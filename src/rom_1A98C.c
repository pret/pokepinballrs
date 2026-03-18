#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

void AnimateSharpedoCatchSequence(void);
void InitSharpedoCatchMode(void);
void AnimateEggHatchSequence(void);
void InitRubyEvolutionShopMode(void);
void AnimateRubyEvolutionShopSequence(void);
void InitCenterTrapMode(void);
void AnimateCenterTrapSequence(void);
void RequestBoardStateTransition(u8);
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
        InitEggHatchMode();
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
        AnimateEggHatchSequence(); //Hatch hole
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


void InitEggHatchMode(void)
{
    gCurrentPinballGame->scoreAddedInFrame = 100000;
    if (gCurrentPinballGame->eggCaveState == 3)
    {
        gCurrentPinballGame->eggCaveState = 4;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        gCurrentPinballGame->modeAnimTimer = 500;
    }
    else if (gCurrentPinballGame->eggDeliveryState !=0)
    {
        gCurrentPinballGame->modeAnimTimer = 300;
    }
    else
    {
        gCurrentPinballGame->modeAnimTimer = 120;
    }

    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
}

void AnimateEggHatchSequence(void)
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

        if (gCurrentPinballGame->eggDeliveryState != 1)
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

        if (gCurrentPinballGame->eggDeliveryState == 2)
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

void UpdateShopEntryAnimation(s16 arg0)
{
    int var_r7 = 0;

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->shopEntryTimer != 0)
        gCurrentPinballGame->shopEntryTimer--;

    if (arg0 == 0)
    {
        if (gCurrentPinballGame->shopEntryTimer == 149)
        {
            m4aMPlayAllStop();
            gCurrentPinballGame->outcomeFrameCounter = 0;
            gCurrentPinballGame->shopPurchaseConfirmed = 0;
            gCurrentPinballGame->shopOutcomeRepeatCount = 0;
            gCurrentPinballGame->catchModeEventTimer = 0;
            gMain.blendControl = 206;
            gMain.blendBrightness = 0;
        }

        if (gCurrentPinballGame->shopEntryTimer == 146)
        {
            gCurrentPinballGame->activePortraitType = 18;

            DmaCopy16(3, &gPokemonNameDisplayGfx, OBJ_VRAM1 + 0x1C00, 0x940);
            DmaCopy16(3, &gShopNameDisplay_Pals, BG_PLTT + 0x180, 0x20);
        }

        if (gCurrentPinballGame->shopEntryTimer >= 145 && gCurrentPinballGame->shopEntryTimer < 150)
        {
            if (gCurrentPinballGame->shopEntryTimer > 146)
            {
                gMain.blendBrightness = 4;

                if (gCurrentPinballGame->shopEntryTimer <= 148)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->activePaletteIndex = 1;
                    gCurrentPinballGame->paletteSwapActive = 0;
                }
            }
            else
            {
                gMain.blendBrightness = 7;

                if (gCurrentPinballGame->shopEntryTimer <= 145)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[2] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->activePaletteIndex = 2;
                    gCurrentPinballGame->paletteSwapActive = 0;
                }
            }
        }

        if (gCurrentPinballGame->shopEntryTimer == 145)
        {
            m4aSongNumStart(MUS_SHOP);

            gCurrentPinballGame->shopItemCursor = 0;
            gCurrentPinballGame->shopSlideDirection = 0;
            gCurrentPinballGame->shopSelectedItemId = gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor];

            LoadPortraitGraphics(6, 0);
            RenderEvolutionUI(1);

            gMain.fieldSpriteGroups[7]->available = 1;
            gMain.fieldSpriteGroups[8]->available = 1;
            gMain.fieldSpriteGroups[6]->available = 1;
            gMain.fieldSpriteGroups[9]->available = 1;

            DmaCopy16(3, gShopEvoUI_Pals, OBJ_PLTT + 0x1C0, 0x20);
            DmaCopy16(3, gShopModeBG_Gfx, BG_VRAM + 0x2000, 0xC40);

            gMain.bgOffsets[0].yOffset = 80;
            gMain.shopPanelSlideOffset = 0;
            gCurrentPinballGame->shopAnimSlideTimer = 15;
            gMain.shopPanelActive = 1;

            m4aSongNumStart(SE_SHOP_LIST_REVEAL);

            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->shopPikaSaverMaxed = 1;
            else
                gCurrentPinballGame->shopPikaSaverMaxed = 0;
        }

        if (gCurrentPinballGame->shopEntryTimer <= 144)
        {
            gCurrentPinballGame->rouletteSubOffset = 0;
            gCurrentPinballGame->portraitDisplayState = 2;
            gCurrentPinballGame->creatureOamPriority = 0;
            var_r7 = 0;

            if (gCurrentPinballGame->shopAnimSlideTimer > 0)
            {
                if (--gCurrentPinballGame->shopAnimSlideTimer > 14)
                {
                    gCurrentPinballGame->shopUISlideOffset = (30 - gCurrentPinballGame->shopAnimSlideTimer) * 7;

                    if (gCurrentPinballGame->shopAnimSlideTimer == 15)
                    {
                        if (gCurrentPinballGame->shopItemCursor == 3)
                        {
                            if (gCurrentPinballGame->ballUpgradeType <= BALL_UPGRADE_TYPE_ULTRA_BALL)
                                gCurrentPinballGame->shopSelectedItemId = gCurrentPinballGame->ballUpgradeType + 10;
                            else
                                gCurrentPinballGame->shopSelectedItemId = 12;
                        }
                        else if (gCurrentPinballGame->shopItemCursor == 6)
                        {
                            if (gMain.selectedField == FIELD_RUBY)
                                gCurrentPinballGame->shopSelectedItemId = 22;
                            else
                                gCurrentPinballGame->shopSelectedItemId = 23;
                        }
                        else
                            gCurrentPinballGame->shopSelectedItemId = gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor];

                        LoadPortraitGraphics(6, 0);
                        var_r7 = 1;
                    }
                }
                else
                    gCurrentPinballGame->shopUISlideOffset = gCurrentPinballGame->shopAnimSlideTimer * 7;
            }
            else
            {
                if (JOY_NEW(DPAD_LEFT) && gCurrentPinballGame->shopPurchaseConfirmed == 0)
                {
                    m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                    if (gCurrentPinballGame->shopItemCursor > 0)
                        gCurrentPinballGame->shopItemCursor--;
                    else
                        gCurrentPinballGame->shopItemCursor = 7;

                    gCurrentPinballGame->shopSlideDirection = 1;
                    gCurrentPinballGame->shopAnimSlideTimer = 30;
                }

                if (JOY_NEW(DPAD_RIGHT))
                {
                    if (gCurrentPinballGame->shopPurchaseConfirmed == 0)
                    {
                        m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                        if (gCurrentPinballGame->shopItemCursor <= 6)
                            gCurrentPinballGame->shopItemCursor++;
                        else
                            gCurrentPinballGame->shopItemCursor = 0;

                        gCurrentPinballGame->shopSlideDirection = 0;
                        gCurrentPinballGame->shopAnimSlideTimer = 30;
                    }
                }
            }

            RenderEvolutionUI(var_r7);

            if (gCurrentPinballGame->shopSlideDirection != 0)
            {
                if (gCurrentPinballGame->shopBgAnimFrame != 0)
                    gCurrentPinballGame->shopBgAnimFrame--;
                else
                    gCurrentPinballGame->shopBgAnimFrame = 7;
            }
            else if (gCurrentPinballGame->shopBgAnimFrame < 7)
                gCurrentPinballGame->shopBgAnimFrame++;
            else
                gCurrentPinballGame->shopBgAnimFrame = 0;

            DmaCopy16(3, gShopEvoBGAnimFrames[gCurrentPinballGame->shopBgAnimFrame / 2], BG_VRAM + 0x2000, 0xC40);
            gMain.bgOffsets[0].yOffset = 80 - (4 * gMain.shopPanelSlideOffset);

            if (gCurrentPinballGame->catchModeEventTimer != 0)
            {
                if (gMain.shopPanelSlideOffset > 0 && --gMain.shopPanelSlideOffset == 0)
                {
                    gMain.shopPanelActive = 0;
                    gMain.vCount = 144;
                }
            }
            else if (gMain.shopPanelSlideOffset < 20)
                gMain.shopPanelSlideOffset++;
        }

        if (gCurrentPinballGame->shopAnimSlideTimer <= 0 && gMain.shopPanelSlideOffset > 19)
        {
            if (JOY_NEW(A_BUTTON) && gCurrentPinballGame->shopPurchaseConfirmed == 0)
            {
                s16 var_r3;
                const u16 *arr = gShopItemData[gCurrentPinballGame->shopSelectedItemId];

                if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                    var_r3 = 999;
                else if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 4 && gCurrentPinballGame->shopBonusStageAlreadyBought)
                    var_r3 = 999;
                else
                    var_r3 = arr[3];

                if (gCurrentPinballGame->coins >= var_r3)
                {
                    gCurrentPinballGame->shopPurchaseConfirmed = 1;
                    gCurrentPinballGame->rouletteOutcomeId = gCurrentPinballGame->shopSelectedItemId;
                    gCurrentPinballGame->coins -= var_r3;

                    m4aMPlayAllStop();
                    m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);

                    gCurrentPinballGame->shopDoorOpenLevel = 19;
                    gCurrentPinballGame->sapphireBumperLitCountdown = 30;
                }
                else
                    m4aSongNumStart(SE_FAILURE);
            }
            else if (JOY_NEW(B_BUTTON) && gCurrentPinballGame->shopPurchaseConfirmed == 0)
            {
                gCurrentPinballGame->catchModeEventTimer = 30;
                gCurrentPinballGame->shopAnimSlideTimer = 30;
                m4aSongNumStart(SE_MENU_CANCEL);
            }
        }

        if (gCurrentPinballGame->shopPurchaseConfirmed != 0)
        {
            ProcessRouletteOutcome();

            if (gCurrentPinballGame->outcomeFrameCounter == 179)
            {
                gCurrentPinballGame->catchModeEventTimer = 30;
                gCurrentPinballGame->shopAnimSlideTimer = 30;

                if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 4)
                    gCurrentPinballGame->shopBonusStageAlreadyBought = 1;
            }
        }

        if (gCurrentPinballGame->catchModeEventTimer != 0)
        {
            gCurrentPinballGame->catchModeEventTimer--;

            if (gCurrentPinballGame->shopAnimSlideTimer <= 14)
                gCurrentPinballGame->shopAnimSlideTimer = 15;

            if (gCurrentPinballGame->catchModeEventTimer < 5)
            {
                if (gCurrentPinballGame->catchModeEventTimer > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->catchModeEventTimer <= 3)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->activePaletteIndex = 1;
                        gCurrentPinballGame->paletteSwapActive = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->catchModeEventTimer == 0)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->activePaletteIndex = 0;
                        gCurrentPinballGame->paletteSwapActive = 1;
                    }
                }
            }

            if (gCurrentPinballGame->catchModeEventTimer == 0)
            {
                if (gMain.selectedField == FIELD_RUBY)
                {
                    if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                        m4aSongNumStart(MUS_FIELD_RUBY);
                    else
                        m4aSongNumStart(MUS_FIELD_RUBY2);
                }
                else
                {
                    if ((gCurrentPinballGame->numCompletedBonusStages / 5) % 2 == 0)
                        m4aSongNumStart(MUS_FIELD_SAPPHIRE);
                    else
                        m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
                }

                if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
                    gCurrentPinballGame->outcomeFrameCounter = 170;
                else
                    gCurrentPinballGame->modeAnimTimer = 24;

                if (gCurrentPinballGame->boardState == 2)
                    LoadPortraitGraphics(1, 0);
                else
                    LoadPortraitGraphics(0, 0);

                gCurrentPinballGame->portraitDisplayState = 0;
                gCurrentPinballGame->creatureOamPriority = 3;
                gCurrentPinballGame->shopPurchaseConfirmed = 0;

                gMain.fieldSpriteGroups[7]->available = 0;
                gMain.fieldSpriteGroups[8]->available = 0;
                gMain.fieldSpriteGroups[6]->available = 0;
                gMain.fieldSpriteGroups[9]->available = 0;

                gCurrentPinballGame->activePortraitType = 0;
            }
        }
    }
    else
    {
        s16 evoTarget = 0;

        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->shopEntryTimer == 149)
            {
                m4aMPlayAllStop();

                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 120;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 3;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->bannerDisplayDuration = 80;
                gCurrentPinballGame->bannerSlidePosition = 0xF63C; //-2500
                gCurrentPinballGame->bannerSlideTimer = 50;
                gCurrentPinballGame->bannerSlideVelocity = 0;

                DmaCopy16(3, gModeBannerTilemaps[3], OBJ_VRAM1 + 0x1800, 0x2400);
                DmaCopy16(3, gModeBannerPalettes[3], OBJ_PLTT + 0x1C0, 0x20);

                gMain.blendControl = 206;
                gCurrentPinballGame->shopEntryTimer = 148;
                gCurrentPinballGame->evolvingPartyIndex = 0;
                gCurrentPinballGame->shopItemCursor = 0;
                gCurrentPinballGame->evoChainPosition = 0;
                gCurrentPinballGame->evoNameSlideOnly = 0;
                gCurrentPinballGame->evoFormAlternateTimer = 0;
            }

            if (gCurrentPinballGame->shopEntryTimer == 146)
            {
                gCurrentPinballGame->activePortraitType = 18;

                DmaCopy16(3, &gPokemonNameDisplayGfx, OBJ_VRAM1 + 0x1C00, 0x940);
                DmaCopy16(3, &gEvoNameDisplay_Pals, PLTT + 0x180, 0x20);
            }

            if (gCurrentPinballGame->shopEntryTimer == 145)
            {
                int stage1Evo;
                int stage2Evo;
                gCurrentPinballGame->shopSlideDirection = 0;
                gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                gCurrentPinballGame->evoChainMaxStage = 0;
                stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                if (stage1Evo < SPECIES_NONE)
                {
                    gCurrentPinballGame->evoChainMaxStage++;
                    stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;
                    if (stage2Evo < SPECIES_NONE)
                        gCurrentPinballGame->evoChainMaxStage++;

                }

                LoadPokemonNameGraphics();

                if (gMain.selectedField == FIELD_RUBY)
                    m4aSongNumStart(MUS_EVO_MODE);
                else
                    m4aSongNumStart(MUS_EVO_MODE2);

                RenderEvolutionUI(var_r7);

                gMain.fieldSpriteGroups[8]->available = 1;
                gMain.fieldSpriteGroups[9]->available = 1;
                gMain.fieldSpriteGroups[6]->available = 1;

                DmaCopy16(3, &gShopEvoUI_Pals, PLTT + 0x3C0, 0x20);

                gMain.bgOffsets[0].yOffset = 80;
                gMain.shopPanelSlideOffset = 0;
                gCurrentPinballGame->shopAnimSlideTimer = 15;
                gMain.shopPanelActive = 1;

                DmaCopy16(3, &gEvoModeBG_Gfx, VRAM + 0x2000, 0xC40);
            }

            if (gCurrentPinballGame->shopEntryTimer <= 144)
            {
                gCurrentPinballGame->rouletteSubOffset = 0;
                gCurrentPinballGame->portraitDisplayState = 2;
                gCurrentPinballGame->creatureOamPriority = 0;

                if (gCurrentPinballGame->shopAnimSlideTimer > 0)
                {
                    gCurrentPinballGame->shopAnimSlideTimer--;

                    if (gCurrentPinballGame->evoNameSlideOnly != 0)
                    {
                        if (gCurrentPinballGame->shopAnimSlideTimer == 15)
                            LoadPokemonNameGraphics();
                    }
                    else
                    {
                        if (gCurrentPinballGame->shopAnimSlideTimer > 14)
                        {
                            gCurrentPinballGame->shopUISlideOffset = (30 - gCurrentPinballGame->shopAnimSlideTimer) * 7;

                            if (gCurrentPinballGame->shopAnimSlideTimer == 15)
                                LoadPokemonNameGraphics();
                        }
                        else
                            gCurrentPinballGame->shopUISlideOffset = gCurrentPinballGame->shopAnimSlideTimer * 7;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->evolvablePartySize > 1)
                    {
                        if (JOY_NEW(DPAD_LEFT))
                        {
                            int stage1Evo;
                            int stage2Evo;

                            m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                            if (gCurrentPinballGame->evolvingPartyIndex > 0)
                                gCurrentPinballGame->evolvingPartyIndex--;
                            else
                                gCurrentPinballGame->evolvingPartyIndex = gCurrentPinballGame->evolvablePartySize - 1;

                            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                            gCurrentPinballGame->shopSlideDirection = 1;
                            gCurrentPinballGame->shopAnimSlideTimer = 30;
                            gCurrentPinballGame->evoChainPosition = 0;
                            gCurrentPinballGame->evoNameSlideOnly = 0;
                            gCurrentPinballGame->evoChainMaxStage = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->evoChainMaxStage++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->evoChainMaxStage++;
                            }
                        }
                        else if (JOY_NEW(DPAD_RIGHT))
                        {
                            int stage1Evo;
                            int stage2Evo;

                            m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                            if (gCurrentPinballGame->evolvingPartyIndex < gCurrentPinballGame->evolvablePartySize - 1)
                                gCurrentPinballGame->evolvingPartyIndex++;
                            else
                                gCurrentPinballGame->evolvingPartyIndex = 0;

                            gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                            gCurrentPinballGame->shopSlideDirection = 0;
                            gCurrentPinballGame->shopAnimSlideTimer = 30;
                            gCurrentPinballGame->evoChainPosition = 0;
                            gCurrentPinballGame->evoNameSlideOnly = 0;
                            gCurrentPinballGame->evoChainMaxStage = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->evoChainMaxStage++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->evoChainMaxStage++;
                            }
                        }
                    }

                    if (JOY_NEW(DPAD_UP))
                    {
                        if (gCurrentPinballGame->evoChainPosition == 0)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->shopAnimSlideTimer = 30;
                                gCurrentPinballGame->evoNameSlideOnly = 1;
                                gCurrentPinballGame->evoChainPosition++;
                            }
                        }
                        else if (gCurrentPinballGame->evoChainPosition == 1)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->evoTargetSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->shopAnimSlideTimer = 30;
                                gCurrentPinballGame->evoNameSlideOnly = 1;
                                gCurrentPinballGame->evoChainPosition++;
                            }
                        }

                        gCurrentPinballGame->evoFormAlternateTimer = 0;
                    }
                    else if (JOY_NEW(DPAD_DOWN))
                    {
                        if (gCurrentPinballGame->evoChainPosition == 1)
                        {
                            evoTarget = gCurrentPinballGame->currentSpecies;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->shopAnimSlideTimer = 30;
                                gCurrentPinballGame->evoNameSlideOnly = 1;
                                gCurrentPinballGame->evoChainPosition--;
                            }
                        }
                        else if (gCurrentPinballGame->evoChainPosition == 2)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->shopAnimSlideTimer = 30;
                                gCurrentPinballGame->evoNameSlideOnly = 1;
                                gCurrentPinballGame->evoChainPosition--;
                            }
                        }

                        gCurrentPinballGame->evoFormAlternateTimer = 0;
                    }

                    if (gCurrentPinballGame->evoChainPosition > 0)
                    {
                        switch (gCurrentPinballGame->evoTargetSpecies)
                        {
                        case 14:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 16;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        case 16:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 14;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        case 89:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 90;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        case 90:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 89;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        case 176:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 177;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        case 177:
                            if (gCurrentPinballGame->evoFormAlternateTimer == 50)
                            {
                                gCurrentPinballGame->evoFormAlternateTimer = 0;
                                gCurrentPinballGame->evoTargetSpecies = 176;
                                LoadPokemonNameGraphics();
                            }
                            break;
                        }

                        gCurrentPinballGame->evoFormAlternateTimer++;
                    }
                }

                UpdatePokemonNamePosition();

                if (gCurrentPinballGame->shopSlideDirection != 0)
                {
                    if (gCurrentPinballGame->shopBgAnimFrame != 0)
                        gCurrentPinballGame->shopBgAnimFrame--;
                    else
                        gCurrentPinballGame->shopBgAnimFrame = 7;
                }
                else
                {
                    if (gCurrentPinballGame->shopBgAnimFrame <= 6)
                        gCurrentPinballGame->shopBgAnimFrame++;
                    else
                        gCurrentPinballGame->shopBgAnimFrame = 0;
                }

                DmaCopy16(3, gShopEvoBGAnimFrames[gCurrentPinballGame->shopBgAnimFrame / 2 + 4], VRAM + 0x2000, 0xC40);
                gMain.bgOffsets[0].yOffset = 80 - (gMain.shopPanelSlideOffset * 4);

                if (gCurrentPinballGame->catchModeEventTimer != 0)
                {
                    if (gMain.shopPanelSlideOffset > 0 && --gMain.shopPanelSlideOffset == 0)
                    {
                        gMain.shopPanelActive = 0;
                        gMain.vCount = 144;
                    }
                }
                else if (gMain.shopPanelSlideOffset <= 19)
                    gMain.shopPanelSlideOffset++;

                RenderEvolutionUI(0);
            }

            if (gCurrentPinballGame->shopAnimSlideTimer <= 0 && gMain.shopPanelSlideOffset > 19 && JOY_NEW(A_BUTTON) == A_BUTTON)
            {
                gCurrentPinballGame->catchModeEventTimer = 30;
                gCurrentPinballGame->evoNameSlideOnly = 0;
                gCurrentPinballGame->shopAnimSlideTimer = 30;
                m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);
            }

            if (gCurrentPinballGame->catchModeEventTimer == 0)
                return;

            gCurrentPinballGame->catchModeEventTimer--;

            if (gCurrentPinballGame->shopAnimSlideTimer <= 14)
                gCurrentPinballGame->shopAnimSlideTimer = 15;

            if (gCurrentPinballGame->catchModeEventTimer <= 4)
            {
                if (gCurrentPinballGame->catchModeEventTimer > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->catchModeEventTimer <= 3)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->activePaletteIndex = 1;
                        gCurrentPinballGame->paletteSwapActive = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->catchModeEventTimer != 0)
                        return;

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0], OBJ_PLTT, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteSets[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->activePaletteIndex = 0;
                    gCurrentPinballGame->paletteSwapActive = 1;
                }
            }

            if (gCurrentPinballGame->catchModeEventTimer == 0)
            {
                if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
                    gCurrentPinballGame->outcomeFrameCounter = 170;
                else
                    gCurrentPinballGame->modeAnimTimer = 24;

                gCurrentPinballGame->portraitDisplayState = 0;
                gCurrentPinballGame->creatureOamPriority = 3;

                gMain.fieldSpriteGroups[8]->available = 0;
                gMain.fieldSpriteGroups[6]->available = 0;
                gMain.fieldSpriteGroups[9]->available = 0;

                gCurrentPinballGame->evoBlinkTimer = 0;
                gCurrentPinballGame->catchLights[0] = 4;
                gCurrentPinballGame->catchLights[1] = 4;
                gCurrentPinballGame->catchLights[2] = 4;

                HidePokemonNameDisplay();
                gCurrentPinballGame->activePortraitType = 0;
            }
        }
        else if (gCurrentPinballGame->shopEntryTimer == 50)
            gCurrentPinballGame->modeAnimTimer = 24;

    }
}

void InitCenterTrapMode(void)
{
    gCurrentPinballGame->modeAnimTimer = 0x96;
    gMain.fieldSpriteGroups[13]->available = 0;
    gCurrentPinballGame->bonusTrapEnabled = 0;
    gCurrentPinballGame->scoreAddedInFrame = 10000;
    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
    PlayRumble(8);
}

void AnimateCenterTrapSequence(void)
{
    if (gCurrentPinballGame->modeAnimTimer)
    {
        gCurrentPinballGame->modeAnimTimer--;
        if (gCurrentPinballGame->modeAnimTimer > 148)
        {
            gCurrentPinballGame->ball->ballHidden = 1;
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            gCurrentPinballGame->trapAnimState = 1;
        }
        else if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->trapAnimState = 0;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 36)
        {
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->trapAnimState = 0;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 24)
        {
            gCurrentPinballGame->ballFrozenState = 1;
            gCurrentPinballGame->trapAnimState = 1;
        }
        else if (gCurrentPinballGame->modeAnimTimer == 24)
        {
            m4aSongNumStart(SE_CENTER_HOLE_EJECT);
            gCurrentPinballGame->trapAnimState = 2;
            gCurrentPinballGame->ball->velocity.x = 73;
            gCurrentPinballGame->ball->velocity.y = 236;
            gCurrentPinballGame->ball->ballHidden = 0;
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->boardEntityActive = 0;
            gCurrentPinballGame->ball->scale = 0x88;
            gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 12)
        {
            gCurrentPinballGame->trapAnimState = 2;
            if (gCurrentPinballGame->modeAnimTimer > 21)
                gCurrentPinballGame->ball->scale = ((24 - gCurrentPinballGame->modeAnimTimer) * 0x70 / 3) + 0x90;
            else
                gCurrentPinballGame->ball->scale = 0x100;
        }
        else
        {
            gCurrentPinballGame->trapAnimState = 1;
        }
        if (gCurrentPinballGame->modeAnimTimer <= 40)
        {
            if (gCurrentPinballGame->cameraYAdjust > 0)
            {
                gCurrentPinballGame->cameraYAdjust--;
            }
        }
    }
    else
    {
        gCurrentPinballGame->trapAnimState = 0;
        gCurrentPinballGame->ballCatchState = NOT_TRAPPED;
    }
}

void TransitionToBonusField(void)
{
    gMain.fieldSpriteGroups[13]->available = 0;
    SaveGameStateSnapshot(0);
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->ballHidden = 0;
    gCurrentPinballGame->ballFrozenState = 0;
    gCurrentPinballGame->ball->scale = 0x100;
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->ballCatchState = NOT_TRAPPED;
    if (gCurrentPinballGame->bonusReturnState == 0)
    {
        gCurrentPinballGame->evoItemCount = 0;
        gCurrentPinballGame->evoBlinkTimer = 0;
        gCurrentPinballGame->catchLights[0] = 0;
        gCurrentPinballGame->catchLights[1] = 0;
        gCurrentPinballGame->catchLights[2] = 0;
    }
    m4aMPlayAllStop();
    DisableVBlankInterrupts();
    gMain.tempField = gMain.selectedField;
    gMain.selectedField = gCurrentPinballGame->nextBonusField;
    gMain.isBonusField = 1;
    gMain.subState = 0;
}