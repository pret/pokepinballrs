#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"
#include "m4a.h"

extern void MainBoardProcess_7B_12524(void);
extern void BonusBoardProcess_7B_12BF8(void);
extern void sub_2AADC(void);

extern const u8 gUnknown_08137E14[][0x20];

void AllBoardProcess_5A_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        MainBoardProcess_7B_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->ball = &gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        BonusBoardProcess_7B_12BF8();
    }
}

void sub_11C14(s16 arg0)
{
    struct BallState *ball = &gCurrentPinballGame->unk1334[arg0];
    ball->positionQ0.x = gUnknown_02031520.unk14.unk26;
    ball->positionQ0.y = gUnknown_02031520.unk14.unk28;
    ball->positionQ8.x = Q_24_8(ball->positionQ0.x);
    ball->positionQ8.y = Q_24_8(ball->positionQ0.y);
    ball->positionQ1.x = gUnknown_02031520.unk14.unk26 * 2;
    ball->positionQ1.y = gUnknown_02031520.unk14.unk28 * 2;
    ball->scale = 0x100;
    ball->velocity.x = 0;
    ball->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        ball->oamPriority = 3;
    else
        ball->oamPriority = 1;

    ball->unk6 = 0;
    gCurrentPinballGame->unk5B2 = 1;
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
        velocity.x = unk132c->velocity.x;                \
        velocity.y = unk132c->velocity.y;                \
    }                                                    \
    unk132c->positionQ8.x += velocity.x;                   \
    unk132c->positionQ8.y += velocity.y;                   \
}

void MainBoardProcess_5B_11C98(void)
{
    struct Vector16 velocity;
    struct BallState *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->ball;
    unk132c->prevPositionQ8 = unk132c->positionQ8;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 160)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 80)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (unk132c->positionQ0.y < 380)
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

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 200)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 100)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (unk132c->positionQ0.y < 380)
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
        sub_2AADC();
    }

    unk132c->prevPositionQ1 = unk132c->positionQ1;
    unk132c->positionQ1.x = (unk132c->positionQ8.x + 64) / 128;
    unk132c->positionQ1.y = (unk132c->positionQ8.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

void BonusBoardProcess_5B_11F88(void)
{
    struct Vector16 velocity;
    struct BallState *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->ball;
    unk132c->prevPositionQ8 = unk132c->positionQ8;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (!gCurrentPinballGame->unk1F && !gCurrentPinballGame->unk383)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (unk132c->velocity.y > 150)
                unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
            else if (unk132c->velocity.y > 75)
                unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
            else
                unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->positionQ0.y < 150)
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
                if (unk132c->positionQ0.y < 218)
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
                if (unk132c->positionQ0.y < 218)
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
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->positionQ0.y < 150)
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
                if (unk132c->positionQ0.y < 218)
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
                if (unk132c->positionQ0.y < 218)
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
        sub_2AADC();
    }

    unk132c->prevPositionQ1 = unk132c->positionQ1;
    unk132c->positionQ1.x = (unk132c->positionQ8.x + 64) / 128;
    unk132c->positionQ1.y = (unk132c->positionQ8.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}
