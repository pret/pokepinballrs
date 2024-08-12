// include guard
#ifndef GUARD_LINK_H
#define GUARD_LINK_H

// include macros

// "extern" define macros
#define CMD_LENGTH 8
#define QUEUE_CAPACITY 0x20
#define MAX_LINK_PLAYERS 2

// "extern" enums

// "extern" struct definitions
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

struct Link {
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

// extern function declarations
extern void sub_19B4(void);
extern void sub_1AA4(void);
extern s32 sub_1B04(u8 *shouldAdvanceLinkState, s16 *sendCmd, u16 (*recvCmds)[MAX_LINK_PLAYERS]);
extern void sub_1F4C(void);
extern void sub_1F5C(void);

// extern IWRAM variable declarations

// extern EWRAM variable declarations
extern u8 gUnknown_0202BEC8;
extern struct Link gUnknown_0202BF20; // gLink

// extern const definitions

// end include guard
#endif//GUARD_LINK_H
