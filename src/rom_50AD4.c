#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gUnknown_086B0E6C[][2];
extern const u8 *gUnknown_086B0F9C[][3][2];
extern const u8 *gUnknown_086B12AC[][3];
extern const u8 *gUnknown_086B125C[][4];
extern const u8 *gUnknown_086B12D0[][4];
extern const u8 *gUnknown_086B14A8[][5][3];
extern const u8 *gUnknown_086B1340[][5][3];
extern const u8 *gUnknown_086B122C[][4];
extern const u8 *gUnknown_086B11FC[][4];
extern const u8 *gUnknown_086B13F4[][5][3];
extern const u8 *gUnknown_086B11CC[][4];
extern const u8 *gUnknown_086B1300[][4];
extern const u8 *gUnknown_086B1124[][7][2];
extern const u8 *gUnknown_086B0F4C[][4];
extern const u8 *gUnknown_086B1104[][2];
extern const u16 gUnknown_086B0E60[];
extern const u8 *gUnknown_086B108C[][3][5];
extern const u8 *gUnknown_086B0E9C[][4];
extern const u8 *gUnknown_086B0D6C[][5][3];
extern const u8 *gUnknown_086B0C04[][5][3];
extern const u8 *gUnknown_086B0CB8[][5][3];
extern const s16 gUnknown_086B08C4[];


void sub_4F2B8(void)
{
    if (gCurrentPinballGame->unk72B > 0)
    {
        if (gCurrentPinballGame->unk72C < gUnknown_086B08C4[gCurrentPinballGame->unk72B - 1])
        {
            gCurrentPinballGame->unk72C++;
        }
        else
        {
            gCurrentPinballGame->unk72C = 0;
            gCurrentPinballGame->unk72B--;
        }
    }
}

void sub_4F30C(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk72B == 0)
    {
        sp0[0] = gCurrentPinballGame->unk734 * 2;
        sp0[1] = gCurrentPinballGame->unk734;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->unk72B == 1)
    {
        sp0[0] = 3;
        sp0[1] = gCurrentPinballGame->unk734 + 1;
        sp0[2] = gCurrentPinballGame->unk734 * 2;
    }
    else if (gCurrentPinballGame->unk72B == 2)
    {
        sp0[0] = 3;
        sp0[1] = 3;
        sp0[2] = gCurrentPinballGame->unk734 + 2;
    }
    else
    {
        sp0[0] = 3;
        sp0[1] = 3;
        sp0[2] = 3;
    }

    src = gUnknown_086B0CB8[0][sp0[0]];
    dest = gUnknown_086B0CB8[0][4];
    if (gCurrentPinballGame->unk6A >= 42 && gCurrentPinballGame->unk6A < 208)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->unk6A >= 50 && gCurrentPinballGame->unk6A < 216)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gUnknown_086B0CB8[1][sp0[1]];
    dest = gUnknown_086B0CB8[1][4];
    if (gCurrentPinballGame->unk6A >= 58 && gCurrentPinballGame->unk6A < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->unk6A >= 66 && gCurrentPinballGame->unk6A < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    src = gUnknown_086B0CB8[2][sp0[2]];
    dest = gUnknown_086B0CB8[2][4];
    if (gCurrentPinballGame->unk6A >= 74 && gCurrentPinballGame->unk6A < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->unk6A >= 82 && gCurrentPinballGame->unk6A < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->unk6A >= 90)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void sub_4F4B4(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk72E == 0)
        {
            sp0[0] = gCurrentPinballGame->unk734 * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->unk72E == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->unk734 + 1;
            sp0[2] = gCurrentPinballGame->unk734 * 2;
        }
        else if (gCurrentPinballGame->unk72E == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = gCurrentPinballGame->unk734 + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->unk739[0];
        sp0[1] = gCurrentPinballGame->unk739[1];
        sp0[2] = gCurrentPinballGame->unk739[2];
    }

    src = gUnknown_086B0C04[0][sp0[0]];
    dest = gUnknown_086B0C04[0][4];
    if (gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->unk6A > 120)
    {
        src = gUnknown_086B0C04[1][sp0[1]];
        dest = gUnknown_086B0C04[1][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->unk6A > 136)
    {
        src = gUnknown_086B0C04[2][sp0[2]];
        dest = gUnknown_086B0C04[2][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void sub_4F660(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk72F == 0)
        {
            sp0[0] = gCurrentPinballGame->unk734 * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->unk72F == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->unk734 + 1;
            sp0[2] = gCurrentPinballGame->unk734 * 2;
        }
        else if (gCurrentPinballGame->unk72F == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = (s16) gCurrentPinballGame->unk734 + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->unk736[0];
        sp0[1] = gCurrentPinballGame->unk736[1];
        sp0[2] = gCurrentPinballGame->unk736[2];
    }

    src = gUnknown_086B0D6C[0][sp0[0]];
    dest = gUnknown_086B0D6C[0][4];
    if (gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->unk6A > 120)
    {
        src = gUnknown_086B0D6C[1][sp0[1]];
        dest = gUnknown_086B0D6C[1][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->unk6A > 136)
    {
        src = gUnknown_086B0D6C[2][sp0[2]];
        dest = gUnknown_086B0D6C[2][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }
}

void sub_4F814(void)
{

    gCurrentPinballGame->unk734 = (gCurrentPinballGame->unk70C % 40) / 20;
    gCurrentPinballGame->unk70C++;
    sub_50710();
    if (gCurrentPinballGame->unk6A > 83)
        sub_50000();

    if (gCurrentPinballGame->unk6A > 18)
        sub_500B4();

    if (gCurrentPinballGame->unk6A >= 56 && gCurrentPinballGame->unk6A < 243)
        sub_505A4();

    sub_4F0F0();
    if (gCurrentPinballGame->unk6A < 112)
        sub_506B0();

    if (gCurrentPinballGame->unk6A >= 64 && gCurrentPinballGame->unk6A < 254)
        sub_504C0();

    if (gCurrentPinballGame->unk6A >= 27 && gCurrentPinballGame->unk6A < 211)
    {
        sub_4FB08();
        sub_4F95C();
    }

    if (gCurrentPinballGame->unk6A > 104)
    {
        sub_50154();
        sub_5030C();
    }

    if (gCurrentPinballGame->unk6A > 72)
        sub_4FE6C();

    sub_4F2B8();
    if (gCurrentPinballGame->unk6A > 110)
        sub_4FAC0();

    if (gCurrentPinballGame->unk6A > 178)
    {
        sub_4FBA4();
        sub_4FC7C();
        sub_4F9F0();
    }

    if (gCurrentPinballGame->unk6A > 202)
        sub_4FD88();

    if (gCurrentPinballGame->unk6A >= 8 && gCurrentPinballGame->unk6A < 182)
        sub_507D4();

    if (gCurrentPinballGame->unk724 && gCurrentPinballGame->unk25 == 0)
        gCurrentPinballGame->unk724--;
}

void sub_4F95C(void)
{
    s16 var0, var1;
    const u8 **src;
    const u8 **dest;

    var0 = gCurrentPinballGame->unk70E / 10;
    var1 = gCurrentPinballGame->unk70E % 10;
    if (gCurrentPinballGame->unk6A > 36)
    {
        src = gUnknown_086B0E9C[var0];
        dest = gUnknown_086B0E9C[10];
        DmaCopy16(3, src[0], dest[0], 0x20);
        DmaCopy16(3, src[1], dest[1], 0x20);

        src = gUnknown_086B0E9C[var1];
        DmaCopy16(3, src[2], dest[2], 0x20);
        DmaCopy16(3, src[3], dest[3], 0x20);
    }
}

void sub_4F9F0(void)
{
    s16 var0;
    const u8 **src;
    const u8 **dest;

    var0 = gUnknown_086B0E60[gCurrentPinballGame->unk716];
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

    src = gUnknown_086B108C[gCurrentPinballGame->unk717][var0];
    dest = gUnknown_086B108C[gCurrentPinballGame->unk717][2];
    DmaCopy16(3, src[0], dest[0], 0x20);
    DmaCopy16(3, src[1], dest[1], 0x40);
    DmaCopy16(3, src[2], dest[2], 0x60);
    DmaCopy16(3, src[3], dest[3], 0x60);
    DmaCopy16(3, src[4], dest[4], 0x40);
}

void sub_4FAC0(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B1104[gCurrentPinballGame->unk730];
    dest = gUnknown_086B1104[3];
    DmaCopy16(3, src[0], dest[0], 0x40);
    DmaCopy16(3, src[1], dest[1], 0x40);
}

void sub_4FB08(void)
{
    const u8 **src;
    const u8 **dest;

    src = gUnknown_086B0F4C[(gMain.systemFrameCount % 64) / 16];
    dest = gUnknown_086B0F4C[4];
    if (gCurrentPinballGame->unk6A < 192)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->unk6A < 200)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->unk6A < 208)
    {
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    DmaCopy16(3, src[3], dest[3], 0x60);
}

void sub_4FBA4(void)
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
        src = gUnknown_086B1124[i][gCurrentPinballGame->unk71D[i]];
        dest = gUnknown_086B1124[i][6];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
    }
}

void sub_4FC7C(void)
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
        src = &gUnknown_086B1300[i][gCurrentPinballGame->holeIndicators[i]];
        dest = &gUnknown_086B1300[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void sub_4FD88(void)
{
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk724 > 300)
    {
        gCurrentPinballGame->unk726 = 1;
    }
    else if (gCurrentPinballGame->unk724)
    {
        if (gCurrentPinballGame->unk25)
            gCurrentPinballGame->unk726 = 1;
        else
            gCurrentPinballGame->unk726 = (gMain.fieldFrameCount & 0xF) / 8;
    }
    else
    {
        gCurrentPinballGame->unk726 = 0;
    }

    src = gUnknown_086B11CC[gCurrentPinballGame->unk726];
    dest = gUnknown_086B11CC[2];
    DmaCopy16(3, src[0], dest[0], 0xE0);
    DmaCopy16(3, src[1], dest[1], 0xE0);
    if (gCurrentPinballGame->unk6A > 215)
    {
        DmaCopy16(3, src[2], dest[2], 0xC0);
        DmaCopy16(3, src[3], dest[3], 0x40);
    }
}

void sub_4FE6C(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk72B == 0)
    {
        sp0[0] = gCurrentPinballGame->unk734;
        sp0[1] = 0;
        sp0[2] = 0;
    }
    else if (gCurrentPinballGame->unk72B == 1)
    {
        sp0[0] = 1;
        sp0[1] = gCurrentPinballGame->unk734;
        sp0[2] = gCurrentPinballGame->unk734;
    }
    else if (gCurrentPinballGame->unk72B == 2)
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = gCurrentPinballGame->unk734 + 1;
    }
    else
    {
        sp0[0] = 2;
        sp0[1] = 2;
        sp0[2] = 2;
    }

    src = gUnknown_086B13F4[0][sp0[0]];
    dest = gUnknown_086B13F4[0][3];
    if (gCurrentPinballGame->unk6A < 240)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->unk6A < 248)
    {
        DmaCopy16(3, src[1], dest[1], 0x60);
    }

    if (gCurrentPinballGame->unk6A > 88)
    {
        src = gUnknown_086B13F4[1][sp0[1]];
        dest = gUnknown_086B13F4[1][3];
        if (gCurrentPinballGame->unk6A < 254)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }
        if (gCurrentPinballGame->unk6A < 262)
        {
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }

    if (gCurrentPinballGame->unk6A > 96)
    {
        src = gUnknown_086B13F4[2][sp0[2]];
        dest = gUnknown_086B13F4[2][3];
        if (gCurrentPinballGame->unk6A < 264)
        {
            DmaCopy16(3, src[0], dest[0], 0x40);
        }

        DmaCopy16(3, src[1], dest[1], 0x40);
        if (gCurrentPinballGame->unk6A > 104)
        {
            DmaCopy16(3, src[2], dest[2], 0x40);
        }
    }
}

void sub_50000(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk728 > 0)
        index = 1 - gCurrentPinballGame->unk734;

    src = gUnknown_086B11FC[index];
    dest = gUnknown_086B11FC[2];
    if (gCurrentPinballGame->unk6A < 256)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    if (gCurrentPinballGame->unk6A >= 97 && gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->unk6A > 0x67)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void sub_500B4(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk729 > 0)
        index = 1 - gCurrentPinballGame->unk734;

    src = gUnknown_086B122C[index];
    dest = gUnknown_086B122C[2];
    if (gCurrentPinballGame->unk6A < 195)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->unk6A > 30)
    {
        DmaCopy16(3, src[2], dest[2], 0x80);
    }

    if (gCurrentPinballGame->unk6A > 38)
    {
        DmaCopy16(3, src[3], dest[3], 0x80);
    }
}

void sub_50154(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk72E == 0)
        {
            sp0[0] = gCurrentPinballGame->unk734 * 2;
            sp0[1] = gCurrentPinballGame->unk734;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->unk72E == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->unk734 + 1;
            sp0[2] = gCurrentPinballGame->unk734 * 2;
        }
        else if (gCurrentPinballGame->unk72E == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = gCurrentPinballGame->unk734 + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->unk739[0];
        sp0[1] = gCurrentPinballGame->unk739[1];
        sp0[2] = gCurrentPinballGame->unk739[2];
    }


    src = gUnknown_086B1340[0][sp0[0]];
    dest = gUnknown_086B1340[0][4];
    if (gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }
    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->unk6A > 120)
    {
        src = gUnknown_086B1340[1][sp0[1]];
        dest = gUnknown_086B1340[1][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->unk6A > 136) {
        src = gUnknown_086B1340[2][sp0[2]];
        dest = gUnknown_086B1340[2][4];
        DmaCopy16(3, src[0], dest[0], 0x60);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void sub_5030C(void)
{
    s16 sp0[3];
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk72F == 0)
        {
            sp0[0] = gCurrentPinballGame->unk734 * 2;
            sp0[1] = 0;
            sp0[2] = 0;
        }
        else if (gCurrentPinballGame->unk72F == 1)
        {
            sp0[0] = 3;
            sp0[1] = gCurrentPinballGame->unk734 + 1;
            sp0[2] = gCurrentPinballGame->unk734 * 2;
        }
        else if (gCurrentPinballGame->unk72F == 2)
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = (s16) gCurrentPinballGame->unk734 + 2;
        }
        else
        {
            sp0[0] = 3;
            sp0[1] = 3;
            sp0[2] = 3;
        }
    }
    else
    {
        sp0[0] = gCurrentPinballGame->unk736[0];
        sp0[1] = gCurrentPinballGame->unk736[1];
        sp0[2] = gCurrentPinballGame->unk736[2];
    }

    src = gUnknown_086B14A8[0][sp0[0]];
    dest = gUnknown_086B14A8[0][4];
    if (gCurrentPinballGame->unk6A < 264)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    DmaCopy16(3, src[1], dest[1], 0x60);
    DmaCopy16(3, src[2], dest[2], 0x60);

    if (gCurrentPinballGame->unk6A > 120)
    {
        src = gUnknown_086B14A8[1][sp0[1]];
        dest = gUnknown_086B14A8[1][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x40);
        DmaCopy16(3, src[2], dest[2], 0x60);
    }

    if (gCurrentPinballGame->unk6A > 136)
    {
        src = gUnknown_086B14A8[2][sp0[2]];
        dest = gUnknown_086B14A8[2][4];
        DmaCopy16(3, src[0], dest[0], 0x40);
        DmaCopy16(3, src[1], dest[1], 0x60);
        DmaCopy16(3, src[2], dest[2], 0x40);
    }
}

void sub_504C0(void)
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


    src = gUnknown_086B12D0[index];
    dest = gUnknown_086B12D0[2];
    if (gCurrentPinballGame->unk6A < 232)
    {
        DmaCopy16(3, src[0], dest[0], 0x60);
    }

    if (gCurrentPinballGame->unk6A < 240)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->unk6A >= 80)
    {
        if (gCurrentPinballGame->unk6A < 248)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void sub_505A4(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk366 == 3)
        gCurrentPinballGame->unk72A = 1;
    else if (gCurrentPinballGame->unk13)
        gCurrentPinballGame->unk72A = 0;

    if (gCurrentPinballGame->unk72A > 0)
        index = gCurrentPinballGame->unk1A5 * 2 + 1 - gCurrentPinballGame->unk734;
    else
        index = gCurrentPinballGame->unk1A5 * 2;


    src = gUnknown_086B125C[index];
    dest = gUnknown_086B125C[4];
    if (gCurrentPinballGame->unk6A < 224)
    {
        DmaCopy16(3, src[0], dest[0], 0x80);
    }

    if (gCurrentPinballGame->unk6A < 232)
    {
        DmaCopy16(3, src[1], dest[1], 0x80);
    }

    if (gCurrentPinballGame->unk6A > 71)
    {
        if (gCurrentPinballGame->unk6A < 240)
        {
            DmaCopy16(3, src[2], dest[2], 0x80);
        }

        DmaCopy16(3, src[3], dest[3], 0x60);
    }
}

void sub_506B0(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        const u8 **src = &gUnknown_086B12AC[i][gCurrentPinballGame->ballPowerUpLight[i]];
        const u8 **dest = &gUnknown_086B12AC[i][2];
        DmaCopy16(3, *src, *dest, 0x40);
    }
}

void sub_50710(void)
{
    s16 i;
    s16 srcIndex;
    const u8 **src;
    const u8 **dest;

    if (gCurrentPinballGame->unk346 != 3)
    {
        for (i = 0; i < 10; i++)
        {
            if (gCurrentPinballGame->unk34B[i] > 0)
            {
                if (gCurrentPinballGame->unk34B[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0xDC);

                gCurrentPinballGame->unk34B[i]--;
                srcIndex = 1;
            }
            else
            {
                srcIndex = 0;
            }

            src = gUnknown_086B0F9C[i][srcIndex];
            dest = gUnknown_086B0F9C[i][2];
            DmaCopy16(3, src[0], dest[0], 0x40);
            DmaCopy16(3, src[1], dest[1], 0x40);
        }
    }
}

void sub_507D4(void)
{
    s16 index;
    const u8 **src;
    const u8 **dest;

    index = 0;
    if (gCurrentPinballGame->unk308 >= 100)
        index = (gCurrentPinballGame->unk70C % 20) / 4;

    src = gUnknown_086B0E6C[index];
    dest = gUnknown_086B0E6C[5];
    if (gCurrentPinballGame->unk6A < 176)
    {
        DmaCopy16(3, src[0], dest[0], 0x40);
    }

    DmaCopy16(3, src[1], dest[1], 0x40);
}
