#include "global.h"
#include "main.h"

extern s16 gUnknown_0202A1C0[];
extern s16 gUnknown_0202A588;
extern s16 gUnknown_0202BF14;

extern s16 gUnknown_086A61BC[];

/* TODO unfinished
void sub_8974(s32 species)
{
    s32 var0 = gUnknown_086A61BC[(s16) species];
    s32 quotient;
    s16 remainder;
    s16 var1;

    if (var0 != -1)
    {
        if (var0 < 100)
        {
            gUnknown_0202BF14 = 0;
            quotient = var0 / 5;
            remainder = var0 % 5;
            var1 = (s16) var0;

            sub_10708(___ + remainder * 0xD80, (void *)(OBJ_VRAM0 + 0x3800), 0x6C, 1);
        }
        else
        {
            gUnknown_0202BF14 = 1;
            quotient = (var0 - 100) / 6;
            remainder = (var0 - 100) / 6;
            var1 = (s16) var0;

            sub_10708((void *)(gMonHatchSpriteGroupGfx[var1] + remainder * 0x10E0), (void *)(OBJ_VRAM0 + 0x4800), 0x87, 1);
        }
    }
}*/

s16 sub_8A78(s32 species)
{
    s16 var0 = (s16) species;

    if ((gUnknown_0202A1C0[var0] == 4) && (gUnknown_086A61BC[var0] != -1))
        gUnknown_0202A588 = 1;
    else
        gUnknown_0202A588 = 0;

    return gUnknown_0202A588;
}

void ResetPokedex(void)
{
    s32 i;
    for (i = 0; i < NUM_SPECIES; i++)
    {
        gMain_saveData.pokedexFlags[i] = 0;
    }
}
