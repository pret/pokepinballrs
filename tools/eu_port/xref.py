#!/usr/bin/env python3
"""Find EU code literal-pool references to given addresses (or address ranges)."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, struct, json, bisect
EU = open(_BASEROM, 'rb').read()
names = {int(k, 16): v for k, v in json.load(open(_W + '/eu_names.json')).items()}
ents = sorted(set(json.load(open(_W + '/eu_entries.json'))))
fn_names = {k: v for k, v in names.items() if k < 0x0805d000}
starts = sorted(set(ents) | set(fn_names))
def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    s = starts[i]
    return f"{fn_names.get(s, 'sub_%08x' % s)}"
TEXT_END = 0x0805cac4
for arg in sys.argv[1:]:
    if '-' in arg:
        lo, hi = [int(x, 16) for x in arg.split('-')]
    else:
        lo = int(arg, 16); hi = lo + 1
    hits = {}
    for o in range(0, TEXT_END - 0x08000000, 4):
        v = struct.unpack_from('<I', EU, o)[0]
        if lo <= v < hi:
            hits.setdefault(owner(o + 0x08000000), set()).add(hex(v))
    print(arg, '->', {k: sorted(v) for k, v in sorted(hits.items())})
