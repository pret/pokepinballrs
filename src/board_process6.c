#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "constants/anglemath.h"

extern u16 gUnknown_086ACD84[][2];

u16 sub_13824(struct Vector16*);
void sub_13D24(u16,struct Vector16*, struct Vector16*);
void sub_13934(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle);
void sub_1493C(void);
u16 sub_14488(struct Vector16*, struct Vector16);

void sub_14B84(u32 arg0, s16 arg1, struct Vector16 *arg2, u16 arg3);

void AllBoardProcess_6A_4CEA8()
{
	gCurrentPinballGame->unk26 = 60;
}

void AllBoardProcess_6B_1333C()
{
    struct Vector16 var0;
    struct Vector16 var1;
    struct Vector16 var2;
    s16 i;
    u16 r7;

    r7 = sub_13824(&var0);
    switch (gCurrentPinballGame->unk22) 
    {
        case 7:
            gCurrentPinballGame->ball->velocity.x = 0;
            gCurrentPinballGame->ball->velocity.y = 0;
            break;
        case 1:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 6:
            sub_13934(&var0, &var1,r7);
            sub_13D24(r7, &gCurrentPinballGame->ball->velocity, &var2); 
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 2:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->ball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            break;
        case 3:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk14.unk22 * 2);
            var0.y -= (gUnknown_02031520.unk14.unk20 * 2);
            if (gCurrentPinballGame->unk13BC[0].unk4 == 0)
            {
                sub_13D24(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->unk13BC[0].unk4 = 1;
            }
            else
            {            
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            sub_13B28(&var0, &var2, 0);
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->unk22 == 5) 
            {
                for (i = 0; i < 4; i++)
                {
                    if (gUnknown_086ACD74[i].unk2 <= r7)
                    {
                        var0.x += gUnknown_086ACD74[i].unk0;
                        var0.y += gUnknown_086ACD74[i].unk1;
                        break;
                    }
                }
            }
            var0.x += gUnknown_02031520.unk14.unk22 * 2;
            var0.y += gUnknown_02031520.unk14.unk20 * 2;
            break;
        case 4:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk14.unk24 * 2);
            var0.y -= (gUnknown_02031520.unk14.unk20 * 2);
            if (gCurrentPinballGame->unk13BC[1].unk4 == 0)
            {
                sub_13D24(r7, &gCurrentPinballGame->ball->velocity, &var2);
                gCurrentPinballGame->unk13BC[1].unk4 = 1;
            }
            else
            {
                var2.x = gCurrentPinballGame->ball->velocity.x;
                var2.y = gCurrentPinballGame->ball->velocity.y;
            }
            var0.x = 0x5f - var0.x;
            var2.x = -var2.x;
            sub_13B28(&var0, &var2, 1);
            var2.x = -var2.x;
            gCurrentPinballGame->ball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->ball->velocity.y = var2.y + var1.y;
            if (gCurrentPinballGame->unk22 == 5) 
            {
                for (i = 0; i < 4; i++)
                {
                    if (gUnknown_086ACD74[i].unk2 <= r7)
                    {
                        var0.x -= gUnknown_086ACD74[i].unk0;
                        var0.y += gUnknown_086ACD74[i].unk1;
                        break;
                    }
                }
            }
            var0.x = 0x5f - var0.x;
            var0.x += gUnknown_02031520.unk14.unk24 * 2;
            var0.y += gUnknown_02031520.unk14.unk20 * 2;
            break;
        default:
            if (gCurrentPinballGame->unk122 > 0)
            {
                if (gCurrentPinballGame->unk127 != 1)
                {
                    gCurrentPinballGame->ball->velocity.x -=  4;
                    gCurrentPinballGame->unk127 = 1;
                }
            }
            else if (gCurrentPinballGame->unk122 < 0)
            {
                if (gCurrentPinballGame->unk127 != -1)
                {
                    gCurrentPinballGame->ball->velocity.x += 4;
                    gCurrentPinballGame->unk127 = -1;
                }
            }
            if (gCurrentPinballGame->unk5F3) 
            {
                sub_1493C();
            }
    }
    if (gCurrentPinballGame->unk22 != 0) 
    {
        gCurrentPinballGame->ball->positionQ1.x = var0.x;
        gCurrentPinballGame->ball->positionQ1.y = var0.y;
        gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ1.x << 7;
        gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ1.y << 7;
    }
}

u16 sub_13824(struct Vector16* param) 
{
    u16 retVal;
    struct Vector16 test;
    test.x = gCurrentPinballGame->ball->positionQ1.x - gCurrentPinballGame->ball->prevPositionQ1.x;
    test.y = gCurrentPinballGame->ball->positionQ1.y - gCurrentPinballGame->ball->prevPositionQ1.y;
    param->x = gCurrentPinballGame->ball->prevPositionQ1.x;
    param->y = gCurrentPinballGame->ball->prevPositionQ1.y;
    retVal = sub_14488(param, test);

    gCurrentPinballGame->unk124 = 0;
    gCurrentPinballGame->unk125 = 0;

    if (!gCurrentPinballGame->unk22 && (gCurrentPinballGame->unk122 || gCurrentPinballGame->unk123))
    {
        param->x = gCurrentPinballGame->ball->positionQ1.x;
        param->y = gCurrentPinballGame->ball->positionQ1.y;
        test.x = gCurrentPinballGame->unk122;
        test.y = gCurrentPinballGame->unk123;
        retVal = sub_14488(param, test);
        gCurrentPinballGame->unk124 = param->x - gCurrentPinballGame->ball->positionQ1.x;
        gCurrentPinballGame->unk125 = param->y - gCurrentPinballGame->ball->positionQ1.y;
    }
    return retVal;
}

void sub_13934(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle)
{
    s16 cos;

    arg1->x = 0;
    arg1->y = 0;
    if (gCurrentPinballGame->unk122)
    {
        arg0->x -= gCurrentPinballGame->unk124;
        if (gCurrentPinballGame->unk122 > 0)
        {
            cos = Cos(angle);
            if (cos < 0)
            {
                arg1->x = (Cos(angle) * 70) / 20000;
                gCurrentPinballGame->unk126 = 1;
            }
        }
        else if (gCurrentPinballGame->unk122 < 0)
        {
            cos = Cos(angle);
            if (cos > 0)
            {
                arg1->x = (Cos(angle) * 70) / 20000;
                gCurrentPinballGame->unk126 = 1;
            }
        }
    }

    if (gCurrentPinballGame->unk123 > 0)
    {
        arg0->y -= gCurrentPinballGame->unk125;
        if (gCurrentPinballGame->ball->positionQ0.y > 364)
        {
            if (gCurrentPinballGame->unk122 == 0)
                arg1->y = -(Sin(angle) * 130) / 20000;
            else
                arg1->y = -(Sin(angle) * 100) / 20000;
        }
        else
        {
            if (gCurrentPinballGame->unk122 == 0)
                arg1->y = -(Sin(angle) * 100) / 20000;
            else
                arg1->y = -(Sin(angle) * 75) / 20000;

            if (arg1->y >= 90)
                gCurrentPinballGame->ball->velocity.x /= 4;
            else if (arg1->y >= 70)
                gCurrentPinballGame->ball->velocity.x /= 4;
        }

        gCurrentPinballGame->unk126 = 1;
    }

    if (gCurrentPinballGame->unk126)
    {
        gCurrentPinballGame->unk122 = 0;
        gCurrentPinballGame->unk123 = 0;
    }
}

void sub_13B28(struct Vector16* arg0, struct Vector16* arg1, s16 arg2)
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
        sp12 = gCurrentPinballGame->unk13BC[arg2].unk0 - gCurrentPinballGame->unk13BC[arg2].unk1;
        
        if ((sp12 *= gCurrentPinballGame->unk13BC[arg2].unk8) > 0)
        {
            if (gCurrentPinballGame->unk13BC[arg2].unk2 < 7)
                r4 = gUnknown_086ACD84[gCurrentPinballGame->unk13BC[arg2].unk5 - 1][0] +  0x4000;
            else
                r4 = gUnknown_086ACD84[gCurrentPinballGame->unk13BC[arg2].unk5 + 1][1] + -0x4000; // This changes compilation, apparently
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
        sub_14B84(temp, arg2, &sp4, r4);
        
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
        
        for (i = gCurrentPinballGame->unk1E; i < 4; i++)
        {
            if (sub_14AF4(*arg0, i + 1, &sp0, arg2))
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
        gCurrentPinballGame->unk22 = 5;
    }
    else
    {
        arg1->x = sp4.x;
        arg1->y = sp4.y;
    }
}


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
            m4aSongNumStart(SE_UNKNOWN_0x77);
    
        if (forwardMag > 0x118 
            && gCurrentPinballGame->unk61C == 0 
            && gMain.selectedField < MAIN_FIELD_COUNT)
        {
            sub_11B0(6);
        }
    }

    if (gCurrentPinballGame->ballSpeed != 0)
        scaledForwardMag = forwardMag * 21;
    else
        scaledForwardMag = forwardMag * 26;

    forwardMag = scaledForwardMag / 100;
    scaledLateralMag = (lateralMag * 8) / 10;

    curveScaleFactor = gCurrentPinballGame->ball->unk6 * 0xEB8 / 0x2BC00;

    curveDir = -angleSign;
    curveDirScaledFactor = (curveDir * 25) * 1024;
    gCurrentPinballGame->ball->unk6 = 
        curveDirScaledFactor * scaledLateralMag / 0xEB8 
        + gCurrentPinballGame->ball->unk4;

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

    sub_14074(arg0, &tempVec, angleOfFlippedArg1);

    arg2->x = tempVec.x;
    arg2->y = tempVec.y;
}

void sub_14074(u16 arg0, struct Vector32 *arg1, u16 arg2)
{
    const u16 VECTORSCALEDOWN = 20000;
    s32 vMagSquared;
    s16 x, y;
    s16 var0;

    struct Vector16 tempVec;
    
    x = gCurrentPinballGame->ball->velocity.x;
    y = gCurrentPinballGame->ball->velocity.y;
    vMagSquared = (x * x) + (y * y);

    if (gCurrentPinballGame->unk23 == 2)
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

            gCurrentPinballGame->ball->unk6 = (gCurrentPinballGame->ball->unk6 * 4) / 10; 
            
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
            
            gCurrentPinballGame->unk716 = 4;
            if (gCurrentPinballGame->ball->positionQ0.x < 120)
                gCurrentPinballGame->unk717 = 0;
            else
                gCurrentPinballGame->unk717 = 1;
        } 
    } 
    else
    {
        if (gCurrentPinballGame->unk23 == 1)
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
            tempVec.x =  gUnknown_086ACDF4[gCurrentPinballGame->unk23] * Cos(arg0) / VECTORSCALEDOWN;
            tempVec.y = -gUnknown_086ACDF4[gCurrentPinballGame->unk23] * Sin(arg0) / VECTORSCALEDOWN;
        } 
    }
    
    arg1->x = arg1->x + tempVec.x;
    arg1->y = arg1->y + tempVec.y;
    
    if (gCurrentPinballGame->unk5A4 != 0)
    {
        s16 x2 = arg1->x;
        s16 xSign = 1;
        u16 angle;
        if (gCurrentPinballGame->unk5A4 == 1)
        {
            gCurrentPinballGame->unk5A4 = 0;
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
        
        gCurrentPinballGame->ball->unk6 = 0;
        angle = ArcTan2(arg1->x, -arg1->y);
        arg1->x = vMagSquared  * Cos(angle) / VECTORSCALEDOWN;
        arg1->y = -vMagSquared  * Sin(angle) / VECTORSCALEDOWN;
    }   
}

// TODO: Hopefully we can match this properly without "goto" usage in the future...
u16 sub_14488(struct Vector16* arg0, struct Vector16 arg1) {
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

    
    gCurrentPinballGame->unk22 = 0;
    gCurrentPinballGame->unk23 = 0;

    spC = BoardCollisionFuncts_086ACE0C[gMain.selectedField];
    
    do{
        goto Lab_144;
    
        Lab_AE:
        {
            gCurrentPinballGame->unk22 = 0;
            
            if (sub_1467C(arg0, &sp0_return) != 0 ||
                (gCurrentPinballGame->unk5F2 != 0 && sub_14740(arg0, &sp0_return) != 0))
                goto Lab_1E0;
        
            goto Lab_E6;
        }
        Lab_E6:
        {    
            if (!(arg1.x > 0 || arg1.y > 0))
                goto Lab_1E0;
            
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
        }
        Lab_144:
        {
            if(spC(arg0, &sp0_return) == 0)
            {
                goto Lab_AE;
            }
            else if (gCurrentPinballGame->unk22 == 1)
            {
                if (gCurrentPinballGame->unk23 == 3)
                {
                    u16 j;
                    u16 sp2_testRes;
                    struct Vector16 sp4_testPos;
                    
                    for(j=0; j < 4; j++)
                    {
                        sp4_testPos.x = arg0->x + gUnknown_086ACE60[j].x;
                        sp4_testPos.y = arg0->y + gUnknown_086ACE60[j].y;
            
                        spC(&sp4_testPos, &sp2_testRes);
                        if (gCurrentPinballGame->unk22 == 1 && gCurrentPinballGame->unk23 == 0)
                        {
                            Lab_9C:
                            arg0->x = sp4_testPos.x;
                            arg0->y = sp4_testPos.y;
                            sp0_return = sp2_testRes;
                    
                            break;
                        }   
                    }
                }
                goto Lab_E6;
            }
            else {
                break;
            }
        }
    } while(1);
    
    Lab_1E0:
    return sp0_return;
}

u16 sub_1467C(struct Vector16* arg0, u16* arg1) 
{
    u16 res;
    struct Vector16 vec1;
    struct Vector16 vec2;
 
    res = 0;
    
    vec1.x = arg0->x - gUnknown_02031520.unk14.unk22 * 2;
    vec2.x = arg0->x - gUnknown_02031520.unk14.unk24 * 2;
    vec1.y = arg0->y - gUnknown_02031520.unk14.unk20 * 2;
    vec2.y = vec1.y;

    if (vec1.y <= 95 && vec1.y >= 0)
    {
        if (vec1.x <= 95 && vec1.x >= 0)
        {
            if(sub_14AF4(vec1, gCurrentPinballGame->unk1E + 1, arg1, 0))
            {
                gCurrentPinballGame->unk22 = 3;
                res = 1;
            }
        }

        if (res == 0)
        {   
            if (vec2.x <= 95 && vec2.x >= 0)
            {
                vec2.x = 95 - vec2.x;
                if (sub_14AF4(vec2, gCurrentPinballGame->unk1E + 1, arg1, 1))
                {
                    gCurrentPinballGame->unk22 = 4;
                    res = 1;
                }
            }
        } 
    }
    
    return res;
}
