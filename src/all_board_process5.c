#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"
#include "constants/board/center_screen_states.h"

extern void MainBoardProcess_7B_12524(void);
extern void BonusBoardProcess_7B_12BF8(void);
extern void RunMonCaptureSequence(void);


void AllBoardProcess_5A_11B9C(void)
{
    s16 i;
    if ( !gMain.isBonusField )
    {
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[0];
        InitBallState(0);
        MainBoardProcess_7B_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->ball = &gCurrentPinballGame->ballStates[i];
            InitBallState(i);
        }
        BonusBoardProcess_7B_12BF8();
    }
}

void InitBallState(s16 arg0)
{
    struct BallState *ball = &gCurrentPinballGame->ballStates[arg0];
    ball->positionQ0.x = gBoardConfig.fieldLayout.ballSpawnX;
    ball->positionQ0.y = gBoardConfig.fieldLayout.ballSpawnY;
    ball->positionQ8.x = Q_24_8(ball->positionQ0.x);
    ball->positionQ8.y = Q_24_8(ball->positionQ0.y);
    ball->positionQ1.x = gBoardConfig.fieldLayout.ballSpawnX * 2;
    ball->positionQ1.y = gBoardConfig.fieldLayout.ballSpawnY * 2;
    ball->scale = 0x100;
    ball->velocity.x = 0;
    ball->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        ball->oamPriority = 3;
    else
        ball->oamPriority = 1;

    ball->spinSpeed = 0;
    gCurrentPinballGame->ballInLowerHalf = TRUE;
}

extern const u16 gGravityDeltas_Strong[4];
extern const u16 gGravityDeltas_Medium[4];
extern const u16 gGravityDeltas_Light[4];


// Before updating the ball's position, cap the ball's velocity
// vector to a maximum speed.
#define UPDATE_BALL_POSITION(max_speed, angle)           \
{                                                        \
    maxSpeed = (max_speed);                              \
    if (squaredSpeed > maxSpeed * maxSpeed)              \
    {                                                    \
        velocity.x =  (maxSpeed * Cos((angle))) / 20000; \
        velocity.y = (-maxSpeed * Sin((angle))) / 20000; \
    }                                                    \
    else                                                 \
    {                                                    \
        velocity.x = currentBall->velocity.x;                \
        velocity.y = currentBall->velocity.y;                \
    }                                                    \
    currentBall->positionQ8.x += velocity.x;                   \
    currentBall->positionQ8.y += velocity.y;                   \
}

void MainBoardProcess_5B_11C98(void)
{
    struct Vector16 velocity;
    struct BallState *currentBall;
    int xx, yy;
    int squaredSpeed;
    int maxSpeed;

    currentBall = gCurrentPinballGame->ball;
    currentBall->prevPositionQ8 = currentBall->positionQ8;

    if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (currentBall->velocity.y > 160)
                    currentBall->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->gravityStrengthIndex];
                else if (currentBall->velocity.y > 80)
                    currentBall->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->gravityStrengthIndex];
                else
                    currentBall->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->gravityStrengthIndex];
            }

            angle = ArcTan2(currentBall->velocity.x, -currentBall->velocity.y);
            xx = currentBall->velocity.x * currentBall->velocity.x;
            yy = currentBall->velocity.y * currentBall->velocity.y;
            squaredSpeed = xx + yy;

            if (currentBall->positionQ0.y < 380)
            {
                UPDATE_BALL_POSITION(272, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
        else
        {
            u16 angle;

            if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (currentBall->velocity.y > 200)
                    currentBall->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->gravityStrengthIndex];
                else if (currentBall->velocity.y > 100)
                    currentBall->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->gravityStrengthIndex];
                else
                    currentBall->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->gravityStrengthIndex];
            }

            angle = ArcTan2(currentBall->velocity.x, -currentBall->velocity.y);
            xx = currentBall->velocity.x * currentBall->velocity.x;
            yy = currentBall->velocity.y * currentBall->velocity.y;
            squaredSpeed = xx + yy;

            if (currentBall->positionQ0.y < 380)
            {
                UPDATE_BALL_POSITION(336, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
    }
    else
    {
        RunMonCaptureSequence();
    }

    currentBall->prevPositionQ1 = currentBall->positionQ1;
    currentBall->positionQ1.x = (currentBall->positionQ8.x + 64) / 128;
    currentBall->positionQ1.y = (currentBall->positionQ8.y + 64) / 128;
    currentBall->prevSpinSpeed = currentBall->spinSpeed;
    currentBall->spinAngle += currentBall->spinSpeed;
}

void BonusBoardProcess_5B_11F88(void)
{
    struct Vector16 velocity;
    struct BallState *currentBall;
    int xx, yy;
    int squaredSpeed;
    int maxSpeed;

    currentBall = gCurrentPinballGame->ball;
    currentBall->prevPositionQ8 = currentBall->positionQ8;
    if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
    {
        if (gCurrentPinballGame->ballPhysicsState == BALL_PHYSICS_NORMAL
            && !gCurrentPinballGame->ballGrabbed)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (currentBall->velocity.y > 150)
                currentBall->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->gravityStrengthIndex];
            else if (currentBall->velocity.y > 75)
                currentBall->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->gravityStrengthIndex];
            else
                currentBall->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->gravityStrengthIndex];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(currentBall->velocity.x, -currentBall->velocity.y);
            xx = currentBall->velocity.x * currentBall->velocity.x;
            yy = currentBall->velocity.y * currentBall->velocity.y;
            squaredSpeed = xx + yy;

            if (gMain.selectedField < FIELD_BOSS_START)
            {
                if (currentBall->positionQ0.y < 150)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (currentBall->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (currentBall->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
        else
        {
            u16 angle;
            angle = ArcTan2(currentBall->velocity.x, -currentBall->velocity.y);
            xx = currentBall->velocity.x * currentBall->velocity.x;
            yy = currentBall->velocity.y * currentBall->velocity.y;
            squaredSpeed = xx + yy;

            if (gMain.selectedField < FIELD_BOSS_START)
            {
                if (currentBall->positionQ0.y < 150)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (currentBall->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (currentBall->positionQ0.y < 218)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
    }
    else
    {
        RunMonCaptureSequence();
    }

    currentBall->prevPositionQ1 = currentBall->positionQ1;
    currentBall->positionQ1.x = (currentBall->positionQ8.x + 64) / 128;
    currentBall->positionQ1.y = (currentBall->positionQ8.y + 64) / 128;
    currentBall->prevSpinSpeed = currentBall->spinSpeed;
    currentBall->spinAngle += currentBall->spinSpeed;
}
