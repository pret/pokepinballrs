#ifndef GUARD_INLINE_LOAD_LIGHTING_PAL_H
#define GUARD_INLINE_LOAD_LIGHTING_PAL_H

#include "global.h"
#include "main.h"

/* Loads board palettes for dimming, such as with a banner display
   Dims slots 2-7, 10-12, and 8 on ruby board. (8 used for the shop sign on sapphire, which uses its own pal loading)
   Slot 0 is also dimmed, but in different spots in code

   Dimming levels are 0 (normal), 1 (dimming), and 2 (dim)*/
static inline void LoadObjLightingPalette(u16 dimmingIx)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[dimmingIx][PAL_IX_DIMMING_BASE_2],
            OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_2),
            LIGHTING_BASE_2_SAPPHIRE_COUNT * PLTT_SLOT_SIZE);
    }
    else
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[dimmingIx][PAL_IX_DIMMING_BASE_2],
            OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_2),
            LIGHTING_BASE_2_RUBY_COUNT * PLTT_SLOT_SIZE);

    DmaCopy16(3,
        gBoardConfig.fieldLayout.objPaletteSets[dimmingIx][PAL_IX_DIMMING_BASE_10],
        OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_10),
        LIGHTING_BASE_10_COUNT * PLTT_SLOT_SIZE);
    gCurrentPinballGame->paletteDimmingIx = dimmingIx;
}

/* Loads board palettes for dimming, such as with a banner display
   Handles Slot 0. (other slots dimmed with separate function, different blocks of code)

   Dimming levels are 0 (normal), 1 (dimming), and 2 (dim)*/
static inline void LoadObjLightingPalette_0(u16 dimmingIx){
    DmaCopy16(3,
        gBoardConfig.fieldLayout.objPaletteSets[dimmingIx][PAL_IX_DIMMING_BASE_0],
        OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_0),
        PLTT_SLOT_SIZE);
}

#endif