#include "global.h"
#include "main.h"

extern const u16 gPortraitGenericPalettes[];
extern const u16 gPortraitPaletteSlots[2];
extern const u16 gPortraitIdleCycleData[];
extern const u16 gPortraitAnimPalettes[];

extern const s16 gRouletteOutcomeFrameOffsets[];

/*
    File is used for the center screen display on the main board.
    Can contain travel location picture, catch mon, roulette wheel
*/

void LoadPortraitGraphics(s16 arg0, s16 arg1)
{
    s16 i;
    s16 var0;
    s16 sp0[16];
    s16 rgb[3];
    u16 index;
    const u16 *ptr;
    const u16 *ptr2;
    u16 index2;

    switch (arg0)
    {
    case 0:
        gCurrentPinballGame->creatureOamPriority = 3;
        gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->roulettePortraitIndexes[arg1];
        DmaCopy16(3, gPortraitGenericGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        index = gCurrentPinballGame->roulettePortraitIndexes[arg1] * 0x10;
        DmaCopy16(3, &gPortraitGenericPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    case 1:
        ptr = gPortraitIdleCycleData;
        gCurrentPinballGame->portraitGfxIndex[arg1] = ptr[(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    case 2:
        ptr = gShopItemData[gCurrentPinballGame->modeOutcomeValues[arg1]];
        gCurrentPinballGame->portraitGfxIndex[arg1] = ptr[0];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    case 3:
        gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->currentSpecies;
        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 24,
            0x300);
        DmaCopy16(
            3,
            gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x20,
            (void *)0x050003A0 ,
            0x20);
        DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003E0, 0x20);
        break;
    case 9:
        if (gCurrentPinballGame->evoChainPosition > 0)
        {
            if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == SPECIES_UNSEEN)
            {
                gCurrentPinballGame->portraitGfxIndex[arg1] = SPECIES_NONE;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
            else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] < SPECIES_CAUGHT)
            {
                gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003A0, 0x20);
            }
            else
            {
                gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
        }
        else
        {
            gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->currentSpecies;
            DmaCopy16(
                3,
                gMonPortraitGroupPals[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x20,
                (void *)0x050003A0,
                0x20);
        }

        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitGfxIndex[arg1] / 15] + (gCurrentPinballGame->portraitGfxIndex[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 0x18,
            0x300);
        break;
    case 4:
        if (gCurrentPinballGame->boardSubState == 2)
        {
            gCurrentPinballGame->portraitGfxIndex[arg1] = gShopItemData[15][(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);

            // !!!!! BUG: this should be multiplied by 16 !!
            index = gShopItemData[15][2];
        }
        else
        {
            gCurrentPinballGame->portraitGfxIndex[arg1] = gShopItemData[16][(gCurrentPinballGame->portraitCycleFrame % 48) / 24];
            DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
            index = gShopItemData[16][2] * 16;
        }
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    case 6:
        ptr = gShopItemData[gCurrentPinballGame->shopSelectedItemId];
        gCurrentPinballGame->portraitGfxIndex[arg1] = ptr[0];
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        if (gCurrentPinballGame->coins < ptr[3] ||
            (
                (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                ||
                (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 4 && gCurrentPinballGame->shopBonusStageAlreadyBought)
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

            DmaCopy16(3, sp0, (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        }
        else
        {
            DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        }
        break;
    case 7:
        // TODO: fake match
        ptr2 = ptr = gShopItemData[gCurrentPinballGame->modeOutcomeValues[arg1]];
        gCurrentPinballGame->portraitGfxIndex[arg1] = *(ptr2 += (gCurrentPinballGame->portraitCycleFrame % 48) / 24);
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    case 8:
        // TODO: fake match
        ptr2 = ptr = gShopItemData[gCurrentPinballGame->rouletteOutcomeId];
        gCurrentPinballGame->portraitGfxIndex[arg1] = *(ptr2 += gRouletteOutcomeFrameOffsets[gCurrentPinballGame->outcomeFrameCounter / 12]);
        index = ptr[2] * 16;
        DmaCopy16(3, gPortraitAnimFrameGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gPortraitAnimPalettes[index], (void *)0x05000200 + gPortraitPaletteSlots[arg1] * 0x20, 0x20);
        break;
    }

    gCurrentPinballGame->portraitRenderMode[arg1] = arg0;
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

    if (gCurrentPinballGame->portraitDisplayState == 3)
    {
        baseX = 0;
        var1 = 180;
        var2 = 180;
    }
    else if (gCurrentPinballGame->portraitDisplayState == 2)
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

    group = gMain.fieldSpriteGroups[22];
    group->baseX = baseX;
    group->baseY = var1;
    gCurrentPinballGame->rouletteBasePos.x = baseX;
    gCurrentPinballGame->rouletteBasePos.y = group->baseY;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].paletteNum = gCurrentPinballGame->hatchTilePalette[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->portraitDisplayState == 1)
    {
        group = gMain.fieldSpriteGroups[23];
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

        group = gMain.fieldSpriteGroups[20];
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

        group = gMain.fieldSpriteGroups[21];
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

    group = gMain.fieldSpriteGroups[19];
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

    if (gCurrentPinballGame->portraitDisplayState == 1)
    {
        group = gMain.fieldSpriteGroups[22];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[23];
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[20];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[21];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}
