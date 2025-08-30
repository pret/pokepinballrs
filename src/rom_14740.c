#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0839A28C[];


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