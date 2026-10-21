#!/usr/bin/env python3
"""Simulate agbcc's (gcc 2.95) PRE/lazy code motion for one expression of one function, to see
why GCSE keeps or deletes a computation (e.g. a reload of a global's address that the
original does not have).

usage: lcm_sim.py DUMP EXPR_SUBSTRING [EXPR_INDEX]
  DUMP: the gcse dump of the function only, e.g.
        tools/agbcc/bin/agbcc -O2 ... -dG file.i -o file.s   -> file.i.gcse
        then cut out the ";; Function NAME" section.
  EXPR_SUBSTRING: text identifying the loads of the expression in the RTL,
        e.g. 'LC69")) 0))' for (mem/u (symbol_ref "*.LC69")).
  EXPR_INDEX: index of the expression in the dump's "Expression hash table" (default 0).

Prints the blocks where the expression is computed (ANTLOC), which ones LCM deletes and the
sets EARLYIN/DELAYIN/ISOOUT. A computation is kept when LATEIN or ISOOUT holds in its block;
calls (non-transparent blocks) make the following blocks "earliest". Note that agbcc's
compute_latein sets LATEIN = DELAYIN for every block but the last."""
import re, sys
txt = open(sys.argv[1]).read()
expr = sys.argv[2]
head, _, rest = txt.partition('GCSE pass 1')
bbs = {}
for m in re.finditer(r'BB (\d+), start (\d+), end (\d+)\n  preds: ([^\n]*)\n  succs: ([^\n]*)', head):
    n = int(m.group(1))
    bbs[n] = dict(start=int(m.group(2)), end=int(m.group(3)),
                  preds=[p for p in m.group(4).split()], succs=[s for s in m.group(5).split()])
N = max(bbs) + 1
# insn stream after gcse (last listing in the dump); PRE deletions logged
EXPR_IX = sys.argv[3] if len(sys.argv) > 3 else '0'
red_logged = set(int(b) for b in re.findall(r'PRE: redundant insn \d+ \(expression ' + EXPR_IX + r'\) in bb (\d+)', txt))
# find the final insn stream: after the last "CPROP of" line
stream = txt[txt.rfind('CPROP of'):]
uids = []
occ = set()
calls = set()
for m in re.finditer(r'^\((insn|jump_insn|call_insn|code_label|note|barrier) (\d+) .*?(?=^\(|\Z)', stream, re.S | re.M):
    uid = int(m.group(2)); uids.append(uid)
    if m.group(1) == 'insn' and expr in m.group(0) and '(set (reg' in m.group(0):
        occ.add(uid)
    if m.group(1) == 'call_insn':
        calls.add(uid)
# assign uids to bbs by walking stream order
pos = {u: i for i, u in enumerate(uids)}
bb_of = {}
for n, b in bbs.items():
    if b['start'] in pos and b['end'] in pos:
        for u in uids[pos[b['start']]:pos[b['end']] + 1]:
            bb_of[u] = n
antloc = [False] * N
transp = [True] * N
first_call = {}
for u in uids:
    if u in calls and u in bb_of:
        transp[bb_of[u]] = False
        first_call.setdefault(bb_of[u], pos[u])
for u in occ:
    if u in bb_of:
        b = bb_of[u]
        if b not in first_call or pos[u] < first_call[b]:
            antloc[b] = True
print('non-transparent (calls):', [b for b in range(N) if not transp[b]])
for b in red_logged: antloc[b] = True
antloc[0] = antloc[0] or any(bb_of.get(u) == 0 for u in occ)
print('ANTLOC blocks:', [b for b in range(N) if antloc[b]])

def succ(b): return [int(s) for s in bbs[b]['succs'] if s.isdigit()]
def pred(b): return [int(p) for p in bbs[b]['preds'] if p.isdigit()]

def lcm(antloc):
    antin = [True] * N; antout = [False] * N
    ch = True
    while ch:
        ch = False
        for b in range(N - 1, -1, -1):
            if b != N - 1:
                s = succ(b)
                antout[b] = all(antin[x] for x in s) if s else False
                if any(not x.isdigit() for x in bbs[b]['succs']): antout[b] = False
            v = antloc[b] or (transp[b] and antout[b])
            if v != antin[b]: antin[b] = v; ch = True
    earlyin = [False] * N; earlyout = [False] * N; earlyin[0] = True
    ch = True
    while ch:
        ch = False
        for b in range(N):
            if b != 0: earlyin[b] = any(earlyout[p] for p in pred(b))
            v = (not transp[b]) or (earlyin[b] and not antin[b])
            if v != earlyout[b]: earlyout[b] = v; ch = True
    ae = [antin[b] and earlyin[b] for b in range(N)]
    delayin = [False] * N; delayout = [False] * N; delayin[0] = ae[0]
    ch = True
    while ch:
        ch = False
        for b in range(N):
            if b != 0:
                p = pred(b)
                v = ae[b] or (all(delayout[x] for x in p) if p else False)
                if v and not delayin[b]: delayin[b] = True; ch = True
            v = (not antloc[b]) and delayin[b]
            if v and not delayout[b]: delayout[b] = True; ch = True
    latein = list(delayin)
    latein[N - 1] = delayin[N - 1] and (antloc[N - 1] or True)
    isoin = [False] * N; isoout = [False] * N
    ch = True
    while ch:
        ch = False
        for b in range(N - 1, -1, -1):
            if b != N - 1:
                s = succ(b); isoout[b] = all(isoin[x] for x in s) if s else False
            v = latein[b] or (isoout[b] and not antloc[b])
            if v and not isoin[b]: isoin[b] = True; ch = True
    red = [antloc[b] and not (latein[b] or isoout[b]) for b in range(N)]
    return dict(antin=antin, earlyin=earlyin, delayin=delayin, latein=latein, isoout=isoout, red=red)

r = lcm(antloc)
print('redundant:', [b for b in range(N) if r['red'][b]], ' logged:', sorted(red_logged))
print('kept     :', [b for b in range(N) if antloc[b] and not r['red'][b]])
for k in ('antin', 'earlyin', 'delayin', 'isoout'):
    print(k, [b for b in range(N) if r[k][b]])
