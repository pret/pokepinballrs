#include "global.h"
#include "main.h"

extern StateFunc gPokedexStateFuncs[];

void PokedexMain(void)
{
    gPokedexStateFuncs[gMain.subState]();
}
