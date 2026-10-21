#!/usr/bin/env python3
"""Generate data/eu/*.s from the US data sources + the EU alignment (layout.json)."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_W = _os.path.join(_T, 'data')                               # reference + generated data
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import json, re, os, sys, struct, bisect, collections
REPO = _R
EU = open(_BASEROM, 'rb').read()
L = json.load(open(_W + '/layout.json'))
items = L['items']
eu_syms = {k: v for k, v in L['eu_syms'].items()}
code_syms = {k: int(v, 16) for k, v in json.load(open(_W + '/hard_syms.json')).items()}
code_syms.update({k: int(v, 16) for k, v in json.load(open(_W + '/code_syms.json')).items()})
extra_names = json.load(open(_W + '/extra_names.json')) if os.path.exists(_W + '/extra_names.json') else {}
OUT = REPO + '/data/eu'
BIN = OUT + '/bin'
os.makedirs(BIN, exist_ok=True)

# Sources for EU-only data, emitted instead of the bytes of their range:
# - hand-written data/eu/src/*.inc with a line "@ eu_range START END";
# - per-language graphics files made by gfx_eu.py (tools/eu_port/data/eu_graphics.json).
MANUAL = []
for fn_ in sorted(os.listdir(OUT + '/src')) if os.path.isdir(OUT + '/src') else []:
    if fn_.endswith('.inc'):
        m_ = re.search(r'^@ eu_range (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)', open(f'{OUT}/src/{fn_}', encoding='utf-8').read(), re.M)
        if m_:
            MANUAL.append((int(m_.group(1), 16), int(m_.group(2), 16), [f'.include "data/eu/src/{fn_}"']))
if os.path.exists(_W + '/eu_graphics.json'):
    for a_, g_ in json.load(open(_W + '/eu_graphics.json')).items():
        MANUAL.append((int(a_, 16), int(a_, 16) + g_['size'], g_['lines']))

FILES = [  # (us source, us object, eu name)
    ('data/rom_1.s', 'data/rom_1.o', 'rom_1'),
    ('data/sound_data.s', 'data/sound_data.o', 'sound_data'),
    ('data/sound_data_2.s', 'data/sound_data_2.o', 'sound_data_2'),
    ('data/rom_2.s', 'data/rom_2.o', 'rom_2'),
]
C_OBJS = ['src/m4a_tables.o', 'src/agb_sram.o', 'src/data.o']
ORDER = ['data/rom_1.o', 'src/m4a_tables.o', 'data/sound_data.o', 'src/agb_sram.o', 'data/sound_data_2.o', 'src/data.o', 'data/rom_2.o']
EU_RO_LO, EU_RO_HI = 0x0805cac4, 0x0895a3c8

def obj_items(o): return [it for it in items if it['obj'] == o]
def first_eu(o):
    v = [it['eu'] for it in obj_items(o) if it['eu']]
    return min(v)
def last_eu_end(o):
    v = [it['eu'] + it['size'] for it in obj_items(o) if it['eu']]
    return max(v)
# EU ranges of asm files: from end of previous object to start of next object
bounds = {}
starts = {}
for o in ORDER:
    starts[o] = first_eu(o)
starts['data/rom_1.o'] = EU_RO_LO
starts['src/data.o'] = min(starts['src/data.o'], code_syms['gSpeciesInfo'])
from elftools.elf.elffile import ELFFile
def eu_c_rodata_size(o):
    e = ELFFile(open(REPO + '/build/pokepinballrs_eu/' + o, 'rb'))
    return e.get_section_by_name('.rodata')['sh_size']
prev_end = None
for k, o in enumerate(ORDER):
    nxt = starts[ORDER[k + 1]] if k + 1 < len(ORDER) else EU_RO_HI
    st = starts[o]
    if o.startswith('data/') and prev_end is not None:
        st = (prev_end + 3) & ~3
    bounds[o] = (st, nxt)
    prev_end = st + eu_c_rodata_size(o) if o.startswith('src/') else nxt
for o in ORDER: print(o, hex(bounds[o][0]), hex(bounds[o][1]))

# ---------------------------------------------------------------- pointer pre-pass
import subprocess
FUNCS = {}
try:
    for l in subprocess.run(['arm-none-eabi-nm', REPO + '/pokepinballrs_eu.elf'], capture_output=True, text=True).stdout.splitlines():
        p_ = l.split()
        if len(p_) == 3 and p_[1] in 'tT' and int(p_[0], 16) < EU_RO_LO and not p_[2].startswith(('$', '.')):
            FUNCS.setdefault(int(p_[0], 16), p_[2])
except FileNotFoundError:
    pass
RAM = {}
for f_ in ['sym_ewram_eu.txt', 'sym_bss_eu.txt']:
    for ln_ in open(REPO + '/' + f_):
        m_ = re.match(r'^(\w+): @ (0x[0-9A-Fa-f]+)', ln_)
        if m_: RAM[int(m_.group(2), 16)] = m_.group(1)
for n_, a_ in code_syms.items():
    if 0x02000000 <= a_ < 0x04000000: RAM.setdefault(a_, n_)
RAM_ADDRS = sorted(RAM)
def gaps_of(o):
    lo_, hi_ = bounds[o]
    pl = sorted((it['eu'], it['size']) for it in obj_items(o) if it['eu'])
    g = []; cur_ = lo_
    for e_, z_ in pl:
        if e_ > cur_: g.append((cur_, e_))
        cur_ = max(cur_, e_ + z_)
    if cur_ < hi_: g.append((cur_, hi_))
    return g
GAPS = {o: gaps_of(o) for o in ORDER if o.startswith('data/')}
GAP_LIST = sorted(g for o in GAPS for g in GAPS[o])
GAP_STARTS = [g[0] for g in GAP_LIST]
def in_gap(v):
    i_ = bisect.bisect_right(GAP_STARTS, v) - 1
    return i_ >= 0 and GAP_LIST[i_][0] <= v < GAP_LIST[i_][1]
# primary label of each placed item, and EU labels known by address
PLACED = sorted((it['eu'], it['size'], it) for it in items if it['eu'] and it['size'])
PLACED_STARTS = [x[0] for x in PLACED]
def primary(it):
    for n_ in it['names']:
        if n_ in code_syms and code_syms[n_] not in (it['eu'], it['eu'] | 1): continue
        return n_
    return None
LABEL_AT = {}
for n_, a_ in list(code_syms.items()) + list(eu_syms.items()) + list(extra_names.items()):
    if EU_RO_LO <= a_ < EU_RO_HI: LABEL_AT.setdefault(a_, n_)
for e_, z_, it in PLACED:
    pn = primary(it)
    if pn: LABEL_AT[e_] = pn
AUTO = {}
def ptr_name(v):
    if (v & 1) and (v & ~1) in FUNCS: return FUNCS[v & ~1]
    if EU_RO_LO <= v < EU_RO_HI:
        if v in LABEL_AT: return LABEL_AT[v]
        i_ = bisect.bisect_right(PLACED_STARTS, v) - 1
        if i_ >= 0 and PLACED[i_][0] <= v < PLACED[i_][0] + PLACED[i_][1]:
            pn = primary(PLACED[i_][2])
            if pn: return f'{pn} + 0x{v - PLACED[i_][0]:X}'
        if in_gap(v):
            n_ = f'gUnknown_{v:08X}'
            AUTO[n_] = v; LABEL_AT[v] = n_
            return n_
        return None
    if 0x02000000 <= v < 0x02040000 or 0x03000000 <= v < 0x03008000:
        i_ = bisect.bisect_right(RAM_ADDRS, v) - 1
        if i_ >= 0:
            d_ = v - RAM_ADDRS[i_]
            return RAM[RAM_ADDRS[i_]] if d_ == 0 else f'{RAM[RAM_ADDRS[i_]]} + 0x{d_:X}'
    return None
PTR_OBJS = {'data/rom_2.o'}
PTRS = {}
for o in PTR_OBJS:
    for a_, b_ in GAPS[o]:
        for x_ in range((a_ + 3) & ~3, b_ - 3, 4):
            v = struct.unpack_from('<I', EU, x_ - 0x08000000)[0]
            nm_ = ptr_name(v)
            if nm_: PTRS[x_] = nm_
print('symbolized pointers in gaps:', len(PTRS), ' auto labels:', len(AUTO))

# name auto labels after the corresponding entry of a sibling language table
SUF = re.compile(r'^(.*?)(_(?:En|Fr|De|It|Es|Default)+)$')
ALL_AT = sorted(set(list(LABEL_AT.keys()) + [x[0] for x in PLACED]))
def extent(a_):
    i_ = bisect.bisect_right(ALL_AT, a_)
    return ALL_AT[i_] if i_ < len(ALL_AT) else EU_RO_HI
ITEM_AT = {x[0]: x[2] for x in PLACED}
def entries(a_):
    """offset -> pointer target name (exact, non-auto) of the table at a_"""
    r = {}
    if a_ in ITEM_AT:
        for o_, t_ in ITEM_AT[a_]['rel'].items():
            if t_ and t_[1] == 0: r[int(o_)] = t_[0]
    else:
        e_ = extent(a_)
        for x_ in range(a_, e_, 4):
            if x_ in PTRS and ' + ' not in PTRS[x_]: r[x_ - a_] = PTRS[x_]
    return r
names_by_base = collections.defaultdict(list)
for a_, n_ in LABEL_AT.items():
    m_ = SUF.match(n_)
    names_by_base[m_.group(1) if m_ else n_].append((n_, a_))
rename = {}
taken = set(LABEL_AT.values()) | set(code_syms) | set(eu_syms)
for a_, n_ in sorted(LABEL_AT.items()):
    m_ = SUF.match(n_)
    if not m_: continue
    base, suf = m_.group(1), m_.group(2)
    sibs = [(sn, sa) for sn, sa in names_by_base[base] if sa != a_]
    e_ = extent(a_)
    for x_ in range(a_, e_, 4):
        cur_ = PTRS.get(x_)
        if not cur_ or not cur_.startswith('gUnknown_') or cur_ in rename: continue
        for sn, sa in sibs:
            ent = entries(sa)
            tn = ent.get(x_ - a_)
            if tn and not tn.startswith('gUnknown_'):
                tb = SUF.match(tn)
                new = (tb.group(1) if tb else tn) + suf
                if new not in taken:
                    rename[cur_] = new; taken.add(new)
                break
for k_ in list(PTRS):
    if PTRS[k_] in rename: PTRS[k_] = rename[PTRS[k_]]
for old_, new_ in rename.items():
    AUTO[new_] = AUTO.pop(old_); LABEL_AT[AUTO[new_]] = new_
print('renamed auto labels:', len(rename))

NEUTRAL = re.compile(r'^\s*($|@|//|#|\.equ\b|\.equiv\b|\.set\b|\.global\b|\.globl\b|\.section\b|\.syntax\b|\.include\s+"(asm/|sound/MPlayDef)|\.ifndef|\.ifdef|\.endif|\.else)', re.I)
LABEL = re.compile(r'^\s*([A-Za-z_][\w]*)::?(?=\s|$|@)')
INCL = re.compile(r'^\s*\.include\s+"([^"]+)"')

def flatten(path, stack, out, incs):
    lines = open(REPO + '/' + path).read().split('\n')
    if lines and lines[-1] == '': lines.pop()
    for ln in lines:
        m = INCL.match(ln)
        if m and not m.group(1).startswith('asm/') and m.group(1) != 'sound/MPlayDef.s':
            a = len(out)
            iid = len(incs); incs.append([a, None, ln, m.group(1)])
            flatten(m.group(1), stack + [iid], out, incs)
            incs[iid][1] = len(out)
        else:
            out.append(ln)

def labels_of(ln):
    m = LABEL.match(ln)
    if m: return [m.group(1)]
    m = re.match(r'^\s*voice_group\s+(\w+)\s*(,\s*\d+)?', ln)
    if m:
        r = ['voicegroup_base_' + m.group(1)]
        if not m.group(2): r.append('voicegroup_' + m.group(1))
        return r
    m = re.match(r'^\s*keysplit\s+(\w+)', ln)
    if m: return ['keysplit_' + m.group(1)]
    return []

ALL_LABELS = {}
def gen_file(src, obj, name):
    flat = []; incs = []
    flatten(src, [], flat, incs)
    its = obj_items(obj)
    name2item = {}
    for k, it in enumerate(its):
        for n in it['names']: name2item.setdefault(n, k)
    # label line index -> item index
    lab_item = {}
    for li, ln in enumerate(flat):
        for n in labels_of(ln):
            if n in name2item: lab_item[li] = name2item[n]; break
    # region of each line
    region = [-1] * len(flat)
    cur = -1
    seen = set()
    starts_at = {}
    for li in range(len(flat)):
        if li in lab_item and lab_item[li] not in seen and lab_item[li] >= cur:
            k = lab_item[li]
            # items without own label lines in between (e.g. synthetic start) are skipped
            cur = k; seen.add(k); starts_at[k] = li
        region[li] = cur
    missing = [its[k]['names'] for k in range(len(its)) if k not in starts_at and its[k]['size']]
    if missing: print('  items without label line:', len(missing), missing[:8])
    lo, hi = bounds[obj]
    # EU labels to place: EU-referenced names not defined by placed US items
    defined = set()
    for it in its:
        if it['eu']: defined.update(it['names'])
    want = {}
    for n, a in list(code_syms.items()) + list(eu_syms.items()):
        if lo <= a < hi and n not in defined: want.setdefault(n, a)
    for n, a in list(extra_names.items()) + list(AUTO.items()):
        if lo <= a < hi and n not in defined: want.setdefault(n, a)
    by_addr = collections.defaultdict(list)
    for n, a in want.items(): by_addr[a].append(n)
    placed_at = {}
    for k, it in enumerate(its):
        if it['eu']: placed_at[it['eu']] = k
    out = []  # tokens: ('src', idx) / ('gen', text)
    cursor = lo
    used_labels = set()
    binn = [0]
    def emit_gap(a, b):
        nonlocal cursor
        assert a == cursor, (hex(a), hex(cursor))
        if b < a: raise Exception('negative gap %x %x in %s' % (a, b, name))
        manual = [(s, e, p) for s, e, p in MANUAL if a <= s < b]
        pts = sorted(set([a, b] + [x for x in by_addr if a <= x < b] + [s for s, e, p in manual] + [e for s, e, p in manual]))
        skip_to = None
        for x, y in zip(pts, pts[1:] + [None]):
            if skip_to is not None and x < skip_to:
                if by_addr.get(x):
                    raise Exception('label %s inside %s' % (by_addr[x], skip_to_path))
                continue
            for n in sorted(by_addr.get(x, [])):
                if n not in used_labels and x < b:
                    out.append(('gen', f'{n}:: @ 0x{x:08X}')); used_labels.add(n); ALL_LABELS[n] = x
            if y is None or y <= x: continue
            m = [(s, e, p) for s, e, p in manual if s == x]
            if m:
                s, e, p = m[0]
                if e > b: raise Exception('%s extends past the gap at 0x%X' % (p[0], b))
                for l_ in p:
                    out.append(('gen', l_ if l_.endswith('::') else '\t' + l_))
                skip_to, skip_to_path = e, p[0]
                continue
            data = EU[x - 0x08000000:y - 0x08000000]
            if obj in PTR_OBJS:
                buf = []
                def flush():
                    for i in range(0, len(buf), 16):
                        out.append(('gen', '\t.byte ' + ', '.join('0x%02X' % c for c in buf[i:i + 16])))
                    buf.clear()
                q = x
                while q < y:
                    if q in PTRS and q + 4 <= y:
                        flush(); out.append(('gen', f'\t.4byte {PTRS[q]}')); q += 4
                    else:
                        buf.append(EU[q - 0x08000000]); q += 1
                flush()
                continue
            if len(data) >= 32:
                fn = f'data/eu/bin/{name}_{x:08X}.bin'
                open(REPO + '/' + fn, 'wb').write(data)
                out.append(('gen', f'\t.incbin "{fn}"'))
            else:
                for i in range(0, len(data), 16):
                    out.append(('gen', '\t.byte ' + ', '.join('0x%02X' % c for c in data[i:i + 16])))
        cursor = b
    warn = []
    cur_region = None
    for li, ln in enumerate(flat):
        k = region[li]
        if k != cur_region:
            cur_region = k
            if k >= 0 and its[k]['eu']:
                E = its[k]['eu']
                if E != cursor:
                    emit_gap(cursor, E)
                for n in sorted(by_addr.get(E, [])):
                    if n not in used_labels:
                        out.append(('gen', f'{n}:: @ 0x{E:08X}')); used_labels.add(n); ALL_LABELS[n] = E
                if (E - its[k]['us']) % 4:
                    seg = [flat[j] for j in range(li, len(flat)) if region[j] == k]
                    if any(re.match(r'\s*\.(align|balign|p2align)', s) for s in seg):
                        warn.append(its[k]['names'][0])
                cursor = E + its[k]['size']
        if k >= 0 and not its[k]['eu']:
            # unplaced US item: keep only neutral lines, but not its labels
            if NEUTRAL.match(ln) and not labels_of(ln):
                out.append(('src', li))
            continue
        labs = labels_of(ln)
        if k >= 0 and labs and LABEL.match(ln):
            n = labs[0]
            if n in code_syms and code_syms[n] not in (its[k]['eu'], its[k]['eu'] | 1) and n in its[k]['names']:
                print('  dropping US label', n, 'at', hex(its[k]['eu']), '(EU code uses it at', hex(code_syms[n]), ')')
                continue
        if k >= 0 and labs and LABEL.match(ln):
            ALL_LABELS[labs[0]] = its[k]['eu']
            if '@ 0x' in ln:
                out.append(('gen', re.sub(r'@ 0x[0-9A-Fa-f]+', f'@ 0x{its[k]["eu"]:08X}', ln))); continue
        out.append(('src', li))
    if cursor != hi:
        emit_gap(cursor, hi)
    if warn: print('  WARNING: .align inside non-congruent items:', warn)
    # collapse fully-emitted includes back into .include lines
    toks = [(t, v, (v, v + 1) if t == 'src' else None) for t, v in out]
    for a, b, ln, p in sorted(incs, key=lambda x: x[1] - x[0]):
        if a == b: continue
        # find token whose coverage starts at a
        for ti, tk in enumerate(toks):
            if tk[2] and tk[2][0] == a: break
        else: continue
        tj = ti; pos = a
        while tj < len(toks) and toks[tj][2] and toks[tj][2][0] == pos and pos < b:
            pos = toks[tj][2][1]; tj += 1
        if pos == b:
            toks[ti:tj] = [('inc', ln, (a, b))]
    with open(f'{OUT}/{name}.s', 'w', newline='\n') as f:
        f.write(f'@ Generated for the European version (BPPP) from {src}\n')
        for t, v, cov in toks:
            if t == 'src': f.write(flat[v] + '\n')
            elif t == 'gen': f.write(v + '\n')
            else: f.write(v + '\n')
    print(name, 'written; bins', len(os.listdir(BIN)))

for src, obj, name in FILES:
    gen_file(src, obj, name)
json.dump(ALL_LABELS, open(_W + '/eu_data_labels.json', 'w'), indent=0, sort_keys=True)
