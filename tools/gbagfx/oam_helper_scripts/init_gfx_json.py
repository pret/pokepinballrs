#!/usr/bin/env python3
import argparse, json, sys
from pathlib import Path

def to_posix(p: Path) -> str:
    return p.as_posix()

def parse_int_auto(s: str) -> int:
    # accepts "32" or "0x20"
    return int(s, 0)

def main():
    ap = argparse.ArgumentParser(
        description="Scan a directory for .4bpp files and create an initial gfx JSON (with tileCount)."
    )
    ap.add_argument("root", nargs="?", default=".", help="Directory to scan (default: .)")
    ap.add_argument("-o", "--output", help="Output JSON path (default: <root>/gfx.json)")
    ap.add_argument("--relative-to", choices=["cwd","root"], default="cwd",
                    help="Store paths relative to: cwd (default) or root dir")
    # Defaults for gfx options (these don’t affect flags if 0/empty)
    ap.add_argument("--defaults-mwidth", type=int, default=0)
    ap.add_argument("--defaults-mheight", type=int, default=0)
    ap.add_argument("--defaults-oam", action="store_true")
    ap.add_argument("--defaults-width", type=int, default=0)
    ap.add_argument("--defaults-palette", default="")
    # Tile handling
    ap.add_argument("--tile-size", default="0x20",
                    help="Tile size in bytes (default: 0x20 = 32)")
    ap.add_argument("--strict-tiles", action="store_true",
                    help="Error if any .4bpp size is not a multiple of tile size")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()

    root = Path(args.root).resolve()
    if not root.exists() or not root.is_dir():
        raise SystemExit(f"[init] root is not a directory: {root}")

    out = Path(args.output) if args.output else root / "gfx.json"
    tile_size = parse_int_auto(args.tile_size)
    if tile_size <= 0:
        raise SystemExit(f"[init] --tile-size must be > 0 (got {tile_size})")

    if args.verbose:
        print(f"[init] scanning root: {root}")
        print(f"[init] tile_size: {tile_size} bytes")
        print(f"[init] will write JSON: {out}")

    files = []
    warnings = 0

    # Collect base paths for *.4bpp (case-insensitive)
    for p in sorted(root.rglob("*")):
        if p.is_file() and p.suffix.lower() == ".4bpp":
            base = p.with_suffix("")  # remove .4bpp
            # choose how to store path
            if args.relative_to == "root":
                f = to_posix(base.relative_to(root))
            else:
                try:
                    f = to_posix(base.relative_to(Path.cwd()))
                except ValueError:
                    f = to_posix(base)

            size = p.stat().st_size
            remainder = size % tile_size
            tile_count = size // tile_size

            if remainder != 0:
                msg = (f"[init] WARNING: {p} size={size} not a multiple of tile_size={tile_size} "
                       f"(tileCount will be {tile_count}, remainder {remainder} bytes)")
                print(msg, file=sys.stderr)
                warnings += 1
                if args.strict_tiles:
                    raise SystemExit("[init] --strict-tiles: aborting due to misaligned file size.")

            palette_rel = None
            pal_candidate = base.with_suffix(".gbapal")
            if pal_candidate.exists():
                if args.relative_to == "root":
                    palette_rel = to_posix(pal_candidate.relative_to(root))
                else:
                    try:
                        palette_rel = to_posix(pal_candidate.relative_to(Path.cwd()))
                    except ValueError:
                        palette_rel = to_posix(pal_candidate)

            entry = {
                "gfx_filename": f,
                "tileCount": tile_count
            }
            if palette_rel:
                entry["palette"] = palette_rel  # per-file override if .gbapal is present

            files.append(entry)

    if args.verbose:
        print(f"[init] found {len(files)} .4bpp file(s)")
        if 0 < len(files) <= 10:
            for e in files:
                print(f"  - {e['f']}.4bpp  (tileCount={e['tileCount']})")
        elif len(files) > 10:
            for e in files[:5]:
                print(f"  - {e['f']}.4bpp  (tileCount={e['tileCount']})")
            print("  ...")

    cfg = {
        "kind": "gfx-config",
        "version": 1,
        "defaults": {
            "mwidth": args.defaults_mwidth,
            "mheight": args.defaults_mheight,
            "oam": bool(args.defaults_oam),
            "width": args.defaults_width,
            "palette": args.defaults_palette
        },
        "files": files
    }

    out.parent.mkdir(parents=True, exist_ok=True)
    with open(out, "w", encoding="utf-8") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")

    print(f"[init] wrote {out} with {len(files)} entr{'y' if len(files)==1 else 'ies'}"
          f"{' and warnings' if warnings else ''}")

if __name__ == "__main__":
    main()
