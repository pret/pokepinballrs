#include "global.h"
#include "main.h"

void sub_50B80(void)
{
    s16 i;

    for (i = 55; i < 71; i++)
        gMain.spriteGroups[i].available = 0;

    gMain.spriteGroups[52].available = 0;
    gMain.spriteGroups[72].available = 0;
    gMain.spriteGroups[26].available = 0;
    gMain.spriteGroups[51].available = 0;
    gMain.spriteGroups[76].available = 0;
    gMain.spriteGroups[75].available = 0;
    gMain.spriteGroups[10].available = 0;
    gMain.spriteGroups[11].available = 0;
    gCurrentPinballGame->unk1BC = gMain.systemFrameCount % 25;
    if (gCurrentPinballGame->unk68 < 90)
    {
        gMain.spriteGroups[52].available = 1;
        gMain.spriteGroups[51].available = 1;
    }
    if (gCurrentPinballGame->unk68 < 220)
    {
        gMain.spriteGroups[72].available = 1;
    }
    if (gCurrentPinballGame->unk68 < 150)
    {
        gMain.spriteGroups[60].available = 1;
        gMain.spriteGroups[69].available = 1;
    }
    if (gCurrentPinballGame->unk68 < 196)
    {
        gMain.spriteGroups[63].available = 1;
        gMain.spriteGroups[75].available = 1;
    }
    if (gCurrentPinballGame->unk68 < 202)
    {
        gMain.spriteGroups[61].available = 1;
        gMain.spriteGroups[58].available = 1;
        gMain.spriteGroups[62].available = 1;
        gMain.spriteGroups[59].available = 1;
        gMain.spriteGroups[76].available = 1;
    }
    if (gCurrentPinballGame->unk68 > 118)
    {
        gMain.spriteGroups[70].available = 1;
        gMain.spriteGroups[26].available = 1;
        gMain.spriteGroups[64].available = 1;
        gMain.spriteGroups[68].available = 1;
        gMain.spriteGroups[65].available = 1;
        gMain.spriteGroups[66].available = 1;
        gMain.spriteGroups[67].available = 1;
    }
    if (gCurrentPinballGame->unk68 > 216)
    {
        gMain.spriteGroups[57].available = 1;
        gMain.spriteGroups[55].available = 1;
        gMain.spriteGroups[56].available = 1;
        gMain.spriteGroups[10].available = 1;
        gMain.spriteGroups[11].available = 1;
    }

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets, gUnknown_086B155C[gMain.selectedField].numSpriteSets, gMain.spriteGroups);
}

void sub_50D48(void)
{
    s16 i;

    for (i = 0; i < 15; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    gMain.unk44[0]->available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_50DB8(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_50DE0(void)
{
    s16 i;

    for (i = 0; i < 33; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    gMain.unk44[0]->available = 1;
    gMain.spriteGroups[23].available = 1;
    gMain.spriteGroups[9].available = 1;
    gMain.spriteGroups[24].available = 1;
    gMain.spriteGroups[16].available = 1;
    gMain.spriteGroups[17].available = 1;
    gMain.spriteGroups[7].available = 1;
    gMain.spriteGroups[10].available = 1;
    gMain.spriteGroups[11].available = 1;
    gMain.spriteGroups[12].available = 1;
    gMain.spriteGroups[13].available = 1;
    gMain.spriteGroups[14].available = 1;
    gMain.spriteGroups[15].available = 1;
    gMain.spriteGroups[18].available = 1;
    gMain.spriteGroups[19].available = 1;
    gMain.spriteGroups[20].available = 1;
    gMain.spriteGroups[21].available = 1;
    gMain.spriteGroups[25].available = 1;
    gMain.spriteGroups[26].available = 1;
    gMain.spriteGroups[27].available = 1;
    gMain.spriteGroups[28].available = 1;
    gMain.spriteGroups[31].available = 1;
    gMain.spriteGroups[32].available = 1;
    gMain.spriteGroups[29].available = 1;
    gMain.spriteGroups[30].available = 1;

    LoadSpriteSets(
        gUnknown_086B155C[gMain.selectedField].spriteSets,
        gUnknown_086B155C[gMain.selectedField].numSpriteSets,
        gMain.spriteGroups
    );
}

void nullsub_20(void)
{}

void sub_50F04()
{
    s16 i;

    for (i = 0; i < 27; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    gMain.unk44[0]->available = 1;
    gMain.spriteGroups[11].available = 1;
    gMain.spriteGroups[12].available = 1;
    gMain.spriteGroups[13].available = 1;
    gMain.spriteGroups[14].available = 1;
    gMain.spriteGroups[21].available = 1;
    gMain.spriteGroups[22].available = 1;
    gMain.spriteGroups[23].available = 1;
    gMain.spriteGroups[15].available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_50FAC(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_50FD4(void)
{
    s16 i;

    for (i = 0; i < 32; i++)
    {
        if (i < 5) {
            gMain.spriteGroups[i].available = 1;
        } else {
            gMain.spriteGroups[i].available = 0;
        }
    }

    gMain.unk44[0]->available = 1;
    gMain.spriteGroups[11].available = 1;
    gMain.spriteGroups[12].available = 1;
    gMain.spriteGroups[13].available = 1;
    gMain.spriteGroups[14].available = 1;
    gMain.spriteGroups[29].available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51068(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51090(void)
{
    s16 i;

    for (i = 0; i < 46; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    gMain.unk44[0]->available = 1;
    gMain.spriteGroups[42].available = 1;
    gMain.spriteGroups[11].available = 1;
    gMain.spriteGroups[12].available = 1;
    gMain.spriteGroups[13].available = 1;
    gMain.spriteGroups[21].available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51128(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_51150(void)
{
    s16 i;

    for (i = 0; i < 23; i++)
    {
        if (i < 5)
            gMain.spriteGroups[i].available = 1;
        else
            gMain.spriteGroups[i].available = 0;
    }

    gMain.unk44[0]->available = 1;
    gMain.spriteGroups[18].available = 1;
    gMain.spriteGroups[21].available = 1;
    gMain.spriteGroups[22].available = 1;
    gMain.spriteGroups[14].available = 1;
    gMain.spriteGroups[15].available = 1;
    gMain.spriteGroups[16].available = 1;
    gMain.spriteGroups[17].available = 1;

    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void sub_511F8(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}
