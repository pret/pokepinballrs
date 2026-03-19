#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern const void (*gBoardStateInitFuncs[])(void);
extern const void (*gBoardStateUpdateFuncs[])(void);

extern void HandleBoardStateTransitionTeardown(void);

void RequestBoardStateTransition(u8 arg0)
{
    gCurrentPinballGame->boardTransitionPhase = 2;
    gCurrentPinballGame->nextBoardState = arg0;
    if (gCurrentPinballGame->boardState == 2)
        gMain.fieldSpriteGroups[13]->available = 0;
}

void BoardStateDispatcher(void)
{
    switch (gCurrentPinballGame->boardTransitionPhase)
    {
        case 0:
            gBoardStateInitFuncs[gCurrentPinballGame->boardState]();
            gCurrentPinballGame->boardTransitionPhase++;
            break;
        case 1:
            gBoardStateUpdateFuncs[gCurrentPinballGame->boardState]();
            break;
        case 2:
            HandleBoardStateTransitionTeardown();
            gCurrentPinballGame->prevBoardState = gCurrentPinballGame->boardState;
            gCurrentPinballGame->boardState = gCurrentPinballGame->nextBoardState;
            gCurrentPinballGame->boardTransitionPhase = 0;
            break;
    }
}

void InitFieldIdle(void)
{
    s16 num1;
    u8 num2;

    if (gCurrentPinballGame->prevBoardState > 0)
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
    if (num2 > 1)
    {
        gCurrentPinballGame->evoArrowProgress = gCurrentPinballGame->arrowProgressPreserved;
        gCurrentPinballGame->catchArrowProgress = gCurrentPinballGame->catchModeArrows;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->catchModeArrows = 0;
    }
}

void UpdateFieldIdle(void)
{
    if (gCurrentPinballGame->allHolesLit != 0)
    {
        if (gCurrentPinballGame->allHolesLitDelayTimer != 0)
        {
            gCurrentPinballGame->allHolesLitDelayTimer--;
        }
        else
        {
            RequestBoardStateTransition(2);
        }
    }
}

void HandleBoardStateTransitionTeardown(void)
{
    if (gCurrentPinballGame->boardState == 2 && gCurrentPinballGame->nextBoardState > 2)
        ResetCatchState(0);

    if (gCurrentPinballGame->boardState > 2)
        return;

    if (gCurrentPinballGame->nextBoardState == 3)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }

    if (gCurrentPinballGame->nextBoardState == 4)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState == 6)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->arrowProgressPreserved = 0;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
    else if (gCurrentPinballGame->nextBoardState > 3)
    {
        gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->catchArrowProgress = 0;
    }
}
