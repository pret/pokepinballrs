#!/usr/bin/env python3
"""For differing aligned words in a range, show our value / EU value with symbol names."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, struct, bisect, subprocess, collections
A = open(_R + '/pokepinballrs_eu.gba', 'rb').read()
B = open(_BASEROM, 'rb').read()
lo = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x08000000
hi = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x0805cac4
syms = []
for l in subprocess.run(['arm-none-eabi-nm', '-n', _R + '/pokepinballrs_eu.elf'], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3 and not p[2].startswith('$'): syms.append((int(p[0], 16), p[2]))
syms.sort(); addrs = [s[0] for s in syms]
def near(a):
    i = bisect.bisect_right(addrs, a) - 1
    return f'{syms[i][1]}+{a - syms[i][0]:#x}' if i >= 0 else '?'
cnt = collections.Counter()
rows = []
for o in range(lo - 0x08000000, hi - 0x08000000, 4):
    a, b = A[o:o+4], B[o:o+4]
    if a != b:
        va, vb = struct.unpack('<I', a)[0], struct.unpack('<I', b)[0]
        key = near(va).split('+')[0]
        cnt[(key, vb - va)] += 1
        rows.append((0x08000000 + o, va, vb))
for (k, d), c in cnt.most_common(60):
    print(f'{c:5d}  {k:45s} delta {d:#x}')
print(len(rows), 'words')
