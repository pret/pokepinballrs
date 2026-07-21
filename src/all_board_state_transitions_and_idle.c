#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

extern const void (*gBoardStateInitFuncs[])(void);
extern const void (*gBoardStateUpdateFuncs[])(void);

extern void HandleBoardStateTransitionTeardown(void);

void RequestBoardStateTransition(u8 boardState)
{
    gCurrentPinballGame->boardTransitionPhase = BOARD_STATE_DISPATCHER_STATE_CHANGING;
    gCurrentPinballGame->nextBoardState = boardState;
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
        gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
}

void BoardStateDispatcher(void)
{
    switch (gCurrentPinballGame->boardTransitionPhase)
    {
        case BOARD_STATE_DISPATCHER_STATE_INIT:
            gBoardStateInitFuncs[gCurrentPinballGame->boardState]();
            gCurrentPinballGame->boardTransitionPhase++;
            break;
        case BOARD_STATE_DISPATCHER_STATE_RUNNING:
            gBoardStateUpdateFuncs[gCurrentPinballGame->boardState]();
            break;
        case BOARD_STATE_DISPATCHER_STATE_CHANGING:
            HandleBoardStateTransitionTeardown();
            gCurrentPinballGame->prevBoardState = gCurrentPinballGame->boardState;
            gCurrentPinballGame->boardState = gCurrentPinballGame->nextBoardState;
            gCurrentPinballGame->boardTransitionPhase = BOARD_STATE_DISPATCHER_STATE_INIT;
            break;
    }
}

void InitFieldIdle(void)
{
    s16 num1;
    u8 num2;

    if (gCurrentPinballGame->prevBoardState >= MAIN_BOARD_STATE_DEFAULT)
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

    num2 = gCurrentPinballGame->prevBoardState - 1;
    if (num2 > MAIN_BOARD_STATE_DEFAULT)
    {
        gCurrentPinballGame->evoArrowProgress = gCurrentPinballGame->arrowProgressPreserved;
        gCurrentPinballGame->catchArrowProgress = gCurrentPinballGame->catchModeArrows;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->catchModeArrows = 0;
    }
}

void UpdateFieldIdle(void)
{
    if (gCurrentPinballGame->allHolesLit)
    {
        if (gCurrentPinballGame->allHolesLitDelayTimer != 0)
        {
            gCurrentPinballGame->allHolesLitDelayTimer--;
        }
        else
        {
            RequestBoardStateTransition(MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE);
        }
    }
}

void HandleBoardStateTransitionTeardown(void)
{
    if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE && 
        gCurrentPinballGame->nextBoardState > MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
        ResetCatchState(0);

    if (gCurrentPinballGame->boardState > MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
        return;

    if (gCurrentPinballGame->nextBoardState == MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }

    if (gCurrentPinballGame->nextBoardState == MAIN_BOARD_STATE_CATCH_EM_MODE)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState == MAIN_BOARD_STATE_EVO_MODE)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState >= MAIN_BOARD_STATE_ACTIVITY_BASE)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
}
