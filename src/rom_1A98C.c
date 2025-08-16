#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

void sub_1AAA0(void);
void sub_1AA38(void);
void sub_1ADF4(void);
void sub_1AF84(void);
void sub_1AFD4(void);
void sub_1C560(void);
void sub_1C5AC(void);
void sub_19B64(u8);
void sub_22A30(void);
void sub_22C6C(void);
void sub_22D54(void);


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
        sub_1AAA0(); // Catch hole
        break;
    case 2:
        sub_1ADF4(); //Hatch hole
        break;
    case 3:
        sub_1AFD4(); //Mart / Evo hole
        break;
    case 4:
        sub_1C5AC(); //Center Hole
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
    gCurrentPinballGame->unk3C = 50000;

    sub_11B0(8);
}

/*
* Ruby board Sharpedo; during the initation of the catch mode
* Echoes sub_32BE4, which is the equivalent 'catch hole' on the sapphire board.
*
* Note: this *does not* affect the start of the catch mode itself.
* When this function is nulled out at sub_1A9E8, the banner *doesn't* show, and
* the ball bounces off the sharpedo. However, the grid still shows a picked mon,
* and the mode otherwise works mostly normally, with the exception of affecting 
* the 'tilt' behavior, and the colision with the cyndaquil pushback.
*/
void sub_1AAA0(void)
{
    if (gCurrentPinballGame->unk28) //Countdown timer; ball grabbed/held while banner shows
    {
        gCurrentPinballGame->unk28--;
        if (gCurrentPinballGame->unk28 > 100) 
        {
            gCurrentPinballGame->unk5F7 = 1;
            gCurrentPinballGame->unk1F = 1;
    
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->unk6 = 0;

            if (gCurrentPinballGame->unk28 > 108)
            {
                gCurrentPinballGame->unk5FA = 1;
                
                if (gCurrentPinballGame->unk28 > 110)
                {
                    gCurrentPinballGame->ball->positionQ0.x = 195;
                    gCurrentPinballGame->ball->positionQ0.y = 222;
                }
                else
                {
                    gCurrentPinballGame->ball->positionQ0.x = 196;
                    gCurrentPinballGame->ball->positionQ0.y = 221;
                }
                //Presumed controling either the message board 'state'/'tile'
                // or the sharpedo animation 'state'/tile.
                gCurrentPinballGame->unk2F4 =6;  
            }
            else if (gCurrentPinballGame->unk28 > 104)
            {
                gCurrentPinballGame->ball->positionQ0.x = 197;
                gCurrentPinballGame->ball->positionQ0.y = 219;
                gCurrentPinballGame->unk2F4 = 7;
            }
            else 
            {
                gCurrentPinballGame->ball->unk0 = 1;
                gCurrentPinballGame->unk2F4 = 8;
            }
        }
        else if (gCurrentPinballGame->unk28 > 20)
        {
            if (gCurrentPinballGame->unk28 > 77)
            {
                gCurrentPinballGame->unk2F4 = 9;

                if (gCurrentPinballGame->unk28 < 80)
                {
                    if (gCurrentPinballGame->unk2F6 != 0)
                    {
                        gCurrentPinballGame->unk2F6--;
                        gCurrentPinballGame->unk28++;
                    }
                }
            }
            else if (gCurrentPinballGame->unk28 > 72)
            {
                gCurrentPinballGame->unk2F4 = 10;
            }
            else if (gCurrentPinballGame->unk28 > 67)
            {
                gCurrentPinballGame->unk2F4 = 11;
            }
            else if (gCurrentPinballGame->unk28 > 44)
            {
                gCurrentPinballGame->unk2F4 = 12;
            }
            else if (gCurrentPinballGame->unk28 > 38)
            {
                gCurrentPinballGame->unk2F4 = 13;
            }
            else if (gCurrentPinballGame->unk28 > 28)
            {
                gCurrentPinballGame->unk2F4 = 14;
            }
            else if (gCurrentPinballGame->unk28 > 23)
            {
                gCurrentPinballGame->unk2F4 = 15;
            }
            else {
                gCurrentPinballGame->unk2F4 = 16;
            }
        }
        else if (gCurrentPinballGame->unk28 > 18) 
        {
            gCurrentPinballGame->ball->positionQ0.x = 193;
            gCurrentPinballGame->ball->positionQ0.y = 226;
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk2F4 = 17;
        }
        else if (gCurrentPinballGame->unk28 > 16) 
        {
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk5FE = 0;
            gCurrentPinballGame->unk5FB = 1;
            gCurrentPinballGame->unk5FA = 0;
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->ball->velocity.x = 0xFF56;
            gCurrentPinballGame->ball->velocity.y = 220;
            gCurrentPinballGame->ball->positionQ0.x = 190;
            gCurrentPinballGame->ball->positionQ0.y = 232;
            gCurrentPinballGame->unk2F4 = 18;
            if (gCurrentPinballGame->unk28 == 18)
            {
                m4aSongNumStart(194);
                sub_11B0(7);
            }
        }
        else if (gCurrentPinballGame->unk28 > 12) 
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 19;
        }
        else if (gCurrentPinballGame->unk28 > 8) 
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 20;
        }
        else if (gCurrentPinballGame->unk28 > 4) 
        {
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->unk2F4 = 21;
        }
        else
        {
            gCurrentPinballGame->unk2F4 = 22;
        }
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->ball->positionQ8.x= gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        
    }
    else
    {
        gCurrentPinballGame->unk26 = 30;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk25 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->unk2F4 = 0;
    }
}


void sub_1AD84(void)
{
    gCurrentPinballGame->unk3C = 100000;
    if (gCurrentPinballGame->unk2DA == 3)
    {
        gCurrentPinballGame->unk2DA = 4;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        sub_11B0(7);
        gCurrentPinballGame->unk28 = 500;
    }
    else if (gCurrentPinballGame->unk2D0 !=0)
    {
        gCurrentPinballGame->unk28 = 300;
    }
    else
    {
        gCurrentPinballGame->unk28 = 120;
    }

    gCurrentPinballGame->unk5F7 = 1;
}

void sub_1ADF4(void)
{
    u16 unk28 = gCurrentPinballGame->unk28;

    if (unk28 != 0)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;

        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0x94;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        if (gCurrentPinballGame->unk2D0 != 1)
            return;
        if (gCurrentPinballGame->unk28 > 0xC8)
            return;

        if (gCurrentPinballGame->unk28 == 0xC8)
        {
            if (gCurrentPinballGame->unkE4 != 0)
                gCurrentPinballGame->unk28++;
            else
            {
                if (gCurrentPinballGame->unk48 != 0 && gCurrentPinballGame->unk16C == 4)
                    sub_22978();
                else
                    sub_22C6C();
            }
        }
        else
        {
            if (gCurrentPinballGame->unk48 != 0 && gCurrentPinballGame->unk16C == 4)
                sub_22A30();
            else
                sub_22D54();
        }
        if (gCurrentPinballGame->unk28 <= 9)
            gCurrentPinballGame->unk28++;
    }
    else
    {
        gCurrentPinballGame->ball->unk0 = unk28;
        gCurrentPinballGame->unk25 = unk28;

        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0xA2;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk5F7 = 0;

        if (gCurrentPinballGame->unk2D0 == 2)
        {
            gCurrentPinballGame->unk2DA = 3;
            gCurrentPinballGame->unk2DE = 0x30;
            gCurrentPinballGame->unk2E0 = 0x1E;
        }
        else
        {
            gCurrentPinballGame->unk1F = 0;
            gCurrentPinballGame->unk26 = 0x3C;
            gCurrentPinballGame->ball->velocity.x = 0x14;
            gCurrentPinballGame->ball->velocity.y = 0xC8;
        }
    }
}

void sub_1AF84(void)
{
    gCurrentPinballGame->unk1B8 = 0;
    gCurrentPinballGame->unk1B6 = 0;
    gCurrentPinballGame->unk28 = 0xB4;
    gCurrentPinballGame->unk1BA = 0xB4;
    gCurrentPinballGame->unk3C = 0x7A120;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->unk5F7 = 1;
}

void sub_1AFD4(void)
{

    if (gCurrentPinballGame->unk28 > 0x18)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28 = gCurrentPinballGame->unk28 - 1;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xDC;
        gCurrentPinballGame->ball->positionQ0.y = 0x62;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x * 256;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y * 256;

        if (gCurrentPinballGame->unk28 > 0x9B)
            gCurrentPinballGame->unk2F0 = (gCurrentPinballGame->unk28 - 0x9C) / 8;
        if (gCurrentPinballGame->unk28 <= 0x31)
            gCurrentPinballGame->unk28++;

        sub_1B140(gCurrentPinballGame->unk1A5);
        return;
    }

    if (gCurrentPinballGame->unk28 > 0)
    {
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->unk2F0 = (0x18 - gCurrentPinballGame->unk28) / 8;
        return;
    }

    gCurrentPinballGame->ball->unk0 = 0;
    gCurrentPinballGame->unk1F = 0;
    gCurrentPinballGame->unk26 = 0x3C;

    gCurrentPinballGame->ball->velocity.x = 0x60;
    gCurrentPinballGame->ball->velocity.y = 0xC0;
    gCurrentPinballGame->ball->positionQ0.x = 0xDF;
    gCurrentPinballGame->ball->positionQ0.y = 0x63;

    gCurrentPinballGame->ball->unk6 = 0;
    gCurrentPinballGame->unk5F7 = 0;
    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
    gCurrentPinballGame->unk25 = 0;
    gCurrentPinballGame->unk2F0 = 0x13;

    m4aSongNumStart(SE_UNKNOWN_0xC3);

    if (gCurrentPinballGame->unk72E > 2 && gCurrentPinballGame->evolvablePartySize > 0)
    {
        sub_19B64(6);
    }
}