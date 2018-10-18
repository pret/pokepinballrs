#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

typedef void (*StateFunc)(void);

struct Main
{
    /*0x00*/ u8 filler0[0x2];
    /*0x02*/ u8 mainState;
    /*0x03*/ u8 subState;
    /*0x04*/ u8 filler4[0x9];
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 fillerE[0x8];
    /*0x16*/ u16 unk16;
    /*0x18*/ u16 newKeys;
    /*0x1A*/ u16 releasedKeys;
    /*0x1C*/ u16 heldKeys;
    /*0x1E*/ u8 filler1E[0x22];
    /*0x40*/ int unk40;
};

struct Unk0200B3B8_2
{

};

struct Unk0200B3B8
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 filler6[0x2];
    u16 unk8;
    u8 fillerA[0xAE];
};

extern struct Main gMain;
extern struct Unk0200B3B8 gUnknown_0200B3B8[];
extern StateFunc gMainFuncs[];

void SetMainGameState(u16);
void sub_24C(void);
void sub_2B4(void);
void sub_D74(void);

#endif // GUARD_MAIN_H
