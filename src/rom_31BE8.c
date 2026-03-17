#include "global.h"
#include "main.h"
#include "gba/gba.h"
#include "m4a.h"
#include "constants/fields.h"
#include "constants/bg_music.h"

extern const u8 gSplashEffectTileGfx[][0x100];
extern const s16 gHoleAnimKeyframeData[][2];
extern const s16 gSplashEffectFrameDurations[][2];
extern const s16 gSplashEffectTileIndices[][2];
extern const u8 gHoleIndicatorTileGfx[][0x440];
extern struct Vector16 gSplashEffectPositions[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gSapphireShopSignPalettes[][0x20];
extern const u8 gSapphireShopSignTileGfx[][0x480];

void DrawSapphireShopSignSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[69];
    if (group->available)
    {
        group->baseX = 16 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 115 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->shopSignPaletteIndex + gCurrentPinballGame->activePaletteIndex * 3;
        DmaCopy16(3, gSapphireShopSignPalettes[index], (void *)0x05000300, 0x20);
        DmaCopy16(3, gSapphireShopSignTileGfx[gCurrentPinballGame->shopSignFrame], (void *) 0x06014B20, 0x480);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void UpdateSapphireHoleLetterSystem(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    switch (gCurrentPinballGame->holeLetterSystemState)
    {
    case 0:
        if (gCurrentPinballGame->holeLetterNewHit)
        {
            if (gCurrentPinballGame->boardState < 3)
            {
                if (gCurrentPinballGame->holeLetterCount < 3)
                {
                    gCurrentPinballGame->holeLetterCount++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
                else
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 920;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = 0;
                    gCurrentPinballGame->bannerActive = 1;
                    gCurrentPinballGame->bannerPreserveBallState = 0;
                    gCurrentPinballGame->holeLetterSystemState = 1;
                    gCurrentPinballGame->holeAnimFrameCounter = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    gCurrentPinballGame->scoreAddedInFrame = 200000;
                    m4aSongNumStart(SE_UNKNOWN_0xDF);
                }
            }
            else
            {
                if (gCurrentPinballGame->holeLetterCount < 3)
                {
                    gCurrentPinballGame->holeLetterCount++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
            }

            index = gCurrentPinballGame->holeLetterCount;
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->holeLetterNewHit = 0;
        }
        break;
    case 1:
        if (gCurrentPinballGame->holeAnimFrameCounter < 270)
        {
            index = (gCurrentPinballGame->holeAnimFrameCounter % 60) / 30 + 4;
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        }
        else
        {
            index = 0;
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->holeLetterSystemState = 2;
            gCurrentPinballGame->holeLetterCount = 0;
        }

        if (gCurrentPinballGame->holeAnimFrameCounter == 60)
        {
            m4aSongNumStart(MUS_EGG_MODE_START);
            gCurrentPinballGame->catchArrowPaletteActive = 0;
            gCurrentPinballGame->eggAnimationPhase = 5;
            gCurrentPinballGame->eggAnimFrameIndex = 12;
            gCurrentPinballGame->eggFrameTimer = 0;
        }

        gCurrentPinballGame->holeAnimFrameCounter++;
        break;
    case 3:
        if (gHoleAnimKeyframeData[gCurrentPinballGame->holeLetterCount][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->holeLetterCount++;
            if (gCurrentPinballGame->holeLetterCount == 10)
                gCurrentPinballGame->holeLetterSystemState = 4;

            if (gCurrentPinballGame->holeLetterCount == 6)
                m4aSongNumStart(SE_UNKNOWN_0xE0);

            index = gHoleAnimKeyframeData[gCurrentPinballGame->holeLetterCount][0];
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->holeLetterCount < 6)
        {
            gCurrentPinballGame->walkMonYPos = 280;
        }
        else
        {
            gCurrentPinballGame->walkMonYPos += 6;
            if (gCurrentPinballGame->holeLetterSystemState == 4)
                gCurrentPinballGame->walkMonYPos = gCurrentPinballGame->walkMonYPos + 20;
        }
        break;
    case 4:
        if (gCurrentPinballGame->holeCaptureReady && gCurrentPinballGame->holeLetterNewHit)
        {
            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
            gCurrentPinballGame->bannerDelayTimer = 0;
            gCurrentPinballGame->bannerDisplayTimer = 160;
            gCurrentPinballGame->cameraYScrollTarget = 0;
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->cameraYScrollSpeed = 0;
            gCurrentPinballGame->bannerGfxIndex = 0;
            gCurrentPinballGame->bannerActive = 1;
            gCurrentPinballGame->bannerPreserveBallState = 0;
            gCurrentPinballGame->holeLetterSystemState = 5;
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->holeLetterCount = 10;
            m4aSongNumStart(SE_UNKNOWN_0xE0);
            gCurrentPinballGame->eggAnimationPhase = 1;
            gCurrentPinballGame->portraitOffsetX = 2080;
            gCurrentPinballGame->portraitOffsetY = 960;
        }

        gCurrentPinballGame->holeLetterNewHit = 0;
        break;
    case 5:
        if (gHoleAnimKeyframeData[gCurrentPinballGame->holeLetterCount][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->holeLetterCount++;
            if (gCurrentPinballGame->holeLetterCount == 15)
                gCurrentPinballGame->holeLetterSystemState = 6;

            index = gHoleAnimKeyframeData[gCurrentPinballGame->holeLetterCount][0];
            DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->holeLetterCount == 14 && gCurrentPinballGame->holeAnimFrameCounter == 10)
            m4aSongNumStart(SE_UNKNOWN_0xE1);

        if (gCurrentPinballGame->portraitOffsetY > 700)
            gCurrentPinballGame->portraitOffsetY -= 5;
        else
            gCurrentPinballGame->portraitOffsetY = 700;
        break;
    case 6:
        gCurrentPinballGame->holeLetterCount = 0;
        gCurrentPinballGame->holeAnimFrameCounter = 0;
        gCurrentPinballGame->holeLetterSystemState = 0;
        gCurrentPinballGame->holeCaptureReady = 0;
        break;
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[47 + i];
        if (group->available)
        {
            if (gSplashEffectFrameDurations[gCurrentPinballGame->splashEffectFrameIndex[i]][0] > gCurrentPinballGame->splashEffectFrameTimer[i])
            {
                gCurrentPinballGame->splashEffectFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->splashEffectFrameTimer[i] = 0;
                gCurrentPinballGame->splashEffectFrameIndex[i]++;
                if (gCurrentPinballGame->splashEffectFrameIndex[i] == 6)
                {
                    group->available = 0;
                    gCurrentPinballGame->splashEffectFrameIndex[i] = 5;
                }
            }

            index = gSplashEffectTileIndices[gCurrentPinballGame->splashEffectFrameIndex[i]][0];
            DmaCopy16(3, &gSplashEffectTileGfx[index], (void *)0x060140a0 + i * 0x100, 0x100);
            group->baseX = gSplashEffectPositions[gCurrentPinballGame->splashEffectPositionIndex[i]].x - gCurrentPinballGame->cameraXOffset;
            group->baseY = gSplashEffectPositions[gCurrentPinballGame->splashEffectPositionIndex[i]].y - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

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
