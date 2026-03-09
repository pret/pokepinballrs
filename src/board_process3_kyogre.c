#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gUnknown_081B0DE4[][0x20];
extern const u16 gUnknown_08333004[];
extern const u8 gUnknown_0833FF58[][0x20];
extern const u8 gUnknown_083529D8[][0x20];
extern const u8 gUnknown_083C13AC[][0xC0];
extern const u8 gUnknown_083C1A6C[][0x3C0];
extern const u8 gUnknown_0849664C[][0x580];
extern const u8 gUnknown_0849B8CC[][0x4C0];
extern const u8 gUnknown_084FF90C[][0x200];
extern struct SongHeader se_unk_10a;
extern struct SongHeader se_unk_10b;
extern struct SongHeader se_unk_10c;
extern struct SongHeader se_unk_10d;
extern struct SongHeader se_unk_10e;
extern struct SongHeader se_unk_10f;
extern const u8 *gUnknown_086AEAE0[];
extern const u16 gUnknown_086AEAF8[][3];
extern const s16 gUnknown_086AEDA4[];
extern const s16 gUnknown_086AEDCC[];
extern const struct Vector16 gUnknown_086AEDE8[];
extern const s16 gUnknown_086AEE20[];
extern const s16 gUnknown_086AEE5E[][3];
extern const s16 gUnknown_086AEED6[];
extern const s16 gUnknown_086AEEDE[];
extern const s16 gUnknown_086AEEE6[];
extern const u16 gUnknown_086AEEFE[];
extern const s16 gUnknown_086AEF04[];
extern const u16 gUnknown_086B91AC[28][4][3];
extern const u16 gUnknown_086B92FC[66][10][3];


void KyogreBoardProcess_3A_383E4(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    gCurrentPinballGame->entityActivePhase = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->bossCryCountdown = 0;
    gCurrentPinballGame->bossHitPaletteState = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bossBgPaletteIndex = 0;
    gCurrentPinballGame->bonusCaptureState = 3;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;
    gCurrentPinballGame->bossFieldScrollQ10 = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->boardEntityCollisionMode = 0;
    gCurrentPinballGame->hatchRevealState = 3;
    gCurrentPinballGame->entitySpriteFrame = 14;
    gCurrentPinballGame->entityState = 0;
    gCurrentPinballGame->entityPosXQ10 = 0;
    gCurrentPinballGame->entityPosYQ10 = 0;
    gCurrentPinballGame->entityDirection = 0;
    gCurrentPinballGame->entityWalkCycleCount = 0;
    gCurrentPinballGame->entityAnimIndex = 0;
    gCurrentPinballGame->entityAnimTimer = 0;
    gCurrentPinballGame->kyogreWhirlpoolActive = 0;
    gCurrentPinballGame->kyogreBodyAnimState = 0;
    gCurrentPinballGame->kyogreBodyAnimEndFrame = 0;
    gCurrentPinballGame->kyogreBodyNextState = 0;
    gCurrentPinballGame->kyogreBodyAnimFrame = 0;
    gCurrentPinballGame->kyogreBodyLoopStartFrame = 0;
    gCurrentPinballGame->kyogreBodyLoopCount = 0;
    gCurrentPinballGame->kyogreRotationOffset = 0;
    gCurrentPinballGame->bossHitReactionTimer = 0;
    gCurrentPinballGame->bossAttackSubFrame = 0;
    gCurrentPinballGame->bossVortexScaleTimer = 0;
    gCurrentPinballGame->kyogreBgAnimFrame = 0;

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

    for (i = 0; i < 4; i ++)
    {
        gCurrentPinballGame->rockSpriteScaleOffset[i].x = 0;
        gCurrentPinballGame->rockSpriteScaleOffset[i].y = 0;
    }

    gCurrentPinballGame->fieldEntryInProgress = 1;
    UpdateKyogreStateMachine();
    RenderKyogreSprite();
    RenderKyogreAttackSprites();
    AnimateWaterBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_KYOGRE);
    DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    DmaCopy16(3, &gUnknown_086AEAE0[0][0], (void *)0x05000000, 0x100);
    DmaCopy16(3, gUnknown_081B36A4, (void *)0x05000320, 0x20);
}

void KyogreBoardProcess_3B_3869C(void)
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
            gCurrentPinballGame->bossBgPaletteIndex = (gCurrentPinballGame->stageTimer - 500) / 24;
            if (gCurrentPinballGame->bossBgPaletteIndex > 5)
                gCurrentPinballGame->bossBgPaletteIndex = 5;

            gCurrentPinballGame->stageTimer++;
            DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->bossBgPaletteIndex][0], (void *)0x05000000, 0x60);
            DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->bossBgPaletteIndex][0x80], (void *)0x05000080, 0x80);
            if (gCurrentPinballGame->fieldScrollOffsetY >= -32)
                gCurrentPinballGame->fieldEntryInProgress = 0;
        } else
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
            DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
        DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
    }

    RenderKyogreAttackSprites();
    UpdateKyogreStateMachine();
    RenderKyogreSprite();
    AnimateWaterBackground();
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

void UpdateKyogreStateMachine(void)
{
    s16 i;
    s16 index;

    if (gCurrentPinballGame->bossHitReactionTimer)
    {
        gCurrentPinballGame->bossHitReactionTimer--;
        if (gCurrentPinballGame->entityState != 8)
        {
            gCurrentPinballGame->bossHitPaletteState = 1;
            if (gCurrentPinballGame->bossHitReactionTimer == 4)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10a);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = 500000;
                gCurrentPinballGame->bonusModeHitCount++;
                if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired &&
                    gCurrentPinballGame->boardEntityCollisionMode == 1)
                    gCurrentPinballGame->entityState = 7;
            }
        }

        if (gCurrentPinballGame->bossHitReactionTimer == 0)
            gCurrentPinballGame->bossHitPaletteState = 0;
    }

    switch (gCurrentPinballGame->entityState)
    {
    case 0:
        gCurrentPinballGame->entityState = 1;
        gCurrentPinballGame->entityAnimIndex = 12;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityPosXQ10 = 0;
        gCurrentPinballGame->entityPosYQ10 = 0;
        gCurrentPinballGame->kyogreBgAnimFrame = 0;
        break;
    case 1:
        index = gUnknown_086AEDA4[(gCurrentPinballGame->kyogreBgAnimFrame % 280) / 14];
        DmaCopy16(3, gUnknown_081B0DE4[index], (void *)0x050003E0, 0x20);
        gCurrentPinballGame->kyogreBgAnimFrame++;
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 34)
            {
                gCurrentPinballGame->entityAnimIndex = 0;
                gCurrentPinballGame->entityState = 4;
                gCurrentPinballGame->entityReturnState = 6;
                gCurrentPinballGame->entitySubPhase = 0;
                gCurrentPinballGame->bossCryCountdown = 60;
                DmaCopy16(3, &gUnknown_081B0DE4[5], (void *)0x050003E0, 0x20);
            }

            if (gCurrentPinballGame->entityAnimIndex == 32)
                gCurrentPinballGame->entityActivePhase = 1;

            if (gCurrentPinballGame->entityAnimIndex == 33)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
                gCurrentPinballGame->boardEntityCollisionMode = 1;
            }
        }

        if (gCurrentPinballGame->bonusSequenceTimer > 2)
            gCurrentPinballGame->bonusSequenceTimer--;
        break;
    case 2:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 12)
            {
                gCurrentPinballGame->entityAnimIndex = 0;
                gCurrentPinballGame->entityState = 4;
                gCurrentPinballGame->entityReturnState = 6;
                gCurrentPinballGame->entitySubPhase = 2;
            }

            if (gCurrentPinballGame->entityAnimIndex == 11)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            }
        }
        break;
    case 3:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 8)
            {
                gCurrentPinballGame->entityAnimIndex = 8;
                gCurrentPinballGame->entityState = 11;
                gCurrentPinballGame->entitySubPhase = 0;
            }

            if (gCurrentPinballGame->entityAnimIndex == 5)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
            }
        }
        break;
    case 4:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 4)
            {
                if (gCurrentPinballGame->entitySubPhase < 3)
                {
                    gCurrentPinballGame->entityAnimIndex = 0;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    if (gCurrentPinballGame->entityReturnState == 3)
                    {
                        if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                        {
                            gCurrentPinballGame->entityAnimIndex = 0;
                            gCurrentPinballGame->entityState = 4;
                            gCurrentPinballGame->entitySubPhase = 0;
                            gCurrentPinballGame->entityReturnState = 6;
                        }
                        else
                        {
                            gCurrentPinballGame->entityAnimIndex = 4;
                            gCurrentPinballGame->entityState = gCurrentPinballGame->entityReturnState;
                        }
                    }
                    else
                    {
                        gCurrentPinballGame->entityAnimIndex = 34;
                        gCurrentPinballGame->entityState = gCurrentPinballGame->entityReturnState;
                        gCurrentPinballGame->kyogreWhirlpoolActive = 0;
                        gCurrentPinballGame->entitySubPhase = 0;
                    }
                }
            }
        }
        break;
    case 5:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 67)
            {
                if (gCurrentPinballGame->entitySubPhase <= 0)
                {
                    gCurrentPinballGame->entityAnimIndex = 45;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entityAnimIndex = 0;
                    gCurrentPinballGame->entityState = 4;
                    gCurrentPinballGame->entitySubPhase = 1;
                    gCurrentPinballGame->entityReturnState = 3;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 52)
            {
                gCurrentPinballGame->segmentAnimTimers[gCurrentPinballGame->entitySubPhase] = 0;
                gCurrentPinballGame->bossSegmentState[gCurrentPinballGame->entitySubPhase] = 1;
            }

            if (gCurrentPinballGame->entityAnimIndex == 50 || gCurrentPinballGame->entityAnimIndex == 56 || gCurrentPinballGame->entityAnimIndex == 62)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10d);
        }
        break;
    case 6:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 40)
            {
                if (gCurrentPinballGame->entitySubPhase <= 0)
                {
                    gCurrentPinballGame->entityAnimIndex = 34;
                    gCurrentPinballGame->entitySubPhase++;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 45)
            {
                gCurrentPinballGame->entityAnimIndex = 45;
                gCurrentPinballGame->entityState = 5;
                gCurrentPinballGame->entitySubPhase = 0;
            }

            if (gCurrentPinballGame->kyogreWhirlpoolActive == 0 && gCurrentPinballGame->entityAnimIndex == 42)
            {
                gMain.spriteGroups[24].available = 1;
                gCurrentPinballGame->bossVortexScaleTimer = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10e);
            }
        }

        if (gCurrentPinballGame->bossHitReactionTimer > 6)
            gCurrentPinballGame->kyogreWhirlpoolActive = 1;
        break;
    case 7:
        gCurrentPinballGame->entityActivePhase = 3;

        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch kyogre
            gCurrentPinballGame->entityState = 10;
            gCurrentPinballGame->entityAnimIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_KYOGRE;
            gCurrentPinballGame->bossFieldScrollQ10 = 0;
            gCurrentPinballGame->captureSequencePhase = 0;
            gCurrentPinballGame->entityCaptureTimer = 0;
            gCurrentPinballGame->catchModeHitPhase = 2;
        }
        else
        {
            // normal completion
            gCurrentPinballGame->entityState = 9;
            gCurrentPinballGame->entityAnimIndex = 79;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->bonusCaptureState = 2;
            gCurrentPinballGame->bonusSequenceTimer = 0;
        }

        if (gMain.spriteGroups[16].available)
        {
            gCurrentPinballGame->kyogreBodyAnimState = 7;
            gCurrentPinballGame->kyogreRotationOffset = 1;
        }

        gCurrentPinballGame->entityAnimTimer = 0;
        break;
    case 8:
        break;
    case 9:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 108)
            {
                gCurrentPinballGame->entityAnimIndex = 107;
                gCurrentPinballGame->entityState = 13;
                gCurrentPinballGame->boardState = 2;
                gCurrentPinballGame->stageTimer = 0;
            }

            if (gCurrentPinballGame->entityAnimIndex == 97)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10f);
            }
        }
        break;
    case 10:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 4)
                gCurrentPinballGame->entityAnimIndex = 0;
        }

        if (gCurrentPinballGame->bossFieldScrollQ10 > -500)
        {
            gCurrentPinballGame->bossFieldScrollQ10 += (-500 - gCurrentPinballGame->bossFieldScrollQ10) / 30;
            gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->bossFieldScrollQ10 / 10;
            if (gCurrentPinballGame->fieldScrollOffsetY < -50)
                gCurrentPinballGame->fieldScrollOffsetY = -50;
        }

        if (gCurrentPinballGame->captureSequencePhase == 21)
            gCurrentPinballGame->entityAnimIndex = 114;

        if (gCurrentPinballGame->captureSequencePhase == 22)
            gCurrentPinballGame->entityAnimIndex = 115;
        break;
    case 11:
        if (gCurrentPinballGame->entityAnimTimer < 300)
        {
            gCurrentPinballGame->entityAnimTimer++;
            if (gCurrentPinballGame->entityAnimTimer == 218)
            {
                gCurrentPinballGame->bossVortexScaleTimer = 0;
                gCurrentPinballGame->entityPosXQ10 = 500 - (Random() % 100) * 10;
                gCurrentPinballGame->entityPosYQ10 = 200 + (Random() % 100) * 4;
            }

            if (gCurrentPinballGame->entityAnimTimer == 260)
            {
                for (i = 0; i < 2; i++)
                {
                    if (gCurrentPinballGame->bossSegmentState[i] == 3)
                    {
                        gCurrentPinballGame->segmentAnimTimers[i] = 0;
                        gCurrentPinballGame->bossSegmentState[i] = 4;
                        gCurrentPinballGame->captureArcRadius /= 2;
                    }

                    if (gCurrentPinballGame->bossSegmentState[i] == 2)
                    {
                        gCurrentPinballGame->segmentAnimTimers[i] = 0;
                        gCurrentPinballGame->bossSegmentState[i] = 5;
                    }
                }
            }
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex = 67;
            gCurrentPinballGame->entityState = 12;
            gCurrentPinballGame->boardEntityCollisionMode = 2;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            PlayRumble(8);
        }
        break;
    case 12:
        if (gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;
            if (gCurrentPinballGame->entityAnimIndex == 79)
            {
                if (gCurrentPinballGame->entitySubPhase <= 0)
                {
                    gCurrentPinballGame->entityAnimIndex = 78;
                    gCurrentPinballGame->entityState = 11;
                    gCurrentPinballGame->entitySubPhase++;
                }
                else
                {
                    gCurrentPinballGame->entitySubPhase = 0;
                    gCurrentPinballGame->entityAnimIndex = 8;
                    gCurrentPinballGame->entityState = 2;
                    gCurrentPinballGame->entityPosXQ10 = 0;
                    gCurrentPinballGame->entityPosYQ10 = 0;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == 70)
                gCurrentPinballGame->boardEntityCollisionMode = 3;

            if (gCurrentPinballGame->entityAnimIndex == 73)
                gCurrentPinballGame->boardEntityCollisionMode = 0;

            if (gCurrentPinballGame->entityAnimIndex == 72)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
                PlayRumble(8);
            }
        }
        break;
    case 13:
        break;
    }

    if (gCurrentPinballGame->bossCryCountdown)
    {
        gCurrentPinballGame->bossCryCountdown--;
        if (gCurrentPinballGame->bossCryCountdown == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_KYOGRE].mainSeriesIndexNumber, 0);

        if (gCurrentPinballGame->bossCryCountdown == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderKyogreSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 var2;
    s16 index;
    s16 palette;

    group = &gMain.spriteGroups[21];
    if (group->available)
    {
        index = gCurrentPinballGame->entitySpriteFrame;
        gCurrentPinballGame->entitySpriteFrame = gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][2];
        var2 = gUnknown_086AEAF8[gCurrentPinballGame->entityAnimIndex][0];
        if (index < 15)
        {
            DmaCopy16(3, gUnknown_0849664C[index], (void *)0x06010FA0, 0x580);
        }
        else
        {
            index -= 15;
            DmaCopy16(3, gUnknown_0849B8CC[index], (void *)0x06010FA0, 0x4C0);
        }

        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + 72u - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 + 66u - gCurrentPinballGame->bgScrollYWithOffset;
        gCurrentPinballGame->entityCenterX = gCurrentPinballGame->entityPosXQ10 / 10 + 120;
        gCurrentPinballGame->entityCenterY = gCurrentPinballGame->entityPosYQ10 / 10 + 50;
        if (gCurrentPinballGame->boardEntityCollisionMode == 2)
        {
            gCurrentPinballGame->entityCollisionOriginX = (gCurrentPinballGame->entityPosXQ10 / 10) * 2 + 192;
            gCurrentPinballGame->entityCollisionOriginY = (gCurrentPinballGame->entityPosYQ10 / 10) * 2 + 134;
        }
        else if (gCurrentPinballGame->boardEntityCollisionMode == 3)
        {
            gCurrentPinballGame->entityCollisionOriginX = (gCurrentPinballGame->entityPosXQ10 / 10) * 2 + 192;
            gCurrentPinballGame->entityCollisionOriginY = (gCurrentPinballGame->entityPosYQ10 / 10) * 2 + 150;
        }
        else
        {
            gCurrentPinballGame->entityCollisionOriginX = (gCurrentPinballGame->entityPosXQ10 / 10) * 2 + 180;
            gCurrentPinballGame->entityCollisionOriginY = (gCurrentPinballGame->entityPosYQ10 / 10) * 2 + 116;
        }

        if (gCurrentPinballGame->bossHitPaletteState > 9)
        {
            palette = 11;
            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else
        {
            if (gCurrentPinballGame->bossHitPaletteState == 1)
                palette = 14;
            else if (gCurrentPinballGame->bossHitPaletteState == 3)
                palette = 11;
            else if (var2 == 20)
                palette = 4;
            else if (var2 == 21)
                palette = 3;
            else
                palette = 15;

            for (i = 0; i < 10; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gUnknown_086B92FC[var2][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
    }

    group = &gMain.spriteGroups[26];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + 108 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = gCurrentPinballGame->entityPosYQ10 / 10 +  82 - gCurrentPinballGame->bgScrollYWithOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gUnknown_086AEDCC[(gCurrentPinballGame->bossVortexScaleTimer % 84) / 6];
        DmaCopy16(3, gUnknown_083C13AC[index], (void *)0x06012420, 0xC0);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->bossVortexScaleTimer < 83)
        {
            gCurrentPinballGame->bossVortexScaleTimer++;
        }
        else
        {
            gCurrentPinballGame->bossVortexScaleTimer = 0;
            gMain.spriteGroups[26].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->entityState == 11 && gCurrentPinballGame->entityAnimTimer == 218)
            group->available = 1;
    }
}

void RenderKyogreAttackSprites(void)
{
    s16 i, j;
    s16 var4;
    int var5;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    s16 index;
    int xx, yy;
    u16 angle;
    int squaredMagnitude;
    struct Vector32 tempVector2;
    struct Vector32 tempVector;
    struct Vector32 tempVector3;

    index = 0;
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

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
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

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->spriteLayerPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[16];
    if (group->available)
    {
        switch (gCurrentPinballGame->kyogreBodyAnimState)
        {
        case 0:
            gCurrentPinballGame->kyogreBodyLoopStartFrame = 0;
            gCurrentPinballGame->kyogreBodyAnimEndFrame = 5;
            gCurrentPinballGame->kyogreBodyNextState = 1;
            gCurrentPinballGame->kyogreBodyLoopCount = 0;
            gCurrentPinballGame->kyogreRotationOffset = 0;
            if (gCurrentPinballGame->kyogreBodyAnimFrame == 2)
            {
                int a; // force addition of 8 instead of offsetting the global constant
                DmaCopy16(3, &gUnknown_08137E14[a = gCurrentPinballGame->ballUpgradeType + 8], (void *)0x05000220, 0x20);
            }
            break;
        case 1:
            gCurrentPinballGame->kyogreBodyLoopCount = 4;
            gCurrentPinballGame->kyogreRotationOffset = 90;
            gCurrentPinballGame->kyogreBodyAnimState = 2;
            break;
        case 2:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->kyogreRotationOffset -= 90;
                if (gCurrentPinballGame->kyogreRotationOffset < 0)
                    gCurrentPinballGame->kyogreRotationOffset = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->kyogreBodyLoopStartFrame = 5;
            gCurrentPinballGame->kyogreBodyAnimEndFrame = 9;
            gCurrentPinballGame->kyogreBodyNextState = 3;
            break;
        case 3:
            gCurrentPinballGame->kyogreBodyLoopCount = 4;
            gCurrentPinballGame->kyogreRotationOffset = 90;
            gCurrentPinballGame->kyogreBodyAnimState = 4;
            break;
        case 4:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->kyogreRotationOffset -= 90;
                if (gCurrentPinballGame->kyogreRotationOffset < 0)
                    gCurrentPinballGame->kyogreRotationOffset = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->kyogreBodyLoopStartFrame = 9;
            gCurrentPinballGame->kyogreBodyAnimEndFrame = 13;
            gCurrentPinballGame->kyogreBodyNextState = 5;
            break;
        case 5:
            gCurrentPinballGame->kyogreBodyLoopCount = 0;
            gCurrentPinballGame->kyogreRotationOffset = 90;
            gCurrentPinballGame->kyogreBodyAnimState = 6;
            break;
        case 6:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->kyogreRotationOffset -= 90;
                if (gCurrentPinballGame->kyogreRotationOffset < 0)
                    gCurrentPinballGame->kyogreRotationOffset = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->kyogreBodyLoopStartFrame = 13;
            gCurrentPinballGame->kyogreBodyAnimEndFrame = 19;
            gCurrentPinballGame->kyogreBodyNextState = 7;
            break;
        case 7:
            gMain.spriteGroups[16].available = 0;
            break;
        }

        if (gCurrentPinballGame->kyogreRotationOffset > 0)
        {
            gCurrentPinballGame->kyogreRotationOffset--;
            if (gCurrentPinballGame->kyogreRotationOffset == 0)
                m4aSongNumStart(SE_UNKNOWN_0x111);
        }
        else
        {
            if (gUnknown_086AEE5E[gCurrentPinballGame->kyogreBodyAnimFrame][1] > gCurrentPinballGame->bossAttackSubFrame)
            {
                gCurrentPinballGame->bossAttackSubFrame++;
            }
            else
            {
                gCurrentPinballGame->bossAttackSubFrame = 0;
                gCurrentPinballGame->kyogreBodyAnimFrame++;
                if (gCurrentPinballGame->kyogreBodyAnimFrame == gCurrentPinballGame->kyogreBodyAnimEndFrame)
                {
                    if (gCurrentPinballGame->kyogreBodyLoopCount > 0)
                    {
                        gCurrentPinballGame->kyogreBodyAnimFrame = gCurrentPinballGame->kyogreBodyLoopStartFrame;
                        gCurrentPinballGame->kyogreBodyLoopCount--;
                    }
                    else
                    {
                        gCurrentPinballGame->kyogreBodyAnimFrame = gCurrentPinballGame->kyogreBodyAnimEndFrame - 1;
                        gCurrentPinballGame->kyogreBodyAnimState = gCurrentPinballGame->kyogreBodyNextState;
                    }

                    gCurrentPinballGame->kyogreRotationOffset = 90;
                }

                if (gCurrentPinballGame->kyogreBodyAnimFrame == 1)
                    m4aSongNumStart(SE_UNKNOWN_0x110);

                if (gCurrentPinballGame->kyogreBodyAnimFrame == 15)
                {
                    DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
                    m4aSongNumStart(SE_UNKNOWN_0x112);
                }
            }
        }

        if (gCurrentPinballGame->kyogreBodyAnimFrame < 18)
        {
            gCurrentPinballGame->bossGrabbedBall = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spin = 0;
        }
        else
        {
            gCurrentPinballGame->bossGrabbedBall = 0;
        }

        group->baseX = gCurrentPinballGame->ball->screenPosition.x;
        group->baseY = gCurrentPinballGame->ball->screenPosition.y;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gUnknown_086AEE5E[gCurrentPinballGame->kyogreBodyAnimFrame][2];
        DmaCopy16(3, gUnknown_083C1A6C[index], (void *)0x060124E0, 0x3C0);
        var0 = gUnknown_086AEE5E[gCurrentPinballGame->kyogreBodyAnimFrame][0];
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gUnknown_086B91AC[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[22 + i];
        if ((gMain.modeChangeFlags & MODE_CHANGE_BONUS_BANNER) == 0)
        {
            switch (gCurrentPinballGame->bossSegmentState[i]) {
            case 0:
                index = 0;
                gCurrentPinballGame->legendarySegmentPos[i].x = 0;
                gCurrentPinballGame->legendarySegmentPos[i].y = 0;
                break;
            case 1:
                index = gCurrentPinballGame->segmentAnimTimers[i] / 9;
                if (gCurrentPinballGame->segmentAnimTimers[i] < 98)
                {
                    gCurrentPinballGame->segmentAnimTimers[i]++;
                }
                else
                {
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 2;
                    gCurrentPinballGame->segmentMoveTargetIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->segmentTargetPos[i].x = gUnknown_086AEDE8[gCurrentPinballGame->segmentMoveTargetIndex[i]].x;
                    gCurrentPinballGame->segmentTargetPos[i].y = gUnknown_086AEDE8[gCurrentPinballGame->segmentMoveTargetIndex[i]].y;
                }

                gCurrentPinballGame->legendarySegmentPos[i].x = 0;
                gCurrentPinballGame->legendarySegmentPos[i].y = 0;
                break;
            case 2:
                index = ((gCurrentPinballGame->segmentAnimTimers[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->bossSegmentState[0] < 3 && gCurrentPinballGame->bossSegmentState[1] < 3)
                {
                    int xoff = 120;
                    int yoff = 144;
                    tempVector.x = (gCurrentPinballGame->ball->positionQ0.x - xoff) - (gCurrentPinballGame->legendarySegmentPos[i].x / 10);
                    tempVector.y = (gCurrentPinballGame->ball->positionQ0.y - yoff) - (gCurrentPinballGame->legendarySegmentPos[i].y / 10);
                    xx = tempVector.x * tempVector.x;
                    yy = tempVector.y * tempVector.y;
                    squaredMagnitude = xx + yy;
                    if (gCurrentPinballGame->bossGrabbedBall == 0 && gCurrentPinballGame->bonusCaptureState == 0 &&
                        gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired &&
                        gCurrentPinballGame->bossHitReactionTimer == 0 && squaredMagnitude < 400)
                    {
                        m4aSongNumStart(SE_UNKNOWN_0x113);
                        PlayRumble(12);
                        gCurrentPinballGame->ballLockState = 1;
                        gCurrentPinballGame->segmentAnimTimers[i] = 0;
                        gCurrentPinballGame->bossSegmentState[i] = 3;
                        gCurrentPinballGame->bossActive = 1;
                        tempVector2.x = gCurrentPinballGame->legendarySegmentPos[i].x / 10 + 120;
                        tempVector2.y = gCurrentPinballGame->legendarySegmentPos[i].y / 10 + 144;
                        tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                        tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                        gCurrentPinballGame->captureArcRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                        gCurrentPinballGame->captureArcRadius = Sqrt(gCurrentPinballGame->captureArcRadius * 4) / 2;
                        gCurrentPinballGame->captureArcAngle = ArcTan2(-tempVector.x, tempVector.y);
                    }
                }

                if (gCurrentPinballGame->segmentAnimTimers[i] < 900)
                {
                    gCurrentPinballGame->segmentAnimTimers[i]++;
                }
                else
                {
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 5;
                }
                break;
            case 3:
                index = ((gCurrentPinballGame->segmentAnimTimers[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                    gCurrentPinballGame->segmentAnimTimers[i] += 8;

                var4 = 29 - gCurrentPinballGame->segmentAnimTimers[i];
                if (var4 < 10)
                    var4 = 10;

                gCurrentPinballGame->captureArcAngle -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
                gCurrentPinballGame->ball->rotation -= 0x2000;
                var5 = (gCurrentPinballGame->captureArcRadius * var4) / 30;
                tempVector2.x = gCurrentPinballGame->legendarySegmentPos[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->legendarySegmentPos[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->segmentAnimTimers[i] < 480)
                {
                    gCurrentPinballGame->segmentAnimTimers[i]++;
                    if (gCurrentPinballGame->segmentAnimTimers[i] % 9 == 0)
                        PlayRumble(12);
                }
                else
                {
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 4;
                    gCurrentPinballGame->captureArcRadius /= 2;
                }
                break;
            case 4:
                index = 5 - gCurrentPinballGame->segmentAnimTimers[i] / 8;
                var4 = 47 - gCurrentPinballGame->segmentAnimTimers[i];
                gCurrentPinballGame->captureArcAngle -= ((0x2000 - (var4 * 0x1000) / 47) * 2) / 5;
                gCurrentPinballGame->ball->rotation -= 0x2000;
                var5 = (gCurrentPinballGame->captureArcRadius * var4) / 47;
                tempVector2.x = gCurrentPinballGame->legendarySegmentPos[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->legendarySegmentPos[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->captureArcAngle) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->segmentAnimTimers[i] < 47)
                {
                    gCurrentPinballGame->segmentAnimTimers[i]++;
                }
                else
                {
                    gCurrentPinballGame->segmentAnimTimers[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = -150 + (gMain.systemFrameCount % 2) * 300;
                    gCurrentPinballGame->ball->velocity.y = 300;
                    gCurrentPinballGame->ballLockState = 0;
                    gCurrentPinballGame->bossSegmentState[i] = 0;
                    gCurrentPinballGame->bossActive = 0;
                }
                break;
            case 5:
                index = 5 - gCurrentPinballGame->segmentAnimTimers[i] / 6;
                if (gCurrentPinballGame->segmentAnimTimers[i] < 36)
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

            if (gCurrentPinballGame->bossSegmentState[i] >= 2 && gCurrentPinballGame->bossSegmentState[i] < 4)
            {
                tempVector.x = gCurrentPinballGame->segmentTargetPos[i].x - gCurrentPinballGame->legendarySegmentPos[i].x;
                tempVector.y = gCurrentPinballGame->segmentTargetPos[i].y - gCurrentPinballGame->legendarySegmentPos[i].y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                angle = ArcTan2(tempVector.x, -tempVector.y);
                tempVector3.x =  (Cos(angle) * 4) / 20000;
                tempVector3.y = -(Sin(angle) * 4) / 20000;
                gCurrentPinballGame->legendarySegmentPos[i].x += tempVector3.x;
                gCurrentPinballGame->legendarySegmentPos[i].y += tempVector3.y;
                if (squaredMagnitude < 2500)
                {
                    gCurrentPinballGame->segmentMoveTargetIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->segmentTargetPos[i].x = gUnknown_086AEDE8[gCurrentPinballGame->segmentMoveTargetIndex[i]].x;
                    gCurrentPinballGame->segmentTargetPos[i].y = gUnknown_086AEDE8[gCurrentPinballGame->segmentMoveTargetIndex[i]].y;
                }
            }
        }

        DmaCopy16(3, gUnknown_084FF90C[index], (void *)0x06011520 + i * 0x200, 0x200);
        if (group->available)
        {
            if (gCurrentPinballGame->bossSegmentState[i] > 0)
            {
                group->baseX = gCurrentPinballGame->legendarySegmentPos[i].x / 10 - (gCurrentPinballGame->bgScrollXCopy - 104u);
                group->baseY = gCurrentPinballGame->legendarySegmentPos[i].y / 10 - (gCurrentPinballGame->bgScrollYWithOffset - 128u);
            }
            else
            {
                group->baseX = 240;
                group->baseY = 180;
            }

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        s16 scale;
        s16 var6;

        if (gCurrentPinballGame->bossVortexScaleTimer < 36)
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
            group->baseY = 30 - gCurrentPinballGame->bgScrollYWithOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->rockSpriteScaleOffset[i].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->rockSpriteScaleOffset[i].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + i;
            }
        }

        if (gCurrentPinballGame->bossVortexScaleTimer < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 127;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->bonusCaptureState == 0 && squaredMagnitude < gUnknown_086AEE20[gCurrentPinballGame->bossVortexScaleTimer])
            {
                gCurrentPinballGame->kyogreBodyAnimState = 0;
                gCurrentPinballGame->kyogreBodyAnimFrame = 0;
                gCurrentPinballGame->bossAttackSubFrame = 0;
                if (!gMain.spriteGroups[16].available)
                    PlayRumble(8);

                gMain.spriteGroups[16].available = 1;
            }
        }

        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER)
            gMain.spriteGroups[24].available = 0;
    }
}

void HideKyogreShockwaveSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[24];
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

void AnimateWaterBackground(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 index;

    if (gCurrentPinballGame->boardState == 0 && gCurrentPinballGame->stageTimer < 600)
    {
        index = gUnknown_086AEF04[(gCurrentPinballGame->stageTimer % 240) / 24];
        DmaCopy16(3, gUnknown_083529D8[index], (void *)0x05000340, 0x20);
        DmaCopy16(3, gUnknown_0833FF58[index], (void *)0x050002A0, 0x20);
        var0 = 2;
        index = 0;
        gCurrentPinballGame->kyogreWaterAnimFrame = index;
    }
    else
    {
        var0 = gUnknown_086AEEE6[(gCurrentPinballGame->kyogreWaterAnimFrame % 96) / 24];
        gCurrentPinballGame->kyogreWaterAnimFrame++;
    }

    index = gUnknown_086AEED6[(gCurrentPinballGame->gameFrameCount % 96) / 24];
    for (i = 0; i < 0x400; i++)
        gBgScreenBuffer[0x800 + i] = gUnknown_08333004[i] + index * 4;

    DmaCopy16(3, &gBgScreenBuffer[0x800], (void *)0x06000000, 0x800);
    index = gUnknown_086AEEDE[(gMain.systemFrameCount % 96) / 24];
    DmaCopy16(3, &gUnknown_086AEAE0[gCurrentPinballGame->bossBgPaletteIndex][index * 0x20], (void *)0x05000060, 0x20);

    for (j = 0; j < 4; j++)
    {
        group = &gMain.spriteGroups[11 + j];
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 128 - gCurrentPinballGame->bgScrollYWithOffset;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gUnknown_086AEEFE[i] + var0 * 8;
        }
    }

    group = &gMain.spriteGroups[15];
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->bgScrollXCopy;
        group->baseY = 128 - gCurrentPinballGame->bgScrollYWithOffset;
        for (i = 0; i < 8; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->stageTimer == 480)
            gMain.spriteGroups[15].available = 0;
    }
}
