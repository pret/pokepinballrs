#include "global.h"
#include "functions.h"
#include "functions_ruby.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

void RubyBoardProcess_3A_19A20(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    UpdateNuzleafEntity();
    LoadShopItemGraphics(0);
    AnimateRubyShopDoor();
    InitRubyEggModeAnimation();
    UpdateEggModeAnimation();

    gCurrentPinballGame->cyndaquilCaveSpriteX = 73;
    gCurrentPinballGame->cyndaquilCaveSpriteY = 154;
    gCurrentPinballGame->eggCaveState = 0;
    UpdateHatchCave();
    RubyPond_EntityLogic();

    gCurrentPinballGame->pondBumperStates[0] = 10;
    gCurrentPinballGame->pondBumperStates[1] = 10;
    gCurrentPinballGame->pondBumperStates[2] = 10;
    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_STAGGERED;
    RubyPondTriBumperHandleHitAndDraw();
    AnimateSharpedoEntity();

    gCurrentPinballGame->pikachuSpinFrame = 0;
    gCurrentPinballGame->pikachuSpinPrevFrame = 1;
    UpdatePikachuChargeCounter();
    ProcessChargeIndicator();
    DrawPikachuSpinner();

    gCurrentPinballGame->chargeIndicatorScaleX = 256;
    gCurrentPinballGame->chargeIndicatorScaleY = 256;
    gCurrentPinballGame->rampPrizeType = 2;
    DrawRubyNuzleafPlatformSprite();

    gCurrentPinballGame->sideBumperShakeOffset[0] = 3;
    gCurrentPinballGame->sideBumperShakeOffset[1] = 3;
    DrawBoardEdgeBanner();
}

void RubyBoardProcess_3B_19B10(void)
{
    BoardStateDispatcher();
    UpdateRubyBoardEntityRendering();

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        UpdateRubyBoardEntityLogic();
    }

    HandleRubyFlipperButtonInput();
    if (gCurrentPinballGame->bgmFadeTimer != 0)
    {
        gCurrentPinballGame->bgmFadeTimer--;
        if (gCurrentPinballGame->bgmFadeTimer == 0)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        }
    }
}
