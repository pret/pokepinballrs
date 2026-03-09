#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_0847DF0C[][0x300];
extern const u8 gRubyBoardRampPrize_Gfx[][0x80];


void UpdateRubyRampGulpinEntity(void)
{
    s16 i;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    int x, y;
    int squaredMagnitude;
    s16 index;

    index = 0;
    switch (gCurrentPinballGame->rampPrizeAnimState)
    {
    case 0:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 36) / 18;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        gCurrentPinballGame->rampPrizeHitPending = 0;
        break;
    case 1:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 36) / 18 + 2;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        if (gCurrentPinballGame->rampPrizeHitPending)
        {
            gCurrentPinballGame->rampPrizeAnimState = 2;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
        }
        gCurrentPinballGame->rampPrizeHitPending = 0;
        break;
    case 2:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 9) / 3 + 4;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        if (gCurrentPinballGame->rampPrizeAnimFrame == 9)
        {
             gCurrentPinballGame->rampPrizeAnimState = 3;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
        }
        break;
    case 3:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 36) / 18 + 2;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        if (gCurrentPinballGame->rampPrizeAnimFrame > 65)
        {
            gCurrentPinballGame->rampPrizeAnimState = 1;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
        }

        if (gCurrentPinballGame->rampPrizeAnimFrame > 6 && gCurrentPinballGame->rampPrizeHitPending)
        {
            gCurrentPinballGame->rampPrizeAnimState = 4;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
            gCurrentPinballGame->rampPrizeHitPending = 0;
        }
        break;
    case 4:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 9) / 3 + 7;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        if (gCurrentPinballGame->rampPrizeAnimFrame == 9)
        {
            gCurrentPinballGame->rampPrizeAnimState = 5;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
        }
        break;
    case 5:
        index = (gCurrentPinballGame->rampPrizeAnimFrame % 36) / 18 + 2;
        gCurrentPinballGame->rampPrizeAnimFrame++;
        if (gCurrentPinballGame->rampPrizeAnimFrame > 65)
        {
            gCurrentPinballGame->rampPrizeAnimState = 1;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
        }

        if (gCurrentPinballGame->rampPrizeAnimFrame > 6 && gCurrentPinballGame->rampPrizeHitPending)
        {
            gCurrentPinballGame->rampPrizeAnimState = 2;
            gCurrentPinballGame->rampPrizeAnimFrame = 0;
            gCurrentPinballGame->rampPrizeHitPending = 0;
        }
        break;
    }

    group = &gMain.spriteGroups[68];
    if (group->available)
    {
        if (gCurrentPinballGame->rampPrizeAnimState < 3)
        {
            group->baseX = 188 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 281 - gCurrentPinballGame->bgScrollYWithOffset;
        }
        else
        {
            group->baseX = 192 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 278 - gCurrentPinballGame->bgScrollYWithOffset;
        }

        if (gCurrentPinballGame->rampPrizeHitCooldown > 0)
        {
            gCurrentPinballGame->rampPrizeHitCooldown--;
            if (gCurrentPinballGame->rampPrizeHitCooldown == 0)
                gMain.spriteGroups[68].available = 0;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->rampPrizeAnimState == 4 || gCurrentPinballGame->rampPrizeAnimState == 2)
    {
        x = gCurrentPinballGame->ball->positionQ0.x - 190;
        y = gCurrentPinballGame->ball->positionQ0.y - 285;
        squaredMagnitude = (x * x) + (y * y);
        if(squaredMagnitude >= 0 && squaredMagnitude <= 140)
        {
            if (gCurrentPinballGame->rampPrizeHitCooldown <= 0)
            {
                m4aSongNumStart(SE_UNKNOWN_0xC5);
                gCurrentPinballGame->scoreAddedInFrame = 10000;
                gCurrentPinballGame->ball->velocity.x = -600;
                gCurrentPinballGame->ball->velocity.y = -300;
                gCurrentPinballGame->ball->spin = 0;
                gMain.spriteGroups[68].available = 1;
                gCurrentPinballGame->rampPrizeHitCooldown = 6;
                PlayRumble(8);
            }
        }
    }

    group = &gMain.spriteGroups[58];
    if (group->available)
    {
        group->baseX = 184 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 277 - gCurrentPinballGame->bgScrollYWithOffset;
        DmaCopy16(3, gUnknown_0847DF0C[index], (void*) 0x06013580, 0x300);
        for (i = 0; i < 3;i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void DrawRubyRampPrizeIndicator(void)
{
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    s16 index;

    group = &gMain.spriteGroups[66];
    if (group->available)
    {
        if (gCurrentPinballGame->rampPrizeType)
            group->baseY = (gCurrentPinballGame->gameFrameCount % 32) / 8 - (gCurrentPinballGame->bgScrollYWithOffset - 52);
        else
            group->baseY = 180;

        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        if (gCurrentPinballGame->rampPrizeType == 1)
            index = (gCurrentPinballGame->gameFrameCount % 32) / 8 + 4;
        else
            index = (gCurrentPinballGame->gameFrameCount % 32) / 8;

        DmaCopy16(3, gRubyBoardRampPrize_Gfx[index], (void *) 0x06014B00, 0x80);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}