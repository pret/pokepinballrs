	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_394C
sub_394C: @ 0x0800394C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080039A0 @ =gUnknown_0202A58C
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	ldr r2, _080039A4 @ =gUnknown_0200B3B8
	adds r7, r0, r2
	ldr r0, _080039A8 @ =gUnknown_0202BEC0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _080039AC @ =gUnknown_0202C584
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r7]
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	ldr r0, _080039B0 @ =gUnknown_086A54D8
	movs r1, #0xd
	bl LoadSpriteSets
	ldrh r0, [r7]
	cmp r0, #1
	bne _08003A18
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080039B4
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x64
	b _080039BA
	.align 2, 0
_080039A0: .4byte gUnknown_0202A58C
_080039A4: .4byte gUnknown_0200B3B8
_080039A8: .4byte gUnknown_0202BEC0
_080039AC: .4byte gUnknown_0202C584
_080039B0: .4byte gUnknown_086A54D8
_080039B4:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x50
_080039BA:
	strh r0, [r7, #4]
	ldr r1, _08003A9C @ =gUnknown_086A54D8
	ldr r0, _08003AA0 @ =gUnknown_0202A58C
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r2, [r6]
	cmp r5, r2
	bge _08003A18
	ldr r0, _08003AA4 @ =gOamBuffer
	mov ip, r0
	ldr r1, _08003AA8 @ =0xFFFFFE00
	mov sb, r1
	adds r4, r7, #0
	adds r4, #8
_080039E0:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, ip
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08003AAC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _080039E0
_08003A18:
	movs r0, #0x78
	mov r1, r8
	strh r0, [r1, #2]
	movs r0, #0x18
	strh r0, [r1, #4]
	ldr r1, _08003A9C @ =gUnknown_086A54D8
	ldr r0, _08003AB0 @ =gUnknown_0202BEC0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r2, [r6]
	cmp r5, r2
	bge _08003A86
	ldr r0, _08003AA4 @ =gOamBuffer
	mov ip, r0
	ldr r1, _08003AA8 @ =0xFFFFFE00
	mov sb, r1
	mov r4, r8
	adds r4, #8
_08003A46:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, ip
	movs r0, #2
	ldrsh r2, [r4, r0]
	mov sl, r2
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	mov r2, sl
	adds r1, r2, r0
	ldr r2, _08003AAC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _08003A46
_08003A86:
	movs r0, #0
	strh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003A9C: .4byte gUnknown_086A54D8
_08003AA0: .4byte gUnknown_0202A58C
_08003AA4: .4byte gOamBuffer
_08003AA8: .4byte 0xFFFFFE00
_08003AAC: .4byte 0x000001FF
_08003AB0: .4byte gUnknown_0202BEC0

	thumb_func_start sub_3AB4
sub_3AB4: @ 0x08003AB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08003B08 @ =gUnknown_0202A58C
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	ldr r2, _08003B0C @ =gUnknown_0200B3B8
	adds r7, r0, r2
	ldr r0, _08003B10 @ =gUnknown_0202BEC0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _08003B14 @ =gUnknown_0202C584
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r7]
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	ldr r0, _08003B18 @ =gUnknown_086A54D8
	movs r1, #0xd
	bl sub_2414
	ldrh r0, [r7]
	cmp r0, #1
	bne _08003B80
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _08003B1C
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x64
	b _08003B22
	.align 2, 0
_08003B08: .4byte gUnknown_0202A58C
_08003B0C: .4byte gUnknown_0200B3B8
_08003B10: .4byte gUnknown_0202BEC0
_08003B14: .4byte gUnknown_0202C584
_08003B18: .4byte gUnknown_086A54D8
_08003B1C:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x50
_08003B22:
	strh r0, [r7, #4]
	ldr r1, _08003C04 @ =gUnknown_086A54D8
	ldr r0, _08003C08 @ =gUnknown_0202A58C
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r2, [r6]
	cmp r5, r2
	bge _08003B80
	ldr r0, _08003C0C @ =gOamBuffer
	mov ip, r0
	ldr r1, _08003C10 @ =0xFFFFFE00
	mov sb, r1
	adds r4, r7, #0
	adds r4, #8
_08003B48:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, ip
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08003C14 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _08003B48
_08003B80:
	movs r0, #0x78
	mov r1, r8
	strh r0, [r1, #2]
	movs r0, #0x18
	strh r0, [r1, #4]
	ldr r1, _08003C04 @ =gUnknown_086A54D8
	ldr r0, _08003C18 @ =gUnknown_0202BEC0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r2, [r6]
	cmp r5, r2
	bge _08003BEE
	ldr r0, _08003C0C @ =gOamBuffer
	mov ip, r0
	ldr r1, _08003C10 @ =0xFFFFFE00
	mov sb, r1
	mov r4, r8
	adds r4, #8
_08003BAE:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, ip
	movs r0, #2
	ldrsh r2, [r4, r0]
	mov sl, r2
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	mov r2, sl
	adds r1, r2, r0
	ldr r2, _08003C14 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _08003BAE
_08003BEE:
	movs r0, #0
	strh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003C04: .4byte gUnknown_086A54D8
_08003C08: .4byte gUnknown_0202A58C
_08003C0C: .4byte gOamBuffer
_08003C10: .4byte 0xFFFFFE00
_08003C14: .4byte 0x000001FF
_08003C18: .4byte gUnknown_0202BEC0

	thumb_func_start sub_3C1C
sub_3C1C: @ 0x08003C1C
	push {r4, lr}
	ldr r0, _08003C64 @ =gUnknown_0202A564
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08003C68 @ =gUnknown_02019C20
	strb r1, [r0]
	ldr r0, _08003C6C @ =gUnknown_0202ADE8
	strb r1, [r0]
	ldr r1, _08003C70 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08003C34:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08003C34
	movs r1, #0
	ldr r4, _08003C74 @ =gUnknown_0201A4D0
	movs r3, #0
_08003C42:
	lsls r0, r1, #1
	adds r2, r1, #1
	movs r1, #7
	adds r0, r0, r4
	adds r0, #0x1c
_08003C4C:
	strh r3, [r0]
	subs r0, #4
	subs r1, #1
	cmp r1, #0
	bge _08003C4C
	adds r1, r2, #0
	cmp r1, #1
	ble _08003C42
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003C64: .4byte gUnknown_0202A564
_08003C68: .4byte gUnknown_02019C20
_08003C6C: .4byte gUnknown_0202ADE8
_08003C70: .4byte gUnknown_0202C5F0
_08003C74: .4byte gUnknown_0201A4D0

	thumb_func_start sub_3C78
sub_3C78: @ 0x08003C78
	ldr r0, _08003C8C @ =gUnknown_02019C20
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08003C98
	ldr r1, _08003C90 @ =gUnknown_0202C5F0
	ldr r0, _08003C94 @ =0x0000DFDF
	strh r0, [r1]
	b _08003CD0
	.align 2, 0
_08003C8C: .4byte gUnknown_02019C20
_08003C90: .4byte gUnknown_0202C5F0
_08003C94: .4byte 0x0000DFDF
_08003C98:
	ldr r3, _08003CB4 @ =gUnknown_0202ADE8
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08003CC0
	ldr r0, _08003CB8 @ =gUnknown_0202C5F0
	movs r2, #0
	ldr r1, _08003CBC @ =0x0000CDFE
	strh r1, [r0]
	strb r2, [r3]
	b _08003CD0
	.align 2, 0
_08003CB4: .4byte gUnknown_0202ADE8
_08003CB8: .4byte gUnknown_0202C5F0
_08003CBC: .4byte 0x0000CDFE
_08003CC0:
	ldr r1, _08003CD4 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08003CC8:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08003CC8
_08003CD0:
	movs r0, #0
	bx lr
	.align 2, 0
_08003CD4: .4byte gUnknown_0202C5F0

	thumb_func_start sub_3CD8
sub_3CD8: @ 0x08003CD8
	push {r4, lr}
	ldr r0, _08003D24 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	ldr r2, _08003D28 @ =gUnknown_0202A564
	cmp r0, #0
	beq _08003D02
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08003D0A
	movs r0, #1
	rsbs r0, r0, #0
	adds r1, r0, #0
	strb r1, [r2]
	ldr r0, _08003D2C @ =gUnknown_0202ADE8
	strb r1, [r0]
	ldr r1, _08003D30 @ =gUnknown_0202A58C
	movs r0, #1
	strb r0, [r1]
_08003D02:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08003D7A
_08003D0A:
	ldr r3, _08003D34 @ =gUnknown_02019C20
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bne _08003D66
	ldr r1, _08003D38 @ =gUnknown_0201A4D0
	ldrh r0, [r1]
	ldr r2, _08003D3C @ =0x0000FEDC
	cmp r0, r2
	bne _08003D44
	ldr r0, _08003D40 @ =gUnknown_0202BEEC
	ldrh r1, [r1, #4]
	b _08003D4E
	.align 2, 0
_08003D24: .4byte gMain
_08003D28: .4byte gUnknown_0202A564
_08003D2C: .4byte gUnknown_0202ADE8
_08003D30: .4byte gUnknown_0202A58C
_08003D34: .4byte gUnknown_02019C20
_08003D38: .4byte gUnknown_0201A4D0
_08003D3C: .4byte 0x0000FEDC
_08003D40: .4byte gUnknown_0202BEEC
_08003D44:
	ldrh r0, [r1, #2]
	cmp r0, r2
	bne _08003D7A
	ldr r0, _08003D5C @ =gUnknown_0202BEEC
	ldrh r1, [r1, #6]
_08003D4E:
	strh r1, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	strb r0, [r3]
	b _08003D7A
	.align 2, 0
_08003D5C: .4byte gUnknown_0202BEEC
_08003D60:
	movs r0, #1
	rsbs r0, r0, #0
	b _08003D9C
_08003D66:
	movs r1, #0
	ldr r3, _08003DA4 @ =0x0000DFDF
	ldr r2, _08003DA8 @ =gUnknown_0201A4D0
_08003D6C:
	ldrh r0, [r2]
	cmp r0, r3
	beq _08003D60
	adds r2, #2
	adds r1, #1
	cmp r1, #1
	ble _08003D6C
_08003D7A:
	movs r1, #0
	ldr r4, _08003DA8 @ =gUnknown_0201A4D0
	movs r3, #0
_08003D80:
	lsls r0, r1, #1
	adds r2, r1, #1
	movs r1, #7
	adds r0, r0, r4
	adds r0, #0x1c
_08003D8A:
	strh r3, [r0]
	subs r0, #4
	subs r1, #1
	cmp r1, #0
	bge _08003D8A
	adds r1, r2, #0
	cmp r1, #1
	ble _08003D80
	movs r0, #0
_08003D9C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08003DA4: .4byte 0x0000DFDF
_08003DA8: .4byte gUnknown_0201A4D0
