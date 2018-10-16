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

extern struct Main gMain;
extern StateFunc gMainFuncs[];

void SetMainGameState(u16);

#endif // GUARD_MAIN_H
