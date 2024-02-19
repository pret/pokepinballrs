	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_F8B0
sub_F8B0: @ 0x0800F8B0
	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	cmp r0, #0
	beq _0800F8BC
	b _0800F9CC
_0800F8BC:
	cmp r1, #0
	bne _0800F93C
	ldr r0, _0800F924 @ =gUnknown_03005C00
	ldr r7, _0800F928 @ =0x000090EA
	ldr r6, _0800F92C @ =0x0000912A
	ldr r1, _0800F930 @ =gUnknown_086A7FA4
	adds r2, r0, #0
	adds r2, #0x98
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800F8D4:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F8E8
	cmp r0, r6
	beq _0800F8E8
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800F8E8:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F8D4
	ldr r0, _0800F924 @ =gUnknown_03005C00
	ldr r7, _0800F934 @ =0x0000910A
	ldr r6, _0800F938 @ =0x0000914A
	ldr r1, _0800F930 @ =gUnknown_086A7FA4
	adds r3, r0, #0
	adds r3, #0xd8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800F904:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F918
	cmp r0, r6
	beq _0800F918
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800F918:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F904
	b _0800FAC2
	.align 2, 0
_0800F924: .4byte gUnknown_03005C00
_0800F928: .4byte 0x000090EA
_0800F92C: .4byte 0x0000912A
_0800F930: .4byte gUnknown_086A7FA4
_0800F934: .4byte 0x0000910A
_0800F938: .4byte 0x0000914A
_0800F93C:
	lsls r1, r1, #1
	adds r0, r1, #3
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	adds r6, r1, #0
	ldr r1, _0800F9B4 @ =gUnknown_03005C00
	ldr r0, _0800F9B8 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800F9BC @ =0x000091AA
	ldr r2, _0800F9C0 @ =gUnknown_086A7FA4
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800F95E:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800F972
	cmp r0, r7
	beq _0800F972
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800F972:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F95E
	adds r0, r6, #4
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	ldr r1, _0800F9B4 @ =gUnknown_03005C00
	ldr r7, _0800F9C4 @ =0x0000918A
	ldr r6, _0800F9C8 @ =0x000091CA
	ldr r2, _0800F9C0 @ =gUnknown_086A7FA4
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800F996:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800F9AA
	cmp r0, r6
	beq _0800F9AA
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800F9AA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F996
	b _0800FAC2
	.align 2, 0
_0800F9B4: .4byte gUnknown_03005C00
_0800F9B8: .4byte 0x0000916A
_0800F9BC: .4byte 0x000091AA
_0800F9C0: .4byte gUnknown_086A7FA4
_0800F9C4: .4byte 0x0000918A
_0800F9C8: .4byte 0x000091CA
_0800F9CC:
	cmp r1, #0
	bne _0800FA54
	ldr r0, _0800FA34 @ =gUnknown_03005C00
	ldr r7, _0800FA38 @ =0x000090EA
	ldr r6, _0800FA3C @ =0x0000912A
	ldr r1, _0800FA40 @ =gUnknown_086A7FA4
	ldr r3, _0800FA44 @ =0x00000894
	adds r2, r0, r3
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800F9E4:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F9F8
	cmp r0, r6
	beq _0800F9F8
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800F9F8:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F9E4
	ldr r0, _0800FA34 @ =gUnknown_03005C00
	ldr r7, _0800FA48 @ =0x0000910A
	ldr r6, _0800FA4C @ =0x0000914A
	ldr r1, _0800FA40 @ =gUnknown_086A7FA4
	ldr r4, _0800FA50 @ =0x000008D4
	adds r3, r0, r4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FA14:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FA28
	cmp r0, r6
	beq _0800FA28
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FA28:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FA14
	b _0800FAC2
	.align 2, 0
_0800FA34: .4byte gUnknown_03005C00
_0800FA38: .4byte 0x000090EA
_0800FA3C: .4byte 0x0000912A
_0800FA40: .4byte gUnknown_086A7FA4
_0800FA44: .4byte 0x00000894
_0800FA48: .4byte 0x0000910A
_0800FA4C: .4byte 0x0000914A
_0800FA50: .4byte 0x000008D4
_0800FA54:
	lsls r0, r1, #1
	lsls r3, r0, #6
	adds r6, r0, #0
	ldr r1, _0800FAC8 @ =gUnknown_03005C00
	ldr r0, _0800FACC @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FAD0 @ =0x000091AA
	ldr r2, _0800FAD4 @ =gUnknown_086A7FA4
	ldr r4, _0800FAD8 @ =0x000008D4
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FA72:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FA86
	cmp r0, r7
	beq _0800FA86
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FA86:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FA72
	lsls r3, r6, #6
	ldr r1, _0800FAC8 @ =gUnknown_03005C00
	ldr r7, _0800FADC @ =0x0000918A
	ldr r6, _0800FAE0 @ =0x000091CA
	ldr r2, _0800FAD4 @ =gUnknown_086A7FA4
	ldr r4, _0800FAE4 @ =0x00000914
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FAA6:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FABA
	cmp r0, r6
	beq _0800FABA
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FABA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FAA6
_0800FAC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FAC8: .4byte gUnknown_03005C00
_0800FACC: .4byte 0x0000916A
_0800FAD0: .4byte 0x000091AA
_0800FAD4: .4byte gUnknown_086A7FA4
_0800FAD8: .4byte 0x000008D4
_0800FADC: .4byte 0x0000918A
_0800FAE0: .4byte 0x000091CA
_0800FAE4: .4byte 0x00000914

	thumb_func_start sub_FAE8
sub_FAE8: @ 0x0800FAE8
	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	cmp r0, #0
	beq _0800FAF4
	b _0800FC04
_0800FAF4:
	cmp r1, #0
	bne _0800FB74
	ldr r0, _0800FB5C @ =gUnknown_03005C00
	ldr r7, _0800FB60 @ =0x000090EA
	ldr r6, _0800FB64 @ =0x0000912A
	ldr r1, _0800FB68 @ =gUnknown_086A7FA8
	adds r2, r0, #0
	adds r2, #0x98
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800FB0C:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FB20
	cmp r0, r6
	beq _0800FB20
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800FB20:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB0C
	ldr r0, _0800FB5C @ =gUnknown_03005C00
	ldr r7, _0800FB6C @ =0x0000910A
	ldr r6, _0800FB70 @ =0x0000914A
	ldr r1, _0800FB68 @ =gUnknown_086A7FA8
	adds r3, r0, #0
	adds r3, #0xd8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FB3C:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FB50
	cmp r0, r6
	beq _0800FB50
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FB50:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB3C
	b _0800FCFA
	.align 2, 0
_0800FB5C: .4byte gUnknown_03005C00
_0800FB60: .4byte 0x000090EA
_0800FB64: .4byte 0x0000912A
_0800FB68: .4byte gUnknown_086A7FA8
_0800FB6C: .4byte 0x0000910A
_0800FB70: .4byte 0x0000914A
_0800FB74:
	lsls r1, r1, #1
	adds r0, r1, #3
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	adds r6, r1, #0
	ldr r1, _0800FBEC @ =gUnknown_03005C00
	ldr r0, _0800FBF0 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FBF4 @ =0x000091AA
	ldr r2, _0800FBF8 @ =gUnknown_086A7FA8
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FB96:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FBAA
	cmp r0, r7
	beq _0800FBAA
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FBAA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB96
	adds r0, r6, #4
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	ldr r1, _0800FBEC @ =gUnknown_03005C00
	ldr r7, _0800FBFC @ =0x0000918A
	ldr r6, _0800FC00 @ =0x000091CA
	ldr r2, _0800FBF8 @ =gUnknown_086A7FA8
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FBCE:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FBE2
	cmp r0, r6
	beq _0800FBE2
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FBE2:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FBCE
	b _0800FCFA
	.align 2, 0
_0800FBEC: .4byte gUnknown_03005C00
_0800FBF0: .4byte 0x0000916A
_0800FBF4: .4byte 0x000091AA
_0800FBF8: .4byte gUnknown_086A7FA8
_0800FBFC: .4byte 0x0000918A
_0800FC00: .4byte 0x000091CA
_0800FC04:
	cmp r1, #0
	bne _0800FC8C
	ldr r0, _0800FC6C @ =gUnknown_03005C00
	ldr r7, _0800FC70 @ =0x000090EA
	ldr r6, _0800FC74 @ =0x0000912A
	ldr r1, _0800FC78 @ =gUnknown_086A7FA8
	ldr r3, _0800FC7C @ =0x00000894
	adds r2, r0, r3
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800FC1C:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FC30
	cmp r0, r6
	beq _0800FC30
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800FC30:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FC1C
	ldr r0, _0800FC6C @ =gUnknown_03005C00
	ldr r7, _0800FC80 @ =0x0000910A
	ldr r6, _0800FC84 @ =0x0000914A
	ldr r1, _0800FC78 @ =gUnknown_086A7FA8
	ldr r4, _0800FC88 @ =0x000008D4
	adds r3, r0, r4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FC4C:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FC60
	cmp r0, r6
	beq _0800FC60
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FC60:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FC4C
	b _0800FCFA
	.align 2, 0
_0800FC6C: .4byte gUnknown_03005C00
_0800FC70: .4byte 0x000090EA
_0800FC74: .4byte 0x0000912A
_0800FC78: .4byte gUnknown_086A7FA8
_0800FC7C: .4byte 0x00000894
_0800FC80: .4byte 0x0000910A
_0800FC84: .4byte 0x0000914A
_0800FC88: .4byte 0x000008D4
_0800FC8C:
	lsls r0, r1, #1
	lsls r3, r0, #6
	adds r6, r0, #0
	ldr r1, _0800FD00 @ =gUnknown_03005C00
	ldr r0, _0800FD04 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FD08 @ =0x000091AA
	ldr r2, _0800FD0C @ =gUnknown_086A7FA8
	ldr r4, _0800FD10 @ =0x000008D4
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FCAA:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FCBE
	cmp r0, r7
	beq _0800FCBE
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FCBE:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FCAA
	lsls r3, r6, #6
	ldr r1, _0800FD00 @ =gUnknown_03005C00
	ldr r7, _0800FD14 @ =0x0000918A
	ldr r6, _0800FD18 @ =0x000091CA
	ldr r2, _0800FD0C @ =gUnknown_086A7FA8
	ldr r4, _0800FD1C @ =0x00000914
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FCDE:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FCF2
	cmp r0, r6
	beq _0800FCF2
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FCF2:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FCDE
_0800FCFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD00: .4byte gUnknown_03005C00
_0800FD04: .4byte 0x0000916A
_0800FD08: .4byte 0x000091AA
_0800FD0C: .4byte gUnknown_086A7FA8
_0800FD10: .4byte 0x000008D4
_0800FD14: .4byte 0x0000918A
_0800FD18: .4byte 0x000091CA
_0800FD1C: .4byte 0x00000914

	thumb_func_start sub_FD20
sub_FD20: @ 0x0800FD20
	sub sp, #0x19c
	movs r2, #0
	ldr r3, _0800FD48 @ =gMain+0x74
	mov r1, sp
_0800FD28:
	adds r0, r2, r3
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0xcc
	ble _0800FD28
	movs r2, #0
	mov r1, sp
_0800FD3A:
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #4
	beq _0800FD4C
	movs r0, #0
	b _0800FD56
	.align 2, 0
_0800FD48: .4byte gMain+0x74
_0800FD4C:
	adds r1, #2
	adds r2, #1
	cmp r2, #0xc8
	ble _0800FD3A
	movs r0, #1
_0800FD56:
	add sp, #0x19c
	bx lr

	thumb_func_start sub_FD5C
sub_FD5C: @ 0x0800FD5C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r4, _0800FDC8 @ =0x040000D4
	movs r6, #0xa0
	lsls r6, r6, #0x13
	str r6, [r4]
	ldr r2, _0800FDCC @ =gUnknown_0201A920
	str r2, [r4, #4]
	ldr r5, _0800FDD0 @ =0x80000200
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sp
	ldr r3, _0800FDD4 @ =0x00007FFF
	adds r0, r3, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _0800FDD8 @ =0xFFFFFC00
	adds r1, r2, r0
	str r1, [r4, #4]
	ldr r0, _0800FDDC @ =0x81000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r1, [r4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r2, r3
	str r2, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	str r2, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_1050C
	movs r7, #0
_0800FDAA:
	mov r0, r8
	cmp r0, #0
	beq _0800FDB4
	bl _call_via_r8
_0800FDB4:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FDE0
	ldr r0, _0800FDCC @ =gUnknown_0201A920
	b _0800FDE2
	.align 2, 0
_0800FDC8: .4byte 0x040000D4
_0800FDCC: .4byte gUnknown_0201A920
_0800FDD0: .4byte 0x80000200
_0800FDD4: .4byte 0x00007FFF
_0800FDD8: .4byte 0xFFFFFC00
_0800FDDC: .4byte 0x81000200
_0800FDE0:
	ldr r0, _0800FE00 @ =gUnknown_0201AD20
_0800FDE2:
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FDAA
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE00: .4byte gUnknown_0201AD20

	thumb_func_start sub_FE04
sub_FE04: @ 0x0800FE04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FE6C @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov r8, r0
	str r0, [r1]
	ldr r3, _0800FE70 @ =gUnknown_0201A520
	str r3, [r1, #4]
	ldr r4, _0800FE74 @ =0x80000200
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sp
	ldr r6, _0800FE78 @ =0x00007FFF
	adds r0, r6, #0
	strh r0, [r2]
	str r2, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r3, r2
	str r0, [r1, #4]
	ldr r0, _0800FE7C @ =0x81000200
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
_0800FE4C:
	cmp r5, #0
	beq _0800FE54
	bl _call_via_r5
_0800FE54:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FE84
	ldr r0, _0800FE80 @ =gUnknown_0201A920
	str r0, [r6]
	mov r0, r8
	str r0, [r6, #4]
	b _0800FE8C
	.align 2, 0
_0800FE6C: .4byte 0x040000D4
_0800FE70: .4byte gUnknown_0201A520
_0800FE74: .4byte 0x80000200
_0800FE78: .4byte 0x00007FFF
_0800FE7C: .4byte 0x81000200
_0800FE80: .4byte gUnknown_0201A920
_0800FE84:
	ldr r0, _0800FEB4 @ =gUnknown_0201AD20
	str r0, [r6]
	mov r2, r8
	str r2, [r6, #4]
_0800FE8C:
	str r4, [r6, #8]
	ldr r0, [r6, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FE4C
	bl sub_10528
	bl MainLoopIter
	bl ClearGraphicsMemory
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FEB4: .4byte gUnknown_0201AD20

	thumb_func_start sub_FEB8
sub_FEB8: @ 0x0800FEB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r2
	ldr r4, _0800FF34 @ =0x040000D4
	str r0, [r4]
	ldr r2, _0800FF38 @ =gUnknown_0201A920
	str r2, [r4, #4]
	ldr r0, _0800FF3C @ =0x80000100
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
	movs r0, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _0800FF40 @ =0xFFFFFC00
	adds r2, r2, r0
	str r2, [r4, #4]
	ldr r0, _0800FF44 @ =0x81000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r2, [r4]
	str r3, [r4, #4]
	ldr r5, _0800FF48 @ =0x80000200
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	str r3, [r4]
	movs r6, #0xa0
	lsls r6, r6, #0x13
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_1050C
	ldr r1, _0800FF4C @ =gMain
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r0, [r0]
	strh r0, [r1, #0x16]
	movs r7, #0
_0800FF18:
	mov r1, r8
	cmp r1, #0
	beq _0800FF22
	bl _call_via_r8
_0800FF22:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FF50
	ldr r0, _0800FF38 @ =gUnknown_0201A920
	b _0800FF52
	.align 2, 0
_0800FF34: .4byte 0x040000D4
_0800FF38: .4byte gUnknown_0201A920
_0800FF3C: .4byte 0x80000100
_0800FF40: .4byte 0xFFFFFC00
_0800FF44: .4byte 0x81000200
_0800FF48: .4byte 0x80000200
_0800FF4C: .4byte gMain
_0800FF50:
	ldr r0, _0800FF70 @ =gUnknown_0201AD20
_0800FF52:
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FF18
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FF70: .4byte gUnknown_0201AD20

	thumb_func_start sub_FF74
sub_FF74: @ 0x0800FF74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FFDC @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov r8, r0
	str r0, [r1]
	ldr r3, _0800FFE0 @ =gUnknown_0201A520
	str r3, [r1, #4]
	ldr r4, _0800FFE4 @ =0x80000200
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sp
	movs r0, #0
	strh r0, [r2]
	str r2, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r3, r2
	str r0, [r1, #4]
	ldr r0, _0800FFE8 @ =0x81000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r3, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r3, r0
	str r3, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	adds r6, r1, #0
_0800FFBA:
	cmp r5, #0
	beq _0800FFC2
	bl _call_via_r5
_0800FFC2:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FFF0
	ldr r0, _0800FFEC @ =gUnknown_0201A920
	str r0, [r6]
	mov r2, r8
	str r2, [r6, #4]
	b _0800FFF8
	.align 2, 0
_0800FFDC: .4byte 0x040000D4
_0800FFE0: .4byte gUnknown_0201A520
_0800FFE4: .4byte 0x80000200
_0800FFE8: .4byte 0x81000200
_0800FFEC: .4byte gUnknown_0201A920
_0800FFF0:
	ldr r0, _08010018 @ =gUnknown_0201AD20
	str r0, [r6]
	mov r0, r8
	str r0, [r6, #4]
_0800FFF8:
	str r4, [r6, #8]
	ldr r0, [r6, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FFBA
	bl MainLoopIter
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010018: .4byte gUnknown_0201AD20

	thumb_func_start sub_1001C
sub_1001C: @ 0x0801001C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	add r1, sp, #0xc
	movs r0, #0
	strh r0, [r1]
	movs r0, #2
	strh r0, [r1, #2]
	movs r0, #1
	strh r0, [r1, #4]
	movs r2, #3
	strh r2, [r1, #6]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #0x17
	lsrs r1, r0, #0x10
	mov ip, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _080100D8 @ =0x0000FFFC
	ands r7, r0
	adds r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp ip, r8
	bhs _08010160
	add r5, sp, #8
	ldr r0, _080100DC @ =gUnknown_0201A520
	mov sb, r0
	add r4, sp, #4
	mov r6, sp
	movs r1, #0xf8
	lsls r1, r1, #7
	mov sl, r1
_08010076:
	mov r0, ip
	lsls r3, r0, #1
	mov r1, sb
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6, #2]
	ldrh r1, [r6]
	cmp r1, r0
	bhs _080100E0
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r6]
	b _080100EE
	.align 2, 0
_080100D8: .4byte 0x0000FFFC
_080100DC: .4byte gUnknown_0201A520
_080100E0:
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r6]
_080100EE:
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bhs _08010106
	ldrh r0, [r4, #2]
	ldrh r1, [r4]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r4]
	b _08010114
_08010106:
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r4]
_08010114:
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bhs _0801012C
	ldrh r0, [r5, #2]
	ldrh r1, [r5]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5]
	b _0801013A
_0801012C:
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r5]
_0801013A:
	movs r2, #0x80
	lsls r2, r2, #4
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, r8
	blo _08010076
_08010160:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_10170
sub_10170: @ 0x08010170
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r1, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	mov r8, r1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov ip, r3
	ldr r1, _08010298 @ =0x040000D4
	str r0, [r1]
	ldr r4, _0801029C @ =gUnknown_0201A520
	str r4, [r1, #4]
	lsrs r2, r2, #0x11
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r3, sp, #0xc
	movs r0, #0
	strh r0, [r3]
	str r3, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r3, r4, r0
	str r3, [r1, #4]
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	cmp r7, r8
	bhs _08010270
	add r5, sp, #8
	add r4, sp, #4
	movs r1, #0xf8
	lsls r1, r1, #2
	mov sl, r1
	mov r6, sp
	movs r0, #0xf8
	lsls r0, r0, #7
	mov sb, r0
_080101D0:
	lsls r3, r7, #1
	ldr r1, _0801029C @ =gUnknown_0201A520
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	ldr r0, _080102A0 @ =gUnknown_0201A920
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	lsrs r1, r0, #0xa
	strh r1, [r6, #2]
	ldrh r0, [r6]
	cmp r0, r1
	bls _08010222
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_08010222:
	strh r1, [r6]
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bls _08010236
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_08010236:
	strh r1, [r4]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bls _0801024A
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_0801024A:
	strh r1, [r5]
	ldr r1, _0801029C @ =gUnknown_0201A520
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r1, r0
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, r8
	blo _080101D0
_08010270:
	ldr r2, _08010298 @ =0x040000D4
	ldr r1, _080102A4 @ =gUnknown_0201AD20
	str r1, [r2]
	ldr r0, [sp, #0x10]
	str r0, [r2, #4]
	mov r1, r8
	lsrs r0, r1, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010298: .4byte 0x040000D4
_0801029C: .4byte gUnknown_0201A520
_080102A0: .4byte gUnknown_0201A920
_080102A4: .4byte gUnknown_0201AD20

	thumb_func_start sub_102A8
sub_102A8: @ 0x080102A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r1, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	mov r8, r1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r1, _08010368 @ =0x040000D4
	str r0, [r1]
	ldr r4, _0801036C @ =gUnknown_0201A520
	str r4, [r1, #4]
	lsrs r2, r2, #0x11
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r3, sp, #0xc
	ldr r5, _08010370 @ =0x00007FFF
	adds r0, r5, #0
	strh r0, [r3]
	str r3, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r4, r3
	str r0, [r1, #4]
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0
	mov ip, r5
	cmp ip, r8
	bhs _080103F4
	add r5, sp, #8
	mov sb, r4
	add r4, sp, #4
	mov r6, sp
	movs r0, #0xf8
	lsls r0, r0, #7
	mov sl, r0
_08010306:
	mov r1, ip
	lsls r3, r1, #1
	mov r0, sb
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6, #2]
	ldrh r1, [r6]
	cmp r1, r0
	bhs _08010374
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r6]
	b _08010382
	.align 2, 0
_08010368: .4byte 0x040000D4
_0801036C: .4byte gUnknown_0201A520
_08010370: .4byte 0x00007FFF
_08010374:
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r6]
_08010382:
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bhs _0801039A
	ldrh r0, [r4, #2]
	ldrh r1, [r4]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r4]
	b _080103A8
_0801039A:
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r4]
_080103A8:
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bhs _080103C0
	ldrh r0, [r5, #2]
	ldrh r1, [r5]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5]
	b _080103CE
_080103C0:
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r5]
_080103CE:
	movs r2, #0x80
	lsls r2, r2, #4
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, r8
	blo _08010306
_080103F4:
	ldr r2, _0801041C @ =0x040000D4
	ldr r1, _08010420 @ =gUnknown_0201AD20
	str r1, [r2]
	ldr r3, [sp, #0x10]
	str r3, [r2, #4]
	mov r5, r8
	lsrs r0, r5, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801041C: .4byte 0x040000D4
_08010420: .4byte gUnknown_0201AD20

	thumb_func_start sub_10424
sub_10424: @ 0x08010424
	push {r4, r5, r6, lr}
	ldr r4, _08010470 @ =0x04000054
	movs r3, #0x10
	strh r3, [r4]
	ldr r6, _08010474 @ =0x04000050
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r6]
	ldrh r1, [r2]
	ldr r0, _08010478 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0801047C @ =gMain
	ldrh r0, [r2]
	movs r5, #0
	strh r0, [r1, #0x16]
	strh r3, [r4]
	bl MainLoopIter
	movs r0, #8
	strh r0, [r4]
	bl MainLoopIter
	strh r5, [r4]
	bl MainLoopIter
	strh r5, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010470: .4byte 0x04000054
_08010474: .4byte 0x04000050
_08010478: .4byte 0x0000FF7F
_0801047C: .4byte gMain

	thumb_func_start sub_10480
sub_10480: @ 0x08010480
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, _080104F8 @ =0x04000054
	movs r4, #0
	strh r4, [r5]
	ldr r2, _080104FC @ =0x04000050
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	bl MainLoopIter
	movs r0, #8
	strh r0, [r5]
	bl MainLoopIter
	movs r0, #0x10
	strh r0, [r5]
	bl MainLoopIter
	mov r0, sp
	strh r4, [r0]
	ldr r1, _08010500 @ =0x040000D4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08010504 @ =0x8100C000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08010508 @ =0x04000010
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	bl MainLoopIter
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080104F8: .4byte 0x04000054
_080104FC: .4byte 0x04000050
_08010500: .4byte 0x040000D4
_08010504: .4byte 0x8100C000
_08010508: .4byte 0x04000010

	thumb_func_start sub_1050C
sub_1050C: @ 0x0801050C
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _08010520 @ =0x0000FF7F
	ands r0, r2
	strh r0, [r1]
	ldr r2, _08010524 @ =gMain
	ldrh r0, [r1]
	strh r0, [r2, #0x16]
	bx lr
	.align 2, 0
_08010520: .4byte 0x0000FF7F
_08010524: .4byte gMain

	thumb_func_start sub_10528
sub_10528: @ 0x08010528
	ldr r1, _08010540 @ =gMain
	ldrh r0, [r1, #0x16]
	movs r2, #0x80
	orrs r0, r2
	strh r0, [r1, #0x16]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08010540: .4byte gMain

	thumb_func_start sub_10544
sub_10544: @ 0x08010544
	ldr r1, _08010580 @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _08010584 @ =0x0000FFF7
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08010588 @ =0x0000FFDF
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0801058C @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _08010590 @ =0x00003FFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08010594 @ =0x00003FFE
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	bne _08010574
	ldr r0, _08010598 @ =0x04000208
	strh r1, [r0]
_08010574:
	ldr r0, _0801059C @ =0x04000202
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08010580: .4byte 0x04000004
_08010584: .4byte 0x0000FFF7
_08010588: .4byte 0x0000FFDF
_0801058C: .4byte 0x04000200
_08010590: .4byte 0x00003FFF
_08010594: .4byte 0x00003FFE
_08010598: .4byte 0x04000208
_0801059C: .4byte 0x04000202

	thumb_func_start sub_105A0
sub_105A0: @ 0x080105A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	mov ip, r4
	ldr r4, [sp, #0x28]
	mov sb, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	movs r1, #0
	cmp r1, sb
	bge _08010602
	lsls r0, r3, #5
	adds r0, r0, r2
	mov r8, r0
_080105CC:
	movs r2, #0
	adds r6, r1, #1
	cmp r2, ip
	bge _080105FA
	ldr r7, _08010614 @ =gUnknown_03005C00
	lsls r0, r1, #5
	mov r1, r8
	adds r5, r1, r0
	ldr r1, [sp]
	adds r4, r1, r0
	mov r0, sl
	lsls r3, r0, #0xc
_080105E4:
	adds r0, r5, r2
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r1, r2, r4
	orrs r1, r3
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, ip
	blt _080105E4
_080105FA:
	lsls r0, r6, #0x10
	lsrs r1, r0, #0x10
	cmp r1, sb
	blt _080105CC
_08010602:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010614: .4byte gUnknown_03005C00
