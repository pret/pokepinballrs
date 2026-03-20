#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SongHeader se_roulette_tick;
extern struct SongHeader se_unk_9a;
extern struct SongHeader se_ball_upgrade;

extern u16 gRouletteWheelContents[][7];
extern const u8 gPikachuSaverTilesGfx[];

extern const s16 gCaptureSequenceTimings[34];
extern const u8 gCaptureScreenTilesGfx[];
extern const s8 gCaptureShakeOffsets[];
extern const u16 gPokeballCaptureOamFrames[][0x30];
extern const u8 gBallUpgradeTilesGfx[];
extern const u8 gBallFlashPalette;

extern u8 gCatchSequencePalA;
extern u8 gCatchSequencePalB;
extern u8 gCatchSequencePalC;
extern u8 gCatchSpritePalettes[];

void InitRouletteWheel(void)
{
    s16 i;

    gMain.fieldSpriteGroups[23]->available = 1;
    gMain.fieldSpriteGroups[20]->available = 1;
    gMain.fieldSpriteGroups[21]->available = 1;
    gMain.blendControl = 0x1C10;
    gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
    gCurrentPinballGame->rouletteStopRequested = 0;
    gCurrentPinballGame->rouletteRotationPeriod = 8;
    gCurrentPinballGame->rouletteSpinSpeed = 0;
    gCurrentPinballGame->rouletteSubOffset = 0;
    if (gCurrentPinballGame->rouletteLevel == 25)
        gCurrentPinballGame->rouletteLevel = 10;

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->rouletteSlotValues[i] = gRouletteWheelContents[gCurrentPinballGame->rouletteLevel][i];
        if (gCurrentPinballGame->rouletteSlotValues[i] == 41)
        {
            if (gMain.selectedField == FIELD_RUBY)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = 42;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = 44;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = 45;
                    break;
                }
            }
            else
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    gCurrentPinballGame->rouletteSlotValues[i] = 41;
                    break;
                case 1:
                case 3:
                    gCurrentPinballGame->rouletteSlotValues[i] = 43;
                    break;
                case 4:
                    gCurrentPinballGame->rouletteSlotValues[i] = 45;
                    break;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 10)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + 10;
            else
                gCurrentPinballGame->rouletteSlotValues[i] = 12;
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 3)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
            {
                if (gMain.systemFrameCount & 1)
                {
                    if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                        gCurrentPinballGame->rouletteSlotValues[i] = gCurrentPinballGame->ballUpgradeType + 10;
                    else
                        gCurrentPinballGame->rouletteSlotValues[i] = 12;
                }
                else
                {
                    gCurrentPinballGame->rouletteSlotValues[i] = 1;
                }
            }
        }
        else if (gCurrentPinballGame->rouletteSlotValues[i] == 9)
        {
            if (gCurrentPinballGame->evolvablePartySize <= 0)
                gCurrentPinballGame->rouletteSlotValues[i] = 8;
        }
    }

    gCurrentPinballGame->roulettePortraitId = 21;
    if (gCurrentPinballGame->rouletteLevel < 25)
        gCurrentPinballGame->rouletteLevel++;

    gCurrentPinballGame->rouletteSlotCount = 5;
    if ((gCurrentPinballGame->jirachiActivationFlags & 0xF0) == 0 && gCurrentPinballGame->area > AREA_WILDERNESS)
        gCurrentPinballGame->rouletteSlotCount++;

    gCurrentPinballGame->rouletteSlotCursor = 1;
    gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->rouletteSlotValues[0];
    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[1];
    LoadPortraitGraphics(2, 0);
    LoadPortraitGraphics(2, 1);
}

void RunRouletteWheel(void)
{
    if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        if (gCurrentPinballGame->rouletteStopRequested == 0)
        {
            if ((gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)) && gCurrentPinballGame->zigzagoonShockWallActive)
            {
                gCurrentPinballGame->zigzagoonState = 2;
                if (gCurrentPinballGame->rouletteSubOffset < 17)
                    gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->modeOutcomeValues[0];

                gCurrentPinballGame->rouletteStopRequested = 1;
                gCurrentPinballGame->rouletteRotationPeriod = 40;
                gCurrentPinballGame->rouletteFrameIndex = 39;
            }
        }
    }

    if (gCurrentPinballGame->rouletteStopRequested == 0)
    {
        gCurrentPinballGame->portraitDisplayState = 1;
        gCurrentPinballGame->rouletteFrameIndex++;
        if (gCurrentPinballGame->rouletteSpinSpeed)
        {
            gCurrentPinballGame->rouletteSpinSpeed--;
            if (gCurrentPinballGame->rouletteSpinSpeed == 0)
            {
                gCurrentPinballGame->rouletteStopRequested = 1;
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
        else if (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->rouletteSpinSpeed = (Random() % 200) + 100;
            if (gMain.selectedField == FIELD_SAPPHIRE)
            {
                if (gCurrentPinballGame->zigzagoonState == 1)
                {
                    gCurrentPinballGame->rouletteSpinSpeed = 320;
                    gCurrentPinballGame->zigzagoonShockWallActive = 1;
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
            gMain.fieldSpriteGroups[23]->available = 0;
            gMain.fieldSpriteGroups[20]->available = 0;
            gMain.fieldSpriteGroups[21]->available = 0;
            gCurrentPinballGame->rouletteSubOffset = 0;
            gCurrentPinballGame->portraitDisplayState = 0;
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->shopPurchaseConfirmed = 1;
            gCurrentPinballGame->outcomeFrameCounter = 0;
        }
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 0)
    {
        gCurrentPinballGame->modeOutcomeValues[0] = gCurrentPinballGame->modeOutcomeValues[1];
        LoadPortraitGraphics(2, 0);
        gCurrentPinballGame->rouletteOutcomeId = gCurrentPinballGame->modeOutcomeValues[0];
    }

    if (gCurrentPinballGame->rouletteFrameIndex == 1)
    {
        if (gCurrentPinballGame->rouletteSlotCursor < gCurrentPinballGame->rouletteSlotCount)
            gCurrentPinballGame->rouletteSlotCursor++;
        else
            gCurrentPinballGame->rouletteSlotCursor = 0;

        gCurrentPinballGame->modeOutcomeValues[1] = gCurrentPinballGame->rouletteSlotValues[gCurrentPinballGame->rouletteSlotCursor];
        LoadPortraitGraphics(2, 1);
        MPlayStart(&gMPlayInfo_SE1, &se_roulette_tick);
    }
}

void ProcessRouletteOutcome(void)
{
    if (gCurrentPinballGame->outcomeFrameCounter < 180)
    {
        if (gCurrentPinballGame->outcomeFrameCounter == 4)
            m4aSongNumStart(MUS_UNKNOWN_0x14);

        if (gCurrentPinballGame->rouletteOutcomeId == 3)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 120)
                m4aSongNumStart(SE_UNKNOWN_0xB2);
        }

        gCurrentPinballGame->outcomeFrameCounter++;
        if (gCurrentPinballGame->outcomeFrameCounter < 80)
            LoadPortraitGraphics(8, 0);
    }

    switch (gCurrentPinballGame->rouletteOutcomeId)
    {
    case 0:
    case 1:
    case 2:
        gCurrentPinballGame->saverTimeRemaining = (gCurrentPinballGame->rouletteOutcomeId + 1) * 1800;
        break;
    case 3:
        if (gCurrentPinballGame->ballCatchState == 3)
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
                gCurrentPinballGame->outLanePikaPosition = 2;
                gMain.fieldSpriteGroups[41]->available = 0;
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
                gCurrentPinballGame->bannerGfxIndex = 0;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->pichuWalkMode = 1;
                gCurrentPinballGame->pichuEntranceTimer = 800;
                gCurrentPinballGame->outLanePikaPosition = 0;
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
    case 4:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->oneUpAnimTimer = 90;
        break;
    case 5:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 33;
        }
        break;
    case 6:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 6)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 24;
            else if ((s32) gCurrentPinballGame->rouletteLevel <= 0xA)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 24;
            else if (gCurrentPinballGame->rouletteLevel % 5 == 0)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 28;
            else
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 7) + 24;
        }
        break;
    case 7:
        if (gCurrentPinballGame->outcomeFrameCounter == 95)
        {
            gCurrentPinballGame->outcomeFrameCounter = 12;
            if (gCurrentPinballGame->rouletteLevel < 10)
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 3) + 36;
            else
                gCurrentPinballGame->rouletteOutcomeId = (gMain.systemFrameCount % 5) + 36;
        }
        break;
    case 8:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            RequestBoardStateTransition(4);
            gCurrentPinballGame->modeAnimTimer = 100;
        }
        break;
    case 9:
        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->outcomeFrameCounter == 149)
            {
                gCurrentPinballGame->shopEntryTimer = 180;
                gCurrentPinballGame->portraitDisplayState = 3;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 150)
            {
                gCurrentPinballGame->outcomeFrameCounter = 149;
                gCurrentPinballGame->evolutionShopActive = 1;
                UpdateShopEntryAnimation(1);
                gCurrentPinballGame->sapphireBumperState[0] = 3;
                gCurrentPinballGame->sapphireBumperState[1] = 3;
            }

            if (gCurrentPinballGame->outcomeFrameCounter == 170)
            {
                gCurrentPinballGame->shopDoorTargetFrame = 0;
                gCurrentPinballGame->evolutionShopActive = 0;
                RequestBoardStateTransition(6);
            }
        }
        break;
    case 10:
    case 11:
    case 12:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 13:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
            gCurrentPinballGame->ballUpgradeCounter = 3600;
            MPlayStart(&gMPlayInfo_SE1, &se_ball_upgrade);
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }
        break;
    case 17:
    case 18:
    case 19:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
        {
            gCurrentPinballGame->coinRewardLevel = 1;
            gCurrentPinballGame->coinRewardAmount = (gCurrentPinballGame->rouletteOutcomeId - 17) * 20 + 10;
            gCurrentPinballGame->coinRewardTimer = 0;
        }

        if (gCurrentPinballGame->outcomeFrameCounter == 140)
            gCurrentPinballGame->outcomeFrameCounter = 139;
        break;
    case 20:
        if (gCurrentPinballGame->outcomeFrameCounter == 130)
            gCurrentPinballGame->timerBonus = 1800;
        break;
    case 21:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->modeAnimTimer = 100;
            gCurrentPinballGame->jirachiActivationFlags = 15;
            RequestBoardStateTransition(8);
        }
        break;
    case 22:
        if (gCurrentPinballGame->outcomeFrameCounter == 150 && gCurrentPinballGame->shouldProcessWhiscash == 0)
        {
            gCurrentPinballGame->rubyPondChangeTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->forcePondToWhiscash = TRUE;
        }
        break;
    case 23:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
        {
            gCurrentPinballGame->bumperHitsSinceReset = 100;
            gCurrentPinballGame->pelipperFrameTimer = 1800;
            gCurrentPinballGame->pelipperState = 1;
        }
        break;
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->outcomeFrameCounter = 81;

        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->rouletteOutcomeId - 23) * 1000000;
        }
        break;
    case 33:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 100;
        }
        break;
    case 34:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 500;
        }
        break;
    case 35:
        if (gCurrentPinballGame->outcomeFrameCounter == 70) {
            m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            gCurrentPinballGame->scoreAddedInFrame = 900;
        }
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        if (gCurrentPinballGame->outcomeFrameCounter == 70)
        {
            gCurrentPinballGame->progressLevel += gCurrentPinballGame->rouletteOutcomeId + 221;
            if (gCurrentPinballGame->progressLevel > 99)
                gCurrentPinballGame->progressLevel = 99;
        }
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
        if (gCurrentPinballGame->outcomeFrameCounter == 150)
            RequestBoardStateTransition(3);
        break;
    }
}

//Gravity well + functionality
void RunBallCaptureSequence(void)
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

        if (gMain.selectedField < MAIN_FIELD_COUNT && (gCurrentPinballGame->boardState == 4 || gCurrentPinballGame->boardState == 8))
            gCurrentPinballGame->boardModeType = 1;

        gCurrentPinballGame->ballFrozenState = 1;

        gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
        gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        gCurrentPinballGame->ball->positionQ8.x += gCurrentPinballGame->ball->velocity.x;
        gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;

        gCurrentPinballGame->activePortraitType = 9;
        DmaCopy16(3, gCaptureScreenTilesGfx, 0x06015800, 0x1C00);
        DmaCopy16(3, &gBallUpgradeTilesGfx[gCurrentPinballGame->ballUpgradeType << 9], 0x060164C0, 0x80);
        DmaCopy16(3, &gBallUpgradeTilesGfx[((gCurrentPinballGame->ballUpgradeType * 8 + 4) << 6)], 0x06016760, 0x80);

        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;

        if (gCurrentPinballGame->captureSequenceFrame == 1)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            gCurrentPinballGame->ballTrailEnabled = 1;
        }

        break;

    case 1:
        if (gCurrentPinballGame->boardState == 4)
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
            MPlayStart(&gMPlayInfo_SE1, &se_unk_9a);

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
            gCurrentPinballGame->paletteSwapActive = 1;
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
            gCurrentPinballGame->paletteSwapActive = 1;
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
            if (gMain.selectedField <= 3 &&
                (
                    (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
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

        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            if (gCurrentPinballGame->boardState == 5)
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

        gMain.fieldSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequenceTimer == 10 && gCurrentPinballGame->captureSequenceFrame == 3)
            gMain.fieldSpriteGroups[3]->available = 0;
        break;
    case 11:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i=gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);

        tempVector.x = (gCurrentPinballGame->catchTargetX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->catchTargetY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);

        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

        if (gMain.selectedField > 3)
        {
            gCurrentPinballGame->legendaryFlashState = 0;
        }
        else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                 (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
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
        gCurrentPinballGame->trapAngleQ16 -= (temp_r0 * 0x2000) / 100 - 0x2000;
        gCurrentPinballGame->ball->spinAngle -= 0x2000;

        temp_r0 -= 20;

        if (temp_r0 < 0)
        {
            temp_r0 = 0;
            gCurrentPinballGame->ball->ballHidden = 0;
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
        gCurrentPinballGame->ballTrailEnabled = 0;
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 14:
        DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 15:
        //TODO: fakematch; unused i. Here for the +4 to parse correctly;
        DmaCopy16(3, gBallPalettes[i= gCurrentPinballGame->ballUpgradeType + 4], 0x05000220, 0x20);
        gCurrentPinballGame->ball->spinAngle -= 0x2000;
        break;

    case 16:
        if (gCurrentPinballGame->captureSequenceFrame == 0)
            m4aSongNumStart(0x9B);

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
        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            gCurrentPinballGame->ball->ballHidden = 1;
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;
            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
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
        gMain.fieldSpriteGroups[3]->available = 1;

        if (gCurrentPinballGame->captureSequenceTimer == 18 || gCurrentPinballGame->captureSequenceTimer == 20 || gCurrentPinballGame->captureSequenceTimer == 21)
        {
            gCurrentPinballGame->captureFlashTimer = 200;

            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 1;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gCatchSequencePalA, 0x050003A0, 0x20);
        }
        else if (gCurrentPinballGame->captureSequenceTimer == 19 || gCurrentPinballGame->captureSequenceTimer == 22)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 3;
            else if ((gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9) ||
                    (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3))
                DmaCopy16(3, &gCatchSequencePalC, 0x050003A0, 0x20);
        }

        if (gCurrentPinballGame->captureSequenceTimer == 23)
        {
            if (gMain.selectedField > 3)
                gCurrentPinballGame->legendaryFlashState = 10;
            else
            {
                if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 9)
                {
                    CleanupCaughtPokemonSprite();
                    gCurrentPinballGame->jirachiCollisionEnabled = 0;
                    m4aMPlayAllStop();
                }

                if (gCurrentPinballGame->boardState == 8 && gCurrentPinballGame->boardSubState == 3)
                {
                    CleanupJirachiSprites();
                    gCurrentPinballGame->jirachiCollisionEnabled = 0;
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
                m4aSongNumStart(0x9C);
        }
        break;

    case 26:
        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            spriteGroup->baseX = gCurrentPinballGame->ball->screenPosition.x;
            spriteGroup->baseY = gCurrentPinballGame->ball->screenPosition.y;

            temp_r3 = gCaptureShakeOffsets[gCurrentPinballGame->captureSequenceTimer - 17] + 7;

            if (gCurrentPinballGame->boardState == 5)
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

        spriteGroup = gMain.fieldSpriteGroups[3];

        if (spriteGroup->available != 0)
        {
            for (i = 0; i <= 21; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].y = 190;
            }
        }

        gMain.fieldSpriteGroups[3]->available = 0;
        gCurrentPinballGame->ball->ballHidden = 0;
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
                    gCurrentPinballGame->paletteSwapActive = 1;
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
                    gCurrentPinballGame->paletteSwapActive = 1;
                }
            }
        }

        if (gCurrentPinballGame->boardState == 5 || gCurrentPinballGame->boardState == 8)
        {
            gCurrentPinballGame->ball->velocity.y += 16;
            gCurrentPinballGame->ball->positionQ8.y += gCurrentPinballGame->ball->velocity.y;
            gCurrentPinballGame->ball->positionQ8.x += ((118 << 8) - gCurrentPinballGame->ball->positionQ8.x) / 30;

            if (gCurrentPinballGame->ball->positionQ8.y >= 314 << 8)
            {
                if (gCurrentPinballGame->ball->velocity.y > 49)
                    m4aSongNumStart(0x9D);

                if (gCurrentPinballGame->ball->velocity.y <= -50)
                    m4aSongNumStart(0x9D);

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
                m4aSongNumStart(0x9D);
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
                    m4aSongNumStart(158);

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
                    m4aSongNumStart(0x9E);

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
                        m4aSongNumStart(0x9E);

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
                        m4aSongNumStart(0x9E);

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
            m4aSongNumStart(0x11);
            InitEvolutionSuccessDisplay();
        }

        break;

    case 33:
        gCurrentPinballGame->ball->oamPriority = 3;
        AnimateEvolutionSuccessScreen();

        if (gCurrentPinballGame->captureSequenceFrame <= 229 && gCurrentPinballGame->nameRevealAnimFrame == 150)
            gCurrentPinballGame->nameRevealAnimFrame--;

        if (gCurrentPinballGame->captureSequenceFrame == 270 && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            LoadPortraitGraphics(0, 0);
            gCurrentPinballGame->portraitDisplayState = 0;
        }

        if (gCurrentPinballGame->captureSequenceFrame <= 29)
        {
            gMain.scoreOverlayActive = 1;
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
                gMain.scoreOverlayActive = 0;

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
            if (gCurrentPinballGame->boardState == 4 || gCurrentPinballGame->boardState == 8)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                switch (gCurrentPinballGame->currentSpecies) 
                {
                case 59:
                case 114:
                case 132:
                case 134:
                case 139:
                case 141:
                case 144:
                case 151:
                case 160:
                    gCurrentPinballGame->scoreAddStepSize = 80000;
                    gCurrentPinballGame->scoreAddedInFrame = 5000000;
                    break;
                case 195:
                case 196:
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                    break;
                default:
                    gCurrentPinballGame->scoreAddedInFrame = 1000000;
                    break;
                }
            }

            if (gCurrentPinballGame->boardState == 5)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            
                if (gCurrentPinballGame->currentSpecies == SPECIES_PICHU)
                {
                    gCurrentPinballGame->scoreAddStepSize = 140000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
                else
                    gCurrentPinballGame->scoreAddedInFrame = 3000000;
            }

            if (gMain.selectedField > MAIN_FIELD_COUNT)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                
                if (gMain.selectedField == FIELD_RAYQUAZA)
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 30000000;
                }
                else
                {
                    gCurrentPinballGame->scoreAddStepSize = 400000;
                    gCurrentPinballGame->scoreAddedInFrame = 10000000;
                }
            }
        }

        break;

    case 34:
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        gCurrentPinballGame->ball->oamPriority = 3;
        gCurrentPinballGame->captureState = 0;
        gCurrentPinballGame->captureSequenceFrame = 0;
        gCurrentPinballGame->captureSequenceTimer = 0;

        if (gMain.selectedField < MAIN_FIELD_COUNT)
        {
            gCurrentPinballGame->ballFrozenState = 0;
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

            if (gCurrentPinballGame->boardState == 4)
                gCurrentPinballGame->boardSubState = 10;

            if (gCurrentPinballGame->boardState == 8)
                gCurrentPinballGame->boardSubState = 5;

            if (gCurrentPinballGame->boardState == 5)
                gCurrentPinballGame->boardSubState = 6;

        }
        else
        {
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->portraitDisplayState = 3;
            gCurrentPinballGame->boardState = 4;
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
