#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
//#include "constants/pinball_game.h"

extern void RotateSapphireHoleIndicators(void);

void SapphireBoardProcess_3A_326F4(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    gCurrentPinballGame->pikaSpinnerFrame = 0;
    gCurrentPinballGame->pikaSpinnerFramePrev = 1;

    UpdatePikachuChargeProgress();
    UpdatePikachuChargeAnimation();
    UpdatePikaSpinnerGraphics();
    UpdateSapphireBumperOscillation();
    HandleSapphireBumperHitAndDraw();

    gCurrentPinballGame->pikaChargeSpriteScaleX = 0x100;
    gCurrentPinballGame->pikaChargeSpriteScaleY = 0x100;

    InitSapphirePondState();
    UpdateAndDrawSapphirePondAnimation();
    UpdateSapphireTrapDoorAnimation();
    DrawSapphireTrapDoorSprite();
    RunSapphirePondPelliperStateMachine();
    UpdateEdgeIndicatorSprite();
}

void SapphireBoardProcess_3B_3276C(void)
{
    ProcessBoardStateTransition();
    UpdateSapphireBoardVisuals();

    if (!gMain.modeChangeFlags)
        UpdateSapphireBoardState();

    RotateSapphireHoleIndicators();

    if (gCurrentPinballGame->bgmVolumeRestoreTimer)
    {
        gCurrentPinballGame->bgmVolumeRestoreTimer--;
        if (!gCurrentPinballGame->bgmVolumeRestoreTimer)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void UpdateSapphireBoardVisuals(void)
{
    s32 temp;

    RenderBoardDynamicEntities();
    UpdateBannerScrolling();
    UpdateSapphirePokeballSprite();

    if (gCurrentPinballGame->viewportBottomY < 0x5a)
    {
        UpdateAndDrawSapphirePondAnimation();
        UpdateCyndaquilEruptionStateMachine();
    }

    if (gCurrentPinballGame->boardState < 3)
    {
        if (gCurrentPinballGame->cyndaquilAnimFrame == 3 && gCurrentPinballGame->cyndaquilAnimPhase == 0)
        {
            gCurrentPinballGame->catchModeBlinkActive = 1;
        }
        else
        {
            gCurrentPinballGame->catchModeBlinkActive = 0;
        }
    }
    else
    {
        gCurrentPinballGame->catchModeBlinkActive = 0;
    }

    if (gCurrentPinballGame->viewportBottomY < 0x96)
    {
        RunSapphirePondPelliperStateMachine();
        DrawSapphireTrapDoorSprite();
    }
    if (gCurrentPinballGame->viewportBottomY < 0xC4)
    {
        HandleSapphireBumperHitAndDraw();
        DrawSapphirePondWailmerSprite();
    }
    if (gCurrentPinballGame->viewportBottomY < 0xCA)
    {
        DrawSapphireShockWallSprites();
    }
    if (gCurrentPinballGame->viewportBottomY < 0xDC)
    {
        UpdatePikaSpinnerGraphics();
    }

    UpdateSapphireSeedotCollectionLogic();

    if (0x76 < gCurrentPinballGame->viewportBottomY)
    {
        DrawSapphireZigzagoonSprites();
        DrawSapphireSeedotSprites();
    }

    UpdateSapphireChimechoAnimState();

    if (0xA8 < gCurrentPinballGame->viewportBottomY)
        DrawSapphireChimechoSprite();

    RunPikachuThunderboltSequence();
    UpdatePikachuChargeAnimation();
    DrawBoardPortraitSprites();
    UpdateEdgeIndicatorSprite();

    if (gCurrentPinballGame->coinsTotalToCollect)
        UpdateCoinCollectionAnimation();

    BonusStage_HandleModeChangeFlags();
}

void UpdateSapphireBoardState(void)
{
    UpdateSapphireBumperOscillation();
    UpdateSapphireBoardEntryMode();
    UpdatePikachuChargeProgress();

    if (gCurrentPinballGame->triggerButtonCooldown)
        gCurrentPinballGame->triggerButtonCooldown--;

    UpdateSapphireZigzagoonKickState();
    UpdateSapphirePondEntityCooldown();
    UpdateSapphireTrapDoorAnimation();

    if (!(gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME))
        UpdateSapphireShockWallState();
}

void InitSapphireBoardEntryMode(void)
{
    if (gMain.modeChangeFlags != MODE_CHANGE_NONE)
        return;

    switch (gCurrentPinballGame->boardEntryMode)
    {
    case 1:
        InitSapphireWhiscashCatchEntry();
        break;
    case 3:
        InitSapphireTrapHoleEntry();
        break;
    case 4:
        InitCenterHoleEntry();
        break;
    }

    gCurrentPinballGame->entryAnimTimer = 60;
}

void UpdateSapphireBoardEntryMode(void)
{
    if (gCurrentPinballGame->entryAnimTimer)
        gCurrentPinballGame->entryAnimTimer--;

    switch (gCurrentPinballGame->boardEntryMode)
    {
    case 1:
        UpdateSapphireWhiscashCatchSequence();
        break;
    case 3:
        UpdateSapphireTrapHoleSequence();
        break;
    case 4:
        UpdateCenterHoleAnimation(); //Center Hole
        break;
    }
}

void InitSapphireTrapHoleEntry(void)
{
    gCurrentPinballGame->sequenceTimer = 0xB4;
    gCurrentPinballGame->entrySequenceTimer = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->ballLocked = 1;
}

void UpdateSapphireTrapHoleSequence(void)
{
    s16 i;

    if (gCurrentPinballGame->sequenceTimer > 0x18)
    {
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->sequenceTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 58;
        gCurrentPinballGame->ball->positionQ0.y = 178;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

        if (gCurrentPinballGame->sequenceTimer <= 0x31)
        {
            gCurrentPinballGame->sequenceTimer++;
        }

        UpdateMartEvoSelectionUI(gCurrentPinballGame->trapDisplayState);

        if (gCurrentPinballGame->trapDisplayState)
        {
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->targetHitCountdown[i] = 10;
                gCurrentPinballGame->targetAnimSubframe[i] = 0;
                gCurrentPinballGame->targetAnimPhase[i] = 4;
            }
        }
    }
    else if (gCurrentPinballGame->sequenceTimer > 0)
    {
        gCurrentPinballGame->sequenceTimer--;
    }
    else
    {
        gCurrentPinballGame->ball->isGrabbed = 0;
        gCurrentPinballGame->ballLockState = 0;
        gCurrentPinballGame->entryAnimTimer = 0x3C;
        gCurrentPinballGame->ball->velocity.x = 0x60;
        gCurrentPinballGame->ball->velocity.y = 0xC0;
        gCurrentPinballGame->ball->positionQ0.x = 0x3C;
        gCurrentPinballGame->ball->positionQ0.y = 0xB4;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ballLocked = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->boardEntryMode = 0;

        m4aSongNumStart(SE_UNKNOWN_0xC3);

        if (gCurrentPinballGame->savedEvoHitCount > 2 && gCurrentPinballGame->evolvablePartySize > 0) {
            RequestBoardTransition(6);
        }
    }
}

void InitSapphireWhiscashCatchEntry(void)
{
    if (gCurrentPinballGame->savedCatchArrows > 1)
        RequestBoardTransition(4);

    gCurrentPinballGame->sequenceTimer = 100;
    gCurrentPinballGame->pokemonActionFrame = 2;
    gCurrentPinballGame->scrollNudgeY = 0;
    gCurrentPinballGame->scrollNudgeTargetY = 30;
    gCurrentPinballGame->scrollNudgeActive = 0;
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    m4aSongNumStart(SE_WHISCASH_CATCH_BALL);
    PlayRumble(8);
}

void UpdateSapphireWhiscashCatchSequence(void)
{
    if (gCurrentPinballGame->sequenceTimer)
    {
        gCurrentPinballGame->ballLocked = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->sequenceTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
        if (gCurrentPinballGame->sequenceTimer > 97)
        {
            gCurrentPinballGame->bossActive = 1;
            gCurrentPinballGame->pokemonActionFrame = 2;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else if (gCurrentPinballGame->sequenceTimer > 94)
        {
            gCurrentPinballGame->pokemonActionFrame = 3;
            gCurrentPinballGame->ball->positionQ0.x = 0xb8;
            gCurrentPinballGame->ball->positionQ0.y = 0xbb;
        }
        else if (gCurrentPinballGame->sequenceTimer > 91)
        {
            gCurrentPinballGame->ball->isGrabbed = 1;
            gCurrentPinballGame->pokemonActionFrame = 4;
        }
        else if (gCurrentPinballGame->sequenceTimer > 83)
        {
            gCurrentPinballGame->pokemonActionFrame = 5;
        }
        else if (gCurrentPinballGame->sequenceTimer > 34)
        {
            gCurrentPinballGame->pokemonActionFrame = 6;

        }
        else if (gCurrentPinballGame->sequenceTimer > 26)
        {
            gCurrentPinballGame->pokemonActionFrame = 7;

        }
        else if (gCurrentPinballGame->sequenceTimer > 18)
        {
            gCurrentPinballGame->pokemonActionFrame = 8;

        }
        else if (gCurrentPinballGame->sequenceTimer > 10)
        {
            gCurrentPinballGame->pokemonActionFrame = 9;

        }
        else if (gCurrentPinballGame->sequenceTimer > 4)
        {
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->pokemonActionFrame = 10;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else
        {
            gCurrentPinballGame->pokemonActionFrame = 11;
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
        gCurrentPinballGame->pokemonActionFrame = 0;
        gCurrentPinballGame->ballLockState = 0;
        gCurrentPinballGame->entryAnimTimer = 60;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->velocity.x = -0x66;
        gCurrentPinballGame->ball->velocity.y = 0xC8;
        PlayRumble(7);
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xAB;
        gCurrentPinballGame->ball->positionQ0.y = 0xD4;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->boardEntryMode = 0;
        gCurrentPinballGame->ballLocked = 0;
        m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
        gCurrentPinballGame->scrollNudgeTargetY = 0;
        gCurrentPinballGame->scrollNudgeActive = 1;
        gCurrentPinballGame->bossActive = 0;
    }
}

void RotateSapphireHoleIndicators(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->outLaneSaverTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pikaSaverAnimTimer == 0 && gCurrentPinballGame->inputLockActive == 0)
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
        if (gCurrentPinballGame->outLaneSaverTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pikaSaverAnimTimer == 0 && gCurrentPinballGame->inputLockActive == 0)
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
