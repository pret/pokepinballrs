#!/usr/bin/env python3
"""Compare compiled EU objects against the EU baserom, sequentially in link order.
usage: cmp_eu.py [objname-substring ...]  (-v for per-function detail)
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, re, json, struct, os
from elftools.elf.elffile import ELFFile
REPO = _R
EU = open(_BASEROM, 'rb').read()
BUILD = REPO + '/build/pokepinballrs_eu'
LD = REPO + '/ld_script_eu.txt' if os.path.exists(REPO + '/ld_script_eu.txt') else REPO + '/ld_script.txt'
ANCH = json.load(open(_W + '/obj_starts.json')) if os.path.exists(_W + '/obj_starts.json') else {}

def text_objs():
    s = open(LD).read()
    m = re.search(r'\.text\s*:\s*\{(.*?)\}', s, re.S)
    out = []
    for l in m.group(1).splitlines():
        mm = re.match(r'\s*(\S+\.o)\(\.text\);', l)
        if mm: out.append(mm.group(1))
    return out

def load_obj(path):
    f = ELFFile(open(path, 'rb'))
    t = f.get_section_by_name('.text')
    data = t.data() if t else b''
    mask = bytearray(len(data))
    relocs = []
    rs = f.get_section_by_name('.rel.text')
    symtab = f.get_section_by_name('.symtab')
    syms = list(symtab.iter_symbols())
    if rs:
        for r in rs.iter_relocations():
            o = r['r_offset']; ty = r['r_info_type']
            n = 2 if ty in (102, 103) else 4
            for i in range(n):
                if o + i < len(mask): mask[o + i] = 1
            s = syms[r['r_info_sym']]
            relocs.append((o, ty, s.name, s['st_shndx'], s['st_value']))
    # mask intra-object BL calls too (resolved by the assembler without relocations)
    for o in range(0, len(data) - 3, 2):
        h1 = data[o] | (data[o+1] << 8); h2 = data[o+2] | (data[o+3] << 8)
        if (h1 & 0xF800) == 0xF000 and (h2 & 0xF800) == 0xF800:
            for i in range(4): mask[o + i] = 1
    tidx = [i for i, s in enumerate(f.iter_sections()) if s.name == '.text']
    funcs = []
    for s in syms:
        if s['st_info']['type'] == 'STT_FUNC' and tidx and s['st_shndx'] == tidx[0]:
            funcs.append((s['st_value'] & ~1, s['st_size'], s.name))
    funcs.sort()
    return data, mask, funcs, relocs, (t['sh_addralign'] if t else 4)

def cmp_at(data, mask, start, lo, hi):
    off = start - 0x08000000
    nd = 0; first = None
    for i in range(lo, hi):
        if mask[i]: continue
        if off + i >= len(EU) or data[i] != EU[off + i]:
            nd += 1
            if first is None: first = i
    return nd, first

def main():
    verbose = '-v' in sys.argv
    filt = [a for a in sys.argv[1:] if not a.startswith('-')]
    cur = 0x08000000
    prev_ok = False
    total_ok = total = 0
    report = []
    for objpath in text_objs():
        name = objpath
        if not objpath.startswith('src/') and not objpath.startswith('asm/') and not objpath.startswith('data/'):
            # libs: skip but advance using anchors
            if name in ANCH: cur = int(ANCH[name], 16)
            continue
        p = BUILD + '/' + objpath
        if not os.path.exists(p):
            print('missing', objpath); continue
        data, mask, funcs, relocs, align = load_obj(p)
        start = (cur + align - 1) & ~(align - 1)
        if objpath in ANCH and ANCH[objpath] and not prev_ok:
            a = int(ANCH[objpath], 16)
            if a != start and verbose: print(f'  [anchor override {hex(start)} -> {hex(a)}]')
            start = a
        if not prev_ok and funcs:
            # resync: look for the first function near the predicted address
            fo, fs, fn = funcs[0]
            fs = min(fs, 0x200)
            if cmp_at(data, mask, start, fo, fo + fs)[0] != 0:
                best = None
                for delta in sorted(range(-0x800, 0x802, 2), key=abs):
                    if cmp_at(data, mask, start + delta, fo, fo + fs)[0] == 0:
                        best = start + delta; break
                if best is not None:
                    if verbose: print(f'  [resync {hex(start)} -> {hex(best)}]')
                    start = best
        nd, first = cmp_at(data, mask, start, 0, len(data))
        nf = len(funcs)
        fok = 0; firstbad = None
        details = []
        shift = 0
        for (fo, fs, fn) in funcs:
            d, fi = cmp_at(data, mask, start + shift, fo, fo + fs)
            if d != 0 and nd:
                # try to find the function nearby (a previous function may have a different size)
                for delta in sorted(range(-0x400, 0x402, 2), key=abs):
                    if cmp_at(data, mask, start + shift + delta, fo, fo + fs)[0] == 0:
                        shift += delta; d = 0; break
            if d == 0: fok += 1
            elif firstbad is None: firstbad = (fn, hex(start + shift + fo), d)
            details.append((fn, start + shift + fo, fs, d))
        total += nf; total_ok += fok
        status = 'OK ' if nd == 0 else 'BAD'
        show = (not filt) or any(f in objpath for f in filt)
        if show:
            print(f'{status} {objpath:48s} eu={start:08x} size={len(data):5x} funcs {fok}/{nf}' + (f'  first bad: {firstbad}' if firstbad else ''))
            if verbose and nd:
                for fn, fa, fs, d in details:
                    print(f'      {"ok " if d == 0 else "BAD"} {fn:50s} {fa:08x} {fs:5x} diff={d}')
        report.append(dict(obj=objpath, eu=hex(start), size=len(data), ok=nd == 0, fok=fok, nf=nf))
        cur = start + len(data)
        prev_ok = (nd == 0)
    print(f'TOTAL functions matching in place: {total_ok}/{total}; objects OK: {sum(r["ok"] for r in report)}/{len(report)}')
    json.dump(report, open(_W + '/cmp_report.json', 'w'), indent=0)


def iter_matched():
    cur = 0x08000000
    prev_ok = False
    for objpath in text_objs():
        if not objpath.startswith(('src/','asm/','data/')):
            if objpath in ANCH: cur = int(ANCH[objpath], 16)
            continue
        p = BUILD + '/' + objpath
        if not os.path.exists(p): continue
        data, mask, funcs, relocs, align = load_obj(p)
        start = (cur + align - 1) & ~(align - 1)
        if objpath in ANCH and ANCH[objpath] and not prev_ok:
            start = int(ANCH[objpath], 16)
        if not prev_ok and funcs:
            fo, fs, fn = funcs[0]
            fs = min(fs, 0x200)
            if cmp_at(data, mask, start, fo, fo + fs)[0] != 0:
                for delta in sorted(range(-0x800, 0x802, 2), key=abs):
                    if cmp_at(data, mask, start + delta, fo, fo + fs)[0] == 0:
                        start = start + delta; break
        nd, first = cmp_at(data, mask, start, 0, len(data))
        shift = 0; out = []
        for (fo, fs, fn) in funcs:
            d, fi = cmp_at(data, mask, start + shift, fo, fo + fs)
            if d != 0 and nd:
                for delta in sorted(range(-0x400, 0x402, 2), key=abs):
                    if cmp_at(data, mask, start + shift + delta, fo, fo + fs)[0] == 0:
                        shift += delta; d = 0; break
            out.append((fo, fs, fn, start + shift + fo, d == 0))
        yield objpath, start, out, data, relocs
        cur = start + len(data)
        prev_ok = (nd == 0)
