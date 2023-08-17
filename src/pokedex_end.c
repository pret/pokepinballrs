#include "global.h"
#include "main.h"

void ResetPokedex(void)
{
    s32 i;
    for (i = 0; i < NUM_SPECIES; i++)
    {
        gMain_saveData.pokedexFlags[i] = 0;
    }
}
