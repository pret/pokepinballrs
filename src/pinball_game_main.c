#include "global.h"
#include "main.h"

extern const StateFunc gPinballGameStateFuncs[];

void PinballGameMain(void)
{
    gPinballGameStateFuncs[gMain.subState]();
}