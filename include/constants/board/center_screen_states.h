#ifndef GUARD_CENTER_SCREEN_STATES_H
#define GUARD_CENTER_SCREEN_STATES_H

#include "prize_definitions.h"

// Portrait/CenterScreen is for the 'screen' that shows the location, travel indicator, roulette wheel
// catch picture, etc.
enum PortraitDisplayMode{
    PORTRAIT_DISPLAY_MODE_BOARD_CENTER = 0,
    PORTRAIT_DISPLAY_MODE_ROULETTE = 1,
    PORTRAIT_DISPLAY_MODE_SHOP = 2,
    PORTRAIT_DISPLAY_MODE_BANNER = 3,
};

enum PortraitStates{
    PORTRAIT_STATE_CURRENT_LOCATION = 0,
    PORTRAIT_STATE_SLOT_START_CARD = 1,
    PORTRAIT_STATE_ROULETTE_WHEEL = 2,
    PORTRAIT_STATE_POKEMON_DISPLAY = 3,
    PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR = 4,
    PORTRAIT_STATE_5 = 5, //Unused
    PORTRAIT_STATE_SHOP_SELECTOR = 6,
    PORTRAIT_STATE_CONFIRMATION_PROMPT = 7,
    PORTRAIT_STATE_ROULETTE_OUTCOME = 8,
    PORTRAIT_STATE_EVO_PREVIEW = 9,
};

enum PortraitSlot{
    PORTRAIT_MAIN_SLOT = 0,
    PORTRAIT_ALT_SLOT = 1,
};

// Inactive: no special override of the ball handling logic for the capture process
// Mon_hit_in_catch_mode: extremely short lived. Returns to inactive after adding
//    additional bounce strength to the ball.
// Capture Cutscene: ball flies around in circles, opens up, and absorbs mon.
enum MonCaptureSpecialStates{
    MON_CAPTURE_SPECIAL_STATE_INACTIVE = 0,
    MON_CAPTURE_SPECIAL_STATE_MON_HIT_IN_CATCH_MODE = 1,
    MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE = 2,
};

#endif //GUARD_CENTER_SCREEN_STATES_H