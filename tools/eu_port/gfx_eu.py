#!/usr/bin/env python3
"""Turn EU-only graphics blobs (data/eu/bin) into per-language copies of the US graphics files.

A blob is matched with the US item of the same label without the language suffix, and with
the US items that follow it when the EU data has no labels between them. Those items must be
made of .incbin of files under graphics/ (.4bpp/.8bpp/.gbapal/.bin, also LZ-compressed),
.space, .fill and .align. Each file becomes <US file stem>_<language>.png/.pal/.bin next to
the US one, converted with gbagfx like the US file (palette, width, -mwidth/-mheight/-oam,
segments of the gfx-config JSON), and is kept only if gbagfx converts it back to the same
bytes. Images may have a different number of tiles (-num_tiles is added when needed) and
padding that holds data in the EU version is taken into the image before it.
An EU file whose segments differ from the US ones (other sizes, more segments) is described
by its own entry in a gfx-config JSON, e.g. graphics/pokedex/pokedex_gfx_eu.json, so make has
its rule: the segments that are not US files are written from the blob (their size comes from
"width"/"mwidth" and "height", in tiles, and their palette from "palette"/"palbank"), the
others must hold the same bytes.

Output:
  - tools/eu_port/data/eu_graphics.json: the directives that replace each blob, read by
    gen_eu_data.py (so run regen.sh afterwards);
  - graphics_rules_eu.mk: the rules of the files that need gbagfx options or segments.
Blobs that cannot be matched or reproduced exactly are left as they are. All the blobs are
read from the EU ROM, listed by gen_eu_data.py in data/eu_blobs.json (run regen.sh first),
so the tool can be rerun.

Run from the repository root in the build environment (uses tools/gbagfx/gbagfx).
usage: gfx_eu.py [-v]"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import os, re, sys, json, struct, subprocess, tempfile, collections

GFX = _os.path.join(_R, 'tools', 'gbagfx', 'gbagfx')
VERBOSE = '-v' in sys.argv
SUF = re.compile(r'^(.*?)_((?:En|Fr|De|It|Es)+)$')
INC = re.compile(r'^\.incbin\s+"(graphics/[^"]+\.(4bpp|8bpp|gbapal|bin)(\.lz)?)"$')
SPACE = re.compile(r'^\.space\s+(0x[0-9A-Fa-f]+|\d+)$')
ALLOWED_FLAGS = {'-mwidth': 1, '-mheight': 1, '-oam': 0, '-oamshape': 1, '-num_tiles': 1}

# EU-only symbols with the layout of a US item: base name -> (US label, infix of the files)
ALIASES = {
    # the window of the bonus field select, in the languages that do not use gFieldSelectWindow_Gfx
    'gBonusFieldSelectWindow_Gfx': ('gFieldSelectWindow_Gfx', 'bonus'),
}

# EU-only graphics with no US counterpart: label -> output file (.png for 4bpp tiles, .pal for
# a palette, .bin as is), width of the image in tiles, palette of the image (a palette label
# and slot in the EU ROM, or a US PNG), and for data that several labels point into, its size
# and the other labels (defined with .set at their offset).
LANG_NAMES = ['En', 'Fr', 'De', 'It', 'Es']
EXTRA = {
    'gLanguageSelectBg0_Tilemap': dict(file='graphics/language_select/bg0_tilemap.bin'),
    'gLanguageSelectBg1_Tilemap': dict(file='graphics/language_select/bg1_tilemap.bin'),
    'gLanguageSelectSprite_Gfx': dict(file='graphics/language_select/sprites.png', width=16,
                                      pal=('gLanguageSelectSprite_Pals', 0)),
    'gLanguageSelectSprite_Pals': dict(file='graphics/language_select/sprites.pal'),
    'gLanguageSelect_Gfx': dict(file='graphics/language_select/bg.png', width=32, pal=('gLanguageSelectBg_Pals', 0)),
    # titles of the screen in French, German, Italian and Spanish
    'gLanguageSelectTitle_Gfx': dict(file='graphics/language_select/titles.png', width=32,
                                     pal=('gLanguageSelectBg_Pals', 0)),
    'gLanguageSelectBg_Pals': dict(file='graphics/language_select/bg.pal'),
    # one sheet with the ranks (1er, 1°, 1. ...) of four languages (11x4 tiles each), copied with
    # CopyBgTilesRect
    'gHighScoreTitle_Gfx_Fr': dict(file='graphics/high_score/rank_numbers_frdeites.png', width=32,
                                   pal='graphics/high_score/bg_eu.pal', size=0x2020,
                                   sets={'gHighScoreTitle_Gfx_It': 0x160, 'gHighScoreTitle_Gfx_De': 0x1000,
                                         'gHighScoreTitle_Gfx_Es': 0x1160}),
}
for _l in LANG_NAMES:
    # label of the Ruby shop sign showing which shop is open (gRubyShopSignTilePointers_<Lang>[0/1][0])
    for _shop in ('Mart', 'Evo'):
        EXTRA['gRubyShopSign%sLabel_%s' % (_shop, _l)] = dict(
            file='graphics/stage/ruby/shop_sign/shop_sign_%s_label_%s.png' % (_shop.lower(), _l.lower()),
            width=6, pal='graphics/stage/ruby/shop_sign/shop_sign_mart_piece0.png')
    # "text" of the board intro sprites (in the US version it is part of the intro sprites)
    EXTRA['gFieldIntroText_Gfx_' + _l] = dict(file='graphics/stage/misc/field_intro_text_%s.png' % _l.lower(),
                                             width=10, pal='graphics/stage/ruby/intro_sprite_location.png')
    if _l != 'En':
        # text drawn over the e-Reader background (the English one is part of the background)
        EXTRA['gEReaderBackgroundText_Gfx_' + _l] = dict(file='graphics/ereader/background_text_%s.png' % _l.lower(),
                                                        width=32, pal='graphics/ereader/background.png')
TMP = tempfile.mkdtemp(prefix='gfx_eu_')


def flat(f):
    for ln in open(_R + '/' + f, encoding='utf-8'):
        m = re.match(r'^\s*\.include\s+"([^"]+)"', ln)
        if m and m.group(1).startswith('data/') and os.path.exists(_R + '/' + m.group(1)):
            yield from flat(m.group(1))
        else:
            yield ln


def us_items():
    """US data items in file order: list of (label, directive lines)."""
    items = []
    for f in ['data/rom_1.s', 'data/rom_2.s']:
        items.append(('', []))  # lines before the first label of the file
        for ln in flat(f):
            m = re.match(r'^(\w+)::', ln)
            if m:
                items.append((m.group(1), []))
                continue
            s_ = ln.split('@')[0].strip().rstrip(';').strip()
            if items and s_:
                items[-1][1].append(s_)
    return items


def eu_blobs():
    """(EU address, bytes, labels) of the EU-only data ranges of rom_1 that gen_eu_data.py writes
    as binary files or replaces with converted sources (data/eu_blobs.json, made by regen.sh);
    the bytes come from the EU ROM."""
    if not os.path.exists(_W + '/eu_blobs.json'):
        raise SystemExit('missing %s/eu_blobs.json: run regen.sh first' % _W)
    rom = open(_BASEROM, 'rb').read()
    out = []
    for b in json.load(open(_W + '/eu_blobs.json')):
        a = int(b['addr'], 16)
        out.append((a, rom[a - 0x08000000:a - 0x08000000 + b['size']], b['labels']))
    return out


def make_rules():
    rules = {}
    for f in ['graphics_rules.mk', 'graphics_rules_generated.mk']:
        if not os.path.exists(_R + '/' + f):
            continue
        txt = open(_R + '/' + f, encoding='utf-8').read()
        for m in re.finditer(r'^([^\s:#=][^:=\n]*?):([^=\n]*)\n((?:\t[^\n]*\n)*)', txt, re.M):
            for t in m.group(1).split():
                rules[t] = (m.group(2).split(), [l.strip() for l in m.group(3).strip().split('\n') if l.strip()])
    return rules


def gfx_configs():
    """Files built from segments of a gfx-config JSON: target path -> (directory, file entry)."""
    out = {}
    for root, _, files in os.walk(_R + '/graphics'):
        d = os.path.relpath(root, _R).replace('\\', '/')
        for f in files:
            if not f.endswith('.json'):
                continue
            try:
                cfg = json.load(open(os.path.join(root, f), encoding='utf-8'))
            except ValueError:
                continue  # skipped by generate_graphics_rules.sh too (jq fails)
            if not isinstance(cfg, dict) or cfg.get('kind') != 'gfx-config':
                continue
            for e in cfg.get('files', []):
                if e.get('segments'):
                    out['%s/%s.4bpp' % (d, e['gfx_filename'])] = (d, e)
    return out


def gfx(*args):
    r = subprocess.run([GFX] + [str(a) for a in args], capture_output=True, text=True)
    if r.returncode != 0:
        raise RuntimeError('gbagfx %s: %s' % (' '.join(map(str, args)), (r.stderr or r.stdout).strip()))


def png_info(path):
    d = open(path, 'rb').read(64 * 1024)
    w, h, depth, ctype = struct.unpack('>IIBB', d[16:26])
    return w, h, depth, ctype, b'PLTE' in d


def tmp(name, data=None):
    p = os.path.join(TMP, name)
    if data is not None:
        open(p, 'wb').write(data)
    return p


class Unsupported(Exception):
    pass


def parse_flags(toks, what):
    flags, i = [], 0
    while i < len(toks):
        if toks[i] not in ALLOWED_FLAGS:
            raise Unsupported('flag %s for %s' % (toks[i], what))
        n = ALLOWED_FLAGS[toks[i]]
        flags += toks[i:i + 1 + n]
        i += 1 + n
    return flags


def image(us_png, out_png, raw, flags, ext, us_size):
    """Write raw tiles as out_png laid out like us_png; return the gbagfx options it needs."""
    w, h, depth, ctype, has_pal = png_info(_R + '/' + us_png)
    inv = [f for i, f in enumerate(flags) if f != '-num_tiles' and (i == 0 or flags[i - 1] != '-num_tiles')]
    bpp = 4 if ext == '4bpp' else 8
    tile = 8 * bpp
    full = (w // 8) * (h // 8) * tile
    if us_size is not None and len(raw) != us_size:
        # The EU image has a different number of tiles: same width, as many rows as needed.
        if inv or len(raw) % tile:
            raise Unsupported('resized ' + us_png)
        ntiles = len(raw) // tile
        rows = -(-ntiles // (w // 8))
        full = rows * (w // 8) * tile
        flags = ['-num_tiles', str(ntiles)] if rows * (w // 8) != ntiles else []
    inraw = raw + bytes(max(0, full - len(raw))) if '-num_tiles' in flags else raw
    args = [tmp('in.' + ext, inraw), _R + '/' + out_png, '-width', w // 8] + inv
    if has_pal:
        gfx(_R + '/' + us_png, tmp('pal.gbapal'))
        pal = open(tmp('pal.gbapal'), 'rb').read()[:2 << bpp]
        args += ['-palette', tmp('pal.gbapal', pal)]
    gfx(*args)
    gfx(_R + '/' + out_png, tmp('chk.' + ext), *flags)
    if open(tmp('chk.' + ext), 'rb').read() != raw:
        raise Unsupported('round trip ' + us_png)
    return flags


GFX_CMD = re.compile(r'^\$\(GFX\) (\S+\.png) (\S+\.4bpp)((?: [^\s;\\]+)*)(?:; \\)?$')
CAT_CMD = re.compile(r'^cat ((?:\S+\.4bpp ?)+)> \$@(?:; \\)?$')
DD_CMD = re.compile(r'^dd if=/dev/zero bs=32 count=(\d+) >> \$@ 2>/dev/null$')


def segmented(t, raw, stem, suffix_low, new_rules):
    """EU copy of a target built from segments (gfx-config "segments"): one PNG per segment."""
    prereqs, recipe = RULES[t]
    segs, cat, dd = [], None, 0
    for l in recipe:
        m1, m2, m3 = GFX_CMD.match(l), CAT_CMD.match(l), DD_CMD.match(l)
        if m1:
            segs.append((m1.group(1), m1.group(2), parse_flags(m1.group(3).split(), t)))
        elif m2:
            cat = m2.group(1).split()
        elif m3:
            dd = int(m3.group(1))
        else:
            raise Unsupported('rule ' + t)
    if not segs or cat != [s[1] for s in segs]:
        raise Unsupported('rule ' + t)
    sizes = [os.path.getsize(_R + '/' + s[1]) for s in segs]
    if sum(sizes) + 32 * dd != len(raw):
        raise Unsupported('segment sizes ' + t)
    if any(raw[sum(sizes):]):
        raise Unsupported('nonzero padding ' + t)
    lines, outs, pngs, pos = [], [], [], 0
    for (png, out, flags), size in zip(segs, sizes):
        eu_png = png[:-4] + '_' + suffix_low + '.png'
        eu_out = stem + out[len(t.rsplit('.', 1)[0]):]
        image(png, eu_png, raw[pos:pos + size], flags, '4bpp', None)
        pos += size
        pngs.append(eu_png)
        outs.append(eu_out)
        lines.append('$(GFX) %s %s%s; \\' % (eu_png, eu_out, ''.join(' ' + f for f in flags)))
    lines.append('cat %s > $@%s' % (' '.join(outs), '; \\' if dd else ''))
    if dd:
        lines.append('dd if=/dev/zero bs=32 count=%d >> $@ 2>/dev/null' % dd)
    deps = [p for p in prereqs if p.endswith('.json')]
    new_rules[stem + '.4bpp'] = (' '.join(pngs + deps), lines)
    return pngs


def sheet(t, raw, written):
    """EU file t with its own segments (SHEETS, rule made from the JSON): write the segment PNGs
    that do not exist yet, check that the existing ones hold the same bytes."""
    d, entry = SHEETS[t]
    pos = 0
    for seg in entry['segments']:
        png = '%s/%s.png' % (d, seg['segfile'])
        flags = []
        for k in ('mwidth', 'mheight'):
            if seg.get(k):
                flags += ['-' + k, str(seg[k])]
        if seg.get('oam'):
            flags.append('-oam')
        if os.path.exists(_R + '/' + png):
            w, h = png_info(_R + '/' + png)[:2]
            size = w * h // 2
        else:
            width = seg.get('width', seg.get('mwidth', 1))
            size = 32 * width * seg['height']
            gfx(_R + '/' + d + '/' + seg['palette'].rsplit('.', 1)[0] + '.pal', tmp('pal.gbapal'))
            bank = seg.get('palbank', 0)
            pal = open(tmp('pal.gbapal'), 'rb').read()[32 * bank:32 * bank + 32]
            written.append(_R + '/' + png)
            gfx(tmp('in.4bpp', raw[pos:pos + size]), _R + '/' + png, '-width', width,
                '-palette', tmp('pal.gbapal', pal), *flags)
        gfx(_R + '/' + png, tmp('chk.4bpp'), *flags)
        if open(tmp('chk.4bpp'), 'rb').read() != raw[pos:pos + size]:
            raise Unsupported('segment ' + png)
        pos += size
    if len(raw) - pos != 32 * entry.get('align', 0) or any(raw[pos:]):
        raise Unsupported('segment sizes ' + t)


def convert(g, data, stem, new_rules, written):
    """Write the EU copy of graphics file g (US path) holding data; return its .incbin path.
    Source files created are added to written."""
    lz = g.endswith('.lz')
    t = g[:-3] if lz else g
    base, ext = t.rsplit('.', 1)
    raw = data
    if lz:
        gfx(tmp('in.lz', data), tmp('in.raw'))
        raw = open(tmp('in.raw'), 'rb').read()
    out_t = f'{stem}.{ext}'
    suffix_low = stem[len(base) + 1:]
    def mark(path):
        if not os.path.exists(_R + '/' + path):
            written.append(_R + '/' + path)
    if out_t in SHEETS:
        sheet(out_t, raw, written)
    elif ext == 'bin':
        mark(out_t)
        open(_R + '/' + out_t, 'wb').write(raw)
    elif ext == 'gbapal':
        if t in RULES:
            raise Unsupported('rule for ' + t)
        mark(f'{stem}.pal')
        gfx(tmp('in.gbapal', raw), _R + f'/{stem}.pal')
        gfx(_R + f'/{stem}.pal', tmp('chk.gbapal'))
        if open(tmp('chk.gbapal'), 'rb').read() != raw:
            raise Unsupported('palette round trip ' + t)
    elif t in RULES and len(RULES[t][1]) == 2 and RULES[t][1][0].startswith('$(GFX) $< $@') \
            and DD_CMD.match(RULES[t][1][1]):
        # one image followed by zero padding (an "align" in the gfx-config JSON)
        pad = 32 * int(DD_CMD.match(RULES[t][1][1]).group(1))
        if len(raw) <= pad or any(raw[-pad:]):
            raise Unsupported('padding ' + t)
        flags = parse_flags(RULES[t][1][0].split()[3:], t)
        mark(f'{stem}.png')
        us_size = os.path.getsize(_R + '/' + t) - pad if os.path.exists(_R + '/' + t) else None
        flags = image(f'{base}.png', f'{stem}.png', raw[:-pad], flags, ext, us_size)
        new_rules[out_t] = (f'{stem}.png', ['$(GFX) $< $@' + ''.join(' ' + f for f in flags), RULES[t][1][1]])
    elif t in RULES and len(RULES[t][1]) > 1:
        for png in [s for s in RULES[t][0] if s.endswith('.png')]:
            mark(png[:-4] + '_' + suffix_low + '.png')
        segmented(t, raw, stem, suffix_low, new_rules)
    else:
        if not os.path.exists(_R + f'/{base}.png'):
            raise Unsupported('no png for ' + t)
        flags = []
        rule = RULES.get(t)
        if rule:
            prereqs, recipe = rule
            if not recipe[0].startswith('$(GFX) $< $@') or not prereqs or prereqs[0] != f'{base}.png':
                raise Unsupported('rule ' + t)
            flags = parse_flags(recipe[0].split()[3:], t)
        mark(f'{stem}.png')
        us_size = os.path.getsize(_R + '/' + t) if os.path.exists(_R + '/' + t) else None
        flags = image(f'{base}.png', f'{stem}.png', raw, flags, ext, us_size)
        if flags:
            new_rules[out_t] = (f'{stem}.png', ['$(GFX) $< $@ ' + ' '.join(flags)])
        else:
            new_rules.pop(out_t, None)  # converted again with more data: no options needed now
    if lz:
        gfx(tmp('chk.raw', raw), tmp('chk.lz'))
        if open(tmp('chk.lz'), 'rb').read() != data:
            raise Unsupported('lz compression differs ' + t)
        return out_t + '.lz'
    return out_t


FILL = re.compile(r'^\.fill\s+(\S+),\s*(\S+),\s*(\S+)$')
ALIGN = re.compile(r'^\.align\s+(\d+)(?:,\s*(\S+))?$')


def lz_len(buf, pos):
    """Length of the GBA LZ77 stream at buf[pos], padded to 4 bytes like gbagfx."""
    if pos + 4 > len(buf) or buf[pos] != 0x10:
        raise Unsupported('lz header')
    size = buf[pos + 1] | buf[pos + 2] << 8 | buf[pos + 3] << 16
    p, out = pos + 4, 0
    while out < size:
        if p >= len(buf):
            raise Unsupported('lz stream')
        flags = buf[p]
        p += 1
        for bit in range(8):
            if out >= size:
                break
            if flags & (0x80 >> bit):
                if p + 2 > len(buf):
                    raise Unsupported('lz stream')
                out += (buf[p] >> 4) + 3
                p += 2
            else:
                out += 1
                p += 1
    return (p - pos + 3) & ~3


def parse_item(lines):
    """Pieces of a US item: ('inc', path) / ('space', n) / ('fill', n, value) / ('align', n)."""
    pieces = []
    for l in lines:
        mi, ms, mf, ma = INC.match(l), SPACE.match(l), FILL.match(l), ALIGN.match(l)
        if mi:
            if not os.path.exists(_R + '/' + mi.group(1)):
                raise Unsupported('missing ' + mi.group(1))
            pieces.append(('inc', mi.group(1)))
        elif ms:
            pieces.append(('space', int(ms.group(1), 0)))
        elif mf:
            if int(mf.group(2), 0) != 1:
                raise Unsupported('fill size')
            pieces.append(('fill', int(mf.group(1), 0), int(mf.group(3), 0)))
        elif ma and not ma.group(2):
            pieces.append(('align', int(ma.group(1))))
        else:
            raise Unsupported('directive ' + l.split()[0])
    return pieces


def piece_size(piece, data, pos, addr):
    if piece[0] == 'inc':
        if piece[1].endswith('.lz'):
            return lz_len(data, pos)
        return os.path.getsize(_R + '/' + piece[1])
    if piece[0] in ('space', 'fill'):
        return piece[1]
    n = 1 << piece[1]
    return (-(addr + pos)) % n


def layout(items, k, data, addr):
    """Split data into consecutive US items starting at items[k].
    Returns [(item index, label, [(piece, size)])]. Tries exact sizes (also a prefix of the
    first item's pieces), then a resized image."""
    plan, pos = [], 0
    for i in range(k, len(items)):
        lab, lines = items[i]
        if not lab:
            break
        pieces = parse_item(lines)
        sized = []
        for j, pc in enumerate(pieces):
            n = piece_size(pc, data, pos, addr)
            sized.append((pc, n))
            pos += n
            if not plan and pos == len(data) and j < len(pieces) - 1 and pc[0] == 'inc':
                return [(i, lab, sized)]  # the EU data stops before the end of the US item
        plan.append((i, lab, sized))
        if pos == len(data):
            return plan
        if pos > len(data) or not sized or len(plan) > 64:
            break
    # a single item whose first piece (an image) has a different size; the trailing
    # .space/.fill/.align are kept when the data still has room for them
    pieces = parse_item(items[k][1])
    if pieces and all(p[0] in ('inc', 'space', 'fill') and not (p[0] == 'inc' and p[1].endswith('.lz')) for p in pieces) \
            and sum(p[0] == 'inc' for p in pieces) > 1:
        # several images: one of them (the last that fits) has a different size
        us = [os.path.getsize(_R + '/' + p[1]) if p[0] == 'inc' else p[1] for p in pieces]
        for j in reversed([j for j, p in enumerate(pieces) if p[0] == 'inc']):
            n = len(data) - (sum(us) - us[j])
            if n > 0 and n % 32 == 0:
                return [(k, items[k][0], [(p, n if i == j else us[i]) for i, p in enumerate(pieces)])]
        raise Unsupported('size')
    if not pieces or pieces[0][0] != 'inc' or pieces[0][1].endswith('.lz') or any(p[0] == 'inc' for p in pieces[1:]):
        raise Unsupported('size')
    for keep in range(len(pieces), 0, -1):
        tail = pieces[1:keep]
        if any(p[0] == 'align' for p in tail):
            continue
        n = len(data) - sum(p[1] for p in tail)
        if n <= 0:
            continue
        return [(k, items[k][0], [(pieces[0], n)] + [(p, p[1]) for p in tail])]
    raise Unsupported('size')


def build(plan, data, suffix, known, rules_here, written, made, stem_suffix=None):
    """Convert the pieces of a layout; return the directive lines."""
    out_lines = []
    made_here = set()
    last_img = None  # (line index, US path, stem, start, end) of the last image of the item
    pos = 0
    for n_item, (i, ilab, sized) in enumerate(plan):
        if n_item:
            name = ilab + ('_' + suffix if suffix else '')
            out_lines.append(f'{name}::' if name not in known else f'@ {name}')
            last_img = None
        for pc, size in sized:
            chunk = data[pos:pos + size]
            pos += size
            if pc[0] in ('space', 'fill', 'align'):
                ok = not any(chunk) if pc[0] != 'fill' else chunk == bytes([pc[2]]) * size
                if not ok:
                    # real data where the US file has padding: part of the previous image
                    if last_img is None or pc[0] == 'align':
                        raise Unsupported('nonzero space')
                    li, g, stem, start, end = last_img
                    out_lines[li] = '.incbin "%s"' % convert(g, data[start:pos], stem, rules_here, written)
                    last_img = (li, g, stem, start, pos)
                    continue
                if pc[0] == 'space':
                    out_lines.append('.space 0x%X' % size)
                elif pc[0] == 'align':
                    out_lines.append('.align %d' % pc[1])
                else:
                    out_lines.append('.fill 0x%X, 1, 0x%X' % (size, pc[2]))
                continue
            g = pc[1]
            t = g[:-3] if g.endswith('.lz') else g
            ext = t.rsplit('.', 1)[1]
            stem = t.rsplit('.', 1)[0] + '_' + (stem_suffix or (suffix.lower() if suffix else 'eu'))
            key = stem + '.' + ext
            if key in made or key in made_here:
                raise Unsupported('duplicate ' + key)
            out_lines.append('.incbin "%s"' % convert(g, chunk, stem, rules_here, written))
            made_here.add(key)
            last_img = (len(out_lines) - 1, g, stem, pos - size, pos) if ext in ('4bpp', '8bpp') and not g.endswith('.lz') else None
    return out_lines, made_here


def extra(lab, spec, data, rom, label_addr, new_rules, written):
    """Write an EU-only graphic described in EXTRA; return its directive lines."""
    f = spec['file']
    stem, ext = f.rsplit('.', 1)
    os.makedirs(os.path.dirname(_R + '/' + f), exist_ok=True)
    if not os.path.exists(_R + '/' + f):
        written.append(_R + '/' + f)
    if ext == 'bin':
        open(_R + '/' + f, 'wb').write(data)
        lines = ['.incbin "%s"' % f]
    elif ext == 'pal':
        gfx(tmp('in.gbapal', data), _R + '/' + f)
        gfx(_R + '/' + f, tmp('chk.gbapal'))
        if open(tmp('chk.gbapal'), 'rb').read() != data:
            raise Unsupported('palette round trip ' + f)
        lines = ['.incbin "%s.gbapal"' % stem]
    else:
        w = spec['width']
        if len(data) % 32:
            raise Unsupported('size ' + f)
        ntiles = len(data) // 32
        rows = -(-ntiles // w)
        flags = ['-num_tiles', str(ntiles)] if rows * w != ntiles else []
        inraw = data + bytes(rows * w * 32 - len(data))
        pal = spec['pal']
        if isinstance(pal, tuple):
            a = label_addr[pal[0]] - 0x08000000 + 32 * pal[1]
            pal_data = rom[a:a + 32]
        else:
            gfx(_R + '/' + pal, tmp('pal.gbapal'))
            pal_data = open(tmp('pal.gbapal'), 'rb').read()[:32]
        gfx(tmp('in.4bpp', inraw), _R + '/' + f, '-width', w, '-palette', tmp('pal.gbapal', pal_data))
        gfx(_R + '/' + f, tmp('chk.4bpp'), *flags)
        if open(tmp('chk.4bpp'), 'rb').read() != data:
            raise Unsupported('round trip ' + f)
        if flags:
            new_rules[stem + '.4bpp'] = (f, ['$(GFX) $< $@ ' + ' '.join(flags)])
        lines = ['.incbin "%s.4bpp"' % stem]
    for name, off in sorted(spec.get('sets', {}).items(), key=lambda x: x[1]):
        lines += ['.global %s' % name, '.set %s, %s + 0x%X' % (name, lab, off)]
    return lines


def main():
    global RULES, SHEETS
    RULES = make_rules()
    SHEETS = gfx_configs()
    items = us_items()
    index = {}
    for i, (lab, lines) in enumerate(items):
        if lab:
            index.setdefault(lab, i)
    known = set()
    for f in ['eu_data_labels.json', 'code_syms.json', 'hard_syms.json']:
        if os.path.exists(_W + '/' + f):
            known.update(json.load(open(_W + '/' + f)))
    result = {}
    new_rules = {}
    made = set()
    why = collections.Counter()
    blobs = {}
    for addr, data, labs in eu_blobs():
        blobs.setdefault(addr, (data, labs))
    rom = open(_BASEROM, 'rb').read()
    label_addr = json.load(open(_W + '/eu_data_labels.json')) if os.path.exists(_W + '/eu_data_labels.json') else {}
    covered = 0  # end of the data converted with an EXTRA entry that spans several blobs
    for addr, (data, labs) in sorted(blobs.items()):
        if addr < covered:
            continue
        lab = labs[0] if labs else None
        m = SUF.match(lab or '')
        base, suffix = (m.group(1), m.group(2)) if m else (lab, None)
        written = []
        rules_here = {}
        try:
            if lab in EXTRA:
                spec = EXTRA[lab]
                if 'size' in spec:
                    data = rom[addr - 0x08000000:addr - 0x08000000 + spec['size']]
                    covered = addr + spec['size']
                try:
                    out_lines = extra(lab, spec, data, rom, label_addr, rules_here, written)
                except RuntimeError as e:
                    raise Unsupported('gbagfx: ' + str(e))
                new_rules.update(rules_here)
                result['0x%08X' % addr] = dict(size=len(data), label=lab, lines=out_lines)
                why['converted'] += 1
                continue
            # Only blobs whose label names a US item: matching others by size alone (for example
            # continuing the US items of the previous blob) can pick the wrong files.
            stem_suffix = None
            if base in index:
                start = index[base]
            elif base in ALIASES and ALIASES[base][0] in index:
                start = index[ALIASES[base][0]]
                stem_suffix = ALIASES[base][1] + ('_' + suffix.lower() if suffix else '')
            else:
                why['no US counterpart'] += 1
                if VERBOSE:
                    print('skip 0x%08X %s no US counterpart' % (addr, lab))
                continue
            plan = layout(items, start, data, addr)
            try:
                out_lines, made_here = build(plan, data, suffix, known, rules_here, written, made, stem_suffix)
            except RuntimeError as e:
                raise Unsupported('gbagfx: ' + str(e))
            made |= made_here
            new_rules.update(rules_here)
            result['0x%08X' % addr] = dict(size=len(data), label=lab, lines=out_lines)
            why['converted'] += 1
        except Unsupported as e:
            for w in written:
                if os.path.exists(w):
                    os.remove(w)
            why[str(e).split()[0]] += 1
            if VERBOSE:
                print('skip 0x%08X %s %s' % (addr, lab, e))
    json.dump(result, open(_W + '/eu_graphics.json', 'w', newline='\n'), indent=1, sort_keys=True)
    with open(_R + '/graphics_rules_eu.mk', 'w', newline='\n') as f:
        f.write('# Per-language graphics of the European version that need gbagfx options\n')
        f.write('# or are built from segments. Generated by tools/eu_port/gfx_eu.py.\n')
        for t in sorted(new_rules):
            deps, recipe = new_rules[t]
            f.write(f'\n{t}: {deps}\n\t' + '\n\t'.join(recipe) + '\n')
    for k, v in why.most_common():
        print(v, k)
    print('bytes converted', sum(r['size'] for r in result.values()))


if __name__ == '__main__':
    main()
