#include "global.h"
#include "main.h"
#include "gba/gba.h"
#include "m4a.h"
#include "constants/fields.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_0845A08C[][0x100];
extern const s16 gUnknown_086AE5A0[][2];
extern const s16 gUnknown_086AE58A[][2];
extern const s16 gUnknown_086AE588[][2];
extern const u8 gUnknown_08490A4C[][0x440];
extern struct Vector16 gUnknown_086AE554[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gUnknown_081BC984[][0x20];
extern const u8 gUnknown_0848108C[][0x480];

void DrawSapphireTrapDoorSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[69];
    if (group->available)
    {
        group->baseX = 16 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 115 - gCurrentPinballGame->bgScrollYWithOffset;
        index = gCurrentPinballGame->pondPaletteVariant + gCurrentPinballGame->paletteCycleIndex * 3;
        DmaCopy16(3, gUnknown_081BC984[index], (void *)0x05000300, 0x20);
        DmaCopy16(3, gUnknown_0848108C[gCurrentPinballGame->pondSpriteFrame], (void *) 0x06014B20, 0x480);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void UpdateCyndaquilEruptionStateMachine(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    switch (gCurrentPinballGame->cyndaquilAnimPhase)
    {
    case 0:
        if (gCurrentPinballGame->cyndaquilHitPending)
        {
            if (gCurrentPinballGame->boardState < 3)
            {
                if (gCurrentPinballGame->cyndaquilAnimFrame < 3)
                {
                    gCurrentPinballGame->cyndaquilAnimFrame++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
                else
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->scrollDelayFrames = 0;
                    gCurrentPinballGame->scrollHoldFrames = 920;
                    gCurrentPinballGame->scrollTargetBottomY = 0;
                    gCurrentPinballGame->fieldScrollOffsetY = 0;
                    gCurrentPinballGame->fieldScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxVariant = 0;
                    gCurrentPinballGame->scrollOverrideActive = 1;
                    gCurrentPinballGame->scrollFromBottom = 0;
                    gCurrentPinballGame->cyndaquilAnimPhase = 1;
                    gCurrentPinballGame->cyndaquilSubframeTimer = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    gCurrentPinballGame->scoreAddedInFrame = 200000;
                    m4aSongNumStart(SE_UNKNOWN_0xDF);
                }
            }
            else
            {
                if (gCurrentPinballGame->cyndaquilAnimFrame < 3)
                {
                    gCurrentPinballGame->cyndaquilAnimFrame++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
            }

            index = gCurrentPinballGame->cyndaquilAnimFrame;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->cyndaquilHitPending = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->cyndaquilSubframeTimer < 270)
        {
            index = (gCurrentPinballGame->cyndaquilSubframeTimer % 60) / 30 + 4;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }
        else
        {
            index = 0;
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->cyndaquilAnimPhase = 2;
            gCurrentPinballGame->cyndaquilAnimFrame = 0;
        }

        if (gCurrentPinballGame->cyndaquilSubframeTimer == 60)
        {
            m4aSongNumStart(MUS_EGG_MODE_START);
            gCurrentPinballGame->catchModeBlinkActive = 0;
            gCurrentPinballGame->pondAnimState = 5;
            gCurrentPinballGame->pondAnimIndex = 12;
            gCurrentPinballGame->pondAnimSubFrame = 0;
        }

        gCurrentPinballGame->cyndaquilSubframeTimer++;
        break;
    case 3:
        if (gUnknown_086AE5A0[gCurrentPinballGame->cyndaquilAnimFrame][1] > gCurrentPinballGame->cyndaquilSubframeTimer)
        {
            gCurrentPinballGame->cyndaquilSubframeTimer++;
        }
        else
        {
            gCurrentPinballGame->cyndaquilSubframeTimer = 0;
            gCurrentPinballGame->cyndaquilAnimFrame++;
            if (gCurrentPinballGame->cyndaquilAnimFrame == 10)
                gCurrentPinballGame->cyndaquilAnimPhase = 4;

            if (gCurrentPinballGame->cyndaquilAnimFrame == 6)
                m4aSongNumStart(SE_UNKNOWN_0xE0);

            index = gUnknown_086AE5A0[gCurrentPinballGame->cyndaquilAnimFrame][0];
            DmaCopy16(3, &gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->cyndaquilAnimFrame < 6)
        {
            gCurrentPinballGame->bonusSpriteYQ10 = 280;
        }
        else
        {
            gCurrentPinballGame->bonusSpriteYQ10 += 6;
            if (gCurrentPinballGame->cyndaquilAnimPhase == 4)
                gCurrentPinballGame->bonusSpriteYQ10 = gCurrentPinballGame->bonusSpriteYQ10 + 20;
        }
        break;
    case 4:
        if (gCurrentPinballGame->cyndaquilCatchReady && gCurrentPinballGame->cyndaquilHitPending)
        {
            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
            gCurrentPinballGame->scrollDelayFrames = 0;
            gCurrentPinballGame->scrollHoldFrames = 160;
            gCurrentPinballGame->scrollTargetBottomY = 0;
            gCurrentPinballGame->fieldScrollOffsetY = 0;
            gCurrentPinballGame->fieldScrollSpeed = 0;
            gCurrentPinballGame->bannerGfxVariant = 0;
            gCurrentPinballGame->scrollOverrideActive = 1;
            gCurrentPinballGame->scrollFromBottom = 0;
            gCurrentPinballGame->cyndaquilAnimPhase = 5;
            gCurrentPinballGame->cyndaquilSubframeTimer = 0;
            gCurrentPinballGame->cyndaquilAnimFrame = 10;
            m4aSongNumStart(SE_UNKNOWN_0xE0);
            gCurrentPinballGame->pondAnimState = 1;
            gCurrentPinballGame->pondSpriteXQ10 = 2080;
            gCurrentPinballGame->pondSpriteYQ10 = 960;
        }

        gCurrentPinballGame->cyndaquilHitPending = 0;
        break;
    case 5:
        if (gUnknown_086AE5A0[gCurrentPinballGame->cyndaquilAnimFrame][1] > gCurrentPinballGame->cyndaquilSubframeTimer)
        {
            gCurrentPinballGame->cyndaquilSubframeTimer++;
        }
        else
        {
            gCurrentPinballGame->cyndaquilSubframeTimer = 0;
            gCurrentPinballGame->cyndaquilAnimFrame++;
            if (gCurrentPinballGame->cyndaquilAnimFrame == 15)
                gCurrentPinballGame->cyndaquilAnimPhase = 6;

            index = gUnknown_086AE5A0[gCurrentPinballGame->cyndaquilAnimFrame][0];
            DmaCopy16(3, gUnknown_08490A4C[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->cyndaquilAnimFrame == 14 && gCurrentPinballGame->cyndaquilSubframeTimer == 10)
            m4aSongNumStart(SE_UNKNOWN_0xE1);

        if (gCurrentPinballGame->pondSpriteYQ10 > 700)
            gCurrentPinballGame->pondSpriteYQ10 -= 5;
        else
            gCurrentPinballGame->pondSpriteYQ10 = 700;
        break;
    case 6:
        gCurrentPinballGame->cyndaquilAnimFrame = 0;
        gCurrentPinballGame->cyndaquilSubframeTimer = 0;
        gCurrentPinballGame->cyndaquilAnimPhase = 0;
        gCurrentPinballGame->cyndaquilCatchReady = 0;
        break;
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[47 + i];
        if (group->available)
        {
            if (gUnknown_086AE58A[gCurrentPinballGame->edgeHitFxAnimFrame[i]][0] > gCurrentPinballGame->edgeHitFxSubframe[i])
            {
                gCurrentPinballGame->edgeHitFxSubframe[i]++;
            }
            else
            {
                gCurrentPinballGame->edgeHitFxSubframe[i] = 0;
                gCurrentPinballGame->edgeHitFxAnimFrame[i]++;
                if (gCurrentPinballGame->edgeHitFxAnimFrame[i] == 6)
                {
                    group->available = 0;
                    gCurrentPinballGame->edgeHitFxAnimFrame[i] = 5;
                }
            }

            index = gUnknown_086AE588[gCurrentPinballGame->edgeHitFxAnimFrame[i]][0];
            DmaCopy16(3, &gUnknown_0845A08C[index], (void *)0x060140a0 + i * 0x100, 0x100);
            group->baseX = gUnknown_086AE554[gCurrentPinballGame->edgeHitFxTargetIndex[i]].x - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gUnknown_086AE554[gCurrentPinballGame->edgeHitFxTargetIndex[i]].y - gCurrentPinballGame->bgScrollYWithOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void UpdateEdgeIndicatorSprite(void)
{
    s16 i;
    struct SpriteGroup *group;

    if (gMain.selectedField == FIELD_RUBY)
        group = &gMain.spriteGroups[81];
    else
        group = &gMain.spriteGroups[85];

    if (group->available)
    {
        if (gCurrentPinballGame->cameraScrollX < 8)
        {
            group->baseX = gCurrentPinballGame->bgScrollXCopy;
            group->baseX = -8 - group->baseX;
        }
        else
        {
            group->baseX = gCurrentPinballGame->bgScrollXCopy;
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
void RestoreBoardPalettesAfterMenu(s16 arg0)
{
    if (gCurrentPinballGame->fieldScrollState == 1)
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[arg0], (void*)OBJ_PLTT, 0x20);
    }

    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xC0);
    }
    else
    {
        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[arg0] + 0x40, (void*)OBJ_PLTT + 0x40, 0xE0);
    }

    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[arg0] + 0x140, (void *)OBJ_PLTT + 0x140, 0x20);

    // related to Y position of camera on the field
    if (gCurrentPinballGame->viewportBottomY < 170)
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][arg0 * 2], (void *)OBJ_PLTT + 0x160, 0x20);
    }
    else
    {
        DmaCopy16(3, gUnknown_08137B3C[gMain.selectedField][arg0 * 2 + 1], (void *)OBJ_PLTT + 0x160, 0x20);
    }
}
