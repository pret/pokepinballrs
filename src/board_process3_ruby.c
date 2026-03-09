#include "global.h"
#include "functions.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

extern const void (*gUnknown_086AD4C4[])(void);
extern const void (*gUnknown_086AD4E8[])(void);

extern void RestoreSavedProgressOnTransition(void);
extern void UpdateRubyBoardVisuals(void);
extern void UpdateRubyBoardEntityLogic(void);
extern void RotateRubyHoleIndicators(void);
extern void UpdateRubyNuzleafAnimation(void);
extern void UpdateRubyShopDoorState(void);
extern void AnimateRubyShopDoor(void);
extern void DrawWhiscash(void);
extern void RubyPond_EntityLogic(void);
extern void RubyPondTriBumperHandleHitAndDraw(void);
extern void DrawRubySharpedoSprite(void);
extern void UpdatePikaSpinnerGraphics(void);
extern void AnimateRubyGulpinProjectile(void);
extern void UpdateRubyGulpinBodySprite(void);
extern void DrawRubyPondGulpinPlatforms(void);
extern void UpdateRubyPondGateHitLogic(void);
extern void DrawRubyPondGateSprites(void);
extern void UpdateEvolutionShopIcon(void);
extern void ResetHatchCaveAnimationState(void);
extern void UpdateHatchCaveAnimation(void);
extern void UpdateCyndaquilHatchCaveSprite(void);
extern void UpdateRubyRampGulpinEntity(void);
extern void DrawRubyRampPrizeIndicator(void);
extern void CopyRubyTrapGfxToVram(s16);

void RubyBoardProcess_3A_19A20(void)
{
    gCurrentPinballGame->catchModeArrows = 2;
    UpdateRubyNuzleafAnimation();
    CopyRubyTrapGfxToVram(0);
    AnimateRubyShopDoor();
    ResetHatchCaveAnimationState();
    UpdateHatchCaveAnimation();

    gCurrentPinballGame->cyndaquilSpriteX = 73;
    gCurrentPinballGame->cyndaquilSpriteY = 154;
    gCurrentPinballGame->hatchCaveState = 0;
    UpdateCyndaquilHatchCaveSprite();
    RubyPond_EntityLogic();

    gCurrentPinballGame->pondBumperAnimState[0] = 10;
    gCurrentPinballGame->pondBumperAnimState[1] = 10;
    gCurrentPinballGame->pondBumperAnimState[2] = 10;
    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_STAGGERED;
    RubyPondTriBumperHandleHitAndDraw();
    DrawRubySharpedoSprite();

    gCurrentPinballGame->pikaSpinnerFrame = 0;
    gCurrentPinballGame->pikaSpinnerFramePrev = 1;
    UpdatePikachuChargeProgress();
    UpdatePikachuChargeAnimation();
    UpdatePikaSpinnerGraphics();

    gCurrentPinballGame->pikaChargeSpriteScaleX = 256;
    gCurrentPinballGame->pikaChargeSpriteScaleY = 256;
    gCurrentPinballGame->rampPrizeType = 2;
    DrawRubyRampPrizeIndicator();

    gCurrentPinballGame->pondGateSpriteOffset[0] = 3;
    gCurrentPinballGame->pondGateSpriteOffset[1] = 3;
    UpdateEdgeIndicatorSprite();
}

void RubyBoardProcess_3B_19B10(void)
{
    ProcessBoardStateTransition();
    UpdateRubyBoardVisuals();

    if (gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        UpdateRubyBoardEntityLogic();
    }

    RotateRubyHoleIndicators();
    if (gCurrentPinballGame->bgmVolumeRestoreTimer != 0)
    {
        gCurrentPinballGame->bgmVolumeRestoreTimer--;
        if (gCurrentPinballGame->bgmVolumeRestoreTimer == 0)
        {
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        }
    }
}

void RequestBoardTransition(u8 arg0)
{
    gCurrentPinballGame->boardTransitionPhase = 2;
    gCurrentPinballGame->nextBoardState = arg0;
    if (gCurrentPinballGame->boardState == 2)
        gMain.boardSpriteGroups[13]->available = 0;
}

void ProcessBoardStateTransition(void)
{
    switch (gCurrentPinballGame->boardTransitionPhase)
    {
        case 0:
            gUnknown_086AD4C4[gCurrentPinballGame->boardState]();
            gCurrentPinballGame->boardTransitionPhase++;
            break;
        case 1:
            gUnknown_086AD4E8[gCurrentPinballGame->boardState]();
            break;
        case 2:
            RestoreSavedProgressOnTransition();
            gCurrentPinballGame->prevBoardState = gCurrentPinballGame->boardState;
            gCurrentPinballGame->boardState = gCurrentPinballGame->nextBoardState;
            gCurrentPinballGame->boardTransitionPhase = 0;
            break;
    }
}

void SelectFieldMusic(void)
{
    s16 num1;
    u8 num2;

    if (gCurrentPinballGame->prevBoardState > 0)
    {
        if (gMain.selectedField == FIELD_RUBY)
        {
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_RUBY);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_RUBY2);
            }
        }
        else
        {
            num1 = gCurrentPinballGame->numCompletedBonusStages / 5;
            if ((num1 & 1) == 0)
            {
                m4aSongNumStart(MUS_FIELD_SAPPHIRE);
            }
            else
            {
                 m4aSongNumStart(MUS_FIELD_SAPPHIRE2);
            }
        }
    }

    num2 = gCurrentPinballGame->prevBoardState - 1;
    if (num2 > 1)
    {
        gCurrentPinballGame->savedEvoHitCount = gCurrentPinballGame->activeEvoHitCount;
        gCurrentPinballGame->savedCatchArrows = gCurrentPinballGame->catchModeArrows;
        gCurrentPinballGame->activeEvoHitCount = 0;
        gCurrentPinballGame->catchModeArrows = 0;
    }
}

void CheckBonusStageReturnTimer(void)
{
    if (gCurrentPinballGame->allHolesCompleted != 0)
    {
        if (gCurrentPinballGame->allHolesCompleteCooldown != 0)
        {
            gCurrentPinballGame->allHolesCompleteCooldown--;
        }
        else
        {
            RequestBoardTransition(2);
        }
    }
}

void RestoreSavedProgressOnTransition(void)
{
    if (gCurrentPinballGame->boardState == 2 && gCurrentPinballGame->nextBoardState > 2)
        ResetBonusStageIndicators(0);

    if (gCurrentPinballGame->boardState > 2)
        return;

    if (gCurrentPinballGame->nextBoardState == 3)
    {
        gCurrentPinballGame->activeEvoHitCount = gCurrentPinballGame->savedEvoHitCount;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
        gCurrentPinballGame->savedEvoHitCount = 0;
        gCurrentPinballGame->savedCatchArrows = 0;
    }

    if (gCurrentPinballGame->nextBoardState == 4)
    {
        gCurrentPinballGame->activeEvoHitCount = gCurrentPinballGame->savedEvoHitCount;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
        gCurrentPinballGame->savedEvoHitCount = 0;
        gCurrentPinballGame->savedCatchArrows = 0;
    }
    else if (gCurrentPinballGame->nextBoardState == 6)
    {
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
        gCurrentPinballGame->activeEvoHitCount = 0;
        gCurrentPinballGame->savedEvoHitCount = 0;
        gCurrentPinballGame->savedCatchArrows = 0;
    }
    else if (gCurrentPinballGame->nextBoardState > 3)
    {
        gCurrentPinballGame->activeEvoHitCount = gCurrentPinballGame->savedEvoHitCount;
        gCurrentPinballGame->catchModeArrows = gCurrentPinballGame->savedCatchArrows;
        gCurrentPinballGame->savedEvoHitCount = 0;
        gCurrentPinballGame->savedCatchArrows = 0;
    }
}

void UpdateRubyBoardVisuals(void)
{
    int randNum;

    UpdateBannerScrolling();
    UpdateRubyShopDoorState();
    if (gCurrentPinballGame->rampPrizeCooldown != 0)
    {
        gCurrentPinballGame->rampPrizeCooldown--;
        if (gCurrentPinballGame->rampPrizeCooldown == 0)
        {
            randNum = Random();
            gCurrentPinballGame->rampPrizeType = ((randNum + gMain.systemFrameCount) % 100) + 1;
        }
    }

    if (gCurrentPinballGame->viewportBottomY < 110)
    {
        UpdateRubyNuzleafAnimation();
        AnimateRubyShopDoor();
        DrawRubyRampPrizeIndicator();
    }
    UpdateSapphirePokeballSprite();
    if (gCurrentPinballGame->viewportBottomY < 168)
    {
        UpdateHatchCaveAnimation();
    }
    if (gCurrentPinballGame->viewportBottomY < 220)
    {
        UpdateCyndaquilHatchCaveSprite();
        if (gCurrentPinballGame->shouldProcessWhiscash)
        {
            DrawWhiscash();
        }
        else
        {
            RubyPondTriBumperHandleHitAndDraw();
        }
        DrawRubySharpedoSprite();
        UpdatePikaSpinnerGraphics();
    }
    AnimateRubyGulpinProjectile();
    if (gCurrentPinballGame->viewportBottomY > 63)
    {
        UpdateRubyGulpinBodySprite();
        DrawRubyPondGulpinPlatforms();
    }
    if (gCurrentPinballGame->viewportBottomY > 115)
    {
        UpdateRubyRampGulpinEntity();
    }
    if (gCurrentPinballGame->viewportBottomY > 130)
    {
        DrawRubyPondGateSprites();
    }
    UpdateSapphireChimechoAnimState();
    if (gCurrentPinballGame->viewportBottomY > 168)
    {
        DrawSapphireChimechoSprite();
    }
    RunPikachuThunderboltSequence();
    UpdatePikachuChargeAnimation();
    RenderRubyBoardDynamicEntities();
    DrawBoardPortraitSprites();
    UpdateEvolutionShopIcon();
    UpdateEdgeIndicatorSprite();

    if (gCurrentPinballGame->coinsTotalToCollect != 0)
    {
        UpdateCoinCollectionAnimation();
    }
    BonusStage_HandleModeChangeFlags();

    if (gCurrentPinballGame->boardState28 != 0)
    {
        gCurrentPinballGame->boardState28--;
        if (gCurrentPinballGame->boardState28 == 0)
        {
            gCurrentPinballGame->boardState30 = gCurrentPinballGame->boardState34;
        }
    }
}

void UpdateRubyBoardEntityLogic(void)
{
    RubyPond_EntityLogic();
    UpdateBoardEntryHole();
    UpdatePikachuChargeProgress();
    UpdateRubyPondGateHitLogic();
    if (gCurrentPinballGame->triggerButtonCooldown != 0)
    {
        gCurrentPinballGame->triggerButtonCooldown--;
    }
}

//Duplicate of RotateSapphireHoleIndicators, with "gCurrentPinballGame->rampPrizeHitPending = 1;" added in the final if statement
void RotateRubyHoleIndicators(void)
{
    int tmp;

    if (gCurrentPinballGame->newButtonActions[0])
    {
        if (gCurrentPinballGame->outLaneSaverTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pikaSaverAnimTimer == 0 && gCurrentPinballGame->inputLockActive == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 0;
        }

        tmp = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = tmp;
    }

    if (gCurrentPinballGame->newButtonActions[1])
    {
        if (gCurrentPinballGame->outLaneSaverTimer == 0 && gCurrentPinballGame->outLanePikaPosition != 2 &&
            gCurrentPinballGame->pikaSaverAnimTimer == 0 && gCurrentPinballGame->inputLockActive == 0)
        {
            gCurrentPinballGame->outLanePikaPosition = 1;
        }

        tmp = gCurrentPinballGame->holeIndicators[3];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[2];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[1];
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[0] = tmp;

        tmp = gCurrentPinballGame->ballPowerUpLight[2];
        gCurrentPinballGame->ballPowerUpLight[2] = gCurrentPinballGame->ballPowerUpLight[1];
        gCurrentPinballGame->ballPowerUpLight[1] = gCurrentPinballGame->ballPowerUpLight[0];
        gCurrentPinballGame->ballPowerUpLight[0] = tmp;

        gCurrentPinballGame->rampPrizeHitPending = 1;
    }
}
