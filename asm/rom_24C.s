	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_24C
sub_24C: @ 0x0800024C
	push {r4, r5, r6, lr}
	ldr r3, _080002A4 @ =0x04000050
	movs r0, #0
	strh r0, [r3]
	ldr r4, _080002A8 @ =0x04000054
	movs r0, #0x10
	strh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r3]
	ldrh r1, [r2]
	ldr r0, _080002AC @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080002B0 @ =0x0200B0C0
	ldrh r0, [r2]
	strh r0, [r1, #0x16]
	movs r5, #0
	adds r6, r4, #0
	movs r4, #0xf
_08000282:
	lsrs r0, r5, #1
	subs r0, r4, r0
	strh r0, [r6]
	bl sub_D74
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x1f
	bls _08000282
	ldr r1, _080002A4 @ =0x04000050
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080002A4: .4byte 0x04000050
_080002A8: .4byte 0x04000054
_080002AC: .4byte 0x0000FF7F
_080002B0: .4byte 0x0200B0C0

	thumb_func_start sub_2B4
sub_2B4: @ 0x080002B4
	push {r4, r5, lr}
	sub sp, #4
	ldr r3, _08000344 @ =0x04000050
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08000348 @ =0x04000054
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r3]
	movs r4, #0
	adds r5, r2, #0
_080002DA:
	adds r4, #1
	strh r4, [r5]
	bl sub_D74
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0xf
	bls _080002DA
	ldr r1, _0800034C @ =0x0200B0C0
	ldrh r0, [r1, #0x16]
	movs r3, #0x80
	movs r2, #0
	orrs r0, r3
	strh r0, [r1, #0x16]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	mov r0, sp
	strh r2, [r0]
	adds r1, #0xd4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000350 @ =0x8100C000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08000354 @ =0x04000010
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #0x32
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08000344: .4byte 0x04000050
_08000348: .4byte 0x04000054
_0800034C: .4byte 0x0200B0C0
_08000350: .4byte 0x8100C000
_08000354: .4byte 0x04000010

	thumb_func_start sub_358
sub_358: @ 0x08000358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	str r2, [sp, #8]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r4, _08000424 @ =0x03005000
	movs r7, #0
	ldr r2, _08000428 @ =0x040000D4
	ldr r0, _0800042C @ =0x08057C46
	str r0, [r2]
	str r4, [r2, #4]
	ldr r0, _08000430 @ =0x80000200
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r7, r0
	bhs _0800040E
	mov ip, r2
_0800038A:
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, [sp, #8]
	adds r6, r2, r0
	ldrh r0, [r6]
	adds r2, r1, #1
	str r2, [sp, #0xc]
	cmp r0, #0
	beq _08000402
	lsls r0, r1, #2
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r5, [r0]
	adds r0, #2
	mov r2, ip
	str r0, [r2]
	lsls r0, r7, #3
	ldr r1, _08000424 @ =0x03005000
	adds r0, r0, r1
	str r0, [r2, #4]
	lsls r0, r5, #2
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r3, #0
	cmp r3, r5
	bhs _08000402
	ldr r2, _08000424 @ =0x03005000
	mov sb, r2
	ldr r0, _08000434 @ =0x000001FF
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
_080003D2:
	adds r2, r7, #0
	lsls r0, r2, #3
	mov r1, sb
	adds r4, r0, r1
	lsls r1, r3, #3
	adds r1, #8
	adds r1, r6, r1
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	strh r2, [r1]
	ldrh r2, [r4, #2]
	mov r0, sl
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r2, [r4]
	mov r0, r8
	ands r0, r2
	strh r0, [r1, #4]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	blo _080003D2
_08000402:
	ldr r2, [sp, #0xc]
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	ldr r0, [sp, #4]
	cmp r1, r0
	blo _0800038A
_0800040E:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08000424: .4byte 0x03005000
_08000428: .4byte 0x040000D4
_0800042C: .4byte 0x08057C46
_08000430: .4byte 0x80000200
_08000434: .4byte 0x000001FF

	thumb_func_start sub_438
sub_438: @ 0x08000438
	push {r4, r5, r6, lr}
	ldr r4, _0800048C @ =0x0200B0C0
	ldrh r0, [r4, #0x16]
	movs r2, #0x80
	movs r6, #0
	movs r5, #0
	orrs r0, r2
	strh r0, [r4, #0x16]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	bl sub_490
	bl sub_518
	bl sub_578
	strb r6, [r4, #0xf]
	strb r6, [r4, #0x10]
	str r5, [r4, #0x50]
	strb r6, [r4, #0x11]
	strh r5, [r4, #0x12]
	strh r5, [r4, #0x14]
	movs r0, #0x90
	strh r0, [r4, #0x26]
	strh r5, [r4, #0x28]
	strh r5, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x36
	strb r6, [r0]
	ldrh r0, [r4, #0x38]
	strh r5, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	strh r5, [r4, #0x3a]
	ldrh r0, [r4, #0x3c]
	strh r5, [r4, #0x3c]
	strh r5, [r4, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800048C: .4byte 0x0200B0C0

	thumb_func_start sub_490
sub_490: @ 0x08000490
	sub sp, #8
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08000504 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000508 @ =0x8100C000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	str r2, [sp, #4]
	add r0, sp, #4
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800050C @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, sp
	strh r2, [r0]
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000510 @ =0x81000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08000514 @ =0x04000010
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #0x32
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	subs r0, #0x50
	strh r2, [r0]
	adds r0, #0x4e
	strh r2, [r0]
	add sp, #8
	bx lr
	.align 2, 0
_08000504: .4byte 0x040000D4
_08000508: .4byte 0x8100C000
_0800050C: .4byte 0x85000100
_08000510: .4byte 0x81000200
_08000514: .4byte 0x04000010

	thumb_func_start sub_518
sub_518: @ 0x08000518
	push {r4, r5, r6, lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08000564 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08000568 @ =0x03005C00
	str r0, [r1, #4]
	ldr r0, _0800056C @ =0x81000600
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0
	ldr r6, _08000570 @ =0x0200B0C0
	movs r5, #0xba
	lsls r5, r5, #2
	movs r3, #0
	ldr r4, _08000574 @ =0x000002EA
_0800053E:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r6
	adds r2, r1, r5
	strh r3, [r2]
	adds r1, r1, r4
	strh r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0800053E
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08000564: .4byte 0x040000D4
_08000568: .4byte 0x03005C00
_0800056C: .4byte 0x81000600
_08000570: .4byte 0x0200B0C0
_08000574: .4byte 0x000002EA

	thumb_func_start sub_578
sub_578: @ 0x08000578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r6, _08000660 @ =0x0200B0C0
	movs r0, #0xb8
	mov sb, r0
	movs r4, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	mov r8, r1
	ldr r3, _08000664 @ =0x00000302
	mov ip, r3
	movs r7, #0xc1
	lsls r7, r7, #2
	mov sl, r7
_0800059C:
	mov r2, sb
	muls r2, r5, r2
	adds r1, r2, r6
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r4, [r0]
	ldr r7, _08000668 @ =0x000002FA
	adds r0, r1, r7
	strh r4, [r0]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r4, [r1]
	movs r3, #0
_080005BA:
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
	bls _080005BA
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x63
	bls _0800059C
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
	ldr r6, _0800066C @ =0xFFFFFE00
	adds r3, #0x12
_08000600:
	lsls r2, r5, #3
	ldr r7, _08000670 @ =0x03005000
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
	ldr r0, _08000674 @ =0xFFFFFC00
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
	cmp r5, #0x7f
	bls _08000600
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08000660: .4byte 0x0200B0C0
_08000664: .4byte 0x00000302
_08000668: .4byte 0x000002FA
_0800066C: .4byte 0xFFFFFE00
_08000670: .4byte 0x03005000
_08000674: .4byte 0xFFFFFC00

	thumb_func_start sub_678
sub_678: @ 0x08000678
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	bl sub_55A24
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0xb
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r4, r4, r5
	lsls r4, r4, #1
	ldr r0, _080006C4 @ =0x03005C00
	adds r4, r4, r0
_080006A2:
	ldrb r0, [r6]
	subs r0, #0x20
	strh r0, [r4]
	adds r6, #1
	adds r4, #2
	adds r1, r2, #0
	lsls r0, r1, #0x10
	ldr r2, _080006C8 @ =0xFFFF0000
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _080006A2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080006C4: .4byte 0x03005C00
_080006C8: .4byte 0xFFFF0000

	thumb_func_start sub_6CC
sub_6CC: @ 0x080006CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	cmp r6, #0
	bge _080006E8
	movs r0, #0x2d
	strb r0, [r5]
	adds r5, #1
	rsbs r6, r6, #0
_080006E8:
	lsls r7, r3, #0x10
	movs r0, #0x30
	mov r8, r0
_080006EE:
	cmp r4, #1
	ble _08000708
	subs r4, #1
	movs r0, #0xa
	adds r1, r4, #0
	bl sub_780
	cmp r6, r0
	bge _08000708
	mov r0, r8
	strb r0, [r5]
	adds r5, #1
	b _080006EE
_08000708:
	asrs r4, r7, #0x10
	cmp r4, #0
	beq _0800071A
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	bl sub_734
	b _08000726
_0800071A:
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	bl sub_734
	strb r4, [r0]
_08000726:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_734
sub_734: @ 0x08000734
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r1, r6, #0
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r5
	adds r0, r4, #0
	adds r1, r6, #0
	bl __udivsi3
	cmp r0, #0
	beq _08000762
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_734
	adds r7, r0, #0
_08000762:
	cmp r5, #9
	bhi _0800076C
	adds r0, r5, #0
	adds r0, #0x30
	b _08000770
_0800076C:
	mov r0, r8
	adds r0, #0x57
_08000770:
	strb r0, [r7]
	adds r0, r7, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_780
sub_780: @ 0x08000780
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r1, #0
	bge _0800078C
	rsbs r2, r1, #0
_0800078C:
	movs r4, #1
	cmp r2, #0
	beq _080007AA
	movs r5, #1
_08000794:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0800079E
	muls r4, r3, r4
_0800079E:
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r0, #0
	asrs r2, r2, #1
	cmp r2, #0
	bne _08000794
_080007AA:
	cmp r1, #0
	bge _080007B8
	movs r0, #1
	adds r1, r4, #0
	bl __divsi3
	b _080007BA
_080007B8:
	adds r0, r4, #0
_080007BA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_7C0
sub_7C0: @ 0x080007C0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	mov r8, r0
	adds r1, r3, #0
	bl __divsi3
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r0, r8
	adds r1, r4, #0
	bl __divsi3
	mov r1, sp
	strh r6, [r1]
	mov r4, sp
	adds r4, #2
	movs r1, #0
	strh r1, [r4]
	add r6, sp, #4
	strh r1, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	adds r1, #6
	strh r0, [r1]
	ldr r3, _0800084C @ =0x03005000
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r1, r5, #5
	adds r1, r1, r3
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, #6]
	lsls r5, r5, #2
	adds r1, r5, #1
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrh r2, [r4]
	strh r2, [r1, #6]
	adds r1, r5, #2
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrh r2, [r6]
	strh r2, [r1, #6]
	adds r5, #3
	lsls r5, r5, #3
	adds r5, r5, r3
	strh r0, [r5, #6]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800084C: .4byte 0x03005000

	thumb_func_start sub_850
sub_850: @ 0x08000850
	ldr r0, _08000888 @ =0x04000208
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08000894
	ldr r0, _0800088C @ =0x04000004
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08000894
	ldr r0, _08000890 @ =0x04000200
	ldrh r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08000894
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08000894
	movs r0, #1
	b _08000896
	.align 2, 0
_08000888: .4byte 0x04000208
_0800088C: .4byte 0x04000004
_08000890: .4byte 0x04000200
_08000894:
	movs r0, #0
_08000896:
	bx lr

	thumb_func_start sub_898
sub_898: @ 0x08000898
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080008B4 @ =0x02017BD4
	str r4, [r0]
	bl sub_850
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080008AE
	ldr r0, _080008B8 @ =0x0200FB9C
	str r4, [r0]
_080008AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080008B4: .4byte 0x02017BD4
_080008B8: .4byte 0x0200FB9C

	thumb_func_start sub_8BC
sub_8BC: @ 0x080008BC
	ldr r0, _080008C8 @ =0x0200FB9C
	ldr r1, _080008CC @ =sub_DC4 + 1
	str r1, [r0]
	ldr r0, _080008D0 @ =0x02017BD4
	str r1, [r0]
	bx lr
	.align 2, 0
_080008C8: .4byte 0x0200FB9C
_080008CC: .4byte sub_DC4 + 1
_080008D0: .4byte 0x02017BD4

	thumb_func_start sub_8D4
sub_8D4: @ 0x080008D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080008F4 @ =0x02017BD0
	str r4, [r0]
	bl sub_850
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080008EC
	ldr r0, _080008F8 @ =0x0200FB98
	ldr r0, [r0]
	str r4, [r0]
_080008EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080008F4: .4byte 0x02017BD0
_080008F8: .4byte 0x0200FB98

	thumb_func_start sub_8FC
sub_8FC: @ 0x080008FC
	ldr r0, _0800090C @ =0x0200FB98
	ldr r0, [r0]
	ldr r1, _08000910 @ =sub_A08 + 1
	str r1, [r0]
	ldr r0, _08000914 @ =0x02017BD0
	str r1, [r0]
	bx lr
	.align 2, 0
_0800090C: .4byte 0x0200FB98
_08000910: .4byte sub_A08 + 1
_08000914: .4byte 0x02017BD0

	thumb_func_start sub_918
sub_918: @ 0x08000918
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08000938 @ =0x0200FBA0
	str r4, [r0]
	bl sub_850
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08000930
	ldr r0, _0800093C @ =0x02019BE0
	ldr r0, [r0]
	str r4, [r0]
_08000930:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000938: .4byte 0x0200FBA0
_0800093C: .4byte 0x02019BE0

	thumb_func_start sub_940
sub_940: @ 0x08000940
	ldr r0, _08000950 @ =0x02019BE0
	ldr r0, [r0]
	ldr r1, _08000954 @ =sub_A20 + 1
	str r1, [r0]
	ldr r0, _08000958 @ =0x0200FBA0
	str r1, [r0]
	bx lr
	.align 2, 0
_08000950: .4byte 0x02019BE0
_08000954: .4byte sub_A20 + 1
_08000958: .4byte 0x0200FBA0

	thumb_func_start AgbMain
AgbMain: @ 0x0800095C
	push {r4, r5, lr}
	movs r0, #0xff
	bl RegisterRamReset
	bl sub_BBC
	ldr r1, _080009A0 @ =0x040000D4
	ldr r0, _080009A4 @ =IntrMain
	str r0, [r1]
	ldr r2, _080009A8 @ =0x03005400
	str r2, [r1, #4]
	ldr r0, _080009AC @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080009B0 @ =0x03007FFC
	str r2, [r0]
	bl sub_B54
	bl sub_FE8
	ldr r5, _080009B4 @ =gMainFuncs
	ldr r4, _080009B8 @ =0x0200B0C0
_08000988:
	bl ReadKeys
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	bl _call_via_r0
	bl sub_D74
	b _08000988
	.align 2, 0
_080009A0: .4byte 0x040000D4
_080009A4: .4byte IntrMain
_080009A8: .4byte 0x03005400
_080009AC: .4byte 0x84000200
_080009B0: .4byte 0x03007FFC
_080009B4: .4byte gMainFuncs
_080009B8: .4byte 0x0200B0C0

	thumb_func_start sub_9BC_Main
sub_9BC_Main: @ 0x080009BC
	push {r4, lr}
	ldr r4, _080009DC @ =0x0200B0C0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080009E0
	cmp r0, #1
	beq _080009EE
	bl sub_2B4
	bl sub_D10
	movs r0, #1
	bl sub_23C
	b _080009FC
	.align 2, 0
_080009DC: .4byte 0x0200B0C0
_080009E0:
	bl sub_CBC
	bl sub_24C
	ldrb r0, [r4, #3]
	adds r0, #1
	b _080009FA
_080009EE:
	ldrh r1, [r4, #0x18]
	ldr r0, _08000A04 @ =0x000003FF
	ands r0, r1
	cmp r0, #0
	beq _080009FC
	movs r0, #2
_080009FA:
	strb r0, [r4, #3]
_080009FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000A04: .4byte 0x000003FF

	thumb_func_start sub_A08
sub_A08: @ 0x08000A08
	push {lr}
	bl m4aSoundVSync
	ldr r0, _08000A1C @ =0x03007FF8
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08000A1C: .4byte 0x03007FF8

	thumb_func_start sub_A20
sub_A20: @ 0x08000A20
	push {r4, r5, lr}
	ldr r2, _08000A78 @ =0x03007FF8
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08000A7C @ =0x04000004
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	ldr r3, _08000A80 @ =0x0200B0C0
	cmp r0, #0
	bne _08000A46
	movs r4, #2
_08000A3C:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08000A3C
_08000A46:
	adds r2, r3, #0
	ldrb r0, [r2, #2]
	cmp r0, #2
	bne _08000B2E
	ldr r0, _08000A84 @ =0x04000010
	movs r4, #0
	strh r4, [r0]
	movs r0, #0x28
	ldrsh r1, [r2, r0]
	cmp r1, #0
	beq _08000AA0
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	cmp r0, #0x48
	bne _08000A8C
	ldr r1, _08000A88 @ =0x04000012
	movs r3, #0x2a
	ldrsh r0, [r2, r3]
	lsls r0, r0, #2
	adds r0, #0x58
	strh r0, [r1]
	movs r1, #0x90
	strh r1, [r2, #0x26]
	b _08000B00
	.align 2, 0
_08000A78: .4byte 0x03007FF8
_08000A7C: .4byte 0x04000004
_08000A80: .4byte 0x0200B0C0
_08000A84: .4byte 0x04000010
_08000A88: .4byte 0x04000012
_08000A8C:
	ldr r1, _08000A9C @ =0x04000012
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r0, r5, #0
	strh r0, [r1]
	movs r1, #0x48
	strh r1, [r2, #0x26]
	b _08000B00
	.align 2, 0
_08000A9C: .4byte 0x04000012
_08000AA0:
	movs r5, #0x2c
	ldrsh r0, [r2, r5]
	cmp r0, #0
	beq _08000B24
	movs r5, #0x26
	ldrsh r0, [r2, r5]
	cmp r0, #0x28
	bne _08000ADC
	ldrh r0, [r2, #0x38]
	ldr r0, _08000AD0 @ =0x00001E41
	strh r0, [r2, #0x38]
	ldrh r0, [r2, #0x3a]
	ldr r0, _08000AD4 @ =0x00000A06
	strh r0, [r2, #0x3a]
	ldr r1, _08000AD8 @ =0x04000050
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	movs r1, #0x90
	strh r1, [r2, #0x26]
	b _08000B00
	.align 2, 0
_08000AD0: .4byte 0x00001E41
_08000AD4: .4byte 0x00000A06
_08000AD8: .4byte 0x04000050
_08000ADC:
	ldrh r0, [r3, #0x38]
	ldr r0, _08000B18 @ =0x00001E01
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3a]
	strh r1, [r3, #0x3a]
	ldr r1, _08000B1C @ =0x04000050
	ldrh r0, [r3, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #0x3a]
	strh r0, [r1]
	subs r1, #0x40
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0x28
	strh r1, [r3, #0x26]
_08000B00:
	ldr r2, _08000B20 @ =0x04000004
	ldrh r3, [r2]
	movs r0, #0xff
	ands r0, r3
	strh r0, [r2]
	lsls r1, r1, #8
	adds r1, #0x20
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	b _08000B2E
	.align 2, 0
_08000B18: .4byte 0x00001E01
_08000B1C: .4byte 0x04000050
_08000B20: .4byte 0x04000004
_08000B24:
	ldr r1, _08000B34 @ =0x04000012
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r3, #0
	strh r0, [r1]
_08000B2E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08000B34: .4byte 0x04000012

	thumb_func_start sub_B38
sub_B38: @ 0x08000B38
	push {lr}
	bl sub_1F5C
	pop {r0}
	bx r0

	thumb_func_start sub_B44
sub_B44: @ 0x08000B44
	push {lr}
	bl sub_1F4C
	pop {r0}
	bx r0

	thumb_func_start sub_B50
sub_B50: @ 0x08000B50
	bx lr

	thumb_func_start sub_B54
sub_B54: @ 0x08000B54
	push {lr}
	ldr r1, _08000B84 @ =0x04000204
	ldr r2, _08000B88 @ =0x000045B6
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #4
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #8
	movs r0, #1
	strh r0, [r1]
	bl sub_B8C
	bl m4aSoundInit
	bl m4aSoundVSyncOff
	bl sub_52A18
	pop {r0}
	bx r0
	.align 2, 0
_08000B84: .4byte 0x04000204
_08000B88: .4byte 0x000045B6

	thumb_func_start sub_B8C
sub_B8C: @ 0x08000B8C
	push {lr}
	ldr r0, _08000BB8 @ =0x0200B0C0
	movs r1, #0
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x1c]
	strh r1, [r0, #0x18]
	strh r1, [r0, #0x20]
	str r1, [r0, #0x48]
	str r1, [r0, #0x4c]
	strh r1, [r0, #0x30]
	movs r2, #0x90
	strh r2, [r0, #0x26]
	strh r1, [r0, #0x2c]
	bl sub_1090C
	bl sub_438
	pop {r0}
	bx r0
	.align 2, 0
_08000BB8: .4byte 0x0200B0C0

	thumb_func_start sub_BBC
sub_BBC: @ 0x08000BBC
	push {r4, r5, r6, lr}
	ldr r5, _08000BF0 @ =0x0200FB98
	ldr r2, _08000BF4 @ =0x02003068
	ldr r6, _08000BF8 @ =0x02019BE0
	ldr r4, _08000BFC @ =0x086A4AA0
	adds r3, r2, #0
	subs r3, #8
	movs r1, #0xd
_08000BCC:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08000BCC
	str r2, [r5]
	adds r0, r2, #0
	adds r0, #8
	str r0, [r6]
	bl sub_8BC
	bl sub_8FC
	bl sub_940
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08000BF0: .4byte 0x0200FB98
_08000BF4: .4byte 0x02003068
_08000BF8: .4byte 0x02019BE0
_08000BFC: .4byte 0x086A4AA0

	thumb_func_start sub_C00
sub_C00: @ 0x08000C00
	ldr r2, _08000C14 @ =0x0200B0C0
	ldr r1, [r2, #0x48]
	ldr r0, _08000C18 @ =0x41C64E6D
	muls r0, r1, r0
	ldr r1, _08000C1C @ =0x00003039
	adds r0, r0, r1
	str r0, [r2, #0x48]
	ldr r1, _08000C20 @ =0x0000FFFF
	ands r0, r1
	bx lr
	.align 2, 0
_08000C14: .4byte 0x0200B0C0
_08000C18: .4byte 0x41C64E6D
_08000C1C: .4byte 0x00003039
_08000C20: .4byte 0x0000FFFF

	thumb_func_start sub_C24
sub_C24: @ 0x08000C24
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x12
	movs r3, #1
	ldr r0, _08000C60 @ =0x00001FFF
	cmp r2, r0
	bls _08000C3A
	ldr r1, _08000C64 @ =0xFFFFE000
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r3, _08000C68 @ =0x0000FFFF
_08000C3A:
	ldr r0, _08000C6C @ =0x00000FFF
	cmp r2, r0
	bls _08000C4C
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08000C4C:
	ldr r1, _08000C70 @ =0x08055C44
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bx lr
	.align 2, 0
_08000C60: .4byte 0x00001FFF
_08000C64: .4byte 0xFFFFE000
_08000C68: .4byte 0x0000FFFF
_08000C6C: .4byte 0x00000FFF
_08000C70: .4byte 0x08055C44

	thumb_func_start sub_C74
sub_C74: @ 0x08000C74
	push {lr}
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start ReadKeys
ReadKeys: @ 0x08000C8C
	push {r4, lr}
	ldr r0, _08000CB4 @ =0x04000130
	ldrh r2, [r0]
	mvns r2, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08000CB8 @ =0x0200B0C0
	ldrh r4, [r3, #0x1c]
	adds r1, r2, #0
	eors r1, r4
	adds r0, r2, #0
	ands r0, r1
	strh r0, [r3, #0x18]
	ands r1, r4
	strh r1, [r3, #0x1a]
	strh r2, [r3, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000CB4: .4byte 0x04000130
_08000CB8: .4byte 0x0200B0C0

	thumb_func_start sub_CBC
sub_CBC: @ 0x08000CBC
	push {r4, lr}
	ldr r3, _08000CFC @ =0x04000200
	ldrh r1, [r3]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08000CF6
	ldr r1, _08000D00 @ =0x04000202
	ldrh r0, [r1]
	movs r2, #5
	orrs r0, r2
	strh r0, [r1]
	ldrh r1, [r3]
	ldr r0, _08000D04 @ =0x00003FFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _08000D08 @ =0x04000208
	strh r4, [r0]
	ldrh r0, [r3]
	orrs r0, r2
	strh r0, [r3]
	ldr r2, _08000D0C @ =0x04000004
	ldrh r0, [r2]
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	bl m4aSoundVSyncOn
_08000CF6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000CFC: .4byte 0x04000200
_08000D00: .4byte 0x04000202
_08000D04: .4byte 0x00003FFF
_08000D08: .4byte 0x04000208
_08000D0C: .4byte 0x04000004

	thumb_func_start sub_D10
sub_D10: @ 0x08000D10
	push {lr}
	ldr r1, _08000D54 @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _08000D58 @ =0x0000FFF7
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08000D5C @ =0x0000FFDF
	ands r0, r2
	strh r0, [r1]
	ldr r1, _08000D60 @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _08000D64 @ =0x00003FFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08000D68 @ =0x00003FFE
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	bne _08000D42
	ldr r0, _08000D6C @ =0x04000208
	strh r1, [r0]
_08000D42:
	ldr r0, _08000D70 @ =0x04000202
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	bl m4aSoundVSyncOff
	pop {r0}
	bx r0
	.align 2, 0
_08000D54: .4byte 0x04000004
_08000D58: .4byte 0x0000FFF7
_08000D5C: .4byte 0x0000FFDF
_08000D60: .4byte 0x04000200
_08000D64: .4byte 0x00003FFF
_08000D68: .4byte 0x00003FFE
_08000D6C: .4byte 0x04000208
_08000D70: .4byte 0x04000202

	thumb_func_start sub_D74
sub_D74: @ 0x08000D74
	push {lr}
	ldr r2, _08000DA8 @ =0x0200FB9C
	ldr r0, _08000DAC @ =0x02017BD4
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _08000DB0 @ =0x0200FB98
	ldr r1, [r0]
	ldr r0, _08000DB4 @ =0x02017BD0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08000DB8 @ =0x02019BE0
	ldr r1, [r0]
	ldr r0, _08000DBC @ =0x0200FBA0
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, [r2]
	cmp r2, #0
	beq _08000D9C
	bl _call_via_r2
_08000D9C:
	ldr r1, _08000DC0 @ =0x0200B0C0
	ldr r0, [r1, #0x4c]
	adds r0, #1
	str r0, [r1, #0x4c]
	pop {r0}
	bx r0
	.align 2, 0
_08000DA8: .4byte 0x0200FB9C
_08000DAC: .4byte 0x02017BD4
_08000DB0: .4byte 0x0200FB98
_08000DB4: .4byte 0x02017BD0
_08000DB8: .4byte 0x02019BE0
_08000DBC: .4byte 0x0200FBA0
_08000DC0: .4byte 0x0200B0C0

	thumb_func_start sub_DC4
sub_DC4: @ 0x08000DC4
	push {r4, lr}
	ldr r4, _08000E7C @ =0x04000004
	ldrh r1, [r4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08000E76
	bl VBlankIntrWait
	ldr r1, _08000E80 @ =0x040000D4
	ldr r0, _08000E84 @ =0x03005000
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08000E88 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xd4
	ldr r2, _08000E8C @ =0x0200B0C0
	ldrh r0, [r2, #0x16]
	strh r0, [r1]
	adds r1, #0x10
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _08000E5E
	adds r1, #0x32
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3c]
	strh r0, [r1]
_08000E5E:
	ldrh r1, [r4]
	movs r0, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #0x26]
	lsls r0, r0, #8
	adds r0, #0x20
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	bl m4aSoundMain
_08000E76:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08000E7C: .4byte 0x04000004
_08000E80: .4byte 0x040000D4
_08000E84: .4byte 0x03005000
_08000E88: .4byte 0x84000100
_08000E8C: .4byte 0x0200B0C0

	thumb_func_start sub_E90
sub_E90: @ 0x08000E90
	ldr r0, _08000EA8 @ =0x04000130
	ldrh r0, [r0]
	ldr r2, _08000EAC @ =0x000003FF
	adds r1, r2, #0
	eors r1, r0
	ldr r3, _08000EB0 @ =0x02002002
	ldr r2, _08000EB4 @ =0x02002000
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	bx lr
	.align 2, 0
_08000EA8: .4byte 0x04000130
_08000EAC: .4byte 0x000003FF
_08000EB0: .4byte 0x02002002
_08000EB4: .4byte 0x02002000

	thumb_func_start sub_EB8
sub_EB8: @ 0x08000EB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r7, #0
	movs r0, #0
	mov sl, r0
	mov sb, r0
	mov r8, r0
	bl VBlankIntrWait
	ldr r0, _08000F30 @ =0x040000D4
	ldr r1, _08000F34 @ =0x08058248
	str r1, [r0]
	ldr r1, _08000F38 @ =0x06008000
	str r1, [r0, #4]
	ldr r1, _08000F3C @ =0x80002000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08000F40 @ =0x08058048
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08000F44 @ =0x80000100
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08000F48 @ =0x0805C248
	str r1, [r0]
	ldr r2, _08000F4C @ =0x02002008
	str r2, [r0, #4]
	ldr r1, _08000F50 @ =0x80000280
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08000F54 @ =0x80000400
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08000F58 @ =0x04000008
	movs r0, #0x88
	strh r0, [r1]
	movs r4, #0
	ldr r6, _08000F5C @ =0x04000054
	movs r5, #0x10
_08000F18:
	bl VBlankIntrWait
	subs r0, r5, r4
	strh r0, [r6]
	adds r4, #1
	cmp r4, #0x10
	bls _08000F18
	ldr r6, _08000F60 @ =0x02002002
	ldr r5, _08000F64 @ =0x02002000
	ldr r4, _08000F30 @ =0x040000D4
	b _08000FA4
	.align 2, 0
_08000F30: .4byte 0x040000D4
_08000F34: .4byte 0x08058248
_08000F38: .4byte 0x06008000
_08000F3C: .4byte 0x80002000
_08000F40: .4byte 0x08058048
_08000F44: .4byte 0x80000100
_08000F48: .4byte 0x0805C248
_08000F4C: .4byte 0x02002008
_08000F50: .4byte 0x80000280
_08000F54: .4byte 0x80000400
_08000F58: .4byte 0x04000008
_08000F5C: .4byte 0x04000054
_08000F60: .4byte 0x02002002
_08000F64: .4byte 0x02002000
_08000F68:
	ldrh r0, [r6]
	ldrh r1, [r5]
	eors r0, r1
	ands r0, r1
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0xf0
	bne _08000F7C
	mov r8, sb
	mov sb, r7
_08000F7C:
	mov r1, r8
	cmp r1, #0
	beq _08000F8E
	mov r2, sb
	subs r0, r2, r1
	cmp r0, #3
	bgt _08000F8E
	movs r0, #1
	mov sl, r0
_08000F8E:
	adds r7, #1
	bl VBlankIntrWait
	ldr r0, _08000FB0 @ =0x02002008
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08000FB4 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_08000FA4:
	cmp r7, #0x1d
	bgt _08000FB8
	bl sub_E90
	b _08000F68
	.align 2, 0
_08000FB0: .4byte 0x02002008
_08000FB4: .4byte 0x84000200
_08000FB8:
	movs r4, #0
	ldr r5, _08000FD4 @ =0x04000054
_08000FBC:
	bl VBlankIntrWait
	strh r4, [r5]
	adds r4, #1
	cmp r4, #0x10
	bls _08000FBC
	mov r1, sl
	cmp r1, #0
	bne _08000FD8
	movs r0, #0
	b _08000FDA
	.align 2, 0
_08000FD4: .4byte 0x04000054
_08000FD8:
	movs r0, #1
_08000FDA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_FE8
sub_FE8: @ 0x08000FE8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r2, _08001080 @ =0x04000200
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r6, _08001084 @ =0x04000004
	ldrh r0, [r6]
	movs r1, #8
	orrs r0, r1
	strh r0, [r6]
	ldr r1, _08001088 @ =0x04000050
	ldr r3, _0800108C @ =0x00003FBF
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r3, r8
	strh r0, [r3]
	ldr r0, _08001090 @ =0x02019C00
	movs r4, #0
	str r4, [r0]
	ldr r0, _08001094 @ =0x02019BEC
	str r4, [r0]
	ldr r0, _08001098 @ =0x02019BF4
	str r4, [r0]
	ldr r0, _0800109C @ =0x02019BF0
	str r4, [r0]
	ldr r5, _080010A0 @ =0x02019C0C
	str r2, [sp]
	bl sub_EB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r5]
	ldr r2, [sp]
	ldrh r1, [r2]
	ldr r0, _080010A4 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldrh r1, [r6]
	ldr r0, _080010A8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r6]
	mov r0, r8
	strh r4, [r0]
	ldr r1, _080010AC @ =0x02019BFC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r0, _080010B0 @ =0x02019BE4
	str r4, [r0]
	ldr r0, _080010B4 @ =0x02019BE8
	str r4, [r0]
	ldr r0, _080010B8 @ =0x02019BF8
	str r4, [r0]
	ldr r1, _080010BC @ =0x02019C08
	movs r0, #2
	str r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001080: .4byte 0x04000200
_08001084: .4byte 0x04000004
_08001088: .4byte 0x04000050
_0800108C: .4byte 0x00003FBF
_08001090: .4byte 0x02019C00
_08001094: .4byte 0x02019BEC
_08001098: .4byte 0x02019BF4
_0800109C: .4byte 0x02019BF0
_080010A0: .4byte 0x02019C0C
_080010A4: .4byte 0x0000FFFE
_080010A8: .4byte 0x0000FFF7
_080010AC: .4byte 0x02019BFC
_080010B0: .4byte 0x02019BE4
_080010B4: .4byte 0x02019BE8
_080010B8: .4byte 0x02019BF8
_080010BC: .4byte 0x02019C08

	thumb_func_start sub_10C0
sub_10C0: @ 0x080010C0
	push {lr}
	ldr r0, _080010F8 @ =0x02019C0C
	ldr r2, [r0]
	cmp r2, #1
	bne _080010DC
	ldr r1, _080010FC @ =0x02003060
	ldr r0, _08001100 @ =sub_13FC + 1
	str r0, [r1]
	ldr r0, _08001104 @ =sub_1828 + 1
	str r0, [r1, #4]
	ldr r0, _08001108 @ =0x02019BF4
	str r2, [r0]
	bl sub_1340
_080010DC:
	ldr r1, _0800110C @ =0x02019BFC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r0, _08001110 @ =0x02019BE4
	movs r2, #0
	str r2, [r0]
	ldr r1, _08001114 @ =0x02019C08
	movs r0, #2
	str r0, [r1]
	ldr r0, _08001118 @ =0x02019C04
	str r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080010F8: .4byte 0x02019C0C
_080010FC: .4byte 0x02003060
_08001100: .4byte sub_13FC + 1
_08001104: .4byte sub_1828 + 1
_08001108: .4byte 0x02019BF4
_0800110C: .4byte 0x02019BFC
_08001110: .4byte 0x02019BE4
_08001114: .4byte 0x02019C08
_08001118: .4byte 0x02019C04

	thumb_func_start sub_111C
sub_111C: @ 0x0800111C
	ldr r2, _0800114C @ =0x02019BF4
	movs r1, #0
	ldr r0, _08001150 @ =0x02019C00
	str r1, [r0]
	ldr r0, _08001154 @ =0x02019BEC
	str r1, [r0]
	str r1, [r2]
	ldr r0, _08001158 @ =0x02019BF0
	str r1, [r0]
	ldr r2, _0800115C @ =0x02019BFC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
	ldr r0, _08001160 @ =0x02019BE4
	str r1, [r0]
	ldr r0, _08001164 @ =0x02019BE8
	str r1, [r0]
	ldr r0, _08001168 @ =0x02019BF8
	str r1, [r0]
	ldr r1, _0800116C @ =0x02019C08
	movs r0, #2
	str r0, [r1]
	bx lr
	.align 2, 0
_0800114C: .4byte 0x02019BF4
_08001150: .4byte 0x02019C00
_08001154: .4byte 0x02019BEC
_08001158: .4byte 0x02019BF0
_0800115C: .4byte 0x02019BFC
_08001160: .4byte 0x02019BE4
_08001164: .4byte 0x02019BE8
_08001168: .4byte 0x02019BF8
_0800116C: .4byte 0x02019C08

	thumb_func_start sub_1170
sub_1170: @ 0x08001170
	ldr r0, _0800118C @ =0x02019C0C
	ldr r0, [r0]
	cmp r0, #1
	bne _08001194
	ldr r0, _08001190 @ =0x02019C10
	ldrb r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08001194
	movs r0, #0
	b _08001196
	.align 2, 0
_0800118C: .4byte 0x02019C0C
_08001190: .4byte 0x02019C10
_08001194:
	movs r0, #1
_08001196:
	bx lr

	thumb_func_start sub_1198
sub_1198: @ 0x08001198
	ldr r0, _080011A4 @ =0x02003060
	ldr r1, _080011A8 @ =sub_B38 + 1
	str r1, [r0]
	ldr r1, _080011AC @ =sub_B44 + 1
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_080011A4: .4byte 0x02003060
_080011A8: .4byte sub_B38 + 1
_080011AC: .4byte sub_B44 + 1

	thumb_func_start sub_11B0
sub_11B0: @ 0x080011B0
	adds r1, r0, #0
	ldr r0, _080011D0 @ =0x0200B134
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080011CE
	ldr r0, _080011D4 @ =0x02019BF8
	str r1, [r0]
	ldr r0, _080011D8 @ =0x02019BFC
	movs r1, #0
	str r1, [r0]
	ldr r0, _080011DC @ =0x02019BE4
	str r1, [r0]
	ldr r0, _080011E0 @ =0x02019BE8
	str r1, [r0]
_080011CE:
	bx lr
	.align 2, 0
_080011D0: .4byte 0x0200B134
_080011D4: .4byte 0x02019BF8
_080011D8: .4byte 0x02019BFC
_080011DC: .4byte 0x02019BE4
_080011E0: .4byte 0x02019BE8

	thumb_func_start sub_11E4
sub_11E4: @ 0x080011E4
	ldr r1, _080011EC @ =0x02019C08
	str r0, [r1]
	bx lr
	.align 2, 0
_080011EC: .4byte 0x02019C08

	thumb_func_start sub_11F0
sub_11F0: @ 0x080011F0
	ldr r1, _080011F8 @ =0x02019C04
	str r0, [r1]
	bx lr
	.align 2, 0
_080011F8: .4byte 0x02019C04

	thumb_func_start sub_11FC
sub_11FC: @ 0x080011FC
	push {r4, r5, r6, r7, lr}
	ldr r0, _0800121C @ =0x02019C0C
	ldr r0, [r0]
	cmp r0, #1
	beq _08001208
	b _08001324
_08001208:
	ldr r0, _08001220 @ =0x02019C10
	ldrb r0, [r0]
	cmp r0, #5
	bls _08001212
	b _08001324
_08001212:
	lsls r0, r0, #2
	ldr r1, _08001224 @ =_08001228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800121C: .4byte 0x02019C0C
_08001220: .4byte 0x02019C10
_08001224: .4byte _08001228
_08001228: @ jump table
	.4byte _08001324 @ case 0
	.4byte _08001324 @ case 1
	.4byte _08001324 @ case 2
	.4byte _08001240 @ case 3
	.4byte _08001240 @ case 4
	.4byte _08001308 @ case 5
_08001240:
	ldr r0, _080012A8 @ =0x02019BFC
	ldr r1, [r0]
	mov ip, r0
	cmp r1, #0
	blt _080012FC
	ldr r0, _080012AC @ =0x02019C08
	ldr r3, [r0]
	cmp r3, #0
	beq _080012FC
	ldr r0, _080012B0 @ =0x02019C04
	ldr r2, [r0]
	cmp r2, #0
	bne _080012FC
	ldr r0, _080012B4 @ =0x02019BE8
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080012DC
	ldr r1, _080012B8 @ =0x086A4C44
	ldr r0, _080012BC @ =0x02019BF8
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r7, r0, r1
	mov r5, ip
	movs r6, #1
	rsbs r6, r6, #0
_08001276:
	ldr r2, [r5]
	ldr r0, [r7]
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r3, [r1]
	adds r2, #1
	str r2, [r5]
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r4, [r1]
	cmp r3, r6
	beq _080012F8
	cmp r3, r6
	bge _080012D0
	ldr r1, _080012C0 @ =0x02019BE4
	ldr r0, [r1]
	cmp r0, #0
	beq _080012C4
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _080012C8
	adds r0, r2, #1
	str r0, [r5]
	b _08001276
	.align 2, 0
_080012A8: .4byte 0x02019BFC
_080012AC: .4byte 0x02019C08
_080012B0: .4byte 0x02019C04
_080012B4: .4byte 0x02019BE8
_080012B8: .4byte 0x086A4C44
_080012BC: .4byte 0x02019BF8
_080012C0: .4byte 0x02019BE4
_080012C4:
	mvns r0, r3
	str r0, [r1]
_080012C8:
	subs r0, r2, #1
	subs r0, r0, r4
	str r0, [r5]
	b _08001276
_080012D0:
	ldr r0, _080012D8 @ =0x02019C00
	str r3, [r0]
	b _08001324
	.align 2, 0
_080012D8: .4byte 0x02019C00
_080012DC:
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r0, r1, r0
	cmp r0, #1
	bne _08001324
	cmp r3, #1
	bne _08001324
	ldr r0, _080012F4 @ =0x02019C00
	str r2, [r0]
	b _08001324
	.align 2, 0
_080012F4: .4byte 0x02019C00
_080012F8:
	mov r0, ip
	str r3, [r0]
_080012FC:
	ldr r1, _08001304 @ =0x02019C00
	movs r0, #0
	str r0, [r1]
	b _08001324
	.align 2, 0
_08001304: .4byte 0x02019C00
_08001308:
	ldr r4, _08001334 @ =0x02019BF0
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x3c
	bls _08001324
	ldr r0, _08001338 @ =0x02019BF4
	ldr r0, [r0]
	cmp r0, #0
	beq _08001320
	bl sub_1340
_08001320:
	movs r0, #0
	str r0, [r4]
_08001324:
	ldr r1, _0800133C @ =0x02019BE8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001334: .4byte 0x02019BF0
_08001338: .4byte 0x02019BF4
_0800133C: .4byte 0x02019BE8

	thumb_func_start sub_1340
sub_1340: @ 0x08001340
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r6, _080013D0 @ =0x04000208
	movs r3, #0
	strh r3, [r6]
	ldr r2, _080013D4 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _080013D8 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	mov r8, r0
	strh r0, [r6]
	ldr r0, _080013DC @ =0x04000134
	strh r3, [r0]
	ldr r4, _080013E0 @ =0x04000128
	ldr r1, _080013E4 @ =0x00001008
	adds r0, r1, #0
	strh r0, [r4]
	ldrh r0, [r4]
	movs r5, #0x80
	lsls r5, r5, #7
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _080013E8 @ =0x04000202
	movs r1, #0xc0
	strh r1, [r0]
	strh r3, [r6]
	ldrh r0, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r0, r8
	strh r0, [r6]
	ldrb r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
	ldr r0, _080013EC @ =0x02019C10
	strb r3, [r0]
	movs r5, #0
	str r5, [sp]
	ldr r1, _080013F0 @ =0x02002808
	ldr r2, _080013F4 @ =0x05000003
	mov r0, sp
	bl CpuSet
	strh r5, [r6]
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	mov r1, r8
	strh r1, [r6]
	ldr r1, _080013F8 @ =0x0400010C
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc1
	strh r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080013D0: .4byte 0x04000208
_080013D4: .4byte 0x04000200
_080013D8: .4byte 0x0000FF3F
_080013DC: .4byte 0x04000134
_080013E0: .4byte 0x04000128
_080013E4: .4byte 0x00001008
_080013E8: .4byte 0x04000202
_080013EC: .4byte 0x02019C10
_080013F0: .4byte 0x02002808
_080013F4: .4byte 0x05000003
_080013F8: .4byte 0x0400010C

	thumb_func_start sub_13FC
sub_13FC: @ 0x080013FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r1, _08001434 @ =0x02002818
	ldr r0, _08001438 @ =0x04000120
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800143C @ =0x0400010E
	movs r0, #0
	strh r0, [r1]
	subs r1, #2
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08001440 @ =0x02019C10
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #5
	bls _0800142A
	b _0800161C
_0800142A:
	lsls r0, r1, #2
	ldr r1, _08001444 @ =_08001448
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001434: .4byte 0x02002818
_08001438: .4byte 0x04000120
_0800143C: .4byte 0x0400010E
_08001440: .4byte 0x02019C10
_08001444: .4byte _08001448
_08001448: @ jump table
	.4byte _08001460 @ case 0
	.4byte _08001520 @ case 1
	.4byte _08001574 @ case 2
	.4byte _080015C8 @ case 3
	.4byte _0800161C @ case 4
	.4byte _0800161C @ case 5
_08001460:
	ldr r0, _080014B0 @ =0x04000120
	mov r8, r0
	ldr r6, [r0]
	ldr r3, _080014B4 @ =0x02002808
	ldrb r1, [r3]
	lsls r2, r1, #4
	adds r0, r6, #0
	lsls r0, r2
	lsrs r0, r0, #0x10
	movs r7, #1
	subs r1, r7, r1
	lsls r1, r1, #4
	lsls r6, r1
	adds r1, r6, #0
	lsrs r6, r1, #0x10
	ldrh r5, [r3, #0xa]
	adds r4, r3, #0
	cmp r5, #0
	bne _080014E4
	ldrh r2, [r4, #6]
	adds r1, r0, #0
	cmp r1, r2
	bne _080014E2
	ldrh r3, [r4, #2]
	cmp r3, #3
	bhi _080014B8
	ldrh r0, [r4, #4]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne _080014E4
	mvns r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bne _080014E4
	adds r0, r3, #1
	strh r0, [r4, #2]
	b _080014E4
	.align 2, 0
_080014B0: .4byte 0x04000120
_080014B4: .4byte 0x02002808
_080014B8:
	strh r6, [r4, #0xa]
	ldr r0, _080014D8 @ =0x00008002
	cmp r6, r0
	bne _080014E0
	mov r1, sb
	strb r7, [r1]
	movs r0, #1
	bl sub_1748
	ldr r1, _080014DC @ =0x02002814
	str r0, [r1]
	mov r2, r8
	str r0, [r2]
	strh r5, [r4, #2]
	b _08001640
	.align 2, 0
_080014D8: .4byte 0x00008002
_080014DC: .4byte 0x02002814
_080014E0:
	strh r5, [r4, #0xa]
_080014E2:
	strh r5, [r4, #2]
_080014E4:
	ldrh r0, [r4, #2]
	cmp r0, #3
	bhi _080014F8
	lsls r0, r0, #1
	ldr r1, _080014F4 @ =0x0805C748
	adds r0, r0, r1
	ldrh r0, [r0]
	b _080014FC
	.align 2, 0
_080014F4: .4byte 0x0805C748
_080014F8:
	movs r0, #0x80
	lsls r0, r0, #8
_080014FC:
	strh r0, [r4, #4]
	mvns r0, r6
	strh r0, [r4, #6]
	ldr r3, _0800151C @ =0x04000120
	ldrh r2, [r4, #4]
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	lsls r2, r0
	ldrh r0, [r4, #6]
	lsls r1, r1, #4
	lsls r0, r1
	adds r2, r2, r0
	str r2, [r3]
	b _08001640
	.align 2, 0
_0800151C: .4byte 0x04000120
_08001520:
	ldr r5, _08001544 @ =0x02019C10
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _08001550
	ldr r1, _08001548 @ =0x02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp]
	ldr r2, _0800154C @ =0x05000003
	mov r0, sp
	bl CpuSet
	strb r4, [r5]
	b _08001554
	.align 2, 0
_08001544: .4byte 0x02019C10
_08001548: .4byte 0x02002808
_0800154C: .4byte 0x05000003
_08001550:
	movs r0, #2
	strb r0, [r5]
_08001554:
	ldr r0, _0800156C @ =0x02019BF4
	ldr r0, [r0]
	ldr r1, _08001570 @ =0x02019C10
	mov sb, r1
	cmp r0, #0
	bne _08001564
	movs r0, #4
	strb r0, [r1]
_08001564:
	mov r2, sb
	ldrb r0, [r2]
	b _080015F8
	.align 2, 0
_0800156C: .4byte 0x02019BF4
_08001570: .4byte 0x02019C10
_08001574:
	ldr r5, _08001598 @ =0x02019C10
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _080015A4
	ldr r1, _0800159C @ =0x02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, _080015A0 @ =0x05000003
	bl CpuSet
	strb r4, [r5]
	b _080015A8
	.align 2, 0
_08001598: .4byte 0x02019C10
_0800159C: .4byte 0x02002808
_080015A0: .4byte 0x05000003
_080015A4:
	movs r0, #3
	strb r0, [r5]
_080015A8:
	ldr r0, _080015C0 @ =0x02019BF4
	ldr r0, [r0]
	ldr r1, _080015C4 @ =0x02019C10
	mov sb, r1
	cmp r0, #0
	bne _080015B8
	movs r0, #4
	strb r0, [r1]
_080015B8:
	mov r2, sb
	ldrb r0, [r2]
	b _080015F8
	.align 2, 0
_080015C0: .4byte 0x02019BF4
_080015C4: .4byte 0x02019C10
_080015C8:
	mov r5, sb
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _080015E8
	ldr r1, _08001608 @ =0x02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _0800160C @ =0x05000003
	bl CpuSet
	strb r4, [r5]
_080015E8:
	ldr r0, _08001610 @ =0x02019BF4
	ldr r0, [r0]
	cmp r0, #0
	bne _080015F4
	movs r0, #4
	strb r0, [r5]
_080015F4:
	mov r1, sb
	ldrb r0, [r1]
_080015F8:
	bl sub_1748
	ldr r1, _08001614 @ =0x02002814
	str r0, [r1]
	ldr r1, _08001618 @ =0x04000120
	str r0, [r1]
	b _08001640
	.align 2, 0
_08001608: .4byte 0x02002808
_0800160C: .4byte 0x05000003
_08001610: .4byte 0x02019BF4
_08001614: .4byte 0x02002814
_08001618: .4byte 0x04000120
_0800161C:
	ldr r3, _08001634 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08001638 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0800163C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	b _08001650
	.align 2, 0
_08001634: .4byte 0x04000208
_08001638: .4byte 0x04000200
_0800163C: .4byte 0x0000FF7F
_08001640:
	ldr r2, _08001660 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08001664 @ =0x0400010E
	movs r0, #0xc1
	strh r0, [r1]
_08001650:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001660: .4byte 0x04000128
_08001664: .4byte 0x0400010E

	thumb_func_start sub_1668
sub_1668: @ 0x08001668
	push {r4, r5, lr}
	ldr r2, _0800169C @ =0x00FFFFFF
	ands r2, r0
	lsls r4, r2, #4
	lsls r1, r1, #0x1c
	orrs r4, r1
	lsrs r3, r4, #0x1c
	movs r2, #6
	movs r5, #0xf
_0800167A:
	lsls r0, r2, #2
	adds r1, r4, #0
	lsrs r1, r0
	ands r1, r5
	eors r3, r1
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0800167A
	movs r0, #0xf
	ands r3, r0
	orrs r4, r3
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800169C: .4byte 0x00FFFFFF

	thumb_func_start sub_16A0
sub_16A0: @ 0x080016A0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r6, _080016C4 @ =0x02002818
	ldr r0, [r6]
	lsrs r5, r0, #0x1c
	bl sub_170C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080016DE
	cmp r4, #2
	beq _080016E8
	cmp r4, #2
	bgt _080016C8
	cmp r4, #1
	beq _080016CE
	b _080016DE
	.align 2, 0
_080016C4: .4byte 0x02002818
_080016C8:
	cmp r4, #3
	beq _08001700
	b _080016DE
_080016CE:
	ldr r1, _080016E4 @ =0x0200281C
	ldr r0, [r6]
	lsls r0, r0, #4
	lsrs r0, r0, #8
	ands r0, r4
	str r0, [r1]
	cmp r5, #1
	beq _08001704
_080016DE:
	movs r0, #1
	b _08001706
	.align 2, 0
_080016E4: .4byte 0x0200281C
_080016E8:
	cmp r5, #2
	bne _080016DE
	ldr r0, _080016FC @ =0x0200281C
	ldr r1, [r6]
	lsls r1, r1, #4
	lsrs r1, r1, #8
	ldr r0, [r0]
	cmp r0, r1
	beq _08001704
	b _080016DE
	.align 2, 0
_080016FC: .4byte 0x0200281C
_08001700:
	cmp r5, #3
	bne _080016DE
_08001704:
	movs r0, #0
_08001706:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_170C
sub_170C: @ 0x0800170C
	push {r4, r5, r6, lr}
	ldr r0, _0800173C @ =0x02002818
	ldr r0, [r0]
	lsrs r4, r0, #4
	movs r5, #0xf
	ands r5, r0
	lsrs r3, r4, #0x18
	movs r0, #6
	movs r6, #0xf
_0800171E:
	subs r0, #1
	lsls r2, r0, #2
	adds r1, r4, #0
	lsrs r1, r2
	ands r1, r6
	eors r3, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0800171E
	cmp r3, r5
	beq _08001740
	movs r0, #1
	b _08001742
	.align 2, 0
_0800173C: .4byte 0x02002818
_08001740:
	movs r0, #0
_08001742:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_1748
sub_1748: @ 0x08001748
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #4
	bhi _080017CE
	lsls r0, r0, #2
	ldr r1, _08001760 @ =_08001764
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001760: .4byte _08001764
_08001764: @ jump table
	.4byte _080017C4 @ case 0
	.4byte _08001778 @ case 1
	.4byte _08001784 @ case 2
	.4byte _080017C4 @ case 3
	.4byte _080017C4 @ case 4
_08001778:
	ldr r0, _08001780 @ =0x0200281C
	ldr r0, [r0]
	movs r1, #2
	b _080017C8
	.align 2, 0
_08001780: .4byte 0x0200281C
_08001784:
	ldr r4, _080017C0 @ =0x02019C00
	ldr r0, [r4]
	cmp r0, #0
	bne _0800179A
	movs r0, #0
	bl sub_17D8
	movs r1, #4
	bl sub_1668
	adds r2, r0, #0
_0800179A:
	ldr r0, [r4]
	cmp r0, #1
	bne _080017AE
	movs r0, #1
	bl sub_17D8
	movs r1, #4
	bl sub_1668
	adds r2, r0, #0
_080017AE:
	ldr r0, [r4]
	cmp r0, #2
	bne _080017CE
	movs r0, #2
	bl sub_17D8
	movs r1, #4
	b _080017C8
	.align 2, 0
_080017C0: .4byte 0x02019C00
_080017C4:
	movs r0, #1
	movs r1, #1
_080017C8:
	bl sub_1668
	adds r2, r0, #0
_080017CE:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_17D8
sub_17D8: @ 0x080017D8
	adds r2, r0, #0
	ldr r0, _080017EC @ =0x02019BEC
	ldr r0, [r0]
	cmp r0, #4
	bhi _08001824
	lsls r0, r0, #2
	ldr r1, _080017F0 @ =_080017F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080017EC: .4byte 0x02019BEC
_080017F0: .4byte _080017F4
_080017F4: @ jump table
	.4byte _08001808 @ case 0
	.4byte _0800180C @ case 1
	.4byte _08001810 @ case 2
	.4byte _08001814 @ case 3
	.4byte _08001818 @ case 4
_08001808:
	adds r1, r2, #0
	b _08001824
_0800180C:
	lsls r1, r2, #2
	b _08001824
_08001810:
	lsls r1, r2, #4
	b _08001824
_08001814:
	lsls r1, r2, #6
	b _08001824
_08001818:
	lsls r1, r2, #2
	orrs r1, r2
	lsls r0, r2, #4
	orrs r1, r0
	lsls r0, r2, #6
	orrs r1, r0
_08001824:
	adds r0, r1, #0
	bx lr

	thumb_func_start sub_1828
sub_1828: @ 0x08001828
	push {r4, r5, lr}
	ldr r3, _08001868 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _0800186C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08001870 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
	movs r5, #1
	strh r5, [r3]
	strh r4, [r3]
	subs r2, #0xd8
	ldrh r1, [r2]
	ldr r0, _08001874 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	strh r5, [r3]
	ldr r0, _08001878 @ =0x0400010E
	strh r4, [r0]
	ldr r1, _0800187C @ =0x0400010C
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08001880 @ =0x02019C10
	movs r0, #5
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001868: .4byte 0x04000208
_0800186C: .4byte 0x04000200
_08001870: .4byte 0x0000FFBF
_08001874: .4byte 0x0000FF7F
_08001878: .4byte 0x0400010E
_0800187C: .4byte 0x0400010C
_08001880: .4byte 0x02019C10

	thumb_func_start sub_1884
sub_1884: @ 0x08001884
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r0, _08001944 @ =0x02002822
	mov r8, r0
	ldr r5, _08001948 @ =0x04000208
	ldrh r2, [r5]
	movs r4, #0
	strh r4, [r5]
	ldr r6, _0800194C @ =0x04000200
	ldrh r1, [r6]
	ldr r0, _08001950 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r6]
	strh r2, [r5]
	ldr r0, _08001954 @ =0x04000134
	strh r4, [r0]
	ldr r2, _08001958 @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0800195C @ =0x00004003
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r5]
	mov r1, r8
	strh r0, [r1]
	ldr r0, _08001960 @ =sub_19CC + 1
	bl sub_898
	ldr r0, _08001964 @ =sub_1A78 + 1
	bl sub_8D4
	strh r4, [r5]
	ldrh r0, [r6]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r6]
	mov r3, r8
	ldrh r0, [r3]
	strh r0, [r5]
	ldr r0, _08001968 @ =0x0400012A
	strh r4, [r0]
	ldr r2, _0800196C @ =0x04000120
	movs r0, #0
	movs r1, #0
	str r0, [r2]
	str r1, [r2, #4]
	movs r5, #0
	str r5, [sp]
	ldr r1, _08001970 @ =0x0202BF20
	ldr r2, _08001974 @ =0x05000189
	mov r0, sp
	bl CpuSet
	ldr r0, _08001978 @ =0x02002824
	strb r4, [r0]
	ldr r0, _0800197C @ =0x02002825
	strb r4, [r0]
	ldr r0, _08001980 @ =0x02002827
	strb r4, [r0]
	ldr r0, _08001984 @ =0x02019C2C
	strb r4, [r0]
	ldr r0, _08001988 @ =0x0202A554
	strb r4, [r0]
	ldr r0, _0800198C @ =0x0202C5E0
	strb r4, [r0]
	ldr r0, _08001990 @ =0x0202ADD0
	str r5, [r0]
	ldr r0, _08001994 @ =0x0201A444
	strh r5, [r0]
	ldr r0, _08001998 @ =0x0202BDF0
	str r5, [r0]
	ldr r0, _0800199C @ =0x0201C1AC
	strb r4, [r0]
	ldr r0, _080019A0 @ =0x0202ADDC
	strb r4, [r0]
	ldr r0, _080019A4 @ =0x0202BEC8
	strb r4, [r0]
	ldr r0, _080019A8 @ =0x02002820
	strb r4, [r0]
	ldr r0, _080019AC @ =0x02002828
	strh r5, [r0]
	ldr r0, _080019B0 @ =0x0200282A
	strh r5, [r0]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001944: .4byte 0x02002822
_08001948: .4byte 0x04000208
_0800194C: .4byte 0x04000200
_08001950: .4byte 0x0000FF3F
_08001954: .4byte 0x04000134
_08001958: .4byte 0x04000128
_0800195C: .4byte 0x00004003
_08001960: .4byte sub_19CC + 1
_08001964: .4byte sub_1A78 + 1
_08001968: .4byte 0x0400012A
_0800196C: .4byte 0x04000120
_08001970: .4byte 0x0202BF20
_08001974: .4byte 0x05000189
_08001978: .4byte 0x02002824
_0800197C: .4byte 0x02002825
_08001980: .4byte 0x02002827
_08001984: .4byte 0x02019C2C
_08001988: .4byte 0x0202A554
_0800198C: .4byte 0x0202C5E0
_08001990: .4byte 0x0202ADD0
_08001994: .4byte 0x0201A444
_08001998: .4byte 0x0202BDF0
_0800199C: .4byte 0x0201C1AC
_080019A0: .4byte 0x0202ADDC
_080019A4: .4byte 0x0202BEC8
_080019A8: .4byte 0x02002820
_080019AC: .4byte 0x02002828
_080019B0: .4byte 0x0200282A

	thumb_func_start sub_19B4
sub_19B4: @ 0x080019B4
	push {lr}
	bl sub_24DC
	bl sub_250C
	bl sub_1884
	bl sub_1AA4
	pop {r0}
	bx r0

	thumb_func_start sub_19CC
sub_19CC: @ 0x080019CC
	push {lr}
	ldr r0, _08001A6C @ =0x04000004
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08001A64
	ldr r0, _08001A70 @ =0x03005000
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuSet
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _08001A74 @ =0x0200B0C0
	ldrh r0, [r2, #0x16]
	strh r0, [r1]
	adds r1, #0x10
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _08001A60
	adds r1, #0x32
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3c]
	strh r0, [r1]
_08001A60:
	bl VBlankIntrWait
_08001A64:
	bl m4aSoundMain
	pop {r0}
	bx r0
	.align 2, 0
_08001A6C: .4byte 0x04000004
_08001A70: .4byte 0x03005000
_08001A74: .4byte 0x0200B0C0

	thumb_func_start sub_1A78
sub_1A78: @ 0x08001A78
	push {lr}
	bl sub_1EC0
	bl m4aSoundVSync
	ldr r3, _08001A98 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08001A9C @ =0x03007FF8
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	strh r1, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_08001A98: .4byte 0x04000208
_08001A9C: .4byte 0x03007FF8

	thumb_func_start nullsub_15
nullsub_15: @ 0x08001AA0
	bx lr

	thumb_func_start sub_1AA4
sub_1AA4: @ 0x08001AA4
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08001AE4 @ =0x02002822
	ldr r2, _08001AE8 @ =0x04000208
	ldrh r5, [r2]
	strh r5, [r0]
	movs r4, #0
	strh r4, [r2]
	ldr r3, _08001AEC @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _08001AF0 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r3]
	strh r5, [r2]
	ldr r0, _08001AF4 @ =0x04000128
	strh r4, [r0]
	subs r0, #0x1a
	strh r4, [r0]
	ldr r1, _08001AF8 @ =0x04000202
	movs r0, #0xc0
	strh r0, [r1]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08001AFC @ =0x0202BF20
	ldr r2, _08001B00 @ =0x05000189
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001AE4: .4byte 0x02002822
_08001AE8: .4byte 0x04000208
_08001AEC: .4byte 0x04000200
_08001AF0: .4byte 0x0000FF3F
_08001AF4: .4byte 0x04000128
_08001AF8: .4byte 0x04000202
_08001AFC: .4byte 0x0202BF20
_08001B00: .4byte 0x05000189

	thumb_func_start sub_1B04
sub_1B04: @ 0x08001B04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _08001B20 @ =0x0202BF20
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _08001BEE
	lsls r0, r0, #2
	ldr r1, _08001B24 @ =_08001B28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001B20: .4byte 0x0202BF20
_08001B24: .4byte _08001B28
_08001B28: @ jump table
	.4byte _08001B3C @ case 0
	.4byte _08001B4C @ case 1
	.4byte _08001B5C @ case 2
	.4byte _08001BD0 @ case 3
	.4byte _08001BDA @ case 4
_08001B3C:
	bl sub_1AA4
	ldr r1, _08001B48 @ =0x0202BF20
	movs r0, #1
	strb r0, [r1, #1]
	b _08001BEE
	.align 2, 0
_08001B48: .4byte 0x0202BF20
_08001B4C:
	bl sub_1884
	ldr r1, _08001B58 @ =0x0202BF20
	movs r0, #2
	strb r0, [r1, #1]
	b _08001BEE
	.align 2, 0
_08001B58: .4byte 0x0202BF20
_08001B5C:
	ldrb r1, [r6]
	cmp r1, #1
	beq _08001B98
	cmp r1, #2
	beq _08001BBC
	bl sub_1C5C
	ldr r2, _08001B90 @ =0x0202C5E0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08001BEE
	ldr r1, _08001B94 @ =0x0202BF20
	ldrb r0, [r1]
	cmp r0, #0
	beq _08001BEE
	ldrb r0, [r1, #3]
	cmp r0, #2
	bne _08001BEE
	movs r0, #1
	strb r0, [r1, #0x10]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	strb r0, [r2]
	b _08001BEE
	.align 2, 0
_08001B90: .4byte 0x0202C5E0
_08001B94: .4byte 0x0202BF20
_08001B98:
	ldr r2, _08001BB4 @ =0x0202BF20
	ldrb r0, [r2]
	cmp r0, #0
	beq _08001BA8
	ldrb r0, [r2, #3]
	cmp r0, #2
	bne _08001BA8
	strb r1, [r2, #0x10]
_08001BA8:
	ldr r1, _08001BB8 @ =0x0202C5E0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r1]
	b _08001BEE
	.align 2, 0
_08001BB4: .4byte 0x0202BF20
_08001BB8: .4byte 0x0202C5E0
_08001BBC:
	ldr r0, _08001BC8 @ =0x0202BF20
	movs r1, #0
	strb r1, [r0, #1]
	ldr r0, _08001BCC @ =0x0400012A
	strh r1, [r0]
	b _08001BEE
	.align 2, 0
_08001BC8: .4byte 0x0202BF20
_08001BCC: .4byte 0x0400012A
_08001BD0:
	bl sub_1C84
	ldr r1, _08001C30 @ =0x0202BF20
	movs r0, #4
	strb r0, [r1, #1]
_08001BDA:
	ldr r0, _08001C30 @ =0x0202BF20
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	bne _08001BE8
	adds r0, r4, #0
	bl sub_1CD4
_08001BE8:
	adds r0, r5, #0
	bl sub_1DB8
_08001BEE:
	movs r0, #0
	strb r0, [r6]
	ldr r1, _08001C30 @ =0x0202BF20
	ldrb r2, [r1, #2]
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _08001C06
	movs r0, #0x20
	orrs r2, r0
_08001C06:
	ldrb r0, [r1, #0xc]
	lsls r3, r0, #8
	ldrb r0, [r1, #0x11]
	lsls r4, r0, #9
	ldrb r0, [r1, #0x12]
	lsls r5, r0, #0x10
	ldrb r0, [r1, #0x13]
	lsls r6, r0, #0x11
	ldrb r0, [r1, #0x14]
	lsls r7, r0, #0x12
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #0x14
	mov ip, r0
	ldrb r0, [r1, #1]
	cmp r0, #4
	bne _08001C34
	movs r0, #0x40
	orrs r0, r3
	orrs r0, r2
	b _08001C38
	.align 2, 0
_08001C30: .4byte 0x0202BF20
_08001C34:
	adds r0, r2, #0
	orrs r0, r3
_08001C38:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	mov r2, ip
	orrs r0, r2
	adds r2, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #1
	bls _08001C52
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r2, r0
_08001C52:
	adds r0, r2, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_1C5C
sub_1C5C: @ 0x08001C5C
	ldr r0, _08001C74 @ =0x04000128
	ldr r1, [r0]
	movs r0, #0xc
	ands r1, r0
	ldr r2, _08001C78 @ =0x0202BF20
	cmp r1, #8
	bne _08001C7C
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _08001C7C
	strb r1, [r2]
	b _08001C80
	.align 2, 0
_08001C74: .4byte 0x04000128
_08001C78: .4byte 0x0202BF20
_08001C7C:
	movs r0, #0
	strb r0, [r2]
_08001C80:
	bx lr

	thumb_func_start sub_1C84
sub_1C84: @ 0x08001C84
	push {r4, lr}
	ldr r0, _08001CBC @ =0x0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08001CB4
	ldr r1, _08001CC0 @ =0x0400010C
	ldr r2, _08001CC4 @ =0x0000FF3B
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x41
	strh r0, [r1]
	ldr r0, _08001CC8 @ =0x02002822
	ldr r2, _08001CCC @ =0x04000208
	ldrh r4, [r2]
	strh r4, [r0]
	movs r0, #0
	strh r0, [r2]
	ldr r3, _08001CD0 @ =0x04000200
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3]
	strh r4, [r2]
_08001CB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001CBC: .4byte 0x0202BF20
_08001CC0: .4byte 0x0400010C
_08001CC4: .4byte 0x0000FF3B
_08001CC8: .4byte 0x02002822
_08001CCC: .4byte 0x04000208
_08001CD0: .4byte 0x04000200

	thumb_func_start sub_1CD4
sub_1CD4: @ 0x08001CD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	ldr r2, _08001D48 @ =0x02002822
	ldr r1, _08001D4C @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08001D50 @ =0x0202BF20
	ldr r4, _08001D54 @ =0x0000021D
	adds r0, r1, r4
	ldrb r4, [r0]
	mov sl, r2
	adds r6, r1, #0
	cmp r4, #0x1f
	bhi _08001D60
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08001D14
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08001D14:
	movs r2, #0
	ldr r4, _08001D58 @ =0x02002828
	mov r8, r4
	ldr r1, _08001D5C @ =0x02019C2C
	mov sb, r1
	lsls r5, r0, #1
	movs r0, #0x1c
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
_08001D28:
	ldrh r0, [r4]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r4]
	lsls r0, r2, #6
	adds r0, r5, r0
	add r0, ip
	strh r1, [r0]
	strh r7, [r3]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _08001D28
	b _08001D70
	.align 2, 0
_08001D48: .4byte 0x02002822
_08001D4C: .4byte 0x04000208
_08001D50: .4byte 0x0202BF20
_08001D54: .4byte 0x0000021D
_08001D58: .4byte 0x02002828
_08001D5C: .4byte 0x02019C2C
_08001D60:
	ldrb r1, [r6, #0x14]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0x14]
	ldr r1, _08001DA8 @ =0x02002828
	mov r8, r1
	ldr r2, _08001DAC @ =0x02019C2C
	mov sb, r2
_08001D70:
	mov r4, r8
	ldrh r0, [r4]
	cmp r0, #0
	beq _08001D86
	ldr r1, _08001DB0 @ =0x0000021D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strh r2, [r4]
_08001D86:
	ldr r1, _08001DB4 @ =0x04000208
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r4, _08001DB0 @ =0x0000021D
	adds r0, r6, r4
	ldrb r0, [r0]
	mov r1, sb
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001DA8: .4byte 0x02002828
_08001DAC: .4byte 0x02019C2C
_08001DB0: .4byte 0x0000021D
_08001DB4: .4byte 0x04000208

	thumb_func_start sub_1DB8
sub_1DB8: @ 0x08001DB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r2, _08001E18 @ =0x02002822
	ldr r1, _08001E1C @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08001E20 @ =0x0202BF20
	ldr r3, _08001E24 @ =0x00000621
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	bne _08001E28
	movs r1, #0
	mov r8, r7
	ldrb r6, [r7, #3]
_08001DE4:
	movs r2, #0
	adds r5, r1, #1
	cmp r2, r6
	bhs _08001E08
	lsls r0, r1, #2
	mov r3, ip
	adds r1, r0, r3
	movs r4, #0
	mov r0, r8
	ldrb r3, [r0, #3]
_08001DF8:
	lsls r0, r2, #1
	adds r0, r0, r1
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	blo _08001DF8
_08001E08:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls _08001DE4
	movs r0, #1
	strb r0, [r7, #0xc]
	b _08001E9A
	.align 2, 0
_08001E18: .4byte 0x02002822
_08001E1C: .4byte 0x04000208
_08001E20: .4byte 0x0202BF20
_08001E24: .4byte 0x00000621
_08001E28:
	movs r1, #0
	ldrb r2, [r7, #3]
	mov sb, r2
	movs r3, #0x88
	lsls r3, r3, #2
	adds r3, r3, r7
	mov r8, r3
	mov sl, r7
_08001E38:
	movs r2, #0
	adds r5, r1, #1
	cmp r2, sb
	bhs _08001E6C
	lsls r0, r1, #2
	mov r3, ip
	adds r6, r0, r3
	ldr r0, _08001EB0 @ =0x0202C540
	ldrb r0, [r0]
	lsls r0, r0, #1
	lsls r1, r1, #6
	adds r4, r0, r1
	mov r0, sl
	ldrb r3, [r0, #3]
_08001E54:
	lsls r1, r2, #1
	adds r1, r1, r6
	lsls r0, r2, #9
	adds r0, r4, r0
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	blo _08001E54
_08001E6C:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls _08001E38
	adds r2, r7, #0
	ldr r3, _08001EB4 @ =0x00000621
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	movs r3, #0
	strb r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08001E98
	strb r3, [r2]
_08001E98:
	strb r3, [r7, #0xc]
_08001E9A:
	ldr r1, _08001EB8 @ =0x04000208
	ldr r2, _08001EBC @ =0x02002822
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001EB0: .4byte 0x0202C540
_08001EB4: .4byte 0x00000621
_08001EB8: .4byte 0x04000208
_08001EBC: .4byte 0x02002822

	thumb_func_start sub_1EC0
sub_1EC0: @ 0x08001EC0
	push {r4, lr}
	ldr r4, _08001F00 @ =0x0202BF20
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08001EDC
	ldr r1, _08001F04 @ =0x02002826
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08001F42
	strb r0, [r4, #0xe]
_08001EDC:
	ldrb r3, [r4]
	cmp r3, #0
	beq _08001F16
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08001F10
	cmp r0, #4
	bne _08001F42
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	bhi _08001F08
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08001F10
	movs r0, #1
	strb r0, [r4, #0x15]
	b _08001F42
	.align 2, 0
_08001F00: .4byte 0x0202BF20
_08001F04: .4byte 0x02002826
_08001F08:
	ldrb r0, [r4, #0x15]
	cmp r0, #0
	bne _08001F42
	strb r0, [r4, #0xd]
_08001F10:
	bl sub_1FEC
	b _08001F42
_08001F16:
	ldrb r2, [r4, #1]
	cmp r2, #4
	beq _08001F20
	cmp r2, #2
	bne _08001F42
_08001F20:
	ldr r1, _08001F48 @ =0x02002824
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _08001F42
	cmp r2, #4
	bne _08001F38
	movs r0, #2
	strb r0, [r4, #0x15]
_08001F38:
	cmp r2, #2
	bne _08001F42
	strb r3, [r4, #2]
	strb r3, [r4, #3]
	strb r3, [r4, #0x11]
_08001F42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001F48: .4byte 0x02002824

	thumb_func_start sub_1F4C
sub_1F4C: @ 0x08001F4C
	push {lr}
	bl sub_2308
	bl sub_1FEC
	pop {r0}
	bx r0

	thumb_func_start sub_1F5C
sub_1F5C: @ 0x08001F5C
	push {r4, lr}
	ldr r0, _08001F90 @ =0x04000128
	ldr r1, [r0]
	ldr r4, _08001F94 @ =0x0202BF20
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r4, #2]
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08001F98
	cmp r0, #4
	bne _08001FB6
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	beq _08001F80
	movs r0, #1
	strb r0, [r4, #0x12]
_08001F80:
	bl sub_20FC
	bl sub_223C
	bl sub_2338
	b _08001FB6
	.align 2, 0
_08001F90: .4byte 0x04000128
_08001F94: .4byte 0x0202BF20
_08001F98:
	bl sub_1FFC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08001FB6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08001FB2
	movs r0, #3
	strb r0, [r4, #1]
	movs r0, #8
	strb r0, [r4, #0xd]
	b _08001FB6
_08001FB2:
	movs r0, #4
	strb r0, [r4, #1]
_08001FB6:
	ldr r3, _08001FDC @ =0x0202BF20
	ldrb r0, [r3, #0xd]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #0xd]
	ldr r1, _08001FE0 @ =0x02002824
	strb r2, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08001FD6
	ldr r0, _08001FE4 @ =0x0202A554
	ldr r2, _08001FE8 @ =0x00000621
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
_08001FD6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001FDC: .4byte 0x0202BF20
_08001FE0: .4byte 0x02002824
_08001FE4: .4byte 0x0202A554
_08001FE8: .4byte 0x00000621

	thumb_func_start sub_1FEC
sub_1FEC: @ 0x08001FEC
	ldr r0, _08001FF8 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08001FF8: .4byte 0x04000128

	thumb_func_start sub_1FFC
sub_1FFC: @ 0x08001FFC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r5, _08002018 @ =0x0000FFFF
	ldr r0, _0800201C @ =0x0202BF20
	ldrb r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r1, #1
	bne _0800202C
	ldr r1, _08002020 @ =0x0400012A
	ldr r2, _08002024 @ =0x00008FFF
	b _08002030
	.align 2, 0
_08002018: .4byte 0x0000FFFF
_0800201C: .4byte 0x0202BF20
_08002020: .4byte 0x0400012A
_08002024: .4byte 0x00008FFF
_08002028:
	movs r7, #0
	b _080020B2
_0800202C:
	ldr r1, _08002080 @ =0x0400012A
	ldr r2, _08002084 @ =0x0000D13B
_08002030:
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
	strb r0, [r4, #0x10]
	ldr r0, _08002088 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #4]
	str r1, [r4, #8]
	movs r3, #0
	ldr r0, _0800208C @ =0x02002827
	mov sb, r0
	adds r6, r4, #0
	ldr r1, _08002090 @ =0x00008FFF
	mov r8, r1
	ldr r2, _08002094 @ =0x0000FFFF
	mov ip, r2
_08002052:
	lsls r0, r3, #1
	adds r1, r6, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r2
	ldr r1, _08002098 @ =0x0000D138
	cmp r0, r1
	beq _0800206C
	adds r0, r2, #0
	cmp r0, r8
	bne _0800209C
_0800206C:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r2, #0
	cmp r5, r0
	bls _080020A8
	cmp r0, #0
	beq _080020A8
	adds r5, r2, #0
	b _080020A8
	.align 2, 0
_08002080: .4byte 0x0400012A
_08002084: .4byte 0x0000D13B
_08002088: .4byte 0x04000120
_0800208C: .4byte 0x02002827
_08002090: .4byte 0x00008FFF
_08002094: .4byte 0x0000FFFF
_08002098: .4byte 0x0000D138
_0800209C:
	cmp r0, ip
	bne _08002028
	ldrb r0, [r6, #2]
	cmp r3, r0
	bne _080020A8
	movs r7, #0
_080020A8:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08002052
_080020B2:
	strb r7, [r4, #3]
	adds r0, r7, #0
	cmp r0, #2
	bne _080020E2
	mov r1, sb
	ldrb r1, [r1]
	cmp r0, r1
	bne _080020D4
	ldrh r1, [r4, #4]
	ldr r0, _080020D0 @ =0x00008FFF
	cmp r1, r0
	bne _080020D4
	movs r0, #1
	b _080020EE
	.align 2, 0
_080020D0: .4byte 0x00008FFF
_080020D4:
	ldrb r0, [r4, #3]
	cmp r0, #2
	bne _080020E2
	movs r0, #3
	ands r5, r0
	adds r0, r5, #1
	b _080020E4
_080020E2:
	movs r0, #0
_080020E4:
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #3]
	mov r2, sb
	strb r0, [r2]
	movs r0, #0
_080020EE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_20FC
sub_20FC: @ 0x080020FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08002158 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0800215C @ =0x0202BF20
	ldrb r1, [r0, #0x18]
	adds r6, r0, #0
	cmp r1, #0
	bne _08002164
	movs r3, #0
	ldr r7, _08002160 @ =0x02002820
	ldrb r0, [r6, #3]
	cmp r3, r0
	bhs _0800214C
	adds r5, r6, #0
	ldrh r1, [r6, #0x16]
	adds r4, r7, #0
	adds r2, r6, #0
_0800212C:
	lsls r0, r3, #1
	add r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	beq _08002140
	ldrb r0, [r4]
	cmp r0, #0
	beq _08002140
	movs r0, #1
	strb r0, [r5, #0x13]
_08002140:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r0, [r2, #3]
	cmp r3, r0
	blo _0800212C
_0800214C:
	movs r0, #0
	strh r0, [r6, #0x16]
	movs r0, #1
	strb r0, [r7]
	b _08002224
	.align 2, 0
_08002158: .4byte 0x04000120
_0800215C: .4byte 0x0202BF20
_08002160: .4byte 0x02002820
_08002164:
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r2, #1
	adds r0, r6, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08002182
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08002182:
	cmp r2, #0x1f
	bhi _080021F8
	movs r3, #0
	ldrb r1, [r6, #3]
	cmp r3, r1
	bhs _08002200
	adds r5, r6, #0
	ldr r7, _080021F0 @ =0x0200282A
	lsls r0, r0, #1
	mov ip, r0
	movs r2, #0x88
	lsls r2, r2, #2
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _080021F4 @ =0x02002826
	mov r8, r0
_080021A2:
	lsls r0, r3, #1
	mov r1, sp
	adds r4, r1, r0
	ldrh r2, [r4]
	ldrh r1, [r5, #0x16]
	adds r0, r2, r1
	strh r0, [r5, #0x16]
	ldrh r0, [r7]
	orrs r0, r2
	strh r0, [r7]
	ldrb r0, [r5, #0x19]
	lsls r0, r0, #6
	add r0, ip
	lsls r1, r3, #9
	adds r0, r0, r1
	add r0, sb
	strh r2, [r0]
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _080021E2
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080021E2
	ldrh r0, [r4]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	bne _080021E2
	strb r1, [r5, #0xe]
	movs r0, #5
	mov r2, r8
	strb r0, [r2]
_080021E2:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r0, [r5, #3]
	cmp r3, r0
	blo _080021A2
	b _08002200
	.align 2, 0
_080021F0: .4byte 0x0200282A
_080021F4: .4byte 0x02002826
_080021F8:
	ldrb r1, [r6, #0x14]
	movs r0, #2
	orrs r0, r1
	strb r0, [r6, #0x14]
_08002200:
	ldrb r0, [r6, #0x19]
	adds r0, #1
	strb r0, [r6, #0x19]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08002224
	ldr r2, _08002234 @ =0x0200282A
	ldrh r0, [r2]
	cmp r0, #0
	beq _08002224
	ldr r1, _08002238 @ =0x00000621
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_08002224:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002234: .4byte 0x0200282A
_08002238: .4byte 0x00000621

	thumb_func_start sub_223C
sub_223C: @ 0x0800223C
	ldr r0, _08002278 @ =0x0202BF20
	ldrb r2, [r0, #0x18]
	adds r3, r0, #0
	cmp r2, #8
	bne _0800228E
	ldr r1, _0800227C @ =0x0400012A
	ldrh r0, [r3, #0x16]
	strh r0, [r1]
	ldr r1, _08002280 @ =0x02002825
	ldrb r2, [r1]
	cmp r2, #0
	bne _08002288
	ldr r0, _08002284 @ =0x0000021D
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080022FE
	strb r2, [r1]
	b _080022FE
	.align 2, 0
_08002278: .4byte 0x0202BF20
_0800227C: .4byte 0x0400012A
_08002280: .4byte 0x02002825
_08002284: .4byte 0x0000021D
_08002288:
	movs r0, #0
	strb r0, [r1]
	b _080022FE
_0800228E:
	ldr r1, _080022B0 @ =0x02002825
	cmp r2, #0
	bne _080022A2
	ldr r2, _080022B4 @ =0x0000021D
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080022A2
	movs r0, #1
	strb r0, [r1]
_080022A2:
	ldrb r0, [r1]
	cmp r0, #0
	beq _080022BC
	ldr r1, _080022B8 @ =0x0400012A
	movs r0, #0
	strh r0, [r1]
	b _080022D8
	.align 2, 0
_080022B0: .4byte 0x02002825
_080022B4: .4byte 0x0000021D
_080022B8: .4byte 0x0400012A
_080022BC:
	ldr r2, _08002300 @ =0x0400012A
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r3, #0x18]
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x1c
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
_080022D8:
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080022F8
	ldrb r0, [r3, #0x18]
	cmp r0, #0
	bne _080022F8
	ldr r2, _08002304 @ =0x00000621
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080022F8
	ldr r0, _08002300 @ =0x0400012A
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
_080022F8:
	ldrb r0, [r3, #0x18]
	adds r0, #1
	strb r0, [r3, #0x18]
_080022FE:
	bx lr
	.align 2, 0
_08002300: .4byte 0x0400012A
_08002304: .4byte 0x00000621

	thumb_func_start sub_2308
sub_2308: @ 0x08002308
	ldr r0, _08002324 @ =0x0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08002322
	ldr r2, _08002328 @ =0x0400010E
	ldrh r1, [r2]
	ldr r0, _0800232C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08002330 @ =0x0400010C
	ldr r2, _08002334 @ =0x0000FF3B
	adds r0, r2, #0
	strh r0, [r1]
_08002322:
	bx lr
	.align 2, 0
_08002324: .4byte 0x0202BF20
_08002328: .4byte 0x0400010E
_0800232C: .4byte 0x0000FF7F
_08002330: .4byte 0x0400010C
_08002334: .4byte 0x0000FF3B

	thumb_func_start sub_2338
sub_2338: @ 0x08002338
	ldr r1, _08002348 @ =0x0202BF20
	ldrb r0, [r1, #0x19]
	cmp r0, #8
	bne _0800234C
	movs r0, #0
	strb r0, [r1, #0x18]
	strb r0, [r1, #0x19]
	b _0800235C
	.align 2, 0
_08002348: .4byte 0x0202BF20
_0800234C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800235C
	ldr r0, _08002360 @ =0x0400010E
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
_0800235C:
	bx lr
	.align 2, 0
_08002360: .4byte 0x0400010E

	thumb_func_start sub_2364
sub_2364: @ 0x08002364
	push {r4, r5, lr}
	ldr r1, _080023A8 @ =0x0202BF20
	ldr r2, _080023AC @ =0x0000021D
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #0
	adds r5, r1, #0
	adds r5, #0x1c
	ldr r4, _080023B0 @ =0x0000EFFF
_08002380:
	movs r2, #0
	adds r1, r0, #1
	lsls r3, r0, #6
_08002386:
	lsls r0, r2, #1
	adds r0, r0, r3
	adds r0, r0, r5
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1f
	bls _08002386
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08002380
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080023A8: .4byte 0x0202BF20
_080023AC: .4byte 0x0000021D
_080023B0: .4byte 0x0000EFFF

	thumb_func_start sub_23B4
sub_23B4: @ 0x080023B4
	push {r4, r5, r6, r7, lr}
	ldr r1, _08002408 @ =0x0202BF20
	ldr r2, _0800240C @ =0x00000621
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	adds r7, r1, r0
	ldr r6, _08002410 @ =0x0000EFFF
_080023D0:
	movs r0, #0
	adds r5, r2, #1
	lsls r4, r2, #9
_080023D6:
	movs r2, #0
	adds r1, r0, #1
	lsls r3, r0, #6
_080023DC:
	lsls r0, r2, #1
	adds r0, r0, r3
	adds r0, r0, r4
	adds r0, r0, r7
	strh r6, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1f
	bls _080023DC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080023D6
	lsls r0, r5, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls _080023D0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002408: .4byte 0x0202BF20
_0800240C: .4byte 0x00000621
_08002410: .4byte 0x0000EFFF

	thumb_func_start sub_2414
sub_2414: @ 0x08002414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	str r2, [sp, #8]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r4, _080024CC @ =0x03005000
	movs r7, #0
	ldr r0, _080024D0 @ =0x08057C46
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, #0
	bl CpuSet
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r7, r0
	bhs _080024B8
_08002442:
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, [sp, #8]
	adds r6, r2, r0
	ldrh r0, [r6]
	adds r2, r1, #1
	mov sl, r2
	cmp r0, #0
	beq _080024AC
	lsls r0, r1, #2
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r5, [r0]
	adds r0, #2
	lsls r1, r7, #3
	ldr r4, _080024CC @ =0x03005000
	adds r1, r1, r4
	lsls r2, r5, #2
	bl CpuSet
	movs r3, #0
	cmp r3, r5
	bhs _080024AC
	mov r8, r4
	ldr r2, _080024D4 @ =0x000001FF
	mov sb, r2
	movs r0, #0xff
	mov ip, r0
_0800247C:
	adds r2, r7, #0
	lsls r0, r2, #3
	mov r1, r8
	adds r4, r0, r1
	lsls r1, r3, #3
	adds r1, #8
	adds r1, r6, r1
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	strh r2, [r1]
	ldrh r2, [r4, #2]
	mov r0, sb
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r2, [r4]
	mov r0, ip
	ands r0, r2
	strh r0, [r1, #4]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	blo _0800247C
_080024AC:
	mov r2, sl
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	ldr r0, [sp, #4]
	cmp r1, r0
	blo _08002442
_080024B8:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080024CC: .4byte 0x03005000
_080024D0: .4byte 0x08057C46
_080024D4: .4byte 0x000001FF

	thumb_func_start nullsub_16
nullsub_16: @ 0x080024D8
	bx lr

	thumb_func_start sub_24DC
sub_24DC: @ 0x080024DC
	ldr r1, _08002504 @ =0x04000134
	movs r0, #0
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	ldr r2, _08002508 @ =0x0400012A
	strh r0, [r2]
	subs r1, #8
	strh r0, [r1]
	strh r0, [r2]
	strh r0, [r1]
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08002504: .4byte 0x04000134
_08002508: .4byte 0x0400012A

	thumb_func_start sub_250C
sub_250C: @ 0x0800250C
	ldr r2, _08002528 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	ldr r1, _0800252C @ =0x04000200
	ldr r3, _08002530 @ =0x00002001
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, _08002534 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08002528: .4byte 0x04000208
_0800252C: .4byte 0x04000200
_08002530: .4byte 0x00002001
_08002534: .4byte 0x04000004

	thumb_func_start sub_2538
sub_2538: @ 0x08002538
	ldr r0, _08002554 @ =0x0202ADD0
	movs r1, #0
	str r1, [r0]
	ldr r0, _08002558 @ =0x0201A444
	movs r2, #0
	strh r1, [r0]
	ldr r0, _0800255C @ =0x0202BDF0
	str r1, [r0]
	ldr r0, _08002560 @ =0x0201C1AC
	strb r2, [r0]
	ldr r0, _08002564 @ =0x0202ADDC
	strb r2, [r0]
	bx lr
	.align 2, 0
_08002554: .4byte 0x0202ADD0
_08002558: .4byte 0x0201A444
_0800255C: .4byte 0x0202BDF0
_08002560: .4byte 0x0201C1AC
_08002564: .4byte 0x0202ADDC

	thumb_func_start sub_2568
sub_2568: @ 0x08002568
	push {r4, lr}
	bl sub_24DC
	ldr r4, _08002594 @ =0x04000208
	movs r0, #0
	strh r0, [r4]
	bl sub_8BC
	bl sub_8FC
	ldr r1, _08002598 @ =0x04000200
	ldr r2, _0800259C @ =0x00002005
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080025A0 @ =0x04000004
	movs r0, #0x28
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002594: .4byte 0x04000208
_08002598: .4byte 0x04000200
_0800259C: .4byte 0x00002005
_080025A0: .4byte 0x04000004
