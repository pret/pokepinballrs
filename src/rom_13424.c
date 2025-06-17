#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "constants/anglemath.h"

void sub_13D24(u16 arg0, struct Vector16 *arg1, struct Vector16 *arg2) 
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
    } else 
    {
        angleDelta = arg0 - angleOfFlippedArg1;
        angleSign = 1;
    }

    //Note on agbcc's angle representation:
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
    {
        adjustedAngle = ANGLE_360 + adjustedAngle;
    }
    
    // Project a curved arg2 delta based on half the magnitude
    // Note: GBA trigonometric functions return s16, typically scaled by 0x1000 or more
    lateralMag = halfMag * Sin(angleDelta) / 20000;
    forwardMag = halfMag * Cos(angleDelta) / 20000;

    // 'wall' sound if collision angle is high enough
    if (Cos(angleDelta)  > 0x1F3F)
    {
        if (forwardMag > 0x46) {
            m4aSongNumStart(SE_UNKNOWN_0x77);
        }
    
        if (forwardMag > 0x118 
            && gCurrentPinballGame->unk61C == 0 
            && gMain.selectedField < MAIN_FIELD_COUNT) {
            sub_11B0(6);
        }
    }

    if (gCurrentPinballGame->ballSpeed != 0)
    {
        scaledForwardMag = forwardMag * 21;
    }
    else
    {
        scaledForwardMag = forwardMag * 26;
    }

    forwardMag = scaledForwardMag / 100;
    scaledLateralMag = (lateralMag * 8) / 10;

    curveScaleFactor = gCurrentPinballGame->unk132c->unk6 * 0xEB8 / 0x2BC00;

    curveDir = -angleSign;
    curveDirScaledFactor = (curveDir * 25) * 1024;
    gCurrentPinballGame->unk132c->unk6 = 
        curveDirScaledFactor * scaledLateralMag / 0xEB8 
        + gCurrentPinballGame->unk132c->unk4;

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
        && gCurrentPinballGame->unk24 > 0 
        && gCurrentPinballGame->unk132c->unk10.y <= 0xD1) 
    {
        tempVec.x =  halfMag * Cos(finalAngle) / 20000;        
        tempVec.y = -halfMag * Sin(finalAngle) / 20000;
    } else 
    {
        tempVec.x =  halfMag2 * Cos(finalAngle) / 20000;
        tempVec.y = -halfMag2 * Sin(finalAngle) / 20000;
    }

    sub_14074(arg0, &tempVec, angleOfFlippedArg1);

    arg2->x = tempVec.x;
    arg2->y = tempVec.y;
}