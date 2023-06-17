	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start EReaderMain
EReaderMain: @ 0x08002C58
	push {lr}
	ldr r1, _08002C70 @ =gUnknown_0805C75C
	ldr r0, _08002C74 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08002C70: .4byte gUnknown_0805C75C
_08002C74: .4byte gMain

	thumb_func_start sub_2C78
sub_2C78: @ 0x08002C78
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x86
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _08002D80 @ =0x04000008
	movs r0, #4
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08002D84 @ =0x0400000A
	adds r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	adds r3, #0xfb
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r6, _08002D88 @ =gMain
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r5, #0
	ldr r0, _08002D8C @ =0x0000FFE8
	strh r0, [r1]
	adds r3, #0xea
	adds r1, r6, r3
	subs r0, #0x48
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r6, #0x16]
	ldr r4, _08002D90 @ =0x040000D4
	ldr r0, _08002D94 @ =gUnknown_08081D20
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08002D98 @ =0x80000020
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002D9C @ =gUnknown_080897E0
	str r0, [r4]
	ldr r0, _08002DA0 @ =0x05000040
	str r0, [r4, #4]
	ldr r0, _08002DA4 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002DA8 @ =gUnknown_08080500
	str r0, [r4]
	ldr r0, _08002DAC @ =gUnknown_03000000
	mov r8, r0
	str r0, [r4, #4]
	ldr r1, _08002DB0 @ =0x80001800
	mov sb, r1
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002DB4 @ =gUnknown_0807DD00
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08002DB8 @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002DBC @ =gUnknown_0807FD00
	str r0, [r4]
	ldr r0, _08002DC0 @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002DC4 @ =gUnknown_08089960
	str r0, [r4]
	ldr r0, _08002DC8 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _08002DCC @ =0x80000060
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08002DD0 @ =gUnknown_08089B60
	str r0, [r4]
	ldr r0, _08002DD4 @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _08002DD8 @ =0x80003610
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_2DF0
	ldr r0, _08002DDC @ =gUnknown_0202C604
	strb r5, [r0]
	ldr r0, _08002DE0 @ =gUnknown_0202A580
	strb r5, [r0]
	ldr r0, _08002DE4 @ =gUnknown_0202C5A4
	strb r5, [r0]
	ldr r0, _08002DE8 @ =gUnknown_0202AD90
	strb r5, [r0]
	bl sub_377C
	mov r3, r8
	str r3, [r4]
	ldr r0, _08002DEC @ =0x06004000
	str r0, [r4, #4]
	mov r0, sb
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_394C
	movs r0, #5
	bl m4aSongNumStart
	bl sub_CBC
	bl sub_24C
	movs r0, #1
	strb r0, [r6, #3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002D80: .4byte 0x04000008
_08002D84: .4byte 0x0400000A
_08002D88: .4byte gMain
_08002D8C: .4byte 0x0000FFE8
_08002D90: .4byte 0x040000D4
_08002D94: .4byte gUnknown_08081D20
_08002D98: .4byte 0x80000020
_08002D9C: .4byte gUnknown_080897E0
_08002DA0: .4byte 0x05000040
_08002DA4: .4byte 0x80000010
_08002DA8: .4byte gUnknown_08080500
_08002DAC: .4byte gUnknown_03000000
_08002DB0: .4byte 0x80001800
_08002DB4: .4byte gUnknown_0807DD00
_08002DB8: .4byte 0x80000400
_08002DBC: .4byte gUnknown_0807FD00
_08002DC0: .4byte 0x06000800
_08002DC4: .4byte gUnknown_08089960
_08002DC8: .4byte 0x05000200
_08002DCC: .4byte 0x80000060
_08002DD0: .4byte gUnknown_08089B60
_08002DD4: .4byte 0x06010000
_08002DD8: .4byte 0x80003610
_08002DDC: .4byte gUnknown_0202C604
_08002DE0: .4byte gUnknown_0202A580
_08002DE4: .4byte gUnknown_0202C5A4
_08002DE8: .4byte gUnknown_0202AD90
_08002DEC: .4byte 0x06004000

	thumb_func_start sub_2DF0
sub_2DF0: @ 0x08002DF0
	ldr r0, _08002E1C @ =gUnknown_0202A58C
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08002E20 @ =gUnknown_0202C584
	strb r1, [r0]
	ldr r2, _08002E24 @ =gUnknown_0202BEC0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _08002E28 @ =gUnknown_0201B174
	strb r1, [r0]
	ldr r0, _08002E2C @ =gUnknown_0202C5A0
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08002E30 @ =gUnknown_0201A44C
	strh r1, [r0]
	ldr r0, _08002E34 @ =gUnknown_0202BEF8
	strb r1, [r0]
	ldr r0, _08002E38 @ =gUnknown_0200282C
	strb r1, [r0]
	ldr r0, _08002E3C @ =gUnknown_0200282D
	strb r1, [r0]
	bx lr
	.align 2, 0
_08002E1C: .4byte gUnknown_0202A58C
_08002E20: .4byte gUnknown_0202C584
_08002E24: .4byte gUnknown_0202BEC0
_08002E28: .4byte gUnknown_0201B174
_08002E2C: .4byte gUnknown_0202C5A0
_08002E30: .4byte gUnknown_0201A44C
_08002E34: .4byte gUnknown_0202BEF8
_08002E38: .4byte gUnknown_0200282C
_08002E3C: .4byte gUnknown_0200282D

	thumb_func_start sub_2E40
sub_2E40: @ 0x08002E40
	push {r4, r5, r6, r7, lr}
	ldr r4, _08002E84 @ =gUnknown_0202C604
	ldr r2, _08002E88 @ =gUnknown_086A551A
	ldr r3, _08002E8C @ =gUnknown_0202AD90
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08002E94
	ldr r1, _08002E90 @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08002EF0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_3828
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08002EF0
	.align 2, 0
_08002E84: .4byte gUnknown_0202C604
_08002E88: .4byte gUnknown_086A551A
_08002E8C: .4byte gUnknown_0202AD90
_08002E90: .4byte gUnknown_0202A580
_08002E94:
	ldr r1, _08002ECC @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _08002EF0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08002ED0 @ =gUnknown_0202C5A4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08002ED4
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xea
	lsls r1, r1, #6
	bl sub_38A0
	b _08002EE6
	.align 2, 0
_08002ECC: .4byte gUnknown_0202A580
_08002ED0: .4byte gUnknown_0202C5A4
_08002ED4:
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	bl sub_38A0
_08002EE6:
	ldr r2, _08002F2C @ =gUnknown_0202C5A4
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_08002EF0:
	ldr r7, _08002F30 @ =gMain
	ldrh r1, [r7, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08002F78
	ldr r5, _08002F34 @ =gUnknown_0202C604
	ldr r6, _08002F38 @ =gUnknown_086A551A
	ldr r4, _08002F3C @ =gUnknown_0202AD90
	movs r2, #0
	ldrsb r2, [r4, r2]
	adds r0, r2, r6
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08002F40
	adds r0, r2, #0
	bl sub_37B4
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r0, #1
	strb r0, [r5]
	b _08002F90
	.align 2, 0
_08002F2C: .4byte gUnknown_0202C5A4
_08002F30: .4byte gMain
_08002F34: .4byte gUnknown_0202C604
_08002F38: .4byte gUnknown_086A551A
_08002F3C: .4byte gUnknown_0202AD90
_08002F40:
	ldr r0, _08002F54 @ =gUnknown_086A5528
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08002F58
	movs r0, #2
	b _08002F8E
	.align 2, 0
_08002F54: .4byte gUnknown_086A5528
_08002F58:
	bl sub_377C
	movs r1, #0
	strb r1, [r5]
	ldr r0, _08002F70 @ =gUnknown_0202A580
	strb r1, [r0]
	ldr r0, _08002F74 @ =gUnknown_0202C5A4
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08002F90
	.align 2, 0
_08002F70: .4byte gUnknown_0202A580
_08002F74: .4byte gUnknown_0202C5A4
_08002F78:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08002F90
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r0, _08002FAC @ =gUnknown_0202BEF8
	movs r1, #1
	strb r1, [r0]
	movs r0, #8
_08002F8E:
	strb r0, [r7, #3]
_08002F90:
	bl sub_394C
	ldr r1, _08002FB0 @ =0x040000D4
	ldr r0, _08002FB4 @ =gUnknown_03000000
	str r0, [r1]
	ldr r0, _08002FB8 @ =0x06004000
	str r0, [r1, #4]
	ldr r0, _08002FBC @ =0x80001800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002FAC: .4byte gUnknown_0202BEF8
_08002FB0: .4byte 0x040000D4
_08002FB4: .4byte gUnknown_03000000
_08002FB8: .4byte 0x06004000
_08002FBC: .4byte 0x80001800

	thumb_func_start sub_2FC0
sub_2FC0: @ 0x08002FC0
	push {r4, r5, lr}
	ldr r4, _0800302C @ =gUnknown_0202C5A0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r2, _08003030 @ =gUnknown_086A550C
	ldr r3, _08003034 @ =gUnknown_0201B174
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _08003012
	movs r5, #0
	strh r5, [r4]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _08003012
	bl sub_19B4
	bl sub_3C1C
	ldr r0, _08003038 @ =gUnknown_0201B124
	strb r5, [r0]
	ldr r1, _0800303C @ =gUnknown_0202C584
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x76
	bl m4aSongNumStart
	ldr r1, _08003040 @ =gMain
	movs r0, #3
	strb r0, [r1, #3]
_08003012:
	ldr r1, _08003044 @ =gUnknown_0202A58C
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08003048 @ =gUnknown_0202BEC0
	ldr r0, _08003034 @ =gUnknown_0201B174
	ldrb r0, [r0]
	adds r0, #4
	strb r0, [r1]
	bl sub_3AB4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800302C: .4byte gUnknown_0202C5A0
_08003030: .4byte gUnknown_086A550C
_08003034: .4byte gUnknown_0201B174
_08003038: .4byte gUnknown_0201B124
_0800303C: .4byte gUnknown_0202C584
_08003040: .4byte gMain
_08003044: .4byte gUnknown_0202A58C
_08003048: .4byte gUnknown_0202BEC0

	thumb_func_start sub_304C
sub_304C: @ 0x0800304C
	push {r4, r5, lr}
	bl sub_3AB4
	ldr r5, _08003114 @ =gMain
	ldrh r1, [r5, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08003076
	bl sub_2568
	bl sub_1AA4
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	movs r0, #0
	strb r0, [r5, #3]
_08003076:
	ldr r4, _08003118 @ =gUnknown_0202ADD0
	ldr r0, _0800311C @ =gUnknown_0202BEC8
	ldr r1, _08003120 @ =gUnknown_0202C5F0
	ldr r2, _08003124 @ =gUnknown_0201A4D0
	bl sub_1B04
	str r0, [r4]
	ldr r1, _08003128 @ =gUnknown_0202BDF0
	movs r3, #3
	ands r3, r0
	str r3, [r1]
	ldr r2, _0800312C @ =gUnknown_0201C1AC
	movs r1, #0x1c
	ands r1, r0
	lsrs r1, r1, #2
	strb r1, [r2]
	ldr r2, _08003130 @ =gUnknown_0202ADDC
	movs r1, #0xe0
	lsls r1, r1, #4
	ands r1, r0
	lsrs r1, r1, #9
	strb r1, [r2]
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0
	bne _080030AC
	b _080031DC
_080030AC:
	cmp r3, #1
	bls _080030B2
	b _080031DC
_080030B2:
	bl sub_3C78
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800316C
	bl sub_3CD8
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne _0800316C
	bl sub_38F0
	ldr r1, _08003134 @ =gUnknown_0201C184
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	beq _0800313C
	cmp r0, #4
	bgt _0800313C
	adds r3, r5, #0
	adds r4, r1, #0
	ldr r5, _08003138 @ =gUnknown_0201A44C
	movs r2, #0
	movs r1, #4
	adds r0, r3, #0
	adds r0, #0xb
_080030F4:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _080030F4
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r0, r3, #7
	adds r1, r1, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	strh r2, [r5]
	movs r0, #5
	strb r0, [r3, #3]
	b _0800316C
	.align 2, 0
_08003114: .4byte gMain
_08003118: .4byte gUnknown_0202ADD0
_0800311C: .4byte gUnknown_0202BEC8
_08003120: .4byte gUnknown_0202C5F0
_08003124: .4byte gUnknown_0201A4D0
_08003128: .4byte gUnknown_0202BDF0
_0800312C: .4byte gUnknown_0201C1AC
_08003130: .4byte gUnknown_0202ADDC
_08003134: .4byte gUnknown_0201C184
_08003138: .4byte gUnknown_0201A44C
_0800313C:
	ldr r0, _080031E4 @ =gUnknown_0201A44C
	movs r2, #0
	strh r2, [r0]
	ldr r1, _080031E8 @ =gUnknown_0202A58C
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080031EC @ =gUnknown_0202BEC0
	movs r0, #0xa
	strb r0, [r1]
	ldr r0, _080031F0 @ =gUnknown_0202C604
	strb r2, [r0]
	ldr r0, _080031F4 @ =gUnknown_0202C5A4
	strb r2, [r0]
	ldr r1, _080031F8 @ =gUnknown_0202AD90
	movs r0, #0xd
	strb r0, [r1]
	bl sub_377C
	ldr r1, _080031FC @ =gMain
	movs r0, #4
	strb r0, [r1, #3]
	movs r0, #0x8a
	bl m4aSongNumStart
_0800316C:
	ldr r4, _080031E8 @ =gUnknown_0202A58C
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #1
	bne _080031DC
	ldr r3, _080031E4 @ =gUnknown_0201A44C
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r3]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08003192
	ldr r2, _080031EC @ =gUnknown_0202BEC0
	ldrb r1, [r2]
	movs r0, #0x15
	subs r0, r0, r1
	strb r0, [r2]
_08003192:
	ldr r0, _08003200 @ =gUnknown_0202ADD0
	ldr r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080031DC
	ldr r1, _08003204 @ =gUnknown_0201A444
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _080031DC
	movs r2, #0
	strh r2, [r3]
	movs r0, #2
	strb r0, [r4]
	ldr r1, _080031EC @ =gUnknown_0202BEC0
	movs r0, #0xa
	strb r0, [r1]
	ldr r0, _080031F0 @ =gUnknown_0202C604
	strb r2, [r0]
	ldr r0, _080031F4 @ =gUnknown_0202C5A4
	strb r2, [r0]
	ldr r1, _080031F8 @ =gUnknown_0202AD90
	movs r0, #0xd
	strb r0, [r1]
	bl sub_377C
	ldr r1, _080031FC @ =gMain
	movs r0, #4
	strb r0, [r1, #3]
	movs r0, #0x8a
	bl m4aSongNumStart
_080031DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080031E4: .4byte gUnknown_0201A44C
_080031E8: .4byte gUnknown_0202A58C
_080031EC: .4byte gUnknown_0202BEC0
_080031F0: .4byte gUnknown_0202C604
_080031F4: .4byte gUnknown_0202C5A4
_080031F8: .4byte gUnknown_0202AD90
_080031FC: .4byte gMain
_08003200: .4byte gUnknown_0202ADD0
_08003204: .4byte gUnknown_0201A444

	thumb_func_start sub_3208
sub_3208: @ 0x08003208
	push {r4, r5, r6, r7, lr}
	ldr r1, _0800326C @ =gUnknown_0201A44C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _08003228
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08003270 @ =gUnknown_0202BEC0
	ldrb r1, [r2]
	movs r0, #0x16
	subs r0, r0, r1
	strb r0, [r2]
_08003228:
	ldr r4, _08003274 @ =gUnknown_0202C604
	ldr r2, _08003278 @ =gUnknown_086A551A
	ldr r3, _0800327C @ =gUnknown_0202AD90
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08003284
	ldr r1, _08003280 @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080032E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_3828
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _080032E0
	.align 2, 0
_0800326C: .4byte gUnknown_0201A44C
_08003270: .4byte gUnknown_0202BEC0
_08003274: .4byte gUnknown_0202C604
_08003278: .4byte gUnknown_086A551A
_0800327C: .4byte gUnknown_0202AD90
_08003280: .4byte gUnknown_0202A580
_08003284:
	ldr r1, _080032BC @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _080032E0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080032C0 @ =gUnknown_0202C5A4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080032C4
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xea
	lsls r1, r1, #6
	bl sub_38A0
	b _080032D6
	.align 2, 0
_080032BC: .4byte gUnknown_0202A580
_080032C0: .4byte gUnknown_0202C5A4
_080032C4:
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	bl sub_38A0
_080032D6:
	ldr r2, _0800331C @ =gUnknown_0202C5A4
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_080032E0:
	ldr r7, _08003320 @ =gMain
	ldrh r1, [r7, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800336E
	ldr r6, _08003324 @ =gUnknown_0202C604
	ldr r4, _08003328 @ =gUnknown_086A551A
	ldr r5, _0800332C @ =gUnknown_0202AD90
	movs r2, #0
	ldrsb r2, [r5, r2]
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08003330
	adds r0, r2, #0
	bl sub_37B4
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r0, #1
	strb r0, [r6]
	b _0800336E
	.align 2, 0
_0800331C: .4byte gUnknown_0202C5A4
_08003320: .4byte gMain
_08003324: .4byte gUnknown_0202C604
_08003328: .4byte gUnknown_086A551A
_0800332C: .4byte gUnknown_0202AD90
_08003330:
	ldr r0, _08003354 @ =gUnknown_086A5528
	adds r0, r2, r0
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	bne _08003358
	bl sub_2568
	bl sub_1AA4
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	strb r4, [r7, #3]
	b _0800336E
	.align 2, 0
_08003354: .4byte gUnknown_086A5528
_08003358:
	bl sub_377C
	movs r1, #0
	strb r1, [r6]
	ldr r0, _08003388 @ =gUnknown_0202A580
	strb r1, [r0]
	ldr r0, _0800338C @ =gUnknown_0202C5A4
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_0800336E:
	bl sub_394C
	ldr r1, _08003390 @ =0x040000D4
	ldr r0, _08003394 @ =gUnknown_03000000
	str r0, [r1]
	ldr r0, _08003398 @ =0x06004000
	str r0, [r1, #4]
	ldr r0, _0800339C @ =0x80001800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003388: .4byte gUnknown_0202A580
_0800338C: .4byte gUnknown_0202C5A4
_08003390: .4byte 0x040000D4
_08003394: .4byte gUnknown_03000000
_08003398: .4byte 0x06004000
_0800339C: .4byte 0x80001800

	thumb_func_start sub_33A0
sub_33A0: @ 0x080033A0
	push {lr}
	bl sub_3AB4
	ldr r2, _080033BC @ =gUnknown_0201A44C
	movs r0, #0
	ldrsh r1, [r2, r0]
	cmp r1, #0x96
	beq _080033D4
	cmp r1, #0x96
	bgt _080033C0
	cmp r1, #4
	beq _080033CA
	b _080033FE
	.align 2, 0
_080033BC: .4byte gUnknown_0201A44C
_080033C0:
	movs r0, #0x87
	lsls r0, r0, #1
	cmp r1, r0
	beq _080033E8
	b _080033FE
_080033CA:
	bl sub_2568
	bl sub_1AA4
	b _080033FE
_080033D4:
	ldr r1, _080033E4 @ =gUnknown_0202A58C
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x65
	bl m4aSongNumStart
	b _080033FE
	.align 2, 0
_080033E4: .4byte gUnknown_0202A58C
_080033E8:
	movs r0, #0
	strh r0, [r2]
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _0800342C @ =gMain
	movs r0, #6
	strb r0, [r1, #3]
_080033FE:
	ldr r0, _08003430 @ =gUnknown_0202A58C
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r3, _08003434 @ =gUnknown_0201A44C
	cmp r0, #1
	bne _08003420
	ldrh r0, [r3]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08003420
	ldr r2, _08003438 @ =gUnknown_0202BEC0
	ldrb r1, [r2]
	movs r0, #0x15
	subs r0, r0, r1
	strb r0, [r2]
_08003420:
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_0800342C: .4byte gMain
_08003430: .4byte gUnknown_0202A58C
_08003434: .4byte gUnknown_0201A44C
_08003438: .4byte gUnknown_0202BEC0

	thumb_func_start sub_343C
sub_343C: @ 0x0800343C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x86
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _08003550 @ =0x04000008
	movs r0, #4
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08003554 @ =0x0400000A
	adds r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	adds r3, #0xfb
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r6, _08003558 @ =gMain
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r5, #0
	ldr r0, _0800355C @ =0x0000FFE8
	strh r0, [r1]
	adds r3, #0xea
	adds r1, r6, r3
	subs r0, #0x48
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r6, #0x16]
	ldr r4, _08003560 @ =0x040000D4
	ldr r0, _08003564 @ =gUnknown_08081D20
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08003568 @ =0x80000020
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800356C @ =gUnknown_080897E0
	str r0, [r4]
	ldr r0, _08003570 @ =0x05000040
	str r0, [r4, #4]
	ldr r0, _08003574 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08003578 @ =gUnknown_08080500
	str r0, [r4]
	ldr r0, _0800357C @ =gUnknown_03000000
	mov r8, r0
	str r0, [r4, #4]
	ldr r1, _08003580 @ =0x80001800
	mov sb, r1
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08003584 @ =gUnknown_0807DD00
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08003588 @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800358C @ =gUnknown_0807FD00
	str r0, [r4]
	ldr r0, _08003590 @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08003594 @ =gUnknown_08089960
	str r0, [r4]
	ldr r0, _08003598 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0800359C @ =0x80000060
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080035A0 @ =gUnknown_08089B60
	str r0, [r4]
	ldr r0, _080035A4 @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _080035A8 @ =0x80003610
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_2DF0
	ldr r0, _080035AC @ =gUnknown_0202C604
	strb r5, [r0]
	ldr r0, _080035B0 @ =gUnknown_0202A580
	strb r5, [r0]
	ldr r0, _080035B4 @ =gUnknown_0202C5A4
	strb r5, [r0]
	ldr r2, _080035B8 @ =gUnknown_0202AD90
	ldr r1, _080035BC @ =gUnknown_086A5536
	ldr r0, _080035C0 @ =gUnknown_0201C184
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	bl sub_377C
	mov r0, r8
	str r0, [r4]
	ldr r0, _080035C4 @ =0x06004000
	str r0, [r4, #4]
	mov r1, sb
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_394C
	movs r0, #5
	bl m4aSongNumStart
	bl sub_CBC
	bl sub_24C
	movs r0, #7
	strb r0, [r6, #3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003550: .4byte 0x04000008
_08003554: .4byte 0x0400000A
_08003558: .4byte gMain
_0800355C: .4byte 0x0000FFE8
_08003560: .4byte 0x040000D4
_08003564: .4byte gUnknown_08081D20
_08003568: .4byte 0x80000020
_0800356C: .4byte gUnknown_080897E0
_08003570: .4byte 0x05000040
_08003574: .4byte 0x80000010
_08003578: .4byte gUnknown_08080500
_0800357C: .4byte gUnknown_03000000
_08003580: .4byte 0x80001800
_08003584: .4byte gUnknown_0807DD00
_08003588: .4byte 0x80000400
_0800358C: .4byte gUnknown_0807FD00
_08003590: .4byte 0x06000800
_08003594: .4byte gUnknown_08089960
_08003598: .4byte 0x05000200
_0800359C: .4byte 0x80000060
_080035A0: .4byte gUnknown_08089B60
_080035A4: .4byte 0x06010000
_080035A8: .4byte 0x80003610
_080035AC: .4byte gUnknown_0202C604
_080035B0: .4byte gUnknown_0202A580
_080035B4: .4byte gUnknown_0202C5A4
_080035B8: .4byte gUnknown_0202AD90
_080035BC: .4byte gUnknown_086A5536
_080035C0: .4byte gUnknown_0201C184
_080035C4: .4byte 0x06004000

	thumb_func_start sub_35C8
sub_35C8: @ 0x080035C8
	push {r4, r5, r6, lr}
	ldr r4, _0800360C @ =gUnknown_0202C604
	ldr r2, _08003610 @ =gUnknown_086A551A
	ldr r3, _08003614 @ =gUnknown_0202AD90
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _0800361C
	ldr r1, _08003618 @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08003678
	movs r0, #0
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_3828
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08003678
	.align 2, 0
_0800360C: .4byte gUnknown_0202C604
_08003610: .4byte gUnknown_086A551A
_08003614: .4byte gUnknown_0202AD90
_08003618: .4byte gUnknown_0202A580
_0800361C:
	ldr r1, _08003654 @ =gUnknown_0202A580
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _08003678
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08003658 @ =gUnknown_0202C5A4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0800365C
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xea
	lsls r1, r1, #6
	bl sub_38A0
	b _0800366E
	.align 2, 0
_08003654: .4byte gUnknown_0202A580
_08003658: .4byte gUnknown_0202C5A4
_0800365C:
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	bl sub_38A0
_0800366E:
	ldr r2, _080036B4 @ =gUnknown_0202C5A4
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_08003678:
	ldr r2, _080036B8 @ =gMain
	ldrh r1, [r2, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800371A
	ldr r5, _080036BC @ =gUnknown_0202C604
	ldr r6, _080036C0 @ =gUnknown_086A551A
	ldr r4, _080036C4 @ =gUnknown_0202AD90
	movs r3, #0
	ldrsb r3, [r4, r3]
	adds r0, r3, r6
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _080036C8
	adds r0, r3, #0
	bl sub_37B4
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r0, #1
	strb r0, [r5]
	b _0800371A
	.align 2, 0
_080036B4: .4byte gUnknown_0202C5A4
_080036B8: .4byte gMain
_080036BC: .4byte gUnknown_0202C604
_080036C0: .4byte gUnknown_086A551A
_080036C4: .4byte gUnknown_0202AD90
_080036C8:
	ldr r0, _080036E8 @ =gUnknown_086A5528
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08003704
	ldr r0, _080036EC @ =gUnknown_0201C184
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bne _080036F4
	ldr r1, _080036F0 @ =gUnknown_0202BEF8
	movs r0, #0xb
	b _080036F8
	.align 2, 0
_080036E8: .4byte gUnknown_086A5528
_080036EC: .4byte gUnknown_0201C184
_080036F0: .4byte gUnknown_0202BEF8
_080036F4:
	ldr r1, _08003700 @ =gUnknown_0202BEF8
	movs r0, #1
_080036F8:
	strb r0, [r1]
	movs r0, #8
	strb r0, [r2, #3]
	b _0800371A
	.align 2, 0
_08003700: .4byte gUnknown_0202BEF8
_08003704:
	bl sub_377C
	movs r1, #0
	strb r1, [r5]
	ldr r0, _08003734 @ =gUnknown_0202A580
	strb r1, [r0]
	ldr r0, _08003738 @ =gUnknown_0202C5A4
	strb r1, [r0]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0800371A:
	bl sub_394C
	ldr r1, _0800373C @ =0x040000D4
	ldr r0, _08003740 @ =gUnknown_03000000
	str r0, [r1]
	ldr r0, _08003744 @ =0x06004000
	str r0, [r1, #4]
	ldr r0, _08003748 @ =0x80001800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003734: .4byte gUnknown_0202A580
_08003738: .4byte gUnknown_0202C5A4
_0800373C: .4byte 0x040000D4
_08003740: .4byte gUnknown_03000000
_08003744: .4byte 0x06004000
_08003748: .4byte 0x80001800

	thumb_func_start sub_374C
sub_374C: @ 0x0800374C
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _08003774 @ =gAutoDisplayTitlescreenMenu
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08003778 @ =gUnknown_0202BEF8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_08003774: .4byte gAutoDisplayTitlescreenMenu
_08003778: .4byte gUnknown_0202BEF8

	thumb_func_start sub_377C
sub_377C: @ 0x0800377C
	push {r4, r5, r6, r7, lr}
	movs r1, #0
	ldr r7, _080037AC @ =gUnknown_03001800
_08003782:
	movs r5, #0
	lsls r0, r1, #0xb
	adds r6, r1, #1
	adds r4, r7, r0
_0800378A:
	ldr r0, _080037B0 @ =gUnknown_080ACC60
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	adds r4, #0x20
	adds r5, #1
	cmp r5, #0x17
	ble _0800378A
	adds r1, r6, #0
	cmp r1, #2
	ble _08003782
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080037AC: .4byte gUnknown_03001800
_080037B0: .4byte gUnknown_080ACC60

	thumb_func_start sub_37B4
sub_37B4: @ 0x080037B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	lsls r0, r0, #0x18
	ldr r1, _08003818 @ =gUnknown_086A4CF8
	mov sb, r1
	asrs r0, r0, #0x18
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #4
	mov r8, r1
_080037CE:
	movs r5, #0
	lsls r1, r2, #1
	lsls r6, r2, #0xb
	adds r7, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	mov r0, r8
	add r0, sb
	adds r4, r1, r0
_080037E0:
	ldrh r1, [r4]
	ldr r2, _0800381C @ =0x0000FFF0
	adds r0, r2, #0
	ands r0, r1
	ldr r1, _08003820 @ =gUnknown_080ACC60
	adds r0, r0, r1
	lsls r1, r5, #5
	ldr r2, _08003824 @ =gUnknown_03001800
	adds r1, r1, r2
	adds r1, r6, r1
	movs r2, #1
	movs r3, #2
	bl sub_10708
	adds r4, #2
	adds r5, #1
	cmp r5, #0x17
	ble _080037E0
	adds r2, r7, #0
	cmp r2, #2
	ble _080037CE
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003818: .4byte gUnknown_086A4CF8
_0800381C: .4byte 0x0000FFF0
_08003820: .4byte gUnknown_080ACC60
_08003824: .4byte gUnknown_03001800

	thumb_func_start sub_3828
sub_3828: @ 0x08003828
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0x18
	bl __divsi3
	adds r6, r0, #0
	lsls r6, r6, #0x18
	asrs r6, r6, #0x18
	adds r0, r4, #0
	movs r1, #0x18
	bl __modsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldr r3, _08003890 @ =gUnknown_086A4CF8
	lsls r1, r6, #1
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsls r5, r5, #0x18
	asrs r5, r5, #0x18
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r3
	ldrh r1, [r1]
	ldr r0, _08003894 @ =0x0000FFF0
	ands r0, r1
	ldr r1, _08003898 @ =gUnknown_080ACC60
	adds r0, r0, r1
	lsls r6, r6, #0xb
	lsls r2, r2, #5
	ldr r1, _0800389C @ =gUnknown_03001800
	adds r2, r2, r1
	adds r6, r6, r2
	adds r1, r6, #0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003890: .4byte gUnknown_086A4CF8
_08003894: .4byte 0x0000FFF0
_08003898: .4byte gUnknown_080ACC60
_0800389C: .4byte gUnknown_03001800

	thumb_func_start sub_38A0
sub_38A0: @ 0x080038A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r5, r5, #0x18
	asrs r5, r5, #0x18
	adds r0, r5, #0
	movs r1, #0x18
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	ldr r1, _080038E8 @ =gUnknown_080ACC60
	adds r6, r6, r1
	lsls r4, r4, #0xb
	asrs r0, r0, #0x13
	ldr r1, _080038EC @ =gUnknown_03001800
	adds r0, r0, r1
	adds r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080038E8: .4byte gUnknown_080ACC60
_080038EC: .4byte gUnknown_03001800

	thumb_func_start sub_38F0
sub_38F0: @ 0x080038F0
	ldr r0, _08003900 @ =gUnknown_0202BEEC
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08003904 @ =0x00001F52
	cmp r1, r0
	bne _08003908
	movs r0, #0
	b _0800394A
	.align 2, 0
_08003900: .4byte gUnknown_0202BEEC
_08003904: .4byte 0x00001F52
_08003908:
	ldr r0, _08003914 @ =0x00003E1A
	cmp r1, r0
	bne _08003918
	movs r0, #1
	b _0800394A
	.align 2, 0
_08003914: .4byte 0x00003E1A
_08003918:
	ldr r0, _08003924 @ =0x000025AF
	cmp r1, r0
	bne _08003928
	movs r0, #2
	b _0800394A
	.align 2, 0
_08003924: .4byte 0x000025AF
_08003928:
	ldr r0, _08003934 @ =0x00004A09
	cmp r1, r0
	bne _08003938
	movs r0, #3
	b _0800394A
	.align 2, 0
_08003934: .4byte 0x00004A09
_08003938:
	ldr r0, _08003944 @ =0x00006B12
	cmp r1, r0
	beq _08003948
	movs r0, #1
	rsbs r0, r0, #0
	b _0800394A
	.align 2, 0
_08003944: .4byte 0x00006B12
_08003948:
	movs r0, #4
_0800394A:
	bx lr

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
