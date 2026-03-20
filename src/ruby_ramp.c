#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gRubyRampGateTileGfx[][0x300];
extern const u8 gRubyBoardRampPrize_Gfx[][0x80];


void UpdateRubyRampPrizeGate(void)
{
    s16 i;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    int x, y;
    int squaredMagnitude;
    s16 index;

    index = 0;
    switch (gCurrentPinballGame->rampGateState)
    {
    case 0:
        index = (gCurrentPinballGame->rampGateAnimCounter % 36) / 18;
        gCurrentPinballGame->rampGateAnimCounter++;
        gCurrentPinballGame->rampGateHitFlag = 0;
        break;
    case 1:
        index = (gCurrentPinballGame->rampGateAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->rampGateAnimCounter++;
        if (gCurrentPinballGame->rampGateHitFlag)
        {
            gCurrentPinballGame->rampGateState = 2;
            gCurrentPinballGame->rampGateAnimCounter = 0;
        }
        gCurrentPinballGame->rampGateHitFlag = 0;
        break;
    case 2:
        index = (gCurrentPinballGame->rampGateAnimCounter % 9) / 3 + 4;
        gCurrentPinballGame->rampGateAnimCounter++;
        if (gCurrentPinballGame->rampGateAnimCounter == 9)
        {
             gCurrentPinballGame->rampGateState = 3;
            gCurrentPinballGame->rampGateAnimCounter = 0;
        }
        break;
    case 3:
        index = (gCurrentPinballGame->rampGateAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->rampGateAnimCounter++;
        if (gCurrentPinballGame->rampGateAnimCounter > 65)
        {
            gCurrentPinballGame->rampGateState = 1;
            gCurrentPinballGame->rampGateAnimCounter = 0;
        }

        if (gCurrentPinballGame->rampGateAnimCounter > 6 && gCurrentPinballGame->rampGateHitFlag)
        {
            gCurrentPinballGame->rampGateState = 4;
            gCurrentPinballGame->rampGateAnimCounter = 0;
            gCurrentPinballGame->rampGateHitFlag = 0;
        }
        break;
    case 4:
        index = (gCurrentPinballGame->rampGateAnimCounter % 9) / 3 + 7;
        gCurrentPinballGame->rampGateAnimCounter++;
        if (gCurrentPinballGame->rampGateAnimCounter == 9)
        {
            gCurrentPinballGame->rampGateState = 5;
            gCurrentPinballGame->rampGateAnimCounter = 0;
        }
        break;
    case 5:
        index = (gCurrentPinballGame->rampGateAnimCounter % 36) / 18 + 2;
        gCurrentPinballGame->rampGateAnimCounter++;
        if (gCurrentPinballGame->rampGateAnimCounter > 65)
        {
            gCurrentPinballGame->rampGateState = 1;
            gCurrentPinballGame->rampGateAnimCounter = 0;
        }

        if (gCurrentPinballGame->rampGateAnimCounter > 6 && gCurrentPinballGame->rampGateHitFlag)
        {
            gCurrentPinballGame->rampGateState = 2;
            gCurrentPinballGame->rampGateAnimCounter = 0;
            gCurrentPinballGame->rampGateHitFlag = 0;
        }
        break;
    }

    group = &gMain.spriteGroups[68];
    if (group->available)
    {
        if (gCurrentPinballGame->rampGateState < 3)
        {
            group->baseX = 188 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 281 - gCurrentPinballGame->cameraYOffset;
        }
        else
        {
            group->baseX = 192 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 278 - gCurrentPinballGame->cameraYOffset;
        }

        if (gCurrentPinballGame->rampPrizeVisibilityTimer > 0)
        {
            gCurrentPinballGame->rampPrizeVisibilityTimer--;
            if (gCurrentPinballGame->rampPrizeVisibilityTimer == 0)
                gMain.spriteGroups[68].available = 0;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->rampGateState == 4 || gCurrentPinballGame->rampGateState == 2)
    {
        x = gCurrentPinballGame->ball->positionQ0.x - 190;
        y = gCurrentPinballGame->ball->positionQ0.y - 285;
        squaredMagnitude = (x * x) + (y * y);
        if(squaredMagnitude >= 0 && squaredMagnitude <= 140)
        {
            if (gCurrentPinballGame->rampPrizeVisibilityTimer <= 0)
            {
                m4aSongNumStart(SE_UNKNOWN_0xC5);
                gCurrentPinballGame->scoreAddedInFrame = 10000;
                gCurrentPinballGame->ball->velocity.x = -600;
                gCurrentPinballGame->ball->velocity.y = -300;
                gCurrentPinballGame->ball->spinSpeed = 0;
                gMain.spriteGroups[68].available = 1;
                gCurrentPinballGame->rampPrizeVisibilityTimer = 6;
                PlayRumble(8);
            }
        }
    }

    group = &gMain.spriteGroups[58];
    if (group->available)
    {
        group->baseX = 184 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 277 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gRubyRampGateTileGfx[index], (void*) 0x06013580, 0x300);
        for (i = 0; i < 3;i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void DrawRubyNuzleafPlatformSprite(void)
{
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    s16 index;

    group = &gMain.spriteGroups[66];
    if (group->available)
    {
        if (gCurrentPinballGame->rampPrizeType)
            group->baseY = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8 - (gCurrentPinballGame->cameraYOffset - 52);
        else
            group->baseY = 180;

        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->rampPrizeType == 1)
            index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8 + 4;
        else
            index = (gCurrentPinballGame->globalAnimFrameCounter % 32) / 8;

        DmaCopy16(3, gRubyBoardRampPrize_Gfx[index], (void *) 0x06014B00, 0x80);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}