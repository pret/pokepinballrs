#include "global.h"
#include "main.h"


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
        if (gCurrentPinballGame->shouldProcessWhiscash)
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

void SapphireBoardProcess_0B_50B80(void)
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

void DusclopsBoardProcess_0A_50D48(void)
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

void DusclopsBoardProcess_0B_50DB8(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void KecleonBoardProcess_0A_50DE0(void)
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

void KyogreBoardProcess_0A_50F04()
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

void KyogreBoardProcess_0B_50FAC(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void GroudonBoardProcess_0A_50FD4(void)
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

void GroudonBoardProcess_0B_51068(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void RayquazaBoardProcess_0A_51090(void)
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

void RayquazaBoardProcess_0B_51128(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}

void SphealBoardProcess_0A_51150(void)
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

void SphealBoardProcess_0B_511F8(void)
{
    LoadSpriteSets(gUnknown_086B155C[gMain.selectedField].spriteSets,
                   gUnknown_086B155C[gMain.selectedField].numSpriteSets,
                   gMain.spriteGroups);
}
