// include macros
#include "global.h"
#include "m4a.h"
#include "main.h"

// "static" define macros

// "static" enums

// "static" struct definitions

// static function declarations

// static IWRAM variable declarations

// static EWRAM variable declarations

// static const definitions

// function definitions

// TODO Unsorted

#define MAX_LINK_PLAYERS 2

void sub_1884(void);
void sub_19B4(void);
void sub_19CC(void);
void sub_1A78(void);
void nullsub_15(void);
void sub_1AA4(void);
s32 sub_1B04(u8 *shouldAdvanceLinkState, s16 *sendCmd, u16 (*recvCmds)[MAX_LINK_PLAYERS]);
void sub_1C5C(void);

void sub_1C84(void);
void sub_1CD4(u16 *);
void sub_1DB8(u16 (*recvCmds)[MAX_LINK_PLAYERS]);
void sub_1EC0(void);
void sub_1F4C(void);
void sub_1F5C(void);
void sub_1FEC(void);

bool8 sub_1FFC(void);
void sub_20FC(void);
void sub_223C(void);
void sub_2308(void);
void sub_2338(void);
void sub_2364(void);
void sub_23B4(void);

#define CMD_LENGTH 8
#define QUEUE_CAPACITY 0x20


void sub_1DB8(u16 (*recvCmds)[MAX_LINK_PLAYERS]);

#define LINKCMD_NONE 0xEFFF

#define LINK_SLAVE 0
#define LINK_MASTER 8

// TODO quite different from pokeemerald, redo constants
#define LINK_STAT_LOCAL_ID               0x00000003
#define LINK_STAT_PLAYER_COUNT           0x0000001C
#define LINK_STAT_PLAYER_COUNT_SHIFT     2
#define LINK_STAT_MASTER                 0x00000020
#define LINK_STAT_MASTER_SHIFT           5
#define LINK_STAT_CONN_ESTABLISHED       0x00000040
#define LINK_STAT_CONN_ESTABLISHED_SHIFT 6
#define LINK_STAT_RECEIVED_NOTHING       0x00000100
#define LINK_STAT_RECEIVED_NOTHING_SHIFT 8
#define LINK_STAT_UNK_FLAG_9             0x00000200
#define LINK_STAT_UNK_FLAG_9_SHIFT       9
#define LINK_STAT_ERRORS                 0x0007F000
#define LINK_STAT_ERRORS_SHIFT           12

#define LINK_STAT_ERROR_HARDWARE         0x00001000
#define LINK_STAT_ERROR_HARDWARE_SHIFT   12
#define LINK_STAT_ERROR_CHECKSUM         0x00002000
#define LINK_STAT_ERROR_CHECKSUM_SHIFT   13
#define LINK_STAT_ERROR_QUEUE_FULL       0x00004000
#define LINK_STAT_ERROR_QUEUE_FULL_SHIFT 14
#define LINK_STAT_ERROR_LAG_MASTER       0x00010000
#define LINK_STAT_ERROR_LAG_MASTER_SHIFT 16
#define LINK_STAT_ERROR_INVALID_ID       0x00020000
#define LINK_STAT_ERROR_INVALID_ID_SHIFT 17
#define LINK_STAT_ERROR_LAG_SLAVE        0x00040000
#define LINK_STAT_ERROR_LAG_SLAVE_SHIFT  18

enum
{
    QUEUE_FULL_NONE,
    QUEUE_FULL_SEND,
    QUEUE_FULL_RECV,
};

enum
{
    LINK_STATE_START0,
    LINK_STATE_START1,
    LINK_STATE_HANDSHAKE,
    LINK_STATE_INIT_TIMER,
    LINK_STATE_CONN_ESTABLISHED,
};

enum
{
    LAG_NONE,
    LAG_MASTER,
    LAG_SLAVE,
};

struct SendQueue
{
    u16 data[CMD_LENGTH][QUEUE_CAPACITY];
    u8 pos;
    u8 count;
};

struct RecvQueue
{
    u16 data[MAX_LINK_PLAYERS][CMD_LENGTH][QUEUE_CAPACITY];
    u8 pos;
    u8 count; // 0x621
};

struct Link { // struct Link
    u8 isMaster; // 0x0
    u8 state; // 0x1
    u8 localId; // 0x2
    u8 playerCount; // 0x3
    u16 handshakeBuffer[4]; // 0x4
    bool8 receivedNothing; // 0xC
    u8 serialIntrCounter; // 0xD
    u8 unkE; // 0xE
    u8 fillerF; // 0xF
    bool8 handshakeAsMaster; // 0x10
    u8 unk11;
    u8 hardwareError;
    u8 unk13;
    u8 queueFull; // 0x14
    u8 unk15;
    u16 checksum; // 0x16
    u8 sendCmdIndex; // 0x18
    u8 recvCmdIndex; // 0x19
    u8 filler1A[0x1C-0x1A]; // 0x1A

    struct SendQueue sendQueue;
    struct RecvQueue recvQueue;
};
extern struct Link gUnknown_0202BF20; // gLink

extern u8 gUnknown_02002820; // sChecksumAvailable
extern u16 gUnknown_02002822; // gLinkSavedIme
extern u8 gUnknown_02002824; // sNumVBlanksWithoutSerialIntr
extern u8 gUnknown_02002826;
extern u16 gUnknown_02002828; // sSendNonzeroCheck
extern u16 gUnknown_0200282A;
extern u8  gUnknown_02019C2C; // gLastSendQueueCount
extern s8 gUnknown_0202C5E0;
extern u8 gUnknown_02002825; // sSendBufferEmpty
extern u8 gUnknown_02002827; // sHandshakePlayerCount ?
extern u8 gUnknown_0202A554; // ???
extern u8 gUnknown_0202BEC8;


#define MASTER_HANDSHAKE  0x8FFF
#define SLAVE_HANDSHAKE   0xD13B
//#define EREADER_HANDSHAKE 0xCCD0

#define SIO_MULTI_CNT ((struct SioMultiCnt *)REG_ADDR_SIOCNT)

#define EnableInterrupts(interrupts) \
{ \
    gUnknown_02002822 = REG_IME; \
    REG_IME = 0; \
    REG_IE |= (interrupts); \
    REG_IME = gUnknown_02002822; \
}

#define DisableInterrupts(interrupts) \
{ \
    gUnknown_02002822 = REG_IME; \
    REG_IME = 0; \
    REG_IE &= ~(interrupts); \
    REG_IME = gUnknown_02002822; \
}

void sub_1884(void) // EnableSerial
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_115200_BPS | SIO_INTR_ENABLE;

    gUnknown_02002822 = REG_IME;
    SetMainCallback(sub_19CC+1);
    SetVBlankIntrFunc(sub_1A78+1);
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = gUnknown_02002822;
    
    REG_SIOMLT_SEND = 0; // TODO correct register name?
    *((u64 *) REG_ADDR_SIOMULTI0) = 0;
    CpuFill32(0, &gUnknown_0202BF20, sizeof(gUnknown_0202BF20));

    gUnknown_02002824 = 0;
    gUnknown_02002825 = 0;
    gUnknown_02002827 = 0;
    gUnknown_02019C2C = 0;
    gUnknown_0202A554 = 0;
    gUnknown_0202C5E0 = 0;
    gUnknown_0202ADD0 = 0;
    gUnknown_0201A444 = 0;
    gUnknown_0202BDF0 = 0;
    gUnknown_0201C1AC = 0;
    gUnknown_0202ADDC = 0;
    gUnknown_0202BEC8 = 0;
    gUnknown_02002820 = 0;
    gUnknown_02002828 = 0;
    gUnknown_0200282A = 0;
}

void sub_19B4(void) // TODO
{
    sub_24DC();
    sub_250C();
    sub_1884();
    sub_1AA4();
}

void sub_19CC(void) // TODO
{
    if ((REG_DISPSTAT & 0x8) != 0)
    {
        CpuSet(gOamBuffer, (void *) 0x7000000, 0x200);
        REG_DISPCNT = gMain.unk16;
        
        REG_BG0HOFS = gMain.unk2E8[0].unk0;
        REG_BG0VOFS = gMain.unk2E8[0].unk2;
        REG_BG1HOFS = gMain.unk2E8[1].unk0;
        REG_BG1VOFS = gMain.unk2E8[1].unk2;
        REG_BG2HOFS = gMain.unk2E8[2].unk0;
        REG_BG2VOFS = gMain.unk2E8[2].unk2;
        REG_BG3HOFS = gMain.unk2E8[3].unk0;
        REG_BG3VOFS = gMain.unk2E8[3].unk2;

        if (gMain.unk36)
        {
            REG_BLDCNT = gMain.blendControl;
            REG_BLDALPHA = gMain.blendAlpha;
            REG_BLDY = gMain.blendBrightness;
        }

        VBlankIntrWait();
    }

    m4aSoundMain();
}

void sub_1A78(void) // VBlankIntr
{
    sub_1EC0();
    m4aSoundVSync();
    REG_IME = 0;
    INTR_CHECK |= INTR_FLAG_VBLANK;
    REG_IME = 1;
}

void nullsub_15(void)
{
}

void sub_1AA4(void) // TODO DisableSerial?
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);

    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = 0xC0;

    CpuFill32(0, &gUnknown_0202BF20, sizeof(gUnknown_0202BF20)); // TODO off by 4 error?
}

s32 sub_1B04(u8 *shouldAdvanceLinkState, s16 *sendCmd, u16 (*recvCmds)[MAX_LINK_PLAYERS]) // LinkMain1
{
    u32 retVal;

    switch (gUnknown_0202BF20.state)
    {
        case LINK_STATE_START0:
            sub_1AA4();
            gUnknown_0202BF20.state = 1;
            break;
        case LINK_STATE_START1:
            sub_1884();
            gUnknown_0202BF20.state = 2;
            break;
        case LINK_STATE_HANDSHAKE:
            switch (*shouldAdvanceLinkState)
            {
                default:
                    sub_1C5C();
                    if (gUnknown_0202C5E0 == 0 && gUnknown_0202BF20.isMaster && gUnknown_0202BF20.playerCount == 2)
                    {
                        gUnknown_0202BF20.handshakeAsMaster = TRUE;
                        gUnknown_0202C5E0 = -1;
                    }
                    break;
                case 1:
                    if (gUnknown_0202BF20.isMaster != LINK_SLAVE && gUnknown_0202BF20.playerCount == 2)
                        gUnknown_0202BF20.handshakeAsMaster = TRUE;
                    gUnknown_0202C5E0 = -1;
                    break;
                case 2:
                    gUnknown_0202BF20.state = LINK_STATE_START0;
                    REG_SIOMLT_SEND = 0;
                    break;
            }
            break;
        case LINK_STATE_INIT_TIMER:
            sub_1C84();
            gUnknown_0202BF20.state = LINK_STATE_CONN_ESTABLISHED;
            // fallthrough
        case LINK_STATE_CONN_ESTABLISHED:
            if (gUnknown_0202BF20.unkE == 0)
            {
                sub_1CD4(sendCmd);
            }
            sub_1DB8(recvCmds);
            break;
    }
    *shouldAdvanceLinkState = 0;
    retVal = gUnknown_0202BF20.localId;
    retVal |= (gUnknown_0202BF20.playerCount << LINK_STAT_PLAYER_COUNT_SHIFT);
    if (gUnknown_0202BF20.isMaster == LINK_MASTER)
    {
        retVal |= LINK_STAT_MASTER;
    }

    {
        u32 receivedNothing = gUnknown_0202BF20.receivedNothing << 8;
        u32 unk11 = gUnknown_0202BF20.unk11 << 9;
        u32 hardwareError = gUnknown_0202BF20.hardwareError << 0x10;
        u32 unk13 = gUnknown_0202BF20.unk13 << 0x11;
        u32 queueFull = gUnknown_0202BF20.queueFull << 0x12;
        u32 unk15 = gUnknown_0202BF20.unk15 << 0x14;
        u32 val;

        if (gUnknown_0202BF20.state == LINK_STATE_CONN_ESTABLISHED)
        {
            val = LINK_STAT_CONN_ESTABLISHED;
            val |= receivedNothing;
            val |= retVal;
            val |= unk11;
            val |= hardwareError;
            val |= unk13;
            val |= queueFull;
            val |= unk15;
        }
        else
        {
            val = retVal;
            val |= receivedNothing;
            val |= unk11;
            val |= hardwareError;
            val |= unk13;
            val |= queueFull;
            val |= unk15;
        }

        retVal = val;
    }

    if (gUnknown_0202BF20.localId >= MAX_LINK_PLAYERS)
        retVal |= 0x80 << 0xF;


    return retVal;
}

void sub_1C5C(void) // CheckMasterOrSlave
{
    u32 terminals;
    terminals = *(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SD | SIO_MULTI_SI);
    
    if (terminals == SIO_MULTI_SD && gUnknown_0202BF20.localId == 0)
    {
        gUnknown_0202BF20.isMaster = 8;
    }
    else
    {
        gUnknown_0202BF20.isMaster = 0;
    }
}

void sub_1C84(void) // InitTimer
{
    if (gUnknown_0202BF20.isMaster)
    {
        REG_TM3CNT_L = -197;
        REG_TM3CNT_H = TIMER_64CLK | TIMER_INTR_ENABLE;

        EnableInterrupts(INTR_FLAG_TIMER3);
    }
}

void sub_1CD4(u16 *sendCmd) // EnqueueSendCmd
{
    u8 i;
    u8 offset;

    gUnknown_02002822 = REG_IME;
    REG_IME = 0;
    
    if (gUnknown_0202BF20.sendQueue.count < QUEUE_CAPACITY)
    {
        offset = gUnknown_0202BF20.sendQueue.pos + gUnknown_0202BF20.sendQueue.count;
        if (offset >= QUEUE_CAPACITY)
        {
            offset -= QUEUE_CAPACITY;
        }
        for (i = 0; i < CMD_LENGTH; i++)
        {
            gUnknown_02002828 |= *sendCmd;
            gUnknown_0202BF20.sendQueue.data[i][offset] = *sendCmd;
            *sendCmd = 0;
            sendCmd++;
        }
    }
    else
    {
        gUnknown_0202BF20.queueFull |= QUEUE_FULL_SEND;
    }

    if (gUnknown_02002828)
    {
        gUnknown_0202BF20.sendQueue.count++;
        gUnknown_02002828 = 0;
    }

    REG_IME = gUnknown_02002822;
    gUnknown_02019C2C = gUnknown_0202BF20.sendQueue.count;
}

void sub_1DB8(u16 (*recvCmds)[MAX_LINK_PLAYERS]) // DequeueRecvCmds
{
    u8 i;
    u8 j;

    gUnknown_02002822 = REG_IME;
    REG_IME = 0;

    if (gUnknown_0202BF20.recvQueue.count == 0)
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gUnknown_0202BF20.playerCount; j++)
            {
                recvCmds[i][j] = 0;
            }
        }

        gUnknown_0202BF20.receivedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gUnknown_0202BF20.playerCount; j++)
            {
                recvCmds[i][j] = gUnknown_0202BF20.recvQueue.data[j][i][gUnknown_0202BF20.recvQueue.pos];
            }
        }
        gUnknown_0202BF20.recvQueue.count--;
        gUnknown_0202BF20.recvQueue.pos++;
        if (gUnknown_0202BF20.recvQueue.pos >= QUEUE_CAPACITY)
        {
            gUnknown_0202BF20.recvQueue.pos = 0;
        }
        gUnknown_0202BF20.receivedNothing = FALSE;
    }

    REG_IME = gUnknown_02002822;
}

void sub_1EC0(void) // LinkVSync
{
    if (gUnknown_0202BF20.unkE)
    {
        if (--gUnknown_02002826 != 0)
        {
            return;
        }
        gUnknown_0202BF20.unkE = 0;
    }

    if (gUnknown_0202BF20.isMaster)
    {
        switch (gUnknown_0202BF20.state)
        {
            case LINK_STATE_CONN_ESTABLISHED:
                if (gUnknown_0202BF20.serialIntrCounter < 9)
                {
                    if (!gUnknown_0202BF20.hardwareError)
                    {
                        gUnknown_0202BF20.unk15 = LAG_MASTER;
                    }
                    else
                    {
                        sub_1FEC();
                    }
                }
                else if (gUnknown_0202BF20.unk15 == LAG_NONE)
                {
                    gUnknown_0202BF20.serialIntrCounter = 0;
                    sub_1FEC();
                }
                break;
            case LINK_STATE_HANDSHAKE:
                sub_1FEC();
                break;
        }
    }
    else if (gUnknown_0202BF20.state == LINK_STATE_CONN_ESTABLISHED || gUnknown_0202BF20.state == LINK_STATE_HANDSHAKE)
    {
        if (++gUnknown_02002824 > 6)
        {
            if (gUnknown_0202BF20.state == LINK_STATE_CONN_ESTABLISHED)
            {
                gUnknown_0202BF20.unk15 = LAG_SLAVE;
            }
            if (gUnknown_0202BF20.state == LINK_STATE_HANDSHAKE)
            {
                gUnknown_0202BF20.localId = 0;
                gUnknown_0202BF20.playerCount = 0;
                gUnknown_0202BF20.unk11 = FALSE;
            }
        }
    }
}

void sub_1F4C(void) // Timer3Init
{
    sub_2308();
    sub_1FEC();
}

void sub_1F5C(void) // SerialCB
{
    u32 temp;
    temp = *((u32*) REG_ADDR_SIOCNT);
    gUnknown_0202BF20.localId = (temp << 0x1A) >> 0x1E; // TODO fakenatch?
    switch (gUnknown_0202BF20.state)
    {
        case LINK_STATE_CONN_ESTABLISHED:
            if (temp & 0x40)
            {
                gUnknown_0202BF20.hardwareError = 1;
            }
            sub_20FC();
            sub_223C();
            sub_2338();
            break;
        case LINK_STATE_HANDSHAKE:
            if (sub_1FFC())
            {
                if (gUnknown_0202BF20.isMaster)
                {
                    gUnknown_0202BF20.state = LINK_STATE_INIT_TIMER;
                    gUnknown_0202BF20.serialIntrCounter = 8;
                }
                else
                {
                    gUnknown_0202BF20.state = LINK_STATE_CONN_ESTABLISHED;
                }
            }
            break;
    }
    gUnknown_0202BF20.serialIntrCounter++;
    gUnknown_02002824 = 0;
    if (gUnknown_0202BF20.serialIntrCounter == 8)
    {
        gUnknown_0202A554 = gUnknown_0202BF20.recvQueue.count;
    }
}

void sub_1FEC(void) // StartTransfer
{
    REG_SIOCNT |= SIO_START;
}

bool8 sub_1FFC(void) // DoHandshake
{
    u8 i;
    u8 playerCount;
    u16 minRecv;

    playerCount = 0;
    minRecv = 0xFFFF;
    if (gUnknown_0202BF20.handshakeAsMaster == TRUE)
    {
        REG_SIOMLT_SEND = MASTER_HANDSHAKE;
    }
    else
    {
        REG_SIOMLT_SEND = SLAVE_HANDSHAKE;
    }
    gUnknown_0202BF20.handshakeAsMaster = FALSE;
    *(u64 *)gUnknown_0202BF20.handshakeBuffer = REG_SIOMLT_RECV;
    //REG_SIOMLT_RECV = 0;
    
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if ((gUnknown_0202BF20.handshakeBuffer[i] & ~0x3) == (SLAVE_HANDSHAKE & ~3) || gUnknown_0202BF20.handshakeBuffer[i] == MASTER_HANDSHAKE)
        {
            playerCount++;
            if (minRecv > gUnknown_0202BF20.handshakeBuffer[i] && gUnknown_0202BF20.handshakeBuffer[i] != 0)
                minRecv = gUnknown_0202BF20.handshakeBuffer[i];
        }
        else
        {
            if (gUnknown_0202BF20.handshakeBuffer[i] != 0xFFFF)
            {
                playerCount = 0;
                break;
            }
            if (i == gUnknown_0202BF20.localId) // TODO check order
            {
                playerCount = 0;
            }
        }
    }
    gUnknown_0202BF20.playerCount = playerCount;
    if (gUnknown_0202BF20.playerCount == 2 && gUnknown_0202BF20.playerCount == gUnknown_02002827 && gUnknown_0202BF20.handshakeBuffer[0] == MASTER_HANDSHAKE)
    {
        return TRUE;
    }
    if (gUnknown_0202BF20.playerCount == 2) // ???
    {
        gUnknown_0202BF20.unk11 = (minRecv & 3) + 1;
    }
    else
    {
        gUnknown_0202BF20.unk11 = 0;
    }
    gUnknown_02002827 = gUnknown_0202BF20.playerCount;
    return FALSE;
}

void sub_20FC(void) // DoRecv
{
    u16 recv[4];
    u8 i;
    u8 index;

    *(u64 *)recv = REG_SIOMLT_RECV;
    if (gUnknown_0202BF20.sendCmdIndex == 0)
    {
        for (i = 0; i < gUnknown_0202BF20.playerCount; i++)
        {
            if (gUnknown_0202BF20.checksum != recv[i] && gUnknown_02002820)
            {
                gUnknown_0202BF20.unk13 = TRUE;
            }
        }
        gUnknown_0202BF20.checksum = 0;
        gUnknown_02002820 = TRUE;
    }
    else
    {
        index = gUnknown_0202BF20.recvQueue.pos + gUnknown_0202BF20.recvQueue.count;
        if (index >= QUEUE_CAPACITY)
        {
            index -= QUEUE_CAPACITY;
        }
        if (gUnknown_0202BF20.recvQueue.count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gUnknown_0202BF20.playerCount; i++)
            {
                gUnknown_0202BF20.checksum += recv[i];
                gUnknown_0200282A |= recv[i];
                gUnknown_0202BF20.recvQueue.data[i][gUnknown_0202BF20.recvCmdIndex][index] = recv[i];
                if ((gUnknown_0202BF20.sendCmdIndex == 1) && (gUnknown_0202BF20.unkE == 0) && ((recv[i] & 0xF) == 1))
                {
                    gUnknown_0202BF20.unkE = 1;
                    gUnknown_02002826 = 5;
                }
            }
        }
        else
        {
            gUnknown_0202BF20.queueFull |= QUEUE_FULL_RECV;
        }
        gUnknown_0202BF20.recvCmdIndex++;
        if (gUnknown_0202BF20.recvCmdIndex == CMD_LENGTH && gUnknown_0200282A)
        {
            gUnknown_0202BF20.recvQueue.count++;
            gUnknown_0200282A = 0;
        }
    }
}

void sub_223C(void) // DoSend
{
    if (gUnknown_0202BF20.sendCmdIndex == CMD_LENGTH)
    {
        REG_SIOMLT_SEND = gUnknown_0202BF20.checksum;
        if (!gUnknown_02002825)
        {
            gUnknown_0202BF20.sendQueue.count--;
            gUnknown_0202BF20.sendQueue.pos++;
            if (gUnknown_0202BF20.sendQueue.pos >= QUEUE_CAPACITY)
            {
                gUnknown_0202BF20.sendQueue.pos = 0;
            }
        }
        else
        {
            gUnknown_02002825 = FALSE;
        }
    }
    else
    {
        if (gUnknown_0202BF20.sendCmdIndex == 0 && gUnknown_0202BF20.sendQueue.count == 0)
        {
            gUnknown_02002825 = TRUE;
        }
        if (gUnknown_02002825)
        {
            REG_SIOMLT_SEND = 0;
        }
        else
        {
            REG_SIOMLT_SEND = gUnknown_0202BF20.sendQueue.data[gUnknown_0202BF20.sendCmdIndex][gUnknown_0202BF20.sendQueue.pos];
        }
        if ((gUnknown_0202BF20.unkE == 0) && (gUnknown_0202BF20.sendCmdIndex == 0) && (3 < gUnknown_0202BF20.recvQueue.count)) {
            REG_SIOMLT_SEND |= 1; // TODO
        }
        gUnknown_0202BF20.sendCmdIndex++;
    }
}

void sub_2308(void) // StopTimer
{
    if (gUnknown_0202BF20.isMaster)
    {
        REG_TM3CNT_H &= ~TIMER_ENABLE;
        REG_TM3CNT_L = -197;
    }
}

void sub_2338(void) // SendRecvDone
{
    if (gUnknown_0202BF20.recvCmdIndex == CMD_LENGTH)
    {
        gUnknown_0202BF20.sendCmdIndex = 0;
        gUnknown_0202BF20.recvCmdIndex = 0;
    }
    else if (gUnknown_0202BF20.isMaster)
    {
        REG_TM3CNT_H |= TIMER_ENABLE;
    }
}

void sub_2364(void) // ResetSendBuffer
{
    u8 i;
    u8 j;

    gUnknown_0202BF20.sendQueue.count = 0;
    gUnknown_0202BF20.sendQueue.pos = 0;
    for (i = 0; i < CMD_LENGTH; i++)
    {
        for (j = 0; j < QUEUE_CAPACITY; j++)
        {
            gUnknown_0202BF20.sendQueue.data[i][j] = LINKCMD_NONE;
        }
    }
}

void sub_23B4(void) // ResetRecvBuffer
{
    u8 i;
    u8 j;
    u8 k;

    gUnknown_0202BF20.recvQueue.count = 0;
    gUnknown_0202BF20.recvQueue.pos = 0;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
        {
            for (k = 0; k < QUEUE_CAPACITY; k++)
            {
                gUnknown_0202BF20.recvQueue.data[i][j][k] = LINKCMD_NONE;
            }
        }
    }
}
