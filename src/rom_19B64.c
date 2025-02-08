#include "global.h"
#include "main.h"

void sub_19B64(u8 a) {
    gCurrentPinballGame->unk16 = 2;
    gCurrentPinballGame->unk14 = a;
    
    if(gCurrentPinballGame->unk13 == 2) {
        gMain.unk44->unk34->unk0 = 0;
    }
}