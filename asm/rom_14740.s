#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_14740
sub_14740: @ 0x08014740
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r7, r1, #0
	movs r6, #0
	ldr r0, _080147E8 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r5, _080147EC @ =0x000005A4
	adds r1, r4, r5
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #2
	bne _0801475A
	b _08014924
_0801475A:
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	movs r3, #2
	ldrsh r0, [r2, r3]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r2, r4, #0
	adds r2, #0xc6
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r1, #0x10
	orrs r3, r0
	adds r1, r0, #0
	lsrs r0, r1, #0x10
	cmp r0, #0x2f
	bls _08014790
	b _08014924
_08014790:
	lsls r2, r3, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x2f
	bls _0801479A
	b _08014924
_0801479A:
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r2, #0x10
	adds r0, r0, r1
	ldr r1, _080147F0 @ =gUnknown_0839A28C
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	bne _080147B6
	b _08014924
_080147B6:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #0x23
	movs r1, #3
	strb r1, [r0]
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	strh r0, [r7]
	ldr r2, [r5]
	ldr r0, _080147F4 @ =0x000005A6
	adds r1, r2, r0
	movs r0, #0x14
	strh r0, [r1]
	ldr r1, _080147F8 @ =0x000005A9
	adds r2, r2, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080147FC
	movs r0, #0x18
	b _080147FE
	.align 2, 0
_080147E8: .4byte gCurrentPinballGame
_080147EC: .4byte 0x000005A4
_080147F0: .4byte gUnknown_0839A28C
_080147F4: .4byte 0x000005A6
_080147F8: .4byte 0x000005A9
_080147FC:
	movs r0, #0x14
_080147FE:
	strb r0, [r2]
	ldr r1, [r5]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0xc8
	bne _080148A4
	ldr r3, _0801484C @ =0x000005AA
	adds r0, r1, r3
	ldrh r3, [r0]
	cmp r3, #0
	bne _0801487E
	adds r2, #0xd
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #3
	bne _08014858
	adds r0, r2, #0
	adds r0, r1, r0
	ldr r1, _08014850 @ =0x0000071C
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _08014854 @ =0x000005A4
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	b _08014870
	.align 2, 0
_0801484C: .4byte 0x000005AA
_08014850: .4byte 0x0000071C
_08014854: .4byte 0x000005A4
_08014858:
	ldrb r0, [r0]
	adds r0, r1, r0
	ldr r3, _08014890 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, _08014894 @ =0x000005A4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r5]
_08014870:
	ldr r0, _08014898 @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, [r5]
	ldr r2, _0801489C @ =0x000005AA
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
_0801487E:
	movs r6, #1
	ldr r0, _080148A0 @ =0x00000145
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	b _08014924
	.align 2, 0
_08014890: .4byte 0x0000071C
_08014894: .4byte 0x000005A4
_08014898: .4byte 0x00002710
_0801489C: .4byte 0x000005AA
_080148A0: .4byte 0x00000145
_080148A4:
	ldr r3, _080148E0 @ =0x000005AA
	adds r0, r1, r3
	ldrh r3, [r0]
	cmp r3, #0
	bne _08014916
	ldr r2, _080148E4 @ =0x000005A5
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #3
	bne _080148F0
	adds r0, r2, #0
	adds r0, r1, r0
	ldr r1, _080148E8 @ =0x0000071C
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _080148EC @ =0x000005A4
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	b _08014908
	.align 2, 0
_080148E0: .4byte 0x000005AA
_080148E4: .4byte 0x000005A5
_080148E8: .4byte 0x0000071C
_080148EC: .4byte 0x000005A4
_080148F0:
	ldrb r0, [r0]
	adds r0, r1, r0
	ldr r3, _0801492C @ =0x0000071C
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, _08014930 @ =0x000005A4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r5]
_08014908:
	ldr r0, _08014934 @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, [r5]
	ldr r2, _08014938 @ =0x000005AA
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
_08014916:
	movs r6, #1
	movs r0, SE_UNKNOWN_0x74
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_08014924:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801492C: .4byte 0x0000071C
_08014930: .4byte 0x000005A4
_08014934: .4byte 0x00002710
_08014938: .4byte 0x000005AA

	thumb_func_start sub_1493C
sub_1493C: @ 0x0801493C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08014A28 @ =gCurrentPinballGame
	mov sb, r0
	ldr r4, [r0]
	ldr r1, _08014A2C @ =0x0000132C
	mov r8, r1
	adds r0, r4, r1
	ldr r2, [r0]
	ldrh r1, [r2, #0x28]
	subs r1, #0xee
	lsls r1, r1, #0x10
	ldr r5, _08014A30 @ =0xFFFFFDD2
	adds r0, r5, #0
	ldrh r2, [r2, #0x2a]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r1, #0x10
	orrs r3, r0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	asrs r2, r3, #0x10
	adds r0, r2, #0
	muls r0, r2, r0
	adds r7, r1, r0
	ldr r0, _08014A34 @ =0x000006E3
	cmp r7, r0
	bgt _08014A04
	ldrb r1, [r4, #0x1e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08014A04
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, #0
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0x1e
	adds r0, r4, #0
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	ldr r6, _08014A38 @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r4, #0
	bl Sin
	rsbs r5, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #4]
	mov r0, sb
	ldr r4, [r0]
	add r4, r8
	ldr r5, [r4]
	movs r1, #0x64
	mov r8, r1
	ldr r2, [sp]
	mov r0, r8
	muls r0, r2, r0
	movs r2, #0x30
	ldrsh r1, [r5, r2]
	movs r6, #0x62
	muls r1, r6, r1
	adds r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0x30]
	ldr r4, [r4]
	ldr r5, [sp, #4]
	mov r0, r8
	muls r0, r5, r0
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	muls r1, r6, r1
	adds r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r4, #0x32]
_08014A04:
	ldr r0, _08014A28 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _08014A3C @ =0x000005F4
	adds r3, r1, r5
	ldrh r0, [r3]
	adds r2, r0, #0
	cmp r2, #0x13
	bhi _08014A5C
	cmp r7, #0x27
	bgt _08014A40
	adds r0, #1
	strh r0, [r3]
	ldr r2, _08014A2C @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	b _08014ADC
	.align 2, 0
_08014A28: .4byte gCurrentPinballGame
_08014A2C: .4byte 0x0000132C
_08014A30: .4byte 0xFFFFFDD2
_08014A34: .4byte 0x000006E3
_08014A38: .4byte 0x00004E20
_08014A3C: .4byte 0x000005F4
_08014A40:
	ldr r5, _08014A58 @ =0x0000132C
	adds r0, r1, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0xe]
	cmp r7, #0x64
	ble _08014ADE
	movs r0, #0
	strh r0, [r3]
	b _08014ADE
	.align 2, 0
_08014A58: .4byte 0x0000132C
_08014A5C:
	cmp r2, #0x1d
	bhi _08014AA8
	adds r0, #1
	movs r6, #0
	strh r0, [r3]
	ldr r0, _08014AA4 @ =0x0000132C
	adds r4, r1, r0
	ldr r5, [r4]
	ldrh r1, [r3]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r0, r0, #7
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x80
	strh r0, [r5, #0xe]
	ldr r1, [r4]
	movs r0, #0x77
	strh r0, [r1, #0x10]
	ldr r1, [r4]
	adds r0, #0xa0
	strh r0, [r1, #0x12]
	ldr r0, [r4]
	strh r6, [r0, #6]
	ldr r1, [r4]
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r5, #0x12
	ldrsh r0, [r1, r5]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	b _08014ADE
	.align 2, 0
_08014AA4: .4byte 0x0000132C
_08014AA8:
	movs r0, #0
	strh r0, [r3]
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08014AC0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08014AC4
	bl sub_1A98C
	b _08014AC8
	.align 2, 0
_08014AC0: .4byte gMain
_08014AC4:
	bl sub_32914
_08014AC8:
	ldr r2, _08014AEC @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08014AF0 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x80
_08014ADC:
	strh r0, [r1, #0xe]
_08014ADE:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014AEC: .4byte gCurrentPinballGame
_08014AF0: .4byte 0x0000132C

	thumb_func_start sub_14AF4
sub_14AF4: @ 0x08014AF4
	push {r4, r5, r6, r7, lr}
	adds r7, r2, #0
	movs r2, #0
	mov ip, r2
	asrs r2, r0, #0x10
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r4, r4, #5
	adds r4, r4, r0
	lsls r4, r4, #0x10
	ldr r2, _08014B70 @ =gCurrentPinballGame
	lsls r3, r3, #0x10
	asrs r6, r3, #0x10
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r3, _08014B74 @ =0x000013BC
	adds r0, r0, r3
	ldr r3, [r2]
	adds r3, r3, r0
	ldr r5, _08014B78 @ =gUnknown_086ACDB8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #2
	ldrsb r2, [r3, r2]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r0, [r1]
	strb r0, [r3, #5]
	ldr r0, _08014B7C @ =gUnknown_02031520
	movs r1, #5
	ldrsb r1, [r3, r1]
	ldr r2, [r0, #0x68]
	lsrs r4, r4, #0xf
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0xb
	adds r0, r0, r2
	adds r4, r4, r0
	ldrh r4, [r4]
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	beq _08014B66
	ldr r1, _08014B80 @ =0x0000FFF0
	ands r1, r4
	strh r1, [r7]
	cmp r6, #1
	bne _08014B62
	movs r0, #0x80
	lsls r0, r0, #8
	subs r0, r0, r1
	strh r0, [r7]
_08014B62:
	movs r0, #1
	mov ip, r0
_08014B66:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08014B70: .4byte gCurrentPinballGame
_08014B74: .4byte 0x000013BC
_08014B78: .4byte gUnknown_086ACDB8
_08014B7C: .4byte gUnknown_02031520
_08014B80: .4byte 0x0000FFF0

	thumb_func_start sub_14B84
sub_14B84: @ 0x08014B84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov r8, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r0, _08014C20 @ =gCurrentPinballGame
	ldr r2, [r0]
	lsls r3, r1, #0x10
	asrs r0, r3, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r2, r1
	ldr r6, _08014C24 @ =0x000013C1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08014C28 @ =0x000013C4
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08014BC8
	b _08014D3E
_08014BC8:
	adds r0, r2, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov sb, r3
	cmp r0, #0
	beq _08014BD8
	b _08014CF2
_08014BD8:
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	subs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r5, r5, r0
	ldr r0, _08014C2C @ =0x00000B21
	cmp r5, r0
	bgt _08014C34
	ldr r2, _08014C30 @ =0xFFFFF5D8
	adds r4, r5, r2
	lsls r0, r4, #0xb
	movs r1, #0x96
	lsls r1, r1, #2
	bl __divsi3
	movs r3, #0x90
	lsls r3, r3, #7
	adds r1, r3, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r4, r4, #7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, #0
	bl __divsi3
	adds r7, r0, #0
	adds r7, #0x78
	b _08014C68
	.align 2, 0
_08014C20: .4byte gCurrentPinballGame
_08014C24: .4byte 0x000013C1
_08014C28: .4byte 0x000013C4
_08014C2C: .4byte 0x00000B21
_08014C30: .4byte 0xFFFFF5D8
_08014C34:
	ldr r0, _08014D14 @ =gUnknown_086ACE2C
	lsls r1, r2, #2
	adds r6, r1, r0
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, _08014D18 @ =0xFFFFF5D8
	adds r4, r5, r1
	muls r0, r4, r0
	ldr r5, _08014D1C @ =0x00001518
	adds r1, r5, #0
	bl __divsi3
	ldrh r1, [r6]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0xae
	lsls r0, r0, #1
	muls r0, r4, r0
	adds r1, r5, #0
	bl __divsi3
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r7, r0, r2
_08014C68:
	mov r3, sl
	lsls r0, r3, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08014C7E
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	subs r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08014C7E:
	ldr r2, _08014D20 @ =gCurrentPinballGame
	mov sl, r2
	ldr r0, [r2]
	ldr r3, _08014D24 @ =0x0000132C
	adds r0, r0, r3
	ldr r2, [r0]
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08014C9C
	adds r0, #0x7f
_08014C9C:
	asrs r3, r0, #7
	movs r0, #8
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08014CB0
	adds r0, #0xff
_08014CB0:
	asrs r0, r0, #8
	adds r0, r3, r0
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	bl Cos
	mov r1, sl
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r5, _08014D28 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	adds r4, #0x60
	strh r0, [r4]
	adds r0, r6, #0
	bl Sin
	mov r2, sl
	ldr r4, [r2]
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	adds r4, #0x62
	strh r0, [r4]
_08014CF2:
	ldr r2, _08014D20 @ =gCurrentPinballGame
	ldr r3, [r2]
	adds r1, r3, #0
	adds r1, #0x5c
	movs r0, #1
	strh r0, [r1]
	mov r6, sb
	cmp r6, #0
	beq _08014D2C
	adds r0, r3, #0
	adds r0, #0x60
	ldrh r0, [r0]
	rsbs r0, r0, #0
	mov r1, r8
	strh r0, [r1]
	b _08014D36
	.align 2, 0
_08014D14: .4byte gUnknown_086ACE2C
_08014D18: .4byte 0xFFFFF5D8
_08014D1C: .4byte 0x00001518
_08014D20: .4byte gCurrentPinballGame
_08014D24: .4byte 0x0000132C
_08014D28: .4byte 0x00004E20
_08014D2C:
	adds r0, r3, #0
	adds r0, #0x60
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
_08014D36:
	ldr r0, [r2]
	adds r0, #0x62
	ldrh r0, [r0]
	b _08014DEA
_08014D3E:
	adds r0, r5, #0
	movs r1, #0x14
	bl __divsi3
	adds r5, r0, #0
	adds r0, r7, #0
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	ldr r6, _08014DFC @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08014E00 @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	adds r0, r7, #0
	bl Sin
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	rsbs r0, r0, #0
	adds r1, r6, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08014E04 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, r4, r0
	mov r3, r8
	strh r0, [r3]
	asrs r1, r4, #0x10
	movs r0, #2
	ldrsh r2, [r3, r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, r1, r0
	strh r1, [r3, #2]
	movs r2, #0
	ldrsh r0, [r3, r2]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	mov r3, r8
	strh r0, [r3]
	adds r0, r4, #0
	bl Sin
	rsbs r5, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
_08014DEA:
	mov r6, r8
	strh r0, [r6, #2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014DFC: .4byte 0x00004E20
_08014E00: .4byte 0xFFFF0000
_08014E04: .4byte 0x0000FFFF

	thumb_func_start COLLISION_CHECK_RUBY_14E08
COLLISION_CHECK_RUBY_14E08: @ 0x08014E08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _08014F0C @ =gCurrentPinballGame
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08014F10 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, sb
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _08014E3A
	adds r0, r4, #7
_08014E3A:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08014F14 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08014E56
	adds r0, r3, #7
_08014E56:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _08014F18 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08014E82
	adds r2, #0x3f
_08014E82:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _08014F1C @ =gUnknown_02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_15054
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _08014F00
	b _0801502C
_08014F00:
	lsls r0, r0, #2
	ldr r1, _08014F20 @ =_08014F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08014F0C: .4byte gCurrentPinballGame
_08014F10: .4byte 0x0000132C
_08014F14: .4byte 0xFFFF0000
_08014F18: .4byte 0x0000FFFF
_08014F1C: .4byte gUnknown_02031520
_08014F20: .4byte _08014F24
_08014F24: @ jump table
	.4byte _08014F3C @ case 0
	.4byte _08014FE8 @ case 1
	.4byte _08014FE8 @ case 2
	.4byte _08014F3C @ case 3
	.4byte _08015018 @ case 4
	.4byte _08014F3C @ case 5
_08014F3C:
	ldr r2, _08014FB4 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08014FB8 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08014FDC
	ldr r0, [r2]
	ldr r7, _08014FBC @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08014FC0 @ =gUnknown_02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08014F88
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08014FDC
_08014F88:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08014FA6
	cmp r0, #0
	bne _08014FD2
	ldr r0, _08014FC4 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08014FC8
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_08014FA6:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _08014FDC
	.align 2, 0
_08014FB4: .4byte gCurrentPinballGame
_08014FB8: .4byte 0xFFFFC010
_08014FBC: .4byte 0x0000132C
_08014FC0: .4byte gUnknown_02031520
_08014FC4: .4byte gMain
_08014FC8:
	ldr r0, _08014FE4 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08014FD2:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_08014FDC:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _0801502C
	.align 2, 0
_08014FE4: .4byte 0x0000FFD8
_08014FE8:
	ldr r2, _08015010 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08015014 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _0801502C
	.align 2, 0
_08015010: .4byte gCurrentPinballGame
_08015014: .4byte 0x0000FFF0
_08015018:
	ldr r2, _0801504C @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08015050 @ =0x000002A2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
	movs r6, #0
_0801502C:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_153CC
	mov r2, sp
	movs r4, #4
	ldrsh r0, [r2, r4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801504C: .4byte gCurrentPinballGame
_08015050: .4byte 0x000002A2

	thumb_func_start sub_15054
sub_15054: @ 0x08015054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	str r1, [sp]
	mov ip, r2
	movs r7, #0
	movs r5, #0
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _08015128 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801512C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r1, #0
	beq _08015084
	b _08015298
_08015084:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015094
	b _0801539A
_08015094:
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015146
	ldr r1, _08015130 @ =0x000002A3
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080150B4
	b _0801539A
_080150B4:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	ldrh r6, [r4]
	adds r1, r1, r6
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	ldrh r4, [r4, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	cmp r0, #0x4f
	bls _080150D8
	b _0801539A
_080150D8:
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x57
	bls _080150E2
	b _0801539A
_080150E2:
	ldr r2, _08015134 @ =gUnknown_08259C10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08015138 @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _08015104
	b _0801539A
_08015104:
	ldr r6, [sp]
	strh r7, [r6]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0801513C @ =0x000002A2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08015140
	mov r3, ip
	strb r5, [r3]
	ldr r0, [r1]
	adds r0, r0, r2
	movs r1, #7
	strb r1, [r0]
	b _0801539A
	.align 2, 0
_08015128: .4byte gCurrentPinballGame
_0801512C: .4byte 0x000005B2
_08015130: .4byte 0x000002A3
_08015134: .4byte gUnknown_08259C10
_08015138: .4byte 0x0000FFF0
_0801513C: .4byte 0x000002A2
_08015140:
	movs r0, #1
	mov r6, ip
	b _08015398
_08015146:
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08015154
	b _0801539A
_08015154:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	movs r6, #0xc3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r6, r1, #0x10
	lsrs r0, r6, #0x10
	mov sb, r3
	mov sl, r2
	cmp r0, #0x3f
	bhi _080151A2
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080151A2
	ldr r2, _08015288 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r6, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	beq _080151A6
	movs r0, #0
	str r0, [sp, #4]
_080151A2:
	cmp r5, #0
	bne _08015246
_080151A6:
	mov r1, r8
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, sb
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080151F0
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080151F0
	ldr r2, _08015288 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	beq _080151F4
	movs r0, #1
	str r0, [sp, #4]
_080151F0:
	cmp r5, #0
	bne _08015246
_080151F4:
	mov r1, r8
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, sb
	movs r6, #0xc7
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _08015240
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08015240
	ldr r2, _08015288 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _0801523C
	b _0801539A
_0801523C:
	movs r0, #2
	str r0, [sp, #4]
_08015240:
	cmp r5, #0
	bne _08015246
	b _0801539A
_08015246:
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _08015290 @ =0x0000016F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015266
	movs r6, #0xb8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldr r1, [sp, #4]
	adds r0, r0, r1
	movs r1, #0x6b
	strb r1, [r0]
_08015266:
	ldr r2, [sp]
	strh r7, [r2]
	mov r3, ip
	strb r5, [r3]
	mov r6, r8
	ldr r0, [r6]
	ldr r2, _08015294 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08015280
	b _0801539A
_08015280:
	movs r0, #2
	strb r0, [r1]
	b _0801539A
	.align 2, 0
_08015288: .4byte gUnknown_08252B10
_0801528C: .4byte 0x0000FFF0
_08015290: .4byte 0x0000016F
_08015294: .4byte 0x00000624
_08015298:
	mov r3, ip
	ldrb r1, [r3]
	movs r5, #0xf
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0801539A
	ldr r6, _080153AC @ =0x000002E5
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08015320
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x18
	rsbs r1, r1, #0
	subs r1, r1, r0
	lsls r1, r1, #1
	ldrh r3, [r4]
	adds r1, r1, r3
	ldr r6, _080153B0 @ =0xFFFFFDBC
	adds r0, r6, #0
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x47
	bhi _08015320
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x47
	bhi _08015320
	ldr r2, _080153B4 @ =gUnknown_08254B10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, _080153B8 @ =0x0000FFF0
	ands r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	adds r0, r5, #0
	ands r0, r1
	mov r6, ip
	strb r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08015320
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _080153BC @ =0x000002E2
	adds r0, r0, r3
	strb r1, [r0]
	movs r0, #6
	strb r0, [r6]
_08015320:
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _080153C0 @ =0x000002E6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0801539A
	ldr r3, _080153C4 @ =0x000002EE
	adds r0, r1, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	subs r1, #0xb4
	lsls r1, r1, #1
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _080153B0 @ =0xFFFFFDBC
	adds r0, r2, #0
	ldrh r4, [r4, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	cmp r0, #0x47
	bhi _0801539A
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x47
	bhi _0801539A
	ldr r2, _080153C8 @ =gUnknown_08257390
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, _080153B8 @ =0x0000FFF0
	ands r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	movs r0, #0xf
	ands r0, r1
	mov r6, ip
	strb r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801539A
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080153BC @ =0x000002E2
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	movs r0, #6
_08015398:
	strb r0, [r6]
_0801539A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080153AC: .4byte 0x000002E5
_080153B0: .4byte 0xFFFFFDBC
_080153B4: .4byte gUnknown_08254B10
_080153B8: .4byte 0x0000FFF0
_080153BC: .4byte 0x000002E2
_080153C0: .4byte 0x000002E6
_080153C4: .4byte 0x000002EE
_080153C8: .4byte gUnknown_08257390

	thumb_func_start sub_153CC
sub_153CC: @ 0x080153CC
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bls _080153E0
	bl _08016082
_080153E0:
	lsls r0, r0, #2
	ldr r1, _080153EC @ =_080153F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080153EC: .4byte _080153F0
_080153F0: @ jump table
	.4byte _0801542C @ case 0
	.4byte _08015494 @ case 1
	.4byte _080154E0 @ case 2
	.4byte _08015578 @ case 3
	.4byte _08015620 @ case 4
	.4byte _0801564C @ case 5
	.4byte _0801567C @ case 6
	.4byte _08015764 @ case 7
	.4byte _08015AA4 @ case 8
	.4byte _08015AF0 @ case 9
	.4byte _08015CA0 @ case 10
	.4byte _08015E4C @ case 11
	.4byte _08015EB4 @ case 12
	.4byte _08015F20 @ case 13
	.4byte _08015F8C @ case 14
_0801542C:
	ldr r0, _0801545C @ =gCurrentPinballGame
	ldr r2, [r0]
	ldrh r0, [r2, #0x26]
	cmp r0, #0
	beq _0801543A
	bl _08016082
_0801543A:
	ldr r1, _08015460 @ =0x0000132C
	adds r0, r2, r1
	ldr r3, [r0]
	movs r4, #0x28
	ldrsh r1, [r3, r4]
	ldr r0, _08015464 @ =0x00000167
	cmp r1, r0
	ble _08015470
	movs r1, #0x2a
	ldrsh r0, [r3, r1]
	cmp r0, #0xc7
	ble _08015468
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #1
	b _08015476
	.align 2, 0
_0801545C: .4byte gCurrentPinballGame
_08015460: .4byte 0x0000132C
_08015464: .4byte 0x00000167
_08015468:
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #3
	b _08015476
_08015470:
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #2
_08015476:
	strb r0, [r1]
	bl sub_1A98C
	ldr r0, _08015490 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	movs r0, #1
	strh r0, [r7]
	bl _08016082
	.align 2, 0
_08015490: .4byte gCurrentPinballGame
_08015494:
	ldr r3, _080154B8 @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _080154C0
	ldr r4, _080154BC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080154B8: .4byte gCurrentPinballGame
_080154BC: .4byte 0x0000132C
_080154C0:
	cmp r1, #2
	beq _080154C8
	bl _08016082
_080154C8:
	ldr r4, _080154DC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080154DC: .4byte 0x0000132C
_080154E0:
	ldr r1, _08015508 @ =gCurrentPinballGame
	ldr r2, [r1]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #2
	bne _08015510
	ldr r1, _0801550C @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	movs r2, #0
	movs r0, #3
	strb r0, [r1, #1]
	ldr r0, [r5]
	adds r0, #0x24
	strb r2, [r0]
	b _08015524
	.align 2, 0
_08015508: .4byte gCurrentPinballGame
_0801550C: .4byte 0x0000132C
_08015510:
	cmp r0, #3
	bne _08015524
	ldr r3, _0801556C @ =0x0000132C
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r5]
	adds r0, #0x24
	strb r1, [r0]
_08015524:
	ldr r0, [r5]
	ldr r4, _08015570 @ =0x000002FB
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bne _08015536
	movs r0, #7
	strb r0, [r1]
_08015536:
	ldr r0, [r5]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r3, #0xf0
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0801554E
	movs r0, #0
	strb r0, [r2]
_0801554E:
	ldr r0, [r5]
	ldr r2, _08015574 @ =0x000001AB
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	ands r0, r3
	cmp r0, #0
	bne _08015562
	bl _08016082
_08015562:
	movs r0, #0
	strb r0, [r1]
	bl _08016082
	.align 2, 0
_0801556C: .4byte 0x0000132C
_08015570: .4byte 0x000002FB
_08015574: .4byte 0x000001AB
_08015578:
	ldr r1, _080155B8 @ =gCurrentPinballGame
	ldr r2, [r1]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r3, [r0]
	adds r5, r1, #0
	cmp r3, #0
	beq _0801558E
	bl _08016082
_0801558E:
	ldr r4, _080155BC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x83
	ble _080155C4
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
	ldr r3, _080155C0 @ =0x0000070E
	adds r1, r2, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x62
	bgt _08015604
	adds r0, r2, #1
	strb r0, [r1]
	b _08015604
	.align 2, 0
_080155B8: .4byte gCurrentPinballGame
_080155BC: .4byte 0x0000132C
_080155C0: .4byte 0x0000070E
_080155C4:
	cmp r0, #0x5b
	ble _080155E4
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r2, #0x3c]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r3, [r0]
	ldr r0, _080155E0 @ =0x0000016F
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	b _08015604
	.align 2, 0
_080155E0: .4byte 0x0000016F
_080155E4:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
	ldr r3, _0801561C @ =0x000002B2
	adds r1, r2, r3
	movs r2, #0
	ldrsb r2, [r1, r2]
	cmp r2, #0
	bne _08015604
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xac
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r2, [r0]
_08015604:
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, SE_UNKNOWN_0x76
	bl m4aSongNumStart
	bl _08016082
	.align 2, 0
_0801561C: .4byte 0x000002B2
_08015620:
	ldr r1, _08015640 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, #0x20
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	ldr r4, _08015644 @ =0x00000165
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r1]
	ldr r1, _08015648 @ =0x00000732
	adds r0, r0, r1
	strb r3, [r0]
	bl _08016082
	.align 2, 0
_08015640: .4byte gCurrentPinballGame
_08015644: .4byte 0x00000165
_08015648: .4byte 0x00000732
_0801564C:
	ldr r4, _08015670 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _08015674 @ =0x000005B2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015662
	bl _08016082
_08015662:
	movs r0, #1
	bl sub_46FD4
	ldr r0, [r4]
	ldr r3, _08015678 @ =0x0000029E
	b _0801588E
	.align 2, 0
_08015670: .4byte gCurrentPinballGame
_08015674: .4byte 0x000005B2
_08015678: .4byte 0x0000029E
_0801567C:
	ldr r5, _080156C4 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r4, _080156C8 @ =0x0000132C
	mov ip, r4
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x31
	bgt _080156D4
	ldr r3, _080156CC @ =0x000002FA
	adds r0, r1, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _08015734
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r4, _080156D0 @ =0x000002FB
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	strh r2, [r7]
	b _08015734
	.align 2, 0
_080156C4: .4byte gCurrentPinballGame
_080156C8: .4byte 0x0000132C
_080156CC: .4byte 0x000002FA
_080156D0: .4byte 0x000002FB
_080156D4:
	ldr r2, _08015744 @ =0x000002FA
	adds r0, r1, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _08015734
	movs r3, #0
	movs r2, #2
	strb r2, [r0]
	ldr r0, [r5]
	ldr r1, _08015748 @ =0x000002FB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r2, [r0]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r4, [r7]
	ldr r1, [r5]
	mov r4, ip
	adds r2, r1, r4
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
	ldr r4, _0801574C @ =0x00001378
	adds r0, r1, r4
	ldr r2, _08015750 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r0, [r5]
	ldr r3, _08015754 @ =0x00001330
	adds r1, r0, r3
	adds r4, r0, r4
	str r4, [r1]
	ldr r4, _08015758 @ =0x00001328
	adds r0, r0, r4
	movs r1, #0x78
	strh r1, [r0]
_08015734:
	ldr r0, _0801575C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _08015760 @ =0x00000732
	adds r0, r0, r1
	movs r1, #0xe
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_08015744: .4byte 0x000002FA
_08015748: .4byte 0x000002FB
_0801574C: .4byte 0x00001378
_08015750: .4byte 0x00001334
_08015754: .4byte 0x00001330
_08015758: .4byte 0x00001328
_0801575C: .4byte gCurrentPinballGame
_08015760: .4byte 0x00000732
_08015764:
	ldr r0, _080157A8 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _080157AC @ =0x0000132C
	adds r1, r2, r3
	ldr r1, [r1]
	movs r4, #0x10
	ldrsh r1, [r1, r4]
	adds r5, r0, #0
	cmp r1, #0x32
	bgt _0801580C
	ldr r1, _080157B0 @ =0x00000732
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _080157EA
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _080157DC
	ldr r3, _080157B4 @ =0x0000072E
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080157DC
	cmp r0, #0
	bne _080157B8
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080157C6
	.align 2, 0
_080157A8: .4byte gCurrentPinballGame
_080157AC: .4byte 0x0000132C
_080157B0: .4byte 0x00000732
_080157B4: .4byte 0x0000072E
_080157B8:
	cmp r0, #1
	bne _080157C4
	ldr r0, _080157C0 @ =0x00001388
	b _080157C6
	.align 2, 0
_080157C0: .4byte 0x00001388
_080157C4:
	ldr r0, _080157F8 @ =0x00002710
_080157C6:
	str r0, [r2, #0x3c]
	ldr r0, _080157FC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r4, _08015800 @ =0x0000072E
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x99
	bl m4aSongNumStart
_080157DC:
	ldr r0, _080157FC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08015804 @ =0x000006BC
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	adds r5, r0, #0
_080157EA:
	ldr r0, [r5]
	ldr r3, _08015808 @ =0x00000732
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080157F8: .4byte 0x00002710
_080157FC: .4byte gCurrentPinballGame
_08015800: .4byte 0x0000072E
_08015804: .4byte 0x000006BC
_08015808: .4byte 0x00000732
_0801580C:
	cmp r1, #0x64
	bgt _080158A8
	ldr r4, _0801584C @ =0x00000732
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801588A
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r2, #0xa
	strb r2, [r0]
	ldr r1, [r5]
	subs r4, #7
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08015878
	cmp r0, #0
	bne _08015850
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	b _0801586C
	.align 2, 0
_0801584C: .4byte 0x00000732
_08015850:
	cmp r0, #1
	bne _08015864
	ldr r0, _08015860 @ =0x00001388
	str r0, [r1, #0x3c]
	adds r1, r1, r3
	movs r0, #5
	strb r0, [r1]
	b _0801586C
	.align 2, 0
_08015860: .4byte 0x00001388
_08015864:
	ldr r0, _08015898 @ =0x00002710
	str r0, [r1, #0x3c]
	adds r0, r1, r3
	strb r2, [r0]
_0801586C:
	ldr r1, [r5]
	ldr r0, _0801589C @ =0x0000072B
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08015878:
	ldr r0, [r5]
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r2, _080158A0 @ =0x0000072C
	adds r0, r0, r2
	strh r1, [r0]
_0801588A:
	ldr r0, [r5]
	ldr r3, _080158A4 @ =0x00000732
_0801588E:
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_08015898: .4byte 0x00002710
_0801589C: .4byte 0x0000072B
_080158A0: .4byte 0x0000072C
_080158A4: .4byte 0x00000732
_080158A8:
	cmp r1, #0x7e
	bgt _08015918
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080158C2
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_080158C2:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801590C @ =0x00000732
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08015910 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080158E6
	bl _08016082
_080158E6:
	subs r2, #2
	adds r0, r1, r2
	adds r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _080158FA
	b _08016082
_080158FA:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _08015914 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_0801590C: .4byte 0x00000732
_08015910: .4byte 0x0000071B
_08015914: .4byte 0x0000071C
_08015918:
	cmp r1, #0x94
	bgt _08015988
	ldr r1, _08015978 @ =0x00000719
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015930
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_08015930:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801597C @ =0x00000732
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08015980 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08015952
	b _08016082
_08015952:
	subs r2, #3
	adds r0, r1, r2
	adds r2, #2
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08015966
	b _08016082
_08015966:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _08015984 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_08015978: .4byte 0x00000719
_0801597C: .4byte 0x00000732
_08015980: .4byte 0x0000071B
_08015984: .4byte 0x0000071C
_08015988:
	cmp r1, #0xac
	bgt _080159F8
	ldr r1, _080159E8 @ =0x0000071A
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080159A0
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_080159A0:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _080159EC @ =0x00000732
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _080159F0 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080159C2
	b _08016082
_080159C2:
	subs r2, #3
	adds r0, r1, r2
	adds r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _080159D6
	b _08016082
_080159D6:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _080159F4 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_080159E8: .4byte 0x0000071A
_080159EC: .4byte 0x00000732
_080159F0: .4byte 0x0000071B
_080159F4: .4byte 0x0000071C
_080159F8:
	ldr r4, _08015A28 @ =0x00000732
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _08015A78
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _08015A6A
	ldr r1, _08015A2C @ =0x0000072F
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08015A6A
	cmp r0, #0
	bne _08015A30
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08015A3E
	.align 2, 0
_08015A28: .4byte 0x00000732
_08015A2C: .4byte 0x0000072F
_08015A30:
	cmp r0, #1
	bne _08015A3C
	ldr r0, _08015A38 @ =0x00001388
	b _08015A3E
	.align 2, 0
_08015A38: .4byte 0x00001388
_08015A3C:
	ldr r0, _08015A84 @ =0x00002710
_08015A3E:
	str r0, [r2, #0x3c]
	ldr r5, _08015A88 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r4, _08015A8C @ =0x0000072F
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08015A90 @ =gMPlayInfo_SE1
	ldr r1, _08015A94 @ =gUnknown_0869FC0C
	bl MPlayStart
	ldr r1, [r5]
	adds r4, r1, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #1
	ble _08015A6A
	ldr r2, _08015A98 @ =0x00000731
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
_08015A6A:
	ldr r0, _08015A88 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _08015A9C @ =0x000006BC
	adds r1, r1, r3
	movs r2, #2
	strb r2, [r1]
	adds r5, r0, #0
_08015A78:
	ldr r0, [r5]
	ldr r4, _08015AA0 @ =0x00000732
	adds r0, r0, r4
	movs r1, #6
	strb r1, [r0]
	b _08016082
	.align 2, 0
_08015A84: .4byte 0x00002710
_08015A88: .4byte gCurrentPinballGame
_08015A8C: .4byte 0x0000072F
_08015A90: .4byte gMPlayInfo_SE1
_08015A94: .4byte gUnknown_0869FC0C
_08015A98: .4byte 0x00000731
_08015A9C: .4byte 0x000006BC
_08015AA0: .4byte 0x00000732
_08015AA4:
	ldr r0, _08015AC0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08015AC4 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0x10
	ldrsh r0, [r0, r3]
	cmp r0, #0x32
	bgt _08015ACC
	ldr r4, _08015AC8 @ =0x00000732
	adds r1, r1, r4
	movs r0, #8
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015AC0: .4byte gCurrentPinballGame
_08015AC4: .4byte 0x0000132C
_08015AC8: .4byte 0x00000732
_08015ACC:
	cmp r0, #0x64
	bgt _08015AE0
	ldr r0, _08015ADC @ =0x00000732
	adds r1, r1, r0
	movs r0, #7
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015ADC: .4byte 0x00000732
_08015AE0:
	ldr r2, _08015AEC @ =0x00000732
	adds r1, r1, r2
	movs r0, #9
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015AEC: .4byte 0x00000732
_08015AF0:
	ldr r4, _08015B48 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r3, _08015B4C @ =0x0000132C
	adds r0, r1, r3
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x2e
	bgt _08015B60
	ldr r3, _08015B50 @ =0x00000732
	adds r0, r1, r3
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, [r4]
	movs r0, #0xe2
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015B1C
	b _08016082
_08015B1C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08015B54 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015B36
	b _08016082
_08015B36:
	ldr r2, _08015B58 @ =0x00000711
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015B5C @ =0x00000713
	b _08015C64
	.align 2, 0
_08015B48: .4byte gCurrentPinballGame
_08015B4C: .4byte 0x0000132C
_08015B50: .4byte 0x00000732
_08015B54: .4byte 0x00000714
_08015B58: .4byte 0x00000711
_08015B5C: .4byte 0x00000713
_08015B60:
	cmp r0, #0x78
	bgt _08015BC0
	ldr r2, _08015BAC @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xb
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015BB0 @ =0x00000711
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015B7C
	b _08016082
_08015B7C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015BB4 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015B96
	b _08016082
_08015B96:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015BB8 @ =0x00000712
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015BBC @ =0x00000713
	b _08015C64
	.align 2, 0
_08015BAC: .4byte 0x00000732
_08015BB0: .4byte 0x00000711
_08015BB4: .4byte 0x00000714
_08015BB8: .4byte 0x00000712
_08015BBC: .4byte 0x00000713
_08015BC0:
	cmp r0, #0xc1
	bgt _08015C20
	ldr r2, _08015C0C @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015C10 @ =0x00000712
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015BDC
	b _08016082
_08015BDC:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015C14 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015BF6
	b _08016082
_08015BF6:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015C18 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015C1C @ =0x00000713
	b _08015C64
	.align 2, 0
_08015C0C: .4byte 0x00000732
_08015C10: .4byte 0x00000712
_08015C14: .4byte 0x00000714
_08015C18: .4byte 0x00000711
_08015C1C: .4byte 0x00000713
_08015C20:
	ldr r2, _08015C88 @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015C8C @ =0x00000713
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015C38
	b _08016082
_08015C38:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015C90 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015C52
	b _08016082
_08015C52:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015C94 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015C98 @ =0x00000712
_08015C64:
	adds r1, r3, r2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08015C70
	b _08016082
_08015C70:
	strb r6, [r5]
	ldr r0, [r4]
	ldr r3, _08015C9C @ =0x00000715
	adds r0, r0, r3
	movs r1, #0x7e
	strb r1, [r0]
	ldr r1, [r4]
_08015C7E:
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
	b _08016082
	.align 2, 0
_08015C88: .4byte 0x00000732
_08015C8C: .4byte 0x00000713
_08015C90: .4byte 0x00000714
_08015C94: .4byte 0x00000711
_08015C98: .4byte 0x00000712
_08015C9C: .4byte 0x00000715
_08015CA0:
	ldr r1, _08015D18 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r4, _08015D1C @ =0x000005B2
	adds r0, r2, r4
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r5, r1, #0
	cmp r3, #0
	beq _08015CB4
	b _08015DE0
_08015CB4:
	ldr r1, _08015D20 @ =0x0000132C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #0x10
	ldrsh r0, [r0, r4]
	cmp r0, #0xaa
	ble _08015D30
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _08015CD0
	b _08016082
_08015CD0:
	adds r0, r2, #0
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r2, #0xb0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08015D0E
	ldr r3, _08015D24 @ =0x000001AB
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08015D0E
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r4, _08015D28 @ =0x000002F2
	adds r0, r0, r4
	movs r1, #5
	strh r1, [r0]
_08015D0E:
	ldr r1, [r5]
	ldr r0, _08015D2C @ =0x0000C350
	str r0, [r1, #0x3c]
	b _08016082
	.align 2, 0
_08015D18: .4byte gCurrentPinballGame
_08015D1C: .4byte 0x000005B2
_08015D20: .4byte 0x0000132C
_08015D24: .4byte 0x000001AB
_08015D28: .4byte 0x000002F2
_08015D2C: .4byte 0x0000C350
_08015D30:
	ldr r4, _08015D88 @ =0x000002FB
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _08015D58
	adds r0, r2, #0
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xf8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
_08015D58:
	ldr r0, [r5]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _08015D68
	movs r0, #6
	strb r0, [r1]
_08015D68:
	ldr r1, [r5]
	ldr r2, _08015D8C @ =0x0000029F
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015D7A
	b _08016082
_08015D7A:
	cmp r0, #1
	bne _08015D94
	ldr r3, _08015D90 @ =0x00000286
	adds r1, r1, r3
	movs r0, #0x5a
	strh r0, [r1]
	b _08015DB6
	.align 2, 0
_08015D88: .4byte 0x000002FB
_08015D8C: .4byte 0x0000029F
_08015D90: .4byte 0x00000286
_08015D94:
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r1, r4
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08015DD0 @ =0x0000071B
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _08015DD4 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	movs r0, SE_UNKNOWN_0xD8
	bl m4aSongNumStart
_08015DB6:
	ldr r2, _08015DD8 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r4, _08015DDC @ =0x0000029F
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r0, r1
	subs r1, #0x48
	strh r1, [r0]
	b _08016082
	.align 2, 0
_08015DD0: .4byte 0x0000071B
_08015DD4: .4byte 0x0000071C
_08015DD8: .4byte gCurrentPinballGame
_08015DDC: .4byte 0x0000029F
_08015DE0:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015DEE
	b _08016082
_08015DEE:
	ldr r4, _08015E04 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _08015E08
	subs r3, #2
	adds r1, r2, r3
	movs r0, #1
	b _08015E10
	.align 2, 0
_08015E04: .4byte 0x0000132C
_08015E08:
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #2
_08015E10:
	strb r0, [r1]
	ldr r2, [r5]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08015E40
	adds r1, r0, #0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	beq _08015E38
	b _08016082
_08015E38:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r2, r4
	b _08015E46
_08015E40:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r2, r0
_08015E46:
	movs r0, #0x78
	strh r0, [r1]
	b _08016082
_08015E4C:
	ldr r6, _08015EA4 @ =gCurrentPinballGame
	ldr r1, [r6]
	ldr r5, _08015EA8 @ =0x00000616
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015E5C
	b _08016082
_08015E5C:
	ldr r2, _08015EAC @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r2, [r0, #0x32]
	ldr r3, _08015EB0 @ =0x00000614
	adds r0, r1, r3
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08015E78
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08015E78:
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r4, r1, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa8
	ble _08015E9A
	movs r0, #0xa8
	strh r0, [r4]
_08015E9A:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x14
	strh r1, [r0]
	b _08016082
	.align 2, 0
_08015EA4: .4byte gCurrentPinballGame
_08015EA8: .4byte 0x00000616
_08015EAC: .4byte 0x0000132C
_08015EB0: .4byte 0x00000614
_08015EB4:
	ldr r3, _08015F14 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015ECA
	b _08016082
_08015ECA:
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _08015ED2
	b _08016082
_08015ED2:
	ldr r2, _08015F18 @ =0x000002DA
	adds r1, r1, r2
	ldrb r0, [r1]
	movs r2, #0
	ldrsb r2, [r1, r2]
	cmp r2, #0
	beq _08015EE2
	b _08016082
_08015EE2:
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r4, #0xd0
	lsls r4, r4, #8
	adds r0, r4, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r3]
	ldr r0, _08015F1C @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	b _08016020
	.align 2, 0
_08015F14: .4byte gCurrentPinballGame
_08015F18: .4byte 0x000002DA
_08015F1C: .4byte 0x00001388
_08015F20:
	ldr r4, _08015F80 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r5, #0xb6
	lsls r5, r5, #2
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015F36
	b _08016082
_08015F36:
	ldrh r2, [r1, #0x26]
	cmp r2, #0
	beq _08015F3E
	b _08016082
_08015F3E:
	ldr r0, _08015F84 @ =0x000002DA
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r3, #0
	ldrsb r3, [r1, r3]
	cmp r3, #1
	beq _08015F4E
	b _08016082
_08015F4E:
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xcc
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	strh r3, [r7]
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r1, [r4]
	ldr r0, _08015F88 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015F80: .4byte gCurrentPinballGame
_08015F84: .4byte 0x000002DA
_08015F88: .4byte 0x00001388
_08015F8C:
	ldr r0, _08015FE8 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r2, #0x13
	ldrsb r2, [r3, r2]
	adds r5, r0, #0
	cmp r2, #2
	ble _0801602C
	cmp r2, #5
	beq _0801602C
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _08016082
	ldr r4, _08015FEC @ =0x000002DA
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #2
	bne _08015FF4
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r1, [r0]
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r5]
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _08015FF0 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015FE8: .4byte gCurrentPinballGame
_08015FEC: .4byte 0x000002DA
_08015FF0: .4byte 0x00001388
_08015FF4:
	cmp r1, #3
	bne _08016082
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r2, #0xc8
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	movs r4, #1
	strh r4, [r7]
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r0, [r5]
	ldr r3, _08016028 @ =0x000002D9
	adds r0, r0, r3
	strb r4, [r0]
_08016020:
	movs r0, #7
	bl sub_11B0
	b _08016082
	.align 2, 0
_08016028: .4byte 0x000002D9
_0801602C:
	ldr r1, [r5]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08016082
	ldr r0, _08016088 @ =0x000002DA
	adds r2, r1, r0
	ldrb r0, [r2]
	movs r3, #0
	ldrsb r3, [r2, r3]
	cmp r3, #2
	bne _08016082
	adds r0, #1
	movs r1, #0
	strb r0, [r2]
	ldr r0, [r5]
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r3, [r0]
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _0801608C @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, #7
	bl sub_11B0
_08016082:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016088: .4byte 0x000002DA
_0801608C: .4byte 0x00001388

	thumb_func_start COLLISION_CHECK_SAPPHIRE_16090
COLLISION_CHECK_SAPPHIRE_16090: @ 0x08016090
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _08016190 @ =gCurrentPinballGame
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08016194 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r1, sb
	movs r3, #0
	ldrsh r4, [r1, r3]
	adds r0, r4, #0
	cmp r4, #0
	bge _080160C2
	adds r0, r4, #7
_080160C2:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r7, _08016198 @ =0xFFFF0000
	mov ip, r7
	mov r2, ip
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _080160E0
	adds r0, r3, #7
_080160E0:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _0801619C @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _0801610C
	adds r2, #0x3f
_0801610C:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _080161A0 @ =gUnknown_02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_162B8
	ldrb r0, [r4]
	movs r1, #0xf
	ands r1, r0
	lsrs r6, r0, #4
	cmp r1, #3
	bgt _080161A4
	cmp r1, #2
	bge _0801626C
	cmp r1, #1
	beq _080161A8
	b _08016290
	.align 2, 0
_08016190: .4byte gCurrentPinballGame
_08016194: .4byte 0x0000132C
_08016198: .4byte 0xFFFF0000
_0801619C: .4byte 0x0000FFFF
_080161A0: .4byte gUnknown_02031520
_080161A4:
	cmp r1, #4
	bne _08016290
_080161A8:
	ldr r2, _08016208 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r3, _0801620C @ =0xFFFFC010
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08016260
	ldr r0, [r2]
	ldr r4, _08016210 @ =0x0000132C
	adds r3, r0, r4
	ldr r2, [r3]
	movs r7, #0x10
	ldrsh r1, [r2, r7]
	ldr r4, _08016214 @ =gUnknown_02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _080161F4
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08016260
_080161F4:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _08016218
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r3, r8
	strh r0, [r3]
	b _08016260
	.align 2, 0
_08016208: .4byte gCurrentPinballGame
_0801620C: .4byte 0xFFFFC010
_08016210: .4byte 0x0000132C
_08016214: .4byte gUnknown_02031520
_08016218:
	cmp r0, #0
	beq _08016228
	movs r4, #0x82
	lsls r4, r4, #7
	adds r0, r4, #0
	mov r7, r8
	strh r0, [r7]
	b _08016260
_08016228:
	ldr r0, _08016248 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _0801624C
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	b _08016260
	.align 2, 0
_08016248: .4byte gMain
_0801624C:
	ldr r0, _08016268 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
	movs r3, #0x82
	lsls r3, r3, #7
	adds r0, r3, #0
	mov r4, r8
	strh r0, [r4]
_08016260:
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _08016290
	.align 2, 0
_08016268: .4byte 0x0000FFD8
_0801626C:
	ldr r2, _080162B0 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080162B4 @ =0x0000FFF0
	ands r0, r1
	mov r3, r8
	strh r0, [r3]
	movs r0, #1
	mov r4, sp
	strh r0, [r4, #4]
_08016290:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_1642C
	mov r7, sp
	movs r1, #4
	ldrsh r0, [r7, r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080162B0: .4byte gCurrentPinballGame
_080162B4: .4byte 0x0000FFF0

	thumb_func_start sub_162B8
sub_162B8: @ 0x080162B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	movs r7, #0
	movs r6, #0
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08016418 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801641C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _080162E8
	b _08016408
_080162E8:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _080162FA
	b _08016408
_080162FA:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	adds r5, #2
	adds r0, r2, r5
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	mov r8, r3
	mov sb, r2
	cmp r0, #0x3f
	bhi _08016342
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08016342
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	mov r0, ip
	str r0, [sp, #8]
_08016342:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #1
	str r0, [sp, #8]
_0801638C:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc7
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #2
	str r0, [sp, #8]
_080163D6:
	cmp r6, #0
	beq _08016408
_080163DA:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [sp, #8]
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	ldr r5, [sp]
	strh r7, [r5]
	ldr r0, [sp, #4]
	strb r6, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08016428 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08016408
	movs r0, #2
	strb r0, [r1]
_08016408:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016418: .4byte gCurrentPinballGame
_0801641C: .4byte 0x000005B2
_08016420: .4byte gUnknown_08252B10
_08016424: .4byte 0x0000FFF0
_08016428: .4byte 0x00000624

	thumb_func_start sub_1642C
sub_1642C: @ 0x0801642C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bls _08016446
	bl _080171B8
_08016446:
	lsls r0, r0, #2
	ldr r1, _08016450 @ =_08016454
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016450: .4byte _08016454
_08016454: @ jump table
	.4byte _08016490 @ case 0
	.4byte _080164D8 @ case 1
	.4byte _08016530 @ case 2
	.4byte _08016580 @ case 3
	.4byte _08016794 @ case 4
	.4byte _080167CC @ case 5
	.4byte _0801686C @ case 6
	.4byte _080168B4 @ case 7
	.4byte _08016C28 @ case 8
	.4byte _08016C80 @ case 9
	.4byte _08016E28 @ case 10
	.4byte _08016EA2 @ case 11
	.4byte _08016F08 @ case 12
	.4byte _08017094 @ case 13
	.4byte _0801716C @ case 14
_08016490:
	ldr r0, _080164B4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _0801649E
	bl _080171B8
_0801649E:
	ldr r2, _080164B8 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0x28
	ldrsh r0, [r0, r3]
	cmp r0, #0xc7
	ble _080164BC
	adds r1, #0x25
	movs r0, #1
	b _080164C0
	.align 2, 0
_080164B4: .4byte gCurrentPinballGame
_080164B8: .4byte 0x0000132C
_080164BC:
	adds r1, #0x25
	movs r0, #3
_080164C0:
	strb r0, [r1]
	bl sub_32914
	ldr r0, _080164D4 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	b _080168A4
	.align 2, 0
_080164D4: .4byte gCurrentPinballGame
_080164D8:
	ldr r3, _080164F0 @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _080164F8
	ldr r4, _080164F4 @ =0x0000132C
	adds r0, r2, r4
	b _0801656C
	.align 2, 0
_080164F0: .4byte gCurrentPinballGame
_080164F4: .4byte 0x0000132C
_080164F8:
	cmp r1, #2
	bne _08016514
	ldr r5, _08016510 @ =0x0000132C
	adds r0, r2, r5
	ldr r0, [r0]
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016510: .4byte 0x0000132C
_08016514:
	cmp r1, #3
	beq _0801651C
	bl _080171B8
_0801651C:
	ldr r1, _0801652C @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #1]
	bl _080171B8
	.align 2, 0
_0801652C: .4byte 0x0000132C
_08016530:
	ldr r3, _08016558 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08016560
	ldr r2, _0801655C @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r2, #0
	movs r0, #3
	strb r0, [r1, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r2, [r0]
	bl _080171B8
	.align 2, 0
_08016558: .4byte gCurrentPinballGame
_0801655C: .4byte 0x0000132C
_08016560:
	cmp r0, #3
	beq _08016568
	bl _080171B8
_08016568:
	ldr r4, _0801657C @ =0x0000132C
	adds r0, r1, r4
_0801656C:
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801657C: .4byte 0x0000132C
_08016580:
	ldr r5, _080165D4 @ =gCurrentPinballGame
	ldr r3, [r5]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r4, [r0]
	cmp r4, #0
	beq _08016594
	bl _080171B8
_08016594:
	ldr r6, _080165D8 @ =0x0000132C
	adds r0, r3, r6
	ldr r2, [r0]
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	ldr r0, _080165DC @ =0x00000103
	cmp r1, r0
	ble _080165A6
	b _08016718
_080165A6:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x49
	bgt _08016624
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _080165B8
	b _0801676E
_080165B8:
	ldr r2, _080165E0 @ =0x0000036B
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080165C8
	b _0801676E
_080165C8:
	cmp r0, #1
	bne _080165E8
	ldr r4, _080165E4 @ =0x0000036D
	adds r1, r3, r4
	movs r0, #6
	b _080165EE
	.align 2, 0
_080165D4: .4byte gCurrentPinballGame
_080165D8: .4byte 0x0000132C
_080165DC: .4byte 0x00000103
_080165E0: .4byte 0x0000036B
_080165E4: .4byte 0x0000036D
_080165E8:
	ldr r5, _08016614 @ =0x0000036D
	adds r1, r3, r5
	movs r0, #4
_080165EE:
	strb r0, [r1]
	ldr r5, _08016618 @ =gCurrentPinballGame
	ldr r1, [r5]
	movs r0, #0xdc
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, _0801661C @ =0x0000036B
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r3, _08016620 @ =0x0000132C
	adds r4, r1, r3
	b _0801667E
	.align 2, 0
_08016614: .4byte 0x0000036D
_08016618: .4byte gCurrentPinballGame
_0801661C: .4byte 0x0000036B
_08016620: .4byte 0x0000132C
_08016624:
	cmp r0, #0x73
	bgt _080166DC
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _08016632
	b _0801676E
_08016632:
	ldr r5, _08016650 @ =0x0000036A
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08016642
	b _0801676E
_08016642:
	cmp r0, #1
	bne _08016654
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
	b _0801665C
	.align 2, 0
_08016650: .4byte 0x0000036A
_08016654:
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
_0801665C:
	strb r0, [r1]
	ldr r5, _080166BC @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r3, _080166C0 @ =0x0000036E
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	ldr r4, _080166C4 @ =0x0000036A
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r0, _080166C8 @ =0x0000132C
	adds r4, r1, r0
_0801667E:
	ldr r3, [r4]
	movs r2, #0x30
	ldrsh r0, [r3, r2]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x30]
	ldr r3, [r4]
	movs r4, #0x32
	ldrsh r0, [r3, r4]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x32]
	ldr r4, _080166CC @ =0x00001378
	adds r0, r1, r4
	ldr r2, _080166D0 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r0, [r5]
	ldr r3, _080166D4 @ =0x00001330
	adds r1, r0, r3
	adds r4, r0, r4
	str r4, [r1]
	ldr r4, _080166D8 @ =0x00001328
	adds r0, r0, r4
	movs r1, #0x19
	strh r1, [r0]
	b _0801676E
	.align 2, 0
_080166BC: .4byte gCurrentPinballGame
_080166C0: .4byte 0x0000036E
_080166C4: .4byte 0x0000036A
_080166C8: .4byte 0x0000132C
_080166CC: .4byte 0x00001378
_080166D0: .4byte 0x00001334
_080166D4: .4byte 0x00001330
_080166D8: .4byte 0x00001328
_080166DC:
	movs r0, #0xc3
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r2, _0801670C @ =0x00000306
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _08016710 @ =0x0000070E
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x62
	bgt _08016704
	adds r0, r2, #1
	strb r0, [r1]
_08016704:
	ldr r1, [r5]
	ldr r0, _08016714 @ =0x00001388
	str r0, [r1, #0x3c]
	b _0801676E
	.align 2, 0
_0801670C: .4byte 0x00000306
_08016710: .4byte 0x0000070E
_08016714: .4byte 0x00001388
_08016718:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x6d
	bgt _0801673E
	movs r2, #0xca
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	ldr r2, [r0]
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	b _0801676E
_0801673E:
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r3, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08016752
	movs r0, #1
	strb r0, [r1]
	b _08016754
_08016752:
	strb r4, [r1]
_08016754:
	ldr r0, _08016788 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r1, _0801678C @ =0x0000132C
	adds r0, r3, r1
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	ldr r0, _08016790 @ =0x00000BB8
	str r0, [r3, #0x3c]
_0801676E:
	ldr r0, _08016788 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, SE_UNKNOWN_0x76
	bl m4aSongNumStart
	bl _080171B8
	.align 2, 0
_08016788: .4byte gCurrentPinballGame
_0801678C: .4byte 0x0000132C
_08016790: .4byte 0x00000BB8
_08016794:
	ldr r1, _080167BC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080167C0 @ =0x00000165
	adds r0, r0, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x20
	strb r2, [r0]
	ldr r0, [r1]
	ldr r4, _080167C4 @ =0x00000732
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r1]
	ldr r5, _080167C8 @ =0x00000342
	adds r0, r0, r5
	strb r3, [r0]
	bl _080171B8
	.align 2, 0
_080167BC: .4byte gCurrentPinballGame
_080167C0: .4byte 0x00000165
_080167C4: .4byte 0x00000732
_080167C8: .4byte 0x00000342
_080167CC:
	ldr r0, _08016850 @ =gCurrentPinballGame
	mov sb, r0
	ldr r1, [r0]
	ldr r2, _08016854 @ =0x0000132C
	mov r8, r2
	adds r0, r1, r2
	ldr r2, [r0]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	cmp r0, #0x77
	bgt _0801685C
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bgt _080167EE
	bl _080171B8
_080167EE:
	movs r6, #0xda
	lsls r6, r6, #8
	movs r5, #0x30
	ldrsh r0, [r2, r5]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r7, r1, r0
	lsls r0, r7, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x11
	adds r0, r6, #0
	bl Cos
	mov r5, sb
	ldr r1, [r5]
	add r1, r8
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r5, _08016858 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x30]
	adds r0, r6, #0
	bl Sin
	mov r2, sb
	ldr r1, [r2]
	add r1, r8
	ldr r4, [r1]
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x32]
	bl _080171B8
	.align 2, 0
_08016850: .4byte gCurrentPinballGame
_08016854: .4byte 0x0000132C
_08016858: .4byte 0x00004E20
_0801685C:
	ldr r3, _08016868 @ =0x00000342
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	bl _080171B8
	.align 2, 0
_08016868: .4byte 0x00000342
_0801686C:
	ldr r4, _080168AC @ =gCurrentPinballGame
	ldr r3, [r4]
	ldr r1, _080168B0 @ =0x00000366
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08016882
	bl _080171B8
_08016882:
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r2, #0
	movs r0, #0x11
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r5]
_080168A4:
	movs r0, #1
	strh r0, [r6]
	bl _080171B8
	.align 2, 0
_080168AC: .4byte gCurrentPinballGame
_080168B0: .4byte 0x00000366
_080168B4:
	ldr r1, _0801690C @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r4, _08016910 @ =0x0000132C
	adds r0, r3, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #0
	ble _0801697C
	ldr r5, _08016914 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801695A
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r3, #0xa
	strb r3, [r0]
	ldr r1, [r1]
	ldr r4, _08016918 @ =0x0000072B
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016946
	cmp r0, #0
	bne _0801691C
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801690C: .4byte gCurrentPinballGame
_08016910: .4byte 0x0000132C
_08016914: .4byte 0x00000732
_08016918: .4byte 0x0000072B
_0801691C:
	cmp r0, #1
	bne _08016930
	ldr r0, _0801692C @ =0x00001388
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #5
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801692C: .4byte 0x00001388
_08016930:
	ldr r0, _0801696C @ =0x00002710
	str r0, [r1, #0x3c]
	adds r0, r1, r2
	strb r3, [r0]
_08016938:
	mov r5, sb
	ldr r1, [r5]
	ldr r0, _08016970 @ =0x0000072B
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08016946:
	mov r1, sb
	ldr r0, [r1]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r2, r0, r3
	movs r1, #0
	strh r1, [r2]
	ldr r4, _08016974 @ =0x0000072C
	adds r0, r0, r4
	strh r1, [r0]
_0801695A:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016978 @ =0x00000732
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801696C: .4byte 0x00002710
_08016970: .4byte 0x0000072B
_08016974: .4byte 0x0000072C
_08016978: .4byte 0x00000732
_0801697C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x48
	bgt _08016A14
	ldr r2, _080169B4 @ =0x00000732
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _080169EE
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _080169E0
	ldr r4, _080169B8 @ =0x0000072E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080169E0
	cmp r0, #0
	bne _080169BC
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080169CA
	.align 2, 0
_080169B4: .4byte 0x00000732
_080169B8: .4byte 0x0000072E
_080169BC:
	cmp r0, #1
	bne _080169C8
	ldr r0, _080169C4 @ =0x00001388
	b _080169CA
	.align 2, 0
_080169C4: .4byte 0x00001388
_080169C8:
	ldr r0, _08016A00 @ =0x00002710
_080169CA:
	str r0, [r3, #0x3c]
	ldr r0, _08016A04 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _08016A08 @ =0x0000072E
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x99
	bl m4aSongNumStart
_080169E0:
	ldr r0, _08016A04 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08016A0C @ =0x000006BC
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	mov sb, r0
_080169EE:
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A10 @ =0x00000732
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016A00: .4byte 0x00002710
_08016A04: .4byte gCurrentPinballGame
_08016A08: .4byte 0x0000072E
_08016A0C: .4byte 0x000006BC
_08016A10: .4byte 0x00000732
_08016A14:
	cmp r0, #0x62
	bgt _08016A88
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016A2E
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016A2E:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016A78 @ =0x00000732
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016A7C @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016A52
	b _080171B8
_08016A52:
	ldr r5, _08016A80 @ =0x00000719
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016A66
	b _080171B8
_08016A66:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A84 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016A78: .4byte 0x00000732
_08016A7C: .4byte 0x0000071B
_08016A80: .4byte 0x00000719
_08016A84: .4byte 0x0000071C
_08016A88:
	cmp r0, #0x76
	bgt _08016AFC
	ldr r1, _08016AEC @ =0x00000719
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016AA0
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016AA0:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016AF0 @ =0x00000732
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016AF4 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016AC4
	b _080171B8
_08016AC4:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016ADA
	b _080171B8
_08016ADA:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016AF8 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016AEC: .4byte 0x00000719
_08016AF0: .4byte 0x00000732
_08016AF4: .4byte 0x0000071B
_08016AF8: .4byte 0x0000071C
_08016AFC:
	cmp r0, #0x92
	bgt _08016B70
	ldr r1, _08016B60 @ =0x0000071A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016B14
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016B14:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016B64 @ =0x00000732
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016B68 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016B38
	b _080171B8
_08016B38:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #2
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016B4E
	b _080171B8
_08016B4E:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016B6C @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016B60: .4byte 0x0000071A
_08016B64: .4byte 0x00000732
_08016B68: .4byte 0x0000071B
_08016B6C: .4byte 0x0000071C
_08016B70:
	ldr r5, _08016BA0 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _08016C00
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _08016BF4
	ldr r1, _08016BA4 @ =0x0000072F
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016BF4
	cmp r0, #0
	bne _08016BA8
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08016BB6
	.align 2, 0
_08016BA0: .4byte 0x00000732
_08016BA4: .4byte 0x0000072F
_08016BA8:
	cmp r0, #1
	bne _08016BB4
	ldr r0, _08016BB0 @ =0x00001388
	b _08016BB6
	.align 2, 0
_08016BB0: .4byte 0x00001388
_08016BB4:
	ldr r0, _08016C10 @ =0x00002710
_08016BB6:
	str r0, [r3, #0x3c]
	ldr r4, _08016C14 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r5, _08016C18 @ =0x0000072F
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xd
	bne _08016BDC
	movs r0, SE_UNKNOWN_0x99
	bl m4aSongNumStart
_08016BDC:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r4
	cmp r0, #1
	ble _08016BF4
	ldr r4, _08016C1C @ =0x00000731
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
_08016BF4:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016C20 @ =0x000006BC
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
_08016C00:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _08016C24 @ =0x00000732
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	b _080171B8
	.align 2, 0
_08016C10: .4byte 0x00002710
_08016C14: .4byte gCurrentPinballGame
_08016C18: .4byte 0x0000072F
_08016C1C: .4byte 0x00000731
_08016C20: .4byte 0x000006BC
_08016C24: .4byte 0x00000732
_08016C28:
	ldr r0, _08016C4C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r4, _08016C50 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08016C58
	ldr r5, _08016C54 @ =0x00000732
	adds r1, r1, r5
	movs r0, #7
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C4C: .4byte gCurrentPinballGame
_08016C50: .4byte 0x0000132C
_08016C54: .4byte 0x00000732
_08016C58:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	bgt _08016C70
	ldr r0, _08016C6C @ =0x00000732
	adds r1, r1, r0
	movs r0, #8
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C6C: .4byte 0x00000732
_08016C70:
	ldr r2, _08016C7C @ =0x00000732
	adds r1, r1, r2
	movs r0, #9
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C7C: .4byte 0x00000732
_08016C80:
	ldr r4, _08016CD8 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r3, _08016CDC @ =0x0000132C
	adds r0, r1, r3
	ldr r0, [r0]
	movs r5, #0x10
	ldrsh r0, [r0, r5]
	cmp r0, #0x2e
	bgt _08016CF4
	ldr r2, _08016CE0 @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, [r4]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016CAC
	b _080171B8
_08016CAC:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08016CE4 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016CC6
	b _080171B8
_08016CC6:
	ldr r1, _08016CE8 @ =0x00000711
	adds r0, r3, r1
	ldr r2, _08016CEC @ =0x00000712
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016CF0 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016CD8: .4byte gCurrentPinballGame
_08016CDC: .4byte 0x0000132C
_08016CE0: .4byte 0x00000732
_08016CE4: .4byte 0x00000714
_08016CE8: .4byte 0x00000711
_08016CEC: .4byte 0x00000712
_08016CF0: .4byte 0x00000713
_08016CF4:
	cmp r0, #0x78
	bgt _08016D50
	ldr r5, _08016D40 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xb
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016D44 @ =0x00000711
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D10
	b _080171B8
_08016D10:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016D48 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D2A
	b _080171B8
_08016D2A:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #2
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016D4C @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D40: .4byte 0x00000732
_08016D44: .4byte 0x00000711
_08016D48: .4byte 0x00000714
_08016D4C: .4byte 0x00000713
_08016D50:
	cmp r0, #0xc1
	bgt _08016DAC
	ldr r5, _08016D9C @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016DA0 @ =0x00000712
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D6C
	b _080171B8
_08016D6C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016DA4 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D86
	b _080171B8
_08016D86:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016DA8 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D9C: .4byte 0x00000732
_08016DA0: .4byte 0x00000712
_08016DA4: .4byte 0x00000714
_08016DA8: .4byte 0x00000713
_08016DAC:
	ldr r5, _08016E14 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016E18 @ =0x00000713
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016DC4
	b _080171B8
_08016DC4:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016E1C @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016DDE
	b _080171B8
_08016DDE:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016E20 @ =0x00000712
_08016DF0:
	adds r1, r3, r2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08016DFC
	b _080171B8
_08016DFC:
	strb r6, [r5]
	ldr r0, [r4]
	ldr r3, _08016E24 @ =0x00000715
	adds r0, r0, r3
	movs r1, #0x7e
	strb r1, [r0]
	ldr r1, [r4]
_08016E0A:
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
	b _080171B8
	.align 2, 0
_08016E14: .4byte 0x00000732
_08016E18: .4byte 0x00000713
_08016E1C: .4byte 0x00000714
_08016E20: .4byte 0x00000712
_08016E24: .4byte 0x00000715
_08016E28:
	ldr r0, _08016E54 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sb, r0
	cmp r1, #0
	beq _08016E3C
	b _080171B8
_08016E3C:
	ldr r5, _08016E58 @ =0x0000132C
	adds r0, r3, r5
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _08016E5C
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #1
	b _08016E64
	.align 2, 0
_08016E54: .4byte gCurrentPinballGame
_08016E58: .4byte 0x0000132C
_08016E5C:
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #2
_08016E64:
	strb r0, [r1]
	mov r5, sb
	ldr r2, [r5]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08016E96
	adds r1, r0, #0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	beq _08016E8E
	b _080171B8
_08016E8E:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r2, r4
	b _08016E9C
_08016E96:
	movs r5, #0xe2
	lsls r5, r5, #1
	adds r1, r2, r5
_08016E9C:
	movs r0, #0x78
	strh r0, [r1]
	b _080171B8
_08016EA2:
	ldr r6, _08016EF8 @ =gCurrentPinballGame
	ldr r1, [r6]
	ldr r5, _08016EFC @ =0x00000616
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08016EB2
	b _080171B8
_08016EB2:
	ldr r2, _08016F00 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r2, [r0, #0x32]
	ldr r3, _08016F04 @ =0x00000614
	adds r0, r1, r3
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08016ECE
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08016ECE:
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r4, r1, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa8
	ble _08016EF0
	movs r0, #0xa8
	strh r0, [r4]
_08016EF0:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x14
	b _080171B6
	.align 2, 0
_08016EF8: .4byte gCurrentPinballGame
_08016EFC: .4byte 0x00000616
_08016F00: .4byte 0x0000132C
_08016F04: .4byte 0x00000614
_08016F08:
	ldr r5, _08017058 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _0801705C @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xe
	bne _08016F1A
	b _080171B8
_08016F1A:
	movs r0, #0xe
	strb r0, [r1]
	ldr r3, _08017060 @ =gUnknown_086ACE70
	ldr r1, [r5]
	ldr r2, _08017064 @ =0x0000034A
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r3, [r0]
	mov r8, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r3, _08017068 @ =0x0000034B
	adds r1, r1, r3
	adds r1, r1, r0
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r2, r1, r2
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #3
	bne _08016F88
	ldr r4, _0801706C @ =0x00001378
	adds r0, r1, r4
	ldr r2, _08017070 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r1, [r5]
	ldr r3, _08017074 @ =0x00001330
	adds r0, r1, r3
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, _08017078 @ =0x00000342
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08016F88
	movs r5, #0xd1
	lsls r5, r5, #2
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1]
_08016F88:
	ldr r0, _08017058 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r6, _08017064 @ =0x0000034A
	adds r1, r3, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r1, #0xb
	bne _08016FA6
	ldr r0, _08017074 @ =0x00001330
	adds r1, r3, r0
	ldr r2, _08017070 @ =0x00001334
	adds r0, r3, r2
	str r0, [r1]
_08016FA6:
	mov r3, sb
	ldr r5, [r3]
	adds r0, r5, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _08016FBA
	adds r3, r1, #2
_08016FBA:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _0801707C @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r7, #0
	movs r4, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _08017080 @ =0x00000355
	adds r0, r5, r1
	adds r0, r0, r3
	strb r7, [r0]
	mov r5, sb
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r5, _08017084 @ =0x0000035E
	adds r0, r2, r5
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, _08017088 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xc
	ble _0801700E
	strb r7, [r1]
_0801700E:
	mov r2, r8
	lsls r0, r2, #0x10
	adds r3, r0, #0
	cmp r3, #0
	bne _08017030
	mov r4, sb
	ldr r0, [r4]
	ldr r5, _0801708C @ =0x0000132C
	adds r0, r0, r5
	ldr r2, [r0]
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08017030
	strh r1, [r2, #0x32]
_08017030:
	asrs r0, r3, #0x10
	cmp r0, #2
	beq _08017038
	b _080171B8
_08017038:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _0801708C @ =0x0000132C
	adds r0, r0, r3
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r1, [r2, r4]
	movs r0, #0xb4
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08017050
	b _080171B8
_08017050:
	ldr r0, _08017090 @ =0x0000FF4C
	strh r0, [r2, #0x32]
	b _080171B8
	.align 2, 0
_08017058: .4byte gCurrentPinballGame
_0801705C: .4byte 0x00000732
_08017060: .4byte gUnknown_086ACE70
_08017064: .4byte 0x0000034A
_08017068: .4byte 0x0000034B
_0801706C: .4byte 0x00001378
_08017070: .4byte 0x00001334
_08017074: .4byte 0x00001330
_08017078: .4byte 0x00000342
_0801707C: .4byte gMain
_08017080: .4byte 0x00000355
_08017084: .4byte 0x0000035E
_08017088: .4byte 0x00000359
_0801708C: .4byte 0x0000132C
_08017090: .4byte 0x0000FF4C
_08017094:
	ldr r5, _08017144 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _08017148 @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xf
	bne _080170A6
	b _080171B8
_080170A6:
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _0801714C @ =gUnknown_086ACE70
	ldr r1, [r5]
	ldr r6, _08017150 @ =0x0000034A
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r7, [r0, r3]
	ldr r4, _08017154 @ =0x0000034B
	adds r1, r1, r4
	adds r1, r1, r7
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, [r5]
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _080170E6
	adds r3, r1, #2
_080170E6:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _08017158 @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _0801715C @ =0x00000355
	adds r0, r4, r1
	adds r0, r0, r3
	strb r2, [r0]
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r4, _08017160 @ =0x0000035E
	adds r0, r2, r4
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08017164 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	cmp r7, #1
	bne _080171B8
	ldr r0, [r5]
	ldr r1, _08017168 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	movs r3, #0x96
	rsbs r3, r3, #0
	cmp r0, r3
	ble _080171B8
	strh r3, [r1, #0x32]
	b _080171B8
	.align 2, 0
_08017144: .4byte gCurrentPinballGame
_08017148: .4byte 0x00000732
_0801714C: .4byte gUnknown_086ACE70
_08017150: .4byte 0x0000034A
_08017154: .4byte 0x0000034B
_08017158: .4byte gMain
_0801715C: .4byte 0x00000355
_08017160: .4byte 0x0000035E
_08017164: .4byte 0x00000359
_08017168: .4byte 0x0000132C
_0801716C:
	ldr r3, _08017190 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _08017194 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	movs r5, #0x12
	ldrsh r0, [r0, r5]
	cmp r0, #0x4f
	bgt _0801719C
	ldr r0, _08017198 @ =0x00000306
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _080171B8
	movs r0, #2
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08017190: .4byte gCurrentPinballGame
_08017194: .4byte 0x0000132C
_08017198: .4byte 0x00000306
_0801719C:
	ldr r4, _080171C4 @ =0x00000306
	adds r2, r1, r4
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _080171B8
	movs r1, #0
	movs r0, #3
	strb r0, [r2]
	ldr r0, [r3]
	movs r5, #0xc3
	lsls r5, r5, #2
	adds r0, r0, r5
_080171B6:
	strh r1, [r0]
_080171B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080171C4: .4byte 0x00000306

	thumb_func_start COLLISION_CHECK_DUSCLOPS_171C8
COLLISION_CHECK_DUSCLOPS_171C8: @ 0x080171C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _080172CC @ =gCurrentPinballGame
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _080172D0 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, sb
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _080171FA
	adds r0, r4, #7
_080171FA:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080172D4 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08017216
	adds r0, r3, #7
_08017216:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _080172D8 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08017242
	adds r2, #0x3f
_08017242:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _080172DC @ =gUnknown_02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_173FC
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _080172C0
	b _080173DA
_080172C0:
	lsls r0, r0, #2
	ldr r1, _080172E0 @ =_080172E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080172CC: .4byte gCurrentPinballGame
_080172D0: .4byte 0x0000132C
_080172D4: .4byte 0xFFFF0000
_080172D8: .4byte 0x0000FFFF
_080172DC: .4byte gUnknown_02031520
_080172E0: .4byte _080172E4
_080172E4: @ jump table
	.4byte _080172FC @ case 0
	.4byte _080173A8 @ case 1
	.4byte _080173A8 @ case 2
	.4byte _080172FC @ case 3
	.4byte _080173D8 @ case 4
	.4byte _080172FC @ case 5
_080172FC:
	ldr r2, _08017374 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08017378 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _0801739C
	ldr r0, [r2]
	ldr r7, _0801737C @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08017380 @ =gUnknown_02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08017348
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _0801739C
_08017348:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08017366
	cmp r0, #0
	bne _08017392
	ldr r0, _08017384 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08017388
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_08017366:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _0801739C
	.align 2, 0
_08017374: .4byte gCurrentPinballGame
_08017378: .4byte 0xFFFFC010
_0801737C: .4byte 0x0000132C
_08017380: .4byte gUnknown_02031520
_08017384: .4byte gMain
_08017388:
	ldr r0, _080173A4 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08017392:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_0801739C:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _080173DA
	.align 2, 0
_080173A4: .4byte 0x0000FFD8
_080173A8:
	ldr r2, _080173D0 @ =gCurrentPinballGame
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080173D4 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _080173DA
	.align 2, 0
_080173D0: .4byte gCurrentPinballGame
_080173D4: .4byte 0x0000FFF0
_080173D8:
	movs r6, #4
_080173DA:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_17634
	mov r1, sp
	movs r2, #4
	ldrsh r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_173FC
sub_173FC: @ 0x080173FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov ip, r2
	movs r7, #0
	movs r3, #0
	ldr r1, _08017494 @ =gCurrentPinballGame
	ldr r5, [r1]
	ldr r2, _08017498 @ =0x00000387
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r1
	cmp r0, #2
	bne _080174C0
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801742C
	b _080175FE
_0801742C:
	adds r2, #0x69
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801749C @ =0x000003F2
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x5f
	bls _0801744E
	b _080175FE
_0801744E:
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x77
	bls _08017458
	b _080175FE
_08017458:
	ldr r2, _080174A0 @ =gUnknown_083071D4
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _080174A4 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	bne _0801747A
	b _080175FE
_0801747A:
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080174A8
	movs r0, #1
	mov r2, ip
	strb r0, [r2]
	b _080174AC
	.align 2, 0
_08017494: .4byte gCurrentPinballGame
_08017498: .4byte 0x00000387
_0801749C: .4byte 0x000003F2
_080174A0: .4byte gUnknown_083071D4
_080174A4: .4byte 0x0000FFF0
_080174A8:
	mov r0, ip
	strb r3, [r0]
_080174AC:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #4
	strb r1, [r0]
	mov r0, sb
	strh r7, [r0]
	b _080175FE
_080174C0:
	cmp r0, #1
	beq _080174C6
	b _080175FE
_080174C6:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _080174D0
	b _080175FE
_080174D0:
	ldr r2, _0801760C @ =0x000003A9
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801752C
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08017610 @ =0x000003D2
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _0801752C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801752C
	ldr r2, _08017614 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _08017530
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_0801752C:
	cmp r3, #0
	bne _080175F4
_08017530:
	mov r0, r8
	ldr r5, [r0]
	ldr r1, _0801761C @ =0x000003AA
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801758E
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08017620 @ =0x000003D6
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _0801758E
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801758E
	ldr r2, _08017614 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _08017592
	ldr r2, _08017624 @ =0x000003A1
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_0801758E:
	cmp r3, #0
	bne _080175F4
_08017592:
	mov r0, r8
	ldr r5, [r0]
	ldr r1, _08017628 @ =0x000003AB
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080175F0
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801762C @ =0x000003DA
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _080175F0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080175F0
	ldr r2, _08017614 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _080175FE
	ldr r2, _08017630 @ =0x000003A2
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_080175F0:
	cmp r3, #0
	beq _080175FE
_080175F4:
	mov r0, sb
	strh r7, [r0]
	movs r0, #6
	mov r1, ip
	strb r0, [r1]
_080175FE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801760C: .4byte 0x000003A9
_08017610: .4byte 0x000003D2
_08017614: .4byte gUnknown_08252B10
_08017618: .4byte 0x0000FFF0
_0801761C: .4byte 0x000003AA
_08017620: .4byte 0x000003D6
_08017624: .4byte 0x000003A1
_08017628: .4byte 0x000003AB
_0801762C: .4byte 0x000003DA
_08017630: .4byte 0x000003A2
