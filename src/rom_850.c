#include "global.h"
#include "main.h"

u16 IsInVblank(void)
{
    if ((REG_IME & 1)                           // Interrupts enabled
     && (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)   // In VBLANK
     && (REG_IE & INTR_FLAG_VBLANK)             // VBlank interrupt enabled
     && !(REG_DISPCNT & DISPCNT_FORCED_BLANK))  // Ignore VBlank interrupts during forced blank
        return TRUE;
    else
        return FALSE;
}

void SetMainCallback(void (*func)(void))
{
    gUnknown_02017BD4 = func;
    if (!IsInVblank())
        gMainCallback = func;
}

void ResetMainCallback(void)
{
    gMainCallback = DefaultMainCallback;
    gUnknown_02017BD4 = DefaultMainCallback;
}

void SetVBlankIntrFunc(void (*func)(void))
{
    gUnknown_02017BD0 = func;
    if (!IsInVblank())
        *gVBlankIntrFuncPtr = func;
}

void ResetVBlankIntrFunc(void)
{
    *gVBlankIntrFuncPtr = VBlankIntr;
    gUnknown_02017BD0 = VBlankIntr;
}

void SetVCountIntrFunc(void (*func)(void))
{
    gUnknown_0200FBA0 = func;
    if (!IsInVblank())
        *gVCountIntrFuncPtr = func;
}

void ResetVCountIntrFunc(void)
{
    *gVCountIntrFuncPtr = VCountIntr;
    gUnknown_0200FBA0 = VCountIntr;
}

