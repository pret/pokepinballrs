#include "global.h"
#include "main.h"
#include "gba/gba.h"
#include "m4a.h"
#include "constants/fields.h"
#include "constants/bg_music.h"

extern const u8 gRubyStageCyndaquil_Gfx[][0x280];

void DrawBoardEdgeBanner(void)
{
    s16 i;
    struct SpriteGroup *group;

    if (gMain.selectedField == FIELD_RUBY)
        group = &gMain.spriteGroups[SG_RUBY_BOARD_RIGHT_EDGE];
    else
        group = &gMain.spriteGroups[SG_SAPPHIRE_BOARD_RIGHT_EDGE];

    if (group->active)
    {
        if (gCurrentPinballGame->cameraBaseX < 8)
        {
            group->baseX = gCurrentPinballGame->cameraXOffset;
            group->baseX = -8 - group->baseX;
        }
        else
        {
            group->baseX = gCurrentPinballGame->cameraXOffset;
            group->baseX = 256 - group->baseX;
        }

        group->baseY = 0;
        for (i = 0; i < 5; i++)
        {
            struct OamDataSimple *oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + i * 0x20;
        }
    }
}

/**
 * Executed when saving or loading from a main field
 * arg0
 *   0 when saving and loading normally
 *   2 when loading into the evo or mart menu
 */
void RestoreBoardObjPalettes(s16 arg0)
{
    if (gCurrentPinballGame->paletteSwapActive == TRUE)
    {
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[arg0][PAL_IX_DIMMING_BASE_0],
            OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_0),
            PLTT_SLOT_SIZE);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[arg0][PAL_IX_DIMMING_BASE_2],
            OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_2),
            LIGHTING_BASE_2_SAPPHIRE_COUNT * PLTT_SLOT_SIZE);
    }
    else
    {
        DmaCopy16(3,
            gBoardConfig.fieldLayout.objPaletteSets[arg0][PAL_IX_DIMMING_BASE_2],
            OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_2),
            LIGHTING_BASE_2_RUBY_COUNT * PLTT_SLOT_SIZE);
    }

    DmaCopy16(3,
        gBoardConfig.fieldLayout.objPaletteSets[arg0][PAL_IX_DIMMING_BASE_10],
        OBJ_PLTT_SLOT(PAL_IX_DIMMING_BASE_10),
        PLTT_SLOT_SIZE);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->cameraYViewport < 170)
    {
        DmaCopy16(3, gFieldVariant_Pals[gMain.selectedField][arg0 * 2], OBJ_PLTT_SLOT(PAL_IX_HATCH_EGG), PLTT_SLOT_SIZE);
    }
    else
    {
        DmaCopy16(3, gFieldVariant_Pals[gMain.selectedField][arg0 * 2 + 1], OBJ_PLTT_SLOT(PAL_IX_SPOINK), PLTT_SLOT_SIZE);
    }
}
