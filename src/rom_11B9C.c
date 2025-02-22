#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

void sub_11C14(s16);
void sub_12524(void);
void sub_12BF8(void);
void sub_2AADC(void);

void sub_11B9C(void)
{
    s16 i;
    if (gMain.unk6 == 0)
    {
        gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[0];
        sub_11C14(0);
        sub_12524();
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            gCurrentPinballGame->unk132c = &gCurrentPinballGame->unk1334[i];
            sub_11C14(i);
        }
        sub_12BF8();
    }
}

void sub_11C14(s16 arg0)
{
    struct UnkPinballGame1334 *var0 = &gCurrentPinballGame->unk1334[arg0];
    var0->unk10.x = gUnknown_02031520.unk26;
    var0->unk10.y = gUnknown_02031520.unk28;
    var0->position.x = Q_24_8(var0->unk10.x);
    var0->position.y = Q_24_8(var0->unk10.y);
    var0->unk28.x = gUnknown_02031520.unk26 * 2;
    var0->unk28.y = gUnknown_02031520.unk28 * 2;
    var0->unkE = 0x100;
    var0->velocity.x = 0;
    var0->velocity.y = 0;
    if (gMain.selectedField == FIELD_RUBY)
        var0->unk1 = 3; 
    else
        var0->unk1 = 1;

    var0->unk6 = 0;
    gCurrentPinballGame->unk5B2 = 1;
}

extern const u16 gGravityDeltas_Strong[4];
extern const u16 gGravityDeltas_Medium[4];
extern const u16 gGravityDeltas_Light[4];

#define DO_THING(max_speed, angle)                                          \
{ \
    maxSpeed =(max_speed); \
    if (squaredMagnitude > maxSpeed * maxSpeed) \
    { \
        var0 = (u16)((maxSpeed * Cos(angle)) / 0x4E20); \
        var1 = (var1 & 0xFFFF0000) | var0; \
        var0 = ((-maxSpeed * Sin(angle)) / 0x4E20) << 16; \
        var1 = (var1 & 0xFFFF) | var0; \
        unk132c->position.x += (s16)var1; \
        unk132c->position.y += var1 >> 16; \
    } \
    else \
    { \
        var1 = (u16)unk132c->velocity.y << 16 | (u16)unk132c->velocity.x; \
        unk132c->position.x += (s16)var1; \
        unk132c->position.y += var1 >> 16; \
    } \
}

void sub_11C98(void)
{
    struct UnkPinballGame1334 *unk132c;
    int var1;
    u32 var0;
    u32 xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->unk132c;
    unk132c->unk3C = unk132c->position;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        u16 angle;

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            if (!gCurrentPinballGame->unk1F)
            {
                if (unk132c->velocity.y > 0xA0)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 0x50)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }
            
            // _08011D0A
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (unk132c->unk10.y < 380)
            {
                DO_THING(0x110, angle);
            }
            else
            {
                // _08011DA4
                DO_THING(0x190, angle);
            }
        }
        else
        {
            u16 angle;

            // _08011E04
            if (!gCurrentPinballGame->unk1F)
            {
                if (unk132c->velocity.y > 0xC8)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 0x64)
                    unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
                else
                    unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
            }

            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (unk132c->unk10.y < 380)
            {
                DO_THING(0x150, angle);
            }
            else
            {
                DO_THING(0x190, angle);
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    // _08011F4C
    unk132c->unk2C = unk132c->unk28;
    var1 = unk132c->position.x + 0x40;
    if (var1 < 0)
        var1 += 0x7F;
    
    unk132c->unk28.x = var1 >> 7;
    var1 = unk132c->position.y + 0x40;
    if (var1 < 0)
        var1 += 0x7F;
    
    unk132c->unk28.y = var1 >> 7;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}
