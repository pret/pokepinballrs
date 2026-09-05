#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "constants/anglemath.h"
#include "constants/board/main_board.h"
#include "constants/collision.h"

extern u8 gCatchTargetCollisionBitmap[];
extern u16 gFlipperCollisionAngles[][2];
extern u16 gFlipperLaunchVelocityParams[][2];
extern s8 gFlipperCollisionFrameMapping[][5];


u16 DetectBallCollision(struct Vector16*);
void ComputeWallReflection(u16,struct Vector16*, struct Vector16*);
void ApplyTiltEffectOnCollision(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle);
void ProcessBonusTrapPhysics(void);
u16 PixelWalkCollisionDetection(struct Vector16*, struct Vector16);

void ComputeFlipperLaunchVelocity(s32 arg0, s16 arg1, struct Vector16* arg2, u16 arg3);

void AllBoardProcess_6A_4CEA8()
{
	gCurrentPinballGame->collisionCooldownTimer = 60;
}

void AllBoardProcess_6B_1333C()
{
    struct Vector16 ballPosition;
    struct Vector16 var1;
    struct Vector16 var2;
    s16 i;
    u16 r7;

    r7 = DetectBallCollision(&ballPosition);
    switch (gCurrentPinballGame->collisionResponseType)
    {
        case 7:
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            break;
        case 1:
            ApplyTiltEffectOnCollision(&ballPosition, &var1, r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= r7)
                {
                    ballPosition.x += gWallCollisionPositionCorrection[i].correctionX;
                    ballPosition.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 6:
            ApplyTiltEffectOnCollision(&ballPosition, &var1,r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 2:
            ApplyTiltEffectOnCollision(&ballPosition, &var1, r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= r7)
                {
                    ballPosition.x += gWallCollisionPositionCorrection[i].correctionX;
                    ballPosition.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 3:
            ApplyTiltEffectOnCollision(&ballPosition, &var1, r7);
            ballPosition.x -= (gBoardConfig.fieldLayout.leftFlipperOriginX * 2);
            ballPosition.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (!gCurrentPinballGame->flipper[SIDE_IX_LEFT].bounceApplied)
            {
                ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->flipper[SIDE_IX_LEFT].bounceApplied = TRUE;
            }
            else
            {
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            ComputeFlipperBounce(&ballPosition, &var2, SIDE_IX_LEFT);
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->collisionResponseType == 5)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= r7)
                    {
                        ballPosition.x += gFlipperCollisionAngleCorrection[i].correctionX;
                        ballPosition.y += gFlipperCollisionAngleCorrection[i].correctionY;
                        break;
                    }
                }
            }
            ballPosition.x += gBoardConfig.fieldLayout.leftFlipperOriginX * 2;
            ballPosition.y += gBoardConfig.fieldLayout.flipperOriginY * 2;
            break;
        case 4:
            ApplyTiltEffectOnCollision(&ballPosition, &var1, r7);
            ballPosition.x -= (gBoardConfig.fieldLayout.rightFlipperOriginX * 2);
            ballPosition.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (!gCurrentPinballGame->flipper[SIDE_IX_RIGHT].bounceApplied)
            {
                ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->flipper[SIDE_IX_RIGHT].bounceApplied = TRUE;
            }
            else
            {
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            ballPosition.x = 0x5f - ballPosition.x;
            var2.x = -var2.x;
            ComputeFlipperBounce(&ballPosition, &var2, SIDE_IX_RIGHT);
            var2.x = -var2.x;
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->collisionResponseType == 5)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= r7)
                    {
                        ballPosition.x -= gFlipperCollisionAngleCorrection[i].correctionX;
                        ballPosition.y += gFlipperCollisionAngleCorrection[i].correctionY;
                        break;
                    }
                }
            }
            ballPosition.x = 0x5f - ballPosition.x;
            ballPosition.x += gBoardConfig.fieldLayout.rightFlipperOriginX * 2;
            ballPosition.y += gBoardConfig.fieldLayout.flipperOriginY * 2;
            break;
        default:
            if (gCurrentPinballGame->tiltTargetXOffset > 0)
            {
                if (gCurrentPinballGame->lastTiltDirection != 1)
                {
                    gCurrentPinballGame->ball->velocity.x -=  4;
                    gCurrentPinballGame->lastTiltDirection = 1;
                }
            }
            else if (gCurrentPinballGame->tiltTargetXOffset < 0)
            {
                if (gCurrentPinballGame->lastTiltDirection != -1)
                {
                    gCurrentPinballGame->ball->velocity.x += 4;
                    gCurrentPinballGame->lastTiltDirection = -1;
                }
            }
            if (gCurrentPinballGame->bonusTrapEnabled)
            {
                ProcessBonusTrapPhysics();
            }
    }
    if (gCurrentPinballGame->collisionResponseType != 0)
    {
        gCurrentPinballGame->ball->positionQ1.x = ballPosition.x;
        gCurrentPinballGame->ball->positionQ1.y = ballPosition.y;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x << 7;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y << 7;
    }
}

u16 DetectBallCollision(struct Vector16* ballPosition)
{
    u16 retVal;
    struct Vector16 test;
    test.x = gCurrentPinballGame->ball->positionQ1.x - gCurrentPinballGame->ball->prevPositionQ1.x;
    test.y = gCurrentPinballGame->ball->positionQ1.y - gCurrentPinballGame->ball->prevPositionQ1.y;
    ballPosition->x = gCurrentPinballGame->ball->prevPositionQ1.x;
    ballPosition->y = gCurrentPinballGame->ball->prevPositionQ1.y;
    retVal = PixelWalkCollisionDetection(ballPosition, test);

    gCurrentPinballGame->tiltInputCounterX = 0;
    gCurrentPinballGame->tiltInputCounterY = 0;

    if (!gCurrentPinballGame->collisionResponseType && (gCurrentPinballGame->tiltTargetXOffset || gCurrentPinballGame->tiltTargetYOffset))
    {
        ballPosition->x = gCurrentPinballGame->ball->positionQ1.x;
        ballPosition->y = gCurrentPinballGame->ball->positionQ1.y;
        test.x = gCurrentPinballGame->tiltTargetXOffset;
        test.y = gCurrentPinballGame->tiltTargetYOffset;
        retVal = PixelWalkCollisionDetection(ballPosition, test);
        gCurrentPinballGame->tiltInputCounterX = ballPosition->x - gCurrentPinballGame->ball->positionQ1.x;
        gCurrentPinballGame->tiltInputCounterY = ballPosition->y - gCurrentPinballGame->ball->positionQ1.y;
    }
    return retVal;
}

void ApplyTiltEffectOnCollision(struct Vector16 *ballPosition, struct Vector16 *arg1, u16 angle)
{
    s16 cos;

    arg1->x = 0;
    arg1->y = 0;
    if (gCurrentPinballGame->tiltTargetXOffset)
    {
        ballPosition->x -= gCurrentPinballGame->tiltInputCounterX;
        if (gCurrentPinballGame->tiltTargetXOffset > 0)
        {
            cos = Cos(angle);
            if (cos < 0)
            {
                arg1->x = MulCos(70, angle);
                gCurrentPinballGame->tiltLockoutTimer = 1;
            }
        }
        else if (gCurrentPinballGame->tiltTargetXOffset < 0)
        {
            cos = Cos(angle);
            if (cos > 0)
            {
                arg1->x = MulCos(70, angle);
                gCurrentPinballGame->tiltLockoutTimer = 1;
            }
        }
    }

    if (gCurrentPinballGame->tiltTargetYOffset > 0)
    {
        ballPosition->y -= gCurrentPinballGame->tiltInputCounterY;
        if (gCurrentPinballGame->ball->positionQ0.y > 364)
        {
            if (gCurrentPinballGame->tiltTargetXOffset == 0)
                arg1->y = MulSin(-130, angle);
            else
                arg1->y = MulNegSinSpecial(100, angle);
        }
        else
        {
            if (gCurrentPinballGame->tiltTargetXOffset == 0)
                arg1->y = MulNegSinSpecial(100, angle);
            else
                arg1->y = MulSin(-75, angle);

            if (arg1->y >= 90)
                gCurrentPinballGame->ball->velocity.x /= 4;
            else if (arg1->y >= 70)
                gCurrentPinballGame->ball->velocity.x /= 4;
        }

        gCurrentPinballGame->tiltLockoutTimer = 1;
    }

    if (gCurrentPinballGame->tiltLockoutTimer)
    {
        gCurrentPinballGame->tiltTargetXOffset = 0;
        gCurrentPinballGame->tiltTargetYOffset = 0;
    }
}

void ComputeFlipperBounce(struct Vector16* ballPosition, struct Vector16* arg1, s16 flipperIx)
{
    struct Vector16 r7;
    u16 r4;
    s16 sp0;
    s16 sp12;
    bool32 flag;
    s16 i;
    int temp;
    int xx, yy;
    struct Vector16 r5 = { ballPosition->x * 128, ballPosition->y * 128 };
    struct Vector16 sp4 = { arg1->x, arg1->y };

    for (;;)
    {
        sp12 = gCurrentPinballGame->flipper[flipperIx].position - gCurrentPinballGame->flipper[flipperIx].prevPosition;
        
        if ((sp12 *= gCurrentPinballGame->flipper[flipperIx].ballSide) > 0)
        {
            if (gCurrentPinballGame->flipper[flipperIx].collisionFrameIndex < 7)
                r4 = gFlipperCollisionAngles[gCurrentPinballGame->flipper[flipperIx].collisionMapFrame - 1][0] +  ANGLE_90;
            else
                r4 = gFlipperCollisionAngles[gCurrentPinballGame->flipper[flipperIx].collisionMapFrame + 1][1] + -ANGLE_90; // This changes compilation, apparently
        }
        else
        {
            break;
        }

        r7.x = r5.x - 22 * 128;
        r7.y = r5.y - 48 * 128;

        xx = r7.x * r7.x;
        yy = r7.y * r7.y;
        temp = xx + yy - 0x240000;
        temp = Sqrt(temp * 4) / 2;
        ComputeFlipperLaunchVelocity(temp, flipperIx, &sp4, r4);

        if (sp4.x > 0x1C2)
            sp4.x = 0x1C2;
        else if (sp4.x < -0x1C2)
            sp4.x = -0x1C2;

        r5.x += sp4.x;
        r5.y += sp4.y;
        ballPosition->x = r5.x / 128;
        ballPosition->y = r5.y / 128;
        flag = FALSE;

        if (ballPosition->x < 50)
            break;

        for (i = gCurrentPinballGame->gravityStrengthIndex; i < 4; i++)
        {
            if (LookupFlipperCollisionMap(*ballPosition, i + 1, &sp0, flipperIx))
            {
                flag = TRUE;
                break;
            }
        }

        if (!flag)
            break;
    }

    if (sp12 <= 0)
    {
        gCurrentPinballGame->collisionResponseType = 5;
    }
    else
    {
        arg1->x = sp4.x;
        arg1->y = sp4.y;
    }
}

void ComputeWallReflection(u16 arg0, struct Vector16 *arg1, struct Vector16 *arg2)
{
    u16 angleOfFlippedArg1;
    s32 angleDelta, adjustedAngle;
    s16 angleSign;

    u16 halfMag;
    s32 halfMag2;

    s32 forwardMag, lateralMag, scaledForwardMag, scaledLateralMag;
    u32 vxSquared, vySquared;

    s32 curveDir, curveSign, curveDirScaledFactor, curveScaleFactor;
    u16 finalAngle;

    struct Vector32 tempVec;
    struct Vector16 tempVec2;

    angleOfFlippedArg1 = ArcTan2(-arg1->x, arg1->y);

    vxSquared = (arg1->x * arg1->x) + (arg1->y * arg1->y);
    halfMag = Sqrt(vxSquared * 4) /2;

    // Determine smallest angle difference and its direction
    if (angleOfFlippedArg1 > arg0)
    {
        angleDelta = angleOfFlippedArg1 - arg0;
        angleSign = -1;
    }
    else
    {
        angleDelta = arg0 - angleOfFlippedArg1;
        angleSign = 1;
    }

    //Note on angle representation:
    //0x4000 = 90 degrees
    //0x8000 = 180 degrees
    //0x10000 = 360 degrees

    //Clamps to the closest 180, with direction
    if (angleDelta > ANGLE_180)
    {
        angleDelta = ANGLE_360 - angleDelta;
        angleSign = -angleSign;
    }

    //Adds a 90 degree offset based on the delta factor
    adjustedAngle = arg0 + angleSign * ANGLE_90;

    // Apply signed adjustedAngle to stay in 0..0xFFFF
    if (adjustedAngle < 0)
        adjustedAngle = ANGLE_360 + adjustedAngle;

    // Project a curved arg2 delta based on half the magnitude
    // Note: the trigonometric functions return s16, typically scaled by 0x1000 or more
    lateralMag = MulSin(halfMag, angleDelta);
    forwardMag = MulCos(halfMag, angleDelta);

    // 'wall' sound if collision angle is high enough
    if (Cos(angleDelta)  > 0x1F3F)
    {
        if (forwardMag > 0x46)
            m4aSongNumStart(SE_WALL_HIT);

        if (forwardMag > 0x118
            && !gCurrentPinballGame->kickbackFiring
            && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            PlayRumble(6);
        }
    }

    if (gCurrentPinballGame->ballSpeed != 0)
        scaledForwardMag = forwardMag * 21;
    else
        scaledForwardMag = forwardMag * 26;

    forwardMag = scaledForwardMag / 100;
    scaledLateralMag = (lateralMag * 8) / 10;

    curveScaleFactor = gCurrentPinballGame->ball->spinSpeed * 0xEB8 / 0x2BC00;

    curveDir = -angleSign;
    curveDirScaledFactor = (curveDir * 25) * 1024;
    gCurrentPinballGame->ball->spinSpeed =
        curveDirScaledFactor * scaledLateralMag / 0xEB8
        + gCurrentPinballGame->ball->spinAcceleration;

/*
    tempVec.x = MulCos(forwardMag, arg0) + MulCos(lateralMag, adjustedAngle);
    tempVec.y = MulSin(-forwardMag, arg0) + MulSin(-lateralMag, adjustedAngle);
*/
    tempVec.x =  forwardMag * Cos(arg0);
    tempVec.y = -forwardMag * Sin(arg0);

    tempVec.x =  lateralMag * Cos(adjustedAngle) + tempVec.x;
    tempVec.y = -lateralMag * Sin(adjustedAngle) + tempVec.y;

    tempVec.x = tempVec.x / TRIG_SCALE;
    tempVec.y = tempVec.y / TRIG_SCALE;

    // With how the curveSign/curveScaleFactor are only used 'multiplied together'
    // with the tempVec calculation, the negations cancel out. - Shouldn't be needed.
    // Speculation is that this might have been a defensive code measure against
    // sign misbehavior, written by someone familar with assembly patterns.
    curveSign = 1;
    if (curveScaleFactor < 0)
    {
        curveSign = -1;
        curveScaleFactor = -curveScaleFactor;
    }
    curveSign = curveDir * curveSign;

    tempVec2.x = MulCos(curveSign * curveScaleFactor, adjustedAngle);
    tempVec2.y = MulSin( -curveSign * curveScaleFactor, adjustedAngle);

    vxSquared = tempVec.x * tempVec.x;
    vySquared = tempVec.y * tempVec.y;
    //Yes, the name is weird here. -- var reuse was needed for register match
    halfMag2 = vxSquared + vySquared;
    halfMag2 = Sqrt(halfMag2 * 4) /2;

    tempVec.x = tempVec2.x + tempVec.x;
    tempVec.y = tempVec2.y + tempVec.y;

    finalAngle = ArcTan2( tempVec.x, -tempVec.y);

    if (gMain.selectedField == FIELD_SAPPHIRE
        && gCurrentPinballGame->boardLayerDepth > 0
        && gCurrentPinballGame->ball->positionQ0.y < 0xD2)
    {
        tempVec.x = MulCos(halfMag, finalAngle);
        tempVec.y = MulSin(-halfMag, finalAngle);
    }
    else
    {
        tempVec.x = MulCos(halfMag2, finalAngle);
        tempVec.y = MulSin(-halfMag2, finalAngle);
    }

    ApplyBounceBackForce(arg0, &tempVec, angleOfFlippedArg1);

    arg2->x = tempVec.x;
    arg2->y = tempVec.y;
}

void ApplyBounceBackForce(u16 arg0, struct Vector32 *arg1, u16 arg2)
{
    s32 squaredSpeed;
    s16 x, y;
    s16 var0;

    struct Vector16 tempVec;

    x = gCurrentPinballGame->ball->velocity.x;
    y = gCurrentPinballGame->ball->velocity.y;
    squaredSpeed = (x * x) + (y * y);

    if (gCurrentPinballGame->collisionSurfaceType == 2)
    {
        if (gCurrentPinballGame->ball->positionQ1.x > 0xE0)
        {
            s32 value = -0x2A1C;
            var0 = value + arg2;
            arg0 = 0x6a1c;
        }
        else
        {
            s32 value = 0x55e4;
            var0 = value - arg2;
            arg0 = 0x15e4;
        }

        if (var0 >= 0 && var0 <= 0x1200 && squaredSpeed < 0x4000)
        {
            tempVec.x = 0;
            tempVec.y = 0;
        }
        else
        {
            arg1->x = arg1->x / 5;
            arg1->y = arg1->y / 5;

            gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 4) / 10;

            if ( gCurrentPinballGame->ballSpeed > 0)
            {
                tempVec.x = MulCos(230, arg0);
                tempVec.y = MulSin(-230, arg0);
            }
            else
            {
                tempVec.x = MulCos(285, arg0);
                tempVec.y = MulSin(-285, arg0);
            }

            gCurrentPinballGame->slingshotHitAnimTimer = 4;
            if (gCurrentPinballGame->ball->positionQ0.x < 120)
                gCurrentPinballGame->slingshotSideIndex = 0;
            else
                gCurrentPinballGame->slingshotSideIndex = 1;
        }
    }
    else
    {
        if (gCurrentPinballGame->collisionSurfaceType == 1)
        {
            arg1->x = arg1->x / 5;
            arg1->y = arg1->y / 5;

            if (arg0 > 0xA000 && arg0 < 0xE000)
            {
                tempVec.x = MulCos(60, arg0);
                tempVec.y = MulSin(-60, arg0);
            }
            else if (arg0 >= 0x1000 && arg0 <= 0x7000)
            {
                tempVec.x = MulCos(240, arg0);
                tempVec.y = MulSin(-240, arg0);
            }
            else
            {
                tempVec.x = MulCos(120, arg0);
                tempVec.y = MulSin(-120, arg0);
            }
        }
        else
        {
            tempVec.x = MulCos(gBounceBackForceMagnitudes[gCurrentPinballGame->collisionSurfaceType], arg0);
            tempVec.y = MulSin(-gBounceBackForceMagnitudes[gCurrentPinballGame->collisionSurfaceType], arg0);
        }
    }

    arg1->x = arg1->x + tempVec.x;
    arg1->y = arg1->y + tempVec.y;

    if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_INACTIVE)
    {
        s16 x2 = arg1->x;
        s16 xSign = 1;
        u16 angle;
        if (gCurrentPinballGame->captureState == MON_CAPTURE_SPECIAL_STATE_MON_HIT_IN_CATCH_MODE)
        {
            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_INACTIVE;
            squaredSpeed  = 0x80;
        }
        else
        {
            squaredSpeed  = 0x280;
        }

        if (x2 < 0)
        {
            x2 = -x2;
            xSign = -1;
        }

        if (x2 < 0x100)
            arg1->x = xSign * 256;

        gCurrentPinballGame->ball->spinSpeed = 0;
        angle = ArcTan2(arg1->x, -arg1->y);
        arg1->x = MulCos(squaredSpeed, angle);
        arg1->y = MulSin(-squaredSpeed, angle);
    }
}

u16 PixelWalkCollisionDetection(struct Vector16* ballPosition, struct Vector16 arg1) {
    struct Vector16 r8;

    u32 toggleShiftMode;
    s16 (*boardCollisionFunc)(struct Vector16*, u16*);
    u16 collisionAngle;

    r8.x = 1;
    r8.y = 1;

    if (arg1.x < 0)
    {
        r8.x = -1;
        arg1.x = -arg1.x;
    }

    if (arg1.y < 0)
    {
        r8.y = -1;
        arg1.y =  -arg1.y ;
    }

    if (arg1.x  > arg1.y)
        toggleShiftMode = FALSE;
    else
        toggleShiftMode = TRUE;

    gCurrentPinballGame->collisionResponseType = 0;
    gCurrentPinballGame->collisionSurfaceType = 0;

    boardCollisionFunc = BoardCollisionFuncts_086ACE0C[gMain.selectedField];

    do
    {
        if(boardCollisionFunc(ballPosition, &collisionAngle) != 0)
        {
            if (gCurrentPinballGame->collisionResponseType == 1)
            {
                if (gCurrentPinballGame->collisionSurfaceType == 3)
                {
                    u16 j;
                    u16 sp2_testRes;
                    struct Vector16 sp4_testPos;

                    for(j=0; j < 4; j++)
                    {
                        sp4_testPos.x = ballPosition->x + gWallEscapeOffsets[j].x;
                        sp4_testPos.y = ballPosition->y + gWallEscapeOffsets[j].y;

                        boardCollisionFunc(&sp4_testPos, &sp2_testRes);

                        if (gCurrentPinballGame->collisionResponseType == 1 && gCurrentPinballGame->collisionSurfaceType == 0)
                        {
                            ballPosition->x = sp4_testPos.x;
                            ballPosition->y = sp4_testPos.y;
                            collisionAngle = sp2_testRes;

                            break;
                        }
                    }
                }
            }
            else {
                break;
            }
        }
        else
        {
            gCurrentPinballGame->collisionResponseType = 0;

            if (CheckFlipperCollision(ballPosition, &collisionAngle) != 0
                || (gCurrentPinballGame->catchMonCollisionEnabled
                    && CheckCatchTargetCollision(ballPosition, &collisionAngle) != 0))
                break;
        }

        if (!(arg1.x > 0 || arg1.y > 0))
            break;

        if (!toggleShiftMode)
        {
            ballPosition->x = r8.x + ballPosition->x;
            arg1.x--;
            if (arg1.y > 0)
                toggleShiftMode = TRUE;
        }
        else
        {
            ballPosition->y = ballPosition->y + r8.y;
            arg1.y--;
            if (arg1.x > 0)
                toggleShiftMode = FALSE;
        }
    } while(1);

    return collisionAngle;
}

u16 CheckFlipperCollision(struct Vector16* ballPosition, u16* collisionAngle)
{
    u16 hasCollisionImpact;
    struct Vector16 leftFlipperBallRelativePosition;
    struct Vector16 rightFlipperBallRelativePosition;

    hasCollisionImpact = FALSE;

    leftFlipperBallRelativePosition.x = ballPosition->x - gBoardConfig.fieldLayout.leftFlipperOriginX * 2;
    rightFlipperBallRelativePosition.x = ballPosition->x - gBoardConfig.fieldLayout.rightFlipperOriginX * 2;
    leftFlipperBallRelativePosition.y = ballPosition->y - gBoardConfig.fieldLayout.flipperOriginY * 2;
    rightFlipperBallRelativePosition.y = leftFlipperBallRelativePosition.y;

    if (leftFlipperBallRelativePosition.y <= 95 && leftFlipperBallRelativePosition.y >= 0)
    {
        if (leftFlipperBallRelativePosition.x <= 95 && leftFlipperBallRelativePosition.x >= 0)
        {
            if(LookupFlipperCollisionMap(leftFlipperBallRelativePosition, gCurrentPinballGame->gravityStrengthIndex + 1, collisionAngle, SIDE_IX_LEFT))
            {
                gCurrentPinballGame->collisionResponseType = 3;
                hasCollisionImpact = TRUE;
            }
        }

        if (!hasCollisionImpact)
        {
            if (rightFlipperBallRelativePosition.x <= 95 && rightFlipperBallRelativePosition.x >= 0)
            {
                rightFlipperBallRelativePosition.x = 95 - rightFlipperBallRelativePosition.x;
                if (LookupFlipperCollisionMap(rightFlipperBallRelativePosition, gCurrentPinballGame->gravityStrengthIndex + 1, collisionAngle, SIDE_IX_RIGHT))
                {
                    gCurrentPinballGame->collisionResponseType = 4;
                    hasCollisionImpact = TRUE;
                }
            }
        }
    }

    return hasCollisionImpact;
}

u16 CheckCatchTargetCollision(struct Vector16 *ballPosition, u16 *collisionAngle)
{
    struct Vector16 vec1;
    u16 x, y;
    u16 res;
    u16 var0;

    res = FALSE;
    if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE)
    {
        vec1.x = ballPosition->x / 2 - gCurrentPinballGame->jirachiCenterX;
        vec1.y = ballPosition->y / 2 - gCurrentPinballGame->jirachiCenterY;
        if ((vec1.y >= 0 && vec1.y < 48) && (vec1.x >= 0 && vec1.x < 48))
        {
            s32 ix = vec1.y * 48 + vec1.x;
            var0 = gCatchTargetCollisionBitmap[ix];
            if (var0 & 0x80)
            {
                gCurrentPinballGame->collisionResponseType = 2;
                gCurrentPinballGame->collisionSurfaceType = 3;
                //Todo: fakematch; used to swap register order
                *collisionAngle = (var0 & 0x7F & var0) * 512;
                gCurrentPinballGame->captureSequenceFrame = 20;

                if (gCurrentPinballGame->captureFlashTimer)
                    gCurrentPinballGame->captureFlashTimer = 24;
                else
                    gCurrentPinballGame->captureFlashTimer = 20;

                // Only difference between these two branches is the played sound
                if (gCurrentPinballGame->currentSpecies == SPECIES_JIRACHI)
                {
                    if (gCurrentPinballGame->creatureHitCooldown == 0)
                    {
                        gCurrentPinballGame->creatureHitCount++;
                        if (gCurrentPinballGame->creatureHitCount == 3)
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_JIRACHI_CATCH_HIT;
                        }
                        else
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_MON_HIT_IN_CATCH_MODE;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_JIRACHI_CATCH_HIT;
                        }

                        gCurrentPinballGame->creatureHitCooldown = 4;
                    }

                    res = TRUE;
                    m4aSongNumStart(SE_JIRACHI_HIT);
                    PlayRumble(7);
                }
                else
                {
                    if (gCurrentPinballGame->creatureHitCooldown == 0)
                    {
                        gCurrentPinballGame->creatureHitCount++;
                        if (gCurrentPinballGame->creatureHitCount == 3)
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_CATCH_HIT;
                        }
                        else
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_MON_HIT_IN_CATCH_MODE;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_CATCH_HIT;
                        }

                        gCurrentPinballGame->creatureHitCooldown = 4;
                    }

                    res = TRUE;
                    m4aSongNumStart(SE_POKEMON_CATCH_HIT);
                    PlayRumble(7);
                }
            }
        }
    }

    return res;
}

void ProcessBonusTrapPhysics(void)
{
    struct Vector16 vec1;
    struct Vector32 vec2;
    int squaredDistance;
    u16 angle;
    u8 temp_adjust;

    vec1.x = gCurrentPinballGame->ball->positionQ1.x - 238;
    vec1.y = gCurrentPinballGame->ball->positionQ1.y - 558;
    squaredDistance = (vec1.x * vec1.x) + (vec1.y * vec1.y);

    if (squaredDistance < 1764 && (gCurrentPinballGame->gravityStrengthIndex & 1) == 0)
    {
        angle = ArcTan2(-vec1.x, vec1.y);
        temp_adjust = 30;
        vec2.x = MulCos(temp_adjust, angle);
        vec2.y = MulSin(-temp_adjust, angle);
        gCurrentPinballGame->ball->velocity.x = ((vec2.x * 100) + (98 * gCurrentPinballGame->ball->velocity.x)) / 100;
        gCurrentPinballGame->ball->velocity.y = ((vec2.y * 100) + (98 * gCurrentPinballGame->ball->velocity.y)) / 100;
    }

    if (gCurrentPinballGame->collisionMapScrollY < 20)
    {
        if (squaredDistance < 40)
        {
            gCurrentPinballGame->collisionMapScrollY++;
            gCurrentPinballGame->ball->scale = 0x100;
        }
        else
        {
            gCurrentPinballGame->ball->scale = 0x100;
            if (squaredDistance > 100)
                gCurrentPinballGame->collisionMapScrollY = 0;
        }
    }
    else
    {
        if (gCurrentPinballGame->collisionMapScrollY < 30)
        {
            gCurrentPinballGame->collisionMapScrollY++;
            gCurrentPinballGame->ball->scale = ((30 - gCurrentPinballGame->collisionMapScrollY) * 0x80) / 10 + 0x80;
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->spinSpeed = 0;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        }
        else
        {
            gCurrentPinballGame->collisionMapScrollY = 0;
            gCurrentPinballGame->ballCatchState = TRAP_CENTER_HOLE;
            if (gMain.selectedField == FIELD_RUBY)
                DispatchRubyCatchModeInit();
            else
                DispatchSapphireCatchModeInit();

            gCurrentPinballGame->collisionResponseType = 7;
            gCurrentPinballGame->ball->scale = 0x80;
        }
    }
}

/**
 * flipperBallRelativePosition: Ball distance from flipper x/y origin
 * gravityStrength: 1 to 4
 * collisionAngle: output value, representing the resulting angle from any collision result.
 * flipperIx: 0=Left, 1=Right
 */
u16 LookupFlipperCollisionMap(struct Vector16 relPos, s16 gravityStrength, u16 *collisionAngle, s16 flipperIx) {
    struct FlipperState* flipper;
    u16 hasCollisionImpact;
    int new_var;
    unsigned short ix;

    hasCollisionImpact = FALSE;

    ix = (relPos.y * 96) + relPos.x;
    flipper = &gCurrentPinballGame->flipper[flipperIx];

    flipper->collisionMapFrame = gFlipperCollisionFrameMapping[flipper->collisionFrameIndex][gravityStrength];

    if (COLLISION_TYPE_MASK & gBoardConfig.flipperCollisionData[flipper->collisionMapFrame][ix])
    {
        *collisionAngle = COLLISION_ANGLE_MASK & gBoardConfig.flipperCollisionData[flipper->collisionMapFrame][ix];
        if (flipperIx == SIDE_IX_RIGHT)
        {
            new_var = ANGLE_180;
            *collisionAngle = new_var - (*collisionAngle);
        }
        hasCollisionImpact = TRUE;
    }

    return hasCollisionImpact;
}

void ComputeFlipperLaunchVelocity(s32 arg0, s16 flipperIx, struct Vector16* arg2, u16 arg3)
{
    u16 angle;
    
    angle = gCurrentPinballGame->flipper[flipperIx].collisionMapFrame;
    
    if (gCurrentPinballGame->flipper[flipperIx].ballSide > 0)
    {
        if (!gCurrentPinballGame->flipperLaunchPending)
        {
            u16 var0;
            s32 scale;
            s16 temp_r2;
            s16 temp_r5;

            temp_r2 = gCurrentPinballGame->flipper[flipperIx].collisionMapFrame;
            temp_r5 = (temp_r2 - 2) * 25;
            arg0 -= temp_r5;

            if (arg0 < 2850)
            {
                var0 = 0x4800 - (arg0 - 2600) * 2048 / 600;
                scale = (arg0 - 2600) * 128 / 300 + 120;
            }
            else
            {
                var0 =
                    gFlipperLaunchVelocityParams[temp_r2][0] -
                    ((gFlipperLaunchVelocityParams[temp_r2][1] * (arg0 -2600)) / 5400);
                scale = ((arg0 -2600) * 348 / 5400) + 406;
            }

            if (flipperIx != SIDE_IX_LEFT)
                var0 = 0x8000 - var0;

            angle = (gCurrentPinballGame->ball->velocity.x * -0x600) / 0x80 +
                    (gCurrentPinballGame->ball->prevSpinSpeed * -0x180) / 0x100 +
                    var0;
            gCurrentPinballGame->flipperLaunchVelocity.x = MulCos(scale, angle);
            gCurrentPinballGame->flipperLaunchVelocity.y = MulSin(-scale, angle);
        }

        gCurrentPinballGame->flipperLaunchPending = TRUE;

        if (flipperIx)
            arg2->x = -gCurrentPinballGame->flipperLaunchVelocity.x;
        else
            arg2->x = gCurrentPinballGame->flipperLaunchVelocity.x;

        arg2->y = gCurrentPinballGame->flipperLaunchVelocity.y;
    }
    else
    {
        struct Vector16 vec1;
        s32 scale;
        u16 angle2;

        scale = arg0 / 20;
        vec1.x = MulCos(scale, arg3);
        vec1.y = MulNegSinSpecial(scale, arg3);

        arg2->x = vec1.x + arg2->x * 3 / 2;
        arg2->y = vec1.y + arg2->y * 3 / 2;

        angle2 = ArcTan2(arg2->x, -arg2->y);
        arg2->x = MulCos(scale, angle2);
        arg2->y = MulSin(-scale, angle2);
    }
}
