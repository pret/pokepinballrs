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
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0][0], OBJ_PLTT_SLOT(0), PLTT_SLOT_SIZE);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0][2], OBJ_PLTT_SLOT(2), 6*PLTT_SLOT_SIZE);
    }
    else
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0][2], OBJ_PLTT_SLOT(2), 7*PLTT_SLOT_SIZE);
    }

    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0][10], OBJ_PLTT_SLOT(10), PLTT_SLOT_SIZE);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->cameraYViewport < 170)
    {
        DmaCopy16(3, gFieldVariant_Pals[gMain.selectedField][arg0 * 2], OBJ_PLTT_SLOT(11), PLTT_SLOT_SIZE);
    }
    else
    {
        DmaCopy16(3, gFieldVariant_Pals[gMain.selectedField][arg0 * 2 + 1], OBJ_PLTT_SLOT(11), PLTT_SLOT_SIZE);
    }
}
