#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gDefaultBallPalette[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const u8 gEvoItemPalettes[][0x20];
extern const s16 gEvoItemAppearFrameThresholds[];
extern const u16 gEvoItemAnimOamFramesets[58][15];
extern const struct Vector16 gEvoItemPositions[][8];
extern const s16 gBumperAnimFrames[];
extern const s16 gPondDialAnimFrames[];
extern const s16 gAreaRouletteTable[][7];
extern const s16 gAreaToSpeciesTable[];
extern const u16 gAreaRouletteOamFramesets[18][27];
extern const u8 gHatchCompletePalette[];
extern const u8 gEggPortraitTilesGfx[];
extern const u8 gHatchStartTilesGfx[];
extern const u8 gHatchStartPalette[];
extern const s16 gHatchRevealSparkleTimings[];
extern const u16 gHatchRevealOamFramesets[16][18];
extern const u8 gHatchStage2TilesGfx[];
extern const u8 gHatchStage2Palette[];
extern const u16 gHatchFullRevealOamFramesets[18][18];
extern const u8 gHatchStage3TilesGfx[];
extern const u8 gHatchStage3Palette[];
extern const u8 gHatchFinalTilesGfx[];
extern const u8 gHatchFinalPalette[];
extern const s16 gHatchRevealFinalTimings[];
extern const u16 gHatchSequentialOamFramesets[22][12];
extern const u8 gHatchRevealPalette[];
extern const u8 gHatchRevealTilesGfx[];
extern const s16 gHatchSequentialTileFramesetData[][2];
extern const u16 gHatchSequentialTileBreakSpritesheetOam[28][18];
extern const s16 gEggHatchAnimData[28][3];
extern const u8 gCatchSpriteFrameBuffer[][0x120];
extern const struct Vector32 gSapphireEggWaypoints[];
extern const u16 gAngleToDirectionTable[];
extern const struct Vector32 gEggWalkPathWaypoints[][29];
extern const u8 gCapturePalette[];
extern const u8 gCaptureScreenTilesGfx[];
extern const u8 gBallUpgradeTilesGfx[];
extern const u8 gCatchAnimTileBuffer[];
extern const u16 gCatchCreatureOamFramesets[48][4][3];
extern const u16 gCyndaquilFrameIndices[];
extern const struct Vector16 gCyndaquilCavePositions[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u16 gHatchCaveOamFramesets[40][2][3];
extern const u8 gSpaceTileGfx[][0x40];
extern const u8 gAlphabetTilesGfx[][0x40];
extern const s16 gCaughtTextChars[];
extern const struct Vector16 gFlyingCreatureCameraOffsets[];
extern const u16 gEggFloatOamFramesets[14][15];
extern const u8 gEggModeTilesGfx[];
extern const u8 gEggModePalette[];
extern const u16 gPikaSaverFrameData[][2];
extern const u16 gPokemonFloatOamFramesets[82][6][3];
extern const u8 gCaptureModePalette[];
extern const u8 gCaptureModeTilesGfx[];
extern const u16 gShopOamAttributes[18][3];
extern const u16 gShopNumberOamFramesets[4][15];
extern const s16 gArrowBounceOffsets[];
extern const s16 gTimerIndicatorFrames[];
extern const u8 gShopDigitTilesGfx[][0x300];
extern const u8 gDecimalDigitTilesGfx[][0x40];
extern const s16 gEvoShopAnimFrames[][7];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gShopPalette[];
extern const struct Vector32 gPikaSaverWaypoints[];
extern const u8 gPikachuSaverTilesGfx[];

extern u8 gCatchSpritePaletteBuffer[];

extern struct SongHeader se_evo_item_appear;
extern struct SongHeader se_evo_item_finish_appear;
extern struct SongHeader se_evo_item_collected;


void PichuArrivalSequence(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    int xx, yy;
    int squaredMagnitude;
    s16 index;

    group = gMain.fieldSpriteGroups[41];
    if (gCurrentPinballGame->pichuEntranceTimer == 0)
        return;

    if (gCurrentPinballGame->pichuEntranceTimer == 800)
    {
        group->available = 1;
        if (gCurrentPinballGame->pichuWalkMode == 1)
        {
            //Start entrance
            gCurrentPinballGame->walkMonXPos = 1090;
            gCurrentPinballGame->walkMonYPos = 4680;
            gCurrentPinballGame->creatureWaypointIndex = 0;
        }
        else
        {
            //Start exit
            gCurrentPinballGame->walkMonXPos = 2000;
            gCurrentPinballGame->walkMonYPos = 3820;
            gCurrentPinballGame->creatureWaypointIndex = 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->pichuEntranceTimer == 799)
        {
            if (gCurrentPinballGame->pichuWalkMode != 1)
            {
                DmaCopy16(3, gPikaSaverTilesGfx, (void *)0x06010600, 0x180);
            }
        }
        tempVec.x = gPikaSaverWaypoints[gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
        tempVec.y = gPikaSaverWaypoints[gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = (Sin(angle) * -7) / 20000;
        index = gAngleToDirectionTable[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
        gCurrentPinballGame->walkMonXPos += tempVec2.x;
        gCurrentPinballGame->walkMonYPos += tempVec2.y;
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (group->baseY < -30)
                group->baseY = -30;

            DmaCopy16(3, gMonHatchSpriteGroup5_Gfx + (index + 30) * 0x120 , (void *)0x060112A0, 0x120);
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = 1;
                gOamBuffer[oamSimple->oamId].paletteNum = 3;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        if (squaredMagnitude < 2500)
        {
            gCurrentPinballGame->creatureWaypointIndex++;
            if (gCurrentPinballGame->pichuWalkMode == 1)
            {
                if (gCurrentPinballGame->creatureWaypointIndex == 4)
                {
                    DmaCopy16(3, gPikachuSaverTilesGfx, (void *)0x06010600, 0x180);
                    gCurrentPinballGame->outLanePikaPosition = 2;
                    gMain.fieldSpriteGroups[41]->available = 0;
                    gCurrentPinballGame->pichuEntranceTimer = 1;
                    m4aSongNumStart(SE_PICHU_IN_POSITION_CHIRP);
                }
            }
            else if (gCurrentPinballGame->creatureWaypointIndex == 7)
            {
                gMain.fieldSpriteGroups[41]->available = 0;
                gCurrentPinballGame->pichuEntranceTimer = 1;
            }
        }
    }

    gCurrentPinballGame->pichuEntranceTimer--;
}

void ResetCatchState(s16 resetHoleIndicators)
{
    if (resetHoleIndicators)
    {
        gCurrentPinballGame->allHolesLit = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    }

    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = 0;
    if (gCurrentPinballGame->boardTransitionPhase != 2 || gCurrentPinballGame->nextBoardState < 3)
    {
        if ((gCurrentPinballGame->jirachiActivationFlags & 0xF) == 0)
        {
            LoadPortraitGraphics(0, 0);
            gCurrentPinballGame->portraitDisplayState = 0;
        }
    }

    if (gCurrentPinballGame->nextBoardState == 6 && gCurrentPinballGame->boardTransitionPhase == 2)
        gCurrentPinballGame->shopDoorTargetFrame = 0;
}

void InitCatchTrigger(void)
{
    gCurrentPinballGame->boardSubState = 1;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->shopPurchaseConfirmed = 0;
}

void UpdateCatchTrigger(void)
{
    switch (gCurrentPinballGame->boardSubState)
    {
    case 1:
        if (gCurrentPinballGame->stageTimer < 9)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer < 8)
            {
                gCurrentPinballGame->trapAnimState = 1;
            }
            else if (gCurrentPinballGame->stageTimer == 8)
            {
                ShowBonusTrapSprite();
                gCurrentPinballGame->trapAnimState = 2;
                gCurrentPinballGame->portraitCycleFrame = 0;
                LoadPortraitGraphics(1, 0);
                gCurrentPinballGame->boardSubState++;
            }
        }
        break;
    case 2:
        AnimateBonusTrapSprite();
        if (gCurrentPinballGame->ballCatchState == 0)
            LoadPortraitGraphics(1, 0);

        if (gCurrentPinballGame->ballCatchState == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        gCurrentPinballGame->allHolesLit = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->boardSubState++;
        InitRouletteWheel();
        if (gCurrentPinballGame->catchTriggerCompletionCount < 99)
            gCurrentPinballGame->catchTriggerCompletionCount++;
        break;
    case 4:
        if (gCurrentPinballGame->modeAnimTimer == 148)
        {
            gCurrentPinballGame->modeAnimTimer++;
            RunRouletteWheel();
        }
        else if (gCurrentPinballGame->modeAnimTimer == 139)
        {
        }
        else if (gCurrentPinballGame->modeAnimTimer == 24)
        {
            LoadPortraitGraphics(0, 0);
        }
        else if (gCurrentPinballGame->modeAnimTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
        }

        if (gCurrentPinballGame->shopPurchaseConfirmed)
        {
            ProcessRouletteOutcome();
            if (gCurrentPinballGame->outcomeFrameCounter < 180)
            {
                gCurrentPinballGame->modeAnimTimer = 140;
                if (gCurrentPinballGame->outcomeFrameCounter == 179)
                    gCurrentPinballGame->modeAnimTimer = 30;
            }
        }

        gCurrentPinballGame->stageTimer = 0;
        break;
    case 5:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[13]->available = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 6:
        ResetCatchState(1);
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            RequestBoardStateTransition(1);
        break;
    }
}

void FullCatchStateCleanup(void)
{
    gCurrentPinballGame->trapAnimState = 0;
    gCurrentPinballGame->bonusTrapEnabled = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    gCurrentPinballGame->evoItemCount = 0;
    gCurrentPinballGame->evoBlinkTimer = 0;
    gCurrentPinballGame->catchLights[0] = 0;
    gCurrentPinballGame->catchLights[1] = 0;
    gCurrentPinballGame->catchLights[2] = 0;
}

void InitBonusStageSelect(void)
{
    if (gMain.selectedField == FIELD_RUBY)
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->modeOutcomeValues[0] = 42;
            gCurrentPinballGame->nextBonusField = FIELD_KECLEON;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->modeOutcomeValues[0] = 44;
            gCurrentPinballGame->nextBonusField = FIELD_GROUDON;
            break;
        case 4:
            gCurrentPinballGame->modeOutcomeValues[0] = 45;
            gCurrentPinballGame->nextBonusField = FIELD_RAYQUAZA;
            break;
        }
    }
    else
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->modeOutcomeValues[0] = 41;
            gCurrentPinballGame->nextBonusField = FIELD_DUSCLOPS;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->modeOutcomeValues[0] = 43;
            gCurrentPinballGame->nextBonusField = FIELD_KYOGRE;
            break;
        case 4:
            gCurrentPinballGame->modeOutcomeValues[0] = 45;
            gCurrentPinballGame->nextBonusField = FIELD_RAYQUAZA;
            break;
        }
    }

    if (gCurrentPinballGame->ballCatchState == 4 && gCurrentPinballGame->prevBoardState == 2)
    {
        gCurrentPinballGame->modeAnimTimer = 150;
        gCurrentPinballGame->boardSubState = 3;
        gCurrentPinballGame->stageTimer = 0;
    }
    else
    {
        gCurrentPinballGame->boardSubState = 0;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        LoadPortraitGraphics(7, 0);
    }
}

void UpdateBonusStageSelect(void)
{
    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        if (gCurrentPinballGame->stageTimer < 60)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState++;
        }
        break;
    case 1:
        if (gCurrentPinballGame->stageTimer < 9)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer < 8)
            {
                gCurrentPinballGame->trapAnimState = 1;
            }
            else if (gCurrentPinballGame->stageTimer == 8)
            {
                switch (gCurrentPinballGame->numCompletedBonusStages % 5)
                {
                case 0:
                case 2:
                    m4aSongNumStart(MUS_BONUS_CHANCE);
                    break;
                case 1:
                case 3:
                case 4:
                    m4aSongNumStart(MUS_BONUS_CHANCE_LEGENDARY);
                    break;
                }

                ShowBonusTrapSprite();
                gCurrentPinballGame->trapAnimState = 2;
                gCurrentPinballGame->boardSubState++;
                gCurrentPinballGame->portraitCycleFrame = 0;
            }
        }
        break;
    case 2:
        AnimateBonusTrapSprite();
        LoadPortraitGraphics(7, 0);
        if (gCurrentPinballGame->ballCatchState == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitCycleFrame = 0;
        gCurrentPinballGame->modeOutcomeValues[0] = 46;
        LoadPortraitGraphics(7, 0);
        break;
    case 4:
        if (gCurrentPinballGame->modeAnimTimer == 145)
        {
            gCurrentPinballGame->modeAnimTimer++;
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->modeAnimTimer = 144;
                m4aMPlayAllStop();
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

            gCurrentPinballGame->modeOutcomeValues[0] = 46;
            LoadPortraitGraphics(7, 0);
        }

        if (gCurrentPinballGame->modeAnimTimer == 130)
        {
            m4aSongNumStart(SE_WARP);
            gCurrentPinballGame->stageTimer = 65;
            gMain.blendControl = 0x9F;
        }

        if (gCurrentPinballGame->modeAnimTimer == 125)
            gCurrentPinballGame->modeAnimTimer++;

        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->startButtonDisabled = 1;
            gCurrentPinballGame->stageTimer--;
            gMain.blendBrightness = 16 - gCurrentPinballGame->stageTimer / 4;
            if (gCurrentPinballGame->stageTimer == 0)
                gCurrentPinballGame->boardSubState++;
        }
        break;
    case 5:
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardSubState = 0;
            gCurrentPinballGame->bonusReturnState = 0;
            TransitionToBonusField();
        }
        break;
    case 6:
        AnimateBonusTrapSprite();
        gMain.fieldSpriteGroups[13]->available = 0;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        break;
    case 7:
        FullCatchStateCleanup();
        gCurrentPinballGame->boardSubState++;
        break;
    case 8:
        RequestBoardStateTransition(1);
        break;
    }
}

void ShowBonusTrapSprite(void)
{
    DmaCopy16(3, gMainStageBonusTrap_Gfx[0], (void *)0x060113C0, 0x300);
    gMain.fieldSpriteGroups[13]->available = 1;
    gCurrentPinballGame->bonusTrapEnabled = 1;
}

void AnimateBonusTrapSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[13];
    gCurrentPinballGame->bonusTrapAnimFrame = (gCurrentPinballGame->globalAnimFrameCounter % 35) / 7;
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 280 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        if (gCurrentPinballGame->ballCatchState == 3)
        {
            group->baseY = 200;
        }
        else
        {
            if (gCurrentPinballGame->bonusTrapAnimFrame != gCurrentPinballGame->prevBonusTrapFrame)
            {
                DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->bonusTrapAnimFrame], (void *)0x060113C0, 0x300);
                gCurrentPinballGame->prevBonusTrapFrame = gCurrentPinballGame->bonusTrapAnimFrame;
            }
        }

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void ProcessChargeIndicator(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 chargeLevelIx;
    s16 sp0[3];

    group = gMain.fieldSpriteGroups[17];
    memset(sp0, 0, sizeof(sp0));
    if (gCurrentPinballGame->chargeFillValue != gCurrentPinballGame->prevChargeFillValue)
    {
        if (gCurrentPinballGame->chargeFillValue == 12) {
            if (gCurrentPinballGame->chargeFillAnimTimer)
            {
                gCurrentPinballGame->chargeFillAnimTimer--;
                chargeLevelIx = ((gCurrentPinballGame->chargeFillAnimTimer % 20) / 10) + 12;
                if (gCurrentPinballGame->chargeFillAnimTimer < 41)
                {
                    if (gCurrentPinballGame->chargeFillAnimTimer > 2)
                    {
                        gCurrentPinballGame->chargeIndicatorXOffset += 3;
                        gCurrentPinballGame->chargeIndicatorYOffset += 2;
                    }

                    gCurrentPinballGame->chargeIndicatorScaleX = gCurrentPinballGame->chargeIndicatorScaleY = ((gCurrentPinballGame->chargeFillAnimTimer * 128) / 40) + 128;
                    sp0[1] =  ((40 - gCurrentPinballGame->chargeFillAnimTimer) * 16) / 40;
                    sp0[0] = -((40 - gCurrentPinballGame->chargeFillAnimTimer) * 16) / 40;
                    sp0[2] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->prevChargeFillValue = 13;
                gCurrentPinballGame->chargeFillValue = 13;
                chargeLevelIx = 13;
                gCurrentPinballGame->fullChargeSlideAnimTimer = 0;
                gCurrentPinballGame->chargeIndicatorYOffset = 120;
                gCurrentPinballGame->fullChargeIndicatorBlinkTimer = 60;
            }

            DmaCopy16(3, gChargeFillIndicator_Gfx[chargeLevelIx], (void *)0x06010AE0, 0x80);
        }
        else
        {
            DmaCopy16(3, gChargeFillIndicator_Gfx[gCurrentPinballGame->chargeFillValue], (void *)0x06010AE0, 0x80);
            gCurrentPinballGame->prevChargeFillValue = gCurrentPinballGame->chargeFillValue;
        }
    }

    if (gCurrentPinballGame->fullChargeSlideAnimTimer)
    {
        gCurrentPinballGame->fullChargeSlideAnimTimer--;
        group->baseY = 80 + gCurrentPinballGame->chargeIndicatorYOffset;
        if (gCurrentPinballGame->fullChargeSlideAnimTimer < 20)
            gCurrentPinballGame->chargeIndicatorScaleY = (gCurrentPinballGame->fullChargeSlideAnimTimer * 12) + 16;
    }
    else
    {
        group->baseY = 180;
    }

    group->baseX = 119 + gCurrentPinballGame->chargeIndicatorXOffset;
    SetMatrixScale(gCurrentPinballGame->chargeIndicatorScaleX, gCurrentPinballGame->chargeIndicatorScaleY, 1);
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + sp0[i];
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
        gOamBuffer[oamSimple->oamId].matrixNum = 1;
    }
}

void UpdateEvolutionShopSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[78];
    if (gCurrentPinballGame->shopTransitionActive == 0)
    {
        if (gCurrentPinballGame->evoArrowProgress > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->evolutionShopActive == 0)
            {
                gCurrentPinballGame->shopTransitionActive = 1;
                gCurrentPinballGame->shopAnimTimer = 0;
                gCurrentPinballGame->evolutionShopActive = 1;
            }
        }
        else if (gCurrentPinballGame->boardState != 6 && gCurrentPinballGame->evolutionShopActive == 1 && gCurrentPinballGame->ballCatchState != 4)
        {
            gCurrentPinballGame->shopTransitionActive = 1;
            gCurrentPinballGame->shopAnimTimer = 0;
            gCurrentPinballGame->evolutionShopActive = 0;
        }
    }
    else
    {
        index = gEvoShopAnimFrames[gCurrentPinballGame->evolutionShopActive][(gCurrentPinballGame->shopAnimTimer % 42) / 6];
        if (gCurrentPinballGame->shopAnimTimer == 0)
        {
            group->available = 1;
            DmaCopy16(3, gShopPalette, (void *)0x05000240, 0x20);
        }
        else if (gCurrentPinballGame->shopAnimTimer == 37)
        {
            m4aSongNumStart(SE_UNKNOWN_0xCA);
        }

        if (gCurrentPinballGame->shopAnimTimer % 6 == 0)
        {
            DmaCopy16(3, gRubyBoardShop_Gfx[index], (void *)0x06013D00, 0x500);
        }

        group->baseX = 181 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 48 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY < -50)
            group->baseY = -50;

        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->shopAnimTimer++;
        if (gCurrentPinballGame->shopAnimTimer > 40)
        {
            LoadShopItemGraphics(gCurrentPinballGame->evolutionShopActive);
            gCurrentPinballGame->shopTransitionActive = 0;
            gMain.spriteGroups[78].available = 0;
        }
    }
}

void RenderEvolutionUI(s16 arg0)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *var1;
    u16 *dst;
    const u16 *src;
    s16 index;
    s16 sp0[2];
    s16 sp4[2];

    group = gMain.fieldSpriteGroups[7];
    var1 = gShopItemData[gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor]];
    if (arg0)
    {
        index = var1[3] / 10;
        DmaCopy16(3, gDecimalDigitTilesGfx[index], (void *)0x06015DA0, 0x40);
        index = var1[3] % 10;
        DmaCopy16(3, gDecimalDigitTilesGfx[index], (void *)0x06015E60, 0x40);
    }

    if (group->available)
    {
        group->baseX = 156 + gCurrentPinballGame->shopUISlideOffset;
        group->baseY = 96;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.fieldSpriteGroups[8];
    index = gCurrentPinballGame->evolutionShopActive != 0 ? 1 : 0;
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->shopUISlideOffset + 136);
        group->baseY = 88;
        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 0];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 1];
            *dst++ = gShopNumberOamFramesets[index][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = gMain.fieldSpriteGroups[6];
    if (group->available)
    {
        if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        sp0[0] = -gArrowBounceOffsets[(gMain.systemFrameCount % 30) / 5];
        sp0[1] = gArrowBounceOffsets[(gMain.systemFrameCount % 30) / 5];
        sp4[0] = sp0[0];
        sp4[1] = sp0[1];
        if (gCurrentPinballGame->evolutionShopActive == 0)
        {
            for (i = 0; i < 4; i++)
            {
                s16 i2 = i / 2;
                group->baseX = i2 * 24 + 36 + sp0[i2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else if (gCurrentPinballGame->evolvablePartySize > 1)
        {
            for (i = 0; i < 4; i++)
            {
                group->baseX = (i / 2) * 24 + 36 + sp0[i / 2];
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        else
        {
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 0;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
        }

        if (gCurrentPinballGame->evolutionShopActive == 0)
            group->baseY = 180;
        else if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        group->baseX = 48;
        if (gCurrentPinballGame->evoChainPosition < gCurrentPinballGame->evoChainMaxStage)
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[0];
        }
        else
        {
            oamSimple = &group->oam[4];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }

        if (gCurrentPinballGame->evoChainPosition > 0)
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + sp4[1];
        }
        else
        {
            oamSimple = &group->oam[5];
            gOamBuffer[oamSimple->oamId].x = 0;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    group = gMain.fieldSpriteGroups[9];
    if (group->available)
    {
        group->baseX = 48;
        if (gMain.shopPanelSlideOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 88;

        if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 4)
        {
            if (gCurrentPinballGame->shopBonusStageAlreadyBought && gCurrentPinballGame->shopAnimSlideTimer / 5 == 0)
                index = 4;
            else
                index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }
        else if (gShopCursorToItemMap[gCurrentPinballGame->shopItemCursor] == 3)
        {
            if (gCurrentPinballGame->shopPikaSaverMaxed && gCurrentPinballGame->shopAnimSlideTimer / 5 == 0)
                index = 4;
            else
                index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }
        else
        {
            index = gTimerIndicatorFrames[gCurrentPinballGame->shopAnimSlideTimer / 5];
        }

        DmaCopy16(3, gShopDigitTilesGfx[index], (void *)0x06016220, 0x300);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void AnimateCoinReward(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int var1;
    s16 var2;

    group = gMain.fieldSpriteGroups[39];
    if (gCurrentPinballGame->coinRewardTimer < ((gCurrentPinballGame->coinRewardAmount - 1) * 9) + 19)
    {
        if (gCurrentPinballGame->coinRewardTimer == 0)
        {
            group->available = 1;
            gCurrentPinballGame->coinsAwarded = 0;
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->coinBounceTimer[i] = 0;
                gCurrentPinballGame->coinSpritePos[i].x = 70;
                gCurrentPinballGame->coinSpritePos[i].y = 180;
            }

            gCurrentPinballGame->coinRewardFastPayout = 0;
        }
        else
        {
            if (gCurrentPinballGame->ballCatchState == 4 && (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)))
                gCurrentPinballGame->coinRewardFastPayout = 1;

            if (gCurrentPinballGame->coinsAwarded < gCurrentPinballGame->coinRewardAmount)
            {
                var1 = gCurrentPinballGame->coinRewardTimer - 1;
                if (var1 % 9 == 0)
                {
                    if (gCurrentPinballGame->coinRewardFastPayout)
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinBounceTimer[var2] = 17;
                        gCurrentPinballGame->coinSpritePos[var2].x = 188;
                        gCurrentPinballGame->coinSpritePos[var2].y = 140;
                        m4aSongNumStart(SE_COIN_COLLECTED);
                        gCurrentPinballGame->coins += gCurrentPinballGame->coinRewardAmount - gCurrentPinballGame->coinsAwarded;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->coinRewardAmount - gCurrentPinballGame->coinsAwarded) * 100;
                        gCurrentPinballGame->coinRewardTimer = (gCurrentPinballGame->coinRewardAmount * 9) + 1;
                        gCurrentPinballGame->coinsAwarded = gCurrentPinballGame->coinRewardAmount;
                    }
                    else
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinBounceTimer[var2] = 17;
                        gCurrentPinballGame->coinSpritePos[var2].x = 188;
                        gCurrentPinballGame->coinSpritePos[var2].y = 140;
                        gCurrentPinballGame->coinsAwarded++;
                        m4aSongNumStart(SE_COIN_COLLECTED);
                        gCurrentPinballGame->coins++;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = 100;
                    }
                }
            }

            for (i = 0; i < 2; i++)
            {
                group->baseX = gCurrentPinballGame->coinSpritePos[i].x;
                group->baseY = gCurrentPinballGame->coinSpritePos[i].y;
                if (gCurrentPinballGame->coinSpritePos[i].y > 160)
                    var0 = 0;
                else
                    var0 = (17 - gCurrentPinballGame->coinBounceTimer[i]) / 2;

                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gShopOamAttributes[var0];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;

                if (gCurrentPinballGame->coinBounceTimer[i] > 0)
                {
                    gCurrentPinballGame->coinBounceTimer[i]--;
                    if (gCurrentPinballGame->coinBounceTimer[i] == 0)
                    {
                        gCurrentPinballGame->coinSpritePos[i].x = 70;
                        gCurrentPinballGame->coinSpritePos[i].y = 180;
                    }
                }
            }
        }

        gCurrentPinballGame->coinRewardTimer++;
        if (gCurrentPinballGame->coinRewardTimer == ((gCurrentPinballGame->coinRewardAmount - 1) * 9) + 19)
        {
            gMain.fieldSpriteGroups[39]->available = 0;
            gCurrentPinballGame->coinRewardAmount = 0;
            if (gCurrentPinballGame->ballCatchState == 4)
                gCurrentPinballGame->outcomeFrameCounter = 170;
        }
    }
}

void InitTotodileEggDelivery(void)
{
    gCurrentPinballGame->eggDeliveryX = 1600;
    gCurrentPinballGame->eggDeliveryY = 2080;
    gCurrentPinballGame->totodileDeliveryFrame = 0;
    gCurrentPinballGame->totodileDeliveryTimer = 0;
    gMain.spriteGroups[82].available = 1;
    gCurrentPinballGame->eggAnimationPhase = 1;
    gCurrentPinballGame->portraitOffsetX = 240;
    gCurrentPinballGame->portraitOffsetY = 160;
    gCurrentPinballGame->activePortraitType = 3;
    DmaCopy16(3, gCaptureModePalette, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gCaptureModeTilesGfx, (void *)0x06015800, 0xCA0);
}

void AnimateTotodileEggDelivery(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;

    var0 = 0;
    group = &gMain.spriteGroups[82];
    if (gPikaSaverFrameData[gCurrentPinballGame->totodileDeliveryFrame][1] > gCurrentPinballGame->totodileDeliveryTimer)
    {
        gCurrentPinballGame->totodileDeliveryTimer++;
    }
    else
    {
        gCurrentPinballGame->totodileDeliveryFrame++;
        gCurrentPinballGame->totodileDeliveryTimer = 0;
        if (gCurrentPinballGame->totodileDeliveryFrame == 41)
        {
            gCurrentPinballGame->totodileDeliveryFrame = 40;
            group->available = 0;
            gCurrentPinballGame->eggDeliveryState = 2;
            gCurrentPinballGame->activePortraitType = 0;
        }

        if (gCurrentPinballGame->totodileDeliveryFrame == 1)
            m4aSongNumStart(SE_UNKNOWN_0x146);

        if (gCurrentPinballGame->totodileDeliveryFrame == 7)
            m4aSongNumStart(SE_UNKNOWN_0x147);

        if (gCurrentPinballGame->totodileDeliveryFrame == 13)
            m4aSongNumStart(SE_UNKNOWN_0x148);

        if (gCurrentPinballGame->totodileDeliveryFrame == 39)
        {
            gCurrentPinballGame->portraitOffsetX = 0;
            gCurrentPinballGame->portraitOffsetY = 0;
            DmaCopy16(3, gEggFrameTilesGfx[0], (void *)0x06011CE0, 0x200);
        }

        if (gCurrentPinballGame->totodileDeliveryFrame == 14)
            gCurrentPinballGame->scoreAddedInFrame = 2000000;
    }

    if (gCurrentPinballGame->totodileDeliveryFrame >= 14 && gCurrentPinballGame->totodileDeliveryFrame < 38 && gCurrentPinballGame->globalAnimFrameCounter % 7 == 0)
        m4aSongNumStart(SE_UNKNOWN_0x149);

    group->baseX = gCurrentPinballGame->eggDeliveryX / 20 - gCurrentPinballGame->cameraXOffset;
    group->baseY = gCurrentPinballGame->eggDeliveryY / 20 - gCurrentPinballGame->cameraYOffset;
    var0 = gPikaSaverFrameData[gCurrentPinballGame->totodileDeliveryFrame][0];
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gPokemonFloatOamFramesets[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void InitAerodactylEggDelivery(void)
{
    gCurrentPinballGame->eggDropTimer = 0;
    gCurrentPinballGame->eggDeliveryX = 3600;
    gCurrentPinballGame->eggDeliveryY = -40;
    gCurrentPinballGame->eggDeliveryVelX = -36;
    gCurrentPinballGame->eggDeliveryVelY = 60;
    gMain.spriteGroups[12].available = 1;
    gCurrentPinballGame->eggAnimationPhase = 1;
    gCurrentPinballGame->portraitOffsetX = gCurrentPinballGame->eggDeliveryX / 20 - gFlyingCreatureCameraOffsets[0].x;
    gCurrentPinballGame->portraitOffsetY = gCurrentPinballGame->eggDeliveryY / 20 - gFlyingCreatureCameraOffsets[0].y;
    gCurrentPinballGame->activePortraitType = 2;
    DmaCopy16(3, gEggModePalette, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gEggModeTilesGfx, (void *)0x06015800, 0x1000);
}

void AnimateAerodactylEggDelivery(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    var0 = (gCurrentPinballGame->eggDropTimer % 56) / 8;
    group = &gMain.spriteGroups[12];
    if (gCurrentPinballGame->eggDropTimer < 130)
    {
        if (gCurrentPinballGame->eggDropTimer % 36U == 0)
            m4aSongNumStart(SE_UNKNOWN_0xB8);

        gCurrentPinballGame->eggDropTimer++;
        gCurrentPinballGame->eggDeliveryX += gCurrentPinballGame->eggDeliveryVelX;
        gCurrentPinballGame->eggDeliveryY += gCurrentPinballGame->eggDeliveryVelY;
        if (gCurrentPinballGame->eggDeliveryVelY > 7 || gMain.systemFrameCount % 3 == 0)
            gCurrentPinballGame->eggDeliveryVelY--;

        if (gCurrentPinballGame->eggDropTimer < 78)
        {
            gCurrentPinballGame->portraitOffsetX = gCurrentPinballGame->eggDeliveryX / 20 - gFlyingCreatureCameraOffsets[var0].x;
            gCurrentPinballGame->portraitOffsetY = gCurrentPinballGame->eggDeliveryY / 20 - gFlyingCreatureCameraOffsets[var0].y;
        }
        else
        {
            gCurrentPinballGame->portraitOffsetX = 0;
            gCurrentPinballGame->portraitOffsetY = 0;
        }

        if (gCurrentPinballGame->eggDropTimer == 78)
            gCurrentPinballGame->scoreAddedInFrame = 100000;

        DmaCopy16(3, gEggFrameTilesGfx[0], (void *)0x06011CE0, 0x200);
    }
    else
    {
        group->available = 0;
        do {} while (0); // needed to match, there was probably some dead code
        gCurrentPinballGame->eggDeliveryState = 2;
        gCurrentPinballGame->activePortraitType = 0;
    }

    group->baseX = gCurrentPinballGame->eggDeliveryX / 20 - gCurrentPinballGame->cameraXOffset;
    group->baseY = gCurrentPinballGame->eggDeliveryY / 20 - gCurrentPinballGame->cameraYOffset;
    for (i = 0; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gEggFloatOamFramesets[var0][i * 3 + 0];
        *dst++ = gEggFloatOamFramesets[var0][i * 3 + 1];
        *dst++ = gEggFloatOamFramesets[var0][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void LoadPokemonNameGraphics(void)
{
    s16 i;
    int index;

    gCurrentPinballGame->nameSpacingOffset = 0;
    LoadPortraitGraphics(9, 0);
    gCurrentPinballGame->activePortraitType = 14;
    gMain.fieldSpriteGroups[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gSpaceTileGfx[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->nameSpacingOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gAlphabetTilesGfx[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }
}

void UpdatePokemonNamePosition(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[4];
    for (i = 0; i < 10; i++)
    {
        group->baseX = i * 8 + (gCurrentPinballGame->nameSpacingOffset + 152) + gCurrentPinballGame->shopUISlideOffset;
        group->baseY = 96;
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void HidePokemonNameDisplay(void)
{
    gMain.fieldSpriteGroups[4]->available = 0;
    gCurrentPinballGame->activePortraitType = 0;
}

void InitEvolutionSuccessDisplay(void)
{
    s16 i;
    u8 letter;
    int index;
    const u8 *dest;

    gCurrentPinballGame->nameSpacingOffset = 0;
    gCurrentPinballGame->creatureOamPriority = 0;
    gCurrentPinballGame->nameRevealAnimFrame = 0;
    LoadPortraitGraphics(3, 0);
    gCurrentPinballGame->activePortraitType = 13;
    gMain.fieldSpriteGroups[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gSpaceTileGfx[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->nameSpacingOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gAlphabetTilesGfx[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }

    gMain.fieldSpriteGroups[5]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gCaughtTextChars[i] == 0x20)
        {
            DmaCopy16(3, gSpaceTileGfx[0], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
        else
        {
            index = gCaughtTextChars[i] - 0x41;
            DmaCopy16(3, gAlphabetTilesGfx[index], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->nameRevealDelays[i] = i * 2;
        gCurrentPinballGame->nameSlideRow1[i].x = 0;
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->nameRevealDelaysRow2[i] = (i + 10) * 2;
        gCurrentPinballGame->nameSlideRow2[i].x = 0;
    }
}

void AnimateEvolutionSuccessScreen(void)
{
    s16 i, j, k;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 var0;

    gCurrentPinballGame->portraitDisplayState = 0;
    if (gCurrentPinballGame->nameRevealAnimFrame == 0)
    {
        gCurrentPinballGame->nameRevealAnimFrame++;
        group = gMain.fieldSpriteGroups[4];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.fieldSpriteGroups[5];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
    else if (gCurrentPinballGame->nameRevealAnimFrame < 195)
    {
        gCurrentPinballGame->nameRevealAnimFrame++;
        if (gCurrentPinballGame->nameRevealAnimFrame < 156)
        {

            group = gMain.fieldSpriteGroups[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelays[i])
                {
                    gCurrentPinballGame->nameRevealDelays[i]--;
                }
                else
                {
                    gCurrentPinballGame->nameSlideRow1[i].x += ((1600 - gCurrentPinballGame->nameSlideRow1[i].x) * 12) / 100;
                    if (gCurrentPinballGame->nameSlideRow1[i].x >= 1592)
                        gCurrentPinballGame->nameSlideRow1[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow1[i].x / 10 - var0) + gCurrentPinballGame->nameSpacingOffset;;
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelaysRow2[i])
                {
                    gCurrentPinballGame->nameRevealDelaysRow2[i]--;
                }
                else
                {
                    gCurrentPinballGame->nameSlideRow2[i].x += ((1600 - gCurrentPinballGame->nameSlideRow2[i].x) * 12) / 100;
                    if (gCurrentPinballGame->nameSlideRow2[i].x >= 1592)
                        gCurrentPinballGame->nameSlideRow2[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow2[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->nameRevealAnimFrame == 155)
            {
                for (j = 0; j < 10; j++)
                {
                    gCurrentPinballGame->nameRevealDelays[j] = j * 2;
                    gCurrentPinballGame->nameSlideRow1[j].x = 0;
                }

                for (k = 0; k < 10; k++)
                {
                    gCurrentPinballGame->nameRevealDelaysRow2[k] = (k + 10) * 2;
                    gCurrentPinballGame->nameSlideRow2[k].x = 0;
                }
            }
        }
        else
        {
            group = gMain.fieldSpriteGroups[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelays[i])
                    gCurrentPinballGame->nameRevealDelays[i]--;
                else
                    gCurrentPinballGame->nameSlideRow1[i].x += ((2000 - gCurrentPinballGame->nameSlideRow1[i].x) * 12) / 100;

                var0 = i * 8 + 80;
                group->baseX = var0 - gCurrentPinballGame->cameraXOffset - gCurrentPinballGame->nameSlideRow1[i].x / 10 + gCurrentPinballGame->nameSpacingOffset;
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.fieldSpriteGroups[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameRevealDelaysRow2[i])
                    gCurrentPinballGame->nameRevealDelaysRow2[i]--;
                else
                    gCurrentPinballGame->nameSlideRow2[i].x += ((2000 - gCurrentPinballGame->nameSlideRow2[i].x) * 12) / 100;

                var0 = 0;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->cameraXOffset - (gCurrentPinballGame->nameSlideRow2[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->rouletteBasePos.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
    else
    {
        group = gMain.fieldSpriteGroups[4];
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = gMain.fieldSpriteGroups[5];
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 180;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        gMain.fieldSpriteGroups[4]->available = 0;
        gMain.fieldSpriteGroups[5]->available = 0;
        gCurrentPinballGame->activePortraitType = 0;
    }
}

void InitEggModeAnimation(void)
{
    gCurrentPinballGame->eggAnimationPhase = 1;
    gCurrentPinballGame->prevEggAnimFrame = 0;
    gCurrentPinballGame->eggAnimFrameIndex = 0;
    gCurrentPinballGame->eggFrameTimer = 0;
    gCurrentPinballGame->eggCaveState = 0;
    gCurrentPinballGame->eggCaveReEntryFlag = 0;
}

void UpdateEggModeAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    s16 var2;
    s16 var3;
    s16 priority;
    s16 index;

    priority = 1;
    var0 = 0;
    var1 = 0;
    var2 = 0;
    group = &gMain.spriteGroups[48];
    var3 = 0;
    switch (gCurrentPinballGame->eggAnimationPhase)
    {
    case 0:
    case 1:
        break;
    case 2:
        var0 = 4;
        var1 = 4;
        var2 = 3;
        break;
    case 3:
        var0 = 8;
        var1 = 4;
        var2 = 3;
        break;
    case 4:
        var0 = 12;
        var1 = 12;
        var2 = 5;
        break;
    case 5:
        var0 = 33;
        var1 = 0;
        var2 = 0;
        break;
    }

    if (gCurrentPinballGame->prevEggAnimFrame != gCurrentPinballGame->eggAnimFrameIndex)
    {
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][2];
        DmaCopy16(3, gRubyBoardHatchCave_Gfx[index], (void *)0x060122A0, 0x480);
        index = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][3];
        DmaCopy16(3, gEggFrameTilesGfx[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->prevEggAnimFrame = gCurrentPinballGame->eggAnimFrameIndex;
    }

    if (gCurrentPinballGame->eggAnimationPhase > 1)
    {
        if (gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][1] > gCurrentPinballGame->eggFrameTimer)
        {
            gCurrentPinballGame->eggFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->eggAnimFrameIndex++;
            gCurrentPinballGame->eggFrameTimer = 0;
            if (gCurrentPinballGame->eggAnimFrameIndex >= var0)
            {
                gCurrentPinballGame->eggAnimFrameIndex = var1;
                gCurrentPinballGame->eggAnimationPhase = var2;
            }

            if (gCurrentPinballGame->eggAnimFrameIndex == 18)
                BuildSpeciesWeightsForEggMode();

            if (gCurrentPinballGame->eggAnimFrameIndex == 19)
            {
                PickSpeciesForEggMode();
                if (gMain.mainState != STATE_GAME_IDLE)
                    SaveFile_SetPokedexFlags(gCurrentPinballGame->currentSpecies, 1);
            }

            if (gCurrentPinballGame->eggAnimFrameIndex == 20)
                LoadEggSpriteGraphics();

            if ((gCurrentPinballGame->eggAnimFrameIndex == 8 || gCurrentPinballGame->eggAnimFrameIndex == 27) && gCurrentPinballGame->eggFrameTimer == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->eggAnimFrameIndex == 12 && gCurrentPinballGame->eggFrameTimer == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->eggAnimFrameIndex == 29)
                RequestBoardStateTransition(5);

            if (gCurrentPinballGame->eggAnimFrameIndex == 28)
                m4aSongNumStart(SE_HATCH_FLOURISH);
        }

        var3 = gEggAnimationFrameData[gCurrentPinballGame->eggAnimFrameIndex][0];
    }

    gCurrentPinballGame->eggBasePosX = 88 - gCurrentPinballGame->cameraXOffset;
    gCurrentPinballGame->eggBasePosY = 144 - gCurrentPinballGame->cameraYOffset;
    group->baseX = gCurrentPinballGame->eggBasePosX + gCurrentPinballGame->portraitOffsetX;
    if (gCurrentPinballGame->eggAnimationPhase > 0)
    {
        if (gCurrentPinballGame->eggAnimFrameIndex == 32 && gCurrentPinballGame->eggFrameTimer > 208)
        {
            s16 varZ = (0x100 - gCurrentPinballGame->eggFrameTimer) / 16 + 1;
            if (gMain.systemFrameCount & (varZ << 1))
                group->baseY = gCurrentPinballGame->eggBasePosY + gCurrentPinballGame->portraitOffsetY;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->eggBasePosY + gCurrentPinballGame->portraitOffsetY;
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
        src = gHatchCaveOamFramesets[var3][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[52];
    group->baseX = gCurrentPinballGame->eggBasePosX;
    group->baseY = gCurrentPinballGame->eggBasePosY;
    for (i = 0; i < 4; i++)
    {
        oamSimple = &gMain.spriteGroups[52].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateEggHatchDisplay(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 var0;

    priority = 1;
    group = &gMain.spriteGroups[51];
    var0 = gMain.systemFrameCount % 36;
    gCurrentPinballGame->cyndaquilFrame = 0;
    gCurrentPinballGame->cyndaquilCollisionEnabled = 1;
    if (gCurrentPinballGame->eggCaveState < 3)
    {
        gCurrentPinballGame->cyndaquilFrame = gCyndaquilFrameIndices[var0 / 6];
        gCurrentPinballGame->cyndaquilCaveSpriteX = gCyndaquilCavePositions[gCurrentPinballGame->eggCaveState].x;
        gCurrentPinballGame->cyndaquilCaveSpriteY = gCyndaquilCavePositions[gCurrentPinballGame->eggCaveState].y;
        group->baseX = gCurrentPinballGame->cyndaquilCaveSpriteX - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->cyndaquilCaveSpriteY - gCurrentPinballGame->cameraYOffset;
        if (var0 % 6 == 0)
        {
            DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], (void *)0x06013300, 0x280);
        }
    }
    else if (gCurrentPinballGame->eggCaveState == 3)
    {
        if (gCurrentPinballGame->eggDeliveryState != 2)
        {
            if (gCurrentPinballGame->eggAnimationPhase == 1)
            {
                gCurrentPinballGame->eggAnimationPhase = 2;
                gCurrentPinballGame->cyndaquilFrame = 1;
                DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilFrame], (void *)0x06013300, 0x280);
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->bannerDelayTimer = 0;
                gCurrentPinballGame->bannerDisplayTimer = 60;
                gCurrentPinballGame->cameraYScrollTarget = 72;
                gCurrentPinballGame->cameraYAdjust = 0;
                gCurrentPinballGame->cameraYScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxIndex = 0;
                gCurrentPinballGame->bannerActive = 1;
                gCurrentPinballGame->bannerPreserveBallState = 0;
                gCurrentPinballGame->eggCaveLiftTimer = 48;
            }

            if (gCurrentPinballGame->eggCaveReEntryFlag)
            {
                gCurrentPinballGame->eggCaveReEntryFlag = 0;
                gCurrentPinballGame->eggCaveLiftTimer = 48;
            }
        }
        else
        {
            if (gCurrentPinballGame->eggCaveLiftTimer == 0)
            {
                if (gCurrentPinballGame->eggCaveExitDelayTimer == 30)
                {
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->collisionCooldownTimer = 60;
                    gCurrentPinballGame->ball->velocity.x = 20;
                    gCurrentPinballGame->ball->velocity.y = 200;
                    gCurrentPinballGame->ball->positionQ0.x = 88;
                    gCurrentPinballGame->ball->positionQ0.y = 163;
                    gCurrentPinballGame->ball->spinSpeed = 0;
                    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                    m4aSongNumStart(SE_UNKNOWN_0xB9);
                    gCurrentPinballGame->boardEntityActive = 0;
                }

                if (gCurrentPinballGame->eggCaveExitDelayTimer)
                {
                    gCurrentPinballGame->eggCaveExitDelayTimer--;
                }
                else
                {
                    InitEggModeAnimation();
                    gCurrentPinballGame->eggCaveState = 0;
                    gCurrentPinballGame->eggDeliveryState = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->positionQ0.x = 88;
                gCurrentPinballGame->ball->positionQ0.y = 163 - gCurrentPinballGame->eggCaveLiftTimer / 3;
                gCurrentPinballGame->ball->spinSpeed = 0;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
                gCurrentPinballGame->boardEntityActive = 1;
            }
        }

        gCurrentPinballGame->cyndaquilCaveSpriteX = gCyndaquilCavePositions[gCurrentPinballGame->eggCaveState].x;
        gCurrentPinballGame->cyndaquilCaveSpriteY = gCyndaquilCavePositions[gCurrentPinballGame->eggCaveState].y - gCurrentPinballGame->eggCaveLiftTimer / 3;
        group->baseX = gCurrentPinballGame->cyndaquilCaveSpriteX - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->cyndaquilCaveSpriteY - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->boardState < 3)
        {
            if (gCurrentPinballGame->eggCaveState == 3 && gCurrentPinballGame->eggDeliveryState != 2)
                gCurrentPinballGame->catchArrowPaletteActive = 1;
            else
                gCurrentPinballGame->catchArrowPaletteActive = 0;
        }
        else
        {
            gCurrentPinballGame->catchArrowPaletteActive = 0;
        }

        if (gCurrentPinballGame->eggCaveLiftTimer)
        {
            gCurrentPinballGame->eggCaveLiftTimer--;
            priority = 2;
        }
    }
    else
    {
        if (gCurrentPinballGame->eggAnimationPhase == 3)
        {
            gCurrentPinballGame->catchArrowPaletteActive = 0;
            gCurrentPinballGame->eggAnimationPhase = 4;
            gCurrentPinballGame->eggAnimFrameIndex = 8;
            gCurrentPinballGame->eggFrameTimer = 0;
        }

        gCurrentPinballGame->cyndaquilCaveSpriteX = 0;
        gCurrentPinballGame->cyndaquilCaveSpriteY = 0;
        group->baseX = 0;
        group->baseY = 160;
    }

    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void CleanupEggModeState(void)
{
    s16 i;

    if (gMain.selectedField == FIELD_RUBY)
        gCurrentPinballGame->eggDeliveryState = 1;
    else
        gCurrentPinballGame->holeCaptureReady = 1;

    gCurrentPinballGame->creatureHitCount = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->evoItemCount)
            gCurrentPinballGame->catchLights[i] = 1;
        else
            gCurrentPinballGame->catchLights[i] = 0;
    }
}

void InitEggMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->saverTimeRemaining = 1800;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->walkMonXVelocity = 0;
    gCurrentPinballGame->walkMonYVelocity = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->walkMonXPos = 750;
        gCurrentPinballGame->walkMonYPos = 1040;
    }
    else
    {
        gCurrentPinballGame->walkMonXPos = 1960;
        gCurrentPinballGame->walkMonYPos = 300;
    }

    gCurrentPinballGame->creatureWaypointIndex = 0;
    gCurrentPinballGame->waypointSubTimer = 0;
    gCurrentPinballGame->walkMonXVelocity = 0;
    gCurrentPinballGame->walkMonYVelocity = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
}

void UpdateEggMode(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    int priority;
    struct Vector32 tempVec;
    struct Vector32 tempVec2;
    u16 angle;
    u16 angle2;
    int xx, yy;
    int squaredMagnitude;

    group = gMain.fieldSpriteGroups[41];
    priority = 1;
    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        gCurrentPinballGame->portraitDisplayState = 3;
        gMain.fieldSpriteGroups[41]->available = 1;
        gCurrentPinballGame->boardSubState++;
        break;
    case 1:
        if (gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][1] > gCurrentPinballGame->waypointSubTimer)
        {
            gCurrentPinballGame->waypointSubTimer++;
        }
        else
        {
            gCurrentPinballGame->creatureWaypointIndex++;
            gCurrentPinballGame->waypointSubTimer = 0;
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->creatureWaypointIndex > 13)
                {
                    gCurrentPinballGame->creatureWaypointIndex = 0;
                    gCurrentPinballGame->boardSubState = 3;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 12)
                {
                    if (gCurrentPinballGame->waypointSubTimer == 0)
                        m4aSongNumStart(MUS_EGG_MODE);
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 10)
                {
                    gCurrentPinballGame->bgmFadeTimer = 140;
                    PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].speciesIdRS, 0);
                }

                if (gCurrentPinballGame->creatureWaypointIndex == 12)
                {
                    gCurrentPinballGame->walkMonXVelocity = -8;
                    gCurrentPinballGame->walkMonYVelocity = -30;
                }
                else
                {
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->creatureWaypointIndex > 9)
                {
                    gCurrentPinballGame->waypointSubTimer = 0;
                    gCurrentPinballGame->creatureWaypointIndex = 10;
                    gCurrentPinballGame->boardSubState = 2;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }
        }

        var0 = gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][0];
        var1 = gEggHatchAnimData[gCurrentPinballGame->creatureWaypointIndex][2];
        if (gCurrentPinballGame->creatureWaypointIndex == 12)
        {
            gCurrentPinballGame->walkMonYVelocity += 2;
            gCurrentPinballGame->walkMonXPos += gCurrentPinballGame->walkMonXVelocity;
            gCurrentPinballGame->walkMonYPos += gCurrentPinballGame->walkMonYVelocity;
        }

        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gCatchSpriteFrameBuffer[var0], (void *)0x060112A0, 0x120);
        DmaCopy16(3, gCatchSpritePaletteBuffer, (void *)0x050003A0, 0x20);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gCatchCreatureOamFramesets[var1][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
        break;
    case 2:
        if (gCurrentPinballGame->waypointSubTimer < 240)
        {
            priority = 1;
            if (gCurrentPinballGame->waypointSubTimer == 0)
            {
                gCurrentPinballGame->holeLetterSystemState = 3;
                m4aSongNumStart(SE_UNKNOWN_0xDD);
            }
            var0 = 0;
        }
        else if (gCurrentPinballGame->waypointSubTimer == 240)
        {
            gCurrentPinballGame->walkMonXPos = 2260;
            gCurrentPinballGame->walkMonYPos = 740;
            gCurrentPinballGame->creatureWaypointIndex = 0;
            priority = 2;
            var0 = 0;
            m4aSongNumStart(MUS_EGG_MODE);
        }
        else
        {
            tempVec.x = gSapphireEggWaypoints[gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
            tempVec.y = gSapphireEggWaypoints[gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            angle = ArcTan2(tempVec.x,-tempVec.y);
            if (gCurrentPinballGame->waypointSubTimer < 324)
                priority = 2;
            else
                priority = 1;

            if (gCurrentPinballGame->creatureWaypointIndex < 4)
            {
                var0 = 0;
                tempVec2.x = (Cos(angle) * 14) / 20000;
                tempVec2.y = -(Sin(angle) * 14) / 20000;
            }
            else
            {
                var0 = gAngleToDirectionTable[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
                tempVec2.x = (Cos(angle) * 7) / 20000;
                tempVec2.y = -(Sin(angle) * 7) / 20000;
            }

            gCurrentPinballGame->walkMonXPos += tempVec2.x;
            gCurrentPinballGame->walkMonYPos += tempVec2.y;
            if (squaredMagnitude < 2500)
            {
                if (gCurrentPinballGame->creatureWaypointIndex < 6)
                {
                    gCurrentPinballGame->creatureWaypointIndex++;
                }
                else
                {
                    gCurrentPinballGame->creatureWaypointIndex = 3;
                    gCurrentPinballGame->boardSubState = 3;
                    gCurrentPinballGame->walkMonXVelocity = 0;
                    gCurrentPinballGame->walkMonYVelocity = 0;
                }
            }

            if (gCurrentPinballGame->waypointSubTimer < 380)
            {
                gCurrentPinballGame->cameraYAdjust++;
            }
            else if (gCurrentPinballGame->waypointSubTimer >= 400)
            {
                if (gCurrentPinballGame->cameraYAdjust > 0)
                    gCurrentPinballGame->cameraYAdjust--;
            }
        }

        DmaCopy16(3, gCatchSpriteFrameBuffer[var0], (void *)0x060112A0, 0x120);
        gCurrentPinballGame->waypointSubTimer++;
        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
        break;
    case 3:
        tempVec.x = gEggWalkPathWaypoints[gMain.selectedField][gCurrentPinballGame->creatureWaypointIndex].x - 120 - gCurrentPinballGame->walkMonXPos;
        tempVec.y = gEggWalkPathWaypoints[gMain.selectedField][gCurrentPinballGame->creatureWaypointIndex].y - 160 - gCurrentPinballGame->walkMonYPos;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = -(Sin(angle) * 7) / 20000;
        if (gCurrentPinballGame->captureFlashTimer)
        {
            gCurrentPinballGame->captureFlashTimer--;
            var0 = 14;
        }
        else
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].specialEggFlag)
            {
                var0 = gAngleToDirectionTable[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
            }
            else
            {
                var0 = gAngleToDirectionTable[angle / 0x2000] + (gMain.systemFrameCount % 32) / 8 - ((gMain.systemFrameCount % 32) / 24) * 2;
            }

            gCurrentPinballGame->walkMonXPos += tempVec2.x;
            gCurrentPinballGame->walkMonYPos += tempVec2.y;
        }

        if (squaredMagnitude < 2500)
        {
            if (gCurrentPinballGame->creatureWaypointIndex < 28)
            {
                gCurrentPinballGame->creatureWaypointIndex++;
            }
            else
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL);
                gCurrentPinballGame->stageTimer = 200;
                gCurrentPinballGame->boardSubState = 6;
            }
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->creatureWaypointIndex > 26)
                priority = 2;
            else
                priority = 1;
        }
        else if (gCurrentPinballGame->creatureWaypointIndex > 27)
        {
            priority = 3;
            gCurrentPinballGame->eggHatchShockWallOverride = 1;
        }
        else
        {
            priority = 1;
        }

        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        DmaCopy16(3, gCatchSpriteFrameBuffer[var0], (void *)0x060112A0, 0x120);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->creatureHitCooldown)
        {
            gCurrentPinballGame->creatureHitCooldown--;
        }
        else
        {
            tempVec.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->walkMonXPos / 10 + 12);
            tempVec.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->walkMonYPos / 10 + 14);
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            if (squaredMagnitude < 82)
            {
                gCurrentPinballGame->creatureHitCount++;
                gCurrentPinballGame->creatureHitCooldown = 4;
                gCurrentPinballGame->captureFlashTimer = 20;
                if (gCurrentPinballGame->creatureHitCount > 1)
                    gCurrentPinballGame->boardSubState = 4;

                m4aSongNumStart(SE_PICHU_IN_POSITION_CHIRP);
                angle2 = ArcTan2(-gCurrentPinballGame->ball->velocity.x, gCurrentPinballGame->ball->velocity.y);
                if (gCurrentPinballGame->creatureHitCount > 1)
                {
                    gCurrentPinballGame->ball->velocity.x = (Cos(angle2) * 400) / 20000;
                    gCurrentPinballGame->ball->velocity.y = -(Sin(angle2) * 400) / 20000;
                }
                else
                {
                    gCurrentPinballGame->ball->velocity.x = (Cos(angle2) * 160) / 20000;
                    gCurrentPinballGame->ball->velocity.y = -(Sin(angle2) * 160) / 20000;
                }

                PlayRumble(7);
            }
        }
        break;
    case 4:
        gCurrentPinballGame->activePortraitType = 9;
        DmaCopy16(3, gCapturePalette, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gCaptureScreenTilesGfx, (void *)0x06015800, 0x1C00);
        DmaCopy16(3, &gBallUpgradeTilesGfx[gCurrentPinballGame->ballUpgradeType * 0x200], (void *)0x060164C0, 0x80);
        DmaCopy16(3, &gBallUpgradeTilesGfx[(gCurrentPinballGame->ballUpgradeType * 8 + 4) * 0x40], (void *)0x06016760, 0x80);
        gCurrentPinballGame->captureSequenceFrame = 0;
        gCurrentPinballGame->captureState = 2;
        gCurrentPinballGame->catchTargetX = gCurrentPinballGame->walkMonXPos / 10 + 8;
        gCurrentPinballGame->catchTargetY = gCurrentPinballGame->walkMonYPos / 10 - 31;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->hatchTilePalette[i] = 13;

        gCurrentPinballGame->boardSubState++;
        group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY > 180)
            group->baseY = 180;

        DmaCopy16(3, gCatchAnimTileBuffer, (void *)0x060112A0, 0x120);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = 2;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->stageTimer = 0;
        break;
    case 5:
        if (gCurrentPinballGame->captureSequenceTimer < 17)
            priority = 2;
        else
            priority = 0;

        if (group->available)
        {
            group->baseX = gCurrentPinballGame->walkMonXPos / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->walkMonYPos / 10 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = priority;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            DmaCopy16(3, gCatchAnimTileBuffer, (void *)0x060112A0, 0x120);
            if (gCurrentPinballGame->captureSequenceTimer == 23)
                gMain.fieldSpriteGroups[41]->available = 0;
        }
        break;
    case 6:
        if (group->available)
        {
            group->baseX = 0;
            group->baseY = 200;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
        gMain.fieldSpriteGroups[41]->available = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        CleanupEggModeState();
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->eggHatchShockWallOverride = 0;
        break;
    case 8:
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

void DisableHatchTileDisplay(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.fieldSpriteGroups[18];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[18]->available = 0;
    group = gMain.fieldSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.fieldSpriteGroups[12]->available = 0;
    gCurrentPinballGame->activePortraitType = 0;
}

void RevealSequentialHatchTiles(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;
    int var1;

    var1 = 1;
    gMain.fieldSpriteGroups[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 0)
        UpdateSequentialTileParticles();

    if (gCurrentPinballGame->hatchSequentialTilesRevealed < gCurrentPinballGame->hatchTilesBoardAcknowledged)
    {
        if (gCurrentPinballGame->hatchFrameId == 0 && gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer == 0)
        {
            gCurrentPinballGame->activePortraitType = 11;
            DmaCopy16(3, gHatchRevealPalette, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gHatchRevealTilesGfx, (void *)0x06015800, 0x2800);
        }

        if (gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][1] > gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer)
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
            gCurrentPinballGame->hatchFrameId++;
            if (gCurrentPinballGame->hatchFrameId > 12)
            {
                gCurrentPinballGame->hatchSequentialTilesRevealed++;
                gCurrentPinballGame->hatchFrameId = 0;
                var1 = 0;
                gCurrentPinballGame->hatchTilesRemaining--;
                if (gCurrentPinballGame->hatchSequentialTilesRevealed == gCurrentPinballGame->hatchTilesBoardAcknowledged)
                {
                    if (gCurrentPinballGame->hatchTilesRemaining >= 0)
                        gCurrentPinballGame->activePortraitType = 0;
                }

                if (gCurrentPinballGame->hatchTilesRemaining < 0)
                {
                    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                    for (i = 0; i < 6; i++)
                        gCurrentPinballGame->hatchTileShufflePool[i] = i;

                    var0 = gMain.systemFrameCount % 6;
                    gCurrentPinballGame->hatchTilesRemaining = 5;
                    gCurrentPinballGame->boardSubState++;
                    gMain.fieldSpriteGroups[18]->available = 0;
                }
                else if (gCurrentPinballGame->hatchTilesRemaining == 0)
                {
                    var0 = 0;
                }
                else
                {
                    var0 = gMain.systemFrameCount % gCurrentPinballGame->hatchTilesRemaining;
                }

                gCurrentPinballGame->hatchGridCellIndex = gCurrentPinballGame->hatchTileShufflePool[var0];
                for (i = var0; i < gCurrentPinballGame->hatchTilesRemaining; i++)
                    gCurrentPinballGame->hatchTileShufflePool[i] = gCurrentPinballGame->hatchTileShufflePool[i + 1];
            }
            else
            {
                if (gCurrentPinballGame->hatchFrameId == 1)
                    gCurrentPinballGame->hatchTilePalette[gCurrentPinballGame->hatchGridCellIndex] = 13;
            }
        }
    }
    else
    {
        var1 = 0;
    }

    if (gCurrentPinballGame->hatchFrameId == 1)
    {
        m4aSongNumStart(SE_CATCH_TILE_REVEAL);
        InitSequentialTileParticles();
    }

    if (gCurrentPinballGame->hatchFrameId == 12)
        var1 = 0;

    group = gMain.fieldSpriteGroups[18];
    if (var1)
    {
        group->baseX = (gCurrentPinballGame->hatchGridCellIndex % 3) * 16 - (gCurrentPinballGame->cameraXOffset - 96);
        group->baseY = (gCurrentPinballGame->hatchGridCellIndex / 3) * 16 - (gCurrentPinballGame->cameraYOffset - 300);
    }
    else
    {
        group->baseY = 200;
    }

    if (group->baseY >= 200)
        group->baseY = 200;

    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 0];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 1];
        *dst++ = gHatchSequentialTileBreakSpritesheetOam[gHatchSequentialTileFramesetData[gCurrentPinballGame->hatchFrameId][0]][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].priority = 3;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RevealAllHatchTilesAtOnce(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    switch (gCurrentPinballGame->hatchRevealPhase)
    {
    case 0:
        if (gCurrentPinballGame->revealAnimFrameCounter < 60)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
        }
        gMain.blendControl = 0xCE;
        break;
    case 1:
        gCurrentPinballGame->activePortraitType = 5;
        DmaCopy16(3, gHatchStartTilesGfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gHatchStartPalette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[35]->available = 1;
        m4aSongNumStart(SE_CATCH_ALL_REVEAL_LIGHTNING);
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->revealFramesetIndex = 0;
        break;
    case 2:
        if (gHatchRevealSparkleTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex++;
            if (gCurrentPinballGame->revealFramesetIndex > 7)
            {
                gCurrentPinballGame->revealFramesetIndex = 7;
                gCurrentPinballGame->hatchRevealPhase++;
                gMain.fieldSpriteGroups[35]->available = 0;
            }
        }

        var0 = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[35];
        group->baseX = 124 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 244 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchRevealOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 3:
        gCurrentPinballGame->activePortraitType = 6;
        DmaCopy16(3, gHatchStage2TilesGfx, (void *)0x06015800, 0x800);
        DmaCopy16(3, gHatchStage2Palette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[36]->available = 1;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->revealAnimFrameCounter = 0;
        gCurrentPinballGame->startButtonDisabled = 1;
        break;
    case 4:
        var0 = gCurrentPinballGame->revealAnimFrameCounter / 2;
        if (gCurrentPinballGame->revealAnimFrameCounter < 15)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gMain.fieldSpriteGroups[36]->available = 0;
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex = 0;
        }

        group = gMain.fieldSpriteGroups[36];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchFullRevealOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 5:
        gCurrentPinballGame->activePortraitType = 7;
        DmaCopy16(3, gHatchStage3TilesGfx, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gHatchStage3Palette, (void *)0x050003C0, 0x20);
        gCurrentPinballGame->hatchRevealPhase++;
        InitBurstTileParticles();
        m4aSongNumStart(SE_CATCH_ALL_REVEAL_SHATTER);
        break;
    case 6:
        gMain.blendBrightness = 0;
        gMain.blendControl = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8) | 0xA0;
        if (gCurrentPinballGame->revealAnimFrameCounter < 73)
        {
            s16 var1;
            if (gCurrentPinballGame->revealAnimFrameCounter < 8)
            {
                gMain.blendBrightness = 16;
            }
            else
            {
                for (i = 0; i < 6; i++)
                    gCurrentPinballGame->hatchTilePalette[i] = 13;

                gMain.blendBrightness = ((8 - gCurrentPinballGame->revealAnimFrameCounter) / 4) + 16;
            }
        }

        if (gCurrentPinballGame->revealAnimFrameCounter < 72)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->hatchRevealPhase++;
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex = 0;
        }

        if (gCurrentPinballGame->revealAnimFrameCounter > 8U)
        {
            if (gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer < 0x7000)
                UpdateBurstTileParticles();
        }
        break;
    case 7:
        gCurrentPinballGame->activePortraitType = 8;
        DmaCopy16(3, gHatchFinalTilesGfx, (void *)0x06015800, 0x1800);
        DmaCopy16(3, gHatchFinalPalette, (void *)0x050003C0, 0x20);
        gMain.fieldSpriteGroups[37]->available = 1;
        gCurrentPinballGame->hatchRevealPhase++;
        gCurrentPinballGame->startButtonDisabled = 0;
        break;
    case 8:
        if (gHatchRevealFinalTimings[gCurrentPinballGame->revealFramesetIndex] > gCurrentPinballGame->revealAnimFrameCounter)
        {
            gCurrentPinballGame->revealAnimFrameCounter++;
        }
        else
        {
            gCurrentPinballGame->revealAnimFrameCounter = 0;
            gCurrentPinballGame->revealFramesetIndex++;
            if (gCurrentPinballGame->revealFramesetIndex > 10)
            {
                gCurrentPinballGame->boardSubState++;
                gMain.fieldSpriteGroups[37]->available = 0;
                gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                gMain.blendControl = 0xCE;
                gMain.blendBrightness = 0;
                gMain.fieldSpriteGroups[37]->available = 0;
                gCurrentPinballGame->revealFramesetIndex = 10;
                gCurrentPinballGame->activePortraitType = 0;
            }
        }

        var0 = gCurrentPinballGame->revealFramesetIndex;
        group = gMain.fieldSpriteGroups[37];
        group->baseX = 96 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 300 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 0];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 1];
            *dst++ = gHatchSequentialOamFramesets[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    }
}

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

    DmaCopy16(3, gHatchCompletePalette, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gEggPortraitTilesGfx, (void *)0x06015800, 0x280);
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
                    gCurrentPinballGame->sapphirePondFlag = 1;
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
    gCurrentPinballGame->rouletteSlotActive = 0;
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

void CleanupCatchEmState(void)
{
    s16 i;

    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gMain.fieldSpriteGroups[18]->available = 0;
    gMain.fieldSpriteGroups[12]->available = 0;
    gCurrentPinballGame->jirachiCollisionEnabled = 0;
    LoadPortraitGraphics(0, 0);
    gCurrentPinballGame->portraitDisplayState = 0;
    ResetEventState();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->hatchTilePalette[i] = 13;

    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->evoItemCount)
            gCurrentPinballGame->catchLights[i] = 1;
        else
            gCurrentPinballGame->catchLights[i] = 0;
    }
}

void InitCatchEmMode(void)
{
    s16 i, j;

    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardModeType = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->creatureHitCount = 0;
    gCurrentPinballGame->creatureHitCooldown = 0;
    gCurrentPinballGame->captureFlashTimer = 0;
    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
    gCurrentPinballGame->hatchFrameId = 0;
    gCurrentPinballGame->catchArrowProgress = 0;
    gCurrentPinballGame->catchProgressFlashing = 0;

    if (gCurrentPinballGame->catchEmModeStartCount == 0)
    {
        gCurrentPinballGame->saverTimeRemaining = 6000;
    }
    else
    {
        gCurrentPinballGame->saverTimeRemaining = 4200;
    }
    gCurrentPinballGame->catchEmModeStartCount++;

    DmaCopy16(3, gDefaultBallPalette, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->hatchTileShufflePool[i] = i;
    }

    gCurrentPinballGame->hatchGridCellIndex = gMain.systemFrameCount % 6;
    gCurrentPinballGame->hatchTilesRemaining = 5;

    for (j = gCurrentPinballGame->hatchGridCellIndex; j < gCurrentPinballGame->hatchTilesRemaining; j++)
    {
        gCurrentPinballGame->hatchTileShufflePool[j] = gCurrentPinballGame->hatchTileShufflePool[j+1];
    }
}
