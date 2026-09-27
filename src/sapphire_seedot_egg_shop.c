#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/sapphire.h"

extern const u16 gEggOamFramestates[40][2][3];
extern const u16 gSeedotBasketBounceFrames[];
extern const u8 gSapphireStageBasket_Gfx[][0x280];
extern const u8 gSapphireBoardSeedot_Gfx[][0x180];
extern const u16 gSeedotBaseXPositions[];
extern const u16 gSapphireBoardSeedotSpritesheetOam[6][6][2][3];
extern const u16 gShopSignTransitionFrames[][14];
extern const u16 gShopSignIntroFrames[][4];
extern const u16 gShopSignLoopFrames[][5];

extern const s16 gHoleAnimKeyframeData[][2];
extern const u8 gHatchMachineElevator_Gfx[][0x440];

extern const u8 gHatchMachineSparkleFx_Gfx[][0x100];
extern struct Vector16 gSplashEffectPositions[];
extern const s16 gSplashEffectTileIndices[][2];
extern const Palette gSapphireShopSign_Pals[];
extern const u8 gSapphireShopSignTileGfx[][0x480];


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
                DmaCopy16(3, gModeBannerTilemaps[4], OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_MODE_BANNER_LOAD_TILES);
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
        DmaCopy16(3, gSapphireShopSignTileGfx[gCurrentPinballGame->sapphireShopSignFrame], OBJ_VRAM_ADDR_SAPPHIRE_MART_SIGN_TILES, SIZE_OF_SAPPHIRE_MART_SIGN_TILES);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

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
