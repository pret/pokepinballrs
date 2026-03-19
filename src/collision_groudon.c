#include "global.h"
#include "main.h"

s16 CollisionCheck_Groudon(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    if (arg0->y < 0x200)
    {
        s16 r2;
        s32 tileMapPage;
        s32 boardLayer;
        vec1.x = arg0->x / 8;
        vec1.y = arg0->y / 8;
        vec2.x = arg0->x % 8;
        vec2.y = arg0->y % 8;
        tileMapPage = vec1.y / 64;
        boardLayer = gCurrentPinballGame->boardLayerDepth;
        vec1.y %= 64;
        r2 = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
        sp00 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
        sp02 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][r2 * 64 + vec2.y * 8 + vec2.x];
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckGroudonEntityCollision(arg0, &sp00, &sp02);
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
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) || gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
            {
                if (gCurrentPinballGame->ball->spinSpeed > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->spinSpeed != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->spinAcceleration = 40;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = -40;
                        gCurrentPinballGame->ball->spinSpeed = -1;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = switch_enum - 1;
        gCurrentPinballGame->collisionResponseType = 2;
        *arg1 = sp00 & 0xFFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessGroudonCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckGroudonEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 resultFromArray;
    u16 maskedResult;
    u16 lowerNibble;
    s16 i;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if ((*arg2 & 0xF) == 0)
        {
            deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
            deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

            if ((deltaX >= 0 && deltaX < 0x70) && (deltaY >= 0 && deltaY < 0x80))
            {
                resultFromArray = gGroudonBodyCollisionMap[(deltaY * 0x70) + deltaX];
                maskedResult = resultFromArray & 0xFFF0;
                lowerNibble = resultFromArray & 0xF;
                if (lowerNibble != 0)
                {
                    if (gCurrentPinballGame->bossHitFlashTimer == 0)
                        gCurrentPinballGame->bossHitFlashTimer = 0x27;

                    *arg1 = maskedResult;
                    *arg2 = lowerNibble;
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->boulderCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->boulderCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->boulderCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->boulderHitFlag[i] = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->firePillarCollisionPos[i].x <= 0)
            continue;
        if ((*arg2 & 0xF) != 0)
            continue;

        deltaX = arg0->x - gCurrentPinballGame->firePillarCollisionPos[i].x;
        deltaY = arg0->y - gCurrentPinballGame->firePillarCollisionPos[i].y;

        if ((deltaX < 0 || deltaX >= 0x50) || (deltaY < 0 || deltaY >= 0x50))
            continue;

        maskedResult = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xFFF0;
        lowerNibble = gGroudonProjectileCollisionMap[(deltaY * 0x50) + deltaX] & 0xF;

        if (lowerNibble == 0)
            continue;

        *arg1 = maskedResult;
        *arg2 = 6;
        gCurrentPinballGame->firePillarHitTimer[i] = 8;
    }
}

void ProcessGroudonCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = 6;
        gCurrentPinballGame->ballFrozenState = 1;
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
