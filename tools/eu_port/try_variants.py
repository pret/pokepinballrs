#!/usr/bin/env python3
"""Try C variants for a snippet until a function matches.
usage: try_variants.py SRCFILE FUNC VARIANTS_FILE
VARIANTS_FILE: first block = original snippet, then variants separated by lines '=====' .
Leaves the first matching variant in place (or restores the original)."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, subprocess, re, os
src, func, vf = sys.argv[1:4]
blocks = open(vf).read().split('\n=====\n')
orig = blocks[0]; variants = blocks[1:]
path = _R + '/' + src
text = open(path).read()
assert text.count(orig) == 1, 'original snippet not found exactly once'
obj = 'build/pokepinballrs_eu/' + src.replace('.c', '.o')
def build_and_check():
    r = subprocess.run(['make', 'REGION=EU', 'NODEP=', obj], cwd=_R, capture_output=True, text=True)
    if r.returncode != 0:
        return None, r.stderr[-400:]
    r = subprocess.run(['python3', '-I', _T + '/cmp_eu.py', os.path.basename(obj), '-v'], capture_output=True, text=True)
    for l in r.stdout.splitlines():
        if l.startswith('OK ') and os.path.basename(obj) in l:
            return 0, ''
        m = re.search(r'(ok|BAD)\s+(\S+)\s+\S+\s+\S+ diff=(\d+)', l)
        if m and m.group(2) == func:
            return int(m.group(3)), ''
    return None, 'func not found'
for i, v in enumerate(variants):
    open(path, 'w').write(text.replace(orig, v))
    d, err = build_and_check()
    print(f'variant {i}: diff={d} {err}')
    if d == 0:
        print('MATCH'); sys.exit(0)
open(path, 'w').write(text)
subprocess.run(['make', 'REGION=EU', 'NODEP=', obj], cwd=_R, capture_output=True)
print('no match; restored original')
