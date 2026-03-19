#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gTimerWarningPalette_Fast[];
extern const u8 gDefaultBallPalette[];
extern const u8 gTimerWarningPalette_Slow[];

void AllBoardProcess_8A_4CEA8(void)
{
    AllBoardProcess_8B_4CEB4();
}

void AllBoardProcess_8B_4CEB4(void)
{
    s16 i, j;
    s16 sp0[12];
    u32 value;

    ProcessEventTimer();
    gCurrentPinballGame->scoreAdditionAccumulator += (gCurrentPinballGame->ballUpgradeType + 1) * gCurrentPinballGame->scoreAddedInFrame;
    if (gCurrentPinballGame->scoreCounterAnimationEnabled)
    {
        if (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->scoreLo += gCurrentPinballGame->scoreAdditionAccumulator;
            gCurrentPinballGame->scoreAdditionAccumulator = 0;
            gCurrentPinballGame->scoreCounterAnimationEnabled = FALSE;
            gCurrentPinballGame->scoreAddStepSize = 40000;
        }

        if (gMain.systemFrameCount % 2 == 0)
        {
            if (gCurrentPinballGame->scoreAdditionAccumulator)
            {
                if (gCurrentPinballGame->scoreAdditionAccumulator <= gCurrentPinballGame->scoreAddStepSize)
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->scoreAdditionAccumulator;
                    gCurrentPinballGame->scoreAdditionAccumulator = 0;
                    gCurrentPinballGame->scoreCounterAnimationEnabled = FALSE;
                    gCurrentPinballGame->scoreAddStepSize = 40000;
                }
                else
                {
                    gCurrentPinballGame->scoreLo += gCurrentPinballGame->scoreAddStepSize;
                    gCurrentPinballGame->scoreAdditionAccumulator -= gCurrentPinballGame->scoreAddStepSize;
                    m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
                }
            }
        }
    }
    else
    {
        gCurrentPinballGame->scoreLo += gCurrentPinballGame->scoreAdditionAccumulator;
        gCurrentPinballGame->scoreAdditionAccumulator = 0;
    }

    if (gCurrentPinballGame->scoreLo / 100000000 != 0)
    {
        if (gCurrentPinballGame->scoreHi < 9999)
        {
            gCurrentPinballGame->scoreHi++;
            gCurrentPinballGame->scoreLo -= 100000000;
        }
        else
        {
            gCurrentPinballGame->scoreHi = 9999;
            gCurrentPinballGame->scoreLo = 99999999;
        }
    }

    gCurrentPinballGame->scoreAddedInFrame = 0;

    value = gCurrentPinballGame->scoreHi;
    sp0[0] = (value % 10000) / 1000 + 5;
    sp0[1] = (value % 1000) / 100 + 5;
    sp0[2] = (value % 100) / 10 + 19;
    sp0[3] = value % 10 + 5;

    value = gCurrentPinballGame->scoreLo;
    sp0[4] = value / 10000000 + 5;
    sp0[5] = (value % 10000000) / 1000000 + 19;
    sp0[6] = (value % 1000000) / 100000 + 5;
    sp0[7] = (value % 100000) / 10000 + 5;
    sp0[8] = (value % 10000) / 1000 + 19;
    sp0[9] = (value % 1000) / 100 + 5;
    sp0[10] = (value % 100) / 10 + 5;
    sp0[11] = value % 10 + 5;

    for (i = 0; i < 5; i++)
    {
        if (sp0[i] == 5 || sp0[i] == 19)
            sp0[i] = 30;
        else
            break;
    }
    for (j = i; j < 12; j++)
    {
        gBG0TilemapBuffer[0x7C1 + (j - i)] = sp0[j] * 2 - 0x3EA0;
        gBG0TilemapBuffer[0x7E1 + (j - i)] = sp0[j] * 2 - 0x3E9F;
    }

    if (gCurrentPinballGame->caughtMonCount > 999)
        gCurrentPinballGame->caughtMonCount = 999;
    sp0[2] = gCurrentPinballGame->caughtMonCount / 100;
    sp0[1] = (gCurrentPinballGame->caughtMonCount % 100) / 10;
    sp0[0] = gCurrentPinballGame->caughtMonCount % 10;
    gBG0TilemapBuffer[0x7D1] = 0xC17E;
    gBG0TilemapBuffer[0x7F1] = 0xC17F;
    gBG0TilemapBuffer[0x7D2] = (sp0[2] + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7F2] = (sp0[2] + 5) * 2 - 0x3E9F;
    gBG0TilemapBuffer[0x7D3] = (sp0[1] + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7F3] = (sp0[1] + 5) * 2 - 0x3E9F;
    gBG0TilemapBuffer[0x7D4] = (sp0[0] + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7F4] = (sp0[0] + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->coins > 99)
        gCurrentPinballGame->coins = 99;
    sp0[1] = gCurrentPinballGame->coins / 10;
    sp0[0] = gCurrentPinballGame->coins % 10;
    gBG0TilemapBuffer[0x7D6] = 0xC19C;
    gBG0TilemapBuffer[0x7F6] = 0xC19D;
    gBG0TilemapBuffer[0x7D7] = (sp0[1] + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7F7] = (sp0[1] + 5) * 2 - 0x3E9F;
    gBG0TilemapBuffer[0x7D8] = (sp0[0] + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7F8] = (sp0[0] + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->numLives > 9)
        gCurrentPinballGame->numLives = 9;
    gBG0TilemapBuffer[0x7DA] = 0xC180;
    gBG0TilemapBuffer[0x7FA] = 0xC181;
    gBG0TilemapBuffer[0x7DB] = (gCurrentPinballGame->numLives + 5) * 2 - 0x3EA0;
    gBG0TilemapBuffer[0x7FB] = (gCurrentPinballGame->numLives + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->chargeFillValue == 13)
    {
        if (gCurrentPinballGame->fullChargeIndicatorBlinkTimer & 0x8)
        {
            gBG0TilemapBuffer[0x7DD] = 0xC19A;
            gBG0TilemapBuffer[0x7FD] = 0xC19B;
        }
        else
        {
            gBG0TilemapBuffer[0x7DD] = 0xC182;
            gBG0TilemapBuffer[0x7FD] = 0xC183;
        }

        if (gCurrentPinballGame->fullChargeIndicatorBlinkTimer)
            gCurrentPinballGame->fullChargeIndicatorBlinkTimer--;
    }
    else
    {
        gBG0TilemapBuffer[0x7DD] = 0xC19E;
        gBG0TilemapBuffer[0x7FD] = 0xC19F;
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x7C0], (void *)0x06002F80, 0x80);
}

void ProcessEventTimer(void)
{
    s16 i;
    s16 sp0[4];
    s16 var2;

    if (gCurrentPinballGame->boardModeType == 0)
        return;

    if (gCurrentPinballGame->eventTimer == 0)
        return;

    if (gCurrentPinballGame->boardModeType == 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        gCurrentPinballGame->eventTimer--;

    sp0[0] = gCurrentPinballGame->eventTimer / 3600;
    var2 = gCurrentPinballGame->eventTimer % 3600;
    sp0[1] = 10;
    sp0[2] = var2 / 600;
    var2 %= 600;
    sp0[3] = var2 / 60;
    if (gCurrentPinballGame->boardModeType == 3)
    {
        for (i = 0; i < 4; i++)
        {
            gBG0TilemapBuffer[0x179 + i] = 0x1FF;
            gBG0TilemapBuffer[0x199 + i] = 0x1FF;
        }

        DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
        gCurrentPinballGame->boardModeType = 0;
        gCurrentPinballGame->eventTimer = 0;
    }
    else
    {
        if (gCurrentPinballGame->eventTimer == 0)
        {
            ResetEventState();
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gBG0TilemapBuffer[i + 0x179] = sp0[i] * 2 - 0x3EC0;
                gBG0TilemapBuffer[i + 0x199] = sp0[i] * 2 - 0x3EBF;
            }
        }
        DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
    }

    if (gCurrentPinballGame->eventTimer <= 900)
    {
        if (gCurrentPinballGame->eventTimer & 0x8)
        {
            DmaCopy16(3, gTimerWarningPalette_Fast, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gDefaultBallPalette, (void *)0x05000180, 0x20);
        }

        if (gCurrentPinballGame->eventTimer == 900)
            m4aSongNumStart(MUS_HURRY_UP);
    }
    else if (gCurrentPinballGame->eventTimer <= 1800)
    {
        if ((gCurrentPinballGame->eventTimer % 22) / 11)
        {
            DmaCopy16(3, gTimerWarningPalette_Slow, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gDefaultBallPalette, (void *)0x05000180, 0x20);
        }
    }
}

void ResetEventState(void)
{
    s16 i;

    gCurrentPinballGame->boardModeType = 0;
    gCurrentPinballGame->eventTimer = 0;
    for (i = 0; i < 4; i++)
    {
        gBG0TilemapBuffer[0x179 + i] = 0x1FF;
        gBG0TilemapBuffer[0x199 + i] = 0x1FF;
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
}
