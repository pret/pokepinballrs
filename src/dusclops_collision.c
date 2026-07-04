#include "global.h"
#include "main.h"
#include "constants/board/dusclops_states.h"
#include "constants/collision.h"

s16 CollisionCheck_Dusclops(struct Vector16* ballPosition, u16* collisionAngle) {
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

    CheckDusclopsEntitiesCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);
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

    CheckDusclopsAbsorbZoneHit(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

void CheckDusclopsEntitiesCollision(struct Vector16 *ballPosition, s16* collisionAngle, u8* collisionType) {
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    u8 temp;

    maskedResult = 0;
    lowerNibble = 0;

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS)
    {
        if (*collisionType != 0)
            return;

        deltaX = ballPosition->x -gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y -gCurrentPinballGame->bossCollisionY;

        if (deltaX > 95U || deltaY > 119U)
            return;

        maskedResult = COLLISION_ANGLE_MASK & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];
        lowerNibble = COLLISION_TYPE_MASK & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];

        if (lowerNibble == 0)
            return;

        //Can be hit when ready to absorb (2) or when walking (3)
        temp = gCurrentPinballGame->bossEntityState -3;
        if (temp <= 1U)
            *collisionType = 1;
        else
            *collisionType = lowerNibble;

        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT;
        *collisionAngle = maskedResult;

        return;
    }

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSKULL)
    {
        if (*collisionType != 0)
            return;

        if (gCurrentPinballGame->minionCanCollide[0] )
        {
            deltaX = ballPosition->x - gCurrentPinballGame->minionCollisionPosition[0].x;
            deltaY = ballPosition->y - gCurrentPinballGame->minionCollisionPosition[0].y;

            if (deltaX < 64U && deltaY < 64U)
            {
                maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                if (lowerNibble != 0)
                    gCurrentPinballGame->minionState[0] = DUSKULL_ENTITY_STATE_HIT;
            }
        }

        if (lowerNibble == 0)
        {
            if (gCurrentPinballGame->minionCanCollide[1] )
            {
                deltaX = ballPosition->x - gCurrentPinballGame->minionCollisionPosition[1].x;
                deltaY = ballPosition->y - gCurrentPinballGame->minionCollisionPosition[1].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                        gCurrentPinballGame->minionState[1] = DUSKULL_ENTITY_STATE_HIT;
                }
            }
        }

        if (lowerNibble == 0)
        {
            if ( gCurrentPinballGame->minionCanCollide[2] )
            {
                deltaX = ballPosition->x - gCurrentPinballGame->minionCollisionPosition[2].x;
                deltaY = ballPosition->y - gCurrentPinballGame->minionCollisionPosition[2].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = COLLISION_ANGLE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = COLLISION_TYPE_MASK & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                    {
                        gCurrentPinballGame->minionState[2] = DUSKULL_ENTITY_STATE_HIT;
                    }
                }
            }
        }

        if (lowerNibble != 0)
        {
            *collisionAngle = maskedResult;
            *collisionType = 6;
        }
        return;
    }
}

void CheckDusclopsAbsorbZoneHit(u8 triggerType, u16 *hasCollisionImpact, u16 *collisionAngle)
{
    switch (triggerType)
    {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE;
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
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

