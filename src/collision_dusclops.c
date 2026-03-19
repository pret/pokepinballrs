#include "global.h"
#include "main.h"
#include "constants/dusclops_states.h"

s16 CollisionCheck_Dusclops(struct Vector16* arg0, u16* arg1) {
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
    collisionTileIndex = gBoardConfig.fieldLayout.collisionTileMap[boardLayer + tileMapPage][vec1.y * 64 + vec1.x];
    sp00 = gBoardConfig.fieldLayout.collisionAngleMap[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];
    sp02 = gBoardConfig.fieldLayout.collisionTypeMap[boardLayer + tileMapPage][collisionTileIndex * 64 + vec2.y * 8 + vec2.x];

    CheckDusclopsEntitiesCollision(arg0, &sp00, &sp02);
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

    CheckDusclopsAbsorbZoneHit(some_enum, &return_val, arg1);
    return return_val;
}

void CheckDusclopsEntitiesCollision(struct Vector16 *arg0, s16* arg1, u8* arg2) {
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    u8 temp;

    maskedResult = 0;
    lowerNibble = 0;

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS)
    {
        if (*arg2 != 0)
            return;

        deltaX = arg0->x -gCurrentPinballGame->bossCollisionX;
        deltaY = arg0->y -gCurrentPinballGame->bossCollisionY;

        if (deltaX > 95U || deltaY > 119U)
            return;

        maskedResult = 0xFFF0 & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];
        lowerNibble = 0xF & gDusclopsBodyCollisionMap[(deltaY * 96 ) + deltaX];

        if (lowerNibble == 0)
            return;

        //Can be hit when ready to absorb (2) or when walking (3)
        temp = gCurrentPinballGame->bossEntityState -3;
        if (temp <= 1U)
            *arg2 = 1;
        else
            *arg2 = lowerNibble;

        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT;
        *arg1 = maskedResult;

        return;
    }

    if(gCurrentPinballGame->boardEntityCollisionMode == DUSCLOPS_ENTITY_COLLISION_MODE_DUSKULL)
    {
        if (*arg2 != 0)
            return;

        if (gCurrentPinballGame->minionCanCollide[0] )
        {
            deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[0].x;
            deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[0].y;

            if (deltaX < 64U && deltaY < 64U)
            {
                maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                if (lowerNibble != 0)
                    gCurrentPinballGame->minionState[0] = DUSKULL_ENTITY_STATE_HIT;
            }
        }

        if (lowerNibble == 0)
        {
            if (gCurrentPinballGame->minionCanCollide[1] )
            {
                deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[1].x;
                deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[1].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                        gCurrentPinballGame->minionState[1] = DUSKULL_ENTITY_STATE_HIT;
                }
            }
        }

        if (lowerNibble == 0)
        {
            if ( gCurrentPinballGame->minionCanCollide[2] )
            {
                deltaX = arg0->x - gCurrentPinballGame->minionCollisionPosition[2].x;
                deltaY = arg0->y - gCurrentPinballGame->minionCollisionPosition[2].y;

                if (deltaX < 64U && deltaY < 64U)
                {
                    maskedResult = 0xFFF0 & gSharedBumperCollisionMap[deltaY * 64 + deltaX];
                    lowerNibble = 0xF & gSharedBumperCollisionMap[deltaY * 64 + deltaX];

                    if (lowerNibble != 0)
                    {
                        gCurrentPinballGame->minionState[2] = DUSKULL_ENTITY_STATE_HIT;
                    }
                }
            }
        }

        if (lowerNibble != 0)
        {
            *arg1 = maskedResult;
            *arg2 = 6;
        }
        return;
    }
}

void CheckDusclopsAbsorbZoneHit(u8 arg0, u16 *arg1, u16 *arg2)
{
    switch (arg0)
    {
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE;
        gCurrentPinballGame->ballFrozenState = 1;
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

