#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/groudon_states.h"
#include "constants/board/center_screen_states.h"

#define GROUDON_MODE_TIME TICKS_FOR_TIME(3,0)

extern const u8 gGroudonBonusClear_Gfx[];
extern const u8 gGroudonLavaPaletteCycleData[];
extern const u8 gGroudonAttackFx_Gfx[];
extern const s8 gGroudonBoardBoulders_Gfx[][0x300];
extern struct SongHeader se_groudon_hit;
extern struct SongHeader se_groudon_lands;
extern struct SongHeader se_groudon_spits_fire;
extern struct SongHeader se_groudon_fire_ring;
extern struct SongHeader se_groudon_fire_grab;
extern const s16 gShockwaveSplashDistanceThresholds[];
extern const s16 gScreenShakeOscillationValues[];
extern const s16 gGroudonFootstepShakePatterns[][31];
extern const s16 gGroudonCryShakePattern[];
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
    gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_ACTIVE;
    gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_INTRO;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + GROUDON_MODE_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_INITIAL_SPAWN;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = TRUE;
    gCurrentPinballGame->returnToMainBoardFlag = FALSE;
    gCurrentPinballGame->boardEntityCollisionMode = GROUDON_COLLISION_MODE_ACTIVE;
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballGrabbed = FALSE;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_SPAWN;
    gCurrentPinballGame->bossNextAttackState = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->bossVulnerable = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossMovementPhase = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->bossAnimLoopCount = 0;
    gCurrentPinballGame->bossPositionX = 0;
    gCurrentPinballGame->bossPositionY = 0;
    gCurrentPinballGame->bossTargetXPosition = 0;
    gCurrentPinballGame->bossTargetYPosition = 0;
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
        gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_SPAWN;
        gCurrentPinballGame->firePillarAnimEndFrame[i] = 0;
        gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_SPAWN;
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
        gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_SPAWN;
        gCurrentPinballGame->boulderSpriteFrame[i] = 0;
        gCurrentPinballGame->boulderHitFlag[i] = FALSE;
        gCurrentPinballGame->boulderAnimTimer[i] = 0;
        gCurrentPinballGame->boulderFallVelocity[i] = 0;
        gCurrentPinballGame->boulderFallHeight[i] = 0;
        gCurrentPinballGame->boulderGroundPosition[i].x = 0;
        gCurrentPinballGame->boulderGroundPosition[i].y = 0;
        gCurrentPinballGame->boulderCollisionPos[i].x = 0;
        gCurrentPinballGame->boulderCollisionPos[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = TRUE;
    UpdateGroudonFieldEntities();
    UpdateGroudonEntityLogic();
    RenderGroudonSprites();
    DmaCopy16(3, gGroudonAttackFx_Gfx, (void *)0x06015800, 0x2000);
    AnimateGroudonBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_GROUDON);
    DmaCopy16(3, gBonusStageObjPal, OBJ_PLTT_SLOT(9), 0x20);
}

void GroudonBoardProcess_3B_3B49C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case LEGENDARY_BOARD_STATE_INTRO:
        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
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
                gCurrentPinballGame->flippersDisabled = FALSE;

            if (gCurrentPinballGame->stageTimer == 650)
                gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;
        }
        else
        {
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_BATTLE_PHASE;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case LEGENDARY_BOARD_STATE_SUCCESS_BANNER:
        if (gCurrentPinballGame->stageTimer < 120)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SUCCESS_SCORING;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER].active = TRUE;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE].active = TRUE;
            DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
            gCurrentPinballGame->bannerSlideYOffset = 136;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->cameraLocked = TRUE;
        }
        break;
    case LEGENDARY_BOARD_STATE_SUCCESS_SCORING:
        ProcessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_GROUDON_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_GROUDON_BONUS_COMPLETE;
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
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SCORE_COUNTING_FINISHED;
            gCurrentPinballGame->numCompletedBonusStages++;
        }

        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    case LEGENDARY_BOARD_STATE_CATCH_BANNER:
        gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_CATCH_SCORING;
        gCurrentPinballGame->stageTimer = 140;
        gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER].active = TRUE;
        gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE].active = TRUE;
        DmaCopy16(3, gGroudonBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->bannerSlideYOffset = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        break;
    case LEGENDARY_BOARD_STATE_CATCH_SCORING:
        ProcessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_GROUDON_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_GROUDON_BONUS_COMPLETE;
        }

        if (gCurrentPinballGame->stageTimer < 240)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SCORE_COUNTING_FINISHED;
            gCurrentPinballGame->numCompletedBonusStages++;
        }
        break;
    case LEGENDARY_BOARD_STATE_SCORE_COUNTING_FINISHED:
        ProcessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = TRUE;
        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    }

    UpdateGroudonFieldEntities();
    UpdateGroudonEntityLogic();
    RenderGroudonSprites();
    AnimateGroudonBackground();

    if (gCurrentPinballGame->eventTimerType 
        && gCurrentPinballGame->eventTimer < 2
        && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->cameraLocked = TRUE;
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
            MPlayStart(&gMPlayInfo_SE1, &se_groudon_hit);
            gCurrentPinballGame->scoreAddedInFrame = SCORE_GROUDON_HIT;
            PlayRumble(7);
            gCurrentPinballGame->bonusModeHitCount++;
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_SUFFICIENT_HITS;
        }

        if (gCurrentPinballGame->bossHitFlashTimer < 31)
            gCurrentPinballGame->legendaryFlashState = 0;
    }

    switch (gCurrentPinballGame->bossEntityState)
    {
    case GROUDON_ENTITY_STATE_SPAWN:
        gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_ENTRY;
        gCurrentPinballGame->bossFramesetIndex = 22;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossPositionX = 0;
        gCurrentPinballGame->bossPositionY = -1200;
        gCurrentPinballGame->bossDropVelocity = 0;
        break;
    case GROUDON_ENTITY_STATE_ENTRY:
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
                    gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_IDLE;
                    gCurrentPinballGame->bossNextAttackState = GROUDON_ENTITY_STATE_SHOCKWAVE;
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
                    m4aSongNumStart(SE_GROUDON_INTRO_LEAP);
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
                MPlayStart(&gMPlayInfo_SE1, &se_groudon_lands);
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
    case GROUDON_ENTITY_STATE_IDLE:
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
                    if (gCurrentPinballGame->bossMovementPhase == 12
                        && gCurrentPinballGame->bossNextAttackState == GROUDON_ENTITY_STATE_SHOCKWAVE)
                    {
                        for (i = 0; i < 4; i++)
                        {
                            if (gCurrentPinballGame->firePillarState[i] < GROUDON_FIRE_PILLAR_STATE_DESTROYED)
                                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_DESTROYED;
                        }
                    }
                }
                else
                {
                    if (gCurrentPinballGame->bossNextAttackState == GROUDON_ENTITY_STATE_SHOCKWAVE)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 36;
                        gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_SHOCKWAVE;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else if (gCurrentPinballGame->bossNextAttackState == GROUDON_ENTITY_STATE_FIREBALL)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 76;
                        gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_FIREBALL;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 58;
                        gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_JUMP;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
            }
        }

        if (gCurrentPinballGame->bossFramesetIndex == 21)
            gCurrentPinballGame->bossFramesetIndex = 0;
        break;
    case GROUDON_ENTITY_STATE_FIREBALL:
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
                gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_IDLE;

                if (gCurrentPinballGame->projectileAttackCount & 1)
                {
                    gCurrentPinballGame->bossNextAttackState = GROUDON_ENTITY_STATE_SHOCKWAVE;
                    gCurrentPinballGame->bossMovementPhase = 8;
                }
                else
                {
                    gCurrentPinballGame->bossNextAttackState = GROUDON_ENTITY_STATE_JUMP;
                    gCurrentPinballGame->bossMovementPhase = 8;
                }

                gCurrentPinballGame->projectileAttackCount++;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 90)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_groudon_spits_fire);
                gCurrentPinballGame->projectileAttackAnimTimer = 8;
                gCurrentPinballGame->projectileFlightTimer = 35;
                gMain.spriteGroups[SG_GROUDON_FIREBALL].active = TRUE;
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
    case GROUDON_ENTITY_STATE_SHOCKWAVE: //Shockwave, then raise flame pillars
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
                    gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_IDLE;
                    gCurrentPinballGame->bossNextAttackState = GROUDON_ENTITY_STATE_FIREBALL;
                    gCurrentPinballGame->bossMovementPhase = 6;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 50)
            {
                if (gCurrentPinballGame->bossFrameTimer == 0)
                {
                    gMain.spriteGroups[SG_GROUDON_SHOCKWAVE].active = TRUE;
                    gCurrentPinballGame->shockwaveAnimTimer = 0;
                    MPlayStart(&gMPlayInfo_SE1, &se_groudon_fire_ring);
                }
            }
        }
        break;
    case GROUDON_ENTITY_STATE_JUMP: // Groudon Jumps, lands: Rocks fall
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
                gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_IDLE;
                gCurrentPinballGame->bossNextAttackState = GROUDON_ENTITY_STATE_FIREBALL;
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
                    MPlayStart(&gMPlayInfo_SE1, &se_groudon_lands);
                }
            }
        }
        break;
    case GROUDON_ENTITY_STATE_SUFFICIENT_HITS:
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;

        // Alternating completions lead to escape vs catch
        // This will happen on the 4th/9th/etc board. ( %5 == 3 completed)
        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch groudon
            gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_CAPTURE;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT].active = TRUE;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT_BORDERS].active = TRUE;
            gCurrentPinballGame->currentSpecies = SPECIES_GROUDON;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
        }
        else
        {
            // bonus completed
            gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_PREPARE_LEAVING;
            gCurrentPinballGame->bossFramesetIndex = 32;
            gCurrentPinballGame->boardEntityCollisionMode = GROUDON_COLLISION_MODE_NONE;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_DISABLED;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossFrameTimer = 0;
        if (gMain.spriteGroups[SG_GROUDON_FIREBALL_CAUGHT_BALL].active)
            gCurrentPinballGame->ballGrabTimer = 1;
        break;
    case GROUDON_ENTITY_STATE_PREPARE_LEAVING:
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
                    gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_LEAVES;
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
    case GROUDON_ENTITY_STATE_LEAVES:
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
                    gCurrentPinballGame->bossEntityState = GROUDON_ENTITY_STATE_FINISHED;
                    gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SUCCESS_BANNER;
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
    case GROUDON_ENTITY_STATE_CAPTURE:
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
    case GROUDON_ENTITY_STATE_FINISHED:
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
            gMain.spriteGroups[SG_GROUDON_BOULDER_BASE + i].active = TRUE;
            gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_SPAWN;
            gCurrentPinballGame->boulderSpriteFrame[i] = 0;
            gCurrentPinballGame->boulderAnimTimer[i] = 0;
        }

        if (gCurrentPinballGame->impactShakeTimer == 20)
        {
            i = 1;
            gMain.spriteGroups[SG_GROUDON_BOULDER_BASE + i].active = TRUE;
            gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_SPAWN;
            gCurrentPinballGame->boulderSpriteFrame[i] = 13;
            gCurrentPinballGame->boulderAnimTimer[i] = 0;
        }

        if (gCurrentPinballGame->impactShakeTimer == 53)
        {
            i = 2;
            gMain.spriteGroups[SG_GROUDON_BOULDER_BASE + i].active = TRUE;
            gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_SPAWN;
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
    s16 oamAnimFrameIx;
    int palette;

    group = &gMain.spriteGroups[SG_GROUDON_ENTITY];
    if (group->active)
    {
        oamAnimFrameIx = gGroudonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][0];
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
                src = gGroudonMainBodyOamData[oamAnimFrameIx][i];
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
                src = gGroudonMainBodyOamData[oamAnimFrameIx][i];
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
                src = gGroudonMainBodyOamData[oamAnimFrameIx][i];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamSimple->oamId].x += group->baseX;
                gOamBuffer[oamSimple->oamId].y += group->baseY;
            }
        }
    }

    // Special effect that appears for a small number of frames around groudon's face, when launching a fireball
    group = &gMain.spriteGroups[SG_GROUDON_FIREBALL_LAUNCH_FX];
    if (group->active)
    {
        if (gCurrentPinballGame->projectileAttackAnimTimer > 0)
        {
            gCurrentPinballGame->projectileAttackAnimTimer--;
            if (gCurrentPinballGame->projectileAttackAnimTimer == 0)
                group->active = FALSE;
        }

        oamAnimFrameIx = gCurrentPinballGame->projectileDirection * 2 - (gCurrentPinballGame->projectileAttackAnimTimer / 4 - 1);
        group->baseX = gCurrentPinballGame->bossPositionX / 10 + 100u - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->bossPositionY / 10 +  84u - gCurrentPinballGame->cameraYOffset;
        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gGroudonProjectileAttackOamData[oamAnimFrameIx][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->captureState == MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
        {
            gMain.spriteGroups[SG_GROUDON_FIREBALL_LAUNCH_FX].active = FALSE;
            gCurrentPinballGame->projectileAttackAnimTimer = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->projectileAttackAnimTimer == 8)
            group->active = TRUE;
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
    int squaredDistance;
    struct Vector32 tempVector;
    s8 frameIx;

    varSL = 0;
    group = &gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT];
    if (group->active)
    {
        if (gCurrentPinballGame->portraitDisplayState == PORTRAIT_DISPLAY_MODE_BANNER)
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

        group = &gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT_BORDERS];
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

    group = &gMain.spriteGroups[SG_GROUDON_FIREBALL_CAUGHT_BALL];
    if (group->active)
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
            else if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
            {
                gCurrentPinballGame->ballGrabTimer = gCurrentPinballGame->ballGrabTimer - 30;
                if (gCurrentPinballGame->ballGrabTimer < 5)
                    gCurrentPinballGame->ballGrabTimer = 5;

                gCurrentPinballGame->ballGrabShakeTimer = 7;
                m4aSongNumStart(SE_GROUDON_FIRE_GRAB_RESIST);
            }

            if (gCurrentPinballGame->ballGrabFlashTimer)
            {
                gCurrentPinballGame->ballGrabFlashTimer--;
                if (gCurrentPinballGame->ballGrabFlashTimer > 50)
                    varSL = 4;
                else if (gCurrentPinballGame->ballGrabFlashTimer > 40)
                    varSL = 5;
            }
            else if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
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
            gMain.spriteGroups[SG_GROUDON_FIREBALL_CAUGHT_BALL].active = FALSE;
            gCurrentPinballGame->ballGrabFlashTimer = 0;
            gCurrentPinballGame->ballGrabbed = FALSE;
        }
        else
        {
            gCurrentPinballGame->ballGrabbed = TRUE;
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

    group = &gMain.spriteGroups[SG_GROUDON_FIREBALL];
    if (group->active)
    {
        tempVector.x = gCurrentPinballGame->projectilePosition.x / 10 - gCurrentPinballGame->ball->positionQ0.x;
        tempVector.y = gCurrentPinballGame->projectilePosition.y / 10 - gCurrentPinballGame->ball->positionQ0.y;
        xx = tempVector.x * tempVector.x;
        yy = tempVector.y * tempVector.y;
        squaredDistance = xx + yy;
        if (gCurrentPinballGame->projectileFlightTimer)
        {
            gCurrentPinballGame->projectileFlightTimer--;
            if (gCurrentPinballGame->projectileFlightTimer >= 10)
            {
                varSL = (gCurrentPinballGame->projectileFlightTimer % 8) / 4 + gCurrentPinballGame->projectileDirection * 2;
                if (squaredDistance <= 240
                    && !gCurrentPinballGame->ballRespawnState
                    && gCurrentPinballGame->ballGrabTimer < 600)
                {
                    MPlayStart(&gMPlayInfo_SE1, &se_groudon_fire_grab);
                    gCurrentPinballGame->projectileFlightTimer = 10;
                    gMain.spriteGroups[SG_GROUDON_FIREBALL_CAUGHT_BALL].active = TRUE;
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
                    if (squaredDistance <= 240)
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

                    m4aSongNumStart(SE_GROUDON_FIREBALL_CONNECTS);
                }
            }

            if (gCurrentPinballGame->projectileFlightTimer == 0)
                gMain.spriteGroups[SG_GROUDON_FIREBALL].active = FALSE;
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

        if (gCurrentPinballGame->captureState == MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
        {
            gMain.spriteGroups[SG_GROUDON_FIREBALL].active = FALSE;
            gCurrentPinballGame->projectileFlightTimer = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        group = &gMain.spriteGroups[SG_GROUDON_BOULDER_BASE + i];
        if (group->active)
        {
            switch (gCurrentPinballGame->boulderState[i])
            {
            case GROUDON_BOULDER_STATE_SPAWN:
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
                gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_DROP;
                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                gCurrentPinballGame->boulderHitFlag[i] = FALSE;
                break;
            case GROUDON_BOULDER_STATE_DROP:
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
                        gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_UNHIT;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }

                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                break;
            case GROUDON_BOULDER_STATE_UNHIT:
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
                        gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_HIT_ONCE;
                        gCurrentPinballGame->boulderHitFlag[i] = FALSE;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case GROUDON_BOULDER_STATE_HIT_ONCE:
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
                        gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_HIT_TWICE;
                        gCurrentPinballGame->boulderHitFlag[i] = FALSE;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case GROUDON_BOULDER_STATE_HIT_TWICE:
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
                        gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_CLEANUP;
                        gCurrentPinballGame->boulderHitFlag[i] = FALSE;
                    }

                    gCurrentPinballGame->boulderAnimTimer[i]++;
                }
                break;
            case GROUDON_BOULDER_STATE_CLEANUP:
                gCurrentPinballGame->boulderCollisionPos[i].x = 0;
                gCurrentPinballGame->boulderCollisionPos[i].y = 0;
                gMain.spriteGroups[SG_GROUDON_BOULDER_BASE + i].active = FALSE;
                break;
            }

            frameIx = gCurrentPinballGame->boulderSpriteFrame[i];
            DmaCopy16(3, gGroudonBoardBoulders_Gfx[frameIx], (void *)0x06010FA0 + i * 0x300, 0x300);

            group->baseX = (gCurrentPinballGame->boulderGroundPosition[i].x / 10) + i - gCurrentPinballGame->cameraXOffset;
            group->baseY = (gCurrentPinballGame->boulderFallHeight[i] / 10) + (gCurrentPinballGame->boulderGroundPosition[i].y / 10) - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 3; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->boulderState[i] > GROUDON_BOULDER_STATE_DROP
                && gCurrentPinballGame->boulderState[i] < GROUDON_BOULDER_STATE_CLEANUP)
            {
                if (gGroudonBoulderPositionTable[gCurrentPinballGame->boulderPositionIndex[i]][2] == gCurrentPinballGame->shockwaveAnimTimer)
                {
                    gCurrentPinballGame->boulderState[i] = GROUDON_BOULDER_STATE_HIT_TWICE;
                    gCurrentPinballGame->boulderHitFlag[i] = TRUE;
                    gCurrentPinballGame->boulderAnimTimer[i] = 0;
                }
            }
        }
    }

    /*Fire pillars
        Pillars will shrink on their own over time, transitioning to the next smaller size after a
        given number of loops of animation.

        This uses an extra 'setup' state between each hittable check, to set the animation frame
        boundaries and loop information for the next scheduled shrinkage.
    */
    for (i = 0; i < 4; i++)
    {
        group = &gMain.spriteGroups[SG_GROUDON_FILE_PILLAR_BASE + i];
        if (group->active)
        {
            switch(gCurrentPinballGame->firePillarState[i])
            {
            case GROUDON_FIRE_PILLAR_STATE_SPAWN:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 0;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 8;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_FULL_SIZE_SETUP;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 0;
                break;
            case GROUDON_FIRE_PILLAR_STATE_FULL_SIZE_SETUP:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 8;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 12;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_TALL_SETUP;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_FULL_SIZE_VULNERABLE;
                break;
            case GROUDON_FIRE_PILLAR_STATE_FULL_SIZE_VULNERABLE:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_TALL_SETUP;
                        PlayRumble(7);
                    }
                }
                break;
            case GROUDON_FIRE_PILLAR_STATE_TALL_SETUP:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 12;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 16;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_MEDIUM_SETUP;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_TALL_VULNERABLE;
                break;
            case GROUDON_FIRE_PILLAR_STATE_TALL_VULNERABLE:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_MEDIUM_SETUP;
                        PlayRumble(7);
                    }
                }
                break;
            case GROUDON_FIRE_PILLAR_STATE_MEDIUM_SETUP:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 16;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 20;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_SHORT_SETUP;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_MEDIUM_VULNERABLE;
                break;
            case GROUDON_FIRE_PILLAR_STATE_MEDIUM_VULNERABLE:
                if (gCurrentPinballGame->firePillarHitTimer[i] > 0)
                {
                    gCurrentPinballGame->firePillarHitTimer[i]--;
                    if (gCurrentPinballGame->firePillarHitTimer[i] == 7)
                    {
                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_SHORT_SETUP;
                        PlayRumble(7);
                    }
                }
                break;
            case GROUDON_FIRE_PILLAR_STATE_SHORT_SETUP:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 20;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 24;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_DESTROYED;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 14;
                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_SHORT_VULNERABLE;
                gCurrentPinballGame->firePillarExtraHitCount[i] = 0;
                break;
            case GROUDON_FIRE_PILLAR_STATE_SHORT_VULNERABLE:
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
                            gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_DESTROYED;
                        }

                        m4aSongNumStart(SE_GROUDON_BALL_HIT_FIRE);
                        PlayRumble(7);
                    }
                }
                break;
            case GROUDON_FIRE_PILLAR_STATE_DESTROYED:
                gCurrentPinballGame->firePillarAnimStartFrame[i] = 24;
                gCurrentPinballGame->firePillarAnimEndFrame[i] = 27;
                gCurrentPinballGame->firePillarNextState[i] = GROUDON_FIRE_PILLAR_STATE_CLEANUP;
                gCurrentPinballGame->firePillarAnimLoopCount[i] = 0;
                break;
            case GROUDON_FIRE_PILLAR_STATE_CLEANUP:
                gMain.spriteGroups[SG_GROUDON_FILE_PILLAR_BASE + i].active = FALSE;
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
            if (gCurrentPinballGame->firePillarState[i] < GROUDON_FIRE_PILLAR_STATE_DESTROYED)
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

    group = &gMain.spriteGroups[SG_GROUDON_SHOCKWAVE];
    if (group->active)
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
            group->active = FALSE;
        }

        if (gCurrentPinballGame->shockwaveAnimTimer == 34)
        {
            for (i = 0; i < 4; i++)
            {
                gMain.spriteGroups[SG_GROUDON_FILE_PILLAR_BASE + i].active = TRUE;
                gCurrentPinballGame->firePillarState[i] = GROUDON_FIRE_PILLAR_STATE_SPAWN;
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

        if (group->active)
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
            squaredDistance = xx + yy;
            if (!gCurrentPinballGame->ballRespawnState
                && squaredDistance < gShockwaveSplashDistanceThresholds[gCurrentPinballGame->shockwaveAnimTimer])
            {
                gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);
                gCurrentPinballGame->ball->velocity.x = (Cos(gCurrentPinballGame->trapAngleQ16) * -400) / 20000;
                gCurrentPinballGame->ball->velocity.y = (Sin(gCurrentPinballGame->trapAngleQ16) *  400) / 20000;
                PlayRumble(9);
            }
        }

        if ((gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER) != 0)
            gMain.spriteGroups[SG_GROUDON_SHOCKWAVE].active = FALSE;
    }
}

void HideGroudonShockwaveSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[SG_GROUDON_SHOCKWAVE];
    if (group->active)
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
        group = &gMain.spriteGroups[SG_GROUDON_CRYSTAL_BASE + i];
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