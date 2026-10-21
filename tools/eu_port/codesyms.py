#!/usr/bin/env python3
"""Derive EU addresses of external symbols referenced from the EU-compiled C objects.
For each function that matches the EU ROM (found by the same resync as cmp_eu), every
R_ARM_ABS32 relocation gives symbol = EU_word - addend.  Output: tools/eu_port/data/code_syms.json
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, json, struct, os, collections
sys.argv = [sys.argv[0]]
import importlib.util
spec = importlib.util.spec_from_file_location('cmp', _T + '/cmp_eu_lib.py')
cmp = importlib.util.module_from_spec(spec); spec.loader.exec_module(cmp)
EU = cmp.EU
res = collections.defaultdict(collections.Counter)
where = collections.defaultdict(set)
for objpath, start, funcs, data, relocs in cmp.iter_matched():
    for (o, ty, name, shndx, val) in relocs:
        if ty != 2: continue
        # which function contains o
        fa = None
        for (fo, fs, fn, ea, ok) in funcs:
            if fo <= o < fo + fs or (fo <= o < fo + fs + 0x400 and False):
                fa = (fo, ea, ok, fn); break
        # literal pools sit after the function body but within st_size? (agbcc includes pools in size)
        if fa is None or not fa[2]: continue
        fo, ea, ok, fn = fa
        eu_off = ea + (o - fo) - 0x08000000
        w = struct.unpack_from('<I', EU, eu_off)[0]
        add = struct.unpack_from('<I', data, o)[0]
        if not name:
            continue  # section-relative (jump tables, local statics)
        res[name][(w - add) & 0xffffffff] += 1
        where[name].add(fn)
out = {}
bad = 0
for n, c in res.items():
    if len(c) > 1:
        bad += 1
        print('INCONSISTENT', n, {hex(k): v for k, v in c.items()}, sorted(where[n])[:5])
    out[n] = hex(c.most_common(1)[0][0])
json.dump(out, open(_W + '/code_syms.json', 'w'), indent=0, sort_keys=True)
print(len(out), 'symbols;', bad, 'inconsistent')
