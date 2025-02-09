#include "global.h"

extern void sub_21238(s32);

void sub_19D04(void)
{
    if ((gCurrentPinballGame->unk13 == 2) && (2 < gCurrentPinballGame->unk14))
    {
        sub_21238(0);
    }
    if (2 < gCurrentPinballGame->unk13)
    {
        return;
    }

    // Normal switch doesn't work... is it an enum switch?
    if (gCurrentPinballGame->unk14 == 3)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
    if (gCurrentPinballGame->unk14 == 4)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
    else
    {
        if (gCurrentPinballGame->unk14 == 6)
        {
            gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
            gCurrentPinballGame->unk73C = 0;
            gCurrentPinballGame->unk72E = 0;
            gCurrentPinballGame->unk72F = 0;
            return;
        }
        if (gCurrentPinballGame->unk14 < 4)
        {
            return;
        }
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }

}
