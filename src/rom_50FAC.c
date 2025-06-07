#include "global.h"
#include "main.h"

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
