#include "global.h"
#include "main.h"
#include "constants/bg_music.h"
#include "constants/fields.h"

void sub_11C14(s16);
void sub_12524(void);
void sub_12BF8(void);
void sub_2AADC(void);

extern const u8 gUnknown_08137E14[][0x20];
extern const u8 gUnknown_083BB16C[][0x80];
extern const u8 gUnknown_083BD36C[][0x200];

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


// Before updating the ball's position, cap the ball's velocity
// vector to a maximum speed.
#define UPDATE_BALL_POSITION(max_speed, angle)           \
{                                                        \
    maxSpeed = (max_speed);                              \
    if (squaredMagnitude > maxSpeed * maxSpeed)          \
    {                                                    \
        velocity.x =  (maxSpeed * Cos((angle))) / 20000; \
        velocity.y = (-maxSpeed * Sin((angle))) / 20000; \
    }                                                    \
    else                                                 \
    {                                                    \
        velocity.x = unk132c->velocity.x;                \
        velocity.y = unk132c->velocity.y;                \
    }                                                    \
    unk132c->position.x += velocity.x;                   \
    unk132c->position.y += velocity.y;                   \
}

void sub_11C98(void)
{
    struct Vector16 velocity;
    struct UnkPinballGame1334 *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->unk132c;
    unk132c->prevPosition = unk132c->position;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 160)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 80)
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
                UPDATE_BALL_POSITION(272, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
        else
        {
            u16 angle;

            if (!gCurrentPinballGame->unk1F)
            {
                // Gravity is applied at different strengths, depending on fast the ball is
                // currently moving downwards.
                if (unk132c->velocity.y > 200)
                    unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
                else if (unk132c->velocity.y > 100)
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
                UPDATE_BALL_POSITION(336, angle);
            }
            else
            {
                UPDATE_BALL_POSITION(400, angle);
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->unk2C = unk132c->unk28;
    unk132c->unk28.x = (unk132c->position.x + 64) / 128;
    unk132c->unk28.y = (unk132c->position.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

void sub_11F88(void)
{
    struct Vector16 velocity;
    struct UnkPinballGame1334 *unk132c;
    int xx, yy;
    int squaredMagnitude;
    int maxSpeed;

    unk132c = gCurrentPinballGame->unk132c;
    unk132c->prevPosition = unk132c->position;
    if (gCurrentPinballGame->unk5A4 != 2)
    {
        if (!gCurrentPinballGame->unk1F && !gCurrentPinballGame->unk383)
        {
            // Gravity is applied at different strengths, depending on fast the ball is
            // currently moving downwards.
            if (unk132c->velocity.y > 150)
                unk132c->velocity.y += gGravityDeltas_Light[gCurrentPinballGame->unk1E];
            else if (unk132c->velocity.y > 75)
                unk132c->velocity.y += gGravityDeltas_Medium[gCurrentPinballGame->unk1E];
            else
                unk132c->velocity.y += gGravityDeltas_Strong[gCurrentPinballGame->unk1E];
        }

        if (gCurrentPinballGame->ballSpeed != 0)
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;
            
            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->unk10.y < 150)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
        else
        {
            u16 angle;
            angle = ArcTan2(unk132c->velocity.x, -unk132c->velocity.y);
            xx = unk132c->velocity.x * unk132c->velocity.x;
            yy = unk132c->velocity.y * unk132c->velocity.y;
            squaredMagnitude = xx + yy;

            if (gMain.selectedField <= FIELD_KECLEON)
            {
                if (unk132c->unk10.y < 150)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else if (gMain.selectedField == FIELD_SPHEAL)
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(272, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
            else
            {
                if (unk132c->unk10.y < 218)
                {
                    UPDATE_BALL_POSITION(304, angle);
                }
                else
                {
                    UPDATE_BALL_POSITION(400, angle);
                }
            }
        }
    }
    else
    {
        sub_2AADC();
    }

    unk132c->unk2C = unk132c->unk28;
    unk132c->unk28.x = (unk132c->position.x + 64) / 128;
    unk132c->unk28.y = (unk132c->position.y + 64) / 128;
    unk132c->unk8 = unk132c->unk6;
    unk132c->unkA += unk132c->unk6;
}

#ifdef NONMATCHING
void sub_12524(void)
{
    s16 i;
    struct UnkPinballGame1334 *unk132c;
    struct MainUnk44 *mainUnk44;
    struct OamData *oam;
    s16 r8;

    unk132c = gCurrentPinballGame->unk132c;
    r8 = unk132c->unkA / 0x1000;
    if (unk132c->unk10.y == 340 && (unk132c->unk10.x == 90 || unk132c->unk10.x == 149))
        unk132c->unkA = unk132c->unkC;

    unk132c->unkC = unk132c->unkA;
    if (!gCurrentPinballGame->unk5F7 && gCurrentPinballGame->unk5F8 > 0)
    {
        if (--gCurrentPinballGame->unk5F8 == 0)
        {
            if (gCurrentPinballGame->unk5F6 > 0)
            {
                gCurrentPinballGame->unk5F6--;
                if (gCurrentPinballGame->unk5F6 > 0)
                {
                    gCurrentPinballGame->unk5F8 = 60 * 60;
                }
            }

            DmaCopy16(3, gUnknown_08137E14[gCurrentPinballGame->unk5F6], (void *)OBJ_PLTT + 0x20, 0x20);
        }
    }

    if (unk132c->unk10.y >= 244)
    {
        gCurrentPinballGame->unk5B2 = 1;
        gCurrentPinballGame->unk176 = 0;
    }
    else
    {
        gCurrentPinballGame->unk5B2 = 0;
    }

    // _08012620
    unk132c->unk10.x = unk132c->unk28.x / 2;
    unk132c->unk10.y = unk132c->unk28.y / 2;
    mainUnk44 = gMain.unk44[0];
    if (mainUnk44->a.unk0)
    {
        SetMatrixScale(unk132c->unkE, unk132c->unkE, 0);
        mainUnk44->a.unk2 = -(gCurrentPinballGame->unk4C + 7) + unk132c->unk10.x - gCurrentPinballGame->unk2AA;
        mainUnk44->a.unk4 = -(gCurrentPinballGame->unk4E + 7) + unk132c->unk10.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;
        unk132c->unk24 = mainUnk44->a.unk2;
        unk132c->unk26 = mainUnk44->a.unk4;
        
        oam = &gOamBuffer[mainUnk44->b.unk0];
        if (unk132c->unk1 == 3)
        {
            if (unk132c->unk10.y > 248)
                oam->priority = 2;
            else
                oam->priority = 3;
        }
        else
        {
            oam->priority = unk132c->unk1;
        }

        DmaCopy16(3, gUnknown_083BB16C[r8 + gCurrentPinballGame->unk5F6 * 17], (void *)0x6010400, 0x80);

        if (mainUnk44->a.unk4 > 200)
            mainUnk44->a.unk4 = 200;
        if (mainUnk44->a.unk4 < -20)
            mainUnk44->a.unk4 = -20;

        oam->x = mainUnk44->b.unk2 + mainUnk44->a.unk2;
        if (unk132c->unk0)
            oam->y = 200;
        else
            oam->y = mainUnk44->b.unk4 + mainUnk44->a.unk4;
    }

    // _08012792
    mainUnk44 = gMain.unk44[49];
    if (mainUnk44->a.unk0)
    {
        SetMatrixScale(unk132c->unkE, unk132c->unkE, 0);
        mainUnk44->a.unk2 = -(gCurrentPinballGame->unk4C + 7) + unk132c->unk10.x - gCurrentPinballGame->unk2AA;
        mainUnk44->a.unk4 = -(gCurrentPinballGame->unk4E + 7) + unk132c->unk10.y - gCurrentPinballGame->unk5FC - gCurrentPinballGame->unkE6 + gCurrentPinballGame->unk166;
        unk132c->unk24 = mainUnk44->a.unk2;
        unk132c->unk26 = mainUnk44->a.unk4;
        oam = &gOamBuffer[mainUnk44->b.unk0];
        if (unk132c->unk1 == 3)
        {
            if (unk132c->unk10.y > 248)
                oam->priority = 2;
            else
                oam->priority = 3;
        }
        else
        {
            oam->priority = unk132c->unk1;
        }

        DmaCopy16(3, gUnknown_083BB16C[gCurrentPinballGame->unk5F6 * 17 + r8], (void *)0x6010400, 0x80);

        if (mainUnk44->a.unk4 > 200)
            mainUnk44->a.unk4 = 200;
        if (mainUnk44->a.unk4 < -20)
            mainUnk44->a.unk4 = -20;

        oam->x = mainUnk44->b.unk2 + mainUnk44->a.unk2;
        if (unk132c->unk0)
            oam->y = 200;
        else
            oam->y = mainUnk44->b.unk4 + mainUnk44->a.unk4;
    }

    // _080128EA
    for (i = 4; i > 0; i--)
    {
        gCurrentPinballGame->unkD0[i].x = gCurrentPinballGame->unkD0[(i - 1)].x;
        gCurrentPinballGame->unkD0[i].y = gCurrentPinballGame->unkD0[(i - 1)].y;
    }

    gCurrentPinballGame->unkD0[0].x = unk132c->unk10.x - 7;
    gCurrentPinballGame->unkD0[0].y = unk132c->unk10.y - 7;
    if (gCurrentPinballGame->unk71)
    {
        for (i = 0; i < 2; i++)
        {
            mainUnk44 = gMain.unk44[i + 1];
            if (mainUnk44->a.unk0)
            {
                oam = &gOamBuffer[mainUnk44->b.unk0];
                oam->priority = unk132c->unk1;
                oam->x = mainUnk44->b.unk2 +
                         gCurrentPinballGame->unkD0[i + 1 * 2].x -
                         gCurrentPinballGame->unk4C;
                if (i == 0)
                {
                    oam->y = gCurrentPinballGame->unkD0[2].y - gCurrentPinballGame->unk4E + mainUnk44->b.unk4;
                }
                else if (i == 1)
                {
                    if (gMain.systemFrameCount % 2 == 0)
                        oam->y = gCurrentPinballGame->unkD0[4].y - gCurrentPinballGame->unk4E + mainUnk44->b.unk4;
                    else
                        oam->y = 200;
                }
            }
        }

        gMain.unk44[1]->a.unk0 = 1;
        gMain.unk44[2]->a.unk0 = 1;
        gMain.unk44[49]->a.unk0 = 1;
        gMain.unk44[0]->a.unk0 = 0;
    }
    else
    {
        // _08012A44
        for (i = 0; i < 2; i++)
        {
            mainUnk44 = gMain.unk44[i + 1];
            if (mainUnk44->a.unk0)
            {
                oam = &gOamBuffer[mainUnk44->b.unk0];
                oam->priority = unk132c->unk1;
                oam->x = mainUnk44->b.unk2 +
                         gCurrentPinballGame->unkD0[(i + 1) * 2].x -
                         gCurrentPinballGame->unk4C;
                oam->y = 200;
            }
        }

        gMain.unk44[1]->a.unk0 = 0;
        gMain.unk44[2]->a.unk0 = 0;
        gMain.unk44[49]->a.unk0 = 0;
        gMain.unk44[0]->a.unk0 = 1;
    }

    // _08012AE4
    mainUnk44 = gMain.unk44[43];
    if (mainUnk44->a.unk0)
    {
        if (gCurrentPinballGame->unk71C < 59)
        {
            mainUnk44->a.unk2 = gMain.unk44[0]->a.unk2 - 8;
            mainUnk44->a.unk4 = gMain.unk44[0]->a.unk4 - 8;
        }
        else
        {
            mainUnk44->a.unk2 = 0;
            mainUnk44->a.unk4 = 180;
        }

        DmaCopy16(3, gUnknown_083BD36C[gCurrentPinballGame->unk6E], (void *)0x6011EE0, 0x200);
        gOamBuffer[mainUnk44->b.unk0].x = mainUnk44->a.unk2 + mainUnk44->b.unk2;
        gOamBuffer[mainUnk44->b.unk0].y =  mainUnk44->a.unk4 + mainUnk44->b.unk4;
        gOamBuffer[mainUnk44->b.unk0].priority = unk132c->unk1;
        if (gCurrentPinballGame->unk71C < 14)
            gMain.unk44[43]->a.unk0 = 0;
    }
}
#else
NAKED
void sub_12524(void)
{
    asm_unified("\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r2, _080125F0 @ =gCurrentPinballGame\n\
	ldr r0, [r2]\n\
	ldr r1, _080125F4 @ =0x0000132C\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldrh r0, [r7, #0xa]\n\
	lsrs r0, r0, #0xc\n\
	mov r8, r0\n\
	movs r3, #0x12\n\
	ldrsh r1, [r7, r3]\n\
	movs r0, #0xaa\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _0801255A\n\
	movs r4, #0x10\n\
	ldrsh r0, [r7, r4]\n\
	cmp r0, #0x5a\n\
	beq _08012556\n\
	cmp r0, #0x95\n\
	bne _0801255A\n\
_08012556:\n\
	ldrh r0, [r7, #0xc]\n\
	strh r0, [r7, #0xa]\n\
_0801255A:\n\
	ldrh r0, [r7, #0xa]\n\
	strh r0, [r7, #0xc]\n\
	ldr r6, _080125F0 @ =gCurrentPinballGame\n\
	ldr r3, [r6]\n\
	ldr r1, _080125F8 @ =0x000005F7\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080125CE\n\
	movs r4, #0xbf\n\
	lsls r4, r4, #3\n\
	adds r2, r3, r4\n\
	ldrh r0, [r2]\n\
	cmp r0, #0\n\
	beq _080125CE\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080125CE\n\
	ldr r6, _080125FC @ =0x000005F6\n\
	adds r2, r3, r6\n\
	ldrb r3, [r2]\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	cmp r0, #0\n\
	ble _080125AC\n\
	subs r0, r3, #1\n\
	strb r0, [r2]\n\
	ldr r0, _080125F0 @ =gCurrentPinballGame\n\
	ldr r1, [r0]\n\
	adds r0, r1, r6\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _080125AC\n\
	adds r1, r1, r4\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #4\n\
	strh r0, [r1]\n\
_080125AC:\n\
	ldr r2, _08012600 @ =0x040000D4\n\
	ldr r1, _080125F0 @ =gCurrentPinballGame\n\
	ldr r0, [r1]\n\
	ldr r3, _080125FC @ =0x000005F6\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #5\n\
	ldr r1, _08012604 @ =gUnknown_08137E14\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _08012608 @ =0x05000220\n\
	str r0, [r2, #4]\n\
	ldr r0, _0801260C @ =0x80000010\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
_080125CE:\n\
	movs r4, #0x12\n\
	ldrsh r0, [r7, r4]\n\
	cmp r0, #0xf3\n\
	ble _08012614\n\
	ldr r6, _080125F0 @ =gCurrentPinballGame\n\
	ldr r0, [r6]\n\
	ldr r1, _08012610 @ =0x000005B2\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, [r6]\n\
	movs r3, #0xbb\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	strb r2, [r0]\n\
	b _08012620\n\
	.align 2, 0\n\
_080125F0: .4byte gCurrentPinballGame\n\
_080125F4: .4byte 0x0000132C\n\
_080125F8: .4byte 0x000005F7\n\
_080125FC: .4byte 0x000005F6\n\
_08012600: .4byte 0x040000D4\n\
_08012604: .4byte gUnknown_08137E14\n\
_08012608: .4byte 0x05000220\n\
_0801260C: .4byte 0x80000010\n\
_08012610: .4byte 0x000005B2\n\
_08012614:\n\
	ldr r4, _080126C8 @ =gCurrentPinballGame\n\
	ldr r0, [r4]\n\
	ldr r6, _080126CC @ =0x000005B2\n\
	adds r0, r0, r6\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
_08012620:\n\
	movs r1, #0x28\n\
	ldrsh r0, [r7, r1]\n\
	lsrs r1, r0, #0x1f\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	strh r0, [r7, #0x10]\n\
	movs r2, #0x2a\n\
	ldrsh r0, [r7, r2]\n\
	lsrs r1, r0, #0x1f\n\
	adds r0, r0, r1\n\
	asrs r0, r0, #1\n\
	strh r0, [r7, #0x12]\n\
	ldr r1, _080126D0 @ =gMain\n\
	ldr r0, [r1, #0x44]\n\
	ldr r6, [r0]\n\
	ldrh r0, [r6]\n\
	cmp r0, #0\n\
	bne _08012646\n\
	b _08012792\n\
_08012646:\n\
	movs r3, #0xe\n\
	ldrsh r1, [r7, r3]\n\
	adds r0, r1, #0\n\
	movs r2, #0\n\
	bl SetMatrixScale\n\
	ldr r0, _080126C8 @ =gCurrentPinballGame\n\
	ldr r3, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x4c\n\
	ldrh r0, [r0]\n\
	adds r0, #7\n\
	ldrh r2, [r7, #0x10]\n\
	subs r2, r2, r0\n\
	ldr r4, _080126D4 @ =0x000002AA\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	subs r2, r2, r0\n\
	strh r2, [r6, #2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x4e\n\
	ldrh r1, [r0]\n\
	adds r1, #7\n\
	ldrh r0, [r7, #0x12]\n\
	subs r0, r0, r1\n\
	ldr r4, _080126D8 @ =0x000005FC\n\
	adds r1, r3, r4\n\
	ldrh r1, [r1]\n\
	subs r0, r0, r1\n\
	adds r1, r3, #0\n\
	adds r1, #0xe6\n\
	ldrh r1, [r1]\n\
	movs r4, #0xb3\n\
	lsls r4, r4, #1\n\
	adds r3, r3, r4\n\
	subs r0, r0, r1\n\
	ldrh r3, [r3]\n\
	adds r0, r0, r3\n\
	strh r0, [r6, #4]\n\
	strh r2, [r7, #0x24]\n\
	ldrh r0, [r6, #4]\n\
	strh r0, [r7, #0x26]\n\
	movs r0, #8\n\
	adds r0, r0, r6\n\
	mov ip, r0\n\
	ldrh r0, [r6, #8]\n\
	lsls r0, r0, #3\n\
	ldr r1, _080126DC @ =gOamBuffer\n\
	adds r5, r0, r1\n\
	movs r0, #1\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #3\n\
	bne _080126E6\n\
	movs r1, #0x12\n\
	ldrsh r0, [r7, r1]\n\
	cmp r0, #0xf8\n\
	ble _080126E0\n\
	ldrb r0, [r5, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r0\n\
	movs r0, #8\n\
	orrs r1, r0\n\
	strb r1, [r5, #5]\n\
	b _080126FA\n\
	.align 2, 0\n\
_080126C8: .4byte gCurrentPinballGame\n\
_080126CC: .4byte 0x000005B2\n\
_080126D0: .4byte gMain\n\
_080126D4: .4byte 0x000002AA\n\
_080126D8: .4byte 0x000005FC\n\
_080126DC: .4byte gOamBuffer\n\
_080126E0:\n\
	ldrb r0, [r5, #5]\n\
	movs r1, #0xc\n\
	b _080126F6\n\
_080126E6:\n\
	movs r0, #3\n\
	ldrb r1, [r7, #1]\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r5, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
_080126F6:\n\
	orrs r0, r1\n\
	strb r0, [r5, #5]\n\
_080126FA:\n\
	ldr r3, _08012768 @ =0x040000D4\n\
	mov r2, r8\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r4, _0801276C @ =gCurrentPinballGame\n\
	ldr r0, [r4]\n\
	ldr r2, _08012770 @ =0x000005F6\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #4 @ r0 = unk5F6 * 16\n\
	adds r0, r0, r2 @ r0 = unk5F6 * 17\n\
	adds r1, r1, r0 @ r1 = (unk5F6 * 17) + r8\n\
	lsls r1, r1, #7 @ r1 = ((unk5F6 * 17) + r8) * 0x80\n\
	ldr r0, _08012774 @ =gUnknown_083BB16C\n\
	adds r1, r1, r0\n\
	str r1, [r3]\n\
	ldr r0, _08012778 @ =0x06010400\n\
	str r0, [r3, #4]\n\
	ldr r0, _0801277C @ =0x80000040\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	movs r3, #4\n\
	ldrsh r0, [r6, r3]\n\
	cmp r0, #0xc8\n\
	ble _08012732\n\
	movs r0, #0xc8\n\
	strh r0, [r6, #4]\n\
_08012732:\n\
	movs r4, #4\n\
	ldrsh r0, [r6, r4]\n\
	movs r1, #0x14\n\
	rsbs r1, r1, #0\n\
	cmp r0, r1\n\
	bge _08012740\n\
	strh r1, [r6, #4]\n\
_08012740:\n\
	mov r0, ip\n\
	movs r2, #2\n\
	ldrsh r1, [r0, r2]\n\
	movs r3, #2\n\
	ldrsh r0, [r6, r3]\n\
	adds r1, r1, r0\n\
	ldr r4, _08012780 @ =0x000001FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldrh r2, [r5, #2]\n\
	ldr r0, _08012784 @ =0xFFFFFE00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r5, #2]\n\
	movs r0, #0\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #0\n\
	beq _08012788\n\
	movs r0, #0xc8\n\
	b _08012790\n\
	.align 2, 0\n\
_08012768: .4byte 0x040000D4\n\
_0801276C: .4byte gCurrentPinballGame\n\
_08012770: .4byte 0x000005F6\n\
_08012774: .4byte gUnknown_083BB16C\n\
_08012778: .4byte 0x06010400\n\
_0801277C: .4byte 0x80000040\n\
_08012780: .4byte 0x000001FF\n\
_08012784: .4byte 0xFFFFFE00\n\
_08012788:\n\
	ldrb r0, [r6, #4]\n\
	mov r6, ip\n\
	ldrb r6, [r6, #4]\n\
	adds r0, r0, r6\n\
_08012790:\n\
	strb r0, [r5]\n\
_08012792:\n\
	ldr r1, _08012824 @ =gMain\n\
	ldr r0, [r1, #0x44]\n\
	adds r0, #0xc4\n\
	ldr r6, [r0]\n\
	ldrh r0, [r6]\n\
	cmp r0, #0\n\
	bne _080127A2\n\
	b _080128EA\n\
_080127A2:\n\
	movs r2, #0xe\n\
	ldrsh r1, [r7, r2]\n\
	adds r0, r1, #0\n\
	movs r2, #0\n\
	bl SetMatrixScale\n\
	ldr r0, _08012828 @ =gCurrentPinballGame\n\
	ldr r3, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x4c\n\
	ldrh r0, [r0]\n\
	adds r0, #7\n\
	ldrh r2, [r7, #0x10]\n\
	subs r2, r2, r0\n\
	ldr r4, _0801282C @ =0x000002AA\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	subs r2, r2, r0\n\
	strh r2, [r6, #2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x4e\n\
	ldrh r1, [r0]\n\
	adds r1, #7\n\
	ldrh r0, [r7, #0x12]\n\
	subs r0, r0, r1\n\
	ldr r4, _08012830 @ =0x000005FC\n\
	adds r1, r3, r4\n\
	ldrh r1, [r1]\n\
	subs r0, r0, r1\n\
	adds r1, r3, #0\n\
	adds r1, #0xe6\n\
	ldrh r1, [r1]\n\
	movs r4, #0xb3\n\
	lsls r4, r4, #1\n\
	adds r3, r3, r4\n\
	subs r0, r0, r1\n\
	ldrh r3, [r3]\n\
	adds r0, r0, r3\n\
	strh r0, [r6, #4]\n\
	strh r2, [r7, #0x24]\n\
	ldrh r0, [r6, #4]\n\
	strh r0, [r7, #0x26]\n\
	movs r0, #8\n\
	adds r0, r0, r6\n\
	mov ip, r0\n\
	ldrh r0, [r6, #8]\n\
	lsls r0, r0, #3\n\
	ldr r1, _08012834 @ =gOamBuffer\n\
	adds r5, r0, r1\n\
	movs r0, #1\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #3\n\
	bne _0801283E\n\
	movs r1, #0x12\n\
	ldrsh r0, [r7, r1]\n\
	cmp r0, #0xf8\n\
	ble _08012838\n\
	ldrb r0, [r5, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r0\n\
	movs r0, #8\n\
	orrs r1, r0\n\
	strb r1, [r5, #5]\n\
	b _08012852\n\
	.align 2, 0\n\
_08012824: .4byte gMain\n\
_08012828: .4byte gCurrentPinballGame\n\
_0801282C: .4byte 0x000002AA\n\
_08012830: .4byte 0x000005FC\n\
_08012834: .4byte gOamBuffer\n\
_08012838:\n\
	ldrb r0, [r5, #5]\n\
	movs r1, #0xc\n\
	b _0801284E\n\
_0801283E:\n\
	movs r0, #3\n\
	ldrb r1, [r7, #1]\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r5, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
_0801284E:\n\
	orrs r0, r1\n\
	strb r0, [r5, #5]\n\
_08012852:\n\
	ldr r3, _080128C0 @ =0x040000D4\n\
	mov r2, r8\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r4, _080128C4 @ =gCurrentPinballGame\n\
	ldr r0, [r4]\n\
	ldr r2, _080128C8 @ =0x000005F6\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #4\n\
	adds r0, r0, r2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #7\n\
	ldr r0, _080128CC @ =gUnknown_083BB16C\n\
	adds r1, r1, r0\n\
	str r1, [r3]\n\
	ldr r0, _080128D0 @ =0x06010400\n\
	str r0, [r3, #4]\n\
	ldr r0, _080128D4 @ =0x80000040\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	movs r3, #4\n\
	ldrsh r0, [r6, r3]\n\
	cmp r0, #0xc8\n\
	ble _0801288A\n\
	movs r0, #0xc8\n\
	strh r0, [r6, #4]\n\
_0801288A:\n\
	movs r4, #4\n\
	ldrsh r0, [r6, r4]\n\
	movs r1, #0x14\n\
	rsbs r1, r1, #0\n\
	cmp r0, r1\n\
	bge _08012898\n\
	strh r1, [r6, #4]\n\
_08012898:\n\
	mov r0, ip\n\
	movs r2, #2\n\
	ldrsh r1, [r0, r2]\n\
	movs r3, #2\n\
	ldrsh r0, [r6, r3]\n\
	adds r1, r1, r0\n\
	ldr r4, _080128D8 @ =0x000001FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldrh r2, [r5, #2]\n\
	ldr r0, _080128DC @ =0xFFFFFE00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r5, #2]\n\
	movs r0, #0\n\
	ldrsb r0, [r7, r0]\n\
	cmp r0, #0\n\
	beq _080128E0\n\
	movs r0, #0xc8\n\
	b _080128E8\n\
	.align 2, 0\n\
_080128C0: .4byte 0x040000D4\n\
_080128C4: .4byte gCurrentPinballGame\n\
_080128C8: .4byte 0x000005F6\n\
_080128CC: .4byte gUnknown_083BB16C\n\
_080128D0: .4byte 0x06010400\n\
_080128D4: .4byte 0x80000040\n\
_080128D8: .4byte 0x000001FF\n\
_080128DC: .4byte 0xFFFFFE00\n\
_080128E0:\n\
	ldrb r0, [r6, #4]\n\
	mov r6, ip\n\
	ldrb r6, [r6, #4]\n\
	adds r0, r0, r6\n\
_080128E8:\n\
	strb r0, [r5]\n\
_080128EA:\n\
	movs r3, #4\n\
	ldr r5, _080129D0 @ =gCurrentPinballGame\n\
LOOP:\n\
	ldr r2, [r5]\n\
	lsls r1, r3, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r4, r1, #2    @ r4 = i * 4\n\
	adds r4, r2, r4    @ r4 = gCurrentPinballGame + i * 4\n\
	subs r1, #1        @ r1 = i - 1\n\
	lsls r0, r1, #2    @ r0 = (i - 1) * 4\n\
	adds r2, r2, r0    @ r2 = gCurrentPinballGame + (i - 1) * 4\n\
	adds r0, r2, #0    @ r0 = gCurrentPinballGame + (i - 1) * 4\n\
	adds r0, #0xd0\n\
	ldrh r3, [r0]      @ r3 = gCurrentPinballGame.unkD0[i - 1][0]\n\
	adds r0, r4, #0\n\
	adds r0, #0xd0\n\
	strh r3, [r0]\n\
	adds r2, #0xd2\n\
	ldrh r0, [r2]\n\
	adds r4, #0xd2\n\
	strh r0, [r4]\n\
	lsls r1, r1, #0x10\n\
	lsrs r3, r1, #0x10\n\
	cmp r1, #0\n\
	bgt LOOP\n\
	ldr r0, _080129D0 @ =gCurrentPinballGame\n\
	ldr r2, [r0]\n\
	ldrh r0, [r7, #0x10]\n\
	subs r0, #7\n\
	adds r1, r2, #0\n\
	adds r1, #0xd0\n\
	strh r0, [r1]\n\
	ldrh r0, [r7, #0x12]\n\
	subs r0, #7\n\
	adds r1, #2\n\
	strh r0, [r1]\n\
	adds r0, r2, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08012940\n\
	b _08012A44\n\
_08012940:\n\
	movs r3, #0\n\
	ldr r1, _080129D4 @ =gMain\n\
	mov sb, r1\n\
	movs r2, #0xd\n\
	rsbs r2, r2, #0\n\
	mov sl, r2\n\
LOOP_2:\n\
	lsls r2, r3, #0x10\n\
	asrs r4, r2, #0x10\n\
	mov r3, sb\n\
	ldr r1, [r3, #0x44]  @ r1 = gMain.unk44\n\
	lsls r0, r4, #2      @ r0 = i * 4\n\
	adds r0, r0, r1      @ r0 = &gMain.unk44[0]\n\
	ldr r6, [r0, #4]\n\
	ldrh r0, [r6]        @ r6 = gMain.unk44[i].unk4\n\
	mov r8, r2\n\
	cmp r0, #0\n\
	beq LOOP_2_END\n\
	movs r0, #8\n\
	adds r0, r0, r6      @ r0 = gMain.unk44[i].unk4 + 8\n\
	mov ip, r0           @ ip = gMain.unk44[i].unk4 + 8\n\
	ldrh r0, [r6, #8]    @ r0 = \n\
	lsls r0, r0, #3\n\
	ldr r1, _080129D8 @ =gOamBuffer\n\
	adds r5, r0, r1\n\
	movs r0, #3\n\
	ldrb r1, [r7, #1]\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r5, #5]\n\
	mov r0, sl\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r5, #5]\n\
	mov r1, ip\n\
	movs r3, #2\n\
	ldrsh r2, [r1, r3] @ r2 = mainUnk44->arr[1].unk2\n\
	ldr r6, _080129D0  @ =gCurrentPinballGame\n\
	ldr r3, [r6]\n\
	adds r0, r4, #1    @ r0 = i + 1\n\
	lsls r0, r0, #3    @ r0 = (i + 1) * 8\n\
	adds r0, r3, r0    @ r0 = gCurrentPinballGame + (i + 1) * 8\n\
	adds r0, #0xd0     @ r0 = gCurrentPinballGame.unkD0[i + 1]\n\
	movs r6, #0\n\
	ldrsh r1, [r0, r6]\n\
	adds r0, r3, #0\n\
	adds r0, #0x4c\n\
	movs r6, #0\n\
	ldrsh r0, [r0, r6]\n\
	subs r1, r1, r0\n\
	adds r2, r2, r1\n\
	ldr r1, _080129DC @ =0x000001FF\n\
	adds r0, r1, #0\n\
	ands r2, r0\n\
	ldrh r1, [r5, #2]\n\
	ldr r0, _080129E0 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r5, #2]\n\
	cmp r4, #0\n\
	bne _080129E4\n\
	adds r0, r3, #0\n\
	adds r0, #0xda\n\
	ldrb r0, [r0]   @ r0 = gCurrentPinballGame->unkD0[5]\n\
	adds r1, r3, #0\n\
	adds r1, #0x4e\n\
	ldrb r1, [r1]\n\
	subs r0, r0, r1\n\
	mov r2, ip\n\
	ldrb r2, [r2, #4]\n\
	adds r0, r0, r2\n\
	b _08012A0A\n\
	.align 2, 0\n\
_080129D0: .4byte gCurrentPinballGame\n\
_080129D4: .4byte gMain\n\
_080129D8: .4byte gOamBuffer\n\
_080129DC: .4byte 0x000001FF\n\
_080129E0: .4byte 0xFFFFFE00\n\
_080129E4:\n\
	cmp r4, #1\n\
	bne LOOP_2_END\n\
	mov r6, sb\n\
	ldr r0, [r6, #0x4c]\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	bne _08012A08\n\
	adds r0, r3, #0\n\
	adds r0, #0xe2\n\
	ldrb r0, [r0]\n\
	adds r1, r3, #0\n\
	adds r1, #0x4e\n\
	ldrb r1, [r1]\n\
	subs r0, r0, r1\n\
	mov r1, ip\n\
	ldrb r1, [r1, #4]\n\
	adds r0, r0, r1\n\
	b _08012A0A\n\
_08012A08:\n\
	movs r0, #0xc8\n\
_08012A0A:\n\
	strb r0, [r5]\n\
LOOP_2_END:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	add r0, r8\n\
	lsrs r3, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble LOOP_2\n\
	ldr r2, _08012A40 @ =gMain\n\
	ldr r0, [r2, #0x44]\n\
	ldr r0, [r0, #4]\n\
	movs r2, #0\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	ldr r3, _08012A40 @ =gMain\n\
	ldr r0, [r3, #0x44]\n\
	ldr r0, [r0, #8]\n\
	strh r1, [r0]\n\
	ldr r0, [r3, #0x44]\n\
	adds r0, #0xc4\n\
	ldr r0, [r0]\n\
	strh r1, [r0]\n\
	ldr r0, [r3, #0x44]\n\
	ldr r0, [r0]\n\
	strh r2, [r0]\n\
	b _08012AE4\n\
	.align 2, 0\n\
_08012A40: .4byte gMain\n\
_08012A44:\n\
	movs r3, #0\n\
	ldr r4, _08012B14 @ =gMain\n\
	mov sl, r4\n\
	movs r6, #3\n\
	mov sb, r6\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	mov ip, r0\n\
	ldr r1, _08012B18 @ =0xFFFFFE00\n\
	mov r8, r1\n\
LOOP_3:\n\
	lsls r0, r3, #0x10\n\
	asrs r4, r0, #0x10\n\
	mov r2, sl\n\
	ldr r1, [r2, #0x44]\n\
	lsls r0, r4, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0, #4]\n\
	ldrh r0, [r6]\n\
	cmp r0, #0\n\
	beq LOOP_3_END\n\
	ldrh r0, [r6, #8]\n\
	lsls r0, r0, #3\n\
	ldr r1, _08012B1C @ =gOamBuffer\n\
	adds r5, r0, r1\n\
	ldrb r1, [r7, #1]\n\
	mov r3, sb\n\
	ands r1, r3\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r5, #5]\n\
	mov r0, ip\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r5, #5]\n\
	movs r0, #0xa\n\
	ldrsh r3, [r6, r0]\n\
	ldr r1, _08012B20 @ =gCurrentPinballGame\n\
	ldr r2, [r1]\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #3\n\
	adds r0, r2, r0\n\
	adds r0, #0xd0\n\
	movs r6, #0\n\
	ldrsh r1, [r0, r6]\n\
	adds r2, #0x4c\n\
	movs r6, #0\n\
	ldrsh r0, [r2, r6]\n\
	subs r1, r1, r0\n\
	adds r3, r3, r1\n\
	ldr r1, _08012B24 @ =0x000001FF\n\
	adds r0, r1, #0\n\
	ands r3, r0\n\
	ldrh r1, [r5, #2]\n\
	mov r0, r8\n\
	ands r0, r1\n\
	orrs r0, r3\n\
	strh r0, [r5, #2]\n\
	movs r0, #0xc8\n\
	strb r0, [r5]\n\
LOOP_3_END:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	ble LOOP_3\n\
	ldr r2, _08012B14 @ =gMain\n\
	ldr r0, [r2, #0x44]\n\
	ldr r0, [r0, #4]\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, [r2, #0x44]\n\
	ldr r0, [r0, #8]\n\
	strh r1, [r0]\n\
	ldr r0, [r2, #0x44]\n\
	adds r0, #0xc4\n\
	ldr r0, [r0]\n\
	strh r1, [r0]\n\
	ldr r0, [r2, #0x44]\n\
	ldr r1, [r0]\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
_08012AE4:\n\
	ldr r3, _08012B14 @ =gMain\n\
	ldr r1, [r3, #0x44]\n\
	adds r0, r1, #0\n\
	adds r0, #0xac\n\
	ldr r6, [r0]\n\
	ldrh r0, [r6]\n\
	cmp r0, #0\n\
	beq END\n\
	ldr r4, _08012B20 @ =gCurrentPinballGame\n\
	ldr r0, [r4]\n\
	ldr r2, _08012B28 @ =0x0000071C\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0x3a\n\
	bhi _08012B2C\n\
	ldr r0, [r1]\n\
	ldrh r0, [r0, #2]\n\
	subs r0, #8\n\
	strh r0, [r6, #2]\n\
	ldr r0, [r3, #0x44]\n\
	ldr r0, [r0]\n\
	ldrh r0, [r0, #4]\n\
	subs r0, #8\n\
	b _08012B32\n\
	.align 2, 0\n\
_08012B14: .4byte gMain\n\
_08012B18: .4byte 0xFFFFFE00\n\
_08012B1C: .4byte gOamBuffer\n\
_08012B20: .4byte gCurrentPinballGame\n\
_08012B24: .4byte 0x000001FF\n\
_08012B28: .4byte 0x0000071C\n\
_08012B2C:\n\
	movs r0, #0\n\
	strh r0, [r6, #2]\n\
	movs r0, #0xb4\n\
_08012B32:\n\
	strh r0, [r6, #4]\n\
	ldr r3, _08012BD0 @ =gCurrentPinballGame\n\
	ldr r0, [r3]\n\
	adds r0, #0x6e\n\
	ldr r2, _08012BD4 @ =0x040000D4\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #9\n\
	ldr r1, _08012BD8 @ =gUnknown_083BD36C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _08012BDC @ =0x06011EE0\n\
	str r0, [r2, #4]\n\
	ldr r0, _08012BE0 @ =0x80000100\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	movs r4, #8\n\
	adds r4, r4, r6\n\
	mov ip, r4\n\
	ldr r4, _08012BE4 @ =gOamBuffer\n\
	ldrh r2, [r6, #8]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r4\n\
	mov r0, ip\n\
	movs r3, #2\n\
	ldrsh r1, [r0, r3]\n\
	movs r3, #2\n\
	ldrsh r0, [r6, r3]\n\
	adds r1, r1, r0\n\
	ldr r3, _08012BE8 @ =0x000001FF\n\
	adds r0, r3, #0\n\
	ands r1, r0\n\
	ldrh r3, [r2, #2]\n\
	ldr r0, _08012BEC @ =0xFFFFFE00\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strh r0, [r2, #2]\n\
	ldrh r1, [r6, #8]\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r4\n\
	ldrb r0, [r6, #4]\n\
	mov r2, ip\n\
	ldrb r2, [r2, #4]\n\
	adds r0, r0, r2\n\
	strb r0, [r1]\n\
	ldrh r2, [r6, #8]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r4\n\
	movs r0, #3\n\
	ldrb r1, [r7, #1]\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r3, [r2, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	orrs r0, r1\n\
	strb r0, [r2, #5]\n\
	ldr r3, _08012BD0 @ =gCurrentPinballGame\n\
	ldr r0, [r3]\n\
	ldr r4, _08012BF0 @ =0x0000071C\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xd\n\
	bhi END\n\
	ldr r6, _08012BF4 @ =gMain\n\
	ldr r0, [r6, #0x44]\n\
	adds r0, #0xac\n\
	ldr r1, [r0]\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
END:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08012BD0: .4byte gCurrentPinballGame\n\
_08012BD4: .4byte 0x040000D4\n\
_08012BD8: .4byte gUnknown_083BD36C\n\
_08012BDC: .4byte 0x06011EE0\n\
_08012BE0: .4byte 0x80000100\n\
_08012BE4: .4byte gOamBuffer\n\
_08012BE8: .4byte 0x000001FF\n\
_08012BEC: .4byte 0xFFFFFE00\n\
_08012BF0: .4byte 0x0000071C\n\
_08012BF4: .4byte gMain\n\
    ");
}
#endif
