#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

typedef void (*StateFunc)(void);

struct Main
{
    /*0x00*/u8 filler0[0x2];
    /*0x02*/u8 mainState;
    /*0x03*/u8 subState;
    /*0x04*/u8 filler4[0x12];
    /*0x16*/u16 unk16;
    /*0x18*/u8 filler18[0x28];
    /*0x40*/int unk40;
};

extern struct Main gMain;
extern StateFunc gMainFuncs[];

#endif // GUARD_MAIN_H
