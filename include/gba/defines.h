#ifndef GUARD_GBA_DEFINES
#define GUARD_GBA_DEFINES

#define TRUE  1
#define FALSE 0

// Note: IWRAM, EWRAM, SOUND_INFO_PTR, INTR_CHECK and INTR_VECTOR have been split to
// a separate file, allowing reuse of these defines from the rom_.s data files.

#define EWRAM_START 0x02000000
#define EWRAM_END   (EWRAM_START + 0x40000)
#define IWRAM_START 0x03000000
#define IWRAM_END   (IWRAM_START + 0x8000)

#define PLTT      0x5000000
#define PLTT_SIZE 0x400

#define BG_PLTT      PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT      (PLTT + 0x200)
#define OBJ_PLTT_SIZE 0x200

#define VRAM      0x6000000
#define VRAM_SIZE 0x18000

#define BG_VRAM           VRAM
#define BG_VRAM_SIZE      0x10000

// Naming note (historical naming due to using a technique originally for text)
// "Character" Data: The raw pixel maps of your 8 × 8 tiles.
// "Character" Block: The container in VRAM holding a set of these tiles.
#define BG_CHAR_SIZE      0x4000
#define BG_SCREEN_SIZE    0x800  // Char block is 8 screens

#define BG_TILE_H_FLIP(n) (0x400 + (n))
#define BG_TILE_V_FLIP(n) (0x800 + (n))

// text-mode BG
#define OBJ_VRAM0      (VRAM + 0x10000)
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1      (VRAM + 0x14000)
#define OBJ_VRAM1_SIZE 0x4000

#define OAM      0x7000000
#define OAM_SIZE 0x400

#define ROM_HEADER_SIZE   0xC0

#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 160

#define TILE_SIZE_4BPP 0x20

#define TILE_OFFSET_4BPP(n) ((n) * TILE_SIZE_4BPP)

#define TOTAL_OBJ_TILE_COUNT 1024

#define WIN_RANGE(a, b) (((a) << 8) | (b))



#define PLTT_SLOT_SIZE 0x20
#define PALETTES_PER_BANK 16 // One bank for BG palettes, one for Obj palettes
#define COLORS_PER_PALETTE 16

#define BG_PLTT_SLOT(n)  (BG_PLTT  + (n) * PLTT_SLOT_SIZE)
#define OBJ_PLTT_SLOT(n) (OBJ_PLTT + (n) * PLTT_SLOT_SIZE)

#define TILES_SIZE_4BPP(n) ((n) * TILE_SIZE_4BPP)

#define BG_TILE_ADDR(n)  (BG_VRAM  + TILE_OFFSET_4BPP(n))
#define OBJ_TILE_ADDR(n) (OBJ_VRAM0 + TILE_OFFSET_4BPP(n))

#define TILE_WIDTH  8
#define TILE_HEIGHT 8

#define TILES_PER_CHARBLOCK_ROW 32
#define TILES_PER_CHARBLOCK (BG_CHAR_SIZE / TILE_SIZE_4BPP)

#define TILE_INDEX(charBlock, y, x)  (((charBlock) * TILES_PER_CHARBLOCK) +  ((y) * TILES_PER_CHARBLOCK_ROW) + (x))

/*
The main board graphics for the pinball board are loaded into the BG section of VRAM, starting at
char block 2, and extending 6 rows into BG_VRAM char block 3.

From there, a tilemap pulls them onto the board, and gives them the correct palette on BG layer 3.
The tilemap covers the whole board, but is pulling it from a memory space that gets reused. (section wrapping)
One consequence of this is that a piece intended for one segment of the board will also appear on the output
BG layer 3 in other spots, possibly with the wrong palette. (Outside the area the camera is showing)

Board wrapping starts with the top of the board offset a few rows, as part of the scroll wrapping strategy.
*/

// Note: this is mostly normalized, based on manual calculations from the top
// loadFieldBoardGraphics suggests that the top of sapphire might be 1 line earlier, ruby 2 lines later
#define BOARD_ROW_OFFSET 11
#define BOARD_ROW_COUNT 22

#define WRAP_ROW(y) (((y) + BOARD_ROW_OFFSET) % BOARD_ROW_COUNT)

#define BG_ADDR_FOR_BOARD_WRAP(y, x)  BG_TILE_ADDR(TILE_INDEX(2, WRAP_ROW(y), (x)))

#endif // GUARD_GBA_DEFINES
