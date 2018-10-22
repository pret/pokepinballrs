#include "global.h"
#include "m4a.h"
#include "main.h"

extern void sub_B54(void);
extern void sub_BBC(void);
extern void sub_CBC(void);
extern void sub_D10(void);
extern void sub_D74(void);
extern void sub_FE8(void);
extern void ReadKeys(void);
extern u32 IntrMain_Buffer[0x200];
extern u32 IntrMain[];

void AgbMain(void)
{
    RegisterRamReset(0xFF);
    sub_BBC();
    DmaCopy32(3, IntrMain, IntrMain_Buffer, sizeof(IntrMain_Buffer));
    INTR_VECTOR = IntrMain_Buffer;
    sub_B54();
    sub_FE8();
    while (1)
    {
        ReadKeys();
        gMainFuncs[gMain.mainState]();
        sub_D74();
    }
}

void sub_9BC_Main(void)
{
    switch (gMain.subState)
    {
    case 0:
        sub_CBC();
        sub_24C();
        gMain.subState++;
        break;
    case 1:
        if (gMain.newKeys & KEYS_MASK)
            gMain.subState = 2;
        break;
    default:
        sub_2B4();
        sub_D10();
        SetMainGameState(1);
        break;
    }
}

void sub_A08(void)
{
    m4aSoundVSync();
    INTR_CHECK |= INTR_FLAG_VBLANK;
}

void sub_A20(void)
{
    INTR_CHECK |= INTR_FLAG_VCOUNT;
    while (!(REG_DISPSTAT & DISPSTAT_HBLANK));
    if (gMain.mainState == 2)
    {
        REG_BG0HOFS = 0;
        if (gMain.unk28)
        {
            if (gMain.vCount == 72)
            {
                REG_BG0VOFS = gMain.unk2A * 4 + 88;
                gMain.vCount = 144;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
            else
            {
                REG_BG0VOFS = 352;
                gMain.vCount = 72;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
        }
        else if (gMain.unk2C)
        {
            if (gMain.vCount == 40)
            {
                gMain.blendControl = BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3
                            | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG0;
                gMain.blendAlpha = 0xA06;
                REG_BLDCNT = gMain.blendControl;
                REG_BLDALPHA = gMain.blendAlpha;
                gMain.vCount = 144;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
            else
            {
                gMain.blendControl = BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3
                            | BLDCNT_EFFECT_NONE | BLDCNT_TGT1_BG0;
                gMain.blendAlpha = 0;
                REG_BLDCNT = gMain.blendControl;
                REG_BLDALPHA = gMain.blendAlpha;
                REG_BG0VOFS = 352;
                gMain.vCount = 40;
                REG_DISPSTAT &= 0xFF;
                REG_DISPSTAT |= (gMain.vCount << 8) + DISPSTAT_VCOUNT_INTR;
            }
        }
        else
        {
            REG_BG0VOFS = 352;
        }
    }
}
