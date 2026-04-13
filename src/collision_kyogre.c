#include "global.h"
#include "main.h"

s16 CollisionCheck_Kyogre(struct Vector16 *arg0, u16 *arg1)
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
    if (arg0->y < 0x200)
    {
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
    }
    else
    {
        sp00 = 0;
        sp02 = 0;
    }

    CheckKyogreEntityCollision(arg0, &sp00, &sp02);
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
            if (gCurrentPinballGame->ball->positionQ0.x < gBoardConfig.fieldLayout.ballSpawnX - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gBoardConfig.fieldLayout.ballSpawnY - 8)
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
                        gCurrentPinballGame->ball->spinAcceleration = 0x28;
                        gCurrentPinballGame->ball->spinSpeed = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->spinAcceleration = 0xFFD8;
                        gCurrentPinballGame->ball->spinSpeed = 0xFFFF;
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
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;
        break;
    case 5:
        some_enum = 4;
        break;
    }

    ProcessKyogreCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckKyogreEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 arrayValue;
    u16 maskedResult;

    if (gCurrentPinballGame->boardEntityCollisionMode == 1)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x78) || (deltaY < 0 || deltaY >= 0x98))
            return;

        maskedResult = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm1CollisionMap[(deltaY * 0x78) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 2)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x58))
            return;

        maskedResult = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm2CollisionMap[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
    else if (gCurrentPinballGame->boardEntityCollisionMode == 3)
    {
        if (*arg2 & 0xF)
            return;

        deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

        if ((deltaX < 0 || deltaX >= 0x60) || (deltaY < 0 || deltaY >= 0x68))
            return;

        maskedResult = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & 0xFFF0;
        arrayValue = gKyogreForm3CollisionMap[(deltaY * 0x60) + deltaX] & 0xF;

        if (arrayValue == 0)
            return;

        gCurrentPinballGame->bossHitFlashTimer = 8;
        *arg1 = maskedResult;
        *arg2 = 6;
    }
}

void ProcessKyogreCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
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
