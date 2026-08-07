#include "global.h"
#include "main.h"
#include "constants/board/center_screen_states.h"
#include "constants/board/main_board.h"

extern const u16 gLocationPalettes[];
extern const u16 gPortraitPaletteSlots[2];
extern const u16 gPortraitAnimPalettes[];

extern const s16 gRouletteOutcomeFrameOffsets[];

/*
    File is used for the center screen display on the main board.
    Can contain travel location picture, catch mon, roulette wheel.

    displayMode tells it what type of graphics to load.
    picIx is 0/1. (can draw up to 2 pics at once, during roulette.)
*/

void LoadPortraitGraphics(s16 displayMode, s16 picIx)
{
    s16 i;
    s16 sp0[16];
    s16 rgb[3];
    u16 index;
    const u16 *ptr;
    const u16 *ptr2;
    u16 index2;

    switch (displayMode)
    {
    case PORTRAIT_STATE_CURRENT_LOCATION:
        gCurrentPinballGame->creatureOamPriority = 3;
        gCurrentPinballGame->portraitGfxIndex[picIx] = gCurrentPinballGame->areaRoulettePortraitIndex[picIx];
        DmaCopy16(3, gLocationPortraitGfx[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        index = gCurrentPinballGame->areaRoulettePortraitIndex[picIx] * 0x10;
        DmaCopy16(3, &gLocationPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    case PORTRAIT_STATE_SLOT_START_CARD:
        ptr = gShopItemData[START_SLOT_CARD];
        gCurrentPinballGame->portraitGfxIndex[picIx] = ptr[(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    case PORTRAIT_STATE_ROULETTE_WHEEL:
        ptr = gShopItemData[gCurrentPinballGame->modeOutcomeValues[picIx]];
        gCurrentPinballGame->portraitGfxIndex[picIx] = ptr[0];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    case PORTRAIT_STATE_POKEMON_DISPLAY:
        gCurrentPinballGame->portraitGfxIndex[picIx] = gCurrentPinballGame->currentSpecies;
        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x300,
            (void *)0x06010CA0 + picIx * 24,
            0x300);
        DmaCopy16(
            3,
            gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x20,
            (void *)0x050003A0 ,
            0x20);
        DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003E0, 0x20);
        break;
    case PORTRAIT_STATE_EVO_PREVIEW:
        if (gCurrentPinballGame->evoChainPosition > 0)
        {
            if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == SPECIES_UNSEEN)
            {
                gCurrentPinballGame->portraitGfxIndex[picIx] = SPECIES_NONE;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
            else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] < SPECIES_CAUGHT)
            {
                gCurrentPinballGame->portraitGfxIndex[picIx] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003A0, 0x20);
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[picIx] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
        }
        else
        {
            gCurrentPinballGame->portraitGfxIndex[picIx] = gCurrentPinballGame->currentSpecies;
            DmaCopy16(
                3,
                gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x20,
                (void *)0x050003A0,
                0x20);
        }

        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[picIx] / 15] + (gCurrentPinballGame->portraitGfxIndex[picIx] % 15) * 0x300,
            (void *)0x06010CA0 + picIx * 0x18,
            0x300);
        break;
    case PORTRAIT_STATE_TRAVEL_RAMP_INDICATOR:
        if (gCurrentPinballGame->boardSubState == TRAVEL_SUBSTATE_STOP_LANE_INDICATORS)
        {
            // This code state likely doesn't matter - Board is in this board substate for exactly 1 frame.
            gCurrentPinballGame->portraitGfxIndex[picIx] = gShopItemData[GOTO_NEXT_CARD][(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);

            // !!!!! BUG: this should be multiplied by 16 !!
            index = gShopItemData[GOTO_NEXT_CARD][2];
        }
        else
        {
            gCurrentPinballGame->portraitGfxIndex[picIx] = gShopItemData[TRAVEL_RAMP_INDICATOR_CARD][(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
            index = gShopItemData[TRAVEL_RAMP_INDICATOR_CARD][2] * 16;
        }
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    case PORTRAIT_STATE_SHOP_SELECTOR:
        ptr = gShopItemData[gCurrentPinballGame->shopSelectedItemId];
        gCurrentPinballGame->portraitGfxIndex[picIx] = ptr[0];
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        if (gCurrentPinballGame->coins < ptr[3] ||
            (
                (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_PICHU_SAVER
                    && gCurrentPinballGame->outLanePikaPosition == PIKA_BOTH_SIDES)
                ||
                (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == PRIZE_EXTRA_BALL
                    && gCurrentPinballGame->shopExtraBallPreviouslyPurchased)
            ))
        {
            DmaCopy16(3, &gPortraitAnimPalettes[index], sp0, 0x20);
            for (i = 0; i < 16; i++)
            {
                rgb[0] = ((sp0[i] & 0x1F) * 2) / 3;
                rgb[1] = ((sp0[i] & 0x3E0) >> 4) / 3;
                rgb[2] = ((sp0[i] & 0x7C00) >> 9) / 3;
                sp0[i] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }

            DmaCopy16(3, sp0, (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        }
        else
        {
            DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        }
        break;
    case PORTRAIT_STATE_CONFIRMATION_PROMPT:
        // TODO: fake match
        ptr2 = ptr = gShopItemData[gCurrentPinballGame->modeOutcomeValues[picIx]];
        gCurrentPinballGame->portraitGfxIndex[picIx] = *(ptr2 += (gCurrentPinballGame->portraitCycleFrame % 48) / 24);
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    case PORTRAIT_STATE_ROULETTE_OUTCOME:
        // TODO: fake match
        ptr2 = ptr = gShopItemData[gCurrentPinballGame->prizeId];
        gCurrentPinballGame->portraitGfxIndex[picIx] = *(ptr2 += gRouletteOutcomeFrameOffsets[gCurrentPinballGame->outcomeFrameCounter / 12]);
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[picIx]], (void *)0x06010CA0 + picIx * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[picIx] * 0x20, 0x20);
        break;
    }

    gCurrentPinballGame->portraitRenderMode[picIx] = displayMode;
    gCurrentPinballGame->portraitCycleFrame++;
}

void UpdatePortraitSpritePositions(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 baseX;
    s16 var1;
    s16 var2;

    if (gCurrentPinballGame->portraitDisplayState == PORTRAIT_DISPLAY_MODE_BANNER)
    {
        baseX = 0;
        var1 = 180;
        var2 = 180;
    }
    else if (gCurrentPinballGame->portraitDisplayState == PORTRAIT_DISPLAY_MODE_SHOP)
    {
        if (gMain.shopPanelSlideOffset < 20)
        {
            var1 = 180;
            var2 = 180;
        }
        else
        {
            var1 = 88 + gCurrentPinballGame->rouletteSubOffset;
            var2 = 88;
        }

        baseX = 48;
    }
    else
    {
        baseX = 96 - gCurrentPinballGame->cameraXOffset;
        var1 = gCurrentPinballGame->rouletteSubOffset + 300u - gCurrentPinballGame->cameraYOffset;
        var2 = 300 - gCurrentPinballGame->cameraYOffset;
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_PORTRAIT];
    group->baseX = baseX;
    group->baseY = var1;
    gCurrentPinballGame->rouletteBasePos.x = baseX;
    gCurrentPinballGame->rouletteBasePos.y = group->baseY;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].paletteNum = gCurrentPinballGame->catchTilePalette[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->portraitDisplayState == PORTRAIT_DISPLAY_MODE_ROULETTE)
    {
        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1];
        group->baseX = baseX;
        group->baseY = var1 - 0x20;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].paletteNum = 12;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM];
        group->baseX = baseX;
        group->baseY = 267 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM];
        group->baseX = baseX;
        group->baseY = 333 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_PORTRAIT_BORDERS];
    group->baseX = baseX - 8;
    group->baseY = var2 - 8;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void ClampPortraitSpritesToOffscreen(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    if (gCurrentPinballGame->portraitDisplayState == PORTRAIT_DISPLAY_MODE_ROULETTE)
    {
        group = gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_PORTRAIT];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1];
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
