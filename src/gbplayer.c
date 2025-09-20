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
    DmaCopy16(3, gGbPlayerGfx, (void *)BG_CHAR_ADDR(2), BG_CHAR_SIZE);
    DmaCopy16(3, gGbPlayerPalettes, (void *)BG_PLTT, BG_PLTT_SIZE);
    DmaCopy16(3, gGbPlayerTilemap, gGbPlayerTilemapBuffer, 0x500);
    DmaCopy16(3, gGbPlayerTilemapBuffer, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
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
            dmaRegs[0] = (vu32)gGbPlayerTilemapBuffer;
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
        gIntrTable[0] = Sio32IDIntr;
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
    if (gMain_saveData.rumbleEnabled)
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
    CpuFill32(0, &gUnknown_02002808, 0xC);
    REG_IME = 0;
    REG_SIOCNT |= SIO_MULTI_BUSY;
    REG_IME = INTR_FLAG_VBLANK;
    REG_TM3CNT_L = 0x8000;
    REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_64CLK;
}

// https://decomp.me/scratch/eHAo1
// Case 0 similar to https://github.com/pret/pokefirered/blob/d2c592030d78d1a46df1cba562a3c7af677dbf21/src/librfu_sio32id.c#L122
void Sio32IDIntr(void)
{
    s32 iVar6;
    gUnknown_02002818 = REG_SIODATA32;
    REG_TM3CNT_H = 0;
    REG_TM3CNT_L = 0x8000;

    switch (gUnknown_02019C10)
    {
        case 0: {
            u32 receiverChunk = REG_SIODATA32;
            u32 senderChunk;
            senderChunk = receiverChunk << 16 * gUnknown_02002808.MS_mode >> 16;
            receiverChunk = receiverChunk << 16 * (1 - gUnknown_02002808.MS_mode) >> 16;
            if (gUnknown_02002808.lastId == 0)
            {
                if ((u16) senderChunk == gUnknown_02002808.recv_id)
                {
                    if (gUnknown_02002808.count < 4)
                    {
                        if (gUnknown_02002808.recv_id == (u16)~gUnknown_02002808.send_id)
                        {
                            if ((u16) receiverChunk == (u16)~gUnknown_02002808.recv_id)
                                ++gUnknown_02002808.count;
                        }
                        // goto green
                    }
                    else // blue
                    {
                        gUnknown_02002808.lastId = receiverChunk;
                        if (receiverChunk == 0x8002)
                        {
                            gUnknown_02019C10 = 1;
                            gUnknown_02002814 = sub_1748(1);
                            REG_SIODATA32 = gUnknown_02002814;
                            gUnknown_02002808.count = 0;
                            break;
                        }
                        else
                        {
                            gUnknown_02002808.lastId = 0;
                            gUnknown_02002808.count = 0;
                        }
                    }
                }
                else
                {
                    gUnknown_02002808.count = 0;
                }
            }
            // green
            if (gUnknown_02002808.count < 4)
            {
                gUnknown_02002808.send_id = *(gUnknown_02002808.count + Sio32ConnectionData); // oh no
            }
            else
            {
                gUnknown_02002808.send_id = 0x8000;
            }
            gUnknown_02002808.recv_id = ~receiverChunk;
            REG_SIODATA32 =
                (gUnknown_02002808.send_id << ((1 - gUnknown_02002808.MS_mode) << 4)) +
                (gUnknown_02002808.recv_id << (gUnknown_02002808.MS_mode << 4));
            break;
    }
        case 1:
            iVar6 = sub_16A0(gUnknown_02019C10);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gUnknown_02019C10 = 0;
            }
            else
            {
                gUnknown_02019C10 = 2;
            }

            if (gUnknown_02019BF4 == 0)
            {
                gUnknown_02019C10 = 4;
            }
            gUnknown_02002814 = sub_1748(gUnknown_02019C10);
            REG_SIODATA32 = gUnknown_02002814;
            break;
        case 2:
            iVar6 = sub_16A0(gUnknown_02019C10);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gUnknown_02019C10 = 0;
            }
            else
            {
                gUnknown_02019C10 = 3;
            }

            if (gUnknown_02019BF4 == 0)
            {
                gUnknown_02019C10 = 4;
            }
            gUnknown_02002814 = sub_1748(gUnknown_02019C10);
            REG_SIODATA32 = gUnknown_02002814;
            break;
        case 3:
            iVar6 = sub_16A0(gUnknown_02019C10);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gUnknown_02019C10 = 0;
            }

            if (gUnknown_02019BF4 == 0)
            {
                gUnknown_02019C10 = 4;
            }
            gUnknown_02002814 = sub_1748(gUnknown_02019C10);
            REG_SIODATA32 = gUnknown_02002814;
            break;
        case 4:
        case 5:
        default:
            REG_IME = 0; // TODO DisableInterrupts
            REG_IE &= 0xFF7F;
            REG_IME = 1;
            return;
    }

    REG_SIOCNT |= 0x80;
    REG_TM3CNT_H = 0xC1;
}

u32 sub_1668(u32 arg1, u32 arg2)
{
    u8 uVar1;
    u32 uVar2;
    u32 uVar3;

    uVar2 = (arg1 & 0xFFFFFF) << 4;
    arg2 = (arg2 << 0x1C);
    uVar2 |= arg2;
    uVar3 = uVar2 >> 0x1C;

    for (uVar1 = 6; uVar1 != 0; uVar1--)
    {
        uVar3 ^= uVar2 >> (uVar1 << 2) & 0xF;
    }

    uVar3 &= 0xF;
    uVar2 |= uVar3;
    return uVar2;
}

u32 sub_16A0(u8 param_1)
{
    s8 cVar1;
    u32 uVar3;

    uVar3 = gUnknown_02002818 >> 0x1C;
    cVar1 = sub_170C();

    if (cVar1) return 1;
    switch (param_1)
    {
        default:
            return 1;
        case 1:
            {
                u32 *r1 = &gUnknown_0200281C;
                u32 r0 = (gUnknown_02002818 << 4) >> 8;
                *r1 = r0 & 1;
                if (uVar3 != 1) return 1;
            }
            break;
        case 2:
            if (uVar3 != 2)
                return 1;
            {
                u32* r0 = &gUnknown_0200281C;
                u32 r1 = (gUnknown_02002818 << 4) >> 8;
                if (*r0 != r1) return 1;
            }
            break;
        case 3:
            if (uVar3 != 3) return 1;
    }

    return 0;
}

u32 sub_170C(void)
{
    u8 uVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    u32 uVar5;

    uVar2 = gUnknown_02002818 / 16;
    ++uVar2; --uVar2;
    uVar3 = gUnknown_02002818 % 16;
    uVar4 = uVar2 >> 0x18;

    for (uVar1 = 6; uVar1 != 0; uVar1--)
    {
        uVar5 = uVar2 >> (4 * (uVar1 - 1));
        uVar5 &= 0xF;
        uVar4 ^= uVar5;
    }

    if (uVar4 == uVar3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

u32 sub_1748(u8 param_1)
{
    u32 uVar1;
    u32 uVar2;
    u32 param_3;

    switch (param_1)
    {
        case 2:
            uVar1 = gUnknown_0200281C;
            uVar2 = 2;
            goto case_fallthrough;
        case 3:
            if (gUnknown_02019C00 == 0)
            {
                uVar1 = sub_17D8(0);
                param_3 = sub_1668(uVar1, 4);
            }
            if (gUnknown_02019C00 == 1)
            {
                uVar1 = sub_17D8(1);
                param_3 = sub_1668(uVar1, 4);
            }
            if (gUnknown_02019C00 != 2) break;
            uVar1 = sub_17D8(2);
            uVar2 = 4;
            goto case_fallthrough;
        case 1:
        case 4:
        case 5:
            uVar1 = 1;
            uVar2 = 1;
        case_fallthrough: // Fairly confident that this is not in fact a fakematch, due to the break above
            param_3 = sub_1668(uVar1, uVar2);
    }

    return param_3;
}

u32 sub_17D8(u32 arg1)
{
    u32 retVal;

    switch (gUnknown_02019BEC)
    {
    case 0:
        retVal = arg1;
        break;
    case 1:
        retVal = arg1 << 2;
        break;
    case 2:
        retVal = arg1 << 4;
        break;
    case 3:
        retVal = arg1 << 6;
        break;
    case 4:
        retVal = arg1 | arg1 << 2 | arg1 << 4 | arg1 << 6;
    }

    return retVal;
}

void sub_1828(void)
{
    // TODO macro?
    REG_IME = 0;
    REG_IE &= 0xFFBF; // TODO convert to and not flag
    REG_IME = 1;

    REG_IME = 0;
    REG_SIOCNT &= 0xFF7F; // TODO convert to and not flag
    REG_IME = 1;

    REG_TM3CNT_H = 0;
    REG_TM3CNT_L = 0x8000;

    gUnknown_02019C10 = 5;
}
