#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/ruby_states.h"

#define BONUS_CATCH_TIME 7200 //2 minutes, 60FPS

extern const u8 gUnknown_081C0064[];
extern const u8 *gEvoItemAppear_GfxList[];
extern const u8 gUnknown_0815C4C4[][0x20];
extern const s16 gUnknown_086AE0E6[];
extern const u16 gUnknown_086B4202[58][15];
extern const struct Vector16 gUnknown_086ACFA0[][8];
extern const s16 gUnknown_08137AB8[];
extern const s16 gUnknown_08137944[];
extern const s16 gUnknown_08055A68[][7];
extern const s16 gUnknown_08137928[];
extern const u16 gUnknown_086B51CE[18][27];
extern const u8 gUnknown_083A8AAC[];
extern const u8 gUnknown_084FA20C[];
extern const u8 gUnknown_083A07CC[];
extern const u8 gUnknown_083A27EC[];
extern const s16 gUnknown_086AE0C0[];
extern const u16 gUnknown_086B50AE[16][18];
extern const u8 gUnknown_083A29EC[];
extern const u8 gUnknown_083A320C[];
extern const u16 gUnknown_086B4F6A[18][18];
extern const u8 gUnknown_083A340C[];
extern const u8 gUnknown_083A542C[];
extern const u8 gUnknown_083A562C[];
extern const u8 gUnknown_083A6E4C[];
extern const s16 gUnknown_086AE0D0[];
extern const u16 gUnknown_086B4E62[22][12];
extern const u8 gUnknown_083A05CC[];
extern const u8 gUnknown_0839DDAC[];
extern const s16 gHatchSequentialTileFramesetData[][2];
extern const u16 gHatchSequentialTileBreakSpritesheetOam[28][18];
extern const s16 gUnknown_086AD52C[28][3];
extern const u8 gUnknown_0202C7A0[][0x120];
extern const struct Vector32 gUnknown_086AD750[];
extern const u16 gUnknown_086AD788[];
extern const struct Vector32 gUnknown_086AD580[][29];
extern const u8 gUnknown_086ACF80[];
extern const u8 gUnknown_081428D4[];
extern const u8 gUnknown_08138014[];
extern const u8 gUnknown_0202D760[];
extern const u16 gUnknown_086B4B0E[48][4][3];
extern const u16 gUnknown_086AE0B4[];
extern const struct Vector16 gUnknown_086AE0A4[];
extern const u8 gRubyStageCyndaquil_Gfx[][0x280];
extern const u8 gRubyBoardHatchCave_Gfx[][0x480];
extern const u16 gUnknown_086B4D4E[40][2][3];
extern const u8 gUnknown_083FFD4C[][0x40];
extern const u8 gUnknown_083FF04C[][0x40];
extern const s16 gUnknown_086ACFE0[];
extern const struct Vector16 gUnknown_086AE088[];
extern const u16 gUnknown_086B4850[14][15];
extern const u8 gUnknown_083A704C[];
extern const u8 gUnknown_083A806C[];
extern const u16 gUnknown_086ADFE2[][2];
extern const u16 gUnknown_086B28A0[82][6][3];
extern const u8 gUnknown_083A808C[];
extern const u8 gUnknown_0848FD8C[];
extern const u16 gUnknown_086B481A[18][3];
extern const u16 gUnknown_086B47DE[4][15];
extern const s16 gUnknown_086ADFC8[];
extern const s16 gUnknown_086ADFD4[];
extern const u8 gUnknown_0847FF0C[][0x300];
extern const u8 gUnknown_08480E0C[][0x40];
extern const s16 gUnknown_086AD456[][7];
extern const u8 gRubyBoardShop_Gfx[][0x500];
extern const u8 gUnknown_083A8A8C[];
extern const struct Vector32 gUnknown_086ADF90[];
extern const u8 gUnknown_084C156C[];

extern u8 gUnknown_020315D0[];

extern struct SongHeader se_unk_84;
extern struct SongHeader se_unk_85;
extern struct SongHeader se_unk_86;


void UpdateHatchedMonFlyingAnimation(void)
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

    group = gMain.boardSpriteGroups[41];
    if (gCurrentPinballGame->pikaSaverAnimTimer == 0)
        return;

    if (gCurrentPinballGame->pikaSaverAnimTimer == 800)
    {
        group->available = 1;
        if (gCurrentPinballGame->pikaSaverLossType == 1)
        {
            gCurrentPinballGame->ballLockStateC = 1090;
            gCurrentPinballGame->bonusSpriteYQ10 = 4680;
            gCurrentPinballGame->bonusTargetIndex = 0;
        }
        else
        {
            gCurrentPinballGame->ballLockStateC = 2000;
            gCurrentPinballGame->bonusSpriteYQ10 = 3820;
            gCurrentPinballGame->bonusTargetIndex = 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->pikaSaverAnimTimer == 799)
        {
            if (gCurrentPinballGame->pikaSaverLossType != 1)
            {
                DmaCopy16(3, gUnknown_084C07EC, (void *)0x06010600, 0x180);
            }
        }
        tempVec.x = gUnknown_086ADF90[gCurrentPinballGame->bonusTargetIndex].x - 120 - gCurrentPinballGame->ballLockStateC;
        tempVec.y = gUnknown_086ADF90[gCurrentPinballGame->bonusTargetIndex].y - 160 - gCurrentPinballGame->bonusSpriteYQ10;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = (Sin(angle) * -7) / 20000;
        index = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
        gCurrentPinballGame->ballLockStateC += tempVec2.x;
        gCurrentPinballGame->bonusSpriteYQ10 += tempVec2.y;
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
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
            gCurrentPinballGame->bonusTargetIndex++;
            if (gCurrentPinballGame->pikaSaverLossType == 1)
            {
                if (gCurrentPinballGame->bonusTargetIndex == 4)
                {
                    DmaCopy16(3, gUnknown_084C156C, (void *)0x06010600, 0x180);
                    gCurrentPinballGame->outLanePikaPosition = 2;
                    gMain.boardSpriteGroups[41]->available = 0;
                    gCurrentPinballGame->pikaSaverAnimTimer = 1;
                    m4aSongNumStart(SE_UNKNOWN_0x75);
                }
            }
            else if (gCurrentPinballGame->bonusTargetIndex == 7)
            {
                gMain.boardSpriteGroups[41]->available = 0;
                gCurrentPinballGame->pikaSaverAnimTimer = 1;
            }
        }
    }

    gCurrentPinballGame->pikaSaverAnimTimer--;
}

void ResetBonusStageIndicators(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->allHolesCompleted = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
    }

    gCurrentPinballGame->ballSpriteVariant = 0;
    gCurrentPinballGame->centerHoleAttractionActive = 0;
    if (gCurrentPinballGame->boardTransitionPhase != 2 || gCurrentPinballGame->nextBoardState < 3)
    {
        if ((gCurrentPinballGame->hatchModeFlags & 0xF) == 0)
        {
            SetBoardPortraitGraphics(0, 0);
            gCurrentPinballGame->hatchRevealState = 0;
        }
    }

    if (gCurrentPinballGame->nextBoardState == 6 && gCurrentPinballGame->boardTransitionPhase == 2)
        gCurrentPinballGame->shopDoorTargetFrame = 0;
}

void InitHatchCatchCountdownMode(void)
{
    gCurrentPinballGame->boardSubState = 1;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->slotReelConfirmed = 0;
}

void UpdateHatchCatchCountdownMode(void)
{
    switch (gCurrentPinballGame->boardSubState)
    {
    case 1:
        if (gCurrentPinballGame->stageTimer < 9)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer < 8)
            {
                gCurrentPinballGame->ballSpriteVariant = 1;
            }
            else if (gCurrentPinballGame->stageTimer == 8)
            {
                EnableBonusTrapSprite();
                gCurrentPinballGame->ballSpriteVariant = 2;
                gCurrentPinballGame->portraitAnimCounter = 0;
                SetBoardPortraitGraphics(1, 0);
                gCurrentPinballGame->boardSubState++;
            }
        }
        break;
    case 2:
        UpdateBonusTrapSprite();
        if (gCurrentPinballGame->boardEntryMode == 0)
            SetBoardPortraitGraphics(1, 0);

        if (gCurrentPinballGame->boardEntryMode == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        gCurrentPinballGame->allHolesCompleted = 0;
        gCurrentPinballGame->holeIndicators[0] = 0;
        gCurrentPinballGame->holeIndicators[1] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[2] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->holeIndicators[3] = gCurrentPinballGame->holeIndicators[0];
        gCurrentPinballGame->boardSubState++;
        InitSlotReelDisplay();
        if (gCurrentPinballGame->bonusStageEntryCount < 99)
            gCurrentPinballGame->bonusStageEntryCount++;
        break;
    case 4:
        if (gCurrentPinballGame->sequenceTimer == 148)
        {
            gCurrentPinballGame->sequenceTimer++;
            UpdateSlotReelSpin();
        }
        else if (gCurrentPinballGame->sequenceTimer == 139)
        {
        }
        else if (gCurrentPinballGame->sequenceTimer == 24)
        {
            SetBoardPortraitGraphics(0, 0);
        }
        else if (gCurrentPinballGame->sequenceTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
        }

        if (gCurrentPinballGame->slotReelConfirmed)
        {
            ProcessSlotReelPrize();
            if (gCurrentPinballGame->plungerAnimFrame < 180)
            {
                gCurrentPinballGame->sequenceTimer = 140;
                if (gCurrentPinballGame->plungerAnimFrame == 179)
                    gCurrentPinballGame->sequenceTimer = 30;
            }
        }

        gCurrentPinballGame->stageTimer = 0;
        break;
    case 5:
        UpdateBonusTrapSprite();
        gMain.boardSpriteGroups[13]->available = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 6:
        ResetBonusStageIndicators(1);
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer--;
        else
            RequestBoardTransition(1);
        break;
    }
}

void ResetBonusModeDisplayState(void)
{
    gCurrentPinballGame->ballSpriteVariant = 0;
    gCurrentPinballGame->centerHoleAttractionActive = 0;
    SetBoardPortraitGraphics(0, 0);
    gCurrentPinballGame->hatchRevealState = 0;
    gCurrentPinballGame->activatedBumperCount = 0;
    gCurrentPinballGame->bumperFlashAnimTimer = 0;
    gCurrentPinballGame->bumperHitTimers[0] = 0;
    gCurrentPinballGame->bumperHitTimers[1] = 0;
    gCurrentPinballGame->bumperHitTimers[2] = 0;
}

void InitBonusStageLegendaryMode(void)
{
    if (gMain.selectedField == FIELD_RUBY)
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->slotReelResultPair[0] = 42;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_KECLEON;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->slotReelResultPair[0] = 44;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_GROUDON;
            break;
        case 4:
            gCurrentPinballGame->slotReelResultPair[0] = 45;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_RAYQUAZA;
            break;
        }
    }
    else
    {
        switch (gCurrentPinballGame->numCompletedBonusStages % 5)
        {
        case 0:
        case 2:
            gCurrentPinballGame->slotReelResultPair[0] = 41;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_DUSCLOPS;
            break;
        case 1:
        case 3:
            gCurrentPinballGame->slotReelResultPair[0] = 43;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_KYOGRE;
            break;
        case 4:
            gCurrentPinballGame->slotReelResultPair[0] = 45;
            gCurrentPinballGame->pendingBonusFieldId = FIELD_RAYQUAZA;
            break;
        }
    }

    if (gCurrentPinballGame->boardEntryMode == 4 && gCurrentPinballGame->prevBoardState == 2)
    {
        gCurrentPinballGame->sequenceTimer = 150;
        gCurrentPinballGame->boardSubState = 3;
        gCurrentPinballGame->stageTimer = 0;
    }
    else
    {
        gCurrentPinballGame->boardSubState = 0;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitAnimCounter = 0;
        SetBoardPortraitGraphics(7, 0);
    }
}

void UpdateBonusStageLegendaryMode(void)
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
                gCurrentPinballGame->ballSpriteVariant = 1;
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

                EnableBonusTrapSprite();
                gCurrentPinballGame->ballSpriteVariant = 2;
                gCurrentPinballGame->boardSubState++;
                gCurrentPinballGame->portraitAnimCounter = 0;
            }
        }
        break;
    case 2:
        UpdateBonusTrapSprite();
        SetBoardPortraitGraphics(7, 0);
        if (gCurrentPinballGame->boardEntryMode == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitAnimCounter = 0;
        gCurrentPinballGame->slotReelResultPair[0] = 46;
        SetBoardPortraitGraphics(7, 0);
        break;
    case 4:
        if (gCurrentPinballGame->sequenceTimer == 145)
        {
            gCurrentPinballGame->sequenceTimer++;
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->sequenceTimer = 144;
                m4aMPlayAllStop();
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->sequenceTimer = 60;
                gCurrentPinballGame->boardSubState = 6;
                if (gCurrentPinballGame->allHolesCompleted)
                    gCurrentPinballGame->allHolesCompleteCooldown = 120;
            }

            gCurrentPinballGame->slotReelResultPair[0] = 46;
            SetBoardPortraitGraphics(7, 0);
        }

        if (gCurrentPinballGame->sequenceTimer == 130)
        {
            m4aSongNumStart(SE_WARP);
            gCurrentPinballGame->stageTimer = 65;
            gMain.blendControl = 0x9F;
        }

        if (gCurrentPinballGame->sequenceTimer == 125)
            gCurrentPinballGame->sequenceTimer++;

        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->pauseInputLocked = 1;
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
            gCurrentPinballGame->ballReturnMode = 0;
            TransitionToBonusField();
        }
        break;
    case 6:
        UpdateBonusTrapSprite();
        gMain.boardSpriteGroups[13]->available = 0;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        break;
    case 7:
        ResetBonusModeDisplayState();
        gCurrentPinballGame->boardSubState++;
        break;
    case 8:
        RequestBoardTransition(1);
        break;
    }
}

void EnableBonusTrapSprite(void)
{
    DmaCopy16(3, gMainStageBonusTrap_Gfx[0], (void *)0x060113C0, 0x300);
    gMain.boardSpriteGroups[13]->available = 1;
    gCurrentPinballGame->centerHoleAttractionActive = 1;
}

void UpdateBonusTrapSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[13];
    gCurrentPinballGame->trapSpriteAnimFrame = (gCurrentPinballGame->gameFrameCount % 35) / 7;
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 280 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        if (gCurrentPinballGame->boardEntryMode == 3)
        {
            group->baseY = 200;
        }
        else
        {
            if (gCurrentPinballGame->trapSpriteAnimFrame != gCurrentPinballGame->trapSpritePrevFrame)
            {
                DmaCopy16(3, gMainStageBonusTrap_Gfx[gCurrentPinballGame->trapSpriteAnimFrame], (void *)0x060113C0, 0x300);
                gCurrentPinballGame->trapSpritePrevFrame = gCurrentPinballGame->trapSpriteAnimFrame;
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

void UpdatePikachuChargeAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;
    s16 sp0[3];

    group = gMain.boardSpriteGroups[17];
    memset(sp0, 0, sizeof(sp0));
    if (gCurrentPinballGame->pikaChargeSegment != gCurrentPinballGame->pikaChargeSegmentPrev)
    {
        if (gCurrentPinballGame->pikaChargeSegment == 12) {
            if (gCurrentPinballGame->pikaChargeFlashTimer)
            {
                gCurrentPinballGame->pikaChargeFlashTimer--;
                index = ((gCurrentPinballGame->pikaChargeFlashTimer % 20) / 10) + 12;
                if (gCurrentPinballGame->pikaChargeFlashTimer < 41)
                {
                    if (gCurrentPinballGame->pikaChargeFlashTimer > 2)
                    {
                        gCurrentPinballGame->pikaChargeSpriteOffsetX += 3;
                        gCurrentPinballGame->pikaChargeSpriteY += 2;
                    }

                    gCurrentPinballGame->pikaChargeSpriteScaleX = gCurrentPinballGame->pikaChargeSpriteScaleY = ((gCurrentPinballGame->pikaChargeFlashTimer * 128) / 40) + 128;
                    sp0[1] =  ((40 - gCurrentPinballGame->pikaChargeFlashTimer) * 16) / 40;
                    sp0[0] = -((40 - gCurrentPinballGame->pikaChargeFlashTimer) * 16) / 40;
                    sp0[2] = 0;
                }
            }
            else
            {
                gCurrentPinballGame->pikaChargeSegmentPrev = 13;
                gCurrentPinballGame->pikaChargeSegment = 13;
                index = 13;
                gCurrentPinballGame->pikaChargeAnimDuration = 0;
                gCurrentPinballGame->pikaChargeSpriteY = 120;
                gCurrentPinballGame->pikaChargeFullFlashTimer = 60;
            }

            DmaCopy16(3, gUnknown_084C00EC[index], (void *)0x06010AE0, 0x80);
        }
        else
        {
            DmaCopy16(3, gUnknown_084C00EC[gCurrentPinballGame->pikaChargeSegment], (void *)0x06010AE0, 0x80);
            gCurrentPinballGame->pikaChargeSegmentPrev = gCurrentPinballGame->pikaChargeSegment;
        }
    }

    if (gCurrentPinballGame->pikaChargeAnimDuration)
    {
        gCurrentPinballGame->pikaChargeAnimDuration--;
        group->baseY = 80 + gCurrentPinballGame->pikaChargeSpriteY;
        if (gCurrentPinballGame->pikaChargeAnimDuration < 20)
            gCurrentPinballGame->pikaChargeSpriteScaleY = (gCurrentPinballGame->pikaChargeAnimDuration * 12) + 16;
    }
    else
    {
        group->baseY = 180;
    }

    group->baseX = 119 + gCurrentPinballGame->pikaChargeSpriteOffsetX;
    SetMatrixScale(gCurrentPinballGame->pikaChargeSpriteScaleX, gCurrentPinballGame->pikaChargeSpriteScaleY, 1);
    for (i = 0; i < 3; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + sp0[i];
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_NORMAL;
        gOamBuffer[oamSimple->oamId].matrixNum = 1;
    }
}

void UpdateEvolutionShopIcon(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[78];
    if (gCurrentPinballGame->trapDoorAnimActive == 0)
    {
        if (gCurrentPinballGame->savedEvoHitCount > 2)
        {
            if (gCurrentPinballGame->evolvablePartySize > 0 && gCurrentPinballGame->trapDisplayState == 0)
            {
                gCurrentPinballGame->trapDoorAnimActive = 1;
                gCurrentPinballGame->slotReelFrame = 0;
                gCurrentPinballGame->trapDisplayState = 1;
            }
        }
        else if (gCurrentPinballGame->boardState != 6 && gCurrentPinballGame->trapDisplayState == 1 && gCurrentPinballGame->boardEntryMode != 4)
        {
            gCurrentPinballGame->trapDoorAnimActive = 1;
            gCurrentPinballGame->slotReelFrame = 0;
            gCurrentPinballGame->trapDisplayState = 0;
        }
    }
    else
    {
        index = gUnknown_086AD456[gCurrentPinballGame->trapDisplayState][(gCurrentPinballGame->slotReelFrame % 42) / 6];
        if (gCurrentPinballGame->slotReelFrame == 0)
        {
            group->available = 1;
            DmaCopy16(3, gUnknown_083A8A8C, (void *)0x05000240, 0x20);
        }
        else if (gCurrentPinballGame->slotReelFrame == 37)
        {
            m4aSongNumStart(SE_UNKNOWN_0xCA);
        }

        if (gCurrentPinballGame->slotReelFrame % 6 == 0)
        {
            DmaCopy16(3, gRubyBoardShop_Gfx[index], (void *)0x06013D00, 0x500);
        }

        group->baseX = 181 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 48 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY < -50)
            group->baseY = -50;

        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        gCurrentPinballGame->slotReelFrame++;
        if (gCurrentPinballGame->slotReelFrame > 40)
        {
            CopyRubyTrapGfxToVram(gCurrentPinballGame->trapDisplayState);
            gCurrentPinballGame->trapDoorAnimActive = 0;
            gMain.spriteGroups[78].available = 0;
        }
    }
}

void UpdatePikachuAttackDisplay(s16 arg0)
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

    group = gMain.boardSpriteGroups[7];
    var1 = gUnknown_086AD000[gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor]];
    if (arg0)
    {
        index = var1[3] / 10;
        DmaCopy16(3, gUnknown_08480E0C[index], (void *)0x06015DA0, 0x40);
        index = var1[3] % 10;
        DmaCopy16(3, gUnknown_08480E0C[index], (void *)0x06015E60, 0x40);
    }

    if (group->available)
    {
        group->baseX = 156 + gCurrentPinballGame->bannerScrollOffset;
        group->baseY = 96;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = gMain.boardSpriteGroups[8];
    index = gCurrentPinballGame->trapDisplayState != 0 ? 1 : 0;
    if (group->available)
    {
        group->baseX = (gCurrentPinballGame->bannerScrollOffset + 136);
        group->baseY = 88;
        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 0];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 1];
            *dst++ = gUnknown_086B47DE[index][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = gMain.boardSpriteGroups[6];
    if (group->available)
    {
        if (gMain.splitScreenOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        sp0[0] = -gUnknown_086ADFC8[(gMain.systemFrameCount % 30) / 5];
        sp0[1] = gUnknown_086ADFC8[(gMain.systemFrameCount % 30) / 5];
        sp4[0] = sp0[0];
        sp4[1] = sp0[1];
        if (gCurrentPinballGame->trapDisplayState == 0)
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

        if (gCurrentPinballGame->trapDisplayState == 0)
            group->baseY = 180;
        else if (gMain.splitScreenOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 86;

        group->baseX = 48;
        if (gCurrentPinballGame->evoStageSelection < gCurrentPinballGame->maxEvoStages)
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

        if (gCurrentPinballGame->evoStageSelection > 0)
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

    group = gMain.boardSpriteGroups[9];
    if (group->available)
    {
        group->baseX = 48;
        if (gMain.splitScreenOffset < 20)
            group->baseY = 180;
        else
            group->baseY = 88;

        if (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 4)
        {
            if (gCurrentPinballGame->bonusStagePurchased && gCurrentPinballGame->bannerAnimTimer / 5 == 0)
                index = 4;
            else
                index = gUnknown_086ADFD4[gCurrentPinballGame->bannerAnimTimer / 5];
        }
        else if (gUnknown_086AD2DE[gCurrentPinballGame->upgradeMenuCursor] == 3)
        {
            if (gCurrentPinballGame->pikaChargeFull && gCurrentPinballGame->bannerAnimTimer / 5 == 0)
                index = 4;
            else
                index = gUnknown_086ADFD4[gCurrentPinballGame->bannerAnimTimer / 5];
        }
        else
        {
            index = gUnknown_086ADFD4[gCurrentPinballGame->bannerAnimTimer / 5];
        }

        DmaCopy16(3, gUnknown_0847FF0C[index], (void *)0x06016220, 0x300);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void UpdateCoinCollectionAnimation(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int var1;
    s16 var2;

    group = gMain.boardSpriteGroups[39];
    if (gCurrentPinballGame->coinAnimFrameCounter < ((gCurrentPinballGame->coinsTotalToCollect - 1) * 9) + 19)
    {
        if (gCurrentPinballGame->coinAnimFrameCounter == 0)
        {
            group->available = 1;
            gCurrentPinballGame->coinsCollected = 0;
            for (i = 0; i < 2; i++)
            {
                gCurrentPinballGame->coinSpriteTimers[i] = 0;
                gCurrentPinballGame->coinSpritePositions[i].x = 70;
                gCurrentPinballGame->coinSpritePositions[i].y = 180;
            }

            gCurrentPinballGame->coinCollectBonusInput = 0;
        }
        else
        {
            if (gCurrentPinballGame->boardEntryMode == 4 && (gCurrentPinballGame->newButtonActions[1] || JOY_NEW(A_BUTTON)))
                gCurrentPinballGame->coinCollectBonusInput = 1;

            if (gCurrentPinballGame->coinsCollected < gCurrentPinballGame->coinsTotalToCollect)
            {
                var1 = gCurrentPinballGame->coinAnimFrameCounter - 1;
                if (var1 % 9 == 0)
                {
                    if (gCurrentPinballGame->coinCollectBonusInput)
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinSpriteTimers[var2] = 17;
                        gCurrentPinballGame->coinSpritePositions[var2].x = 188;
                        gCurrentPinballGame->coinSpritePositions[var2].y = 140;
                        m4aSongNumStart(SE_UNKNOWN_0x7E);
                        gCurrentPinballGame->coins += gCurrentPinballGame->coinsTotalToCollect - gCurrentPinballGame->coinsCollected;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = (gCurrentPinballGame->coinsTotalToCollect - gCurrentPinballGame->coinsCollected) * 100;
                        gCurrentPinballGame->coinAnimFrameCounter = (gCurrentPinballGame->coinsTotalToCollect * 9) + 1;
                        gCurrentPinballGame->coinsCollected = gCurrentPinballGame->coinsTotalToCollect;
                    }
                    else
                    {
                        var2 = (var1 % 18) / 9;
                        gCurrentPinballGame->coinSpriteTimers[var2] = 17;
                        gCurrentPinballGame->coinSpritePositions[var2].x = 188;
                        gCurrentPinballGame->coinSpritePositions[var2].y = 140;
                        gCurrentPinballGame->coinsCollected++;
                        m4aSongNumStart(SE_UNKNOWN_0x7E);
                        gCurrentPinballGame->coins++;
                        if (gCurrentPinballGame->coins > 99)
                            gCurrentPinballGame->coins = 99;

                        gCurrentPinballGame->scoreAddedInFrame = 100;
                    }
                }
            }

            for (i = 0; i < 2; i++)
            {
                group->baseX = gCurrentPinballGame->coinSpritePositions[i].x;
                group->baseY = gCurrentPinballGame->coinSpritePositions[i].y;
                if (gCurrentPinballGame->coinSpritePositions[i].y > 160)
                    var0 = 0;
                else
                    var0 = (17 - gCurrentPinballGame->coinSpriteTimers[i]) / 2;

                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B481A[var0];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;

                if (gCurrentPinballGame->coinSpriteTimers[i] > 0)
                {
                    gCurrentPinballGame->coinSpriteTimers[i]--;
                    if (gCurrentPinballGame->coinSpriteTimers[i] == 0)
                    {
                        gCurrentPinballGame->coinSpritePositions[i].x = 70;
                        gCurrentPinballGame->coinSpritePositions[i].y = 180;
                    }
                }
            }
        }

        gCurrentPinballGame->coinAnimFrameCounter++;
        if (gCurrentPinballGame->coinAnimFrameCounter == ((gCurrentPinballGame->coinsTotalToCollect - 1) * 9) + 19)
        {
            gMain.boardSpriteGroups[39]->available = 0;
            gCurrentPinballGame->coinsTotalToCollect = 0;
            if (gCurrentPinballGame->boardEntryMode == 4)
                gCurrentPinballGame->plungerAnimFrame = 170;
        }
    }
}

void InitLotadBonusCelebration(void)
{
    gCurrentPinballGame->holeCelebSpriteXQ20 = 1600;
    gCurrentPinballGame->holeCelebSpriteYQ20 = 2080;
    gCurrentPinballGame->lotadCelebKeyframeIndex = 0;
    gCurrentPinballGame->lotadCelebSubFrame = 0;
    gMain.spriteGroups[82].available = 1;
    gCurrentPinballGame->pondAnimState = 1;
    gCurrentPinballGame->ballLockState4 = 240;
    gCurrentPinballGame->ballLockState6 = 160;
    gCurrentPinballGame->bannerType = 3;
    DmaCopy16(3, gUnknown_083A808C, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_0848FD8C, (void *)0x06015800, 0xCA0);
}

void UpdateLotadBonusCelebration(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;

    var0 = 0;
    group = &gMain.spriteGroups[82];
    if (gUnknown_086ADFE2[gCurrentPinballGame->lotadCelebKeyframeIndex][1] > gCurrentPinballGame->lotadCelebSubFrame)
    {
        gCurrentPinballGame->lotadCelebSubFrame++;
    }
    else
    {
        gCurrentPinballGame->lotadCelebKeyframeIndex++;
        gCurrentPinballGame->lotadCelebSubFrame = 0;
        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 41)
        {
            gCurrentPinballGame->lotadCelebKeyframeIndex = 40;
            group->available = 0;
            gCurrentPinballGame->hatchCaveCompletionFlag = 2;
            gCurrentPinballGame->bannerType = 0;
        }

        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 1)
            m4aSongNumStart(SE_UNKNOWN_0x146);

        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 7)
            m4aSongNumStart(SE_UNKNOWN_0x147);

        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 13)
            m4aSongNumStart(SE_UNKNOWN_0x148);

        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 39)
        {
            gCurrentPinballGame->ballLockState4 = 0;
            gCurrentPinballGame->ballLockState6 = 0;
            DmaCopy16(3, gUnknown_084FD18C[0], (void *)0x06011CE0, 0x200);
        }

        if (gCurrentPinballGame->lotadCelebKeyframeIndex == 14)
            gCurrentPinballGame->scoreAddedInFrame = 2000000;
    }

    if (gCurrentPinballGame->lotadCelebKeyframeIndex >= 14 && gCurrentPinballGame->lotadCelebKeyframeIndex < 38 && gCurrentPinballGame->gameFrameCount % 7 == 0)
        m4aSongNumStart(SE_UNKNOWN_0x149);

    group->baseX = gCurrentPinballGame->holeCelebSpriteXQ20 / 20 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = gCurrentPinballGame->holeCelebSpriteYQ20 / 20 - gCurrentPinballGame->bgScrollYWithOffset;
    var0 = gUnknown_086ADFE2[gCurrentPinballGame->lotadCelebKeyframeIndex][0];
    for (i = 0; i < 6; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B28A0[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void InitStandardHoleBonusCelebration(void)
{
    gCurrentPinballGame->holeCelebAnimFrame = 0;
    gCurrentPinballGame->holeCelebSpriteXQ20 = 3600;
    gCurrentPinballGame->holeCelebSpriteYQ20 = -40;
    gCurrentPinballGame->holeCelebVelX = -36;
    gCurrentPinballGame->holeCelebVelY = 60;
    gMain.spriteGroups[12].available = 1;
    gCurrentPinballGame->pondAnimState = 1;
    gCurrentPinballGame->ballLockState4 = gCurrentPinballGame->holeCelebSpriteXQ20 / 20 - gUnknown_086AE088[0].x;
    gCurrentPinballGame->ballLockState6 = gCurrentPinballGame->holeCelebSpriteYQ20 / 20 - gUnknown_086AE088[0].y;
    gCurrentPinballGame->bannerType = 2;
    DmaCopy16(3, gUnknown_083A806C, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_083A704C, (void *)0x06015800, 0x1000);
}

void UpdateStandardHoleBonusCelebration(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    s16 var0;

    var0 = (gCurrentPinballGame->holeCelebAnimFrame % 56) / 8;
    group = &gMain.spriteGroups[12];
    if (gCurrentPinballGame->holeCelebAnimFrame < 130)
    {
        if (gCurrentPinballGame->holeCelebAnimFrame % 36U == 0)
            m4aSongNumStart(SE_UNKNOWN_0xB8);

        gCurrentPinballGame->holeCelebAnimFrame++;
        gCurrentPinballGame->holeCelebSpriteXQ20 += gCurrentPinballGame->holeCelebVelX;
        gCurrentPinballGame->holeCelebSpriteYQ20 += gCurrentPinballGame->holeCelebVelY;
        if (gCurrentPinballGame->holeCelebVelY > 7 || gMain.systemFrameCount % 3 == 0)
            gCurrentPinballGame->holeCelebVelY--;

        if (gCurrentPinballGame->holeCelebAnimFrame < 78)
        {
            gCurrentPinballGame->ballLockState4 = gCurrentPinballGame->holeCelebSpriteXQ20 / 20 - gUnknown_086AE088[var0].x;
            gCurrentPinballGame->ballLockState6 = gCurrentPinballGame->holeCelebSpriteYQ20 / 20 - gUnknown_086AE088[var0].y;
        }
        else
        {
            gCurrentPinballGame->ballLockState4 = 0;
            gCurrentPinballGame->ballLockState6 = 0;
        }

        if (gCurrentPinballGame->holeCelebAnimFrame == 78)
            gCurrentPinballGame->scoreAddedInFrame = 100000;

        DmaCopy16(3, gUnknown_084FD18C[0], (void *)0x06011CE0, 0x200);
    }
    else
    {
        group->available = 0;
        do {} while (0); // needed to match, there was probably some dead code
        gCurrentPinballGame->hatchCaveCompletionFlag = 2;
        gCurrentPinballGame->bannerType = 0;
    }

    group->baseX = gCurrentPinballGame->holeCelebSpriteXQ20 / 20 - gCurrentPinballGame->bgScrollXCopy;
    group->baseY = gCurrentPinballGame->holeCelebSpriteYQ20 / 20 - gCurrentPinballGame->bgScrollYWithOffset;
    for (i = 0; i < 5; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16 *)&gOamBuffer[oamSimple->oamId];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 0];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 1];
        *dst++ = gUnknown_086B4850[var0][i * 3 + 2];

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void ShowSpeciesNameBanner(void)
{
    s16 i;
    int index;

    gCurrentPinballGame->speciesNamePixelOffset = 0;
    SetBoardPortraitGraphics(9, 0);
    gCurrentPinballGame->bannerType = 14;
    gMain.boardSpriteGroups[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->speciesNamePixelOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }
}

void UpdateSpeciesNameBannerPosition(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[4];
    for (i = 0; i < 10; i++)
    {
        group->baseX = i * 8 + (gCurrentPinballGame->speciesNamePixelOffset + 152) + gCurrentPinballGame->bannerScrollOffset;
        group->baseY = 96;
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void HideSpeciesNameBanner(void)
{
    gMain.boardSpriteGroups[4]->available = 0;
    gCurrentPinballGame->bannerType = 0;
}

void InitEvolutionNameRevealBanner(void)
{
    s16 i;
    u8 letter;
    int index;
    const u8 *dest;

    gCurrentPinballGame->speciesNamePixelOffset = 0;
    gCurrentPinballGame->spriteLayerPriority = 0;
    gCurrentPinballGame->nameRevealScrollProgress = 0;
    SetBoardPortraitGraphics(3, 0);
    gCurrentPinballGame->bannerType = 13;
    gMain.boardSpriteGroups[4]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + i * 0x40, 0x40);
            gCurrentPinballGame->speciesNamePixelOffset += 4;
        }
        else
        {
            index = gSpeciesInfo[gCurrentPinballGame->currentSpecies].name[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + i * 0x40, 0x40);
        }
    }

    gMain.boardSpriteGroups[5]->available = 1;
    for (i = 0; i < 10; i++)
    {
        if (gUnknown_086ACFE0[i] == 0x20)
        {
            DmaCopy16(3, gUnknown_083FFD4C[0], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
        else
        {
            index = gUnknown_086ACFE0[i] - 0x41;
            DmaCopy16(3, gUnknown_083FF04C[index], (void *)0x06015800 + (i + 10) * 0x40, 0x40);
        }
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->nameLetterStaggerDelay[i] = i * 2;
        gCurrentPinballGame->nameLetterSlidePos[i].x = 0;
    }

    for (i = 0; i < 10; i++)
    {
        gCurrentPinballGame->boardStateD4[i] = (i + 10) * 2;
        gCurrentPinballGame->boardStateE8[i].x = 0;
    }
}

void UpdateEvolutionNameRevealBanner(void)
{
    s16 i, j, k;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 var0;

    gCurrentPinballGame->hatchRevealState = 0;
    if (gCurrentPinballGame->nameRevealScrollProgress == 0)
    {
        gCurrentPinballGame->nameRevealScrollProgress++;
        group = gMain.boardSpriteGroups[4];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = gMain.boardSpriteGroups[5];
        group->baseX = 0;
        group->baseY = 180;
        for (i = 0; i < 10; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
    else if (gCurrentPinballGame->nameRevealScrollProgress < 195)
    {
        gCurrentPinballGame->nameRevealScrollProgress++;
        if (gCurrentPinballGame->nameRevealScrollProgress < 156)
        {

            group = gMain.boardSpriteGroups[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameLetterStaggerDelay[i])
                {
                    gCurrentPinballGame->nameLetterStaggerDelay[i]--;
                }
                else
                {
                    gCurrentPinballGame->nameLetterSlidePos[i].x += ((1600 - gCurrentPinballGame->nameLetterSlidePos[i].x) * 12) / 100;
                    if (gCurrentPinballGame->nameLetterSlidePos[i].x >= 1592)
                        gCurrentPinballGame->nameLetterSlidePos[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->bgScrollXCopy - (gCurrentPinballGame->nameLetterSlidePos[i].x / 10 - var0) + gCurrentPinballGame->speciesNamePixelOffset;;
                group->baseY = gCurrentPinballGame->bossGroupBasePosition.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.boardSpriteGroups[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->boardStateD4[i])
                {
                    gCurrentPinballGame->boardStateD4[i]--;
                }
                else
                {
                    gCurrentPinballGame->boardStateE8[i].x += ((1600 - gCurrentPinballGame->boardStateE8[i].x) * 12) / 100;
                    if (gCurrentPinballGame->boardStateE8[i].x >= 1592)
                        gCurrentPinballGame->boardStateE8[i].x = 1600;
                }

                var0 = 160;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->bgScrollXCopy - (gCurrentPinballGame->boardStateE8[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->bossGroupBasePosition.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->nameRevealScrollProgress == 155)
            {
                for (j = 0; j < 10; j++)
                {
                    gCurrentPinballGame->nameLetterStaggerDelay[j] = j * 2;
                    gCurrentPinballGame->nameLetterSlidePos[j].x = 0;
                }

                for (k = 0; k < 10; k++)
                {
                    gCurrentPinballGame->boardStateD4[k] = (k + 10) * 2;
                    gCurrentPinballGame->boardStateE8[k].x = 0;
                }
            }
        }
        else
        {
            group = gMain.boardSpriteGroups[4];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->nameLetterStaggerDelay[i])
                    gCurrentPinballGame->nameLetterStaggerDelay[i]--;
                else
                    gCurrentPinballGame->nameLetterSlidePos[i].x += ((2000 - gCurrentPinballGame->nameLetterSlidePos[i].x) * 12) / 100;

                var0 = i * 8 + 80;
                group->baseX = var0 - gCurrentPinballGame->bgScrollXCopy - gCurrentPinballGame->nameLetterSlidePos[i].x / 10 + gCurrentPinballGame->speciesNamePixelOffset;
                group->baseY = gCurrentPinballGame->bossGroupBasePosition.y + 36;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            group = gMain.boardSpriteGroups[5];
            for (i = 0; i < 10; i++)
            {
                if (gCurrentPinballGame->boardStateD4[i])
                    gCurrentPinballGame->boardStateD4[i]--;
                else
                    gCurrentPinballGame->boardStateE8[i].x += ((2000 - gCurrentPinballGame->boardStateE8[i].x) * 12) / 100;

                var0 = 0;
                group->baseX = i * 8 + 80 - gCurrentPinballGame->bgScrollXCopy - (gCurrentPinballGame->boardStateE8[i].x / 10 - var0);
                group->baseY = gCurrentPinballGame->bossGroupBasePosition.y + 52;
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
    else
    {
        group = gMain.boardSpriteGroups[4];
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

        group = gMain.boardSpriteGroups[5];
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

        gMain.boardSpriteGroups[4]->available = 0;
        gMain.boardSpriteGroups[5]->available = 0;
        gCurrentPinballGame->bannerType = 0;
    }
}

void ResetHatchCaveAnimationState(void)
{
    gCurrentPinballGame->pondAnimState = 1;
    gCurrentPinballGame->pondAnimIndexPrev = 0;
    gCurrentPinballGame->pondAnimIndex = 0;
    gCurrentPinballGame->ballLockState0 = 0;
    gCurrentPinballGame->hatchCaveState = 0;
    gCurrentPinballGame->hatchCaveHitPending = 0;
}

void UpdateHatchCaveAnimation(void)
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
    switch (gCurrentPinballGame->pondAnimState)
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

    if (gCurrentPinballGame->pondAnimIndexPrev != gCurrentPinballGame->pondAnimIndex)
    {
        index = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][2];
        DmaCopy16(3, gRubyBoardHatchCave_Gfx[index], (void *)0x060122A0, 0x480);
        index = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][3];
        DmaCopy16(3, gUnknown_084FD18C[index], (void *)0x06011CE0, 0x200);
        gCurrentPinballGame->pondAnimIndexPrev = gCurrentPinballGame->pondAnimIndex;
    }

    if (gCurrentPinballGame->pondAnimState > 1)
    {
        if (gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][1] > gCurrentPinballGame->ballLockState0)
        {
            gCurrentPinballGame->ballLockState0++;
        }
        else
        {
            gCurrentPinballGame->pondAnimIndex++;
            gCurrentPinballGame->ballLockState0 = 0;
            if (gCurrentPinballGame->pondAnimIndex >= var0)
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

            if ((gCurrentPinballGame->pondAnimIndex == 8 || gCurrentPinballGame->pondAnimIndex == 27) && gCurrentPinballGame->ballLockState0 == 0)
                m4aMPlayAllStop();

            if (gCurrentPinballGame->pondAnimIndex == 12 && gCurrentPinballGame->ballLockState0 == 0)
                m4aSongNumStart(MUS_EGG_MODE_START);

            if (gCurrentPinballGame->pondAnimIndex == 29)
                RequestBoardTransition(5);

            if (gCurrentPinballGame->pondAnimIndex == 28)
                m4aSongNumStart(SE_UNKNOWN_0x92);
        }

        var3 = gUnknown_086AD2EE[gCurrentPinballGame->pondAnimIndex][0];
    }

    gCurrentPinballGame->hatchCaveSpriteBaseX = 88 - gCurrentPinballGame->bgScrollXCopy;
    gCurrentPinballGame->hatchCaveSpriteBaseY = 144 - gCurrentPinballGame->bgScrollYWithOffset;
    group->baseX = gCurrentPinballGame->hatchCaveSpriteBaseX + gCurrentPinballGame->ballLockState4;
    if (gCurrentPinballGame->pondAnimState > 0)
    {
        if (gCurrentPinballGame->pondAnimIndex == 32 && gCurrentPinballGame->ballLockState0 > 208)
        {
            s16 varZ = (0x100 - gCurrentPinballGame->ballLockState0) / 16 + 1;
            if (gMain.systemFrameCount & (varZ << 1))
                group->baseY = gCurrentPinballGame->hatchCaveSpriteBaseY + gCurrentPinballGame->ballLockState6;
            else
                group->baseY = 200;
        }
        else
        {
            group->baseY = gCurrentPinballGame->hatchCaveSpriteBaseY + gCurrentPinballGame->ballLockState6;
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
        src = gUnknown_086B4D4E[var3][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }

    group = &gMain.spriteGroups[52];
    group->baseX = gCurrentPinballGame->hatchCaveSpriteBaseX;
    group->baseY = gCurrentPinballGame->hatchCaveSpriteBaseY;
    for (i = 0; i < 4; i++)
    {
        oamSimple = &gMain.spriteGroups[52].oam[i];
        gOamBuffer[oamSimple->oamId].priority = priority;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateCyndaquilHatchCaveSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 priority;
    s16 var0;

    priority = 1;
    group = &gMain.spriteGroups[51];
    var0 = gMain.systemFrameCount % 36;
    gCurrentPinballGame->cyndaquilGfxFrame = 0;
    gCurrentPinballGame->hatchCaveCollisionReady = 1;
    if (gCurrentPinballGame->hatchCaveState < 3)
    {
        gCurrentPinballGame->cyndaquilGfxFrame = gUnknown_086AE0B4[var0 / 6];
        gCurrentPinballGame->cyndaquilSpriteX = gUnknown_086AE0A4[gCurrentPinballGame->hatchCaveState].x;
        gCurrentPinballGame->cyndaquilSpriteY = gUnknown_086AE0A4[gCurrentPinballGame->hatchCaveState].y;
        group->baseX = gCurrentPinballGame->cyndaquilSpriteX - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->cyndaquilSpriteY - gCurrentPinballGame->bgScrollYWithOffset;
        if (var0 % 6 == 0)
        {
            DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilGfxFrame], (void *)0x06013300, 0x280);
        }
    }
    else if (gCurrentPinballGame->hatchCaveState == 3)
    {
        if (gCurrentPinballGame->hatchCaveCompletionFlag != 2)
        {
            if (gCurrentPinballGame->pondAnimState == 1)
            {
                gCurrentPinballGame->pondAnimState = 2;
                gCurrentPinballGame->cyndaquilGfxFrame = 1;
                DmaCopy16(3, gRubyStageCyndaquil_Gfx[gCurrentPinballGame->cyndaquilGfxFrame], (void *)0x06013300, 0x280);
                gMain.modeChangeFlags |= MODE_CHANGE_BANNER;
                gCurrentPinballGame->scrollDelayFrames = 0;
                gCurrentPinballGame->scrollHoldFrames = 60;
                gCurrentPinballGame->scrollTargetBottomY = 72;
                gCurrentPinballGame->fieldScrollOffsetY = 0;
                gCurrentPinballGame->fieldScrollSpeed = 2;
                gCurrentPinballGame->bannerGfxVariant = 0;
                gCurrentPinballGame->scrollOverrideActive = 1;
                gCurrentPinballGame->scrollFromBottom = 0;
                gCurrentPinballGame->cyndaquilRiseTimer = 48;
            }

            if (gCurrentPinballGame->hatchCaveHitPending)
            {
                gCurrentPinballGame->hatchCaveHitPending = 0;
                gCurrentPinballGame->cyndaquilRiseTimer = 48;
            }
        }
        else
        {
            if (gCurrentPinballGame->cyndaquilRiseTimer == 0)
            {
                if (gCurrentPinballGame->cyndaquilRiseHoldTimer == 30)
                {
                    gCurrentPinballGame->ballLockState = 0;
                    gCurrentPinballGame->entryAnimTimer = 60;
                    gCurrentPinballGame->ball->velocity.x = 20;
                    gCurrentPinballGame->ball->velocity.y = 200;
                    gCurrentPinballGame->ball->positionQ0.x = 88;
                    gCurrentPinballGame->ball->positionQ0.y = 163;
                    gCurrentPinballGame->ball->spin = 0;
                    gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                    gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                    m4aSongNumStart(SE_UNKNOWN_0xB9);
                    gCurrentPinballGame->bossActive = 0;
                }

                if (gCurrentPinballGame->cyndaquilRiseHoldTimer)
                {
                    gCurrentPinballGame->cyndaquilRiseHoldTimer--;
                }
                else
                {
                    ResetHatchCaveAnimationState();
                    gCurrentPinballGame->hatchCaveState = 0;
                    gCurrentPinballGame->hatchCaveCompletionFlag = 0;
                }
            }
            else
            {
                gCurrentPinballGame->ball->positionQ0.x = 88;
                gCurrentPinballGame->ball->positionQ0.y = 163 - gCurrentPinballGame->cyndaquilRiseTimer / 3;
                gCurrentPinballGame->ball->spin = 0;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
                gCurrentPinballGame->bossActive = 1;
            }
        }

        gCurrentPinballGame->cyndaquilSpriteX = gUnknown_086AE0A4[gCurrentPinballGame->hatchCaveState].x;
        gCurrentPinballGame->cyndaquilSpriteY = gUnknown_086AE0A4[gCurrentPinballGame->hatchCaveState].y - gCurrentPinballGame->cyndaquilRiseTimer / 3;
        group->baseX = gCurrentPinballGame->cyndaquilSpriteX - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->cyndaquilSpriteY - gCurrentPinballGame->bgScrollYWithOffset;
        if (gCurrentPinballGame->boardState < 3)
        {
            if (gCurrentPinballGame->hatchCaveState == 3 && gCurrentPinballGame->hatchCaveCompletionFlag != 2)
                gCurrentPinballGame->catchModeBlinkActive = 1;
            else
                gCurrentPinballGame->catchModeBlinkActive = 0;
        }
        else
        {
            gCurrentPinballGame->catchModeBlinkActive = 0;
        }

        if (gCurrentPinballGame->cyndaquilRiseTimer)
        {
            gCurrentPinballGame->cyndaquilRiseTimer--;
            priority = 2;
        }
    }
    else
    {
        if (gCurrentPinballGame->pondAnimState == 3)
        {
            gCurrentPinballGame->catchModeBlinkActive = 0;
            gCurrentPinballGame->pondAnimState = 4;
            gCurrentPinballGame->pondAnimIndex = 8;
            gCurrentPinballGame->ballLockState0 = 0;
        }

        gCurrentPinballGame->cyndaquilSpriteX = 0;
        gCurrentPinballGame->cyndaquilSpriteY = 0;
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

void CleanupAfterCatchMode(void)
{
    s16 i;

    if (gMain.selectedField == FIELD_RUBY)
        gCurrentPinballGame->hatchCaveCompletionFlag = 1;
    else
        gCurrentPinballGame->cyndaquilCatchReady = 1;

    gCurrentPinballGame->catchModeHitCount = 0;
    SetBoardPortraitGraphics(0, 0);
    gCurrentPinballGame->hatchRevealState = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->activatedBumperCount)
            gCurrentPinballGame->bumperHitTimers[i] = 1;
        else
            gCurrentPinballGame->bumperHitTimers[i] = 0;
    }
}

void InitEggHatchMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->modeTimerFrames = 1800;
    gCurrentPinballGame->catchModeHitCount = 0;
    gCurrentPinballGame->ballLockState8 = 0;
    gCurrentPinballGame->ballLockStateA = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->ballLockStateC = 750;
        gCurrentPinballGame->bonusSpriteYQ10 = 1040;
    }
    else
    {
        gCurrentPinballGame->ballLockStateC = 1960;
        gCurrentPinballGame->bonusSpriteYQ10 = 300;
    }

    gCurrentPinballGame->bonusTargetIndex = 0;
    gCurrentPinballGame->nameRevealAnimFrame = 0;
    gCurrentPinballGame->ballLockState8 = 0;
    gCurrentPinballGame->ballLockStateA = 0;
    gCurrentPinballGame->catchHitInvulnTimer = 0;
    gCurrentPinballGame->catchHitReactionTimer = 0;
}

void UpdateEggHatchMode(void)
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

    group = gMain.boardSpriteGroups[41];
    priority = 1;
    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        gCurrentPinballGame->hatchRevealState = 3;
        gMain.boardSpriteGroups[41]->available = 1;
        gCurrentPinballGame->boardSubState++;
        break;
    case 1:
        if (gUnknown_086AD52C[gCurrentPinballGame->bonusTargetIndex][1] > gCurrentPinballGame->nameRevealAnimFrame)
        {
            gCurrentPinballGame->nameRevealAnimFrame++;
        }
        else
        {
            gCurrentPinballGame->bonusTargetIndex++;
            gCurrentPinballGame->nameRevealAnimFrame = 0;
            if (gMain.selectedField == FIELD_RUBY)
            {
                if (gCurrentPinballGame->bonusTargetIndex > 13)
                {
                    gCurrentPinballGame->bonusTargetIndex = 0;
                    gCurrentPinballGame->boardSubState = 3;
                    gCurrentPinballGame->ballLockState8 = 0;
                    gCurrentPinballGame->ballLockStateA = 0;
                }

                if (gCurrentPinballGame->bonusTargetIndex == 12)
                {
                    if (gCurrentPinballGame->nameRevealAnimFrame == 0)
                        m4aSongNumStart(MUS_EGG_MODE);
                }

                if (gCurrentPinballGame->bonusTargetIndex == 10)
                {
                    gCurrentPinballGame->bgmVolumeRestoreTimer = 140;
                    PlayCry_Normal(gSpeciesInfo[gCurrentPinballGame->currentSpecies].mainSeriesIndexNumber, 0);
                }

                if (gCurrentPinballGame->bonusTargetIndex == 12)
                {
                    gCurrentPinballGame->ballLockState8 = -8;
                    gCurrentPinballGame->ballLockStateA = -30;
                }
                else
                {
                    gCurrentPinballGame->ballLockState8 = 0;
                    gCurrentPinballGame->ballLockStateA = 0;
                }
            }
            else
            {
                if (gCurrentPinballGame->bonusTargetIndex > 9)
                {
                    gCurrentPinballGame->nameRevealAnimFrame = 0;
                    gCurrentPinballGame->bonusTargetIndex = 10;
                    gCurrentPinballGame->boardSubState = 2;
                    gCurrentPinballGame->ballLockState8 = 0;
                    gCurrentPinballGame->ballLockStateA = 0;
                }
            }
        }

        var0 = gUnknown_086AD52C[gCurrentPinballGame->bonusTargetIndex][0];
        var1 = gUnknown_086AD52C[gCurrentPinballGame->bonusTargetIndex][2];
        if (gCurrentPinballGame->bonusTargetIndex == 12)
        {
            gCurrentPinballGame->ballLockStateA += 2;
            gCurrentPinballGame->ballLockStateC += gCurrentPinballGame->ballLockState8;
            gCurrentPinballGame->bonusSpriteYQ10 += gCurrentPinballGame->ballLockStateA;
        }

        group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        DmaCopy16(3, gUnknown_020315D0, (void *)0x050003A0, 0x20);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B4B0E[var1][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
            gOamBuffer[oamSimple->oamId].priority = priority;
        }
        break;
    case 2:
        if (gCurrentPinballGame->nameRevealAnimFrame < 240)
        {
            priority = 1;
            if (gCurrentPinballGame->nameRevealAnimFrame == 0)
            {
                gCurrentPinballGame->cyndaquilAnimPhase = 3;
                m4aSongNumStart(SE_UNKNOWN_0xDD);
            }
            var0 = 0;
        }
        else if (gCurrentPinballGame->nameRevealAnimFrame == 240)
        {
            gCurrentPinballGame->ballLockStateC = 2260;
            gCurrentPinballGame->bonusSpriteYQ10 = 740;
            gCurrentPinballGame->bonusTargetIndex = 0;
            priority = 2;
            var0 = 0;
            m4aSongNumStart(MUS_EGG_MODE);
        }
        else
        {
            tempVec.x = gUnknown_086AD750[gCurrentPinballGame->bonusTargetIndex].x - 120 - gCurrentPinballGame->ballLockStateC;
            tempVec.y = gUnknown_086AD750[gCurrentPinballGame->bonusTargetIndex].y - 160 - gCurrentPinballGame->bonusSpriteYQ10;
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            angle = ArcTan2(tempVec.x,-tempVec.y);
            if (gCurrentPinballGame->nameRevealAnimFrame < 324)
                priority = 2;
            else
                priority = 1;

            if (gCurrentPinballGame->bonusTargetIndex < 4)
            {
                var0 = 0;
                tempVec2.x = (Cos(angle) * 14) / 20000;
                tempVec2.y = -(Sin(angle) * 14) / 20000;
            }
            else
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
                tempVec2.x = (Cos(angle) * 7) / 20000;
                tempVec2.y = -(Sin(angle) * 7) / 20000;
            }

            gCurrentPinballGame->ballLockStateC += tempVec2.x;
            gCurrentPinballGame->bonusSpriteYQ10 += tempVec2.y;
            if (squaredMagnitude < 2500)
            {
                if (gCurrentPinballGame->bonusTargetIndex < 6)
                {
                    gCurrentPinballGame->bonusTargetIndex++;
                }
                else
                {
                    gCurrentPinballGame->bonusTargetIndex = 3;
                    gCurrentPinballGame->boardSubState = 3;
                    gCurrentPinballGame->ballLockState8 = 0;
                    gCurrentPinballGame->ballLockStateA = 0;
                }
            }

            if (gCurrentPinballGame->nameRevealAnimFrame < 380)
            {
                gCurrentPinballGame->fieldScrollOffsetY++;
            }
            else if (gCurrentPinballGame->nameRevealAnimFrame >= 400)
            {
                if (gCurrentPinballGame->fieldScrollOffsetY > 0)
                    gCurrentPinballGame->fieldScrollOffsetY--;
            }
        }

        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        gCurrentPinballGame->nameRevealAnimFrame++;
        group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
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
        tempVec.x = gUnknown_086AD580[gMain.selectedField][gCurrentPinballGame->bonusTargetIndex].x - 120 - gCurrentPinballGame->ballLockStateC;
        tempVec.y = gUnknown_086AD580[gMain.selectedField][gCurrentPinballGame->bonusTargetIndex].y - 160 - gCurrentPinballGame->bonusSpriteYQ10;
        xx = tempVec.x * tempVec.x;
        yy = tempVec.y * tempVec.y;
        squaredMagnitude = xx + yy;
        angle = ArcTan2(tempVec.x, -tempVec.y);
        tempVec2.x = (Cos(angle) * 7) / 20000;
        tempVec2.y = -(Sin(angle) * 7) / 20000;
        if (gCurrentPinballGame->catchHitReactionTimer)
        {
            gCurrentPinballGame->catchHitReactionTimer--;
            var0 = 14;
        }
        else
        {
            if (gSpeciesInfo[gCurrentPinballGame->currentSpecies].hatchAnimSimple)
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 24) / 8;
            }
            else
            {
                var0 = gUnknown_086AD788[angle / 0x2000] + (gMain.systemFrameCount % 32) / 8 - ((gMain.systemFrameCount % 32) / 24) * 2;
            }

            gCurrentPinballGame->ballLockStateC += tempVec2.x;
            gCurrentPinballGame->bonusSpriteYQ10 += tempVec2.y;
        }

        if (squaredMagnitude < 2500)
        {
            if (gCurrentPinballGame->bonusTargetIndex < 28)
            {
                gCurrentPinballGame->bonusTargetIndex++;
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
            if (gCurrentPinballGame->bonusTargetIndex > 26)
                priority = 2;
            else
                priority = 1;
        }
        else if (gCurrentPinballGame->bonusTargetIndex > 27)
        {
            priority = 3;
            gCurrentPinballGame->catchModeForceOpen = 1;
        }
        else
        {
            priority = 1;
        }

        group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;;
        if (group->baseY > 180)
            group->baseY = 180;
        else if (group->baseY < -30)
            group->baseY = -30;

        DmaCopy16(3, gUnknown_0202C7A0[var0], (void *)0x060112A0, 0x120);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = priority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->catchHitInvulnTimer)
        {
            gCurrentPinballGame->catchHitInvulnTimer--;
        }
        else
        {
            tempVec.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->ballLockStateC / 10 + 12);
            tempVec.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->bonusSpriteYQ10 / 10 + 14);
            xx = tempVec.x * tempVec.x;
            yy = tempVec.y * tempVec.y;
            squaredMagnitude = xx + yy;
            if (squaredMagnitude < 82)
            {
                gCurrentPinballGame->catchModeHitCount++;
                gCurrentPinballGame->catchHitInvulnTimer = 4;
                gCurrentPinballGame->catchHitReactionTimer = 20;
                if (gCurrentPinballGame->catchModeHitCount > 1)
                    gCurrentPinballGame->boardSubState = 4;

                m4aSongNumStart(SE_UNKNOWN_0x75);
                angle2 = ArcTan2(-gCurrentPinballGame->ball->velocity.x, gCurrentPinballGame->ball->velocity.y);
                if (gCurrentPinballGame->catchModeHitCount > 1)
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
        gCurrentPinballGame->bannerType = 9;
        DmaCopy16(3, gUnknown_086ACF80, (void *)0x050003E0, 0x20);
        DmaCopy16(3, gUnknown_081428D4, (void *)0x06015800, 0x1C00);
        DmaCopy16(3, &gUnknown_08138014[gCurrentPinballGame->ballUpgradeType * 0x200], (void *)0x060164C0, 0x80);
        DmaCopy16(3, &gUnknown_08138014[(gCurrentPinballGame->ballUpgradeType * 8 + 4) * 0x40], (void *)0x06016760, 0x80);
        gCurrentPinballGame->entityCaptureTimer = 0;
        gCurrentPinballGame->catchModeHitPhase = 2;
        gCurrentPinballGame->entityCenterX = gCurrentPinballGame->ballLockStateC / 10 + 8;
        gCurrentPinballGame->entityCenterY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - 31;
        for (i = 0; i < 6; i++)
            gCurrentPinballGame->pondEntityPaletteIds[i] = 13;

        gCurrentPinballGame->boardSubState++;
        group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY > 180)
            group->baseY = 180;

        DmaCopy16(3, gUnknown_0202D760, (void *)0x060112A0, 0x120);
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
        if (gCurrentPinballGame->captureSequencePhase < 17)
            priority = 2;
        else
            priority = 0;

        if (group->available)
        {
            group->baseX = gCurrentPinballGame->ballLockStateC / 10 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gCurrentPinballGame->bonusSpriteYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].priority = priority;
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            DmaCopy16(3, gUnknown_0202D760, (void *)0x060112A0, 0x120);
            if (gCurrentPinballGame->captureSequencePhase == 23)
                gMain.boardSpriteGroups[41]->available = 0;
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
        gMain.boardSpriteGroups[41]->available = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        CleanupAfterCatchMode();
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->catchModeForceOpen = 0;
        break;
    case 8:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->bumperHitTimers[2] == 1)
                RequestBoardTransition(3);
            else
                RequestBoardTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

void HideHatchRevealSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = gMain.boardSpriteGroups[18];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.boardSpriteGroups[18]->available = 0;
    group = gMain.boardSpriteGroups[12];
    if (group->available)
    {
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = 200;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }
    gMain.boardSpriteGroups[12]->available = 0;
    gCurrentPinballGame->bannerType = 0;
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
    gMain.boardSpriteGroups[18]->available = 1;
    if (gCurrentPinballGame->hatchFrameId > 0)
        AnimateHatchTileExplodeParticles();

    if (gCurrentPinballGame->hatchSequentialTilesRevealed < gCurrentPinballGame->hatchTilesBoardAcknowledged)
    {
        if (gCurrentPinballGame->hatchFrameId == 0 && gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer == 0)
        {
            gCurrentPinballGame->bannerType = 11;
            DmaCopy16(3, gUnknown_083A05CC, (void *)0x050003C0, 0x20);
            DmaCopy16(3, gUnknown_0839DDAC, (void *)0x06015800, 0x2800);
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
                gCurrentPinballGame->remainingHatchTileCount--;
                if (gCurrentPinballGame->hatchSequentialTilesRevealed == gCurrentPinballGame->hatchTilesBoardAcknowledged)
                {
                    if (gCurrentPinballGame->remainingHatchTileCount >= 0)
                        gCurrentPinballGame->bannerType = 0;
                }

                if (gCurrentPinballGame->remainingHatchTileCount < 0)
                {
                    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                    for (i = 0; i < 6; i++)
                        gCurrentPinballGame->hatchTileShuffleOrder[i] = i;

                    var0 = gMain.systemFrameCount % 6;
                    gCurrentPinballGame->remainingHatchTileCount = 5;
                    gCurrentPinballGame->boardSubState++;
                    gMain.boardSpriteGroups[18]->available = 0;
                }
                else if (gCurrentPinballGame->remainingHatchTileCount == 0)
                {
                    var0 = 0;
                }
                else
                {
                    var0 = gMain.systemFrameCount % gCurrentPinballGame->remainingHatchTileCount;
                }

                gCurrentPinballGame->selectedHatchTileIndex = gCurrentPinballGame->hatchTileShuffleOrder[var0];
                for (i = var0; i < gCurrentPinballGame->remainingHatchTileCount; i++)
                    gCurrentPinballGame->hatchTileShuffleOrder[i] = gCurrentPinballGame->hatchTileShuffleOrder[i + 1];
            }
            else
            {
                if (gCurrentPinballGame->hatchFrameId == 1)
                    gCurrentPinballGame->pondEntityPaletteIds[gCurrentPinballGame->selectedHatchTileIndex] = 13;
            }
        }
    }
    else
    {
        var1 = 0;
    }

    if (gCurrentPinballGame->hatchFrameId == 1)
    {
        m4aSongNumStart(SE_UNKNOWN_0x8C);
        InitHatchTileExplodeParticles();
    }

    if (gCurrentPinballGame->hatchFrameId == 12)
        var1 = 0;

    group = gMain.boardSpriteGroups[18];
    if (var1)
    {
        group->baseX = (gCurrentPinballGame->selectedHatchTileIndex % 3) * 16 - (gCurrentPinballGame->bgScrollXCopy - 96);
        group->baseY = (gCurrentPinballGame->selectedHatchTileIndex / 3) * 16 - (gCurrentPinballGame->bgScrollYWithOffset - 300);
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

    switch (gCurrentPinballGame->hatchTileAnimPhase)
    {
    case 0:
        if (gCurrentPinballGame->hatchTileAnimTimer < 60)
        {
            gCurrentPinballGame->hatchTileAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchTileAnimPhase++;
            gCurrentPinballGame->hatchTileAnimTimer = 0;
        }
        gMain.blendControl = 0xCE;
        break;
    case 1:
        gCurrentPinballGame->bannerType = 5;
        DmaCopy16(3, gUnknown_083A07CC, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gUnknown_083A27EC, (void *)0x050003C0, 0x20);
        gMain.boardSpriteGroups[35]->available = 1;
        m4aSongNumStart(SE_UNKNOWN_0x8D);
        gCurrentPinballGame->hatchTileAnimPhase++;
        gCurrentPinballGame->hatchTileAnimTimer = 0;
        gCurrentPinballGame->hatchRevealKeyframe = 0;
        break;
    case 2:
        if (gUnknown_086AE0C0[gCurrentPinballGame->hatchRevealKeyframe] > gCurrentPinballGame->hatchTileAnimTimer)
        {
            gCurrentPinballGame->hatchTileAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchTileAnimTimer = 0;
            gCurrentPinballGame->hatchRevealKeyframe++;
            if (gCurrentPinballGame->hatchRevealKeyframe > 7)
            {
                gCurrentPinballGame->hatchRevealKeyframe = 7;
                gCurrentPinballGame->hatchTileAnimPhase++;
                gMain.boardSpriteGroups[35]->available = 0;
            }
        }

        var0 = gCurrentPinballGame->hatchRevealKeyframe;
        group = gMain.boardSpriteGroups[35];
        group->baseX = 124 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 244 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 0];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 1];
            *dst++ = gUnknown_086B50AE[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 3:
        gCurrentPinballGame->bannerType = 6;
        DmaCopy16(3, gUnknown_083A29EC, (void *)0x06015800, 0x800);
        DmaCopy16(3, gUnknown_083A320C, (void *)0x050003C0, 0x20);
        gMain.boardSpriteGroups[36]->available = 1;
        gCurrentPinballGame->hatchTileAnimPhase++;
        gCurrentPinballGame->hatchTileAnimTimer = 0;
        gCurrentPinballGame->pauseInputLocked = 1;
        break;
    case 4:
        var0 = gCurrentPinballGame->hatchTileAnimTimer / 2;
        if (gCurrentPinballGame->hatchTileAnimTimer < 15)
        {
            gCurrentPinballGame->hatchTileAnimTimer++;
        }
        else
        {
            gMain.boardSpriteGroups[36]->available = 0;
            gCurrentPinballGame->hatchTileAnimPhase++;
            gCurrentPinballGame->hatchTileAnimTimer = 0;
            gCurrentPinballGame->hatchRevealKeyframe = 0;
        }

        group = gMain.boardSpriteGroups[36];
        group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 300 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 0];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 1];
            *dst++ = gUnknown_086B4F6A[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    case 5:
        gCurrentPinballGame->bannerType = 7;
        DmaCopy16(3, gUnknown_083A340C, (void *)0x06015800, 0x2000);
        DmaCopy16(3, gUnknown_083A542C, (void *)0x050003C0, 0x20);
        gCurrentPinballGame->hatchTileAnimPhase++;
        InitHatchTileRevealAllParticles();
        m4aSongNumStart(SE_UNKNOWN_0x8E);
        break;
    case 6:
        gMain.blendBrightness = 0;
        gMain.blendControl = ((REG_DISPCNT & (DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON)) >> 8) | 0xA0;
        if (gCurrentPinballGame->hatchTileAnimTimer < 73)
        {
            s16 var1;
            if (gCurrentPinballGame->hatchTileAnimTimer < 8)
            {
                gMain.blendBrightness = 16;
            }
            else
            {
                for (i = 0; i < 6; i++)
                    gCurrentPinballGame->pondEntityPaletteIds[i] = 13;

                gMain.blendBrightness = ((8 - gCurrentPinballGame->hatchTileAnimTimer) / 4) + 16;
            }
        }

        if (gCurrentPinballGame->hatchTileAnimTimer < 72)
        {
            gCurrentPinballGame->hatchTileAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchTileAnimPhase++;
            gCurrentPinballGame->hatchTileAnimTimer = 0;
            gCurrentPinballGame->hatchRevealKeyframe = 0;
        }

        if (gCurrentPinballGame->hatchTileAnimTimer > 8U)
        {
            if (gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer < 0x7000)
                AnimateHatchTileRevealAllParticles();
        }
        break;
    case 7:
        gCurrentPinballGame->bannerType = 8;
        DmaCopy16(3, gUnknown_083A562C, (void *)0x06015800, 0x1800);
        DmaCopy16(3, gUnknown_083A6E4C, (void *)0x050003C0, 0x20);
        gMain.boardSpriteGroups[37]->available = 1;
        gCurrentPinballGame->hatchTileAnimPhase++;
        gCurrentPinballGame->pauseInputLocked = 0;
        break;
    case 8:
        if (gUnknown_086AE0D0[gCurrentPinballGame->hatchRevealKeyframe] > gCurrentPinballGame->hatchTileAnimTimer)
        {
            gCurrentPinballGame->hatchTileAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->hatchTileAnimTimer = 0;
            gCurrentPinballGame->hatchRevealKeyframe++;
            if (gCurrentPinballGame->hatchRevealKeyframe > 10)
            {
                gCurrentPinballGame->boardSubState++;
                gMain.boardSpriteGroups[37]->available = 0;
                gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
                gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
                gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
                gMain.blendControl = 0xCE;
                gMain.blendBrightness = 0;
                gMain.boardSpriteGroups[37]->available = 0;
                gCurrentPinballGame->hatchRevealKeyframe = 10;
                gCurrentPinballGame->bannerType = 0;
            }
        }

        var0 = gCurrentPinballGame->hatchRevealKeyframe;
        group = gMain.boardSpriteGroups[37];
        group->baseX = 96 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 300 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 0];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 1];
            *dst++ = gUnknown_086B4E62[var0][i * 3 + 2];

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
        break;
    }
}

void InitAreaRouletteMode(void)
{
    s16 i;

    gCurrentPinballGame->boardSubState = 1;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->spriteLayerPriority = 3;
    gCurrentPinballGame->areaRotationCount = 0;
    gCurrentPinballGame->areaRotationIndex = (Random() + gMain.systemFrameCount) % 6;
    gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->areaRotationIndex];
    gCurrentPinballGame->portraitAreaLookupIds[1] = gUnknown_08137928[gCurrentPinballGame->area];
    gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][(gCurrentPinballGame->areaRotationIndex + 1) % 6];
    gCurrentPinballGame->portraitAreaLookupIds[0] = gUnknown_08137928[gCurrentPinballGame->area];
    SetBoardPortraitGraphics(0, 0);
    SetBoardPortraitGraphics(0, 1);
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->pondEntityPaletteIds[i] = 13;

    DmaCopy16(3, gUnknown_083A8AAC, (void *)0x050003C0, 0x20);
    DmaCopy16(3, gUnknown_084FA20C, (void *)0x06015800, 0x280);
    gCurrentPinballGame->bannerType = 12;
}

void UpdateAreaRouletteMode(void)
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
        gCurrentPinballGame->slotReelVisualFrame = 0;
        gCurrentPinballGame->scrollNudgeTargetY = 0;
        gCurrentPinballGame->scrollNudgeActive = 1;
        gMain.boardSpriteGroups[20]->available = 1;
        gMain.boardSpriteGroups[21]->available = 1;
        gMain.boardSpriteGroups[23]->available = 1;
        gMain.boardSpriteGroups[22]->available = 1;
        gMain.boardSpriteGroups[19]->available = 1;
        gCurrentPinballGame->slotReelSpinPosition = 30;
        gCurrentPinballGame->slotReelFramesPerCycle = 30;
        gCurrentPinballGame->slotReelDecelerationTimer = 0;
        if (gMain.selectedField == FIELD_RUBY)
        {
            gCurrentPinballGame->pondBumperAnimState[0] = 10;
            gCurrentPinballGame->pondBumperAnimState[1] = 10;
            gCurrentPinballGame->pondBumperAnimState[2] = 10;
        }
        else
        {
            gCurrentPinballGame->pondBumperAnimState[0] = 0;
            gCurrentPinballGame->pondBumperAnimState[1] = 0;
            gCurrentPinballGame->pondBumperAnimState[2] = 0;
        }
        gCurrentPinballGame->rubyPondChangeTimer = 0;
        break;
    case 2:
        if (gCurrentPinballGame->scrollNudgeY == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }

        if (gMain.selectedField == FIELD_RUBY)
        {
            if (gCurrentPinballGame->rubyPondChangeTimer < 143)
                gCurrentPinballGame->pondBumperAnimState[0] = gUnknown_08137944[gCurrentPinballGame->rubyPondChangeTimer / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 18 && gCurrentPinballGame->rubyPondChangeTimer < 161)
                gCurrentPinballGame->pondBumperAnimState[2] = gUnknown_08137944[(gCurrentPinballGame->rubyPondChangeTimer - 18) / 8];

            if (gCurrentPinballGame->rubyPondChangeTimer >= 36 && gCurrentPinballGame->rubyPondChangeTimer < 179)
                gCurrentPinballGame->pondBumperAnimState[1] = gUnknown_08137944[(gCurrentPinballGame->rubyPondChangeTimer - 36) / 8];

            gCurrentPinballGame->rubyPondChangeTimer++;
        }

        gCurrentPinballGame->slotReelVisualFrame = (gCurrentPinballGame->slotReelSpinPosition * 32) / gCurrentPinballGame->slotReelFramesPerCycle;
        gCurrentPinballGame->hatchRevealState = 1;
        gCurrentPinballGame->stageTimer++;
        UpdateRouletteBoardIndicatorPulse();
        break;
    case 3:
        if (gCurrentPinballGame->stageTimer < 15)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 15)
            {
                gCurrentPinballGame->boardSubState++;
                gCurrentPinballGame->slotReelFramesPerCycle = 6;
                gCurrentPinballGame->slotReelDecelerationTimer = 0;
            }
        }
        SetRouletteIndicatorState(0);
        /* fallthrough */
    case 4:
    case 5:
        if (gCurrentPinballGame->boardSubState == 3)
        {
            gCurrentPinballGame->slotReelSpinPosition--;
            gCurrentPinballGame->slotReelSpinPosition %= gCurrentPinballGame->slotReelFramesPerCycle;
        }
        else if (gCurrentPinballGame->boardSubState == 4)
        {
            gCurrentPinballGame->slotReelSpinPosition++;
            if (gCurrentPinballGame->newButtonActions[1] && gCurrentPinballGame->boardSubState == 4)
            {
                if (gCurrentPinballGame->slotReelDecelerationTimer == 0)
                {
                    if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                        gCurrentPinballGame->slotReelDecelerationTimer = 48;
                    else
                        gCurrentPinballGame->slotReelDecelerationTimer = 1;

                    gCurrentPinballGame->slotReelDecelerationTotal = gCurrentPinballGame->slotReelDecelerationTimer;
                    gCurrentPinballGame->peliAnimState = 1;
                    gCurrentPinballGame->tiltButtonHeld = 1;
                    gCurrentPinballGame->modeTimerFrames = 3600;
                    gCurrentPinballGame->rubyPondState = RUBY_POND_STATE_CHINCHOU_COUNTERCLOCKWISE;
                }
            }

            if (gCurrentPinballGame->slotReelDecelerationTimer)
            {
                gCurrentPinballGame->slotReelDecelerationTimer--;
                if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
                {
                    gCurrentPinballGame->numCompletedBonusStages = 4;
                    if (gCurrentPinballGame->slotReelDecelerationTimer < 24)
                    {
                        gCurrentPinballGame->slotReelDecelerationTimer = 24;
                        if (gCurrentPinballGame->areaRotationIndex == 6)
                            gCurrentPinballGame->slotReelDecelerationTimer = 0;
                    }
                }

                if (gCurrentPinballGame->slotReelDecelerationTimer == 0)
                {
                    gCurrentPinballGame->boardSubState = 5;
                }
                else
                {
                    if (gCurrentPinballGame->slotReelSpinPosition == gCurrentPinballGame->slotReelFramesPerCycle)
                    {
                        gCurrentPinballGame->slotReelFramesPerCycle = 40 - (gCurrentPinballGame->slotReelDecelerationTimer * 30) / gCurrentPinballGame->slotReelDecelerationTotal;
                        gCurrentPinballGame->slotReelSpinPosition = 0;
                    }
                }
            }

            gCurrentPinballGame->slotReelSpinPosition %= gCurrentPinballGame->slotReelFramesPerCycle;
        }
        else
        {
            gCurrentPinballGame->slotReelSpinPosition++;
            gCurrentPinballGame->slotReelSpinPosition %= gCurrentPinballGame->slotReelFramesPerCycle;
            if (gCurrentPinballGame->slotReelSpinPosition == 0)
            {
                gCurrentPinballGame->stageTimer = 0;
                gCurrentPinballGame->boardSubState++;
                gMain.boardSpriteGroups[23]->available = 0;
                gMain.boardSpriteGroups[20]->available = 0;
                gMain.boardSpriteGroups[21]->available = 0;
                gMain.boardSpriteGroups[34]->available = 1;
                m4aSongNumStart(SE_UNKNOWN_0x93);
            }
        }

        gCurrentPinballGame->slotReelVisualFrame = (gCurrentPinballGame->slotReelSpinPosition * 32) / gCurrentPinballGame->slotReelFramesPerCycle;
        if (gCurrentPinballGame->slotReelSpinPosition == 0)
        {
            gCurrentPinballGame->portraitAreaLookupIds[0] = gCurrentPinballGame->portraitAreaLookupIds[1];
            SetBoardPortraitGraphics(0, 0);
        }

        if (gCurrentPinballGame->slotReelSpinPosition == 1)
        {
            if (gMain.eReaderBonuses[EREADER_RUIN_AREA_CARD])
            {
                gCurrentPinballGame->areaRotationIndex = (gCurrentPinballGame->areaRotationIndex + 1) % 7;
                gCurrentPinballGame->nextAreaIndex = 0;
                gCurrentPinballGame->nextNextAreaIndex = 1;
            }
            else
            {
                gCurrentPinballGame->areaRotationIndex = (gCurrentPinballGame->areaRotationIndex + 1) % 6;
                gCurrentPinballGame->nextAreaIndex = (gCurrentPinballGame->areaRotationIndex + 1) % 6;
                gCurrentPinballGame->nextNextAreaIndex = (gCurrentPinballGame->areaRotationIndex + 2) % 6;
            }

            gCurrentPinballGame->area = gUnknown_08055A68[gMain.selectedField][gCurrentPinballGame->areaRotationIndex];
            gCurrentPinballGame->portraitAreaLookupIds[1] = gUnknown_08137928[gCurrentPinballGame->area];
            SetBoardPortraitGraphics(0, 1);
            m4aSongNumStart(SE_UNKNOWN_0x81);
        }
        break;
    case 6:
        if (gCurrentPinballGame->stageTimer < 50)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 50)
            {
                gCurrentPinballGame->boardSubState = 0;
                RequestBoardTransition(1);
            }
        }

        if (gCurrentPinballGame->stageTimer < 29)
        {
            if (gCurrentPinballGame->stageTimer < 8)
                var0 = gCurrentPinballGame->stageTimer / 4;
            else
                var0 = ((gCurrentPinballGame->stageTimer - 8) / 3) + 2;

            group = gMain.boardSpriteGroups[34];
            if (group->available)
            {
                group->baseX = 96u - gCurrentPinballGame->bgScrollXCopy;
                group->baseY = gCurrentPinballGame->slotReelVisualFrame + 300u - gCurrentPinballGame->bgScrollYWithOffset;
                if (group->baseY >= 200)
                    group->baseY = 200;

                for (i = 0; i < 9; i++)
                {
                    oamSimple = &group->oam[i];
                    dst = (u16 *)&gOamBuffer[oamSimple->oamId];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 0];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 1];
                    *dst++ = gUnknown_086B51CE[var0][i * 3 + 2];

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                }
            }

            if (gCurrentPinballGame->stageTimer == 0x1C) {
                gMain.boardSpriteGroups[34]->available = 0;
                gCurrentPinballGame->bannerType = 0;
            }
        }

        gCurrentPinballGame->hatchRevealState = 0;
        break;
    }
}

void UpdateRouletteBoardIndicatorPulse(void)
{
    s16 index;

    index = (gMain.systemFrameCount % 100) / 10;
    gCurrentPinballGame->renderAnimCounter = 0;
    gCurrentPinballGame->savedCatchArrows = gUnknown_08137AB8[index];
    gCurrentPinballGame->savedEvoHitCount = gUnknown_08137AB8[index];
    gCurrentPinballGame->scoreMultiplierLevel = gUnknown_08137AB8[index];
    if (index == 7 || index == 9)
    {
        gCurrentPinballGame->catchModeBlinkActive = 1;
        gCurrentPinballGame->trapDisplayBlinkActive = 1;
        gCurrentPinballGame->hatchModeBlinkActive = 1;
    }
    else
    {
        gCurrentPinballGame->catchModeBlinkActive = 0;
        gCurrentPinballGame->trapDisplayBlinkActive = 0;
        gCurrentPinballGame->hatchModeBlinkActive = 0;
    }
}

void SetRouletteIndicatorState(s16 arg0)
{
    if (arg0)
    {
        gCurrentPinballGame->trapDisplayBlinkActive = 1;
        gCurrentPinballGame->catchModeBlinkActive = 1;
        gCurrentPinballGame->catchArrowIndicatorBlink = 1;
        gCurrentPinballGame->savedEvoHitCount = 3;
        gCurrentPinballGame->scoreMultiplierLevel = 3;
        gCurrentPinballGame->savedCatchArrows = 3;
        gCurrentPinballGame->hatchModeBlinkActive = 1;
    }
    else
    {
        gCurrentPinballGame->hatchModeBlinkActive = 0;
        gCurrentPinballGame->trapDisplayBlinkActive = 0;
        gCurrentPinballGame->catchModeBlinkActive = 0;
        gCurrentPinballGame->savedEvoHitCount = 0;
        gCurrentPinballGame->scoreMultiplierLevel = 0;
        gCurrentPinballGame->savedCatchArrows = 2;
    }

    gCurrentPinballGame->bonusMultiplier = 1;
}

void ResetTravelModeState(void)
{
    gCurrentPinballGame->travelModeProgress = 0;
    gCurrentPinballGame->rubyPondStage = 0;
    if (gMain.selectedField == FIELD_RUBY)
    {
        gCurrentPinballGame->rubyPondCurrentStage = 0;
        gCurrentPinballGame->rubyPondAnimFrame = 0;
        gCurrentPinballGame->rubyPondSubframeTimer = 0;
    }

    gCurrentPinballGame->pondStageTransitionActive = 1;
    gCurrentPinballGame->pondTransitionFrame = 0;
    SetBoardPortraitGraphics(0, 0);
    gCurrentPinballGame->hatchRevealState = 0;
    gMain.boardSpriteGroups[13]->available = 0;
    gCurrentPinballGame->ballSpriteVariant = 0;
    gCurrentPinballGame->centerHoleAttractionActive = 0;
    gCurrentPinballGame->prevCatchArrowGfxState[0] = gCurrentPinballGame->catchArrowGfxState[0] = 0;
    gCurrentPinballGame->prevCatchArrowGfxState[1] = gCurrentPinballGame->catchArrowGfxState[1] = 0;
    gCurrentPinballGame->prevCatchArrowGfxState[2] = gCurrentPinballGame->catchArrowGfxState[2] = 0;
    ClearEventIndicatorDisplay();
}

void InitTravelMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->entityActivePhase = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 3600;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->modeTimerFrames = 1800;
    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
}

void UpdateTravelMode(void)
{
    s16 var0;

    if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 6)
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
            gCurrentPinballGame->portraitAnimCounter = 0;
        }
        gCurrentPinballGame->travelModeProgress = 0;
        break;
    case 1:
        SetBoardPortraitGraphics(4, 0);
        if (gCurrentPinballGame->stageTimer == 35)
            m4aSongNumStart(MUS_TRAVEL_MODE);

        if (gCurrentPinballGame->travelModeProgress)
        {
            gCurrentPinballGame->boardSubState++;
            if (gCurrentPinballGame->stageTimer < 35)
                m4aSongNumStart(MUS_TRAVEL_MODE);

            gCurrentPinballGame->rubyPondStage = 0;
            gCurrentPinballGame->pondStageTransitionActive = 1;
            gCurrentPinballGame->pondTransitionFrame = 0;
        }

        var0 = (gCurrentPinballGame->stageTimer % 40) / 10;
        gCurrentPinballGame->stageTimer++;
        if (var0 == 0)
        {
            gCurrentPinballGame->catchArrowGfxState[0] = 0;
            gCurrentPinballGame->catchArrowGfxState[1] = 0;
            gCurrentPinballGame->catchArrowGfxState[2] = 0;
        }
        else if (var0 == 1)
        {
            gCurrentPinballGame->catchArrowGfxState[0] = 3;
            gCurrentPinballGame->catchArrowGfxState[1] = 1;
            gCurrentPinballGame->catchArrowGfxState[2] = 0;
        }
        else if (var0 == 2)
        {
            gCurrentPinballGame->catchArrowGfxState[0] = 3;
            gCurrentPinballGame->catchArrowGfxState[1] = 3;
            gCurrentPinballGame->catchArrowGfxState[2] = 2;
        }
        else
        {
            gCurrentPinballGame->catchArrowGfxState[0] = 3;
            gCurrentPinballGame->catchArrowGfxState[1] = 3;
            gCurrentPinballGame->catchArrowGfxState[2] = 3;
        }

        gCurrentPinballGame->prevCatchArrowGfxState[0] = gCurrentPinballGame->catchArrowGfxState[0];
        gCurrentPinballGame->prevCatchArrowGfxState[1] = gCurrentPinballGame->catchArrowGfxState[1];
        gCurrentPinballGame->prevCatchArrowGfxState[2] = gCurrentPinballGame->catchArrowGfxState[2];
        break;
    case 2:
        EnableBonusTrapSprite();
        gCurrentPinballGame->ballSpriteVariant = 2;
        SetBoardPortraitGraphics(0, 0);
        gCurrentPinballGame->prevCatchArrowGfxState[0] = gCurrentPinballGame->catchArrowGfxState[0] = 0;
        gCurrentPinballGame->prevCatchArrowGfxState[1] = gCurrentPinballGame->catchArrowGfxState[1] = 0;
        gCurrentPinballGame->prevCatchArrowGfxState[2] = gCurrentPinballGame->catchArrowGfxState[2] = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 3:
        UpdateBonusTrapSprite();
        if (gCurrentPinballGame->boardEntryMode == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 4:
        gCurrentPinballGame->entityActivePhase = 3;
        gCurrentPinballGame->boardSubState++;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->portraitAnimCounter = 0;
        gCurrentPinballGame->slotReelResultPair[0] = 47;
        SetBoardPortraitGraphics(7, 0);
        break;
    case 5:
        if (gCurrentPinballGame->sequenceTimer == 145)
        {
            gCurrentPinballGame->sequenceTimer++;
            gCurrentPinballGame->slotReelResultPair[0] = 47;
            SetBoardPortraitGraphics(7, 0);
            if (JOY_NEW(A_BUTTON))
            {
                gCurrentPinballGame->sequenceTimer = 144;
                m4aMPlayAllStop();
                SetBoardPortraitGraphics(0, 0);
                if (gCurrentPinballGame->areaRotationCount < 5)
                {
                    var0 = gCurrentPinballGame->nextNextAreaIndex;
                    if (gCurrentPinballGame->travelModeProgress == 1)
                        gCurrentPinballGame->areaRotationIndex = gCurrentPinballGame->nextAreaIndex;
                    else
                        gCurrentPinballGame->areaRotationIndex = gCurrentPinballGame->nextNextAreaIndex;

                    gCurrentPinballGame->nextAreaIndex = (var0 + 1) % 6;
                    gCurrentPinballGame->nextNextAreaIndex = (var0 + 2) % 6;
                    gCurrentPinballGame->areaRotationCount++;
                }
                else
                {
                    gCurrentPinballGame->areaRotationIndex = 6;
                    gCurrentPinballGame->areaRotationCount = 0;
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                m4aMPlayAllStop();
                m4aSongNumStart(SE_MENU_CANCEL);
                gCurrentPinballGame->sequenceTimer = 60;
                gCurrentPinballGame->boardSubState = 6;
                if (gCurrentPinballGame->allHolesCompleted)
                    gCurrentPinballGame->allHolesCompleteCooldown = 120;
            }
        }

        if (gCurrentPinballGame->sequenceTimer == 130)
        {
            gCurrentPinballGame->sequenceTimer++;
            if (gCurrentPinballGame->stageTimer < 490)
            {
                RunSapphirePelliperFlybyAnimation();
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
                gCurrentPinballGame->sequenceTimer = 120;
            }

            gCurrentPinballGame->stageTimer++;
        }
        else if (gCurrentPinballGame->sequenceTimer == 0)
        {
            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
            if (gCurrentPinballGame->evolutionCompletionCount < 99)
                gCurrentPinballGame->evolutionCompletionCount++;
        }
        break;
    case 6:
        UpdateBonusTrapSprite();
        gMain.boardSpriteGroups[13]->available = 0;
        ResetTravelModeState();
        gCurrentPinballGame->boardSubState++;
        break;
    case 7:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            RequestBoardTransition(1);
            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

void CleanupAfterEvolutionMode(void)
{
    s16 i;

    SetBoardPortraitGraphics(0, 0);
    gCurrentPinballGame->hatchRevealState = 0;
    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->activatedBumperCount)
            gCurrentPinballGame->bumperHitTimers[i] = 1;
        else
            gCurrentPinballGame->bumperHitTimers[i] = 0;
    }

    gMain.boardSpriteGroups[13]->available = 0;
    gCurrentPinballGame->ballSpriteVariant = 0;
    gCurrentPinballGame->centerHoleAttractionActive = 0;
    ClearEventIndicatorDisplay();
}

void InitEvolutionMode(void)
{
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->entityActivePhase = 2;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 7200;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->modeTimerFrames = 3600;
    if (gCurrentPinballGame->currentSpecies == SPECIES_WURMPLE)
    {
        gCurrentPinballGame->evoItemType = 0;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_GLOOM)
    {
        if (gMain.selectedField == FIELD_RUBY)
            gCurrentPinballGame->evoItemType = 1;
        else
            gCurrentPinballGame->evoItemType = 7;
    }
    else if (gCurrentPinballGame->currentSpecies == SPECIES_CLAMPERL)
    {
        gCurrentPinballGame->evoItemType = 3;
    }
    else
    {
        gCurrentPinballGame->evoItemType = gSpeciesInfo[gCurrentPinballGame->currentSpecies].evolutionMethod - 1;
        if (gCurrentPinballGame->evoItemType < 0)
            gCurrentPinballGame->evoItemType = 0;
    }

    DmaCopy16(3, gUnknown_081C0064, (void *)0x05000180, 0x20);
    gCurrentPinballGame->savedEvoHitCount = 0;
    gCurrentPinballGame->trapDisplayBlinkActive = 0;
    gCurrentPinballGame->menuDismissTimer = 0;
    gCurrentPinballGame->evoItemTargetIndex = 0;
    gCurrentPinballGame->evoItemHitCount = 0;
    gCurrentPinballGame->evoItemResetFlag = 0;
    gCurrentPinballGame->evoItemAppearTimer = 0;
    SetBoardPortraitGraphics(3, 0);
}

void UpdateEvolutionMode(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gCurrentPinballGame->boardSubState < 8)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL2);
        gCurrentPinballGame->stageTimer = 200;
        gCurrentPinballGame->boardSubState = 8;
    }

    switch (gCurrentPinballGame->boardSubState)
    {
    case 0:
        if (gCurrentPinballGame->evoItemRound < 2)
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = i;

            index = (Random() + gMain.systemFrameCount) % 5;
            gCurrentPinballGame->evoItemShuffledSlots[0] = gCurrentPinballGame->evoItemCandidatePool[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = gCurrentPinballGame->evoItemCandidatePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 4;
            gCurrentPinballGame->evoItemShuffledSlots[1] = gCurrentPinballGame->evoItemCandidatePool[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = gCurrentPinballGame->evoItemCandidatePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 3;
            gCurrentPinballGame->evoItemShuffledSlots[2] = gCurrentPinballGame->evoItemCandidatePool[index];
        }
        else
        {
            for (i = 0; i < 8; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = i;

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->evoItemShuffledSlots[0] = gCurrentPinballGame->evoItemCandidatePool[index];
            for (i = index; i < 7; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = gCurrentPinballGame->evoItemCandidatePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 7;
            gCurrentPinballGame->evoItemShuffledSlots[1] = gCurrentPinballGame->evoItemCandidatePool[index];
            for (i = index; i < 6; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = gCurrentPinballGame->evoItemCandidatePool[i + 1];

            index = (Random() + gMain.systemFrameCount) % 6;
            gCurrentPinballGame->evoItemShuffledSlots[2] = gCurrentPinballGame->evoItemCandidatePool[index];
            for (i = index; i < 5; i++)
                gCurrentPinballGame->evoItemCandidatePool[i] = gCurrentPinballGame->evoItemCandidatePool[i + 1];

            if (gMain.selectedField == FIELD_SAPPHIRE && gCurrentPinballGame->numCompletedBonusStages < 5)
            {
                for (i = 0; i < 3; i++)
                {
                    if (gCurrentPinballGame->evoItemShuffledSlots[i] == 5)
                    {
                        index = (Random() + gMain.systemFrameCount) % 5;
                        gCurrentPinballGame->evoItemShuffledSlots[i] = gCurrentPinballGame->evoItemCandidatePool[index];
                    }
                }
            }
        }

        gCurrentPinballGame->evoItemRound++;
        gCurrentPinballGame->boardSubState++;
        break;
    case 1:
        gCurrentPinballGame->evoItemTargetIndex = gCurrentPinballGame->evoItemShuffledSlots[gCurrentPinballGame->evoItemHitCount];
        gCurrentPinballGame->evoItemPosX = gUnknown_086ACFA0[gMain.selectedField][gCurrentPinballGame->evoItemTargetIndex].x;
        gCurrentPinballGame->evoItemPosY = gUnknown_086ACFA0[gMain.selectedField][gCurrentPinballGame->evoItemTargetIndex].y;
        gCurrentPinballGame->evoItemAppearTimer = 80;
        gMain.boardSpriteGroups[40]->available = 1;
        gCurrentPinballGame->boardSubState++;
        break;
    case 2:
        UpdateEvolutionItemSprite();
        gCurrentPinballGame->stageTimer = 0;
        break;
    case 3:
        gCurrentPinballGame->ballSpriteVariant = 1;
        if (gCurrentPinballGame->stageTimer < 8)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            EnableBonusTrapSprite();
            gCurrentPinballGame->ballSpriteVariant = 2;
            gCurrentPinballGame->boardSubState++;
        }
        break;
    case 4:
        UpdateBonusTrapSprite();
        if (gCurrentPinballGame->boardEntryMode == 4)
            gCurrentPinballGame->boardSubState++;
        break;
    case 5:
        gCurrentPinballGame->entityActivePhase = 3;
        gCurrentPinballGame->lastEvolvedSpecies = gCurrentPinballGame->currentSpecies;
        RegisterCapturedOrEvolvedPokemon(1);
        gCurrentPinballGame->savedHatchSpecies = gCurrentPinballGame->currentSpecies;
        gCurrentPinballGame->stageTimer = 0;
        gCurrentPinballGame->boardSubState++;
        break;
    case 6:
        if (gCurrentPinballGame->sequenceTimer == 148)
        {
            gCurrentPinballGame->sequenceTimer++;
            if (gMain.spriteGroups[13].available)
            {
                if (gCurrentPinballGame->coinBounceTimer >= 80)
                {
                    RunEvolutionCutsceneAnimation();
                    if (gCurrentPinballGame->boardSubState == 6)
                        gCurrentPinballGame->stageTimer++;
                }
            }
            else
            {
                RunEvolutionCutsceneAnimation();
                if (gCurrentPinballGame->boardSubState == 6)
                    gCurrentPinballGame->stageTimer++;
            }
        }
        break;
    case 7:
        if (gCurrentPinballGame->sequenceTimer == 148)
        {
            gCurrentPinballGame->sequenceTimer++;
            if (gCurrentPinballGame->stageTimer < 280)
            {
                if (gCurrentPinballGame->stageTimer == 0)
                {
                    InitEvolutionNameRevealBanner();
                    m4aSongNumStart(MUS_SUCCESS2);
                }
                else
                {
                    UpdateEvolutionNameRevealBanner();
                    if (gCurrentPinballGame->stageTimer < 230)
                    {
                        if (gCurrentPinballGame->nameRevealScrollProgress == 150)
                            gCurrentPinballGame->nameRevealScrollProgress--;
                    }

                    if (gCurrentPinballGame->stageTimer == 270)
                    {
                        SetBoardPortraitGraphics(0, 0);
                        gCurrentPinballGame->hatchRevealState = 0;
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
                    gMain.blendScanlineEnabled = 1;
                    var0 = gCurrentPinballGame->stageTimer;
                    gCurrentPinballGame->blendScanlineWidth = gCurrentPinballGame->stageTimer;
                    for (i = 0; i <= var0; i++)
                    {
                        for (j = 2; j < 12; j++)
                            gBgScreenBuffer[((j + 15) * 0x20) + i] = 0xC100;
                    }

                    DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
                }

                if (gCurrentPinballGame->stageTimer >= 240 && gCurrentPinballGame->stageTimer < 270)
                {
                    var0 = gCurrentPinballGame->stageTimer - 240;
                    for (i = 0; i <= var0; i ++)
                    {
                        for (j = 2; j < 12; j++)
                            gBgScreenBuffer[((j + 15) << 5) + i] = 0x1FF;
                    }

                    DmaCopy16(3, gBgScreenBuffer, (void *)0x06002000, 0x800);
                    if (gCurrentPinballGame->stageTimer == 269)
                    {
                        gMain.blendScanlineEnabled = 0;
                        gMain.blendControl = 0;
                        gMain.blendBrightness = 0;
                        gMain.blendAlpha = 0;
                    }
                }

                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->sequenceTimer = 40;
            }
        }
        else if (gCurrentPinballGame->sequenceTimer == 24)
        {
            if (gCurrentPinballGame->activatedBumperCount < 3)
            {
                gCurrentPinballGame->bumperFlashTargetA = gCurrentPinballGame->activatedBumperCount;
                gCurrentPinballGame->bumperFlashTargetB = gCurrentPinballGame->activatedBumperCount;
                gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetA] = 1;
                gCurrentPinballGame->bumperFlashAnimTimer = 120;
                gCurrentPinballGame->activatedBumperCount++;
                if (gCurrentPinballGame->activatedBumperCount < 3)
                {
                    gCurrentPinballGame->bumperFlashTargetB = gCurrentPinballGame->activatedBumperCount;
                    gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->bumperFlashTargetB] = 1;
                    gCurrentPinballGame->bumperFlashAnimTimer = 120;
                    gCurrentPinballGame->activatedBumperCount++;
                }
            }

            if (gCurrentPinballGame->currentSpecies == SPECIES_NINJASK)
            {
                gCurrentPinballGame->caughtMonCount++;
                if (gCurrentPinballGame->catchCompletionCount < 99)
                    gCurrentPinballGame->catchCompletionCount++;

                if (gCurrentPinballGame->caughtMonCount == 15)
                    gCurrentPinballGame->extraLifeAnimTimer = 92;
            }

            gCurrentPinballGame->caughtMonCount++;
            if (gCurrentPinballGame->caughtMonCount == 15)
                gCurrentPinballGame->extraLifeAnimTimer = 92;

            if (gCurrentPinballGame->catchCompletionCount < 99)
                gCurrentPinballGame->catchCompletionCount++;

            gCurrentPinballGame->boardSubState++;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 8:
        group = gMain.boardSpriteGroups[32];
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset - 56;

        gMain.boardSpriteGroups[32]->available = 0;
        UpdateEvolutionItemSprite();
        gMain.boardSpriteGroups[40]->available = 0;
        gCurrentPinballGame->bannerType = 0;
        UpdateBonusTrapSprite();
        gMain.boardSpriteGroups[13]->available = 0;
        gCurrentPinballGame->trapDoorAnimActive = 1;
        gCurrentPinballGame->slotReelFrame = 0;
        gCurrentPinballGame->trapDisplayState = 0;
        gCurrentPinballGame->boardSubState++;
        if (gCurrentPinballGame->allHolesCompleted)
            gCurrentPinballGame->allHolesCompleteCooldown = 120;
        break;
    case 9:
        CleanupAfterEvolutionMode();
        gCurrentPinballGame->boardSubState++;
        break;
    case 10:
        if (gCurrentPinballGame->stageTimer)
        {
            gCurrentPinballGame->stageTimer--;
        }
        else
        {
            if (gCurrentPinballGame->bumperHitTimers[2] == 1)
                RequestBoardTransition(3);
            else
                RequestBoardTransition(1);

            gCurrentPinballGame->boardSubState = 0;
        }
        break;
    }
}

void UpdateEvolutionItemSprite(void)
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
    group = gMain.boardSpriteGroups[32];
    if (gCurrentPinballGame->evoItemAppearTimer)
    {
        group = gMain.boardSpriteGroups[40];
        if (gCurrentPinballGame->evoItemAppearTimer == 80)
        {
            gCurrentPinballGame->bannerType = 15;
            DmaCopy16(3, gEvoItemAppear_GfxList[gCurrentPinballGame->evoItemType], (void *)0x06015800, 0x1C00);
            DmaCopy16(3, &gUnknown_0815C4C4[gCurrentPinballGame->evoItemType], (void *)0x050003E0, 0x20);
            gCurrentPinballGame->evoItemAnimKeyframe = 0;
            gCurrentPinballGame->evoItemAnimSubFrame = 0;
        }

        if (gCurrentPinballGame->evoItemAppearTimer == 60)
            MPlayStart(&gMPlayInfo_SE1, &se_unk_84);

        if (gUnknown_086AE0E6[gCurrentPinballGame->evoItemAnimKeyframe] > gCurrentPinballGame->evoItemAnimSubFrame)
        {
            gCurrentPinballGame->evoItemAnimSubFrame++;
        }
        else
        {
            gCurrentPinballGame->evoItemAnimSubFrame = 1;
            gCurrentPinballGame->evoItemAnimKeyframe++;
            if (gCurrentPinballGame->evoItemAnimKeyframe == 29)
            {
                gCurrentPinballGame->evoItemAnimKeyframe = 28;
                gCurrentPinballGame->evoItemAppearTimer = 1;
                gMain.boardSpriteGroups[40]->available = 0;
                gMain.boardSpriteGroups[32]->available = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_85);
                gCurrentPinballGame->bannerType = 0;
            }
        }

        group->baseX = gCurrentPinballGame->evoItemPosX - gCurrentPinballGame->bgScrollXCopy + 8;
        group->baseY = gCurrentPinballGame->evoItemPosY - gCurrentPinballGame->bgScrollYWithOffset + 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        for (i = 0; i < 5; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16 *)&gOamBuffer[oamSimple->oamId];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->evoItemAnimKeyframe][i * 3 + 0];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->evoItemAnimKeyframe][i * 3 + 1];
            *dst++ = gUnknown_086B4202[gCurrentPinballGame->evoItemAnimKeyframe][i * 3 + 2];

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
            ((gCurrentPinballGame->collisionMapIndex == 0 && gCurrentPinballGame->evoItemTargetIndex <= 5) || (gCurrentPinballGame->collisionMapIndex == 2 && gCurrentPinballGame->evoItemTargetIndex > 5)) &&
            gCurrentPinballGame->evoItemHitCount < 3)
        {
            gCurrentPinballGame->scoreAddedInFrame = 10000;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_86);
            gCurrentPinballGame->boardSubState = 1;
            gCurrentPinballGame->bumperHitTimers[gCurrentPinballGame->evoItemHitCount] = 5;
            gCurrentPinballGame->evoItemHitCount++;
            gMain.boardSpriteGroups[32]->available = 0;
            if (gCurrentPinballGame->evoItemHitCount == 3)
            {
                gCurrentPinballGame->evoItemHitCount = 0;
                gCurrentPinballGame->boardSubState = 3;
            }
        }

        group->baseX = gCurrentPinballGame->evoItemPosX - gCurrentPinballGame->bgScrollXCopy - 8;
        group->baseY = gCurrentPinballGame->evoItemPosY - gCurrentPinballGame->bgScrollYWithOffset - 8;
        if (group->baseY < -30)
            group->baseY = -30;
        if (group->baseY > 200)
            group->baseY = 200;

        if (index > 14)
            index = 14;

        DmaCopy16(3, gUnknown_086AD49C[gCurrentPinballGame->evoItemType] + index * 0x200, (void *)0x060116C0, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void CleanupAfterCatchHatchMode(void)
{
    s16 i;

    gCurrentPinballGame->catchModeHitCount = 0;
    gCurrentPinballGame->catchHitReactionTimer = 0;
    gMain.boardSpriteGroups[18]->available = 0;
    gMain.boardSpriteGroups[12]->available = 0;
    gCurrentPinballGame->catchCollisionActive = 0;
    SetBoardPortraitGraphics(0, 0);
    gCurrentPinballGame->hatchRevealState = 0;
    ClearEventIndicatorDisplay();
    for (i = 0; i < 6; i++)
        gCurrentPinballGame->pondEntityPaletteIds[i] = 13;

    for (i = 0; i < 3; i++)
    {
        if (i < gCurrentPinballGame->activatedBumperCount)
            gCurrentPinballGame->bumperHitTimers[i] = 1;
        else
            gCurrentPinballGame->bumperHitTimers[i] = 0;
    }
}

void InitCatchMode(void)
{
    s16 i, j;

    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->entityActivePhase = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_CATCH_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->catchModeHitCount = 0;
    gCurrentPinballGame->catchHitInvulnTimer = 0;
    gCurrentPinballGame->catchHitReactionTimer = 0;
    gCurrentPinballGame->hatchTilesBoardAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTilesRevealed = 0;
    gCurrentPinballGame->hatchTilesBumperAcknowledged = 0;
    gCurrentPinballGame->hatchSequentialTileRevealFrameAnimTimer = 0;
    gCurrentPinballGame->hatchFrameId = 0;
    gCurrentPinballGame->savedCatchArrows = 0;
    gCurrentPinballGame->catchArrowIndicatorBlink = 0;

    if (gCurrentPinballGame->catchModeAttemptCount == 0)
    {
        gCurrentPinballGame->modeTimerFrames = 6000;
    }
    else
    {
        gCurrentPinballGame->modeTimerFrames = 4200;
    }
    gCurrentPinballGame->catchModeAttemptCount++;

    DmaCopy16(3, gUnknown_081C0064, (void *)PLTT + 0x180, 0x20);

    for (i = 0; i < 6; i++)
    {
        gCurrentPinballGame->hatchTileShuffleOrder[i] = i;
    }

    gCurrentPinballGame->selectedHatchTileIndex = gMain.systemFrameCount % 6;
    gCurrentPinballGame->remainingHatchTileCount = 5;

    for (j = gCurrentPinballGame->selectedHatchTileIndex; j < gCurrentPinballGame->remainingHatchTileCount; j++)
    {
        gCurrentPinballGame->hatchTileShuffleOrder[j] = gCurrentPinballGame->hatchTileShuffleOrder[j+1];
    }
}
