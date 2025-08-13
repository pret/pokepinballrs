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
        sp0[0] = gCurrentPinballGame->unk739;
        sp0[1] = gCurrentPinballGame->unk73A;
        sp0[2] = gCurrentPinballGame->unk73B;
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
        sp0[0] = gCurrentPinballGame->unk736;
        sp0[1] = gCurrentPinballGame->unk737;
        sp0[2] = gCurrentPinballGame->unk738;
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

void RubyBoardProcess_0A_50848(void)
{
    s16 i;
    struct SpriteGroup *group;

    for (i = 0; i < 84; i++)
        gMain.spriteGroups[i].available = 0;

    gMain.spriteGroups[64].available = 1;
    group = &gMain.spriteGroups[48]; // fake match?
    gMain.spriteGroups[70].available = 1;
    gMain.spriteGroups[0].available = 1;
    gMain.spriteGroups[1].available = 1;
    gMain.spriteGroups[2].available = 1;
    gMain.spriteGroups[28].available = 1;
    gMain.spriteGroups[81].available = 1;
    gMain.spriteGroups[65].available = 1;
    gMain.spriteGroups[71].available = 1;
    gMain.spriteGroups[66].available = 1;
    gMain.spriteGroups[51].available = 1;
    gMain.spriteGroups[61].available = 1;
    group->available = 1;
    gMain.spriteGroups[52].available = 1;
    gMain.spriteGroups[62].available = 1;
    LoadSpriteSets(
        gUnknown_086B155C[gMain.selectedField].spriteSets,
        gUnknown_086B155C[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups);
}

void RubyBoardProcess_0B_50918(void)
{
    s16 i;

    gMain.spriteGroups[10].available = 0;
    gMain.spriteGroups[11].available = 0;
    gMain.spriteGroups[48].available = 0;
    gMain.spriteGroups[71].available = 0;
    for (i = 51; i < 67; i++)
        gMain.spriteGroups[i].available = 0;

    gCurrentPinballGame->unk1BC = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->unk68 < 110)
    {
        gMain.spriteGroups[65].available = 1;
        gMain.spriteGroups[71].available = 1;
        gMain.spriteGroups[66].available = 1;
    }

    if (gCurrentPinballGame->unk68 < 168)
    {
        gMain.spriteGroups[48].available = 1;
        gMain.spriteGroups[52].available = 1;
    }

    if (gCurrentPinballGame->unk68 < 220)
    {
        gMain.spriteGroups[51].available = 1;
        gMain.spriteGroups[61].available = 1;
        gMain.spriteGroups[64].available = 1;
        if (gCurrentPinballGame->unk2A4 != 0)
            gMain.spriteGroups[63].available = 1;
        else
            gMain.spriteGroups[62].available = 1;
    }

    if (gCurrentPinballGame->unk68 > 63)
    {
        gMain.spriteGroups[53].available = 1;
        gMain.spriteGroups[57].available = 1;
    }

    if (gCurrentPinballGame->unk68 > 115)
        gMain.spriteGroups[58].available = 1;

    if (gCurrentPinballGame->unk68 > 130)
    {
        gMain.spriteGroups[59].available = 1;
        gMain.spriteGroups[60].available = 1;
    }

    if (gCurrentPinballGame->unk68 > 216)
    {
        gMain.spriteGroups[56].available = 1;
        gMain.spriteGroups[54].available = 1;
        gMain.spriteGroups[55].available = 1;
        gMain.spriteGroups[10].available = 1;
        gMain.spriteGroups[11].available = 1;
    }

    LoadSpriteSets(
        gUnknown_086B155C[gMain.selectedField].spriteSets,
        gUnknown_086B155C[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups);
}

void SapphireBoardProcess_0A_50AD4(void)
{
    s16 i;

    for (i = 0; i < 87; i++)
        gMain.spriteGroups[i].available = 0;

    gMain.spriteGroups[72].available = 1;
    gMain.spriteGroups[63].available = 1;
    gMain.spriteGroups[60].available = 1;
    gMain.spriteGroups[69].available = 1;
    gMain.spriteGroups[52].available = 1;
    gMain.spriteGroups[74].available = 1;
    gMain.spriteGroups[0].available = 1;
    gMain.spriteGroups[1].available = 1;
    gMain.spriteGroups[2].available = 1;
    gMain.spriteGroups[25].available = 1;
    gMain.spriteGroups[85].available = 1;
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}