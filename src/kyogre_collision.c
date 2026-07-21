#include "global.h"
#include "main.h"
#include "constants/board/kyogre_states.h"
#include "constants/collision.h"

s16 CollisionCheck_Kyogre(struct Vector16 *ballPosition, u16 *collisionAngle)
{
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

    if (ballPosition->y < 0x200)
    {
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

    CheckKyogreEntityCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);
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

    ProcessKyogreCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

void CheckKyogreEntityCollision(struct Vector16 *ballPosition, u16 *collisionAngle, u8 *collisionType)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;
    u16 maskedResult;

    if (gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_TOP_POSITION)
    {
        if (*collisionType & COLLISION_TYPE_MASK)
            return;

        deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x78) || (deltaY < 0 || deltaY >= 0x98))
            return;

        maskedResult = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & COLLISION_ANGLE_MASK;
        arrayValue = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & COLLISION_TYPE_MASK;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *collisionAngle = maskedResult;
        *collisionType = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_EMERGING_FROM_WATER)
    {
        if (*collisionType & COLLISION_TYPE_MASK)
            return;

        deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x58))
            return;

        maskedResult = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & COLLISION_ANGLE_MASK;
        arrayValue = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & COLLISION_TYPE_MASK;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *collisionAngle = maskedResult;
        *collisionType = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_JUMPING)
    {
        if (*collisionType & COLLISION_TYPE_MASK)
            return;

        deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x68))
            return;

        maskedResult = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & COLLISION_ANGLE_MASK;
        arrayValue = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & COLLISION_TYPE_MASK;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *collisionAngle = maskedResult;
        *collisionType = 6;
    }
}

void ProcessKyogreCollisionEvent(u8 triggerType, u16 *hasCollisionImpact, u16 *collisionAngle)
{
    switch (triggerType)
    {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_SHOCKWAVE;
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
