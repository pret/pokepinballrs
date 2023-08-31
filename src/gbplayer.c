#include "global.h"
#include "gbplayer.h"
#include "main.h"

/*static*/ void ReadGbPlayerKeys(void)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    sGbPlayerPrevKeys = sGbPlayerCurKeys;
    sGbPlayerCurKeys = keyInput;
}

static u8 CheckGameBoyPlayer(void)
{
    u32 i;
    u16 *curKeys;
    u16 *prevKeys;
    u16 newKeys;
    int gbPlayerDetected;
    int curFrame, lastDetectedFrame, prevDetectedFrame;
    void *labels[2]; // TODO fake match
    vu32 *dma3;

    curFrame = 0;
    gbPlayerDetected = 0;
    lastDetectedFrame = 0;
    prevDetectedFrame = 0;
    VBlankIntrWait();
    DmaCopy16(3, gUnknown_08058248, (void *)BG_CHAR_ADDR(2), BG_CHAR_SIZE);
    DmaCopy16(3, gUnknown_08058048, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gUnknown_0805C248, gUnknown_02002008, 0x500);
    DmaCopy16(3, gUnknown_02002008, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    REG_BG0CNT = BGCNT_256COLOR | BGCNT_CHARBASE(2);
    for (i = 0; i <= 16; i++)
    {
        VBlankIntrWait();
        REG_BLDY = 16 - i;
    }

    prevKeys = &sGbPlayerPrevKeys;
    curKeys = &sGbPlayerCurKeys;
    dma3 = (vu32 *)REG_ADDR_DMA3; // unroll it manuallly :/
    labels[0] = &&label; // reference label to disable block reorder
    while (1)
    {
        if (curFrame < 30)
            ReadGbPlayerKeys();
        else
            break;
    label:
        newKeys = (*prevKeys ^ *curKeys) & *curKeys;
        if ((newKeys & DPAD_ANY) == DPAD_ANY)
        {
            prevDetectedFrame = lastDetectedFrame;
            lastDetectedFrame = curFrame;
        }

        if (prevDetectedFrame && lastDetectedFrame - prevDetectedFrame < 4)
            gbPlayerDetected = 1;

        curFrame++;
        VBlankIntrWait();
        {
            vu32 *dmaRegs = dma3;
            dmaRegs[0] = (vu32)gUnknown_02002008;
            dmaRegs[1] = BG_SCREEN_ADDR(0);
            dmaRegs[2] = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_INC) << 16 | (BG_SCREEN_SIZE / sizeof(u32)));
            dmaRegs[2];
        }
    }

    for (i = 0; i <= 16; i++)
    {
        VBlankIntrWait();
        REG_BLDY = i;
    }

    if (gbPlayerDetected) // TODO bool8?
        return 1;
    else
        return 0;
}

void InitGameBoyPlayer(void)
{
    REG_IE |= INTR_FLAG_VBLANK;
    REG_DISPSTAT |= DISPSTAT_VBLANK_INTR;
    REG_BLDCNT = BLDCNT_TGT2_ALL | BLDCNT_EFFECT_LIGHTEN | BLDCNT_TGT1_ALL;
    REG_BLDY = 0x10;
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_BG0_ON;
    gUnknown_02019C00 = 0;
    gUnknown_02019BEC = 0;
    gUnknown_02019BF4 = 0;
    gUnknown_02019BF0 = 0;
    gGameBoyPlayerEnabled = CheckGameBoyPlayer();
    REG_IE &= ~INTR_FLAG_VBLANK;
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPCNT = 0;
    gUnknown_02019BFC = -1;
    gUnknown_02019BE4 = 0;
    gUnknown_02019BE8 = 0;
    gUnknown_02019BF8 = 0;
    gUnknown_02019C08 = 2;
}

void sub_10C0(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        gIntrTable[0] = sub_13FC;
        gIntrTable[1] = sub_1828;
        gUnknown_02019BF4 = 1;
        sub_1340();
    }

    gUnknown_02019BFC = -1;
    gUnknown_02019BE4 = 0;
    gUnknown_02019C08 = 2;
    gUnknown_02019C04 = 0;
}

void sub_111C(void)
{
    // TODO This probably wasn't the original code, but it matches.
    int *var0 = &gUnknown_02019BF4;
    int val = 0;
    gUnknown_02019C00 = val;
    gUnknown_02019BEC = val;
    *var0 = val;
    gUnknown_02019BF0 = val;
    gUnknown_02019BFC = -1;
    gUnknown_02019BE4 = val;
    gUnknown_02019BE8 = val;
    gUnknown_02019BF8 = val;
    gUnknown_02019C08 = 2;
}

int sub_1170(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        u8 val = gUnknown_02019C10 - 4;
        if (val > 1)
            return 0;
    }

    return 1;
}

void sub_1198(void)
{
    gIntrTable[0] = SerialIntr;
    gIntrTable[1] = Timer3Intr;
}

void sub_11B0(int arg0)
{
    if (gMain_saveData.unk141)
    {
        gUnknown_02019BF8 = arg0;
        gUnknown_02019BFC = 0;
        gUnknown_02019BE4 = 0;
        gUnknown_02019BE8 = 0;
    }
}

void sub_11E4(int arg0)
{
    gUnknown_02019C08 = arg0;
}

void sub_11F0(int arg0)
{
    gUnknown_02019C04 = arg0;
}

void sub_11FC(void)
{
    int var0;
    int var1;

    if (gGameBoyPlayerEnabled == 1)
    {
        switch (gUnknown_02019C10)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 4:
            if (gUnknown_02019BFC >= 0 && gUnknown_02019C08 && !gUnknown_02019C04)
            {
                if (!(gUnknown_02019BE8 & 1))
                {
                    while (1)
                    {
                        var0 = gUnknown_086A4C44[gUnknown_02019BF8][gUnknown_02019BFC++];
                        var1 = gUnknown_086A4C44[gUnknown_02019BF8][gUnknown_02019BFC];
                        if (var0 == -1)
                        {
                            gUnknown_02019BFC = var0;
                            gUnknown_02019C00 = 0;
                            break;
                        }

                        if (var0 < -1)
                        {
                            if (gUnknown_02019BE4)
                            {
                                if (--gUnknown_02019BE4 == 0)
                                {
                                    gUnknown_02019BFC++;
                                }
                                else
                                {
                                    gUnknown_02019BFC--;
                                    gUnknown_02019BFC -= var1;
                                }
                            }
                            else
                            {
                                gUnknown_02019BE4 = ~var0;
                                gUnknown_02019BFC--;
                                gUnknown_02019BFC -= var1;
                            }
                        }
                        else
                        {
                            gUnknown_02019C00 = var0;
                            break;
                        }
                    }
                }
                else if (gUnknown_02019BE8 % 2 == 1 && gUnknown_02019C08 == 1)
                {
                    gUnknown_02019C00 = 0;
                }
            }
            else
            {
                gUnknown_02019C00 = 0;
            }
            break;
        case 5:
            if (++gUnknown_02019BF0 > 60)
            {
                if (gUnknown_02019BF4)
                    sub_1340();

                gUnknown_02019BF0 = 0;
            }
            break;
        }
    }

    gUnknown_02019BE8++;
}

void sub_1340(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD;
    REG_SIOCNT |= SIO_INTR_ENABLE;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
    REG_IME = INTR_FLAG_VBLANK;
    REG_SIOCNT_L &= -2;
    gUnknown_02019C10 = 0;
    CpuFill32(0, gUnknown_02002808, 0xC);
    REG_IME = 0;
    REG_SIOCNT |= SIO_MULTI_BUSY;
    REG_IME = INTR_FLAG_VBLANK;
    REG_TM3CNT_L = 0x8000;
    REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_64CLK;
}

// void sub_13FC(void)
// {

// }
