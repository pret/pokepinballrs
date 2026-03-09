#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"


extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gUnknown_08352BD8[];
extern const u8 gUnknown_0849F1CC[];
extern const s8 gUnknown_084A11EC[][0x300];
extern struct SongHeader se_unk_118;
extern struct SongHeader se_unk_11b;
extern struct SongHeader se_unk_11c;
extern struct SongHeader se_unk_11d;
extern struct SongHeader se_unk_11f;
extern const s16 gUnknown_086AEE20[];
extern const s16 gUnknown_086AEF28[];
extern const u16 gUnknown_086AEF40[][31];
extern const u16 gUnknown_086AF0B4[];
extern const u16 gUnknown_086AF140[][2];
extern const struct Vector16 gUnknown_086AF2CC[];
extern const u16 gUnknown_086AF2DC[][2];
extern const s16 gUnknown_086AF34C[][3];
extern const s16 gUnknown_086AF3AC[];
extern const s16 gUnknown_086AF3B2[];
extern const s16 gUnknown_086AF3BE[];
extern const u16 gUnknown_086AF3C6[];
extern const u16 gUnknown_086B63AA[12][2][3];
extern const u16 gUnknown_086B63F2[24][4][3];
extern const u16 gUnknown_086B6512[12][6][3];
extern const u16 gUnknown_086B65EA[166][19][3];
extern const u16 gUnknown_086B8AE0[58][10][3];


void GroudonBoardProcess_3A_3B120(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->entityActivePhase = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->bonusCaptureState = 3;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    gCurrentPinballGame->hatchRevealState = 3;
    gCurrentPinballGame->bossBgPaletteIndex = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->bossHitPaletteState = 0;
    gCurrentPinballGame->bossFieldScrollQ10 = 0;
    gCurrentPinballGame->bossCryCountdown = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;
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
    gCurrentPinballGame->bossHitReactionTimer = 0;
    gCurrentPinballGame->bossVortexScaleTimer = 0;
    gCurrentPinballGame->groudonAttackCycleCount = 0;
    gCurrentPinballGame->groudonAttackColumn = 0;
    gCurrentPinballGame->groudonAttackFeedbackTimer = 0;
    gCurrentPinballGame->bossFlipperEscapeTimer = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;
    gCurrentPinballGame->groudonFireballChaseTimer = 0;
    gCurrentPinballGame->groudonFireballAngle = 0;
    gCurrentPinballGame->bossGrabDurationTimer = 0;
    gCurrentPinballGame->groudonFireballPosQ10.x = 0;
    gCurrentPinballGame->groudonFireballPosQ10.y = 0;
    gCurrentPinballGame->rockSpawnSequenceTimer = 0;
    gCurrentPinballGame->groudonFallAcceleration = 0;
    gCurrentPinballGame->bossImpactShakeTimer = 0;
    gCurrentPinballGame->groudonQuakeSubTimer = 0;
    gCurrentPinballGame->groudonQuakeIntensity = 0;

    for (i = 0; i < 4; i++)
    {
        gCurrentPinballGame->rockSpriteScaleOffset[i].x = 0;
        gCurrentPinballGame->rockSpriteScaleOffset[i].y = 0;
        gCurrentPinballGame->rockAnimState[i] = 0;
        gCurrentPinballGame->rockAnimEndFrame[i] = 0;
        gCurrentPinballGame->rockNextState[i] = 0;
        gCurrentPinballGame->rockAnimCurrentFrame[i] = 0;
        gCurrentPinballGame->rockAnimLoopStart[i] = 0;
        gCurrentPinballGame->rockAnimLoopCount[i] = 0;
        gCurrentPinballGame->rockHitReactionTimer[i] = 0;
        gCurrentPinballGame->rockFrameDelayCounter[i] = 0;
        gCurrentPinballGame->rockCollisionPos[i].x = 0;
        gCurrentPinballGame->rockCollisionPos[i].y = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->fireRockSpawnSlot[i] = 0;
        gCurrentPinballGame->fireRockPhase[i] = 0;
        gCurrentPinballGame->fireRockSpriteFrame[i] = 0;
        gCurrentPinballGame->fireRockBallHitFlag[i] = 0;
        gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
        gCurrentPinballGame->fireRockFallSpeed[i] = 0;
        gCurrentPinballGame->fireRockAltitudeQ10[i] = 0;
        gCurrentPinballGame->fireRockLogicPosQ10[i].x = 0;
        gCurrentPinballGame->fireRockLogicPosQ10[i].y = 0;
        gCurrentPinballGame->fireRockCollisionPos[i].x = 0;
        gCurrentPinballGame->fireRockCollisionPos[i].y = 0;
    }

    gCurrentPinballGame->fieldEntryInProgress = 1;
    RenderGroudonAttackSprites();
    UpdateGroudonStateMachine();
    RenderGroudonSprite();
    DmaCopy16(3, gUnknown_0849F1CC, (void *)0x06015800, 0x2000);
    AnimateLavaBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_GROUDON);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void GroudonBoardProcess_3B_3B49C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballLocked = 1;
        if (gCurrentPinballGame->stageTimer < 500)
        {
            gCurrentPinballGame->fieldScrollOffsetY = -64;
            gCurrentPinballGame->stageTimer++;
        }
        else if (gCurrentPinballGame->stageTimer < 820)
        {
            gCurrentPinballGame->fieldScrollOffsetY = (gCurrentPinballGame->stageTimer - 500) / 5 - 64;
            gCurrentPinballGame->stageTimer++;;
            if (gCurrentPinballGame->fieldScrollOffsetY >= -32)
                gCurrentPinballGame->fieldEntryInProgress = 0;

            if (gCurrentPinballGame->stageTimer == 650)
                gCurrentPinballGame->entityActivePhase = 1;
        }
        else
        {
            gCurrentPinballGame->fieldScrollOffsetY = 0;
            gCurrentPinballGame->boardState = 1;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case 2:
        if (gCurrentPinballGame->stageTimer < 120)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = 3;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[6].available = 1;
            gMain.spriteGroups[5].available = 1;
            DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
            gCurrentPinballGame->bonusScrollOffsetY = 136;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->bossActive = 1;
        }
        break;
    case 3:
        ProceessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = 400000;
            gCurrentPinballGame->scoreAddedInFrame = 50000000;
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
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->scoreAddedInFrame = 50000000;
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
        }
        break;
    case 6:
        ProceessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->bossActive = 1;
        break;
    }

    RenderGroudonAttackSprites();
    UpdateGroudonStateMachine();
    RenderGroudonSprite();
    AnimateLavaBackground();
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

void UpdateGroudonStateMachine(void)
{
    s16 i;
    struct Vector32 tempVector;

    if (gCurrentPinballGame->bossHitReactionTimer)
    {
        gCurrentPinballGame->bossHitReactionTimer--;
        gCurrentPinballGame->bossHitPaletteState = 1;
        if (gCurrentPinballGame->bossHitReactionTimer == 35)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_unk_118);
            gCurrentPinballGame->scoreAddedInFrame = 500000;
            PlayRumble(7);
            gCurrentPinballGame->bonusModeHitCount++;
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                gCurrentPinballGame->entityState = 6;
        }

        if (gCurrentPinballGame->bossHitReactionTimer < 31)
            gCurrentPinballGame->bossHitPaletteState = 0;
    }

    switch (gCurrentPinballGame->entityState)
    {
    case 0:
        gCurrentPinballGame->entityState = 1;
        gCurrentPinballGame->entityAnimIndex = 22;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entitySubPhase = 0;
        gCurrentPinballGame->entityPosXQ10 = 0;
        gCurrentPinballGame->entityPosYQ10 = -1200;
        gCurrentPinballGame->groudonFallAcceleration = 0;
        break;
    case 1:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 36)
            {
                if (gCurrentPinballGame->entitySubPhase < 18)
                {
                    gCurrentPinballGame->entityAnimIndex = 34;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 0;
                    gCurrentPinballGame->entityState = 2;
                    gCurrentPinballGame->entityReturnState = 4;
                    gCurrentPinballGame->entitySubPhase = 9;
                }
            }
        }

        if (gCurrentPinballGame->entityAnimIndex == 22)
        {
            if (gCurrentPinballGame->entityAnimTimer < 500)
            {
                if (gCurrentPinballGame->entityAnimTimer == 50 || gCurrentPinballGame->entityAnimTimer == 270)
                {
                    gCurrentPinballGame->groudonQuakeSubTimer = 31;
                    gCurrentPinballGame->groudonQuakeIntensity = gCurrentPinballGame->entityAnimTimer / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }

                if (gCurrentPinballGame->entityAnimTimer == 160 || gCurrentPinballGame->entityAnimTimer == 380)
                {
                    gCurrentPinballGame->groudonQuakeSubTimer = 31;
                    gCurrentPinballGame->groudonQuakeIntensity = gCurrentPinballGame->entityAnimTimer / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }

                if (gCurrentPinballGame->entityAnimTimer == 490)
                {
                    gCurrentPinballGame->groudonQuakeSubTimer = 31;
                    gCurrentPinballGame->groudonQuakeIntensity = 4;
                    m4aSongNumStart(SE_UNKNOWN_0x11A);
                    PlayRumble(8);
                }
            }

            if (gCurrentPinballGame->entityAnimTimer >= 630)
            {
                if (gCurrentPinballGame->entityPosYQ10 < 0)
                {
                    gCurrentPinballGame->groudonFallAcceleration += 4;
                    gCurrentPinballGame->entityPosYQ10 += gCurrentPinballGame->groudonFallAcceleration;
                    if (gCurrentPinballGame->entityPosYQ10 > 0)
                        gCurrentPinballGame->entityPosYQ10 = 0;
                }
            }

            if (gCurrentPinballGame->entityPosYQ10 >= 0)
            {
                gCurrentPinballGame->bossImpactShakeTimer = 60;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->entityAnimIndex == 33)
        {
            if (gCurrentPinballGame->entityAnimTimer == 0)
                gCurrentPinballGame->bossCryCountdown = 41;
        }

        if (gCurrentPinballGame->bonusSequenceTimer > 120)
            gCurrentPinballGame->bonusSequenceTimer--;
        break;
    case 2:
        if (gCurrentPinballGame->bossHitReactionTimer > 30)
        {
            gCurrentPinballGame->entityAnimIndex = 21;
            gCurrentPinballGame->entityAnimTimer = 0;
            break;
        }

        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 2)
            {
                if (gCurrentPinballGame->entitySubPhase < 12)
                {
                    gCurrentPinballGame->entityAnimIndex = 0;
                    gCurrentPinballGame->entitySubPhase++;
                    if (gCurrentPinballGame->entitySubPhase == 12 && gCurrentPinballGame->entityReturnState == 4)
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (gCurrentPinballGame->rockAnimState[i] < 9)
                                gCurrentPinballGame->rockAnimState[i] = 9;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->entityReturnState == 4)
                    {
                        gCurrentPinballGame->entityAnimIndex = 36;
                        gCurrentPinballGame->entityState = 4;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                    else if (gCurrentPinballGame->entityReturnState == 3)
                    {
                        gCurrentPinballGame->entityAnimIndex = 76;
                        gCurrentPinballGame->entityState = 3;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimIndex = 58;
                        gCurrentPinballGame->entityState = 5;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                }
            }
        }

        if (gCurrentPinballGame->entityAnimIndex == 21)
            gCurrentPinballGame->entityAnimIndex = 0;
        break;
    case 3:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            s16 varZZ;
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 93 || gCurrentPinballGame->entityAnimIndex == 96 || gCurrentPinballGame->entityAnimIndex == 99)
            {
                gCurrentPinballGame->entityAnimIndex = 0;
                gCurrentPinballGame->entityState = 2;

                if (gCurrentPinballGame->groudonAttackCycleCount & 1)
                {
                    gCurrentPinballGame->entityReturnState = 4;
                    gCurrentPinballGame->entitySubPhase = 8;
                }
                else
                {
                    gCurrentPinballGame->entityReturnState = 5;
                    gCurrentPinballGame->entitySubPhase = 8;
                }

                gCurrentPinballGame->groudonAttackCycleCount++;
            }

            if (gCurrentPinballGame->entityAnimIndex == 90)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11c);
                gCurrentPinballGame->groudonAttackFeedbackTimer = 8;
                gCurrentPinballGame->groudonFireballChaseTimer = 35;
                gMain.spriteGroups[22].available = 1;
                gCurrentPinballGame->groudonFireballPosQ10.x = 1200;
                gCurrentPinballGame->groudonFireballPosQ10.y = 1240;
                tempVector.x = gCurrentPinballGame->groudonFireballPosQ10.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
                tempVector.y = gCurrentPinballGame->groudonFireballPosQ10.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
                gCurrentPinballGame->groudonFireballAngle = ArcTan2(-tempVector.x, tempVector.y);
                if (gCurrentPinballGame->bonusCaptureState)
                    gCurrentPinballGame->groudonFireballAngle = (((Random() * gMain.systemFrameCount) % 100) * 0x5000) / 100 + 0x9800;

                if (gCurrentPinballGame->groudonFireballAngle < 0x4000)
                {
                    gCurrentPinballGame->groudonFireballAngle = 0xE800;
                    gCurrentPinballGame->groudonAttackColumn = 2;
                    gCurrentPinballGame->groudonFireballPosQ10.x = 1340;
                }
                else if (gCurrentPinballGame->groudonFireballAngle < 0x9800)
                {
                    gCurrentPinballGame->groudonFireballAngle = 0x9800;
                    gCurrentPinballGame->groudonAttackColumn = 1;
                    gCurrentPinballGame->groudonFireballPosQ10.x = 1060;
                }
                else if (gCurrentPinballGame->groudonFireballAngle < 0xB000)
                {
                    gCurrentPinballGame->groudonAttackColumn = 1;
                    gCurrentPinballGame->groudonFireballPosQ10.x = 1060;
                }
                else if (gCurrentPinballGame->groudonFireballAngle < 0xD000)
                {
                    gCurrentPinballGame->groudonAttackColumn = 0;
                }
                else if (gCurrentPinballGame->groudonFireballAngle < 0xE800)
                {
                    gCurrentPinballGame->groudonAttackColumn = 2;
                    gCurrentPinballGame->groudonFireballPosQ10.x = 1340;
                }
                else
                {
                    gCurrentPinballGame->groudonFireballAngle = 0xE800;
                    gCurrentPinballGame->groudonAttackColumn = 2;
                    gCurrentPinballGame->groudonFireballPosQ10.x = 1340;
                }

                gCurrentPinballGame->entityAnimIndex += gCurrentPinballGame->groudonAttackColumn * 3;
                if (gCurrentPinballGame->bonusCaptureState)
                    gCurrentPinballGame->bonusCaptureState -= 0;
            }
        }
        break;
    case 4:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 56)
            {
                if (gCurrentPinballGame->entitySubPhase < 6)
                {
                    gCurrentPinballGame->entityAnimIndex = 54;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 0;
                    gCurrentPinballGame->entityState = 2;
                    gCurrentPinballGame->entityReturnState = 3;
                    gCurrentPinballGame->entitySubPhase = 6;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 50)
            {
                if (gCurrentPinballGame->entityAnimTimer == 0)
                {
                    gMain.spriteGroups[30].available = 1;
                    gCurrentPinballGame->bossVortexScaleTimer = 0;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11d);
                }
            }
        }
        break;
    case 5:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 74)
            {
                gCurrentPinballGame->entityAnimIndex = 0;
                gCurrentPinballGame->entityState = 2;
                gCurrentPinballGame->entityReturnState = 3;
                gCurrentPinballGame->entitySubPhase = 8;
            }

            if (gCurrentPinballGame->entityAnimIndex == 71)
            {
                if (gCurrentPinballGame->entityAnimTimer == 0)
                {
                    gCurrentPinballGame->bumperShakeAxis = 0;
                    gCurrentPinballGame->bumperShakeTimer = 1;
                    gCurrentPinballGame->bossImpactShakeTimer = 60;
                    PlayRumble(13);
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                }
            }
        }
        break;
    case 6:
        gCurrentPinballGame->entityActivePhase = 3;

        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch groudon
            gCurrentPinballGame->entityState = 9;
            gCurrentPinballGame->entityAnimIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_GROUDON;
            gCurrentPinballGame->bossFieldScrollQ10 = 0;
            gCurrentPinballGame->captureSequencePhase = 0;
            gCurrentPinballGame->entityCaptureTimer = 0;
            gCurrentPinballGame->catchModeHitPhase = 2;
        }
        else
        {
            // bonus completed
            gCurrentPinballGame->entityState = 7;
            gCurrentPinballGame->entityAnimIndex = 32;
            gCurrentPinballGame->boardEntityCollisionMode = 0;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->bonusCaptureState = 2;
            gCurrentPinballGame->bonusSequenceTimer = 0;
        }

        gCurrentPinballGame->entitySubPhase = 0;
        gCurrentPinballGame->entityAnimTimer = 0;
        if (gMain.spriteGroups[24].available)
            gCurrentPinballGame->bossGrabDurationTimer = 1;
        break;
    case 7:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 36)
            {
                if (gCurrentPinballGame->entitySubPhase < 18)
                {
                    gCurrentPinballGame->entityAnimIndex = 34;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 2;
                    gCurrentPinballGame->entityState = 8;
                    gCurrentPinballGame->entitySubPhase = 0;
                }
            }
        }

        if (gCurrentPinballGame->entityAnimIndex == 33)
        {
            if (gCurrentPinballGame->entityAnimTimer == 0)
                gCurrentPinballGame->bossCryCountdown = 41;
        }
        break;
    case 8:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 20)
            {
                if (gCurrentPinballGame->entitySubPhase < 7)
                {
                    gCurrentPinballGame->entityAnimIndex = 3;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 3;
                    gCurrentPinballGame->entityState = 10;
                    gCurrentPinballGame->boardState = 2;
                    gCurrentPinballGame->stageTimer = 0;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 3 || gCurrentPinballGame->entityAnimIndex == 12)
                gCurrentPinballGame->entityPosYQ10 -= 10;

            if ((gCurrentPinballGame->entityAnimIndex >= 4 && gCurrentPinballGame->entityAnimIndex < 6) ||
                gCurrentPinballGame->entityAnimIndex == 13 || gCurrentPinballGame->entityAnimIndex == 14)
            {
                gCurrentPinballGame->entityPosYQ10 -= 20;
            }

            if (gCurrentPinballGame->entityAnimIndex == 5)
            {
                if (gCurrentPinballGame->entityAnimTimer == 0)
                {
                    gCurrentPinballGame->groudonQuakeSubTimer = 31;
                    gCurrentPinballGame->groudonQuakeIntensity = 6;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 14)
            {
                if (gCurrentPinballGame->entityAnimTimer == 0)
                {
                    gCurrentPinballGame->groudonQuakeSubTimer = 31;
                    gCurrentPinballGame->groudonQuakeIntensity = 5;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }
            }
        }
        break;
    case 9:
        if (gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 2)
                gCurrentPinballGame->entityAnimIndex = 0;
        }

        if (gCurrentPinballGame->bossFieldScrollQ10 > -500)
        {
            gCurrentPinballGame->bossFieldScrollQ10 += (-500 - gCurrentPinballGame->bossFieldScrollQ10) / 30;
            gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->bossFieldScrollQ10 / 10;
            if (gCurrentPinballGame->fieldScrollOffsetY < -38)
                gCurrentPinballGame->fieldScrollOffsetY = -38;
        }

        if (gCurrentPinballGame->captureSequencePhase == 21)
            gCurrentPinballGame->entityAnimIndex = 74;

        if (gCurrentPinballGame->captureSequencePhase == 22)
            gCurrentPinballGame->entityAnimIndex = 75;
        break;
    case 10:
        break;
    }

    if (gCurrentPinballGame->bossImpactShakeTimer > 0)
    {
        gCurrentPinballGame->bossImpactShakeTimer--;
        if (gCurrentPinballGame->bossImpactShakeTimer < 20)
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12] * 2;
        else
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF28[gCurrentPinballGame->bossImpactShakeTimer % 12] * 4;

        if (gCurrentPinballGame->bossImpactShakeTimer == 0)
            gCurrentPinballGame->bossShakeOffsetY = 0;

        if (gCurrentPinballGame->bossImpactShakeTimer == 8)
        {
            i = 0;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->fireRockPhase[i] = 0;
            gCurrentPinballGame->fireRockSpriteFrame[i] = 0;
            gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
        }

        if (gCurrentPinballGame->bossImpactShakeTimer == 20)
        {
            i = 1;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->fireRockPhase[i] = 0;
            gCurrentPinballGame->fireRockSpriteFrame[i] = 13;
            gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
        }

        if (gCurrentPinballGame->bossImpactShakeTimer == 53)
        {
            i = 2;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->fireRockPhase[i] = 0;
            gCurrentPinballGame->fireRockSpriteFrame[i] = 22;
            gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
        }
    }

    if (gCurrentPinballGame->groudonQuakeSubTimer)
    {
        gCurrentPinballGame->groudonQuakeSubTimer--;
        if (gCurrentPinballGame->groudonQuakeIntensity < 6)
        {
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AEF40[gCurrentPinballGame->groudonQuakeIntensity][30 - gCurrentPinballGame->groudonQuakeSubTimer % 31];
        }
        else
        {
            gCurrentPinballGame->bossShakeOffsetY = gUnknown_086AF0B4[69 - gCurrentPinballGame->groudonQuakeSubTimer % 70];
        }

        if (gCurrentPinballGame->groudonQuakeSubTimer == 0)
            gCurrentPinballGame->bossShakeOffsetY = 0;
    }

    if (gCurrentPinballGame->bossCryCountdown)
    {
        gCurrentPinballGame->bossCryCountdown--;
        if (gCurrentPinballGame->bossCryCountdown == 20)
        {
            PlayCry_Normal(gSpeciesInfo[SPECIES_GROUDON].mainSeriesIndexNumber, 0);
            gCurrentPinballGame->groudonQuakeSubTimer = 70;
            gCurrentPinballGame->groudonQuakeIntensity = 6;
        }

        if (gCurrentPinballGame->bossCryCountdown == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderGroudonSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var0;
    int palette;

    group = &gMain.spriteGroups[29];
    if (group->available)
    {
        var0 = gUnknown_086AF140[gCurrentPinballGame->entityAnimIndex][0];
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + 100u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 +  84u - gCurrentPinballGame->bgScrollYWithOffset;
        gCurrentPinballGame->entityCenterX = gCurrentPinballGame->entityPosXQ10 / 10 + 118;
        gCurrentPinballGame->entityCenterY = gCurrentPinballGame->entityPosYQ10 / 10 + 60;
        gCurrentPinballGame->entityCollisionOriginX = (gCurrentPinballGame->entityPosXQ10 / 10) * 2 + 184;
        gCurrentPinballGame->entityCollisionOriginY = (gCurrentPinballGame->entityPosYQ10 / 10) * 2 + 156;
        if (group->baseY < -60)
            group->baseY = -60;
        if (group->baseY > 180)
            group->baseY = 180;

        if (gCurrentPinballGame->bossHitPaletteState > 9)
        {
            palette = 11;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else if (gCurrentPinballGame->bossHitPaletteState == 1)
        {
            palette = 14;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else if (gCurrentPinballGame->bossHitPaletteState == 3)
        {
            palette = 11;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else
        {
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B65EA[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }
    }

    group = &gMain.spriteGroups[23];
    if (group->available)
    {
        if (gCurrentPinballGame->groudonAttackFeedbackTimer > 0)
        {
            gCurrentPinballGame->groudonAttackFeedbackTimer--;
            if (gCurrentPinballGame->groudonAttackFeedbackTimer == 0)
                group->available = 0;
        }

        var0 = gCurrentPinballGame->groudonAttackColumn * 2 - (gCurrentPinballGame->groudonAttackFeedbackTimer / 4 - 1);
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + 100u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 +  84u - gCurrentPinballGame->bgScrollYWithOffset;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B6512[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->catchModeHitPhase == 2)
        {
            gMain.spriteGroups[23].available = 0;
            gCurrentPinballGame->groudonAttackFeedbackTimer = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->groudonAttackFeedbackTimer == 8)
            group->available = 1;
    }
}

void RenderGroudonAttackSprites(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 varSL;
    int xx, yy;
    int squaredMagnitude;
    struct Vector32 tempVector;
    s8 var0;

    varSL = 0;
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

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        gCurrentPinballGame->bossGrabDurationTimer--;
        if (gCurrentPinballGame->bossGrabDurationTimer >= 600)
        {
            varSL = 0;
        }
        else if (gCurrentPinballGame->bossGrabDurationTimer >= 6)
        {
            varSL = (gCurrentPinballGame->bossGrabDurationTimer % 15) / 5 + 1;
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
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->bossGrabDurationTimer = gCurrentPinballGame->bossGrabDurationTimer - 30;
                if (gCurrentPinballGame->bossGrabDurationTimer < 5)
                    gCurrentPinballGame->bossGrabDurationTimer = 5;

                gCurrentPinballGame->bossFlipperEscapeTimer = 7;
                m4aSongNumStart(SE_UNKNOWN_0x11E);
            }

            if (gCurrentPinballGame->bossHitFlashTimer)
            {
                gCurrentPinballGame->bossHitFlashTimer--;
                if (gCurrentPinballGame->bossHitFlashTimer > 50)
                    varSL = 4;
                else if (gCurrentPinballGame->bossHitFlashTimer > 40)
                    varSL = 5;
            }
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->bossHitFlashTimer = 60;
            }
        }
        else
        {
            varSL = 4;
        }

        if (gCurrentPinballGame->bossGrabDurationTimer == 0)
        {
            gMain.spriteGroups[24].available = 0;
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
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B63AA[varSL][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        tempVector.x = gCurrentPinballGame->groudonFireballPosQ10.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
        tempVector.y = gCurrentPinballGame->groudonFireballPosQ10.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (gCurrentPinballGame->groudonFireballChaseTimer)
        {
            gCurrentPinballGame->groudonFireballChaseTimer--;
            if (gCurrentPinballGame->groudonFireballChaseTimer >= 10)
            {
                varSL = (gCurrentPinballGame->groudonFireballChaseTimer % 8) / 4 + gCurrentPinballGame->groudonAttackColumn * 2;
                if (squaredMagnitude <= 240 && gCurrentPinballGame->bonusCaptureState == 0 && gCurrentPinballGame->bossGrabDurationTimer < 600)
                {
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11f);
                    gCurrentPinballGame->groudonFireballChaseTimer = 10;
                    gMain.spriteGroups[24].available = 1;
                    gCurrentPinballGame->bossGrabDurationTimer = 612;
                    PlayRumble(9);
                }

                gCurrentPinballGame->groudonFireballPosQ10.x += (Cos(gCurrentPinballGame->groudonFireballAngle) *  40) / 20000;
                gCurrentPinballGame->groudonFireballPosQ10.y += (Sin(gCurrentPinballGame->groudonFireballAngle) * -40) / 20000;

            }
            else
            {
                varSL = (gCurrentPinballGame->groudonAttackColumn * 2) - ((gCurrentPinballGame->groudonFireballChaseTimer / 5) - 7);
                if (gCurrentPinballGame->groudonFireballChaseTimer == 9)
                {
                    if (squaredMagnitude <= 240)
                    {
                        gCurrentPinballGame->groudonFireballPosQ10.x = (gCurrentPinballGame->ball->positionQ0.x + 4) * 10;
                        gCurrentPinballGame->groudonFireballPosQ10.y = (gCurrentPinballGame->ball->positionQ0.y + 14) * 10;
                    }
                    else
                    {
                        if (gCurrentPinballGame->groudonAttackColumn == 0)
                        {
                            gCurrentPinballGame->groudonFireballPosQ10.x += 0;
                            gCurrentPinballGame->groudonFireballPosQ10.y += 240;
                        }
                        else if (gCurrentPinballGame->groudonAttackColumn == 1)
                        {
                            gCurrentPinballGame->groudonFireballPosQ10.x -= 120;
                            gCurrentPinballGame->groudonFireballPosQ10.y += 240;
                        }
                        else
                        {
                            gCurrentPinballGame->groudonFireballPosQ10.x += 120;
                            gCurrentPinballGame->groudonFireballPosQ10.y += 240;
                        }
                    }

                    m4aSongNumStart(SE_UNKNOWN_0x120);
                }
            }

            if (gCurrentPinballGame->groudonFireballChaseTimer == 0)
                gMain.spriteGroups[22].available = 0;
        }

        group->baseX = gCurrentPinballGame->groudonFireballPosQ10.x / 10 - gCurrentPinballGame->bgScrollXCopy - 12;
        group->baseY = gCurrentPinballGame->groudonFireballPosQ10.y / 10 - gCurrentPinballGame->bgScrollYWithOffset - 22;
        for (j = 0; j < 4; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B63F2[varSL][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->catchModeHitPhase == 2)
        {
            gMain.spriteGroups[22].available = 0;
            gCurrentPinballGame->groudonFireballChaseTimer = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        if (group->available)
        {
            switch (gCurrentPinballGame->fireRockPhase[i])
            {
            case 0:
                gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i];
                gCurrentPinballGame->fireRockLogicPosQ10[i].x = (((Random() % 101) * 145) / 100 + 30) * 10;
                gCurrentPinballGame->fireRockSpawnSlot[i] = Random() % 16;
                if (gCurrentPinballGame->fireRockSpawnSlot[i] == gCurrentPinballGame->fireRockSpawnSlot[(i + 1) % 3])
                    gCurrentPinballGame->fireRockSpawnSlot[i] = (gCurrentPinballGame->fireRockSpawnSlot[i] + 1) % 16;

                if (gCurrentPinballGame->fireRockSpawnSlot[i] == gCurrentPinballGame->fireRockSpawnSlot[(i + 2) % 3])
                    gCurrentPinballGame->fireRockSpawnSlot[i] = (gCurrentPinballGame->fireRockSpawnSlot[i] + 1) % 16;

                gCurrentPinballGame->fireRockLogicPosQ10[i].x = gUnknown_086AF34C[gCurrentPinballGame->fireRockSpawnSlot[i]][0] * 10;
                gCurrentPinballGame->fireRockLogicPosQ10[i].y = gUnknown_086AF34C[gCurrentPinballGame->fireRockSpawnSlot[i]][1] * 10;
                gCurrentPinballGame->fireRockAltitudeQ10[i] = -1200;
                gCurrentPinballGame->fireRockFallSpeed[i] = 0;
                gCurrentPinballGame->fireRockPhase[i] = 1;
                gCurrentPinballGame->fireRockCollisionPos[i].x = 0;
                gCurrentPinballGame->fireRockCollisionPos[i].y = 0;
                gCurrentPinballGame->fireRockBallHitFlag[i] = 0;
                break;
            case 1:
                if (gCurrentPinballGame->fireRockAltitudeQ10[i] < 0) {
                    gCurrentPinballGame->fireRockFallSpeed[i] += 3;
                    gCurrentPinballGame->fireRockAltitudeQ10[i] += gCurrentPinballGame->fireRockFallSpeed[i];
                    if (gCurrentPinballGame->fireRockAltitudeQ10[i] > 0) {
                        gCurrentPinballGame->fireRockAltitudeQ10[i] = 0;
                    }
                }

                if (gCurrentPinballGame->fireRockAltitudeQ10[i] >= 0)
                {
                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] == 0)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 5)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 1;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 10)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 2;
                    }
                    else
                    {
                        gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i];
                        gCurrentPinballGame->fireRockPhase[i] = 2;
                    }

                    gCurrentPinballGame->fireRockPhaseSubFrame[i]++;
                }

                gCurrentPinballGame->fireRockCollisionPos[i].x = 0;
                gCurrentPinballGame->fireRockCollisionPos[i].y = 0;
                break;
            case 2:
                gCurrentPinballGame->fireRockCollisionPos[i].x = (gCurrentPinballGame->fireRockLogicPosQ10[i].x / 10) * 2;
                gCurrentPinballGame->fireRockCollisionPos[i].y = (gCurrentPinballGame->fireRockLogicPosQ10[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->fireRockBallHitFlag[i])
                {
                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 5)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 3;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 10)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 4;
                    }
                    else
                    {
                        gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 5;
                        gCurrentPinballGame->fireRockPhase[i] = 3;
                        gCurrentPinballGame->fireRockBallHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->fireRockPhaseSubFrame[i]++;
                }
                break;
            case 3:
                gCurrentPinballGame->fireRockCollisionPos[i].x = (gCurrentPinballGame->fireRockLogicPosQ10[i].x / 10) * 2;
                gCurrentPinballGame->fireRockCollisionPos[i].y = (gCurrentPinballGame->fireRockLogicPosQ10[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->fireRockBallHitFlag[i])
                {
                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 5)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 6;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 10)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 7;
                    }
                    else
                    {
                        gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
                        gCurrentPinballGame->fireRockSpriteFrame[i] = gUnknown_086AF3AC[i] + 8;
                        gCurrentPinballGame->fireRockPhase[i] = 4;
                        gCurrentPinballGame->fireRockBallHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->fireRockPhaseSubFrame[i]++;
                }
                break;
            case 4:
                gCurrentPinballGame->fireRockCollisionPos[i].x = (gCurrentPinballGame->fireRockLogicPosQ10[i].x / 10) * 2;
                gCurrentPinballGame->fireRockCollisionPos[i].y = (gCurrentPinballGame->fireRockLogicPosQ10[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->fireRockBallHitFlag[i])
                {
                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 3)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = 9;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 8)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = 10;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 14)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = 11;
                    }
                    else if (gCurrentPinballGame->fireRockPhaseSubFrame[i] < 23)
                    {
                        gCurrentPinballGame->fireRockSpriteFrame[i] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
                        gCurrentPinballGame->fireRockSpriteFrame[i] = 12;
                        gCurrentPinballGame->fireRockPhase[i] = 5;
                        gCurrentPinballGame->fireRockBallHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->fireRockPhaseSubFrame[i]++;
                }
                break;
            case 5:
                gCurrentPinballGame->fireRockCollisionPos[i].x = 0;
                gCurrentPinballGame->fireRockCollisionPos[i].y = 0;
                gMain.spriteGroups[15 + i].available = 0;
                break;
            }

            var0 = gCurrentPinballGame->fireRockSpriteFrame[i];
            DmaCopy16(3, gUnknown_084A11EC[var0], (void *)0x06010FA0 + i * 0x300, 0x300);

            group->baseX = (gCurrentPinballGame->fireRockLogicPosQ10[i].x / 10) + i - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = (gCurrentPinballGame->fireRockAltitudeQ10[i] / 10) + (gCurrentPinballGame->fireRockLogicPosQ10[i].y / 10) - gCurrentPinballGame->bgScrollYWithOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->fireRockPhase[i] >= 2 && gCurrentPinballGame->fireRockPhase[i] < 5)
            {
                if (gUnknown_086AF34C[gCurrentPinballGame->fireRockSpawnSlot[i]][2] == gCurrentPinballGame->bossVortexScaleTimer)
                {
                    gCurrentPinballGame->fireRockPhase[i] = 4;
                    gCurrentPinballGame->fireRockBallHitFlag[i] = 1;
                    gCurrentPinballGame->fireRockPhaseSubFrame[i] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[18 + i];
        if (group->available)
        {
            switch(gCurrentPinballGame->rockAnimState[i])
            {
            case 0:
                gCurrentPinballGame->rockAnimLoopStart[i] = 0;
                gCurrentPinballGame->rockAnimEndFrame[i] = 8;
                gCurrentPinballGame->rockNextState[i] = 1;
                gCurrentPinballGame->rockAnimLoopCount[i] = 0;
                break;
            case 1:
                gCurrentPinballGame->rockAnimLoopStart[i] = 8;
                gCurrentPinballGame->rockAnimEndFrame[i] = 12;
                gCurrentPinballGame->rockNextState[i] = 3;
                gCurrentPinballGame->rockAnimLoopCount[i] = 14;
                gCurrentPinballGame->rockAnimState[i] = 2;
                break;
            case 2:
                if (gCurrentPinballGame->rockHitReactionTimer[i] > 0)
                {
                    gCurrentPinballGame->rockHitReactionTimer[i]--;
                    if (gCurrentPinballGame->rockHitReactionTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->rockAnimState[i] = 3;
                        PlayRumble(7);
                    }
                }
                break;
            case 3:
                gCurrentPinballGame->rockAnimLoopStart[i] = 12;
                gCurrentPinballGame->rockAnimEndFrame[i] = 16;
                gCurrentPinballGame->rockNextState[i] = 5;
                gCurrentPinballGame->rockAnimLoopCount[i] = 14;
                gCurrentPinballGame->rockAnimState[i] = 4;
                break;
            case 4:
                if (gCurrentPinballGame->rockHitReactionTimer[i] > 0)
                {
                    gCurrentPinballGame->rockHitReactionTimer[i]--;
                    if (gCurrentPinballGame->rockHitReactionTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->rockAnimState[i] = 5;
                        PlayRumble(7);
                    }
                }
                break;
            case 5:
                gCurrentPinballGame->rockAnimLoopStart[i] = 16;
                gCurrentPinballGame->rockAnimEndFrame[i] = 20;
                gCurrentPinballGame->rockNextState[i] = 7;
                gCurrentPinballGame->rockAnimLoopCount[i] = 14;
                gCurrentPinballGame->rockAnimState[i] = 6;
                break;
            case 6:
                if (gCurrentPinballGame->rockHitReactionTimer[i] > 0)
                {
                    gCurrentPinballGame->rockHitReactionTimer[i]--;
                    if (gCurrentPinballGame->rockHitReactionTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->rockAnimState[i] = 7;
                        PlayRumble(7);
                    }
                }
                break;
            case 7:
                gCurrentPinballGame->rockAnimLoopStart[i] = 20;
                gCurrentPinballGame->rockAnimEndFrame[i] = 24;
                gCurrentPinballGame->rockNextState[i] = 9;
                gCurrentPinballGame->rockAnimLoopCount[i] = 14;
                gCurrentPinballGame->rockAnimState[i] = 8;
                gCurrentPinballGame->rockDoubleHitCounter[i] = 0;
                break;
            case 8:
                if (gCurrentPinballGame->rockHitReactionTimer[i] > 0)
                {
                    gCurrentPinballGame->rockHitReactionTimer[i]--;
                    if (gCurrentPinballGame->rockHitReactionTimer[i] == 7)
                    {
                        if (gCurrentPinballGame->rockDoubleHitCounter[i] <= 0)
                        {
                            gCurrentPinballGame->rockDoubleHitCounter[i]++;
                        }
                        else
                        {
                            gCurrentPinballGame->rockDoubleHitCounter[i] = 0;
                            gCurrentPinballGame->rockAnimState[i] = 9;
                        }

                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        PlayRumble(7);
                    }
                }
                break;
            case 9:
                gCurrentPinballGame->rockAnimLoopStart[i] = 24;
                gCurrentPinballGame->rockAnimEndFrame[i] = 27;
                gCurrentPinballGame->rockNextState[i] = 10;
                gCurrentPinballGame->rockAnimLoopCount[i] = 0;
                break;
            case 10:
                gMain.spriteGroups[18 + i].available = 0;
                break;
            }

            if (gUnknown_086AF2DC[gCurrentPinballGame->rockAnimCurrentFrame[i]][1] > gCurrentPinballGame->rockFrameDelayCounter[i])
            {
                gCurrentPinballGame->rockFrameDelayCounter[i]++;
            }
            else
            {
                gCurrentPinballGame->rockFrameDelayCounter[i] = 0;
                gCurrentPinballGame->rockAnimCurrentFrame[i]++;
                if (gCurrentPinballGame->rockAnimCurrentFrame[i] == gCurrentPinballGame->rockAnimEndFrame[i])
                {
                    if (gCurrentPinballGame->rockAnimLoopCount[i] > 0)
                    {
                        gCurrentPinballGame->rockAnimCurrentFrame[i] = gCurrentPinballGame->rockAnimLoopStart[i];
                        gCurrentPinballGame->rockAnimLoopCount[i]--;
                    }
                    else
                    {
                        gCurrentPinballGame->rockAnimCurrentFrame[i] = gCurrentPinballGame->rockAnimEndFrame[i] - 1;
                        gCurrentPinballGame->rockAnimState[i] = gCurrentPinballGame->rockNextState[i];
                    }
                }
            }

            varSL = gUnknown_086AF2DC[gCurrentPinballGame->rockAnimCurrentFrame[i]][0];
            // Unsigned integers for matching
            group->baseX = gUnknown_086AF2CC[i].x + 65u - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = gUnknown_086AF2CC[i].y + 60u - gCurrentPinballGame->bgScrollYWithOffset;
            if (gCurrentPinballGame->rockAnimState[i] < 9)
            {
                gCurrentPinballGame->rockCollisionPos[i].x = (gUnknown_086AF2CC[i].x + 61) * 2;
                gCurrentPinballGame->rockCollisionPos[i].y = (gUnknown_086AF2CC[i].y + 96) * 2;
            }

            if (gCurrentPinballGame->rockHitReactionTimer[i] > 0)
            {
                for (j = 0; j < 10; j++)
                {
                    oamSimple = &group->oam[j];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    src = gUnknown_086B8AE0[varSL][j];
                    *dst++ = *src++;
                    *dst++ = *src++;
                    *dst++ = *src++;

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                    gOamBuffer[oamSimple->oamId].paletteNum = 2;
                }
            }
            else
            {
                for (j = 0; j < 10; j++)
                {
                    oamSimple = &group->oam[j];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    src = gUnknown_086B8AE0[varSL][j];
                    *dst++ = *src++;
                    *dst++ = *src++;
                    *dst++ = *src++;

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                    gOamBuffer[oamSimple->oamId].y += group->baseY;
                }
            }
        }
        else
        {
            gCurrentPinballGame->rockCollisionPos[i].x = 0;
            gCurrentPinballGame->rockCollisionPos[i].y = 0;
        }
    }

    if (gCurrentPinballGame->rockSpawnSequenceTimer)
    {
        gCurrentPinballGame->rockSpawnSequenceTimer--;
        if (gCurrentPinballGame->rockSpawnSequenceTimer == 36)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->rockSpawnSequenceTimer == 24)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->rockSpawnSequenceTimer == 12)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->rockSpawnSequenceTimer == 0)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);
    }

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        s16 scale;
        s16 var6;
        if (gCurrentPinballGame->bossVortexScaleTimer <= 35)
        {
            scale = (gCurrentPinballGame->bossVortexScaleTimer * 0x200) / 35 + 0x10;
            if (scale > 0x200)
                scale = 0x200;

            SetMatrixScale(scale, scale, 1);
            SetMatrixScale(-scale, scale, 2);
            SetMatrixScale(scale, -scale, 3);
            SetMatrixScale(-scale, -scale, 4);
            if (gCurrentPinballGame->bossVortexScaleTimer > 30)
                var6 = 12 - ((gCurrentPinballGame->bossVortexScaleTimer - 30) * 11) / 5;
            else
                var6 = 16 - (gCurrentPinballGame->bossVortexScaleTimer * 4) / 30;

            gCurrentPinballGame->bossVortexScaleTimer++;
        }
        else
        {
            scale = 0x100;
            var6 = 0;
            group->available = 0;
        }

        if (gCurrentPinballGame->bossVortexScaleTimer == 34)
        {
            for (i = 0; i < 4; i++)
            {
                gMain.spriteGroups[i + 18].available = 1;
                gCurrentPinballGame->rockAnimState[i] = 0;
                gCurrentPinballGame->rockAnimCurrentFrame[i] = 0;
                gCurrentPinballGame->rockFrameDelayCounter[i] = 0;
            }

            gCurrentPinballGame->rockSpawnSequenceTimer = 37;
        }

        gCurrentPinballGame->rockSpriteScaleOffset[0].x = 0x20 - scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[1].x = 0x20 + scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[2].x = 0x20 - scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[3].x = 0x20 + scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[0].y = 0x20 - scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[1].y = 0x20 - scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[2].y = 0x20 + scale / 8;
        gCurrentPinballGame->rockSpriteScaleOffset[3].y = 0x20 + scale / 8;

        if ((gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER) == 0)
        {
            gMain.blendControl = 0x1E10;
            gMain.blendAlpha = BLDALPHA_BLEND(var6, 16 - var6);
        }

        if (group->available)
        {
            group->baseX = 23 - gCurrentPinballGame->bgScrollXCopy;
            group->baseY = 50 - gCurrentPinballGame->bgScrollYWithOffset;
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->rockSpriteScaleOffset[j].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->rockSpriteScaleOffset[j].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + j;
            }
        }

        if (gCurrentPinballGame->bossVortexScaleTimer < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 147;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->bonusCaptureState == 0 && squaredMagnitude < gUnknown_086AEE20[gCurrentPinballGame->bossVortexScaleTimer])
            {
                gCurrentPinballGame->captureArcAngle = ArcTan2(-tempVector.x, tempVector.y);
                gCurrentPinballGame->ball->velocity.x = (Cos(gCurrentPinballGame->captureArcAngle) * -400) / 20000;
                gCurrentPinballGame->ball->velocity.y = (Sin(gCurrentPinballGame->captureArcAngle) *  400) / 20000;
                PlayRumble(9);
            }
        }

        if ((gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER) != 0)
            gMain.spriteGroups[30].available = 0;
    }
}

void HideGroudonShockwaveSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        group->baseX = 240;
        group->baseY = 160;
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }
}

void AnimateLavaBackground(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = gUnknown_086AF3B2[(gMain.systemFrameCount % 144) / 24];
    DmaCopy16(3, &gUnknown_08352BD8[var0 * 0x20], (void *)0x05000000, 0x20);
    DmaCopy16(3, &gUnknown_08352BD8[(var0 + 4) * 0x20], (void *)0x05000080, 0x20);

    var0 = gUnknown_086AF3BE[(gMain.systemFrameCount % 96) / 24];
    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[11 + i];
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 128 - gCurrentPinballGame->bgScrollYWithOffset;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gUnknown_086AF3C6[j] + var0 * 8;
        }
    }
}