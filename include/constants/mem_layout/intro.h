#ifndef GUARD_CONSTANTS_MEM_LAYOUT_INTRO
#define GUARD_CONSTANTS_MEM_LAYOUT_INTRO

#include "constants/mem_layout/shared.h"

// NOTE: Idle section is inside the area defined for the HUD tilemap space

//Idle board (Demo)
#define BG_VRAM_ADDR_IDLE_PRESS_START_TILEMAP    BG_TILE_ADDR(TILE_INDEX(0, 9, 20))
// Size 2 "tiles"
#define BG_VRAM_ADDR_IDLE_TBD_TILEMAP            BG_TILE_ADDR(TILE_INDEX(0, 9, 18))
// Size 2 "tiles"


#endif