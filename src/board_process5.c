#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern void MainBoardProcess_7B_12524(void);
extern void BonusBoardProcess_7B_12BF8(void);
extern void RunPokemonCaptureAnimation(void);

extern const u8 gUnknown_08137E14[][0x20];

void AllBoardProcess_5A_11B9C(void)
{
    s16 i;
    if (gMain.isBonusField == 0)
    {
        gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[0];
        ResetBallToStartPosition(0);
        MainBoardProcess_7B_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->ball = &gCurrentPinballGame->ballInstances[i];
            ResetBallToStartPosition(i);
        }
        BonusBoardProcess_7B_12BF8();
    }
}

void ResetBallToStartPosition(s16 arg0)
{
    struct BallState *ball = &gCurrentPinballGame->ballInstances[arg0];
    ball->positionQ0.x = gBoardConfig.fieldLayout.ballStartX;
    ball->positionQ0.y = gBoardConfig.fieldLayout.ballStartY;
    ball->positionQ8.x = Q_24_8(ball->positionQ0.x);
    ball->positionQ8.y = Q_24_8(ball->positionQ0.y);
    ball->positionQ1.x = gBoardConfig.fieldLayout.ballStartX * 2;
    ball->positionQ1.y = gBoardConfig.fieldLayout.ballStartY * 2;
    ball->scale = 0x100;
    ball->velocity.x = 0;
    ball->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        ball->oamPriority = 3;
    else
        ball->oamPriority = 1;

    ball->spin = 0;
    gCurrentPinballGame->ballCollisionDisabled = 1;
}

extern const u16 gGravityDeltas_Strong[4];
extern const u16 gGravityDeltas_Medium[4];
extern const u16 gGravityDeltas_Light[4];


// Before updating the ball's position, cap the ball's velocity
// vector to a maximum speed.
#define UPDATE_BALL_POSITION(max_speed, angle)           \
{                                                        \
    maxSpeed = (max_speed);                              \
    if (squaredMagnitude > maxSpeed * maxSpeed)          \
    {                                                    \
        velocity.x =  (maxSpeed * Cos((angle))) / 20000; \
        velocity.y = (-maxSpeed * Sin((angle))) / 20000; \
    }                                                    \
    else                                                 \
    {                                                    \
        velocity.x = ball->velocity.x;                \
        velocity.y = ball->velocity.y;                \
    }                                                    \
    ball->positionQ8.x += velocity.x;                   \
    ball->positionQ8.y += velocity.y;                   \
}

void MainBoardProcess_5B_11C98(void)
{
    struct Vector16 velocity;
    struct BallState *ball;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    ball = gCurrentPinballGame->ball;
    ball->prevPositionQ8 = ball->positionQ8;
    if (gCurrentPinballGame->catchModeHitPhase != 2)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (!gCurrentPinballGame->ballLockState)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (ball->velocity.y > 160)
                    ball->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->currentProcessPass];
                else if (ball->velocity.y > 80)
                    ball->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->currentProcessPass];
                else
                    ball->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->currentProcessPass];
            }

            angle = ArcTan2(ball->velocity.x, -ball->velocity.y);
            xx = ball->velocity.x * ball->velocity.x;
            yy = ball->velocity.y * ball->velocity.y;
            squaredMagnitude = xx + yy;

            if (ball->positionQ0.y < 380)
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

            if (!gCurrentPinballGame->ballLockState)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (ball->velocity.y > 200)
                    ball->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->currentProcessPass];
                else if (ball->velocity.y > 100)
                    ball->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->currentProcessPass];
                else
                    ball->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->currentProcessPass];
            }

            angle = ArcTan2(ball->velocity.x, -ball->velocity.y);
            xx = ball->velocity.x * ball->velocity.x;
            yy = ball->velocity.y * ball->velocity.y;
            squaredMagnitude = xx + yy;

            if (ball->positionQ0.y < 380)
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
        RunPokemonCaptureAnimation();
    }

    ball->prevPositionQ1 = ball->positionQ1;
    ball->positionQ1.x = (ball->positionQ8.x + 64) / 128;
    ball->positionQ1.y = (ball->positionQ8.y + 64) / 128;
    ball->angleBias = ball->spin;
    ball->rotation += ball->spin;
}

void BonusBoardProcess_5B_11F88(void)
{
    struct Vector16 velocity;
    struct BallState *ball;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    ball = gCurrentPinballGame->ball;
    ball->prevPositionQ8 = ball->positionQ8;
    if (gCurrentPinballGame->catchModeHitPhase != 2)
    {
        if (!gCurrentPinballGame->ballLockState && !gCurrentPinballGame->bossGrabbedBall)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (ball->velocity.y > 150)
                ball->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->currentProcessPass];
            else if (ball->velocity.y > 75)
                ball->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->currentProcessPass];
            else
                ball->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->currentProcessPass];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(ball->velocity.x, -ball->velocity.y);
            xx = ball->velocity.x * ball->velocity.x;
            yy = ball->velocity.y * ball->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (ball->positionQ0.y < 150)
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
                if (ball->positionQ0.y < 218)
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
                if (ball->positionQ0.y < 218)
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
            angle = ArcTan2(ball->velocity.x, -ball->velocity.y);
            xx = ball->velocity.x * ball->velocity.x;
            yy = ball->velocity.y * ball->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (ball->positionQ0.y < 150)
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
                if (ball->positionQ0.y < 218)
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
                if (ball->positionQ0.y < 218)
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
        RunPokemonCaptureAnimation();
    }

    ball->prevPositionQ1 = ball->positionQ1;
    ball->positionQ1.x = (ball->positionQ8.x + 64) / 128;
    ball->positionQ1.y = (ball->positionQ8.y + 64) / 128;
    ball->angleBias = ball->spin;
    ball->rotation += ball->spin;
}
