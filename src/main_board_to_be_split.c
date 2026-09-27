#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/board/ruby_states.h"
#include "constants/board/sapphire_states.h"
#include "constants/mem_layout/ruby.h"

#define HATCH_MODE_SAVER_TIME TICKS_FOR_TIME(0,30)

extern const s16 gEggHatchAnimData[28][3];
extern const u8 gHatchedWalkerAnimTileBuffer[][SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES];
extern const struct Vector32 gSapphireEggWaypoints[];
extern const struct Vector32 gEggWalkPathWaypoints[][29];
extern const Palette gCaptureHit_Pal;
extern const u8 gCaptureScreenTilesGfx[];
extern const u8 gCaptureBallTilesGfx[];
extern const u16 gCatchCreatureOamFramesets[48][4][3];
extern const u16 gCyndaquilFrameIndices[];
extern const struct Vector16 gCyndaquilCavePositions[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u16 gEggOamFramestates[40][2][3];
extern const u8 gSpaceTileGfx[0x40];
extern const u8 gAlphabetTilesGfx[][0x40];
extern const s16 gCaughtTextChars[];
extern const struct Vector16 gFlyingCreatureCameraOffsets[];
extern const u16 gAerodactylEggDeliveryCutsceneFramesets[14][15];
extern const u8 gAerodactlyFlight_Gfx[];
extern const Palette gAerodactlyFlight_Pal;
extern const u16 gPikaSaverFrameData[][2];
extern const u16 gTotodileEggDeliveryCutsceneFramesets[82][6][3];
extern const Palette gTotodile_Pal;
extern const u8 gTotodileEggDelivery_Gfx[];
extern const u16 gCoinRewardAnimOamFramesets[18][3];
extern const u16 gShopNumberOamFramesets[4][15];
extern const s16 gArrowBounceOffsets[];
extern const s16 gTimerIndicatorFrames[];
extern const u8 gShopPortraitOverlayGfx[][0x300];
extern const u8 gDecimalDigitTilesGfx[][0x40];
extern const s16 gEvoShopAnimFrames[][7];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const Palette gRubyShopSign_Pal;

extern const u16 gAngleToDirectionTable[];

extern u8 gCatchSpritePaletteBuffer[];

// This is the 'Gravity Well' in the center of the board.
// Used with travel confirmation, bonus board entry, roulette, etc

void ResetCatchState(s16 resetHoleIndicators)
{
    if (resetHoleIndicators)
    {
        gCurrentPinballGame->allHolesLit = FALSE;
        gCurrentPinballGame->holeIndicators[0] = FALSE;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    }

    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = FALSE;
    if (gCurrentPinballGame->boardTransitionPhase != BOARD_STATE_DISPATCHER_STATE_CHANGING
        || gCurrentPinballGame->nextBoardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
    {
        if ((gCurrentPinballGame->jirachiActivationFlags & 0xF) == 0)
        {
            LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
        }
    }

    if (gCurrentPinballGame->nextBoardState == MAIN_BOARD_STATE_EVO_MODE
        && gCurrentPinballGame->boardTransitionPhase == BOARD_STATE_DISPATCHER_STATE_CHANGING)
        gCurrentPinballGame->shopDoorTargetFrame = 0;
}

void InitCatchTrigger(void)
{
    gCurrentPinballGame->boardSubState = BONUS_HOLE_SUBSTATE_OPEN_TRAP_DOOR;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->prizeSelected = FALSE;
}

void UpdateCatchTrigger(void)
{
    switch (gCurrentPinballGame->boardSubState)
    {
    case BONUS_HOLE_SUBSTATE_OPEN_TRAP_DOOR:
        if (gCurrentPinballGame->stageTimer < 9)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer < 8)
            {
                gCurrentPinballGame->trapAnimState = 1;
            }
            else if (gCurrentPinballGame->stageTimer == 8)
            {
                ShowBonusTrapSprite();
                gCurrentPinballGame->trapAnimState = 2;
                gCurrentPinballGame->portraitCycleFrame = 0;
                LoadPortraitGraphics(PORTRAIT_STATE_SLOT_START_CARD, PORTRAIT_MAIN_SLOT);
                gCurrentPinballGame->boardSubState++;
            }
        }
        break;
    case BONUS_HOLE_SUBSTATE_GRAVITY_WELL:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == NOT_TRAPPED)
            LoadPortraitGraphics(PORTRAIT_STATE_SLOT_START_CARD, PORTRAIT_MAIN_SLOT);

        if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
            gCurrentPinballGame->boardSubState++;
        break;
    case BONUS_HOLE_SUBSTATE_START_ROULETTE:
        gCurrentPinballGame->allHolesLit = FALSE;
        gCurrentPinballGame->holeIndicators[0] = FALSE;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->boardSubState++;
        InitRouletteWheel();
        if (gCurrentPinballGame->slotsPlayedCount < 99)
            gCurrentPinballGame->slotsPlayedCount++;
        break;
    case BONUS_HOLE_SUBSTATE_RUN_ROULETTE:
        if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->modeAnimTimer++;
            RunRouletteWheel();
        }
        else if (gCurrentPinballGame->modeAnimTimer == 139)
        {
        }
        else if (gCurrentPinballGame->modeAnimTimer == 24)
        {
            LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
        }
        else if (gCurrentPinballGame->modeAnimTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
        }

        if (gCurrentPinballGame->prizeSelected)
        {
            GivePrize();
            if (gCurrentPinballGame->outcomeFrameCounter < 180)
            {
                gCurrentPinballGame->modeAnimTimer = 140;
                if (gCurrentPinballGame->outcomeFrameCounter == 179)
                    gCurrentPinballGame->modeAnimTimer = 30;
            }
        }

        gCurrentPinballGame->stageTimer = 0;
        break;
    case BONUS_HOLE_SUBSTATE_START_CLOSING:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
        gCurrentPinballGame->boardSubState++;
        break;
    case BONUS_HOLE_SUBSTATE_BOARD_STATE_CLEANUP:
        ResetCatchState(1);
        gCurrentPinballGame->boardSubState++;
        break;
    case BONUS_HOLE_SUBSTATE_RETURN_TO_DEFAULT_TIMER:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
        break;
    }
}

void FullCatchStateCleanup(void)
{
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = FALSE;
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    gCurrentPinballGame->monProgressTowardsBonusCount = 0;
    gCurrentPinballGame->modeProgressBlinkTimer = 0;
    gCurrentPinballGame->modeProgressLights[MODE_LAMP_LEFT] = MODE_PROGRESS_LAMP_BALL_UNLIT;
    gCurrentPinballGame->modeProgressLights[MODE_LAMP_CENTER] = MODE_PROGRESS_LAMP_BALL_UNLIT;
    gCurrentPinballGame->modeProgressLights[MODE_LAMP_RIGHT] = MODE_PROGRESS_LAMP_BALL_UNLIT;
}

void InitBonusStageSelect(void)
{
    if (gMain.selectedField == FIELD_RUBY)
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % BONUS_STAGE_LOOP_COUNT)
        {
        case BONUS_STAGE_LOOP_START:
        case BONUS_STAGE_LOOP_FIRST_BOSS_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 42;
            gCurrentPinballGame->nextBonusField = FIELD_KECLEON;
            break;
        case BONUS_STAGE_LOOP_FIRST_SIMPLE_CLEARED:
        case BONUS_STAGE_LOOP_SECOND_SIMPLE_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 44;
            gCurrentPinballGame->nextBonusField = FIELD_GROUDON;
            break;
        case BONUS_STAGE_LOOP_SECOND_BOSS_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 45;
            gCurrentPinballGame->nextBonusField = FIELD_RAYQUAZA;
            break;
        }
    }
    else
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % BONUS_STAGE_LOOP_COUNT)
        {
        case BONUS_STAGE_LOOP_START:
        case BONUS_STAGE_LOOP_FIRST_BOSS_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 41;
            gCurrentPinballGame->nextBonusField = FIELD_DUSCLOPS;
            break;
        case BONUS_STAGE_LOOP_FIRST_SIMPLE_CLEARED:
        case BONUS_STAGE_LOOP_SECOND_SIMPLE_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 43;
            gCurrentPinballGame->nextBonusField = FIELD_KYOGRE;
            break;
        case BONUS_STAGE_LOOP_SECOND_BOSS_CLEARED:
            gCurrentPinballGame->modeOutcomeValues[0] = 45;
            gCurrentPinballGame->nextBonusField = FIELD_RAYQUAZA;
            break;
        }
    }

    if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE
        && gCurrentPinballGame->prevBoardState == MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
    {
        gCurrentPinballGame->modeAnimTimer = 150;
        gCurrentPinballGame->boardSubState = BOSS_HOLE_SUBSTATE_DISPLAY_CONFIRMATION;
        gCurrentPinballGame->stageTimer = 0;
    }
    else
    {
        gCurrentPinballGame->boardSubState = BOSS_HOLE_SUBSTATE_INIT_DELAY;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
    }
}

void UpdateBonusStageSelect(void)
{
    switch (gCurrentPinballGame->boardSubState)
    {
    case BOSS_HOLE_SUBSTATE_INIT_DELAY:
        if (gCurrentPinballGame->stageTimer < 60)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState++;
        }
        break;
    case BOSS_HOLE_SUBSTATE_OPEN_TRAP_DOOR:
        if (gCurrentPinballGame->stageTimer < 9)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer < 8)
            {
                gCurrentPinballGame->trapAnimState = 1;
            }
            else if (gCurrentPinballGame->stageTimer == 8)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % BONUS_STAGE_LOOP_COUNT)
                {
                case BONUS_STAGE_LOOP_START:
                case BONUS_STAGE_LOOP_FIRST_BOSS_CLEARED:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case BONUS_STAGE_LOOP_FIRST_SIMPLE_CLEARED:
                case BONUS_STAGE_LOOP_SECOND_SIMPLE_CLEARED:
                case BONUS_STAGE_LOOP_SECOND_BOSS_CLEARED:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }

                ShowBonusTrapSprite();
                gCurrentPinballGame->trapAnimState = 2;
                gCurrentPinballGame->boardSubState++;
                gCurrentPinballGame->portraitCycleFrame = 0;
            }
        }
        break;
    case BOSS_HOLE_SUBSTATE_GRAVITY_WELL:
        AnimateBonusTrapSprite();
        LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
        if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
            gCurrentPinballGame->boardSubState++;
        break;
    case BOSS_HOLE_SUBSTATE_DISPLAY_CONFIRMATION:
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        gCurrentPinballGame->modeOutcomeValues[0] = 46;
        LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
        break;
    case BOSS_HOLE_SUBSTATE_AWAIT_CONFIRMATION:
        if (gCurrentPinballGame->modeAnimTimer == 145)
        {
            //Adds timer tick back, to ensure we wait for player input
            gCurrentPinballGame->modeAnimTimer++;
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->modeAnimTimer = 144;
                m4aMPlayAllStop();
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->modeAnimTimer = 60;
                gCurrentPinballGame->boardSubState = BOSS_HOLE_SUBSTATE_CANCEL_BONUS;
                if (gCurrentPinballGame->allHolesLit)
                    gCurrentPinballGame->allHolesLitDelayTimer = 120;
            }

            gCurrentPinballGame->modeOutcomeValues[0] = 46;
            LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
        }

        if (gCurrentPinballGame->modeAnimTimer == 130)
        {
            m4aSongNumStart(SE_WARP);
            gCurrentPinballGame->stageTimer = 65;
            gMain.blendControl = 0x9F;
        }

        if (gCurrentPinballGame->modeAnimTimer == 125)
            gCurrentPinballGame->modeAnimTimer++;

        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->startButtonDisabled = TRUE;
            gCurrentPinballGame->stageTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->stageTimer / 4;
            if (gCurrentPinballGame->stageTimer == 0)
                gCurrentPinballGame->boardSubState++;
        }
        break;
    case BOSS_HOLE_SUBSTATE_PREPARE_BONUS_TRANSFER:
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
            gCurrentPinballGame->bonusReturnState = BONUS_RETURN_LOCATION_CENTER_KICKOUT;
            TransitionToBonusField();
        }
        break;
    case BOSS_HOLE_SUBSTATE_CANCEL_BONUS:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        break;
    case BOSS_HOLE_SUBSTATE_BOARD_STATE_CLEANUP:
        FullCatchStateCleanup();
        gCurrentPinballGame->boardSubState++;
        break;
    case BOSS_HOLE_SUBSTATE_RETURN_TO_DEFAULT:
        RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
        break;
    }
}

void ShowBonusTrapSprite(void)
{
    DmaCopy16(3, gMainStageBonusTrap_Gfx[0], OBJ_VRAM_ADDR_FX_CENTER_HOLE_GRAVITY_TILES, SIZE_OF_VRAM_FX_CENTER_HOLE_GRAVITY_TILES);
    gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = TRUE;
    gCurrentPinballGame->bonusTrapEnabled = TRUE;
}

void AnimateBonusTrapSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX];
    gCurrentPinballGame->bonusTrapAnimFrame = (gCurrentPinballGame->globalAnimFrameCounter % 35) / 7;
    if (group->active)
    {
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 280 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        if (gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE)
        {
            group->baseY = 200;
        }
        else
        {
            if (gCurrentPinballGame->bonusTrapAnimFrame != gCurrentPinballGame->prevBonusTrapFrame)
            {
                DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->bonusTrapAnimFrame], OBJ_VRAM_ADDR_FX_CENTER_HOLE_GRAVITY_TILES, SIZE_OF_VRAM_FX_CENTER_HOLE_GRAVITY_TILES);
                gCurrentPinballGame->prevBonusTrapFrame = gCurrentPinballGame->bonusTrapAnimFrame;
            }
        }

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void ProcessChargeIndicator(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 chargeLevelIx;
    s16 sp0[3];

    group = gMain.fieldSpriteGroups[FIELD_SG_CHARGE_INDICATOR_DEVICE];
    memset(sp0, 0, sizeof(sp0));
    if (gCurrentPinballGame->chargeFillValue != gCurrentPinballGame->prevChargeFillValue)
    {
        if (gCurrentPinballGame->chargeFillValue == 12) {
            if (gCurrentPinballGame->chargeFillAnimTimer)
            {
                gCurrentPinballGame->chargeFillAnimTimer--;
                chargeLevelIx = ((gCurrentPinballGame->chargeFillAnimTimer % 20) / 10) + 12;
                if (gCurrentPinballGame->chargeFillAnimTimer < 41)
                {
                    if (gCurrentPinballGame->chargeFillAnimTimer > 2)
                    {
                        gCurrentPinballGame->chargeIndicatorXOffset += 3;
                        gCurrentPinballGame->chargeIndicatorYOffset += 2;
                    }

                    gCurrentPinballGame->chargeIndicatorScaleX = gCurrentPinballGame->chargeIndicatorScaleY = ((gCurrentPinballGame->chargeFillAnimTimer * 128) / 40) + 128;
                    sp0[1] =  ((40 - gCurrentPinballGame->chargeFillAnimTimer) * 16) / 40;
                    sp0[0] = -((40 - gCurrentPinballGame->chargeFillAnimTimer) * 16) / 40;
                    sp0[2] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                chargeLevelIx = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
            }

            DmaCopy16(3, gChargeFillIndicator_Gfx[chargeLevelIx], OBJ_VRAM_ADDR_CHARGE_INDICATOR_CIRCLE_TILES, SIZE_OF_VRAM_CHARGE_INDICATOR_CIRCLE_TILES);
        }
        else
        {
            DmaCopy16(3, gChargeFillIndicator_Gfx[gCurrentPinballGame->chargeFillValue], OBJ_VRAM_ADDR_CHARGE_INDICATOR_CIRCLE_TILES, SIZE_OF_VRAM_CHARGE_INDICATOR_CIRCLE_TILES);
            gCurrentPinballGame->prevChargeFillValue = gCurrentPinballGame->chargeFillValue;
        }
    }

    if (gCurrentPinballGame->fullChargeSlideAnimTimer)
    {
        gCurrentPinballGame->fullChargeSlideAnimTimer--;
        group->baseY = 80 + gCurrentPinballGame->chargeIndicatorYOffset;
        if (gCurrentPinballGame->fullChargeSlideAnimTimer < 20)
            gCurrentPinballGame->chargeIndicatorScaleY = (gCurrentPinballGame->fullChargeSlideAnimTimer * 12) + 16;
    }
    else
    {
        group->baseY = 180;
    }

    group->baseX = 119 + gCurrentPinballGame->chargeIndicatorXOffset;
    SetMatrixScale(gCurrentPinballGame->chargeIndicatorScaleX, gCurrentPinballGame->chargeIndicatorScaleY, 1);
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + sp0[i];
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
        gOamBuffer[oamSimple->oamId].matrixNum = 1;
    }
}

void UpdateRubyEvolutionShopSignSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[SG_RUBY_SHOP_SIGN_CHANGE];
    if (!gCurrentPinballGame->shopTransitionActive)
    {
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
        else if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_EVO_MODE
            && gCurrentPinballGame->evolutionShopActive == TRUE
            && gCurrentPinballGame->ballCatchState != TRAP_CENTER_HOLE)
        {
            gCurrentPinballGame->shopTransitionActive = TRUE;
            gCurrentPinballGame->shopAnimTimer = 0;
            gCurrentPinballGame->evolutionShopActive = FALSE;
        }
    }
    else
    {
        index = gEvoShopAnimFrames[gCurrentPinballGame->evolutionShopActive][(gCurrentPinballGame->shopAnimTimer % 42) / 6];
        if (gCurrentPinballGame->shopAnimTimer == 0)
        {
            group->active = TRUE;
            DmaCopy16(3, gRubyShopSign_Pal, OBJ_PLTT_SLOT(PAL_IX_RUBY_SHOP_SIGN), PLTT_SLOT_SIZE);
        }
        else if (gCurrentPinballGame->shopAnimTimer == 37)
        {
            m4aSongNumStart(SE_RUBY_MART_SIGN_CHANGED);
        }

        if (gCurrentPinballGame->shopAnimTimer % 6 == 0)
        {
            DmaCopy16(3, gRubyBoardShop_Gfx[index], OBJ_VRAM_ADDR_RUBY_MART_SIGN_TILES, SIZE_OF_VRAM_RUBY_MART_SIGN_TILES);
        }

        group->baseX = 181 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 48 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY < -50)
            group->baseY = -50;

        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->shopAnimTimer++;
        if (gCurrentPinballGame->shopAnimTimer > 40)
        {
            LoadShopItemGraphics(gCurrentPinballGame->evolutionShopActive);
            gCurrentPinballGame->shopTransitionActive = FALSE;
            gMain.spriteGroups[SG_RUBY_SHOP_SIGN_CHANGE].active = FALSE;
        }
    }
}

void RenderMartUI(s16 showPrice)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *var1;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 sp0[2];
    s16 sp4[2];

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_COINS];
    var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
    if (showPrice)
    {
        index = LEAD_DIGIT_10S(var1[3]);
        DmaCopy16(3, gDecimalDigitTilesGfx[index], OBJ_VRAM_ADDR_MART_PRICE_TENS_DIGIT_TILES, SIZE_OF_VRAM_MART_PRICE_DIGIT);
        index = DIGIT_1S(var1[3]);
        DmaCopy16(3, gDecimalDigitTilesGfx[index], OBJ_VRAM_ADDR_MART_PRICE_ONES_DIGIT_TILES, SIZE_OF_VRAM_MART_PRICE_DIGIT);
    }

    if (group->active)
    {
        group->baseX = 156 + gCurrentPinballGame->shopUISlideOffset;
        group->baseY = 96;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_CONFIRMATION_PANEL];
    index = gCurrentPinballGame->evolutionShopActive ? 1 : 0;
    if (group->active)
    {
        group->baseX = (gCurrentPinballGame->shopUISlideOffset + 136);
        group->baseY = 88;
        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 0];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 1];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_ARROWS];
    if (group->active)
    {
        if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        sp0[0] = -gArrowBounceOffsets[(gMain.systemFrameCount % 30) / 5];
        sp0[1] = gArrowBounceOffsets[(gMain.systemFrameCount % 30) / 5];
        sp4[0] = sp0[0];
        sp4[1] = sp0[1];
        if (!gCurrentPinballGame->evolutionShopActive)
        {
            for (i = 0; i < 4; i++)
            {
                s16 i2 = i / 2;
                group->baseX = i2 * 24 + 36 + sp0[i2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else if (gCurrentPinballGame->evolvablePartySize > 1)
        {
            for (i = 0; i < 4; i++)
            {
                group->baseX = (i / 2) * 24 + 36 + sp0[i / 2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 0;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
        }

        if (!gCurrentPinballGame->evolutionShopActive)
            group->baseY = 180;
        else if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        group->baseX = 48;
        if (gCurrentPinballGame->evoChainPosition < gCurrentPinballGame->evoChainMaxStage)
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[0];
        }
        else
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }

        if (gCurrentPinballGame->evoChainPosition > 0)
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[1];
        }
        else
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_PORTRAIT_OVERLAY];
    if (group->active)
    {
        group->baseX = 48;
        if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 88;

        if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_EXTRA_BALL)
        {
            if (gCurrentPinballGame->shopExtraBallPreviouslyPurchased
                && gCurrentPinballGame->shopAnimSlideTimer / 5 == 0)
                index = 4;
            else
                index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }
        else if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_PICHU_SAVER)
        {
            if (gCurrentPinballGame->shopPikaSaverMaxed && gCurrentPinballGame->shopAnimSlideTimer / 5 == 0)
                index = 4;
            else
                index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }
        else
        {
            index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }

        // Used for change selection sheen, sold out banner/greying
        DmaCopy16(3, gShopPortraitOverlayGfx[index], OBJ_VRAM_ADDR_MART_EVO_SELECTION_CHANGE_TILES, SIZE_OF_VRAM_MART_EVO_SELECTION_CHANGE_TILES);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void AnimateCoinReward(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int var1;
    s16 var2;

    group = gMain.fieldSpriteGroups[FIELD_SG_COIN_COLLECTED];
    if (gCurrentPinballGame->coinRewardTimer < ((gCurrentPinballGame->coinRewardAmount - 1) * 9) + 19)
    {
        if (gCurrentPinballGame->coinRewardTimer == 0)
        {
            group->active = TRUE;
            gCurrentPinballGame->coinsAwarded = 0;
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->coinBounceTimer[i] = 0;
                gCurrentPinballGame->coinSpritePos[i].x = 70;
                gCurrentPinballGame->coinSpritePos[i].y = 180;
            }

            gCurrentPinballGame->coinRewardFastPayout = FALSE;
        }
        else
        {
            if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE
                && (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]
                    || JOY_NEW(A_BUTTON)))
                gCurrentPinballGame->coinRewardFastPayout = TRUE;

            if (gCurrentPinballGame->coinsAwarded < gCurrentPinballGame->coinRewardAmount)
            {
                var1 = gCurrentPinballGame->coinRewardTimer - 1;
                if (var1 % 9 == 0)
                {
                    if (gCurrentPinballGame->coinRewardFastPayout)
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinBounceTimer[var2] = 17;
                        gCurrentPinballGame->coinSpritePos[var2].x = 188;
                        gCurrentPinballGame->coinSpritePos[var2].y = 140;
                        m4aSongNumStart(SE_COIN_COLLECTED);
                        gCurrentPinballGame->coins += gCurrentPinballGame->coinRewardAmount - gCurrentPinballGame->coinsAwarded;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->coinRewardAmount - gCurrentPinballGame->coinsAwarded) * SCORE_COIN_COLLECTED;
                        gCurrentPinballGame->coinRewardTimer = (gCurrentPinballGame->coinRewardAmount * 9) + 1;
                        gCurrentPinballGame->coinsAwarded = gCurrentPinballGame->coinRewardAmount;
                    }
                    else
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinBounceTimer[var2] = 17;
                        gCurrentPinballGame->coinSpritePos[var2].x = 188;
                        gCurrentPinballGame->coinSpritePos[var2].y = 140;
                        gCurrentPinballGame->coinsAwarded++;
                        m4aSongNumStart(SE_COIN_COLLECTED);
                        gCurrentPinballGame->coins++;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = SCORE_COIN_COLLECTED;
                    }
                }
            }

            for (i = 0; i < 2; i++)
            {
                group->baseX = gCurrentPinballGame->coinSpritePos[i].x;
                group->baseY = gCurrentPinballGame->coinSpritePos[i].y;
                if (gCurrentPinballGame->coinSpritePos[i].y > 160)
                    var0 = 0;
                else
                    var0 = (17 - gCurrentPinballGame->coinBounceTimer[i]) / 2;

                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gCoinRewardAnimOamFramesets[var0];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;

                if (gCurrentPinballGame->coinBounceTimer[i] > 0)
                {
                    gCurrentPinballGame->coinBounceTimer[i]--;
                    if (gCurrentPinballGame->coinBounceTimer[i] == 0)
                    {
                        gCurrentPinballGame->coinSpritePos[i].x = 70;
                        gCurrentPinballGame->coinSpritePos[i].y = 180;
                    }
                }
            }
        }

        gCurrentPinballGame->coinRewardTimer++;
        if (gCurrentPinballGame->coinRewardTimer == ((gCurrentPinballGame->coinRewardAmount - 1) * 9) + 19)
        {
            gMain.fieldSpriteGroups[FIELD_SG_COIN_COLLECTED]->active = FALSE;
            gCurrentPinballGame->coinRewardAmount = 0;
            if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
                gCurrentPinballGame->outcomeFrameCounter = 170;
        }
    }
}

void InitTotodileEggDelivery(void)
{
    gCurrentPinballGame->eggDeliveryX = 1600;
    gCurrentPinballGame->eggDeliveryY = 2080;
    gCurrentPinballGame->totodileDeliveryFrame = 0;
    gCurrentPinballGame->totodileDeliveryTimer = 0;
    gMain.spriteGroups[SG_RUBY_TOTODILE_EGG_DELIVERY].active = TRUE;
    gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_STILL;
    gCurrentPinballGame->portraitOffsetX = 240;
    gCurrentPinballGame->portraitOffsetY = 160;
    gCurrentPinballGame->activeFxType = FX_TOTODILE_EGG_DELIVERY;
    DmaCopy16(3, gTotodile_Pal, OBJ_PLTT_SLOT(PAL_IX_RUBY_EGG_DELIVERER), PLTT_SLOT_SIZE);
    DmaCopy16(3, gTotodileEggDelivery_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_TOTODILE_EGG_DELIVERY_TILES);
}

void AnimateTotodileEggDelivery(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;

    var0 = 0;
    group = &gMain.spriteGroups[SG_RUBY_TOTODILE_EGG_DELIVERY];
    if (gPikaSaverFrameData[gCurrentPinballGame->totodileDeliveryFrame][1] > gCurrentPinballGame->totodileDeliveryTimer)
    {
        gCurrentPinballGame->totodileDeliveryTimer++;
    }
    else
    {
        gCurrentPinballGame->totodileDeliveryFrame++;
        gCurrentPinballGame->totodileDeliveryTimer = 0;
        if (gCurrentPinballGame->totodileDeliveryFrame == 41)
        {
            gCurrentPinballGame->totodileDeliveryFrame = 40;
            group->active = FALSE;
            gCurrentPinballGame->rubyEggDeliveryState = 2;
            gCurrentPinballGame->activeFxType = FX_NONE;
        }

        if (gCurrentPinballGame->totodileDeliveryFrame == 1)
            m4aSongNumStart(SE_TOTODILE_LOWERS_ROPE);

        if (gCurrentPinballGame->totodileDeliveryFrame == 7)
            m4aSongNumStart(SE_TOTODILE_SLIDES_DOWN);

        if (gCurrentPinballGame->totodileDeliveryFrame == 13)
            m4aSongNumStart(SE_TOTODILE_PLACES_EGG);

        if (gCurrentPinballGame->totodileDeliveryFrame == 39)
        {
            gCurrentPinballGame->portraitOffsetX = 0;
            gCurrentPinballGame->portraitOffsetY = 0;
            DmaCopy16(3, gEggFrameTilesGfx[0], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
        }

        if (gCurrentPinballGame->totodileDeliveryFrame == 14)
            gCurrentPinballGame->scoreAddedInFrame = SCORE_TOTODILE_EGG_DELIVERY;
    }

    if (gCurrentPinballGame->totodileDeliveryFrame >= 14 && gCurrentPinballGame->totodileDeliveryFrame < 38 && gCurrentPinballGame->globalAnimFrameCounter % 7 == 0)
        m4aSongNumStart(SE_TOTODILE_CLIMBS_ROPE);

    group->baseX = gCurrentPinballGame->eggDeliveryX / 20 - gCurrentPinballGame->cameraXOffset;
    group->baseY = gCurrentPinballGame->eggDeliveryY / 20 - gCurrentPinballGame->cameraYOffset;
    var0 = gPikaSaverFrameData[gCurrentPinballGame->totodileDeliveryFrame][0];
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gTotodileEggDeliveryCutsceneFramesets[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void InitAerodactylEggDelivery(void)
{
    gCurrentPinballGame->eggDropTimer = 0;
    gCurrentPinballGame->eggDeliveryX = 3600;
    gCurrentPinballGame->eggDeliveryY = -40;
    gCurrentPinballGame->eggDeliveryVelX = -36;
    gCurrentPinballGame->eggDeliveryVelY = 60;
    gMain.spriteGroups[SG_RUBY_AERODACTLY_EGG_DELIVERY].active = TRUE;
    gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_STILL;
    gCurrentPinballGame->portraitOffsetX = gCurrentPinballGame->eggDeliveryX / 20 - gFlyingCreatureCameraOffsets[0].x;
    gCurrentPinballGame->portraitOffsetY = gCurrentPinballGame->eggDeliveryY / 20 - gFlyingCreatureCameraOffsets[0].y;
    gCurrentPinballGame->activeFxType = FX_AERODACTYL_EGG_DELIVERY;
    DmaCopy16(3, gAerodactlyFlight_Pal, OBJ_PLTT_SLOT(PAL_IX_RUBY_EGG_DELIVERER), PLTT_SLOT_SIZE);
    DmaCopy16(3, gAerodactlyFlight_Gfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_AERODACTYL_EGG_DELIVERY_TILES);
}

void AnimateAerodactylEggDelivery(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    var0 = (gCurrentPinballGame->eggDropTimer % 56) / 8;
    group = &gMain.spriteGroups[SG_RUBY_AERODACTLY_EGG_DELIVERY];
    if (gCurrentPinballGame->eggDropTimer < 130)
    {
        if (gCurrentPinballGame->eggDropTimer % 36U == 0)
            m4aSongNumStart(SE_AERODACTYL_EGG_FLIGHT);

        gCurrentPinballGame->eggDropTimer++;
        gCurrentPinballGame->eggDeliveryX += gCurrentPinballGame->eggDeliveryVelX;
        gCurrentPinballGame->eggDeliveryY += gCurrentPinballGame->eggDeliveryVelY;
        if (gCurrentPinballGame->eggDeliveryVelY > 7 || gMain.systemFrameCount % 3 == 0)
            gCurrentPinballGame->eggDeliveryVelY--;

        if (gCurrentPinballGame->eggDropTimer < 78)
        {
            gCurrentPinballGame->portraitOffsetX = gCurrentPinballGame->eggDeliveryX / 20 - gFlyingCreatureCameraOffsets[var0].x;
            gCurrentPinballGame->portraitOffsetY = gCurrentPinballGame->eggDeliveryY / 20 - gFlyingCreatureCameraOffsets[var0].y;
        }
        else
        {
            gCurrentPinballGame->portraitOffsetX = 0;
            gCurrentPinballGame->portraitOffsetY = 0;
        }

        if (gCurrentPinballGame->eggDropTimer == 78)
            gCurrentPinballGame->scoreAddedInFrame = SCORE_AERODACTYL_EGG_DELIVERY;

        DmaCopy16(3, gEggFrameTilesGfx[0], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
    }
    else
    {
        group->active = FALSE;
        do {} while (0); // needed to match, there was probably some dead code
        gCurrentPinballGame->rubyEggDeliveryState = 2;
        gCurrentPinballGame->activeFxType = FX_NONE;
    }

    group->baseX = gCurrentPinballGame->eggDeliveryX / 20 - gCurrentPinballGame->cameraXOffset;
    group->baseY = gCurrentPinballGame->eggDeliveryY / 20 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gAerodactylEggDeliveryCutsceneFramesets[var0][i * 3 + 0];
        *dst++ = gAerodactylEggDeliveryCutsceneFramesets[var0][i * 3 + 1];
        *dst++ = gAerodactylEggDeliveryCutsceneFramesets[var0][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void LoadPokemonNameGraphics(void)
{
    s16 i;
    int index;

    gCurrentPinballGame->nameSpacingOffset = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_EVO_PREVIEW, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->activeFxType = FX_MON_SELECTION_NAME;
    gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT]->active = TRUE;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
        {
            DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            gCurrentPinballGame->nameSpacingOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
            DmaCopy16(3, gAlphabetTilesGfx[index], OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
        }
    }
}

void UpdatePokemonNamePosition(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT];
    for (i = 0; i < 10; i++)
    {
        group->baseX = i * 8 + (gCurrentPinballGame->nameSpacingOffset + 152) + gCurrentPinballGame->shopUISlideOffset;
        group->baseY = 96;
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void HidePokemonNameDisplay(void)
{
    gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT]->active = FALSE;
    gCurrentPinballGame->activeFxType = FX_NONE;
}

void InitWasCaughtBanner(void)
{
    s16 i;
    u8 letter;
    int index;
    const u8 *dest;

    gCurrentPinballGame->nameSpacingOffset = 0;
    gCurrentPinballGame->creatureOamPriority = 0;
    gCurrentPinballGame->nameRevealAnimFrame = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_POKEMON_DISPLAY, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->activeFxType = FX_MON_WAS_CAUGHT_CUTSCENE;
    gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT]->active = TRUE;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == ' ')
        {
            DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
            gCurrentPinballGame->nameSpacingOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 'A';
            DmaCopy16(3, gAlphabetTilesGfx[index], OBJ_VRAM_ADDR_MON_NAME_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
        }
    }

    gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT]->active = TRUE;
    for (i = 0; i < 10; i++)
    {
        if (gCaughtTextChars[i] == ' ')
        {
            DmaCopy16(3, gSpaceTileGfx, OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
        }
        else
        {
            index = gCaughtTextChars[i] - 'A';
            DmaCopy16(3, gAlphabetTilesGfx[index], OBJ_VRAM_ADDR_WAS_CAUGHT_TEXT_CHAR(i), SIZE_OF_VRAM_LETTER_TILE);
        }
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->nameRevealDelays[i] = i * 2;
        gCurrentPinballGame->nameSlideRow1[i].x = 0;
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->nameRevealDelaysRow2[i] = (i + 10) * 2;
        gCurrentPinballGame->nameSlideRow2[i].x = 0;
    }
}

void AnimateWasCaughtBanner(void)
{
    s16 i, j, k;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 var0;

    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    if (gCurrentPinballGame->nameRevealAnimFrame == 0)
    {
        gCurrentPinballGame->nameRevealAnimFrame++;
        group = gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
    else if (gCurrentPinballGame->nameRevealAnimFrame < 195)
    {
        gCurrentPinballGame->nameRevealAnimFrame++;
        if (gCurrentPinballGame->nameRevealAnimFrame < 156)
        {

            group = gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelays[i])
                {
                    gCurrentPinballGame->nameRevealDelays[i]--;
                }
                else
                {
                    gCurrentPinballGame->nameSlideRow1[i].x += ((1600 - gCurrentPinballGame->nameSlideRow1[i].x) * 12) / 100;
                    if (gCurrentPinballGame->nameSlideRow1[i].x >= 1592)
                        gCurrentPinballGame->nameSlideRow1[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow1[i].x / 10 - var0) + gCurrentPinballGame->nameSpacingOffset;;
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelaysRow2[i])
                {
                    gCurrentPinballGame->nameRevealDelaysRow2[i]--;
                }
                else
                {
                    gCurrentPinballGame->nameSlideRow2[i].x += ((1600 - gCurrentPinballGame->nameSlideRow2[i].x) * 12) / 100;
                    if (gCurrentPinballGame->nameSlideRow2[i].x >= 1592)
                        gCurrentPinballGame->nameSlideRow2[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow2[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->nameRevealAnimFrame == 155)
            {
                for (j = 0; j < 10; j++)
                {
                    gCurrentPinballGame->nameRevealDelays[j] = j * 2;
                    gCurrentPinballGame->nameSlideRow1[j].x = 0;
                }

                for (k = 0; k < 10; k++)
                {
                    gCurrentPinballGame->nameRevealDelaysRow2[k] = (k + 10) * 2;
                    gCurrentPinballGame->nameSlideRow2[k].x = 0;
                }
            }
        }
        else
        {
            group = gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelays[i])
                    gCurrentPinballGame->nameRevealDelays[i]--;
                else
                    gCurrentPinballGame->nameSlideRow1[i].x += ((2000 - gCurrentPinballGame->nameSlideRow1[i].x) * 12) / 100;

                var0 = i * 8 + 80;
                group->baseX = var0 - gCurrentPinballGame->cameraXOffset - gCurrentPinballGame->nameSlideRow1[i].x / 10 + gCurrentPinballGame->nameSpacingOffset;
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelaysRow2[i])
                    gCurrentPinballGame->nameRevealDelaysRow2[i]--;
                else
                    gCurrentPinballGame->nameSlideRow2[i].x += ((2000 - gCurrentPinballGame->nameSlideRow2[i].x) * 12) / 100;

                var0 = 0;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow2[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
    else
    {
        group = gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT];
        if (group->active)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT];
        if (group->active)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.fieldSpriteGroups[FIELD_SG_POKEMON_NAME_TEXT]->active = FALSE;
        gMain.fieldSpriteGroups[FIELD_SG_WAS_CAUGHT_TEXT]->active = FALSE;
        gCurrentPinballGame->activeFxType = FX_NONE;
    }
}

void InitRubyEggHatchAnimation(void)
{
    gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_STILL;
    gCurrentPinballGame->prevEggAnimFrame = 0;
    gCurrentPinballGame->eggAnimFrameIndex = 0;
    gCurrentPinballGame->eggFrameTimer = 0;
    gCurrentPinballGame->cyndaquilPosition = CYNDAQUIL_POSITION_LOW_GUARD;
    gCurrentPinballGame->eggCaveReEntryFlag = FALSE;
}

void UpdateRubyEggHatchAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 lastFrameOfPhase;
    s16 startFrameOfNextPhase;
    s16 nextPhase;
    s16 caveFrameIx;
    s16 priority;
    s16 index;

    priority = 1;
    lastFrameOfPhase = 0;
    startFrameOfNextPhase = 0;
    nextPhase = 0;
    group = &gMain.spriteGroups[SG_RUBY_HATCH_EGG];
    caveFrameIx = 0;
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
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][2];
        DmaCopy16(3, gRubyBoardHatchCave_Gfx[index], OBJ_VRAM_ADDR_HATCH_CAVE_TILES, SIZE_OF_VRAM_HATCH_CAVE_TILES);
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3];
        DmaCopy16(3, gEggFrameTilesGfx[index], OBJ_VRAM_ADDR_HATCH_EGG_TILES, SIZE_OF_VRAM_HATCH_EGG_TILES);
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

        caveFrameIx = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][0];
    }

    gCurrentPinballGame->eggBasePosX = 88 - gCurrentPinballGame->cameraXOffset;
    gCurrentPinballGame->eggBasePosY = 144 - gCurrentPinballGame->cameraYOffset;
    group->baseX = gCurrentPinballGame->eggBasePosX + gCurrentPinballGame->portraitOffsetX;
    if (gCurrentPinballGame->eggAnimationPhase > EGG_ANIM_PHASE_OFF_BOARD)
    {
        if (gCurrentPinballGame->eggAnimFrameIndex == 32 && gCurrentPinballGame->eggFrameTimer > 208)
        {
            s16 varZ = (0x100 - gCurrentPinballGame->eggFrameTimer) / 16 + 1;
            if (gMain.systemFrameCount & (varZ << 1))
                group->baseY = gCurrentPinballGame->eggBasePosY + gCurrentPinballGame->portraitOffsetY;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->eggBasePosY + gCurrentPinballGame->portraitOffsetY;
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
        src = gEggOamFramestates[caveFrameIx][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[SG_RUBY_HATCH_CAVE];
    group->baseX = gCurrentPinballGame->eggBasePosX;
    group->baseY = gCurrentPinballGame->eggBasePosY;
    for (i = 0; i < 4; i++)
    {
        oamSimple = &gMain.spriteGroups[SG_RUBY_HATCH_CAVE].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateHatchCave(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 var0;

    priority = 1;
    group = &gMain.spriteGroups[SG_RUBY_CYNDAQUIL];
    var0 = gMain.systemFrameCount % 36;
    gCurrentPinballGame->cyndaquilFrame = 0;
    gCurrentPinballGame->cyndaquilCollisionEnabled = TRUE;
    if (gCurrentPinballGame->cyndaquilPosition < CYNDAQUIL_POSITION_CAVE_ENTRANCE)
    {
        gCurrentPinballGame->cyndaquilFrame = gCyndaquilFrameIndices[var0 / 6];
        gCurrentPinballGame->cyndaquilCaveSpriteX = gCyndaquilCavePositions[gCurrentPinballGame->cyndaquilPosition].x;
        gCurrentPinballGame->cyndaquilCaveSpriteY = gCyndaquilCavePositions[gCurrentPinballGame->cyndaquilPosition].y;
        group->baseX = gCurrentPinballGame->cyndaquilCaveSpriteX - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->cyndaquilCaveSpriteY - gCurrentPinballGame->cameraYOffset;
        if (var0 % 6 == 0)
        {
            DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], OBJ_VRAM_ADDR_CYNDAQUIL_TILES, SIZE_OF_VRAM_CYNDAQUIL_TILES);
        }
    }
    else if (gCurrentPinballGame->cyndaquilPosition == CYNDAQUIL_POSITION_CAVE_ENTRANCE)
    {
        if (gCurrentPinballGame->rubyEggDeliveryState != 2)
        {
            if (gCurrentPinballGame->eggAnimationPhase == EGG_ANIM_PHASE_STILL)
            {
                gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_CYNDAQUIL_ENTERS_BALL_JUMP;
                gCurrentPinballGame->cyndaquilFrame = 1;
                DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], OBJ_VRAM_ADDR_CYNDAQUIL_TILES, SIZE_OF_VRAM_CYNDAQUIL_TILES);
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 60;
                gCurrentPinballGame->cameraYScrollTarget = 72;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
                gCurrentPinballGame->bannerActive = TRUE;
                gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
                gCurrentPinballGame->eggCaveLiftTimer = 48;
            }

            if (gCurrentPinballGame->eggCaveReEntryFlag)
            {
                gCurrentPinballGame->eggCaveReEntryFlag = FALSE;
                gCurrentPinballGame->eggCaveLiftTimer = 48;
            }
        }
        else
        {
            if (gCurrentPinballGame->eggCaveLiftTimer == 0)
            {
                if (gCurrentPinballGame->eggCaveExitDelayTimer == 30)
                {
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gCurrentPinballGame->collisionCooldownTimer = 60;
                    gCurrentPinballGame->ball->velocity.x = 20;
                    gCurrentPinballGame->ball->velocity.y = 200;
                    gCurrentPinballGame->ball->positionQ0.x = 88;
                    gCurrentPinballGame->ball->positionQ0.y = 163;
                    gCurrentPinballGame->ball->spinSpeed = 0;
                    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                    m4aSongNumStart(SE_CYNDAQUIL_BALL_EJECT_AFTER_EGG_ARRIVAL);
                    gCurrentPinballGame->cameraLocked = FALSE;
                }

                if (gCurrentPinballGame->eggCaveExitDelayTimer)
                {
                    gCurrentPinballGame->eggCaveExitDelayTimer--;
                }
                else
                {
                    InitRubyEggHatchAnimation();
                    gCurrentPinballGame->cyndaquilPosition = CYNDAQUIL_POSITION_LOW_GUARD;
                    gCurrentPinballGame->rubyEggDeliveryState = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->positionQ0.x = 88;
                gCurrentPinballGame->ball->positionQ0.y = 163 - gCurrentPinballGame->eggCaveLiftTimer / 3;
                gCurrentPinballGame->ball->spinSpeed = 0;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
                gCurrentPinballGame->cameraLocked = TRUE;
            }
        }

        gCurrentPinballGame->cyndaquilCaveSpriteX = gCyndaquilCavePositions[gCurrentPinballGame->cyndaquilPosition].x;
        gCurrentPinballGame->cyndaquilCaveSpriteY = gCyndaquilCavePositions[gCurrentPinballGame->cyndaquilPosition].y - gCurrentPinballGame->eggCaveLiftTimer / 3;
        group->baseX = gCurrentPinballGame->cyndaquilCaveSpriteX - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->cyndaquilCaveSpriteY - gCurrentPinballGame->cameraYOffset;
        if (BoardNotInActivityMode)
        {
            if (gCurrentPinballGame->cyndaquilPosition == CYNDAQUIL_POSITION_CAVE_ENTRANCE && gCurrentPinballGame->rubyEggDeliveryState != 2)
                gCurrentPinballGame->catchArrowPaletteActive = TRUE;
            else
                gCurrentPinballGame->catchArrowPaletteActive = FALSE;
        }
        else
        {
            gCurrentPinballGame->catchArrowPaletteActive = FALSE;
        }

        if (gCurrentPinballGame->eggCaveLiftTimer)
        {
            gCurrentPinballGame->eggCaveLiftTimer--;
            priority = 2;
        }
    }
    else
    {
        if (gCurrentPinballGame->eggAnimationPhase == EGG_ANIM_PHASE_HATCH_CAVE_GLOW)
        {
            gCurrentPinballGame->catchArrowPaletteActive = FALSE;
            gCurrentPinballGame->eggAnimationPhase = EGG_ANIM_PHASE_EGG_JUMPS;
            gCurrentPinballGame->eggAnimFrameIndex = 8;
            gCurrentPinballGame->eggFrameTimer = 0;
        }

        gCurrentPinballGame->cyndaquilCaveSpriteX = 0;
        gCurrentPinballGame->cyndaquilCaveSpriteY = 0;
        group->baseX = 0;
        group->baseY = 160;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void CleanupEggModeState(void)
{
    s16 i;

    if (gMain.selectedField == FIELD_RUBY)
        gCurrentPinballGame->rubyEggDeliveryState = 1;
    else
        gCurrentPinballGame->sapphireReadyForNewEgg = TRUE;

    gCurrentPinballGame->creatureHitCount = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->monProgressTowardsBonusCount)
            gCurrentPinballGame->modeProgressLights[i] = MODE_PROGRESS_LAMP_BALL_LIT;
        else
            gCurrentPinballGame->modeProgressLights[i] = MODE_PROGRESS_LAMP_BALL_UNLIT;
    }
}

void InitEggMode(void)
{
    gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_INIT;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->saverTimeRemaining = HATCH_MODE_SAVER_TIME;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->walkMonXVelocity = 0;
    gCurrentPinballGame->walkMonYVelocity = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->walkMonXPos = 750;
        gCurrentPinballGame->walkMonYPos = 1040;
    }
    else
    {
        gCurrentPinballGame->walkMonXPos = 1960;
        gCurrentPinballGame->walkMonYPos = 300;
    }

    gCurrentPinballGame->creatureWaypointIndex = 0;
    gCurrentPinballGame->waypointSubTimer = 0;
    gCurrentPinballGame->walkMonXVelocity = 0;
    gCurrentPinballGame->walkMonYVelocity = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
}

void UpdateEggMode(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    int priority;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    u16 angle2;
    int xx, yy;
    int squaredDistance;

    group = gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY];
    priority = 1;
    switch (gCurrentPinballGame->boardSubState)
    {
    case EGG_HATCH_SUBSTATE_INIT:
        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
        gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY]->active = TRUE;
        gCurrentPinballGame->boardSubState++;
        break;
    case EGG_HATCH_SUBSTATE_SETUP_WANDERING:
        if (gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][1] > gCurrentPinballGame->waypointSubTimer)
        {
            gCurrentPinballGame->waypointSubTimer++;
        }
        else
        {
            gCurrentPinballGame->creatureWaypointIndex++;
            gCurrentPinballGame->waypointSubTimer = 0;
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->creatureWaypointIndex > 13)
                {
                    gCurrentPinballGame->creatureWaypointIndex = 0;
                    gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_WANDERING;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 12)
                {
                    if (gCurrentPinballGame->waypointSubTimer == 0)
                        m4aSongNumStart(MUS_EGG_MODE);
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 10)
                {
                    gCurrentPinballGame->bgmFadeTimer = 140;
                    PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].speciesIdRS, 0);
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 12)
                {
                    gCurrentPinballGame->walkMonXVelocity = -8;
                    gCurrentPinballGame->walkMonYVelocity = -30;
                }
                else
                {
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->creatureWaypointIndex > 9)
                {
                    gCurrentPinballGame->waypointSubTimer = 0;
                    gCurrentPinballGame->creatureWaypointIndex = 10;
                    gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_SAPPHIRE_RAMP_SLIDE;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }
        }

        var0 = gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][0];
        var1 = gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][2];
        if (gCurrentPinballGame->creatureWaypointIndex == 12)
        {
            gCurrentPinballGame->walkMonYVelocity += 2;
            gCurrentPinballGame->walkMonXPos += gCurrentPinballGame->walkMonXVelocity;
            gCurrentPinballGame->walkMonYPos += gCurrentPinballGame->walkMonYVelocity;
        }

        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gHatchedWalkerAnimTileBuffer[var0], OBJ_VRAM_ADDR_HATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES);
        DmaCopy16(3, gCatchSpritePaletteBuffer, OBJ_PLTT_SLOT(PAL_IX_CATCH_MON), PLTT_SLOT_SIZE);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gCatchCreatureOamFramesets[var1][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
        break;
    case EGG_HATCH_SUBSTATE_SAPPHIRE_RAMP_SLIDE:
        if (gCurrentPinballGame->waypointSubTimer < 240)
        {
            priority = 1;
            if (gCurrentPinballGame->waypointSubTimer == 0)
            {
                gCurrentPinballGame->sapphireHatchMachineState = HATCH_MACHINE_STATE_ELEVATOR_DECENDS;
                m4aSongNumStart(SE_MON_LANDS_ON_HATCH_MACHINE_TOP);
            }
            var0 = 0;
        }
        else if (gCurrentPinballGame->waypointSubTimer == 240)
        {
            gCurrentPinballGame->walkMonXPos = 2260;
            gCurrentPinballGame->walkMonYPos = 740;
            gCurrentPinballGame->creatureWaypointIndex = 0;
            priority = 2;
            var0 = 0;
            m4aSongNumStart(MUS_EGG_MODE);
        }
        else
        {
            tempVec.x = gSapphireEggWaypoints[gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
            tempVec.y = gSapphireEggWaypoints[gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredDistance = xx + yy;
            angle = ArcTan2(tempVec.x,-tempVec.y);
            if (gCurrentPinballGame->waypointSubTimer < 324)
                priority = 2;
            else
                priority = 1;

            if (gCurrentPinballGame->creatureWaypointIndex < 4)
            {
                var0 = 0;
                tempVec2.x = MulCos(14, angle);
                tempVec2.y = MulSin(-14, angle);
            }
            else
            {
                var0 = gAngleToDirectionTable[angle / ANGLE_45] + (gMain.systemFrameCount % 24) / 8;
                tempVec2.x = MulCos(7, angle);
                tempVec2.y = MulSin(-7, angle);
            }

            gCurrentPinballGame->walkMonXPos += tempVec2.x;
            gCurrentPinballGame->walkMonYPos += tempVec2.y;
            if (squaredDistance < 2500)
            {
                if (gCurrentPinballGame->creatureWaypointIndex < 6)
                {
                    gCurrentPinballGame->creatureWaypointIndex++;
                }
                else
                {
                    gCurrentPinballGame->creatureWaypointIndex = 3;
                    gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_WANDERING;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }

            if (gCurrentPinballGame->waypointSubTimer < 380)
            {
                gCurrentPinballGame->cameraYAdjust++;
            }
            else if (gCurrentPinballGame->waypointSubTimer >= 400)
            {
                if (gCurrentPinballGame->cameraYAdjust > 0)
                    gCurrentPinballGame->cameraYAdjust--;
            }
        }

        DmaCopy16(3, gHatchedWalkerAnimTileBuffer[var0], OBJ_VRAM_ADDR_HATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES);
        gCurrentPinballGame->waypointSubTimer++;
        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
        break;
    case EGG_HATCH_SUBSTATE_WANDERING:
        tempVec.x = gEggWalkPathWaypoints[gMain.selectedField][gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
        tempVec.y = gEggWalkPathWaypoints[gMain.selectedField][gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredDistance = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = MulCos(7, angle);
        tempVec2.y = MulSin(-7, angle);
        if (gCurrentPinballGame->captureFlashTimer)
        {
            gCurrentPinballGame->captureFlashTimer--;
            var0 = 14;
        }
        else
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].specialEggFlag)
            {
                var0 = gAngleToDirectionTable[angle / ANGLE_45] + (gMain.systemFrameCount % 24) / 8;
            }
            else
            {
                var0 = gAngleToDirectionTable[angle / ANGLE_45] + (gMain.systemFrameCount % 32) / 8 - ((gMain.systemFrameCount % 32) / 24) * 2;
            }

            gCurrentPinballGame->walkMonXPos += tempVec2.x;
            gCurrentPinballGame->walkMonYPos += tempVec2.y;
        }

        if (squaredDistance < 2500)
        {
            if (gCurrentPinballGame->creatureWaypointIndex < 28)
            {
                gCurrentPinballGame->creatureWaypointIndex++;
            }
            else
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                gCurrentPinballGame->stageTimer = 200;
                gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_CLEANUP_MON_SPRITES;
            }
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->creatureWaypointIndex > 26)
                priority = 2;
            else
                priority = 1;
        }
        else if (gCurrentPinballGame->creatureWaypointIndex > 27)
        {
            priority = 3;
            gCurrentPinballGame->eggHatchShockWallOverride = TRUE;
        }
        else
        {
            priority = 1;
        }

        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        DmaCopy16(3, gHatchedWalkerAnimTileBuffer[var0], OBJ_VRAM_ADDR_HATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->creatureHitCooldown)
        {
            gCurrentPinballGame->creatureHitCooldown--;
        }
        else
        {
            tempVec.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->walkMonXPos / 10 + 12);
            tempVec.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->walkMonYPos / 10 + 14);
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredDistance = xx + yy;
            if (squaredDistance < 82)
            {
                gCurrentPinballGame->creatureHitCount++;
                gCurrentPinballGame->creatureHitCooldown = 4;
                gCurrentPinballGame->captureFlashTimer = 20;
                if (gCurrentPinballGame->creatureHitCount > 1)
                    gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_SETUP_CATCH_ANIMATION;

                m4aSongNumStart(SE_PICHU_IN_POSITION_CHIRP);
                angle2 = ArcTan2(-gCurrentPinballGame->ball->velocity.x, gCurrentPinballGame->ball->velocity.y);
                if (gCurrentPinballGame->creatureHitCount > 1)
                {
                    gCurrentPinballGame->ball->velocity.x = MulCos(400, angle2);
                    gCurrentPinballGame->ball->velocity.y = MulSin(-400, angle2);
                }
                else
                {
                    gCurrentPinballGame->ball->velocity.x = MulCos(160, angle2);
                    gCurrentPinballGame->ball->velocity.y = MulSin(-160, angle2);
                }

                PlayRumble(7);
            }
        }
        break;
    case EGG_HATCH_SUBSTATE_SETUP_CATCH_ANIMATION:
        gCurrentPinballGame->activeFxType = FX_CAPTURE_MON_ABSORB;
        DmaCopy16(3, gCaptureHit_Pal, OBJ_PLTT_SLOT(PAL_IX_MON_SHADOW_PORTRAIT), PLTT_SLOT_SIZE);
        DmaCopy16(3, gCaptureScreenTilesGfx, OBJ_VRAM_ADDR_FX_BASE, SIZE_OF_VRAM_FX_MON_CATCH_CUTSCENE_TILES);
        DmaCopy16(3, &gCaptureBallTilesGfx[gCurrentPinballGame->ballUpgradeType * 0x200], OBJ_VRAM_ADDR_FX_MON_CATCH_OPEN_BALL_TILES1, SIZE_OF_VRAM_FX_MON_CATCH_OPEN_BALL_TILES1);
        DmaCopy16(3, &gCaptureBallTilesGfx[(gCurrentPinballGame->ballUpgradeType * 8 + 4) * 0x40], OBJ_VRAM_ADDR_FX_MON_CATCH_OPEN_BALL_TILES2, SIZE_OF_VRAM_FX_MON_CATCH_OPEN_BALL_TILES2);
        gCurrentPinballGame->captureSequenceFrame = 0;
        gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
        gCurrentPinballGame->catchTargetX = gCurrentPinballGame->walkMonXPos / 10 + 8;
        gCurrentPinballGame->catchTargetY = gCurrentPinballGame->walkMonYPos / 10 - 31;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->catchTilePalette[i] = PAL_IX_MON_PORTRAIT;

        gCurrentPinballGame->boardSubState++;
        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;

        DmaCopy16(3, gHatchedWalkerAnimTileBuffer[14], OBJ_VRAM_ADDR_HATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = 2;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->stageTimer = 0;
        break;
    case EGG_HATCH_SUBSTATE_CATCH_ANIMATION:
        if (gCurrentPinballGame->captureSequenceTimer < 17)
            priority = 2;
        else
            priority = 0;

        if (group->active)
        {
            group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = priority;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            DmaCopy16(3, gHatchedWalkerAnimTileBuffer[14], OBJ_VRAM_ADDR_HATCH_MON_ENTITY_TILES, SIZE_OF_VRAM_HATCH_MON_ENTITY_TILES);
            if (gCurrentPinballGame->captureSequenceTimer == 23)
                gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY]->active = FALSE;
        }
        break;
    case EGG_HATCH_SUBSTATE_CLEANUP_MON_SPRITES:
        if (group->active)
        {
            group->baseX = 0;
            group->baseY = 200;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY]->active = FALSE;
        gCurrentPinballGame->boardSubState++;
        break;
    case EGG_HATCH_SUBSTATE_BOARD_STATE_CLEANUP:
        CleanupEggModeState();
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->eggHatchShockWallOverride = FALSE;
        break;
    case EGG_HATCH_SUBSTATE_PREPARE_NEXT_BOARD_MODE:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->modeProgressLights[MODE_LAMP_RIGHT] == MODE_PROGRESS_LAMP_BALL_LIT)
                RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
            else
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);

            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
        }
        break;
    }
}
