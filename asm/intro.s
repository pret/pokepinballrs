	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_C948
sub_C948: @ 0x0800C948
	push {r4, lr}
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r3]
	ldr r1, _0800C9E4 @ =0x0400000E
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0800C9E8 @ =0x040000D4
	ldr r1, _0800C9EC @ =gUnknown_08115A60
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800C9F0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C9F4 @ =gUnknown_08116260
	str r1, [r0]
	ldr r1, _0800C9F8 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _0800C9FC @ =0x80001200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r4, _0800CA00 @ =gUnknown_08115860
	str r4, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800CA04 @ =0x80000020
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800CA08 @ =gUnknown_08118680
	str r1, [r0]
	ldr r1, _0800CA0C @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800CA10 @ =0x80003800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [r0]
	ldr r1, _0800CA14 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0800CA18 @ =gMain
	ldrh r0, [r3]
	strh r0, [r4, #0x16]
	bl sub_CA28
	ldr r2, _0800CA1C @ =gUnknown_0202ADA0
	ldrh r1, [r2]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldr r1, _0800CA20 @ =0x000002F6
	adds r4, r4, r1
	strh r0, [r4]
	bl sub_0CBC
	bl sub_10424
	ldr r1, _0800CA24 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C9E4: .4byte 0x0400000E
_0800C9E8: .4byte 0x040000D4
_0800C9EC: .4byte gUnknown_08115A60
_0800C9F0: .4byte 0x80000400
_0800C9F4: .4byte gUnknown_08116260
_0800C9F8: .4byte 0x06004000
_0800C9FC: .4byte 0x80001200
_0800CA00: .4byte gUnknown_08115860
_0800CA04: .4byte 0x80000020
_0800CA08: .4byte gUnknown_08118680
_0800CA0C: .4byte 0x06010000
_0800CA10: .4byte 0x80003800
_0800CA14: .4byte 0x05000200
_0800CA18: .4byte gMain
_0800CA1C: .4byte gUnknown_0202ADA0
_0800CA20: .4byte 0x000002F6
_0800CA24: .4byte gUnknown_0202C790

	thumb_func_start sub_CA28
sub_CA28: @ 0x0800CA28
	push {r4, lr}
	ldr r0, _0800CA80 @ =gUnknown_0202ADA0
	movs r4, #0
	movs r3, #0
	strh r3, [r0]
	strh r3, [r0, #2]
	ldr r1, _0800CA84 @ =gUnknown_0201A450
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0x1e
	strh r0, [r1, #2]
	movs r0, #0xe
	strh r0, [r1, #4]
	movs r2, #1
	movs r0, #1
	strh r0, [r1, #8]
	strb r2, [r1, #0xc]
	movs r0, #0x84
	lsls r0, r0, #1
	strh r0, [r1, #0x10]
	movs r0, #0x50
	strh r0, [r1, #0x12]
	movs r0, #6
	strh r0, [r1, #0x14]
	strb r4, [r1, #0x1c]
	ldr r0, _0800CA88 @ =gUnknown_0202BF10
	strh r3, [r0]
	ldr r0, _0800CA8C @ =gUnknown_0202A578
	strh r3, [r0]
	ldr r0, _0800CA90 @ =gUnknown_0202C5E4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0800CA94 @ =gUnknown_0202ADD8
	strh r1, [r0]
	ldr r0, _0800CA98 @ =gUnknown_0202BEDC
	strb r4, [r0]
	ldr r0, _0800CA9C @ =gUnknown_0202A56C
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CA80: .4byte gUnknown_0202ADA0
_0800CA84: .4byte gUnknown_0201A450
_0800CA88: .4byte gUnknown_0202BF10
_0800CA8C: .4byte gUnknown_0202A578
_0800CA90: .4byte gUnknown_0202C5E4
_0800CA94: .4byte gUnknown_0202ADD8
_0800CA98: .4byte gUnknown_0202BEDC
_0800CA9C: .4byte gUnknown_0202A56C

	thumb_func_start sub_CAA0
sub_CAA0: @ 0x0800CAA0
	push {r4, r5, lr}
	ldr r4, _0800CB48 @ =gUnknown_0202ADA0
	ldrh r0, [r4]
	subs r0, #0x24
	strh r0, [r4]
	ldr r5, _0800CB4C @ =gUnknown_0201A450
	ldr r1, _0800CB50 @ =gUnknown_086A7D4C
	ldr r2, _0800CB54 @ =gUnknown_0202A578
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r0, _0800CB58 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800CAEA
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble _0800CAEA
	movs r0, #1
	strh r0, [r5, #8]
_0800CAEA:
	ldr r0, _0800CB5C @ =gMain
	ldrh r1, [r4]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bl sub_CD18
	ldr r2, _0800CB58 @ =gUnknown_0202BF10
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x28
	ble _0800CB26
	ldr r1, _0800CB60 @ =gUnknown_0202C5E4
	ldrh r0, [r1]
	adds r0, #6
	strh r0, [r1]
	ldr r1, _0800CB64 @ =gUnknown_0202ADD8
	ldrh r0, [r1]
	adds r0, #6
	strh r0, [r1]
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800CB26
	ldr r1, _0800CB4C @ =gUnknown_0201A450
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_0800CB26:
	ldr r0, _0800CB58 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x5a
	ble _0800CB42
	ldr r1, _0800CB4C @ =gUnknown_0201A450
	movs r0, #0
	strb r0, [r1, #0xc]
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, _0800CB68 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CB42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800CB48: .4byte gUnknown_0202ADA0
_0800CB4C: .4byte gUnknown_0201A450
_0800CB50: .4byte gUnknown_086A7D4C
_0800CB54: .4byte gUnknown_0202A578
_0800CB58: .4byte gUnknown_0202BF10
_0800CB5C: .4byte gMain
_0800CB60: .4byte gUnknown_0202C5E4
_0800CB64: .4byte gUnknown_0202ADD8
_0800CB68: .4byte gUnknown_0202C790

	thumb_func_start sub_CB6C
sub_CB6C: @ 0x0800CB6C
	ldr r0, _0800CB94 @ =gUnknown_0202ADA0
	ldrh r1, [r0]
	subs r1, #0x24
	strh r1, [r0]
	ldr r0, _0800CB98 @ =gMain
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	ldr r0, _0800CB9C @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	ble _0800CB90
	ldr r1, _0800CBA0 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CB90:
	bx lr
	.align 2, 0
_0800CB94: .4byte gUnknown_0202ADA0
_0800CB98: .4byte gMain
_0800CB9C: .4byte gUnknown_0202BF10
_0800CBA0: .4byte gUnknown_0202C790

	thumb_func_start sub_CBA4
sub_CBA4: @ 0x0800CBA4
	push {r4, lr}
	ldr r0, _0800CBBC @ =gUnknown_0202BF10
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r0, #0
	cmp r1, #0x86
	bgt _0800CBC4
	ldr r1, _0800CBC0 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #0xc
	b _0800CBCA
	.align 2, 0
_0800CBBC: .4byte gUnknown_0202BF10
_0800CBC0: .4byte gUnknown_0201A450
_0800CBC4:
	ldr r1, _0800CC68 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #1
_0800CBCA:
	strh r0, [r1, #0x10]
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	ldr r2, _0800CC6C @ =gUnknown_0202BEDC
	cmp r0, #0
	bne _0800CBEA
	ldrb r0, [r2]
	adds r0, #3
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	ble _0800CBEA
	movs r0, #0x20
	strb r0, [r2]
_0800CBEA:
	ldr r4, _0800CC70 @ =gUnknown_08115860
	ldr r1, _0800CC74 @ =0x05000200
	movs r3, #0
	ldrsb r3, [r2, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r2, #0x20
	bl sub_102A8
	ldr r0, _0800CC78 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x88
	ble _0800CC30
	ldr r2, _0800CC7C @ =gUnknown_0202A56C
	ldrb r0, [r2]
	adds r0, #2
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	ble _0800CC1C
	movs r0, #0x20
	strb r0, [r2]
_0800CC1C:
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r3, #0
	ldrsb r3, [r2, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r2, #0x40
	bl sub_102A8
_0800CC30:
	ldr r0, _0800CC80 @ =gUnknown_0202ADA0
	ldrh r1, [r0]
	subs r1, #0x24
	strh r1, [r0]
	ldr r0, _0800CC84 @ =gMain
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bl sub_CD18
	ldr r1, _0800CC78 @ =gUnknown_0202BF10
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x98
	ble _0800CC62
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800CC88 @ =gUnknown_0202A578
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0800CC8C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800CC62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CC68: .4byte gUnknown_0201A450
_0800CC6C: .4byte gUnknown_0202BEDC
_0800CC70: .4byte gUnknown_08115860
_0800CC74: .4byte 0x05000200
_0800CC78: .4byte gUnknown_0202BF10
_0800CC7C: .4byte gUnknown_0202A56C
_0800CC80: .4byte gUnknown_0202ADA0
_0800CC84: .4byte gMain
_0800CC88: .4byte gUnknown_0202A578
_0800CC8C: .4byte gUnknown_0202C790

	thumb_func_start nullsub_14
nullsub_14: @ 0x0800CC90
	bx lr

	thumb_func_start sub_CC94
sub_CC94: @ 0x0800CC94
	push {r4, r5, r6, lr}
	ldr r6, _0800CCE4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800CCCE
	ldr r1, _0800CCE8 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r4, _0800CCEC @ =gMPlayInfo_BGM
	ldr r5, _0800CCF0 @ =0x0000FFFF
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl __divsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl m4aMPlayVolumeControl
_0800CCCE:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0x2d
	ble _0800CCDE
	ldr r1, _0800CCF4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800CCE4: .4byte gUnknown_0202BF10
_0800CCE8: .4byte gUnknown_0202A578
_0800CCEC: .4byte gMPlayInfo_BGM
_0800CCF0: .4byte 0x0000FFFF
_0800CCF4: .4byte gUnknown_0202C790

	thumb_func_start sub_CCF8
sub_CCF8: @ 0x0800CCF8
	push {lr}
	bl sub_02B4
	bl m4aMPlayAllStop
	bl sub_0D10
	ldr r1, _0800CD14 @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD14: .4byte gMain

	thumb_func_start sub_CD18
sub_CD18: @ 0x0800CD18
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _0800CE28 @ =gUnknown_0201A450
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r0, #0xb8
	muls r1, r0, r1
	ldr r0, _0800CE2C @ =gUnknown_0200B3B8
	adds r6, r1, r0
	mov r8, r0
	movs r0, #0xc
	ldrsb r0, [r7, r0]
	strh r0, [r6]
	movs r0, #0x1c
	ldrsb r0, [r7, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r0, _0800CE30 @ =gUnknown_086A7D20
	movs r1, #0xb
	mov r2, r8
	bl LoadSpriteSets
	ldrh r0, [r6]
	cmp r0, #1
	bne _0800CDBA
	ldr r0, _0800CE34 @ =gUnknown_0202C5E4
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, _0800CE38 @ =gUnknown_0202ADD8
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #0
	bl SetMatrixScale
	ldrh r0, [r7]
	strh r0, [r6, #2]
	ldrh r0, [r7, #2]
	strh r0, [r6, #4]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0800CE3C @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0800CE40 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800CE44 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r1, #1]
	movs r2, #3
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r2, [r1, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #3]
_0800CDBA:
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800CE12
	ldrh r0, [r7, #0x10]
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	ldr r2, _0800CE3C @ =gOamBuffer
	mov sb, r2
	ldr r3, _0800CE44 @ =0xFFFFFE00
	mov ip, r3
	mov r4, r8
	adds r4, #8
	movs r5, #3
_0800CDD8:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800CE40 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800CDD8
_0800CE12:
	movs r0, #0
	strh r0, [r6]
	mov r1, r8
	strh r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800CE28: .4byte gUnknown_0201A450
_0800CE2C: .4byte gUnknown_0200B3B8
_0800CE30: .4byte gUnknown_086A7D20
_0800CE34: .4byte gUnknown_0202C5E4
_0800CE38: .4byte gUnknown_0202ADD8
_0800CE3C: .4byte gOamBuffer
_0800CE40: .4byte 0x000001FF
_0800CE44: .4byte 0xFFFFFE00
