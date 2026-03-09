#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gUnknown_086B0884[];
extern const u8 gUnknown_081C0064[];
extern const u8 gUnknown_086B08A4[];

void AllBoardProcess_8A_4CEA8(void)
{
    AllBoardProcess_8B_4CEB4();
}

void AllBoardProcess_8B_4CEB4(void)
{
    s16 i, j;
    s16 sp0[12];
    u32 value;

    UpdateEventTimerDisplay();
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
                    m4aSongNumStart(SE_UNKNOWN_0x91);
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
        gBgScreenBuffer[0x7C1 + (j - i)] = sp0[j] * 2 - 0x3EA0;
        gBgScreenBuffer[0x7E1 + (j - i)] = sp0[j] * 2 - 0x3E9F;
    }

    if (gCurrentPinballGame->caughtMonCount > 999)
        gCurrentPinballGame->caughtMonCount = 999;
    sp0[2] = gCurrentPinballGame->caughtMonCount / 100;
    sp0[1] = (gCurrentPinballGame->caughtMonCount % 100) / 10;
    sp0[0] = gCurrentPinballGame->caughtMonCount % 10;
    gBgScreenBuffer[0x7D1] = 0xC17E;
    gBgScreenBuffer[0x7F1] = 0xC17F;
    gBgScreenBuffer[0x7D2] = (sp0[2] + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7F2] = (sp0[2] + 5) * 2 - 0x3E9F;
    gBgScreenBuffer[0x7D3] = (sp0[1] + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7F3] = (sp0[1] + 5) * 2 - 0x3E9F;
    gBgScreenBuffer[0x7D4] = (sp0[0] + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7F4] = (sp0[0] + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->coins > 99)
        gCurrentPinballGame->coins = 99;
    sp0[1] = gCurrentPinballGame->coins / 10;
    sp0[0] = gCurrentPinballGame->coins % 10;
    gBgScreenBuffer[0x7D6] = 0xC19C;
    gBgScreenBuffer[0x7F6] = 0xC19D;
    gBgScreenBuffer[0x7D7] = (sp0[1] + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7F7] = (sp0[1] + 5) * 2 - 0x3E9F;
    gBgScreenBuffer[0x7D8] = (sp0[0] + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7F8] = (sp0[0] + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->numLives > 9)
        gCurrentPinballGame->numLives = 9;
    gBgScreenBuffer[0x7DA] = 0xC180;
    gBgScreenBuffer[0x7FA] = 0xC181;
    gBgScreenBuffer[0x7DB] = (gCurrentPinballGame->numLives + 5) * 2 - 0x3EA0;
    gBgScreenBuffer[0x7FB] = (gCurrentPinballGame->numLives + 5) * 2 - 0x3E9F;

    if (gCurrentPinballGame->pikaChargeSegment == 13)
    {
        if (gCurrentPinballGame->pikaChargeFullFlashTimer & 0x8)
        {
            gBgScreenBuffer[0x7DD] = 0xC19A;
            gBgScreenBuffer[0x7FD] = 0xC19B;
        }
        else
        {
            gBgScreenBuffer[0x7DD] = 0xC182;
            gBgScreenBuffer[0x7FD] = 0xC183;
        }

        if (gCurrentPinballGame->pikaChargeFullFlashTimer)
            gCurrentPinballGame->pikaChargeFullFlashTimer--;
    }
    else
    {
        gBgScreenBuffer[0x7DD] = 0xC19E;
        gBgScreenBuffer[0x7FD] = 0xC19F;
    }

    DmaCopy16(3, &gBgScreenBuffer[0x7C0], (void *)0x06002F80, 0x80);
}

void UpdateEventTimerDisplay(void)
{
    s16 i;
    s16 sp0[4];
    s16 var2;

    if (gCurrentPinballGame->entityActivePhase == 0)
        return;

    if (gCurrentPinballGame->eventTimer == 0)
        return;

    if (gCurrentPinballGame->entityActivePhase == 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        gCurrentPinballGame->eventTimer--;

    sp0[0] = gCurrentPinballGame->eventTimer / 3600;
    var2 = gCurrentPinballGame->eventTimer % 3600;
    sp0[1] = 10;
    sp0[2] = var2 / 600;
    var2 %= 600;
    sp0[3] = var2 / 60;
    if (gCurrentPinballGame->entityActivePhase == 3)
    {
        for (i = 0; i < 4; i++)
        {
            gBgScreenBuffer[0x179 + i] = 0x1FF;
            gBgScreenBuffer[0x199 + i] = 0x1FF;
        }

        DmaCopy16(3, &gBgScreenBuffer[0x160], (void *)0x060022C0, 0x80);
        gCurrentPinballGame->entityActivePhase = 0;
        gCurrentPinballGame->eventTimer = 0;
    }
    else
    {
        if (gCurrentPinballGame->eventTimer == 0)
        {
            ClearEventIndicatorDisplay();
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                gBgScreenBuffer[i + 0x179] = sp0[i] * 2 - 0x3EC0;
                gBgScreenBuffer[i + 0x199] = sp0[i] * 2 - 0x3EBF;
            }
        }
        DmaCopy16(3, &gBgScreenBuffer[0x160], (void *)0x060022C0, 0x80);
    }

    if (gCurrentPinballGame->eventTimer <= 900)
    {
        if (gCurrentPinballGame->eventTimer & 0x8)
        {
            DmaCopy16(3, gUnknown_086B0884, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
        }

        if (gCurrentPinballGame->eventTimer == 900)
            m4aSongNumStart(MUS_HURRY_UP);
    }
    else if (gCurrentPinballGame->eventTimer <= 1800)
    {
        if ((gCurrentPinballGame->eventTimer % 22) / 11)
        {
            DmaCopy16(3, gUnknown_086B08A4, (void *)0x05000180, 0x20);
        }
        else
        {
            DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
        }
    }
}

void ClearEventIndicatorDisplay(void)
{
    s16 i;

    gCurrentPinballGame->entityActivePhase = 0;
    gCurrentPinballGame->eventTimer = 0;
    for (i = 0; i < 4; i++)
    {
        gBgScreenBuffer[0x179 + i] = 0x1FF;
        gBgScreenBuffer[0x199 + i] = 0x1FF;
    }

    DmaCopy16(3, &gBgScreenBuffer[0x160], (void *)0x060022C0, 0x80);
}
