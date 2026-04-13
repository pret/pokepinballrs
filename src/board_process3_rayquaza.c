#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"

extern const s16 gWhirlwindGrabAnimFrameIndices[];
extern const u8 gRayquazaBonusClear_Gfx[];
extern const u8 gRayquazaSkyBackgroundGfx[];
extern const u8 gRayquazaMinionOrbFrames[][0x280];
extern const u8 gRayquazaWindBoardGfx[];
extern const u8 gRayquazaSpriteSheet[];
extern const u8 gRayquazaBodyVariantTiles[][0x800];
extern const s16 gScreenShakeOscillationValues[];
extern const u16 gRayquazaAnimFramesetTable[][3];
extern const struct Vector16 gRayquazaMinionOrbitWaypoints[32];
extern const s16 gRayquazaCloudScrollPositions[];
extern const u16 gRayquazaNeckSegmentOamData[39][6][3];
extern const u16 gRayquazaHitBurstOamData[10][5][3];
extern const u16 gRayquazaWhirlwindGrabOamData[20][2][3];
extern const u16 gRayquazaSwoopAttackOamData[12][7][3];
extern const u16 gRayquazaHeadOamData[10][3][3];
extern const u16 gRayquazaMainBodyOamData[212][3];

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

    gCurrentPinballGame->boardModeType = 0;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + 10800;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnState = 3;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = 1;
    gCurrentPinballGame->cameraYAdjust = -88;
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    gCurrentPinballGame->portraitDisplayState = 3;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballGrabbed = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->rayquazaOrbAngle = 0;
    gCurrentPinballGame->bossRenderOffsetY = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionLogicPosition[i].x = 0;
        gCurrentPinballGame->minionLogicPosition[i].y = 0;
    }

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
    gCurrentPinballGame->orbLogicPosition.x = 0;
    gCurrentPinballGame->orbLogicPosition.y = 0;
    gCurrentPinballGame->orbCollisionPosition.x = 0;
    gCurrentPinballGame->orbCollisionPosition.y = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;

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

    gCurrentPinballGame->impactShakeTimer = 0;
    gCurrentPinballGame->ballGrabShakeTimer = 0;
    gCurrentPinballGame->ballGrabFlashTimer = 0;
    gCurrentPinballGame->ballGrabTimer = 0;
    gCurrentPinballGame->windAttackCount = 0;
    gCurrentPinballGame->orbHitIndex = 0;
    gCurrentPinballGame->introSequencePhase = 0;
    gCurrentPinballGame->swoopAttackState = 0;
    gCurrentPinballGame->horizontalShakeTimer = 0;
    gCurrentPinballGame->roarBrightnessFlashTimer = 0;
    gCurrentPinballGame->bossInvulnTimer = 0;
    gCurrentPinballGame->hitBurstAnimFrame = 0;
    gCurrentPinballGame->swoopAttackAnimFrame = 0;
    gCurrentPinballGame->bossSineAngle = 0;
    gCurrentPinballGame->windCloudSpawnTimer = 0;
    gCurrentPinballGame->introFrameCounter = 0;
    gCurrentPinballGame->bgScrollSpeed = 0;
    gCurrentPinballGame->bossHeadScreenY = 0;
    gCurrentPinballGame->swoopTargetPosition.x = 0;
    gCurrentPinballGame->swoopTargetPosition.y = 0;
    gCurrentPinballGame->orbHitPosition.x = 0;
    gCurrentPinballGame->orbHitPosition.y = 0;
    gCurrentPinballGame->windEntityPosition.x = 0;
    gCurrentPinballGame->windEntityPosition.y = 0;
    gCurrentPinballGame->windCloudPosition.x = 0;
    gCurrentPinballGame->windCloudPosition.y = 0;
    gCurrentPinballGame->flippersDisabled = 1;
    UpdateRayquazaIntroSequence();
    DmaCopy16(3, gRayquazaSkyBackgroundGfx, (void *)0x06015800, 0x2800);
    DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x06011620, 0x860);
    UpdateRayquazaEntityLogic();
    RenderRayquazaSprites();
    DmaCopy16(3, gBonusStageObjPal, (void *)0x05000320, 0x20);
}

void RayquazaBoardProcess_3B_3EB2C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case 0:
        gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
        if (gCurrentPinballGame->introSequencePhase == 1)
        {
            gCurrentPinballGame->cameraYAdjust = 0;
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
        gCurrentPinballGame->bannerSlideYOffset = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gCurrentPinballGame->boardEntityActive = 1;
        break;
    case 3:
        ProcessBonusBannerAndScoring();
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

        gCurrentPinballGame->boardEntityActive = 1;
        break;
    case 4:
        gCurrentPinballGame->boardState = 5;
        gCurrentPinballGame->stageTimer = 140;
        gMain.spriteGroups[6].available = 1;
        gMain.spriteGroups[5].available = 1;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->shopBonusStageAlreadyBought = 0;
        }
        break;
    case 6:
        ProcessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = 1;
        gCurrentPinballGame->boardEntityActive = 1;
        break;
    }

    UpdateRayquazaIntroSequence();
    UpdateRayquazaMinionsAndEffects();
    UpdateRayquazaEntityLogic();
    RenderRayquazaSprites();
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

void UpdateRayquazaEntityLogic(void)
{
    if (gCurrentPinballGame->bossHitFlashTimer)
    {
        gCurrentPinballGame->bossHitFlashTimer--;
        gCurrentPinballGame->legendaryFlashState = 1;
        if (gCurrentPinballGame->bossHitFlashTimer == 5)
        {
            m4aSongNumStart(SE_RAYQUAZA_HIT);
            gCurrentPinballGame->scoreAddedInFrame = 1000000;
            gCurrentPinballGame->bonusModeHitCount++;
            PlayRumble(7);
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired && gCurrentPinballGame->bossEntityState != 6)
                gCurrentPinballGame->bossEntityState = 9;
        }

        gCurrentPinballGame->bossInvulnTimer = 20;
        if (gCurrentPinballGame->bossHitFlashTimer == 0)
            gCurrentPinballGame->legendaryFlashState = 0;
    }

    if (gCurrentPinballGame->bossInvulnTimer)
    {
        gCurrentPinballGame->bossInvulnTimer--;
        gCurrentPinballGame->boardEntityCollisionMode = 0;
    }
    else
    {
        gCurrentPinballGame->boardEntityCollisionMode = 1;
    }

    switch (gCurrentPinballGame->bossEntityState)
    {
    case 0:
        gCurrentPinballGame->bossPositionX = 1140;
        gCurrentPinballGame->bossPositionY = 2400;
        gCurrentPinballGame->bossEntityState = 1;
        gCurrentPinballGame->bossFramesetIndex = 13;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossHeadScreenY = 0;
        break;
    case 1:
        if (gCurrentPinballGame->introFrameCounter > 530)
        {
            if (gCurrentPinballGame->bossPositionY > -1200)
                gCurrentPinballGame->bossPositionY -= 70;

            if (gCurrentPinballGame->introFrameCounter == 672)
            {
                gCurrentPinballGame->bossEntityState = 2;
                gCurrentPinballGame->bossPositionX = 0;
                gCurrentPinballGame->bossPositionY = -640;
            }
        }

        if (gCurrentPinballGame->introFrameCounter == 530)
            gCurrentPinballGame->bossRoarTimer = 25;
        break;
    case 2:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 63)
                gCurrentPinballGame->bossFramesetIndex = 13;
        }

        if (gCurrentPinballGame->bossPositionY < 0)
        {
            gCurrentPinballGame->bossPositionY += 18;
            if (gCurrentPinballGame->bossPositionY > 0)
            {
                gCurrentPinballGame->bossPositionY = 0;
                m4aSongNumStart(MUS_BONUS_FIELD_RAYQUAZA);
            }
        }

        if (gCurrentPinballGame->bossPositionY == 0)
        {
            gCurrentPinballGame->bossEntityState = 5;
            gCurrentPinballGame->bossMovementPhase = 0;
            gCurrentPinballGame->bossAttackPhase = 6;
        }
        break;
    case 3:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 63)
                gCurrentPinballGame->bossFramesetIndex = 13;
        }

        if (gCurrentPinballGame->bossPositionY < 0)
        {
            gCurrentPinballGame->bossPositionY += 18;
            if (gCurrentPinballGame->bossPositionY > 0)
                gCurrentPinballGame->bossPositionY = 0;
        }

        if (gCurrentPinballGame->bossPositionY == 0)
        {
            gCurrentPinballGame->bossEntityState = 5;
            gCurrentPinballGame->bossMovementPhase = 0;
            gCurrentPinballGame->bossAttackPhase = 6;
        }
        break;
    case 4:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 34)
                gCurrentPinballGame->bossFramesetIndex = 33;
        }

        if (gCurrentPinballGame->bossFramesetIndex == 33 && gCurrentPinballGame->bossPositionY > -0x300)
        {
            gCurrentPinballGame->bossPositionY -= 0x18;
            if (gCurrentPinballGame->bossPositionY < -0x300)
                gCurrentPinballGame->bossPositionY = -0x300;
        }

        if (gCurrentPinballGame->bossPositionY == -0x300)
        {
            gCurrentPinballGame->bossFramesetIndex = 0;
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossEntityState = 7;
            gCurrentPinballGame->bossMovementPhase = 0;
        }
        break;
    case 5:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 63)
            {
                if (gCurrentPinballGame->bossMovementPhase < 6)
                {
                    gCurrentPinballGame->bossFramesetIndex = 13;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else if (gCurrentPinballGame->bossAttackPhase == 6)
                {
                    if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired - 1)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 13;
                        gCurrentPinballGame->bossEntityState = 4;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 98;
                        gCurrentPinballGame->bossEntityState = 6;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 13;
                    gCurrentPinballGame->bossEntityState = 4;
                    gCurrentPinballGame->bossMovementPhase = 0;
                }
            }
        }

        if (gCurrentPinballGame->bossMovementPhase > 1)
        {
            gCurrentPinballGame->bossSineAngle += 0x80;
            gCurrentPinballGame->bossPositionX = ((Sin(gCurrentPinballGame->bossSineAngle) * 62) / 20000) * 10;
        }
        break;
    case 6:
        gCurrentPinballGame->legendaryFlashState = 2;
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 116 && gCurrentPinballGame->bossMovementPhase < 15)
            {
                gCurrentPinballGame->bossMovementPhase++;
                gCurrentPinballGame->bossFramesetIndex = 114;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 131)
            {
                gCurrentPinballGame->bossFramesetIndex = 29;
                gCurrentPinballGame->bossMovementPhase = 0;
                gCurrentPinballGame->bossEntityState = 5;
                gCurrentPinballGame->bossAttackPhase = 4;
                gCurrentPinballGame->legendaryFlashState = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 114)
            {
                if (gCurrentPinballGame->bossMovementPhase == 0)
                {
                    gMain.spriteGroups[17].available = 1;
                    gMain.spriteGroups[18].available = 1;
                    gMain.spriteGroups[19].available = 1;
                    gCurrentPinballGame->swoopAttackState = 1;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 120)
                gCurrentPinballGame->bossRoarTimer = 21;

            if (gCurrentPinballGame->bossFramesetIndex == 124)
                gCurrentPinballGame->roarBrightnessFlashTimer = 16;
        }
        break;
    case 7:
        if (gCurrentPinballGame->bossFrameTimer < 120)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossEntityState = 8;
            DmaCopy16(3, gRayquazaWindBoardGfx, (void *)0x06015800, 0x1C00);
            if (gCurrentPinballGame->windAttackCount & 1)
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

            gCurrentPinballGame->windAttackCount++;
            gCurrentPinballGame->windEntityPosition.x = 0;
            gCurrentPinballGame->windEntityPosition.y = 0;
            gCurrentPinballGame->windCloudPosition.x = 0;
            gCurrentPinballGame->windCloudPosition.y = 0;
            gCurrentPinballGame->windCloudSpawnTimer = 0;
            gCurrentPinballGame->bossFrameTimer = 0;
            m4aSongNumStart(SE_RAYQUAZA_WIND);
        }
        break;
    case 8:
        if (gMain.spriteGroups[22].available)
        {
            if (gCurrentPinballGame->windEntityPosition.x < 4800)
                gCurrentPinballGame->windEntityPosition.x += 140;
            else
                gMain.spriteGroups[22].available = 0;

            if (gCurrentPinballGame->windEntityPosition.x > 2400)
            {
                if (gCurrentPinballGame->windCloudPosition.x < 4960)
                    gCurrentPinballGame->windCloudPosition.x += 200;

                gCurrentPinballGame->windCloudSpawnTimer++;
            }
        }
        else
        {
            if (gCurrentPinballGame->windEntityPosition.x > -4800)
                gCurrentPinballGame->windEntityPosition.x -= 140;
            else
                gMain.spriteGroups[23].available = 0;

            if (gCurrentPinballGame->windEntityPosition.x < -2400)
            {
                if (gCurrentPinballGame->windCloudPosition.x > -4960)
                    gCurrentPinballGame->windCloudPosition.x -= 200;

                gCurrentPinballGame->windCloudSpawnTimer++;
            }
        }

        if (gCurrentPinballGame->bossFrameTimer == 20)
            gCurrentPinballGame->impactShakeTimer = 60;

        gCurrentPinballGame->bossFrameTimer++;
        if (gCurrentPinballGame->bossFrameTimer >= 200)
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex = 13;
            gCurrentPinballGame->bossEntityState = 3;
        }
        break;
    case 9:
        gCurrentPinballGame->boardModeType = 3;
        if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        {
            // Catch Rayquaza
            gCurrentPinballGame->bossEntityState = 14;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[10].available = 1;
            gMain.spriteGroups[9].available = 1;
            gCurrentPinballGame->currentSpecies = SPECIES_RAYQUAZA;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = 2;
        }
        else
        {
            // Normal Completion
            gCurrentPinballGame->bossEntityState = 10;
            gCurrentPinballGame->bossFramesetIndex = 98;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = 2;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        gCurrentPinballGame->bossFrameTimer = 0;
        if (gMain.spriteGroups[36].available)
            gCurrentPinballGame->ballGrabTimer = 1;
        break;
    case 10:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 131)
            {
                gCurrentPinballGame->bossFramesetIndex = 13;
                gCurrentPinballGame->bossMovementPhase = 0;
                gCurrentPinballGame->bossEntityState = 11;
                gCurrentPinballGame->legendaryFlashState = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 120)
                gCurrentPinballGame->bossRoarTimer = 21;
        }
        break;
    case 11:
        if (gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == 34)
                gCurrentPinballGame->bossFramesetIndex = 33;
        }
            if (gCurrentPinballGame->bossFramesetIndex == 33)
            {
                if (gCurrentPinballGame->bossPositionY > -0x300)
                {
                    gCurrentPinballGame->bossPositionY -= 0x18;
                    if (gCurrentPinballGame->bossPositionY < -0x300)
                        gCurrentPinballGame->bossPositionY = -0x300;
                }
            }

            if (gCurrentPinballGame->bossPositionY == -0x300)
            {
                gCurrentPinballGame->bossFramesetIndex = 0;
                gCurrentPinballGame->bossFrameTimer = 0;
                gCurrentPinballGame->bossEntityState = 12;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

        break;
    case 12:
        DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x06011620, 0x860);
        gCurrentPinballGame->bossEntityState = 13;
        gCurrentPinballGame->bossPositionX = 1140;
        gCurrentPinballGame->bossPositionY = -1200;
        gCurrentPinballGame->introSequencePhase = 2;
        gCurrentPinballGame->introFrameCounter = 0;
        gCurrentPinballGame->boardEntityActive = 1;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gMain.spriteGroups[14].available = 1;
        gCurrentPinballGame->minionLogicPosition[0].x = 0;
        gCurrentPinballGame->minionLogicPosition[0].y = -5000;
        gCurrentPinballGame->minionLogicPosition[1].x = 1400;
        gCurrentPinballGame->minionLogicPosition[1].y = -2000;
        gCurrentPinballGame->orbCollisionPosition.x = -200;
        gCurrentPinballGame->orbCollisionPosition.y = 800;
        gCurrentPinballGame->orbLogicPosition.x = 24;
        gCurrentPinballGame->orbLogicPosition.y = -16;
        break;
    case 13:
        if (gCurrentPinballGame->introFrameCounter < 256)
        {
            if (gCurrentPinballGame->bossFrameTimer < 80)
                gCurrentPinballGame->bossFrameTimer++;
            else if (gCurrentPinballGame->bossPositionY < 2400)
                gCurrentPinballGame->bossPositionY += 80;
        }
        else
        {
            gCurrentPinballGame->boardState = 2;
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->bossEntityState = 15;
        }
        break;
    case 14:
        gCurrentPinballGame->bossRenderOffsetY = 1;
        if (gCurrentPinballGame->bossAttackTimer > -500)
        {
            gCurrentPinballGame->bossAttackTimer += (-500 - gCurrentPinballGame->bossAttackTimer) / 30;
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->bossAttackTimer / 10;
            if (gCurrentPinballGame->cameraYAdjust < -38)
                gCurrentPinballGame->cameraYAdjust = -38;
        }
        break;
    case 15:
        break;
    }

    if (gCurrentPinballGame->bossRoarTimer)
    {
        gCurrentPinballGame->bossRoarTimer--;
        if (gCurrentPinballGame->bossRoarTimer == 20)
            PlayCry_Normal(gSpeciesInfo[SPECIES_RAYQUAZA].speciesIdRS, 0);

        if (gCurrentPinballGame->bossRoarTimer == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

void RenderRayquazaSprites(void)
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
        group->baseX = gCurrentPinballGame->bossPositionX / 10;
        group->baseY = gCurrentPinballGame->bossPositionY / 10;
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
        group->baseX = gCurrentPinballGame->bossPositionX / 10;
        group->baseY = gCurrentPinballGame->bossPositionY / 10;
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

        if (gCurrentPinballGame->introFrameCounter == 671)
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
            group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
            group->baseY = gCurrentPinballGame->bossPositionY / 10 - (gCurrentPinballGame->cameraYOffset - 78);
            gCurrentPinballGame->catchTargetX = gCurrentPinballGame->bossPositionX / 10 + 116;
            gCurrentPinballGame->catchTargetY = gCurrentPinballGame->bossPositionY / 10 + 60;
            if (gCurrentPinballGame->bossHeadScreenY > 91)
            {
                gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 172;
                gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 184;
            }
            else
            {
                gCurrentPinballGame->bossCollisionX = 0;
                gCurrentPinballGame->bossCollisionY = -160;
            }

            if (group->baseY < -70)
                group->baseY = -70;
            if (group->baseY > 180)
                group->baseY = 180;

            var1 = gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][0];
            if (gCurrentPinballGame->legendaryFlashState > 9)
            {
                sp0 = 11;
                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = 240;
                gOamBuffer[oamSimple->oamId].y = 180;
                gOamBuffer[oamSimple->oamId].paletteNum = sp0;
            }
            else
            {
                if (gCurrentPinballGame->legendaryFlashState == 1)
                {
                    varSL = 2;
                    sp0 = 14;
                }
                else if (gCurrentPinballGame->legendaryFlashState == 3)
                {
                    varSL = 2;
                    sp0 = 11;
                }
                else
                {
                    varSL = gCurrentPinballGame->bossVulnerable;
                    sp0 = 15;
                }

                if (gCurrentPinballGame->captureSequenceTimer == 21)
                    varSL = 8;

                if (gCurrentPinballGame->captureSequenceTimer == 22)
                    varSL = 9;

                oamSimple = &group->oam[0];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gRayquazaMainBodyOamData[var1];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                y = gOamBuffer[oamSimple->oamId].y;
                gCurrentPinballGame->bossHeadScreenY = (y + 78u) + (gCurrentPinballGame->bossPositionY / 10);
                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
                if (gCurrentPinballGame->legendaryFlashState < 2)
                    gOamBuffer[oamSimple->oamId].paletteNum = sp0;
                else
                    sp0 = gOamBuffer[oamSimple->oamId].paletteNum;
            }

            gCurrentPinballGame->bossVulnerable = gRayquazaAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][2];
            DmaCopy16(3, gRayquazaBodyVariantTiles[varSL], (void *)0x06011620, 0x800);
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
                group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
                group->baseY = gCurrentPinballGame->bossPositionY / 10 - gCurrentPinballGame->cameraYOffset + 96;
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
            s16 var2 = (gCurrentPinballGame->bossHeadScreenY - 70) / 3 + 1;
            if (var2 < 0)
                var2 = 0;
            else if (var2 > 9)
                var2 = 9;

            if (gCurrentPinballGame->bossEntityState != 14)
            {
                if (gCurrentPinballGame->roarBrightnessFlashTimer > 0)
                {
                    gMain.blendControl = 0x9E;
                    gMain.blendBrightness = gCurrentPinballGame->roarBrightnessFlashTimer;
                    gCurrentPinballGame->roarBrightnessFlashTimer--;
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

            group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
            group->baseY = gCurrentPinballGame->bossPositionY / 10 - (gCurrentPinballGame->cameraYOffset - 78) + 36 + var2;
            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

            if (gCurrentPinballGame->bossEntityState == 12)
            {
                gMain.spriteGroups[43].available = 1;
                gMain.spriteGroups[41].available = 0;
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }

            if (gCurrentPinballGame->captureSequenceTimer == 21)
            {
                gMain.spriteGroups[45].available = 0;
                gMain.spriteGroups[21].available = 0;
            }
        }
    }
}

void UpdateRayquazaMinionsAndEffects(void)
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

    UpdateWhirlwindGrabEntity();
    switch (gCurrentPinballGame->swoopAttackState)
    {
    case 0:
        gCurrentPinballGame->swoopAttackAnimFrame = 0;
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        break;
    case 1:
        if (gCurrentPinballGame->swoopAttackAnimFrame == 0)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame == 8)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame == 24)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame == 36)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame == 50)
            m4aSongNumStart(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame == 56)
            m4aSongNumStop(SE_UNKNOWN_0x128);

        if (gCurrentPinballGame->swoopAttackAnimFrame < 14)
            var0 = gCurrentPinballGame->swoopAttackAnimFrame / 2;
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 42)
            var0 = 7;
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 56)
            var0 = (gCurrentPinballGame->swoopAttackAnimFrame - 42) / 2;
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 61)
            var0 = 7;
        else
            var0 = (gCurrentPinballGame->swoopAttackAnimFrame - 61) / 2;

        if (gCurrentPinballGame->swoopAttackAnimFrame < 8)
            sp4 = gCurrentPinballGame->swoopAttackAnimFrame / 2;
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 48)
            sp4 = 12;
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 64)
            sp4 = (gCurrentPinballGame->swoopAttackAnimFrame - 48) / 2 + 4;
        else
            sp4 = 12;

        sp8 = 5;
        gCurrentPinballGame->swoopAttackAnimFrame++;
        if (gCurrentPinballGame->swoopAttackAnimFrame == 75)
        {
            gCurrentPinballGame->swoopAttackAnimFrame = 0;
            gCurrentPinballGame->swoopAttackState = 2;
        }
        break;
    case 2:
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        if (gCurrentPinballGame->swoopAttackAnimFrame < 34)
        {
            gCurrentPinballGame->swoopAttackAnimFrame++;
            if (gCurrentPinballGame->swoopAttackAnimFrame == 28)
            {
                if (gCurrentPinballGame->ballRespawnState)
                {
                    gCurrentPinballGame->swoopTargetPosition.x = 200 - (Random() % 160);
                    gCurrentPinballGame->swoopTargetPosition.y = gCurrentPinballGame->ball->positionQ0.y - 347 - (Random() % 80);
                }
                else
                {
                    gCurrentPinballGame->swoopTargetPosition.x = gCurrentPinballGame->ball->positionQ0.x - 13;
                    gCurrentPinballGame->swoopTargetPosition.y = gCurrentPinballGame->ball->positionQ0.y - 347;
                }
            }
        }
        else
        {
            gCurrentPinballGame->swoopAttackAnimFrame = 0;
            gCurrentPinballGame->swoopAttackState = 3;
            m4aSongNumStart(SE_RAYQUAZA_FLYBY);
        }
        break;
    case 3:
        var0 = 7;
        sp4 = 12;
        if (gCurrentPinballGame->swoopAttackAnimFrame < 2)
        {
            sp8 = gCurrentPinballGame->swoopAttackAnimFrame;
        }
        else if (gCurrentPinballGame->swoopAttackAnimFrame < 10)
        {
            sp8 = (gCurrentPinballGame->swoopAttackAnimFrame - 2) / 2 + 2;
            gCurrentPinballGame->horizontalShakeTimer = sp4;
            if (sp8 == 2)
            {
                int a = 13;
                int b = 347;
                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - a - gCurrentPinballGame->swoopTargetPosition.x;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - b - gCurrentPinballGame->swoopTargetPosition.y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;

                PlayRumble(8);
                if (gCurrentPinballGame->orbEntityState[0] < 3 && gCurrentPinballGame->orbEntityState[1] < 3 &&
                    gCurrentPinballGame->ballRespawnState == 0 && squaredMagnitude < 200)
                {
                    gMain.spriteGroups[36].available = 1;
                    gCurrentPinballGame->ballGrabTimer = 600;
                    m4aSongNumStart(SE_UNKNOWN_0x12A);
                    PlayRumble(9);
                }
            }
        }
        else
        {
            sp8 = 5;
            gCurrentPinballGame->swoopAttackState = 4;
        }

        gCurrentPinballGame->swoopAttackAnimFrame++;
        break;
    case 4:
        gCurrentPinballGame->swoopAttackAnimFrame = 0;
        gCurrentPinballGame->swoopAttackState = 0;
        break;
    }

    group = &gMain.spriteGroups[17];
    if (group->available)
    {
        // ! odd behavior in the assembly with the addition and subtraction
        group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
        group->baseY = gCurrentPinballGame->bossPositionY / 10 - gCurrentPinballGame->cameraYOffset + 96;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaHeadOamData[var0][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->swoopAttackState == 4)
            gMain.spriteGroups[17].available = 0;
    }

    group = &gMain.spriteGroups[18];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
        group->baseY = gCurrentPinballGame->bossPositionY / 10 - gCurrentPinballGame->cameraYOffset + 96;
        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaNeckSegmentOamData[sp4][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->swoopAttackState == 4)
            gMain.spriteGroups[18].available = 0;
    }

    group = &gMain.spriteGroups[19];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->swoopTargetPosition.x - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->swoopTargetPosition.y - gCurrentPinballGame->cameraYOffset;
        for (j = 0; j < 7; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaSwoopAttackOamData[sp8][j];
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

        if (gCurrentPinballGame->swoopAttackState == 4)
            gMain.spriteGroups[19].available = 0;
    }

    group = &gMain.spriteGroups[22];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->windEntityPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 120);
        group->baseY = gCurrentPinballGame->windEntityPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 128);
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
        group->baseX = gCurrentPinballGame->windEntityPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 360);
        group->baseY = gCurrentPinballGame->windEntityPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 128);
        for (j = 0; j < 18; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->bossRenderOffsetY > 0)
        gCurrentPinballGame->ball->oamPriority = 1;
    else
        gCurrentPinballGame->ball->oamPriority = 2;

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[15 + i];
        switch (gCurrentPinballGame->orbEntityState[i])
        {
        case 0:
            sp0 = 0;
            gCurrentPinballGame->orbScreenPosition[i].x = 0;
            gCurrentPinballGame->orbScreenPosition[i].y = 0;
            break;
        case 1:
            sp0 = gCurrentPinballGame->orbAnimTimer[i] / 5 + 1;
            if (gCurrentPinballGame->orbAnimTimer[i] < 14)
            {
                gCurrentPinballGame->orbAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->orbAnimTimer[i] = 0;
                gCurrentPinballGame->orbEntityState[i] = 2;
            }
            break;
        case 2:
            sp0 = gCurrentPinballGame->orbAnimTimer[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            if (gCurrentPinballGame->orbEntityState[i] < 3)
            {

                s16 angle = (((gMain.systemFrameCount + 120 * i) % 240) << 0x10) / 240;
                gCurrentPinballGame->orbScreenPosition[i].x = gCurrentPinballGame->orbOrbitCenter[i].x + (Cos(angle) * 4) / 2000;
                gCurrentPinballGame->orbScreenPosition[i].y = gCurrentPinballGame->orbOrbitCenter[i].y + (Sin(angle) * 4) / 2000;

                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->orbScreenPosition[i].x / 10) - 16;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->orbScreenPosition[i].y / 10) - 32;;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredMagnitude = xx + yy;
                if (gCurrentPinballGame->ballGrabbed == 0 && gCurrentPinballGame->ballRespawnState == 0 &&
                    gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired &&
                    gCurrentPinballGame->bossHitFlashTimer == 0 && squaredMagnitude < 300)
                {
                    gCurrentPinballGame->ballGrabTimer = 6;
                    gCurrentPinballGame->ballFrozenState = 1;
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->orbEntityState[i] = 3;
                    gCurrentPinballGame->boardEntityActive = 1;

                    tempVector2.x = gCurrentPinballGame->orbScreenPosition[i].x / 10 + 16;
                    tempVector2.y = gCurrentPinballGame->orbScreenPosition[i].y / 10 + 32;
                    tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                    tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                    gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                    gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
                    gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

                    gCurrentPinballGame->orbHitIndex = i + 1;
                    gCurrentPinballGame->orbHitPosition.x = gCurrentPinballGame->orbScreenPosition[i].x;
                    gCurrentPinballGame->orbHitPosition.y = gCurrentPinballGame->orbScreenPosition[i].y;
                    m4aSongNumStart(SE_UNKNOWN_0x12B);
                    PlayRumble(13);
                }
            }

            if (gCurrentPinballGame->orbAnimTimer[i] < 840)
            {
                gCurrentPinballGame->orbAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->orbAnimTimer[i] = 0;
                gCurrentPinballGame->orbEntityState[i] = 5;
            }
            break;
        case 3: {
            s16 var4;
            int var5;

            sp0 = gCurrentPinballGame->orbAnimTimer[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            var4 = 29 - gCurrentPinballGame->orbAnimTimer[i];
            if (var4 < 10)
                var4 = 10;

            gCurrentPinballGame->trapAngleQ16 -= ((0x2000 - (var4 * 0x2000) / 30) * 2) / 5;
            gCurrentPinballGame->ball->spinAngle -= 0x2000;
            var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 30;
            tempVector2.x = gCurrentPinballGame->orbScreenPosition[i].x / 10 + 16;
            tempVector2.y = gCurrentPinballGame->orbScreenPosition[i].y / 10 + 32;
            gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
            gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

            if (gCurrentPinballGame->bossRenderOffsetY < 1800)
            {
                gCurrentPinballGame->rayquazaOrbAngle = 0;
                gCurrentPinballGame->bossRenderOffsetY += 32;
            }

            if (gCurrentPinballGame->orbAnimTimer[i] < 180)
            {
                gCurrentPinballGame->orbAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->orbAnimTimer[i] = 0;
                gCurrentPinballGame->orbEntityState[i] = 4;
                gCurrentPinballGame->trapSpinRadius /= 2;
                gCurrentPinballGame->ball->positionQ8.y = 0xA500;
            }
            break;
        }
        case 4:
            if (gCurrentPinballGame->orbAnimTimer[i] < 130)
            {
                if (gCurrentPinballGame->orbAnimTimer[i] == 10)
                    m4aSongNumStart(SE_UNKNOWN_0x12C);

                gCurrentPinballGame->rayquazaOrbAngle--;
                gCurrentPinballGame->bossRenderOffsetY += gCurrentPinballGame->rayquazaOrbAngle;
                if (gCurrentPinballGame->bossRenderOffsetY <= 0)
                {
                    gCurrentPinballGame->bossRenderOffsetY = 0;
                    gCurrentPinballGame->ball->velocity.y = -((gCurrentPinballGame->rayquazaOrbAngle * 0x80) / 10) / 2;
                    gCurrentPinballGame->ballFrozenState = 0;
                    gCurrentPinballGame->orbAnimTimer[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = 0;
                    gCurrentPinballGame->orbEntityState[i] = 0;
                    gCurrentPinballGame->boardEntityActive = 0;
                    PlayRumble(8);
                }

                gCurrentPinballGame->orbAnimTimer[i]++;
            }
            break;
        case 5:
            sp0 = gCurrentPinballGame->orbAnimTimer[i] / 6 + 7;
            if (gCurrentPinballGame->orbAnimTimer[i] < 11)
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

        if (group->available)
        {
            DmaCopy16(3, gRayquazaMinionOrbFrames[sp0], (void *)0x06011EA0, 0x280);
            group->baseX = gCurrentPinballGame->orbScreenPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->orbScreenPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 2; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->orbEntityState[i] == 0)
                group->available = 0;

            if (gCurrentPinballGame->orbHitIndex && i == (gCurrentPinballGame->orbHitIndex - 1))
                group->available = 0;
        }
    }

    RenderWindCloudSprites();
    group = &gMain.spriteGroups[20];
    if (group->available)
    {
        s16 a;
        group->baseX = gCurrentPinballGame->orbHitPosition.x / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->orbHitPosition.y / 10 - gCurrentPinballGame->cameraYOffset;
        a = gCurrentPinballGame->hitBurstAnimFrame / 5;
        for (j = 0; j < 5; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaHitBurstOamData[a][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->hitBurstAnimFrame < 25)
        {
            gCurrentPinballGame->hitBurstAnimFrame++;
            if (gCurrentPinballGame->hitBurstAnimFrame == 25)
                group->available = 0;
        }
    }

    if (gCurrentPinballGame->orbHitIndex)
    {
        gCurrentPinballGame->orbHitIndex = 0;
        gCurrentPinballGame->hitBurstAnimFrame = 0;
        group->available = 1;
    }
}

void UpdateWhirlwindGrabEntity(void)
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

    gCurrentPinballGame->ballGrabTimer--;
    if (gCurrentPinballGame->ballGrabTimer > 5)
    {
        var0 = gWhirlwindGrabAnimFrameIndices[(gCurrentPinballGame->ballGrabTimer % 33) / 3];
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
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
            {
                gCurrentPinballGame->ballGrabTimer -= 30;
                if (gCurrentPinballGame->ballGrabTimer < 5)
                    gCurrentPinballGame->ballGrabTimer = 5;

                gCurrentPinballGame->ballGrabShakeTimer = 7;
                m4aSongNumStart(SE_UNKNOWN_0x12A);
            }
        }

        if (gCurrentPinballGame->ballGrabFlashTimer)
        {
            gCurrentPinballGame->ballGrabFlashTimer--;
            if (gCurrentPinballGame->ballGrabFlashTimer > 52)
                var0 = 8;
            else if (gCurrentPinballGame->ballGrabFlashTimer > 42)
                var0 = 9;
        }
        else
        {
            if (gCurrentPinballGame->newButtonActions[0] || gCurrentPinballGame->newButtonActions[1])
                gCurrentPinballGame->ballGrabFlashTimer = 60;
        }

    }
    else
    {
        var0 = 8;
    }

    if (gCurrentPinballGame->ballGrabTimer == 0)
    {
        gMain.spriteGroups[36].available = 0;
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
    for (i = 0; i < 2; i++)
    {
        oamSimple = &group->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gRayquazaWhirlwindGrabOamData[var0][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        gOamBuffer[oamSimple->oamId].x += group->baseX;
        gOamBuffer[oamSimple->oamId].y += group->baseY;
    }
}

void RenderWindCloudSprites(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    u32 rand;
    u16 var0;

    group = &gMain.spriteGroups[24];
    if (group->available)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[25];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
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
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[27];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
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
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[29];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
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
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[31];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
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
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[33];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
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
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[35];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gMain.spriteGroups[22].available)
    {
        if (gCurrentPinballGame->windCloudSpawnTimer == 6)
        {
            gMain.spriteGroups[24].available = 0;
            gMain.spriteGroups[25].available = 0;
            gMain.spriteGroups[26].available = 1;
            gMain.spriteGroups[27].available = 1;
            if (gCurrentPinballGame->orbEntityState[0] < 3 && gCurrentPinballGame->orbEntityState[1] < 3 && gCurrentPinballGame->ballRespawnState == 0)
            {
                gCurrentPinballGame->ball->velocity.x += 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 11)
        {
            gMain.spriteGroups[26].available = 0;
            gMain.spriteGroups[27].available = 0;
            gMain.spriteGroups[28].available = 1;
            gMain.spriteGroups[29].available = 1;
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 14)
        {
            gMain.spriteGroups[28].available = 0;
            gMain.spriteGroups[29].available = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->windCloudSpawnTimer == 6)
        {
            gMain.spriteGroups[30].available = 0;
            gMain.spriteGroups[31].available = 0;
            gMain.spriteGroups[32].available = 1;
            gMain.spriteGroups[33].available = 1;
            if (gCurrentPinballGame->orbEntityState[0] < 3 && gCurrentPinballGame->orbEntityState[1] < 3 && gCurrentPinballGame->ballRespawnState == 0)
            {
                gCurrentPinballGame->ball->velocity.x -= 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 11)
        {
            gMain.spriteGroups[32].available = 0;
            gMain.spriteGroups[33].available = 0;
            gMain.spriteGroups[34].available = 1;
            gMain.spriteGroups[35].available = 1;
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 14)
        {
            gMain.spriteGroups[34].available = 0;
            gMain.spriteGroups[35].available = 0;
        }
    }

    if (gCurrentPinballGame->windCloudSpawnTimer == 10)
    {
        if (gCurrentPinballGame->orbEntityState[0] < 3)
        {
            gCurrentPinballGame->orbAnimTimer[0] = 0;
            gCurrentPinballGame->orbEntityState[0] = 1;
            gMain.spriteGroups[15].available = 1;
            rand = Random() % 8;
            var0 = ((gMain.systemFrameCount % 240) << 0x10) / 240;
            gCurrentPinballGame->orbOrbitCenter[0].x = gRayquazaMinionOrbitWaypoints[rand].x;
            gCurrentPinballGame->orbOrbitCenter[0].y = gRayquazaMinionOrbitWaypoints[rand].y;
            gCurrentPinballGame->orbScreenPosition[0].x = gCurrentPinballGame->orbOrbitCenter[0].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->orbScreenPosition[0].y = gCurrentPinballGame->orbOrbitCenter[0].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->windCloudSpawnTimer == 16)
    {
        if (gCurrentPinballGame->orbEntityState[1] < 3)
        {
            gCurrentPinballGame->orbAnimTimer[1] = 0;
            gCurrentPinballGame->orbEntityState[1] = 1;
            gMain.spriteGroups[16].available = 1;
            rand = (Random() % 8 + 8) % 32; // Force 8 to be added to r1
            var0 = (((gMain.systemFrameCount + 120) % 240) << 0x10) / 240;
            gCurrentPinballGame->orbOrbitCenter[1].x = gRayquazaMinionOrbitWaypoints[rand].x;
            gCurrentPinballGame->orbOrbitCenter[1].y = gRayquazaMinionOrbitWaypoints[rand].y;
            gCurrentPinballGame->orbScreenPosition[1].x = gCurrentPinballGame->orbOrbitCenter[1].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->orbScreenPosition[1].y = gCurrentPinballGame->orbOrbitCenter[1].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_UNKNOWN_0x12D);
        }
    }

    if (gCurrentPinballGame->impactShakeTimer > 0)
    {
        gCurrentPinballGame->impactShakeTimer--;
        if (gCurrentPinballGame->impactShakeTimer < 12)
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12];
        else if (gCurrentPinballGame->impactShakeTimer < 24)
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12] * 2;
        else if (gCurrentPinballGame->impactShakeTimer < 36)
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12] * 4;
        else if (gCurrentPinballGame->impactShakeTimer < 48)
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12] * 2;
        else
            gCurrentPinballGame->screenShakeY = gScreenShakeOscillationValues[gCurrentPinballGame->impactShakeTimer % 12];

        if (gCurrentPinballGame->impactShakeTimer == 0)
            gCurrentPinballGame->screenShakeY = 0;
    }

    if (gCurrentPinballGame->horizontalShakeTimer > 0)
    {
        s16 var0 = gCurrentPinballGame->horizontalShakeTimer % 4;
        if (var0 / 2 != 0)
            gCurrentPinballGame->screenShakeX = 2;
        else
            gCurrentPinballGame->screenShakeX = -2;

        gCurrentPinballGame->horizontalShakeTimer--;
        if (gCurrentPinballGame->horizontalShakeTimer == 0)
            gCurrentPinballGame->screenShakeX = 0;
    }
}

void UpdateRayquazaIntroSequence(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->introSequencePhase == 0)
    {
        if (gCurrentPinballGame->introFrameCounter < 689)
        {
            if (gCurrentPinballGame->introFrameCounter < 569)
            {
                if (gCurrentPinballGame->introFrameCounter % 160 == 20)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x80);

                if (gCurrentPinballGame->introFrameCounter % 160 == 90)
                    m4aMPlayFadeOutTemporarily(&gMPlayInfo_SE1, 5);

                if (gCurrentPinballGame->introFrameCounter % 160 == 1)
                    m4aSongNumStart(SE_RAYQUAZA_STAGE_WIND);

                if (gCurrentPinballGame->introFrameCounter % 160 == 2)
                    m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, 0x33);
            }

            if (gCurrentPinballGame->introFrameCounter >= 512)
                gCurrentPinballGame->cameraYAdjust = (gCurrentPinballGame->introFrameCounter - 512) / 2 - 88;

            if (gCurrentPinballGame->introFrameCounter == 624)
                gCurrentPinballGame->boardModeType = 1;

            if (gCurrentPinballGame->introFrameCounter < 513)
                gCurrentPinballGame->bgScrollSpeed = gCurrentPinballGame->introFrameCounter / 2;

            if (gCurrentPinballGame->introFrameCounter == 688)
                gCurrentPinballGame->introSequencePhase = 1;

            gCurrentPinballGame->introFrameCounter++;
            if (gCurrentPinballGame->introFrameCounter <= 568 && gCurrentPinballGame->ballRespawnTimer > 5)
                gCurrentPinballGame->ballRespawnTimer--;

            if (gCurrentPinballGame->introFrameCounter == 1)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 300;
                gCurrentPinballGame->minionLogicPosition[0].y = 1200;
                gCurrentPinballGame->minionLogicPosition[1].x = 1200;
                gCurrentPinballGame->minionLogicPosition[1].y = 400;
                gCurrentPinballGame->minionLogicPosition[2].x = 1000;
                gCurrentPinballGame->minionLogicPosition[2].y = 2500;
            }

            if (gCurrentPinballGame->introFrameCounter == 88)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 1600;
                gCurrentPinballGame->minionLogicPosition[0].y = 1800;
            }

            if (gCurrentPinballGame->introFrameCounter == 120)
            {
                gCurrentPinballGame->minionLogicPosition[1].x = 600;
                gCurrentPinballGame->minionLogicPosition[1].y = 1800;
            }

            if (gCurrentPinballGame->introFrameCounter == 170)
            {
                gCurrentPinballGame->minionLogicPosition[2].x = 1800;
                gCurrentPinballGame->minionLogicPosition[2].y = 2000;
            }

            if (gCurrentPinballGame->introFrameCounter == 215)
            {
                gCurrentPinballGame->minionLogicPosition[0].x = 0;
                gCurrentPinballGame->minionLogicPosition[0].y = 2000;
            }

            if (gCurrentPinballGame->introFrameCounter == 305)
            {
                gCurrentPinballGame->minionLogicPosition[1].x = 1800;
                gCurrentPinballGame->minionLogicPosition[1].y = 1800;
            }

            if (gCurrentPinballGame->introFrameCounter == 315)
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

            if (gCurrentPinballGame->introFrameCounter == 660)
            {
                gMain.spriteGroups[11].available = 0;
                gMain.spriteGroups[12].available = 0;
                gMain.spriteGroups[13].available = 0;
            }

            group = &gMain.spriteGroups[14];
            if (group->available)
            {
                if (gCurrentPinballGame->introFrameCounter >= 195 && gCurrentPinballGame->introFrameCounter < 205)
                    var0 = gRayquazaCloudScrollPositions[(gCurrentPinballGame->introFrameCounter - 195) / 2];
                else
                    var0 = (gCurrentPinballGame->introFrameCounter % 4) / 2;

                group->baseX = gCurrentPinballGame->orbCollisionPosition.x / 10;
                group->baseY = gCurrentPinballGame->orbCollisionPosition.y / 10;

                if (group->baseY < -60)
                    group->baseY = -60;
                if (group->baseY > 180)
                    group->baseY = 180;

                oamSimple = &group->oam[0];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;
            }

            if (gCurrentPinballGame->introFrameCounter == 150)
            {
                gMain.spriteGroups[14].available = 1;
                gCurrentPinballGame->orbCollisionPosition.x = 1600;
                gCurrentPinballGame->orbCollisionPosition.y = -100;
                gCurrentPinballGame->orbLogicPosition.x = -21;
                gCurrentPinballGame->orbLogicPosition.y = 14;
            }

            if (gCurrentPinballGame->introFrameCounter > 205)
            {
                gCurrentPinballGame->orbLogicPosition.y++;
                gCurrentPinballGame->orbCollisionPosition.x += gCurrentPinballGame->orbLogicPosition.x;
                gCurrentPinballGame->orbCollisionPosition.y += gCurrentPinballGame->orbLogicPosition.y;
            }
            else if (gCurrentPinballGame->introFrameCounter > 150)
            {
                gCurrentPinballGame->orbCollisionPosition.x += gCurrentPinballGame->orbLogicPosition.x;
                gCurrentPinballGame->orbCollisionPosition.y += gCurrentPinballGame->orbLogicPosition.y;
            }

            if (gCurrentPinballGame->introFrameCounter == 350)
                gMain.spriteGroups[14].available = 0;
        }
    }

    if (gCurrentPinballGame->introSequencePhase == 2)
    {
        if (gCurrentPinballGame->introFrameCounter < 256)
        {
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->introFrameCounter / -2;
            gCurrentPinballGame->introFrameCounter++;
        }

        group = &gMain.spriteGroups[11];
        if (group->available)
        {
            group->baseX = gCurrentPinballGame->minionLogicPosition[0].x / 10;
            group->baseY = gCurrentPinballGame->minionLogicPosition[0].y / 10;
            if (group->baseY > 180)
                group->baseY = 180;
            else if (gCurrentPinballGame->introFrameCounter < 256)
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
            else if (gCurrentPinballGame->introFrameCounter < 256)
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
            if (gCurrentPinballGame->introFrameCounter >= 190 && gCurrentPinballGame->introFrameCounter < 200)
                var0 = gRayquazaCloudScrollPositions[(gCurrentPinballGame->introFrameCounter - 190) / 2];
            else
                var0 = (gCurrentPinballGame->introFrameCounter % 4) / 2;

            group->baseX = gCurrentPinballGame->orbCollisionPosition.x / 10;
            group->baseY = gCurrentPinballGame->orbCollisionPosition.y / 10;

            if (group->baseY < -60)
                group->baseY = -60;
            if (group->baseY > 180)
                group->baseY = 180;

            oamSimple = &group->oam[0];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x7D + var0 * 4;

            if (gCurrentPinballGame->introFrameCounter > 160)
            {
                gCurrentPinballGame->orbCollisionPosition.x += gCurrentPinballGame->orbLogicPosition.x;
                gCurrentPinballGame->orbCollisionPosition.y += gCurrentPinballGame->orbLogicPosition.y;
            }
        }
    }

    if (gCurrentPinballGame->cameraYAdjust >= -0x20)
        gCurrentPinballGame->flippersDisabled = 0;
    else
        gCurrentPinballGame->flippersDisabled = 1;

    gMain.bgOffsets[2].yOffset += gCurrentPinballGame->bgScrollSpeed;
    gMain.bgOffsets[1].yOffset += gCurrentPinballGame->bgScrollSpeed;
    gMain.bgOffsets[3].yOffset += gCurrentPinballGame->bgScrollSpeed / 4 + 224;
}

