#include "global.h"


u16 sub_13824(struct Vector16*);
void sub_13D24(u16,struct Vector16*, struct Vector16*);
void sub_13934(struct Vector16 *arg0, struct Vector16 *arg1, u16 angle);
void sub_1493C(void);
u16 sub_14488(struct Vector16*, struct Vector16);

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
            gCurrentPinballGame->pokeball->velocity.x = 0;
            gCurrentPinballGame->pokeball->velocity.y = 0;
            break;
        case 1:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->pokeball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->pokeball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->pokeball->velocity.y = var2.y + var1.y;
            break;
        case 6:
            sub_13934(&var0, &var1,r7);
            sub_13D24(r7, &gCurrentPinballGame->pokeball->velocity, &var2); 
            gCurrentPinballGame->pokeball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->pokeball->velocity.y = var2.y + var1.y;
            break;
        case 2:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->pokeball->velocity, &var2);
            for (i = 0; i < 9; i++)
            {
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->pokeball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->pokeball->velocity.y = var2.y + var1.y;
            break;
        case 3:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk22 * 2);
            var0.y -= (gUnknown_02031520.unk20 * 2);
            if (gCurrentPinballGame->unk13BC[0].unk4 == 0)
            {
                sub_13D24(r7, &gCurrentPinballGame->pokeball->velocity, &var2);
                gCurrentPinballGame->unk13BC[0].unk4 = 1;
            }
            else
            {            
                var2.x = gCurrentPinballGame->pokeball->velocity.x;
                var2.y = gCurrentPinballGame->pokeball->velocity.y;
            }
            sub_13B28(&var0, &var2, 0);
            gCurrentPinballGame->pokeball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->pokeball->velocity.y = var2.y + var1.y;
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
                sub_13D24(r7, &gCurrentPinballGame->pokeball->velocity, &var2);
                gCurrentPinballGame->unk13BC[1].unk4 = 1;
            }
            else
            {
                var2.x = gCurrentPinballGame->pokeball->velocity.x;
                var2.y = gCurrentPinballGame->pokeball->velocity.y;
            }
            var0.x = 0x5f - var0.x;
            var2.x = -var2.x;
            sub_13B28(&var0, &var2, 1);
            var2.x = -var2.x;
            gCurrentPinballGame->pokeball->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->pokeball->velocity.y = var2.y + var1.y;
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
                    gCurrentPinballGame->pokeball->velocity.x -=  4;
                    gCurrentPinballGame->unk127 = 1;
                }
            }
            else if (gCurrentPinballGame->unk122 < 0)
            {
                if (gCurrentPinballGame->unk127 != -1)
                {
                    gCurrentPinballGame->pokeball->velocity.x += 4;
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
        gCurrentPinballGame->pokeball->halfPxPosition.x = var0.x;
        gCurrentPinballGame->pokeball->halfPxPosition.y = var0.y;
        gCurrentPinballGame->pokeball->physicsPosition.x = gCurrentPinballGame->pokeball->halfPxPosition.x << 7;
        gCurrentPinballGame->pokeball->physicsPosition.y = gCurrentPinballGame->pokeball->halfPxPosition.y << 7;
    }
}

u16 sub_13824(struct Vector16* param) 
{
    u16 retVal;
    struct Vector16 test;
    test.x = gCurrentPinballGame->pokeball->halfPxPosition.x - gCurrentPinballGame->pokeball->prevHalfPxPosition.x;
    test.y = gCurrentPinballGame->pokeball->halfPxPosition.y - gCurrentPinballGame->pokeball->prevHalfPxPosition.y;
    param->x = gCurrentPinballGame->pokeball->prevHalfPxPosition.x;
    param->y = gCurrentPinballGame->pokeball->prevHalfPxPosition.y;
    retVal = sub_14488(param, test);

    gCurrentPinballGame->unk124 = 0;
    gCurrentPinballGame->unk125 = 0;

    if (!gCurrentPinballGame->unk22 && (gCurrentPinballGame->unk122 || gCurrentPinballGame->unk123))
    {
        param->x = gCurrentPinballGame->pokeball->halfPxPosition.x;
        param->y = gCurrentPinballGame->pokeball->halfPxPosition.y;
        test.x = gCurrentPinballGame->unk122;
        test.y = gCurrentPinballGame->unk123;
        retVal = sub_14488(param, test);
        gCurrentPinballGame->unk124 = param->x - gCurrentPinballGame->pokeball->halfPxPosition.x;
        gCurrentPinballGame->unk125 = param->y - gCurrentPinballGame->pokeball->halfPxPosition.y;
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
        if (gCurrentPinballGame->pokeball->logicPosition.y > 364)
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
                gCurrentPinballGame->pokeball->velocity.x /= 4;
            else if (arg1->y >= 70)
                gCurrentPinballGame->pokeball->velocity.x /= 4;
        }

        gCurrentPinballGame->unk126 = 1;
    }

    if (gCurrentPinballGame->unk126)
    {
        gCurrentPinballGame->unk122 = 0;
        gCurrentPinballGame->unk123 = 0;
    }
}
