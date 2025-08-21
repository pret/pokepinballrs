#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_30EB4
sub_30EB4: @ 0x08030EB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _0803100C @ =gMain+0x30F8 @gMain.spriteGroups[64]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08030EC8
	b _0803110C
_08030EC8:
	ldr r3, _08031010 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xa
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r3]
	movs r7, #0xc9
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r2, _08031014 @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08031018 @ =gUnknown_0844F20C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0803101C @ =0x060139A0
	str r0, [r2, #4]
	ldr r0, _08031020 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r5, #0
	mov sl, r3
	ldr r0, _08031024 @ =gOamBuffer
	mov sb, r0
	mov r7, sb
	ldr r1, _08031028 @ =0xFFFFFE00
	mov ip, r1
_08030F18:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r0, _0803102C @ =0x000001FF
	mov r8, r0
	mov r2, r8
	ands r1, r2
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08030F18
	ldr r6, _08031030 @ =gMain+0x33D8 @gMain.spriteGroups[68]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xa
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r7, #0x95
	lsls r7, r7, #1
	adds r0, r7, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	mov r7, r8
	ands r1, r7
	ldrh r3, [r2, #2]
	ldr r0, _08031028 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	movs r3, #0
	ldr r0, _08031014 @ =0x040000D4
	mov sl, r0
_08030FB4:
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	movs r0, #0xb8
	muls r0, r2, r0
	ldr r1, _08031034 @ =gMain+0x31B0 @gMain.spriteGroups[65]
	adds r6, r0, r1
	lsls r5, r2, #1
	ldr r7, _08031038 @ =gUnknown_086AE544
	adds r0, r5, r7
	ldrh r1, [r0]
	subs r1, r1, r2
	ldr r0, _08031010 @ =gCurrentPinballGame
	ldr r4, [r0]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r6, #2]
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r0, r4, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r3
	cmp r0, #0
	ble _0803103C
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r0, r0, r5
	movs r3, #0x92
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r6, #4]
	b _08031040
	.align 2, 0
_0803100C: .4byte gMain+0x30F8 @gMain.spriteGroups[64]
_08031010: .4byte gCurrentPinballGame
_08031014: .4byte 0x040000D4
_08031018: .4byte gUnknown_0844F20C
_0803101C: .4byte 0x060139A0
_08031020: .4byte 0x80000140
_08031024: .4byte gOamBuffer
_08031028: .4byte 0xFFFFFE00
_0803102C: .4byte 0x000001FF
_08031030: .4byte gMain+0x33D8 @gMain.spriteGroups[68]
_08031034: .4byte gMain+0x31B0 @gMain.spriteGroups[65]
_08031038: .4byte gUnknown_086AE544
_0803103C:
	movs r0, #0xc8
	strh r0, [r6, #4]
_08031040:
	ldr r7, _0803111C @ =gCurrentPinballGame
	ldr r3, [r7]
	mov r0, sb
	asrs r2, r0, #0x10
	ldr r1, _08031120 @ =0x0000032F
	adds r0, r3, r1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r7, _08031124 @ =gUnknown_084FDF8C
	adds r0, r0, r7
	mov r1, sl
	str r0, [r1]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r7, _08031128 @ =0x06013C20
	adds r0, r0, r7
	str r0, [r1, #4]
	ldr r0, _0803112C @ =0x800000B0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08031130 @ =0x00000332
	adds r3, r3, r0
	adds r3, r3, r2
	movs r5, #0
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	mov r8, r0
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
_0803108E:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r1, _08031134 @ =gOamBuffer
	adds r2, r2, r1
	ldr r1, _08031138 @ =gUnknown_086B3E1E
	add r1, ip
	add r1, r8
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r7, _08031134 @ =gOamBuffer
	adds r2, r2, r7
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0803113C @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldr r0, _08031140 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	ldr r0, _08031134 @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _0803108E
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0803110C
	b _08030FB4
_0803110C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803111C: .4byte gCurrentPinballGame
_08031120: .4byte 0x0000032F
_08031124: .4byte gUnknown_084FDF8C
_08031128: .4byte 0x06013C20
_0803112C: .4byte 0x800000B0
_08031130: .4byte 0x00000332
_08031134: .4byte gOamBuffer
_08031138: .4byte gUnknown_086B3E1E
_0803113C: .4byte 0x000001FF
_08031140: .4byte 0xFFFFFE00

	thumb_func_start sub_31144
sub_31144: @ 0x08031144
	push {r4, r5, r6, r7, lr}
	ldr r1, _08031190 @ =gCurrentPinballGame
	ldr r5, [r1]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r7, r1, #0
	cmp r2, #0
	beq _0803115C
	b _080312D0
_0803115C:
	ldr r3, _08031194 @ =0x000001A5
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080311DC
	movs r4, #0xda
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r1, [r0]
	cmp r1, #0x5f
	bhi _080311CC
	cmp r1, #7
	bhi _0803119C
	ldr r1, _08031198 @ =gUnknown_08137CF6
	ldrh r0, [r0]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r1, #8
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080311B4
	.align 2, 0
_08031190: .4byte gCurrentPinballGame
_08031194: .4byte 0x000001A5
_08031198: .4byte gUnknown_08137CF6
_0803119C:
	ldr r2, _080311C8 @ =gUnknown_08137CE2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r2, #0xa
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
_080311B4:
	strb r1, [r0]
	ldr r1, [r7]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080311CE
	.align 2, 0
_080311C8: .4byte gUnknown_08137CE2
_080311CC:
	strh r2, [r0]
_080311CE:
	ldr r0, [r7]
	ldr r2, _080311D8 @ =0x000001AD
	adds r1, r0, r2
	movs r0, #2
	b _0803123E
	.align 2, 0
_080311D8: .4byte 0x000001AD
_080311DC:
	movs r3, #0xda
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x77
	bhi _08031234
	cmp r1, #7
	bhi _08031204
	ldr r1, _08031200 @ =gUnknown_08137CF6
	ldrh r0, [r0]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	b _0803121E
	.align 2, 0
_08031200: .4byte gUnknown_08137CF6
_08031204:
	ldr r4, _08031230 @ =gUnknown_08137CE2
	ldrh r0, [r0]
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x13
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
_0803121E:
	strb r1, [r0]
	ldr r1, [r7]
	movs r3, #0xda
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08031236
	.align 2, 0
_08031230: .4byte gUnknown_08137CE2
_08031234:
	strh r2, [r0]
_08031236:
	ldr r0, [r7]
	ldr r4, _08031288 @ =0x000001AD
	adds r1, r0, r4
	movs r0, #0
_0803123E:
	strb r0, [r1]
	ldr r1, [r7]
	ldr r2, _0803128C @ =0x0000072E
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08031298
	ldr r3, _08031290 @ =0x00000281
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _08031260
	b _08031396
_08031260:
	ldr r4, _08031294 @ =0x000001A5
	adds r0, r1, r4
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	beq _0803126E
	b _08031396
_0803126E:
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r7]
	adds r4, #0xf
	adds r0, r2, r4
	strh r3, [r0]
	ldr r3, _08031294 @ =0x000001A5
	adds r0, r2, r3
	strb r1, [r0]
	b _08031396
	.align 2, 0
_08031288: .4byte 0x000001AD
_0803128C: .4byte 0x0000072E
_08031290: .4byte 0x00000281
_08031294: .4byte 0x000001A5
_08031298:
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bne _080312A2
	b _08031396
_080312A2:
	ldr r4, _080312CC @ =0x000001A5
	adds r0, r1, r4
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #1
	bne _08031396
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	strb r3, [r0]
	ldr r3, [r7]
	adds r4, #0xf
	adds r0, r3, r4
	movs r1, #0
	strh r2, [r0]
	ldr r2, _080312CC @ =0x000001A5
	adds r0, r3, r2
	strb r1, [r0]
	b _08031396
	.align 2, 0
_080312CC: .4byte 0x000001A5
_080312D0:
	ldr r4, _0803131C @ =gUnknown_08137D06
	movs r6, #0xda
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	ldr r3, _08031320 @ =0x000001A5
	adds r1, r5, r3
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r3, #0
	strb r2, [r1]
	ldr r1, [r7]
	adds r0, r1, r0
	ldrb r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08031328
	ldr r4, _08031324 @ =0x000001AD
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	b _0803136A
	.align 2, 0
_0803131C: .4byte gUnknown_08137D06
_08031320: .4byte 0x000001A5
_08031324: .4byte 0x000001AD
_08031328:
	ldr r2, _08031344 @ =0x000001A5
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0803134C
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0xe
	bls _08031364
	ldr r0, _08031348 @ =0x000001AD
	adds r1, r1, r0
	b _08031358
	.align 2, 0
_08031344: .4byte 0x000001A5
_08031348: .4byte 0x000001AD
_0803134C:
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0xe
	bhi _08031364
	ldr r2, _08031360 @ =0x000001AD
	adds r1, r1, r2
_08031358:
	movs r0, #2
	strb r0, [r1]
	b _0803136A
	.align 2, 0
_08031360: .4byte 0x000001AD
_08031364:
	ldr r4, _0803139C @ =0x000001AD
	adds r0, r1, r4
	strb r3, [r0]
_0803136A:
	ldr r2, [r7]
	movs r0, #0xda
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2a
	bne _08031396
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r7]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
_08031396:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803139C: .4byte 0x000001AD
