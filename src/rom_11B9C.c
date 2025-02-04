#include "constants/bg_music.h"
#include "main.h"
#include "global.h"

void sub_11C14(s32);
void sub_12524(void);
void sub_12BF8(void);

void sub_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->unk132c = gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        sub_12524();
    }else{
        i = 0;
        for (; i < 2; i++)
        {
            gCurrentPinballGame->unk132c = gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
    return;
}
