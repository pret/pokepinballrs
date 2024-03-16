	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_C4F0
sub_C4F0: @ 0x0800C4F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, _0800C64C @ =gUnknown_0200B3B8
	mov r8, r0
	ldr r6, _0800C650 @ =gUnknown_0201A450
	movs r1, #0x28
	ldrsh r0, [r6, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r3, r0, #0
	muls r3, r2, r3
	movs r0, #0xb8
	lsls r0, r0, #1
	add r0, r8
	adds r3, r3, r0
	str r3, [sp]
	movs r7, #0x38
	ldrsh r0, [r6, r7]
	muls r0, r2, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	movs r1, #0xb8
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x58
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r2, r0
	adds r1, r2, #0
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	movs r1, #0x8a
	lsls r1, r1, #3
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	mov r2, r8
	strh r0, [r2]
	movs r0, #1
	ldr r7, _0800C654 @ =gUnknown_0200B470
	strh r0, [r7]
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r3]
	ldr r1, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x6c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r0, _0800C658 @ =gUnknown_086A7C24
	movs r1, #0x11
	bl LoadSpriteSets
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800C614
	ldrh r0, [r6]
	strh r0, [r1, #2]
	ldrh r0, [r6, #2]
	strh r0, [r1, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _0800C65C @ =gOamBuffer
	ldrh r1, [r1, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	mov r3, r8
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r7, #2
	ldrsh r1, [r5, r7]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _0800C660 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800C664 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r7, r8
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_0800C614:
	movs r5, #0
	str r6, [sp, #0x14]
_0800C618:
	lsls r1, r5, #2
	mov r2, sp
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	adds r4, r1, #0
	adds r3, r5, #1
	str r3, [sp, #0x18]
	cmp r0, #1
	beq _0800C62E
	b _0800C75A
_0800C62E:
	ldr r1, _0800C668 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0800C670
	lsls r1, r5, #3
	ldr r6, _0800C66C @ =gUnknown_086A7C68
	adds r0, r1, r6
	ldrb r2, [r0, #2]
	ldrb r0, [r0, #3]
	b _0800C67A
	.align 2, 0
_0800C64C: .4byte gUnknown_0200B3B8
_0800C650: .4byte gUnknown_0201A450
_0800C654: .4byte gUnknown_0200B470
_0800C658: .4byte gUnknown_086A7C24
_0800C65C: .4byte gOamBuffer
_0800C660: .4byte 0x000001FF
_0800C664: .4byte 0xFFFFFE00
_0800C668: .4byte gUnknown_0202A578
_0800C66C: .4byte gUnknown_086A7C68
_0800C670:
	lsls r1, r5, #3
	ldr r7, _0800C7F8 @ =gUnknown_086A7C68
	adds r0, r1, r7
	ldrb r2, [r0]
	ldrb r0, [r0, #1]
_0800C67A:
	adds r7, r1, #0
	adds r3, r5, #2
	lsls r1, r3, #4
	ldr r6, [sp, #0x14]
	adds r1, r1, r6
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldrh r6, [r1]
	adds r2, r2, r6
	strh r2, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r1, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	add r4, sp
	ldr r0, [r4]
	strh r2, [r0, #2]
	ldr r2, [r4]
	ldrh r0, [r1, #2]
	strh r0, [r2, #4]
	movs r0, #8
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #2
	adds r0, r5, r0
	lsls r0, r0, #2
	ldr r1, _0800C7FC @ =gUnknown_086A7C24
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r6, #0
	str r3, [sp, #0x1c]
	adds r5, #1
	str r5, [sp, #0x18]
	ldrh r2, [r0]
	cmp r6, r2
	bge _0800C732
	ldr r3, _0800C800 @ =gOamBuffer
	mov ip, r3
	ldr r0, _0800C7F8 @ =gUnknown_086A7C68
	adds r7, r7, r0
	mov sl, r7
	movs r7, #8
_0800C6D4:
	ldr r0, [r4]
	adds r5, r0, r7
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	mov r0, sl
	ldrb r1, [r0, #5]
	movs r3, #3
	ands r1, r3
	lsls r1, r1, #2
	ldrb r3, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #2
	ldrsh r1, [r5, r0]
	ldr r0, [r4]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _0800C804 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800C808 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, ip
	ldr r0, [r4]
	ldrb r0, [r0, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r7, #8
	adds r6, #1
	mov r0, sb
	ldrh r0, [r0]
	cmp r6, r0
	blt _0800C6D4
_0800C732:
	ldr r1, [sp, #0x1c]
	lsls r0, r1, #4
	ldr r2, [sp, #0x14]
	adds r3, r0, r2
	ldrh r0, [r3, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800C75A
	strh r1, [r3, #0xa]
	ldrh r1, [r3, #8]
	movs r6, #8
	ldrsh r0, [r3, r6]
	cmp r0, #1
	bgt _0800C75A
	adds r0, r1, #1
	strh r0, [r3, #8]
_0800C75A:
	ldr r5, [sp, #0x18]
	cmp r5, #4
	bgt _0800C762
	b _0800C618
_0800C762:
	ldr r7, _0800C80C @ =gUnknown_0200B470
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800C7C8
	ldr r0, _0800C810 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	strh r1, [r7, #2]
	ldrh r0, [r0, #0x12]
	strh r0, [r7, #4]
	ldr r5, _0800C800 @ =gOamBuffer
	ldr r0, _0800C808 @ =0xFFFFFE00
	mov sb, r0
	adds r4, r7, #0
	adds r4, #8
	movs r6, #3
_0800C780:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r7, _0800C80C @ =gUnknown_0200B470
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _0800C804 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, _0800C80C @ =gUnknown_0200B470
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _0800C780
_0800C7C8:
	movs r0, #0
	ldr r6, _0800C80C @ =gUnknown_0200B470
	strh r0, [r6]
	mov r7, r8
	strh r0, [r7]
	ldr r1, [sp]
	strh r0, [r1]
	ldr r1, [sp, #4]
	strh r0, [r1]
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	strh r0, [r1]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C7F8: .4byte gUnknown_086A7C68
_0800C7FC: .4byte gUnknown_086A7C24
_0800C800: .4byte gOamBuffer
_0800C804: .4byte 0x000001FF
_0800C808: .4byte 0xFFFFFE00
_0800C80C: .4byte gUnknown_0200B470
_0800C810: .4byte gUnknown_0201A450

	thumb_func_start sub_C814
sub_C814: @ 0x0800C814
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0518
	movs r0, #0
	str r0, [sp]
	ldr r1, _0800C924 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800C928 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0
	ldr r6, _0800C92C @ =gMain
	movs r1, #0xb8
	mov sb, r1
	movs r4, #0
	movs r3, #0xc0
	lsls r3, r3, #2
	mov r8, r3
	ldr r7, _0800C930 @ =0x00000302
	mov ip, r7
	movs r0, #0xc1
	lsls r0, r0, #2
	mov sl, r0
_0800C854:
	mov r2, sb
	muls r2, r5, r2
	adds r1, r2, r6
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r4, [r0]
	ldr r7, _0800C934 @ =0x000002FA
	adds r0, r1, r7
	strh r4, [r0]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r4, [r1]
	movs r3, #0
_0800C872:
	lsls r0, r3, #3
	adds r0, r0, r2
	adds r0, r0, r6
	mov r7, r8
	adds r1, r0, r7
	strh r4, [r1]
	mov r7, ip
	adds r1, r0, r7
	strh r4, [r1]
	add r0, sl
	strh r4, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x15
	bls _0800C872
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls _0800C854
	movs r5, #0
	mov sl, r5
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	mov sb, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	mov r8, r3
	movs r4, #0x3f
	ldr r6, _0800C938 @ =0xFFFFFE00
	adds r3, #0x12
_0800C8B8:
	lsls r2, r5, #3
	ldr r7, _0800C93C @ =gOamBuffer
	adds r2, r2, r7
	movs r0, #0xf4
	strb r0, [r2]
	movs r0, #0
	strb r0, [r2, #1]
	ldrh r1, [r2, #2]
	adds r0, r6, #0
	ands r0, r1
	movs r7, #0xfa
	lsls r7, r7, #1
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrb r1, [r2, #3]
	adds r0, r3, #0
	ands r0, r1
	mov r1, sb
	ands r0, r1
	mov r7, r8
	ands r0, r7
	ands r0, r4
	strb r0, [r2, #3]
	ldrh r1, [r2, #4]
	ldr r0, _0800C940 @ =0xFFFFFC00
	ands r0, r1
	strh r0, [r2, #4]
	ldrb r1, [r2, #5]
	mov r0, ip
	ands r0, r1
	movs r1, #0xf
	ands r0, r1
	strb r0, [r2, #5]
	mov r0, sl
	strh r0, [r2, #6]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls _0800C8B8
	ldr r1, _0800C944 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C924: .4byte 0x040000D4
_0800C928: .4byte 0x85000100
_0800C92C: .4byte gMain
_0800C930: .4byte 0x00000302
_0800C934: .4byte 0x000002FA
_0800C938: .4byte 0xFFFFFE00
_0800C93C: .4byte gOamBuffer
_0800C940: .4byte 0xFFFFFC00
_0800C944: .4byte gUnknown_0202C790

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
