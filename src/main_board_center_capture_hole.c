#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"
#include "constants/board/bonus_board.h"
#include "constants/anglemath.h"

extern struct SongHeader se_roulette_tick;
extern struct SongHeader se_mon_catch_ball_woosh;
extern struct SongHeader se_ball_upgrade;

extern u16 gRouletteWheelContents[][7];
extern const u8 gPikachuSaverTilesGfx[];

extern const s16 gCaptureSequenceTimings[34];
extern const u8 gCaptureScreenTilesGfx[];
extern const s8 gCaptureShakeOffsets[];
extern const u16 gPokeballCaptureOamFrames[][0x30];
extern const u8 gCaptureBallTilesGfx[];
extern const u8 gBallFlashPalette;

extern u8 gCatchSequencePalA;
extern u8 gCatchSequencePalB;
extern u8 gCatchSequencePalC;
extern u8 gCatchSpritePalettes[];

void InitRouletteWheel(void)
{
    s16 i;

    gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1]->active = TRUE;
    gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM]->active = TRUE;
    gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM]->active = TRUE;
    gMain.blendControl = 0x1C10;
    gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
    gCurrentPinballGame->rouletteStopRequested = FALSE;
    gCurrentPinballGame->rouletteRotationPeriod = 8;
    gCurrentPinballGame->rouletteSpinSpeed = 0;
    gCurrentPinballGame->rouletteSubOffset = 0;
    if (gCurrentPinballGame->rouletteLevel == 25)
        gCurrentPinballGame->rouletteLevel = 10;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->rouletteSlotValues[i] = gRouletteWheelContents[gCurrentPinballGame->rouletteLevel][i];
        if (gCurrentPinballGame->rouletteSlotValues[i] == PRIZE_START_BONUS_MODE_ANY)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_KECLEON;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_GROUDON;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_RAYQUAZA;
                    break;
                }
            }
            else
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_DUSKULL;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_KYOGRE;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_BONUS_MODE_RAYQUAZA;
                    break;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == PRIZE_BALL_UPGRADE_BASE)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + PRIZE_BALL_UPGRADE_BASE;
            else
                gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_BALL_UPGRADE_C;
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == PRIZE_PICHU_SAVER)
        {
            if (gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES)
            {
                if (gMain.systemFrameCount & 1)
                {
                    if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                        gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + PRIZE_BALL_UPGRADE_BASE;
                    else
                        gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_BALL_UPGRADE_C;
                }
                else
                {
                    gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_60_SEC_BALL_SAVER;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == PRIZE_START_EVO_MODE)
        {
            if (gCurrentPinballGame->evolvablePartySize <= 0)
                gCurrentPinballGame->rouletteSlotValues[i] = PRIZE_START_CATCH_MODE;
        }
    }

    gCurrentPinballGame->roulettePortraitId = 21;
    if (gCurrentPinballGame->rouletteLevel < 25)
        gCurrentPinballGame->rouletteLevel++;

    gCurrentPinballGame->rouletteSlotMaxIndex = 5;
    if ((gCurrentPinballGame->jirachiActivationFlags & 0xF0) == 0 && gCurrentPinballGame->area > AREA_WILDERNESS)
        gCurrentPinballGame->rouletteSlotMaxIndex++;

    gCurrentPinballGame->rouletteSlotCursor = 1;
    gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->rouletteSlotValues[0];
    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[1];
    LoadPortraitGraphics(PORTRAIT_STATE_ROULETTE_WHEEL, PORTRAIT_MAIN_SLOT);
    LoadPortraitGraphics(PORTRAIT_STATE_ROULETTE_WHEEL, PORTRAIT_ALT_SLOT);
}

void RunRouletteWheel(void)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        if (!gCurrentPinballGame->rouletteStopRequested)
        {
            if (    (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]
                    || JOY_NEW(A_BUTTON))
                && gCurrentPinballGame->zigzagoonShockWallActive)
            {
                gCurrentPinballGame->zigzagoonState = 2;
                if (gCurrentPinballGame->rouletteSubOffset < 17)
                    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->modeOutcomeValues[0];

                gCurrentPinballGame->rouletteStopRequested = TRUE;
                gCurrentPinballGame->rouletteRotationPeriod = 40;
                gCurrentPinballGame->rouletteFrameIndex = 39;
            }
        }
    }

    if (!gCurrentPinballGame->rouletteStopRequested)
    {
        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_ROULETTE;
        gCurrentPinballGame->rouletteFrameIndex++;
        if (gCurrentPinballGame->rouletteSpinSpeed)
        {
            gCurrentPinballGame->rouletteSpinSpeed--;
            if (gCurrentPinballGame->rouletteSpinSpeed == 0)
            {
                gCurrentPinballGame->rouletteStopRequested = TRUE;
            }
            else
            {
                if (gCurrentPinballGame->rouletteFrameIndex == gCurrentPinballGame->rouletteRotationPeriod)
                {
                    gCurrentPinballGame->rouletteRotationPeriod = 40 - (gCurrentPinballGame->rouletteSpinSpeed * 34) / gCurrentPinballGame->rouletteInitialSpeed;
                    gCurrentPinballGame->rouletteFrameIndex = 0;
                }
            }
        }
        else if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]
                || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->rouletteSpinSpeed = (Random() % 200) + 100;
            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                if (gCurrentPinballGame->zigzagoonState == 1)
                {
                    gCurrentPinballGame->rouletteSpinSpeed = 320;
                    gCurrentPinballGame->zigzagoonShockWallActive = TRUE;
                }
            }

            gCurrentPinballGame->rouletteInitialSpeed = gCurrentPinballGame->rouletteSpinSpeed;
        }

        gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
    }
    else
    {
        gCurrentPinballGame->rouletteFrameIndex++;
        gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        if (gCurrentPinballGame->rouletteFrameIndex == 0)
        {
            gCurrentPinballGame->modeAnimTimer = 140;
            gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1]->active = FALSE;
            gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM]->active = FALSE;
            gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM]->active = FALSE;
            gCurrentPinballGame->rouletteSubOffset = 0;
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->prizeSelected = TRUE;
            gCurrentPinballGame->outcomeFrameCounter = 0;
        }
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 0)
    {
        gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->modeOutcomeValues[1];
        LoadPortraitGraphics(PORTRAIT_STATE_ROULETTE_WHEEL, PORTRAIT_MAIN_SLOT);
        gCurrentPinballGame->prizeId = gCurrentPinballGame->modeOutcomeValues[0];
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 1)
    {
        if (gCurrentPinballGame->rouletteSlotCursor < gCurrentPinballGame->rouletteSlotMaxIndex)
            gCurrentPinballGame->rouletteSlotCursor++;
        else
            gCurrentPinballGame->rouletteSlotCursor = 0;

        gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[gCurrentPinballGame->rouletteSlotCursor];
        LoadPortraitGraphics(PORTRAIT_STATE_ROULETTE_WHEEL, PORTRAIT_ALT_SLOT);
        MPlayStart(&gMPlayInfo_SE1, &se_roulette_tick);
    }
}


/*
    Used for both the prizes given by roulette outcome, and by shop purchases.
*/
void GivePrize(void)
{
    if (gCurrentPinballGame->outcomeFrameCounter < 180)
    {
        if (gCurrentPinballGame->outcomeFrameCounter == 4)
            m4aSongNumStart(MUS_PRIZE_AWARDED);

        if (gCurrentPinballGame->prizeId == PRIZE_PICHU_SAVER)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 120)
                m4aSongNumStart(SE_PICHU_KICKBACK_ENABLED);
        }

        gCurrentPinballGame->outcomeFrameCounter++;
        if (gCurrentPinballGame->outcomeFrameCounter < 80)
            LoadPortraitGraphics(PORTRAIT_STATE_ROULETTE_OUTCOME, PORTRAIT_MAIN_SLOT);
    }

    switch (gCurrentPinballGame->prizeId)
    {
    case PRIZE_30_SEC_BALL_SAVER:
    case PRIZE_60_SEC_BALL_SAVER:
    case PRIZE_90_SEC_BALL_SAVER:
        gCurrentPinballGame->saverTimeRemaining = (gCurrentPinballGame->prizeId + 1) * TICKS_FOR_TIME(0,30);
        break;
    case PRIZE_PICHU_SAVER:
        if (gCurrentPinballGame->ballCatchState == TRAP_EVO_SHOP_HOLE)
        {
            if (gCurrentPinballGame->outcomeFrameCounter > 124)
            {
                if (gCurrentPinballGame->shopOutcomeRepeatCount < 100)
                {
                    gCurrentPinballGame->shopOutcomeRepeatCount++;
                    gCurrentPinballGame->outcomeFrameCounter = 124;
                }
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 4)
            {
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeProgress = 168;
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
                DmaCopy16(3, gPikachuSaverTilesGfx, (void *)0x06010600, 0x180);
                gCurrentPinballGame->outLanePikaPosition = PIKA_BOTH_SIDES;
                gMain.fieldSpriteGroups[FIELD_SG_HATCH_MON_ENTITY]->active = FALSE;
                gCurrentPinballGame->pichuEntranceTimer = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 120)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 250;
                gCurrentPinballGame->cameraYScrollTarget = 272;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_NONE;
                gCurrentPinballGame->bannerActive = TRUE;
                gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
                gCurrentPinballGame->pichuWalkMode = 1;
                gCurrentPinballGame->pichuEntranceTimer = 800;
                gCurrentPinballGame->outLanePikaPosition = PIKA_LEFT_SIDE;
                gCurrentPinballGame->pikaChargeTarget = 168;
                gCurrentPinballGame->pikaChargeProgress = 168;
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
            }

            if (gCurrentPinballGame->pichuEntranceTimer)
            {
                if (gCurrentPinballGame->outcomeFrameCounter >= 176)
                    gCurrentPinballGame->outcomeFrameCounter = 176;
            }
        }
        break;
    case PRIZE_EXTRA_BALL:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->oneUpAnimTimer = 90;
        break;
    case PRIZE_SMALL_POINT_BONUS:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 3) + PRIZE_100_POINTS;
        }
        break;
    case PRIZE_BIG_POINT_BONUS:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 6)
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 3) + PRIZE_1M_POINTS;
            else if ((s32) gCurrentPinballGame->rouletteLevel <= 10)
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 5) + PRIZE_1M_POINTS;
            else if (gCurrentPinballGame->rouletteLevel % 5 == 0)
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 5) + PRIZE_5M_POINTS;
            else
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 7) + PRIZE_1M_POINTS;
        }
        break;
    case PRIZE_RANDOM_BONUS_MULTIPLIER:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 10)
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 3) + PRIZE_BONUS_MULT_PLUS_BASE;
            else
                gCurrentPinballGame->prizeId = (gMain.systemFrameCount % 5) + PRIZE_BONUS_MULT_PLUS_BASE;
        }
        break;
    case PRIZE_START_CATCH_MODE:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            RequestBoardStateTransition(MAIN_BOARD_STATE_CATCH_EM_MODE);
            gCurrentPinballGame->modeAnimTimer = 100;
        }
        break;
    case PRIZE_START_EVO_MODE:
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 149)
            {
                gCurrentPinballGame->shopEntryTimer = 180;
                gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 150)
            {
                gCurrentPinballGame->outcomeFrameCounter = 149;
                gCurrentPinballGame->evolutionShopActive = TRUE;
                UpdateShopEntryAnimation(1);
                gCurrentPinballGame->sapphireMartGateBumperState[0] = 3;
                gCurrentPinballGame->sapphireMartGateBumperState[1] = 3;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 170)
            {
                gCurrentPinballGame->shopDoorTargetFrame = 0;
                gCurrentPinballGame->evolutionShopActive = FALSE;
                RequestBoardStateTransition(MAIN_BOARD_STATE_EVO_MODE);
            }
        }
        break;
    case PRIZE_BALL_UPGRADE_A:
    case PRIZE_BALL_UPGRADE_B:
    case PRIZE_BALL_UPGRADE_C:
        //Note: all 3 ball upgrades are equivalent, upgrade 1 level
        //If ball already at masterball state, reset its timer.
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case PRIZE_BALL_UPGRADE_TO_MASTER:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeTimer = TICKS_FOR_TIME(1,0);
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case PRIZE_10_COINS:
    case PRIZE_30_COINS:
    case PRIZE_50_COINS:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->coinRewardLevel = 1;
            gCurrentPinballGame->coinRewardAmount = (gCurrentPinballGame->prizeId - PRIZE_10_COINS) * 20 + 10;
            gCurrentPinballGame->coinRewardTimer = 0;
        }

        if (gCurrentPinballGame->outcomeFrameCounter == 140)
            gCurrentPinballGame->outcomeFrameCounter = 139;
        break;
    case PRIZE_30_SEC_EXTRA_BONUS_STAGE_TIME:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->timerBonus = 1800;
        break;
    case PRIZE_JIRACHI_CATCH_MODE:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->modeAnimTimer = 100;
            gCurrentPinballGame->jirachiActivationFlags = 15;
            RequestBoardStateTransition(MAIN_BOARD_STATE_JIRACHI_CATCH_MODE);
        }
        break;
    case PRIZE_WISCASH_ACTIVE_SPHEAL_OPPORTUNITY:
        if (gCurrentPinballGame->outcomeFrameCounter == 150 && gCurrentPinballGame->shouldProcessWhiscash == 0)
        {
            gCurrentPinballGame->rubyPondChangeTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->forcePondToWhiscash = TRUE;
        }
        break;
    case PRIZE_PELIPPER_ACTIVE_SPHEAL_OPPORTUNITY:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->bumperHitsSinceReset = 100;
            gCurrentPinballGame->pelipperFrameTimer = 1800;
            gCurrentPinballGame->pelipperState = 1;
        }
        break;
    case PRIZE_1M_POINTS:
    case PRIZE_2M_POINTS:
    case PRIZE_3M_POINTS:
    case PRIZE_4M_POINTS:
    case PRIZE_5M_POINTS:
    case PRIZE_6M_POINTS:
    case PRIZE_7M_POINTS:
    case PRIZE_8M_POINTS:
    case PRIZE_9M_POINTS:
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->outcomeFrameCounter = 81;

        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->prizeId - 23) * SCORE_M;
        }
        break;
    case PRIZE_100_POINTS:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = (1 * SCORE_100);
        }
        break;
    case PRIZE_500_POINTS:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = (5 * SCORE_100);
        }
        break;
    case PRIZE_900_POINTS:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = (9 * SCORE_100);
        }
        break;
    case PRIZE_BONUS_MULT_PLUS_1:
    case PRIZE_BONUS_MULT_PLUS_2:
    case PRIZE_BONUS_MULT_PLUS_3:
    case PRIZE_BONUS_MULT_PLUS_4:
    case PRIZE_BONUS_MULT_PLUS_5:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->progressLevel += gCurrentPinballGame->prizeId - 35;
            if (gCurrentPinballGame->progressLevel > 99)
                gCurrentPinballGame->progressLevel = 99;
        }
        break;
    case PRIZE_START_BONUS_MODE_DUSKULL:
    case PRIZE_START_BONUS_MODE_KECLEON:
    case PRIZE_START_BONUS_MODE_KYOGRE:
    case PRIZE_START_BONUS_MODE_GROUDON:
    case PRIZE_START_BONUS_MODE_RAYQUAZA:
        // Note: all start the currently available mode.
        // This controls Dusclops/Kecleon/Kyogre/Groudon/Rayquaza
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
            RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
        break;
    }
}

//Capture pokemon cutscene.
void RunMonCaptureSequence(void)
{
    s16 i;
    s16 j;
    s16 temp_r0;
    s16 temp_r3;
    struct Vector16 tempVector;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    if (gCurrentPinballGame->gravityStrengthIndex != 0)
        return;

    // Handle counter increment logic
    if (gCurrentPinballGame->captureSequenceFrame < gCaptureSequenceTimings[gCurrentPinballGame->captureSequenceTimer])
    {
        gCurrentPinballGame->captureSequenceFrame++;

        if (gCurrentPinballGame->captureSequenceFrame >= gCaptureSequenceTimings[gCurrentPinballGame->captureSequenceTimer])
        {
            gCurrentPinballGame->captureSequenceFrame = 0;

            if (gCurrentPinballGame->captureSequenceTimer <= 34)
                gCurrentPinballGame->captureSequenceTimer++;
        }
    }

    switch (gCurrentPinballGame->captureSequenceTimer)
    {
    case 0:
        gMain.blendControl = 0xCE;

        if (gMain.selectedField < MAIN_FIELD_COUNT
            && (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                || gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE))
            gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;

        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;

        gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
        gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        gCurrentPinballGame->activePortraitType = 9;
        DmaCopy16(3, gCaptureScreenTilesGfx, 0x06015800, 0x1C00);
        DmaCopy16(3, &gCaptureBallTilesGfx[gCurrentPinballGame->ballUpgradeType << 9], 0x060164C0, 0x80);
        DmaCopy16(3, &gCaptureBallTilesGfx[((gCurrentPinballGame->ballUpgradeType * 8 + 4) << 6)], 0x06016760, 0x80);

        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;

        if (gCurrentPinballGame->captureSequenceFrame == 1)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->ballTrailEnabled = TRUE;
        }

        break;

    case 1:
        if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
        {
            gCurrentPinballGame->evoBlinkTimer = 0;
            gCurrentPinballGame->catchLights[0] = 2;
            gCurrentPinballGame->catchLights[1] = 2;
            gCurrentPinballGame->catchLights[2] = 2;
        }

        gCurrentPinballGame->ball->oamPriority = 0;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        if (gCurrentPinballGame->captureSequenceFrame == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_mon_catch_ball_woosh);

        break;

    case 2:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gMain.blendBrightness = 4;

        if (gCurrentPinballGame->captureSequenceFrame > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->activePaletteIndex = 1;
            gCurrentPinballGame->paletteSwapActive = TRUE;
        }
        break;

    case 3:
        gMain.blendBrightness = 7;

        if (gCurrentPinballGame->captureSequenceFrame > 1)
        {
            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2], 0x05000200, 0x20);

            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, 0x05000240, 0xC0);
            }
            else
                DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, 0x05000240, 0xE0);

            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x140, 0x05000340, 0x60);
            gCurrentPinballGame->activePaletteIndex = 2;
            gCurrentPinballGame->paletteSwapActive = TRUE;
        }

        DmaCopy16(3, &gBallFlashPalette, 0x05000220, 0x20);
        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        temp_r3 = gCurrentPinballGame->captureSequenceTimer - 4;

        if (temp_r3 == 0 || temp_r3 == 6)
        {
            if (gMain.selectedField < FIELD_KYOGRE &&
                (
                    (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                        && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_CATCH_HIT_PHASE)
                    || (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE
                        && gCurrentPinballGame->boardSubState == JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE)
                ))
            {
                DmaCopy16(3, &gCatchSequencePalB, 0x050003A0, 0x20);
            }

            DmaCopy16(3, &gBallFlashPalette, 0x05000220, 0x20);
            gMain.blendBrightness = 6;
        }
        else
        {
            //TODO: fakematch; unused i. Here for the +4 to parse correctly;
            DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
            gMain.blendBrightness = 7;
        }

        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX];

        if (spriteGroup->active)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX]->active = TRUE;

        if (gCurrentPinballGame->captureSequenceTimer == 10 && gCurrentPinballGame->captureSequenceFrame == 3)
            gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX]->active = FALSE;
        break;
    case 11:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);

        tempVector.x = (gCurrentPinballGame->catchTargetX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->catchTargetY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);

        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

        if (gMain.selectedField >= FIELD_BOSS_START)
        {
            gCurrentPinballGame->legendaryFlashState = 0;
        }
        else if (
            (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
             && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_CATCH_HIT_PHASE)
            || (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE
                 && gCurrentPinballGame->boardSubState == JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE))
        {
            DmaCopy16(3, &gCatchSpritePalettes, 0x050003A0, 0x20);
        }

        for (i = 0; i < 4; i++)
        {
            gCurrentPinballGame->ball->prevPositionsQ0[i].x = gCurrentPinballGame->ball->positionQ0.x;
            gCurrentPinballGame->ball->prevPositionsQ0[i].y = gCurrentPinballGame->ball->positionQ0.y;
        }
        break;
    case 12:
        temp_r0 = 99 - gCurrentPinballGame->captureSequenceFrame;
        gCurrentPinballGame->trapAngleQ16 -= (temp_r0 * ANGLE_45) / 100 - ANGLE_45;
        gCurrentPinballGame->ball->spinAngle -= DEG_TO_BAM(45);

        temp_r0 -= 20;

        if (temp_r0 < 0)
        {
            temp_r0 = 0;
            gCurrentPinballGame->ball->ballHidden = FALSE;
        }

        {
            s32 var_3 = (gCurrentPinballGame->trapSpinRadius * temp_r0) / 80;

            gCurrentPinballGame->ball->positionQ8.x =
                (gCurrentPinballGame->catchTargetX << 8) + Cos(gCurrentPinballGame->trapAngleQ16) * var_3 / 20000;
            gCurrentPinballGame->ball->positionQ8.y =
                (gCurrentPinballGame->catchTargetY << 8) - Sin(gCurrentPinballGame->trapAngleQ16) * var_3 / 20000;
        }
        break;

    case 13:
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ballTrailEnabled = FALSE;
        gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
        break;

    case 14:
        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
        break;

    case 15:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i= gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
        break;

    case 16:
        if (gCurrentPinballGame->captureSequenceFrame == 0)
            m4aSongNumStart(SE_MON_CATCH_ENERGY_BEAM);

        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle = 0x7000;
        break;

    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX];

        if (spriteGroup->active)
        {
            gCurrentPinballGame->ball->ballHidden = TRUE;
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;
            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }
        gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX]->active = TRUE;

        if (gCurrentPinballGame->captureSequenceTimer == 18 || gCurrentPinballGame->captureSequenceTimer == 20 || gCurrentPinballGame->captureSequenceTimer == 21)
        {
            gCurrentPinballGame->captureFlashTimer = 200;

            if (gMain.selectedField >= FIELD_BOSS_START)
                gCurrentPinballGame->legendaryFlashState = 1;
            else if (
                (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                 && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_CATCH_HIT_PHASE)
                || (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE
                    && gCurrentPinballGame->boardSubState == JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE))
                DmaCopy16(3, &gCatchSequencePalA, 0x050003A0, 0x20);
        }
        else if (gCurrentPinballGame->captureSequenceTimer == 19 || gCurrentPinballGame->captureSequenceTimer == 22)
        {
            if (gMain.selectedField >= FIELD_BOSS_START)
                gCurrentPinballGame->legendaryFlashState = 3;
            else if (
                (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                    && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_CATCH_HIT_PHASE)
                || (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE
                    && gCurrentPinballGame->boardSubState == JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE))
                DmaCopy16(3, &gCatchSequencePalC, 0x050003A0, 0x20);
        }

        if (gCurrentPinballGame->captureSequenceTimer == 23)
        {
            if (gMain.selectedField >= FIELD_BOSS_START)
                gCurrentPinballGame->legendaryFlashState = 10;
            else
            {
                if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                    && gCurrentPinballGame->boardSubState == CATCH_EM_SUBSTATE_CATCH_HIT_PHASE)
                {
                    CleanupCatchMonBoardSprite();
                    gCurrentPinballGame->catchMonCollisionEnabled = FALSE;
                    m4aMPlayAllStop();
                }

                if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE
                    && gCurrentPinballGame->boardSubState == JIRACHI_CATCH_SUBSTATE_CATCH_HIT_PHASE)
                {
                    CleanupJirachiSprites();
                    gCurrentPinballGame->catchMonCollisionEnabled = FALSE;
                    m4aMPlayAllStop();
                }
            }
        }

        if (gCurrentPinballGame->captureSequenceTimer == 28)
        {
            if (gCurrentPinballGame->captureSequenceFrame == 0)
            {
                m4aMPlayAllStop();
                PlayRumble(8);
            }

            if (gCurrentPinballGame->captureSequenceFrame == 2)
                m4aSongNumStart(SE_MON_CATCH_BALL_CLOSE);
        }
        break;

    case 26:
        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX];

        if (spriteGroup->active)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                    gOamBuffer[oamSimple->oamId].priority = 0;
                }
            }
            else
            {
                for (i = 0; i <= 15; i++)
                {
                    oamSimple = &spriteGroup->oam[i];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 0];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 1];
                    *dst++ = gPokeballCaptureOamFrames[temp_r3][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                    gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
                }
            }
        }

        break;

    case 29:
        gMain.blendBrightness = 4;
        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);

        spriteGroup = gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX];

        if (spriteGroup->active)
        {
            for (i = 0; i <= 21; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].y = 190;
            }
        }

        gMain.fieldSpriteGroups[FIELD_SG_CAPTURE_MON_BALL_FX]->active = FALSE;
        gCurrentPinballGame->ball->ballHidden = FALSE;
        gCurrentPinballGame->ball->velocity.y = -256;
        gCurrentPinballGame->ball->velocity.x = 40;
        gCurrentPinballGame->ball->spinSpeed = 256;

        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->activePortraitType = 0;

        break;

    case 30:
        if (gCurrentPinballGame->captureSequenceFrame <= 7)
        {
            if (gCurrentPinballGame->captureSequenceFrame <= 3)
            {
                if (gCurrentPinballGame->captureSequenceFrame == 0)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, 0x05000340, 0x60);
                    gCurrentPinballGame->activePaletteIndex = 1;
                    gCurrentPinballGame->paletteSwapActive = TRUE;
                }
            }
            else
            {
                gMain.blendBrightness = 0;

                if (gCurrentPinballGame->captureSequenceFrame > 4)
                {
                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], 0x05000200, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, 0x05000240, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, 0x05000240, 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x140, 0x05000340, 0x60);

                    gCurrentPinballGame->activePaletteIndex = 0;
                    gCurrentPinballGame->paletteSwapActive = TRUE;
                }
            }
        }

        if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE
            || gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE)
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += ((118 << 8) - gCurrentPinballGame->ball->positionQ8.x) / 30;

            if (gCurrentPinballGame->ball->positionQ8.y >= 314 << 8)
            {
                if (gCurrentPinballGame->ball->velocity.y > 49)
                    m4aSongNumStart(SE_MON_CATCH_BALL_HIT_GROUND);

                if (gCurrentPinballGame->ball->velocity.y <= -50)
                    m4aSongNumStart(SE_MON_CATCH_BALL_HIT_GROUND);

                gCurrentPinballGame->ball->positionQ8.y = 314 << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 7) / 10;

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                    gCurrentPinballGame->ball->spinSpeed = -gCurrentPinballGame->ball->spinSpeed;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }

            {
                s16 var_4 = gCurrentPinballGame->ball->velocity.y;

                if (var_4 < 0)
                    var_4 = -var_4;

                if (var_4 > 256)
                    gCurrentPinballGame->captureSequenceFrame--;
            }
        }
        else
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;

            if (gCurrentPinballGame->ball->positionQ8.y >= (gCurrentPinballGame->catchTargetY + 50) << 8)
            {
                m4aSongNumStart(SE_MON_CATCH_BALL_HIT_GROUND);
                gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->catchTargetY + 50) << 8;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * -45) / 100;
                gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 7) / 10;

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                    gCurrentPinballGame->ball->spinSpeed = -gCurrentPinballGame->ball->spinSpeed;

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 7) / 10;

                if (gCurrentPinballGame->ball->velocity.x > 0)
                    gCurrentPinballGame->ball->velocity.x = -gCurrentPinballGame->ball->velocity.x;
            }
        }

        gCurrentPinballGame->trapAngleQ16 = 0;
        break;

    case 31:
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        break;

    case 32:
        temp_r0 = 237 - gCurrentPinballGame->captureSequenceFrame;

        if (temp_r0 <= 191)
        {
            if (temp_r0 > 183)
            {
                if (temp_r0 == 185)
                    PlayRumble(6);

                if (temp_r0 == 184)
                    m4aSongNumStart(SE_MON_CATCH_BALL_SHAKE);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->spinAngle -= 0x400;
            }
            else if (temp_r0 > 175)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->spinAngle += 0x400;
            }
            else if (temp_r0 > 167)
            {
                if (temp_r0 == 169)
                    PlayRumble(6);

                if (temp_r0 == 168)
                    m4aSongNumStart(SE_MON_CATCH_BALL_SHAKE);

                gCurrentPinballGame->ball->positionQ8.x -= 96;
                gCurrentPinballGame->ball->spinAngle -= 0x400;
            }
            else if (temp_r0 > 159)
            {
                gCurrentPinballGame->ball->positionQ8.x += 96;
                gCurrentPinballGame->ball->spinAngle += 0x400;
            }
            else if (temp_r0 <= 123)
            {
                if (temp_r0 > 115)
                {
                    if (temp_r0 == 117)
                        PlayRumble(6);

                    if (temp_r0 == 116)
                        m4aSongNumStart(SE_MON_CATCH_BALL_SHAKE);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->spinAngle -= 0x400;
                }
                else if (temp_r0 > 107)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->spinAngle += 0x400;
                }
                else if (temp_r0 > 99)
                {
                    if (temp_r0 == 101)
                        PlayRumble(6);

                    if (temp_r0 == 100)
                        m4aSongNumStart(SE_MON_CATCH_BALL_SHAKE);

                    gCurrentPinballGame->ball->positionQ8.x -= 96;
                    gCurrentPinballGame->ball->spinAngle -= 0x400;
                }
                else if (temp_r0 > 91)
                {
                    gCurrentPinballGame->ball->positionQ8.x += 96;
                    gCurrentPinballGame->ball->spinAngle += 0x400;
                }
            }
        }

        if (temp_r0 == 0)
        {
            m4aSongNumStart(MUS_SUCCESS);
            InitEvolutionSuccessDisplay();
        }

        break;

    case 33:
        gCurrentPinballGame->ball->oamPriority = 3;
        AnimateWasCaughtBanner();

        if (gCurrentPinballGame->captureSequenceFrame <= 229 && gCurrentPinballGame->nameRevealAnimFrame == 150)
            gCurrentPinballGame->nameRevealAnimFrame--;

        if (gCurrentPinballGame->captureSequenceFrame == 270 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
        }

        if (gCurrentPinballGame->captureSequenceFrame <= 29)
        {
            gMain.scoreOverlayActive = TRUE;
            temp_r0 = gCurrentPinballGame->captureSequenceFrame;
            gCurrentPinballGame->cutsceneTilemapColumn = temp_r0;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBG0TilemapBuffer[(i + 15) * 32 + j] = 0xC100;
                }
            }

            DmaCopy16(3, &gBG0TilemapBuffer, 0x06002000, 0x800);
        }

        if (gCurrentPinballGame->captureSequenceFrame >= 240 && gCurrentPinballGame->captureSequenceFrame <= 269)
        {
            temp_r0 = gCurrentPinballGame->captureSequenceFrame - 240;

            for (j = 0; j <= temp_r0; j++)
            {
                for (i = 1; i <= 10; i++)
                {
                    gBG0TilemapBuffer[(i + 15) * 32 + j] = 511;
                }
            }

            DmaCopy16(3, &gBG0TilemapBuffer, 0x06002000, 0x800);

            if (gCurrentPinballGame->captureSequenceFrame == 269)
            {
                gMain.scoreOverlayActive = FALSE;

                if (gMain.selectedField < MAIN_FIELD_COUNT)
                {
                    gMain.blendControl = 0;
                    gMain.blendBrightness = 0;
                    gMain.blendAlpha = 0;
                }
            }
        }

        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->captureSequenceFrame = 181;

        if (gCurrentPinballGame->captureSequenceFrame == 180)
        {
            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE
                || gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;

                switch (gCurrentPinballGame->currentSpecies)
                {
                    //Rare catches
                case SPECIES_NOSEPASS:
                case SPECIES_SKARMORY:
                case SPECIES_LILEEP:
                case SPECIES_ANORITH:
                case SPECIES_FEEBAS:
                case SPECIES_CASTFORM:
                case SPECIES_KECLEON:
                case SPECIES_ABSOL:
                case SPECIES_WOBBUFFET:
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_RARE_CATCH;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_RARE_CATCH;
                    break;
                case SPECIES_LATIAS:
                case SPECIES_LATIOS:
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_LATI_CATCH;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_LATI_CATCH;
                    break;
                default:
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_NORMAL_CATCH;
                    break;
                }
            }

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            
                if (gCurrentPinballGame->currentSpecies == SPECIES_PICHU)
                {
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_PICHU_HATCH;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_PICHU_HATCH;
                }
                else
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_NORMAL_HATCH;
            }

            if (gMain.selectedField > MAIN_FIELD_COUNT)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                if (gMain.selectedField == FIELD_RAYQUAZA)
                {
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_LEGENDARY_CATCH;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_RAYQUAZA_CATCH;
                }
                else
                {
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_LEGENDARY_CATCH;
                    gCurrentPinballGame->scoreAddedInFrame = SCORE_KYRGRO_CATCH;
                }
            }
        }

        break;

    case 34:
        gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
        gCurrentPinballGame->ball->oamPriority = 3;
        gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_INACTIVE;
        gCurrentPinballGame->captureSequenceFrame = 0;
        gCurrentPinballGame->captureSequenceTimer = 0;

        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
            gCurrentPinballGame->ball->velocity.y = -10;
            gCurrentPinballGame->ball->velocity.x = 20;

            for (i = 0; i <= 2; i++)
            {
                if (i < gCurrentPinballGame->evoItemCount)
                    gCurrentPinballGame->catchLights[i] = 1;
                else
                    gCurrentPinballGame->catchLights[i] = 0;
            }

            if (gCurrentPinballGame->evoItemCount <= 2)
            {
                gCurrentPinballGame->evoCatchLightSlot1 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->evoCatchLightSlot2 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot1] = 1;
                gCurrentPinballGame->evoBlinkTimer = 120;
                gCurrentPinballGame->evoItemCount++;
            }

            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 90;

            if (gCurrentPinballGame->bonusCatchCount <= 98)
                gCurrentPinballGame->bonusCatchCount++;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
                gCurrentPinballGame->boardSubState = CATCH_EM_SUBSTATE_END_CATCH_HIT_PHASE;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_JIRACHI_CATCH_MODE)
                gCurrentPinballGame->boardSubState = JIRACHI_CATCH_SUBSTATE_BOARD_STATE_CLEANUP;

            if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
                gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_CLEANUP_MON_SPRITES;

        }
        else
        {
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_CATCH_BANNER;
            gCurrentPinballGame->caughtMonCount++;

            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 91;
        }
        RegisterCaptureOrEvolution(0);
        break;
    }

    gCurrentPinballGame->ball->prevPositionsQ0[0].x = gCurrentPinballGame->ball->positionQ0.x;
    gCurrentPinballGame->ball->prevPositionsQ0[0].y = gCurrentPinballGame->ball->positionQ0.y;

    for (i = 2; i >= 0; i--)
    {
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].x = gCurrentPinballGame->ball->prevPositionsQ0[i].x;
        gCurrentPinballGame->ball->prevPositionsQ0[i + 1].y = gCurrentPinballGame->ball->prevPositionsQ0[i].y;
    }
}
