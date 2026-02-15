#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_0847DF0C[][0x300];
extern const u8 gRubyBoardRampPrize_Gfx[][0x80];


void sub_2C538(void)
{
    s16 i;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    int x, y;
    int squaredMagnitude;
    s16 index;

    index = 0;
    switch (gCurrentPinballGame->unk300)
    {
    case 0:
        index = (gCurrentPinballGame->unk304 % 36) / 18;
        gCurrentPinballGame->unk304++;
        gCurrentPinballGame->unk301 = 0;
        break;
    case 1:
        index = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk301)
        {
            gCurrentPinballGame->unk300 = 2;
            gCurrentPinballGame->unk304 = 0;
        }
        gCurrentPinballGame->unk301 = 0;
        break;
    case 2:
        index = (gCurrentPinballGame->unk304 % 9) / 3 + 4;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 == 9)
        {
             gCurrentPinballGame->unk300 = 3;
            gCurrentPinballGame->unk304 = 0;
        }
        break;
    case 3:
        index = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 > 65)
        {
            gCurrentPinballGame->unk300 = 1;
            gCurrentPinballGame->unk304 = 0;
        }

        if (gCurrentPinballGame->unk304 > 6 && gCurrentPinballGame->unk301)
        {
            gCurrentPinballGame->unk300 = 4;
            gCurrentPinballGame->unk304 = 0;
            gCurrentPinballGame->unk301 = 0;
        }
        break;
    case 4:
        index = (gCurrentPinballGame->unk304 % 9) / 3 + 7;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 == 9)
        {
            gCurrentPinballGame->unk300 = 5;
            gCurrentPinballGame->unk304 = 0;
        }
        break;
    case 5:
        index = (gCurrentPinballGame->unk304 % 36) / 18 + 2;
        gCurrentPinballGame->unk304++;
        if (gCurrentPinballGame->unk304 > 65)
        {
            gCurrentPinballGame->unk300 = 1;
            gCurrentPinballGame->unk304 = 0;
        }

        if (gCurrentPinballGame->unk304 > 6 && gCurrentPinballGame->unk301)
        {
            gCurrentPinballGame->unk300 = 2;
            gCurrentPinballGame->unk304 = 0;
            gCurrentPinballGame->unk301 = 0;
        }
        break;
    }

    group = &gMain.spriteGroups[68];
    if (group->available)
    {
        if (gCurrentPinballGame->unk300 < 3)
        {
            group->baseX = 188 - gCurrentPinballGame->unk58;
            group->baseY = 281 - gCurrentPinballGame->unk5A;
        }
        else
        {
            group->baseX = 192 - gCurrentPinballGame->unk58;
            group->baseY = 278 - gCurrentPinballGame->unk5A;
        }

        if (gCurrentPinballGame->unk302 > 0)
        {
            gCurrentPinballGame->unk302--;
            if (gCurrentPinballGame->unk302 == 0)
                gMain.spriteGroups[68].available = 0;
        }

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->unk300 == 4 || gCurrentPinballGame->unk300 == 2)
    {
        x = gCurrentPinballGame->ball->positionQ0.x - 190;
        y = gCurrentPinballGame->ball->positionQ0.y - 285;
        squaredMagnitude = (x * x) + (y * y);
        if(squaredMagnitude >= 0 && squaredMagnitude <= 140)
        {
            if (gCurrentPinballGame->unk302 <= 0)
            {
                m4aSongNumStart(SE_UNKNOWN_0xC5);
                gCurrentPinballGame->scoreAddedInFrame = 10000;
                gCurrentPinballGame->ball->velocity.x = -600;
                gCurrentPinballGame->ball->velocity.y = -300;
                gCurrentPinballGame->ball->unk6 = 0;
                gMain.spriteGroups[68].available = 1;
                gCurrentPinballGame->unk302 = 6;
                sub_11B0(8);
            }
        }
    }

    group = &gMain.spriteGroups[58];
    if (group->available)
    {
        group->baseX = 184 - gCurrentPinballGame->unk58;
        group->baseY = 277 - gCurrentPinballGame->unk5A;
        DmaCopy16(3, gUnknown_0847DF0C[index], (void*) 0x06013580, 0x300);
        for (i = 0; i < 3;i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void sub_2C9A4(void)
{
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *group;
    s16 index;

    group = &gMain.spriteGroups[66];
    if (group->available)
    {
        if (gCurrentPinballGame->unk29F)
            group->baseY = (gCurrentPinballGame->unk290 % 32) / 8 - (gCurrentPinballGame->unk5A - 52);
        else
            group->baseY = 180;

        group->baseX = 120 - gCurrentPinballGame->unk58;
        if (gCurrentPinballGame->unk29F == 1)
            index = (gCurrentPinballGame->unk290 % 32) / 8 + 4;
        else
            index = (gCurrentPinballGame->unk290 % 32) / 8;

        DmaCopy16(3, gRubyBoardRampPrize_Gfx[index], (void *) 0x06014B00, 0x80);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x =  oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y =  oamSimple->yOffset + group->baseY;
    }
}