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
    gRumbleCommand = 0;
    gRumbleMotorMode = 0;
    gSio32SerialEnabled = 0;
    gSio32ReconnectTimer = 0;
    gGameBoyPlayerEnabled = CheckGameBoyPlayer();
    REG_IE &= ~INTR_FLAG_VBLANK;
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_INTR;
    REG_DISPCNT = 0;
    gRumblePatternPosition = -1;
    gRumbleLoopCounter = 0;
    gRumbleFrameCounter = 0;
    gRumblePatternIndex = 0;
    gRumbleSpeedMode = 2;
}

void EnableGbPlayerRumble(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        gIntrTable[0] = Sio32IDIntr;
        gIntrTable[1] = Sio32TimeoutIntr;
        gSio32SerialEnabled = 1;
        InitSio32Hardware();
    }

    gRumblePatternPosition = -1;
    gRumbleLoopCounter = 0;
    gRumbleSpeedMode = 2;
    gRumblePaused = 0;
}

void DisableGbPlayerRumble(void)
{
    // TODO This probably wasn't the original code, but it matches.
    int *var0 = &gSio32SerialEnabled;
    int val = 0;
    gRumbleCommand = 0;
    gRumbleMotorMode = 0;
    gSio32SerialEnabled = 0;
    *var0 = val;
    gSio32ReconnectTimer = 0;
    gRumblePatternPosition = -1;
    gRumbleLoopCounter = 0;
    gRumbleFrameCounter = 0;
    gRumblePatternIndex = 0;
    gRumbleSpeedMode = 2;
}

int IsGbPlayerReady(void)
{
    if (gGameBoyPlayerEnabled == 1)
    {
        u8 val = gSio32CommState - 4;
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
        gRumblePatternIndex = arg0;
        gRumblePatternPosition = 0;
        gRumbleLoopCounter = 0;
        gRumbleFrameCounter = 0;
    }
}

void SetRumbleMode(int arg0)
{
    gRumbleSpeedMode = arg0;
}

void SetRumblePaused(int arg0)
{
    gRumblePaused = arg0;
}

void ProcessRumbleFrame(void)
{
    int var0;
    int var1;

    if (gGameBoyPlayerEnabled == 1)
    {
        switch (gSio32CommState)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 4:
            if (gRumblePatternPosition >= 0 && gRumbleSpeedMode && !gRumblePaused)
            {
                if (!(gRumbleFrameCounter & 1))
                {
                    while (1)
                    {
                        var0 = gRumblePatterns[gRumblePatternIndex][gRumblePatternPosition++];
                        var1 = gRumblePatterns[gRumblePatternIndex][gRumblePatternPosition];
                        if (var0 == -1)
                        {
                            gRumblePatternPosition = var0;
                            gRumbleCommand = 0;
                            break;
                        }

                        if (var0 < -1)
                        {
                            if (gRumbleLoopCounter)
                            {
                                if (--gRumbleLoopCounter == 0)
                                {
                                    gRumblePatternPosition++;
                                }
                                else
                                {
                                    gRumblePatternPosition--;
                                    gRumblePatternPosition -= var1;
                                }
                            }
                            else
                            {
                                gRumbleLoopCounter = ~var0;
                                gRumblePatternPosition--;
                                gRumblePatternPosition -= var1;
                            }
                        }
                        else
                        {
                            gRumbleCommand = var0;
                            break;
                        }
                    }
                }
                else if (gRumbleFrameCounter % 2 == 1 && gRumbleSpeedMode == 1)
                {
                    gRumbleCommand = 0;
                }
            }
            else
            {
                gRumbleCommand = 0;
            }
            break;
        case 5:
            if (++gSio32ReconnectTimer > 60)
            {
                if (gSio32SerialEnabled)
                    InitSio32Hardware();

                gSio32ReconnectTimer = 0;
            }
            break;
        }
    }

    gRumbleFrameCounter++;
}

void InitSio32Hardware(void)
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
    gSio32CommState = 0;
    CpuFill32(0, &gSio32Id, 0xC);
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
    gSio32ReceivedData = REG_SIODATA32;
    REG_TM3CNT_H = 0;
    REG_TM3CNT_L = 0x8000;

    switch (gSio32CommState)
    {
        case 0: {
            u32 receiverChunk = REG_SIODATA32;
            u32 senderChunk;
            senderChunk = receiverChunk << 16 * gSio32Id.MS_mode >> 16;
            receiverChunk = receiverChunk << 16 * (1 - gSio32Id.MS_mode) >> 16;
            if (gSio32Id.lastId == 0)
            {
                if ((u16) senderChunk == gSio32Id.recv_id)
                {
                    if (gSio32Id.count < 4)
                    {
                        if (gSio32Id.recv_id == (u16)~gSio32Id.send_id)
                        {
                            if ((u16) receiverChunk == (u16)~gSio32Id.recv_id)
                                ++gSio32Id.count;
                        }
                        // goto green
                    }
                    else // blue
                    {
                        gSio32Id.lastId = receiverChunk;
                        if (receiverChunk == 0x8002)
                        {
                            gSio32CommState = 1;
                            gSio32SendData = Sio32BuildCommand(1);
                            REG_SIODATA32 = gSio32SendData;
                            gSio32Id.count = 0;
                            break;
                        }
                        else
                        {
                            gSio32Id.lastId = 0;
                            gSio32Id.count = 0;
                        }
                    }
                }
                else
                {
                    gSio32Id.count = 0;
                }
            }
            // green
            if (gSio32Id.count < 4)
            {
                gSio32Id.send_id = *(gSio32Id.count + Sio32ConnectionData); // oh no
            }
            else
            {
                gSio32Id.send_id = 0x8000;
            }
            gSio32Id.recv_id = ~receiverChunk;
            REG_SIODATA32 =
                (gSio32Id.send_id << ((1 - gSio32Id.MS_mode) << 4)) +
                (gSio32Id.recv_id << (gSio32Id.MS_mode << 4));
            break;
    }
        case 1:
            iVar6 = Sio32ValidateResponse(gSio32CommState);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gSio32Id.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gSio32Id, 0x5000003);
                gSio32CommState = 0;
            }
            else
            {
                gSio32CommState = 2;
            }

            if (gSio32SerialEnabled == 0)
            {
                gSio32CommState = 4;
            }
            gSio32SendData = Sio32BuildCommand(gSio32CommState);
            REG_SIODATA32 = gSio32SendData;
            break;
        case 2:
            iVar6 = Sio32ValidateResponse(gSio32CommState);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gSio32Id.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gSio32Id, 0x5000003);
                gSio32CommState = 0;
            }
            else
            {
                gSio32CommState = 3;
            }

            if (gSio32SerialEnabled == 0)
            {
                gSio32CommState = 4;
            }
            gSio32SendData = Sio32BuildCommand(gSio32CommState);
            REG_SIODATA32 = gSio32SendData;
            break;
        case 3:
            iVar6 = Sio32ValidateResponse(gSio32CommState);
            if (iVar6 != 0)
            {
                u32 stack_temp;
                gSio32Id.count = 0;
                stack_temp = 0;
                CpuSet(&stack_temp, &gSio32Id, 0x5000003);
                gSio32CommState = 0;
            }

            if (gSio32SerialEnabled == 0)
            {
                gSio32CommState = 4;
            }
            gSio32SendData = Sio32BuildCommand(gSio32CommState);
            REG_SIODATA32 = gSio32SendData;
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

u32 Sio32EncodePacket(u32 arg1, u32 arg2)
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

u32 Sio32ValidateResponse(u8 param_1)
{
    s8 cVar1;
    u32 uVar3;

    uVar3 = gSio32ReceivedData >> 0x1C;
    cVar1 = Sio32VerifyChecksum();

    if (cVar1) return 1;
    switch (param_1)
    {
        default:
            return 1;
        case 1:
            {
                u32 *r1 = &gSio32RemoteDeviceId;
                u32 r0 = (gSio32ReceivedData << 4) >> 8;
                *r1 = r0 & 1;
                if (uVar3 != 1) return 1;
            }
            break;
        case 2:
            if (uVar3 != 2)
                return 1;
            {
                u32* r0 = &gSio32RemoteDeviceId;
                u32 r1 = (gSio32ReceivedData << 4) >> 8;
                if (*r0 != r1) return 1;
            }
            break;
        case 3:
            if (uVar3 != 3) return 1;
    }

    return 0;
}

u32 Sio32VerifyChecksum(void)
{
    u8 uVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    u32 uVar5;

    uVar2 = gSio32ReceivedData / 16;
    ++uVar2; --uVar2;
    uVar3 = gSio32ReceivedData % 16;
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

u32 Sio32BuildCommand(u8 param_1)
{
    u32 uVar1;
    u32 uVar2;
    u32 param_3;

    switch (param_1)
    {
        case 2:
            uVar1 = gSio32RemoteDeviceId;
            uVar2 = 2;
            goto case_fallthrough;
        case 3:
            if (gRumbleCommand == 0)
            {
                uVar1 = EncodeRumbleCommand(0);
                param_3 = Sio32EncodePacket(uVar1, 4);
            }
            if (gRumbleCommand == 1)
            {
                uVar1 = EncodeRumbleCommand(1);
                param_3 = Sio32EncodePacket(uVar1, 4);
            }
            if (gRumbleCommand != 2) break;
            uVar1 = EncodeRumbleCommand(2);
            uVar2 = 4;
            goto case_fallthrough;
        case 1:
        case 4:
        case 5:
            uVar1 = 1;
            uVar2 = 1;
        case_fallthrough: // Fairly confident that this is not in fact a fakematch, due to the break above
            param_3 = Sio32EncodePacket(uVar1, uVar2);
    }

    return param_3;
}

u32 EncodeRumbleCommand(u32 arg1)
{
    u32 retVal;

    switch (gRumbleMotorMode)
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

void Sio32TimeoutIntr(void)
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

    gSio32CommState = 5;
}
