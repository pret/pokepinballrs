#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u16 gUnknown_086B4D4E[40][2][3];
extern const u16 gUnknown_086AE54A[];
extern const u8 gSapphireStageBasket_Gfx[][0x280];
extern const u8 gSapphireBoardSeedot_Gfx[][0x180];
extern const u16 gUnknown_086AE544[];
extern const u16 gSapphireBoardSeedotSpritesheetOam[6][6][2][3];
extern const u16 gUnknown_08137D06[][14];
extern const u16 gUnknown_08137CF6[][4];
extern const u16 gUnknown_08137CE2[][5];


void InitSapphirePondState(void)
{
    gCurrentPinballGame->pondAnimState = 1;
    gCurrentPinballGame->pondAnimIndexPrev = 0;
    gCurrentPinballGame->pondAnimIndex = 0;
    gCurrentPinballGame->pondAnimSubFrame = 0;
    gCurrentPinballGame->pondSpriteXQ10 = 2080;
    gCurrentPinballGame->pondSpriteYQ10 = 700;
}

void UpdateAndDrawSapphirePondAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 sp0;
    s16 index;
    s16 var1;
    s16 var2;
    s16 var3;
    int var0;

    var3 = 0;
    var1 = 0;
    var2 = 0;
    group = &gMain.spriteGroups[52];
    sp0 = 0;
    switch (gCurrentPinballGame->pondAnimState)
    {
    case 0:
    case 1:
        break;
    case 2:
        var3 = 4;
        var1 = 4;
        var2 = 3;
        break;
    case 3:
        var3 = 8;
        var1 = 4;
        var2 = 3;
        break;
    case 4:
        var3 = 12;
        var1 = 12;
        var2 = 5;
        break;
    case 5:
        var3 = 33;
        var1 = 0;
        var2 = 0;
        break;
    }

    if (gCurrentPinballGame->pondAnimIndexPrev != gCurrentPinballGame->pondAnimIndex)
    {
        index = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][3];
        DmaCopy16(3, &gUnknown_084FD18C[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->pondAnimIndexPrev = gCurrentPinballGame->pondAnimIndex;
    }

    if (gCurrentPinballGame->pondAnimState > 1)
    {
        if (gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][1] > gCurrentPinballGame->pondAnimSubFrame)
        {
            gCurrentPinballGame->pondAnimSubFrame++;
        }
        else
        {
            gCurrentPinballGame->pondAnimIndex++;
            gCurrentPinballGame->pondAnimSubFrame = 0;
            if (gCurrentPinballGame->pondAnimIndex >= var3)
            {
                gCurrentPinballGame->pondAnimIndex = var1;
                gCurrentPinballGame->pondAnimState = var2;
            }

            if (gCurrentPinballGame->pondAnimIndex == 18)
                BuildSpeciesWeightsForEggMode();

            if (gCurrentPinballGame->pondAnimIndex == 19)
            {
                PickSpeciesForEggMode();
                if (gMain.mainState != STATE_GAME_IDLE)
                    SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);
            }

            if (gCurrentPinballGame->pondAnimIndex == 20)
                LoadHatchModePokemonSpritesheets();

            if ((gCurrentPinballGame->pondAnimIndex == 8 || gCurrentPinballGame->pondAnimIndex == 27) && gCurrentPinballGame->pondAnimSubFrame == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->pondAnimIndex == 12 && gCurrentPinballGame->pondAnimSubFrame == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->pondAnimIndex == 29)
                RequestBoardTransition(5);

            if (gCurrentPinballGame->pondAnimIndex == 28)
                m4aSongNumStart(SE_UNKNOWN_0x92);
        }

        sp0 = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][0];
    }

    group->baseX = gCurrentPinballGame->pondSpriteXQ10 / 10 - gCurrentPinballGame->bgScrollXCopy;
    if (gCurrentPinballGame->pondAnimState > 0)
    {
        if (gCurrentPinballGame->pondAnimIndex == 32 && gCurrentPinballGame->pondAnimSubFrame > 208)
        {
            var0 = (0x100 - gCurrentPinballGame->pondAnimSubFrame) / 16;
            if (gMain.systemFrameCount & ((var0 + 1) * 2))
                group->baseY = gCurrentPinballGame->pondSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->pondSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
        }
    }
    else
    {
        group->baseY = 200;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B4D4E[sp0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[51];
    if (group->available)
    {
        group->baseX = 192 - gCurrentPinballGame->bgScrollXCopy;
        if (gCurrentPinballGame->cyndaquilAnimPhase > 2 && gMain.modeChangeFlags)
            group->baseY = 56 - gCurrentPinballGame->bgScrollYWithOffset;
        else
            group->baseY = 200;

        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateSapphireSeedotCollectionLogic(void)
{
    s16 i;
    s16 var0;

    if (gCurrentPinballGame->seedotHitFlag)
    {
        if (gCurrentPinballGame->boardState != 7)
        {
            if (gCurrentPinballGame->boardState < 3)
            {
                if (gCurrentPinballGame->rubyPondStage < 3)
                {
                    gCurrentPinballGame->seedotOffsetY[gCurrentPinballGame->rubyPondStage] = -100;
                    gCurrentPinballGame->seedotOamFrame[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->seedotAnimPhase[gCurrentPinballGame->rubyPondStage] = 1;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->rubyPondStage++;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    if (gCurrentPinballGame->rubyPondStage == 3)
                        gCurrentPinballGame->pondBannerTriggerDelay = 1;
                }
            }
            else
            {
                if (gCurrentPinballGame->rubyPondStage < 2)
                {
                    gCurrentPinballGame->seedotOffsetY[gCurrentPinballGame->rubyPondStage] = -100;
                    gCurrentPinballGame->seedotOamFrame[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->seedotAnimPhase[gCurrentPinballGame->rubyPondStage] = 1;
                    gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->rubyPondStage] = 0;
                    gCurrentPinballGame->seedotDecayTimer = 1800;
                    gCurrentPinballGame->rubyPondStage++;
                }
            }
        }

        gCurrentPinballGame->seedotHitFlag = 0;
        gCurrentPinballGame->scoreAddedInFrame = 3000;
    }

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->seedotAnimPhase[i])
        {
        case 0:
            gCurrentPinballGame->seedotOffsetY[i] = -100;
            gCurrentPinballGame->seedotOamFrame[i] = 0;
            gCurrentPinballGame->seedotAnimTimer[i] = 0;
            break;
        case 1:
            if (gCurrentPinballGame->seedotAnimTimer[i] < 33)
            {
                if (gCurrentPinballGame->seedotAnimTimer[i] == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xE9);

                if (gCurrentPinballGame->seedotAnimTimer[i] == 26)
                    m4aSongNumStart(SE_UNKNOWN_0xEA);

                gCurrentPinballGame->seedotAnimTimer[i]++;
                if (gCurrentPinballGame->seedotAnimTimer[i] < 21)
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 0;
                    gCurrentPinballGame->seedotOffsetY[i] = gCurrentPinballGame->seedotAnimTimer[i] * 4 - 80;
                    if (gCurrentPinballGame->seedotAnimTimer[i] == 20)
                        gCurrentPinballGame->basketShakeTimer = 23;
                }
                else if (gCurrentPinballGame->seedotAnimTimer[i] < 25)
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 1;
                }
                else
                {
                    gCurrentPinballGame->seedotSpriteFrame[i] = 2;
                }
            }
            else
            {
                gCurrentPinballGame->seedotAnimPhase[i] = 2;
                gCurrentPinballGame->seedotAnimTimer[i] = 0;
                if (i == 2)
                    RequestBoardTransition(7);
            }
            break;
        case 2:
            gCurrentPinballGame->seedotSpriteFrame[i] = (((gCurrentPinballGame->gameFrameCount % 32) / 16) * 2) + 1;
            if (gCurrentPinballGame->seedotSpriteFrame[i] == 1)
                gCurrentPinballGame->seedotOffsetY[i] = -2;
            else
                gCurrentPinballGame->seedotOffsetY[i] = 0;
            break;
        case 3:
            var0 = gCurrentPinballGame->seedotAnimTimer[i];
            if (var0 < 32)
            {
                gCurrentPinballGame->seedotSpriteFrame[i] = var0 / 16 + 4;
                gCurrentPinballGame->seedotOamFrame[i] = var0 / 16 + 1;
            }
            else if (var0 < 38)
            {
                if (var0 == 32 && (gMain.modeChangeFlags & MODE_CHANGE_END_OF_GAME) == 0)
                    m4aSongNumStart(SE_UNKNOWN_0xEB);

                gCurrentPinballGame->seedotSpriteFrame[i] = 6;
                gCurrentPinballGame->seedotOamFrame[i] = 3;
            }
            else if (var0 < 46)
            {
                gCurrentPinballGame->seedotOamFrame[i] = 4;
            }
            else if (var0 < 54)
            {
                gCurrentPinballGame->seedotOamFrame[i] = 5;
            }
            else
            {
                gCurrentPinballGame->seedotAnimPhase[i] = 0;
            }

            gCurrentPinballGame->seedotAnimTimer[i]++;
            break;
        }
    }

    if (gCurrentPinballGame->basketShakeTimer)
    {
        gCurrentPinballGame->basketSpriteFrame = gUnknown_086AE54A[gCurrentPinballGame->basketShakeTimer / 6];
        gCurrentPinballGame->basketShakeTimer--;
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
    if (gCurrentPinballGame->pondStageTransitionActive)
    {
        var0 = gCurrentPinballGame->pondTransitionFrame++;
        if (var0 <= 60)
        {
            if (var0 % 30 == 0)
            {
                if (gCurrentPinballGame->seedotAnimPhase[var0 / 30] == 2)
                {
                    gCurrentPinballGame->seedotAnimPhase[var0 / 30] = 3;
                    gCurrentPinballGame->seedotAnimTimer[var0 / 30] = 0;
                }
            }
        }
        else
        {
            gCurrentPinballGame->pondStageTransitionActive = 0;
            gCurrentPinballGame->pondTransitionFrame = 0;
        }
    }

    if (gCurrentPinballGame->seedotDecayTimer)
    {
        gCurrentPinballGame->seedotDecayTimer--;
        if (gCurrentPinballGame->seedotDecayTimer == 0)
        {
            if (gCurrentPinballGame->rubyPondStage == 1 || gCurrentPinballGame->rubyPondStage == 2)
            {
                gCurrentPinballGame->rubyPondStage--;
                gCurrentPinballGame->seedotAnimPhase[gCurrentPinballGame->rubyPondStage] = 3;
                gCurrentPinballGame->seedotAnimTimer[gCurrentPinballGame->rubyPondStage] = 0;
                gCurrentPinballGame->seedotDecayTimer = 1800;
            }
        }
    }
}

void DrawSapphireSeedotSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    int var0;

    group = &gMain.spriteGroups[64];
    if (!group->available)
        return;

    group->baseX = 10 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 298 - gCurrentPinballGame->bgScrollYWithOffset;
    index = gCurrentPinballGame->basketSpriteFrame;
    DmaCopy16(3, gSapphireStageBasket_Gfx[index], (void *)0x060139A0, 0x280);

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[68];
    group->baseX = 10 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = 298 - gCurrentPinballGame->bgScrollYWithOffset;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    for (j = 0; j < 3; j++)
    {
        group = &gMain.spriteGroups[65 + j];

        var0 = gUnknown_086AE544[j] - j;
        group->baseX = var0 - gCurrentPinballGame->bgScrollXCopy;
        if (gCurrentPinballGame->seedotAnimPhase[j] > 0)
            group->baseY = gCurrentPinballGame->seedotOffsetY[j] + 292 - gCurrentPinballGame->bgScrollYWithOffset;
        else
            group->baseY = 200;

        DmaCopy16(3, gSapphireBoardSeedot_Gfx[gCurrentPinballGame->seedotSpriteFrame[j]], (void *)0x06013C20 + j * 0x180, 0x160);
        index = gCurrentPinballGame->seedotOamFrame[j];
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gSapphireBoardSeedotSpritesheetOam[j][index][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }
}

void UpdateSapphireTrapDoorAnimation(void)
{
    if (gCurrentPinballGame->trapDoorAnimActive == 0)
    {
        if (gCurrentPinballGame->trapDisplayState == 1)
        {
            if (gCurrentPinballGame->slotReelFrame < 96)
            {
                if (gCurrentPinballGame->slotReelFrame < 8)
                    gCurrentPinballGame->pondSpriteFrame = gUnknown_08137CF6[1][gCurrentPinballGame->slotReelFrame / 2];
                else
                    gCurrentPinballGame->pondSpriteFrame = gUnknown_08137CE2[1][(gCurrentPinballGame->slotReelFrame % 32) / 8];

                gCurrentPinballGame->slotReelFrame++;
            }
            else
            {
                gCurrentPinballGame->slotReelFrame = 0;
            }

            gCurrentPinballGame->pondPaletteVariant = 2;
        }
        else
        {
            if (gCurrentPinballGame->slotReelFrame < 120)
            {
                if (gCurrentPinballGame->slotReelFrame < 8)
                    gCurrentPinballGame->pondSpriteFrame = gUnknown_08137CF6[0][gCurrentPinballGame->slotReelFrame / 2];
                else
                    gCurrentPinballGame->pondSpriteFrame = gUnknown_08137CE2[0][(gCurrentPinballGame->slotReelFrame % 40) / 8];

                gCurrentPinballGame->slotReelFrame++;
            }
            else
            {
                gCurrentPinballGame->slotReelFrame = 0;
            }

            gCurrentPinballGame->pondPaletteVariant = 0;
        }

        if (gCurrentPinballGame->savedEvoHitCount > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->trapDisplayState == 0)
            {
                gCurrentPinballGame->trapDoorAnimActive = 1;
                gCurrentPinballGame->slotReelFrame = 0;
                gCurrentPinballGame->trapDisplayState = 1;
            }
        }
        else
        {
            if (gCurrentPinballGame->boardState != 6 && gCurrentPinballGame->trapDisplayState == 1)
            {
                gCurrentPinballGame->trapDoorAnimActive = 1;
                gCurrentPinballGame->slotReelFrame = 0;
                gCurrentPinballGame->trapDisplayState = 0;
            }
        }
    }
    else
    {
        gCurrentPinballGame->pondSpriteFrame = gUnknown_08137D06[gCurrentPinballGame->trapDisplayState][gCurrentPinballGame->slotReelFrame / 3];
        if (gCurrentPinballGame->pondSpriteFrame >= 4 && gCurrentPinballGame->pondSpriteFrame < 6)
        {
            gCurrentPinballGame->pondPaletteVariant = 1;
        }
        else
        {
            if (gCurrentPinballGame->trapDisplayState == 1)
            {
                if (gCurrentPinballGame->slotReelFrame < 15)
                    gCurrentPinballGame->pondPaletteVariant = 0;
                else
                    gCurrentPinballGame->pondPaletteVariant = 2;
            }
            else
            {
                if (gCurrentPinballGame->slotReelFrame < 15)
                    gCurrentPinballGame->pondPaletteVariant = 2;
                else
                    gCurrentPinballGame->pondPaletteVariant = 0;
            }
        }

        gCurrentPinballGame->slotReelFrame++;
        if (gCurrentPinballGame->slotReelFrame == 42)
        {
            gCurrentPinballGame->trapDoorAnimActive = 0;
            gCurrentPinballGame->slotReelFrame = 0;
        }
    }
}
