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


# ---------------------------------------------------------------- sprite sets in rom_2
# EU-only sprite sets (".2byte count" then count OAM entries of 8 bytes, see packed_sprite_oaml
# in asm/macros/sprite_oam.inc) are written with the macros, like the US ones.
SPRITE_SIZES = {(0, 0): 'SPRITE_SIZE_8x8', (0, 1): 'SPRITE_SIZE_16x16', (0, 2): 'SPRITE_SIZE_32x32',
                (0, 3): 'SPRITE_SIZE_64x64', (1, 0): 'SPRITE_SIZE_16x8', (1, 1): 'SPRITE_SIZE_32x8',
                (1, 2): 'SPRITE_SIZE_32x16', (1, 3): 'SPRITE_SIZE_64x32', (2, 0): 'SPRITE_SIZE_8x16',
                (2, 1): 'SPRITE_SIZE_8x32', (2, 2): 'SPRITE_SIZE_16x32', (2, 3): 'SPRITE_SIZE_32x64'}
OAM_CONSTANTS = {'affineMode': {0: 'ST_OAM_AFFINE_OFF', 1: 'ST_OAM_AFFINE_NORMAL', 2: 'ST_OAM_AFFINE_ERASE',
                                3: 'ST_OAM_AFFINE_DOUBLE'},
                 'objMode': {0: 'ST_OAM_OBJ_NORMAL', 1: 'ST_OAM_OBJ_BLEND', 2: 'ST_OAM_OBJ_WINDOW'}}
PAL_VALUES = {}
for m_ in re.finditer(r'^#define (PAL_IX_\w+)\s+(\d+)\b', open(REPO + '/include/constants/palette_mappings.h').read(), re.M):
    PAL_VALUES[m_.group(1)] = int(m_.group(2))


def us_sprite_sets():
    """US labels of sprite sets -> (entry size: 8 for packed_sprite_oaml, 6 for packed_sprite_oam,
    {palette number: palette name used in that set})."""
    sets = {}
    lab = None
    lines_ = []
    def flat_(path):
        for ln in open(REPO + '/' + path, encoding='utf-8'):
            m = re.match(r'^\s*\.include\s+"(data/[^"]+)"', ln)
            if m and os.path.exists(REPO + '/' + m.group(1)):
                yield from flat_(m.group(1))
            else:
                yield ln
    def close():
        if lab and lines_ and lines_[0].startswith('.2byte') and len(lines_) > 1 and lines_[1].startswith('packed_sprite_oam'):
            pals = {}
            for l in lines_:
                m = re.search(r'paletteNum=(PAL_IX_\w+)', l)
                if m and m.group(1) in PAL_VALUES:
                    pals.setdefault(PAL_VALUES[m.group(1)], m.group(1))
            sets[lab] = (8 if lines_[1].startswith('packed_sprite_oaml') else 6, pals)
    for ln in flat_('data/rom_2.s'):
        m = re.match(r'^(\w+)::', ln)
        if m:
            close()
            lab, lines_ = m.group(1), []
            continue
        s_ = ln.split('@')[0].strip()
        if s_:
            lines_.append(s_)
    close()
    return sets


US_SPRITE_SETS = us_sprite_sets()
SPRITE_SUF = re.compile(r'^(.*?)_((?:En|Fr|De|It|Es)+)$')


def us_sprite_set(n):
    m = SPRITE_SUF.match(n)
    return US_SPRITE_SETS.get(m.group(1) if m else n)


def sprite_sets_end(a, b, size, max_sets=None):
    """End of the run of valid sprite sets with entries of size bytes at a (at most max_sets
    sets, before b), and how many there are."""
    n, pos = 0, a
    while pos < b and (max_sets is None or n < max_sets):
        count = struct.unpack_from('<H', EU, pos - 0x08000000)[0] if pos + 2 <= b else 0
        if count == 0 or count > 128 or pos + 2 + size * count > b:
            break
        for k in range(count):
            p = pos + 2 + size * k - 0x08000000
            word = struct.unpack_from('<I', EU, p)[0]
            if (word >> 14) & 3 == 3 or (size == 8 and struct.unpack_from('<H', EU, p + 6)[0] > 1):
                return pos, n
        n, pos = n + 1, pos + 2 + size * count
    return pos, n


def anims_fill(a, b):
    """Whether EU[a:b] holds animations: runs of a frame count and (frame, duration) pairs,
    then at most the zero padding to 4 bytes."""
    p = a
    while p + 2 <= b:
        k = struct.unpack_from('<H', EU, p - 0x08000000)[0]
        if k == 0:
            break
        if k > 64 or p + 2 + 4 * k > b:
            return False
        p += 2 + 4 * k
    return p > a and b - p < 4 and not any(EU[p - 0x08000000:b - 0x08000000])


def parses_as_sprite_set(a, b):
    """Entry size (8 or 6) if EU[a:b] is exactly one sprite set (count, then count valid OAM
    entries, with or without the 2-byte flag), a run of sprite sets with entries of the same
    size, or a sprite set followed by animations (in the unused copies of the sprite data, like
    the gSpriteSetRawDup_ regions of the US version), else 0."""
    if b - a < 8 or any(a <= p < b for p in PTRS):
        return 0
    found = {}
    for size in (8, 6):
        end, n = sprite_sets_end(a, b, size)
        found[size] = n if end == b else 0
    for size in (8, 6):
        if found[size] == 1:
            return size
    # a run: entries of 6 bytes when both sizes parse, as in the US data
    if found[6] or found[8]:
        return 6 if found[6] else 8
    for size in (6, 8):
        end, n = sprite_sets_end(a, b, size, 1)
        if n and anims_fill(end, b):
            return size
    return 0


# gUnknown_ blocks of rom_2 that are sprite sets: in a run of at least two consecutive pointers
# (a table in the EU-only data) to sprite sets, known ones or blocks that parse as one.
NAME_AT = {n: a for a, n in LABEL_AT.items()}
SPRITE_TARGETS = {}
PTR_AT = sorted(PTRS)


def data_end(a, b):
    """End of the data at a before b: the first pointer of the range, or b."""
    i_ = bisect.bisect_left(PTR_AT, a)
    return min(b, PTR_AT[i_]) if i_ < len(PTR_AT) else b


def _sprite_runs():
    words = PTR_AT
    run = []
    def flush():
        good = []
        for w in run + [None]:
            n = PTRS.get(w) if w is not None else None
            a = NAME_AT.get(n) if n else None
            size = 0
            if a is not None:
                if us_sprite_set(n):
                    size = us_sprite_set(n)[0]
                elif n.startswith('gUnknown_'):
                    size = parses_as_sprite_set(a, data_end(a, extent(a)))
            if size:
                good.append((n, size))
                continue
            if len(good) >= 2:
                SPRITE_TARGETS.update((g, s) for g, s in good if g.startswith('gUnknown_'))
            good = []
    for w in words:
        if run and w != run[-1] + 4:
            flush()
            run = []
        run.append(w)
    flush()
_sprite_runs()
print('EU-only sprite sets found from pointer tables:', len(SPRITE_TARGETS))


def sprite_set_lines(x, y, labels):
    """Lines of the sprite set(s) at x if one of the labels names a US sprite set or an EU-only
    one found in a pointer table, and where they end (before y and the first pointer)."""
    spec = None
    for n in labels:
        if us_sprite_set(n):
            spec = us_sprite_set(n)
        elif n in SPRITE_TARGETS:
            spec = (SPRITE_TARGETS[n], {})
    y = data_end(x, y)
    if spec is None or y == x:
        return None
    size, pals = spec
    lines_ = oam_lines(x, y, size, pals)
    if lines_ is None:
        # one sprite set, then animations (unused copies of the sprite data)
        end, n = sprite_sets_end(x, y, size, 1)
        if not n or not anims_fill(end, y):
            return None
        lines_ = oam_lines(x, end, size, pals) + ['\t@ animations: frame count, then (frame, duration) pairs']
        p = end
        while p + 2 <= y and struct.unpack_from('<H', EU, p - 0x08000000)[0]:
            k = struct.unpack_from('<H', EU, p - 0x08000000)[0]
            pairs = struct.unpack_from('<%dH' % (2 * k), EU, p + 2 - 0x08000000)
            lines_ += ['\t.2byte %d' % k] + ['\t.2byte ' + ', '.join(str(v) for v in pairs[i:i + 16])
                                             for i in range(0, 2 * k, 16)]
            p += 2 + 4 * k
        lines_ += ['\t.2byte 0'] * ((y - p) // 2)
    return lines_, y


def oam_lines(x, y, size, pals):
    """Lines of the sprite sets that fill EU[x:y] exactly, else None."""
    macro = 'packed_sprite_oaml' if size == 8 else 'packed_sprite_oam'
    out_, pos = [], x
    while pos < y:
        if pos + 2 > y:
            return None
        count = struct.unpack_from('<H', EU, pos - 0x08000000)[0]
        pos += 2
        if count == 0 or pos + size * count > y:
            return None
        out_.append('.2byte %d' % count)
        for _ in range(count):
            word, half = struct.unpack_from('<IH', EU, pos - 0x08000000)
            flag = struct.unpack_from('<H', EU, pos + 6 - 0x08000000)[0] if size == 8 else 0
            pos += size
            e = dict(y=word & 0xFF, affineMode=(word >> 8) & 3, objMode=(word >> 10) & 3, mosaic=(word >> 12) & 1,
                     bpp=(word >> 13) & 1, shape=(word >> 14) & 3, x=(word >> 16) & 0x1FF, matrixNum=(word >> 25) & 7,
                     hFlip=(word >> 28) & 1, vFlip=(word >> 29) & 1, size=(word >> 30) & 3,
                     tileNum=half & 0x3FF, priority=(half >> 10) & 3, paletteNum=half >> 12)
            sx = e['x'] - 0x200 if e['x'] & 0x100 else e['x']
            sy = e['y'] - 0x100 if e['y'] & 0x80 else e['y']
            hx = lambda v: '-0x%X' % -v if v < 0 else '0x%X' % v
            parts = ['x=' + hx(sx), 'y=' + hx(sy)]
            for f_ in ('affineMode', 'objMode', 'mosaic', 'bpp', 'matrixNum', 'hFlip', 'vFlip', 'priority'):
                if e[f_]:
                    parts.append('%s=%s' % (f_, OAM_CONSTANTS.get(f_, {}).get(e[f_], '0x%X' % e[f_])))
            if (e['shape'], e['size']) not in SPRITE_SIZES:
                return None
            parts.append('spriteSize=' + SPRITE_SIZES[(e['shape'], e['size'])])
            parts.append('tileNum=0x%X' % e['tileNum'])
            parts.append('paletteNum=' + pals.get(e['paletteNum'], 'PAL_IX_%d' % e['paletteNum']))
            if flag:
                parts.append('unkFlag=0x%X' % flag)
            out_.append('    %s %s' % (macro, ', '.join(parts)))
        out_.append('')
    return out_


# Element types of the data declared in the C code (extern const <type> name[...] or
# EXTERN_LANG*(<type>, name, dims) for the per-language copies): the EU-only tables of rom_2
# with a scalar element type are written with the directive of that size.
C_TYPES = {}
for root_, _, files_ in list(os.walk(REPO + '/src')) + list(os.walk(REPO + '/include')):
    for f_ in files_:
        if f_.endswith(('.c', '.h')):
            txt_ = open(os.path.join(root_, f_), encoding='utf-8', errors='replace').read()
            for m_ in re.finditer(r'\bextern\s+const\s+(?:struct\s+)?(\w+)\s+(\w+)\s*\[', txt_):
                C_TYPES.setdefault(m_.group(2), m_.group(1))
            for m_ in re.finditer(r'\bEXTERN_LANG\w*\(\s*(?:const\s+)?(?:struct\s+)?(\w+)\s*,\s*(\w+)\s*,', txt_):
                C_TYPES.setdefault(m_.group(2), m_.group(1))
ELEMENTS = {'u8': ('.byte', 'B'), 's8': ('.byte', 'b'), 'u16': ('.2byte', 'H'), 's16': ('.2byte', 'h'),
            'u32': ('.4byte', 'I'), 's32': ('.4byte', 'i'), 'Vector16': ('.2byte', 'h'), 'Vector32': ('.4byte', 'i')}
# VRAM addresses in the EU-only tables of rom_2 (destinations of tile copies) are written with the
# BG_/OBJ_VRAM_ADDR_ constant of include/constants/mem_layout that has that value, if only one.
def _vram_names():
    import tempfile
    names, headers = set(), sorted(os.listdir(REPO + '/include/constants/mem_layout'))
    for h in headers:
        names.update(re.findall(r'^#define\s+((?:BG|OBJ)_VRAM_ADDR_\w+)\b(?!\()',
                                open(REPO + '/include/constants/mem_layout/' + h, encoding='utf-8').read(), re.M))
    names = sorted(names)
    d = tempfile.mkdtemp()
    src = ['#include "global.h"'] + ['#include "constants/mem_layout/%s"' % h for h in headers if h.endswith('.h')]
    open(d + '/v.S', 'w', newline='\n').write('\n'.join(src + ['.4byte %s' % n for n in names]) + '\n')
    pre = subprocess.run(['arm-none-eabi-cpp', '-I', 'tools/agbcc/include', '-iquote', 'include', '-nostdinc',
                          '-undef', '-DEUROPE', '-P', d + '/v.S'], cwd=REPO, capture_output=True, text=True).stdout
    open(d + '/v.s', 'w', newline='\n').write('\n'.join(l for l in pre.split('\n') if l.startswith('.4byte')) + '\n')
    subprocess.check_call(['arm-none-eabi-as', '-o', d + '/v.o', d + '/v.s'])
    subprocess.check_call(['arm-none-eabi-objcopy', '-O', 'binary', '-j', '.text', d + '/v.o', d + '/v.bin'])
    data = open(d + '/v.bin', 'rb').read()
    by = collections.defaultdict(list)
    for n, v in zip(names, struct.unpack('<%dI' % (len(data) // 4), data)):
        by[v].append(n)
    return {v: n[0] for v, n in by.items() if len(n) == 1}
VRAM_NAMES = _vram_names()


def _us_word_exprs():
    """Values of the non-symbol .4byte expressions of data/rom_2.s (e.g. BG_ADDR_FOR_BOARD_WRAP(31, 23)),
    evaluated for EU: {label: {value: expression}} and {value: expression} when only one."""
    import tempfile
    text = open(REPO + '/data/rom_2.s', encoding='utf-8').read()
    headers = re.findall(r'^#include .*$', text, re.M)
    exprs, label = [], None
    for ln in text.split('\n'):
        m = re.match(r'^(\w+)::', ln)
        if m:
            label = m.group(1)
            continue
        m = re.match(r'^\s*\.4byte\s+(.*?)\s*(?:@.*)?$', ln)
        if not m or label is None:
            continue
        args, depth, cur = [], 0, ''
        for c in m.group(1):
            if c == ',' and depth == 0:
                args.append(cur.strip()); cur = ''
                continue
            depth += (c == '(') - (c == ')')
            cur += c
        args.append(cur.strip())
        exprs += [(label, a) for a in args if a and not re.match(r'^[a-z_]\w*$|^g\w*$|^0x[0-9A-Fa-f]+$|^\d+$', a)]
    uniq = sorted(set(e for _, e in exprs))
    d = tempfile.mkdtemp()
    open(d + '/e.S', 'w', newline='\n').write('\n'.join(headers + ['.4byte %s' % e for e in uniq]) + '\n')
    pre = subprocess.run(['arm-none-eabi-cpp', '-I', 'tools/agbcc/include', '-iquote', 'include', '-nostdinc',
                          '-undef', '-DEUROPE', '-P', d + '/e.S'], cwd=REPO, capture_output=True, text=True).stdout
    words_ = [l for l in pre.split('\n') if l.startswith('.4byte')]
    if len(words_) != len(uniq):
        return {}, {}
    open(d + '/e.s', 'w', newline='\n').write('\n'.join(words_) + '\n')
    if subprocess.run(['arm-none-eabi-as', '-o', d + '/e.o', d + '/e.s']).returncode:
        return {}, {}
    subprocess.check_call(['arm-none-eabi-objcopy', '-O', 'binary', '-j', '.text', d + '/e.o', d + '/e.bin'])
    data = open(d + '/e.bin', 'rb').read()
    value = dict(zip(uniq, struct.unpack('<%dI' % (len(data) // 4), data)))
    by_table, by_value = collections.defaultdict(dict), collections.defaultdict(set)
    for lab, e in exprs:
        by_table[lab].setdefault(value[e], e)
        by_value[value[e]].add(e)
    return by_table, {v: next(iter(es)) for v, es in by_value.items() if len(es) == 1}
US_WORD_EXPRS, US_WORD_EXPR = _us_word_exprs()


def word_text(v, label):
    """How to write the word v of the EU-only table label: the expression of the US table of the
    same base name, an expression used once in the US data, a VRAM constant, or hex."""
    m_ = SPRITE_SUF.match(label or '')
    base = m_.group(1) if m_ else label
    return (US_WORD_EXPRS.get(base, {}).get(v) or US_WORD_EXPR.get(v) or VRAM_NAMES.get(v)
            or '0x%08X' % v)
# tables written with character literals in the US source, like gCaughtTextChars
CHAR_TABLES = set(re.findall(r"^(\w+)::.*\n\s*\.2?byte\s+'", open(REPO + '/data/rom_2.s', encoding='utf-8').read(), re.M))


def typed_lines(x, y, labels):
    """Lines of the data at x..y if one of the labels has a scalar element type in the C code."""
    for n in labels:
        m_ = SPRITE_SUF.match(n)
        base = m_.group(1) if m_ else n
        t_ = C_TYPES.get(n) or C_TYPES.get(base)
        if t_ in ELEMENTS:
            break
    else:
        return None
    directive, fmt = ELEMENTS[t_]
    size = struct.calcsize('<' + fmt)
    n = (y - x) // size
    if not n or any(x <= p < y for p in PTRS):
        return None
    vals = struct.unpack_from('<%d%s' % (n, fmt), EU, x - 0x08000000)
    per = 16 // size
    show = str
    if base in CHAR_TABLES and all(0x20 <= v < 0x7F and chr(v) not in "'\\" for v in vals):
        show = lambda v: "'%s'" % chr(v)
    out_ = ['\t%s %s' % (directive, ', '.join(show(v) for v in vals[i:i + per])) for i in range(0, n, per)]
    rest = EU[x + n * size - 0x08000000:y - 0x08000000]
    if rest:
        out_.append('\t.byte ' + ', '.join('0x%02X' % c for c in rest))
    return out_


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
# EU-only data ranges written as binary or replaced by MANUAL sources (read by gfx_eu.py)
BLOBS = []
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
        def stale(s, e, p):
            # a graphic of eu_graphics.json with a label inside that its lines do not define (a
            # name added since): written as data again, for gfx_eu.py to convert anew
            if p[0].startswith('.include "data/eu/src/'):
                return False
            text_ = '\n'.join(p)
            defined_ = set(re.findall(r'^\s*(\w+)::', text_, re.M) + re.findall(r'\.set\s+(\w+)', text_))
            return any(s < x < e and n not in defined_ for x in by_addr for n in by_addr[x])
        manual = [(s, e, p) for s, e, p in MANUAL if a <= s < b and not stale(s, e, p)]
        pts = sorted(set([a, b] + [x for x in by_addr if a <= x < b] + [s for s, e, p in manual] + [e for s, e, p in manual]))
        skip_to = None
        for x, y in zip(pts, pts[1:] + [None]):
            if skip_to is not None and x < skip_to:
                for n in by_addr.get(x, []):
                    # labels inside must be defined by the source that replaces the range
                    if n not in skip_defined:
                        raise Exception('label %s inside %s' % (n, skip_to_path))
                    ALL_LABELS[n] = x
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
                text_ = '\n'.join(p)
                for inc_ in re.findall(r'\.include "([^"]+)"', text_):
                    text_ += '\n' + open(REPO + '/' + inc_, encoding='utf-8').read()
                skip_defined = set(re.findall(r'^\s*(\w+)::', text_, re.M) + re.findall(r'\.set\s+(\w+)', text_))
                if obj not in PTR_OBJS:
                    BLOBS.append(dict(addr='0x%08X' % s, size=e - s, labels=sorted(by_addr.get(s, []))))
                continue
            data = EU[x - 0x08000000:y - 0x08000000]
            if obj in PTR_OBJS:
                q = x
                spr = sprite_set_lines(x, y, by_addr.get(x, []))
                if spr is not None:
                    out.extend(('gen', l_) for l_ in spr[0])
                    q = spr[1]
                else:
                    typed = typed_lines(x, y, by_addr.get(x, []))
                    if typed is not None:
                        out.extend(('gen', l_) for l_ in typed)
                        continue
                buf = []
                def flush():
                    for i in range(0, len(buf), 16):
                        out.append(('gen', '\t.byte ' + ', '.join('0x%02X' % c for c in buf[i:i + 16])))
                    buf.clear()
                while q < y:
                    if q in PTRS and q + 4 <= y:
                        flush(); out.append(('gen', f'\t.4byte {PTRS[q]}')); q += 4
                    elif q % 4 == 0 and q + 4 <= y and 0x06000000 <= struct.unpack_from('<I', EU, q - 0x08000000)[0] < 0x06018000:
                        v = struct.unpack_from('<I', EU, q - 0x08000000)[0]
                        label = next(reversed(ALL_LABELS)) if ALL_LABELS else None
                        flush(); out.append(('gen', '\t.4byte ' + word_text(v, label))); q += 4
                    else:
                        buf.append(EU[q - 0x08000000]); q += 1
                flush()
                continue
            if not any(data) and not by_addr.get(x):
                out.append(('gen', '\t.space 0x%X' % len(data)))
            elif len(data) >= 32:
                BLOBS.append(dict(addr='0x%08X' % x, size=y - x, labels=sorted(by_addr.get(x, []))))
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
json.dump(BLOBS, open(_W + '/eu_blobs.json', 'w'), indent=0)
