# Main-field board BG VRAM layout

How the scrolling pinball board is assembled in VRAM. Worked out for FIELD_RUBY;
the other main fields use the same shape with their own assets.

Without this, the board tile sheets cannot be read as pictures: the tilemaps
index a window that is streamed at runtime, so any static interpretation of
char base 2 produces a recognisable-but-corrupted board.

## BG configuration

From `SetupDisplayRegistersForField` (`src/all_board_pinball_game_main.c:178`),
FIELD_RUBY. Screen base N is `VRAM + N*0x800`, char base N is `VRAM + N*0x4000`.

| BG  | screen base | char base | size  | priority | tilemap source                            |
|-----|-------------|-----------|-------|----------|-------------------------------------------|
| BG0 | 4           | 1         | 32x64 | 0        | built at runtime in `gBG0TilemapBuffer`   |
| BG1 | 6           | 2         | 32x64 | 1        | `gRubyBoardBGTilemap`                     |
| BG2 | 2           | 1         | 32x64 | 2        | `gRubyBoardBG1Tilemap` (ramp)             |
| BG3 | 0           | 2         | 32x64 | 3        | `gRubyBoardBG0Tilemap`                    |

Note the labels do not match the layers: `gRubyBoardBG0Tilemap` is DMA'd to
screen base 0, which is **BG3**, and `gRubyBoardBG1Tilemap` to screen base 2,
which is **BG2**.

## Char base 1 (BG0, BG2)

`loadFieldBoardGraphics` decompresses `gRubyBoardCompressedTiles1` (the bgramp
sheet) and copies its first 0x4000 bytes -- 512 tiles -- over the whole
charblock. BG2's tilemap only reaches id 223, well inside that.

## Char base 2 (BG1, BG3) -- the part that matters

Two regions with completely different lifetimes:

    tiles 0-703     streamed ring window, rewritten as the board scrolls
    tiles 704-1023  gRubyBoardBGTiles, static overlay (rails, ramps, SHOP sign)

`loadFieldBoardGraphics` appears to place bgtop into tiles 0-703 with two
DmaCopy16 calls, but those are immediately superseded: the caller in
`src/save_and_restore_game.c:213` runs a streaming loop afterwards.

### The ring

    for (i = 0; i < 22; i++) {
        var0 = i + scroll;
        var1 = (i + 10 + scroll) % 22;
        src  = var0 < 32 ? &gBoardGfxBuffer[var0 * 0x400]          // bgtop
                         : &gBoardBGTileBufferAlt[(var0-32) * 0x400]; // bgbottom
        DmaCopy16(3, src, (void *)0x6008000 + var1 * 0x400, 0x400);
    }

A chunk is `0x400` bytes = 32 tiles = exactly one row of the 32-tile-wide board.
The source is a virtual 64-chunk strip: bgtop supplies chunks 0-31, bgbottom
chunks 32-63. 22 of those 64 rows are resident at a time.

Substituting `i = C - scroll` for chunk `C` gives slot `(C + 10) % 22`: **a chunk
always lands in the same slot regardless of scroll position.** That invariant is
what makes the sheets statically reconstructible.

## Reconstructing the board

Because chunk == tilemap row, BG3's tilemap row `R` always draws chunk `R`:

    tile pixels for (row R, column c)
        = (bgtop ++ bgbottom)[ R*32 + (tilemap_id % 32) ]

with the entry's own flip bits and palette bank applied as usual.

Verified against `ruby_board_bg0_tilemap.bin`: 57 of 64 rows have every tile id
inside slot `(R+10) % 22` exactly as predicted. The 7 exceptions are rows 56-63,
which are filler -- every entry is 0. So the board proper is rows 0-55, i.e.
256x448 pixels.

## Palette

`loadFieldBoardGraphics` copies `BG_PLTT_SIZE` (0x200) from `gRubyBoardPalette`,
which is only 0x180 long, so banks 12-15 come from whatever follows it in ROM.
The tilemaps do use bank 13, so a faithful render needs the full 0x200 read.

## Which boards this applies to

The streaming loop is gated on `gMain.selectedField < MAIN_FIELD_COUNT`, and
`MAIN_FIELD_COUNT` is 2 (`include/constants/fields.h:6`). So **only Ruby and
Sapphire scroll**, and they share an identical BG configuration -- the model
above transfers to Sapphire unchanged.

The six bonus boards are static: no ring, no scroll, char base 2 is simply what
`loadFieldBoardGraphics` leaves there. Dusclops is representative:

    LZ77UnCompWram(gBonusFieldCompressedBaseTiles, gBoardGfxBuffer);
    DmaCopy16(3, gBoardGfxBuffer, (void *)0x06004000, 0x4000);   // char base 1, shared
    LZ77UnCompWram(gDusclopsBoardCompressedBGTiles, gBoardGfxBuffer);
    DmaCopy16(3, gBoardGfxBuffer, (void *)0x06008000, 0x8000);   // char base 2, 1024 tiles
    DmaCopy16(3, gDusclopsBoardBG0Tilemap, (void *)0x06000000, 0x800);  // BG3
    DmaCopy16(3, gDusclopsBoardBG1Tilemap, (void *)0x06000800, 0x800);  // BG2
    DmaCopy16(3, gDusclopsBoardBG2Tilemap, (void *)0x06001000, 0x800);  // BG1

All three of its BG layers read char base 2, and each tilemap is a plain 32x32
screen, so those boards fold with `detilemap` directly -- no ring reconstruction.
Note char base 1 holds `gBonusFieldCompressedBaseTiles`, which is shared by every
bonus board.

Per-field BG configuration (screen base / char base / size):

| field    | BG0        | BG1        | BG2        | BG3        |
|----------|------------|------------|------------|------------|
| RUBY     | 4/1 32x64  | 6/2 32x64  | 2/1 32x64  | 0/2 32x64  |
| SAPPHIRE | 4/1 32x64  | 6/2 32x64  | 2/1 32x64  | 0/2 32x64  |
| DUSCLOPS | 4/1 32x64  | 2/2 32x32  | 1/2 32x32  | 0/2 32x32  |
| KECLEON  | 4/1 32x64  | 2/2 32x32  | 1/2 32x32  | 0/2 32x32  |
| KYOGRE   | 4/1 32x64  | --         | 1/2 32x32  | 0/2 32x32  |
| GROUDON  | 4/1 32x64  | --         | 1/2 32x32  | 0/2 32x32  |
| RAYQUAZA | 4/1 32x64  | 6/2 32x64  | 2/2 32x64  | 0/2 32x64  |
| SPHEAL   | 4/1 32x64  | 2/2 32x64  | 1/2 32x32  | 0/2 32x32  |

## OBJ tiles and the OBJ palette

`loadFieldBoardGraphics` ends every field with one 0x8000 DMA of the board's
`intro_sprite` sheet to 0x06010000, so OAM tile number 0 is tile 0 of that
sheet and the tile ranges quoted in the sprite-set data index it directly.
The sheets are shorter than the 1024 tiles the region holds; the tail is left
over from whatever ran before.

Much of the region is scratch, streamed over frame by frame from a table of
interchangeable art. The art checked in at those offsets is only what the sheet
happens to ship with, and its palette arrives with the replacement tiles rather
than sitting in the board's own set:

| tiles | written by | palette |
|-------|------------|---------|
| 0x65  | `all_board_portrait_display.c` (portrait slot 0) | into the bank `gPortraitPaletteSlots[0]` names, 13 |
| 0x7d  | `all_board_portrait_display.c` (portrait slot 1) | `gLocationPalettes[n]`, into bank 12 |
| 0x95  | `main_board_pichu_entity.c`, `gMonHatchSpriteGroup5_Gfx` | mon hatch group palette |
| 0xb6  | `main_board_evolution_mode.c`, `gEvoItemTilesGfxPtrs[n]` | `gEvoItemPalettes[n]`, into bank 15 |
| 0x107 | `main_board_launcher_and_cutscenes.c`, `gSpoinkEntity_Gfx` | bank 11, see below |
| 0x115 | `main_board_to_be_split.c`, `gRubyBoardHatchCave_Gfx` | bank 11, see below |
| 0x1e8 | `UpdateRubyEvolutionShopSprite`, `gRubyBoardShop_Gfx` | `gShopPalette`, into bank 2 |
| 0x295 | `DrawOneUpBannerSprite`, `gOneUpBannerSprite_Gfx` | `gOneUpSpritePalette`, into bank 12 |

Which entry of each table the sheet ships is recoverable by searching the ROM
for the segment's own tiles: tile 0x7d is `gLocationPortraitGfx[0]` and tile
0x95 is `wurmple_hatch` frame 0, both byte-identical, and tile 0xb6 is
`gPickupIcon1_Gfx`. Tile 0x65 is a Geodude portrait close to but not identical
to the extracted one.

OBJ bank 11 is never its resting ROM value on the main fields: `UpdateSpoinkAnimation`
runs every frame and rewrites it from `gFieldPaletteVariants[field][set * 2 + (camera is low)]`,
six banks per field -- three brightness sets crossed with which half of the
board is on screen. Set 0 is what plays, so the upper half of the board is
variant 0 (ruby) / 6 (sapphire) and the lower half 1 / 7. Spoink is the plunger
at the bottom; the egg, hatch cave and hatch machine sit at the top. Ruby's
resting value for the bank happens to equal its own upper-half variant.

The OBJ palette itself is one 512-byte DMA:

    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], (void *)OBJ_PLTT, OBJ_PLTT_SIZE);

`objPaletteSets[1]` and `[2]` are the same palette at two dimmer levels, used
by the banner fades in `all_board_banners.c`; set 0 is the one on screen during
play. Every board's set 0 is a full 512 bytes except ruby's, which is 0x120 --
the DMA runs on past it into `gBonusStageObjPal`, so ruby's OBJ banks 0-8 come
from `ruby_board_palset_0.gbapal` and banks 9-15 from
`graphics/stage/main/bonus_stage_obj.gbapal`. The bonus boards copy that same
label's first bank to 0x05000320, which is OBJ bank 9 there too.

Sapphire leaves banks 12-15 at zero and loads them when the sprites that use
them appear; ruby, by the overlap above, keeps a usable copy in ROM.

`tools/scripts/objpalette.py` derives which bank each segment of a sheet is
drawn with from the OAM data in `data/rom_2.s`, records it in the gfx config as
`"palette"`/`"palbank"`, and recolours the segment PNGs to match.
