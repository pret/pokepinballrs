#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
