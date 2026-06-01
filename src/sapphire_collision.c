#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/board/sapphire_states.h"
#include "constants/collision.h"

extern u16 gSapphireTargetBumperIndexMap[];

s16 CollisionCheck_Sapphire(struct Vector16 *ballPosition, u16* collisionAngle) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 boardCollisionAngle;
    u8 boardCollisionType;
    u16 hasCollisionImpact;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;

    u32 boardTriggerType;
    u8 collisionType;

    hasCollisionImpact = FALSE;
    gCurrentPinballGame->ball->spinAcceleration = SPIN_BOOST_NONE;

    vec1.x = ballPosition->x / 8;
    vec1.y = ballPosition->y / 8;
    vec2.x = ballPosition->x % 8;
    vec2.y = ballPosition->y % 8;
    tileMapPage = vec1.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    vec1.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    boardCollisionAngle = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    boardCollisionType = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckSapphireBumperCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);

    collisionType = boardCollisionType & COLLISION_TYPE_MASK;
    boardTriggerType = boardCollisionType >> 4;

    switch (collisionType)
    {
    case 1:
    case 4:
        gCurrentPinballGame->collisionSurfaceType = collisionType - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *collisionAngle = boardCollisionAngle;
        if (*collisionAngle >= ANGLE_UP_RANGE_MIN && *collisionAngle <= ANGLE_UP_RANGE_MAX)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballSpawnX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
            {

                if (gCurrentPinballGame->ball->spinSpeed > 0)
                {
                    *collisionAngle = ANGLE_UP_RIGHT_BOUNCE;
                }
                else if (gCurrentPinballGame->ball->spinSpeed != 0)
                {
                    *collisionAngle = ANGLE_UP_LEFT_BOUNCE;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinAcceleration = ANGLE_UP_RIGHT_SPIN_BOOST;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *collisionAngle = ANGLE_UP_RIGHT_BOUNCE;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = ANGLE_UP_LEFT_SPIN_BOOST;
                        gCurrentPinballGame->ball->spinSpeed = -1;
                        *collisionAngle = ANGLE_UP_LEFT_BOUNCE;
                    }
                }

            }
        }
        hasCollisionImpact = TRUE;
        break;
    case 3:
    case 2:
        gCurrentPinballGame->collisionSurfaceType = collisionType - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *collisionAngle = boardCollisionAngle & COLLISION_ANGLE_MASK;
        hasCollisionImpact = TRUE;
        break;
    }

    ProcessSapphireCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

void CheckSapphireBumperCollision(struct Vector16 *ballPosition, s16 *collisionAngle, u8 *collisionType) {

    s16 deltaX;
    s16 deltaY;
    u16 maskedResult = 0;
    u8 lowerNibble = 0;
    s32 ix = 0;

    if (gCurrentPinballGame->ballInLowerHalf == 0)
    {
        if (gCurrentPinballGame->boardLayerDepth != 0)
            return;

        deltaX = ballPosition->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
        deltaY = ballPosition->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
            lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
            ix = 0;
        }
        if (lowerNibble == 0)
        {
            deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[1].x + ballPosition->x;
            deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[1].y + ballPosition->y;

            if (deltaX <= 63U && deltaY <= 63U)
            {
                maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                ix = 1;
            }

            if (lowerNibble == 0)
            {
                deltaX = gCurrentPinballGame->rubyBumperCollisionPosition[2].x + ballPosition->x;
                deltaY = gCurrentPinballGame->rubyBumperCollisionPosition[2].y + ballPosition->y;

                if (deltaX <= 63U && deltaY <= 63U)
                {
                    maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                    lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }
        gCurrentPinballGame->pondBumperStates[ix] = 6;

        *collisionAngle = maskedResult;
        *collisionType = lowerNibble;

        if (gCurrentPinballGame->bumperHitCountdown <= 0)
            gCurrentPinballGame->bumperHitCountdown = 2;
    }
}


void ProcessSapphireCollisionEvent(u8 triggerType, u16* hasCollisionImpact, u16* collisionAngle)
{
    s16 absVelY;
    s16 x0Position;
    s16 modRes;
    s16 index;
    u16 angle;
    int squaredMagnitude;

    switch (triggerType)
    {
        case SAPPHIRE_TRIGGER_MODE_START_BALL_LOCK:
            if (gCurrentPinballGame->collisionCooldownTimer == 0)
            {
                if (gCurrentPinballGame->ball->positionQ1.x >= 200)
                    gCurrentPinballGame->ballCatchState = TRAP_CATCH_HOLE;
                else
                    gCurrentPinballGame->ballCatchState = TRAP_EVO_SHOP_HOLE;

                DispatchSapphireCatchModeInit();
                gCurrentPinballGame->collisionResponseType = 7;
                *hasCollisionImpact = TRUE;
            }
            break;
        case SAPPHIRE_TRIGGER_2:
            if (gCurrentPinballGame->boardLayerDepth == 0)
            {
                gCurrentPinballGame->ball->oamPriority = 2;
                gCurrentPinballGame->boardLayerDepth = 2;
            }
            else if (gCurrentPinballGame->boardLayerDepth == 2)
            {
                gCurrentPinballGame->ball->oamPriority = 2;
                gCurrentPinballGame->boardLayerDepth = 3;
            }
            else if (gCurrentPinballGame->boardLayerDepth == 3)
            {
                gCurrentPinballGame->ball->oamPriority = 1;
            }
            break;
        case SAPPHIRE_TRIGGER_3:
            if (gCurrentPinballGame->boardLayerDepth == 2)
            {
                gCurrentPinballGame->ball->oamPriority = 3;
                gCurrentPinballGame->boardLayerDepth = 0;
            }
            else if (gCurrentPinballGame->boardLayerDepth == 3)
            {
                gCurrentPinballGame->ball->oamPriority = 2;
                gCurrentPinballGame->boardLayerDepth = 2;
            }
            break;
        case SAPPHIRE_TRIGGER_4:
            if (gCurrentPinballGame->mainBoardCountdownTimer == 0)
            {
                if (gCurrentPinballGame->ball->positionQ0.y < 260)
                {
                    if (gCurrentPinballGame->ball->positionQ0.x < 74)
                    {
                        if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                            && gCurrentPinballGame->sapphireBumperState[1] < 3)
                        {
                            if (gCurrentPinballGame->sapphireBumperState[1] == 1)
                                gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 6;
                            else
                                gCurrentPinballGame->sapphireBumperAnimKeyframe[1] = 4;

                            gCurrentPinballGame->sapphireBumperAnimSubTimer[1] = 0;
                            gCurrentPinballGame->sapphireBumperState[1] = 1;
                            PlayRumble(7);

                            gCurrentPinballGame->ball->velocity.x /= 2;
                            gCurrentPinballGame->ball->velocity.y /= 2;

                            memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));

                            gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[1];
                            gCurrentPinballGame->altBallCameraTimer = 25;
                        }
                    }
                    else if (gCurrentPinballGame->ball->positionQ0.x < 116)
                    {
                        if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                            && gCurrentPinballGame->sapphireBumperState[0] < 3)
                        {
                            if (gCurrentPinballGame->sapphireBumperState[0] == 1)
                                gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 6;
                            else
                                gCurrentPinballGame->sapphireBumperAnimKeyframe[0] = 4;

                            gCurrentPinballGame->sapphireBumperAnimSubTimer[0] = 0;
                            gCurrentPinballGame->sapphireBumperState[0] = 1;

                            PlayRumble(7);

                            gCurrentPinballGame->ball->velocity.x /= 2;
                            gCurrentPinballGame->ball->velocity.y /= 2;

                            memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));

                            gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[1];
                            gCurrentPinballGame->altBallCameraTimer = 25;
                        }
                    }
                    else
                    {
                        gCurrentPinballGame->pelipperFrameTimer = 1800;
                        gCurrentPinballGame->pelipperState = 1;

                        if (gCurrentPinballGame->progressLevel < 99)
                            gCurrentPinballGame->progressLevel++;

                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ0.x < 110)
                    {
                        gCurrentPinballGame->seedotCollisionTrigger = 1;
                        gCurrentPinballGame->ball->velocity.y /= 2;
                    }
                    else
                    {
                        if (gCurrentPinballGame->zigzagoonState == 0)
                            gCurrentPinballGame->zigzagoonState = 1;
                        else
                            gCurrentPinballGame->zigzagoonState = 0;

                        gCurrentPinballGame->ball->velocity.y /=2;
                        gCurrentPinballGame->scoreAddedInFrame = 3000;
                    }
                }

                gCurrentPinballGame->mainBoardCountdownTimer = 45;
                m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
            }
            break;
        case SAPPHIRE_TRIGGER_5:
            gCurrentPinballGame->ballTouchingSpoink = 1;
            gCurrentPinballGame->ballInLaunchChute = TRUE;
            gCurrentPinballGame->ballCollisionZone = 0;
            gCurrentPinballGame->hatchMachineActive = 0;
            break;
        case SAPPHIRE_TRIGGER_6:
            if (gCurrentPinballGame->ball->positionQ0.x < 120)
            {
                if (gCurrentPinballGame->ball->velocity.y > 0)
                {
                    angle = 0xDA00;
                    squaredMagnitude =
                        gCurrentPinballGame->ball->velocity.x * gCurrentPinballGame->ball->velocity.x +
                        gCurrentPinballGame->ball->velocity.y * gCurrentPinballGame->ball->velocity.y;

                    squaredMagnitude = Sqrt(squaredMagnitude * 4) / 2;
                    gCurrentPinballGame->ball->velocity.x = squaredMagnitude * Cos(angle) / 20000;
                    gCurrentPinballGame->ball->velocity.y = -squaredMagnitude * Sin(angle) / 20000;
                }
            }
            else
                gCurrentPinballGame->hatchMachineActive = 1;
            break;
        case SAPPHIRE_TRIGGER_7:
            if (gCurrentPinballGame->shopShockWallAnimState != 3)
            {
                gCurrentPinballGame->shopBumperHitTimer = 17;
                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *collisionAngle = 0xD800;
                *hasCollisionImpact = TRUE;
            }
            break;
        case SAPPHIRE_TRIGGER_8:
            x0Position = gCurrentPinballGame->ball->positionQ0.x;
            if (gCurrentPinballGame->boardLayerDepth > 0)
            {
                if (gCurrentPinballGame->ballCollisionZone == 7)
                {
                    gCurrentPinballGame->coinRewardAmount = 10;
                    if (gCurrentPinballGame->coinRewardLevel < 3)
                    {
                        if (gCurrentPinballGame->coinRewardLevel == 0)
                        {
                            gCurrentPinballGame->scoreAddedInFrame = 2000;
                            gCurrentPinballGame->coinRewardAmount = 1;
                        }
                        else if (gCurrentPinballGame->coinRewardLevel == 1)
                        {
                            gCurrentPinballGame->scoreAddedInFrame = 5000;
                            gCurrentPinballGame->coinRewardAmount = 5;
                        }
                        else
                        {
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                            gCurrentPinballGame->coinRewardAmount = 10;
                        }

                        gCurrentPinballGame->coinRewardLevel++;
                    }

                    gCurrentPinballGame->coinRewardTimer = 0;
                    gCurrentPinballGame->coinRewardLevelTimer = 0;
                }

                gCurrentPinballGame->ballCollisionZone = 1;
            }
            else
            {
                if (x0Position <= 72)
                {
                    if (gCurrentPinballGame->ballCollisionZone == 8)
                    {
                        if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                            && gCurrentPinballGame->evoArrowProgress < 3)
                        {
                            if (gCurrentPinballGame->evoArrowProgress == 0)
                                gCurrentPinballGame->scoreAddedInFrame = 2000;
                            else if (gCurrentPinballGame->evoArrowProgress == 1)
                                gCurrentPinballGame->scoreAddedInFrame = 5000;
                            else
                                gCurrentPinballGame->scoreAddedInFrame = 10000;
                            
                            gCurrentPinballGame->evoArrowProgress++;
                            m4aSongNumStart(SE_UNKNOWN_0x99);
                        }

                        gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_LEFT;
                    }

                    gCurrentPinballGame->ballCollisionZone = 2;
                }
                else if (x0Position <= 98)
                {
                    if (gCurrentPinballGame->ballPowerUpLight[0] == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 1000;
                    
                    gCurrentPinballGame->ballPowerUpLight[0] = 1;
                    gCurrentPinballGame->ballCollisionZone = 3;

                    if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[1] & gCurrentPinballGame->ballPowerUpLight[2]))
                    {
                        gCurrentPinballGame->ballPowerUpAnimActive = 1;
                        gCurrentPinballGame->ballShadowTimer = 60;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
                else if (x0Position <= 118)
                {
                    if (gCurrentPinballGame->ballPowerUpLight[1] == 0) 
                        gCurrentPinballGame->scoreAddedInFrame = 1000;
                    
                    gCurrentPinballGame->ballPowerUpLight[1] = 1;
                    gCurrentPinballGame->ballCollisionZone = 4;

                    if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[2]))
                    {
                        gCurrentPinballGame->ballPowerUpAnimActive = 1;
                        gCurrentPinballGame->ballShadowTimer = 60;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
                else if (x0Position <= 146)
                {
                    if (gCurrentPinballGame->ballPowerUpLight[2] == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 1000;
                    
                    gCurrentPinballGame->ballPowerUpLight[2] = 1;
                    gCurrentPinballGame->ballCollisionZone = 5;

                    if (gCurrentPinballGame->ballPowerUpAnimActive == 0 && (gCurrentPinballGame->ballPowerUpLight[0] & gCurrentPinballGame->ballPowerUpLight[1]))
                    {
                        gCurrentPinballGame->ballPowerUpAnimActive = 1;
                        gCurrentPinballGame->ballShadowTimer = 60;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->ballCollisionZone == 9)
                    {
                        if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                            && gCurrentPinballGame->catchArrowProgress < 3)
                        {
                            if (gCurrentPinballGame->catchArrowProgress == 0)
                                gCurrentPinballGame->scoreAddedInFrame = 2000;
                            else if (gCurrentPinballGame->catchArrowProgress == 1)
                                gCurrentPinballGame->scoreAddedInFrame = 5000;
                            else
                                gCurrentPinballGame->scoreAddedInFrame = 10000;
                            
                            gCurrentPinballGame->catchArrowProgress++;

                            if (gCurrentPinballGame->chargeFillValue == 13)
                                m4aSongNumStart(SE_UNKNOWN_0x99);

                            if (gCurrentPinballGame->catchArrowProgress > 1)
                                gCurrentPinballGame->catchProgressFlashing = 1;
                        }

                        gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_RIGHT;
                    }

                    gCurrentPinballGame->ballCollisionZone = 6;
                }
            }
            break;
        case SAPPHIRE_TRIGGER_9:
            x0Position = gCurrentPinballGame->ball->positionQ0.x;
            if (gCurrentPinballGame->boardLayerDepth > 0)
                gCurrentPinballGame->ballCollisionZone = 7;
            else if (x0Position <= 50)
                gCurrentPinballGame->ballCollisionZone = 8;
            else
                gCurrentPinballGame->ballCollisionZone = 9;
            break;
        case SAPPHIRE_TRIGGER_10:
            if (gCurrentPinballGame->ball->positionQ0.x <= 46)
            {
                gCurrentPinballGame->ballCollisionZone = 10;
                if (gCurrentPinballGame->holeIndicators[0] == 0)
                {
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                    gCurrentPinballGame->holeIndicators[0] = 1;
                    if (!gCurrentPinballGame->allHolesLit && (
                        gCurrentPinballGame->holeIndicators[1] &
                        gCurrentPinballGame->holeIndicators[2] &
                        gCurrentPinballGame->holeIndicators[3]))
                    {
                        gCurrentPinballGame->allHolesLit = TRUE;
                        gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
            }
            else if (gCurrentPinballGame->ball->positionQ0.x <= 120)
            {
                gCurrentPinballGame->ballCollisionZone = 11;

                if (gCurrentPinballGame->holeIndicators[1] == 0)
                {
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                    gCurrentPinballGame->holeIndicators[1] = 1; 
                    if (!gCurrentPinballGame->allHolesLit && (
                        gCurrentPinballGame->holeIndicators[0] &
                        gCurrentPinballGame->holeIndicators[2] &
                        gCurrentPinballGame->holeIndicators[3]))
                    {
                        gCurrentPinballGame->allHolesLit = TRUE;
                        gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
            }
            else if (gCurrentPinballGame->ball->positionQ0.x <= 193)
            {
                gCurrentPinballGame->ballCollisionZone = 12;
                if (gCurrentPinballGame->holeIndicators[2] == 0)
                {
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                    gCurrentPinballGame->holeIndicators[2] = 1;

                    if (!gCurrentPinballGame->allHolesLit && (
                        gCurrentPinballGame->holeIndicators[0] &
                        gCurrentPinballGame->holeIndicators[1] &
                        gCurrentPinballGame->holeIndicators[3]))
                    {
                        gCurrentPinballGame->allHolesLit = TRUE;
                        gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
            }
            else
            {
                gCurrentPinballGame->ballCollisionZone = 13;
                if (gCurrentPinballGame->holeIndicators[3] == 0)
                {
                    gCurrentPinballGame->scoreAddedInFrame = 1000;
                    gCurrentPinballGame->holeIndicators[3] = 1;
                    if (!gCurrentPinballGame->allHolesLit && (
                        gCurrentPinballGame->holeIndicators[0] &
                        gCurrentPinballGame->holeIndicators[1] &
                        gCurrentPinballGame->holeIndicators[2]))
                    {
                        gCurrentPinballGame->allHolesLit = TRUE;
                        gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                        gCurrentPinballGame->scoreAddedInFrame = 4000;
                    }
                }
            }
            break;
        case SAPPHIRE_TRIGGER_11:
            if (gCurrentPinballGame->pikaKickbackTimer == 0)
            {
                if (gCurrentPinballGame->ball->positionQ0.x <= 120)
                    gCurrentPinballGame->outLaneSide = 1;
                else
                    gCurrentPinballGame->outLaneSide = 2;

                if (gCurrentPinballGame->outLanePikaPosition < 2)
                {
                    if (gCurrentPinballGame->outLanePikaPosition == gCurrentPinballGame->outLaneSide - 1)
                        gCurrentPinballGame->pikaKickbackTimer = 120;
                }
                else
                {
                    gCurrentPinballGame->pikaKickbackTimer = 120;
                }
            }
            break;
        case SAPPHIRE_TRIGGER_12:
            if (gCurrentPinballGame->pikaSpinCooldownTimer == 0)
            {
                absVelY = gCurrentPinballGame->ball->velocity.y;
                gCurrentPinballGame->pikaSpinMomentum = absVelY;
                if (absVelY < 0)
                    absVelY = -absVelY;

                gCurrentPinballGame->pikaChargeTarget = gCurrentPinballGame->pikaChargeTarget + (absVelY / 3);
                if (gCurrentPinballGame->pikaChargeTarget > 168)
                    gCurrentPinballGame->pikaChargeTarget = 168;

                gCurrentPinballGame->pikaSpinCooldownTimer = 20;
            }
            break;
        case SAPPHIRE_TRIGGER_13:
            if (gCurrentPinballGame->ballCollisionZone != 14)
            {
                gCurrentPinballGame->ballCollisionZone = 14;
                index = gSapphireTargetBumperIndexMap[gCurrentPinballGame->hatchMachineTriggerCounter];
                gCurrentPinballGame->targetBumperAnimTimers[index] = 10;
                gCurrentPinballGame->hatchMachineTriggerCounter++;

                // Lock camera in place while in hatch machine loop
                if (gCurrentPinballGame->hatchMachineTriggerCounter == 3)
                {
                    memcpy(&gCurrentPinballGame->ballStates[1], &gCurrentPinballGame->ballStates[0], sizeof(*gCurrentPinballGame->ballStates));
                    gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[1];
                    if (gCurrentPinballGame->hatchMachineActive)
                        gCurrentPinballGame->hatchMachineProgressTickSignaled = TRUE;
                }

                // Release camera when leaving hatch ramp.
                if (gCurrentPinballGame->hatchMachineTriggerCounter == 11)
                    gCurrentPinballGame->cameraBall = gCurrentPinballGame->ballStates;

                modRes = (gCurrentPinballGame->hatchMachineTriggerCounter - 1) % 4;
                gMain.spriteGroups[47 + modRes].active = TRUE;
                gCurrentPinballGame->splashEffectFrameIndex[modRes] = 0;
                gCurrentPinballGame->splashEffectFrameTimer[modRes] = 0;
                gCurrentPinballGame->splashEffectPositionIndex[modRes] = gCurrentPinballGame->hatchMachineTriggerCounter - 1;

                if (gCurrentPinballGame->hatchMachineTriggerCounter > 12)
                    gCurrentPinballGame->hatchMachineTriggerCounter = 0;

                // Ensure sufficient speed to make it through the loop.
                if (index == 0 && gCurrentPinballGame->ball->velocity.y > -120)
                    gCurrentPinballGame->ball->velocity.y = -120;

                if (index == 2 && gCurrentPinballGame->ball->velocity.y > -180)
                    gCurrentPinballGame->ball->velocity.y = -180;
            }
            break;
        case SAPPHIRE_TRIGGER_14:
            if (gCurrentPinballGame->ballCollisionZone != 15)
            {
                gCurrentPinballGame->ballCollisionZone = 15;
                index = gSapphireTargetBumperIndexMap[gCurrentPinballGame->hatchMachineTriggerCounter];
                gCurrentPinballGame->targetBumperAnimTimers[index] = 10;
                gCurrentPinballGame->hatchMachineTriggerCounter++;

                modRes = (gCurrentPinballGame->hatchMachineTriggerCounter -1) % 4;
                gMain.spriteGroups[47 + modRes].active = TRUE;
                gCurrentPinballGame->splashEffectFrameIndex[modRes] = 0;
                gCurrentPinballGame->splashEffectFrameTimer[modRes] = 0;
                gCurrentPinballGame->splashEffectPositionIndex[modRes] = gCurrentPinballGame->hatchMachineTriggerCounter - 1;
                if (index == 1 && gCurrentPinballGame->ball->velocity.y > -150)
                    gCurrentPinballGame->ball->velocity.y = -150;
            }
            break;
        case SAPPHIRE_TRIGGER_15:
            if (gCurrentPinballGame->ball->positionQ0.y < 80)
            {
                if (gCurrentPinballGame->pelipperState == 1)
                    gCurrentPinballGame->pelipperState = 2;
            }
            else
            {
                if (gCurrentPinballGame->pelipperState == 2)
                {
                    gCurrentPinballGame->pelipperState = 3;
                    gCurrentPinballGame->pelipperFrameTimer = 0;
                }
            }

            break;
    }
}
