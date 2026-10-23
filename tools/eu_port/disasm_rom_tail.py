#!/usr/bin/env python3
"""Disassemble the unreferenced block at the end of the European ROM (0x08FE0000, 16 KB) into
data/eu/rom_tail.s.

The block is a development tool made of a resident part (its first 4 KB) linked to run at
0x09FE2000 and three overlays (the following 4 KB pages, the last one shorter) all linked at
0x09FE3000: each overlay starts with a table of entry points, and its pointers into 0x09FE3xxx
refer to itself. Code is found by recursive descent from the ARM branches at the start, the
pointers in the block (odd values: Thumb; even values to an ARM instruction with the "always"
condition: ARM), branch and call targets, registers loaded from a literal pool and then used by
bx, the Thumb switch tables of gcc, function prologues and a few stubs listed in EXTRA_CODE; the
rest is data. Each instruction is written as source when GNU as encodes it back to the same
bytes (checked by assembling the file), otherwise as .inst with the disassembly in a comment.
usage: disasm_rom_tail.py             write data/eu/rom_tail.s
       disasm_rom_tail.py -l START END   list the classification of offsets START-END (hex)
(needs capstone, the arm-none-eabi binutils and cpp on PATH, and tools/preproc built)"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import re, struct, subprocess, sys, tempfile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_OP_IMM, ARM_OP_MEM, ARM_OP_REG, ARM_REG_PC

ROM = open(_BASEROM, 'rb').read()
ROM_ADDR, SIZE = 0x08FE0000, 0x4000
RES_RUN, OVL_RUN = 0x09FE2000, 0x09FE3000
D = ROM[ROM_ADDR - 0x08000000:ROM_ADDR - 0x08000000 + SIZE]
END = max(i for i in range(SIZE) if D[i]) + 1          # zeros after it
OUT = _os.path.join(_R, 'data', 'eu', 'rom_tail.s')

# start, end, run address, label prefix, symbol for the run address of the segment
SEGS = [(0x0000, 0x1000, RES_RUN, 'RomTail', 'RES'),
        (0x1000, 0x2000, OVL_RUN, 'RomTailOv1', 'OV1'),
        (0x2000, 0x3000, OVL_RUN, 'RomTailOv2', 'OV2'),
        (0x3000, END, OVL_RUN, 'RomTailOv3', 'OV3')]

# code that nothing in the block reaches (offset: Thumb)
EXTRA_CODE = {0x003C: False,     # nop after the first ARM function
              0x009C: True,      # leaf function: sets a halfword to 1 and waits for it to clear
              0x06D8: False,     # leaf function: reads 8 halfwords
              0x12AA: True,      # stubs: ldr r1, =x; bx r1
              0x3058: True}

ARM = Cs(CS_ARCH_ARM, CS_MODE_ARM); ARM.detail = True
THUMB = Cs(CS_ARCH_ARM, CS_MODE_THUMB); THUMB.detail = True
COND = r'(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)'


def word(o):
    return struct.unpack_from('<I', D, o)[0]


def half(o):
    return struct.unpack_from('<H', D, o)[0]


def seg(o):
    return min(o >> 12, 3)


def run(o):
    s = SEGS[seg(o)]
    return s[2] + o - s[0]


def internal(v, ref):
    """Offset in the block of the address v, as seen from the segment of offset ref: the
    resident part, or the overlay of ref. None outside the block."""
    if RES_RUN <= v < RES_RUN + 0x1000:
        return v - RES_RUN
    k = seg(ref)
    if k and OVL_RUN <= v < OVL_RUN + 0x1000:
        t = SEGS[k][0] + v - OVL_RUN
        return t if t < SEGS[k][1] else None
    return None


class Code:
    def __init__(self):
        self.ins = {}        # offset -> (thumb, size, capstone instruction, target offset, pool offset)
        self.pool = {}       # offset of a literal pool word -> offset of a load
        self.tables = {}     # offset of a Thumb switch jump table -> number of entries
        self.starts = set()  # offsets where a walk started (functions and branch targets)
        self.todo = []
        self.later = []      # Thumb pointers and targets of bx with a register loaded from a pool:
                             # walked after the code reached by branches

    def in_table(self, o):
        return any(t <= o < t + 4 * n for t, n in self.tables.items())

    def owner(self, o):
        """Whether offset o is already taken by an instruction, a pool word or a jump table."""
        if self.in_table(o):
            return True
        for d in (0, 1, 2, 3):
            if o - d in self.ins and self.ins[o - d][1] > d:
                return True
            if o - d in self.pool:
                return True
        return False

    def add(self, o, thumb):
        if o is not None and 0 <= o < END and not self.owner(o):
            self.todo.append((o, thumb))

    def walk(self):
        while self.todo or self.later:
            o, thumb = (self.todo or self.later).pop()
            regs = {}     # register -> value loaded from a literal pool in this run
            if 0 <= o < END and not self.owner(o):
                self.starts.add(o)
            while 0 <= o < END and not self.owner(o):
                md = THUMB if thumb else ARM
                ins = next(md.disasm(D[o:o + 4], run(o)), None)
                if ins is None or (thumb and o % 2) or (not thumb and o % 4) or (thumb and ins.size == 4 and not ins.mnemonic == 'bl'):
                    break
                m, ops = ins.mnemonic, ins.operands
                target = pool = loaded = None
                for op in ops:
                    if op.type == ARM_OP_MEM and op.mem.base == ARM_REG_PC and op.mem.index == 0:
                        p = internal(((run(o) + (4 if thumb else 8)) & ~3) + op.mem.disp, o)
                        if p is not None and p % 4 == 0:
                            pool = p
                            self.pool.setdefault(p, o)
                            if m == 'ldr' and ops[0].type == ARM_OP_REG:
                                loaded = word(p)
                is_branch = m in ('b', 'bl') or re.match('^b' + COND + '$', m)
                if is_branch and ops and ops[0].type == ARM_OP_IMM:
                    target = internal(ops[0].imm, o)
                    self.add(target, thumb)
                self.ins[o] = (thumb, ins.size, ins, target, pool)
                if m == 'bx' and ops and ops[0].type == ARM_OP_REG:
                    v = regs.get(ops[0].reg)
                    if v is not None and internal(v, o) is not None:
                        self.later.append((internal(v, o) & ~1, bool(v & 1)))
                    break
                if m == 'b' or (m == 'pop' and 'pc' in ins.op_str) or \
                        (m.startswith('ldm') and 'pc' in ins.op_str and not re.search(COND + '$', m)) or \
                        (m in ('mov', 'movs') and ins.op_str.startswith('pc')):
                    break
                if ops and ops[0].type == ARM_OP_REG and m not in ('cmp', 'cmn', 'tst', 'teq', 'str', 'strh', 'strb', 'push', 'stm', 'stmia', 'stmdb'):
                    regs.pop(ops[0].reg, None)   # overwritten
                if loaded is not None:
                    regs[ops[0].reg] = loaded
                o += ins.size


def switch_tables(c):
    """The Thumb switch jump tables made by gcc: a pool word with the address of the next word,
    after a mov pc, rX, then the even addresses of the cases (Thumb code)."""
    for o in range(4, END - 7, 4):
        if internal(word(o), o) == o + 4 and any((half(h) & 0xFF87) == 0x4687 for h in range(o - 8, o, 2)):
            n = 0
            while internal(word(o + 4 + 4 * n), o) is not None and not word(o + 4 + 4 * n) & 1:
                n += 1
            c.tables[o + 4] = n
            for k in range(n):
                c.add(internal(word(o + 4 + 4 * k), o), True)


def classify():
    c = Code()
    switch_tables(c)
    for o in (0, 4, 8, 12):
        c.add(o, False)
    for o, thumb in EXTRA_CODE.items():
        c.add(o, thumb)
    for o in range(0, END - 3, 4):
        v = word(o)
        t = internal(v, o)
        if t is None or c.in_table(o):
            continue
        if v & 1:
            c.later.insert(0, (t & ~1, True))
        elif t % 4 == 0 and word(t) >> 28 == 0xE:
            c.add(t, False)
    c.walk()
    while True:   # function prologues in the parts not reached
        found = 0
        for o in range(0, END - 1, 2):
            if c.owner(o):
                continue
            if (half(o) & 0xFF00) == 0xB500 and (o == 0 or c.owner(o - 2) or not any(D[o - 2:o])):
                c.add(o, True); found += 1
            elif o % 4 == 0 and o + 4 <= END and (word(o) & 0xFFFF4000) == 0xE92D4000:
                c.add(o, False); found += 1
        c.walk()
        if not found:
            break
    for o, (th, sz, ins, t, p) in list(c.ins.items()):
        # Thumb nop (mov r8, r8) that aligns a literal pool after a function
        e = o + sz
        if th and e % 4 == 2 and e + 2 <= END and half(e) == 0x46C0 and not c.owner(e) and c.owner(e + 2):
            c.add(e, True)
    c.walk()
    return c


def report(c):
    covered = bytearray(END)
    for o, (th, s, *_r) in c.ins.items():
        covered[o:o + s] = b'\x01' * s
    for p in c.pool:
        covered[p:p + 4] = b'\x01' * 4
    for t, n in c.tables.items():
        covered[t:t + 4 * n] = b'\x01' * 4 * n
    left = [i for i in range(END) if not covered[i] and D[i]]
    print('instructions %d (thumb %d), pool words %d, uncovered nonzero bytes %d of 0x%X'
          % (len(c.ins), sum(1 for v in c.ins.values() if v[0]), len(c.pool), len(left), END))
    runs, s = [], None
    for i in range(END + 1):
        u = i < END and not covered[i] and D[i]
        if u and s is None: s = i
        if not u and s is not None: runs.append((s, i)); s = None
    for a, b in runs:
        print('  0x%04X-0x%04X (%3d) %s' % (a, b, b - a, D[a:min(b, a + 24)].hex(' ')))


def listing(c, a, b):
    o = a
    while o < b:
        if o in c.ins:
            th, sz, ins, t, p = c.ins[o]
            print('%04X %s %-8s %s' % (o, 'T' if th else 'A', ins.mnemonic, ins.op_str))
            o += sz
        elif o in c.pool or c.in_table(o):
            print('%04X word 0x%08X' % (o, word(o)))
            o += 4
        else:
            print('%04X data %s' % (o, D[o:o + 2].hex(' ')))
            o += 2


HEADER = '''\
@ Leftover block at the end of the European ROM (generated by tools/eu_port/disasm_rom_tail.py),
@ followed by 0xFF padding up to 0x08FFF000 and 0x800 zero bytes. The US ROM is 8 MiB and has
@ none of this, and the game never references it.
@ It is a development tool, probably a debug monitor: it saves the registers of every CPU mode
@ and uses the interrupt, wait state and serial (RCNT) registers. It is linked to run near the
@ end of a 32 MiB cartridge, not where it is in this ROM: a resident part (the first 4 KB) at
@ 0x09FE2000 and three overlays (the following 4 KB pages) at 0x09FE3000, each starting with a
@ table of entry points. ARM code at the start jumps to a stub that calls the Thumb code.
@ Labels are named after their run address; "label - RES" (or OV1, OV2, OV3) is that address.
'''
INST_NOTE = '''\
@ Instructions that GNU as encodes differently (or not at all) are written with .inst.
'''
SECTION = '''
\t.syntax unified
\t.section .rodata
'''

FLOW_END = re.compile(r'^(b|bx)$')


def label(o):
    s = SEGS[seg(o)]
    return '%s_%08X' % (s[3], run(o))


def word_text(o):
    """A word as source: a run address in the block as label - segment symbol."""
    v = word(o)
    t = internal(v, o)
    if t is None:
        return '0x%08X' % v
    return '%s - %s%s' % (label(t & ~1), SEGS[seg(t)][4], ' + 1' if v & 1 else '')


def is_pointer(c, o):
    return o % 4 == 0 and o + 4 <= END and not c.owner(o) and internal(word(o), o) is not None


def instr_text(c, o, inst):
    th, sz, ins, t, p = c.ins[o]
    dis = '%s %s' % (ins.mnemonic, ins.op_str)
    m, ops = ins.mnemonic, ins.op_str
    is_branch = m in ('b', 'bl') or re.match('^b' + COND + '$', m)
    if o in inst or (is_branch and t is None and ins.operands and ins.operands[0].type == ARM_OP_IMM):
        if th:
            return '.inst.n %s  @ %s' % (', '.join('0x%04X' % half(o + k) for k in range(0, sz, 2)), dis)
        return '.inst 0x%08X  @ %s' % (word(o), dis)
    if t is not None:
        delta = (run(t) - run(o)) - (t - o)    # an overlay calling the resident part
        ops = label(t) + (' + 0x%X' % delta if delta > 0 else ' - 0x%X' % -delta if delta else '')
    if p is not None:
        ops = re.sub(r'\[pc(, #-?(0x[0-9a-f]+|\d+))?\]', label(p), ops)
    if not th and m in ('push', 'pop'):
        m = 'stmdb' if m == 'push' else 'ldmia'
        ops = 'sp!, ' + ops
    ops = ops.replace('apsr', 'cpsr')
    return '%s %s' % (m, ops) if ops else m


def data_lines(a, b):
    """Data bytes from a to b: runs of one value as .fill/.space, the rest as words, halfwords
    and bytes by alignment."""
    out = []
    o = a
    while o < b:
        n = 1
        while o + n < b and D[o + n] == D[o]:
            n += 1
        if n >= 8:
            out.append('\t.space %d' % n if not D[o] else '\t.fill %d, 1, 0x%02X' % (n, D[o]))
            o += n
            continue
        e = o            # up to the next run of 8 equal bytes
        while e < b:
            n = 1
            while e + n < b and D[e + n] == D[e]:
                n += 1
            if n >= 8:
                break
            e += n
        while o < e:
            if o % 2 or o + 2 > e:
                out.append('\t.byte 0x%02X' % D[o]); o += 1
            elif o % 4 or o + 4 > e:
                out.append('\t.2byte 0x%04X' % half(o)); o += 2
            else:
                k = min(4, (e - o) // 4)
                out.append('\t.4byte ' + ', '.join('0x%08X' % word(o + 4 * i) for i in range(k)))
                o += 4 * k
    return out


def generate(c, inst):
    labels = set()
    for o, (th, sz, ins, t, p) in c.ins.items():
        if t is not None: labels.add(t)
        if p is not None: labels.add(p)
    for t, n in c.tables.items():
        labels.add(t)
    for o in range(0, END - 3, 4):
        t = internal(word(o), o)
        if t is not None and (o in c.pool or c.in_table(o) or not c.owner(o)):
            labels.add(t & ~1)
    labels |= c.starts
    entries = {o for o in c.ins if o in labels}
    for l in labels:
        if c.owner(l) and l not in c.ins and l not in c.pool and l not in c.tables:
            sys.exit('label inside an instruction or a pool word: 0x%04X' % l)
    lines = [HEADER + (INST_NOTE if inst else '') + SECTION]
    mode = None
    o = 0
    while o < END:
        k = seg(o)
        if o == SEGS[k][0]:
            if k == 0:
                lines += ['@ resident part, runs at 0x%08X' % RES_RUN, '', 'gUnusedRomTailCode:: @ 0x%08X' % ROM_ADDR,
                          '\t.set RES, gUnusedRomTailCode - 0x%08X' % RES_RUN]
            else:
                lines += ['', '@ overlay %d (0x%08X), runs at 0x%08X' % (k, ROM_ADDR + o, OVL_RUN), '',
                          '%s:' % label(o), '\t.set %s, %s - 0x%08X' % (SEGS[k][4], label(o), OVL_RUN)]
        if o in labels and not (k and o == SEGS[k][0]):
            if o in entries and lines[-1] != '':
                lines.append('')
            lines.append('%s:' % label(o))
        if o in c.ins:
            th = c.ins[o][0]
            if mode != th:
                lines.append('\t.thumb' if th else '\t.arm')
                mode = th
            lines.append('\t' + instr_text(c, o, inst))
            ins = c.ins[o][2]
            o += c.ins[o][1]
            if FLOW_END.match(ins.mnemonic) or 'pc' in ins.op_str.split(',')[0] or \
                    (ins.mnemonic in ('pop', 'ldm') and 'pc' in ins.op_str):
                lines.append('')
            continue
        if o in c.pool or c.in_table(o) or is_pointer(c, o):
            lines.append('\t.4byte ' + word_text(o))
            o += 4
            continue
        e = o + 1
        while e < END and e not in c.ins and e not in labels and e not in c.pool and not c.in_table(e) \
                and not is_pointer(c, e) and seg(e) == k and e != SEGS[k][0]:
            e += 1
        if e % 4 == 0 and e - o < 4 and not any(D[o:e]) and o - 2 in c.ins and c.ins[o - 2][0]:
            lines.append('\t.align 2, 0')    # after a Thumb function, before a literal pool
        else:
            lines += data_lines(o, e)
        o = e
    lines += ['\t.space 0x%X  @ up to 0x%08X' % (SIZE - END, ROM_ADDR + SIZE), '',
              '\t.fill 0x08FFF000 - 0x%08X, 1, 0xFF' % (ROM_ADDR + SIZE),
              'gUnusedRomTailZeros:: @ 0x08FFF000', '\t.fill 0x800, 1, 0', '']
    return '\n'.join(lines)


def assemble(text):
    """The bytes of the .rodata section of text, assembled like the data files by the Makefile."""
    with tempfile.TemporaryDirectory() as d:
        src, obj, bin_ = (_os.path.join(d, n) for n in ('t.s', 't.o', 't.bin'))
        with open(src, 'w', encoding='utf-8', newline='\n') as f:
            f.write(text)
        preproc = _os.path.join(_R, 'tools', 'preproc', 'preproc')
        pp = subprocess.run([preproc, src, _os.path.join(_R, 'charmap.txt')], capture_output=True, check=True)
        cpp = subprocess.run(['arm-none-eabi-cpp', '-DEUROPE', '-I', _os.path.join(_R, 'include')], input=pp.stdout,
                             capture_output=True, check=True)
        r = subprocess.run(['arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj], input=cpp.stdout, capture_output=True)
        if r.returncode:
            return None, r.stderr.decode()
        rel = subprocess.run(['arm-none-eabi-readelf', '-r', obj], capture_output=True, text=True).stdout
        if re.search(r'R_ARM_(?!V4BX)', rel):   # V4BX only marks the ARM bx instructions
            sys.exit('relocations left:\n' + rel)
        subprocess.run(['arm-none-eabi-objcopy', '-O', 'binary', '-j', '.rodata', obj, bin_], check=True)
        return open(bin_, 'rb').read(), r.stderr.decode()


def line_of_error(err):
    return [int(n) for n in re.findall(r':(\d+): Error', err)]


if __name__ == '__main__':
    c = classify()
    report(c)
    if len(sys.argv) > 2 and sys.argv[1] == '-l':
        listing(c, int(sys.argv[2], 16), int(sys.argv[3], 16))
        sys.exit()
    inst = set()
    target = ROM[ROM_ADDR - 0x08000000:0x08FFF800 - 0x08000000]
    for _ in range(200):
        text = generate(c, inst)
        data, err = assemble(text)
        if data is None:
            # an instruction that GNU as rejects: .inst for the instructions on the error lines
            lines = text.split('\n')
            bad = set()
            for n in line_of_error(err):
                ln = lines[n - 1]
                for o, (th, sz, ins, t, p) in c.ins.items():
                    if o not in inst and ln.strip() == instr_text(c, o, inst):
                        bad.add(o)
            if not bad:
                sys.exit(err)
            inst |= bad
            continue
        if data == target:
            break
        x = next(i for i in range(min(len(data), len(target))) if data[i] != target[i]) \
            if data[:len(target)] != target[:len(data)] else min(len(data), len(target))
        o = next((o for o in c.ins if o <= x < o + c.ins[o][1]), None)
        if o is None or o in inst:
            sys.exit('mismatch at 0x%08X, not in an instruction' % (ROM_ADDR + x))
        inst.add(o)
    else:
        sys.exit('too many mismatches')
    with open(OUT, 'w', encoding='utf-8', newline='\n') as f:
        f.write(text)
    print('%s: identical; %d instructions as .inst:' % (OUT, len(inst)))
    for o in sorted(inst):
        print('  0x%04X %s' % (o, instr_text(c, o, set())))
