#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

void UpdateCatchHoleAnimation(void);
void InitCatchHoleEntry(void);
void UpdateHatchHoleAnimation(void);
void InitMartEvoHoleEntry(void);
void UpdateMartEvoHoleAnimation(void);
void InitCenterHoleEntry(void);
void UpdateCenterHoleAnimation(void);
void RequestBoardTransition(u8);
void UpdateLotadBonusCelebration(void);
void InitStandardHoleBonusCelebration(void);
void UpdateStandardHoleBonusCelebration(void);


void InitBoardEntryHole(void)
{
    if (gMain.modeChangeFlags != MODE_CHANGE_NONE)
        return;

    switch (gCurrentPinballGame->boardEntryMode)
    {
    case 1:
        InitCatchHoleEntry();
        break;
    case 2:
        InitHatchHoleEntry();
        break;
    case 3:
        InitMartEvoHoleEntry();
        break;
    case 4:
        InitCenterHoleEntry();
        break;
    }

    gCurrentPinballGame->entryAnimTimer = 60;
}

void UpdateBoardEntryHole(void)
{
    if (gCurrentPinballGame->entryAnimTimer > 0)
        gCurrentPinballGame->entryAnimTimer--;

    switch (gCurrentPinballGame->boardEntryMode)
    {
    case 1:
        UpdateCatchHoleAnimation(); // Catch hole
        break;
    case 2:
        UpdateHatchHoleAnimation(); //Hatch hole
        break;
    case 3:
        UpdateMartEvoHoleAnimation(); //Mart / Evo hole
        break;
    case 4:
        UpdateCenterHoleAnimation(); //Center Hole
        break;
    }
}

void InitCatchHoleEntry(void)
{
    if (gCurrentPinballGame->savedCatchArrows > 1)
    {
        RequestBoardTransition(4);
    }

    gCurrentPinballGame->scrollNudgeY = 0;
    gCurrentPinballGame->scrollNudgeActive = 0;
    gCurrentPinballGame->scrollNudgeTargetY = 0;
    gCurrentPinballGame->sequenceTimer = 113;

    m4aSongNumStart(SE_UNKNOWN_0xCE);
    gCurrentPinballGame->scoreAddedInFrame = 50000;

    PlayRumble(8);
}

/*
* Ruby board Sharpedo; during the initation of the catch mode
* Echoes UpdateSapphireWhiscashCatchSequence, which is the equivalent 'catch hole' on the sapphire board.
*
* Note: this *does not* affect the start of the catch mode itself.
* When this function is nulled out at UpdateBoardEntryHole, the banner *doesn't* show, and
* the ball bounces off the sharpedo. However, the grid still shows a picked mon,
* and the mode otherwise works mostly normally, with the exception of affecting
* the 'tilt' behavior, and the collision with the cyndaquil pushback.
*/
void UpdateCatchHoleAnimation(void)
{
    if (gCurrentPinballGame->sequenceTimer) //Countdown timer; ball grabbed/held while banner shows
    {
        gCurrentPinballGame->sequenceTimer--;
        if (gCurrentPinballGame->sequenceTimer > 100)
        {
            gCurrentPinballGame->ballLocked = 1;
            gCurrentPinballGame->ballLockState = 1;

            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spin = 0;

            if (gCurrentPinballGame->sequenceTimer > 108)
            {
                gCurrentPinballGame->bossActive = 1;

                if (gCurrentPinballGame->sequenceTimer > 110)
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
                gCurrentPinballGame->pokemonActionFrame =6;
            }
            else if (gCurrentPinballGame->sequenceTimer > 104)
            {
                gCurrentPinballGame->ball->positionQ0.x = 197;
                gCurrentPinballGame->ball->positionQ0.y = 219;
                gCurrentPinballGame->pokemonActionFrame = 7;
            }
            else
            {
                gCurrentPinballGame->ball->isGrabbed = 1;
                gCurrentPinballGame->pokemonActionFrame = 8;
            }
        }
        else if (gCurrentPinballGame->sequenceTimer > 20)
        {
            if (gCurrentPinballGame->sequenceTimer > 77)
            {
                gCurrentPinballGame->pokemonActionFrame = 9;

                if (gCurrentPinballGame->sequenceTimer < 80)
                {
                    if (gCurrentPinballGame->sharpedoHoldTimer != 0)
                    {
                        gCurrentPinballGame->sharpedoHoldTimer--;
                        gCurrentPinballGame->sequenceTimer++;
                    }
                }
            }
            else if (gCurrentPinballGame->sequenceTimer > 72)
            {
                gCurrentPinballGame->pokemonActionFrame = 10;
            }
            else if (gCurrentPinballGame->sequenceTimer > 67)
            {
                gCurrentPinballGame->pokemonActionFrame = 11;
            }
            else if (gCurrentPinballGame->sequenceTimer > 44)
            {
                gCurrentPinballGame->pokemonActionFrame = 12;
            }
            else if (gCurrentPinballGame->sequenceTimer > 38)
            {
                gCurrentPinballGame->pokemonActionFrame = 13;
            }
            else if (gCurrentPinballGame->sequenceTimer > 28)
            {
                gCurrentPinballGame->pokemonActionFrame = 14;
            }
            else if (gCurrentPinballGame->sequenceTimer > 23)
            {
                gCurrentPinballGame->pokemonActionFrame = 15;
            }
            else {
                gCurrentPinballGame->pokemonActionFrame = 16;
            }
        }
        else if (gCurrentPinballGame->sequenceTimer > 18)
        {
            gCurrentPinballGame->ball->positionQ0.x = 193;
            gCurrentPinballGame->ball->positionQ0.y = 226;
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->pokemonActionFrame = 17;
        }
        else if (gCurrentPinballGame->sequenceTimer > 16)
        {
            gCurrentPinballGame->ballLockState = 0;
            gCurrentPinballGame->scrollNudgeTargetY = 0;
            gCurrentPinballGame->scrollNudgeActive = 1;
            gCurrentPinballGame->bossActive = 0;
            gCurrentPinballGame->ball->spin = 0;
            gCurrentPinballGame->ball->velocity.x = 0xFF56;
            gCurrentPinballGame->ball->velocity.y = 220;
            gCurrentPinballGame->ball->positionQ0.x = 190;
            gCurrentPinballGame->ball->positionQ0.y = 232;
            gCurrentPinballGame->pokemonActionFrame = 18;
            if (gCurrentPinballGame->sequenceTimer == 18)
            {
                m4aSongNumStart(194);
                PlayRumble(7);
            }
        }
        else if (gCurrentPinballGame->sequenceTimer > 12)
        {
            gCurrentPinballGame->ball->spin = 0;
            gCurrentPinballGame->pokemonActionFrame = 19;
        }
        else if (gCurrentPinballGame->sequenceTimer > 8)
        {
            gCurrentPinballGame->ball->spin = 0;
            gCurrentPinballGame->pokemonActionFrame = 20;
        }
        else if (gCurrentPinballGame->sequenceTimer > 4)
        {
            gCurrentPinballGame->ball->spin = 0;
            gCurrentPinballGame->pokemonActionFrame = 21;
        }
        else
        {
            gCurrentPinballGame->pokemonActionFrame = 22;
        }
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        gCurrentPinballGame->ball->prevPositionQ1 = gCurrentPinballGame->ball->positionQ1;
        gCurrentPinballGame->ball->positionQ8.x= gCurrentPinballGame->ball->positionQ0.x << 8;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;

    }
    else
    {
        gCurrentPinballGame->entryAnimTimer = 30;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->boardEntryMode = 0;
        gCurrentPinballGame->ballLocked = 0;
        gCurrentPinballGame->pokemonActionFrame = 0;
    }
}


void InitHatchHoleEntry(void)
{
    gCurrentPinballGame->scoreAddedInFrame = 100000;
    if (gCurrentPinballGame->hatchCaveState == 3)
    {
        gCurrentPinballGame->hatchCaveState = 4;
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        PlayRumble(7);
        gCurrentPinballGame->sequenceTimer = 500;
    }
    else if (gCurrentPinballGame->hatchCaveCompletionFlag !=0)
    {
        gCurrentPinballGame->sequenceTimer = 300;
    }
    else
    {
        gCurrentPinballGame->sequenceTimer = 120;
    }

    gCurrentPinballGame->ballLocked = 1;
}

void UpdateHatchHoleAnimation(void)
{
    u16 seqTimer = gCurrentPinballGame->sequenceTimer;

    if (seqTimer != 0)
    {
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->sequenceTimer--;

        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0x94;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;

        if (gCurrentPinballGame->hatchCaveCompletionFlag != 1)
            return;
        if (gCurrentPinballGame->sequenceTimer > 0xC8)
            return;

        if (gCurrentPinballGame->sequenceTimer == 0xC8)
        {
            if (gCurrentPinballGame->bannerType != 0)
                gCurrentPinballGame->sequenceTimer++;
            else
            {
                if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                    InitLotadBonusCelebration();
                else
                    InitStandardHoleBonusCelebration();
            }
        }
        else
        {
            if (gCurrentPinballGame->scoreHi != 0 && gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                UpdateLotadBonusCelebration();
            else
                UpdateStandardHoleBonusCelebration();
        }
        if (gCurrentPinballGame->sequenceTimer <= 9)
            gCurrentPinballGame->sequenceTimer++;
    }
    else
    {
        gCurrentPinballGame->ball->isGrabbed = ballStartY;
        gCurrentPinballGame->boardEntryMode = ballStartY;

        gCurrentPinballGame->ball->positionQ0.x = 0x58;
        gCurrentPinballGame->ball->positionQ0.y = 0xA2;
        gCurrentPinballGame->ball->spin = 0;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ballLocked = 0;

        if (gCurrentPinballGame->hatchCaveCompletionFlag == 2)
        {
            gCurrentPinballGame->hatchCaveState = 3;
            gCurrentPinballGame->cyndaquilRiseTimer = 0x30;
            gCurrentPinballGame->cyndaquilRiseHoldTimer = 0x1E;
        }
        else
        {
            gCurrentPinballGame->ballLockState = 0;
            gCurrentPinballGame->entryAnimTimer = 0x3C;
            gCurrentPinballGame->ball->velocity.x = 0x14;
            gCurrentPinballGame->ball->velocity.y = 0xC8;
        }
    }
}

void InitMartEvoHoleEntry(void)
{
    gCurrentPinballGame->bannerAnimTimer = 0;
    gCurrentPinballGame->bannerScrollOffset = 0;
    gCurrentPinballGame->sequenceTimer = 0xB4;
    gCurrentPinballGame->entrySequenceTimer = 0xB4;
    gCurrentPinballGame->scoreAddedInFrame = 500000;
    gMain.blendControl = 0xCE;
    gMain.blendBrightness = 0;
    gCurrentPinballGame->ballLocked = 1;
}

void UpdateMartEvoHoleAnimation(void)
{

    if (gCurrentPinballGame->sequenceTimer > 0x18)
    {
        gCurrentPinballGame->ball->isGrabbed = 1;
        gCurrentPinballGame->ballLockState = 1;
        gCurrentPinballGame->sequenceTimer--;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->positionQ0.x = 0xDC;
        gCurrentPinballGame->ball->positionQ0.y = 0x62;
        gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
        gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x * 256;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y * 256;

        if (gCurrentPinballGame->sequenceTimer > 0x9B)
            gCurrentPinballGame->shopDoorTargetFrame = (gCurrentPinballGame->sequenceTimer - 0x9C) / 8;
        if (gCurrentPinballGame->sequenceTimer <= 0x31)
            gCurrentPinballGame->sequenceTimer++;

        UpdateMartEvoSelectionUI(gCurrentPinballGame->trapDisplayState);
        return;
    }

    if (gCurrentPinballGame->sequenceTimer > 0)
    {
        gCurrentPinballGame->sequenceTimer--;
        gCurrentPinballGame->shopDoorTargetFrame = (0x18 - gCurrentPinballGame->sequenceTimer) / 8;
        return;
    }

    gCurrentPinballGame->ball->isGrabbed = 0;
    gCurrentPinballGame->ballLockState = 0;
    gCurrentPinballGame->entryAnimTimer = 0x3C;

    gCurrentPinballGame->ball->velocity.x = 0x60;
    gCurrentPinballGame->ball->velocity.y = 0xC0;
    gCurrentPinballGame->ball->positionQ0.x = 0xDF;
    gCurrentPinballGame->ball->positionQ0.y = 0x63;

    gCurrentPinballGame->ball->spin = 0;
    gCurrentPinballGame->ballLocked = 0;
    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
    gCurrentPinballGame->boardEntryMode = 0;
    gCurrentPinballGame->shopDoorTargetFrame = 0x13;

    m4aSongNumStart(SE_UNKNOWN_0xC3);

    if (gCurrentPinballGame->savedEvoHitCount > 2 && gCurrentPinballGame->evolvablePartySize > 0)
    {
        RequestBoardTransition(6);
    }
}

void UpdateMartEvoSelectionUI(s16 arg0)
{
    int var_r7 = 0;

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->entrySequenceTimer != 0)
        gCurrentPinballGame->entrySequenceTimer--;

    if (arg0 == 0)
    {
        if (gCurrentPinballGame->entrySequenceTimer == 149)
        {
            m4aMPlayAllStop();
            gCurrentPinballGame->plungerAnimFrame = 0;
            gCurrentPinballGame->slotReelConfirmed = 0;
            gCurrentPinballGame->plungerLoopCount = 0;
            gCurrentPinballGame->menuDismissTimer = 0;
            gMain.blendControl = 206;
            gMain.blendBrightness = 0;
        }

        if (gCurrentPinballGame->entrySequenceTimer == 146)
        {
            gCurrentPinballGame->bannerType = 18;

            DmaCopy16(3, &gUnknown_084F61EC, OBJ_VRAM1 + 0x1C00, 0x940);
            DmaCopy16(3, &gUnknown_081B45A4, BG_PLTT + 0x180, 0x20);
        }

        if (gCurrentPinballGame->entrySequenceTimer >= 145 && gCurrentPinballGame->entrySequenceTimer < 150)
        {
            if (gCurrentPinballGame->entrySequenceTimer > 146)
            {
                gMain.blendBrightness = 4;

                if (gCurrentPinballGame->entrySequenceTimer <= 148)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->paletteCycleIndex = 1;
                    gCurrentPinballGame->fieldScrollState = 0;
                }
            }
            else
            {
                gMain.blendBrightness = 7;

                if (gCurrentPinballGame->entrySequenceTimer <= 145)
                {
                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[2] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->paletteCycleIndex = 2;
                    gCurrentPinballGame->fieldScrollState = 0;
                }
            }
        }

        if (gCurrentPinballGame->entrySequenceTimer == 145)
        {
            m4aSongNumStart(MUS_SHOP);

            gCurrentPinballGame->upgradeMenuCursor = 0;
            gCurrentPinballGame->upgradeMenuScrollDirection = 0;
            gCurrentPinballGame->upgradeMenuItemId = gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor];

            SetBoardPortraitGraphics(6, 0);
            UpdatePikachuAttackDisplay(1);

            gMain.boardSpriteGroups[7]->available = 1;
            gMain.boardSpriteGroups[8]->available = 1;
            gMain.boardSpriteGroups[6]->available = 1;
            gMain.boardSpriteGroups[9]->available = 1;

            DmaCopy16(3, gUnknown_081B8784, OBJ_PLTT + 0x1C0, 0x20);
            DmaCopy16(3, gUnknown_081B8984, BG_VRAM + 0x2000, 0xC40);

            gMain.bgOffsets[0].yOffset = 80;
            gMain.splitScreenOffset = 0;
            gCurrentPinballGame->bannerAnimTimer = 15;
            gMain.splitScreenEnabled = 1;

            m4aSongNumStart(SE_UNKNOWN_0x8F);

            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->pikaChargeFull = 1;
            else
                gCurrentPinballGame->pikaChargeFull = 0;
        }

        if (gCurrentPinballGame->entrySequenceTimer <= 144)
        {
            gCurrentPinballGame->slotReelVisualFrame = 0;
            gCurrentPinballGame->hatchRevealState = 2;
            gCurrentPinballGame->spriteLayerPriority = 0;
            var_r7 = 0;

            if (gCurrentPinballGame->bannerAnimTimer > 0)
            {
                if (--gCurrentPinballGame->bannerAnimTimer > 14)
                {
                    gCurrentPinballGame->bannerScrollOffset = (30 - gCurrentPinballGame->bannerAnimTimer) * 7;

                    if (gCurrentPinballGame->bannerAnimTimer == 15)
                    {
                        if (gCurrentPinballGame->upgradeMenuCursor == 3)
                        {
                            if (gCurrentPinballGame->ballUpgradeType <= BALL_UPGRADE_TYPE_ULTRA_BALL)
                                gCurrentPinballGame->upgradeMenuItemId = gCurrentPinballGame->ballUpgradeType + 10;
                            else
                                gCurrentPinballGame->upgradeMenuItemId = 12;
                        }
                        else if (gCurrentPinballGame->upgradeMenuCursor == 6)
                        {
                            if (gMain.selectedField == FIELD_RUBY)
                                gCurrentPinballGame->upgradeMenuItemId = 22;
                            else
                                gCurrentPinballGame->upgradeMenuItemId = 23;
                        }
                        else
                            gCurrentPinballGame->upgradeMenuItemId = gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor];

                        SetBoardPortraitGraphics(6, 0);
                        var_r7 = 1;
                    }
                }
                else
                    gCurrentPinballGame->bannerScrollOffset = gCurrentPinballGame->bannerAnimTimer * 7;
            }
            else
            {
                if (JOY_NEW(DPAD_LEFT) && gCurrentPinballGame->slotReelConfirmed == 0)
                {
                    m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                    if (gCurrentPinballGame->upgradeMenuCursor > 0)
                        gCurrentPinballGame->upgradeMenuCursor--;
                    else
                        gCurrentPinballGame->upgradeMenuCursor = 7;

                    gCurrentPinballGame->upgradeMenuScrollDirection = 1;
                    gCurrentPinballGame->bannerAnimTimer = 30;
                }

                if (JOY_NEW(DPAD_RIGHT))
                {
                    if (gCurrentPinballGame->slotReelConfirmed == 0)
                    {
                        m4aSongNumStart(SE_EVO_SELECTION_MOVE);

                        if (gCurrentPinballGame->upgradeMenuCursor <= 6)
                            gCurrentPinballGame->upgradeMenuCursor++;
                        else
                            gCurrentPinballGame->upgradeMenuCursor = 0;

                        gCurrentPinballGame->upgradeMenuScrollDirection = 0;
                        gCurrentPinballGame->bannerAnimTimer = 30;
                    }
                }
            }

            UpdatePikachuAttackDisplay(var_r7);

            if (gCurrentPinballGame->upgradeMenuScrollDirection != 0)
            {
                if (gCurrentPinballGame->upgradeMenuScrollFrame != 0)
                    gCurrentPinballGame->upgradeMenuScrollFrame--;
                else
                    gCurrentPinballGame->upgradeMenuScrollFrame = 7;
            }
            else if (gCurrentPinballGame->upgradeMenuScrollFrame < 7)
                gCurrentPinballGame->upgradeMenuScrollFrame++;
            else
                gCurrentPinballGame->upgradeMenuScrollFrame = 0;

            DmaCopy16(3, gUnknown_086AD50C[gCurrentPinballGame->upgradeMenuScrollFrame / 2], BG_VRAM + 0x2000, 0xC40);
            gMain.bgOffsets[0].yOffset = 80 - (4 * gMain.splitScreenOffset);

            if (gCurrentPinballGame->menuDismissTimer != 0)
            {
                if (gMain.splitScreenOffset > 0 && --gMain.splitScreenOffset == 0)
                {
                    gMain.splitScreenEnabled = 0;
                    gMain.vCount = 144;
                }
            }
            else if (gMain.splitScreenOffset < 20)
                gMain.splitScreenOffset++;
        }

        if (gCurrentPinballGame->bannerAnimTimer <= 0 && gMain.splitScreenOffset > 19)
        {
            if (JOY_NEW(A_BUTTON) && gCurrentPinballGame->slotReelConfirmed == 0)
            {
                s16 var_r3;
                const u16 *arr = gUnknown_086AD000[gCurrentPinballGame->upgradeMenuItemId];

                if (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                    var_r3 = 999;
                else if (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 4 && gCurrentPinballGame->bonusStagePurchased)
                    var_r3 = 999;
                else
                    var_r3 = arr[3];

                if (gCurrentPinballGame->coins >= var_r3)
                {
                    gCurrentPinballGame->slotReelConfirmed = 1;
                    gCurrentPinballGame->slotReelResult = gCurrentPinballGame->upgradeMenuItemId;
                    gCurrentPinballGame->coins -= var_r3;

                    m4aMPlayAllStop();
                    m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);

                    gCurrentPinballGame->holeEntryState = 19;
                    gCurrentPinballGame->evoTargetCooldown = 30;
                }
                else
                    m4aSongNumStart(SE_FAILURE);
            }
            else if (JOY_NEW(B_BUTTON) && gCurrentPinballGame->slotReelConfirmed == 0)
            {
                gCurrentPinballGame->menuDismissTimer = 30;
                gCurrentPinballGame->bannerAnimTimer = 30;
                m4aSongNumStart(SE_MENU_CANCEL);
            }
        }

        if (gCurrentPinballGame->slotReelConfirmed != 0)
        {
            ProcessSlotReelPrize();

            if (gCurrentPinballGame->plungerAnimFrame == 179)
            {
                gCurrentPinballGame->menuDismissTimer = 30;
                gCurrentPinballGame->bannerAnimTimer = 30;

                if (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 4)
                    gCurrentPinballGame->bonusStagePurchased = 1;
            }
        }

        if (gCurrentPinballGame->menuDismissTimer != 0)
        {
            gCurrentPinballGame->menuDismissTimer--;

            if (gCurrentPinballGame->bannerAnimTimer <= 14)
                gCurrentPinballGame->bannerAnimTimer = 15;

            if (gCurrentPinballGame->menuDismissTimer < 5)
            {
                if (gCurrentPinballGame->menuDismissTimer > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->menuDismissTimer <= 3)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->paletteCycleIndex = 1;
                        gCurrentPinballGame->fieldScrollState = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->menuDismissTimer == 0)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                        gCurrentPinballGame->paletteCycleIndex = 0;
                        gCurrentPinballGame->fieldScrollState = 1;
                    }
                }
            }

            if (gCurrentPinballGame->menuDismissTimer == 0)
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

                if (gCurrentPinballGame->boardEntryMode == 4)
                    gCurrentPinballGame->plungerAnimFrame = 170;
                else
                    gCurrentPinballGame->sequenceTimer = 24;

                if (gCurrentPinballGame->boardState == 2)
                    SetBoardPortraitGraphics(1, 0);
                else
                    SetBoardPortraitGraphics(0, 0);

                gCurrentPinballGame->hatchRevealState = 0;
                gCurrentPinballGame->spriteLayerPriority = 3;
                gCurrentPinballGame->slotReelConfirmed = 0;

                gMain.boardSpriteGroups[7]->available = 0;
                gMain.boardSpriteGroups[8]->available = 0;
                gMain.boardSpriteGroups[6]->available = 0;
                gMain.boardSpriteGroups[9]->available = 0;

                gCurrentPinballGame->bannerType = 0;
            }
        }
    }
    else
    {
        s16 evoTarget = 0;

        if (gCurrentPinballGame->evolvablePartySize > 0)
        {
            if (gCurrentPinballGame->entrySequenceTimer == 149)
            {
                m4aMPlayAllStop();

                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->scrollDelayFrames = 0;
                gCurrentPinballGame->scrollHoldFrames = 120;
                gCurrentPinballGame->scrollTargetBottomY = 0;
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->fieldScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxVariant = 3;
                gCurrentPinballGame->scrollOverrideActive = 1;
                gCurrentPinballGame->scrollFromBottom = 0;
                gCurrentPinballGame->fieldEntryAnimTimer = 80;
                gCurrentPinballGame->bannerScrollPosQ10 = 0xF63C; //-2500
                gCurrentPinballGame->bannerAnimPhase = 50;
                gCurrentPinballGame->bannerScrollVelocity = 0;

                DmaCopy16(3, gUnknown_086ACEF8[3], OBJ_VRAM1 + 0x1800, 0x2400);
                DmaCopy16(3, gUnknown_086ACF18[3], OBJ_PLTT + 0x1C0, 0x20);

                gMain.blendControl = 206;
                gCurrentPinballGame->entrySequenceTimer = 148;
                gCurrentPinballGame->evolvingPartyIndex = 0;
                gCurrentPinballGame->upgradeMenuCursor = 0;
                gCurrentPinballGame->evoStageSelection = 0;
                gCurrentPinballGame->evoSelectionActive = 0;
                gCurrentPinballGame->evoStepCounter = 0;
            }

            if (gCurrentPinballGame->entrySequenceTimer == 146)
            {
                gCurrentPinballGame->bannerType = 18;

                DmaCopy16(3, &gUnknown_084F61EC, OBJ_VRAM1 + 0x1C00, 0x940);
                DmaCopy16(3, &gUnknown_081B4584, PLTT + 0x180, 0x20);
            }

            if (gCurrentPinballGame->entrySequenceTimer == 145)
            {
                int stage1Evo;
                int stage2Evo;
                gCurrentPinballGame->upgradeMenuScrollDirection = 0;
                gCurrentPinballGame->currentSpecies = gCurrentPinballGame->evolvablePartySpecies[gCurrentPinballGame->evolvingPartyIndex];
                gCurrentPinballGame->maxEvoStages = 0;
                stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                if (stage1Evo < SPECIES_NONE)
                {
                    gCurrentPinballGame->maxEvoStages++;
                    stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;
                    if (stage2Evo < SPECIES_NONE)
                        gCurrentPinballGame->maxEvoStages++;

                }

                ShowSpeciesNameBanner();

                if (gMain.selectedField == FIELD_RUBY)
                    m4aSongNumStart(MUS_EVO_MODE);
                else
                    m4aSongNumStart(MUS_EVO_MODE2);

                UpdatePikachuAttackDisplay(var_r7);

                gMain.boardSpriteGroups[8]->available = 1;
                gMain.boardSpriteGroups[9]->available = 1;
                gMain.boardSpriteGroups[6]->available = 1;

                DmaCopy16(3, &gUnknown_081B8784, PLTT + 0x3C0, 0x20);

                gMain.bgOffsets[0].yOffset = 80;
                gMain.splitScreenOffset = 0;
                gCurrentPinballGame->bannerAnimTimer = 15;
                gMain.splitScreenEnabled = 1;

                DmaCopy16(3, &gUnknown_081B4784, VRAM + 0x2000, 0xC40);
            }

            if (gCurrentPinballGame->entrySequenceTimer <= 144)
            {
                gCurrentPinballGame->slotReelVisualFrame = 0;
                gCurrentPinballGame->hatchRevealState = 2;
                gCurrentPinballGame->spriteLayerPriority = 0;

                if (gCurrentPinballGame->bannerAnimTimer > 0)
                {
                    gCurrentPinballGame->bannerAnimTimer--;

                    if (gCurrentPinballGame->evoSelectionActive != 0)
                    {
                        if (gCurrentPinballGame->bannerAnimTimer == 15)
                            ShowSpeciesNameBanner();
                    }
                    else
                    {
                        if (gCurrentPinballGame->bannerAnimTimer > 14)
                        {
                            gCurrentPinballGame->bannerScrollOffset = (30 - gCurrentPinballGame->bannerAnimTimer) * 7;

                            if (gCurrentPinballGame->bannerAnimTimer == 15)
                                ShowSpeciesNameBanner();
                        }
                        else
                            gCurrentPinballGame->bannerScrollOffset = gCurrentPinballGame->bannerAnimTimer * 7;
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
                            gCurrentPinballGame->upgradeMenuScrollDirection = 1;
                            gCurrentPinballGame->bannerAnimTimer = 30;
                            gCurrentPinballGame->evoStageSelection = 0;
                            gCurrentPinballGame->evoSelectionActive = 0;
                            gCurrentPinballGame->maxEvoStages = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->maxEvoStages++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->maxEvoStages++;
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
                            gCurrentPinballGame->upgradeMenuScrollDirection = 0;
                            gCurrentPinballGame->bannerAnimTimer = 30;
                            gCurrentPinballGame->evoStageSelection = 0;
                            gCurrentPinballGame->evoSelectionActive = 0;
                            gCurrentPinballGame->maxEvoStages = 0;
                            stage1Evo = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (stage1Evo < SPECIES_NONE)
                            {
                                gCurrentPinballGame->maxEvoStages++;
                                stage2Evo = gSpeciesInfo[stage1Evo].evolutionTarget;

                                if (stage2Evo < SPECIES_NONE)
                                    gCurrentPinballGame->maxEvoStages++;
                            }
                        }
                    }

                    if (JOY_NEW(DPAD_UP))
                    {
                        if (gCurrentPinballGame->evoStageSelection == 0)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->bannerAnimTimer = 30;
                                gCurrentPinballGame->evoSelectionActive = 1;
                                gCurrentPinballGame->evoStageSelection++;
                            }
                        }
                        else if (gCurrentPinballGame->evoStageSelection == 1)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->evoTargetSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->bannerAnimTimer = 30;
                                gCurrentPinballGame->evoSelectionActive = 1;
                                gCurrentPinballGame->evoStageSelection++;
                            }
                        }

                        gCurrentPinballGame->evoStepCounter = 0;
                    }
                    else if (JOY_NEW(DPAD_DOWN))
                    {
                        if (gCurrentPinballGame->evoStageSelection == 1)
                        {
                            evoTarget = gCurrentPinballGame->currentSpecies;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->bannerAnimTimer = 30;
                                gCurrentPinballGame->evoSelectionActive = 1;
                                gCurrentPinballGame->evoStageSelection--;
                            }
                        }
                        else if (gCurrentPinballGame->evoStageSelection == 2)
                        {
                            evoTarget = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionTarget;

                            if (evoTarget < SPECIES_NONE)
                            {
                                m4aSongNumStart(SE_EVO_SELECTION_MOVE);
                                gCurrentPinballGame->evoTargetSpecies = evoTarget;
                                gCurrentPinballGame->bannerAnimTimer = 30;
                                gCurrentPinballGame->evoSelectionActive = 1;
                                gCurrentPinballGame->evoStageSelection--;
                            }
                        }

                        gCurrentPinballGame->evoStepCounter = 0;
                    }

                    if (gCurrentPinballGame->evoStageSelection > 0)
                    {
                        switch (gCurrentPinballGame->evoTargetSpecies)
                        {
                        case 14:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 16;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        case 16:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 14;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        case 89:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 90;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        case 90:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 89;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        case 176:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 177;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        case 177:
                            if (gCurrentPinballGame->evoStepCounter == 50)
                            {
                                gCurrentPinballGame->evoStepCounter = 0;
                                gCurrentPinballGame->evoTargetSpecies = 176;
                                ShowSpeciesNameBanner();
                            }
                            break;
                        }

                        gCurrentPinballGame->evoStepCounter++;
                    }
                }

                UpdateSpeciesNameBannerPosition();

                if (gCurrentPinballGame->upgradeMenuScrollDirection != 0)
                {
                    if (gCurrentPinballGame->upgradeMenuScrollFrame != 0)
                        gCurrentPinballGame->upgradeMenuScrollFrame--;
                    else
                        gCurrentPinballGame->upgradeMenuScrollFrame = 7;
                }
                else
                {
                    if (gCurrentPinballGame->upgradeMenuScrollFrame <= 6)
                        gCurrentPinballGame->upgradeMenuScrollFrame++;
                    else
                        gCurrentPinballGame->upgradeMenuScrollFrame = 0;
                }

                DmaCopy16(3, gUnknown_086AD50C[gCurrentPinballGame->upgradeMenuScrollFrame / 2 + 4], VRAM + 0x2000, 0xC40);
                gMain.bgOffsets[0].yOffset = 80 - (gMain.splitScreenOffset * 4);

                if (gCurrentPinballGame->menuDismissTimer != 0)
                {
                    if (gMain.splitScreenOffset > 0 && --gMain.splitScreenOffset == 0)
                    {
                        gMain.splitScreenEnabled = 0;
                        gMain.vCount = 144;
                    }
                }
                else if (gMain.splitScreenOffset <= 19)
                    gMain.splitScreenOffset++;

                UpdatePikachuAttackDisplay(0);
            }

            if (gCurrentPinballGame->bannerAnimTimer <= 0 && gMain.splitScreenOffset > 19 && JOY_NEW(A_BUTTON) == A_BUTTON)
            {
                gCurrentPinballGame->menuDismissTimer = 30;
                gCurrentPinballGame->evoSelectionActive = 0;
                gCurrentPinballGame->bannerAnimTimer = 30;
                m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);
            }

            if (gCurrentPinballGame->menuDismissTimer == 0)
                return;

            gCurrentPinballGame->menuDismissTimer--;

            if (gCurrentPinballGame->bannerAnimTimer <= 14)
                gCurrentPinballGame->bannerAnimTimer = 15;

            if (gCurrentPinballGame->menuDismissTimer <= 4)
            {
                if (gCurrentPinballGame->menuDismissTimer > 1)
                {
                    gMain.blendBrightness = 4;

                    if (gCurrentPinballGame->menuDismissTimer <= 3)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1], OBJ_PLTT, 0x20);

                        if (gMain.selectedField == FIELD_SAPPHIRE)
                        {
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                        }
                        else
                            DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[1] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);
                        gCurrentPinballGame->paletteCycleIndex = 1;
                        gCurrentPinballGame->fieldScrollState = 1;
                    }
                }
                else
                {
                    gMain.blendBrightness = 0;

                    if (gCurrentPinballGame->menuDismissTimer != 0)
                        return;

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0], OBJ_PLTT, 0x20);

                    if (gMain.selectedField == FIELD_SAPPHIRE)
                    {
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, OBJ_PLTT + 0x40, 0xC0);
                    }
                    else
                        DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x40, (void *)(OBJ_PLTT + 0x40), 0xE0);

                    DmaCopy16(3, gBoardConfig.fieldLayout.objPaletteData[0] + 0x140, (void *)(OBJ_PLTT + 0x140), 0x60);

                    gCurrentPinballGame->paletteCycleIndex = 0;
                    gCurrentPinballGame->fieldScrollState = 1;
                }
            }

            if (gCurrentPinballGame->menuDismissTimer == 0)
            {
                if (gCurrentPinballGame->boardEntryMode == 4)
                    gCurrentPinballGame->plungerAnimFrame = 170;
                else
                    gCurrentPinballGame->sequenceTimer = 24;

                gCurrentPinballGame->hatchRevealState = 0;
                gCurrentPinballGame->spriteLayerPriority = 3;

                gMain.boardSpriteGroups[8]->available = 0;
                gMain.boardSpriteGroups[6]->available = 0;
                gMain.boardSpriteGroups[9]->available = 0;

                gCurrentPinballGame->bumperFlashAnimTimer = 0;
                gCurrentPinballGame->bumperHitTimers[0] = 4;
                gCurrentPinballGame->bumperHitTimers[1] = 4;
                gCurrentPinballGame->bumperHitTimers[2] = 4;

                HideSpeciesNameBanner();
                gCurrentPinballGame->bannerType = 0;
            }
        }
        else if (gCurrentPinballGame->entrySequenceTimer == 50)
            gCurrentPinballGame->sequenceTimer = 24;

    }
}

void InitCenterHoleEntry(void)
{
    gCurrentPinballGame->sequenceTimer = 0x96;
    gMain.boardSpriteGroups[13]->available = 0;
    gCurrentPinballGame->centerHoleAttractionActive = 0;
    gCurrentPinballGame->scoreAddedInFrame = 10000;
    gCurrentPinballGame->ballLocked = 1;
    PlayRumble(8);
}

void UpdateCenterHoleAnimation(void)
{
    if (gCurrentPinballGame->sequenceTimer)
    {
        gCurrentPinballGame->sequenceTimer--;
        if (gCurrentPinballGame->sequenceTimer > 148)
        {
            gCurrentPinballGame->ball->isGrabbed = 1;
            gCurrentPinballGame->ballLockState = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->spin = 0;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            gCurrentPinballGame->ballSpriteVariant = 1;
        }
        else if (gCurrentPinballGame->sequenceTimer == 148)
        {
            gCurrentPinballGame->ballLockState = 1;
            gCurrentPinballGame->ballSpriteVariant = 0;
        }
        else if (gCurrentPinballGame->sequenceTimer > 36)
        {
            gCurrentPinballGame->ballLockState = 1;
            gCurrentPinballGame->ballSpriteVariant = 0;
        }
        else if (gCurrentPinballGame->sequenceTimer > 24)
        {
            gCurrentPinballGame->ballLockState = 1;
            gCurrentPinballGame->ballSpriteVariant = 1;
        }
        else if (gCurrentPinballGame->sequenceTimer == 24)
        {
            m4aSongNumStart(SE_UNKNOWN_0x80);
            gCurrentPinballGame->ballSpriteVariant = 2;
            gCurrentPinballGame->ball->velocity.x = 73;
            gCurrentPinballGame->ball->velocity.y = 236;
            gCurrentPinballGame->ball->isGrabbed = 0;
            gCurrentPinballGame->ballLockState = 0;
            gCurrentPinballGame->bossActive = 0;
            gCurrentPinballGame->ball->scale = 0x88;
            gCurrentPinballGame->ballLocked = 0;
        }
        else if (gCurrentPinballGame->sequenceTimer > 12)
        {
            gCurrentPinballGame->ballSpriteVariant = 2;
            if (gCurrentPinballGame->sequenceTimer > 21)
                gCurrentPinballGame->ball->scale = ((24 - gCurrentPinballGame->sequenceTimer) * 0x70 / 3) + 0x90;
            else
                gCurrentPinballGame->ball->scale = 0x100;
        }
        else
        {
            gCurrentPinballGame->ballSpriteVariant = 1;
        }
        if (gCurrentPinballGame->sequenceTimer <= 40)
        {
            if (gCurrentPinballGame->fieldScrollOffsetY > 0)
            {
                gCurrentPinballGame->fieldScrollOffsetY--;
            }
        }
    }
    else
    {
        gCurrentPinballGame->ballSpriteVariant = 0;
        gCurrentPinballGame->boardEntryMode = 0;
    }
}

void TransitionToBonusField(void)
{
    gMain.boardSpriteGroups[13]->available = 0;
    SaveBoardStateForPause(0);
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->isGrabbed = 0;
    gCurrentPinballGame->ballLockState = 0;
    gCurrentPinballGame->ball->scale = 0x100;
    gCurrentPinballGame->ballSpriteVariant = 0;
    gCurrentPinballGame->boardEntryMode = 0;
    if (gCurrentPinballGame->ballReturnMode == 0)
    {
        gCurrentPinballGame->activatedBumperCount = 0;
        gCurrentPinballGame->bumperFlashAnimTimer = 0;
        gCurrentPinballGame->bumperHitTimers[0] = 0;
        gCurrentPinballGame->bumperHitTimers[1] = 0;
        gCurrentPinballGame->bumperHitTimers[2] = 0;
    }
    m4aMPlayAllStop();
    DisableVBlankProcessing();
    gMain.currentField = gMain.selectedField;
    gMain.selectedField = gCurrentPinballGame->pendingBonusFieldId;
    gMain.isBonusField = 1;
    gMain.subState = 0;
}