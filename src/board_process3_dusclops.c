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
    gCurrentPinballGame->entityActivePhase = 1;
    gCurrentPinballGame->eventTimer = gCurrentPinballGame->timerBonus + BONUS_DUSKULL_TIME;
    gCurrentPinballGame->timerBonus = 0;
    gCurrentPinballGame->bossGrabbedBall = 0;
    gCurrentPinballGame->bonusCaptureState = 3;
    gCurrentPinballGame->ball->isGrabbed = 1;
    gCurrentPinballGame->bonusModeHitCount = 0;
    gCurrentPinballGame->returnToMainBoardFlag = 0;
    gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
    gCurrentPinballGame->bonusSequenceTimer = 0;
    gCurrentPinballGame->bonusScrollOffsetY = 0;
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

    gCurrentPinballGame->entityState = 0;
    gCurrentPinballGame->entityDirection = 0;
    gCurrentPinballGame->entitySpriteFrame = 0;
    gCurrentPinballGame->entityWalkCycleCount = 0;
    gCurrentPinballGame->entityAnimIndex = 0;
    gCurrentPinballGame->entityAnimTimer = 0;
    gCurrentPinballGame->entityAppearDissolveTimer = 0;
    gCurrentPinballGame->entityPosXQ10 = 0;
    gCurrentPinballGame->entityPosYQ10 = 0;
    gCurrentPinballGame->entityTargetPosX = 0;
    gCurrentPinballGame->entityTargetPosY = 0;
    gCurrentPinballGame->entityCollisionOriginX = 0;
    gCurrentPinballGame->entityCollisionOriginY = 0;
    gCurrentPinballGame->fieldEntryInProgress = 0;

    DuskullPhase_ProcessEntityLogic();
    DuskullPhase_ProcessGraphics();

    m4aSongNumStart(MUS_BONUS_FIELD_DUSKULL);

    DmaCopy16(3, (void *)gUnknown_081B36A4, (void *)0x05000320, 32);
}

void DusclopsBoardProcess_3B_33130(void)
{
    s16 temp;
    switch (gCurrentPinballGame->boardState)
    {
        case DUSCLOPS_BOARD_STATE_0_INTRO:
            gCurrentPinballGame->ballLocked = 1;
            if (gCurrentPinballGame->stageTimer < 120)
            {
                temp = gCurrentPinballGame->stageTimer / 24;
                DmaCopy16(3, gUnknown_082EE0E0 + temp * 40, 0x05000000, 160);

                gCurrentPinballGame->fieldScrollOffsetY = gCurrentPinballGame->stageTimer / 5 + 0xFFE8;
                gCurrentPinballGame->stageTimer++;
            }
            else
            {
                gCurrentPinballGame->fieldScrollOffsetY = 0;
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
                gCurrentPinballGame->bonusScrollOffsetY = 136;
            }
            break;
        case DUSCLOPS_BOARD_STATE_SCORE_PHASE:
            ProceessBonusBannerAndScoring();
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
            ProceessBonusBannerAndScoring();
            gCurrentPinballGame->returnToMainBoardFlag = 1;
            break;
    }

    if (gCurrentPinballGame->entityActivePhase)
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
            spriteGroup->baseX = gCurrentPinballGame->minionLogicPosition[i].x / 10 + 108 + x - gCurrentPinballGame->bgScrollXCopy;
            spriteGroup->baseY = gCurrentPinballGame->minionLogicPosition[i].y / 10 + 28 + x - gCurrentPinballGame->bgScrollYWithOffset;
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
    switch(gCurrentPinballGame->entityState)
    {
    case DUSCLOPS_ENTITY_STATE_INIT:
    {
        gCurrentPinballGame->entityPosXQ10 = 880;
        gCurrentPinballGame->entityPosYQ10 = 300;
        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_INTRO_APPEARANCE;
        gCurrentPinballGame->entityAppearDissolveTimer = 184;
        gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_INTRO_START;
        tileOffset = 0;
        gCurrentPinballGame->entityActivePhase = 1;
        break;
    }

    case DUSCLOPS_ENTITY_STATE_INTRO_APPEARANCE:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
            gCurrentPinballGame->entityAnimTimer++;
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;

            if (gCurrentPinballGame->entityAnimIndex > DUSCLOPS_FRAME_INTRO_END)
            {
                gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_INTRO_START;

                if (gCurrentPinballGame->entityWalkCycleCount <= 0)
                    gCurrentPinballGame->entityWalkCycleCount++;
                else
                {
                    gCurrentPinballGame->entityWalkCycleCount = 0;
                    gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                }
            }

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_INTRO_FOOTSTEP_LEFT)
            {
                gCurrentPinballGame->bumperShakeAxis = 0;
                gCurrentPinballGame->bumperShakeTimer = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_INTRO_FOOTSTEP_RIGHT)
            {
                gCurrentPinballGame->bumperShakeAxis = 1;
                gCurrentPinballGame->bumperShakeTimer = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);

            }
        }

        tileOffset = 0;
        break;
    }
    case DUSCLOPS_ENTITY_STATE_GUARD_READY:
    {
        if (gCurrentPinballGame->entityAnimTimer <= 255)
        {
            tileOffset = gUnknown_08137D40[(gCurrentPinballGame->entityAnimTimer % 0x40) / 16];
            gCurrentPinballGame->entityAnimTimer++;

            if (gCurrentPinballGame->entityAnimTimer == 256)
            {
                gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_WALKING;
                gCurrentPinballGame->entityAnimTimer = 0;

                if (gCurrentPinballGame->entityWalkCycleCount > 3)
                    gCurrentPinballGame->entityWalkCycleCount = 0;
                if (gCurrentPinballGame->entityWalkCycleCount <= 1)
                    gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                else
                    gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD;
            }
        }

        if (gCurrentPinballGame->entityAppearDissolveTimer > 0)
        {
            if (gCurrentPinballGame->entityAppearDissolveTimer > 64)
                gCurrentPinballGame->entityAppearDissolveTimer--;
            else
                gCurrentPinballGame->entityAppearDissolveTimer -= 2;

            if (gCurrentPinballGame->entityAppearDissolveTimer == 154)
                m4aSongNumStart(SE_DUSCLOPS_APPEAR); //Dusclops Appears
        }
        else
        {
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
            gCurrentPinballGame->entityActivePhase = 2;
        }

        break;
    }
    case DUSCLOPS_ENTITY_STATE_WALKING:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
        {
            gCurrentPinballGame->entityAnimTimer++;
        }
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;

            if (gCurrentPinballGame->entityWalkCycleCount <= 1)
            {
                gCurrentPinballGame->entityAnimIndex++;

                if (gCurrentPinballGame->entityAnimIndex > DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD)
                {
                    gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                    gCurrentPinballGame->entityWalkCycleCount++;

                    if ((gCurrentPinballGame->entityWalkCycleCount & 1) == 0)
                    {
                        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                        gCurrentPinballGame->entityAnimTimer = 0;
                    }
                }
            }
            else if (--gCurrentPinballGame->entityAnimIndex < 0)
            {
                gCurrentPinballGame->entityWalkCycleCount++;

                if ((gCurrentPinballGame->entityWalkCycleCount & 1) == 0)
                {
                    gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
                    gCurrentPinballGame->entityAnimTimer = 0;
                    gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                }
                else
                    gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_RIGHT_FOOT_FORWARD;
            }

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_LEFT_FOOT_LANDS)
            {
                gCurrentPinballGame->bumperShakeAxis = 0;
                gCurrentPinballGame->bumperShakeTimer = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_RIGHT_FOOT_LANDS)
            {
                gCurrentPinballGame->bumperShakeAxis = 1;
                gCurrentPinballGame->bumperShakeTimer = 1;
                m4aSongNumStart(SE_DUSCLOPS_MOVE);
                PlayRumble(8);
            }
        }

        tileOffset = DuclopsFramesetData[gCurrentPinballGame->entityAnimIndex][0];

        if( gCurrentPinballGame->entityAnimIndex  == DUSCLOPS_FRAME_WALK_NEUTRAL || 
            gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_WALK_NEUTRAL_RIGHT_FOOT_FORWARD )
        {
            break;
        }

        if (gCurrentPinballGame->entityWalkCycleCount <= 1)
        {
            if (gCurrentPinballGame->entityPosYQ10 <= 583)
            {
                gCurrentPinballGame->entityPosYQ10++;
                break;
            }

            if ((gCurrentPinballGame->entityAnimIndex % 4) != 0)
                break;

            gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
            gCurrentPinballGame->entityWalkCycleCount = 2;
            break;
        }

        if (gCurrentPinballGame->entityPosYQ10 > 300)
        {
            gCurrentPinballGame->entityPosYQ10--;
            break;
        }

        if ((gCurrentPinballGame->entityAnimIndex % 4) != 0)
            break;

        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
        gCurrentPinballGame->entityWalkCycleCount = 4;

        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT:
    {
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_HIT_STUN;
        tileOffset = DUSCLOPS_TILE_OFFSET_HIT;

        m4aSongNumStart(SE_DUSCLOPS_HIT); //Dusclops hit
        gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
        PlayRumble(7);
        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT_STUN:
    {
        if (gCurrentPinballGame->entityAnimTimer <= 27)
        {
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
            gCurrentPinballGame->entityAnimTimer++;
            break;
        }

        if (gCurrentPinballGame->bonusModeHitCount < DUSCLOPS_HITS_NEEDED_TO_SUCCEED -1)
        {
            gCurrentPinballGame->entityAnimTimer = 128;
            gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
            gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_NONE;
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
        }
        else
        {
            gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_VANISH;
            tileOffset = DUSCLOPS_TILE_OFFSET_HIT;
        }

        gCurrentPinballGame->bonusModeHitCount++;
        gCurrentPinballGame->scoreAddedInFrame = 300000;

        break;
    }
    case DUSCLOPS_ENTITY_STATE_HIT_ABSORB_ZONE:
    {
        struct Vector16 tempVector;

        gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_ABSORB_START;
        gCurrentPinballGame->entityAnimTimer = 0;
        gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_ABSORBED_BALL;
        gCurrentPinballGame->entityCaptureTimer = 0;
        tileOffset = DUSCLOPS_TILE_OFFSET_ABSORB_START;

        m4aSongNumStart(SE_DUSCLOPS_BALL_ABSORB); //Dusclops absorbs ball
        gCurrentPinballGame->entityCenterX = (gCurrentPinballGame->entityPosXQ10 / 10) + 32;
        gCurrentPinballGame->entityCenterY = (gCurrentPinballGame->entityPosYQ10 / 10) + 36;

        tempVector.x = (gCurrentPinballGame->entityCenterX << 8) - gCurrentPinballGame->ball->positionQ8.x;
        tempVector.y = (gCurrentPinballGame->entityCenterY << 8) - gCurrentPinballGame->ball->positionQ8.y;

        gCurrentPinballGame->captureArcRadius = (tempVector.x * tempVector.x) + (tempVector.y * tempVector.y);
        gCurrentPinballGame->captureArcRadius = Sqrt(gCurrentPinballGame->captureArcRadius * 4) / 2;
        gCurrentPinballGame->captureArcAngle = ArcTan2(-tempVector.x, tempVector.y);

        PlayRumble(13);
        break;
    }
    case DUSCLOPS_ENTITY_STATE_ABSORBED_BALL:
    {
        if (DuclopsFramesetData[gCurrentPinballGame->entityAnimIndex][1] > gCurrentPinballGame->entityAnimTimer)
            gCurrentPinballGame->entityAnimTimer++;
        else
        {
            gCurrentPinballGame->entityAnimTimer = 0;
            gCurrentPinballGame->entityAnimIndex++;

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_ABSORB_LAUNCH_PREP)
            {
                gCurrentPinballGame->ball->velocity.x = (gMain.systemFrameCount % 2 * 300) + 65386;
                gCurrentPinballGame->ball->velocity.y = 300;
                gCurrentPinballGame->ball->isGrabbed = 0;
                m4aSongNumStart(SE_DUSCLOPS_BALL_LAUNCH); //Dusclops launch ball
                PlayRumble(8);
            }

            if (gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH)
                gCurrentPinballGame->ballLockState = 0;

            if (gCurrentPinballGame->entityAnimIndex > DUSCLOPS_FRAME_ABSOLB_LAUNCH)
            {
                gCurrentPinballGame->entityAnimTimer = 128;
                gCurrentPinballGame->entityAnimIndex = DUSCLOPS_FRAME_WALK_NEUTRAL;
                gCurrentPinballGame->entityState = DUSCLOPS_ENTITY_STATE_GUARD_READY;
            }
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            if ((gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH) && (gCurrentPinballGame->entityAnimTimer > 4))
                gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
        }
        else
        {
            if ((gCurrentPinballGame->entityAnimIndex == DUSCLOPS_FRAME_ABSOLB_LAUNCH) && (gCurrentPinballGame->entityAnimTimer != 0))
                gCurrentPinballGame->boardEntityCollisionMode = DUSCLOPS_ENTITY_COLLISION_MODE_DUSCLOPS;
        }

        if (gCurrentPinballGame->entityCaptureTimer <= 29)
        {
            s16 tr4 = 29 - gCurrentPinballGame->entityCaptureTimer;
            s32 sl;

            gCurrentPinballGame->captureArcAngle -= ((tr4 * 8192) / 30) - 8192;
            gCurrentPinballGame->ball->rotation = gCurrentPinballGame->ball->rotation - 8192;

            sl = (gCurrentPinballGame->captureArcRadius * tr4) / 30;

            gCurrentPinballGame->ball->positionQ8.x = (gCurrentPinballGame->entityCenterX * 256) + ((Cos(gCurrentPinballGame->captureArcAngle) * sl) / 20000);

            gCurrentPinballGame->ball->positionQ8.y = (gCurrentPinballGame->entityCenterY * 256) - ((Sin(gCurrentPinballGame->captureArcAngle) * sl) / 20000);

            gCurrentPinballGame->ball->velocity.x = (gCurrentPinballGame->ball->velocity.x * 4) / 5;
            gCurrentPinballGame->ball->velocity.y = (gCurrentPinballGame->ball->velocity.y * 4) / 5;
        }

        if (gCurrentPinballGame->entityCaptureTimer == 40)
        {
            gCurrentPinballGame->ball->isGrabbed = 1;
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
        }

        gCurrentPinballGame->entityCaptureTimer++;
        tileOffset = DuclopsFramesetData[gCurrentPinballGame->entityAnimIndex][0];

        break;
    }
    case DUSCLOPS_ENTITY_STATE_VANISH:
    {
        gCurrentPinballGame->entityActivePhase = 3;
        gMain.modeChangeFlags = MODE_CHANGE_BONUS_BANNER;

        if (gCurrentPinballGame->entityAppearDissolveTimer == 0)
        {
            gCurrentPinballGame->bonusCaptureState = 2;
            gCurrentPinballGame->bonusSequenceTimer = 0;
        }

        tileOffset = DUSCLOPS_TILE_OFFSET_VANQUISHED;

        if (gCurrentPinballGame->entityAppearDissolveTimer <= 183)
        {
            if (gCurrentPinballGame->entityAppearDissolveTimer <= 63)
                gCurrentPinballGame->entityAppearDissolveTimer++;
            else
                gCurrentPinballGame->entityAppearDissolveTimer += 2;

            if (gCurrentPinballGame->entityAppearDissolveTimer == 30)
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

    gCurrentPinballGame->entityCollisionOriginX = ((gCurrentPinballGame->entityPosXQ10 / 10) * 2) + 16;
    gCurrentPinballGame->entityCollisionOriginY = ((gCurrentPinballGame->entityPosYQ10 / 10) * 2) + 16;

    // Draw dusclops
    if(spriteGroup->available != 0)
    {
        struct OamDataSimple *new_var;
        spriteGroup->baseX = (-gCurrentPinballGame->bgScrollXCopy) + (gCurrentPinballGame->entityPosXQ10 / 10);
        spriteGroup->baseY = (-gCurrentPinballGame->bgScrollYWithOffset) + (gCurrentPinballGame->entityPosYQ10 / 10);

        oamSimple = spriteGroup->oam;

        if (tileOffset == DUSCLOPS_TILE_OFFSET_HIT)
        {
            if (gCurrentPinballGame->entityAnimTimer <= 5)
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

            spriteGroup->baseX = -gCurrentPinballGame->bgScrollXCopy + (gCurrentPinballGame->entityPosXQ10 / 10);
            spriteGroup->baseY = -gCurrentPinballGame->bgScrollYWithOffset + (gCurrentPinballGame->entityPosYQ10 / 10)
                + ((gCurrentPinballGame->entityAppearDissolveTimer / 2) - offY);
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
        spriteGroup->baseX = gCurrentPinballGame->entityPosXQ10 / 10 + offX - gCurrentPinballGame->bgScrollXCopy;
        if (gCurrentPinballGame->entityAnimIndex >= DUSCLOPS_FRAME_ABSORB_VORTEX_START &&
            gCurrentPinballGame->entityAnimIndex <= DUSCLOPS_FRAME_ABSORB_VORTEX_END )
        {
            s16 r0;
            spriteGroup->baseY = ((gCurrentPinballGame->entityPosYQ10 / 10) + offY) - gCurrentPinballGame->bgScrollYWithOffset;
            r0 = gCurrentPinballGame->entityCaptureTimer % 24;
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
