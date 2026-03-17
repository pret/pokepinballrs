#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const void (*gBoardStateInitFuncs[])(void);
extern const void (*gBoardStateUpdateFuncs[])(void);

extern void HandleBoardStateTransitionTeardown(void);
extern void UpdateRubyBoardEntityRendering(void);
extern void UpdateRubyBoardEntityLogic(void);
extern void HandleRubyFlipperButtonInput(void);
extern void UpdateNuzleafEntity(void);
extern void SelectShopDoorState(void);
extern void AnimateShopDoor(void);
extern void DrawWhiscash(void);
extern void RubyPond_EntityLogic(void);
extern void RubyPondTriBumperHandleHitAndDraw(void);
extern void AnimateSharpedoEntity(void);
extern void DrawPikachuSpinner(void);
extern void UpdateChikoritaAttackAnimation(void);
extern void AnimateChikoritaSprite(void);
extern void UpdateGulpinBossState(void);
extern void UpdateSideBumperAnimation(void);
extern void DrawSideBumperSprites(void);
extern void UpdateEvolutionShopSprite(void);
extern void InitEggModeAnimation(void);
extern void UpdateEggModeAnimation(void);
extern void UpdateEggHatchDisplay(void);
extern void UpdateRubyRampPrizeGate(void);
extern void DrawRubyNuzleafPlatformSprite(void);
extern void LoadShopItemGraphics(s16);

void RubyBoardProcess_3A_19A20(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    UpdateNuzleafEntity();
    LoadShopItemGraphics(0);
    AnimateShopDoor();
    InitEggModeAnimation();
    UpdateEggModeAnimation();

    gCurrentPinballGame->cyndaquilCaveSpriteX = 73;
    gCurrentPinballGame->cyndaquilCaveSpriteY = 154;
    gCurrentPinballGame->eggCaveState = 0;
    UpdateEggHatchDisplay();
    RubyPond_EntityLogic();

    gCurrentPinballGame->pondBumperStates[0] = 10;
    gCurrentPinballGame->pondBumperStates[1] = 10;
    gCurrentPinballGame->pondBumperStates[2] = 10;
    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_STAGGERED;
    RubyPondTriBumperHandleHitAndDraw();
    AnimateSharpedoEntity();

    gCurrentPinballGame->pikachuSpinFrame = 0;
    gCurrentPinballGame->pikachuSpinPrevFrame = 1;
    UpdatePikachuChargeCounter();
    ProcessChargeIndicator();
    DrawPikachuSpinner();

    gCurrentPinballGame->chargeIndicatorScaleX = 256;
    gCurrentPinballGame->chargeIndicatorScaleY = 256;
    gCurrentPinballGame->rampPrizeType = 2;
    DrawRubyNuzleafPlatformSprite();

    gCurrentPinballGame->sideBumperShakeOffset[0] = 3;
    gCurrentPinballGame->sideBumperShakeOffset[1] = 3;
    DrawBoardEdgeBanner();
}

void RubyBoardProcess_3B_19B10(void)
{
    BoardStateDispatcher();
    UpdateRubyBoardEntityRendering();

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        UpdateRubyBoardEntityLogic();
    }

    HandleRubyFlipperButtonInput();
    if (gCurrentPinballGame->bgmFadeTimer != 0)
    {
        gCurrentPinballGame->bgmFadeTimer--;
        if (gCurrentPinballGame->bgmFadeTimer == 0)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        }
    }
}

void RequestBoardStateTransition(u8 arg0)
{
    gCurrentPinballGame->boardTransitionPhase = 2;
    gCurrentPinballGame->nextBoardState = arg0;
    if (gCurrentPinballGame->boardState == 2)
        gMain.fieldSpriteGroups[13]->available = 0;
}

void BoardStateDispatcher(void)
{
    switch (gCurrentPinballGame->boardTransitionPhase)
    {
        case 0:
            gBoardStateInitFuncs[gCurrentPinballGame->boardState]();
            gCurrentPinballGame->boardTransitionPhase++;
            break;
        case 1:
            gBoardStateUpdateFuncs[gCurrentPinballGame->boardState]();
            break;
        case 2:
            HandleBoardStateTransitionTeardown();
            gCurrentPinballGame->prevBoardState = gCurrentPinballGame->boardState;
            gCurrentPinballGame->boardState = gCurrentPinballGame->nextBoardState;
            gCurrentPinballGame->boardTransitionPhase = 0;
            break;
    }
}

void InitFieldIdle(void)
{
    s16 num1;
    u8 num2;

    if (gCurrentPinballGame->prevBoardState > 0)
    {
        if (gMain.selectedField == FIELD_RUBY)
        {
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_RUBY);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_RUBY2);
            }
        }
        else
        {
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_SAPPHIRE);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
            }
        }
    }

    num2 = gCurrentPinballGame->prevBoardState - 1;
    if (num2 > 1)
    {
        gCurrentPinballGame->evoArrowProgress = gCurrentPinballGame->arrowProgressPreserved;
        gCurrentPinballGame->catchArrowProgress = gCurrentPinballGame->catchModeArrows;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->catchModeArrows = 0;
    }
}

void UpdateFieldIdle(void)
{
    if (gCurrentPinballGame->allHolesLit != 0)
    {
        if (gCurrentPinballGame->allHolesLitDelayTimer != 0)
        {
            gCurrentPinballGame->allHolesLitDelayTimer--;
        }
        else
        {
            RequestBoardStateTransition(2);
        }
    }
}

void HandleBoardStateTransitionTeardown(void)
{
    if (gCurrentPinballGame->boardState == 2 && gCurrentPinballGame->nextBoardState > 2)
        ResetCatchState(0);

    if (gCurrentPinballGame->boardState > 2)
        return;

    if (gCurrentPinballGame->nextBoardState == 3)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }

    if (gCurrentPinballGame->nextBoardState == 4)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState == 6)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState > 3)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
}

void UpdateRubyBoardEntityRendering(void)
{
    int randNum;

    ProcessBannerCameraTransition();
    SelectShopDoorState();
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
        AnimateShopDoor();
        DrawRubyNuzleafPlatformSprite();
    }
    AnimateOneUpSprite();
    if (gCurrentPinballGame->cameraYViewport < 168)
    {
        UpdateEggModeAnimation();
    }
    if (gCurrentPinballGame->cameraYViewport < 220)
    {
        UpdateEggHatchDisplay();
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
        DrawSideBumperSprites();
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
    UpdateSideBumperAnimation();
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
