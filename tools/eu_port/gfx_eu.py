#!/usr/bin/env python3
"""Turn EU-only graphics blobs (data/eu/bin) into per-language copies of the US graphics files.

For each blob whose US counterpart (same label without the language suffix) is made only of
.incbin of files under graphics/ and .space, with the same total size, write
<US file stem>_<language>.png/.pal/.bin next to the US file, check that gbagfx converts it back
to the same bytes, and record:
  - the directives that replace the blob in tools/eu_port/data/eu_graphics.json (read by
    gen_eu_data.py, so run regen.sh afterwards);
  - the conversion rules of files that need gbagfx options in graphics_rules_eu.mk.
Blobs that cannot be reproduced exactly are left as they are.

Run from the repository root in the build environment (uses tools/gbagfx/gbagfx).
usage: gfx_eu.py [-v]"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')
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
    us = {}
    for f in ['data/rom_1.s', 'data/rom_2.s']:
        lab = None
        for ln in flat(f):
            m = re.match(r'^(\w+)::', ln)
            if m:
                lab = m.group(1)
                us[lab] = []
                continue
            s = ln.split('@')[0].strip().rstrip(';').strip()
            if lab and s:
                us[lab].append(s)
    return us


def eu_blobs():
    out = []
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
                out.append((int(m.group(1), 16), path, list(labs)))
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


def convert(g, data, stem, new_rules):
    """Write the EU copy of graphics file g (US path) holding data; return its .incbin path."""
    lz = g.endswith('.lz')
    t = g[:-3] if lz else g
    base, ext = t.rsplit('.', 1)
    raw = data
    if lz:
        gfx(tmp('in.lz', data), tmp('in.raw'))
        raw = open(tmp('in.raw'), 'rb').read()
    out_t = f'{stem}.{ext}'
    if ext == 'bin':
        open(_R + '/' + out_t, 'wb').write(raw)
    elif ext == 'gbapal':
        if t in RULES:
            raise Unsupported('rule for ' + t)
        gfx(tmp('in.gbapal', raw), _R + f'/{stem}.pal')
        gfx(_R + f'/{stem}.pal', tmp('chk.gbapal'))
        if open(tmp('chk.gbapal'), 'rb').read() != raw:
            raise Unsupported('palette round trip ' + t)
    else:
        us_png = _R + f'/{base}.png'
        if not os.path.exists(us_png):
            raise Unsupported('no png for ' + t)
        flags = []
        rule = RULES.get(t)
        if rule:
            prereqs, recipe = rule
            if len(recipe) != 1 or not recipe[0].startswith('$(GFX) $< $@') or not prereqs or prereqs[0] != f'{base}.png':
                raise Unsupported('rule ' + t)
            toks = recipe[0].split()[3:]
            i = 0
            while i < len(toks):
                if toks[i] not in ALLOWED_FLAGS:
                    raise Unsupported('flag %s for %s' % (toks[i], t))
                n = ALLOWED_FLAGS[toks[i]]
                flags += toks[i:i + 1 + n]
                i += 1 + n
        w, h, depth, ctype, has_pal = png_info(us_png)
        inv = [f for i, f in enumerate(flags) if f != '-num_tiles' and (i == 0 or flags[i - 1] != '-num_tiles')]
        bpp = 4 if ext == '4bpp' else 8
        tile = 8 * bpp
        full = (w // 8) * (h // 8) * tile
        inraw = raw + bytes(max(0, full - len(raw))) if '-num_tiles' in flags else raw
        args = [tmp('in.' + ext, inraw), _R + f'/{stem}.png', '-width', w // 8] + inv
        if has_pal:
            gfx(us_png, tmp('pal.gbapal'))
            pal = open(tmp('pal.gbapal'), 'rb').read()[:2 << bpp]
            args += ['-palette', tmp('pal.gbapal', pal)]
        gfx(*args)
        gfx(_R + f'/{stem}.png', tmp('chk.' + ext), *flags)
        if open(tmp('chk.' + ext), 'rb').read() != raw:
            raise Unsupported('round trip ' + t)
        if flags:
            new_rules[out_t] = (f'{stem}.png', ' '.join(flags))
    if lz:
        gfx(tmp('chk.raw', raw), tmp('chk.lz'))
        if open(tmp('chk.lz'), 'rb').read() != data:
            raise Unsupported('lz compression differs ' + t)
        return out_t + '.lz'
    return out_t


def main():
    global RULES
    RULES = make_rules()
    us = us_items()
    result = {}
    new_rules = {}
    made = set()
    why = collections.Counter()
    for addr, path, labs in eu_blobs():
        data = open(_R + '/' + path, 'rb').read()
        lab = labs[0] if labs else None
        m = SUF.match(lab or '')
        base, suffix = (m.group(1), m.group(2)) if m else (lab, None)
        lines = us.get(base)
        if not lines:
            why['no US counterpart'] += 1
            continue
        pieces = []
        written = []
        try:
            for l in lines:
                mi, ms = INC.match(l), SPACE.match(l)
                if mi:
                    g = mi.group(1)
                    if not os.path.exists(_R + '/' + g):
                        raise Unsupported('missing ' + g)
                    pieces.append(('inc', g, os.path.getsize(_R + '/' + g)))
                elif ms:
                    pieces.append(('space', l, int(ms.group(1), 0)))
                else:
                    raise Unsupported('directive ' + l.split()[0])
            if sum(p[2] for p in pieces) != len(data):
                raise Unsupported('size')
            out_lines = []
            pos = 0
            rules_here = {}
            written = []
            for kind, g, size in pieces:
                chunk = data[pos:pos + size]
                pos += size
                if kind == 'space':
                    if any(chunk):
                        raise Unsupported('nonzero space')
                    out_lines.append(g)
                    continue
                t = g[:-3] if g.endswith('.lz') else g
                stem = t.rsplit('.', 1)[0] + '_' + (suffix.lower() if suffix else 'eu')
                key = stem + '.' + t.rsplit('.', 1)[1]
                if key in made:
                    raise Unsupported('duplicate ' + key)
                ext = t.rsplit('.', 1)[1]
                written.append(_R + '/' + stem + {'bin': '.bin', 'gbapal': '.pal'}.get(ext, '.png'))
                try:
                    out_lines.append('.incbin "%s"' % convert(g, chunk, stem, rules_here))
                except RuntimeError as e:
                    raise Unsupported('gbagfx: ' + str(e))
                made.add(key)
            new_rules.update(rules_here)
            result['0x%08X' % addr] = dict(size=len(data), label=lab, lines=out_lines)
            why['converted'] += 1
        except Unsupported as e:
            for w in written:
                if os.path.exists(w):
                    os.remove(w)
            why[str(e).split()[0]] += 1
            if VERBOSE:
                print('skip', path, lab, e)
    json.dump(result, open(_W + '/eu_graphics.json', 'w', newline='\n'), indent=1, sort_keys=True)
    with open(_R + '/graphics_rules_eu.mk', 'w', newline='\n') as f:
        f.write('# Per-language graphics of the European version that need gbagfx options.\n')
        f.write('# Generated by tools/eu_port/gfx_eu.py.\n')
        for t in sorted(new_rules):
            png, flags = new_rules[t]
            f.write(f'\n{t}: {png}\n\t$(GFX) $< $@ {flags}\n')
    for k, v in why.most_common():
        print(v, k)
    print('bytes converted', sum(r['size'] for r in result.values()))


if __name__ == '__main__':
    main()
