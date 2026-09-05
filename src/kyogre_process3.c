#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/kyogre_states.h"
#include "constants/board/center_screen_states.h"

#define KYOGRE_MODE_TIME TICKS_FOR_TIME(3,0)

extern const u8 gKyogreBonusClear_Gfx[];
extern const Palette gKyogreWaterAnimFrame_Pals[];
extern const u16 gKyogreWaterBackgroundTilemap[];
extern const Palette gKyogreIntroShorePalette[];
extern const Palette gKyogreIntroIcePalette[];
extern const u8 gKyogreSplashSpriteFrames[][0xC0];
extern const u8 gKyogreWhirlpoolSpriteFrames[][0x3C0];
extern const u8 gKyogreBodySprites_First15[][0x580];
extern const u8 gKyogreBodySprites_After15[][0x4C0];
extern const u8 gKyogreWhirlpoolMinionSprites[][0x200];
extern struct SongHeader se_kyogre_hit;
extern struct SongHeader se_kyogre_breach_surface;
extern struct SongHeader se_kyogre_dive;
extern struct SongHeader se_kyogre_spawn_whirlpool;
extern struct SongHeader se_kyogre_freeze_ring;
extern struct SongHeader se_kyogre_departs;
extern const Palette *gKyogreFadeInPaletteProgression[];
extern const u16 gKyogreAnimFramesetTable[][3];
extern const s16 gKyogreRisingPaletteCycleIndices[];
extern const s16 gKyogreSplashAnimIndices[];
extern const struct Vector16 gKyogreWhirlpoolTargetPositions[];
extern const s16 gShockwaveSplashDistanceThresholds[];
extern const s16 gKyogrefreezeTrapAnimFrameset[][3];
extern const s16 gWaterTilePaletteCycle[];
extern const s16 gKyogreWaterPaletteSegmentCycle[];
extern const s16 gKyogreBgTileVariantCycle[];
extern const u16 gKyogreBgSpriteBaseTileNums[];
extern const s16 gKyogreIntroPaletteCycleIndices[];
extern const u16 gKyogrefreezeTrapOamData[28][4][3];
extern const u16 gKyogreMainBodyOamData[66][10][3];


void KyogreBoardProcess_3A_383E4(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_ACTIVE;
    gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_INTRO;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_NONE;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + KYOGRE_MODE_TIME;
    gCurrentPinballGame->timerBonus = 0;
    if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        gCurrentPinballGame->legendaryHitsRequired = 18;
    else
        gCurrentPinballGame->legendaryHitsRequired = 15;

    gCurrentPinballGame->bossRoarTimer = 0;
    gCurrentPinballGame->legendaryFlashState = 0;
    gCurrentPinballGame->ballGrabbed = FALSE;
    gCurrentPinballGame->bossLightFadeInCounter = 0;
    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_INITIAL_SPAWN;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = TRUE;
    gCurrentPinballGame->returnToMainBoardFlag = FALSE;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->bossAttackTimer = 0;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_NONE;
    gCurrentPinballGame->portraitDisplayState = PORTRAIT_DISPLAY_MODE_BANNER;
    gCurrentPinballGame->bossVulnerable = 14;
    gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_INIT;
    gCurrentPinballGame->bossPositionX = 0;
    gCurrentPinballGame->bossPositionY = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->shockwaveAlreadyHit = FALSE;
    gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_ENCLOSE_BALL;
    gCurrentPinballGame->freezeTrapAnimEndFrame = 0;
    gCurrentPinballGame->freezeTrapNextPhase = KYOGRE_FREEZE_PHASE_ENCLOSE_BALL;
    gCurrentPinballGame->freezeTrapAnimFrame = 0;
    gCurrentPinballGame->freezeTrapAnimLoopStart = 0;
    gCurrentPinballGame->freezeTrapLoopCount = 0;
    gCurrentPinballGame->freezeTrapPauseTimer = 0;
    gCurrentPinballGame->bossHitFlashTimer = 0;
    gCurrentPinballGame->freezeTrapFrameTimer = 0;
    gCurrentPinballGame->shockwaveAnimTimer = 0;
    gCurrentPinballGame->kyogreWaveTimer = 0;

    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_INIT;
        gCurrentPinballGame->vortexTargetWaypointIndex[i] = 0;
        gCurrentPinballGame->vortexAnimTimer[i] = 0;
        gCurrentPinballGame->vortexScreenPosition[i].x = 0;
        gCurrentPinballGame->vortexScreenPosition[i].y = 0;
        gCurrentPinballGame->vortexOrbitCenter[i].x = 0;
        gCurrentPinballGame->vortexOrbitCenter[i].y = 0;
    }

    for (i = 0; i < 4; i ++)
    {
        gCurrentPinballGame->shockwaveQuadrantOffset[i].x = 0;
        gCurrentPinballGame->shockwaveQuadrantOffset[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = TRUE;
    UpdateKyogreEntityLogic();
    RenderKyogreSprites();
    UpdateKyogreFieldEntities();
    AnimateKyogreBackground();
    m4aSongNumStart(MUS_BONUS_FIELD_KYOGRE);
    DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);
    DmaCopy16(3, gKyogreFadeInPaletteProgression[0][0], BG_PLTT, 8*PLTT_SLOT_SIZE);
    DmaCopy16(3, gBonusStageObjPal, OBJ_PLTT_SLOT(PAL_IX_9), PLTT_SLOT_SIZE);
}

void KyogreBoardProcess_3B_3869C(void)
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
            gCurrentPinballGame->bossLightFadeInCounter = (gCurrentPinballGame->stageTimer - 500) / 24;
            if (gCurrentPinballGame->bossLightFadeInCounter > 5)
                gCurrentPinballGame->bossLightFadeInCounter = 5;

            gCurrentPinballGame->stageTimer++;
            DmaCopy16(3, gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][0], PLTT, 3*PLTT_SLOT_SIZE);
            DmaCopy16(3, gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][4], BG_PLTT_SLOT(PAL_IX_4), 4*PLTT_SLOT_SIZE);
            if (gCurrentPinballGame->cameraYAdjust >= -32)
                gCurrentPinballGame->flippersDisabled = FALSE;
        } else
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
            DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_KYOGRE_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_KYOGRE_BONUS_COMPLETE;
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
        DmaCopy16(3, gKyogreBonusClear_Gfx, (void *)0x06015800, 0x2000);
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
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_KYOGRE_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_KYOGRE_BONUS_COMPLETE;
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
    }

    UpdateKyogreFieldEntities();
    UpdateKyogreEntityLogic();
    RenderKyogreSprites();
    AnimateKyogreBackground();

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

void UpdateKyogreEntityLogic(void)
{
    s16 i;
    s16 index;

    if (gCurrentPinballGame->bossHitFlashTimer)
    {
        gCurrentPinballGame->bossHitFlashTimer--;
        if (gCurrentPinballGame->bossEntityState != KYOGRE_ENTITY_STATE_PRESUMED_UNREACHABLE)
        {
            gCurrentPinballGame->legendaryFlashState = 1;
            if (gCurrentPinballGame->bossHitFlashTimer == 4)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_hit);
                PlayRumble(7);
                gCurrentPinballGame->scoreAddedInFrame = SCORE_KYOGRE_HIT;
                gCurrentPinballGame->bonusModeHitCount++;
                if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired &&
                    gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_TOP_POSITION)
                    gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_SUFFICIENT_HITS;
            }
        }

        if (gCurrentPinballGame->bossHitFlashTimer == 0)
            gCurrentPinballGame->legendaryFlashState = 0;
    }

    switch (gCurrentPinballGame->bossEntityState)
    {
    case KYOGRE_ENTITY_STATE_INIT:
        gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_ENTRY;
        gCurrentPinballGame->bossFramesetIndex = 12;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossPositionX = 0;
        gCurrentPinballGame->bossPositionY = 0;
        gCurrentPinballGame->kyogreWaveTimer = 0;
        break;
    case KYOGRE_ENTITY_STATE_ENTRY:
        index = gKyogreRisingPaletteCycleIndices[(gCurrentPinballGame->kyogreWaveTimer % 280) / 14];
        DmaCopy16(3, gKyogreWaterAnimFrame_Pals[index], OBJ_PLTT_SLOT(PAL_IX_15), PLTT_SLOT_SIZE);
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
                gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_IDLE;
                gCurrentPinballGame->bossNextAttackState = KYOGRE_ENTITY_STATE_SHOCKWAVE;
                gCurrentPinballGame->bossMovementPhase = 0;
                gCurrentPinballGame->bossRoarTimer = 60;
                DmaCopy16(3, &gKyogreWaterAnimFrame_Pals[5], OBJ_PLTT_SLOT(PAL_IX_15), PLTT_SLOT_SIZE);
            }

            if (gCurrentPinballGame->bossFramesetIndex == 32)
                gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;

            if (gCurrentPinballGame->bossFramesetIndex == 33)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_breach_surface);
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_TOP_POSITION;
            }
        }

        if (gCurrentPinballGame->ballRespawnTimer > 2)
            gCurrentPinballGame->ballRespawnTimer--;
        break;
    case KYOGRE_ENTITY_STATE_RETURN_TO_TOP:
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
                gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_IDLE;
                gCurrentPinballGame->bossNextAttackState = KYOGRE_ENTITY_STATE_SHOCKWAVE;
                gCurrentPinballGame->bossMovementPhase = 2;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 11)
            {
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_TOP_POSITION;
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_breach_surface);
            }
        }
        break;
    case KYOGRE_ENTITY_STATE_DIVE:
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
                gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_UNDERWATER;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 5)
            {
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_NONE;
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_dive);
            }
        }
        break;
    case KYOGRE_ENTITY_STATE_IDLE:
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
                    if (gCurrentPinballGame->bossNextAttackState == KYOGRE_ENTITY_STATE_DIVE)
                    {
                        if (gCurrentPinballGame->bonusModeHitCount >= gCurrentPinballGame->legendaryHitsRequired)
                        {
                            gCurrentPinballGame->bossFramesetIndex = 0;
                            gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_IDLE;
                            gCurrentPinballGame->bossMovementPhase = 0;
                            gCurrentPinballGame->bossNextAttackState = KYOGRE_ENTITY_STATE_SHOCKWAVE;
                        }
                        else
                        {
                            gCurrentPinballGame->bossFramesetIndex = 4;
                            gCurrentPinballGame->bossEntityState = gCurrentPinballGame->bossNextAttackState;
                        }
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 34;
                        gCurrentPinballGame->bossEntityState = gCurrentPinballGame->bossNextAttackState;
                        gCurrentPinballGame->shockwaveAlreadyHit = FALSE;
                        gCurrentPinballGame->bossMovementPhase = 0;
                    }
                }
            }
        }
        break;
    case KYOGRE_ENTITY_STATE_SPAWN_WHIRLPOOLS:
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
                //First pass resets to earlier in the animation, to spawn the second whirlpool, before actually moving
                if (gCurrentPinballGame->bossMovementPhase <= 0)
                {
                    gCurrentPinballGame->bossFramesetIndex = 45;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 0;
                    gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_IDLE;
                    gCurrentPinballGame->bossMovementPhase = 1;
                    gCurrentPinballGame->bossNextAttackState = KYOGRE_ENTITY_STATE_DIVE;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 52)
            {
                gCurrentPinballGame->vortexAnimTimer[gCurrentPinballGame->bossMovementPhase] = 0;
                gCurrentPinballGame->vortexEntityState[gCurrentPinballGame->bossMovementPhase] = KYOGRE_WHIRLPOOL_PHASE_SPAWN;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 50 || gCurrentPinballGame->bossFramesetIndex == 56 || gCurrentPinballGame->bossFramesetIndex == 62)
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_spawn_whirlpool);
        }
        break;
    case KYOGRE_ENTITY_STATE_SHOCKWAVE:
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
                gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_SPAWN_WHIRLPOOLS;
                gCurrentPinballGame->bossMovementPhase = 0;
            }

            if (!gCurrentPinballGame->shockwaveAlreadyHit && gCurrentPinballGame->bossFramesetIndex == 42)
            {
                gMain.spriteGroups[SG_KYOGRE_SHOCKWAVE].active = TRUE;
                gCurrentPinballGame->shockwaveAnimTimer = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_freeze_ring);
            }
        }

        // if boss is hit in the first several frames in this state, cancel the shockwave/freeze.
        if (gCurrentPinballGame->bossHitFlashTimer > 6)
            gCurrentPinballGame->shockwaveAlreadyHit = TRUE;
        break;
    case KYOGRE_ENTITY_STATE_SUFFICIENT_HITS:
        gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;

        if (gCurrentPinballGame->numCompletedBonusStages % 5 == 3)
        {
            // catch kyogre
            gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_CAPTURE;
            gCurrentPinballGame->bossFramesetIndex = 0;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT].active = TRUE;
            gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT_BORDERS].active = TRUE;
            gCurrentPinballGame->currentSpecies = SPECIES_KYOGRE;
            gCurrentPinballGame->bossAttackTimer = 0;
            gCurrentPinballGame->captureSequenceTimer = 0;
            gCurrentPinballGame->captureSequenceFrame = 0;
            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
        }
        else
        {
            // normal completion
            gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_PREPARE_LEAVING;
            gCurrentPinballGame->bossFramesetIndex = 79;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
            gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_DISABLED;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        if (gMain.spriteGroups[SG_KYOGRE_FREEZE_TRAP].active)
        {
            gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_DESPAWN;
            gCurrentPinballGame->freezeTrapPauseTimer = 1;
        }

        gCurrentPinballGame->bossFrameTimer = 0;
        break;
    case KYOGRE_ENTITY_STATE_PRESUMED_UNREACHABLE:
        break;
    case KYOGRE_ENTITY_STATE_PREPARE_LEAVING:
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
                gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_FINISHED;
                gCurrentPinballGame->boardState = LEGENDARY_BOARD_STATE_SUCCESS_BANNER;
                gCurrentPinballGame->stageTimer = 0;
            }

            if (gCurrentPinballGame->bossFramesetIndex == 97)
            {
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_NONE;
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_departs);
            }
        }
        break;
    case KYOGRE_ENTITY_STATE_CAPTURE:
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
    case KYOGRE_ENTITY_STATE_UNDERWATER:
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
                    if (gCurrentPinballGame->vortexEntityState[i] == KYOGRE_WHIRLPOOL_PHASE_FULL_CAUGHT_BALL)
                    {
                        gCurrentPinballGame->vortexAnimTimer[i] = 0;
                        gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_SHRINKING_CAUGHT_BALL;
                        gCurrentPinballGame->trapSpinRadius /= 2;
                    }

                    if (gCurrentPinballGame->vortexEntityState[i] == KYOGRE_WHIRLPOOL_PHASE_FULL)
                    {
                        gCurrentPinballGame->vortexAnimTimer[i] = 0;
                        gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_SHRUNK;
                    }
                }
            }
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex = 67;
            gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_LEAP;
            gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_EMERGING_FROM_WATER;
            MPlayStart(&gMPlayInfo_SE1, &se_kyogre_breach_surface);
            PlayRumble(8);
        }
        break;
    case KYOGRE_ENTITY_STATE_LEAP:
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
                    gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_UNDERWATER;
                    gCurrentPinballGame->bossMovementPhase++;
                }
                else
                {
                    gCurrentPinballGame->bossMovementPhase = 0;
                    gCurrentPinballGame->bossFramesetIndex = 8;
                    gCurrentPinballGame->bossEntityState = KYOGRE_ENTITY_STATE_RETURN_TO_TOP;
                    gCurrentPinballGame->bossPositionX = 0;
                    gCurrentPinballGame->bossPositionY = 0;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 70)
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_JUMPING;

            if (gCurrentPinballGame->bossFramesetIndex == 73)
                gCurrentPinballGame->boardEntityCollisionMode = KYOGRE_COLLISION_MODE_NONE;

            if (gCurrentPinballGame->bossFramesetIndex == 72)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_kyogre_dive);
                PlayRumble(8);
            }
        }
        break;
    case KYOGRE_ENTITY_STATE_FINISHED:
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

    group = &gMain.spriteGroups[SG_KYOGRE_ENTITY];
    if (group->active)
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
        if (gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_EMERGING_FROM_WATER)
        {
            gCurrentPinballGame->bossCollisionX = (gCurrentPinballGame->bossPositionX / 10) * 2 + 192;
            gCurrentPinballGame->bossCollisionY = (gCurrentPinballGame->bossPositionY / 10) * 2 + 134;
        }
        else if (gCurrentPinballGame->boardEntityCollisionMode == KYOGRE_COLLISION_MODE_JUMPING)
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
            palette = PAL_IX_11;
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
                palette = PAL_IX_14;
            else if (gCurrentPinballGame->legendaryFlashState == 3)
                palette = PAL_IX_11;
            else if (var2 == 20)
                palette = PAL_IX_4;
            else if (var2 == 21)
                palette = PAL_IX_3;
            else
                palette = PAL_IX_15;

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

    group = &gMain.spriteGroups[SG_KYOGRE_SURFACING_FX];
    if (group->active)
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
            gMain.spriteGroups[SG_KYOGRE_SURFACING_FX].active = FALSE;
        }
    }
    else
    {
        if (gCurrentPinballGame->bossEntityState == KYOGRE_ENTITY_STATE_UNDERWATER
            && gCurrentPinballGame->bossFrameTimer == 218)
        {
            group->active = TRUE;
        }
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
    int squaredDistance;
    struct Vector32 tempVector2;
    struct Vector32 tempVector;
    struct Vector32 tempVector3;

    index = 0;

    //Portrait display (during catch)
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

        for (i = 0; i < 6; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].paletteNum = PAL_IX_MON_PORTRAIT;
            gOamBuffer[oamSimple->oamId].priority = gCurrentPinballGame->creatureOamPriority;
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }

        group = &gMain.spriteGroups[SG_LEGENDARY_CATCH_PORTRAIT_BORDERS];
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

    //Freeze trap
    group = &gMain.spriteGroups[SG_KYOGRE_FREEZE_TRAP];
    if (group->active)
    {
        // General handling: Processes through a number of loops of animation frames.
        // While in one of the 'vulnerable' states, inside each loop, the timer is paused
        // for 90 ticks, which gets reduced to 0 ticks immediately if a new flipper press is detected.
        // The animation cycle still needs to finish, before it proceeds to the next loop/transitions phases.
        // Note: this will move from the 'setup' to the 'vulnerable' state with a paused trap timer, so the
        // new animation won't start until after the first 'button/loop end' in the vulnerable state.
        // State flow: Engulf -> unbroken, 1 cycle -> cracked, 5 cycles -> split, 5 cycles -> breaks.
        switch (gCurrentPinballGame->freezeTrapPhase)
        {
        case KYOGRE_FREEZE_PHASE_ENCLOSE_BALL:
            //Note: board starts with this mode, pre-ready for catching the ball, but doesn't actually
            //start running the animation/logic until the sprite group is marked active
            gCurrentPinballGame->freezeTrapAnimLoopStart = 0;
            gCurrentPinballGame->freezeTrapAnimEndFrame = 5;
            gCurrentPinballGame->freezeTrapNextPhase = KYOGRE_FREEZE_PHASE_CRACKING_HIT_SETUP;
            gCurrentPinballGame->freezeTrapLoopCount = 0;
            gCurrentPinballGame->freezeTrapPauseTimer = 0;
            if (gCurrentPinballGame->freezeTrapAnimFrame == 2)
            {
                int a; // force addition of 8 instead of offsetting the global constant
                DmaCopy16(3, gBall_Pals[a = gCurrentPinballGame->ballUpgradeType + 8], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);

            }
            break;
        case KYOGRE_FREEZE_PHASE_CRACKING_HIT_SETUP:
            gCurrentPinballGame->freezeTrapLoopCount = 4;
            gCurrentPinballGame->freezeTrapPauseTimer = 90;
            gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_CRACKED_VULNERABLE;
            break;
        case KYOGRE_FREEZE_PHASE_CRACKED_VULNERABLE:
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
            {
                gCurrentPinballGame->freezeTrapPauseTimer -= 90;
                if (gCurrentPinballGame->freezeTrapPauseTimer < 0)
                    gCurrentPinballGame->freezeTrapPauseTimer = 0;

                m4aSongNumStart(SE_KYOGRE_FREEZE_CRACK);
            }

            gCurrentPinballGame->freezeTrapAnimLoopStart = 5;
            gCurrentPinballGame->freezeTrapAnimEndFrame = 9;
            gCurrentPinballGame->freezeTrapNextPhase = KYOGRE_FREEZE_PHASE_SPLITTING_HIT_SETUP;
            break;
        case KYOGRE_FREEZE_PHASE_SPLITTING_HIT_SETUP:
            gCurrentPinballGame->freezeTrapLoopCount = 4;
            gCurrentPinballGame->freezeTrapPauseTimer = 90;
            gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_SPLIT_VULNERABLE;
            break;
        case KYOGRE_FREEZE_PHASE_SPLIT_VULNERABLE:
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
            {
                gCurrentPinballGame->freezeTrapPauseTimer -= 90;
                if (gCurrentPinballGame->freezeTrapPauseTimer < 0)
                    gCurrentPinballGame->freezeTrapPauseTimer = 0;

                m4aSongNumStart(SE_KYOGRE_FREEZE_CRACK);
            }

            gCurrentPinballGame->freezeTrapAnimLoopStart = 9;
            gCurrentPinballGame->freezeTrapAnimEndFrame = 13;
            gCurrentPinballGame->freezeTrapNextPhase = KYOGRE_FREEZE_PHASE_BREAKING_HIT_SETUP;
            break;
        case KYOGRE_FREEZE_PHASE_BREAKING_HIT_SETUP:
            gCurrentPinballGame->freezeTrapLoopCount = 0;
            gCurrentPinballGame->freezeTrapPauseTimer = 90;
            gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_LAST_HIT_VULNERABLE;
            break;
        case KYOGRE_FREEZE_PHASE_LAST_HIT_VULNERABLE:
            if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
            {
                gCurrentPinballGame->freezeTrapPauseTimer -= 90;
                if (gCurrentPinballGame->freezeTrapPauseTimer < 0)
                    gCurrentPinballGame->freezeTrapPauseTimer = 0;

                m4aSongNumStart(SE_KYOGRE_FREEZE_CRACK);
            }

            gCurrentPinballGame->freezeTrapAnimLoopStart = 13;
            gCurrentPinballGame->freezeTrapAnimEndFrame = 19;
            gCurrentPinballGame->freezeTrapNextPhase = KYOGRE_FREEZE_PHASE_DESPAWN;
            break;
        case KYOGRE_FREEZE_PHASE_DESPAWN:
            gMain.spriteGroups[SG_KYOGRE_FREEZE_TRAP].active = FALSE;
            break;
        }

        if (gCurrentPinballGame->freezeTrapPauseTimer > 0)
        {
            gCurrentPinballGame->freezeTrapPauseTimer--;
            if (gCurrentPinballGame->freezeTrapPauseTimer == 0)
                m4aSongNumStart(SE_KYOGRE_FREEZE_CRACK);
        }
        else
        {
            if (gKyogrefreezeTrapAnimFrameset[gCurrentPinballGame->freezeTrapAnimFrame][1] > gCurrentPinballGame->freezeTrapFrameTimer)
            {
                gCurrentPinballGame->freezeTrapFrameTimer++;
            }
            else
            {
                gCurrentPinballGame->freezeTrapFrameTimer = 0;
                gCurrentPinballGame->freezeTrapAnimFrame++;
                if (gCurrentPinballGame->freezeTrapAnimFrame == gCurrentPinballGame->freezeTrapAnimEndFrame)
                {
                    if (gCurrentPinballGame->freezeTrapLoopCount > 0)
                    {
                        gCurrentPinballGame->freezeTrapAnimFrame = gCurrentPinballGame->freezeTrapAnimLoopStart;
                        gCurrentPinballGame->freezeTrapLoopCount--;
                    }
                    else
                    {
                        gCurrentPinballGame->freezeTrapAnimFrame = gCurrentPinballGame->freezeTrapAnimEndFrame - 1;
                        gCurrentPinballGame->freezeTrapPhase = gCurrentPinballGame->freezeTrapNextPhase;
                    }

                    gCurrentPinballGame->freezeTrapPauseTimer = 90;
                }

                if (gCurrentPinballGame->freezeTrapAnimFrame == 1)
                    m4aSongNumStart(SE_KYOGRE_FREEZE_HITS_BALL);

                if (gCurrentPinballGame->freezeTrapAnimFrame == 15)
                {
                    DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);
                    m4aSongNumStart(SE_KYOGRE_FREEZE_ESCAPED);
                }
            }
        }

        if (gCurrentPinballGame->freezeTrapAnimFrame < 18)
        {
            gCurrentPinballGame->ballGrabbed = TRUE;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            gCurrentPinballGame->ball->spinSpeed = 0;
        }
        else
        {
            gCurrentPinballGame->ballGrabbed = FALSE;
        }

        group->baseX = gCurrentPinballGame->ball->screenPosition.x;
        group->baseY = gCurrentPinballGame->ball->screenPosition.y;
        if (group->baseY >= 200)
            group->baseY = 200;

        index = gKyogrefreezeTrapAnimFrameset[gCurrentPinballGame->freezeTrapAnimFrame][2];
        DmaCopy16(3, gKyogreWhirlpoolSpriteFrames[index], (void *)0x060124E0, 0x3C0);
        var0 = gKyogrefreezeTrapAnimFrameset[gCurrentPinballGame->freezeTrapAnimFrame][0];
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            dst = (u16*)&gOamBuffer[oamSimple->oamId];
            src = gKyogrefreezeTrapOamData[var0][i];
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;

            gOamBuffer[oamSimple->oamId].x += group->baseX;
            gOamBuffer[oamSimple->oamId].y += group->baseY;
        }
    }

    // Whirlpool processing
    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[SG_KYOGRE_WHIRLPOOL_0 + i];
        if ((gMain.modeChangeFlags & MODE_CHANGE_BONUS_BANNER) == 0)
        {
            switch (gCurrentPinballGame->vortexEntityState[i]) {
            case KYOGRE_WHIRLPOOL_PHASE_INIT:
                index = 0;
                gCurrentPinballGame->vortexScreenPosition[i].x = 0;
                gCurrentPinballGame->vortexScreenPosition[i].y = 0;
                break;
            case KYOGRE_WHIRLPOOL_PHASE_SPAWN:
                index = gCurrentPinballGame->vortexAnimTimer[i] / 9;
                if (gCurrentPinballGame->vortexAnimTimer[i] < 98)
                {
                    gCurrentPinballGame->vortexAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_FULL;
                    gCurrentPinballGame->vortexTargetWaypointIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->vortexOrbitCenter[i].x = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->vortexTargetWaypointIndex[i]].x;
                    gCurrentPinballGame->vortexOrbitCenter[i].y = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->vortexTargetWaypointIndex[i]].y;
                }

                gCurrentPinballGame->vortexScreenPosition[i].x = 0;
                gCurrentPinballGame->vortexScreenPosition[i].y = 0;
                break;
            case KYOGRE_WHIRLPOOL_PHASE_FULL:
                index = ((gCurrentPinballGame->vortexAnimTimer[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->vortexEntityState[0] < KYOGRE_WHIRLPOOL_PHASE_FULL_CAUGHT_BALL 
                    && gCurrentPinballGame->vortexEntityState[1] < KYOGRE_WHIRLPOOL_PHASE_FULL_CAUGHT_BALL)
                {
                    int xoff = 120;
                    int yoff = 144;
                    tempVector.x = (gCurrentPinballGame->ball->positionQ0.x - xoff) - (gCurrentPinballGame->vortexScreenPosition[i].x / 10);
                    tempVector.y = (gCurrentPinballGame->ball->positionQ0.y - yoff) - (gCurrentPinballGame->vortexScreenPosition[i].y / 10);
                    xx = tempVector.x * tempVector.x;
                    yy = tempVector.y * tempVector.y;
                    squaredDistance = xx + yy;
                    if (!gCurrentPinballGame->ballGrabbed
                        && !gCurrentPinballGame->ballRespawnState
                        && gCurrentPinballGame->bonusModeHitCount < gCurrentPinballGame->legendaryHitsRequired
                        && gCurrentPinballGame->bossHitFlashTimer == 0
                        && squaredDistance < 400)
                    {
                        m4aSongNumStart(SE_KYOGRE_WHIRLPOOL_GRABS_BALL);
                        PlayRumble(12);
                        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                        gCurrentPinballGame->vortexAnimTimer[i] = 0;
                        gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_FULL_CAUGHT_BALL;
                        gCurrentPinballGame->cameraLocked = TRUE;
                        tempVector2.x = gCurrentPinballGame->vortexScreenPosition[i].x / 10 + 120;
                        tempVector2.y = gCurrentPinballGame->vortexScreenPosition[i].y / 10 + 144;
                        tempVector.x = (tempVector2.x << 8) - gCurrentPinballGame->ball->positionQ8.x;
                        tempVector.y = (tempVector2.y << 8) - gCurrentPinballGame->ball->positionQ8.y;
                        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
                        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
                        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);
                    }
                }

                if (gCurrentPinballGame->vortexAnimTimer[i] < 900)
                {
                    gCurrentPinballGame->vortexAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_SHRUNK;
                }
                break;
            case KYOGRE_WHIRLPOOL_PHASE_FULL_CAUGHT_BALL:
                index = ((gCurrentPinballGame->vortexAnimTimer[i] % 40) / 8) + 6;
                if (gCurrentPinballGame->newButtonActions[PINBALL_INPUT_LEFT_FLIPPER]
                    || gCurrentPinballGame->newButtonActions[PINBALL_INPUT_RIGHT_FLIPPER])
                {
                    gCurrentPinballGame->vortexAnimTimer[i] += 8;
                }

                var4 = 29 - gCurrentPinballGame->vortexAnimTimer[i];
                if (var4 < 10)
                    var4 = 10;

                gCurrentPinballGame->trapAngleQ16 -= ((ANGLE_45 - (var4 * ANGLE_45) / 30) * 2) / 5;
                gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
                var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 30;
                tempVector2.x = gCurrentPinballGame->vortexScreenPosition[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->vortexScreenPosition[i].y / 10 + 144;

                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8)
                    + MulCos(var5, gCurrentPinballGame->trapAngleQ16);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8)
                    - MulSin(var5, gCurrentPinballGame->trapAngleQ16);

                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->vortexAnimTimer[i] < 480)
                {
                    gCurrentPinballGame->vortexAnimTimer[i]++;
                    if (gCurrentPinballGame->vortexAnimTimer[i] % 9 == 0)
                        PlayRumble(12);
                }
                else
                {
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_SHRINKING_CAUGHT_BALL;
                    gCurrentPinballGame->trapSpinRadius /= 2;
                }
                break;
            case KYOGRE_WHIRLPOOL_PHASE_SHRINKING_CAUGHT_BALL:
                index = 5 - gCurrentPinballGame->vortexAnimTimer[i] / 8;
                var4 = 47 - gCurrentPinballGame->vortexAnimTimer[i];
                gCurrentPinballGame->trapAngleQ16 -= ((ANGLE_45 - (var4 * 0x1000) / 47) * 2) / 5;
                gCurrentPinballGame->ball->spinAngle -= ANGLE_45;
                var5 = (gCurrentPinballGame->trapSpinRadius * var4) / 47;
                tempVector2.x = gCurrentPinballGame->vortexScreenPosition[i].x / 10 + 120;
                tempVector2.y = gCurrentPinballGame->vortexScreenPosition[i].y / 10 + 144;

                gCurrentPinballGame->ball->positionQ8.x = (tempVector2.x << 8)
                    + MulCos(var5, gCurrentPinballGame->trapAngleQ16);
                gCurrentPinballGame->ball->positionQ8.y = (tempVector2.y << 8)
                    - MulSin(var5, gCurrentPinballGame->trapAngleQ16);
                gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
                gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;

                if (gCurrentPinballGame->vortexAnimTimer[i] < 47)
                {
                    gCurrentPinballGame->vortexAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->ball->velocity.x = -150 + (gMain.systemFrameCount % 2) * 300;
                    gCurrentPinballGame->ball->velocity.y = 300;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_INIT;
                    gCurrentPinballGame->cameraLocked = FALSE;
                }
                break;
            case KYOGRE_WHIRLPOOL_PHASE_SHRUNK:
                index = 5 - gCurrentPinballGame->vortexAnimTimer[i] / 6;
                if (gCurrentPinballGame->vortexAnimTimer[i] < 36)
                {
                    gCurrentPinballGame->vortexAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->vortexAnimTimer[i] = 0;
                    gCurrentPinballGame->vortexEntityState[i] = KYOGRE_WHIRLPOOL_PHASE_INIT;
                }
                break;
            }

            if (gCurrentPinballGame->vortexEntityState[i] >= KYOGRE_WHIRLPOOL_PHASE_FULL
                && gCurrentPinballGame->vortexEntityState[i] < KYOGRE_WHIRLPOOL_PHASE_SHRINKING_CAUGHT_BALL)
            {
                tempVector.x = gCurrentPinballGame->vortexOrbitCenter[i].x - gCurrentPinballGame->vortexScreenPosition[i].x;
                tempVector.y = gCurrentPinballGame->vortexOrbitCenter[i].y - gCurrentPinballGame->vortexScreenPosition[i].y;
                xx = tempVector.x * tempVector.x;
                yy = tempVector.y * tempVector.y;
                squaredDistance = xx + yy;
                angle = ArcTan2(tempVector.x, -tempVector.y);
                tempVector3.x = MulCos(4, angle);
                tempVector3.y = MulSin(-4, angle);
                gCurrentPinballGame->vortexScreenPosition[i].x += tempVector3.x;
                gCurrentPinballGame->vortexScreenPosition[i].y += tempVector3.y;
                if (squaredDistance < 2500)
                {
                    gCurrentPinballGame->vortexTargetWaypointIndex[i] = i * 7 + ((Random() + gMain.systemFrameCount) % 7);
                    gCurrentPinballGame->vortexOrbitCenter[i].x = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->vortexTargetWaypointIndex[i]].x;
                    gCurrentPinballGame->vortexOrbitCenter[i].y = gKyogreWhirlpoolTargetPositions[gCurrentPinballGame->vortexTargetWaypointIndex[i]].y;
                }
            }
        }

        DmaCopy16(3, gKyogreWhirlpoolMinionSprites[index], (void *)(0x06011520 + i * 0x200), 0x200);
        if (group->active)
        {
            if (gCurrentPinballGame->vortexEntityState[i] > KYOGRE_WHIRLPOOL_PHASE_INIT)
            {
                group->baseX = gCurrentPinballGame->vortexScreenPosition[i].x / 10 - (gCurrentPinballGame->cameraXOffset - 104u);
                group->baseY = gCurrentPinballGame->vortexScreenPosition[i].y / 10 - (gCurrentPinballGame->cameraYOffset - 128u);
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

    //Shockwave processing
    group = &gMain.spriteGroups[SG_KYOGRE_SHOCKWAVE];
    if (group->active)
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
            group->active = FALSE;
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
            squaredDistance = xx + yy;

            //Check if shockwave close enough to the ball.
            if (!gCurrentPinballGame->ballRespawnState
                && squaredDistance < gShockwaveSplashDistanceThresholds[gCurrentPinballGame->shockwaveAnimTimer])
            {
                gCurrentPinballGame->freezeTrapPhase = KYOGRE_FREEZE_PHASE_ENCLOSE_BALL;
                gCurrentPinballGame->freezeTrapAnimFrame = 0;
                gCurrentPinballGame->freezeTrapFrameTimer = 0;
                if (!gMain.spriteGroups[SG_KYOGRE_FREEZE_TRAP].active)
                    PlayRumble(8);

                //Activate the 'ice trap' sprite + logic.
                gMain.spriteGroups[SG_KYOGRE_FREEZE_TRAP].active = TRUE;
            }
        }

        if (gMain.modeChangeFlags & MODE_CHANGE_EXPIRED_BONUS_BANNER)
            gMain.spriteGroups[SG_KYOGRE_SHOCKWAVE].active = FALSE;
    }
}

void HideKyogreSplashSprite(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    group = &gMain.spriteGroups[SG_KYOGRE_SHOCKWAVE];
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

void AnimateKyogreBackground(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;
    s16 index;

    if (gCurrentPinballGame->boardState == LEGENDARY_BOARD_STATE_INTRO
        && gCurrentPinballGame->stageTimer < 600)
    {
        index = gKyogreIntroPaletteCycleIndices[(gCurrentPinballGame->stageTimer % 240) / 24];
        DmaCopy16(3, gKyogreIntroIcePalette[index], OBJ_PLTT_SLOT(PAL_IX_10), 0x20);
        DmaCopy16(3, gKyogreIntroShorePalette[index], OBJ_PLTT_SLOT(PAL_IX_5), 0x20);
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

    DmaCopy16(3, &gBG0TilemapBuffer[0x800], BG_SCREEN_ADDR(0), BG_SCREEN_SIZE);
    index = gKyogreWaterPaletteSegmentCycle[(gMain.systemFrameCount % 96) / 24];
    DmaCopy16(3, gKyogreFadeInPaletteProgression[gCurrentPinballGame->bossLightFadeInCounter][index], BG_PLTT_SLOT(PAL_IX_3), PLTT_SLOT_SIZE);

    for (j = 0; j < 4; j++)
    {
        group = &gMain.spriteGroups[SG_KYOGRE_CRYSTAL_BASE + j];
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

    group = &gMain.spriteGroups[SG_KYOGRE_INTRO_CRYSTAL_GROUND];
    if (group->active)
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
            gMain.spriteGroups[SG_KYOGRE_INTRO_CRYSTAL_GROUND].active = FALSE;
    }
}
