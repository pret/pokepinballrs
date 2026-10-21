#!/usr/bin/env python3
"""Convert an EU ROM function to an asm_unified() body for a NAKED C function.
usage: fn2asm.py EU_ADDR END_ADDR  (END = start of the next function)
Literal pool words become symbol references; BL targets become function names.
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, json, struct, bisect, subprocess, re, os
sys.path.insert(0, _T)
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
EU = open(_BASEROM, 'rb').read()
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
def u32(a): return struct.unpack_from('<I', EU, a - 0x08000000)[0]
def u16(a): return struct.unpack_from('<H', EU, a - 0x08000000)[0]

def build_names():
    names = {}  # addr -> name (preferred)
    funcs = {}
    import cmp_eu_lib as C
    for objpath, start, fl, data, relocs in C.iter_matched():
        for (fo, fs, fn, ea, ok) in fl: funcs[ea] = fn
    # libraries: EU anchor + offset inside our linked lib object
    anch = json.load(open(_W + '/obj_starts.json'))
    mp = open(_R + '/pokepinballrs_eu.map').read()
    nmout = subprocess.run(['arm-none-eabi-nm', _R + '/pokepinballrs_eu.elf'], capture_output=True, text=True).stdout
    ours = {}
    for l in nmout.splitlines():
        p = l.split()
        if len(p) == 3: ours[p[2]] = int(p[0], 16)
    for k, v in anch.items():
        if '.a(' not in k: continue
        m = re.search(r'^ \.text\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+) .*' + re.escape(k.split('(')[1].rstrip(')')) + r'\)$', mp, re.M)
        if not m: continue
        ostart = int(m.group(1), 16); osz = int(m.group(2), 16)
        for n, a in ours.items():
            if ostart <= a < ostart + osz and not n.startswith('$') and not n.startswith('.'):
                funcs.setdefault(int(v, 16) + (a - ostart), n)
    data = json.load(open(_W + '/eu_data_labels.json'))
    cs = {k: int(v, 16) for k, v in json.load(open(_W + '/code_syms.json')).items()}
    # RAM labels
    ram = {}
    for f in ['sym_ewram_eu.txt', 'sym_bss_eu.txt']:
        for ln in open(_R + '/' + f):
            m = re.match(r'^(\w+): @ (0x[0-9A-Fa-f]+)', ln)
            if m: ram[int(m.group(2), 16)] = m.group(1)
    for n, a in cs.items():
        if 0x02000000 <= a < 0x04000000: ram.setdefault(a, n)
    rom = {}
    for n, a in data.items(): rom.setdefault(a, []).append(n)
    for n, a in cs.items():
        if 0x08000000 <= a < 0x09000000 and not (a & 1): rom.setdefault(a, []).insert(0, n)
    return funcs, rom, ram, cs

def pick(lst, prefer):
    for n in lst:
        if n in prefer: return n
    for n in lst:
        if not n.startswith(('gUnknown', 'gSpriteSetRawDup', 'gPackedOamDup')): return n
    return lst[0]

def main():
    a = int(sys.argv[1], 16); end = int(sys.argv[2], 16)
    prefer = set(sys.argv[3].split(',')) if len(sys.argv) > 3 else set()
    funcs, rom, ram, cs = build_names()
    rom_addrs = sorted(rom); ram_addrs = sorted(ram)
    def symref(v):
        if a <= v < end: return f'_{v:08X}'
        if (v & 1) and (v & ~1) in funcs: return funcs[v & ~1]
        if v in funcs and not (v & 1): return funcs[v] + ' - 1'
        if 0x08000000 <= v < 0x0a000000:
            i = bisect.bisect_right(rom_addrs, v) - 1
            if i >= 0 and v - rom_addrs[i] < 0x40000:
                n = pick(rom[rom_addrs[i]], prefer); d = v - rom_addrs[i]
                return n if d == 0 else f'{n} + 0x{d:X}'
        if 0x02000000 <= v < 0x02040000 or 0x03000000 <= v < 0x03008000:
            i = bisect.bisect_right(ram_addrs, v) - 1
            if i >= 0:
                n = ram[ram_addrs[i]]; d = v - ram_addrs[i]
                return n if d == 0 else f'{n} + 0x{d:X}'
        return f'0x{v:X}'
    n = end - a
    code = EU[a - 0x08000000:end - 0x08000000]
    lits = set(); targets = set(); jts = {}
    pos = 0; lastlit = None
    while pos < n:
        ad = a + pos
        if ad in lits or any(ad >= t and ad < t + 4 * len(e) for t, e in jts.items()):
            pos += 2; continue
        ins = list(md.disasm(code[pos:pos + 4], ad, count=1))
        if not ins: pos += 2; continue
        ins = ins[0]
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            la = ((ad + 4) & ~3) + imm
            lits.add(la)
            lv = u32(la)
            if a <= lv < end: lastlit = lv
        if ins.mnemonic.startswith('b') and ins.mnemonic not in ('bl', 'bx', 'bic', 'bics', 'blx') and '#' in ins.op_str:
            targets.add(int(ins.op_str.split('#')[-1], 16))
        if ins.mnemonic == 'mov' and ins.op_str.startswith('pc,'):
            t0 = lastlit; t = t0; ents = []
            while t is not None and t < end and a <= u32(t) < end:
                ents.append(u32(t)); t += 4
            if ents: jts[t0] = ents
            for e in ents: targets.add(e)
        pos += ins.size
    out = []
    pos = 0
    while pos < n:
        ad = a + pos
        lab = f'_{ad:08X}:' if (ad in targets or ad in lits or ad in jts) else ''
        if ad in jts:
            for k, e in enumerate(jts[ad]):
                out.append((f'_{ad:08X}:' if k == 0 else '', f'.4byte _{e:08X} @ case {k}'))
            pos += 4 * len(jts[ad]); continue
        if ad in lits:
            out.append((lab, f'.4byte {symref(u32(ad))}')); pos += 4; continue
        ins = list(md.disasm(code[pos:pos + 4], ad, count=1))
        if not ins:
            out.append((lab, f'.2byte 0x{u16(ad):04X}')); pos += 2; continue
        ins = ins[0]
        txt = f'{ins.mnemonic} {ins.op_str}'.strip()
        if ins.mnemonic == 'ldr' and '[pc' in ins.op_str:
            imm = int(ins.op_str.split('#')[-1].rstrip(']'), 16) if '#' in ins.op_str else 0
            la = ((ad + 4) & ~3) + imm
            txt = f'ldr {ins.op_str.split(",")[0]}, _{la:08X}'
        elif ins.mnemonic == 'bl':
            t = int(ins.op_str.split('#')[-1], 16)
            txt = 'bl ' + funcs.get(t, f'0x{t:X}')
        elif ins.mnemonic.startswith('b') and '#' in ins.op_str and ins.mnemonic not in ('bic', 'bics'):
            t = int(ins.op_str.split('#')[-1], 16)
            txt = f'{ins.mnemonic} _{t:08X}'
        elif ins.mnemonic in ('adr',) or ('pc' in ins.op_str and ins.mnemonic == 'add' and '#' in ins.op_str):
            txt = f'.2byte 0x{u16(ad):04X} @ {txt}'
        m2 = re.match(r'add (r\d+), sp, (r\d+)$', txt)
        if m2 and m2.group(1) == m2.group(2): txt = f'add {m2.group(1)}, sp'
        txt = re.sub(r'#0x([0-9a-f]+)', lambda m: '#0x' + m.group(1).upper(), txt)
        out.append((lab, txt))
        pos += ins.size
    for lab, txt in out:
        print(f'\t"{lab}\\t{txt}\\n"' if lab else f'\t"\\t{txt}\\n"')
main()
