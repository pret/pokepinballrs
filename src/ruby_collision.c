#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"
#include "constants/collision.h"

extern const u16 gRubyLinooneLeftCollisionMap[];
extern const u16 gRubyLinooneRightCollisionMap[];
extern const u16 gWhiscashCollisionMap[];

extern struct SongHeader se_evo_get_arrow_earned;

s16 CollisionCheck_Ruby(struct Vector16 *ballPosition, u16* collisionAngle) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 boardCollisionAngle;
    u8 boardCollisionType;
    u16 hasCollisionImpact;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;

    u32 boardTriggerType;
    u32 collisionType;

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

    CheckRubyBoardCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);

    collisionType = boardCollisionType & COLLISION_TYPE_MASK;
    boardTriggerType = boardCollisionType >> 4;

    switch (collisionType)
    {
        case 1:
        case 4:
        case 6:
            gCurrentPinballGame->collisionSurfaceType = (collisionType - 1);
            gCurrentPinballGame->collisionResponseType = 1;
            *collisionAngle = boardCollisionAngle;

            // angle range is "up", with a tiny margin
            if (*collisionAngle >= ANGLE_UP_RANGE_MIN && *collisionAngle <= ANGLE_UP_RANGE_MAX)
            {
                if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballSpawnX - 8 ||
                    gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
                {

                    if (gCurrentPinballGame->ball->spinSpeed > 0)
                    {
                        *collisionAngle = ANGLE_UP_RIGHT_BOUNCE; //Slight Right bounce
                    }
                    else if (gCurrentPinballGame->ball->spinSpeed != 0)
                    {
                        *collisionAngle = ANGLE_UP_LEFT_BOUNCE; //Slight Left bounce
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
        case 2:
        case 3:
            gCurrentPinballGame->collisionSurfaceType = collisionType - 1;
            gCurrentPinballGame->collisionResponseType = 2;
            *collisionAngle = boardCollisionAngle & COLLISION_ANGLE_MASK;
            hasCollisionImpact = TRUE;

            break;
        case 5:
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORB_ZONE_HIT;
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            boardTriggerType = 0;
            break;
    }
    ProcessRubyCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);

    return hasCollisionImpact;
}


void CheckRubyBoardCollision(struct Vector16* ballPosition, u16* collisionAngle, u8* collisionType)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    s32 ix;

    maskedResult = 0;
    lowerNibble = 0;
    ix = 0;

    if ( !gCurrentPinballGame->ballInLowerHalf )
    {
        if (gCurrentPinballGame->boardLayerDepth != 0)
            return;

        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            if (gCurrentPinballGame->whiscashInvulnerable == 0)
                return;

            deltaX = ballPosition->x + gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
            deltaY = ballPosition->y + gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

            if (deltaX > 79U)
                return;

            if (deltaY > 87U)
                return;

            maskedResult = COLLISION_ANGLE_MASK & gWhiscashCollisionMap[(deltaY * 80) + deltaX];
            lowerNibble = COLLISION_TYPE_MASK & gWhiscashCollisionMap[(deltaY * 80) + deltaX];

            if (lowerNibble == 0)
                return;

            *collisionAngle = maskedResult;

            // if hit, while in its base mode, processes as a hit.
            // A Ball in the area being sucked in, or already hitting it won't affect it.
            if (gCurrentPinballGame->whiscashState <= WHISCASH_STATE_SITTING)
            {
                *collisionType = lowerNibble;
                gCurrentPinballGame->whiscashState = WHISCASH_STATE_HIT;
                return;
            }

            *collisionType = 1;
            return;
        }

        if (COLLISION_TYPE_MASK & *collisionType)
            return;

        deltaX = ballPosition->x + (u16) gCurrentPinballGame->rubyBumperCollisionPosition[0].x;
        deltaY = ballPosition->y + (u16) gCurrentPinballGame->rubyBumperCollisionPosition[0].y;

        if (deltaX <= 63U && deltaY <= 63U)
        {
            maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];
            lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[(deltaY * 64) + deltaX];

            if (lowerNibble != 0)
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
                if (lowerNibble != 0)
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

                    if (lowerNibble == 0)
                        return;

                    ix = 2;
                }

                if (lowerNibble == 0)
                    return;
            }
        }

        if (!gCurrentPinballGame->rubyPondContentsChanging)
            gCurrentPinballGame->pondBumperStates[ix] = 107;

        *collisionAngle = maskedResult;
        *collisionType = lowerNibble;

        if (gCurrentPinballGame->bumperHitCountdown > 0)
            return;

        gCurrentPinballGame->bumperHitCountdown = 2;
    }
    else
    {
        if ((*collisionType & COLLISION_TYPE_MASK) == 0)
        {
            if (gCurrentPinballGame->linooneSideBumperAnimPhase[SIDE_IX_LEFT] > 0)
            {
                s16 deltaY_alt;
                deltaX = 2 * (-24 -gCurrentPinballGame->linooneSideBumperExtensionOffset[SIDE_IX_LEFT]) + ballPosition->x;
                deltaY_alt = ballPosition->y -580;

                if (deltaX <= 71U && deltaY_alt <= 71U)
                {
                    *collisionAngle = COLLISION_ANGLE_MASK & gRubyLinooneLeftCollisionMap[(deltaY_alt * 72) + deltaX];
                    *collisionType = COLLISION_TYPE_MASK & gRubyLinooneLeftCollisionMap[(deltaY_alt * 72) + deltaX];

                    if (*collisionType & 1)
                    {
                        gCurrentPinballGame->linooneSideBumperHitFlag = SIDE_COLLISION_LEFT;
                        *collisionType = 6;
                    }
                }
            }

            if (gCurrentPinballGame->linooneSideBumperAnimPhase[SIDE_IX_RIGHT] > 0)
            {
                deltaX = ((gCurrentPinballGame->linooneSideBumperExtensionOffset[SIDE_IX_RIGHT] - 180) * 2) + ballPosition->x;
                deltaY = ballPosition->y -580;

                if (deltaX <= 71U && deltaY <= 71U)
                {
                    *collisionAngle = COLLISION_ANGLE_MASK & gRubyLinooneRightCollisionMap[(deltaY * 72) + deltaX];
                    *collisionType = COLLISION_TYPE_MASK & gRubyLinooneRightCollisionMap[(deltaY * 72) + deltaX];

                    if (*collisionType & 1)
                    {
                        gCurrentPinballGame->linooneSideBumperHitFlag = SIDE_COLLISION_RIGHT;
                        *collisionType = 6;
                        return;
                    }
                }
            }
        }
    }
}

void ProcessRubyCollisionEvent(u8 triggerType, s16* hasCollisionImpact, u16* collisionAngle)
{
    s16 absVelY;

    switch (triggerType)
    {
    case RUBY_TRIGGER_MODE_START_BALL_LOCK:
        if (gCurrentPinballGame->collisionCooldownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ1.x > 359)
            {
                if (gCurrentPinballGame->ball->positionQ1.y > 199)
                    gCurrentPinballGame->ballCatchState = TRAP_CATCH_HOLE;
                else
                    gCurrentPinballGame->ballCatchState = TRAP_EVO_SHOP_HOLE;
            }
            else
                gCurrentPinballGame->ballCatchState= TRAP_EGG_HOLE;

            DispatchRubyCatchModeInit();
            gCurrentPinballGame->collisionResponseType = 7;
            *hasCollisionImpact = TRUE;
            return;
        }
    default:
        return;
    case RUBY_TRIGGER_CHANGE_LAYER_UP:
        // Move ball collision/draw order to 'ramp' layer.
        if (gCurrentPinballGame->boardLayerDepth == 0)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 2;
            break;
        }

        if (gCurrentPinballGame->boardLayerDepth == 2)
        {
            gCurrentPinballGame->ball->oamPriority = 2;
            gCurrentPinballGame->boardLayerDepth = 3;
        }

        break;
    case RUBY_TRIGGER_CHANGE_LAYER_DOWN:
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

        if (gCurrentPinballGame->nuzleafAnimState == 6)
            gCurrentPinballGame->nuzleafAnimState = 7;

        if (gCurrentPinballGame->shopDoorTargetFrame & 0xF0 )
            gCurrentPinballGame->shopDoorTargetFrame = 0;

        if (gCurrentPinballGame->shopDoorOpenLevel & 0xF0)
            gCurrentPinballGame->shopDoorOpenLevel = 0;

        break;
    case RUBY_TRIGGER_TARGET_SWITCH:
        if (gCurrentPinballGame->mainBoardCountdownTimer == 0)
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 131)
            {
                // Bonus Multiplier Addition button
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (gCurrentPinballGame->progressLevel <= 98)
                    gCurrentPinballGame->progressLevel++;
            }
            else if (gCurrentPinballGame->ball->positionQ0.x > 91)
            {
                // Pond Change Button
                gCurrentPinballGame->scoreAddedInFrame = 2000;
                gCurrentPinballGame->rubyPondChangeTimer = 0;
                gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            }
            else
            {
                // Chikorita Firing button
                gCurrentPinballGame->scoreAddedInFrame = 1000;

                if (!gCurrentPinballGame->chikoritaFlashActive)
                {
                    gCurrentPinballGame->chikoritaFlashActive = TRUE;
                    gCurrentPinballGame->chikoritaFlashTimer = 0;
                }
            }
            gCurrentPinballGame->mainBoardCountdownTimer = 45;

            m4aSongNumStart(SE_TRIGGER_BUTTON_HIT);
        }
        break;
    case RUBY_TRIGGER_BALL_LAUNCH_POSITION:
        gCurrentPinballGame->ballInLaunchChute = TRUE;
        gCurrentPinballGame->ballTouchingSpoink = TRUE;
        gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_LAUNCH_CHUTE;
        return;
    case RUBY_TRIGGER_CLOSE_LAUNCH_LANE:
        if ( !gCurrentPinballGame->ballInLowerHalf )
        {
            // Change upper board collision to use the 'closed launch ramp' alternate
            SetBoardCollisionConfig(1);
            gCurrentPinballGame->boardCollisionConfigChanged = TRUE;
        }
        break;
    case RUBY_TRIGGER_NUZLEAF:
        if (gCurrentPinballGame->ball->positionQ0.x < 50)
        {
            if (gCurrentPinballGame->nuzleafHitFlag == 0)
            {
                gCurrentPinballGame->nuzleafHitFlag = 1;
                gCurrentPinballGame->nuzleafAnimState = 1;
                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *collisionAngle = 0xB000;
                *hasCollisionImpact = TRUE;
            }
        }
        else if (gCurrentPinballGame->nuzleafHitFlag == 1)
        {
            gCurrentPinballGame->nuzleafHitFlag = 2;
            gCurrentPinballGame->nuzleafAnimState = 3;
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 2;
            *collisionAngle = 0xA000;
            *hasCollisionImpact = TRUE;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;

            memcpy(&gCurrentPinballGame->ballStates[1], gCurrentPinballGame->ballStates, 0x44U);

            gCurrentPinballGame->cameraBall = &gCurrentPinballGame->ballStates[1];
            gCurrentPinballGame->altBallCameraTimer = 120;
        }

        gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_NUZLEAF_RAMP;
        return;
    case RUBY_TRIGGER_UPPER_LANE_ROLLOVER:
        // Top of Evo/Get orbit and coin lane, Ball powerup lamps
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            // Evo ramp upper rollover
            if (gCurrentPinballGame->ballCollisionZone == RUBY_ZONE_EVO_LANE_BOTTOM)
            {
                if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                    && gCurrentPinballGame->evoArrowProgress <= 2)
                {
                    if (gCurrentPinballGame->evoArrowProgress == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->evoArrowProgress == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->evoArrowProgress++;

                    m4aSongNumStart(SE_EVO_GET_ARROW_EARNED);
                }

                gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_LEFT;
            }
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_EVO_LANE_TOP;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            // Coin ramp upper rollover
            if (gCurrentPinballGame->ballCollisionZone == RUBY_ZONE_COIN_LANE_BOTTOM)
            {
                gCurrentPinballGame->coinRewardAmount = 10;

                if(gCurrentPinballGame->coinRewardLevel <= 2)
                {
                    if(gCurrentPinballGame->coinRewardLevel == 0)
                    {
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                        gCurrentPinballGame->coinRewardAmount = 1;
                    }
                    else if(gCurrentPinballGame->coinRewardLevel == 1)
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

            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_COIN_LANE_TOP;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 126)
        {
            // Left Ball Upgrade rollover
            if (!gCurrentPinballGame->ballPowerUpLight[0])
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[0] = TRUE;
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_LEFT_BALL_UPGRADE_LANE;

            if (!gCurrentPinballGame->ballPowerUpAnimActive)
            {
                if (!(gCurrentPinballGame->ballPowerUpLight[1] &
                      gCurrentPinballGame->ballPowerUpLight[2]))
                    return;

                gCurrentPinballGame->ballPowerUpAnimActive = TRUE;
                gCurrentPinballGame->ballShadowTimer = 60;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
                return;
            }
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 148)
        {
            // Middle Ball Upgrade rollover
            if (!gCurrentPinballGame->ballPowerUpLight[1])
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[1] = TRUE;
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_CENTER_BALL_UPGRADE_LANE;

            if (gCurrentPinballGame->ballPowerUpAnimActive)
                return;

            if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                    gCurrentPinballGame->ballPowerUpLight[2]))
                return;

            gCurrentPinballGame->ballPowerUpAnimActive = TRUE;
            gCurrentPinballGame->ballShadowTimer = 60;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 172)
        {
            // Right Ball Upgrade rollover
            if (!gCurrentPinballGame->ballPowerUpLight[2])
                gCurrentPinballGame->scoreAddedInFrame = 1000;

            gCurrentPinballGame->ballPowerUpLight[2] = TRUE;
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_RIGHT_BALL_UPGRADE_LANE;

            if (gCurrentPinballGame->ballPowerUpAnimActive)
                return;

            if (!(gCurrentPinballGame->ballPowerUpLight[0] &
                    gCurrentPinballGame->ballPowerUpLight[1]))
                return;

            gCurrentPinballGame->ballPowerUpAnimActive = TRUE;
            gCurrentPinballGame->ballShadowTimer = 60;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
        else {
            // Get lane upper rollover
            if (gCurrentPinballGame->ballCollisionZone == RUBY_ZONE_GET_LANE_BOTTOM)
            {
                // coming from lower Get lane rollover
                if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                    && gCurrentPinballGame->catchArrowProgress <= 2)
                {
                    if (gCurrentPinballGame->catchArrowProgress == 0)
                        gCurrentPinballGame->scoreAddedInFrame = 2000;
                    else if (gCurrentPinballGame->catchArrowProgress == 1)
                        gCurrentPinballGame->scoreAddedInFrame = 5000;
                    else
                        gCurrentPinballGame->scoreAddedInFrame = 10000;

                    gCurrentPinballGame->catchArrowProgress++;

                    MPlayStart(&gMPlayInfo_SE1, &se_evo_get_arrow_earned);

                    if (gCurrentPinballGame->catchArrowProgress > 1)
                        gCurrentPinballGame->catchProgressFlashing = TRUE;
                }

                gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_RIGHT;
            }

            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_GET_LANE_TOP;
            return;
        }

        break;
    case RUBY_TRIGGER_LOWER_LANE_ROLLOVER:
        if (gCurrentPinballGame->ball->positionQ0.x <= 50)
        {
            // Evo lane lower rollover
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_EVO_LANE_BOTTOM;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 100)
        {
            // Coin lane lower rollover
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_COIN_LANE_BOTTOM;
            return;
        }
        else
        {
            // Get lane lower rollover
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_GET_LANE_BOTTOM;
            return;
        }
    case RUBY_TRIGGER_HOLE_ROLLOVER:
        if (gCurrentPinballGame->ball->positionQ0.x <= 46)
        {
            // H rollover trigger
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_H_OUTLANE;

            if (gCurrentPinballGame->holeIndicators[0])
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[0] = TRUE;

            if (gCurrentPinballGame->allHolesLit)
                return;

            if (!(gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = TRUE;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 120)
        {
            // O rollover trigger
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_O_INLANE;

            if (gCurrentPinballGame->holeIndicators[1])
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[1] = TRUE;

            if (gCurrentPinballGame->allHolesLit)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[2] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = TRUE;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
        else if (gCurrentPinballGame->ball->positionQ0.x <= 193)
        {
            // L rollover trigger
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_L_INLANE;

            if (gCurrentPinballGame->holeIndicators[2])
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[2] = TRUE;

            if (gCurrentPinballGame->allHolesLit)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                  gCurrentPinballGame->holeIndicators[1] &
                  gCurrentPinballGame->holeIndicators[3]))
                return;

            gCurrentPinballGame->allHolesLit = TRUE;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
        else
        {
            // E rollover trigger
            gCurrentPinballGame->ballCollisionZone = RUBY_ZONE_E_OUTLANE;

            if (gCurrentPinballGame->holeIndicators[3])
                return;

            gCurrentPinballGame->scoreAddedInFrame = 1000;
            gCurrentPinballGame->holeIndicators[3] = TRUE;

            if (gCurrentPinballGame->allHolesLit)
                return;

            if (!(gCurrentPinballGame->holeIndicators[0] &
                gCurrentPinballGame->holeIndicators[1] &
                gCurrentPinballGame->holeIndicators[2]))
                return;

            gCurrentPinballGame->allHolesLit = TRUE;
            gCurrentPinballGame->allHolesLitBlinkTimer = 126;
            gCurrentPinballGame->scoreAddedInFrame = 4000;
            return;
        }
    case RUBY_TRIGGER_CONDITIONAL_ACTIVATION:
        // Shop door, ramp prize, pika kickback
        if ( !gCurrentPinballGame->ballInLowerHalf )
        {
            if (gCurrentPinballGame->ball->positionQ0.x > 170)
            {
                // Shop Door
                if (gCurrentPinballGame->shopDoorTargetFrame > 2U)
                    return;

                gCurrentPinballGame->collisionSurfaceType = 0;
                gCurrentPinballGame->collisionResponseType = 2;
                *collisionAngle = 0xB000;
                *hasCollisionImpact = TRUE;

                if (gCurrentPinballGame->boardState <= MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
                    && gCurrentPinballGame->shopDoorOpenLevel <= 2)
                {
                    gCurrentPinballGame->shopDoorOpenLevel = 3;
                    gCurrentPinballGame->shopDoorAnimDelay = 5;
                }

                gCurrentPinballGame->scoreAddedInFrame = 50000;
                return;
            }
            else {
                // Ramp prize
                if (gCurrentPinballGame->nuzleafAnimState <= 4)
                {
                    gCurrentPinballGame->collisionSurfaceType = 0;
                    gCurrentPinballGame->collisionResponseType = 2;
                    *collisionAngle = 0xF800;
                    *hasCollisionImpact = TRUE;
                }

                if (gCurrentPinballGame->nuzleafAnimState == 5)
                    gCurrentPinballGame->nuzleafAnimState = 6;

                if (gCurrentPinballGame->rampPrizeType == 0)
                    return;

                if (gCurrentPinballGame->rampPrizeType == 1)
                    gCurrentPinballGame->oneUpAnimTimer = 90;
                else
                {
                    gCurrentPinballGame->ballPowerUpOverride = TRUE;
                    gCurrentPinballGame->ballPowerUpAnimActive = TRUE;
                    gCurrentPinballGame->ballShadowTimer = 60;
                    m4aSongNumStart(SE_RAMP_PRIZE_COLLECTED);
                }

                gCurrentPinballGame->rampPrizeType = 0;
                gCurrentPinballGame->rampPrizeRespawnTimer = 600;
                return;
            }
        }
        else
        {
            // Pika Kickback trigger
            if (gCurrentPinballGame->pikaKickbackTimer != 0)
                return;

            if (gCurrentPinballGame->ball->positionQ0.x <= 120)
                gCurrentPinballGame->outLaneSide = OUTLANE_LEFT;
            else
                gCurrentPinballGame->outLaneSide = OUTLANE_RIGHT;

            if (gCurrentPinballGame->outLanePikaPosition < PIKA_BOTH_SIDES)
            {
                if (gCurrentPinballGame->outLanePikaPosition != gCurrentPinballGame->outLaneSide - 1)
                    return;
                else
                    gCurrentPinballGame->pikaKickbackTimer = 120;
                return;
            }

            gCurrentPinballGame->pikaKickbackTimer = 120;
            return;
        }
    case RUBY_TRIGGER_PIKA_CHARGE_SPINNER:
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
    case RUBY_TRIGGER_CYNDAQUIL_LOW_POSITION:
        if (!gCurrentPinballGame->cyndaquilCollisionEnabled)
            return;

        if (gCurrentPinballGame->collisionCooldownTimer != 0)
            return;

        if (gCurrentPinballGame->eggCaveState != 0)
            return;

        gCurrentPinballGame->eggCaveState++;

        gCurrentPinballGame->cyndaquilCollisionEnabled = FALSE;
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 2;

        *collisionAngle = 0xD000;
        *hasCollisionImpact = TRUE;
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        m4aSongNumStart(SE_CYNDAQUIL_EGG_GUARD_HIT);
        PlayRumble(7);
        return;
    case RUBY_TRIGGER_CYNDAQUIL_MID_POSITION:
        if (!gCurrentPinballGame->cyndaquilCollisionEnabled)
            return;

        if (gCurrentPinballGame->collisionCooldownTimer != 0)
            return;

        if (gCurrentPinballGame->eggCaveState != 1)
            return;

        gCurrentPinballGame->eggCaveState++;
        gCurrentPinballGame->cyndaquilCollisionEnabled = FALSE;
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 2;
        *collisionAngle = 0xCC00;
        *hasCollisionImpact = TRUE;

        m4aSongNumStart(SE_CYNDAQUIL_EGG_GUARD_HIT);
        gCurrentPinballGame->scoreAddedInFrame = 5000;
        PlayRumble(7);
        return;
    case RUBY_TRIGGER_CYNDAQUIL_HIGH_POSITION:
        if (gCurrentPinballGame->boardState > MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE
            && gCurrentPinballGame->boardState != MAIN_BOARD_STATE_EGG_HATCH_MODE)
        {
            if (gCurrentPinballGame->eggCaveExitDelayTimer == 0)
            {
                if (gCurrentPinballGame->eggCaveState == 2)
                {
                    gCurrentPinballGame->collisionSurfaceType = 0;
                    gCurrentPinballGame->collisionResponseType = 2;
                    *collisionAngle = 0xC800;
                    *hasCollisionImpact = TRUE;
                    gCurrentPinballGame->eggCaveState++;

                    m4aSongNumStart(SE_CYNDAQUIL_EGG_GUARD_HIT);
                    gCurrentPinballGame->scoreAddedInFrame = 5000;
                    PlayRumble(7);
                    return;
                }
                else if (gCurrentPinballGame->eggCaveState == 3)
                {
                    gCurrentPinballGame->collisionSurfaceType = 0;
                    gCurrentPinballGame->collisionResponseType = 2;
                    *collisionAngle = 0xC800;
                    *hasCollisionImpact = TRUE;

                    m4aSongNumStart(SE_CYNDAQUIL_EGG_GUARD_HIT);
                    gCurrentPinballGame->eggCaveReEntryFlag = TRUE;
                    PlayRumble(7);
                    return;
                }
            }
        }
        else if (gCurrentPinballGame->cyndaquilCollisionEnabled && gCurrentPinballGame->eggCaveState == 2)
        {
            gCurrentPinballGame->eggCaveState++;
            gCurrentPinballGame->cyndaquilCollisionEnabled = FALSE;
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 2;
            *collisionAngle = 0xC800;
            *hasCollisionImpact = TRUE;

            m4aSongNumStart(SE_CYNDAQUIL_EGG_GUARD_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            PlayRumble(7);
        }

        break;
    }
}


