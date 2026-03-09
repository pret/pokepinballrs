#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"



void AllBoardProcess_1A_47100(void)
{
    gCurrentPinballGame->bonusPanelOffsetY = 128;
}

void ClearAllBgScreenBuffer(void)
{
    s16 i;

    for (i = 0; i < 0x800; i++)
        gBgScreenBuffer[i] = 0x1FF;

    DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x1000);
}


void AllBoardProcess_1B_47160(void)
{
    if (JOY_NEW(START_BUTTON) && gMain.mainState != STATE_GAME_IDLE && gCurrentPinballGame->pauseInputLocked == 0)
    {
        if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        {
            gMain.modeChangeFlags &= ~MODE_CHANGE_PAUSE;
            UnpauseGame();
        }
        else if ((gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME) == 0)
        {
            gMain.modeChangeFlags |= MODE_CHANGE_PAUSE;
            PauseGame();
        }
    }

    //Game is paused
    if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            gCurrentPinballGame->pauseMenuCursorIndex ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(DPAD_DOWN))
        {
            gCurrentPinballGame->pauseMenuCursorIndex ^= 1;
            m4aSongNumStart(SE_UNKNOWN_0xA3);
        }

        if (JOY_NEW(A_BUTTON) && !JOY_HELD(B_BUTTON | SELECT_BUTTON | START_BUTTON))
        {
            if (gCurrentPinballGame->pauseMenuCursorIndex == 0)
            {
                gMain.gameIdleState = 2;
                SetupGameEndSprites();
            }

            gMain.modeChangeFlags &= ~MODE_CHANGE_PAUSE;
            UnpauseGame();
            gMain.newKeys &= ~A_BUTTON;
        }

        if (JOY_NEW(B_BUTTON))
        {
            gMain.modeChangeFlags &= ~MODE_CHANGE_PAUSE;
            UnpauseGame();
            gMain.newKeys &= ~B_BUTTON;
        }

        if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
            DrawPauseMenuOverlay();
    }

    //Game is not paused
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        gCurrentPinballGame->debugMenuSelection = 0;
        if (gMain.modeTransitionDelay != 0)
        {
            gMain.modeTransitionDelay--;
            if (gMain.modeTransitionDelay == 1)
            {
                if (gCurrentPinballGame->bannerType)
                    gMain.modeTransitionDelay = 10;
                else if (gMain.pendingModeChangeFlags == 0x8)
                    gCurrentPinballGame->bannerType = 19;
                else
                    gCurrentPinballGame->bannerType = 20;
            }

            if (gMain.modeTransitionDelay == 0)
                gMain.modeChangeFlags = gMain.pendingModeChangeFlags;
        }
    }
}

