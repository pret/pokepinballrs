	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1157C
sub_1157C: @ 0x0801157C
	push {r4, r5, r6, r7, lr}
	ldr r6, _080115E4 @ =0x086A97AC
	ldr r3, _080115E8 @ =0x020028A2
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	ldr r2, _080115EC @ =gMain
	ldrh r1, [r2, #0x1c]
	movs r0, #0x10
	ands r0, r1
	adds r4, r2, #0
	ldr r7, _080115F0 @ =0x020028A3
	cmp r0, #0
	beq _080115FC
	ldrh r1, [r4, #0x18]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ands r1, r0
	cmp r1, r0
	bne _080115FC
	movs r0, #0x28
	strb r0, [r7]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _080115FC
	movs r0, #0
	strb r0, [r3]
	strb r0, [r7]
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _080115F4 @ =gTitlescreen
	movs r0, #5
	strb r0, [r1, #6]
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _080115F8
	movs r0, #0xb
	b _080115FA
	.align 2, 0
_080115E4: .4byte 0x086A97AC
_080115E8: .4byte 0x020028A2
_080115EC: .4byte gMain
_080115F0: .4byte 0x020028A3
_080115F4: .4byte gTitlescreen
_080115F8:
	movs r0, #0xa
_080115FA:
	strb r0, [r4, #3]
_080115FC:
	ldrh r0, [r4, #0x18]
	ldr r1, _08011638 @ =0x000003FF
	ands r0, r1
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bics r0, r1
	cmp r0, #0
	beq _08011614
	movs r1, #0
	strb r1, [r7]
	ldr r0, _0801163C @ =0x020028A2
	strb r1, [r0]
_08011614:
	ldrb r1, [r7]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	ble _08011630
	subs r0, r1, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08011630
	movs r1, #0
	strb r1, [r7]
	ldr r0, _0801163C @ =0x020028A2
	strb r1, [r0]
_08011630:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011638: .4byte 0x000003FF
_0801163C: .4byte 0x020028A2

	thumb_func_start sub_11640
sub_11640: @ 0x08011640
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08011744 @ =gTitlescreen
	movs r0, #8
	ldrsb r0, [r4, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	ldr r2, _08011748 @ =0x0200B3B8
	adds r7, r0, r2
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	muls r0, r1, r0
	adds r6, r0, r2
	movs r0, #9
	ldrsb r0, [r4, r0]
	strh r0, [r7]
	movs r0, #0x11
	ldrsb r0, [r4, r0]
	strh r0, [r6]
	ldr r5, _0801174C @ =0x086A96E4
	adds r0, r5, #0
	movs r1, #5
	bl sub_358
	ldrh r0, [r7]
	cmp r0, #1
	bne _080116DC
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x66
	strh r0, [r7, #4]
	movs r0, #8
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	mov ip, r0
	movs r5, #0
	ldrh r0, [r0]
	cmp r5, r0
	bge _080116DC
	ldr r1, _08011750 @ =0x03005000
	mov r8, r1
	ldr r2, _08011754 @ =0xFFFFFE00
	mov sb, r2
	adds r4, r7, #0
	adds r4, #8
_080116A2:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08011758 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	mov r0, ip
	ldrh r0, [r0]
	cmp r5, r0
	blt _080116A2
_080116DC:
	ldrh r0, [r6]
	cmp r0, #1
	bne _08011730
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x50
	strh r0, [r6, #4]
	ldr r1, _08011750 @ =0x03005000
	mov r8, r1
	ldr r2, _08011754 @ =0xFFFFFE00
	mov sb, r2
	adds r4, r6, #0
	adds r4, #8
	ldr r0, _08011758 @ =0x000001FF
	mov ip, r0
	movs r5, #1
_080116FC:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	mov r0, ip
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _080116FC
_08011730:
	movs r0, #0
	strh r0, [r7]
	strh r0, [r6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011744: .4byte gTitlescreen
_08011748: .4byte 0x0200B3B8
_0801174C: .4byte 0x086A96E4
_08011750: .4byte 0x03005000
_08011754: .4byte 0xFFFFFE00
_08011758: .4byte 0x000001FF

	thumb_func_start sub_1175C
sub_1175C: @ 0x0801175C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _08011810 @ =gMain
	ldrh r0, [r2, #0x38]
	movs r0, #0x84
	lsls r0, r0, #2
	strh r0, [r2, #0x38]
	ldrh r0, [r2, #0x3a]
	ldr r0, _08011814 @ =0x00000808
	strh r0, [r2, #0x3a]
	ldr r1, _08011818 @ =0x04000050
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	ldr r3, _0801181C @ =gTitlescreen
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r2, r2, r4
	adds r0, r0, r2
	mov sl, r0
	movs r0, #0xc
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov sb, r0
	movs r0, #0xe
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	mov r6, sl
	strh r0, [r6]
	movs r0, #0xd
	ldrsb r0, [r3, r0]
	mov r7, sb
	strh r0, [r7]
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08011820 @ =0x0201C190
	adds r0, r4, #0
	movs r1, #7
	bl sub_358
	ldrh r0, [r6]
	cmp r0, #1
	bne _0801187C
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x66
	strh r0, [r6, #4]
	ldr r4, [r4, #0x18]
	mov ip, r4
	movs r2, #0
	str r2, [sp]
	ldrh r3, [r4]
	cmp r2, r3
	bge _0801187C
	ldr r6, _08011824 @ =0x03005000
	mov r4, sl
	adds r4, #8
	mov r5, ip
_080117F2:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _08011828
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	b _08011838
	.align 2, 0
_08011810: .4byte gMain
_08011814: .4byte 0x00000808
_08011818: .4byte 0x04000050
_0801181C: .4byte gTitlescreen
_08011820: .4byte 0x0201C190
_08011824: .4byte 0x03005000
_08011828:
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #1]
_08011838:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08011950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	adds r5, #8
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	mov r1, ip
	ldrh r1, [r1]
	cmp r0, r1
	blt _080117F2
_0801187C:
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #1
	bne _080118D8
	ldr r2, _08011958 @ =0x086A9684
	ldr r1, _0801195C @ =gTitlescreen
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	mov r5, sb
	adds r5, #8
	ldr r4, _08011960 @ =0x03005000
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _08011950 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r6, sb
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_080118D8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08011930
	ldr r2, _08011964 @ =0x086A9694
	ldr r1, _0801195C @ =gTitlescreen
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _08011960 @ =0x03005000
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r6, _08011950 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011930:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, sb
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011950: .4byte 0x000001FF
_08011954: .4byte 0xFFFFFE00
_08011958: .4byte 0x086A9684
_0801195C: .4byte gTitlescreen
_08011960: .4byte 0x03005000
_08011964: .4byte 0x086A9694

	thumb_func_start sub_11968
sub_11968: @ 0x08011968
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _08011A1C @ =gMain
	ldrh r0, [r2, #0x38]
	movs r0, #0x84
	lsls r0, r0, #2
	strh r0, [r2, #0x38]
	ldrh r0, [r2, #0x3a]
	ldr r0, _08011A20 @ =0x00000808
	strh r0, [r2, #0x3a]
	ldr r1, _08011A24 @ =0x04000050
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	ldr r3, _08011A28 @ =gTitlescreen
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r2, r2, r4
	adds r0, r0, r2
	mov sl, r0
	movs r0, #0xc
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov sb, r0
	movs r0, #0xe
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	mov r6, sl
	strh r0, [r6]
	movs r0, #0xd
	ldrsb r0, [r3, r0]
	mov r7, sb
	strh r0, [r7]
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08011A2C @ =0x0202BE00
	adds r0, r4, #0
	movs r1, #7
	bl sub_358
	ldrh r0, [r6]
	cmp r0, #1
	bne _08011A88
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x66
	strh r0, [r6, #4]
	ldr r4, [r4, #0x18]
	mov ip, r4
	movs r2, #0
	str r2, [sp]
	ldrh r3, [r4]
	cmp r2, r3
	bge _08011A88
	ldr r6, _08011A30 @ =0x03005000
	mov r4, sl
	adds r4, #8
	mov r5, ip
_080119FE:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _08011A34
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	b _08011A44
	.align 2, 0
_08011A1C: .4byte gMain
_08011A20: .4byte 0x00000808
_08011A24: .4byte 0x04000050
_08011A28: .4byte gTitlescreen
_08011A2C: .4byte 0x0202BE00
_08011A30: .4byte 0x03005000
_08011A34:
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #1]
_08011A44:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08011B5C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	adds r5, #8
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	mov r1, ip
	ldrh r1, [r1]
	cmp r0, r1
	blt _080119FE
_08011A88:
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #1
	bne _08011AE4
	ldr r2, _08011B64 @ =0x086A96AC
	ldr r1, _08011B68 @ =gTitlescreen
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	mov r5, sb
	adds r5, #8
	ldr r4, _08011B6C @ =0x03005000
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _08011B5C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r6, sb
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011AE4:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08011B3C
	ldr r2, _08011B70 @ =0x086A96C0
	ldr r1, _08011B68 @ =gTitlescreen
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _08011B6C @ =0x03005000
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r6, _08011B5C @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011B3C:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, sb
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011B5C: .4byte 0x000001FF
_08011B60: .4byte 0xFFFFFE00
_08011B64: .4byte 0x086A96AC
_08011B68: .4byte gTitlescreen
_08011B6C: .4byte 0x03005000
_08011B70: .4byte 0x086A96C0

	thumb_func_start sub_11B74
sub_11B74: @ 0x08011B74
	push {lr}
	bl sub_52C64
	bl sub_52B30
	ldr r0, _08011B94 @ =gMain
	movs r1, #0
	str r1, [r0, #0x40]
	adds r0, #0x40
	ldr r1, _08011B98 @ =0x0E000544
	movs r2, #4
	bl sub_55654
	pop {r0}
	bx r0
	.align 2, 0
_08011B94: .4byte gMain
_08011B98: .4byte 0x0E000544
