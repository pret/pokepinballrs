#!/usr/bin/env python3
"""Generate sym_ewram_eu.txt (and copy bss/common) from the US files + EU addresses."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import json, re, glob
REPO = _R
L = json.load(open(_W + '/layout.json'))
eu = {k: v for k, v in L['eu_syms'].items()}
cs = {k: int(v, 16) for k, v in json.load(open(_W + '/code_syms.json')).items()}
eu.update(cs)
ent = []  # (label, us_addr)
addr = 0x02000000
for ln in open(REPO + '/sym_ewram.txt'):
    m = re.match(r'^(\w+):', ln)
    if m: ent.append([m.group(1), addr]); continue
    m = re.match(r'^\s*\.space\s+(0x[0-9A-Fa-f]+|\d+)', ln)
    if m: addr += int(m.group(1), 0)
ewram_end_us = addr
removed = {'gIntroJingleVariant'}  # not present in the European build
GMAIN_DELTA = {'gMain_saveData_pokedexFlags_90': 0, 'gMain_saveData_customButtonConfig': 2}
out = {}
for n, a in ent:
    if n in removed: continue
    if n in eu and 0x02000000 <= eu[n] < 0x02040000:
        out[n] = eu[n]
    elif n.startswith('gMain_'):
        out[n] = a + GMAIN_DELTA.get(n, 4)
    else:
        out[n] = None
# infer unknowns from neighbours with equal deltas
names = [n for n, a in ent if n not in removed]
usa = dict((n, a) for n, a in ent)
for i, n in enumerate(names):
    if out[n] is not None: continue
    p = i - 1
    while out[names[p]] is None: p -= 1
    q = i + 1
    while out[names[q]] is None: q += 1
    dp = out[names[p]] - usa[names[p]]; dq = out[names[q]] - usa[names[q]]
    if dp == dq:
        out[n] = usa[n] + dp
        print('inferred', n, hex(out[n]))
    else:
        raise SystemExit(f'cannot infer {n}: deltas {dp:#x} {dq:#x}')
# EU-only labels
us_names = set(names)
for n, a in eu.items():
    if 0x02000000 <= a < 0x02031810 and n not in us_names and n not in removed:
        out[n] = a; print('EU-only', n, hex(a))
# check: gMain_* consistency with known code refs
srt = sorted(out.items(), key=lambda x: (x[1], x[0]))
end = 0x02031810  # start of COMMON (gSoundInfo) in the EU build
lines = []
for k, (n, a) in enumerate(srt):
    nxt = srt[k + 1][1] if k + 1 < len(srt) else end
    lines.append(f'{n}: @ 0x{a:08X}')
    if nxt > a: lines.append(f'\t.space 0x{nxt - a:X}')
    elif nxt < a: raise SystemExit('overlap')
open(REPO + '/sym_ewram_eu.txt', 'w', newline='\n').write('\n'.join(lines) + '\n')
print(len(srt), 'labels')
