#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/sapphire_states.h"

//#include "constants/pinball_game.h"

extern void HandleSapphireFlipperButtonInput(void);

void SapphireBoardProcess_3A_326F4(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    gCurrentPinballGame->pikachuSpinFrame = 0;
    gCurrentPinballGame->pikachuSpinPrevFrame = 1;

    UpdatePikachuChargeCounter();
    ProcessChargeIndicator();
    DrawPikachuSpinner();
    CalculateRubyBumperBounce();
    HandleRubyBumperHit();

    gCurrentPinballGame->chargeIndicatorScaleX = 0x100;
    gCurrentPinballGame->chargeIndicatorScaleY = 0x100;

    InitSapphireEggHatchState();
    UpdateSapphireEggHatchAnimation();
    UpdateSapphireShopSignAnimation();
    DrawSapphireShopSignSprite();
    UpdatePelipperPondEntity();
    DrawBoardEdgeBanner();
}

void SapphireBoardProcess_3B_3276C(void)
{
    BoardStateDispatcher();
    UpdateSapphireBoardEntityRendering();

    if (!gMain.modeChangeFlags)
        UpdateSapphireBoardEntityLogic();

    HandleSapphireFlipperButtonInput();

    if (gCurrentPinballGame->bgmFadeTimer)
    {
        gCurrentPinballGame->bgmFadeTimer--;
        if (!gCurrentPinballGame->bgmFadeTimer)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void UpdateSapphireBoardEntityRendering(void)
{
    s32 temp;

    UpdateSapphireBoardAnimations();
    ProcessBannerCameraTransition();
    AnimateOneUpSprite();

    if (gCurrentPinballGame->cameraYViewport < 0x5a)
    {
        UpdateSapphireEggHatchAnimation();
        UpdateSapphireEggMachine();
    }

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->sapphireHatchMachineFrameIx == 3 && 
            gCurrentPinballGame->sapphireHatchMachineState == 0)
        {
            gCurrentPinballGame->catchArrowPaletteActive = 1;
        }
        else
        {
            gCurrentPinballGame->catchArrowPaletteActive = 0;
        }
    }
    else
    {
        gCurrentPinballGame->catchArrowPaletteActive = 0;
    }

    if (gCurrentPinballGame->cameraYViewport < 0x96)
    {
        UpdatePelipperPondEntity();
        DrawSapphireShopSignSprite();
    }
    if (gCurrentPinballGame->cameraYViewport < 0xC4)
    {
        HandleRubyBumperHit();
        AnimateWailmerEntity();
    }
    if (gCurrentPinballGame->cameraYViewport < 0xCA)
    {
        DrawSapphireBumperSprites();
    }
    if (gCurrentPinballGame->cameraYViewport < 0xDC)
    {
        DrawPikachuSpinner();
    }

    UpdateSapphireSeedotCollection();

    if (0x76 < gCurrentPinballGame->cameraYViewport)
    {
        DrawZigzagoonAndRouletteStopPrompt();
        DrawSapphireSeedotAndBasketSprites();
    }

    UpdateSpoinkAnimation();

    if (0xA8 < gCurrentPinballGame->cameraYViewport)
        DrawSpoinkSprite();

    UpdateKickbackLogic();
    ProcessChargeIndicator();
    UpdatePortraitSpritePositions();
    DrawBoardEdgeBanner();

    if (gCurrentPinballGame->coinRewardAmount)
        AnimateCoinReward();

    BonusStage_HandleModeChangeFlags();
}

void UpdateSapphireBoardEntityLogic(void)
{
    CalculateRubyBumperBounce();
    UpdateSapphireCatchModeAnimation();
    UpdatePikachuChargeCounter();

    if (gCurrentPinballGame->mainBoardCountdownTimer)
        gCurrentPinballGame->mainBoardCountdownTimer--;

    UpdateZigzagoonEntity();
    DecrementPelipperTimer();
    UpdateSapphireShopSignAnimation();

    if (!(gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME))
        UpdateSapphireBumperLogic();
}

void DispatchSapphireCatchModeInit(void)
{
    if (gMain.modeChangeFlags != MODE_CHANGE_NONE)
        return;

    switch (gCurrentPinballGame->ballCatchState)
    {
    case TRAP_CATCH_HOLE:
        InitSapphireWailmerCatch();
        break;
    case TRAP_EVO_SHOP_HOLE:
        InitSapphireEvolutionShopCatch();
        break;
    case TRAP_CENTER_HOLE:
        InitCenterTrapMode();
        break;
    }

    gCurrentPinballGame->collisionCooldownTimer = 60;
}

void UpdateSapphireCatchModeAnimation(void)
{
    if (gCurrentPinballGame->collisionCooldownTimer)
        gCurrentPinballGame->collisionCooldownTimer--;

    switch (gCurrentPinballGame->ballCatchState)
    {
    case TRAP_CATCH_HOLE:
        UpdateSapphireWailmerCatchSequence();
        break;
    case TRAP_EVO_SHOP_HOLE:
        UpdateSapphireEvolutionShopSequence();
        break;
    case TRAP_CENTER_HOLE:
        AnimateCenterTrapSequence(); //Center Hole
        break;
    }
}

void InitSapphireEvolutionShopCatch(void)
{
    gCurrentPinballGame->modeAnimTimer = 0xB4;
    gCurrentPinballGame->shopEntryTimer = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
}

void UpdateSapphireEvolutionShopSequence(void)
{
    s16 i;

    if (gCurrentPinballGame->modeAnimTimer > 0x18)
    {
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->modeAnimTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 58;
        gCurrentPinballGame->ball->positionQ0.y = 178;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

        if (gCurrentPinballGame->modeAnimTimer <= 0x31)
        {
            gCurrentPinballGame->modeAnimTimer++;
        }

        UpdateShopEntryAnimation(gCurrentPinballGame->evolutionShopActive);

        if (gCurrentPinballGame->evolutionShopActive)
        {
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->sapphireBumperAnimKeyframe[i] = 10;
                gCurrentPinballGame->sapphireBumperAnimSubTimer[i] = 0;
                gCurrentPinballGame->sapphireBumperState[i] = 4;
            }
        }
    }
    else if (gCurrentPinballGame->modeAnimTimer > 0)
    {
        gCurrentPinballGame->modeAnimTimer--;
    }
    else
    {
        gCurrentPinballGame->ball->ballHidden = 0;
        gCurrentPinballGame->ballFrozenState = 0;
        gCurrentPinballGame->collisionCooldownTimer = 0x3C;
        gCurrentPinballGame->ball->velocity.x = 0x60;
        gCurrentPinballGame->ball->velocity.y = 0xC0;
        gCurrentPinballGame->ball->positionQ0.x = 0x3C;
        gCurrentPinballGame->ball->positionQ0.y = 0xB4;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ballCatchState = NOT_TRAPPED;

        m4aSongNumStart(SE_UNKNOWN_0xC3);

        if (gCurrentPinballGame->evoArrowProgress > 2 && gCurrentPinballGame->evolvablePartySize > 0) {
            RequestBoardStateTransition(6);
        }
    }
}

void InitSapphireWailmerCatch(void)
{
    if (gCurrentPinballGame->catchArrowProgress > 1)
        RequestBoardStateTransition(4);

    gCurrentPinballGame->modeAnimTimer = 100;
    gCurrentPinballGame->catchHoleAnimFrame = 2;
    gCurrentPinballGame->cameraScrollOffset = 0;
    gCurrentPinballGame->cameraScrollTarget = 30;
    gCurrentPinballGame->cameraScrollEnabled = 0;
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    m4aSongNumStart(SE_WHISCASH_CATCH_BALL);
    PlayRumble(8);
}

void UpdateSapphireWailmerCatchSequence(void)
{
    if (gCurrentPinballGame->modeAnimTimer)
    {
        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->modeAnimTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spinSpeed = 0;
        if (gCurrentPinballGame->modeAnimTimer > 97)
        {
            gCurrentPinballGame->boardEntityActive = 1;
            gCurrentPinballGame->catchHoleAnimFrame = 2;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 94)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 3;
            gCurrentPinballGame->ball->positionQ0.x = 0xb8;
            gCurrentPinballGame->ball->positionQ0.y = 0xbb;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 91)
        {
            gCurrentPinballGame->ball->ballHidden = 1;
            gCurrentPinballGame->catchHoleAnimFrame = 4;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 83)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 5;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 34)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 6;

        }
        else if (gCurrentPinballGame->modeAnimTimer > 26)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 7;

        }
        else if (gCurrentPinballGame->modeAnimTimer > 18)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 8;

        }
        else if (gCurrentPinballGame->modeAnimTimer > 10)
        {
            gCurrentPinballGame->catchHoleAnimFrame = 9;

        }
        else if (gCurrentPinballGame->modeAnimTimer > 4)
        {
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->catchHoleAnimFrame = 10;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else
        {
            gCurrentPinballGame->catchHoleAnimFrame = 11;
            gCurrentPinballGame->ball->positionQ0.x = 0xb0;
            gCurrentPinballGame->ball->positionQ0.y = 0xca;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
    else
    {
        gCurrentPinballGame->catchHoleAnimFrame = 0;
        gCurrentPinballGame->ballFrozenState = 0;
        gCurrentPinballGame->collisionCooldownTimer = 60;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->velocity.x = -0x66;
        gCurrentPinballGame->ball->velocity.y = 0xC8;
        PlayRumble(7);
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xAB;
        gCurrentPinballGame->ball->positionQ0.y = 0xD4;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->ballCatchState = NOT_TRAPPED;
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
        gCurrentPinballGame->cameraScrollTarget = 0;
        gCurrentPinballGame->cameraScrollEnabled = 1;
        gCurrentPinballGame->boardEntityActive = 0;
    }
}

void HandleSapphireFlipperButtonInput(void)
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
    }
}
