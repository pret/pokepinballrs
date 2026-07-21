#include "global.h"
#include "functions.h"
#include "functions_ruby.h"
#include "main.h"
#include "constants/board/main_board.h"

void UpdateRubyBoardEntityRendering(void)
{
    int randNum;

    ProcessBannerCameraTransition();
    SelectRubyShopDoorState();
    if (gCurrentPinballGame->rampPrizeRespawnTimer != 0)
    {
        gCurrentPinballGame->rampPrizeRespawnTimer--;
        if (gCurrentPinballGame->rampPrizeRespawnTimer == 0)
        {
            // Determine prize. Prize 1 = "1Up". (1% chance) All others is 'Ball Upgrade'.
            randNum = Random();
            gCurrentPinballGame->rampPrizeType = ((randNum + gMain.systemFrameCount) % 100) + 1;
        }
    }

    if (gCurrentPinballGame->cameraYViewport < 110)
    {
        UpdateNuzleafEntity();
        AnimateRubyShopDoor();
        DrawRubyRampPrize();
    }
    AnimateOneUpSprite();
    if (gCurrentPinballGame->cameraYViewport < 168)
    {
        UpdateRubyEggHatchAnimation();
    }
    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        UpdateHatchCave();
        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            DrawWhiscash();
        }
        else
        {
            RubyPondTriBumperHandleHitAndDraw();
        }
        AnimateSharpedoEntity();
        DrawPikachuSpinner();
    }
    UpdateChikoritaAttackAnimation();
    if (gCurrentPinballGame->cameraYViewport > 63)
    {
        AnimateChikoritaSprite();
        UpdateGulpinBossState();
    }
    if (gCurrentPinballGame->cameraYViewport > 115)
    {
        UpdateMakuhitaEntity();
    }
    if (gCurrentPinballGame->cameraYViewport > 130)
    {
        DrawRubySideBumperSprites();
    }
    UpdateSpoinkAnimation();
    if (gCurrentPinballGame->cameraYViewport > 168)
    {
        DrawSpoinkSprite();
    }

    UpdateKickbackLogic();
    ProcessChargeIndicator();
    UpdateRubyBoardAnimations();
    UpdatePortraitSpritePositions();
    UpdateRubyEvolutionShopSprite();
    DrawBoardEdgeBanner();

    if (gCurrentPinballGame->coinRewardAmount != 0)
    {
        AnimateCoinReward();
    }
    BonusStage_HandleModeChangeFlags();

    if (gCurrentPinballGame->altBallCameraTimer != 0)
    {
        gCurrentPinballGame->altBallCameraTimer--;
        if (gCurrentPinballGame->altBallCameraTimer == 0)
        {
            gCurrentPinballGame->cameraBall = gCurrentPinballGame->ballStates;
        }
    }
}

void UpdateRubyBoardEntityLogic(void)
{
    RubyPond_EntityLogic();
    UpdateRubyCatchModeAnimation();
    UpdatePikachuChargeCounter();
    UpdateRubySideBumperAnimation();
    if (gCurrentPinballGame->mainBoardCountdownTimer != 0)
    {
        gCurrentPinballGame->mainBoardCountdownTimer--;
    }
}

//Duplicate of HandleSapphireFlipperButtonInput, with "gCurrentPinballGame->makuhitaPunchTriggeredFlag = TRUE;" added in the final if statement
void HandleRubyFlipperButtonInput(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER])
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 0
            && gCurrentPinballGame->outLanePikaPosition != PIKA_BOTH_SIDES
            && gCurrentPinballGame->pichuEntranceTimer == 0
            && !gCurrentPinballGame->kickbackFiring)
        {
            gCurrentPinballGame->outLanePikaPosition = PIKA_LEFT_SIDE;
        }

        tmp = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = tmp;
    }

    if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 0
            && gCurrentPinballGame->outLanePikaPosition != PIKA_BOTH_SIDES
            && gCurrentPinballGame->pichuEntranceTimer == 0
            && !gCurrentPinballGame->kickbackFiring)
        {
            gCurrentPinballGame->outLanePikaPosition = PIKA_RIGHT_SIDE;
        }

        tmp = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = tmp;

        gCurrentPinballGame->makuhitaPunchTriggeredFlag = TRUE;
    }
}
