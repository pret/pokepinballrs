#include "global.h"
#include "main.h"

extern StateFunc gUnknown_0805C880[];

void PokedexMain(void)
{
    gUnknown_0805C880[gMain.subState]();
}
