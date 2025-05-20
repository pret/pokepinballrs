#include "global.h"
#include "main.h"

extern s16 gPokedexFlags[];
extern s16 gUnknown_0202A588;
extern s16 gUnknown_0202BF14;

extern s16 gUnknown_086A61BC[];

extern u8 *gUnknown_086B15B4[];
extern u8 *gUnknown_086BB6F4[];
extern u8 *gMonHatchSpriteGroupGfx[];
extern u8 *gMonHatchSpriteGroupPals[];

void sub_8974(s16 species)
{
    int var0;
    s16 quotient;
    s16 remainder;
    s16 var1;

    var0 = gUnknown_086A61BC[species];
    if (var0 == -1)
        return;

    if (var0 < 100)
    {
        gUnknown_0202BF14 = 0;
        quotient = var0 / 5;
        remainder = var0 % 5;

        sub_10708(gUnknown_086BB6F4[quotient] + remainder * 0xD80, (void *)(OBJ_VRAM0 + 0x3800), 108, 1);
        DmaCopy16(3, gUnknown_086B15B4[quotient] + remainder * 0x20, (void *)OBJ_PLTT + 0x40, 0x20);
    }
    else
    {
        gUnknown_0202BF14 = 1;
        quotient = (var0 - 100) / 6;
        remainder = (var0 - 100) % 6;

        sub_10708(gMonHatchSpriteGroupGfx[quotient] + remainder * 0x10E0, (void *)(OBJ_VRAM0 + 0x4800), 135, 1);
        DmaCopy16(3, gMonHatchSpriteGroupPals[quotient] + remainder * 0x20, (void *)OBJ_PLTT + 0x60, 0x20);
    }
}

s16 sub_8A78(s16 species)
{
    if (gPokedexFlags[species] == 4 && gUnknown_086A61BC[species] != -1)
        gUnknown_0202A588 = 1;
    else
        gUnknown_0202A588 = 0;

    return gUnknown_0202A588;
}

void ResetPokedex(void)
{
    int i;

    for (i = 0; i < NUM_SPECIES; i++)
        gMain_saveData.pokedexFlags[i] = SPECIES_UNSEEN;
}
