#!/usr/bin/env python3
"""Dump small EU tables from the EU ROM as source, in data/eu/src (used by gen_eu_data.py
in place of the bytes; run regen.sh afterwards):
  - high_score_tables.inc: gDefaultHighScores, gHighScoreNamePositions,
    gHighScoreNamePixelPositions (same layout as the US tables in data/rom_1.s);
  - pause_menu_sprite_offsets.inc: gPauseMenuSpriteOffsets (one more entry than in the US);
  - idle_press_start_tiles.inc: gIdlePressStartTiles_Fr/_De (EU only: the tiles of the longer
    French and German "press start" text, see all_board_pinball_game_main.c);
  - options_unused_sprite_copy.inc, options_unused_anim_tail.inc: the cut ends of the unused
    copies of the options sprite data (sprite sets with 6-byte entries, animations made of a
    frame count and (frame, duration) pairs).
usage: dump_tables_eu.py"""
import os as _os
_T = _os.path.dirname(_os.path.abspath(__file__))           # tools/eu_port
_R = _os.path.dirname(_os.path.dirname(_T))                  # repository root
_BASEROM = _os.environ.get('BASEROM_EU', _os.path.join(_R, 'baserom_eu.gba'))
import struct

ROM = open(_BASEROM, 'rb').read()


def words(addr, n):
    return struct.unpack_from('<%dI' % n, ROM, addr - 0x08000000)


def halves(addr, n):
    return struct.unpack_from('<%dh' % n, ROM, addr - 0x08000000)


def write(name, start, end, comment, body):
    lines = ['@ ' + c for c in comment] + ['@ eu_range 0x%08X 0x%08X' % (start, end), ''] + body + ['']
    with open(_R + '/data/eu/src/' + name, 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines))
    print(name)


def high_scores():
    start = 0x080EC64C
    body = ['\t@ 4 \'name\' blocks followed by 2 score high/low (name characters 0x3D; 0x28 in the US version)']
    d = words(start, 16 * 6)
    for i in range(16):
        body.append('\t.4byte ' + ', '.join('0x%x' % v for v in d[i * 6:i * 6 + 6]))
    body += ['', 'gHighScoreNamePositions::']
    d = words(0x080EC7CC, 16 * 3)
    for i in range(16):
        body.append('\t.4byte ' + ', '.join('0x%02X' % v for v in d[i * 3:i * 3 + 3]))
    body += ['', 'gHighScoreNamePixelPositions::']
    d = words(0x080EC88C, 16 * 2)
    for i in range(16):
        body.append('\t.4byte ' + ', '.join('0x%02X' % v for v in d[i * 2:i * 2 + 2]))
    write('high_score_tables.inc', start, 0x080EC90C,
          ['Default high scores and positions of the names on the high score screen (EU values).',
           'gDefaultHighScores starts here (its label comes from rom_1.s).'], body)


def pause_menu():
    start = 0x08253E74
    d = halves(start, 22)
    body = ['\t@ Vector16'] + ['\t.2byte %d, %d' % (d[i], d[i + 1]) for i in range(0, 22, 2)]
    write('pause_menu_sprite_offsets.inc', start, start + 44,
          ['Positions of the pause menu sprites (gPauseMenuSpriteOffsets; its label comes from rom_1.s).'], body)


def idle_press_start():
    start = 0x08253F10
    fr = halves(start, 17)
    de = halves(0x08253F32, 12)
    body = ['\t.2byte ' + ', '.join(str(v) for v in fr), '',
            'gIdlePressStartTiles_De::', '\t.2byte ' + ', '.join(str(v) for v in de), '\t.align 2, 0']
    write('idle_press_start_tiles.inc', start, 0x08253F4C,
          ['Tiles of the blinking "press start" text in French (gIdlePressStartTiles_Fr, label from',
           'rom_1.s) and German, which are longer than the 10 sequential tiles of the other languages.'], body)


SPRITE_SIZES = {(0, 0): '8x8', (0, 1): '16x16', (0, 2): '32x32', (0, 3): '64x64', (1, 0): '16x8',
                (1, 1): '32x8', (1, 2): '32x16', (1, 3): '64x32', (2, 0): '8x16', (2, 1): '8x32',
                (2, 2): '16x32', (2, 3): '32x64'}


def oam_entry(addr):
    """A 6-byte sprite set entry as a packed_sprite_oam line (asm/macros/sprite_oam.inc)."""
    word, half = struct.unpack_from('<IH', ROM, addr - 0x08000000)
    x, y = (word >> 16) & 0x1FF, word & 0xFF
    x, y = x - 0x200 if x & 0x100 else x, y - 0x100 if y & 0x80 else y
    hx = lambda v: '-0x%X' % -v if v < 0 else '0x%X' % v
    parts = ['x=' + hx(x), 'y=' + hx(y)]
    for name, v in (('affineMode', (word >> 8) & 3), ('objMode', (word >> 10) & 3), ('mosaic', (word >> 12) & 1),
                    ('bpp', (word >> 13) & 1), ('matrixNum', (word >> 25) & 7), ('hFlip', (word >> 28) & 1),
                    ('vFlip', (word >> 29) & 1), ('priority', (half >> 10) & 3)):
        if v:
            parts.append('%s=0x%X' % (name, v))
    parts.append('spriteSize=SPRITE_SIZE_' + SPRITE_SIZES[((word >> 14) & 3, (word >> 30) & 3)])
    parts += ['tileNum=0x%X' % (half & 0x3FF), 'paletteNum=PAL_IX_%d' % (half >> 12)]
    return '    packed_sprite_oam ' + ', '.join(parts)


def sprite_set(addr):
    """Lines of the sprite set at addr and its end."""
    count = struct.unpack_from('<H', ROM, addr - 0x08000000)[0]
    return ['.2byte %d' % count] + [oam_entry(addr + 2 + 6 * k) for k in range(count)] + [''], addr + 2 + 6 * count


def animations(addr, end):
    """Lines of the animations from addr to end: frame count, then (frame, duration) pairs."""
    lines = ['\t@ animations: frame count, then (frame, duration) pairs']
    while addr < end:
        count = struct.unpack_from('<H', ROM, addr - 0x08000000)[0]
        pairs = struct.unpack_from('<%dH' % (2 * count), ROM, addr + 2 - 0x08000000)
        lines += ['\t.2byte %d' % count] + ['\t.2byte ' + ', '.join(str(v) for v in pairs[i:i + 16])
                                           for i in range(0, 2 * count, 16)]
        addr += 2 + 4 * count
    assert addr == end
    return lines


def options_unused_copies():
    # gUnknown_0895A03C (label from rom_2.s): one more unused copy of the options sprite data, cut
    # at both ends like the US gSpriteSetRawDup_ regions
    start, end = 0x0895A03C, 0x0895A180
    body, a = sprite_set(start)
    body += animations(a, 0x0895A0B8) + ['', '\t@ two entries of a sprite set whose count is not in the copy',
                                         oam_entry(0x0895A0B8), oam_entry(0x0895A0BE), '']
    a = 0x0895A0C4
    for _ in range(6):
        lines, a = sprite_set(a)
        body += lines
    body += animations(a, end)
    write('options_unused_sprite_copy.inc', start, end,
          ['Unused copy of the options sprite data (not referenced by the code): a sprite set,',
           'animations, the end of a cut sprite set, sprite sets and the same animations again.'], body)
    # the 6 bytes after gUnknown_086BBCAC (label from rom_2.s): the end of a cut animation
    start, end = 0x089599CE, 0x089599D4
    write('options_unused_anim_tail.inc', start, end,
          ['End of an animation of an unused copy of the options sprite data: the copy is cut in',
           'the middle of a (frame, duration) list, so only the last duration and pair are left.'],
          ['\t.2byte %s  @ ..., 18, (34, 18)' % ', '.join(str(v) for v in halves(start, 3))])


if __name__ == '__main__':
    high_scores()
    pause_menu()
    idle_press_start()
    options_unused_copies()
