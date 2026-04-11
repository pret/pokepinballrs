#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern struct SongHeader se_evo_item_appear;
extern struct SongHeader se_evo_item_finish_appear;
extern struct SongHeader se_evo_item_collected;

extern const u8 gDefaultBallPalette[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const u8 gEvoItemPalettes[][0x20];
extern const s16 gEvoItemAppearFrameThresholds[];
extern const u16 gEvoItemAnimOamFramesets[58][15];
extern const struct Vector16 gEvoItemPositions[][8];

void CleanupEvolutionModeState(void)
{
    s16 i;

    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->evoItemCount)
            gCurrentPinballGame->catchLights[i] = 1;
        else
            gCurrentPinballGame->catchLights[i] = 0;
    }

    gMain.fieldSpriteGroups[13]->available = 0;
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = 0;
    ResetEventState();
}

void InitEvolutionMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardModeType = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->saverTimeRemaining = 3600;
    if (gCurrentPinballGame->currentSpecies == SPECIES_WURMPLE)
    {
        gCurrentPinballGame->evoItemGfxIndex = 0;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_GLOOM)
    {
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->evoItemGfxIndex = 1;
        else
            gCurrentPinballGame->evoItemGfxIndex = 7;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_CLAMPERL)
    {
        gCurrentPinballGame->evoItemGfxIndex = 3;
    }
    else
    {
        gCurrentPinballGame->evoItemGfxIndex = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod - 1;
        if (gCurrentPinballGame->evoItemGfxIndex < 0)
            gCurrentPinballGame->evoItemGfxIndex = 0;
    }

    DmaCopy16(3, gDefaultBallPalette, (void *)0x05000180, 0x20);
    gCurrentPinballGame->evoArrowProgress = 0;
    gCurrentPinballGame->shopArrowActive = 0;
    gCurrentPinballGame->catchModeEventTimer = 0;
    gCurrentPinballGame->evoItemSlotIndex = 0;
    gCurrentPinballGame->evoItemsCaught = 0;
    gCurrentPinballGame->evoModeResetFlag = 0;
    gCurrentPinballGame->evoItemAppearTimer = 0;
    LoadPortraitGraphics(3, 0);
}

void UpdateEvolutionMode(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    if (gCurrentPinballGame->boardModeType && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 8)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = 8;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        if (gCurrentPinballGame->evoModeShuffleRound < 2)
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = i;

            index = (Random() + gMain.systemFrameCount) % 5;
            gCurrentPinballGame->evoShuffledSlots[0] = gCurrentPinballGame->evoItemShufflePool[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = gCurrentPinballGame->evoItemShufflePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 4;
            gCurrentPinballGame->evoShuffledSlots[1] = gCurrentPinballGame->evoItemShufflePool[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = gCurrentPinballGame->evoItemShufflePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 3;
            gCurrentPinballGame->evoShuffledSlots[2] = gCurrentPinballGame->evoItemShufflePool[index];
        }
        else
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = i;

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->evoShuffledSlots[0] = gCurrentPinballGame->evoItemShufflePool[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = gCurrentPinballGame->evoItemShufflePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 7;
            gCurrentPinballGame->evoShuffledSlots[1] = gCurrentPinballGame->evoItemShufflePool[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = gCurrentPinballGame->evoItemShufflePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->evoShuffledSlots[2] = gCurrentPinballGame->evoItemShufflePool[index];
            for (i = index; i < 5; i++)
                gCurrentPinballGame->evoItemShufflePool[i] = gCurrentPinballGame->evoItemShufflePool[i + 1];

            if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->numCompletedBonusStages < 5)
            {
                for (i = 0; i < 3; i++)
                {
                    if (gCurrentPinballGame->evoShuffledSlots[i] == 5)
                    {
                        index = (Random() + gMain.systemFrameCount) % 5;
                        gCurrentPinballGame->evoShuffledSlots[i] = gCurrentPinballGame->evoItemShufflePool[index];
                    }
                }
            }
        }

        gCurrentPinballGame->evoModeShuffleRound++;
        gCurrentPinballGame->boardSubState++;
        break;
    case 1:
        gCurrentPinballGame->evoItemSlotIndex = gCurrentPinballGame->evoShuffledSlots[gCurrentPinballGame->evoItemsCaught];
        gCurrentPinballGame->evoItemPosX = gEvoItemPositions[gMain.selectedField][gCurrentPinballGame->evoItemSlotIndex].x;
        gCurrentPinballGame->evoItemPosY = gEvoItemPositions[gMain.selectedField][gCurrentPinballGame->evoItemSlotIndex].y;
        gCurrentPinballGame->evoItemAppearTimer = 80;
        gMain.fieldSpriteGroups[40]->available = 1;
        gCurrentPinballGame->boardSubState++;
        break;
    case 2:
        UpdateEvolutionItemAnimation();
        gCurrentPinballGame->stageTimer = 0;
        break;
    case 3:
        gCurrentPinballGame->trapAnimState = 1;
        if (gCurrentPinballGame->stageTimer < 8)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            ShowBonusTrapSprite();
            gCurrentPinballGame->trapAnimState = 2;
            gCurrentPinballGame->boardSubState++;
        }
        break;
    case 4:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 5:
        gCurrentPinballGame->boardModeType = 3;
        gCurrentPinballGame->preEvoSpecies = gCurrentPinballGame->currentSpecies;
        RegisterCaptureOrEvolution(1);
        gCurrentPinballGame->postEvoSpecies = gCurrentPinballGame->currentSpecies;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 6:
        if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (gMain.spriteGroups[13].available)
            {
                if (gCurrentPinballGame->chikoritaProjectileTimer >= 80)
                {
                    RunEvolutionCutscene();
                    if (gCurrentPinballGame->boardSubState == 6)
                        gCurrentPinballGame->stageTimer++;
                }
            }
            else
            {
                RunEvolutionCutscene();
                if (gCurrentPinballGame->boardSubState == 6)
                    gCurrentPinballGame->stageTimer++;
            }
        }
        break;
    case 7:
        if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (gCurrentPinballGame->stageTimer < 280)
            {
                if (gCurrentPinballGame->stageTimer == 0)
                {
                    InitEvolutionSuccessDisplay();
                    m4aSongNumStart(MUS_SUCCESS2);
                }
                else
                {
                    AnimateEvolutionSuccessScreen();
                    if (gCurrentPinballGame->stageTimer < 230)
                    {
                        if (gCurrentPinballGame->nameRevealAnimFrame == 150)
                            gCurrentPinballGame->nameRevealAnimFrame--;
                    }

                    if (gCurrentPinballGame->stageTimer == 270)
                    {
                        LoadPortraitGraphics(0, 0);
                        gCurrentPinballGame->portraitDisplayState = 0;
                    }

                    if (gCurrentPinballGame->scoreCounterAnimationEnabled)
                        gCurrentPinballGame->stageTimer = 181;

                    if (gCurrentPinballGame->stageTimer == 180) {
                        gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                        gCurrentPinballGame->scoreAddedInFrame = 5000000;
                    }
                }

                if (gCurrentPinballGame->stageTimer < 30)
                {
                    gMain.scoreOverlayActive = 1;
                    var0 = gCurrentPinballGame->stageTimer;
                    gCurrentPinballGame->cutsceneTilemapColumn = gCurrentPinballGame->stageTimer;
                    for (i = 0; i <= var0; i++)
                    {
                        for (j = 2; j < 12; j++)
                            gBG0TilemapBuffer[((j + 15) * 0x20) + i] = 0xC100;
                    }

                    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
                }

                if (gCurrentPinballGame->stageTimer >= 240 && gCurrentPinballGame->stageTimer < 270)
                {
                    var0 = gCurrentPinballGame->stageTimer - 240;
                    for (i = 0; i <= var0; i ++)
                    {
                        for (j = 2; j < 12; j++)
                            gBG0TilemapBuffer[((j + 15) << 5) + i] = 0x1FF;
                    }

                    DmaCopy16(3, gBG0TilemapBuffer, (void *)0x06002000, 0x800);
                    if (gCurrentPinballGame->stageTimer == 269)
                    {
                        gMain.scoreOverlayActive = 0;
                        gMain.blendControl = 0;
                        gMain.blendBrightness = 0;
                        gMain.blendAlpha = 0;
                    }
                }

                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->modeAnimTimer = 40;
            }
        }
        else if (gCurrentPinballGame->modeAnimTimer == 24)
        {
            if (gCurrentPinballGame->evoItemCount < 3)
            {
                gCurrentPinballGame->evoCatchLightSlot1 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->evoCatchLightSlot2 = gCurrentPinballGame->evoItemCount;
                gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot1] = 1;
                gCurrentPinballGame->evoBlinkTimer = 120;
                gCurrentPinballGame->evoItemCount++;
                if (gCurrentPinballGame->evoItemCount < 3)
                {
                    gCurrentPinballGame->evoCatchLightSlot2 = gCurrentPinballGame->evoItemCount;
                    gCurrentPinballGame->catchLights[gCurrentPinballGame->evoCatchLightSlot2] = 1;
                    gCurrentPinballGame->evoBlinkTimer = 120;
                    gCurrentPinballGame->evoItemCount++;
                }
            }

            if (gCurrentPinballGame->currentSpecies == SPECIES_NINJASK)
            {
                gCurrentPinballGame->caughtMonCount++;
                if (gCurrentPinballGame->bonusMonCatchCount < 99)
                    gCurrentPinballGame->bonusMonCatchCount++;

                if (gCurrentPinballGame->caughtMonCount == 15)
                    gCurrentPinballGame->oneUpAnimTimer = 92;
            }

            gCurrentPinballGame->caughtMonCount++;
            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 92;

            if (gCurrentPinballGame->bonusMonCatchCount < 99)
                gCurrentPinballGame->bonusMonCatchCount++;

            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 8:
        group = gMain.fieldSpriteGroups[32];
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 56;

        gMain.fieldSpriteGroups[32]->available = 0;
        UpdateEvolutionItemAnimation();
        gMain.fieldSpriteGroups[40]->available = 0;
        gCurrentPinballGame->activePortraitType = 0;
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[13]->available = 0;
        gCurrentPinballGame->shopTransitionActive = 1;
        gCurrentPinballGame->shopAnimTimer = 0;
        gCurrentPinballGame->evolutionShopActive = 0;
        gCurrentPinballGame->boardSubState++;
        if (gCurrentPinballGame->allHolesLit)
            gCurrentPinballGame->allHolesLitDelayTimer = 120;
        break;
    case 9:
        CleanupEvolutionModeState();
        gCurrentPinballGame->boardSubState++;
        break;
    case 10:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(3);
            else
                RequestBoardStateTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

void UpdateEvolutionItemAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    index = (gMain.systemFrameCount % 75) / 3;
    group = gMain.fieldSpriteGroups[32];
    if (gCurrentPinballGame->evoItemAppearTimer)
    {
        group = gMain.fieldSpriteGroups[40];
        if (gCurrentPinballGame->evoItemAppearTimer == 80)
        {
            gCurrentPinballGame->activePortraitType = 15;
            DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemGfxIndex], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, &gEvoItemPalettes[gCurrentPinballGame->evoItemGfxIndex], (void *)0x050003E0, 0x20);
            gCurrentPinballGame->evoItemAnimFrame = 0;
            gCurrentPinballGame->evoItemAnimFrameTimer = 0;
        }

        if (gCurrentPinballGame->evoItemAppearTimer == 60)
            MPlayStart(&gMPlayInfo_SE1, &se_evo_item_appear);

        if (gEvoItemAppearFrameThresholds[gCurrentPinballGame->evoItemAnimFrame] > gCurrentPinballGame->evoItemAnimFrameTimer)
        {
            gCurrentPinballGame->evoItemAnimFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->evoItemAnimFrameTimer = 1;
            gCurrentPinballGame->evoItemAnimFrame++;
            if (gCurrentPinballGame->evoItemAnimFrame == 29)
            {
                gCurrentPinballGame->evoItemAnimFrame = 28;
                gCurrentPinballGame->evoItemAppearTimer = 1;
                gMain.fieldSpriteGroups[40]->available = 0;
                gMain.fieldSpriteGroups[32]->available = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_evo_item_finish_appear);
                gCurrentPinballGame->activePortraitType = 0;
            }
        }

        group->baseX = gCurrentPinballGame->evoItemPosX - gCurrentPinballGame->cameraXOffset + 8;
        group->baseY = gCurrentPinballGame->evoItemPosY - gCurrentPinballGame->cameraYOffset + 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gEvoItemAnimOamFramesets[gCurrentPinballGame->evoItemAnimFrame][i * 3 + 0];
            *dst++ = gEvoItemAnimOamFramesets[gCurrentPinballGame->evoItemAnimFrame][i * 3 + 1];
            *dst++ = gEvoItemAnimOamFramesets[gCurrentPinballGame->evoItemAnimFrame][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        gCurrentPinballGame->evoItemAppearTimer--;
    }
    else
    {
        tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->evoItemPosX + 8);
        tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->evoItemPosY + 8);
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (squaredMagnitude < 82 &&
            ((gCurrentPinballGame->boardLayerDepth == 0 && gCurrentPinballGame->evoItemSlotIndex <= 5) || (gCurrentPinballGame->boardLayerDepth == 2 && gCurrentPinballGame->evoItemSlotIndex > 5)) &&
            gCurrentPinballGame->evoItemsCaught < 3)
        {
            gCurrentPinballGame->scoreAddedInFrame = 10000;
            MPlayStart(&gMPlayInfo_SE1, &se_evo_item_collected);
            gCurrentPinballGame->boardSubState = 1;
            gCurrentPinballGame->catchLights[gCurrentPinballGame->evoItemsCaught] = 5;
            gCurrentPinballGame->evoItemsCaught++;
            gMain.fieldSpriteGroups[32]->available = 0;
            if (gCurrentPinballGame->evoItemsCaught == 3)
            {
                gCurrentPinballGame->evoItemsCaught = 0;
                gCurrentPinballGame->boardSubState = 3;
            }
        }

        group->baseX = gCurrentPinballGame->evoItemPosX - gCurrentPinballGame->cameraXOffset - 8;
        group->baseY = gCurrentPinballGame->evoItemPosY - gCurrentPinballGame->cameraYOffset - 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        if (index > 14)
            index = 14;

        DmaCopy16(3, gEvoItemTilesGfxPtrs[gCurrentPinballGame->evoItemGfxIndex] + index * 0x200, (void *)0x060116C0, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}
