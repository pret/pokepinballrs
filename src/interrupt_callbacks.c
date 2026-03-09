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
    gMainCallbackShadow = func;
    if (!IsInVblank())
        gMainCallback = func;
}

void ResetMainCallback(void)
{
    gMainCallback = DefaultMainCallback;
    gMainCallbackShadow = DefaultMainCallback;
}

void SetVBlankIntrFunc(void (*func)(void))
{
    gVBlankIntrFuncShadow = func;
    if (!IsInVblank())
        *gVBlankIntrFuncPtr = func;
}

void ResetVBlankIntrFunc(void)
{
    *gVBlankIntrFuncPtr = VBlankIntr;
    gVBlankIntrFuncShadow = VBlankIntr;
}

void SetVCountIntrFunc(void (*func)(void))
{
    gVCountIntrFuncShadow = func;
    if (!IsInVblank())
        *gVCountIntrFuncPtr = func;
}

void ResetVCountIntrFunc(void)
{
    *gVCountIntrFuncPtr = VCountIntr;
    gVCountIntrFuncShadow = VCountIntr;
}

