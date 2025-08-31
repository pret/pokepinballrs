#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0839A28C[];
extern u16 gUnknown_086ACE2C[][2];
extern s8 gUnknown_086ACDB8[];


u16 sub_14740(struct Vector16* arg0, u16* arg1) 
{
    struct Vector16 vec1;
    u16 x;
    u16 y;
    u16 res;
    u16 temp_r2;

    res = 0;
    if (gCurrentPinballGame->unk5A4 != 2) 
    {
        vec1.x = arg0->x / 2 - gCurrentPinballGame->unkC4;
        vec1.y = arg0->y / 2 - gCurrentPinballGame->unkC6;
        
        if ((vec1.y >= 0 && vec1.y < 48) && (vec1.x >= 0 && vec1.x < 48))
        {
            s32 ix = vec1.y * 48 + vec1.x;
            temp_r2 = gUnknown_0839A28C[ix]; 
    
            if (temp_r2 & 0x80) 
            {
                gCurrentPinballGame->unk22 = 2;
                gCurrentPinballGame->unk23 = 3;

                //Todo: fakematch; used to swap register order
                *arg1 = (temp_r2 & 0x7F & temp_r2 ) * 512;
                gCurrentPinballGame->unk5A6 = 20;
                
                if (gCurrentPinballGame->unk5A9 != 0)
                    gCurrentPinballGame->unk5A9 =24;
                else
                    gCurrentPinballGame->unk5A9 = 20;
                
                //Only difference between the two branches is the sound played
                if (gCurrentPinballGame->currentSpecies == 200) 
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


void sub_1493C(void) {
    struct Vector16 vec1;
    struct Vector32 vec2;
    
    s32 mag1;
    u16 tan1;
    u8 temp_adjust;

    vec1.x = gCurrentPinballGame->ball->positionQ1.x - 238;
    vec1.y = gCurrentPinballGame->ball->positionQ1.y - 558;
    mag1 = (vec1.x * vec1.x) + (vec1.y * vec1.y);
    
    if ((mag1 <= 1763) && !(1 & gCurrentPinballGame->unk1E)) 
    {
        tan1 = ArcTan2(-vec1.x, vec1.y);
        
        temp_adjust = 30;
        vec2.x = (temp_adjust  * Cos(tan1)) / 20000;
        vec2.y = (-temp_adjust * Sin(tan1)) / 20000;
        
        gCurrentPinballGame->ball->velocity.x = ((vec2.x * 100) + (98 * gCurrentPinballGame->ball->velocity.x)) / 100;
        gCurrentPinballGame->ball->velocity.y = ((vec2.y * 100) + (98 * gCurrentPinballGame->ball->velocity.y)) / 100;
    }
    
    if (gCurrentPinballGame->unk5F4 <= 19) 
    {    
        if (mag1 <= 39) 
        {
            gCurrentPinballGame->unk5F4 += 1;
            gCurrentPinballGame->ball->unkE = 256;
        }
        else
        {
            gCurrentPinballGame->ball->unkE = 256;
            
            if (mag1 > 100)
                gCurrentPinballGame->unk5F4 = 0;
        }
    } 
    else 
    {
        if (gCurrentPinballGame->unk5F4 <= 29) 
        {
            gCurrentPinballGame->unk5F4 += 1;
            gCurrentPinballGame->ball->unkE = ((30 - gCurrentPinballGame->unk5F4) * 128) / 10 + 128;
            
            gCurrentPinballGame->ball->positionQ0.x = 119;
            gCurrentPinballGame->ball->positionQ0.y = 279;
            gCurrentPinballGame->ball->unk6 = 0;
            
            gCurrentPinballGame->ball->positionQ8.x = gCurrentPinballGame->ball->positionQ0.x << 8;
            gCurrentPinballGame->ball->positionQ8.y = gCurrentPinballGame->ball->positionQ0.y << 8;
            
            return;
        }

        gCurrentPinballGame->unk5F4 = 0;
        gCurrentPinballGame->unk25 = 4;
        
        if (gMain.selectedField == 0)
            sub_1A98C();
        else
            sub_32914();
        
        gCurrentPinballGame->unk22 = 7;
        gCurrentPinballGame->ball->unkE = 128;
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
