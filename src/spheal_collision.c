#include "global.h"
#include "main.h"
#include "constants/board/spheal_states.h"
#include "constants/collision.h"

s16 CollisionCheck_Spheal(struct Vector16 *ballPosition, u16 *collisionAngle)
{
    u16 boardCollisionAngle;
    u8 boardCollisionType;
    u16 hasCollisionImpact;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 tileMapPage;
    s32 boardLayer;
    s16 collisionTileIndex;
    u8 collisionType, boardTriggerType;

    hasCollisionImpact = FALSE;
    gCurrentPinballGame->ball->spinAcceleration = SPIN_BOOST_NONE;

    div_result.x = ballPosition->x / 8;
    div_result.y = ballPosition->y / 8;
    div_remainder.x = ballPosition->x % 8;
    div_remainder.y = ballPosition->y % 8;
    tileMapPage = div_result.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    div_result.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][div_result.y * 64 + div_result.x];
    boardCollisionAngle = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];
    boardCollisionType = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];

    CheckSphealEntityCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);

    collisionType = boardCollisionType & COLLISION_TYPE_MASK;
    boardTriggerType = boardCollisionType >> 4;
    switch (collisionType)
    {
        case 1:
        case 4:
        case 6:
            gCurrentPinballGame->collisionSurfaceType = collisionType - 1;
            gCurrentPinballGame->collisionResponseType = 1;
            *collisionAngle = boardCollisionAngle;
            if (*collisionAngle >= ANGLE_UP_RANGE_MIN && *collisionAngle <= ANGLE_UP_RANGE_MAX)
            {
                if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) ||
                    gCurrentPinballGame->ball->positionQ0.y < (gBoardConfig.fieldLayout.ballSpawnY - 8))
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
        case 2:
        case 3:
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 1;
            *collisionAngle = boardCollisionAngle & COLLISION_ANGLE_MASK;

            if (gCurrentPinballGame->ball->positionQ0.x < 120)
                gCurrentPinballGame->sealeoStunnedTimer[0] = 24;
            else
                gCurrentPinballGame->sealeoStunnedTimer[1] = 24;

            hasCollisionImpact = TRUE;
            break;
        case 5:
            boardTriggerType = 4;
            break;
    }

    ProcessSphealCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

void CheckSphealEntityCollision(struct Vector16 *ballPosition, u16 *collisionAngle, u8 *collisionType)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->sphealEntityCollisionType[i] == SPHEAL_COLLISION_TYPE_SWIMMING)
        {
            if ((*collisionType & COLLISION_TYPE_MASK) != 0)
                continue;

            deltaX = ballPosition->x - gCurrentPinballGame->sphealEntityCollisionPos[i].x;
            deltaY = ballPosition->y - gCurrentPinballGame->sphealEntityCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & COLLISION_ANGLE_MASK;
            lowerReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & COLLISION_TYPE_MASK;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->ballRespawnState)
                continue;

            *collisionAngle = upperReadFromRom;
            *collisionType = lowerReadFromRom;
            *collisionType = 6;
            gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_HIT;
        }
        else if (gCurrentPinballGame->sphealEntityCollisionType[i] != SPHEAL_COLLISION_TYPE_INACTIVE)
        {
            //Handles ramp and 'walk down' collisions

            if ((*collisionType & COLLISION_TYPE_MASK) != 0)
                continue;

            deltaX = ballPosition->x - gCurrentPinballGame->sphealEntityCollisionPos[i].x;
            deltaY = ballPosition->y - gCurrentPinballGame->sphealEntityCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealRampCollisionMap[(deltaY * 64) + deltaX] & COLLISION_ANGLE_MASK;
            lowerReadFromRom = gSphealRampCollisionMap[(deltaY * 64) + deltaX] & COLLISION_TYPE_MASK;
            if (lowerReadFromRom == 0)
                continue;

            *collisionAngle = upperReadFromRom;
            *collisionType = lowerReadFromRom;
            *collisionType = 6;
            if (gCurrentPinballGame->sphealEntityCollisionType[i] == SPHEAL_COLLISION_TYPE_ON_RAMP)
            {
                gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_HIT;
            }
            else
            {
                //Will stun the spheal if they are hit while walking down after scoring.
                gCurrentPinballGame->sphealStunnedTimer[i] = 24;
            }
        }
    }
}

// Ball entering ramp, bounce position
void ProcessSphealCollisionEvent(u8 triggerType, u16 *hasCollisionImpact, u16 *collisionAngle)
{
    switch (triggerType)
    {
        case 2:
            gCurrentPinballGame->knockdownTargetIndex[2] = TARGET_SEALEO_LEFT;
            gCurrentPinballGame->knockdownPhase[2] = SPHEAL_KNOCKDOWN_PHASE_PREPARE_BOUNCE;
            break;
        case 3:
            gCurrentPinballGame->knockdownTargetIndex[2] = TARGET_SEALEO_RIGHT;
            gCurrentPinballGame->knockdownPhase[2] = SPHEAL_KNOCKDOWN_PHASE_PREPARE_BOUNCE;
            break;
        case 8:
            gCurrentPinballGame->knockdownTargetIndex[2] = TARGET_SEALEO_LEFT;
            gCurrentPinballGame->knockdownPhase[2] = SPHEAL_KNOCKDOWN_PHASE_BALL_PROXIMITY_CROSSED;
            gCurrentPinballGame->knockdownBallReadinessTimer[2] = 100;
            break;
        case 9:
            gCurrentPinballGame->knockdownTargetIndex[2] = TARGET_SEALEO_RIGHT;
            gCurrentPinballGame->knockdownPhase[2] = SPHEAL_KNOCKDOWN_PHASE_BALL_PROXIMITY_CROSSED;
            gCurrentPinballGame->knockdownBallReadinessTimer[2] = 100;
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
    }
}