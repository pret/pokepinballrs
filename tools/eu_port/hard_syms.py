#!/usr/bin/env python3
"""Map literal-pool symbols of non-matching functions by literal order."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, json, struct
sys.path.insert(0, _T)
import cmp_eu_lib as C
EU = C.EU
res = {}
allf = []
for objpath, start, funcs, data, relocs in C.iter_matched():
    for f in funcs: allf.append((objpath, f, data, relocs))
for k, (objpath, (fo, fs, fn, ea, ok), data, relocs) in enumerate(allf):
    if ok: continue
    nxt = allf[k + 1][1][3] if k + 1 < len(allf) else ea + fs
    ours = [(o, name, struct.unpack_from('<I', data, o)[0]) for (o, ty, name, sh, val) in sorted(relocs) if ty == 2 and fo <= o < fo + fs]
    eus = []
    for a in range(ea, nxt, 4):
        if a & 3: continue
        w = struct.unpack_from('<I', EU, a - 0x08000000)[0]
        if 0x02000000 <= w < 0x04000000 or 0x08000000 <= w < 0x09000000:
            eus.append(w)
    print(fn, hex(ea), 'ours', len(ours), 'eu', len(eus))
    # remove jump table entries (relocs against section symbol '') from ours: they point into own function
    ours2 = [x for x in ours if x[1]]
    eus2 = [w for w in eus if not (ea <= w < nxt)]
    if len(ours2) != len(eus2):
        print('   count mismatch', len(ours2), len(eus2))
        for x in ours2: print('     ', x[1], hex(x[2]))
        print('    ', [hex(w) for w in eus2])
        continue
    for (o, name, add), w in zip(ours2, eus2):
        v = w - add
        if name in res and res[name] != v: print('   conflict', name, hex(res[name]), hex(v))
        res.setdefault(name, v)
json.dump({k: hex(v) for k, v in res.items()}, open(_W + '/hard_syms.json', 'w'), indent=0, sort_keys=True)
cs = json.load(open(_W + '/code_syms.json'))
for k, v in sorted(res.items()):
    if k in cs and int(cs[k], 16) != v: print('DIFF vs code_syms', k, cs[k], hex(v))
    elif k not in cs: print('new', k, hex(v))
