#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gUnknown_086B0B70[][3];
extern const u16 gUnknown_086B0E20[];
extern const u8 *gUnknown_086B0B94[][4];
extern const u8 *gUnknown_086B0B20[][4];
extern const u8 *gUnknown_086B0AF0[][4];
extern const u8 *gUnknown_086B0AC0[][4];
extern const u8 *gUnknown_086B0A90[][4];
extern const u8 *gUnknown_086B0BC4[][4];
extern const u8 *gUnknown_086B09E8[][7][2];
extern const u8 *gUnknown_086B09C8[][2];
extern const u8 *gUnknown_086B0970[][2];
extern const u8 *gUnknown_086B094C[][3];
extern const s16 gUnknown_086B08CA[];
extern const u8 *gUnknown_086B08D4[][3][5];

extern struct SongHeader se_unk_87;


void sub_4E814(void)
{
    gCurrentPinballGame->unk734 = (gCurrentPinballGame->unk70C % 40) / 20;
    gCurrentPinballGame->unk70C++;
    sub_4EA44();
    if (gCurrentPinballGame->unk6A < 232)
    {
        sub_4EDC0();
        sub_4EE74();
    }

    if (gCurrentPinballGame->unk6A >= 81 && gCurrentPinballGame->unk6A < 248)
        sub_4EF38();

    sub_4F0F0();
    if (gCurrentPinballGame->unk6A < 112)
        sub_4F258();

    if (gCurrentPinballGame->unk6A > 112)
        sub_4F028();

    if (gCurrentPinballGame->unk6A > 104)
    {
        sub_4F4B4();
        sub_4F660();
    }

    if (gCurrentPinballGame->unk6A < 256)
        sub_4F30C();

    sub_4F2B8();
    if (gCurrentPinballGame->unk6A > 110)
        sub_4EAB0();

    if (gCurrentPinballGame->unk6A > 178)
    {
        sub_4EAF8();
        sub_4EBD0();
        sub_4E920();
    }

    if (gCurrentPinballGame->unk6A > 202)
        sub_4ECDC();

    if (gCurrentPinballGame->unk724 && gCurrentPinballGame->unk25 == 0)
        gCurrentPinballGame->unk724--;
}

void sub_4E920(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = gUnknown_086B08CA[gCurrentPinballGame->unk716];
    if (gCurrentPinballGame->unk716)
    {
        gCurrentPinballGame->unk716--;
        if (gCurrentPinballGame->unk716 == 3)
        {
            m4aSongNumStart(SE_SLINGSHOT_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 500;
            sub_11B0(7);
        }
    }

    src = gUnknown_086B08D4[gCurrentPinballGame->unk717][index];
    dest = gUnknown_086B08D4[gCurrentPinballGame->unk717][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void sub_4E9F0(s16 arg0)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B094C[arg0];
    dest = gUnknown_086B094C[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    DmaCopy16(3, src[2], dest[2], 0x20);
}

void sub_4EA44(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->unk70E / 10;
    var1 = gCurrentPinballGame->unk70E % 10;
    src = gUnknown_086B0970[var0];
    dest = gUnknown_086B0970[10];
    DmaCopy16(3, src[0], dest[0], 0x20);

    src = gUnknown_086B0970[var1];
    DmaCopy16(3, src[1], dest[1], 0x20);
}

void sub_4EAB0(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B09C8[gCurrentPinballGame->unk730];
    dest = gUnknown_086B09C8[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

void sub_4EAF8(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk720)
    {
        gCurrentPinballGame->unk71D[gCurrentPinballGame->unk721] = 1 - (gCurrentPinballGame->unk720 % 36) / 18;
        gCurrentPinballGame->unk71D[gCurrentPinballGame->unk722] = gCurrentPinballGame->unk71D[gCurrentPinballGame->unk721];
        gCurrentPinballGame->unk720--;
    }

    for (i = 0; i < 3; i++)
    {
        src = gUnknown_086B09E8[i][gCurrentPinballGame->unk71D[i]];
        dest = gUnknown_086B09E8[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void sub_4EBD0(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk714)
    {
        if (gCurrentPinballGame->unk715)
        {
            gCurrentPinballGame->holeIndicators[0] = (gCurrentPinballGame->unk715 % 36) / 18;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->unk715--;
        }
        else
        {
            gCurrentPinballGame->holeIndicators[0] = 1;
            gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
            gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        }
    }

    for (i = 0; i < 4; i++)
    {
        src = &gUnknown_086B0BC4[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gUnknown_086B0BC4[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void sub_4ECDC(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk724 > 300)
    {
        gCurrentPinballGame->unk726 = 1;
    }
    else
    {
        if (gCurrentPinballGame->unk724)
        {
            if (gCurrentPinballGame->unk25)
                gCurrentPinballGame->unk726 = 1;
            else
                gCurrentPinballGame->unk726 = (gMain.fieldFrameCount % 16) / 8;
        }
        else
        {
            gCurrentPinballGame->unk726 = 0;
        }
    }

    src = gUnknown_086B0A90[gCurrentPinballGame->unk726];
    dest = gUnknown_086B0A90[2];
    DmaCopy16(3, src[0], dest[0], 0xC0);
    DmaCopy16(3, src[1], dest[1], 0xC0);
    if (gCurrentPinballGame->unk6A >= 216)
    {
        DmaCopy16(3, src[2], dest[2], 0xA0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void sub_4EDC0(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk728 > 0)
        index = 1 - gCurrentPinballGame->unk734;

    src = gUnknown_086B0AC0[index];
    dest = gUnknown_086B0AC0[2];
    if (gCurrentPinballGame->unk6A > 48)
    {
        if (gCurrentPinballGame->unk6A < 216)
        {
            DmaCopy16(3, src[0], dest[0], 0x80);
        }

        if (gCurrentPinballGame->unk6A < 224)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }
    if (gCurrentPinballGame->unk6A > 64)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void sub_4EE74(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk729 > 0)
        index = 1 - gCurrentPinballGame->unk734;

    src = gUnknown_086B0AF0[index];
    dest = gUnknown_086B0AF0[2];
    if (gCurrentPinballGame->unk6A > 40)
    {
        if (gCurrentPinballGame->unk6A < 208)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        if (gCurrentPinballGame->unk6A < 216)
        {
            DmaCopy16(3, src[1], dest[1], 0x80);
        }
    }

    if (gCurrentPinballGame->unk6A > 56)
    {
        if (gCurrentPinballGame->unk6A < 224)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void sub_4EF38(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk2F0 > 2)
        gCurrentPinballGame->unk72A = 1;
    else if (gCurrentPinballGame->unk13)
        gCurrentPinballGame->unk72A = 0;

    if (gCurrentPinballGame->unk72A > 0)
        index = gCurrentPinballGame->unk1A5 * 2 + 1 - gCurrentPinballGame->unk734;
    else
        index = gCurrentPinballGame->unk1A5 * 2;

    src = gUnknown_086B0B20[index];
    dest = gUnknown_086B0B20[4];
    if (gCurrentPinballGame->unk6A < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0xA0);
    }

    DmaCopy16(3, src[1], dest[1], 0xA0);
    DmaCopy16(3, src[2], dest[2], 0xA0);
    if (gCurrentPinballGame->unk6A > 88)
    {
        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void sub_4F028(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    gCurrentPinballGame->unk731 = 0;
    if (gCurrentPinballGame->unk72F > 1 && gCurrentPinballGame->unk13 < 3)
        gCurrentPinballGame->unk731 = 1;

    if (gCurrentPinballGame->unk731 > 0)
        index = 1 - gCurrentPinballGame->unk734;

    src = gUnknown_086B0B94[index];
    dest = gUnknown_086B0B94[2];
    if (gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }
    DmaCopy16(3, src[1], dest[1], 0x80);
    DmaCopy16(3, src[2], dest[2], 0x80);
    DmaCopy16(3, src[3], dest[3], 0x80);
}

void sub_4F0F0(void)
{
    if (gCurrentPinballGame->unk71B == 0)
        return;

    if (gCurrentPinballGame->unk71C)
    {
        if (gCurrentPinballGame->unk2F8 == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] = (gMain.fieldFrameCount % 20) / 10;
            gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
            gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[0];
        }

        if (gCurrentPinballGame->unk71C == 28)
        {
            if (gCurrentPinballGame->ballUpgradeType < BALL_UPGRADE_TYPE_MASTER_BALL)
                gCurrentPinballGame->ballUpgradeType++;

            gCurrentPinballGame->ballUpgradeCounter = 3600;
            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
        }

        if (gCurrentPinballGame->unk71C == 40)
        MPlayStart(&gMPlayInfo_SE1, &se_unk_87);

        if (gCurrentPinballGame->unk71C == 60)
            gMain.unk44[43]->available = 1;

        gCurrentPinballGame->unk6E = gUnknown_086B0E20[30 - gCurrentPinballGame->unk71C / 2];
        gCurrentPinballGame->unk71C--;
    }
    else
    {
        gCurrentPinballGame->unk71B = 0;
        if (gCurrentPinballGame->unk2F8 == 0)
        {
            gCurrentPinballGame->ballPowerUpLight[0] =
                gCurrentPinballGame->ballPowerUpLight[1] =
                gCurrentPinballGame->ballPowerUpLight[2] = 0;
        }

        gCurrentPinballGame->unk2F8 = 0;
    }
}

void sub_4F258(void)
{
    s16 i;
    const u8 **src;
    const u8 **dest;

    for (i = 0; i < 3; i++) {
        src = &gUnknown_086B0B70[i][gCurrentPinballGame->ballPowerUpLight[i]];
        dest = &gUnknown_086B0B70[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}
