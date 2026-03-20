#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u16 gHatchCaveOamFramesets[40][2][3];
extern const u16 gSeedotBasketBounceFrames[];
extern const u8 gSapphireStageBasket_Gfx[][0x280];
extern const u8 gSapphireBoardSeedot_Gfx[][0x180];
extern const u16 gSeedotBaseXPositions[];
extern const u16 gSapphireBoardSeedotSpritesheetOam[6][6][2][3];
extern const u16 gShopSignTransitionFrames[][14];
extern const u16 gShopSignIntroFrames[][4];
extern const u16 gShopSignLoopFrames[][5];

extern const s16 gHoleAnimKeyframeData[][2];
extern const u8 gHoleIndicatorTileGfx[][0x440];

extern const u8 gSplashEffectTileGfx[][0x100];
extern struct Vector16 gSplashEffectPositions[];
extern const s16 gSplashEffectFrameDurations[][2];
extern const s16 gSplashEffectTileIndices[][2];
extern const u8 gSapphireShopSignPalettes[][0x20];
extern const u8 gSapphireShopSignTileGfx[][0x480];


void InitSapphireEggHatchState(void)
{
    gCurrentPinballGame->eggAnimationPhase = 1;
    gCurrentPinballGame->prevEggAnimFrame = 0;
    gCurrentPinballGame->eggAnimFrameIndex = 0;
    gCurrentPinballGame->eggFrameTimer = 0;
    gCurrentPinballGame->portraitOffsetX = 2080;
    gCurrentPinballGame->portraitOffsetY = 700;
}

void UpdateSapphireEggHatchAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 sp0;
    s16 index;
    s16 var1;
    s16 var2;
    s16 var3;
    int var0;

    var3 = 0;
    var1 = 0;
    var2 = 0;
    group = &gMain.spriteGroups[52];
    sp0 = 0;
    switch (gCurrentPinballGame->eggAnimationPhase)
    {
    case 0:
    case 1:
        break;
    case 2:
        var3 = 4;
        var1 = 4;
        var2 = 3;
        break;
    case 3:
        var3 = 8;
        var1 = 4;
        var2 = 3;
        break;
    case 4:
        var3 = 12;
        var1 = 12;
        var2 = 5;
        break;
    case 5:
        var3 = 33;
        var1 = 0;
        var2 = 0;
        break;
    }

    if (gCurrentPinballGame->prevEggAnimFrame != gCurrentPinballGame->eggAnimFrameIndex)
    {
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3];
        DmaCopy16(3, &gEggFrameTilesGfx[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->prevEggAnimFrame = gCurrentPinballGame->eggAnimFrameIndex;
    }

    if (gCurrentPinballGame->eggAnimationPhase > 1)
    {
        if (gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][1] > gCurrentPinballGame->eggFrameTimer)
        {
            gCurrentPinballGame->eggFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->eggAnimFrameIndex++;
            gCurrentPinballGame->eggFrameTimer = 0;
            if (gCurrentPinballGame->eggAnimFrameIndex >= var3)
            {
                gCurrentPinballGame->eggAnimFrameIndex = var1;
                gCurrentPinballGame->eggAnimationPhase = var2;
            }

            if (gCurrentPinballGame->eggAnimFrameIndex == 18)
                BuildSpeciesWeightsForEggMode();

            if (gCurrentPinballGame->eggAnimFrameIndex == 19)
            {
                PickSpeciesForEggMode();
                if (gMain.mainState != STATE_GAME_IDLE)
                    SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);
            }

            if (gCurrentPinballGame->eggAnimFrameIndex == 20)
                LoadEggSpriteGraphics();

            if ((gCurrentPinballGame->eggAnimFrameIndex == 8 || gCurrentPinballGame->eggAnimFrameIndex == 27) && gCurrentPinballGame->eggFrameTimer == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->eggAnimFrameIndex == 12 && gCurrentPinballGame->eggFrameTimer == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->eggAnimFrameIndex == 29)
                RequestBoardStateTransition(5);

            if (gCurrentPinballGame->eggAnimFrameIndex == 28)
                m4aSongNumStart(SE_HATCH_FLOURISH);
        }

        sp0 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][0];
    }

    group->baseX = gCurrentPinballGame->portraitOffsetX / 10 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->eggAnimationPhase > 0)
    {
        if (gCurrentPinballGame->eggAnimFrameIndex == 32 && gCurrentPinballGame->eggFrameTimer > 208)
        {
            var0 = (0x100 - gCurrentPinballGame->eggFrameTimer) / 16;
            if (gMain.systemFrameCount & ((var0 + 1) * 2))
                group->baseY = gCurrentPinballGame->portraitOffsetY / 10 - gCurrentPinballGame->cameraYOffset;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->portraitOffsetY / 10 - gCurrentPinballGame->cameraYOffset;
        }
    }
    else
    {
        group->baseY = 200;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gHatchCaveOamFramesets[sp0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[51];
    if (group->available)
    {
        group->baseX = 192 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->sapphireHatchMachineState > 2 && gMain.modeChangeFlags)
            group->baseY = 56 - gCurrentPinballGame->cameraYOffset;
        else
            group->baseY = 200;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateSapphireSeedotCollection(void)
{
    s16 i;
    s16 var0;

    if (gCurrentPinballGame->seedotCollisionTrigger)
    {
        if (gCurrentPinballGame->boardState != 7)
        {
            if (gCurrentPinballGame->boardState < 3)
            {
                if (gCurrentPinballGame->seedotCount < 3)
                {
                    gCurrentPinballGame->seedotYOffset[gCurrentPinballGame->seedotCount] = -100;
                    gCurrentPinballGame->seedotOamFramesetIndex[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotState[gCurrentPinballGame->seedotCount] = 1;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotCount++;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    if (gCurrentPinballGame->seedotCount == 3)
                        gCurrentPinballGame->seedotModeStartDelay = 1;
                }
            }
            else
            {
                if (gCurrentPinballGame->seedotCount < 2)
                {
                    gCurrentPinballGame->seedotYOffset[gCurrentPinballGame->seedotCount] = -100;
                    gCurrentPinballGame->seedotOamFramesetIndex[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotState[gCurrentPinballGame->seedotCount] = 1;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->seedotCount] = 0;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    gCurrentPinballGame->seedotCount++;
                }
            }
        }

        gCurrentPinballGame->seedotCollisionTrigger = 0;
        gCurrentPinballGame->scoreAddedInFrame = 3000;
    }

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->seedotState[i])
        {
        case 0:
            gCurrentPinballGame->seedotYOffset[i] = -100;
            gCurrentPinballGame->seedotOamFramesetIndex[i] = 0;
            gCurrentPinballGame->seedotAnimTimer[i] = 0;
            break;
        case 1:
            if (gCurrentPinballGame->seedotAnimTimer[i] < 33)
            {
                if (gCurrentPinballGame->seedotAnimTimer[i] == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xE9);

                if (gCurrentPinballGame->seedotAnimTimer[i] == 26)
                    m4aSongNumStart(SE_UNKNOWN_0xEA);

                gCurrentPinballGame->seedotAnimTimer[i]++;
                if (gCurrentPinballGame->seedotAnimTimer[i] < 21)
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 0;
                    gCurrentPinballGame->seedotYOffset[i] = gCurrentPinballGame->seedotAnimTimer[i] * 4 - 80;
                    if (gCurrentPinballGame->seedotAnimTimer[i] == 20)
                        gCurrentPinballGame->basketBounceTimer = 23;
                }
                else if (gCurrentPinballGame->seedotAnimTimer[i] < 25)
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 1;
                }
                else
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 2;
                }
            }
            else
            {
                gCurrentPinballGame->seedotState[i] = 2;
                gCurrentPinballGame->seedotAnimTimer[i] = 0;
                if (i == 2)
                    RequestBoardStateTransition(7);
            }
            break;
        case 2:
            gCurrentPinballGame->seedotSpriteFrame[i] = (((gCurrentPinballGame->globalAnimFrameCounter % 32) / 16) * 2) + 1;
            if (gCurrentPinballGame->seedotSpriteFrame[i] == 1)
                gCurrentPinballGame->seedotYOffset[i] = -2;
            else
                gCurrentPinballGame->seedotYOffset[i] = 0;
            break;
        case 3:
            var0 = gCurrentPinballGame->seedotAnimTimer[i];
            if (var0 < 32)
            {
                gCurrentPinballGame->seedotSpriteFrame[i] = var0 / 16 + 4;
                gCurrentPinballGame->seedotOamFramesetIndex[i] = var0 / 16 + 1;
            }
            else if (var0 < 38)
            {
                if (var0 == 32 && (gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME) == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xEB);

                gCurrentPinballGame->seedotSpriteFrame[i] = 6;
                gCurrentPinballGame->seedotOamFramesetIndex[i] = 3;
            }
            else if (var0 < 46)
            {
                gCurrentPinballGame->seedotOamFramesetIndex[i] = 4;
            }
            else if (var0 < 54)
            {
                gCurrentPinballGame->seedotOamFramesetIndex[i] = 5;
            }
            else
            {
                gCurrentPinballGame->seedotState[i] = 0;
            }

            gCurrentPinballGame->seedotAnimTimer[i]++;
            break;
        }
    }

    if (gCurrentPinballGame->basketBounceTimer)
    {
        gCurrentPinballGame->basketBounceFrame = gSeedotBasketBounceFrames[gCurrentPinballGame->basketBounceTimer / 6];
        gCurrentPinballGame->basketBounceTimer--;
    }

    if (gCurrentPinballGame->seedotModeStartDelay)
    {
        gCurrentPinballGame->seedotModeStartDelay--;
        if (gCurrentPinballGame->seedotModeStartDelay == 0)
        {
            if (gCurrentPinballGame->activePortraitType)
                gCurrentPinballGame->seedotModeStartDelay = 1;
            else
                gCurrentPinballGame->activePortraitType = 4;

            if (gCurrentPinballGame->seedotModeStartDelay == 0)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 70;
                gCurrentPinballGame->bannerDisplayTimer = 160;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 4;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->bannerDisplayDuration = 120;
                gCurrentPinballGame->bannerSlidePosition = 0;
                gCurrentPinballGame->bannerSlideTimer = 50;
                gCurrentPinballGame->bannerSlideVelocity = 0;
                DmaCopy16(3, gModeBannerTilemaps[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gModeBannerPalettes[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
    if (gCurrentPinballGame->seedotExitSequenceActive)
    {
        var0 = gCurrentPinballGame->seedotExitSequenceTimer++;
        if (var0 <= 60)
        {
            if (var0 % 30 == 0)
            {
                if (gCurrentPinballGame->seedotState[var0 / 30] == 2)
                {
                    gCurrentPinballGame->seedotState[var0 / 30] = 3;
                    gCurrentPinballGame->seedotAnimTimer[var0 / 30] = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->seedotExitSequenceActive = 0;
            gCurrentPinballGame->seedotExitSequenceTimer = 0;
        }
    }

    if (gCurrentPinballGame->seedotDecayTimer)
    {
        gCurrentPinballGame->seedotDecayTimer--;
        if (gCurrentPinballGame->seedotDecayTimer == 0)
        {
            if (gCurrentPinballGame->seedotCount == 1 || gCurrentPinballGame->seedotCount == 2)
            {
                gCurrentPinballGame->seedotCount--;
                gCurrentPinballGame->seedotState[gCurrentPinballGame->seedotCount] = 3;
                gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->seedotCount] = 0;
                gCurrentPinballGame->seedotDecayTimer = 1800;
            }
        }
    }
}

void DrawSapphireSeedotAndBasketSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    int var0;

    group = &gMain.spriteGroups[64];
    if (!group->available)
        return;

    group->baseX = 10 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 298 - gCurrentPinballGame->cameraYOffset;
    index = gCurrentPinballGame->basketBounceFrame;
    DmaCopy16(3, gSapphireStageBasket_Gfx[index], (void *)0x060139A0, 0x280);

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[68];
    group->baseX = 10 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 298 - gCurrentPinballGame->cameraYOffset;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    for (j = 0; j < 3; j++)
    {
        group = &gMain.spriteGroups[65 + j];

        var0 = gSeedotBaseXPositions[j] - j;
        group->baseX = var0 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->seedotState[j] > 0)
            group->baseY = gCurrentPinballGame->seedotYOffset[j] + 292 - gCurrentPinballGame->cameraYOffset;
        else
            group->baseY = 200;

        DmaCopy16(3, gSapphireBoardSeedot_Gfx[gCurrentPinballGame->seedotSpriteFrame[j]], (void *)0x06013C20 + j * 0x180, 0x160);
        index = gCurrentPinballGame->seedotOamFramesetIndex[j];
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gSapphireBoardSeedotSpritesheetOam[j][index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void UpdateSapphireShopSignAnimation(void)
{
    if (gCurrentPinballGame->shopTransitionActive == 0)
    {
        if (gCurrentPinballGame->evolutionShopActive == 1)
        {
            if (gCurrentPinballGame->shopAnimTimer < 96)
            {
                if (gCurrentPinballGame->shopAnimTimer < 8)
                    gCurrentPinballGame->shopSignFrame = gShopSignIntroFrames[1][gCurrentPinballGame->shopAnimTimer / 2];
                else
                    gCurrentPinballGame->shopSignFrame = gShopSignLoopFrames[1][(gCurrentPinballGame->shopAnimTimer % 32) / 8];

                gCurrentPinballGame->shopAnimTimer++;
            }
            else
            {
                gCurrentPinballGame->shopAnimTimer = 0;
            }

            gCurrentPinballGame->shopSignPaletteIndex = 2;
        }
        else
        {
            if (gCurrentPinballGame->shopAnimTimer < 120)
            {
                if (gCurrentPinballGame->shopAnimTimer < 8)
                    gCurrentPinballGame->shopSignFrame = gShopSignIntroFrames[0][gCurrentPinballGame->shopAnimTimer / 2];
                else
                    gCurrentPinballGame->shopSignFrame = gShopSignLoopFrames[0][(gCurrentPinballGame->shopAnimTimer % 40) / 8];

                gCurrentPinballGame->shopAnimTimer++;
            }
            else
            {
                gCurrentPinballGame->shopAnimTimer = 0;
            }

            gCurrentPinballGame->shopSignPaletteIndex = 0;
        }

        if (gCurrentPinballGame->evoArrowProgress > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->evolutionShopActive == 0)
            {
                gCurrentPinballGame->shopTransitionActive = 1;
                gCurrentPinballGame->shopAnimTimer = 0;
                gCurrentPinballGame->evolutionShopActive = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->boardState != 6 && gCurrentPinballGame->evolutionShopActive == 1)
            {
                gCurrentPinballGame->shopTransitionActive = 1;
                gCurrentPinballGame->shopAnimTimer = 0;
                gCurrentPinballGame->evolutionShopActive = 0;
            }
        }
    }
    else
    {
        gCurrentPinballGame->shopSignFrame = gShopSignTransitionFrames[gCurrentPinballGame->evolutionShopActive][gCurrentPinballGame->shopAnimTimer / 3];
        if (gCurrentPinballGame->shopSignFrame >= 4 && gCurrentPinballGame->shopSignFrame < 6)
        {
            gCurrentPinballGame->shopSignPaletteIndex = 1;
        }
        else
        {
            if (gCurrentPinballGame->evolutionShopActive == 1)
            {
                if (gCurrentPinballGame->shopAnimTimer < 15)
                    gCurrentPinballGame->shopSignPaletteIndex = 0;
                else
                    gCurrentPinballGame->shopSignPaletteIndex = 2;
            }
            else
            {
                if (gCurrentPinballGame->shopAnimTimer < 15)
                    gCurrentPinballGame->shopSignPaletteIndex = 2;
                else
                    gCurrentPinballGame->shopSignPaletteIndex = 0;
            }
        }

        gCurrentPinballGame->shopAnimTimer++;
        if (gCurrentPinballGame->shopAnimTimer == 42)
        {
            gCurrentPinballGame->shopTransitionActive = 0;
            gCurrentPinballGame->shopAnimTimer = 0;
        }
    }
}

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

void UpdateSapphireEggMachine(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    switch (gCurrentPinballGame->sapphireHatchMachineState)
    {
    case 0:
        if (gCurrentPinballGame->hatchMachineNewHit)
        {
            if (gCurrentPinballGame->boardState < 3)
            {
                if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 3)
                {
                    gCurrentPinballGame->sapphireHatchMachineFrameIx++;
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
                    gCurrentPinballGame->sapphireHatchMachineState = 1;
                    gCurrentPinballGame->holeAnimFrameCounter = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    gCurrentPinballGame->scoreAddedInFrame = 200000;
                    m4aSongNumStart(SE_UNKNOWN_0xDF);
                }
            }
            else
            {
                if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 3)
                {
                    gCurrentPinballGame->sapphireHatchMachineFrameIx++;
                    gCurrentPinballGame->scoreAddedInFrame = 20000;
                    m4aSongNumStart(SE_UNKNOWN_0xDE);
                }
            }

            index = gCurrentPinballGame->sapphireHatchMachineFrameIx;
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
            gCurrentPinballGame->hatchMachineNewHit = 0;
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
            gCurrentPinballGame->sapphireHatchMachineState = 2;
            gCurrentPinballGame->sapphireHatchMachineFrameIx = 0;
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
        if (gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx++;
            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 10)
                gCurrentPinballGame->sapphireHatchMachineState = 4;

            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 6)
                m4aSongNumStart(SE_UNKNOWN_0xE0);

            index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
            DmaCopy16(3, &gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 6)
        {
            gCurrentPinballGame->walkMonYPos = 280;
        }
        else
        {
            gCurrentPinballGame->walkMonYPos += 6;
            if (gCurrentPinballGame->sapphireHatchMachineState == 4)
                gCurrentPinballGame->walkMonYPos = gCurrentPinballGame->walkMonYPos + 20;
        }
        break;
    case 4:
        if (gCurrentPinballGame->sapphirerubyEggDeliveryState && gCurrentPinballGame->hatchMachineNewHit)
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
            gCurrentPinballGame->sapphireHatchMachineState = 5;
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx = 10;
            m4aSongNumStart(SE_UNKNOWN_0xE0);
            gCurrentPinballGame->eggAnimationPhase = 1;
            gCurrentPinballGame->portraitOffsetX = 2080;
            gCurrentPinballGame->portraitOffsetY = 960;
        }

        gCurrentPinballGame->hatchMachineNewHit = 0;
        break;
    case 5:
        if (gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx++;
            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 15)
                gCurrentPinballGame->sapphireHatchMachineState = 6;

            index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
            DmaCopy16(3, gHoleIndicatorTileGfx[index], (void *)0x600D900, 0x440);
        }

        if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 14 && gCurrentPinballGame->holeAnimFrameCounter == 10)
            m4aSongNumStart(SE_UNKNOWN_0xE1);

        if (gCurrentPinballGame->portraitOffsetY > 700)
            gCurrentPinballGame->portraitOffsetY -= 5;
        else
            gCurrentPinballGame->portraitOffsetY = 700;
        break;
    case 6:
        gCurrentPinballGame->sapphireHatchMachineFrameIx = 0;
        gCurrentPinballGame->holeAnimFrameCounter = 0;
        gCurrentPinballGame->sapphireHatchMachineState = 0;
        gCurrentPinballGame->sapphirerubyEggDeliveryState = 0;
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
