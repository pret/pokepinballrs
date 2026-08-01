#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/score.h"

#define TIMER_TEXT_YELLOW_UNDER_TIME TICKS_FOR_TIME(0,30)
#define TIMER_TEXT_RED_UNDER_TIME TICKS_FOR_TIME(0,15)

extern const u8 gTimerWarningPalette_Fast[];
extern const u8 gDefaultTimerPalette[];
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
        if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER] 
            || JOY_NEW(A_BUTTON))
        {
            gCurrentPinballGame->scoreLo += gCurrentPinballGame->scoreAdditionAccumulator;
            gCurrentPinballGame->scoreAdditionAccumulator = 0;
            gCurrentPinballGame->scoreCounterAnimationEnabled = FALSE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_DEFAULT;
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
                    gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_DEFAULT;
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

    if (gCurrentPinballGame->scoreLo / SCORE_HI_STEP != 0)
    {
        if (gCurrentPinballGame->scoreHi < SCORE_HIGH_MAX)
        {
            gCurrentPinballGame->scoreHi++;
            gCurrentPinballGame->scoreLo -= SCORE_HI_STEP;
        }
        else
        {
            gCurrentPinballGame->scoreHi = SCORE_HIGH_MAX;
            gCurrentPinballGame->scoreLo = SCORE_LO_MAX;
        }
    }

    gCurrentPinballGame->scoreAddedInFrame = 0;

    value = gCurrentPinballGame->scoreHi;
    sp0[0] = DIGIT_1K(value) + 5;
    sp0[1] = DIGIT_100S(value) + 5;
    sp0[2] = DIGIT_10S(value) + 19;
    sp0[3] = DIGIT_1S(value) + 5;

    value = gCurrentPinballGame->scoreLo;
    sp0[4] = LEAD_DIGIT_10M(value) + 5;
    sp0[5] = DIGIT_1M(value) + 19;
    sp0[6] = DIGIT_100K(value) + 5;
    sp0[7] = DIGIT_10K(value) + 5;
    sp0[8] = DIGIT_1K(value) + 19;
    sp0[9] = DIGIT_100S(value) + 5;
    sp0[10] = DIGIT_10S(value) + 5;
    sp0[11] = DIGIT_1S(value) + 5;

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
    sp0[2] = LEAD_DIGIT_100S(gCurrentPinballGame->caughtMonCount);
    sp0[1] = DIGIT_10S(gCurrentPinballGame->caughtMonCount);
    sp0[0] = DIGIT_1S(gCurrentPinballGame->caughtMonCount);
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
    sp0[1] = LEAD_DIGIT_10S(gCurrentPinballGame->coins);
    sp0[0] = DIGIT_1S(gCurrentPinballGame->coins);
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
    s16 timerDisplayChar[4];
    s16 var2;

    if (gCurrentPinballGame->eventTimerType == EVENT_TIMER_MODE_NONE)
        return;

    if (gCurrentPinballGame->eventTimer == 0)
        return;

    if (gCurrentPinballGame->eventTimerType == EVENT_TIMER_MODE_RUNNING
        && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        gCurrentPinballGame->eventTimer--;

    timerDisplayChar[0] = gCurrentPinballGame->eventTimer / TICKS_FOR_TIME(1,0);
    var2 = gCurrentPinballGame->eventTimer % TICKS_FOR_TIME(1,0);
    timerDisplayChar[1] = 10;
    timerDisplayChar[2] = var2 / TICKS_FOR_TIME(0,10);
    var2 %= TICKS_FOR_TIME(0,10);
    timerDisplayChar[3] = var2 / TICKS_FOR_TIME(0,1);
    if (gCurrentPinballGame->eventTimerType == EVENT_TIMER_MODE_COMPLETED)
    {
        for (i = 0; i < 4; i++)
        {
            gBG0TilemapBuffer[0x179 + i] = 0x1FF;
            gBG0TilemapBuffer[0x199 + i] = 0x1FF;
        }

        DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
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
                gBG0TilemapBuffer[i + 0x179] = timerDisplayChar[i] * 2 - 0x3EC0;
                gBG0TilemapBuffer[i + 0x199] = timerDisplayChar[i] * 2 - 0x3EBF;
            }
        }
        DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
    }

    if (gCurrentPinballGame->eventTimer <= TIMER_TEXT_RED_UNDER_TIME)
    {
        if (gCurrentPinballGame->eventTimer & 0x8)
        {
            DmaCopy16(3, gTimerWarningPalette_Fast, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gDefaultTimerPalette, (void *)0x05000180, 0x20);
        }

        if (gCurrentPinballGame->eventTimer == TIMER_TEXT_RED_UNDER_TIME)
            m4aSongNumStart(MUS_HURRY_UP);
    }
    else if (gCurrentPinballGame->eventTimer <= TIMER_TEXT_YELLOW_UNDER_TIME)
    {
        if ((gCurrentPinballGame->eventTimer % 22) / 11)
        {
            DmaCopy16(3, gTimerWarningPalette_Slow, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gDefaultTimerPalette, (void *)0x05000180, 0x20);
        }
    }
}

void ResetEventState(void)
{
    s16 i;

    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
    gCurrentPinballGame->eventTimer = 0;
    for (i = 0; i < 4; i++)
    {
        gBG0TilemapBuffer[0x179 + i] = 0x1FF;
        gBG0TilemapBuffer[0x199 + i] = 0x1FF;
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x160], (void *)0x060022C0, 0x80);
}
