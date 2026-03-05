#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const void (*gUnknown_086AD4C4[])(void);
extern const void (*gUnknown_086AD4E8[])(void);

extern void sub_19D04(void);
extern void sub_19E10(void);
extern void sub_19F70(void);
extern void sub_19FA0(void);
extern void sub_1D5D8(void);
extern void sub_1DA74(void);
extern void sub_1DAD8(void);
extern void DrawWhiscash(void);
extern void RubyPond_EntityLogic(void);
extern void RubyPondTriBumperHandleHitAndDraw(void);
extern void sub_1F158(void);
extern void sub_1F59C(void);
extern void sub_1F698(void);
extern void sub_1FA48(void);
extern void sub_1FBC4(void);
extern void sub_1FF0C(void);
extern void sub_201B8(void);
extern void sub_21D78(void);
extern void sub_23954(void);
extern void sub_239A4(void);
extern void sub_23E18(void);
extern void sub_2C538(void);
extern void sub_2C9A4(void);
extern void sub_4E9F0(s16);

void RubyBoardProcess_3A_19A20(void)
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
    RubyPond_EntityLogic();

    gCurrentPinballGame->unk170[0] = 10;
    gCurrentPinballGame->unk170[1] = 10;
    gCurrentPinballGame->unk170[2] = 10;
    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_STAGGERED;
    RubyPondTriBumperHandleHitAndDraw();
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

    gCurrentPinballGame->unk2EC[0] = 3;
    gCurrentPinballGame->unk2EC[1] = 3;
    sub_31B30();
}

void RubyBoardProcess_3B_19B10(void)
{
    sub_19B90();
    sub_19E10();

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        sub_19F70();
    }

    sub_19FA0();
    if (gCurrentPinballGame->unk29C != 0)
    {
        gCurrentPinballGame->unk29C--;
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
        gMain.unk44[13]->available = 0;
}

void sub_19B90(void)
{
    switch (gCurrentPinballGame->unk16)
    {
        case 0:
            gUnknown_086AD4C4[gCurrentPinballGame->unk13]();
            gCurrentPinballGame->unk16++;
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
        if (gMain.selectedField == FIELD_RUBY)
        {
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
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
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
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
            gCurrentPinballGame->unk6EE--;
        }
        else
        {
            sub_19B64(2);
        }
    }
}

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

void sub_19E10(void)
{
    int randNum;

    sub_1A0F4();
    sub_1DA74();
    if (gCurrentPinballGame->unk2A0 != 0)
    {
        gCurrentPinballGame->unk2A0--;
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
        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            DrawWhiscash();
        }
        else
        {
            RubyPondTriBumperHandleHitAndDraw();
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
    BonusStage_HandleModeChangeFlags();

    if (gCurrentPinballGame->unk1328 != 0)
    {
        gCurrentPinballGame->unk1328--;
        if (gCurrentPinballGame->unk1328 == 0)
        {
            gCurrentPinballGame->unk1330 = gCurrentPinballGame->unk1334;
        }
    }
}

void sub_19F70(void)
{
    RubyPond_EntityLogic();
    sub_1A9E8();
    sub_1F2A4();
    sub_1FF0C();
    if (gCurrentPinballGame->unk600 != 0)
    {
        gCurrentPinballGame->unk600--;
    }
}

//Duplicate of sub_32DF8, with "gCurrentPinballGame->unk301 = 1;" added in the final if statement
void sub_19FA0(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->unk1C4 == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->unk1C0 == 0 && gCurrentPinballGame->unk61C == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 0;
        }

        tmp = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = tmp;

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

        tmp = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = tmp;

        gCurrentPinballGame->unk301 = 1;
    }
}
