#include "global.h"
#include "main.h"
#include "constants/board/groudon_states.h"
#include "constants/collision.h"

s16 CollisionCheck_Groudon(struct Vector16 *ballPosition, u16 *collisionAngle)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 boardCollisionAngle;
    u8 boardCollisionType;
    u16 hasCollisionImpact;
    u32 boardTriggerType;
    u32 collisionType;

    hasCollisionImpact = FALSE;
    gCurrentPinballGame->ball->spinAcceleration = SPIN_BOOST_NONE;

    if (ballPosition->y < 0x200)
    {
        s16 collisionTileIndex;
        s32 tileMapPage;
        s32 boardLayer;
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
    }
    else
    {
        boardCollisionAngle = 0;
        boardCollisionType = 0;
    }

    CheckGroudonEntityCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);
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
                if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
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
            gCurrentPinballGame->collisionSurfaceType = collisionType - 1;
            gCurrentPinballGame->collisionResponseType = 2;
            *collisionAngle = boardCollisionAngle & COLLISION_ANGLE_MASK;
            hasCollisionImpact = TRUE;
            break;
        case 5:
            boardTriggerType = 4;
            break;
    }

    ProcessGroudonCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

void CheckGroudonEntityCollision(struct Vector16 *ballPosition, u16 *collisionAngle, u8 *collisionType)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;
    s16 i;

    if (gCurrentPinballGame->boardEntityCollisionMode == GROUDON_COLLISION_MODE_ACTIVE)
    {
        if ((*collisionType & COLLISION_TYPE_MASK) == 0)
        {
            deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
            deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

            if ((deltaX >= 0 && deltaX < 0x70) && (deltaY >= 0 && deltaY < 0x80))
            {
                resultFromArray = gGroudonBodyCollisionMap[(deltaY * 0x70) + deltaX];
                maskedResult = resultFromArray & COLLISION_ANGLE_MASK;
                lowerNibble = resultFromArray & COLLISION_TYPE_MASK;
                if (lowerNibble != 0)
                {
                    if (gCurrentPinballGame->bossHitFlashTimer == 0)
                        gCurrentPinballGame->bossHitFlashTimer = 0x27;

                    *collisionAngle = maskedResult;
                    *collisionType = lowerNibble;
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->boulderCollisionPos[i].x <= 0)
            continue;
        if ((*collisionType & COLLISION_TYPE_MASK) != 0)
            continue;

        deltaX = ballPosition->x - gCurrentPinballGame->boulderCollisionPos[i].x;
        deltaY = ballPosition->y - gCurrentPinballGame->boulderCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & COLLISION_ANGLE_MASK;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & COLLISION_TYPE_MASK;

        if (lowerNibble == 0)
            continue;

        *collisionAngle = maskedResult;
        *collisionType = 6;
        gCurrentPinballGame->boulderHitFlag[i] = TRUE;
    }

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->firePillarCollisionPos[i].x <= 0)
            continue;
        if ((*collisionType & COLLISION_TYPE_MASK) != 0)
            continue;

        deltaX = ballPosition->x - gCurrentPinballGame->firePillarCollisionPos[i].x;
        deltaY = ballPosition->y - gCurrentPinballGame->firePillarCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & COLLISION_ANGLE_MASK;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & COLLISION_TYPE_MASK;

        if (lowerNibble == 0)
            continue;

        *collisionAngle = maskedResult;
        *collisionType = 6;
        gCurrentPinballGame->firePillarHitTimer[i] = 8;
    }
}

void ProcessGroudonCollisionEvent(u8 triggerType, u16 *hasCollisionImpact, u16 *collisionAngle)
{
    switch (triggerType)
    {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_SUFFICIENT_HITS;
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
    }
}
