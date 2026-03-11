#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

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
        gCurrentPinballGame->scrollNudgeY = var1 - 244;
        gCurrentPinballGame->scrollNudgeTargetY = 0;
        gCurrentPinballGame->scrollNudgeActive = 0;
        gCurrentPinballGame->cameraScrollX = gBoardConfig.fieldLayout.initialScrollX;
        gCurrentPinballGame->cameraScrollY = gBoardConfig.fieldLayout.initialScrollY;
        gCurrentPinballGame->cameraScrollYQ8 = gBoardConfig.fieldLayout.initialScrollY << 8;
        gCurrentPinballGame->bgScrollXCopy = gCurrentPinballGame->cameraScrollX;
        gCurrentPinballGame->bgScrollYWithOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;
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
        gCurrentPinballGame->scrollNudgeY = 0;
        gCurrentPinballGame->scrollNudgeTargetY = 0;
        gCurrentPinballGame->scrollNudgeActive = 0;
        if (gMain.selectedField <= FIELD_KECLEON)
            gCurrentPinballGame->fieldScrollOffsetY = -24;
        else if (gMain.selectedField == FIELD_RAYQUAZA)
            gCurrentPinballGame->fieldScrollOffsetY = -88;
        else
            gCurrentPinballGame->fieldScrollOffsetY = -64;

        gCurrentPinballGame->cameraScrollX = gBoardConfig.fieldLayout.initialScrollX;
        gCurrentPinballGame->cameraScrollY = gBoardConfig.fieldLayout.initialScrollY + gCurrentPinballGame->fieldScrollOffsetY;
        gCurrentPinballGame->cameraScrollYQ8 = gBoardConfig.fieldLayout.initialScrollY << 8;
        gCurrentPinballGame->bgScrollXCopy = gCurrentPinballGame->cameraScrollX;
        gCurrentPinballGame->bgScrollYWithOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->scrollNudgeY;
        gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[2].yOffset = gCurrentPinballGame->cameraScrollY;
        gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[3].yOffset = gCurrentPinballGame->cameraScrollY;
        gMain.bgOffsets[1].xOffset = gCurrentPinballGame->cameraScrollX + var0;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->cameraScrollY / 2;
        if (gMain.selectedField == FIELD_KECLEON)
            gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->gameFrameCount & 0x7FF) / 8;
    }

    gMain.bgOffsets[0].yOffset = 80;
    gCurrentPinballGame->bgTargetScrollY = gMain.bgOffsets[3].yOffset;
    gCurrentPinballGame->bgSmoothScrollY = gCurrentPinballGame->bgTargetScrollY;
    gCurrentPinballGame->cameraFollowOffsetQ8 = 0x1000;
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
        CheckMainBoardBallOutOfBounds();

    if (gCurrentPinballGame->scrollNudgeActive)
    {
        if (gCurrentPinballGame->scrollNudgeY != gCurrentPinballGame->scrollNudgeTargetY)
        {
            if (gCurrentPinballGame->scrollNudgeY > gCurrentPinballGame->scrollNudgeTargetY)
                gCurrentPinballGame->scrollNudgeY--;
            else
                gCurrentPinballGame->scrollNudgeY++;
        }
        else
        {
            gCurrentPinballGame->scrollNudgeActive = 0;
        }
    }

    if (gCurrentPinballGame->ballLockState == 0)
        var0 = (gCurrentPinballGame->ballInstancesBase->velocity.y * 40) + 0x1000;

    gCurrentPinballGame->cameraFollowOffsetQ8 += (var0 - gCurrentPinballGame->cameraFollowOffsetQ8) / 10;
    var1 = gCurrentPinballGame->ballInstancesBase->positionQ8.y + gCurrentPinballGame->cameraFollowOffsetQ8;
    if (var1 > gBoardConfig.fieldLayout.cameraScrollMaxY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMaxY << 8;
    else if (var1 < gBoardConfig.fieldLayout.cameraScrollMinY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMinY << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->cameraScrollYQ8;
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
    if (gCurrentPinballGame->bossActive == 0)
    {
        gCurrentPinballGame->cameraScrollYQ8 = var4;
        gCurrentPinballGame->cameraScrollY = var4 / 0x100;
        if (gCurrentPinballGame->ballInstancesBase->positionQ0.x >= 230)
            gCurrentPinballGame->cameraScrollX++;
        else
            gCurrentPinballGame->cameraScrollX--;

        if (gCurrentPinballGame->cameraScrollX > 16)
            gCurrentPinballGame->cameraScrollX = 16;
        else if (gCurrentPinballGame->cameraScrollX < 0)
            gCurrentPinballGame->cameraScrollX = 0;
    }

    ProcessBoardTiltShake();
    gMain.bgOffsets[3].xOffset = gCurrentPinballGame->cameraScrollX + gCurrentPinballGame->shakeOffsetX + gCurrentPinballGame->bossShakeOffsetX;
    gCurrentPinballGame->bgTargetScrollY = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY;
    var3 = gMain.bgOffsets[3].yOffset - gCurrentPinballGame->bgTargetScrollY;
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
    gCurrentPinballGame->bgScrollXCopy = gCurrentPinballGame->cameraScrollX + gCurrentPinballGame->shakeOffsetX + gCurrentPinballGame->bossShakeOffsetX;
    gCurrentPinballGame->bgScrollYWithOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY;
    gCurrentPinballGame->viewportBottomYPrev = gCurrentPinballGame->viewportBottomY;
    gCurrentPinballGame->viewportBottomY = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY;
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
        CheckBonusBoardBallOutOfBounds();

    if (gCurrentPinballGame->scrollNudgeActive)
    {
        if (gCurrentPinballGame->scrollNudgeY != gCurrentPinballGame->scrollNudgeTargetY)
        {
            if (gCurrentPinballGame->scrollNudgeY > gCurrentPinballGame->scrollNudgeTargetY)
                gCurrentPinballGame->scrollNudgeY--;
            else
                gCurrentPinballGame->scrollNudgeY++;
        }
        else
        {
            gCurrentPinballGame->scrollNudgeActive = 0;
        }
    }

    if (gCurrentPinballGame->ballLockState == 0)
        var0 = gCurrentPinballGame->ballInstancesBase->velocity.y * 40 + 0x1000;

    gCurrentPinballGame->cameraFollowOffsetQ8 += (var0 - gCurrentPinballGame->cameraFollowOffsetQ8) / 10;
    var1 = gCurrentPinballGame->ballInstancesBase->positionQ8.y + gCurrentPinballGame->cameraFollowOffsetQ8;
    if (var1 > gBoardConfig.fieldLayout.cameraScrollMaxY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMaxY << 8;
    else if (var1 < gBoardConfig.fieldLayout.cameraScrollMinY << 8)
        var1 = gBoardConfig.fieldLayout.cameraScrollMinY << 8;

    var1 -= 0x5000;
    var4 = gCurrentPinballGame->cameraScrollYQ8;
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
    if (gCurrentPinballGame->bossActive == 0)
    {
        gCurrentPinballGame->cameraScrollYQ8 = var4;
        gCurrentPinballGame->cameraScrollY = var4 / 0x100;
    }

    ProcessBoardTiltShake();
    gMain.bgOffsets[2].xOffset = gCurrentPinballGame->cameraScrollX + gCurrentPinballGame->shakeOffsetX + 8 + gCurrentPinballGame->bossShakeOffsetX;
    gCurrentPinballGame->bgTargetScrollY = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY + gCurrentPinballGame->bossShakeOffsetY;
    var3 = gCurrentPinballGame->bgSmoothScrollY - gCurrentPinballGame->bgTargetScrollY;
    if (var3 > 8)
        var3 = 8;
    else if (var3 < -8)
        var3 = -8;

    if (var3)
        gCurrentPinballGame->bgSmoothScrollY -= var3;

    gMain.bgOffsets[2].yOffset = gCurrentPinballGame->bgSmoothScrollY;

    switch (gMain.selectedField)
    {
    case 2:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gCurrentPinballGame->bgSmoothScrollY / 2;
        break;
    case 3:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset + (gCurrentPinballGame->gameFrameCount & 0x7FF) / 8;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = 0;
        break;
    case 4:
    case 5:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case 6:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset / 4;
        gMain.bgOffsets[1].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[1].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    case 7:
        gMain.bgOffsets[3].xOffset = gMain.bgOffsets[2].xOffset;
        gMain.bgOffsets[3].yOffset = gMain.bgOffsets[2].yOffset;
        break;
    }

    gCurrentPinballGame->bgScrollXCopy = gCurrentPinballGame->cameraScrollX + gCurrentPinballGame->shakeOffsetX + gCurrentPinballGame->bossShakeOffsetX;
    gCurrentPinballGame->bgScrollYWithOffset = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY + gCurrentPinballGame->bossShakeOffsetY;
    gCurrentPinballGame->viewportBottomY = gCurrentPinballGame->cameraScrollY + gCurrentPinballGame->shakeOffsetY + gCurrentPinballGame->scrollNudgeY + gCurrentPinballGame->fieldScrollOffsetY;
}

void ProcessBoardTiltShake(void)
{
    int i;
    s16 sp0[4];

    if (gCurrentPinballGame->boardEntryMode == 0 && gCurrentPinballGame->catchModeHitPhase != 2 && gCurrentPinballGame->inputLockActive == 0)
    {
        if (gCurrentPinballGame->newButtonActions[2])
        {
            if (gCurrentPinballGame->shakeCooldown == 0)
            {
                gCurrentPinballGame->bumperShakeAxis = 0;
                if (gCurrentPinballGame->bumperShakeTimer == 0)
                {
                    gCurrentPinballGame->bumperShakeTimer = 4;
                    m4aSongNumStart(SE_TILT_TRIGGERED);
                    PlayRumble(8);
                }
            }
        }

        if (gCurrentPinballGame->newButtonActions[3] && gCurrentPinballGame->shakeCooldown == 0)
        {
            gCurrentPinballGame->bumperShakeAxis = 1;
            if (gCurrentPinballGame->bumperShakeTimer == 0)
            {
                gCurrentPinballGame->bumperShakeTimer = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }

        if (gCurrentPinballGame->newButtonActions[4] && gCurrentPinballGame->shakeCooldown == 0)
        {
            gCurrentPinballGame->bumperShakeAxis = 2;
            if (gCurrentPinballGame->bumperShakeTimer == 0)
            {
                gCurrentPinballGame->bumperShakeTimer = 4;
                m4aSongNumStart(SE_TILT_TRIGGERED);
                PlayRumble(8);
            }
        }
    }

    if (gCurrentPinballGame->bumperShakeTimer)
    {
        gCurrentPinballGame->bumperShakeTimer--;
        if (gCurrentPinballGame->bumperShakeTimer == 0)
        {
            switch (gCurrentPinballGame->bumperShakeAxis)
            {
            case 0:
                gCurrentPinballGame->boardShakeTimers[0] = 6;
                gCurrentPinballGame->boardShakeDirections[0] = -1;
                gCurrentPinballGame->boardShakeTimers[2] = 6;
                gCurrentPinballGame->boardShakeDirections[2] = 1;
                break;
            case 1:
                gCurrentPinballGame->boardShakeTimers[1] = 6;
                gCurrentPinballGame->boardShakeDirections[1] = 1;
                gCurrentPinballGame->boardShakeTimers[3] = 6;
                gCurrentPinballGame->boardShakeDirections[3] = 1;
                break;
            case 2:
                gCurrentPinballGame->boardShakeTimers[2] = 6;
                gCurrentPinballGame->boardShakeDirections[2] = 1;
                gCurrentPinballGame->boardShakeTimers[3] = 0;
                gCurrentPinballGame->boardShakeDirections[3] = 1;
                break;
            }

            gCurrentPinballGame->shakeCooldown = 24;
        }
    }

    if (gCurrentPinballGame->shakeCooldown)
        gCurrentPinballGame->shakeCooldown--;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->boardShakeTimers[i] > 0)
            gCurrentPinballGame->boardShakeTimers[i]--;

        if (gCurrentPinballGame->boardShakeTimers[i] < 3)
            sp0[i] = gCurrentPinballGame->boardShakeDirections[i] * gCurrentPinballGame->boardShakeTimers[i];
        else
            sp0[i] = gCurrentPinballGame->boardShakeDirections[i] * (6 - gCurrentPinballGame->boardShakeTimers[i]);
    }

    gCurrentPinballGame->shakeOffsetX = sp0[0] + sp0[1];
    gCurrentPinballGame->shakeOffsetY = sp0[2] + sp0[3];

    if (gCurrentPinballGame->shakeOffsetX == 0 && gCurrentPinballGame->shakeOffsetY == 0)
    {
        gCurrentPinballGame->shakeApplied = 0;
        gCurrentPinballGame->shakeVelocityDirection = 0;
    }

    if (gCurrentPinballGame->shakeOffsetX > 0)
    {
        if (gCurrentPinballGame->shakeOffsetX < gCurrentPinballGame->shakePeakX)
            gCurrentPinballGame->shakePeakX--;
    }
    else if (gCurrentPinballGame->shakeOffsetX < 0)
    {
        if (gCurrentPinballGame->shakeOffsetX > gCurrentPinballGame->shakePeakX)
            gCurrentPinballGame->shakePeakX++;
    }

    if (gCurrentPinballGame->shakeOffsetY > 0)
    {
        if (gCurrentPinballGame->shakeOffsetY < gCurrentPinballGame->shakePeakY)
            gCurrentPinballGame->shakePeakY--;
    }
    else if (gCurrentPinballGame->shakeOffsetY < 0)
    {
        if (gCurrentPinballGame->shakeOffsetY > gCurrentPinballGame->shakePeakY)
            gCurrentPinballGame->shakePeakY++;
    }

    if (gCurrentPinballGame->shakeApplied == 0)
    {
        gCurrentPinballGame->shakePeakX = gCurrentPinballGame->shakeOffsetX;
        gCurrentPinballGame->shakePeakY = gCurrentPinballGame->shakeOffsetY;
    }
}

void CheckMainBoardBallOutOfBounds(void)
{
    struct BallState *ballInstances;

    if (gCurrentPinballGame->boardState && gCurrentPinballGame->newButtonActions[1] && gCurrentPinballGame->tiltDetected)
    {
        gCurrentPinballGame->tiltButtonHeld = 1;
        gCurrentPinballGame->peliAnimState = 1;
    }

    if (gCurrentPinballGame->tiltButtonHeld && gCurrentPinballGame->releasedButtonActions[1])
    {
        gCurrentPinballGame->peliAnimState = 3;
        if (gCurrentPinballGame->tiltDetected)
        {
            PlayRumble(7);
            gCurrentPinballGame->ball->velocity.y = -590;
            gCurrentPinballGame->ball->velocity.x = 0;
            m4aSongNumStart(SE_UNKNOWN_0xCD);
        }

        gCurrentPinballGame->tiltButtonHeld = 0;
    }

    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
    ballInstances = &gCurrentPinballGame->ballInstances[0];

    if (ballInstances->positionQ0.y >= gBoardConfig.fieldLayout.ballLossY)
    {
        ballInstances->positionQ0.y = gBoardConfig.fieldLayout.ballLossY;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.modeTransitionDelay == 0)
        {
            if (gCurrentPinballGame->modeTimerFrames)
            {
                gMain.modeTransitionDelay = 4;
                gMain.pendingModeChangeFlags = 8;
                gMain.stateTimer = 204;
            }
            else
            {
                gMain.modeTransitionDelay = 80;
                gMain.pendingModeChangeFlags = 16;
                gMain.stateTimer = 200;
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                ResetBoardStateAfterBallLoss();
                if (gCurrentPinballGame->outLanePikaPosition == 2 && gMain.eReaderBonuses[EREADER_DX_MODE_CARD] == 0)
                {
                    gCurrentPinballGame->pikaSaverLossType = 2;
                    gCurrentPinballGame->pikaSaverAnimTimer = 800;
                    gCurrentPinballGame->outLanePikaPosition = 0;
                }
            }
        }
    }

    gCurrentPinballGame->tiltDetected = 0;
}

void CheckBonusBoardBallOutOfBounds(void)
{
    struct BallState *ballInstances;

    gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
    ballInstances = &gCurrentPinballGame->ballInstances[0];

    if (ballInstances->positionQ0.y >= gBoardConfig.fieldLayout.ballLossY)
    {
        ballInstances->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS)
        {
            gCurrentPinballGame->returnToMainBoardFlag = 1;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ball->positionQ0.y = gBoardConfig.fieldLayout.ballLossY - 10;
        }
        else
        {
            gCurrentPinballGame->ball->isGrabbed = 1;
            gCurrentPinballGame->bonusCaptureState = 1;
            gCurrentPinballGame->bonusSequenceTimer = 0;
            gCurrentPinballGame->ball->positionQ0.x = gBoardConfig.fieldLayout.ballStartX;
            gCurrentPinballGame->ball->positionQ0.y = gBoardConfig.fieldLayout.ballStartY;
            if (gCurrentPinballGame->ballUpgradeType > BALL_UPGRADE_TYPE_POKE_BALL)
                gCurrentPinballGame->ballUpgradeType--;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
}

void ResetBoardStateAfterBallLoss(void)
{
    gCurrentPinballGame->stageTimer = 10199;

    if (gCurrentPinballGame->boardState == 2)
        gCurrentPinballGame->boardSubState = 5;
    if (gCurrentPinballGame->boardState == 7)
        gCurrentPinballGame->boardSubState = 6;
    if (gCurrentPinballGame->boardState == 4)
        gCurrentPinballGame->boardSubState = 10;
    if (gCurrentPinballGame->boardState == 5)
        gCurrentPinballGame->boardSubState = 6;
    if (gCurrentPinballGame->boardState == 6)
        gCurrentPinballGame->boardSubState = 8;

    gCurrentPinballGame->allHolesCompleted = 0;
    gCurrentPinballGame->holeIndicators[0] = 0;
    gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    gCurrentPinballGame->lastBallImpactVelocityY = 0;
    gCurrentPinballGame->outLanePikaAnimSubFrame = 0;
    gCurrentPinballGame->outLanePikaAnimKeyframe = 0;
    if (gCurrentPinballGame->outLanePikaPosition != 2 || !gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->pikaChargeTarget = 0;
        gCurrentPinballGame->pikaChargeDisplay = 0;
        gCurrentPinballGame->pikaChargeSegmentPrev = 0;
        gCurrentPinballGame->pikaChargeSegment = 0;
        gCurrentPinballGame->pikaChargeSpriteOffsetX = 0;
        gCurrentPinballGame->pikaChargeSpriteY = -4;
        gCurrentPinballGame->pikaChargeSpriteScaleX = 0x100;
        gCurrentPinballGame->pikaChargeSpriteScaleY = 0x100;
        gCurrentPinballGame->pikaChargeFlashTimer = 0;
        gCurrentPinballGame->pikaChargeAnimDuration = 0;
    }

    gCurrentPinballGame->ballPowerUpLight[0] = 0;
    gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
    gCurrentPinballGame->bumperHitsSinceReset = 0;
    if (gMain.eReaderBonuses[EREADER_DX_MODE_CARD])
    {
        gCurrentPinballGame->ballUpgradeType = BALL_UPGRADE_TYPE_MASTER_BALL;
        gCurrentPinballGame->ballUpgradeCounter = 60 * 60;
        DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    }
    else
    {
        gCurrentPinballGame->ballUpgradeType = 0;
        gCurrentPinballGame->ballUpgradeCounter = 0;
    }

    gCurrentPinballGame->ballLocked = 0;
    DmaCopy16(3, &gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)OBJ_PLTT + 0x20, 0x20);
    gCurrentPinballGame->savedBonusMultiplier = gCurrentPinballGame->bonusMultiplier;
    gCurrentPinballGame->bonusMultiplier = 1;
    if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
    {
        gCurrentPinballGame->shouldProcessWhiscash = FALSE;
        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
        gCurrentPinballGame->whiscashStateTimer = 0;
        gCurrentPinballGame->rubyPondContentsChanging = TRUE;
        gCurrentPinballGame->rubyPondChangeTimer = 0x40;
        gCurrentPinballGame->bossShakeOffsetX = 0;

    }

    gCurrentPinballGame->rampPrizeAnimState = 0;
}
