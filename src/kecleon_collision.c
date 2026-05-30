#include "global.h"
#include "constants/board/kecleon_states.h"

s16 CollisionCheck_Kecleon(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    tileMapPage = vec1.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    vec1.y %= 64;
    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckKecleonEntityCollision(arg0, &sp00, &sp02);
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;

    switch (switch_enum)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00;
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
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
        some_enum = 4;
        break;
    }

    ProcessKecleonBallDisturbanceCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

// This handles the ball hitting the kecleon
void CheckKecleonEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;

    if (gCurrentPinballGame->boardEntityCollisionMode == KECLEON_COLLISION_MODE_STANDING)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x3F) || (deltaY < 0 || deltaY > 0x57))
            return;

        arrayValue = (u8)(gKecleonTongueCollisionMap[(deltaY * 0x40) + deltaX]) & 0xF;

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

        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX > 0x57) || (deltaY < 0 || deltaY > 0x3F))
            return;

        maskedResult = gKecleonBodyCollisionMap[(deltaY * 0x58) + deltaX] & 0xFFF0;
        arrayValue = gKecleonBodyCollisionMap[(deltaY * 0x58) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;
        if (gCurrentPinballGame->ball->ballHidden)
            return;
        if (gCurrentPinballGame->bossEntityState == KECLEON_ENTITY_STATE_RESPOND_TO_HIT)
            return;

        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_HIT_WHILE_DOWN;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

//This handles the signs of motion in the flower/bush/water collision that the *ball* triggers
void ProcessKecleonBallDisturbanceCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    s16 x, y;
    x = gCurrentPinballGame->ball->positionQ0.x;
    y = gCurrentPinballGame->ball->positionQ0.y;

    switch (arg0)
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
    case 8:
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
    case 9:
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
    case 10:
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
    case 11:
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
    case 12:
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

//This handles the signs of motion in the flowers/bushes/water that *kecleon* triggers when it moves.
void ProcessKecleonSkulkingDisturbanceCollisionEvent(struct Vector16 *arg0)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    s16 x, y;
    u16 sp00;
    u8 sp02;
    s16 collisionTileIndex;
    s32 tileMapPage;
    s32 boardLayer;
    u32 some_enum;

    gCurrentPinballGame->kecleonCollisionEnabled = 1;
    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    tileMapPage = vec1.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    vec1.y %= 64;
    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    some_enum = (sp02 >> 2) >> 2;

    x = gCurrentPinballGame->kecleonCollisionPos.x;
    y = gCurrentPinballGame->kecleonCollisionPos.y;

    switch (some_enum)
    {
    case 8:
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
    case 9:
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
    case 10:
        gCurrentPinballGame->kecleonCollisionEnabled = 0;
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
    case 11:
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
    case 12:
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
