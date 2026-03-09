#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const u8 gUnknown_0847FD0C[][0x100];
extern const s16 gUnknown_086ADEB0[][2];
extern const u16 gUnknown_086ADEB2[][2];
extern const s16 gUnknown_086ADA6E[][5];
extern const u16 gUnknown_086B2FC0[146][18];
extern const u8 gRubyStageGulpin_Gfx[][0x180];
extern const s16 gUnknown_086ADA58[];
extern const u8 gUnknown_083C3C2C[][0x300];
extern const u8 gUnknown_083C562C[][0x100];
extern const u8 gUnknown_083C542C[][0x80];
extern const u8 gRubyBoardSharpedo_Gfx[][0x260];
extern const s16 gUnknown_086AD9FC[][2];
extern const u16 gSharpedoSpritesheetOam[42][3][3];
extern const u8 gUnknown_083C806C[][0x100];
extern const u8 gUnknown_0844928C[][0x100];
extern const u8 gUnknown_08137998[];
extern const u8 gUnknown_081379B8[];
extern const s16 gUnknown_08137968[];
extern const struct Vector16 gUnknown_086AD9DC[];
extern const s16 gWhiscashFramesetData[][4];
extern const s16 gUnknown_086AD9EC[];
extern const s16 gUnknown_0813798C[];
extern const u8 gUnknown_081379D8[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gRubyBoardShopDoor_Gfx[][0x180];
extern const s16 gUnknown_086AD7C0[50][3];
extern const s16 gUnknown_086AD856[][2];
extern const u8 gRubyStageNuzleaf_Gfx[][0x280];
extern const u16 gUnknown_086B2E64[58][6];
extern const u16 gUnknown_081C00E4[];
extern const u16 gUnknown_086AD798[2];
extern const u16 gUnknown_086AD070[];
extern const u16 gUnknown_081C02E4[];
extern const s16 gUnknown_086AD79C[];

extern struct SongHeader se_unk_7a;
extern struct SongHeader se_unk_79;
extern struct SongHeader se_whiscash_splashdown;
extern struct SongHeader se_unk_142;
extern struct SongHeader se_unk_b1;
extern struct SongHeader se_unk_b3;
extern s16 gUnknown_086ADF48[100];
extern s16 gUnknown_086ADF8A[3];
extern u16 gUnknown_086ADEE0[][2];
extern s16 gUnknown_086B4922[28][12];

#define MIN_POND_SWITCHES_BEFORE_WHISCASH_AVAILABLE 3


void SetBoardPortraitGraphics(s16 arg0, s16 arg1)
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
        gCurrentPinballGame->spriteLayerPriority = 3;
        gCurrentPinballGame->portraitSpeciesId[arg1] = gCurrentPinballGame->portraitAreaLookupIds[arg1];
        DmaCopy16(3, gUnknown_0848D68C[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        index = gCurrentPinballGame->portraitAreaLookupIds[arg1] * 0x10;
        DmaCopy16(3, &gUnknown_081C00E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 1:
        ptr = gUnknown_086AD070;
        gCurrentPinballGame->portraitSpeciesId[arg1] = ptr[(gCurrentPinballGame->portraitAnimCounter % 48) / 24];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 2:
        ptr = gUnknown_086AD000[gCurrentPinballGame->slotReelResultPair[arg1]];
        gCurrentPinballGame->portraitSpeciesId[arg1] = ptr[0];
        index = ptr[2] * 0x10;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 3:
        gCurrentPinballGame->portraitSpeciesId[arg1] = gCurrentPinballGame->currentSpecies;
        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 24,
            0x300);
        DmaCopy16(
            3,
            gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x20,
            (void *)0x050003A0 ,
            0x20);
        DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003E0, 0x20);
        break;
    case 9:
        if (gCurrentPinballGame->evoStageSelection > 0)
        {
            if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] == SPECIES_UNSEEN)
            {
                gCurrentPinballGame->portraitSpeciesId[arg1] = SPECIES_NONE;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
            else if (gMain_saveData.pokedexFlags[gCurrentPinballGame->evoTargetSpecies] < SPECIES_CAUGHT)
            {
                gCurrentPinballGame->portraitSpeciesId[arg1] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(3, gMonPortraitGroupPals[0] + 15 * 0x20, (void *)0x050003A0, 0x20);
            }
            else
            {
                gCurrentPinballGame->portraitSpeciesId[arg1] = gCurrentPinballGame->evoTargetSpecies;
                DmaCopy16(
                    3,
                    gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x20,
                    (void *)0x050003A0,
                    0x20);
            }
        }
        else
        {
            gCurrentPinballGame->portraitSpeciesId[arg1] = gCurrentPinballGame->currentSpecies;
            DmaCopy16(
                3,
                gMonPortraitGroupPals[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x20,
                (void *)0x050003A0,
                0x20);
        }

        DmaCopy16(
            3,
            gMonPortraitGroupGfx[gCurrentPinballGame->portraitSpeciesId[arg1] / 15] + (gCurrentPinballGame->portraitSpeciesId[arg1] % 15) * 0x300,
            (void *)0x06010CA0 + arg1 * 0x18,
            0x300);
        break;
    case 4:
        if (gCurrentPinballGame->boardSubState == 2)
        {
            gCurrentPinballGame->portraitSpeciesId[arg1] = gUnknown_086AD000[15][(gCurrentPinballGame->portraitAnimCounter % 48) / 24];
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);

            // !!!!! BUG: this should be multiplied by 16 !!
            index = gUnknown_086AD000[15][2];
        }
        else
        {
            gCurrentPinballGame->portraitSpeciesId[arg1] = gUnknown_086AD000[16][(gCurrentPinballGame->portraitAnimCounter % 48) / 24];
            DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
            index = gUnknown_086AD000[16][2] * 16;
        }
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 6:
        ptr = gUnknown_086AD000[gCurrentPinballGame->upgradeMenuItemId];
        gCurrentPinballGame->portraitSpeciesId[arg1] = ptr[0];
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        if (gCurrentPinballGame->coins < ptr[3] ||
            (
                (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 3 && gCurrentPinballGame->outLanePikaPosition == 2)
                ||
                (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 4 && gCurrentPinballGame->bonusStagePurchased)
            ))
        {
            DmaCopy16(3, &gUnknown_081C02E4[index], sp0, 0x20);
            for (i = 0; i < 16; i++)
            {
                rgb[0] = ((sp0[i] & 0x1F) * 2) / 3;
                rgb[1] = ((sp0[i] & 0x3E0) >> 4) / 3;
                rgb[2] = ((sp0[i] & 0x7C00) >> 9) / 3;
                sp0[i] = rgb[0] | (rgb[1] << 5) | (rgb[2] << 10);
            }

            DmaCopy16(3, sp0, (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        }
        else
        {
            DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        }
        break;
    case 7:
        // TODO: fake match
        ptr2 = ptr = gUnknown_086AD000[gCurrentPinballGame->slotReelResultPair[arg1]];
        gCurrentPinballGame->portraitSpeciesId[arg1] = *(ptr2 += (gCurrentPinballGame->portraitAnimCounter % 48) / 24);
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    case 8:
        // TODO: fake match
        ptr2 = ptr = gUnknown_086AD000[gCurrentPinballGame->slotReelResult];
        gCurrentPinballGame->portraitSpeciesId[arg1] = *(ptr2 += gUnknown_086AD79C[gCurrentPinballGame->plungerAnimFrame / 12]);
        index = ptr[2] * 16;
        DmaCopy16(3, gUnknown_083A8EEC[gCurrentPinballGame->portraitSpeciesId[arg1]], (void *)0x06010CA0 + arg1 * 0x300, 0x300);
        DmaCopy16(3, &gUnknown_081C02E4[index], (void *)0x05000200 + gUnknown_086AD798[arg1] * 0x20, 0x20);
        break;
    }

    gCurrentPinballGame->portraitRenderMode[arg1] = arg0;
    gCurrentPinballGame->portraitAnimCounter++;
}

void DrawBoardPortraitSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 baseX;
    s16 var1;
    s16 var2;

    if (gCurrentPinballGame->hatchRevealState == 3)
    {
        baseX = 0;
        var1 = 180;
        var2 = 180;
    }
    else if (gCurrentPinballGame->hatchRevealState == 2)
    {
        if (gMain.splitScreenOffset < 20)
        {
            var1 = 180;
            var2 = 180;
        }
        else
        {
            var1 = 88 + gCurrentPinballGame->slotReelVisualFrame;
            var2 = 88;
        }

        baseX = 48;
    }
    else
    {
        baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
        var1 = gCurrentPinballGame->slotReelVisualFrame + 300u - gCurrentPinballGame->bgScrollYWithOffset;
        var2 = 300 - gCurrentPinballGame->bgScrollYWithOffset;
    }

    group = gMain.boardSpriteGroups[22];
    group->baseX = baseX;
    group->baseY = var1;
    gCurrentPinballGame->bossGroupBasePosition.x = baseX;
    gCurrentPinballGame->bossGroupBasePosition.y = group->baseY;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].paletteNum = gCurrentPinballGame->pondEntityPaletteIds[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->spriteLayerPriority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->hatchRevealState == 1)
    {
        group = gMain.boardSpriteGroups[23];
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

        group = gMain.boardSpriteGroups[20];
        group->baseX = baseX;
        group->baseY = 267 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.boardSpriteGroups[21];
        group->baseX = baseX;
        group->baseY = 333 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.boardSpriteGroups[19];
    group->baseX = baseX - 8;
    group->baseY = var2 - 8;
    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->spriteLayerPriority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateRubyBonusFieldYPositions(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    if (gCurrentPinballGame->hatchRevealState == 1)
    {
        group = gMain.boardSpriteGroups[22];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.boardSpriteGroups[23];
        group->baseY = 300 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 180)
            group->baseY = 180;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.boardSpriteGroups[20];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.boardSpriteGroups[21];
        group->baseY = 180;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void UpdateRubyNuzleafAnimation(void)
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
        gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
        gCurrentPinballGame->nuzleafKeyframeIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 2;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 50000;
        break;
    case 2:
        if (gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][1] > gCurrentPinballGame->nuzleafKeyframeSubFrame)
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame++;
        }
        else
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
            gCurrentPinballGame->nuzleafKeyframeIndex++;
            if (gCurrentPinballGame->nuzleafKeyframeIndex == 7)
            {
                gCurrentPinballGame->nuzleafAnimState = 0;
                gCurrentPinballGame->nuzleafKeyframeIndex = 0;
                gCurrentPinballGame->nuzleafPositionIndex = 1;
            }
        }
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        break;
    case 3:
        gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
        gCurrentPinballGame->nuzleafKeyframeIndex = 7;
        gCurrentPinballGame->nuzleafAnimState = 4;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        m4aSongNumStart(SE_UNKNOWN_0xCF);
        PlayRumble(7);
        gCurrentPinballGame->scoreAddedInFrame = 100000;
        break;
    case 4:
        if (gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][1] > gCurrentPinballGame->nuzleafKeyframeSubFrame)
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame++;
        }
        else
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
            gCurrentPinballGame->nuzleafKeyframeIndex++;
            if (gCurrentPinballGame->nuzleafKeyframeIndex == 18)
            {
                gCurrentPinballGame->nuzleafAnimState = 5;
                m4aSongNumStart(SE_UNKNOWN_0xD1);
            }
        }

        if (gCurrentPinballGame->nuzleafKeyframeSubFrame == 6)
            m4aSongNumStart(SE_UNKNOWN_0xD0);

        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        break;
    case 5:
    case 6:
        if (gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][1] > gCurrentPinballGame->nuzleafKeyframeSubFrame)
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame++;
        }
        else
        {
            gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
            gCurrentPinballGame->nuzleafKeyframeIndex++;
            if (gCurrentPinballGame->nuzleafKeyframeIndex == 24)
                gCurrentPinballGame->nuzleafKeyframeIndex = 18;
        }

        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        break;
    case 7:
        gCurrentPinballGame->nuzleafHitPhase = 0;
        gCurrentPinballGame->nuzleafPositionIndex = 0;
        gCurrentPinballGame->nuzleafKeyframeSubFrame = 0;
        gCurrentPinballGame->nuzleafKeyframeIndex = 0;
        gCurrentPinballGame->nuzleafAnimState = 0;
        gCurrentPinballGame->nuzleafKeyframeIndex = 24;
        var1 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][0];
        var0 = gUnknown_086AD7C0[gCurrentPinballGame->nuzleafKeyframeIndex][2];
        break;
    }

    if (group->available)
    {
        group->baseX = gUnknown_086AD856[gCurrentPinballGame->nuzleafPositionIndex][0] - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gUnknown_086AD856[gCurrentPinballGame->nuzleafPositionIndex][1] - gCurrentPinballGame->bgScrollYWithOffset;
        DmaCopy16(3, gRubyStageNuzleaf_Gfx[gCurrentPinballGame->nuzleafGfxFrame], (void *)0x06014380, 0x260);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 0];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 1];
            *dst++ = gUnknown_086B2E64[var1][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    gCurrentPinballGame->nuzleafGfxFrame = var0;
}

void UpdateRubyShopDoorState(void)
{
    if (gCurrentPinballGame->boardEntryMode != 3)
    {
        if (gCurrentPinballGame->boardState < 3)
        {
            if (gCurrentPinballGame->trapDisplayState == 0)
                gCurrentPinballGame->shopDoorTargetFrame = gCurrentPinballGame->holeEntryState & 0xF;
            else
                gCurrentPinballGame->shopDoorTargetFrame = 3;
        }
        else if (gCurrentPinballGame->boardState != 6)
        {
            gCurrentPinballGame->shopDoorTargetFrame = 0;
        }
    }
}

void AnimateRubyShopDoor(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;

    group = &gMain.spriteGroups[65];
    if ((gCurrentPinballGame->shopDoorTargetFrame & 0xF) != gCurrentPinballGame->shopDoorCurrentFrame)
    {
        if (gCurrentPinballGame->shopDoorTransitionDelay)
        {
            if (gCurrentPinballGame->shopDoorTransitionDelay == 5)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->scrollDelayFrames = 0;
                gCurrentPinballGame->scrollHoldFrames = 3;
                gCurrentPinballGame->scrollTargetBottomY = 0;
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->fieldScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxVariant = 0;
                gCurrentPinballGame->scrollOverrideActive = 1;
                gCurrentPinballGame->scrollFromBottom = 0;
                m4aSongNumStart(SE_UNKNOWN_0xBD);
            }

            gCurrentPinballGame->shopDoorTransitionDelay--;
        }
        else
        {
            if (gCurrentPinballGame->shopDoorCurrentFrame > (gCurrentPinballGame->shopDoorTargetFrame & 0xF))
            {
                gCurrentPinballGame->shopDoorCurrentFrame--;
                gCurrentPinballGame->shopDoorTransitionDelay = 4;
            }
            else
            {
                gCurrentPinballGame->shopDoorCurrentFrame++;
                gCurrentPinballGame->shopDoorTransitionDelay = 4;
            }

            DmaCopy16(3, gRubyBoardShopDoor_Gfx[gCurrentPinballGame->shopDoorCurrentFrame], (void *)0x06013180, 0x180);
        }
    }

    if (gCurrentPinballGame->shopDoorCurrentFrame < 3)
        priority = 3;
    else
        priority = 2;

    group->baseX = 208 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 80 - gCurrentPinballGame->bgScrollYWithOffset;
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
        DmaCopy16(3, gUnknown_081379D8 + gCurrentPinballGame->paletteCycleIndex * 0x60, (void *)0x05000320, 0x20);
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06014680, 0x460);
        gCurrentPinballGame->rubyBumperCollisionPosition[0].x = -248;
        gCurrentPinballGame->rubyBumperCollisionPosition[0].y = -316;
        group->baseX = var1[2] + 124u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = var1[3] + 150u - gCurrentPinballGame->bgScrollYWithOffset;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (var0 == 4 || var0 == 10)
            gCurrentPinballGame->whiscashVulnerable = 0;
        else
            gCurrentPinballGame->whiscashVulnerable = 1;
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
                gCurrentPinballGame->ball->rotation += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8900;
                gCurrentPinballGame->ball->positionQ8.y = 0xBD00;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+1)
            {
                gCurrentPinballGame->ball->rotation += 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8C00;
                gCurrentPinballGame->ball->positionQ8.y = 0xB700;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_ABSORB_BALL_START+2)
                gCurrentPinballGame->ball->isGrabbed = 1;
            break;
        case WHISCASH_STATE_TO_SPHEAL_BOARD:
            gCurrentPinballGame->pauseInputLocked = 1;
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
                    gCurrentPinballGame->pendingBonusFieldId = FIELD_SPHEAL;
                    gCurrentPinballGame->ballReturnMode = 1;
                    gCurrentPinballGame->activeEvoHitCount = gCurrentPinballGame->savedEvoHitCount;
                    gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
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
                    gCurrentPinballGame->ball->rotation -= 64;
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
                gCurrentPinballGame->ball->isGrabbed = 0;
                gCurrentPinballGame->ball->rotation -= 64;
                gCurrentPinballGame->ball->positionQ8.x = 0x8500;
                gCurrentPinballGame->ball->positionQ8.y = 0xC000;
                gCurrentPinballGame->ball->velocity.x = 0;
                gCurrentPinballGame->ball->velocity.y = 0;
            }

            if (gCurrentPinballGame->whiscashFrameIx == WHISCASH_FRAME_SPITBALL+2)
                gCurrentPinballGame->ballLockState = 0;
            break;
        case WHISCASH_STATE_HIT:
            gCurrentPinballGame->whiscashFrameIx = WHISCASH_FRAME_HIT;
            gCurrentPinballGame->whiscashStateTimer = 0;
            gCurrentPinballGame->whiscashState = WHISCASH_STATE_ANGRY;
            gCurrentPinballGame->scoreAddedInFrame = 10;
            m4aSongNumStart(SE_RUBY_BUMPER_HIT);
            PlayRumble(7);
            if (gCurrentPinballGame->modeTimerFrames)
                gCurrentPinballGame->modeTimerFrames = 1;
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
                gCurrentPinballGame->bossShakeOffsetX = gUnknown_086AD9EC[gCurrentPinballGame->whiscashStateTimer % 8];
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
            gCurrentPinballGame->bossShakeOffsetX = 0;
            break;
        }
    }
    else
    {
        if (gCurrentPinballGame->rubyPondContentsChanging)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 144)
            {
                gCurrentPinballGame->pondBumperAnimState[0] = gUnknown_08137968[gCurrentPinballGame->rubyPondChangeTimer / 8];
                gCurrentPinballGame->pondBumperAnimState[1] = gCurrentPinballGame->pondBumperAnimState[0];
                gCurrentPinballGame->pondBumperAnimState[2] = gCurrentPinballGame->pondBumperAnimState[0];
            }
            else
            {
                gCurrentPinballGame->rubyPondContentsChanging = FALSE;
            }

            if (gCurrentPinballGame->pondBumperAnimState[0] == 10)
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
                        gCurrentPinballGame->rubyBumperLogicPosition[0].x = gUnknown_086AD9DC[0].x * 10;
                        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gUnknown_086AD9DC[0].y * 10;
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
            angle = (gCurrentPinballGame->gameFrameCount & 0x7F) * 0x200 + i * 0x5555;
            var1 = (gCurrentPinballGame->gameFrameCount % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->chinchouOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->chinchouOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->chinchouOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE:
        for (i = 0; i < 3; i++)
        {
            angle = 10000 - ((gCurrentPinballGame->gameFrameCount & 0x7F) * 0x200 + i * 0x5555);
            var1 = (gCurrentPinballGame->gameFrameCount % 60) - 30;
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->chinchouOrbitRadius = 180;
            gCurrentPinballGame->rubyBumperLogicPosition[i].x = (gCurrentPinballGame->chinchouOrbitRadius * Cos(angle)) / 20000 + 1380;
            gCurrentPinballGame->rubyBumperLogicPosition[i].y = (gCurrentPinballGame->chinchouOrbitRadius * Sin(angle)) / 20000 + 1500;
        }
        break;
    case RUBY_POND_STATE_CHINCHOU_ROWS:
        for (i = 0; i < 2; i++)
        {
            var1 = 23 - (gCurrentPinballGame->gameFrameCount % 46);
            if (var1 < 0)
                var1 = -var1;

            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].x = (i * 33 + 121) * 10;
            gCurrentPinballGame->rubyBumperLogicPosition[i + 1].y = var1 * 5 + 1340;
        }

        var1 = 23 - (gCurrentPinballGame->gameFrameCount + 23) % 46;
        if (var1 < 0)
            var1 = 0-var1;

        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = var1 * 5 + 1620;
        break;
    case RUBY_POND_STATE_LOTAD:
        gCurrentPinballGame->rubyBumperLogicPosition[0].x = 1210;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y = gUnknown_0813798C[(gCurrentPinballGame->gameFrameCount % 60) / 10] + 1300;
        gCurrentPinballGame->rubyBumperLogicPosition[1].x = 1600;
        gCurrentPinballGame->rubyBumperLogicPosition[1].y = gUnknown_0813798C[((gCurrentPinballGame->gameFrameCount + 20) % 60) / 10] + 1410;
        gCurrentPinballGame->rubyBumperLogicPosition[2].x = 1370;
        gCurrentPinballGame->rubyBumperLogicPosition[2].y = gUnknown_0813798C[((gCurrentPinballGame->gameFrameCount + 40) % 60) / 10] + 1660;
        break;
    case RUBY_POND_STATE_CHINCHOU_SINGLE_CLOCKWISE:
        tempVec.x = gUnknown_086AD9DC[gCurrentPinballGame->chinchouRandomTarget].x * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].x;
        tempVec.y = gUnknown_086AD9DC[gCurrentPinballGame->chinchouRandomTarget].y * 10 - gCurrentPinballGame->rubyBumperLogicPosition[0].y;
        squaredMagnitude = (tempVec.x * tempVec.x) + (tempVec.y * tempVec.y);
        angle2 = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle2) * 7) / 20000;
        tempVec2.y = (Sin(angle2) * -7) / 20000;
        gCurrentPinballGame->rubyBumperLogicPosition[0].x += tempVec2.x;
        gCurrentPinballGame->rubyBumperLogicPosition[0].y += tempVec2.y;
        if (squaredMagnitude < 2500)
            gCurrentPinballGame->chinchouRandomTarget = Random() % 4;

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
                            gCurrentPinballGame->scrollDelayFrames = 50;
                            gCurrentPinballGame->scrollHoldFrames = 600;
                            gCurrentPinballGame->scrollTargetBottomY = 236;
                            gCurrentPinballGame->fieldScrollOffsetY = 0;
                            gCurrentPinballGame->fieldScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxVariant = 6;
                            gCurrentPinballGame->scrollOverrideActive = 1;
                            gCurrentPinballGame->scrollFromBottom = 0;
                            gCurrentPinballGame->fieldEntryAnimTimer = 80;
                            gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                            gCurrentPinballGame->bannerAnimPhase = 50;
                            gCurrentPinballGame->bannerScrollVelocity = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[6], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[6], (void *)0x050003C0, 0x20);
                        }
                        else
                        {
                            gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                            gCurrentPinballGame->scrollDelayFrames = 50;
                            gCurrentPinballGame->scrollHoldFrames = 600;
                            gCurrentPinballGame->scrollTargetBottomY = 236;
                            gCurrentPinballGame->fieldScrollOffsetY = 0;
                            gCurrentPinballGame->fieldScrollSpeed = 4;
                            gCurrentPinballGame->bannerGfxVariant = 1;
                            gCurrentPinballGame->scrollOverrideActive = 1;
                            gCurrentPinballGame->scrollFromBottom = 0;
                            gCurrentPinballGame->fieldEntryAnimTimer = 80;
                            gCurrentPinballGame->bannerScrollPosQ10 = -2500;
                            gCurrentPinballGame->bannerAnimPhase = 50;
                            gCurrentPinballGame->bannerScrollVelocity = 0;
                            DmaCopy16(3, gUnknown_086ACEF8[1], (void *)0x06015800, 0x2400);
                            DmaCopy16(3, gUnknown_086ACF18[1], (void *)0x050003C0, 0x20);
                        }

                        gMain.blendControl = 0xCE;
                    }
                }
            }

            gCurrentPinballGame->bumperHitCount++;
            gCurrentPinballGame->bumperHitsSinceReset++;
        }

        gCurrentPinballGame->bumperHitCountdown--;
    }

    group = &gMain.spriteGroups[62];
    if (gCurrentPinballGame->rubyPondState == RUBY_POND_STATE_LOTAD)
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperAnimState[i])
            {
                if (gCurrentPinballGame->pondBumperAnimState[i] > 100)
                {
                    gCurrentPinballGame->pondBumperAnimState[i]--;
                    if (gCurrentPinballGame->pondBumperAnimState[i] == 100)
                        gCurrentPinballGame->pondBumperAnimState[i] = 0;

                    var0 = 8;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperAnimState[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->gameFrameCount % 50) / 25;
            }

            DmaCopy16(3, gUnknown_0844928C[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gUnknown_081379B8 + gCurrentPinballGame->paletteCycleIndex * 0x60, (void *)0x05000320, 0x20);
    }
    else // chinchou
    {
        for (i = 0; i < 3; i++)
        {
            if (gCurrentPinballGame->pondBumperAnimState[i])
            {
                if (gCurrentPinballGame->pondBumperAnimState[i] > 100)
                {
                    var0 = 9 - gCurrentPinballGame->pondBumperAnimState[i] / 105;
                    gCurrentPinballGame->pondBumperAnimState[i]--;
                    if (gCurrentPinballGame->pondBumperAnimState[i] == 100)
                        gCurrentPinballGame->pondBumperAnimState[i] = 0;
                }
                else
                {
                    var0 = gCurrentPinballGame->pondBumperAnimState[i];
                }
            }
            else
            {
                var0 = (gCurrentPinballGame->gameFrameCount % 50) / 25;
            }

            DmaCopy16(3, gUnknown_083C806C[var0], (void *)0x06012E80 + i * 0x100, 0x100);
        }

        DmaCopy16(3, gUnknown_08137998 + gCurrentPinballGame->paletteCycleIndex * 0x60, (void *)0x05000320, 0x20);
    }

    // Draw Bumpers: Lotad/chinchou
    for (i = 0; i < 3; i++)
    {
        group->baseX = gCurrentPinballGame->rubyBumperLogicPosition[i].x / 10 - gCurrentPinballGame->bgScrollXCopy - 8;
        group->baseY = gCurrentPinballGame->rubyBumperLogicPosition[i].y / 10 - gCurrentPinballGame->bgScrollYWithOffset - 4;
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

void DrawRubySharpedoSprite(void)
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
    DmaCopy16(3, gRubyBoardSharpedo_Gfx[gCurrentPinballGame->sharpedoGfxVariant], (void *)0x06012C20, 0x260);
    if (gCurrentPinballGame->pokemonActionFrame)
        index = gCurrentPinballGame->pokemonActionFrame;

    var0 = gUnknown_086AD9FC[index][0];
    gCurrentPinballGame->sharpedoGfxVariant = gUnknown_086AD9FC[index][1];
    group->baseX = 179 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 174 - gCurrentPinballGame->bgScrollYWithOffset;
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

void UpdatePikachuChargeProgress(void)
{
    if (gCurrentPinballGame->pikaChargeTarget != gCurrentPinballGame->pikaChargeDisplay)
    {
        gCurrentPinballGame->pikaChargeDisplay += 2;
        gCurrentPinballGame->pikaChargeSegment = gCurrentPinballGame->pikaChargeDisplay / 14;
        gCurrentPinballGame->pikaChargeAnimDuration = 80;
        gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
        gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
        if (gCurrentPinballGame->pikaChargeSegment == 11)
            gCurrentPinballGame->pikaChargeFlashTimer = 120;

        if (gCurrentPinballGame->pikaChargeSegment > 11)
        {
            gCurrentPinballGame->pikaChargeSegment = 12;
            gCurrentPinballGame->pikaChargeAnimDuration = 120;
            gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
            gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
        }

        if (gCurrentPinballGame->pikaChargeDisplay < 168 && gCurrentPinballGame->pikaChargeDisplay % 8 == 0)
        {
            s8 offset = gCurrentPinballGame->pikaChargeDisplay / 21;
            m4aSongNumStart(SE_PIKA_CHARGE_DO + offset);
        }

        if (gCurrentPinballGame->pikaChargeTarget <= gCurrentPinballGame->pikaChargeDisplay)
        {
            gCurrentPinballGame->pikaChargeDisplay = gCurrentPinballGame->pikaChargeTarget;
            if (gCurrentPinballGame->pikaChargeDisplay >= 168)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_7a);
                gCurrentPinballGame->scoreAddedInFrame = 3000;
            }
        }
    }

    if (gCurrentPinballGame->impactVelocitySampleCooldown)
        gCurrentPinballGame->impactVelocitySampleCooldown--;

    if (gCurrentPinballGame->lastBallImpactVelocityY > 0)
    {
        gCurrentPinballGame->lastBallImpactVelocityY -= 3;
        if (gCurrentPinballGame->lastBallImpactVelocityY < 0)
            gCurrentPinballGame->lastBallImpactVelocityY = 0;

        if (gCurrentPinballGame->pikachuChargeFrame < gCurrentPinballGame->pikachuChargeCycleLength - 1)
        {
            gCurrentPinballGame->pikachuChargeFrame++;
        }
        else
        {
            gCurrentPinballGame->pikachuChargeFrame = 0;
            MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
            gCurrentPinballGame->scoreAddedInFrame = 100;
            if (gCurrentPinballGame->pikaChargeSegment < 12 && gCurrentPinballGame->inputLockActive == 0)
            {
                gCurrentPinballGame->pikaChargeAnimDuration = 80;
                gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
                gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
            }
        }

        gCurrentPinballGame->pikachuChargeCycleLength = (450 - gCurrentPinballGame->lastBallImpactVelocityY) / 10;
        if (gCurrentPinballGame->pikachuChargeCycleLength < 5)
            gCurrentPinballGame->pikachuChargeCycleLength = 5;

        gCurrentPinballGame->pikaSpinnerFrame = (gCurrentPinballGame->pikachuChargeFrame * 16) / gCurrentPinballGame->pikachuChargeCycleLength;
    }
    else
    {
        if (gCurrentPinballGame->lastBallImpactVelocityY < 0)
        {
            gCurrentPinballGame->lastBallImpactVelocityY += 3;
            if (gCurrentPinballGame->lastBallImpactVelocityY > 0)
                gCurrentPinballGame->lastBallImpactVelocityY = 0;

            if (gCurrentPinballGame->pikachuChargeFrame < gCurrentPinballGame->pikachuChargeCycleLength - 1)
            {
                gCurrentPinballGame->pikachuChargeFrame++;
            }
            else
            {
                gCurrentPinballGame->pikachuChargeFrame = 0;
                MPlayStart(&gMPlayInfo_SE3, &se_unk_79);
                gCurrentPinballGame->scoreAddedInFrame = 100;
                if (gCurrentPinballGame->pikaChargeSegment < 12 && gCurrentPinballGame->inputLockActive == 0)
                {
                    gCurrentPinballGame->pikaChargeAnimDuration = 80;
                    gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
                    gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
                }
            }

            gCurrentPinballGame->pikachuChargeCycleLength = (450 + gCurrentPinballGame->lastBallImpactVelocityY) / 10;
            if (gCurrentPinballGame->pikachuChargeCycleLength < 5)
                gCurrentPinballGame->pikachuChargeCycleLength = 5;

            gCurrentPinballGame->pikaSpinnerFrame = (gCurrentPinballGame->pikachuChargeFrame * 16) / gCurrentPinballGame->pikachuChargeCycleLength;
        }
        else
        {
            if (gCurrentPinballGame->pikaSpinnerFrame > 0)
            {
                gCurrentPinballGame->pikachuChargeFrame++;
                gCurrentPinballGame->pikachuChargeFrame %= 40;
                gCurrentPinballGame->pikaSpinnerFrame = (gCurrentPinballGame->pikachuChargeFrame * 16) / 40;
            }
        }
    }
}

void UpdatePikaSpinnerGraphics(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    index = gCurrentPinballGame->pikaSpinnerFrame;
    group = gMain.boardSpriteGroups[31];
    group->baseX = 206 - gCurrentPinballGame->bgScrollXCopy;
    if (gMain.selectedField == FIELD_RUBY)
        group->baseY = 174 - gCurrentPinballGame->bgScrollYWithOffset;
    else
        group->baseY = 154 - gCurrentPinballGame->bgScrollYWithOffset;

    if (gCurrentPinballGame->pikaSpinnerFrame != gCurrentPinballGame->pikaSpinnerFramePrev)
    {
        gCurrentPinballGame->pikaSpinnerFramePrev = gCurrentPinballGame->pikaSpinnerFrame;
        DmaCopy16(3, gMainBoardPikaSpinner_Gfx[index], (void *)0x06010780, 0x120);
    }

    for (i = 0; i < 4; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void AnimateRubyGulpinProjectile(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 var0;

    index = 0;
    group = &gMain.spriteGroups[14];
    if (gCurrentPinballGame->coinBounceTimer < 60)
    {
        if (gCurrentPinballGame->coinBounceTimer >= 27 && gCurrentPinballGame->coinBounceTimer < 47)
        {
            index = (gCurrentPinballGame->coinBounceTimer - 27) / 5;
            DmaCopy16(3, gUnknown_083C562C[index], (void *)0x06014280, 0x100);
            group->baseX = 176 - gCurrentPinballGame->bgScrollXCopy;
        }
        else
        {
            group->available = 0;
            group->baseX = 176 - gCurrentPinballGame->bgScrollXCopy;
        }
    }
    else
    {
        if (gCurrentPinballGame->coinBounceTimer >= 100 && gCurrentPinballGame->coinBounceTimer < 120)
        {
            index = (gCurrentPinballGame->coinBounceTimer - 100) / 5;
            DmaCopy16(3, gUnknown_083C562C[index], (void *)0x06014280, 0x100);
            group->baseX = 32 - gCurrentPinballGame->bgScrollXCopy;
        }
        else
        {
            group->available = 0;
            group->baseX = 32 - gCurrentPinballGame->bgScrollXCopy;
        }

    }

    if (group->available)
    {
        group->baseY = 296 - gCurrentPinballGame->bgScrollYWithOffset;
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
        if (gCurrentPinballGame->coinBounceTimer < 120)
        {
            if (gCurrentPinballGame->coinBounceTimer % 8 == 0)
                m4aSongNumStart(SE_UNKNOWN_0xC6);

            index = (gCurrentPinballGame->coinBounceTimer % 16) / 4;
            DmaCopy16(3, gUnknown_083C542C[index], (void *)0x06014200, 0x80);
            var0 = (gCurrentPinballGame->coinBounceTimer << 0x10) / 90;
            gCurrentPinballGame->coinBounceVelX -= 2;
            gCurrentPinballGame->coinBounceX += gCurrentPinballGame->coinBounceVelX;
            if (gCurrentPinballGame->coinBounceTimer < 30)
                gCurrentPinballGame->coinBounceY = gCurrentPinballGame->coinBounceTimer + (Sin(var0) * 24) / 20000;
            else
                gCurrentPinballGame->coinBounceY = 30 + (Sin(var0) * 24) / 20000;

            gCurrentPinballGame->coinBounceTimer++;
            if (gCurrentPinballGame->coinBounceTimer == 27)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->pondGateCycleCount[1] > 0)
                {
                    gCurrentPinballGame->pondGateCycleCount[1]++;
                }
                else
                {
                    gCurrentPinballGame->pondGateCycleCount[1] = 2;
                    gCurrentPinballGame->pondGateAnimSubFrame[1] = 190;
                }
            }

            if (gCurrentPinballGame->coinBounceTimer == 100)
            {
                gMain.spriteGroups[14].available = 1;
                m4aSongNumStart(SE_UNKNOWN_0xC7);
                if (gCurrentPinballGame->pondGateCycleCount[0] > 0)
                {
                    gCurrentPinballGame->pondGateCycleCount[0]++;
                }
                else
                {
                    gCurrentPinballGame->pondGateCycleCount[0] = 2;
                    gCurrentPinballGame->pondGateAnimSubFrame[0] = 190;
                }
            }
        }
        else
        {
            gCurrentPinballGame->coinBounceTimer = 0;
            gCurrentPinballGame->coinBounceX = 0;
            gCurrentPinballGame->coinBounceY = 190;
            gCurrentPinballGame->coinBounceVelX = 100;
            gCurrentPinballGame->coinBounceVelY = 0;
            group->available = 0;
        }

        group->baseX = (gCurrentPinballGame->coinBounceX / 20) + 71u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->coinBounceY + 248u - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY > 190)
            group->baseY = 190;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateRubyGulpinBodySprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[53];
    if (gCurrentPinballGame->coinAnimActive)
    {
        index = gUnknown_086ADA58[gCurrentPinballGame->coinAnimFrame / 5];
        if (gCurrentPinballGame->coinAnimFrame == 40)
        {
            gCurrentPinballGame->coinBounceTimer = 0;
            gCurrentPinballGame->coinBounceX = 0;
            gCurrentPinballGame->coinBounceY = 0;
            gCurrentPinballGame->coinBounceVelX = 100;
            gCurrentPinballGame->coinBounceVelY = 0;
            gMain.spriteGroups[13].available = 1;
        }

        if (gCurrentPinballGame->coinAnimFrame < 54)
            gCurrentPinballGame->coinAnimFrame++;
        else
            gCurrentPinballGame->coinAnimActive = 0;

        DmaCopy16(3, gUnknown_083C3C2C[index], (void *)0x06012720, 0x300);
    }
    else
    {
        index = (gMain.systemFrameCount % 50) / 25;
        if (gCurrentPinballGame->spriteUpdateSlot == 1)
        {
            DmaCopy16(3, gUnknown_083C3C2C[index], (void *)0x06012720, 0x300);
        }
    }

    group->baseX = 55 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 221 - gCurrentPinballGame->bgScrollYWithOffset;
    i = 0;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void DrawRubyPondGulpinPlatforms(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const s16 *var0;
    s16 index;

    var0 = gUnknown_086ADA6E[gCurrentPinballGame->rubyPondAnimFrame];
    group = &gMain.spriteGroups[57];
    group->baseX = 9 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 288 - gCurrentPinballGame->bgScrollYWithOffset;
    if (gCurrentPinballGame->rubyPondCurrentStage > gCurrentPinballGame->rubyPondStage)
    {
        if (gCurrentPinballGame->pondStageTransitionActive)
        {
            if (gCurrentPinballGame->pondTransitionFrame == 0)
            {
                gCurrentPinballGame->rubyPondAnimFrame = 59;
                gCurrentPinballGame->rubyPondSubframeTimer = 0;
                gCurrentPinballGame->pondTransitionFrame++;
            }

            if (var0[1] > gCurrentPinballGame->rubyPondSubframeTimer)
            {
                gCurrentPinballGame->rubyPondSubframeTimer++;
            }
            else
            {
                gCurrentPinballGame->rubyPondSubframeTimer = 1;
                gCurrentPinballGame->rubyPondAnimFrame++;
                if (gCurrentPinballGame->rubyPondAnimFrame == 84)
                {
                    gCurrentPinballGame->rubyPondAnimFrame = 0;
                    gCurrentPinballGame->pondStageTransitionActive = 0;
                    gCurrentPinballGame->pondTransitionFrame = 0;
                    gCurrentPinballGame->rubyPondCurrentStage = 0;
                }

                if (gCurrentPinballGame->rubyPondAnimFrame == 60 || gCurrentPinballGame->rubyPondAnimFrame == 69 || gCurrentPinballGame->rubyPondAnimFrame == 78)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
    }
    else if (gCurrentPinballGame->rubyPondCurrentStage < gCurrentPinballGame->rubyPondStage)
    {
        if (var0[1] <= gCurrentPinballGame->rubyPondSubframeTimer)
        {
            gCurrentPinballGame->rubyPondSubframeTimer = 1;
            gCurrentPinballGame->rubyPondAnimFrame++;
            if (gCurrentPinballGame->rubyPondStage == 1)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 9)
                {
                    gCurrentPinballGame->rubyPondCurrentStage = 1;
                    gCurrentPinballGame->rubyPondAnimFrame = 84;
                }

                if (gCurrentPinballGame->rubyPondAnimFrame == 6)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->rubyPondStage == 2)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 23)
                {
                    gCurrentPinballGame->rubyPondCurrentStage = 2;
                    gCurrentPinballGame->rubyPondAnimFrame = 95;
                }

                if (gCurrentPinballGame->rubyPondAnimFrame == 20)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
            else if (gCurrentPinballGame->rubyPondStage == 3)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 35)
                {
                    gCurrentPinballGame->rubyPondCurrentStage = 3;
                    gCurrentPinballGame->rubyPondAnimFrame = 35;
                    RequestBoardTransition(7);
                }

                if (gCurrentPinballGame->rubyPondAnimFrame == 32)
                    m4aSongNumStart(SE_UNKNOWN_0xD2);
            }
        }
        else
        {
            gCurrentPinballGame->rubyPondSubframeTimer++;
        }
    }
    else if (gCurrentPinballGame->rubyPondStage)
    {
        if (var0[1] > gCurrentPinballGame->rubyPondSubframeTimer)
        {
            gCurrentPinballGame->rubyPondSubframeTimer++;
        }
        else
        {
            gCurrentPinballGame->rubyPondSubframeTimer = 1;
            gCurrentPinballGame->rubyPondAnimFrame++;
            if (gCurrentPinballGame->rubyPondStage == 1)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 95)
                    gCurrentPinballGame->rubyPondAnimFrame = 84;
            }
            else if (gCurrentPinballGame->rubyPondStage == 2)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 109)
                    gCurrentPinballGame->rubyPondAnimFrame = 95;
            }
            else if (gCurrentPinballGame->rubyPondStage == 3)
            {
                if (gCurrentPinballGame->rubyPondAnimFrame == 60)
                    gCurrentPinballGame->rubyPondAnimFrame = 35;
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
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 0];
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 1];
        *dst++ = gUnknown_086B2FC0[index][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void UpdateRubyPondGateHitLogic(void)
{
    s16 i;

    for (i = 0; i < 2; i++)
    {
        if (gCurrentPinballGame->pondGateCycleCount[i] > 0)
        {
            if (gUnknown_086ADEB2[gCurrentPinballGame->pondGateAnimPhase[i]][0] > gCurrentPinballGame->pondGateAnimSubFrame[i])
            {
                gCurrentPinballGame->pondGateAnimSubFrame[i]++;
            }
            else
            {
                gCurrentPinballGame->pondGateAnimSubFrame[i] = 0;
                gCurrentPinballGame->pondGateAnimPhase[i]++;
                if (gCurrentPinballGame->pondGateAnimPhase[i] > 11)
                {
                    gCurrentPinballGame->pondGateAnimPhase[i] = 0;
                    gCurrentPinballGame->pondGateCycleCount[i]--;
                }
            }

            if (gCurrentPinballGame->pondGateAnimPhase[i] == 1)
                gCurrentPinballGame->pondGateSpriteOffset[i] = gCurrentPinballGame->pondGateAnimSubFrame[i] / 2;

            if (gCurrentPinballGame->pondGateAnimPhase[i] == 11)
                gCurrentPinballGame->pondGateSpriteOffset[i] = 14 - gCurrentPinballGame->pondGateAnimSubFrame[i] / 2;

            if (gCurrentPinballGame->pondGateSpriteOffset[i] < 3)
                gCurrentPinballGame->pondGateSpriteOffset[i] = 3;
        }
    }

    if (gCurrentPinballGame->pondGateHitSide)
    {
        if (gCurrentPinballGame->pondGateHitSide == 1)
        {
            if (gCurrentPinballGame->boardState != 7)
            {
                if (gCurrentPinballGame->boardState < 3) {
                    if (gCurrentPinballGame->rubyPondStage < 3)
                    {
                        gCurrentPinballGame->rubyPondStage++;
                        if (gCurrentPinballGame->rubyPondStage == 1)
                        {
                            gCurrentPinballGame->rubyPondAnimFrame = 0;
                            gCurrentPinballGame->rubyPondSubframeTimer = 0;
                        }
                        else if (gCurrentPinballGame->rubyPondStage == 2)
                        {
                            gCurrentPinballGame->rubyPondAnimFrame = 12;
                            gCurrentPinballGame->rubyPondSubframeTimer = 0;
                        }
                        else if (gCurrentPinballGame->rubyPondStage == 3)
                        {
                            gCurrentPinballGame->rubyPondAnimFrame = 24;
                            gCurrentPinballGame->rubyPondSubframeTimer = 0;
                            gCurrentPinballGame->pondBannerTriggerDelay = 1;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->rubyPondStage < 2)
                    {
                        gCurrentPinballGame->rubyPondStage++;
                        if (gCurrentPinballGame->rubyPondStage == 1)
                        {
                            gCurrentPinballGame->rubyPondAnimFrame = 0;
                            gCurrentPinballGame->rubyPondSubframeTimer = 0;
                        }
                        else if (gCurrentPinballGame->rubyPondStage == 2)
                        {
                            gCurrentPinballGame->rubyPondAnimFrame = 12;
                            gCurrentPinballGame->rubyPondSubframeTimer = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (gCurrentPinballGame->rampPrizeAnimState == 0)
                gCurrentPinballGame->rampPrizeAnimState = 1;
            else
                gCurrentPinballGame->rampPrizeAnimState = 0;
        }

        gCurrentPinballGame->pondGateCycleCount[0] = 0;
        gCurrentPinballGame->pondGateCycleCount[1] = 0;
        gCurrentPinballGame->pondGateHitSide = 0;
        PlayRumble(7);
        m4aSongNumStart(SE_UNKNOWN_0xB7);
        gCurrentPinballGame->scoreAddedInFrame = 3000;
        gCurrentPinballGame->pondGateAnimPhase[0] = 0;
        gCurrentPinballGame->pondGateAnimPhase[1] = 0;
        gCurrentPinballGame->pondGateAnimSubFrame[0] = 0;
        gCurrentPinballGame->pondGateAnimSubFrame[1] = 0;
        gCurrentPinballGame->pondGateSpriteOffset[0] = 3;
        gCurrentPinballGame->pondGateSpriteOffset[1] = 3;
    }
}

void DrawRubyPondGateSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    for (i = 0; i < 2; i++)
    {
        index = gUnknown_086ADEB0[gCurrentPinballGame->pondGateAnimPhase[i]][0];
        DmaCopy16(3, gUnknown_0847FD0C[index], (void *)0x06012A20 + i * 0x100, 0x100);
        group = &gMain.spriteGroups[59 + i];
        if (group->available)
        {
            int var0 = i * 120 - (gCurrentPinballGame->bgScrollXCopy - 48);
            group->baseX = var0 + ((1 - (i * 2)) * (gCurrentPinballGame->pondGateSpriteOffset[i] - 14));
            group->baseY = 301 - gCurrentPinballGame->bgScrollYWithOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    if (gCurrentPinballGame->pondBannerTriggerDelay)
    {
        gCurrentPinballGame->pondBannerTriggerDelay--;
        if (gCurrentPinballGame->pondBannerTriggerDelay == 0)
        {
            if (gCurrentPinballGame->bannerType)
                gCurrentPinballGame->pondBannerTriggerDelay = 1;
            else
                gCurrentPinballGame->bannerType = 4;

            if (gCurrentPinballGame->pondBannerTriggerDelay == 0)
            {
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->scrollDelayFrames = 70;
                gCurrentPinballGame->scrollHoldFrames = 160;
                gCurrentPinballGame->scrollTargetBottomY = 0;
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->fieldScrollSpeed = 0;
                gCurrentPinballGame->bannerGfxVariant = 4;
                gCurrentPinballGame->scrollOverrideActive = 1;
                gCurrentPinballGame->scrollFromBottom = 0;
                gCurrentPinballGame->fieldEntryAnimTimer = 120;
                gCurrentPinballGame->bannerScrollPosQ10 = 0;
                gCurrentPinballGame->bannerAnimPhase = 50;
                gCurrentPinballGame->bannerScrollVelocity = 0;
                DmaCopy16(3, gUnknown_086ACEF8[4], (void *)0x06015800, 0x2400);
                DmaCopy16(3, gUnknown_086ACF18[4], (void *)0x050003C0, 0x20);
                gMain.blendControl = 0xCE;
            }
        }
    }
}

void RunPikachuThunderboltSequence(void)
{
    s16 i;
    s16 j;
    s16 r5;
    s16 tempY;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;

    UpdateHatchedMonFlyingAnimation();

    if (gCurrentPinballGame->pikaChargeTarget > 167)
    {
        gCurrentPinballGame->pondEntitySpriteFrame[0] = gUnknown_086ADF48[(gMain.fieldFrameCount % 160) / 5];
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pondEntitySpriteFrame[1] = gCurrentPinballGame->pondEntitySpriteFrame[0] + 6;
        else
            gCurrentPinballGame->pondEntitySpriteFrame[1] = gCurrentPinballGame->pondEntitySpriteFrame[0];
    }
    else
    {
        gCurrentPinballGame->pondEntitySpriteFrame[0] = (gMain.fieldFrameCount % 50) / 25;
        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pondEntitySpriteFrame[1] = gCurrentPinballGame->pondEntitySpriteFrame[0] + 9;
        else
            gCurrentPinballGame->pondEntitySpriteFrame[1] = gCurrentPinballGame->pondEntitySpriteFrame[0];
    }

    if (gCurrentPinballGame->outLanePikaPosition == 2)
    {
        gCurrentPinballGame->outLanePikaActive[0] = 1;
        gCurrentPinballGame->outLanePikaActive[1] = 1;
    }
    else
    {
        gCurrentPinballGame->outLanePikaActive[0 + gCurrentPinballGame->outLanePikaPosition] = 1;
        gCurrentPinballGame->outLanePikaActive[1 - gCurrentPinballGame->outLanePikaPosition] = 0;
    }

    if (gCurrentPinballGame->outLaneSaverTimer != 0)
    {
        if (gCurrentPinballGame->outLaneSaverTimer == 120)
        {
            // gCurrentPinballGame->outLaneSide + gCurrentPinballGame->unk1E2
            // Note: this can be && chained off of the previous if, once we have this line deciphered.
            if (gCurrentPinballGame->outLanePikaActive[gCurrentPinballGame->outLaneSide - 1] != 0)
            {
                if (gCurrentPinballGame->pikaChargeTarget > 167)
                {
                    gCurrentPinballGame->ballLockState = 1;
                    gCurrentPinballGame->inputLockActive = 1;
                    gCurrentPinballGame->outLaneSaverAnimProgress = 120;
                    gCurrentPinballGame->outLaneSaverAnimTotal = 120;
                    gCurrentPinballGame->captureLockdownTimer = gCurrentPinballGame->outLaneSaverAnimProgress;
                    gCurrentPinballGame->ballLocked = 1;
                    gCurrentPinballGame->outLanePikaAnimSubFrame = 0;
                    gCurrentPinballGame->outLanePikaAnimKeyframe = 0;

                    if (gCurrentPinballGame->outLanePikaPosition != 2)
                    {
                        gCurrentPinballGame->pikaChargeTarget = 0;
                        gCurrentPinballGame->pikaChargeDisplay = 0;
                        gCurrentPinballGame->pikaChargeSegmentPrev = 0;
                        gCurrentPinballGame->pikaChargeSegment = 0;
                        gCurrentPinballGame->pikaChargeSpriteOffsetX = 0;
                        gCurrentPinballGame->pikaChargeSpriteY = -4;
                        gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
                        gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
                        gCurrentPinballGame->pikaChargeFlashTimer = 0;
                        gCurrentPinballGame->pikaChargeAnimDuration = 0;
                    }

                    gCurrentPinballGame->captureOriginPosition = gCurrentPinballGame->ball->positionQ1;
                    gCurrentPinballGame->scoreAddedInFrame = 30000;

                    if (gCurrentPinballGame->pondBonusHitCount <= 98)
                        gCurrentPinballGame->pondBonusHitCount++;
                }
                else
                {
                    gCurrentPinballGame->outLaneSaverTimer = 60;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_142);
                }

                i = gCurrentPinballGame->outLaneSide - 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2)
                    gCurrentPinballGame->pondEntitySpriteFrame[i] = (i) * 7 + 2;
                else
                    gCurrentPinballGame->pondEntitySpriteFrame[i] = 2;

                DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->pondEntitySpriteFrame[i] * 0x180), 0x06010480 + ((i) * 0x180), 0x180);
            }
        }

        if (gCurrentPinballGame->outLanePikaPosition == 2)
            gCurrentPinballGame->pondEntitySpriteFrame[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
        else
            gCurrentPinballGame->pondEntitySpriteFrame[gCurrentPinballGame->outLaneSide - 1] = 2;

        gCurrentPinballGame->outLaneSaverTimer--;
    }

    if (gCurrentPinballGame->inputLockActive != 0)
    {
        if (gCurrentPinballGame->captureLockdownTimer > 1)
        {
            r5 = (gCurrentPinballGame->outLaneSaverAnimProgress * 0x10000) / 10;
            gCurrentPinballGame->captureLockdownTimer--;
            if (gCurrentPinballGame->outLaneSaverAnimProgress != 0)
            {
                gCurrentPinballGame->outLaneSaverAnimProgress--;
                if (gCurrentPinballGame->outLaneSaverAnimProgress == 40 && gCurrentPinballGame->captureLockdownTimer > 40)
                {
                    gCurrentPinballGame->outLaneSaverAnimProgress = 60;
                }
            }
            if (gCurrentPinballGame->captureLockdownTimer == 116)
            {
                if (gCurrentPinballGame->bannerType)
                    gCurrentPinballGame->captureLockdownTimer = 120;
                else
                {
                    gCurrentPinballGame->bannerType = 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                    {
                        if (gCurrentPinballGame->outLaneSide == 1)
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        else
                            MPlayStart(&gMPlayInfo_SE1, &se_unk_b3);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                    else
                    {
                        MPlayStart(&gMPlayInfo_SE1, &se_unk_b1);
                        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x40);
                    }
                }
            }
            if (gCurrentPinballGame->captureLockdownTimer == 115 && gCurrentPinballGame->bannerType == 1)
                m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, 0x200);

            gCurrentPinballGame->ball->positionQ1.x =
                gCurrentPinballGame->captureOriginPosition.x + ((Sin(r5) * 6) / 20000) +
                ((gUnknown_086ADF8A[gCurrentPinballGame->outLaneSide - 1] * 2 - gCurrentPinballGame->captureOriginPosition.x) * (gCurrentPinballGame->outLaneSaverAnimTotal - gCurrentPinballGame->outLaneSaverAnimProgress)) / gCurrentPinballGame->outLaneSaverAnimTotal;

            tempY = ((gCurrentPinballGame->outLaneSaverAnimTotal - gCurrentPinballGame->outLaneSaverAnimProgress) * 40) / gCurrentPinballGame->outLaneSaverAnimTotal;
            gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->captureOriginPosition.y - tempY;

            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
        }
        else if (gCurrentPinballGame->captureLockdownTimer == 1)
        {
            gCurrentPinballGame->ball->positionQ1.x = gUnknown_086ADF8A[gCurrentPinballGame->outLaneSide - 1] * 2;
            gCurrentPinballGame->ball->positionQ1.y = 702;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x * 128;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y * 128;
            gCurrentPinballGame->ball->velocity.x = 0;
            // fly me to the moon
            gCurrentPinballGame->ball->velocity.y = -300;
            m4aSongNumStart(SE_UNKNOWN_0x7C);
            gCurrentPinballGame->captureLockdownTimer = 0;
            gCurrentPinballGame->ballLockState = 0;
            gCurrentPinballGame->ballLocked = 0;
            gCurrentPinballGame->holeIndicators[(gCurrentPinballGame->outLaneSide - 1) * 3] = 1;

            if (gCurrentPinballGame->allHolesCompleted == 0 &&
                (gCurrentPinballGame->holeIndicators[0] &
                 gCurrentPinballGame->holeIndicators[1] &
                 gCurrentPinballGame->holeIndicators[2] &
                 gCurrentPinballGame->holeIndicators[3]))
            {
                gCurrentPinballGame->allHolesCompleted = 1;
                gCurrentPinballGame->holeCompletionFlashTimer = 126;
                gCurrentPinballGame->scoreAddedInFrame = 4000;
            }

            PlayRumble(11);
        }

        if (gCurrentPinballGame->captureLockdownTimer >= 100)
        {
            if (gCurrentPinballGame->outLanePikaPosition == 2)
                gCurrentPinballGame->pondEntitySpriteFrame[gCurrentPinballGame->outLaneSide - 1] = (gCurrentPinballGame->outLaneSide - 1) * 7 + 2;
            else
                gCurrentPinballGame->pondEntitySpriteFrame[gCurrentPinballGame->outLaneSide - 1] = 2;

            if (gCurrentPinballGame->captureLockdownTimer == 100)
            {
                gMain.boardSpriteGroups[38]->available = 1;

                if (gCurrentPinballGame->outLanePikaPosition == 2 && gCurrentPinballGame->outLaneSide == 2)
                {
                    DmaCopy16(3, gUnknown_08395A4C, 0x06015800, 0x2400);
                }
                else
                {
                    DmaCopy16(3, gUnknown_08397E6C, 0x06015800, 0x2400);
                }
            }
        }
        else
        {
            if (gUnknown_086ADEE0[gCurrentPinballGame->outLanePikaAnimKeyframe][1] > gCurrentPinballGame->outLanePikaAnimSubFrame)
                gCurrentPinballGame->outLanePikaAnimSubFrame++;
            else
            {
                gCurrentPinballGame->outLanePikaAnimSubFrame = 0;
                gCurrentPinballGame->outLanePikaAnimKeyframe++;

                if (gCurrentPinballGame->outLanePikaAnimKeyframe == 23)
                {
                    m4aSongNumStop(SE_UNKNOWN_0x7C);
                    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
                }

                if (gCurrentPinballGame->outLanePikaAnimKeyframe > 25)
                {
                    gCurrentPinballGame->outLanePikaAnimKeyframe = 25;
                    gCurrentPinballGame->inputLockActive = 0;
                    gMain.boardSpriteGroups[38]->available = 0;
                    gCurrentPinballGame->bannerType = 0;

                    i = gCurrentPinballGame->outLaneSide - 1;
                    if (gCurrentPinballGame->outLanePikaPosition == 2)
                        gCurrentPinballGame->pondEntitySpriteFrame[i] = i * 9;
                    else
                        gCurrentPinballGame->pondEntitySpriteFrame[i] = 0;

                    DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->pondEntitySpriteFrame[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }
            }

            if (gCurrentPinballGame->outLanePikaAnimKeyframe >= 17 && gCurrentPinballGame->outLanePikaAnimKeyframe <= 23)
            {
                if ((gMain.systemFrameCount & 3) >> 1)
                    gCurrentPinballGame->cameraScrollX = -3;
                else
                    gCurrentPinballGame->cameraScrollX = 3;
            }

            r5 = gUnknown_086ADEE0[gCurrentPinballGame->outLanePikaAnimKeyframe][0];
            i = gCurrentPinballGame->outLaneSide - 1;

            spriteGroup = gMain.boardSpriteGroups[38];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->bgScrollXCopy - 16);
            if (gCurrentPinballGame->inputLockActive)
            {
                spriteGroup->baseY = 380 - gCurrentPinballGame->bgScrollYWithOffset;
                gCurrentPinballGame->outLanePikaActive[i] = 0;
            }
            else
            {
                spriteGroup->baseY = 180;
                gCurrentPinballGame->outLanePikaActive[i] = 1;
            }

            for (j = 0; j < 4; j++)
            {
                oamSimple = &spriteGroup->oam[j];
                dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 0];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 1];
                *dst++ = gUnknown_086B4922[r5][j * 3 + 2];

                gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            }
        }
    }
    spriteGroup = gMain.boardSpriteGroups[29];

    if (spriteGroup->available)
    {
        for (i = 0; i <= 1; i++)
        {
            spriteGroup = gMain.boardSpriteGroups[29 + i];
            spriteGroup->baseX = (i * 177) - (gCurrentPinballGame->bgScrollXCopy - 16);
            if (gCurrentPinballGame->outLanePikaActive[i])
            {
                if ((gMain.fieldFrameCount % 5) == 0)
                {
                    DmaCopy16(3, gUnknown_084C07EC + (gCurrentPinballGame->pondEntitySpriteFrame[i] * 0x180), 0x06010480 + (i * 0x180), 0x180);
                }

                tempY = 380 - gCurrentPinballGame->bgScrollYWithOffset;
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
