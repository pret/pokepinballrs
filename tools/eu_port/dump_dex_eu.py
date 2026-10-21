#!/usr/bin/env python3
"""Dump the European Pokedex entries (gPokedexEntries) from the EU ROM as preproc source.
usage: dump_dex_eu.py [OUT]   (default data/eu/src/pokedex_entries.inc)

The glyph encoding is read from tools/preproc/asm_file.cpp (American table + European
overrides), so the output assembles back to the same bytes. Characters that do not follow
the per-language table are written as {XXXX} raw glyph codes."""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import re, struct, sys

START, END = 0x08063910, 0x080EC4CC
SIZE = 0xAAC
LANGS = ['EN', 'FR', 'DE', 'IT', 'ES']
NAME_LEN, CAT_LEN, LINE_LEN = 10, 11, 42

src = open(_R + '/tools/preproc/asm_file.cpp', encoding='utf-8').read()

def table(block):
    return {ch: int(v, 16) for ch, v in re.findall(r'\{\s*"([^"]*)",\s*(0x[0-9A-Fa-f]+)\s*\}', block)}

def block_after(marker, end_marker):
    a = src.index(marker)
    return src[a:src.index(end_marker, a)]

us = table(block_after('dexEncoding = ', 'else {'))
common = table(block_after('> common =', '};'))
english = table(block_after('> english =', '};'))
french = table(block_after('> french =', '};'))

def encoding(lang):
    enc = dict(us)
    enc.update(common)
    enc.update(english if lang == 'EN' else french if lang == 'FR' else {})
    return enc

# reverse tables: code -> character (prefer the per-language table)
REV = {}
for lang in LANGS:
    rev = {}
    for ch, v in encoding(lang).items():
        if ch == 'ņ':
            continue
        rev.setdefault(v, ch)
    rev[0] = ' '
    REV[lang] = rev
OE = (0x4B23, 0x4B45)

def text(seq, lang):
    """Decode glyph codes to a dex string (padding spaces removed by the caller)."""
    rev = REV[lang]
    out = []
    i = 0
    while i < len(seq):
        v = seq[i]
        if tuple(seq[i:i + 2]) == OE:
            out.append('œ'); i += 2; continue
        ch = rev.get(v)
        if ch is None or ch in '{}"':
            out.append('{%04X}' % v)
        else:
            out.append(ch)
        i += 1
    return ''.join(out)

def strip(seq, left_aligned=True):
    seq = list(seq)
    if left_aligned:
        while seq and seq[-1] == 0: seq.pop()
    else:
        while seq and seq[0] == 0: seq.pop(0)
    return seq

def encode(s, lang, n, left_aligned=True):
    """Re-encode like preproc, to check the dump."""
    enc = encoding(lang)
    out = []
    i = 0
    while i < len(s):
        if s[i] == '{':
            j = s.index('}', i); out.append(int(s[i + 1:j], 16)); i = j + 1; continue
        out.append(enc[s[i]])
        if s[i] == 'œ': out.append(OE[1])
        i += 1
    pad = [0] * (n - len(out))
    return out + pad if left_aligned else pad + out

def main():
    out_path = sys.argv[1] if len(sys.argv) > 1 else _R + '/data/eu/src/pokedex_entries.inc'
    rom = open(_BASEROM, 'rb').read()
    n = (END - START) // SIZE
    lines = [
        '@ Pokedex entries of the European version (gPokedexEntries), one struct PokedexEntry each',
        '@ (src/pokedex.c): number, height and weight digits (imperial, metric; 10 = blank), names',
        '@ (English, also used in Italian and Spanish; French; German), category and description in',
        '@ English, French, German, Italian and Spanish.',
        '@ .dexLang selects the European glyph encoding of each language (tools/preproc/asm_file.cpp);',
        '@ {XXXX} is a raw glyph code, for the few characters drawn with a different width.',
        '@ English categories are right-aligned, the others left-aligned.',
        '@ eu_range 0x%08X 0x%08X' % (START, END),
        '',
    ]
    for e in range(n):
        hw = struct.unpack_from('<%dH' % (SIZE // 2), rom, START - 0x08000000 + e * SIZE)
        names = [hw[21 + l * NAME_LEN:21 + (l + 1) * NAME_LEN] for l in range(3)]
        cats = [hw[51 + l * CAT_LEN:51 + (l + 1) * CAT_LEN] for l in range(5)]
        descs = [hw[106 + l * 6 * LINE_LEN:106 + (l + 1) * 6 * LINE_LEN] for l in range(5)]
        num = '%d%d%d' % hw[0:3]
        lines += ['\t.align 2, 0', 'dexEntryEu%d:: @ %s %s' % (e + 1, num, text(strip(names[0]), 'EN')),
                  '\t.2byte %d, %d, %d' % hw[0:3],
                  '\t.2byte %s  @ height' % ', '.join(map(str, hw[3:11])),
                  '\t.2byte %s  @ weight' % ', '.join(map(str, hw[11:21]))]
        body = []
        def put(lang, directive, seq, n, left_aligned=True):
            s = text(strip(seq, left_aligned), lang)
            assert encode(s, lang, n, left_aligned) == list(seq), (e, lang, directive, s)
            body.append((lang, '\t%s "%s"' % (directive, s)))
        for l in range(3):
            put(LANGS[l], '.dexName', names[l], NAME_LEN)
        for l in range(5):
            if l == 0:
                put('EN', '.dexCategory', cats[l], CAT_LEN, left_aligned=False)
            else:
                put(LANGS[l], '.dexCategoryLeftAligned', cats[l], CAT_LEN)
        for l in range(5):
            for k in range(6):
                put(LANGS[l], '.dexText', descs[l][k * LINE_LEN:(k + 1) * LINE_LEN], LINE_LEN)
        cur = None
        for lang, ln in body:
            if lang != cur:
                lines.append('\t.dexLang %s' % lang); cur = lang
            lines.append(ln)
        lines.append('')
    lines += ['\t.dexLang US', '']
    with open(out_path, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines))
    print(out_path, n, 'entries')

if __name__ == '__main__':
    main()
