#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
//#include "constants/pinball_game.h"

extern void sub_32DF8(void);

void SapphireBoardProcess_3A_326F4(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    gCurrentPinballGame->unk1E5 = 0;
    gCurrentPinballGame->unk1E6 = 1;

    sub_1F2A4();
    sub_21B0C();
    sub_1F59C();
    sub_300D8();
    sub_30178();

    gCurrentPinballGame->unk1D8 = 0x100;
    gCurrentPinballGame->unk1DA = 0x100;

    sub_30480();
    sub_304C8();
    sub_31144();
    sub_313A0();
    sub_2E6AC();
    sub_31B30();
}

void SapphireBoardProcess_3B_3276C(void)
{
    sub_19B90();
    sub_327C0();

    if (!gMain.unkF)
        sub_328C8();

    sub_32DF8();

    if (gCurrentPinballGame->unk29C)
    {
        gCurrentPinballGame->unk29C--;
        if (!gCurrentPinballGame->unk29C)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void sub_327C0(void)
{
    s32 temp;

    sub_4F814();
    sub_1A0F4();
    sub_2CA9C();

    if (gCurrentPinballGame->unk68 < 0x5a)
    {
        sub_304C8();
        sub_31498();
    }

    if (gCurrentPinballGame->unk13 < 3)
    {
        if (gCurrentPinballGame->unk345 == 3 && gCurrentPinballGame->unk346 == 0)
        {
            gCurrentPinballGame->unk728 = 1;
        }
        else
        {
            gCurrentPinballGame->unk728 = 0;
        }
    }
    else
    {
        gCurrentPinballGame->unk728 = 0;
    }

    if (gCurrentPinballGame->unk68 < 0x96)
    {
        sub_2E6AC();
        sub_313A0();
    }
    if (gCurrentPinballGame->unk68 < 0xC4)
    {
        sub_30178();
        sub_2F140();
    }
    if (gCurrentPinballGame->unk68 < 0xCA)
    {
        sub_2FCD0();
    }
    if (gCurrentPinballGame->unk68 < 0xDC)
    {
        sub_1F59C();
    }

    sub_308DC();

    if (0x76 < gCurrentPinballGame->unk68)
    {
        sub_2F504();
        sub_30EB4();
    }

    sub_2CE80();

    if (0xA8 < gCurrentPinballGame->unk68)
        sub_2D104();

    sub_203CC();
    sub_21B0C();
    sub_1D128();
    sub_31B30();

    if (gCurrentPinballGame->unk194)
        sub_225F0();

    sub_472E4();
}

void sub_328C8(void)
{
    sub_300D8();
    sub_32968();
    sub_1F2A4();

    if (gCurrentPinballGame->unk600)
        gCurrentPinballGame->unk600--;

    sub_2F26C();
    sub_2E67C();
    sub_31144();

    if (!(gMain.unkF & 0x20))
        sub_2F79C();
}

void sub_32914(void)
{
    if (gMain.unkF != 0)
        return;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_32B74();
        break;
    case 3:
        sub_329B0();
        break;
    case 4:
        sub_1C560();
        break;
    }

    gCurrentPinballGame->unk26 = 60;
}

void sub_32968(void)
{
    if (gCurrentPinballGame->unk26)
        gCurrentPinballGame->unk26--;

    switch (gCurrentPinballGame->unk25)
    {
    case 1:
        sub_32BE4();
        break;
    case 3:
        sub_329F4();
        break;
    case 4:
        sub_1C5AC(); //Center Hole
        break;
    }
}

void sub_329B0(void)
{
    gCurrentPinballGame->unk28 = 0xB4;
    gCurrentPinballGame->unk1BA = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->unk5F7 = 1;
}

void sub_329F4(void)
{
    s16 i;

    if (gCurrentPinballGame->unk28 > 0x18)
    {
        gCurrentPinballGame->ball->unk0 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 58;
        gCurrentPinballGame->ball->positionQ0.y = 178;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

        if (gCurrentPinballGame->unk28 <= 0x31)
        {
            gCurrentPinballGame->unk28++;
        }

        sub_1B140(gCurrentPinballGame->unk1A5);

        if (gCurrentPinballGame->unk1A5)
        {
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->unk36C[i] = 10;
                gCurrentPinballGame->unk36E[i] = 0;
                gCurrentPinballGame->unk36A[i] = 4;
            }
        }
    }
    else if (gCurrentPinballGame->unk28 > 0)
    {
        gCurrentPinballGame->unk28--;
    }
    else
    {
        gCurrentPinballGame->ball->unk0 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 0x3C;
        gCurrentPinballGame->ball->velocity.x = 0x60;
        gCurrentPinballGame->ball->velocity.y = 0xC0;
        gCurrentPinballGame->ball->positionQ0.x = 0x3C;
        gCurrentPinballGame->ball->positionQ0.y = 0xB4;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->unk25 = 0;

        m4aSongNumStart(SE_UNKNOWN_0xC3);

        if (gCurrentPinballGame->unk72E > 2 && gCurrentPinballGame->evolvablePartySize > 0) {
            sub_19B64(6);
        }
    }
}

void sub_32B74(void)
{
    if (gCurrentPinballGame->unk72F > 1)
        sub_19B64(4);

    gCurrentPinballGame->unk28 = 100;
    gCurrentPinballGame->unk2F4 = 2;
    gCurrentPinballGame->unk5FC = 0;
    gCurrentPinballGame->unk5FE = 30;
    gCurrentPinballGame->unk5FB = 0;
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    m4aSongNumStart(SE_UNKNOWN_0xD5);
    sub_11B0(8);
}

void sub_32BE4(void)
{
    if (gCurrentPinballGame->unk28)
    {
        gCurrentPinballGame->unk5F7 = 1;
        gCurrentPinballGame->unk1F = 1;
        gCurrentPinballGame->unk28--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->unk6 = 0;
        if (gCurrentPinballGame->unk28 > 97)
        {
            gCurrentPinballGame->unk5FA = 1;
            gCurrentPinballGame->unk2F4 = 2;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else if (gCurrentPinballGame->unk28 > 94)
        {
            gCurrentPinballGame->unk2F4 = 3;
            gCurrentPinballGame->ball->positionQ0.x = 0xb8;
            gCurrentPinballGame->ball->positionQ0.y = 0xbb;
        }
        else if (gCurrentPinballGame->unk28 > 91)
        {
            gCurrentPinballGame->ball->unk0 = 1;
            gCurrentPinballGame->unk2F4 = 4;
        }
        else if (gCurrentPinballGame->unk28 > 83)
        {
            gCurrentPinballGame->unk2F4 = 5;
        }
        else if (gCurrentPinballGame->unk28 > 34)
        {
            gCurrentPinballGame->unk2F4 = 6;

        }
        else if (gCurrentPinballGame->unk28 > 26)
        {
            gCurrentPinballGame->unk2F4 = 7;

        }
        else if (gCurrentPinballGame->unk28 > 18)
        {
            gCurrentPinballGame->unk2F4 = 8;

        }
        else if (gCurrentPinballGame->unk28 > 10)
        {
            gCurrentPinballGame->unk2F4 = 9;

        }
        else if (gCurrentPinballGame->unk28 > 4)
        {
            gCurrentPinballGame->ball->unk0 = 0;
            gCurrentPinballGame->unk2F4 = 10;
            gCurrentPinballGame->ball->positionQ0.x = 0xb5;
            gCurrentPinballGame->ball->positionQ0.y = 0xc3;
        }
        else
        {
            gCurrentPinballGame->unk2F4 = 11;
            gCurrentPinballGame->ball->positionQ0.x = 0xb0;
            gCurrentPinballGame->ball->positionQ0.y = 0xca;
        }

        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
    }
    else
    {
        gCurrentPinballGame->unk2F4 = 0;
        gCurrentPinballGame->unk1F = 0;
        gCurrentPinballGame->unk26 = 60;
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->velocity.x = -0x66;
        gCurrentPinballGame->ball->velocity.y = 0xC8;
        sub_11B0(7);
        gCurrentPinballGame->ball->unk6 = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xAB;
        gCurrentPinballGame->ball->positionQ0.y = 0xD4;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->unk25 = 0;
        gCurrentPinballGame->unk5F7 = 0;
        m4aSongNumStart(SE_UNKNOWN_0xD6);
        gCurrentPinballGame->unk5FE = 0;
        gCurrentPinballGame->unk5FB = 1;
        gCurrentPinballGame->unk5FA = 0;
    }
}

void sub_32DF8(void)
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
    }
}
