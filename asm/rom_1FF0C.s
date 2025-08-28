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
