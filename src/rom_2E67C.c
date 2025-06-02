//
// Created by Delta on 6/2/25.
//
#include "global.h"

void sub_2E67C(void)
{
    if ((s8)gCurrentPinballGame->unk306 == 1)
    {
        if (gCurrentPinballGame->unk30C)
            gCurrentPinballGame->unk30C--;
        else
            gCurrentPinballGame->unk306 = 0;
    }
}
