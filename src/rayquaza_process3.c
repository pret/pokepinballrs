#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/rayquaza_states.h"
#include "constants/board/center_screen_states.h"

#define RAYQUAZA_MODE_TIME TICKS_FOR_TIME(3,0)

extern const s16 gLightningGrabAnimFrameIndices[];
extern const u8 gRayquazaBonusClear_Gfx[];
extern const u8 gRayquazaSkyBackgroundGfx[];
extern const u8 gRayquazaTornadoGfx[][0x280];
extern const u8 gRayquazaWindBoardGfx[];
extern const u8 gRayquazaSpriteSheet[];
extern const u8 gRayquazaBodyVariantTiles[][0x800];
extern const s16 gScreenShakeOscillationValues[];
extern const u16 gRayquazaAnimFramesetTable[][3];
extern const struct Vector16 gRayquazaTornadoSpawnPos[32];
extern const s16 gRayquazaCloudScrollPositions[];
extern const u16 gRayquazaLightningWarningStrikeOamData[39][6][3];
extern const u16 gRayquazaHitBurstOamData[10][5][3];
extern const u16 gRayquazaWhirlwindGrabOamData[20][2][3];
extern const u16 gRayquazaLightningStrikeOamData[12][7][3];
extern const u16 gRayquazaLightningChargeRingOamData[10][3][3];
extern const u16 gRayquazaMainBodyOamData[212][3];

void RayquazaBoardProcess_3A_3E79C(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 10;
    for (i = 0; i < frame; i++)
        Random();

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_ACTIVE;
    gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_INTRO;
    if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + RAYQUAZA_MODE_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_INITIAL_SPAWN;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = TRUE;
    gCurrentPinballGame->cameraYAdjust = -88;
    gCurrentPinballGame->boardEntityCollisionMode = 1;
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballGrabbed = FALSE;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->returnToMainBoardFlag = FALSE;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->ballWhirlwindFallAcceleration = 0;
    gCurrentPinballGame->ballWhirlwindLiftY = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;

    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionLogicPosition[i].x = 0;
        gCurrentPinballGame->minionLogicPosition[i].y = 0;
    }

    gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_SPAWN;
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
    gCurrentPinballGame->orbLogicPosition.x = 0;
    gCurrentPinballGame->orbLogicPosition.y = 0;
    gCurrentPinballGame->orbCollisionPosition.x = 0;
    gCurrentPinballGame->orbCollisionPosition.y = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_INIT;
        gCurrentPinballGame->vortexTargetWaypointIndex[i] = 0;
        gCurrentPinballGame->vortexAnimTimer[i] = 0;
        gCurrentPinballGame->vortexScreenPosition[i].x = 0;
        gCurrentPinballGame->vortexScreenPosition[i].y = 0;
        gCurrentPinballGame->vortexOrbitCenter[i].x = 0;
        gCurrentPinballGame->vortexOrbitCenter[i].y = 0;
    }

    gCurrentPinballGame->impactShakeTimer = 0;
    gCurrentPinballGame->ballGrabShakeTimer = 0;
    gCurrentPinballGame->ballGrabFlashTimer = 0;
    gCurrentPinballGame->ballGrabTimer = 0;
    gCurrentPinballGame->windAttackCount = 0;
    gCurrentPinballGame->whirlwindHitIndex = 0;
    gCurrentPinballGame->introSequencePhase = 0;
    gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_INACTIVE;
    gCurrentPinballGame->horizontalShakeTimer = 0;
    gCurrentPinballGame->roarBrightnessFlashTimer = 0;
    gCurrentPinballGame->bossInvulnTimer = 0;
    gCurrentPinballGame->hitBurstAnimFrame = 0;
    gCurrentPinballGame->lightningAttackAnimFrame = 0;
    gCurrentPinballGame->bossSineAngle = 0;
    gCurrentPinballGame->windCloudSpawnTimer = 0;
    gCurrentPinballGame->introFrameCounter = 0;
    gCurrentPinballGame->bgScrollSpeed = 0;
    gCurrentPinballGame->bossHeadScreenY = 0;
    gCurrentPinballGame->lightningTargetPosition.x = 0;
    gCurrentPinballGame->lightningTargetPosition.y = 0;
    gCurrentPinballGame->whirlwindHitPosition.x = 0;
    gCurrentPinballGame->whirlwindHitPosition.y = 0;
    gCurrentPinballGame->windEntityPosition.x = 0;
    gCurrentPinballGame->windEntityPosition.y = 0;
    gCurrentPinballGame->windCloudPosition.x = 0;
    gCurrentPinballGame->windCloudPosition.y = 0;
    gCurrentPinballGame->flippersDisabled = TRUE;
    UpdateRayquazaIntroSequence();
    DmaCopy16(3, gRayquazaSkyBackgroundGfx, (void *)0x06015800, 0x2800);
    DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x06011620, 0x860);
    UpdateRayquazaEntityLogic();
    RenderRayquazaSprites();
    DmaCopy16(3, gBonusStageObjPal, OBJ_PLTT_SLOT(9), 0x20);
}

void RayquazaBoardProcess_3B_3EB2C(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case LEGENDARY_BOARD_STATE_INTRO:
        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
        if (gCurrentPinballGame->introSequencePhase == 1)
        {
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_BATTLE_PHASE;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case LEGENDARY_BOARD_STATE_BATTLE_PHASE:
        break;
    case LEGENDARY_BOARD_STATE_SUCCESS_BANNER:
        gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SUCCESS_SCORING;
        gCurrentPinballGame->stageTimer = 0;
        gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER].active = TRUE;
        gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE].active = TRUE;
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
        gCurrentPinballGame->bannerSlideYOffset = 136;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    case LEGENDARY_BOARD_STATE_SUCCESS_SCORING:
        ProcessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_RAYQUAZA_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_RAYQUAZA_BONUS_COMPLETE;
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
        DmaCopy16(3, gRayquazaBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_RAYQUAZA_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_RAYQUAZA_BONUS_COMPLETE;
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
            gCurrentPinballGame->shopExtraBallPreviouslyPurchased = FALSE;
        }
        break;
    case LEGENDARY_BOARD_STATE_SCORE_COUNTING_FINISHED:
        ProcessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = TRUE;
        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    }

    UpdateRayquazaIntroSequence();
    UpdateRayquazaMinionsAndEffects();
    UpdateRayquazaEntityLogic();
    RenderRayquazaSprites();
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

void UpdateRayquazaEntityLogic(void)
{
    if (gCurrentPinballGame->bossHitFlashTimer)
    {
        gCurrentPinballGame->bossHitFlashTimer--;
        gCurrentPinballGame->legendaryFlashState = 1;
        if (gCurrentPinballGame->bossHitFlashTimer == 5)
        {
            m4aSongNumStart(SE_RAYQUAZA_HIT);
            gCurrentPinballGame->scoreAddedInFrame = SCORE_RAYQUAZA_HIT;
            gCurrentPinballGame->bonusModeHitCount++;
            PlayRumble(7);
            if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired 
                && gCurrentPinballGame->bossEntityState != RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK)
                gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_SUFFICIENT_HITS;
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
    case RAYQUAZA_ENTITY_STATE_SPAWN:
        gCurrentPinballGame->bossPositionX = 1140;
        gCurrentPinballGame->bossPositionY = 2400;
        gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_ENTRY;
        gCurrentPinballGame->bossFramesetIndex = 13;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossMovementPhase = 0;
        gCurrentPinballGame->bossHeadScreenY = 0;
        break;
    case RAYQUAZA_ENTITY_STATE_ENTRY:
        if (gCurrentPinballGame->introFrameCounter > 530)
        {
            if (gCurrentPinballGame->bossPositionY > -1200)
                gCurrentPinballGame->bossPositionY -= 70;

            if (gCurrentPinballGame->introFrameCounter == 672)
            {
                gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_BOUNCE_IN_PLACE;
                gCurrentPinballGame->bossPositionX = 0;
                gCurrentPinballGame->bossPositionY = -640;
            }
        }

        if (gCurrentPinballGame->introFrameCounter == 530)
            gCurrentPinballGame->bossRoarTimer = 25;
        break;
    case RAYQUAZA_ENTITY_STATE_BOUNCE_IN_PLACE:
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
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_BOUNCES_SIDEWAYS;
            gCurrentPinballGame->bossMovementPhase = 0;
            gCurrentPinballGame->bossNextAttackState = RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_LANDS:
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
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_BOUNCES_SIDEWAYS;
            gCurrentPinballGame->bossMovementPhase = 0;
            gCurrentPinballGame->bossNextAttackState = RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_FLIES_UP:
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
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_WAIT_FOR_FLYBY;
            gCurrentPinballGame->bossMovementPhase = 0;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_BOUNCES_SIDEWAYS:
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
                else if (gCurrentPinballGame->bossNextAttackState == RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK)
                {
                    if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired - 1)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 13;
                        gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_FLIES_UP;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 98;
                        gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 13;
                    gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_FLIES_UP;
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
    case RAYQUAZA_ENTITY_STATE_LIGHTNING_ATTACK:
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
                gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_BOUNCES_SIDEWAYS;
                gCurrentPinballGame->bossNextAttackState = RAYQUAZA_ENTITY_STATE_FLIES_UP;
                gCurrentPinballGame->legendaryFlashState = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 114)
            {
                if (gCurrentPinballGame->bossMovementPhase == 0)
                {
                    gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_CHARGE_RING].active = TRUE;
                    gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_WARNING_STRIKE].active = TRUE;
                    gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_STRIKE].active = TRUE;
                    gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_CHARGING;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 120)
                gCurrentPinballGame->bossRoarTimer = 21;

            if (gCurrentPinballGame->bossFramesetIndex == 124)
                gCurrentPinballGame->roarBrightnessFlashTimer = 16;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_WAIT_FOR_FLYBY:
        if (gCurrentPinballGame->bossFrameTimer < 120)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_FLYBY;
            DmaCopy16(3, gRayquazaWindBoardGfx, (void *)0x06015800, 0x1C00);
            if (gCurrentPinballGame->windAttackCount & 1)
            {
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_RIGHT].active = TRUE;
                gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0A].active = TRUE;
                gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0B].active = TRUE;
            }
            else
            {
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_LEFT].active = TRUE;
                gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0A].active = TRUE;
                gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0B].active = TRUE;
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
    case RAYQUAZA_ENTITY_STATE_FLYBY:
        if (gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_RIGHT].active)
        {
            if (gCurrentPinballGame->windEntityPosition.x < 4800)
                gCurrentPinballGame->windEntityPosition.x += 140;
            else
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_RIGHT].active = FALSE;

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
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_LEFT].active = FALSE;

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
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_LANDS;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_SUFFICIENT_HITS:
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;
        if (gCurrentPinballGame->numCompletedBonusStages % 10 == 9)
        {
            // Catch Rayquaza
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_CAPTURE;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT].active = TRUE;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT_BORDERS].active = TRUE;
            gCurrentPinballGame->currentSpecies = SPECIES_RAYQUAZA;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
        }
        else
        {
            // Normal Completion
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_YELLS;
            gCurrentPinballGame->bossFramesetIndex = 98;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_DISABLED;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        gCurrentPinballGame->bossFrameTimer = 0;
        if (gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_BALL_GRAB_FX].active)
            gCurrentPinballGame->ballGrabTimer = 1;
        break;
    case RAYQUAZA_ENTITY_STATE_YELLS:
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
                gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_DEPARTS;
                gCurrentPinballGame->legendaryFlashState = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 120)
                gCurrentPinballGame->bossRoarTimer = 21;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_DEPARTS:
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
                gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_BOARD_CLEANUP;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

        break;
    case RAYQUAZA_ENTITY_STATE_BOARD_CLEANUP:
        DmaCopy16(3, gRayquazaSpriteSheet, (void *)0x06011620, 0x860);
        gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_FLYDOWN;
        gCurrentPinballGame->bossPositionX = 1140;
        gCurrentPinballGame->bossPositionY = -1200;
        gCurrentPinballGame->introSequencePhase = 2;
        gCurrentPinballGame->introFrameCounter = 0;
        gCurrentPinballGame->cameraLocked = TRUE;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        gMain.spriteGroups[SG_RAYQUAZA_FLYING_SPARKLE].active = TRUE;
        gCurrentPinballGame->minionLogicPosition[0].x = 0;
        gCurrentPinballGame->minionLogicPosition[0].y = -5000;
        gCurrentPinballGame->minionLogicPosition[1].x = 1400;
        gCurrentPinballGame->minionLogicPosition[1].y = -2000;
        gCurrentPinballGame->orbCollisionPosition.x = -200;
        gCurrentPinballGame->orbCollisionPosition.y = 800;
        gCurrentPinballGame->orbLogicPosition.x = 24;
        gCurrentPinballGame->orbLogicPosition.y = -16;
        break;
    case RAYQUAZA_ENTITY_STATE_FLYDOWN:
        if (gCurrentPinballGame->introFrameCounter < 256)
        {
            if (gCurrentPinballGame->bossFrameTimer < 80)
                gCurrentPinballGame->bossFrameTimer++;
            else if (gCurrentPinballGame->bossPositionY < 2400)
                gCurrentPinballGame->bossPositionY += 80;
        }
        else
        {
            gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SUCCESS_BANNER;
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->bossEntityState = RAYQUAZA_ENTITY_STATE_FINISHED;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_CAPTURE:
        gCurrentPinballGame->ballWhirlwindLiftY = 1;
        if (gCurrentPinballGame->bossAttackTimer > -500)
        {
            gCurrentPinballGame->bossAttackTimer += (-500 - gCurrentPinballGame->bossAttackTimer) / 30;
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->bossAttackTimer / 10;
            if (gCurrentPinballGame->cameraYAdjust < -38)
                gCurrentPinballGame->cameraYAdjust = -38;
        }
        break;
    case RAYQUAZA_ENTITY_STATE_FINISHED:
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
    group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BACKGROUND_FLY_DOWN];
    if (group->active)
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

    group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BACKGROUND_FLY_UP];
    if (group->active)
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
            group->active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BOUNCING].active = TRUE;
            gMain.spriteGroups[SG_RAYQUAZA_ENTITY_SHADOW_FX].active = TRUE;
        }
    }
    else
    {
        group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BOUNCING];
        if (group->active)
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

        group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_ROAR_HEAD_EXTENSION];
        if (group->active)
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

        group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_SHADOW_FX];
        if (group->active)
        {
            s16 var2 = (gCurrentPinballGame->bossHeadScreenY - 70) / 3 + 1;
            if (var2 < 0)
                var2 = 0;
            else if (var2 > 9)
                var2 = 9;

            if (gCurrentPinballGame->bossEntityState != RAYQUAZA_ENTITY_STATE_CAPTURE)
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

            if (gCurrentPinballGame->bossEntityState == RAYQUAZA_ENTITY_STATE_BOARD_CLEANUP)
            {
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BACKGROUND_FLY_DOWN].active = TRUE;
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_BOUNCING].active = FALSE;
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_SHADOW_FX].active = FALSE;
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_ROAR_HEAD_EXTENSION].active = FALSE;
            }

            if (gCurrentPinballGame->captureSequenceTimer == 21)
            {
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_SHADOW_FX].active = FALSE;
                gMain.spriteGroups[SG_RAYQUAZA_ENTITY_ROAR_HEAD_EXTENSION].active = FALSE;
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
    int squaredDistance;
    u16 *dst;
    const u16 *src;
    struct OamDataSimple *oamSimple;

    sp8 = 0;
    sp4 = 0;
    var0 = 0;
    sp0 = 0;

    //screen, used for catch mon display.
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

    UpdateLightningGrabEntity();

    switch (gCurrentPinballGame->lightningAttackState)
    {
    case RAYQUAZA_LIGHTNING_STATE_INACTIVE:
        gCurrentPinballGame->lightningAttackAnimFrame = 0;
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        break;
    case RAYQUAZA_LIGHTNING_STATE_CHARGING:
        if (gCurrentPinballGame->lightningAttackAnimFrame == 0)
            m4aSongNumStart(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame == 8)
            m4aSongNumStop(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame == 24)
            m4aSongNumStart(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame == 36)
            m4aSongNumStop(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame == 50)
            m4aSongNumStart(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame == 56)
            m4aSongNumStop(SE_RAYQUAZA_LIGHTNING_CHARGE);

        if (gCurrentPinballGame->lightningAttackAnimFrame < 14)
            var0 = gCurrentPinballGame->lightningAttackAnimFrame / 2;
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 42)
            var0 = 7;
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 56)
            var0 = (gCurrentPinballGame->lightningAttackAnimFrame - 42) / 2;
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 61)
            var0 = 7;
        else
            var0 = (gCurrentPinballGame->lightningAttackAnimFrame - 61) / 2;

        if (gCurrentPinballGame->lightningAttackAnimFrame < 8)
            sp4 = gCurrentPinballGame->lightningAttackAnimFrame / 2;
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 48)
            sp4 = 12;
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 64)
            sp4 = (gCurrentPinballGame->lightningAttackAnimFrame - 48) / 2 + 4;
        else
            sp4 = 12;

        sp8 = 5;
        gCurrentPinballGame->lightningAttackAnimFrame++;
        if (gCurrentPinballGame->lightningAttackAnimFrame == 75)
        {
            gCurrentPinballGame->lightningAttackAnimFrame = 0;
            gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_TARGET_BALL;
        }
        break;
    case RAYQUAZA_LIGHTNING_STATE_TARGET_BALL:
        var0 = 7;
        sp4 = 12;
        sp8 = 5;
        if (gCurrentPinballGame->lightningAttackAnimFrame < 34)
        {
            gCurrentPinballGame->lightningAttackAnimFrame++;
            if (gCurrentPinballGame->lightningAttackAnimFrame == 28)
            {
                if (gCurrentPinballGame->ballRespawnState)
                {
                    gCurrentPinballGame->lightningTargetPosition.x = 200 - (Random() % 160);
                    gCurrentPinballGame->lightningTargetPosition.y = gCurrentPinballGame->ball->positionQ0.y - 347 - (Random() % 80);
                }
                else
                {
                    gCurrentPinballGame->lightningTargetPosition.x = gCurrentPinballGame->ball->positionQ0.x - 13;
                    gCurrentPinballGame->lightningTargetPosition.y = gCurrentPinballGame->ball->positionQ0.y - 347;
                }
            }
        }
        else
        {
            gCurrentPinballGame->lightningAttackAnimFrame = 0;
            gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_STRIKING;
            m4aSongNumStart(SE_RAYQUAZA_FLYBY);
        }
        break;
    case RAYQUAZA_LIGHTNING_STATE_STRIKING:
        var0 = 7;
        sp4 = 12;
        if (gCurrentPinballGame->lightningAttackAnimFrame < 2)
        {
            sp8 = gCurrentPinballGame->lightningAttackAnimFrame;
        }
        else if (gCurrentPinballGame->lightningAttackAnimFrame < 10)
        {
            sp8 = (gCurrentPinballGame->lightningAttackAnimFrame - 2) / 2 + 2;
            gCurrentPinballGame->horizontalShakeTimer = sp4;
            if (sp8 == 2)
            {
                int a = 13;
                int b = 347;
                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - a - gCurrentPinballGame->lightningTargetPosition.x;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - b - gCurrentPinballGame->lightningTargetPosition.y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredDistance = xx + yy;

                PlayRumble(8);
                if (gCurrentPinballGame->vortexEntityState[0] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                    && gCurrentPinballGame->vortexEntityState[1] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                    && !gCurrentPinballGame->ballRespawnState
                    && squaredDistance < 200)
                {
                    gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_BALL_GRAB_FX].active = TRUE;
                    gCurrentPinballGame->ballGrabTimer = 600;
                    m4aSongNumStart(SE_RAYQUAZA_LIGHTNING_TRAP);
                    PlayRumble(9);
                }
            }
        }
        else
        {
            sp8 = 5;
            gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_4;
        }

        gCurrentPinballGame->lightningAttackAnimFrame++;
        break;
    case RAYQUAZA_LIGHTNING_STATE_4:
        gCurrentPinballGame->lightningAttackAnimFrame = 0;
        gCurrentPinballGame->lightningAttackState = RAYQUAZA_LIGHTNING_STATE_INACTIVE;
        break;
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_CHARGE_RING];
    if (group->active)
    {
        // ! odd behavior in the assembly with the addition and subtraction
        group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
        group->baseY = gCurrentPinballGame->bossPositionY / 10 - gCurrentPinballGame->cameraYOffset + 96;
        for (j = 0; j < 3; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaLightningChargeRingOamData[var0][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->lightningAttackState == RAYQUAZA_LIGHTNING_STATE_4)
            gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_CHARGE_RING].active = FALSE;
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_WARNING_STRIKE];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->bossPositionX / 10 - (gCurrentPinballGame->cameraXOffset - 88);
        group->baseY = gCurrentPinballGame->bossPositionY / 10 - gCurrentPinballGame->cameraYOffset + 96;
        for (j = 0; j < 6; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaLightningWarningStrikeOamData[sp4][j];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }

        if (gCurrentPinballGame->lightningAttackState == RAYQUAZA_LIGHTNING_STATE_4)
            gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_WARNING_STRIKE].active = FALSE;
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_STRIKE];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->lightningTargetPosition.x - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->lightningTargetPosition.y - gCurrentPinballGame->cameraYOffset;
        for (j = 0; j < 7; j++)
        {
            oamSimple = &group->oam[j];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gRayquazaLightningStrikeOamData[sp8][j];
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

        if (gCurrentPinballGame->lightningAttackState == RAYQUAZA_LIGHTNING_STATE_4)
            gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_STRIKE].active = FALSE;
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_RIGHT];
    if (group->active)
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

    group = &gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_LEFT];
    if (group->active)
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

    if (gCurrentPinballGame->ballWhirlwindLiftY > 0)
        gCurrentPinballGame->ball->oamPriority = 1;
    else
        gCurrentPinballGame->ball->oamPriority = 2;

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[SG_RAYQUAZA_TORNADO_BASE + i];
        switch (gCurrentPinballGame->vortexEntityState[i])
        {
        case RAYQUAZA_WHIRLWIND_STATE_INIT:
            sp0 = 0;
            gCurrentPinballGame->vortexScreenPosition[i].x = 0;
            gCurrentPinballGame->vortexScreenPosition[i].y = 0;
            break;
        case RAYQUAZA_WHIRLWIND_STATE_SPAWN:
            sp0 = gCurrentPinballGame->vortexAnimTimer[i] / 5 + 1;
            if (gCurrentPinballGame->vortexAnimTimer[i] < 14)
            {
                gCurrentPinballGame->vortexAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->vortexAnimTimer[i] = 0;
                gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_FULL;
            }
            break;
        case RAYQUAZA_WHIRLWIND_STATE_FULL:
            sp0 = gCurrentPinballGame->vortexAnimTimer[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            if (gCurrentPinballGame->vortexEntityState[i] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL)
            {

                s16 angle = (((gMain.systemFrameCount + 120 * i) % 240) << 0x10) / 240;
                gCurrentPinballGame->vortexScreenPosition[i].x = gCurrentPinballGame->vortexOrbitCenter[i].x + (Cos(angle) * 4) / 2000;
                gCurrentPinballGame->vortexScreenPosition[i].y = gCurrentPinballGame->vortexOrbitCenter[i].y + (Sin(angle) * 4) / 2000;

                tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->vortexScreenPosition[i].x / 10) - 16;
                tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->vortexScreenPosition[i].y / 10) - 32;;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredDistance = xx + yy;
                if (!gCurrentPinballGame->ballGrabbed
                    && !gCurrentPinballGame->ballRespawnState
                    && gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired
                    && gCurrentPinballGame->bossHitFlashTimer == 0 && squaredDistance < 300)
                {
                    gCurrentPinballGame->ballGrabTimer = 6;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL;
                    gCurrentPinballGame->cameraLocked = TRUE;

                    tempVector2.x = gCurrentPinballGame->vortexScreenPosition[i].x / 10 + 16;
                    tempVector2.y = gCurrentPinballGame->vortexScreenPosition[i].y / 10 + 32;
                    tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                    tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                    gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                    gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
                    gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

                    gCurrentPinballGame->whirlwindHitIndex = i + 1;
                    gCurrentPinballGame->whirlwindHitPosition.x = gCurrentPinballGame->vortexScreenPosition[i].x;
                    gCurrentPinballGame->whirlwindHitPosition.y = gCurrentPinballGame->vortexScreenPosition[i].y;
                    m4aSongNumStart(SE_RAYQUAZA_WHIRLWIND_BALL_LAUNCH);
                    PlayRumble(13);
                }
            }

            if (gCurrentPinballGame->vortexAnimTimer[i] < 840)
            {
                gCurrentPinballGame->vortexAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->vortexAnimTimer[i] = 0;
                gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_SHRUNK;
            }
            break;
        case RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL: {
            s16 var4;
            int var5;

            sp0 = gCurrentPinballGame->vortexAnimTimer[i] % 16;
            if (sp0 < 4)
                sp0 = 4;
            else if (sp0 < 10)
                sp0 = 5;
            else
                sp0 = 6;

            var4 = 29 - gCurrentPinballGame->vortexAnimTimer[i];
            if (var4 < 10)
                var4 = 10;

            gCurrentPinballGame->trapAngleQ16 -= ((ANGLE_45 - (var4 * ANGLE_45) / 30) * 2) / 5;
            gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
            var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 30;
            tempVector2.x = gCurrentPinballGame->vortexScreenPosition[i].x / 10 + 16;
            tempVector2.y = gCurrentPinballGame->vortexScreenPosition[i].y / 10 + 32;
            gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8) + ((Cos(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
            gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8) - ((Sin(gCurrentPinballGame->trapAngleQ16) * var5) / 20000);
            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

            if (gCurrentPinballGame->ballWhirlwindLiftY < 1800)
            {
                gCurrentPinballGame->ballWhirlwindFallAcceleration = 0;
                gCurrentPinballGame->ballWhirlwindLiftY += 32;
            }

            if (gCurrentPinballGame->vortexAnimTimer[i] < 180)
            {
                gCurrentPinballGame->vortexAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->vortexAnimTimer[i] = 0;
                gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_SHRINKING_CAUGHT_BALL;
                gCurrentPinballGame->trapSpinRadius /= 2;
                gCurrentPinballGame->ball->positionQ8.y = 0xA500;
            }
            break;
        }
        case RAYQUAZA_WHIRLWIND_STATE_SHRINKING_CAUGHT_BALL:
            if (gCurrentPinballGame->vortexAnimTimer[i] < 130)
            {
                if (gCurrentPinballGame->vortexAnimTimer[i] == 10)
                    m4aSongNumStart(SE_RAYQUAZA_WHIRLWIND_BALL_LAND);

                gCurrentPinballGame->ballWhirlwindFallAcceleration--;
                gCurrentPinballGame->ballWhirlwindLiftY += gCurrentPinballGame->ballWhirlwindFallAcceleration;
                if (gCurrentPinballGame->ballWhirlwindLiftY <= 0)
                {
                    gCurrentPinballGame->ballWhirlwindLiftY = 0;
                    gCurrentPinballGame->ball->velocity.y = -((gCurrentPinballGame->ballWhirlwindFallAcceleration * 0x80) / 10) / 2;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = 0;
                    gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_INIT;
                    gCurrentPinballGame->cameraLocked = FALSE;
                    PlayRumble(8);
                }

                gCurrentPinballGame->vortexAnimTimer[i]++;
            }
            break;
        case RAYQUAZA_WHIRLWIND_STATE_SHRUNK:
            sp0 = gCurrentPinballGame->vortexAnimTimer[i] / 6 + 7;
            if (gCurrentPinballGame->vortexAnimTimer[i] < 11)
            {
                gCurrentPinballGame->vortexAnimTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->vortexAnimTimer[i] = 0;
                gCurrentPinballGame->vortexEntityState[i] = RAYQUAZA_WHIRLWIND_STATE_INIT;
            }
            break;
        }

        if (group->active)
        {
            DmaCopy16(3, gRayquazaTornadoGfx[sp0], (void *)0x06011EA0, 0x280);
            group->baseX = gCurrentPinballGame->vortexScreenPosition[i].x / 10 - gCurrentPinballGame->cameraXOffset;
            group->baseY = gCurrentPinballGame->vortexScreenPosition[i].y / 10 - gCurrentPinballGame->cameraYOffset;
            for (j = 0; j < 2; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }

            if (gCurrentPinballGame->vortexEntityState[i] == RAYQUAZA_WHIRLWIND_STATE_INIT)
                group->active = FALSE;

            if (gCurrentPinballGame->whirlwindHitIndex && i == (gCurrentPinballGame->whirlwindHitIndex - 1))
                group->active = FALSE;
        }
    }

    RenderWindCloudSprites();
    group = &gMain.spriteGroups[SG_RAYQUAZA_WHIRLWIND_BALL_FLY_UP];
    if (group->active)
    {
        s16 a;
        group->baseX = gCurrentPinballGame->whirlwindHitPosition.x / 10 - gCurrentPinballGame->cameraXOffset;
        group->baseY = gCurrentPinballGame->whirlwindHitPosition.y / 10 - gCurrentPinballGame->cameraYOffset;
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
                group->active = FALSE;
        }
    }

    if (gCurrentPinballGame->whirlwindHitIndex)
    {
        gCurrentPinballGame->whirlwindHitIndex = 0;
        gCurrentPinballGame->hitBurstAnimFrame = 0;
        group->active = TRUE;
    }
}

void UpdateLightningGrabEntity(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    u16 *dst;
    const u16 *src;

    group = &gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_BALL_GRAB_FX];
    if (!group->active)
        return;

    gCurrentPinballGame->ballGrabTimer--;
    if (gCurrentPinballGame->ballGrabTimer > 5)
    {
        var0 = gLightningGrabAnimFrameIndices[(gCurrentPinballGame->ballGrabTimer % 33) / 3];
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
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
            {
                gCurrentPinballGame->ballGrabTimer -= 30;
                if (gCurrentPinballGame->ballGrabTimer < 5)
                    gCurrentPinballGame->ballGrabTimer = 5;

                gCurrentPinballGame->ballGrabShakeTimer = 7;
                m4aSongNumStart(SE_RAYQUAZA_LIGHTNING_TRAP);
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
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
                gCurrentPinballGame->ballGrabFlashTimer = 60;
        }

    }
    else
    {
        var0 = 8;
    }

    if (gCurrentPinballGame->ballGrabTimer == 0)
    {
        gMain.spriteGroups[SG_RAYQUAZA_LIGHTNING_BALL_GRAB_FX].active = FALSE;
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

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset + 128);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 14; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 9; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2A];
    if (group->active)
    {
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 15; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2B];
        group->baseX = gCurrentPinballGame->windCloudPosition.x / 10 - (gCurrentPinballGame->cameraXOffset - 368);
        group->baseY = gCurrentPinballGame->windCloudPosition.y / 10 - (gCurrentPinballGame->cameraYOffset - 90);
        for (i = 0; i < 12; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gMain.spriteGroups[SG_RAYQUAZA_ENTITY_FLYBY_RIGHT].active)
    {
        if (gCurrentPinballGame->windCloudSpawnTimer == 6)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_0B].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1A].active = TRUE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1B].active = TRUE;
            if (gCurrentPinballGame->vortexEntityState[0] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                && gCurrentPinballGame->vortexEntityState[1] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                && !gCurrentPinballGame->ballRespawnState)
            {
                gCurrentPinballGame->ball->velocity.x += 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 11)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_1B].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2A].active = TRUE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2B].active = TRUE;
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 14)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_RIGHT_WIND_SPEEDLINES_2B].active = FALSE;
        }
    }
    else
    {
        if (gCurrentPinballGame->windCloudSpawnTimer == 6)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_0B].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1A].active = TRUE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1B].active = TRUE;
            if (gCurrentPinballGame->vortexEntityState[0] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                && gCurrentPinballGame->vortexEntityState[1] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL
                && !gCurrentPinballGame->ballRespawnState)
            {
                gCurrentPinballGame->ball->velocity.x -= 500;
                PlayRumble(13);
            }
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 11)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_1B].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2A].active = TRUE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2B].active = TRUE;
        }

        if (gCurrentPinballGame->windCloudSpawnTimer == 14)
        {
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2A].active = FALSE;
            gMain.spriteGroups[SG_RAYQUAZA_FLYBY_LEFT_WIND_SPEEDLINES_2B].active = FALSE;
        }
    }

    if (gCurrentPinballGame->windCloudSpawnTimer == 10)
    {
        if (gCurrentPinballGame->vortexEntityState[0] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL)
        {
            gCurrentPinballGame->vortexAnimTimer[0] = 0;
            gCurrentPinballGame->vortexEntityState[0] = RAYQUAZA_WHIRLWIND_STATE_SPAWN;
            gMain.spriteGroups[SG_RAYQUAZA_TORNADO_0].active = TRUE;
            rand = Random() % 8;
            var0 = ((gMain.systemFrameCount % 240) << 0x10) / 240;
            gCurrentPinballGame->vortexOrbitCenter[0].x = gRayquazaTornadoSpawnPos[rand].x;
            gCurrentPinballGame->vortexOrbitCenter[0].y = gRayquazaTornadoSpawnPos[rand].y;
            gCurrentPinballGame->vortexScreenPosition[0].x = gCurrentPinballGame->vortexOrbitCenter[0].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->vortexScreenPosition[0].y = gCurrentPinballGame->vortexOrbitCenter[0].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_RAYQUAZA_SONIC_BOOM);
        }
    }

    if (gCurrentPinballGame->windCloudSpawnTimer == 16)
    {
        if (gCurrentPinballGame->vortexEntityState[1] < RAYQUAZA_WHIRLWIND_STATE_FULL_CAUGHT_BALL)
        {
            gCurrentPinballGame->vortexAnimTimer[1] = 0;
            gCurrentPinballGame->vortexEntityState[1] = RAYQUAZA_WHIRLWIND_STATE_SPAWN;
            gMain.spriteGroups[SG_RAYQUAZA_TORNADO_1].active = TRUE;
            rand = (Random() % 8 + 8) % 32; // Force 8 to be added to r1
            var0 = (((gMain.systemFrameCount + 120) % 240) << 0x10) / 240;
            gCurrentPinballGame->vortexOrbitCenter[1].x = gRayquazaTornadoSpawnPos[rand].x;
            gCurrentPinballGame->vortexOrbitCenter[1].y = gRayquazaTornadoSpawnPos[rand].y;
            gCurrentPinballGame->vortexScreenPosition[1].x = gCurrentPinballGame->vortexOrbitCenter[1].x + (Cos(var0) * 4) / 2000;
            gCurrentPinballGame->vortexScreenPosition[1].y = gCurrentPinballGame->vortexOrbitCenter[1].y + (Sin(var0) * 4) / 2000;
            m4aSongNumStart(SE_RAYQUAZA_SONIC_BOOM);
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
                gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;

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

            group = &gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_0];
            if (group->active)
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

            group = &gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_1];
            if (group->active)
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

            group = &gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_2];
            if (group->active)
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
                gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_0].active = FALSE;
                gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_1].active = FALSE;
                gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_2].active = FALSE;
            }

            group = &gMain.spriteGroups[SG_RAYQUAZA_FLYING_SPARKLE];
            if (group->active)
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
                gMain.spriteGroups[SG_RAYQUAZA_FLYING_SPARKLE].active = TRUE;
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
                gMain.spriteGroups[SG_RAYQUAZA_FLYING_SPARKLE].active = FALSE;
        }
    }

    if (gCurrentPinballGame->introSequencePhase == 2)
    {
        if (gCurrentPinballGame->introFrameCounter < 256)
        {
            gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->introFrameCounter / -2;
            gCurrentPinballGame->introFrameCounter++;
        }

        group = &gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_0];
        if (group->active)
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

        group = &gMain.spriteGroups[SG_RAYQUAZA_INTRO_CLOUD_1];
        if (group->active)
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

        group = &gMain.spriteGroups[SG_RAYQUAZA_FLYING_SPARKLE];
        if (group->active)
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
        gCurrentPinballGame->flippersDisabled = FALSE;
    else
        gCurrentPinballGame->flippersDisabled = TRUE;

    gMain.bgOffsets[2].yOffset += gCurrentPinballGame->bgScrollSpeed;
    gMain.bgOffsets[1].yOffset += gCurrentPinballGame->bgScrollSpeed;
    gMain.bgOffsets[3].yOffset += gCurrentPinballGame->bgScrollSpeed / 4 + 224;
}

