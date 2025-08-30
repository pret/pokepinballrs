#include "global.h"
#include "main.h"
#include "m4a.h"
#include "constants/bg_music.h"

extern u8 gUnknown_0839A28C[];



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