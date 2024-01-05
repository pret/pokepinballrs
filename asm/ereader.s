	.include "asm/macros.inc"

	.syntax unified

	.text

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
