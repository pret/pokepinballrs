#!/usr/bin/env python3
"""Wrap a C function so the EU build uses the original EU asm (NONMATCHING keeps the C).
usage: wrap_asm.py src/file.c FuncName EU_START EU_END
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import sys, subprocess, re
sys.path.insert(0, _T)
path, fn, a, e = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]
src = open(path).read()
# symbols referenced by our compiled function (preferred names)
from elftools.elf.elffile import ELFFile
obj = _R + '/build/pokepinballrs_eu/' + path.replace('.c', '.o')
ef = ELFFile(open(obj, 'rb'))
syms = list(ef.get_section_by_name('.symtab').iter_symbols())
f = [s for s in syms if s.name == fn][0]
lo, hi = f['st_value'] & ~1, (f['st_value'] & ~1) + f['st_size']
prefer = set()
for r in ef.get_section_by_name('.rel.text').iter_relocations():
    if lo <= r['r_offset'] < hi:
        n = syms[r['r_info_sym']].name
        if n: prefer.add(n)
body = subprocess.run(['python3', _T + '/fn2asm.py', a, e, ','.join(sorted(prefer)) or 'none'], capture_output=True, text=True, check=True).stdout
m = re.search(r'^([^\n;{}]*\b' + re.escape(fn) + r'\s*\([^)]*\))\s*\n\{', src, re.M)
assert m, 'function not found'
start = m.start()
# find matching closing brace at column 0
end = src.index('\n}\n', m.end()) + 3
orig = src[start:end]
sig = m.group(1).strip()
if '#if defined(EUROPE) && !defined(NONMATCHING)' in src[max(0, start - 200):start]:
    sys.exit('already wrapped')
new = (f'#if defined(EUROPE) && !defined(NONMATCHING)\n'
       f'// The European build differs in register allocation / cross-jumping; use the original code.\n'
       f'NAKED\n{sig}\n{{\n    asm_unified(\n{body}    );\n}}\n#else\n{orig}#endif\n')
src = src[:start] + new + src[end:]
open(path, 'w', newline='').write(src)
print('wrapped', fn, 'lines', body.count('\n'))
