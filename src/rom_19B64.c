#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern const void (*gUnknown_086AD4C4[])(void);
extern const void (*gUnknown_086AD4E8[])(void);

void sub_19D04(void);
void sub_19E10(void);
void sub_19F70(void);
void sub_19FA0(void);
void sub_1D5D8(void);
void sub_1DAD8(void);
void sub_1DDDC(void);
void sub_1EC48(void);
void sub_1F158(void);
void sub_23954(void);
void sub_239A4(void);
void sub_23E18(void);
void sub_2C9A4(void);
void sub_4E9F0(s8);

void sub_19A20(void) 
{    
    gCurrentPinballGame->catchModeArrows = 2;
    sub_1D5D8();
    sub_4E9F0(0);
    sub_1DAD8();
    sub_23954();
    sub_239A4();

    gCurrentPinballGame->unk2D4 = 73;
    gCurrentPinballGame->unk2D6 = 154;
    gCurrentPinballGame->unk2DA = 0;
    sub_23E18();
    sub_1DDDC();
    
    gCurrentPinballGame->unk170 = 10;
    gCurrentPinballGame->unk171 = 10;
    gCurrentPinballGame->unk172 = 10;
    gCurrentPinballGame->unk16C = 0;
    sub_1EC48();
    sub_1F158();

    gCurrentPinballGame->unk1E5 = 0;
    gCurrentPinballGame->unk1E6 = 1;
    sub_1F2A4();
    sub_21B0C();
    sub_1F59C();

    gCurrentPinballGame->unk1D8 = 256;
    gCurrentPinballGame->unk1DA = 256;
    gCurrentPinballGame->unk29F = 2;
    sub_2C9A4();

    gCurrentPinballGame->unk2EC = 3;
    gCurrentPinballGame->unk2EE = 3;
    sub_31B30();
}

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

void sub_19B64(u8 arg0)
{
    gCurrentPinballGame->unk16 = 2;
    gCurrentPinballGame->unk14 = arg0;
    if (gCurrentPinballGame->unk13 == 2) 
        gMain.unk44[13]->a.unk0 = 0;
}

void sub_19B90(void) 
{
    switch (gCurrentPinballGame->unk16)
    {
        case 0:
            gUnknown_086AD4C4[gCurrentPinballGame->unk13]();
            gCurrentPinballGame->unk16 += 1;
            break;
        case 1:
            gUnknown_086AD4E8[gCurrentPinballGame->unk13]();
            break;
        case 2:
            sub_19D04();
            gCurrentPinballGame->unk15 = gCurrentPinballGame->unk13;
            gCurrentPinballGame->unk13 = gCurrentPinballGame->unk14;
            gCurrentPinballGame->unk16 = 0;
            break;
    }
}

void sub_19C04(void) 
{
    s16 num1;
    u8 num2;
    
    if (gCurrentPinballGame->unk15 > 0)
    {
        if (gMain.selectedField == 0)
        {
            num1 = gCurrentPinballGame->bonusFieldsComplete / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_RUBY);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_RUBY2);
            }
        }
        else
        {
            num1 = gCurrentPinballGame->bonusFieldsComplete / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_SAPPHIRE);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
            }
        }
    }
    
    num2 = gCurrentPinballGame->unk15 - 1;
    if (num2 > 1)
    {
        gCurrentPinballGame->unk72E = gCurrentPinballGame->unk73C;
        gCurrentPinballGame->unk72F = gCurrentPinballGame->catchModeArrows;
        gCurrentPinballGame->unk73C = 0;
        gCurrentPinballGame->catchModeArrows = 0;
    }
}

void sub_19CC8(void) 
{
    if (gCurrentPinballGame->unk714 != 0)
    {
        if (gCurrentPinballGame->unk6EE != 0)
        {
            gCurrentPinballGame->unk6EE -= 1;
        }
        else
        {
            sub_19B64(2);
        }
    }
}
