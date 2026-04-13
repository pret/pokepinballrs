#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"


extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gGroudonLavaPaletteCycleData[];
extern const u8 gGroudonBoardBackgroundGfx[];
extern const s8 gGroudonBoulderSpriteFrames[][0x300];
extern struct SongHeader se_unk_118;
extern struct SongHeader se_unk_11b;
extern struct SongHeader se_unk_11c;
extern struct SongHeader se_unk_11d;
extern struct SongHeader se_unk_11f;
extern const s16 gShockwaveSplashDistanceThresholds[];
extern const s16 gScreenShakeOscillationValues[];
extern const u16 gGroudonFootstepShakePatterns[][31];
extern const u16 gGroudonCryShakePattern[];
extern const u16 gGroudonAnimFramesetTable[][2];
extern const struct Vector16 gGroudonFirePillarBasePositions[];
extern const u16 gGroudonFirePillarAnimFrameset[][2];
extern const s16 gGroudonBoulderPositionTable[][3];
extern const s16 gGroudonBoulderBaseSpriteIndices[];
extern const s16 gGroudonLavaPaletteAnimIndices[];
extern const s16 gGroudonBgTileAnimIndices[];
extern const u16 gGroudonBgSpriteBaseTileNums[];
extern const u16 gGroudonBallGrabOamData[12][2][3];
extern const u16 gGroudonProjectileOamData[24][4][3];
extern const u16 gGroudonProjectileAttackOamData[12][6][3];
extern const u16 gGroudonMainBodyOamData[166][19][3];
extern const u16 gGroudonFirePillarOamData[58][10][3];


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

    gCurrentPinballGame->boardModeType = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnState = 3;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = 1;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    gCurrentPinballGame->portraitDisplayState = 3;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballGrabbed = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->bossEntityState = 0;
    gCurrentPinballGame->bossAttackPhase = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->bossVulnerable = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossMovementPhase = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->bossAnimLoopCount = 0;
    gCurrentPinballGame->bossPositionX = 0;
    gCurrentPinballGame->bossPositionY = 0;
    gCurrentPinballGame->bossVelocityX = 0;
    gCurrentPinballGame->bossVelocityY = 0;
    gCurrentPinballGame->bossCollisionX = 0;
    gCurrentPinballGame->bossCollisionY = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;
    gCurrentPinballGame->shockwaveAnimTimer = 0;
    gCurrentPinballGame->projectileAttackCount = 0;
    gCurrentPinballGame->projectileDirection = 0;
    gCurrentPinballGame->projectileAttackAnimTimer = 0;
    gCurrentPinballGame->ballGrabShakeTimer = 0;
    gCurrentPinballGame->ballGrabFlashTimer = 0;
    gCurrentPinballGame->projectileFlightTimer = 0;
    gCurrentPinballGame->projectileAngle = 0;
    gCurrentPinballGame->ballGrabTimer = 0;
    gCurrentPinballGame->projectilePosition.x = 0;
    gCurrentPinballGame->projectilePosition.y = 0;
    gCurrentPinballGame->firePillarSpawnSfxTimer = 0;
    gCurrentPinballGame->bossDropVelocity = 0;
    gCurrentPinballGame->impactShakeTimer = 0;
    gCurrentPinballGame->footstepShakeTimer = 0;
    gCurrentPinballGame->footstepShakePattern = 0;

    for (i = 0; i < 4; i++)
    {
        gCurrentPinballGame->shockwaveQuadrantOffset[i].x = 0;
        gCurrentPinballGame->shockwaveQuadrantOffset[i].y = 0;
        gCurrentPinballGame->firePillarState[i] = 0;
        gCurrentPinballGame->firePillarAnimEndFrame[i] = 0;
        gCurrentPinballGame->firePillarNextState[i] = 0;
        gCurrentPinballGame->firePillarAnimFrame[i] = 0;
        gCurrentPinballGame->firePillarAnimStartFrame[i] = 0;
        gCurrentPinballGame->firePillarAnimLoopCount[i] = 0;
        gCurrentPinballGame->firePillarHitTimer[i] = 0;
        gCurrentPinballGame->firePillarFrameTimer[i] = 0;
        gCurrentPinballGame->firePillarCollisionPos[i].x = 0;
        gCurrentPinballGame->firePillarCollisionPos[i].y = 0;
    }

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->boulderPositionIndex[i] = 0;
        gCurrentPinballGame->boulderState[i] = 0;
        gCurrentPinballGame->boulderSpriteFrame[i] = 0;
        gCurrentPinballGame->boulderHitFlag[i] = 0;
        gCurrentPinballGame->boulderAnimTimer[i] = 0;
        gCurrentPinballGame->boulderFallVelocity[i] = 0;
        gCurrentPinballGame->boulderFallHeight[i] = 0;
        gCurrentPinballGame->boulderGroundPosition[i].x = 0;
        gCurrentPinballGame->boulderGroundPosition[i].y = 0;
        gCurrentPinballGame->boulderCollisionPos[i].x = 0;
        gCurrentPinballGame->boulderCollisionPos[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = 1;
    UpdateGroudonFieldEntities();
    UpdateGroudonEntityLogic();
    RenderGroudonSprites();
    DmaCopy16(3, gGroudonBoardBackgroundGfx, (void *)0x06015800, 0x2000);
    AnimateGroudonBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_GROUDON);
    DmaCopy16(3, gBonusStageObjPal, (void *)0x05000320, 0x20);
}

void GroudonBoardProcess_3B_3B49C(void)
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
            gCurrentPinballGame->stageTimer++;;
            if (gCurrentPinballGame->cameraYAdjust >= -32)
                gCurrentPinballGame->flippersDisabled = 0;

            if (gCurrentPinballGame->stageTimer == 650)
                gCurrentPinballGame->boardModeType = 1;
        }
        else
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
            DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
        break;
    }

    UpdateGroudonFieldEntities();
    UpdateGroudonEntityLogic();
    RenderGroudonSprites();
    AnimateGroudonBackground();
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

void UpdateGroudonEntityLogic(void)
{
    s16 i;
    struct Vector32 tempVector;

    if (gCurrentPinballGame->bossHitFlashTimer)
    {
        gCurrentPinballGame->bossHitFlashTimer--;
        gCurrentPinballGame->legendaryFlashState = 1;
        if (gCurrentPinballGame->bossHitFlashTimer == 35)
        {
            MPlayStart(&gMPlayInfo_SE1, &se_unk_118);
            gCurrentPinballGame->scoreAddedInFrame = 500000;
            PlayRumble(7);
            gCurrentPinballGame->bonusModeHitCount++;
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                gCurrentPinballGame->bossEntityState = 6;
        }

        if (gCurrentPinballGame->bossHitFlashTimer < 31)
            gCurrentPinballGame->legendaryFlashState = 0;
    }

    switch (gCurrentPinballGame->bossEntityState)
    {
    case 0:
        gCurrentPinballGame->bossEntityState = 1;
        gCurrentPinballGame->bossFramesetIndex = 22;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossPositionX = 0;
        gCurrentPinballGame->bossPositionY = -1200;
        gCurrentPinballGame->bossDropVelocity = 0;
        break;
    case 1:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 36)
            {
                if (gCurrentPinballGame->bossMovementPhase < 18)
                {
                    gCurrentPinballGame->bossFramesetIndex = 34;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossEntityState = 2;
                    gCurrentPinballGame->bossAttackPhase = 4;
                    gCurrentPinballGame->bossMovementPhase = 9;
                }
            }
        }

        if (gCurrentPinballGame->bossFramesetIndex == 22)
        {
            if (gCurrentPinballGame->bossFrameTimer < 500)
            {
                if (gCurrentPinballGame->bossFrameTimer == 50 || gCurrentPinballGame->bossFrameTimer == 270)
                {
                    gCurrentPinballGame->footstepShakeTimer = 31;
                    gCurrentPinballGame->footstepShakePattern = gCurrentPinballGame->bossFrameTimer / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }

                if (gCurrentPinballGame->bossFrameTimer == 160 || gCurrentPinballGame->bossFrameTimer == 380)
                {
                    gCurrentPinballGame->footstepShakeTimer = 31;
                    gCurrentPinballGame->footstepShakePattern = gCurrentPinballGame->bossFrameTimer / 110;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }

                if (gCurrentPinballGame->bossFrameTimer == 490)
                {
                    gCurrentPinballGame->footstepShakeTimer = 31;
                    gCurrentPinballGame->footstepShakePattern = 4;
                    m4aSongNumStart(SE_UNKNOWN_0x11A);
                    PlayRumble(8);
                }
            }

            if (gCurrentPinballGame->bossFrameTimer >= 630)
            {
                if (gCurrentPinballGame->bossPositionY < 0)
                {
                    gCurrentPinballGame->bossDropVelocity += 4;
                    gCurrentPinballGame->bossPositionY += gCurrentPinballGame->bossDropVelocity;
                    if (gCurrentPinballGame->bossPositionY > 0)
                        gCurrentPinballGame->bossPositionY = 0;
                }
            }

            if (gCurrentPinballGame->bossPositionY >= 0)
            {
                gCurrentPinballGame->impactShakeTimer = 60;
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->bossFramesetIndex == 33)
        {
            if (gCurrentPinballGame->bossFrameTimer == 0)
                gCurrentPinballGame->bossRoarTimer = 41;
        }

        if (gCurrentPinballGame->ballRespawnTimer > 120)
            gCurrentPinballGame->ballRespawnTimer--;
        break;
    case 2:
        if (gCurrentPinballGame->bossHitFlashTimer > 30)
        {
            gCurrentPinballGame->bossFramesetIndex = 21;
            gCurrentPinballGame->bossFrameTimer = 0;
            break;
        }

        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 2)
            {
                if (gCurrentPinballGame->bossMovementPhase < 12)
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossMovementPhase++;
                    if (gCurrentPinballGame->bossMovementPhase == 12 && gCurrentPinballGame->bossAttackPhase == 4)
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (gCurrentPinballGame->firePillarState[i] < 9)
                                gCurrentPinballGame->firePillarState[i] = 9;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->bossAttackPhase == 4)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 36;
                        gCurrentPinballGame->bossEntityState = 4;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else if (gCurrentPinballGame->bossAttackPhase == 3)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 76;
                        gCurrentPinballGame->bossEntityState = 3;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 58;
                        gCurrentPinballGame->bossEntityState = 5;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
            }
        }

        if (gCurrentPinballGame->bossFramesetIndex == 21)
            gCurrentPinballGame->bossFramesetIndex = 0;
        break;
    case 3:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            s16 varZZ;
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 93 || gCurrentPinballGame->bossFramesetIndex == 96 || gCurrentPinballGame->bossFramesetIndex == 99)
            {
                gCurrentPinballGame->bossFramesetIndex = 0;
                gCurrentPinballGame->bossEntityState = 2;

                if (gCurrentPinballGame->projectileAttackCount & 1)
                {
                    gCurrentPinballGame->bossAttackPhase = 4;
                    gCurrentPinballGame->bossMovementPhase = 8;
                }
                else
                {
                    gCurrentPinballGame->bossAttackPhase = 5;
                    gCurrentPinballGame->bossMovementPhase = 8;
                }

                gCurrentPinballGame->projectileAttackCount++;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 90)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_unk_11c);
                gCurrentPinballGame->projectileAttackAnimTimer = 8;
                gCurrentPinballGame->projectileFlightTimer = 35;
                gMain.spriteGroups[22].available = 1;
                gCurrentPinballGame->projectilePosition.x = 1200;
                gCurrentPinballGame->projectilePosition.y = 1240;
                tempVector.x = gCurrentPinballGame->projectilePosition.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
                tempVector.y = gCurrentPinballGame->projectilePosition.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
                gCurrentPinballGame->projectileAngle = ArcTan2(-tempVector.x, tempVector.y);
                if (gCurrentPinballGame->ballRespawnState)
                    gCurrentPinballGame->projectileAngle = (((Random() * gMain.systemFrameCount) % 100) * 0x5000) / 100 + 0x9800;

                if (gCurrentPinballGame->projectileAngle < 0x4000)
                {
                    gCurrentPinballGame->projectileAngle = 0xE800;
                    gCurrentPinballGame->projectileDirection = 2;
                    gCurrentPinballGame->projectilePosition.x = 1340;
                }
                else if (gCurrentPinballGame->projectileAngle < 0x9800)
                {
                    gCurrentPinballGame->projectileAngle = 0x9800;
                    gCurrentPinballGame->projectileDirection = 1;
                    gCurrentPinballGame->projectilePosition.x = 1060;
                }
                else if (gCurrentPinballGame->projectileAngle < 0xB000)
                {
                    gCurrentPinballGame->projectileDirection = 1;
                    gCurrentPinballGame->projectilePosition.x = 1060;
                }
                else if (gCurrentPinballGame->projectileAngle < 0xD000)
                {
                    gCurrentPinballGame->projectileDirection = 0;
                }
                else if (gCurrentPinballGame->projectileAngle < 0xE800)
                {
                    gCurrentPinballGame->projectileDirection = 2;
                    gCurrentPinballGame->projectilePosition.x = 1340;
                }
                else
                {
                    gCurrentPinballGame->projectileAngle = 0xE800;
                    gCurrentPinballGame->projectileDirection = 2;
                    gCurrentPinballGame->projectilePosition.x = 1340;
                }

                gCurrentPinballGame->bossFramesetIndex += gCurrentPinballGame->projectileDirection * 3;
                if (gCurrentPinballGame->ballRespawnState)
                    gCurrentPinballGame->ballRespawnState -= 0;
            }
        }
        break;
    case 4:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 56)
            {
                if (gCurrentPinballGame->bossMovementPhase < 6)
                {
                    gCurrentPinballGame->bossFramesetIndex = 54;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossEntityState = 2;
                    gCurrentPinballGame->bossAttackPhase = 3;
                    gCurrentPinballGame->bossMovementPhase = 6;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 50)
            {
                if (gCurrentPinballGame->bossFrameTimer == 0)
                {
                    gMain.spriteGroups[30].available = 1;
                    gCurrentPinballGame->shockwaveAnimTimer = 0;
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11d);
                }
            }
        }
        break;
    case 5:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 74)
            {
                gCurrentPinballGame->bossFramesetIndex = 0;
                gCurrentPinballGame->bossEntityState = 2;
                gCurrentPinballGame->bossAttackPhase = 3;
                gCurrentPinballGame->bossMovementPhase = 8;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 71)
            {
                if (gCurrentPinballGame->bossFrameTimer == 0)
                {
                    gCurrentPinballGame->boardShakeDirection = 0;
                    gCurrentPinballGame->boardShakeIntensity = 1;
                    gCurrentPinballGame->impactShakeTimer = 60;
                    PlayRumble(13);
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11b);
                }
            }
        }
        break;
    case 6:
        gCurrentPinballGame->boardModeType = 3;

        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch groudon
            gCurrentPinballGame->bossEntityState = 9;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_GROUDON;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = 2;
        }
        else
        {
            // bonus completed
            gCurrentPinballGame->bossEntityState = 7;
            gCurrentPinballGame->bossFramesetIndex = 32;
            gCurrentPinballGame->boardEntityCollisionMode = 0;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = 2;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossFrameTimer = 0;
        if (gMain.spriteGroups[24].available)
            gCurrentPinballGame->ballGrabTimer = 1;
        break;
    case 7:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 36)
            {
                if (gCurrentPinballGame->bossMovementPhase < 18)
                {
                    gCurrentPinballGame->bossFramesetIndex = 34;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 2;
                    gCurrentPinballGame->bossEntityState = 8;
                    gCurrentPinballGame->bossMovementPhase = 0;
                }
            }
        }

        if (gCurrentPinballGame->bossFramesetIndex == 33)
        {
            if (gCurrentPinballGame->bossFrameTimer == 0)
                gCurrentPinballGame->bossRoarTimer = 41;
        }
        break;
    case 8:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 20)
            {
                if (gCurrentPinballGame->bossMovementPhase < 7)
                {
                    gCurrentPinballGame->bossFramesetIndex = 3;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 3;
                    gCurrentPinballGame->bossEntityState = 10;
                    gCurrentPinballGame->boardState = 2;
                    gCurrentPinballGame->stageTimer = 0;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 3 || gCurrentPinballGame->bossFramesetIndex == 12)
                gCurrentPinballGame->bossPositionY -= 10;

            if ((gCurrentPinballGame->bossFramesetIndex >= 4 && gCurrentPinballGame->bossFramesetIndex < 6) ||
                gCurrentPinballGame->bossFramesetIndex == 13 || gCurrentPinballGame->bossFramesetIndex == 14)
            {
                gCurrentPinballGame->bossPositionY -= 20;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 5)
            {
                if (gCurrentPinballGame->bossFrameTimer == 0)
                {
                    gCurrentPinballGame->footstepShakeTimer = 31;
                    gCurrentPinballGame->footstepShakePattern = 6;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 14)
            {
                if (gCurrentPinballGame->bossFrameTimer == 0)
                {
                    gCurrentPinballGame->footstepShakeTimer = 31;
                    gCurrentPinballGame->footstepShakePattern = 5;
                    m4aSongNumStart(SE_GROUDON_STEP);
                    PlayRumble(8);
                }
            }
        }
        break;
    case 9:
        if (gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 2)
                gCurrentPinballGame->bossFramesetIndex = 0;
        }

        if (gCurrentPinballGame->bossAttackTimer > -500)
        {
            gCurrentPinballGame->bossAttackTimer += (-500 - gCurrentPinballGame->bossAttackTimer) / 30;
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->bossAttackTimer / 10;
            if (gCurrentPinballGame->cameraYAdjust < -38)
                gCurrentPinballGame->cameraYAdjust = -38;
        }

        if (gCurrentPinballGame->captureSequenceTimer == 21)
            gCurrentPinballGame->bossFramesetIndex = 74;

        if (gCurrentPinballGame->captureSequenceTimer == 22)
            gCurrentPinballGame->bossFramesetIndex = 75;
        break;
    case 10:
        break;
    }

    if (gCurrentPinballGame->impactShakeTimer > 0)
    {
        gCurrentPinballGame->impactShakeTimer--;
        if (gCurrentPinballGame->impactShakeTimer < 20)
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12] * 2;
        else
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12] * 4;

        if (gCurrentPinballGame->impactShakeTimer == 0)
            gCurrentPinballGame->screenShakeY = 0;

        if (gCurrentPinballGame->impactShakeTimer == 8)
        {
            i = 0;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->boulderState[i] = 0;
            gCurrentPinballGame->boulderSpriteFrame[i] = 0;
            gCurrentPinballGame->boulderAnimTimer[i] = 0;
        }

        if (gCurrentPinballGame->impactShakeTimer == 20)
        {
            i = 1;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->boulderState[i] = 0;
            gCurrentPinballGame->boulderSpriteFrame[i] = 13;
            gCurrentPinballGame->boulderAnimTimer[i] = 0;
        }

        if (gCurrentPinballGame->impactShakeTimer == 53)
        {
            i = 2;
            gMain.spriteGroups[15 + i].available = 1;
            gCurrentPinballGame->boulderState[i] = 0;
            gCurrentPinballGame->boulderSpriteFrame[i] = 22;
            gCurrentPinballGame->boulderAnimTimer[i] = 0;
        }
    }

    if (gCurrentPinballGame->footstepShakeTimer)
    {
        gCurrentPinballGame->footstepShakeTimer--;
        if (gCurrentPinballGame->footstepShakePattern < 6)
        {
            gCurrentPinballGame->screenShakeY = gGroudonFootstepShakePatterns[gCurrentPinballGame->footstepShakePattern][30 - gCurrentPinballGame->footstepShakeTimer % 31];
        }
        else
        {
            gCurrentPinballGame->screenShakeY = gGroudonCryShakePattern[69 - gCurrentPinballGame->footstepShakeTimer % 70];
        }

        if (gCurrentPinballGame->footstepShakeTimer == 0)
            gCurrentPinballGame->screenShakeY = 0;
    }

    if (gCurrentPinballGame->bossRoarTimer)
    {
        gCurrentPinballGame->bossRoarTimer--;
        if (gCurrentPinballGame->bossRoarTimer == 20)
        {
            PlayCry_Normal(gSpeciesInfo[SPECIES_GROUDON].speciesIdRS, 0);
            gCurrentPinballGame->footstepShakeTimer = 70;
            gCurrentPinballGame->footstepShakePattern = 6;
        }

        if (gCurrentPinballGame->bossRoarTimer == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderGroudonSprites(void)
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
        var0 = gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][0];
        group->baseX = gCurrentPinballGame->bossPositionX / 10 + 100u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->bossPositionY / 10 +  84u - gCurrentPinballGame->cameraYOffset;
        gCurrentPinballGame->catchTargetX = gCurrentPinballGame->bossPositionX / 10 + 118;
        gCurrentPinballGame->catchTargetY = gCurrentPinballGame->bossPositionY / 10 + 60;
        gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 184;
        gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 156;
        if (group->baseY < -60)
            group->baseY = -60;
        if (group->baseY > 180)
            group->baseY = 180;

        if (gCurrentPinballGame->legendaryFlashState > 9)
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
        else if (gCurrentPinballGame->legendaryFlashState == 1)
        {
            palette = 14;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gGroudonMainBodyOamData[var0][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].paletteNum = palette;
            }
        }
        else if (gCurrentPinballGame->legendaryFlashState == 3)
        {
            palette = 11;
            for (i = 0; i < 19; i++)
            {
                oamSimple = &group->oam[i];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gGroudonMainBodyOamData[var0][i];
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
                src = gGroudonMainBodyOamData[var0][i];
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
        if (gCurrentPinballGame->projectileAttackAnimTimer > 0)
        {
            gCurrentPinballGame->projectileAttackAnimTimer--;
            if (gCurrentPinballGame->projectileAttackAnimTimer == 0)
                group->available = 0;
        }

        var0 = gCurrentPinballGame->projectileDirection * 2 - (gCurrentPinballGame->projectileAttackAnimTimer / 4 - 1);
        group->baseX = gCurrentPinballGame->bossPositionX / 10 + 100u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->bossPositionY / 10 +  84u - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gGroudonProjectileAttackOamData[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->captureState == 2)
        {
            gMain.spriteGroups[23].available = 0;
            gCurrentPinballGame->projectileAttackAnimTimer = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->projectileAttackAnimTimer == 8)
            group->available = 1;
    }
}

void UpdateGroudonFieldEntities(void)
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

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
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

        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        gCurrentPinballGame->ballGrabTimer--;
        if (gCurrentPinballGame->ballGrabTimer >= 600)
        {
            varSL = 0;
        }
        else if (gCurrentPinballGame->ballGrabTimer >= 6)
        {
            varSL = (gCurrentPinballGame->ballGrabTimer % 15) / 5 + 1;
            if (gCurrentPinballGame->ballGrabShakeTimer > 0)
            {
                if (gCurrentPinballGame->ballGrabShakeTimer == 7)
                    gCurrentPinballGame->ball->positionQ8.x += 0x100;
                else if (gCurrentPinballGame->ballGrabShakeTimer == 4)
                    gCurrentPinballGame->ball->positionQ8.x -= 0x200;
                else if (gCurrentPinballGame->ballGrabShakeTimer == 1)
                    gCurrentPinballGame->ball->positionQ8.x += 0x100;

                gCurrentPinballGame->ballGrabShakeTimer--;
            }
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->ballGrabTimer = gCurrentPinballGame->ballGrabTimer - 30;
                if (gCurrentPinballGame->ballGrabTimer < 5)
                    gCurrentPinballGame->ballGrabTimer = 5;

                gCurrentPinballGame->ballGrabShakeTimer = 7;
                m4aSongNumStart(SE_UNKNOWN_0x11E);
            }

            if (gCurrentPinballGame->ballGrabFlashTimer)
            {
                gCurrentPinballGame->ballGrabFlashTimer--;
                if (gCurrentPinballGame->ballGrabFlashTimer > 50)
                    varSL = 4;
                else if (gCurrentPinballGame->ballGrabFlashTimer > 40)
                    varSL = 5;
            }
            else if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->ballGrabFlashTimer = 60;
            }
        }
        else
        {
            varSL = 4;
        }

        if (gCurrentPinballGame->ballGrabTimer == 0)
        {
            gMain.spriteGroups[24].available = 0;
            gCurrentPinballGame->ballGrabFlashTimer = 0;
            gCurrentPinballGame->ballGrabbed = 0;
        }
        else
        {
            gCurrentPinballGame->ballGrabbed = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spinSpeed = 0;
        }

        group->baseX = gCurrentPinballGame->ball->positionQ0.x - gCurrentPinballGame->cameraXOffset - 8;
        group->baseY = gCurrentPinballGame->ball->positionQ0.y - gCurrentPinballGame->cameraYOffset - 8;
        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gGroudonBallGrabOamData[varSL][j];
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
        tempVector.x = gCurrentPinballGame->projectilePosition.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
        tempVector.y = gCurrentPinballGame->projectilePosition.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredMagnitude = xx + yy;
        if (gCurrentPinballGame->projectileFlightTimer)
        {
            gCurrentPinballGame->projectileFlightTimer--;
            if (gCurrentPinballGame->projectileFlightTimer >= 10)
            {
                varSL = (gCurrentPinballGame->projectileFlightTimer % 8) / 4 + gCurrentPinballGame->projectileDirection * 2;
                if (squaredMagnitude <= 240 && gCurrentPinballGame->ballRespawnState == 0 && gCurrentPinballGame->ballGrabTimer < 600)
                {
                    MPlayStart(&gMPlayInfo_SE1, &se_unk_11f);
                    gCurrentPinballGame->projectileFlightTimer = 10;
                    gMain.spriteGroups[24].available = 1;
                    gCurrentPinballGame->ballGrabTimer = 612;
                    PlayRumble(9);
                }

                gCurrentPinballGame->projectilePosition.x += (Cos(gCurrentPinballGame->projectileAngle) *  40) / 20000;
                gCurrentPinballGame->projectilePosition.y += (Sin(gCurrentPinballGame->projectileAngle) * -40) / 20000;

            }
            else
            {
                varSL = (gCurrentPinballGame->projectileDirection * 2) - ((gCurrentPinballGame->projectileFlightTimer / 5) - 7);
                if (gCurrentPinballGame->projectileFlightTimer == 9)
                {
                    if (squaredMagnitude <= 240)
                    {
                        gCurrentPinballGame->projectilePosition.x = (gCurrentPinballGame->ball->positionQ0.x + 4) * 10;
                        gCurrentPinballGame->projectilePosition.y = (gCurrentPinballGame->ball->positionQ0.y + 14) * 10;
                    }
                    else
                    {
                        if (gCurrentPinballGame->projectileDirection == 0)
                        {
                            gCurrentPinballGame->projectilePosition.x += 0;
                            gCurrentPinballGame->projectilePosition.y += 240;
                        }
                        else if (gCurrentPinballGame->projectileDirection == 1)
                        {
                            gCurrentPinballGame->projectilePosition.x -= 120;
                            gCurrentPinballGame->projectilePosition.y += 240;
                        }
                        else
                        {
                            gCurrentPinballGame->projectilePosition.x += 120;
                            gCurrentPinballGame->projectilePosition.y += 240;
                        }
                    }

                    m4aSongNumStart(SE_UNKNOWN_0x120);
                }
            }

            if (gCurrentPinballGame->projectileFlightTimer == 0)
                gMain.spriteGroups[22].available = 0;
        }

        group->baseX = gCurrentPinballGame->projectilePosition.x / 10 - gCurrentPinballGame->cameraXOffset - 12;
        group->baseY = gCurrentPinballGame->projectilePosition.y / 10 - gCurrentPinballGame->cameraYOffset - 22;
        for (j = 0; j < 4; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gGroudonProjectileOamData[varSL][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->captureState == 2)
        {
            gMain.spriteGroups[22].available = 0;
            gCurrentPinballGame->projectileFlightTimer = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        if (group->available)
        {
            switch (gCurrentPinballGame->boulderState[i])
            {
            case 0:
                gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i];
                gCurrentPinballGame->boulderGroundPosition[i].x = (((Random() % 101) * 145) / 100 + 30) * 10;
                gCurrentPinballGame->boulderPositionIndex[i] = Random() % 16;
                if (gCurrentPinballGame->boulderPositionIndex[i] == gCurrentPinballGame->boulderPositionIndex[(i + 1) % 3])
                    gCurrentPinballGame->boulderPositionIndex[i] = (gCurrentPinballGame->boulderPositionIndex[i] + 1) % 16;

                if (gCurrentPinballGame->boulderPositionIndex[i] == gCurrentPinballGame->boulderPositionIndex[(i + 2) % 3])
                    gCurrentPinballGame->boulderPositionIndex[i] = (gCurrentPinballGame->boulderPositionIndex[i] + 1) % 16;

                gCurrentPinballGame->boulderGroundPosition[i].x = gGroudonBoulderPositionTable[gCurrentPinballGame->boulderPositionIndex[i]][0] * 10;
                gCurrentPinballGame->boulderGroundPosition[i].y = gGroudonBoulderPositionTable[gCurrentPinballGame->boulderPositionIndex[i]][1] * 10;
                gCurrentPinballGame->boulderFallHeight[i] = -1200;
                gCurrentPinballGame->boulderFallVelocity[i] = 0;
                gCurrentPinballGame->boulderState[i] = 1;
                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                gCurrentPinballGame->boulderHitFlag[i] = 0;
                break;
            case 1:
                if (gCurrentPinballGame->boulderFallHeight[i] < 0) {
                    gCurrentPinballGame->boulderFallVelocity[i] += 3;
                    gCurrentPinballGame->boulderFallHeight[i] += gCurrentPinballGame->boulderFallVelocity[i];
                    if (gCurrentPinballGame->boulderFallHeight[i] > 0) {
                        gCurrentPinballGame->boulderFallHeight[i] = 0;
                    }
                }

                if (gCurrentPinballGame->boulderFallHeight[i] >= 0)
                {
                    if (gCurrentPinballGame->boulderAnimTimer[i] == 0)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->boulderAnimTimer[i] < 5)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 1;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 10)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 2;
                    }
                    else
                    {
                        gCurrentPinballGame->boulderAnimTimer[i] = 0;
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i];
                        gCurrentPinballGame->boulderState[i] = 2;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }

                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                break;
            case 2:
                gCurrentPinballGame->boulderCollisionPos[i].x = (gCurrentPinballGame->boulderGroundPosition[i].x / 10) * 2;
                gCurrentPinballGame->boulderCollisionPos[i].y = (gCurrentPinballGame->boulderGroundPosition[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->boulderHitFlag[i])
                {
                    if (gCurrentPinballGame->boulderAnimTimer[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->boulderAnimTimer[i] < 5)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 3;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 10)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 4;
                    }
                    else
                    {
                        gCurrentPinballGame->boulderAnimTimer[i] = 0;
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 5;
                        gCurrentPinballGame->boulderState[i] = 3;
                        gCurrentPinballGame->boulderHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case 3:
                gCurrentPinballGame->boulderCollisionPos[i].x = (gCurrentPinballGame->boulderGroundPosition[i].x / 10) * 2;
                gCurrentPinballGame->boulderCollisionPos[i].y = (gCurrentPinballGame->boulderGroundPosition[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->boulderHitFlag[i])
                {
                    if (gCurrentPinballGame->boulderAnimTimer[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->boulderAnimTimer[i] < 5)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 6;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 10)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 7;
                    }
                    else
                    {
                        gCurrentPinballGame->boulderAnimTimer[i] = 0;
                        gCurrentPinballGame->boulderSpriteFrame[i] = gGroudonBoulderBaseSpriteIndices[i] + 8;
                        gCurrentPinballGame->boulderState[i] = 4;
                        gCurrentPinballGame->boulderHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case 4:
                gCurrentPinballGame->boulderCollisionPos[i].x = (gCurrentPinballGame->boulderGroundPosition[i].x / 10) * 2;
                gCurrentPinballGame->boulderCollisionPos[i].y = (gCurrentPinballGame->boulderGroundPosition[i].y / 10) * 2 + 8;
                if (gCurrentPinballGame->boulderHitFlag[i])
                {
                    if (gCurrentPinballGame->boulderAnimTimer[i] == 1)
                    {
                        m4aSongNumStart(SE_GROUDON_BOULDER_LAND);
                        PlayRumble(7);
                    }

                    if (gCurrentPinballGame->boulderAnimTimer[i] < 3)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = 9;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 8)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = 10;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 14)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = 11;
                    }
                    else if (gCurrentPinballGame->boulderAnimTimer[i] < 23)
                    {
                        gCurrentPinballGame->boulderSpriteFrame[i] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->boulderAnimTimer[i] = 0;
                        gCurrentPinballGame->boulderSpriteFrame[i] = 12;
                        gCurrentPinballGame->boulderState[i] = 5;
                        gCurrentPinballGame->boulderHitFlag[i] = 0;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case 5:
                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                gMain.spriteGroups[15 + i].available = 0;
                break;
            }

            var0 = gCurrentPinballGame->boulderSpriteFrame[i];
            DmaCopy16(3, gGroudonBoulderSpriteFrames[var0], (void *)0x06010FA0 + i * 0x300, 0x300);

            group->baseX = (gCurrentPinballGame->boulderGroundPosition[i].x / 10) + i - gCurrentPinballGame->cameraXOffset;
            group->baseY = (gCurrentPinballGame->boulderFallHeight[i] / 10) + (gCurrentPinballGame->boulderGroundPosition[i].y / 10) - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->boulderState[i] >= 2 && gCurrentPinballGame->boulderState[i] < 5)
            {
                if (gGroudonBoulderPositionTable[gCurrentPinballGame->boulderPositionIndex[i]][2] == gCurrentPinballGame->shockwaveAnimTimer)
                {
                    gCurrentPinballGame->boulderState[i] = 4;
                    gCurrentPinballGame->boulderHitFlag[i] = 1;
                    gCurrentPinballGame->boulderAnimTimer[i] = 0;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[18 + i];
        if (group->available)
        {
            switch(gCurrentPinballGame->firePillarState[i])
            {
            case 0:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 0;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 8;
                gCurrentPinballGame->firePillarNextState[i] = 1;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 0;
                break;
            case 1:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 8;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 12;
                gCurrentPinballGame->firePillarNextState[i] = 3;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = 2;
                break;
            case 2:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = 3;
                        PlayRumble(7);
                    }
                }
                break;
            case 3:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 12;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 16;
                gCurrentPinballGame->firePillarNextState[i] = 5;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = 4;
                break;
            case 4:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = 5;
                        PlayRumble(7);
                    }
                }
                break;
            case 5:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 16;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 20;
                gCurrentPinballGame->firePillarNextState[i] = 7;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = 6;
                break;
            case 6:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = 7;
                        PlayRumble(7);
                    }
                }
                break;
            case 7:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 20;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 24;
                gCurrentPinballGame->firePillarNextState[i] = 9;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = 8;
                gCurrentPinballGame->firePillarExtraHitCount[i] = 0;
                break;
            case 8:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        if (gCurrentPinballGame->firePillarExtraHitCount[i] <= 0)
                        {
                            gCurrentPinballGame->firePillarExtraHitCount[i]++;
                        }
                        else
                        {
                            gCurrentPinballGame->firePillarExtraHitCount[i] = 0;
                            gCurrentPinballGame->firePillarState[i] = 9;
                        }

                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        PlayRumble(7);
                    }
                }
                break;
            case 9:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 24;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 27;
                gCurrentPinballGame->firePillarNextState[i] = 10;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 0;
                break;
            case 10:
                gMain.spriteGroups[18 + i].available = 0;
                break;
            }

            if (gGroudonFirePillarAnimFrameset[gCurrentPinballGame->firePillarAnimFrame[i]][1] > gCurrentPinballGame->firePillarFrameTimer[i])
            {
                gCurrentPinballGame->firePillarFrameTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->firePillarFrameTimer[i] = 0;
                gCurrentPinballGame->firePillarAnimFrame[i]++;
                if (gCurrentPinballGame->firePillarAnimFrame[i] == gCurrentPinballGame->firePillarAnimEndFrame[i])
                {
                    if (gCurrentPinballGame->firePillarAnimLoopCount[i] > 0)
                    {
                        gCurrentPinballGame->firePillarAnimFrame[i] = gCurrentPinballGame->firePillarAnimStartFrame[i];
                        gCurrentPinballGame->firePillarAnimLoopCount[i]--;
                    }
                    else
                    {
                        gCurrentPinballGame->firePillarAnimFrame[i] = gCurrentPinballGame->firePillarAnimEndFrame[i] - 1;
                        gCurrentPinballGame->firePillarState[i] = gCurrentPinballGame->firePillarNextState[i];
                    }
                }
            }

            varSL = gGroudonFirePillarAnimFrameset[gCurrentPinballGame->firePillarAnimFrame[i]][0];
            // Unsigned integers for matching
            group->baseX = gGroudonFirePillarBasePositions[i].x + 65u - gCurrentPinballGame->cameraXOffset;
            group->baseY = gGroudonFirePillarBasePositions[i].y + 60u - gCurrentPinballGame->cameraYOffset;
            if (gCurrentPinballGame->firePillarState[i] < 9)
            {
                gCurrentPinballGame->firePillarCollisionPos[i].x = (gGroudonFirePillarBasePositions[i].x + 61) * 2;
                gCurrentPinballGame->firePillarCollisionPos[i].y = (gGroudonFirePillarBasePositions[i].y + 96) * 2;
            }

            if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
            {
                for (j = 0; j < 10; j++)
                {
                    oamSimple = &group->oam[j];
                    dst = (u16*)&gOamBuffer[oamSimple->oamId];
                    src = gGroudonFirePillarOamData[varSL][j];
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
                    src = gGroudonFirePillarOamData[varSL][j];
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
            gCurrentPinballGame->firePillarCollisionPos[i].x = 0;
            gCurrentPinballGame->firePillarCollisionPos[i].y = 0;
        }
    }

    if (gCurrentPinballGame->firePillarSpawnSfxTimer)
    {
        gCurrentPinballGame->firePillarSpawnSfxTimer--;
        if (gCurrentPinballGame->firePillarSpawnSfxTimer == 36)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->firePillarSpawnSfxTimer == 24)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->firePillarSpawnSfxTimer == 12)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);

        if (gCurrentPinballGame->firePillarSpawnSfxTimer == 0)
            m4aSongNumStart(SE_GROUDON_DUSTORM_LIFT);
    }

    group = &gMain.spriteGroups[30];
    if (group->available)
    {
        s16 scale;
        s16 var6;
        if (gCurrentPinballGame->shockwaveAnimTimer <= 35)
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

        if (gCurrentPinballGame->shockwaveAnimTimer == 34)
        {
            for (i = 0; i < 4; i++)
            {
                gMain.spriteGroups[i + 18].available = 1;
                gCurrentPinballGame->firePillarState[i] = 0;
                gCurrentPinballGame->firePillarAnimFrame[i] = 0;
                gCurrentPinballGame->firePillarFrameTimer[i] = 0;
            }

            gCurrentPinballGame->firePillarSpawnSfxTimer = 37;
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
            group->baseY = 50 - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX + gCurrentPinballGame->shockwaveQuadrantOffset[j].x;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY + gCurrentPinballGame->shockwaveQuadrantOffset[j].y;
                gOamBuffer[oamSimple->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamSimple->oamId].matrixNum = 1 + j;
            }
        }

        if (gCurrentPinballGame->shockwaveAnimTimer < 30)
        {
            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - 119;
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - 147;
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredMagnitude = xx + yy;
            if (gCurrentPinballGame->ballRespawnState == 0 && squaredMagnitude < gShockwaveSplashDistanceThresholds[gCurrentPinballGame->shockwaveAnimTimer])
            {
                gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);
                gCurrentPinballGame->ball->velocity.x = (Cos(gCurrentPinballGame->trapAngleQ16) * -400) / 20000;
                gCurrentPinballGame->ball->velocity.y = (Sin(gCurrentPinballGame->trapAngleQ16) *  400) / 20000;
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

void AnimateGroudonBackground(void)
{
    s16 i, j;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = gGroudonLavaPaletteAnimIndices[(gMain.systemFrameCount % 144) / 24];
    DmaCopy16(3, &gGroudonLavaPaletteCycleData[var0 * 0x20], (void *)0x05000000, 0x20);
    DmaCopy16(3, &gGroudonLavaPaletteCycleData[(var0 + 4) * 0x20], (void *)0x05000080, 0x20);

    var0 = gGroudonBgTileAnimIndices[(gMain.systemFrameCount % 96) / 24];
    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[11 + i];
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 128 - gCurrentPinballGame->cameraYOffset;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = gGroudonBgSpriteBaseTileNums[j] + var0 * 8;
        }
    }
}