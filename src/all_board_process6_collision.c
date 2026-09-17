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

void ComputeFlipperLaunchVelocity(s32 arg0, s16 flipperIx, struct Vector16* arg2, u16 arg3);

void InitFrameProcess6_Collision_AllBoards()
{
	gCurrentPinballGame->collisionCooldownTimer = 60;
}

void UpdateFrameProcess6_Collision_AllBoards()
{
    struct Vector16 ballPosition;
    struct Vector16 tiltVelocityDelta;
    struct Vector16 collisionVelocity;
    s16 i;
    u16 collisionAngle;

    collisionAngle = DetectBallCollision(&ballPosition);
    switch (gCurrentPinballGame->collisionResolutionState)
    {
        case COLLISION_RESOLUTION_STATE_STOP_BALL:
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            break;
        case COLLISION_RESOLUTION_STATE_PIXEL_WALK_CONTINUING:
            ApplyTiltEffectOnCollision(&ballPosition, &tiltVelocityDelta, collisionAngle);
            ComputeWallReflection(collisionAngle, &gCurrentPinballGame->ball->velocity, &collisionVelocity);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= collisionAngle)
                {
                    ballPosition.x += gWallCollisionPositionCorrection[i].correctionX;
                    ballPosition.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = collisionVelocity.x + tiltVelocityDelta.x;
            gCurrentPinballGame->ball->velocity.y = collisionVelocity.y + tiltVelocityDelta.y;
            break;
        case COLLISION_RESOLUTION_STATE_UNUSED:
            ApplyTiltEffectOnCollision(&ballPosition, &tiltVelocityDelta,collisionAngle);
            ComputeWallReflection(collisionAngle, &gCurrentPinballGame->ball->velocity, &collisionVelocity);
            gCurrentPinballGame->ball->velocity.x = collisionVelocity.x + tiltVelocityDelta.x;
            gCurrentPinballGame->ball->velocity.y = collisionVelocity.y + tiltVelocityDelta.y;
            break;
        case COLLISION_RESOLUTION_STATE_PIXEL_WALK_ONE_STEP:
            ApplyTiltEffectOnCollision(&ballPosition, &tiltVelocityDelta, collisionAngle);
            ComputeWallReflection(collisionAngle, &gCurrentPinballGame->ball->velocity, &collisionVelocity);
            for (i = 0; i < 9; i++)
            {
                if (gWallCollisionPositionCorrection[i].angleThreshold <= collisionAngle)
                {
                    ballPosition.x += gWallCollisionPositionCorrection[i].correctionX;
                    ballPosition.y += gWallCollisionPositionCorrection[i].correctionY;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = collisionVelocity.x + tiltVelocityDelta.x;
            gCurrentPinballGame->ball->velocity.y = collisionVelocity.y + tiltVelocityDelta.y;
            break;
        case COLLISION_RESOLUTION_STATE_LEFT_FLIPPER:
            ApplyTiltEffectOnCollision(&ballPosition, &tiltVelocityDelta, collisionAngle);
            ballPosition.x -= (gBoardConfig.fieldLayout.leftFlipperOriginX * 2);
            ballPosition.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (!gCurrentPinballGame->flipper[SIDE_IX_LEFT].bounceApplied)
            {
                ComputeWallReflection(collisionAngle, &gCurrentPinballGame->ball->velocity, &collisionVelocity);
                gCurrentPinballGame->flipper[SIDE_IX_LEFT].bounceApplied = TRUE;
            }
            else
            {
                collisionVelocity.x = gCurrentPinballGame->ball->velocity.x;
                collisionVelocity.y = gCurrentPinballGame->ball->velocity.y;
            }
            ComputeFlipperBounce(&ballPosition, &collisionVelocity, SIDE_IX_LEFT);
            gCurrentPinballGame->ball->velocity.x = collisionVelocity.x + tiltVelocityDelta.x;
            gCurrentPinballGame->ball->velocity.y = collisionVelocity.y + tiltVelocityDelta.y;
            if (gCurrentPinballGame->collisionResolutionState == COLLISION_RESOLUTION_STATE_PASSIVE_FLIPPER_COLLISION)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= collisionAngle)
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
        case COLLISION_RESOLUTION_STATE_RIGHT_FLIPPER:
            ApplyTiltEffectOnCollision(&ballPosition, &tiltVelocityDelta, collisionAngle);
            ballPosition.x -= (gBoardConfig.fieldLayout.rightFlipperOriginX * 2);
            ballPosition.y -= (gBoardConfig.fieldLayout.flipperOriginY * 2);
            if (!gCurrentPinballGame->flipper[SIDE_IX_RIGHT].bounceApplied)
            {
                ComputeWallReflection(collisionAngle, &gCurrentPinballGame->ball->velocity, &collisionVelocity);
                gCurrentPinballGame->flipper[SIDE_IX_RIGHT].bounceApplied = TRUE;
            }
            else
            {
                collisionVelocity.x = gCurrentPinballGame->ball->velocity.x;
                collisionVelocity.y = gCurrentPinballGame->ball->velocity.y;
            }
            ballPosition.x = 0x5f - ballPosition.x;
            collisionVelocity.x = -collisionVelocity.x;
            ComputeFlipperBounce(&ballPosition, &collisionVelocity, SIDE_IX_RIGHT);
            collisionVelocity.x = -collisionVelocity.x;
            gCurrentPinballGame->ball->velocity.x = collisionVelocity.x + tiltVelocityDelta.x;
            gCurrentPinballGame->ball->velocity.y = collisionVelocity.y + tiltVelocityDelta.y;
            if (gCurrentPinballGame->collisionResolutionState == COLLISION_RESOLUTION_STATE_PASSIVE_FLIPPER_COLLISION)
            {
                for (i = 0; i < 4; i++)
                {
                    if (gFlipperCollisionAngleCorrection[i].angleThreshold <= collisionAngle)
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
    if (gCurrentPinballGame->collisionResolutionState != COLLISION_RESOLUTION_STATE_NONE)
    {
        gCurrentPinballGame->ball->positionQ1.x = ballPosition.x;
        gCurrentPinballGame->ball->positionQ1.y = ballPosition.y;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x << 7;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y << 7;
    }
}

u16 DetectBallCollision(struct Vector16* ballPosition)
{
    u16 retCollisionAngle;
    struct Vector16 movementDelta;
    movementDelta.x = gCurrentPinballGame->ball->positionQ1.x - gCurrentPinballGame->ball->prevPositionQ1.x;
    movementDelta.y = gCurrentPinballGame->ball->positionQ1.y - gCurrentPinballGame->ball->prevPositionQ1.y;
    ballPosition->x = gCurrentPinballGame->ball->prevPositionQ1.x;
    ballPosition->y = gCurrentPinballGame->ball->prevPositionQ1.y;
    retCollisionAngle = PixelWalkCollisionDetection(ballPosition, movementDelta);

    gCurrentPinballGame->tiltInputCounterX = 0;
    gCurrentPinballGame->tiltInputCounterY = 0;

    if (gCurrentPinballGame->collisionResolutionState == COLLISION_RESOLUTION_STATE_NONE
        && (gCurrentPinballGame->tiltTargetXOffset || gCurrentPinballGame->tiltTargetYOffset))
    {
        ballPosition->x = gCurrentPinballGame->ball->positionQ1.x;
        ballPosition->y = gCurrentPinballGame->ball->positionQ1.y;
        movementDelta.x = gCurrentPinballGame->tiltTargetXOffset;
        movementDelta.y = gCurrentPinballGame->tiltTargetYOffset;
        retCollisionAngle = PixelWalkCollisionDetection(ballPosition, movementDelta);
        gCurrentPinballGame->tiltInputCounterX = ballPosition->x - gCurrentPinballGame->ball->positionQ1.x;
        gCurrentPinballGame->tiltInputCounterY = ballPosition->y - gCurrentPinballGame->ball->positionQ1.y;
    }
    return retCollisionAngle;
}

void ApplyTiltEffectOnCollision(struct Vector16 *ballPosition, struct Vector16 *tiltVelocityDelta, u16 angle)
{
    s16 cos;

    tiltVelocityDelta->x = 0;
    tiltVelocityDelta->y = 0;
    if (gCurrentPinballGame->tiltTargetXOffset)
    {
        ballPosition->x -= gCurrentPinballGame->tiltInputCounterX;
        if (gCurrentPinballGame->tiltTargetXOffset > 0)
        {
            cos = Cos(angle);
            if (cos < 0)
            {
                tiltVelocityDelta->x = MulCos(70, angle);
                gCurrentPinballGame->tiltLockoutTimer = 1;
            }
        }
        else if (gCurrentPinballGame->tiltTargetXOffset < 0)
        {
            cos = Cos(angle);
            if (cos > 0)
            {
                tiltVelocityDelta->x = MulCos(70, angle);
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
                tiltVelocityDelta->y = MulSin(-130, angle);
            else
                tiltVelocityDelta->y = MulNegSinSpecial(100, angle);
        }
        else
        {
            if (gCurrentPinballGame->tiltTargetXOffset == 0)
                tiltVelocityDelta->y = MulNegSinSpecial(100, angle);
            else
                tiltVelocityDelta->y = MulSin(-75, angle);

            if (tiltVelocityDelta->y >= 90)
                gCurrentPinballGame->ball->velocity.x /= 4;
            else if (tiltVelocityDelta->y >= 70)
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

void ComputeFlipperBounce(struct Vector16* ballPosition, struct Vector16* collisionVelocity, s16 flipperIx)
{
    struct Vector16 flipperRelativeBallPosition;
    u16 flipperCollisionAngle;
    s16 collisionAngle;
    s16 sp12;
    bool32 flag;
    s16 i;
    int flipperRelativeBallDistance;
    int xx, yy;
    struct Vector16 ballPosition_Q7 = { ballPosition->x * 128, ballPosition->y * 128 };
    struct Vector16 velocity = { collisionVelocity->x, collisionVelocity->y };

    for (;;)
    {
        sp12 = gCurrentPinballGame->flipper[flipperIx].position - gCurrentPinballGame->flipper[flipperIx].prevPosition;

        if ((sp12 *= gCurrentPinballGame->flipper[flipperIx].ballSide) > 0)
        {
            if (gCurrentPinballGame->flipper[flipperIx].collisionFrameIndex < 7)
                flipperCollisionAngle = gFlipperCollisionAngles[gCurrentPinballGame->flipper[flipperIx].collisionMapFrame - 1][0] +  ANGLE_90;
            else
                flipperCollisionAngle = gFlipperCollisionAngles[gCurrentPinballGame->flipper[flipperIx].collisionMapFrame + 1][1] + -ANGLE_90; // This changes compilation, apparently
        }
        else
        {
            break;
        }

        flipperRelativeBallPosition.x = ballPosition_Q7.x - 22 * 128;
        flipperRelativeBallPosition.y = ballPosition_Q7.y - 48 * 128;

        xx = flipperRelativeBallPosition.x * flipperRelativeBallPosition.x;
        yy = flipperRelativeBallPosition.y * flipperRelativeBallPosition.y;
        flipperRelativeBallDistance = xx + yy - 0x240000;
        flipperRelativeBallDistance = Sqrt(flipperRelativeBallDistance * 4) / 2;
        ComputeFlipperLaunchVelocity(flipperRelativeBallDistance, flipperIx, &velocity, flipperCollisionAngle);

        // Cap horizontal speed
        if (velocity.x > 0x1C2)
            velocity.x = 0x1C2;
        else if (velocity.x < -0x1C2)
            velocity.x = -0x1C2;

        ballPosition_Q7.x += velocity.x;
        ballPosition_Q7.y += velocity.y;
        ballPosition->x = ballPosition_Q7.x / 128;
        ballPosition->y = ballPosition_Q7.y / 128;
        flag = FALSE;

        if (ballPosition->x < 50)
            break;

        for (i = gCurrentPinballGame->gravityStrengthIndex; i < 4; i++)
        {
            if (LookupFlipperCollisionMap(*ballPosition, i + 1, &collisionAngle, flipperIx))
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
        gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_PASSIVE_FLIPPER_COLLISION;
    }
    else
    {
        collisionVelocity->x = velocity.x;
        collisionVelocity->y = velocity.y;
    }
}

void ComputeWallReflection(u16 collisionAngle, struct Vector16 *inputVelocity, struct Vector16 *outputVelocity)
{
    u16 incomingVelocityAngle;
    s32 collisionAngleDelta, adjustedAngle;
    s16 angleSign;

    u16 halfMag;
    s32 halfMag2;

    s32 forwardMag, lateralMag, scaledForwardMag, scaledLateralMag;
    u32 vxSquared, vySquared;

    s32 curveDir, curveSign, curveDirScaledFactor, curveScaleFactor;
    u16 finalAngle;

    struct Vector32 tempVec;
    struct Vector16 tempVec2;

    incomingVelocityAngle = ArcTan2(-inputVelocity->x, inputVelocity->y);

    vxSquared = (inputVelocity->x * inputVelocity->x) + (inputVelocity->y * inputVelocity->y);
    halfMag = Sqrt(vxSquared * 4) /2;

    // Determine smallest angle difference and its direction
    if (incomingVelocityAngle > collisionAngle)
    {
        collisionAngleDelta = incomingVelocityAngle - collisionAngle;
        angleSign = -1;
    }
    else
    {
        collisionAngleDelta = collisionAngle - incomingVelocityAngle;
        angleSign = 1;
    }

    //Note on angle representation:
    //0x4000 = 90 degrees
    //0x8000 = 180 degrees
    //0x10000 = 360 degrees

    //Clamps to the closest 180, with direction
    if (collisionAngleDelta > ANGLE_180)
    {
        collisionAngleDelta = ANGLE_360 - collisionAngleDelta;
        angleSign = -angleSign;
    }

    //Adds a 90 degree offset based on the delta factor
    adjustedAngle = collisionAngle + angleSign * ANGLE_90;

    // Apply signed adjustedAngle to stay in 0..0xFFFF
    if (adjustedAngle < 0)
        adjustedAngle = ANGLE_360 + adjustedAngle;

    // Project a curved arg2 delta based on half the magnitude
    // Note: the trigonometric functions return s16, typically scaled by 0x1000 or more
    lateralMag = MulSin(halfMag, collisionAngleDelta);
    forwardMag = MulCos(halfMag, collisionAngleDelta);

    // 'wall' sound if collision angle is high enough
    if (Cos(collisionAngleDelta)  > 0x1F3F)
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
    tempVec.x =  forwardMag * Cos(collisionAngle);
    tempVec.y = -forwardMag * Sin(collisionAngle);

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

    ApplyBounceBackForce(collisionAngle, &tempVec, incomingVelocityAngle);

    outputVelocity->x = tempVec.x;
    outputVelocity->y = tempVec.y;
}

void ApplyBounceBackForce(u16 collisionAngle, struct Vector32 *outputVelocity, u16 incomingVelocityAngle)
{
    s32 squaredSpeed;
    s16 x, y;
    s16 var0;

    struct Vector16 tempVec;

    x = gCurrentPinballGame->ball->velocity.x;
    y = gCurrentPinballGame->ball->velocity.y;
    squaredSpeed = (x * x) + (y * y);

    if (gCurrentPinballGame->collisionBounceBehaviorType == COLLISION_BOUNCE_BEHAVIOR_TYPE_SLINGSHOT)
    {
        if (gCurrentPinballGame->ball->positionQ1.x > 0xE0)
        {
            s32 value = -0x2A1C;
            var0 = value + incomingVelocityAngle;
            collisionAngle = 0x6a1c;
        }
        else
        {
            s32 value = 0x55e4;
            var0 = value - incomingVelocityAngle;
            collisionAngle = 0x15e4;
        }

        if (var0 >= 0 && var0 <= 0x1200 && squaredSpeed < 0x4000)
        {
            tempVec.x = 0;
            tempVec.y = 0;
        }
        else
        {
            outputVelocity->x = outputVelocity->x / 5;
            outputVelocity->y = outputVelocity->y / 5;

            gCurrentPinballGame->ball->spinSpeed = (gCurrentPinballGame->ball->spinSpeed * 4) / 10;

            if ( gCurrentPinballGame->ballSpeed > 0)
            {
                tempVec.x = MulCos(230, collisionAngle);
                tempVec.y = MulSin(-230, collisionAngle);
            }
            else
            {
                tempVec.x = MulCos(285, collisionAngle);
                tempVec.y = MulSin(-285, collisionAngle);
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
        if (gCurrentPinballGame->collisionBounceBehaviorType == COLLISION_BOUNCE_BEHAVIOR_TYPE_BUMPER)
        {
            outputVelocity->x = outputVelocity->x / 5;
            outputVelocity->y = outputVelocity->y / 5;

            if (collisionAngle > 0xA000 && collisionAngle < 0xE000)
            {
                tempVec.x = MulCos(60, collisionAngle);
                tempVec.y = MulSin(-60, collisionAngle);
            }
            else if (collisionAngle >= 0x1000 && collisionAngle <= 0x7000)
            {
                tempVec.x = MulCos(240, collisionAngle);
                tempVec.y = MulSin(-240, collisionAngle);
            }
            else
            {
                tempVec.x = MulCos(120, collisionAngle);
                tempVec.y = MulSin(-120, collisionAngle);
            }
        }
        else
        {
            tempVec.x = MulCos(gBounceBackForceMagnitudes[gCurrentPinballGame->collisionBounceBehaviorType], collisionAngle);
            tempVec.y = MulSin(-gBounceBackForceMagnitudes[gCurrentPinballGame->collisionBounceBehaviorType], collisionAngle);
        }
    }

    outputVelocity->x = outputVelocity->x + tempVec.x;
    outputVelocity->y = outputVelocity->y + tempVec.y;

    if (gCurrentPinballGame->captureState != MON_CAPTURE_SPECIAL_STATE_INACTIVE)
    {
        s16 x2 = outputVelocity->x;
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
            outputVelocity->x = xSign * 256;

        gCurrentPinballGame->ball->spinSpeed = 0;
        angle = ArcTan2(outputVelocity->x, -outputVelocity->y);
        outputVelocity->x = MulCos(squaredSpeed, angle);
        outputVelocity->y = MulSin(-squaredSpeed, angle);
    }
}

u16 PixelWalkCollisionDetection(struct Vector16* ballPosition, struct Vector16 movementDelta) {
    struct Vector16 stepDirection;

    u32 toggleShiftMode;
    s16 (*boardCollisionFunc)(struct Vector16*, u16*);
    u16 collisionAngle;

    stepDirection.x = 1;
    stepDirection.y = 1;

    if (movementDelta.x < 0)
    {
        stepDirection.x = -1;
        movementDelta.x = -movementDelta.x;
    }

    if (movementDelta.y < 0)
    {
        stepDirection.y = -1;
        movementDelta.y =  -movementDelta.y ;
    }

    if (movementDelta.x  > movementDelta.y)
        toggleShiftMode = FALSE;
    else
        toggleShiftMode = TRUE;

    gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_NONE;
    gCurrentPinballGame->collisionBounceBehaviorType = COLLISION_BOUNCE_BEHAVIOR_TYPE_NORMAL;

    boardCollisionFunc = BoardCollisionFuncts_086ACE0C[gMain.selectedField];

    do
    {
        if(boardCollisionFunc(ballPosition, &collisionAngle) != 0)
        {
            if (gCurrentPinballGame->collisionResolutionState == COLLISION_RESOLUTION_STATE_PIXEL_WALK_CONTINUING)
            {
                // Prevent Wall penetration. When an outer wall collision is detected, find an associated inner wall
                // collision point, and continue from there.
                if (gCurrentPinballGame->collisionBounceBehaviorType == COLLISION_BOUNCE_BEHAVIOR_TYPE_OUTER_WALL)
                {
                    u16 j;
                    u16 sp2_testRes;
                    struct Vector16 sp4_testPos;

                    for(j=0; j < 4; j++)
                    {
                        sp4_testPos.x = ballPosition->x + gWallEscapeOffsets[j].x;
                        sp4_testPos.y = ballPosition->y + gWallEscapeOffsets[j].y;

                        boardCollisionFunc(&sp4_testPos, &sp2_testRes);

                        if (gCurrentPinballGame->collisionResolutionState == COLLISION_RESOLUTION_STATE_PIXEL_WALK_CONTINUING && gCurrentPinballGame->collisionBounceBehaviorType == COLLISION_BOUNCE_BEHAVIOR_TYPE_NORMAL)
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
            gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_NONE;

            if (CheckFlipperCollision(ballPosition, &collisionAngle) != 0
                || (gCurrentPinballGame->catchMonCollisionEnabled
                    && CheckCatchTargetCollision(ballPosition, &collisionAngle) != 0))
                break;
        }

        if (!(movementDelta.x > 0 || movementDelta.y > 0))
            break;

        if (!toggleShiftMode)
        {
            ballPosition->x = stepDirection.x + ballPosition->x;
            movementDelta.x--;
            if (movementDelta.y > 0)
                toggleShiftMode = TRUE;
        }
        else
        {
            ballPosition->y = ballPosition->y + stepDirection.y;
            movementDelta.y--;
            if (movementDelta.x > 0)
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
                gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_LEFT_FLIPPER;
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
                    gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_RIGHT_FLIPPER;
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
                gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_PIXEL_WALK_ONE_STEP;
                gCurrentPinballGame->collisionBounceBehaviorType = COLLISION_BOUNCE_BEHAVIOR_TYPE_OUTER_WALL;
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
                            gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->creatureHitCount - 1] = MODE_PROGRESS_LAMP_CATCH_LIT;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_JIRACHI_CATCH_HIT;
                        }
                        else
                        {
                            gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->creatureHitCount - 1] = MODE_PROGRESS_LAMP_CATCH_LIT;
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
                            gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->creatureHitCount - 1] = MODE_PROGRESS_LAMP_CATCH_LIT;
                            gCurrentPinballGame->captureState = MON_CAPTURE_SPECIAL_STATE_CAPTURE_CUTSCENE;
                            gCurrentPinballGame->captureSequenceFrame = 0;
                            gCurrentPinballGame->scoreAddedInFrame = SCORE_CATCH_HIT;
                        }
                        else
                        {
                            gCurrentPinballGame->modeProgressLights[gCurrentPinballGame->creatureHitCount - 1] = MODE_PROGRESS_LAMP_CATCH_LIT;
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
    struct Vector16 centerTargetRelativeDistance;
    struct Vector32 gravityForceAngle;
    int squaredDistance;
    u16 angle;
    u8 temp_adjust;

    centerTargetRelativeDistance.x = gCurrentPinballGame->ball->positionQ1.x - 238;
    centerTargetRelativeDistance.y = gCurrentPinballGame->ball->positionQ1.y - 558;
    squaredDistance = (centerTargetRelativeDistance.x * centerTargetRelativeDistance.x) + (centerTargetRelativeDistance.y * centerTargetRelativeDistance.y);

    if (squaredDistance < 1764 && (gCurrentPinballGame->gravityStrengthIndex & 1) == 0)
    {
        angle = ArcTan2(-centerTargetRelativeDistance.x, centerTargetRelativeDistance.y);
        temp_adjust = 30;
        gravityForceAngle.x = MulCos(temp_adjust, angle);
        gravityForceAngle.y = MulSin(-temp_adjust, angle);
        gCurrentPinballGame->ball->velocity.x = ((gravityForceAngle.x * 100) + (98 * gCurrentPinballGame->ball->velocity.x)) / 100;
        gCurrentPinballGame->ball->velocity.y = ((gravityForceAngle.y * 100) + (98 * gCurrentPinballGame->ball->velocity.y)) / 100;
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

            gCurrentPinballGame->collisionResolutionState = COLLISION_RESOLUTION_STATE_STOP_BALL;
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

void ComputeFlipperLaunchVelocity(s32 flipperRelativeBallDistance, s16 flipperIx, struct Vector16* collisionVelocity, u16 flipperCollisionAngle)
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
            flipperRelativeBallDistance -= temp_r5;

            if (flipperRelativeBallDistance < 2850)
            {
                var0 = 0x4800 - (flipperRelativeBallDistance - 2600) * 2048 / 600;
                scale = (flipperRelativeBallDistance - 2600) * 128 / 300 + 120;
            }
            else
            {
                var0 =
                    gFlipperLaunchVelocityParams[temp_r2][0] -
                    ((gFlipperLaunchVelocityParams[temp_r2][1] * (flipperRelativeBallDistance -2600)) / 5400);
                scale = ((flipperRelativeBallDistance -2600) * 348 / 5400) + 406;
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
            collisionVelocity->x = -gCurrentPinballGame->flipperLaunchVelocity.x;
        else
            collisionVelocity->x = gCurrentPinballGame->flipperLaunchVelocity.x;

        collisionVelocity->y = gCurrentPinballGame->flipperLaunchVelocity.y;
    }
    else
    {
        struct Vector16 vec1;
        s32 scale;
        u16 angle2;

        scale = flipperRelativeBallDistance / 20;
        vec1.x = MulCos(scale, flipperCollisionAngle);
        vec1.y = MulNegSinSpecial(scale, flipperCollisionAngle);

        collisionVelocity->x = vec1.x + collisionVelocity->x * 3 / 2;
        collisionVelocity->y = vec1.y + collisionVelocity->y * 3 / 2;

        angle2 = ArcTan2(collisionVelocity->x, -collisionVelocity->y);
        collisionVelocity->x = MulCos(scale, angle2);
        collisionVelocity->y = MulSin(-scale, angle2);
    }
}
