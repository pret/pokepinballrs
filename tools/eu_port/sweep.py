"""Linear-sweep function boundary finder for agbcc Thumb code."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import struct, sys, json
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM
from capstone.arm import ARM_OP_IMM, ARM_OP_MEM, ARM_REG_PC

md = Cs(CS_ARCH_ARM, CS_MODE_THUMB); md.detail = True

def u16(rom, a): return struct.unpack_from('<H', rom, a - 0x08000000)[0]
def u32(rom, a): return struct.unpack_from('<I', rom, a - 0x08000000)[0]

def decode(rom, a):
    """decode a single thumb instruction at a; returns (size, kind, info)."""
    h = u16(rom, a)
    # BL pair
    if (h & 0xF800) == 0xF000:
        h2 = u16(rom, a+2)
        if (h2 & 0xF800) == 0xF800:
            o = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
            if o & 0x400000: o -= 0x800000
            return 4, 'bl', a + 4 + o
    # ldr rX, [pc, #imm]
    if (h & 0xF800) == 0x4800:
        lit = ((a + 4) & ~3) + (h & 0xFF) * 4
        return 2, 'ldrpc', lit
    # add rX, pc, #imm (adr)
    if (h & 0xF800) == 0xA000:
        return 2, 'adr', ((a + 4) & ~3) + (h & 0xFF) * 4
    # b (unconditional)
    if (h & 0xF800) == 0xE000:
        o = (h & 0x7FF) << 1
        if o & 0x800: o -= 0x1000
        return 2, 'b', a + 4 + o
    # conditional branch
    if (h & 0xF000) == 0xD000 and (h & 0x0F00) not in (0x0E00, 0x0F00):
        o = (h & 0xFF) << 1
        if o & 0x100: o -= 0x200
        return 2, 'bcc', a + 4 + o
    # bx rX
    if (h & 0xFF87) == 0x4700:
        return 2, 'bx', (h >> 3) & 0xF
    # mov pc, rX  (hi reg mov with rd=pc): 0100 0110 H1 H2 Rm Rd ; rd=pc => H1=1, rd bits=111
    if (h & 0xFF00) == 0x4600 and (h & 0x87) == 0x87:
        return 2, 'movpc', (h >> 3) & 0xF
    # pop {.., pc}
    if (h & 0xFF00) == 0xBD00:
        return 2, 'poppc', None
    # swi
    if (h & 0xFF00) == 0xDF00:
        return 2, 'swi', h & 0xFF
    return 2, 'op', None

def sweep_function(rom, start, limit):
    """Return (end_of_code, end_including_pool, branch_targets, calls, literals)."""
    a = start
    maxtarget = start
    maxlit = start
    calls = set(); lits = set(); targets = set()
    jt_ranges = []
    while a < limit:
        # skip into jump table ranges
        skip = False
        for (s, e) in jt_ranges:
            if s <= a < e:
                a = e; skip = True
        if skip: continue
        if a in lits or any(l <= a < l + 4 for l in lits):
            # we ran into a literal; stop (function ended earlier) - shouldn't happen
            pass
        sz, kind, info = decode(rom, a)
        if kind == 'bl':
            calls.add(info)
        elif kind == 'ldrpc':
            lits.add(info); maxlit = max(maxlit, info + 4)
        elif kind == 'adr':
            pass
        elif kind in ('b', 'bcc'):
            targets.add(info)
            if info > maxtarget: maxtarget = info
        elif kind == 'movpc':
            # jump table: find table address: previous ldr literal value
            # table begins at next 4-aligned addr after this instr (agbcc places it inline)
            tbl = (a + 2 + 3) & ~3
            t = tbl
            ents = []
            while t + 4 <= limit:
                v = u32(rom, t)
                if start <= v < limit + 0x10000 and (v & 1) == 0 and v > a:
                    ents.append(v); t += 4
                else:
                    break
            if ents:
                jt_ranges.append((a + 2, t))
                for v in ents:
                    targets.add(v); maxtarget = max(maxtarget, v)
                a = t
                continue
        a += sz
        if kind in ('b', 'poppc', 'bx', 'movpc') and a > maxtarget:
            # end of code
            code_end = a
            end = max(code_end, maxlit)
            # literal pool may contain more words after the max referenced? no.
            return code_end, end, targets, calls, lits
    return a, a, targets, calls, lits

def sweep_region(rom, start, end):
    funcs = []
    a = start
    while a < end:
        # skip alignment padding (0x0000) to 4
        while a < end and a % 4 != 0 and u16(rom, a) == 0:
            a += 2
        if a >= end: break
        ce, fe, t, c, l = sweep_function(rom, a, end)
        funcs.append((a, fe - a, ce - a))
        a = fe
    return funcs

if __name__ == '__main__':
    rom = open(sys.argv[1], 'rb').read()
    s, e = int(sys.argv[2], 16), int(sys.argv[3], 16)
    for f in sweep_region(rom, s, e):
        print(hex(f[0]), hex(f[1]))
