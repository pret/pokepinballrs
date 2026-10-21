#!/usr/bin/env python3
"""Disassemble EU ROM region with labels and resolved literals.
usage: eudis.py ADDR [SIZE]   (if SIZE omitted, sweep until function end)
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, json, struct, os
sys.path.insert(0, _T)
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from sweep import sweep_function
EU = open(_BASEROM, 'rb').read()
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
NAMES = {}
def load_names():
    p = _W + '/eu_names.json'
    if os.path.exists(p):
        NAMES.update({int(k, 16): v for k, v in json.load(open(p)).items()})
load_names()
def nm(v):
    if v in NAMES: return NAMES[v]
    if (v & ~1) in NAMES and v & 1: return NAMES[v & ~1] + '+1'
    return None
def u32(a): return struct.unpack_from('<I', EU, a - 0x08000000)[0]
def main():
    a = int(sys.argv[1], 16)
    if len(sys.argv) > 2:
        n = int(sys.argv[2], 16)
    else:
        ce, fe, *_ = sweep_function(EU, a, a + 0x4000)
        n = fe - a
    code = EU[a - 0x08000000: a - 0x08000000 + n]
    # pass 1: literals & targets
    lits = set(); targets = set(); jts = {}
    pos = 0; lastlit = None
    while pos < n:
        ins = list(md.disasm(code[pos:pos+4], a + pos, count=1))
        if not ins: pos += 2; continue
        ins = ins[0]
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            lits.add(((a + pos + 4) & ~3) + imm)
            lv = u32(((a + pos + 4) & ~3) + imm)
            if a <= lv < a + n: lastlit = lv
        if ins.mnemonic.startswith('b') and ins.mnemonic not in ('bl', 'bx', 'bic', 'bics') and '#' in ins.op_str:
            targets.add(int(ins.op_str.split('#')[-1], 16))
        if ins.mnemonic == 'mov' and ins.op_str.startswith('pc,'):
            t0 = lastlit if lastlit else (a + pos + 2 + 3) & ~3
            t = t0; ents = []
            while t < a + n and a <= u32(t) < a + n:
                ents.append(u32(t)); t += 4
            if ents: jts[t0] = ents
            for e in ents: targets.add(e)
        pos += ins.size
    print(f'@ EU {a:#x} size {n:#x}' + (f'  <{nm(a)}>' if nm(a) else ''))
    pos = 0
    while pos < n:
        ad = a + pos
        if ad in jts:
            for k, e in enumerate(jts[ad]):
                print(f'  {ad+4*k:08x}:   .4byte _{e:08x}   @ case {k}')
            pos += 4 * len(jts[ad]); continue
        if ad in lits:
            v = u32(ad); s = nm(v)
            print(f'  {ad:08x}: _{ad:08x}: .4byte {v:#010x}' + (f'  @ {s}' if s else '')); pos += 4; continue
        ins = list(md.disasm(code[pos:pos+4], ad, count=1))
        if not ins:
            print(f'  {ad:08x}:   .2byte {struct.unpack_from("<H", code, pos)[0]:#06x}'); pos += 2; continue
        ins = ins[0]
        txt = f'{ins.mnemonic} {ins.op_str}'
        extra = ''
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            la = ((ad + 4) & ~3) + imm
            v = u32(la); s = nm(v)
            txt = f'ldr {ins.op_str.split(",")[0]}, =' + (s if s else f'{v:#x}')
        if ins.mnemonic == 'bl':
            t = int(ins.op_str.split('#')[-1], 16); s = nm(t)
            txt = 'bl ' + (s if s else f'sub_{t:08x}')
        elif ins.mnemonic.startswith('b') and '#' in ins.op_str and ins.mnemonic not in ('bic', 'bics'):
            t = int(ins.op_str.split('#')[-1], 16)
            txt = f'{ins.mnemonic} _{t:08x}'
        lab = f'_{ad:08x}:' if ad in targets else ''
        print(f'  {ad:08x}: {lab:11s} {txt}')
        pos += ins.size
main()
