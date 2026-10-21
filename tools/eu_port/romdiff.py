#!/usr/bin/env python3
"""Compare built EU ROM vs baserom: list differing regions with the nearest symbol."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, bisect, subprocess
A = open(_R + '/pokepinballrs_eu.gba', 'rb').read()
B = open(_BASEROM, 'rb').read()
print('sizes', hex(len(A)), hex(len(B)))
syms = []
for l in subprocess.run(['arm-none-eabi-nm', '-n', _R + '/pokepinballrs_eu.elf'], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3 and p[1] in 'tTdDrRbB' and int(p[0], 16) >= 0x08000000: syms.append((int(p[0], 16), p[2]))
syms.sort(); addrs = [s[0] for s in syms]
def near(a):
    i = bisect.bisect_right(addrs, a) - 1
    return f'{syms[i][1]}+{a - syms[i][0]:#x}' if i >= 0 else '?'
n = min(len(A), len(B))
regs = []
i = 0
while i < n:
    if A[i] != B[i]:
        j = i
        while j < n and (A[j] != B[j] or (j + 16 < n and A[j:j+16] != B[j:j+16])): j += 1
        regs.append((i, j)); i = j
    else: i += 1
print(len(regs), 'differing regions, bytes', sum(b - a for a, b in regs))
for a, b in regs[:int(sys.argv[1]) if len(sys.argv) > 1 else 40]:
    print(f'{0x08000000 + a:08x}-{0x08000000 + b:08x} ({b - a:#x}) {near(0x08000000 + a)}')
