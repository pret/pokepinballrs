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
        group = &gMain.spriteGroups[81];
    else
        group = &gMain.spriteGroups[85];

    if (group->available)
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
    if (gCurrentPinballGame->paletteSwapActive == 1)
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0], (void*)OBJ_PLTT, 0x20);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xC0);
    }
    else
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xE0);
    }

    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[arg0] + 0x140, (void *)OBJ_PLTT + 0x140, 0x20);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->cameraYViewport < 170)
    {
        DmaCopy16(3, gFieldPaletteVariants[gMain.selectedField][arg0 * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gFieldPaletteVariants[gMain.selectedField][arg0 * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }
}
