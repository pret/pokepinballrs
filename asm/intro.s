	.include "asm/macros.inc"

	.syntax unified

	.text

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
