#include "constants/bg_music.h"
#include "main.h"
#include "global.h"

void sub_11C14(s32);
void sub_12524();
void sub_12BF8();
void sub_11C14();

//Some kind of init function?
void sub_11B9C(void){
    s16 i;
    if (gMain.unk6 == 0){
        gCurrentPinballGame->selection = gCurrentPinballGame->array[0];
        sub_11C14(0);
        sub_12524();
    }else{
        i = 0;
        for (; i < 2; i++) {
            gCurrentPinballGame->selection = gCurrentPinballGame->array[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
    return;
}
