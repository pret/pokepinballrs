#!/usr/bin/env python3
"""Dump small EU tables from the EU ROM as source, in data/eu/src (used by gen_eu_data.py
in place of the bytes; run regen.sh afterwards):
  - high_score_tables.inc: gDefaultHighScores, gHighScoreNamePositions,
    gHighScoreNamePixelPositions (same layout as the US tables in data/rom_1.s);
  - pause_menu_sprite_offsets.inc: gPauseMenuSpriteOffsets (one more entry than in the US);
  - idle_press_start_tiles.inc: gIdlePressStartTiles_Fr/_De (EU only: the tiles of the longer
    French and German "press start" text, see all_board_pinball_game_main.c).
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


if __name__ == '__main__':
    high_scores()
    pause_menu()
    idle_press_start()
