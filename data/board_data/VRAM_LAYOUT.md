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
