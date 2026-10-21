#!/usr/bin/env python3
"""Summarize language switches of an EU function: for each jump table on gMain.saveData.language,
print case -> target and the 0x08xxxxxx literals loaded in each case block.
usage: langsw.py ADDR SIZE"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, subprocess, re
addr = int(sys.argv[1], 16); size = int(sys.argv[2], 16)
out = subprocess.run(['python3', _T + '/eudis.py', '%x' % addr, '%x' % size], capture_output=True, text=True).stdout.splitlines()
rows = []
for l in out:
    m = re.match(r'\s*([0-9a-f]{8}):\s*(.*)', l)
    if m: rows.append((int(m.group(1), 16), m.group(2).strip()))
# find case tables
i = 0
while i < len(rows):
    a, t = rows[i]
    if '@ case 0' in t:
        cases = []
        j = i
        while j < len(rows) and '@ case' in rows[j][1]:
            tg = int(re.search(r'_([0-9a-f]{8})', rows[j][1]).group(1), 16)
            cases.append(tg); j += 1
        print(f'switch table at {a:08x}: ' + ' '.join(f'{k}:{c:08x}' for k, c in enumerate(cases)))
        for k, c in enumerate(cases):
            lits = []
            for (b, u) in rows:
                if b >= c and len(lits) < 4:
                    mm = re.search(r'=0x(8[0-9a-f]{6})\b', u)
                    if mm: lits.append(mm.group(1))
                    if u.startswith('b _') or 'bl sub_' in u or u.startswith('_') and ' b _' in u: break
            print(f'   case {k}: {c:08x} lits {lits}')
        i = j
    else:
        i += 1
