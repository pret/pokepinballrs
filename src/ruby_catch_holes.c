#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"
#include "functions_ruby.h"

void InitSharpedoCatchMode(void);
void AnimateSharpedoCatchSequence(void);
void InitRubyEvolutionShopMode(void);
void AnimateRubyEvolutionShopSequence(void);
void AnimateRubyEggHatchSequence(void);
void AnimateTotodileEggDelivery(void);
void InitAerodactylEggDelivery(void);
void AnimateAerodactylEggDelivery(void);

void DispatchRubyCatchModeInit(void)
{
    if (gMain.modeChangeFlags != MODE_CHANGE_NONE)
        return;

    switch (gCurrentPinballGame->ballCatchState)
    {
    case TRAP_CATCH_HOLE:
        InitSharpedoCatchMode();
        break;
    case TRAP_EGG_HOLE:
        InitRubyEggHatchMode();
        break;
    case TRAP_EVO_SHOP_HOLE:
        InitRubyEvolutionShopMode();
        break;
    case TRAP_CENTER_HOLE:
        InitCenterTrapMode();
        break;
    }

    gCurrentPinballGame->collisionCooldownTimer = 60;
}

void UpdateRubyCatchModeAnimation(void)
{
    if (gCurrentPinballGame->collisionCooldownTimer > 0)
        gCurrentPinballGame->collisionCooldownTimer--;

    switch (gCurrentPinballGame->ballCatchState)
    {
    case TRAP_CATCH_HOLE:
        AnimateSharpedoCatchSequence(); // Catch hole
        break;
    case TRAP_EGG_HOLE:
        AnimateRubyEggHatchSequence(); //Hatch hole
        break;
    case TRAP_EVO_SHOP_HOLE:
        AnimateRubyEvolutionShopSequence(); //Mart / Evo hole
        break;
    case TRAP_CENTER_HOLE:
        AnimateCenterTrapSequence(); //Center Hole
        break;
    }
}

void InitSharpedoCatchMode(void)
{
    if (gCurrentPinballGame->catchArrowProgress > 1)
    {
        RequestBoardStateTransition(4);
    }

    gCurrentPinballGame->cameraScrollOffset = 0;
    gCurrentPinballGame->cameraScrollEnabled = 0;
    gCurrentPinballGame->cameraScrollTarget = 0;
    gCurrentPinballGame->modeAnimTimer = 113;

    m4aSongNumStart(SE_UNKNOWN_0xCE);
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    PlayRumble(8);
}

/*
* Ruby board Sharpedo; during the initation of the catch mode
* Echoes UpdateSapphireWailmerCatchSequence, which is the equivalent 'catch hole' on the sapphire board.
*
* Note: this *does not* affect the start of the catch mode itself.
* When this function is nulled out at UpdateRubyCatchModeAnimation, the banner *doesn't* show, and
* the ball bounces off the sharpedo. However, the grid still shows a picked mon,
* and the mode otherwise works mostly normally, with the exception of affecting
* the 'tilt' behavior, and the collision with the cyndaquil pushback.
*/
void AnimateSharpedoCatchSequence(void)
{
    if (gCurrentPinballGame->modeAnimTimer) //Countdown timer; ball grabbed/held while banner shows
    {
        gCurrentPinballGame->modeAnimTimer--;
        if (gCurrentPinballGame->modeAnimTimer > 100)
        {
            gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
            gCurrentPinballGame->ballFrozenState = 1;

            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spinSpeed = 0;

            if (gCurrentPinballGame->modeAnimTimer > 108)
            {
                gCurrentPinballGame->boardEntityActive = 1;

                if (gCurrentPinballGame->modeAnimTimer > 110)
                {
                    gCurrentPinballGame->ball->positionQ0.x = 195;
                    gCurrentPinballGame->ball->positionQ0.y = 222;
                }
                else
                {
                    gCurrentPinballGame->ball->positionQ0.x = 196;
                    gCurrentPinballGame->ball->positionQ0.y = 221;
                }
                //Presumed controling either the message board 'state'/'tile'
                // or the sharpedo animation 'state'/tile.
                gCurrentPinballGame->catchHoleAnimFrame =6;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 104)
            {
                gCurrentPinballGame->ball->positionQ0.x = 197;
                gCurrentPinballGame->ball->positionQ0.y = 219;
                gCurrentPinballGame->catchHoleAnimFrame = 7;
            }
            else
            {
                gCurrentPinballGame->ball->ballHidden = 1;
                gCurrentPinballGame->catchHoleAnimFrame = 8;
            }
        }
        else if (gCurrentPinballGame->modeAnimTimer > 20)
        {
            if (gCurrentPinballGame->modeAnimTimer > 77)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 9;

                if (gCurrentPinballGame->modeAnimTimer < 80)
                {
                    if (gCurrentPinballGame->catchHolePauseTimer != 0)
                    {
                        gCurrentPinballGame->catchHolePauseTimer--;
                        gCurrentPinballGame->modeAnimTimer++;
                    }
                }
            }
            else if (gCurrentPinballGame->modeAnimTimer > 72)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 10;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 67)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 11;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 44)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 12;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 38)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 13;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 28)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 14;
            }
            else if (gCurrentPinballGame->modeAnimTimer > 23)
            {
                gCurrentPinballGame->catchHoleAnimFrame = 15;
            }
            else {
                gCurrentPinballGame->catchHoleAnimFrame = 16;
            }
        }
        else if (gCurrentPinballGame->modeAnimTimer > 18)
        {
            gCurrentPinballGame->ball->positionQ0.x = 193;
            gCurrentPinballGame->ball->positionQ0.y = 226;
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->catchHoleAnimFrame = 17;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 16)
        {
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->cameraScrollTarget = 0;
            gCurrentPinballGame->cameraScrollEnabled = 1;
            gCurrentPinballGame->boardEntityActive = 0;
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->ball->velocity.x = 0xFF56;
            gCurrentPinballGame->ball->velocity.y = 220;
            gCurrentPinballGame->ball->positionQ0.x = 190;
            gCurrentPinballGame->ball->positionQ0.y = 232;
            gCurrentPinballGame->catchHoleAnimFrame = 18;
            if (gCurrentPinballGame->modeAnimTimer == 18)
            {
                m4aSongNumStart(194);
                PlayRumble(7);
            }
        }
        else if (gCurrentPinballGame->modeAnimTimer > 12)
        {
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->catchHoleAnimFrame = 19;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 8)
        {
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->catchHoleAnimFrame = 20;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 4)
        {
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->catchHoleAnimFrame = 21;
        }
        else
        {
            gCurrentPinballGame->catchHoleAnimFrame = 22;
        }
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->ball->positionQ8.x= gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

    }
    else
    {
        gCurrentPinballGame->collisionCooldownTimer = 30;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ballCatchState = NOT_TRAPPED;
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        gCurrentPinballGame->catchHoleAnimFrame = 0;
    }
}

void InitRubyEggHatchMode(void)
{
    gCurrentPinballGame->scoreAddedInFrame = 100000;
    if (gCurrentPinballGame->eggCaveState == 3)
    {
        gCurrentPinballGame->eggCaveState = 4;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        gCurrentPinballGame->modeAnimTimer = 500;
    }
    else if (gCurrentPinballGame->rubyEggDeliveryState !=0)
    {
        gCurrentPinballGame->modeAnimTimer = 300;
    }
    else
    {
        gCurrentPinballGame->modeAnimTimer = 120;
    }

    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
}

void AnimateRubyEggHatchSequence(void)
{
    u16 modeAnimTimer = gCurrentPinballGame->modeAnimTimer;

    if (modeAnimTimer != 0)
    {
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->modeAnimTimer--;

        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0x94;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        if (gCurrentPinballGame->rubyEggDeliveryState != 1)
            return;
        if (gCurrentPinballGame->modeAnimTimer > 0xC8)
            return;

        if (gCurrentPinballGame->modeAnimTimer == 0xC8)
        {
            if (gCurrentPinballGame->activePortraitType != 0)
                gCurrentPinballGame->modeAnimTimer++;
            else
            {
                if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                    InitTotodileEggDelivery();
                else
                    InitAerodactylEggDelivery();
            }
        }
        else
        {
            if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                AnimateTotodileEggDelivery();
            else
                AnimateAerodactylEggDelivery();
        }
        if (gCurrentPinballGame->modeAnimTimer <= 9)
            gCurrentPinballGame->modeAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->ball->ballHidden = 0;
        gCurrentPinballGame->ballCatchState = NOT_TRAPPED;

        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0xA2;
        gCurrentPinballGame->ball->spinSpeed = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ballUpgradeTimerFrozen = 0;

        if (gCurrentPinballGame->rubyEggDeliveryState == 2)
        {
            gCurrentPinballGame->eggCaveState = 3;
            gCurrentPinballGame->eggCaveLiftTimer = 0x30;
            gCurrentPinballGame->eggCaveExitDelayTimer = 0x1E;
        }
        else
        {
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->collisionCooldownTimer = 0x3C;
            gCurrentPinballGame->ball->velocity.x = 0x14;
            gCurrentPinballGame->ball->velocity.y = 0xC8;
        }
    }
}

void InitRubyEvolutionShopMode(void)
{
    gCurrentPinballGame->shopAnimSlideTimer = 0;
    gCurrentPinballGame->shopUISlideOffset = 0;
    gCurrentPinballGame->modeAnimTimer = 0xB4;
    gCurrentPinballGame->shopEntryTimer = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
}

void AnimateRubyEvolutionShopSequence(void)
{

    if (gCurrentPinballGame->modeAnimTimer > 0x18)
    {
        gCurrentPinballGame->ball->ballHidden = 1;
        gCurrentPinballGame->ballFrozenState = 1;
        gCurrentPinballGame->modeAnimTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xDC;
        gCurrentPinballGame->ball->positionQ0.y = 0x62;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x * 256;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y * 256;

        if (gCurrentPinballGame->modeAnimTimer > 0x9B)
            gCurrentPinballGame->shopDoorTargetFrame = (gCurrentPinballGame->modeAnimTimer - 0x9C) / 8;
        if (gCurrentPinballGame->modeAnimTimer <= 0x31)
            gCurrentPinballGame->modeAnimTimer++;

        UpdateShopEntryAnimation(gCurrentPinballGame->evolutionShopActive);
        return;
    }

    if (gCurrentPinballGame->modeAnimTimer > 0)
    {
        gCurrentPinballGame->modeAnimTimer--;
        gCurrentPinballGame->shopDoorTargetFrame = (0x18 - gCurrentPinballGame->modeAnimTimer) / 8;
        return;
    }

    gCurrentPinballGame->ball->ballHidden = 0;
    gCurrentPinballGame->ballFrozenState = 0;
    gCurrentPinballGame->collisionCooldownTimer = 0x3C;

    gCurrentPinballGame->ball->velocity.x = 0x60;
    gCurrentPinballGame->ball->velocity.y = 0xC0;
    gCurrentPinballGame->ball->positionQ0.x = 0xDF;
    gCurrentPinballGame->ball->positionQ0.y = 0x63;

    gCurrentPinballGame->ball->spinSpeed = 0;
    gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
    gCurrentPinballGame->ballCatchState = NOT_TRAPPED;
    gCurrentPinballGame->shopDoorTargetFrame = 0x13;

    m4aSongNumStart(SE_UNKNOWN_0xC3);

    if (gCurrentPinballGame->evoArrowProgress > 2 && gCurrentPinballGame->evolvablePartySize > 0)
    {
        RequestBoardStateTransition(6);
    }
}
