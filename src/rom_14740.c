#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern const u16 gUnknown_08252B10[];
extern const u16 gUnknown_08254B10[];
extern const u16 gUnknown_08257390[];
extern const u16 gUnknown_08259C10[];

extern u8 gUnknown_0839A28C[];
extern u16 gUnknown_086ACE2C[][2];
extern s8 gUnknown_086ACDB8[];



u16 sub_14740(struct Vector16 *arg0, u16 *arg1)
{
    struct Vector16 vec1;
    u16 x, y;
    u16 res;
    u16 var0;

    res = 0;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        vec1.x = arg0->x / 2 - gCurrentPinballGame->unkC4;
        vec1.y = arg0->y / 2 - gCurrentPinballGame->unkC6;
        if ((vec1.y >= 0 && vec1.y < 48) && (vec1.x >= 0 && vec1.x < 48))
        {
            s32 ix = vec1.y * 48 + vec1.x;
            var0 = gUnknown_0839A28C[ix]; 
            if (var0 & 0x80) 
            {
                gCurrentPinballGame->unk22 = 2;
                gCurrentPinballGame->unk23 = 3;
                //Todo: fakematch; used to swap register order
                *arg1 = (var0 & 0x7F & var0) * 512;
                gCurrentPinballGame->unk5A6 = 20;

                if (gCurrentPinballGame->unk5A9)
                    gCurrentPinballGame->unk5A9 = 24;
                else
                    gCurrentPinballGame->unk5A9 = 20;

                // Only difference between these two branches is the played sound
                if (gCurrentPinballGame->currentSpecies == SPECIES_JIRACHI)
                {
                    if (gCurrentPinballGame->unk5AA == 0) 
                    {
                        gCurrentPinballGame->unk5A5++;
                        if (gCurrentPinballGame->unk5A5 == 3) 
                        {
                            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk5A5 - 1] = 3;
                            gCurrentPinballGame->unk5A4 = 2;
                            gCurrentPinballGame->unk5A6 = 0;
                            gCurrentPinballGame->unk3C = 10000;
                        }
                        else
                        {
                            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk5A5 - 1] = 3;
                            gCurrentPinballGame->unk5A4 = 1;
                            gCurrentPinballGame->unk3C = 10000;
                        }

                        gCurrentPinballGame->unk5AA = 4;
                    }

                    res = 1;
                    m4aSongNumStart(SE_UNKNOWN_0x145);
                    sub_11B0(7);
                }
                else
                {
                    if (gCurrentPinballGame->unk5AA == 0)
                    {
                        gCurrentPinballGame->unk5A5++;
                        if (gCurrentPinballGame->unk5A5 == 3)
                        {
                            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk5A5 - 1] = 3;
                            gCurrentPinballGame->unk5A4 = 2;
                            gCurrentPinballGame->unk5A6 = 0;
                            gCurrentPinballGame->unk3C = 10000;
                        }
                        else
                        {
                            gCurrentPinballGame->unk71D[gCurrentPinballGame->unk5A5 - 1] = 3;
                            gCurrentPinballGame->unk5A4 = 1;
                            gCurrentPinballGame->unk3C = 10000;
                        }

                        gCurrentPinballGame->unk5AA = 4;
                    }

                    res = 1;
                    m4aSongNumStart(SE_UNKNOWN_0x74);
                    sub_11B0(7);
                }
            }
        }
    }

    return res;
}


void sub_1493C(void)
{
    struct Vector16 vec1;
    struct Vector32 vec2;    
    int squaredMagnitude;
    u16 angle;
    u8 temp_adjust;

    vec1.x = gCurrentPinballGame->ball->positionQ1.x - 238;
    vec1.y = gCurrentPinballGame->ball->positionQ1.y - 558;
    squaredMagnitude = (vec1.x * vec1.x) + (vec1.y * vec1.y);

    if (squaredMagnitude < 1764 && (gCurrentPinballGame->unk1E & 1) == 0) 
    {
        angle = ArcTan2(-vec1.x, vec1.y);
        temp_adjust = 30;
        vec2.x = (temp_adjust  * Cos(angle)) / 20000;
        vec2.y = (-temp_adjust * Sin(angle)) / 20000;
        gCurrentPinballGame->ball->velocity.x = ((vec2.x * 100) + (98 * gCurrentPinballGame->ball->velocity.x)) / 100;
        gCurrentPinballGame->ball->velocity.y = ((vec2.y * 100) + (98 * gCurrentPinballGame->ball->velocity.y)) / 100;
    }

    if (gCurrentPinballGame->unk5F4 < 20)
    {    
        if (squaredMagnitude < 40) 
        {
            gCurrentPinballGame->unk5F4++;
            gCurrentPinballGame->ball->unkE = 256;
        }
        else
        {
            gCurrentPinballGame->ball->unkE = 256;
            if (squaredMagnitude > 100)
                gCurrentPinballGame->unk5F4 = 0;
        }
    } 
    else 
    {
        if (gCurrentPinballGame->unk5F4 < 30) 
        {
            gCurrentPinballGame->unk5F4++;
            gCurrentPinballGame->ball->unkE = ((30 - gCurrentPinballGame->unk5F4) * 128) / 10 + 128;
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->unk6 = 0;
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
        }
        else
        {
            gCurrentPinballGame->unk5F4 = 0;
            gCurrentPinballGame->unk25 = 4;
            if (gMain.selectedField == FIELD_RUBY)
                sub_1A98C();
            else
                sub_32914();

            gCurrentPinballGame->unk22 = 7;
            gCurrentPinballGame->ball->unkE = 128;
        }
    }
}

u16 sub_14AF4(struct Vector16 r0, s16 r1, u16 *r2, s16 r3) {
    struct UnkPinballGame13BC* unk13BC;
    u16 res;
    int new_var;
    unsigned short ix;
    
    res = 0;
    
    ix = (r0.y * 96) + r0.x; 
    unk13BC = &gCurrentPinballGame->unk13BC[r3]; 

    unk13BC->unk5 = gUnknown_086ACDB8[r1 + (unk13BC->unk2 * 5)];
    
    if (0xF & (&gUnknown_02031520.unk68[unk13BC->unk5 * 0x2400])[ix])
    {
        *r2 = 0xFFF0 & (&gUnknown_02031520.unk68[unk13BC->unk5 * 0x2400])[ix];
        if (r3 == 1)
        {
            new_var = 0x8000;
            *r2 = new_var - (*r2);
        }
        res = 1;
    }

    return res;
}

void sub_14B84(s32 arg0, s16 arg1, struct Vector16* arg2, u16 arg3) 
{
    u16 angle;
    
    angle = gCurrentPinballGame->unk13BC[arg1].unk5;
    
    if (gCurrentPinballGame->unk13BC[arg1].unk8 > 0)
    {
        if (gCurrentPinballGame->unk5C == 0)
        {
            u16 var0;
            s32 scale;
            s16 temp_r2;
            s16 temp_r5;

            temp_r2 = gCurrentPinballGame->unk13BC[arg1].unk5;
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
                    gUnknown_086ACE2C[temp_r2][0] -
                    ((gUnknown_086ACE2C[temp_r2][1] * (arg0 -2600)) / 5400);
                scale = ((arg0 -2600) * 348 / 5400) + 406;
            }

            if (arg1)
                var0 = 0x8000 - var0;

            angle = (gCurrentPinballGame->ball->velocity.x * -0x600) / 0x80 +
                    (gCurrentPinballGame->ball->unk8 * -0x180) / 0x100 +
                    var0;
            gCurrentPinballGame->unk60.x = scale * Cos(angle) / 20000;
            gCurrentPinballGame->unk60.y = -scale * Sin(angle) / 20000;
        }

        gCurrentPinballGame->unk5C = 1;

        if (arg1)
            arg2->x = -gCurrentPinballGame->unk60.x;
        else
            arg2->x = gCurrentPinballGame->unk60.x;

        arg2->y = gCurrentPinballGame->unk60.y;
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

s16 COLLISION_CHECK_RUBY_14E08(struct Vector16 *arg0, u16* arg1) {
    struct Vector16 vec1;
    struct Vector16 vec2;
    u16 sp00;
    u8 sp02;
    u16 return_val;
    s16 unk0;
    s32 unk1;
    s32 unk2;

    u32 some_enum;
    u32 switch_enum;

    return_val = 0;
    gCurrentPinballGame->ball->unk4 = 0;

    vec1.x = arg0->x / 8;
    vec1.y = arg0->y / 8;
    vec2.x = arg0->x % 8;
    vec2.y = arg0->y % 8;
    unk1 = vec1.y / 64;
    unk2 = gCurrentPinballGame->unk24;
    vec1.y %= 64;

    unk0 = gUnknown_02031520.unk14.unk38[unk2 + unk1][vec1.y * 64 + vec1.x];
    sp00 = gUnknown_02031520.unk14.unk48[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];
    sp02 = gUnknown_02031520.unk14.unk58[unk2 + unk1][unk0 * 64 + vec2.y * 8 + vec2.x];

    sub_15054(arg0, &sp00, &sp02);
    
    switch_enum = sp02 & 0xF;
    some_enum = sp02 >> 4;
    
    switch (switch_enum-1) {
    case 0:
    case 3:
    case 5:
        gCurrentPinballGame->unk23 = (switch_enum - 1);
        gCurrentPinballGame->unk22 = 1;
        *arg1 = sp00;

        if (*arg1 >= 0x3FF0 && *arg1 <= 0x4010)
        {
            if (gCurrentPinballGame->ball->positionQ0.x < gUnknown_02031520.unk14.unk26 - 8 ||
                gCurrentPinballGame->ball->positionQ0.y < gUnknown_02031520.unk14.unk28 - 8)
            {

                if (gCurrentPinballGame->ball->unk6 > 0)
                {
                    *arg1 = 0x3E00;
                }
                else if (gCurrentPinballGame->ball->unk6 != 0)
                {
                    *arg1 = 0x4100;
                }
                else
                {
                    if (gMain.systemFrameCount & 1)
                    {
                        gCurrentPinballGame->ball->unk4 = 0x28;
                        gCurrentPinballGame->ball->unk6 = 1;
                        *arg1 = 0x3E00;
                    }
                    else
                    {
                        gCurrentPinballGame->ball->unk4 = 0xFFD8;
                        gCurrentPinballGame->ball->unk6 = 0xFFFF;
                        *arg1 = 0x4100;
                    }
                }
            }
        }
        return_val = 1;
        break;
    case 1:
    case 2:
        gCurrentPinballGame->unk23 = switch_enum - 1;
        gCurrentPinballGame->unk22 = 2;
        *arg1 = sp00 & 0x0000FFF0;
        return_val = 1;

        break;
    case 4:
        gCurrentPinballGame->unk2A2 = 2;
        gCurrentPinballGame->unk1F = 1;
        some_enum = 0;
        break;
    }
    sub_153CC((s32) some_enum, &return_val, arg1);

    return return_val;
}


void sub_15054(struct Vector16* arg0, u16* arg1, u8* arg2) 
{
    s16 deltaX;
    s16 deltaY;
    u16 maskedResult;
    u8 lowerNibble;
    s32 ix;

    maskedResult = 0;
    lowerNibble = 0;
    ix = 0;
    
    if (gCurrentPinballGame->unk5B2 == 0)
    {
        if (gCurrentPinballGame->unk24 != 0)
            return;

        if (gCurrentPinballGame->unk2A4 != 0) 
        {
            if (gCurrentPinballGame->unk2A3 == 0)
                return;
            
            deltaX = arg0->x + gCurrentPinballGame->unk184[0].x;
            deltaY = arg0->y + gCurrentPinballGame->unk184[0].y;
            
            if (deltaX > 79U)
                return;
            
            if (deltaY > 87U)
                return;
            
            maskedResult = 0xFFF0 & gUnknown_08259C10[(deltaY * 80) + deltaX];
            lowerNibble = 0xF & gUnknown_08259C10[(deltaY * 80) + deltaX];
            
            if (lowerNibble == 0)
                return;
            
            *arg1 = maskedResult;
            
            if (gCurrentPinballGame->unk2A2 <= 1)
            {
                *arg2 = lowerNibble;
                gCurrentPinballGame->unk2A2 = 7;
                return;
            }
            
            *arg2 = 1;
            return;
        }
        
        if (0xF & *arg2)
            return;
        
        deltaX = arg0->x + (u16) gCurrentPinballGame->unk184[0].x;
        deltaY = arg0->y + (u16) gCurrentPinballGame->unk184[0].y;
        
        if (deltaX <= 63U && deltaY <= 63U) 
        {
            maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
            lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
            
            if (lowerNibble != 0)
                ix = 0;
        }
        
        if (lowerNibble == 0) 
        {
            deltaX = gCurrentPinballGame->unk184[1].x + arg0->x;
            deltaY = gCurrentPinballGame->unk184[1].y + arg0->y;
            
            if (deltaX <= 63U && deltaY <= 63U) 
            {
                maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                if (lowerNibble != 0)
                    ix = 1;
            }
            
            if (lowerNibble == 0) 
            {
                deltaX = gCurrentPinballGame->unk184[2].x + arg0->x;
                deltaY = gCurrentPinballGame->unk184[2].y + arg0->y;
                
                if (deltaX <= 63U && deltaY <= 63U) 
                {
                    maskedResult = 0xFFF0 & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    lowerNibble = 0xF & gUnknown_08252B10[(deltaY * 64) + deltaX];
                    
                    if (lowerNibble == 0)
                        return;
                    
                    ix = 2;
                }
                
                if (lowerNibble == 0)
                    return;
            }
        }

        if (gCurrentPinballGame->unk16F == 0)
            gCurrentPinballGame->unk170[ix] = 107;        
        
        *arg1 = maskedResult;
        *arg2 = lowerNibble;
        
        if (gCurrentPinballGame->unk624 > 0)
            return;
        
        gCurrentPinballGame->unk624 = 2;
    }
    else 
    {
        if ((*arg2 & 0xF) == 0) 
        {
            if (gCurrentPinballGame->unk2E5[0] > 0) 
            {
                s16 deltaY_alt;
                deltaX = 2 * (-24 -gCurrentPinballGame->unk2EC[0]) + arg0->x;
                deltaY_alt = arg0->y -580;
                
                if (deltaX <= 71U && deltaY_alt <= 71U) 
                {
                    *arg1 = 0xFFF0 & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08254B10[(deltaY_alt * 72) + deltaX];
                    
                    if (*arg2 & 1) 
                    {
                        gCurrentPinballGame->unk2E2 = 1;
                        *arg2 = 6;
                    }
                }
            }
            
            if (gCurrentPinballGame->unk2E5[1] > 0) 
            {
                deltaX = ((gCurrentPinballGame->unk2EC[1] - 180) * 2) + arg0->x;
                deltaY = arg0->y -580;
                
                if (deltaX <= 71U && deltaY <= 71U) 
                {
                    *arg1 = 0xFFF0 & gUnknown_08257390[(deltaY * 72) + deltaX];
                    *arg2 = 0xF & gUnknown_08257390[(deltaY * 72) + deltaX];
                    
                    if (*arg2 & 1) 
                    {
                        gCurrentPinballGame->unk2E2 = 2;
                        *arg2 = 6;
                        return;
                    }
                }
            }
        }
    }
}