#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/sapphire.h"

// Rom_1 data
extern const u16 gShopSignLoopFrames[][5];
extern const u16 gShopSignIntroFrames[][4];
extern const u16 gShopSignTransitionFrames[][14];
extern const Palette gSapphireShopSign_Pals[];
extern const u8 gSapphireStageBasket_Gfx[][SIZE_OF_SEEDOT_BASKET_TILES];
extern const u8 gHatchMachineSparkleFx_Gfx[][SIZE_OF_HATCH_MACHINE_SPARKLE_FX_TILES];
#ifdef EUROPE
extern const u8 gSapphireShopSignTileGfx_En[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
extern const u8 gSapphireShopSignTileGfx_Fr[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
extern const u8 gSapphireShopSignTileGfx_De[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
extern const u8 gSapphireShopSignTileGfx_It[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
extern const u8 gSapphireShopSignTileGfx_Es[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
#else
extern const u8 gSapphireShopSignTileGfx[][SIZE_OF_SAPPHIRE_MART_SIGN_TILES];
#endif
extern const u8 gHatchMachineElevator_Gfx[][SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES];
extern const u8 gEggFrameTilesGfx[][SIZE_OF_VRAM_HATCH_EGG_TILES];
extern const u8 gSapphireBoardSeedot_Gfx[][SIZE_OF_SEEDOT_ENTITY_RAW_TILES];

// Rom_2 data
extern const u16 gEggAnimationFrameData[][4];
extern const u16 gSeedotBaseXPositions[];
extern const u16 gSeedotBasketBounceFrames[];
extern const struct Vector16 gSplashEffectPositions[];
extern const s16 gSplashEffectTileIndices[][2];
extern const s16 gHoleAnimKeyframeData[][2];
extern const u16 gSapphireBoardSeedotSpritesheetOam[6][6][2][3];
extern const u16 gEggOamFramestates[40][2][3];

void InitSapphireEggHatchAnimation(void)
{
    gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_STILL;
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
    s16 startFrameOfNextPhase;
    s16 nextPhase;
    s16 lastFrameOfPhase;
    int var0;

    lastFrameOfPhase = 0;
    startFrameOfNextPhase = 0;
    nextPhase = 0;
    group = &gMain.spriteGroups[SG_SAPPHIRE_HATCH_EGG];
    sp0 = 0;
    
    //Note: Sapphire board jumps straight from 'Still' to 'Hatch shakes'
    switch (gCurrentPinballGame->eggAnimationPhase)
    {
    case EGG_ANIM_PHASE_OFF_BOARD:
    case EGG_ANIM_PHASE_STILL:
        break;
    case EGG_ANIM_PHASE_CYNDAQUIL_ENTERS_BALL_JUMP:
        lastFrameOfPhase = 4;
        startFrameOfNextPhase = 4;
        nextPhase = EGG_ANIM_PHASE_HATCH_CAVE_GLOW;
        break;
    case EGG_ANIM_PHASE_HATCH_CAVE_GLOW:
        lastFrameOfPhase = 8;
        startFrameOfNextPhase = 4;
        nextPhase = EGG_ANIM_PHASE_HATCH_CAVE_GLOW;
        break;
    case EGG_ANIM_PHASE_EGG_JUMPS:
        lastFrameOfPhase = 12;
        startFrameOfNextPhase = 12;
        nextPhase = EGG_ANIM_PHASE_HATCH_SHAKES;
        break;
    case EGG_ANIM_PHASE_HATCH_SHAKES:
        lastFrameOfPhase = 33;
        startFrameOfNextPhase = 0;
        nextPhase = EGG_ANIM_PHASE_OFF_BOARD;
        break;
    }

    if (gCurrentPinballGame->prevEggAnimFrame != gCurrentPinballGame->eggAnimFrameIndex)
    {
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3];
        DmaCopy16(3, &gEggFrameTilesGfx[index], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
        gCurrentPinballGame->prevEggAnimFrame = gCurrentPinballGame->eggAnimFrameIndex;
    }

    if (gCurrentPinballGame->eggAnimationPhase > EGG_ANIM_PHASE_STILL)
    {
        if (gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][1] > gCurrentPinballGame->eggFrameTimer)
        {
            gCurrentPinballGame->eggFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->eggAnimFrameIndex++;
            gCurrentPinballGame->eggFrameTimer = 0;
            if (gCurrentPinballGame->eggAnimFrameIndex >= lastFrameOfPhase)
            {
                gCurrentPinballGame->eggAnimFrameIndex = startFrameOfNextPhase;
                gCurrentPinballGame->eggAnimationPhase = nextPhase;
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
                LoadMonFieldSpriteGraphics();

            if ((gCurrentPinballGame->eggAnimFrameIndex == 8 || gCurrentPinballGame->eggAnimFrameIndex == 27) && gCurrentPinballGame->eggFrameTimer == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->eggAnimFrameIndex == 12 && gCurrentPinballGame->eggFrameTimer == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->eggAnimFrameIndex == 29)
                RequestBoardStateTransition(MAIN_BOARD_STATE_EGG_HATCH_MODE);

            if (gCurrentPinballGame->eggAnimFrameIndex == 28)
                m4aSongNumStart(SE_HATCH_FLOURISH);
        }

        sp0 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][0];
    }

    group->baseX = gCurrentPinballGame->portraitOffsetX / 10 - gCurrentPinballGame->cameraXOffset;
    if (gCurrentPinballGame->eggAnimationPhase > EGG_ANIM_PHASE_OFF_BOARD)
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
        src = gEggOamFramestates[sp0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[SG_SAPPHIRE_HATCH_MACHINE_LOWER_SEGMENT];
    if (group->active)
    {
        group->baseX = 192 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->sapphireHatchMachineState > HATCH_MACHINE_STATE_MON_HATCHED && gMain.modeChangeFlags)
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
        if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_TRAVEL_MODE)
        {
            if (BoardNotInActivityMode)
            {
                if (gCurrentPinballGame->travelTrackerCount < 3)
                {
                    gCurrentPinballGame->seedotYOffset[gCurrentPinballGame->travelTrackerCount] = -100;
                    gCurrentPinballGame->seedotOamFramesetIndex[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->seedotState[gCurrentPinballGame->travelTrackerCount] = SEEDOT_STATE_DROPPING_IN;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->travelTrackerCount++;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    if (gCurrentPinballGame->travelTrackerCount == 3)
                        gCurrentPinballGame->travelModeStartDelay = 1;
                }
            }
            else
            {
                if (gCurrentPinballGame->travelTrackerCount < 2)
                {
                    gCurrentPinballGame->seedotYOffset[gCurrentPinballGame->travelTrackerCount] = -100;
                    gCurrentPinballGame->seedotOamFramesetIndex[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->seedotState[gCurrentPinballGame->travelTrackerCount] = SEEDOT_STATE_DROPPING_IN;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->travelTrackerCount] = 0;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    gCurrentPinballGame->travelTrackerCount++;
                }
            }
        }

        gCurrentPinballGame->seedotCollisionTrigger = FALSE;
        gCurrentPinballGame->scoreAddedInFrame = SCORE_SEEDOT_BUTTON;
    }

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->seedotState[i])
        {
        case SEEDOT_STATE_OFF_BOARD:
            gCurrentPinballGame->seedotYOffset[i] = -100;
            gCurrentPinballGame->seedotOamFramesetIndex[i] = 0;
            gCurrentPinballGame->seedotAnimTimer[i] = 0;
            break;
        case SEEDOT_STATE_DROPPING_IN:
            if (gCurrentPinballGame->seedotAnimTimer[i] < 33)
            {
                if (gCurrentPinballGame->seedotAnimTimer[i] == 0)
                    m4aSongNumStart(SE_SEEDOT_FALLING);

                if (gCurrentPinballGame->seedotAnimTimer[i] == 26)
                    m4aSongNumStart(SE_SEEDOT_LANDS);

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
                gCurrentPinballGame->seedotState[i] = SEEDOT_STATE_WAITING;
                gCurrentPinballGame->seedotAnimTimer[i] = 0;
                if (i == 2)
                    RequestBoardStateTransition(MAIN_BOARD_STATE_TRAVEL_MODE);
            }
            break;
        case SEEDOT_STATE_WAITING:
            gCurrentPinballGame->seedotSpriteFrame[i] = (((gCurrentPinballGame->globalAnimFrameCounter % 32) / 16) * 2) + 1;
            if (gCurrentPinballGame->seedotSpriteFrame[i] == 1)
                gCurrentPinballGame->seedotYOffset[i] = -2;
            else
                gCurrentPinballGame->seedotYOffset[i] = 0;
            break;
        case SEEDOT_STATE_LEAVING:
            var0 = gCurrentPinballGame->seedotAnimTimer[i];
            if (var0 < 32)
            {
                gCurrentPinballGame->seedotSpriteFrame[i] = var0 / 16 + 4;
                gCurrentPinballGame->seedotOamFramesetIndex[i] = var0 / 16 + 1;
            }
            else if (var0 < 38)
            {
                if (var0 == 32 && (gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME) == 0)
                    m4aSongNumStart(SE_SEEDOT_LEAVES);

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
                gCurrentPinballGame->seedotState[i] = SEEDOT_STATE_OFF_BOARD;
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

    if (gCurrentPinballGame->travelModeStartDelay)
    {
        gCurrentPinballGame->travelModeStartDelay--;
        if (gCurrentPinballGame->travelModeStartDelay == 0)
        {
            if (gCurrentPinballGame->activeFxType)
                gCurrentPinballGame->travelModeStartDelay = 1;
            else
                gCurrentPinballGame->activeFxType = FX_MODE_START_BANNER;

            if (gCurrentPinballGame->travelModeStartDelay == 0)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 70;
                gCurrentPinballGame->bannerDisplayTimer = 160;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_TRAVEL;
                gCurrentPinballGame->bannerActive = TRUE;
                gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
                gCurrentPinballGame->bannerDisplayDuration = 120;
                gCurrentPinballGame->bannerSlidePosition = 0;
                gCurrentPinballGame->bannerSlideTimer = 50;
                gCurrentPinballGame->bannerSlideVelocity = 0;
                DMA_MODE_BANNER_TILEMAP(4, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_MODE_BANNER_LOAD_TILES);
                DmaCopy16(3, gModeBanner_Pals[4], OBJ_PLTT_SLOT(PAL_IX_BANNER), PLTT_SLOT_SIZE);
                gMain.blendControl = 0xCE;
            }
        }
    }
    if (gCurrentPinballGame->travelTrackerExitSequenceActive)
    {
        var0 = gCurrentPinballGame->travelTrackerExitSequenceTimer++;
        if (var0 <= 60)
        {
            if (var0 % 30 == 0)
            {
                if (gCurrentPinballGame->seedotState[var0 / 30] == SEEDOT_STATE_WAITING)
                {
                    gCurrentPinballGame->seedotState[var0 / 30] = SEEDOT_STATE_LEAVING;
                    gCurrentPinballGame->seedotAnimTimer[var0 / 30] = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->travelTrackerExitSequenceActive = FALSE;
            gCurrentPinballGame->travelTrackerExitSequenceTimer = 0;
        }
    }

    if (gCurrentPinballGame->seedotDecayTimer)
    {
        gCurrentPinballGame->seedotDecayTimer--;
        if (gCurrentPinballGame->seedotDecayTimer == 0)
        {
            if (gCurrentPinballGame->travelTrackerCount == 1 || gCurrentPinballGame->travelTrackerCount == 2)
            {
                gCurrentPinballGame->travelTrackerCount--;
                gCurrentPinballGame->seedotState[gCurrentPinballGame->travelTrackerCount] = SEEDOT_STATE_LEAVING;
                gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->travelTrackerCount] = 0;
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

    group = &gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_BASKET_BACK];
    if (!group->active)
        return;

    group->baseX = 10 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 298 - gCurrentPinballGame->cameraYOffset;
    index = gCurrentPinballGame->basketBounceFrame;
    DmaCopy16(3, gSapphireStageBasket_Gfx[index], OBJ_VRAM_ADDR_SEEDOT_BASKET_TILES, SIZE_OF_SEEDOT_BASKET_TILES);

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_BASKET_FRONT];
    group->baseX = 10 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 298 - gCurrentPinballGame->cameraYOffset;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    for (j = 0; j < 3; j++)
    {
        group = &gMain.spriteGroups[SG_SAPPHIRE_SEEDOT_ENTITY_BASE + j];

        var0 = gSeedotBaseXPositions[j] - j;
        group->baseX = var0 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->seedotState[j] > SEEDOT_STATE_OFF_BOARD)
            group->baseY = gCurrentPinballGame->seedotYOffset[j] + 292 - gCurrentPinballGame->cameraYOffset;
        else
            group->baseY = 200;

        DmaCopy16(3, gSapphireBoardSeedot_Gfx[gCurrentPinballGame->seedotSpriteFrame[j]],  OBJ_VRAM_ADDR_SEEDOT_ENTITY(j), SIZE_OF_SEEDOT_ENTITY_TILES);
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
    if (!gCurrentPinballGame->shopTransitionActive)
    {
        if (gCurrentPinballGame->evolutionShopActive == TRUE)
        {
            if (gCurrentPinballGame->shopAnimTimer < 96)
            {
                if (gCurrentPinballGame->shopAnimTimer < 8)
                    gCurrentPinballGame->sapphireShopSignFrame = gShopSignIntroFrames[1][gCurrentPinballGame->shopAnimTimer / 2];
                else
                    gCurrentPinballGame->sapphireShopSignFrame = gShopSignLoopFrames[1][(gCurrentPinballGame->shopAnimTimer % 32) / 8];

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
                    gCurrentPinballGame->sapphireShopSignFrame = gShopSignIntroFrames[0][gCurrentPinballGame->shopAnimTimer / 2];
                else
                    gCurrentPinballGame->sapphireShopSignFrame = gShopSignLoopFrames[0][(gCurrentPinballGame->shopAnimTimer % 40) / 8];

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
            if (gCurrentPinballGame->evolvablePartySize > 0
                && !gCurrentPinballGame->evolutionShopActive)
            {
                gCurrentPinballGame->shopTransitionActive = TRUE;
                gCurrentPinballGame->shopAnimTimer = 0;
                gCurrentPinballGame->evolutionShopActive = TRUE;
            }
        }
        else
        {
            if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_EVO_MODE
                && gCurrentPinballGame->evolutionShopActive == TRUE)
            {
                gCurrentPinballGame->shopTransitionActive = TRUE;
                gCurrentPinballGame->shopAnimTimer = 0;
                gCurrentPinballGame->evolutionShopActive = FALSE;
            }
        }
    }
    else
    {
        gCurrentPinballGame->sapphireShopSignFrame = gShopSignTransitionFrames[gCurrentPinballGame->evolutionShopActive][gCurrentPinballGame->shopAnimTimer / 3];
        if (gCurrentPinballGame->sapphireShopSignFrame >= 4 && gCurrentPinballGame->sapphireShopSignFrame < 6)
        {
            gCurrentPinballGame->shopSignPaletteIndex = 1;
        }
        else
        {
            if (gCurrentPinballGame->evolutionShopActive == TRUE)
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
            gCurrentPinballGame->shopTransitionActive = FALSE;
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

    group = &gMain.spriteGroups[SG_SAPPHIRE_MART_SIGN];
    if (group->active)
    {
        group->baseX = 16 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 115 - gCurrentPinballGame->cameraYOffset;
        index = gCurrentPinballGame->shopSignPaletteIndex + gCurrentPinballGame->paletteDimmingIx * 3;
        DmaCopy16(3, gSapphireShopSign_Pals[index], OBJ_PLTT_SLOT(PAL_IX_SAPPHIRE_MART_SIGN), PLTT_SLOT_SIZE);
#ifdef EUROPE
        index = gCurrentPinballGame->sapphireShopSignFrame;
        switch (gMain_saveData.language)
        {
        case LANGUAGE_ENGLISH:
            DmaCopy16(3, gSapphireShopSignTileGfx_En[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
            break;
        case LANGUAGE_FRENCH:
            DmaCopy16(3, gSapphireShopSignTileGfx_Fr[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
            break;
        case LANGUAGE_GERMAN:
            DmaCopy16(3, gSapphireShopSignTileGfx_De[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
            break;
        case LANGUAGE_ITALIAN:
            DmaCopy16(3, gSapphireShopSignTileGfx_It[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
            break;
        case LANGUAGE_SPANISH:
            DmaCopy16(3, gSapphireShopSignTileGfx_Es[index], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
            break;
        }
#else
        DmaCopy16(3, gSapphireShopSignTileGfx[gCurrentPinballGame->sapphireShopSignFrame], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
#endif
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

#if defined(EUROPE) && !defined(NONMATCHING)
// The European build differs in register allocation / cross-jumping; use the original code.
NAKED
void UpdateSapphireHatchMachine(void)
{
    asm_unified(
	"\tpush {r4, r5, r6, r7, lr}\n"
	"\tmov r7, sl\n"
	"\tmov r6, sb\n"
	"\tmov r5, r8\n"
	"\tpush {r5, r6, r7}\n"
	"\tldr r1, _080349C8\n"
	"\tldr r0, [r1]\n"
	"\tldr r2, _080349CC\n"
	"\tadds r0, r0, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tadds r5, r1, #0\n"
	"\tcmp r0, #6\n"
	"\tbls _080349BC\n"
	"\tb _08034EAC\n"
	"_080349BC:\tlsls r0, r0, #2\n"
	"\tldr r1, _080349D0\n"
	"\tadds r0, r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tmov pc, r0\n"
	"\tmovs r0, r0\n"
	"_080349C8:\t.4byte gCurrentPinballGame\n"
	"_080349CC:\t.4byte 0x346\n"
	"_080349D0:\t.4byte _080349D4\n"
	"_080349D4:\t.4byte _080349F0 @ case 0\n"
	"\t.4byte _08034B14 @ case 1\n"
	"\t.4byte _08034EAC @ case 2\n"
	"\t.4byte _08034BF8 @ case 3\n"
	"\t.4byte _08034CE4 @ case 4\n"
	"\t.4byte _08034DA8 @ case 5\n"
	"\t.4byte _08034E88 @ case 6\n"
	"_080349F0:\tldr r4, [r5]\n"
	"\tmovs r3, #0xD1\n"
	"\tlsls r3, r3, #2\n"
	"\tadds r0, r4, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbne _08034A04\n"
	"\tb _08034EAC\n"
	"_08034A04:\tmovs r0, #0x13\n"
	"\tldrsb r0, [r4, r0]\n"
	"\tcmp r0, #2\n"
	"\tbgt _08034AA8\n"
	"\tldr r7, _08034A2C\n"
	"\tadds r1, r4, r7\n"
	"\tldrb r2, [r1]\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #2\n"
	"\tbgt _08034A34\n"
	"\tadds r0, r2, #1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, _08034A30\n"
	"\tstr r0, [r1, #0x3C]\n"
	"\tmovs r0, #0xDE\n"
	"\tbl m4aSongNumStart\n"
	"\tb _08034AC6\n"
	"_08034A2C:\t.4byte 0x345\n"
	"_08034A30:\t.4byte 0x4E20\n"
	"_08034A34:\tldr r2, _08034A98\n"
	"\tldrb r1, [r2, #0xF]\n"
	"\tmovs r0, #1\n"
	"\tmovs r3, #0\n"
	"\torrs r0, r1\n"
	"\tstrb r0, [r2, #0xF]\n"
	"\tadds r0, r4, #0\n"
	"\tadds r0, #0xEA\n"
	"\tmovs r2, #0\n"
	"\tstrh r3, [r0]\n"
	"\tadds r1, r4, #0\n"
	"\tadds r1, #0xEC\n"
	"\tmovs r0, #0xE6\n"
	"\tlsls r0, r0, #2\n"
	"\tstrh r0, [r1]\n"
	"\tadds r0, r4, #0\n"
	"\tadds r0, #0xE8\n"
	"\tstrh r3, [r0]\n"
	"\tsubs r0, #2\n"
	"\tstrh r3, [r0]\n"
	"\tadds r0, #8\n"
	"\tstrh r3, [r0]\n"
	"\tadds r0, #4\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0xFA\n"
	"\tmovs r1, #1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0xFB\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tldr r2, _08034A9C\n"
	"\tadds r0, r0, r2\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tmovs r4, #0xD2\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r0, r0, r4\n"
	"\tstrh r3, [r0]\n"
	"\tldr r0, _08034AA0\n"
	"\tbl m4aMPlayStop\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, _08034AA4\n"
	"\tstr r0, [r1, #0x3C]\n"
	"\tmovs r0, #0xDF\n"
	"\tbl m4aSongNumStart\n"
	"\tb _08034AC6\n"
	"_08034A98:\t.4byte gMain\n"
	"_08034A9C:\t.4byte 0x346\n"
	"_08034AA0:\t.4byte gMPlayInfo_BGM\n"
	"_08034AA4:\t.4byte 0x30D40\n"
	"_08034AA8:\tldr r7, _08034AF8\n"
	"\tadds r1, r4, r7\n"
	"\tldrb r2, [r1]\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #2\n"
	"\tbgt _08034AC6\n"
	"\tadds r0, r2, #1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r1, [r5]\n"
	"\tldr r0, _08034AFC\n"
	"\tstr r0, [r1, #0x3C]\n"
	"\tmovs r0, #0xDE\n"
	"\tbl m4aSongNumStart\n"
	"_08034AC6:\tldr r0, _08034B00\n"
	"\tldr r3, [r0]\n"
	"\tldr r1, _08034AF8\n"
	"\tadds r0, r3, r1\n"
	"\tldr r2, _08034B04\n"
	"\tmovs r1, #0\n"
	"\tldrsb r1, [r0, r1]\n"
	"\tlsls r0, r1, #4\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #6\n"
	"\tldr r1, _08034B08\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08034B0C\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08034B10\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tmovs r2, #0xD1\n"
	"\tlsls r2, r2, #2\n"
	"\tadds r3, r3, r2\n"
	"\tmovs r0, #0\n"
	"\tstrb r0, [r3]\n"
	"\tb _08034EAC\n"
	"\tmovs r0, r0\n"
	"_08034AF8:\t.4byte 0x345\n"
	"_08034AFC:\t.4byte 0x4E20\n"
	"_08034B00:\t.4byte gCurrentPinballGame\n"
	"_08034B04:\t.4byte 0x40000D4\n"
	"_08034B08:\t.4byte gHatchMachineElevator_Gfx\n"
	"_08034B0C:\t.4byte 0x600D900\n"
	"_08034B10:\t.4byte 0x80000220\n"
	"_08034B14:\tldr r0, [r5]\n"
	"\tmovs r3, #0xD2\n"
	"\tlsls r3, r3, #2\n"
	"\tadds r2, r0, r3\n"
	"\tldrh r1, [r2]\n"
	"\tldr r0, _08034B58\n"
	"\tcmp r1, r0\n"
	"\tbhi _08034B6C\n"
	"\tadds r0, r1, #0\n"
	"\tmovs r1, #0x3C\n"
	"\tbl __umodsi3\n"
	"\tlsls r0, r0, #0x10\n"
	"\tlsrs r0, r0, #0x10\n"
	"\tmovs r1, #0x1E\n"
	"\tbl __udivsi3\n"
	"\tadds r0, #4\n"
	"\tldr r2, _08034B5C\n"
	"\tlsls r0, r0, #0x10\n"
	"\tasrs r0, r0, #0x10\n"
	"\tlsls r1, r0, #4\n"
	"\tadds r1, r1, r0\n"
	"\tlsls r1, r1, #6\n"
	"\tldr r0, _08034B60\n"
	"\tadds r1, r1, r0\n"
	"\tstr r1, [r2]\n"
	"\tldr r0, _08034B64\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08034B68\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"\tb _08034B90\n"
	"\tmovs r0, r0\n"
	"_08034B58:\t.4byte 0x10D\n"
	"_08034B5C:\t.4byte 0x40000D4\n"
	"_08034B60:\t.4byte gHatchMachineElevator_Gfx\n"
	"_08034B64:\t.4byte 0x600D900\n"
	"_08034B68:\t.4byte 0x80000220\n"
	"_08034B6C:\tldr r1, _08034BDC\n"
	"\tmovs r2, #0\n"
	"\tldr r0, _08034BE0\n"
	"\tstr r0, [r1]\n"
	"\tldr r0, _08034BE4\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r0, _08034BE8\n"
	"\tstr r0, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"\tldr r0, [r5]\n"
	"\tldr r4, _08034BEC\n"
	"\tadds r0, r0, r4\n"
	"\tmovs r1, #2\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tldr r7, _08034BF0\n"
	"\tadds r0, r0, r7\n"
	"\tstrb r2, [r0]\n"
	"_08034B90:\tldr r0, [r5]\n"
	"\tmovs r4, #0xD2\n"
	"\tlsls r4, r4, #2\n"
	"\tadds r0, r0, r4\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, #0x3C\n"
	"\tbne _08034BD0\n"
	"\tmovs r0, #0x16\n"
	"\tbl m4aSongNumStart\n"
	"\tldr r0, [r5]\n"
	"\tmovs r1, #0xE5\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r2, #0\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tmovs r3, #0xF6\n"
	"\tlsls r3, r3, #1\n"
	"\tadds r0, r0, r3\n"
	"\tmovs r1, #5\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tldr r7, _08034BF4\n"
	"\tadds r1, r0, r7\n"
	"\tmovs r0, #0xC\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, [r5]\n"
	"\tmovs r1, #0xF8\n"
	"\tlsls r1, r1, #1\n"
	"\tadds r0, r0, r1\n"
	"\tstrh r2, [r0]\n"
	"_08034BD0:\tldr r1, [r5]\n"
	"\tadds r1, r1, r4\n"
	"\tldrh r0, [r1]\n"
	"\tadds r0, #1\n"
	"\tstrh r0, [r1]\n"
	"\tb _08034EAC\n"
	"_08034BDC:\t.4byte 0x40000D4\n"
	"_08034BE0:\t.4byte gHatchMachineElevator_Gfx\n"
	"_08034BE4:\t.4byte 0x600D900\n"
	"_08034BE8:\t.4byte 0x80000220\n"
	"_08034BEC:\t.4byte 0x346\n"
	"_08034BF0:\t.4byte 0x345\n"
	"_08034BF4:\t.4byte 0x1ED\n"
	"_08034BF8:\tldr r6, _08034C20\n"
	"\tldr r2, [r5]\n"
	"\tldr r4, _08034C24\n"
	"\tadds r3, r2, r4\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r1, r6, #2\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r7, #0\n"
	"\tldrsh r0, [r0, r7]\n"
	"\tmovs r1, #0xD2\n"
	"\tlsls r1, r1, #2\n"
	"\tadds r2, r2, r1\n"
	"\tldrh r1, [r2]\n"
	"\tcmp r0, r1\n"
	"\tble _08034C28\n"
	"\tadds r0, r1, #1\n"
	"\tstrh r0, [r2]\n"
	"\tb _08034C88\n"
	"_08034C20:\t.4byte gHoleAnimKeyframeData\n"
	"_08034C24:\t.4byte 0x345\n"
	"_08034C28:\tmovs r0, #0\n"
	"\tstrh r0, [r2]\n"
	"\tldrb r0, [r3]\n"
	"\tadds r0, #1\n"
	"\tstrb r0, [r3]\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _08034CA4\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0xA\n"
	"\tbne _08034C4A\n"
	"\tldr r3, _08034CA8\n"
	"\tadds r1, r1, r3\n"
	"\tmovs r0, #4\n"
	"\tstrb r0, [r1]\n"
	"_08034C4A:\tldr r0, [r5]\n"
	"\tadds r0, r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #6\n"
	"\tbne _08034C5E\n"
	"\tmovs r0, #0xE0\n"
	"\tbl m4aSongNumStart\n"
	"_08034C5E:\tldr r0, [r5]\n"
	"\tadds r0, r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r0, r6\n"
	"\tldr r2, _08034CAC\n"
	"\tmovs r4, #0\n"
	"\tldrsh r1, [r0, r4]\n"
	"\tlsls r0, r1, #4\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #6\n"
	"\tldr r1, _08034CB0\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08034CB4\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08034CB8\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"_08034C88:\tldr r1, [r5]\n"
	"\tldr r7, _08034CA4\n"
	"\tadds r0, r1, r7\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #5\n"
	"\tbgt _08034CBC\n"
	"\tmovs r0, #0x80\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r1, r1, r0\n"
	"\tsubs r0, #0xE8\n"
	"\tstr r0, [r1]\n"
	"\tb _08034EAC\n"
	"_08034CA4:\t.4byte 0x345\n"
	"_08034CA8:\t.4byte 0x346\n"
	"_08034CAC:\t.4byte 0x40000D4\n"
	"_08034CB0:\t.4byte gHatchMachineElevator_Gfx\n"
	"_08034CB4:\t.4byte 0x600D900\n"
	"_08034CB8:\t.4byte 0x80000220\n"
	"_08034CBC:\tmovs r2, #0x80\n"
	"\tlsls r2, r2, #2\n"
	"\tadds r3, r1, r2\n"
	"\tldr r2, [r3]\n"
	"\tadds r0, r2, #6\n"
	"\tstr r0, [r3]\n"
	"\tldr r4, _08034CE0\n"
	"\tadds r0, r1, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #4\n"
	"\tbeq _08034CD8\n"
	"\tb _08034EAC\n"
	"_08034CD8:\tadds r0, r2, #0\n"
	"\tadds r0, #0x1A\n"
	"\tstr r0, [r3]\n"
	"\tb _08034EAC\n"
	"_08034CE0:\t.4byte 0x346\n"
	"_08034CE4:\tldr r4, [r5]\n"
	"\tldr r7, _08034D94\n"
	"\tadds r0, r4, r7\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbeq _08034D84\n"
	"\tmovs r1, #0xD1\n"
	"\tlsls r1, r1, #2\n"
	"\tadds r0, r4, r1\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0\n"
	"\tbeq _08034D84\n"
	"\tldr r2, _08034D98\n"
	"\tldrb r1, [r2, #0xF]\n"
	"\tmovs r0, #1\n"
	"\tmovs r3, #0\n"
	"\torrs r0, r1\n"
	"\tstrb r0, [r2, #0xF]\n"
	"\tadds r0, r4, #0\n"
	"\tadds r0, #0xEA\n"
	"\tmovs r2, #0\n"
	"\tstrh r3, [r0]\n"
	"\tadds r1, r4, #0\n"
	"\tadds r1, #0xEC\n"
	"\tmovs r0, #0xA0\n"
	"\tstrh r0, [r1]\n"
	"\tadds r0, r4, #0\n"
	"\tadds r0, #0xE8\n"
	"\tstrh r3, [r0]\n"
	"\tsubs r0, #2\n"
	"\tstrh r3, [r0]\n"
	"\tadds r0, #8\n"
	"\tstrh r3, [r0]\n"
	"\tadds r0, #4\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0xFA\n"
	"\tmovs r4, #1\n"
	"\tstrb r4, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, #0xFB\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tldr r2, _08034D9C\n"
	"\tadds r0, r0, r2\n"
	"\tmovs r1, #5\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r7, #5\n"
	"\tadds r1, r0, r7\n"
	"\tstrh r3, [r1]\n"
	"\tldr r1, _08034DA0\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r1, #0xA\n"
	"\tstrb r1, [r0]\n"
	"\tmovs r0, #0xE0\n"
	"\tbl m4aSongNumStart\n"
	"\tldr r0, [r5]\n"
	"\tmovs r2, #0xF6\n"
	"\tlsls r2, r2, #1\n"
	"\tadds r0, r0, r2\n"
	"\tstrb r4, [r0]\n"
	"\tldr r2, [r5]\n"
	"\tmovs r3, #0xFA\n"
	"\tlsls r3, r3, #1\n"
	"\tadds r1, r2, r3\n"
	"\tmovs r0, #0x82\n"
	"\tlsls r0, r0, #4\n"
	"\tstrh r0, [r1]\n"
	"\tmovs r4, #0xFB\n"
	"\tlsls r4, r4, #1\n"
	"\tadds r1, r2, r4\n"
	"\tmovs r0, #0xF0\n"
	"\tlsls r0, r0, #2\n"
	"\tstrh r0, [r1]\n"
	"_08034D84:\tldr r0, _08034DA4\n"
	"\tldr r0, [r0]\n"
	"\tmovs r7, #0xD1\n"
	"\tlsls r7, r7, #2\n"
	"\tadds r0, r0, r7\n"
	"\tmovs r1, #0\n"
	"\tstrb r1, [r0]\n"
	"\tb _08034EAC\n"
	"_08034D94:\t.4byte 0x343\n"
	"_08034D98:\t.4byte gMain\n"
	"_08034D9C:\t.4byte 0x346\n"
	"_08034DA0:\t.4byte 0x345\n"
	"_08034DA4:\t.4byte gCurrentPinballGame\n"
	"_08034DA8:\tldr r6, _08034DD0\n"
	"\tldr r2, [r5]\n"
	"\tldr r4, _08034DD4\n"
	"\tadds r3, r2, r4\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r1, r6, #2\n"
	"\tadds r0, r0, r1\n"
	"\tmovs r1, #0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r7, #0xD2\n"
	"\tlsls r7, r7, #2\n"
	"\tadds r2, r2, r7\n"
	"\tldrh r1, [r2]\n"
	"\tcmp r0, r1\n"
	"\tble _08034DD8\n"
	"\tadds r0, r1, #1\n"
	"\tstrh r0, [r2]\n"
	"\tb _08034E24\n"
	"_08034DD0:\t.4byte gHoleAnimKeyframeData\n"
	"_08034DD4:\t.4byte 0x345\n"
	"_08034DD8:\tmovs r0, #0\n"
	"\tstrh r0, [r2]\n"
	"\tldrb r0, [r3]\n"
	"\tadds r0, #1\n"
	"\tstrb r0, [r3]\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _08034E68\n"
	"\tadds r0, r1, r2\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0xF\n"
	"\tbne _08034DFA\n"
	"\tldr r3, _08034E6C\n"
	"\tadds r1, r1, r3\n"
	"\tmovs r0, #6\n"
	"\tstrb r0, [r1]\n"
	"_08034DFA:\tldr r0, [r5]\n"
	"\tadds r0, r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tadds r0, r0, r6\n"
	"\tldr r2, _08034E70\n"
	"\tmovs r4, #0\n"
	"\tldrsh r1, [r0, r4]\n"
	"\tlsls r0, r1, #4\n"
	"\tadds r0, r0, r1\n"
	"\tlsls r0, r0, #6\n"
	"\tldr r1, _08034E74\n"
	"\tadds r0, r0, r1\n"
	"\tstr r0, [r2]\n"
	"\tldr r0, _08034E78\n"
	"\tstr r0, [r2, #4]\n"
	"\tldr r0, _08034E7C\n"
	"\tstr r0, [r2, #8]\n"
	"\tldr r0, [r2, #8]\n"
	"_08034E24:\tldr r0, _08034E80\n"
	"\tldr r1, [r0]\n"
	"\tldr r7, _08034E68\n"
	"\tadds r0, r1, r7\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tcmp r0, #0xE\n"
	"\tbne _08034E48\n"
	"\tmovs r2, #0xD2\n"
	"\tlsls r2, r2, #2\n"
	"\tadds r0, r1, r2\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, #0xA\n"
	"\tbne _08034E48\n"
	"\tmovs r0, #0xE1\n"
	"\tbl m4aSongNumStart\n"
	"_08034E48:\tldr r0, _08034E80\n"
	"\tldr r0, [r0]\n"
	"\tmovs r3, #0xFB\n"
	"\tlsls r3, r3, #1\n"
	"\tadds r1, r0, r3\n"
	"\tldrh r3, [r1]\n"
	"\tmovs r4, #0\n"
	"\tldrsh r0, [r1, r4]\n"
	"\tmovs r2, #0xAF\n"
	"\tlsls r2, r2, #2\n"
	"\tcmp r0, r2\n"
	"\tble _08034E84\n"
	"\tsubs r0, r3, #5\n"
	"\tstrh r0, [r1]\n"
	"\tb _08034EAC\n"
	"\tmovs r0, r0\n"
	"_08034E68:\t.4byte 0x345\n"
	"_08034E6C:\t.4byte 0x346\n"
	"_08034E70:\t.4byte 0x40000D4\n"
	"_08034E74:\t.4byte gHatchMachineElevator_Gfx\n"
	"_08034E78:\t.4byte 0x600D900\n"
	"_08034E7C:\t.4byte 0x80000220\n"
	"_08034E80:\t.4byte gCurrentPinballGame\n"
	"_08034E84:\tstrh r2, [r1]\n"
	"\tb _08034EAC\n"
	"_08034E88:\tldr r0, [r5]\n"
	"\tldr r7, _08034EF8\n"
	"\tadds r0, r0, r7\n"
	"\tmovs r2, #0\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tmovs r3, #0xD2\n"
	"\tlsls r3, r3, #2\n"
	"\tadds r1, r0, r3\n"
	"\tmovs r3, #0\n"
	"\tstrh r2, [r1]\n"
	"\tldr r4, _08034EFC\n"
	"\tadds r0, r0, r4\n"
	"\tstrb r3, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tsubs r7, #2\n"
	"\tadds r0, r0, r7\n"
	"\tstrb r3, [r0]\n"
	"_08034EAC:\tmovs r1, #0\n"
	"\tldr r0, _08034F00\n"
	"\tmov sb, r0\n"
	"\tldr r2, _08034F04\n"
	"\tmov sl, r2\n"
	"_08034EB6:\tlsls r1, r1, #0x10\n"
	"\tasrs r4, r1, #0x10\n"
	"\tmovs r0, #0xB8\n"
	"\tmuls r0, r4, r0\n"
	"\tldr r3, _08034F08\n"
	"\tadds r6, r0, r3\n"
	"\tldrh r0, [r6]\n"
	"\tmov r8, r1\n"
	"\tcmp r0, #0\n"
	"\tbne _08034ECC\n"
	"\tb _08034FEA\n"
	"_08034ECC:\tldr r5, _08034F0C\n"
	"\tldr r1, [r5]\n"
	"\tldr r7, _08034F10\n"
	"\tadds r0, r1, r7\n"
	"\tadds r3, r0, r4\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r3, r0]\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r2, _08034F14\n"
	"\tadds r0, r0, r2\n"
	"\tmovs r7, #0\n"
	"\tldrsh r2, [r0, r7]\n"
	"\tlsls r0, r4, #1\n"
	"\tldr r7, _08034F18\n"
	"\tadds r1, r1, r7\n"
	"\tadds r1, r1, r0\n"
	"\tldrh r0, [r1]\n"
	"\tcmp r2, r0\n"
	"\tble _08034F1C\n"
	"\tadds r0, #1\n"
	"\tstrh r0, [r1]\n"
	"\tb _08034F3C\n"
	"_08034EF8:\t.4byte 0x345\n"
	"_08034EFC:\t.4byte 0x346\n"
	"_08034F00:\t.4byte 0x40000D4\n"
	"_08034F04:\t.4byte gSplashEffectPositions\n"
	"_08034F08:\t.4byte gMain_spriteGroups_47\n"
	"_08034F0C:\t.4byte gCurrentPinballGame\n"
	"_08034F10:\t.4byte 0x355\n"
	"_08034F14:\t.4byte gSplashEffectTileIndices + 0x2\n"
	"_08034F18:\t.4byte 0x35E\n"
	"_08034F1C:\tmovs r2, #0\n"
	"\tstrh r2, [r1]\n"
	"\tldrb r0, [r3]\n"
	"\tadds r0, #1\n"
	"\tstrb r0, [r3]\n"
	"\tldr r0, [r5]\n"
	"\tldr r1, _08035008\n"
	"\tadds r0, r0, r1\n"
	"\tadds r1, r0, r4\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r1, r0]\n"
	"\tcmp r0, #6\n"
	"\tbne _08034F3C\n"
	"\tstrh r2, [r6]\n"
	"\tmovs r0, #5\n"
	"\tstrb r0, [r1]\n"
	"_08034F3C:\tldr r2, _0803500C\n"
	"\tldr r4, [r2]\n"
	"\tmov r7, r8\n"
	"\tasrs r3, r7, #0x10\n"
	"\tldr r1, _08035008\n"
	"\tadds r0, r4, r1\n"
	"\tadds r0, r0, r3\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, r0, #0x18\n"
	"\tasrs r0, r0, #0x18\n"
	"\tlsls r0, r0, #2\n"
	"\tldr r2, _08035010\n"
	"\tadds r0, r0, r2\n"
	"\tmovs r7, #0\n"
	"\tldrsh r0, [r0, r7]\n"
	"\tlsls r0, r0, #8\n"
	"\tldr r1, _08035014\n"
	"\tadds r0, r0, r1\n"
	"\tmov r1, sb\n"
	"\tstr r0, [r1]\n"
	"\tlsls r0, r3, #8\n"
	"\tldr r2, _08035018\n"
	"\tadds r0, r0, r2\n"
	"\tstr r0, [r1, #4]\n"
	"\tldr r0, _0803501C\n"
	"\tstr r0, [r1, #8]\n"
	"\tldr r0, [r1, #8]\n"
	"\tldr r7, _08035020\n"
	"\tadds r2, r4, r7\n"
	"\tadds r2, r2, r3\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r2, r0]\n"
	"\tlsls r0, r0, #2\n"
	"\tadd r0, sl\n"
	"\tadds r1, r4, #0\n"
	"\tadds r1, #0x58\n"
	"\tldrh r0, [r0]\n"
	"\tldrh r1, [r1]\n"
	"\tsubs r0, r0, r1\n"
	"\tstrh r0, [r6, #2]\n"
	"\tmovs r0, #0\n"
	"\tldrsb r0, [r2, r0]\n"
	"\tlsls r0, r0, #2\n"
	"\tadd r0, sl\n"
	"\tadds r4, #0x5A\n"
	"\tldrh r0, [r0, #2]\n"
	"\tldrh r1, [r4]\n"
	"\tsubs r0, r0, r1\n"
	"\tstrh r0, [r6, #4]\n"
	"\tmovs r0, #0\n"
	"\tldr r7, _08035024\n"
	"\tldr r1, _08035028\n"
	"\tmov ip, r1\n"
	"_08034FA6:\tlsls r3, r0, #0x10\n"
	"\tasrs r3, r3, #0x10\n"
	"\tlsls r5, r3, #3\n"
	"\tadds r5, #8\n"
	"\tadds r5, r6, r5\n"
	"\tldrh r2, [r5]\n"
	"\tlsls r2, r2, #3\n"
	"\tadds r2, r2, r7\n"
	"\tmovs r4, #2\n"
	"\tldrsh r1, [r5, r4]\n"
	"\tmovs r4, #2\n"
	"\tldrsh r0, [r6, r4]\n"
	"\tadds r1, r1, r0\n"
	"\tldr r4, _0803502C\n"
	"\tadds r0, r4, #0\n"
	"\tands r1, r0\n"
	"\tldrh r4, [r2, #2]\n"
	"\tmov r0, ip\n"
	"\tands r0, r4\n"
	"\torrs r0, r1\n"
	"\tstrh r0, [r2, #2]\n"
	"\tldrh r1, [r5]\n"
	"\tlsls r1, r1, #3\n"
	"\tadds r1, r1, r7\n"
	"\tldrb r0, [r6, #4]\n"
	"\tldrb r5, [r5, #4]\n"
	"\tadds r0, r0, r5\n"
	"\tstrb r0, [r1]\n"
	"\tadds r3, #1\n"
	"\tlsls r3, r3, #0x10\n"
	"\tlsrs r0, r3, #0x10\n"
	"\tasrs r3, r3, #0x10\n"
	"\tcmp r3, #2\n"
	"\tble _08034FA6\n"
	"_08034FEA:\tmovs r0, #0x80\n"
	"\tlsls r0, r0, #9\n"
	"\tadd r0, r8\n"
	"\tlsrs r1, r0, #0x10\n"
	"\tasrs r0, r0, #0x10\n"
	"\tcmp r0, #3\n"
	"\tbgt _08034FFA\n"
	"\tb _08034EB6\n"
	"_08034FFA:\tpop {r3, r4, r5}\n"
	"\tmov r8, r3\n"
	"\tmov sb, r4\n"
	"\tmov sl, r5\n"
	"\tpop {r4, r5, r6, r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"_08035008:\t.4byte 0x355\n"
	"_0803500C:\t.4byte gCurrentPinballGame\n"
	"_08035010:\t.4byte gSplashEffectTileIndices\n"
	"_08035014:\t.4byte gHatchMachineSparkleFx_Gfx\n"
	"_08035018:\t.4byte 0x60140A0\n"
	"_0803501C:\t.4byte 0x80000080\n"
	"_08035020:\t.4byte 0x359\n"
	"_08035024:\t.4byte gOamBuffer\n"
	"_08035028:\t.4byte 0xFFFFFE00\n"
	"_0803502C:\t.4byte 0x1FF\n"
    );
}
#else
void UpdateSapphireHatchMachine(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    switch (gCurrentPinballGame->sapphireHatchMachineState)
    {
    case HATCH_MACHINE_STATE_INCUBATION_LIGHTS:
        if (gCurrentPinballGame->hatchMachineProgressTickSignaled)
        {
            if (BoardNotInActivityMode)
            {
                if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 3)
                {
                    gCurrentPinballGame->sapphireHatchMachineFrameIx++;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_HATCH_MACHINE_STAGE_ADVANCE;
                    m4aSongNumStart(SE_HATCH_MACHINE_STAGE_ADVANCE);
                }
                else
                {
                    gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                    gCurrentPinballGame->bannerDelayTimer = 0;
                    gCurrentPinballGame->bannerDisplayTimer = 920;
                    gCurrentPinballGame->cameraYScrollTarget = 0;
                    gCurrentPinballGame->cameraYAdjust = 0;
                    gCurrentPinballGame->cameraYScrollSpeed = 0;
                    gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
                    gCurrentPinballGame->bannerActive = TRUE;
                    gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
                    gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_ACTIVATED_LIGHT_CROSS;
                    gCurrentPinballGame->holeAnimFrameCounter = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_HATCH_MACHINE_EGG_HATCH;
                    m4aSongNumStart(SE_HATCH_MACHINE_EGG_HATCH);
                }
            }
            else
            {
                if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 3)
                {
                    gCurrentPinballGame->sapphireHatchMachineFrameIx++;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_HATCH_MACHINE_STAGE_ADVANCE;
                    m4aSongNumStart(SE_HATCH_MACHINE_STAGE_ADVANCE);
                }
            }

            index = gCurrentPinballGame->sapphireHatchMachineFrameIx;
            DmaCopy16(3, &gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
            gCurrentPinballGame->hatchMachineProgressTickSignaled = FALSE;
        }
        break;
    case HATCH_MACHINE_STATE_ACTIVATED_LIGHT_CROSS:
        if (gCurrentPinballGame->holeAnimFrameCounter < 270)
        {
            index = (gCurrentPinballGame->holeAnimFrameCounter % 60) / 30 + 4;
            DmaCopy16(3, &gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        }
        else
        {
            index = 0;
            DmaCopy16(3, &gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
            gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_MON_HATCHED;
            gCurrentPinballGame->sapphireHatchMachineFrameIx = 0;
        }

        if (gCurrentPinballGame->holeAnimFrameCounter == 60)
        {
            m4aSongNumStart(MUS_EGG_MODE_START);
            gCurrentPinballGame->catchArrowPaletteActive = FALSE;
            gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_HATCH_SHAKES;
            gCurrentPinballGame->eggAnimFrameIndex = 12;
            gCurrentPinballGame->eggFrameTimer = 0;
        }

        gCurrentPinballGame->holeAnimFrameCounter++;
        break;
    case HATCH_MACHINE_STATE_ELEVATOR_DECENDS:
        if (gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx++;
            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 10)
                gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_EMPTY;

            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 6)
                m4aSongNumStart(SE_HATCH_MACHINE_ELEVATOR);

            index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
            DmaCopy16(3, &gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        }

        if (gCurrentPinballGame->sapphireHatchMachineFrameIx < 6)
        {
            gCurrentPinballGame->walkMonYPos = 280;
        }
        else
        {
            gCurrentPinballGame->walkMonYPos += 6;
            if (gCurrentPinballGame->sapphireHatchMachineState == HATCH_MACHINE_STATE_EMPTY)
                gCurrentPinballGame->walkMonYPos = gCurrentPinballGame->walkMonYPos + 20;
        }
        break;
    case HATCH_MACHINE_STATE_EMPTY:
        if (gCurrentPinballGame->sapphireReadyForNewEgg && gCurrentPinballGame->hatchMachineProgressTickSignaled)
        {
            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
            gCurrentPinballGame->bannerDelayTimer = 0;
            gCurrentPinballGame->bannerDisplayTimer = 160;
            gCurrentPinballGame->cameraYScrollTarget = 0;
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->cameraYScrollSpeed = 0;
            gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
            gCurrentPinballGame->bannerActive = TRUE;
            gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
            gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_EGG_RISING;
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx = 10;
            m4aSongNumStart(SE_HATCH_MACHINE_ELEVATOR);
            gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_STILL;
            gCurrentPinballGame->portraitOffsetX = 2080;
            gCurrentPinballGame->portraitOffsetY = 960;
        }

        gCurrentPinballGame->hatchMachineProgressTickSignaled = FALSE;
        break;
    case HATCH_MACHINE_STATE_EGG_RISING:
        if (gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][1] > gCurrentPinballGame->holeAnimFrameCounter)
        {
            gCurrentPinballGame->holeAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->holeAnimFrameCounter = 0;
            gCurrentPinballGame->sapphireHatchMachineFrameIx++;
            if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 15)
                gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_RESET;

            index = gHoleAnimKeyframeData[gCurrentPinballGame->sapphireHatchMachineFrameIx][0];
            DmaCopy16(3, gHatchMachineElevator_Gfx[index], BG_VRAM_ADDR_HATCH_MACHINE_ALL_TILES, SIZE_OF_VRAM_HATCH_MACHINE_ALL_TILES);
        }

        if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 14 && gCurrentPinballGame->holeAnimFrameCounter == 10)
            m4aSongNumStart(SE_HATCH_MACHINE_ELEVATOR_TOP);

        if (gCurrentPinballGame->portraitOffsetY > 700)
            gCurrentPinballGame->portraitOffsetY -= 5;
        else
            gCurrentPinballGame->portraitOffsetY = 700;
        break;
    case HATCH_MACHINE_STATE_RESET:
        gCurrentPinballGame->sapphireHatchMachineFrameIx = 0;
        gCurrentPinballGame->holeAnimFrameCounter = 0;
        gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_INCUBATION_LIGHTS;
        gCurrentPinballGame->sapphireReadyForNewEgg = FALSE;
        break;
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[SG_SAPPHIRE_HATCH_MACHINE_LIGHT_SPARK_FX_BASE + i];
        if (group->active)
        {
            if (gSplashEffectTileIndices[gCurrentPinballGame->splashEffectFrameIndex[i]][1] > gCurrentPinballGame->splashEffectFrameTimer[i])
            {
                gCurrentPinballGame->splashEffectFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->splashEffectFrameTimer[i] = 0;
                gCurrentPinballGame->splashEffectFrameIndex[i]++;
                if (gCurrentPinballGame->splashEffectFrameIndex[i] == 6)
                {
                    group->active = FALSE;
                    gCurrentPinballGame->splashEffectFrameIndex[i] = 5;
                }
            }

            index = gSplashEffectTileIndices[gCurrentPinballGame->splashEffectFrameIndex[i]][0];
            DmaCopy16(3, &gHatchMachineSparkleFx_Gfx[index], OBJ_VRAM_ADDR_HATCH_MACHINE_SPARKLE_FX_TILES + i* SIZE_OF_HATCH_MACHINE_SPARKLE_FX_TILES, SIZE_OF_HATCH_MACHINE_SPARKLE_FX_TILES);
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
#endif
