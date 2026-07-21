#include "global.h"
#include "constants/board/kecleon_states.h"
#include "constants/collision.h"

s16 CollisionCheck_Kecleon(struct Vector16 *ballPosition, u16 *collisionAngle)
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

    CheckKecleonEntityCollision(ballPosition, &boardCollisionAngle, &boardCollisionType);
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

            // Note: missing the 'up range/bounce' seen in other collision files. Possible minor bug?

            hasCollisionImpact = TRUE;
            break;
        case 2:
        case 3:
            gCurrentPinballGame->collisionSurfaceType = 0;
            gCurrentPinballGame->collisionResponseType = 1;
            *collisionAngle = boardCollisionAngle & COLLISION_ANGLE_MASK;
            hasCollisionImpact = TRUE;
            if (gCurrentPinballGame->kecleonBoardHitState == 0)
            {
                s32 kecleonActive = gCurrentPinballGame->kecleonTargetActive;
                if (kecleonActive == 0)
                {
                    gCurrentPinballGame->kecleonBoardHitState = 1;
                    gCurrentPinballGame->kecleonCollisionX = kecleonActive;
                }
            }
            gCurrentPinballGame->kecleonCollisionY = 40;
            break;
        case 5:
            boardTriggerType = 4;
            break;
    }

    ProcessKecleonBallDisturbanceCollisionEvent(boardTriggerType, &hasCollisionImpact, collisionAngle);
    return hasCollisionImpact;
}

// This handles the ball hitting the kecleon
void CheckKecleonEntityCollision(struct Vector16 *ballPosition, u16 *collisionAngle, u8 *collisionType)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->boardEntityCollisionMode == KECLEON_COLLISION_MODE_STANDING)
    {
        if (*collisionType & COLLISION_TYPE_MASK)
            return;

        deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gKecleonUprightCollisionMap[(deltaY * 0x40) + deltaX]) & COLLISION_TYPE_MASK;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->ballHidden)
            return;
        if (gCurrentPinballGame->bossEntityState >= KECLEON_ENTITY_STATE_HIT_WHILE_STANDING)
            return;

        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_HIT_WHILE_STANDING;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == KECLEON_COLLISION_MODE_KNOCKED_OVER)
    {
        u16 maskedResult;

        if (*collisionType & COLLISION_TYPE_MASK)
            return;

        deltaX = ballPosition->x - gCurrentPinballGame->bossCollisionX;
        deltaY = ballPosition->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gKecleonKnockedDownCollisionMap[(deltaY * 0x58) + deltaX] & COLLISION_ANGLE_MASK;
        arrayValue = gKecleonKnockedDownCollisionMap[(deltaY * 0x58) + deltaX] & COLLISION_TYPE_MASK;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->ballHidden)
            return;
        if (gCurrentPinballGame->bossEntityState == KECLEON_ENTITY_STATE_RESPOND_TO_HIT)
            return;

        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_HIT_WHILE_DOWN;
        *collisionAngle = maskedResult;
        *collisionType = 6;
    }
}

//This handles the signs of motion in the flower/bush/water collision that the *ball* triggers
void ProcessKecleonBallDisturbanceCollisionEvent(u8 triggerType, u16 *hasCollisionImpact, u16 *collisionAngle)
{
    s16 x, y;
    x = gCurrentPinballGame->ball->positionQ0.x;
    y = gCurrentPinballGame->ball->positionQ0.y;

    switch (triggerType)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 13:
        case 14:
        case 15:
            return;
        case KECLEON_TRIGGER_FLOWERS:
            if (x <= 0x72)
            {
                if (y <= 0x38)
                {
                    // Single top, under tree
                    if (gCurrentPinballGame->kecleonFlowerMotionTimer[0] <= 0)
                        gCurrentPinballGame->kecleonFlowerMotionTimer[0] = 0x18;
                }
                else
                {
                    // Double left
                    if (gCurrentPinballGame->kecleonFlowerMotionTimer[1] <= 0)
                        gCurrentPinballGame->kecleonFlowerMotionTimer[1] = 0x18;
                }
            }
            else if (y <= 0x63)
            {
                // Top right triple
                if (gCurrentPinballGame->kecleonFlowerMotionTimer[3] <= 0)
                    gCurrentPinballGame->kecleonFlowerMotionTimer[3] = 0x18;
            }
            else
            {
                // Bottom right double
                if (gCurrentPinballGame->kecleonFlowerMotionTimer[2] <= 0)
                    gCurrentPinballGame->kecleonFlowerMotionTimer[2] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_0:
            if (x <= 0x72)
            {
                if (y <= 0x45)
                {
                    // left bush of top left pair
                    if (gCurrentPinballGame->kecleonBushMotionTimer[7] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[7] = 0x18;
                }
                else
                {
                    // left bush of lower left trio
                    if (gCurrentPinballGame->kecleonBushMotionTimer[5] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[5] = 0x18;
                }
            }
            else if (y <= 0x45)
            {
                // left bush of top right pair
                if (gCurrentPinballGame->kecleonBushMotionTimer[8] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[8] = 0x18;
            }
            else
            {
                // left bush of bottom right trio
                if (gCurrentPinballGame->kecleonBushMotionTimer[0] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[0] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_WATER:
            if (gCurrentPinballGame->kecleonWaterBallCollisionTimer == 0)
            {
                gCurrentPinballGame->kecleonWaterMotionTimer[0] = 0xB;
                gCurrentPinballGame->ballTrailPosition[0].x = gCurrentPinballGame->ball->positionQ0.x - 7;
                gCurrentPinballGame->ballTrailPosition[0].y = gCurrentPinballGame->ball->positionQ0.y - 7;
            }
            else if (gCurrentPinballGame->kecleonWaterBallCollisionTimer == 3)
            {
                gCurrentPinballGame->kecleonWaterMotionTimer[1] = 0xB;
                gCurrentPinballGame->ballTrailPosition[1].x = gCurrentPinballGame->ball->positionQ0.x - 7;
                gCurrentPinballGame->ballTrailPosition[1].y = gCurrentPinballGame->ball->positionQ0.y - 7;
            }
            else if (gCurrentPinballGame->kecleonWaterBallCollisionTimer == 6)
            {
                gCurrentPinballGame->kecleonWaterMotionTimer[2] = 0xB;
                gCurrentPinballGame->ballTrailPosition[2].x = gCurrentPinballGame->ball->positionQ0.x - 7;
                gCurrentPinballGame->ballTrailPosition[2].y = gCurrentPinballGame->ball->positionQ0.y - 7;
            }
            else if (gCurrentPinballGame->kecleonWaterBallCollisionTimer == 9)
            {
                gCurrentPinballGame->kecleonWaterMotionTimer[3] = 0xB;
                gCurrentPinballGame->ballTrailPosition[3].x = gCurrentPinballGame->ball->positionQ0.x - 7;
                gCurrentPinballGame->ballTrailPosition[3].y = gCurrentPinballGame->ball->positionQ0.y - 7;
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_1:
            if (x <= 0x72)
            {
                if (y <= 0x45)
                {
                    // Right bush of top left pair
                    if (gCurrentPinballGame->kecleonBushMotionTimer[9] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[9] = 0x18;
                }
                else
                {
                    // Middle bush of bottom left trio
                    if (gCurrentPinballGame->kecleonBushMotionTimer[2] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[2] = 0x18;
                }
            }
            else if (y <= 0x45)
            {
                // Right bush of top right pair
                if (gCurrentPinballGame->kecleonBushMotionTimer[6] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[6] = 0x18;
            }
            else
            {
                // Middle bush of bottom right trio
                if (gCurrentPinballGame->kecleonBushMotionTimer[1] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[1] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_2:
            if (x <= 0x72)
            {
                // Right bush of bottom left trio
                if (gCurrentPinballGame->kecleonBushMotionTimer[4] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[4] = 0x18;
            }
            else
            {
                // Right bush of bottom right trio
                if (gCurrentPinballGame->kecleonBushMotionTimer[3] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[3] = 0x18;
            }
            break;
    }
}

//This handles the signs of motion in the flowers/bushes/water that *kecleon* triggers when it moves.
void ProcessKecleonSkulkingDisturbanceCollisionEvent(struct Vector16 *kecleonPosition)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    s16 x, y;
    u16 boardCollisionAngle;
    u8 boardCollisionType;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;
    u32 some_enum;

    gCurrentPinballGame->kecleonCollisionEnabled = TRUE;
    vec1.x = kecleonPosition->x / 8;
    vec1.y = kecleonPosition->y / 8;
    vec2.x = kecleonPosition->x % 8;
    vec2.y = kecleonPosition->y % 8;
    tileMapPage = vec1.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    vec1.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    boardCollisionAngle = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    boardCollisionType = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    some_enum = (boardCollisionType >> 2) >> 2;

    x = gCurrentPinballGame->kecleonCollisionPos.x;
    y = gCurrentPinballGame->kecleonCollisionPos.y;

    switch (some_enum)
    {
        case KECLEON_TRIGGER_FLOWERS:
            if (x <= 0x72)
            {
                if (y <= 0x38)
                {
                    if (gCurrentPinballGame->kecleonFlowerMotionTimer[0] <= 0)
                        gCurrentPinballGame->kecleonFlowerMotionTimer[0] = 0x18;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonFlowerMotionTimer[1] <= 0)
                        gCurrentPinballGame->kecleonFlowerMotionTimer[1] = 0x18;
                }
            }
            else if (y <= 0x63)
            {
                if (gCurrentPinballGame->kecleonFlowerMotionTimer[3] <= 0)
                    gCurrentPinballGame->kecleonFlowerMotionTimer[3] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonFlowerMotionTimer[2] <= 0)
                    gCurrentPinballGame->kecleonFlowerMotionTimer[2] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_0:
            if (x <= 0x72)
            {
                if (y <= 0x45)
                {
                    if (gCurrentPinballGame->kecleonBushMotionTimer[7] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[7] = 0x18;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonBushMotionTimer[5] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[5] = 0x18;
                }
            }
            else if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[8] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[8] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[0] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[0] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_WATER:
            gCurrentPinballGame->kecleonCollisionEnabled = FALSE;
            if (gCurrentPinballGame->kecleonWaterCollisionTimer == 0)
            {
                if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonWaterTileCollisionPosition[0].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonWaterTileCollisionPosition[0].y)
                {
                    gCurrentPinballGame->kecleonWaterMotionTimer[4] = 0x11;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[0].x = gCurrentPinballGame->kecleonCollisionPos.x;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[0].y = gCurrentPinballGame->kecleonCollisionPos.y;
                }
            }
            else if (gCurrentPinballGame->kecleonWaterCollisionTimer == 8)
            {
                if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonWaterTileCollisionPosition[1].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonWaterTileCollisionPosition[1].y)
                {
                    gCurrentPinballGame->kecleonWaterMotionTimer[5] = 0x11;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[1].x = gCurrentPinballGame->kecleonCollisionPos.x;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[1].y = gCurrentPinballGame->kecleonCollisionPos.y;
                }
            }
            else if (gCurrentPinballGame->kecleonWaterCollisionTimer == 16)
            {
                if (gCurrentPinballGame->kecleonCollisionPos.x != gCurrentPinballGame->kecleonWaterTileCollisionPosition[2].x || gCurrentPinballGame->kecleonCollisionPos.y != gCurrentPinballGame->kecleonWaterTileCollisionPosition[2].y)
                {
                    gCurrentPinballGame->kecleonWaterMotionTimer[6] = 0x11;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[2].x = gCurrentPinballGame->kecleonCollisionPos.x;
                    gCurrentPinballGame->kecleonWaterTileCollisionPosition[2].y = gCurrentPinballGame->kecleonCollisionPos.y;
                }
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_1:
            if (x <= 0x72)
            {
                if (y <= 0x45)
                {
                    if (gCurrentPinballGame->kecleonBushMotionTimer[9] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[9] = 0x18;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonBushMotionTimer[2] <= 0)
                        gCurrentPinballGame->kecleonBushMotionTimer[2] = 0x18;
                }
            }
            else if (y <= 0x45)
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[6] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[6] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[1] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[1] = 0x18;
            }
            break;
        case KECLEON_TRIGGER_BUSH_GROUP_2:
            if (x <= 0x72)
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[4] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[4] = 0x18;
            }
            else
            {
                if (gCurrentPinballGame->kecleonBushMotionTimer[3] <= 0)
                    gCurrentPinballGame->kecleonBushMotionTimer[3] = 0x18;
            }
            break;
    }
}
