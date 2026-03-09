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
    gGbPlayerRumbleMode = 0;
    gGbPlayerCommandState = 0;
    gGbPlayerReady = 0;
    gGbPlayerTimeout = 0;
    gGameBoyPlayerEnabled = CheckGameBoyPlayer();
    REG_IE &= ~INTR_FLAG_VBLANK;
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPCNT = 0;
    gGbPlayerCmdIndex = -1;
    gGbPlayerRumbleTimer = 0;
    gGbPlayerFrameCounter = 0;
    gGbPlayerDataIndex = 0;
    gGbPlayerMotorMode = 2;
}

void StartGbPlayerCommunication(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        gIntrTable[0] = Sio32IDIntr;
        gIntrTable[1] = GbPlayerTimeoutIntr;
        gGbPlayerReady = 1;
        InitGbPlayerSerialComm();
    }

    gGbPlayerCmdIndex = -1;
    gGbPlayerRumbleTimer = 0;
    gGbPlayerMotorMode = 2;
    gGbPlayerPaused = 0;
}

void ResetGbPlayerState(void)
{
    // TODO This probably wasn't the original code, but it matches.
    int *var0 = &gGbPlayerReady;
    int val = 0;
    gGbPlayerRumbleMode = val;
    gGbPlayerCommandState = val;
    *var0 = val;
    gGbPlayerTimeout = val;
    gGbPlayerCmdIndex = -1;
    gGbPlayerRumbleTimer = val;
    gGbPlayerFrameCounter = val;
    gGbPlayerDataIndex = val;
    gGbPlayerMotorMode = 2;
}

int IsGbPlayerCommDone(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        u8 val = gGbPlayerCommPhase - 4;
        if (val > 1)
            return 0;
    }

    return 1;
}

void RestoreDefaultInterrupts(void)
{
    gIntrTable[0] = SerialIntr;
    gIntrTable[1] = Timer3Intr;
}

void PlayRumble(int arg0)
{
    if (gMain_saveData.rumbleEnabled)
    {
        gGbPlayerDataIndex = arg0;
        gGbPlayerCmdIndex = 0;
        gGbPlayerRumbleTimer = 0;
        gGbPlayerFrameCounter = 0;
    }
}

void SetGbPlayerMotorMode(int arg0)
{
    gGbPlayerMotorMode = arg0;
}

void SetGbPlayerPaused(int arg0)
{
    gGbPlayerPaused = arg0;
}

void UpdateGbPlayerRumble(void)
{
    int var0;
    int var1;

    if (gGameBoyPlayerEnabled == 1)
    {
        switch (gGbPlayerCommPhase)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 4:
            if (gGbPlayerCmdIndex >= 0 && gGbPlayerMotorMode && !gGbPlayerPaused)
            {
                if (!(gGbPlayerFrameCounter & 1))
                {
                    while (1)
                    {
                        var0 = gUnknown_086A4C44[gGbPlayerDataIndex][gGbPlayerCmdIndex++];
                        var1 = gUnknown_086A4C44[gGbPlayerDataIndex][gGbPlayerCmdIndex];
                        if (var0 == -1)
                        {
                            gGbPlayerCmdIndex = var0;
                            gGbPlayerRumbleMode = 0;
                            break;
                        }

                        if (var0 < -1)
                        {
                            if (gGbPlayerRumbleTimer)
                            {
                                if (--gGbPlayerRumbleTimer == 0)
                                {
                                    gGbPlayerCmdIndex++;
                                }
                                else
                                {
                                    gGbPlayerCmdIndex--;
                                    gGbPlayerCmdIndex -= var1;
                                }
                            }
                            else
                            {
                                gGbPlayerRumbleTimer = ~var0;
                                gGbPlayerCmdIndex--;
                                gGbPlayerCmdIndex -= var1;
                            }
                        }
                        else
                        {
                            gGbPlayerRumbleMode = var0;
                            break;
                        }
                    }
                }
                else if (gGbPlayerFrameCounter % 2 == 1 && gGbPlayerMotorMode == 1)
                {
                    gGbPlayerRumbleMode = 0;
                }
            }
            else
            {
                gGbPlayerRumbleMode = 0;
            }
            break;
        case 5:
            if (++gGbPlayerTimeout > 60)
            {
                if (gGbPlayerReady)
                    InitGbPlayerSerialComm();

                gGbPlayerTimeout = 0;
            }
            break;
        }
    }

    gGbPlayerFrameCounter++;
}

void InitGbPlayerSerialComm(void)
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
    gGbPlayerCommPhase = 0;
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

    switch (gGbPlayerCommPhase)
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
                            gGbPlayerCommPhase = 1;
                            gUnknown_02002814 = GetGbPlayerCommResult(1);
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
            iVar6 = ValidateGbPlayerResponse(gGbPlayerCommPhase);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gGbPlayerCommPhase = 0;
            }
            else
            {
                gGbPlayerCommPhase = 2;
            }

            if (gGbPlayerReady == 0)
            {
                gGbPlayerCommPhase = 4;
            }
            gUnknown_02002814 = GetGbPlayerCommResult(gGbPlayerCommPhase);
            REG_SIODATA32 = gUnknown_02002814;
            break;
        case 2:
            iVar6 = ValidateGbPlayerResponse(gGbPlayerCommPhase);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gGbPlayerCommPhase = 0;
            }
            else
            {
                gGbPlayerCommPhase = 3;
            }

            if (gGbPlayerReady == 0)
            {
                gGbPlayerCommPhase = 4;
            }
            gUnknown_02002814 = GetGbPlayerCommResult(gGbPlayerCommPhase);
            REG_SIODATA32 = gUnknown_02002814;
            break;
        case 3:
            iVar6 = ValidateGbPlayerResponse(gGbPlayerCommPhase);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gUnknown_02002808.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gUnknown_02002808, 0x5000003);
                gGbPlayerCommPhase = 0;
            }

            if (gGbPlayerReady == 0)
            {
                gGbPlayerCommPhase = 4;
            }
            gUnknown_02002814 = GetGbPlayerCommResult(gGbPlayerCommPhase);
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

u32 EncodeGbPlayerPacket(u32 arg1, u32 arg2)
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

u32 ValidateGbPlayerResponse(u8 param_1)
{
    s8 cVar1;
    u32 uVar3;

    uVar3 = gUnknown_02002818 >> 0x1C;
    cVar1 = VerifyGbPlayerChecksum();

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

u32 VerifyGbPlayerChecksum(void)
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

u32 GetGbPlayerCommResult(u8 param_1)
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
            if (gGbPlayerRumbleMode == 0)
            {
                uVar1 = ShiftRumbleByCommandState(0);
                param_3 = EncodeGbPlayerPacket(uVar1, 4);
            }
            if (gGbPlayerRumbleMode == 1)
            {
                uVar1 = ShiftRumbleByCommandState(1);
                param_3 = EncodeGbPlayerPacket(uVar1, 4);
            }
            if (gGbPlayerRumbleMode != 2) break;
            uVar1 = ShiftRumbleByCommandState(2);
            uVar2 = 4;
            goto case_fallthrough;
        case 1:
        case 4:
        case 5:
            uVar1 = 1;
            uVar2 = 1;
        case_fallthrough: // Fairly confident that this is not in fact a fakematch, due to the break above
            param_3 = EncodeGbPlayerPacket(uVar1, uVar2);
    }

    return param_3;
}

u32 ShiftRumbleByCommandState(u32 arg1)
{
    u32 retVal;

    switch (gGbPlayerCommandState)
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

void GbPlayerTimeoutIntr(void)
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

    gGbPlayerCommPhase = 5;
}
