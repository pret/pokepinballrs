#!/usr/bin/env python3
"""Turn EU-only graphics blobs (data/eu/bin) into per-language copies of the US graphics files.

For each blob whose US counterpart (same label without the language suffix) is made only of
.incbin of files under graphics/ and .space, with the same total size, write
<US file stem>_<language>.png/.pal/.bin next to the US file, check that gbagfx converts it back
to the same bytes, and record:
  - the directives that replace the blob in tools/eu_port/data/eu_graphics.json (read by
    gen_eu_data.py, so run regen.sh afterwards);
  - the conversion rules of files that need gbagfx options in graphics_rules_eu.mk.
Blobs that cannot be reproduced exactly are left as they are. Blobs converted by a previous
run (listed in eu_graphics.json) are converted again from the EU ROM, so the tool can be rerun.

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
    """(EU address, bytes, labels) of the blobs still in data/eu/bin and of those already
    converted (eu_graphics.json, bytes read from the EU ROM)."""
    rom = open(_BASEROM, 'rb').read()
    out = []
    if os.path.exists(_W + '/eu_graphics.json'):
        for a, g in json.load(open(_W + '/eu_graphics.json')).items():
            a = int(a, 16)
            out.append((a, rom[a - 0x08000000:a - 0x08000000 + g['size']], [g['label']]))
    for f in ['rom_1', 'rom_2']:
        labs = []
        for ln in open(f'{_R}/data/eu/{f}.s', encoding='utf-8'):
            m = re.match(r'^(\w+)::', ln)
            if m:
                labs.append(m.group(1))
                continue
            m = re.search(r'\.incbin "data/eu/bin/\w+_([0-9A-F]{8})\.bin"', ln)
            if m:
                path = re.search(r'"([^"]+)"', ln).group(1)
                out.append((int(m.group(1), 16), open(_R + '/' + path, 'rb').read(), list(labs)))
            if ln.strip() and not ln.strip().startswith('@'):
                labs = []
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
    if ext == 'bin':
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
    Returns [(label, [(piece, size)])], trying first exact sizes, then a resized image."""
    plan, pos = [], 0
    for lab, lines in items[k:]:
        pieces = parse_item(lines)
        sized = []
        for pc in pieces:
            n = piece_size(pc, data, pos, addr)
            sized.append((pc, n))
            pos += n
        plan.append((lab, sized))
        if pos == len(data):
            return plan
        if pos > len(data) or not plan[-1][1] or len(plan) > 64:
            break
    # a single item whose first piece (an image) has a different size; the trailing
    # .space/.fill/.align are kept when the data still has room for them
    pieces = parse_item(items[k][1])
    if not pieces or pieces[0][0] != 'inc' or pieces[0][1].endswith('.lz') or any(p[0] == 'inc' for p in pieces[1:]):
        raise Unsupported('size')
    for keep in range(len(pieces), 0, -1):
        tail = pieces[1:keep]
        if any(p[0] == 'align' for p in tail):
            continue
        n = len(data) - sum(p[1] for p in tail)
        if n <= 0:
            continue
        return [(items[k][0], [(pieces[0], n)] + [(p, p[1]) for p in tail])]
    raise Unsupported('size')


def main():
    global RULES
    RULES = make_rules()
    items = us_items()
    index = {}
    for i, (lab, lines) in enumerate(items):
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
        blobs.setdefault(addr, (data, labs))  # converted ones first, then data/eu/bin
    for addr, (data, labs) in sorted(blobs.items()):
        lab = labs[0] if labs else None
        m = SUF.match(lab or '')
        base, suffix = (m.group(1), m.group(2)) if m else (lab, None)
        if base not in index:
            why['no US counterpart'] += 1
            if VERBOSE:
                print('skip 0x%08X %s no US counterpart' % (addr, lab))
            continue
        written = []
        try:
            plan = layout(items, index[base], data, addr)
            out_lines = []
            rules_here = {}
            made_here = set()
            pos = 0
            for n_item, (ilab, sized) in enumerate(plan):
                if n_item:
                    name = ilab + ('_' + suffix if suffix else '')
                    out_lines.append(f'{name}::' if name not in known else f'@ {name}')
                for pc, size in sized:
                    chunk = data[pos:pos + size]
                    pos += size
                    if pc[0] in ('space', 'align'):
                        if any(chunk):
                            raise Unsupported('nonzero space')
                        out_lines.append('.space 0x%X' % size if pc[0] == 'space' else '.align %d' % pc[1])
                        continue
                    if pc[0] == 'fill':
                        if chunk != bytes([pc[2]]) * size:
                            raise Unsupported('fill value')
                        out_lines.append('.fill 0x%X, 1, 0x%X' % (size, pc[2]))
                        continue
                    g = pc[1]
                    t = g[:-3] if g.endswith('.lz') else g
                    ext = t.rsplit('.', 1)[1]
                    stem = t.rsplit('.', 1)[0] + '_' + (suffix.lower() if suffix else 'eu')
                    key = stem + '.' + ext
                    if key in made or key in made_here:
                        raise Unsupported('duplicate ' + key)
                    try:
                        # files created are removed again if the blob fails
                        out_lines.append('.incbin "%s"' % convert(g, chunk, stem, rules_here, written))
                    except RuntimeError as e:
                        raise Unsupported('gbagfx: ' + str(e))
                    made_here.add(key)
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
