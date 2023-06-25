#include "global.h"
#include "functions.h"

extern u32 gUnknown_0202ADD0;
extern u16 gUnknown_0201A444;
extern u32 gUnknown_0202BDF0;
extern u8 gUnknown_0201C1AC;
extern u8 gUnknown_0202ADDC;

void sub_250C(void)
{
    REG_IME = 0;
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
}

void sub_2538(void)
{
    gUnknown_0202ADD0 = 0;
    gUnknown_0201A444 = 0;
    gUnknown_0202BDF0 = 0;
    gUnknown_0201C1AC = 0;
    gUnknown_0202ADDC = 0;
}

void sub_2568(void)
{
    sub_24DC();
    REG_IME = 0;
    ResetMainCallback();
    ResetVBlankIntrFunc();
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VCOUNT | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VCOUNT_INTR  | DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
}

