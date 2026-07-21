#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"



void AllBoardProcess_1A_47100(void)
{
    gCurrentPinballGame->bonusSummarySlideY = 128;
}

void ClearBG0Tilemap(void)
{
    s16 i;

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[i] = 0x1FF;

    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x1000);
}


void AllBoardProcess_1B_47160(void)
{
    if (JOY_NEW(START_BUTTON) && gMain.mainState != STATE_GAME_IDLE
        && !gCurrentPinballGame->startButtonDisabled)
    {
        if (gMain.modeChangeFlags & MODE_CHANGE_PAUSE)
        {
            gMain.modeChangeFlags &= ~MODE_CHANGE_PAUSE;
            UnpauseGame();
        }
        else if (!(gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME))
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
            m4aSongNumStart(SE_PAUSE_CURSOR_MOVE);
        }

        if (JOY_NEW(DPAD_DOWN))
        {
            gCurrentPinballGame->pauseMenuCursorIndex ^= 1;
            m4aSongNumStart(SE_PAUSE_CURSOR_MOVE);
        }

        if (JOY_NEW(A_BUTTON) && !JOY_HELD(B_BUTTON | SELECT_BUTTON | START_BUTTON))
        {
            if (gCurrentPinballGame->pauseMenuCursorIndex == 0)
            {
                gMain.gameExitState = 2;
                PositionPauseMenuSprites();
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
            AnimatePauseMenuOverlay();
    }

    //Game is not paused
    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        gCurrentPinballGame->debugMenuSelection = 0;
        if (gMain.modeChangeDelayTimer != 0)
        {
            gMain.modeChangeDelayTimer--;
            if (gMain.modeChangeDelayTimer == 1)
            {
                if (gCurrentPinballGame->activePortraitType)
                    gMain.modeChangeDelayTimer = 10;
                else if (gMain.pendingModeChangeType == MODE_CHANGE_BALL_SAVER)
                    gCurrentPinballGame->activePortraitType = 19;
                else
                    gCurrentPinballGame->activePortraitType = 20;
            }

            if (gMain.modeChangeDelayTimer == 0)
                gMain.modeChangeFlags = gMain.pendingModeChangeType;
        }
    }
}

