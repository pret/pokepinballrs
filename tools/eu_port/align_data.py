#!/usr/bin/env python3
"""Align US rodata items to the EU ROM.
Output tools/eu_port/data/layout.json : list of items with eu address (or None) and learned symbols.
"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import json, struct, bisect, sys, re, subprocess, collections, os
from elftools.elf.elffile import ELFFile
sys.path.insert(0, _T)
REPO = _R
US = open(REPO + '/pokepinballrs.gba', 'rb').read()
EU = open(_BASEROM, 'rb').read()
EU_RO_LO, EU_RO_HI = 0x0805cac4, 0x0895a3c8

# --- US symbols (final addresses)
usel = ELFFile(open(REPO + '/pokepinballrs.elf', 'rb'))
us_sym = {}
us_func = set()
for s in usel.get_section_by_name('.symtab').iter_symbols():
    if s.name and not s.name.startswith('$') and s['st_info']['type'] != 'STT_SECTION' and s['st_shndx'] != 'SHN_ABS':
        us_sym.setdefault(s.name, s['st_value'])
        if s['st_info']['type'] == 'STT_FUNC': us_func.add(s.name)
us_by_addr = collections.defaultdict(list)
for n, a in us_sym.items(): us_by_addr[a & ~1 if n in us_func else a].append(n)
us_addrs = sorted(us_by_addr)

# --- object bases from map
mp = open(REPO + '/pokepinballrs.map').read()
OBJS = ['data/rom_1.o', 'src/m4a_tables.o', 'data/sound_data.o', 'src/agb_sram.o', 'data/sound_data_2.o', 'src/data.o', 'data/rom_2.o']
base = {}
for o in OBJS:
    m = re.search(r'^ \.rodata\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+) ' + re.escape(o) + '$', mp, re.M)
    base[o] = (int(m.group(1), 16), int(m.group(2), 16))

def us_target(v):
    """attribute a US pointer value to (symbol, offset)"""
    a = v & ~1 if (v & 1) and (v & ~1) in us_by_addr and any(n in us_func for n in us_by_addr[v & ~1]) else v
    i = bisect.bisect_right(us_addrs, a) - 1
    if i < 0: return None
    s = us_addrs[i]
    names = us_by_addr[s]
    return (sorted(names, key=lambda n: (n.startswith('gUnknown'), len(n)))[0], v - s)

items = []
for o in OBJS:
    b, size = base[o]
    e = ELFFile(open(REPO + '/build/pokepinballrs/' + o, 'rb'))
    secs = list(e.iter_sections())
    ro = [i for i, s in enumerate(secs) if s.name == '.rodata'][0]
    labs = collections.defaultdict(list)
    for s in e.get_section_by_name('.symtab').iter_symbols():
        if s['st_shndx'] == ro and s.name and not s.name.startswith('$') and s['st_info']['type'] != 'STT_SECTION':
            labs[s['st_value']].append(s.name)
    if 0 not in labs: labs[0].append(o.split('/')[-1].replace('.o', '') + '_rodata_start')
    offs = sorted(x for x in labs if x <= size)
    rel = {}
    rs = e.get_section_by_name('.rel.rodata')
    if rs:
        for r in rs.iter_relocations():
            if r['r_info_type'] == 2:
                v = struct.unpack_from('<I', US, b + r['r_offset'] - 0x08000000)[0]
                rel[r['r_offset']] = us_target(v)
            else:
                print('reloc type', r['r_info_type'], o, hex(r['r_offset']))
    for k, off in enumerate(offs):
        end = offs[k + 1] if k + 1 < len(offs) else size
        its_rel = {x - off: rel[x] for x in rel if off <= x < end}
        items.append(dict(obj=o, names=labs[off], us=b + off, size=end - off, rel=its_rel))
print(len(items), 'US items')

# --- EU known symbols
eu = {k: int(v, 16) for k, v in json.load(open(_W + '/hard_syms.json')).items()}
eu.update({k: int(v, 16) for k, v in json.load(open(_W + '/code_syms.json')).items()})
if os.path.exists(_W + '/extra_names.json'):
    for k, v in json.load(open(_W + '/extra_names.json')).items(): eu.setdefault(k, v)
import cmp_eu_lib
for objpath, start, funcs, data, relocs in cmp_eu_lib.iter_matched():
    for (fo, fs, fn, ea, ok) in funcs:
        eu.setdefault(fn, ea | 1)
code_known = set(eu)
known_lab = sorted(set(v & ~1 for k, v in eu.items() if EU_RO_LO <= v < EU_RO_HI))

def verify(it, E):
    if E < EU_RO_LO or E + it['size'] > EU_RO_HI: return None
    us_off = it['us'] - 0x08000000; eu_off = E - 0x08000000
    mask = set()
    for r in it['rel']:
        mask.update(range(r, r + 4))
    sz = it['size']
    # fast path: compare unmasked chunks
    if not mask:
        return {} if US[us_off:us_off + sz] == EU[eu_off:eu_off + sz] else None
    i = 0
    for r in sorted(it['rel']):
        if US[us_off + i:us_off + r] != EU[eu_off + i:eu_off + r]: return None
        i = r + 4
    if US[us_off + i:us_off + sz] != EU[eu_off + i:eu_off + sz]: return None
    learn = {}
    for r, t in it['rel'].items():
        w = struct.unpack_from('<I', EU, eu_off + r)[0]
        if t is None: return None
        n, d = t
        if n in eu:
            if eu[n] + d != w and not (eu[n] | 1) + d == w and not (eu[n] & ~1) + d == w: return None
        else:
            v = w - d
            if n in learn and learn[n] != v: return None
            if not (0x02000000 <= v < 0x04000000 or 0x08000000 <= v < 0x09000000): return None
            learn[n] = v
    return learn

placed = {}  # item index -> eu addr
iv = []      # sorted (start, end)
def free(E, sz):
    j = bisect.bisect_right(known_lab, E)
    if j < len(known_lab) and known_lab[j] < E + sz: return False
    k = bisect.bisect_right(iv, (E, 1 << 40))
    if k > 0 and iv[k - 1][1] > E: return False
    if k < len(iv) and iv[k][0] < E + sz: return False
    return True
def consistent(i, E, learn):
    if os.environ.get('NOCONS'): return True
    for n in items[i]['names']:
        if n in eu and eu[n] != E and eu[n] != (E | 1): return False
        if n in learn and learn[n] != E: return False
    return True

def place(i, E, learn):
    placed[i] = E
    if items[i]['size']: bisect.insort(iv, (E, E + items[i]['size']))
    for n, v in learn.items(): eu.setdefault(n, v)
    for n in items[i]['names']: eu.setdefault(n, E)

def candidates(i):
    it = items[i]
    for n in it['names']:
        for nn in (n, n + '_En'):
            if nn in eu: yield eu[nn]
    # sequential from previous / next item (across objects: align 4)
    if i - 1 >= 0 and (i - 1) in placed:
        e = placed[i - 1] + items[i - 1]['size']
        if items[i - 1]['obj'] != it['obj']: e = (e + 3) & ~3
        yield e
    if i + 1 < len(items) and items[i + 1]['obj'] == it['obj'] and (i + 1) in placed:
        yield placed[i + 1] - it['size']

def window(i):
    it = items[i]
    lo, hi = EU_RO_LO, EU_RO_HI
    j = i - 1
    while j >= 0 and j not in placed: j -= 1
    if j >= 0: lo = placed[j] + items[j]['size']
    j = i + 1
    while j < len(items) and j not in placed: j += 1
    if j < len(items): hi = placed[j]
    return lo, hi

def search(i, pred):
    it = items[i]
    lo, hi = window(i)
    if it['size'] < 8 or hi - lo < it['size']: return None
    us_off = it['us'] - 0x08000000
    # longest unmasked run among first 64 bytes
    mask = set()
    for r in it['rel']: mask.update(range(r, r + 4))
    best = None; s = 0
    for k in range(min(it['size'], 256) + 1):
        if k == min(it['size'], 256) or k in mask:
            if best is None or k - s > best[1] - best[0]: best = (s, k)
            s = k + 1
    a, b = best
    if b - a < (8 if hi - lo < 0x10000 else 16): return None
    b = min(b, a + 32)
    pat = US[us_off + a:us_off + b]
    if len(set(pat)) <= 1: return None  # uniform bytes: ambiguous
    hits = []
    pos = EU.find(pat, lo - 0x08000000 + a)
    while pos != -1 and pos - a + it['size'] <= hi - 0x08000000 and len(hits) < 50:
        E = 0x08000000 + pos - a
        L = verify(it, E)
        if L is not None and free(E, it['size']) and consistent(i, E, L): hits.append((E, L))
        pos = EU.find(pat, pos + 1)
    if not hits: return None
    if len(hits) == 1: return hits[0]
    if pred is not None:
        after = [h for h in hits if h[0] >= pred]
        if after: return min(after, key=lambda h: h[0] - pred)
    return None

for rnd in range(40):
    changed = 0
    for i, it in enumerate(items):
        if i in placed: continue
        lo, hi = window(i)
        for E in candidates(i):
            if not (lo <= E and E + it['size'] <= hi): continue
            L = verify(it, E)
            if L is not None and free(E, it['size']) and consistent(i, E, L):
                place(i, E, L); changed += 1; break
    if rnd >= 1:
        for i, it in enumerate(items):
            if i in placed: continue
            pred = None
            j = i - 1
            while j >= 0 and items[j]['obj'] == it['obj'] and j not in placed: j -= 1
            if j >= 0 and j in placed: pred = placed[j] + items[j]['size']
            h = search(i, pred)
            if h: place(i, *h); changed += 1
    tot = sum(items[i]['size'] for i in placed)
    print(f'round {rnd}: placed {len(placed)}/{len(items)} ({tot:#x} bytes), +{changed}')
    if not changed and rnd >= 2: break

out = []
for i, it in enumerate(items):
    out.append(dict(obj=it['obj'], names=it['names'], us=it['us'], size=it['size'], eu=placed.get(i),
                    rel={str(k): v for k, v in it['rel'].items()}))
json.dump(dict(items=out, eu_syms={k: v for k, v in eu.items()}), open(_W + '/layout.json', 'w'))
# overlap check
pl = sorted((placed[i], items[i]['size'], i) for i in placed)
ov = 0
for (a, s, i), (b, t, j) in zip(pl, pl[1:]):
    if a + s > b:
        ov += 1
        if ov < 20: print('overlap', items[i]['names'][0], hex(a), hex(s), items[j]['names'][0], hex(b))
print('overlaps', ov)
