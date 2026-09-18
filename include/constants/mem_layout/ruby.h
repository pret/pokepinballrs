#ifndef GUARD_CONSTANTS_MEM_LAYOUT_RUBY
#define GUARD_CONSTANTS_MEM_LAYOUT_RUBY

#include "constants/mem_layout/shared.h"


#define BG_VRAM_ADDR_RUBY_LAYER_3_TILEMAP   BG_TILE_ADDR(TILE_INDEX(0,0,0))
#define BG_VRAM_ADDR_RUBY_LAYER_2_TILEMAP   BG_TILE_ADDR(TILE_INDEX(0,4,0))
// Tile_Index(0,8,0) - Tile(0,11,31) shared, for BG0 hud layer/debug

#define BG_VRAM_ADDR_RUBY_LAYER_1_TILEMAP   BG_TILE_ADDR(TILE_INDEX(0,12,0))





// Tiles

// BG TILE_INDEX(1, 10, 0) - BG TILE_INDEX(1, 12, 31) shared for hud

#endif