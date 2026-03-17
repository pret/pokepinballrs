#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const u8 gSideBumperGfx[][0x100];
extern const s16 gSideBumperGfxFrameIndices[][2];
extern const u16 gSideBumperAnimDurations[][2];
extern const s16 gGulpinAnimData[][5];
extern const u16 gGulpinOamData[146][18];
extern const u8 gRubyStageGulpin_Gfx[][0x180];
extern const s16 gChikoritaFlashFrameIndices[];
extern const u8 gRubyFlashingDecorationTiles[][0x300];
extern const u8 gChikoritaExplosionTiles[][0x100];
extern const u8 gChikoritaProjectileTiles[][0x80];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const s16 gSharpedoAnimFrameData[][2];
extern const u16 gSharpedoSpritesheetOam[42][3][3];
extern const u8 gRubyFlashingTiles_Secondary[][0x100];
extern const u8 gLotadBumperTiles[][0x100];
extern const u8 gChinchouBumperPalettes[];
extern const u8 gLotadBumperPalettes[];
extern const s16 gPondBumperTransitionFrames[];
extern const struct Vector16 gChinchouWaypointPositions[];
extern const s16 gWhiscashFramesetData[][4];
extern const s16 gWhiscashShakeOffsets[];
extern const s16 gLotadBobOffsets[];
extern const u8 gWhiscashPalettes[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const s16 gNuzleafAnimFrameData[50][3];
extern const s16 gNuzleafPositions[][2];
extern const u8 gRubyStageNuzleaf_Gfx[][0x280];
extern const u16 gNuzleafOamData[58][6];
extern const u16 gPortraitGenericPalettes[];
extern const u16 gPortraitPaletteSlots[2];
extern const u16 gPortraitIdleCycleData[];
extern const u16 gPortraitAnimPalettes[];
extern const s16 gRouletteOutcomeFrameOffsets[];

extern struct SongHeader se_pika_full_charge_1_up;
extern struct SongHeader se_pika_spinner_clack;
extern struct SongHeader se_whiscash_splashdown;
extern struct SongHeader se_pika_no_kickback;
extern struct SongHeader se_pikachu_kickback;
extern struct SongHeader se_pichu_kickback;
extern s16 gPikaSaverAnimFrameTable[100];
extern s16 gOutlaneCenterXPositions[2];
extern u16 gCatchOverlayAnimData[][2];
extern s16 gCatchOverlayOamData[28][12];

#define MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE 3


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
        gCurrentPinballGame->portraitGfxIndex[arg1] = gCurrentPinballGame->rouletteAreaIndex[arg1];
        DmaCopy16(3, gPortraitGenericGraphics[gCurrentPinballGame->portraitGfxIndex[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        index = gCurrentPinballGame->rouletteAreaIndex[arg1] * 0x10;
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

void UpdateNuzleafEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    s16 var0;
    s16 var1;

    group = &gMain.spriteGroups[71];
    var0 = 0;
    var1 = 0;
    switch (gCurrentPinballGame->nuzleafAnimState)
    {
    case 0:
        var0 = (gMain.systemFrameCount % 36) / 18;
        var1 = var0;
        break;
    case 1:
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 2;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 50000;
        break;
    case 2:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 7)
            {
                gCurrentPinballGame->nuzleafAnimState = 0;
                gCurrentPinballGame->nuzleafFrameIndex = 0;
                gCurrentPinballGame->nuzleafPositionIndex = 1;
            }
        }
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 3:
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 7;
        gCurrentPinballGame->nuzleafAnimState = 4;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 100000;
        break;
    case 4:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 18)
            {
                gCurrentPinballGame->nuzleafAnimState = 5;
                m4aSongNumStart(SE_UNKNOWN_0xD1);
            }
        }

        if (gCurrentPinballGame->nuzleafFrameTimer == 6)
            m4aSongNumStart(SE_UNKNOWN_0xD0);

        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 5:
    case 6:
        if (gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][1] > gCurrentPinballGame->nuzleafFrameTimer)
        {
            gCurrentPinballGame->nuzleafFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->nuzleafFrameTimer = 0;
            gCurrentPinballGame->nuzleafFrameIndex++;
            if (gCurrentPinballGame->nuzleafFrameIndex == 24)
                gCurrentPinballGame->nuzleafFrameIndex = 18;
        }

        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    case 7:
        gCurrentPinballGame->nuzleafHitFlag = 0;
        gCurrentPinballGame->nuzleafPositionIndex = 0;
        gCurrentPinballGame->nuzleafFrameTimer = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 0;
        gCurrentPinballGame->nuzleafFrameIndex = 24;
        var1 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][0];
        var0 = gNuzleafAnimFrameData[gCurrentPinballGame->nuzleafFrameIndex][2];
        break;
    }

    if (group->available)
    {
        group->baseX = gNuzleafPositions[gCurrentPinballGame->nuzleafPositionIndex][0] - gCurrentPinballGame->cameraXOffset;
        group->baseY = gNuzleafPositions[gCurrentPinballGame->nuzleafPositionIndex][1] - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gRubyStageNuzleaf_Gfx[gCurrentPinballGame->nuzleafGfxTileIndex], (void *)0x06014380, 0x260);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gNuzleafOamData[var1][i * 3 + 0];
            *dst++ = gNuzleafOamData[var1][i * 3 + 1];
            *dst++ = gNuzleafOamData[var1][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gCurrentPinballGame->nuzleafGfxTileIndex = var0;
}

void SelectShopDoorState(void)
{
    if (gCurrentPinballGame->ballCatchState != 3)
    {
        if (gCurrentPinballGame->boardState < 3)
        {
            if (gCurrentPinballGame->evolutionShopActive == 0)
                gCurrentPinballGame->shopDoorTargetFrame = gCurrentPinballGame->shopDoorOpenLevel & 0xF;
            else
                gCurrentPinballGame->shopDoorTargetFrame = 3;
        }
        else if (gCurrentPinballGame->boardState != 6)
        {
            gCurrentPinballGame->shopDoorTargetFrame = 0;
        }
    }
}

void AnimateShopDoor(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;

    group = &gMain.spriteGroups[65];
    if ((gCurrentPinballGame->shopDoorTargetFrame & 0xF) != gCurrentPinballGame->shopDoorCurrentFrame)
    {
        if (gCurrentPinballGame->shopDoorAnimDelay)
        {
            if (gCurrentPinballGame->shopDoorAnimDelay == 5)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 3;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 0;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                m4aSongNumStart(SE_UNKNOWN_0xBD);
            }

            gCurrentPinballGame->shopDoorAnimDelay--;
        }
        else
        {
            if (gCurrentPinballGame->shopDoorCurrentFrame > (gCurrentPinballGame->shopDoorTargetFrame & 0xF))
            {
                gCurrentPinballGame->shopDoorCurrentFrame--;
                gCurrentPinballGame->shopDoorAnimDelay = 4;
            }
            else
            {
                gCurrentPinballGame->shopDoorCurrentFrame++;
                gCurrentPinballGame->shopDoorAnimDelay = 4;
            }

            DmaCopy16(3, gRubyBoardShopDoor_Gfx[gCurrentPinballGame->shopDoorCurrentFrame], (void *)0x06013180, 0x180);
        }
    }

    if (gCurrentPinballGame->shopDoorCurrentFrame < 3)
        priority = 3;
    else
        priority = 2;

    group->baseX = 208 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 80 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &gMain.spriteGroups[65].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void DrawWhiscash(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    const s16 *var1;

    group = &gMain.spriteGroups[63];
    var1 = gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx];
    if (group->available)
    {
        var0 = var1[0];
        DmaCopy16(3, gWhiscashPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06014680, 0x460);
        gCurrentPinballGame->rubyBumperCollisionPosition[0].x = -248;
        gCurrentPinballGame->rubyBumperCollisionPosition[0].y = -316;
        group->baseX = var1[2] + 124u - gCurrentPinballGame->cameraXOffset;
        group->baseY = var1[3] + 150u - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (var0 == 4 || var0 == 10)
            gCurrentPinballGame->whiscashInvulnerable = 0;
        else
            gCurrentPinballGame->whiscashInvulnerable = 1;
    }
}

//Ruby Pond
void RubyPond_EntityLogic(void)
{
    s16 i;
    u16 angle;
    u16 angle2;
    s16 var1;
    s16 frameDecidedNextPondState;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    int squaredMagnitude;

    if (gCurrentPinballGame->shouldProcessWhiscash)
    {
        // If board is currently in one of the modes (catch/etc) force reset to the 3 chinchou
        if (gCurrentPinballGame->boardState > 2)
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;

        // Don't immediately force change state if Wishcash is actively doing something
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->whiscashState < WHISCASH_STATE_ABSORB_ZONE_HIT)
            {
                gCurrentPinballGame->whiscashState = WHISCASH_STATE_LEAVING;
                gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_LEAVING-1;
                gCurrentPinballGame->whiscashStateTimer = 0;
            }

            gCurrentPinballGame->rubyPondContentsChanging = FALSE;
        }

        switch (gCurrentPinballGame->whiscashState)
        {
        case WHISCASH_STATE_ARRIVAL:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SITTING)
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_SITTING;

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPLASH)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);
            }
            break;
        case WHISCASH_STATE_SITTING:
            // Alternates between frame 4 and 5
            gCurrentPinballGame->whiscashFrameIx = (gCurrentPinballGame->whiscashStateTimer % 44) / 22 + 4;
            gCurrentPinballGame->whiscashStateTimer++;
            break;
        case WHISCASH_STATE_ABSORB_ZONE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_ABSORB_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ABSORBING;
            gCurrentPinballGame->ball->oamPriority = 0;
            gCurrentPinballGame->scoreAddedInFrame = 5000;
            m4aSongNumStart(SE_WHISCASH_CATCH_BALL);
            PlayRumble(7);
            break;
        case WHISCASH_STATE_ABSORBING:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_BALL_HELD_SUNK;
                    gCurrentPinballGame->whiscashStateTimer = 65;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_TO_SPHEAL_BOARD;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START)
            {
                gCurrentPinballGame->ball->spinAngle += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8900;
                gCurrentPinballGame->ball->positionQ8.y = 0xBD00;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+1)
            {
                gCurrentPinballGame->ball->spinAngle += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8C00;
                gCurrentPinballGame->ball->positionQ8.y = 0xB700;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+2)
                gCurrentPinballGame->ball->ballHidden = 1;
            break;
        case WHISCASH_STATE_TO_SPHEAL_BOARD:
            gCurrentPinballGame->startButtonDisabled = 1;
            if (gCurrentPinballGame->whiscashStateTimer == 65)
            {
                m4aSongNumStart(SE_WARP);
                gMain.blendControl = 0x9E;
            }

            if (gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer--;
                gMain.blendBrightness = 16 - gCurrentPinballGame->whiscashStateTimer / 4;
                if (gCurrentPinballGame->whiscashStateTimer == 0)
                {
                    gCurrentPinballGame->nextBonusField = FIELD_SPHEAL;
                    gCurrentPinballGame->bonusReturnState = 1;
                    gCurrentPinballGame->arrowProgressPreserved = gCurrentPinballGame->evoArrowProgress;
                    gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->catchArrowProgress;
                    TransitionToBonusField();
                }
            }
            break;
        case WHISCASH_STATE_INIT_RETURN_FROM_BONUS: //from board initialization
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_DELIVER_BALL_START;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_RISE_SPIT_LEAVE;
            gCurrentPinballGame->ball->oamPriority = 0;
            break;
        case WHISCASH_STATE_RISE_SPIT_LEAVE:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_DELIVER_BALL_END+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 1)
                {
                    gCurrentPinballGame->ball->spinAngle -= 64;
                    gCurrentPinballGame->ball->positionQ8.x = 0x8300;
                    gCurrentPinballGame->ball->positionQ8.y = 0xC700;
                    gCurrentPinballGame->ball->velocity.x = -120;
                    gCurrentPinballGame->ball->velocity.y = 210;
                    gCurrentPinballGame->ball->oamPriority = 3;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_EMERGING)
                    m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL + 7) {
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
                }
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
                {
                    m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
                }
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL)
            {
                gCurrentPinballGame->ball->ballHidden = 0;
                gCurrentPinballGame->ball->spinAngle -= 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8500;
                gCurrentPinballGame->ball->positionQ8.y = 0xC000;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL+2)
                gCurrentPinballGame->ballFrozenState = 0;
            break;
        case WHISCASH_STATE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_HIT;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ANGRY;
            gCurrentPinballGame->scoreAddedInFrame = 10;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->saverTimeRemaining)
                gCurrentPinballGame->saverTimeRemaining = 1;
            break;
        case WHISCASH_STATE_ANGRY:
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING_AFTER_HIT)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_HIT+2)
                    m4aSongNumStart(SE_WHISCASH_EARTHQUAKE);
            }

            // Heavy shaking starts
            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_GONE_AFTER_HIT)
            {
                gCurrentPinballGame->screenShakeX = gWhiscashShakeOffsets[gCurrentPinballGame->whiscashStateTimer % 8];
                if (gCurrentPinballGame->whiscashStateTimer % 4 == 0)
                    MPlayStart(&gMPlayInfo_SE3, &se_whiscash_splashdown);

                if (gCurrentPinballGame->whiscashStateTimer % 10 == 0)
                    PlayRumble(12);
            }
            break;
        case WHISCASH_STATE_LEAVING: //Early Exit (mode started)
            if (gWhiscashFramesetData[gCurrentPinballGame->whiscashFrameIx][1] > gCurrentPinballGame->whiscashStateTimer)
            {
                gCurrentPinballGame->whiscashStateTimer++;
            }
            else
            {
                gCurrentPinballGame->whiscashStateTimer = 0;
                gCurrentPinballGame->whiscashFrameIx++;
                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_BALL_HELD_SUNK+1)
                {
                    gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                    gCurrentPinballGame->whiscashState = WHISCASH_STATE_CLEANUP;
                }

                if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_LEAVING)
                    m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);
            }
            break;
        case WHISCASH_STATE_CLEANUP:
            gCurrentPinballGame->shouldProcessWhiscash = FALSE;
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->rubyPondContentsChanging = TRUE;
            gCurrentPinballGame->rubyPondChangeTimer = 64;
            gCurrentPinballGame->screenShakeX = 0;
            break;
        }
    }
    else
    {
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 144)
            {
                gCurrentPinballGame->pondBumperStates[0] = gPondBumperTransitionFrames[gCurrentPinballGame->rubyPondChangeTimer / 8];
                gCurrentPinballGame->pondBumperStates[1] = gCurrentPinballGame->pondBumperStates[0];
                gCurrentPinballGame->pondBumperStates[2] = gCurrentPinballGame->pondBumperStates[0];
            }
            else
            {
                gCurrentPinballGame->rubyPondContentsChanging = FALSE;
            }

            if (gCurrentPinballGame->pondBumperStates[0] == 10)
            {
                if (gCurrentPinballGame->rubyPondChangeTimer % 8 == 0 && gCurrentPinballGame->rubyPondChangeTimer / 8 == 8)
                {
                    // Can't switch to Whiscash if in a catch/hatch/etc state, or if it hasn't yet hit a threshold
                    // of pond states first.
                    gCurrentPinballGame->pondSwitchesSinceLastWhiscash++;
                    if (gCurrentPinballGame->pondSwitchesSinceLastWhiscash < MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE ||
                        gCurrentPinballGame->boardState > 2)
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 5) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 5) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }
                    else
                    {
                        frameDecidedNextPondState = (gMain.systemFrameCount % 6) + 1;
                        if (gCurrentPinballGame->rubyPondState == frameDecidedNextPondState)
                            gCurrentPinballGame->rubyPondState = ((gMain.systemFrameCount + 1) % 6) + 1;
                        else
                            gCurrentPinballGame->rubyPondState = frameDecidedNextPondState;
                    }

                    if (gCurrentPinballGame->forcePondToWhiscash)
                    {
                        gCurrentPinballGame->forcePondToWhiscash = FALSE;
                        gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_WHISCASH;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_WHISCASH)
                    {
                        gCurrentPinballGame->shouldProcessWhiscash = TRUE;
                        gCurrentPinballGame->whiscashState = WHISCASH_STATE_ARRIVAL;
                        gCurrentPinballGame->whiscashStateTimer = 0;
                        gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_SUBMERGED;
                        gCurrentPinballGame->rubyPondContentsChanging = FALSE;
                        gCurrentPinballGame->pondSwitchesSinceLastWhiscash = 0;
                    }

                    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE)
                    {
                        gCurrentPinballGame->rubyBumperLogicPosition[0].x = gChinchouWaypointPositions[0].x * 10;
                        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gChinchouWaypointPositions[0].y * 10;
                    }
                }
            }

            gCurrentPinballGame->rubyPondChangeTimer++;
            if (gCurrentPinballGame->rubyPondChangeTimer == 32)
                m4aSongNumStart(SE_RUBY_BUMPER_LEAVES);

            switch (gCurrentPinballGame->rubyPondState)
            {
            case RUBY_POND_STATE_CHINCHOU_STAGGERED:
            case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
            case RUBY_POND_STATE_CHINCHOU_ROWS:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 116)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 130)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_LOTAD:
                if (gCurrentPinballGame->rubyPondChangeTimer == 102)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 118)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                if (gCurrentPinballGame->rubyPondChangeTimer == 134)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
                if (gCurrentPinballGame->rubyPondChangeTimer == 104)
                    m4aSongNumStart(SE_RUBY_BUMPER_EMERGES);
                break;
            }
        }
    }

    switch (gCurrentPinballGame->rubyPondState)
    {
    case RUBY_POND_STATE_CHINCHOU_STAGGERED:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1250;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = 1270;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = 1360;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = 1610;
        break;
    case RUBY_POND_STATE_CHINCHOU_CLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = (gCurrentPinballGame->globalAnimFrameCounter & 0x7F) * 0x200 + i * 0x5555;
            var1 = (gCurrentPinballGame->globalAnimFrameCounter % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->bumperOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->bumperOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->bumperOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = 10000 - ((gCurrentPinballGame->globalAnimFrameCounter & 0x7F) * 0x200 + i * 0x5555);
            var1 = (gCurrentPinballGame->globalAnimFrameCounter % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->bumperOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->bumperOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->bumperOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_ROWS:
        for (i = 0; i < 2; i++)
        {
            var1 = 23 - (gCurrentPinballGame->globalAnimFrameCounter % 46);
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].x = (i * 33 + 121) * 10;
            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].y = var1 * 5 + 1340;
        }

        var1 = 23 - (gCurrentPinballGame->globalAnimFrameCounter + 23) % 46;
        if (var1 < 0)
            var1 = 0-var1;

        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = var1 * 5 + 1620;
        break;
    case RUBY_POND_STATE_LOTAD:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1210;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gLotadBobOffsets[(gCurrentPinballGame->globalAnimFrameCounter % 60) / 10] + 1300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = gLotadBobOffsets[((gCurrentPinballGame->globalAnimFrameCounter + 20) % 60) / 10] + 1410;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = gLotadBobOffsets[((gCurrentPinballGame->globalAnimFrameCounter + 40) % 60) / 10] + 1660;
        break;
    case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
        tempVec.x = gChinchouWaypointPositions[gCurrentPinballGame->chinchouWaypointTarget].x * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].x;
        tempVec.y = gChinchouWaypointPositions[gCurrentPinballGame->chinchouWaypointTarget].y * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].y;
        squaredMagnitude = (tempVec.x * tempVec.x) + (tempVec.y * tempVec.y);
        angle2 = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle2) * 7) / 20000;
        tempVec2.y = (Sin(angle2) * -7) / 20000;
        gCurrentPinballGame->rubyBumperLogicPosition[0].x += tempVec2.x;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y += tempVec2.y;
        if (squaredMagnitude < 2500)
            gCurrentPinballGame->chinchouWaypointTarget = Random() % 4;

        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    case RUBY_POND_STATE_WHISCASH:
        // moved off screen
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = -300;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 0;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = -300;
        break;
    }
}

// Ruby pond bumpers Handle Hit and draw
void RubyPondTriBumperHandleHitAndDraw(void)
{
    s16 i;
    s16 j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->bumperHitCountdown > 0)
    {
        if (gCurrentPinballGame->bumperHitCountdown == 2)
        {
            gCurrentPinballGame->scoreAddedInFrame = 500;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->boardState == 4 && gCurrentPinballGame->boardSubState == 5 && gCurrentPinballGame->hatchTilesBumperAcknowledged < 6)
            {
                if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 0)
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 1;
                else if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 1)
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 3;
                else
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 6;

                if (gCurrentPinballGame->hatchTilesBumperAcknowledged == 6)
                {
                    if (gCurrentPinballGame->hatchTilesBoardAcknowledged == 0)
                    {
                        if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 236;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 6;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[6], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[6], (void *)0x050003C0, 0x20);
                        }
                        else
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->bannerDelayTimer = 50;
                            gCurrentPinballGame->bannerDisplayTimer = 600;
                            gCurrentPinballGame->cameraYScrollTarget = 236;
                            gCurrentPinballGame->cameraYAdjust = 0;
                            gCurrentPinballGame->cameraYScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxIndex = 1;
                            gCurrentPinballGame->bannerActive = 1;
                            gCurrentPinballGame->bannerPreserveBallState = 0;
                            gCurrentPinballGame->bannerDisplayDuration = 80;
                            gCurrentPinballGame->bannerSlidePosition = -2500;
                            gCurrentPinballGame->bannerSlideTimer = 50;
                            gCurrentPinballGame->bannerSlideVelocity = 0;
                            DmaCopy16(3, gModeBannerTilemaps[1], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gModeBannerPalettes[1], (void *)0x050003C0, 0x20);
                        }

                        gMain.blendControl = 0xCE;
                    }
                }
            }

            gCurrentPinballGame->pondEntitySpriteFlag++;
            gCurrentPinballGame->bumperHitsSinceReset++;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    group = &gMain.spriteGroups[62];
    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperStates[i])
            {
                if (gCurrentPinballGame->pondBumperStates[i] > 100)
                {
                    gCurrentPinballGame->pondBumperStates[i]--;
                    if (gCurrentPinballGame->pondBumperStates[i] == 100)
                        gCurrentPinballGame->pondBumperStates[i] = 0;

                    var0 = 8;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperStates[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            }

            DmaCopy16(3, gLotadBumperTiles[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gLotadBumperPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
    }
    else // chinchou
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperStates[i])
            {
                if (gCurrentPinballGame->pondBumperStates[i] > 100)
                {
                    var0 = 9 - gCurrentPinballGame->pondBumperStates[i] / 105;
                    gCurrentPinballGame->pondBumperStates[i]--;
                    if (gCurrentPinballGame->pondBumperStates[i] == 100)
                        gCurrentPinballGame->pondBumperStates[i] = 0;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperStates[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->globalAnimFrameCounter % 50) / 25;
            }

            DmaCopy16(3, gRubyFlashingTiles_Secondary[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gChinchouBumperPalettes + gCurrentPinballGame->activePaletteIndex * 0x60, (void *)0x05000320, 0x20);
    }

    // Draw Bumpers: Lotad/chinchou
    for (i = 0; i < 3; i++)
    {
        group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset - 8;
        group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset - 4;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].x = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10) + 8) * 2;
        gCurrentPinballGame->rubyBumperCollisionPosition[i].y = (-(gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10) + 7) * 2;
        if (group->baseY < -40)
            group->baseY = -40;

        //sprites have a left/right half.
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j + i * 2];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void AnimateSharpedoEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 * dst;
    const u16 * src;
    s16 index;
    s16 var0;

    index = (gMain.systemFrameCount % 55) / 11;
    group = &gMain.spriteGroups[61];
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->catchHoleTileVariant], (void *)0x06012C20, 0x260);
    if (gCurrentPinballGame->catchHoleAnimFrame)
        index = gCurrentPinballGame->catchHoleAnimFrame;

    var0 = gSharpedoAnimFrameData[index][0];
    gCurrentPinballGame->catchHoleTileVariant = gSharpedoAnimFrameData[index][1];
    group->baseX = 179 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 174 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gSharpedoSpritesheetOam[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void UpdatePikachuChargeCounter(void)
{
    if (gCurrentPinballGame->pikaChargeTarget != gCurrentPinballGame->pikaChargeProgress)
    {
        gCurrentPinballGame->pikaChargeProgress += 2;
        gCurrentPinballGame->chargeFillValue = gCurrentPinballGame->pikaChargeProgress / 14;
        gCurrentPinballGame->fullChargeSlideAnimTimer = 80;
        gCurrentPinballGame->chargeIndicatorScaleX = 256;
        gCurrentPinballGame->chargeIndicatorScaleY = 256;
        if (gCurrentPinballGame->chargeFillValue == 11)
            gCurrentPinballGame->chargeFillAnimTimer = 120;

        if (gCurrentPinballGame->chargeFillValue > 11)
        {
            gCurrentPinballGame->chargeFillValue = 12;
            gCurrentPinballGame->fullChargeSlideAnimTimer = 120;
            gCurrentPinballGame->chargeIndicatorScaleX = 256;
            gCurrentPinballGame->chargeIndicatorScaleY = 256;
        }

        if (gCurrentPinballGame->pikaChargeProgress < 168 && gCurrentPinballGame->pikaChargeProgress % 8 == 0)
        {
            s8 offset = gCurrentPinballGame->pikaChargeProgress / 21;
            m4aSongNumStart(SE_PIKA_CHARGE_DO + offset);
        }

        if (gCurrentPinballGame->pikaChargeTarget <= gCurrentPinballGame->pikaChargeProgress)
        {
            gCurrentPinballGame->pikaChargeProgress = gCurrentPinballGame->pikaChargeTarget;
            if (gCurrentPinballGame->pikaChargeProgress >= 168)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_pika_full_charge_1_up);
                gCurrentPinballGame->scoreAddedInFrame = 3000;
            }
        }
    }

    if (gCurrentPinballGame->pikaSpinCooldownTimer)
        gCurrentPinballGame->pikaSpinCooldownTimer--;

    if (gCurrentPinballGame->pikaSpinMomentum > 0)
    {
        gCurrentPinballGame->pikaSpinMomentum -= 3;
        if (gCurrentPinballGame->pikaSpinMomentum < 0)
            gCurrentPinballGame->pikaSpinMomentum = 0;

        if (gCurrentPinballGame->pikaSpinFrameCounter < gCurrentPinballGame->pikaSpinPeriod - 1)
        {
            gCurrentPinballGame->pikaSpinFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->pikaSpinFrameCounter = 0;
            MPlayStart(&gMPlayInfo_SE3, &se_pika_spinner_clack);
            gCurrentPinballGame->scoreAddedInFrame = 100;
            if (gCurrentPinballGame->chargeFillValue < 12 && gCurrentPinballGame->kickbackFiring == 0)
            {
                gCurrentPinballGame->fullChargeSlideAnimTimer = 80;
                gCurrentPinballGame->chargeIndicatorScaleX = 256;
                gCurrentPinballGame->chargeIndicatorScaleY = 256;
            }
        }

        gCurrentPinballGame->pikaSpinPeriod = (450 - gCurrentPinballGame->pikaSpinMomentum) / 10;
        if (gCurrentPinballGame->pikaSpinPeriod < 5)
            gCurrentPinballGame->pikaSpinPeriod = 5;

        gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / gCurrentPinballGame->pikaSpinPeriod;
    }
    else
    {
        if (gCurrentPinballGame->pikaSpinMomentum < 0)
        {
            gCurrentPinballGame->pikaSpinMomentum += 3;
            if (gCurrentPinballGame->pikaSpinMomentum > 0)
                gCurrentPinballGame->pikaSpinMomentum = 0;

            if (gCurrentPinballGame->pikaSpinFrameCounter < gCurrentPinballGame->pikaSpinPeriod - 1)
            {
                gCurrentPinballGame->pikaSpinFrameCounter++;
            }
            else
            {
                gCurrentPinballGame->pikaSpinFrameCounter = 0;
                MPlayStart(&gMPlayInfo_SE3, &se_pika_spinner_clack);
                gCurrentPinballGame->scoreAddedInFrame = 100;
                if (gCurrentPinballGame->chargeFillValue < 12 && gCurrentPinballGame->kickbackFiring == 0)
                {
                    gCurrentPinballGame->fullChargeSlideAnimTimer = 80;
                    gCurrentPinballGame->chargeIndicatorScaleX = 256;
                    gCurrentPinballGame->chargeIndicatorScaleY = 256;
                }
            }

            gCurrentPinballGame->pikaSpinPeriod = (450 + gCurrentPinballGame->pikaSpinMomentum) / 10;
            if (gCurrentPinballGame->pikaSpinPeriod < 5)
                gCurrentPinballGame->pikaSpinPeriod = 5;

            gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / gCurrentPinballGame->pikaSpinPeriod;
        }
        else
        {
            if (gCurrentPinballGame->pikachuSpinFrame > 0)
            {
                gCurrentPinballGame->pikaSpinFrameCounter++;
                gCurrentPinballGame->pikaSpinFrameCounter %= 40;
                gCurrentPinballGame->pikachuSpinFrame = (gCurrentPinballGame->pikaSpinFrameCounter * 16) / 40;
            }
        }
    }
}

void DrawPikachuSpinner(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    index = gCurrentPinballGame->pikachuSpinFrame;
    group = gMain.fieldSpriteGroups[31];
    group->baseX = 206 - gCurrentPinballGame->cameraXOffset;
    if (gMain.selectedField == FIELD_RUBY)
        group->baseY = 174 - gCurrentPinballGame->cameraYOffset;
    else
        group->baseY = 154 - gCurrentPinballGame->cameraYOffset;

    if (gCurrentPinballGame->pikachuSpinFrame != gCurrentPinballGame->pikachuSpinPrevFrame)
    {
        gCurrentPinballGame->pikachuSpinPrevFrame = gCurrentPinballGame->pikachuSpinFrame;
        DmaCopy16(3, gMainBoardPikaSpinner_Gfx[index], (void *)0x06010780, 0x120);
    }

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateChikoritaAttackAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 var0;

    index = 0;
    group = &gMain.spriteGroups[14];
    if (gCurrentPinballGame->chikoritaProjectileTimer < 60)
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer >= 27 && gCurrentPinballGame->chikoritaProjectileTimer < 47)
        {
            index = (gCurrentPinballGame->chikoritaProjectileTimer - 27) / 5;
            DmaCopy16(3, gChikoritaExplosionTiles[index], (void *)0x06014280, 0x100);
            group->baseX = 176 - gCurrentPinballGame->cameraXOffset;
        }
        else
        {
            group->available = 0;
            group->baseX = 176 - gCurrentPinballGame->cameraXOffset;
        }
    }
    else
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer >= 100 && gCurrentPinballGame->chikoritaProjectileTimer < 120)
        {
            index = (gCurrentPinballGame->chikoritaProjectileTimer - 100) / 5;
            DmaCopy16(3, gChikoritaExplosionTiles[index], (void *)0x06014280, 0x100);
            group->baseX = 32 - gCurrentPinballGame->cameraXOffset;
        }
        else
        {
            group->available = 0;
            group->baseX = 32 - gCurrentPinballGame->cameraXOffset;
        }

    }

    if (group->available)
    {
        group->baseY = 296 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;

        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[13];
    if (group->available)
    {
        if (gCurrentPinballGame->chikoritaProjectileTimer < 120)
        {
            if (gCurrentPinballGame->chikoritaProjectileTimer % 8 == 0)
                m4aSongNumStart(SE_UNKNOWN_0xC6);

            index = (gCurrentPinballGame->chikoritaProjectileTimer % 16) / 4;
            DmaCopy16(3, gChikoritaProjectileTiles[index], (void *)0x06014200, 0x80);
            var0 = (gCurrentPinballGame->chikoritaProjectileTimer << 0x10) / 90;
            gCurrentPinballGame->chikoritaProjectileVelX -= 2;
            gCurrentPinballGame->chikoritaProjectileX += gCurrentPinballGame->chikoritaProjectileVelX;
            if (gCurrentPinballGame->chikoritaProjectileTimer < 30)
                gCurrentPinballGame->chikoritaProjectileY = gCurrentPinballGame->chikoritaProjectileTimer + (Sin(var0) * 24) / 20000;
            else
                gCurrentPinballGame->chikoritaProjectileY = 30 + (Sin(var0) * 24) / 20000;

            gCurrentPinballGame->chikoritaProjectileTimer++;
            if (gCurrentPinballGame->chikoritaProjectileTimer == 27)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->sideBumperBounceCount[1] > 0)
                {
                    gCurrentPinballGame->sideBumperBounceCount[1]++;
                }
                else
                {
                    gCurrentPinballGame->sideBumperBounceCount[1] = 2;
                    gCurrentPinballGame->sideBumperAnimTimer[1] = 190;
                }
            }

            if (gCurrentPinballGame->chikoritaProjectileTimer == 100)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->sideBumperBounceCount[0] > 0)
                {
                    gCurrentPinballGame->sideBumperBounceCount[0]++;
                }
                else
                {
                    gCurrentPinballGame->sideBumperBounceCount[0] = 2;
                    gCurrentPinballGame->sideBumperAnimTimer[0] = 190;
                }
            }
        }
        else
        {
            gCurrentPinballGame->chikoritaProjectileTimer = 0;
            gCurrentPinballGame->chikoritaProjectileX = 0;
            gCurrentPinballGame->chikoritaProjectileY = 190;
            gCurrentPinballGame->chikoritaProjectileVelX = 100;
            gCurrentPinballGame->chikoritaProjectileUnused = 0;
            group->available = 0;
        }

        group->baseX = (gCurrentPinballGame->chikoritaProjectileX / 20) + 71u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->chikoritaProjectileY + 248u - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 190)
            group->baseY = 190;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void AnimateChikoritaSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[53];
    if (gCurrentPinballGame->chikoritaFlashActive)
    {
        index = gChikoritaFlashFrameIndices[gCurrentPinballGame->chikoritaFlashTimer / 5];
        if (gCurrentPinballGame->chikoritaFlashTimer == 40)
        {
            gCurrentPinballGame->chikoritaProjectileTimer = 0;
            gCurrentPinballGame->chikoritaProjectileX = 0;
            gCurrentPinballGame->chikoritaProjectileY = 0;
            gCurrentPinballGame->chikoritaProjectileVelX = 100;
            gCurrentPinballGame->chikoritaProjectileUnused = 0;
            gMain.spriteGroups[13].available = 1;
        }

        if (gCurrentPinballGame->chikoritaFlashTimer < 54)
            gCurrentPinballGame->chikoritaFlashTimer++;
        else
            gCurrentPinballGame->chikoritaFlashActive = 0;

        DmaCopy16(3, gRubyFlashingDecorationTiles[index], (void *)0x06012720, 0x300);
    }
    else
    {
        index = (gMain.systemFrameCount % 50) / 25;
        if (gCurrentPinballGame->randomSpriteVariantSeed == 1)
        {
            DmaCopy16(3, gRubyFlashingDecorationTiles[index], (void *)0x06012720, 0x300);
        }
    }

    group->baseX = 55 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 221 - gCurrentPinballGame->cameraYOffset;
    i = 0;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateGulpinBossState(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const s16 *var0;
    s16 index;

    var0 = gGulpinAnimData[gCurrentPinballGame->gulpinAnimFrameIndex];
    group = &gMain.spriteGroups[57];
    group->baseX = 9 - gCurrentPinballGame->cameraXOffset;
    group->baseY = 288 - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->gulpinCurrentLevel > gCurrentPinballGame->seedotCount)
    {
        if (gCurrentPinballGame->seedotExitSequenceActive)
        {
            if (gCurrentPinballGame->seedotExitSequenceTimer == 0)
            {
                gCurrentPinballGame->gulpinAnimFrameIndex = 59;
                gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                gCurrentPinballGame->seedotExitSequenceTimer++;
            }

            if (var0[1] > gCurrentPinballGame->gulpinAnimFrameTimer)
            {
                gCurrentPinballGame->gulpinAnimFrameTimer++;
            }
            else
            {
                gCurrentPinballGame->gulpinAnimFrameTimer = 1;
                gCurrentPinballGame->gulpinAnimFrameIndex++;
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 84)
                {
                    gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                    gCurrentPinballGame->seedotExitSequenceActive = 0;
                    gCurrentPinballGame->seedotExitSequenceTimer = 0;
                    gCurrentPinballGame->gulpinCurrentLevel = 0;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 60 || gCurrentPinballGame->gulpinAnimFrameIndex == 69 || gCurrentPinballGame->gulpinAnimFrameIndex == 78)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
    }
    else if (gCurrentPinballGame->gulpinCurrentLevel < gCurrentPinballGame->seedotCount)
    {
        if (var0[1] <= gCurrentPinballGame->gulpinAnimFrameTimer)
        {
            gCurrentPinballGame->gulpinAnimFrameTimer = 1;
            gCurrentPinballGame->gulpinAnimFrameIndex++;
            if (gCurrentPinballGame->seedotCount == 1)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 9)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 1;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 84;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 6)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->seedotCount == 2)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 23)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 2;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 95;
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 20)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->seedotCount == 3)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 35)
                {
                    gCurrentPinballGame->gulpinCurrentLevel = 3;
                    gCurrentPinballGame->gulpinAnimFrameIndex = 35;
                    RequestBoardStateTransition(7);
                }

                if (gCurrentPinballGame->gulpinAnimFrameIndex == 32)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
        else
        {
            gCurrentPinballGame->gulpinAnimFrameTimer++;
        }
    }
    else if (gCurrentPinballGame->seedotCount)
    {
        if (var0[1] > gCurrentPinballGame->gulpinAnimFrameTimer)
        {
            gCurrentPinballGame->gulpinAnimFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->gulpinAnimFrameTimer = 1;
            gCurrentPinballGame->gulpinAnimFrameIndex++;
            if (gCurrentPinballGame->seedotCount == 1)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 95)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 84;
            }
            else if (gCurrentPinballGame->seedotCount == 2)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 109)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 95;
            }
            else if (gCurrentPinballGame->seedotCount == 3)
            {
                if (gCurrentPinballGame->gulpinAnimFrameIndex == 60)
                    gCurrentPinballGame->gulpinAnimFrameIndex = 35;
            }
        }
    }

    index = var0[0];
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[2]], (void *)0x06013B80, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[3]], (void *)0x06013A00, 0x180);
    DmaCopy16(3, gRubyStageGulpin_Gfx[var0[4]], (void *)0x06013880, 0x180);
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gGulpinOamData[index][i * 3 + 0];
        *dst++ = gGulpinOamData[index][i * 3 + 1];
        *dst++ = gGulpinOamData[index][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void UpdateSideBumperAnimation(void)
{
    s16 i;

    for (i = 0; i < 2; i++)
    {
        if (gCurrentPinballGame->sideBumperBounceCount[i] > 0)
        {
            if (gSideBumperAnimDurations[gCurrentPinballGame->sideBumperAnimPhase[i]][0] > gCurrentPinballGame->sideBumperAnimTimer[i])
            {
                gCurrentPinballGame->sideBumperAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->sideBumperAnimTimer[i] = 0;
                gCurrentPinballGame->sideBumperAnimPhase[i]++;
                if (gCurrentPinballGame->sideBumperAnimPhase[i] > 11)
                {
                    gCurrentPinballGame->sideBumperAnimPhase[i] = 0;
                    gCurrentPinballGame->sideBumperBounceCount[i]--;
                }
            }

            if (gCurrentPinballGame->sideBumperAnimPhase[i] == 1)
                gCurrentPinballGame->sideBumperShakeOffset[i] = gCurrentPinballGame->sideBumperAnimTimer[i] / 2;

            if (gCurrentPinballGame->sideBumperAnimPhase[i] == 11)
                gCurrentPinballGame->sideBumperShakeOffset[i] = 14 - gCurrentPinballGame->sideBumperAnimTimer[i] / 2;

            if (gCurrentPinballGame->sideBumperShakeOffset[i] < 3)
                gCurrentPinballGame->sideBumperShakeOffset[i] = 3;
        }
    }

    if (gCurrentPinballGame->sideBumperHitFlag)
    {
        if (gCurrentPinballGame->sideBumperHitFlag == 1)
        {
            if (gCurrentPinballGame->boardState != 7)
            {
                if (gCurrentPinballGame->boardState < 3) {
                    if (gCurrentPinballGame->seedotCount < 3)
                    {
                        gCurrentPinballGame->seedotCount++;
                        if (gCurrentPinballGame->seedotCount == 1)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 2)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 12;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 3)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 24;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                            gCurrentPinballGame->seedotModeStartDelay = 1;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->seedotCount < 2)
                    {
                        gCurrentPinballGame->seedotCount++;
                        if (gCurrentPinballGame->seedotCount == 1)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 0;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                        else if (gCurrentPinballGame->seedotCount == 2)
                        {
                            gCurrentPinballGame->gulpinAnimFrameIndex = 12;
                            gCurrentPinballGame->gulpinAnimFrameTimer = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (gCurrentPinballGame->rampGateState == 0)
                gCurrentPinballGame->rampGateState = 1;
            else
                gCurrentPinballGame->rampGateState = 0;
        }

        gCurrentPinballGame->sideBumperBounceCount[0] = 0;
        gCurrentPinballGame->sideBumperBounceCount[1] = 0;
        gCurrentPinballGame->sideBumperHitFlag = 0;
        PlayRumble(7);
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 3000;
        gCurrentPinballGame->sideBumperAnimPhase[0] = 0;
        gCurrentPinballGame->sideBumperAnimPhase[1] = 0;
        gCurrentPinballGame->sideBumperAnimTimer[0] = 0;
        gCurrentPinballGame->sideBumperAnimTimer[1] = 0;
        gCurrentPinballGame->sideBumperShakeOffset[0] = 3;
        gCurrentPinballGame->sideBumperShakeOffset[1] = 3;
    }
}

void DrawSideBumperSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    for (i = 0; i < 2; i++)
    {
        index = gSideBumperGfxFrameIndices[gCurrentPinballGame->sideBumperAnimPhase[i]][0];
        DmaCopy16(3, gSideBumperGfx[index], (void *)0x06012A20 + i * 0x100, 0x100);
        group = &gMain.spriteGroups[59 + i];
        if (group->available)
        {
            int var0 = i * 120 - (gCurrentPinballGame->cameraXOffset - 48);
            group->baseX = var0 + ((1 - (i * 2)) * (gCurrentPinballGame->sideBumperShakeOffset[i] - 14));
            group->baseY = 301 - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    if (gCurrentPinballGame->seedotModeStartDelay)
    {
        gCurrentPinballGame->seedotModeStartDelay--;
        if (gCurrentPinballGame->seedotModeStartDelay == 0)
        {
            if (gCurrentPinballGame->activePortraitType)
                gCurrentPinballGame->seedotModeStartDelay = 1;
            else
                gCurrentPinballGame->activePortraitType = 4;

            if (gCurrentPinballGame->seedotModeStartDelay == 0)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 70;
                gCurrentPinballGame->bannerDisplayTimer = 160;
                gCurrentPinballGame->cameraYScrollTarget = 0;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxIndex = 4;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->bannerDisplayDuration = 120;
                gCurrentPinballGame->bannerSlidePosition = 0;
                gCurrentPinballGame->bannerSlideTimer = 50;
                gCurrentPinballGame->bannerSlideVelocity = 0;
                DmaCopy16(3, gModeBannerTilemaps[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gModeBannerPalettes[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
}

void UpdateKickbackLogic(void)
{
    s16 outlaneChuteIx;
    s16 j;
    s16 r5;
    s16 oamIx;
    s16 tempY;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    PichuArrivalSequence();

    if (gCurrentPinballGame->pikaChargeTarget > 167)
    {
        gCurrentPinballGame->pikaSaverTileIndex[0] = gPikaSaverAnimFrameTable[(gMain.fieldFrameCount % 160) / 5];
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0] + 6;
        else
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0];
    }
    else
    {
        gCurrentPinballGame->pikaSaverTileIndex[0] = (gMain.fieldFrameCount % 50) / 25;
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0] + 9;
        else
            gCurrentPinballGame->pikaSaverTileIndex[1] = gCurrentPinballGame->pikaSaverTileIndex[0];
    }

    if (gCurrentPinballGame->outLanePikaPosition == 2)
    {
        gCurrentPinballGame->kickbackOccupied[0] = 1;
        gCurrentPinballGame->kickbackOccupied[1] = 1;
    }
    else
    {
        gCurrentPinballGame->kickbackOccupied[0 + gCurrentPinballGame->outLanePikaPosition] = 1;
        gCurrentPinballGame->kickbackOccupied[1 - gCurrentPinballGame->outLanePikaPosition] = 0;
    }

    if (gCurrentPinballGame->pikaKickbackTimer != 0)
    {
        if (gCurrentPinballGame->pikaKickbackTimer == 120)
        {
            // gCurrentPinballGame->outLaneSide + gCurrentPinballGame->outLanePikaPosition
            // Note: this can be && chained off of the previous if, once we have this line deciphered.
            if (gCurrentPinballGame->kickbackOccupied[gCurrentPinballGame->outLaneSide - 1] != 0)
            {
                if (gCurrentPinballGame->pikaChargeTarget > 167)
                {
                    gCurrentPinballGame->ballFrozenState = 1;
                    gCurrentPinballGame->kickbackFiring = 1;
                    gCurrentPinballGame->kickbackAnimProgress = 120;
                    gCurrentPinballGame->kickbackAnimDuration = 120;
                    gCurrentPinballGame->kickbackLaunchTimer = gCurrentPinballGame->kickbackAnimProgress;
                    gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
                    gCurrentPinballGame->kickbackAnimFrameTimer = 0;
                    gCurrentPinballGame->kickbackFrameId = 0;

                    if (gCurrentPinballGame->outLanePikaPosition != 2)
                    {
                        gCurrentPinballGame->pikaChargeTarget = 0;
                        gCurrentPinballGame->pikaChargeProgress = 0;
                        gCurrentPinballGame->prevChargeFillValue = 0;
                        gCurrentPinballGame->chargeFillValue = 0;
                        gCurrentPinballGame->chargeIndicatorXOffset = 0;
                        gCurrentPinballGame->chargeIndicatorYOffset = -4;
                        gCurrentPinballGame->chargeIndicatorScaleX = 256;
                        gCurrentPinballGame->chargeIndicatorScaleY = 256;
                        gCurrentPinballGame->chargeFillAnimTimer = 0;
                        gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                    }

                    gCurrentPinballGame->kickbackBallHoverPos = gCurrentPinballGame->ball->positionQ1;
                    gCurrentPinballGame->scoreAddedInFrame = 30000;

                    if (gCurrentPinballGame->bonusPikaSaverCount <= 98)
                        gCurrentPinballGame->bonusPikaSaverCount++;
                }
                else
                {
                    gCurrentPinballGame->pikaKickbackTimer = 60;
                    MPlayStart(&gMPlayInfo_SE1, &se_pika_no_kickback);
                }

                outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2)
                    gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = (outlaneChuteIx) * 7 + 2;
                else
                    gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = 2;

                DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + ((outlaneChuteIx) * 0x180), 0x180);
            }
        }

        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
        else
            gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

        gCurrentPinballGame->pikaKickbackTimer--;
    }

    if (gCurrentPinballGame->kickbackFiring != 0)
    {
        if (gCurrentPinballGame->kickbackLaunchTimer > 1)
        {
            r5 = (gCurrentPinballGame->kickbackAnimProgress * 0x10000) / 10;
            gCurrentPinballGame->kickbackLaunchTimer--;
            if (gCurrentPinballGame->kickbackAnimProgress != 0)
            {
                gCurrentPinballGame->kickbackAnimProgress--;
                if (gCurrentPinballGame->kickbackAnimProgress == 40 && gCurrentPinballGame->kickbackLaunchTimer > 40)
                {
                    gCurrentPinballGame->kickbackAnimProgress = 60;
                }
            }
            if (gCurrentPinballGame->kickbackLaunchTimer == 116)
            {
                if (gCurrentPinballGame->activePortraitType)
                    gCurrentPinballGame->kickbackLaunchTimer = 120;
                else
                {
                    gCurrentPinballGame->activePortraitType = 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                    {
                        if (gCurrentPinballGame->outLaneSide == 1)
                            MPlayStart(&gMPlayInfo_SE1, &se_pikachu_kickback);
                        else
                            MPlayStart(&gMPlayInfo_SE1, &se_pichu_kickback);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                    else
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_pikachu_kickback);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                }
            }
            if (gCurrentPinballGame->kickbackLaunchTimer == 115 && gCurrentPinballGame->activePortraitType == 1)
                m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, 0x200);

            // used for the horizontal 'floaty' movement when electric builds pre-launch.
            gCurrentPinballGame->ball->positionQ1.x =
                gCurrentPinballGame->kickbackBallHoverPos.x + ((Sin(r5) * 6) / 20000) +
                ((gOutlaneCenterXPositions[gCurrentPinballGame->outLaneSide - 1] * 2 - gCurrentPinballGame->kickbackBallHoverPos.x) * (gCurrentPinballGame->kickbackAnimDuration - gCurrentPinballGame->kickbackAnimProgress)) / gCurrentPinballGame->kickbackAnimDuration;

            tempY = ((gCurrentPinballGame->kickbackAnimDuration - gCurrentPinballGame->kickbackAnimProgress) * 40) / gCurrentPinballGame->kickbackAnimDuration;
            gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->kickbackBallHoverPos.y - tempY;

            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
        }
        else if (gCurrentPinballGame->kickbackLaunchTimer == 1)
        {
            gCurrentPinballGame->ball->positionQ1.x = gOutlaneCenterXPositions[gCurrentPinballGame->outLaneSide - 1] * 2;
            gCurrentPinballGame->ball->positionQ1.y = 702;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
            gCurrentPinballGame->ball->velocity.x = 0;
            // fly me to the moon
            gCurrentPinballGame->ball->velocity.y = -300;
            m4aSongNumStart(SE_KICKBACK_THUNDERWAVE);
            gCurrentPinballGame->kickbackLaunchTimer = 0;
            gCurrentPinballGame->ballFrozenState = 0;
            gCurrentPinballGame->ballUpgradeTimerFrozen = 0;
            gCurrentPinballGame->holeIndicators[(gCurrentPinballGame->outLaneSide - 1) * 3] = 1;

            if (gCurrentPinballGame->allHolesLit == 0 &&
                (gCurrentPinballGame->holeIndicators[0] &
                 gCurrentPinballGame->holeIndicators[1] &
                 gCurrentPinballGame->holeIndicators[2] &
                 gCurrentPinballGame->holeIndicators[3]))
            {
                gCurrentPinballGame->allHolesLit = 1;
                gCurrentPinballGame->allHolesLitBlinkTimer = 126;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
            }

            PlayRumble(11);
        }

        if (gCurrentPinballGame->kickbackLaunchTimer >= 100)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
            else
                gCurrentPinballGame->pikaSaverTileIndex[gCurrentPinballGame->outLaneSide - 1] = 2;

            if (gCurrentPinballGame->kickbackLaunchTimer == 100)
            {
                gMain.fieldSpriteGroups[38]->available = 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
                {
                    DmaCopy16(3, gPikaSaverFullCoverageGfx, 0x06015800, 0x2400);
                }
                else
                {
                    DmaCopy16(3, gPikaSaverPartialCoverageGfx, 0x06015800, 0x2400);
                }
            }
        }
        else
        {
            if (gCatchOverlayAnimData[gCurrentPinballGame->kickbackFrameId][1] > gCurrentPinballGame->kickbackAnimFrameTimer)
                gCurrentPinballGame->kickbackAnimFrameTimer++;
            else
            {
                gCurrentPinballGame->kickbackAnimFrameTimer = 0;
                gCurrentPinballGame->kickbackFrameId++;

                if (gCurrentPinballGame->kickbackFrameId == 23)
                {
                    m4aSongNumStop(SE_KICKBACK_THUNDERWAVE);
                    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
                }

                if (gCurrentPinballGame->kickbackFrameId > 25)
                {
                    gCurrentPinballGame->kickbackFrameId = 25;
                    gCurrentPinballGame->kickbackFiring = 0;
                    gMain.fieldSpriteGroups[38]->available = 0;
                    gCurrentPinballGame->activePortraitType = 0;

                    outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                        gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = outlaneChuteIx * 9;
                    else
                        gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] = 0;

                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + (outlaneChuteIx * 0x180), 0x180);
                }
            }

            if (gCurrentPinballGame->kickbackFrameId >= 17 && gCurrentPinballGame->kickbackFrameId <= 23)
            {
                if ((gMain.systemFrameCount & 3) >> 1)
                    gCurrentPinballGame->cameraBaseX = -3;
                else
                    gCurrentPinballGame->cameraBaseX = 3;
            }

            oamIx = gCatchOverlayAnimData[gCurrentPinballGame->kickbackFrameId][0];
            outlaneChuteIx = gCurrentPinballGame->outLaneSide - 1;

            spriteGroup = gMain.fieldSpriteGroups[38];
            spriteGroup->baseX = (outlaneChuteIx * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->kickbackFiring)
            {
                spriteGroup->baseY = 380 - gCurrentPinballGame->cameraYOffset;
                gCurrentPinballGame->kickbackOccupied[outlaneChuteIx] = 0;
            }
            else
            {
                spriteGroup->baseY = 180;
                gCurrentPinballGame->kickbackOccupied[outlaneChuteIx] = 1;
            }

            for (j = 0; j < 4; j++)
            {
                oamSimple = &spriteGroup->oam[j];
                dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 0];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 1];
                *dst++ = gCatchOverlayOamData[oamIx][j * 3 + 2];

                gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            }
        }
    }
    spriteGroup = gMain.fieldSpriteGroups[29];

    if (spriteGroup->available)
    {
        for (outlaneChuteIx = 0; outlaneChuteIx <= 1; outlaneChuteIx++)
        {
            spriteGroup = gMain.fieldSpriteGroups[29 + outlaneChuteIx];
            spriteGroup->baseX = (outlaneChuteIx * 177) - (gCurrentPinballGame->cameraXOffset - 16);
            if (gCurrentPinballGame->kickbackOccupied[outlaneChuteIx])
            {
                if ((gMain.fieldFrameCount % 5) == 0)
                {
                    DmaCopy16(3, gPikaSaverTilesGfx + (gCurrentPinballGame->pikaSaverTileIndex[outlaneChuteIx] * 0x180), 0x06010480 + (outlaneChuteIx * 0x180), 0x180);
                }

                tempY = 380 - gCurrentPinballGame->cameraYOffset;
                spriteGroup->baseY = tempY;
            }
            else
                spriteGroup->baseY = 200;

            for (j = 0; j <= 1; j++)
            {
                oamSimple = &spriteGroup->oam[j];

                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
            }
        }
    }
}
