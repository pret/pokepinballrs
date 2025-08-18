#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1FF0C
sub_1FF0C: @ 0x0801FF0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r1, #0
	ldr r6, _0801FF70 @ =gCurrentPinballGame
	mov sb, r6
	ldr r0, _0801FF74 @ =0x000002E3
	mov sl, r0
	movs r2, #0xba
	lsls r2, r2, #2
	mov r8, r2
	movs r3, #0xbb
	lsls r3, r3, #2
	mov ip, r3
_0801FF2E:
	mov r4, sb
	ldr r3, [r4]
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	mov r7, sl
	adds r1, r3, r7
	adds r1, r1, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r0, [sp]
	cmp r1, #0
	ble _08020012
	ldr r1, _0801FF78 @ =0x000002E5
	adds r0, r3, r1
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r1, r1, #2
	ldr r2, _0801FF7C @ =gUnknown_086ADEB2
	adds r1, r1, r2
	lsls r2, r5, #1
	mov r7, r8
	adds r0, r3, r7
	adds r2, r0, r2
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0801FF80
	adds r0, r3, #1
	strh r0, [r2]
	b _0801FFAE
	.align 2, 0
_0801FF70: .4byte gCurrentPinballGame
_0801FF74: .4byte 0x000002E3
_0801FF78: .4byte 0x000002E5
_0801FF7C: .4byte gUnknown_086ADEB2
_0801FF80:
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _08020070 @ =0x000002E5
	adds r0, r0, r2
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	ble _0801FFAE
	strb r3, [r1]
	mov r3, sb
	ldr r1, [r3]
	add r1, sl
	adds r1, r1, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801FFAE:
	ldr r3, [r6]
	ldr r7, [sp]
	asrs r4, r7, #0x10
	ldr r5, _08020070 @ =0x000002E5
	adds r0, r3, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0801FFD8
	lsls r2, r4, #1
	mov r0, ip
	adds r1, r3, r0
	adds r1, r1, r2
	mov r7, r8
	adds r0, r3, r7
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
_0801FFD8:
	ldr r1, [r6]
	adds r0, r1, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r3, r4, #1
	cmp r0, #0xb
	bne _08020000
	mov r0, ip
	adds r2, r1, r0
	adds r2, r2, r3
	mov r4, r8
	adds r0, r1, r4
	adds r0, r0, r3
	ldrh r1, [r0]
	lsrs r1, r1, #1
	movs r0, #0xe
	subs r0, r0, r1
	strh r0, [r2]
_08020000:
	ldr r0, [r6]
	add r0, ip
	adds r2, r0, r3
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r0, #2
	bgt _08020012
	movs r0, #3
	strh r0, [r2]
_08020012:
	ldr r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r1, r2
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0801FF2E
	ldr r1, [r6]
	ldr r3, _08020074 @ =0x000002E2
	adds r0, r1, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _08020032
	b _0802018E
_08020032:
	cmp r3, #1
	bne _08020120
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #7
	bne _08020040
	b _08020136
_08020040:
	cmp r0, #2
	bgt _080200C4
	ldr r4, _08020078 @ =0x000006BD
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08020136
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020080
	ldr r7, _0802007C @ =0x000002C2
	adds r0, r1, r7
	strb r2, [r0]
	b _08020110
	.align 2, 0
_08020070: .4byte 0x000002E5
_08020074: .4byte 0x000002E2
_08020078: .4byte 0x000006BD
_0802007C: .4byte 0x000002C2
_08020080:
	cmp r0, #2
	bne _0802009C
	ldr r3, _08020098 @ =0x000002C2
	adds r1, r1, r3
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r6]
	movs r4, #0xb0
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r2, [r0]
	b _08020136
	.align 2, 0
_08020098: .4byte 0x000002C2
_0802009C:
	cmp r0, #3
	bne _08020136
	ldr r7, _080200BC @ =0x000002C2
	adds r1, r1, r7
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, [r6]
	movs r4, #0xb0
	lsls r4, r4, #2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r7, _080200C0 @ =0x000006C2
	adds r0, r0, r7
	strh r3, [r0]
	b _08020136
	.align 2, 0
_080200BC: .4byte 0x000002C2
_080200C0: .4byte 0x000006C2
_080200C4:
	ldr r0, _080200FC @ =0x000006BD
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08020136
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r1]
	ldr r1, [r6]
	ldr r3, _080200FC @ =0x000006BD
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020104
	ldr r4, _08020100 @ =0x000002C2
	adds r0, r1, r4
	strb r2, [r0]
	ldr r0, [r6]
	movs r7, #0xb0
	lsls r7, r7, #2
	adds r0, r0, r7
	strh r2, [r0]
	b _08020136
	.align 2, 0
_080200FC: .4byte 0x000006BD
_08020100: .4byte 0x000002C2
_08020104:
	cmp r0, #2
	bne _08020136
	ldr r0, _0802011C @ =0x000002C2
	adds r1, r1, r0
	movs r0, #0xc
	strb r0, [r1]
_08020110:
	ldr r0, [r6]
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
	b _08020136
	.align 2, 0
_0802011C: .4byte 0x000002C2
_08020120:
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08020132
	movs r0, #1
	b _08020134
_08020132:
	movs r0, #0
_08020134:
	strb r0, [r1]
_08020136:
	ldr r0, [r6]
	ldr r3, _080201A0 @ =0x000002E3
	adds r0, r0, r3
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r6]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r0, r0, r7
	strb r4, [r0]
	ldr r0, [r6]
	ldr r1, _080201A4 @ =0x000002E2
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #7
	bl sub_11B0
	movs r0, 0xB7 @=SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r0, [r6]
	ldr r1, _080201A8 @ =0x00000BB8
	str r1, [r0, #0x3c]
	ldr r2, _080201AC @ =0x000002E5
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _080201B0 @ =0x000002E6
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r6]
	adds r7, #4
	adds r0, r1, r7
	strh r4, [r0]
	adds r2, #5
	adds r0, r1, r2
	strh r4, [r0]
	adds r3, #6
	adds r0, r1, r3
	movs r2, #3
	strh r2, [r0]
	ldr r4, _080201B4 @ =0x000002EE
	adds r1, r1, r4
	strh r2, [r1]
_0802018E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080201A0: .4byte 0x000002E3
_080201A4: .4byte 0x000002E2
_080201A8: .4byte 0x00000BB8
_080201AC: .4byte 0x000002E5
_080201B0: .4byte 0x000002E6
_080201B4: .4byte 0x000002EE

	thumb_func_start sub_201B8
sub_201B8: @ 0x080201B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0
	ldr r0, _080202D0 @ =gCurrentPinballGame
	mov sl, r0
	ldr r2, _080202D4 @ =0x040000D4
	mov r8, r2
_080201CC:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
	ldr r4, _080202D8 @ =0x000002E5
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r5, _080202DC @ =gUnknown_086ADEB0
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	ldr r4, _080202E0 @ =gUnknown_0847FD0C
	adds r0, r0, r4
	mov r5, r8
	str r0, [r5]
	lsls r0, r3, #8
	ldr r2, _080202E4 @ =0x06012A20
	adds r0, r0, r2
	str r0, [r5, #4]
	ldr r0, _080202E8 @ =0x80000080
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0xb8
	muls r0, r3, r0
	ldr r4, _080202EC @ =gMain+0x2D60 @gMain.spriteGroups[59]
	adds r6, r0, r4
	ldrh r0, [r6]
	mov sb, r1
	cmp r0, #0
	beq _0802029A
	lsls r1, r3, #4
	subs r1, r1, r3
	lsls r1, r1, #3
	adds r1, #0x30
	mov r5, sl
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r3, r3, #1
	movs r2, #1
	subs r2, r2, r3
	movs r5, #0xbb
	lsls r5, r5, #2
	adds r0, r4, r5
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #0xe
	muls r0, r2, r0
	adds r1, r1, r0
	strh r1, [r6, #2]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r4, _080202F0 @ =0x0000012D
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _080202F4 @ =gOamBuffer
	ldr r5, _080202F8 @ =0xFFFFFE00
	mov ip, r5
_08020256:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	lsls r5, r3, #3
	adds r5, #8
	adds r5, r6, r5
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r4, _080202FC @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, ip
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _08020256
_0802029A:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080201CC
	mov r5, sl
	ldr r2, [r5]
	ldr r0, _08020300 @ =0x000006C2
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08020398
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08020398
	adds r2, #0xe4
	ldrb r0, [r2]
	cmp r0, #0
	beq _08020304
	movs r0, #1
	strh r0, [r1]
	b _08020308
	.align 2, 0
_080202D0: .4byte gCurrentPinballGame
_080202D4: .4byte 0x040000D4
_080202D8: .4byte 0x000002E5
_080202DC: .4byte gUnknown_086ADEB0
_080202E0: .4byte gUnknown_0847FD0C
_080202E4: .4byte 0x06012A20
_080202E8: .4byte 0x80000080
_080202EC: .4byte gMain+0x2D60 @gMain.spriteGroups[59]
_080202F0: .4byte 0x0000012D
_080202F4: .4byte gOamBuffer
_080202F8: .4byte 0xFFFFFE00
_080202FC: .4byte 0x000001FF
_08020300: .4byte 0x000006C2
_08020304:
	movs r0, #4
	strb r0, [r2]
_08020308:
	mov r1, sl
	ldr r4, [r1]
	ldr r2, _080203A8 @ =0x000006C2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _08020398
	ldr r2, _080203AC @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r1, r4, #0
	adds r1, #0xea
	movs r3, #0
	movs r0, #0x46
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r5, [r0]
	subs r0, #2
	strh r5, [r0]
	adds r0, #8
	strh r5, [r0]
	adds r1, #6
	movs r0, #4
	strb r0, [r1]
	mov r4, sl
	ldr r0, [r4]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0xfb
	strb r3, [r0]
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0xf4
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf6
	strh r5, [r0]
	subs r1, #4
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf8
	strh r5, [r0]
	ldr r1, _080203B0 @ =0x040000D4
	ldr r0, _080203B4 @ =gUnknown_086ACEF8
	ldr r0, [r0, #0x10]
	str r0, [r1]
	ldr r0, _080203B8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080203BC @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080203C0 @ =gUnknown_086ACF18
	ldr r0, [r0, #0x10]
	str r0, [r1]
	ldr r0, _080203C4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080203C8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_08020398:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080203A8: .4byte 0x000006C2
_080203AC: .4byte gMain
_080203B0: .4byte 0x040000D4
_080203B4: .4byte gUnknown_086ACEF8
_080203B8: .4byte 0x06015800
_080203BC: .4byte 0x80001200
_080203C0: .4byte gUnknown_086ACF18
_080203C4: .4byte 0x050003C0
_080203C8: .4byte 0x80000010

	thumb_func_start sub_203CC
sub_203CC: @ 0x080203CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_20EC0
	ldr r6, _0802042C @ =gCurrentPinballGame
	ldr r5, [r6]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa7
	ble _0802044C
	ldr r4, _08020430 @ =gUnknown_086ADF48
	ldr r0, _08020434 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0xa0
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r3, _08020438 @ =0x00000744
	adds r0, r5, r3
	strb r1, [r0]
	ldr r2, [r6]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020440
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #6
	ldr r5, _0802043C @ =0x00000745
	adds r1, r2, r5
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_0802042C: .4byte gCurrentPinballGame
_08020430: .4byte gUnknown_086ADF48
_08020434: .4byte gMain
_08020438: .4byte 0x00000744
_0802043C: .4byte 0x00000745
_08020440:
	ldr r7, _08020448 @ =0x00000744
	adds r0, r2, r7
	b _08020494
	.align 2, 0
_08020448: .4byte 0x00000744
_0802044C:
	ldr r0, _08020484 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	ldr r4, _08020488 @ =0x00000744
	adds r1, r5, r4
	strb r0, [r1]
	ldr r2, [r6]
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020490
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #9
	ldr r7, _0802048C @ =0x00000745
	adds r1, r2, r7
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_08020484: .4byte gMain
_08020488: .4byte 0x00000744
_0802048C: .4byte 0x00000745
_08020490:
	ldr r1, _080204C8 @ =0x00000744
	adds r0, r2, r1
_08020494:
	ldrb r1, [r0]
	ldr r3, _080204CC @ =0x00000745
	adds r0, r2, r3
	strb r1, [r0]
_0802049C:
	ldr r1, _080204D0 @ =gCurrentPinballGame
	ldr r5, [r1]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r3, r5, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	mov sl, r1
	cmp r0, #2
	bne _080204D8
	ldr r7, _080204D4 @ =0x000001E3
	adds r0, r5, r7
	movs r1, #1
	strb r1, [r0]
	mov r2, sl
	ldr r0, [r2]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	b _08020500
	.align 2, 0
_080204C8: .4byte 0x00000744
_080204CC: .4byte 0x00000745
_080204D0: .4byte gCurrentPinballGame
_080204D4: .4byte 0x000001E3
_080204D8:
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldr r3, _0802060C @ =0x000001E3
	adds r0, r5, r3
	adds r0, r0, r1
	movs r4, #0
	movs r2, #1
	strb r2, [r0]
	mov r5, sl
	ldr r0, [r5]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r1, r0, r7
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r2, r2, r1
	adds r0, r0, r3
	adds r0, r0, r2
	strb r4, [r0]
_08020500:
	mov r0, sl
	ldr r1, [r0]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r4, [r2]
	cmp r4, #0
	bne _08020512
	b _0802073A
_08020512:
	cmp r4, #0x78
	beq _08020518
	b _080206CC
_08020518:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08020538
	b _080206CC
_08020538:
	movs r6, #0xe3
	lsls r6, r6, #1
	adds r0, r1, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa7
	ble _08020630
	movs r5, #0
	movs r3, #1
	strb r3, [r1, #0x1f]
	mov r7, sl
	ldr r0, [r7]
	ldr r1, _08020610 @ =0x0000061C
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, [r7]
	movs r7, #0xef
	lsls r7, r7, #1
	adds r2, r1, r7
	movs r0, #0
	mov r8, r0
	strh r4, [r2]
	adds r7, #2
	adds r0, r1, r7
	strh r4, [r0]
	ldrh r2, [r2]
	ldr r4, _08020614 @ =0x0000061E
	adds r0, r1, r4
	strh r2, [r0]
	ldr r7, _08020618 @ =0x000005F7
	adds r1, r1, r7
	strb r3, [r1]
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x82
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _0802061C @ =0x0000020A
	adds r0, r0, r3
	mov r4, r8
	strb r4, [r0]
	mov r7, sl
	ldr r2, [r7]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080205E4
	adds r0, r2, r6
	strh r5, [r0]
	subs r3, #0x42
	adds r0, r2, r3
	strh r5, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r5, [r0]
	movs r7, #0xe5
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r5, [r0]
	subs r1, #0xe
	adds r0, r2, r1
	strh r5, [r0]
	adds r3, #0xe
	adds r1, r2, r3
	ldr r0, _08020620 @ =0x0000FFFC
	strh r0, [r1]
	adds r4, #0xc
	adds r0, r2, r4
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r7, #0x10
	adds r0, r2, r7
	strh r1, [r0]
	adds r1, #0xce
	adds r0, r2, r1
	strh r5, [r0]
	subs r3, #6
	adds r0, r2, r3
	strh r5, [r0]
_080205E4:
	mov r4, sl
	ldr r1, [r4]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r2, r1, r5
	ldr r7, _08020624 @ =0x0000132C
	adds r0, r1, r7
	ldr r0, [r0]
	ldr r0, [r0, #0x28]
	str r0, [r2]
	ldr r0, _08020628 @ =0x00007530
	str r0, [r1, #0x3c]
	ldr r0, _0802062C @ =0x0000062E
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802063C
	adds r0, #1
	strb r0, [r1]
	b _0802063C
	.align 2, 0
_0802060C: .4byte 0x000001E3
_08020610: .4byte 0x0000061C
_08020614: .4byte 0x0000061E
_08020618: .4byte 0x000005F7
_0802061C: .4byte 0x0000020A
_08020620: .4byte 0x0000FFFC
_08020624: .4byte 0x0000132C
_08020628: .4byte 0x00007530
_0802062C: .4byte 0x0000062E
_08020630:
	movs r0, #0x3c
	strh r0, [r2]
	ldr r0, _0802067C @ =gMPlayInfo_SE1
	ldr r1, _08020680 @ =gUnknown_086A2FA0
	bl MPlayStart
_0802063C:
	ldr r0, _08020684 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #2
	bne _0802068C
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r4, _08020688 @ =0x00000744
	adds r2, r5, r4
	adds r2, r2, r1
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, #2
	strb r0, [r2]
	mov r8, r3
	b _0802069C
	.align 2, 0
_0802067C: .4byte gMPlayInfo_SE1
_08020680: .4byte gUnknown_086A2FA0
_08020684: .4byte gCurrentPinballGame
_08020688: .4byte 0x00000744
_0802068C:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r7, _08020700 @ =0x00000744
	adds r0, r5, r7
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	mov r8, r2
_0802069C:
	ldr r3, _08020704 @ =0x040000D4
	mov r1, sl
	ldr r0, [r1]
	mov r4, r8
	asrs r2, r4, #0x10
	ldr r5, _08020700 @ =0x00000744
	adds r0, r0, r5
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020708 @ =gUnknown_084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r7, _0802070C @ =0x06010480
	adds r0, r0, r7
	str r0, [r3, #4]
	ldr r0, _08020710 @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_080206CC:
	mov r0, sl
	ldr r2, [r0]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020714
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r4, _08020700 @ =0x00000744
	adds r2, r2, r4
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _0802072A
	.align 2, 0
_08020700: .4byte 0x00000744
_08020704: .4byte 0x040000D4
_08020708: .4byte gUnknown_084C07EC
_0802070C: .4byte 0x06010480
_08020710: .4byte 0x800000C0
_08020714:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r2, r0
	ldr r7, _080207B4 @ =0x00000743
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
_0802072A:
	mov r0, sl
	ldr r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0802073A:
	mov r3, sl
	ldr r5, [r3]
	ldr r4, _080207B8 @ =0x0000061C
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0802074E
	b _08020D82
_0802074E:
	ldr r7, _080207BC @ =0x0000061E
	mov sb, r7
	mov r0, sb
	adds r6, r5, r0
	ldrh r7, [r6]
	mov r8, r7
	mov r1, r8
	cmp r1, #1
	bhi _08020762
	b _08020928
_08020762:
	movs r2, #0xef
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	subs r0, r7, #1
	strh r0, [r6]
	ldrh r0, [r4]
	cmp r0, #0
	beq _08020796
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bne _08020796
	ldrh r0, [r6]
	cmp r0, #0x28
	bls _08020796
	movs r0, #0x3c
	strh r0, [r4]
_08020796:
	ldr r3, _080207C0 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _080207BC @ =0x0000061E
	adds r2, r1, r4
	ldrh r0, [r2]
	cmp r0, #0x74
	bne _08020832
	adds r1, #0xe4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080207C4
	movs r0, #0x78
	strh r0, [r2]
	b _08020832
	.align 2, 0
_080207B4: .4byte 0x00000743
_080207B8: .4byte 0x0000061C
_080207BC: .4byte 0x0000061E
_080207C0: .4byte gCurrentPinballGame
_080207C4:
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r3]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020820
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080207FC
	ldr r0, _080207F4 @ =gMPlayInfo_SE1
	ldr r1, _080207F8 @ =gUnknown_086A0328
	bl MPlayStart
	b _08020804
	.align 2, 0
_080207F4: .4byte gMPlayInfo_SE1
_080207F8: .4byte gUnknown_086A0328
_080207FC:
	ldr r0, _08020810 @ =gMPlayInfo_SE1
	ldr r1, _08020814 @ =gUnknown_086A0368
	bl MPlayStart
_08020804:
	ldr r0, _08020818 @ =gMPlayInfo_BGM
	ldr r1, _0802081C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
	b _08020832
	.align 2, 0
_08020810: .4byte gMPlayInfo_SE1
_08020814: .4byte gUnknown_086A0368
_08020818: .4byte gMPlayInfo_BGM
_0802081C: .4byte 0x0000FFFF
_08020820:
	ldr r0, _08020900 @ =gMPlayInfo_SE1
	ldr r1, _08020904 @ =gUnknown_086A0328
	bl MPlayStart
	ldr r0, _08020908 @ =gMPlayInfo_BGM
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
_08020832:
	ldr r0, _08020910 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _08020914 @ =0x0000061E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x73
	bne _08020856
	adds r0, r1, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #1
	bne _08020856
	ldr r0, _08020900 @ =gMPlayInfo_SE1
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #2
	bl m4aMPlayVolumeControl
_08020856:
	adds r0, r5, #0
	bl Sin
	adds r1, r0, #0
	ldr r0, _08020910 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r5, _08020918 @ =0x0000132C
	adds r5, r5, r4
	mov r8, r5
	ldr r7, [r5]
	mov sb, r7
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r6, r4, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0802091C @ =0x00004E20
	bl __divsi3
	ldrh r5, [r6]
	adds r5, r5, r0
	ldr r1, _08020920 @ =gUnknown_086ADF8A
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	subs r2, r2, r0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r6, r4, r0
	ldrh r1, [r6]
	movs r3, #0xef
	lsls r3, r3, #1
	adds r7, r4, r3
	ldrh r0, [r7]
	subs r0, r1, r0
	muls r0, r2, r0
	bl __divsi3
	adds r5, r5, r0
	mov r0, sb
	strh r5, [r0, #0x28]
	ldrh r1, [r6]
	ldrh r2, [r7]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	bl __divsi3
	mov r1, r8
	ldr r2, [r1]
	ldr r3, _08020924 @ =0x00000622
	adds r4, r4, r3
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r2, #0x2a]
	mov r4, r8
	ldr r1, [r4]
	movs r5, #0x28
	ldrsh r0, [r1, r5]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r7, #0x2a
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	b _080209FE
	.align 2, 0
_08020900: .4byte gMPlayInfo_SE1
_08020904: .4byte gUnknown_086A0328
_08020908: .4byte gMPlayInfo_BGM
_0802090C: .4byte 0x0000FFFF
_08020910: .4byte gCurrentPinballGame
_08020914: .4byte 0x0000061E
_08020918: .4byte 0x0000132C
_0802091C: .4byte 0x00004E20
_08020920: .4byte gUnknown_086ADF8A
_08020924: .4byte 0x00000622
_08020928:
	mov r0, r8
	cmp r0, #1
	bne _080209FE
	ldr r1, _08020A3C @ =0x0000132C
	adds r2, r5, r1
	ldr r3, [r2]
	ldr r1, _08020A40 @ =gUnknown_086ADF8A
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #1
	movs r6, #0
	movs r5, #0
	strh r0, [r3, #0x28]
	ldr r1, [r2]
	ldr r0, _08020A44 @ =0x000002BE
	strh r0, [r1, #0x2a]
	ldr r1, [r2]
	movs r7, #0x28
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r3, #0x2a
	ldrsh r0, [r1, r3]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r5, [r0, #0x30]
	ldr r1, [r2]
	ldr r0, _08020A48 @ =0x0000FED4
	strh r0, [r1, #0x32]
	movs r0, 0x7C @=SE_UNKNOWN_0x7C
	bl m4aSongNumStart
	mov r7, sl
	ldr r1, [r7]
	mov r2, sb
	adds r0, r1, r2
	strh r5, [r0]
	strb r6, [r1, #0x1f]
	ldr r0, [r7]
	ldr r3, _08020A4C @ =0x000005F7
	adds r0, r0, r3
	strb r6, [r0]
	ldr r2, [r7]
	adds r4, r2, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r4, #0xe2
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r2, r1
	mov r5, r8
	strb r5, [r2]
	ldr r3, [r7]
	ldr r7, _08020A50 @ =0x00000714
	adds r4, r3, r7
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080209F8
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08020A54 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r5, _08020A58 @ =0x00000712
	adds r1, r3, r5
	ldrb r1, [r1]
	ands r0, r1
	subs r7, #1
	adds r1, r3, r7
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080209F8
	mov r0, r8
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020A5C @ =0x00000715
	adds r0, r0, r2
	movs r1, #0x7e
	strb r1, [r0]
	mov r3, sl
	ldr r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
_080209F8:
	movs r0, #0xb
	bl sub_11B0
_080209FE:
	ldr r0, _08020A60 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r4, _08020A64 @ =0x0000061E
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sl, r0
	cmp r1, #0x63
	bls _08020AFC
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020A6C
	movs r7, #0xe1
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r1, _08020A68 @ =0x00000744
	adds r2, r3, r1
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _08020A82
	.align 2, 0
_08020A3C: .4byte 0x0000132C
_08020A40: .4byte gUnknown_086ADF8A
_08020A44: .4byte 0x000002BE
_08020A48: .4byte 0x0000FED4
_08020A4C: .4byte 0x000005F7
_08020A50: .4byte 0x00000714
_08020A54: .4byte 0x00000711
_08020A58: .4byte 0x00000712
_08020A5C: .4byte 0x00000715
_08020A60: .4byte gCurrentPinballGame
_08020A64: .4byte 0x0000061E
_08020A68: .4byte 0x00000744
_08020A6C:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r3, r0
	ldr r3, _08020AC4 @ =0x00000743
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
_08020A82:
	mov r4, sl
	ldr r2, [r4]
	ldr r5, _08020AC8 @ =0x0000061E
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0x64
	beq _08020A92
	b _08020D82
_08020A92:
	ldr r0, _08020ACC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x98
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	ldr r1, _08020AD0 @ =0x040000D4
	ldr r0, _08020AD4 @ =gUnknown_08395A4C
	b _08020ADC
	.align 2, 0
_08020AC4: .4byte 0x00000743
_08020AC8: .4byte 0x0000061E
_08020ACC: .4byte gMain
_08020AD0: .4byte 0x040000D4
_08020AD4: .4byte gUnknown_08395A4C
_08020AD8:
	ldr r1, _08020AEC @ =0x040000D4
	ldr r0, _08020AF0 @ =gUnknown_08397E6C
_08020ADC:
	str r0, [r1]
	ldr r0, _08020AF4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08020AF8 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08020D82
	.align 2, 0
_08020AEC: .4byte 0x040000D4
_08020AF0: .4byte gUnknown_08397E6C
_08020AF4: .4byte 0x06015800
_08020AF8: .4byte 0x80001200
_08020AFC:
	ldr r2, _08020B24 @ =gUnknown_086ADEE0
	ldr r6, _08020B28 @ =0x0000020A
	adds r4, r3, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, r2, #2
	adds r0, r0, r1
	movs r5, #0x82
	lsls r5, r5, #2
	adds r1, r3, r5
	ldrh r3, [r1]
	ldrh r0, [r0]
	mov r8, r2
	cmp r0, r3
	bls _08020B2C
	adds r0, r3, #1
	strh r0, [r1]
	b _08020C1C
	.align 2, 0
_08020B24: .4byte gUnknown_086ADEE0
_08020B28: .4byte 0x0000020A
_08020B2C:
	movs r5, #0
	movs r7, #0
	strh r7, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020BC0 @ =0x0000020A
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _08020B5C
	movs r0, #0x7c
	bl m4aSongNumStop
	ldr r0, _08020BC4 @ =gMPlayInfo_BGM
	ldr r1, _08020BC8 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_08020B5C:
	mov r3, sl
	ldr r0, [r3]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x19
	ble _08020C1C
	movs r0, #0x19
	strb r0, [r1]
	mov r4, sl
	ldr r0, [r4]
	ldr r1, _08020BCC @ =0x0000061C
	adds r0, r0, r1
	strb r5, [r0]
	ldr r2, _08020BD0 @ =gMain
	ldr r0, [r2, #0x44]
	adds r0, #0x98
	ldr r0, [r0]
	strh r7, [r0]
	ldr r0, [r4]
	adds r0, #0xe4
	strb r5, [r0]
	ldr r4, [r4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020BD8
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r0, _08020BD4 @ =0x00000744
	adds r2, r4, r0
	adds r2, r2, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	strb r0, [r2]
	mov r8, r3
	b _08020BE6
	.align 2, 0
_08020BC0: .4byte 0x0000020A
_08020BC4: .4byte gMPlayInfo_BGM
_08020BC8: .4byte 0x0000FFFF
_08020BCC: .4byte 0x0000061C
_08020BD0: .4byte gMain
_08020BD4: .4byte 0x00000744
_08020BD8:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r3, _08020C48 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r1
	strb r5, [r0]
	mov r8, r2
_08020BE6:
	ldr r3, _08020C4C @ =0x040000D4
	ldr r4, _08020C50 @ =gCurrentPinballGame
	ldr r0, [r4]
	mov r5, r8
	asrs r2, r5, #0x10
	ldr r7, _08020C48 @ =0x00000744
	adds r0, r0, r7
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020C54 @ =gUnknown_084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r1, _08020C58 @ =0x06010480
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _08020C5C @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r4
	ldr r2, _08020C60 @ =gUnknown_086ADEE0
	mov r8, r2
_08020C1C:
	mov r3, sl
	ldr r1, [r3]
	ldr r4, _08020C64 @ =0x0000020A
	adds r0, r1, r4
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _08020C76
	ldr r5, _08020C68 @ =gMain
	ldr r0, [r5, #0x4c]
	movs r2, #3
	ands r0, r2
	lsrs r0, r0, #1
	cmp r0, #0
	beq _08020C70
	adds r1, #0x4c
	ldr r0, _08020C6C @ =0x0000FFFD
	strh r0, [r1]
	b _08020C76
	.align 2, 0
_08020C48: .4byte 0x00000744
_08020C4C: .4byte 0x040000D4
_08020C50: .4byte gCurrentPinballGame
_08020C54: .4byte gUnknown_084C07EC
_08020C58: .4byte 0x06010480
_08020C5C: .4byte 0x800000C0
_08020C60: .4byte gUnknown_086ADEE0
_08020C64: .4byte 0x0000020A
_08020C68: .4byte gMain
_08020C6C: .4byte 0x0000FFFD
_08020C70:
	adds r0, r1, #0
	adds r0, #0x4c
	strh r2, [r0]
_08020C76:
	mov r7, sl
	ldr r3, [r7]
	ldr r1, _08020CD8 @ =0x0000020A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, r8
	ldrh r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r4, _08020CDC @ =gMain
	ldr r0, [r4, #0x44]
	adds r0, #0x98
	ldr r6, [r0]
	subs r2, r1, #1
	movs r0, #0xb1
	adds r1, r2, #0
	muls r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r7, _08020CE0 @ =0x0000061C
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08020CE8
	adds r0, r3, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r7, _08020CE4 @ =0x000001E3
	adds r0, r3, r7
	adds r0, r0, r2
	movs r1, #0
	b _08020CF4
	.align 2, 0
_08020CD8: .4byte 0x0000020A
_08020CDC: .4byte gMain
_08020CE0: .4byte 0x0000061C
_08020CE4: .4byte 0x000001E3
_08020CE8:
	movs r0, #0xb4
	strh r0, [r6, #4]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r3, r1
	adds r0, r0, r2
	movs r1, #1
_08020CF4:
	strb r1, [r0]
	movs r4, #0
	lsls r1, r5, #0x10
	ldr r2, _08020E18 @ =gOamBuffer
	mov sb, r2
	ldr r3, _08020E1C @ =gUnknown_086B4922
	mov r8, r3
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r0
	ldr r5, _08020E20 @ =0xFFFFFE00
	mov sl, r5
_08020D10:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, ip
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08020E24 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _08020D10
_08020D82:
	ldr r0, _08020E28 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0x74]
	ldrh r1, [r6]
	cmp r1, #0
	bne _08020D90
	b _08020EA4
_08020D90:
	movs r2, #0
	ldr r3, _08020E2C @ =0x040000D4
	mov sl, r3
_08020D96:
	lsls r2, r2, #0x10
	asrs r5, r2, #0x10
	ldr r4, _08020E28 @ =gMain
	ldr r1, [r4, #0x44]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r6, [r0, #0x74]
	movs r0, #0xb1
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r7, _08020E30 @ =gCurrentPinballGame
	ldr r4, [r7]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r2
	cmp r0, #0
	beq _08020E44
	ldr r2, _08020E28 @ =gMain
	ldr r0, [r2, #0x50]
	movs r1, #5
	bl __umodsi3
	cmp r0, #0
	bne _08020E02
	ldr r3, _08020E34 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020E38 @ =gUnknown_084C07EC
	adds r0, r0, r1
	mov r4, sl
	str r0, [r4]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #7
	ldr r5, _08020E3C @ =0x06010480
	adds r0, r0, r5
	str r0, [r4, #4]
	ldr r0, _08020E40 @ =0x800000C0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_08020E02:
	ldr r7, _08020E30 @ =gCurrentPinballGame
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	b _08020E46
	.align 2, 0
_08020E14: .4byte 0x000001E3
_08020E18: .4byte gOamBuffer
_08020E1C: .4byte gUnknown_086B4922
_08020E20: .4byte 0xFFFFFE00
_08020E24: .4byte 0x000001FF
_08020E28: .4byte gMain
_08020E2C: .4byte 0x040000D4
_08020E30: .4byte gCurrentPinballGame
_08020E34: .4byte 0x00000744
_08020E38: .4byte gUnknown_084C07EC
_08020E3C: .4byte 0x06010480
_08020E40: .4byte 0x800000C0
_08020E44:
	movs r0, #0xc8
_08020E46:
	strh r0, [r6, #4]
	movs r4, #0
	ldr r7, _08020EB4 @ =gOamBuffer
	ldr r3, _08020EB8 @ =0xFFFFFE00
	mov sb, r3
_08020E50:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r4, _08020EBC @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08020E50
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08020EA4
	b _08020D96
_08020EA4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020EB4: .4byte gOamBuffer
_08020EB8: .4byte 0xFFFFFE00
_08020EBC: .4byte 0x000001FF

	thumb_func_start sub_20EC0
sub_20EC0: @ 0x08020EC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08020F24 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r7, [r0]
	ldr r0, _08020F28 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _08020EE6
	b _08021220
_08020EE6:
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r1, r0
	bne _08020F5C
	movs r0, #1
	strh r0, [r7]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020F34
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08020F2C @ =0x00000442
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08020F30 @ =0x00001248
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	b _08021210
	.align 2, 0
_08020F24: .4byte gMain
_08020F28: .4byte gCurrentPinballGame
_08020F2C: .4byte 0x00000442
_08020F30: .4byte 0x00001248
_08020F34:
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08020F58 @ =0x00000EEC
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	b _08021210
	.align 2, 0
_08020F58: .4byte 0x00000EEC
_08020F5C:
	ldr r0, _08021084 @ =0x0000031F
	cmp r1, r0
	bne _08020F82
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08020F82
	ldr r1, _08021088 @ =0x040000D4
	ldr r0, _0802108C @ =gUnknown_084C07EC
	str r0, [r1]
	ldr r0, _08021090 @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _08021094 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08020F82:
	ldr r4, _08021098 @ =gUnknown_086ADF90
	ldr r2, _0802109C @ =gCurrentPinballGame
	mov sl, r2
	ldr r3, [r2]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r0, r2, r4
	mov r8, r0
	subs r1, #8
	mov sb, r1
	adds r0, r3, r1
	ldr r0, [r0]
	adds r0, #0x78
	mov ip, r0
	mov r0, r8
	ldr r0, [r0]
	mov r1, ip
	subs r5, r0, r1
	adds r4, #4
	adds r2, r2, r4
	movs r0, #0x80
	lsls r0, r0, #2
	mov r8, r0
	add r3, r8
	ldr r0, [r3]
	adds r0, #0xa0
	ldr r1, [r2]
	subs r6, r1, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r1, r0
	str r1, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r6, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	adds r0, r5, #0
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r6, _080210A0 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl Sin
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #4]
	ldr r0, _080210A4 @ =gUnknown_086AD788
	lsrs r4, r4, #0x1d
	lsls r4, r4, #1
	adds r4, r4, r0
	ldr r0, _080210A8 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x18
	bl __umodsi3
	lsrs r0, r0, #3
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r1, sl
	ldr r5, [r1]
	mov r2, sb
	adds r1, r5, r2
	ldr r0, [r1]
	ldr r2, [sp]
	adds r0, r0, r2
	str r0, [r1]
	mov r0, r8
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, [sp, #4]
	adds r0, r0, r2
	str r0, [r4]
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802114A
	ldr r0, [r1]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r0, [r4]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _080210AC
	movs r0, #0xb4
	strh r0, [r7, #4]
	b _080210B6
	.align 2, 0
_08021084: .4byte 0x0000031F
_08021088: .4byte 0x040000D4
_0802108C: .4byte gUnknown_084C07EC
_08021090: .4byte 0x06010600
_08021094: .4byte 0x800000C0
_08021098: .4byte gUnknown_086ADF90
_0802109C: .4byte gCurrentPinballGame
_080210A0: .4byte 0x00004E20
_080210A4: .4byte gUnknown_086AD788
_080210A8: .4byte gMain
_080210AC:
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080210B6
	strh r1, [r7, #4]
_080210B6:
	ldr r2, _080211B8 @ =0x040000D4
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r1, #0x1e
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080211BC @ =gMonHatchSpriteGroup5_Gfx
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080211C0 @ =0x060112A0
	str r0, [r2, #4]
	ldr r0, _080211C4 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r6, _080211C8 @ =gOamBuffer
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
	ldr r2, _080211CC @ =0xFFFFFE00
	mov r8, r2
_080210E2:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, sb
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080211D0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _080210E2
_0802114A:
	ldr r0, _080211D4 @ =0x000009C3
	ldr r1, [sp, #8]
	cmp r1, r0
	bgt _08021210
	ldr r3, _080211D8 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r5, #0
	strb r0, [r1]
	ldr r2, [r3]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _080211EC
	adds r1, #0x46
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08021210
	ldr r1, _080211B8 @ =0x040000D4
	ldr r0, _080211DC @ =gUnknown_084C156C
	str r0, [r1]
	ldr r0, _080211E0 @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _080211E4 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080211E8 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r5, [r0]
	ldr r0, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, 0x75 @=SE_UNKNOWN_0x75
	bl m4aSongNumStart
	b _08021210
	.align 2, 0
_080211B8: .4byte 0x040000D4
_080211BC: .4byte gMonHatchSpriteGroup5_Gfx
_080211C0: .4byte 0x060112A0
_080211C4: .4byte 0x80000090
_080211C8: .4byte gOamBuffer
_080211CC: .4byte 0xFFFFFE00
_080211D0: .4byte 0x000001FF
_080211D4: .4byte 0x000009C3
_080211D8: .4byte gCurrentPinballGame
_080211DC: .4byte gUnknown_084C156C
_080211E0: .4byte 0x06010600
_080211E4: .4byte 0x800000C0
_080211E8: .4byte gMain
_080211EC:
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _08021210
	ldr r0, _08021230 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r5, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
_08021210:
	ldr r0, _08021234 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_08021220:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021230: .4byte gMain
_08021234: .4byte gCurrentPinballGame

	thumb_func_start sub_21238
sub_21238: @ 0x08021238
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802127A
	ldr r3, _080212E0 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r1, _080212E4 @ =0x00000714
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r3]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r4, _080212E8 @ =0x00000711
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r3]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _080212EC @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
_0802127A:
	ldr r5, _080212E0 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _080212F0 @ =0x000005F3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	movs r0, #0x16
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bne _080212A2
	movs r0, #0x14
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _080212C0
_080212A2:
	adds r0, r1, #0
	adds r0, #0x72
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0
	bne _080212C0
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _080212F4 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
_080212C0:
	ldr r0, _080212E0 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r0, [r2, #0x14]
	ldr r1, _080212F8 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _080212FC @ =0x00020006
	cmp r0, r1
	bne _080212DA
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0
	strb r0, [r1]
_080212DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080212E0: .4byte gCurrentPinballGame
_080212E4: .4byte 0x00000714
_080212E8: .4byte 0x00000711
_080212EC: .4byte 0x00000713
_080212F0: .4byte 0x000005F3
_080212F4: .4byte 0x000006C4
_080212F8: .4byte 0x00FF00FF
_080212FC: .4byte 0x00020006

	thumb_func_start sub_21300
sub_21300: @ 0x08021300
	ldr r2, _08021318 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r3, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	movs r1, #0
	strh r3, [r0, #0x18]
	ldr r2, _0802131C @ =0x000006DD
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_08021318: .4byte gCurrentPinballGame
_0802131C: .4byte 0x000006DD

	thumb_func_start sub_21320
sub_21320: @ 0x08021320
	push {r4, lr}
	ldr r1, _08021340 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r0, #6
	bls _08021336
	b _0802150C
_08021336:
	lsls r0, r0, #2
	ldr r1, _08021344 @ =_08021348
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021340: .4byte gCurrentPinballGame
_08021344: .4byte _08021348
_08021348: @ jump table
	.4byte _08021364 @ case 0
	.4byte _080213B2 @ case 1
	.4byte _080213E8 @ case 2
	.4byte _0802144C @ case 3
	.4byte _080214CC @ case 4
	.4byte _080214E0 @ case 5
	.4byte _080214F8 @ case 6
_08021364:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #8
	bls _0802136E
	b _0802150C
_0802136E:
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08021386
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _0802150C
_08021386:
	cmp r0, #8
	beq _0802138C
	b _0802150C
_0802138C:
	bl sub_219A8
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0
	str r1, [r0]
	movs r0, #1
	bl sub_1C7F4
	ldr r1, [r4]
	b _080214EA
_080213B2:
	bl sub_219EC
	ldr r4, _080213E4 @ =gCurrentPinballGame
	ldr r0, [r4]
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080213CE
	movs r0, #1
	movs r1, #0
	bl sub_1C7F4
_080213CE:
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _080213E0
	b _0802150C
_080213E0:
	b _080214EA
	.align 2, 0
_080213E4: .4byte gCurrentPinballGame
_080213E8:
	ldr r0, [r4]
	ldr r3, _08021440 @ =0x00000714
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _08021444 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	bl sub_29D9C
	ldr r0, [r4]
	ldr r3, _08021448 @ =0x0000062D
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802150C
	adds r0, #1
	strb r0, [r1]
	b _0802150C
	.align 2, 0
_08021440: .4byte 0x00000714
_08021444: .4byte 0x00000713
_08021448: .4byte 0x0000062D
_0802144C:
	ldr r0, _08021464 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldrh r0, [r2, #0x28]
	adds r1, r0, #0
	cmp r1, #0x94
	bne _08021468
	adds r0, #1
	strh r0, [r2, #0x28]
	bl sub_2A054
	b _08021484
	.align 2, 0
_08021464: .4byte gCurrentPinballGame
_08021468:
	cmp r1, #0x8b
	beq _08021484
	cmp r1, #0x18
	bne _0802147A
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	b _08021484
_0802147A:
	cmp r1, #0
	bne _08021484
	ldrb r0, [r2, #0x17]
	adds r0, #1
	strb r0, [r2, #0x17]
_08021484:
	ldr r4, _080214C0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r1, _080214C4 @ =0x000006DD
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080214B4
	bl sub_2A354
	ldr r1, [r4]
	ldr r3, _080214C8 @ =0x000006DE
	adds r2, r1, r3
	ldrh r0, [r2]
	cmp r0, #0xb3
	bhi _080214B4
	movs r0, #0x8c
	strh r0, [r1, #0x28]
	ldrh r0, [r2]
	cmp r0, #0xb3
	bne _080214B4
	movs r0, #0x1e
	strh r0, [r1, #0x28]
_080214B4:
	ldr r0, _080214C0 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x18]
	b _0802150C
	.align 2, 0
_080214C0: .4byte gCurrentPinballGame
_080214C4: .4byte 0x000006DD
_080214C8: .4byte 0x000006DE
_080214CC:
	bl sub_219EC
	ldr r0, _080214DC @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r0, #0
	strh r0, [r1]
	b _080214E6
	.align 2, 0
_080214DC: .4byte gMain
_080214E0:
	movs r0, #1
	bl sub_21238
_080214E6:
	ldr r0, _080214F4 @ =gCurrentPinballGame
	ldr r1, [r0]
_080214EA:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _0802150C
	.align 2, 0
_080214F4: .4byte gCurrentPinballGame
_080214F8:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08021506
	subs r0, #1
	strh r0, [r1, #0x18]
	b _0802150C
_08021506:
	movs r0, #1
	bl sub_19B64
_0802150C:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_21514
sub_21514: @ 0x08021514
	push {r4, r5, lr}
	ldr r5, _0802156C @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08021570 @ =0x000005F3
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _08021574 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #0x5f
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802156C: .4byte gCurrentPinballGame
_08021570: .4byte 0x000005F3
_08021574: .4byte 0x000006C4

	thumb_func_start sub_21578
sub_21578: @ 0x08021578
	push {r4, lr}
	ldr r0, _080215A8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0802161C
	ldr r4, _080215AC @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r1, _080215B0 @ =0x00000283
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0802159C
	b _080216AE
_0802159C:
	lsls r0, r0, #2
	ldr r1, _080215B4 @ =_080215B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080215A8: .4byte gMain
_080215AC: .4byte gCurrentPinballGame
_080215B0: .4byte 0x00000283
_080215B4: .4byte _080215B8
_080215B8: @ jump table
	.4byte _080215CC @ case 0
	.4byte _080215E8 @ case 1
	.4byte _080215CC @ case 2
	.4byte _080215E8 @ case 3
	.4byte _08021604 @ case 4
_080215CC:
	ldr r0, [r4]
	ldr r2, _080215E4 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2a
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #3
	b _080216AC
	.align 2, 0
_080215E4: .4byte 0x000006EC
_080215E8:
	ldr r0, [r4]
	ldr r2, _08021600 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2c
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	b _080216AC
	.align 2, 0
_08021600: .4byte 0x000006EC
_08021604:
	ldr r0, [r4]
	ldr r2, _08021618 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2d
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	b _080216AA
	.align 2, 0
_08021618: .4byte 0x000006EC
_0802161C:
	ldr r4, _08021640 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _08021644 @ =0x00000283
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080216AE
	lsls r0, r0, #2
	ldr r1, _08021648 @ =_0802164C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021640: .4byte gCurrentPinballGame
_08021644: .4byte 0x00000283
_08021648: .4byte _0802164C
_0802164C: @ jump table
	.4byte _08021660 @ case 0
	.4byte _0802167C @ case 1
	.4byte _08021660 @ case 2
	.4byte _0802167C @ case 3
	.4byte _08021698 @ case 4
_08021660:
	ldr r0, [r4]
	ldr r1, _08021678 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x29
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #2
	b _080216AC
	.align 2, 0
_08021678: .4byte 0x000006EC
_0802167C:
	ldr r0, [r4]
	ldr r1, _08021694 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2b
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #4
	b _080216AC
	.align 2, 0
_08021694: .4byte 0x000006EC
_08021698:
	ldr r0, [r4]
	ldr r1, _080216D8 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2d
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
_080216AA:
	movs r1, #6
_080216AC:
	strb r1, [r0]
_080216AE:
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080216DC
	movs r0, #0x15
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _080216DC
	movs r1, #0
	movs r0, #0x96
	strh r0, [r2, #0x28]
	movs r0, #3
	strb r0, [r2, #0x17]
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	b _080216F4
	.align 2, 0
_080216D8: .4byte 0x000006EC
_080216DC:
	ldr r0, [r4]
	movs r1, #0
	strb r1, [r0, #0x17]
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r0, r2
	str r1, [r0]
	movs r0, #7
	bl sub_1C7F4
_080216F4:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_216FC
sub_216FC: @ 0x080216FC
	push {r4, lr}
	ldr r1, _0802171C @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #8
	bls _08021710
	b _080219A2
_08021710:
	lsls r0, r0, #2
	ldr r1, _08021720 @ =_08021724
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802171C: .4byte gCurrentPinballGame
_08021720: .4byte _08021724
_08021724: @ jump table
	.4byte _08021748 @ case 0
	.4byte _0802175C @ case 1
	.4byte _080217FC @ case 2
	.4byte _08021824 @ case 3
	.4byte _08021850 @ case 4
	.4byte _08021938 @ case 5
	.4byte _08021960 @ case 6
	.4byte _08021988 @ case 7
	.4byte _0802199C @ case 8
_08021748:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x3b
	bhi _08021756
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080219A2
_08021756:
	movs r0, #0
	strh r0, [r1, #0x18]
	b _08021990
_0802175C:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #8
	bls _08021766
	b _080219A2
_08021766:
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0802177E
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _080219A2
_0802177E:
	cmp r0, #8
	beq _08021784
	b _080219A2
_08021784:
	ldr r2, _080217A4 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080217CE
	lsls r0, r0, #2
	ldr r1, _080217A8 @ =_080217AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080217A4: .4byte 0x00000283
_080217A8: .4byte _080217AC
_080217AC: @ jump table
	.4byte _080217C0 @ case 0
	.4byte _080217C8 @ case 1
	.4byte _080217C0 @ case 2
	.4byte _080217C8 @ case 3
	.4byte _080217C8 @ case 4
_080217C0:
	movs r0, 0x0E @ =MUS_BONUS_CHANCE
	bl m4aSongNumStart
	b _080217CE
_080217C8:
	movs r0, 0x0F @ =MUS_BONUS_CHANCE_LEGENDARY
	bl m4aSongNumStart
_080217CE:
	bl sub_219A8
	ldr r2, _080217F8 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r3, #0
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	str r3, [r0]
	b _080219A2
	.align 2, 0
_080217F8: .4byte gCurrentPinballGame
_080217FC:
	bl sub_219EC
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08021820 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802181C
	b _080219A2
_0802181C:
	b _08021990
	.align 2, 0
_08021820: .4byte gCurrentPinballGame
_08021824:
	ldr r1, [r3]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	movs r2, #0
	strb r0, [r1, #0x17]
	ldr r0, [r3]
	strh r2, [r0, #0x18]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r1, r0, r3
	str r2, [r1]
	ldr r1, _0802184C @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2e
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	b _080219A2
	.align 2, 0
_0802184C: .4byte 0x000006EC
_08021850:
	ldr r4, _08021874 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x91
	bne _080218C4
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r0, _08021878 @ =gMain
	ldrh r2, [r0, #0x18]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0802187C
	movs r0, #0x90
	strh r0, [r1, #0x28]
	bl m4aMPlayAllStop
	b _080218B0
	.align 2, 0
_08021874: .4byte gCurrentPinballGame
_08021878: .4byte gMain
_0802187C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080218B0
	bl m4aMPlayAllStop
	movs r0, 0x66 @=SE_UNKNOWN_0x66
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x3c
	strh r0, [r1, #0x28]
	movs r0, #6
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r2, _08021924 @ =0x00000714
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080218B0
	ldr r3, _08021928 @ =0x000006EE
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
_080218B0:
	ldr r0, _0802192C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _08021930 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2e
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
_080218C4:
	ldr r4, _0802192C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldrh r0, [r0, #0x28]
	cmp r0, #0x82
	bne _080218E2
	movs r0, 0x9F @=SE_UNKNOWN_0x9F
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x41
	strh r0, [r1, #0x18]
	ldr r1, _08021934 @ =gMain
	ldrh r0, [r1, #0x38]
	movs r0, #0x9f
	strh r0, [r1, #0x38]
_080218E2:
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x7d
	bne _080218EE
	adds r0, #1
	strh r0, [r1, #0x28]
_080218EE:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080219A2
	movs r2, #0x88
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, [r4]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldr r2, _08021934 @ =gMain
	ldrh r0, [r3, #0x18]
	lsrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r2, #0x3c]
	strh r1, [r2, #0x3c]
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	bne _080219A2
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	b _080219A2
	.align 2, 0
_08021924: .4byte 0x00000714
_08021928: .4byte 0x000006EE
_0802192C: .4byte gCurrentPinballGame
_08021930: .4byte 0x000006EC
_08021934: .4byte gMain
_08021938:
	ldr r2, [r3]
	ldrh r0, [r2, #0x18]
	cmp r0, #0x1d
	bhi _08021946
	adds r0, #1
	strh r0, [r2, #0x18]
	b _080219A2
_08021946:
	movs r1, #0
	movs r0, #0
	strh r0, [r2, #0x18]
	strb r1, [r2, #0x17]
	ldr r0, [r3]
	ldr r3, _0802195C @ =0x00000282
	adds r0, r0, r3
	strb r1, [r0]
	bl sub_1C73C
	b _080219A2
	.align 2, 0
_0802195C: .4byte 0x00000282
_08021960:
	bl sub_219EC
	ldr r0, _08021980 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x34]
	movs r3, #0
	strh r3, [r0]
	ldr r2, _08021984 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	strh r3, [r0, #0x18]
	b _080219A2
	.align 2, 0
_08021980: .4byte gMain
_08021984: .4byte gCurrentPinballGame
_08021988:
	bl sub_21514
	ldr r0, _08021998 @ =gCurrentPinballGame
	ldr r1, [r0]
_08021990:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _080219A2
	.align 2, 0
_08021998: .4byte gCurrentPinballGame
_0802199C:
	movs r0, #1
	bl sub_19B64
_080219A2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_219A8
sub_219A8: @ 0x080219A8
	ldr r1, _080219D0 @ =0x040000D4
	ldr r0, _080219D4 @ =gUnknown_0844838C
	str r0, [r1]
	ldr r0, _080219D8 @ =0x060113C0
	str r0, [r1, #4]
	ldr r0, _080219DC @ =0x80000180
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080219E0 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080219E4 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _080219E8 @ =0x000005F3
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080219D0: .4byte 0x040000D4
_080219D4: .4byte gUnknown_0844838C
_080219D8: .4byte 0x060113C0
_080219DC: .4byte 0x80000180
_080219E0: .4byte gMain
_080219E4: .4byte gCurrentPinballGame
_080219E8: .4byte 0x000005F3

	thumb_func_start sub_219EC
sub_219EC: @ 0x080219EC
	push {r4, r5, r6, r7, lr}
	ldr r0, _08021A58 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r6, [r0, #0x34]
	ldr r5, _08021A5C @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x23
	bl __umodsi3
	movs r1, #7
	bl __udivsi3
	ldr r3, _08021A60 @ =0x0000020B
	adds r4, r4, r3
	strb r0, [r4]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08021AE8
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x78
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08021A40
	movs r0, #0xc8
	strh r0, [r6, #4]
_08021A40:
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08021A64
	movs r0, #0xc8
	strh r0, [r6, #4]
	b _08021A9C
	.align 2, 0
_08021A58: .4byte gMain
_08021A5C: .4byte gCurrentPinballGame
_08021A60: .4byte 0x0000020B
_08021A64:
	adds r3, r4, r3
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08021A9C
	ldr r2, _08021AF0 @ =0x040000D4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _08021AF4 @ =gUnknown_0844838C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021AF8 @ =0x060113C0
	str r0, [r2, #4]
	ldr r0, _08021AFC @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r1, [r3]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08021A9C:
	movs r0, #0
	ldr r7, _08021B00 @ =gOamBuffer
	ldr r1, _08021B04 @ =0xFFFFFE00
	mov ip, r1
_08021AA4:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08021B08 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _08021AA4
_08021AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021AF0: .4byte 0x040000D4
_08021AF4: .4byte gUnknown_0844838C
_08021AF8: .4byte 0x060113C0
_08021AFC: .4byte 0x80000180
_08021B00: .4byte gOamBuffer
_08021B04: .4byte 0xFFFFFE00
_08021B08: .4byte 0x000001FF

	thumb_func_start sub_21B0C
sub_21B0C: @ 0x08021B0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08021BE8 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r7, [r0, #0x44]
	mov r0, sp
	movs r1, #0
	movs r2, #6
	bl memset
	ldr r5, _08021BEC @ =gCurrentPinballGame
	ldr r6, [r5]
	movs r0, #0xe5
	lsls r0, r0, #1
	adds r3, r6, r0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08021B44
	b _08021C5C
_08021B44:
	cmp r1, #0xc
	bne _08021C40
	movs r0, #0xe7
	lsls r0, r0, #1
	mov sb, r0
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	beq _08021BF0
	subs r0, #1
	strh r0, [r1]
	ldrh r4, [r1]
	adds r0, r4, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __udivsi3
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r4, #0x28
	bhi _08021C14
	cmp r4, #2
	bls _08021B98
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r1, #3
	strh r1, [r0]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_08021B98:
	ldr r5, [r5]
	mov r0, sb
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #7
	movs r4, #0x28
	movs r1, #0x28
	bl __divsi3
	adds r0, #0x80
	movs r2, #0xed
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r5, r5, r1
	strh r0, [r5]
	mov r5, sp
	ldrh r0, [r6]
	subs r0, r4, r0
	lsls r0, r0, #4
	movs r1, #0x28
	bl __divsi3
	strh r0, [r5, #2]
	mov r5, sp
	ldrh r0, [r6]
	subs r4, r4, r0
	lsls r4, r4, #4
	rsbs r4, r4, #0
	adds r0, r4, #0
	movs r1, #0x28
	bl __divsi3
	strh r0, [r5]
	mov r1, sp
	movs r0, #0
	strh r0, [r1, #4]
	b _08021C14
	.align 2, 0
_08021BE8: .4byte gMain
_08021BEC: .4byte gCurrentPinballGame
_08021BF0:
	movs r0, #0xd
	strh r0, [r4]
	strh r0, [r3]
	mov r8, r0
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_08021C14:
	ldr r2, _08021C30 @ =0x040000D4
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #9
	ldr r1, _08021C34 @ =gUnknown_084C00EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021C38 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _08021C3C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08021C5C
	.align 2, 0
_08021C30: .4byte 0x040000D4
_08021C34: .4byte gUnknown_084C00EC
_08021C38: .4byte 0x06010AE0
_08021C3C: .4byte 0x80000040
_08021C40:
	ldr r2, _08021C98 @ =0x040000D4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #7
	ldr r1, _08021C9C @ =gUnknown_084C00EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021CA0 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _08021CA4 @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrh r0, [r3]
	strh r0, [r4]
_08021C5C:
	ldr r0, _08021CA8 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r2, [r1]
	adds r4, r0, #0
	cmp r2, #0
	beq _08021CAC
	subs r0, r2, #1
	strh r0, [r1]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r7, #4]
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _08021CB0
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x10
	adds r2, #4
	adds r1, r3, r2
	strh r0, [r1]
	b _08021CB0
	.align 2, 0
_08021C98: .4byte 0x040000D4
_08021C9C: .4byte gUnknown_084C00EC
_08021CA0: .4byte 0x06010AE0
_08021CA4: .4byte 0x80000040
_08021CA8: .4byte gCurrentPinballGame
_08021CAC:
	movs r0, #0xb4
	strh r0, [r7, #4]
_08021CB0:
	ldr r1, [r4]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, #0x77
	strh r0, [r7, #2]
	adds r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #1
	bl SetMatrixScale
	movs r0, #0
	ldr r6, _08021D6C @ =gOamBuffer
	ldr r1, _08021D70 @ =0xFFFFFE00
	mov ip, r1
	movs r2, #4
	rsbs r2, r2, #0
	mov sb, r2
	movs r1, #0xf
	rsbs r1, r1, #0
	mov r8, r1
_08021CEA:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	lsls r0, r5, #1
	add r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _08021D74 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	mov r0, sb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #3]
	mov r0, r8
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #3]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _08021CEA
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021D6C: .4byte gOamBuffer
_08021D70: .4byte 0xFFFFFE00
_08021D74: .4byte 0x000001FF

	thumb_func_start sub_21D78
sub_21D78: @ 0x08021D78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _08021DD8 @ =gMain+0x3B08 @gMain.spriteGroups[78]
	ldr r4, _08021DDC @ =gCurrentPinballGame
	ldr r6, [r4]
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r3, #0
	ldrsb r3, [r2, r3]
	cmp r3, #0
	bne _08021E2C
	ldr r1, _08021DE0 @ =0x0000072E
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08021DEC
	ldr r1, _08021DE4 @ =0x00000281
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _08021DB0
	b _08021F86
_08021DB0:
	subs r1, #0xdc
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08021DC0
	b _08021F86
_08021DC0:
	movs r1, #1
	strb r1, [r2]
	ldr r2, [r4]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r3, [r0]
	ldr r3, _08021DE8 @ =0x000001A5
	adds r0, r2, r3
	strb r1, [r0]
	b _08021F86
	.align 2, 0
_08021DD8: .4byte gMain+0x3B08 @gMain.spriteGroups[78]
_08021DDC: .4byte gCurrentPinballGame
_08021DE0: .4byte 0x0000072E
_08021DE4: .4byte 0x00000281
_08021DE8: .4byte 0x000001A5
_08021DEC:
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	cmp r0, #6
	bne _08021DF6
	b _08021F86
_08021DF6:
	ldr r5, _08021E28 @ =0x000001A5
	adds r0, r6, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #1
	beq _08021E04
	b _08021F86
_08021E04:
	adds r0, r6, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08021E14
	b _08021F86
_08021E14:
	strb r1, [r2]
	ldr r0, [r4]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r2, #0
	strh r3, [r1]
	adds r0, r0, r5
	strb r2, [r0]
	b _08021F86
	.align 2, 0
_08021E28: .4byte 0x000001A5
_08021E2C:
	ldr r5, _08021E7C @ =gUnknown_086AD456
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	ldr r2, _08021E80 @ =0x000001A5
	adds r1, r6, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r5, [r0]
	cmp r4, #0
	bne _08021E94
	movs r0, #1
	strh r0, [r7]
	ldr r1, _08021E84 @ =0x040000D4
	ldr r0, _08021E88 @ =gUnknown_083A8A8C
	str r0, [r1]
	ldr r0, _08021E8C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _08021E90 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08021E9E
	.align 2, 0
_08021E7C: .4byte gUnknown_086AD456
_08021E80: .4byte 0x000001A5
_08021E84: .4byte 0x040000D4
_08021E88: .4byte gUnknown_083A8A8C
_08021E8C: .4byte 0x05000240
_08021E90: .4byte 0x80000010
_08021E94:
	cmp r4, #0x25
	bne _08021E9E
	movs r0, 0xCA @=SE_UNKNOWN_0xCA
	bl m4aSongNumStart
_08021E9E:
	ldr r4, _08021F90 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r3, #0xda
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	mov r8, r4
	cmp r0, #0
	bne _08021ED4
	ldr r2, _08021F94 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _08021F98 @ =gUnknown_084F6B0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021F9C @ =0x06013D00
	str r0, [r2, #4]
	ldr r0, _08021FA0 @ =0x80000280
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08021ED4:
	mov r4, r8
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xb5
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0x30
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08021EFC
	strh r1, [r7, #4]
_08021EFC:
	movs r0, #0
	ldr r6, _08021FA4 @ =gOamBuffer
	ldr r1, _08021FA8 @ =0xFFFFFE00
	mov ip, r1
_08021F04:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r6
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08021FAC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _08021F04
	mov r3, r8
	ldr r2, [r3]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _08021F86
	ldr r1, _08021FB0 @ =0x000001A5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_4E9F0
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08021FB4 @ =gMain
	ldr r4, _08021FB8 @ =0x00003B08
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
_08021F86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021F90: .4byte gCurrentPinballGame
_08021F94: .4byte 0x040000D4
_08021F98: .4byte gUnknown_084F6B0C
_08021F9C: .4byte 0x06013D00
_08021FA0: .4byte 0x80000280
_08021FA4: .4byte gOamBuffer
_08021FA8: .4byte 0xFFFFFE00
_08021FAC: .4byte 0x000001FF
_08021FB0: .4byte 0x000001A5
_08021FB4: .4byte gMain
_08021FB8: .4byte 0x00003B08

	thumb_func_start sub_21FBC
sub_21FBC: @ 0x08021FBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r5, _08022168 @ =gMain
	ldr r1, [r5, #0x44]
	ldr r7, [r1, #0x1c]
	ldr r3, _0802216C @ =gUnknown_086AD2DE
	ldr r4, _08022170 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r1, [r1]
	lsls r1, r1, #3
	ldr r2, _08022174 @ =gUnknown_086AD000
	adds r1, r1, r2
	mov r8, r1
	lsls r0, r0, #0x10
	mov sl, r4
	cmp r0, #0
	beq _0802202E
	ldrh r0, [r1, #6]
	movs r1, #0xa
	bl __udivsi3
	ldr r4, _08022178 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	ldr r6, _0802217C @ =gUnknown_08480E0C
	adds r0, r0, r6
	str r0, [r4]
	ldr r0, _08022180 @ =0x06015DA0
	str r0, [r4, #4]
	ldr r5, _08022184 @ =0x80000020
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r3, r8
	ldrh r0, [r3, #6]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	adds r0, r0, r6
	str r0, [r4]
	ldr r0, _08022188 @ =0x06015E60
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
_0802202E:
	ldrh r0, [r7]
	cmp r0, #0
	beq _08022094
	mov r4, sl
	ldr r0, [r4]
	movs r6, #0xdb
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, #0x9c
	strh r0, [r7, #2]
	movs r0, #0x60
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _0802218C @ =gOamBuffer
	ldr r0, _08022190 @ =0xFFFFFE00
	mov r8, r0
_08022050:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08022194 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08022050
_08022094:
	ldr r3, _08022168 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x20]
	mov r4, sl
	ldr r2, [r4]
	ldr r6, _08022198 @ =0x000001A5
	adds r0, r2, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802214C
	movs r3, #0xdb
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #0x88
	strh r0, [r7, #2]
	movs r0, #0x58
	strh r0, [r7, #4]
	movs r5, #0
	ldr r4, _0802218C @ =gOamBuffer
	mov r8, r4
	ldr r6, _0802219C @ =gUnknown_086B47DE
	mov ip, r6
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	str r0, [sp, #8]
	ldr r0, _08022190 @ =0xFFFFFE00
	mov sb, r0
_080220D8:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r4, [sp, #8]
	adds r0, r0, r4
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _08022194 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #4
	ble _080220D8
_0802214C:
	ldr r3, _08022168 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x18]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0802215A
	b _08022470
_0802215A:
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _080221A0
	movs r0, #0xb4
	b _080221A2
	.align 2, 0
_08022168: .4byte gMain
_0802216C: .4byte gUnknown_086AD2DE
_08022170: .4byte gCurrentPinballGame
_08022174: .4byte gUnknown_086AD000
_08022178: .4byte 0x040000D4
_0802217C: .4byte gUnknown_08480E0C
_08022180: .4byte 0x06015DA0
_08022184: .4byte 0x80000020
_08022188: .4byte 0x06015E60
_0802218C: .4byte gOamBuffer
_08022190: .4byte 0xFFFFFE00
_08022194: .4byte 0x000001FF
_08022198: .4byte 0x000001A5
_0802219C: .4byte gUnknown_086B47DE
_080221A0:
	movs r0, #0x56
_080221A2:
	strh r0, [r7, #4]
	mov r5, sp
	ldr r4, _08022254 @ =gUnknown_086ADFC8
	ldr r6, _08022258 @ =gMain
	ldr r0, [r6, #0x4c]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	rsbs r0, r1, #0
	strh r0, [r5]
	mov r0, sp
	strh r1, [r0, #2]
	add r1, sp, #4
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	mov r0, sl
	ldr r2, [r0]
	ldr r3, _0802225C @ =0x000001A5
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0802226C
	movs r5, #0
	movs r4, #0x28
	adds r4, r4, r7
	mov ip, r4
	movs r6, #0x30
	adds r6, r6, r7
	mov sb, r6
	ldr r6, _08022260 @ =gOamBuffer
	ldr r0, _08022264 @ =0xFFFFFE00
	mov r8, r0
_080221F8:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	lsls r1, r0, #1
	adds r0, r1, r0
	lsls r0, r0, #3
	add r1, sp
	ldrh r1, [r1]
	adds r1, #0x24
	adds r0, r0, r1
	strh r0, [r7, #2]
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08022268 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _080221F8
	b _0802233E
	.align 2, 0
_08022254: .4byte gUnknown_086ADFC8
_08022258: .4byte gMain
_0802225C: .4byte 0x000001A5
_08022260: .4byte gOamBuffer
_08022264: .4byte 0xFFFFFE00
_08022268: .4byte 0x000001FF
_0802226C:
	ldr r3, _080222EC @ =0x00000281
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _080222FC
	movs r5, #0
	movs r4, #0x28
	adds r4, r4, r7
	mov ip, r4
	movs r6, #0x30
	adds r6, r6, r7
	mov sb, r6
	ldr r6, _080222F0 @ =gOamBuffer
	ldr r0, _080222F4 @ =0xFFFFFE00
	mov r8, r0
_0802228E:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	lsls r1, r0, #1
	adds r0, r1, r0
	lsls r0, r0, #3
	add r1, sp
	ldrh r1, [r1]
	adds r1, #0x24
	adds r0, r0, r1
	strh r0, [r7, #2]
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080222F8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0802228E
	b _0802233E
	.align 2, 0
_080222EC: .4byte 0x00000281
_080222F0: .4byte gOamBuffer
_080222F4: .4byte 0xFFFFFE00
_080222F8: .4byte 0x000001FF
_080222FC:
	movs r5, #0
	movs r3, #0x28
	adds r3, r3, r7
	mov ip, r3
	movs r4, #0x30
	adds r4, r4, r7
	mov sb, r4
	ldr r4, _08022354 @ =gOamBuffer
	ldr r6, _08022358 @ =0xFFFFFE00
	mov r8, r6
	movs r6, #0xb4
_08022312:
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrh r3, [r1, #2]
	mov r0, r8
	ands r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	strb r6, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _08022312
_0802233E:
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _0802235C @ =0x000001A5
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08022360
	movs r0, #0xb4
	b _08022376
	.align 2, 0
_08022354: .4byte gOamBuffer
_08022358: .4byte 0xFFFFFE00
_0802235C: .4byte 0x000001A5
_08022360:
	ldr r3, _08022370 @ =gMain
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _08022374
	movs r0, #0xb4
	b _08022376
	.align 2, 0
_08022370: .4byte gMain
_08022374:
	movs r0, #0x56
_08022376:
	strh r0, [r7, #4]
	movs r0, #0x30
	strh r0, [r7, #2]
	mov r6, sl
	ldr r0, [r6]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080223D0 @ =0x0000025D
	adds r0, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _080223DC
	mov r5, ip
	ldrh r2, [r7, #0x28]
	lsls r2, r2, #3
	ldr r4, _080223D4 @ =gOamBuffer
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	adds r1, #0x30
	subs r3, #0x5e
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080223D8 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r2, [r7, #0x28]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r7, #4]
	ldrb r5, [r5, #4]
	adds r1, r1, r5
	mov r4, sp
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r2]
	b _080223F6
	.align 2, 0
_080223D0: .4byte 0x0000025D
_080223D4: .4byte gOamBuffer
_080223D8: .4byte 0xFFFFFE00
_080223DC:
	ldrh r1, [r7, #0x28]
	lsls r1, r1, #3
	ldr r6, _08022448 @ =gOamBuffer
	adds r1, r1, r6
	ldrh r2, [r1, #2]
	ldr r0, _0802244C @ =0xFFFFFE00
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
_080223F6:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08022454
	mov r5, sb
	ldrh r2, [r7, #0x30]
	lsls r2, r2, #3
	ldr r3, _08022448 @ =gOamBuffer
	adds r2, r2, r3
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r3, _08022450 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802244C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r2, [r7, #0x30]
	lsls r2, r2, #3
	ldr r4, _08022448 @ =gOamBuffer
	adds r2, r2, r4
	ldrb r1, [r7, #4]
	ldrb r5, [r5, #4]
	adds r1, r1, r5
	mov r6, sp
	ldrh r0, [r6, #6]
	adds r0, r0, r1
	strb r0, [r2]
	b _08022470
	.align 2, 0
_08022448: .4byte gOamBuffer
_0802244C: .4byte 0xFFFFFE00
_08022450: .4byte 0x000001FF
_08022454:
	ldrh r1, [r7, #0x30]
	lsls r1, r1, #3
	ldr r0, _08022490 @ =gOamBuffer
	adds r1, r1, r0
	ldrh r2, [r1, #2]
	ldr r0, _08022494 @ =0xFFFFFE00
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #3
	ldr r1, _08022490 @ =gOamBuffer
	adds r0, r0, r1
	movs r1, #0xb4
	strb r1, [r0]
_08022470:
	ldr r2, _08022498 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x24]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0802247E
	b _080225BE
_0802247E:
	movs r0, #0x30
	strh r0, [r7, #2]
	movs r3, #0x2a
	ldrsh r0, [r2, r3]
	cmp r0, #0x13
	bgt _0802249C
	movs r0, #0xb4
	b _0802249E
	.align 2, 0
_08022490: .4byte gOamBuffer
_08022494: .4byte 0xFFFFFE00
_08022498: .4byte gMain
_0802249C:
	movs r0, #0x58
_0802249E:
	strh r0, [r7, #4]
	mov r4, sl
	ldr r1, [r4]
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	ldr r2, _080224EC @ =gUnknown_086AD2DE
	adds r0, r0, r2
	ldrh r3, [r0]
	cmp r3, #4
	bne _080224F8
	ldr r3, _080224F0 @ =0x000001AF
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080224DC
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r1, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08022522
_080224DC:
	ldr r4, _080224F4 @ =gUnknown_086ADFD4
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08022544
	.align 2, 0
_080224EC: .4byte gUnknown_086AD2DE
_080224F0: .4byte 0x000001AF
_080224F4: .4byte gUnknown_086ADFD4
_080224F8:
	cmp r3, #3
	bne _0802253C
	movs r4, #0xd5
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08022526
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r1, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08022526
_08022522:
	movs r1, #4
	b _08022556
_08022526:
	ldr r4, _08022538 @ =gUnknown_086ADFD4
	mov r2, sl
	ldr r0, [r2]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	b _08022548
	.align 2, 0
_08022538: .4byte gUnknown_086ADFD4
_0802253C:
	ldr r4, _080225D0 @ =gUnknown_086ADFD4
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r1, r2
_08022544:
	movs r3, #0
	ldrsh r0, [r0, r3]
_08022548:
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r1, [r0]
_08022556:
	ldr r2, _080225D4 @ =0x040000D4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _080225D8 @ =gUnknown_0847FF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080225DC @ =0x06016220
	str r0, [r2, #4]
	ldr r0, _080225E0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r5, #0
	ldr r6, _080225E4 @ =gOamBuffer
	ldr r4, _080225E8 @ =0xFFFFFE00
	mov r8, r4
_0802257A:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080225EC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0802257A
_080225BE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080225D0: .4byte gUnknown_086ADFD4
_080225D4: .4byte 0x040000D4
_080225D8: .4byte gUnknown_0847FF0C
_080225DC: .4byte 0x06016220
_080225E0: .4byte 0x80000180
_080225E4: .4byte gOamBuffer
_080225E8: .4byte 0xFFFFFE00
_080225EC: .4byte 0x000001FF
