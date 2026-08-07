#!/usr/bin/env python3
"""objpalette -- give each OBJ tile sheet segment the palette bank it renders with.

A 4bpp sprite sheet stores only colour indices; the palette bank comes from the
OAM entry that draws it, so a checked-in sheet has no colour of its own and was
exported as a greyscale ramp.  That makes the art unreadable: every sheet is a
grey blob, and nothing in the tree records which of the 16 OBJ banks a given
sprite belongs to.

The binding is recoverable.  `data/rom_2.s` spells out every OAM entry as

    packed_sprite_oaml x=..., y=..., spriteSize=..., tileNum=0x1d1, paletteNum=0xf

and the per-board `g<Board>BoardSpriteSets` tables say which of those entries a
board actually uses.  A sheet's segments are laid end to end in tile order, so
each segment owns a known tile range and the OAM entries landing in that range
name its bank.

    derive   rom_2.s + gfx.json  ->  "palette"/"palbank" written into gfx.json
    apply    gfx.json            ->  segment PNGs rewritten as indexed colour
    check    gfx.json            ->  verify PNG palettes match the json

`apply` swaps the PNG's greyscale ramp for a PLTE chunk and inverts the pixel
values while doing it.  gbagfx converts a palette-less PNG with
`invertColors = !image.hasPalette` (main.c), so a greyscale sheet stores
`15 - index` and gaining a PLTE turns that inversion off; writing the samples
through unchanged would quietly rewrite every tile.  Inverting on the way in
keeps the .4bpp the build produces byte-for-byte identical -- and is why these
sheets looked so wrong before: a Pikachu whose transparent surround is stored
as 15 comes out drawn in whatever colour sits at the top of the bank.

Deriving the bank
-----------------
An OAM entry only counts for a segment when its whole tile span lies inside
that segment.  An entry crossing a boundary is drawing from a sheet other than
the one checked in -- VRAM at 0x06010000 is written repeatedly at run time --
and would otherwise drag in a palette that has nothing to do with this art.
Surviving entries are grouped by bank and the bank covering the most tiles
wins.  Two passes: first the board's own sprite-set table, then, for segments
no table entry reaches, the `g<Board>*OamData` animation arrays, which the boss
code indexes frame by frame instead of going through a sprite set.

Whatever is left is a region no OAM entry ever names -- scratch slots the game
DMAs over before drawing, or sheet padding.  Those are listed in OVERRIDES with
the reason, since no amount of static analysis will settle them.

Only stdlib is used, so this adds no build dependency.

Examples
--------
    objpalette.py derive --board ruby --write
    objpalette.py apply  --board all
    objpalette.py check  --board all
"""

import argparse
import collections
import json
import os
import re
import struct
import sys
import zlib

ROM_SOURCE = 'data/rom_2.s'

# shape/size -> pixel dimensions, for the OAM entries that spell out shape and
# size numerically instead of using a SPRITE_SIZE_WxH name.
OAM_DIMS = {
    (0, 0): (8, 8),   (0, 1): (16, 16), (0, 2): (32, 32), (0, 3): (64, 64),
    (1, 0): (16, 8),  (1, 1): (32, 8),  (1, 2): (32, 16), (1, 3): (64, 32),
    (2, 0): (8, 16),  (2, 1): (8, 32),  (2, 2): (16, 32), (2, 3): (32, 64),
}

# board -> sprite-set table, graphics dir, gfx config, prefixes of the board's
# own OAM arrays, and the OBJ palette as the board loads it.  A board's OBJ
# palette is one 512-byte DMA from objPaletteSets[0] (all_board_pinball_game_main.c),
# which for ruby runs off the end of its own palset into the next label; see
# data/board_data/VRAM_LAYOUT.md.
BOARDS = {
    'ruby': dict(
        table='gRubyBoardSpriteSets', dir='graphics/stage/ruby',
        gfx='ruby_gfx.json', prefixes=('gRuby',),
        palette=[('ruby_board_palset_0.gbapal', 9),
                 ('../main/bonus_stage_obj.gbapal', 7)]),
    'sapphire': dict(
        table='gSapphireBoardSpriteSets', dir='graphics/stage/sapphire',
        gfx='sapphire_gfx.json', prefixes=('gSapphire',),
        palette=[('sapphire_board_palset_0.gbapal', 16)]),
    'dusclops': dict(
        table='gDusclopsBoardSpriteSets', dir='graphics/stage/dusclops',
        gfx='dusclops_stage_gfx.json', prefixes=('gDusclops', 'gDuskull'),
        palette=[('dusclops_board_palset_0.gbapal', 16)]),
    'kecleon': dict(
        table='gKecleonBoardSpriteSets', dir='graphics/stage/kecleon',
        gfx='kecleon_stage_gfx.json', prefixes=('gKecleon',),
        palette=[('kecleon_board_palset_0.gbapal', 16)]),
    'kyogre': dict(
        table='gKyogreBoardSpriteSets', dir='graphics/stage/kyogre',
        gfx='kyogre_stage_gfx.json', prefixes=('gKyogre',),
        palette=[('kyogre_board_palset_0.gbapal', 16)]),
    'groudon': dict(
        table='gGroudonBoardSpriteSets', dir='graphics/stage/groudon',
        gfx='groudon_stage_gfx.json', prefixes=('gGroudon',),
        palette=[('groudon_board_palset_0.gbapal', 16)]),
    'rayquaza': dict(
        table='gRayquazaBoardSpriteSets', dir='graphics/stage/rayquaza',
        gfx='rayquaza_stage_gfx.json', prefixes=('gRayquaza', 'gRaquaza'),
        palette=[('rayquaza_board_palset_0.gbapal', 16)]),
}

# (board, gfx_filename, segfile) -> (bank, why).  Only for segments no OAM entry
# in the board's data reaches, or where two banks draw the same tiles and the
# tie has to be broken from the code rather than the tables.  A bank is either
# an OBJ bank number or an explicit (palette file, bank) pair, for the regions
# whose palette is DMA'd in from outside the board's own set.
OVERRIDES = {
    # Sparkle art sharing the sheet with the Jirachi star trail that follows it
    # at t657; nothing indexes these tiles directly.
    ('ruby', 'intro_sprite', 'intro_sprite_glint_set_0'): (13, 'unreferenced, matches glint_set'),
    ('ruby', 'intro_sprite', 'intro_sprite_glint'): (13, 'unreferenced, matches glint_set'),

    # Kecleon's head is drawn by both halves of its reflection at the same
    # tiles; gKecleonEntitySpriteSet (bank 2) is the one on the board, and
    # gKecleonReflectionHeadSpriteSet (bank 4) the copy in the water.
    ('kecleon', 'intro_sprite', 'intro_sprite_kecleon'): (2, 'board copy, not the reflection'),
    ('kecleon', 'intro_sprite', 'intro_sprite_kecleon_2'): (2, 'unreferenced, matches kecleon'),
    ('kecleon', 'intro_sprite', 'intro_sprite_grass'): (6, 'unreferenced, matches the foliage banks'),
    ('kecleon', 'intro_sprite', 'intro_sprite_ball_3'): (1, 'unreferenced, matches ball'),

    # t73..92 on the three legendary boards: dusclops and kecleon put their
    # entity art here, these three leave it unused.
    ('kyogre', 'intro_sprite', 'intro_sprite_balls'): (1, 'unreferenced, matches ball'),
    ('groudon', 'intro_sprite', 'intro_sprite_balls'): (1, 'unreferenced, matches ball'),
    ('rayquaza', 'intro_sprite', 'intro_sprite_balls'): (1, 'unreferenced, matches ball'),

    ('groudon', 'intro_sprite', 'intro_sprite_groudon_step'): (15, 'unreferenced, matches the body'),
    ('rayquaza', 'intro_sprite', 'intro_sprite_blank_spacer'): (12, 'blank padding tile'),

    # Rayquaza's head, and the only sprite set reaching it is the roar
    # extension, which draws it through bank 14 -- dark red, the roaring frame.
    # Every other segment of the entity is bank 15, its resting green.
    ('rayquaza', 'intro_sprite', 'intro_sprite_rayquaza_fly_up'):
        (15, 'entity resting palette; bank 14 is only the roar frame'),

    # The shop sign is a scratch region too: UpdateRubyEvolutionShopSprite
    # (main_board_to_be_split.c) streams gRubyBoardShop_Gfx frames into
    # 0x06013D00 -- tile 488, exactly this segment -- and loads gShopPalette
    # into bank 2 for the duration.  Bank 2's resting value is ruby's white
    # flash palette, which is why the tables point at it.
    ('ruby', 'intro_sprite', 'intro_sprite_shop_roof'):
        (('../main/shop.gbapal', 0), 'gShopPalette, loaded into bank 2 while the sign animates'),

    # OBJ bank 12 on the main fields is the 1UP palette: DrawOneUpBannerSprite
    # (main_board_launcher_and_cutscenes.c) streams gOneUpBannerSprite_Gfx over
    # tile 0x295 -- the treeko segment -- and puts gOneUpSpritePalette in bank
    # 12 to draw it.  gTreecko1UpDeliverySpriteSet's other two spans are ball_2
    # and shape, so all three belong to the same sprite.  Ruby's resting value
    # for bank 12 is the tail of gBonusStageObjPal, which is never on screen.
    ('ruby', 'intro_sprite', 'intro_sprite_treeko'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),
    ('ruby', 'intro_sprite', 'intro_sprite_ball_2'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),
    ('ruby', 'intro_sprite', 'intro_sprite_shape'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),
    ('sapphire', 'intro_sprite', 'intro_sprite_treeko'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),
    ('sapphire', 'intro_sprite', 'intro_sprite_ball_2'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),
    ('sapphire', 'intro_sprite', 'intro_sprite_shape'):
        (('../main/one_up_sprite.gbapal', 0), 'gOneUpSpritePalette, loaded into bank 12'),

    # OBJ bank 11 on the main fields never holds its resting ROM value either.
    # UpdateSpoinkAnimation runs every frame on both boards and rewrites it from
    # gFieldPaletteVariants[field][set * 2 + (camera is low)] -- six banks per
    # field, three brightness sets crossed with the half of the board on screen.
    # Set 0 is the one on screen during play, so the upper half is variant 0
    # (ruby) / 6 (sapphire) and the lower half 1 / 7.  Spoink is the plunger at
    # the bottom; the egg, hatch cave and hatch machine sit at the top.
    ('ruby', 'intro_sprite', 'intro_sprite_spoink'):
        (('../main/field_variants.gbapal', 1), 'bank 11, lower half of the board'),
    ('ruby', 'intro_sprite', 'intro_sprite_spoink_tail'):
        (('../main/field_variants.gbapal', 1), 'bank 11, lower half of the board'),
    ('ruby', 'intro_sprite', 'intro_sprite_egg'):
        (('../main/field_variants.gbapal', 0), 'bank 11, upper half of the board'),
    ('ruby', 'intro_sprite', 'intro_sprite_hatch_cave'):
        (('../main/field_variants.gbapal', 0), 'bank 11, upper half of the board'),
    ('sapphire', 'intro_sprite', 'intro_sprite_spoink'):
        (('../main/field_variants.gbapal', 7), 'bank 11, lower half of the board'),
    ('sapphire', 'intro_sprite', 'intro_sprite_spoink_tail'):
        (('../main/field_variants.gbapal', 7), 'bank 11, lower half of the board'),
    ('sapphire', 'intro_sprite', 'intro_sprite_egg'):
        (('../main/field_variants.gbapal', 6), 'bank 11, upper half of the board'),
    ('sapphire', 'intro_sprite', 'intro_sprite_hatch_machine_base'):
        (('../main/field_variants.gbapal', 6), 'bank 11, upper half of the board'),

    # Sapphire's palset leaves OBJ banks 13-15 at zero -- the game loads them
    # when the sprites that use them appear -- while ruby's palset runs on into
    # gBonusStageObjPal and keeps a usable copy there.  This segment carries
    # ruby's art byte for byte, so show it under the palette ruby gives it
    # rather than under sapphire's four resting colours.
    ('sapphire', 'intro_sprite', 'intro_sprite_glint_set'):
        (('../main/bonus_stage_obj.gbapal', 4), 'ruby draws this art with OBJ bank 13'),

    # gKyogreIntroCrystalGroundSpriteSet names bank 10, which kyogre leaves at
    # zero during play -- the board intro loads it before the sprite appears.
    # Bank 12 is the ice palette the neighbouring iceberg tiles use.
    ('kyogre', 'intro_sprite', 'intro_sprite_rock_highlight'):
        (12, 'bank 10 is unset during play; matches the iceberg'),
}

# Four more scratch slots.  Each is filled at run time from a table of
# interchangeable art, and coloured with that entry's own palette, so the OBJ
# bank they nominally draw through holds nothing meaningful until the moment
# they appear.  What ships in the sheet is one specific entry from each table --
# found by searching the ROM for the segment's own tiles -- so each takes the
# palette that same art already carries where it is extracted properly:
#
#   evo_pickup  gEvoItemTilesGfxPtrs[n] -> 0x060116C0, palette gEvoItemPalettes[n]
#               (main_board_evolution_mode.c).  Ships gPickupIcon1_Gfx.
#   location    gLocationPortraitGfx[n] -> 0x06010FA0, palette gLocationPalettes[n]
#               (all_board_portrait_display.c).  Ships entry 0.
#   catch_mon   the other portrait slot, at 0x06010CA0, palette loaded into the
#               bank gPortraitPaletteSlots names.  Ships a Geodude portrait --
#               close to but not byte-identical to the extracted one, so this is
#               the only one of the four identified by likeness rather than an
#               exact match.
#   hatch_mon   gMonHatchSpriteGroup5_Gfx -> 0x060112A0
#               (main_board_pichu_entity.c).  Ships wurmple_hatch frame 0.
#
# Each .gbapal is built from the tracked .png beside it, the arrangement
# graphics/mon_hatch_sprites/hatch.json already uses.
for _board, _segment, _palette, _why in [
    ('ruby', 'evo_pickup', '../../board_pickups/icon1_xp.gbapal', 'pickup icon 1'),
    ('sapphire', 'evo_pickup', '../../board_pickups/icon1_xp.gbapal', 'pickup icon 1'),
    ('ruby', 'location', '../../area_portraits/loc00_ruby_forest.gbapal', 'location portrait 0'),
    ('sapphire', 'location', '../../area_portraits/loc00_ruby_forest.gbapal', 'location portrait 0'),
    ('ruby', 'hatch_mon', '../../mon_hatch_sprites/wurmple_hatch.gbapal', 'wurmple hatch frame 0'),
    ('sapphire', 'hatch_mon', '../../mon_hatch_sprites/wurmple_hatch.gbapal', 'wurmple hatch frame 0'),
    ('ruby', 'catch_mon', '../../mon_portraits/geodude_portrait.gbapal', 'geodude portrait'),
    ('sapphire', 'catch_mon', '../../mon_portraits/geodude_portrait.gbapal', 'geodude portrait'),
    ('kyogre', 'catch_mon', '../../mon_portraits/geodude_portrait.gbapal', 'geodude portrait'),
    ('groudon', 'catch_mon', '../../mon_portraits/geodude_portrait.gbapal', 'geodude portrait'),
    ('rayquaza', 'catch_mon', '../../mon_portraits/geodude_portrait.gbapal', 'geodude portrait'),
]:
    OVERRIDES[(_board, 'intro_sprite', 'intro_sprite_' + _segment)] = ((_palette, 0), _why)


# ---------------------------------------------------------------- rom parsing

def _int(text):
    text = text.strip()
    return int(text, 16) if text.lower().startswith(('0x', '-0x')) else int(text, 0)


def read_oam_data(path=ROM_SOURCE):
    """-> (label -> [(tile, bank, tile_count)], label -> [referenced labels])"""
    entries = collections.defaultdict(list)
    tables = collections.defaultdict(list)
    label = None
    for line in open(path):
        m = re.match(r'^(\w+)::', line)
        if m:
            label = m.group(1)
            continue
        m = re.match(r'^\s*packed_sprite_oaml?\s+(.*)$', line)
        if m:
            args = {}
            for part in m.group(1).split('@')[0].split(','):
                if '=' in part:
                    key, value = part.split('=', 1)
                    args[key.strip()] = value.strip()
            named = re.search(r'SPRITE_SIZE_(\d+)x(\d+)', args.get('spriteSize', ''))
            if named:
                w, h = int(named.group(1)), int(named.group(2))
            else:
                w, h = OAM_DIMS[(_int(args.get('shape', '0')), _int(args.get('size', '0')))]
            entries[label].append((_int(args['tileNum']), _int(args['paletteNum']),
                                   (w // 8) * (h // 8)))
            continue
        m = re.match(r'^\s*\.4byte\s+(g\w+)\s*(?:@.*)?$', line)
        if m and label:
            tables[label].append(m.group(1))
    return entries, tables


# ------------------------------------------------------------------ png codec

def png_read_indices(path):
    """-> (width, height, rows, greyscale) for a 4-bit PNG.

    `rows` holds raw samples, not colour indices: for a greyscale PNG the two
    differ by gbagfx's inversion, and only the caller knows whether it wants
    what is on disk or what the tile data means."""
    data = open(path, 'rb').read()
    if data[:8] != b'\x89PNG\r\n\x1a\x0a':
        raise ValueError('%s: not a PNG' % path)
    idat = b''
    width = height = None
    pos = 8
    while pos + 8 <= len(data):
        length = struct.unpack('>I', data[pos:pos + 4])[0]
        tag = data[pos + 4:pos + 8]
        chunk = data[pos + 8:pos + 8 + length]
        if tag == b'IHDR':
            width, height, depth, colour, _, _, interlace = struct.unpack('>IIBBBBB', chunk)
            if depth != 4 or colour not in (0, 3) or interlace:
                raise ValueError('%s: expected a non-interlaced 4bpp PNG, got '
                                 'depth %d colour type %d' % (path, depth, colour))
        elif tag == b'IDAT':
            idat += chunk
        elif tag == b'IEND':
            break
        pos += 12 + length

    raw = zlib.decompress(idat)
    stride = (width + 1) // 2
    rows = []
    previous = bytearray(stride)
    pos = 0
    for _ in range(height):
        filter_type = raw[pos]
        pos += 1
        line = bytearray(raw[pos:pos + stride])
        pos += stride
        for i in range(stride):
            left = line[i - 1] if i else 0
            up = previous[i]
            upleft = previous[i - 1] if i else 0
            if filter_type == 1:
                line[i] = (line[i] + left) & 0xFF
            elif filter_type == 2:
                line[i] = (line[i] + up) & 0xFF
            elif filter_type == 3:
                line[i] = (line[i] + ((left + up) >> 1)) & 0xFF
            elif filter_type == 4:
                estimate = left + up - upleft
                da, db, dc = (abs(estimate - left), abs(estimate - up),
                              abs(estimate - upleft))
                nearest = left if (da <= db and da <= dc) else (up if db <= dc else upleft)
                line[i] = (line[i] + nearest) & 0xFF
            elif filter_type != 0:
                raise ValueError('%s: unknown filter %d' % (path, filter_type))
        pixels = []
        for byte in line:
            pixels.append(byte >> 4)
            pixels.append(byte & 0xF)
        rows.append(pixels[:width])
        previous = line
    return width, height, rows, colour == 0


def png_palette(path):
    """-> the PLTE colours of a PNG, or None when it has none."""
    data = open(path, 'rb').read()
    pos = 8
    while pos + 8 <= len(data):
        length = struct.unpack('>I', data[pos:pos + 4])[0]
        tag = data[pos + 4:pos + 8]
        if tag == b'PLTE':
            chunk = data[pos + 8:pos + 8 + length]
            return [tuple(chunk[i:i + 3]) for i in range(0, length, 3)]
        if tag == b'IEND':
            break
        pos += 12 + length
    return None


def png_write_indexed(path, width, height, rows, palette):
    """Write a 4-bit colour-type-3 PNG.  Matches what gbagfx itself emits:
    IHDR, PLTE, IDAT, IEND, with no transparency chunk."""
    def chunk(tag, payload):
        body = tag + payload
        return (struct.pack('>I', len(payload)) + body
                + struct.pack('>I', zlib.crc32(body) & 0xFFFFFFFF))

    colours = list(palette) + [(0, 0, 0)] * (16 - len(palette))
    stride = (width + 1) // 2
    raw = bytearray()
    for row in rows:
        raw.append(0)
        line = bytearray(stride)
        for x, index in enumerate(row):
            if x & 1:
                line[x >> 1] |= index & 0xF
            else:
                line[x >> 1] = (index & 0xF) << 4
        raw += line

    out = b'\x89PNG\r\n\x1a\x0a'
    out += chunk(b'IHDR', struct.pack('>IIBBBBB', width, height, 4, 3, 0, 0, 0))
    out += chunk(b'PLTE', b''.join(bytes(c) for c in colours[:16]))
    out += chunk(b'IDAT', zlib.compress(bytes(raw), 9))
    out += chunk(b'IEND', b'')
    open(path, 'wb').write(out)


# --------------------------------------------------------------------- palette

def read_gbapal(path):
    """-> list of (r, g, b), scaled the way gbagfx does it (5-bit value << 3)."""
    data = open(path, 'rb').read()
    colours = []
    for i in range(0, len(data), 2):
        value = data[i] | data[i + 1] << 8
        colours.append(((value & 31) << 3, ((value >> 5) & 31) << 3,
                        ((value >> 10) & 31) << 3))
    return colours


def obj_palette(board):
    """The 16 banks a board loads into OBJ palette RAM, as (file, bank) per bank."""
    slots = []
    for name, banks in BOARDS[board]['palette']:
        for bank in range(banks):
            slots.append((name, bank))
    return slots[:16]


# ------------------------------------------------------------------- segments

def gfx_files(board):
    path = os.path.join(BOARDS[board]['dir'], BOARDS[board]['gfx'])
    return path, json.load(open(path))


def patch_segment(text, segfile, palette, bank):
    """Add palette/palbank to one segment object, leaving the rest of the file
    byte for byte alone.  json.dump would reflow all of it -- and normalise the
    CRLF several of these configs use -- which buries the change in a whole-file
    diff."""
    newline = '\r\n' if '\r\n' in text else '\n'
    marker = re.search(r'"segfile"\s*:\s*"%s"' % re.escape(segfile), text)
    if not marker:
        raise KeyError('no segment %r in the config' % segfile)
    start = text.rfind('{', 0, marker.start())
    depth = 0
    for end in range(start, len(text)):
        depth += {'{': 1, '}': -1}.get(text[end], 0)
        if depth == 0:
            break
    body = text[start:end]
    body = re.sub(r',\s*"pal(?:ette|bank)"\s*:\s*[^,}\r\n]+', '', body)
    indent = re.search(r'\n([ \t]*)"segfile"', body)
    pad = indent.group(1) if indent else '      '
    gap = ' ' if re.search(r'"segfile":\s', body) else ''
    added = ',{nl}{pad}"palette":{gap}{palette},{nl}{pad}"palbank":{gap}{bank}{nl}{close}'.format(
        nl=newline, pad=pad, gap=gap, palette=json.dumps(palette), bank=bank,
        close=pad[:-2])
    return text[:start] + body.rstrip() + added + text[end:]


def segment_ranges(board, entry):
    """-> [(segfile, first_tile, tile_count)] for one gfx.json file entry.

    Tile counts come from the built per-segment .4bpp when it is there: -oam and
    -oamshape segments are not width*height/64 tiles, and using the PNG size for
    those drifts every later offset (13 tiles over, on ruby's sheet)."""
    directory = BOARDS[board]['dir']
    ranges = []
    offset = 0
    for segment in entry.get('segments', []):
        segfile = segment['segfile']
        built = os.path.join(directory, '%s_%s.4bpp' % (entry['gfx_filename'], segfile))
        if os.path.exists(built):
            count = os.path.getsize(built) // 32
        else:
            width, height = png_read_indices(os.path.join(directory, segfile + '.png'))[:2]
            count = (width // 8) * (height // 8)
        ranges.append((segfile, offset, count))
        offset += count
    return ranges


def flat_banks(board):
    """Banks holding fewer than four distinct colours.  Two things land here and
    neither describes any art: flash states the game swaps in for a few frames
    (gRubyShopSignChangeSpriteSet draws the sign through ruby's all-white bank
    2), and banks a board leaves at zero because it loads the real palette from
    somewhere else when the sprite is actually on screen.  Either way a segment
    that only such a bank reaches is reported unresolved rather than given a
    palette it would render solid under."""
    flat = set()
    for bank, (name, index) in enumerate(obj_palette(board)):
        colours = read_gbapal(os.path.join(BOARDS[board]['dir'], name))
        if len(set(colours[index * 16:index * 16 + 16])) < 4:
            flat.add(bank)
    return flat


def derive_banks(board, entry, oam, tables):
    """-> [(segfile, first_tile, count, bank, source)], bank None when unknown."""
    ranges = segment_ranges(board, entry)
    bounds = [(start, start + count, name) for name, start, count in ranges]

    def owning_segment(tile):
        for start, end, name in bounds:
            if start <= tile < end:
                return name
        return None

    def vote(name, start, count, labels):
        """Tiles and entries per bank, over entries wholly inside the segment."""
        tiles = collections.defaultdict(set)
        votes = collections.Counter()
        for label in labels:
            for tile, bank, span in oam.get(label, ()):
                covered = range(tile, tile + span)
                if bank in flat or {owning_segment(t) for t in covered} != {name}:
                    continue
                tiles[bank] |= set(covered)
                votes[bank] += 1
        return tiles, votes

    flat = flat_banks(board)
    table = tables.get(BOARDS[board]['table'], [])
    animation = [label for label in oam
                 if label.startswith(BOARDS[board]['prefixes'])]

    out = []
    for name, start, count in ranges:
        override = OVERRIDES.get((board, entry['gfx_filename'], name))
        if override:
            out.append((name, start, count, override[0], 'override: ' + override[1]))
            continue
        for labels, source in ((table, 'sprite set'), (animation, 'oam array')):
            tiles, votes = vote(name, start, count, labels)
            if not tiles:
                continue
            best = max(len(v) for v in tiles.values())
            winners = [b for b, v in tiles.items() if len(v) == best]
            if len(winners) > 1:                     # same tiles, two banks
                winners = [max(winners, key=lambda b: votes[b])] \
                    if len({votes[b] for b in winners}) > 1 else winners
            if len(winners) == 1:
                out.append((name, start, count, winners[0],
                            '%s %d/%d tiles' % (source, best, count)))
                break
        else:
            out.append((name, start, count, None, 'no OAM entry reaches these tiles'))
    return out


# ------------------------------------------------------------------- commands

def cmd_derive(args):
    oam, tables = read_oam_data(args.rom_source)
    unresolved = 0
    for board in args.boards:
        path, config = gfx_files(board)
        slots = obj_palette(board)
        text = open(path, newline='').read()
        changed = False
        print('== %s (%s)' % (board, path))
        for entry in config['files']:
            if args.name and entry['gfx_filename'] != args.name:
                continue
            if not entry.get('segments'):
                continue
            for name, start, count, bank, source in derive_banks(board, entry, oam, tables):
                if bank is None:
                    unresolved += 1
                    print('   ??  %-38s t%-4d n%-3d  %s' % (name, start, count, source))
                    continue
                palette, index = slots[bank] if isinstance(bank, int) else bank
                print('   %-4s%-38s t%-4d n%-3d  %-16s %s#%d'
                      % (bank if isinstance(bank, int) else '--',
                         name, start, count, source, palette, index))
                for segment in entry['segments']:
                    if segment['segfile'] == name and \
                            (segment.get('palette'), segment.get('palbank')) != (palette, index):
                        text = patch_segment(text, name, palette, index)
                        changed = True
        if changed and args.write:
            open(path, 'w', newline='').write(text)
            print('   written')
    if unresolved:
        print('\n%d segment(s) unresolved -- add them to OVERRIDES' % unresolved)
    return 1 if unresolved else 0


def cmd_apply(args):
    for board in args.boards:
        directory = BOARDS[board]['dir']
        _, config = gfx_files(board)
        for entry in config['files']:
            if args.name and entry['gfx_filename'] != args.name:
                continue
            for segment in entry.get('segments', []):
                if 'palette' not in segment:
                    continue
                png = os.path.join(directory, segment['segfile'] + '.png')
                bank = segment.get('palbank', 0)
                colours = read_gbapal(os.path.join(directory, segment['palette']))
                colours = colours[bank * 16:bank * 16 + 16]
                width, height, rows, greyscale = png_read_indices(png)
                if png_palette(png) == colours:
                    continue
                if args.dry_run:
                    print('would recolour %s' % png)
                    continue
                if greyscale:
                    rows = [[15 - value for value in row] for row in rows]
                png_write_indexed(png, width, height, rows, colours)
                print('recoloured %s' % png)
    return 0


def cmd_check(args):
    bad = 0
    for board in args.boards:
        directory = BOARDS[board]['dir']
        _, config = gfx_files(board)
        for entry in config['files']:
            if args.name and entry['gfx_filename'] != args.name:
                continue
            for segment in entry.get('segments', []):
                png = os.path.join(directory, segment['segfile'] + '.png')
                if 'palette' not in segment:
                    if png_palette(png) is None:
                        print('no palette recorded and none in the PNG: %s' % png)
                        bad += 1
                    continue
                bank = segment.get('palbank', 0)
                colours = read_gbapal(os.path.join(directory, segment['palette']))
                if png_palette(png) != colours[bank * 16:bank * 16 + 16]:
                    print('palette does not match %s#%d: %s'
                          % (segment['palette'], bank, png))
                    bad += 1
    print('%d mismatch(es)' % bad)
    return 1 if bad else 0


def main():
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--board', default='all',
                        help='board name, or "all" (default)')
    parser.add_argument('--name', default='intro_sprite',
                        help='gfx_filename to work on, or "" for every segmented '
                             'sheet in the config (default: intro_sprite)')
    sub = parser.add_subparsers(dest='command', required=True)

    p = sub.add_parser('derive', help='work out each segment\'s palette bank')
    p.add_argument('--rom-source', default=ROM_SOURCE)
    p.add_argument('--write', action='store_true',
                   help='record the result in the gfx.json')
    p.set_defaults(func=cmd_derive)

    p = sub.add_parser('apply', help='recolour segment PNGs from the gfx.json')
    p.add_argument('--dry-run', action='store_true')
    p.set_defaults(func=cmd_apply)

    p = sub.add_parser('check', help='verify PNG palettes against the gfx.json')
    p.set_defaults(func=cmd_check)

    args = parser.parse_args()
    if args.board == 'all':
        args.boards = list(BOARDS)
    elif args.board in BOARDS:
        args.boards = [args.board]
    else:
        parser.error('unknown board %r; expected one of %s, or "all"'
                     % (args.board, ', '.join(BOARDS)))
    return args.func(args)


if __name__ == '__main__':
    sys.exit(main())
