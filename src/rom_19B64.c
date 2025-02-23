#include "global.h"
#include "main.h"
#include "m4a.h"

void sub_19E10(void);
void sub_19F70(void);
void sub_19FA0(void);

void sub_19B10(void) 
{
    sub_19B90();
    sub_19E10();

    if (gMain.unkF == 0)
    {
        sub_19F70();
    }

    sub_19FA0();
    if (gCurrentPinballGame->unk29C != 0)
    {
        gCurrentPinballGame->unk29C -= 1;
        if (gCurrentPinballGame->unk29C == 0) 
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        }
    }
}

void sub_19B64(u8 a)
{
    gCurrentPinballGame->unk16 = 2;
    gCurrentPinballGame->unk14 = a;
    
    if (gCurrentPinballGame->unk13 == 2) 
    {
        gMain.unk44->unk34->unk0 = 0;
    }
}
