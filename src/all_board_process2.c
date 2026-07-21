#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

void AllBoardProcess_2A_4D6C4(void)
{
    s16 var0;
    s16 var1;

    var0 = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        var1 = 0;
    }
    else if (gMain.selectedField == FIELD_SAPPHIRE)
    {
        var1 = -24;
    }
    else
    {
        var1 = 0;
        var0 = 8;
    }

    if (gMain.selectedField < MAIN_FIELD_COUNT)
    {
        gCurrentPinballGame->cameraScrollOffset = var1 - 244;
        gCurrentPinballGame->cameraScrollTarget = 0;
        gCurrentPinballGame->cameraScrollEnabled = FALSE;
        gCurrentPinballGame->cameraBaseX = gBoardConfig.fieldLayout.cameraStartX;
        gCurrentPinballGame->cameraBaseY = gBoardConfig.fieldLayout.cameraStartY;
        gCurrentPinballGame->cameraYQ8 = gBoardConfig.fieldLayout.cameraStartY << 8;
        gCurrentPinballGame->cameraXOffset = gCurrentPinballGame->cameraBaseX;
        gCurrentPinballGame->cameraYOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;
        if (gMain.selectedField == FIELD_RUBY)
        {
            if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                m4aSongNumStart(MUS_FIELD_RUBY);
            else
                m4aSongNumStart(MUS_FIELD_RUBY2);
        }
        else
        {
            if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                m4aSongNumStart(MUS_FIELD_SAPPHIRE);
            else
                m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
        }
    }
    else
    {
        gCurrentPinballGame->cameraScrollOffset = 0;
        gCurrentPinballGame->cameraScrollTarget = 0;
        gCurrentPinballGame->cameraScrollEnabled = FALSE;
        if (gMain.selectedField <= FIELD_KECLEON)
            gCurrentPinballGame->cameraYAdjust = -24;
        else if (gMain.selectedField == FIELD_RAYQUAZA)
            gCurrentPinballGame->cameraYAdjust = -88;
        else
            gCurrentPinballGame->cameraYAdjust = -64;

        gCurrentPinballGame->cameraBaseX = gBoardConfig.fieldLayout.cameraStartX;
        gCurrentPinballGame->cameraBaseY = gBoardConfig.fieldLayout.cameraStartY + gCurrentPinballGame->cameraYAdjust;
        gCurrentPinballGame->cameraYQ8 = gBoardConfig.fieldLayout.cameraStartY << 8;
        gCurrentPinballGame->cameraXOffset = gCurrentPinballGame->cameraBaseX;
        gCurrentPinballGame->cameraYOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->cameraScrollOffset;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraBaseY;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraBaseY;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraBaseX + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraBaseY / 2;
        if (gMain.selectedField == FIELD_KECLEON)
            gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->globalAnimFrameCounter & 0x7FF) / 8;
    }

    gMain.bgOffsets[0].yOffset = 80;
    gCurrentPinballGame->scrollEffectY = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->scrollEffectX = gCurrentPinballGame->scrollEffectY;
    gCurrentPinballGame->cameraLookAhead = 0x1000;
}

void MainBoardProcess_2B_4D960(void)
{
    int var0;
    int var1;
    int var2;
    s16 var3;
    int var4;

    var0 = 0x1000;
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        ProcessMainBoardBallDrainAndLaunch();

    if (gCurrentPinballGame->cameraScrollEnabled)
    {
        if (gCurrentPinballGame->cameraScrollOffset != gCurrentPinballGame->cameraScrollTarget)
        {
            if (gCurrentPinballGame->cameraScrollOffset > gCurrentPinballGame->cameraScrollTarget)
                gCurrentPinballGame->cameraScrollOffset--;
            else
                gCurrentPinballGame->cameraScrollOffset++;
        }
        else
        {
            gCurrentPinballGame->cameraScrollEnabled = FALSE;
        }
    }

    if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
        var0 = (gCurrentPinballGame->cameraBall->velocity.y * 40) + 0x1000;

    gCurrentPinballGame->cameraLookAhead += (var0 - gCurrentPinballGame->cameraLookAhead) / 10;
    var1 = gCurrentPinballGame->cameraBall->positionQ8.y + gCurrentPinballGame->cameraLookAhead;
    if (var1 > gBoardConfig.fieldLayout.cameraScrollMaxY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMaxY << 8;
    else if (var1 < gBoardConfig.fieldLayout.cameraScrollMinY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMinY << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->cameraYQ8;
    var2 = (var1 - var4) / 12;
    if (var2 > 0)
    {
        if (var2 < 80)
            var2 = 0;
    }
    else
    {
        if (var2 > -80)
            var2 = 0;
    }

    var4 += var2;
    if (!gCurrentPinballGame->cameraLocked)
    {
        gCurrentPinballGame->cameraYQ8 = var4;
        gCurrentPinballGame->cameraBaseY = var4 / 0x100;
        if (gCurrentPinballGame->cameraBall->positionQ0.x >= 230)
            gCurrentPinballGame->cameraBaseX++;
        else
            gCurrentPinballGame->cameraBaseX--;

        if (gCurrentPinballGame->cameraBaseX > 16)
            gCurrentPinballGame->cameraBaseX = 16;
        else if (gCurrentPinballGame->cameraBaseX < 0)
            gCurrentPinballGame->cameraBaseX = 0;
    }

    ProcessTiltInput();
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraBaseX + gCurrentPinballGame->tiltXOffset + gCurrentPinballGame->screenShakeX;
    gCurrentPinballGame->scrollEffectY = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust;
    var3 = gMain.bgOffsets[3].yOffset - gCurrentPinballGame->scrollEffectY;
    if (var3 > 8)
        var3 = 8;
    else if (var3 < -8)
        var3 = -8;

    if (var3)
        gMain.bgOffsets[3].yOffset -= var3;

    gMain.bgOffsets[2].xOffset = gMain.bgOffsets[3].xOffset;
    gMain.bgOffsets[2].yOffset = gMain.bgOffsets[3].yOffset;
    gMain.bgOffsets[1].xOffset = gMain.bgOffsets[3].xOffset;
    gMain.bgOffsets[1].yOffset = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->cameraXOffset = gCurrentPinballGame->cameraBaseX + gCurrentPinballGame->tiltXOffset + gCurrentPinballGame->screenShakeX;
    gCurrentPinballGame->cameraYOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust;
    gCurrentPinballGame->hudSpriteBaseY = gCurrentPinballGame->cameraYViewport;
    gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust;
}

void BonusBoardProcess_2B_4DBFC(void)
{
    int var0;
    int var1;
    int var2;
    s16 var3;
    int var4;

    var0 = 0x1000;
    if ((gMain.modeChangeFlags & ~MODE_CHANGE_EXPIRED_BONUS) == 0)
        ProcessBonusBoardBallDrain();

    if (gCurrentPinballGame->cameraScrollEnabled)
    {
        if (gCurrentPinballGame->cameraScrollOffset != gCurrentPinballGame->cameraScrollTarget)
        {
            if (gCurrentPinballGame->cameraScrollOffset > gCurrentPinballGame->cameraScrollTarget)
                gCurrentPinballGame->cameraScrollOffset--;
            else
                gCurrentPinballGame->cameraScrollOffset++;
        }
        else
        {
            gCurrentPinballGame->cameraScrollEnabled = FALSE;
        }
    }

    if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
        var0 = gCurrentPinballGame->cameraBall->velocity.y * 40 + 0x1000;

    gCurrentPinballGame->cameraLookAhead += (var0 - gCurrentPinballGame->cameraLookAhead) / 10;
    var1 = gCurrentPinballGame->cameraBall->positionQ8.y + gCurrentPinballGame->cameraLookAhead;
    if (var1 > gBoardConfig.fieldLayout.cameraScrollMaxY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMaxY << 8;
    else if (var1 < gBoardConfig.fieldLayout.cameraScrollMinY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMinY << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->cameraYQ8;
    var2 = (var1 - var4) / 12;
    if (var2 > 0)
    {
        if (var2 < 80)
            var2 = 0;
    }
    else
    {
        if (var2 > -80)
            var2 = 0;
    }

    var4 += var2;
    if (!gCurrentPinballGame->cameraLocked)
    {
        gCurrentPinballGame->cameraYQ8 = var4;
        gCurrentPinballGame->cameraBaseY = var4 / 0x100;
    }

    ProcessTiltInput();
    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraBaseX + gCurrentPinballGame->tiltXOffset + 8 + gCurrentPinballGame->screenShakeX;
    gCurrentPinballGame->scrollEffectY = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust + gCurrentPinballGame->screenShakeY;
    var3 = gCurrentPinballGame->scrollEffectX - gCurrentPinballGame->scrollEffectY;
    if (var3 > 8)
        var3 = 8;
    else if (var3 < -8)
        var3 = -8;

    if (var3)
        gCurrentPinballGame->scrollEffectX -= var3;

    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->scrollEffectX;

    switch (gMain.selectedField)
    {
    case FIELD_DUSCLOPS:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->scrollEffectX / 2;
        break;
    case FIELD_KECLEON:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->globalAnimFrameCounter & 0x7FF) / 8;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = 0;
        break;
    case FIELD_KYOGRE:
    case FIELD_GROUDON:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case FIELD_RAYQUAZA:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset / 4;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case FIELD_SPHEAL:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    }

    gCurrentPinballGame->cameraXOffset = gCurrentPinballGame->cameraBaseX + gCurrentPinballGame->tiltXOffset + gCurrentPinballGame->screenShakeX;
    gCurrentPinballGame->cameraYOffset = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust + gCurrentPinballGame->screenShakeY;
    gCurrentPinballGame->cameraYViewport = gCurrentPinballGame->cameraBaseY + gCurrentPinballGame->tiltYOffset + gCurrentPinballGame->cameraScrollOffset + gCurrentPinballGame->cameraYAdjust;
}

void ProcessTiltInput(void)
{
    int i;
    s16 sp0[4];

    if (gCurrentPinballGame->ballCatchState == NOT_TRAPPED
        && gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE
        && !gCurrentPinballGame->kickbackFiring)
    {
        if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_TILT_LEFT]
            && gCurrentPinballGame->boardShakeTimer == 0)
        {
            gCurrentPinballGame->boardShakeDirection = 0;
            if (gCurrentPinballGame->boardShakeIntensity == 0)
            {
                gCurrentPinballGame->boardShakeIntensity = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }

        if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_TILT_RIGHT]
            && gCurrentPinballGame->boardShakeTimer == 0)
        {
            gCurrentPinballGame->boardShakeDirection = 1;
            if (gCurrentPinballGame->boardShakeIntensity == 0)
            {
                gCurrentPinballGame->boardShakeIntensity = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }

        if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_TILT_UP]
            && gCurrentPinballGame->boardShakeTimer == 0)
        {
            gCurrentPinballGame->boardShakeDirection = 2;
            if (gCurrentPinballGame->boardShakeIntensity == 0)
            {
                gCurrentPinballGame->boardShakeIntensity = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }
    }

    if (gCurrentPinballGame->boardShakeIntensity)
    {
        gCurrentPinballGame->boardShakeIntensity--;
        if (gCurrentPinballGame->boardShakeIntensity == 0)
        {
            switch (gCurrentPinballGame->boardShakeDirection)
            {
            case 0:
                gCurrentPinballGame->tiltShakeAmplitude[0] = 6;
                gCurrentPinballGame->tiltShakeVelocity[0] = -1;
                gCurrentPinballGame->tiltShakeAmplitude[2] = 6;
                gCurrentPinballGame->tiltShakeVelocity[2] = 1;
                break;
            case 1:
                gCurrentPinballGame->tiltShakeAmplitude[1] = 6;
                gCurrentPinballGame->tiltShakeVelocity[1] = 1;
                gCurrentPinballGame->tiltShakeAmplitude[3] = 6;
                gCurrentPinballGame->tiltShakeVelocity[3] = 1;
                break;
            case 2:
                gCurrentPinballGame->tiltShakeAmplitude[2] = 6;
                gCurrentPinballGame->tiltShakeVelocity[2] = 1;
                gCurrentPinballGame->tiltShakeAmplitude[3] = 0;
                gCurrentPinballGame->tiltShakeVelocity[3] = 1;
                break;
            }

            gCurrentPinballGame->boardShakeTimer = 24;
        }
    }

    if (gCurrentPinballGame->boardShakeTimer)
        gCurrentPinballGame->boardShakeTimer--;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->tiltShakeAmplitude[i] > 0)
            gCurrentPinballGame->tiltShakeAmplitude[i]--;

        if (gCurrentPinballGame->tiltShakeAmplitude[i] < 3)
            sp0[i] = gCurrentPinballGame->tiltShakeVelocity[i] * gCurrentPinballGame->tiltShakeAmplitude[i];
        else
            sp0[i] = gCurrentPinballGame->tiltShakeVelocity[i] * (6 - gCurrentPinballGame->tiltShakeAmplitude[i]);
    }

    gCurrentPinballGame->tiltXOffset = sp0[0] + sp0[1];
    gCurrentPinballGame->tiltYOffset = sp0[2] + sp0[3];

    if (gCurrentPinballGame->tiltXOffset == 0 && gCurrentPinballGame->tiltYOffset == 0)
    {
        gCurrentPinballGame->tiltLockoutTimer = 0;
        gCurrentPinballGame->lastTiltDirection = 0;
    }

    if (gCurrentPinballGame->tiltXOffset > 0)
    {
        if (gCurrentPinballGame->tiltXOffset < gCurrentPinballGame->tiltTargetXOffset)
            gCurrentPinballGame->tiltTargetXOffset--;
    }
    else if (gCurrentPinballGame->tiltXOffset < 0)
    {
        if (gCurrentPinballGame->tiltXOffset > gCurrentPinballGame->tiltTargetXOffset)
            gCurrentPinballGame->tiltTargetXOffset++;
    }

    if (gCurrentPinballGame->tiltYOffset > 0)
    {
        if (gCurrentPinballGame->tiltYOffset < gCurrentPinballGame->tiltTargetYOffset)
            gCurrentPinballGame->tiltTargetYOffset--;
    }
    else if (gCurrentPinballGame->tiltYOffset < 0)
    {
        if (gCurrentPinballGame->tiltYOffset > gCurrentPinballGame->tiltTargetYOffset)
            gCurrentPinballGame->tiltTargetYOffset++;
    }

    if (gCurrentPinballGame->tiltLockoutTimer == 0)
    {
        gCurrentPinballGame->tiltTargetXOffset = gCurrentPinballGame->tiltXOffset;
        gCurrentPinballGame->tiltTargetYOffset = gCurrentPinballGame->tiltYOffset;
    }
}

void ProcessMainBoardBallDrainAndLaunch(void)
{
    struct BallState *ballStates;

    if (gCurrentPinballGame->boardState != MAIN_BOARD_STATE_BOARD_INTRO
        && gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]
        && gCurrentPinballGame->ballInLaunchChute)
    {
        gCurrentPinballGame->launcherCharging = TRUE;
        gCurrentPinballGame->spoinkEntityState = 1;
    }

    if (gCurrentPinballGame->launcherCharging
        && gCurrentPinballGame->releasedButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
    {
        gCurrentPinballGame->spoinkEntityState = 3;
        if (gCurrentPinballGame->ballInLaunchChute)
        {
            PlayRumble(7);
            gCurrentPinballGame->ball->velocity.y = -590;
            gCurrentPinballGame->ball->velocity.x = 0;
            m4aSongNumStart(SE_SPOINK_LAUNCHER_FIRED);
        }

        gCurrentPinballGame->launcherCharging = FALSE;
    }

    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
    ballStates = &gCurrentPinballGame->ballStates[0];

    if (ballStates->positionQ0.y >= gBoardConfig.fieldLayout.ballDrainY)
    {
        ballStates->positionQ0.y = gBoardConfig.fieldLayout.ballDrainY;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.modeChangeDelayTimer == 0)
        {
            if (gCurrentPinballGame->saverTimeRemaining)
            {
                gMain.modeChangeDelayTimer = 4;
                gMain.pendingModeChangeType = MODE_CHANGE_BALL_SAVER;
                gMain.animationTimer = 204;
            }
            else
            {
                gMain.modeChangeDelayTimer = 80;
                gMain.pendingModeChangeType = MODE_CHANGE_END_OF_BALL;
                gMain.animationTimer = 200;
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                ResetBoardStateOnDeath();
                if (gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES
                    && !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
                {
                    gCurrentPinballGame->pichuWalkMode = 2;
                    gCurrentPinballGame->pichuEntranceTimer = 800;
                    gCurrentPinballGame->outLanePikaPosition = PIKA_LEFT_SIDE;
                }
            }
        }
    }

    gCurrentPinballGame->ballInLaunchChute = FALSE;
}

void ProcessBonusBoardBallDrain(void)
{
    struct BallState *ballStates;

    gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
    ballStates = &gCurrentPinballGame->ballStates[0];

    if (ballStates->positionQ0.y >= gBoardConfig.fieldLayout.ballDrainY)
    {
        ballStates->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS)
        {
            gCurrentPinballGame->returnToMainBoardFlag = TRUE;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ball->positionQ0.y = gBoardConfig.fieldLayout.ballDrainY - 10;
        }
        else
        {
            gCurrentPinballGame->ball->ballHidden = TRUE;
            gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_RESPAWN;
            gCurrentPinballGame->ballRespawnTimer = 0;
            gCurrentPinballGame->ball->positionQ0.x = gBoardConfig.fieldLayout.ballSpawnX;
            gCurrentPinballGame->ball->positionQ0.y = gBoardConfig.fieldLayout.ballSpawnY;
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                gCurrentPinballGame->ballUpgradeType--;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
}

void ResetBoardStateOnDeath(void)
{
    gCurrentPinballGame->stageTimer = 10199;

    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
        gCurrentPinballGame->boardSubState = BONUS_HOLE_SUBSTATE_START_CLOSING;
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_TRAVEL_MODE)
        gCurrentPinballGame->boardSubState = TRAVEL_SUBSTATE_BOARD_STATE_CLEANUP;
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
        gCurrentPinballGame->boardSubState = CATCH_EM_SUBSTATE_END_CATCH_HIT_PHASE;
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EGG_HATCH_MODE)
        gCurrentPinballGame->boardSubState = EGG_HATCH_SUBSTATE_CLEANUP_MON_SPRITES;
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_EVO_MODE)
        gCurrentPinballGame->boardSubState = EVOLUTION_SUBSTATE_END_EVO_PHASE;

    gCurrentPinballGame->allHolesLit = FALSE;
    gCurrentPinballGame->holeIndicators[0] = FALSE;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->pikaSpinMomentum = 0;
    gCurrentPinballGame->kickbackAnimFrameTimer = 0;
    gCurrentPinballGame->kickbackFrameId = 0;
    if (gCurrentPinballGame->outLanePikaPosition != PIKA_BOTH_SIDES
        || !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->pikaChargeTarget = 0;
        gCurrentPinballGame->pikaChargeProgress = 0;
        gCurrentPinballGame->prevChargeFillValue = 0;
        gCurrentPinballGame->chargeFillValue = 0;
        gCurrentPinballGame->chargeIndicatorXOffset = 0;
        gCurrentPinballGame->chargeIndicatorYOffset = -4;
        gCurrentPinballGame->chargeIndicatorScaleX = 0x100;
        gCurrentPinballGame->chargeIndicatorScaleY = 0x100;
        gCurrentPinballGame->chargeFillAnimTimer = 0;
        gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
    }

    gCurrentPinballGame->ballPowerUpLight[0] = FALSE;
    gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->bumperHitsSinceReset = 0;
    if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
        gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
        DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    }
    else
    {
        gCurrentPinballGame->ballUpgradeType = 0;
        gCurrentPinballGame->ballUpgradeCounter = 0;
    }

    gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
    DmaCopy16(3, &gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    gCurrentPinballGame->bonusMultiplier = gCurrentPinballGame->progressLevel;
    gCurrentPinballGame->progressLevel = 1;
    if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
    {
        gCurrentPinballGame->shouldProcessWhiscash = FALSE;
        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
        gCurrentPinballGame->whiscashStateTimer = 0;
        gCurrentPinballGame->rubyPondContentsChanging = TRUE;
        gCurrentPinballGame->rubyPondChangeTimer = 0x40;
        gCurrentPinballGame->screenShakeX = 0;

    }

    gCurrentPinballGame->makuhitaPunchState = 0;
}
