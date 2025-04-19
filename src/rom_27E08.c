#include "global.h"
#include "main.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gUnknown_081C0064[];

void sub_27E08(void)
{
    s16 i, j;

    gCurrentPinballGame->unk17 = 0;
    gCurrentPinballGame->unk18 = 0;
    gCurrentPinballGame->unk294 = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->unk5A5 = 0;
    gCurrentPinballGame->unk5AA = 0;
    gCurrentPinballGame->unk5A9 = 0;
    gCurrentPinballGame->unk6C6 = 0;
    gCurrentPinballGame->unk6C7 = 0;
    gCurrentPinballGame->unk625 = 0;
    gCurrentPinballGame->unk6CA = 0;
    gCurrentPinballGame->unk6CC = 0;
    gCurrentPinballGame->unk72F = 0;
    gCurrentPinballGame->unk731 = 0;

    if (gCurrentPinballGame->unk29A == 0) {
        gCurrentPinballGame->unk724 = 6000;
    } else {
        gCurrentPinballGame->unk724 = 4200;
    }
    gCurrentPinballGame->unk29A += 1;

    DmaCopy16(3, gUnknown_081C0064, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++) {
        gCurrentPinballGame->unk6CD[i] = i;
    }

    gCurrentPinballGame->unk6C8 = gMain.systemFrameCount % 6;
    gCurrentPinballGame->unk6C9 = 5;

    for (j = gCurrentPinballGame->unk6C8; j < gCurrentPinballGame->unk6C9; j++) {
        gCurrentPinballGame->unk6CD[j] = gCurrentPinballGame->unk6CD[j+1];
    }
}
