#include "global.h"

void sub_2E67C(void)
{
    if (gCurrentPinballGame->unk306 == 1)
    {
        if (gCurrentPinballGame->unk30C)
            gCurrentPinballGame->unk30C--;
        else
            gCurrentPinballGame->unk306 = 0;
    }
}
