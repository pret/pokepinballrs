#include "global.h"
#include "main.h"

extern void sub_1A2C0(void);
extern void sub_1D5D8(void);
extern void sub_1DA74(void);
extern void sub_1DAD8(void);
extern void sub_1DC7C(void);
extern void sub_1DDDC(void);
extern void sub_1EC48(void);
extern void sub_1F158(void);
extern void sub_1F59C(void);
extern void sub_1F698(void);
extern void sub_1FA48(void);
extern void sub_1FBC4(void);
extern void sub_1FF0C(void);
extern void sub_201B8(void);
extern void sub_21238(s32);
extern void sub_21D78(void);
extern void sub_239A4(void);
extern void sub_23E18(void);
extern void sub_2C538(void);
extern void sub_2C9A4(void);

void sub_19D04(void)
{
    if (gCurrentPinballGame->unk13 == 2 && gCurrentPinballGame->unk14 > 2)
        sub_21238(0);

    if (gCurrentPinballGame->unk13 > 2)
        return;

    if (gCurrentPinballGame->unk14 == 3)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }

    if (gCurrentPinballGame->unk14 == 4)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
    else if (gCurrentPinballGame->unk14 == 6)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk73C = 0;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
    else if (gCurrentPinballGame->unk14 > 3)
    {
        gCurrentPinballGame->unk73C = gCurrentPinballGame->unk72E;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->unk72F;
        gCurrentPinballGame->unk72E = 0;
        gCurrentPinballGame->unk72F = 0;
    }
}

void sub_19E10(void) {
    int randNum;
    
    sub_1A0F4();
    sub_1DA74();
    if (gCurrentPinballGame->unk2A0 != 0) 
    {
        gCurrentPinballGame->unk2A0 -= 1;
        if (gCurrentPinballGame->unk2A0 == 0)
        {
            randNum = Random();
            gCurrentPinballGame->unk29F = ((randNum + gMain.systemFrameCount) % 100) + 1;
        }
    }

    if (gCurrentPinballGame->unk68 < 110)
    {
        sub_1D5D8();
        sub_1DAD8();
        sub_2C9A4();
    }
    sub_2CA9C();
    if (gCurrentPinballGame->unk68 < 168)
    {
        sub_239A4();
    }
    if (gCurrentPinballGame->unk68 < 220)
    {
        sub_23E18();
        if (gCurrentPinballGame->unk2A4 != 0)
        {
            sub_1DC7C();
        }
        else
        {
            sub_1EC48();
        }
        sub_1F158();
        sub_1F59C();
    }
    sub_1F698();
    if (gCurrentPinballGame->unk68 > 63)
    {
        sub_1FA48();
        sub_1FBC4();
    }
    if (gCurrentPinballGame->unk68 > 115)
    {
        sub_2C538();
    }
    if (gCurrentPinballGame->unk68 > 130)
    {
        sub_201B8();
    }
    sub_2CE80();
    if (gCurrentPinballGame->unk68 > 168)
    {
        sub_2D104();
    }
    sub_203CC();
    sub_21B0C();
    sub_4E814();
    sub_1D128();
    sub_21D78();
    sub_31B30();

    if (gCurrentPinballGame->unk194 != 0)
    {
        sub_225F0();
    }
    sub_472E4();

    if (gCurrentPinballGame->unk1328 != 0)
    {
        gCurrentPinballGame->unk1328 -= 1;
        if (gCurrentPinballGame->unk1328 == 0)
        {
            gCurrentPinballGame->unk1330 = gCurrentPinballGame->unk1334;
        }
    }
}

void sub_19F70(void) 
{
    sub_1DDDC();
    sub_1A9E8();
    sub_1F2A4();
    sub_1FF0C();
    if (gCurrentPinballGame->unk600 != 0)
    {
        gCurrentPinballGame->unk600 -= 1;
    }
}

//Duplicate of sub_32DF8, with "gCurrentPinballGame->unk301 = 1;" added in the final if statement
void sub_19FA0(void) {
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->unk1C4 == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->unk1C0 == 0 && gCurrentPinballGame->unk61C == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 0;
        }

        tmp = gCurrentPinballGame->hLight;
        gCurrentPinballGame->hLight = gCurrentPinballGame->oLight;
        gCurrentPinballGame->oLight = gCurrentPinballGame->lLight;
        gCurrentPinballGame->lLight = gCurrentPinballGame->eLight;
        gCurrentPinballGame->eLight = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = tmp;
    }

    if (gCurrentPinballGame->newButtonActions[1])
    {
        if (gCurrentPinballGame->unk1C4 == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->unk1C0 == 0 && gCurrentPinballGame->unk61C == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 1;
        }

        tmp = gCurrentPinballGame->eLight;
        gCurrentPinballGame->eLight = gCurrentPinballGame->lLight;
        gCurrentPinballGame->lLight = gCurrentPinballGame->oLight;
        gCurrentPinballGame->oLight = gCurrentPinballGame->hLight;
        gCurrentPinballGame->hLight = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = tmp;
        
        gCurrentPinballGame->unk301 = 1;
    }
}

void sub_1A0F4(void) 
{                
    if ((gMain.unkF & 1) != 0)
    {
        gCurrentPinballGame->unk5F7 = 1;
        if (gCurrentPinballGame->unkFA != 0)
        {
            gCurrentPinballGame->unk1F = 2;
            gCurrentPinballGame->unk5FA = 1;
            if (gCurrentPinballGame->unkEA != 0)
            {
                gCurrentPinballGame->unkEA -= 1;
            }
            else if (gCurrentPinballGame->unkEE == 0)
            {
                if (gCurrentPinballGame->unkEC != 0)
                {
                    gCurrentPinballGame->unkEC -= 1;
                }
                else
                {
                    gCurrentPinballGame->unkFA = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->unk68 + gCurrentPinballGame->unkEE <= gCurrentPinballGame->unkE8)
                {
                    gCurrentPinballGame->unkE6 += gCurrentPinballGame->unkEE;
                }
                else if (gCurrentPinballGame->unk68 - gCurrentPinballGame->unkEE >= gCurrentPinballGame->unkE8)
                {
                    gCurrentPinballGame->unkE6 -= gCurrentPinballGame->unkEE;
                }
                else if (gCurrentPinballGame->unkEC != 0)
                {
                    gCurrentPinballGame->unkEC -= 1;
                }
                else
                {
                    gCurrentPinballGame->unkFA = 0;
                }
            }
  
            if (gCurrentPinballGame->unkF2 != 0)
            {
                sub_1A2C0();
            }
        }
        else
        {
            if (gCurrentPinballGame->unkEE == 0 || gCurrentPinballGame->unkE6 == 0)
            {
                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unk1F = 0;
                gMain.unkF = gMain.unkF & 254;
                gCurrentPinballGame->unk5F7 = 0;
                
                if (gCurrentPinballGame->unkFB == 0)
                {
                    gCurrentPinballGame->unk5FA = 0;
                }
            }
    
            if (gCurrentPinballGame->unkE6 > 0)
            {
                gCurrentPinballGame->unkE6 -= gCurrentPinballGame->unkEE;
                if (gCurrentPinballGame->unkE6 > 0)
                {
                    return;
                }

                gCurrentPinballGame->unkE6 = 0;
                gCurrentPinballGame->unk1F = 0;
                gMain.unkF = gMain.unkF & 254;
                gCurrentPinballGame->unk5F7 = 0;

                if (gCurrentPinballGame->unkFB == 0)
                {
                    gCurrentPinballGame->unk5FA = 0;
                }
            }
    
            if (gCurrentPinballGame->unkE6 <= -1)
            {
                gCurrentPinballGame->unkE6 += gCurrentPinballGame->unkEE;
                if (gCurrentPinballGame->unkE6 >= 0)
                {
                    gCurrentPinballGame->unkE6 = 0;
                    gCurrentPinballGame->unk1F = 0;
                    gMain.unkF = gMain.unkF & 254;
                    gCurrentPinballGame->unk5F7 = 0;

                    if (gCurrentPinballGame->unkFB == 0)
                    {
                        gCurrentPinballGame->unk5FA = 0;
                    }
                }
            }
        }
    }
}
