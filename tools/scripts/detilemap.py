#!/usr/bin/env python3
"""detilemap -- convert between GBA BG tile sheets and assembled screen images.

A BG tile sheet is stored deduplicated: the tilemap references each unique 8x8
tile once, so the raw sheet is unreadable as a picture no matter what width it
is exported at. This tool moves the editable form to the *assembled screen*,
where the art is actually visible, and derives the sheet from it.

    assemble   tiles.4bpp + tilemap.bin + palette.pal  ->  screen.png
    extract    screen.png + tilemap.bin                ->  tiles.4bpp

The screen image is an 8bpp indexed PNG carrying the full 256-colour GBA
palette, with each pixel storing  bank * 16 + colour_index.  That keeps every
per-cell palette bank distinct and makes the conversion lossless in both
directions -- a 4bpp image could only hold one of the banks a screen uses.

Flips are applied on assemble and undone on extract, so a cell that the tilemap
marks h/v flipped still contributes its unflipped pixels back to the sheet.

Ruby and Sapphire stream their board through a scroll ring, so a tilemap row R
draws chunk R of a virtual strip rather than indexing the sheet directly. Pass
`--row-chunk N` for those: the tile index becomes `R*N + (id % N)`. See
data/board_data/VRAM_LAYOUT.md.

Only stdlib is used, so this adds no build dependency.

Examples
--------
    detilemap.py assemble -t tiles.4bpp -m bg3.bin -p scene.pal -s 32x32 \\
                          -o screen_bg3.png

    detilemap.py extract  -n 704 -o tiles.4bpp \\
                          --from screen_bg3.png:bg3.bin \\
                          --from screen_bg1.png:bg1.bin

`extract` takes as many screen/tilemap pairs as the sheet needs: one sheet is
often shared by several BG layers. Tiles that no supplied tilemap references
are emitted as zeroes and reported, so you can see exactly how much of the
sheet was reconstructed rather than assumed.
"""
import argparse
import struct
import sys
import zlib

SCREEN_SIZES = {"32x32": (32, 32), "64x32": (64, 32), "32x64": (32, 64), "64x64": (64, 64)}


# ---------------------------------------------------------------- PNG (8bpp indexed)

def png_write(path, width, height, pixels, palette):
    """pixels: bytes, one byte per pixel. palette: list of (r,g,b), <=256 entries."""
    def chunk(tag, data):
        return (struct.pack(">I", len(data)) + tag + data
                + struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF))

    raw = bytearray()
    for y in range(height):
        raw.append(0)  # filter type 0 (None)
        raw += pixels[y * width:(y + 1) * width]
    plte = b"".join(bytes(c) for c in palette)
    out = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0))
           + chunk(b"PLTE", plte)
           + chunk(b"IDAT", zlib.compress(bytes(raw), 9))
           + chunk(b"IEND", b""))
    with open(path, "wb") as fp:
        fp.write(out)


def png_read(path):
    """Returns (width, height, pixels bytes one-per-pixel, palette list)."""
    data = open(path, "rb").read()
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise SystemExit(f"{path}: not a PNG")
    pos, idat, plte, ihdr = 8, bytearray(), None, None
    while pos < len(data):
        ln, tag = struct.unpack(">I4s", data[pos:pos + 8])
        body = data[pos + 8:pos + 8 + ln]
        if tag == b"IHDR":
            ihdr = struct.unpack(">IIBBBBB", body)
        elif tag == b"PLTE":
            plte = body
        elif tag == b"IDAT":
            idat += body
        pos += 12 + ln
    w, h, bd, ct, comp, filt, inter = ihdr
    if ct != 3 or bd not in (1, 2, 4, 8):
        raise SystemExit(f"{path}: need an indexed PNG (colour type 3), got type {ct} depth {bd}")
    if inter:
        raise SystemExit(f"{path}: interlaced PNGs are not supported")

    raw = zlib.decompress(bytes(idat))
    bpp = 1  # bytes per pixel for filtering purposes at bd<=8
    stride = (w * bd + 7) // 8
    rows, prev, pos = [], bytearray(stride), 0
    for _ in range(h):
        ftype = raw[pos]; pos += 1
        line = bytearray(raw[pos:pos + stride]); pos += stride
        for i in range(stride):
            a = line[i - bpp] if i >= bpp else 0
            b = prev[i]
            c = prev[i - bpp] if i >= bpp else 0
            if ftype == 1:   line[i] = (line[i] + a) & 0xFF
            elif ftype == 2: line[i] = (line[i] + b) & 0xFF
            elif ftype == 3: line[i] = (line[i] + ((a + b) >> 1)) & 0xFF
            elif ftype == 4:
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if (pa <= pb and pa <= pc) else (b if pb <= pc else c)
                line[i] = (line[i] + pr) & 0xFF
            elif ftype != 0:
                raise SystemExit(f"{path}: bad PNG filter type {ftype}")
        rows.append(bytes(line)); prev = line

    if bd == 8:
        pixels = b"".join(rows)
    else:  # unpack sub-byte indices
        px = bytearray()
        mask = (1 << bd) - 1
        for line in rows:
            for x in range(w):
                byte = line[(x * bd) // 8]
                shift = 8 - bd - ((x * bd) % 8)
                px.append((byte >> shift) & mask)
        pixels = bytes(px)
    pal = [tuple(plte[i:i + 3]) for i in range(0, len(plte or b""), 3)]
    return w, h, pixels, pal


# ---------------------------------------------------------------- GBA data

def read_jasc(path):
    lines = open(path, "rb").read().decode().replace("\r\n", "\n").split("\n")
    if lines[0] != "JASC-PAL":
        raise SystemExit(f"{path}: not a JASC palette")
    n = int(lines[2])
    return [tuple(map(int, lines[3 + k].split())) for k in range(n)]


def split_map_arg(arg):
    """`file.bin` or `file.bin@N` -- N is an entry offset, for files holding
    several screens back to back."""
    if "@" in arg:
        path, off = arg.rsplit("@", 1)
        return path, int(off, 0)
    return arg, 0


def read_tilemap(path, cols, rows, offset=0):
    """GBA stores >32-wide/tall screens as 32x32 screenblocks in TL,TR,BL,BR order."""
    blob = open(path, "rb").read()
    entries = [int.from_bytes(blob[i:i + 2], "little") for i in range(0, len(blob), 2)]
    entries = entries[offset:]
    need = cols * rows
    if len(entries) < need:
        raise SystemExit(f"{path}: {len(entries)} entries from offset {offset}, "
                         f"need {need} for {cols}x{rows}")
    cell = {}
    blocks_x = cols // 32
    for i, e in enumerate(entries[:need]):
        blk, off = divmod(i, 1024)
        r = off // 32 + 32 * (blk // blocks_x)
        c = off % 32 + 32 * (blk % blocks_x)
        cell[(r, c)] = (e & 0x3FF, (e >> 10) & 1, (e >> 11) & 1, e >> 12)
    return cell


def tile_pixels(sheet, tile):
    """Return 64 palette indices for one 4bpp tile, row-major."""
    out = bytearray(64)
    base = tile * 32
    for y in range(8):
        for x in range(0, 8, 2):
            byte = sheet[base + y * 4 + x // 2]
            out[y * 8 + x] = byte & 0xF
            out[y * 8 + x + 1] = byte >> 4
    return out


# ---------------------------------------------------------------- commands

def cmd_assemble(a):
    cols, rows = SCREEN_SIZES[a.size]
    sheet = open(a.tiles, "rb").read()
    ntiles = len(sheet) // 32
    pal = read_jasc(a.palette)
    if len(pal) < 256:
        pal = pal + [(0, 0, 0)] * (256 - len(pal))
    map_path, map_off = split_map_arg(a.map)
    cells = read_tilemap(map_path, cols, rows, map_off)

    w, h = cols * 8, rows * 8
    px = bytearray(w * h)
    missing = set()
    for (r, c), (tile, hf, vf, bank) in cells.items():
        if a.row_chunk:
            tile = r * a.row_chunk + (tile % a.row_chunk)
        if tile >= ntiles:
            missing.add(tile)
            continue
        tp = tile_pixels(sheet, tile)
        for y in range(8):
            for x in range(8):
                sx = 7 - x if hf else x
                sy = 7 - y if vf else y
                px[(r * 8 + y) * w + c * 8 + x] = bank * 16 + tp[sy * 8 + sx]
    png_write(a.output, w, h, bytes(px), pal[:256])
    print(f"assembled {a.output}  {w}x{h}  ({cols}x{rows} cells, {ntiles} tiles in sheet)")
    if missing:
        lo, hi = min(missing), max(missing)
        print(f"  note: {len(missing)} tile ids referenced but outside this sheet ({lo}..{hi}) "
              f"-- those cells are left blank")


def cmd_extract(a):
    sheet = bytearray(a.count * 32)
    written = {}
    conflicts = []

    for spec in getattr(a, "from"):
        parts = spec.split(":")
        if len(parts) == 3 and parts[2] in SCREEN_SIZES:
            png_path, map_path, size = parts
        elif len(parts) == 2:
            png_path, map_path, size = parts[0], parts[1], a.size
        else:
            raise SystemExit(f"--from needs PNG:TILEMAP[:SIZE], got {spec!r}")
        cols, rows = SCREEN_SIZES[size]
        w, h, px, _ = png_read(png_path)
        if (w, h) != (cols * 8, rows * 8):
            raise SystemExit(f"{png_path}: is {w}x{h}, expected {cols*8}x{rows*8} for size {size}")
        map_file, map_off = split_map_arg(map_path)
        cells = read_tilemap(map_file, cols, rows, map_off)

        for (r, c), (tile, hf, vf, bank) in cells.items():
            if a.row_chunk:
                tile = r * a.row_chunk + (tile % a.row_chunk)
            if tile >= a.count:
                continue
            tp = bytearray(64)
            ok = True
            for y in range(8):
                for x in range(8):
                    v = px[(r * 8 + y) * w + c * 8 + x]
                    if v >> 4 != bank:
                        ok = False
                    sx = 7 - x if hf else x
                    sy = 7 - y if vf else y
                    tp[sy * 8 + sx] = v & 0xF
                if not ok:
                    break
            if not ok:
                conflicts.append(("bank", png_path, r, c, tile, bank))
                continue
            packed = bytes((tp[i * 8 + j] | (tp[i * 8 + j + 1] << 4))
                           for i in range(8) for j in range(0, 8, 2))
            if tile in written and written[tile] != packed:
                conflicts.append(("pixels", png_path, r, c, tile, bank))
                continue
            written[tile] = packed

    # Tiles that live in the sheet but that no tilemap references. They cannot
    # come from a screen, so they are supplied as a plain linear tile strip.
    for spec in getattr(a, "extra", None) or []:
        png_path, first = split_map_arg(spec)
        if "@" not in spec:
            raise SystemExit(f"--extra needs PNG@FIRST_TILE, got {spec!r}")
        w, h, px, _ = png_read(png_path)
        if w % 8 or h % 8:
            raise SystemExit(f"{png_path}: is {w}x{h}, must be a whole number of 8x8 tiles")
        per_row = w // 8
        for n in range((w // 8) * (h // 8)):
            tile = first + n
            if tile >= a.count:
                raise SystemExit(f"{png_path}: tile {tile} is past the end of a {a.count}-tile sheet")
            tr, tc = divmod(n, per_row)
            packed = bytes(
                ((px[(tr * 8 + y) * w + tc * 8 + x] & 0xF)
                 | ((px[(tr * 8 + y) * w + tc * 8 + x + 1] & 0xF) << 4))
                for y in range(8) for x in range(0, 8, 2))
            if tile in written and written[tile] != packed:
                conflicts.append(("pixels", png_path, 0, n, tile, 0))
                continue
            written[tile] = packed

    for tile, packed in written.items():
        sheet[tile * 32:(tile + 1) * 32] = packed

    if conflicts:
        print(f"error: {len(conflicts)} cell(s) did not agree with the tilemap:", file=sys.stderr)
        for kind, p, r, c, tile, bank in conflicts[:10]:
            if kind == "bank":
                print(f"  {p} cell ({r},{c}): pixels are not in palette bank {bank}", file=sys.stderr)
            else:
                print(f"  {p} cell ({r},{c}): tile {tile} drawn two different ways", file=sys.stderr)
        if len(conflicts) > 10:
            print(f"  ... and {len(conflicts) - 10} more", file=sys.stderr)
        return 1

    with open(a.output, "wb") as fp:
        fp.write(sheet)
    blank = a.count - len(written)
    print(f"extracted {a.output}  {a.count} tiles, {len(written)} reconstructed from screens")
    if blank:
        ids = sorted(set(range(a.count)) - set(written))
        runs, start = [], ids[0]
        for i in range(1, len(ids) + 1):
            if i == len(ids) or ids[i] != ids[i - 1] + 1:
                runs.append((start, ids[i - 1])); start = ids[i] if i < len(ids) else 0
        pretty = ", ".join(f"{x}" if x == y else f"{x}-{y}" for x, y in runs[:6])
        print(f"  note: {blank} tile(s) unreferenced, emitted as zeroes ({pretty}"
              f"{', ...' if len(runs) > 6 else ''})")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    asm = sub.add_parser("assemble", help="tiles + tilemap + palette -> screen PNG")
    asm.add_argument("-t", "--tiles", required=True)
    asm.add_argument("-m", "--map", required=True)
    asm.add_argument("-p", "--palette", required=True)
    asm.add_argument("-s", "--size", default="32x32", choices=sorted(SCREEN_SIZES))
    asm.add_argument("-o", "--output", required=True)
    asm.add_argument("--row-chunk", type=int, default=0, metavar="N",
                     help="scroll-ring addressing: tile index is R*N + (id %% N)")
    asm.set_defaults(fn=cmd_assemble)

    ext = sub.add_parser("extract", help="screen PNG(s) + tilemap(s) -> tiles")
    ext.add_argument("--from", action="append", required=True, metavar="PNG:TILEMAP[:SIZE]",
                     help="screen image and the tilemap that placed it, with an optional "
                          "per-pair screen size; repeatable. The tilemap may carry an "
                          "@ENTRY_OFFSET suffix when one file holds several screens.")
    ext.add_argument("--extra", action="append", metavar="PNG@FIRST_TILE",
                     help="linear tile strip for sheet tiles no tilemap references; "
                          "written into consecutive slots from FIRST_TILE. Repeatable.")
    ext.add_argument("-n", "--count", type=int, required=True, help="tiles in the output sheet")
    ext.add_argument("-s", "--size", default="32x32", choices=sorted(SCREEN_SIZES),
                     help="default screen size for --from pairs that do not give one")
    ext.add_argument("-o", "--output", required=True)
    ext.add_argument("--row-chunk", type=int, default=0, metavar="N",
                     help="scroll-ring addressing: tile index is R*N + (id %% N)")
    ext.set_defaults(fn=cmd_extract)

    a = ap.parse_args()
    return a.fn(a) or 0


if __name__ == "__main__":
    sys.exit(main())
