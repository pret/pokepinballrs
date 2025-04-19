#include "global.h"
#include "main.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

void sub_27E08(void)
{
    s16 i;
    s8 j;
    struct Unknown volatile *unk;
    u32 unused;

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

    unk = (struct Unknown *) 0x040000D4;
    unk->unk0 = 0x081C0064; //*gUnknown_081C0064;
    unk->unk4 = 0x05000180;
    unk->unk8 = 0x80000010;
    unused = unk->unk8; // unused

    for (i = 0; i < 6; i++) {
        gCurrentPinballGame->unk6CD[i] = i;
    }
    gCurrentPinballGame->unk6C8 = gMain.systemFrameCount % 6;
    gCurrentPinballGame->unk6C9 = 5;

    j = (s8) gCurrentPinballGame->unk6C8;
    while (j < gCurrentPinballGame->unk6C9 /*5*/) {
        gCurrentPinballGame->unk6CD[j] = gCurrentPinballGame->unk6CD[j+1];
        j++;
    }
}
