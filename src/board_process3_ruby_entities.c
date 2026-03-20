#include "global.h"
#include "functions.h"
#include "functions_ruby.h"
#include "main.h"

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
            randNum = Random();
            gCurrentPinballGame->rampPrizeType = ((randNum + gMain.systemFrameCount) % 100) + 1;
        }
    }

    if (gCurrentPinballGame->cameraYViewport < 110)
    {
        UpdateNuzleafEntity();
        AnimateRubyShopDoor();
        DrawRubyNuzleafPlatformSprite();
    }
    AnimateOneUpSprite();
    if (gCurrentPinballGame->cameraYViewport < 168)
    {
        UpdateEggModeAnimation();
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
        UpdateRubyRampPrizeGate();
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
    UpdateEvolutionShopSprite();
    DrawBoardEdgeBanner();

    if (gCurrentPinballGame->coinRewardAmount != 0)
    {
        AnimateCoinReward();
    }
    BonusStage_HandleModeChangeFlags();

    if (gCurrentPinballGame->ballLaunchTimer != 0)
    {
        gCurrentPinballGame->ballLaunchTimer--;
        if (gCurrentPinballGame->ballLaunchTimer == 0)
        {
            gCurrentPinballGame->secondaryBall = gCurrentPinballGame->ballStates;
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

//Duplicate of HandleSapphireFlipperButtonInput, with "gCurrentPinballGame->rampGateHitFlag = 1;" added in the final if statement
void HandleRubyFlipperButtonInput(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pichuEntranceTimer == 0 && gCurrentPinballGame->kickbackFiring == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 0;
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

    if (gCurrentPinballGame->newButtonActions[1])
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pichuEntranceTimer == 0 && gCurrentPinballGame->kickbackFiring == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 1;
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

        gCurrentPinballGame->rampGateHitFlag = 1;
    }
}
