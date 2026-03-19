#include "global.h"
#include "main.h"

//One known callsite is 080145D2 during the rayquaza bonus stage
s16 CollisionCheck_Rayquaza(struct Vector16 *arg0, u16 *arg1)
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

    CheckRayquazaEntityCollision(arg0, &sp00, &sp02);
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

    ProcessRayquazaCollisionEvent(some_enum, &return_val, arg1);
    return return_val;
}

void CheckRayquazaEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u16 lowerNibble;

    if (gCurrentPinballGame->boardEntityCollisionMode != 1)
        return;
    if (*arg2 & 0xF)
        return;

    deltaX = arg0->x - gCurrentPinballGame->bossCollisionX;
    deltaY = arg0->y - gCurrentPinballGame->bossCollisionY;

    if ((deltaX < 0 || deltaX >= 0x80) || (deltaY < 0 || deltaY >= 0x80))
        return;

    maskedResult = gRayquazaBodyCollisionMap[(deltaY * 0x80) + deltaX] & 0xFFF0;
    lowerNibble = gRayquazaBodyCollisionMap[(deltaY * 0x80) + deltaX] & 0xF;

    if (lowerNibble == 0)
        return;

    gCurrentPinballGame->bossHitFlashTimer = 9;
    *arg1 = maskedResult;
    *arg2 = lowerNibble;
}

void ProcessRayquazaCollisionEvent(u8 arg0, u16 *arg1, u16 *arg2)
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
