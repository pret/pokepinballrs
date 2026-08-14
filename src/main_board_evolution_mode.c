#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/main_board.h"

#define EVO_MODE_TIME TICKS_FOR_TIME(2,0)
#define EVO_SAVER_TIME TICKS_FOR_TIME(1,0)

extern struct SongHeader se_evo_item_appear;
extern struct SongHeader se_evo_item_finish_appear;
extern struct SongHeader se_evo_item_collected;

extern const Palette gTimer_Default_Pal;
extern const u8 *gEvoItemAppear_GfxList[];
extern const Palette gEvoItem_Pals[];
extern const s16 gEvoItemAppearFrameThresholds[];
extern const u16 gEvoItemAnimOamFramesets[58][15];
extern const struct Vector16 gEvoItemPositions[][8];

void CleanupEvolutionModeState(void)
{
    s16 i;

    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->evoItemCount)
            gCurrentPinballGame->catchLights[i] = 1;
        else
            gCurrentPinballGame->catchLights[i] = 0;
    }

    gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = FALSE;
    ResetEventState();
}

void InitEvolutionMode(void)
{
    gCurrentPinballGame->boardSubState = EVOLUTION_SUBSTATE_SHUFFLE_EVO_ITEM_PLACEMENTS;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + EVO_MODE_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->saverTimeRemaining = EVO_SAVER_TIME;
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

    DmaCopy16(3, gTimer_Default_Pal, BG_PLTT_SLOT(12), PLTT_SLOT_SIZE);
    gCurrentPinballGame->evoArrowProgress = 0;
    gCurrentPinballGame->shopArrowActive = FALSE;
    gCurrentPinballGame->catchModeEventTimer = 0;
    gCurrentPinballGame->evoItemSlotIndex = 0;
    gCurrentPinballGame->evoItemsCaught = 0;
    gCurrentPinballGame->evoModeResetFlag = 0;
    gCurrentPinballGame->evoItemAppearTimer = 0;
    LoadPortraitGraphics(PORTRAIT_STATE_POKEMON_DISPLAY, PORTRAIT_MAIN_SLOT);
}

void UpdateEvolutionMode(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    if (gCurrentPinballGame->eventTimerType
        && gCurrentPinballGame->eventTimer < 2
        && gCurrentPinballGame->boardSubState < EVOLUTION_SUBSTATE_END_EVO_PHASE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = EVOLUTION_SUBSTATE_END_EVO_PHASE;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case EVOLUTION_SUBSTATE_SHUFFLE_EVO_ITEM_PLACEMENTS:
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
    case EVOLUTION_SUBSTATE_PREP_SPAWN_EVO_ITEM:
        gCurrentPinballGame->evoItemSlotIndex = gCurrentPinballGame->evoShuffledSlots[gCurrentPinballGame->evoItemsCaught];
        gCurrentPinballGame->evoItemPosX = gEvoItemPositions[gMain.selectedField][gCurrentPinballGame->evoItemSlotIndex].x;
        gCurrentPinballGame->evoItemPosY = gEvoItemPositions[gMain.selectedField][gCurrentPinballGame->evoItemSlotIndex].y;
        gCurrentPinballGame->evoItemAppearTimer = 80;
        gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM_SPAWN_FX]->active = TRUE;
        gCurrentPinballGame->boardSubState++;
        break;
    case EVOLUTION_SUBSTATE_SPAWN_EVO_ITEM_AND_CHECK_FOR_COLLECTION:
        UpdateEvolutionItemAnimation();
        gCurrentPinballGame->stageTimer = 0;
        break;
    case EVOLUTION_SUBSTATE_OPEN_TRAP_DOOR:
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
    case EVOLUTION_SUBSTATE_GRAVITY_WELL:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == TRAP_CENTER_HOLE)
            gCurrentPinballGame->boardSubState++;
        break;
    case EVOLUTION_SUBSTATE_REGISTER_CAPTURE:
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;
        gCurrentPinballGame->preEvoSpecies = gCurrentPinballGame->currentSpecies;
        RegisterCaptureOrEvolution(1);
        gCurrentPinballGame->postEvoSpecies = gCurrentPinballGame->currentSpecies;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case EVOLUTION_SUBSTATE_EVOLVE_CUTSCENE:
        if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (gMain.spriteGroups[SG_RUBY_CHIKORITA_PROJECTILE].active)
            {
                if (gCurrentPinballGame->chikoritaProjectileTimer >= 80)
                {
                    RunEvolutionCutscene();
                    if (gCurrentPinballGame->boardSubState == EVOLUTION_SUBSTATE_EVOLVE_CUTSCENE)
                        gCurrentPinballGame->stageTimer++;
                }
            }
            else
            {
                RunEvolutionCutscene();
                if (gCurrentPinballGame->boardSubState == EVOLUTION_SUBSTATE_EVOLVE_CUTSCENE)
                    gCurrentPinballGame->stageTimer++;
            }
        }
        break;
    case EVOLUTION_SUBSTATE_SHOWCASE_EVOLVED_FORM:
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
                    AnimateWasCaughtBanner();
                    if (gCurrentPinballGame->stageTimer < 230)
                    {
                        if (gCurrentPinballGame->nameRevealAnimFrame == 150)
                            gCurrentPinballGame->nameRevealAnimFrame--;
                    }

                    if (gCurrentPinballGame->stageTimer == 270)
                    {
                        LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
                        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
                    }

                    if (gCurrentPinballGame->scoreCounterAnimationEnabled)
                        gCurrentPinballGame->stageTimer = 181;

                    if (gCurrentPinballGame->stageTimer == 180) {
                        gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                        gCurrentPinballGame->scoreAddedInFrame = SCORE_EVO_COMPLETED;
                    }
                }

                if (gCurrentPinballGame->stageTimer < 30)
                {
                    gMain.scoreOverlayActive = TRUE;
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
                        gMain.scoreOverlayActive = FALSE;
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
                if (gCurrentPinballGame->bonusMonEvoCount < 99)
                    gCurrentPinballGame->bonusMonEvoCount++;

                if (gCurrentPinballGame->caughtMonCount == 15)
                    gCurrentPinballGame->oneUpAnimTimer = 92;
            }

            gCurrentPinballGame->caughtMonCount++;
            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->oneUpAnimTimer = 92;

            if (gCurrentPinballGame->bonusMonEvoCount < 99)
                gCurrentPinballGame->bonusMonEvoCount++;

            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case EVOLUTION_SUBSTATE_END_EVO_PHASE:
        group = gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM];
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 56;

        gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM]->active = FALSE;
        UpdateEvolutionItemAnimation();
        gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM_SPAWN_FX]->active = FALSE;
        gCurrentPinballGame->activePortraitType = 0;
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[FIELD_SG_CENTER_HOLE_GRAVITY_FX]->active = FALSE;
        gCurrentPinballGame->shopTransitionActive = TRUE;
        gCurrentPinballGame->shopAnimTimer = 0;
        gCurrentPinballGame->evolutionShopActive = FALSE;
        gCurrentPinballGame->boardSubState++;
        if (gCurrentPinballGame->allHolesLit)
            gCurrentPinballGame->allHolesLitDelayTimer = 120;
        break;
    case EVOLUTION_SUBSTATE_BOARD_STATE_CLEANUP:
        CleanupEvolutionModeState();
        gCurrentPinballGame->boardSubState++;
        break;
    case EVOLUTION_SUBSTATE_PREPARE_NEXT_BOARD_MODE:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->catchLights[2] == 1)
                RequestBoardStateTransition(MAIN_BOARD_STATE_BOSS_HOLE_ACTIVE);
            else
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);

            gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
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
    int squaredDistance;
    s16 index;

    index = (gMain.systemFrameCount % 75) / 3;
    group = gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM];
    if (gCurrentPinballGame->evoItemAppearTimer)
    {
        group = gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM_SPAWN_FX];
        if (gCurrentPinballGame->evoItemAppearTimer == 80)
        {
            gCurrentPinballGame->activePortraitType = 15;
            DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemGfxIndex], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, gEvoItem_Pals[gCurrentPinballGame->evoItemGfxIndex], OBJ_PLTT_SLOT(15), PLTT_SLOT_SIZE);
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
                gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM_SPAWN_FX]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM]->active = TRUE;
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
        squaredDistance = xx + yy;
        if (squaredDistance < 82 &&
            ((gCurrentPinballGame->boardLayerDepth == 0 && gCurrentPinballGame->evoItemSlotIndex <= 5) || (gCurrentPinballGame->boardLayerDepth == 2 && gCurrentPinballGame->evoItemSlotIndex > 5)) &&
            gCurrentPinballGame->evoItemsCaught < 3)
        {
            gCurrentPinballGame->scoreAddedInFrame = SCORE_EVO_ITEM_COLLECTED;
            MPlayStart(&gMPlayInfo_SE1, &se_evo_item_collected);
            gCurrentPinballGame->boardSubState = EVOLUTION_SUBSTATE_PREP_SPAWN_EVO_ITEM;
            gCurrentPinballGame->catchLights[gCurrentPinballGame->evoItemsCaught] = 5;
            gCurrentPinballGame->evoItemsCaught++;
            gMain.fieldSpriteGroups[FIELD_SG_EVO_ITEM]->active = FALSE;
            if (gCurrentPinballGame->evoItemsCaught == 3)
            {
                gCurrentPinballGame->evoItemsCaught = 0;
                gCurrentPinballGame->boardSubState = EVOLUTION_SUBSTATE_OPEN_TRAP_DOOR;
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
