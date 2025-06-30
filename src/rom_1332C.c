#include "global.h"

extern u16 gUnknown_086ACD84[][2];

u16 sub_13824(struct Vector16*);
void sub_13D24(u16,struct Vector16*, struct Vector16*);
void sub_13934(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle);
void sub_1493C(void);
u16 sub_14488(struct Vector16*, struct Vector16);
u16 sub_14AF4(struct Vector16 r0, s16 r1, s16 *r2 /* s16 or u16 */, s16 r3);
void sub_14B84(u32 r0, s16 r1, struct Vector16 *r2, u16 r3);

void sub_1332C()
{
	gCurrentPinballGame->unk26 = 60;
}

void sub_1333C()
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
            var0.x -= (gUnknown_02031520.unk22 * 2);
            var0.y -= (gUnknown_02031520.unk20 * 2);
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
            var0.x += gUnknown_02031520.unk22 * 2;
            var0.y += gUnknown_02031520.unk20 * 2;
            break;
        case 4:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk24 * 2);
            var0.y -= (gUnknown_02031520.unk20 * 2);
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
            var0.x += gUnknown_02031520.unk24 * 2;
            var0.y += gUnknown_02031520.unk20 * 2;
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
