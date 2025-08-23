#include "global.h"
#include "m4a.h"
#include "main.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gUnknown_081C0064[];
extern const u8 *gUnknown_086AD474[];
extern const u8 gUnknown_0815C4C4[][0x20];
extern const s16 gUnknown_086AE0E6[];
extern const u16 gUnknown_086B4202[][15];
extern const u8 *gUnknown_086AD49C[];

extern struct SongHeader gUnknown_0869F58C;
extern struct SongHeader gUnknown_0869F5C8;
extern struct SongHeader gUnknown_0869F618;

void sub_278F4(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    index = (gMain.systemFrameCount % 75) / 3;
    group = gMain.unk44[32];
    if (gCurrentPinballGame->unk26E)
    {
        group = gMain.unk44[40];
        if (gCurrentPinballGame->unk26E == 80)
        {
            gCurrentPinballGame->unkE4 = 15;
            DmaCopy16(3, gUnknown_086AD474[gCurrentPinballGame->unk25F], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, &gUnknown_0815C4C4[gCurrentPinballGame->unk25F], (void *)0x050003E0, 0x20);
            gCurrentPinballGame->unk626 = 0;
            gCurrentPinballGame->unk628 = 0;
        }

        if (gCurrentPinballGame->unk26E == 60)
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F58C);

        if (gUnknown_086AE0E6[gCurrentPinballGame->unk626] > gCurrentPinballGame->unk628)
        {
            gCurrentPinballGame->unk628++;
        }
        else
        {
            gCurrentPinballGame->unk628 = 1;
            gCurrentPinballGame->unk626++;
            if (gCurrentPinballGame->unk626 == 29)
            {
                gCurrentPinballGame->unk626 = 28;
                gCurrentPinballGame->unk26E = 1;
                gMain.unk44[40]->available = 0;
                gMain.unk44[32]->available = 1;
                MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F5C8);
                gCurrentPinballGame->unkE4 = 0;
            }
        }

        group->baseX = gCurrentPinballGame->unk258 - gCurrentPinballGame->unk58 + 8;
        group->baseY = gCurrentPinballGame->unk25A - gCurrentPinballGame->unk5A + 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 0];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 1];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->unk626][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        gCurrentPinballGame->unk26E--;
    }
    else
    {
        tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->unk258 + 8);
        tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->unk25A + 8);
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (squaredMagnitude < 82 &&
            ((gCurrentPinballGame->unk24 == 0 && gCurrentPinballGame->unk25E <= 5) || (gCurrentPinballGame->unk24 == 2 && gCurrentPinballGame->unk25E > 5)) &&
            gCurrentPinballGame->unk26B < 3)
        {    
            gCurrentPinballGame->unk3C = 10000;
            MPlayStart(&gMPlayInfo_SE1, &gUnknown_0869F618);
            gCurrentPinballGame->unk17 = 1;
            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk26B] = 5;
            gCurrentPinballGame->unk26B++;
            gMain.unk44[32]->available = 0;
            if (gCurrentPinballGame->unk26B == 3)
            {
                gCurrentPinballGame->unk26B = 0;
                gCurrentPinballGame->unk17 = 3;
            }
        }

        group->baseX = gCurrentPinballGame->unk258 - gCurrentPinballGame->unk58 - 8;
        group->baseY = gCurrentPinballGame->unk25A - gCurrentPinballGame->unk5A - 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        if (index > 14)
            index = 14;

        DmaCopy16(3, gUnknown_086AD49C[gCurrentPinballGame->unk25F] + index * 0x200, (void *)0x060116C0, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void sub_27D44(void)
{
    s16 i;

    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gMain.unk44[18]->available = 0;
    gMain.unk44[12]->available = 0;
    gCurrentPinballGame->unk5F2 = 0;
    sub_1C7F4(0, 0);
    gCurrentPinballGame->unk6C4 = 0;
    sub_4D648();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->unk6D3[i] = 13;

    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->unk723)
            gCurrentPinballGame->unk71D[i] = 1;
        else
            gCurrentPinballGame->unk71D[i] = 0;
    }
}

void sub_27E08(void)
{
    s16 i, j;

    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5AA = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gCurrentPinballGame->unk6C6 = 0;
    gCurrentPinballGame->unk6C7 = 0;
    gCurrentPinballGame->unk625 = 0;
    gCurrentPinballGame->unk6CA = 0;
    gCurrentPinballGame->unk6CC = 0;
    gCurrentPinballGame->unk72F = 0;
    gCurrentPinballGame->unk731 = 0;

    if (gCurrentPinballGame->unk29A == 0)
    {
        gCurrentPinballGame->unk724 = 6000;
    }
    else
    {
        gCurrentPinballGame->unk724 = 4200;
    }
    gCurrentPinballGame->unk29A += 1;

    DmaCopy16(3, gUnknown_081C0064, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->unk6CD[i] = i;
    }

    gCurrentPinballGame->unk6C8 = gMain.systemFrameCount % 6;
    gCurrentPinballGame->unk6C9 = 5;

    for (j = gCurrentPinballGame->unk6C8; j < gCurrentPinballGame->unk6C9; j++)
    {
        gCurrentPinballGame->unk6CD[j] = gCurrentPinballGame->unk6CD[j+1];
    }
}
