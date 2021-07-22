	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_2990
sub_2990: @ 0x08002990
	push {lr}
	ldr r0, _080029BC @ =sub_29C8 + 1
	bl sub_FE04
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _080029C0 @ =gAutoDisplayTitlescreenMenu
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080029C4 @ =gUnknown_0202BEE4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_080029BC: .4byte sub_29C8 + 1
_080029C0: .4byte gAutoDisplayTitlescreenMenu
_080029C4: .4byte gUnknown_0202BEE4

	thumb_func_start sub_29C8
sub_29C8: @ 0x080029C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r1, _08002C14 @ =gMain
	ldrh r0, [r1, #0x38]
	ldr r0, _08002C18 @ =0x00000C14
	strh r0, [r1, #0x38]
	ldrh r0, [r1, #0x3a]
	ldr r0, _08002C1C @ =0x00000808
	strh r0, [r1, #0x3a]
	ldr r2, _08002C20 @ =0x04000050
	ldrh r0, [r1, #0x38]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0x3a]
	strh r0, [r2]
	ldr r7, _08002C24 @ =gUnknown_0201A4F8
	movs r0, #0xe9
	lsls r0, r0, #3
	adds r3, r1, r0
	ldr r4, _08002C28 @ =gUnknown_0201A4C0
	ldr r5, _08002C2C @ =gUnknown_0201A4F4
	ldr r2, _08002C30 @ =gUnknown_0201A4B0
	mov sb, r2
	ldr r0, _08002C34 @ =gUnknown_086A4C80
	mov ip, r0
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r1, r2
	add r0, sp, #0x14
_08002A0A:
	str r1, [r0]
	subs r1, #0xb8
	subs r0, #4
	cmp r0, sp	 @ warning: use of r13 is deprecated
	bge _08002A0A
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #0xb8
	muls r0, r2, r0
	adds r0, r0, r3
	mov sl, r0
	ldrb r1, [r4]
	lsls r1, r1, #1
	movs r4, #0
	ldrsh r0, [r5, r4]
	adds r0, #0xc
	adds r1, r1, r0
	muls r1, r2, r1
	ldr r2, _08002C38 @ =0xFFFFFBB0
	adds r0, r3, r2
	adds r1, r1, r0
	mov r8, r1
	movs r2, #1
	mov r1, sp
	movs r6, #5
_08002A3C:
	ldm r1!, {r0}
	strh r2, [r0]
	subs r6, #1
	cmp r6, #0
	bge _08002A3C
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	mov r3, sl
	strh r0, [r3]
	mov r4, sb
	movs r0, #0
	ldrsb r0, [r4, r0]
	mov r7, r8
	strh r0, [r7]
	mov r0, ip
	movs r1, #0x10
	ldr r2, _08002C3C @ =gUnknown_0200B3B8
	bl LoadSpriteSets
	movs r1, #0
_08002A70:
	lsls r2, r1, #2
	mov r0, sp
	adds r4, r0, r2
	ldr r3, [r4]
	ldrh r0, [r3]
	adds r1, #1
	mov sb, r1
	cmp r0, #1
	bne _08002AEC
	ldr r1, _08002C40 @ =gUnknown_086A4CC0
	adds r1, r2, r1
	ldrh r0, [r1]
	strh r0, [r3, #2]
	ldr r2, [r4]
	ldrh r0, [r1, #2]
	strh r0, [r2, #4]
	adds r5, r4, #0
	ldr r1, _08002C44 @ =gOamBuffer
	mov ip, r1
	movs r7, #8
	movs r6, #3
_08002A9A:
	ldr r4, [r5]
	adds r4, r4, r7
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r4, r3]
	ldr r0, [r5]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _08002C48 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08002C4C @ =0xFFFFFE00
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
	adds r7, #8
	subs r6, #1
	cmp r6, #0
	bge _08002A9A
_08002AEC:
	mov r1, sb
	cmp r1, #5
	ble _08002A70
	movs r0, #0x58
	mov r4, sl
	strh r0, [r4, #2]
	movs r0, #0x85
	strh r0, [r4, #4]
	ldr r5, _08002C44 @ =gOamBuffer
	movs r7, #0xd
	rsbs r7, r7, #0
	mov sb, r7
	ldr r0, _08002C4C @ =0xFFFFFE00
	mov ip, r0
	adds r4, #8
	movs r6, #1
_08002B0C:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldr r3, _08002C50 @ =gUnknown_0202BEE8
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r3, [r2, #5]
	movs r0, #0xf
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08002C48 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08002B0C
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _08002BEA
	ldr r2, _08002C54 @ =gUnknown_086A4CD8
	ldr r1, _08002C24 @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	ldr r5, _08002C44 @ =gOamBuffer
	movs r4, #0xd
	rsbs r4, r4, #0
	mov sb, r4
	ldr r7, _08002C4C @ =0xFFFFFE00
	mov ip, r7
	mov r4, r8
	adds r4, #8
	movs r6, #4
_08002BA2:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08002C48 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08002BA2
_08002BEA:
	movs r2, #0
	mov r1, sp
	movs r6, #5
_08002BF0:
	ldm r1!, {r0}
	strh r2, [r0]
	subs r6, #1
	cmp r6, #0
	bge _08002BF0
	movs r0, #0
	mov r1, sl
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002C14: .4byte gMain
_08002C18: .4byte 0x00000C14
_08002C1C: .4byte 0x00000808
_08002C20: .4byte 0x04000050
_08002C24: .4byte gUnknown_0201A4F8
_08002C28: .4byte gUnknown_0201A4C0
_08002C2C: .4byte gUnknown_0201A4F4
_08002C30: .4byte gUnknown_0201A4B0
_08002C34: .4byte gUnknown_086A4C80
_08002C38: .4byte 0xFFFFFBB0
_08002C3C: .4byte gUnknown_0200B3B8
_08002C40: .4byte gUnknown_086A4CC0
_08002C44: .4byte gOamBuffer
_08002C48: .4byte 0x000001FF
_08002C4C: .4byte 0xFFFFFE00
_08002C50: .4byte gUnknown_0202BEE8
_08002C54: .4byte gUnknown_086A4CD8
