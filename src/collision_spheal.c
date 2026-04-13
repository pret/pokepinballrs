#include "global.h"
#include "main.h"

s16 CollisionCheck_Spheal(struct Vector16 *arg0, u16 *arg1)
{
    u16 sp0;
    u8 sp2;
    u16 sp4_return;

    struct Vector16 div_result;
    struct Vector16 div_remainder;
    s32 tileMapPage;
    s32 boardLayer;
    s16 collisionTileIndex;
    u8 enum1, enum2;

    sp4_return = 0;
    gCurrentPinballGame->ball->spinAcceleration = 0;

    div_result.x = arg0->x / 8;
    div_result.y = arg0->y / 8;
    div_remainder.x = arg0->x % 8;
    div_remainder.y = arg0->y % 8;
    tileMapPage = div_result.y / 64;
    boardLayer = gCurrentPinballGame->boardLayerDepth;
    div_result.y %= 64;

    collisionTileIndex = gBoardConfig.fieldLayout.collision.tileData[boardLayer + tileMapPage][div_result.y * 64 + div_result.x];
    sp0 = gBoardConfig.fieldLayout.collision.angleData[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];
    sp2 = gBoardConfig.fieldLayout.collision.typeData[boardLayer + tileMapPage][collisionTileIndex * 64 + div_remainder.y * 8 + div_remainder.x];

    CheckSphealEntityCollision(arg0, &sp0, &sp2);

    enum1 = sp2 & 0xF;
    enum2 = sp2 >> 4;
    switch (enum1)
    {
    case 1:
    case 4:
    case 6:
        gCurrentPinballGame->collisionSurfaceType = enum1 - 1;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp0;
        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < (gBoardConfig.fieldLayout.ballSpawnX - 8) ||
                gCurrentPinballGame->ball->positionQ0.y < (gBoardConfig.fieldLayout.ballSpawnY - 8))
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
        sp4_return = 1;
        break;
    case 2:
    case 3:
        gCurrentPinballGame->collisionSurfaceType = 0;
        gCurrentPinballGame->collisionResponseType = 1;
        *arg1 = sp0 & 0x0000FFF0;

        if (gCurrentPinballGame->ball->positionQ0.x < 120)
            gCurrentPinballGame->minionHitFlashTimer[0] = 24;
        else
            gCurrentPinballGame->minionHitFlashTimer[1] = 24;

        sp4_return = 1;
        break;
    case 5:
        enum2 = 4;
        break;
    }

    ProcessSphealCollisionEvent(enum2, &sp4_return, arg1);
    return sp4_return;
}

void CheckSphealEntityCollision(struct Vector16 *arg0, u16 *arg1, u8 *arg2)
{
    s16 i;
    s16 deltaX, deltaY;
    u16 lowerReadFromRom;
    u16 upperReadFromRom;
    for (i = 0; i < 2; i++)
    {

        if (gCurrentPinballGame->flyingEnemyCollisionType[i] == 1)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->flyingEnemyCollisionPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->flyingEnemyCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gSphealFrozenIceCollisionMap[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            if (gCurrentPinballGame->ballRespawnState != 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            gCurrentPinballGame->flyingEnemyState[i] = 4;
        }
        else if (gCurrentPinballGame->flyingEnemyCollisionType[i] != 0)
        {
            if ((arg2[0] & 0xf) != 0)
                continue;

            deltaX = arg0->x - gCurrentPinballGame->flyingEnemyCollisionPos[i].x;
            deltaY = arg0->y - gCurrentPinballGame->flyingEnemyCollisionPos[i].y;
            if ((deltaX >= 64 || deltaX < 0) || (deltaY >= 64 || deltaY < 0))
                continue;

            upperReadFromRom = gSphealCrackedIceCollisionMap[(deltaY * 64) + deltaX] & 0xFFF0;
            lowerReadFromRom = gSphealCrackedIceCollisionMap[(deltaY * 64) + deltaX] & 0xF;
            if (lowerReadFromRom == 0)
                continue;

            arg1[0] = upperReadFromRom;
            arg2[0] = lowerReadFromRom;
            arg2[0] = 6;
            if (gCurrentPinballGame->flyingEnemyCollisionType[i] == 2)
            {
                gCurrentPinballGame->flyingEnemyState[i] = 4;
            }
            else
            {
                gCurrentPinballGame->flyingEnemyHitCooldown[i] = 24;
            }
        }
    }
}

void ProcessSphealCollisionEvent(u8 arg0_enum, u16 *arg1, u16 *arg2)
{
    switch (arg0_enum)
    {
    case 2:
        gCurrentPinballGame->knockdownTargetIndex[2] = 0;
        gCurrentPinballGame->knockdownPhase[2] = 2;
        break;
    case 3:
        gCurrentPinballGame->knockdownTargetIndex[2] = 1;
        gCurrentPinballGame->knockdownPhase[2] = 2;
        break;
    case 8:
        gCurrentPinballGame->knockdownTargetIndex[2] = 0;
        gCurrentPinballGame->knockdownPhase[2] = 1;
        gCurrentPinballGame->knockdownStunTimer[2] = 100;
        break;
    case 9:
        gCurrentPinballGame->knockdownTargetIndex[2] = 1;
        gCurrentPinballGame->knockdownPhase[2] = 1;
        gCurrentPinballGame->knockdownStunTimer[2] = 100;
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