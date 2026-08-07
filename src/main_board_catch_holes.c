#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

/// @brief 
/// @param arg0 0 = shop, 1= evolution selection
void UpdateShopEntryAnimation(s16 arg0)
{
    int showSelectionUI = FALSE;

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->shopEntryTimer != 0)
        gCurrentPinballGame->shopEntryTimer--;

    if (arg0 == 0)
    {
        if (gCurrentPinballGame->shopEntryTimer == 149)
        {
            m4aMPlayAllStop();
            gCurrentPinballGame->outcomeFrameCounter = 0;
            gCurrentPinballGame->prizeSelected = FALSE;
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
                    gCurrentPinballGame->paletteSwapActive = FALSE;
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
                    gCurrentPinballGame->paletteSwapActive = FALSE;
                }
            }
        }

        if (gCurrentPinballGame->shopEntryTimer == 145)
        {
            m4aSongNumStart(MUS_SHOP);

            gCurrentPinballGame->shopItemCursor = 0;
            gCurrentPinballGame->shopSlideDirection = 0;
            gCurrentPinballGame->shopSelectedItemId = gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor];

            LoadPortraitGraphics(PORTRAIT_STATE_SHOP_SELECTOR, PORTRAIT_MAIN_SLOT);
            RenderEvolutionUI(1);

            gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_COINS]->active = TRUE;
            gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_CONFIRMATION_PANEL]->active = TRUE;
            gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_ARROWS]->active = TRUE;
            gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_PORTRAIT_OVERLAY]->active = TRUE;

            DmaCopy16(3, gShopEvoUI_Pals, OBJ_PLTT + 0x1C0, 0x20);
            DmaCopy16(3, gShopModeBG0_0_Tilemap, BG_VRAM + 0x2000, 0xC40);

            gMain.bgOffsets[0].yOffset = 80;
            gMain.shopPanelSlideOffset = 0;
            gCurrentPinballGame->shopAnimSlideTimer = 15;
            gMain.shopPanelActive = TRUE;

            m4aSongNumStart(SE_SHOP_LIST_REVEAL);

            if (gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES)
                gCurrentPinballGame->shopPikaSaverMaxed = TRUE;
            else
                gCurrentPinballGame->shopPikaSaverMaxed = FALSE;
        }

        if (gCurrentPinballGame->shopEntryTimer <= 144)
        {
            gCurrentPinballGame->rouletteSubOffset = 0;
            gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_SHOP;
            gCurrentPinballGame->creatureOamPriority = 0;
            showSelectionUI = FALSE;

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
                                gCurrentPinballGame->shopSelectedItemId = gCurrentPinballGame->ballUpgradeType + PRIZE_BALL_UPGRADE_A;
                            else
                                gCurrentPinballGame->shopSelectedItemId = PRIZE_BALL_UPGRADE_C;
                        }
                        else if (gCurrentPinballGame->shopItemCursor == 6)
                        {
                            if (gMain.selectedField == FIELD_RUBY)
                                gCurrentPinballGame->shopSelectedItemId = PRIZE_WISCASH_ACTIVE_SPHEAL_OPPORTUNITY;
                            else
                                gCurrentPinballGame->shopSelectedItemId = PRIZE_PELIPPER_ACTIVE_SPHEAL_OPPORTUNITY;
                        }
                        else
                            gCurrentPinballGame->shopSelectedItemId = gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor];

                        LoadPortraitGraphics(PORTRAIT_STATE_SHOP_SELECTOR, PORTRAIT_MAIN_SLOT);
                        showSelectionUI = TRUE;
                    }
                }
                else
                    gCurrentPinballGame->shopUISlideOffset = gCurrentPinballGame->shopAnimSlideTimer * 7;
            }
            else
            {
                if (JOY_NEW(DPAD_LEFT) && !gCurrentPinballGame->prizeSelected)
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
                    if (!gCurrentPinballGame->prizeSelected)
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

            RenderEvolutionUI(showSelectionUI);

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
                    gMain.shopPanelActive = FALSE;
                    gMain.vCount = 144;
                }
            }
            else if (gMain.shopPanelSlideOffset < 20)
                gMain.shopPanelSlideOffset++;
        }

        if (gCurrentPinballGame->shopAnimSlideTimer <= 0 && gMain.shopPanelSlideOffset > 19)
        {
            if (JOY_NEW(A_BUTTON) && !gCurrentPinballGame->prizeSelected)
            {
                s16 price;
                const u16 *itemData = gShopItemData[gCurrentPinballGame->shopSelectedItemId];

                if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_PICHU_SAVER
                    && gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES)
                    price = 999;
                else if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_EXTRA_BALL
                    && gCurrentPinballGame->shopExtraBallPreviouslyPurchased)
                    price = 999;
                else
                    price = itemData[3];

                if (gCurrentPinballGame->coins >= price)
                {
                    gCurrentPinballGame->prizeSelected = TRUE;
                    gCurrentPinballGame->prizeId = gCurrentPinballGame->shopSelectedItemId;
                    gCurrentPinballGame->coins -= price;

                    m4aMPlayAllStop();
                    m4aSongNumStart(SE_EVO_SELECTION_CONFIRM);

                    gCurrentPinballGame->shopDoorOpenLevel = 19;
                    gCurrentPinballGame->sapphireBumperLitCountdown = 30;
                }
                else
                    m4aSongNumStart(SE_FAILURE);
            }
            else if (JOY_NEW(B_BUTTON) && !gCurrentPinballGame->prizeSelected)
            {
                gCurrentPinballGame->catchModeEventTimer = 30;
                gCurrentPinballGame->shopAnimSlideTimer = 30;
                m4aSongNumStart(SE_MENU_CANCEL);
            }
        }

        if (gCurrentPinballGame->prizeSelected)
        {
            GivePrize();

            if (gCurrentPinballGame->outcomeFrameCounter == 179)
            {
                gCurrentPinballGame->catchModeEventTimer = 30;
                gCurrentPinballGame->shopAnimSlideTimer = 30;

                if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_EXTRA_BALL)
                    gCurrentPinballGame->shopExtraBallPreviouslyPurchased = TRUE;
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
                        gCurrentPinballGame->paletteSwapActive = TRUE;
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
                        gCurrentPinballGame->paletteSwapActive = TRUE;
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

                if (gCurrentPinballGame->boardState == MAIN_BOARD_STATE_BONUS_HOLE_ACTIVE)
                    LoadPortraitGraphics(PORTRAIT_STATE_SLOT_START_CARD, PORTRAIT_MAIN_SLOT);
                else
                    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);

                gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
                gCurrentPinballGame->creatureOamPriority = 3;
                gCurrentPinballGame->prizeSelected = FALSE;

                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_COINS]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_CONFIRMATION_PANEL]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_ARROWS]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_PORTRAIT_OVERLAY]->active = FALSE;

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
                gCurrentPinballGame->bannerGfxIndex = BANNER_MODE_EVOLUTION;
                gCurrentPinballGame->bannerActive = TRUE;
                gCurrentPinballGame->holdCameraLockAfterBanner = FALSE;
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
                gCurrentPinballGame->evoNameSlideOnly = FALSE;
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

                RenderEvolutionUI(showSelectionUI);

                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_CONFIRMATION_PANEL]->active = TRUE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_PORTRAIT_OVERLAY]->active = TRUE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_ARROWS]->active = TRUE;

                DmaCopy16(3, &gShopEvoUI_Pals, PLTT + 0x3C0, 0x20);

                gMain.bgOffsets[0].yOffset = 80;
                gMain.shopPanelSlideOffset = 0;
                gCurrentPinballGame->shopAnimSlideTimer = 15;
                gMain.shopPanelActive = TRUE;

                DmaCopy16(3, &gEvoModeBG0_0_Tilemap, VRAM + 0x2000, 0xC40);
            }

            if (gCurrentPinballGame->shopEntryTimer <= 144)
            {
                gCurrentPinballGame->rouletteSubOffset = 0;
                gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_SHOP;
                gCurrentPinballGame->creatureOamPriority = 0;

                if (gCurrentPinballGame->shopAnimSlideTimer > 0)
                {
                    gCurrentPinballGame->shopAnimSlideTimer--;

                    if (gCurrentPinballGame->evoNameSlideOnly)
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
                            gCurrentPinballGame->evoNameSlideOnly = FALSE;
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
                            gCurrentPinballGame->evoNameSlideOnly = FALSE;
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
                                gCurrentPinballGame->evoNameSlideOnly = TRUE;
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
                                gCurrentPinballGame->evoNameSlideOnly = TRUE;
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
                                gCurrentPinballGame->evoNameSlideOnly = TRUE;
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
                                gCurrentPinballGame->evoNameSlideOnly = TRUE;
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
                        gMain.shopPanelActive = FALSE;
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
                gCurrentPinballGame->evoNameSlideOnly = FALSE;
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
                        gCurrentPinballGame->paletteSwapActive = TRUE;
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
                    gCurrentPinballGame->paletteSwapActive = TRUE;
                }
            }

            if (gCurrentPinballGame->catchModeEventTimer == 0)
            {
                if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
                    gCurrentPinballGame->outcomeFrameCounter = 170;
                else
                    gCurrentPinballGame->modeAnimTimer = 24;

                gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
                gCurrentPinballGame->creatureOamPriority = 3;

                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_CONFIRMATION_PANEL]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_ARROWS]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_MAIN_SHOP_PORTRAIT_OVERLAY]->active = FALSE;

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
    gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
    gCurrentPinballGame->bonusTrapEnabled = FALSE;
    gCurrentPinballGame->scoreAddedInFrame = SCORE_CENTER_TRAP_HOLE;
    gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
    PlayRumble(8);
}

void AnimateCenterTrapSequence(void)
{
    if (gCurrentPinballGame->modeAnimTimer)
    {
        gCurrentPinballGame->modeAnimTimer--;
        if (gCurrentPinballGame->modeAnimTimer > 148)
        {
            gCurrentPinballGame->ball->ballHidden = TRUE;
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
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
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            gCurrentPinballGame->trapAnimState = 0;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 36)
        {
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            gCurrentPinballGame->trapAnimState = 0;
        }
        else if (gCurrentPinballGame->modeAnimTimer > 24)
        {
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
            gCurrentPinballGame->trapAnimState = 1;
        }
        else if (gCurrentPinballGame->modeAnimTimer == 24)
        {
            m4aSongNumStart(SE_CENTER_HOLE_EJECT);
            gCurrentPinballGame->trapAnimState = 2;
            gCurrentPinballGame->ball->velocity.x = 73;
            gCurrentPinballGame->ball->velocity.y = 236;
            gCurrentPinballGame->ball->ballHidden = FALSE;
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
            gCurrentPinballGame->cameraLocked = FALSE;
            gCurrentPinballGame->ball->scale = 0x88;
            gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
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
    gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
    SaveGameStateSnapshot(0);
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->ballHidden = FALSE;
    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
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
    gMain.isBonusField = TRUE;
    gMain.subState = 0;
}