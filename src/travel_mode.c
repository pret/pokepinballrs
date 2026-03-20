#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const s16 gAreaRouletteTable[][7];
extern const s16 gAreaToSpeciesTable[];
extern const u16 gAreaRouletteOamFramesets[18][27];

extern const u8 gTravelPortraitPalette[];
extern const u8 gAreaRouletteSelectedFx_Gfx[];

extern const u8 gDefaultBallPalette[];

extern const s16 gPondDialAnimFrames[];
extern const s16 gBumperAnimFrames[];

void InitAreaRoulette(void)
{
    s16 i;

    gCurrentPinballGame->boardSubState = 1;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->creatureOamPriority = 3;
    gCurrentPinballGame->areaVisitCount = 0;
    gCurrentPinballGame->areaRouletteSlotIndex = (Random() + gMain.systemFrameCount) % 6;
    gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][gCurrentPinballGame->areaRouletteSlotIndex];
    gCurrentPinballGame->rouletteAreaIndex[1] = gAreaToSpeciesTable[gCurrentPinballGame->area];
    gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][(gCurrentPinballGame->areaRouletteSlotIndex + 1) % 6];
    gCurrentPinballGame->rouletteAreaIndex[0] = gAreaToSpeciesTable[gCurrentPinballGame->area];
    LoadPortraitGraphics(0, 0);
    LoadPortraitGraphics(0, 1);
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->hatchTilePalette[i] = 13;

    DmaCopy16(3, gTravelPortraitPalette, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gAreaRouletteSelectedFx_Gfx, (void *)0x06015800, 0x280);
    gCurrentPinballGame->activePortraitType = 12;
}

void UpdateAreaRoulette(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->boardSubState)
    {
    case 1:
        gMain.blendControl = 0x1C10;
        gMain.blendAlpha = BLDALPHA_BLEND(0, 16);
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->rouletteSubOffset = 0;
        gCurrentPinballGame->cameraScrollTarget = 0;
        gCurrentPinballGame->cameraScrollEnabled = 1;
        gMain.fieldSpriteGroups[20]->available = 1;
        gMain.fieldSpriteGroups[21]->available = 1;
        gMain.fieldSpriteGroups[23]->available = 1;
        gMain.fieldSpriteGroups[22]->available = 1;
        gMain.fieldSpriteGroups[19]->available = 1;
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
    case 2:
        if (gCurrentPinballGame->cameraScrollOffset == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 143)
                gCurrentPinballGame->pondBumperStates[0] = gPondDialAnimFrames[gCurrentPinballGame->rubyPondChangeTimer / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 18 && gCurrentPinballGame->rubyPondChangeTimer < 161)
                gCurrentPinballGame->pondBumperStates[2] = gPondDialAnimFrames[(gCurrentPinballGame->rubyPondChangeTimer - 18) / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 36 && gCurrentPinballGame->rubyPondChangeTimer < 179)
                gCurrentPinballGame->pondBumperStates[1] = gPondDialAnimFrames[(gCurrentPinballGame->rubyPondChangeTimer - 36) / 8];

            gCurrentPinballGame->rubyPondChangeTimer++;
        }

        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        gCurrentPinballGame->portraitDisplayState = 1;
        gCurrentPinballGame->stageTimer++;
        UpdateRouletteAnimState();
        break;
    case 3:
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
        SetRouletteActiveState(0);
        /* fallthrough */
    case 4:
    case 5:
        if (gCurrentPinballGame->boardSubState == 3)
        {
            gCurrentPinballGame->rouletteFrameIndex--;
            gCurrentPinballGame->rouletteFrameIndex %= gCurrentPinballGame->rouletteRotationPeriod;
        }
        else if (gCurrentPinballGame->boardSubState == 4)
        {
            gCurrentPinballGame->rouletteFrameIndex++;
            if (gCurrentPinballGame->newButtonActions[1] && gCurrentPinballGame->boardSubState == 4)
            {
                if (gCurrentPinballGame->rouletteSpinSpeed == 0)
                {
                    if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                        gCurrentPinballGame->rouletteSpinSpeed = 48;
                    else
                        gCurrentPinballGame->rouletteSpinSpeed = 1;

                    gCurrentPinballGame->rouletteInitialSpeed = gCurrentPinballGame->rouletteSpinSpeed;
                    gCurrentPinballGame->spoinkEntityState = 1;
                    gCurrentPinballGame->launcherCharging = 1;
                    gCurrentPinballGame->saverTimeRemaining = 3600;
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
                        if (gCurrentPinballGame->areaRouletteSlotIndex == 6)
                            gCurrentPinballGame->rouletteSpinSpeed = 0;
                    }
                }

                if (gCurrentPinballGame->rouletteSpinSpeed == 0)
                {
                    gCurrentPinballGame->boardSubState = 5;
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
                gMain.fieldSpriteGroups[23]->available = 0;
                gMain.fieldSpriteGroups[20]->available = 0;
                gMain.fieldSpriteGroups[21]->available = 0;
                gMain.fieldSpriteGroups[34]->available = 1;
                m4aSongNumStart(SE_AREA_ROULETTE_SELECTED);
            }
        }

        gCurrentPinballGame->rouletteSubOffset = (gCurrentPinballGame->rouletteFrameIndex * 32) / gCurrentPinballGame->rouletteRotationPeriod;
        if (gCurrentPinballGame->rouletteFrameIndex == 0)
        {
            gCurrentPinballGame->rouletteAreaIndex[0] = gCurrentPinballGame->rouletteAreaIndex[1];
            LoadPortraitGraphics(0, 0);
        }

        if (gCurrentPinballGame->rouletteFrameIndex == 1)
        {
            if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
            {
                gCurrentPinballGame->areaRouletteSlotIndex = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % 7;
                gCurrentPinballGame->areaRouletteNextSlot = 0;
                gCurrentPinballGame->areaRouletteFarSlot = 1;
            }
            else
            {
                gCurrentPinballGame->areaRouletteSlotIndex = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % 6;
                gCurrentPinballGame->areaRouletteNextSlot = (gCurrentPinballGame->areaRouletteSlotIndex + 1) % 6;
                gCurrentPinballGame->areaRouletteFarSlot = (gCurrentPinballGame->areaRouletteSlotIndex + 2) % 6;
            }

            gCurrentPinballGame->area = gAreaRouletteTable[gMain.selectedField][gCurrentPinballGame->areaRouletteSlotIndex];
            gCurrentPinballGame->rouletteAreaIndex[1] = gAreaToSpeciesTable[gCurrentPinballGame->area];
            LoadPortraitGraphics(0, 1);
            m4aSongNumStart(SE_ROULETTE_TICK);
        }
        break;
    case 6:
        if (gCurrentPinballGame->stageTimer < 50)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 50)
            {
                gCurrentPinballGame->boardSubState = 0;
                RequestBoardStateTransition(1);
            }
        }

        if (gCurrentPinballGame->stageTimer < 29)
        {
            if (gCurrentPinballGame->stageTimer < 8)
                var0 = gCurrentPinballGame->stageTimer / 4;
            else
                var0 = ((gCurrentPinballGame->stageTimer - 8) / 3) + 2;

            group = gMain.fieldSpriteGroups[34];
            if (group->available)
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

            if (gCurrentPinballGame->stageTimer == 0x1C) {
                gMain.fieldSpriteGroups[34]->available = 0;
                gCurrentPinballGame->activePortraitType = 0;
            }
        }

        gCurrentPinballGame->portraitDisplayState = 0;
        break;
    }
}

void UpdateRouletteAnimState(void)
{
    s16 index;

    index = (gMain.systemFrameCount % 100) / 10;
    gCurrentPinballGame->hudAnimFrameCounter = 0;
    gCurrentPinballGame->catchArrowProgress = gBumperAnimFrames[index];
    gCurrentPinballGame->evoArrowProgress = gBumperAnimFrames[index];
    gCurrentPinballGame->coinRewardLevel = gBumperAnimFrames[index];
    if (index == 7 || index == 9)
    {
        gCurrentPinballGame->catchArrowPaletteActive = 1;
        gCurrentPinballGame->rouletteSlotActive = 1;
        gCurrentPinballGame->evoArrowPaletteActive = 1;
    }
    else
    {
        gCurrentPinballGame->catchArrowPaletteActive = 0;
        gCurrentPinballGame->rouletteSlotActive = 0;
        gCurrentPinballGame->evoArrowPaletteActive = 0;
    }
}

void SetRouletteActiveState(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->rouletteSlotActive = 1;
        gCurrentPinballGame->catchArrowPaletteActive = 1;
        gCurrentPinballGame->catchProgressFlashing = 1;
        gCurrentPinballGame->evoArrowProgress = 3;
        gCurrentPinballGame->coinRewardLevel = 3;
        gCurrentPinballGame->catchArrowProgress = 3;
        gCurrentPinballGame->evoArrowPaletteActive = 1;
    }
    else
    {
        gCurrentPinballGame->evoArrowPaletteActive = 0;
        gCurrentPinballGame->rouletteSlotActive = 0;
        gCurrentPinballGame->catchArrowPaletteActive = 0;
        gCurrentPinballGame->evoArrowProgress = 0;
        gCurrentPinballGame->coinRewardLevel = 0;
        gCurrentPinballGame->catchArrowProgress = 2;
    }

    gCurrentPinballGame->progressLevel = 1;
}

void CleanupTravelModeState(void)
{
    gCurrentPinballGame->travelRouletteSlotHitType = 0;
    gCurrentPinballGame->seedotCount = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->gulpinCurrentLevel = 0;
        gCurrentPinballGame->gulpinAnimFrameIndex = 0;
        gCurrentPinballGame->gulpinAnimFrameTimer = 0;
    }

    gCurrentPinballGame->seedotExitSequenceActive = 1;
    gCurrentPinballGame->seedotExitSequenceTimer = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    gMain.fieldSpriteGroups[13]->available = 0;
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = 0;
    gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0] = 0;
    gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1] = 0;
    gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2] = 0;
    ResetEventState();
}

void InitTravelMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardModeType = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 3600;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->saverTimeRemaining = 1800;
    DmaCopy16(3, gDefaultBallPalette, (void *)0x05000180, 0x20);
}

void UpdateTravelMode(void)
{
    s16 var0;

    if (gCurrentPinballGame->boardModeType && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 6)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = 6;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->portraitCycleFrame = 0;
        }
        gCurrentPinballGame->travelRouletteSlotHitType = 0;
        break;
    case 1:
        LoadPortraitGraphics(4, 0);
        if (gCurrentPinballGame->stageTimer == 35)
            m4aSongNumStart(MUS_TRAVEL_MODE);

        if (gCurrentPinballGame->travelRouletteSlotHitType)
        {
            gCurrentPinballGame->boardSubState++;
            if (gCurrentPinballGame->stageTimer < 35)
                m4aSongNumStart(MUS_TRAVEL_MODE);

            gCurrentPinballGame->seedotCount = 0;
            gCurrentPinballGame->seedotExitSequenceActive = 1;
            gCurrentPinballGame->seedotExitSequenceTimer = 0;
        }

        var0 = (gCurrentPinballGame->stageTimer % 40) / 10;
        gCurrentPinballGame->stageTimer++;
        if (var0 == 0)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 0;
            gCurrentPinballGame->travelArrowTiles[1] = 0;
            gCurrentPinballGame->travelArrowTiles[2] = 0;
        }
        else if (var0 == 1)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 1;
            gCurrentPinballGame->travelArrowTiles[2] = 0;
        }
        else if (var0 == 2)
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 3;
            gCurrentPinballGame->travelArrowTiles[2] = 2;
        }
        else
        {
            gCurrentPinballGame->travelArrowTiles[0] = 3;
            gCurrentPinballGame->travelArrowTiles[1] = 3;
            gCurrentPinballGame->travelArrowTiles[2] = 3;
        }

        gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0];
        gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1];
        gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2];
        break;
    case 2:
        ShowBonusTrapSprite();
        gCurrentPinballGame->trapAnimState = 2;
        LoadPortraitGraphics(0, 0);
        gCurrentPinballGame->prevTravelArrowTiles[0] = gCurrentPinballGame->travelArrowTiles[0] = 0;
        gCurrentPinballGame->prevTravelArrowTiles[1] = gCurrentPinballGame->travelArrowTiles[1] = 0;
        gCurrentPinballGame->prevTravelArrowTiles[2] = gCurrentPinballGame->travelArrowTiles[2] = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 4:
        gCurrentPinballGame->boardModeType = 3;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        gCurrentPinballGame->modeOutcomeValues[0] = 47;
        LoadPortraitGraphics(7, 0);
        break;
    case 5:
        if (gCurrentPinballGame->modeAnimTimer == 145)
        {
            gCurrentPinballGame->modeAnimTimer++;
            gCurrentPinballGame->modeOutcomeValues[0] = 47;
            LoadPortraitGraphics(7, 0);
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->modeAnimTimer = 144;
                m4aMPlayAllStop();
                LoadPortraitGraphics(0, 0);
                if (gCurrentPinballGame->areaVisitCount < 5)
                {
                    var0 = gCurrentPinballGame->areaRouletteFarSlot;
                    if (gCurrentPinballGame->travelRouletteSlotHitType == 1)
                        gCurrentPinballGame->areaRouletteSlotIndex = gCurrentPinballGame->areaRouletteNextSlot;
                    else
                        gCurrentPinballGame->areaRouletteSlotIndex = gCurrentPinballGame->areaRouletteFarSlot;

                    gCurrentPinballGame->areaRouletteNextSlot = (var0 + 1) % 6;
                    gCurrentPinballGame->areaRouletteFarSlot = (var0 + 2) % 6;
                    gCurrentPinballGame->areaVisitCount++;
                }
                else
                {
                    gCurrentPinballGame->areaRouletteSlotIndex = 6;
                    gCurrentPinballGame->areaVisitCount = 0;
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->modeAnimTimer = 60;
                gCurrentPinballGame->boardSubState = 6;
                if (gCurrentPinballGame->allHolesLit)
                    gCurrentPinballGame->allHolesLitDelayTimer = 120;
            }
        }

        if (gCurrentPinballGame->modeAnimTimer == 130)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (gCurrentPinballGame->stageTimer < 490)
            {
                RunTravelEventCutscene();
                if (gCurrentPinballGame->scoreCounterAnimationEnabled && gCurrentPinballGame->stageTimer >= 428)
                    gCurrentPinballGame->stageTimer = 428;

                if (gCurrentPinballGame->stageTimer == 394)
                {
                    gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                    gCurrentPinballGame->scoreAddedInFrame = 500000;
                }
            }
            else
            {
                gCurrentPinballGame->modeAnimTimer = 120;
            }

            gCurrentPinballGame->stageTimer++;
        }
        else if (gCurrentPinballGame->modeAnimTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
            if (gCurrentPinballGame->travelModeCompletionCount < 99)
                gCurrentPinballGame->travelModeCompletionCount++;
        }
        break;
    case 6:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[13]->available = 0;
        CleanupTravelModeState();
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            RequestBoardStateTransition(1);
            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}
