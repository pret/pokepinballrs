#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/dusclops_states.h"

#define BONUS_DUSKULL_TIME 7200 //2 minutes, 60FPS
#define BONUS_DUSKULL_COMPLETE_POINTS 30000000

#define DUSKULL_NEEDED_TO_PHASE_TRANSFER 20
#define DUSKULL_CONCURRENT_MAX 3
#define DUSKULL_ALLOWED_TO_SPAWN DUSKULL_NEEDED_TO_PHASE_TRANSFER - DUSKULL_CONCURRENT_MAX + 1
#define DUSCLOPS_HITS_NEEDED_TO_SUCCEED 5

extern struct SongHeader se_duskull_appear;
extern s16 DuskullFramesetData[][3];



void DuskullBonus_Setup(void)
{
    s16 i;
    gCurrentPinballGame->stageTimer = 0;
    gCurrentPinballGame->boardSubState = 0;
    gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_0_INTRO;
    gCurrentPinballGame->boardModeType = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_DUSKULL_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->ballGrabbed = 0;
    gCurrentPinballGame->ballRespawnState = 3;
    gCurrentPinballGame->ball->ballHidden = 1;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
    gCurrentPinballGame->ballRespawnTimer = 0;
    gCurrentPinballGame->bannerSlideYOffset = 0;
    gCurrentPinballGame->minionActiveCount = 0;

    for (i = 0; i < DUSKULL_CONCURRENT_MAX; i++)
    {
        gCurrentPinballGame->minionSpriteVariant[i] = 0;
        gCurrentPinballGame->minionNextSpriteVariant[i] = 0;
        gCurrentPinballGame->minionOamIx[i] = 0;
        gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_SPAWN;
        gCurrentPinballGame->minionFramesetIx[i] = 0;
        gCurrentPinballGame->minionDrawInFrame[i] = FALSE;
        gCurrentPinballGame->minionCanCollide[i] = FALSE;
        gCurrentPinballGame->minionDeathTimer[i] = 0;
        gCurrentPinballGame->minionStateTimer[i] = 0;
        gCurrentPinballGame->minionTimeAlive[i] = 0;
        gCurrentPinballGame->minionEscapeAtTime[i] = 0;
        gCurrentPinballGame->minionLogicPosition[i].x = 0;
        gCurrentPinballGame->minionLogicPosition[i].y = 0;
        gCurrentPinballGame->minionCollisionPosition[i].x = 0;
        gCurrentPinballGame->minionCollisionPosition[i].y = 0;
    }

    gCurrentPinballGame->bossEntityState = 0;
    gCurrentPinballGame->kecleonFramesetBase = 0;
    gCurrentPinballGame->bossVulnerable = 0;
    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
    gCurrentPinballGame->bossFramesetIndex = 0;
    gCurrentPinballGame->bossFrameTimer = 0;
    gCurrentPinballGame->bossAnimLoopCount = 0;
    gCurrentPinballGame->bossPositionX = 0;
    gCurrentPinballGame->bossPositionY = 0;
    gCurrentPinballGame->bossVelocityX = 0;
    gCurrentPinballGame->bossVelocityY = 0;
    gCurrentPinballGame->bossCollisionX = 0;
    gCurrentPinballGame->bossCollisionY = 0;
    gCurrentPinballGame->flippersDisabled = 0;

    DuskullPhase_ProcessEntityLogic();
    DuskullPhase_ProcessGraphics();

    m4aSongNumStart(MUS_BONUS_FIELD_DUSKULL);

    DmaCopy16(3, (void *)gBonusStageObjPal, (void *)0x05000320, 32);
}

void DusclopsBoardProcess_3B_33130(void)
{
    s16 temp;
    switch (gCurrentPinballGame->boardState)
    {
        case DUSCLOPS_BOARD_STATE_0_INTRO:
            gCurrentPinballGame->ballUpgradeTimerFrozen = 1;
            if (gCurrentPinballGame->stageTimer < 120)
            {
                temp = gCurrentPinballGame->stageTimer / 24;
                DmaCopy16(3, gDusclopsAnimPalettes + temp * 40, 0x05000000, 160);

                gCurrentPinballGame->cameraYAdjust = gCurrentPinballGame->stageTimer / 5 + 0xFFE8;
                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->cameraYAdjust = 0;
                gMain.spriteGroups[7].available = TRUE;
                gMain.spriteGroups[8].available = TRUE;
                gMain.spriteGroups[9].available = TRUE;
                gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_1_DUSKULL_PHASE;
                gCurrentPinballGame->stageTimer = 0;
            }

            break;
        case DUSCLOPS_BOARD_STATE_1_DUSKULL_PHASE:
            if (!gCurrentPinballGame->returnToMainBoardFlag)
            {
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = 0x30D;
            }
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSKULL;
            DuskullPhase_ProcessEntityLogic();
            DuskullPhase_ProcessGraphics();
            break;
        case DUSCLOPS_BOARD_STATE_2_INIT_DUSCLOPS_PHASE:
            gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_3_DUSCLOPS_PHASE;
            gMain.spriteGroups[13].available = TRUE;
            gMain.spriteGroups[14].available = TRUE;
            gMain.spriteGroups[12].available = TRUE;
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
            gCurrentPinballGame->bonusModeHitCount = 0;
            m4aSongNumStart(MUS_BONUS_FIELD_DUSCLOPS);
            break;
        case DUSCLOPS_BOARD_STATE_3_DUSCLOPS_PHASE:
            if (!gCurrentPinballGame->returnToMainBoardFlag)
            {
                gMain.blendControl = 0x1C10;
                gMain.blendAlpha = 0x1000;
            }
            DusclopsPhase_ProcessEntityLogicAndGraphics();
            break;
        case DUSCLOPS_BOARD_STATE_4_INIT_SCORE_PHASE:
            if (gCurrentPinballGame->stageTimer < 120)
            {
                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_SCORE_PHASE;
                gCurrentPinballGame->stageTimer = 0;
                gMain.spriteGroups[6].available = TRUE;
                gMain.spriteGroups[5].available = TRUE;
                DmaCopy16(3, gDusclopsBonusClear_Gfx, OBJ_VRAM1+0x1800, 8192);
                gCurrentPinballGame->bannerSlideYOffset = 136;
            }
            break;
        case DUSCLOPS_BOARD_STATE_SCORE_PHASE:
            ProcessBonusBannerAndScoring();
            if (gCurrentPinballGame->scoreCounterAnimationEnabled)
            {
                gCurrentPinballGame->stageTimer = 181;
            }
            if (gCurrentPinballGame->stageTimer == 180)
            {
                gCurrentPinballGame->scoreCounterAnimationEnabled = TRUE;
                gCurrentPinballGame->scoreAddStepSize = 400000;
                gCurrentPinballGame->scoreAddedInFrame = BONUS_DUSKULL_COMPLETE_POINTS;
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
                gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_SCORE_COUNTING_FINISHED;
                gCurrentPinballGame->numCompletedBonusStages++;
            }

            break;
        case DUSCLOPS_BOARD_STATE_SCORE_COUNTING_FINISHED:
            ProcessBonusBannerAndScoring();
            gCurrentPinballGame->returnToMainBoardFlag = 1;
            break;
    }

    if (gCurrentPinballGame->boardModeType)
    {
        if (gCurrentPinballGame->eventTimer < 2)
        {
            if (!gMain.modeChangeFlags)
            {
                m4aMPlayAllStop();
                m4aSongNumStart(MUS_END_OF_BALL3);
                gMain.modeChangeFlags |= MODE_CHANGE_EXPIRED_BONUS;
            }
        }
    }

    if (gCurrentPinballGame->returnToMainBoardFlag)
        FadeToMainBoard();

    BonusStage_HandleModeChangeFlags();
}

void SwapDuskullEntityIndex(s16 index1, s16 index2)
{
    u8 tempSpriteVariant, tempNextSpriteVariant, tempOamIx, tempState, tempFramesetIx, tempDrawInFrame, tempCanCollide, tempDeathTimer;
    u16 tempStateTimer, tempTimeAlive, tempEscapeAtTime;
    struct Vector16 tempLogicPosition, tempCollisionPosition;

    tempSpriteVariant = gCurrentPinballGame->minionSpriteVariant[index1];
    tempNextSpriteVariant = gCurrentPinballGame->minionNextSpriteVariant[index1];
    tempOamIx = gCurrentPinballGame->minionOamIx[index1];
    tempState = gCurrentPinballGame->minionState[index1];
    tempFramesetIx = gCurrentPinballGame->minionFramesetIx[index1];
    tempDrawInFrame = gCurrentPinballGame->minionDrawInFrame[index1];
    tempCanCollide = gCurrentPinballGame->minionCanCollide[index1];
    tempDeathTimer = gCurrentPinballGame->minionDeathTimer[index1];
    tempStateTimer = gCurrentPinballGame->minionStateTimer[index1];
    tempTimeAlive = gCurrentPinballGame->minionTimeAlive[index1];
    tempEscapeAtTime = gCurrentPinballGame->minionEscapeAtTime[index1];
    tempLogicPosition.x = gCurrentPinballGame->minionLogicPosition[index1].x;
    tempLogicPosition.y = gCurrentPinballGame->minionLogicPosition[index1].y;
    tempCollisionPosition.x = gCurrentPinballGame->minionCollisionPosition[index1].x;
    tempCollisionPosition.y = gCurrentPinballGame->minionCollisionPosition[index1].y;

    gCurrentPinballGame->minionSpriteVariant[index1] = gCurrentPinballGame->minionSpriteVariant[index2];
    gCurrentPinballGame->minionNextSpriteVariant[index1] = gCurrentPinballGame->minionNextSpriteVariant[index2];
    gCurrentPinballGame->minionOamIx[index1] = gCurrentPinballGame->minionOamIx[index2];
    gCurrentPinballGame->minionState[index1] = gCurrentPinballGame->minionState[index2];
    gCurrentPinballGame->minionFramesetIx[index1] = gCurrentPinballGame->minionFramesetIx[index2];
    gCurrentPinballGame->minionDrawInFrame[index1] = gCurrentPinballGame->minionDrawInFrame[index2];
    gCurrentPinballGame->minionCanCollide[index1] = gCurrentPinballGame->minionCanCollide[index2];
    gCurrentPinballGame->minionDeathTimer[index1] = gCurrentPinballGame->minionDeathTimer[index2];
    gCurrentPinballGame->minionStateTimer[index1] = gCurrentPinballGame->minionStateTimer[index2];
    gCurrentPinballGame->minionTimeAlive[index1] = gCurrentPinballGame->minionTimeAlive[index2];
    gCurrentPinballGame->minionEscapeAtTime[index1] = gCurrentPinballGame->minionEscapeAtTime[index2];
    gCurrentPinballGame->minionLogicPosition[index1].x = gCurrentPinballGame->minionLogicPosition[index2].x;
    gCurrentPinballGame->minionLogicPosition[index1].y = gCurrentPinballGame->minionLogicPosition[index2].y;
    gCurrentPinballGame->minionCollisionPosition[index1].x = gCurrentPinballGame->minionCollisionPosition[index2].x;
    gCurrentPinballGame->minionCollisionPosition[index1].y = gCurrentPinballGame->minionCollisionPosition[index2].y;

    gCurrentPinballGame->minionSpriteVariant[index2] = tempSpriteVariant;
    gCurrentPinballGame->minionNextSpriteVariant[index2] = tempNextSpriteVariant;
    gCurrentPinballGame->minionOamIx[index2] = tempOamIx;
    gCurrentPinballGame->minionState[index2] = tempState;
    gCurrentPinballGame->minionFramesetIx[index2] = tempFramesetIx;
    gCurrentPinballGame->minionDrawInFrame[index2] = tempDrawInFrame;
    gCurrentPinballGame->minionCanCollide[index2] = tempCanCollide;
    gCurrentPinballGame->minionDeathTimer[index2] = tempDeathTimer;
    gCurrentPinballGame->minionStateTimer[index2] = tempStateTimer;
    gCurrentPinballGame->minionTimeAlive[index2] = tempTimeAlive;
    gCurrentPinballGame->minionEscapeAtTime[index2] = tempEscapeAtTime;
    gCurrentPinballGame->minionLogicPosition[index2].x = tempLogicPosition.x;
    gCurrentPinballGame->minionLogicPosition[index2].y = tempLogicPosition.y;
    gCurrentPinballGame->minionCollisionPosition[index2].x = tempCollisionPosition.x;
    gCurrentPinballGame->minionCollisionPosition[index2].y = tempCollisionPosition.y;
}

void DuskullPhase_ProcessEntityLogic(void) {
    s16 i, j;
    bool32 r4 = TRUE;
    u16 oamIx = 0;
    u16 tileOffset = 0;

    // If target number of Duskulls spawned, check to see if all are removed before moving to next state
    if (gCurrentPinballGame->bonusModeHitCount > DUSKULL_ALLOWED_TO_SPAWN)
    {
        for (i = 0; i < DUSKULL_CONCURRENT_MAX; i++)
        {
            if (gCurrentPinballGame->minionDrawInFrame[i])
                r4 = FALSE;
        }
        if (r4)
        {
            gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_2_INIT_DUSCLOPS_PHASE;
            gMain.spriteGroups[7].available = FALSE;
            gMain.spriteGroups[8].available = FALSE;
            gMain.spriteGroups[9].available = FALSE;
        }
    }

    for (i = 0; i < DUSKULL_CONCURRENT_MAX; i++)
    {
        switch(gCurrentPinballGame->minionState[i])
        {
        case DUSKULL_ENTITY_STATE_SPAWN:
            if (gCurrentPinballGame->bonusModeHitCount <= DUSKULL_ALLOWED_TO_SPAWN && 
                gCurrentPinballGame->minionActiveCount < 2)
            {
                gCurrentPinballGame->minionActiveCount++;
                gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_APPEARS; 
                gCurrentPinballGame->minionFramesetIx[i] = 0;
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionLogicPosition[i].x = (Random() % 1400) - 700;
                gCurrentPinballGame->minionLogicPosition[i].y = (Random() % 9) * 80;
                gCurrentPinballGame->minionEscapeAtTime[i] = (Random() % 1000) + 200;
                gCurrentPinballGame->minionDrawInFrame[i] = FALSE;
                gCurrentPinballGame->minionCanCollide[i] = FALSE;
                oamIx = 4;
                tileOffset = DUSKULL_TILE_OFFSET_FACE_FORWARD; // Facing forward picture
                gCurrentPinballGame->minionTimeAlive[i] = 0;
                MPlayStart(&gMPlayInfo_SE1, &se_duskull_appear);

                //Check/swap Y index ordering, for proper sprite draw layering
                for (j = DUSKULL_CONCURRENT_MAX - 1; j > 0; j--)
                {
                    if (gCurrentPinballGame->minionLogicPosition[j].y > gCurrentPinballGame->minionLogicPosition[j-1].y)
                    {
                        SwapDuskullEntityIndex(j, j - 1);
                        j = DUSKULL_CONCURRENT_MAX;
                    }
                }
            }
            else
            {
                gCurrentPinballGame->minionLogicPosition[i].x = 0;
                gCurrentPinballGame->minionLogicPosition[i].y = 120;
                gCurrentPinballGame->minionDrawInFrame[i] = FALSE;
                Random();
            }
            break;
        case DUSKULL_ENTITY_STATE_APPEARS: //Spawn in, Wait and initial movement decision
            if (gCurrentPinballGame->minionStateTimer[i] < 20)
            {
                gCurrentPinballGame->minionStateTimer[i]++;
                // Minion 'Blinking' by alternating whether drawn in frame, or off screen
                gCurrentPinballGame->minionDrawInFrame[i] = (gCurrentPinballGame->minionStateTimer[i] % 4) / 2;
                oamIx = 4;
                tileOffset = DUSKULL_TILE_OFFSET_FACE_FORWARD;
                break;
            }
            else
            {
                if (gMain.systemFrameCount % 2)
                {
                    gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_MOVE_LEFT;
                    gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_LEFT_START;
                }
                else
                {
                    gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_MOVE_RIGHT;
                    gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_RIGHT_START;
                }

                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionDrawInFrame[i] = TRUE;
                gCurrentPinballGame->minionCanCollide[i] = TRUE;
                oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
                tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            }
            break;
        case DUSKULL_ENTITY_STATE_MOVE_LEFT:
            gCurrentPinballGame->minionTimeAlive[i]++;
            if (gCurrentPinballGame->minionLogicPosition[i].x > -800)
            {
                gCurrentPinballGame->minionLogicPosition[i].x -= 3; //Move left
                if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                {
                    gCurrentPinballGame->minionStateTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->minionStateTimer[i] = 0;
                    gCurrentPinballGame->minionFramesetIx[i]++;

                    //Animation frame reset
                    if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_MOVE_LEFT_END)
                        gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_LEFT_START;
                }
            }
            else
            {
                if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                {
                    gCurrentPinballGame->minionStateTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->minionStateTimer[i] = 0;
                    gCurrentPinballGame->minionFramesetIx[i]++;

                    //Animation frame at neutral forward, continue with move right
                    if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_NEUTRAL_FACING)
                    {
                        gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_RIGHT_START;
                        gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_MOVE_RIGHT;
                    }
                }
            }
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            break;
        case DUSKULL_ENTITY_STATE_MOVE_RIGHT:
            gCurrentPinballGame->minionTimeAlive[i]++;
            if (gCurrentPinballGame->minionLogicPosition[i].x < 800)
            {
                gCurrentPinballGame->minionLogicPosition[i].x += 3; //Move right
                gCurrentPinballGame->minionLogicPosition[i].y += 0; // ! Dead code needed for matching
                if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                {
                    gCurrentPinballGame->minionStateTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->minionStateTimer[i] = 0;
                    gCurrentPinballGame->minionFramesetIx[i]++;
                    if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_MOVE_RIGHT_END)
                        gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_RIGHT_START;
                }
            }
            else
            {
                if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
                {
                    gCurrentPinballGame->minionStateTimer[i]++;
                }
                else
                {
                    gCurrentPinballGame->minionStateTimer[i] = 0;
                    gCurrentPinballGame->minionFramesetIx[i]++;
                    if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_TURN_TO_FACE_LEFT_END)
                    {
                        gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_MOVE_LEFT_START;
                        gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_MOVE_LEFT;
                    }
                }
            }
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            break;
        case DUSKULL_ENTITY_STATE_HIT:
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_HIT;
            gCurrentPinballGame->minionStateTimer[i] = 0;
            gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_DYING;
            gCurrentPinballGame->minionDeathTimer[i] = 0;
            gCurrentPinballGame->minionCanCollide[i] = FALSE;

            if (gCurrentPinballGame->minionActiveCount > 0)
                gCurrentPinballGame->minionActiveCount--; //Number of active duskull
            gCurrentPinballGame->scoreAddedInFrame = 100000;
            gCurrentPinballGame->bonusModeHitCount++; // Number hit
            m4aSongNumStart(SE_DUSKULL_DEATH_CRY); //Duskull Death cry
            PlayRumble(7);
            break;
        case DUSKULL_ENTITY_STATE_DYING:
            if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
            {
                gCurrentPinballGame->minionStateTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i]++;
                if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_DYING)
                {
                    gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_DYING;
                    gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_CLEANUP;
                    gCurrentPinballGame->minionDrawInFrame[i] = FALSE;
                }
            }
            if (gCurrentPinballGame->minionFramesetIx[i] == DUSKULL_FRAME_DYING)
                gCurrentPinballGame->minionDeathTimer[i]++;
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            break;
        case DUSKULL_ENTITY_STATE_ESCAPE_WHILE_WALKING_LEFT:
            if (gCurrentPinballGame->minionStateTimer[i] < 6)
            {
                gCurrentPinballGame->minionStateTimer[i]++;
                oamIx = 3;
                tileOffset = DUSKULL_TILE_OFFSET_QUARTER_FACING;
            }
            else
            {
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_ESCAPE_PREP;
                gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_ESCAPE;
                gCurrentPinballGame->minionCanCollide[i] = FALSE;
                if (gCurrentPinballGame->minionActiveCount > 0)
                    gCurrentPinballGame->minionActiveCount--;
                oamIx = 3;
                tileOffset = DUSKULL_TILE_OFFSET_QUARTER_FACING;
                m4aSongNumStart(SE_DUSCLOPS_DEPART_INCOMPLETE);
            }
            break;
        case DUSKULL_ENTITY_STATE_ESCAPE_WHILE_WALKING_RIGHT:
            if (gCurrentPinballGame->minionStateTimer[i] < 6)
            {
                gCurrentPinballGame->minionStateTimer[i]++;
                oamIx = 9;
                tileOffset = DUSKULL_TILE_OFFSET_QUARTER_FACING;
            }
            else
            {
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_ESCAPE_PREP;
                gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_ESCAPE;
                gCurrentPinballGame->minionCanCollide[i] = FALSE;
                if (gCurrentPinballGame->minionActiveCount > 0)
                    gCurrentPinballGame->minionActiveCount--;
                m4aSongNumStart(SE_DUSCLOPS_DEPART_INCOMPLETE);
                oamIx = 9;
                tileOffset = DUSKULL_TILE_OFFSET_QUARTER_FACING;
            }
            break;
        case DUSKULL_ENTITY_STATE_ESCAPE:
            if (DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][1] > gCurrentPinballGame->minionStateTimer[i])
            {
                gCurrentPinballGame->minionStateTimer[i]++;
            }
            else
            {
                gCurrentPinballGame->minionStateTimer[i] = 0;
                gCurrentPinballGame->minionFramesetIx[i]++;
                if (gCurrentPinballGame->minionFramesetIx[i] > DUSKULL_FRAME_ESCAPE)
                {
                    gCurrentPinballGame->minionFramesetIx[i] = DUSKULL_FRAME_ESCAPE;
                    gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_CLEANUP;
                }
            }
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            break;
        case DUSKULL_ENTITY_STATE_CLEANUP:
            gCurrentPinballGame->minionDrawInFrame[i] = FALSE;
            gCurrentPinballGame->minionCanCollide[i] = FALSE;
            gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_SPAWN;
            oamIx = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][0];
            tileOffset = DuskullFramesetData[gCurrentPinballGame->minionFramesetIx[i]][2];
            break;
        }

        // Time alive > time before escape, && Not in the last set before moving to the next mode.
        if (gCurrentPinballGame->minionTimeAlive[i] > gCurrentPinballGame->minionEscapeAtTime[i] &&
            gCurrentPinballGame->bonusModeHitCount <= DUSKULL_ALLOWED_TO_SPAWN)
        {
            gCurrentPinballGame->minionTimeAlive[i] = 0;
            if (gCurrentPinballGame->minionState[i] == DUSKULL_ENTITY_STATE_MOVE_LEFT)
                gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_ESCAPE_WHILE_WALKING_LEFT;
            else
                gCurrentPinballGame->minionState[i] = DUSKULL_ENTITY_STATE_ESCAPE_WHILE_WALKING_RIGHT;

            gCurrentPinballGame->minionStateTimer[i] = 0;
        }

        gCurrentPinballGame->minionSpriteVariant[i] = gCurrentPinballGame->minionNextSpriteVariant[i];
        gCurrentPinballGame->minionNextSpriteVariant[i] = tileOffset;
        gCurrentPinballGame->minionOamIx[i] = oamIx;
        gCurrentPinballGame->minionCollisionPosition[i].x = (gCurrentPinballGame->minionLogicPosition[i].x / 10) * 2 + 208;
        gCurrentPinballGame->minionCollisionPosition[i].y = (gCurrentPinballGame->minionLogicPosition[i].y / 10) * 2 + 66;
    }
}

extern const u8 gDusclopsBoardDuskull_Gfx[];
extern const u16 gDuskullSpritesheetOam[][2][3];
void DuskullPhase_ProcessGraphics() {
    s16 i, animPiece;
    s16 oamIx;
    struct SpriteGroup *spriteGroup;
    struct OamDataSimple * oamData;
    u16 * dst;
    const u16 * src;

    for (i = 0; i < DUSKULL_CONCURRENT_MAX; i++)
    {
        s16 spriteVariant = gCurrentPinballGame->minionSpriteVariant[i];
        DmaCopy16(3, gDusclopsBoardDuskull_Gfx + spriteVariant * 0x280, OBJ_VRAM0 + 0x920 + i * 0x280, 0x280);
        oamIx = gCurrentPinballGame->minionOamIx[i];
        spriteGroup = &gMain_spriteGroups[7 + i];

        if (gCurrentPinballGame->minionDrawInFrame[i]) {
            s32 x = 0; // Scrub C to get the compiler to add before subtracting
            spriteGroup->baseX = gCurrentPinballGame->minionLogicPosition[i].x / 10 + 108 + x - gCurrentPinballGame->cameraXOffset;
            spriteGroup->baseY = gCurrentPinballGame->minionLogicPosition[i].y / 10 + 28 + x - gCurrentPinballGame->cameraYOffset;
        } else {
            // Draw off screen, past lower right bounds of screen
            spriteGroup->baseX = 240;
            spriteGroup->baseY = 180;
        }

        if (spriteVariant == 6)
        {
            u16 scaleX;
            u16 scaleY;
            if (gCurrentPinballGame->minionDeathTimer[i] <= 6) {
                scaleX = (gCurrentPinballGame->minionDeathTimer[i] * 0x80) / 6 + 0x100;
                scaleY = ((6-gCurrentPinballGame->minionDeathTimer[i]) * 0x80) / 6 + 0x80;
            } else {
                scaleX = ((24-gCurrentPinballGame->minionDeathTimer[i]) * 0x170) / 18 + 0x10;
                scaleY = ((gCurrentPinballGame->minionDeathTimer[i]-6) * 0x1C0) / 18 + 0x80;
            }
            SetMatrixScale(scaleX, scaleY, i + 2);
            spriteGroup->baseX -= 16;
            spriteGroup->baseY -= 16;

            for (animPiece = 0; animPiece < 2; animPiece++)
            {
                oamData = &spriteGroup->oam[animPiece];

                dst = (u16*)&gOamBuffer[oamData->oamId];
                src = gDuskullSpritesheetOam[oamIx][animPiece];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamData->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamData->oamId].y += spriteGroup->baseY;
                gOamBuffer[oamData->oamId].tileNum += i * 20;
                gOamBuffer[oamData->oamId].affineMode = ST_OAM_AFFINE_DOUBLE;
                gOamBuffer[oamData->oamId].matrixNum = i + 2;
            }
        }
        else
        {
            for (animPiece = 0; animPiece < 2; animPiece++)
            {
                oamData = &spriteGroup->oam[animPiece];
                dst = (u16*)&gOamBuffer[oamData->oamId];
                src = gDuskullSpritesheetOam[oamIx][animPiece];
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;

                gOamBuffer[oamData->oamId].x += spriteGroup->baseX;
                gOamBuffer[oamData->oamId].y += spriteGroup->baseY;
                gOamBuffer[oamData->oamId].tileNum += i * 20;
            }
        }
    }
}

void DusclopsPhase_ProcessEntityLogicAndGraphics(void)
{
    s16 tileOffset;
    u16 available;
    struct OamDataSimple *oamSimple;
    struct SpriteGroup *spriteGroup;

    tileOffset = 0;
    spriteGroup = &gMain.spriteGroups[14];
    switch(gCurrentPinballGame->bossEntityState)
    {
    case DUSCLOPS_ENTITY_STATE_INIT:
    {
        gCurrentPinballGame->bossPositionX = 880;
        gCurrentPinballGame->bossPositionY = 300;
        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_INTRO_APPEARANCE;
        gCurrentPinballGame->bossAnimLoopCount = 184;
        gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_INTRO_START;
        tileOffset = 0;
        gCurrentPinballGame->boardModeType = 1;
        break;
    }

    case DUSCLOPS_ENTITY_STATE_INTRO_APPEARANCE:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
            gCurrentPinballGame->bossFrameTimer++;
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;

            if (gCurrentPinballGame->bossFramesetIndex > DUSCLOPS_FRAME_INTRO_END)
            {
                gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_INTRO_START;

                if (gCurrentPinballGame->dusclopsWalkFootIndex <= 0)
                    gCurrentPinballGame->dusclopsWalkFootIndex++;
                else
                {
                    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
                    gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                }
            }

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_INTRO_FOOTSTEP_LEFT)
            {
                gCurrentPinballGame->boardShakeDirection = 0;
                gCurrentPinballGame->boardShakeIntensity = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_INTRO_FOOTSTEP_RIGHT)
            {
                gCurrentPinballGame->boardShakeDirection = 1;
                gCurrentPinballGame->boardShakeIntensity = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);

            }
        }

        tileOffset = 0;
        break;
    }
    case DUSCLOPS_ENTITY_STATE_GUARD_READY:
    {
        if (gCurrentPinballGame->bossFrameTimer <= 255)
        {
            tileOffset = gDusclopsBossGuardReadyTileOffsets[(gCurrentPinballGame->bossFrameTimer % 0x40) / 16];
            gCurrentPinballGame->bossFrameTimer++;

            if (gCurrentPinballGame->bossFrameTimer == 256)
            {
                gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_WALKING;
                gCurrentPinballGame->bossFrameTimer = 0;

                if (gCurrentPinballGame->dusclopsWalkFootIndex > 3)
                    gCurrentPinballGame->dusclopsWalkFootIndex = 0;
                if (gCurrentPinballGame->dusclopsWalkFootIndex <= 1)
                    gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                else
                    gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD;
            }
        }

        if (gCurrentPinballGame->bossAnimLoopCount > 0)
        {
            if (gCurrentPinballGame->bossAnimLoopCount > 64)
                gCurrentPinballGame->bossAnimLoopCount--;
            else
                gCurrentPinballGame->bossAnimLoopCount -= 2;

            if (gCurrentPinballGame->bossAnimLoopCount == 154)
                m4aSongNumStart(SE_DUSCLOPS_APPEAR); //Dusclops Appears
        }
        else
        {
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
            gCurrentPinballGame->boardModeType = 2;
        }

        break;
    }
    case DUSCLOPS_ENTITY_STATE_WALKING:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
        {
            gCurrentPinballGame->bossFrameTimer++;
        }
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;

            if (gCurrentPinballGame->dusclopsWalkFootIndex <= 1)
            {
                gCurrentPinballGame->bossFramesetIndex++;

                if (gCurrentPinballGame->bossFramesetIndex > DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD)
                {
                    gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                    gCurrentPinballGame->dusclopsWalkFootIndex++;

                    if ((gCurrentPinballGame->dusclopsWalkFootIndex & 1) == 0)
                    {
                        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                        gCurrentPinballGame->bossFrameTimer = 0;
                    }
                }
            }
            else if (--gCurrentPinballGame->bossFramesetIndex < 0)
            {
                gCurrentPinballGame->dusclopsWalkFootIndex++;

                if ((gCurrentPinballGame->dusclopsWalkFootIndex & 1) == 0)
                {
                    gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                    gCurrentPinballGame->bossFrameTimer = 0;
                    gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                }
                else
                    gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD;
            }

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_LEFT_FOOT_LANDS)
            {
                gCurrentPinballGame->boardShakeDirection = 0;
                gCurrentPinballGame->boardShakeIntensity = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_RIGHT_FOOT_LANDS)
            {
                gCurrentPinballGame->boardShakeDirection = 1;
                gCurrentPinballGame->boardShakeIntensity = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }
        }

        tileOffset = DuclopsFramesetData[gCurrentPinballGame->bossFramesetIndex][0];

        if( gCurrentPinballGame->bossFramesetIndex  == DUSCLOPS_FRAME_WALK_NEUTRAL || 
            gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_WALK_NEUTRAL_RIGHT_FOOT_FORWARD )
        {
            break;
        }

        if (gCurrentPinballGame->dusclopsWalkFootIndex <= 1)
        {
            if (gCurrentPinballGame->bossPositionY <= 583)
            {
                gCurrentPinballGame->bossPositionY++;
                break;
            }

            if ((gCurrentPinballGame->bossFramesetIndex % 4) != 0)
                break;

            gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
            gCurrentPinballGame->dusclopsWalkFootIndex = 2;
            break;
        }

        if (gCurrentPinballGame->bossPositionY > 300)
        {
            gCurrentPinballGame->bossPositionY--;
            break;
        }

        if ((gCurrentPinballGame->bossFramesetIndex % 4) != 0)
            break;

        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
        gCurrentPinballGame->dusclopsWalkFootIndex = 4;

        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT:
    {
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_HIT_STUN;
        tileOffset = DUSCLOPS_TILE_OFFSET_HIT;

        m4aSongNumStart(SE_DUSCLOPS_HIT); //Dusclops hit
        gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
        PlayRumble(7);
        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT_STUN:
    {
        if (gCurrentPinballGame->bossFrameTimer <= 27)
        {
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
            gCurrentPinballGame->bossFrameTimer++;
            break;
        }

        if (gCurrentPinballGame->bonusModeHitCount < DUSCLOPS_HITS_NEEDED_TO_SUCCEED -1)
        {
            gCurrentPinballGame->bossFrameTimer = 128;
            gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
            gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
        }
        else
        {
            gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_VANISH;
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
        }

        gCurrentPinballGame->bonusModeHitCount++;
        gCurrentPinballGame->scoreAddedInFrame = 300000;

        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE:
    {
        struct Vector16 tempVector;

        gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_ABSORB_START;
        gCurrentPinballGame->bossFrameTimer = 0;
        gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_ABSORBED_BALL;
        gCurrentPinballGame->captureSequenceFrame = 0;
        tileOffset = DUSCLOPS_TILE_OFFSET_ABSORB_START;

        m4aSongNumStart(SE_DUSCLOPS_BALL_ABSORB); //Dusclops absorbs ball
        gCurrentPinballGame->catchTargetX = (gCurrentPinballGame->bossPositionX / 10) + 32;
        gCurrentPinballGame->catchTargetY = (gCurrentPinballGame->bossPositionY / 10) + 36;

        tempVector.x = (gCurrentPinballGame->catchTargetX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->catchTargetY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->trapSpinRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
        gCurrentPinballGame->trapSpinRadius = Sqrt(gCurrentPinballGame->trapSpinRadius * 4) / 2;
        gCurrentPinballGame->trapAngleQ16 = ArcTan2(-tempVector.x, tempVector.y);

        PlayRumble(13);
        break;
    }
    case DUSCLOPS_ENTITY_STATE_ABSORBED_BALL:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->bossFramesetIndex][1] > gCurrentPinballGame->bossFrameTimer)
            gCurrentPinballGame->bossFrameTimer++;
        else
        {
            gCurrentPinballGame->bossFrameTimer = 0;
            gCurrentPinballGame->bossFramesetIndex++;

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_ABSORB_LAUNCH_PREP)
            {
                gCurrentPinballGame->ball->velocity.x = (gMain.systemFrameCount % 2 * 300) + 65386;
                gCurrentPinballGame->ball->velocity.y = 300;
                gCurrentPinballGame->ball->ballHidden = 0;
                m4aSongNumStart(SE_DUSCLOPS_BALL_LAUNCH); //Dusclops launch ball
                PlayRumble(8);
            }

            if (gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH)
                gCurrentPinballGame->ballFrozenState = 0;

            if (gCurrentPinballGame->bossFramesetIndex > DUSCLOPS_FRAME_ABSOLB_LAUNCH)
            {
                gCurrentPinballGame->bossFrameTimer = 128;
                gCurrentPinballGame->bossFramesetIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                gCurrentPinballGame->bossEntityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            }
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            if ((gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH) && (gCurrentPinballGame->bossFrameTimer > 4))
                gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
        }
        else
        {
            if ((gCurrentPinballGame->bossFramesetIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH) && (gCurrentPinballGame->bossFrameTimer != 0))
                gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
        }

        if (gCurrentPinballGame->captureSequenceFrame <= 29)
        {
            s16 tr4 = 29 - gCurrentPinballGame->captureSequenceFrame;
            s32 sl;

            gCurrentPinballGame->trapAngleQ16 -= ((tr4 * 8192) / 30) - 8192;
            gCurrentPinballGame->ball->spinAngle = gCurrentPinballGame->ball->spinAngle - 8192;

            sl = (gCurrentPinballGame->trapSpinRadius * tr4) / 30;

            gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->catchTargetX * 256) + ((Cos(gCurrentPinballGame->trapAngleQ16) * sl) / 20000);

            gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->catchTargetY * 256) - ((Sin(gCurrentPinballGame->trapAngleQ16) * sl) / 20000);

            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        }

        if (gCurrentPinballGame->captureSequenceFrame == 40)
        {
            gCurrentPinballGame->ball->ballHidden = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        gCurrentPinballGame->captureSequenceFrame++;
        tileOffset = DuclopsFramesetData[gCurrentPinballGame->bossFramesetIndex][0];

        break;
    }
    case DUSCLOPS_ENTITY_STATE_VANISH:
    {
        gCurrentPinballGame->boardModeType = 3;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;

        if (gCurrentPinballGame->bossAnimLoopCount == 0)
        {
            gCurrentPinballGame->ballRespawnState = 2;
            gCurrentPinballGame->ballRespawnTimer = 0;
        }

        tileOffset = DUSCLOPS_TILE_OFFSET_VANQUISHED;

        if (gCurrentPinballGame->bossAnimLoopCount <= 183)
        {
            if (gCurrentPinballGame->bossAnimLoopCount <= 63)
                gCurrentPinballGame->bossAnimLoopCount++;
            else
                gCurrentPinballGame->bossAnimLoopCount += 2;

            if (gCurrentPinballGame->bossAnimLoopCount == 30)
            {
                MPlayStart(&gMPlayInfo_SE1, &se_dusclops_appear);
            }
            break;
        }

        gMain.spriteGroups[13].available = FALSE;
        gMain.spriteGroups[14].available = FALSE;
        gMain.spriteGroups[12].available = FALSE;
        gCurrentPinballGame->boardState = DUSCLOPS_BOARD_STATE_4_INIT_SCORE_PHASE;
        gCurrentPinballGame->stageTimer = 0;
        break;
    }
    default:
        break;
    } //End switch

    DmaCopy16(3 , gDusclopsBoardDusclops_Gfx + tileOffset * 1024, (void *)OBJ_VRAM0+0x10a0, BG_SCREEN_SIZE);

    gCurrentPinballGame->bossCollisionX = ((gCurrentPinballGame->bossPositionX / 10) * 2) + 16;
    gCurrentPinballGame->bossCollisionY = ((gCurrentPinballGame->bossPositionY / 10) * 2) + 16;

    // Draw dusclops
    if(spriteGroup->available != 0)
    {
        struct OamDataSimple *new_var;
        spriteGroup->baseX = (-gCurrentPinballGame->cameraXOffset) + (gCurrentPinballGame->bossPositionX / 10);
        spriteGroup->baseY = (-gCurrentPinballGame->cameraYOffset) + (gCurrentPinballGame->bossPositionY / 10);

        oamSimple = spriteGroup->oam;

        if (tileOffset == DUSCLOPS_TILE_OFFSET_HIT)
        {
            if (gCurrentPinballGame->bossFrameTimer <= 5)
                gOamBuffer[oamSimple->oamId].paletteNum = 4;
            else
                gOamBuffer[oamSimple->oamId].paletteNum = 3;
        }
        else
            gOamBuffer[oamSimple->oamId].paletteNum = 3;

        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    }

    // Blend appearance Lines
    spriteGroup = &gMain.spriteGroups[12];
    if (spriteGroup->available != 0)
    {
        if (gCurrentPinballGame->returnToMainBoardFlag == 0)
        {
            u32 offY = 92;

            spriteGroup->baseX = -gCurrentPinballGame->cameraXOffset + (gCurrentPinballGame->bossPositionX / 10);
            spriteGroup->baseY = -gCurrentPinballGame->cameraYOffset + (gCurrentPinballGame->bossPositionY / 10)
                + ((gCurrentPinballGame->bossAnimLoopCount / 2) - offY);
        }
        else
        {
            spriteGroup->baseX = 240;
            spriteGroup->baseY = 160;
        }

        {
            s16 i;
            u8 r1;
            r1 = gMain.systemFrameCount % 4;
            DmaCopy16(3 , gDusclopsBoardDusclopsAppearFx_Gfx + r1 / 2 * 0x600, (void *)OBJ_VRAM0 + 0x1aa0, 0xc00);

            for (i = 0; i < 2; i++)
            {
                oamSimple = &spriteGroup->oam[i];
                gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
                gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
            }
        }
    }

    // Draw ball capture vortex
    spriteGroup = &gMain.spriteGroups[13];

    if (spriteGroup->available != 0)
    {
        s32 offX = 16;
        s32 offY = 20;
        spriteGroup->baseX = gCurrentPinballGame->bossPositionX / 10 + offX - gCurrentPinballGame->cameraXOffset;
        if (gCurrentPinballGame->bossFramesetIndex >= DUSCLOPS_FRAME_ABSORB_VORTEX_START &&
            gCurrentPinballGame->bossFramesetIndex <= DUSCLOPS_FRAME_ABSORB_VORTEX_END )
        {
            s16 r0;
            spriteGroup->baseY = ((gCurrentPinballGame->bossPositionY / 10) + offY) - gCurrentPinballGame->cameraYOffset;
            r0 = gCurrentPinballGame->captureSequenceFrame % 24;
            if(r0 <= 10)
                tileOffset = 0;
            else if (r0 <= 17)
                tileOffset = 1;
            else
                tileOffset = 2;

            DmaCopy16(3 , gDusclopsBoardDusclopsBallGrabSwirl_Gfx + tileOffset * 0x200,(void *)OBJ_VRAM0+0x18a0, 0x200);
        }
        else
        {
            spriteGroup->baseY = 180;
        }

        oamSimple = spriteGroup->oam;
        gOamBuffer[oamSimple->oamId].x = oamSimple->xOffset + spriteGroup->baseX;
        gOamBuffer[oamSimple->oamId].y = oamSimple->yOffset + spriteGroup->baseY;
    }
}
