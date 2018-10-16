#include "global.h"
#include "main.h"

void SetMainGameState(u16 mainState)
{
	gMain.mainState = mainState;
	gMain.subState = 0;
}
