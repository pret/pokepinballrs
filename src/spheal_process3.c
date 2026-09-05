#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/spheal_states.h"

#define SPHEAL_MODE_TIME TICKS_FOR_TIME(2,0)

struct SphealFlightPath
{
    struct Vector16 *pathWaypoints;
    s16 pathLength;
};
extern const struct SphealFlightPath gSphealFlightPathData[];

extern const s16 gSphealWhiscashAnimFrameset[][4];
extern struct SongHeader se_spheal_hit;
extern struct SongHeader se_spheal_net_swoosh;
extern struct SongHeader se_spheal_crowd_cheer;
extern struct SongHeader se_spheal_end_whistle;
extern struct SongHeader se_sealeo_hit_thud;
extern struct SongHeader se_sealeo_nose_bounce;

extern const s8 gSphealScoreDigitSpriteIndices[];
extern const u16 gSphealWaterBackgroundTilemap[];
extern const u8 gSphealNetGfx[][0x200];
extern const u8 gSphealNetFrontGfx[][0x180];
extern const u8 gSphealFlyingEnemyVariantSprites[][0x120];
extern const u8 gSphealMinionBodySprites[][0x800];
extern const u8 gSphealResultsScreenGfx[];
extern const u8 gWhiscash_Gfx[][0x480];
extern const u8 gPelipper_Gfx[][0x480];
extern const s16 gWaterTilePaletteCycle[];
extern const u16 gSealeoFramesetData[][2];
extern const u16 gSphealFramesetData[][3];
extern const u16 gSphealFlyingEnemyOamData[126][4][3];


void SphealBoardProcess_3A_42E48(void)
{
    s16 i;
    s16 frame;

    frame = gMain.systemFrameCount % 16;
    for (i = 0; i < frame; i++)
        Random();

    gMain.rngValue = gMain.systemFrameCount;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_ACTIVE;
    gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_INTRO;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + SPHEAL_MODE_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ballGrabbed = FALSE;
    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_LIVE_BALL;
    gCurrentPinballGame->ball->ballHidden = TRUE;
    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
    gCurrentPinballGame->ball->velocity.x = 0;
    gCurrentPinballGame->ball->velocity.y = 0;
    gCurrentPinballGame->ball->spinSpeed = 0;
    gCurrentPinballGame->returnToMainBoardFlag = FALSE;
    gCurrentPinballGame->resultsAnimTimer = 0;
    gCurrentPinballGame->scoreCountdownTimer = 0;
    gCurrentPinballGame->totalBonusScore = 0;
    gCurrentPinballGame->unk54A = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->unk590 = 0;
    gCurrentPinballGame->deliveryAnimFrameIndex = 0;
    gCurrentPinballGame->deliveryAnimTimer = 0;
    gCurrentPinballGame->unk594 = 0;
    gCurrentPinballGame->unk596 = 0;
    gCurrentPinballGame->ballDeliveryActive = TRUE;

    // Clear minion info, used for Sealeo. (3rd slot not used on this board)
    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->minionState[i] = SEALEO_ENTITY_STATE_INIT;
        gCurrentPinballGame->minionFramesetIx[i] = 0;
        gCurrentPinballGame->minionStateTimer[i] = 0;
    }

    // Set base info for the 'knockdown' process. spheal/ball being bounced, and into the hoop.
    for (i = 0; i < 3; i++)
    {
        gCurrentPinballGame->knockdownTargetIndex[i] = TARGET_SEALEO_LEFT;
        gCurrentPinballGame->knockdownBounceCount[i] = 0;
        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
        gCurrentPinballGame->knockdownBallReadinessTimer[i] = 0;
    }

    // Clear info for the hoop counts, sealeo stun timers, and spheal data
    for (i = 0; i < 2; i++)
    {
        gCurrentPinballGame->sphealKnockdownCount[i] = 0;
        gCurrentPinballGame->sphealKnockdownDisplayCount[i] = 0;
        gCurrentPinballGame->sealeoStunnedTimer[i] = 0;

        gCurrentPinballGame->sphealWasStunned[i] = FALSE;
        gCurrentPinballGame->sphealStunnedTimer[i] = 0;
        gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
        gCurrentPinballGame->sphealMovementDirection[i] = SPHEAL_MOVING_LEFT;
        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_INIT;
        gCurrentPinballGame->sphealNextFrameIx[i] = 0;
        gCurrentPinballGame->sphealSpawnPositionVariant[i] = SPHEAL_SPAWN_AT_LEFT_RAMP;
        gCurrentPinballGame->sphealFlightPathIx[i] = 0;
        gCurrentPinballGame->sphealFramesetIndex[i] = 0;
        gCurrentPinballGame->sphealOamXOffset[i] = 0;
        gCurrentPinballGame->sphealOamYOffset[i] = 0;
        gCurrentPinballGame->sphealAnimTimer[i] = 0;
        gCurrentPinballGame->sphealHitYPosition[i] = 0;
        gCurrentPinballGame->sphealEscapeTimer[i] = 0;
        gCurrentPinballGame->sphealEntityCollisionPos[i].x = 0;
        gCurrentPinballGame->sphealEntityCollisionPos[i].y = 0;
        gCurrentPinballGame->sphealVelocity[i].x = 0;
        gCurrentPinballGame->sphealVelocity[i].y = 0;
        gCurrentPinballGame->sphealPositionQ8[i].x = 0;
        gCurrentPinballGame->sphealPositionQ8[i].y = 0;
    }

    gCurrentPinballGame->flippersDisabled = FALSE;
    UpdateSphealEntityLogic();
    UpdateSealeoEntityLogic();
    UpdateSphealScoreAndDelivery();
    AnimateSphealBackground();

    for (i = 0; i < 0x800; i++)
        gBG0TilemapBuffer[0x400 + i] = 0x200;

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], BG_CHAR_SCREEN_ADDR(0,2), 2*BG_SCREEN_SIZE);

    gMain.blendControl = 0x1C42;
    gMain.blendAlpha = 0xC04;
    for (i = 0; i < 0x140; i++)
    {
        u16 var0 = i % 32 - 2;
        if (var0 < 28)
           gBG0TilemapBuffer[0x800 + i] = 0x9000;
    }

    gMain.bgOffsets[1].yOffset = 126;
    DmaCopy16(3, &gBG0TilemapBuffer[0x800], (void *)0x06001140, 0x280);
    DmaCopy16(3, gBall_Pals[gCurrentPinballGame->ballUpgradeType], OBJ_PLTT_SLOT(PAL_IX_BALL), PLTT_SLOT_SIZE);
    m4aSongNumStart(MUS_BONUS_FIELD_SPHEAL);
    DmaCopy16(3, gBonusStageObjPal, OBJ_PLTT_SLOT(PAL_IX_9), PLTT_SLOT_SIZE);
}

void SphealBoardProcess_3B_43228(void)
{
    switch (gCurrentPinballGame->boardState)
    {
    case SPHEAL_BOARD_STATE_INTRO:
        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
        if (gCurrentPinballGame->stageTimer < 340)
        {
            if (gCurrentPinballGame->stageTimer < 321)
                gCurrentPinballGame->cameraYAdjust = (gCurrentPinballGame->stageTimer / 5) + 0xFFC0;

            if (gCurrentPinballGame->stageTimer == 325)
                gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_RUNNING;

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_ACTIVE_PHASE;
            gCurrentPinballGame->stageTimer = 0;
        }
        break;
    case SPHEAL_BOARD_STATE_ACTIVE_PHASE:
        if (gCurrentPinballGame->eventTimer == 0)
        {
            gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;
            if (gCurrentPinballGame->stageTimer == 0)
            {
                m4aMPlayAllStop();
                MPlayStart(&gMPlayInfo_SE1, &se_spheal_end_whistle);
                gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_DISABLED;
                gCurrentPinballGame->ballRespawnTimer = 0;
            }

            if (gCurrentPinballGame->stageTimer < 60)
            {
                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_ENDING;
                gCurrentPinballGame->stageTimer = 0;
            }
        }
        break;
    case SPHEAL_BOARD_STATE_ENDING:
        if (gCurrentPinballGame->stageTimer == 0)
        {
            m4aMPlayAllStop();
            m4aSongNumStart(MUS_SUCCESS3);
        }

        if (gCurrentPinballGame->stageTimer < 20)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_SCORE_DISPLAY;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[SG_SPHEAL_END_SCORE_PANEL].active = TRUE;
            gMain.spriteGroups[SG_SPHEAL_END_SCORE_SPHEALS_SUNK].active = TRUE;
            gMain.spriteGroups[SG_SPHEAL_END_SCORE_BALLS_SUNK].active = TRUE;
            gMain.spriteGroups[SG_SPHEAL_END_SCORE_TOTAL].active = TRUE;
            DmaCopy16(3, gSphealResultsScreenGfx, (void *)0x06015800, 0x800);
            gCurrentPinballGame->bannerSlideYOffset = -126;
            gCurrentPinballGame->cameraLocked = TRUE;
        }
        break;
    case SPHEAL_BOARD_STATE_SCORE_DISPLAY:
        UpdateSphealResultsScreen();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180 && gCurrentPinballGame->totalBonusScore != 0)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_SEAL_RESULTS;
            gCurrentPinballGame->scoreAddedInFrame = gCurrentPinballGame->totalBonusScore;
        }

        if (gCurrentPinballGame->stageTimer > 189 && JOY_NEW(A_BUTTON))
            gCurrentPinballGame->stageTimer = 540;

        if (gCurrentPinballGame->stageTimer < 540)
        {
            if (gCurrentPinballGame->stageTimer == 4)
                m4aSongNumStart(SE_BONUS_PANEL_SLIDE);

            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_SCORE_DISPLAY_CLEANUP;
        }

        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    case SPHEAL_BOARD_STATE_SCORE_DISPLAY_CLEANUP:
        UpdateSphealResultsScreen();
        if (gCurrentPinballGame->stageTimer < 30)
        {
            gCurrentPinballGame->stageTimer++;
            if (gCurrentPinballGame->stageTimer == 2)
                m4aSongNumStart(SE_BONUS_PANEL_SLIDE);
        }
        else
        {
            gCurrentPinballGame->stageTimer = 0;
            gCurrentPinballGame->boardState = SPHEAL_BOARD_STATE_PREPARE_RETURN;
        }
        break;
    case SPHEAL_BOARD_STATE_PREPARE_RETURN:
        UpdateSphealResultsScreen();
        gCurrentPinballGame->returnToMainBoardFlag = TRUE;
        gCurrentPinballGame->cameraLocked = TRUE;
        break;
    }

    UpdateSphealEntityLogic();
    UpdateSealeoEntityLogic();
    UpdateSphealScoreAndDelivery();
    AnimateSphealBackground();
    if (gCurrentPinballGame->returnToMainBoardFlag)
    {
        gCurrentPinballGame->cameraLocked = TRUE;
        FadeToMainBoard();
    }

    BonusStage_HandleModeChangeFlags();
}

void UpdateSealeoEntityLogic(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 var0;

    if (gCurrentPinballGame->boardState < SPHEAL_BOARD_STATE_ENDING
        && gMain.modeChangeFlags == MODE_CHANGE_NONE)
        UpdateSealeoKnockdownPhysics();

    if (gCurrentPinballGame->boardState < SPHEAL_BOARD_STATE_ENDING
        && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            if (gCurrentPinballGame->sealeoStunnedTimer[i] == 23)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_sealeo_hit_thud);
                gCurrentPinballGame->scoreAddedInFrame = SCORE_SEALEO_HIT;
                PlayRumble(8);
            }

            switch (gCurrentPinballGame->minionState[i])
            {
            case SEALEO_ENTITY_STATE_INIT:
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i] = 4;
                gCurrentPinballGame->minionState[i] = SEALEO_ENTITY_STATE_READY;
                break;
            case SEALEO_ENTITY_STATE_READY:
                if (gCurrentPinballGame->sealeoStunnedTimer[i] > 0)
                {
                    gCurrentPinballGame->sealeoStunnedTimer[i]--;
                }
                else
                {
                    if (gSealeoFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] == 6)
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                    }
                }
                break;
            case SEALEO_ENTITY_STATE_ANTICIPATE_BOUNCE:
                if (gCurrentPinballGame->sealeoStunnedTimer[i] > 0)
                {
                    gCurrentPinballGame->sealeoStunnedTimer[i]--;
                }
                else
                {
                    if (gCurrentPinballGame->minionStateTimer[i] != 0)
                    {
                        gCurrentPinballGame->minionStateTimer[i]--;
                        gCurrentPinballGame->minionFramesetIx[i] = 8;
                    }
                    else
                    {
                        gCurrentPinballGame->minionFramesetIx[i] = 7;
                    }
                }
                break;
            case SEALEO_ENTITY_STATE_DONE_BOUNCING:
                if (gCurrentPinballGame->sealeoStunnedTimer[i] > 0)
                {
                    gCurrentPinballGame->sealeoStunnedTimer[i]--;
                }
                else
                {
                    if (gSealeoFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                    {
                        gCurrentPinballGame->minionStateTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->minionStateTimer[i] = 0;
                        gCurrentPinballGame->minionFramesetIx[i]++;
                        if (gCurrentPinballGame->minionFramesetIx[i] > 14)
                        {
                            gCurrentPinballGame->minionFramesetIx[i] = 4;
                            gCurrentPinballGame->minionState[i] = SEALEO_ENTITY_STATE_READY;
                        }
                    }
                }
                break;
            }
        }
    }

    group = &gMain.spriteGroups[SG_SPHEAL_RIGHT_SEALEO_ENTITY];
    if (group->active)
    {
        group->baseX = 100 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->sealeoStunnedTimer[0] > 0)
            var0 = 0;
        else
            var0 = gSealeoFramesetData[gCurrentPinballGame->minionFramesetIx[0]][0];

        DmaCopy16(3, gSphealMinionBodySprites[var0], (void *)0x060114A0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_SPHEAL_LEFT_SEALEO_ENTITY];
    if (group->active)
    {
        group->baseX = 140 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->sealeoStunnedTimer[1] > 0)
            var0 = 0;
        else
            var0 = gSealeoFramesetData[gCurrentPinballGame->minionFramesetIx[1]][0];

        DmaCopy16(3, gSphealMinionBodySprites[var0], (void *)0x06010CA0, 0x600);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }
}

void UpdateSphealEntityLogic(void)
{
    s16 i;
    s16 j;
    s16 var1;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 sphealFrameIx;
    s16 var2;
    u16 *dst;
    const u16 *src;
    int var3;
    s16 var4;
    const struct SphealFlightPath *var5;

    if (gCurrentPinballGame->boardState == SPHEAL_BOARD_STATE_ACTIVE_PHASE && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            switch (gCurrentPinballGame->sphealEntityState[i])
            {
            case SPHEAL_ENTITY_STATE_INIT:
                gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_CHOOSE_SPAWN;
                gCurrentPinballGame->sphealFramesetIndex[i] = 0;
                gCurrentPinballGame->sphealAnimTimer[i] = 0;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                gCurrentPinballGame->sphealSpawnPositionVariant[i] = SPHEAL_SPAWN_UNDEFINED_POSITION;
                break;
            case SPHEAL_ENTITY_STATE_CHOOSE_SPAWN:
                if (gCurrentPinballGame->sphealAnimTimer[i] < i * 30 + 120)
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    u16 var0 = gMain.systemFrameCount + Random();
                    gCurrentPinballGame->sphealSpawnPositionVariant[i] = var0 % 6;

                    // Don't allow both to be spawned at the same position. Bump if it rolls the same as other spheal.
                    if (gCurrentPinballGame->sphealSpawnPositionVariant[0] == gCurrentPinballGame->sphealSpawnPositionVariant[1])
                        gCurrentPinballGame->sphealSpawnPositionVariant[i] = (gCurrentPinballGame->sphealSpawnPositionVariant[i] + 2) % 6;

                    if (gCurrentPinballGame->sphealSpawnPositionVariant[i] <= SPHEAL_SPAWN_AT_RIGHT_RAMP)
                    {
                        if (gCurrentPinballGame->sphealSpawnPositionVariant[i] == SPHEAL_SPAWN_AT_LEFT_RAMP)
                        {
                            gCurrentPinballGame->sphealPositionQ8[i].x = 0x4900;
                            gCurrentPinballGame->sphealPositionQ8[i].y = 0xAB00;
                            gCurrentPinballGame->sphealMovementDirection[i] = SPHEAL_MOVING_LEFT;
                        }
                        else
                        {
                            gCurrentPinballGame->sphealPositionQ8[i].x = 0xA700;
                            gCurrentPinballGame->sphealPositionQ8[i].y = 0xAC00;
                            gCurrentPinballGame->sphealMovementDirection[i] = SPHEAL_MOVING_RIGHT;
                        }

                        gCurrentPinballGame->sphealFramesetIndex[i] = 9;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_SURFACE_AT_RAMP;
                    }
                    else
                    {
                        //Choose random direction & x position of the spawning Spheal.
                        gCurrentPinballGame->sphealMovementDirection[i] = (gMain.systemFrameCount + Random()) % 2;
                        if (gCurrentPinballGame->sphealMovementDirection[i] != SPHEAL_MOVING_LEFT)
                        {
                            //Lowest row doesn't have the full width to swim, constrain it to the smaller space.
                            if (gCurrentPinballGame->sphealSpawnPositionVariant[i] == SPHEAL_SPAWN_AT_LOWEST_ROW)
                                gCurrentPinballGame->sphealPositionQ8[i].x = (((Random() % 101) / 5) + 80) << 8;
                            else
                                gCurrentPinballGame->sphealPositionQ8[i].x = (((Random() % 101) / 2) + 50) << 8;
                        }
                        else
                        {
                            if (gCurrentPinballGame->sphealSpawnPositionVariant[i] == SPHEAL_SPAWN_AT_LOWEST_ROW)
                                gCurrentPinballGame->sphealPositionQ8[i].x = (((Random() % 101) / 5) + 140) << 8;
                            else
                                gCurrentPinballGame->sphealPositionQ8[i].x = (((Random() % 101) / 2) + 140) << 8;
                        }

                        // Calculate Y position for the top, center high/low, lowest row.
                        gCurrentPinballGame->sphealPositionQ8[i].y = 0xAF00 + ((gCurrentPinballGame->sphealSpawnPositionVariant[i] - 2) * 0xA00);

                        gCurrentPinballGame->sphealFramesetIndex[i] = 0;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_SURFACE_IN_WATER;
                    }

                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                }

                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                break;
            case SPHEAL_ENTITY_STATE_SURFACE_IN_WATER:
                if (gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][1] > gCurrentPinballGame->sphealAnimTimer[i])
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i]++;
                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 3)
                    {
                        gCurrentPinballGame->sphealFramesetIndex[i] = 3;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_SWIMMING;
                    }

                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 1)
                        m4aSongNumStart(SE_SPHEAL_SURFACING);
                }

                gCurrentPinballGame->sphealEscapeTimer[i] = 0;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_SWIMMING;
                break;
            case SPHEAL_ENTITY_STATE_SWIMMING:
                if (gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][1] > gCurrentPinballGame->sphealAnimTimer[i])
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i]++;
                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 5)
                        gCurrentPinballGame->sphealFramesetIndex[i] = 3;
                }

                if (gCurrentPinballGame->sphealEscapeTimer[i] < 400)
                {
                    gCurrentPinballGame->sphealEscapeTimer[i]++;
                    if (gCurrentPinballGame->sphealMovementDirection[i] != SPHEAL_MOVING_LEFT)
                        gCurrentPinballGame->sphealPositionQ8[i].x += 35;
                    else
                        gCurrentPinballGame->sphealPositionQ8[i].x -= 35;
                }
                else
                {
                    gCurrentPinballGame->sphealFramesetIndex[i] = 6;
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_DIVING;
                }

                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_SWIMMING;
                break;
            case SPHEAL_ENTITY_STATE_HIT:
                // Note: A hit while 'walking down' won't come here.
                MPlayStart(&gMPlayInfo_SE1, &se_spheal_hit);
                if (gCurrentPinballGame->sphealEntityCollisionType[i] == SPHEAL_COLLISION_TYPE_SWIMMING)
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i] = 5;
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_HIT_WHILE_SWIMMING;
                }
                else
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].y + (gCurrentPinballGame->sphealOamYOffset[i] << 8) < gCurrentPinballGame->ball->positionQ8.y)
                    {
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_HIT_UP_RAMP;
                    }
                    else
                    {
                        gCurrentPinballGame->sphealAnimTimer[i] = 0xAC - (gCurrentPinballGame->sphealAnimTimer[i] * 12) / 0xA0;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_CLIMBING_RAMP;
                    }
                }

                PlayRumble(7);
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                gCurrentPinballGame->scoreAddedInFrame = SCORE_SPHEAL_HIT;
                break;
            case SPHEAL_ENTITY_STATE_HIT_WHILE_SWIMMING:
                if (gCurrentPinballGame->sphealAnimTimer[i] < 10)
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                    gCurrentPinballGame->sphealFramesetIndex[i] = 5;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_DIVING;
                }
                break;
            case SPHEAL_ENTITY_STATE_DIVING:
                if (gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][1] > gCurrentPinballGame->sphealAnimTimer[i])
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i]++;
                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 9)
                    {
                        gCurrentPinballGame->sphealFramesetIndex[i] = 0;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_INIT;
                    }

                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 7)
                        m4aSongNumStart(SE_SPHEAL_SUBMERGING);
                }

                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;

                break;
            case SPHEAL_ENTITY_STATE_SURFACE_AT_RAMP:
                if (gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][1] > gCurrentPinballGame->sphealAnimTimer[i])
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i]++;
                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 14)
                    {
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_CLIMBING_RAMP;
                        gCurrentPinballGame->sphealPositionQ8[i].x += gCurrentPinballGame->sphealOamXOffset[i] << 8;
                        gCurrentPinballGame->sphealPositionQ8[i].y += gCurrentPinballGame->sphealOamYOffset[i] << 8;
                    }

                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 10)
                        m4aSongNumStart(SE_SPHEAL_SURFACE_AT_RAMP);

                }
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_ON_RAMP;

                break;
            case SPHEAL_ENTITY_STATE_CLIMBING_RAMP:
                if (gCurrentPinballGame->sphealAnimTimer[i] < 184)
                {
                    if (gCurrentPinballGame->sphealAnimTimer[i] < 160)
                    {
                        // Climbing up
                        if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                            gCurrentPinballGame->sphealPositionQ8[i].x -= 0x10;
                        else
                            gCurrentPinballGame->sphealPositionQ8[i].x += 0x10;

                        if (gCurrentPinballGame->sphealAnimTimer[i] & 1)
                            gCurrentPinballGame->sphealPositionQ8[i].y -= 0x10;
                        else
                            gCurrentPinballGame->sphealPositionQ8[i].y -= 0x20;

                        if (gCurrentPinballGame->sphealAnimTimer[i] % 19 < 10)
                            gCurrentPinballGame->sphealFramesetIndex[i] = 14;
                        else
                            gCurrentPinballGame->sphealFramesetIndex[i] = 15;
                    }
                    else
                    {
                        // Sliding down
                        if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                            gCurrentPinballGame->sphealPositionQ8[i].x += 0x140;
                        else
                            gCurrentPinballGame->sphealPositionQ8[i].x -= 0x140;

                        if (gCurrentPinballGame->sphealAnimTimer[i] & 1)
                            gCurrentPinballGame->sphealPositionQ8[i].y += 0x140;
                        else
                            gCurrentPinballGame->sphealPositionQ8[i].y += 0x1E0;

                        gCurrentPinballGame->sphealFramesetIndex[i] = 15;
                    }

                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    // slid to end of ramp
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_SLIDE_PLUNGE;
                    gCurrentPinballGame->sphealFramesetIndex[i] = 16;
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;

                    if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                        gCurrentPinballGame->sphealPositionQ8[i].x += 0xF0;
                    else
                        gCurrentPinballGame->sphealPositionQ8[i].x -= 0xF0;
                }
                break;
            case SPHEAL_ENTITY_STATE_SLIDE_PLUNGE:
                if (gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][1] > gCurrentPinballGame->sphealAnimTimer[i])
                {
                    gCurrentPinballGame->sphealAnimTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealFramesetIndex[i]++;
                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 20)
                    {
                        gCurrentPinballGame->sphealFramesetIndex[i] = 0;
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_INIT;
                    }

                    if (gCurrentPinballGame->sphealFramesetIndex[i] == 17)
                        m4aSongNumStart(SE_SPHEAL_SUBMERGING);
                }
                break;
            case SPHEAL_ENTITY_STATE_HIT_UP_RAMP: {
                s16 len;
                if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                    var1 = 3;
                else
                    var1 = 0;

                // Use height on ramp where the spheal was hit to determine the starting flight path ix.
                len = gSphealFlightPathData[var1].pathLength;
                for (j = 0; j < len; j++)
                {
                    if (gSphealFlightPathData[var1].pathWaypoints[j].y <= gCurrentPinballGame->sphealHitYPosition[i])
                        break;
                }

                gCurrentPinballGame->sphealFlightPathIx[i] = j;
                gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_FOLLOW_RAMP;
                gCurrentPinballGame->sphealFramesetIndex[i] = 29;
                gCurrentPinballGame->sphealAnimTimer[i] = 0;

                gCurrentPinballGame->sphealPositionQ8[i].x = gSphealFlightPathData[var1].pathWaypoints[gCurrentPinballGame->sphealFlightPathIx[i]].x << 8;
                gCurrentPinballGame->sphealPositionQ8[i].y = gSphealFlightPathData[var1].pathWaypoints[gCurrentPinballGame->sphealFlightPathIx[i]].y << 8;

                gCurrentPinballGame->sphealFlightPathIx[i]++;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                break;
            }
            case SPHEAL_ENTITY_STATE_FOLLOW_RAMP:
                if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                    var1 = 3;
                else
                    var1 = 0;

                var4 = gCurrentPinballGame->sphealFlightPathIx[i];
                var5 = gSphealFlightPathData;
                if (var4 < var5[var1].pathLength)
                {
                    gCurrentPinballGame->sphealPositionQ8[i].x = var5[var1].pathWaypoints[gCurrentPinballGame->sphealFlightPathIx[i]].x << 8;
                    gCurrentPinballGame->sphealPositionQ8[i].y = var5[var1].pathWaypoints[gCurrentPinballGame->sphealFlightPathIx[i]].y << 8;

                    gCurrentPinballGame->sphealFlightPathIx[i]++;
                    if (gCurrentPinballGame->sphealFlightPathIx[i] == var5[var1].pathLength)
                    {
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_AWAIT_BOUNCE;
                        gCurrentPinballGame->knockdownTargetIndex[i] = gCurrentPinballGame->sphealMovementDirection[i];
                        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_PREPARE_BOUNCE;
                        if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                            gCurrentPinballGame->sphealVelocity[i].x = 0x140;
                        else
                            gCurrentPinballGame->sphealVelocity[i].x = -0x140;

                        gCurrentPinballGame->sphealVelocity[i].y = 0x1D0;
                    }
                }

                gCurrentPinballGame->sphealFramesetIndex[i] = ((gCurrentPinballGame->sphealAnimTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->sphealAnimTimer[i]++;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                break;
            case SPHEAL_ENTITY_STATE_AWAIT_BOUNCE:
                gCurrentPinballGame->sphealPositionQ8[i].x += gCurrentPinballGame->sphealVelocity[i].x;
                gCurrentPinballGame->sphealPositionQ8[i].y += gCurrentPinballGame->sphealVelocity[i].y;
                gCurrentPinballGame->sphealFramesetIndex[i] = ((gCurrentPinballGame->sphealAnimTimer[i] % 32) / 4) + 30;
                gCurrentPinballGame->sphealAnimTimer[i]++;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                break;
            case SPHEAL_ENTITY_STATE_BOUNCING:
                gCurrentPinballGame->sphealPositionQ8[i].x += gCurrentPinballGame->sphealVelocity[i].x;
                gCurrentPinballGame->sphealPositionQ8[i].y += gCurrentPinballGame->sphealVelocity[i].y;
                gCurrentPinballGame->sphealFramesetIndex[i] = ((gCurrentPinballGame->sphealAnimTimer[i] % 32) / 8) + 26;
                gCurrentPinballGame->sphealAnimTimer[i]++;
                gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                break;
            case SPHEAL_ENTITY_STATE_LAND_AND_WALK_TO_WATER:
                gCurrentPinballGame->sphealSpawnPositionVariant[i] = SPHEAL_SPAWN_UNDEFINED_POSITION;
                if (gCurrentPinballGame->sphealStunnedTimer[i] > 0)
                {
                    gCurrentPinballGame->sphealStunnedTimer[i]--;
                    gCurrentPinballGame->sphealFramesetIndex[i] = 38;
                    gCurrentPinballGame->sphealWasStunned[i] = TRUE;
                }
                else
                {
                    if (gCurrentPinballGame->sphealAnimTimer[i] < 334)
                    {
                        if (gCurrentPinballGame->sphealAnimTimer[i] < 16)
                        {
                            gCurrentPinballGame->sphealFramesetIndex[i] = 21;
                            if (gCurrentPinballGame->sphealAnimTimer[i] == 1)
                                m4aSongNumStart(SE_SPHEAL_LAND_UNDER_NET);

                            gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_WALK_DOWN;
                        }
                        else if (gCurrentPinballGame->sphealAnimTimer[i] < 316)
                        {
                            if (gCurrentPinballGame->sphealWasStunned[i] == FALSE)
                            {
                                gCurrentPinballGame->sphealPositionQ8[i].y += 0x40;
                                if (gCurrentPinballGame->sphealAnimTimer[i] % 19 < 10)
                                    gCurrentPinballGame->sphealFramesetIndex[i] = 22;
                                else
                                    gCurrentPinballGame->sphealFramesetIndex[i] = 23;
                            }
                            else
                            {
                                gCurrentPinballGame->sphealPositionQ8[i].y += 0x80;
                                if (gCurrentPinballGame->sphealAnimTimer[i] % 10 < 5)
                                    gCurrentPinballGame->sphealFramesetIndex[i] = 22;
                                else
                                    gCurrentPinballGame->sphealFramesetIndex[i] = 23;
                            }

                            if (gCurrentPinballGame->sphealPositionQ8[i].y > 0xAC00)
                                gCurrentPinballGame->sphealAnimTimer[i] = 316;

                            gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_WALK_DOWN;
                        }
                        else
                        {
                            s16 var20;
                            gCurrentPinballGame->sphealPositionQ8[i].y += 0x30;
                            var20 = gCurrentPinballGame->sphealAnimTimer[i] - 316;
                            if (var20 < 10)
                                gCurrentPinballGame->sphealFramesetIndex[i] = 24;
                            else
                                gCurrentPinballGame->sphealFramesetIndex[i] = 25;

                            if (var20 == 1)
                                m4aSongNumStart(SE_SPHEAL_SUBMERGE_AFTER_SCORING);

                            gCurrentPinballGame->sphealEntityCollisionType[i] = SPHEAL_COLLISION_TYPE_INACTIVE;
                        }

                        gCurrentPinballGame->sphealAnimTimer[i]++;
                    }
                    else
                    {
                        gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_INIT;
                        gCurrentPinballGame->sphealFramesetIndex[i] = 0;
                        gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    }
                }
                break;
            }
        }
    }

    // Draw Spheals; set collision position.
    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[SG_SPHEAL_ENTITY_BASE + i];
        if (group->active)
        {
            sphealFrameIx = gCurrentPinballGame->sphealNextFrameIx[i];
            gCurrentPinballGame->sphealNextFrameIx[i] =
                gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][2]
                + (1 - gCurrentPinballGame->sphealMovementDirection[i]) * 30;
            var2 = gSphealFramesetData[gCurrentPinballGame->sphealFramesetIndex[i]][0];

            group->baseX = (gCurrentPinballGame->sphealPositionQ8[i].x / 256) - (gCurrentPinballGame->cameraXOffset + 12);
            group->baseY = (gCurrentPinballGame->sphealPositionQ8[i].y / 256) - (gCurrentPinballGame->cameraYOffset + 14);

            DmaCopy16(3, gSphealFlyingEnemyVariantSprites[sphealFrameIx], (void *)0x06011CA0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                dst = (u16*)&gOamBuffer[oamSimple->oamId];
                src = gSphealFlyingEnemyOamData[var2][j];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                if (gCurrentPinballGame->sphealMovementDirection[i] == SPHEAL_MOVING_LEFT)
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->sphealOamXOffset[i] = -gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->sphealOamYOffset[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX + gCurrentPinballGame->sphealOamXOffset[i] * 2;
                }
                else
                {
                    if (j == 0)
                    {
                        gCurrentPinballGame->sphealOamXOffset[i] = gOamBuffer[oamSimple->oamId].x;
                        gCurrentPinballGame->sphealOamYOffset[i] = gOamBuffer[oamSimple->oamId].y;
                    }

                    gOamBuffer[oamSimple->oamId].x += group->baseX;
                }

                gOamBuffer[oamSimple->oamId].y += group->baseY;
                gOamBuffer[oamSimple->oamId].tileNum += i * 9;
            }

            var3 = 0x10;
            gCurrentPinballGame->sphealEntityCollisionPos[i].x = ((gCurrentPinballGame->sphealPositionQ8[i].x / 256) + (gCurrentPinballGame->sphealOamXOffset[i] - var3)) * 2;

            var3 = 0x12;
            gCurrentPinballGame->sphealEntityCollisionPos[i].y = ((gCurrentPinballGame->sphealPositionQ8[i].y / 256) + (gCurrentPinballGame->sphealOamYOffset[i] - var3)) * 2;

            gCurrentPinballGame->sphealHitYPosition[i] = gCurrentPinballGame->sphealPositionQ8[i].y / 256 + gCurrentPinballGame->sphealOamYOffset[i];

            group = &gMain.spriteGroups[SG_SPHEAL_ENTITY_REFLECTION_BASE + i];

            //Note: left/right are separated by 30
            if (sphealFrameIx == 12 || sphealFrameIx == 42)
            {
                if (gCurrentPinballGame->sphealFramesetIndex[i] == 11)
                    sphealFrameIx = 8;
                else
                    sphealFrameIx = 9;
            }
            else
            {
                sphealFrameIx = 0;
            }

            group->baseX = (gCurrentPinballGame->sphealPositionQ8[i].x / 256) - (gCurrentPinballGame->cameraXOffset + 12);
            group->baseY = (gCurrentPinballGame->sphealPositionQ8[i].y / 256) - (gCurrentPinballGame->cameraYOffset + 14);

            DmaCopy16(3, gSphealFlyingEnemyVariantSprites[sphealFrameIx], (void *)0x06011EE0 + i * 0x120, 0x120);
            for (j = 0; j < 4; j++)
            {
                oamSimple = &group->oam[j];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            }
        }
    }
}

void UpdateSphealScoreAndDelivery(void)
{
    s16 i;
    s16 var0;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;

    var0 = 0;
    group = &gMain.spriteGroups[SG_SPHEAL_NET];
    if (group->active)
    {
        group->baseX = 104 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 86 - gCurrentPinballGame->cameraYOffset;
        if (gCurrentPinballGame->scoreCountdownTimer < 22)
            var0 = gSphealScoreDigitSpriteIndices[gCurrentPinballGame->scoreCountdownTimer];

        DmaCopy16(3, gSphealNetGfx[var0], (void *)0x06010920, 0x200);
        oamSimple = &group->oam[0];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[SG_SPHEAL_NET_FRONT];
    if (group->active)
    {
        group->baseX = 104 - gCurrentPinballGame->cameraXOffset;
        group->baseY = 94 - gCurrentPinballGame->cameraYOffset;
        DmaCopy16(3, gSphealNetFrontGfx[var0], (void *)0x06010B20, 0x180);
        for (i = 0; i < 2; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->boardState == SPHEAL_BOARD_STATE_ACTIVE_PHASE)
        gMain.spriteGroups[SG_SPHEAL_NET_FRONT].active = TRUE;

    if (gCurrentPinballGame->boardState < SPHEAL_BOARD_STATE_ENDING && gMain.modeChangeFlags == MODE_CHANGE_NONE && gCurrentPinballGame->scoreCountdownTimer)
    {
        if (gCurrentPinballGame->scoreCountdownTimer == 21)
            MPlayStart(&gMPlayInfo_SE1, &se_spheal_net_swoosh);

        gCurrentPinballGame->scoreCountdownTimer--;
        if (gCurrentPinballGame->scoreCountdownTimer == 0)
            MPlayStart(&gMPlayInfo_SE1, &se_spheal_crowd_cheer);
    }

    if (gCurrentPinballGame->ballDeliveryActive)
    {
        if (gMain.tempField == FIELD_RUBY)
            SphealBoard_WhiscashDeliversBall();
        else
            SphealBoard_PelipperDeliversBall();
    }
}

void SphealBoard_WhiscashDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    const u16 *offsets;
    s16 var0;

    group = &gMain.spriteGroups[SG_SPHEAL_WHISCASH_ENTITY];
    if (group->active)
    {
        offsets = gSphealWhiscashAnimFrameset[gCurrentPinballGame->deliveryAnimFrameIndex];
        group->baseX = 134 + offsets[2] - gCurrentPinballGame->cameraXOffset;
        group->baseY = 154 + offsets[3] - gCurrentPinballGame->cameraYOffset;
        var0 = offsets[0];
        DmaCopy16(3, gWhiscash_Gfx[var0], (void *)0x06012120, 0x460);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gSphealWhiscashAnimFrameset[gCurrentPinballGame->deliveryAnimFrameIndex][1] > gCurrentPinballGame->deliveryAnimTimer)
    {
        gCurrentPinballGame->deliveryAnimTimer++;
    }
    else
    {
        gCurrentPinballGame->deliveryAnimTimer = 0;
        gCurrentPinballGame->deliveryAnimFrameIndex++;
        if (gCurrentPinballGame->deliveryAnimFrameIndex == 1)
            gMain.spriteGroups[SG_SPHEAL_WHISCASH_ENTITY].active = TRUE;

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 19)
        {
            gCurrentPinballGame->deliveryAnimFrameIndex = 18;
            gMain.spriteGroups[SG_SPHEAL_WHISCASH_ENTITY].active = FALSE;
            gCurrentPinballGame->ballDeliveryActive = FALSE;
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 9)
        {
            gCurrentPinballGame->ball->spinAngle -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8D00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC800;
            gCurrentPinballGame->ball->velocity.x = -0x60;
            gCurrentPinballGame->ball->velocity.y = 0x54;
            gCurrentPinballGame->ball->oamPriority = 3;
            PlayRumble(7);
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 2)
            m4aSongNumStart(SE_WHISCASH_EMERGE_SPLASH);

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 15)
            m4aSongNumStart(SE_WHISCASH_LEAVE_BURBLE);

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 8)
        {
            m4aSongNumStart(SE_WHISCASH_SPIT_BALL);
            gCurrentPinballGame->ball->ballHidden = FALSE;
            gCurrentPinballGame->ball->spinAngle -= 0x40;
            gCurrentPinballGame->ball->positionQ8.x = 0x8F00;
            gCurrentPinballGame->ball->positionQ8.y = 0xC300;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        if (gCurrentPinballGame->deliveryAnimFrameIndex == 10)
            gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
    }
}

void SphealBoard_PelipperDeliversBall(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    s16 index;

    group = &gMain.spriteGroups[SG_SPHEAL_PELIPPER_ENTITY];
    if (group->active)
    {
        group->baseX = (gCurrentPinballGame->pelipperPosX / 10) - (gCurrentPinballGame->cameraXOffset - 146);
        group->baseY = (gCurrentPinballGame->pelipperPosY / 10) - (gCurrentPinballGame->cameraYOffset - 110) + (gCurrentPinballGame->pelipperYBobOffset / 10);
        index = gCurrentPinballGame->deliveryAnimFrameIndex;
        DmaCopy16(3, gPelipper_Gfx[index], (void *)0x060125A0, 0x480);
        for (i = 0; i < 4; i++)
        {
            oamSimple = &group->oam[i];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        }
    }

    if (gCurrentPinballGame->deliveryAnimTimer <= 250)
    {
        if (gCurrentPinballGame->deliveryAnimTimer == 250)
        {
            gCurrentPinballGame->pelipperPosX = 920;
            gCurrentPinballGame->pelipperPosY = -100;
            gCurrentPinballGame->pelipperFlyVelX = -82;
            gCurrentPinballGame->pelipperFlyVelY = 0;
            gCurrentPinballGame->pelipperFrameTimer = 0;
            gCurrentPinballGame->pelipperState = 8;
            gCurrentPinballGame->deliveryAnimFrameIndex = 13;
            gMain.spriteGroups[SG_SPHEAL_PELIPPER_ENTITY].active = TRUE;
            gCurrentPinballGame->cameraLocked = TRUE;
        }
    }
    else
    {
        gCurrentPinballGame->deliveryAnimFrameIndex = (gCurrentPinballGame->pelipperFrameTimer % 24) / 6 + 13;
        gCurrentPinballGame->pelipperYBobOffset = MulSin(240, gCurrentPinballGame->pelipperFrameTimer * 0x400);
        if (gCurrentPinballGame->pelipperFrameTimer == 0)
            m4aSongNumStart(SE_PELIPPER_SWOOSH);

        if (gCurrentPinballGame->pelipperFrameTimer < 40)
        {
            gCurrentPinballGame->pelipperPosX += gCurrentPinballGame->pelipperFlyVelX;
            gCurrentPinballGame->pelipperPosY += gCurrentPinballGame->pelipperFlyVelY;
        }
        else
        {
            gMain.spriteGroups[SG_SPHEAL_PELIPPER_ENTITY].active = FALSE;
        }

        if (gCurrentPinballGame->pelipperFrameTimer == 13)
        {
            gCurrentPinballGame->ball->ballHidden = FALSE;
            gCurrentPinballGame->pelipperBallDropVelX = -10;
            gCurrentPinballGame->pelipperBallDropVelY = -25;
            gCurrentPinballGame->pelipperBallDropPosX = ((gCurrentPinballGame->pelipperPosX / 10) + 157) * 10;
            gCurrentPinballGame->pelipperBallDropPosY = ((gCurrentPinballGame->pelipperPosY / 10) + 134) * 10;
            gCurrentPinballGame->ball->oamPriority = 1;
        }

        if (gCurrentPinballGame->ballPhysicsState != BALL_PHYSICS_NORMAL)
        {
            if (gCurrentPinballGame->pelipperFrameTimer < 13)
            {
                gCurrentPinballGame->ball->positionQ0.x = (gCurrentPinballGame->pelipperPosX / 10) + 157;
                gCurrentPinballGame->ball->positionQ0.y = (gCurrentPinballGame->pelipperPosY / 10) + 134;
                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
            else
            {
                gCurrentPinballGame->pelipperBallDropVelY += 2;
                gCurrentPinballGame->pelipperBallDropPosX += gCurrentPinballGame->pelipperBallDropVelX;
                gCurrentPinballGame->pelipperBallDropPosY += gCurrentPinballGame->pelipperBallDropVelY;
                gCurrentPinballGame->ball->positionQ0.x = gCurrentPinballGame->pelipperBallDropPosX / 10;
                gCurrentPinballGame->ball->positionQ0.y = gCurrentPinballGame->pelipperBallDropPosY / 10;
                if (gCurrentPinballGame->ball->positionQ0.y >= 181)
                {
                    gCurrentPinballGame->ball->positionQ0.y = 181;
                    gCurrentPinballGame->ballUpgradeTimerPaused = FALSE;
                    gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                    gCurrentPinballGame->ball->velocity.x = -10;
                    gCurrentPinballGame->ball->velocity.y = 0;
                    gCurrentPinballGame->cameraLocked = FALSE;
                    gCurrentPinballGame->ball->oamPriority = 3;
                    gCurrentPinballGame->boardLayerDepth = 0;
                    gCurrentPinballGame->ballDeliveryActive = FALSE;
                    m4aSongNumStart(SE_PELIPPER_BALL_DROP_LANDS);
                    PlayRumble(7);
                }

                gCurrentPinballGame->ball->positionQ1.x = gCurrentPinballGame->ball->positionQ0.x * 2;
                gCurrentPinballGame->ball->positionQ1.y = gCurrentPinballGame->ball->positionQ0.y * 2;
                gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
                gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            }
        }

        gCurrentPinballGame->pelipperFrameTimer++;
    }

    gCurrentPinballGame->deliveryAnimTimer++;
}

// Handles the sequence of the object being bounced, up, and into hoop.
void UpdateSealeoKnockdownPhysics(void)
{
    s16 i;
    s16 targetSealeoIx; // 0= left, 1 = right

    for (i = 0; i < 3; i++)
    {
        switch (gCurrentPinballGame->knockdownPhase[i])
        {
        case SPHEAL_KNOCKDOWN_PHASE_WAITING:
            gCurrentPinballGame->knockdownTargetIndex[i] = TARGET_SEALEO_LEFT;
            break;
        case SPHEAL_KNOCKDOWN_PHASE_BALL_PROXIMITY_CROSSED:
            targetSealeoIx = gCurrentPinballGame->knockdownTargetIndex[i];
            gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_ANTICIPATE_BOUNCE;
            gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
            gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 7;

            // If the ball crosses the first rollover trigger, (corner of ramp, readying the sealeo)
            // but fails to cross the second, (at the end of the ramp) within a given number of frames,
            // reset the sealeo, and stop the knockdown phase.
            if (gCurrentPinballGame->knockdownBallReadinessTimer[i])
            {
                gCurrentPinballGame->knockdownBallReadinessTimer[i]--;
                if (gCurrentPinballGame->knockdownBallReadinessTimer[i] == 0)
                {
                    gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
                    gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_READY;
                    gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
                    gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 4;
                }
            }
            break;
        case SPHEAL_KNOCKDOWN_PHASE_PREPARE_BOUNCE:
            targetSealeoIx = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i == 2)
            {
                // Ball
                gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_MANUAL;
                gCurrentPinballGame->ball->velocity.x += 5 - targetSealeoIx * 10;
            }

            gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_VERTICAL_BOUNCE;
            gCurrentPinballGame->knockdownBounceCount[i] = 0;
            gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_ANTICIPATE_BOUNCE;
            gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
            gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 7;
            break;
        case SPHEAL_KNOCKDOWN_PHASE_VERTICAL_BOUNCE:
            targetSealeoIx = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                // Spheals
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x >= 0x5600)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x <= 0x9C00)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;

                }

                gCurrentPinballGame->sphealVelocity[i].y += 12;

                if (gCurrentPinballGame->sealeoStunnedTimer[targetSealeoIx] > 0)
                {
                    // If sealeo recovers from being stunned, before the ball would bounce, it's ok.
                    // If the spheal crosses the threshold while the sealeo is stunned, it is dropped.
                    if (gCurrentPinballGame->sphealPositionQ8[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->knockdownBounceCount[i] = 0;
                        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_DROPPED;
                        gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_DONE_BOUNCING;
                        gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 15;
                        gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
                    }
                }
                else
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].y >= 0x6600)
                    {
                        gCurrentPinballGame->knockdownBounceCount[i]++;
                        MPlayStart(&gMPlayInfo_SE1, &se_sealeo_nose_bounce);
                        if (gCurrentPinballGame->knockdownBounceCount[i] < 3)
                        {
                            gCurrentPinballGame->sphealPositionQ8[i].y = 0x6600;
                            gCurrentPinballGame->sphealVelocity[i].y = 0xFED4;
                            gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_BOUNCING;
                            gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_ANTICIPATE_BOUNCE;
                            gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 8;
                            gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 12;
                        }
                        else
                        {
                            gCurrentPinballGame->sphealVelocity[i].x = (30 - targetSealeoIx * 60) * 4;
                            gCurrentPinballGame->sphealVelocity[i].y = 0xFE70;
                            gCurrentPinballGame->knockdownBounceCount[i] = 0;
                            gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_BOUNCE_TO_HOOP;
                            gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_DONE_BOUNCING;
                            gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 11;
                            gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
                            gCurrentPinballGame->scoreCountdownTimer = 100;
                            gCurrentPinballGame->sphealKnockdownCount[0]++;
                        }
                    }
                }
            }
            else
            {
                // Ball
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x5600)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x9C00)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                gCurrentPinballGame->ball->velocity.y += 3;
                if (gCurrentPinballGame->ball->positionQ8.y >= 0x6500)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    MPlayStart(&gMPlayInfo_SE1, &se_sealeo_nose_bounce);
                    PlayRumble(7);
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 3)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x6500;
                        gCurrentPinballGame->ball->velocity.y = -0x5A;
                        gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_ANTICIPATE_BOUNCE;
                        gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 8;
                        gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 12;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.x = 28 - targetSealeoIx * 56;
                        gCurrentPinballGame->ball->velocity.y = -0x78;
                        gCurrentPinballGame->knockdownBounceCount[i] = 0;
                        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_BOUNCE_TO_HOOP;
                        gCurrentPinballGame->minionState[targetSealeoIx] = SEALEO_ENTITY_STATE_DONE_BOUNCING;
                        gCurrentPinballGame->minionFramesetIx[targetSealeoIx] = 11;
                        gCurrentPinballGame->minionStateTimer[targetSealeoIx] = 0;
                        gCurrentPinballGame->scoreCountdownTimer = 106;
                        gCurrentPinballGame->sphealKnockdownCount[1]++;
                    }
                }
            }
            break;
        case SPHEAL_KNOCKDOWN_PHASE_BOUNCE_TO_HOOP:
            targetSealeoIx = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                //Spheals
                gCurrentPinballGame->sphealVelocity[i].y += 12;
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x >= 0x7800)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x <= 0x7800)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;
                }

                if (gCurrentPinballGame->sphealPositionQ8[i].y >= 0x8400)
                {
                    gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_LAND_AND_WALK_TO_WATER;
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealWasStunned[i] = FALSE;
                }
            }
            else
            {
                //Ball
                gCurrentPinballGame->ball->velocity.y += 3;
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8400)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8400;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                        if (gCurrentPinballGame->knockdownBounceCount[i] == 1)
                            PlayRumble(7);
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - targetSealeoIx * 10;
                        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
                    }
                }
            }
            break;
        case SPHEAL_KNOCKDOWN_PHASE_DROPPED:
            targetSealeoIx = gCurrentPinballGame->knockdownTargetIndex[i];
            if (i < 2)
            {
                //Spheals
                gCurrentPinballGame->sphealVelocity[i].y += 12;
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x >= 0x7800)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->sphealPositionQ8[i].x <= 0x7800)
                        gCurrentPinballGame->sphealVelocity[i].x = 0;
                }

                if (gCurrentPinballGame->sphealPositionQ8[i].y >= 0x8E00)
                {
                    gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
                    gCurrentPinballGame->sphealEntityState[i] = SPHEAL_ENTITY_STATE_LAND_AND_WALK_TO_WATER;
                    gCurrentPinballGame->sphealAnimTimer[i] = 0;
                    gCurrentPinballGame->sphealWasStunned[i] = FALSE;
                }
            }
            else
            {
                // Ball -- Dropped ball should be an unreachable branch.
                // This may be dead code from a time when multiball was a thing
                gCurrentPinballGame->ball->velocity.y += 3;
                if (targetSealeoIx == TARGET_SEALEO_LEFT)
                {
                    if (gCurrentPinballGame->ball->positionQ8.x >= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }
                else
                {
                    if (gCurrentPinballGame->ball->positionQ8.x <= 0x7800)
                        gCurrentPinballGame->ball->velocity.x = 0;
                }

                if (gCurrentPinballGame->ball->positionQ8.y >= 0x8E00)
                {
                    gCurrentPinballGame->knockdownBounceCount[i]++;
                    if (gCurrentPinballGame->knockdownBounceCount[i] < 2)
                    {
                        gCurrentPinballGame->ball->positionQ8.y = 0x8E00;
                        gCurrentPinballGame->ball->velocity.y = -gCurrentPinballGame->ball->velocity.y / 3;
                        gCurrentPinballGame->ball->velocity.x = 0;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->velocity.y = 0;
                        gCurrentPinballGame->ball->velocity.x = 5 - targetSealeoIx * 10;
                        gCurrentPinballGame->ballPhysicsState = BALL_PHYSICS_NORMAL;
                        gCurrentPinballGame->knockdownPhase[i] = SPHEAL_KNOCKDOWN_PHASE_WAITING;
                    }
                }
            }
            break;
        }
    }
}

void AnimateSphealBackground(void)
{
    s16 i;
    s16 var0;

    var0 = gWaterTilePaletteCycle[(gMain.systemFrameCount % 96) / 24];
    for (i = 0x100; i < 0x400; i++)
        gBG0TilemapBuffer[0x800 + i] = gSphealWaterBackgroundTilemap[i] + var0 * 4;

    DmaCopy16(3, &gBG0TilemapBuffer[0x800], BG_CHAR_SCREEN_ADDR(0,0), BG_SCREEN_SIZE);
}

void UpdateSphealResultsScreen(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    int value;
    s16 sp0[12];
    s16 sp18[12];

    if (gCurrentPinballGame->boardState > SPHEAL_BOARD_STATE_SCORE_DISPLAY)
    {
        if (gCurrentPinballGame->bannerSlideYOffset > -126)
        {
            gCurrentPinballGame->bannerSlideYOffset -= 6;
            gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bannerSlideYOffset + 4;
        }
    }
    else
    {
        if (gCurrentPinballGame->bannerSlideYOffset < 0)
        {
            gCurrentPinballGame->bannerSlideYOffset += 6;
            if (gCurrentPinballGame->bannerSlideYOffset > 0)
                gCurrentPinballGame->bannerSlideYOffset = 0;
        }

        gMain.bgOffsets[1].yOffset = -gCurrentPinballGame->bannerSlideYOffset + 4;
    }

    if (gCurrentPinballGame->boardState < SPHEAL_BOARD_STATE_PREPARE_RETURN)
    {
        gMain.blendControl = 0x1C42;
        gMain.blendAlpha = 0xC04;
    }

    if (gCurrentPinballGame->boardState == SPHEAL_BOARD_STATE_SCORE_DISPLAY)
    {
        if (gCurrentPinballGame->stageTimer)
            gCurrentPinballGame->stageTimer += 0;
    }

    if (gCurrentPinballGame->resultsAnimTimer > 100 && gCurrentPinballGame->resultsAnimTimer < 450)
    {
        if (gCurrentPinballGame->sphealKnockdownDisplayCount[0] != gCurrentPinballGame->sphealKnockdownCount[0])
        {
            if ((gCurrentPinballGame->resultsAnimTimer % 3) == 0)
            {
                gCurrentPinballGame->sphealKnockdownDisplayCount[0]++;
                m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            }
        }
        else
        {
            gCurrentPinballGame->resultsAnimTimer = 490;
        }
    }

    if (gCurrentPinballGame->resultsAnimTimer > 500 && gCurrentPinballGame->resultsAnimTimer < 800)
    {
        if (gCurrentPinballGame->sphealKnockdownDisplayCount[1] != gCurrentPinballGame->sphealKnockdownCount[1])
        {
            if ((gCurrentPinballGame->resultsAnimTimer % 3) == 0)
            {
                gCurrentPinballGame->sphealKnockdownDisplayCount[1]++;
                m4aSongNumStart(SE_BONUS_SCORE_TALLIED);
            }
        }
        else
        {
            gCurrentPinballGame->resultsAnimTimer = 800;
        }
    }

    if (gCurrentPinballGame->resultsAnimTimer < 800 && gCurrentPinballGame->stageTimer > 160)
        gCurrentPinballGame->stageTimer = 160;

    gCurrentPinballGame->resultsAnimTimer++;

    group = &gMain.spriteGroups[SG_SPHEAL_END_SCORE_PANEL];
    if (!group->active)
        return;

    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 22; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0] * SCORE_PER_SPHEAL_IN_NET;
    sp0[0] = LEAD_DIGIT_10M(value);
    sp0[1] = DIGIT_1M(value);
    sp0[2] = 10;
    sp0[3] = DIGIT_100K(value);
    sp0[4] = DIGIT_10K(value);
    sp0[5] = DIGIT_1K(value);
    sp0[6] = 10;
    sp0[7] = DIGIT_100S(value);
    sp0[8] = DIGIT_10S(value);
    sp0[9] = DIGIT_1S(value);
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0];
    sp0[0] = LEAD_DIGIT_10S(value);
    sp0[1] = DIGIT_1S(value);
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[SG_SPHEAL_END_SCORE_SPHEALS_SUNK];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[1] * SCORE_PER_BALL_IN_NET;
    sp0[0] = LEAD_DIGIT_10M(value);
    sp0[1] = DIGIT_1M(value);
    sp0[2] = 10;
    sp0[3] = DIGIT_100K(value);
    sp0[4] = DIGIT_10K(value);
    sp0[5] = DIGIT_1K(value);
    sp0[6] = 10;
    sp0[7] = DIGIT_100S(value);
    sp0[8] = DIGIT_10S(value);
    sp0[9] = DIGIT_1S(value);
    for (i = 0; i < 9; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[1];
    sp0[0] = LEAD_DIGIT_10S(value);
    sp0[1] = DIGIT_1S(value);
    if (sp0[0] == 0)
        sp0[0] = 0x14;
    sp18[10] = sp0[0] * 2 + 0x2D0;
    sp18[11] = sp0[1] * 2 + 0x2D0;

    group = &gMain.spriteGroups[SG_SPHEAL_END_SCORE_BALLS_SUNK];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }

    value = gCurrentPinballGame->sphealKnockdownDisplayCount[0] * SCORE_PER_SPHEAL_IN_NET
          + gCurrentPinballGame->sphealKnockdownDisplayCount[1] * SCORE_PER_BALL_IN_NET;
    gCurrentPinballGame->totalBonusScore = value;
    sp0[0] = LEAD_DIGIT_100M(value);
    sp0[1] = DIGIT_10M(value);
    sp0[2] = DIGIT_1M(value);
    sp0[3] = 10;
    sp0[4] = DIGIT_100K(value);
    sp0[5] = DIGIT_10K(value);
    sp0[6] = DIGIT_1K(value);
    sp0[7] = 10;
    sp0[8] = DIGIT_100S(value);
    sp0[9] = DIGIT_10S(value);
    sp0[10] = DIGIT_1S(value);
    for (i = 0; i < 10; i++)
    {
        if (sp0[i] % 10 == 0)
            sp0[i] = 0x14;
        else
            break;
    }

    sp18[0] = sp0[0] * 2 + 0x2D0;
    sp18[1] = sp0[1] * 2 + 0x2D0;
    sp18[2] = sp0[2] * 2 + 0x2D0;
    sp18[3] = sp0[3] * 2 + 0x2D0;
    sp18[4] = sp0[4] * 2 + 0x2D0;
    sp18[5] = sp0[5] * 2 + 0x2D0;
    sp18[6] = sp0[6] * 2 + 0x2D0;
    sp18[7] = sp0[7] * 2 + 0x2D0;
    sp18[8] = sp0[8] * 2 + 0x2D0;
    sp18[9] = sp0[9] * 2 + 0x2D0;
    sp18[10] = sp0[10] * 2 + 0x2D0;
    value = gCurrentPinballGame->ballUpgradeType + 1;
    sp0[0] = value;
    sp18[11] = sp0[0] * 2 + 0x2D0;

    group = &gMain.spriteGroups[SG_SPHEAL_END_SCORE_TOTAL];
    group->baseX = 120;
    group->baseY = 60 + gCurrentPinballGame->bannerSlideYOffset;
    for (i = 0; i < 12; i++)
    {
        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = sp18[i];
    }
}
