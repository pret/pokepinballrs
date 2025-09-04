// include macros
#include "global.h"
#include "link.h"
#include "m4a.h"
#include "main.h"

// "static" define macros
#define LINKCMD_NONE 0xEFFF
#define MASTER_HANDSHAKE  0x8FFF
#define SLAVE_HANDSHAKE   0xD13B
//#define EREADER_HANDSHAKE 0xCCD0

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

#define SIO_MULTI_CNT ((struct SioMultiCnt *)REG_ADDR_SIOCNT)

#define EnableInterrupts(interrupts) \
{ \
    gLinkSavedIme = REG_IME; \
    REG_IME = 0; \
    REG_IE |= (interrupts); \
    REG_IME = gLinkSavedIme; \
}

#define DisableInterrupts(interrupts) \
{ \
    gLinkSavedIme = REG_IME; \
    REG_IME = 0; \
    REG_IE &= ~(interrupts); \
    REG_IME = gLinkSavedIme; \
}

// "static" enums
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

// "static" struct definitions

// static function declarations
static void EnableSerial(void);
static void sub_19CC(void);
static void LinkVBlankIntr(void);
static void nullsub_15(void);
static void CheckMasterOrSlave(void);
static void InitTimer(void);
static void EnqueueSendCmd(u16 *);
static void DequeueRecvCmds(u16 (*recvCmds)[MAX_LINK_PLAYERS]);
static void LinkVSync(void);
static void StartTransfer(void);
static bool8 DoHandshake(void);
static void DoRecv(void);
static void DoSend(void);
static void StopTimer(void);
static void SendRecvDone(void);
static void ResetSendBuffer(void);
static void ResetRecvBuffer(void);

// static IWRAM variable declarations

// static EWRAM variable declarations
// TODO fix bss discard nonsense
extern u8 sChecksumAvailable;
extern u16 gLinkSavedIme;
extern u8 sNumVBlanksWithoutSerialIntr;
extern u8 sSendBufferEmpty;
extern u8 gUnknown_02002826;
extern u8 gUnknown_02002827; // sHandshakePlayerCount ?
extern u16 sSendNonzeroCheck;
extern u16 gUnknown_0200282A;
extern u8 gLastSendQueueCount;
extern u8 gUnknown_0202A554; // ???
extern s8 gUnknown_0202C5E0;

// static const definitions

// function definitions
static void EnableSerial(void)
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_115200_BPS | SIO_INTR_ENABLE;

    gLinkSavedIme = REG_IME;
    SetMainCallback(sub_19CC);
    SetVBlankIntrFunc(LinkVBlankIntr);
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = gLinkSavedIme;

    REG_SIOMLT_SEND = 0; // TODO correct register name?
    *((u64 *) REG_ADDR_SIOMULTI0) = 0;
    CpuFill32(0, &gLink, sizeof(gLink));

    sNumVBlanksWithoutSerialIntr = 0;
    sSendBufferEmpty = 0;
    gUnknown_02002827 = 0;
    gLastSendQueueCount = 0;
    gUnknown_0202A554 = 0;
    gUnknown_0202C5E0 = 0;
    gUnknown_0202ADD0 = 0;
    gUnknown_0201A444 = 0;
    gUnknown_0202BDF0 = 0;
    gUnknown_0201C1AC = 0;
    gUnknown_0202ADDC = 0;
    gUnknown_0202BEC8 = 0;
    sChecksumAvailable = 0;
    sSendNonzeroCheck = 0;
    gUnknown_0200282A = 0;
}

extern void sub_19B4(void) // TODO
{
    sub_24DC();
    sub_250C();
    EnableSerial();
    DisableSerial();
}

static void sub_19CC(void) // TODO
{
    if ((REG_DISPSTAT & 0x8) != 0)
    {
        CpuSet(gOamBuffer, (void *) 0x7000000, 0x200);
        REG_DISPCNT = gMain.dispcntBackup;

        REG_BG0HOFS = gMain.bgOffsets[0].xOffset;
        REG_BG0VOFS = gMain.bgOffsets[0].yOffset;
        REG_BG1HOFS = gMain.bgOffsets[1].xOffset;
        REG_BG1VOFS = gMain.bgOffsets[1].yOffset;
        REG_BG2HOFS = gMain.bgOffsets[2].xOffset;
        REG_BG2VOFS = gMain.bgOffsets[2].yOffset;
        REG_BG3HOFS = gMain.bgOffsets[3].xOffset;
        REG_BG3VOFS = gMain.bgOffsets[3].yOffset;

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

static void LinkVBlankIntr(void)
{
    LinkVSync();
    m4aSoundVSync();
    REG_IME = 0;
    INTR_CHECK |= INTR_FLAG_VBLANK;
    REG_IME = 1;
}

static void nullsub_15(void)
{
}

extern void DisableSerial(void)
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);

    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = 0xC0;

    CpuFill32(0, &gLink, sizeof(gLink));
}

extern s32 LinkMain1(u8 *shouldAdvanceLinkState, s16 *sendCmd, u16 (*recvCmds)[MAX_LINK_PLAYERS])
{
    u32 retVal;

    switch (gLink.state)
    {
        case LINK_STATE_START0:
            DisableSerial();
            gLink.state = 1;
            break;
        case LINK_STATE_START1:
            EnableSerial();
            gLink.state = 2;
            break;
        case LINK_STATE_HANDSHAKE:
            switch (*shouldAdvanceLinkState)
            {
                default:
                    CheckMasterOrSlave();
                    if (gUnknown_0202C5E0 == 0 && gLink.isMaster && gLink.playerCount == 2)
                    {
                        gLink.handshakeAsMaster = TRUE;
                        gUnknown_0202C5E0 = -1;
                    }
                    break;
                case 1:
                    if (gLink.isMaster != LINK_SLAVE && gLink.playerCount == 2)
                        gLink.handshakeAsMaster = TRUE;
                    gUnknown_0202C5E0 = -1;
                    break;
                case 2:
                    gLink.state = LINK_STATE_START0;
                    REG_SIOMLT_SEND = 0;
                    break;
            }
            break;
        case LINK_STATE_INIT_TIMER:
            InitTimer();
            gLink.state = LINK_STATE_CONN_ESTABLISHED;
            // fallthrough
        case LINK_STATE_CONN_ESTABLISHED:
            if (gLink.unkE == 0)
            {
                EnqueueSendCmd(sendCmd);
            }
            DequeueRecvCmds(recvCmds);
            break;
    }
    *shouldAdvanceLinkState = 0;
    retVal = gLink.localId;
    retVal |= (gLink.playerCount << LINK_STAT_PLAYER_COUNT_SHIFT);
    if (gLink.isMaster == LINK_MASTER)
    {
        retVal |= LINK_STAT_MASTER;
    }

    {
        u32 receivedNothing = gLink.receivedNothing << 8;
        u32 unk11 = gLink.unk11 << 9;
        u32 hardwareError = gLink.hardwareError << 0x10;
        u32 unk13 = gLink.unk13 << 0x11;
        u32 queueFull = gLink.queueFull << 0x12;
        u32 unk15 = gLink.unk15 << 0x14;
        u32 val;

        if (gLink.state == LINK_STATE_CONN_ESTABLISHED)
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

    if (gLink.localId >= MAX_LINK_PLAYERS)
        retVal |= 0x80 << 0xF;


    return retVal;
}

static void CheckMasterOrSlave(void)
{
    u32 terminals;
    terminals = *(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SD | SIO_MULTI_SI);

    if (terminals == SIO_MULTI_SD && gLink.localId == 0)
    {
        gLink.isMaster = 8;
    }
    else
    {
        gLink.isMaster = 0;
    }
}

static void InitTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_L = -197;
        REG_TM3CNT_H = TIMER_64CLK | TIMER_INTR_ENABLE;

        EnableInterrupts(INTR_FLAG_TIMER3);
    }
}

static void EnqueueSendCmd(u16 *sendCmd)
{
    u8 i;
    u8 offset;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;

    if (gLink.sendQueue.count < QUEUE_CAPACITY)
    {
        offset = gLink.sendQueue.pos + gLink.sendQueue.count;
        if (offset >= QUEUE_CAPACITY)
        {
            offset -= QUEUE_CAPACITY;
        }
        for (i = 0; i < CMD_LENGTH; i++)
        {
            sSendNonzeroCheck |= *sendCmd;
            gLink.sendQueue.data[i][offset] = *sendCmd;
            *sendCmd = 0;
            sendCmd++;
        }
    }
    else
    {
        gLink.queueFull |= QUEUE_FULL_SEND;
    }

    if (sSendNonzeroCheck)
    {
        gLink.sendQueue.count++;
        sSendNonzeroCheck = 0;
    }

    REG_IME = gLinkSavedIme;
    gLastSendQueueCount = gLink.sendQueue.count;
}

static void DequeueRecvCmds(u16 (*recvCmds)[MAX_LINK_PLAYERS])
{
    u8 i;
    u8 j;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;

    if (gLink.recvQueue.count == 0)
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gLink.playerCount; j++)
            {
                recvCmds[i][j] = 0;
            }
        }

        gLink.receivedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gLink.playerCount; j++)
            {
                recvCmds[i][j] = gLink.recvQueue.data[j][i][gLink.recvQueue.pos];
            }
        }
        gLink.recvQueue.count--;
        gLink.recvQueue.pos++;
        if (gLink.recvQueue.pos >= QUEUE_CAPACITY)
        {
            gLink.recvQueue.pos = 0;
        }
        gLink.receivedNothing = FALSE;
    }

    REG_IME = gLinkSavedIme;
}

static void LinkVSync(void)
{
    if (gLink.unkE)
    {
        if (--gUnknown_02002826 != 0)
        {
            return;
        }
        gLink.unkE = 0;
    }

    if (gLink.isMaster)
    {
        switch (gLink.state)
        {
            case LINK_STATE_CONN_ESTABLISHED:
                if (gLink.serialIntrCounter < 9)
                {
                    if (!gLink.hardwareError)
                    {
                        gLink.unk15 = LAG_MASTER;
                    }
                    else
                    {
                        StartTransfer();
                    }
                }
                else if (gLink.unk15 == LAG_NONE)
                {
                    gLink.serialIntrCounter = 0;
                    StartTransfer();
                }
                break;
            case LINK_STATE_HANDSHAKE:
                StartTransfer();
                break;
        }
    }
    else if (gLink.state == LINK_STATE_CONN_ESTABLISHED || gLink.state == LINK_STATE_HANDSHAKE)
    {
        if (++sNumVBlanksWithoutSerialIntr > 6)
        {
            if (gLink.state == LINK_STATE_CONN_ESTABLISHED)
            {
                gLink.unk15 = LAG_SLAVE;
            }
            if (gLink.state == LINK_STATE_HANDSHAKE)
            {
                gLink.localId = 0;
                gLink.playerCount = 0;
                gLink.unk11 = FALSE;
            }
        }
    }
}

extern void Timer3Init(void)
{
    StopTimer();
    StartTransfer();
}

extern void SerialCB(void)
{
    u32 temp;
    temp = *((u32*) REG_ADDR_SIOCNT);
    gLink.localId = (temp << 0x1A) >> 0x1E; // TODO fakenatch?
    switch (gLink.state)
    {
        case LINK_STATE_CONN_ESTABLISHED:
            if (temp & 0x40)
            {
                gLink.hardwareError = 1;
            }
            DoRecv();
            DoSend();
            SendRecvDone();
            break;
        case LINK_STATE_HANDSHAKE:
            if (DoHandshake())
            {
                if (gLink.isMaster)
                {
                    gLink.state = LINK_STATE_INIT_TIMER;
                    gLink.serialIntrCounter = 8;
                }
                else
                {
                    gLink.state = LINK_STATE_CONN_ESTABLISHED;
                }
            }
            break;
    }
    gLink.serialIntrCounter++;
    sNumVBlanksWithoutSerialIntr = 0;
    if (gLink.serialIntrCounter == 8)
    {
        gUnknown_0202A554 = gLink.recvQueue.count;
    }
}

static void StartTransfer(void)
{
    REG_SIOCNT |= SIO_START;
}

static bool8 DoHandshake(void)
{
    u8 i;
    u8 playerCount;
    u16 minRecv;

    playerCount = 0;
    minRecv = 0xFFFF;
    if (gLink.handshakeAsMaster == TRUE)
    {
        REG_SIOMLT_SEND = MASTER_HANDSHAKE;
    }
    else
    {
        REG_SIOMLT_SEND = SLAVE_HANDSHAKE;
    }
    gLink.handshakeAsMaster = FALSE;
    *(u64 *)gLink.handshakeBuffer = REG_SIOMLT_RECV;
    //REG_SIOMLT_RECV = 0;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if ((gLink.handshakeBuffer[i] & ~0x3) == (SLAVE_HANDSHAKE & ~3) || gLink.handshakeBuffer[i] == MASTER_HANDSHAKE)
        {
            playerCount++;
            if (minRecv > gLink.handshakeBuffer[i] && gLink.handshakeBuffer[i] != 0)
                minRecv = gLink.handshakeBuffer[i];
        }
        else
        {
            if (gLink.handshakeBuffer[i] != 0xFFFF)
            {
                playerCount = 0;
                break;
            }
            if (i == gLink.localId) // TODO check order
            {
                playerCount = 0;
            }
        }
    }
    gLink.playerCount = playerCount;
    if (gLink.playerCount == 2 && gLink.playerCount == gUnknown_02002827 && gLink.handshakeBuffer[0] == MASTER_HANDSHAKE)
    {
        return TRUE;
    }
    if (gLink.playerCount == 2) // ???
    {
        gLink.unk11 = (minRecv & 3) + 1;
    }
    else
    {
        gLink.unk11 = 0;
    }
    gUnknown_02002827 = gLink.playerCount;
    return FALSE;
}

static void DoRecv(void)
{
    u16 recv[4];
    u8 i;
    u8 index;

    *(u64 *)recv = REG_SIOMLT_RECV;
    if (gLink.sendCmdIndex == 0)
    {
        for (i = 0; i < gLink.playerCount; i++)
        {
            if (gLink.checksum != recv[i] && sChecksumAvailable)
            {
                gLink.unk13 = TRUE;
            }
        }
        gLink.checksum = 0;
        sChecksumAvailable = TRUE;
    }
    else
    {
        index = gLink.recvQueue.pos + gLink.recvQueue.count;
        if (index >= QUEUE_CAPACITY)
        {
            index -= QUEUE_CAPACITY;
        }
        if (gLink.recvQueue.count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gLink.playerCount; i++)
            {
                gLink.checksum += recv[i];
                gUnknown_0200282A |= recv[i];
                gLink.recvQueue.data[i][gLink.recvCmdIndex][index] = recv[i];
                if ((gLink.sendCmdIndex == 1) && (gLink.unkE == 0) && ((recv[i] & 0xF) == 1))
                {
                    gLink.unkE = 1;
                    gUnknown_02002826 = 5;
                }
            }
        }
        else
        {
            gLink.queueFull |= QUEUE_FULL_RECV;
        }
        gLink.recvCmdIndex++;
        if (gLink.recvCmdIndex == CMD_LENGTH && gUnknown_0200282A)
        {
            gLink.recvQueue.count++;
            gUnknown_0200282A = 0;
        }
    }
}

static void DoSend(void)
{
    if (gLink.sendCmdIndex == CMD_LENGTH)
    {
        REG_SIOMLT_SEND = gLink.checksum;
        if (!sSendBufferEmpty)
        {
            gLink.sendQueue.count--;
            gLink.sendQueue.pos++;
            if (gLink.sendQueue.pos >= QUEUE_CAPACITY)
            {
                gLink.sendQueue.pos = 0;
            }
        }
        else
        {
            sSendBufferEmpty = FALSE;
        }
    }
    else
    {
        if (gLink.sendCmdIndex == 0 && gLink.sendQueue.count == 0)
        {
            sSendBufferEmpty = TRUE;
        }
        if (sSendBufferEmpty)
        {
            REG_SIOMLT_SEND = 0;
        }
        else
        {
            REG_SIOMLT_SEND = gLink.sendQueue.data[gLink.sendCmdIndex][gLink.sendQueue.pos];
        }
        if ((gLink.unkE == 0) && (gLink.sendCmdIndex == 0) && (3 < gLink.recvQueue.count)) {
            REG_SIOMLT_SEND |= 1; // TODO
        }
        gLink.sendCmdIndex++;
    }
}

static void StopTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_H &= ~TIMER_ENABLE;
        REG_TM3CNT_L = -197;
    }
}

static void SendRecvDone(void)
{
    if (gLink.recvCmdIndex == CMD_LENGTH)
    {
        gLink.sendCmdIndex = 0;
        gLink.recvCmdIndex = 0;
    }
    else if (gLink.isMaster)
    {
        REG_TM3CNT_H |= TIMER_ENABLE;
    }
}

// TODO Unused?
static void ResetSendBuffer(void)
{
    u8 i;
    u8 j;

    gLink.sendQueue.count = 0;
    gLink.sendQueue.pos = 0;
    for (i = 0; i < CMD_LENGTH; i++)
    {
        for (j = 0; j < QUEUE_CAPACITY; j++)
        {
            gLink.sendQueue.data[i][j] = LINKCMD_NONE;
        }
    }
}

// TODO Unused?
static void ResetRecvBuffer(void)
{
    u8 i;
    u8 j;
    u8 k;

    gLink.recvQueue.count = 0;
    gLink.recvQueue.pos = 0;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
        {
            for (k = 0; k < QUEUE_CAPACITY; k++)
            {
                gLink.recvQueue.data[i][j][k] = LINKCMD_NONE;
            }
        }
    }
}
