	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1068C
sub_1068C: @ 0x0801068C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r7, r2, #0
	mov sb, r3
	ldr r0, [sp, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	movs r2, #0
	cmp r2, sb
	bge _080106F0
	lsls r0, r1, #5
	adds r0, r0, r4
	mov sl, r0
_080106B2:
	movs r3, #0
	adds r6, r2, #1
	cmp r3, r7
	bge _080106E8
	lsls r0, r2, #5
	mov r1, sl
	adds r5, r1, r0
	ldr r0, _08010700 @ =0x03005C00
	mov ip, r0
	ldr r1, _08010704 @ =0x00000FFF
	mov r8, r1
	ldr r0, [sp]
	lsls r4, r0, #0xc
_080106CC:
	adds r1, r3, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	add r1, ip
	ldrh r2, [r1]
	mov r0, r8
	ands r0, r2
	orrs r0, r4
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r7
	blt _080106CC
_080106E8:
	lsls r0, r6, #0x10
	lsrs r2, r0, #0x10
	cmp r2, sb
	blt _080106B2
_080106F0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010700: .4byte 0x03005C00
_08010704: .4byte 0x00000FFF

	thumb_func_start sub_10708
sub_10708: @ 0x08010708
	push {r4, r5, lr}
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	movs r4, #0
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	cmp r4, r1
	bge _08010744
	ldr r2, _0801074C @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r3, r0, #0xc
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r3, r0
	adds r5, r1, #0
_0801072C:
	lsls r1, r4, #0xa
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	adds r4, #1
	cmp r4, r5
	blt _0801072C
_08010744:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801074C: .4byte 0x040000D4

	thumb_func_start sub_10750
sub_10750: @ 0x08010750
	push {r4, r5, lr}
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	movs r4, #0
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	cmp r4, r1
	bge _0801078C
	ldr r2, _08010794 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r3, r0
	adds r5, r1, #0
_08010774:
	lsls r1, r4, #6
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	adds r4, #1
	cmp r4, r5
	blt _08010774
_0801078C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010794: .4byte 0x040000D4

	thumb_func_start sub_10798
sub_10798: @ 0x08010798
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r2
	ldr r4, _08010818 @ =0x040000D4
	str r0, [r4]
	ldr r2, _0801081C @ =0x0201A920
	str r2, [r4, #4]
	ldr r0, _08010820 @ =0x80000100
	str r0, [r4, #8]
	ldr r3, [r4, #8]
	str r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r2, r1
	str r3, [r4, #4]
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sp
	ldr r5, _08010824 @ =0x00007FFF
	adds r0, r5, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _08010828 @ =0xFFFFFC00
	adds r2, r2, r0
	str r2, [r4, #4]
	ldr r0, _0801082C @ =0x81000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r2, [r4]
	str r3, [r4, #4]
	ldr r5, _08010830 @ =0x80000200
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	str r3, [r4]
	movs r6, #0xa0
	lsls r6, r6, #0x13
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_1050C
	ldr r1, _08010834 @ =0x0200B0C0
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r0, [r0]
	strh r0, [r1, #0x16]
	movs r7, #0
_080107FA:
	mov r1, r8
	cmp r1, #0
	beq _08010804
	bl _call_via_r8
_08010804:
	adds r0, r7, #0
	bl sub_1001C
	bl sub_D74
	cmp r7, #0x20
	bne _08010838
	ldr r0, _0801081C @ =0x0201A920
	b _0801083A
	.align 2, 0
_08010818: .4byte 0x040000D4
_0801081C: .4byte 0x0201A920
_08010820: .4byte 0x80000100
_08010824: .4byte 0x00007FFF
_08010828: .4byte 0xFFFFFC00
_0801082C: .4byte 0x81000200
_08010830: .4byte 0x80000200
_08010834: .4byte 0x0200B0C0
_08010838:
	ldr r0, _0801085C @ =0x0201AD20
_0801083A:
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x20
	bls _080107FA
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801085C: .4byte 0x0201AD20

	thumb_func_start sub_10860
sub_10860: @ 0x08010860
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _080108C8 @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov r8, r0
	str r0, [r1]
	ldr r3, _080108CC @ =0x0201A520
	str r3, [r1, #4]
	ldr r4, _080108D0 @ =0x80000200
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sp
	ldr r6, _080108D4 @ =0x00007FFF
	adds r0, r6, #0
	strh r0, [r2]
	str r2, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r3, r2
	str r0, [r1, #4]
	ldr r0, _080108D8 @ =0x81000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r3, [r1]
	movs r6, #0x80
	lsls r6, r6, #4
	adds r3, r3, r6
	str r3, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	adds r6, r1, #0
_080108A8:
	cmp r5, #0
	beq _080108B0
	bl _call_via_r5
_080108B0:
	adds r0, r7, #0
	bl sub_1001C
	bl sub_D74
	cmp r7, #0x20
	bne _080108E0
	ldr r0, _080108DC @ =0x0201A920
	str r0, [r6]
	mov r0, r8
	str r0, [r6, #4]
	b _080108E8
	.align 2, 0
_080108C8: .4byte 0x040000D4
_080108CC: .4byte 0x0201A520
_080108D0: .4byte 0x80000200
_080108D4: .4byte 0x00007FFF
_080108D8: .4byte 0x81000200
_080108DC: .4byte 0x0201A920
_080108E0:
	ldr r0, _08010908 @ =0x0201AD20
	str r0, [r6]
	mov r2, r8
	str r2, [r6, #4]
_080108E8:
	str r4, [r6, #8]
	ldr r0, [r6, #8]
	adds r0, r7, #0
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x20
	bls _080108A8
	bl sub_D74
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010908: .4byte 0x0201AD20

	thumb_func_start sub_1090C
sub_1090C: @ 0x0801090C
	ldr r1, _08010920 @ =0x0201A500
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xc
_08010914:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08010914
	bx lr
	.align 2, 0
_08010920: .4byte 0x0201A500
