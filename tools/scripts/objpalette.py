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

Two kinds of sheet
------------------
BOARDS covers the sheets a board loads whole: their segments start at OBJ tile
0 and each gets its own bank.  SLOTS covers the ones streamed frame by frame
over a slot inside that sheet while the board runs -- the entities, the shop
sign, every banner -- which start at the slot's tile instead, and whose frames
all share the single bank covering the slot.

Whatever is left is a region no OAM entry ever names -- scratch the game DMAs
over before drawing, or sheet padding -- or a slot whose palette arrives from
outside the board's set entirely, as most of the tile-704 banners do.  Those
are listed in OVERRIDES and SLOT_PALETTES with the reason, since no amount of
static analysis will settle them.

A sheet that the Makefile's plain %.4bpp: %.png rule already handles has no
config entry to record the answer in; `derive` adds one carrying nothing but
the palette, which generate_graphics_rules.sh ignores.

Only stdlib is used, so this adds no build dependency.

Not covered: sheets that go to BG VRAM rather than OBJ.  Their bank lives in
the tilemap entries the code writes, not in any OAM data, so they need a
different derivation -- graphics/*/text*.png and high_score/ball_watermark_tiles
are still greyscale for that reason.

Examples
--------
    objpalette.py derive --board ruby --write
    objpalette.py apply  --board all
    objpalette.py check  --board all
"""

import argparse
import collections
import glob
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
    # The Pokedex is a screen rather than a board, but it works the same way:
    # one sheet to OBJ_VRAM0, one palette to OBJ_PLTT, one sprite-set table
    # (pokedex.c:133).
    'pokedex': dict(
        table=('gPokedexSpriteSets', 'gEReaderSpriteSets'), dir='graphics/pokedex',
        gfx='pokedex_gfx.json', prefixes=('gPokedex',),
        palette=[('sprites.gbapal', 16)]),
    'spheal': dict(
        table='gSphealBoardSpriteSets', dir='graphics/stage/spheal',
        gfx='gfx_segments.json', prefixes=('gSpheal',),
        palette=[('spheal_board_palset_0.gbapal', 16)]),
}

# Sheets that are not laid into the board sheet but streamed over a slot inside
# it, frame by frame, while the board runs.  Every frame in such a sheet is
# drawn through the same OAM entry, so the whole thing takes one palette: the
# one covering the slot it lands in.
#
#   (dir, gfx_filename) -> (board, first tile, tile count, where the copy is)
#
# The tiles come straight from the destination in the DmaCopy16 named in the
# comment: (dest - 0x06010000) / 32, length / 32.
SLOTS = {
    ('graphics/stage/ruby', 'cyndaquil'): ('ruby', 408, 20, 'main_board_to_be_split.c'),
    ('graphics/stage/ruby', 'gulpin'): ('ruby', 452, 12, 'ruby_trigger_targets.c, three slots'),
    ('graphics/stage/ruby', 'hatch_cave'): ('ruby', 277, 36, 'main_board_to_be_split.c'),
    ('graphics/stage/ruby', 'nuzleaf'): ('ruby', 540, 19, 'ruby_process3_entities_2.c'),
    # Labelled gRubyChikoritaEntity, but ruby_trigger_targets.c streams it
    # into the Chikorita slot and gRubyChikoritaSpriteSet is what draws it.
    ('graphics/stage/ruby', 'chikorita_frames'): ('ruby', 313, 24, 'ruby_trigger_targets.c'),
    ('graphics/stage/ruby', 'makuhita'): ('ruby', 428, 24, 'ruby_ramp.c'),
    ('graphics/stage/ruby', 'ramp_prize'): ('ruby', 600, 4, 'ruby_ramp.c'),
    ('graphics/stage/ruby', 'sharpedo'): ('ruby', 353, 19, 'ruby_process3_entities_2.c'),
    ('graphics/stage/ruby', 'shop'): ('ruby', 488, 40, 'main_board_to_be_split.c'),
    ('graphics/stage/ruby', 'shop_door'): ('ruby', 396, 12, 'ruby_process3_entities_2.c'),
    ('graphics/stage/ruby', 'whiscash'): ('ruby', 564, 35, 'ruby_process3_entities_2.c'),

    ('graphics/stage/sapphire', 'pelipper'): ('sapphire', 277, 36, 'sapphire_pond_and_zigzagoon.c'),
    ('graphics/stage/sapphire', 'charger'): ('sapphire', 277, 36, 'tail of gPelipper_Gfx'),
    ('graphics/stage/sapphire', 'seedot'): ('sapphire', 481, 11, 'sapphire_seedot_egg_shop.c'),
    ('graphics/stage/sapphire', 'seedot_basket'): ('sapphire', 461, 20, 'sapphire_seedot_egg_shop.c'),
    ('graphics/stage/sapphire', 'shop_shock_wall'): ('sapphire', 565, 4, 'main_board_bumpers.c'),
    ('graphics/stage/sapphire', 'wailmer'): ('sapphire', 313, 24, 'sapphire_pond_and_zigzagoon.c'),
    ('graphics/stage/sapphire', 'zigzagoon'): ('sapphire', 337, 28, 'sapphire_pond_and_zigzagoon.c'),

    ('graphics/stage/dusclops', 'dusclops'): ('dusclops', 133, 64, 'dusclops_process3.c'),
    ('graphics/stage/dusclops', 'duskull'): ('dusclops', 73, 20, 'dusclops_process3.c'),
    ('graphics/stage/dusclops', 'dusclops_appear_fx'): ('dusclops', 213, 96, 'dusclops_process3.c'),
    ('graphics/stage/dusclops', 'dusclops_ball_grab'): ('dusclops', 197, 16, 'dusclops_process3.c'),

    ('graphics/stage/kecleon', 'kecleon'): ('kecleon', 73, 20, 'kecleon_process3.c'),
    ('graphics/stage/kecleon', 'kecleon_fx'): ('kecleon', 93, 8, 'kecleon_process3.c'),

    ('graphics/stage/groudon', 'boulders'): ('groudon', 125, 24, 'groudon_process3.c'),
    ('graphics/stage/groudon', 'board_fx'): ('groudon', 704, 256, 'groudon_process3.c'),

    # Labelled gKyogreWhirlpoolSpriteFrames, but the only code that reads it is
    # the freeze trap (gKyogrefreezeTrapAnimFrameset, gKyogreFreezeTrapSpriteSet).
    ('graphics/stage/kyogre', 'freeze_trap_frames'): ('kyogre', 295, 30, 'kyogre_process3.c'),
    ('graphics/stage/kyogre', 'whirlpool_minion_frames'): ('kyogre', 169, 16, 'kyogre_process3.c'),

    ('graphics/stage/spheal', 'spheal'): ('spheal', 229, 9, 'spheal_process3.c'),
    ('graphics/stage/spheal', 'sealeo'): ('spheal', 165, 48, 'spheal_process3.c'),
    ('graphics/stage/spheal', 'spheal_net'): ('spheal', 73, 16, 'spheal_process3.c'),
    ('graphics/stage/spheal', 'spheal_net_front'): ('spheal', 89, 12, 'spheal_process3.c'),

    # Shared between both main fields; ruby is the one shown.  Ruby and
    # sapphire agree on OBJ banks 0, 1 and 3 and differ everywhere else, so a
    # sheet landing outside those banks is ruby's colours by choice.
    ('graphics/stage/main', 'bonus_trap'): ('ruby', 158, 24, 'main_board_to_be_split.c'),
    ('graphics/stage/main', 'charge_fill_indicator'): ('ruby', 87, 4, 'main_board_to_be_split.c'),
    ('graphics/stage/main', 'egg'): ('ruby', 231, 16, 'main_board_to_be_split.c'),
    ('graphics/stage/main', 'pause_menu_text'): ('ruby', 198, 1, 'all_board_pause_game.c'),
    ('graphics/stage/main', 'pika_spinner'): ('ruby', 60, 9, 'main_board_charge_spinner.c'),
    ('graphics/stage/main', 'gunk_0844AA0C'): ('ruby', 101, 36, 'gJirachiFx_Gfx, main_board_catch_normal_and_jirachi_modes.c'),
    ('graphics/stage/main', 'latios'): ('ruby', 832, 64, 'all_board_mode_change_and_debug_menu.c'),
    ('graphics/stage/main', 'latios_arm'): ('ruby', 896, 6, 'all_board_mode_change_and_debug_menu.c'),
    ('graphics/stage/main', 'gunk_084F61EC'): ('ruby', 736, 74, 'gPokemonNameDisplayGfx, main_board_catch_holes.c'),

    ('graphics/stage/misc', 'gunk_0845690C'): ('ruby', 413, 16, 'gPondBumper_Gfx, main_board_bumpers.c'),
    ('graphics/stage', 'gunk_084ED6CC'): ('sapphire', 637, 16, 'gZigzagoonShockWallIndicator_Gfx, sapphire_pond_and_zigzagoon.c'),

    # Tile 704 (0x06015800) is the shared overlay slot every mode borrows for
    # its banner.  These sheets are segmented, so their segments run from 704
    # rather than from tile 0.
    ('graphics/stage/ruby', 'travel_paint'): ('ruby', 704, 192, 'main_board_launcher_and_cutscenes.c'),
    ('graphics/stage/sapphire', 'travel_paint'): ('sapphire', 704, 192, 'main_board_launcher_and_cutscenes.c'),
    ('graphics/stage/main', 'ball_save'): ('ruby', 704, 288, 'all_board_mode_change_and_debug_menu.c'),
    ('graphics/stage/main', 'capture_screen'): ('ruby', 704, 225, 'main_board_center_capture_hole.c'),
    ('graphics/stage/main', 'alphabet'): ('ruby', 704, 2, 'main_board_to_be_split.c'),
    ('graphics/stage/main', 'capture_mode'): ('ruby', 704, 102, 'main_board_to_be_split.c'),
    ('graphics/stage/main', 'spoink_launcher'): ('ruby', 263, 14, 'main_board_launcher_and_cutscenes.c'),
    ('graphics/stage/main', 'flipper_frames'): ('ruby', 0, 16, 'all_board_process4.c'),
    ('graphics/stage/main', 'decimal_digits'): ('ruby', 749, 2, 'all_board_banners.c'),
    ('graphics/stage/ruby', 'chikorita_projectile'): ('ruby', 528, 4, 'ruby_trigger_targets.c'),
    ('graphics/stage/ruby', 'chikorita_projectile_fx'): ('ruby', 532, 8, 'ruby_trigger_targets.c'),
    ('graphics/stage/ruby', 'linoone_side_bumper'): ('ruby', 337, 8, 'ruby_trigger_targets.c'),
    ('graphics/stage/kyogre', 'surfacing_fx_frames'): ('kyogre', 289, 6, 'kyogre_process3.c'),
    ('graphics/stage/rayquaza', 'entity_flying'): ('rayquaza', 177, 67, 'rayquaza_process3.c'),
    ('graphics/stage/sapphire', 'hatch_machine_spark_fx'): ('sapphire', 517, 8, 'sapphire_seedot_egg_shop.c'),
    # Labelled gBallUpgradeFx_Gfx, but the group is FIELD_SG_BALL_UPGRADE_FX
    # and gBallUpgradeFxSpriteSet is what draws it.
    ('graphics/stage/main', 'ball_upgrade_fx_frames'): ('ruby', 247, 16, 'all_board_process7.c'),
    ('graphics/stage/main', 'ball_spawn_glow_type1'): ('ruby', 57, 16, 'all_board_process7.c'),
    ('graphics/stage/main', 'ball_spawn_glow_type2'): ('ruby', 57, 16, 'all_board_process7.c'),
    ('graphics/stage/main', 'end_of_ball'): ('ruby', 704, 320, 'all_board_mode_change_and_debug_menu.c'),
    ('graphics/stage/main', 'game_over_text'): ('ruby', 704, 32, 'all_board_mode_change_and_debug_menu.c'),
    ('graphics/stage/main', 'area_roulette_selected_fx'): ('ruby', 704, 20, 'main_board_intro_mode.c'),
    ('graphics/stage/sapphire', 'zigzagoon_fx'): ('sapphire', 704, 96, 'sapphire_pond_and_zigzagoon.c'),
    ('graphics/stage/spheal', 'spheal_results'): ('spheal', 704, 64, 'spheal_process3.c'),
    # 306 tiles, though the copy asks for 320 and runs into the label below it.
    ('graphics/stage/rayquaza', 'sky_background'): ('rayquaza', 704, 306, 'rayquaza_process3.c'),
    ('graphics/stage/rayquaza', 'wind_board'): ('rayquaza', 704, 224, 'rayquaza_process3.c'),
    # Labelled gRayquazaTornadoGfx; gRaquazaTornadoSpriteSet is what reads
    # the slot, and the art is a tornado.
    ('graphics/stage/rayquaza', 'tornado_frames'): ('rayquaza', 245, 20, 'rayquaza_process3.c'),
    ('graphics/stage/dusclops', 'dusclops_bonus_clear'): ('dusclops', 704, 256, 'dusclops_process3.c'),
    ('graphics/stage/groudon', 'groudon_bonus_clear'): ('groudon', 704, 256, 'groudon_process3.c'),
    ('graphics/stage/kecleon', 'kecleon_bonus_clear'): ('kecleon', 704, 256, 'kecleon_process3.c'),
    ('graphics/stage/kyogre', 'kyogre_bonus_clear'): ('kyogre', 704, 256, 'kyogre_process3.c'),
    ('graphics/stage/rayquaza', 'rayquaza_bonus_clear'): ('rayquaza', 704, 256, 'rayquaza_process3.c'),
}

# Slots whose palette the vote cannot reach, with the copy that settles it.
SLOT_PALETTES = {
    # The catch-tile break sheet and its palette are DMA'd together
    # (main_board_catch_tile_logic.c): the sheet over the tile-704 overlay slot,
    # gCatchTile_RevealPalette into OBJ bank 14.  Every OAM entry that draws it
    # names bank 14, so the whole sheet takes that one palette.
    ('graphics/stage/main', 'catch_tile_reveal'): ('catch_tile_reveal.gbapal', 0,
                                                   'gCatchTile_RevealPalette, DMAd to OBJ bank 14 beside the sheet'),
    # Same pairing again for the burst stages, each with its own palette label
    # sitting beside its sheet in rom_1.s.
    # OBJ bank 11 on the main field is not the board's own set: field_variants
    # supplies it, three brightness sets crossed with the half of the board on
    # screen.  Spoink is the plunger at the bottom, so it takes the lower-half
    # variant -- greys with a pink crest -- not bank 11's resting value, which is
    # the yellow-green set and is what the vote sees.  Ruby's intro sheet already
    # carries the same binding for its own copy of this sprite.
    ('graphics/stage/main', 'spoink_launcher'): ('field_variants.gbapal', 1,
                                                 'bank 11, lower half of the board'),
    # The two pond bumpers, streamed into the same three slots and each loading
    # its own palette into OBJ bank 9 in the copy right after the tiles.
    ('graphics/stage/main', 'chinchou_bumper'): ('chinchou_bumper.gbapal', 0,
                                                 'gChinchouBumperPalettes, DMAd to OBJ bank 9 beside the sheet'),
    ('graphics/stage/main', 'lotad_bumper'): ('lotad_bumper.gbapal', 0,
                                              'gLotadBumperPalettes, DMAd to OBJ bank 9 beside the sheet'),
    ('graphics/stage/main', 'egg_mode'): ('egg_mode.gbapal', 0,
                                          'gAerodactlyFlight_Pal, DMAd to OBJ bank 14 beside the sheet'),
    ('graphics/stage/main', 'egg_mode_cap'): ('egg_mode.gbapal', 0,
                                              'tail of the egg mode sheet, past the copy'),
    ('graphics/stage/main', 'catch_mon_appear_fx'): ('catch_mon_appear_fx.gbapal', 0,
                                                    'gCatchMonAppearFx_Pal, DMAd to OBJ bank 14 beside the sheet'),
    ('graphics/stage/main', 'catch_tile_burst_start'): ('catch_tile_burst_start.gbapal', 0,
                                                       'gCatchTile_BurstStart_Pal, DMAd to OBJ bank 14 beside the sheet'),
    ('graphics/stage/main', 'catch_tile_burst_stage2'): ('catch_tile_burst_stage2.gbapal', 0,
                                                        'gCatchTile_BurstStage2_Pal, DMAd to OBJ bank 14 beside the sheet'),
    ('graphics/stage/main', 'catch_tile_burst_stage3'): ('catch_tile_burst_stage3.gbapal', 0,
                                                        'gCatchTile_BurstStage3_Pal, DMAd to OBJ bank 14 beside the sheet'),
    ('graphics/stage/main', 'catch_tile_burst_stage4'): ('catch_tile_burst_stage4.gbapal', 0,
                                                        'gCatchTile_BurstStage4_Pal, DMAd to OBJ bank 14 beside the sheet'),
    # Tile 57 is one of the lowest slots and half the game's screens put
    # something there, so the vote lands on whichever set happens to cover most
    # of it -- gPikaChargingSpinnerSpriteSet, with 9 of 16 tiles.  The set that
    # actually reads this slot is gBonusBoardBallRespawnFxSpriteSet: one 32x32
    # over the whole 16, drawn in bank 1, which is where the board keeps
    # gBallPalettes.
    ('graphics/stage/main', 'ball_spawn_glow_type1'): ('../ruby/ruby_board_palset_0.gbapal', 1,
                                                       'gBonusBoardBallRespawnFxSpriteSet, bank 1'),
    ('graphics/stage/main', 'ball_spawn_glow_type2'): ('../ruby/ruby_board_palset_0.gbapal', 1,
                                                       'gBonusBoardBallRespawnFxSpriteSet, bank 1'),
    # Same pairing for the evolution banner: gBoardActionObjPal goes to OBJ bank
    # 14 in the copy right after the sheet's own
    # (main_board_launcher_and_cutscenes.c), and every gEvolutionBanner* entry
    # that draws it names bank 14.
    ('graphics/stage/main', 'board_action'): ('board_action_obj.gbapal', 0,
                                              'gBoardActionObjPal, DMAd to OBJ bank 14 beside the sheet'),

    # The 1UP banner and the life-count digit beside it are the sheets that
    # stream over tiles 0x295 and 0x2a9, drawn through gOneUpSpritePalette.
    ('graphics/stage/misc', 'gunk_08455E8C'): ('../main/one_up_sprite.gbapal', 0,
                                               'gOneUpBannerSprite_Gfx, bank 12'),
    ('graphics/stage/misc', 'gunk_0845648C'): ('../main/one_up_sprite.gbapal', 0,
                                               'gLifeCountDigit_Gfx, bank 12'),
    # The evolution pickup icons: gEvoItemPalettes runs parallel to
    # gEvoItemAppear_GfxList, so each sheet takes the icon palette of its name.
    ('graphics/board_pickups', 'evo_item_ex'): ('icon1_xp.gbapal', 0, 'gEvoItemPalettes[0]'),
    ('graphics/board_pickups', 'evo_item_leaf'): ('icon2_leaf.gbapal', 0, 'gEvoItemPalettes[1]'),
    ('graphics/board_pickups', 'evo_item_fire'): ('icon3_fire.gbapal', 0, 'gEvoItemPalettes[2]'),
    ('graphics/board_pickups', 'evo_item_link'): ('icon4_link.gbapal', 0, 'gEvoItemPalettes[3]'),
    ('graphics/board_pickups', 'evo_item_moon'): ('icon5_moon.gbapal', 0, 'gEvoItemPalettes[4]'),
    ('graphics/board_pickups', 'evo_item_water'): ('icon6_water.gbapal', 0, 'gEvoItemPalettes[5]'),
    ('graphics/board_pickups', 'evo_item_bolt'): ('icon7_bolt.gbapal', 0, 'gEvoItemPalettes[6]'),
    ('graphics/board_pickups', 'evo_item_sun'): ('icon8_sun.gbapal', 0, 'gEvoItemPalettes[7]'),
    ('graphics/board_pickups', 'evo_item_heart'): ('icon9_heart.gbapal', 0, 'gEvoItemPalettes[8]'),
    ('graphics/board_pickups', 'evo_item_box'): ('icon10_pokeblock.gbapal', 0, 'gEvoItemPalettes[9]'),

    # Tile 704 and OBJ bank 14 are the overlay pair: every mode that wants a
    # banner streams its sheet over one and its palette over the other, so
    # whichever sprite set the vote happens to find there says nothing.  The
    # palette is the one loaded beside the sheet's own copy.
    ('graphics/stage/ruby', 'travel_paint'):
        ('painter.gbapal', 0, 'gRubyPainterPalette, bank 14'),
    ('graphics/stage/sapphire', 'travel_paint'):
        ('painter.gbapal', 0, 'gSapphirePainterPalette, bank 14'),
    ('graphics/stage/main', 'ball_save'):
        ('bonus_stage_lit.gbapal', 0, 'gBonusStagePal_Lit, bank 14'),
    ('graphics/stage/main', 'latios'):
        ('bonus_stage_lit.gbapal', 0, 'gBonusStagePal_Lit, bank 14'),
    ('graphics/stage/main', 'latios_arm'):
        ('bonus_stage_lit.gbapal', 0, 'gBonusStagePal_Lit, bank 14'),
    ('graphics/stage/main', 'end_of_ball'):
        ('bonus_clear_text_lit.gbapal', 0, 'gBonusClearTextPal_Lit, bank 14'),
    ('graphics/stage/main', 'game_over_text'):
        ('bonus_clear_text_lit.gbapal', 0, 'bank 14, as the end-of-ball banner left it'),
    ('graphics/stage/main', 'area_roulette_selected_fx'):
        ('travel_portrait.gbapal', 0, 'gTravelPortraitPalette, bank 14'),

    # Two more slots the vote cannot call.
    ('graphics/stage/ruby', 'shop'):
        ('../main/shop.gbapal', 0, 'gShopPalette, as for the sign in the sheet'),
    ('graphics/stage/kecleon', 'kecleon'):
        ('kecleon_board_palset_0.gbapal', 2, 'board copy, not the reflection'),
    ('graphics/stage/main', 'gunk_0844AA0C'):
        ('../main/bonus_stage_obj.gbapal', 4,
         'gJirachiFx_Gfx lands in portrait slot 0, ruby OBJ bank 13'),
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

    # board_fx sits in the tile-704 overlay slot, which the board's sprite-set
    # table shares with sheets from other modes, so the vote reaches entries that
    # do not draw this art.  Every gGroudon* entry landing in 704..959 names bank
    # 12 and nothing else, so that is the sheet's palette throughout; these are
    # the segments where a foreign set outvoted it.
    # The capture cutscene shares the 704 slot with the banner sheets, which
    # outvote it below the float-up fx.  Everything from t123 on is the ball and
    # its absorb fx: gMonCatchBallAbsorbPokemonFxSpriteSet names bank 1
    # throughout, and gCaptureBallTilesGfx streams the ball itself into t102..105
    # and t123..126, drawn with gBallPalettes in bank 1.
    ('ruby', 'capture_mode', 'capture_mode_cap'):
        (14, 'past the end of the copy, matches the sheet around it'),

    ('ruby', 'capture_screen', 'capture_screen_capture_ball_slot_0'):
        (1, 'gCaptureBallTilesGfx slot, drawn with gBallPalettes'),
    ('ruby', 'capture_screen', 'capture_screen_absorb_fx_frame_0'):
        (1, 'first absorb fx frame, pairs with ball slot 0'),
    ('ruby', 'capture_screen', 'capture_screen_absorb_fx'):
        (1, 'gMonCatchBallAbsorbPokemonFxSpriteSet; a banner sheet outvoted it'),
    ('ruby', 'capture_screen', 'capture_screen_unused_tail'):
        (1, 'past the end of the copy, matches the absorb fx'),

    ('groudon', 'board_fx', 'board_fx_projectile_spawn'): (12, 'foreign set in the 704 slot outvoted bank 12'),
    ('groudon', 'board_fx', 'board_fx_projectile_impact'): (12, 'foreign set in the 704 slot outvoted bank 12'),
    ('groudon', 'board_fx', 'board_fx_projectile_debris'): (12, 'foreign set in the 704 slot outvoted bank 12'),
    ('groudon', 'board_fx', 'board_fx_projectile_split'): (12, 'foreign set in the 704 slot outvoted bank 12'),
    ('groudon', 'board_fx', 'board_fx_ball_grab_frames'): (12, 'foreign set in the 704 slot outvoted bank 12'),
    ('rayquaza', 'intro_sprite', 'intro_sprite_blank_spacer'): (12, 'blank padding tile'),
    ('rayquaza', 'sky_background', 'sky_background_orb'): (2, 'unreferenced, matches the clouds'),
    # No gRaquaza* entry reaches the wind sheet's tail; the bank 8 the vote finds
    # there belongs to another mode's sheet in the same 704 slot.
    ('rayquaza', 'wind_board', 'wind_board_unused_tail'): (12, 'unreferenced, matches the speedlines'),

    # Tiles 0..72 of every bonus board's sheet are one shared block, byte for
    # byte; the pause panel and its borders sit at t36..56 and are drawn through
    # gBonusBoardPausePanelSpriteSet in bank 9.  Spheal is the one board that
    # leaves bank 9 at zero, so the vote reports it flat.  The main field is
    # where these tiles are actually lit, and there banks 9..15 come from
    # bonus_stage_obj rather than the board's own set.
    ('spheal', 'intro_sprite', 'intro_sprite_pause_cursor'):
        (('../main/bonus_stage_obj.gbapal', 0), 'shared pause block, OBJ bank 9 on the main field'),
    ('spheal', 'intro_sprite', 'intro_sprite_pause_text'):
        (('../main/bonus_stage_obj.gbapal', 0), 'shared pause block, OBJ bank 9 on the main field'),

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

    # Padding between the Pokedex sheet's segments, and two pieces the screen
    # builds its OAM for at run time.  The silhouette shown for an unseen mon
    # sits in the portrait slot, which pokedex.c fills from
    # gMonPortraitGroupPals into OBJ bank 1.
    ('pokedex', 'sprites', 'sprites_spaceA'): (0, 'padding'),
    ('pokedex', 'sprites', 'sprites_spaceB'): (0, 'padding'),
    ('pokedex', 'sprites', 'sprites_spaceC'): (0, 'padding'),
    ('pokedex', 'sprites', 'sprites_spaceD'): (0, 'padding'),
    ('pokedex', 'sprites', 'sprites_spaceE'): (0, 'padding'),
    ('pokedex', 'sprites', 'sprites_not_seen_pic'): (1, 'portrait slot, pokedex.c'),
    ('pokedex', 'sprites', 'sprites_dex_entry_continue'): (0, 'matches the press-start prompt'),

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


def patch_object(text, field, value, palette, bank):
    """Add palette/palbank to the one object whose `field` holds `value`,
    leaving the rest of the file byte for byte alone.  json.dump would reflow
    all of it -- and normalise the CRLF several of these configs use -- which
    buries the change in a whole-file diff."""
    newline = '\r\n' if '\r\n' in text else '\n'
    marker = re.search(r'"%s"\s*:\s*"%s"' % (field, re.escape(value)), text)
    if not marker:
        raise KeyError('no %s %r in the config' % (field, value))
    start = text.rfind('{', 0, marker.start())
    depth = 0
    for end in range(start, len(text)):
        depth += {'{': 1, '}': -1}.get(text[end], 0)
        if depth == 0:
            break
    body = text[start:end]
    body = re.sub(r',\s*"pal(?:ette|bank)"\s*:\s*[^,}\r\n]+', '', body)
    indent = re.search(r'\n([ \t]*)"%s"' % field, body)
    pad = indent.group(1) if indent else '      '
    gap = ' ' if re.search(r'"%s":\s' % field, body) else ''
    added = ',{nl}{pad}"palette":{gap}{palette},{nl}{pad}"palbank":{gap}{bank}{nl}{close}'.format(
        nl=newline, pad=pad, gap=gap, palette=json.dumps(palette), bank=bank,
        close=pad[:-2])
    return text[:start] + body.rstrip() + added + text[end:]


def segment_ranges(directory, entry, base=0):
    """-> [(segfile, first_tile, tile_count)] for one gfx.json file entry.

    Tile counts come from the built per-segment .4bpp when it is there: -oam and
    -oamshape segments are not width*height/64 tiles, and using the PNG size for
    those drifts every later offset (13 tiles over, on ruby's sheet)."""
    ranges = []
    offset = base
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


def board_labels(board, tables):
    """Sprite-set labels a board or screen draws with.  The Pokedex sheet is
    also what the e-reader screen puts in OBJ VRAM, so some of its segments are
    only ever named by that screen's table."""
    names = BOARDS[board]['table']
    if isinstance(names, str):
        names = (names,)
    return [label for name in names for label in tables.get(name, [])]


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


def derive_banks(board, directory, entry, oam, tables, base=0):
    """-> [(segfile, first_tile, count, bank, source)], bank None when unknown."""
    ranges = segment_ranges(directory, entry, base)
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
    table = board_labels(board, tables)
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

def derive_slot(board, first, count, oam, tables):
    """-> (bank, source) for a streamed sheet occupying [first, first + count).

    Entries wholly inside the slot answer it directly.  Where there are none the
    slot is a piece of a larger sprite -- the charge indicator streams four
    tiles into the middle of an eight-tile one -- so an entry that covers the
    whole slot answers instead."""
    flat = flat_banks(board)
    slot = set(range(first, first + count))
    for inside in (True, False):
        tiles = collections.defaultdict(set)
        owners = collections.defaultdict(set)
        for label in board_labels(board, tables):
            for tile, bank, span in oam.get(label, ()):
                covered = set(range(tile, tile + span))
                if bank in flat:
                    continue
                if covered <= slot if inside else slot <= covered:
                    tiles[bank] |= covered & slot
                    owners[bank].add(label)
        if not tiles:
            continue
        best = max(len(v) for v in tiles.values())
        winners = [b for b, v in tiles.items() if len(v) == best]
        if len(winners) > 1:
            return None, 'slot is drawn through banks %s' % sorted(winners)
        return winners[0], 'slot %s %d/%d tiles %s' % (
            'holds' if inside else 'inside', best, count, sorted(owners[winners[0]])[0])
    return None, 'no OAM entry lies inside or over the slot'


def configs():
    """Every gfx config this tool has something to say about, dir -> path."""
    paths = {}
    for board in BOARDS:
        paths[BOARDS[board]['dir']] = os.path.join(BOARDS[board]['dir'],
                                                   BOARDS[board]['gfx'])
    for directory, _ in list(SLOTS) + list(SLOT_PALETTES):
        if directory in paths:
            continue
        for candidate in sorted(glob.glob(os.path.join(directory, '*.json'))):
            try:
                config = json.load(open(candidate))
            except ValueError:
                continue        # oamshape files sit alongside and are gbagfx's
            if config.get('kind') == 'gfx-config':
                paths[directory] = candidate
                break
    return paths


def append_object(text, gfx_filename, palette, bank):
    """Add a files entry that carries nothing but the palette.

    Sheets built by the Makefile's plain %.4bpp: %.png rule need no config
    entry, so several streamed ones have none.  An entry with no mwidth,
    mheight, oam or align makes generate_graphics_rules.sh emit nothing, so
    this records the palette without touching the build."""
    newline = '\r\n' if '\r\n' in text else '\n'
    files = re.search(r'"files"\s*:\s*\[', text)
    if not files:
        raise KeyError('no files array in the config')
    depth = 0
    for end in range(files.end() - 1, len(text)):
        depth += {'[': 1, ']': -1}.get(text[end], 0)
        if depth == 0:
            break
    last = text.rfind('}', 0, end)
    sample = re.search(r'\n([ \t]*)"gfx_filename"', text)
    pad = sample.group(1) if sample else '    '
    gap = ' ' if re.search(r'"gfx_filename":\s', text) else ''
    entry = ('{nl}{outer}{{{nl}{pad}"gfx_filename":{gap}{name},{nl}'
             '{pad}"palette":{gap}{palette},{nl}{pad}"palbank":{gap}{bank}{nl}{outer}}}').format(
        nl=newline, outer=pad[:-2], pad=pad, gap=gap,
        name=json.dumps(gfx_filename), palette=json.dumps(palette), bank=bank)
    return text[:last + 1] + ',' + entry + text[last + 1:]


def relative(where, board, directory):
    """Rewrite a board-relative palette path to be relative to `directory`.

    A config can sit somewhere other than the board whose palette its sheets
    are drawn with -- graphics/stage/gfx.json holds a sapphire sheet -- and the
    path in the config has to resolve from beside the config."""
    if where is None:
        return None
    palette, index = where
    if directory == BOARDS[board]['dir']:
        return palette, index
    full = os.path.normpath(os.path.join(BOARDS[board]['dir'], palette))
    return os.path.relpath(full, directory), index


def wants(args, directory, gfx_filename):
    return ((not args.dirs or directory in args.dirs)
            and (not args.name or gfx_filename == args.name))


def cmd_derive(args):
    oam, tables = read_oam_data(args.rom_source)
    unresolved = 0
    for directory, path in sorted(configs().items()):
        config = json.load(open(path))
        text = open(path, newline='').read()
        changed = False
        header = False
        for entry in config['files']:
            name = entry['gfx_filename']
            if not wants(args, directory, name):
                continue
            rows = []
            if (directory, name) in SLOT_PALETTES:
                # A whole-sheet answer, so it also settles every segment of a
                # segmented sheet -- the segments share one slot and one palette.
                palette, index, why = SLOT_PALETTES[(directory, name)]
                rows.append(('gfx_filename', name, -1, 0, '--', (palette, index), why))
            elif entry.get('segments'):
                if (directory, name) in SLOTS:
                    board, base = SLOTS[(directory, name)][:2]
                else:
                    board = next((b for b in BOARDS if BOARDS[b]['dir'] == directory), None)
                    base = 0
                if board is None:
                    continue
                banks = obj_palette(board)
                for seg, start, count, bank, source in derive_banks(board, directory, entry, oam, tables, base):
                    where = banks[bank] if isinstance(bank, int) else bank
                    rows.append(('segfile', seg, start, count, bank,
                                 relative(where, board, directory), source))
            elif (directory, name) in SLOTS:
                board, first, count, note = SLOTS[(directory, name)]
                bank, source = derive_slot(board, first, count, oam, tables)
                where = relative(obj_palette(board)[bank], board, directory) \
                    if bank is not None else None
                rows.append(('gfx_filename', name, first, count, bank, where,
                             '%s; %s' % (source, note)))
            for field, key, start, count, bank, where, source in rows:
                if not header:
                    print('== %s' % path)
                    header = True
                if where is None:
                    unresolved += 1
                    print('   ??  %-38s t%-4d n%-3d  %s' % (key, start, count, source))
                    continue
                palette, index = where
                print('   %-4s%-38s t%-4d n%-3d  %-34s %s#%d'
                      % (bank if isinstance(bank, int) else '--',
                         key, start, count, source[:34], palette, index))
                target = entry if field == 'gfx_filename' else \
                    next(s for s in entry['segments'] if s['segfile'] == key)
                if (target.get('palette'), target.get('palbank')) != (palette, index):
                    text = patch_object(text, field, key, palette, index)
                    changed = True
        for key in sorted(set(SLOTS) | set(SLOT_PALETTES)):
            if key[0] != directory or not wants(args, *key):
                continue
            if any(f['gfx_filename'] == key[1] for f in config['files']):
                continue
            if key in SLOT_PALETTES:
                palette, index, source = SLOT_PALETTES[key]
            else:
                board, first, count, note = SLOTS[key]
                bank, source = derive_slot(board, first, count, oam, tables)
                if bank is None:
                    unresolved += 1
                    print('   ??  %-38s t%-4d n%-3d  %s' % (key[1], first, count, source))
                    continue
                palette, index = relative(obj_palette(board)[bank], board, directory)
            if not header:
                print('== %s' % path)
                header = True
            print('   new %-38s %-34s %s#%d' % (key[1], source[:34], palette, index))
            text = append_object(text, key[1], palette, index)
            changed = True
        if changed and args.write:
            open(path, 'w', newline='').write(text)
            print('   written')
    if unresolved:
        print('\n%d sheet(s) unresolved -- add them to OVERRIDES or SLOT_PALETTES'
              % unresolved)
    return 1 if unresolved else 0


def coloured_targets(args):
    """-> [(png, palette path, bank)] for everything a config gives a palette.

    The evolution pickups share one appear-and-sparkle animation between nine
    sheets that each colour it differently, and a PNG can only carry one
    palette, so a segment reached more than once keeps the first sheet's."""
    out = []
    seen = set()
    for directory, path in sorted(configs().items()):
        for entry in json.load(open(path))['files']:
            name = entry['gfx_filename']
            if not wants(args, directory, name):
                continue
            holders = [(name, entry)] + [(s['segfile'], s) for s in entry.get('segments', [])]
            for stem, holder in holders:
                palette = holder.get('palette') or entry.get('palette')
                if not palette:
                    continue
                bank = holder.get('palbank', entry.get('palbank', 0))
                png = os.path.join(directory, stem + '.png')
                if os.path.exists(png) and png not in seen:
                    seen.add(png)
                    out.append((png, os.path.join(directory, palette), bank))
    return out


def cmd_apply(args):
    for png, palette, bank in coloured_targets(args):
        colours = read_gbapal(palette)[bank * 16:bank * 16 + 16]
        if png_palette(png) == colours:
            continue
        if args.dry_run:
            print('would recolour %s' % png)
            continue
        width, height, rows, greyscale = png_read_indices(png)
        if greyscale:
            rows = [[15 - value for value in row] for row in rows]
        png_write_indexed(png, width, height, rows, colours)
        print('recoloured %s' % png)
    return 0


def cmd_check(args):
    bad = 0
    for png, palette, bank in coloured_targets(args):
        if png_palette(png) != read_gbapal(palette)[bank * 16:bank * 16 + 16]:
            print('palette does not match %s#%d: %s'
                  % (os.path.basename(palette), bank, png))
            bad += 1
    print('%d mismatch(es)' % bad)
    return 1 if bad else 0


def main():
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--board', default='all',
                        help='board name, or "all" (default) for every config '
                             'this tool knows about, boards and shared sheets alike')
    parser.add_argument('--name', default='',
                        help='a single gfx_filename to work on (default: all of them)')
    sub = parser.add_subparsers(dest='command', required=True)

    p = sub.add_parser('derive', help='work out each sheet\'s palette bank')
    p.add_argument('--rom-source', default=ROM_SOURCE)
    p.add_argument('--write', action='store_true',
                   help='record the result in the gfx config')
    p.set_defaults(func=cmd_derive)

    p = sub.add_parser('apply', help='recolour PNGs from the gfx configs')
    p.add_argument('--dry-run', action='store_true')
    p.set_defaults(func=cmd_apply)

    p = sub.add_parser('check', help='verify PNG palettes against the gfx configs')
    p.set_defaults(func=cmd_check)

    args = parser.parse_args()
    if args.board == 'all':
        args.dirs = None
    elif args.board in BOARDS:
        args.dirs = {BOARDS[args.board]['dir']}
    else:
        parser.error('unknown board %r; expected one of %s, or "all"'
                     % (args.board, ', '.join(BOARDS)))
    return args.func(args)


if __name__ == '__main__':
    sys.exit(main())
