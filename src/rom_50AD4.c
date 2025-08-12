#include "global.h"
#include "main.h"

struct Unk_086B0E6C
{
    const u8 *unk0[5][2];
    u8 *unk28[2];
};
extern const struct Unk_086B0E6C gUnknown_086B0E6C;

void sub_507D4(void)
{
    s16 index;
    const u8 *const *src;
    u8 *const *dest;

    index = 0;
    if (gCurrentPinballGame->unk308 >= 100)
        index = (gCurrentPinballGame->unk70C % 20) / 4;

    src = gUnknown_086B0E6C.unk0[index];
    dest = gUnknown_086B0E6C.unk28;
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