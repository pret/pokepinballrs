#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const u8 gKyogreBonusClear_Gfx[];
extern const u8 gKyogreWaterAnimPaletteFrames[][0x20];
extern const u16 gKyogreWaterBackgroundTilemap[];
extern const u8 gKyogreIntroShorePalette[][0x20];
extern const u8 gKyogreIntroIcePalette[][0x20];
extern const u8 gKyogreSplashSpriteFrames[][0xC0];
extern const u8 gKyogreWhirlpoolSpriteFrames[][0x3C0];
extern const u8 gKyogreBodySprites_First15[][0x580];
extern const u8 gKyogreBodySprites_After15[][0x4C0];
extern const u8 gKyogreWhirlpoolMinionSprites[][0x200];
extern struct SongHeader se_unk_10a;
extern struct SongHeader se_unk_10b;
extern struct SongHeader se_unk_10c;
extern struct SongHeader se_unk_10d;
extern struct SongHeader se_unk_10e;
extern struct SongHeader se_unk_10f;
extern const u8 *gKyogreFadeInPaletteProgression[];
extern const u16 gKyogreAnimFramesetTable[][3];
extern const s16 gKyogreRisingPaletteCycleIndices[];
extern const s16 gKyogreSplashAnimIndices[];
extern const struct Vector16 gKyogreWhirlpoolTargetPositions[];
extern const s16 gShockwaveSplashDistanceThresholds[];
extern const s16 gKyogreWhirlpoolTrapAnimFrameset[][3];
extern const s16 gWaterTilePaletteCycle[];
extern const s16 gKyogreWaterPaletteSegmentCycle[];
extern const s16 gKyogreBgTileVariantCycle[];
extern const u16 gKyogreBgSpriteBaseTileNums[];
extern const s16 gKyogreIntroPaletteCycleIndices[];
extern const u16 gKyogreWhirlpoolTrapOamData[28][4][3];
extern const u16 gKyogreMainBodyOamData[66][10][3];


void KyogreBoardProcess_3A_383E4(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = 0;
    gCurrentPinballGame->boardModeType = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->ballGrabbed = 0;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballRespawnState = 3;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = 1;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->boardEntityCollisionMode = 0;
    gCurrentPinballGame->portraitDisplayState = 3;
    gCurrentPinballGame->bossVulnerable = 14;
    gCurrentPinballGame->bossEntityState = 0;
    gCurrentPinballGame->bossPositionX = 0;
    gCurrentPinballGame->bossPositionY = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->shockwaveAlreadyHit = 0;
    gCurrentPinballGame->whirlpoolTrapPhase = 0;
    gCurrentPinballGame->whirlpoolTrapAnimEndFrame = 0;
    gCurrentPinballGame->whirlpoolTrapNextPhase = 0;
    gCurrentPinballGame->whirlpoolTrapAnimFrame = 0;
    gCurrentPinballGame->whirlpoolTrapAnimLoopStart = 0;
    gCurrentPinballGame->whirlpoolTrapLoopCount = 0;
    gCurrentPinballGame->whirlpoolTrapPauseTimer = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;
    gCurrentPinballGame->whirlpoolTrapFrameTimer = 0;
    gCurrentPinballGame->shockwaveAnimTimer = 0;
    gCurrentPinballGame->kyogreWaveTimer = 0;

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->orbEntityState[i] = 0;
        gCurrentPinballGame->orbTargetWaypointIndex[i] = 0;
        gCurrentPinballGame->orbAnimTimer[i] = 0;
        gCurrentPinballGame->orbScreenPosition[i].x = 0;
        gCurrentPinballGame->orbScreenPosition[i].y = 0;
        gCurrentPinballGame->orbOrbitCenter[i].x = 0;
        gCurrentPinballGame->orbOrbitCenter[i].y = 0;
    }

    for (i = 0; i < 4; i ++)
    {
        gCurrentPinballGame->shockwaveQuadrantOffset[i].x = 0;
        gCurrentPinballGame->shockwaveQuadrantOffset[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = 1;
    UpdateKyogreEntityLogic();
    RenderKyogreSprites();
    UpdateKyogreFieldEntities();
    AnimateKyogreBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_KYOGRE);
    DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
    DmaCopy16(3, &gKyogreFadeInPaletteProgression[0][0], (void *)0x05000000, 0x100);
    DmaCopy16(3, gBonusStageObjPal, (void *)0x05000320, 0x20);
}

void KyogreBoardProcess_3B_3869C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
        if (gCurrentPinballGame->stageTimer < 500)
        {
            gCurrentPinballGame->cameraYAdjust = -64;
            gCurrentPinballGame->stageTimer++;
        }
        else if (gCurrentPinballGame->stageTimer < 820)
        {
            gCurrentPinballGame->cameraYAdjust = (gCurrentPinballGame->stageTimer - 500) / 5 - 64;
            gCurrentPinballGame->bossLightFadeInCounter = (gCurrentPinballGame->stageTimer - 500) / 24;
            if (gCurrentPinballGame->bossLightFadeInCounter > 5)
                gCurrentPinballGame->bossLightFadeInCounter = 5;

            gCurrentPinballGame->stageTimer++;
            DmaCopy16(3, &gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][0], (void *)0x05000000, 0x60);
            DmaCopy16(3, &gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][0x80], (void *)0x05000080, 0x80);
            if (gCurrentPinballGame->cameraYAdjust >= -32)
                gCurrentPinballGame->flippersDisabled = 0;
        } else
        {
            gCurrentPinballGame->cameraYAdjust = 0;
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
            gCurrentPinballGame->bannerSlideYOffset = 136;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->boardEntityActive = 1;
        }
        break;
    case 3:
        ProcessBonusBannerAndScoring();
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

        gCurrentPinballGame->boardEntityActive = 1;
        break;
    case 4:
        gCurrentPinballGame->boardState = 5;
        gCurrentPinballGame->stageTimer = 140;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->bannerSlideYOffset = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        break;
    case 5:
        ProcessBonusBannerAndScoring();
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
        ProcessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->boardEntityActive = 1;
    }

    UpdateKyogreFieldEntities();
    UpdateKyogreEntityLogic();
    RenderKyogreSprites();
    AnimateKyogreBackground();
    if (gCurrentPinballGame->boardModeType && gCurrentPinballGame->eventTimer < 2 && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->boardEntityActive = 1;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void UpdateKyogreEntityLogic(void)
{
    s16 i;
    s16 index;

    if (gCurrentPinballGame->bossHitFlashTimer)
    {
        gCurrentPinballGame->bossHitFlashTimer--;
        if (gCurrentPinballGame->bossEntityState != 8)
        {
            gCurrentPinballGame->legendaryFlashState = 1;
            if (gCurrentPinballGame->bossHitFlashTimer == 4)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10a);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = 500000;
                gCurrentPinballGame->bonusModeHitCount++;
                if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired &&
                    gCurrentPinballGame->boardEntityCollisionMode == 1)
                    gCurrentPinballGame->bossEntityState = 7;
            }
        }

        if (gCurrentPinballGame->bossHitFlashTimer == 0)
            gCurrentPinballGame->legendaryFlashState = 0;
    }

    switch (gCurrentPinballGame->bossEntityState)
    {
    case 0:
        gCurrentPinballGame->bossEntityState = 1;
        gCurrentPinballGame->bossFramesetIndex = 12;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossPositionX = 0;
        gCurrentPinballGame->bossPositionY = 0;
        gCurrentPinballGame->kyogreWaveTimer = 0;
        break;
    case 1:
        index = gKyogreRisingPaletteCycleIndices[(gCurrentPinballGame->kyogreWaveTimer % 280) / 14];
        DmaCopy16(3, gKyogreWaterAnimPaletteFrames[index], (void *)0x050003E0, 0x20);
        gCurrentPinballGame->kyogreWaveTimer++;
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 34)
            {
                gCurrentPinballGame->bossFramesetIndex = 0;
                gCurrentPinballGame->bossEntityState = 4;
                gCurrentPinballGame->bossAttackPhase = 6;
                gCurrentPinballGame->bossMovementPhase = 0;
                gCurrentPinballGame->bossRoarTimer = 60;
                DmaCopy16(3, &gKyogreWaterAnimPaletteFrames[5], (void *)0x050003E0, 0x20);
            }

            if (gCurrentPinballGame->bossFramesetIndex == 32)
                gCurrentPinballGame->boardModeType = 1;

            if (gCurrentPinballGame->bossFramesetIndex == 33)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
                gCurrentPinballGame->boardEntityCollisionMode = 1;
            }
        }

        if (gCurrentPinballGame->ballRespawnTimer > 2)
            gCurrentPinballGame->ballRespawnTimer--;
        break;
    case 2:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 12)
            {
                gCurrentPinballGame->bossFramesetIndex = 0;
                gCurrentPinballGame->bossEntityState = 4;
                gCurrentPinballGame->bossAttackPhase = 6;
                gCurrentPinballGame->bossMovementPhase = 2;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 11)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 1;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            }
        }
        break;
    case 3:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 8)
            {
                gCurrentPinballGame->bossFramesetIndex = 8;
                gCurrentPinballGame->bossEntityState = 11;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 5)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
            }
        }
        break;
    case 4:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 4)
            {
                if (gCurrentPinballGame->bossMovementPhase < 3)
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    if (gCurrentPinballGame->bossAttackPhase == 3)
                    {
                        if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                        {
                            gCurrentPinballGame->bossFramesetIndex = 0;
                            gCurrentPinballGame->bossEntityState = 4;
                            gCurrentPinballGame->bossMovementPhase = 0;
                            gCurrentPinballGame->bossAttackPhase = 6;
                        }
                        else
                        {
                            gCurrentPinballGame->bossFramesetIndex = 4;
                            gCurrentPinballGame->bossEntityState = gCurrentPinballGame->bossAttackPhase;
                        }
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 34;
                        gCurrentPinballGame->bossEntityState = gCurrentPinballGame->bossAttackPhase;
                        gCurrentPinballGame->shockwaveAlreadyHit = 0;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
            }
        }
        break;
    case 5:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 67)
            {
                if (gCurrentPinballGame->bossMovementPhase <= 0)
                {
                    gCurrentPinballGame->bossFramesetIndex = 45;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossEntityState = 4;
                    gCurrentPinballGame->bossMovementPhase = 1;
                    gCurrentPinballGame->bossAttackPhase = 3;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 52)
            {
                gCurrentPinballGame->orbAnimTimer[gCurrentPinballGame->bossMovementPhase] = 0;
                gCurrentPinballGame->orbEntityState[gCurrentPinballGame->bossMovementPhase] = 1;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 50 || gCurrentPinballGame->bossFramesetIndex == 56 || gCurrentPinballGame->bossFramesetIndex == 62)
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10d);
        }
        break;
    case 6:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 40)
            {
                if (gCurrentPinballGame->bossMovementPhase <= 0)
                {
                    gCurrentPinballGame->bossFramesetIndex = 34;
                    gCurrentPinballGame->bossMovementPhase++;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 45)
            {
                gCurrentPinballGame->bossFramesetIndex = 45;
                gCurrentPinballGame->bossEntityState = 5;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

            if (gCurrentPinballGame->shockwaveAlreadyHit == 0 && gCurrentPinballGame->bossFramesetIndex == 42)
            {
                gMain.spriteGroups[24].available = 1;
                gCurrentPinballGame->shockwaveAnimTimer = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10e);
            }
        }

        if (gCurrentPinballGame->bossHitFlashTimer > 6)
            gCurrentPinballGame->shockwaveAlreadyHit = 1;
        break;
    case 7:
        gCurrentPinballGame->boardModeType = 3;

        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch kyogre
            gCurrentPinballGame->bossEntityState = 10;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_KYOGRE;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = 2;
        }
        else
        {
            // normal completion
            gCurrentPinballGame->bossEntityState = 9;
            gCurrentPinballGame->bossFramesetIndex = 79;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = 2;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        if (gMain.spriteGroups[16].available)
        {
            gCurrentPinballGame->whirlpoolTrapPhase = 7;
            gCurrentPinballGame->whirlpoolTrapPauseTimer = 1;
        }

        gCurrentPinballGame->bossFrameTimer = 0;
        break;
    case 8:
        break;
    case 9:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 108)
            {
                gCurrentPinballGame->bossFramesetIndex = 107;
                gCurrentPinballGame->bossEntityState = 13;
                gCurrentPinballGame->boardState = 2;
                gCurrentPinballGame->stageTimer = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 97)
            {
                gCurrentPinballGame->boardEntityCollisionMode = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10f);
            }
        }
        break;
    case 10:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 4)
                gCurrentPinballGame->bossFramesetIndex = 0;
        }

        if (gCurrentPinballGame->bossAttackTimer > -500)
        {
            gCurrentPinballGame->bossAttackTimer += (-500 - gCurrentPinballGame->bossAttackTimer) / 30;
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->bossAttackTimer / 10;
            if (gCurrentPinballGame->cameraYAdjust < -50)
                gCurrentPinballGame->cameraYAdjust = -50;
        }

        if (gCurrentPinballGame->captureSequenceTimer == 21)
            gCurrentPinballGame->bossFramesetIndex = 114;

        if (gCurrentPinballGame->captureSequenceTimer == 22)
            gCurrentPinballGame->bossFramesetIndex = 115;
        break;
    case 11:
        if (gCurrentPinballGame->bossFrameTimer < 300)
        {
            gCurrentPinballGame->bossFrameTimer++;
            if (gCurrentPinballGame->bossFrameTimer == 218)
            {
                gCurrentPinballGame->shockwaveAnimTimer = 0;
                gCurrentPinballGame->bossPositionX = 500 - (Random() % 100) * 10;
                gCurrentPinballGame->bossPositionY = 200 + (Random() % 100) * 4;
            }

            if (gCurrentPinballGame->bossFrameTimer == 260)
            {
                for (i = 0; i < 2; i++)
                {
                    if (gCurrentPinballGame->orbEntityState[i] == 3)
                    {
                        gCurrentPinballGame->orbAnimTimer[i] = 0;
                        gCurrentPinballGame->orbEntityState[i] = 4;
                        gCurrentPinballGame->trapSpinRadius /= 2;
                    }

                    if (gCurrentPinballGame->orbEntityState[i] == 2)
                    {
                        gCurrentPinballGame->orbAnimTimer[i] = 0;
                        gCurrentPinballGame->orbEntityState[i] = 5;
                    }
                }
            }
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex = 67;
            gCurrentPinballGame->bossEntityState = 12;
            gCurrentPinballGame->boardEntityCollisionMode = 2;
            MPlayStart(&gMPlayInfo_SE1, &se_unk_10b);
            PlayRumble(8);
        }
        break;
    case 12:
        if (gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 79)
            {
                if (gCurrentPinballGame->bossMovementPhase <= 0)
                {
                    gCurrentPinballGame->bossFramesetIndex = 78;
                    gCurrentPinballGame->bossEntityState = 11;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossMovementPhase = 0;
                    gCurrentPinballGame->bossFramesetIndex = 8;
                    gCurrentPinballGame->bossEntityState = 2;
                    gCurrentPinballGame->bossPositionX = 0;
                    gCurrentPinballGame->bossPositionY = 0;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 70)
                gCurrentPinballGame->boardEntityCollisionMode = 3;

            if (gCurrentPinballGame->bossFramesetIndex == 73)
                gCurrentPinballGame->boardEntityCollisionMode = 0;

            if (gCurrentPinballGame->bossFramesetIndex == 72)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_10c);
                PlayRumble(8);
            }
        }
        break;
    case 13:
        break;
    }

    if (gCurrentPinballGame->bossRoarTimer)
    {
        gCurrentPinballGame->bossRoarTimer--;
        if (gCurrentPinballGame->bossRoarTimer == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_KYOGRE].speciesIdRS, 0);

        if (gCurrentPinballGame->bossRoarTimer == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderKyogreSprites(void)
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
        index = gCurrentPinballGame->bossVulnerable;
        gCurrentPinballGame->bossVulnerable = gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][2];
        var2 = gKyogreAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][0];
        if (index < 15)
        {
            DmaCopy16(3, gKyogreBodySprites_First15[index], (void *)0x06010FA0, 0x580);
        }
        else
        {
            index -= 15;
            DmaCopy16(3, gKyogreBodySprites_After15[index], (void *)0x06010FA0, 0x4C0);
        }

        group->baseX = gCurrentPinballGame->bossPositionX / 10 + 72u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->bossPositionY / 10 + 66u - gCurrentPinballGame->cameraYOffset;
        gCurrentPinballGame->catchTargetX = gCurrentPinballGame->bossPositionX / 10 + 120;
        gCurrentPinballGame->catchTargetY = gCurrentPinballGame->bossPositionY / 10 + 50;
        if (gCurrentPinballGame->boardEntityCollisionMode == 2)
        {
            gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 192;
            gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 134;
        }
        else if (gCurrentPinballGame->boardEntityCollisionMode == 3)
        {
            gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 192;
            gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 150;
        }
        else
        {
            gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 180;
            gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 116;
        }

        if (gCurrentPinballGame->legendaryFlashState > 9)
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
            if (gCurrentPinballGame->legendaryFlashState == 1)
                palette = 14;
            else if (gCurrentPinballGame->legendaryFlashState == 3)
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
                src = gKyogreMainBodyOamData[var2][i];
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
        group->baseX = gCurrentPinballGame->bossPositionX / 10 + 108 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->bossPositionY / 10 +  82 - gCurrentPinballGame->cameraYOffset;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gKyogreSplashAnimIndices[(gCurrentPinballGame->shockwaveAnimTimer % 84) / 6];
        DmaCopy16(3, gKyogreSplashSpriteFrames[index], (void *)0x06012420, 0xC0);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        if (gCurrentPinballGame->shockwaveAnimTimer < 83)
        {
            gCurrentPinballGame->shockwaveAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->shockwaveAnimTimer = 0;
            gMain.spriteGroups[26].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->bossEntityState == 11 && gCurrentPinballGame->bossFrameTimer == 218)
            group->available = 1;
    }
}

void UpdateKyogreFieldEntities(void)
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
        if (gCurrentPinballGame->portraitDisplayState == 3)
        {
            group->baseX = 240;
            group->baseY = 180;
        }
        else
        {
            group->baseX = 96;
            group->baseY = 55;
        }

        gCurrentPinballGame->rouletteBasePos.x = group->baseX;
        gCurrentPinballGame->rouletteBasePos.y = group->baseY;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].paletteNum = 13;
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[9];
        group->baseX = gCurrentPinballGame->rouletteBasePos.x - 8;
        group->baseY = gCurrentPinballGame->rouletteBasePos.y - 8;
        if (group->baseY >= 200)
            group->baseY = 200;

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[16];
    if (group->available)
    {
        switch (gCurrentPinballGame->whirlpoolTrapPhase)
        {
        case 0:
            gCurrentPinballGame->whirlpoolTrapAnimLoopStart = 0;
            gCurrentPinballGame->whirlpoolTrapAnimEndFrame = 5;
            gCurrentPinballGame->whirlpoolTrapNextPhase = 1;
            gCurrentPinballGame->whirlpoolTrapLoopCount = 0;
            gCurrentPinballGame->whirlpoolTrapPauseTimer = 0;
            if (gCurrentPinballGame->whirlpoolTrapAnimFrame == 2)
            {
                int a; // force addition of 8 instead of offsetting the global constant
                DmaCopy16(3, &gBallPalettes[a = gCurrentPinballGame->ballUpgradeType + 8], (void *)0x05000220, 0x20);
            }
            break;
        case 1:
            gCurrentPinballGame->whirlpoolTrapLoopCount = 4;
            gCurrentPinballGame->whirlpoolTrapPauseTimer = 90;
            gCurrentPinballGame->whirlpoolTrapPhase = 2;
            break;
        case 2:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->whirlpoolTrapPauseTimer -= 90;
                if (gCurrentPinballGame->whirlpoolTrapPauseTimer < 0)
                    gCurrentPinballGame->whirlpoolTrapPauseTimer = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->whirlpoolTrapAnimLoopStart = 5;
            gCurrentPinballGame->whirlpoolTrapAnimEndFrame = 9;
            gCurrentPinballGame->whirlpoolTrapNextPhase = 3;
            break;
        case 3:
            gCurrentPinballGame->whirlpoolTrapLoopCount = 4;
            gCurrentPinballGame->whirlpoolTrapPauseTimer = 90;
            gCurrentPinballGame->whirlpoolTrapPhase = 4;
            break;
        case 4:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->whirlpoolTrapPauseTimer -= 90;
                if (gCurrentPinballGame->whirlpoolTrapPauseTimer < 0)
                    gCurrentPinballGame->whirlpoolTrapPauseTimer = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->whirlpoolTrapAnimLoopStart = 9;
            gCurrentPinballGame->whirlpoolTrapAnimEndFrame = 13;
            gCurrentPinballGame->whirlpoolTrapNextPhase = 5;
            break;
        case 5:
            gCurrentPinballGame->whirlpoolTrapLoopCount = 0;
            gCurrentPinballGame->whirlpoolTrapPauseTimer = 90;
            gCurrentPinballGame->whirlpoolTrapPhase = 6;
            break;
        case 6:
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->whirlpoolTrapPauseTimer -= 90;
                if (gCurrentPinballGame->whirlpoolTrapPauseTimer < 0)
                    gCurrentPinballGame->whirlpoolTrapPauseTimer = 0;

                m4aSongNumStart(SE_UNKNOWN_0x111);
            }

            gCurrentPinballGame->whirlpoolTrapAnimLoopStart = 13;
            gCurrentPinballGame->whirlpoolTrapAnimEndFrame = 19;
            gCurrentPinballGame->whirlpoolTrapNextPhase = 7;
            break;
        case 7:
            gMain.spriteGroups[16].available = 0;
            break;
        }

        if (gCurrentPinballGame->whirlpoolTrapPauseTimer > 0)
        {
            gCurrentPinballGame->whirlpoolTrapPauseTimer--;
            if (gCurrentPinballGame->whirlpoolTrapPauseTimer == 0)
                m4aSongNumStart(SE_UNKNOWN_0x111);
        }
        else
        {
            if (gKyogreWhirlpoolTrapAnimFrameset[gCurrentPinballGame->whirlpoolTrapAnimFrame][1] > gCurrentPinballGame->whirlpoolTrapFrameTimer)
            {
                gCurrentPinballGame->whirlpoolTrapFrameTimer++;
            }
            else
            {
                gCurrentPinballGame->whirlpoolTrapFrameTimer = 0;
                gCurrentPinballGame->whirlpoolTrapAnimFrame++;
                if (gCurrentPinballGame->whirlpoolTrapAnimFrame == gCurrentPinballGame->whirlpoolTrapAnimEndFrame)
                {
                    if (gCurrentPinballGame->whirlpoolTrapLoopCount > 0)
                    {
                        gCurrentPinballGame->whirlpoolTrapAnimFrame = gCurrentPinballGame->whirlpoolTrapAnimLoopStart;
                        gCurrentPinballGame->whirlpoolTrapLoopCount--;
                    }
                    else
                    {
                        gCurrentPinballGame->whirlpoolTrapAnimFrame = gCurrentPinballGame->whirlpoolTrapAnimEndFrame - 1;
                        gCurrentPinballGame->whirlpoolTrapPhase = gCurrentPinballGame->whirlpoolTrapNextPhase;
                    }

                    gCurrentPinballGame->whirlpoolTrapPauseTimer = 90;
                }

                if (gCurrentPinballGame->whirlpoolTrapAnimFrame == 1)
                    m4aSongNumStart(SE_UNKNOWN_0x110);

                if (gCurrentPinballGame->whirlpoolTrapAnimFrame == 15)
                {
                    DmaCopy16(3, gBallPalettes[gCurrentPinballGame->ballUpgradeType], (void *)0x05000220, 0x20);
                    m4aSongNumStart(SE_UNKNOWN_0x112);
                }
            }
        }

        if (gCurrentPinballGame->whirlpoolTrapAnimFrame < 18)
        {
            gCurrentPinballGame->ballGrabbed = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spinSpeed = 0;
        }
        else
        {
            gCurrentPinballGame->ballGrabbed = 0;
        }

        group->baseX = gCurrentPinballGame->ball->screenPosition.x;
        group->baseY = gCurrentPinballGame->ball->screenPosition.y;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gKyogreWhirlpoolTrapAnimFrameset[gCurrentPinballGame->whirlpoolTrapAnimFrame][2];
        DmaCopy16(3, gKyogreWhirlpoolSpriteFrames[index], (void *)0x060124E0, 0x3C0);
        var0 = gKyogreWhirlpoolTrapAnimFrameset[gCurrentPinballGame->whirlpoolTrapAnimFrame][0];
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gKyogreWhirlpoolTrapOamData[var0][i];
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
            switch (gCurrentPinballGame->orbEntityState[i]) {
            case 0:
                index = 0;
                gCurrentPinballGame->orbScreenPosition[i].x = 0;
                gCurrentPinballGame->orbScreenPosition[i].y = 0;
                break;
            case 1:
                index = gCurrentPinballGame->orbAnimTimer[i] / 9;
                if (gCurrentPinballGame->orbAnimTimer[i] < 98)
                {
                    gCurrentPinballGame->orbAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->orbEntityState[i] = 2;
                    gCurrentPinballGame->orbTargetWaypointIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->orbOrbitCenter[i].x = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->orbTargetWaypointIndex[i]].x;
                    gCurrentPinballGame->orbOrbitCenter[i].y = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->orbTargetWaypointIndex[i]].y;
                }

                gCurrentPinballGame->orbScreenPosition[i].x = 0;
                gCurrentPinballGame->orbScreenPosition[i].y = 0;
                break;
            case 2:
                index = ((gCurrentPinballGame->orbAnimTimer[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->orbEntityState[0] < 3 && gCurrentPinballGame->orbEntityState[1] < 3)
                {
                    int xoff = 120;
                    int yoff = 144;
                    tempVector.x = (gCurrentPinballGame->ball->positionQ0.x - xoff) - (gCurrentPinballGame->orbScreenPosition[i].x / 10);
                    tempVector.y = (gCurrentPinballGame->ball->positionQ0.y - yoff) - (gCurrentPinballGame->orbScreenPosition[i].y / 10);
                    xx = tempVector.x * tempVector.x;
                    yy = tempVector.y * tempVector.y;
                    squaredMagnitude = xx + yy;
                    if (gCurrentPinballGame->ballGrabbed == 0 && gCurrentPinballGame->ballRespawnState == 0 &&
                        gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired &&
                        gCurrentPinballGame->bossHitFlashTimer == 0 && squaredMagnitude < 400)
                    {
                        m4aSongNumStart(SE_UNKNOWN_0x113);
                        PlayRumble(12);
                        gCurrentPinballGame->ballFrozenState = 1;
                        gCurrentPinballGame->orbAnimTimer[i] = 0;
                        gCurrentPinballGame->orbEntityState[i] = 3;
                        gCurrentPinballGame->boardEntityActive = 1;
                        tempVector2.x = gCurrentPinballGame->orbScreenPosition[i].x / 10 + 120;
                        tempVector2.y = gCurrentPinballGame->orbScreenPosition[i].y / 10 + 144;
                        tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                        tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
                        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);
                    }
                }

                if (gCurrentPinballGame->orbAnimTimer[i] < 900)
                {
                    gCurrentPinballGame->orbAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->orbEntityState[i] = 5;
                }
                break;
            case 3:
                index = ((gCurrentPinballGame->orbAnimTimer[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                    gCurrentPinballGame->orbAnimTimer[i] += 8;

                var4 = 29 - gCurrentPinballGame->orbAnimTimer[i];
                if (var4 < 10)
                    var4 = 10;

                gCurrentPinballGame->trapAngleQ16 -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
                gCurrentPinballGame->ball->spinAngle -= 0x2000;
                var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 30;
                tempVector2.x = gCurrentPinballGame->orbScreenPosition[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->orbScreenPosition[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->orbAnimTimer[i] < 480)
                {
                    gCurrentPinballGame->orbAnimTimer[i]++;
                    if (gCurrentPinballGame->orbAnimTimer[i] % 9 == 0)
                        PlayRumble(12);
                }
                else
                {
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->orbEntityState[i] = 4;
                    gCurrentPinballGame->trapSpinRadius /= 2;
                }
                break;
            case 4:
                index = 5 - gCurrentPinballGame->orbAnimTimer[i] / 8;
                var4 = 47 - gCurrentPinballGame->orbAnimTimer[i];
                gCurrentPinballGame->trapAngleQ16 -= ((0x2000 - (var4 * 0x1000) / 47) * 2) / 5;
                gCurrentPinballGame->ball->spinAngle -= 0x2000;
                var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 47;
                tempVector2.x = gCurrentPinballGame->orbScreenPosition[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->orbScreenPosition[i].y / 10 + 144;
                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->orbAnimTimer[i] < 47)
                {
                    gCurrentPinballGame->orbAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = -150 + (gMain.systemFrameCount % 2) * 300;
                    gCurrentPinballGame->ball->velocity.y = 300;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->orbEntityState[i] = 0;
                    gCurrentPinballGame->boardEntityActive = 0;
                }
                break;
            case 5:
                index = 5 - gCurrentPinballGame->orbAnimTimer[i] / 6;
                if (gCurrentPinballGame->orbAnimTimer[i] < 36)
                {
                    gCurrentPinballGame->orbAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->orbEntityState[i] = 0;
                }
                break;
            }

            if (gCurrentPinballGame->orbEntityState[i] >= 2 && gCurrentPinballGame->orbEntityState[i] < 4)
            {
                tempVector.x = gCurrentPinballGame->orbOrbitCenter[i].x - gCurrentPinballGame->orbScreenPosition[i].x;
                tempVector.y = gCurrentPinballGame->orbOrbitCenter[i].y - gCurrentPinballGame->orbScreenPosition[i].y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                angle = ArcTan2(tempVector.x, -tempVector.y);
                tempVector3.x =  (Cos(angle) * 4) / 20000;
                tempVector3.y = -(Sin(angle) * 4) / 20000;
                gCurrentPinballGame->orbScreenPosition[i].x += tempVector3.x;
                gCurrentPinballGame->orbScreenPosition[i].y += tempVector3.y;
                if (squaredMagnitude < 2500)
                {
                    gCurrentPinballGame->orbTargetWaypointIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->orbOrbitCenter[i].x = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->orbTargetWaypointIndex[i]].x;
                    gCurrentPinballGame->orbOrbitCenter[i].y = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->orbTargetWaypointIndex[i]].y;
                }
            }
        }

        DmaCopy16(3, gKyogreWhirlpoolMinionSprites[index], (void *)0x06011520 + i * 0x200, 0x200);
        if (group->available)
        {
            if (gCurrentPinballGame->orbEntityState[i] > 0)
            {
                group->baseX = gCurrentPinballGame->orbScreenPosition[i].x / 10 - (gCurrentPinballGame->cameraXOffset - 104u);
                group->baseY = gCurrentPinballGame->orbScreenPosition[i].y / 10 - (gCurrentPinballGame->cameraYOffset - 128u);
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

        if (gCurrentPinballGame->shockwaveAnimTimer < 36)
        {
            scale = (gCurrentPinballGame->shockwaveAnimTimer * 0x200) / 35 + 0x10;
            if (scale > 0x200)
                scale = 0x200;

            SetMatrixScale(scale, scale, 1);
            SetMatrixScale(-scale, scale, 2);
            SetMatrixScale(scale, -scale, 3);
            SetMatrixScale(-scale, -scale, 4);
            if (gCurrentPinballGame->shockwaveAnimTimer > 30)
                var6 = 12 - ((gCurrentPinballGame->shockwaveAnimTimer - 30) * 11) / 5;
            else
                var6 = 16 - (gCurrentPinballGame->shockwaveAnimTimer * 4) / 30;

            gCurrentPinballGame->shockwaveAnimTimer++;
        }
        else
        {
            scale = 0x100;
            var6 = 0;
            group->available = 0;
        }

        gCurrentPinballGame->shockwaveQuadrantOffset[0].x = 0x20 - scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[1].x = 0x20 + scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[2].x = 0x20 - scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[3].x = 0x20 + scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[0].y = 0x20 - scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[1].y = 0x20 - scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[2].y = 0x20 + scale / 8;
        gCurrentPinballGame->shockwaveQuadrantOffset[3].y = 0x20 + scale / 8;

        if ((gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER) == 0)
        {
            gMain.blendControl = 0x1E10;
            gMain.blendAlpha = BLDALPHA_BLEND(var6, 16 - var6);
        }

        if (group->available)
        {
            group->baseX = 23 - gCurrentPinballGame->cameraXOffset;
            group->baseY = 30 - gCurrentPinballGame->cameraYOffset;
            for (i = 0; i < 4; i++)
            {
                oamSimple = &group->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->shockwaveQuadrantOffset[i].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->shockwaveQuadrantOffset[i].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + i;
            }
        }

        if (gCurrentPinballGame->shockwaveAnimTimer < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 127;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->ballRespawnState == 0 && squaredMagnitude < gShockwaveSplashDistanceThresholds[gCurrentPinballGame->shockwaveAnimTimer])
            {
                gCurrentPinballGame->whirlpoolTrapPhase = 0;
                gCurrentPinballGame->whirlpoolTrapAnimFrame = 0;
                gCurrentPinballGame->whirlpoolTrapFrameTimer = 0;
                if (!gMain.spriteGroups[16].available)
                    PlayRumble(8);

                gMain.spriteGroups[16].available = 1;
            }
        }

        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER)
            gMain.spriteGroups[24].available = 0;
    }
}

void HideKyogreSplashSprite(void)
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

void AnimateKyogreBackground(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 index;

    if (gCurrentPinballGame->boardState == 0 && gCurrentPinballGame->stageTimer < 600)
    {
        index = gKyogreIntroPaletteCycleIndices[(gCurrentPinballGame->stageTimer % 240) / 24];
        DmaCopy16(3, gKyogreIntroIcePalette[index], (void *)0x05000340, 0x20);
        DmaCopy16(3, gKyogreIntroShorePalette[index], (void *)0x050002A0, 0x20);
        var0 = 2;
        index = 0;
        gCurrentPinballGame->kyogreBgAnimTimer = index;
    }
    else
    {
        var0 = gKyogreBgTileVariantCycle[(gCurrentPinballGame->kyogreBgAnimTimer % 96) / 24];
        gCurrentPinballGame->kyogreBgAnimTimer++;
    }

    index = gWaterTilePaletteCycle[(gCurrentPinballGame->globalAnimFrameCounter % 96) / 24];
    for (i = 0; i < 0x400; i++)
        gBG0TilemapBuffer[0x800 + i] = gKyogreWaterBackgroundTilemap[i] + index * 4;

    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x06000000, 0x800);
    index = gKyogreWaterPaletteSegmentCycle[(gMain.systemFrameCount % 96) / 24];
    DmaCopy16(3, &gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][index * 0x20], (void *)0x05000060, 0x20);

    for (j = 0; j < 4; j++)
    {
        group = &gMain.spriteGroups[11 + j];
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 128 - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 3; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gKyogreBgSpriteBaseTileNums[i] + var0 * 8;
        }
    }

    group = &gMain.spriteGroups[15];
    if (group->available)
    {
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 128 - gCurrentPinballGame->cameraYOffset;
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
