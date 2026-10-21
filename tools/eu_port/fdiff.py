#!/usr/bin/env python3
"""Diff a compiled EU function (from object) against EU ROM.
usage: fdiff.py OBJ FUNC [EU_ADDR] [EU_SIZE]   (OBJ e.g. src/main.o)
If EU_ADDR omitted: uses cmp_report position (object start + func offset).
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, json, struct, difflib
sys.path.insert(0, _T)
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
EU = open(_BASEROM, 'rb').read()
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
BUILD = _R + '/build/pokepinballrs_eu/'

def load(objpath):
    f = ELFFile(open(BUILD + objpath, 'rb'))
    t = f.get_section_by_name('.text'); data = t.data()
    syms = list(f.get_section_by_name('.symtab').iter_symbols())
    rel = {}
    rs = f.get_section_by_name('.rel.text')
    if rs:
        for r in rs.iter_relocations():
            s = syms[r['r_info_sym']]
            nm = s.name or ('sec%d' % s['st_shndx'])
            rel[r['r_offset']] = (r['r_info_type'], nm)
    funcs = {}
    for s in syms:
        if s['st_info']['type'] == 'STT_FUNC':
            funcs[s.name] = (s['st_value'] & ~1, s['st_size'])
    return data, rel, funcs

def litset(code, n):
    lits = set(); pos = 0
    while pos < n:
        ins = list(md.disasm(code[pos:pos+4], pos, count=1))
        if not ins: pos += 2; continue
        ins = ins[0]
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            lits.add(((pos + 4) & ~3) + imm)
        pos += ins.size
    return lits

def lines(buf, base, n, rel=None, roff=0, litsrc=None):
    out = []
    i = 0
    code = buf[:n]
    lits = litset(code, n)
    if litsrc: lits |= litsrc
    pos = 0
    while pos < n:
        if pos in lits and pos + 4 <= n and not (rel is not None and (roff + pos) in rel):
            out.append((base+pos, f'.word 0x{struct.unpack_from("<I", code, pos)[0]:08x}')); pos += 4; continue
        ins = list(md.disasm(code[pos:pos+4], base + pos, count=1))
        if not ins:
            out.append((base+pos, f'.2byte 0x{struct.unpack_from("<H", code, pos)[0]:04x}')); pos += 2; continue
        ins = ins[0]
        txt = f'{ins.mnemonic} {ins.op_str}'
        if rel is not None and (roff + pos) in rel:
            ty, nm = rel[roff + pos]
            if ty == 10: txt = f'bl {nm}'
            elif ty == 2:
                txt = f'.word {nm}+0x{struct.unpack_from("<I", code, pos)[0]:x}'; out.append((base+pos, txt)); pos += 4; continue
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            la = ((base + pos + 4) & ~3) + imm
            txt += f'   ; ={hex(la)}'
        out.append((base + pos, txt)); pos += ins.size
    return out

def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    obj, fn = args[0], args[1]
    data, rel, funcs = load(obj)
    fo, fs = funcs[fn]
    if len(args) > 2:
        ea = int(args[2], 16)
    else:
        rep = {r['obj']: r for r in json.load(open(_W + '/cmp_report.json'))}
        ea = int(rep[obj]['eu'], 16) + fo
    es = int(args[3], 16) if len(args) > 3 else fs
    A = lines(data[fo:fo+fs], 0, fs, rel, fo)
    words = {o - fo for o, (ty, nm) in rel.items() if ty == 2 and fo <= o < fo + fs}
    B = lines(EU[ea-0x08000000: ea-0x08000000+es], 0, es, litsrc=words if es == fs else None)
    # normalize: strip pc-relative literal comment addresses for diff
    # raw byte differences outside relocations
    masked = set()
    for o, (ty, nm) in rel.items():
        for i in range(2 if ty in (102, 103) else 4): masked.add(o + i)
    for o in range(fo, fo + fs - 3, 2):
        h1 = data[o] | (data[o+1] << 8); h2 = data[o+2] | (data[o+3] << 8)
        if (h1 & 0xF800) == 0xF000 and (h2 & 0xF800) == 0xF800:
            for i in range(4): masked.add(o + i)
    rawd = [i for i in range(min(fs, es)) if (fo + i) not in masked and data[fo + i] != EU[ea - 0x08000000 + i]]
    if rawd: print('raw byte diffs at offsets:', ' '.join(hex(i) for i in rawd[:40]))
    def key(t):
        t = t.split('   ;')[0]
        if t.startswith('bl '): return 'bl'
        if t.startswith('.word') and '+0x' in t: return '.word'
        return t
    na = [key(t) for _, t in A]; nb = [key(t) for _, t in B]
    sm = difflib.SequenceMatcher(None, na, nb, autojunk=False)
    print(f'{fn}: obj size {fs:#x}, EU @ {ea:#x} size {es:#x}, ratio {sm.ratio():.3f}')
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i1, i2):
                if '-q' not in sys.argv: print(f'   {A[k][0]:4x} {A[k][1]:40s} | {B[j1+k-i1][1]}')
        else:
            L = max(i2-i1, j2-j1)
            for k in range(L):
                a = A[i1+k] if i1+k < i2 else None
                b = B[j1+k] if j1+k < j2 else None
                print(f' * {a[0] if a else 0:4x} {(a[1] if a else ""):40s} | {b[1] if b else ""}')
main()
