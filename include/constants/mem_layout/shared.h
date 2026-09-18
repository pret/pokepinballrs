#ifndef GUARD_CONSTANTS_MEM_LAYOUT_SHARED
#define GUARD_CONSTANTS_MEM_LAYOUT_SHARED

#include "gba/defines.h"

// 32 OUTPUT tiles (one screen width) are mapped by 0x40 bytes of data
// From a tile index perspective, 2 "tiles" of data = mapping for 1 board row.
#define MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW 0x40

#define MEM_SIZE_OF_TILE_ROW                32 * TILE_SIZE_4BPP

// From tile_Index perspective, 4 'rows' of data, mapping a 256*512 output
#define MEM_SIZE_OF_TILEMAP_256_BY_512   MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW * 64
// From tile_Index perspective, 2 'rows' of data, mapping a 256*256 output
#define MEM_SIZE_OF_TILEMAP_256_BY_256   MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW * 32


//Hud: all boards

#define BG_VRAM_ADDR_ALL_BOARDS_LAYER_0_TILEMAP   BG_TILE_ADDR(TILE_INDEX(0,8,0))
// Size 4 "rows of tiles" of tilemap data

#define BG_VRAM_ADDR_ALL_BOARDS_DEBUG_TILEMAP     BG_TILE_ADDR(TILE_INDEX(0,8,0))
// Size 2 "rows of tiles" of tilemap data

#define BG_VRAM_ADDR_WAS_CAUGHT_BACKDROP_TILEMAP   BG_TILE_ADDR(TILE_INDEX(0,8,0))
#define SIZE_OF_VRAM_WAS_CAUGHT_BACKDROP_TILEMAP   32 * MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW


#define BG_VRAM_ADDR_TIMER_TILEMAP_DATA   BG_TILE_ADDR(TILE_INDEX(0, 8, 22))
//4 "tiles" of tilemap data
#define SIZE_OF_VRAM_TIMER_TILEMAP_DATA   2 * MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW 

#define BG_VRAM_ADDR_HUD_TILEMAP_DATA     BG_TILE_ADDR(TILE_INDEX(0, 11, 28))
//4 "tiles" of tilemap data
#define SIZE_OF_VRAM_HUD_TILEMAP_DATA     2 * MEM_SIZE_OF_TILEMAP_FOR_32_TILE_ROW


// Tiles - Each 0x20 of space is a single 8x8 tile.

#define BG_VRAM_ADDR_HUD_TILES_A         BG_TILE_ADDR(TILE_INDEX(1, 10, 0))
#define SIZE_OF_VRAM_HUD_TILES_A         MEM_SIZE_OF_TILE_ROW
#define BG_VRAM_ADDR_HUD_TILES_B         BG_TILE_ADDR(TILE_INDEX(1, 11, 0))
#define SIZE_OF_VRAM_HUD_TILES_B         2 * MEM_SIZE_OF_TILE_ROW

#endif