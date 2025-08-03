#include "global.h"
#include "main.h"

extern u8* gUnknown_086B0B70[][3];

void sub_4F258(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        u8 ** src = gUnknown_086B0B70[i] + gCurrentPinballGame->ballPowerUpLight[i];
        u8 ** dst = gUnknown_086B0B70[i] + 2;
        DmaCopy16(3, *src, *dst, 0x40);
    }
}
