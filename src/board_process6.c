#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "constants/anglemath.h"
#include "constants/main_board.h"

extern u8 gCatchTargetCollisionBitmap[];
extern u16 gFlipperCollisionAngles[][2];
extern u16 gFlipperLaunchVelocityParams[][2];
extern s8 gFlipperCollisionFrameMapping[];


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
    struct Vector16 var0;
    struct Vector16 var1;
    struct Vector16 var2;
    s16 i;
    u16 r7;

    r7 = DetectBallCollision(&var0);
    switch (gCurrentPinballGame->collisionResponseType)
    {
        case 7:
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            break;
        case 1:
            ApplyTiltEffectOnCollision(&var0, &var1, r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= r7)
                {
                    var0.x += gWallCollisionPositionCorrection[i].correctionX;
                    var0.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 6:
            ApplyTiltEffectOnCollision(&var0, &var1,r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 2:
            ApplyTiltEffectOnCollision(&var0, &var1, r7);
            ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= r7)
                {
                    var0.x += gWallCollisionPositionCorrection[i].correctionX;
                    var0.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 3:
            ApplyTiltEffectOnCollision(&var0, &var1, r7);
            var0.x -= (gBoardConfig.fieldLayout.leftFlipperOriginX * 2);
            var0.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (gCurrentPinballGame->flipper[0].bounceApplied == 0)
            {
                ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->flipper[0].bounceApplied = 1;
            }
            else
            {
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            ComputeFlipperBounce(&var0, &var2, 0);
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->collisionResponseType == 5)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= r7)
                    {
                        var0.x += gFlipperCollisionAngleCorrection[i].correctionX;
                        var0.y += gFlipperCollisionAngleCorrection[i].correctionY;
                        break;
                    }
                }
            }
            var0.x += gBoardConfig.fieldLayout.leftFlipperOriginX * 2;
            var0.y += gBoardConfig.fieldLayout.flipperOriginY * 2;
            break;
        case 4:
            ApplyTiltEffectOnCollision(&var0, &var1, r7);
            var0.x -= (gBoardConfig.fieldLayout.rightFlipperOriginX * 2);
            var0.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (gCurrentPinballGame->flipper[1].bounceApplied == 0)
            {
                ComputeWallReflection(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->flipper[1].bounceApplied = 1;
            }
            else
            {
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            var0.x = 0x5f - var0.x;
            var2.x = -var2.x;
            ComputeFlipperBounce(&var0, &var2, 1);
            var2.x = -var2.x;
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->collisionResponseType == 5)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= r7)
                    {
                        var0.x -= gFlipperCollisionAngleCorrection[i].correctionX;
                        var0.y += gFlipperCollisionAngleCorrection[i].correctionY;
                        break;
                    }
                }
            }
            var0.x = 0x5f - var0.x;
            var0.x += gBoardConfig.fieldLayout.rightFlipperOriginX * 2;
            var0.y += gBoardConfig.fieldLayout.flipperOriginY * 2;
            break;
        default:
            if (gCurrentPinballGame->tiltTargetXOffset > 0)
            {
                if (gCurrentPinballGame->tiltLockoutActive != 1)
                {
                    gCurrentPinballGame->ball->velocity.x -=  4;
                    gCurrentPinballGame->tiltLockoutActive = 1;
                }
            }
            else if (gCurrentPinballGame->tiltTargetXOffset < 0)
            {
                if (gCurrentPinballGame->tiltLockoutActive != -1)
                {
                    gCurrentPinballGame->ball->velocity.x += 4;
                    gCurrentPinballGame->tiltLockoutActive = -1;
                }
            }
            if (gCurrentPinballGame->bonusTrapEnabled)
            {
                ProcessBonusTrapPhysics();
            }
    }
    if (gCurrentPinballGame->collisionResponseType != 0)
    {
        gCurrentPinballGame->ball->positionQ1.x = var0.x;
        gCurrentPinballGame->ball->positionQ1.y = var0.y;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x << 7;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y << 7;
    }
}

u16 DetectBallCollision(struct Vector16* param)
{
    u16 retVal;
    struct Vector16 test;
    test.x = gCurrentPinballGame->ball->positionQ1.x - gCurrentPinballGame->ball->prevPositionQ1.x;
    test.y = gCurrentPinballGame->ball->positionQ1.y - gCurrentPinballGame->ball->prevPositionQ1.y;
    param->x = gCurrentPinballGame->ball->prevPositionQ1.x;
    param->y = gCurrentPinballGame->ball->prevPositionQ1.y;
    retVal = PixelWalkCollisionDetection(param, test);

    gCurrentPinballGame->tiltInputCounterX = 0;
    gCurrentPinballGame->tiltInputCounterY = 0;

    if (!gCurrentPinballGame->collisionResponseType && (gCurrentPinballGame->tiltTargetXOffset || gCurrentPinballGame->tiltTargetYOffset))
    {
        param->x = gCurrentPinballGame->ball->positionQ1.x;
        param->y = gCurrentPinballGame->ball->positionQ1.y;
        test.x = gCurrentPinballGame->tiltTargetXOffset;
        test.y = gCurrentPinballGame->tiltTargetYOffset;
        retVal = PixelWalkCollisionDetection(param, test);
        gCurrentPinballGame->tiltInputCounterX = param->x - gCurrentPinballGame->ball->positionQ1.x;
        gCurrentPinballGame->tiltInputCounterY = param->y - gCurrentPinballGame->ball->positionQ1.y;
    }
    return retVal;
}

void ApplyTiltEffectOnCollision(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle)
{
    s16 cos;

    arg1->x = 0;
    arg1->y = 0;
    if (gCurrentPinballGame->tiltTargetXOffset)
    {
        arg0->x -= gCurrentPinballGame->tiltInputCounterX;
        if (gCurrentPinballGame->tiltTargetXOffset > 0)
        {
            cos = Cos(angle);
            if (cos < 0)
            {
                arg1->x = (Cos(angle) * 70) / 20000;
                gCurrentPinballGame->tiltLockoutTimer = 1;
            }
        }
        else if (gCurrentPinballGame->tiltTargetXOffset < 0)
        {
            cos = Cos(angle);
            if (cos > 0)
            {
                arg1->x = (Cos(angle) * 70) / 20000;
                gCurrentPinballGame->tiltLockoutTimer = 1;
            }
        }
    }

    if (gCurrentPinballGame->tiltTargetYOffset > 0)
    {
        arg0->y -= gCurrentPinballGame->tiltInputCounterY;
        if (gCurrentPinballGame->ball->positionQ0.y > 364)
        {
            if (gCurrentPinballGame->tiltTargetXOffset == 0)
                arg1->y = -(Sin(angle) * 130) / 20000;
            else
                arg1->y = -(Sin(angle) * 100) / 20000;
        }
        else
        {
            if (gCurrentPinballGame->tiltTargetXOffset == 0)
                arg1->y = -(Sin(angle) * 100) / 20000;
            else
                arg1->y = -(Sin(angle) * 75) / 20000;

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

void ComputeFlipperBounce(struct Vector16* arg0, struct Vector16* arg1, s16 arg2)
{
    struct Vector16 r7;
    u16 r4;
    s16 sp0;
    s16 sp12;
    bool32 flag;
    s16 i;
    int temp;
    int xx, yy;
    struct Vector16 r5 = { arg0->x * 128, arg0->y * 128 };
    struct Vector16 sp4 = { arg1->x, arg1->y };

    for (;;)
    {
        sp12 = gCurrentPinballGame->flipper[arg2].position - gCurrentPinballGame->flipper[arg2].prevPosition;
        
        if ((sp12 *= gCurrentPinballGame->flipper[arg2].ballSide) > 0)
        {
            if (gCurrentPinballGame->flipper[arg2].collisionFrameIndex < 7)
                r4 = gFlipperCollisionAngles[gCurrentPinballGame->flipper[arg2].collisionMapFrame - 1][0] +  0x4000;
            else
                r4 = gFlipperCollisionAngles[gCurrentPinballGame->flipper[arg2].collisionMapFrame + 1][1] + -0x4000; // This changes compilation, apparently
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
        ComputeFlipperLaunchVelocity(temp, arg2, &sp4, r4);

        if (sp4.x > 0x1C2)
            sp4.x = 0x1C2;
        else if (sp4.x < -0x1C2)
            sp4.x = -0x1C2;

        r5.x += sp4.x;
        r5.y += sp4.y;
        arg0->x = r5.x / 128;
        arg0->y = r5.y / 128;
        flag = FALSE;

        if (arg0->x < 50)
            break;

        for (i = gCurrentPinballGame->gravityStrengthIndex; i < 4; i++)
        {
            if (LookupFlipperCollisionMap(*arg0, i + 1, &sp0, arg2))
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
    lateralMag = halfMag * Sin(angleDelta) / 20000;
    forwardMag = halfMag * Cos(angleDelta) / 20000;

    // 'wall' sound if collision angle is high enough
    if (Cos(angleDelta)  > 0x1F3F)
    {
        if (forwardMag > 0x46)
            m4aSongNumStart(SE_WALL_HIT);

        if (forwardMag > 0x118
            && gCurrentPinballGame->kickbackFiring == 0
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

    tempVec.x =  forwardMag * Cos(arg0);
    tempVec.y = -forwardMag * Sin(arg0);

    tempVec.x =  lateralMag * Cos(adjustedAngle) + tempVec.x;
    tempVec.y = -lateralMag * Sin(adjustedAngle) + tempVec.y;

    tempVec.x = tempVec.x / 20000;
    tempVec.y = tempVec.y / 20000;

    // With how the curveSign/curveScaleFactor are only used 'multiplied together'
    // with the tempVec calculation, the negations cancel out. - Shouldn't be needed.
    // Speculation is that this might have been a defensive code measure against
    // sign misbehavior, written by someone familar with assembly patterns.
    curveSign = 1;
    if (curveScaleFactor < 0)
    {
        curveSign = curveSign -2;
        curveScaleFactor = -curveScaleFactor;
    }
    curveSign = curveDir * curveSign;

    tempVec2.x =  curveSign * curveScaleFactor * Cos(adjustedAngle) / 20000;
    tempVec2.y = -curveSign * curveScaleFactor * Sin(adjustedAngle) / 20000;

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
        tempVec.x =  halfMag * Cos(finalAngle) / 20000;
        tempVec.y = -halfMag * Sin(finalAngle) / 20000;
    }
    else
    {
        tempVec.x =  halfMag2 * Cos(finalAngle) / 20000;
        tempVec.y = -halfMag2 * Sin(finalAngle) / 20000;
    }

    ApplyBounceBackForce(arg0, &tempVec, angleOfFlippedArg1);

    arg2->x = tempVec.x;
    arg2->y = tempVec.y;
}

void ApplyBounceBackForce(u16 arg0, struct Vector32 *arg1, u16 arg2)
{
    const u16 VECTORSCALEDOWN = 20000;
    s32 vMagSquared;
    s16 x, y;
    s16 var0;

    struct Vector16 tempVec;

    x = gCurrentPinballGame->ball->velocity.x;
    y = gCurrentPinballGame->ball->velocity.y;
    vMagSquared = (x * x) + (y * y);

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

        if (var0 >= 0 && var0 <= 0x1200 && vMagSquared < 0x4000)
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
                tempVec.x = 230 * Cos(arg0) / VECTORSCALEDOWN;
                tempVec.y = -230 * Sin(arg0) / VECTORSCALEDOWN;
            }
            else
            {
                tempVec.x = 285 * Cos(arg0) / VECTORSCALEDOWN;
                tempVec.y = -285 * Sin(arg0) / VECTORSCALEDOWN;
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
                tempVec.x =  60 * Cos(arg0) / VECTORSCALEDOWN;
                tempVec.y = -60 * Sin(arg0) / VECTORSCALEDOWN;
            }
            else if (arg0 >= 0x1000 && arg0 <= 0x7000)
            {
                tempVec.x =  240 * Cos(arg0) / VECTORSCALEDOWN;
                tempVec.y = -240 * Sin(arg0) / VECTORSCALEDOWN;
            }
            else
            {
                tempVec.x =  120 * Cos(arg0) / VECTORSCALEDOWN;
                tempVec.y = -120 * Sin(arg0) / VECTORSCALEDOWN;
            }
        }
        else
        {
            tempVec.x =  gBounceBackForceMagnitudes[gCurrentPinballGame->collisionSurfaceType] * Cos(arg0) / VECTORSCALEDOWN;
            tempVec.y = -gBounceBackForceMagnitudes[gCurrentPinballGame->collisionSurfaceType] * Sin(arg0) / VECTORSCALEDOWN;
        }
    }

    arg1->x = arg1->x + tempVec.x;
    arg1->y = arg1->y + tempVec.y;

    if (gCurrentPinballGame->captureState != 0)
    {
        s16 x2 = arg1->x;
        s16 xSign = 1;
        u16 angle;
        if (gCurrentPinballGame->captureState == 1)
        {
            gCurrentPinballGame->captureState = 0;
            vMagSquared  = 0x80;
        }
        else
        {
            vMagSquared  = 0x280;
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
        arg1->x = vMagSquared  * Cos(angle) / VECTORSCALEDOWN;
        arg1->y = -vMagSquared  * Sin(angle) / VECTORSCALEDOWN;
    }
}

u16 PixelWalkCollisionDetection(struct Vector16* arg0, struct Vector16 arg1) {
    struct Vector16 r8;

    u32 toggleShiftMode;
    s16 (*spC)(struct Vector16*, u16*);
    u16 sp0_return;

    r8.x =1;
    r8.y =1;

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
        toggleShiftMode = 0;
    else
        toggleShiftMode = 1;

    gCurrentPinballGame->collisionResponseType = 0;
    gCurrentPinballGame->collisionSurfaceType = 0;

    spC = BoardCollisionFuncts_086ACE0C[gMain.selectedField];

    do
    {
        if(spC(arg0, &sp0_return) != 0)
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
                        sp4_testPos.x = arg0->x + gWallEscapeOffsets[j].x;
                        sp4_testPos.y = arg0->y + gWallEscapeOffsets[j].y;

                        spC(&sp4_testPos, &sp2_testRes);

                        if (gCurrentPinballGame->collisionResponseType == 1 && gCurrentPinballGame->collisionSurfaceType == 0)
                        {
                            arg0->x = sp4_testPos.x;
                            arg0->y = sp4_testPos.y;
                            sp0_return = sp2_testRes;

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

            if (CheckFlipperCollision(arg0, &sp0_return) != 0 ||
                (gCurrentPinballGame->jirachiCollisionEnabled != 0 && CheckCatchTargetCollision(arg0, &sp0_return) != 0))
                break;
        }

        if (!(arg1.x > 0 || arg1.y > 0))
            break;

        if (toggleShiftMode == 0)
        {
            arg0->x = r8.x + arg0->x;
            arg1.x--;
            if (arg1.y >0)
                toggleShiftMode = 1;
        }
        else
        {
            arg0->y = arg0->y + r8.y;
            arg1.y--;
            if (arg1.x > 0)
                toggleShiftMode = 0;
        }
    } while(1);

    return sp0_return;
}

u16 CheckFlipperCollision(struct Vector16* arg0, u16* arg1)
{
    u16 res;
    struct Vector16 vec1;
    struct Vector16 vec2;

    res = 0;

    vec1.x = arg0->x - gBoardConfig.fieldLayout.leftFlipperOriginX * 2;
    vec2.x = arg0->x - gBoardConfig.fieldLayout.rightFlipperOriginX * 2;
    vec1.y = arg0->y - gBoardConfig.fieldLayout.flipperOriginY * 2;
    vec2.y = vec1.y;

    if (vec1.y <= 95 && vec1.y >= 0)
    {
        if (vec1.x <= 95 && vec1.x >= 0)
        {
            if(LookupFlipperCollisionMap(vec1, gCurrentPinballGame->gravityStrengthIndex + 1, arg1, 0))
            {
                gCurrentPinballGame->collisionResponseType = 3;
                res = 1;
            }
        }

        if (res == 0)
        {
            if (vec2.x <= 95 && vec2.x >= 0)
            {
                vec2.x = 95 - vec2.x;
                if (LookupFlipperCollisionMap(vec2, gCurrentPinballGame->gravityStrengthIndex + 1, arg1, 1))
                {
                    gCurrentPinballGame->collisionResponseType = 4;
                    res = 1;
                }
            }
        }
    }

    return res;
}


u16 CheckCatchTargetCollision(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    u16 x, y;
    u16 res;
    u16 var0;

    res = 0;
    if (gCurrentPinballGame->captureState != 2)
    {
        vec1.x = arg0->x / 2 - gCurrentPinballGame->jirachiCenterX;
        vec1.y = arg0->y / 2 - gCurrentPinballGame->jirachiCenterY;
        if ((vec1.y >= 0 && vec1.y < 48) && (vec1.x >= 0 && vec1.x < 48))
        {
            s32 ix = vec1.y * 48 + vec1.x;
            var0 = gCatchTargetCollisionBitmap[ix];
            if (var0 & 0x80)
            {
                gCurrentPinballGame->collisionResponseType = 2;
                gCurrentPinballGame->collisionSurfaceType = 3;
                //Todo: fakematch; used to swap register order
                *arg1 = (var0 & 0x7F & var0) * 512;
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
                            gCurrentPinballGame->captureState = 2;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        }
                        else
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = 1;
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        }

                        gCurrentPinballGame->creatureHitCooldown = 4;
                    }

                    res = 1;
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
                            gCurrentPinballGame->captureState = 2;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        }
                        else
                        {
                            gCurrentPinballGame->catchLights[gCurrentPinballGame->creatureHitCount - 1] = 3;
                            gCurrentPinballGame->captureState = 1;
                            gCurrentPinballGame->scoreAddedInFrame = 10000;
                        }

                        gCurrentPinballGame->creatureHitCooldown = 4;
                    }

                    res = 1;
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
    int squaredMagnitude;
    u16 angle;
    u8 temp_adjust;

    vec1.x = gCurrentPinballGame->ball->positionQ1.x - 238;
    vec1.y = gCurrentPinballGame->ball->positionQ1.y - 558;
    squaredMagnitude = (vec1.x * vec1.x) + (vec1.y * vec1.y);

    if (squaredMagnitude < 1764 && (gCurrentPinballGame->gravityStrengthIndex & 1) == 0)
    {
        angle = ArcTan2(-vec1.x, vec1.y);
        temp_adjust = 30;
        vec2.x = (temp_adjust  * Cos(angle)) / 20000;
        vec2.y = (-temp_adjust * Sin(angle)) / 20000;
        gCurrentPinballGame->ball->velocity.x = ((vec2.x * 100) + (98 * gCurrentPinballGame->ball->velocity.x)) / 100;
        gCurrentPinballGame->ball->velocity.y = ((vec2.y * 100) + (98 * gCurrentPinballGame->ball->velocity.y)) / 100;
    }

    if (gCurrentPinballGame->collisionMapScrollY < 20)
    {
        if (squaredMagnitude < 40)
        {
            gCurrentPinballGame->collisionMapScrollY++;
            gCurrentPinballGame->ball->scale = 0x100;
        }
        else
        {
            gCurrentPinballGame->ball->scale = 0x100;
            if (squaredMagnitude > 100)
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

u16 LookupFlipperCollisionMap(struct Vector16 r0, s16 r1, u16 *r2, s16 r3) {
    struct FlipperState* flipper;
    u16 res;
    int new_var;
    unsigned short ix;

    res = 0;
    
    ix = (r0.y * 96) + r0.x; 
    flipper = &gCurrentPinballGame->flipper[r3]; 

    flipper->collisionMapFrame = gFlipperCollisionFrameMapping[r1 + (flipper->collisionFrameIndex * 5)];
    
    if (0xF & (&gBoardConfig.flipperCollisionData[flipper->collisionMapFrame * 0x2400])[ix])
    {
        *r2 = 0xFFF0 & (&gBoardConfig.flipperCollisionData[flipper->collisionMapFrame * 0x2400])[ix];
        if (r3 == 1)
        {
            new_var = 0x8000;
            *r2 = new_var - (*r2);
        }
        res = 1;
    }

    return res;
}

void ComputeFlipperLaunchVelocity(s32 arg0, s16 arg1, struct Vector16* arg2, u16 arg3)
{
    u16 angle;
    
    angle = gCurrentPinballGame->flipper[arg1].collisionMapFrame;
    
    if (gCurrentPinballGame->flipper[arg1].ballSide > 0)
    {
        if (gCurrentPinballGame->flipperLaunchPending == 0)
        {
            u16 var0;
            s32 scale;
            s16 temp_r2;
            s16 temp_r5;

            temp_r2 = gCurrentPinballGame->flipper[arg1].collisionMapFrame;
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

            if (arg1)
                var0 = 0x8000 - var0;

            angle = (gCurrentPinballGame->ball->velocity.x * -0x600) / 0x80 +
                    (gCurrentPinballGame->ball->prevSpinSpeed * -0x180) / 0x100 +
                    var0;
            gCurrentPinballGame->flipperLaunchVelocity.x = scale * Cos(angle) / 20000;
            gCurrentPinballGame->flipperLaunchVelocity.y = -scale * Sin(angle) / 20000;
        }

        gCurrentPinballGame->flipperLaunchPending = 1;

        if (arg1)
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
        vec1.x = scale * Cos(arg3) / 20000;
        vec1.y = -(scale * Sin(arg3)) / 20000;

        arg2->x = vec1.x + arg2->x * 3 / 2;
        arg2->y = vec1.y + arg2->y * 3 / 2;

        angle2 = ArcTan2(arg2->x, -arg2->y);
        arg2->x = scale * Cos(angle2) / 20000;
        arg2->y = -scale * Sin(angle2) / 20000;
    }
}