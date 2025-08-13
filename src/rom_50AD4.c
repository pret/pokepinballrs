#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 *gUnknown_086B0E6C[][2];
extern const u8 *gUnknown_086B0F9C[][3][2];
extern const u8 *gUnknown_086B12AC[][3];
extern const u8 *gUnknown_086B125C[][4];
extern const u8 *gUnknown_086B12D0[][4];


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
        index = gCurrentPinballGame->unk1A5 * 2 - (gCurrentPinballGame->unk734 - 1);
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