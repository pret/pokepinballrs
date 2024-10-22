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

// https://decomp.me/scratch/eHAo1
// Case 0 similar to https://github.com/pret/pokefirered/blob/d2c592030d78d1a46df1cba562a3c7af677dbf21/src/librfu_sio32id.c#L122
NAKED
void sub_13FC(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #0xc\n\
	ldr r1, _08001434 @ =gUnknown_02002818\n\
	ldr r0, _08001438 @ =0x04000120\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, _0800143C @ =0x0400010E\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08001440 @ =gUnknown_02019C10\n\
	ldrb r1, [r0]\n\
	mov sb, r0\n\
	cmp r1, #5\n\
	bls _0800142A\n\
	b _0800161C\n\
_0800142A:\n\
	lsls r0, r1, #2\n\
	ldr r1, _08001444 @ =_08001448\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08001434: .4byte gUnknown_02002818\n\
_08001438: .4byte 0x04000120\n\
_0800143C: .4byte 0x0400010E\n\
_08001440: .4byte gUnknown_02019C10\n\
_08001444: .4byte _08001448\n\
_08001448: @ jump table\n\
	.4byte _08001460 @ case 0\n\
	.4byte _08001520 @ case 1\n\
	.4byte _08001574 @ case 2\n\
	.4byte _080015C8 @ case 3\n\
	.4byte _0800161C @ case 4\n\
	.4byte _0800161C @ case 5\n\
_08001460:\n\
	ldr r0, _080014B0 @ =0x04000120\n\
	mov r8, r0\n\
	ldr r6, [r0]\n\
	ldr r3, _080014B4 @ =gUnknown_02002808\n\
	ldrb r1, [r3]\n\
	lsls r2, r1, #4\n\
	adds r0, r6, #0\n\
	lsls r0, r2\n\
	lsrs r0, r0, #0x10\n\
	movs r7, #1\n\
	subs r1, r7, r1\n\
	lsls r1, r1, #4\n\
	lsls r6, r1\n\
	adds r1, r6, #0\n\
	lsrs r6, r1, #0x10\n\
	ldrh r5, [r3, #0xa]\n\
	adds r4, r3, #0\n\
	cmp r5, #0\n\
	bne _080014E4\n\
	ldrh r2, [r4, #6]\n\
	adds r1, r0, #0\n\
	cmp r1, r2\n\
	bne _080014E2\n\
	ldrh r3, [r4, #2]\n\
	cmp r3, #3\n\
	bhi _080014B8\n\
	ldrh r0, [r4, #4]\n\
	mvns r0, r0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r1, r0\n\
	bne _080014E4\n\
	mvns r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r6, r0\n\
	bne _080014E4\n\
	adds r0, r3, #1\n\
	strh r0, [r4, #2]\n\
	b _080014E4\n\
	.align 2, 0\n\
_080014B0: .4byte 0x04000120\n\
_080014B4: .4byte gUnknown_02002808\n\
_080014B8:\n\
	strh r6, [r4, #0xa]\n\
	ldr r0, _080014D8 @ =0x00008002\n\
	cmp r6, r0\n\
	bne _080014E0\n\
	mov r1, sb\n\
	strb r7, [r1]\n\
	movs r0, #1\n\
	bl sub_1748\n\
	ldr r1, _080014DC @ =gUnknown_02002814\n\
	str r0, [r1]\n\
	mov r2, r8\n\
	str r0, [r2]\n\
	strh r5, [r4, #2]\n\
	b _08001640\n\
	.align 2, 0\n\
_080014D8: .4byte 0x00008002\n\
_080014DC: .4byte gUnknown_02002814\n\
_080014E0:\n\
	strh r5, [r4, #0xa]\n\
_080014E2:\n\
	strh r5, [r4, #2]\n\
_080014E4:\n\
	ldrh r0, [r4, #2]\n\
	cmp r0, #3\n\
	bhi _080014F8\n\
	lsls r0, r0, #1\n\
	ldr r1, _080014F4 @ =gUnknown_0805C748\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	b _080014FC\n\
	.align 2, 0\n\
_080014F4: .4byte gUnknown_0805C748\n\
_080014F8:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
_080014FC:\n\
	strh r0, [r4, #4]\n\
	mvns r0, r6\n\
	strh r0, [r4, #6]\n\
	ldr r3, _0800151C @ =0x04000120\n\
	ldrh r2, [r4, #4]\n\
	ldrb r1, [r4]\n\
	movs r0, #1\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #4\n\
	lsls r2, r0\n\
	ldrh r0, [r4, #6]\n\
	lsls r1, r1, #4\n\
	lsls r0, r1\n\
	adds r2, r2, r0\n\
	str r2, [r3]\n\
	b _08001640\n\
	.align 2, 0\n\
_0800151C: .4byte 0x04000120\n\
_08001520:\n\
	ldr r5, _08001544 @ =gUnknown_02019C10\n\
	ldrb r0, [r5]\n\
	bl sub_16A0\n\
	cmp r0, #0\n\
	beq _08001550\n\
	ldr r1, _08001548 @ =gUnknown_02002808\n\
	movs r4, #0\n\
	movs r0, #0\n\
	strh r0, [r1, #2]\n\
	str r0, [sp]\n\
	ldr r2, _0800154C @ =0x05000003\n\
	mov r0, sp\n\
	bl CpuSet\n\
	strb r4, [r5]\n\
	b _08001554\n\
	.align 2, 0\n\
_08001544: .4byte gUnknown_02019C10\n\
_08001548: .4byte gUnknown_02002808\n\
_0800154C: .4byte 0x05000003\n\
_08001550:\n\
	movs r0, #2\n\
	strb r0, [r5]\n\
_08001554:\n\
	ldr r0, _0800156C @ =gUnknown_02019BF4\n\
	ldr r0, [r0]\n\
	ldr r1, _08001570 @ =gUnknown_02019C10\n\
	mov sb, r1\n\
	cmp r0, #0\n\
	bne _08001564\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
_08001564:\n\
	mov r2, sb\n\
	ldrb r0, [r2]\n\
	b _080015F8\n\
	.align 2, 0\n\
_0800156C: .4byte gUnknown_02019BF4\n\
_08001570: .4byte gUnknown_02019C10\n\
_08001574:\n\
	ldr r5, _08001598 @ =gUnknown_02019C10\n\
	ldrb r0, [r5]\n\
	bl sub_16A0\n\
	cmp r0, #0\n\
	beq _080015A4\n\
	ldr r1, _0800159C @ =gUnknown_02002808\n\
	movs r4, #0\n\
	movs r0, #0\n\
	strh r0, [r1, #2]\n\
	str r0, [sp, #4]\n\
	add r0, sp, #4\n\
	ldr r2, _080015A0 @ =0x05000003\n\
	bl CpuSet\n\
	strb r4, [r5]\n\
	b _080015A8\n\
	.align 2, 0\n\
_08001598: .4byte gUnknown_02019C10\n\
_0800159C: .4byte gUnknown_02002808\n\
_080015A0: .4byte 0x05000003\n\
_080015A4:\n\
	movs r0, #3\n\
	strb r0, [r5]\n\
_080015A8:\n\
	ldr r0, _080015C0 @ =gUnknown_02019BF4\n\
	ldr r0, [r0]\n\
	ldr r1, _080015C4 @ =gUnknown_02019C10\n\
	mov sb, r1\n\
	cmp r0, #0\n\
	bne _080015B8\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
_080015B8:\n\
	mov r2, sb\n\
	ldrb r0, [r2]\n\
	b _080015F8\n\
	.align 2, 0\n\
_080015C0: .4byte gUnknown_02019BF4\n\
_080015C4: .4byte gUnknown_02019C10\n\
_080015C8:\n\
	mov r5, sb\n\
	ldrb r0, [r5]\n\
	bl sub_16A0\n\
	cmp r0, #0\n\
	beq _080015E8\n\
	ldr r1, _08001608 @ =gUnknown_02002808\n\
	movs r4, #0\n\
	movs r0, #0\n\
	strh r0, [r1, #2]\n\
	str r0, [sp, #8]\n\
	add r0, sp, #8\n\
	ldr r2, _0800160C @ =0x05000003\n\
	bl CpuSet\n\
	strb r4, [r5]\n\
_080015E8:\n\
	ldr r0, _08001610 @ =gUnknown_02019BF4\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _080015F4\n\
	movs r0, #4\n\
	strb r0, [r5]\n\
_080015F4:\n\
	mov r1, sb\n\
	ldrb r0, [r1]\n\
_080015F8:\n\
	bl sub_1748\n\
	ldr r1, _08001614 @ =gUnknown_02002814\n\
	str r0, [r1]\n\
	ldr r1, _08001618 @ =0x04000120\n\
	str r0, [r1]\n\
	b _08001640\n\
	.align 2, 0\n\
_08001608: .4byte gUnknown_02002808\n\
_0800160C: .4byte 0x05000003\n\
_08001610: .4byte gUnknown_02019BF4\n\
_08001614: .4byte gUnknown_02002814\n\
_08001618: .4byte 0x04000120\n\
_0800161C:\n\
	ldr r3, _08001634 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08001638 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0800163C @ =0x0000FF7F\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	b _08001650\n\
	.align 2, 0\n\
_08001634: .4byte 0x04000208\n\
_08001638: .4byte 0x04000200\n\
_0800163C: .4byte 0x0000FF7F\n\
_08001640:\n\
	ldr r2, _08001660 @ =0x04000128\n\
	ldrh r0, [r2]\n\
	movs r1, #0x80\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08001664 @ =0x0400010E\n\
	movs r0, #0xc1\n\
	strh r0, [r1]\n\
_08001650:\n\
	add sp, #0xc\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08001660: .4byte 0x04000128\n\
_08001664: .4byte 0x0400010E"
    );
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
