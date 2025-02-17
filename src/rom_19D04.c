#include "global.h"

extern void sub_21238(s32);

void sub_19D04(void)
{
    if (gCurrentPinballGame->progressForBonus == 2 && gCurrentPinballGame->unk14 > 2)
        sub_21238(0);

    if (gCurrentPinballGame->progressForBonus > 2)
        return;

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
    else if (gCurrentPinballGame->unk14 == 6)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk73C = 0;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
    else if (gCurrentPinballGame->unk14 > 3)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
}
