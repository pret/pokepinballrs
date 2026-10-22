#!/usr/bin/env python3
"""Dump the e-Reader texts of the European version from the EU ROM as preproc source, in
data/eu/src (used by gen_eu_data.py in place of the bytes; run regen.sh afterwards):
  - ereader_text.inc: gEReaderTextGlyphTable, 15 pages of 3 lines of 25 cells per language;
  - ereader_text_lengths.inc: gEReaderTextLengths;
  - ereader_text_has_next_page.inc: the rest of gEReaderTextHasNextPage (its first 14 bytes,
    the English ones of the US table, come from rom_2.s).
Each line is written with the directive that reproduces it: .ereaderText (the fixed widths of
the American e-Reader table, with the European glyphs) or .ereaderDexText (the widths of the
Pokedex text of the language set with .dexLang). The glyph tables are read from
tools/preproc/asm_file.cpp; characters that follow neither are written as {XXXX} raw codes.
usage: dump_ereader_eu.py"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import re, struct

ROM = open(_BASEROM, 'rb').read()
LANGS = ['EN', 'FR', 'DE', 'IT', 'ES']
PAGES, ROWS, CELLS = 15, 3, 25
TABLE, TABLE_END = 0x08937700, 0x0893A2F4
LENGTHS, LENGTHS_END = 0x0893A36A, 0x0893A3B5
HAS_NEXT, HAS_NEXT_US_END, HAS_NEXT_END = 0x0893A3B5, 0x0893A3C3, 0x0893A400
OE = (0x4B23, 0x4B45)

src = open(_R + '/tools/preproc/asm_file.cpp', encoding='utf-8').read()


def table(block):
    return {ch: int(v, 16) for ch, v in re.findall(r'\{\s*"([^"]*)",\s*(0x[0-9A-Fa-f]+)\s*\}', block)}


def block_after(marker, end_marker, start=0):
    a = src.index(marker, start)
    return src[a:src.index(end_marker, a)]


dex = table(block_after('dexEncoding = ', 'else {'))
fixed = table(block_after('dexEncoding = ', '};', src.index('dexEncoding = ') + 1))
common = table(block_after('> common =', '};'))
english = table(block_after('> english =', '};'))
french = table(block_after('> french =', '};'))


def encoding(lang, directive):
    """Glyph table of preproc for a directive and a .dexLang language."""
    if directive == '.ereaderText':
        enc = dict(fixed)
        enc.update((k, v) for k, v in common.items() if ord(k[0]) >= 0x80)
    else:
        enc = dict(dex)
        enc.update(common)
        enc.update(english if lang == 'EN' else french if lang == 'FR' else {})
    return enc


def text(seq, enc):
    """Characters of a line (padding removed) and the number of raw codes in it."""
    rev = {}
    for ch, v in enc.items():
        rev.setdefault(v, ch)
    seq = list(seq)
    while seq and seq[-1] == 0:
        seq.pop()
    out, raw, i = [], 0, 0
    while i < len(seq):
        if tuple(seq[i:i + 2]) == OE:
            out.append('œ'); i += 2; continue
        ch = ' ' if seq[i] == 0 else rev.get(seq[i])
        if ch is None or ch in '{}"':
            out.append('{%04X}' % seq[i]); raw += 1
        else:
            out.append(ch)
        i += 1
    return ''.join(out), raw


def encode(s, enc):
    """Re-encode like preproc, to check the dump."""
    out, i = [], 0
    while i < len(s):
        if s[i] == '{':
            j = s.index('}', i); out.append(int(s[i + 1:j], 16)); i = j + 1; continue
        out.append(enc[s[i]])
        if s[i] == 'œ':
            out.append(OE[1])
        i += 1
    return out + [0] * (CELLS - len(out))


def write(name, start, end, comment, body):
    lines = ['@ ' + c for c in comment] + ['@ eu_range 0x%08X 0x%08X' % (start, end), ''] + body + ['']
    with open(_R + '/data/eu/src/' + name, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines))
    print(name)


def glyph_table():
    body = []
    raw_total = 0
    for li, lang in enumerate(LANGS):
        lines = []
        for page in range(PAGES):
            for row in range(ROWS):
                o = TABLE - 0x08000000 + 2 * (((li * PAGES + page) * ROWS + row) * CELLS)
                seq = list(struct.unpack_from('<%dH' % CELLS, ROM, o))
                options = []
                for directive in ('.ereaderText', '.ereaderDexText'):
                    enc = encoding(lang, directive)
                    s, raw = text(seq, enc)
                    assert encode(s, enc) == seq, (lang, page, row, directive, s)
                    options.append((raw, directive, s))
                lines.append((page, row, options))
        # on a tie, the directive that writes more lines of the language without raw codes
        prefer = max(('.ereaderText', '.ereaderDexText'),
                     key=lambda d: sum(1 for _, _, o in lines for raw, dd, _ in o if dd == d and raw == 0))
        body += ['\t.dexLang %s' % lang, '']
        for page, row, options in lines:
            raw, directive, s = min(options, key=lambda o: (o[0], o[1] != prefer))
            raw_total += raw
            body.append('\t%s "%s"' % (directive, s))
            if row == ROWS - 1:
                body.append('')
    body += ['\t.dexLang US', '\t.align 2, 0']
    write('ereader_text.inc', TABLE, TABLE_END,
          ['Text of the e-Reader screens in the European version (gEReaderTextGlyphTable; its label comes',
           'from rom_2.s): 15 pages of 3 lines of 25 cells in English, French, German, Italian and Spanish.',
           '.ereaderText uses the fixed widths of the American e-Reader text, .ereaderDexText the widths',
           'of the Pokedex text of the language (.dexLang); the game ignores the widths. {XXXX} is a',
           'raw glyph code.'], body)
    print('raw codes', raw_total)


def page_tables():
    lengths = ROM[LENGTHS - 0x08000000:LENGTHS_END - 0x08000000]
    body = ['\t.byte ' + ', '.join('0x%02X' % b for b in lengths[i * PAGES:(i + 1) * PAGES]) + '  @ ' + lang
            for i, lang in enumerate(LANGS)]
    write('ereader_text_lengths.inc', LENGTHS, LENGTHS_END,
          ['Number of characters of each e-Reader text page, per language (gEReaderTextLengths; its',
           'label comes from rom_2.s).'], body)
    rest = ROM[HAS_NEXT_US_END - 0x08000000:HAS_NEXT_END - 0x08000000]
    body = ['\t.byte 0x%02X  @ EN, page 14' % rest[0]]
    body += ['\t.byte ' + ', '.join('0x%02X' % b for b in rest[1 + i * PAGES:1 + (i + 1) * PAGES]) + '  @ ' + lang
             for i, lang in enumerate(LANGS[1:])]
    write('ereader_text_has_next_page.inc', HAS_NEXT_US_END, HAS_NEXT_END,
          ['Rest of gEReaderTextHasNextPage (whether an e-Reader text page goes on with the next one):',
           'its first 14 bytes, the English pages 0-13 of the US table, come from rom_2.s.'], body)


if __name__ == '__main__':
    glyph_table()
    page_tables()
