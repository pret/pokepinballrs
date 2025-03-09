#include "global.h"

void sub_1332C()
{
	gCurrentPinballGame->unk26 = 60;
}

u16 sub_13824(struct Vector16*);

void sub_13D24(u16,struct Vector16*, struct Vector16*);

void sub_13934(struct Vector16*,struct Vector16*,u16);

void sub_13B28(struct Vector16*, struct Vector16*, s16);

void sub_1493C(void);

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
            gCurrentPinballGame->unk132c->velocity.x = 0;
            gCurrentPinballGame->unk132c->velocity.y = 0;
            break;
        case 1:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->unk132c->velocity, &var2);
            for(i = 0; i < 9; i++){
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->unk132c->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->unk132c->velocity.y = var2.y + var1.y;
            break;
        case 6:
            sub_13934(&var0, &var1,r7);
            sub_13D24(r7, &gCurrentPinballGame->unk132c->velocity, &var2); 
            gCurrentPinballGame->unk132c->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->unk132c->velocity.y = var2.y + var1.y;
            break;
        case 2:
            sub_13934(&var0, &var1, r7);
            sub_13D24(r7, &gCurrentPinballGame->unk132c->velocity, &var2);
            for(i = 0; i < 9; i++){
                if (gUnknown_086ACD50[i].unk2 <= r7) 
                {
                    var0.x += gUnknown_086ACD50[i].unk0;
                    var0.y += gUnknown_086ACD50[i].unk1;
                    break;
                }
            }
            gCurrentPinballGame->unk132c->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->unk132c->velocity.y = var2.y + var1.y;
            break;
        case 3:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk22 * 2);
            var0.y -= (gUnknown_02031520.unk20 * 2);
            if (gCurrentPinballGame->unk13C0 == 0) 
            {
                sub_13D24(r7, &gCurrentPinballGame->unk132c->velocity, &var2);
                gCurrentPinballGame->unk13C0 = 1;
            }
            else
            {            
                var2.x = gCurrentPinballGame->unk132c->velocity.x;
                var2.y = gCurrentPinballGame->unk132c->velocity.y;
            }
            sub_13B28(&var0, &var2, 0);
            gCurrentPinballGame->unk132c->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->unk132c->velocity.y = var2.y + var1.y;
            if(gCurrentPinballGame->unk22 == 5) {
                for(i = 0; i < 4; i++)
                {
                    if(gUnknown_086ACD74[i].unk2 <= r7)
                    {
                        var0.x += gUnknown_086ACD74[i].unk0;
                        var0.y += gUnknown_086ACD74[i].unk1;
                        break;
                    }
                };
            }
            var0.x += gUnknown_02031520.unk22 * 2;
            var0.y += gUnknown_02031520.unk20 * 2;
            break;
        case 4:
            sub_13934(&var0, &var1, r7);
            var0.x -= (gUnknown_02031520.unk24 * 2);
            var0.y -= (gUnknown_02031520.unk20 * 2);
            if (gCurrentPinballGame->unk13CC == 0) 
            {
                sub_13D24(r7, &gCurrentPinballGame->unk132c->velocity, &var2);
                gCurrentPinballGame->unk13CC = 1;
            }
            else
            {
                var2.x = gCurrentPinballGame->unk132c->velocity.x;
                var2.y = gCurrentPinballGame->unk132c->velocity.y;
            }
            var0.x = 0x5f - var0.x;
            var2.x = -var2.x;
            sub_13B28(&var0, &var2, 1);
            var2.x = -var2.x;
            gCurrentPinballGame->unk132c->velocity.x = var2.x + var1.x;
            gCurrentPinballGame->unk132c->velocity.y = var2.y + var1.y;
            if(gCurrentPinballGame->unk22 == 5) {
                for(i = 0; i < 4; i++)
                {
                    if(gUnknown_086ACD74[i].unk2 <= r7)
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
                if (gCurrentPinballGame->unk127[0] != 1)
                {
                    gCurrentPinballGame->unk132c->velocity.x -=  4;
                    gCurrentPinballGame->unk127[0] = 1;
                }
            }
            else if (gCurrentPinballGame->unk122 < 0)
            {
                if (gCurrentPinballGame->unk127[0] != -1)
                {
                    gCurrentPinballGame->unk132c->velocity.x += 4;
                    gCurrentPinballGame->unk127[0] = -1;
                }
            }
            if (gCurrentPinballGame->unk5F3) {
                sub_1493C();
            }
    }
    if (gCurrentPinballGame->unk22 != 0) {
        gCurrentPinballGame->unk132c->unk28.x = var0.x;
        gCurrentPinballGame->unk132c->unk28.y = var0.y;
        gCurrentPinballGame->unk132c->position.x = gCurrentPinballGame->unk132c->unk28.x << 7;
        gCurrentPinballGame->unk132c->position.y = gCurrentPinballGame->unk132c->unk28.y << 7;
    }
}
