#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

void sub_1AAA0(void);
void sub_1AA38(void);
void sub_1AD84(void);
void sub_1ADF4(void);
void sub_1AF84(void);
void sub_1AFD4(void);
void sub_1C560(void);
void sub_1C5AC(void);
void sub_19B64(u8 a);

void sub_1A98C(void)
{    
    if (gMain.unkF != 0)
        return;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_1AA38();
        break;
    case 2:
        sub_1AD84();
        break;
    case 3:
        sub_1AF84();
        break;
    case 4:
        sub_1C560();
        break;
    }

    gCurrentPinballGame->unk26 = 60;
}

void sub_1A9E8(void)
{
    if (gCurrentPinballGame->unk26 > 0)
        gCurrentPinballGame->unk26 -= 1;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_1AAA0();
        break;
    case 2:
        sub_1ADF4();
        break;
    case 3:
        sub_1AFD4();
        break;
    case 4:
        sub_1C5AC();
        break;
    }
}

void sub_1AA38(void) 
{
    if (gCurrentPinballGame->unk72F > 1)
    {
        sub_19B64(4);
    }
    
    gCurrentPinballGame->unk5FC = 0;
    gCurrentPinballGame->unk5FB = 0;
    gCurrentPinballGame->unk5FE = 0;
    gCurrentPinballGame->unk28 = 113;
    
    m4aSongNumStart(SE_UNKNOWN_0xCE);
    gCurrentPinballGame->unk3C = 0xC350;

    sub_11B0(8);
}
