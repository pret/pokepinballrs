	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_B0E8
sub_B0E8: @ 0x0800B0E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0800B2C0 @ =gMain
	ldrh r0, [r4, #0x38]
	movs r0, #0xf1
	lsls r0, r0, #4
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	ldr r0, _0800B2C4 @ =0x00000808
	strh r0, [r4, #0x3a]
	ldr r1, _0800B2C8 @ =0x04000050
	ldrh r0, [r4, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x3a]
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #2
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r8, r1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r2, r4
	mov sb, r2
	movs r0, #1
	mov r7, sl
	strh r0, [r7]
	strh r0, [r1]
	strh r0, [r2]
	ldr r0, _0800B2CC @ =gUnknown_086A79EC
	movs r1, #3
	mov r2, r8
	bl LoadSpriteSets
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800B1B8
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0]
	strh r1, [r7, #2]
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0xee
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r5, #3
_0800B15A:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	mov r0, ip
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, ip
	ands r0, r2
	movs r7, #4
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800B2D8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800B2DC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, sl
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B15A
_0800B1B8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800B234
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	strh r1, [r7, #2]
	ldrh r0, [r0, #0x12]
	strh r0, [r7, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	ldr r0, _0800B2DC @ =0xFFFFFE00
	mov ip, r0
	mov r4, r8
	adds r4, #8
	movs r5, #3
_0800B1D6:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r4, r2]
	mov r7, r8
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _0800B2D8 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B1D6
_0800B234:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800B2A2
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x20]
	mov r2, sb
	strh r1, [r2, #2]
	ldrh r0, [r0, #0x22]
	strh r0, [r2, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	movs r7, #0xd
	rsbs r7, r7, #0
	mov ip, r7
	mov r4, sb
	adds r4, #8
	movs r5, #7
_0800B256:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, ip
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800B2D8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800B2DC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, sb
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B256
_0800B2A2:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	mov r2, sb
	strh r0, [r2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B2C0: .4byte gMain
_0800B2C4: .4byte 0x00000808
_0800B2C8: .4byte 0x04000050
_0800B2CC: .4byte gUnknown_086A79EC
_0800B2D0: .4byte gUnknown_0201A450
_0800B2D4: .4byte gOamBuffer
_0800B2D8: .4byte 0x000001FF
_0800B2DC: .4byte 0xFFFFFE00

	thumb_func_start sub_B2E0
sub_B2E0: @ 0x0800B2E0
	push {lr}
	bl sub_0518
	ldr r1, _0800B2F4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800B2F4: .4byte gUnknown_0202C790

	thumb_func_start sub_B2F8
sub_B2F8: @ 0x0800B2F8
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800B428 @ =0x04000008
	movs r3, #0xf0
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B42C @ =0x0400000A
	ldr r3, _0800B430 @ =0x0000DA01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B434 @ =0x0400000C
	ldr r3, _0800B438 @ =0x00001E02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B43C @ =0x0400000E
	ldr r3, _0800B440 @ =0x00001F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800B444 @ =0x040000D4
	ldr r1, _0800B448 @ =gUnknown_080FD7C0
	str r1, [r0]
	ldr r1, _0800B44C @ =0x06007800
	str r1, [r0, #4]
	ldr r2, _0800B450 @ =0x80000400
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B454 @ =gUnknown_080FDFC0
	str r1, [r0]
	ldr r1, _0800B458 @ =0x0600D000
	str r1, [r0, #4]
	ldr r1, _0800B45C @ =0x80001000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B460 @ =gUnknown_080FCFC0
	str r1, [r0]
	ldr r1, _0800B464 @ =0x0600F000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B468 @ =gUnknown_080F63A0
	str r1, [r0]
	ldr r1, _0800B46C @ =0x0600F800
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B470 @ =gUnknown_080F6BA0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800B474 @ =0x80003200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r3, _0800B478 @ =gUnknown_080F61A0
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800B47C @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B480 @ =gUnknown_080FFFC0
	str r1, [r0]
	ldr r1, _0800B484 @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800B488 @ =0x80000800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0800B48C @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_B4A0
	ldr r1, _0800B490 @ =gMain
	ldr r2, _0800B494 @ =gUnknown_0202ADA0
	ldrh r3, [r2]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x18]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x1a]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x24]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r0, [r2, #0x26]
	ldr r2, _0800B498 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_0CBC
	bl sub_10424
	ldr r1, _0800B49C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B428: .4byte 0x04000008
_0800B42C: .4byte 0x0400000A
_0800B430: .4byte 0x0000DA01
_0800B434: .4byte 0x0400000C
_0800B438: .4byte 0x00001E02
_0800B43C: .4byte 0x0400000E
_0800B440: .4byte 0x00001F03
_0800B444: .4byte 0x040000D4
_0800B448: .4byte gUnknown_080FD7C0
_0800B44C: .4byte 0x06007800
_0800B450: .4byte 0x80000400
_0800B454: .4byte gUnknown_080FDFC0
_0800B458: .4byte 0x0600D000
_0800B45C: .4byte 0x80001000
_0800B460: .4byte gUnknown_080FCFC0
_0800B464: .4byte 0x0600F000
_0800B468: .4byte gUnknown_080F63A0
_0800B46C: .4byte 0x0600F800
_0800B470: .4byte gUnknown_080F6BA0
_0800B474: .4byte 0x80003200
_0800B478: .4byte gUnknown_080F61A0
_0800B47C: .4byte 0x80000040
_0800B480: .4byte gUnknown_080FFFC0
_0800B484: .4byte 0x06010000
_0800B488: .4byte 0x80000800
_0800B48C: .4byte 0x05000200
_0800B490: .4byte gMain
_0800B494: .4byte gUnknown_0202ADA0
_0800B498: .4byte 0x000002F6
_0800B49C: .4byte gUnknown_0202C790

	thumb_func_start sub_B4A0
sub_B4A0: @ 0x0800B4A0
	push {r4, r5, r6, r7, lr}
	ldr r1, _0800B540 @ =gUnknown_0202ADA0
	movs r3, #0
	movs r4, #0x1e
	strh r4, [r1, #0xc]
	ldr r0, _0800B544 @ =0x0000FF6A
	strh r0, [r1, #0xe]
	movs r0, #1
	strh r0, [r1, #0x14]
	ldr r0, _0800B548 @ =0x0000FFFE
	strh r0, [r1]
	subs r0, #3
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	movs r2, #8
	strh r2, [r1, #6]
	subs r0, #0x6b
	strh r0, [r1, #0x18]
	adds r0, #0x44
	strh r0, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r3, [r1, #0x1e]
	strh r3, [r1, #0x24]
	strh r3, [r1, #0x26]
	ldr r3, _0800B54C @ =gUnknown_0201A450
	movs r0, #0x32
	strh r0, [r3]
	movs r1, #0x3c
	strh r1, [r3, #2]
	movs r0, #0x50
	strh r0, [r3, #0x10]
	strh r1, [r3, #0x12]
	movs r0, #0x8c
	strh r0, [r3, #0x20]
	movs r2, #0x64
	strh r2, [r3, #0x22]
	movs r0, #0xc8
	strh r0, [r3, #0x30]
	movs r0, #0x5a
	strh r0, [r3, #0x32]
	adds r0, r3, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	movs r0, #0x96
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x52
	strh r2, [r0]
	ldr r5, _0800B550 @ =gUnknown_0202C548
	ldr r6, _0800B554 @ =gUnknown_0202BF10
	ldr r7, _0800B558 @ =gUnknown_0202A578
	ldr r0, _0800B55C @ =gUnknown_0202BEB4
	mov ip, r0
	movs r4, #0
	movs r2, #0
	adds r0, r3, #0
	adds r0, #8
	movs r1, #5
_0800B51C:
	strh r2, [r0]
	strh r2, [r0, #2]
	strb r4, [r0, #4]
	adds r0, #0x10
	subs r1, #1
	cmp r1, #0
	bge _0800B51C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0
	strh r0, [r6]
	strh r0, [r7]
	mov r1, ip
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B540: .4byte gUnknown_0202ADA0
_0800B544: .4byte 0x0000FF6A
_0800B548: .4byte 0x0000FFFE
_0800B54C: .4byte gUnknown_0201A450
_0800B550: .4byte gUnknown_0202C548
_0800B554: .4byte gUnknown_0202BF10
_0800B558: .4byte gUnknown_0202A578
_0800B55C: .4byte gUnknown_0202BEB4

	thumb_func_start sub_B560
sub_B560: @ 0x0800B560
	push {r4, r5, lr}
	ldr r2, _0800B694 @ =gUnknown_0202ADA0
	ldr r3, _0800B698 @ =gUnknown_086A7AC0
	ldr r1, _0800B69C @ =gUnknown_0202C548
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r2, #0xc]
	adds r0, r0, r4
	strh r0, [r2, #0xc]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r5, [r2, #0xe]
	adds r0, r0, r5
	strh r0, [r2, #0xe]
	ldr r3, _0800B6A0 @ =gUnknown_086A7AE4
	ldr r4, _0800B6A4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _0800B5C2
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #2]
	adds r1, r0, r2
	strh r1, [r5, #2]
	subs r0, #2
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B5C2
	movs r0, #8
	strh r0, [r5, #6]
_0800B5C2:
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B5EE
	ldrh r0, [r5, #0x1c]
	ldrh r2, [r5, #0x18]
	adds r1, r0, r2
	strh r1, [r5, #0x18]
	subs r0, #2
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B5EE
	movs r0, #8
	strh r0, [r5, #0x1c]
_0800B5EE:
	ldr r1, _0800B6A8 @ =gMain
	ldrh r2, [r5]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0xc]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0x18]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r5, #0x1a]
	ldr r5, _0800B6AC @ =0x000002F2
	adds r1, r1, r5
	strh r0, [r1]
	ldr r1, _0800B6B0 @ =gUnknown_086A7B34
	ldr r3, _0800B6B4 @ =gUnknown_0202BEB4
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r5, #0
	ldrsh r1, [r4, r5]
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0800B64C
	ldr r1, _0800B6B8 @ =gUnknown_0201A450
	lsls r0, r2, #4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0, #0xc]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0800B64C:
	bl sub_B7F8
	ldr r4, _0800B6BC @ =gUnknown_0202A578
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r2, _0800B698 @ =gUnknown_086A7AC0
	ldr r3, _0800B69C @ =gUnknown_0202C548
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1, #2]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	ble _0800B68C
	movs r0, #0
	strh r0, [r4]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble _0800B68C
	ldr r1, _0800B6C0 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800B68C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800B694: .4byte gUnknown_0202ADA0
_0800B698: .4byte gUnknown_086A7AC0
_0800B69C: .4byte gUnknown_0202C548
_0800B6A0: .4byte gUnknown_086A7AE4
_0800B6A4: .4byte gUnknown_0202BF10
_0800B6A8: .4byte gMain
_0800B6AC: .4byte 0x000002F2
_0800B6B0: .4byte gUnknown_086A7B34
_0800B6B4: .4byte gUnknown_0202BEB4
_0800B6B8: .4byte gUnknown_0201A450
_0800B6BC: .4byte gUnknown_0202A578
_0800B6C0: .4byte gUnknown_0202C790

	thumb_func_start sub_B6C4
sub_B6C4: @ 0x0800B6C4
	push {r4, r5, lr}
	ldr r2, _0800B784 @ =gUnknown_086A7AE4
	ldr r3, _0800B788 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	adds r4, r2, #0
	adds r2, r3, #0
	ldr r3, _0800B78C @ =gUnknown_0202ADA0
	cmp r0, #0
	beq _0800B6FC
	ldrh r0, [r3, #6]
	ldrh r5, [r3, #2]
	adds r1, r0, r5
	strh r1, [r3, #2]
	subs r0, #2
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B6FC
	movs r0, #8
	strh r0, [r3, #6]
_0800B6FC:
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B728
	ldrh r0, [r3, #0x1c]
	ldrh r2, [r3, #0x18]
	adds r1, r0, r2
	strh r1, [r3, #0x18]
	subs r0, #2
	strh r0, [r3, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B728
	movs r0, #8
	strh r0, [r3, #0x1c]
_0800B728:
	ldr r1, _0800B790 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	ldr r5, _0800B794 @ =0x000002EA
	adds r0, r1, r5
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #4
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #4
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x1a]
	adds r5, #4
	adds r1, r1, r5
	strh r0, [r1]
	bl sub_B7F8
	ldr r1, _0800B798 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _0800B77C
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800B79C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800B77C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800B784: .4byte gUnknown_086A7AE4
_0800B788: .4byte gUnknown_0202BF10
_0800B78C: .4byte gUnknown_0202ADA0
_0800B790: .4byte gMain
_0800B794: .4byte 0x000002EA
_0800B798: .4byte gUnknown_0202A578
_0800B79C: .4byte gUnknown_0202C790

	thumb_func_start sub_B7A0
sub_B7A0: @ 0x0800B7A0
	push {lr}
	sub sp, #8
	bl ClearSprites
	movs r2, #0
	str r2, [sp]
	ldr r1, _0800B7E4 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800B7E8 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, _0800B7EC @ =0x06010000
	str r0, [r1, #4]
	ldr r0, _0800B7F0 @ =0x81002800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_10480
	bl sub_10544
	ldr r1, _0800B7F4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800B7E4: .4byte 0x040000D4
_0800B7E8: .4byte 0x85000100
_0800B7EC: .4byte 0x06010000
_0800B7F0: .4byte 0x81002800
_0800B7F4: .4byte gUnknown_0202C790

	thumb_func_start sub_B7F8
sub_B7F8: @ 0x0800B7F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r6, _0800BA0C @ =gUnknown_0201A450
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r0
	lsls r2, r2, #4
	ldr r3, _0800BA10 @ =gUnknown_0200B3B8
	adds r2, r2, r3
	str r2, [sp]
	movs r4, #0x18
	ldrsh r1, [r6, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r3, #0
	adds r1, #0xb8
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x28
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xb8
	lsls r4, r4, #1
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #8]
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r4, #0xb8
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x48
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x58
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xe6
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0x14]
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	strh r0, [r2]
	ldr r1, [sp, #4]
	movs r0, #0x1c
	ldrsb r0, [r6, r0]
	strh r0, [r1]
	ldr r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x14]
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r4, _0800BA14 @ =gUnknown_086A7A78
	adds r0, r4, #0
	movs r1, #0x12
	adds r2, r3, #0
	bl LoadSpriteSets
	movs r5, #0
	str r6, [sp, #0x18]
_0800B8EC:
	lsls r0, r5, #2
	mov r6, sp
	adds r4, r6, r0
	ldr r1, [r4]
	ldrh r1, [r1]
	str r0, [sp, #0x20]
	adds r0, r5, #1
	str r0, [sp, #0x1c]
	cmp r1, #1
	bne _0800B9DA
	lsls r3, r5, #4
	ldr r1, [sp, #0x18]
	adds r2, r3, r1
	ldr r6, [sp, #0x20]
	ldr r1, _0800BA18 @ =gUnknown_086A7B34
	adds r0, r6, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r6, [r2]
	adds r1, r1, r6
	strh r1, [r2]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldr r0, [r4]
	strh r1, [r0, #2]
	ldr r1, [r4]
	ldrh r0, [r2, #2]
	strh r0, [r1, #4]
	movs r0, #8
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	ldr r1, _0800BA14 @ =gUnknown_086A7A78
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r7, #0
	mov sb, r3
	ldrh r2, [r0]
	cmp r7, r2
	bge _0800B998
	adds r5, r4, #0
	ldr r3, _0800BA1C @ =gOamBuffer
	mov ip, r3
	ldr r4, _0800BA20 @ =0xFFFFFE00
	mov sl, r4
	movs r6, #8
_0800B958:
	ldr r0, [r5]
	adds r4, r0, r6
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r4, r3]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _0800BA24 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r6, #8
	adds r7, #1
	mov r4, r8
	ldrh r4, [r4]
	cmp r7, r4
	blt _0800B958
_0800B998:
	ldr r1, [sp, #0x18]
	add r1, sb
	ldrh r0, [r1, #0xa]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800B9BC
	strh r2, [r1, #0xa]
	ldrh r2, [r1, #8]
	movs r6, #8
	ldrsh r0, [r1, r6]
	cmp r0, #1
	bgt _0800B9BC
	adds r0, r2, #1
	strh r0, [r1, #8]
_0800B9BC:
	ldr r1, [sp, #0x20]
	ldr r2, _0800BA18 @ =gUnknown_086A7B34
	adds r0, r1, r2
	ldr r3, _0800BA28 @ =gUnknown_0202BF10
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0800B9DA
	ldr r1, [sp, #0x18]
	add r1, sb
	movs r0, #0
	strb r0, [r1, #0xc]
_0800B9DA:
	ldr r5, [sp, #0x1c]
	cmp r5, #5
	ble _0800B8EC
	ldr r0, [sp]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [sp, #4]
	strh r1, [r0]
	ldr r0, [sp, #8]
	strh r1, [r0]
	ldr r0, [sp, #0xc]
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	strh r1, [r0]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BA0C: .4byte gUnknown_0201A450
_0800BA10: .4byte gUnknown_0200B3B8
_0800BA14: .4byte gUnknown_086A7A78
_0800BA18: .4byte gUnknown_086A7B34
_0800BA1C: .4byte gOamBuffer
_0800BA20: .4byte 0xFFFFFE00
_0800BA24: .4byte 0x000001FF
_0800BA28: .4byte gUnknown_0202BF10

	thumb_func_start sub_BA2C
sub_BA2C: @ 0x0800BA2C
	ldr r1, _0800BA38 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800BA38: .4byte gUnknown_0202C790

	thumb_func_start sub_BA3C
sub_BA3C: @ 0x0800BA3C
	push {r4, r5, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800BB6C @ =0x04000008
	movs r3, #0xd4
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB70 @ =0x0400000A
	ldr r3, _0800BB74 @ =0x0000D801
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB78 @ =0x0400000C
	ldr r3, _0800BB7C @ =0x0000DC02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB80 @ =0x0400000E
	ldr r3, _0800BB84 @ =0x00000F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800BB88 @ =0x040000D4
	ldr r1, _0800BB8C @ =gUnknown_08108A00
	str r1, [r0]
	ldr r1, _0800BB90 @ =0x0600A000
	str r1, [r0, #4]
	ldr r3, _0800BB94 @ =0x80001000
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BB98 @ =gUnknown_0810AA00
	str r1, [r0]
	ldr r1, _0800BB9C @ =0x0600C000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBA0 @ =gUnknown_08106A00
	str r1, [r0]
	ldr r1, _0800BBA4 @ =0x0600E000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBA8 @ =gUnknown_081011E0
	str r1, [r0]
	ldr r1, _0800BBAC @ =0x06007800
	str r1, [r0, #4]
	ldr r1, _0800BBB0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBB4 @ =gUnknown_081019E0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800BBB8 @ =0x80002800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r5, _0800BBBC @ =gUnknown_08100FE0
	str r5, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r4, _0800BBC0 @ =0x800000B0
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBC4 @ =gUnknown_0810CA00
	str r1, [r0]
	ldr r1, _0800BBC8 @ =0x06010000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r5, [r0]
	ldr r1, _0800BBCC @ =0x05000200
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0800BBD0 @ =gMain
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	bl sub_BBE0
	ldr r1, _0800BBD4 @ =gUnknown_0202ADA0
	ldrh r2, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #2]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0xc]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0xe]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x18]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x1a]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x24]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r0, [r1, #0x26]
	ldr r1, _0800BBD8 @ =0x000002F6
	adds r4, r4, r1
	strh r0, [r4]
	bl sub_0CBC
	bl sub_10424
	ldr r1, _0800BBDC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800BB6C: .4byte 0x04000008
_0800BB70: .4byte 0x0400000A
_0800BB74: .4byte 0x0000D801
_0800BB78: .4byte 0x0400000C
_0800BB7C: .4byte 0x0000DC02
_0800BB80: .4byte 0x0400000E
_0800BB84: .4byte 0x00000F03
_0800BB88: .4byte 0x040000D4
_0800BB8C: .4byte gUnknown_08108A00
_0800BB90: .4byte 0x0600A000
_0800BB94: .4byte 0x80001000
_0800BB98: .4byte gUnknown_0810AA00
_0800BB9C: .4byte 0x0600C000
_0800BBA0: .4byte gUnknown_08106A00
_0800BBA4: .4byte 0x0600E000
_0800BBA8: .4byte gUnknown_081011E0
_0800BBAC: .4byte 0x06007800
_0800BBB0: .4byte 0x80000400
_0800BBB4: .4byte gUnknown_081019E0
_0800BBB8: .4byte 0x80002800
_0800BBBC: .4byte gUnknown_08100FE0
_0800BBC0: .4byte 0x800000B0
_0800BBC4: .4byte gUnknown_0810CA00
_0800BBC8: .4byte 0x06010000
_0800BBCC: .4byte 0x05000200
_0800BBD0: .4byte gMain
_0800BBD4: .4byte gUnknown_0202ADA0
_0800BBD8: .4byte 0x000002F6
_0800BBDC: .4byte gUnknown_0202C790

	thumb_func_start sub_BBE0
sub_BBE0: @ 0x0800BBE0
	ldr r1, _0800BC30 @ =gUnknown_0202ADA0
	movs r2, #0
	ldr r0, _0800BC34 @ =0x0000FEFC
	strh r0, [r1]
	movs r0, #0x46
	strh r0, [r1, #2]
	strh r2, [r1, #6]
	ldr r0, _0800BC38 @ =0x0000FEE8
	strh r0, [r1, #0xc]
	movs r0, #0x5a
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x12]
	ldr r0, _0800BC3C @ =0x0000FF10
	strh r0, [r1, #0x18]
	adds r0, #0xbe
	strh r0, [r1, #0x1a]
	adds r0, #0x2f
	strh r0, [r1, #0x1e]
	strh r2, [r1, #0x24]
	strh r2, [r1, #0x26]
	ldr r1, _0800BC40 @ =gUnknown_0201A450
	movs r0, #0x94
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x2c
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	ldr r0, _0800BC44 @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _0800BC48 @ =gUnknown_0202A578
	strh r2, [r0]
	ldr r0, _0800BC4C @ =gUnknown_0202C5E4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0800BC50 @ =gUnknown_0202ADD8
	strh r1, [r0]
	bx lr
	.align 2, 0
_0800BC30: .4byte gUnknown_0202ADA0
_0800BC34: .4byte 0x0000FEFC
_0800BC38: .4byte 0x0000FEE8
_0800BC3C: .4byte 0x0000FF10
_0800BC40: .4byte gUnknown_0201A450
_0800BC44: .4byte gUnknown_0202BF10
_0800BC48: .4byte gUnknown_0202A578
_0800BC4C: .4byte gUnknown_0202C5E4
_0800BC50: .4byte gUnknown_0202ADD8

	thumb_func_start sub_BC54
sub_BC54: @ 0x0800BC54
	push {r4, r5, r6, lr}
	ldr r4, _0800BCD0 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BCD4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BC88
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BC88
	ldr r0, _0800BCD8 @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BC88:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BCDC @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BCE0 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x20
	ble _0800BCC8
	ldr r1, _0800BCE4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BCC8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BCD0: .4byte gUnknown_0202ADA0
_0800BCD4: .4byte gUnknown_0202BF10
_0800BCD8: .4byte 0x0000FFFD
_0800BCDC: .4byte gMain
_0800BCE0: .4byte 0x000002F6
_0800BCE4: .4byte gUnknown_0202C790

	thumb_func_start sub_BCE8
sub_BCE8: @ 0x0800BCE8
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BDA4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BDA8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BD1E
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BD1E
	ldr r0, _0800BDAC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BD1E:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BD4C
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BD4C
	ldr r0, _0800BDB0 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BD4C:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BDB4 @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BDB8 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r0, #0x50
	ble _0800BD9C
	ldr r1, _0800BDBC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BD9C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BDA4: .4byte gUnknown_0202ADA0
_0800BDA8: .4byte gUnknown_0202BF10
_0800BDAC: .4byte 0x0000FFFD
_0800BDB0: .4byte 0x0000FFFA
_0800BDB4: .4byte gMain
_0800BDB8: .4byte 0x000002F6
_0800BDBC: .4byte gUnknown_0202C790

	thumb_func_start sub_BDC0
sub_BDC0: @ 0x0800BDC0
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BEB4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BEB8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BDF6
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BDF6
	ldr r0, _0800BEBC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BDF6:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BE24
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BE24
	ldr r0, _0800BEC0 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BE24:
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r4, #6]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BE4C
	adds r0, r2, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BE4C
	ldr r0, _0800BEBC @ =0x0000FFFD
	strh r0, [r4, #6]
_0800BE4C:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BEC4 @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #0xa
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BEC8 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r0, #0x64
	ble _0800BEAC
	ldr r1, _0800BECC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BEAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BEB4: .4byte gUnknown_0202ADA0
_0800BEB8: .4byte gUnknown_0202BF10
_0800BEBC: .4byte 0x0000FFFD
_0800BEC0: .4byte 0x0000FFFA
_0800BEC4: .4byte gMain
_0800BEC8: .4byte 0x000002F6
_0800BECC: .4byte gUnknown_0202C790

	thumb_func_start sub_BED0
sub_BED0: @ 0x0800BED0
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BFF4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BFF8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BF06
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BF06
	ldr r0, _0800BFFC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BF06:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BF34
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BF34
	ldr r0, _0800C000 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BF34:
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r4, #6]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BF5C
	adds r0, r2, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BF5C
	ldr r0, _0800BFFC @ =0x0000FFFD
	strh r0, [r4, #6]
_0800BF5C:
	ldr r2, _0800C004 @ =gUnknown_0201A450
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	ldrh r3, [r2, #6]
	ldrh r1, [r2, #2]
	adds r0, r3, r1
	strh r0, [r2, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BF86
	adds r0, r3, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BF86
	ldr r0, _0800C008 @ =0x0000FFFC
	strh r0, [r2, #6]
_0800BF86:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800C00C @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #0xa
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800C010 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_C0D8
	ldr r0, _0800BFF8 @ =gUnknown_0202BF10
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xc0
	ble _0800BFEC
	ldr r1, _0800C014 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BFEC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BFF4: .4byte gUnknown_0202ADA0
_0800BFF8: .4byte gUnknown_0202BF10
_0800BFFC: .4byte 0x0000FFFD
_0800C000: .4byte 0x0000FFFA
_0800C004: .4byte gUnknown_0201A450
_0800C008: .4byte 0x0000FFFC
_0800C00C: .4byte gMain
_0800C010: .4byte 0x000002F6
_0800C014: .4byte gUnknown_0202C790

	thumb_func_start sub_C018
sub_C018: @ 0x0800C018
	push {r4, r5, lr}
	ldr r4, _0800C044 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r5, _0800C048 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0800C050
	ldr r1, _0800C04C @ =gUnknown_0201A450
	ldrh r0, [r1]
	subs r0, #3
	b _0800C05A
	.align 2, 0
_0800C044: .4byte gUnknown_0202ADA0
_0800C048: .4byte gUnknown_0202BF10
_0800C04C: .4byte gUnknown_0201A450
_0800C050:
	cmp r0, #3
	bne _0800C05C
	ldr r1, _0800C0A4 @ =gUnknown_0201A450
	ldrh r0, [r1]
	adds r0, #3
_0800C05A:
	strh r0, [r1]
_0800C05C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0xca
	ble _0800C074
	ldr r1, _0800C0A8 @ =gUnknown_0202C5E4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, _0800C0AC @ =gUnknown_0202ADD8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0800C074:
	ldr r1, _0800C0B0 @ =gMain
	ldrh r2, [r4, #0x24]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800C0B4 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_C0D8
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0xde
	ble _0800C09C
	ldr r1, _0800C0B8 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C09C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800C0A4: .4byte gUnknown_0201A450
_0800C0A8: .4byte gUnknown_0202C5E4
_0800C0AC: .4byte gUnknown_0202ADD8
_0800C0B0: .4byte gMain
_0800C0B4: .4byte 0x000002F6
_0800C0B8: .4byte gUnknown_0202C790

	thumb_func_start sub_C0BC
sub_C0BC: @ 0x0800C0BC
	push {lr}
	bl sub_10480
	bl sub_10544
	ldr r1, _0800C0D4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800C0D4: .4byte gUnknown_0202C790

	thumb_func_start sub_C0D8
sub_C0D8: @ 0x0800C0D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0800C1EC @ =gUnknown_0200B3B8
	mov r8, r0
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	ldr r0, _0800C1F0 @ =gUnknown_086A7B74
	movs r1, #1
	mov r2, r8
	bl LoadSpriteSets
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, #1
	bne _0800C1D4
	ldr r5, _0800C1F4 @ =gUnknown_0202C5E4
	movs r3, #0
	ldrsh r0, [r5, r3]
	ldr r4, _0800C1F8 @ =gUnknown_0202ADD8
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r2, #0
	bl SetMatrixScale
	ldr r1, _0800C1FC @ =gUnknown_0201A450
	ldrh r0, [r1]
	mov r3, r8
	strh r0, [r3, #2]
	ldrh r0, [r1, #2]
	strh r0, [r3, #4]
	movs r7, #0
	ldr r6, _0800C200 @ =gOamBuffer
	mov sl, r4
	mov r5, r8
	adds r5, #8
	ldr r4, _0800C204 @ =0xFFFFFE00
	mov sb, r4
	movs r0, #4
	rsbs r0, r0, #0
	mov ip, r0
_0800C132:
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r3, r0, r6
	lsls r0, r7, #2
	ldr r1, _0800C208 @ =gUnknown_086A7B7C
	adds r4, r0, r1
	movs r0, #0
	ldrsh r2, [r4, r0]
	str r2, [sp]
	ldr r1, _0800C1F4 @ =gUnknown_0202C5E4
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r2, [sp]
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _0800C16A
	adds r1, #0xff
_0800C16A:
	asrs r1, r1, #8
	str r1, [sp]
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [sp]
	adds r1, r2, r0
	ldr r2, _0800C20C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r6
	movs r3, #2
	ldrsh r1, [r4, r3]
	mov r4, sl
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r1, r0
	cmp r0, #0
	bge _0800C1A0
	adds r0, #0xff
_0800C1A0:
	asrs r0, r0, #8
	mov r4, r8
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	mov r0, ip
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #3]
	adds r5, #8
	adds r7, #1
	cmp r7, #3
	ble _0800C132
_0800C1D4:
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C1EC: .4byte gUnknown_0200B3B8
_0800C1F0: .4byte gUnknown_086A7B74
_0800C1F4: .4byte gUnknown_0202C5E4
_0800C1F8: .4byte gUnknown_0202ADD8
_0800C1FC: .4byte gUnknown_0201A450
_0800C200: .4byte gOamBuffer
_0800C204: .4byte 0xFFFFFE00
_0800C208: .4byte gUnknown_086A7B7C
_0800C20C: .4byte 0x000001FF

	thumb_func_start sub_C210
sub_C210: @ 0x0800C210
	push {lr}
	bl sub_0518
	ldr r1, _0800C224 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800C224: .4byte gUnknown_0202C790

	thumb_func_start sub_C228
sub_C228: @ 0x0800C228
	push {r4, lr}
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r3]
	ldr r1, _0800C2B4 @ =0x0400000C
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0800C2B8 @ =0x040000D4
	ldr r1, _0800C2BC @ =gUnknown_0810EC20
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800C2C0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C2C4 @ =gUnknown_0810F420
	str r1, [r0]
	ldr r1, _0800C2C8 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _0800C2CC @ =0x80001A00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r4, _0800C2D0 @ =gUnknown_0810EA20
	str r4, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800C2D4 @ =0x800000A0
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C2D8 @ =gUnknown_08112840
	str r1, [r0]
	ldr r1, _0800C2DC @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800C2E0 @ =0x80001600
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [r0]
	ldr r1, _0800C2E4 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _0800C2E8 @ =gMain
	ldrh r0, [r3]
	strh r0, [r1, #0x16]
	bl sub_C2F0
	bl sub_C4F0
	bl sub_0CBC
	bl sub_10424
	ldr r1, _0800C2EC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C2B4: .4byte 0x0400000C
_0800C2B8: .4byte 0x040000D4
_0800C2BC: .4byte gUnknown_0810EC20
_0800C2C0: .4byte 0x80000400
_0800C2C4: .4byte gUnknown_0810F420
_0800C2C8: .4byte 0x06004000
_0800C2CC: .4byte 0x80001A00
_0800C2D0: .4byte gUnknown_0810EA20
_0800C2D4: .4byte 0x800000A0
_0800C2D8: .4byte gUnknown_08112840
_0800C2DC: .4byte 0x06010000
_0800C2E0: .4byte 0x80001600
_0800C2E4: .4byte 0x05000200
_0800C2E8: .4byte gMain
_0800C2EC: .4byte gUnknown_0202C790

	thumb_func_start sub_C2F0
sub_C2F0: @ 0x0800C2F0
	push {r4, r5, r6, lr}
	ldr r0, _0800C380 @ =gUnknown_0201A450
	mov ip, r0
	movs r4, #0
	movs r1, #0
	movs r5, #0x78
	strh r5, [r0, #0x10]
	movs r2, #0x50
	strh r2, [r0, #0x12]
	movs r0, #4
	mov r3, ip
	strh r0, [r3, #0x14]
	strh r0, [r3, #0x16]
	strh r1, [r3, #0x18]
	strh r5, [r3]
	strh r2, [r3, #2]
	strb r4, [r3, #0xc]
	movs r2, #0x80
	strh r2, [r3, #0x20]
	movs r3, #0x58
	mov r0, ip
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x28]
	strh r1, [r0, #0x2a]
	adds r0, #0x2c
	strb r4, [r0]
	mov r0, ip
	strh r2, [r0, #0x30]
	movs r6, #0x48
	strh r6, [r0, #0x32]
	strh r1, [r0, #0x38]
	strh r1, [r0, #0x3a]
	adds r0, #0x3c
	strb r4, [r0]
	adds r0, #4
	movs r2, #0x70
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	adds r0, #4
	strh r5, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	adds r0, #4
	strh r2, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	ldr r0, _0800C384 @ =gUnknown_0202BF10
	strh r1, [r0]
	ldr r0, _0800C388 @ =gUnknown_0202A578
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800C380: .4byte gUnknown_0201A450
_0800C384: .4byte gUnknown_0202BF10
_0800C388: .4byte gUnknown_0202A578

	thumb_func_start sub_C38C
sub_C38C: @ 0x0800C38C
	push {lr}
	bl sub_C4F0
	ldr r0, _0800C3C4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	ble _0800C3C0
	ldr r2, _0800C3C8 @ =gUnknown_0201A450
	movs r1, #1
	strb r1, [r2, #0xc]
	adds r0, r2, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	ldr r1, _0800C3CC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C3C0:
	pop {r0}
	bx r0
	.align 2, 0
_0800C3C4: .4byte gUnknown_0202BF10
_0800C3C8: .4byte gUnknown_0201A450
_0800C3CC: .4byte gUnknown_0202C790

	thumb_func_start sub_C3D0
sub_C3D0: @ 0x0800C3D0
	push {r4, lr}
	ldr r3, _0800C408 @ =gUnknown_0201A450
	ldrh r0, [r3]
	subs r0, #9
	strh r0, [r3]
	ldrh r0, [r3, #2]
	subs r0, #6
	strh r0, [r3, #2]
	ldrh r0, [r3, #0x18]
	adds r0, #1
	strh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _0800C40C
	ldrh r2, [r3, #0x14]
	ldrh r1, [r3, #0x10]
	adds r0, r2, r1
	strh r0, [r3, #0x10]
	ldrh r1, [r3, #0x16]
	ldrh r4, [r3, #0x12]
	adds r0, r1, r4
	strh r0, [r3, #0x12]
	subs r2, #1
	strh r2, [r3, #0x14]
	subs r1, #1
	strh r1, [r3, #0x16]
	b _0800C424
	.align 2, 0
_0800C408: .4byte gUnknown_0201A450
_0800C40C:
	ldr r0, _0800C444 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800C424
	ldrh r0, [r3, #0x10]
	adds r0, #1
	strh r0, [r3, #0x10]
	ldrh r0, [r3, #0x12]
	adds r0, #1
	strh r0, [r3, #0x12]
_0800C424:
	bl sub_C4F0
	ldr r0, _0800C448 @ =gUnknown_0201A450
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800C43E
	ldr r1, _0800C44C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C43E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C444: .4byte gUnknown_0202BF10
_0800C448: .4byte gUnknown_0201A450
_0800C44C: .4byte gUnknown_0202C790

	thumb_func_start sub_C450
sub_C450: @ 0x0800C450
	push {lr}
	bl sub_C4F0
	ldr r2, _0800C484 @ =gUnknown_0202BF10
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800C470
	ldr r0, _0800C488 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	adds r1, #1
	strh r1, [r0, #0x10]
	ldrh r1, [r0, #0x12]
	adds r1, #1
	strh r1, [r0, #0x12]
_0800C470:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x14
	ble _0800C480
	ldr r1, _0800C48C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
_0800C480:
	pop {r0}
	bx r0
	.align 2, 0
_0800C484: .4byte gUnknown_0202BF10
_0800C488: .4byte gUnknown_0201A450
_0800C48C: .4byte gUnknown_0202C790

	thumb_func_start nullsub_12
nullsub_12: @ 0x0800C490
	bx lr

	thumb_func_start nullsub_13
nullsub_13: @ 0x0800C494
	bx lr

	thumb_func_start sub_C498
sub_C498: @ 0x0800C498
	push {lr}
	sub sp, #8
	bl sub_10480
	bl ClearSprites
	movs r2, #0
	str r2, [sp]
	ldr r1, _0800C4DC @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800C4E0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, _0800C4E4 @ =0x06010000
	str r0, [r1, #4]
	ldr r0, _0800C4E8 @ =0x81002800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_10544
	ldr r1, _0800C4EC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800C4DC: .4byte 0x040000D4
_0800C4E0: .4byte 0x85000100
_0800C4E4: .4byte 0x06010000
_0800C4E8: .4byte 0x81002800
_0800C4EC: .4byte gUnknown_0202C790

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
