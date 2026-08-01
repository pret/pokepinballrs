#include "global.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/board/kecleon_states.h"

#define KECLEON_MODE_TIME TICKS_FOR_TIME(2,0)

extern void UpdateKecleonEntityLogic(void);
extern void RenderKecleonSprites(void);
extern void UpdateKecleonScopeItem(void);
extern void UpdateKecleonScopeVision(void);
extern void RenderKecleonBoardElements(void);
extern void SortKecleonSpritesByY(void);

extern const struct SpriteSet *gKecleonSpriteSets[];

struct KecleonMoveNode
{
    u8 adjacentStates[4];
    u16 velocity[2];
};
struct KecleonSpriteSortEntry
{
    const struct SpriteSet *spriteSet;
    u8 ySortKey;
    u8 spriteIndex;
};

extern const u8 gKecleonBonusClear_Gfx[];
extern const u16 gKecleonBerryOverlayTilemap[];
extern const u8 gKecleonStageKecleon_Gfx[][0x280];
extern const u8 gKecleonStageKecleonFx_Gfx[][0x100];
extern struct SongHeader se_kecleon_side_look;
extern struct SongHeader se_kecleon_vanish;
extern struct SongHeader se_kecleon_startled;
extern struct SongHeader se_kecleon_running;
extern struct SongHeader se_kecleon_knocked_over;
extern struct SongHeader se_kecleon_hit_damaged;
extern struct SongHeader se_kecleon_hits_ground_defeated;
extern struct SongHeader se_kecleon_seeing_stars;
extern const u16 gKecleonAnimFramesetTable[][3];
extern const s16 gKecleonOverlayTileAnimIndices[];
extern const u16 gKecleonVisibleWalkDirectionMap[];
extern const u16 gKecleonInvisibleDashDirectionMap[];
extern const struct KecleonMoveNode gKecleonMovementTargetGraph[];
extern const struct Vector16 gKecleonScopeFallTargets[];
extern const u16 *gKecleonOverlayTilemapPointers[];
extern const s16 gKecleonPlantAnimIndices[];
extern const struct KecleonSpriteSortEntry gKecleonSpriteYSortData[];
extern const u16 gKecleonLowerBodyOamData[126][2][3];
extern const u16 gKecleonUpperBodyOamData[126][2][3];
extern const struct SpriteSet *gKecleonBoardSpriteSets[];

void KecleonBoardProcess_3A_35860(void)
{
    s16 i;

    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = BONUS_BOARD_SUBSTATE_ACTIVE;
    gCurrentPinballGame->boardState = KECLEON_BOARD_STATE_INTRO;
    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_PAUSED;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + KECLEON_MODE_TIME; // 120 seconds
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballGrabbed = FALSE;
    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_INITIAL_SPAWN;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->ball->ballHidden = TRUE;
    gCurrentPinballGame->returnToMainBoardFlag = FALSE;
    gCurrentPinballGame->kecleonTargetVisible = TRUE;
    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_SPAWN;
    gCurrentPinballGame->bossPositionX = 750;
    gCurrentPinballGame->bossPositionY = 360;
    gCurrentPinballGame->bossVulnerable = 3;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_NONE;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->kecleonTargetState = 0;
    gCurrentPinballGame->kecleonTargetFrameIndex = 0;
    gCurrentPinballGame->kecleonFallDirection = 0;
    gCurrentPinballGame->kecleonCollisionEnabled = FALSE;
    gCurrentPinballGame->kecleonCamoStrength = 0;
    gCurrentPinballGame->kecleonDustGfxFrame = 0;
    gCurrentPinballGame->kecleonBoardHitState = 0;
    gCurrentPinballGame->kecleonHitFrameIndex = 0;
    gCurrentPinballGame->kecleonTargetActive = FALSE;
    gCurrentPinballGame->kecleonAnimTimer = 0;
    gCurrentPinballGame->kecleonCollisionX = 0;
    gCurrentPinballGame->kecleonCollisionY = 0;
    gCurrentPinballGame->kecleonFrameTimer = 0;
    gCurrentPinballGame->kecleonWaterBallCollisionTimer = 0;
    gCurrentPinballGame->kecleonWaterCollisionTimer = 0;
    for (i = 0; i < 4; i++)
        gCurrentPinballGame->kecleonFlowerMotionTimer[i] = 0;

    for (i = 0; i < 10; i++)
        gCurrentPinballGame->kecleonBushMotionTimer[i] = 0;

    for (i = 0; i < 7; i++)
        gCurrentPinballGame->kecleonWaterMotionTimer[i] = 0;

    gCurrentPinballGame->flippersDisabled = FALSE;
    gCurrentPinballGame->kecleonCollisionPos.y = gCurrentPinballGame->bossPositionY / 10 + 58;
    SortKecleonSpritesByY();
    gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_STANDING;
    UpdateKecleonEntityLogic();
    RenderKecleonSprites();
    m4aSongNumStart(MUS_BONUS_FIELD_KECLEON);
    UpdateKecleonScopeItem();
    UpdateKecleonScopeVision();
    RenderKecleonBoardElements();
    DmaCopy16(3, gBonusStageObjPal, (void *)0x05000320, 0x20);
}

void KecleonBoardProcess_3B_35AA4(void)
{
    SortKecleonSpritesByY();
    switch (gCurrentPinballGame->boardState)
    {
    case KECLEON_BOARD_STATE_INTRO:
        gCurrentPinballGame->ballUpgradeTimerPaused = TRUE;
        if (gCurrentPinballGame->stageTimer < 120)
        {
            gCurrentPinballGame->cameraYAdjust = (gCurrentPinballGame->stageTimer / 5) + 0xFFE8;
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->cameraYAdjust = 0;
            gCurrentPinballGame->boardState = KECLEON_BOARD_STATE_BATTLE_PHASE;
            gCurrentPinballGame->stageTimer = 0;
        }

        if (!gCurrentPinballGame->returnToMainBoardFlag)
        {
            gMain.blendControl = 0x1C10;
            gMain.blendAlpha = BLDALPHA_BLEND(16, 0);
        }
        break;
    case KECLEON_BOARD_STATE_BATTLE_PHASE:
        if (!gCurrentPinballGame->returnToMainBoardFlag)
        {
            if (gCurrentPinballGame->kecleonFrameTimer == 0)
            {
                u16 var0 = 16 - gCurrentPinballGame->kecleonCamoStrength;
                u16 var1 = gCurrentPinballGame->kecleonCamoStrength;
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = BLDALPHA_BLEND(var0, var1);
            }
            else
            {
                gMain.blendControl = 0x1C42;
                gMain.blendAlpha = BLDALPHA_BLEND(7, 9);
            }
        }
        break;
    case KECLEON_BOARD_STATE_ENDING_BANNER:
        if (gCurrentPinballGame->stageTimer < 10)
        {
            gCurrentPinballGame->stageTimer++;
        }
        else
        {
            gCurrentPinballGame->boardState = KECLEON_BOARD_STATE_SCORING;
            gCurrentPinballGame->stageTimer = 0;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER].active = TRUE;
            gMain.spriteGroups[SG_BONUS_COMPLETE_BANNER_SCORE].active = TRUE;
            DmaCopy16(3, gKecleonBonusClear_Gfx, (void *)0x6015800, 0x2000);
            gCurrentPinballGame->bannerSlideYOffset = 0x88;
            gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
        }
        break;
    case KECLEON_BOARD_STATE_SCORING:
        ProcessBonusBannerAndScoring();
        if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            gCurrentPinballGame->stageTimer = 181;

        if (gCurrentPinballGame->stageTimer == 180)
        {
            gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
            gCurrentPinballGame->scoreAddStepSize = SCORE_STEP_KECLEON_BONUS_TALLY;
            gCurrentPinballGame->scoreAddedInFrame = SCORE_KECLEON_BONUS_COMPLETE;
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
            gCurrentPinballGame->boardState = KECLEON_BOARD_STATE_SCORE_COUNTING_FINISHED;
            gCurrentPinballGame->numCompletedBonusStages++;
        }
        break;
    case KECLEON_BOARD_STATE_SCORE_COUNTING_FINISHED:
        ProcessBonusBannerAndScoring();
        gCurrentPinballGame->returnToMainBoardFlag = TRUE;
        break;
    }

    UpdateKecleonEntityLogic();
    RenderKecleonSprites();
    UpdateKecleonScopeItem();
    UpdateKecleonScopeVision();
    if (gCurrentPinballGame->eventTimerType
        && gCurrentPinballGame->eventTimer < 2
        && gMain.modeChangeFlags == MODE_CHANGE_NONE)
    {
        m4aMPlayAllStop();
        m4aSongNumStart(MUS_END_OF_BALL3);
        gCurrentPinballGame->kecleonBoardHitState = 0;
        gCurrentPinballGame->kecleonAnimTimer = 0;
        gCurrentPinballGame->kecleonTargetActive = FALSE;
        gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
        FadeToMainBoard();

    BonusStage_HandleModeChangeFlags();
    RenderKecleonBoardElements();
}

void UpdateKecleonEntityLogic(void)
{
    const u16 VECTORSCALEDOWN = 20000;
    int deltaX;
    int deltaY;
    struct Vector32 tempVec;
    struct Vector32 deltaVec;
    u16 angle;
    int xx, yy;
    int squaredDistance;

    switch (gCurrentPinballGame->bossEntityState)
    {
    case KECLEON_ENTITY_STATE_SPAWN:
        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_WALK_TO_CENTER;
        gCurrentPinballGame->bossFramesetIndex = 3;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossPositionX = 750;
        gCurrentPinballGame->bossPositionY = 360;
        gCurrentPinballGame->kecleonTargetState = gKecleonMovementTargetGraph[10].adjacentStates[(Random() * gMain.systemFrameCount) & 0x3];
        break;
    case KECLEON_ENTITY_STATE_WALK_TO_CENTER:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            if (++gCurrentPinballGame->bossFramesetIndex == 9)
                gCurrentPinballGame->bossFramesetIndex = 3;
        }

        if (gCurrentPinballGame->bossPositionX > 0)
        {
            gCurrentPinballGame->bossPositionX -= 6;
        }
        else
        {
            gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_VANISH;
            gCurrentPinballGame->bossFramesetIndex = 59;
            gCurrentPinballGame->bossFrameTimer = 0;
        }

        if (gCurrentPinballGame->ballRespawnTimer > 2)
            gCurrentPinballGame->ballRespawnTimer--;
        break;
    case KECLEON_ENTITY_STATE_VANISH:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            if (++gCurrentPinballGame->bossFramesetIndex == 66)
            {
                gCurrentPinballGame->bossFramesetIndex = 65;
                if (gCurrentPinballGame->kecleonFrameTimer < 8)
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_WALK_LOCATION;
                }
                else
                {
                    int rand, mask;

                    if (gCurrentPinballGame->kecleonTargetFrameIndex)
                    {
                        gCurrentPinballGame->bossFrameTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFrameTimer = 0;
                        gCurrentPinballGame->kecleonTargetFrameIndex = 1;
                    }

                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;

                    rand = Random() + gMain.systemFrameCount;
                    mask = 0x3;
                    gCurrentPinballGame->kecleonTargetState = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].adjacentStates[rand & mask];
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == 60 || gCurrentPinballGame->bossFramesetIndex == 61)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_side_look);
        }

        if (gCurrentPinballGame->bossFramesetIndex == 64)
        {
            gCurrentPinballGame->kecleonCamoStrength = gCurrentPinballGame->bossFrameTimer / 2;
            if (gCurrentPinballGame->bossFrameTimer == 4)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_vanish);
        }
        break;
    case KECLEON_ENTITY_STATE_CHOOSE_WALK_LOCATION:
        gCurrentPinballGame->bossTargetXPosition = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].velocity[0];
        gCurrentPinballGame->bossTargetYPosition = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].velocity[1];
        deltaVec.x = gCurrentPinballGame->bossTargetXPosition - gCurrentPinballGame->bossPositionX;
        deltaVec.y = gCurrentPinballGame->bossTargetYPosition - gCurrentPinballGame->bossPositionY;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        gCurrentPinballGame->kecleonFramesetBase = gKecleonVisibleWalkDirectionMap[angle / ANGLE_45];
        gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_WALK_TO_TARGET;
        break;
    case KECLEON_ENTITY_STATE_WALK_TO_TARGET:
    {
        deltaVec.x = gCurrentPinballGame->bossTargetXPosition - gCurrentPinballGame->bossPositionX;
        deltaVec.y = gCurrentPinballGame->bossTargetYPosition - gCurrentPinballGame->bossPositionY;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        squaredDistance = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 6 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -6 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->bossPositionX += tempVec.x;
        gCurrentPinballGame->bossPositionY += tempVec.y;
        if (squaredDistance < 2500)
        {
            gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_OBSERVING;
            if (gCurrentPinballGame->kecleonFramesetBase == 3)
            {
                gCurrentPinballGame->kecleonFramesetBase = 66;
                gCurrentPinballGame->bossFramesetIndex = 66;
            }
            else
            {
                gCurrentPinballGame->kecleonFramesetBase = 69;
                gCurrentPinballGame->bossFramesetIndex = 69;
            }

            gCurrentPinballGame->bossFrameTimer = 0;
        }

        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 6)
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;
        }
        break;
    }
    case KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION:
        if (gCurrentPinballGame->bossFrameTimer < 18)
        {
            if (gCurrentPinballGame->bossFrameTimer == 0)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_startled);

            gCurrentPinballGame->bossFrameTimer++;
            if (gCurrentPinballGame->kecleonFramesetBase == 66)
                gCurrentPinballGame->bossFramesetIndex = 37;
            else
                gCurrentPinballGame->bossFramesetIndex = 48;
        }
        else
        {
            gCurrentPinballGame->bossTargetXPosition = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].velocity[0];
            gCurrentPinballGame->bossTargetYPosition = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].velocity[1];
            deltaVec.x = gCurrentPinballGame->bossTargetXPosition - gCurrentPinballGame->bossPositionX;
            deltaVec.y = gCurrentPinballGame->bossTargetYPosition - gCurrentPinballGame->bossPositionY;
            angle = ArcTan2(deltaVec.x, -deltaVec.y);
            gCurrentPinballGame->kecleonFramesetBase = gKecleonInvisibleDashDirectionMap[angle / ANGLE_45];
            gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;
            gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RUN_TO_TARGET;
        }
        break;
    case KECLEON_ENTITY_STATE_RUN_TO_TARGET:
        deltaVec.x = gCurrentPinballGame->bossTargetXPosition - gCurrentPinballGame->bossPositionX;
        deltaVec.y = gCurrentPinballGame->bossTargetYPosition - gCurrentPinballGame->bossPositionY;
        xx = deltaVec.x * deltaVec.x;
        yy = deltaVec.y * deltaVec.y;
        squaredDistance = xx + yy;
        angle = ArcTan2(deltaVec.x, -deltaVec.y);
        tempVec.x = 10 * Cos(angle) / VECTORSCALEDOWN;
        tempVec.y = -10 * Sin(angle) / VECTORSCALEDOWN;
        gCurrentPinballGame->bossPositionX += tempVec.x;
        gCurrentPinballGame->bossPositionY += tempVec.y;
        if (squaredDistance < 2500)
        {
            if (gCurrentPinballGame->bonusModeHitCount > 9)
            {
                if (gCurrentPinballGame->kecleonFramesetBase == 66)
                {
                    gCurrentPinballGame->kecleonFramesetBase = 75;
                    gCurrentPinballGame->bossPositionX += 240;
                }
                else
                {
                    gCurrentPinballGame->kecleonFramesetBase = 95;
                    gCurrentPinballGame->bossPositionX -= 240;
                }

                gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_SURRENDERS;
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;
            }
            else
            {
                if (gCurrentPinballGame->kecleonCamoStrength < 16)
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_VANISH;
                    gCurrentPinballGame->bossFramesetIndex = 62;
                    gCurrentPinballGame->bossFrameTimer = 0;
                }
                else
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RESTING;
                    if (gCurrentPinballGame->kecleonFramesetBase == 38)
                    {
                        gCurrentPinballGame->kecleonFramesetBase = 42;
                        gCurrentPinballGame->bossFramesetIndex = 42;
                    }
                    else
                    {
                        gCurrentPinballGame->kecleonFramesetBase = 53;
                        gCurrentPinballGame->bossFramesetIndex = 53;
                    }

                    gCurrentPinballGame->bossFrameTimer = 0;
                }
            }
        }

        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 4)
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;

            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 1)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_running);
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 3)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_running);
        }
        break;
    case KECLEON_ENTITY_STATE_RESTING:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 6)
            {
                int rand, mask;

                if (gCurrentPinballGame->kecleonFrameTimer < 8)
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_WALK_LOCATION;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonTargetFrameIndex)
                    {
                        gCurrentPinballGame->bossFrameTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFrameTimer = 0;
                        gCurrentPinballGame->kecleonTargetFrameIndex = 1;
                    }

                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->kecleonTargetState = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].adjacentStates[rand & mask];
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 5;
            }
        }
        break;
    case KECLEON_ENTITY_STATE_OBSERVING:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            int rand, mask;

            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 2)
            {
                if (gCurrentPinballGame->kecleonFrameTimer < 8)
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_WALK_LOCATION;
                }
                else
                {
                    if (gCurrentPinballGame->kecleonTargetFrameIndex)
                    {
                        gCurrentPinballGame->bossFrameTimer = 20;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFrameTimer = 0;
                        gCurrentPinballGame->kecleonTargetFrameIndex = 1;
                    }

                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;
                }

                rand = Random() + gMain.systemFrameCount;
                mask = 0x3;
                gCurrentPinballGame->kecleonTargetState = gKecleonMovementTargetGraph[gCurrentPinballGame->kecleonTargetState].adjacentStates[rand & mask];
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 1;
            }
        }
        break;
    case KECLEON_ENTITY_STATE_HIT_WHILE_STANDING:
        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_KNOCKED_OVER;
        if (gMain.systemFrameCount & 1)
        {
            if (gCurrentPinballGame->bossPositionX < -640)
            {
                gCurrentPinballGame->kecleonFallDirection = 1;
                gCurrentPinballGame->kecleonFramesetBase = 32;
            }
            else
            {
                gCurrentPinballGame->kecleonFallDirection = 0;
                gCurrentPinballGame->kecleonFramesetBase = 27;
            }
        }
        else
        {
            if (gCurrentPinballGame->bossPositionX > 640)
            {
                gCurrentPinballGame->kecleonFallDirection = 0;
                gCurrentPinballGame->kecleonFramesetBase = 27;
            }
            else
            {
                gCurrentPinballGame->kecleonFallDirection = 1;
                gCurrentPinballGame->kecleonFramesetBase = 32;
            }
        }

        if (gCurrentPinballGame->kecleonCamoStrength < 16)
            gCurrentPinballGame->kecleonCamoStrength = 0;

        gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase;
        gCurrentPinballGame->bossFrameTimer = 0;
        MPlayStart(&gMPlayInfo_SE1, &se_kecleon_knocked_over);
        break;
    case KECLEON_ENTITY_STATE_KNOCKED_OVER:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 1)
                gCurrentPinballGame->kecleonDustGfxFrame = 23;

            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 2)
            {
                gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RISE_FROM_DOWN;
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 1;
            }
        }
        break;
    case KECLEON_ENTITY_STATE_HIT_WHILE_DOWN:
        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RESPOND_TO_HIT;
        gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 2;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->kecleonCamoStrength = 0;
        gCurrentPinballGame->scoreAddedInFrame = SCORE_KECLEON_HIT_WHILE_DOWN;
        gCurrentPinballGame->bonusModeHitCount++;
        MPlayStart(&gMPlayInfo_SE1, &se_kecleon_hit_damaged);
        PlayRumble(7);
        break;
    case KECLEON_ENTITY_STATE_RESPOND_TO_HIT:
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 4)
            {
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 3;
                if (gCurrentPinballGame->bonusModeHitCount < 10)
                {
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RISE_FROM_DOWN;
                }
                else
                {
                    gCurrentPinballGame->eventTimerType = EVENT_TIMER_MODE_COMPLETED;
                    gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;
                    gCurrentPinballGame->ballRespawnState = BALL_SPAWN_STATE_DISABLED;
                    gCurrentPinballGame->ballRespawnTimer = 0;
                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_RISE_FROM_DOWN;
                    gCurrentPinballGame->kecleonBoardHitState = 0;
                    gCurrentPinballGame->kecleonAnimTimer = 0;
                    gCurrentPinballGame->kecleonTargetActive = FALSE;
                    gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_NONE;
                }
            }
        }
        break;
    case KECLEON_ENTITY_STATE_RISE_FROM_DOWN:
        gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 4;
        if (gCurrentPinballGame->bossFrameTimer < 8)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            if (gCurrentPinballGame->bonusModeHitCount > 9)
            {
                if (gCurrentPinballGame->kecleonFallDirection == 0)
                {
                    gCurrentPinballGame->bossFramesetIndex = 72;
                    gCurrentPinballGame->bossPositionX -= 240;
                }
                else
                {
                    gCurrentPinballGame->bossFramesetIndex = 73;
                    gCurrentPinballGame->bossPositionX += 240;
                }

                gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;
                gCurrentPinballGame->bossFrameTimer = 20;
                gCurrentPinballGame->kecleonTargetState = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
            }
            else
            {
                if (gCurrentPinballGame->kecleonCamoStrength < 16)
                {
                    if (gCurrentPinballGame->kecleonFallDirection == 0)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 72;
                        gCurrentPinballGame->bossPositionX -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 73;
                        gCurrentPinballGame->bossPositionX += 240;
                    }

                    gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;
                    gCurrentPinballGame->bossFrameTimer = 20;
                    gCurrentPinballGame->kecleonTargetState = 3 + ((Random() * gMain.systemFrameCount) & 0x3);
                }
                else
                {
                    if (gCurrentPinballGame->kecleonFallDirection == 0)
                    {
                        gCurrentPinballGame->bossFramesetIndex = 72;
                        gCurrentPinballGame->bossPositionX -= 240;
                    }
                    else
                    {
                        gCurrentPinballGame->bossFramesetIndex = 73;
                        gCurrentPinballGame->bossPositionX += 240;
                    }

                    gCurrentPinballGame->bossFrameTimer = 0;
                    if (gCurrentPinballGame->kecleonFrameTimer < 8)
                    {
                        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_WALK_LOCATION;
                    }
                    else
                    {
                        if (gCurrentPinballGame->kecleonTargetFrameIndex)
                        {
                            gCurrentPinballGame->bossFrameTimer = 20;
                        }
                        else
                        {
                            gCurrentPinballGame->bossFrameTimer = 0;
                            gCurrentPinballGame->kecleonTargetFrameIndex = 1;
                        }

                        gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_CHOOSE_RUN_LOCATION;
                    }
                }
            }
        }
        break;
    case KECLEON_ENTITY_STATE_SURRENDERS:
        gCurrentPinballGame->kecleonCamoStrength = 0;
        if (gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;
            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 19)
            {
                gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 18;
                gCurrentPinballGame->bossEntityState = KECLEON_ENTITY_STATE_ENDING;
            }

            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 6)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_hits_ground_defeated);

            if (gCurrentPinballGame->bossFramesetIndex == gCurrentPinballGame->kecleonFramesetBase + 8)
                MPlayStart(&gMPlayInfo_SE1, &se_kecleon_seeing_stars);
        }
        break;
    case KECLEON_ENTITY_STATE_ENDING:
        if (gCurrentPinballGame->bossFrameTimer < 100)
        {
            if (gCurrentPinballGame->bossFrameTimer == 0)
            {
                gCurrentPinballGame->boardState = KECLEON_BOARD_STATE_ENDING_BANNER;
                gCurrentPinballGame->stageTimer = 0;
            }

            gCurrentPinballGame->bossFrameTimer++;
        }

        gCurrentPinballGame->bossFramesetIndex = gCurrentPinballGame->kecleonFramesetBase + 15;
        break;
    }
}

void RenderKecleonSprites(void)
{
    s16 i;
    struct SpriteGroup *spriteGroup;
    s16 sp0;
    s16 sp4;
    struct OamDataSimple *oamSimple;
    u16 *dst;
    const u16 *src;
    int var0;
    int var1;
    int baseX = 104;
    int baseY = 28;

    spriteGroup = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[23]];
    if (!spriteGroup->active)
        return;

    sp0 = gCurrentPinballGame->bossVulnerable;
    gCurrentPinballGame->bossVulnerable = gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][2];
    DmaCopy16(3, gKecleonStageKecleon_Gfx[sp0], (void *)0x6010920, 0x280);
    sp4 = gKecleonAnimFramesetTable[gCurrentPinballGame->bossFramesetIndex][0];
    spriteGroup->baseX = gCurrentPinballGame->bossPositionX / 10 + baseX - gCurrentPinballGame->cameraXOffset;
    spriteGroup->baseY = gCurrentPinballGame->bossPositionY / 10 + baseY - gCurrentPinballGame->cameraYOffset;
    if (gCurrentPinballGame->bossFramesetIndex >= 28 && gCurrentPinballGame->bossFramesetIndex < 31)
    {
        gCurrentPinballGame->bossCollisionX = 2 * (gCurrentPinballGame->bossPositionX / 10) + 144;
        gCurrentPinballGame->bossCollisionY = 2 * (gCurrentPinballGame->bossPositionY / 10) + 84;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_KNOCKED_OVER;
    }
    else if (gCurrentPinballGame->bossFramesetIndex >= 33 && gCurrentPinballGame->bossFramesetIndex < 36)
    {
        gCurrentPinballGame->bossCollisionX = 2 * (gCurrentPinballGame->bossPositionX / 10) + 240;
        gCurrentPinballGame->bossCollisionY = 2 * (gCurrentPinballGame->bossPositionY / 10) + 84;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_KNOCKED_OVER;
    }
    else
    {
        gCurrentPinballGame->bossCollisionX = 2 * (gCurrentPinballGame->bossPositionX / 10) + 208;
        gCurrentPinballGame->bossCollisionY = 2 * (gCurrentPinballGame->bossPositionY / 10) + 56;
        if (gCurrentPinballGame->bonusModeHitCount < 10)
            gCurrentPinballGame->boardEntityCollisionMode = KECLEON_COLLISION_MODE_STANDING;
    }

    gCurrentPinballGame->kecleonCollisionPos.x = (gCurrentPinballGame->bossPositionX / 10) + 120;
    gCurrentPinballGame->kecleonCollisionPos.y = (gCurrentPinballGame->bossPositionY / 10) + 58;
    if (gCurrentPinballGame->kecleonFrameTimer > 7)
        gCurrentPinballGame->kecleonTargetVisible = TRUE;
    else if (gCurrentPinballGame->kecleonCamoStrength > 15)
        gCurrentPinballGame->kecleonTargetVisible = FALSE;
    else
        gCurrentPinballGame->kecleonTargetVisible = TRUE;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gKecleonUpperBodyOamData[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->kecleonTargetVisible)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (gCurrentPinballGame->bossVulnerable == 20) {
                if(gCurrentPinballGame->bossFrameTimer < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 10;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 2;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 60;
    spriteGroup = &gMain.spriteGroups[SG_KECLEON_REFLECTION_HEAD];
    spriteGroup->baseX = gCurrentPinballGame->bossPositionX / 10 + baseX - gCurrentPinballGame->cameraXOffset;
    spriteGroup->baseY = gCurrentPinballGame->bossPositionY / 10 + baseY - gCurrentPinballGame->cameraYOffset;

    for (i = 0; i < 2; i++)
    {
        oamSimple = &spriteGroup->oam[i];
        dst = (u16*)&gOamBuffer[oamSimple->oamId];
        src = gKecleonLowerBodyOamData[sp4][i];
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;

        if (gCurrentPinballGame->kecleonTargetVisible)
        {
            gOamBuffer[oamSimple->oamId].x += spriteGroup->baseX;
            gOamBuffer[oamSimple->oamId].y += spriteGroup->baseY;
            if (sp0 == 20)
            {
                if (gCurrentPinballGame->bossFrameTimer < 10)
                    gOamBuffer[oamSimple->oamId].paletteNum = 11;
                else
                    gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
            else
            {
                gOamBuffer[oamSimple->oamId].paletteNum = 4;
            }
        }
        else
        {
            gOamBuffer[oamSimple->oamId].x = 240;
            gOamBuffer[oamSimple->oamId].y = 180;
        }
    }

    baseX = 104;
    baseY = 26;
    spriteGroup = &gMain.spriteGroups[SG_KECLEON_DUST_FX];
    var0 = gCurrentPinballGame->kecleonCollisionEnabled * 3;
    var1 = gCurrentPinballGame->kecleonDustGfxFrame / 8 - 2;

    DmaCopy16(3, gKecleonStageKecleonFx_Gfx[var0 - var1], (void *)0x6010BA0, 0x100);
    if (gCurrentPinballGame->kecleonDustGfxFrame > 0)
    {
        gCurrentPinballGame->kecleonDustGfxFrame--;
        spriteGroup->baseX = gCurrentPinballGame->bossPositionX / 10 + baseX - gCurrentPinballGame->cameraXOffset;
        spriteGroup->baseY = gCurrentPinballGame->bossPositionY / 10 + - gCurrentPinballGame->cameraYOffset + baseY;
    }
    else
    {
        spriteGroup->baseX = 0;
        spriteGroup->baseY = 180;
    }

    oamSimple = &spriteGroup->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    if (gCurrentPinballGame->kecleonFallDirection == 0)
        gOamBuffer[oamSimple->oamId].hFlip = FALSE;
    else
        gOamBuffer[oamSimple->oamId].hFlip = TRUE;
}


void UpdateKecleonScopeItem(void)
{
    s16 i;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct Vector32 tempVector;
    int xx, yy;
    int squaredDistance;

    group = &gMain.spriteGroups[SG_KECLEON_SCOPE_ITEM];
    if (!group->active)
        return;

    if (gCurrentPinballGame->kecleonBoardHitState)
    {
        if (gCurrentPinballGame->kecleonCollisionX == 0)
        {
            gCurrentPinballGame->kecleonHitFrameIndex = (Random() * gMain.systemFrameCount) % 5;
            gCurrentPinballGame->orbLogicPosition.y = 0;
            gCurrentPinballGame->orbCollisionPosition.y = 0;
        }

        if (gCurrentPinballGame->kecleonCollisionX < 40)
            gCurrentPinballGame->kecleonCollisionX++;

        if (gCurrentPinballGame->kecleonCollisionX == 20)
            m4aMPlayStop(&gMPlayInfo_SE2);

        if (gCurrentPinballGame->kecleonCollisionX == 22)
            m4aSongNumStart(SE_KECLEON_SCOPE_FALL);

        if (gCurrentPinballGame->kecleonCollisionX > 20)
        {
            gCurrentPinballGame->orbLogicPosition.x = 4;
            gCurrentPinballGame->orbLogicPosition.y += 3;
            gCurrentPinballGame->orbCollisionPosition.x = gKecleonScopeFallTargets[gCurrentPinballGame->kecleonHitFrameIndex].x;
            gCurrentPinballGame->orbCollisionPosition.y += gCurrentPinballGame->orbLogicPosition.y;
            if (gCurrentPinballGame->orbCollisionPosition.y > gKecleonScopeFallTargets[gCurrentPinballGame->kecleonHitFrameIndex].y)
            {
                gCurrentPinballGame->orbCollisionPosition.y = gKecleonScopeFallTargets[gCurrentPinballGame->kecleonHitFrameIndex].y;
                gCurrentPinballGame->orbLogicPosition.y = -(gCurrentPinballGame->orbLogicPosition.y / 6);
            }

            tempVector.x = gCurrentPinballGame->ball->positionQ0.x - (gCurrentPinballGame->orbCollisionPosition.x / 10 + 8);
            tempVector.y = gCurrentPinballGame->ball->positionQ0.y - (gCurrentPinballGame->orbCollisionPosition.y / 10 + 8);
            xx = tempVector.x * tempVector.x;
            yy = tempVector.y * tempVector.y;
            squaredDistance = xx + yy;
            if (squaredDistance <= 120)
            {
                gCurrentPinballGame->kecleonBoardHitState = 0;
                gCurrentPinballGame->kecleonTargetActive = TRUE;
                gCurrentPinballGame->kecleonAnimTimer = 0;
                gCurrentPinballGame->scoreAddedInFrame = SCORE_KECLEON_SCOPE_COLLECTED;
                m4aSongNumStart(SE_KECLEON_SCOPE_ACTIVATED);
            }

            group->baseX = -gCurrentPinballGame->cameraXOffset + gCurrentPinballGame->orbCollisionPosition.x / 10;
            group->baseY = -gCurrentPinballGame->cameraYOffset + gCurrentPinballGame->orbCollisionPosition.y / 10;
        }
        else
        {
            group->baseX = 0;
            group->baseY = 180;
        }
    }
    else
    {
        group->baseX = 0;
        group->baseY = 180;
    }

    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
}


void UpdateKecleonScopeVision(void)
{
    s16 i, j;
    s16 var0;
    s16 var1;
    s16 var2;
    s16 index;
    s16 var3;
    const u16 *ptr;

    if (gCurrentPinballGame->kecleonTargetActive)
    {
        if (gCurrentPinballGame->kecleonAnimTimer < 600)
        {
            gCurrentPinballGame->kecleonAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->kecleonAnimTimer = 0;
            gCurrentPinballGame->kecleonTargetActive = FALSE;
        }
    }

    if (gCurrentPinballGame->kecleonTargetActive)
    {
        if (gCurrentPinballGame->kecleonFrameTimer < 10)
            gCurrentPinballGame->kecleonFrameTimer++;
    }
    else
    {
        if (gCurrentPinballGame->kecleonFrameTimer)
            gCurrentPinballGame->kecleonFrameTimer--;
        else
            gCurrentPinballGame->kecleonTargetFrameIndex = 0;
    }

    gMain.kecleonOverlayHeight = gCurrentPinballGame->kecleonFrameTimer * 16;
    var0 = gCurrentPinballGame->kecleonFrameTimer * 64;
    var1 = (20 - gCurrentPinballGame->kecleonFrameTimer * 2) * 32;
    index = (gCurrentPinballGame->kecleonAnimTimer % 36) / 9;
    var3 = gKecleonOverlayTileAnimIndices[index];
    ptr = gKecleonOverlayTilemapPointers[index];
    for (j = 0; j < var0; j++)
        gBG0TilemapBuffer[0x400 + j] = ptr[var1 + j];
    for (j = var0; j < 0x280; j++)
        gBG0TilemapBuffer[0x400 + j] = 0x3FF;

    index = gCurrentPinballGame->kecleonAnimTimer % 150;
    if (index >= 10 && index < 80)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 4; j++)
            {
                gBG0TilemapBuffer[0x408 + ((i + 6) * 0x20) + j] = gKecleonBerryOverlayTilemap[((i + 21) * 0x20) + (j + var3 * 4)];
            }
        }

        var2 = index / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gBG0TilemapBuffer[0x4C3 + j] = gKecleonBerryOverlayTilemap[0x2EC + j];
        }
    }

    if (index >= 80 && index < 150)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 6; j++)
            {
                gBG0TilemapBuffer[0x411 + ((i + 14) * 0x20) + j] = gKecleonBerryOverlayTilemap[((i + 21) * 0x20) + (j + 0xC + var3 * 6)];
            }
        }

        var2 = (index - 70) / 10;
        if (var2 > 5)
            var2 = 5;

        for (j = 0; j < var2; j++)
        {
            gBG0TilemapBuffer[0x5F7 + j] = gKecleonBerryOverlayTilemap[0x2EC + j];
        }
    }

    DmaCopy16(3, &gBG0TilemapBuffer[0x400], (void *)0x06001000, 0x500);
}

void RenderKecleonBoardElements(void)
{
    s16 i, j;
    struct SpriteGroup *group;
    struct OamDataSimple *oamSimple;
    struct OamData *oamData;
    struct Vector16 tempVector;
    s16 var0;
    s16 var1;
    s16 var2;

    tempVector.x = gCurrentPinballGame->kecleonCollisionPos.x * 2;
    tempVector.y = gCurrentPinballGame->kecleonCollisionPos.y * 2;
    ProcessKecleonSkulkingDisturbanceCollisionEvent(&tempVector);

    group = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[16]];
    group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
    group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
    for (j = 0; j < 4; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    group = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[17]];
    group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
    group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[SG_KECLEON_TREE_LEAVES];
    var0 = 5 - gCurrentPinballGame->kecleonCollisionY % 10;
    if (gCurrentPinballGame->kecleonCollisionY > 30)
        var1 = 20;
    else if (gCurrentPinballGame->kecleonCollisionY > 10)
        var1 = 10;
    else
        var1 = 5;

    if (gCurrentPinballGame->kecleonCollisionY == 40)
    {
        m4aSongNumStart(SE_KECLEON_TREE_HIT);
        PlayRumble(7);
    }

    if (var0 < 0)
        var0 = -var0;

    group->baseX = (var1 * (5 - var0)) / 10 + 120u - gCurrentPinballGame->cameraXOffset;
    group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
    for  (j = 0; j < 5; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
    }

    if (gCurrentPinballGame->kecleonCollisionY)
        gCurrentPinballGame->kecleonCollisionY--;

    for (i = 0; i < 6; i++)
    {
        group = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[10 + i]];
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
        var2 = 0;
        if (gCurrentPinballGame->kecleonBushMotionTimer[i])
        {
            var2 = gKecleonPlantAnimIndices[(gCurrentPinballGame->kecleonBushMotionTimer[i] % 24) / 6];
            gCurrentPinballGame->kecleonBushMotionTimer[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    for (i = 6; i < 10; i++)
    {
        group = &gMain.spriteGroups[gKecleonSpriteGroupOrderMap[12 + i]];
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
        var2 = 0;
        if (gCurrentPinballGame->kecleonBushMotionTimer[i])
        {
            var2 = gKecleonPlantAnimIndices[(gCurrentPinballGame->kecleonBushMotionTimer[i] % 24) / 6];
            gCurrentPinballGame->kecleonBushMotionTimer[i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0xD2 + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[SG_KECLEON_FLOWER_BY_TREE];
    group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
    group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
    var2 = 0;
    if (gCurrentPinballGame->kecleonFlowerMotionTimer[0])
    {
        var2 = gKecleonPlantAnimIndices[(gCurrentPinballGame->kecleonFlowerMotionTimer[0] % 24) / 6];
        gCurrentPinballGame->kecleonFlowerMotionTimer[0]--;
    }

    for (j = 0; j < 3; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0xF6 + var2 * 8 + (j * 4 - (j / 2) * 2);
    }

    for (i = 0; i < 2; i++)
    {
        group = &gMain.spriteGroups[SG_KECLEON_FLOWER_PAIR_LEFT + i];
        group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
        group->baseY = -gCurrentPinballGame->cameraYOffset - 128;

        var2 = 0;
        if (gCurrentPinballGame->kecleonFlowerMotionTimer[1 + i])
        {
            var2 = gKecleonPlantAnimIndices[(gCurrentPinballGame->kecleonFlowerMotionTimer[1 + i] % 24) / 6];
            gCurrentPinballGame->kecleonFlowerMotionTimer[1 + i]--;
        }

        for (j = 0; j < 2; j++)
        {
            oamSimple = &group->oam[j];
            gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
            gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
            gOamBuffer[oamSimple->oamId].tileNum = 0x10E + var2 * 12 + j * 8;
        }
    }

    group = &gMain.spriteGroups[SG_KECLEON_FLOWER_TRIPLE_RIGHT];
    group->baseX = 120 - gCurrentPinballGame->cameraXOffset;
    group->baseY = -gCurrentPinballGame->cameraYOffset - 128;
    var2 = 0;
    if (gCurrentPinballGame->kecleonFlowerMotionTimer[3])
    {
        var2 = gKecleonPlantAnimIndices[(gCurrentPinballGame->kecleonFlowerMotionTimer[3] % 24) / 6];
        gCurrentPinballGame->kecleonFlowerMotionTimer[3]--;
    }

    for (j = 0; j < 2; j++)
    {
        oamSimple = &group->oam[j];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x132 + var2 * 12 + j * 8;
    }

    group = &gMain.spriteGroups[SG_KECLEON_REFLECTION_BALL];
    group->baseX = gCurrentPinballGame->ball->screenPosition.x;
    group->baseY = gCurrentPinballGame->ball->screenPosition.y + 14;
    oamSimple = &group->oam[0];
    gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
    if (gCurrentPinballGame->ball->ballHidden)
        gOamBuffer[oamSimple->oamId].y = 200;
    else
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;

    group = &gMain.spriteGroups[SG_KECLEON_BALL_RIPPLE_FX];
    if (gCurrentPinballGame->kecleonWaterBallCollisionTimer < 12)
        gCurrentPinballGame->kecleonWaterBallCollisionTimer++;
    else
        gCurrentPinballGame->kecleonWaterBallCollisionTimer = 0;

    for (i = 0; i < 4; i++)
    {
        if (gCurrentPinballGame->kecleonWaterMotionTimer[i])
        {
            var2 = 2 - gCurrentPinballGame->kecleonWaterMotionTimer[i] / 4;
            gCurrentPinballGame->kecleonWaterMotionTimer[i]--;
            group->baseX = gCurrentPinballGame->ballTrailPosition[i].x - gCurrentPinballGame->cameraBaseX + 4;
            group->baseY = gCurrentPinballGame->ballTrailPosition[i].y - gCurrentPinballGame->cameraBaseY- gCurrentPinballGame->cameraScrollOffset - gCurrentPinballGame->cameraYAdjust + 4;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }

    group = &gMain.spriteGroups[SG_KECLEON_STEP_RIPPLE_FX];
    if (gCurrentPinballGame->kecleonWaterCollisionTimer < 24)
        gCurrentPinballGame->kecleonWaterCollisionTimer++;
    else
        gCurrentPinballGame->kecleonWaterCollisionTimer = 0;

    for (i = 0; i < 3; i++)
    {
        if (gCurrentPinballGame->kecleonWaterMotionTimer[4 + i])
        {
            var2 = 2 - gCurrentPinballGame->kecleonWaterMotionTimer[4 + i] / 6;
            gCurrentPinballGame->kecleonWaterMotionTimer[4 + i]--;
            group->baseX = gCurrentPinballGame->kecleonWaterTileCollisionPosition[i].x - gCurrentPinballGame->cameraXOffset - 4;
            group->baseY = gCurrentPinballGame->kecleonWaterTileCollisionPosition[i].y - gCurrentPinballGame->cameraYOffset + 2;
        }
        else
        {
            group->baseX = 240;
            group->baseY = 180;
        }

        oamSimple = &group->oam[i];
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + group->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + group->baseY;
        gOamBuffer[oamSimple->oamId].tileNum = 0x16E + var2;
    }
}

void SortKecleonSpritesByY(void)
{
    s16 i, j;
    struct KecleonSpriteSortEntry sp0[14];

    for (i = 0; i < 33; i++)
        gKecleonSpriteSets[i] = gKecleonBoardSpriteSets[i];

    sp0[12] = gKecleonSpriteYSortData[12];
    sp0[12].ySortKey = gCurrentPinballGame->ball->positionQ0.y;
    for (i = 0; i < 12; i++)
    {
        if (gKecleonSpriteYSortData[i].ySortKey < gCurrentPinballGame->ball->positionQ0.y)
        {
            for (j = 11; j >= i; j--)
                sp0[j + 1] = gKecleonSpriteYSortData[j];

            sp0[i] = gKecleonSpriteYSortData[12];
            sp0[i].ySortKey = gCurrentPinballGame->ball->positionQ0.y;
            break;
        }
        else
        {
            sp0[i] = gKecleonSpriteYSortData[i];
        }
    }

    sp0[13] = gKecleonSpriteYSortData[13];
    for (i = 0; i < 13; i++)
    {
        if (sp0[i].ySortKey < gCurrentPinballGame->kecleonCollisionPos.y)
        {
            for (j = 12; j >= i; j--)
                sp0[j + 1] = sp0[j];

            sp0[i] = gKecleonSpriteYSortData[13];
            sp0[i].ySortKey = gCurrentPinballGame->kecleonCollisionPos.y;
            break;
        }
    }

    for (i = 0; i < 14; i++)
    {
        gKecleonSpriteGroupOrderMap[10 + sp0[i].spriteIndex] = SG_KECLEON_DRAW_ORDER_SPRITES_BASE + i;
        gKecleonSpriteSets[i + 10] = sp0[i].spriteSet;
    }

    LoadSpriteSets(gKecleonSpriteSets, 33, gMain.spriteGroups);
}
