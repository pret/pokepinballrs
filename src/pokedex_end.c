#include "global.h"
#include "main.h"

extern s16 gUnknown_0202A1C0[];
extern s16 gUnknown_0202A588;
extern s16 gUnknown_086A61BC[];

s16 sub_8A78(s32 unk_a)
{
    s16 a = (s16) unk_a;
    
    if ((gUnknown_0202A1C0[a] == 4) && (gUnknown_086A61BC[a] != -1))
    {
        gUnknown_0202A588 = 1;
    }
    else
    {
        gUnknown_0202A588 = 0;
    }
    
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
