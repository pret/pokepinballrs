	.include "asm/macros.inc"

	.syntax unified

	.text

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
	ldr r4, _080024CC @ =gOamBuffer
	movs r7, #0
	ldr r0, _080024D0 @ =gEmptyOamData
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
	ldr r4, _080024CC @ =gOamBuffer
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
_080024CC: .4byte gOamBuffer
_080024D0: .4byte gEmptyOamData
_080024D4: .4byte 0x000001FF
