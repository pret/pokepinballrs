#include "global.h"
#include "main.h"

void SetMainGameState(u16 mainState)
{
    gMain.mainState = mainState;
    gMain.subState = 0;
}

void sub_24C(void)
{
    u16 i;

    REG_BLDCNT = 0;
    REG_BLDY = 0x10;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8)
                | BLDCNT_EFFECT_LIGHTEN
                | BLDCNT_TGT1_BD;
    REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
    gMain.unk16 = REG_DISPCNT;

    for (i = 0; i < 32; i++)
    {
        REG_BLDY = 15 - i / 2;
        sub_D74();
    }

    REG_BLDCNT = 0;
}

void sub_2B4(void)
{
    u16 i;

    REG_BLDCNT = 0;
    REG_BLDY = 0;
    REG_BLDCNT = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8)
                | BLDCNT_EFFECT_LIGHTEN
                | BLDCNT_TGT1_BD;

    for (i = 0; i < 16; i++)
    {
        REG_BLDY = i + 1;
        sub_D74();
    }

    gMain.unk16 |= DISPCNT_FORCED_BLANK;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
    DmaFill16(3, 0, (void *)BG_VRAM, 0x18000);
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = 0;
    REG_BLDY = 0;
}
