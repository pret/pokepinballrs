#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

#define AREAS_NEEDED_BEFORE_RUINS_APPEARS 5

extern const u8 gDefaultTimerPalette[];

void CleanupTravelModeState(void)
{
    gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_NONE;
    gCurrentPinballGame->seedotCount = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->gulpinCurrentLevel = 0;
        gCurrentPinballGame->gulpinAnimFrameIndex = 0;
        gCurrentPinballGame->gulpinAnimFrameTimer = 0;
    }

    gCurrentPinballGame->seedotExitSequenceActive = TRUE;
    gCurrentPinballGame->seedotExitSequenceTimer = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = FALSE;
    gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0] = 0;
    gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1] = 0;
    gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2] = 0;
    ResetEventState();
}

void InitTravelMode(void)
{
    gCurrentPinballGame->boardSubState = TRAVEL_SUBSTATE_INIT;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 3600;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->saverTimeRemaining = 1800;
    DmaCopy16(3, gDefaultTimerPalette, (void *)0x05000180, 0x20);
}

void UpdateTravelMode(void)
{
    s16 var0;

    if (gCurrentPinballGame->eventTimerType
        && gCurrentPinballGame->eventTimer < 2
        && gCurrentPinballGame->boardSubState < TRAVEL_SUBSTATE_BOARD_STATE_CLEANUP)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = TRAVEL_SUBSTATE_BOARD_STATE_CLEANUP;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case TRAVEL_SUBSTATE_INIT:
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->portraitCycleFrame = 0;
        }
        gCurrentPinballGame->travelRolloverTriggerHitZone = TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_NONE;
        break;
    case TRAVEL_SUBSTATE_SHOW_LANE_INDICATORS:
        LoadPortraitGraphics(PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR, PORTRAIT_MAIN_SLOT);
        if (gCurrentPinballGame->stageTimer == 35)
            m4aSongNumStart(MUS_TRAVEL_MODE);

        if (gCurrentPinballGame->travelRolloverTriggerHitZone != TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_NONE)
        {
            gCurrentPinballGame->boardSubState++;
            if (gCurrentPinballGame->stageTimer < 35)
                m4aSongNumStart(MUS_TRAVEL_MODE);

            gCurrentPinballGame->seedotCount = 0;
            gCurrentPinballGame->seedotExitSequenceActive = TRUE;
            gCurrentPinballGame->seedotExitSequenceTimer = 0;
        }

        var0 = (gCurrentPinballGame->stageTimer % 40) / 10;
        gCurrentPinballGame->stageTimer++;
        if (var0 == 0)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 0;
            gCurrentPinballGame->travelArrowTiles[1] = 0;
            gCurrentPinballGame->travelArrowTiles[2] = 0;
        }
        else if (var0 == 1)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 1;
            gCurrentPinballGame->travelArrowTiles[2] = 0;
        }
        else if (var0 == 2)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 3;
            gCurrentPinballGame->travelArrowTiles[2] = 2;
        }
        else
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 3;
            gCurrentPinballGame->travelArrowTiles[2] = 3;
        }

        gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0];
        gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1];
        gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2];
        break;
    case TRAVEL_SUBSTATE_STOP_LANE_INDICATORS:
        ShowBonusTrapSprite();
        gCurrentPinballGame->trapAnimState = 2;
        LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
        gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0] = 0;
        gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1] = 0;
        gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2] = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case TRAVEL_SUBSTATE_OPEN_TRAP_DOOR:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
            gCurrentPinballGame->boardSubState++;
        break;
    case TRAVEL_SUBSTATE_GRAVITY_WELL:
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        gCurrentPinballGame->modeOutcomeValues[0] = 47;
        LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
        break;
    case TRAVEL_SUBSTATE_CONFIRMATION_AND_TRAVEL_CUTSCENE:
        if (gCurrentPinballGame->modeAnimTimer == 145)
        {
            gCurrentPinballGame->modeAnimTimer++;
            gCurrentPinballGame->modeOutcomeValues[0] = 47;
            LoadPortraitGraphics(PORTRAIT_STATE_CONFIRMATION_PROMPT, PORTRAIT_MAIN_SLOT);
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->modeAnimTimer = 144;
                m4aMPlayAllStop();
                LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
                if (gCurrentPinballGame->areaVisitCount < AREAS_NEEDED_BEFORE_RUINS_APPEARS)
                {
                    var0 = gCurrentPinballGame->areaRouletteFarSlot;
                    if (gCurrentPinballGame->travelRolloverTriggerHitZone == TRAVEL_ROLLOVER_TRIGGER_HIT_ZONE_LEFT)
                        gCurrentPinballGame->areaRouletteSlotIndex = gCurrentPinballGame->areaRouletteNextSlot;
                    else
                        gCurrentPinballGame->areaRouletteSlotIndex = gCurrentPinballGame->areaRouletteFarSlot;

                    gCurrentPinballGame->areaRouletteNextSlot = (var0 + 1) % AREA_ROULETTE_SLOT_COUNT;
                    gCurrentPinballGame->areaRouletteFarSlot = (var0 + 2) % AREA_ROULETTE_SLOT_COUNT;
                    gCurrentPinballGame->areaVisitCount++;
                }
                else
                {
                    gCurrentPinballGame->areaRouletteSlotIndex = AREA_BONUS_RUIN_SLOT_IX;
                    gCurrentPinballGame->areaVisitCount = 0;
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->modeAnimTimer = 60;
                gCurrentPinballGame->boardSubState = TRAVEL_SUBSTATE_BOARD_STATE_CLEANUP;
                if (gCurrentPinballGame->allHolesLit)
                    gCurrentPinballGame->allHolesLitDelayTimer = 120;
            }
        }

        if (gCurrentPinballGame->modeAnimTimer == 130)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (gCurrentPinballGame->stageTimer < 490)
            {
                RunTravelEventCutscene();
                if (gCurrentPinballGame->scoreCounterAnimationEnabled && gCurrentPinballGame->stageTimer >= 428)
                    gCurrentPinballGame->stageTimer = 428;

                if (gCurrentPinballGame->stageTimer == 394)
                {
                    gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                    gCurrentPinballGame->scoreAddedInFrame = 500000;
                }
            }
            else
            {
                gCurrentPinballGame->modeAnimTimer = 120;
            }

            gCurrentPinballGame->stageTimer++;
        }
        else if (gCurrentPinballGame->modeAnimTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
            if (gCurrentPinballGame->travelModeCompletionCount < 99)
                gCurrentPinballGame->travelModeCompletionCount++;
        }
        break;
    case TRAVEL_SUBSTATE_BOARD_STATE_CLEANUP:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
        CleanupTravelModeState();
        gCurrentPinballGame->boardSubState++;
        break;
    case TRAVEL_SUBSTATE_PREPARE_NEXT_BOARD_MODE:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
        }
        break;
    }
}
