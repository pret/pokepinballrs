#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gUnknown_08137D48[];
extern const u8 gRayquazaBonusClear_Gfx[];
extern const u8 gUnknown_083C5A2C[];
extern const u8 gUnknown_084A6EEC[][0x280];
extern const u8 gUnknown_084A856C[];
extern const u8 gUnknown_084AA18C[];
extern const u8 gUnknown_084AA9EC[][0x800];
extern const s16 gUnknown_086AEF28[];
extern const u16 gUnknown_086AF3CC[][3];
extern const struct Vector16 gUnknown_086AF744[32];
extern const s16 gUnknown_086AF784[];
extern const u16 gUnknown_086B5ECA[39][6][3];
extern const u16 gUnknown_086B5CC0[10][5][3];
extern const u16 gUnknown_086B5D56[20][2][3];
extern const u16 gUnknown_086B5DCE[12][7][3];
extern const u16 gUnknown_086B609E[10][3][3];
extern const u16 gUnknown_086B612E[212][3];

void RayquazaBoardProcess_3A_3E79C(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 10;
    for (i = 0; i < frame; i++)
        Random();

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->entityActivePhase = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->bonusCaptureState = 3;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->fieldScrollOffsetY = -88;
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    gCurrentPinballGame->hatchRevealState = 3;
    gCurrentPinballGame->bossBgPaletteIndex = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->bossHitPaletteState = 0;
    gCurrentPinballGame->rayquazaSegmentVelocity = 0;
    gCurrentPinballGame->rayquazaSegmentAltitude = 0;
    gCurrentPinballGame->bossFieldScrollQ10 = 0;
    gCurrentPinballGame->bossCryCountdown = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionLogicPosition[i].x = 0;
        gCurrentPinballGame->minionLogicPosition[i].y = 0;
    }

    gCurrentPinballGame->entityState = 0;
    gCurrentPinballGame->entityReturnState = 0;
    gCurrentPinballGame->entityDirection = 0;
    gCurrentPinballGame->entitySpriteFrame = 0;
    gCurrentPinballGame->entityWalkCycleCount = 0;
    gCurrentPinballGame->entityAnimIndex = 0;
    gCurrentPinballGame->entitySubPhase = 0;
    gCurrentPinballGame->entityAnimTimer = 0;
    gCurrentPinballGame->entityAppearDissolveTimer = 0;
    gCurrentPinballGame->entityPosXQ10 = 0;
    gCurrentPinballGame->entityPosYQ10 = 0;
    gCurrentPinballGame->entityTargetPosX = 0;
    gCurrentPinballGame->entityTargetPosY = 0;
    gCurrentPinballGame->entityCollisionOriginX = 0;
    gCurrentPinballGame->entityCollisionOriginY = 0;
    gCurrentPinballGame->scopeVelocity.x = 0;
    gCurrentPinballGame->scopeVelocity.y = 0;
    gCurrentPinballGame->scopePositionQ10.x = 0;
    gCurrentPinballGame->scopePositionQ10.y = 0;
    gCurrentPinballGame->bossHitReactionTimer = 0;

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->bossSegmentState[i] = 0;
        gCurrentPinballGame->segmentMoveTargetIndex[i] = 0;
        gCurrentPinballGame->segmentAnimTimers[i] = 0;
        gCurrentPinballGame->legendarySegmentPos[i].x = 0;
        gCurrentPinballGame->legendarySegmentPos[i].y = 0;
        gCurrentPinballGame->segmentTargetPos[i].x = 0;
        gCurrentPinballGame->segmentTargetPos[i].y = 0;
    }

    gCurrentPinballGame->bossImpactShakeTimer = 0;
    gCurrentPinballGame->bossFlipperEscapeTimer = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;
    gCurrentPinballGame->bossGrabDurationTimer = 0;
    gCurrentPinballGame->rayquazaWindCycleCount = 0;
    gCurrentPinballGame->rayquazaGrabbedSegmentId = 0;
    gCurrentPinballGame->rayquazaCloudPhase = 0;
    gCurrentPinballGame->rayquazaAttackState = 0;
    gCurrentPinballGame->rayquazaDiveFlashTimer = 0;
    gCurrentPinballGame->rayquazaBrightnessFade = 0;
    gCurrentPinballGame->rayquazaHitCooldown = 0;
    gCurrentPinballGame->rayquazaDefeatAnimFrame = 0;
    gCurrentPinballGame->bossPhaseFrame = 0;
    gCurrentPinballGame->rayquazaSwayAngle = 0;
    gCurrentPinballGame->rayquazaWindAnimSubFrame = 0;
    gCurrentPinballGame->rayquazaPhaseTimer = 0;
    gCurrentPinballGame->rayquazaBgScrollSpeed = 0;
    gCurrentPinballGame->rayquazaScreenY = 0;
    gCurrentPinballGame->rayquazaDiveTargetPos.x = 0;
    gCurrentPinballGame->rayquazaDiveTargetPos.y = 0;
    gCurrentPinballGame->segmentGrabRenderPos.x = 0;
    gCurrentPinballGame->segmentGrabRenderPos.y = 0;
    gCurrentPinballGame->rayquazaWindOffset.x = 0;
    gCurrentPinballGame->rayquazaWindOffset.y = 0;
    gCurrentPinballGame->minionPositionQ10.x = 0;
    gCurrentPinballGame->minionPositionQ10.y = 0;
    gCurrentPinballGame->fieldEntryInProgress = 1;
    UpdateRayquazaIntroOutroSequence();
    DmaCopy16(3, gUnknown_083C5A2C, (void *)0x06015800, 0x2800);
    DmaCopy16(3, gUnknown_084AA18C, (void *)0x06011620, 0x860);
    UpdateRayquazaStateMachine();
    RenderRayquazaSprite();
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void RayquazaBoardProcess_3B_3EB2C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballLocked = 1;
        if (gCurrentPinballGame->rayquazaCloudPhase == 1)
        {
            gCurrentPinballGame->fieldScrollOffsetY = 0;
            gCurrentPinballGame->boardState = 1;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 1:
        break;
    case 2:
        gCurrentPinballGame->boardState = 3;
        gCurrentPinballGame->stageTimer = 0;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->bonusScrollOffsetY = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gCurrentPinballGame->bossActive = 1;
        break;
    case 3:
        ProceessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 99999999;
        }

        if (gCurrentPinballGame->stageTimer < 240)
        {
            if (gCurrentPinballGame->stageTimer == 20)
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_SUCCESS3);
            }

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = 6;
            gCurrentPinballGame->numCompletedBonusStages++;
        }

        gCurrentPinballGame->bossActive = 1;
        break;
    case 4:
        gCurrentPinballGame->boardState = 5;
        gCurrentPinballGame->stageTimer = 140;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->bonusScrollOffsetY = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        break;
    case 5:
        ProceessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 99999999;
        }

        if (gCurrentPinballGame->stageTimer < 240)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = 6;
            gCurrentPinballGame->numCompletedBonusStages++;
            gCurrentPinballGame->bonusStagePurchased = 0;
        }
        break;
    case 6:
        ProceessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->bossActive = 1;
        break;
    }

    UpdateRayquazaIntroOutroSequence();
    RenderRayquazaAttackSprites();
    UpdateRayquazaStateMachine();
    RenderRayquazaSprite();
    if (gCurrentPinballGame->entityActivePhase && gCurrentPinballGame->eventTimer < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->bossActive = 1;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void UpdateRayquazaStateMachine(void)
{
    if (gCurrentPinballGame->bossHitReactionTimer)
    {
        gCurrentPinballGame->bossHitReactionTimer--;
        gCurrentPinballGame->bossHitPaletteState = 1;
        if (gCurrentPinballGame->bossHitReactionTimer == 5)
        {
            m4aSongNumStart(SE_RAYQUAZA_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 1000000;
            gCurrentPinballGame->bonusModeHitCount++;
            PlayRumble(7);
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired && gCurrentPinballGame->entityState != 6)
                gCurrentPinballGame->entityState = 9;
        }

        gCurrentPinballGame->rayquazaHitCooldown = 20;
        if (gCurrentPinballGame->bossHitReactionTimer == 0)
            gCurrentPinballGame->bossHitPaletteState = 0;
    }

    if (gCurrentPinballGame->rayquazaHitCooldown)
    {
        gCurrentPinballGame->rayquazaHitCooldown--;
        gCurrentPinballGame->boardEntityCollisionMode = 0;
    }
    else
    {
        gCurrentPinballGame->boardEntityCollisionMode = 1;
    }

    switch (gCurrentPinballGame->entityState)
    {
    case 0:
        gCurrentPinballGame->entityPosXQ10 = 1140;
        gCurrentPinballGame->entityPosYQ10 = 2400;
        gCurrentPinballGame->entityState = 1;
        gCurrentPinballGame->entityAnimIndex = 13;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entitySubPhase = 0;
        gCurrentPinballGame->rayquazaScreenY = 0;
        break;
    case 1:
        if (gCurrentPinballGame->rayquazaPhaseTimer > 530)
        {
            if (gCurrentPinballGame->entityPosYQ10 > -1200)
                gCurrentPinballGame->entityPosYQ10 -= 70;

            if (gCurrentPinballGame->rayquazaPhaseTimer == 672)
            {
                gCurrentPinballGame->entityState = 2;
                gCurrentPinballGame->entityPosXQ10 = 0;
                gCurrentPinballGame->entityPosYQ10 = -640;
            }
        }

        if (gCurrentPinballGame->rayquazaPhaseTimer == 530)
            gCurrentPinballGame->bossCryCountdown = 25;
        break;
    case 2:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 63)
                gCurrentPinballGame->entityAnimIndex = 13;
        }

        if (gCurrentPinballGame->entityPosYQ10 < 0)
        {
            gCurrentPinballGame->entityPosYQ10 += 18;
            if (gCurrentPinballGame->entityPosYQ10 > 0)
            {
                gCurrentPinballGame->entityPosYQ10 = 0;
                m4aSongNumStart(MUS_BONUS_FIELD_RAYQUAZA);
            }
        }

        if (gCurrentPinballGame->entityPosYQ10 == 0)
        {
            gCurrentPinballGame->entityState = 5;
            gCurrentPinballGame->entitySubPhase = 0;
            gCurrentPinballGame->entityReturnState = 6;
        }
        break;
    case 3:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 63)
                gCurrentPinballGame->entityAnimIndex = 13;
        }

        if (gCurrentPinballGame->entityPosYQ10 < 0)
        {
            gCurrentPinballGame->entityPosYQ10 += 18;
            if (gCurrentPinballGame->entityPosYQ10 > 0)
                gCurrentPinballGame->entityPosYQ10 = 0;
        }

        if (gCurrentPinballGame->entityPosYQ10 == 0)
        {
            gCurrentPinballGame->entityState = 5;
            gCurrentPinballGame->entitySubPhase = 0;
            gCurrentPinballGame->entityReturnState = 6;
        }
        break;
    case 4:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 34)
                gCurrentPinballGame->entityAnimIndex = 33;
        }

        if (gCurrentPinballGame->entityAnimIndex == 33 && gCurrentPinballGame->entityPosYQ10 > -0x300)
        {
            gCurrentPinballGame->entityPosYQ10 -= 0x18;
            if (gCurrentPinballGame->entityPosYQ10 < -0x300)
                gCurrentPinballGame->entityPosYQ10 = -0x300;
        }

        if (gCurrentPinballGame->entityPosYQ10 == -0x300)
        {
            gCurrentPinballGame->entityAnimIndex = 0;
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityState = 7;
            gCurrentPinballGame->entitySubPhase = 0;
        }
        break;
    case 5:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 63)
            {
                if (gCurrentPinballGame->entitySubPhase < 6)
                {
                    gCurrentPinballGame->entityAnimIndex = 13;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else if (gCurrentPinballGame->entityReturnState == 6)
                {
                    if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired - 1)
                    {
                        gCurrentPinballGame->entityAnimIndex = 13;
                        gCurrentPinballGame->entityState = 4;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimIndex = 98;
                        gCurrentPinballGame->entityState = 6;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 13;
                    gCurrentPinballGame->entityState = 4;
                    gCurrentPinballGame->entitySubPhase = 0;
                }
            }
        }

        if (gCurrentPinballGame->entitySubPhase > 1)
        {
            gCurrentPinballGame->rayquazaSwayAngle += 0x80;
            gCurrentPinballGame->entityPosXQ10 = ((Sin(gCurrentPinballGame->rayquazaSwayAngle) * 62) / 20000) * 10;
        }
        break;
    case 6:
        gCurrentPinballGame->bossHitPaletteState = 2;
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 116 && gCurrentPinballGame->entitySubPhase < 15)
            {
                gCurrentPinballGame->entitySubPhase++;
                gCurrentPinballGame->entityAnimIndex = 114;
            }

            if (gCurrentPinballGame->entityAnimIndex == 131)
            {
                gCurrentPinballGame->entityAnimIndex = 29;
                gCurrentPinballGame->entitySubPhase = 0;
                gCurrentPinballGame->entityState = 5;
                gCurrentPinballGame->entityReturnState = 4;
                gCurrentPinballGame->bossHitPaletteState = 0;
            }

            if (gCurrentPinballGame->entityAnimIndex == 114)
            {
                if (gCurrentPinballGame->entitySubPhase == 0)
                {
                    gMain.spriteGroups[17].available = 1;
                    gMain.spriteGroups[18].available = 1;
                    gMain.spriteGroups[19].available = 1;
                    gCurrentPinballGame->rayquazaAttackState = 1;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 120)
                gCurrentPinballGame->bossCryCountdown = 21;

            if (gCurrentPinballGame->entityAnimIndex == 124)
                gCurrentPinballGame->rayquazaBrightnessFade = 16;
        }
        break;
    case 7:
        if (gCurrentPinballGame->entityAnimTimer < 120)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityState = 8;
            DmaCopy16(3, gUnknown_084A856C, (void *)0x06015800, 0x1C00);
            if (gCurrentPinballGame->rayquazaWindCycleCount & 1)
            {
                gMain.spriteGroups[22].available = 1;
                gMain.spriteGroups[24].available = 1;
                gMain.spriteGroups[25].available = 1;
            }
            else
            {
                gMain.spriteGroups[23].available = 1;
                gMain.spriteGroups[30].available = 1;
                gMain.spriteGroups[31].available = 1;
            }

            gCurrentPinballGame->rayquazaWindCycleCount++;
            gCurrentPinballGame->rayquazaWindOffset.x = 0;
            gCurrentPinballGame->rayquazaWindOffset.y = 0;
            gCurrentPinballGame->minionPositionQ10.x = 0;
            gCurrentPinballGame->minionPositionQ10.y = 0;
            gCurrentPinballGame->rayquazaWindAnimSubFrame = 0;
            gCurrentPinballGame->entityAnimTimer = 0;
            m4aSongNumStart(SE_RAYQUAZA_WIND);
        }
        break;
    case 8:
        if (gMain.spriteGroups[22].available)
        {
            if (gCurrentPinballGame->rayquazaWindOffset.x < 4800)
                gCurrentPinballGame->rayquazaWindOffset.x += 140;
            else
                gMain.spriteGroups[22].available = 0;

            if (gCurrentPinballGame->rayquazaWindOffset.x > 2400)
            {
                if (gCurrentPinballGame->minionPositionQ10.x < 4960)
                    gCurrentPinballGame->minionPositionQ10.x += 200;

                gCurrentPinballGame->rayquazaWindAnimSubFrame++;
            }
        }
        else
        {
            if (gCurrentPinballGame->rayquazaWindOffset.x > -4800)
                gCurrentPinballGame->rayquazaWindOffset.x -= 140;
            else
                gMain.spriteGroups[23].available = 0;

            if (gCurrentPinballGame->rayquazaWindOffset.x < -2400)
            {
                if (gCurrentPinballGame->minionPositionQ10.x > -4960)
                    gCurrentPinballGame->minionPositionQ10.x -= 200;

                gCurrentPinballGame->rayquazaWindAnimSubFrame++;
            }
        }

        if (gCurrentPinballGame->entityAnimTimer == 20)
            gCurrentPinballGame->bossImpactShakeTimer = 60;

        gCurrentPinballGame->entityAnimTimer++;
        if (gCurrentPinballGame->entityAnimTimer >= 200)
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex = 13;
            gCurrentPinballGame->entityState = 3;
        }
        break;
    case 9:
        gCurrentPinballGame->entityActivePhase = 3;
        if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        {
            // Catch Rayquaza
            gCurrentPinballGame->entityState = 14;
            gCurrentPinballGame->entityAnimIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_RAYQUAZA;
            gCurrentPinballGame->bossFieldScrollQ10 = 0;
            gCurrentPinballGame->captureSequencePhase = 0;
            gCurrentPinballGame->entityCaptureTimer = 0;
            gCurrentPinballGame->catchModeHitPhase = 2;
        }
        else
        {
            // Normal Completion
            gCurrentPinballGame->entityState = 10;
            gCurrentPinballGame->entityAnimIndex = 98;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->bonusCaptureState = 2;
            gCurrentPinballGame->bonusSequenceTimer = 0;
        }

        gCurrentPinballGame->entityAnimTimer = 0;
        if (gMain.spriteGroups[36].available)
            gCurrentPinballGame->bossGrabDurationTimer = 1;
        break;
    case 10:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 131)
            {
                gCurrentPinballGame->entityAnimIndex = 13;
                gCurrentPinballGame->entitySubPhase = 0;
                gCurrentPinballGame->entityState = 11;
                gCurrentPinballGame->bossHitPaletteState = 0;
            }

            if (gCurrentPinballGame->entityAnimIndex == 120)
                gCurrentPinballGame->bossCryCountdown = 21;
        }
        break;
    case 11:
        if (gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 34)
                gCurrentPinballGame->entityAnimIndex = 33;
        }
            if (gCurrentPinballGame->entityAnimIndex == 33)
            {
                if (gCurrentPinballGame->entityPosYQ10 > -0x300)
                {
                    gCurrentPinballGame->entityPosYQ10 -= 0x18;
                    if (gCurrentPinballGame->entityPosYQ10 < -0x300)
                        gCurrentPinballGame->entityPosYQ10 = -0x300;
                }
            }

            if (gCurrentPinballGame->entityPosYQ10 == -0x300)
            {
                gCurrentPinballGame->entityAnimIndex = 0;
                gCurrentPinballGame->entityAnimTimer = 0;
                gCurrentPinballGame->entityState = 12;
                gCurrentPinballGame->entitySubPhase = 0;
            }

        break;
    case 12:
        DmaCopy16(3, gUnknown_084AA18C, (void *)0x06011620, 0x860);
        gCurrentPinballGame->entityState = 13;
        gCurrentPinballGame->entityPosXQ10 = 1140;
        gCurrentPinballGame->entityPosYQ10 = -1200;
        gCurrentPinballGame->rayquazaCloudPhase = 2;
        gCurrentPinballGame->rayquazaPhaseTimer = 0;
        gCurrentPinballGame->bossActive = 1;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gMain.spriteGroups[14].available = 1;
        gCurrentPinballGame->minionLogicPosition[0].x = 0;
        gCurrentPinballGame->minionLogicPosition[0].y = -5000;
        gCurrentPinballGame->minionLogicPosition[1].x = 1400;
        gCurrentPinballGame->minionLogicPosition[1].y = -2000;
        gCurrentPinballGame->scopePositionQ10.x = -200;
        gCurrentPinballGame->scopePositionQ10.y = 800;
        gCurrentPinballGame->scopeVelocity.x = 24;
        gCurrentPinballGame->scopeVelocity.y = -16;
        break;
    case 13:
        if (gCurrentPinballGame->rayquazaPhaseTimer < 256)
        {
            if (gCurrentPinballGame->entityAnimTimer < 80)
                gCurrentPinballGame->entityAnimTimer++;
            else if (gCurrentPinballGame->entityPosYQ10 < 2400)
                gCurrentPinballGame->entityPosYQ10 += 80;
        }
        else
        {
            gCurrentPinballGame->boardState = 2;
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->entityState = 15;
        }
        break;
    case 14:
        gCurrentPinballGame->rayquazaSegmentAltitude = 1;
        if (gCurrentPinballGame->bossFieldScrollQ10 > -500)
        {
            gCurrentPinballGame->bossFieldScrollQ10 += (-500 - gCurrentPinballGame->bossFieldScrollQ10) / 30;
            gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->bossFieldScrollQ10 / 10;
            if (gCurrentPinballGame->fieldScrollOffsetY < -38)
                gCurrentPinballGame->fieldScrollOffsetY = -38;
        }
        break;
    case 15:
        break;
    }

    if (gCurrentPinballGame->bossCryCountdown)
    {
        gCurrentPinballGame->bossCryCountdown--;
        if (gCurrentPinballGame->bossCryCountdown == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_RAYQUAZA].mainSeriesIndexNumber, 0);

        if (gCurrentPinballGame->bossCryCountdown == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderRayquazaSprite(void)
{
    s16 i;
    s16 sp0;
    s16 varSL;
    s32 temp;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    s16 var1;
    s8 y;

    varSL = 0;
    sp0 = 0;
    group = &gMain.spriteGroups[43];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10;
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            var0 = (s8)oamSimple->yOffset + group->baseY;
            if (var0 > 180 || var0 < -60)
            {
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }

    group = &gMain.spriteGroups[42];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10;
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            var0 = (s8)oamSimple->yOffset + group->baseY;
            if (var0 > 180 || var0 < -60)
            {
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        if (gCurrentPinballGame->rayquazaPhaseTimer == 671)
        {
            group->available = 0;
            gMain.spriteGroups[41].available = 1;
            gMain.spriteGroups[45].available = 1;
        }
    }
    else
    {
        group = &gMain.spriteGroups[41];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 - (gCurrentPinballGame->bgScrollXCopy - 88);
            group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 78);
            gCurrentPinballGame->entityCenterX = gCurrentPinballGame->entityPosXQ10 / 10 + 116;
            gCurrentPinballGame->entityCenterY = gCurrentPinballGame->entityPosYQ10 / 10 + 60;
            if (gCurrentPinballGame->rayquazaScreenY > 91)
            {
                gCurrentPinballGame->entityCollisionOriginX = (gCurrentPinballGame->entityPosXQ10 / 10) * 2 + 172;
                gCurrentPinballGame->entityCollisionOriginY = (gCurrentPinballGame->entityPosYQ10 / 10) * 2 + 184;
            }
            else
            {
                gCurrentPinballGame->entityCollisionOriginX = 0;
                gCurrentPinballGame->entityCollisionOriginY = -160;
            }

            if (group->baseY < -70)
                group->baseY = -70;
            if (group->baseY > 180)
                group->baseY = 180;

            var1 = gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][0];
            if (gCurrentPinballGame->bossHitPaletteState > 9)
            {
                sp0 = 11;
                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = sp0;
            }
            else
            {
                if (gCurrentPinballGame->bossHitPaletteState == 1)
                {
                    varSL = 2;
                    sp0 = 14;
                }
                else if (gCurrentPinballGame->bossHitPaletteState == 3)
                {
                    varSL = 2;
                    sp0 = 11;
                }
                else
                {
                    varSL = gCurrentPinballGame->entitySpriteFrame;
                    sp0 = 15;
                }

                if (gCurrentPinballGame->captureSequencePhase == 21)
                    varSL = 8;

                if (gCurrentPinballGame->captureSequencePhase == 22)
                    varSL = 9;

                oamSimple = &group->oam[0];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B612E[var1];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                y = gOamBuffer[oamSimple->oamId].y;
                gCurrentPinballGame->rayquazaScreenY = (y + 78u) + (gCurrentPinballGame->entityPosYQ10 / 10);
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                if (gCurrentPinballGame->bossHitPaletteState < 2)
                    gOamBuffer[oamSimple->oamId].paletteNum = sp0;
                else
                    sp0 = gOamBuffer[oamSimple->oamId].paletteNum;
            }

            gCurrentPinballGame->entitySpriteFrame = gUnknown_086AF3CC[gCurrentPinballGame->entityAnimIndex][2];
            DmaCopy16(3, gUnknown_084AA9EC[varSL], (void *)0x06011620, 0x800);
        }

        group = &gMain.spriteGroups[21];
        if (group->available)
        {
            if (varSL >= 8)
            {
                group->baseX = 0;
                group->baseY = 0;
                varSL = 0;
            }
            else if (varSL >= 6)
            {
                group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 - (gCurrentPinballGame->bgScrollXCopy - 88);
                group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset + 96;
                varSL -= 6;
            }
            else
            {
                group->baseX = 0;
                group->baseY = 0;
            }

            for (i = 0; i < 2; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum = varSL * 12 + i * 8 + 0x109;
                gOamBuffer[oamSimple->oamId].paletteNum = sp0;
            }
        }

        group = &gMain.spriteGroups[45];
        if (group->available)
        {
            s16 var2 = (gCurrentPinballGame->rayquazaScreenY - 70) / 3 + 1;
            if (var2 < 0)
                var2 = 0;
            else if (var2 > 9)
                var2 = 9;

            if (gCurrentPinballGame->entityState != 14)
            {
                if (gCurrentPinballGame->rayquazaBrightnessFade > 0)
                {
                    gMain.blendControl = 0x9E;
                    gMain.blendBrightness = gCurrentPinballGame->rayquazaBrightnessFade;
                    gCurrentPinballGame->rayquazaBrightnessFade--;
                }
                else
                {
                    if ((gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER) == 0)
                    {
                        gMain.blendControl = 0x1E10;
                        gMain.blendAlpha = BLDALPHA_BLEND(var2, 0x10 - var2);
                    }
                }
            }

            group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 - (gCurrentPinballGame->bgScrollXCopy - 88);
            group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 78) + 36 + var2;
            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

            if (gCurrentPinballGame->entityState == 12)
            {
                gMain.spriteGroups[43].available = 1;
                gMain.spriteGroups[41].available = 0;
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }

            if (gCurrentPinballGame->captureSequencePhase == 21)
            {
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }
        }
    }
}

void RenderRayquazaAttackSprites(void)
{
    s16 sp0;
    s16 sp4;
    s16 sp8;
    s16 i, j;
    struct SpriteGroup *group;
    struct Vector32 tempVector2;
    struct Vector32 tempVector;
    s16 var0;
    int x, y;
    int xx, yy;
    int squaredMagnitude;
    u16 *dst;
    const u16 *src;
    struct OamDataSimple *oamSimple;

    sp8 = 0;
    sp4 = 0;
    var0 = 0;
    sp0 = 0;
    group = &gMain.spriteGroups[10];
    if (group->available)
    {
        if (gCurrentPinballGame->hatchRevealState == 3)
        {
            group->baseX = 240;
            group->baseY = 180;
        }
        else
        {
            group->baseX = 96;
            group->baseY = 55;
        }

        gCurrentPinballGame->bossGroupBasePosition.x = group->baseX;
        gCurrentPinballGame->bossGroupBasePosition.y = group->baseY;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].paletteNum = 13;
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->spriteLayerPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[9];
        group->baseX = gCurrentPinballGame->bossGroupBasePosition.x - 8;
        group->baseY = gCurrentPinballGame->bossGroupBasePosition.y - 8;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->spriteLayerPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    UpdateElectricBallGrab();
    switch (gCurrentPinballGame->rayquazaAttackState)
    {
    case 0:
        gCurrentPinballGame->bossPhaseFrame = 0;
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        break;
    case 1:
        if (gCurrentPinballGame->bossPhaseFrame == 0)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame == 8)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame == 24)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame == 36)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame == 50)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame == 56)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->bossPhaseFrame < 14)
            var0 = gCurrentPinballGame->bossPhaseFrame / 2;
        else if (gCurrentPinballGame->bossPhaseFrame < 42)
            var0 = 7;
        else if (gCurrentPinballGame->bossPhaseFrame < 56)
            var0 = (gCurrentPinballGame->bossPhaseFrame - 42) / 2;
        else if (gCurrentPinballGame->bossPhaseFrame < 61)
            var0 = 7;
        else
            var0 = (gCurrentPinballGame->bossPhaseFrame - 61) / 2;

        if (gCurrentPinballGame->bossPhaseFrame < 8)
            sp4 = gCurrentPinballGame->bossPhaseFrame / 2;
        else if (gCurrentPinballGame->bossPhaseFrame < 48)
            sp4 = 12;
        else if (gCurrentPinballGame->bossPhaseFrame < 64)
            sp4 = (gCurrentPinballGame->bossPhaseFrame - 48) / 2 + 4;
        else
            sp4 = 12;

        sp8 = 5;
        gCurrentPinballGame->bossPhaseFrame++;
        if (gCurrentPinballGame->bossPhaseFrame == 75)
        {
            gCurrentPinballGame->bossPhaseFrame = 0;
            gCurrentPinballGame->rayquazaAttackState = 2;
        }
        break;
    case 2:
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        if (gCurrentPinballGame->bossPhaseFrame < 34)
        {
            gCurrentPinballGame->bossPhaseFrame++;
            if (gCurrentPinballGame->bossPhaseFrame == 28)
            {
                if (gCurrentPinballGame->bonusCaptureState)
                {
                    gCurrentPinballGame->rayquazaDiveTargetPos.x = 200 - (Random() % 160);
                    gCurrentPinballGame->rayquazaDiveTargetPos.y = gCurrentPinballGame->ball->positionQ0.y - 347 - (Random() % 80);
                }
                else
                {
                    gCurrentPinballGame->rayquazaDiveTargetPos.x = gCurrentPinballGame->ball->positionQ0.x - 13;
                    gCurrentPinballGame->rayquazaDiveTargetPos.y = gCurrentPinballGame->ball->positionQ0.y - 347;
                }
            }
        }
        else
        {
            gCurrentPinballGame->bossPhaseFrame = 0;
            gCurrentPinballGame->rayquazaAttackState = 3;
            m4aSongNumStart(SE_RAYQUAZA_FLYBY);
        }
        break;
    case 3:
        var0 = 7;
        sp4 = 12;
        if (gCurrentPinballGame->bossPhaseFrame < 2)
        {
            sp8 = gCurrentPinballGame->bossPhaseFrame;
        }
        else if (gCurrentPinballGame->bossPhaseFrame < 10)
        {
            sp8 = (gCurrentPinballGame->bossPhaseFrame - 2) / 2 + 2;
            gCurrentPinballGame->rayquazaDiveFlashTimer = sp4;
            if (sp8 == 2)
            {
                int a = 13;
                int b = 347;
                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - a - gCurrentPinballGame->rayquazaDiveTargetPos.x;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - b - gCurrentPinballGame->rayquazaDiveTargetPos.y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;

                PlayRumble(8);
                if (gCurrentPinballGame->bossSegmentState[0] < 3 && gCurrentPinballGame->bossSegmentState[1] < 3 &&
                    gCurrentPinballGame->bonusCaptureState == 0 && squaredMagnitude < 200)
                {
                    gMain.spriteGroups[36].available = 1;
                    gCurrentPinballGame->bossGrabDurationTimer = 600;
                    m4aSongNumStart(SE_UNKNOWN_0x12A);
                    PlayRumble(9);
                }
            }
        }
        else
        {
            sp8 = 5;
            gCurrentPinballGame->rayquazaAttackState = 4;
        }

        gCurrentPinballGame->bossPhaseFrame++;
        break;
    case 4:
        gCurrentPinballGame->bossPhaseFrame = 0;
        gCurrentPinballGame->rayquazaAttackState = 0;
        break;
    }

    group = &gMain.spriteGroups[17];
    if (group->available)
    {
        // ! odd behavior in the assembly with the addition and subtraction
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 - (gCurrentPinballGame->bgScrollXCopy - 88);
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset + 96;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B609E[var0][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->rayquazaAttackState == 4)
            gMain.spriteGroups[17].available = 0;
    }

    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 - (gCurrentPinballGame->bgScrollXCopy - 88);
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 - gCurrentPinballGame->bgScrollYWithOffset + 96;
        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5ECA[sp4][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->rayquazaAttackState == 4)
            gMain.spriteGroups[18].available = 0;
    }

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->rayquazaDiveTargetPos.x - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->rayquazaDiveTargetPos.y - gCurrentPinballGame->bgScrollYWithOffset;
        for (j = 0; j < 7; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5DCE[sp8][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            if ((s8)gOamBuffer[oamSimple->oamId].y + group->baseY < -300)
            {
                gOamBuffer[oamSimple->oamId].x = 0;
                gOamBuffer[oamSimple->oamId].y = 180;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }

        if (gCurrentPinballGame->rayquazaAttackState == 4)
            gMain.spriteGroups[19].available = 0;
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->rayquazaWindOffset.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 120);
        group->baseY = gCurrentPinballGame->rayquazaWindOffset.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 128);
        for (j = 0; j < 18; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[23];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->rayquazaWindOffset.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 360);
        group->baseY = gCurrentPinballGame->rayquazaWindOffset.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 128);
        for (j = 0; j < 18; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->rayquazaSegmentAltitude > 0)
        gCurrentPinballGame->ball->oamPriority = 1;
    else
        gCurrentPinballGame->ball->oamPriority = 2;

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        switch (gCurrentPinballGame->bossSegmentState[i])
        {
        case 0:
            sp0 = 0;
            gCurrentPinballGame->legendarySegmentPos[i].x = 0;
            gCurrentPinballGame->legendarySegmentPos[i].y = 0;
            break;
        case 1:
            sp0 = gCurrentPinballGame->segmentAnimTimers[i] / 5 + 1;
            if (gCurrentPinballGame->segmentAnimTimers[i] < 14)
            {
                gCurrentPinballGame->segmentAnimTimers[i]++;
            }
            else
            {
                gCurrentPinballGame->segmentAnimTimers[i] = 0;
                gCurrentPinballGame->bossSegmentState[i] = 2;
            }
            break;
        case 2:
            sp0 = gCurrentPinballGame->segmentAnimTimers[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            if (gCurrentPinballGame->bossSegmentState[i] < 3)
            {

                s16 angle = (((gMain.systemFrameCount + 120 * i) % 240) << 0x10) / 240;
                gCurrentPinballGame->legendarySegmentPos[i].x = gCurrentPinballGame->segmentTargetPos[i].x + (Cos(angle) * 4) / 2000;
                gCurrentPinballGame->legendarySegmentPos[i].y = gCurrentPinballGame->segmentTargetPos[i].y + (Sin(angle) * 4) / 2000;

                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->legendarySegmentPos[i].x / 10) - 16;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->legendarySegmentPos[i].y / 10) - 32;;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                if (gCurrentPinballGame->bossGrabbedBall == 0 && gCurrentPinballGame->bonusCaptureState == 0 &&
                    gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired &&
                    gCurrentPinballGame->bossHitReactionTimer == 0 && squaredMagnitude < 300)
                {
                    gCurrentPinballGame->bossGrabDurationTimer = 6;
                    gCurrentPinballGame->ballLockState = 1;
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 3;
                    gCurrentPinballGame->bossActive = 1;

                    tempVector2.x = gCurrentPinballGame->legendarySegmentPos[i].x / 10 + 16;
                    tempVector2.y = gCurrentPinballGame->legendarySegmentPos[i].y / 10 + 32;
                    tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                    tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                    gCurrentPinballGame->captureArcRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                    gCurrentPinballGame->captureArcRadius = Sqrt(gCurrentPinballGame->captureArcRadius * 4) / 2;
                    gCurrentPinballGame->captureArcAngle = ArcTan2(-tempVector.x, tempVector.y);

                    gCurrentPinballGame->rayquazaGrabbedSegmentId = i + 1;
                    gCurrentPinballGame->segmentGrabRenderPos.x = gCurrentPinballGame->legendarySegmentPos[i].x;
                    gCurrentPinballGame->segmentGrabRenderPos.y = gCurrentPinballGame->legendarySegmentPos[i].y;
                    m4aSongNumStart(SE_UNKNOWN_0x12B);
                    PlayRumble(13);
                }
            }

            if (gCurrentPinballGame->segmentAnimTimers[i] < 840)
            {
                gCurrentPinballGame->segmentAnimTimers[i]++;
            }
            else
            {
                gCurrentPinballGame->segmentAnimTimers[i] = 0;
                gCurrentPinballGame->bossSegmentState[i] = 5;
            }
            break;
        case 3: {
            s16 var4;
            int var5;

            sp0 = gCurrentPinballGame->segmentAnimTimers[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            var4 = 29 - gCurrentPinballGame->segmentAnimTimers[i];
            if (var4 < 10)
                var4 = 10;

            gCurrentPinballGame->captureArcAngle -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
            gCurrentPinballGame->ball->rotation -= 0x2000;
            var5 = (gCurrentPinballGame->captureArcRadius * var4) / 30;
            tempVector2.x = gCurrentPinballGame->legendarySegmentPos[i].x / 10 + 16;
            tempVector2.y = gCurrentPinballGame->legendarySegmentPos[i].y / 10 + 32;
            gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
            gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

            if (gCurrentPinballGame->rayquazaSegmentAltitude < 1800)
            {
                gCurrentPinballGame->rayquazaSegmentVelocity = 0;
                gCurrentPinballGame->rayquazaSegmentAltitude += 32;
            }

            if (gCurrentPinballGame->segmentAnimTimers[i] < 180)
            {
                gCurrentPinballGame->segmentAnimTimers[i]++;
            }
            else
            {
                gCurrentPinballGame->segmentAnimTimers[i] = 0;
                gCurrentPinballGame->bossSegmentState[i] = 4;
                gCurrentPinballGame->captureArcRadius /= 2;
                gCurrentPinballGame->ball->positionQ8.y = 0xA500;
            }
            break;
        }
        case 4:
            if (gCurrentPinballGame->segmentAnimTimers[i] < 130)
            {
                if (gCurrentPinballGame->segmentAnimTimers[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0x12C);

                gCurrentPinballGame->rayquazaSegmentVelocity--;
                gCurrentPinballGame->rayquazaSegmentAltitude += gCurrentPinballGame->rayquazaSegmentVelocity;
                if (gCurrentPinballGame->rayquazaSegmentAltitude <= 0)
                {
                    gCurrentPinballGame->rayquazaSegmentAltitude = 0;
                    gCurrentPinballGame->ball->velocity.y = -((gCurrentPinballGame->rayquazaSegmentVelocity * 0x80) / 10) / 2;
                    gCurrentPinballGame->ballLockState = 0;
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 0;
                    gCurrentPinballGame->bossActive = 0;
                    PlayRumble(8);
                }

                gCurrentPinballGame->segmentAnimTimers[i]++;
            }
            break;
        case 5:
            sp0 = gCurrentPinballGame->segmentAnimTimers[i] / 6 + 7;
            if (gCurrentPinballGame->segmentAnimTimers[i] < 11)
            {
                gCurrentPinballGame->segmentAnimTimers[i]++;
            }
            else
            {
                gCurrentPinballGame->segmentAnimTimers[i] = 0;
                gCurrentPinballGame->bossSegmentState[i] = 0;
            }
            break;
        }

        if (group->available)
        {
            DmaCopy16(3, gUnknown_084A6EEC[sp0], (void *)0x06011EA0, 0x280);
            group->baseX = gCurrentPinballGame->legendarySegmentPos[i].x / 10 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gCurrentPinballGame->legendarySegmentPos[i].y / 10 - gCurrentPinballGame->bgScrollYWithOffset;
            for (j = 0; j < 2; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->bossSegmentState[i] == 0)
                group->available = 0;

            if (gCurrentPinballGame->rayquazaGrabbedSegmentId && i == (gCurrentPinballGame->rayquazaGrabbedSegmentId - 1))
                group->available = 0;
        }
    }

    RenderWindCloudMinions();
    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        s16 a;
        group->baseX = gCurrentPinballGame->segmentGrabRenderPos.x / 10 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->segmentGrabRenderPos.y / 10 - gCurrentPinballGame->bgScrollYWithOffset;
        a = gCurrentPinballGame->rayquazaDefeatAnimFrame / 5;
        for (j = 0; j < 5; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B5CC0[a][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->rayquazaDefeatAnimFrame < 25)
        {
            gCurrentPinballGame->rayquazaDefeatAnimFrame++;
            if (gCurrentPinballGame->rayquazaDefeatAnimFrame == 25)
                group->available = 0;
        }
    }

    if (gCurrentPinballGame->rayquazaGrabbedSegmentId)
    {
        gCurrentPinballGame->rayquazaGrabbedSegmentId = 0;
        gCurrentPinballGame->rayquazaDefeatAnimFrame = 0;
        group->available = 1;
    }
}

void UpdateElectricBallGrab(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    u16 *dst;
    const u16 *src;

    group = &gMain.spriteGroups[36];
    if (!group->available)
        return;

    gCurrentPinballGame->bossGrabDurationTimer--;
    if (gCurrentPinballGame->bossGrabDurationTimer > 5)
    {
        var0 = gUnknown_08137D48[(gCurrentPinballGame->bossGrabDurationTimer % 33) / 3];
        if (gCurrentPinballGame->bossFlipperEscapeTimer > 0)
        {
            if (gCurrentPinballGame->bossFlipperEscapeTimer == 7)
                gCurrentPinballGame->ball->positionQ8.x += 0x100;
            else if (gCurrentPinballGame->bossFlipperEscapeTimer == 4)
                gCurrentPinballGame->ball->positionQ8.x -= 0x200;
            else if (gCurrentPinballGame->bossFlipperEscapeTimer == 1)
                gCurrentPinballGame->ball->positionQ8.x += 0x100;

            gCurrentPinballGame->bossFlipperEscapeTimer--;
        }
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->bossGrabDurationTimer -= 30;
                if (gCurrentPinballGame->bossGrabDurationTimer < 5)
                    gCurrentPinballGame->bossGrabDurationTimer = 5;

                gCurrentPinballGame->bossFlipperEscapeTimer = 7;
                m4aSongNumStart(SE_UNKNOWN_0x12A);
            }
        }

        if (gCurrentPinballGame->bossHitFlashTimer)
        {
            gCurrentPinballGame->bossHitFlashTimer--;
            if (gCurrentPinballGame->bossHitFlashTimer > 52)
                var0 = 8;
            else if (gCurrentPinballGame->bossHitFlashTimer > 42)
                var0 = 9;
        }
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                gCurrentPinballGame->bossHitFlashTimer = 60;
        }

    }
    else
    {
        var0 = 8;
    }

    if (gCurrentPinballGame->bossGrabDurationTimer == 0)
    {
        gMain.spriteGroups[36].available = 0;
        gCurrentPinballGame->bossHitFlashTimer = 0;
        gCurrentPinballGame->bossGrabbedBall = 0;
    }
    else
    {
        gCurrentPinballGame->bossGrabbedBall = 1;
        gCurrentPinballGame->ball->velocity.x = 0;
        gCurrentPinballGame->ball->velocity.y = 0;
        gCurrentPinballGame->ball->spin = 0;
    }

    group->baseX = gCurrentPinballGame->ball->positionQ0.x - gCurrentPinballGame->bgScrollXCopy - 8;
    group->baseY = gCurrentPinballGame->ball->positionQ0.y - gCurrentPinballGame->bgScrollYWithOffset - 8;
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gUnknown_086B5D56[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RenderWindCloudMinions(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 rand;
    u16 var0;

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[25];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[27];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[28];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[29];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy + 128);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[31];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[32];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[33];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[34];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[35];
        group->baseX = gCurrentPinballGame->minionPositionQ10.x / 10 - (gCurrentPinballGame->bgScrollXCopy - 368);
        group->baseY = gCurrentPinballGame->minionPositionQ10.y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gMain.spriteGroups[22].available)
    {
        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 6)
        {
            gMain.spriteGroups[24].available = 0;
            gMain.spriteGroups[25].available = 0;
            gMain.spriteGroups[26].available = 1;
            gMain.spriteGroups[27].available = 1;
            if (gCurrentPinballGame->bossSegmentState[0] < 3 && gCurrentPinballGame->bossSegmentState[1] < 3 && gCurrentPinballGame->bonusCaptureState == 0)
            {
                gCurrentPinballGame->ball->velocity.x += 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 11)
        {
            gMain.spriteGroups[26].available = 0;
            gMain.spriteGroups[27].available = 0;
            gMain.spriteGroups[28].available = 1;
            gMain.spriteGroups[29].available = 1;
        }

        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 14)
        {
            gMain.spriteGroups[28].available = 0;
            gMain.spriteGroups[29].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 6)
        {
            gMain.spriteGroups[30].available = 0;
            gMain.spriteGroups[31].available = 0;
            gMain.spriteGroups[32].available = 1;
            gMain.spriteGroups[33].available = 1;
            if (gCurrentPinballGame->bossSegmentState[0] < 3 && gCurrentPinballGame->bossSegmentState[1] < 3 && gCurrentPinballGame->bonusCaptureState == 0)
            {
                gCurrentPinballGame->ball->velocity.x -= 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 11)
        {
            gMain.spriteGroups[32].available = 0;
            gMain.spriteGroups[33].available = 0;
            gMain.spriteGroups[34].available = 1;
            gMain.spriteGroups[35].available = 1;
        }

        if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 14)
        {
            gMain.spriteGroups[34].available = 0;
            gMain.spriteGroups[35].available = 0;
        }
    }

    if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 10)
    {
        if (gCurrentPinballGame->bossSegmentState[0] < 3)
        {
            gCurrentPinballGame->segmentAnimTimers[0] = 0;
            gCurrentPinballGame->bossSegmentState[0] = 1;
            gMain.spriteGroups[15].available = 1;
            rand = Random() % 8;
            var0 = ((gMain.systemFrameCount % 240) << 0x10) / 240;
            gCurrentPinballGame->segmentTargetPos[0].x = gUnknown_086AF744[rand].x;
            gCurrentPinballGame->segmentTargetPos[0].y = gUnknown_086AF744[rand].y;
            gCurrentPinballGame->legendarySegmentPos[0].x = gCurrentPinballGame->segmentTargetPos[0].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->legendarySegmentPos[0].y = gCurrentPinballGame->segmentTargetPos[0].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->rayquazaWindAnimSubFrame == 16)
    {
        if (gCurrentPinballGame->bossSegmentState[1] < 3)
        {
            gCurrentPinballGame->segmentAnimTimers[1] = 0;
            gCurrentPinballGame->bossSegmentState[1] = 1;
            gMain.spriteGroups[16].available = 1;
            rand = (Random() % 8 + 8) % 32; // Force 8 to be added to r1
            var0 = (((gMain.systemFrameCount + 120) % 240) << 0x10) / 240;
            gCurrentPinballGame->segmentTargetPos[1].x = gUnknown_086AF744[rand].x;
            gCurrentPinballGame->segmentTargetPos[1].y = gUnknown_086AF744[rand].y;
            gCurrentPinballGame->legendarySegmentPos[1].x = gCurrentPinballGame->segmentTargetPos[1].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->legendarySegmentPos[1].y = gCurrentPinballGame->segmentTargetPos[1].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->bossImpactShakeTimer > 0)
    {
        gCurrentPinballGame->bossImpactShakeTimer--;
        if (gCurrentPinballGame->bossImpactShakeTimer < 12)
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12];
        else if (gCurrentPinballGame->bossImpactShakeTimer < 24)
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12] * 2;
        else if (gCurrentPinballGame->bossImpactShakeTimer < 36)
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12] * 4;
        else if (gCurrentPinballGame->bossImpactShakeTimer < 48)
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12] * 2;
        else
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12];

        if (gCurrentPinballGame->bossImpactShakeTimer == 0)
            gCurrentPinballGame->bossShakeOffsetY = 0;
    }

    if (gCurrentPinballGame->rayquazaDiveFlashTimer > 0)
    {
        s16 var0 = gCurrentPinballGame->rayquazaDiveFlashTimer % 4;
        if (var0 / 2 != 0)
            gCurrentPinballGame->bossShakeOffsetX = 2;
        else
            gCurrentPinballGame->bossShakeOffsetX = -2;

        gCurrentPinballGame->rayquazaDiveFlashTimer--;
        if (gCurrentPinballGame->rayquazaDiveFlashTimer == 0)
            gCurrentPinballGame->bossShakeOffsetX = 0;
    }
}

void UpdateRayquazaIntroOutroSequence(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->rayquazaCloudPhase == 0)
    {
        if (gCurrentPinballGame->rayquazaPhaseTimer < 689)
        {
            if (gCurrentPinballGame->rayquazaPhaseTimer < 569)
            {
                if (gCurrentPinballGame->rayquazaPhaseTimer % 160 == 20)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x80);

                if (gCurrentPinballGame->rayquazaPhaseTimer % 160 == 90)
                    m4aMPlayFadeOutTemporarily(&gMPlayInfo_SE1, 5);

                if (gCurrentPinballGame->rayquazaPhaseTimer % 160 == 1)
                    m4aSongNumStart(SE_RAYQUAZA_STAGE_WIND);

                if (gCurrentPinballGame->rayquazaPhaseTimer % 160 == 2)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x33);
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer >= 512)
                gCurrentPinballGame->fieldScrollOffsetY = (gCurrentPinballGame->rayquazaPhaseTimer - 512) / 2 - 88;

            if (gCurrentPinballGame->rayquazaPhaseTimer == 624)
                gCurrentPinballGame->entityActivePhase = 1;

            if (gCurrentPinballGame->rayquazaPhaseTimer < 513)
                gCurrentPinballGame->rayquazaBgScrollSpeed = gCurrentPinballGame->rayquazaPhaseTimer / 2;

            if (gCurrentPinballGame->rayquazaPhaseTimer == 688)
                gCurrentPinballGame->rayquazaCloudPhase = 1;

            gCurrentPinballGame->rayquazaPhaseTimer++;
            if (gCurrentPinballGame->rayquazaPhaseTimer <= 568 && gCurrentPinballGame->bonusSequenceTimer > 5)
                gCurrentPinballGame->bonusSequenceTimer--;

            if (gCurrentPinballGame->rayquazaPhaseTimer == 1)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 300;
                gCurrentPinballGame->minionLogicPosition[0].y = 1200;
                gCurrentPinballGame->minionLogicPosition[1].x = 1200;
                gCurrentPinballGame->minionLogicPosition[1].y = 400;
                gCurrentPinballGame->minionLogicPosition[2].x = 1000;
                gCurrentPinballGame->minionLogicPosition[2].y = 2500;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 88)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 1600;
                gCurrentPinballGame->minionLogicPosition[0].y = 1800;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 120)
            {
                gCurrentPinballGame->minionLogicPosition[1].x = 600;
                gCurrentPinballGame->minionLogicPosition[1].y = 1800;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 170)
            {
                gCurrentPinballGame->minionLogicPosition[2].x = 1800;
                gCurrentPinballGame->minionLogicPosition[2].y = 2000;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 215)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 0;
                gCurrentPinballGame->minionLogicPosition[0].y = 2000;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 305)
            {
                gCurrentPinballGame->minionLogicPosition[1].x = 1800;
                gCurrentPinballGame->minionLogicPosition[1].y = 1800;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 315)
            {
                gCurrentPinballGame->minionLogicPosition[2].x = 300;
                gCurrentPinballGame->minionLogicPosition[2].y = 1800;
            }

            group = &gMain.spriteGroups[11];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->minionLogicPosition[0].x / 10;
                group->baseY = gCurrentPinballGame->minionLogicPosition[0].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->minionLogicPosition[0].y -= 20;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 4; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            group = &gMain.spriteGroups[12];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->minionLogicPosition[1].x / 10;
                group->baseY = gCurrentPinballGame->minionLogicPosition[1].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->minionLogicPosition[1].y -= 12;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 6; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            group = &gMain.spriteGroups[13];
            if (group->available)
            {
                group->baseX = gCurrentPinballGame->minionLogicPosition[2].x / 10;
                group->baseY = gCurrentPinballGame->minionLogicPosition[2].y / 10;
                if (group->baseY <= -60)
                    group->baseY = -60;
                else
                    gCurrentPinballGame->minionLogicPosition[2].y -= 18;

                if (group->baseY > 200)
                    group->baseY = 180;

                for (i = 0; i < 5; i++)
                {
                    oamSimple = &group->oam[i];
                    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                }
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 660)
            {
                gMain.spriteGroups[11].available = 0;
                gMain.spriteGroups[12].available = 0;
                gMain.spriteGroups[13].available = 0;
            }

            group = &gMain.spriteGroups[14];
            if (group->available)
            {
                if (gCurrentPinballGame->rayquazaPhaseTimer >= 195 && gCurrentPinballGame->rayquazaPhaseTimer < 205)
                    var0 = gUnknown_086AF784[(gCurrentPinballGame->rayquazaPhaseTimer - 195) / 2];
                else
                    var0 = (gCurrentPinballGame->rayquazaPhaseTimer % 4) / 2;

                group->baseX = gCurrentPinballGame->scopePositionQ10.x / 10;
                group->baseY = gCurrentPinballGame->scopePositionQ10.y / 10;

                if (group->baseY < -60)
                    group->baseY = -60;
                if (group->baseY > 180)
                    group->baseY = 180;

                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 150)
            {
                gMain.spriteGroups[14].available = 1;
                gCurrentPinballGame->scopePositionQ10.x = 1600;
                gCurrentPinballGame->scopePositionQ10.y = -100;
                gCurrentPinballGame->scopeVelocity.x = -21;
                gCurrentPinballGame->scopeVelocity.y = 14;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer > 205)
            {
                gCurrentPinballGame->scopeVelocity.y++;
                gCurrentPinballGame->scopePositionQ10.x += gCurrentPinballGame->scopeVelocity.x;
                gCurrentPinballGame->scopePositionQ10.y += gCurrentPinballGame->scopeVelocity.y;
            }
            else if (gCurrentPinballGame->rayquazaPhaseTimer > 150)
            {
                gCurrentPinballGame->scopePositionQ10.x += gCurrentPinballGame->scopeVelocity.x;
                gCurrentPinballGame->scopePositionQ10.y += gCurrentPinballGame->scopeVelocity.y;
            }

            if (gCurrentPinballGame->rayquazaPhaseTimer == 350)
                gMain.spriteGroups[14].available = 0;
        }
    }

    if (gCurrentPinballGame->rayquazaCloudPhase == 2)
    {
        if (gCurrentPinballGame->rayquazaPhaseTimer < 256)
        {
            gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->rayquazaPhaseTimer / -2;
            gCurrentPinballGame->rayquazaPhaseTimer++;
        }

        group = &gMain.spriteGroups[11];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->minionLogicPosition[0].x / 10;
            group->baseY = gCurrentPinballGame->minionLogicPosition[0].y / 10;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (gCurrentPinballGame->rayquazaPhaseTimer < 256)
                gCurrentPinballGame->minionLogicPosition[0].y += 20;

            if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = &gMain.spriteGroups[12];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->minionLogicPosition[1].x / 10;
            group->baseY = gCurrentPinballGame->minionLogicPosition[1].y / 10;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (gCurrentPinballGame->rayquazaPhaseTimer < 256)
                gCurrentPinballGame->minionLogicPosition[1].y += 10;

            if (group->baseY < -60)
                group->baseY = -60;

            for (i = 0; i < 6; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }

        group = &gMain.spriteGroups[14];
        if (group->available)
        {
            if (gCurrentPinballGame->rayquazaPhaseTimer >= 190 && gCurrentPinballGame->rayquazaPhaseTimer < 200)
                var0 = gUnknown_086AF784[(gCurrentPinballGame->rayquazaPhaseTimer - 190) / 2];
            else
                var0 = (gCurrentPinballGame->rayquazaPhaseTimer % 4) / 2;

            group->baseX = gCurrentPinballGame->scopePositionQ10.x / 10;
            group->baseY = gCurrentPinballGame->scopePositionQ10.y / 10;

            if (group->baseY < -60)
                group->baseY = -60;
            if (group->baseY > 180)
                group->baseY = 180;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;

            if (gCurrentPinballGame->rayquazaPhaseTimer > 160)
            {
                gCurrentPinballGame->scopePositionQ10.x += gCurrentPinballGame->scopeVelocity.x;
                gCurrentPinballGame->scopePositionQ10.y += gCurrentPinballGame->scopeVelocity.y;
            }
        }
    }

    if (gCurrentPinballGame->fieldScrollOffsetY >= -0x20)
        gCurrentPinballGame->fieldEntryInProgress = 0;
    else
        gCurrentPinballGame->fieldEntryInProgress = 1;

    gMain.bgOffsets[2].yOffset += gCurrentPinballGame->rayquazaBgScrollSpeed;
    gMain.bgOffsets[1].yOffset += gCurrentPinballGame->rayquazaBgScrollSpeed;
    gMain.bgOffsets[3].yOffset += gCurrentPinballGame->rayquazaBgScrollSpeed / 4 + 224;
}

