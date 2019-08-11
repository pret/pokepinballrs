#include "global.h"
#include "gbplayer.h"
#include "main.h"

/*static*/ void ReadGbPlayerKeys(void)
{
    u16 keyInput = REG_KEYINPUT ^ KEYS_MASK;
    sGbPlayerPrevKeys = sGbPlayerCurKeys;
    sGbPlayerCurKeys = keyInput;
}

#ifdef NONMATCHING
static u8 CheckGameBoyPlayer(void)
{
    u32 i;
    u16 *curKeys;
    u16 *prevKeys;
    u16 newKeys;
    int gbPlayerDetected;
    int curFrame, lastDetectedFrame, prevDetectedFrame;

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
    while (1)
    {
        if (curFrame < 30)
            ReadGbPlayerKeys();
        else
            break;

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
        DmaCopy32(3, gUnknown_02002008, (void *)BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    }

    for (i = 0; i <= 16; i++)
    {
        VBlankIntrWait();
        REG_BLDY = i;
    }

    if (gbPlayerDetected)
        return 1;
    else
        return 0;
}
#else
NAKED
static u8 CheckGameBoyPlayer(void)
{
    asm_unified("\n\
    push {r4, r5, r6, r7, lr}\n\
    mov r7, sl\n\
    mov r6, sb\n\
    mov r5, r8\n\
    push {r5, r6, r7}\n\
    movs r7, #0\n\
    movs r0, #0\n\
    mov sl, r0\n\
    mov sb, r0\n\
    mov r8, r0\n\
    bl VBlankIntrWait\n\
    ldr r0, _08000F30 @ =0x040000D4\n\
    ldr r1, _08000F34 @ =0x08058248\n\
    str r1, [r0]\n\
    ldr r1, _08000F38 @ =0x06008000\n\
    str r1, [r0, #4]\n\
    ldr r1, _08000F3C @ =0x80002000\n\
    str r1, [r0, #8]\n\
    ldr r1, [r0, #8]\n\
    ldr r1, _08000F40 @ =0x08058048\n\
    str r1, [r0]\n\
    movs r1, #0xa0\n\
    lsls r1, r1, #0x13\n\
    str r1, [r0, #4]\n\
    ldr r1, _08000F44 @ =0x80000100\n\
    str r1, [r0, #8]\n\
    ldr r1, [r0, #8]\n\
    ldr r1, _08000F48 @ =0x0805C248\n\
    str r1, [r0]\n\
    ldr r2, _08000F4C @ =0x02002008\n\
    str r2, [r0, #4]\n\
    ldr r1, _08000F50 @ =0x80000280\n\
    str r1, [r0, #8]\n\
    ldr r1, [r0, #8]\n\
    str r2, [r0]\n\
    movs r1, #0xc0\n\
    lsls r1, r1, #0x13\n\
    str r1, [r0, #4]\n\
    ldr r1, _08000F54 @ =0x80000400\n\
    str r1, [r0, #8]\n\
    ldr r0, [r0, #8]\n\
    ldr r1, _08000F58 @ =0x04000008\n\
    movs r0, #0x88\n\
    strh r0, [r1]\n\
    movs r4, #0\n\
    ldr r6, _08000F5C @ =0x04000054\n\
    movs r5, #0x10\n\
_08000F18:\n\
    bl VBlankIntrWait\n\
    subs r0, r5, r4\n\
    strh r0, [r6]\n\
    adds r4, #1\n\
    cmp r4, #0x10\n\
    bls _08000F18\n\
    ldr r6, _08000F60 @ =0x02002002\n\
    ldr r5, _08000F64 @ =0x02002000\n\
    ldr r4, _08000F30 @ =0x040000D4\n\
    b _08000FA4\n\
    .align 2, 0\n\
_08000F30: .4byte 0x040000D4\n\
_08000F34: .4byte 0x08058248\n\
_08000F38: .4byte 0x06008000\n\
_08000F3C: .4byte 0x80002000\n\
_08000F40: .4byte 0x08058048\n\
_08000F44: .4byte 0x80000100\n\
_08000F48: .4byte 0x0805C248\n\
_08000F4C: .4byte 0x02002008\n\
_08000F50: .4byte 0x80000280\n\
_08000F54: .4byte 0x80000400\n\
_08000F58: .4byte 0x04000008\n\
_08000F5C: .4byte 0x04000054\n\
_08000F60: .4byte 0x02002002\n\
_08000F64: .4byte 0x02002000\n\
_08000F68:\n\
    ldrh r0, [r6]\n\
    ldrh r1, [r5]\n\
    eors r0, r1\n\
    ands r0, r1\n\
    movs r1, #0xf0\n\
    ands r0, r1\n\
    cmp r0, #0xf0\n\
    bne _08000F7C\n\
    mov r8, sb\n\
    mov sb, r7\n\
_08000F7C:\n\
    mov r1, r8\n\
    cmp r1, #0\n\
    beq _08000F8E\n\
    mov r2, sb\n\
    subs r0, r2, r1\n\
    cmp r0, #3\n\
    bgt _08000F8E\n\
    movs r0, #1\n\
    mov sl, r0\n\
_08000F8E:\n\
    adds r7, #1\n\
    bl VBlankIntrWait\n\
    ldr r0, _08000FB0 @ =0x02002008\n\
    str r0, [r4]\n\
    movs r0, #0xc0\n\
    lsls r0, r0, #0x13\n\
    str r0, [r4, #4]\n\
    ldr r0, _08000FB4 @ =0x84000200\n\
    str r0, [r4, #8]\n\
    ldr r0, [r4, #8]\n\
_08000FA4:\n\
    cmp r7, #0x1d\n\
    bgt _08000FB8\n\
    bl ReadGbPlayerKeys\n\
    b _08000F68\n\
    .align 2, 0\n\
_08000FB0: .4byte 0x02002008\n\
_08000FB4: .4byte 0x84000200\n\
_08000FB8:\n\
    movs r4, #0\n\
    ldr r5, _08000FD4 @ =0x04000054\n\
_08000FBC:\n\
    bl VBlankIntrWait\n\
    strh r4, [r5]\n\
    adds r4, #1\n\
    cmp r4, #0x10\n\
    bls _08000FBC\n\
    mov r1, sl\n\
    cmp r1, #0\n\
    bne _08000FD8\n\
    movs r0, #0\n\
    b _08000FDA\n\
    .align 2, 0\n\
_08000FD4: .4byte 0x04000054\n\
_08000FD8:\n\
    movs r0, #1\n\
_08000FDA:\n\
    pop {r3, r4, r5}\n\
    mov r8, r3\n\
    mov sb, r4\n\
    mov sl, r5\n\
    pop {r4, r5, r6, r7}\n\
    pop {r1}\n\
    bx r1");
}
#endif // NONMATCHING

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
    // This probably wasn't the original code, but it matches.
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
