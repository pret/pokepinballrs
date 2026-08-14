#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/ruby_states.h"

#define BALL_FIRST_LAUNCH_SAVER_TIME TICKS_FOR_TIME(1,0)

extern const s16 gAreaRouletteTable[][AREA_TABLE_SLOT_COUNT];
extern const s16 gAreaPortraitIndexes[];
extern const u16 gAreaRouletteOamFramesets[18][27];
extern const Palette gTravelPortrait_Pal;

extern const u8 gAreaRouletteSelectedFx_Gfx[];
extern const s16 gPondBumperRetractFrames[];
extern const s16 gBoardArrowAnimFrames[];


void InitBoardIntroMode(void)
{
    s16 i;

    gCurrentPinballGame->boardSubState = BOARD_INTRO_SUBSTATE_SETUP_GRAPHICS;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->creatureOamPriority = 3;
    gCurrentPinballGame->areaVisitCount = 0;
    gCurrentPinballGame->areaRouletteSlotIndex = (Random() + gMain.systemFrameCount) % AREA_ROULETTE_SLOT_COUNT;
    gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][gCurrentPinballGame->areaRouletteSlotIndex];
    gCurrentPinballGame->areaRoulettePortraitIndex[1] = gAreaPortraitIndexes[gCurrentPinballGame->area];
    gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][(gCurrentPinballGame->areaRouletteSlotIndex + 1) % AREA_ROULETTE_SLOT_COUNT];
    gCurrentPinballGame->areaRoulettePortraitIndex[0] = gAreaPortraitIndexes[gCurrentPinballGame->area];
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
    LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_ALT_SLOT);
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->catchTilePalette[i] = 13;

    DmaCopy16(3, gTravelPortrait_Pal, OBJ_PLTT_SLOT(14), PLTT_SLOT_SIZE);
    DmaCopy16(3, gAreaRouletteSelectedFx_Gfx, (void *)0x06015800, 0x280);
    gCurrentPinballGame->activePortraitType = 12;
}

void UpdateBoardIntroMode(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->boardSubState)
    {
    case BOARD_INTRO_SUBSTATE_SETUP_GRAPHICS:
        gMain.blendControl = 0x1C10;
        gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->rouletteSubOffset = 0;
        gCurrentPinballGame->cameraScrollTarget = 0;
        gCurrentPinballGame->cameraScrollEnabled = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_PORTRAIT]->active = TRUE;
        gMain.fieldSpriteGroups[FIELD_SG_MAIN_BOARD_PORTRAIT_BORDERS]->active = TRUE;
        gCurrentPinballGame->rouletteFrameIndex = 30;
        gCurrentPinballGame->rouletteRotationPeriod = 30;
        gCurrentPinballGame->rouletteSpinSpeed = 0;
        if (gMain.selectedField == FIELD_RUBY)
        {
            gCurrentPinballGame->pondBumperStates[0] = 10;
            gCurrentPinballGame->pondBumperStates[1] = 10;
            gCurrentPinballGame->pondBumperStates[2] = 10;
        }
        else
        {
            gCurrentPinballGame->pondBumperStates[0] = 0;
            gCurrentPinballGame->pondBumperStates[1] = 0;
            gCurrentPinballGame->pondBumperStates[2] = 0;
        }
        gCurrentPinballGame->rubyPondChangeTimer = 0;
        break;
    case BOARD_INTRO_SUBSTATE_SCROLL:
        if (gCurrentPinballGame->cameraScrollOffset == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 143)
                gCurrentPinballGame->pondBumperStates[0] = gPondBumperRetractFrames[gCurrentPinballGame->rubyPondChangeTimer / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 18 && gCurrentPinballGame->rubyPondChangeTimer < 161)
                gCurrentPinballGame->pondBumperStates[2] = gPondBumperRetractFrames[(gCurrentPinballGame->rubyPondChangeTimer - 18) / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 36 && gCurrentPinballGame->rubyPondChangeTimer < 179)
                gCurrentPinballGame->pondBumperStates[1] = gPondBumperRetractFrames[(gCurrentPinballGame->rubyPondChangeTimer - 36) / 8];

            gCurrentPinballGame->rubyPondChangeTimer++;
        }

        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_ROULETTE;
        gCurrentPinballGame->stageTimer++;
        UpdateBoardArrowAnimState();
        break;
    case BOARD_INTRO_SUBSTATE_START_AREA_SPINNER:
        if (gCurrentPinballGame->stageTimer < 15)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 15)
            {
                gCurrentPinballGame->boardSubState++;
                gCurrentPinballGame->rouletteRotationPeriod = 6;
                gCurrentPinballGame->rouletteSpinSpeed = 0;
            }
        }
        SetBoardArrowState(0);
        /* fallthrough */
    case BOARD_INTRO_SUBSTATE_WAIT_FOR_LAUNCH:
    case BOARD_INTRO_SUBSTATE_AREA_SELECTION_STOPPING:
        if (gCurrentPinballGame->boardSubState == BOARD_INTRO_SUBSTATE_START_AREA_SPINNER)
        {
            gCurrentPinballGame->rouletteFrameIndex--;
            gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        }
        else if (gCurrentPinballGame->boardSubState == BOARD_INTRO_SUBSTATE_WAIT_FOR_LAUNCH)
        {
            gCurrentPinballGame->rouletteFrameIndex++;
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER]
                && gCurrentPinballGame->boardSubState == BOARD_INTRO_SUBSTATE_WAIT_FOR_LAUNCH)
            {
                if (gCurrentPinballGame->rouletteSpinSpeed == 0)
                {
                    if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                        gCurrentPinballGame->rouletteSpinSpeed = 48;
                    else
                        gCurrentPinballGame->rouletteSpinSpeed = 1;

                    gCurrentPinballGame->rouletteInitialSpeed = gCurrentPinballGame->rouletteSpinSpeed;
                    gCurrentPinballGame->spoinkEntityState = 1;
                    gCurrentPinballGame->launcherCharging = TRUE;
                    gCurrentPinballGame->saverTimeRemaining = BALL_FIRST_LAUNCH_SAVER_TIME;
                    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE;
                }
            }

            if (gCurrentPinballGame->rouletteSpinSpeed)
            {
                gCurrentPinballGame->rouletteSpinSpeed--;
                if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                {
                    gCurrentPinballGame->numCompletedBonusStages = 4;
                    if (gCurrentPinballGame->rouletteSpinSpeed < 24)
                    {
                        gCurrentPinballGame->rouletteSpinSpeed = 24;
                        if (gCurrentPinballGame->areaRouletteSlotIndex == AREA_BONUS_RUIN_SLOT_IX)
                            gCurrentPinballGame->rouletteSpinSpeed = 0;
                    }
                }

                if (gCurrentPinballGame->rouletteSpinSpeed == 0)
                {
                    gCurrentPinballGame->boardSubState = BOARD_INTRO_SUBSTATE_AREA_SELECTION_STOPPING;
                }
                else
                {
                    if (gCurrentPinballGame->rouletteFrameIndex == gCurrentPinballGame->rouletteRotationPeriod)
                    {
                        gCurrentPinballGame->rouletteRotationPeriod = 40 - (gCurrentPinballGame->rouletteSpinSpeed * 30) / gCurrentPinballGame->rouletteInitialSpeed;
                        gCurrentPinballGame->rouletteFrameIndex = 0;
                    }
                }
            }

            gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        }
        else
        {
            gCurrentPinballGame->rouletteFrameIndex++;
            gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
            if (gCurrentPinballGame->rouletteFrameIndex == 0)
            {
                gCurrentPinballGame->stageTimer = 0;
                gCurrentPinballGame->boardSubState++;
                gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT0_TRIM]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_PORTRAIT1_TRIM]->active = FALSE;
                gMain.fieldSpriteGroups[FIELD_SG_INITIAL_LOCATION_SELECTED_FX]->active = TRUE;
                m4aSongNumStart(SE_AREA_ROULETTE_SELECTED);
            }
        }

        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        if (gCurrentPinballGame->rouletteFrameIndex == 0)
        {
            gCurrentPinballGame->areaRoulettePortraitIndex[0] = gCurrentPinballGame->areaRoulettePortraitIndex[1];
            LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_MAIN_SLOT);
        }

        if (gCurrentPinballGame->rouletteFrameIndex == 1)
        {
            if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
            {
                gCurrentPinballGame->areaRouletteSlotIndex = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % AREA_TABLE_SLOT_COUNT;
                gCurrentPinballGame->areaRouletteNextSlot = 0;
                gCurrentPinballGame->areaRouletteFarSlot = 1;
            }
            else
            {
                gCurrentPinballGame->areaRouletteSlotIndex = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % AREA_ROULETTE_SLOT_COUNT;
                gCurrentPinballGame->areaRouletteNextSlot = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % AREA_ROULETTE_SLOT_COUNT;
                gCurrentPinballGame->areaRouletteFarSlot = (gCurrentPinballGame->areaRouletteSlotIndex + 2) % AREA_ROULETTE_SLOT_COUNT;
            }

            gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][gCurrentPinballGame->areaRouletteSlotIndex];
            gCurrentPinballGame->areaRoulettePortraitIndex[1] = gAreaPortraitIndexes[gCurrentPinballGame->area];
            LoadPortraitGraphics(PORTRAIT_STATE_CURRENT_LOCATION, PORTRAIT_ALT_SLOT);
            m4aSongNumStart(SE_ROULETTE_TICK);
        }
        break;
    case BOARD_INTRO_SUBSTATE_AREA_SELECTED_FX:
        if (gCurrentPinballGame->stageTimer < 50)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 50)
            {
                gCurrentPinballGame->boardSubState = DEFAULT_MODE_SUBSTATE_INIT;
                RequestBoardStateTransition(MAIN_BOARD_STATE_DEFAULT);
            }
        }

        if (gCurrentPinballGame->stageTimer < 29)
        {
            if (gCurrentPinballGame->stageTimer < 8)
                var0 = gCurrentPinballGame->stageTimer / 4;
            else
                var0 = ((gCurrentPinballGame->stageTimer - 8) / 3) + 2;

            group = gMain.fieldSpriteGroups[FIELD_SG_INITIAL_LOCATION_SELECTED_FX];
            if (group->active)
            {
                group->baseX = 96u - gCurrentPinballGame->cameraXOffset;
                group->baseY = gCurrentPinballGame->rouletteSubOffset + 300u - gCurrentPinballGame->cameraYOffset;
                if (group->baseY >= 200)
                    group->baseY = 200;

                for (i = 0; i < 9; i++)
                {
                    oamSimple = &group->oam[i];
                    dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gAreaRouletteOamFramesets[var0][i * 3 + 0];
                    *dst++ = gAreaRouletteOamFramesets[var0][i * 3 + 1];
                    *dst++ = gAreaRouletteOamFramesets[var0][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                }
            }

            if (gCurrentPinballGame->stageTimer == 28) {
                gMain.fieldSpriteGroups[FIELD_SG_INITIAL_LOCATION_SELECTED_FX]->active = FALSE;
                gCurrentPinballGame->activePortraitType = 0;
            }
        }

        gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BOARD_CENTER;
        break;
    }
}

void UpdateBoardArrowAnimState(void)
{
    s16 index;

    index = (gMain.systemFrameCount % 100) / 10;
    gCurrentPinballGame->hudAnimFrameCounter = 0;
    gCurrentPinballGame->catchArrowProgress = gBoardArrowAnimFrames[index];
    gCurrentPinballGame->evoArrowProgress = gBoardArrowAnimFrames[index];
    gCurrentPinballGame->coinRewardLevel = gBoardArrowAnimFrames[index];
    if (index == 7 || index == 9)
    {
        gCurrentPinballGame->catchArrowPaletteActive = TRUE;
        gCurrentPinballGame->shopArrowActive = TRUE;
        gCurrentPinballGame->evoArrowPaletteActive = TRUE;
    }
    else
    {
        gCurrentPinballGame->catchArrowPaletteActive = FALSE;
        gCurrentPinballGame->shopArrowActive = FALSE;
        gCurrentPinballGame->evoArrowPaletteActive = FALSE;
    }
}

void SetBoardArrowState(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->shopArrowActive = TRUE;
        gCurrentPinballGame->catchArrowPaletteActive = TRUE;
        gCurrentPinballGame->catchProgressFlashing = TRUE;
        gCurrentPinballGame->evoArrowProgress = 3;
        gCurrentPinballGame->coinRewardLevel = 3;
        gCurrentPinballGame->catchArrowProgress = 3;
        gCurrentPinballGame->evoArrowPaletteActive = TRUE;
    }
    else
    {
        gCurrentPinballGame->evoArrowPaletteActive = FALSE;
        gCurrentPinballGame->shopArrowActive = FALSE;
        gCurrentPinballGame->catchArrowPaletteActive = FALSE;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->coinRewardLevel = 0;
        gCurrentPinballGame->catchArrowProgress = 2;
    }

    gCurrentPinballGame->progressLevel = 1;
}
