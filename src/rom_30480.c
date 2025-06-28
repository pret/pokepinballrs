#include "global.h"
#include "main.h"

void sub_30480(void) {
    gCurrentPinballGame->unk1EC = 1;
    gCurrentPinballGame->unk1EE = 0;
    gCurrentPinballGame->unk1ED = 0;
    gCurrentPinballGame->unk1F0 = 0;
    gCurrentPinballGame->unk1F4 = 0x82 << 4;
    gCurrentPinballGame->unk1F6 = 0x2bc;
}