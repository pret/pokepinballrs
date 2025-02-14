#include "global.h"
#include "main.h"

void sub_1AA38(void);
void sub_1AD84(void);
void sub_1AF84(void);
void sub_1C560(void);

void sub_1A98C(void) {    
    if (gMain.unkF == 0) 
    {
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

            default:
                break;
        }
        
        gCurrentPinballGame->unk26 = 60;
    }
}