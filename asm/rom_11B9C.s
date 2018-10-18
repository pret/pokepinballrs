	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_11B9C
sub_11B9C: @ 0x08011B9C
	push {r4, lr}
	ldr r0, _08011BC0 @ =gMain
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _08011BD0
	ldr r0, _08011BC4 @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08011BC8 @ =0x0000132C
	adds r1, r0, r2
	ldr r3, _08011BCC @ =0x00001334
	adds r0, r0, r3
	str r0, [r1]
	movs r0, #0
	bl sub_11C14
	bl sub_12524
	b _08011C02
	.align 2, 0
_08011BC0: .4byte gMain
_08011BC4: .4byte 0x020314E0
_08011BC8: .4byte 0x0000132C
_08011BCC: .4byte 0x00001334
_08011BD0:
	movs r3, #0
_08011BD2:
	ldr r0, _08011C08 @ =0x020314E0
	ldr r1, [r0]
	ldr r0, _08011C0C @ =0x0000132C
	adds r2, r1, r0
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r3, _08011C10 @ =0x00001334
	adds r0, r0, r3
	adds r1, r1, r0
	str r1, [r2]
	adds r0, r4, #0
	bl sub_11C14
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r3, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08011BD2
	bl sub_12BF8
_08011C02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011C08: .4byte 0x020314E0
_08011C0C: .4byte 0x0000132C
_08011C10: .4byte 0x00001334

	thumb_func_start sub_11C14
sub_11C14: @ 0x08011C14
	push {r4, r5, lr}
	ldr r3, _08011C6C @ =0x020314E0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _08011C70 @ =0x00001334
	adds r1, r1, r0
	ldr r0, [r3]
	adds r4, r0, r1
	ldr r1, _08011C74 @ =0x02031520
	ldrh r0, [r1, #0x26]
	movs r2, #0
	strh r0, [r4, #0x10]
	ldrh r0, [r1, #0x28]
	strh r0, [r4, #0x12]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	lsls r0, r0, #8
	str r0, [r4, #0x34]
	movs r5, #0x12
	ldrsh r0, [r4, r5]
	lsls r0, r0, #8
	str r0, [r4, #0x38]
	movs r5, #0x26
	ldrsh r0, [r1, r5]
	lsls r0, r0, #1
	strh r0, [r4, #0x28]
	movs r5, #0x28
	ldrsh r0, [r1, r5]
	lsls r0, r0, #1
	strh r0, [r4, #0x2a]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0xe]
	strh r2, [r4, #0x30]
	strh r2, [r4, #0x32]
	ldr r0, _08011C78 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08011C7C
	movs r0, #3
	b _08011C7E
	.align 2, 0
_08011C6C: .4byte 0x020314E0
_08011C70: .4byte 0x00001334
_08011C74: .4byte 0x02031520
_08011C78: .4byte gMain
_08011C7C:
	movs r0, #1
_08011C7E:
	strb r0, [r4, #1]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, [r3]
	ldr r1, _08011C94 @ =0x000005B2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011C94: .4byte 0x000005B2

	thumb_func_start sub_11C98
sub_11C98: @ 0x08011C98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08011CE0 @ =0x020314E0
	ldr r2, [r0]
	ldr r1, _08011CE4 @ =0x0000132C
	adds r0, r2, r1
	ldr r6, [r0]
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	str r0, [r6, #0x3c]
	str r1, [r6, #0x40]
	ldr r1, _08011CE8 @ =0x000005A4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08011CBE
	b _08011F48
_08011CBE:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _08011CCA
	b _08011E04
_08011CCA:
	ldrb r0, [r2, #0x1f]
	cmp r0, #0
	bne _08011D0A
	ldrh r3, [r6, #0x32]
	movs r1, #0x32
	ldrsh r0, [r6, r1]
	cmp r0, #0xa0
	ble _08011CF0
	ldr r0, _08011CEC @ =0x08137910
	b _08011CFE
	.align 2, 0
_08011CE0: .4byte 0x020314E0
_08011CE4: .4byte 0x0000132C
_08011CE8: .4byte 0x000005A4
_08011CEC: .4byte 0x08137910
_08011CF0:
	cmp r0, #0x50
	ble _08011CFC
	ldr r0, _08011CF8 @ =0x08137908
	b _08011CFE
	.align 2, 0
_08011CF8: .4byte 0x08137908
_08011CFC:
	ldr r0, _08011D8C @ =0x08137900
_08011CFE:
	ldrb r1, [r2, #0x1e]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r3, r0
	strh r0, [r6, #0x32]
_08011D0A:
	movs r2, #0x30
	ldrsh r0, [r6, r2]
	ldrh r1, [r6, #0x32]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r4, r7, #0
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #0x32
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r1, r0
	movs r0, #0x12
	ldrsh r1, [r6, r0]
	ldr r0, _08011D90 @ =0x0000017B
	cmp r1, r0
	bgt _08011DA4
	movs r1, #0x88
	lsls r1, r1, #1
	mov r8, r1
	ldr r0, _08011D94 @ =0x00012100
	cmp r2, r0
	bgt _08011D4C
	b _08011F2C
_08011D4C:
	adds r0, r7, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _08011D98 @ =0x00004E20
	mov sb, r1
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08011D9C @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	adds r0, r7, #0
	bl sub_C24
	mov r2, r8
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sb
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08011DA0 @ =0x0000FFFF
	ands r5, r1
	b _08011F32
	.align 2, 0
_08011D8C: .4byte 0x08137900
_08011D90: .4byte 0x0000017B
_08011D94: .4byte 0x00012100
_08011D98: .4byte 0x00004E20
_08011D9C: .4byte 0xFFFF0000
_08011DA0: .4byte 0x0000FFFF
_08011DA4:
	movs r0, #0xc8
	lsls r0, r0, #1
	mov r8, r0
	ldr r0, _08011DF4 @ =0x00027100
	cmp r2, r0
	bgt _08011DB2
	b _08011F2C
_08011DB2:
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r7, _08011DF8 @ =0x00004E20
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08011DFC @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	adds r0, r4, #0
	bl sub_C24
	mov r2, r8
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08011E00 @ =0x0000FFFF
	ands r5, r1
	b _08011F32
	.align 2, 0
_08011DF4: .4byte 0x00027100
_08011DF8: .4byte 0x00004E20
_08011DFC: .4byte 0xFFFF0000
_08011E00: .4byte 0x0000FFFF
_08011E04:
	ldrb r0, [r2, #0x1f]
	cmp r0, #0
	bne _08011E36
	ldrh r3, [r6, #0x32]
	movs r1, #0x32
	ldrsh r0, [r6, r1]
	cmp r0, #0xc8
	ble _08011E1C
	ldr r0, _08011E18 @ =0x08137910
	b _08011E2A
	.align 2, 0
_08011E18: .4byte 0x08137910
_08011E1C:
	cmp r0, #0x64
	ble _08011E28
	ldr r0, _08011E24 @ =0x08137908
	b _08011E2A
	.align 2, 0
_08011E24: .4byte 0x08137908
_08011E28:
	ldr r0, _08011EB8 @ =0x08137900
_08011E2A:
	ldrb r1, [r2, #0x1e]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r3, r0
	strh r0, [r6, #0x32]
_08011E36:
	movs r2, #0x30
	ldrsh r0, [r6, r2]
	ldrh r1, [r6, #0x32]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov sb, r7
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #0x32
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r1, r0
	movs r0, #0x12
	ldrsh r1, [r6, r0]
	ldr r0, _08011EBC @ =0x0000017B
	cmp r1, r0
	bgt _08011ED0
	movs r1, #0xa8
	lsls r1, r1, #1
	mov r8, r1
	ldr r0, _08011EC0 @ =0x0001B900
	cmp r2, r0
	ble _08011F2C
	adds r0, r7, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _08011EC4 @ =0x00004E20
	mov sb, r1
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08011EC8 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	adds r0, r7, #0
	bl sub_C24
	mov r2, r8
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sb
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08011ECC @ =0x0000FFFF
	ands r5, r1
	b _08011F32
	.align 2, 0
_08011EB8: .4byte 0x08137900
_08011EBC: .4byte 0x0000017B
_08011EC0: .4byte 0x0001B900
_08011EC4: .4byte 0x00004E20
_08011EC8: .4byte 0xFFFF0000
_08011ECC: .4byte 0x0000FFFF
_08011ED0:
	movs r0, #0xc8
	lsls r0, r0, #1
	mov r8, r0
	ldr r0, _08011F1C @ =0x00027100
	cmp r2, r0
	ble _08011F2C
	mov r0, sb
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r7, _08011F20 @ =0x00004E20
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08011F24 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, sb
	bl sub_C24
	mov r2, r8
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08011F28 @ =0x0000FFFF
	ands r5, r1
	b _08011F32
	.align 2, 0
_08011F1C: .4byte 0x00027100
_08011F20: .4byte 0x00004E20
_08011F24: .4byte 0xFFFF0000
_08011F28: .4byte 0x0000FFFF
_08011F2C:
	ldrh r0, [r6, #0x32]
	lsls r0, r0, #0x10
	ldrh r5, [r6, #0x30]
_08011F32:
	orrs r5, r0
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r6, #0x34]
	adds r0, r0, r1
	str r0, [r6, #0x34]
	asrs r1, r5, #0x10
	ldr r0, [r6, #0x38]
	adds r0, r0, r1
	str r0, [r6, #0x38]
	b _08011F4C
_08011F48:
	bl sub_2AADC
_08011F4C:
	ldr r0, [r6, #0x28]
	str r0, [r6, #0x2c]
	ldr r1, [r6, #0x34]
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, #0
	bge _08011F5C
	adds r0, #0x7f
_08011F5C:
	asrs r0, r0, #7
	strh r0, [r6, #0x28]
	ldr r1, [r6, #0x38]
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, #0
	bge _08011F6C
	adds r0, #0x7f
_08011F6C:
	asrs r0, r0, #7
	strh r0, [r6, #0x2a]
	ldrh r0, [r6, #6]
	strh r0, [r6, #8]
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	strh r0, [r6, #0xa]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_11F88
sub_11F88: @ 0x08011F88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, _08011FD0 @ =0x020314E0
	ldr r3, [r2]
	ldr r1, _08011FD4 @ =0x0000132C
	adds r0, r3, r1
	ldr r6, [r0]
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	str r0, [r6, #0x3c]
	str r1, [r6, #0x40]
	ldr r1, _08011FD8 @ =0x000005A4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08011FAE
	b _080124E4
_08011FAE:
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	bne _08011FFE
	ldr r1, _08011FDC @ =0x00000383
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08011FFE
	ldrh r4, [r6, #0x32]
	movs r1, #0x32
	ldrsh r0, [r6, r1]
	cmp r0, #0x96
	ble _08011FE4
	ldr r0, _08011FE0 @ =0x08137910
	b _08011FF2
	.align 2, 0
_08011FD0: .4byte 0x020314E0
_08011FD4: .4byte 0x0000132C
_08011FD8: .4byte 0x000005A4
_08011FDC: .4byte 0x00000383
_08011FE0: .4byte 0x08137910
_08011FE4:
	cmp r0, #0x4b
	ble _08011FF0
	ldr r0, _08011FEC @ =0x08137908
	b _08011FF2
	.align 2, 0
_08011FEC: .4byte 0x08137908
_08011FF0:
	ldr r0, _0801208C @ =0x08137900
_08011FF2:
	ldrb r1, [r3, #0x1e]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r4, r0
	strh r0, [r6, #0x32]
_08011FFE:
	ldr r0, [r2]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801200A
	b _08012270
_0801200A:
	movs r2, #0x30
	ldrsh r0, [r6, r2]
	ldrh r1, [r6, #0x32]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov sb, r8
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #0x32
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08012090 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080120FC
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0x95
	bgt _080120A4
	movs r7, #0x88
	lsls r7, r7, #1
	ldr r0, _08012094 @ =0x00012100
	cmp r1, r0
	bgt _08012052
	b _080124C8
_08012052:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _08012098 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801209C @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080120A0 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_0801208C: .4byte 0x08137900
_08012090: .4byte gMain
_08012094: .4byte 0x00012100
_08012098: .4byte 0x00004E20
_0801209C: .4byte 0xFFFF0000
_080120A0: .4byte 0x0000FFFF
_080120A4:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _080120EC @ =0x00027100
	cmp r1, r0
	bgt _080120B0
	b _080124C8
_080120B0:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _080120F0 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080120F4 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080120F8 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_080120EC: .4byte 0x00027100
_080120F0: .4byte 0x00004E20
_080120F4: .4byte 0xFFFF0000
_080120F8: .4byte 0x0000FFFF
_080120FC:
	cmp r0, #7
	bne _080121B8
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0xd9
	bgt _08012160
	movs r7, #0x88
	lsls r7, r7, #1
	ldr r0, _08012150 @ =0x00012100
	cmp r1, r0
	bgt _08012114
	b _080124C8
_08012114:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _08012154 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08012158 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _0801215C @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_08012150: .4byte 0x00012100
_08012154: .4byte 0x00004E20
_08012158: .4byte 0xFFFF0000
_0801215C: .4byte 0x0000FFFF
_08012160:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _080121A8 @ =0x00027100
	cmp r1, r0
	bgt _0801216C
	b _080124C8
_0801216C:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _080121AC @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080121B0 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080121B4 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_080121A8: .4byte 0x00027100
_080121AC: .4byte 0x00004E20
_080121B0: .4byte 0xFFFF0000
_080121B4: .4byte 0x0000FFFF
_080121B8:
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0xd9
	bgt _08012218
	movs r7, #0x88
	lsls r7, r7, #1
	ldr r0, _08012208 @ =0x00012100
	cmp r1, r0
	bgt _080121CC
	b _080124C8
_080121CC:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _0801220C @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08012210 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08012214 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_08012208: .4byte 0x00012100
_0801220C: .4byte 0x00004E20
_08012210: .4byte 0xFFFF0000
_08012214: .4byte 0x0000FFFF
_08012218:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _08012260 @ =0x00027100
	cmp r1, r0
	bgt _08012224
	b _080124C8
_08012224:
	mov r0, sb
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _08012264 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08012268 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, sb
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _0801226C @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_08012260: .4byte 0x00027100
_08012264: .4byte 0x00004E20
_08012268: .4byte 0xFFFF0000
_0801226C: .4byte 0x0000FFFF
_08012270:
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	ldrh r1, [r6, #0x32]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r2, #0x30
	ldrsh r0, [r6, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #0x32
	ldrsh r0, [r6, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080122F0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _0801235C
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0x95
	bgt _08012304
	movs r7, #0x98
	lsls r7, r7, #1
	ldr r0, _080122F4 @ =0x00016900
	cmp r1, r0
	bgt _080122B6
	b _080124C8
_080122B6:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _080122F8 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080122FC @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08012300 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_080122F0: .4byte gMain
_080122F4: .4byte 0x00016900
_080122F8: .4byte 0x00004E20
_080122FC: .4byte 0xFFFF0000
_08012300: .4byte 0x0000FFFF
_08012304:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _0801234C @ =0x00027100
	cmp r1, r0
	bgt _08012310
	b _080124C8
_08012310:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _08012350 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08012354 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08012358 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_0801234C: .4byte 0x00027100
_08012350: .4byte 0x00004E20
_08012354: .4byte 0xFFFF0000
_08012358: .4byte 0x0000FFFF
_0801235C:
	cmp r0, #7
	bne _08012418
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0xd9
	bgt _080123C0
	movs r7, #0x88
	lsls r7, r7, #1
	ldr r0, _080123B0 @ =0x00012100
	cmp r1, r0
	bgt _08012374
	b _080124C8
_08012374:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _080123B4 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080123B8 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080123BC @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_080123B0: .4byte 0x00012100
_080123B4: .4byte 0x00004E20
_080123B8: .4byte 0xFFFF0000
_080123BC: .4byte 0x0000FFFF
_080123C0:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _08012408 @ =0x00027100
	cmp r1, r0
	bgt _080123CC
	b _080124C8
_080123CC:
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _0801240C @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08012410 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08012414 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_08012408: .4byte 0x00027100
_0801240C: .4byte 0x00004E20
_08012410: .4byte 0xFFFF0000
_08012414: .4byte 0x0000FFFF
_08012418:
	movs r2, #0x12
	ldrsh r0, [r6, r2]
	cmp r0, #0xd9
	bgt _08012474
	movs r7, #0x98
	lsls r7, r7, #1
	ldr r0, _08012464 @ =0x00016900
	cmp r1, r0
	ble _080124C8
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _08012468 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801246C @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08012470 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_08012464: .4byte 0x00016900
_08012468: .4byte 0x00004E20
_0801246C: .4byte 0xFFFF0000
_08012470: .4byte 0x0000FFFF
_08012474:
	movs r7, #0xc8
	lsls r7, r7, #1
	ldr r0, _080124B8 @ =0x00027100
	cmp r1, r0
	ble _080124C8
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r4, _080124BC @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080124C0 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	mov r0, r8
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080124C4 @ =0x0000FFFF
	ands r5, r1
	b _080124CE
	.align 2, 0
_080124B8: .4byte 0x00027100
_080124BC: .4byte 0x00004E20
_080124C0: .4byte 0xFFFF0000
_080124C4: .4byte 0x0000FFFF
_080124C8:
	ldrh r0, [r6, #0x32]
	lsls r0, r0, #0x10
	ldrh r5, [r6, #0x30]
_080124CE:
	orrs r5, r0
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r6, #0x34]
	adds r0, r0, r1
	str r0, [r6, #0x34]
	asrs r1, r5, #0x10
	ldr r0, [r6, #0x38]
	adds r0, r0, r1
	str r0, [r6, #0x38]
	b _080124E8
_080124E4:
	bl sub_2AADC
_080124E8:
	ldr r0, [r6, #0x28]
	str r0, [r6, #0x2c]
	ldr r1, [r6, #0x34]
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, #0
	bge _080124F8
	adds r0, #0x7f
_080124F8:
	asrs r0, r0, #7
	strh r0, [r6, #0x28]
	ldr r1, [r6, #0x38]
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, #0
	bge _08012508
	adds r0, #0x7f
_08012508:
	asrs r0, r0, #7
	strh r0, [r6, #0x2a]
	ldrh r0, [r6, #6]
	strh r0, [r6, #8]
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	strh r0, [r6, #0xa]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_12524
sub_12524: @ 0x08012524
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _080125F0 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _080125F4 @ =0x0000132C
	adds r0, r0, r1
	ldr r7, [r0]
	ldrh r0, [r7, #0xa]
	lsrs r0, r0, #0xc
	mov r8, r0
	movs r3, #0x12
	ldrsh r1, [r7, r3]
	movs r0, #0xaa
	lsls r0, r0, #1
	cmp r1, r0
	bne _0801255A
	movs r4, #0x10
	ldrsh r0, [r7, r4]
	cmp r0, #0x5a
	beq _08012556
	cmp r0, #0x95
	bne _0801255A
_08012556:
	ldrh r0, [r7, #0xc]
	strh r0, [r7, #0xa]
_0801255A:
	ldrh r0, [r7, #0xa]
	strh r0, [r7, #0xc]
	ldr r6, _080125F0 @ =0x020314E0
	ldr r3, [r6]
	ldr r1, _080125F8 @ =0x000005F7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080125CE
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _080125CE
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080125CE
	ldr r6, _080125FC @ =0x000005F6
	adds r2, r3, r6
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080125AC
	subs r0, r3, #1
	strb r0, [r2]
	ldr r0, _080125F0 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080125AC
	adds r1, r1, r4
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
_080125AC:
	ldr r2, _08012600 @ =0x040000D4
	ldr r1, _080125F0 @ =0x020314E0
	ldr r0, [r1]
	ldr r3, _080125FC @ =0x000005F6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _08012604 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012608 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0801260C @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_080125CE:
	movs r4, #0x12
	ldrsh r0, [r7, r4]
	cmp r0, #0xf3
	ble _08012614
	ldr r6, _080125F0 @ =0x020314E0
	ldr r0, [r6]
	ldr r1, _08012610 @ =0x000005B2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	movs r3, #0xbb
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r2, [r0]
	b _08012620
	.align 2, 0
_080125F0: .4byte 0x020314E0
_080125F4: .4byte 0x0000132C
_080125F8: .4byte 0x000005F7
_080125FC: .4byte 0x000005F6
_08012600: .4byte 0x040000D4
_08012604: .4byte 0x08137E14
_08012608: .4byte 0x05000220
_0801260C: .4byte 0x80000010
_08012610: .4byte 0x000005B2
_08012614:
	ldr r4, _080126C8 @ =0x020314E0
	ldr r0, [r4]
	ldr r6, _080126CC @ =0x000005B2
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
_08012620:
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r7, #0x10]
	movs r2, #0x2a
	ldrsh r0, [r7, r2]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r7, #0x12]
	ldr r1, _080126D0 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08012646
	b _08012792
_08012646:
	movs r3, #0xe
	ldrsh r1, [r7, r3]
	adds r0, r1, #0
	movs r2, #0
	bl sub_7C0
	ldr r0, _080126C8 @ =0x020314E0
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, #7
	ldrh r2, [r7, #0x10]
	subs r2, r2, r0
	ldr r4, _080126D4 @ =0x000002AA
	adds r0, r3, r4
	ldrh r0, [r0]
	subs r2, r2, r0
	strh r2, [r6, #2]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r1, #7
	ldrh r0, [r7, #0x12]
	subs r0, r0, r1
	ldr r4, _080126D8 @ =0x000005FC
	adds r1, r3, r4
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0xe6
	ldrh r1, [r1]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r3, r3, r4
	subs r0, r0, r1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r6, #4]
	strh r2, [r7, #0x24]
	ldrh r0, [r6, #4]
	strh r0, [r7, #0x26]
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _080126DC @ =gOamBuffer
	adds r5, r0, r1
	movs r0, #1
	ldrsb r0, [r7, r0]
	cmp r0, #3
	bne _080126E6
	movs r1, #0x12
	ldrsh r0, [r7, r1]
	cmp r0, #0xf8
	ble _080126E0
	ldrb r0, [r5, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r5, #5]
	b _080126FA
	.align 2, 0
_080126C8: .4byte 0x020314E0
_080126CC: .4byte 0x000005B2
_080126D0: .4byte gMain
_080126D4: .4byte 0x000002AA
_080126D8: .4byte 0x000005FC
_080126DC: .4byte gOamBuffer
_080126E0:
	ldrb r0, [r5, #5]
	movs r1, #0xc
	b _080126F6
_080126E6:
	movs r0, #3
	ldrb r1, [r7, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
_080126F6:
	orrs r0, r1
	strb r0, [r5, #5]
_080126FA:
	ldr r3, _08012768 @ =0x040000D4
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r4, _0801276C @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _08012770 @ =0x000005F6
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r0, r2, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r1, r1, #7
	ldr r0, _08012774 @ =0x083BB16C
	adds r1, r1, r0
	str r1, [r3]
	ldr r0, _08012778 @ =0x06010400
	str r0, [r3, #4]
	ldr r0, _0801277C @ =0x80000040
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc8
	ble _08012732
	movs r0, #0xc8
	strh r0, [r6, #4]
_08012732:
	movs r4, #4
	ldrsh r0, [r6, r4]
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08012740
	strh r1, [r6, #4]
_08012740:
	mov r0, ip
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r4, _08012780 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r2, [r5, #2]
	ldr r0, _08012784 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _08012788
	movs r0, #0xc8
	b _08012790
	.align 2, 0
_08012768: .4byte 0x040000D4
_0801276C: .4byte 0x020314E0
_08012770: .4byte 0x000005F6
_08012774: .4byte 0x083BB16C
_08012778: .4byte 0x06010400
_0801277C: .4byte 0x80000040
_08012780: .4byte 0x000001FF
_08012784: .4byte 0xFFFFFE00
_08012788:
	ldrb r0, [r6, #4]
	mov r6, ip
	ldrb r6, [r6, #4]
	adds r0, r0, r6
_08012790:
	strb r0, [r5]
_08012792:
	ldr r1, _08012824 @ =gMain
	ldr r0, [r1, #0x44]
	adds r0, #0xc4
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _080127A2
	b _080128EA
_080127A2:
	movs r2, #0xe
	ldrsh r1, [r7, r2]
	adds r0, r1, #0
	movs r2, #0
	bl sub_7C0
	ldr r0, _08012828 @ =0x020314E0
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, #7
	ldrh r2, [r7, #0x10]
	subs r2, r2, r0
	ldr r4, _0801282C @ =0x000002AA
	adds r0, r3, r4
	ldrh r0, [r0]
	subs r2, r2, r0
	strh r2, [r6, #2]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r1, #7
	ldrh r0, [r7, #0x12]
	subs r0, r0, r1
	ldr r4, _08012830 @ =0x000005FC
	adds r1, r3, r4
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0xe6
	ldrh r1, [r1]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r3, r3, r4
	subs r0, r0, r1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r6, #4]
	strh r2, [r7, #0x24]
	ldrh r0, [r6, #4]
	strh r0, [r7, #0x26]
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _08012834 @ =gOamBuffer
	adds r5, r0, r1
	movs r0, #1
	ldrsb r0, [r7, r0]
	cmp r0, #3
	bne _0801283E
	movs r1, #0x12
	ldrsh r0, [r7, r1]
	cmp r0, #0xf8
	ble _08012838
	ldrb r0, [r5, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r5, #5]
	b _08012852
	.align 2, 0
_08012824: .4byte gMain
_08012828: .4byte 0x020314E0
_0801282C: .4byte 0x000002AA
_08012830: .4byte 0x000005FC
_08012834: .4byte gOamBuffer
_08012838:
	ldrb r0, [r5, #5]
	movs r1, #0xc
	b _0801284E
_0801283E:
	movs r0, #3
	ldrb r1, [r7, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
_0801284E:
	orrs r0, r1
	strb r0, [r5, #5]
_08012852:
	ldr r3, _080128C0 @ =0x040000D4
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r4, _080128C4 @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _080128C8 @ =0x000005F6
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r0, r2, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r1, r1, #7
	ldr r0, _080128CC @ =0x083BB16C
	adds r1, r1, r0
	str r1, [r3]
	ldr r0, _080128D0 @ =0x06010400
	str r0, [r3, #4]
	ldr r0, _080128D4 @ =0x80000040
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc8
	ble _0801288A
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801288A:
	movs r4, #4
	ldrsh r0, [r6, r4]
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08012898
	strh r1, [r6, #4]
_08012898:
	mov r0, ip
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r4, _080128D8 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r2, [r5, #2]
	ldr r0, _080128DC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _080128E0
	movs r0, #0xc8
	b _080128E8
	.align 2, 0
_080128C0: .4byte 0x040000D4
_080128C4: .4byte 0x020314E0
_080128C8: .4byte 0x000005F6
_080128CC: .4byte 0x083BB16C
_080128D0: .4byte 0x06010400
_080128D4: .4byte 0x80000040
_080128D8: .4byte 0x000001FF
_080128DC: .4byte 0xFFFFFE00
_080128E0:
	ldrb r0, [r6, #4]
	mov r6, ip
	ldrb r6, [r6, #4]
	adds r0, r0, r6
_080128E8:
	strb r0, [r5]
_080128EA:
	movs r3, #4
	ldr r5, _080129D0 @ =0x020314E0
_080128EE:
	ldr r2, [r5]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r4, r1, #2
	adds r4, r2, r4
	subs r1, #1
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0xd0
	ldrh r3, [r0]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r3, [r0]
	adds r2, #0xd2
	ldrh r0, [r2]
	adds r4, #0xd2
	strh r0, [r4]
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	bgt _080128EE
	ldr r0, _080129D0 @ =0x020314E0
	ldr r2, [r0]
	ldrh r0, [r7, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xd0
	strh r0, [r1]
	ldrh r0, [r7, #0x12]
	subs r0, #7
	adds r1, #2
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08012940
	b _08012A44
_08012940:
	movs r3, #0
	ldr r1, _080129D4 @ =gMain
	mov sb, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	mov sl, r2
_0801294C:
	lsls r2, r3, #0x10
	asrs r4, r2, #0x10
	mov r3, sb
	ldr r1, [r3, #0x44]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r6, [r0, #4]
	ldrh r0, [r6]
	mov r8, r2
	cmp r0, #0
	beq _08012A0C
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _080129D8 @ =gOamBuffer
	adds r5, r0, r1
	movs r0, #3
	ldrb r1, [r7, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	mov r1, ip
	movs r3, #2
	ldrsh r2, [r1, r3]
	ldr r6, _080129D0 @ =0x020314E0
	ldr r3, [r6]
	adds r0, r4, #1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, #0xd0
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r0, r3, #0
	adds r0, #0x4c
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	adds r2, r2, r1
	ldr r1, _080129DC @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r5, #2]
	ldr r0, _080129E0 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r5, #2]
	cmp r4, #0
	bne _080129E4
	adds r0, r3, #0
	adds r0, #0xda
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrb r1, [r1]
	subs r0, r0, r1
	mov r2, ip
	ldrb r2, [r2, #4]
	adds r0, r0, r2
	b _08012A0A
	.align 2, 0
_080129D0: .4byte 0x020314E0
_080129D4: .4byte gMain
_080129D8: .4byte gOamBuffer
_080129DC: .4byte 0x000001FF
_080129E0: .4byte 0xFFFFFE00
_080129E4:
	cmp r4, #1
	bne _08012A0C
	mov r6, sb
	ldr r0, [r6, #0x4c]
	ands r0, r4
	cmp r0, #0
	bne _08012A08
	adds r0, r3, #0
	adds r0, #0xe2
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrb r1, [r1]
	subs r0, r0, r1
	mov r1, ip
	ldrb r1, [r1, #4]
	adds r0, r0, r1
	b _08012A0A
_08012A08:
	movs r0, #0xc8
_08012A0A:
	strb r0, [r5]
_08012A0C:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0801294C
	ldr r2, _08012A40 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #4]
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	ldr r3, _08012A40 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #8]
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	adds r0, #0xc4
	ldr r0, [r0]
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0]
	strh r2, [r0]
	b _08012AE4
	.align 2, 0
_08012A40: .4byte gMain
_08012A44:
	movs r3, #0
	ldr r4, _08012B14 @ =gMain
	mov sl, r4
	movs r6, #3
	mov sb, r6
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	ldr r1, _08012B18 @ =0xFFFFFE00
	mov r8, r1
_08012A58:
	lsls r0, r3, #0x10
	asrs r4, r0, #0x10
	mov r2, sl
	ldr r1, [r2, #0x44]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r6, [r0, #4]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08012AB8
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _08012B1C @ =gOamBuffer
	adds r5, r0, r1
	ldrb r1, [r7, #1]
	mov r3, sb
	ands r1, r3
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	movs r0, #0xa
	ldrsh r3, [r6, r0]
	ldr r1, _08012B20 @ =0x020314E0
	ldr r2, [r1]
	adds r0, r4, #1
	lsls r0, r0, #3
	adds r0, r2, r0
	adds r0, #0xd0
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r2, #0x4c
	movs r6, #0
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r3, r3, r1
	ldr r1, _08012B24 @ =0x000001FF
	adds r0, r1, #0
	ands r3, r0
	ldrh r1, [r5, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r3
	strh r0, [r5, #2]
	movs r0, #0xc8
	strb r0, [r5]
_08012AB8:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08012A58
	ldr r2, _08012B14 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #4]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #8]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	adds r0, #0xc4
	ldr r0, [r0]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
_08012AE4:
	ldr r3, _08012B14 @ =gMain
	ldr r1, [r3, #0x44]
	adds r0, r1, #0
	adds r0, #0xac
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08012BC2
	ldr r4, _08012B20 @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _08012B28 @ =0x0000071C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x3a
	bhi _08012B2C
	ldr r0, [r1]
	ldrh r0, [r0, #2]
	subs r0, #8
	strh r0, [r6, #2]
	ldr r0, [r3, #0x44]
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	subs r0, #8
	b _08012B32
	.align 2, 0
_08012B14: .4byte gMain
_08012B18: .4byte 0xFFFFFE00
_08012B1C: .4byte gOamBuffer
_08012B20: .4byte 0x020314E0
_08012B24: .4byte 0x000001FF
_08012B28: .4byte 0x0000071C
_08012B2C:
	movs r0, #0
	strh r0, [r6, #2]
	movs r0, #0xb4
_08012B32:
	strh r0, [r6, #4]
	ldr r3, _08012BD0 @ =0x020314E0
	ldr r0, [r3]
	adds r0, #0x6e
	ldr r2, _08012BD4 @ =0x040000D4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #9
	ldr r1, _08012BD8 @ =0x083BD36C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012BDC @ =0x06011EE0
	str r0, [r2, #4]
	ldr r0, _08012BE0 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r4, #8
	adds r4, r4, r6
	mov ip, r4
	ldr r4, _08012BE4 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	mov r0, ip
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08012BE8 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08012BEC @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	mov r2, ip
	ldrb r2, [r2, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #3
	ldrb r1, [r7, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	ldr r3, _08012BD0 @ =0x020314E0
	ldr r0, [r3]
	ldr r4, _08012BF0 @ =0x0000071C
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xd
	bhi _08012BC2
	ldr r6, _08012BF4 @ =gMain
	ldr r0, [r6, #0x44]
	adds r0, #0xac
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
_08012BC2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012BD0: .4byte 0x020314E0
_08012BD4: .4byte 0x040000D4
_08012BD8: .4byte 0x083BD36C
_08012BDC: .4byte 0x06011EE0
_08012BE0: .4byte 0x80000100
_08012BE4: .4byte gOamBuffer
_08012BE8: .4byte 0x000001FF
_08012BEC: .4byte 0xFFFFFE00
_08012BF0: .4byte 0x0000071C
_08012BF4: .4byte gMain

	thumb_func_start sub_12BF8
sub_12BF8: @ 0x08012BF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r3, _08012C30 @ =0x020314E0
	ldr r0, [r3]
	ldr r1, _08012C34 @ =0x00001330
	adds r2, r0, r1
	ldr r4, _08012C38 @ =0x00001334
	adds r1, r0, r4
	str r1, [r2]
	ldr r6, _08012C3C @ =0x0000132C
	adds r0, r0, r6
	str r1, [r0]
	mov r8, r1
	ldr r1, _08012C40 @ =gMain
	ldrb r0, [r1, #4]
	subs r0, #3
	mov sl, r3
	cmp r0, #4
	bhi _08012CA0
	lsls r0, r0, #2
	ldr r1, _08012C44 @ =_08012C48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08012C30: .4byte 0x020314E0
_08012C34: .4byte 0x00001330
_08012C38: .4byte 0x00001334
_08012C3C: .4byte 0x0000132C
_08012C40: .4byte gMain
_08012C44: .4byte _08012C48
_08012C48: @ jump table
	.4byte _08012C5C @ case 0
	.4byte _08012C78 @ case 1
	.4byte _08012C78 @ case 2
	.4byte _08012C88 @ case 3
	.4byte _08012C78 @ case 4
_08012C5C:
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #1]
	ldr r0, _08012C70 @ =0x02031590
	ldrb r1, [r0, #0x16]
	movs r0, #0xb8
	muls r1, r0, r1
	ldr r0, _08012C74 @ =0x0200B3B8
	adds r6, r1, r0
	b _08012CAC
	.align 2, 0
_08012C70: .4byte 0x02031590
_08012C74: .4byte 0x0200B3B8
_08012C78:
	movs r0, #1
	mov r2, r8
	strb r0, [r2, #1]
	ldr r3, _08012C84 @ =gMain
	ldr r0, [r3, #0x44]
	b _08012CAA
	.align 2, 0
_08012C84: .4byte gMain
_08012C88:
	mov r4, r8
	movs r0, #1
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _08012C96
	movs r0, #2
	strb r0, [r4, #1]
_08012C96:
	ldr r6, _08012C9C @ =gMain
	ldr r0, [r6, #0x44]
	b _08012CAA
	.align 2, 0
_08012C9C: .4byte gMain
_08012CA0:
	movs r0, #3
	mov r1, r8
	strb r0, [r1, #1]
	ldr r2, _08012DC0 @ =gMain
	ldr r0, [r2, #0x44]
_08012CAA:
	ldr r6, [r0]
_08012CAC:
	mov r3, sl
	ldr r1, [r3]
	ldr r4, _08012DC4 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	lsrs r5, r0, #0xc
	ldr r2, _08012DC8 @ =0x040000D4
	ldr r0, _08012DCC @ =0x000005F6
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r0, r1, #4
	adds r0, r0, r1
	adds r0, r5, r0
	lsls r0, r0, #7
	ldr r1, _08012DD0 @ =0x083BB16C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012DD4 @ =0x06010400
	str r0, [r2, #4]
	ldr r0, _08012DD8 @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, r8
	movs r3, #0x28
	ldrsh r1, [r2, r3]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	strh r1, [r2, #0x10]
	movs r4, #0x2a
	ldrsh r0, [r2, r4]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	mov r2, r8
	strh r0, [r2, #0x12]
	mov r3, sl
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, #7
	subs r1, r1, r0
	ldr r4, _08012DDC @ =0x000002AA
	adds r0, r2, r4
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r0, #7
	mov r1, r8
	ldrh r4, [r1, #0x12]
	subs r4, r4, r0
	ldr r3, _08012DE0 @ =0x000005FC
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r4, r4, r0
	adds r0, r2, #0
	adds r0, #0xe6
	ldrh r0, [r0]
	subs r4, r4, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r4, r4, r0
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r2, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	subs r4, r4, r0
	strh r4, [r6, #4]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r0, #0x3c
	rsbs r0, r0, #0
	cmp r4, r0
	bge _08012D5E
	ldr r0, _08012DE4 @ =0x0000FFC4
	strh r0, [r6, #4]
_08012D5E:
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0xb4
	ble _08012D6A
	movs r0, #0xb4
	strh r0, [r6, #4]
_08012D6A:
	ldrh r0, [r6, #2]
	mov r3, r8
	strh r0, [r3, #0x24]
	ldrh r0, [r6, #4]
	strh r0, [r3, #0x26]
	adds r7, r6, #0
	adds r7, #8
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r3, _08012DE8 @ =gOamBuffer
	adds r4, r0, r3
	movs r0, #3
	mov r2, r8
	ldrb r1, [r2, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08012DEC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	ldr r0, _08012DF0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	mov sb, r3
	cmp r0, #0
	beq _08012DF4
	movs r0, #0xc8
	b _08012DFA
	.align 2, 0
_08012DC0: .4byte gMain
_08012DC4: .4byte 0x0000132C
_08012DC8: .4byte 0x040000D4
_08012DCC: .4byte 0x000005F6
_08012DD0: .4byte 0x083BB16C
_08012DD4: .4byte 0x06010400
_08012DD8: .4byte 0x80000040
_08012DDC: .4byte 0x000002AA
_08012DE0: .4byte 0x000005FC
_08012DE4: .4byte 0x0000FFC4
_08012DE8: .4byte gOamBuffer
_08012DEC: .4byte 0x000001FF
_08012DF0: .4byte 0xFFFFFE00
_08012DF4:
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
_08012DFA:
	strb r0, [r4]
	mov r2, sl
	ldr r3, [r2]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08012E12
	b _0801309C
_08012E12:
	ldr r6, _08012F84 @ =gMain
	ldr r0, [r6, #0x44]
	ldr r6, [r0, #4]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08012E5E
	mov r1, r8
	ldrh r0, [r1, #0x24]
	subs r0, #8
	strh r0, [r6, #2]
	ldrh r0, [r1, #0x26]
	subs r0, #8
	strh r0, [r6, #4]
	adds r7, r6, #0
	adds r7, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r3, #2
	ldrsh r1, [r7, r3]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r3, _08012F88 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08012F8C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
_08012E5E:
	mov r4, sl
	ldr r2, [r4]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08012E78
	cmp r0, #3
	beq _08012E78
	b _08012FBC
_08012E78:
	ldr r4, _08012F90 @ =0x00000392
	adds r0, r2, r4
	ldrh r1, [r0]
	cmp r1, #0
	bne _08012E8E
	movs r0, #1
	strb r0, [r2, #0x1f]
	mov r2, r8
	strh r1, [r2, #0x30]
	strh r1, [r2, #0x32]
	strh r1, [r2, #6]
_08012E8E:
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	bne _08012E9E
	movs r0, #1
	strh r0, [r6]
_08012E9E:
	mov r1, sl
	ldr r0, [r1]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x9a
	bne _08012EB0
	movs r0, #0xf9
	bl m4aSongNumStart
_08012EB0:
	mov r2, sl
	ldr r0, [r2]
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0x95
	bls _08012EEA
	subs r0, #0x96
	movs r1, #0x42
	bl __modsi3
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r2, _08012F94 @ =0x040000D4
	lsrs r5, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _08012F98 @ =0x083BF16C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012F9C @ =0x06010720
	str r0, [r2, #4]
	ldr r0, _08012FA0 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r3, r8
	ldrh r0, [r3, #6]
	subs r0, #0x28
	strh r0, [r3, #6]
_08012EEA:
	ldr r1, _08012F84 @ =gMain
	ldrb r0, [r1, #0xf]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	cmp r0, #0
	bne _08012F30
	mov r2, sl
	ldr r3, [r2]
	adds r0, r3, r4
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r0, r5, #0x10
	ldr r4, _08012FA4 @ =0xFFF90000
	adds r0, r0, r4
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _08012F30
	ldr r2, _08012F94 @ =0x040000D4
	ldr r1, _08012FA8 @ =0x000005F6
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #4
	lsls r0, r0, #5
	ldr r1, _08012FAC @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012FB0 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _08012FB4 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08012F30:
	ldr r3, _08012FB8 @ =0x020314E0
	ldr r0, [r3]
	ldr r2, _08012F90 @ =0x00000392
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0xba
	bne _08012F44
	movs r0, #0
	mov r4, r8
	strb r0, [r4]
_08012F44:
	ldr r1, [r3]
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0xd7
	bhi _08012F50
	b _0801310A
_08012F50:
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08012F6A
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #2
	strb r0, [r1]
_08012F6A:
	ldr r0, [r3]
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	strh r1, [r6]
	ldr r0, [r3]
	strb r2, [r0, #0x1f]
	ldr r2, _08012F94 @ =0x040000D4
	ldr r0, [r3]
	ldr r1, _08012FA8 @ =0x000005F6
	adds r0, r0, r1
	b _080130F2
	.align 2, 0
_08012F84: .4byte gMain
_08012F88: .4byte 0x000001FF
_08012F8C: .4byte 0xFFFFFE00
_08012F90: .4byte 0x00000392
_08012F94: .4byte 0x040000D4
_08012F98: .4byte 0x083BF16C
_08012F9C: .4byte 0x06010720
_08012FA0: .4byte 0x80000100
_08012FA4: .4byte 0xFFF90000
_08012FA8: .4byte 0x000005F6
_08012FAC: .4byte 0x08137E14
_08012FB0: .4byte 0x05000220
_08012FB4: .4byte 0x80000010
_08012FB8: .4byte 0x020314E0
_08012FBC:
	ldr r4, _0801307C @ =0x00000392
	adds r0, r2, r4
	ldrh r1, [r0]
	cmp r1, #0
	bne _08012FD2
	movs r0, #1
	strb r0, [r2, #0x1f]
	mov r2, r8
	strh r1, [r2, #0x30]
	strh r1, [r2, #0x32]
	strh r1, [r2, #6]
_08012FD2:
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _08012FE2
	movs r0, #1
	strh r0, [r6]
_08012FE2:
	mov r1, sl
	ldr r0, [r1]
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #4
	bls _0801301A
	subs r0, #5
	movs r1, #0x3f
	bl __modsi3
	movs r1, #7
	bl __divsi3
	ldr r2, _08013080 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _08013084 @ =0x083BDF6C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08013088 @ =0x06010720
	str r0, [r2, #4]
	ldr r0, _0801308C @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, r8
	ldrh r0, [r2, #6]
	subs r0, #0x14
	strh r0, [r2, #6]
_0801301A:
	ldr r3, _08013090 @ =gMain
	ldrb r0, [r3, #0xf]
	movs r1, #0x81
	rsbs r1, r1, #0
	ands r0, r1
	cmp r0, #0
	bne _08013034
	mov r0, sl
	ldr r1, [r0]
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08013034:
	mov r1, sl
	ldr r0, [r1]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x17
	bne _08013046
	movs r0, #0xf9
	bl m4aSongNumStart
_08013046:
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x14
	bne _08013058
	movs r0, #1
	mov r3, r8
	strb r0, [r3]
_08013058:
	ldr r0, _08013094 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x43
	bls _0801310A
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #0
	strb r0, [r1]
	strh r0, [r6]
	ldr r2, _08013080 @ =0x040000D4
	ldr r3, _08013094 @ =0x020314E0
	ldr r0, [r3]
	ldr r4, _08013098 @ =0x000005F6
	adds r0, r0, r4
	b _080130F2
	.align 2, 0
_0801307C: .4byte 0x00000392
_08013080: .4byte 0x040000D4
_08013084: .4byte 0x083BDF6C
_08013088: .4byte 0x06010720
_0801308C: .4byte 0x80000100
_08013090: .4byte gMain
_08013094: .4byte 0x020314E0
_08013098: .4byte 0x000005F6
_0801309C:
	ldr r6, _08013204 @ =0x000005F7
	adds r0, r3, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801310A
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _0801310A
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0801310A
	ldr r0, _08013208 @ =0x000005F6
	adds r2, r3, r0
	ldrb r3, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080130E8
	subs r0, r3, #1
	strb r0, [r2]
	mov r2, sl
	ldr r1, [r2]
	ldr r3, _08013208 @ =0x000005F6
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080130E8
	adds r1, r1, r4
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
_080130E8:
	ldr r2, _0801320C @ =0x040000D4
	mov r4, sl
	ldr r0, [r4]
	ldr r6, _08013208 @ =0x000005F6
	adds r0, r0, r6
_080130F2:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _08013210 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08013214 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _08013218 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801310A:
	ldr r1, _0801321C @ =gMain
	ldrb r0, [r1, #4]
	cmp r0, #6
	ble _08013114
	b _0801330C
_08013114:
	cmp r0, #4
	bge _0801311A
	b _0801330C
_0801311A:
	ldr r0, _08013220 @ =0x020314E0
	ldr r1, [r0]
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	bne _0801312E
	b _08013280
_0801312E:
	movs r3, #4
	mov r5, sl
_08013132:
	ldr r2, [r5]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r4, r1, #2
	adds r4, r2, r4
	subs r1, #1
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0xd0
	ldrh r3, [r0]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r3, [r0]
	adds r2, #0xd2
	ldrh r0, [r2]
	adds r4, #0xd2
	strh r0, [r4]
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	bgt _08013132
	mov r3, sl
	ldr r2, [r3]
	mov r4, r8
	ldrh r0, [r4, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xd0
	strh r0, [r1]
	ldrh r0, [r4, #0x12]
	subs r0, #7
	adds r2, #0xd2
	strh r0, [r2]
	movs r3, #0
	ldr r6, _0801321C @ =gMain
	mov sb, r6
_0801317C:
	lsls r2, r3, #0x10
	asrs r5, r2, #0x10
	mov r0, sb
	ldr r1, [r0, #0x44]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r6, [r0, #0x18]
	ldrh r0, [r6]
	mov ip, r2
	cmp r0, #0
	beq _0801325E
	adds r7, r6, #0
	adds r7, #8
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _08013224 @ =gOamBuffer
	adds r4, r0, r1
	movs r0, #3
	mov r2, r8
	ldrb r1, [r2, #1]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
	movs r3, #2
	ldrsh r2, [r7, r3]
	mov r6, sl
	ldr r3, [r6]
	adds r0, r5, #1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, #0xd0
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r0, r3, #0
	adds r0, #0x4c
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	adds r2, r2, r1
	ldr r1, _08013228 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	ldr r0, _0801322C @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	cmp r5, #0
	bne _08013230
	adds r0, r3, #0
	adds r0, #0xda
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrb r1, [r1]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0xe6
	ldrb r1, [r1]
	subs r0, r0, r1
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	b _0801325C
	.align 2, 0
_08013204: .4byte 0x000005F7
_08013208: .4byte 0x000005F6
_0801320C: .4byte 0x040000D4
_08013210: .4byte 0x08137E14
_08013214: .4byte 0x05000220
_08013218: .4byte 0x80000010
_0801321C: .4byte gMain
_08013220: .4byte 0x020314E0
_08013224: .4byte gOamBuffer
_08013228: .4byte 0x000001FF
_0801322C: .4byte 0xFFFFFE00
_08013230:
	cmp r5, #1
	bne _0801325E
	mov r2, sb
	ldr r0, [r2, #0x4c]
	ands r0, r5
	cmp r0, #0
	bne _0801325A
	adds r0, r3, #0
	adds r0, #0xe2
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrb r1, [r1]
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0xe6
	ldrb r1, [r1]
	subs r0, r0, r1
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	b _0801325C
_0801325A:
	movs r0, #0xc8
_0801325C:
	strb r0, [r4]
_0801325E:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0801317C
	ldr r3, _0801327C @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x18]
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	b _08013308
	.align 2, 0
_0801327C: .4byte gMain
_08013280:
	movs r3, #0
	movs r4, #3
	mov sb, r4
	movs r6, #0xd
	rsbs r6, r6, #0
	mov ip, r6
	ldr r7, _0801331C @ =0xFFFFFE00
_0801328E:
	lsls r0, r3, #0x10
	asrs r5, r0, #0x10
	ldr r0, _08013320 @ =gMain
	ldr r1, [r0, #0x44]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r6, [r0, #0x18]
	ldrh r0, [r6]
	cmp r0, #0
	beq _080132F0
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r1, _08013324 @ =gOamBuffer
	adds r4, r0, r1
	mov r2, r8
	ldrb r1, [r2, #1]
	mov r3, sb
	ands r1, r3
	lsls r1, r1, #2
	ldrb r2, [r4, #5]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
	movs r0, #0xa
	ldrsh r3, [r6, r0]
	mov r1, sl
	ldr r2, [r1]
	adds r0, r5, #1
	lsls r0, r0, #3
	adds r0, r2, r0
	adds r0, #0xd0
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r2, #0x4c
	movs r6, #0
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r3, r3, r1
	ldr r1, _08013328 @ =0x000001FF
	adds r0, r1, #0
	ands r3, r0
	ldrh r1, [r4, #2]
	adds r0, r7, #0
	ands r0, r1
	orrs r0, r3
	strh r0, [r4, #2]
	movs r0, #0xc8
	strb r0, [r4]
_080132F0:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0801328E
	ldr r2, _08013320 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x18]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r2, #0x44]
_08013308:
	ldr r0, [r0, #0x1c]
	strh r1, [r0]
_0801330C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801331C: .4byte 0xFFFFFE00
_08013320: .4byte gMain
_08013324: .4byte gOamBuffer
_08013328: .4byte 0x000001FF

	thumb_func_start sub_1332C
sub_1332C: @ 0x0801332C
	ldr r0, _08013338 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	bx lr
	.align 2, 0
_08013338: .4byte 0x020314E0

	thumb_func_start sub_1333C
sub_1333C: @ 0x0801333C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r0, sp
	bl sub_13824
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0801336C @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0x22
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bls _08013362
	b _08013758
_08013362:
	lsls r0, r0, #2
	ldr r1, _08013370 @ =_08013374
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801336C: .4byte 0x020314E0
_08013370: .4byte _08013374
_08013374: @ jump table
	.4byte _080133C8 @ case 0
	.4byte _08013488 @ case 1
	.4byte _080134FC @ case 2
	.4byte _08013614 @ case 3
	.4byte _08013758 @ case 4
	.4byte _08013428 @ case 5
	.4byte _08013390 @ case 6
_08013390:
	ldr r0, _080133A4 @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _080133A8 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0
	strh r2, [r1, #0x30]
	ldr r0, [r0]
	strh r2, [r0, #0x32]
	b _080137CE
	.align 2, 0
_080133A4: .4byte 0x020314E0
_080133A8: .4byte 0x0000132C
_080133AC:
	mov r1, sp
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	movs r1, #1
	ldrsb r1, [r3, r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _0801340C
_080133C8:
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r0, _0801341C @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08013420 @ =0x0000132C
	adds r0, r0, r2
	ldr r1, [r0]
	adds r1, #0x30
	add r4, sp, #8
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_13D24
	movs r1, #0
	mov r8, r5
	adds r5, r4, #0
	ldr r2, _08013424 @ =0x086ACD50
_080133F2:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #2
	adds r3, r0, r2
	ldrh r0, [r3, #2]
	cmp r0, r7
	bls _080133AC
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _080133F2
_0801340C:
	ldr r0, _0801341C @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _08013420 @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	mov r6, r8
	ldrh r0, [r6]
	b _080134DA
	.align 2, 0
_0801341C: .4byte 0x020314E0
_08013420: .4byte 0x0000132C
_08013424: .4byte 0x086ACD50
_08013428:
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r0, _08013464 @ =0x020314E0
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _08013468 @ =0x0000132C
	adds r0, r0, r6
	ldr r1, [r0]
	adds r1, #0x30
	add r4, sp, #8
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_13D24
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r6
	ldr r2, [r1]
	ldrh r0, [r5]
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	b _080134EA
	.align 2, 0
_08013464: .4byte 0x020314E0
_08013468: .4byte 0x0000132C
_0801346C:
	mov r1, sp
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	movs r1, #1
	ldrsb r1, [r3, r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _080134CC
_08013488:
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r0, _080134F0 @ =0x020314E0
	ldr r0, [r0]
	ldr r6, _080134F4 @ =0x0000132C
	adds r0, r0, r6
	ldr r1, [r0]
	adds r1, #0x30
	add r4, sp, #8
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_13D24
	movs r1, #0
	mov r8, r5
	adds r5, r4, #0
	ldr r2, _080134F8 @ =0x086ACD50
_080134B2:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #2
	adds r3, r0, r2
	ldrh r0, [r3, #2]
	cmp r0, r7
	bls _0801346C
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _080134B2
_080134CC:
	ldr r0, _080134F0 @ =0x020314E0
	ldr r1, [r0]
	ldr r0, _080134F4 @ =0x0000132C
	adds r1, r1, r0
	ldr r2, [r1]
	mov r3, r8
	ldrh r0, [r3]
_080134DA:
	ldrh r5, [r5]
	adds r0, r0, r5
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	add r0, sp, #8
	add r1, sp, #4
	ldrh r0, [r0, #2]
	ldrh r1, [r1, #2]
_080134EA:
	adds r0, r0, r1
	strh r0, [r2, #0x32]
	b _080137CE
	.align 2, 0
_080134F0: .4byte 0x020314E0
_080134F4: .4byte 0x0000132C
_080134F8: .4byte 0x086ACD50
_080134FC:
	mov r4, sp
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r2, _08013560 @ =0x02031520
	movs r6, #0x22
	ldrsh r1, [r2, r6]
	lsls r1, r1, #1
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	lsls r1, r1, #1
	ldrh r0, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldr r6, _08013564 @ =0x020314E0
	ldr r2, [r6]
	movs r1, #0x9e
	lsls r1, r1, #5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r5
	cmp r0, #0
	bne _08013588
	ldr r3, _08013568 @ =0x0000132C
	adds r0, r2, r3
	ldr r1, [r0]
	adds r1, #0x30
	add r4, sp, #8
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_13D24
	ldr r0, [r6]
	movs r6, #0x9e
	lsls r6, r6, #5
	adds r0, r0, r6
	movs r1, #1
	strb r1, [r0]
	adds r5, r4, #0
	b _0801359C
	.align 2, 0
_08013560: .4byte 0x02031520
_08013564: .4byte 0x020314E0
_08013568: .4byte 0x0000132C
_0801356C:
	mov r1, sp
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	movs r1, #1
	ldrsb r1, [r3, r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _080135F0
_08013588:
	ldr r0, _08013604 @ =0x0000132C
	adds r2, r2, r0
	ldr r0, [r2]
	ldrh r0, [r0, #0x30]
	add r1, sp, #8
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0, #0x32]
	strh r0, [r1, #2]
	adds r5, r1, #0
_0801359C:
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0
	bl sub_13B28
	ldr r0, _08013608 @ =0x020314E0
	ldr r2, [r0]
	ldr r1, _08013604 @ =0x0000132C
	adds r3, r2, r1
	ldr r4, [r3]
	add r1, sp, #8
	mov r6, r8
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x30]
	ldr r3, [r3]
	add r1, sp, #4
	ldrh r0, [r5, #2]
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r3, #0x32]
	adds r2, #0x22
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #5
	bne _080135F0
	movs r1, #0
	ldr r2, _0801360C @ =0x086ACD74
_080135D6:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #2
	adds r3, r0, r2
	ldrh r0, [r3, #2]
	cmp r0, r7
	bls _0801356C
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080135D6
_080135F0:
	ldr r3, _08013610 @ =0x02031520
	movs r1, #0x22
	ldrsh r0, [r3, r1]
	mov r1, sp
	lsls r0, r0, #1
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	b _08013738
	.align 2, 0
_08013604: .4byte 0x0000132C
_08013608: .4byte 0x020314E0
_0801360C: .4byte 0x086ACD74
_08013610: .4byte 0x02031520
_08013614:
	mov r4, sp
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r2, _08013674 @ =0x02031520
	movs r0, #0x24
	ldrsh r1, [r2, r0]
	lsls r1, r1, #1
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	movs r3, #0x20
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	ldrh r0, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldr r6, _08013678 @ =0x020314E0
	ldr r2, [r6]
	ldr r1, _0801367C @ =0x000013CC
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r5
	cmp r0, #0
	bne _080136A0
	ldr r3, _08013680 @ =0x0000132C
	adds r0, r2, r3
	ldr r1, [r0]
	adds r1, #0x30
	add r4, sp, #8
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_13D24
	ldr r0, [r6]
	ldr r6, _0801367C @ =0x000013CC
	adds r0, r0, r6
	movs r1, #1
	strb r1, [r0]
	adds r5, r4, #0
	b _080136B4
	.align 2, 0
_08013674: .4byte 0x02031520
_08013678: .4byte 0x020314E0
_0801367C: .4byte 0x000013CC
_08013680: .4byte 0x0000132C
_08013684:
	movs r1, #0
	ldrsb r1, [r3, r1]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	movs r1, #1
	ldrsb r1, [r3, r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _0801371E
_080136A0:
	ldr r0, _08013748 @ =0x0000132C
	adds r2, r2, r0
	ldr r0, [r2]
	ldrh r0, [r0, #0x30]
	add r1, sp, #8
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0, #0x32]
	strh r0, [r1, #2]
	adds r5, r1, #0
_080136B4:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x5f
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r5]
	rsbs r0, r0, #0
	add r4, sp, #8
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #1
	bl sub_13B28
	ldrh r1, [r4]
	rsbs r1, r1, #0
	strh r1, [r4]
	ldr r0, _0801374C @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _08013748 @ =0x0000132C
	adds r5, r2, r3
	ldr r3, [r5]
	mov r6, r8
	ldrh r0, [r6]
	adds r1, r1, r0
	strh r1, [r3, #0x30]
	ldr r3, [r5]
	add r1, sp, #4
	ldrh r0, [r4, #2]
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r3, #0x32]
	adds r2, #0x22
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #5
	bne _0801371E
	movs r1, #0
	ldr r2, _08013750 @ =0x086ACD74
_08013704:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #2
	adds r3, r0, r2
	ldrh r0, [r3, #2]
	cmp r0, r7
	bls _08013684
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08013704
_0801371E:
	mov r0, sp
	ldrh r0, [r0]
	movs r1, #0x5f
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldr r3, _08013754 @ =0x02031520
	movs r2, #0x24
	ldrsh r0, [r3, r2]
	lsls r0, r0, #1
	adds r1, r1, r0
	mov r0, sp
	strh r1, [r0]
_08013738:
	mov r2, sp
	movs r6, #0x20
	ldrsh r1, [r3, r6]
	lsls r1, r1, #1
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _080137CE
	.align 2, 0
_08013748: .4byte 0x0000132C
_0801374C: .4byte 0x020314E0
_08013750: .4byte 0x086ACD74
_08013754: .4byte 0x02031520
_08013758:
	ldr r0, _08013788 @ =0x020314E0
	ldr r2, [r0]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08013794
	ldr r6, _0801378C @ =0x00000127
	adds r3, r2, r6
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #1
	beq _080137B8
	ldr r1, _08013790 @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	subs r0, #4
	strh r0, [r1, #0x30]
	movs r0, #1
	b _080137B6
	.align 2, 0
_08013788: .4byte 0x020314E0
_0801378C: .4byte 0x00000127
_08013790: .4byte 0x0000132C
_08013794:
	cmp r0, #0
	bge _080137B8
	ldr r6, _08013814 @ =0x00000127
	adds r3, r2, r6
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080137B8
	ldr r1, _08013818 @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	adds r0, #4
	strh r0, [r1, #0x30]
	movs r0, #0xff
_080137B6:
	strb r0, [r3]
_080137B8:
	ldr r0, _0801381C @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08013820 @ =0x000005F3
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080137CE
	bl sub_1493C
_080137CE:
	ldr r0, _0801381C @ =0x020314E0
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08013808
	ldr r3, _08013818 @ =0x0000132C
	adds r2, r2, r3
	ldr r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r1, #0x28]
	ldr r1, [r2]
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x2a]
	ldr r1, [r2]
	movs r6, #0x28
	ldrsh r0, [r1, r6]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r2, #0x2a
	ldrsh r0, [r1, r2]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
_08013808:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013814: .4byte 0x00000127
_08013818: .4byte 0x0000132C
_0801381C: .4byte 0x020314E0
_08013820: .4byte 0x000005F3

	thumb_func_start sub_13824
sub_13824: @ 0x08013824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _0801391C @ =0x020314E0
	mov r8, r0
	ldr r3, [r0]
	ldr r1, _08013920 @ =0x0000132C
	mov sb, r1
	add r3, sb
	ldr r1, [r3]
	ldrh r2, [r1, #0x28]
	ldrh r4, [r1, #0x2c]
	subs r2, r2, r4
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x2a]
	ldrh r1, [r1, #0x2e]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08013924 @ =0x0000FFFF
	mov sl, r1
	lsrs r6, r2, #0x10
	orrs r6, r0
	movs r5, #0
	strh r4, [r7]
	ldr r0, [r3]
	ldrh r0, [r0, #0x2e]
	strh r0, [r7, #2]
	adds r0, r7, #0
	adds r1, r6, #0
	bl sub_14488
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r3, r8
	ldr r0, [r3]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r3]
	ldr r3, _08013928 @ =0x00000125
	adds r0, r0, r3
	strb r5, [r0]
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801390A
	subs r1, #2
	adds r3, r2, r1
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _0801390A
	mov r0, sb
	adds r1, r2, r0
	ldr r0, [r1]
	ldrh r0, [r0, #0x28]
	strh r0, [r7]
	ldr r0, [r1]
	ldrh r0, [r0, #0x2a]
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801392C @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	ldr r1, _08013930 @ =0x00000123
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	mov r3, sl
	ands r6, r3
	orrs r6, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl sub_14488
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	ldr r1, [r0]
	ldrb r2, [r7]
	mov r3, sb
	adds r0, r1, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x28]
	subs r2, r2, r0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r1, r0
	strb r2, [r1]
	mov r3, r8
	ldr r1, [r3]
	ldrb r2, [r7, #2]
	mov r3, sb
	adds r0, r1, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x2a]
	subs r2, r2, r0
	ldr r0, _08013928 @ =0x00000125
	adds r1, r1, r0
	strb r2, [r1]
_0801390A:
	adds r0, r4, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801391C: .4byte 0x020314E0
_08013920: .4byte 0x0000132C
_08013924: .4byte 0x0000FFFF
_08013928: .4byte 0x00000125
_0801392C: .4byte 0xFFFF0000
_08013930: .4byte 0x00000123

	thumb_func_start sub_13934
sub_13934: @ 0x08013934
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #2]
	ldr r7, _0801399C @ =0x020314E0
	ldr r1, [r7]
	movs r0, #0x91
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _080139D6
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r1, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r6]
	subs r0, r0, r1
	strh r0, [r6]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080139A4
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080139D6
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x46
	muls r0, r1, r0
	ldr r1, _080139A0 @ =0x00004E20
	bl __divsi3
	strh r0, [r5]
	ldr r0, [r7]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r0, r2
	b _080139D2
	.align 2, 0
_0801399C: .4byte 0x020314E0
_080139A0: .4byte 0x00004E20
_080139A4:
	cmp r0, #0
	bge _080139D6
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080139D6
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x46
	muls r0, r1, r0
	ldr r1, _08013A30 @ =0x00004E20
	bl __divsi3
	strh r0, [r5]
	ldr r0, [r7]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r1, r0, r3
_080139D2:
	movs r0, #1
	strb r0, [r1]
_080139D6:
	ldr r1, _08013A34 @ =0x020314E0
	ldr r2, [r1]
	ldr r3, _08013A38 @ =0x00000123
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #0
	bgt _080139EC
	b _08013AF4
_080139EC:
	ldr r1, _08013A3C @ =0x00000125
	adds r0, r2, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _08013A40 @ =0x0000132C
	adds r0, r2, r3
	ldr r0, [r0]
	movs r3, #0x12
	ldrsh r1, [r0, r3]
	movs r0, #0xb6
	lsls r0, r0, #1
	cmp r1, r0
	ble _08013A64
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08013A44
	adds r0, r4, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #1
	b _08013A52
	.align 2, 0
_08013A30: .4byte 0x00004E20
_08013A34: .4byte 0x020314E0
_08013A38: .4byte 0x00000123
_08013A3C: .4byte 0x00000125
_08013A40: .4byte 0x0000132C
_08013A44:
	adds r0, r4, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x64
	muls r0, r1, r0
_08013A52:
	rsbs r0, r0, #0
	ldr r1, _08013A60 @ =0x00004E20
	bl __divsi3
	strh r0, [r5, #2]
	b _08013AE4
	.align 2, 0
_08013A60: .4byte 0x00004E20
_08013A64:
	movs r3, #0x91
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08013A8C
	adds r0, r4, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x64
	muls r0, r1, r0
	rsbs r0, r0, #0
	ldr r1, _08013A88 @ =0x00004E20
	b _08013AA2
	.align 2, 0
_08013A88: .4byte 0x00004E20
_08013A8C:
	adds r0, r4, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r0, r2, #4
	subs r2, r2, r0
	ldr r1, _08013ABC @ =0x00004E20
	adds r0, r2, #0
_08013AA2:
	bl __divsi3
	strh r0, [r5, #2]
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0x59
	ble _08013AC8
	ldr r0, _08013AC0 @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _08013AC4 @ =0x0000132C
	adds r0, r0, r1
	b _08013AD4
	.align 2, 0
_08013ABC: .4byte 0x00004E20
_08013AC0: .4byte 0x020314E0
_08013AC4: .4byte 0x0000132C
_08013AC8:
	cmp r1, #0x45
	ble _08013AE4
	ldr r0, _08013B1C @ =0x020314E0
	ldr r0, [r0]
	ldr r3, _08013B20 @ =0x0000132C
	adds r0, r0, r3
_08013AD4:
	ldr r1, [r0]
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08013AE0
	adds r0, #3
_08013AE0:
	asrs r0, r0, #2
	strh r0, [r1, #0x30]
_08013AE4:
	ldr r0, _08013B1C @ =0x020314E0
	ldr r1, [r0]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r1, #1
	strb r1, [r2]
	adds r3, r0, #0
_08013AF4:
	ldr r1, [r3]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08013B16
	subs r2, #4
	adds r0, r1, r2
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	ldr r3, _08013B24 @ =0x00000123
	adds r0, r0, r3
	strb r1, [r0]
_08013B16:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08013B1C: .4byte 0x020314E0
_08013B20: .4byte 0x0000132C
_08013B24: .4byte 0x00000123

	thumb_func_start sub_13B28
sub_13B28: @ 0x08013B28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	str r1, [sp, #8]
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #0x17
	movs r4, #2
	ldrsh r0, [r0, r4]
	lsls r0, r0, #0x17
	lsrs r5, r1, #0x10
	orrs r5, r0
	ldr r6, [sp, #8]
	ldrh r1, [r6, #2]
	lsls r1, r1, #0x10
	ldrh r0, [r6]
	orrs r0, r1
	str r0, [sp, #4]
	lsls r2, r2, #0x10
	mov sb, r2
	mov r0, sb
	asrs r0, r0, #0x10
	mov sl, r0
	b _08013C4E
_08013B60:
	ldr r2, _08013C04 @ =0xFFFFF500
	adds r1, r5, r2
	lsls r1, r1, #0x10
	asrs r0, r5, #0x10
	ldr r3, _08013C08 @ =0xFFFFE800
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r7, r1, #0x10
	orrs r7, r0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	asrs r0, r7, #0x10
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r1, r1, r0
	ldr r2, _08013C0C @ =0xFFDC0000
	adds r0, r1, r2
	lsls r0, r0, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	mov r3, sb
	asrs r1, r3, #0x10
	add r2, sp, #4
	adds r3, r4, #0
	bl sub_14B84
	add r0, sp, #4
	movs r4, #0
	ldrsh r2, [r0, r4]
	movs r1, #0xe1
	lsls r1, r1, #1
	cmp r2, r1
	bgt _08013BB2
	ldr r1, _08013C10 @ =0xFFFFFE3E
	cmp r2, r1
	bge _08013BB4
_08013BB2:
	strh r1, [r0]
_08013BB4:
	ldrh r0, [r0]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08013C14 @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	asrs r2, r5, #0x10
	add r0, sp, #4
	ldrh r1, [r0, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r0, _08013C18 @ =0x0000FFFF
	ands r5, r0
	orrs r5, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08013BDC
	adds r0, #0x7f
_08013BDC:
	asrs r1, r0, #7
	mov r6, r8
	strh r1, [r6]
	asrs r0, r5, #0x10
	cmp r0, #0
	bge _08013BEA
	adds r0, #0x7f
_08013BEA:
	asrs r0, r0, #7
	mov r2, r8
	strh r0, [r2, #2]
	movs r3, #0
	str r3, [sp, #0x10]
	cmp r1, #0x31
	bgt _08013BFA
	b _08013CF0
_08013BFA:
	ldr r0, _08013C1C @ =0x020314E0
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	b _08013C22
	.align 2, 0
_08013C04: .4byte 0xFFFFF500
_08013C08: .4byte 0xFFFFE800
_08013C0C: .4byte 0xFFDC0000
_08013C10: .4byte 0xFFFFFE3E
_08013C14: .4byte 0xFFFF0000
_08013C18: .4byte 0x0000FFFF
_08013C1C: .4byte 0x020314E0
_08013C20:
	lsrs r0, r4, #0x10
_08013C22:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #3
	bgt _08013C48
	mov r4, r8
	ldr r0, [r4]
	adds r1, #1
	lsls r4, r1, #0x10
	asrs r1, r4, #0x10
	mov r2, sp
	mov r6, sb
	asrs r3, r6, #0x10
	bl sub_14AF4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08013C20
	movs r0, #1
	str r0, [sp, #0x10]
_08013C48:
	ldr r1, [sp, #0x10]
	cmp r1, #0
	beq _08013CF0
_08013C4E:
	ldr r0, _08013CAC @ =0x020314E0
	ldr r1, [r0]
	mov r2, sl
	lsls r0, r2, #1
	add r0, sl
	lsls r0, r0, #2
	adds r3, r1, r0
	ldr r4, _08013CB0 @ =0x000013BC
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r6, _08013CB4 @ =0x000013BD
	adds r0, r3, r6
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r4, #8
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r2
	muls r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r6, [sp, #0xc]
	cmp r0, #0
	ble _08013CF0
	ldr r1, _08013CB8 @ =0x000013BE
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bgt _08013CC4
	ldr r2, _08013CBC @ =0x000013C1
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #2
	ldr r3, _08013CC0 @ =0x086ACD84
	adds r0, r0, r3
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	b _08013CDC
	.align 2, 0
_08013CAC: .4byte 0x020314E0
_08013CB0: .4byte 0x000013BC
_08013CB4: .4byte 0x000013BD
_08013CB8: .4byte 0x000013BE
_08013CBC: .4byte 0x000013C1
_08013CC0: .4byte 0x086ACD84
_08013CC4:
	ldr r6, _08013CE8 @ =0x000013C1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #2
	ldr r1, _08013CEC @ =0x086ACD86
	adds r0, r0, r1
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r1, r2, #0
_08013CDC:
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	b _08013B60
	.align 2, 0
_08013CE8: .4byte 0x000013C1
_08013CEC: .4byte 0x086ACD86
_08013CF0:
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt _08013D08
	ldr r0, _08013D04 @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #5
	strb r1, [r0]
	b _08013D14
	.align 2, 0
_08013D04: .4byte 0x020314E0
_08013D08:
	add r0, sp, #4
	ldrh r1, [r0]
	ldr r4, [sp, #8]
	strh r1, [r4]
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
_08013D14:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_13D24
sub_13D24: @ 0x08013D24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r4, r1, #0
	str r2, [sp, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldrh r0, [r4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	lsls r0, r1, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #8]
	cmp r0, r1
	bls _08013D84
	subs r4, r0, r1
	ldr r1, _08013D80 @ =0x0000FFFF
	b _08013D8C
	.align 2, 0
_08013D80: .4byte 0x0000FFFF
_08013D84:
	ldr r2, [sp, #8]
	ldr r0, [sp, #0x10]
	subs r4, r2, r0
	movs r1, #1
_08013D8C:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r4, r0
	ble _08013DA0
	movs r0, #0x80
	lsls r0, r0, #9
	subs r4, r0, r4
	lsls r0, r1, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x10
_08013DA0:
	lsls r1, r1, #0x10
	asrs r0, r1, #2
	ldr r2, [sp, #8]
	adds r0, r2, r0
	str r0, [sp, #0x14]
	mov r8, r1
	cmp r0, #0
	bge _08013DB8
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	str r0, [sp, #0x14]
_08013DB8:
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	ldr r5, _08013E40 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	str r0, [sp, #0x1c]
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	adds r7, r0, #0
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	ldr r1, _08013E44 @ =0x1F3F0000
	cmp r0, r1
	ble _08013E2A
	cmp r7, #0x46
	ble _08013E02
	movs r0, #0x77
	bl m4aSongNumStart
_08013E02:
	movs r0, #0x8c
	lsls r0, r0, #1
	cmp r7, r0
	ble _08013E2A
	ldr r0, _08013E48 @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08013E4C @ =0x0000061C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08013E2A
	ldr r0, _08013E50 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bhi _08013E2A
	movs r0, #6
	bl sub_11B0
_08013E2A:
	ldr r0, _08013E48 @ =0x020314E0
	ldr r1, [r0]
	adds r1, #0x31
	ldrb r1, [r1]
	cmp r1, #0
	beq _08013E54
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r7
	b _08013E58
	.align 2, 0
_08013E40: .4byte 0x00004E20
_08013E44: .4byte 0x1F3F0000
_08013E48: .4byte 0x020314E0
_08013E4C: .4byte 0x0000061C
_08013E50: .4byte gMain
_08013E54:
	movs r0, #0x1a
	muls r0, r7, r0
_08013E58:
	movs r1, #0x64
	bl __divsi3
	adds r7, r0, #0
	ldr r1, [sp, #0x1c]
	lsls r0, r1, #3
	movs r1, #0xa
	bl __divsi3
	adds r6, r0, #0
	ldr r2, _08014004 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _08014008 @ =0x0000132C
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #6
	ldrsh r0, [r4, r2]
	ldr r5, _0801400C @ =0x00000EB8
	muls r0, r5, r0
	movs r1, #0xaf
	lsls r1, r1, #0xa
	bl __divsi3
	mov sb, r0
	mov r1, r8
	asrs r0, r1, #0x10
	rsbs r0, r0, #0
	mov r8, r0
	lsls r0, r0, #1
	add r0, r8
	lsls r0, r0, #3
	add r0, r8
	lsls r0, r0, #0xa
	muls r0, r6, r0
	adds r1, r5, #0
	bl __divsi3
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #6]
	ldr r0, [sp, #8]
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	str r0, [sp]
	ldr r0, [sp, #8]
	bl sub_C24
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r2, sp
	str r2, [sp, #0x20]
	str r0, [sp, #4]
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x1c]
	muls r0, r2, r0
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	bl sub_C24
	ldr r2, [sp, #0x1c]
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, [sp, #4]
	adds r4, r4, r0
	str r4, [sp, #4]
	ldr r0, [sp]
	ldr r7, _08014010 @ =0x00004E20
	adds r1, r7, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	bl __divsi3
	str r0, [sp, #4]
	movs r4, #1
	mov r0, sb
	cmp r0, #0
	bge _08013F20
	subs r4, #2
	rsbs r0, r0, #0
	mov sb, r0
_08013F20:
	mov r1, r8
	muls r1, r4, r1
	adds r4, r1, #0
	adds r0, r5, #0
	bl sub_C74
	mov r1, sb
	muls r1, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08014014 @ =0xFFFF0000
	mov r2, sl
	ands r2, r1
	orrs r2, r0
	mov sl, r2
	adds r0, r5, #0
	bl sub_C24
	rsbs r1, r4, #0
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r7, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08014018 @ =0x0000FFFF
	mov r2, sl
	ands r2, r1
	orrs r2, r0
	mov sl, r2
	ldr r0, [sp]
	adds r1, r0, #0
	muls r1, r0, r1
	ldr r0, [sp, #4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r1, r0
	lsls r0, r6, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x11
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	mov r2, sl
	asrs r0, r2, #0x10
	ldr r1, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	ldrh r1, [r2, #4]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0801401C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _08014020
	ldr r0, _08014004 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08014020
	ldr r2, _08014008 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #0xd1
	bgt _08014020
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	adds r1, r7, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl sub_C24
	ldr r2, [sp, #0x18]
	rsbs r1, r2, #0
	b _0801403E
	.align 2, 0
_08014004: .4byte 0x020314E0
_08014008: .4byte 0x0000132C
_0801400C: .4byte 0x00000EB8
_08014010: .4byte 0x00004E20
_08014014: .4byte 0xFFFF0000
_08014018: .4byte 0x0000FFFF
_0801401C: .4byte gMain
_08014020:
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r6, r0
	ldr r4, _08014070 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl sub_C24
	rsbs r1, r6, #0
_0801403E:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	ldr r1, _08014070 @ =0x00004E20
	bl __divsi3
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	mov r1, sp
	ldr r2, [sp, #0x10]
	bl sub_14074
	ldr r0, [sp]
	ldr r1, [sp, #0xc]
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r0, [r1, #2]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014070: .4byte 0x00004E20

	thumb_func_start sub_14074
sub_14074: @ 0x08014074
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, r5, #0
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	mov ip, r4
	ldr r0, _080140CC @ =0x020314E0
	mov sl, r0
	ldr r1, [r0]
	ldr r2, _080140D0 @ =0x0000132C
	adds r0, r1, r2
	ldr r3, [r0]
	movs r2, #0x30
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	mov sb, r2
	movs r2, #0x32
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	add sb, r0
	adds r1, #0x23
	ldrb r0, [r1]
	cmp r0, #2
	beq _080140B8
	b _08014230
_080140B8:
	movs r1, #0x28
	ldrsh r0, [r3, r1]
	cmp r0, #0xe0
	ble _080140DC
	ldr r2, _080140D4 @ =0xFFFFD5E4
	adds r0, r4, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r7, _080140D8 @ =0x00006A1C
	b _080140E8
	.align 2, 0
_080140CC: .4byte 0x020314E0
_080140D0: .4byte 0x0000132C
_080140D4: .4byte 0xFFFFD5E4
_080140D8: .4byte 0x00006A1C
_080140DC:
	ldr r0, _080140FC @ =0x000055E4
	mov r1, ip
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r7, _08014100 @ =0x000015E4
_080140E8:
	movs r0, #0x90
	lsls r0, r0, #5
	cmp r2, r0
	bhi _08014108
	ldr r0, _08014104 @ =0x00003FFF
	cmp sb, r0
	bgt _08014108
	movs r6, #0
	b _0801439C
	.align 2, 0
_080140FC: .4byte 0x000055E4
_08014100: .4byte 0x000015E4
_08014104: .4byte 0x00003FFF
_08014108:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	bl __divsi3
	mov r1, r8
	str r0, [r1]
	ldr r0, [r1, #4]
	movs r1, #5
	bl __divsi3
	mov r2, r8
	str r0, [r2, #4]
	ldr r0, _08014180 @ =0x020314E0
	ldr r4, [r0]
	ldr r1, _08014184 @ =0x0000132C
	adds r0, r4, r1
	ldr r5, [r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	lsls r0, r0, #2
	movs r1, #0xa
	bl __divsi3
	strh r0, [r5, #6]
	adds r4, #0x31
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014190
	adds r0, r7, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xe6
	muls r0, r1, r0
	ldr r4, _08014188 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801418C @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r7, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #1
	b _080141C8
	.align 2, 0
_08014180: .4byte 0x020314E0
_08014184: .4byte 0x0000132C
_08014188: .4byte 0x00004E20
_0801418C: .4byte 0xFFFF0000
_08014190:
	adds r0, r7, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08014200 @ =0x0000011D
	muls r0, r1, r0
	ldr r4, _08014204 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08014208 @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r7, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
_080141C8:
	rsbs r0, r0, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _0801420C @ =0x0000FFFF
	ands r6, r1
	orrs r6, r0
	ldr r2, _08014210 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _08014214 @ =0x00000716
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r2]
	ldr r2, _08014218 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x77
	bgt _08014220
	ldr r0, _0801421C @ =0x00000717
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	b _0801439C
	.align 2, 0
_08014200: .4byte 0x0000011D
_08014204: .4byte 0x00004E20
_08014208: .4byte 0xFFFF0000
_0801420C: .4byte 0x0000FFFF
_08014210: .4byte 0x020314E0
_08014214: .4byte 0x00000716
_08014218: .4byte 0x0000132C
_0801421C: .4byte 0x00000717
_08014220:
	ldr r2, _0801422C @ =0x00000717
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	b _0801439C
	.align 2, 0
_0801422C: .4byte 0x00000717
_08014230:
	cmp r0, #1
	beq _08014236
	b _08014340
_08014236:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	bl __divsi3
	mov r2, r8
	str r0, [r2]
	ldr r0, [r2, #4]
	movs r1, #5
	bl __divsi3
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _08014298 @ =0x00005FFF
	adds r0, r5, r2
	lsls r0, r0, #0x10
	ldr r1, _0801429C @ =0x3FFE0000
	cmp r0, r1
	bhi _080142A8
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080142A0 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080142A4 @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	rsbs r0, r0, #0
	b _0801438E
	.align 2, 0
_08014298: .4byte 0x00005FFF
_0801429C: .4byte 0x3FFE0000
_080142A0: .4byte 0x00004E20
_080142A4: .4byte 0xFFFF0000
_080142A8:
	ldr r1, _080142F0 @ =0xFFFFF000
	adds r0, r5, r1
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x17
	cmp r0, r1
	bhi _080142FC
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r4, _080142F4 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080142F8 @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	rsbs r0, r0, #0
	b _0801438E
	.align 2, 0
_080142F0: .4byte 0xFFFFF000
_080142F4: .4byte 0x00004E20
_080142F8: .4byte 0xFFFF0000
_080142FC:
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #3
	ldr r4, _08014338 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801433C @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	rsbs r0, r0, #0
	b _0801438E
	.align 2, 0
_08014338: .4byte 0x00004E20
_0801433C: .4byte 0xFFFF0000
_08014340:
	adds r0, r7, #0
	bl sub_C74
	ldr r5, _080143D4 @ =0x086ACDF4
	mov r2, sl
	ldr r1, [r2]
	adds r1, #0x23
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	ldr r4, _080143D8 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080143DC @ =0xFFFF0000
	ands r6, r1
	orrs r6, r0
	adds r0, r7, #0
	bl sub_C24
	mov r2, sl
	ldr r1, [r2]
	adds r1, #0x23
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	rsbs r1, r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
_0801438E:
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _080143E0 @ =0x0000FFFF
	ands r6, r1
	orrs r6, r0
_0801439C:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r0
	str r4, [r2]
	asrs r1, r6, #0x10
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r1, _080143E4 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _080143E8 @ =0x000005A4
	adds r3, r0, r2
	ldrb r2, [r3]
	adds r5, r1, #0
	cmp r2, #0
	beq _0801446C
	lsls r0, r4, #0x10
	lsrs r1, r0, #0x10
	movs r4, #1
	cmp r2, #1
	bne _080143EC
	movs r0, #0
	strb r0, [r3]
	movs r0, #0x80
	mov sb, r0
	b _080143F2
	.align 2, 0
_080143D4: .4byte 0x086ACDF4
_080143D8: .4byte 0x00004E20
_080143DC: .4byte 0xFFFF0000
_080143E0: .4byte 0x0000FFFF
_080143E4: .4byte 0x020314E0
_080143E8: .4byte 0x000005A4
_080143EC:
	movs r2, #0xa0
	lsls r2, r2, #2
	mov sb, r2
_080143F2:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08014402
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r4, _0801447C @ =0x0000FFFF
_08014402:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bgt _08014412
	lsls r0, r4, #0x10
	asrs r0, r0, #8
	mov r1, r8
	str r0, [r1]
_08014412:
	ldr r0, [r5]
	ldr r2, _08014480 @ =0x0000132C
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [r1, #4]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _08014484 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	mov r2, r8
	str r0, [r2]
	adds r0, r4, #0
	bl sub_C24
	mov r2, sb
	rsbs r1, r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	mov r1, r8
	str r0, [r1, #4]
_0801446C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801447C: .4byte 0x0000FFFF
_08014480: .4byte 0x0000132C
_08014484: .4byte 0x00004E20

	thumb_func_start sub_14488
sub_14488: @ 0x08014488
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r1, _08014510 @ =0xFFFF0000
	mov r0, r8
	ands r0, r1
	mov r8, r0
	movs r0, #1
	mov r2, r8
	orrs r2, r0
	mov r8, r2
	ldr r2, _08014514 @ =0x0000FFFF
	mov r3, r8
	ands r3, r2
	movs r0, #0x80
	lsls r0, r0, #9
	orrs r3, r0
	mov r8, r3
	lsls r0, r4, #0x10
	cmp r0, #0
	bge _080144CA
	orrs r3, r2
	mov r8, r3
	rsbs r0, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r4, r1
	orrs r4, r0
_080144CA:
	asrs r0, r4, #0x10
	cmp r0, #0
	bge _080144DE
	mov r3, r8
	orrs r3, r1
	mov r8, r3
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ands r4, r2
	orrs r4, r0
_080144DE:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	asrs r1, r4, #0x10
	movs r2, #1
	str r2, [sp, #8]
	cmp r0, r1
	ble _080144F0
	movs r3, #0
	str r3, [sp, #8]
_080144F0:
	ldr r2, _08014518 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x23
	strb r1, [r0]
	ldr r1, _0801451C @ =0x086ACE0C
	ldr r0, _08014520 @ =gMain
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	b _080145CC
	.align 2, 0
_08014510: .4byte 0xFFFF0000
_08014514: .4byte 0x0000FFFF
_08014518: .4byte 0x020314E0
_0801451C: .4byte 0x086ACE0C
_08014520: .4byte gMain
_08014524:
	ldrh r0, [r5]
	strh r0, [r7]
	ldrh r0, [r5, #2]
	strh r0, [r7, #2]
	mov r1, sp
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	b _0801456E
_08014536:
	ldr r5, _080145A0 @ =0x020314E0
	ldr r0, [r5]
	adds r0, #0x22
	strb r1, [r0]
	adds r0, r7, #0
	mov r1, sp
	bl sub_1467C
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0801454E
	b _08014668
_0801454E:
	ldr r0, [r5]
	ldr r3, _080145A4 @ =0x000005F2
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801456E
	adds r0, r7, #0
	mov r1, sp
	bl sub_14740
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0801456E
	b _08014668
_0801456E:
	lsls r0, r4, #0x10
	cmp r0, #0
	bgt _0801457A
	asrs r0, r4, #0x10
	cmp r0, #0
	ble _08014668
_0801457A:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _080145AC
	ldrh r0, [r7]
	add r0, r8
	strh r0, [r7]
	subs r1, r4, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080145A8 @ =0xFFFF0000
	ands r4, r0
	orrs r4, r1
	asrs r0, r4, #0x10
	cmp r0, #0
	ble _080145CC
	movs r1, #1
	str r1, [sp, #8]
	b _080145CC
	.align 2, 0
_080145A0: .4byte 0x020314E0
_080145A4: .4byte 0x000005F2
_080145A8: .4byte 0xFFFF0000
_080145AC:
	mov r2, r8
	asrs r0, r2, #0x10
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	strh r0, [r7, #2]
	asrs r1, r4, #0x10
	subs r1, #1
	lsls r1, r1, #0x10
	ldr r0, _08014658 @ =0x0000FFFF
	ands r4, r0
	orrs r4, r1
	lsls r0, r4, #0x10
	cmp r0, #0
	ble _080145CC
	movs r0, #0
	str r0, [sp, #8]
_080145CC:
	adds r0, r7, #0
	mov r1, sp
	ldr r2, [sp, #0xc]
	bl _call_via_r2
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08014536
	ldr r0, _0801465C @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08014668
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #3
	bne _0801456E
	movs r6, #0
	add r5, sp, #4
	movs r3, #2
	add r3, sp
	mov sb, r3
	ldr r0, _08014658 @ =0x0000FFFF
	mov sl, r0
_08014608:
	ldr r0, _08014660 @ =0x086ACE60
	lsls r3, r6, #2
	adds r3, r3, r0
	ldrh r1, [r3]
	ldrh r2, [r7]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08014664 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r3, #2]
	ldrh r3, [r7, #2]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sb
	ldr r3, [sp, #0xc]
	bl _call_via_r3
	ldr r0, _0801465C @ =0x020314E0
	ldr r0, [r0]
	ldrh r1, [r0, #0x22]
	mov r0, sl
	ands r0, r1
	cmp r0, #1
	bne _0801464C
	b _08014524
_0801464C:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #3
	bls _08014608
	b _0801456E
	.align 2, 0
_08014658: .4byte 0x0000FFFF
_0801465C: .4byte 0x020314E0
_08014660: .4byte 0x086ACE60
_08014664: .4byte 0xFFFF0000
_08014668:
	mov r0, sp
	ldrh r0, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_1467C
sub_1467C: @ 0x0801467C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r7, #0
	ldr r4, _08014734 @ =0x02031520
	movs r1, #0x22
	ldrsh r2, [r4, r1]
	lsls r2, r2, #1
	ldrh r3, [r0]
	subs r2, r3, r2
	lsls r2, r2, #0x10
	mov ip, r2
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	subs r3, r3, r1
	lsls r3, r3, #0x10
	movs r2, #0x20
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	ldrh r0, [r0, #2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	mov r1, ip
	lsrs r6, r1, #0x10
	orrs r6, r0
	lsrs r1, r0, #0x10
	lsrs r5, r3, #0x10
	orrs r5, r0
	cmp r1, #0x5f
	bhi _08014724
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _080146E8
	ldr r4, _08014738 @ =0x020314E0
	ldr r0, [r4]
	ldrb r1, [r0, #0x1e]
	adds r1, #1
	adds r0, r6, #0
	mov r2, r8
	movs r3, #0
	bl sub_14AF4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080146E8
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #3
	strb r1, [r0]
	movs r7, #1
_080146E8:
	cmp r7, #0
	bne _08014724
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _08014724
	movs r0, #0x5f
	subs r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0801473C @ =0xFFFF0000
	ands r5, r1
	orrs r5, r0
	ldr r4, _08014738 @ =0x020314E0
	ldr r0, [r4]
	ldrb r1, [r0, #0x1e]
	adds r1, #1
	adds r0, r5, #0
	mov r2, r8
	movs r3, #1
	bl sub_14AF4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08014724
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #4
	strb r1, [r0]
	movs r7, #1
_08014724:
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08014734: .4byte 0x02031520
_08014738: .4byte 0x020314E0
_0801473C: .4byte 0xFFFF0000

	thumb_func_start sub_14740
sub_14740: @ 0x08014740
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r7, r1, #0
	movs r6, #0
	ldr r0, _080147E8 @ =0x020314E0
	ldr r4, [r0]
	ldr r5, _080147EC @ =0x000005A4
	adds r1, r4, r5
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #2
	bne _0801475A
	b _08014924
_0801475A:
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	movs r3, #2
	ldrsh r0, [r2, r3]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r2, r4, #0
	adds r2, #0xc6
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r1, #0x10
	orrs r3, r0
	adds r1, r0, #0
	lsrs r0, r1, #0x10
	cmp r0, #0x2f
	bls _08014790
	b _08014924
_08014790:
	lsls r2, r3, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x2f
	bls _0801479A
	b _08014924
_0801479A:
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r2, #0x10
	adds r0, r0, r1
	ldr r1, _080147F0 @ =0x0839A28C
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	bne _080147B6
	b _08014924
_080147B6:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #0x23
	movs r1, #3
	strb r1, [r0]
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	strh r0, [r7]
	ldr r2, [r5]
	ldr r0, _080147F4 @ =0x000005A6
	adds r1, r2, r0
	movs r0, #0x14
	strh r0, [r1]
	ldr r1, _080147F8 @ =0x000005A9
	adds r2, r2, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080147FC
	movs r0, #0x18
	b _080147FE
	.align 2, 0
_080147E8: .4byte 0x020314E0
_080147EC: .4byte 0x000005A4
_080147F0: .4byte 0x0839A28C
_080147F4: .4byte 0x000005A6
_080147F8: .4byte 0x000005A9
_080147FC:
	movs r0, #0x14
_080147FE:
	strb r0, [r2]
	ldr r1, [r5]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0xc8
	bne _080148A4
	ldr r3, _0801484C @ =0x000005AA
	adds r0, r1, r3
	ldrh r3, [r0]
	cmp r3, #0
	bne _0801487E
	adds r2, #0xd
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #3
	bne _08014858
	adds r0, r2, #0
	adds r0, r1, r0
	ldr r1, _08014850 @ =0x0000071C
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _08014854 @ =0x000005A4
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	b _08014870
	.align 2, 0
_0801484C: .4byte 0x000005AA
_08014850: .4byte 0x0000071C
_08014854: .4byte 0x000005A4
_08014858:
	ldrb r0, [r0]
	adds r0, r1, r0
	ldr r3, _08014890 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, _08014894 @ =0x000005A4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r5]
_08014870:
	ldr r0, _08014898 @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, [r5]
	ldr r2, _0801489C @ =0x000005AA
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
_0801487E:
	movs r6, #1
	ldr r0, _080148A0 @ =0x00000145
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	b _08014924
	.align 2, 0
_08014890: .4byte 0x0000071C
_08014894: .4byte 0x000005A4
_08014898: .4byte 0x00002710
_0801489C: .4byte 0x000005AA
_080148A0: .4byte 0x00000145
_080148A4:
	ldr r3, _080148E0 @ =0x000005AA
	adds r0, r1, r3
	ldrh r3, [r0]
	cmp r3, #0
	bne _08014916
	ldr r2, _080148E4 @ =0x000005A5
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #3
	bne _080148F0
	adds r0, r2, #0
	adds r0, r1, r0
	ldr r1, _080148E8 @ =0x0000071C
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _080148EC @ =0x000005A4
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	b _08014908
	.align 2, 0
_080148E0: .4byte 0x000005AA
_080148E4: .4byte 0x000005A5
_080148E8: .4byte 0x0000071C
_080148EC: .4byte 0x000005A4
_080148F0:
	ldrb r0, [r0]
	adds r0, r1, r0
	ldr r3, _0801492C @ =0x0000071C
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, _08014930 @ =0x000005A4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r5]
_08014908:
	ldr r0, _08014934 @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, [r5]
	ldr r2, _08014938 @ =0x000005AA
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
_08014916:
	movs r6, #1
	movs r0, #0x74
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_08014924:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801492C: .4byte 0x0000071C
_08014930: .4byte 0x000005A4
_08014934: .4byte 0x00002710
_08014938: .4byte 0x000005AA

	thumb_func_start sub_1493C
sub_1493C: @ 0x0801493C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08014A28 @ =0x020314E0
	mov sb, r0
	ldr r4, [r0]
	ldr r1, _08014A2C @ =0x0000132C
	mov r8, r1
	adds r0, r4, r1
	ldr r2, [r0]
	ldrh r1, [r2, #0x28]
	subs r1, #0xee
	lsls r1, r1, #0x10
	ldr r5, _08014A30 @ =0xFFFFFDD2
	adds r0, r5, #0
	ldrh r2, [r2, #0x2a]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r1, #0x10
	orrs r3, r0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	asrs r2, r3, #0x10
	adds r0, r2, #0
	muls r0, r2, r0
	adds r7, r1, r0
	ldr r0, _08014A34 @ =0x000006E3
	cmp r7, r0
	bgt _08014A04
	ldrb r1, [r4, #0x1e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08014A04
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, #0
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r5, #0x1e
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	ldr r6, _08014A38 @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r4, #0
	bl sub_C24
	rsbs r5, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #4]
	mov r0, sb
	ldr r4, [r0]
	add r4, r8
	ldr r5, [r4]
	movs r1, #0x64
	mov r8, r1
	ldr r2, [sp]
	mov r0, r8
	muls r0, r2, r0
	movs r2, #0x30
	ldrsh r1, [r5, r2]
	movs r6, #0x62
	muls r1, r6, r1
	adds r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0x30]
	ldr r4, [r4]
	ldr r5, [sp, #4]
	mov r0, r8
	muls r0, r5, r0
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	muls r1, r6, r1
	adds r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r4, #0x32]
_08014A04:
	ldr r0, _08014A28 @ =0x020314E0
	ldr r1, [r0]
	ldr r5, _08014A3C @ =0x000005F4
	adds r3, r1, r5
	ldrh r0, [r3]
	adds r2, r0, #0
	cmp r2, #0x13
	bhi _08014A5C
	cmp r7, #0x27
	bgt _08014A40
	adds r0, #1
	strh r0, [r3]
	ldr r2, _08014A2C @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	b _08014ADC
	.align 2, 0
_08014A28: .4byte 0x020314E0
_08014A2C: .4byte 0x0000132C
_08014A30: .4byte 0xFFFFFDD2
_08014A34: .4byte 0x000006E3
_08014A38: .4byte 0x00004E20
_08014A3C: .4byte 0x000005F4
_08014A40:
	ldr r5, _08014A58 @ =0x0000132C
	adds r0, r1, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0xe]
	cmp r7, #0x64
	ble _08014ADE
	movs r0, #0
	strh r0, [r3]
	b _08014ADE
	.align 2, 0
_08014A58: .4byte 0x0000132C
_08014A5C:
	cmp r2, #0x1d
	bhi _08014AA8
	adds r0, #1
	movs r6, #0
	strh r0, [r3]
	ldr r0, _08014AA4 @ =0x0000132C
	adds r4, r1, r0
	ldr r5, [r4]
	ldrh r1, [r3]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r0, r0, #7
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x80
	strh r0, [r5, #0xe]
	ldr r1, [r4]
	movs r0, #0x77
	strh r0, [r1, #0x10]
	ldr r1, [r4]
	adds r0, #0xa0
	strh r0, [r1, #0x12]
	ldr r0, [r4]
	strh r6, [r0, #6]
	ldr r1, [r4]
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r5, #0x12
	ldrsh r0, [r1, r5]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	b _08014ADE
	.align 2, 0
_08014AA4: .4byte 0x0000132C
_08014AA8:
	movs r0, #0
	strh r0, [r3]
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08014AC0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08014AC4
	bl sub_1A98C
	b _08014AC8
	.align 2, 0
_08014AC0: .4byte gMain
_08014AC4:
	bl sub_32914
_08014AC8:
	ldr r2, _08014AEC @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08014AF0 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x80
_08014ADC:
	strh r0, [r1, #0xe]
_08014ADE:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014AEC: .4byte 0x020314E0
_08014AF0: .4byte 0x0000132C

	thumb_func_start sub_14AF4
sub_14AF4: @ 0x08014AF4
	push {r4, r5, r6, r7, lr}
	adds r7, r2, #0
	movs r2, #0
	mov ip, r2
	asrs r2, r0, #0x10
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r4, r4, #5
	adds r4, r4, r0
	lsls r4, r4, #0x10
	ldr r2, _08014B70 @ =0x020314E0
	lsls r3, r3, #0x10
	asrs r6, r3, #0x10
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r3, _08014B74 @ =0x000013BC
	adds r0, r0, r3
	ldr r3, [r2]
	adds r3, r3, r0
	ldr r5, _08014B78 @ =0x086ACDB8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #2
	ldrsb r2, [r3, r2]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r0, [r1]
	strb r0, [r3, #5]
	ldr r0, _08014B7C @ =0x02031520
	movs r1, #5
	ldrsb r1, [r3, r1]
	ldr r2, [r0, #0x68]
	lsrs r4, r4, #0xf
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0xb
	adds r0, r0, r2
	adds r4, r4, r0
	ldrh r4, [r4]
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	beq _08014B66
	ldr r1, _08014B80 @ =0x0000FFF0
	ands r1, r4
	strh r1, [r7]
	cmp r6, #1
	bne _08014B62
	movs r0, #0x80
	lsls r0, r0, #8
	subs r0, r0, r1
	strh r0, [r7]
_08014B62:
	movs r0, #1
	mov ip, r0
_08014B66:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08014B70: .4byte 0x020314E0
_08014B74: .4byte 0x000013BC
_08014B78: .4byte 0x086ACDB8
_08014B7C: .4byte 0x02031520
_08014B80: .4byte 0x0000FFF0

	thumb_func_start sub_14B84
sub_14B84: @ 0x08014B84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov r8, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r0, _08014C20 @ =0x020314E0
	ldr r2, [r0]
	lsls r3, r1, #0x10
	asrs r0, r3, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r2, r1
	ldr r6, _08014C24 @ =0x000013C1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08014C28 @ =0x000013C4
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08014BC8
	b _08014D3E
_08014BC8:
	adds r0, r2, #0
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov sb, r3
	cmp r0, #0
	beq _08014BD8
	b _08014CF2
_08014BD8:
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	subs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r5, r5, r0
	ldr r0, _08014C2C @ =0x00000B21
	cmp r5, r0
	bgt _08014C34
	ldr r2, _08014C30 @ =0xFFFFF5D8
	adds r4, r5, r2
	lsls r0, r4, #0xb
	movs r1, #0x96
	lsls r1, r1, #2
	bl __divsi3
	movs r3, #0x90
	lsls r3, r3, #7
	adds r1, r3, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r4, r4, #7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, #0
	bl __divsi3
	adds r7, r0, #0
	adds r7, #0x78
	b _08014C68
	.align 2, 0
_08014C20: .4byte 0x020314E0
_08014C24: .4byte 0x000013C1
_08014C28: .4byte 0x000013C4
_08014C2C: .4byte 0x00000B21
_08014C30: .4byte 0xFFFFF5D8
_08014C34:
	ldr r0, _08014D14 @ =0x086ACE2C
	lsls r1, r2, #2
	adds r6, r1, r0
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, _08014D18 @ =0xFFFFF5D8
	adds r4, r5, r1
	muls r0, r4, r0
	ldr r5, _08014D1C @ =0x00001518
	adds r1, r5, #0
	bl __divsi3
	ldrh r1, [r6]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0xae
	lsls r0, r0, #1
	muls r0, r4, r0
	adds r1, r5, #0
	bl __divsi3
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r7, r0, r2
_08014C68:
	mov r3, sl
	lsls r0, r3, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08014C7E
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	subs r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08014C7E:
	ldr r2, _08014D20 @ =0x020314E0
	mov sl, r2
	ldr r0, [r2]
	ldr r3, _08014D24 @ =0x0000132C
	adds r0, r0, r3
	ldr r2, [r0]
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #9
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08014C9C
	adds r0, #0x7f
_08014C9C:
	asrs r3, r0, #7
	movs r0, #8
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08014CB0
	adds r0, #0xff
_08014CB0:
	asrs r0, r0, #8
	adds r0, r3, r0
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	bl sub_C74
	mov r1, sl
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r5, _08014D28 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	adds r4, #0x60
	strh r0, [r4]
	adds r0, r6, #0
	bl sub_C24
	mov r2, sl
	ldr r4, [r2]
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	adds r4, #0x62
	strh r0, [r4]
_08014CF2:
	ldr r2, _08014D20 @ =0x020314E0
	ldr r3, [r2]
	adds r1, r3, #0
	adds r1, #0x5c
	movs r0, #1
	strh r0, [r1]
	mov r6, sb
	cmp r6, #0
	beq _08014D2C
	adds r0, r3, #0
	adds r0, #0x60
	ldrh r0, [r0]
	rsbs r0, r0, #0
	mov r1, r8
	strh r0, [r1]
	b _08014D36
	.align 2, 0
_08014D14: .4byte 0x086ACE2C
_08014D18: .4byte 0xFFFFF5D8
_08014D1C: .4byte 0x00001518
_08014D20: .4byte 0x020314E0
_08014D24: .4byte 0x0000132C
_08014D28: .4byte 0x00004E20
_08014D2C:
	adds r0, r3, #0
	adds r0, #0x60
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
_08014D36:
	ldr r0, [r2]
	adds r0, #0x62
	ldrh r0, [r0]
	b _08014DEA
_08014D3E:
	adds r0, r5, #0
	movs r1, #0x14
	bl __divsi3
	adds r5, r0, #0
	adds r0, r7, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	ldr r6, _08014DFC @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08014E00 @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	adds r0, r7, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	rsbs r0, r0, #0
	adds r1, r6, #0
	bl __divsi3
	lsls r0, r0, #0x10
	ldr r1, _08014E04 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, r4, r0
	mov r3, r8
	strh r0, [r3]
	asrs r1, r4, #0x10
	movs r0, #2
	ldrsh r2, [r3, r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, r1, r0
	strh r1, [r3, #2]
	movs r2, #0
	ldrsh r0, [r3, r2]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	mov r3, r8
	strh r0, [r3]
	adds r0, r4, #0
	bl sub_C24
	rsbs r5, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
_08014DEA:
	mov r6, r8
	strh r0, [r6, #2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014DFC: .4byte 0x00004E20
_08014E00: .4byte 0xFFFF0000
_08014E04: .4byte 0x0000FFFF

	thumb_func_start sub_14E08
sub_14E08: @ 0x08014E08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _08014F0C @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08014F10 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, sb
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _08014E3A
	adds r0, r4, #7
_08014E3A:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08014F14 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08014E56
	adds r0, r3, #7
_08014E56:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _08014F18 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08014E82
	adds r2, #0x3f
_08014E82:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _08014F1C @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_15054
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _08014F00
	b _0801502C
_08014F00:
	lsls r0, r0, #2
	ldr r1, _08014F20 @ =_08014F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08014F0C: .4byte 0x020314E0
_08014F10: .4byte 0x0000132C
_08014F14: .4byte 0xFFFF0000
_08014F18: .4byte 0x0000FFFF
_08014F1C: .4byte 0x02031520
_08014F20: .4byte _08014F24
_08014F24: @ jump table
	.4byte _08014F3C @ case 0
	.4byte _08014FE8 @ case 1
	.4byte _08014FE8 @ case 2
	.4byte _08014F3C @ case 3
	.4byte _08015018 @ case 4
	.4byte _08014F3C @ case 5
_08014F3C:
	ldr r2, _08014FB4 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08014FB8 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08014FDC
	ldr r0, [r2]
	ldr r7, _08014FBC @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08014FC0 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08014F88
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08014FDC
_08014F88:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08014FA6
	cmp r0, #0
	bne _08014FD2
	ldr r0, _08014FC4 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08014FC8
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_08014FA6:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _08014FDC
	.align 2, 0
_08014FB4: .4byte 0x020314E0
_08014FB8: .4byte 0xFFFFC010
_08014FBC: .4byte 0x0000132C
_08014FC0: .4byte 0x02031520
_08014FC4: .4byte gMain
_08014FC8:
	ldr r0, _08014FE4 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08014FD2:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_08014FDC:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _0801502C
	.align 2, 0
_08014FE4: .4byte 0x0000FFD8
_08014FE8:
	ldr r2, _08015010 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08015014 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _0801502C
	.align 2, 0
_08015010: .4byte 0x020314E0
_08015014: .4byte 0x0000FFF0
_08015018:
	ldr r2, _0801504C @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _08015050 @ =0x000002A2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
	movs r6, #0
_0801502C:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_153CC
	mov r2, sp
	movs r4, #4
	ldrsh r0, [r2, r4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801504C: .4byte 0x020314E0
_08015050: .4byte 0x000002A2

	thumb_func_start sub_15054
sub_15054: @ 0x08015054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	str r1, [sp]
	mov ip, r2
	movs r7, #0
	movs r5, #0
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _08015128 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801512C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r1, #0
	beq _08015084
	b _08015298
_08015084:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015094
	b _0801539A
_08015094:
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015146
	ldr r1, _08015130 @ =0x000002A3
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080150B4
	b _0801539A
_080150B4:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	ldrh r6, [r4]
	adds r1, r1, r6
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	ldrh r4, [r4, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	cmp r0, #0x4f
	bls _080150D8
	b _0801539A
_080150D8:
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x57
	bls _080150E2
	b _0801539A
_080150E2:
	ldr r2, _08015134 @ =0x08259C10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08015138 @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _08015104
	b _0801539A
_08015104:
	ldr r6, [sp]
	strh r7, [r6]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0801513C @ =0x000002A2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08015140
	mov r3, ip
	strb r5, [r3]
	ldr r0, [r1]
	adds r0, r0, r2
	movs r1, #7
	strb r1, [r0]
	b _0801539A
	.align 2, 0
_08015128: .4byte 0x020314E0
_0801512C: .4byte 0x000005B2
_08015130: .4byte 0x000002A3
_08015134: .4byte 0x08259C10
_08015138: .4byte 0x0000FFF0
_0801513C: .4byte 0x000002A2
_08015140:
	movs r0, #1
	mov r6, ip
	b _08015398
_08015146:
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08015154
	b _0801539A
_08015154:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	movs r6, #0xc3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r6, r1, #0x10
	lsrs r0, r6, #0x10
	mov sb, r3
	mov sl, r2
	cmp r0, #0x3f
	bhi _080151A2
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080151A2
	ldr r2, _08015288 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r6, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	beq _080151A6
	movs r0, #0
	str r0, [sp, #4]
_080151A2:
	cmp r5, #0
	bne _08015246
_080151A6:
	mov r1, r8
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, sb
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080151F0
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080151F0
	ldr r2, _08015288 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	beq _080151F4
	movs r0, #1
	str r0, [sp, #4]
_080151F0:
	cmp r5, #0
	bne _08015246
_080151F4:
	mov r1, r8
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, sb
	movs r6, #0xc7
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	add r0, sl
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _08015240
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08015240
	ldr r2, _08015288 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _0801528C @ =0x0000FFF0
	ands r7, r0
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _0801523C
	b _0801539A
_0801523C:
	movs r0, #2
	str r0, [sp, #4]
_08015240:
	cmp r5, #0
	bne _08015246
	b _0801539A
_08015246:
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _08015290 @ =0x0000016F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015266
	movs r6, #0xb8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldr r1, [sp, #4]
	adds r0, r0, r1
	movs r1, #0x6b
	strb r1, [r0]
_08015266:
	ldr r2, [sp]
	strh r7, [r2]
	mov r3, ip
	strb r5, [r3]
	mov r6, r8
	ldr r0, [r6]
	ldr r2, _08015294 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08015280
	b _0801539A
_08015280:
	movs r0, #2
	strb r0, [r1]
	b _0801539A
	.align 2, 0
_08015288: .4byte 0x08252B10
_0801528C: .4byte 0x0000FFF0
_08015290: .4byte 0x0000016F
_08015294: .4byte 0x00000624
_08015298:
	mov r3, ip
	ldrb r1, [r3]
	movs r5, #0xf
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0801539A
	ldr r6, _080153AC @ =0x000002E5
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08015320
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x18
	rsbs r1, r1, #0
	subs r1, r1, r0
	lsls r1, r1, #1
	ldrh r3, [r4]
	adds r1, r1, r3
	ldr r6, _080153B0 @ =0xFFFFFDBC
	adds r0, r6, #0
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x47
	bhi _08015320
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x47
	bhi _08015320
	ldr r2, _080153B4 @ =0x08254B10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, _080153B8 @ =0x0000FFF0
	ands r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	adds r0, r5, #0
	ands r0, r1
	mov r6, ip
	strb r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08015320
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _080153BC @ =0x000002E2
	adds r0, r0, r3
	strb r1, [r0]
	movs r0, #6
	strb r0, [r6]
_08015320:
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _080153C0 @ =0x000002E6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0801539A
	ldr r3, _080153C4 @ =0x000002EE
	adds r0, r1, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	subs r1, #0xb4
	lsls r1, r1, #1
	ldrh r0, [r4]
	adds r1, r1, r0
	ldr r2, _080153B0 @ =0xFFFFFDBC
	adds r0, r2, #0
	ldrh r4, [r4, #2]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	cmp r0, #0x47
	bhi _0801539A
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x47
	bhi _0801539A
	ldr r2, _080153C8 @ =0x08257390
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r0, _080153B8 @ =0x0000FFF0
	ands r0, r1
	ldr r3, [sp]
	strh r0, [r3]
	movs r0, #0xf
	ands r0, r1
	mov r6, ip
	strb r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801539A
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080153BC @ =0x000002E2
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	movs r0, #6
_08015398:
	strb r0, [r6]
_0801539A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080153AC: .4byte 0x000002E5
_080153B0: .4byte 0xFFFFFDBC
_080153B4: .4byte 0x08254B10
_080153B8: .4byte 0x0000FFF0
_080153BC: .4byte 0x000002E2
_080153C0: .4byte 0x000002E6
_080153C4: .4byte 0x000002EE
_080153C8: .4byte 0x08257390

	thumb_func_start sub_153CC
sub_153CC: @ 0x080153CC
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r6, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bls _080153E0
	bl _08016082
_080153E0:
	lsls r0, r0, #2
	ldr r1, _080153EC @ =_080153F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080153EC: .4byte _080153F0
_080153F0: @ jump table
	.4byte _0801542C @ case 0
	.4byte _08015494 @ case 1
	.4byte _080154E0 @ case 2
	.4byte _08015578 @ case 3
	.4byte _08015620 @ case 4
	.4byte _0801564C @ case 5
	.4byte _0801567C @ case 6
	.4byte _08015764 @ case 7
	.4byte _08015AA4 @ case 8
	.4byte _08015AF0 @ case 9
	.4byte _08015CA0 @ case 10
	.4byte _08015E4C @ case 11
	.4byte _08015EB4 @ case 12
	.4byte _08015F20 @ case 13
	.4byte _08015F8C @ case 14
_0801542C:
	ldr r0, _0801545C @ =0x020314E0
	ldr r2, [r0]
	ldrh r0, [r2, #0x26]
	cmp r0, #0
	beq _0801543A
	bl _08016082
_0801543A:
	ldr r1, _08015460 @ =0x0000132C
	adds r0, r2, r1
	ldr r3, [r0]
	movs r4, #0x28
	ldrsh r1, [r3, r4]
	ldr r0, _08015464 @ =0x00000167
	cmp r1, r0
	ble _08015470
	movs r1, #0x2a
	ldrsh r0, [r3, r1]
	cmp r0, #0xc7
	ble _08015468
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #1
	b _08015476
	.align 2, 0
_0801545C: .4byte 0x020314E0
_08015460: .4byte 0x0000132C
_08015464: .4byte 0x00000167
_08015468:
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #3
	b _08015476
_08015470:
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #2
_08015476:
	strb r0, [r1]
	bl sub_1A98C
	ldr r0, _08015490 @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	movs r0, #1
	strh r0, [r7]
	bl _08016082
	.align 2, 0
_08015490: .4byte 0x020314E0
_08015494:
	ldr r3, _080154B8 @ =0x020314E0
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _080154C0
	ldr r4, _080154BC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080154B8: .4byte 0x020314E0
_080154BC: .4byte 0x0000132C
_080154C0:
	cmp r1, #2
	beq _080154C8
	bl _08016082
_080154C8:
	ldr r4, _080154DC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080154DC: .4byte 0x0000132C
_080154E0:
	ldr r1, _08015508 @ =0x020314E0
	ldr r2, [r1]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #2
	bne _08015510
	ldr r1, _0801550C @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	movs r2, #0
	movs r0, #3
	strb r0, [r1, #1]
	ldr r0, [r5]
	adds r0, #0x24
	strb r2, [r0]
	b _08015524
	.align 2, 0
_08015508: .4byte 0x020314E0
_0801550C: .4byte 0x0000132C
_08015510:
	cmp r0, #3
	bne _08015524
	ldr r3, _0801556C @ =0x0000132C
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r5]
	adds r0, #0x24
	strb r1, [r0]
_08015524:
	ldr r0, [r5]
	ldr r4, _08015570 @ =0x000002FB
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bne _08015536
	movs r0, #7
	strb r0, [r1]
_08015536:
	ldr r0, [r5]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r3, #0xf0
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0801554E
	movs r0, #0
	strb r0, [r2]
_0801554E:
	ldr r0, [r5]
	ldr r2, _08015574 @ =0x000001AB
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	ands r0, r3
	cmp r0, #0
	bne _08015562
	bl _08016082
_08015562:
	movs r0, #0
	strb r0, [r1]
	bl _08016082
	.align 2, 0
_0801556C: .4byte 0x0000132C
_08015570: .4byte 0x000002FB
_08015574: .4byte 0x000001AB
_08015578:
	ldr r1, _080155B8 @ =0x020314E0
	ldr r2, [r1]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r3, [r0]
	adds r5, r1, #0
	cmp r3, #0
	beq _0801558E
	bl _08016082
_0801558E:
	ldr r4, _080155BC @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x83
	ble _080155C4
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
	ldr r3, _080155C0 @ =0x0000070E
	adds r1, r2, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x62
	bgt _08015604
	adds r0, r2, #1
	strb r0, [r1]
	b _08015604
	.align 2, 0
_080155B8: .4byte 0x020314E0
_080155BC: .4byte 0x0000132C
_080155C0: .4byte 0x0000070E
_080155C4:
	cmp r0, #0x5b
	ble _080155E4
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r2, #0x3c]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r3, [r0]
	ldr r0, _080155E0 @ =0x0000016F
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	b _08015604
	.align 2, 0
_080155E0: .4byte 0x0000016F
_080155E4:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
	ldr r3, _0801561C @ =0x000002B2
	adds r1, r2, r3
	movs r2, #0
	ldrsb r2, [r1, r2]
	cmp r2, #0
	bne _08015604
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xac
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r2, [r0]
_08015604:
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x76
	bl m4aSongNumStart
	bl _08016082
	.align 2, 0
_0801561C: .4byte 0x000002B2
_08015620:
	ldr r1, _08015640 @ =0x020314E0
	ldr r0, [r1]
	adds r0, #0x20
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	ldr r4, _08015644 @ =0x00000165
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r1]
	ldr r1, _08015648 @ =0x00000732
	adds r0, r0, r1
	strb r3, [r0]
	bl _08016082
	.align 2, 0
_08015640: .4byte 0x020314E0
_08015644: .4byte 0x00000165
_08015648: .4byte 0x00000732
_0801564C:
	ldr r4, _08015670 @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _08015674 @ =0x000005B2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08015662
	bl _08016082
_08015662:
	movs r0, #1
	bl sub_46FD4
	ldr r0, [r4]
	ldr r3, _08015678 @ =0x0000029E
	b _0801588E
	.align 2, 0
_08015670: .4byte 0x020314E0
_08015674: .4byte 0x000005B2
_08015678: .4byte 0x0000029E
_0801567C:
	ldr r5, _080156C4 @ =0x020314E0
	ldr r1, [r5]
	ldr r4, _080156C8 @ =0x0000132C
	mov ip, r4
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x31
	bgt _080156D4
	ldr r3, _080156CC @ =0x000002FA
	adds r0, r1, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _08015734
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r4, _080156D0 @ =0x000002FB
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	strh r2, [r7]
	b _08015734
	.align 2, 0
_080156C4: .4byte 0x020314E0
_080156C8: .4byte 0x0000132C
_080156CC: .4byte 0x000002FA
_080156D0: .4byte 0x000002FB
_080156D4:
	ldr r2, _08015744 @ =0x000002FA
	adds r0, r1, r2
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _08015734
	movs r3, #0
	movs r2, #2
	strb r2, [r0]
	ldr r0, [r5]
	ldr r1, _08015748 @ =0x000002FB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r2, [r0]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r4, [r7]
	ldr r1, [r5]
	mov r4, ip
	adds r2, r1, r4
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
	ldr r4, _0801574C @ =0x00001378
	adds r0, r1, r4
	ldr r2, _08015750 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r0, [r5]
	ldr r3, _08015754 @ =0x00001330
	adds r1, r0, r3
	adds r4, r0, r4
	str r4, [r1]
	ldr r4, _08015758 @ =0x00001328
	adds r0, r0, r4
	movs r1, #0x78
	strh r1, [r0]
_08015734:
	ldr r0, _0801575C @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _08015760 @ =0x00000732
	adds r0, r0, r1
	movs r1, #0xe
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_08015744: .4byte 0x000002FA
_08015748: .4byte 0x000002FB
_0801574C: .4byte 0x00001378
_08015750: .4byte 0x00001334
_08015754: .4byte 0x00001330
_08015758: .4byte 0x00001328
_0801575C: .4byte 0x020314E0
_08015760: .4byte 0x00000732
_08015764:
	ldr r0, _080157A8 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _080157AC @ =0x0000132C
	adds r1, r2, r3
	ldr r1, [r1]
	movs r4, #0x10
	ldrsh r1, [r1, r4]
	adds r5, r0, #0
	cmp r1, #0x32
	bgt _0801580C
	ldr r1, _080157B0 @ =0x00000732
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _080157EA
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _080157DC
	ldr r3, _080157B4 @ =0x0000072E
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080157DC
	cmp r0, #0
	bne _080157B8
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080157C6
	.align 2, 0
_080157A8: .4byte 0x020314E0
_080157AC: .4byte 0x0000132C
_080157B0: .4byte 0x00000732
_080157B4: .4byte 0x0000072E
_080157B8:
	cmp r0, #1
	bne _080157C4
	ldr r0, _080157C0 @ =0x00001388
	b _080157C6
	.align 2, 0
_080157C0: .4byte 0x00001388
_080157C4:
	ldr r0, _080157F8 @ =0x00002710
_080157C6:
	str r0, [r2, #0x3c]
	ldr r0, _080157FC @ =0x020314E0
	ldr r1, [r0]
	ldr r4, _08015800 @ =0x0000072E
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x99
	bl m4aSongNumStart
_080157DC:
	ldr r0, _080157FC @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08015804 @ =0x000006BC
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	adds r5, r0, #0
_080157EA:
	ldr r0, [r5]
	ldr r3, _08015808 @ =0x00000732
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_080157F8: .4byte 0x00002710
_080157FC: .4byte 0x020314E0
_08015800: .4byte 0x0000072E
_08015804: .4byte 0x000006BC
_08015808: .4byte 0x00000732
_0801580C:
	cmp r1, #0x64
	bgt _080158A8
	ldr r4, _0801584C @ =0x00000732
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801588A
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r2, #0xa
	strb r2, [r0]
	ldr r1, [r5]
	subs r4, #7
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08015878
	cmp r0, #0
	bne _08015850
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	b _0801586C
	.align 2, 0
_0801584C: .4byte 0x00000732
_08015850:
	cmp r0, #1
	bne _08015864
	ldr r0, _08015860 @ =0x00001388
	str r0, [r1, #0x3c]
	adds r1, r1, r3
	movs r0, #5
	strb r0, [r1]
	b _0801586C
	.align 2, 0
_08015860: .4byte 0x00001388
_08015864:
	ldr r0, _08015898 @ =0x00002710
	str r0, [r1, #0x3c]
	adds r0, r1, r3
	strb r2, [r0]
_0801586C:
	ldr r1, [r5]
	ldr r0, _0801589C @ =0x0000072B
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08015878:
	ldr r0, [r5]
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r2, _080158A0 @ =0x0000072C
	adds r0, r0, r2
	strh r1, [r0]
_0801588A:
	ldr r0, [r5]
	ldr r3, _080158A4 @ =0x00000732
_0801588E:
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bl _08016082
	.align 2, 0
_08015898: .4byte 0x00002710
_0801589C: .4byte 0x0000072B
_080158A0: .4byte 0x0000072C
_080158A4: .4byte 0x00000732
_080158A8:
	cmp r1, #0x7e
	bgt _08015918
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080158C2
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_080158C2:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801590C @ =0x00000732
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08015910 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080158E6
	bl _08016082
_080158E6:
	subs r2, #2
	adds r0, r1, r2
	adds r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _080158FA
	b _08016082
_080158FA:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _08015914 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_0801590C: .4byte 0x00000732
_08015910: .4byte 0x0000071B
_08015914: .4byte 0x0000071C
_08015918:
	cmp r1, #0x94
	bgt _08015988
	ldr r1, _08015978 @ =0x00000719
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015930
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_08015930:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801597C @ =0x00000732
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08015980 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08015952
	b _08016082
_08015952:
	subs r2, #3
	adds r0, r1, r2
	adds r2, #2
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08015966
	b _08016082
_08015966:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _08015984 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_08015978: .4byte 0x00000719
_0801597C: .4byte 0x00000732
_08015980: .4byte 0x0000071B
_08015984: .4byte 0x0000071C
_08015988:
	cmp r1, #0xac
	bgt _080159F8
	ldr r1, _080159E8 @ =0x0000071A
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080159A0
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r2, #0x3c]
_080159A0:
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _080159EC @ =0x00000732
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _080159F0 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080159C2
	b _08016082
_080159C2:
	subs r2, #3
	adds r0, r1, r2
	adds r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _080159D6
	b _08016082
_080159D6:
	strb r4, [r3]
	ldr r0, [r5]
	ldr r3, _080159F4 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r5]
	b _08015C7E
	.align 2, 0
_080159E8: .4byte 0x0000071A
_080159EC: .4byte 0x00000732
_080159F0: .4byte 0x0000071B
_080159F4: .4byte 0x0000071C
_080159F8:
	ldr r4, _08015A28 @ =0x00000732
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _08015A78
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _08015A6A
	ldr r1, _08015A2C @ =0x0000072F
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08015A6A
	cmp r0, #0
	bne _08015A30
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08015A3E
	.align 2, 0
_08015A28: .4byte 0x00000732
_08015A2C: .4byte 0x0000072F
_08015A30:
	cmp r0, #1
	bne _08015A3C
	ldr r0, _08015A38 @ =0x00001388
	b _08015A3E
	.align 2, 0
_08015A38: .4byte 0x00001388
_08015A3C:
	ldr r0, _08015A84 @ =0x00002710
_08015A3E:
	str r0, [r2, #0x3c]
	ldr r5, _08015A88 @ =0x020314E0
	ldr r1, [r5]
	ldr r4, _08015A8C @ =0x0000072F
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08015A90 @ =0x02032F20
	ldr r1, _08015A94 @ =0x0869FC0C
	bl MPlayStart
	ldr r1, [r5]
	adds r4, r1, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #1
	ble _08015A6A
	ldr r2, _08015A98 @ =0x00000731
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
_08015A6A:
	ldr r0, _08015A88 @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _08015A9C @ =0x000006BC
	adds r1, r1, r3
	movs r2, #2
	strb r2, [r1]
	adds r5, r0, #0
_08015A78:
	ldr r0, [r5]
	ldr r4, _08015AA0 @ =0x00000732
	adds r0, r0, r4
	movs r1, #6
	strb r1, [r0]
	b _08016082
	.align 2, 0
_08015A84: .4byte 0x00002710
_08015A88: .4byte 0x020314E0
_08015A8C: .4byte 0x0000072F
_08015A90: .4byte 0x02032F20
_08015A94: .4byte 0x0869FC0C
_08015A98: .4byte 0x00000731
_08015A9C: .4byte 0x000006BC
_08015AA0: .4byte 0x00000732
_08015AA4:
	ldr r0, _08015AC0 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08015AC4 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0x10
	ldrsh r0, [r0, r3]
	cmp r0, #0x32
	bgt _08015ACC
	ldr r4, _08015AC8 @ =0x00000732
	adds r1, r1, r4
	movs r0, #8
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015AC0: .4byte 0x020314E0
_08015AC4: .4byte 0x0000132C
_08015AC8: .4byte 0x00000732
_08015ACC:
	cmp r0, #0x64
	bgt _08015AE0
	ldr r0, _08015ADC @ =0x00000732
	adds r1, r1, r0
	movs r0, #7
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015ADC: .4byte 0x00000732
_08015AE0:
	ldr r2, _08015AEC @ =0x00000732
	adds r1, r1, r2
	movs r0, #9
	strb r0, [r1]
	b _08016082
	.align 2, 0
_08015AEC: .4byte 0x00000732
_08015AF0:
	ldr r4, _08015B48 @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _08015B4C @ =0x0000132C
	adds r0, r1, r3
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x2e
	bgt _08015B60
	ldr r3, _08015B50 @ =0x00000732
	adds r0, r1, r3
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, [r4]
	movs r0, #0xe2
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015B1C
	b _08016082
_08015B1C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08015B54 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015B36
	b _08016082
_08015B36:
	ldr r2, _08015B58 @ =0x00000711
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015B5C @ =0x00000713
	b _08015C64
	.align 2, 0
_08015B48: .4byte 0x020314E0
_08015B4C: .4byte 0x0000132C
_08015B50: .4byte 0x00000732
_08015B54: .4byte 0x00000714
_08015B58: .4byte 0x00000711
_08015B5C: .4byte 0x00000713
_08015B60:
	cmp r0, #0x78
	bgt _08015BC0
	ldr r2, _08015BAC @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xb
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015BB0 @ =0x00000711
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015B7C
	b _08016082
_08015B7C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015BB4 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015B96
	b _08016082
_08015B96:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015BB8 @ =0x00000712
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015BBC @ =0x00000713
	b _08015C64
	.align 2, 0
_08015BAC: .4byte 0x00000732
_08015BB0: .4byte 0x00000711
_08015BB4: .4byte 0x00000714
_08015BB8: .4byte 0x00000712
_08015BBC: .4byte 0x00000713
_08015BC0:
	cmp r0, #0xc1
	bgt _08015C20
	ldr r2, _08015C0C @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015C10 @ =0x00000712
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015BDC
	b _08016082
_08015BDC:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015C14 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015BF6
	b _08016082
_08015BF6:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015C18 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015C1C @ =0x00000713
	b _08015C64
	.align 2, 0
_08015C0C: .4byte 0x00000732
_08015C10: .4byte 0x00000712
_08015C14: .4byte 0x00000714
_08015C18: .4byte 0x00000711
_08015C1C: .4byte 0x00000713
_08015C20:
	ldr r2, _08015C88 @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r4]
	ldr r3, _08015C8C @ =0x00000713
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08015C38
	b _08016082
_08015C38:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08015C90 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08015C52
	b _08016082
_08015C52:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08015C94 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08015C98 @ =0x00000712
_08015C64:
	adds r1, r3, r2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08015C70
	b _08016082
_08015C70:
	strb r6, [r5]
	ldr r0, [r4]
	ldr r3, _08015C9C @ =0x00000715
	adds r0, r0, r3
	movs r1, #0x7e
	strb r1, [r0]
	ldr r1, [r4]
_08015C7E:
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
	b _08016082
	.align 2, 0
_08015C88: .4byte 0x00000732
_08015C8C: .4byte 0x00000713
_08015C90: .4byte 0x00000714
_08015C94: .4byte 0x00000711
_08015C98: .4byte 0x00000712
_08015C9C: .4byte 0x00000715
_08015CA0:
	ldr r1, _08015D18 @ =0x020314E0
	ldr r2, [r1]
	ldr r4, _08015D1C @ =0x000005B2
	adds r0, r2, r4
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r5, r1, #0
	cmp r3, #0
	beq _08015CB4
	b _08015DE0
_08015CB4:
	ldr r1, _08015D20 @ =0x0000132C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #0x10
	ldrsh r0, [r0, r4]
	cmp r0, #0xaa
	ble _08015D30
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _08015CD0
	b _08016082
_08015CD0:
	adds r0, r2, #0
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r2, #0xb0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08015D0E
	ldr r3, _08015D24 @ =0x000001AB
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08015D0E
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r4, _08015D28 @ =0x000002F2
	adds r0, r0, r4
	movs r1, #5
	strh r1, [r0]
_08015D0E:
	ldr r1, [r5]
	ldr r0, _08015D2C @ =0x0000C350
	str r0, [r1, #0x3c]
	b _08016082
	.align 2, 0
_08015D18: .4byte 0x020314E0
_08015D1C: .4byte 0x000005B2
_08015D20: .4byte 0x0000132C
_08015D24: .4byte 0x000001AB
_08015D28: .4byte 0x000002F2
_08015D2C: .4byte 0x0000C350
_08015D30:
	ldr r4, _08015D88 @ =0x000002FB
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _08015D58
	adds r0, r2, #0
	adds r0, #0x23
	strb r3, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xf8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
_08015D58:
	ldr r0, [r5]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _08015D68
	movs r0, #6
	strb r0, [r1]
_08015D68:
	ldr r1, [r5]
	ldr r2, _08015D8C @ =0x0000029F
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015D7A
	b _08016082
_08015D7A:
	cmp r0, #1
	bne _08015D94
	ldr r3, _08015D90 @ =0x00000286
	adds r1, r1, r3
	movs r0, #0x5a
	strh r0, [r1]
	b _08015DB6
	.align 2, 0
_08015D88: .4byte 0x000002FB
_08015D8C: .4byte 0x0000029F
_08015D90: .4byte 0x00000286
_08015D94:
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r1, r4
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08015DD0 @ =0x0000071B
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _08015DD4 @ =0x0000071C
	adds r0, r0, r3
	movs r1, #0x3c
	strb r1, [r0]
	movs r0, #0xd8
	bl m4aSongNumStart
_08015DB6:
	ldr r2, _08015DD8 @ =0x020314E0
	ldr r0, [r2]
	ldr r4, _08015DDC @ =0x0000029F
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r0, r1
	subs r1, #0x48
	strh r1, [r0]
	b _08016082
	.align 2, 0
_08015DD0: .4byte 0x0000071B
_08015DD4: .4byte 0x0000071C
_08015DD8: .4byte 0x020314E0
_08015DDC: .4byte 0x0000029F
_08015DE0:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015DEE
	b _08016082
_08015DEE:
	ldr r4, _08015E04 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _08015E08
	subs r3, #2
	adds r1, r2, r3
	movs r0, #1
	b _08015E10
	.align 2, 0
_08015E04: .4byte 0x0000132C
_08015E08:
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #2
_08015E10:
	strb r0, [r1]
	ldr r2, [r5]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08015E40
	adds r1, r0, #0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	beq _08015E38
	b _08016082
_08015E38:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r2, r4
	b _08015E46
_08015E40:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r2, r0
_08015E46:
	movs r0, #0x78
	strh r0, [r1]
	b _08016082
_08015E4C:
	ldr r6, _08015EA4 @ =0x020314E0
	ldr r1, [r6]
	ldr r5, _08015EA8 @ =0x00000616
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015E5C
	b _08016082
_08015E5C:
	ldr r2, _08015EAC @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r2, [r0, #0x32]
	ldr r3, _08015EB0 @ =0x00000614
	adds r0, r1, r3
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08015E78
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08015E78:
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r4, r1, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa8
	ble _08015E9A
	movs r0, #0xa8
	strh r0, [r4]
_08015E9A:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x14
	strh r1, [r0]
	b _08016082
	.align 2, 0
_08015EA4: .4byte 0x020314E0
_08015EA8: .4byte 0x00000616
_08015EAC: .4byte 0x0000132C
_08015EB0: .4byte 0x00000614
_08015EB4:
	ldr r3, _08015F14 @ =0x020314E0
	ldr r1, [r3]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015ECA
	b _08016082
_08015ECA:
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _08015ED2
	b _08016082
_08015ED2:
	ldr r2, _08015F18 @ =0x000002DA
	adds r1, r1, r2
	ldrb r0, [r1]
	movs r2, #0
	ldrsb r2, [r1, r2]
	cmp r2, #0
	beq _08015EE2
	b _08016082
_08015EE2:
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r3]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r4, #0xd0
	lsls r4, r4, #8
	adds r0, r4, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r3]
	ldr r0, _08015F1C @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, #0xb7
	bl m4aSongNumStart
	b _08016020
	.align 2, 0
_08015F14: .4byte 0x020314E0
_08015F18: .4byte 0x000002DA
_08015F1C: .4byte 0x00001388
_08015F20:
	ldr r4, _08015F80 @ =0x020314E0
	ldr r1, [r4]
	movs r5, #0xb6
	lsls r5, r5, #2
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08015F36
	b _08016082
_08015F36:
	ldrh r2, [r1, #0x26]
	cmp r2, #0
	beq _08015F3E
	b _08016082
_08015F3E:
	ldr r0, _08015F84 @ =0x000002DA
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r3, #0
	ldrsb r3, [r1, r3]
	cmp r3, #1
	beq _08015F4E
	b _08016082
_08015F4E:
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r1, #0xcc
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	strh r3, [r7]
	movs r0, #0xb7
	bl m4aSongNumStart
	ldr r1, [r4]
	ldr r0, _08015F88 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015F80: .4byte 0x020314E0
_08015F84: .4byte 0x000002DA
_08015F88: .4byte 0x00001388
_08015F8C:
	ldr r0, _08015FE8 @ =0x020314E0
	ldr r3, [r0]
	movs r2, #0x13
	ldrsb r2, [r3, r2]
	adds r5, r0, #0
	cmp r2, #2
	ble _0801602C
	cmp r2, #5
	beq _0801602C
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _08016082
	ldr r4, _08015FEC @ =0x000002DA
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #2
	bne _08015FF4
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r1, [r0]
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	ldr r1, [r5]
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xb7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _08015FF0 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015FE8: .4byte 0x020314E0
_08015FEC: .4byte 0x000002DA
_08015FF0: .4byte 0x00001388
_08015FF4:
	cmp r1, #3
	bne _08016082
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r2, #0xc8
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	movs r4, #1
	strh r4, [r7]
	movs r0, #0xb7
	bl m4aSongNumStart
	ldr r0, [r5]
	ldr r3, _08016028 @ =0x000002D9
	adds r0, r0, r3
	strb r4, [r0]
_08016020:
	movs r0, #7
	bl sub_11B0
	b _08016082
	.align 2, 0
_08016028: .4byte 0x000002D9
_0801602C:
	ldr r1, [r5]
	movs r4, #0xb6
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08016082
	ldr r0, _08016088 @ =0x000002DA
	adds r2, r1, r0
	ldrb r0, [r2]
	movs r3, #0
	ldrsb r3, [r2, r3]
	cmp r3, #2
	bne _08016082
	adds r0, #1
	movs r1, #0
	strb r0, [r2]
	ldr r0, [r5]
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x22
	strb r3, [r0]
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r6]
	movs r0, #1
	strh r0, [r7]
	movs r0, #0xb7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _0801608C @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, #7
	bl sub_11B0
_08016082:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016088: .4byte 0x000002DA
_0801608C: .4byte 0x00001388

	thumb_func_start sub_16090
sub_16090: @ 0x08016090
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _08016190 @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08016194 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r1, sb
	movs r3, #0
	ldrsh r4, [r1, r3]
	adds r0, r4, #0
	cmp r4, #0
	bge _080160C2
	adds r0, r4, #7
_080160C2:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r7, _08016198 @ =0xFFFF0000
	mov ip, r7
	mov r2, ip
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _080160E0
	adds r0, r3, #7
_080160E0:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _0801619C @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _0801610C
	adds r2, #0x3f
_0801610C:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _080161A0 @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_162B8
	ldrb r0, [r4]
	movs r1, #0xf
	ands r1, r0
	lsrs r6, r0, #4
	cmp r1, #3
	bgt _080161A4
	cmp r1, #2
	bge _0801626C
	cmp r1, #1
	beq _080161A8
	b _08016290
	.align 2, 0
_08016190: .4byte 0x020314E0
_08016194: .4byte 0x0000132C
_08016198: .4byte 0xFFFF0000
_0801619C: .4byte 0x0000FFFF
_080161A0: .4byte 0x02031520
_080161A4:
	cmp r1, #4
	bne _08016290
_080161A8:
	ldr r2, _08016208 @ =0x020314E0
	ldr r0, [r2]
	subs r1, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r3, _0801620C @ =0xFFFFC010
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08016260
	ldr r0, [r2]
	ldr r4, _08016210 @ =0x0000132C
	adds r3, r0, r4
	ldr r2, [r3]
	movs r7, #0x10
	ldrsh r1, [r2, r7]
	ldr r4, _08016214 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _080161F4
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08016260
_080161F4:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _08016218
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r3, r8
	strh r0, [r3]
	b _08016260
	.align 2, 0
_08016208: .4byte 0x020314E0
_0801620C: .4byte 0xFFFFC010
_08016210: .4byte 0x0000132C
_08016214: .4byte 0x02031520
_08016218:
	cmp r0, #0
	beq _08016228
	movs r4, #0x82
	lsls r4, r4, #7
	adds r0, r4, #0
	mov r7, r8
	strh r0, [r7]
	b _08016260
_08016228:
	ldr r0, _08016248 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _0801624C
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	b _08016260
	.align 2, 0
_08016248: .4byte gMain
_0801624C:
	ldr r0, _08016268 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
	movs r3, #0x82
	lsls r3, r3, #7
	adds r0, r3, #0
	mov r4, r8
	strh r0, [r4]
_08016260:
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _08016290
	.align 2, 0
_08016268: .4byte 0x0000FFD8
_0801626C:
	ldr r2, _080162B0 @ =0x020314E0
	ldr r0, [r2]
	subs r1, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080162B4 @ =0x0000FFF0
	ands r0, r1
	mov r3, r8
	strh r0, [r3]
	movs r0, #1
	mov r4, sp
	strh r0, [r4, #4]
_08016290:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_1642C
	mov r7, sp
	movs r1, #4
	ldrsh r0, [r7, r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080162B0: .4byte 0x020314E0
_080162B4: .4byte 0x0000FFF0

	thumb_func_start sub_162B8
sub_162B8: @ 0x080162B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	movs r7, #0
	movs r6, #0
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08016418 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801641C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _080162E8
	b _08016408
_080162E8:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _080162FA
	b _08016408
_080162FA:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	adds r5, #2
	adds r0, r2, r5
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	mov r8, r3
	mov sb, r2
	cmp r0, #0x3f
	bhi _08016342
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08016342
	ldr r2, _08016420 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	mov r0, ip
	str r0, [sp, #8]
_08016342:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	ldr r2, _08016420 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #1
	str r0, [sp, #8]
_0801638C:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc7
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	ldr r2, _08016420 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #2
	str r0, [sp, #8]
_080163D6:
	cmp r6, #0
	beq _08016408
_080163DA:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [sp, #8]
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	ldr r5, [sp]
	strh r7, [r5]
	ldr r0, [sp, #4]
	strb r6, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08016428 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08016408
	movs r0, #2
	strb r0, [r1]
_08016408:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016418: .4byte 0x020314E0
_0801641C: .4byte 0x000005B2
_08016420: .4byte 0x08252B10
_08016424: .4byte 0x0000FFF0
_08016428: .4byte 0x00000624

	thumb_func_start sub_1642C
sub_1642C: @ 0x0801642C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bls _08016446
	bl _080171B8
_08016446:
	lsls r0, r0, #2
	ldr r1, _08016450 @ =_08016454
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016450: .4byte _08016454
_08016454: @ jump table
	.4byte _08016490 @ case 0
	.4byte _080164D8 @ case 1
	.4byte _08016530 @ case 2
	.4byte _08016580 @ case 3
	.4byte _08016794 @ case 4
	.4byte _080167CC @ case 5
	.4byte _0801686C @ case 6
	.4byte _080168B4 @ case 7
	.4byte _08016C28 @ case 8
	.4byte _08016C80 @ case 9
	.4byte _08016E28 @ case 10
	.4byte _08016EA2 @ case 11
	.4byte _08016F08 @ case 12
	.4byte _08017094 @ case 13
	.4byte _0801716C @ case 14
_08016490:
	ldr r0, _080164B4 @ =0x020314E0
	ldr r1, [r0]
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _0801649E
	bl _080171B8
_0801649E:
	ldr r2, _080164B8 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0x28
	ldrsh r0, [r0, r3]
	cmp r0, #0xc7
	ble _080164BC
	adds r1, #0x25
	movs r0, #1
	b _080164C0
	.align 2, 0
_080164B4: .4byte 0x020314E0
_080164B8: .4byte 0x0000132C
_080164BC:
	adds r1, #0x25
	movs r0, #3
_080164C0:
	strb r0, [r1]
	bl sub_32914
	ldr r0, _080164D4 @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	b _080168A4
	.align 2, 0
_080164D4: .4byte 0x020314E0
_080164D8:
	ldr r3, _080164F0 @ =0x020314E0
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _080164F8
	ldr r4, _080164F4 @ =0x0000132C
	adds r0, r2, r4
	b _0801656C
	.align 2, 0
_080164F0: .4byte 0x020314E0
_080164F4: .4byte 0x0000132C
_080164F8:
	cmp r1, #2
	bne _08016514
	ldr r5, _08016510 @ =0x0000132C
	adds r0, r2, r5
	ldr r0, [r0]
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016510: .4byte 0x0000132C
_08016514:
	cmp r1, #3
	beq _0801651C
	bl _080171B8
_0801651C:
	ldr r1, _0801652C @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #1]
	bl _080171B8
	.align 2, 0
_0801652C: .4byte 0x0000132C
_08016530:
	ldr r3, _08016558 @ =0x020314E0
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08016560
	ldr r2, _0801655C @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r2, #0
	movs r0, #3
	strb r0, [r1, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r2, [r0]
	bl _080171B8
	.align 2, 0
_08016558: .4byte 0x020314E0
_0801655C: .4byte 0x0000132C
_08016560:
	cmp r0, #3
	beq _08016568
	bl _080171B8
_08016568:
	ldr r4, _0801657C @ =0x0000132C
	adds r0, r1, r4
_0801656C:
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801657C: .4byte 0x0000132C
_08016580:
	ldr r5, _080165D4 @ =0x020314E0
	ldr r3, [r5]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r4, [r0]
	cmp r4, #0
	beq _08016594
	bl _080171B8
_08016594:
	ldr r6, _080165D8 @ =0x0000132C
	adds r0, r3, r6
	ldr r2, [r0]
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	ldr r0, _080165DC @ =0x00000103
	cmp r1, r0
	ble _080165A6
	b _08016718
_080165A6:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x49
	bgt _08016624
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _080165B8
	b _0801676E
_080165B8:
	ldr r2, _080165E0 @ =0x0000036B
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080165C8
	b _0801676E
_080165C8:
	cmp r0, #1
	bne _080165E8
	ldr r4, _080165E4 @ =0x0000036D
	adds r1, r3, r4
	movs r0, #6
	b _080165EE
	.align 2, 0
_080165D4: .4byte 0x020314E0
_080165D8: .4byte 0x0000132C
_080165DC: .4byte 0x00000103
_080165E0: .4byte 0x0000036B
_080165E4: .4byte 0x0000036D
_080165E8:
	ldr r5, _08016614 @ =0x0000036D
	adds r1, r3, r5
	movs r0, #4
_080165EE:
	strb r0, [r1]
	ldr r5, _08016618 @ =0x020314E0
	ldr r1, [r5]
	movs r0, #0xdc
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, _0801661C @ =0x0000036B
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r3, _08016620 @ =0x0000132C
	adds r4, r1, r3
	b _0801667E
	.align 2, 0
_08016614: .4byte 0x0000036D
_08016618: .4byte 0x020314E0
_0801661C: .4byte 0x0000036B
_08016620: .4byte 0x0000132C
_08016624:
	cmp r0, #0x73
	bgt _080166DC
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _08016632
	b _0801676E
_08016632:
	ldr r5, _08016650 @ =0x0000036A
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08016642
	b _0801676E
_08016642:
	cmp r0, #1
	bne _08016654
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
	b _0801665C
	.align 2, 0
_08016650: .4byte 0x0000036A
_08016654:
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
_0801665C:
	strb r0, [r1]
	ldr r5, _080166BC @ =0x020314E0
	ldr r1, [r5]
	ldr r3, _080166C0 @ =0x0000036E
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	ldr r4, _080166C4 @ =0x0000036A
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r0, _080166C8 @ =0x0000132C
	adds r4, r1, r0
_0801667E:
	ldr r3, [r4]
	movs r2, #0x30
	ldrsh r0, [r3, r2]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x30]
	ldr r3, [r4]
	movs r4, #0x32
	ldrsh r0, [r3, r4]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x32]
	ldr r4, _080166CC @ =0x00001378
	adds r0, r1, r4
	ldr r2, _080166D0 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r0, [r5]
	ldr r3, _080166D4 @ =0x00001330
	adds r1, r0, r3
	adds r4, r0, r4
	str r4, [r1]
	ldr r4, _080166D8 @ =0x00001328
	adds r0, r0, r4
	movs r1, #0x19
	strh r1, [r0]
	b _0801676E
	.align 2, 0
_080166BC: .4byte 0x020314E0
_080166C0: .4byte 0x0000036E
_080166C4: .4byte 0x0000036A
_080166C8: .4byte 0x0000132C
_080166CC: .4byte 0x00001378
_080166D0: .4byte 0x00001334
_080166D4: .4byte 0x00001330
_080166D8: .4byte 0x00001328
_080166DC:
	movs r0, #0xc3
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r2, _0801670C @ =0x00000306
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _08016710 @ =0x0000070E
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x62
	bgt _08016704
	adds r0, r2, #1
	strb r0, [r1]
_08016704:
	ldr r1, [r5]
	ldr r0, _08016714 @ =0x00001388
	str r0, [r1, #0x3c]
	b _0801676E
	.align 2, 0
_0801670C: .4byte 0x00000306
_08016710: .4byte 0x0000070E
_08016714: .4byte 0x00001388
_08016718:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x6d
	bgt _0801673E
	movs r2, #0xca
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	ldr r2, [r0]
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	b _0801676E
_0801673E:
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r3, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08016752
	movs r0, #1
	strb r0, [r1]
	b _08016754
_08016752:
	strb r4, [r1]
_08016754:
	ldr r0, _08016788 @ =0x020314E0
	ldr r3, [r0]
	ldr r1, _0801678C @ =0x0000132C
	adds r0, r3, r1
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	ldr r0, _08016790 @ =0x00000BB8
	str r0, [r3, #0x3c]
_0801676E:
	ldr r0, _08016788 @ =0x020314E0
	ldr r0, [r0]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x76
	bl m4aSongNumStart
	bl _080171B8
	.align 2, 0
_08016788: .4byte 0x020314E0
_0801678C: .4byte 0x0000132C
_08016790: .4byte 0x00000BB8
_08016794:
	ldr r1, _080167BC @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _080167C0 @ =0x00000165
	adds r0, r0, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x20
	strb r2, [r0]
	ldr r0, [r1]
	ldr r4, _080167C4 @ =0x00000732
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r1]
	ldr r5, _080167C8 @ =0x00000342
	adds r0, r0, r5
	strb r3, [r0]
	bl _080171B8
	.align 2, 0
_080167BC: .4byte 0x020314E0
_080167C0: .4byte 0x00000165
_080167C4: .4byte 0x00000732
_080167C8: .4byte 0x00000342
_080167CC:
	ldr r0, _08016850 @ =0x020314E0
	mov sb, r0
	ldr r1, [r0]
	ldr r2, _08016854 @ =0x0000132C
	mov r8, r2
	adds r0, r1, r2
	ldr r2, [r0]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	cmp r0, #0x77
	bgt _0801685C
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bgt _080167EE
	bl _080171B8
_080167EE:
	movs r6, #0xda
	lsls r6, r6, #8
	movs r5, #0x30
	ldrsh r0, [r2, r5]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r7, r1, r0
	lsls r0, r7, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x11
	adds r0, r6, #0
	bl sub_C74
	mov r5, sb
	ldr r1, [r5]
	add r1, r8
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r5, _08016858 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x30]
	adds r0, r6, #0
	bl sub_C24
	mov r2, sb
	ldr r1, [r2]
	add r1, r8
	ldr r4, [r1]
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x32]
	bl _080171B8
	.align 2, 0
_08016850: .4byte 0x020314E0
_08016854: .4byte 0x0000132C
_08016858: .4byte 0x00004E20
_0801685C:
	ldr r3, _08016868 @ =0x00000342
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	bl _080171B8
	.align 2, 0
_08016868: .4byte 0x00000342
_0801686C:
	ldr r4, _080168AC @ =0x020314E0
	ldr r3, [r4]
	ldr r1, _080168B0 @ =0x00000366
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08016882
	bl _080171B8
_08016882:
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r2, #0
	movs r0, #0x11
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r5]
_080168A4:
	movs r0, #1
	strh r0, [r6]
	bl _080171B8
	.align 2, 0
_080168AC: .4byte 0x020314E0
_080168B0: .4byte 0x00000366
_080168B4:
	ldr r1, _0801690C @ =0x020314E0
	ldr r3, [r1]
	ldr r4, _08016910 @ =0x0000132C
	adds r0, r3, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #0
	ble _0801697C
	ldr r5, _08016914 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801695A
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r3, #0xa
	strb r3, [r0]
	ldr r1, [r1]
	ldr r4, _08016918 @ =0x0000072B
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016946
	cmp r0, #0
	bne _0801691C
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801690C: .4byte 0x020314E0
_08016910: .4byte 0x0000132C
_08016914: .4byte 0x00000732
_08016918: .4byte 0x0000072B
_0801691C:
	cmp r0, #1
	bne _08016930
	ldr r0, _0801692C @ =0x00001388
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #5
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801692C: .4byte 0x00001388
_08016930:
	ldr r0, _0801696C @ =0x00002710
	str r0, [r1, #0x3c]
	adds r0, r1, r2
	strb r3, [r0]
_08016938:
	mov r5, sb
	ldr r1, [r5]
	ldr r0, _08016970 @ =0x0000072B
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08016946:
	mov r1, sb
	ldr r0, [r1]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r2, r0, r3
	movs r1, #0
	strh r1, [r2]
	ldr r4, _08016974 @ =0x0000072C
	adds r0, r0, r4
	strh r1, [r0]
_0801695A:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016978 @ =0x00000732
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801696C: .4byte 0x00002710
_08016970: .4byte 0x0000072B
_08016974: .4byte 0x0000072C
_08016978: .4byte 0x00000732
_0801697C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x48
	bgt _08016A14
	ldr r2, _080169B4 @ =0x00000732
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _080169EE
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _080169E0
	ldr r4, _080169B8 @ =0x0000072E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080169E0
	cmp r0, #0
	bne _080169BC
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080169CA
	.align 2, 0
_080169B4: .4byte 0x00000732
_080169B8: .4byte 0x0000072E
_080169BC:
	cmp r0, #1
	bne _080169C8
	ldr r0, _080169C4 @ =0x00001388
	b _080169CA
	.align 2, 0
_080169C4: .4byte 0x00001388
_080169C8:
	ldr r0, _08016A00 @ =0x00002710
_080169CA:
	str r0, [r3, #0x3c]
	ldr r0, _08016A04 @ =0x020314E0
	ldr r1, [r0]
	ldr r5, _08016A08 @ =0x0000072E
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x99
	bl m4aSongNumStart
_080169E0:
	ldr r0, _08016A04 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08016A0C @ =0x000006BC
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	mov sb, r0
_080169EE:
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A10 @ =0x00000732
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016A00: .4byte 0x00002710
_08016A04: .4byte 0x020314E0
_08016A08: .4byte 0x0000072E
_08016A0C: .4byte 0x000006BC
_08016A10: .4byte 0x00000732
_08016A14:
	cmp r0, #0x62
	bgt _08016A88
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016A2E
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016A2E:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016A78 @ =0x00000732
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016A7C @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016A52
	b _080171B8
_08016A52:
	ldr r5, _08016A80 @ =0x00000719
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016A66
	b _080171B8
_08016A66:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A84 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016A78: .4byte 0x00000732
_08016A7C: .4byte 0x0000071B
_08016A80: .4byte 0x00000719
_08016A84: .4byte 0x0000071C
_08016A88:
	cmp r0, #0x76
	bgt _08016AFC
	ldr r1, _08016AEC @ =0x00000719
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016AA0
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016AA0:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016AF0 @ =0x00000732
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016AF4 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016AC4
	b _080171B8
_08016AC4:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016ADA
	b _080171B8
_08016ADA:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016AF8 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016AEC: .4byte 0x00000719
_08016AF0: .4byte 0x00000732
_08016AF4: .4byte 0x0000071B
_08016AF8: .4byte 0x0000071C
_08016AFC:
	cmp r0, #0x92
	bgt _08016B70
	ldr r1, _08016B60 @ =0x0000071A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016B14
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016B14:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016B64 @ =0x00000732
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016B68 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016B38
	b _080171B8
_08016B38:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #2
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016B4E
	b _080171B8
_08016B4E:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016B6C @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016B60: .4byte 0x0000071A
_08016B64: .4byte 0x00000732
_08016B68: .4byte 0x0000071B
_08016B6C: .4byte 0x0000071C
_08016B70:
	ldr r5, _08016BA0 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _08016C00
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _08016BF4
	ldr r1, _08016BA4 @ =0x0000072F
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016BF4
	cmp r0, #0
	bne _08016BA8
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08016BB6
	.align 2, 0
_08016BA0: .4byte 0x00000732
_08016BA4: .4byte 0x0000072F
_08016BA8:
	cmp r0, #1
	bne _08016BB4
	ldr r0, _08016BB0 @ =0x00001388
	b _08016BB6
	.align 2, 0
_08016BB0: .4byte 0x00001388
_08016BB4:
	ldr r0, _08016C10 @ =0x00002710
_08016BB6:
	str r0, [r3, #0x3c]
	ldr r4, _08016C14 @ =0x020314E0
	ldr r1, [r4]
	ldr r5, _08016C18 @ =0x0000072F
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xd
	bne _08016BDC
	movs r0, #0x99
	bl m4aSongNumStart
_08016BDC:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r4
	cmp r0, #1
	ble _08016BF4
	ldr r4, _08016C1C @ =0x00000731
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
_08016BF4:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016C20 @ =0x000006BC
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
_08016C00:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _08016C24 @ =0x00000732
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	b _080171B8
	.align 2, 0
_08016C10: .4byte 0x00002710
_08016C14: .4byte 0x020314E0
_08016C18: .4byte 0x0000072F
_08016C1C: .4byte 0x00000731
_08016C20: .4byte 0x000006BC
_08016C24: .4byte 0x00000732
_08016C28:
	ldr r0, _08016C4C @ =0x020314E0
	ldr r1, [r0]
	ldr r4, _08016C50 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08016C58
	ldr r5, _08016C54 @ =0x00000732
	adds r1, r1, r5
	movs r0, #7
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C4C: .4byte 0x020314E0
_08016C50: .4byte 0x0000132C
_08016C54: .4byte 0x00000732
_08016C58:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	bgt _08016C70
	ldr r0, _08016C6C @ =0x00000732
	adds r1, r1, r0
	movs r0, #8
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C6C: .4byte 0x00000732
_08016C70:
	ldr r2, _08016C7C @ =0x00000732
	adds r1, r1, r2
	movs r0, #9
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C7C: .4byte 0x00000732
_08016C80:
	ldr r4, _08016CD8 @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _08016CDC @ =0x0000132C
	adds r0, r1, r3
	ldr r0, [r0]
	movs r5, #0x10
	ldrsh r0, [r0, r5]
	cmp r0, #0x2e
	bgt _08016CF4
	ldr r2, _08016CE0 @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, [r4]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016CAC
	b _080171B8
_08016CAC:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08016CE4 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016CC6
	b _080171B8
_08016CC6:
	ldr r1, _08016CE8 @ =0x00000711
	adds r0, r3, r1
	ldr r2, _08016CEC @ =0x00000712
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016CF0 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016CD8: .4byte 0x020314E0
_08016CDC: .4byte 0x0000132C
_08016CE0: .4byte 0x00000732
_08016CE4: .4byte 0x00000714
_08016CE8: .4byte 0x00000711
_08016CEC: .4byte 0x00000712
_08016CF0: .4byte 0x00000713
_08016CF4:
	cmp r0, #0x78
	bgt _08016D50
	ldr r5, _08016D40 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xb
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016D44 @ =0x00000711
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D10
	b _080171B8
_08016D10:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016D48 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D2A
	b _080171B8
_08016D2A:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #2
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016D4C @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D40: .4byte 0x00000732
_08016D44: .4byte 0x00000711
_08016D48: .4byte 0x00000714
_08016D4C: .4byte 0x00000713
_08016D50:
	cmp r0, #0xc1
	bgt _08016DAC
	ldr r5, _08016D9C @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016DA0 @ =0x00000712
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D6C
	b _080171B8
_08016D6C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016DA4 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D86
	b _080171B8
_08016D86:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016DA8 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D9C: .4byte 0x00000732
_08016DA0: .4byte 0x00000712
_08016DA4: .4byte 0x00000714
_08016DA8: .4byte 0x00000713
_08016DAC:
	ldr r5, _08016E14 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016E18 @ =0x00000713
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016DC4
	b _080171B8
_08016DC4:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016E1C @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016DDE
	b _080171B8
_08016DDE:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016E20 @ =0x00000712
_08016DF0:
	adds r1, r3, r2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08016DFC
	b _080171B8
_08016DFC:
	strb r6, [r5]
	ldr r0, [r4]
	ldr r3, _08016E24 @ =0x00000715
	adds r0, r0, r3
	movs r1, #0x7e
	strb r1, [r0]
	ldr r1, [r4]
_08016E0A:
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
	b _080171B8
	.align 2, 0
_08016E14: .4byte 0x00000732
_08016E18: .4byte 0x00000713
_08016E1C: .4byte 0x00000714
_08016E20: .4byte 0x00000712
_08016E24: .4byte 0x00000715
_08016E28:
	ldr r0, _08016E54 @ =0x020314E0
	ldr r3, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sb, r0
	cmp r1, #0
	beq _08016E3C
	b _080171B8
_08016E3C:
	ldr r5, _08016E58 @ =0x0000132C
	adds r0, r3, r5
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _08016E5C
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #1
	b _08016E64
	.align 2, 0
_08016E54: .4byte 0x020314E0
_08016E58: .4byte 0x0000132C
_08016E5C:
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #2
_08016E64:
	strb r0, [r1]
	mov r5, sb
	ldr r2, [r5]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08016E96
	adds r1, r0, #0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	beq _08016E8E
	b _080171B8
_08016E8E:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r2, r4
	b _08016E9C
_08016E96:
	movs r5, #0xe2
	lsls r5, r5, #1
	adds r1, r2, r5
_08016E9C:
	movs r0, #0x78
	strh r0, [r1]
	b _080171B8
_08016EA2:
	ldr r6, _08016EF8 @ =0x020314E0
	ldr r1, [r6]
	ldr r5, _08016EFC @ =0x00000616
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08016EB2
	b _080171B8
_08016EB2:
	ldr r2, _08016F00 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r2, [r0, #0x32]
	ldr r3, _08016F04 @ =0x00000614
	adds r0, r1, r3
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08016ECE
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08016ECE:
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r4, r1, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa8
	ble _08016EF0
	movs r0, #0xa8
	strh r0, [r4]
_08016EF0:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x14
	b _080171B6
	.align 2, 0
_08016EF8: .4byte 0x020314E0
_08016EFC: .4byte 0x00000616
_08016F00: .4byte 0x0000132C
_08016F04: .4byte 0x00000614
_08016F08:
	ldr r5, _08017058 @ =0x020314E0
	ldr r0, [r5]
	ldr r2, _0801705C @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xe
	bne _08016F1A
	b _080171B8
_08016F1A:
	movs r0, #0xe
	strb r0, [r1]
	ldr r3, _08017060 @ =0x086ACE70
	ldr r1, [r5]
	ldr r2, _08017064 @ =0x0000034A
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r3, [r0]
	mov r8, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r3, _08017068 @ =0x0000034B
	adds r1, r1, r3
	adds r1, r1, r0
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r2, r1, r2
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #3
	bne _08016F88
	ldr r4, _0801706C @ =0x00001378
	adds r0, r1, r4
	ldr r2, _08017070 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r1, [r5]
	ldr r3, _08017074 @ =0x00001330
	adds r0, r1, r3
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, _08017078 @ =0x00000342
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08016F88
	movs r5, #0xd1
	lsls r5, r5, #2
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1]
_08016F88:
	ldr r0, _08017058 @ =0x020314E0
	ldr r3, [r0]
	ldr r6, _08017064 @ =0x0000034A
	adds r1, r3, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r1, #0xb
	bne _08016FA6
	ldr r0, _08017074 @ =0x00001330
	adds r1, r3, r0
	ldr r2, _08017070 @ =0x00001334
	adds r0, r3, r2
	str r0, [r1]
_08016FA6:
	mov r3, sb
	ldr r5, [r3]
	adds r0, r5, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _08016FBA
	adds r3, r1, #2
_08016FBA:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _0801707C @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r7, #0
	movs r4, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _08017080 @ =0x00000355
	adds r0, r5, r1
	adds r0, r0, r3
	strb r7, [r0]
	mov r5, sb
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r5, _08017084 @ =0x0000035E
	adds r0, r2, r5
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, _08017088 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xc
	ble _0801700E
	strb r7, [r1]
_0801700E:
	mov r2, r8
	lsls r0, r2, #0x10
	adds r3, r0, #0
	cmp r3, #0
	bne _08017030
	mov r4, sb
	ldr r0, [r4]
	ldr r5, _0801708C @ =0x0000132C
	adds r0, r0, r5
	ldr r2, [r0]
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08017030
	strh r1, [r2, #0x32]
_08017030:
	asrs r0, r3, #0x10
	cmp r0, #2
	beq _08017038
	b _080171B8
_08017038:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _0801708C @ =0x0000132C
	adds r0, r0, r3
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r1, [r2, r4]
	movs r0, #0xb4
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08017050
	b _080171B8
_08017050:
	ldr r0, _08017090 @ =0x0000FF4C
	strh r0, [r2, #0x32]
	b _080171B8
	.align 2, 0
_08017058: .4byte 0x020314E0
_0801705C: .4byte 0x00000732
_08017060: .4byte 0x086ACE70
_08017064: .4byte 0x0000034A
_08017068: .4byte 0x0000034B
_0801706C: .4byte 0x00001378
_08017070: .4byte 0x00001334
_08017074: .4byte 0x00001330
_08017078: .4byte 0x00000342
_0801707C: .4byte gMain
_08017080: .4byte 0x00000355
_08017084: .4byte 0x0000035E
_08017088: .4byte 0x00000359
_0801708C: .4byte 0x0000132C
_08017090: .4byte 0x0000FF4C
_08017094:
	ldr r5, _08017144 @ =0x020314E0
	ldr r0, [r5]
	ldr r2, _08017148 @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xf
	bne _080170A6
	b _080171B8
_080170A6:
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _0801714C @ =0x086ACE70
	ldr r1, [r5]
	ldr r6, _08017150 @ =0x0000034A
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r7, [r0, r3]
	ldr r4, _08017154 @ =0x0000034B
	adds r1, r1, r4
	adds r1, r1, r7
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, [r5]
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _080170E6
	adds r3, r1, #2
_080170E6:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _08017158 @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _0801715C @ =0x00000355
	adds r0, r4, r1
	adds r0, r0, r3
	strb r2, [r0]
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r4, _08017160 @ =0x0000035E
	adds r0, r2, r4
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08017164 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	cmp r7, #1
	bne _080171B8
	ldr r0, [r5]
	ldr r1, _08017168 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	movs r3, #0x96
	rsbs r3, r3, #0
	cmp r0, r3
	ble _080171B8
	strh r3, [r1, #0x32]
	b _080171B8
	.align 2, 0
_08017144: .4byte 0x020314E0
_08017148: .4byte 0x00000732
_0801714C: .4byte 0x086ACE70
_08017150: .4byte 0x0000034A
_08017154: .4byte 0x0000034B
_08017158: .4byte gMain
_0801715C: .4byte 0x00000355
_08017160: .4byte 0x0000035E
_08017164: .4byte 0x00000359
_08017168: .4byte 0x0000132C
_0801716C:
	ldr r3, _08017190 @ =0x020314E0
	ldr r1, [r3]
	ldr r4, _08017194 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	movs r5, #0x12
	ldrsh r0, [r0, r5]
	cmp r0, #0x4f
	bgt _0801719C
	ldr r0, _08017198 @ =0x00000306
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _080171B8
	movs r0, #2
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08017190: .4byte 0x020314E0
_08017194: .4byte 0x0000132C
_08017198: .4byte 0x00000306
_0801719C:
	ldr r4, _080171C4 @ =0x00000306
	adds r2, r1, r4
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _080171B8
	movs r1, #0
	movs r0, #3
	strb r0, [r2]
	ldr r0, [r3]
	movs r5, #0xc3
	lsls r5, r5, #2
	adds r0, r0, r5
_080171B6:
	strh r1, [r0]
_080171B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080171C4: .4byte 0x00000306

	thumb_func_start sub_171C8
sub_171C8: @ 0x080171C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _080172CC @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _080172D0 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, sb
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _080171FA
	adds r0, r4, #7
_080171FA:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080172D4 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08017216
	adds r0, r3, #7
_08017216:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _080172D8 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08017242
	adds r2, #0x3f
_08017242:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _080172DC @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_173FC
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _080172C0
	b _080173DA
_080172C0:
	lsls r0, r0, #2
	ldr r1, _080172E0 @ =_080172E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080172CC: .4byte 0x020314E0
_080172D0: .4byte 0x0000132C
_080172D4: .4byte 0xFFFF0000
_080172D8: .4byte 0x0000FFFF
_080172DC: .4byte 0x02031520
_080172E0: .4byte _080172E4
_080172E4: @ jump table
	.4byte _080172FC @ case 0
	.4byte _080173A8 @ case 1
	.4byte _080173A8 @ case 2
	.4byte _080172FC @ case 3
	.4byte _080173D8 @ case 4
	.4byte _080172FC @ case 5
_080172FC:
	ldr r2, _08017374 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08017378 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _0801739C
	ldr r0, [r2]
	ldr r7, _0801737C @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08017380 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08017348
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _0801739C
_08017348:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08017366
	cmp r0, #0
	bne _08017392
	ldr r0, _08017384 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08017388
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_08017366:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _0801739C
	.align 2, 0
_08017374: .4byte 0x020314E0
_08017378: .4byte 0xFFFFC010
_0801737C: .4byte 0x0000132C
_08017380: .4byte 0x02031520
_08017384: .4byte gMain
_08017388:
	ldr r0, _080173A4 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08017392:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_0801739C:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _080173DA
	.align 2, 0
_080173A4: .4byte 0x0000FFD8
_080173A8:
	ldr r2, _080173D0 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080173D4 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _080173DA
	.align 2, 0
_080173D0: .4byte 0x020314E0
_080173D4: .4byte 0x0000FFF0
_080173D8:
	movs r6, #4
_080173DA:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_17634
	mov r1, sp
	movs r2, #4
	ldrsh r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_173FC
sub_173FC: @ 0x080173FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov ip, r2
	movs r7, #0
	movs r3, #0
	ldr r1, _08017494 @ =0x020314E0
	ldr r5, [r1]
	ldr r2, _08017498 @ =0x00000387
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r1
	cmp r0, #2
	bne _080174C0
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801742C
	b _080175FE
_0801742C:
	adds r2, #0x69
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801749C @ =0x000003F2
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x5f
	bls _0801744E
	b _080175FE
_0801744E:
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x77
	bls _08017458
	b _080175FE
_08017458:
	ldr r2, _080174A0 @ =0x083071D4
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _080174A4 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	bne _0801747A
	b _080175FE
_0801747A:
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080174A8
	movs r0, #1
	mov r2, ip
	strb r0, [r2]
	b _080174AC
	.align 2, 0
_08017494: .4byte 0x020314E0
_08017498: .4byte 0x00000387
_0801749C: .4byte 0x000003F2
_080174A0: .4byte 0x083071D4
_080174A4: .4byte 0x0000FFF0
_080174A8:
	mov r0, ip
	strb r3, [r0]
_080174AC:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #4
	strb r1, [r0]
	mov r0, sb
	strh r7, [r0]
	b _080175FE
_080174C0:
	cmp r0, #1
	beq _080174C6
	b _080175FE
_080174C6:
	mov r1, ip
	ldrb r0, [r1]
	cmp r0, #0
	beq _080174D0
	b _080175FE
_080174D0:
	ldr r2, _0801760C @ =0x000003A9
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801752C
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08017610 @ =0x000003D2
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _0801752C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801752C
	ldr r2, _08017614 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _08017530
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_0801752C:
	cmp r3, #0
	bne _080175F4
_08017530:
	mov r0, r8
	ldr r5, [r0]
	ldr r1, _0801761C @ =0x000003AA
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801758E
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08017620 @ =0x000003D6
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _0801758E
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801758E
	ldr r2, _08017614 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _08017592
	ldr r2, _08017624 @ =0x000003A1
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_0801758E:
	cmp r3, #0
	bne _080175F4
_08017592:
	mov r0, r8
	ldr r5, [r0]
	ldr r1, _08017628 @ =0x000003AB
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080175F0
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r6]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801762C @ =0x000003DA
	adds r1, r5, r0
	ldrh r0, [r6, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _080175F0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080175F0
	ldr r2, _08017614 @ =0x08252B10
	asrs r0, r1, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08017618 @ =0x0000FFF0
	ands r7, r0
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0
	beq _080175FE
	ldr r2, _08017630 @ =0x000003A2
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
_080175F0:
	cmp r3, #0
	beq _080175FE
_080175F4:
	mov r0, sb
	strh r7, [r0]
	movs r0, #6
	mov r1, ip
	strb r0, [r1]
_080175FE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801760C: .4byte 0x000003A9
_08017610: .4byte 0x000003D2
_08017614: .4byte 0x08252B10
_08017618: .4byte 0x0000FFF0
_0801761C: .4byte 0x000003AA
_08017620: .4byte 0x000003D6
_08017624: .4byte 0x000003A1
_08017628: .4byte 0x000003AB
_0801762C: .4byte 0x000003DA
_08017630: .4byte 0x000003A2

	thumb_func_start sub_17634
sub_17634: @ 0x08017634
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bhi _080176A6
	lsls r0, r0, #2
	ldr r1, _08017648 @ =_0801764C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017648: .4byte _0801764C
_0801764C: @ jump table
	.4byte _080176A6 @ case 0
	.4byte _080176A6 @ case 1
	.4byte _080176A6 @ case 2
	.4byte _08017688 @ case 3
	.4byte _080176A6 @ case 4
	.4byte _080176A6 @ case 5
	.4byte _080176A6 @ case 6
	.4byte _080176A6 @ case 7
	.4byte _080176A6 @ case 8
	.4byte _080176A6 @ case 9
	.4byte _080176A6 @ case 10
	.4byte _080176A6 @ case 11
	.4byte _080176A6 @ case 12
	.4byte _080176A6 @ case 13
	.4byte _080176A6 @ case 14
_08017688:
	ldr r2, _080176A8 @ =0x020314E0
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
	ldr r0, [r2]
	ldr r1, _080176AC @ =0x00000387
	adds r0, r0, r1
	strb r3, [r0]
_080176A6:
	bx lr
	.align 2, 0
_080176A8: .4byte 0x020314E0
_080176AC: .4byte 0x00000387

	thumb_func_start sub_176B0
sub_176B0: @ 0x080176B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sl, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _080177B0 @ =0x020314E0
	ldr r0, [r0]
	mov sb, r0
	ldr r0, _080177B4 @ =0x0000132C
	add r0, sb
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, r8
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _080176E2
	adds r0, r4, #7
_080176E2:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080177B8 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r0, r8
	movs r2, #2
	ldrsh r3, [r0, r2]
	adds r0, r3, #0
	cmp r3, #0
	bge _080176FE
	adds r0, r3, #7
_080176FE:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _080177BC @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _0801772A
	adds r2, #0x3f
_0801772A:
	asrs r2, r2, #6
	mov r0, sb
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r0, _080177C0 @ =0x02031520
	mov ip, r0
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, r8
	mov r1, sp
	adds r2, r4, #0
	bl sub_17898
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r5, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bhi _08017876
	lsls r0, r0, #2
	ldr r1, _080177C4 @ =_080177C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080177B0: .4byte 0x020314E0
_080177B4: .4byte 0x0000132C
_080177B8: .4byte 0xFFFF0000
_080177BC: .4byte 0x0000FFFF
_080177C0: .4byte 0x02031520
_080177C4: .4byte _080177C8
_080177C8: @ jump table
	.4byte _080177E0 @ case 0
	.4byte _08017804 @ case 1
	.4byte _08017804 @ case 2
	.4byte _080177E0 @ case 3
	.4byte _08017874 @ case 4
	.4byte _080177E0 @ case 5
_080177E0:
	ldr r2, _08017800 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #1
	strb r1, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r2, sl
	strh r0, [r2]
	mov r4, sp
	strh r1, [r4, #4]
	b _08017876
	.align 2, 0
_08017800: .4byte 0x020314E0
_08017804:
	ldr r2, _0801785C @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x23
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r3, #1
	strb r3, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08017860 @ =0x0000FFF0
	ands r0, r1
	mov r1, sl
	strh r0, [r1]
	mov r4, sp
	strh r3, [r4, #4]
	ldr r1, [r2]
	ldr r0, _08017864 @ =0x00000404
	adds r3, r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r4, r2, #0
	cmp r0, #0
	bne _0801784E
	ldr r2, _08017868 @ =0x00000406
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	bne _0801784E
	movs r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r1, _0801786C @ =0x0000040A
	adds r0, r0, r1
	strh r2, [r0]
_0801784E:
	ldr r0, [r4]
	ldr r2, _08017870 @ =0x0000040C
	adds r0, r0, r2
	movs r1, #0x28
	strh r1, [r0]
	b _08017876
	.align 2, 0
_0801785C: .4byte 0x020314E0
_08017860: .4byte 0x0000FFF0
_08017864: .4byte 0x00000404
_08017868: .4byte 0x00000406
_0801786C: .4byte 0x0000040A
_08017870: .4byte 0x0000040C
_08017874:
	movs r5, #4
_08017876:
	adds r0, r5, #0
	add r1, sp, #4
	mov r2, sl
	bl sub_179D0
	mov r4, sp
	movs r1, #4
	ldrsh r0, [r4, r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_17898
sub_17898: @ 0x08017898
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	ldr r0, _08017924 @ =0x020314E0
	ldr r5, [r0]
	ldr r1, _08017928 @ =0x00000387
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08017938
	ldrb r1, [r4]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080178C0
	b _080179B8
_080178C0:
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801792C @ =0x000003F2
	adds r1, r5, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bhi _080179B8
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x57
	bhi _080179B8
	ldr r2, _08017930 @ =0x0832D604
	asrs r0, r3, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r3, r6, #0
	ands r3, r0
	cmp r3, #0
	beq _080179B8
	ldr r1, _08017934 @ =0x0000132C
	adds r0, r5, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080179B8
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bgt _080179B8
	movs r0, #9
	strb r0, [r1]
	b _080179B8
	.align 2, 0
_08017924: .4byte 0x020314E0
_08017928: .4byte 0x00000387
_0801792C: .4byte 0x000003F2
_08017930: .4byte 0x0832D604
_08017934: .4byte 0x0000132C
_08017938:
	cmp r0, #2
	bne _080179B8
	ldrb r1, [r4]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080179B8
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _080179C0 @ =0x000003F2
	adds r1, r5, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x57
	bhi _080179B8
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080179B8
	ldr r2, _080179C4 @ =0x08330204
	asrs r1, r1, #0x10
	movs r0, #0x58
	muls r0, r1, r0
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _080179C8 @ =0x0000FFF0
	ands r2, r0
	adds r3, r6, #0
	ands r3, r0
	cmp r3, #0
	beq _080179B8
	ldr r1, _080179CC @ =0x0000132C
	adds r0, r5, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080179B8
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xc
	beq _080179B8
	movs r0, #0xb
	strb r0, [r1]
	strh r2, [r7]
	movs r0, #6
	strb r0, [r4]
_080179B8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080179C0: .4byte 0x000003F2
_080179C4: .4byte 0x08330204
_080179C8: .4byte 0x0000FFF0
_080179CC: .4byte 0x0000132C

	thumb_func_start sub_179D0
sub_179D0: @ 0x080179D0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080179F8 @ =0x020314E0
	ldr r1, [r2]
	ldr r3, _080179FC @ =0x0000132C
	adds r1, r1, r3
	ldr r1, [r1]
	ldrh r3, [r1, #0x10]
	ldrh r4, [r1, #0x12]
	subs r0, #1
	cmp r0, #0xe
	bls _080179EC
	b _08017C12
_080179EC:
	lsls r0, r0, #2
	ldr r1, _08017A00 @ =_08017A04
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080179F8: .4byte 0x020314E0
_080179FC: .4byte 0x0000132C
_08017A00: .4byte _08017A04
_08017A04: @ jump table
	.4byte _08017C12 @ case 0
	.4byte _08017C12 @ case 1
	.4byte _08017C12 @ case 2
	.4byte _08017C12 @ case 3
	.4byte _08017C12 @ case 4
	.4byte _08017C12 @ case 5
	.4byte _08017C12 @ case 6
	.4byte _08017A40 @ case 7
	.4byte _08017A88 @ case 8
	.4byte _08017ACA @ case 9
	.4byte _08017BA4 @ case 10
	.4byte _08017BEC @ case 11
	.4byte _08017C12 @ case 12
	.4byte _08017C12 @ case 13
	.4byte _08017C12 @ case 14
_08017A40:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017A68
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x38
	bgt _08017A5C
	ldr r0, [r2]
	ldr r1, _08017A58 @ =0x0000041C
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017A58: .4byte 0x0000041C
_08017A5C:
	ldr r0, [r2]
	ldr r3, _08017A64 @ =0x0000041D
	b _08017C04
	.align 2, 0
_08017A64: .4byte 0x0000041D
_08017A68:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	bgt _08017A7C
	ldr r0, [r2]
	ldr r1, _08017A78 @ =0x0000041F
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017A78: .4byte 0x0000041F
_08017A7C:
	ldr r0, [r2]
	ldr r3, _08017A84 @ =0x0000041E
	b _08017C04
	.align 2, 0
_08017A84: .4byte 0x0000041E
_08017A88:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017AB0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017AA4
	ldr r0, [r2]
	ldr r1, _08017AA0 @ =0x00000427
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017AA0: .4byte 0x00000427
_08017AA4:
	ldr r0, [r2]
	ldr r3, _08017AAC @ =0x00000425
	b _08017C04
	.align 2, 0
_08017AAC: .4byte 0x00000425
_08017AB0:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017AC2
	ldr r0, [r2]
	movs r1, #0x85
	lsls r1, r1, #3
	adds r2, r0, r1
	b _08017C06
_08017AC2:
	ldr r0, [r2]
	movs r3, #0x84
	lsls r3, r3, #3
	b _08017C04
_08017ACA:
	ldr r1, [r2]
	movs r3, #0x82
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _08017B08
	ldr r0, _08017B00 @ =0x0000042A
	adds r1, r1, r0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	ldr r1, _08017B04 @ =0x0000132C
	adds r3, r2, r1
	ldr r0, [r3]
	ldrh r0, [r0, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xd0
	strh r0, [r1]
	ldr r0, [r3]
	ldrh r0, [r0, #0x12]
	subs r0, #7
	adds r2, #0xd2
	strh r0, [r2]
	b _08017C12
	.align 2, 0
_08017B00: .4byte 0x0000042A
_08017B04: .4byte 0x0000132C
_08017B08:
	cmp r0, #3
	bne _08017B3C
	ldr r3, _08017B34 @ =0x0000042B
	adds r1, r1, r3
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	ldr r0, _08017B38 @ =0x0000132C
	adds r3, r2, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xd4
	strh r0, [r1]
	ldr r0, [r3]
	ldrh r0, [r0, #0x12]
	subs r0, #7
	adds r2, #0xd6
	strh r0, [r2]
	b _08017C12
	.align 2, 0
_08017B34: .4byte 0x0000042B
_08017B38: .4byte 0x0000132C
_08017B3C:
	cmp r0, #6
	bne _08017B70
	ldr r3, _08017B68 @ =0x0000042C
	adds r1, r1, r3
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	ldr r0, _08017B6C @ =0x0000132C
	adds r3, r2, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xd8
	strh r0, [r1]
	ldr r0, [r3]
	ldrh r0, [r0, #0x12]
	subs r0, #7
	adds r2, #0xda
	strh r0, [r2]
	b _08017C12
	.align 2, 0
_08017B68: .4byte 0x0000042C
_08017B6C: .4byte 0x0000132C
_08017B70:
	cmp r0, #9
	bne _08017C12
	ldr r3, _08017B9C @ =0x0000042D
	adds r1, r1, r3
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	ldr r0, _08017BA0 @ =0x0000132C
	adds r3, r2, r0
	ldr r0, [r3]
	ldrh r0, [r0, #0x10]
	subs r0, #7
	adds r1, r2, #0
	adds r1, #0xdc
	strh r0, [r1]
	ldr r0, [r3]
	ldrh r0, [r0, #0x12]
	subs r0, #7
	adds r2, #0xde
	strh r0, [r2]
	b _08017C12
	.align 2, 0
_08017B9C: .4byte 0x0000042D
_08017BA0: .4byte 0x0000132C
_08017BA4:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017BCC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017BC0
	ldr r0, [r2]
	ldr r1, _08017BBC @ =0x00000429
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017BBC: .4byte 0x00000429
_08017BC0:
	ldr r0, [r2]
	ldr r3, _08017BC8 @ =0x00000422
	b _08017C04
	.align 2, 0
_08017BC8: .4byte 0x00000422
_08017BCC:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017BE0
	ldr r0, [r2]
	ldr r1, _08017BDC @ =0x00000426
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017BDC: .4byte 0x00000426
_08017BE0:
	ldr r0, [r2]
	ldr r3, _08017BE8 @ =0x00000421
	b _08017C04
	.align 2, 0
_08017BE8: .4byte 0x00000421
_08017BEC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017C00
	ldr r0, [r2]
	ldr r1, _08017BFC @ =0x00000424
	adds r2, r0, r1
	b _08017C06
	.align 2, 0
_08017BFC: .4byte 0x00000424
_08017C00:
	ldr r0, [r2]
	ldr r3, _08017C18 @ =0x00000423
_08017C04:
	adds r2, r0, r3
_08017C06:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bgt _08017C12
	movs r0, #0x18
	strb r0, [r2]
_08017C12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017C18: .4byte 0x00000423

	thumb_func_start sub_17C1C
sub_17C1C: @ 0x08017C1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r3, r0, #0
	ldr r0, _08017CF8 @ =0x020314E0
	ldr r1, [r0]
	movs r2, #0xfe
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	movs r1, #0
	ldrsh r4, [r3, r1]
	adds r1, r4, #0
	mov ip, r0
	cmp r4, #0
	bge _08017C42
	adds r1, r4, #7
_08017C42:
	asrs r1, r1, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08017CFC @ =0xFFFF0000
	mov r8, r2
	ands r6, r2
	orrs r6, r0
	movs r0, #2
	ldrsh r3, [r3, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08017C5C
	adds r0, r3, #7
_08017C5C:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r5, _08017D00 @ =0x0000FFFF
	ands r6, r5
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, r8
	ands r7, r4
	orrs r7, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r7, r5
	orrs r7, r0
	orrs r6, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08017C88
	adds r2, #0x3f
_08017C88:
	asrs r2, r2, #6
	mov r0, ip
	ldr r0, [r0]
	mov r8, r0
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r6, r5
	ldr r4, _08017D04 @ =0x02031520
	adds r3, r3, r2
	lsls r3, r3, #2
	adds r2, r4, #0
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r7, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	adds r4, #0x58
	adds r3, r3, r4
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsrs r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #3
	add r0, r8
	ldrh r3, [r0]
	ldr r2, _08017D08 @ =0x00000402
	add r2, r8
	ldrh r4, [r2]
	adds r0, r1, #0
	subs r0, #8
	cmp r0, #4
	bls _08017CEE
	b _08017F18
_08017CEE:
	lsls r0, r0, #2
	ldr r1, _08017D0C @ =_08017D10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017CF8: .4byte 0x020314E0
_08017CFC: .4byte 0xFFFF0000
_08017D00: .4byte 0x0000FFFF
_08017D04: .4byte 0x02031520
_08017D08: .4byte 0x00000402
_08017D0C: .4byte _08017D10
_08017D10: @ jump table
	.4byte _08017D24 @ case 0
	.4byte _08017D74 @ case 1
	.4byte _08017DBE @ case 2
	.4byte _08017E9C @ case 3
	.4byte _08017EEC @ case 4
_08017D24:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017D50
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x38
	bgt _08017D40
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017D3C @ =0x0000041C
	b _08017F0A
	.align 2, 0
_08017D3C: .4byte 0x0000041C
_08017D40:
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017D4C @ =0x0000041D
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017D4C: .4byte 0x0000041D
_08017D50:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	bgt _08017D64
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017D60 @ =0x0000041F
	b _08017F0A
	.align 2, 0
_08017D60: .4byte 0x0000041F
_08017D64:
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017D70 @ =0x0000041E
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017D70: .4byte 0x0000041E
_08017D74:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017DA0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017D90
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017D8C @ =0x00000427
	b _08017F0A
	.align 2, 0
_08017D8C: .4byte 0x00000427
_08017D90:
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017D9C @ =0x00000425
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017D9C: .4byte 0x00000425
_08017DA0:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017DB2
	mov r3, ip
	ldr r0, [r3]
	movs r4, #0x85
	lsls r4, r4, #3
	b _08017F0A
_08017DB2:
	mov r1, ip
	ldr r0, [r1]
	movs r2, #0x84
	lsls r2, r2, #3
	adds r1, r0, r2
	b _08017F0C
_08017DBE:
	mov r3, ip
	ldr r0, [r3]
	movs r4, #0xfe
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r2, [r3]
	ldr r1, _08017E10 @ =0x00000412
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _08017E18
	adds r4, #8
	adds r0, r2, r4
	ldr r1, [r0]
	ldr r3, _08017E14 @ =0x00000434
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r1, r0
	bne _08017DEC
	b _08017F18
_08017DEC:
	adds r4, #0x2e
	adds r1, r2, r4
	movs r0, #0x11
	strb r0, [r1]
	mov r0, ip
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #0x32
	adds r0, r1, r3
	ldrh r0, [r0]
	adds r4, #8
	b _08017E90
	.align 2, 0
_08017E10: .4byte 0x00000412
_08017E14: .4byte 0x00000434
_08017E18:
	cmp r0, #8
	bne _08017E58
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, #0x87
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r1, r0
	beq _08017F18
	ldr r4, _08017E54 @ =0x0000042F
	adds r1, r2, r4
	movs r0, #0x11
	strb r0, [r1]
	mov r0, ip
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #0x36
	adds r0, r1, r3
	ldrh r0, [r0]
	adds r4, #0xb
	b _08017E90
	.align 2, 0
_08017E54: .4byte 0x0000042F
_08017E58:
	cmp r0, #0x10
	bne _08017F18
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r3, _08017E98 @ =0x0000043C
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r1, r0
	beq _08017F18
	movs r4, #0x86
	lsls r4, r4, #3
	adds r1, r2, r4
	movs r0, #0x11
	strb r0, [r1]
	mov r0, ip
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #0x3a
	adds r0, r1, r3
	ldrh r0, [r0]
	adds r4, #0xe
_08017E90:
	adds r1, r1, r4
	strh r0, [r1]
	b _08017F18
	.align 2, 0
_08017E98: .4byte 0x0000043C
_08017E9C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017EC8
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017EBC
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017EB8 @ =0x00000429
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017EB8: .4byte 0x00000429
_08017EBC:
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017EC4 @ =0x00000422
	b _08017F0A
	.align 2, 0
_08017EC4: .4byte 0x00000422
_08017EC8:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bgt _08017EE0
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017EDC @ =0x00000426
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017EDC: .4byte 0x00000426
_08017EE0:
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017EE8 @ =0x00000421
	b _08017F0A
	.align 2, 0
_08017EE8: .4byte 0x00000421
_08017EEC:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x72
	bgt _08017F04
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _08017F00 @ =0x00000424
	adds r1, r0, r2
	b _08017F0C
	.align 2, 0
_08017F00: .4byte 0x00000424
_08017F04:
	mov r3, ip
	ldr r0, [r3]
	ldr r4, _08017F24 @ =0x00000423
_08017F0A:
	adds r1, r0, r4
_08017F0C:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08017F18
	movs r0, #0x18
	strb r0, [r1]
_08017F18:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017F24: .4byte 0x00000423

	thumb_func_start sub_17F28
sub_17F28: @ 0x08017F28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r3, #0
	strh r3, [r2]
	ldr r0, _08018018 @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _0801801C @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r3, [r0, #4]
	mov r0, sb
	movs r4, #2
	ldrsh r1, [r0, r4]
	ldr r0, _08018020 @ =0x000001FF
	cmp r1, r0
	bgt _08018030
	mov r7, sb
	movs r0, #0
	ldrsh r4, [r7, r0]
	adds r0, r4, #0
	cmp r4, #0
	bge _08017F66
	adds r0, r4, #7
_08017F66:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08018024 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08017F82
	adds r0, r3, #7
_08017F82:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _08018028 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08017FAE
	adds r2, #0x3f
_08017FAE:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _0801802C @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r0, sp
	adds r0, #2
	strb r1, [r0]
	adds r4, r0, #0
	b _0801803E
	.align 2, 0
_08018018: .4byte 0x020314E0
_0801801C: .4byte 0x0000132C
_08018020: .4byte 0x000001FF
_08018024: .4byte 0xFFFF0000
_08018028: .4byte 0x0000FFFF
_0801802C: .4byte 0x02031520
_08018030:
	mov r0, sp
	strh r3, [r0]
	mov r1, sp
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r4, r1, #0
_0801803E:
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_18180
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _08018058
	b _0801815E
_08018058:
	lsls r0, r0, #2
	ldr r1, _08018064 @ =_08018068
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018064: .4byte _08018068
_08018068: @ jump table
	.4byte _08018080 @ case 0
	.4byte _0801812C @ case 1
	.4byte _0801812C @ case 2
	.4byte _08018080 @ case 3
	.4byte _0801815C @ case 4
	.4byte _08018080 @ case 5
_08018080:
	ldr r2, _080180F8 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _080180FC @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08018120
	ldr r0, [r2]
	ldr r7, _08018100 @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08018104 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _080180CC
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08018120
_080180CC:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _080180EA
	cmp r0, #0
	bne _08018116
	ldr r0, _08018108 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _0801810C
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_080180EA:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _08018120
	.align 2, 0
_080180F8: .4byte 0x020314E0
_080180FC: .4byte 0xFFFFC010
_08018100: .4byte 0x0000132C
_08018104: .4byte 0x02031520
_08018108: .4byte gMain
_0801810C:
	ldr r0, _08018128 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08018116:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_08018120:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _0801815E
	.align 2, 0
_08018128: .4byte 0x0000FFD8
_0801812C:
	ldr r2, _08018154 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08018158 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _0801815E
	.align 2, 0
_08018154: .4byte 0x020314E0
_08018158: .4byte 0x0000FFF0
_0801815C:
	movs r6, #4
_0801815E:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_182B4
	mov r1, sp
	movs r2, #4
	ldrsh r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_18180
sub_18180: @ 0x08018180
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r0, _080181DC @ =0x020314E0
	ldr r4, [r0]
	ldr r1, _080181E0 @ =0x00000387
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080181EC
	ldrb r1, [r5]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0801829C
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _080181E4 @ =0x000003F2
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x77
	bhi _0801829C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x97
	bhi _0801829C
	ldr r2, _080181E8 @ =0x08340B58
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	b _08018278
	.align 2, 0
_080181DC: .4byte 0x020314E0
_080181E0: .4byte 0x00000387
_080181E4: .4byte 0x000003F2
_080181E8: .4byte 0x08340B58
_080181EC:
	cmp r0, #2
	bne _08018234
	ldrb r1, [r5]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0801829C
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _0801822C @ =0x000003F2
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x5f
	bhi _0801829C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x57
	bhi _0801829C
	ldr r2, _08018230 @ =0x083499D8
	b _08018270
	.align 2, 0
_0801822C: .4byte 0x000003F2
_08018230: .4byte 0x083499D8
_08018234:
	cmp r0, #3
	bne _0801829C
	ldrb r1, [r5]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0801829C
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _080182A4 @ =0x000003F2
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x5f
	bhi _0801829C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x67
	bhi _0801829C
	ldr r2, _080182A8 @ =0x0834DBD8
_08018270:
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
_08018278:
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _080182AC @ =0x0000FFF0
	ands r2, r0
	adds r3, r7, #0
	ands r3, r0
	cmp r3, #0
	beq _0801829C
	ldr r1, _080182B0 @ =0x00000452
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	strh r2, [r6]
	movs r0, #6
	strb r0, [r5]
_0801829C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080182A4: .4byte 0x000003F2
_080182A8: .4byte 0x0834DBD8
_080182AC: .4byte 0x0000FFF0
_080182B0: .4byte 0x00000452

	thumb_func_start sub_182B4
sub_182B4: @ 0x080182B4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bhi _0801831C
	lsls r0, r0, #2
	ldr r1, _080182C8 @ =_080182CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080182C8: .4byte _080182CC
_080182CC: @ jump table
	.4byte _0801831C @ case 0
	.4byte _0801831C @ case 1
	.4byte _0801831C @ case 2
	.4byte _08018308 @ case 3
	.4byte _0801831C @ case 4
	.4byte _0801831C @ case 5
	.4byte _0801831C @ case 6
	.4byte _0801831C @ case 7
	.4byte _0801831C @ case 8
	.4byte _0801831C @ case 9
	.4byte _0801831C @ case 10
	.4byte _0801831C @ case 11
	.4byte _0801831C @ case 12
	.4byte _0801831C @ case 13
	.4byte _0801831C @ case 14
_08018308:
	ldr r2, _08018320 @ =0x020314E0
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
_0801831C:
	bx lr
	.align 2, 0
_08018320: .4byte 0x020314E0

	thumb_func_start sub_18324
sub_18324: @ 0x08018324
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r3, #0
	strh r3, [r2]
	ldr r0, _08018414 @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08018418 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r3, [r0, #4]
	mov r0, sb
	movs r4, #2
	ldrsh r1, [r0, r4]
	ldr r0, _0801841C @ =0x000001FF
	cmp r1, r0
	bgt _0801842C
	mov r7, sb
	movs r0, #0
	ldrsh r4, [r7, r0]
	adds r0, r4, #0
	cmp r4, #0
	bge _08018362
	adds r0, r4, #7
_08018362:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08018420 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _0801837E
	adds r0, r3, #7
_0801837E:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _08018424 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _080183AA
	adds r2, #0x3f
_080183AA:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _08018428 @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r0, sp
	adds r0, #2
	strb r1, [r0]
	adds r4, r0, #0
	b _0801843A
	.align 2, 0
_08018414: .4byte 0x020314E0
_08018418: .4byte 0x0000132C
_0801841C: .4byte 0x000001FF
_08018420: .4byte 0xFFFF0000
_08018424: .4byte 0x0000FFFF
_08018428: .4byte 0x02031520
_0801842C:
	mov r0, sp
	strh r3, [r0]
	mov r1, sp
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r4, r1, #0
_0801843A:
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_1857C
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _08018454
	b _0801855A
_08018454:
	lsls r0, r0, #2
	ldr r1, _08018460 @ =_08018464
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018460: .4byte _08018464
_08018464: @ jump table
	.4byte _0801847C @ case 0
	.4byte _08018528 @ case 1
	.4byte _08018528 @ case 2
	.4byte _0801847C @ case 3
	.4byte _08018558 @ case 4
	.4byte _0801847C @ case 5
_0801847C:
	ldr r2, _080184F4 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _080184F8 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _0801851C
	ldr r0, [r2]
	ldr r7, _080184FC @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _08018500 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _080184C8
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _0801851C
_080184C8:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _080184E6
	cmp r0, #0
	bne _08018512
	ldr r0, _08018504 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08018508
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_080184E6:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _0801851C
	.align 2, 0
_080184F4: .4byte 0x020314E0
_080184F8: .4byte 0xFFFFC010
_080184FC: .4byte 0x0000132C
_08018500: .4byte 0x02031520
_08018504: .4byte gMain
_08018508:
	ldr r0, _08018524 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08018512:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_0801851C:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _0801855A
	.align 2, 0
_08018524: .4byte 0x0000FFD8
_08018528:
	ldr r2, _08018550 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08018554 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _0801855A
	.align 2, 0
_08018550: .4byte 0x020314E0
_08018554: .4byte 0x0000FFF0
_08018558:
	movs r6, #4
_0801855A:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_18784
	mov r1, sp
	movs r2, #4
	ldrsh r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_1857C
sub_1857C: @ 0x0801857C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sl, r1
	mov ip, r2
	ldr r0, _08018758 @ =0x020314E0
	ldr r4, [r0]
	ldr r1, _0801875C @ =0x00000387
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0801860E
	ldrb r1, [r2]
	movs r5, #0xf
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0801860E
	movs r3, #0xfc
	lsls r3, r3, #2
	adds r0, r4, r3
	mov r1, r8
	ldrh r2, [r1]
	ldrh r0, [r0]
	subs r2, r2, r0
	adds r3, #2
	adds r1, r4, r3
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x6f
	bhi _0801860E
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x7f
	bhi _0801860E
	ldr r2, _08018760 @ =0x083579C8
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, _08018764 @ =0x0000FFF0
	ands r1, r0
	adds r3, r5, #0
	ands r3, r0
	cmp r3, #0
	beq _0801860E
	ldr r0, _08018768 @ =0x00000452
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _08018606
	movs r0, #0x27
	strh r0, [r2]
_08018606:
	mov r0, sl
	strh r1, [r0]
	mov r1, ip
	strb r3, [r1]
_0801860E:
	movs r5, #0
	ldr r3, _08018758 @ =0x020314E0
	mov sb, r3
_08018614:
	mov r0, sb
	ldr r1, [r0]
	lsls r0, r5, #0x10
	asrs r6, r0, #0x10
	lsls r0, r6, #2
	adds r3, r1, r0
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0801869C
	mov r0, ip
	ldrb r1, [r0]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0801869C
	mov r1, r8
	ldrh r2, [r1]
	subs r2, r2, r4
	ldr r0, _0801876C @ =0x000004FA
	adds r1, r3, r0
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x4f
	bhi _0801869C
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x4f
	bhi _0801869C
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r2, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08018770 @ =0x0835E9C8
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _08018764 @ =0x0000FFF0
	ands r1, r0
	adds r3, r7, #0
	ands r3, r0
	cmp r3, #0
	beq _0801869C
	mov r3, sl
	strh r1, [r3]
	movs r0, #6
	mov r1, ip
	strb r0, [r1]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, _08018774 @ =0x000004D5
	adds r0, r0, r1
	adds r0, r0, r6
	movs r1, #1
	strb r1, [r0]
_0801869C:
	lsls r0, r5, #0x10
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r0, r3
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08018614
	movs r5, #0
	ldr r0, _08018758 @ =0x020314E0
	mov sb, r0
_080186B2:
	mov r3, sb
	ldr r1, [r3]
	lsls r2, r5, #0x10
	asrs r5, r2, #0x10
	lsls r0, r5, #2
	adds r3, r1, r0
	ldr r1, _08018778 @ =0x000004B4
	adds r0, r3, r1
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r7, r2, #0
	cmp r0, #0
	ble _0801873A
	mov r0, ip
	ldrb r1, [r0]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0801873A
	mov r1, r8
	ldrh r2, [r1]
	subs r2, r2, r4
	ldr r0, _0801877C @ =0x000004B6
	adds r1, r3, r0
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x4f
	bhi _0801873A
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x4f
	bhi _0801873A
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r1, r2, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08018770 @ =0x0835E9C8
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _08018764 @ =0x0000FFF0
	ands r1, r0
	adds r3, r6, #0
	ands r3, r0
	cmp r3, #0
	beq _0801873A
	mov r3, sl
	strh r1, [r3]
	movs r0, #6
	mov r1, ip
	strb r0, [r1]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, _08018780 @ =0x000004A4
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #8
	strb r1, [r0]
_0801873A:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r7, r3
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080186B2
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018758: .4byte 0x020314E0
_0801875C: .4byte 0x00000387
_08018760: .4byte 0x083579C8
_08018764: .4byte 0x0000FFF0
_08018768: .4byte 0x00000452
_0801876C: .4byte 0x000004FA
_08018770: .4byte 0x0835E9C8
_08018774: .4byte 0x000004D5
_08018778: .4byte 0x000004B4
_0801877C: .4byte 0x000004B6
_08018780: .4byte 0x000004A4

	thumb_func_start sub_18784
sub_18784: @ 0x08018784
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bhi _080187EC
	lsls r0, r0, #2
	ldr r1, _08018798 @ =_0801879C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018798: .4byte _0801879C
_0801879C: @ jump table
	.4byte _080187EC @ case 0
	.4byte _080187EC @ case 1
	.4byte _080187EC @ case 2
	.4byte _080187D8 @ case 3
	.4byte _080187EC @ case 4
	.4byte _080187EC @ case 5
	.4byte _080187EC @ case 6
	.4byte _080187EC @ case 7
	.4byte _080187EC @ case 8
	.4byte _080187EC @ case 9
	.4byte _080187EC @ case 10
	.4byte _080187EC @ case 11
	.4byte _080187EC @ case 12
	.4byte _080187EC @ case 13
	.4byte _080187EC @ case 14
_080187D8:
	ldr r2, _080187F0 @ =0x020314E0
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
_080187EC:
	bx lr
	.align 2, 0
_080187F0: .4byte 0x020314E0

	thumb_func_start sub_187F4
sub_187F4: @ 0x080187F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r3, #0
	strh r3, [r2]
	ldr r0, _080188E4 @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _080188E8 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r3, [r0, #4]
	mov r0, sb
	movs r4, #2
	ldrsh r1, [r0, r4]
	ldr r0, _080188EC @ =0x000001FF
	cmp r1, r0
	bgt _080188FC
	mov r7, sb
	movs r0, #0
	ldrsh r4, [r7, r0]
	adds r0, r4, #0
	cmp r4, #0
	bge _08018832
	adds r0, r4, #7
_08018832:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080188F0 @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _0801884E
	adds r0, r3, #7
_0801884E:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _080188F4 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _0801887A
	adds r2, #0x3f
_0801887A:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _080188F8 @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r0, sp
	adds r0, #2
	strb r1, [r0]
	adds r4, r0, #0
	b _0801890A
	.align 2, 0
_080188E4: .4byte 0x020314E0
_080188E8: .4byte 0x0000132C
_080188EC: .4byte 0x000001FF
_080188F0: .4byte 0xFFFF0000
_080188F4: .4byte 0x0000FFFF
_080188F8: .4byte 0x02031520
_080188FC:
	mov r0, sp
	strh r3, [r0]
	mov r1, sp
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r4, r1, #0
_0801890A:
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_18A4C
	ldrb r0, [r4]
	movs r3, #0xf
	ands r3, r0
	lsrs r6, r0, #4
	subs r0, r3, #1
	cmp r0, #5
	bls _08018924
	b _08018A2A
_08018924:
	lsls r0, r0, #2
	ldr r1, _08018930 @ =_08018934
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018930: .4byte _08018934
_08018934: @ jump table
	.4byte _0801894C @ case 0
	.4byte _080189F8 @ case 1
	.4byte _080189F8 @ case 2
	.4byte _0801894C @ case 3
	.4byte _08018A28 @ case 4
	.4byte _0801894C @ case 5
_0801894C:
	ldr r2, _080189C4 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _080189C8 @ =0xFFFFC010
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _080189EC
	ldr r0, [r2]
	ldr r7, _080189CC @ =0x0000132C
	adds r3, r0, r7
	ldr r2, [r3]
	movs r0, #0x10
	ldrsh r1, [r2, r0]
	ldr r4, _080189D0 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08018998
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _080189EC
_08018998:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _080189B6
	cmp r0, #0
	bne _080189E2
	ldr r0, _080189D4 @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _080189D8
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_080189B6:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _080189EC
	.align 2, 0
_080189C4: .4byte 0x020314E0
_080189C8: .4byte 0xFFFFC010
_080189CC: .4byte 0x0000132C
_080189D0: .4byte 0x02031520
_080189D4: .4byte gMain
_080189D8:
	ldr r0, _080189F4 @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_080189E2:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_080189EC:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _08018A2A
	.align 2, 0
_080189F4: .4byte 0x0000FFD8
_080189F8:
	ldr r2, _08018A20 @ =0x020314E0
	ldr r0, [r2]
	subs r1, r3, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08018A24 @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	movs r0, #1
	mov r7, sp
	strh r0, [r7, #4]
	b _08018A2A
	.align 2, 0
_08018A20: .4byte 0x020314E0
_08018A24: .4byte 0x0000FFF0
_08018A28:
	movs r6, #4
_08018A2A:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_18AE0
	mov r1, sp
	movs r2, #4
	ldrsh r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_18A4C
sub_18A4C: @ 0x08018A4C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	ldr r0, _08018AC8 @ =0x020314E0
	ldr r4, [r0]
	ldr r1, _08018ACC @ =0x00000387
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08018AC2
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08018AC2
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08018AD0 @ =0x000003F2
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x7f
	bhi _08018AC2
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x7f
	bhi _08018AC2
	ldr r2, _08018AD4 @ =0x083722E8
	asrs r0, r3, #9
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _08018AD8 @ =0x0000FFF0
	ands r2, r0
	adds r3, r6, #0
	ands r3, r0
	cmp r3, #0
	beq _08018AC2
	ldr r0, _08018ADC @ =0x00000452
	adds r1, r4, r0
	movs r0, #9
	strh r0, [r1]
	strh r2, [r7]
	strb r3, [r5]
_08018AC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018AC8: .4byte 0x020314E0
_08018ACC: .4byte 0x00000387
_08018AD0: .4byte 0x000003F2
_08018AD4: .4byte 0x083722E8
_08018AD8: .4byte 0x0000FFF0
_08018ADC: .4byte 0x00000452

	thumb_func_start sub_18AE0
sub_18AE0: @ 0x08018AE0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bhi _08018B48
	lsls r0, r0, #2
	ldr r1, _08018AF4 @ =_08018AF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018AF4: .4byte _08018AF8
_08018AF8: @ jump table
	.4byte _08018B48 @ case 0
	.4byte _08018B48 @ case 1
	.4byte _08018B48 @ case 2
	.4byte _08018B34 @ case 3
	.4byte _08018B48 @ case 4
	.4byte _08018B48 @ case 5
	.4byte _08018B48 @ case 6
	.4byte _08018B48 @ case 7
	.4byte _08018B48 @ case 8
	.4byte _08018B48 @ case 9
	.4byte _08018B48 @ case 10
	.4byte _08018B48 @ case 11
	.4byte _08018B48 @ case 12
	.4byte _08018B48 @ case 13
	.4byte _08018B48 @ case 14
_08018B34:
	ldr r2, _08018B4C @ =0x020314E0
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #0x1f]
_08018B48:
	bx lr
	.align 2, 0
_08018B4C: .4byte 0x020314E0

	thumb_func_start sub_18B50
sub_18B50: @ 0x08018B50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r8, r1
	add r2, sp, #4
	movs r1, #0
	strh r1, [r2]
	ldr r0, _08018C54 @ =0x020314E0
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08018C58 @ =0x0000132C
	add r0, sl
	ldr r0, [r0]
	strh r1, [r0, #4]
	mov r0, sb
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r4, #0
	cmp r4, #0
	bge _08018B82
	adds r0, r4, #7
_08018B82:
	asrs r1, r0, #3
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08018C5C @ =0xFFFF0000
	mov ip, r2
	ands r5, r2
	orrs r5, r0
	mov r7, sb
	movs r0, #2
	ldrsh r3, [r7, r0]
	adds r0, r3, #0
	cmp r3, #0
	bge _08018B9E
	adds r0, r3, #7
_08018B9E:
	asrs r0, r0, #3
	lsls r2, r0, #0x10
	ldr r7, _08018C60 @ =0x0000FFFF
	ands r5, r7
	lsls r1, r1, #3
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r4, ip
	ands r6, r4
	orrs r6, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	lsls r0, r0, #0x10
	ands r6, r7
	orrs r6, r0
	orrs r5, r2
	asrs r4, r2, #0x10
	adds r2, r4, #0
	cmp r4, #0
	bge _08018BCA
	adds r2, #0x3f
_08018BCA:
	asrs r2, r2, #6
	mov r0, sl
	adds r0, #0x24
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r1, r2, #6
	subs r1, r4, r1
	lsls r1, r1, #0x10
	ands r5, r7
	ldr r7, _08018C64 @ =0x02031520
	mov ip, r7
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r2, ip
	adds r2, #0x38
	adds r2, r3, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0xa
	adds r1, r1, r0
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r4, ip
	adds r4, #0x48
	adds r4, r3, r4
	movs r0, #0
	ldrsh r2, [r1, r0]
	asrs r1, r6, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #3
	lsls r2, r2, #6
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r2, [r4]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, sp
	strh r2, [r0]
	mov r0, ip
	adds r0, #0x58
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #2
	strb r0, [r4]
	mov r0, sb
	mov r1, sp
	adds r2, r4, #0
	bl sub_18DAC
	ldrb r0, [r4]
	movs r2, #0xf
	ands r2, r0
	lsrs r6, r0, #4
	subs r0, r2, #1
	cmp r0, #5
	bls _08018C48
	b _08018D8A
_08018C48:
	lsls r0, r0, #2
	ldr r1, _08018C68 @ =_08018C6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018C54: .4byte 0x020314E0
_08018C58: .4byte 0x0000132C
_08018C5C: .4byte 0xFFFF0000
_08018C60: .4byte 0x0000FFFF
_08018C64: .4byte 0x02031520
_08018C68: .4byte _08018C6C
_08018C6C: @ jump table
	.4byte _08018C84 @ case 0
	.4byte _08018D30 @ case 1
	.4byte _08018D30 @ case 2
	.4byte _08018C84 @ case 3
	.4byte _08018D88 @ case 4
	.4byte _08018C84 @ case 5
_08018C84:
	ldr r3, _08018CFC @ =0x020314E0
	ldr r0, [r3]
	subs r1, r2, #1
	adds r0, #0x23
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x22
	movs r5, #1
	strb r5, [r0]
	mov r0, sp
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
	ldr r2, _08018D00 @ =0xFFFFC010
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bhi _08018D24
	ldr r0, [r3]
	ldr r4, _08018D04 @ =0x0000132C
	adds r3, r0, r4
	ldr r2, [r3]
	movs r7, #0x10
	ldrsh r1, [r2, r7]
	ldr r4, _08018D08 @ =0x02031520
	movs r7, #0x26
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	blt _08018CD0
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	movs r7, #0x28
	ldrsh r0, [r4, r7]
	subs r0, #8
	cmp r1, r0
	bge _08018D24
_08018CD0:
	movs r1, #6
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08018CEE
	cmp r0, #0
	bne _08018D1A
	ldr r0, _08018D0C @ =gMain
	ldr r0, [r0, #0x4c]
	ands r0, r5
	cmp r0, #0
	beq _08018D10
	movs r0, #0x28
	strh r0, [r2, #4]
	ldr r0, [r3]
	strh r5, [r0, #6]
_08018CEE:
	movs r2, #0xf8
	lsls r2, r2, #6
	adds r0, r2, #0
	mov r4, r8
	strh r0, [r4]
	b _08018D24
	.align 2, 0
_08018CFC: .4byte 0x020314E0
_08018D00: .4byte 0xFFFFC010
_08018D04: .4byte 0x0000132C
_08018D08: .4byte 0x02031520
_08018D0C: .4byte gMain
_08018D10:
	ldr r0, _08018D2C @ =0x0000FFD8
	strh r0, [r2, #4]
	ldr r1, [r3]
	adds r0, #0x27
	strh r0, [r1, #6]
_08018D1A:
	movs r7, #0x82
	lsls r7, r7, #7
	adds r0, r7, #0
	mov r1, r8
	strh r0, [r1]
_08018D24:
	movs r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	b _08018D8A
	.align 2, 0
_08018D2C: .4byte 0x0000FFD8
_08018D30:
	ldr r2, _08018D68 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x23
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #1
	strb r1, [r0]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08018D6C @ =0x0000FFF0
	ands r0, r1
	mov r4, r8
	strh r0, [r4]
	ldr r1, [r2]
	ldr r7, _08018D70 @ =0x0000132C
	adds r0, r1, r7
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	cmp r0, #0x77
	bgt _08018D74
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r1, r1, r4
	b _08018D78
	.align 2, 0
_08018D68: .4byte 0x020314E0
_08018D6C: .4byte 0x0000FFF0
_08018D70: .4byte 0x0000132C
_08018D74:
	ldr r7, _08018D84 @ =0x00000549
	adds r1, r1, r7
_08018D78:
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	b _08018D8A
	.align 2, 0
_08018D84: .4byte 0x00000549
_08018D88:
	movs r6, #4
_08018D8A:
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	bl sub_18F38
	mov r2, sp
	movs r4, #4
	ldrsh r0, [r2, r4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_18DAC
sub_18DAC: @ 0x08018DAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	mov sb, r1
	adds r7, r2, #0
	movs r1, #0
_08018DBE:
	ldr r0, _08018E5C @ =0x020314E0
	ldr r6, [r0]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x10
	ldr r2, _08018E60 @ =0x0000054F
	adds r0, r6, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sl, r1
	cmp r0, #1
	bne _08018E74
	ldrb r1, [r7]
	movs r3, #0xf
	mov r8, r3
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _08018DE8
	b _08018F16
_08018DE8:
	lsls r1, r5, #2
	adds r1, r6, r1
	adds r2, #0x21
	adds r0, r1, r2
	mov r3, ip
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08018E64 @ =0x00000572
	adds r1, r1, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r2, #0x10
	lsrs r0, r4, #0x10
	cmp r0, #0x3f
	bls _08018E10
	b _08018F16
_08018E10:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bls _08018E1A
	b _08018F16
_08018E1A:
	ldr r2, _08018E68 @ =0x08393A4C
	asrs r0, r3, #0xa
	asrs r1, r4, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, _08018E6C @ =0x0000FFF0
	ands r1, r0
	mov r3, r8
	ands r3, r0
	cmp r3, #0
	beq _08018F16
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08018F16
	mov r3, sb
	strh r1, [r3]
	movs r0, #6
	strb r0, [r7]
	ldr r1, _08018E5C @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _08018E70 @ =0x00000553
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #4
	b _08018F14
	.align 2, 0
_08018E5C: .4byte 0x020314E0
_08018E60: .4byte 0x0000054F
_08018E64: .4byte 0x00000572
_08018E68: .4byte 0x08393A4C
_08018E6C: .4byte 0x0000FFF0
_08018E70: .4byte 0x00000553
_08018E74:
	cmp r0, #0
	beq _08018F16
	ldrb r1, [r7]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08018F16
	lsls r1, r5, #2
	adds r1, r6, r1
	movs r3, #0xae
	lsls r3, r3, #3
	adds r0, r1, r3
	mov r3, ip
	ldrh r2, [r3]
	ldrh r0, [r0]
	subs r2, r2, r0
	ldr r0, _08018EF4 @ =0x00000572
	adds r1, r1, r0
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _08018F16
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08018F16
	ldr r2, _08018EF8 @ =0x08391A4C
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, _08018EFC @ =0x0000FFF0
	ands r1, r0
	adds r3, r4, #0
	ands r3, r0
	cmp r3, #0
	beq _08018F16
	mov r2, sb
	strh r1, [r2]
	movs r0, #6
	strb r0, [r7]
	ldr r3, _08018F00 @ =0x020314E0
	ldr r1, [r3]
	ldr r2, _08018F04 @ =0x0000054F
	adds r0, r1, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08018F0C
	ldr r3, _08018F08 @ =0x00000553
	adds r0, r1, r3
	adds r0, r0, r5
	movs r1, #4
	b _08018F14
	.align 2, 0
_08018EF4: .4byte 0x00000572
_08018EF8: .4byte 0x08391A4C
_08018EFC: .4byte 0x0000FFF0
_08018F00: .4byte 0x020314E0
_08018F04: .4byte 0x0000054F
_08018F08: .4byte 0x00000553
_08018F0C:
	ldr r2, _08018F34 @ =0x0000054D
	adds r0, r1, r2
	adds r0, r0, r5
	movs r1, #0x18
_08018F14:
	strb r1, [r0]
_08018F16:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08018F26
	b _08018DBE
_08018F26:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018F34: .4byte 0x0000054D

	thumb_func_start sub_18F38
sub_18F38: @ 0x08018F38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bhi _0801901C
	lsls r0, r0, #2
	ldr r1, _08018F4C @ =_08018F50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018F4C: .4byte _08018F50
_08018F50: @ jump table
	.4byte _0801901C @ case 0
	.4byte _08018F8C @ case 1
	.4byte _08018FAC @ case 2
	.4byte _0801901C @ case 3
	.4byte _0801901C @ case 4
	.4byte _0801901C @ case 5
	.4byte _0801901C @ case 6
	.4byte _08018FD0 @ case 7
	.4byte _08018FFC @ case 8
	.4byte _0801901C @ case 9
	.4byte _0801901C @ case 10
	.4byte _0801901C @ case 11
	.4byte _0801901C @ case 12
	.4byte _0801901C @ case 13
	.4byte _0801901C @ case 14
_08018F8C:
	ldr r2, _08018FA4 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _08018FA8 @ =0x00000532
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, #0xa7
	lsls r2, r2, #3
	adds r0, r0, r2
	b _08018FC0
	.align 2, 0
_08018FA4: .4byte 0x020314E0
_08018FA8: .4byte 0x00000532
_08018FAC:
	ldr r2, _08018FC8 @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _08018FCC @ =0x00000532
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0xa7
	lsls r1, r1, #3
	adds r0, r0, r1
_08018FC0:
	movs r1, #2
	strb r1, [r0]
	b _0801901C
	.align 2, 0
_08018FC8: .4byte 0x020314E0
_08018FCC: .4byte 0x00000532
_08018FD0:
	ldr r2, _08018FF4 @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _08018FF8 @ =0x00000532
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0xa7
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r0, r2
	b _08019018
	.align 2, 0
_08018FF4: .4byte 0x020314E0
_08018FF8: .4byte 0x00000532
_08018FFC:
	ldr r1, _08019020 @ =0x020314E0
	ldr r0, [r1]
	ldr r3, _08019024 @ =0x00000532
	adds r0, r0, r3
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	adds r3, #6
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r0, r1
_08019018:
	movs r1, #0x64
	strh r1, [r0]
_0801901C:
	bx lr
	.align 2, 0
_08019020: .4byte 0x020314E0
_08019024: .4byte 0x00000532

	thumb_func_start sub_19028_Main
sub_19028_Main: @ 0x08019028
	push {lr}
	ldr r1, _08019040 @ =0x08137918
	ldr r0, _08019044 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08019040: .4byte 0x08137918
_08019044: .4byte gMain

	thumb_func_start sub_19048
sub_19048: @ 0x08019048
	push {r4, r5, lr}
	ldr r1, _080190A4 @ =gMain
	movs r2, #0
	str r2, [r1, #0x54]
	movs r0, #1
	strb r0, [r1, #0xd]
	ldr r0, _080190A8 @ =0x02031510
	str r2, [r0]
	adds r5, r1, #0
	ldr r4, _080190AC @ =0x02031520
	adds r3, r5, #7
_0801905E:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r4
	adds r1, r0, r3
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0801905E
	adds r4, r5, #0
	ldrh r0, [r4, #0x30]
	cmp r0, #0
	bne _0801908E
	bl sub_C00
	ldr r1, [r4, #0x4c]
	adds r0, r0, r1
	movs r1, #0x1e
	bl __umodsi3
	strh r0, [r4, #0x30]
_0801908E:
	ldrh r4, [r5, #0x30]
	movs r0, #3
	ands r4, r0
	adds r0, r4, #0
	cmp r0, #1
	beq _080190D8
	cmp r0, #1
	bgt _080190B0
	cmp r0, #0
	beq _080190BA
	b _0801911E
	.align 2, 0
_080190A4: .4byte gMain
_080190A8: .4byte 0x02031510
_080190AC: .4byte 0x02031520
_080190B0:
	cmp r0, #2
	beq _080190F4
	cmp r0, #3
	beq _08019110
	b _0801911E
_080190BA:
	ldr r1, _080190C8 @ =0x02031520
	ldr r0, _080190CC @ =0x00000A14
	strh r0, [r1, #6]
	ldr r0, _080190D0 @ =0x081450F4
	str r0, [r1, #0x10]
	ldr r0, _080190D4 @ =0x081531F4
	b _0801911C
	.align 2, 0
_080190C8: .4byte 0x02031520
_080190CC: .4byte 0x00000A14
_080190D0: .4byte 0x081450F4
_080190D4: .4byte 0x081531F4
_080190D8:
	ldr r1, _080190E8 @ =0x02031520
	movs r0, #0xf0
	lsls r0, r0, #4
	strh r0, [r1, #6]
	ldr r0, _080190EC @ =0x0814F9B4
	str r0, [r1, #0x10]
	ldr r0, _080190F0 @ =0x08156E60
	b _0801911C
	.align 2, 0
_080190E8: .4byte 0x02031520
_080190EC: .4byte 0x0814F9B4
_080190F0: .4byte 0x08156E60
_080190F4:
	ldr r1, _08019104 @ =0x02031520
	movs r0, #0xd2
	lsls r0, r0, #4
	strh r0, [r1, #6]
	ldr r0, _08019108 @ =0x08148934
	str r0, [r1, #0x10]
	ldr r0, _0801910C @ =0x08154618
	b _0801911C
	.align 2, 0
_08019104: .4byte 0x02031520
_08019108: .4byte 0x08148934
_0801910C: .4byte 0x08154618
_08019110:
	ldr r1, _08019134 @ =0x02031520
	ldr r0, _08019138 @ =0x00000E4C
	strh r0, [r1, #6]
	ldr r0, _0801913C @ =0x0814C174
	str r0, [r1, #0x10]
	ldr r0, _08019140 @ =0x08155A3C
_0801911C:
	str r0, [r1, #0xc]
_0801911E:
	bl sub_49ED4
	adds r1, r4, #0
	cmp r1, #1
	beq _0801914E
	cmp r1, #1
	bgt _08019144
	cmp r1, #0
	beq _08019156
	b _08019164
	.align 2, 0
_08019134: .4byte 0x02031520
_08019138: .4byte 0x00000E4C
_0801913C: .4byte 0x0814C174
_08019140: .4byte 0x08155A3C
_08019144:
	cmp r1, #2
	beq _08019156
	cmp r1, #3
	beq _0801915E
	b _08019164
_0801914E:
	movs r0, #0x20
	bl m4aSongNumStart
	b _08019164
_08019156:
	movs r0, #0x1c
	bl m4aSongNumStart
	b _08019164
_0801915E:
	movs r0, #0x20
	bl m4aSongNumStart
_08019164:
	ldr r3, _08019188 @ =0x02031520
	ldr r1, _0801918C @ =0x0200B134
	movs r0, #0xcd
	adds r0, r0, r1
	mov ip, r0
	ldrb r0, [r0]
	movs r2, #0
	strb r0, [r3, #5]
	mov r0, ip
	strb r2, [r0]
	subs r1, #0x74
	ldrh r0, [r1, #0x30]
	adds r0, #1
	strh r0, [r1, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08019188: .4byte 0x02031520
_0801918C: .4byte 0x0200B134

	thumb_func_start sub_19190
sub_19190: @ 0x08019190
	push {r4, r5, lr}
	ldr r0, _080191A8 @ =0x020314E0
	ldr r2, [r0]
	ldrb r1, [r2, #0x1d]
	cmp r1, #1
	beq _080191C0
	cmp r1, #1
	bgt _080191AC
	cmp r1, #0
	beq _080191B2
	b _0801927C
	.align 2, 0
_080191A8: .4byte 0x020314E0
_080191AC:
	cmp r1, #2
	beq _08019274
	b _0801927C
_080191B2:
	movs r0, #1
	strb r0, [r2, #0x1d]
	ldr r0, _080191BC @ =gMain
	strb r1, [r0, #0xe]
	b _0801927C
	.align 2, 0
_080191BC: .4byte gMain
_080191C0:
	ldr r0, _080191D0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bhi _080191D4
	bl sub_4ACF0
	b _080191D8
	.align 2, 0
_080191D0: .4byte gMain
_080191D4:
	bl sub_4B000
_080191D8:
	ldr r3, _08019214 @ =gMain
	ldr r0, [r3, #0x54]
	ldr r1, _08019218 @ =0x02031520
	movs r4, #6
	ldrsh r2, [r1, r4]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r3, #0x54]
	cmp r1, r2
	bls _080191F0
	movs r0, #1
	strb r0, [r3, #0xe]
_080191F0:
	ldrb r0, [r3, #0x1c]
	cmp r0, #0
	beq _080191FA
	movs r0, #1
	strb r0, [r3, #0xe]
_080191FA:
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _0801927C
	ldrb r0, [r3, #4]
	cmp r0, #1
	bhi _0801921C
	bl sub_1D4D0
	movs r0, #0
	bl sub_31BE8
	b _08019224
	.align 2, 0
_08019214: .4byte gMain
_08019218: .4byte 0x02031520
_0801921C:
	cmp r0, #3
	bne _08019224
	bl sub_356A0
_08019224:
	ldr r4, _0801925C @ =gMain
	ldrb r1, [r4, #0xf]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	ldr r2, _08019260 @ =0x020314E0
	cmp r0, #0
	beq _08019248
	ldr r1, _08019264 @ =0x040000D4
	ldr r0, [r2]
	ldr r5, _08019268 @ =0x0000111A
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0801926C @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _08019270 @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08019248:
	ldr r0, [r2]
	strb r3, [r0, #0x1d]
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _0801927C
	movs r0, #1
	bl sub_4B408
	b _0801927C
	.align 2, 0
_0801925C: .4byte gMain
_08019260: .4byte 0x020314E0
_08019264: .4byte 0x040000D4
_08019268: .4byte 0x0000111A
_0801926C: .4byte 0x05000200
_08019270: .4byte 0x80000100
_08019274:
	ldr r1, _08019284 @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_0801927C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08019284: .4byte gMain

	thumb_func_start sub_19288
sub_19288: @ 0x08019288
	push {r4, r5, lr}
	ldr r1, _080192E0 @ =gMain
	adds r2, r1, #0
	adds r2, #0x36
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080192E4 @ =0x02031520
	ldrb r0, [r2, #5]
	ldr r4, _080192E8 @ =0x00000141
	adds r3, r1, r4
	strb r0, [r3]
	movs r3, #0
	adds r5, r1, #7
	adds r4, r2, #0
_080192A4:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r5
	adds r1, r0, r4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _080192A4
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r2, _080192E0 @ =gMain
	ldr r0, _080192E4 @ =0x02031520
	movs r3, #6
	ldrsh r1, [r0, r3]
	ldr r0, [r2, #0x54]
	cmp r0, r1
	bhs _080192EC
	movs r0, #1
	bl SetMainGameState
	b _080192F2
	.align 2, 0
_080192E0: .4byte gMain
_080192E4: .4byte 0x02031520
_080192E8: .4byte 0x00000141
_080192EC:
	movs r0, #9
	bl SetMainGameState
_080192F2:
	ldr r1, _08019300 @ =gMain
	movs r0, #0
	str r0, [r1, #0x54]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08019300: .4byte gMain

	thumb_func_start sub_19304
sub_19304: @ 0x08019304
	push {lr}
	ldr r0, _08019318 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bls _08019312
	bl sub_19734
_08019312:
	pop {r0}
	bx r0
	.align 2, 0
_08019318: .4byte gMain

	thumb_func_start sub_1931C
sub_1931C: @ 0x0801931C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	ldr r0, _080193BC @ =0x020314E0
	mov r8, r0
	ldr r1, [r0]
	mov sb, r1
	ldr r0, _080193C0 @ =0x000013BC
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r2, _080193C4 @ =0x086ACE8C
	adds r7, r0, r2
	ldrh r0, [r7]
	adds r0, #0x53
	lsls r0, r0, #0x10
	ldr r3, _080193C8 @ =0xFFFF0000
	ldr r2, _080193CC @ =0x02031520
	ldrh r1, [r2, #0x1c]
	ldrh r2, [r7, #2]
	adds r4, r1, r2
	lsls r4, r4, #0x10
	ldr r2, _080193D0 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrh r0, [r7, #4]
	adds r0, #0x53
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r6, r3
	orrs r6, r0
	ldrh r7, [r7, #6]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	ands r6, r2
	orrs r6, r1
	asrs r1, r1, #0x10
	mov r3, sl
	orrs r3, r4
	mov sl, r3
	asrs r4, r4, #0x10
	subs r1, r1, r4
	ldr r2, [sp]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	subs r0, r0, r2
	muls r1, r0, r1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	subs r1, r1, r2
	bl __divsi3
	ldr r3, [sp]
	asrs r1, r3, #0x10
	subs r4, r4, r1
	lsls r1, r4, #4
	subs r1, r1, r4
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	mov r2, r8
	ldr r3, _080193C4 @ =0x086ACE8C
	ldr r4, _080193CC @ =0x02031520
	cmp r0, #0
	blt _080193D8
	ldr r1, _080193D4 @ =0x000013C4
	add r1, sb
	movs r0, #1
	b _080193DE
	.align 2, 0
_080193BC: .4byte 0x020314E0
_080193C0: .4byte 0x000013BC
_080193C4: .4byte 0x086ACE8C
_080193C8: .4byte 0xFFFF0000
_080193CC: .4byte 0x02031520
_080193D0: .4byte 0x0000FFFF
_080193D4: .4byte 0x000013C4
_080193D8:
	ldr r1, _08019460 @ =0x000013C4
	add r1, sb
	movs r0, #0xff
_080193DE:
	strb r0, [r1]
	ldr r2, [r2]
	mov r8, r2
	ldr r0, _08019464 @ =0x000013C8
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r7, r0, r3
	ldrh r3, [r7]
	movs r0, #0x9c
	subs r3, r0, r3
	ldr r1, _08019468 @ =0xFFFF0000
	mov sb, r1
	ldrh r2, [r4, #0x1c]
	ldrh r1, [r7, #2]
	adds r4, r2, r1
	lsls r4, r4, #0x10
	ldr r5, _0801946C @ =0x0000FFFF
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	ands r6, r1
	orrs r6, r0
	ldrh r7, [r7, #6]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	ands r6, r5
	asrs r2, r2, #0x10
	asrs r4, r4, #0x10
	subs r2, r2, r4
	ldr r1, [sp]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	subs r0, r0, r3
	adds r1, r2, #0
	muls r1, r0, r1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	subs r1, r1, r3
	bl __divsi3
	ldr r2, [sp]
	asrs r1, r2, #0x10
	subs r4, r4, r1
	lsls r1, r4, #4
	subs r1, r1, r4
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _08019474
	ldr r1, _08019470 @ =0x000013D0
	add r1, r8
	movs r0, #1
	b _0801947A
	.align 2, 0
_08019460: .4byte 0x000013C4
_08019464: .4byte 0x000013C8
_08019468: .4byte 0xFFFF0000
_0801946C: .4byte 0x0000FFFF
_08019470: .4byte 0x000013D0
_08019474:
	ldr r1, _0801948C @ =0x000013D0
	add r1, r8
	movs r0, #0xff
_0801947A:
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801948C: .4byte 0x000013D0

	thumb_func_start sub_19490
sub_19490: @ 0x08019490
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080194DC @ =gMain
	ldrb r1, [r4, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080194A8
	bl sub_195C4
_080194A8:
	movs r3, #0
	ldr r0, _080194E0 @ =0x020314E0
	mov r8, r0
	ldr r1, _080194E4 @ =0x00000A28
	adds r1, r1, r4
	mov sb, r1
	ldr r7, _080194E8 @ =0x040000D4
	ldr r2, _080194EC @ =gOamBuffer
	mov ip, r2
_080194BA:
	mov r0, r8
	ldr r2, [r0]
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _080194F0 @ =0x000013BC
	adds r2, r2, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0xa
	ble _080194F4
	movs r0, #0xa
	b _080194FA
	.align 2, 0
_080194DC: .4byte gMain
_080194E0: .4byte 0x020314E0
_080194E4: .4byte 0x00000A28
_080194E8: .4byte 0x040000D4
_080194EC: .4byte gOamBuffer
_080194F0: .4byte 0x000013BC
_080194F4:
	cmp r0, #0
	bge _080194FC
	movs r0, #0
_080194FA:
	strb r0, [r2]
_080194FC:
	asrs r6, r3, #0x10
	movs r0, #0xb8
	muls r0, r6, r0
	mov r2, sb
	adds r5, r0, r2
	ldrh r0, [r5]
	cmp r0, #0
	beq _0801958A
	mov r0, r8
	ldr r4, [r0]
	lsls r3, r6, #1
	adds r0, r3, r6
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _080195A4 @ =0x000013BC
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	ldr r0, _080195A8 @ =0x086ACEF4
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldr r0, _080195AC @ =0x02031520
	adds r4, #0x5a
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	asrs r2, r2, #1
	lsls r2, r2, #9
	ldr r0, _080195B0 @ =0x083FE44C
	adds r2, r2, r0
	str r2, [r7]
	lsls r0, r6, #9
	ldr r2, _080195B4 @ =0x06010000
	adds r0, r0, r2
	str r0, [r7, #4]
	ldr r0, _080195B8 @ =0x80000100
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	adds r4, r5, #0
	adds r4, #8
	ldrh r3, [r5, #8]
	lsls r3, r3, #3
	add r3, ip
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	ldr r2, _080195BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _080195C0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r5, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
_0801958A:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080194BA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080195A4: .4byte 0x000013BC
_080195A8: .4byte 0x086ACEF4
_080195AC: .4byte 0x02031520
_080195B0: .4byte 0x083FE44C
_080195B4: .4byte 0x06010000
_080195B8: .4byte 0x80000100
_080195BC: .4byte 0x000001FF
_080195C0: .4byte 0xFFFFFE00

	thumb_func_start sub_195C4
sub_195C4: @ 0x080195C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08019630 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _08019634 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bl sub_1931C
	movs r3, #0
	adds r6, r4, #0
_080195DE:
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r7, _08019638 @ =0x000013BC
	adds r0, r0, r7
	ldr r1, [r6]
	adds r4, r1, r0
	ldrb r1, [r4]
	movs r0, #0
	strb r1, [r4, #1]
	strb r0, [r4, #2]
	ldr r5, [r6]
	adds r0, r5, #0
	adds r0, #0xe
	adds r0, r0, r2
	ldrb r2, [r0]
	mov r8, r3
	cmp r2, #0
	beq _0801963C
	movs r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _08019624
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08019624
	movs r0, #0x72
	bl m4aSongNumStart
_08019624:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #6]
	strb r1, [r4, #7]
	b _08019650
	.align 2, 0
_08019630: .4byte 0x020314E0
_08019634: .4byte 0x0000132C
_08019638: .4byte 0x000013BC
_0801963C:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bne _08019650
	ldrb r0, [r4, #7]
	cmp r0, #2
	bls _0801964C
	strb r2, [r4, #6]
_0801964C:
	adds r0, #1
	strb r0, [r4, #7]
_08019650:
	movs r5, #0
	movs r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _080196AC
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	beq _08019666
	movs r5, #1
	b _08019694
_08019666:
	ldr r2, [r6]
	adds r3, r2, #0
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _08019694
	adds r0, r2, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldr r7, _080196A8 @ =0x00001364
	adds r0, r2, r7
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r7, #2
	adds r0, r2, r7
	strh r1, [r0]
	strh r5, [r3]
	movs r0, #7
	bl sub_11B0
_08019694:
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #1
	strb r0, [r4, #2]
	ldrb r0, [r4]
	adds r0, #4
	b _080196FA
	.align 2, 0
_080196A8: .4byte 0x00001364
_080196AC:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _080196C8
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #6
	strb r0, [r4, #2]
	ldr r5, _080196C4 @ =0x0000FFFF
	b _080196F6
	.align 2, 0
_080196C4: .4byte 0x0000FFFF
_080196C8:
	ldr r2, [r6]
	adds r3, r2, #0
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080196F6
	adds r0, r2, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldr r7, _08019730 @ =0x00001364
	adds r0, r2, r7
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r7, #2
	adds r0, r2, r7
	strh r1, [r0]
	strh r5, [r3]
	movs r0, #7
	bl sub_11B0
_080196F6:
	ldrb r0, [r4]
	subs r0, #2
_080196FA:
	strb r0, [r4]
	movs r0, #3
	ldrsb r0, [r4, r0]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	muls r0, r1, r0
	movs r1, #0
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08019712
	strb r1, [r4, #4]
_08019712:
	strb r5, [r4, #3]
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08019724
	b _080195DE
_08019724:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019730: .4byte 0x00001364

	thumb_func_start sub_19734
sub_19734: @ 0x08019734
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #1
	mov sl, r0
	ldr r4, _08019780 @ =gMain
	ldrb r1, [r4, #0xf]
	ands r0, r1
	cmp r0, #0
	bne _08019750
	bl sub_19894
_08019750:
	movs r3, #0
	ldr r1, _08019784 @ =0x020314E0
	mov sb, r1
	ldr r2, _08019788 @ =0x040000D4
	mov ip, r2
	ldr r0, _0801978C @ =gOamBuffer
	mov r8, r0
_0801975E:
	mov r1, sb
	ldr r2, [r1]
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _08019790 @ =0x000013BC
	adds r2, r2, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r7, r3, #0
	cmp r0, #0xa
	ble _08019794
	movs r0, #0xa
	b _0801979A
	.align 2, 0
_08019780: .4byte gMain
_08019784: .4byte 0x020314E0
_08019788: .4byte 0x040000D4
_0801978C: .4byte gOamBuffer
_08019790: .4byte 0x000013BC
_08019794:
	cmp r0, #0
	bge _0801979C
	movs r0, #0
_0801979A:
	strb r0, [r2]
_0801979C:
	asrs r6, r7, #0x10
	movs r0, #0xb8
	muls r0, r6, r0
	ldr r1, _08019870 @ =0x0200B5E0
	adds r5, r0, r1
	ldrh r0, [r5]
	cmp r0, #0
	beq _08019850
	mov r2, sb
	ldr r4, [r2]
	lsls r3, r6, #1
	adds r0, r3, r6
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _08019874 @ =0x000013BC
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsrs r0, r2, #0x1f
	adds r2, r2, r0
	ldr r0, _08019878 @ =0x086ACEF4
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldr r0, _0801987C @ =0x02031520
	adds r4, #0x5a
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	asrs r2, r2, #1
	lsls r2, r2, #9
	ldr r0, _08019880 @ =0x083FE44C
	adds r2, r2, r0
	mov r0, ip
	str r2, [r0]
	lsls r0, r6, #9
	ldr r1, _08019884 @ =0x06010000
	adds r0, r0, r1
	mov r2, ip
	str r0, [r2, #4]
	ldr r0, _08019888 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #0xb4
	ble _08019808
	movs r0, #0xb4
	strh r0, [r5, #4]
_08019808:
	adds r4, r5, #0
	adds r4, #8
	ldrh r3, [r5, #8]
	lsls r3, r3, #3
	add r3, r8
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	ldr r2, _0801988C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08019890 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r5, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	add r1, r8
	mov r0, sl
	lsls r3, r0, #2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, #5]
_08019850:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r7, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08019860
	b _0801975E
_08019860:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019870: .4byte 0x0200B5E0
_08019874: .4byte 0x000013BC
_08019878: .4byte 0x086ACEF4
_0801987C: .4byte 0x02031520
_08019880: .4byte 0x083FE44C
_08019884: .4byte 0x06010000
_08019888: .4byte 0x80000100
_0801988C: .4byte 0x000001FF
_08019890: .4byte 0xFFFFFE00

	thumb_func_start sub_19894
sub_19894: @ 0x08019894
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08019914 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _08019918 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bl sub_1931C
	movs r3, #0
	adds r6, r4, #0
	mov r8, r3
_080198B2:
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r7, _0801991C @ =0x000013BC
	adds r0, r0, r7
	ldr r1, [r6]
	adds r4, r1, r0
	ldrb r0, [r4]
	strb r0, [r4, #1]
	mov r0, r8
	strb r0, [r4, #2]
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0xe
	adds r0, r0, r2
	ldrb r0, [r0]
	mov sb, r3
	cmp r0, #0
	beq _08019924
	ldr r0, _08019920 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _08019924
	movs r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _08019908
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08019908
	movs r0, #0x1a
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08019908
	movs r0, #0x72
	bl m4aSongNumStart
_08019908:
	movs r0, #1
	strb r0, [r4, #6]
	mov r1, r8
	strb r1, [r4, #7]
	b _0801993A
	.align 2, 0
_08019914: .4byte 0x020314E0
_08019918: .4byte 0x0000132C
_0801991C: .4byte 0x000013BC
_08019920: .4byte gMain
_08019924:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _0801993A
	ldrb r0, [r4, #7]
	cmp r0, #2
	bls _08019936
	mov r7, r8
	strb r7, [r4, #6]
_08019936:
	adds r0, #1
	strb r0, [r4, #7]
_0801993A:
	movs r5, #0
	movs r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _08019998
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	beq _08019950
	movs r5, #1
	b _0801997E
_08019950:
	ldr r2, [r6]
	adds r3, r2, #0
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _0801997E
	adds r0, r2, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldr r7, _08019994 @ =0x00001364
	adds r0, r2, r7
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r7, #2
	adds r0, r2, r7
	strh r1, [r0]
	strh r5, [r3]
	movs r0, #7
	bl sub_11B0
_0801997E:
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #1
	strb r0, [r4, #2]
	ldrb r0, [r4]
	adds r0, #4
	b _080199E6
	.align 2, 0
_08019994: .4byte 0x00001364
_08019998:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _080199B4
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #6
	strb r0, [r4, #2]
	ldr r5, _080199B0 @ =0x0000FFFF
	b _080199E2
	.align 2, 0
_080199B0: .4byte 0x0000FFFF
_080199B4:
	ldr r2, [r6]
	adds r3, r2, #0
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080199E2
	adds r0, r2, #0
	adds r0, #0x60
	ldrh r1, [r0]
	ldr r7, _08019A1C @ =0x00001364
	adds r0, r2, r7
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r7, #2
	adds r0, r2, r7
	strh r1, [r0]
	strh r5, [r3]
	movs r0, #7
	bl sub_11B0
_080199E2:
	ldrb r0, [r4]
	subs r0, #2
_080199E6:
	strb r0, [r4]
	movs r0, #3
	ldrsb r0, [r4, r0]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	muls r0, r1, r0
	movs r1, #0
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _080199FE
	strb r1, [r4, #4]
_080199FE:
	strb r5, [r4, #3]
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08019A10
	b _080198B2
_08019A10:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08019A1C: .4byte 0x00001364

	thumb_func_start sub_19A20
sub_19A20: @ 0x08019A20
	push {r4, r5, r6, lr}
	ldr r4, _08019AF0 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _08019AF4 @ =0x0000073D
	adds r0, r0, r1
	movs r6, #2
	strb r6, [r0]
	bl sub_1D5D8
	movs r0, #0
	bl sub_4E9F0
	bl sub_1DAD8
	bl sub_23954
	bl sub_239A4
	ldr r1, [r4]
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r1, r3
	movs r5, #0
	movs r0, #0x49
	strh r0, [r2]
	ldr r0, _08019AF8 @ =0x000002D6
	adds r2, r1, r0
	movs r0, #0x9a
	strh r0, [r2]
	ldr r2, _08019AFC @ =0x000002DA
	adds r1, r1, r2
	strb r5, [r1]
	bl sub_23E18
	bl sub_1DDDC
	ldr r0, [r4]
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08019B00 @ =0x00000171
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r3, #2
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	bl sub_1EC48
	bl sub_1F158
	ldr r0, [r4]
	ldr r2, _08019B04 @ =0x000001E5
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	movs r3, #0xf3
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #1
	strb r0, [r1]
	bl sub_1F2A4
	bl sub_21B0C
	bl sub_1F59C
	ldr r0, [r4]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r0, r2
	subs r2, #0xd8
	strh r2, [r1]
	movs r3, #0xed
	lsls r3, r3, #1
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _08019B08 @ =0x0000029F
	adds r0, r0, r1
	strb r6, [r0]
	bl sub_2C9A4
	ldr r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #3
	strh r2, [r1]
	ldr r3, _08019B0C @ =0x000002EE
	adds r0, r0, r3
	strh r2, [r0]
	bl sub_31B30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08019AF0: .4byte 0x020314E0
_08019AF4: .4byte 0x0000073D
_08019AF8: .4byte 0x000002D6
_08019AFC: .4byte 0x000002DA
_08019B00: .4byte 0x00000171
_08019B04: .4byte 0x000001E5
_08019B08: .4byte 0x0000029F
_08019B0C: .4byte 0x000002EE

	thumb_func_start sub_19B10
sub_19B10: @ 0x08019B10
	push {lr}
	bl sub_19B90
	bl sub_19E10
	ldr r0, _08019B54 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _08019B26
	bl sub_19F70
_08019B26:
	bl sub_19FA0
	ldr r0, _08019B58 @ =0x020314E0
	ldr r0, [r0]
	movs r2, #0xa7
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08019B50
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08019B50
	ldr r0, _08019B5C @ =0x02032EE0
	ldr r1, _08019B60 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_08019B50:
	pop {r0}
	bx r0
	.align 2, 0
_08019B54: .4byte gMain
_08019B58: .4byte 0x020314E0
_08019B5C: .4byte 0x02032EE0
_08019B60: .4byte 0x0000FFFF

	thumb_func_start sub_19B64
sub_19B64: @ 0x08019B64
	ldr r2, _08019B88 @ =0x020314E0
	ldr r3, [r2]
	movs r1, #2
	strb r1, [r3, #0x16]
	ldr r1, [r2]
	strb r0, [r1, #0x14]
	ldr r0, [r2]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08019B86
	ldr r0, _08019B8C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r0, #0
	strh r0, [r1]
_08019B86:
	bx lr
	.align 2, 0
_08019B88: .4byte 0x020314E0
_08019B8C: .4byte gMain

	thumb_func_start sub_19B90
sub_19B90: @ 0x08019B90
	push {r4, lr}
	ldr r4, _08019BA8 @ =0x020314E0
	ldr r2, [r4]
	movs r0, #0x16
	ldrsb r0, [r2, r0]
	cmp r0, #1
	beq _08019BD0
	cmp r0, #1
	bgt _08019BAC
	cmp r0, #0
	beq _08019BB2
	b _08019BFE
	.align 2, 0
_08019BA8: .4byte 0x020314E0
_08019BAC:
	cmp r0, #2
	beq _08019BE8
	b _08019BFE
_08019BB2:
	ldr r1, _08019BCC @ =0x086AD4C4
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, [r4]
	ldrb r0, [r1, #0x16]
	adds r0, #1
	strb r0, [r1, #0x16]
	b _08019BFE
	.align 2, 0
_08019BCC: .4byte 0x086AD4C4
_08019BD0:
	ldr r0, _08019BE4 @ =0x086AD4E8
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _08019BFE
	.align 2, 0
_08019BE4: .4byte 0x086AD4E8
_08019BE8:
	bl sub_19D04
	ldr r0, [r4]
	ldrb r1, [r0, #0x13]
	movs r2, #0
	strb r1, [r0, #0x15]
	ldr r1, [r4]
	ldrb r0, [r1, #0x14]
	strb r0, [r1, #0x13]
	ldr r0, [r4]
	strb r2, [r0, #0x16]
_08019BFE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_19C04
sub_19C04: @ 0x08019C04
	push {r4, r5, r6, lr}
	ldr r0, _08019C3C @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0x15
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08019C7A
	ldr r0, _08019C40 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08019C50
	ldr r2, _08019C44 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08019C48
	movs r0, #0x1c
	bl m4aSongNumStart
	b _08019C7A
	.align 2, 0
_08019C3C: .4byte 0x020314E0
_08019C40: .4byte gMain
_08019C44: .4byte 0x00000283
_08019C48:
	movs r0, #0x5b
	bl m4aSongNumStart
	b _08019C7A
_08019C50:
	ldr r4, _08019C70 @ =0x00000283
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08019C74
	movs r0, #0x20
	bl m4aSongNumStart
	b _08019C7A
	.align 2, 0
_08019C70: .4byte 0x00000283
_08019C74:
	movs r0, #0x5c
	bl m4aSongNumStart
_08019C7A:
	ldr r5, _08019CB8 @ =0x020314E0
	ldr r2, [r5]
	ldrb r0, [r2, #0x15]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08019CB2
	ldr r3, _08019CBC @ =0x0000073C
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r6, _08019CC0 @ =0x0000072E
	adds r0, r2, r6
	movs r4, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08019CC4 @ =0x0000073D
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r6, #1
	adds r0, r0, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
_08019CB2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08019CB8: .4byte 0x020314E0
_08019CBC: .4byte 0x0000073C
_08019CC0: .4byte 0x0000072E
_08019CC4: .4byte 0x0000073D

	thumb_func_start sub_19CC8
sub_19CC8: @ 0x08019CC8
	push {lr}
	ldr r0, _08019CEC @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08019CF0 @ =0x00000714
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08019CFE
	ldr r0, _08019CF4 @ =0x000006EE
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08019CF8
	subs r0, #1
	strh r0, [r1]
	b _08019CFE
	.align 2, 0
_08019CEC: .4byte 0x020314E0
_08019CF0: .4byte 0x00000714
_08019CF4: .4byte 0x000006EE
_08019CF8:
	movs r0, #2
	bl sub_19B64
_08019CFE:
	pop {r0}
	bx r0

	thumb_func_start sub_19D04
sub_19D04: @ 0x08019D04
	push {r4, r5, r6, lr}
	ldr r0, _08019D80 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bne _08019D20
	movs r0, #0x14
	ldrsb r0, [r1, r0]
	cmp r0, #2
	ble _08019D20
	movs r0, #0
	bl sub_21238
_08019D20:
	ldr r5, _08019D80 @ =0x020314E0
	ldr r2, [r5]
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _08019DFC
	movs r0, #0x14
	ldrsb r0, [r2, r0]
	cmp r0, #3
	bne _08019D5C
	ldr r3, _08019D84 @ =0x0000072E
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, _08019D88 @ =0x0000073C
	adds r0, r2, r4
	movs r4, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08019D8C @ =0x0000072F
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r6, _08019D90 @ =0x0000073D
	adds r0, r0, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
_08019D5C:
	ldr r4, [r5]
	movs r0, #0x14
	ldrsb r0, [r4, r0]
	cmp r0, #4
	bne _08019D94
	ldr r3, _08019D84 @ =0x0000072E
	adds r0, r4, r3
	ldrb r1, [r0]
	ldr r2, _08019D88 @ =0x0000073C
	adds r0, r4, r2
	movs r4, #0
	strb r1, [r0]
	ldr r0, [r5]
	subs r2, #0xd
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r6, _08019D90 @ =0x0000073D
	b _08019DEC
	.align 2, 0
_08019D80: .4byte 0x020314E0
_08019D84: .4byte 0x0000072E
_08019D88: .4byte 0x0000073C
_08019D8C: .4byte 0x0000072F
_08019D90: .4byte 0x0000073D
_08019D94:
	cmp r0, #6
	bne _08019DD0
	ldr r3, _08019DC0 @ =0x0000072F
	adds r0, r4, r3
	ldrb r2, [r0]
	ldr r1, _08019DC4 @ =0x0000073D
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r0, [r5]
	ldr r2, _08019DC8 @ =0x0000073C
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _08019DCC @ =0x0000072E
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r3
	strb r1, [r0]
	b _08019DFC
	.align 2, 0
_08019DC0: .4byte 0x0000072F
_08019DC4: .4byte 0x0000073D
_08019DC8: .4byte 0x0000073C
_08019DCC: .4byte 0x0000072E
_08019DD0:
	cmp r0, #3
	ble _08019DFC
	ldr r3, _08019E04 @ =0x0000072E
	adds r0, r4, r3
	ldrb r1, [r0]
	ldr r6, _08019E08 @ =0x0000073C
	adds r0, r4, r6
	movs r4, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08019E0C @ =0x0000072F
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r6, #1
_08019DEC:
	adds r0, r0, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
_08019DFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08019E04: .4byte 0x0000072E
_08019E08: .4byte 0x0000073C
_08019E0C: .4byte 0x0000072F

	thumb_func_start sub_19E10
sub_19E10: @ 0x08019E10
	push {r4, lr}
	bl sub_1A0F4
	bl sub_1DA74
	ldr r4, _08019EA4 @ =0x020314E0
	ldr r0, [r4]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08019E4E
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08019E4E
	bl sub_C00
	ldr r4, [r4]
	ldr r1, _08019EA8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #0x64
	bl __umodsi3
	adds r0, #1
	ldr r3, _08019EAC @ =0x0000029F
	adds r4, r4, r3
	strb r0, [r4]
_08019E4E:
	ldr r4, _08019EA4 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x6d
	bgt _08019E68
	bl sub_1D5D8
	bl sub_1DAD8
	bl sub_2C9A4
_08019E68:
	bl sub_2CA9C
	ldr r0, [r4]
	adds r0, #0x68
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa7
	bgt _08019E7C
	bl sub_239A4
_08019E7C:
	ldr r0, [r4]
	adds r0, #0x68
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xdb
	bgt _08019EBC
	bl sub_23E18
	ldr r0, [r4]
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08019EB0
	bl sub_1DC7C
	b _08019EB4
	.align 2, 0
_08019EA4: .4byte 0x020314E0
_08019EA8: .4byte gMain
_08019EAC: .4byte 0x0000029F
_08019EB0:
	bl sub_1EC48
_08019EB4:
	bl sub_1F158
	bl sub_1F59C
_08019EBC:
	bl sub_1F698
	ldr r4, _08019F64 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0x68
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x3f
	ble _08019ED6
	bl sub_1FA48
	bl sub_1FBC4
_08019ED6:
	ldr r0, [r4]
	adds r0, #0x68
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x73
	ble _08019EE6
	bl sub_2C538
_08019EE6:
	ldr r0, [r4]
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x82
	ble _08019EF6
	bl sub_201B8
_08019EF6:
	bl sub_2CE80
	ldr r0, [r4]
	adds r0, #0x68
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa8
	ble _08019F0A
	bl sub_2D104
_08019F0A:
	bl sub_203CC
	bl sub_21B0C
	bl sub_4E814
	bl sub_1D128
	bl sub_21D78
	bl sub_31B30
	ldr r0, [r4]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08019F38
	bl sub_225F0
_08019F38:
	bl sub_472E4
	ldr r2, [r4]
	ldr r0, _08019F68 @ =0x00001328
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08019F5C
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08019F5C
	ldr r3, _08019F6C @ =0x00001330
	adds r1, r2, r3
	adds r3, #4
	adds r0, r2, r3
	str r0, [r1]
_08019F5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08019F64: .4byte 0x020314E0
_08019F68: .4byte 0x00001328
_08019F6C: .4byte 0x00001330

	thumb_func_start sub_19F70
sub_19F70: @ 0x08019F70
	push {lr}
	bl sub_1DDDC
	bl sub_1A9E8
	bl sub_1F2A4
	bl sub_1FF0C
	ldr r0, _08019F9C @ =0x020314E0
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08019F96
	subs r0, #1
	strh r0, [r1]
_08019F96:
	pop {r0}
	bx r0
	.align 2, 0
_08019F9C: .4byte 0x020314E0

	thumb_func_start sub_19FA0
sub_19FA0: @ 0x08019FA0
	push {r4, r5, lr}
	ldr r0, _0801A0DC @ =0x020314E0
	ldr r2, [r0]
	ldrb r1, [r2, #4]
	adds r5, r0, #0
	cmp r1, #0
	beq _0801A038
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08019FE2
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	beq _08019FE2
	subs r3, #0x22
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08019FE2
	ldr r3, _0801A0E0 @ =0x0000061C
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08019FE2
	strb r0, [r1]
_08019FE2:
	ldr r0, [r5]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r4, #0
	ldrsb r4, [r1, r4]
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _0801A0E4 @ =0x00000712
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	adds r3, #6
	adds r1, r0, r3
	movs r4, #0
	ldrsb r4, [r1, r4]
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	adds r2, #7
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
_0801A038:
	ldr r1, [r5]
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0801A0D4
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801A076
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	beq _0801A076
	subs r3, #0x22
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801A076
	ldr r3, _0801A0E0 @ =0x0000061C
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801A076
	movs r0, #1
	strb r0, [r2]
_0801A076:
	ldr r0, [r5]
	ldr r2, _0801A0E8 @ =0x00000713
	adds r1, r0, r2
	movs r4, #0
	ldrsb r4, [r1, r4]
	subs r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _0801A0EC @ =0x00000711
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	subs r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	adds r3, #9
	adds r1, r0, r3
	movs r4, #0
	ldrsb r4, [r1, r4]
	subs r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r5]
	adds r2, #8
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801A0F0 @ =0x00000301
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
_0801A0D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A0DC: .4byte 0x020314E0
_0801A0E0: .4byte 0x0000061C
_0801A0E4: .4byte 0x00000712
_0801A0E8: .4byte 0x00000713
_0801A0EC: .4byte 0x00000711
_0801A0F0: .4byte 0x00000301

	thumb_func_start sub_1A0F4
sub_1A0F4: @ 0x0801A0F4
	push {r4, r5, r6, r7, lr}
	ldr r2, _0801A140 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0801A106
	b _0801A2B2
_0801A106:
	ldr r1, _0801A144 @ =0x020314E0
	ldr r0, [r1]
	ldr r6, _0801A148 @ =0x000005F7
	adds r0, r0, r6
	strb r4, [r0]
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0xfa
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r7, r1, #0
	cmp r5, #0
	beq _0801A1D4
	movs r0, #2
	strb r0, [r3, #0x1f]
	ldr r0, [r7]
	ldr r1, _0801A14C @ =0x000005FA
	adds r0, r0, r1
	strb r4, [r0]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r1, #0xea
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801A150
	subs r0, #1
	strh r0, [r1]
	b _0801A1C0
	.align 2, 0
_0801A140: .4byte gMain
_0801A144: .4byte 0x020314E0
_0801A148: .4byte 0x000005F7
_0801A14C: .4byte 0x000005FA
_0801A150:
	adds r1, r2, #0
	adds r1, #0xee
	ldrh r3, [r1]
	mov ip, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne _0801A16E
	adds r3, r2, #0
	adds r3, #0xec
	ldrh r0, [r3]
	adds r1, r0, #0
	cmp r1, #0
	bne _0801A1B4
	b _0801A1BA
_0801A16E:
	adds r0, r2, #0
	adds r0, #0x68
	movs r6, #0
	ldrsh r5, [r0, r6]
	movs r0, #0
	ldrsh r4, [r1, r0]
	adds r1, r5, r4
	adds r0, r2, #0
	adds r0, #0xe8
	movs r6, #0
	ldrsh r3, [r0, r6]
	cmp r1, r3
	bgt _0801A194
	adds r1, r2, #0
	adds r1, #0xe6
	ldrh r0, [r1]
	add r0, ip
	strh r0, [r1]
	b _0801A1C0
_0801A194:
	subs r0, r5, r4
	cmp r0, r3
	blt _0801A1A8
	adds r1, r2, #0
	adds r1, #0xe6
	ldrh r0, [r1]
	mov r2, ip
	subs r0, r0, r2
	strh r0, [r1]
	b _0801A1C0
_0801A1A8:
	adds r3, r2, #0
	adds r3, #0xec
	ldrh r0, [r3]
	adds r1, r0, #0
	cmp r1, #0
	beq _0801A1BA
_0801A1B4:
	subs r0, #1
	strh r0, [r3]
	b _0801A1C0
_0801A1BA:
	adds r0, r2, #0
	adds r0, #0xfa
	strb r1, [r0]
_0801A1C0:
	ldr r0, [r7]
	adds r0, #0xf2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801A2B2
	bl sub_1A2C0
	b _0801A2B2
_0801A1D4:
	adds r0, r3, #0
	adds r0, #0xee
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r3, #0
	adds r1, #0xe6
	cmp r0, #0
	beq _0801A1EC
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne _0801A216
_0801A1EC:
	movs r4, #0
	strh r5, [r1]
	strb r4, [r3, #0x1f]
	ldrb r1, [r2, #0xf]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xf]
	ldr r0, [r7]
	adds r0, r0, r6
	strb r4, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801A216
	ldr r5, _0801A2B8 @ =0x000005FA
	adds r0, r1, r5
	strb r4, [r0]
_0801A216:
	ldr r3, [r7]
	adds r1, r3, #0
	adds r1, #0xe6
	ldrh r4, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	ble _0801A264
	adds r0, r3, #0
	adds r0, #0xee
	ldrh r0, [r0]
	subs r0, r4, r0
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0801A2B2
	movs r0, #0
	strh r0, [r1]
	strb r4, [r3, #0x1f]
	ldrb r1, [r2, #0xf]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xf]
	ldr r0, [r7]
	ldr r1, _0801A2BC @ =0x000005F7
	adds r0, r0, r1
	strb r4, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801A264
	ldr r3, _0801A2B8 @ =0x000005FA
	adds r0, r1, r3
	strb r4, [r0]
_0801A264:
	ldr r3, [r7]
	adds r1, r3, #0
	adds r1, #0xe6
	ldrh r4, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0
	bge _0801A2B2
	adds r0, r3, #0
	adds r0, #0xee
	ldrh r0, [r0]
	adds r0, r4, r0
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0801A2B2
	movs r0, #0
	strh r0, [r1]
	strb r4, [r3, #0x1f]
	ldrb r1, [r2, #0xf]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xf]
	ldr r0, [r7]
	ldr r6, _0801A2BC @ =0x000005F7
	adds r0, r0, r6
	strb r4, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801A2B2
	ldr r2, _0801A2B8 @ =0x000005FA
	adds r0, r1, r2
	strb r4, [r0]
_0801A2B2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A2B8: .4byte 0x000005FA
_0801A2BC: .4byte 0x000005F7

	thumb_func_start sub_1A2C0
sub_1A2C0: @ 0x0801A2C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _0801A328 @ =0x020314E0
	ldr r4, [r2]
	adds r5, r4, #0
	adds r5, #0xf2
	movs r0, #0
	ldrsb r0, [r5, r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, _0801A32C @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x2c]
	mov r8, r0
	ldr r0, [r1, #0x4c]
	movs r7, #7
	ands r0, r7
	lsrs r3, r0, #2
	mov r6, r8
	ldrh r0, [r6]
	mov sb, r1
	cmp r0, #0
	bne _0801A2FC
	b _0801A974
_0801A2FC:
	movs r6, #0
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #2]
	movs r0, #0xc8
	strh r0, [r1, #4]
	movs r1, #0
	ldrsb r1, [r5, r1]
	cmp r1, #4
	bne _0801A3EC
	adds r0, r4, #0
	adds r0, #0xea
	ldrh r5, [r0]
	cmp r5, #0
	beq _0801A330
	movs r0, #0xb9
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2, #2]
	movs r0, #0x2c
	strh r0, [r2, #4]
	b _0801A8B8
	.align 2, 0
_0801A328: .4byte 0x020314E0
_0801A32C: .4byte gMain
_0801A330:
	adds r0, r4, #0
	adds r0, #0xe4
	strb r1, [r0]
	ldr r1, _0801A3AC @ =0x040000D4
	ldr r2, _0801A3B0 @ =0x086ACEF8
	ldr r3, _0801A3B4 @ =0x020314E0
	ldr r0, [r3]
	adds r0, #0xf2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0801A3B8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801A3BC @ =0x800012F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_2CD98
	ldr r4, _0801A3B4 @ =0x020314E0
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0xf4
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0
	ble _0801A3C0
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x77
	bne _0801A384
	bl m4aMPlayAllStop
	movs r0, #0x10
	bl m4aSongNumStart
_0801A384:
	ldr r0, _0801A3B4 @ =0x020314E0
	ldr r1, [r0]
	adds r1, #0xf6
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r0, r0, r3
	mov r4, r8
	strh r0, [r4, #2]
	movs r0, #0x2c
	strh r0, [r4, #4]
	b _0801A8B8
	.align 2, 0
_0801A3AC: .4byte 0x040000D4
_0801A3B0: .4byte 0x086ACEF8
_0801A3B4: .4byte 0x020314E0
_0801A3B8: .4byte 0x06015800
_0801A3BC: .4byte 0x800012F0
_0801A3C0:
	ldr r0, _0801A3E4 @ =0x0000FF92
	mov r7, r8
	strh r0, [r7, #2]
	movs r0, #0x2c
	strh r0, [r7, #4]
	mov r1, sb
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x2c]
	strh r5, [r0]
	adds r0, r3, #0
	adds r0, #0xf2
	strb r6, [r0]
	ldr r2, _0801A3E8 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0xe4
	strb r6, [r0]
	b _0801A8B8
	.align 2, 0
_0801A3E4: .4byte 0x0000FF92
_0801A3E8: .4byte 0x020314E0
_0801A3EC:
	adds r0, r4, #0
	adds r0, #0xe4
	movs r4, #4
	mov sl, r4
	mov r5, sl
	strb r5, [r0]
	ldr r6, _0801A4D8 @ =0x040000D4
	ldr r1, _0801A4DC @ =0x086ACEF8
	ldr r2, _0801A4E0 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0xf2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #2
	adds r2, r2, r1
	adds r1, r3, #0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r6]
	ldr r0, _0801A4E4 @ =0x06015800
	str r0, [r6, #4]
	ldr r0, _0801A4E8 @ =0x800010E0
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	ldr r3, _0801A4E0 @ =0x020314E0
	ldr r5, [r3]
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bgt _0801A43A
	b _0801A6C8
_0801A43A:
	subs r0, r2, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801A44A
	b _0801A692
_0801A44A:
	cmp r0, #0x28
	bne _0801A456
	ldr r0, _0801A4EC @ =0x02032F20
	ldr r1, _0801A4F0 @ =0x0869F7C8
	bl MPlayStart
_0801A456:
	ldr r5, _0801A4E0 @ =0x020314E0
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0xf0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0801A474
	adds r1, #6
	ldrh r0, [r1]
	adds r0, #0xa0
	strh r0, [r1]
_0801A474:
	ldr r6, _0801A4E0 @ =0x020314E0
	ldr r2, [r6]
	adds r1, r2, #0
	adds r1, #0xf0
	ldrh r3, [r1]
	adds r0, r3, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0801A48C
	b _0801A67A
_0801A48C:
	cmp r3, #0x24
	bls _0801A492
	b _0801A5A0
_0801A492:
	mov r3, sb
	ldrh r0, [r3, #0x3c]
	strh r7, [r3, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0x23
	bls _0801A4A0
	b _0801A67A
_0801A4A0:
	adds r0, r2, #0
	adds r0, #0x25
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	bne _0801A4BA
	ldr r4, _0801A4F4 @ =0x000001A5
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801A4C8
_0801A4BA:
	cmp r1, #4
	bne _0801A500
	ldr r5, _0801A4F8 @ =0x000006DC
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #9
	bne _0801A500
_0801A4C8:
	ldr r0, _0801A4E0 @ =0x020314E0
	ldr r1, [r0]
	adds r1, #0x70
	movs r2, #0
	strb r2, [r1]
	ldr r2, _0801A4FC @ =0x02031520
	b _0801A51C
	.align 2, 0
_0801A4D8: .4byte 0x040000D4
_0801A4DC: .4byte 0x086ACEF8
_0801A4E0: .4byte 0x020314E0
_0801A4E4: .4byte 0x06015800
_0801A4E8: .4byte 0x800010E0
_0801A4EC: .4byte 0x02032F20
_0801A4F0: .4byte 0x0869F7C8
_0801A4F4: .4byte 0x000001A5
_0801A4F8: .4byte 0x000006DC
_0801A4FC: .4byte 0x02031520
_0801A500:
	ldr r3, _0801A534 @ =0x020314E0
	ldr r0, [r3]
	adds r0, #0x70
	movs r1, #1
	strb r1, [r0]
	ldr r1, _0801A538 @ =0x040000D4
	ldr r2, _0801A53C @ =0x02031520
	ldr r0, [r2, #0x34]
	str r0, [r1]
	ldr r0, _0801A540 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _0801A544 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801A51C:
	ldr r0, _0801A548 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0801A554
	ldr r1, _0801A538 @ =0x040000D4
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801A54C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801A550 @ =0x80000060
	b _0801A562
	.align 2, 0
_0801A534: .4byte 0x020314E0
_0801A538: .4byte 0x040000D4
_0801A53C: .4byte 0x02031520
_0801A540: .4byte 0x05000200
_0801A544: .4byte 0x80000010
_0801A548: .4byte gMain
_0801A54C: .4byte 0x05000240
_0801A550: .4byte 0x80000060
_0801A554:
	ldr r1, _0801A588 @ =0x040000D4
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801A58C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801A590 @ =0x80000070
_0801A562:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801A588 @ =0x040000D4
	ldr r0, [r2, #0x34]
	movs r6, #0xa0
	lsls r6, r6, #1
	adds r0, r0, r6
	str r0, [r1]
	ldr r0, _0801A594 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801A598 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r7, _0801A59C @ =0x020314E0
	ldr r0, [r7]
	adds r0, #0x6f
	movs r1, #2
	b _0801A678
	.align 2, 0
_0801A588: .4byte 0x040000D4
_0801A58C: .4byte 0x05000240
_0801A590: .4byte 0x80000070
_0801A594: .4byte 0x05000340
_0801A598: .4byte 0x80000030
_0801A59C: .4byte 0x020314E0
_0801A5A0:
	mov r3, sb
	ldrh r0, [r3, #0x3c]
	mov r4, sl
	strh r4, [r3, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0x27
	bhi _0801A67A
	adds r0, r2, #0
	adds r0, #0x25
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	bne _0801A5C8
	ldr r5, _0801A5E4 @ =0x000001A5
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801A5D6
_0801A5C8:
	cmp r1, #4
	bne _0801A5F4
	ldr r6, _0801A5E8 @ =0x000006DC
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #9
	bne _0801A5F4
_0801A5D6:
	ldr r0, _0801A5EC @ =0x020314E0
	ldr r1, [r0]
	adds r1, #0x70
	movs r2, #0
	strb r2, [r1]
	ldr r2, _0801A5F0 @ =0x02031520
	b _0801A610
	.align 2, 0
_0801A5E4: .4byte 0x000001A5
_0801A5E8: .4byte 0x000006DC
_0801A5EC: .4byte 0x020314E0
_0801A5F0: .4byte 0x02031520
_0801A5F4:
	ldr r3, _0801A628 @ =0x020314E0
	ldr r0, [r3]
	adds r0, #0x70
	movs r1, #1
	strb r1, [r0]
	ldr r1, _0801A62C @ =0x040000D4
	ldr r2, _0801A630 @ =0x02031520
	ldr r0, [r2, #0x30]
	str r0, [r1]
	ldr r0, _0801A634 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _0801A638 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801A610:
	ldr r0, _0801A63C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0801A648
	ldr r1, _0801A62C @ =0x040000D4
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801A640 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801A644 @ =0x80000060
	b _0801A656
	.align 2, 0
_0801A628: .4byte 0x020314E0
_0801A62C: .4byte 0x040000D4
_0801A630: .4byte 0x02031520
_0801A634: .4byte 0x05000200
_0801A638: .4byte 0x80000010
_0801A63C: .4byte gMain
_0801A640: .4byte 0x05000240
_0801A644: .4byte 0x80000060
_0801A648:
	ldr r1, _0801A6B0 @ =0x040000D4
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801A6B4 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801A6B8 @ =0x80000070
_0801A656:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801A6B0 @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r0, r7
	str r0, [r1]
	ldr r0, _0801A6BC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801A6C0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801A6C4 @ =0x020314E0
	ldr r0, [r1]
	adds r0, #0x6f
	movs r1, #1
_0801A678:
	strb r1, [r0]
_0801A67A:
	ldr r2, _0801A6C4 @ =0x020314E0
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0xf0
	ldrh r2, [r0]
	cmp r2, #0
	bne _0801A692
	adds r0, #6
	strh r2, [r0]
	adds r1, #0xf8
	movs r0, #0x3c
	strh r0, [r1]
_0801A692:
	ldr r3, _0801A6C4 @ =0x020314E0
	ldr r0, [r3]
	adds r0, #0xf6
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x7f
	mov r5, r8
	strh r0, [r5, #2]
	movs r0, #0x2c
	strh r0, [r5, #4]
	b _0801A8B8
	.align 2, 0
_0801A6B0: .4byte 0x040000D4
_0801A6B4: .4byte 0x05000240
_0801A6B8: .4byte 0x80000070
_0801A6BC: .4byte 0x05000340
_0801A6C0: .4byte 0x80000030
_0801A6C4: .4byte 0x020314E0
_0801A6C8:
	adds r7, r5, #0
	adds r7, #0xf0
	ldrh r0, [r7]
	cmp r0, #0x1d
	bls _0801A6D4
	b _0801A8B8
_0801A6D4:
	adds r1, r5, #0
	adds r1, #0xf6
	adds r4, r5, #0
	adds r4, #0xf8
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x7f
	mov r1, r8
	strh r0, [r1, #2]
	movs r0, #0x2c
	strh r0, [r1, #4]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	ldrh r0, [r4]
	subs r0, #0xa
	strh r0, [r4]
	ldrh r0, [r7]
	cmp r0, #0x18
	bls _0801A7CE
	adds r0, r5, #0
	adds r0, #0x25
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	bne _0801A724
	ldr r2, _0801A768 @ =0x000001A5
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801A7CE
_0801A724:
	cmp r1, #4
	bne _0801A732
	ldr r3, _0801A76C @ =0x000006DC
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #9
	beq _0801A7CE
_0801A732:
	mov r4, sb
	ldrh r0, [r4, #0x3c]
	mov r5, sl
	strh r5, [r4, #0x3c]
	ldrh r0, [r7]
	cmp r0, #0x19
	bls _0801A7BA
	ldr r1, _0801A770 @ =0x02031520
	ldr r3, [r1, #0x30]
	str r3, [r6]
	ldr r0, _0801A774 @ =0x05000200
	str r0, [r6, #4]
	ldr r0, _0801A778 @ =0x80000010
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	ldrb r0, [r4, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801A784
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r6]
	ldr r0, _0801A77C @ =0x05000240
	str r0, [r6, #4]
	ldr r0, _0801A780 @ =0x80000060
	b _0801A790
	.align 2, 0
_0801A768: .4byte 0x000001A5
_0801A76C: .4byte 0x000006DC
_0801A770: .4byte 0x02031520
_0801A774: .4byte 0x05000200
_0801A778: .4byte 0x80000010
_0801A77C: .4byte 0x05000240
_0801A780: .4byte 0x80000060
_0801A784:
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r6]
	ldr r0, _0801A850 @ =0x05000240
	str r0, [r6, #4]
	ldr r0, _0801A854 @ =0x80000070
_0801A790:
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	ldr r1, _0801A858 @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r6, #0xa0
	lsls r6, r6, #1
	adds r0, r0, r6
	str r0, [r1]
	ldr r0, _0801A85C @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801A860 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r7, _0801A864 @ =0x020314E0
	ldr r0, [r7]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0x70
	strb r1, [r0]
_0801A7BA:
	ldr r1, _0801A864 @ =0x020314E0
	ldr r0, [r1]
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0x1d
	bne _0801A7CE
	mov r2, sb
	ldrh r0, [r2, #0x3c]
	movs r0, #0
	strh r0, [r2, #0x3c]
_0801A7CE:
	ldr r3, _0801A864 @ =0x020314E0
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _0801A8B8
	mov r4, sb
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x2c]
	movs r1, #0
	movs r3, #0
	strh r3, [r0]
	adds r0, r2, #0
	adds r0, #0xf2
	strb r1, [r0]
	ldr r5, _0801A864 @ =0x020314E0
	ldr r0, [r5]
	adds r0, #0xe4
	strb r1, [r0]
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x25
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #3
	bne _0801A812
	ldr r6, _0801A868 @ =0x000001A5
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801A8B8
_0801A812:
	cmp r2, #4
	bne _0801A820
	ldr r7, _0801A86C @ =0x000006DC
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #9
	beq _0801A8B8
_0801A820:
	mov r1, sb
	ldrh r0, [r1, #0x3c]
	strh r3, [r1, #0x3c]
	ldr r3, _0801A858 @ =0x040000D4
	ldr r1, _0801A870 @ =0x02031520
	ldr r4, [r1, #0x2c]
	str r4, [r3]
	ldr r0, _0801A874 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801A878 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov r2, sb
	ldrb r0, [r2, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801A880
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801A850 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801A87C @ =0x80000060
	b _0801A88C
	.align 2, 0
_0801A850: .4byte 0x05000240
_0801A854: .4byte 0x80000070
_0801A858: .4byte 0x040000D4
_0801A85C: .4byte 0x05000340
_0801A860: .4byte 0x80000030
_0801A864: .4byte 0x020314E0
_0801A868: .4byte 0x000001A5
_0801A86C: .4byte 0x000006DC
_0801A870: .4byte 0x02031520
_0801A874: .4byte 0x05000200
_0801A878: .4byte 0x80000010
_0801A87C: .4byte 0x80000060
_0801A880:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801A94C @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801A950 @ =0x80000070
_0801A88C:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801A954 @ =0x040000D4
	ldr r0, [r2, #0x2c]
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0801A958 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801A95C @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, _0801A960 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x70
	movs r1, #1
	strb r1, [r0]
_0801A8B8:
	movs r2, #0
	ldr r5, [sp]
	lsls r1, r5, #0x10
	ldr r6, _0801A964 @ =gOamBuffer
	mov ip, r6
	ldr r7, _0801A968 @ =0x086B4568
	mov sl, r7
	asrs r1, r1, #0x10
	movs r0, #0x5a
	adds r6, r1, #0
	muls r6, r0, r6
	ldr r0, _0801A96C @ =0xFFFFFE00
	mov sb, r0
_0801A8D2:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, r8
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	add r1, sl
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	mov r7, r8
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r7, _0801A970 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ldrh r5, [r2, #2]
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r7, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xe
	ble _0801A8D2
	b _0801A97A
	.align 2, 0
_0801A94C: .4byte 0x05000240
_0801A950: .4byte 0x80000070
_0801A954: .4byte 0x040000D4
_0801A958: .4byte 0x05000340
_0801A95C: .4byte 0x80000030
_0801A960: .4byte 0x020314E0
_0801A964: .4byte gOamBuffer
_0801A968: .4byte 0x086B4568
_0801A96C: .4byte 0xFFFFFE00
_0801A970: .4byte 0x000001FF
_0801A974:
	movs r0, #1
	mov r3, r8
	strh r0, [r3]
_0801A97A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_1A98C
sub_1A98C: @ 0x0801A98C
	push {lr}
	ldr r0, _0801A9B0 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _0801A9E0
	ldr r0, _0801A9B4 @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801A9C8
	cmp r0, #2
	bgt _0801A9B8
	cmp r0, #1
	beq _0801A9C2
	b _0801A9D8
	.align 2, 0
_0801A9B0: .4byte gMain
_0801A9B4: .4byte 0x020314E0
_0801A9B8:
	cmp r0, #3
	beq _0801A9CE
	cmp r0, #4
	beq _0801A9D4
	b _0801A9D8
_0801A9C2:
	bl sub_1AA38
	b _0801A9D8
_0801A9C8:
	bl sub_1AD84
	b _0801A9D8
_0801A9CE:
	bl sub_1AF84
	b _0801A9D8
_0801A9D4:
	bl sub_1C560
_0801A9D8:
	ldr r0, _0801A9E4 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0x3c
	strh r0, [r1, #0x26]
_0801A9E0:
	pop {r0}
	bx r0
	.align 2, 0
_0801A9E4: .4byte 0x020314E0

	thumb_func_start sub_1A9E8
sub_1A9E8: @ 0x0801A9E8
	push {lr}
	ldr r2, _0801AA10 @ =0x020314E0
	ldr r1, [r2]
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _0801A9F8
	subs r0, #1
	strh r0, [r1, #0x26]
_0801A9F8:
	ldr r0, [r2]
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801AA24
	cmp r0, #2
	bgt _0801AA14
	cmp r0, #1
	beq _0801AA1E
	b _0801AA34
	.align 2, 0
_0801AA10: .4byte 0x020314E0
_0801AA14:
	cmp r0, #3
	beq _0801AA2A
	cmp r0, #4
	beq _0801AA30
	b _0801AA34
_0801AA1E:
	bl sub_1AAA0
	b _0801AA34
_0801AA24:
	bl sub_1ADF4
	b _0801AA34
_0801AA2A:
	bl sub_1AFD4
	b _0801AA34
_0801AA30:
	bl sub_1C5AC
_0801AA34:
	pop {r0}
	bx r0

	thumb_func_start sub_1AA38
sub_1AA38: @ 0x0801AA38
	push {r4, lr}
	ldr r4, _0801AA88 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _0801AA8C @ =0x0000072F
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _0801AA52
	movs r0, #4
	bl sub_19B64
_0801AA52:
	ldr r0, [r4]
	ldr r2, _0801AA90 @ =0x000005FC
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0
	strh r3, [r1]
	ldr r1, _0801AA94 @ =0x000005FB
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r4]
	ldr r2, _0801AA98 @ =0x000005FE
	adds r0, r1, r2
	strh r3, [r0]
	movs r0, #0x71
	strh r0, [r1, #0x28]
	movs r0, #0xce
	bl m4aSongNumStart
	ldr r1, [r4]
	ldr r0, _0801AA9C @ =0x0000C350
	str r0, [r1, #0x3c]
	movs r0, #8
	bl sub_11B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AA88: .4byte 0x020314E0
_0801AA8C: .4byte 0x0000072F
_0801AA90: .4byte 0x000005FC
_0801AA94: .4byte 0x000005FB
_0801AA98: .4byte 0x000005FE
_0801AA9C: .4byte 0x0000C350

	thumb_func_start sub_1AAA0
sub_1AAA0: @ 0x0801AAA0
	push {r4, r5, r6, lr}
	ldr r6, _0801AB04 @ =0x020314E0
	ldr r0, [r6]
	mov ip, r0
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0801AAB0
	b _0801AD3C
_0801AAB0:
	subs r0, #1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bls _0801AB64
	ldr r0, _0801AB08 @ =0x000005F7
	add r0, ip
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	strb r1, [r0, #0x1f]
	ldr r3, [r6]
	ldr r5, _0801AB0C @ =0x0000132C
	adds r2, r3, r5
	ldr r0, [r2]
	strh r4, [r0, #0x30]
	ldr r0, [r2]
	strh r4, [r0, #0x32]
	ldr r0, [r2]
	strh r4, [r0, #6]
	ldrh r0, [r3, #0x28]
	cmp r0, #0x6c
	bls _0801AB38
	ldr r2, _0801AB10 @ =0x000005FA
	adds r0, r3, r2
	strb r1, [r0]
	ldr r2, [r6]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x6e
	bls _0801AB14
	adds r2, r2, r5
	ldr r1, [r2]
	movs r0, #0xc3
	strh r0, [r1, #0x10]
	ldr r1, [r2]
	movs r0, #0xde
	b _0801AB20
	.align 2, 0
_0801AB04: .4byte 0x020314E0
_0801AB08: .4byte 0x000005F7
_0801AB0C: .4byte 0x0000132C
_0801AB10: .4byte 0x000005FA
_0801AB14:
	adds r2, r2, r5
	ldr r1, [r2]
	movs r0, #0xc4
	strh r0, [r1, #0x10]
	ldr r1, [r2]
	movs r0, #0xdd
_0801AB20:
	strh r0, [r1, #0x12]
	ldr r0, _0801AB34 @ =0x020314E0
	ldr r0, [r0]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	b _0801ACFA
	.align 2, 0
_0801AB34: .4byte 0x020314E0
_0801AB38:
	cmp r0, #0x68
	bls _0801AB52
	ldr r1, [r2]
	movs r0, #0xc5
	strh r0, [r1, #0x10]
	ldr r1, [r2]
	movs r0, #0xdb
	strh r0, [r1, #0x12]
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r0, #7
	b _0801ACF8
_0801AB52:
	ldr r0, [r2]
	strb r1, [r0]
	ldr r0, [r6]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	b _0801ACFA
_0801AB64:
	cmp r0, #0x14
	bls _0801ABFE
	cmp r0, #0x4d
	bls _0801AB9C
	movs r0, #0xbd
	lsls r0, r0, #2
	add r0, ip
	movs r1, #9
	strb r1, [r0]
	ldr r2, [r6]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x4f
	bls _0801AB80
	b _0801ACFA
_0801AB80:
	ldr r3, _0801AB98 @ =0x000002F6
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, #0
	bne _0801AB8C
	b _0801ACFA
_0801AB8C:
	subs r0, #1
	strh r0, [r1]
	ldrh r0, [r2, #0x28]
	adds r0, #1
	strh r0, [r2, #0x28]
	b _0801ACFA
	.align 2, 0
_0801AB98: .4byte 0x000002F6
_0801AB9C:
	cmp r0, #0x48
	bls _0801ABAA
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xa
	b _0801ACF8
_0801ABAA:
	cmp r0, #0x43
	bls _0801ABB8
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xb
	b _0801ACF8
_0801ABB8:
	cmp r0, #0x2c
	bls _0801ABC6
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xc
	b _0801ACF8
_0801ABC6:
	cmp r0, #0x26
	bls _0801ABD4
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xd
	b _0801ACF8
_0801ABD4:
	cmp r0, #0x1c
	bls _0801ABE2
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xe
	b _0801ACF8
_0801ABE2:
	cmp r0, #0x17
	bls _0801ABF0
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0xf
	b _0801ACF8
_0801ABF0:
	ldr r0, [r6]
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0x10
	strb r1, [r0]
	b _0801ACFA
_0801ABFE:
	cmp r0, #0x12
	bls _0801AC28
	ldr r1, _0801AC24 @ =0x0000132C
	add r1, ip
	ldr r2, [r1]
	movs r0, #0xc1
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0xe2
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	strb r3, [r0]
	ldr r0, [r6]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0x11
	strb r1, [r0]
	b _0801ACFA
	.align 2, 0
_0801AC24: .4byte 0x0000132C
_0801AC28:
	cmp r0, #0x10
	bls _0801AC9C
	mov r2, ip
	strb r3, [r2, #0x1f]
	ldr r0, [r6]
	ldr r2, _0801AC8C @ =0x000005FE
	adds r1, r0, r2
	strh r4, [r1]
	ldr r1, _0801AC90 @ =0x000005FB
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	subs r2, #4
	adds r0, r0, r2
	strb r3, [r0]
	ldr r3, [r6]
	ldr r0, _0801AC94 @ =0x0000132C
	adds r1, r3, r0
	ldr r0, [r1]
	strh r4, [r0, #6]
	ldr r2, [r1]
	ldr r0, _0801AC98 @ =0x0000FF56
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	movs r0, #0xdc
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	movs r0, #0xbe
	strh r0, [r2, #0x10]
	ldr r1, [r1]
	movs r0, #0xe8
	strh r0, [r1, #0x12]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r3, r3, r1
	movs r0, #0x12
	strb r0, [r3]
	ldr r0, [r6]
	ldrh r0, [r0, #0x28]
	cmp r0, #0x12
	bne _0801ACFA
	movs r0, #0xc2
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	b _0801ACFA
	.align 2, 0
_0801AC8C: .4byte 0x000005FE
_0801AC90: .4byte 0x000005FB
_0801AC94: .4byte 0x0000132C
_0801AC98: .4byte 0x0000FF56
_0801AC9C:
	cmp r0, #0xc
	bls _0801ACB8
	ldr r0, _0801ACB4 @ =0x0000132C
	add r0, ip
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0x13
	b _0801ACF8
	.align 2, 0
_0801ACB4: .4byte 0x0000132C
_0801ACB8:
	cmp r0, #8
	bls _0801ACD4
	ldr r0, _0801ACD0 @ =0x0000132C
	add r0, ip
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0x14
	b _0801ACF8
	.align 2, 0
_0801ACD0: .4byte 0x0000132C
_0801ACD4:
	cmp r0, #4
	bls _0801ACF0
	ldr r0, _0801ACEC @ =0x0000132C
	add r0, ip
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0x15
	b _0801ACF8
	.align 2, 0
_0801ACEC: .4byte 0x0000132C
_0801ACF0:
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0x16
_0801ACF8:
	strb r0, [r1]
_0801ACFA:
	ldr r0, _0801AD34 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801AD38 @ =0x0000132C
	adds r2, r2, r3
	ldr r1, [r2]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r2]
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r1, [r2]
	ldr r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	ldr r1, [r2]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	b _0801AD74
	.align 2, 0
_0801AD34: .4byte 0x020314E0
_0801AD38: .4byte 0x0000132C
_0801AD3C:
	movs r3, #0
	movs r0, #0x1e
	mov r4, ip
	strh r0, [r4, #0x26]
	ldr r2, _0801AD7C @ =0x0000132C
	add r2, ip
	ldr r1, [r2]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r2]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	ldr r0, [r6]
	ldr r4, _0801AD80 @ =0x000005F7
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r6]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r3, [r0]
_0801AD74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801AD7C: .4byte 0x0000132C
_0801AD80: .4byte 0x000005F7

	thumb_func_start sub_1AD84
sub_1AD84: @ 0x0801AD84
	push {r4, lr}
	ldr r4, _0801ADB4 @ =0x020314E0
	ldr r1, [r4]
	ldr r0, _0801ADB8 @ =0x000186A0
	str r0, [r1, #0x3c]
	ldr r0, _0801ADBC @ =0x000002DA
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #3
	bne _0801ADC0
	movs r0, #4
	strb r0, [r2]
	movs r0, #0xb7
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	movs r0, #0xfa
	lsls r0, r0, #1
	b _0801ADD8
	.align 2, 0
_0801ADB4: .4byte 0x020314E0
_0801ADB8: .4byte 0x000186A0
_0801ADBC: .4byte 0x000002DA
_0801ADC0:
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801ADD6
	movs r0, #0x96
	lsls r0, r0, #1
	b _0801ADD8
_0801ADD6:
	movs r0, #0x78
_0801ADD8:
	strh r0, [r1, #0x28]
	ldr r0, _0801ADEC @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _0801ADF0 @ =0x000005F7
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801ADEC: .4byte 0x020314E0
_0801ADF0: .4byte 0x000005F7

	thumb_func_start sub_1ADF4
sub_1ADF4: @ 0x0801ADF4
	push {r4, r5, r6, lr}
	ldr r5, _0801AE7C @ =0x020314E0
	ldr r0, [r5]
	ldrh r4, [r0, #0x28]
	cmp r4, #0
	beq _0801AEE0
	ldr r1, _0801AE80 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r5]
	strb r2, [r0, #0x1f]
	ldr r5, [r5]
	mov ip, r5
	ldrh r0, [r5, #0x28]
	subs r0, #1
	strh r0, [r5, #0x28]
	add r1, ip
	ldr r0, [r1]
	strh r3, [r0, #0x30]
	ldr r0, [r1]
	strh r3, [r0, #0x32]
	ldr r2, [r1]
	movs r0, #0x58
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0x94
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	strh r3, [r0, #6]
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r1, [r1]
	movs r4, #0x12
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	movs r0, #0xb4
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801AE5A
	b _0801AF78
_0801AE5A:
	ldrh r1, [r5, #0x28]
	adds r0, r1, #0
	cmp r0, #0xc8
	bls _0801AE64
	b _0801AF78
_0801AE64:
	cmp r0, #0xc8
	bne _0801AEA8
	mov r0, ip
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801AE84
	adds r0, r1, #1
	mov r1, ip
	strh r0, [r1, #0x28]
	b _0801AECA
	.align 2, 0
_0801AE7C: .4byte 0x020314E0
_0801AE80: .4byte 0x0000132C
_0801AE84:
	mov r2, ip
	ldr r0, [r2, #0x48]
	cmp r0, #0
	beq _0801AEA2
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801AEA2
	bl sub_22978
	b _0801AECA
_0801AEA2:
	bl sub_22C6C
	b _0801AECA
_0801AEA8:
	mov r3, ip
	ldr r0, [r3, #0x48]
	cmp r0, #0
	beq _0801AEC6
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801AEC6
	bl sub_22A30
	b _0801AECA
_0801AEC6:
	bl sub_22D54
_0801AECA:
	ldr r0, _0801AEDC @ =0x020314E0
	ldr r1, [r0]
	ldrh r0, [r1, #0x28]
	cmp r0, #9
	bhi _0801AF78
	adds r0, #1
	strh r0, [r1, #0x28]
	b _0801AF78
	.align 2, 0
_0801AEDC: .4byte 0x020314E0
_0801AEE0:
	ldr r1, _0801AF50 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, #0x25
	strb r4, [r0]
	ldr r3, [r5]
	adds r1, r3, r1
	ldr r2, [r1]
	movs r6, #0
	movs r0, #0x58
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0xa2
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	strh r4, [r0, #6]
	ldr r2, [r1]
	movs r4, #0x10
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r4, _0801AF54 @ =0x000005F7
	adds r3, r3, r4
	strb r6, [r3]
	ldr r1, [r5]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801AF60
	ldr r3, _0801AF58 @ =0x000002DA
	adds r1, r1, r3
	movs r0, #3
	strb r0, [r1]
	ldr r1, [r5]
	ldr r4, _0801AF5C @ =0x000002DE
	adds r2, r1, r4
	movs r0, #0x30
	strh r0, [r2]
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0x1e
	strh r0, [r1]
	b _0801AF78
	.align 2, 0
_0801AF50: .4byte 0x0000132C
_0801AF54: .4byte 0x000005F7
_0801AF58: .4byte 0x000002DA
_0801AF5C: .4byte 0x000002DE
_0801AF60:
	strb r6, [r1, #0x1f]
	ldr r1, [r5]
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	ldr r2, _0801AF80 @ =0x0000132C
	adds r1, r1, r2
	ldr r2, [r1]
	movs r0, #0x14
	strh r0, [r2, #0x30]
	ldr r1, [r1]
	movs r0, #0xc8
	strh r0, [r1, #0x32]
_0801AF78:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801AF80: .4byte 0x0000132C

	thumb_func_start sub_1AF84
sub_1AF84: @ 0x0801AF84
	push {r4, lr}
	ldr r0, _0801AFC4 @ =0x020314E0
	ldr r3, [r0]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	strh r2, [r0]
	movs r4, #0xdb
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r2, [r0]
	movs r0, #0xb4
	strh r0, [r3, #0x28]
	adds r4, #4
	adds r1, r3, r4
	strh r0, [r1]
	ldr r0, _0801AFC8 @ =0x0007A120
	str r0, [r3, #0x3c]
	ldr r0, _0801AFCC @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r2, [r0, #0x3c]
	ldr r0, _0801AFD0 @ =0x000005F7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AFC4: .4byte 0x020314E0
_0801AFC8: .4byte 0x0007A120
_0801AFCC: .4byte gMain
_0801AFD0: .4byte 0x000005F7

	thumb_func_start sub_1AFD4
sub_1AFD4: @ 0x0801AFD4
	push {r4, r5, r6, r7, lr}
	ldr r7, _0801B074 @ =0x020314E0
	ldr r2, [r7]
	ldrh r0, [r2, #0x28]
	adds r6, r0, #0
	adds r5, r7, #0
	cmp r6, #0x18
	bls _0801B080
	ldr r1, _0801B078 @ =0x0000132C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r7]
	strb r2, [r0, #0x1f]
	ldr r4, [r7]
	ldrh r0, [r4, #0x28]
	subs r0, #1
	strh r0, [r4, #0x28]
	adds r1, r4, r1
	ldr r0, [r1]
	strh r3, [r0, #0x30]
	ldr r0, [r1]
	strh r3, [r0, #0x32]
	ldr r2, [r1]
	movs r0, #0xdc
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0x62
	strh r0, [r2, #0x12]
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r2, [r1]
	movs r3, #0x12
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x2a]
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldrh r0, [r4, #0x28]
	cmp r0, #0x9b
	bls _0801B054
	adds r1, r0, #0
	subs r1, #0x9c
	cmp r1, #0
	bge _0801B04A
	adds r1, #7
_0801B04A:
	asrs r1, r1, #3
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0801B054:
	ldr r1, [r5]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x31
	bhi _0801B060
	adds r0, #1
	strh r0, [r1, #0x28]
_0801B060:
	ldr r0, [r5]
	ldr r1, _0801B07C @ =0x000001A5
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_1B140
	b _0801B12A
	.align 2, 0
_0801B074: .4byte 0x020314E0
_0801B078: .4byte 0x0000132C
_0801B07C: .4byte 0x000001A5
_0801B080:
	cmp r6, #0
	beq _0801B0A0
	subs r0, #1
	strh r0, [r2, #0x28]
	ldrh r1, [r2, #0x28]
	movs r0, #0x18
	subs r0, r0, r1
	cmp r0, #0
	bge _0801B094
	adds r0, #7
_0801B094:
	asrs r1, r0, #3
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	b _0801B12A
_0801B0A0:
	ldr r4, _0801B130 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	strb r6, [r0]
	ldr r0, [r7]
	strb r6, [r0, #0x1f]
	ldr r3, [r7]
	movs r5, #0
	movs r0, #0x3c
	strh r0, [r3, #0x26]
	adds r2, r3, r4
	ldr r1, [r2]
	movs r0, #0x60
	strh r0, [r1, #0x30]
	ldr r1, [r2]
	movs r0, #0xc0
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	movs r0, #0xdf
	strh r0, [r1, #0x10]
	ldr r1, [r2]
	movs r0, #0x63
	strh r0, [r1, #0x12]
	ldr r0, [r2]
	strh r6, [r0, #6]
	ldr r0, _0801B134 @ =0x000005F7
	adds r3, r3, r0
	strb r5, [r3]
	ldr r2, [r7]
	adds r4, r2, r4
	ldr r1, [r4]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	adds r2, #0x25
	strb r5, [r2]
	ldr r0, [r7]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0x13
	strb r1, [r0]
	movs r0, #0xc3
	bl m4aSongNumStart
	ldr r1, [r7]
	ldr r2, _0801B138 @ =0x0000072E
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0801B12A
	ldr r3, _0801B13C @ =0x00000281
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0801B12A
	movs r0, #6
	bl sub_19B64
_0801B12A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801B130: .4byte 0x0000132C
_0801B134: .4byte 0x000005F7
_0801B138: .4byte 0x0000072E
_0801B13C: .4byte 0x00000281

	thumb_func_start sub_1B140
sub_1B140: @ 0x0801B140
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r7, #0
	ldr r0, _0801B228 @ =gMain
	ldrb r0, [r0, #0xf]
	ldr r1, _0801B22C @ =0x020314E0
	mov r8, r1
	cmp r0, #0
	bne _0801B16A
	ldr r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801B16A
	subs r0, #1
	strh r0, [r1]
_0801B16A:
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	beq _0801B176
	bl sub_1BB68
_0801B176:
	ldr r4, _0801B22C @ =0x020314E0
	ldr r0, [r4]
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0801B1B8
	bl m4aMPlayAllStop
	ldr r0, [r4]
	ldr r2, _0801B230 @ =0x000006DE
	adds r1, r0, r2
	movs r2, #0
	strh r5, [r1]
	ldr r3, _0801B234 @ =0x000006DD
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0801B238 @ =0x00000252
	adds r0, r0, r2
	strh r5, [r0]
	ldr r0, _0801B228 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r5, [r0, #0x3c]
_0801B1B8:
	ldr r1, [r4]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x92
	bne _0801B1E6
	adds r1, #0xe4
	movs r0, #0x12
	strb r0, [r1]
	ldr r1, _0801B23C @ =0x040000D4
	ldr r0, _0801B240 @ =0x084F61EC
	str r0, [r1]
	ldr r0, _0801B244 @ =0x06015C00
	str r0, [r1, #4]
	ldr r0, _0801B248 @ =0x800004A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801B24C @ =0x081B45A4
	str r0, [r1]
	ldr r0, _0801B250 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0801B254 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801B1E6:
	ldr r0, [r4]
	adds r2, r0, r6
	ldrh r1, [r2]
	adds r0, r1, #0
	subs r0, #0x91
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r4
	cmp r0, #4
	bls _0801B1FC
	b _0801B332
_0801B1FC:
	cmp r1, #0x92
	bls _0801B2B8
	ldr r1, _0801B228 @ =gMain
	ldrh r0, [r1, #0x3c]
	movs r0, #4
	strh r0, [r1, #0x3c]
	ldrh r0, [r2]
	cmp r0, #0x94
	bls _0801B210
	b _0801B332
_0801B210:
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _0801B264
	ldr r1, _0801B23C @ =0x040000D4
	ldr r2, _0801B258 @ =0x02031520
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B25C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B260 @ =0x80000060
	b _0801B274
	.align 2, 0
_0801B228: .4byte gMain
_0801B22C: .4byte 0x020314E0
_0801B230: .4byte 0x000006DE
_0801B234: .4byte 0x000006DD
_0801B238: .4byte 0x00000252
_0801B23C: .4byte 0x040000D4
_0801B240: .4byte 0x084F61EC
_0801B244: .4byte 0x06015C00
_0801B248: .4byte 0x800004A0
_0801B24C: .4byte 0x081B45A4
_0801B250: .4byte 0x05000180
_0801B254: .4byte 0x80000010
_0801B258: .4byte 0x02031520
_0801B25C: .4byte 0x05000240
_0801B260: .4byte 0x80000060
_0801B264:
	ldr r1, _0801B29C @ =0x040000D4
	ldr r2, _0801B2A0 @ =0x02031520
	ldr r0, [r2, #0x30]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B2A4 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B2A8 @ =0x80000070
_0801B274:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801B29C @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0801B2AC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B2B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0801B2B4 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x6f
	movs r3, #0
	movs r1, #1
	b _0801B328
	.align 2, 0
_0801B29C: .4byte 0x040000D4
_0801B2A0: .4byte 0x02031520
_0801B2A4: .4byte 0x05000240
_0801B2A8: .4byte 0x80000070
_0801B2AC: .4byte 0x05000340
_0801B2B0: .4byte 0x80000030
_0801B2B4: .4byte 0x020314E0
_0801B2B8:
	ldr r1, _0801B2E0 @ =gMain
	ldrh r0, [r1, #0x3c]
	movs r0, #7
	strh r0, [r1, #0x3c]
	ldrh r0, [r2]
	cmp r0, #0x91
	bls _0801B2C8
	b _0801B44A
_0801B2C8:
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _0801B2F4
	ldr r1, _0801B2E4 @ =0x040000D4
	ldr r2, _0801B2E8 @ =0x02031520
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B2EC @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B2F0 @ =0x80000060
	b _0801B304
	.align 2, 0
_0801B2E0: .4byte gMain
_0801B2E4: .4byte 0x040000D4
_0801B2E8: .4byte 0x02031520
_0801B2EC: .4byte 0x05000240
_0801B2F0: .4byte 0x80000060
_0801B2F4:
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r2, _0801B400 @ =0x02031520
	ldr r0, [r2, #0x34]
	adds r0, #0x40
	str r0, [r1]
	ldr r0, _0801B404 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _0801B408 @ =0x80000070
_0801B304:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r0, [r2, #0x34]
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _0801B40C @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B410 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0801B414 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x6f
	movs r3, #0
	movs r1, #2
_0801B328:
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x70
	strb r3, [r0]
	mov r8, r2
_0801B332:
	mov r5, r8
	ldr r0, [r5]
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x91
	beq _0801B344
	b _0801B44A
_0801B344:
	movs r0, #0xb
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r5]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r3, [r5]
	ldr r2, _0801B418 @ =0x086AD2DE
	adds r1, r3, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r5, _0801B41C @ =0x000001A7
	adds r1, r3, r5
	strb r0, [r1]
	movs r0, #6
	movs r1, #0
	bl sub_1C7F4
	movs r0, #1
	bl sub_21FBC
	ldr r2, _0801B420 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x1c]
	movs r3, #1
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x20]
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x18]
	strh r3, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x24]
	strh r3, [r0]
	ldr r1, _0801B3FC @ =0x040000D4
	ldr r0, _0801B424 @ =0x081B8784
	str r0, [r1]
	ldr r0, _0801B428 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801B42C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801B430 @ =0x081B8984
	str r0, [r1]
	ldr r0, _0801B434 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801B438 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _0801B43C @ =0x000002EA
	adds r1, r2, r6
	movs r0, #0x50
	strh r0, [r1]
	strh r4, [r2, #0x2a]
	mov r1, r8
	ldr r0, [r1]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0xf
	strh r1, [r0]
	strh r3, [r2, #0x28]
	movs r0, #0x8f
	bl m4aSongNumStart
	mov r5, r8
	ldr r1, [r5]
	movs r6, #0xf1
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801B440
	movs r0, #0xd5
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	b _0801B448
	.align 2, 0
_0801B3FC: .4byte 0x040000D4
_0801B400: .4byte 0x02031520
_0801B404: .4byte 0x05000240
_0801B408: .4byte 0x80000070
_0801B40C: .4byte 0x05000340
_0801B410: .4byte 0x80000030
_0801B414: .4byte 0x020314E0
_0801B418: .4byte 0x086AD2DE
_0801B41C: .4byte 0x000001A7
_0801B420: .4byte gMain
_0801B424: .4byte 0x081B8784
_0801B428: .4byte 0x050003C0
_0801B42C: .4byte 0x80000010
_0801B430: .4byte 0x081B8984
_0801B434: .4byte 0x06002000
_0801B438: .4byte 0x80000620
_0801B43C: .4byte 0x000002EA
_0801B440:
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r0, #0
_0801B448:
	strb r0, [r1]
_0801B44A:
	mov r4, r8
	ldr r3, [r4]
	movs r5, #0xdd
	lsls r5, r5, #1
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0x90
	bls _0801B45C
	b _0801B6F2
_0801B45C:
	movs r6, #0xdc
	lsls r6, r6, #3
	adds r1, r3, r6
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B4D8 @ =0x000006C4
	adds r1, r3, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801B4DC @ =0x000006DB
	adds r0, r0, r1
	strb r2, [r0]
	movs r7, #0
	ldr r3, [r4]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0
	ble _0801B552
	subs r0, r1, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0801B540
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r1, r0, #3
	subs r1, r1, r0
	subs r4, #2
	adds r0, r3, r4
	strh r1, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0xf
	beq _0801B4B4
	b _0801B614
_0801B4B4:
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r1, r3, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0801B4F0
	ldr r1, _0801B4E0 @ =0x000005F6
	adds r0, r3, r1
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0801B4E4
	adds r0, r1, #0
	adds r0, #0xa
	b _0801B526
	.align 2, 0
_0801B4D8: .4byte 0x000006C4
_0801B4DC: .4byte 0x000006DB
_0801B4E0: .4byte 0x000005F6
_0801B4E4:
	ldr r4, _0801B4EC @ =0x000001A7
	adds r1, r3, r4
	movs r0, #0xc
	b _0801B52A
	.align 2, 0
_0801B4EC: .4byte 0x000001A7
_0801B4F0:
	cmp r0, #6
	bne _0801B518
	ldr r0, _0801B504 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801B50C
	ldr r5, _0801B508 @ =0x000001A7
	adds r1, r3, r5
	movs r0, #0x16
	b _0801B52A
	.align 2, 0
_0801B504: .4byte gMain
_0801B508: .4byte 0x000001A7
_0801B50C:
	ldr r6, _0801B514 @ =0x000001A7
	adds r1, r3, r6
	movs r0, #0x17
	b _0801B52A
	.align 2, 0
_0801B514: .4byte 0x000001A7
_0801B518:
	ldr r0, _0801B538 @ =0x086AD2DE
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
_0801B526:
	ldr r2, _0801B53C @ =0x000001A7
	adds r1, r3, r2
_0801B52A:
	strb r0, [r1]
	movs r0, #6
	movs r1, #0
	bl sub_1C7F4
	movs r7, #1
	b _0801B614
	.align 2, 0
_0801B538: .4byte 0x086AD2DE
_0801B53C: .4byte 0x000001A7
_0801B540:
	movs r4, #0
	ldrsh r1, [r2, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r5, #0xdb
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	b _0801B614
_0801B552:
	ldr r0, _0801B58C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801B5B2
	ldr r6, _0801B590 @ =0x000006DD
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801B5B2
	movs r0, #0x82
	bl m4aSongNumStart
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801B594
	subs r0, r2, #1
	b _0801B596
	.align 2, 0
_0801B58C: .4byte gMain
_0801B590: .4byte 0x000006DD
_0801B594:
	movs r0, #7
_0801B596:
	strb r0, [r1]
	ldr r2, _0801B5EC @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0x1e
	strh r1, [r0]
_0801B5B2:
	ldr r0, _0801B5F0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801B614
	ldr r5, _0801B5EC @ =0x020314E0
	ldr r0, [r5]
	ldr r6, _0801B5F4 @ =0x000006DD
	adds r0, r0, r6
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	bne _0801B614
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bgt _0801B5F8
	adds r0, r2, #1
	strb r0, [r1]
	b _0801B5FA
	.align 2, 0
_0801B5EC: .4byte 0x020314E0
_0801B5F0: .4byte gMain
_0801B5F4: .4byte 0x000006DD
_0801B5F8:
	strb r4, [r1]
_0801B5FA:
	ldr r2, _0801B63C @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0x1e
	strh r1, [r0]
_0801B614:
	adds r0, r7, #0
	bl sub_21FBC
	ldr r0, _0801B63C @ =0x020314E0
	ldr r1, [r0]
	movs r5, #0xd4
	lsls r5, r5, #1
	adds r0, r1, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0801B64A
	ldr r6, _0801B640 @ =0x000001A9
	adds r1, r1, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B644
	subs r0, #1
	strb r0, [r1]
	b _0801B662
	.align 2, 0
_0801B63C: .4byte 0x020314E0
_0801B640: .4byte 0x000001A9
_0801B644:
	movs r0, #7
	strb r0, [r1]
	b _0801B662
_0801B64A:
	ldr r0, _0801B65C @ =0x000001A9
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #6
	bhi _0801B660
	adds r0, #1
	strb r0, [r1]
	b _0801B662
	.align 2, 0
_0801B65C: .4byte 0x000001A9
_0801B660:
	strb r2, [r1]
_0801B662:
	ldr r1, _0801B6C0 @ =0x040000D4
	ldr r3, _0801B6C4 @ =0x086AD50C
	ldr r4, _0801B6C8 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801B6CC @ =0x000001A9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0801B6D0 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801B6D4 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0801B6D8 @ =gMain
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r1, #0x50
	subs r1, r1, r0
	ldr r5, _0801B6DC @ =0x000002EA
	adds r0, r3, r5
	strh r1, [r0]
	ldr r6, _0801B6E0 @ =0x00000252
	adds r2, r2, r6
	ldrh r0, [r2]
	mov r8, r4
	cmp r0, #0
	beq _0801B6E4
	ldrh r1, [r3, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _0801B6F2
	subs r0, r1, #1
	strh r0, [r3, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0801B6F2
	strh r0, [r3, #0x28]
	movs r0, #0x90
	strh r0, [r3, #0x26]
	b _0801B6F2
	.align 2, 0
_0801B6C0: .4byte 0x040000D4
_0801B6C4: .4byte 0x086AD50C
_0801B6C8: .4byte 0x020314E0
_0801B6CC: .4byte 0x000001A9
_0801B6D0: .4byte 0x06002000
_0801B6D4: .4byte 0x80000620
_0801B6D8: .4byte gMain
_0801B6DC: .4byte 0x000002EA
_0801B6E0: .4byte 0x00000252
_0801B6E4:
	ldrh r1, [r3, #0x2a]
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _0801B6F2
	adds r0, r1, #1
	strh r0, [r3, #0x2a]
_0801B6F2:
	mov r5, r8
	ldr r2, [r5]
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0801B706
	b _0801B85E
_0801B706:
	ldr r0, _0801B76C @ =gMain
	movs r3, #0x2a
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x13
	bgt _0801B714
	b _0801B85E
_0801B714:
	ldrh r1, [r3, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801B720
	b _0801B82C
_0801B720:
	ldr r4, _0801B770 @ =0x000006DD
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801B730
	b _0801B82C
_0801B730:
	ldr r5, _0801B774 @ =0x000001A7
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801B778 @ =0x086AD000
	adds r4, r0, r1
	ldr r1, _0801B77C @ =0x086AD2DE
	subs r6, #0x12
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _0801B784
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801B784
	ldr r3, _0801B780 @ =0x000003E7
	b _0801B7AC
	.align 2, 0
_0801B76C: .4byte gMain
_0801B770: .4byte 0x000006DD
_0801B774: .4byte 0x000001A7
_0801B778: .4byte 0x086AD000
_0801B77C: .4byte 0x086AD2DE
_0801B780: .4byte 0x000003E7
_0801B784:
	mov r5, r8
	ldr r2, [r5]
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _0801B7AA
	ldr r1, _0801B804 @ =0x000001AF
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r3, _0801B808 @ =0x000003E7
	cmp r0, #0
	bne _0801B7AC
_0801B7AA:
	ldrh r3, [r4, #6]
_0801B7AC:
	ldr r4, _0801B80C @ =0x020314E0
	ldr r2, [r4]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _0801B824
	ldr r6, _0801B810 @ =0x000006DD
	adds r1, r2, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r2, _0801B814 @ =0x000001A7
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r5, _0801B818 @ =0x000006DC
	adds r0, r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	movs r6, #0xc9
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrb r0, [r1]
	subs r0, r0, r3
	strb r0, [r1]
	bl m4aMPlayAllStop
	movs r0, #0x83
	bl m4aSongNumStart
	ldr r0, [r4]
	ldr r2, _0801B81C @ =0x000001AB
	adds r1, r0, r2
	movs r0, #0x13
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801B820 @ =0x00000376
	adds r0, r0, r3
	movs r1, #0x1e
	strh r1, [r0]
	b _0801B85E
	.align 2, 0
_0801B804: .4byte 0x000001AF
_0801B808: .4byte 0x000003E7
_0801B80C: .4byte 0x020314E0
_0801B810: .4byte 0x000006DD
_0801B814: .4byte 0x000001A7
_0801B818: .4byte 0x000006DC
_0801B81C: .4byte 0x000001AB
_0801B820: .4byte 0x00000376
_0801B824:
	movs r0, #0x8a
	bl m4aSongNumStart
	b _0801B85E
_0801B82C:
	ldrh r1, [r3, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801B85E
	ldr r0, _0801B928 @ =0x020314E0
	ldr r2, [r0]
	ldr r4, _0801B92C @ =0x000006DD
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801B870
	ldr r5, _0801B930 @ =0x00000252
	adds r0, r2, r5
	movs r1, #0x1e
	strh r1, [r0]
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r2, r6
	strh r1, [r0]
	movs r0, #0x66
	bl m4aSongNumStart
_0801B85E:
	ldr r0, _0801B928 @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _0801B92C @ =0x000006DD
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801B8B2
_0801B870:
	bl sub_2A354
	ldr r0, _0801B928 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801B934 @ =0x000006DE
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0xb3
	bne _0801B8B2
	ldr r4, _0801B930 @ =0x00000252
	adds r0, r2, r4
	movs r1, #0x1e
	strh r1, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r0, r2, r5
	strh r1, [r0]
	ldr r1, _0801B938 @ =0x086AD2DE
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _0801B8B2
	ldr r0, _0801B93C @ =0x000001AF
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
_0801B8B2:
	ldr r0, _0801B928 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801B930 @ =0x00000252
	adds r1, r2, r3
	ldrh r5, [r1]
	mov r8, r0
	cmp r5, #0
	bne _0801B8C6
	bl _0801C554
_0801B8C6:
	subs r0, r5, #1
	strh r0, [r1]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0xe
	bgt _0801B8DC
	movs r0, #0xf
	strh r0, [r1]
_0801B8DC:
	mov r6, r8
	ldr r0, [r6]
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #4
	bls _0801B8EA
	b _0801BA38
_0801B8EA:
	cmp r0, #1
	bls _0801B9A8
	ldr r5, _0801B940 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #4
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #3
	bls _0801B8FE
	b _0801BA38
_0801B8FE:
	ldr r3, _0801B944 @ =0x040000D4
	ldr r1, _0801B948 @ =0x02031520
	ldr r4, [r1, #0x30]
	str r4, [r3]
	ldr r0, _0801B94C @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801B950 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801B95C
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B954 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B958 @ =0x80000060
	b _0801B968
	.align 2, 0
_0801B928: .4byte 0x020314E0
_0801B92C: .4byte 0x000006DD
_0801B930: .4byte 0x00000252
_0801B934: .4byte 0x000006DE
_0801B938: .4byte 0x086AD2DE
_0801B93C: .4byte 0x000001AF
_0801B940: .4byte gMain
_0801B944: .4byte 0x040000D4
_0801B948: .4byte 0x02031520
_0801B94C: .4byte 0x05000200
_0801B950: .4byte 0x80000010
_0801B954: .4byte 0x05000240
_0801B958: .4byte 0x80000060
_0801B95C:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B994 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B998 @ =0x80000070
_0801B968:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801B99C @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0801B9A0 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801B9A4 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, r8
	ldr r0, [r3]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x70
	b _0801BA36
	.align 2, 0
_0801B994: .4byte 0x05000240
_0801B998: .4byte 0x80000070
_0801B99C: .4byte 0x040000D4
_0801B9A0: .4byte 0x05000340
_0801B9A4: .4byte 0x80000030
_0801B9A8:
	ldr r5, _0801B9E4 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #0
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801B9BA
	bl _0801C554
_0801B9BA:
	ldr r3, _0801B9E8 @ =0x040000D4
	ldr r1, _0801B9EC @ =0x02031520
	ldr r4, [r1, #0x2c]
	str r4, [r3]
	ldr r0, _0801B9F0 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801B9F4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801BA00
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801B9F8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801B9FC @ =0x80000060
	b _0801BA0C
	.align 2, 0
_0801B9E4: .4byte gMain
_0801B9E8: .4byte 0x040000D4
_0801B9EC: .4byte 0x02031520
_0801B9F0: .4byte 0x05000200
_0801B9F4: .4byte 0x80000010
_0801B9F8: .4byte 0x05000240
_0801B9FC: .4byte 0x80000060
_0801BA00:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801BA74 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801BA78 @ =0x80000070
_0801BA0C:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801BA7C @ =0x040000D4
	ldr r0, [r2, #0x2c]
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _0801BA80 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801BA84 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r5, r8
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x70
	movs r1, #1
_0801BA36:
	strb r1, [r0]
_0801BA38:
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _0801BA88 @ =0x00000252
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801BA4A
	bl _0801C554
_0801BA4A:
	ldr r0, _0801BA8C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801BA9C
	ldr r3, _0801BA90 @ =0x00000283
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801BA94
	movs r0, #0x1c
	bl m4aSongNumStart
	b _0801BAC6
	.align 2, 0
_0801BA74: .4byte 0x05000240
_0801BA78: .4byte 0x80000070
_0801BA7C: .4byte 0x040000D4
_0801BA80: .4byte 0x05000340
_0801BA84: .4byte 0x80000030
_0801BA88: .4byte 0x00000252
_0801BA8C: .4byte gMain
_0801BA90: .4byte 0x00000283
_0801BA94:
	movs r0, #0x5b
	bl m4aSongNumStart
	b _0801BAC6
_0801BA9C:
	ldr r4, _0801BABC @ =0x00000283
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801BAC0
	movs r0, #0x20
	bl m4aSongNumStart
	b _0801BAC6
	.align 2, 0
_0801BABC: .4byte 0x00000283
_0801BAC0:
	movs r0, #0x5c
	bl m4aSongNumStart
_0801BAC6:
	ldr r0, _0801BAE4 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801BAEC
	ldr r5, _0801BAE8 @ =0x000006DE
	adds r1, r1, r5
	movs r0, #0xaa
	strh r0, [r1]
	b _0801BAF0
	.align 2, 0
_0801BAE4: .4byte 0x020314E0
_0801BAE8: .4byte 0x000006DE
_0801BAEC:
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801BAF0:
	ldr r0, _0801BB08 @ =0x020314E0
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0801BB0C
	movs r0, #1
	movs r1, #0
	bl sub_1C7F4
	b _0801BB14
	.align 2, 0
_0801BB08: .4byte 0x020314E0
_0801BB0C:
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
_0801BB14:
	ldr r3, _0801BB54 @ =0x020314E0
	ldr r0, [r3]
	ldr r6, _0801BB58 @ =0x000006C4
	adds r0, r0, r6
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r3]
	ldr r1, _0801BB5C @ =0x000006DB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r3]
	ldr r4, _0801BB60 @ =0x000006DD
	adds r0, r0, r4
	strb r2, [r0]
	ldr r1, _0801BB64 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x1c]
	movs r4, #0
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x20]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x18]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x24]
	strh r2, [r0]
	ldr r0, [r3]
	bl _0801C528
	.align 2, 0
_0801BB54: .4byte 0x020314E0
_0801BB58: .4byte 0x000006C4
_0801BB5C: .4byte 0x000006DB
_0801BB60: .4byte 0x000006DD
_0801BB64: .4byte gMain

	thumb_func_start sub_1BB68
sub_1BB68: @ 0x0801BB68
	movs r5, #0
	mov r6, r8
	ldr r1, [r6]
	ldr r2, _0801BD0C @ =0x00000281
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0801BB80
	bl sub_1C544
_0801BB80:
	movs r6, #0xdd
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0801BC52
	bl m4aMPlayAllStop
	ldr r3, _0801BD10 @ =gMain
	ldrb r1, [r3, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r3, #0xf]
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r5, [r0]
	subs r0, #2
	strh r5, [r0]
	adds r0, #8
	strh r5, [r0]
	adds r1, #6
	movs r0, #3
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r4, [r4]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801BD14 @ =0x0000F63C
	strh r0, [r1]
	subs r1, #6
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf8
	strh r5, [r0]
	ldr r1, _0801BD18 @ =0x040000D4
	ldr r0, _0801BD1C @ =0x086ACEF8
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r0, _0801BD20 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801BD24 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801BD28 @ =0x086ACF18
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r0, _0801BD2C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801BD30 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r3, #0x38]
	movs r0, #0xce
	strh r0, [r3, #0x38]
	mov r0, r8
	ldr r3, [r0]
	adds r1, r3, r6
	movs r0, #0x94
	strh r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r2, [r0]
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xd3
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r3]
	subs r1, #0x24
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r2, [r0]
	mov r4, r8
	ldr r0, [r4]
	subs r1, #0xaa
	adds r0, r0, r1
	strh r5, [r0]
_0801BC52:
	mov r2, r8
	ldr r1, [r2]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x92
	bne _0801BC82
	adds r1, #0xe4
	movs r0, #0x12
	strb r0, [r1]
	ldr r1, _0801BD18 @ =0x040000D4
	ldr r0, _0801BD34 @ =0x084F61EC
	str r0, [r1]
	ldr r0, _0801BD38 @ =0x06015C00
	str r0, [r1, #4]
	ldr r0, _0801BD3C @ =0x800004A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801BD40 @ =0x081B4584
	str r0, [r1]
	ldr r0, _0801BD44 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0801BD30 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0801BC82:
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0x91
	beq _0801BC90
	b _0801BDAC
_0801BC90:
	movs r4, #0xd4
	lsls r4, r4, #1
	adds r0, r1, r4
	strb r5, [r0]
	ldr r1, [r3]
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r0, r1, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r6, #0x9c
	lsls r6, r6, #2
	adds r0, r1, r6
	adds r0, r0, r2
	ldrb r3, [r0]
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r4, #0
	strh r3, [r2]
	ldr r2, _0801BD48 @ =0x0000025D
	adds r1, r1, r2
	strb r4, [r1]
	ldr r6, _0801BD4C @ =0x086A3700
	mov r1, r8
	ldr r5, [r1]
	adds r0, r5, r0
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r4, [r0, #0x15]
	cmp r4, #0xcc
	bgt _0801BCF8
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r0, [r0, #0x15]
	cmp r0, #0xcc
	bgt _0801BCF8
	mov r3, r8
	ldr r1, [r3]
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801BCF8:
	bl sub_22FA4
	ldr r0, _0801BD10 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0801BD50
	movs r0, #0x1e
	bl m4aSongNumStart
	b _0801BD56
	.align 2, 0
_0801BD0C: .4byte 0x00000281
_0801BD10: .4byte gMain
_0801BD14: .4byte 0x0000F63C
_0801BD18: .4byte 0x040000D4
_0801BD1C: .4byte 0x086ACEF8
_0801BD20: .4byte 0x06015800
_0801BD24: .4byte 0x80001200
_0801BD28: .4byte 0x086ACF18
_0801BD2C: .4byte 0x050003C0
_0801BD30: .4byte 0x80000010
_0801BD34: .4byte 0x084F61EC
_0801BD38: .4byte 0x06015C00
_0801BD3C: .4byte 0x800004A0
_0801BD40: .4byte 0x081B4584
_0801BD44: .4byte 0x05000180
_0801BD48: .4byte 0x0000025D
_0801BD4C: .4byte 0x086A3700
_0801BD50:
	movs r0, #0x22
	bl m4aSongNumStart
_0801BD56:
	adds r0, r7, #0
	bl sub_21FBC
	ldr r3, _0801BE08 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x20]
	movs r5, #0
	movs r4, #1
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x24]
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x18]
	strh r4, [r0]
	ldr r2, _0801BE0C @ =0x040000D4
	ldr r0, _0801BE10 @ =0x081B8784
	str r0, [r2]
	ldr r0, _0801BE14 @ =0x050003C0
	str r0, [r2, #4]
	ldr r0, _0801BE18 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r6, _0801BE1C @ =0x000002EA
	adds r1, r3, r6
	movs r0, #0x50
	strh r0, [r1]
	strh r5, [r3, #0x2a]
	ldr r0, _0801BE20 @ =0x020314E0
	ldr r0, [r0]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xf
	strh r1, [r0]
	strh r4, [r3, #0x28]
	ldr r0, _0801BE24 @ =0x081B4784
	str r0, [r2]
	ldr r0, _0801BE28 @ =0x06002000
	str r0, [r2, #4]
	ldr r0, _0801BE2C @ =0x80000620
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801BDAC:
	ldr r4, _0801BE20 @ =0x020314E0
	ldr r2, [r4]
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x90
	bls _0801BDBE
	b _0801C2D8
_0801BDBE:
	movs r5, #0xdc
	lsls r5, r5, #3
	adds r1, r2, r5
	movs r6, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801BE30 @ =0x000006C4
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801BE34 @ =0x000006DB
	adds r0, r0, r1
	strb r6, [r0]
	ldr r3, [r4]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r3, r5
	ldrh r1, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0
	ble _0801BE74
	subs r1, #1
	strh r1, [r2]
	movs r6, #0xd8
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801BE38
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	b _0801BE58
	.align 2, 0
_0801BE08: .4byte gMain
_0801BE0C: .4byte 0x040000D4
_0801BE10: .4byte 0x081B8784
_0801BE14: .4byte 0x050003C0
_0801BE18: .4byte 0x80000010
_0801BE1C: .4byte 0x000002EA
_0801BE20: .4byte 0x020314E0
_0801BE24: .4byte 0x081B4784
_0801BE28: .4byte 0x06002000
_0801BE2C: .4byte 0x80000620
_0801BE30: .4byte 0x000006C4
_0801BE34: .4byte 0x000006DB
_0801BE38:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0801BE64
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r1, r0, #3
	subs r1, r1, r0
	movs r4, #0xdb
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
_0801BE58:
	cmp r0, #0xf
	beq _0801BE5E
	b _0801C1FA
_0801BE5E:
	bl sub_22FA4
	b _0801C1FA
_0801BE64:
	movs r6, #0
	ldrsh r1, [r2, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r2, #0xdb
	lsls r2, r2, #1
	adds r1, r3, r2
	b _0801C1F8
_0801BE74:
	ldr r5, _0801BEAC @ =0x00000281
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0801BE84
	b _0801BFA6
_0801BE84:
	ldr r0, _0801BEB0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801BEEC
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r2, [r4]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r2, r3
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801BEB4
	subs r0, r3, #1
	b _0801BEBA
	.align 2, 0
_0801BEAC: .4byte 0x00000281
_0801BEB0: .4byte gMain
_0801BEB4:
	adds r0, r2, r5
	ldrb r0, [r0]
	subs r0, #1
_0801BEBA:
	strb r0, [r1]
	ldr r5, _0801BEE8 @ =0x020314E0
	ldr r4, [r5]
	movs r6, #0xa0
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strh r1, [r0]
	subs r6, #0xd8
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _0801BF48
	.align 2, 0
_0801BEE8: .4byte 0x020314E0
_0801BEEC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801BFA6
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	bge _0801BF1C
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0801BF1E
_0801BF1C:
	strb r6, [r2]
_0801BF1E:
	ldr r5, _0801C000 @ =0x020314E0
	ldr r4, [r5]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r4, r3
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strh r1, [r0]
	movs r6, #0xd4
	lsls r6, r6, #1
	adds r0, r4, r6
	strb r2, [r0]
_0801BF48:
	ldr r4, [r5]
	movs r0, #0xdc
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, [r5]
	movs r4, #0xd8
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r5]
	ldr r7, _0801C004 @ =0x0000025D
	adds r0, r0, r7
	strb r2, [r0]
	ldr r6, _0801C008 @ =0x086A3700
	ldr r4, [r5]
	adds r3, r4, r3
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #0x15]
	cmp r2, #0xcc
	bgt _0801BFA6
	adds r0, r7, #0
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r0, [r0, #0x15]
	cmp r0, #0xcc
	bgt _0801BFA6
	ldr r1, [r5]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801BFA6:
	ldr r0, _0801C00C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0801C070
	ldr r6, _0801C000 @ =0x020314E0
	ldr r1, [r6]
	movs r7, #0x97
	lsls r7, r7, #2
	adds r0, r1, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	bne _0801C014
	ldr r2, _0801C008 @ =0x086A3700
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C058
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r4, _0801C010 @ =0x0000059A
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r1, r5
	movs r0, #0x1e
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _0801C04E
	.align 2, 0
_0801C000: .4byte 0x020314E0
_0801C004: .4byte 0x0000025D
_0801C008: .4byte 0x086A3700
_0801C00C: .4byte gMain
_0801C010: .4byte 0x0000059A
_0801C014:
	cmp r4, #1
	bne _0801C058
	ldr r2, _0801C064 @ =0x086A3700
	ldr r3, _0801C068 @ =0x0000059A
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C058
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r2, _0801C068 @ =0x0000059A
	adds r0, r1, r2
	strh r5, [r0]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0x1e
	strh r0, [r2]
	movs r5, #0xd8
	lsls r5, r5, #1
	adds r1, r1, r5
	strb r4, [r1]
_0801C04E:
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C058:
	ldr r0, _0801C06C @ =0x020314E0
	ldr r0, [r0]
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r0, r6
	b _0801C116
	.align 2, 0
_0801C064: .4byte 0x086A3700
_0801C068: .4byte 0x0000059A
_0801C06C: .4byte 0x020314E0
_0801C070:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0801C11A
	ldr r6, _0801C0BC @ =0x020314E0
	ldr r1, [r6]
	movs r7, #0x97
	lsls r7, r7, #2
	adds r0, r1, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _0801C0C4
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r5, [r0]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xcc
	bgt _0801C10C
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r2, _0801C0C0 @ =0x0000059A
	adds r0, r1, r2
	strh r5, [r0]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0x1e
	strh r0, [r2]
	movs r5, #0xd8
	lsls r5, r5, #1
	adds r1, r1, r5
	strb r4, [r1]
	b _0801C102
	.align 2, 0
_0801C0BC: .4byte 0x020314E0
_0801C0C0: .4byte 0x0000059A
_0801C0C4:
	cmp r4, #2
	bne _0801C10C
	ldr r2, _0801C148 @ =0x086A3700
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r5, [r0, #0x15]
	cmp r5, #0xcc
	bgt _0801C10C
	movs r0, #0x82
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r4, _0801C14C @ =0x0000059A
	adds r0, r1, r4
	strh r5, [r0]
	movs r5, #0xdc
	lsls r5, r5, #1
	adds r2, r1, r5
	movs r0, #0x1e
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_0801C102:
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801C10C:
	ldr r0, _0801C150 @ =0x020314E0
	ldr r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #1
	adds r1, r0, r2
_0801C116:
	movs r0, #0
	strh r0, [r1]
_0801C11A:
	ldr r0, _0801C150 @ =0x020314E0
	ldr r1, [r0]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0801C1FA
	ldr r4, _0801C14C @ =0x0000059A
	adds r2, r1, r4
	ldrh r0, [r2]
	cmp r0, #0x59
	beq _0801C190
	cmp r0, #0x59
	bgt _0801C154
	cmp r0, #0xe
	beq _0801C168
	cmp r0, #0x10
	beq _0801C17C
	b _0801C1EA
	.align 2, 0
_0801C148: .4byte 0x086A3700
_0801C14C: .4byte 0x0000059A
_0801C150: .4byte 0x020314E0
_0801C154:
	cmp r0, #0xb0
	beq _0801C1B8
	cmp r0, #0xb0
	bgt _0801C162
	cmp r0, #0x5a
	beq _0801C1A4
	b _0801C1EA
_0801C162:
	cmp r0, #0xb1
	beq _0801C1D2
	b _0801C1EA
_0801C168:
	movs r5, #0xd9
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x10
	b _0801C1CA
_0801C17C:
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xe
	b _0801C1CA
_0801C190:
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x5a
	b _0801C1CA
_0801C1A4:
	movs r3, #0xd9
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x59
	b _0801C1CA
_0801C1B8:
	movs r4, #0xd9
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb1
_0801C1CA:
	strh r0, [r2]
	bl sub_22FA4
	b _0801C1EA
_0801C1D2:
	movs r5, #0xd9
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	cmp r0, #0x32
	bne _0801C1EA
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb0
	strh r0, [r2]
	bl sub_22FA4
_0801C1EA:
	ldr r0, _0801C220 @ =0x020314E0
	ldr r0, [r0]
	movs r6, #0xd9
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrh r0, [r1]
	adds r0, #1
_0801C1F8:
	strh r0, [r1]
_0801C1FA:
	bl sub_23070
	ldr r0, _0801C220 @ =0x020314E0
	ldr r1, [r0]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0801C22E
	ldr r3, _0801C224 @ =0x000001A9
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801C228
	subs r0, #1
	strb r0, [r1]
	b _0801C246
	.align 2, 0
_0801C220: .4byte 0x020314E0
_0801C224: .4byte 0x000001A9
_0801C228:
	movs r0, #7
	strb r0, [r1]
	b _0801C246
_0801C22E:
	ldr r4, _0801C240 @ =0x000001A9
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #6
	bhi _0801C244
	adds r0, #1
	strb r0, [r1]
	b _0801C246
	.align 2, 0
_0801C240: .4byte 0x000001A9
_0801C244:
	strb r2, [r1]
_0801C246:
	ldr r1, _0801C2A4 @ =0x040000D4
	ldr r3, _0801C2A8 @ =0x086AD50C
	ldr r0, _0801C2AC @ =0x020314E0
	ldr r2, [r0]
	ldr r5, _0801C2B0 @ =0x000001A9
	adds r0, r2, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r0, #4
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0801C2B4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0801C2B8 @ =0x80000620
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0801C2BC @ =gMain
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r1, #0x50
	subs r1, r1, r0
	ldr r4, _0801C2C0 @ =0x000002EA
	adds r0, r3, r4
	strh r1, [r0]
	adds r5, #0xa9
	adds r2, r2, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _0801C2C4
	ldrh r1, [r3, #0x2a]
	movs r6, #0x2a
	ldrsh r0, [r3, r6]
	cmp r0, #0
	ble _0801C2D2
	subs r0, r1, #1
	strh r0, [r3, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0801C2D2
	strh r0, [r3, #0x28]
	movs r0, #0x90
	strh r0, [r3, #0x26]
	b _0801C2D2
	.align 2, 0
_0801C2A4: .4byte 0x040000D4
_0801C2A8: .4byte 0x086AD50C
_0801C2AC: .4byte 0x020314E0
_0801C2B0: .4byte 0x000001A9
_0801C2B4: .4byte 0x06002000
_0801C2B8: .4byte 0x80000620
_0801C2BC: .4byte gMain
_0801C2C0: .4byte 0x000002EA
_0801C2C4:
	ldrh r1, [r3, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r3, r2]
	cmp r0, #0x13
	bgt _0801C2D2
	adds r0, r1, #1
	strh r0, [r3, #0x2a]
_0801C2D2:
	movs r0, #0
	bl sub_21FBC
_0801C2D8:
	ldr r5, _0801C38C @ =0x020314E0
	ldr r3, [r5]
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	bgt _0801C31A
	ldr r1, _0801C390 @ =gMain
	movs r2, #0x2a
	ldrsh r0, [r1, r2]
	cmp r0, #0x13
	ble _0801C31A
	ldrh r1, [r1, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801C31A
	ldr r6, _0801C394 @ =0x00000252
	adds r0, r3, r6
	movs r1, #0
	movs r2, #0x1e
	strh r2, [r0]
	subs r6, #0xa2
	adds r0, r3, r6
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r0, r4
	strh r2, [r0]
	movs r0, #0x83
	bl m4aSongNumStart
_0801C31A:
	ldr r0, _0801C38C @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0801C394 @ =0x00000252
	adds r1, r2, r3
	ldrh r5, [r1]
	mov r8, r0
	cmp r5, #0
	bne _0801C32C
	b _0801C554
_0801C32C:
	subs r0, r5, #1
	strh r0, [r1]
	movs r0, #0xdc
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xe
	bgt _0801C342
	movs r0, #0xf
	strh r0, [r1]
_0801C342:
	mov r4, r8
	ldr r0, [r4]
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #4
	bls _0801C350
	b _0801C488
_0801C350:
	cmp r0, #1
	bls _0801C3FC
	ldr r5, _0801C390 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #4
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #3
	bls _0801C364
	b _0801C488
_0801C364:
	ldr r3, _0801C398 @ =0x040000D4
	ldr r1, _0801C39C @ =0x02031520
	ldr r4, [r1, #0x30]
	str r4, [r3]
	ldr r0, _0801C3A0 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801C3A4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801C3B0
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C3A8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C3AC @ =0x80000060
	b _0801C3BC
	.align 2, 0
_0801C38C: .4byte 0x020314E0
_0801C390: .4byte gMain
_0801C394: .4byte 0x00000252
_0801C398: .4byte 0x040000D4
_0801C39C: .4byte 0x02031520
_0801C3A0: .4byte 0x05000200
_0801C3A4: .4byte 0x80000010
_0801C3A8: .4byte 0x05000240
_0801C3AC: .4byte 0x80000060
_0801C3B0:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C3E8 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C3EC @ =0x80000070
_0801C3BC:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801C3F0 @ =0x040000D4
	ldr r0, [r2, #0x30]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0801C3F4 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801C3F8 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r6, r8
	ldr r0, [r6]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0x70
	b _0801C486
	.align 2, 0
_0801C3E8: .4byte 0x05000240
_0801C3EC: .4byte 0x80000070
_0801C3F0: .4byte 0x040000D4
_0801C3F4: .4byte 0x05000340
_0801C3F8: .4byte 0x80000030
_0801C3FC:
	ldr r5, _0801C434 @ =gMain
	ldrh r0, [r5, #0x3c]
	movs r0, #0
	strh r0, [r5, #0x3c]
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801C40C
	b _0801C554
_0801C40C:
	ldr r3, _0801C438 @ =0x040000D4
	ldr r1, _0801C43C @ =0x02031520
	ldr r4, [r1, #0x2c]
	str r4, [r3]
	ldr r0, _0801C440 @ =0x05000200
	str r0, [r3, #4]
	ldr r0, _0801C444 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldrb r0, [r5, #4]
	adds r2, r1, #0
	cmp r0, #1
	bne _0801C450
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C448 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C44C @ =0x80000060
	b _0801C45C
	.align 2, 0
_0801C434: .4byte gMain
_0801C438: .4byte 0x040000D4
_0801C43C: .4byte 0x02031520
_0801C440: .4byte 0x05000200
_0801C444: .4byte 0x80000010
_0801C448: .4byte 0x05000240
_0801C44C: .4byte 0x80000060
_0801C450:
	adds r0, r4, #0
	adds r0, #0x40
	str r0, [r3]
	ldr r0, _0801C4B0 @ =0x05000240
	str r0, [r3, #4]
	ldr r0, _0801C4B4 @ =0x80000070
_0801C45C:
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r1, _0801C4B8 @ =0x040000D4
	ldr r0, [r2, #0x2c]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0801C4BC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0801C4C0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, r8
	ldr r0, [r3]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x70
	movs r1, #1
_0801C486:
	strb r1, [r0]
_0801C488:
	mov r4, r8
	ldr r1, [r4]
	ldr r5, _0801C4C4 @ =0x00000252
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801C554
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801C4CC
	ldr r6, _0801C4C8 @ =0x000006DE
	adds r1, r1, r6
	movs r0, #0xaa
	strh r0, [r1]
	b _0801C4D0
	.align 2, 0
_0801C4B0: .4byte 0x05000240
_0801C4B4: .4byte 0x80000070
_0801C4B8: .4byte 0x040000D4
_0801C4BC: .4byte 0x05000340
_0801C4C0: .4byte 0x80000030
_0801C4C4: .4byte 0x00000252
_0801C4C8: .4byte 0x000006DE
_0801C4CC:
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801C4D0:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0801C530 @ =0x000006C4
	adds r0, r0, r2
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r1]
	ldr r3, _0801C534 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r1, _0801C538 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x20]
	movs r4, #0
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x18]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x24]
	strh r2, [r0]
	mov r5, r8
	ldr r0, [r5]
	movs r6, #0xe4
	lsls r6, r6, #3
	adds r0, r0, r6
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _0801C53C @ =0x0000071D
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0801C540 @ =0x0000071E
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #0x44
	adds r0, r0, r3
	strb r1, [r0]
	bl sub_2310C
	ldr r0, [r5]
_0801C528:
	adds r0, #0xe4
	strb r4, [r0]
	b _0801C554
	.align 2, 0
_0801C530: .4byte 0x000006C4
_0801C534: .4byte 0x000006DB
_0801C538: .4byte gMain
_0801C53C: .4byte 0x0000071D
_0801C540: .4byte 0x0000071E

	thumb_func_start sub_1C544
sub_1C544: @ 0x0801C544
	movs r4, #0xdd
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x32
	bne _0801C554
	movs r0, #0x18
	strh r0, [r1, #0x28]
_0801C554:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_1C560
sub_1C560: @ 0x0801C560
	push {r4, lr}
	ldr r3, _0801C598 @ =0x020314E0
	ldr r1, [r3]
	movs r4, #0
	movs r2, #0
	movs r0, #0x96
	strh r0, [r1, #0x28]
	ldr r0, _0801C59C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x34]
	strh r2, [r0]
	ldr r0, _0801C5A0 @ =0x000005F3
	adds r1, r1, r0
	strb r4, [r1]
	ldr r0, [r3]
	ldr r1, _0801C5A4 @ =0x00002710
	str r1, [r0, #0x3c]
	ldr r1, _0801C5A8 @ =0x000005F7
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #8
	bl sub_11B0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C598: .4byte 0x020314E0
_0801C59C: .4byte gMain
_0801C5A0: .4byte 0x000005F3
_0801C5A4: .4byte 0x00002710
_0801C5A8: .4byte 0x000005F7

	thumb_func_start sub_1C5AC
sub_1C5AC: @ 0x0801C5AC
	push {r4, r5, r6, lr}
	ldr r5, _0801C614 @ =0x020314E0
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	adds r1, r0, #0
	cmp r1, #0
	bne _0801C5BC
	b _0801C728
_0801C5BC:
	subs r0, #1
	movs r4, #0
	movs r6, #0
	strh r0, [r2, #0x28]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x94
	bls _0801C61C
	ldr r1, _0801C618 @ =0x0000132C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	strb r4, [r0, #0x1f]
	ldr r3, [r5]
	adds r1, r3, r1
	ldr r0, [r1]
	strh r6, [r0, #0x30]
	ldr r0, [r1]
	strh r6, [r0, #0x32]
	ldr r2, [r1]
	movs r0, #0x77
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	adds r0, #0xa0
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	strh r6, [r0, #6]
	ldr r2, [r1]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	movs r5, #0xe6
	lsls r5, r5, #3
	adds r3, r3, r5
	strb r4, [r3]
	b _0801C706
	.align 2, 0
_0801C614: .4byte 0x020314E0
_0801C618: .4byte 0x0000132C
_0801C61C:
	cmp r0, #0x94
	bne _0801C630
	movs r0, #1
	strb r0, [r2, #0x1f]
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	b _0801C706
_0801C630:
	cmp r0, #0x24
	bls _0801C644
	movs r0, #1
	strb r0, [r2, #0x1f]
	ldr r0, [r5]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r4, [r0]
	b _0801C706
_0801C644:
	cmp r0, #0x18
	bls _0801C658
	movs r1, #1
	strb r1, [r2, #0x1f]
	ldr r0, [r5]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	b _0801C706
_0801C658:
	cmp r0, #0x18
	bne _0801C6B0
	movs r0, #0x80
	bl m4aSongNumStart
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	ldr r3, _0801C6A4 @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	movs r0, #0x49
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	movs r0, #0xec
	strh r0, [r2, #0x32]
	ldr r0, [r1]
	strb r4, [r0]
	ldr r0, [r5]
	strb r4, [r0, #0x1f]
	ldr r0, [r5]
	ldr r2, _0801C6A8 @ =0x000005FA
	adds r0, r0, r2
	strb r4, [r0]
	ldr r1, [r5]
	adds r3, r1, r3
	ldr r2, [r3]
	movs r0, #0x88
	strh r0, [r2, #0xe]
	ldr r3, _0801C6AC @ =0x000005F7
	adds r1, r1, r3
	strb r4, [r1]
	b _0801C706
	.align 2, 0
_0801C6A4: .4byte 0x0000132C
_0801C6A8: .4byte 0x000005FA
_0801C6AC: .4byte 0x000005F7
_0801C6B0:
	cmp r0, #0xc
	bls _0801C6FC
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r5]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x15
	bls _0801C6E8
	ldr r2, _0801C6E4 @ =0x0000132C
	adds r0, r1, r2
	ldr r4, [r0]
	ldrh r0, [r1, #0x28]
	movs r1, #0x18
	subs r1, r1, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	movs r1, #3
	bl __divsi3
	adds r0, #0x90
	strh r0, [r4, #0xe]
	b _0801C706
	.align 2, 0
_0801C6E4: .4byte 0x0000132C
_0801C6E8:
	ldr r3, _0801C6F8 @ =0x0000132C
	adds r0, r1, r3
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0xe]
	b _0801C706
	.align 2, 0
_0801C6F8: .4byte 0x0000132C
_0801C6FC:
	movs r5, #0xe6
	lsls r5, r5, #3
	adds r1, r2, r5
	movs r0, #1
	strb r0, [r1]
_0801C706:
	ldr r0, _0801C724 @ =0x020314E0
	ldr r1, [r0]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x28
	bhi _0801C736
	adds r1, #0xe6
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0801C736
	subs r0, r2, #1
	strh r0, [r1]
	b _0801C736
	.align 2, 0
_0801C724: .4byte 0x020314E0
_0801C728:
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x25
	strb r1, [r0]
_0801C736:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_1C73C
sub_1C73C: @ 0x0801C73C
	push {r4, r5, r6, r7, lr}
	ldr r7, _0801C7E0 @ =gMain
	ldr r0, [r7, #0x44]
	ldr r0, [r0, #0x34]
	movs r6, #0
	movs r4, #0
	strh r4, [r0]
	movs r0, #0
	bl sub_4B408
	ldr r5, _0801C7E4 @ =0x020314E0
	ldr r1, [r5]
	ldr r2, _0801C7E8 @ =0x0000132C
	adds r1, r1, r2
	ldr r0, [r1]
	strh r4, [r0, #0x30]
	ldr r0, [r1]
	strh r4, [r0, #0x32]
	ldr r0, [r1]
	strb r6, [r0]
	ldr r0, [r5]
	strb r6, [r0, #0x1f]
	ldr r1, [r5]
	adds r2, r1, r2
	ldr r2, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	strb r6, [r1]
	ldr r0, [r5]
	adds r0, #0x25
	strb r6, [r0]
	ldr r1, [r5]
	ldr r2, _0801C7EC @ =0x00000282
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801C7BA
	ldr r2, _0801C7F0 @ =0x00000723
	adds r0, r1, r2
	strb r6, [r0]
	ldr r0, [r5]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	subs r2, #6
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	subs r1, #2
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r0, r0, r2
	strb r6, [r0]
_0801C7BA:
	bl m4aMPlayAllStop
	bl sub_D10
	ldrb r0, [r7, #4]
	strb r0, [r7, #5]
	ldr r0, [r5]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #6]
	strb r6, [r7, #3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7E0: .4byte gMain
_0801C7E4: .4byte 0x020314E0
_0801C7E8: .4byte 0x0000132C
_0801C7EC: .4byte 0x00000282
_0801C7F0: .4byte 0x00000723

	thumb_func_start sub_1C7F4
sub_1C7F4: @ 0x0801C7F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x2c]
	lsrs r1, r0, #0x10
	str r1, [sp, #0x28]
	asrs r0, r0, #0x10
	ldr r2, _0801C824 @ =0x020314E0
	mov sl, r2
	cmp r0, #9
	bls _0801C81A
	bl _0801D0B8
_0801C81A:
	lsls r0, r0, #2
	ldr r1, _0801C828 @ =_0801C82C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C824: .4byte 0x020314E0
_0801C828: .4byte _0801C82C
_0801C82C: @ jump table
	.4byte _0801C854 @ case 0
	.4byte _0801C900 @ case 1
	.4byte _0801C9A8 @ case 2
	.4byte _0801CA4C @ case 3
	.4byte _0801CCB8 @ case 4
	.4byte _0801D0B8 @ case 5
	.4byte _0801CDC0 @ case 6
	.4byte _0801CF6C @ case 7
	.4byte _0801D02C @ case 8
	.4byte _0801CB24 @ case 9
_0801C854:
	ldr r6, _0801C8D0 @ =0x020314E0
	ldr r0, [r6]
	ldr r3, _0801C8D4 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, [sp, #0x2c]
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	ldr r2, _0801C8D8 @ =0x00000749
	adds r1, r0, r2
	adds r1, r1, r3
	ldr r5, _0801C8DC @ =0x000006D9
	mov r8, r5
	add r0, r8
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r4, _0801C8E0 @ =0x040000D4
	ldr r5, [r6]
	adds r2, r5, r2
	adds r2, r2, r3
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801C8E4 @ =0x0848D68C
	adds r0, r0, r1
	str r0, [r4]
	lsls r2, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #8
	ldr r1, _0801C8E8 @ =0x06010CA0
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _0801C8EC @ =0x80000180
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	add r5, r8
	adds r5, r5, r3
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0x14
	lsrs r0, r0, #0xf
	ldr r1, _0801C8F0 @ =0x081C00E4
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0801C8F4 @ =0x086AD798
	adds r2, r2, r0
	ldrh r0, [r2]
	lsls r0, r0, #5
	ldr r2, _0801C8F8 @ =0x05000200
	adds r0, r0, r2
	str r0, [r4, #4]
	ldr r0, _0801C8FC @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov sl, r6
	bl _0801D0B8
	.align 2, 0
_0801C8D0: .4byte 0x020314E0
_0801C8D4: .4byte 0x000006DB
_0801C8D8: .4byte 0x00000749
_0801C8DC: .4byte 0x000006D9
_0801C8E0: .4byte 0x040000D4
_0801C8E4: .4byte 0x0848D68C
_0801C8E8: .4byte 0x06010CA0
_0801C8EC: .4byte 0x80000180
_0801C8F0: .4byte 0x081C00E4
_0801C8F4: .4byte 0x086AD798
_0801C8F8: .4byte 0x05000200
_0801C8FC: .4byte 0x80000010
_0801C900:
	ldr r7, _0801C97C @ =0x086AD070
	ldr r6, _0801C980 @ =0x020314E0
	ldr r0, [r6]
	ldr r3, [sp, #0x2c]
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	ldr r5, _0801C984 @ =0x00000749
	mov r8, r5
	adds r5, r0, r5
	adds r5, r5, r4
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801C988 @ =0x040000D4
	ldr r0, [r6]
	add r0, r8
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801C98C @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r5, _0801C990 @ =0x06010CA0
	adds r4, r4, r5
	str r4, [r3, #4]
	ldr r0, _0801C994 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801C998 @ =0x081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801C99C @ =0x086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801C9A0 @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801C9A4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r6
	b _0801D0B8
	.align 2, 0
_0801C97C: .4byte 0x086AD070
_0801C980: .4byte 0x020314E0
_0801C984: .4byte 0x00000749
_0801C988: .4byte 0x040000D4
_0801C98C: .4byte 0x083A8EEC
_0801C990: .4byte 0x06010CA0
_0801C994: .4byte 0x80000180
_0801C998: .4byte 0x081C02E4
_0801C99C: .4byte 0x086AD798
_0801C9A0: .4byte 0x05000200
_0801C9A4: .4byte 0x80000010
_0801C9A8:
	ldr r5, _0801CA1C @ =0x020314E0
	ldr r3, [r5]
	ldr r4, [sp, #0x2c]
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	ldr r1, _0801CA20 @ =0x000006EC
	adds r0, r3, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801CA24 @ =0x086AD000
	adds r7, r0, r1
	ldr r1, _0801CA28 @ =0x00000749
	adds r3, r3, r1
	adds r3, r3, r2
	ldrh r0, [r7]
	strb r0, [r3]
	ldrh r3, [r7, #4]
	lsls r3, r3, #0x14
	ldr r4, _0801CA2C @ =0x040000D4
	ldr r0, [r5]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CA30 @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r4]
	lsls r1, r2, #1
	adds r2, r1, r2
	lsls r2, r2, #8
	ldr r0, _0801CA34 @ =0x06010CA0
	adds r2, r2, r0
	str r2, [r4, #4]
	ldr r0, _0801CA38 @ =0x80000180
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	lsrs r3, r3, #0xf
	ldr r0, _0801CA3C @ =0x081C02E4
	adds r3, r3, r0
	str r3, [r4]
	ldr r0, _0801CA40 @ =0x086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801CA44 @ =0x05000200
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _0801CA48 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov sl, r5
	b _0801D0B8
	.align 2, 0
_0801CA1C: .4byte 0x020314E0
_0801CA20: .4byte 0x000006EC
_0801CA24: .4byte 0x086AD000
_0801CA28: .4byte 0x00000749
_0801CA2C: .4byte 0x040000D4
_0801CA30: .4byte 0x083A8EEC
_0801CA34: .4byte 0x06010CA0
_0801CA38: .4byte 0x80000180
_0801CA3C: .4byte 0x081C02E4
_0801CA40: .4byte 0x086AD798
_0801CA44: .4byte 0x05000200
_0801CA48: .4byte 0x80000010
_0801CA4C:
	ldr r7, _0801CAFC @ =0x020314E0
	ldr r1, [r7]
	ldr r2, [sp, #0x2c]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r8, r2
	ldr r2, _0801CB00 @ =0x00000749
	adds r0, r1, r2
	add r0, r8
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r1, r1, r3
	ldrh r1, [r1]
	strb r1, [r0]
	ldr r5, _0801CB04 @ =0x040000D4
	ldr r4, _0801CB08 @ =gMonPortraitGroupGfx
	mov sl, r4
	ldr r6, [r7]
	adds r6, r6, r2
	add r6, r8
	ldrb r0, [r6]
	mov sb, r0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, sl
	mov r0, sb
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #3
	ldr r2, _0801CB0C @ =0x06010CA0
	adds r0, r0, r2
	str r0, [r5, #4]
	ldr r0, _0801CB10 @ =0x80000180
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r3, _0801CB14 @ =gMonPortraitGroupPals
	mov r8, r3
	ldrb r6, [r6]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, _0801CB18 @ =0x050003A0
	str r0, [r5, #4]
	ldr r1, _0801CB1C @ =0x80000010
	str r1, [r5, #8]
	ldr r0, [r5, #8]
	mov r4, r8
	ldr r0, [r4]
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r5]
	ldr r0, _0801CB20 @ =0x050003E0
	str r0, [r5, #4]
	str r1, [r5, #8]
	ldr r0, [r5, #8]
	mov sl, r7
	b _0801D0B8
	.align 2, 0
_0801CAFC: .4byte 0x020314E0
_0801CB00: .4byte 0x00000749
_0801CB04: .4byte 0x040000D4
_0801CB08: .4byte gMonPortraitGroupGfx
_0801CB0C: .4byte 0x06010CA0
_0801CB10: .4byte 0x80000180
_0801CB14: .4byte gMonPortraitGroupPals
_0801CB18: .4byte 0x050003A0
_0801CB1C: .4byte 0x80000010
_0801CB20: .4byte 0x050003E0
_0801CB24:
	ldr r0, _0801CB68 @ =0x020314E0
	ldr r4, [r0]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	ble _0801CBEC
	ldr r0, _0801CB6C @ =0x0200B134
	ldr r5, _0801CB70 @ =0x0000059A
	adds r1, r4, r5
	ldrh r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801CB80
	ldr r0, [sp, #0x2c]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	ldr r3, _0801CB74 @ =0x00000749
	adds r0, r4, r3
	adds r0, r0, r2
	movs r1, #0xcd
	strb r1, [r0]
	ldr r5, _0801CB78 @ =0x040000D4
	ldr r1, _0801CB7C @ =gMonPortraitGroupPals
	mov r8, r1
	mov r4, sl
	ldr r0, [r4]
	b _0801CC0C
	.align 2, 0
_0801CB68: .4byte 0x020314E0
_0801CB6C: .4byte 0x0200B134
_0801CB70: .4byte 0x0000059A
_0801CB74: .4byte 0x00000749
_0801CB78: .4byte 0x040000D4
_0801CB7C: .4byte gMonPortraitGroupPals
_0801CB80:
	cmp r0, #3
	bhi _0801CBC0
	ldr r5, [sp, #0x2c]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0801CBAC @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, _0801CBB0 @ =0x040000D4
	ldr r0, _0801CBB4 @ =gMonPortraitGroupPals
	ldr r0, [r0]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0801CBB8 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0801CBBC @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0801CC3E
	.align 2, 0
_0801CBAC: .4byte 0x00000749
_0801CBB0: .4byte 0x040000D4
_0801CBB4: .4byte gMonPortraitGroupPals
_0801CBB8: .4byte 0x050003A0
_0801CBBC: .4byte 0x80000010
_0801CBC0:
	ldr r5, [sp, #0x2c]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0801CBE0 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r5, _0801CBE4 @ =0x040000D4
	ldr r0, _0801CBE8 @ =gMonPortraitGroupPals
	mov r8, r0
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r2
	adds r0, r0, r1
	b _0801CC10
	.align 2, 0
_0801CBE0: .4byte 0x00000749
_0801CBE4: .4byte 0x040000D4
_0801CBE8: .4byte gMonPortraitGroupPals
_0801CBEC:
	ldr r5, [sp, #0x2c]
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	ldr r3, _0801CC98 @ =0x00000749
	adds r0, r4, r3
	adds r0, r0, r2
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r1, r4, r5
	ldrh r1, [r1]
	strb r1, [r0]
	ldr r5, _0801CC9C @ =0x040000D4
	ldr r0, _0801CCA0 @ =gMonPortraitGroupPals
	mov r8, r0
	mov r1, sl
	ldr r0, [r1]
_0801CC0C:
	adds r0, r0, r3
	adds r0, r0, r2
_0801CC10:
	ldrb r6, [r0]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r5]
	ldr r0, _0801CCA4 @ =0x050003A0
	str r0, [r5, #4]
	ldr r0, _0801CCA8 @ =0x80000010
	str r0, [r5, #8]
	ldr r0, [r5, #8]
_0801CC3E:
	ldr r2, _0801CC9C @ =0x040000D4
	mov r8, r2
	ldr r3, _0801CCAC @ =gMonPortraitGroupGfx
	mov sb, r3
	mov r4, sl
	ldr r0, [r4]
	ldr r1, [sp, #0x2c]
	lsls r5, r1, #0x10
	asrs r5, r5, #0x10
	ldr r2, _0801CC98 @ =0x00000749
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r6, [r0]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, sb
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	mov r3, r8
	str r0, [r3]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r4, _0801CCB0 @ =0x06010CA0
	adds r0, r0, r4
	str r0, [r3, #4]
	ldr r0, _0801CCB4 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	b _0801D0B8
	.align 2, 0
_0801CC98: .4byte 0x00000749
_0801CC9C: .4byte 0x040000D4
_0801CCA0: .4byte gMonPortraitGroupPals
_0801CCA4: .4byte 0x050003A0
_0801CCA8: .4byte 0x80000010
_0801CCAC: .4byte gMonPortraitGroupGfx
_0801CCB0: .4byte 0x06010CA0
_0801CCB4: .4byte 0x80000180
_0801CCB8:
	ldr r0, _0801CD28 @ =0x020314E0
	ldr r2, [r0]
	movs r1, #0x17
	ldrsb r1, [r2, r1]
	mov sl, r0
	cmp r1, #2
	bne _0801CD44
	ldr r0, [sp, #0x2c]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	ldr r1, _0801CD2C @ =0x00000749
	mov r8, r1
	adds r4, r2, r1
	adds r4, r4, r5
	ldr r6, _0801CD30 @ =0x086AD000
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x78
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r2, _0801CD34 @ =0x040000D4
	mov r4, sl
	ldr r0, [r4]
	add r0, r8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CD38 @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r5, _0801CD3C @ =0x06010CA0
	adds r0, r0, r5
	str r0, [r2, #4]
	ldr r0, _0801CD40 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, #0x7c
	ldrh r5, [r6]
	b _0801CF30
	.align 2, 0
_0801CD28: .4byte 0x020314E0
_0801CD2C: .4byte 0x00000749
_0801CD30: .4byte 0x086AD000
_0801CD34: .4byte 0x040000D4
_0801CD38: .4byte 0x083A8EEC
_0801CD3C: .4byte 0x06010CA0
_0801CD40: .4byte 0x80000180
_0801CD44:
	ldr r0, [sp, #0x2c]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	ldr r1, _0801CDA8 @ =0x00000749
	mov r8, r1
	adds r4, r2, r1
	adds r4, r4, r5
	ldr r6, _0801CDAC @ =0x086AD000
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r1, #0x80
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r2, _0801CDB0 @ =0x040000D4
	mov r4, sl
	ldr r0, [r4]
	add r0, r8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CDB4 @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r5, _0801CDB8 @ =0x06010CA0
	adds r0, r0, r5
	str r0, [r2, #4]
	ldr r0, _0801CDBC @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, #0x84
	ldrh r0, [r6]
	lsls r0, r0, #0x14
	lsrs r5, r0, #0x10
	b _0801CF30
	.align 2, 0
_0801CDA8: .4byte 0x00000749
_0801CDAC: .4byte 0x086AD000
_0801CDB0: .4byte 0x040000D4
_0801CDB4: .4byte 0x083A8EEC
_0801CDB8: .4byte 0x06010CA0
_0801CDBC: .4byte 0x80000180
_0801CDC0:
	ldr r4, _0801CEF8 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801CEFC @ =0x000001A7
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801CF00 @ =0x086AD000
	adds r7, r0, r1
	ldr r0, [sp, #0x2c]
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	ldr r1, _0801CF04 @ =0x00000749
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r0, [r7]
	strb r0, [r2]
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x14
	lsrs r5, r0, #0x10
	ldr r2, _0801CF08 @ =0x040000D4
	ldr r0, [r4]
	mov r8, r0
	add r1, r8
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801CF0C @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r2]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #8
	ldr r1, _0801CF10 @ =0x06010CA0
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _0801CF14 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, r8
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	mov sl, r4
	ldrh r7, [r7, #6]
	cmp r0, r7
	blo _0801CE5A
	ldr r1, _0801CF18 @ =0x086AD2DE
	movs r4, #0xd3
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #3
	bne _0801CE4C
	adds r3, #0x50
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801CE5A
_0801CE4C:
	cmp r1, #4
	bne _0801CF30
	ldr r0, _0801CF1C @ =0x000001AF
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CF30
_0801CE5A:
	ldr r2, _0801CF08 @ =0x040000D4
	lsls r0, r5, #1
	ldr r1, _0801CF20 @ =0x081C02E4
	adds r0, r0, r1
	str r0, [r2]
	mov r4, sp
	str r4, [r2, #4]
	ldr r0, _0801CF24 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r5, _0801CF28 @ =0x086AD798
	mov sb, r5
	add r7, sp, #0x20
_0801CE76:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #1
	mov r1, sp
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r0, r0, #1
	movs r1, #3
	bl __divsi3
	mov r8, r0
	mov r2, r8
	strh r2, [r7]
	ldrh r0, [r6]
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r1, r3, #0
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #3
	bl __divsi3
	adds r4, r0, #0
	strh r4, [r7, #2]
	ldrh r0, [r6]
	movs r2, #0xf8
	lsls r2, r2, #7
	adds r1, r2, #0
	ands r0, r1
	lsrs r0, r0, #9
	movs r1, #3
	bl __divsi3
	strh r0, [r7, #4]
	lsls r4, r4, #5
	mov r3, r8
	orrs r4, r3
	lsls r0, r0, #0xa
	orrs r4, r0
	strh r4, [r6]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #0xf
	ble _0801CE76
	ldr r1, _0801CF08 @ =0x040000D4
	mov r4, sp
	str r4, [r1]
	ldr r5, [sp, #0x2c]
	lsls r0, r5, #0x10
	asrs r0, r0, #0xf
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r2, _0801CF2C @ =0x05000200
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _0801CF24 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0801D0B8
	.align 2, 0
_0801CEF8: .4byte 0x020314E0
_0801CEFC: .4byte 0x000001A7
_0801CF00: .4byte 0x086AD000
_0801CF04: .4byte 0x00000749
_0801CF08: .4byte 0x040000D4
_0801CF0C: .4byte 0x083A8EEC
_0801CF10: .4byte 0x06010CA0
_0801CF14: .4byte 0x80000180
_0801CF18: .4byte 0x086AD2DE
_0801CF1C: .4byte 0x000001AF
_0801CF20: .4byte 0x081C02E4
_0801CF24: .4byte 0x80000010
_0801CF28: .4byte 0x086AD798
_0801CF2C: .4byte 0x05000200
_0801CF30:
	ldr r2, _0801CF58 @ =0x040000D4
	lsls r0, r5, #1
	ldr r1, _0801CF5C @ =0x081C02E4
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0801CF60 @ =0x086AD798
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r4, _0801CF64 @ =0x05000200
	adds r0, r0, r4
	str r0, [r2, #4]
	ldr r0, _0801CF68 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0801D0B8
	.align 2, 0
_0801CF58: .4byte 0x040000D4
_0801CF5C: .4byte 0x081C02E4
_0801CF60: .4byte 0x086AD798
_0801CF64: .4byte 0x05000200
_0801CF68: .4byte 0x80000010
_0801CF6C:
	ldr r5, _0801CFFC @ =0x020314E0
	mov r8, r5
	ldr r2, [r5]
	ldr r0, [sp, #0x2c]
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	ldr r1, _0801D000 @ =0x000006EC
	adds r0, r2, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801D004 @ =0x086AD000
	adds r7, r0, r1
	ldr r6, _0801D008 @ =0x00000749
	adds r5, r2, r6
	adds r5, r5, r4
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #0x30
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r7, r0
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801D00C @ =0x040000D4
	mov r5, r8
	ldr r0, [r5]
	adds r0, r0, r6
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801D010 @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r0, _0801D014 @ =0x06010CA0
	adds r4, r4, r0
	str r4, [r3, #4]
	ldr r0, _0801D018 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801D01C @ =0x081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D020 @ =0x086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801D024 @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801D028 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r8
	b _0801D0B8
	.align 2, 0
_0801CFFC: .4byte 0x020314E0
_0801D000: .4byte 0x000006EC
_0801D004: .4byte 0x086AD000
_0801D008: .4byte 0x00000749
_0801D00C: .4byte 0x040000D4
_0801D010: .4byte 0x083A8EEC
_0801D014: .4byte 0x06010CA0
_0801D018: .4byte 0x80000180
_0801D01C: .4byte 0x081C02E4
_0801D020: .4byte 0x086AD798
_0801D024: .4byte 0x05000200
_0801D028: .4byte 0x80000010
_0801D02C:
	ldr r2, _0801D0EC @ =0x020314E0
	mov sb, r2
	ldr r2, [r2]
	ldr r3, _0801D0F0 @ =0x000006DC
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0801D0F4 @ =0x086AD000
	adds r7, r0, r1
	ldr r5, [sp, #0x2c]
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	ldr r0, _0801D0F8 @ =0x00000749
	mov r8, r0
	adds r5, r2, r0
	adds r5, r5, r4
	ldr r6, _0801D0FC @ =0x086AD79C
	ldr r1, _0801D100 @ =0x000006DE
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r1, #0xc
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r7, r0
	ldrh r0, [r0]
	strb r0, [r5]
	ldrh r2, [r7, #4]
	lsls r2, r2, #0x14
	ldr r3, _0801D104 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	add r0, r8
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801D108 @ =0x083A8EEC
	adds r0, r0, r1
	str r0, [r3]
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r4, r4, #8
	ldr r0, _0801D10C @ =0x06010CA0
	adds r4, r4, r0
	str r4, [r3, #4]
	ldr r0, _0801D110 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	lsrs r2, r2, #0xf
	ldr r0, _0801D114 @ =0x081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D118 @ =0x086AD798
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, _0801D11C @ =0x05000200
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0801D120 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, sb
_0801D0B8:
	mov r2, sl
	ldr r1, [r2]
	ldr r3, [sp, #0x2c]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r4, _0801D124 @ =0x00000747
	adds r1, r1, r4
	adds r1, r1, r0
	add r5, sp, #0x28
	ldrb r5, [r5]
	strb r5, [r1]
	ldr r1, [r2]
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D0EC: .4byte 0x020314E0
_0801D0F0: .4byte 0x000006DC
_0801D0F4: .4byte 0x086AD000
_0801D0F8: .4byte 0x00000749
_0801D0FC: .4byte 0x086AD79C
_0801D100: .4byte 0x000006DE
_0801D104: .4byte 0x040000D4
_0801D108: .4byte 0x083A8EEC
_0801D10C: .4byte 0x06010CA0
_0801D110: .4byte 0x80000180
_0801D114: .4byte 0x081C02E4
_0801D118: .4byte 0x086AD798
_0801D11C: .4byte 0x05000200
_0801D120: .4byte 0x80000010
_0801D124: .4byte 0x00000747

	thumb_func_start sub_1D128
sub_1D128: @ 0x0801D128
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r1, _0801D154 @ =0x020314E0
	ldr r3, [r1]
	ldr r2, _0801D158 @ =0x000006C4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #3
	bne _0801D15C
	movs r3, #0
	mov r8, r3
	movs r0, #0xb4
	mov sl, r0
	movs r2, #0xb4
	b _0801D1C4
	.align 2, 0
_0801D154: .4byte 0x020314E0
_0801D158: .4byte 0x000006C4
_0801D15C:
	cmp r0, #2
	bne _0801D190
	ldr r0, _0801D174 @ =gMain
	movs r2, #0x2a
	ldrsh r1, [r0, r2]
	cmp r1, #0x13
	bgt _0801D178
	movs r3, #0xb4
	mov sl, r3
	movs r2, #0xb4
	b _0801D18A
	.align 2, 0
_0801D174: .4byte gMain
_0801D178:
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r0, #0x58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r2, #0x58
_0801D18A:
	movs r3, #0x30
	mov r8, r3
	b _0801D1C4
_0801D190:
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r1, #0x96
	lsls r1, r1, #1
	adds r2, r1, #0
	ldrh r0, [r0]
	adds r0, r2, r0
	adds r1, r3, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
_0801D1C4:
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x58]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sl
	strh r1, [r6, #4]
	mov r3, sb
	ldr r0, [r3]
	ldr r3, _0801D4A8 @ =0x000006E4
	adds r1, r0, r3
	mov r3, r8
	strh r3, [r1]
	ldrh r1, [r6, #4]
	ldr r3, _0801D4AC @ =0x000006E6
	adds r0, r0, r3
	strh r1, [r0]
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0xc7
	ble _0801D1F2
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D1F2:
	movs r0, #0
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp]
	lsls r2, r2, #0x10
	str r2, [sp, #4]
	ldr r7, _0801D4B0 @ =gOamBuffer
	mov ip, sb
_0801D202:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0801D4B4 @ =0x000006D3
	adds r0, r0, r2
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r3, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0801D4B8 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	subs r0, #0x10
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0801D4C0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D202
	mov r3, sb
	ldr r0, [r3]
	ldr r1, _0801D4C4 @ =0x000006C4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0801D298
	b _0801D3FA
_0801D298:
	ldr r2, _0801D4A4 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r6, [r0, #0x5c]
	mov r3, r8
	strh r3, [r6, #2]
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x20
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb3
	ble _0801D2B8
	movs r0, #0xb4
	strh r0, [r6, #4]
_0801D2B8:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r2, _0801D4C0 @ =0xFFFFFE00
	mov ip, r2
_0801D2C0:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0xc0
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D2C0
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x50]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0801D4C8 @ =0x0000010B
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D33C
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D33C:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r3, _0801D4C0 @ =0xFFFFFE00
	mov ip, r3
_0801D344:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D344
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x54]
	mov r0, r8
	strh r0, [r6, #2]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0801D4CC @ =0x0000014D
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D3AE
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D3AE:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	ldr r3, _0801D4C0 @ =0xFFFFFE00
	mov r8, r3
_0801D3B6:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D3B6
_0801D3FA:
	ldr r3, _0801D4A4 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0x4c]
	ldr r1, [sp]
	asrs r0, r1, #0x10
	subs r0, #8
	strh r0, [r6, #2]
	ldr r2, [sp, #4]
	asrs r0, r2, #0x10
	subs r0, #8
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0801D41C
	movs r0, #0xc8
	strh r0, [r6, #4]
_0801D41C:
	movs r0, #0
	ldr r7, _0801D4B0 @ =gOamBuffer
	movs r3, #3
	mov ip, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sl, r1
	ldr r2, _0801D4C0 @ =0xFFFFFE00
	mov r8, r2
_0801D42E:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0801D4B8 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r0, ip
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801D4BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0801D42E
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D4A4: .4byte gMain
_0801D4A8: .4byte 0x000006E4
_0801D4AC: .4byte 0x000006E6
_0801D4B0: .4byte gOamBuffer
_0801D4B4: .4byte 0x000006D3
_0801D4B8: .4byte 0x000006DB
_0801D4BC: .4byte 0x000001FF
_0801D4C0: .4byte 0xFFFFFE00
_0801D4C4: .4byte 0x000006C4
_0801D4C8: .4byte 0x0000010B
_0801D4CC: .4byte 0x0000014D

	thumb_func_start sub_1D4D0
sub_1D4D0: @ 0x0801D4D0
	push {r4, r5, r6, r7, lr}
	ldr r0, _0801D5C8 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _0801D5CC @ =0x000006C4
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r7, r0, #0
	cmp r1, #1
	bne _0801D5C2
	ldr r0, _0801D5D0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r4, [r1, #0x58]
	movs r1, #0xb4
	strh r1, [r4, #4]
	movs r1, #0
	adds r6, r0, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D4F6:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D4F6
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x5c]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb3
	ble _0801D53A
	movs r0, #0xb4
	strh r0, [r4, #4]
_0801D53A:
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D53E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D53E
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x50]
	movs r0, #0xb4
	strh r0, [r4, #4]
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D56E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D56E
	ldr r0, [r6, #0x44]
	ldr r4, [r0, #0x54]
	movs r0, #0xb4
	strh r0, [r4, #4]
	movs r1, #0
	ldr r5, _0801D5D4 @ =gOamBuffer
_0801D59E:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r3, r4, r0
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r4, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _0801D59E
_0801D5C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801D5C8: .4byte 0x020314E0
_0801D5CC: .4byte 0x000006C4
_0801D5D0: .4byte gMain
_0801D5D4: .4byte gOamBuffer

	thumb_func_start sub_1D5D8
sub_1D5D8: @ 0x0801D5D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0801D60C @ =0x0200E6C0
	mov sb, r0
	movs r1, #0
	mov r8, r1
	movs r5, #0
	ldr r1, _0801D610 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _0801D614 @ =0x000002FB
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bls _0801D600
	b _0801D930
_0801D600:
	lsls r0, r0, #2
	ldr r1, _0801D618 @ =_0801D61C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D60C: .4byte 0x0200E6C0
_0801D610: .4byte 0x020314E0
_0801D614: .4byte 0x000002FB
_0801D618: .4byte _0801D61C
_0801D61C: @ jump table
	.4byte _0801D63C @ case 0
	.4byte _0801D65C @ case 1
	.4byte _0801D6C4 @ case 2
	.4byte _0801D760 @ case 3
	.4byte _0801D7C8 @ case 4
	.4byte _0801D860 @ case 5
	.4byte _0801D860 @ case 6
	.4byte _0801D8E0 @ case 7
_0801D63C:
	ldr r0, _0801D658 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x24
	bl __umodsi3
	movs r1, #0x12
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r5, r8
	b _0801D930
	.align 2, 0
_0801D658: .4byte gMain
_0801D65C:
	ldr r4, _0801D6AC @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _0801D6B0 @ =0x000002FE
	adds r2, r1, r3
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldr r5, _0801D6B4 @ =0x000002FD
	adds r1, r1, r5
	strb r3, [r1]
	ldr r0, [r4]
	ldr r7, _0801D6B8 @ =0x000002FB
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
	ldr r2, _0801D6BC @ =0x086AD7C0
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #0xcf
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	ldr r0, _0801D6C0 @ =0x0000C350
	str r0, [r1, #0x3c]
	b _0801D930
	.align 2, 0
_0801D6AC: .4byte 0x020314E0
_0801D6B0: .4byte 0x000002FE
_0801D6B4: .4byte 0x000002FD
_0801D6B8: .4byte 0x000002FB
_0801D6BC: .4byte 0x086AD7C0
_0801D6C0: .4byte 0x0000C350
_0801D6C4:
	ldr r3, _0801D6F0 @ =0x086AD7C0
	ldr r0, _0801D6F4 @ =0x020314E0
	ldr r2, [r0]
	ldr r6, _0801D6F8 @ =0x000002FD
	adds r4, r2, r6
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _0801D6FC @ =0x000002FE
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801D700
	adds r0, r1, #1
	strh r0, [r2]
	b _0801D736
	.align 2, 0
_0801D6F0: .4byte 0x086AD7C0
_0801D6F4: .4byte 0x020314E0
_0801D6F8: .4byte 0x000002FD
_0801D6FC: .4byte 0x000002FE
_0801D700:
	movs r5, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r7, _0801D754 @ =0x020314E0
	ldr r1, [r7]
	ldr r2, _0801D758 @ =0x000002FD
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801D736
	ldr r7, _0801D75C @ =0x000002FB
	adds r0, r1, r7
	strb r5, [r0]
	ldr r1, _0801D754 @ =0x020314E0
	ldr r0, [r1]
	adds r0, r0, r6
	strb r5, [r0]
	ldr r0, [r1]
	subs r2, #4
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
_0801D736:
	ldr r0, _0801D754 @ =0x020314E0
	ldr r0, [r0]
	ldr r5, _0801D758 @ =0x000002FD
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrh r5, [r1]
	adds r1, r3, #4
	adds r0, r0, r1
	b _0801D92C
	.align 2, 0
_0801D754: .4byte 0x020314E0
_0801D758: .4byte 0x000002FD
_0801D75C: .4byte 0x000002FB
_0801D760:
	ldr r4, _0801D7B0 @ =0x020314E0
	ldr r1, [r4]
	ldr r7, _0801D7B4 @ =0x000002FE
	adds r2, r1, r7
	movs r0, #0
	strh r0, [r2]
	ldr r3, _0801D7B8 @ =0x000002FD
	adds r1, r1, r3
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801D7BC @ =0x000002FB
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _0801D7C0 @ =0x086AD7C0
	ldr r0, [r4]
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r0, #0xcf
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	ldr r0, _0801D7C4 @ =0x000186A0
	str r0, [r1, #0x3c]
	b _0801D930
	.align 2, 0
_0801D7B0: .4byte 0x020314E0
_0801D7B4: .4byte 0x000002FE
_0801D7B8: .4byte 0x000002FD
_0801D7BC: .4byte 0x000002FB
_0801D7C0: .4byte 0x086AD7C0
_0801D7C4: .4byte 0x000186A0
_0801D7C8:
	ldr r2, _0801D7F4 @ =0x086AD7C0
	ldr r5, _0801D7F8 @ =0x020314E0
	ldr r3, [r5]
	ldr r7, _0801D7FC @ =0x000002FD
	adds r4, r3, r7
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, _0801D800 @ =0x000002FE
	adds r3, r3, r2
	ldrh r1, [r3]
	cmp r0, r1
	ble _0801D804
	adds r0, r1, #1
	strh r0, [r3]
	b _0801D82C
	.align 2, 0
_0801D7F4: .4byte 0x086AD7C0
_0801D7F8: .4byte 0x020314E0
_0801D7FC: .4byte 0x000002FD
_0801D800: .4byte 0x000002FE
_0801D804:
	movs r0, #0
	strh r0, [r3]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, [r5]
	ldr r3, _0801D84C @ =0x000002FD
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x12
	bne _0801D82C
	ldr r5, _0801D850 @ =0x000002FB
	adds r1, r1, r5
	movs r0, #5
	strb r0, [r1]
	movs r0, #0xd1
	bl m4aSongNumStart
_0801D82C:
	ldr r4, _0801D854 @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0801D858 @ =0x000002FE
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #6
	bne _0801D840
	movs r0, #0xd0
	bl m4aSongNumStart
_0801D840:
	ldr r2, _0801D85C @ =0x086AD7C0
	ldr r0, [r4]
	ldr r1, _0801D84C @ =0x000002FD
	adds r0, r0, r1
	b _0801D91A
	.align 2, 0
_0801D84C: .4byte 0x000002FD
_0801D850: .4byte 0x000002FB
_0801D854: .4byte 0x020314E0
_0801D858: .4byte 0x000002FE
_0801D85C: .4byte 0x086AD7C0
_0801D860:
	ldr r3, _0801D88C @ =0x086AD7C0
	ldr r5, _0801D890 @ =0x020314E0
	ldr r2, [r5]
	ldr r7, _0801D894 @ =0x000002FD
	adds r4, r2, r7
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _0801D898 @ =0x000002FE
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801D89C
	adds r0, r1, #1
	strh r0, [r2]
	b _0801D8BA
	.align 2, 0
_0801D88C: .4byte 0x086AD7C0
_0801D890: .4byte 0x020314E0
_0801D894: .4byte 0x000002FD
_0801D898: .4byte 0x000002FE
_0801D89C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r7, _0801D8D8 @ =0x020314E0
	ldr r0, [r7]
	ldr r2, _0801D8DC @ =0x000002FD
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x18
	bne _0801D8BA
	movs r0, #0x12
	strb r0, [r1]
_0801D8BA:
	ldr r0, _0801D8D8 @ =0x020314E0
	ldr r0, [r0]
	ldr r5, _0801D8DC @ =0x000002FD
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrh r5, [r1]
	adds r1, r3, #4
	adds r0, r0, r1
	b _0801D92C
	.align 2, 0
_0801D8D8: .4byte 0x020314E0
_0801D8DC: .4byte 0x000002FD
_0801D8E0:
	ldr r4, _0801DA3C @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0801DA40 @ =0x000002FA
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _0801DA44 @ =0x000002F9
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0801DA48 @ =0x000002FE
	adds r2, r0, r3
	movs r5, #0
	strh r1, [r2]
	subs r3, #1
	adds r0, r0, r3
	strb r5, [r0]
	ldr r0, [r4]
	adds r7, #1
	adds r0, r0, r7
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, r0, r3
	movs r1, #0x18
	strb r1, [r0]
	ldr r2, _0801DA4C @ =0x086AD7C0
	ldr r0, [r4]
	adds r0, r0, r3
_0801D91A:
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
_0801D92C:
	ldrh r0, [r0]
	mov r8, r0
_0801D930:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801DA20
	ldr r2, _0801DA50 @ =0x086AD856
	ldr r3, _0801DA3C @ =0x020314E0
	ldr r4, [r3]
	ldr r7, _0801DA44 @ =0x000002F9
	adds r3, r4, r7
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #4]
	ldr r2, _0801DA54 @ =0x040000D4
	movs r3, #0xbf
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DA58 @ =0x0845710C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DA5C @ =0x06014380
	str r0, [r2, #4]
	ldr r0, _0801DA60 @ =0x80000130
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0
	lsls r1, r5, #0x10
	ldr r5, _0801DA64 @ =gOamBuffer
	mov ip, r5
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r6, r0, #2
	ldr r7, _0801DA68 @ =0xFFFFFE00
	mov sl, r7
_0801D9A6:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldr r5, _0801DA6C @ =0x086B2E64
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r7, [r2, #2]
	lsls r1, r7, #0x17
	lsrs r1, r1, #0x17
	mov r5, sb
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _0801DA70 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, sl
	ldrh r7, [r2, #2]
	ands r0, r7
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r1]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _0801D9A6
_0801DA20:
	ldr r7, _0801DA3C @ =0x020314E0
	ldr r0, [r7]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, r8
	strb r2, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DA3C: .4byte 0x020314E0
_0801DA40: .4byte 0x000002FA
_0801DA44: .4byte 0x000002F9
_0801DA48: .4byte 0x000002FE
_0801DA4C: .4byte 0x086AD7C0
_0801DA50: .4byte 0x086AD856
_0801DA54: .4byte 0x040000D4
_0801DA58: .4byte 0x0845710C
_0801DA5C: .4byte 0x06014380
_0801DA60: .4byte 0x80000130
_0801DA64: .4byte gOamBuffer
_0801DA68: .4byte 0xFFFFFE00
_0801DA6C: .4byte 0x086B2E64
_0801DA70: .4byte 0x000001FF

	thumb_func_start sub_1DA74
sub_1DA74: @ 0x0801DA74
	ldr r0, _0801DAB0 @ =0x020314E0
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	beq _0801DAD4
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _0801DAC6
	ldr r1, _0801DAB4 @ =0x000001A5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801DABC
	ldr r3, _0801DAB8 @ =0x000001AB
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	b _0801DAD4
	.align 2, 0
_0801DAB0: .4byte 0x020314E0
_0801DAB4: .4byte 0x000001A5
_0801DAB8: .4byte 0x000001AB
_0801DABC:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #3
	b _0801DAD2
_0801DAC6:
	cmp r0, #6
	beq _0801DAD4
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0
_0801DAD2:
	strb r0, [r1]
_0801DAD4:
	bx lr

	thumb_func_start sub_1DAD8
sub_1DAD8: @ 0x0801DAD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0801DB64 @ =0x0200E270
	mov r8, r0
	ldr r0, _0801DB68 @ =0x020314E0
	ldr r4, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r5, #0xf
	ldr r7, _0801DB6C @ =0x000002F1
	adds r3, r4, r7
	ldrb r2, [r3]
	ands r5, r1
	adds r1, r2, #0
	adds r7, r0, #0
	cmp r5, r1
	beq _0801DBAC
	ldr r6, _0801DB70 @ =0x000002F2
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801DB78
	cmp r0, #5
	bne _0801DB58
	ldr r3, _0801DB74 @ =0xFFFFCE50
	add r3, r8
	ldrb r1, [r3, #0xf]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r3, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r3, #0
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	adds r0, #8
	strh r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldr r0, [r7]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r3, [r0]
	movs r0, #0xbd
	bl m4aSongNumStart
_0801DB58:
	ldr r1, [r7]
	adds r1, r1, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _0801DBAC
	.align 2, 0
_0801DB64: .4byte 0x0200E270
_0801DB68: .4byte 0x020314E0
_0801DB6C: .4byte 0x000002F1
_0801DB70: .4byte 0x000002F2
_0801DB74: .4byte 0xFFFFCE50
_0801DB78:
	cmp r1, r5
	bls _0801DB80
	subs r0, r2, #1
	b _0801DB82
_0801DB80:
	adds r0, r2, #1
_0801DB82:
	strb r0, [r3]
	ldr r0, [r7]
	adds r0, r0, r6
	movs r1, #4
	strh r1, [r0]
	ldr r2, _0801DC58 @ =0x040000D4
	ldr r0, [r7]
	ldr r1, _0801DC5C @ =0x000002F1
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DC60 @ =0x084ED0CC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DC64 @ =0x06013180
	str r0, [r2, #4]
	ldr r0, _0801DC68 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801DBAC:
	ldr r2, [r7]
	ldr r7, _0801DC5C @ =0x000002F1
	adds r0, r2, r7
	ldrb r0, [r0]
	movs r3, #2
	cmp r0, #2
	bhi _0801DBBC
	movs r3, #3
_0801DBBC:
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xd0
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x50
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r0, #0
	ldr r7, _0801DC6C @ =0x0200E278
	mov sl, r7
	ldr r6, _0801DC70 @ =gOamBuffer
	lsls r3, r3, #2
	str r3, [sp]
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
	ldr r2, _0801DC74 @ =0xFFFFFE00
	mov ip, r2
_0801DBEE:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	add r5, sl
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sb
	ands r0, r2
	ldr r7, [sp]
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0801DC78 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, r8
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801DBEE
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DC58: .4byte 0x040000D4
_0801DC5C: .4byte 0x000002F1
_0801DC60: .4byte 0x084ED0CC
_0801DC64: .4byte 0x06013180
_0801DC68: .4byte 0x800000C0
_0801DC6C: .4byte 0x0200E278
_0801DC70: .4byte gOamBuffer
_0801DC74: .4byte 0xFFFFFE00
_0801DC78: .4byte 0x000001FF

	thumb_func_start sub_1DC7C
sub_1DC7C: @ 0x0801DC7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r6, _0801DD7C @ =0x0200E100
	ldr r2, _0801DD80 @ =0x020314E0
	ldr r3, [r2]
	ldr r1, _0801DD84 @ =0x000002A5
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801DD88 @ =0x086AD862
	adds r4, r0, r1
	ldrh r0, [r6]
	mov sb, r2
	cmp r0, #0
	bne _0801DCA4
	b _0801DDCC
_0801DCA4:
	ldrh r2, [r4]
	mov r8, r2
	ldr r2, _0801DD8C @ =0x040000D4
	adds r0, r3, #0
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801DD90 @ =0x081379D8
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DD94 @ =0x05000320
	str r0, [r2, #4]
	ldr r0, _0801DD98 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r0, r8
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DD9C @ =0x084B7FEC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DDA0 @ =0x06014680
	str r0, [r2, #4]
	ldr r0, _0801DDA4 @ =0x80000230
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, _0801DDA8 @ =0x0000FF08
	strh r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0801DDAC @ =0x0000FEC4
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x7c
	adds r1, r3, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #6]
	adds r0, #0x96
	adds r1, r3, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0801DDB0 @ =gOamBuffer
	ldr r1, _0801DDB4 @ =0xFFFFFE00
	mov ip, r1
_0801DD1C:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801DDB8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _0801DD1C
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	beq _0801DD6E
	cmp r0, #0xa
	bne _0801DDC0
_0801DD6E:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, _0801DDBC @ =0x000002A3
	adds r0, r0, r1
	movs r1, #0
	b _0801DDCA
	.align 2, 0
_0801DD7C: .4byte 0x0200E100
_0801DD80: .4byte 0x020314E0
_0801DD84: .4byte 0x000002A5
_0801DD88: .4byte 0x086AD862
_0801DD8C: .4byte 0x040000D4
_0801DD90: .4byte 0x081379D8
_0801DD94: .4byte 0x05000320
_0801DD98: .4byte 0x80000010
_0801DD9C: .4byte 0x084B7FEC
_0801DDA0: .4byte 0x06014680
_0801DDA4: .4byte 0x80000230
_0801DDA8: .4byte 0x0000FF08
_0801DDAC: .4byte 0x0000FEC4
_0801DDB0: .4byte gOamBuffer
_0801DDB4: .4byte 0xFFFFFE00
_0801DDB8: .4byte 0x000001FF
_0801DDBC: .4byte 0x000002A3
_0801DDC0:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, _0801DDD8 @ =0x000002A3
	adds r0, r0, r1
	movs r1, #1
_0801DDCA:
	strb r1, [r0]
_0801DDCC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DDD8: .4byte 0x000002A3

	thumb_func_start sub_1DDDC
sub_1DDDC: @ 0x0801DDDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, _0801DE70 @ =0x020314E0
	ldr r4, [r1]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	ldrsb r3, [r0, r3]
	mov sl, r1
	cmp r3, #0
	bne _0801DDFE
	b _0801E518
_0801DDFE:
	movs r0, #0x13
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _0801DE0E
	ldr r3, _0801DE74 @ =0x0000016F
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0801DE0E:
	mov r4, sl
	ldr r1, [r4]
	ldr r3, _0801DE74 @ =0x0000016F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801DE4E
	ldr r5, _0801DE78 @ =0x000002A2
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _0801DE44
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801DE7C @ =0x000002A5
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _0801DE80 @ =0x000002A6
	adds r0, r0, r4
	strh r2, [r0]
_0801DE44:
	mov r5, sl
	ldr r0, [r5]
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
_0801DE4E:
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _0801DE78 @ =0x000002A2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bls _0801DE64
	bl _0801E780
_0801DE64:
	lsls r0, r0, #2
	ldr r1, _0801DE84 @ =_0801DE88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DE70: .4byte 0x020314E0
_0801DE74: .4byte 0x0000016F
_0801DE78: .4byte 0x000002A2
_0801DE7C: .4byte 0x000002A5
_0801DE80: .4byte 0x000002A6
_0801DE84: .4byte _0801DE88
_0801DE88: @ jump table
	.4byte _0801DEB4 @ case 0
	.4byte _0801DF2C @ case 1
	.4byte _0801DF68 @ case 2
	.4byte _0801DFC0 @ case 3
	.4byte _0801E0D0 @ case 4
	.4byte _0801E174 @ case 5
	.4byte _0801E1B4 @ case 6
	.4byte _0801E2F8 @ case 7
	.4byte _0801E34C @ case 8
	.4byte _0801E44C @ case 9
	.4byte _0801E4CC @ case 10
_0801DEB4:
	ldr r1, _0801DF18 @ =0x086AD862
	ldr r4, _0801DF1C @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801DF20 @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801DF24 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801DED8
	b _0801E46E
_0801DED8:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	ldr r2, _0801DF20 @ =0x000002A5
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801DEFA
	ldr r3, _0801DF28 @ =0x000002A2
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
_0801DEFA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801DF0C
	bl _0801E780
_0801DF0C:
	movs r0, #0xd3
	bl m4aSongNumStart
	bl _0801E780
	.align 2, 0
_0801DF18: .4byte 0x086AD862
_0801DF1C: .4byte 0x020314E0
_0801DF20: .4byte 0x000002A5
_0801DF24: .4byte 0x000002A6
_0801DF28: .4byte 0x000002A2
_0801DF2C:
	ldr r6, _0801DF5C @ =0x020314E0
	ldr r4, [r6]
	ldr r5, _0801DF60 @ =0x000002A6
	adds r0, r4, r5
	ldrh r0, [r0]
	movs r1, #0x2c
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x16
	bl __udivsi3
	adds r0, #4
	ldr r1, _0801DF64 @ =0x000002A5
	adds r4, r4, r1
	strb r0, [r4]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl _0801E780
	.align 2, 0
_0801DF5C: .4byte 0x020314E0
_0801DF60: .4byte 0x000002A6
_0801DF64: .4byte 0x000002A5
_0801DF68:
	ldr r2, _0801DFA8 @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _0801DFAC @ =0x000002A5
	adds r0, r0, r3
	movs r3, #0
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	ldr r4, _0801DFB0 @ =0x000002A6
	adds r0, r1, r4
	movs r4, #0
	strh r3, [r0]
	ldr r5, _0801DFB4 @ =0x000002A2
	adds r1, r1, r5
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, _0801DFB8 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	strb r4, [r0, #1]
	ldr r1, [r2]
	ldr r0, _0801DFBC @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, #0xd5
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	bl _0801E780
	.align 2, 0
_0801DFA8: .4byte 0x020314E0
_0801DFAC: .4byte 0x000002A5
_0801DFB0: .4byte 0x000002A6
_0801DFB4: .4byte 0x000002A2
_0801DFB8: .4byte 0x0000132C
_0801DFBC: .4byte 0x00001388
_0801DFC0:
	ldr r1, _0801DFE8 @ =0x086AD862
	ldr r4, _0801DFEC @ =0x020314E0
	ldr r2, [r4]
	ldr r6, _0801DFF0 @ =0x000002A5
	adds r3, r2, r6
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r5, _0801DFF4 @ =0x000002A6
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801DFF8
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E038
	.align 2, 0
_0801DFE8: .4byte 0x086AD862
_0801DFEC: .4byte 0x020314E0
_0801DFF0: .4byte 0x000002A5
_0801DFF4: .4byte 0x000002A6
_0801DFF8:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E0C0 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xd
	bne _0801E024
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, [r4]
	adds r2, r1, r5
	movs r0, #0x41
	strh r0, [r2]
	ldr r3, _0801E0C4 @ =0x000002A2
	adds r1, r1, r3
	movs r0, #4
	strb r0, [r1]
_0801E024:
	ldr r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _0801E038
	movs r0, #0xd4
	bl m4aSongNumStart
_0801E038:
	ldr r5, _0801E0C8 @ =0x020314E0
	ldr r2, [r5]
	ldr r4, _0801E0C0 @ =0x000002A5
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801E070
	ldr r0, _0801E0CC @ =0x0000132C
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	adds r0, #0x40
	movs r3, #0
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x89
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xbd
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
_0801E070:
	ldr r2, [r5]
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801E0A4
	ldr r1, _0801E0CC @ =0x0000132C
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	adds r0, #0x40
	movs r3, #0
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x8c
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xb7
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
_0801E0A4:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	beq _0801E0B4
	b _0801E780
_0801E0B4:
	ldr r2, _0801E0CC @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1]
	b _0801E780
	.align 2, 0
_0801E0C0: .4byte 0x000002A5
_0801E0C4: .4byte 0x000002A2
_0801E0C8: .4byte 0x020314E0
_0801E0CC: .4byte 0x0000132C
_0801E0D0:
	ldr r5, _0801E154 @ =0x020314E0
	ldr r0, [r5]
	movs r3, #0x88
	lsls r3, r3, #5
	adds r0, r0, r3
	movs r7, #1
	strb r7, [r0]
	ldr r0, [r5]
	ldr r6, _0801E158 @ =0x000002A6
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x41
	bne _0801E0F8
	movs r0, #0x9f
	bl m4aSongNumStart
	ldr r0, _0801E15C @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0x9e
	strh r1, [r0, #0x38]
_0801E0F8:
	ldr r4, [r5]
	adds r3, r4, r6
	ldrh r0, [r3]
	cmp r0, #0
	bne _0801E104
	b _0801E780
_0801E104:
	subs r0, #1
	strh r0, [r3]
	ldr r2, _0801E15C @ =gMain
	ldrh r0, [r3]
	lsrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r2, #0x3c]
	strh r1, [r2, #0x3c]
	ldrh r0, [r3]
	cmp r0, #0
	beq _0801E11E
	b _0801E780
_0801E11E:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0801E160 @ =0x00000282
	adds r0, r0, r1
	strb r7, [r0]
	ldr r0, [r5]
	ldr r2, _0801E164 @ =0x0000072E
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0801E168 @ =0x0000073C
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _0801E16C @ =0x0000072F
	adds r1, r0, r4
	ldrb r1, [r1]
	ldr r5, _0801E170 @ =0x0000073D
	adds r0, r0, r5
	strb r1, [r0]
	bl sub_1C73C
	b _0801E780
	.align 2, 0
_0801E154: .4byte 0x020314E0
_0801E158: .4byte 0x000002A6
_0801E15C: .4byte gMain
_0801E160: .4byte 0x00000282
_0801E164: .4byte 0x0000072E
_0801E168: .4byte 0x0000073C
_0801E16C: .4byte 0x0000072F
_0801E170: .4byte 0x0000073D
_0801E174:
	ldr r2, _0801E1A0 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _0801E1A4 @ =0x000002A5
	adds r0, r0, r1
	movs r3, #0
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r2]
	ldr r4, _0801E1A8 @ =0x000002A6
	adds r0, r1, r4
	movs r4, #0
	strh r3, [r0]
	ldr r5, _0801E1AC @ =0x000002A2
	adds r1, r1, r5
	movs r0, #6
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, _0801E1B0 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	strb r4, [r0, #1]
	b _0801E780
	.align 2, 0
_0801E1A0: .4byte 0x020314E0
_0801E1A4: .4byte 0x000002A5
_0801E1A8: .4byte 0x000002A6
_0801E1AC: .4byte 0x000002A2
_0801E1B0: .4byte 0x0000132C
_0801E1B4:
	ldr r1, _0801E1DC @ =0x086AD862
	ldr r4, _0801E1E0 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801E1E4 @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E1E8 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E1EC
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E28A
	.align 2, 0
_0801E1DC: .4byte 0x086AD862
_0801E1E0: .4byte 0x020314E0
_0801E1E4: .4byte 0x000002A5
_0801E1E8: .4byte 0x000002A6
_0801E1EC:
	movs r6, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E2E4 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x1f
	bne _0801E212
	strb r6, [r1]
	ldr r0, [r4]
	ldr r3, _0801E2E8 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E212:
	ldr r2, [r4]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _0801E24E
	ldr r0, _0801E2EC @ =0x0000132C
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	subs r0, #0x40
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xc7
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r1, [r2]
	ldr r0, _0801E2F0 @ =0x0000FF88
	strh r0, [r1, #0x30]
	ldr r1, [r2]
	movs r0, #0xd2
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	movs r0, #3
	strb r0, [r1, #1]
_0801E24E:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bne _0801E262
	movs r0, #0xd3
	bl m4aSongNumStart
_0801E262:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1b
	bne _0801E276
	movs r0, #0xd4
	bl m4aSongNumStart
_0801E276:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801E2CA
	movs r0, #0xd6
	bl m4aSongNumStart
_0801E28A:
	ldr r1, _0801E2F4 @ =0x020314E0
	ldr r3, [r1]
	ldr r2, _0801E2E4 @ =0x000002A5
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801E2CA
	ldr r2, _0801E2EC @ =0x0000132C
	adds r0, r3, r2
	ldr r0, [r0]
	movs r3, #0
	strb r3, [r0]
	ldr r1, [r1]
	adds r1, r1, r2
	ldr r2, [r1]
	ldrh r0, [r2, #0xa]
	subs r0, #0x40
	strh r0, [r2, #0xa]
	ldr r2, [r1]
	movs r0, #0x85
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r2, [r1]
	movs r0, #0xc0
	lsls r0, r0, #8
	str r0, [r2, #0x38]
	ldr r0, [r1]
	strh r3, [r0, #0x30]
	ldr r0, [r1]
	strh r3, [r0, #0x32]
_0801E2CA:
	ldr r0, _0801E2F4 @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _0801E2E4 @ =0x000002A5
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x16
	beq _0801E2DE
	b _0801E780
_0801E2DE:
	movs r0, #0
	strb r0, [r1, #0x1f]
	b _0801E780
	.align 2, 0
_0801E2E4: .4byte 0x000002A5
_0801E2E8: .4byte 0x000002A2
_0801E2EC: .4byte 0x0000132C
_0801E2F0: .4byte 0x0000FF88
_0801E2F4: .4byte 0x020314E0
_0801E2F8:
	ldr r4, _0801E33C @ =0x020314E0
	ldr r0, [r4]
	ldr r5, _0801E340 @ =0x000002A5
	adds r0, r0, r5
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0801E344 @ =0x000002A6
	adds r1, r0, r3
	strh r2, [r1]
	subs r5, #3
	adds r0, r0, r5
	movs r1, #8
	strb r1, [r0]
	ldr r1, [r4]
	movs r0, #0xa
	str r0, [r1, #0x3c]
	movs r0, #0xb6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r0, [r4]
	ldr r2, _0801E348 @ =0x00000724
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _0801E336
	b _0801E780
_0801E336:
	movs r0, #1
	strh r0, [r1]
	b _0801E780
	.align 2, 0
_0801E33C: .4byte 0x020314E0
_0801E340: .4byte 0x000002A5
_0801E344: .4byte 0x000002A6
_0801E348: .4byte 0x00000724
_0801E34C:
	ldr r1, _0801E374 @ =0x086AD862
	ldr r4, _0801E378 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801E37C @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E380 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E384
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E3D4
	.align 2, 0
_0801E374: .4byte 0x086AD862
_0801E378: .4byte 0x020314E0
_0801E37C: .4byte 0x000002A5
_0801E380: .4byte 0x000002A6
_0801E384:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E430 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x2e
	bne _0801E3AA
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801E434 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E3AA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x2a
	bne _0801E3BE
	movs r0, #0xd4
	bl m4aSongNumStart
_0801E3BE:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x21
	bne _0801E3D4
	movs r0, #0xa6
	lsls r0, r0, #1
	bl m4aSongNumStart
_0801E3D4:
	ldr r6, _0801E438 @ =0x020314E0
	ldr r4, [r6]
	ldr r5, _0801E430 @ =0x000002A5
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x2d
	beq _0801E3E8
	b _0801E780
_0801E3E8:
	ldr r3, _0801E43C @ =0x086AD9EC
	adds r5, #1
	adds r2, r4, r5
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r3, _0801E440 @ =0x000002AA
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0801E412
	ldr r0, _0801E444 @ =0x02032FB0
	ldr r1, _0801E448 @ =0x086A0F30
	bl MPlayStart
_0801E412:
	ldr r0, [r6]
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0801E426
	b _0801E780
_0801E426:
	movs r0, #0xc
	bl sub_11B0
	b _0801E780
	.align 2, 0
_0801E430: .4byte 0x000002A5
_0801E434: .4byte 0x000002A2
_0801E438: .4byte 0x020314E0
_0801E43C: .4byte 0x086AD9EC
_0801E440: .4byte 0x000002AA
_0801E444: .4byte 0x02032FB0
_0801E448: .4byte 0x086A0F30
_0801E44C:
	ldr r1, _0801E474 @ =0x086AD862
	ldr r4, _0801E478 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801E47C @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E480 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E484
_0801E46E:
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E780
	.align 2, 0
_0801E474: .4byte 0x086AD862
_0801E478: .4byte 0x020314E0
_0801E47C: .4byte 0x000002A5
_0801E480: .4byte 0x000002A6
_0801E484:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E4C4 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xd
	bne _0801E4AA
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801E4C8 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E4AA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	beq _0801E4BA
	b _0801E780
_0801E4BA:
	movs r0, #0xd4
	bl m4aSongNumStart
	b _0801E780
	.align 2, 0
_0801E4C4: .4byte 0x000002A5
_0801E4C8: .4byte 0x000002A2
_0801E4CC:
	ldr r2, _0801E508 @ =0x020314E0
	ldr r0, [r2]
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r3, #0
	strb r3, [r0]
	ldr r0, [r2]
	ldr r5, _0801E50C @ =0x000002A5
	adds r0, r0, r5
	strb r3, [r0]
	ldr r1, [r2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldr r5, _0801E510 @ =0x0000016F
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0x40
	strh r1, [r2]
	ldr r2, _0801E514 @ =0x000002AA
	adds r0, r0, r2
	strh r3, [r0]
	b _0801E780
	.align 2, 0
_0801E508: .4byte 0x020314E0
_0801E50C: .4byte 0x000002A5
_0801E510: .4byte 0x0000016F
_0801E514: .4byte 0x000002AA
_0801E518:
	ldr r5, _0801E560 @ =0x0000016F
	adds r1, r4, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _0801E526
	b _0801E780
_0801E526:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0x8f
	bhi _0801E56C
	ldr r1, _0801E564 @ =0x08137968
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	mov r3, sl
	ldr r2, [r3]
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r4, _0801E568 @ =0x00000171
	adds r2, r2, r4
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, r1
	ldrb r1, [r1]
	adds r5, #3
	adds r0, r0, r5
	strb r1, [r0]
	b _0801E56E
	.align 2, 0
_0801E560: .4byte 0x0000016F
_0801E564: .4byte 0x08137968
_0801E568: .4byte 0x00000171
_0801E56C:
	strb r3, [r1]
_0801E56E:
	mov r0, sl
	ldr r4, [r0]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	beq _0801E584
	b _0801E6C4
_0801E584:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0801E596
	b _0801E6C4
_0801E596:
	lsrs r0, r1, #3
	cmp r0, #8
	beq _0801E59E
	b _0801E6C4
_0801E59E:
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _0801E5BA
	movs r0, #0x13
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _0801E5E8
_0801E5BA:
	ldr r0, _0801E5E4 @ =gMain
	ldr r5, [r0, #0x4c]
	adds r0, r5, #0
	movs r1, #5
	bl __umodsi3
	adds r0, #1
	lsls r0, r0, #0x10
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r4, r4, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bne _0801E61C
	adds r0, r5, #1
	movs r1, #5
	b _0801E60E
	.align 2, 0
_0801E5E4: .4byte gMain
_0801E5E8:
	ldr r0, _0801E618 @ =gMain
	ldr r5, [r0, #0x4c]
	adds r0, r5, #0
	movs r1, #6
	bl __umodsi3
	adds r0, #1
	lsls r0, r0, #0x10
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r4, r4, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bne _0801E61C
	adds r0, r5, #1
	movs r1, #6
_0801E60E:
	bl __umodsi3
	adds r0, #1
	strb r0, [r4]
	b _0801E61E
	.align 2, 0
_0801E618: .4byte gMain
_0801E61C:
	strb r2, [r4]
_0801E61E:
	mov r3, sl
	ldr r0, [r3]
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0801E640
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r3]
	movs r5, #0xb6
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r1, #6
	strb r1, [r0]
_0801E640:
	mov r0, sl
	ldr r1, [r0]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801E68E
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r5, sl
	ldr r0, [r5]
	ldr r1, _0801E700 @ =0x000002A2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r1, r0, r2
	movs r2, #0
	strh r3, [r1]
	ldr r5, _0801E704 @ =0x000002A5
	adds r0, r0, r5
	strb r2, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r5, _0801E708 @ =0x0000016F
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r3, [r0]
_0801E68E:
	mov r2, sl
	ldr r3, [r2]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _0801E6C4
	ldr r2, _0801E70C @ =0x086AD9DC
	movs r4, #0
	ldrsh r1, [r2, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
_0801E6C4:
	ldr r5, _0801E710 @ =0x020314E0
	ldr r1, [r5]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bne _0801E6E2
	movs r0, #0xc9
	bl m4aSongNumStart
_0801E6E2:
	ldr r1, [r5]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0801E742
	cmp r0, #4
	ble _0801E714
	cmp r0, #5
	beq _0801E772
	b _0801E780
	.align 2, 0
_0801E700: .4byte 0x000002A2
_0801E704: .4byte 0x000002A5
_0801E708: .4byte 0x0000016F
_0801E70C: .4byte 0x086AD9DC
_0801E710: .4byte 0x020314E0
_0801E714:
	cmp r0, #0
	blt _0801E780
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x66
	bne _0801E726
	movs r0, #0xc8
	bl m4aSongNumStart
_0801E726:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x74
	bne _0801E736
	movs r0, #0xc8
	bl m4aSongNumStart
_0801E736:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	bne _0801E780
	b _0801E76A
_0801E742:
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x66
	bne _0801E750
	movs r0, #0xc8
	bl m4aSongNumStart
_0801E750:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x76
	bne _0801E760
	movs r0, #0xc8
	bl m4aSongNumStart
_0801E760:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x86
	bne _0801E780
_0801E76A:
	movs r0, #0xc8
	bl m4aSongNumStart
	b _0801E780
_0801E772:
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x68
	bne _0801E780
	movs r0, #0xc8
	bl m4aSongNumStart
_0801E780:
	ldr r1, _0801E7A4 @ =0x020314E0
	ldr r0, [r1]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sl, r1
	cmp r0, #6
	bls _0801E798
	b _0801EC32
_0801E798:
	lsls r0, r0, #2
	ldr r1, _0801E7A8 @ =_0801E7AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E7A4: .4byte 0x020314E0
_0801E7A8: .4byte _0801E7AC
_0801E7AC: @ jump table
	.4byte _0801E7C8 @ case 0
	.4byte _0801E814 @ case 1
	.4byte _0801E8D0 @ case 2
	.4byte _0801E998 @ case 3
	.4byte _0801EA50 @ case 4
	.4byte _0801EB00 @ case 5
	.4byte _0801EC00 @ case 6
_0801E7C8:
	mov r5, sl
	ldr r2, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0801E80C @ =0x000004E2
	strh r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r1, r2, r3
	adds r0, #0x14
	strh r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r1]
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r1, r2, r5
	subs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0801E810 @ =0x0000055A
	strh r0, [r1]
	adds r3, #4
	adds r1, r2, r3
	adds r0, #0xf0
	strh r0, [r1]
	b _0801EC32
	.align 2, 0
_0801E80C: .4byte 0x000004E2
_0801E810: .4byte 0x0000055A
_0801E814:
	movs r6, #0
	ldr r4, _0801E8C0 @ =0x020314E0
	mov sb, r4
	movs r5, #0xc8
	lsls r5, r5, #1
	mov r8, r5
	ldr r0, _0801E8C4 @ =0x00004E20
	mov sl, r0
_0801E824:
	mov r1, sb
	ldr r4, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x7f
	ands r3, r0
	lsls r3, r3, #9
	lsls r1, r6, #0x10
	asrs r7, r1, #0x10
	lsls r6, r7, #2
	adds r1, r6, r7
	lsls r2, r1, #4
	adds r1, r1, r2
	lsls r2, r1, #8
	adds r1, r1, r2
	adds r3, r3, r1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	movs r1, #0x3c
	bl __umodsi3
	subs r0, #0x1e
	lsls r0, r0, #0x10
	mov r3, r8
	adds r1, r4, r3
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_C74
	mov r4, sb
	ldr r1, [r4]
	adds r4, r1, r6
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r3, _0801E8C8 @ =0x00000564
	adds r0, r0, r3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r4, r1
	strh r0, [r4]
	adds r0, r5, #0
	bl sub_C24
	mov r2, sb
	ldr r1, [r2]
	adds r4, r1, r6
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r5, _0801E8CC @ =0x000005DC
	adds r0, r0, r5
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0801E824
	b _0801EC32
	.align 2, 0
_0801E8C0: .4byte 0x020314E0
_0801E8C4: .4byte 0x00004E20
_0801E8C8: .4byte 0x00000564
_0801E8CC: .4byte 0x000005DC
_0801E8D0:
	movs r6, #0
	ldr r3, _0801E984 @ =0x020314E0
	mov sb, r3
	movs r4, #0xc8
	lsls r4, r4, #1
	mov r8, r4
	ldr r5, _0801E988 @ =0x00004E20
	mov sl, r5
_0801E8E0:
	mov r0, sb
	ldr r4, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x7f
	ands r3, r0
	lsls r3, r3, #9
	lsls r1, r6, #0x10
	asrs r7, r1, #0x10
	lsls r6, r7, #2
	adds r1, r6, r7
	lsls r2, r1, #4
	adds r1, r1, r2
	lsls r2, r1, #8
	adds r1, r1, r2
	adds r3, r3, r1
	ldr r2, _0801E98C @ =0x00002710
	adds r1, r2, #0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r1, #0x3c
	bl __umodsi3
	subs r0, #0x1e
	lsls r0, r0, #0x10
	mov r3, r8
	adds r1, r4, r3
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_C74
	mov r4, sb
	ldr r1, [r4]
	adds r4, r1, r6
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r3, _0801E990 @ =0x00000564
	adds r0, r0, r3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r4, r1
	strh r0, [r4]
	adds r0, r5, #0
	bl sub_C24
	mov r2, sb
	ldr r1, [r2]
	adds r4, r1, r6
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r5, _0801E994 @ =0x000005DC
	adds r0, r0, r5
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0801E8E0
	b _0801EC32
	.align 2, 0
_0801E984: .4byte 0x020314E0
_0801E988: .4byte 0x00004E20
_0801E98C: .4byte 0x00002710
_0801E990: .4byte 0x00000564
_0801E994: .4byte 0x000005DC
_0801E998:
	movs r6, #0
_0801E99A:
	mov r3, sl
	ldr r5, [r3]
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #0x2e
	bl __umodsi3
	movs r7, #0x17
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9C0
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0801E9C0:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, #1
	lsls r0, r2, #2
	adds r3, r5, r0
	lsls r0, r1, #5
	adds r0, r0, r1
	adds r0, #0x79
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r3, r5
	strh r1, [r0]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, _0801EA44 @ =0x0000053C
	adds r1, r1, r0
	movs r4, #0xbd
	lsls r4, r4, #1
	adds r3, r3, r4
	strh r1, [r3]
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0801E99A
	mov r0, sl
	ldr r5, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0x17
	movs r1, #0x2e
	bl __umodsi3
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801EA22
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0801EA22:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _0801EA48 @ =0x0000055A
	strh r0, [r1]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r3, _0801EA4C @ =0x00000654
	adds r1, r1, r3
	movs r4, #0xbd
	lsls r4, r4, #1
	adds r2, r5, r4
	strh r1, [r2]
	b _0801EC32
	.align 2, 0
_0801EA44: .4byte 0x0000053C
_0801EA48: .4byte 0x0000055A
_0801EA4C: .4byte 0x00000654
_0801EA50:
	mov r5, sl
	ldr r6, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0801EAE8 @ =0x000004BA
	strh r0, [r1]
	ldr r5, _0801EAEC @ =0x0813798C
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAF0 @ =0x00000514
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x14
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAF4 @ =0x00000582
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0801EAF8 @ =0x0000055A
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x28
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAFC @ =0x0000067C
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0801EC30
	.align 2, 0
_0801EAE8: .4byte 0x000004BA
_0801EAEC: .4byte 0x0813798C
_0801EAF0: .4byte 0x00000514
_0801EAF4: .4byte 0x00000582
_0801EAF8: .4byte 0x0000055A
_0801EAFC: .4byte 0x0000067C
_0801EB00:
	ldr r0, _0801EBF0 @ =0x086AD9DC
	mov r4, sl
	ldr r3, [r4]
	movs r5, #0xb7
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r5, #0xa
	adds r1, r3, r5
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r1, r0, r1
	str r1, [sp]
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xbd
	lsls r1, r1, #1
	mov sb, r1
	add r3, sb
	movs r2, #0
	ldrsh r1, [r3, r2]
	subs r1, r0, r1
	str r1, [sp, #4]
	ldr r4, [sp]
	adds r3, r4, #0
	muls r3, r4, r3
	mov r8, r3
	adds r0, r1, #0
	muls r0, r1, r0
	add r8, r0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r6, _0801EBF4 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #8]
	adds r0, r4, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #0xc]
	mov r0, sl
	ldr r1, [r0]
	adds r5, r1, r5
	ldrh r0, [r5]
	ldr r2, [sp, #8]
	adds r0, r2, r0
	movs r4, #0
	strh r0, [r5]
	add r1, sb
	ldrh r0, [r1]
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	strh r0, [r1]
	ldr r0, _0801EBF8 @ =0x000009C3
	cmp r8, r0
	bgt _0801EBCA
	bl sub_C00
	mov r5, sl
	ldr r2, [r5]
	movs r1, #3
	ands r1, r0
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
_0801EBCA:
	mov r5, sl
	ldr r2, [r5]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r4, [r0]
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, _0801EBFC @ =0x0000FED4
	strh r1, [r0]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r2, r5
	strh r4, [r0]
	adds r3, #4
	adds r0, r2, r3
	b _0801EC30
	.align 2, 0
_0801EBF0: .4byte 0x086AD9DC
_0801EBF4: .4byte 0x00004E20
_0801EBF8: .4byte 0x000009C3
_0801EBFC: .4byte 0x0000FED4
_0801EC00:
	mov r4, sl
	ldr r3, [r4]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r2, #0
	strh r2, [r0]
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, _0801EC44 @ =0x0000FED4
	strh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r2, [r0]
	adds r5, #6
	adds r0, r3, r5
	strh r1, [r0]
	adds r4, #4
	adds r0, r3, r4
	strh r2, [r0]
	adds r5, #4
	adds r0, r3, r5
_0801EC30:
	strh r1, [r0]
_0801EC32:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801EC44: .4byte 0x0000FED4

	thumb_func_start sub_1EC48
sub_1EC48: @ 0x0801EC48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0801ECAC @ =0x020314E0
	ldr r3, [r1]
	ldr r2, _0801ECB0 @ =0x00000624
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0801EC66
	b _0801EE4A
_0801EC66:
	cmp r0, #2
	beq _0801EC6C
	b _0801EE3C
_0801EC6C:
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r3, #0x3c]
	movs r0, #0xb6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r3, _0801ECAC @ =0x020314E0
	ldr r1, [r3]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	beq _0801EC8C
	b _0801EE1E
_0801EC8C:
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	beq _0801EC96
	b _0801EE1E
_0801EC96:
	ldr r5, _0801ECB4 @ =0x00000625
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	ble _0801ECA4
	b _0801EE1E
_0801ECA4:
	cmp r0, #0
	bne _0801ECB8
	movs r0, #1
	b _0801ECC2
	.align 2, 0
_0801ECAC: .4byte 0x020314E0
_0801ECB0: .4byte 0x00000624
_0801ECB4: .4byte 0x00000625
_0801ECB8:
	cmp r0, #1
	bne _0801ECC0
	movs r0, #3
	b _0801ECC2
_0801ECC0:
	movs r0, #6
_0801ECC2:
	strb r0, [r1]
	ldr r6, _0801ED70 @ =0x020314E0
	ldr r5, [r6]
	ldr r1, _0801ED74 @ =0x00000625
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #6
	beq _0801ECDA
	b _0801EE1E
_0801ECDA:
	ldr r2, _0801ED78 @ =0x000006C6
	adds r0, r5, r2
	movs r7, #0
	ldrsb r7, [r0, r7]
	cmp r7, #0
	beq _0801ECE8
	b _0801EE1E
_0801ECE8:
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #4
	bne _0801ED98
	ldr r2, _0801ED7C @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r0, r5, #0
	adds r0, #0xea
	movs r4, #0
	movs r3, #0x32
	strh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xec
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	subs r1, #4
	movs r0, #0xec
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xe6
	strh r7, [r0]
	adds r0, #8
	mov r1, r8
	strh r1, [r0]
	adds r0, #4
	mov r5, sb
	strb r5, [r0]
	ldr r0, [r6]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r6]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801ED80 @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r7, [r0]
	ldr r1, _0801ED84 @ =0x040000D4
	ldr r0, _0801ED88 @ =0x086ACEF8
	ldr r0, [r0, #0x18]
	str r0, [r1]
	ldr r0, _0801ED8C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801ED90 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801ED94 @ =0x086ACF18
	ldr r0, [r0, #0x18]
	b _0801EE0C
	.align 2, 0
_0801ED70: .4byte 0x020314E0
_0801ED74: .4byte 0x00000625
_0801ED78: .4byte 0x000006C6
_0801ED7C: .4byte gMain
_0801ED80: .4byte 0x0000F63C
_0801ED84: .4byte 0x040000D4
_0801ED88: .4byte 0x086ACEF8
_0801ED8C: .4byte 0x06015800
_0801ED90: .4byte 0x80001200
_0801ED94: .4byte 0x086ACF18
_0801ED98:
	ldr r2, _0801EEA8 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r0, r5, #0
	adds r0, #0xea
	movs r4, #0
	movs r3, #0x32
	strh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xec
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	subs r1, #4
	movs r0, #0xec
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xe6
	strh r7, [r0]
	adds r1, #6
	movs r0, #4
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xf2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfa
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r6]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801EEAC @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r7, [r0]
	ldr r1, _0801EEB0 @ =0x040000D4
	ldr r0, _0801EEB4 @ =0x086ACEF8
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r0, _0801EEB8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801EEBC @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801EEC0 @ =0x086ACF18
	ldr r0, [r0, #4]
_0801EE0C:
	str r0, [r1]
	ldr r0, _0801EEC4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801EEC8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_0801EE1E:
	ldr r2, _0801EECC @ =0x020314E0
	ldr r0, [r2]
	movs r6, #0xbb
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #0xc2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0801EE3C:
	ldr r2, _0801EECC @ =0x020314E0
	ldr r1, [r2]
	ldr r3, _0801EED0 @ =0x00000624
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801EE4A:
	ldr r5, _0801EED4 @ =0x0200E048
	mov sl, r5
	ldr r6, _0801EECC @ =0x020314E0
	ldr r0, [r6]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801EF4C
	movs r6, #0
	ldr r2, _0801EED8 @ =0x0844928C
	mov sb, r2
	ldr r3, _0801EECC @ =0x020314E0
	mov r8, r3
	movs r7, #0xb8
	lsls r7, r7, #1
	ldr r5, _0801EEB0 @ =0x040000D4
_0801EE72:
	mov r0, r8
	ldr r3, [r0]
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	adds r0, r3, r7
	adds r2, r0, r4
	ldrb r0, [r2]
	movs r1, #0
	ldrsb r1, [r2, r1]
	cmp r1, #0
	beq _0801EEE2
	cmp r1, #0x64
	ble _0801EEDC
	subs r0, #1
	movs r3, #0
	strb r0, [r2]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x64
	bne _0801EEA4
	strb r3, [r1]
_0801EEA4:
	movs r1, #8
	b _0801EEFA
	.align 2, 0
_0801EEA8: .4byte gMain
_0801EEAC: .4byte 0x0000F63C
_0801EEB0: .4byte 0x040000D4
_0801EEB4: .4byte 0x086ACEF8
_0801EEB8: .4byte 0x06015800
_0801EEBC: .4byte 0x80001200
_0801EEC0: .4byte 0x086ACF18
_0801EEC4: .4byte 0x050003C0
_0801EEC8: .4byte 0x80000010
_0801EECC: .4byte 0x020314E0
_0801EED0: .4byte 0x00000624
_0801EED4: .4byte 0x0200E048
_0801EED8: .4byte 0x0844928C
_0801EEDC:
	movs r0, #0
	ldrsb r0, [r2, r0]
	b _0801EEF6
_0801EEE2:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
_0801EEF6:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0801EEFA:
	lsls r0, r1, #0x10
	asrs r0, r0, #8
	add r0, sb
	str r0, [r5]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #8
	ldr r3, _0801EF38 @ =0x06012E80
	adds r0, r0, r3
	str r0, [r5, #4]
	ldr r0, _0801EF3C @ =0x80000080
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _0801EE72
	ldr r2, _0801EF40 @ =0x040000D4
	ldr r5, _0801EF44 @ =0x020314E0
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _0801EF48 @ =0x081379B8
	b _0801F006
	.align 2, 0
_0801EF38: .4byte 0x06012E80
_0801EF3C: .4byte 0x80000080
_0801EF40: .4byte 0x040000D4
_0801EF44: .4byte 0x020314E0
_0801EF48: .4byte 0x081379B8
_0801EF4C:
	movs r6, #0
	movs r0, #0xb8
	lsls r0, r0, #1
	mov sb, r0
	ldr r1, _0801EFA0 @ =0x040000D4
	mov r8, r1
_0801EF58:
	ldr r2, _0801EFA4 @ =0x020314E0
	ldr r1, [r2]
	lsls r0, r6, #0x10
	asrs r5, r0, #0x10
	mov r3, sb
	adds r0, r1, r3
	adds r4, r0, r5
	ldrb r7, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _0801EFAE
	cmp r0, #0x64
	ble _0801EFA8
	movs r1, #0x69
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #9
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	subs r0, r7, #1
	movs r3, #0
	strb r0, [r4]
	ldr r2, _0801EFA4 @ =0x020314E0
	ldr r0, [r2]
	add r0, sb
	adds r2, r0, r5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x64
	bne _0801EFC6
	strb r3, [r2]
	b _0801EFC6
	.align 2, 0
_0801EFA0: .4byte 0x040000D4
_0801EFA4: .4byte 0x020314E0
_0801EFA8:
	movs r0, #0
	ldrsb r0, [r4, r0]
	b _0801EFC2
_0801EFAE:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
_0801EFC2:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0801EFC6:
	lsls r0, r1, #0x10
	asrs r0, r0, #8
	ldr r5, _0801F128 @ =0x083C806C
	adds r0, r0, r5
	mov r1, r8
	str r0, [r1]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #8
	ldr r2, _0801F12C @ =0x06012E80
	adds r0, r0, r2
	mov r3, r8
	str r0, [r3, #4]
	ldr r0, _0801F130 @ =0x80000080
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _0801EF58
	ldr r2, _0801F134 @ =0x040000D4
	ldr r5, _0801F138 @ =0x020314E0
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _0801F13C @ =0x08137998
_0801F006:
	adds r0, r0, r6
	str r0, [r2]
	ldr r0, _0801F140 @ =0x05000320
	str r0, [r2, #4]
	ldr r0, _0801F144 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r6, #0
_0801F016:
	ldr r0, _0801F138 @ =0x020314E0
	ldr r4, [r0]
	lsls r6, r6, #0x10
	asrs r1, r6, #0x10
	mov sb, r1
	lsls r0, r1, #2
	adds r7, r4, r0
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	mov r1, sl
	strh r0, [r1, #2]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r0, #4
	mov r1, sl
	strh r0, [r1, #4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #8
	lsls r0, r0, #1
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r5, r8
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #7
	lsls r0, r0, #1
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	mov r3, sl
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r0, #0x28
	rsbs r0, r0, #0
	mov r8, r6
	cmp r1, r0
	bge _0801F0AE
	ldr r0, _0801F148 @ =0x0000FFD8
	strh r0, [r3, #4]
_0801F0AE:
	movs r0, #0
	mov r6, sb
	lsls r6, r6, #1
	mov ip, r6
	ldr r7, _0801F14C @ =gOamBuffer
	ldr r1, _0801F150 @ =0xFFFFFE00
	mov sb, r1
_0801F0BC:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	mov r3, ip
	adds r2, r4, r3
	lsls r2, r2, #3
	adds r2, #8
	add r2, sl
	ldrh r3, [r2]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r5, #2
	ldrsh r1, [r2, r5]
	mov r6, sl
	movs r5, #2
	ldrsh r0, [r6, r5]
	adds r1, r1, r0
	ldr r6, _0801F154 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r5, [r3, #2]
	mov r0, sb
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r2]
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r2, [r2, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801F0BC
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0801F118
	b _0801F016
_0801F118:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F128: .4byte 0x083C806C
_0801F12C: .4byte 0x06012E80
_0801F130: .4byte 0x80000080
_0801F134: .4byte 0x040000D4
_0801F138: .4byte 0x020314E0
_0801F13C: .4byte 0x08137998
_0801F140: .4byte 0x05000320
_0801F144: .4byte 0x80000010
_0801F148: .4byte 0x0000FFD8
_0801F14C: .4byte gOamBuffer
_0801F150: .4byte 0xFFFFFE00
_0801F154: .4byte 0x000001FF

	thumb_func_start sub_1F158
sub_1F158: @ 0x0801F158
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0801F270 @ =gMain
	ldr r0, [r4, #0x4c]
	movs r1, #0x37
	bl __umodsi3
	movs r1, #0xb
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0801F274 @ =0x00002ED0
	adds r7, r4, r0
	ldr r2, _0801F278 @ =0x040000D4
	ldr r6, _0801F27C @ =0x020314E0
	ldr r3, [r6]
	ldr r0, _0801F280 @ =0x000002F5
	adds r4, r3, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801F284 @ =0x084F5ACC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F288 @ =0x06012C20
	str r0, [r2, #4]
	ldr r0, _0801F28C @ =0x80000130
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r3, r3, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _0801F1B4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0801F1B4:
	ldr r2, _0801F290 @ =0x086AD9FC
	lsls r0, r5, #0x10
	asrs r0, r0, #0xe
	adds r1, r0, r2
	ldrh r3, [r1]
	adds r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xb3
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0xae
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldr r5, _0801F294 @ =0x086B3A04
	mov sb, r5
	ldr r6, _0801F298 @ =gOamBuffer
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #1
	mov ip, r0
	ldr r0, _0801F29C @ =0xFFFFFE00
	mov r8, r0
_0801F1F6:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r5, [r2, #2]
	mov sl, r5
	mov r0, sl
	lsls r1, r0, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _0801F2A0 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	mov r5, sl
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0801F1F6
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F270: .4byte gMain
_0801F274: .4byte 0x00002ED0
_0801F278: .4byte 0x040000D4
_0801F27C: .4byte 0x020314E0
_0801F280: .4byte 0x000002F5
_0801F284: .4byte 0x084F5ACC
_0801F288: .4byte 0x06012C20
_0801F28C: .4byte 0x80000130
_0801F290: .4byte 0x086AD9FC
_0801F294: .4byte 0x086B3A04
_0801F298: .4byte gOamBuffer
_0801F29C: .4byte 0xFFFFFE00
_0801F2A0: .4byte 0x000001FF

	thumb_func_start sub_1F2A4
sub_1F2A4: @ 0x0801F2A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _0801F3E8 @ =0x020314E0
	ldr r4, [r5]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	mov sb, r2
	adds r2, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r3, [r2]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	beq _0801F39A
	adds r0, r3, #2
	strh r0, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #0xe
	bl __divsi3
	movs r6, #0xe5
	lsls r6, r6, #1
	adds r2, r4, r6
	strh r0, [r2]
	movs r3, #0xe8
	lsls r3, r3, #1
	mov r8, r3
	adds r1, r4, r3
	movs r0, #0x50
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	mov ip, r0
	adds r0, r4, r0
	subs r3, #0xd0
	strh r3, [r0]
	movs r7, #0xed
	lsls r7, r7, #1
	adds r0, r4, r7
	strh r3, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xb
	bne _0801F314
	movs r2, #0xe7
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x78
	strh r0, [r1]
_0801F314:
	ldr r2, [r5]
	adds r1, r2, r6
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0xb
	ble _0801F336
	movs r0, #0xc
	strh r0, [r1]
	mov r6, r8
	adds r1, r2, r6
	movs r0, #0x78
	strh r0, [r1]
	mov r1, ip
	adds r0, r2, r1
	strh r3, [r0]
	adds r0, r2, r7
	strh r3, [r0]
_0801F336:
	ldr r0, [r5]
	mov r3, sb
	adds r2, r0, r3
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0xa7
	bgt _0801F368
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801F368
	movs r5, #0
	ldrsh r0, [r2, r5]
	movs r1, #0x15
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	movs r6, #0xa8
	lsls r6, r6, #0x10
	adds r0, r0, r6
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
_0801F368:
	ldr r4, _0801F3E8 @ =0x020314E0
	ldr r1, [r4]
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bgt _0801F39A
	strh r3, [r2]
	cmp r1, #0xa7
	ble _0801F39A
	ldr r0, _0801F3EC @ =0x02032F20
	ldr r1, _0801F3F0 @ =0x0869F2A0
	bl MPlayStart
	ldr r1, [r4]
	ldr r0, _0801F3F4 @ =0x00000BB8
	str r0, [r1, #0x3c]
_0801F39A:
	ldr r5, _0801F3E8 @ =0x020314E0
	ldr r0, [r5]
	ldr r2, _0801F3F8 @ =0x00000616
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801F3AC
	subs r0, #1
	strh r0, [r1]
_0801F3AC:
	ldr r4, [r5]
	ldr r3, _0801F3FC @ =0x00000614
	adds r2, r4, r3
	ldrh r0, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	cmp r1, #0
	ble _0801F478
	subs r0, #3
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801F3CA
	strh r3, [r2]
_0801F3CA:
	ldr r0, [r5]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r4, _0801F400 @ =0x0000061A
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r0, #1
	cmp r2, r0
	bge _0801F404
	adds r0, r2, #1
	strh r0, [r1]
	b _0801F44E
	.align 2, 0
_0801F3E8: .4byte 0x020314E0
_0801F3EC: .4byte 0x02032F20
_0801F3F0: .4byte 0x0869F2A0
_0801F3F4: .4byte 0x00000BB8
_0801F3F8: .4byte 0x00000616
_0801F3FC: .4byte 0x00000614
_0801F400: .4byte 0x0000061A
_0801F404:
	strh r3, [r1]
	ldr r0, _0801F464 @ =0x02032FB0
	ldr r1, _0801F468 @ =0x0869F240
	bl MPlayStart
	ldr r2, [r5]
	movs r0, #0x64
	str r0, [r2, #0x3c]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xb
	bgt _0801F44E
	ldr r4, _0801F46C @ =0x0000061C
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801F44E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x50
	strh r0, [r1]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
_0801F44E:
	ldr r5, _0801F470 @ =0x020314E0
	ldr r4, [r5]
	ldr r6, _0801F474 @ =0x00000614
	adds r0, r4, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xe1
	lsls r0, r0, #1
	subs r0, r0, r1
	b _0801F508
	.align 2, 0
_0801F464: .4byte 0x02032FB0
_0801F468: .4byte 0x0869F240
_0801F46C: .4byte 0x0000061C
_0801F470: .4byte 0x020314E0
_0801F474: .4byte 0x00000614
_0801F478:
	cmp r1, #0
	bge _0801F55C
	adds r0, #3
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0801F48A
	strh r3, [r2]
_0801F48A:
	ldr r0, [r5]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r4, _0801F4A8 @ =0x0000061A
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r0, #1
	cmp r2, r0
	bge _0801F4AC
	adds r0, r2, #1
	strh r0, [r1]
	b _0801F4F6
	.align 2, 0
_0801F4A8: .4byte 0x0000061A
_0801F4AC:
	strh r3, [r1]
	ldr r0, _0801F540 @ =0x02032FB0
	ldr r1, _0801F544 @ =0x0869F240
	bl MPlayStart
	ldr r2, [r5]
	movs r0, #0x64
	str r0, [r2, #0x3c]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xb
	bgt _0801F4F6
	ldr r4, _0801F548 @ =0x0000061C
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801F4F6
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x50
	strh r0, [r1]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
_0801F4F6:
	ldr r5, _0801F54C @ =0x020314E0
	ldr r4, [r5]
	ldr r6, _0801F550 @ =0x00000614
	adds r0, r4, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r0, r2
_0801F508:
	movs r1, #0xa
	bl __divsi3
	ldr r1, _0801F554 @ =0x0000061A
	adds r4, r4, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0801F520
	movs r0, #5
	strh r0, [r4]
_0801F520:
	ldr r4, [r5]
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #4
	adds r1, r4, r1
	movs r5, #0
	ldrsh r1, [r1, r5]
	bl __divsi3
	ldr r6, _0801F558 @ =0x000001E5
	adds r1, r4, r6
	strb r0, [r1]
	b _0801F58A
	.align 2, 0
_0801F540: .4byte 0x02032FB0
_0801F544: .4byte 0x0869F240
_0801F548: .4byte 0x0000061C
_0801F54C: .4byte 0x020314E0
_0801F550: .4byte 0x00000614
_0801F554: .4byte 0x0000061A
_0801F558: .4byte 0x000001E5
_0801F55C:
	ldr r0, _0801F598 @ =0x000001E5
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _0801F58A
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r4, r4, r1
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0x28
	bl __umodsi3
	strh r0, [r4]
	ldrh r0, [r4]
	lsls r0, r0, #4
	movs r1, #0x28
	bl __divsi3
	strb r0, [r5]
_0801F58A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F598: .4byte 0x000001E5

	thumb_func_start sub_1F59C
sub_1F59C: @ 0x0801F59C
	push {r4, r5, r6, r7, lr}
	ldr r3, _0801F5D4 @ =0x020314E0
	ldr r4, [r3]
	ldr r1, _0801F5D8 @ =0x000001E5
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, _0801F5DC @ =gMain
	ldr r0, [r2, #0x44]
	ldr r6, [r0, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xce
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrb r0, [r2, #4]
	cmp r0, #0
	bne _0801F5E0
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xae
	b _0801F5E8
	.align 2, 0
_0801F5D4: .4byte 0x020314E0
_0801F5D8: .4byte 0x000001E5
_0801F5DC: .4byte gMain
_0801F5E0:
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x9a
_0801F5E8:
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, [r3]
	ldr r2, _0801F678 @ =0x000001E5
	adds r0, r1, r2
	movs r3, #0xf3
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrb r3, [r0]
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	beq _0801F624
	strb r3, [r2]
	ldr r2, _0801F67C @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801F680 @ =0x084FA48C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F684 @ =0x06010780
	str r0, [r2, #4]
	ldr r0, _0801F688 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801F624:
	movs r0, #0
	ldr r7, _0801F68C @ =gOamBuffer
	ldr r1, _0801F690 @ =0xFFFFFE00
	mov ip, r1
_0801F62C:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0801F694 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _0801F62C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F678: .4byte 0x000001E5
_0801F67C: .4byte 0x040000D4
_0801F680: .4byte 0x084FA48C
_0801F684: .4byte 0x06010780
_0801F688: .4byte 0x80000090
_0801F68C: .4byte gOamBuffer
_0801F690: .4byte 0xFFFFFE00
_0801F694: .4byte 0x000001FF

	thumb_func_start sub_1F698
sub_1F698: @ 0x0801F698
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r7, _0801F6EC @ =0x0200BDC8
	ldr r0, _0801F6F0 @ =0x020314E0
	ldr r4, [r0]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r3, r4, r1
	ldrh r1, [r3]
	mov sb, r0
	cmp r1, #0x3b
	bhi _0801F712
	adds r0, r1, #0
	subs r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _0801F704
	ldrh r0, [r3]
	subs r0, #0x1b
	movs r1, #5
	bl __divsi3
	ldr r2, _0801F6F4 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	ldr r1, _0801F6F8 @ =0x083C562C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F6FC @ =0x06014280
	str r0, [r2, #4]
	ldr r0, _0801F700 @ =0x80000080
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb0
	b _0801F760
	.align 2, 0
_0801F6EC: .4byte 0x0200BDC8
_0801F6F0: .4byte 0x020314E0
_0801F6F4: .4byte 0x040000D4
_0801F6F8: .4byte 0x083C562C
_0801F6FC: .4byte 0x06014280
_0801F700: .4byte 0x80000080
_0801F704:
	strh r2, [r7]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb0
	b _0801F760
_0801F712:
	adds r0, r1, #0
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _0801F754
	ldrh r0, [r3]
	subs r0, #0x64
	movs r1, #5
	bl __divsi3
	ldr r2, _0801F744 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	ldr r1, _0801F748 @ =0x083C562C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F74C @ =0x06014280
	str r0, [r2, #4]
	ldr r0, _0801F750 @ =0x80000080
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r0, r4, #0
	b _0801F75A
	.align 2, 0
_0801F744: .4byte 0x040000D4
_0801F748: .4byte 0x083C562C
_0801F74C: .4byte 0x06014280
_0801F750: .4byte 0x80000080
_0801F754:
	strh r2, [r7]
	mov r3, sb
	ldr r0, [r3]
_0801F75A:
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x20
_0801F760:
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r7]
	ldr r1, _0801F880 @ =0x0200BD10
	mov r8, r1
	cmp r0, #0
	beq _0801F7D8
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _0801F78C
	movs r0, #0xb4
	strh r0, [r7, #4]
_0801F78C:
	movs r0, #0
	ldr r6, _0801F884 @ =gOamBuffer
	ldr r1, _0801F888 @ =0xFFFFFE00
	mov ip, r1
_0801F794:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0801F88C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801F794
_0801F7D8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #0
	bne _0801F7E2
	b _0801FA26
_0801F7E2:
	mov r0, sb
	ldr r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrh r0, [r1]
	cmp r0, #0x77
	bls _0801F7F4
	b _0801F990
_0801F7F4:
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801F802
	movs r0, #0xc6
	bl m4aSongNumStart
_0801F802:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r2, _0801F890 @ =0x040000D4
	lsrs r0, r0, #2
	lsls r0, r0, #7
	ldr r1, _0801F894 @ =0x083C542C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F898 @ =0x06014200
	str r0, [r2, #4]
	ldr r0, _0801F89C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, sb
	ldr r4, [r2]
	adds r5, r4, r6
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	movs r1, #0x5a
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	subs r1, #2
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5]
	cmp r0, #0x1d
	bhi _0801F8A8
	adds r0, r2, #0
	bl sub_C24
	adds r1, r0, #0
	mov r2, sb
	ldr r4, [r2]
	adds r5, r4, r6
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0801F8A0 @ =0x00004E20
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r1, r0
	ldr r3, _0801F8A4 @ =0x000002B6
	adds r4, r4, r3
	strh r1, [r4]
	b _0801F8CC
	.align 2, 0
_0801F880: .4byte 0x0200BD10
_0801F884: .4byte gOamBuffer
_0801F888: .4byte 0xFFFFFE00
_0801F88C: .4byte 0x000001FF
_0801F890: .4byte 0x040000D4
_0801F894: .4byte 0x083C542C
_0801F898: .4byte 0x06014200
_0801F89C: .4byte 0x80000040
_0801F8A0: .4byte 0x00004E20
_0801F8A4: .4byte 0x000002B6
_0801F8A8:
	adds r0, r2, #0
	bl sub_C24
	adds r1, r0, #0
	mov r0, sb
	ldr r4, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0801F910 @ =0x00004E20
	bl __divsi3
	adds r0, #0x1e
	ldr r1, _0801F914 @ =0x000002B6
	adds r4, r4, r1
	strh r0, [r4]
_0801F8CC:
	ldr r2, _0801F918 @ =0x020314E0
	ldr r1, [r2]
	movs r3, #0xaf
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r2
	cmp r0, #0x1b
	bne _0801F934
	ldr r0, _0801F91C @ =gMain
	ldr r1, _0801F920 @ =0x00000D08
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	movs r0, #0xc7
	bl m4aSongNumStart
	mov r2, sb
	ldr r0, [r2]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801F924
	adds r0, r2, #1
	strb r0, [r1]
	b _0801F934
	.align 2, 0
_0801F910: .4byte 0x00004E20
_0801F914: .4byte 0x000002B6
_0801F918: .4byte 0x020314E0
_0801F91C: .4byte gMain
_0801F920: .4byte 0x00000D08
_0801F924:
	movs r0, #2
	strb r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0801F96C @ =0x000002EA
	adds r0, r0, r2
	movs r1, #0xbe
	strh r1, [r0]
_0801F934:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x64
	bne _0801F9B6
	ldr r0, _0801F970 @ =gMain
	ldr r2, _0801F974 @ =0x00000D08
	adds r0, r0, r2
	movs r1, #1
	strh r1, [r0]
	movs r0, #0xc7
	bl m4aSongNumStart
	mov r3, sb
	ldr r0, [r3]
	ldr r2, _0801F978 @ =0x000002E3
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801F97C
	adds r0, r2, #1
	strb r0, [r1]
	b _0801F9B6
	.align 2, 0
_0801F96C: .4byte 0x000002EA
_0801F970: .4byte gMain
_0801F974: .4byte 0x00000D08
_0801F978: .4byte 0x000002E3
_0801F97C:
	movs r0, #2
	strb r0, [r1]
	mov r3, sb
	ldr r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0xbe
	strh r1, [r0]
	b _0801F9B6
_0801F990:
	movs r2, #0
	strh r2, [r1]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _0801FA34 @ =0x000002B6
	adds r1, r3, r0
	movs r0, #0xbe
	strh r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r1, _0801FA38 @ =0x000002BA
	adds r0, r3, r1
	strh r2, [r0]
	strh r2, [r7]
_0801F9B6:
	mov r2, sb
	ldr r4, [r2]
	movs r3, #0xad
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl __divsi3
	adds r0, #0x47
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r2, _0801FA34 @ =0x000002B6
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r0, #0xf8
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xbe
	ble _0801F9F2
	movs r0, #0xbe
	strh r0, [r7, #4]
_0801F9F2:
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _0801FA3C @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r3, _0801FA40 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0801FA44 @ =0xFFFFFE00
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
_0801FA26:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA34: .4byte 0x000002B6
_0801FA38: .4byte 0x000002BA
_0801FA3C: .4byte gOamBuffer
_0801FA40: .4byte 0x000001FF
_0801FA44: .4byte 0xFFFFFE00

	thumb_func_start sub_1FA48
sub_1FA48: @ 0x0801FA48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r7, _0801FAD0 @ =0x0200D9D0
	ldr r0, _0801FAD4 @ =0x020314E0
	ldr r6, [r0]
	ldr r1, _0801FAD8 @ =0x000002B2
	mov sb, r1
	adds r1, r6, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _0801FAF0
	ldr r5, _0801FADC @ =0x086ADA58
	movs r2, #0xac
	lsls r2, r2, #2
	mov r8, r2
	adds r0, r6, r2
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r5
	ldrh r3, [r0]
	cmp r4, #0x28
	bne _0801FABA
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x64
	strh r0, [r2]
	ldr r2, _0801FAE0 @ =0x000002BA
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0801FAE4 @ =0xFFFFE340
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_0801FABA:
	mov r2, sl
	ldr r1, [r2]
	mov r0, r8
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0x35
	bhi _0801FAE8
	adds r0, #1
	strh r0, [r2]
	b _0801FB12
	.align 2, 0
_0801FAD0: .4byte 0x0200D9D0
_0801FAD4: .4byte 0x020314E0
_0801FAD8: .4byte 0x000002B2
_0801FADC: .4byte 0x086ADA58
_0801FAE0: .4byte 0x000002BA
_0801FAE4: .4byte 0xFFFFE340
_0801FAE8:
	add r1, sb
	movs r0, #0
	strb r0, [r1]
	b _0801FB12
_0801FAF0:
	ldr r1, _0801FBA4 @ =0xFFFFD6F0
	adds r0, r7, r1
	ldr r0, [r0, #0x4c]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _0801FB2E
_0801FB12:
	ldr r2, _0801FBA8 @ =0x040000D4
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801FBAC @ =0x083C3C2C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801FBB0 @ =0x06012720
	str r0, [r2, #4]
	ldr r0, _0801FBB4 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801FB2E:
	mov r0, sl
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x37
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0xdd
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r0, #0
	ldr r6, _0801FBB8 @ =gOamBuffer
	ldr r1, _0801FBBC @ =0xFFFFFE00
	mov ip, r1
_0801FB50:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r6
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0801FBC0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #1
	ble _0801FB50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FBA4: .4byte 0xFFFFD6F0
_0801FBA8: .4byte 0x040000D4
_0801FBAC: .4byte 0x083C3C2C
_0801FBB0: .4byte 0x06012720
_0801FBB4: .4byte 0x80000180
_0801FBB8: .4byte gOamBuffer
_0801FBBC: .4byte 0xFFFFFE00
_0801FBC0: .4byte 0x000001FF

	thumb_func_start sub_1FBC4
sub_1FBC4: @ 0x0801FBC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0801FC74 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _0801FC78 @ =0x000002C2
	adds r3, r2, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0801FC7C @ =0x086ADA6E
	adds r7, r0, r1
	ldr r0, _0801FC80 @ =0x0200DCB0
	mov sb, r0
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #9
	subs r0, r0, r1
	movs r1, #0
	mov r8, r1
	mov r6, sb
	strh r0, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r6, #0x90
	lsls r6, r6, #1
	adds r0, r6, #0
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #4]
	ldr r6, _0801FC84 @ =0x000002BE
	mov ip, r6
	adds r1, r2, r6
	ldr r6, _0801FC88 @ =0x000006BD
	adds r0, r2, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	ble _0801FCDC
	ldr r0, _0801FC8C @ =0x000006BE
	mov sl, r0
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801FC38
	b _0801FDFC
_0801FC38:
	adds r6, #3
	adds r0, r2, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801FC5A
	movs r0, #0x3b
	strb r0, [r3]
	ldr r1, [r4]
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	strh r3, [r0]
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0801FC5A:
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r4]
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r2, r1, r3
	ldrh r3, [r2]
	cmp r0, r3
	ble _0801FC90
	adds r0, r3, #1
	strh r0, [r2]
	b _0801FDFC
	.align 2, 0
_0801FC74: .4byte 0x020314E0
_0801FC78: .4byte 0x000002C2
_0801FC7C: .4byte 0x086ADA6E
_0801FC80: .4byte 0x0200DCB0
_0801FC84: .4byte 0x000002BE
_0801FC88: .4byte 0x000006BD
_0801FC8C: .4byte 0x000006BE
_0801FC90:
	movs r0, #1
	strh r0, [r2]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x54
	bne _0801FCC2
	mov r0, r8
	strb r0, [r1]
	ldr r0, [r4]
	add r0, sl
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r6
	movs r2, #0
	strh r2, [r1]
	add r0, ip
	mov r3, r8
	strb r3, [r0]
_0801FCC2:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3c
	beq _0801FD8E
	cmp r0, #0x45
	beq _0801FD8E
	cmp r0, #0x4e
	beq _0801FCDA
	b _0801FDFC
_0801FCDA:
	b _0801FD8E
_0801FCDC:
	cmp r1, r0
	bge _0801FD96
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r8, r0
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r2, [r1]
	cmp r8, r2
	bgt _0801FDAC
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, r6
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	bne _0801FD32
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _0801FD22
	add r1, ip
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0x54
	strb r1, [r0]
_0801FD22:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801FDFC
	b _0801FD8E
_0801FD32:
	cmp r2, #2
	bne _0801FD60
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _0801FD50
	mov r3, ip
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0x5f
	strb r1, [r0]
_0801FD50:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801FDFC
	b _0801FD8E
_0801FD60:
	cmp r2, #3
	bne _0801FDFC
	adds r0, r1, r5
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0x23
	bne _0801FD80
	mov r6, ip
	adds r0, r1, r6
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r0, r5
	strb r3, [r0]
	movs r0, #7
	bl sub_19B64
_0801FD80:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	bne _0801FDFC
_0801FD8E:
	movs r0, #0xd2
	bl m4aSongNumStart
	b _0801FDFC
_0801FD96:
	cmp r0, #0
	beq _0801FDFC
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r8, r0
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r2, [r1]
	cmp r8, r2
	ble _0801FDB2
_0801FDAC:
	adds r0, r2, #1
	strh r0, [r1]
	b _0801FDFC
_0801FDB2:
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0801FDD8
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x5f
	bne _0801FDFC
	movs r0, #0x54
	b _0801FDFA
_0801FDD8:
	cmp r0, #2
	bne _0801FDEA
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x6d
	bne _0801FDFC
	movs r0, #0x5f
	b _0801FDFA
_0801FDEA:
	cmp r0, #3
	bne _0801FDFC
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x3c
	bne _0801FDFC
	movs r0, #0x23
_0801FDFA:
	strb r0, [r1]
_0801FDFC:
	ldrh r5, [r7]
	ldr r2, _0801FEE4 @ =0x040000D4
	movs r3, #4
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r4, _0801FEE8 @ =0x08447A8C
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEEC @ =0x06013B80
	str r0, [r2, #4]
	ldr r3, _0801FEF0 @ =0x800000C0
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r6, #6
	ldrsh r1, [r7, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEF4 @ =0x06013A00
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #8
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEF8 @ =0x06013880
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r2, _0801FEFC @ =gOamBuffer
	mov ip, r2
	ldr r3, _0801FF00 @ =0x086B2FC0
	mov sl, r3
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r6, r0, #2
	ldr r5, _0801FF04 @ =0xFFFFFE00
	mov r8, r5
_0801FE5E:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	add r1, sl
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r7, [r2, #2]
	lsls r1, r7, #0x17
	lsrs r1, r1, #0x17
	mov r5, sb
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _0801FF08 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	ldrh r7, [r2, #2]
	ands r0, r7
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r1]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _0801FE5E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FEE4: .4byte 0x040000D4
_0801FEE8: .4byte 0x08447A8C
_0801FEEC: .4byte 0x06013B80
_0801FEF0: .4byte 0x800000C0
_0801FEF4: .4byte 0x06013A00
_0801FEF8: .4byte 0x06013880
_0801FEFC: .4byte gOamBuffer
_0801FF00: .4byte 0x086B2FC0
_0801FF04: .4byte 0xFFFFFE00
_0801FF08: .4byte 0x000001FF

	thumb_func_start sub_1FF0C
sub_1FF0C: @ 0x0801FF0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r1, #0
	ldr r6, _0801FF70 @ =0x020314E0
	mov sb, r6
	ldr r0, _0801FF74 @ =0x000002E3
	mov sl, r0
	movs r2, #0xba
	lsls r2, r2, #2
	mov r8, r2
	movs r3, #0xbb
	lsls r3, r3, #2
	mov ip, r3
_0801FF2E:
	mov r4, sb
	ldr r3, [r4]
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	mov r7, sl
	adds r1, r3, r7
	adds r1, r1, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r0, [sp]
	cmp r1, #0
	ble _08020012
	ldr r1, _0801FF78 @ =0x000002E5
	adds r0, r3, r1
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r1, r1, #2
	ldr r2, _0801FF7C @ =0x086ADEB2
	adds r1, r1, r2
	lsls r2, r5, #1
	mov r7, r8
	adds r0, r3, r7
	adds r2, r0, r2
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0801FF80
	adds r0, r3, #1
	strh r0, [r2]
	b _0801FFAE
	.align 2, 0
_0801FF70: .4byte 0x020314E0
_0801FF74: .4byte 0x000002E3
_0801FF78: .4byte 0x000002E5
_0801FF7C: .4byte 0x086ADEB2
_0801FF80:
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _08020070 @ =0x000002E5
	adds r0, r0, r2
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	ble _0801FFAE
	strb r3, [r1]
	mov r3, sb
	ldr r1, [r3]
	add r1, sl
	adds r1, r1, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801FFAE:
	ldr r3, [r6]
	ldr r7, [sp]
	asrs r4, r7, #0x10
	ldr r5, _08020070 @ =0x000002E5
	adds r0, r3, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0801FFD8
	lsls r2, r4, #1
	mov r0, ip
	adds r1, r3, r0
	adds r1, r1, r2
	mov r7, r8
	adds r0, r3, r7
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
_0801FFD8:
	ldr r1, [r6]
	adds r0, r1, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r3, r4, #1
	cmp r0, #0xb
	bne _08020000
	mov r0, ip
	adds r2, r1, r0
	adds r2, r2, r3
	mov r4, r8
	adds r0, r1, r4
	adds r0, r0, r3
	ldrh r1, [r0]
	lsrs r1, r1, #1
	movs r0, #0xe
	subs r0, r0, r1
	strh r0, [r2]
_08020000:
	ldr r0, [r6]
	add r0, ip
	adds r2, r0, r3
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r0, #2
	bgt _08020012
	movs r0, #3
	strh r0, [r2]
_08020012:
	ldr r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r1, r2
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0801FF2E
	ldr r1, [r6]
	ldr r3, _08020074 @ =0x000002E2
	adds r0, r1, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _08020032
	b _0802018E
_08020032:
	cmp r3, #1
	bne _08020120
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #7
	bne _08020040
	b _08020136
_08020040:
	cmp r0, #2
	bgt _080200C4
	ldr r4, _08020078 @ =0x000006BD
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08020136
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020080
	ldr r7, _0802007C @ =0x000002C2
	adds r0, r1, r7
	strb r2, [r0]
	b _08020110
	.align 2, 0
_08020070: .4byte 0x000002E5
_08020074: .4byte 0x000002E2
_08020078: .4byte 0x000006BD
_0802007C: .4byte 0x000002C2
_08020080:
	cmp r0, #2
	bne _0802009C
	ldr r3, _08020098 @ =0x000002C2
	adds r1, r1, r3
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r6]
	movs r4, #0xb0
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r2, [r0]
	b _08020136
	.align 2, 0
_08020098: .4byte 0x000002C2
_0802009C:
	cmp r0, #3
	bne _08020136
	ldr r7, _080200BC @ =0x000002C2
	adds r1, r1, r7
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, [r6]
	movs r4, #0xb0
	lsls r4, r4, #2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r7, _080200C0 @ =0x000006C2
	adds r0, r0, r7
	strh r3, [r0]
	b _08020136
	.align 2, 0
_080200BC: .4byte 0x000002C2
_080200C0: .4byte 0x000006C2
_080200C4:
	ldr r0, _080200FC @ =0x000006BD
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08020136
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r1]
	ldr r1, [r6]
	ldr r3, _080200FC @ =0x000006BD
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020104
	ldr r4, _08020100 @ =0x000002C2
	adds r0, r1, r4
	strb r2, [r0]
	ldr r0, [r6]
	movs r7, #0xb0
	lsls r7, r7, #2
	adds r0, r0, r7
	strh r2, [r0]
	b _08020136
	.align 2, 0
_080200FC: .4byte 0x000006BD
_08020100: .4byte 0x000002C2
_08020104:
	cmp r0, #2
	bne _08020136
	ldr r0, _0802011C @ =0x000002C2
	adds r1, r1, r0
	movs r0, #0xc
	strb r0, [r1]
_08020110:
	ldr r0, [r6]
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
	b _08020136
	.align 2, 0
_0802011C: .4byte 0x000002C2
_08020120:
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08020132
	movs r0, #1
	b _08020134
_08020132:
	movs r0, #0
_08020134:
	strb r0, [r1]
_08020136:
	ldr r0, [r6]
	ldr r3, _080201A0 @ =0x000002E3
	adds r0, r0, r3
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r6]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r0, r0, r7
	strb r4, [r0]
	ldr r0, [r6]
	ldr r1, _080201A4 @ =0x000002E2
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #7
	bl sub_11B0
	movs r0, #0xb7
	bl m4aSongNumStart
	ldr r0, [r6]
	ldr r1, _080201A8 @ =0x00000BB8
	str r1, [r0, #0x3c]
	ldr r2, _080201AC @ =0x000002E5
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r3, _080201B0 @ =0x000002E6
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r6]
	adds r7, #4
	adds r0, r1, r7
	strh r4, [r0]
	adds r2, #5
	adds r0, r1, r2
	strh r4, [r0]
	adds r3, #6
	adds r0, r1, r3
	movs r2, #3
	strh r2, [r0]
	ldr r4, _080201B4 @ =0x000002EE
	adds r1, r1, r4
	strh r2, [r1]
_0802018E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080201A0: .4byte 0x000002E3
_080201A4: .4byte 0x000002E2
_080201A8: .4byte 0x00000BB8
_080201AC: .4byte 0x000002E5
_080201B0: .4byte 0x000002E6
_080201B4: .4byte 0x000002EE

	thumb_func_start sub_201B8
sub_201B8: @ 0x080201B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0
	ldr r0, _080202D0 @ =0x020314E0
	mov sl, r0
	ldr r2, _080202D4 @ =0x040000D4
	mov r8, r2
_080201CC:
	mov r3, sl
	ldr r0, [r3]
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
	ldr r4, _080202D8 @ =0x000002E5
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r5, _080202DC @ =0x086ADEB0
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	ldr r4, _080202E0 @ =0x0847FD0C
	adds r0, r0, r4
	mov r5, r8
	str r0, [r5]
	lsls r0, r3, #8
	ldr r2, _080202E4 @ =0x06012A20
	adds r0, r0, r2
	str r0, [r5, #4]
	ldr r0, _080202E8 @ =0x80000080
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0xb8
	muls r0, r3, r0
	ldr r4, _080202EC @ =0x0200DE20
	adds r6, r0, r4
	ldrh r0, [r6]
	mov sb, r1
	cmp r0, #0
	beq _0802029A
	lsls r1, r3, #4
	subs r1, r1, r3
	lsls r1, r1, #3
	adds r1, #0x30
	mov r5, sl
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r3, r3, #1
	movs r2, #1
	subs r2, r2, r3
	movs r5, #0xbb
	lsls r5, r5, #2
	adds r0, r4, r5
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #0xe
	muls r0, r2, r0
	adds r1, r1, r0
	strh r1, [r6, #2]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r4, _080202F0 @ =0x0000012D
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _080202F4 @ =gOamBuffer
	ldr r5, _080202F8 @ =0xFFFFFE00
	mov ip, r5
_08020256:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	lsls r5, r3, #3
	adds r5, #8
	adds r5, r6, r5
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r4, _080202FC @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, ip
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _08020256
_0802029A:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080201CC
	mov r5, sl
	ldr r2, [r5]
	ldr r0, _08020300 @ =0x000006C2
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08020398
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08020398
	adds r2, #0xe4
	ldrb r0, [r2]
	cmp r0, #0
	beq _08020304
	movs r0, #1
	strh r0, [r1]
	b _08020308
	.align 2, 0
_080202D0: .4byte 0x020314E0
_080202D4: .4byte 0x040000D4
_080202D8: .4byte 0x000002E5
_080202DC: .4byte 0x086ADEB0
_080202E0: .4byte 0x0847FD0C
_080202E4: .4byte 0x06012A20
_080202E8: .4byte 0x80000080
_080202EC: .4byte 0x0200DE20
_080202F0: .4byte 0x0000012D
_080202F4: .4byte gOamBuffer
_080202F8: .4byte 0xFFFFFE00
_080202FC: .4byte 0x000001FF
_08020300: .4byte 0x000006C2
_08020304:
	movs r0, #4
	strb r0, [r2]
_08020308:
	mov r1, sl
	ldr r4, [r1]
	ldr r2, _080203A8 @ =0x000006C2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _08020398
	ldr r2, _080203AC @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r1, r4, #0
	adds r1, #0xea
	movs r3, #0
	movs r0, #0x46
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r5, [r0]
	subs r0, #2
	strh r5, [r0]
	adds r0, #8
	strh r5, [r0]
	adds r1, #6
	movs r0, #4
	strb r0, [r1]
	mov r4, sl
	ldr r0, [r4]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0xfb
	strb r3, [r0]
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0xf4
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf6
	strh r5, [r0]
	subs r1, #4
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf8
	strh r5, [r0]
	ldr r1, _080203B0 @ =0x040000D4
	ldr r0, _080203B4 @ =0x086ACEF8
	ldr r0, [r0, #0x10]
	str r0, [r1]
	ldr r0, _080203B8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080203BC @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080203C0 @ =0x086ACF18
	ldr r0, [r0, #0x10]
	str r0, [r1]
	ldr r0, _080203C4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080203C8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_08020398:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080203A8: .4byte 0x000006C2
_080203AC: .4byte gMain
_080203B0: .4byte 0x040000D4
_080203B4: .4byte 0x086ACEF8
_080203B8: .4byte 0x06015800
_080203BC: .4byte 0x80001200
_080203C0: .4byte 0x086ACF18
_080203C4: .4byte 0x050003C0
_080203C8: .4byte 0x80000010

	thumb_func_start sub_203CC
sub_203CC: @ 0x080203CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_20EC0
	ldr r6, _0802042C @ =0x020314E0
	ldr r5, [r6]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa7
	ble _0802044C
	ldr r4, _08020430 @ =0x086ADF48
	ldr r0, _08020434 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0xa0
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r3, _08020438 @ =0x00000744
	adds r0, r5, r3
	strb r1, [r0]
	ldr r2, [r6]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020440
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #6
	ldr r5, _0802043C @ =0x00000745
	adds r1, r2, r5
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_0802042C: .4byte 0x020314E0
_08020430: .4byte 0x086ADF48
_08020434: .4byte gMain
_08020438: .4byte 0x00000744
_0802043C: .4byte 0x00000745
_08020440:
	ldr r7, _08020448 @ =0x00000744
	adds r0, r2, r7
	b _08020494
	.align 2, 0
_08020448: .4byte 0x00000744
_0802044C:
	ldr r0, _08020484 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	ldr r4, _08020488 @ =0x00000744
	adds r1, r5, r4
	strb r0, [r1]
	ldr r2, [r6]
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020490
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #9
	ldr r7, _0802048C @ =0x00000745
	adds r1, r2, r7
	strb r0, [r1]
	b _0802049C
	.align 2, 0
_08020484: .4byte gMain
_08020488: .4byte 0x00000744
_0802048C: .4byte 0x00000745
_08020490:
	ldr r1, _080204C8 @ =0x00000744
	adds r0, r2, r1
_08020494:
	ldrb r1, [r0]
	ldr r3, _080204CC @ =0x00000745
	adds r0, r2, r3
	strb r1, [r0]
_0802049C:
	ldr r1, _080204D0 @ =0x020314E0
	ldr r5, [r1]
	movs r4, #0xf1
	lsls r4, r4, #1
	adds r3, r5, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	mov sl, r1
	cmp r0, #2
	bne _080204D8
	ldr r7, _080204D4 @ =0x000001E3
	adds r0, r5, r7
	movs r1, #1
	strb r1, [r0]
	mov r2, sl
	ldr r0, [r2]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	b _08020500
	.align 2, 0
_080204C8: .4byte 0x00000744
_080204CC: .4byte 0x00000745
_080204D0: .4byte 0x020314E0
_080204D4: .4byte 0x000001E3
_080204D8:
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldr r3, _0802060C @ =0x000001E3
	adds r0, r5, r3
	adds r0, r0, r1
	movs r4, #0
	movs r2, #1
	strb r2, [r0]
	mov r5, sl
	ldr r0, [r5]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r1, r0, r7
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r2, r2, r1
	adds r0, r0, r3
	adds r0, r0, r2
	strb r4, [r0]
_08020500:
	mov r0, sl
	ldr r1, [r0]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r4, [r2]
	cmp r4, #0
	bne _08020512
	b _0802073A
_08020512:
	cmp r4, #0x78
	beq _08020518
	b _080206CC
_08020518:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08020538
	b _080206CC
_08020538:
	movs r6, #0xe3
	lsls r6, r6, #1
	adds r0, r1, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa7
	ble _08020630
	movs r5, #0
	movs r3, #1
	strb r3, [r1, #0x1f]
	mov r7, sl
	ldr r0, [r7]
	ldr r1, _08020610 @ =0x0000061C
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, [r7]
	movs r7, #0xef
	lsls r7, r7, #1
	adds r2, r1, r7
	movs r0, #0
	mov r8, r0
	strh r4, [r2]
	adds r7, #2
	adds r0, r1, r7
	strh r4, [r0]
	ldrh r2, [r2]
	ldr r4, _08020614 @ =0x0000061E
	adds r0, r1, r4
	strh r2, [r0]
	ldr r7, _08020618 @ =0x000005F7
	adds r1, r1, r7
	strb r3, [r1]
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x82
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _0802061C @ =0x0000020A
	adds r0, r0, r3
	mov r4, r8
	strb r4, [r0]
	mov r7, sl
	ldr r2, [r7]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080205E4
	adds r0, r2, r6
	strh r5, [r0]
	subs r3, #0x42
	adds r0, r2, r3
	strh r5, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r5, [r0]
	movs r7, #0xe5
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r5, [r0]
	subs r1, #0xe
	adds r0, r2, r1
	strh r5, [r0]
	adds r3, #0xe
	adds r1, r2, r3
	ldr r0, _08020620 @ =0x0000FFFC
	strh r0, [r1]
	adds r4, #0xc
	adds r0, r2, r4
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r7, #0x10
	adds r0, r2, r7
	strh r1, [r0]
	adds r1, #0xce
	adds r0, r2, r1
	strh r5, [r0]
	subs r3, #6
	adds r0, r2, r3
	strh r5, [r0]
_080205E4:
	mov r4, sl
	ldr r1, [r4]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r2, r1, r5
	ldr r7, _08020624 @ =0x0000132C
	adds r0, r1, r7
	ldr r0, [r0]
	ldr r0, [r0, #0x28]
	str r0, [r2]
	ldr r0, _08020628 @ =0x00007530
	str r0, [r1, #0x3c]
	ldr r0, _0802062C @ =0x0000062E
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802063C
	adds r0, #1
	strb r0, [r1]
	b _0802063C
	.align 2, 0
_0802060C: .4byte 0x000001E3
_08020610: .4byte 0x0000061C
_08020614: .4byte 0x0000061E
_08020618: .4byte 0x000005F7
_0802061C: .4byte 0x0000020A
_08020620: .4byte 0x0000FFFC
_08020624: .4byte 0x0000132C
_08020628: .4byte 0x00007530
_0802062C: .4byte 0x0000062E
_08020630:
	movs r0, #0x3c
	strh r0, [r2]
	ldr r0, _0802067C @ =0x02032F20
	ldr r1, _08020680 @ =0x086A2FA0
	bl MPlayStart
_0802063C:
	ldr r0, _08020684 @ =0x020314E0
	ldr r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #2
	bne _0802068C
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r4, _08020688 @ =0x00000744
	adds r2, r5, r4
	adds r2, r2, r1
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, #2
	strb r0, [r2]
	mov r8, r3
	b _0802069C
	.align 2, 0
_0802067C: .4byte 0x02032F20
_08020680: .4byte 0x086A2FA0
_08020684: .4byte 0x020314E0
_08020688: .4byte 0x00000744
_0802068C:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r7, _08020700 @ =0x00000744
	adds r0, r5, r7
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	mov r8, r2
_0802069C:
	ldr r3, _08020704 @ =0x040000D4
	mov r1, sl
	ldr r0, [r1]
	mov r4, r8
	asrs r2, r4, #0x10
	ldr r5, _08020700 @ =0x00000744
	adds r0, r0, r5
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020708 @ =0x084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r7, _0802070C @ =0x06010480
	adds r0, r0, r7
	str r0, [r3, #4]
	ldr r0, _08020710 @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_080206CC:
	mov r0, sl
	ldr r2, [r0]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020714
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r4, _08020700 @ =0x00000744
	adds r2, r2, r4
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _0802072A
	.align 2, 0
_08020700: .4byte 0x00000744
_08020704: .4byte 0x040000D4
_08020708: .4byte 0x084C07EC
_0802070C: .4byte 0x06010480
_08020710: .4byte 0x800000C0
_08020714:
	movs r5, #0xe1
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r2, r0
	ldr r7, _080207B4 @ =0x00000743
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
_0802072A:
	mov r0, sl
	ldr r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0802073A:
	mov r3, sl
	ldr r5, [r3]
	ldr r4, _080207B8 @ =0x0000061C
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0802074E
	b _08020D82
_0802074E:
	ldr r7, _080207BC @ =0x0000061E
	mov sb, r7
	mov r0, sb
	adds r6, r5, r0
	ldrh r7, [r6]
	mov r8, r7
	mov r1, r8
	cmp r1, #1
	bhi _08020762
	b _08020928
_08020762:
	movs r2, #0xef
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	subs r0, r7, #1
	strh r0, [r6]
	ldrh r0, [r4]
	cmp r0, #0
	beq _08020796
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bne _08020796
	ldrh r0, [r6]
	cmp r0, #0x28
	bls _08020796
	movs r0, #0x3c
	strh r0, [r4]
_08020796:
	ldr r3, _080207C0 @ =0x020314E0
	ldr r1, [r3]
	ldr r4, _080207BC @ =0x0000061E
	adds r2, r1, r4
	ldrh r0, [r2]
	cmp r0, #0x74
	bne _08020832
	adds r1, #0xe4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080207C4
	movs r0, #0x78
	strh r0, [r2]
	b _08020832
	.align 2, 0
_080207B4: .4byte 0x00000743
_080207B8: .4byte 0x0000061C
_080207BC: .4byte 0x0000061E
_080207C0: .4byte 0x020314E0
_080207C4:
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r3]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020820
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080207FC
	ldr r0, _080207F4 @ =0x02032F20
	ldr r1, _080207F8 @ =0x086A0328
	bl MPlayStart
	b _08020804
	.align 2, 0
_080207F4: .4byte 0x02032F20
_080207F8: .4byte 0x086A0328
_080207FC:
	ldr r0, _08020810 @ =0x02032F20
	ldr r1, _08020814 @ =0x086A0368
	bl MPlayStart
_08020804:
	ldr r0, _08020818 @ =0x02032EE0
	ldr r1, _0802081C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
	b _08020832
	.align 2, 0
_08020810: .4byte 0x02032F20
_08020814: .4byte 0x086A0368
_08020818: .4byte 0x02032EE0
_0802081C: .4byte 0x0000FFFF
_08020820:
	ldr r0, _08020900 @ =0x02032F20
	ldr r1, _08020904 @ =0x086A0328
	bl MPlayStart
	ldr r0, _08020908 @ =0x02032EE0
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x40
	bl m4aMPlayVolumeControl
_08020832:
	ldr r0, _08020910 @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _08020914 @ =0x0000061E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x73
	bne _08020856
	adds r0, r1, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #1
	bne _08020856
	ldr r0, _08020900 @ =0x02032F20
	ldr r1, _0802090C @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #2
	bl m4aMPlayVolumeControl
_08020856:
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	ldr r0, _08020910 @ =0x020314E0
	ldr r4, [r0]
	ldr r5, _08020918 @ =0x0000132C
	adds r5, r5, r4
	mov r8, r5
	ldr r7, [r5]
	mov sb, r7
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r6, r4, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0802091C @ =0x00004E20
	bl __divsi3
	ldrh r5, [r6]
	adds r5, r5, r0
	ldr r1, _08020920 @ =0x086ADF8A
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	subs r2, r2, r0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r6, r4, r0
	ldrh r1, [r6]
	movs r3, #0xef
	lsls r3, r3, #1
	adds r7, r4, r3
	ldrh r0, [r7]
	subs r0, r1, r0
	muls r0, r2, r0
	bl __divsi3
	adds r5, r5, r0
	mov r0, sb
	strh r5, [r0, #0x28]
	ldrh r1, [r6]
	ldrh r2, [r7]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	bl __divsi3
	mov r1, r8
	ldr r2, [r1]
	ldr r3, _08020924 @ =0x00000622
	adds r4, r4, r3
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	strh r1, [r2, #0x2a]
	mov r4, r8
	ldr r1, [r4]
	movs r5, #0x28
	ldrsh r0, [r1, r5]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r7, #0x2a
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	b _080209FE
	.align 2, 0
_08020900: .4byte 0x02032F20
_08020904: .4byte 0x086A0328
_08020908: .4byte 0x02032EE0
_0802090C: .4byte 0x0000FFFF
_08020910: .4byte 0x020314E0
_08020914: .4byte 0x0000061E
_08020918: .4byte 0x0000132C
_0802091C: .4byte 0x00004E20
_08020920: .4byte 0x086ADF8A
_08020924: .4byte 0x00000622
_08020928:
	mov r0, r8
	cmp r0, #1
	bne _080209FE
	ldr r1, _08020A3C @ =0x0000132C
	adds r2, r5, r1
	ldr r3, [r2]
	ldr r1, _08020A40 @ =0x086ADF8A
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #1
	movs r6, #0
	movs r5, #0
	strh r0, [r3, #0x28]
	ldr r1, [r2]
	ldr r0, _08020A44 @ =0x000002BE
	strh r0, [r1, #0x2a]
	ldr r1, [r2]
	movs r7, #0x28
	ldrsh r0, [r1, r7]
	lsls r0, r0, #7
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r3, #0x2a
	ldrsh r0, [r1, r3]
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r5, [r0, #0x30]
	ldr r1, [r2]
	ldr r0, _08020A48 @ =0x0000FED4
	strh r0, [r1, #0x32]
	movs r0, #0x7c
	bl m4aSongNumStart
	mov r7, sl
	ldr r1, [r7]
	mov r2, sb
	adds r0, r1, r2
	strh r5, [r0]
	strb r6, [r1, #0x1f]
	ldr r0, [r7]
	ldr r3, _08020A4C @ =0x000005F7
	adds r0, r0, r3
	strb r6, [r0]
	ldr r2, [r7]
	adds r4, r2, r4
	movs r0, #0
	ldrsb r0, [r4, r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r4, #0xe2
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r2, r1
	mov r5, r8
	strb r5, [r2]
	ldr r3, [r7]
	ldr r7, _08020A50 @ =0x00000714
	adds r4, r3, r7
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080209F8
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r2, _08020A54 @ =0x00000711
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r5, _08020A58 @ =0x00000712
	adds r1, r3, r5
	ldrb r1, [r1]
	ands r0, r1
	subs r7, #1
	adds r1, r3, r7
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _080209F8
	mov r0, r8
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020A5C @ =0x00000715
	adds r0, r0, r2
	movs r1, #0x7e
	strb r1, [r0]
	mov r3, sl
	ldr r1, [r3]
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
_080209F8:
	movs r0, #0xb
	bl sub_11B0
_080209FE:
	ldr r0, _08020A60 @ =0x020314E0
	ldr r3, [r0]
	ldr r4, _08020A64 @ =0x0000061E
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sl, r0
	cmp r1, #0x63
	bls _08020AFC
	movs r5, #0xf1
	lsls r5, r5, #1
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020A6C
	movs r7, #0xe1
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	ldr r1, _08020A68 @ =0x00000744
	adds r2, r3, r1
	adds r2, r2, r0
	lsls r1, r0, #3
	subs r1, r1, r0
	adds r1, #2
	strb r1, [r2]
	b _08020A82
	.align 2, 0
_08020A3C: .4byte 0x0000132C
_08020A40: .4byte 0x086ADF8A
_08020A44: .4byte 0x000002BE
_08020A48: .4byte 0x0000FED4
_08020A4C: .4byte 0x000005F7
_08020A50: .4byte 0x00000714
_08020A54: .4byte 0x00000711
_08020A58: .4byte 0x00000712
_08020A5C: .4byte 0x00000715
_08020A60: .4byte 0x020314E0
_08020A64: .4byte 0x0000061E
_08020A68: .4byte 0x00000744
_08020A6C:
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r3, r0
	ldr r3, _08020AC4 @ =0x00000743
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
_08020A82:
	mov r4, sl
	ldr r2, [r4]
	ldr r5, _08020AC8 @ =0x0000061E
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0x64
	beq _08020A92
	b _08020D82
_08020A92:
	ldr r0, _08020ACC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x98
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020AD8
	ldr r1, _08020AD0 @ =0x040000D4
	ldr r0, _08020AD4 @ =0x08395A4C
	b _08020ADC
	.align 2, 0
_08020AC4: .4byte 0x00000743
_08020AC8: .4byte 0x0000061E
_08020ACC: .4byte gMain
_08020AD0: .4byte 0x040000D4
_08020AD4: .4byte 0x08395A4C
_08020AD8:
	ldr r1, _08020AEC @ =0x040000D4
	ldr r0, _08020AF0 @ =0x08397E6C
_08020ADC:
	str r0, [r1]
	ldr r0, _08020AF4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08020AF8 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08020D82
	.align 2, 0
_08020AEC: .4byte 0x040000D4
_08020AF0: .4byte 0x08397E6C
_08020AF4: .4byte 0x06015800
_08020AF8: .4byte 0x80001200
_08020AFC:
	ldr r2, _08020B24 @ =0x086ADEE0
	ldr r6, _08020B28 @ =0x0000020A
	adds r4, r3, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, r2, #2
	adds r0, r0, r1
	movs r5, #0x82
	lsls r5, r5, #2
	adds r1, r3, r5
	ldrh r3, [r1]
	ldrh r0, [r0]
	mov r8, r2
	cmp r0, r3
	bls _08020B2C
	adds r0, r3, #1
	strh r0, [r1]
	b _08020C1C
	.align 2, 0
_08020B24: .4byte 0x086ADEE0
_08020B28: .4byte 0x0000020A
_08020B2C:
	movs r5, #0
	movs r7, #0
	strh r7, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08020BC0 @ =0x0000020A
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _08020B5C
	movs r0, #0x7c
	bl m4aSongNumStop
	ldr r0, _08020BC4 @ =0x02032EE0
	ldr r1, _08020BC8 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_08020B5C:
	mov r3, sl
	ldr r0, [r3]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x19
	ble _08020C1C
	movs r0, #0x19
	strb r0, [r1]
	mov r4, sl
	ldr r0, [r4]
	ldr r1, _08020BCC @ =0x0000061C
	adds r0, r0, r1
	strb r5, [r0]
	ldr r2, _08020BD0 @ =gMain
	ldr r0, [r2, #0x44]
	adds r0, #0x98
	ldr r0, [r0]
	strh r7, [r0]
	ldr r0, [r4]
	adds r0, #0xe4
	strb r5, [r0]
	ldr r4, [r4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r7, #0xf1
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08020BD8
	lsls r3, r2, #0x10
	asrs r1, r3, #0x10
	ldr r0, _08020BD4 @ =0x00000744
	adds r2, r4, r0
	adds r2, r2, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	strb r0, [r2]
	mov r8, r3
	b _08020BE6
	.align 2, 0
_08020BC0: .4byte 0x0000020A
_08020BC4: .4byte 0x02032EE0
_08020BC8: .4byte 0x0000FFFF
_08020BCC: .4byte 0x0000061C
_08020BD0: .4byte gMain
_08020BD4: .4byte 0x00000744
_08020BD8:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r3, _08020C48 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r1
	strb r5, [r0]
	mov r8, r2
_08020BE6:
	ldr r3, _08020C4C @ =0x040000D4
	ldr r4, _08020C50 @ =0x020314E0
	ldr r0, [r4]
	mov r5, r8
	asrs r2, r5, #0x10
	ldr r7, _08020C48 @ =0x00000744
	adds r0, r0, r7
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020C54 @ =0x084C07EC
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r1, _08020C58 @ =0x06010480
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _08020C5C @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	mov sl, r4
	ldr r2, _08020C60 @ =0x086ADEE0
	mov r8, r2
_08020C1C:
	mov r3, sl
	ldr r1, [r3]
	ldr r4, _08020C64 @ =0x0000020A
	adds r0, r1, r4
	ldrb r0, [r0]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bhi _08020C76
	ldr r5, _08020C68 @ =gMain
	ldr r0, [r5, #0x4c]
	movs r2, #3
	ands r0, r2
	lsrs r0, r0, #1
	cmp r0, #0
	beq _08020C70
	adds r1, #0x4c
	ldr r0, _08020C6C @ =0x0000FFFD
	strh r0, [r1]
	b _08020C76
	.align 2, 0
_08020C48: .4byte 0x00000744
_08020C4C: .4byte 0x040000D4
_08020C50: .4byte 0x020314E0
_08020C54: .4byte 0x084C07EC
_08020C58: .4byte 0x06010480
_08020C5C: .4byte 0x800000C0
_08020C60: .4byte 0x086ADEE0
_08020C64: .4byte 0x0000020A
_08020C68: .4byte gMain
_08020C6C: .4byte 0x0000FFFD
_08020C70:
	adds r0, r1, #0
	adds r0, #0x4c
	strh r2, [r0]
_08020C76:
	mov r7, sl
	ldr r3, [r7]
	ldr r1, _08020CD8 @ =0x0000020A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, r8
	ldrh r5, [r0]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r4, _08020CDC @ =gMain
	ldr r0, [r4, #0x44]
	adds r0, #0x98
	ldr r6, [r0]
	subs r2, r1, #1
	movs r0, #0xb1
	adds r1, r2, #0
	muls r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r7, _08020CE0 @ =0x0000061C
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08020CE8
	adds r0, r3, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r7, _08020CE4 @ =0x000001E3
	adds r0, r3, r7
	adds r0, r0, r2
	movs r1, #0
	b _08020CF4
	.align 2, 0
_08020CD8: .4byte 0x0000020A
_08020CDC: .4byte gMain
_08020CE0: .4byte 0x0000061C
_08020CE4: .4byte 0x000001E3
_08020CE8:
	movs r0, #0xb4
	strh r0, [r6, #4]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r3, r1
	adds r0, r0, r2
	movs r1, #1
_08020CF4:
	strb r1, [r0]
	movs r4, #0
	lsls r1, r5, #0x10
	ldr r2, _08020E18 @ =gOamBuffer
	mov sb, r2
	ldr r3, _08020E1C @ =0x086B4922
	mov r8, r3
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r0
	ldr r5, _08020E20 @ =0xFFFFFE00
	mov sl, r5
_08020D10:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, ip
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08020E24 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _08020D10
_08020D82:
	ldr r0, _08020E28 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0x74]
	ldrh r1, [r6]
	cmp r1, #0
	bne _08020D90
	b _08020EA4
_08020D90:
	movs r2, #0
	ldr r3, _08020E2C @ =0x040000D4
	mov sl, r3
_08020D96:
	lsls r2, r2, #0x10
	asrs r5, r2, #0x10
	ldr r4, _08020E28 @ =gMain
	ldr r1, [r4, #0x44]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r6, [r0, #0x74]
	movs r0, #0xb1
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r7, _08020E30 @ =0x020314E0
	ldr r4, [r7]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x10
	subs r1, r1, r0
	strh r1, [r6, #2]
	ldr r1, _08020E14 @ =0x000001E3
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r2
	cmp r0, #0
	beq _08020E44
	ldr r2, _08020E28 @ =gMain
	ldr r0, [r2, #0x50]
	movs r1, #5
	bl __umodsi3
	cmp r0, #0
	bne _08020E02
	ldr r3, _08020E34 @ =0x00000744
	adds r0, r4, r3
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08020E38 @ =0x084C07EC
	adds r0, r0, r1
	mov r4, sl
	str r0, [r4]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #7
	ldr r5, _08020E3C @ =0x06010480
	adds r0, r0, r5
	str r0, [r4, #4]
	ldr r0, _08020E40 @ =0x800000C0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
_08020E02:
	ldr r7, _08020E30 @ =0x020314E0
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	b _08020E46
	.align 2, 0
_08020E14: .4byte 0x000001E3
_08020E18: .4byte gOamBuffer
_08020E1C: .4byte 0x086B4922
_08020E20: .4byte 0xFFFFFE00
_08020E24: .4byte 0x000001FF
_08020E28: .4byte gMain
_08020E2C: .4byte 0x040000D4
_08020E30: .4byte 0x020314E0
_08020E34: .4byte 0x00000744
_08020E38: .4byte 0x084C07EC
_08020E3C: .4byte 0x06010480
_08020E40: .4byte 0x800000C0
_08020E44:
	movs r0, #0xc8
_08020E46:
	strh r0, [r6, #4]
	movs r4, #0
	ldr r7, _08020EB4 @ =gOamBuffer
	ldr r3, _08020EB8 @ =0xFFFFFE00
	mov sb, r3
_08020E50:
	lsls r3, r4, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	ldr r4, _08020EBC @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08020E50
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08020EA4
	b _08020D96
_08020EA4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020EB4: .4byte gOamBuffer
_08020EB8: .4byte 0xFFFFFE00
_08020EBC: .4byte 0x000001FF

	thumb_func_start sub_20EC0
sub_20EC0: @ 0x08020EC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08020F24 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r7, [r0]
	ldr r0, _08020F28 @ =0x020314E0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _08020EE6
	b _08021220
_08020EE6:
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r1, r0
	bne _08020F5C
	movs r0, #1
	strh r0, [r7]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08020F34
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08020F2C @ =0x00000442
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08020F30 @ =0x00001248
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	b _08021210
	.align 2, 0
_08020F24: .4byte gMain
_08020F28: .4byte 0x020314E0
_08020F2C: .4byte 0x00000442
_08020F30: .4byte 0x00001248
_08020F34:
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08020F58 @ =0x00000EEC
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	b _08021210
	.align 2, 0
_08020F58: .4byte 0x00000EEC
_08020F5C:
	ldr r0, _08021084 @ =0x0000031F
	cmp r1, r0
	bne _08020F82
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08020F82
	ldr r1, _08021088 @ =0x040000D4
	ldr r0, _0802108C @ =0x084C07EC
	str r0, [r1]
	ldr r0, _08021090 @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _08021094 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08020F82:
	ldr r4, _08021098 @ =0x086ADF90
	ldr r2, _0802109C @ =0x020314E0
	mov sl, r2
	ldr r3, [r2]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r0, r2, r4
	mov r8, r0
	subs r1, #8
	mov sb, r1
	adds r0, r3, r1
	ldr r0, [r0]
	adds r0, #0x78
	mov ip, r0
	mov r0, r8
	ldr r0, [r0]
	mov r1, ip
	subs r5, r0, r1
	adds r4, #4
	adds r2, r2, r4
	movs r0, #0x80
	lsls r0, r0, #2
	mov r8, r0
	add r3, r8
	ldr r0, [r3]
	adds r0, #0xa0
	ldr r1, [r2]
	subs r6, r1, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r1, r0
	str r1, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r6, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r6, _080210A0 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #4]
	ldr r0, _080210A4 @ =0x086AD788
	lsrs r4, r4, #0x1d
	lsls r4, r4, #1
	adds r4, r4, r0
	ldr r0, _080210A8 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x18
	bl __umodsi3
	lsrs r0, r0, #3
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r1, sl
	ldr r5, [r1]
	mov r2, sb
	adds r1, r5, r2
	ldr r0, [r1]
	ldr r2, [sp]
	adds r0, r0, r2
	str r0, [r1]
	mov r0, r8
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, [sp, #4]
	adds r0, r0, r2
	str r0, [r4]
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802114A
	ldr r0, [r1]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r0, [r4]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _080210AC
	movs r0, #0xb4
	strh r0, [r7, #4]
	b _080210B6
	.align 2, 0
_08021084: .4byte 0x0000031F
_08021088: .4byte 0x040000D4
_0802108C: .4byte 0x084C07EC
_08021090: .4byte 0x06010600
_08021094: .4byte 0x800000C0
_08021098: .4byte 0x086ADF90
_0802109C: .4byte 0x020314E0
_080210A0: .4byte 0x00004E20
_080210A4: .4byte 0x086AD788
_080210A8: .4byte gMain
_080210AC:
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080210B6
	strh r1, [r7, #4]
_080210B6:
	ldr r2, _080211B8 @ =0x040000D4
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r1, #0x1e
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080211BC @ =0x083E85AC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080211C0 @ =0x060112A0
	str r0, [r2, #4]
	ldr r0, _080211C4 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r6, _080211C8 @ =gOamBuffer
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
	ldr r2, _080211CC @ =0xFFFFFE00
	mov r8, r2
_080210E2:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, sb
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080211D0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _080210E2
_0802114A:
	ldr r0, _080211D4 @ =0x000009C3
	ldr r1, [sp, #8]
	cmp r1, r0
	bgt _08021210
	ldr r3, _080211D8 @ =0x020314E0
	ldr r1, [r3]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r5, #0
	strb r0, [r1]
	ldr r2, [r3]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bne _080211EC
	adds r1, #0x46
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08021210
	ldr r1, _080211B8 @ =0x040000D4
	ldr r0, _080211DC @ =0x084C156C
	str r0, [r1]
	ldr r0, _080211E0 @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _080211E4 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080211E8 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r5, [r0]
	ldr r0, [r3]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0x75
	bl m4aSongNumStart
	b _08021210
	.align 2, 0
_080211B8: .4byte 0x040000D4
_080211BC: .4byte 0x083E85AC
_080211C0: .4byte 0x060112A0
_080211C4: .4byte 0x80000090
_080211C8: .4byte gOamBuffer
_080211CC: .4byte 0xFFFFFE00
_080211D0: .4byte 0x000001FF
_080211D4: .4byte 0x000009C3
_080211D8: .4byte 0x020314E0
_080211DC: .4byte 0x084C156C
_080211E0: .4byte 0x06010600
_080211E4: .4byte 0x800000C0
_080211E8: .4byte gMain
_080211EC:
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _08021210
	ldr r0, _08021230 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r5, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
_08021210:
	ldr r0, _08021234 @ =0x020314E0
	ldr r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_08021220:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021230: .4byte gMain
_08021234: .4byte 0x020314E0

	thumb_func_start sub_21238
sub_21238: @ 0x08021238
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802127A
	ldr r3, _080212E0 @ =0x020314E0
	ldr r0, [r3]
	ldr r1, _080212E4 @ =0x00000714
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r3]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r4, _080212E8 @ =0x00000711
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r3]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _080212EC @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
_0802127A:
	ldr r5, _080212E0 @ =0x020314E0
	ldr r0, [r5]
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _080212F0 @ =0x000005F3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	movs r0, #0x16
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bne _080212A2
	movs r0, #0x14
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _080212C0
_080212A2:
	adds r0, r1, #0
	adds r0, #0x72
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0
	bne _080212C0
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _080212F4 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
_080212C0:
	ldr r0, _080212E0 @ =0x020314E0
	ldr r2, [r0]
	ldr r0, [r2, #0x14]
	ldr r1, _080212F8 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _080212FC @ =0x00020006
	cmp r0, r1
	bne _080212DA
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0
	strb r0, [r1]
_080212DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080212E0: .4byte 0x020314E0
_080212E4: .4byte 0x00000714
_080212E8: .4byte 0x00000711
_080212EC: .4byte 0x00000713
_080212F0: .4byte 0x000005F3
_080212F4: .4byte 0x000006C4
_080212F8: .4byte 0x00FF00FF
_080212FC: .4byte 0x00020006

	thumb_func_start sub_21300
sub_21300: @ 0x08021300
	ldr r2, _08021318 @ =0x020314E0
	ldr r1, [r2]
	movs r3, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	movs r1, #0
	strh r3, [r0, #0x18]
	ldr r2, _0802131C @ =0x000006DD
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_08021318: .4byte 0x020314E0
_0802131C: .4byte 0x000006DD

	thumb_func_start sub_21320
sub_21320: @ 0x08021320
	push {r4, lr}
	ldr r1, _08021340 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r0, #6
	bls _08021336
	b _0802150C
_08021336:
	lsls r0, r0, #2
	ldr r1, _08021344 @ =_08021348
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021340: .4byte 0x020314E0
_08021344: .4byte _08021348
_08021348: @ jump table
	.4byte _08021364 @ case 0
	.4byte _080213B2 @ case 1
	.4byte _080213E8 @ case 2
	.4byte _0802144C @ case 3
	.4byte _080214CC @ case 4
	.4byte _080214E0 @ case 5
	.4byte _080214F8 @ case 6
_08021364:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #8
	bls _0802136E
	b _0802150C
_0802136E:
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08021386
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _0802150C
_08021386:
	cmp r0, #8
	beq _0802138C
	b _0802150C
_0802138C:
	bl sub_219A8
	ldr r0, [r4]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0
	str r1, [r0]
	movs r0, #1
	bl sub_1C7F4
	ldr r1, [r4]
	b _080214EA
_080213B2:
	bl sub_219EC
	ldr r4, _080213E4 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080213CE
	movs r0, #1
	movs r1, #0
	bl sub_1C7F4
_080213CE:
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _080213E0
	b _0802150C
_080213E0:
	b _080214EA
	.align 2, 0
_080213E4: .4byte 0x020314E0
_080213E8:
	ldr r0, [r4]
	ldr r3, _08021440 @ =0x00000714
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _08021444 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	bl sub_29D9C
	ldr r0, [r4]
	ldr r3, _08021448 @ =0x0000062D
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802150C
	adds r0, #1
	strb r0, [r1]
	b _0802150C
	.align 2, 0
_08021440: .4byte 0x00000714
_08021444: .4byte 0x00000713
_08021448: .4byte 0x0000062D
_0802144C:
	ldr r0, _08021464 @ =0x020314E0
	ldr r2, [r0]
	ldrh r0, [r2, #0x28]
	adds r1, r0, #0
	cmp r1, #0x94
	bne _08021468
	adds r0, #1
	strh r0, [r2, #0x28]
	bl sub_2A054
	b _08021484
	.align 2, 0
_08021464: .4byte 0x020314E0
_08021468:
	cmp r1, #0x8b
	beq _08021484
	cmp r1, #0x18
	bne _0802147A
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	b _08021484
_0802147A:
	cmp r1, #0
	bne _08021484
	ldrb r0, [r2, #0x17]
	adds r0, #1
	strb r0, [r2, #0x17]
_08021484:
	ldr r4, _080214C0 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _080214C4 @ =0x000006DD
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080214B4
	bl sub_2A354
	ldr r1, [r4]
	ldr r3, _080214C8 @ =0x000006DE
	adds r2, r1, r3
	ldrh r0, [r2]
	cmp r0, #0xb3
	bhi _080214B4
	movs r0, #0x8c
	strh r0, [r1, #0x28]
	ldrh r0, [r2]
	cmp r0, #0xb3
	bne _080214B4
	movs r0, #0x1e
	strh r0, [r1, #0x28]
_080214B4:
	ldr r0, _080214C0 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x18]
	b _0802150C
	.align 2, 0
_080214C0: .4byte 0x020314E0
_080214C4: .4byte 0x000006DD
_080214C8: .4byte 0x000006DE
_080214CC:
	bl sub_219EC
	ldr r0, _080214DC @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r0, #0
	strh r0, [r1]
	b _080214E6
	.align 2, 0
_080214DC: .4byte gMain
_080214E0:
	movs r0, #1
	bl sub_21238
_080214E6:
	ldr r0, _080214F4 @ =0x020314E0
	ldr r1, [r0]
_080214EA:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _0802150C
	.align 2, 0
_080214F4: .4byte 0x020314E0
_080214F8:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08021506
	subs r0, #1
	strh r0, [r1, #0x18]
	b _0802150C
_08021506:
	movs r0, #1
	bl sub_19B64
_0802150C:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_21514
sub_21514: @ 0x08021514
	push {r4, r5, lr}
	ldr r5, _0802156C @ =0x020314E0
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08021570 @ =0x000005F3
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _08021574 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #0x5f
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802156C: .4byte 0x020314E0
_08021570: .4byte 0x000005F3
_08021574: .4byte 0x000006C4

	thumb_func_start sub_21578
sub_21578: @ 0x08021578
	push {r4, lr}
	ldr r0, _080215A8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0802161C
	ldr r4, _080215AC @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _080215B0 @ =0x00000283
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0802159C
	b _080216AE
_0802159C:
	lsls r0, r0, #2
	ldr r1, _080215B4 @ =_080215B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080215A8: .4byte gMain
_080215AC: .4byte 0x020314E0
_080215B0: .4byte 0x00000283
_080215B4: .4byte _080215B8
_080215B8: @ jump table
	.4byte _080215CC @ case 0
	.4byte _080215E8 @ case 1
	.4byte _080215CC @ case 2
	.4byte _080215E8 @ case 3
	.4byte _08021604 @ case 4
_080215CC:
	ldr r0, [r4]
	ldr r2, _080215E4 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2a
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #3
	b _080216AC
	.align 2, 0
_080215E4: .4byte 0x000006EC
_080215E8:
	ldr r0, [r4]
	ldr r2, _08021600 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2c
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	b _080216AC
	.align 2, 0
_08021600: .4byte 0x000006EC
_08021604:
	ldr r0, [r4]
	ldr r2, _08021618 @ =0x000006EC
	adds r0, r0, r2
	movs r1, #0x2d
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	b _080216AA
	.align 2, 0
_08021618: .4byte 0x000006EC
_0802161C:
	ldr r4, _08021640 @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _08021644 @ =0x00000283
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080216AE
	lsls r0, r0, #2
	ldr r1, _08021648 @ =_0802164C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021640: .4byte 0x020314E0
_08021644: .4byte 0x00000283
_08021648: .4byte _0802164C
_0802164C: @ jump table
	.4byte _08021660 @ case 0
	.4byte _0802167C @ case 1
	.4byte _08021660 @ case 2
	.4byte _0802167C @ case 3
	.4byte _08021698 @ case 4
_08021660:
	ldr r0, [r4]
	ldr r1, _08021678 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x29
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #2
	b _080216AC
	.align 2, 0
_08021678: .4byte 0x000006EC
_0802167C:
	ldr r0, [r4]
	ldr r1, _08021694 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2b
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #4
	b _080216AC
	.align 2, 0
_08021694: .4byte 0x000006EC
_08021698:
	ldr r0, [r4]
	ldr r1, _080216D8 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2d
	strb r1, [r0]
	ldr r0, [r4]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r0, r2
_080216AA:
	movs r1, #6
_080216AC:
	strb r1, [r0]
_080216AE:
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080216DC
	movs r0, #0x15
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _080216DC
	movs r1, #0
	movs r0, #0x96
	strh r0, [r2, #0x28]
	movs r0, #3
	strb r0, [r2, #0x17]
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	b _080216F4
	.align 2, 0
_080216D8: .4byte 0x000006EC
_080216DC:
	ldr r0, [r4]
	movs r1, #0
	strb r1, [r0, #0x17]
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r0, r2
	str r1, [r0]
	movs r0, #7
	bl sub_1C7F4
_080216F4:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_216FC
sub_216FC: @ 0x080216FC
	push {r4, lr}
	ldr r1, _0802171C @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #8
	bls _08021710
	b _080219A2
_08021710:
	lsls r0, r0, #2
	ldr r1, _08021720 @ =_08021724
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802171C: .4byte 0x020314E0
_08021720: .4byte _08021724
_08021724: @ jump table
	.4byte _08021748 @ case 0
	.4byte _0802175C @ case 1
	.4byte _080217FC @ case 2
	.4byte _08021824 @ case 3
	.4byte _08021850 @ case 4
	.4byte _08021938 @ case 5
	.4byte _08021960 @ case 6
	.4byte _08021988 @ case 7
	.4byte _0802199C @ case 8
_08021748:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x3b
	bhi _08021756
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080219A2
_08021756:
	movs r0, #0
	strh r0, [r1, #0x18]
	b _08021990
_0802175C:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #8
	bls _08021766
	b _080219A2
_08021766:
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0802177E
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	b _080219A2
_0802177E:
	cmp r0, #8
	beq _08021784
	b _080219A2
_08021784:
	ldr r2, _080217A4 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080217CE
	lsls r0, r0, #2
	ldr r1, _080217A8 @ =_080217AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080217A4: .4byte 0x00000283
_080217A8: .4byte _080217AC
_080217AC: @ jump table
	.4byte _080217C0 @ case 0
	.4byte _080217C8 @ case 1
	.4byte _080217C0 @ case 2
	.4byte _080217C8 @ case 3
	.4byte _080217C8 @ case 4
_080217C0:
	movs r0, #0xe
	bl m4aSongNumStart
	b _080217CE
_080217C8:
	movs r0, #0xf
	bl m4aSongNumStart
_080217CE:
	bl sub_219A8
	ldr r2, _080217F8 @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r3, #0
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	str r3, [r0]
	b _080219A2
	.align 2, 0
_080217F8: .4byte 0x020314E0
_080217FC:
	bl sub_219EC
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08021820 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802181C
	b _080219A2
_0802181C:
	b _08021990
	.align 2, 0
_08021820: .4byte 0x020314E0
_08021824:
	ldr r1, [r3]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	movs r2, #0
	strb r0, [r1, #0x17]
	ldr r0, [r3]
	strh r2, [r0, #0x18]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r1, r0, r3
	str r2, [r1]
	ldr r1, _0802184C @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2e
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	b _080219A2
	.align 2, 0
_0802184C: .4byte 0x000006EC
_08021850:
	ldr r4, _08021874 @ =0x020314E0
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x91
	bne _080218C4
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r0, _08021878 @ =gMain
	ldrh r2, [r0, #0x18]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0802187C
	movs r0, #0x90
	strh r0, [r1, #0x28]
	bl m4aMPlayAllStop
	b _080218B0
	.align 2, 0
_08021874: .4byte 0x020314E0
_08021878: .4byte gMain
_0802187C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080218B0
	bl m4aMPlayAllStop
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x3c
	strh r0, [r1, #0x28]
	movs r0, #6
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r2, _08021924 @ =0x00000714
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080218B0
	ldr r3, _08021928 @ =0x000006EE
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
_080218B0:
	ldr r0, _0802192C @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _08021930 @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2e
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
_080218C4:
	ldr r4, _0802192C @ =0x020314E0
	ldr r0, [r4]
	ldrh r0, [r0, #0x28]
	cmp r0, #0x82
	bne _080218E2
	movs r0, #0x9f
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x41
	strh r0, [r1, #0x18]
	ldr r1, _08021934 @ =gMain
	ldrh r0, [r1, #0x38]
	movs r0, #0x9f
	strh r0, [r1, #0x38]
_080218E2:
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x7d
	bne _080218EE
	adds r0, #1
	strh r0, [r1, #0x28]
_080218EE:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080219A2
	movs r2, #0x88
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, [r4]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldr r2, _08021934 @ =gMain
	ldrh r0, [r3, #0x18]
	lsrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r2, #0x3c]
	strh r1, [r2, #0x3c]
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	bne _080219A2
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	b _080219A2
	.align 2, 0
_08021924: .4byte 0x00000714
_08021928: .4byte 0x000006EE
_0802192C: .4byte 0x020314E0
_08021930: .4byte 0x000006EC
_08021934: .4byte gMain
_08021938:
	ldr r2, [r3]
	ldrh r0, [r2, #0x18]
	cmp r0, #0x1d
	bhi _08021946
	adds r0, #1
	strh r0, [r2, #0x18]
	b _080219A2
_08021946:
	movs r1, #0
	movs r0, #0
	strh r0, [r2, #0x18]
	strb r1, [r2, #0x17]
	ldr r0, [r3]
	ldr r3, _0802195C @ =0x00000282
	adds r0, r0, r3
	strb r1, [r0]
	bl sub_1C73C
	b _080219A2
	.align 2, 0
_0802195C: .4byte 0x00000282
_08021960:
	bl sub_219EC
	ldr r0, _08021980 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x34]
	movs r3, #0
	strh r3, [r0]
	ldr r2, _08021984 @ =0x020314E0
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	strh r3, [r0, #0x18]
	b _080219A2
	.align 2, 0
_08021980: .4byte gMain
_08021984: .4byte 0x020314E0
_08021988:
	bl sub_21514
	ldr r0, _08021998 @ =0x020314E0
	ldr r1, [r0]
_08021990:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _080219A2
	.align 2, 0
_08021998: .4byte 0x020314E0
_0802199C:
	movs r0, #1
	bl sub_19B64
_080219A2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_219A8
sub_219A8: @ 0x080219A8
	ldr r1, _080219D0 @ =0x040000D4
	ldr r0, _080219D4 @ =0x0844838C
	str r0, [r1]
	ldr r0, _080219D8 @ =0x060113C0
	str r0, [r1, #4]
	ldr r0, _080219DC @ =0x80000180
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080219E0 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080219E4 @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _080219E8 @ =0x000005F3
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080219D0: .4byte 0x040000D4
_080219D4: .4byte 0x0844838C
_080219D8: .4byte 0x060113C0
_080219DC: .4byte 0x80000180
_080219E0: .4byte gMain
_080219E4: .4byte 0x020314E0
_080219E8: .4byte 0x000005F3

	thumb_func_start sub_219EC
sub_219EC: @ 0x080219EC
	push {r4, r5, r6, r7, lr}
	ldr r0, _08021A58 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r6, [r0, #0x34]
	ldr r5, _08021A5C @ =0x020314E0
	ldr r4, [r5]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x23
	bl __umodsi3
	movs r1, #7
	bl __udivsi3
	ldr r3, _08021A60 @ =0x0000020B
	adds r4, r4, r3
	strb r0, [r4]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08021AE8
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x78
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08021A40
	movs r0, #0xc8
	strh r0, [r6, #4]
_08021A40:
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08021A64
	movs r0, #0xc8
	strh r0, [r6, #4]
	b _08021A9C
	.align 2, 0
_08021A58: .4byte gMain
_08021A5C: .4byte 0x020314E0
_08021A60: .4byte 0x0000020B
_08021A64:
	adds r3, r4, r3
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08021A9C
	ldr r2, _08021AF0 @ =0x040000D4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _08021AF4 @ =0x0844838C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021AF8 @ =0x060113C0
	str r0, [r2, #4]
	ldr r0, _08021AFC @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r1, [r3]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08021A9C:
	movs r0, #0
	ldr r7, _08021B00 @ =gOamBuffer
	ldr r1, _08021B04 @ =0xFFFFFE00
	mov ip, r1
_08021AA4:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08021B08 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _08021AA4
_08021AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021AF0: .4byte 0x040000D4
_08021AF4: .4byte 0x0844838C
_08021AF8: .4byte 0x060113C0
_08021AFC: .4byte 0x80000180
_08021B00: .4byte gOamBuffer
_08021B04: .4byte 0xFFFFFE00
_08021B08: .4byte 0x000001FF

	thumb_func_start sub_21B0C
sub_21B0C: @ 0x08021B0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08021BE8 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r7, [r0, #0x44]
	mov r0, sp
	movs r1, #0
	movs r2, #6
	bl memset
	ldr r5, _08021BEC @ =0x020314E0
	ldr r6, [r5]
	movs r0, #0xe5
	lsls r0, r0, #1
	adds r3, r6, r0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08021B44
	b _08021C5C
_08021B44:
	cmp r1, #0xc
	bne _08021C40
	movs r0, #0xe7
	lsls r0, r0, #1
	mov sb, r0
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	beq _08021BF0
	subs r0, #1
	strh r0, [r1]
	ldrh r4, [r1]
	adds r0, r4, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __udivsi3
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r4, #0x28
	bhi _08021C14
	cmp r4, #2
	bls _08021B98
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r1, #3
	strh r1, [r0]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
_08021B98:
	ldr r5, [r5]
	mov r0, sb
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #7
	movs r4, #0x28
	movs r1, #0x28
	bl __divsi3
	adds r0, #0x80
	movs r2, #0xed
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r5, r5, r1
	strh r0, [r5]
	mov r5, sp
	ldrh r0, [r6]
	subs r0, r4, r0
	lsls r0, r0, #4
	movs r1, #0x28
	bl __divsi3
	strh r0, [r5, #2]
	mov r5, sp
	ldrh r0, [r6]
	subs r4, r4, r0
	lsls r4, r4, #4
	rsbs r4, r4, #0
	adds r0, r4, #0
	movs r1, #0x28
	bl __divsi3
	strh r0, [r5]
	mov r1, sp
	movs r0, #0
	strh r0, [r1, #4]
	b _08021C14
	.align 2, 0
_08021BE8: .4byte gMain
_08021BEC: .4byte 0x020314E0
_08021BF0:
	movs r0, #0xd
	strh r0, [r4]
	strh r0, [r3]
	mov r8, r0
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_08021C14:
	ldr r2, _08021C30 @ =0x040000D4
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #9
	ldr r1, _08021C34 @ =0x084C00EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021C38 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _08021C3C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08021C5C
	.align 2, 0
_08021C30: .4byte 0x040000D4
_08021C34: .4byte 0x084C00EC
_08021C38: .4byte 0x06010AE0
_08021C3C: .4byte 0x80000040
_08021C40:
	ldr r2, _08021C98 @ =0x040000D4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #7
	ldr r1, _08021C9C @ =0x084C00EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021CA0 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _08021CA4 @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrh r0, [r3]
	strh r0, [r4]
_08021C5C:
	ldr r0, _08021CA8 @ =0x020314E0
	ldr r3, [r0]
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r2, [r1]
	adds r4, r0, #0
	cmp r2, #0
	beq _08021CAC
	subs r0, r2, #1
	strh r0, [r1]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r7, #4]
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _08021CB0
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x10
	adds r2, #4
	adds r1, r3, r2
	strh r0, [r1]
	b _08021CB0
	.align 2, 0
_08021C98: .4byte 0x040000D4
_08021C9C: .4byte 0x084C00EC
_08021CA0: .4byte 0x06010AE0
_08021CA4: .4byte 0x80000040
_08021CA8: .4byte 0x020314E0
_08021CAC:
	movs r0, #0xb4
	strh r0, [r7, #4]
_08021CB0:
	ldr r1, [r4]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, #0x77
	strh r0, [r7, #2]
	adds r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #1
	bl sub_7C0
	movs r0, #0
	ldr r6, _08021D6C @ =gOamBuffer
	ldr r1, _08021D70 @ =0xFFFFFE00
	mov ip, r1
	movs r2, #4
	rsbs r2, r2, #0
	mov sb, r2
	movs r1, #0xf
	rsbs r1, r1, #0
	mov r8, r1
_08021CEA:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	lsls r0, r5, #1
	add r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _08021D74 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	mov r0, sb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #3]
	mov r0, r8
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #3]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _08021CEA
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021D6C: .4byte gOamBuffer
_08021D70: .4byte 0xFFFFFE00
_08021D74: .4byte 0x000001FF

	thumb_func_start sub_21D78
sub_21D78: @ 0x08021D78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _08021DD8 @ =0x0200EBC8
	ldr r4, _08021DDC @ =0x020314E0
	ldr r6, [r4]
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r3, #0
	ldrsb r3, [r2, r3]
	cmp r3, #0
	bne _08021E2C
	ldr r1, _08021DE0 @ =0x0000072E
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08021DEC
	ldr r1, _08021DE4 @ =0x00000281
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _08021DB0
	b _08021F86
_08021DB0:
	subs r1, #0xdc
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08021DC0
	b _08021F86
_08021DC0:
	movs r1, #1
	strb r1, [r2]
	ldr r2, [r4]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r3, [r0]
	ldr r3, _08021DE8 @ =0x000001A5
	adds r0, r2, r3
	strb r1, [r0]
	b _08021F86
	.align 2, 0
_08021DD8: .4byte 0x0200EBC8
_08021DDC: .4byte 0x020314E0
_08021DE0: .4byte 0x0000072E
_08021DE4: .4byte 0x00000281
_08021DE8: .4byte 0x000001A5
_08021DEC:
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	cmp r0, #6
	bne _08021DF6
	b _08021F86
_08021DF6:
	ldr r5, _08021E28 @ =0x000001A5
	adds r0, r6, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #1
	beq _08021E04
	b _08021F86
_08021E04:
	adds r0, r6, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08021E14
	b _08021F86
_08021E14:
	strb r1, [r2]
	ldr r0, [r4]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r2, #0
	strh r3, [r1]
	adds r0, r0, r5
	strb r2, [r0]
	b _08021F86
	.align 2, 0
_08021E28: .4byte 0x000001A5
_08021E2C:
	ldr r5, _08021E7C @ =0x086AD456
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	ldr r2, _08021E80 @ =0x000001A5
	adds r1, r6, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r5, [r0]
	cmp r4, #0
	bne _08021E94
	movs r0, #1
	strh r0, [r7]
	ldr r1, _08021E84 @ =0x040000D4
	ldr r0, _08021E88 @ =0x083A8A8C
	str r0, [r1]
	ldr r0, _08021E8C @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _08021E90 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08021E9E
	.align 2, 0
_08021E7C: .4byte 0x086AD456
_08021E80: .4byte 0x000001A5
_08021E84: .4byte 0x040000D4
_08021E88: .4byte 0x083A8A8C
_08021E8C: .4byte 0x05000240
_08021E90: .4byte 0x80000010
_08021E94:
	cmp r4, #0x25
	bne _08021E9E
	movs r0, #0xca
	bl m4aSongNumStart
_08021E9E:
	ldr r4, _08021F90 @ =0x020314E0
	ldr r0, [r4]
	movs r3, #0xda
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	mov r8, r4
	cmp r0, #0
	bne _08021ED4
	ldr r2, _08021F94 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _08021F98 @ =0x084F6B0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08021F9C @ =0x06013D00
	str r0, [r2, #4]
	ldr r0, _08021FA0 @ =0x80000280
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08021ED4:
	mov r4, r8
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xb5
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0x30
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08021EFC
	strh r1, [r7, #4]
_08021EFC:
	movs r0, #0
	ldr r6, _08021FA4 @ =gOamBuffer
	ldr r1, _08021FA8 @ =0xFFFFFE00
	mov ip, r1
_08021F04:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r6
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08021FAC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _08021F04
	mov r3, r8
	ldr r2, [r3]
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _08021F86
	ldr r1, _08021FB0 @ =0x000001A5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_4E9F0
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08021FB4 @ =gMain
	ldr r4, _08021FB8 @ =0x00003B08
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
_08021F86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021F90: .4byte 0x020314E0
_08021F94: .4byte 0x040000D4
_08021F98: .4byte 0x084F6B0C
_08021F9C: .4byte 0x06013D00
_08021FA0: .4byte 0x80000280
_08021FA4: .4byte gOamBuffer
_08021FA8: .4byte 0xFFFFFE00
_08021FAC: .4byte 0x000001FF
_08021FB0: .4byte 0x000001A5
_08021FB4: .4byte gMain
_08021FB8: .4byte 0x00003B08

	thumb_func_start sub_21FBC
sub_21FBC: @ 0x08021FBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r5, _08022168 @ =gMain
	ldr r1, [r5, #0x44]
	ldr r7, [r1, #0x1c]
	ldr r3, _0802216C @ =0x086AD2DE
	ldr r4, _08022170 @ =0x020314E0
	ldr r1, [r4]
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r1, [r1]
	lsls r1, r1, #3
	ldr r2, _08022174 @ =0x086AD000
	adds r1, r1, r2
	mov r8, r1
	lsls r0, r0, #0x10
	mov sl, r4
	cmp r0, #0
	beq _0802202E
	ldrh r0, [r1, #6]
	movs r1, #0xa
	bl __udivsi3
	ldr r4, _08022178 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	ldr r6, _0802217C @ =0x08480E0C
	adds r0, r0, r6
	str r0, [r4]
	ldr r0, _08022180 @ =0x06015DA0
	str r0, [r4, #4]
	ldr r5, _08022184 @ =0x80000020
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r3, r8
	ldrh r0, [r3, #6]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	adds r0, r0, r6
	str r0, [r4]
	ldr r0, _08022188 @ =0x06015E60
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
_0802202E:
	ldrh r0, [r7]
	cmp r0, #0
	beq _08022094
	mov r4, sl
	ldr r0, [r4]
	movs r6, #0xdb
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, #0x9c
	strh r0, [r7, #2]
	movs r0, #0x60
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _0802218C @ =gOamBuffer
	ldr r0, _08022190 @ =0xFFFFFE00
	mov r8, r0
_08022050:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08022194 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08022050
_08022094:
	ldr r3, _08022168 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x20]
	mov r4, sl
	ldr r2, [r4]
	ldr r6, _08022198 @ =0x000001A5
	adds r0, r2, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802214C
	movs r3, #0xdb
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #0x88
	strh r0, [r7, #2]
	movs r0, #0x58
	strh r0, [r7, #4]
	movs r5, #0
	ldr r4, _0802218C @ =gOamBuffer
	mov r8, r4
	ldr r6, _0802219C @ =0x086B47DE
	mov ip, r6
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	str r0, [sp, #8]
	ldr r0, _08022190 @ =0xFFFFFE00
	mov sb, r0
_080220D8:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r4, [sp, #8]
	adds r0, r0, r4
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _08022194 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #4
	ble _080220D8
_0802214C:
	ldr r3, _08022168 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x18]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0802215A
	b _08022470
_0802215A:
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _080221A0
	movs r0, #0xb4
	b _080221A2
	.align 2, 0
_08022168: .4byte gMain
_0802216C: .4byte 0x086AD2DE
_08022170: .4byte 0x020314E0
_08022174: .4byte 0x086AD000
_08022178: .4byte 0x040000D4
_0802217C: .4byte 0x08480E0C
_08022180: .4byte 0x06015DA0
_08022184: .4byte 0x80000020
_08022188: .4byte 0x06015E60
_0802218C: .4byte gOamBuffer
_08022190: .4byte 0xFFFFFE00
_08022194: .4byte 0x000001FF
_08022198: .4byte 0x000001A5
_0802219C: .4byte 0x086B47DE
_080221A0:
	movs r0, #0x56
_080221A2:
	strh r0, [r7, #4]
	mov r5, sp
	ldr r4, _08022254 @ =0x086ADFC8
	ldr r6, _08022258 @ =gMain
	ldr r0, [r6, #0x4c]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	rsbs r0, r1, #0
	strh r0, [r5]
	mov r0, sp
	strh r1, [r0, #2]
	add r1, sp, #4
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	mov r0, sl
	ldr r2, [r0]
	ldr r3, _0802225C @ =0x000001A5
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0802226C
	movs r5, #0
	movs r4, #0x28
	adds r4, r4, r7
	mov ip, r4
	movs r6, #0x30
	adds r6, r6, r7
	mov sb, r6
	ldr r6, _08022260 @ =gOamBuffer
	ldr r0, _08022264 @ =0xFFFFFE00
	mov r8, r0
_080221F8:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	lsls r1, r0, #1
	adds r0, r1, r0
	lsls r0, r0, #3
	add r1, sp
	ldrh r1, [r1]
	adds r1, #0x24
	adds r0, r0, r1
	strh r0, [r7, #2]
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08022268 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _080221F8
	b _0802233E
	.align 2, 0
_08022254: .4byte 0x086ADFC8
_08022258: .4byte gMain
_0802225C: .4byte 0x000001A5
_08022260: .4byte gOamBuffer
_08022264: .4byte 0xFFFFFE00
_08022268: .4byte 0x000001FF
_0802226C:
	ldr r3, _080222EC @ =0x00000281
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _080222FC
	movs r5, #0
	movs r4, #0x28
	adds r4, r4, r7
	mov ip, r4
	movs r6, #0x30
	adds r6, r6, r7
	mov sb, r6
	ldr r6, _080222F0 @ =gOamBuffer
	ldr r0, _080222F4 @ =0xFFFFFE00
	mov r8, r0
_0802228E:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r0, r4, r0
	asrs r0, r0, #1
	lsls r1, r0, #1
	adds r0, r1, r0
	lsls r0, r0, #3
	add r1, sp
	ldrh r1, [r1]
	adds r1, #0x24
	adds r0, r0, r1
	strh r0, [r7, #2]
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080222F8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0802228E
	b _0802233E
	.align 2, 0
_080222EC: .4byte 0x00000281
_080222F0: .4byte gOamBuffer
_080222F4: .4byte 0xFFFFFE00
_080222F8: .4byte 0x000001FF
_080222FC:
	movs r5, #0
	movs r3, #0x28
	adds r3, r3, r7
	mov ip, r3
	movs r4, #0x30
	adds r4, r4, r7
	mov sb, r4
	ldr r4, _08022354 @ =gOamBuffer
	ldr r6, _08022358 @ =0xFFFFFE00
	mov r8, r6
	movs r6, #0xb4
_08022312:
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrh r3, [r1, #2]
	mov r0, r8
	ands r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	strb r6, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _08022312
_0802233E:
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _0802235C @ =0x000001A5
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08022360
	movs r0, #0xb4
	b _08022376
	.align 2, 0
_08022354: .4byte gOamBuffer
_08022358: .4byte 0xFFFFFE00
_0802235C: .4byte 0x000001A5
_08022360:
	ldr r3, _08022370 @ =gMain
	movs r4, #0x2a
	ldrsh r0, [r3, r4]
	cmp r0, #0x13
	bgt _08022374
	movs r0, #0xb4
	b _08022376
	.align 2, 0
_08022370: .4byte gMain
_08022374:
	movs r0, #0x56
_08022376:
	strh r0, [r7, #4]
	movs r0, #0x30
	strh r0, [r7, #2]
	mov r6, sl
	ldr r0, [r6]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080223D0 @ =0x0000025D
	adds r0, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _080223DC
	mov r5, ip
	ldrh r2, [r7, #0x28]
	lsls r2, r2, #3
	ldr r4, _080223D4 @ =gOamBuffer
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	adds r1, #0x30
	subs r3, #0x5e
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080223D8 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r2, [r7, #0x28]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r7, #4]
	ldrb r5, [r5, #4]
	adds r1, r1, r5
	mov r4, sp
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r2]
	b _080223F6
	.align 2, 0
_080223D0: .4byte 0x0000025D
_080223D4: .4byte gOamBuffer
_080223D8: .4byte 0xFFFFFE00
_080223DC:
	ldrh r1, [r7, #0x28]
	lsls r1, r1, #3
	ldr r6, _08022448 @ =gOamBuffer
	adds r1, r1, r6
	ldrh r2, [r1, #2]
	ldr r0, _0802244C @ =0xFFFFFE00
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
_080223F6:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08022454
	mov r5, sb
	ldrh r2, [r7, #0x30]
	lsls r2, r2, #3
	ldr r3, _08022448 @ =gOamBuffer
	adds r2, r2, r3
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r3, _08022450 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802244C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r2, [r7, #0x30]
	lsls r2, r2, #3
	ldr r4, _08022448 @ =gOamBuffer
	adds r2, r2, r4
	ldrb r1, [r7, #4]
	ldrb r5, [r5, #4]
	adds r1, r1, r5
	mov r6, sp
	ldrh r0, [r6, #6]
	adds r0, r0, r1
	strb r0, [r2]
	b _08022470
	.align 2, 0
_08022448: .4byte gOamBuffer
_0802244C: .4byte 0xFFFFFE00
_08022450: .4byte 0x000001FF
_08022454:
	ldrh r1, [r7, #0x30]
	lsls r1, r1, #3
	ldr r0, _08022490 @ =gOamBuffer
	adds r1, r1, r0
	ldrh r2, [r1, #2]
	ldr r0, _08022494 @ =0xFFFFFE00
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #3
	ldr r1, _08022490 @ =gOamBuffer
	adds r0, r0, r1
	movs r1, #0xb4
	strb r1, [r0]
_08022470:
	ldr r2, _08022498 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x24]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0802247E
	b _080225BE
_0802247E:
	movs r0, #0x30
	strh r0, [r7, #2]
	movs r3, #0x2a
	ldrsh r0, [r2, r3]
	cmp r0, #0x13
	bgt _0802249C
	movs r0, #0xb4
	b _0802249E
	.align 2, 0
_08022490: .4byte gOamBuffer
_08022494: .4byte 0xFFFFFE00
_08022498: .4byte gMain
_0802249C:
	movs r0, #0x58
_0802249E:
	strh r0, [r7, #4]
	mov r4, sl
	ldr r1, [r4]
	movs r6, #0xd3
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	ldr r2, _080224EC @ =0x086AD2DE
	adds r0, r0, r2
	ldrh r3, [r0]
	cmp r3, #4
	bne _080224F8
	ldr r3, _080224F0 @ =0x000001AF
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080224DC
	movs r4, #0xdc
	lsls r4, r4, #1
	adds r0, r1, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08022522
_080224DC:
	ldr r4, _080224F4 @ =0x086ADFD4
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08022544
	.align 2, 0
_080224EC: .4byte 0x086AD2DE
_080224F0: .4byte 0x000001AF
_080224F4: .4byte 0x086ADFD4
_080224F8:
	cmp r3, #3
	bne _0802253C
	movs r4, #0xd5
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08022526
	movs r6, #0xdc
	lsls r6, r6, #1
	adds r0, r1, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08022526
_08022522:
	movs r1, #4
	b _08022556
_08022526:
	ldr r4, _08022538 @ =0x086ADFD4
	mov r2, sl
	ldr r0, [r2]
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	b _08022548
	.align 2, 0
_08022538: .4byte 0x086ADFD4
_0802253C:
	ldr r4, _080225D0 @ =0x086ADFD4
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r0, r1, r2
_08022544:
	movs r3, #0
	ldrsh r0, [r0, r3]
_08022548:
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r1, [r0]
_08022556:
	ldr r2, _080225D4 @ =0x040000D4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _080225D8 @ =0x0847FF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080225DC @ =0x06016220
	str r0, [r2, #4]
	ldr r0, _080225E0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r5, #0
	ldr r6, _080225E4 @ =gOamBuffer
	ldr r4, _080225E8 @ =0xFFFFFE00
	mov r8, r4
_0802257A:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080225EC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0802257A
_080225BE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080225D0: .4byte 0x086ADFD4
_080225D4: .4byte 0x040000D4
_080225D8: .4byte 0x0847FF0C
_080225DC: .4byte 0x06016220
_080225E0: .4byte 0x80000180
_080225E4: .4byte gOamBuffer
_080225E8: .4byte 0xFFFFFE00
_080225EC: .4byte 0x000001FF

	thumb_func_start sub_225F0
sub_225F0: @ 0x080225F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _08022680 @ =gMain
	ldr r0, [r5, #0x44]
	adds r0, #0x9c
	ldr r7, [r0]
	ldr r2, _08022684 @ =0x020314E0
	ldr r3, [r2]
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r4, [r0]
	movs r6, #0xca
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r1, r0, #3
	adds r1, r1, r0
	adds r1, #0x13
	mov sl, r2
	cmp r4, r1
	blt _0802262A
	b _08022958
_0802262A:
	cmp r4, #0
	bne _08022690
	movs r1, #0
	movs r0, #1
	strh r0, [r7]
	ldr r2, _08022688 @ =0x00000193
	adds r0, r3, r2
	strb r1, [r0]
	movs r2, #0
_0802263C:
	mov r3, sl
	ldr r4, [r3]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r0, r4, r5
	adds r0, r0, r2
	movs r5, #0
	strh r5, [r0]
	lsls r0, r1, #2
	adds r3, r4, r0
	movs r6, #0xce
	lsls r6, r6, #1
	adds r2, r3, r6
	movs r0, #0x46
	strh r0, [r2]
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0xb4
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #1
	ble _0802263C
	ldr r1, _0802268C @ =0x00000195
	adds r0, r4, r1
	strb r5, [r0]
	b _08022908
	.align 2, 0
_08022680: .4byte gMain
_08022684: .4byte 0x020314E0
_08022688: .4byte 0x00000193
_0802268C: .4byte 0x00000195
_08022690:
	adds r0, r3, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080226B6
	ldrb r0, [r3, #5]
	cmp r0, #0
	bne _080226AE
	ldrh r1, [r5, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080226B6
_080226AE:
	ldr r2, _0802279C @ =0x00000195
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
_080226B6:
	mov r3, sl
	ldr r5, [r3]
	ldr r4, _080227A0 @ =0x00000193
	mov sb, r4
	adds r6, r5, r4
	movs r0, #0xca
	lsls r0, r0, #1
	mov r8, r0
	adds r0, r5, r0
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _080226D8
	b _0802280E
_080226D8:
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r4, r0, #1
	adds r0, r4, #0
	movs r1, #9
	bl __modsi3
	cmp r0, #0
	beq _080226F0
	b _0802280E
_080226F0:
	ldr r2, _0802279C @ =0x00000195
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080227A4
	adds r0, r4, #0
	movs r1, #0x12
	bl __modsi3
	movs r1, #9
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	movs r2, #0x11
	strh r2, [r1]
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #0xce
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xbc
	strh r0, [r1]
	movs r5, #0xcf
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x8c
	strh r0, [r1]
	movs r0, #0x7e
	bl m4aSongNumStart
	mov r6, sl
	ldr r1, [r6]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r2, r1, r3
	mov r4, r8
	adds r0, r1, r4
	add r1, sb
	ldrb r0, [r0]
	ldrb r1, [r1]
	subs r0, r0, r1
	ldrb r5, [r2]
	adds r0, r0, r5
	strb r0, [r2]
	ldr r0, [r6]
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _08022766
	movs r0, #0x63
	strb r0, [r1]
_08022766:
	mov r6, sl
	ldr r2, [r6]
	mov r0, r8
	adds r3, r2, r0
	movs r1, #0
	ldrsb r1, [r3, r1]
	mov r5, sb
	adds r4, r2, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	subs r1, r1, r0
	movs r0, #0x64
	muls r0, r1, r0
	str r0, [r2, #0x3c]
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r0, #1
	movs r6, #0xcb
	lsls r6, r6, #1
	adds r2, r2, r6
	strh r0, [r2]
	ldrb r0, [r3]
	strb r0, [r4]
	b _0802280E
	.align 2, 0
_0802279C: .4byte 0x00000195
_080227A0: .4byte 0x00000193
_080227A4:
	adds r0, r4, #0
	movs r1, #0x12
	bl __modsi3
	movs r1, #9
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	movs r2, #0x11
	strh r2, [r1]
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #0xce
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xbc
	strh r0, [r1]
	movs r5, #0xcf
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x8c
	strh r0, [r1]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #0x7e
	bl m4aSongNumStart
	mov r6, sl
	ldr r1, [r6]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _08022806
	movs r0, #0x63
	strb r0, [r1]
_08022806:
	mov r0, sl
	ldr r1, [r0]
	movs r0, #0x64
	str r0, [r1, #0x3c]
_0802280E:
	movs r2, #0
	ldr r1, _08022848 @ =0x086B481A
	mov r8, r1
	ldr r3, _0802284C @ =gOamBuffer
	mov ip, r3
_08022818:
	mov r5, sl
	ldr r4, [r5]
	lsls r1, r2, #0x10
	asrs r3, r1, #0x10
	lsls r0, r3, #2
	adds r2, r4, r0
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r7, #4]
	movs r5, #0
	ldrsh r0, [r2, r5]
	mov sb, r1
	cmp r0, #0xa0
	ble _08022850
	movs r0, #0
	b _0802286A
	.align 2, 0
_08022848: .4byte 0x086B481A
_0802284C: .4byte gOamBuffer
_08022850:
	lsls r1, r3, #1
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r0, r4, r6
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x11
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
_0802286A:
	mov r3, sb
	asrs r5, r3, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r2, [r3]
	lsls r2, r2, #3
	add r2, ip
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r3]
	lsls r2, r2, #3
	add r2, ip
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _08022968 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldr r0, _0802296C @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	mov r4, sl
	ldr r3, [r4]
	lsls r1, r5, #1
	subs r6, #0x67
	adds r0, r3, r6
	adds r1, r0, r1
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _080228FA
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080228FA
	lsls r0, r5, #2
	adds r2, r3, r0
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x46
	strh r0, [r1]
	adds r6, #6
	adds r1, r2, r6
	movs r0, #0xb4
	strh r0, [r1]
_080228FA:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08022818
_08022908:
	mov r0, sl
	ldr r3, [r0]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r2, [r1]
	movs r4, #0xca
	lsls r4, r4, #1
	adds r3, r3, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	subs r1, #1
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r0, #0x13
	cmp r2, r0
	bne _08022958
	ldr r0, _08022970 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x9c
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	strb r0, [r3]
	mov r5, sl
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08022958
	ldr r6, _08022974 @ =0x000006DE
	adds r1, r1, r6
	movs r0, #0xaa
	strh r0, [r1]
_08022958:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022968: .4byte 0x000001FF
_0802296C: .4byte 0xFFFFFE00
_08022970: .4byte gMain
_08022974: .4byte 0x000006DE

	thumb_func_start sub_22978
sub_22978: @ 0x08022978
	push {r4, r5, lr}
	ldr r3, _08022A00 @ =0x020314E0
	ldr r1, [r3]
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r4, #0
	movs r5, #0
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r0, _08022A04 @ =0x000002CA
	adds r2, r1, r0
	movs r0, #0x82
	lsls r0, r0, #4
	strh r0, [r2]
	ldr r0, _08022A08 @ =0x000002C3
	adds r1, r1, r0
	strb r4, [r1]
	ldr r4, [r3]
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r0, _08022A0C @ =gMain
	ldr r1, _08022A10 @ =0x00003DE8
	adds r0, r0, r1
	movs r2, #1
	movs r1, #1
	strh r1, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, [r3]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xa0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0xe4
	movs r0, #3
	strb r0, [r1]
	ldr r1, _08022A14 @ =0x040000D4
	ldr r0, _08022A18 @ =0x083A808C
	str r0, [r1]
	ldr r0, _08022A1C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08022A20 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08022A24 @ =0x0848FD8C
	str r0, [r1]
	ldr r0, _08022A28 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08022A2C @ =0x80000650
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08022A00: .4byte 0x020314E0
_08022A04: .4byte 0x000002CA
_08022A08: .4byte 0x000002C3
_08022A0C: .4byte gMain
_08022A10: .4byte 0x00003DE8
_08022A14: .4byte 0x040000D4
_08022A18: .4byte 0x083A808C
_08022A1C: .4byte 0x050003C0
_08022A20: .4byte 0x80000010
_08022A24: .4byte 0x0848FD8C
_08022A28: .4byte 0x06015800
_08022A2C: .4byte 0x80000650

	thumb_func_start sub_22A30
sub_22A30: @ 0x08022A30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r7, _08022A68 @ =0x0200EEA8
	ldr r1, _08022A6C @ =0x086ADFE2
	ldr r4, _08022A70 @ =0x020314E0
	ldr r2, [r4]
	ldr r5, _08022A74 @ =0x000002C3
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08022A78
	adds r0, r1, #1
	strh r0, [r2]
	b _08022B2E
	.align 2, 0
_08022A68: .4byte 0x0200EEA8
_08022A6C: .4byte 0x086ADFE2
_08022A70: .4byte 0x020314E0
_08022A74: .4byte 0x000002C3
_08022A78:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r3, _08022C30 @ =0x000002C3
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x29
	bne _08022AAE
	movs r0, #0x28
	strb r0, [r1]
	strh r6, [r7]
	ldr r0, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_08022AAE:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08022AC4
	movs r0, #0xa3
	lsls r0, r0, #1
	bl m4aSongNumStart
_08022AC4:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _08022AD8
	ldr r0, _08022C34 @ =0x00000147
	bl m4aSongNumStart
_08022AD8:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xd
	bne _08022AEE
	movs r0, #0xa4
	lsls r0, r0, #1
	bl m4aSongNumStart
_08022AEE:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x27
	bne _08022B1C
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r6, [r0]
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r6, [r0]
	ldr r1, _08022C38 @ =0x040000D4
	ldr r0, _08022C3C @ =0x084FD18C
	str r0, [r1]
	ldr r0, _08022C40 @ =0x06011CE0
	str r0, [r1, #4]
	ldr r0, _08022C44 @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08022B1C:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bne _08022B2E
	ldr r0, _08022C48 @ =0x001E8480
	str r0, [r1, #0x3c]
_08022B2E:
	ldr r0, _08022C4C @ =0x020314E0
	ldr r1, [r0]
	ldr r5, _08022C30 @ =0x000002C3
	adds r0, r1, r5
	ldrb r0, [r0]
	subs r0, #0xe
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _08022B5A
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #7
	bl __umodsi3
	cmp r0, #0
	bne _08022B5A
	ldr r0, _08022C50 @ =0x00000149
	bl m4aSongNumStart
_08022B5A:
	ldr r0, _08022C4C @ =0x020314E0
	ldr r4, [r0]
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r1, _08022C54 @ =0x000002CA
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r1, _08022C58 @ =0x086ADFE2
	ldr r3, _08022C30 @ =0x000002C3
	adds r4, r4, r3
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldr r5, _08022C5C @ =0x086B28A0
	mov sb, r5
	ldr r6, _08022C60 @ =gOamBuffer
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r5, _08022C64 @ =0xFFFFFE00
	mov r8, r5
_08022BB6:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r0, [r2, #2]
	mov sl, r0
	mov r5, sl
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _08022C68 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	mov r5, sl
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _08022BB6
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022C30: .4byte 0x000002C3
_08022C34: .4byte 0x00000147
_08022C38: .4byte 0x040000D4
_08022C3C: .4byte 0x084FD18C
_08022C40: .4byte 0x06011CE0
_08022C44: .4byte 0x80000100
_08022C48: .4byte 0x001E8480
_08022C4C: .4byte 0x020314E0
_08022C50: .4byte 0x00000149
_08022C54: .4byte 0x000002CA
_08022C58: .4byte 0x086ADFE2
_08022C5C: .4byte 0x086B28A0
_08022C60: .4byte gOamBuffer
_08022C64: .4byte 0xFFFFFE00
_08022C68: .4byte 0x000001FF

	thumb_func_start sub_22C6C
sub_22C6C: @ 0x08022C6C
	push {r4, r5, r6, lr}
	ldr r4, _08022D14 @ =0x020314E0
	ldr r2, [r4]
	ldr r0, _08022D18 @ =0x000002C6
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r5, #0xb2
	lsls r5, r5, #2
	adds r1, r2, r5
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
	ldr r6, _08022D1C @ =0x000002CA
	adds r1, r2, r6
	ldr r0, _08022D20 @ =0x0000FFD8
	strh r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08022D24 @ =0x0000FFDC
	strh r0, [r1]
	ldr r0, _08022D28 @ =0x000002CE
	adds r1, r2, r0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _08022D2C @ =gMain
	ldr r1, _08022D30 @ =0x00000B98
	adds r0, r0, r1
	movs r3, #1
	movs r1, #1
	strh r1, [r0]
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r2, r2, r0
	strb r3, [r2]
	ldr r4, [r4]
	adds r5, r4, r5
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0x14
	bl __divsi3
	ldr r5, _08022D34 @ =0x086AE088
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r6, r4, r6
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0x14
	bl __divsi3
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r4, #0xe4
	movs r0, #2
	strb r0, [r4]
	ldr r1, _08022D38 @ =0x040000D4
	ldr r0, _08022D3C @ =0x083A806C
	str r0, [r1]
	ldr r0, _08022D40 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08022D44 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08022D48 @ =0x083A704C
	str r0, [r1]
	ldr r0, _08022D4C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08022D50 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08022D14: .4byte 0x020314E0
_08022D18: .4byte 0x000002C6
_08022D1C: .4byte 0x000002CA
_08022D20: .4byte 0x0000FFD8
_08022D24: .4byte 0x0000FFDC
_08022D28: .4byte 0x000002CE
_08022D2C: .4byte gMain
_08022D30: .4byte 0x00000B98
_08022D34: .4byte 0x086AE088
_08022D38: .4byte 0x040000D4
_08022D3C: .4byte 0x083A806C
_08022D40: .4byte 0x050003C0
_08022D44: .4byte 0x80000010
_08022D48: .4byte 0x083A704C
_08022D4C: .4byte 0x06015800
_08022D50: .4byte 0x80000800

	thumb_func_start sub_22D54
sub_22D54: @ 0x08022D54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08022E38 @ =0x020314E0
	ldr r5, [r4]
	ldr r0, _08022E3C @ =0x000002C6
	mov sb, r0
	adds r0, r5, r0
	ldrh r6, [r0]
	adds r0, r6, #0
	movs r1, #0x38
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x13
	ldr r1, _08022E40 @ =0x0200BC58
	mov r8, r1
	mov sl, r4
	cmp r6, #0x81
	bls _08022D82
	b _08022EA0
_08022D82:
	adds r0, r6, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08022D96
	movs r0, #0xb8
	bl m4aSongNumStart
_08022D96:
	mov r2, sl
	ldr r1, [r2]
	mov r3, sb
	adds r2, r1, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r5, #0xb2
	lsls r5, r5, #2
	adds r2, r1, r5
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	ldrh r5, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	ldr r0, _08022E44 @ =0x000002CA
	adds r2, r1, r0
	adds r3, #2
	adds r4, r1, r3
	ldrh r0, [r4]
	ldrh r5, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	ldrh r6, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bgt _08022DE2
	ldr r0, _08022E48 @ =0xFFFFF468
	add r0, r8
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	cmp r0, #0
	bne _08022DE6
_08022DE2:
	subs r0, r6, #1
	strh r0, [r4]
_08022DE6:
	ldr r0, _08022E38 @ =0x020314E0
	ldr r6, [r0]
	ldr r2, _08022E3C @ =0x000002C6
	adds r1, r6, r2
	ldrh r1, [r1]
	mov sl, r0
	cmp r1, #0x4d
	bhi _08022E50
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0x14
	bl __divsi3
	ldr r1, _08022E4C @ =0x086AE088
	lsls r5, r7, #0x10
	lsrs r4, r5, #0xe
	adds r4, r4, r1
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r7, #0xfa
	lsls r7, r7, #1
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _08022E44 @ =0x000002CA
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	b _08022E64
	.align 2, 0
_08022E38: .4byte 0x020314E0
_08022E3C: .4byte 0x000002C6
_08022E40: .4byte 0x0200BC58
_08022E44: .4byte 0x000002CA
_08022E48: .4byte 0xFFFFF468
_08022E4C: .4byte 0x086AE088
_08022E50:
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	lsls r5, r7, #0x10
_08022E64:
	mov r3, sl
	ldr r1, [r3]
	ldr r7, _08022E88 @ =0x000002C6
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0x4e
	bne _08022E76
	ldr r0, _08022E8C @ =0x000186A0
	str r0, [r1, #0x3c]
_08022E76:
	ldr r1, _08022E90 @ =0x040000D4
	ldr r0, _08022E94 @ =0x084FD18C
	str r0, [r1]
	ldr r0, _08022E98 @ =0x06011CE0
	str r0, [r1, #4]
	ldr r0, _08022E9C @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08022EBA
	.align 2, 0
_08022E88: .4byte 0x000002C6
_08022E8C: .4byte 0x000186A0
_08022E90: .4byte 0x040000D4
_08022E94: .4byte 0x084FD18C
_08022E98: .4byte 0x06011CE0
_08022E9C: .4byte 0x80000100
_08022EA0:
	movs r2, #0
	mov r0, r8
	strh r2, [r0]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	mov r5, sl
	ldr r0, [r5]
	adds r0, #0xe4
	strb r2, [r0]
	lsls r5, r7, #0x10
_08022EBA:
	mov r7, sl
	ldr r4, [r7]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3, #2]
	ldr r7, _08022F90 @ =0x000002CA
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r2, #0
	ldr r3, _08022F94 @ =gOamBuffer
	mov ip, r3
	ldr r7, _08022F98 @ =0x086B4850
	mov sl, r7
	asrs r1, r5, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r6, r0, #1
	ldr r0, _08022F9C @ =0xFFFFFE00
	mov sb, r0
_08022F08:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, r8
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	add r1, sl
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	mov r7, r8
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r7, _08022FA0 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ldrh r5, [r2, #2]
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r7, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #4
	ble _08022F08
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022F90: .4byte 0x000002CA
_08022F94: .4byte gOamBuffer
_08022F98: .4byte 0x086B4850
_08022F9C: .4byte 0xFFFFFE00
_08022FA0: .4byte 0x000001FF

	thumb_func_start sub_22FA4
sub_22FA4: @ 0x08022FA4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _0802301C @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _08023020 @ =0x0000020E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #9
	bl sub_1C7F4
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, _08023024 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r0, #1
	strh r0, [r1]
	movs r2, #0
	mov r8, r4
	ldr r7, _08023028 @ =0x086A3707
	mov ip, r7
	ldr r4, _0802302C @ =0x040000D4
	ldr r0, _08023030 @ =0x06015800
	mov sb, r0
	ldr r6, _08023034 @ =0x80000020
_08022FE0:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	mov r1, r8
	ldr r5, [r1]
	movs r7, #0xb3
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _0802303C
	ldr r0, _08023038 @ =0x083FFD4C
	str r0, [r4]
	lsls r0, r3, #6
	add r0, sb
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08023020 @ =0x0000020E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	b _08023052
	.align 2, 0
_0802301C: .4byte 0x020314E0
_08023020: .4byte 0x0000020E
_08023024: .4byte gMain
_08023028: .4byte 0x086A3707
_0802302C: .4byte 0x040000D4
_08023030: .4byte 0x06015800
_08023034: .4byte 0x80000020
_08023038: .4byte 0x083FFD4C
_0802303C:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _0802306C @ =0x083FF04C
	adds r0, r0, r1
	str r0, [r4]
	lsls r0, r3, #6
	add r0, sb
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
_08023052:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08022FE0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802306C: .4byte 0x083FF04C

	thumb_func_start sub_23070
sub_23070: @ 0x08023070
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080230F4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r6, [r0, #0x10]
	movs r0, #0
	ldr r1, _080230F8 @ =0x020314E0
	mov r8, r1
	ldr r7, _080230FC @ =gOamBuffer
	ldr r2, _08023100 @ =0xFFFFFE00
	mov ip, r2
_08023088:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	mov r3, r8
	ldr r1, [r3]
	ldr r2, _08023104 @ =0x0000020E
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, #0x98
	movs r3, #0xdb
	lsls r3, r3, #1
	adds r2, r1, r3
	adds r0, r4, r0
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	movs r0, #0x60
	strh r0, [r6, #4]
	adds r4, #8
	adds r4, r6, r4
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08023108 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #9
	ble _08023088
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080230F4: .4byte gMain
_080230F8: .4byte 0x020314E0
_080230FC: .4byte gOamBuffer
_08023100: .4byte 0xFFFFFE00
_08023104: .4byte 0x0000020E
_08023108: .4byte 0x000001FF

	thumb_func_start sub_2310C
sub_2310C: @ 0x0802310C
	ldr r0, _08023124 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08023128 @ =0x020314E0
	ldr r0, [r0]
	adds r0, #0xe4
	strb r2, [r0]
	bx lr
	.align 2, 0
_08023124: .4byte gMain
_08023128: .4byte 0x020314E0

	thumb_func_start sub_2312C
sub_2312C: @ 0x0802312C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080231B8 @ =0x020314E0
	ldr r0, [r4]
	ldr r2, _080231BC @ =0x0000020E
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0
	strh r3, [r1]
	ldr r7, _080231C0 @ =0x000006DB
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r3, [r0]
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, _080231C4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r0, #1
	strh r0, [r1]
	movs r5, #0
	mov r8, r4
	ldr r2, _080231C8 @ =0x086A3707
	mov ip, r2
	ldr r3, _080231CC @ =0x040000D4
	ldr r7, _080231D0 @ =0x06015800
	mov sb, r7
	ldr r6, _080231D4 @ =0x80000020
_0802317C:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	mov r0, r8
	ldr r4, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r2, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _080231DC
	ldr r0, _080231D8 @ =0x083FFD4C
	str r0, [r3]
	lsls r0, r2, #6
	add r0, sb
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	ldr r0, _080231BC @ =0x0000020E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	b _080231F2
	.align 2, 0
_080231B8: .4byte 0x020314E0
_080231BC: .4byte 0x0000020E
_080231C0: .4byte 0x000006DB
_080231C4: .4byte gMain
_080231C8: .4byte 0x086A3707
_080231CC: .4byte 0x040000D4
_080231D0: .4byte 0x06015800
_080231D4: .4byte 0x80000020
_080231D8: .4byte 0x083FFD4C
_080231DC:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _08023230 @ =0x083FF04C
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #6
	add r0, sb
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
_080231F2:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0802317C
	ldr r0, _08023234 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x14]
	movs r0, #1
	strh r0, [r1]
	movs r5, #0
	ldr r2, _08023238 @ =0x086ACFE0
	mov r8, r2
	ldr r3, _0802323C @ =0x040000D4
	ldr r6, _08023240 @ =0x06015800
	ldr r4, _08023244 @ =0x80000020
_08023218:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #1
	mov r7, r8
	adds r1, r0, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0x20
	bne _0802324C
	ldr r0, _08023248 @ =0x083FFD4C
	b _08023258
	.align 2, 0
_08023230: .4byte 0x083FF04C
_08023234: .4byte gMain
_08023238: .4byte 0x086ACFE0
_0802323C: .4byte 0x040000D4
_08023240: .4byte 0x06015800
_08023244: .4byte 0x80000020
_08023248: .4byte 0x083FFD4C
_0802324C:
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _080232EC @ =0x083FF04C
	adds r0, r0, r1
_08023258:
	str r0, [r3]
	adds r0, r2, #0
	adds r0, #0xa
	lsls r0, r0, #6
	adds r0, r0, r6
	str r0, [r3, #4]
	str r4, [r3, #8]
	ldr r0, [r3, #8]
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08023218
	movs r5, #0
	ldr r2, _080232F0 @ =0x020314E0
	mov ip, r2
	ldr r7, _080232F4 @ =0x00000212
	movs r6, #0
	movs r4, #0x8a
	lsls r4, r4, #2
_08023286:
	mov r0, ip
	ldr r2, [r0]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #1
	adds r0, r2, r7
	adds r0, r0, r3
	strh r3, [r0]
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r2, r2, r4
	strh r6, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023286
	movs r5, #0
	ldr r1, _080232F0 @ =0x020314E0
	mov ip, r1
	movs r7, #0
	ldr r6, _080232F8 @ =0x000013D4
	ldr r4, _080232FC @ =0x000013E8
_080232B6:
	mov r2, ip
	ldr r3, [r2]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r2, r3, r6
	adds r2, r2, r0
	adds r0, r1, #0
	adds r0, #0xa
	lsls r0, r0, #1
	strh r0, [r2]
	lsls r0, r1, #2
	adds r3, r3, r0
	adds r3, r3, r4
	strh r7, [r3]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _080232B6
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080232EC: .4byte 0x083FF04C
_080232F0: .4byte 0x020314E0
_080232F4: .4byte 0x00000212
_080232F8: .4byte 0x000013D4
_080232FC: .4byte 0x000013E8

	thumb_func_start sub_23300
sub_23300: @ 0x08023300
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080233E4 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _080233E8 @ =0x000006C4
	adds r1, r1, r2
	movs r4, #0
	strb r4, [r1]
	ldr r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	adds r3, r2, #0
	mov r8, r0
	cmp r3, #0
	bne _080233FC
	adds r0, r2, #1
	strh r0, [r1]
	ldr r1, _080233EC @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	strh r4, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _080233F0 @ =gOamBuffer
	ldr r4, _080233F4 @ =0xFFFFFE00
	mov r8, r4
_08023342:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080233F8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _08023342
	ldr r3, _080233EC @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x14]
	movs r0, #0
	strh r0, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _080233F0 @ =gOamBuffer
	ldr r4, _080233F4 @ =0xFFFFFE00
	mov r8, r4
_0802339C:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080233F8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _0802339C
	b _08023934
	.align 2, 0
_080233E4: .4byte 0x020314E0
_080233E8: .4byte 0x000006C4
_080233EC: .4byte gMain
_080233F0: .4byte gOamBuffer
_080233F4: .4byte 0xFFFFFE00
_080233F8: .4byte 0x000001FF
_080233FC:
	cmp r3, #0xc2
	bls _08023402
	b _0802385C
_08023402:
	adds r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x9b
	bls _08023410
	b _08023688
_08023410:
	ldr r1, _0802343C @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	movs r5, #0
	ldr r3, _08023440 @ =gOamBuffer
	mov sb, r3
	ldr r4, _08023444 @ =0x00000637
	mov sl, r4
_08023420:
	mov r0, r8
	ldr r3, [r0]
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #1
	ldr r4, _08023448 @ =0x00000212
	adds r0, r3, r4
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802344C
	subs r0, #1
	strh r0, [r1]
	b _0802347C
	.align 2, 0
_0802343C: .4byte gMain
_08023440: .4byte gOamBuffer
_08023444: .4byte 0x00000637
_08023448: .4byte 0x00000212
_0802344C:
	lsls r0, r2, #2
	adds r0, r3, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r6, #0xc8
	lsls r6, r6, #3
	subs r1, r6, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, sl
	ble _0802347C
	strh r6, [r4]
_0802347C:
	lsls r6, r5, #0x10
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r0, #0xa0
	ldr r3, _08023530 @ =0x0000020E
	adds r1, r5, r3
	subs r4, r4, r0
	ldrh r1, [r1]
	adds r4, r4, r1
	strh r4, [r7, #2]
	ldr r4, _08023534 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x24
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023538 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _0802353C @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023420
	ldr r5, _08023540 @ =gMain
	ldr r0, [r5, #0x44]
	ldr r7, [r0, #0x14]
	movs r5, #0
	ldr r0, _08023544 @ =0x00000637
	mov sl, r0
	ldr r1, _08023548 @ =gOamBuffer
	mov sb, r1
_08023512:
	mov r2, r8
	ldr r4, [r2]
	lsls r2, r5, #0x10
	asrs r3, r2, #0x10
	lsls r1, r3, #1
	ldr r5, _0802354C @ =0x000013D4
	adds r0, r4, r5
	adds r1, r0, r1
	ldrh r0, [r1]
	adds r6, r2, #0
	cmp r0, #0
	beq _08023550
	subs r0, #1
	strh r0, [r1]
	b _0802357E
	.align 2, 0
_08023530: .4byte 0x0000020E
_08023534: .4byte 0x000006E6
_08023538: .4byte 0x000001FF
_0802353C: .4byte 0xFFFFFE00
_08023540: .4byte gMain
_08023544: .4byte 0x00000637
_08023548: .4byte gOamBuffer
_0802354C: .4byte 0x000013D4
_08023550:
	lsls r0, r3, #2
	adds r0, r4, r0
	ldr r1, _0802366C @ =0x000013E8
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r5, #0xc8
	lsls r5, r5, #3
	subs r1, r5, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, sl
	ble _0802357E
	strh r5, [r4]
_0802357E:
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	ldr r1, _0802366C @ =0x000013E8
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r0, #0xa0
	subs r4, r4, r0
	strh r4, [r7, #2]
	ldr r4, _08023670 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x34
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023674 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _08023678 @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023512
	mov r5, r8
	ldr r0, [r5]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x9b
	beq _0802360A
	b _08023934
_0802360A:
	movs r0, #0
	ldr r7, _0802367C @ =0x00000212
	movs r6, #0
	movs r4, #0x8a
	lsls r4, r4, #2
_08023614:
	ldr r2, [r5]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #1
	adds r0, r2, r7
	adds r0, r0, r3
	strh r3, [r0]
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r2, r2, r4
	strh r6, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023614
	movs r0, #0
	ldr r7, _08023680 @ =0x020314E0
	movs r6, #0
	ldr r5, _08023684 @ =0x000013D4
	ldr r4, _0802366C @ =0x000013E8
_08023640:
	ldr r3, [r7]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r2, r3, r5
	adds r2, r2, r0
	adds r0, r1, #0
	adds r0, #0xa
	lsls r0, r0, #1
	strh r0, [r2]
	lsls r0, r1, #2
	adds r3, r3, r0
	adds r3, r3, r4
	strh r6, [r3]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023640
	b _08023934
	.align 2, 0
_0802366C: .4byte 0x000013E8
_08023670: .4byte 0x000006E6
_08023674: .4byte 0x000001FF
_08023678: .4byte 0xFFFFFE00
_0802367C: .4byte 0x00000212
_08023680: .4byte 0x020314E0
_08023684: .4byte 0x000013D4
_08023688:
	ldr r1, _080236B0 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	movs r5, #0
	ldr r2, _080236B4 @ =gOamBuffer
	mov sb, r2
_08023694:
	mov r3, r8
	ldr r2, [r3]
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	ldr r3, _080236B8 @ =0x00000212
	adds r0, r2, r3
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _080236BC
	subs r0, #1
	strh r0, [r1]
	b _080236E2
	.align 2, 0
_080236B0: .4byte gMain
_080236B4: .4byte gOamBuffer
_080236B8: .4byte 0x00000212
_080236BC:
	lsls r4, r4, #2
	adds r4, r2, r4
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xfa
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_080236E2:
	lsls r6, r5, #0x10
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	ldr r3, _08023790 @ =0x0000020E
	adds r1, r5, r3
	subs r4, r4, r0
	ldrh r1, [r1]
	adds r4, r4, r1
	strh r4, [r7, #2]
	ldr r4, _08023794 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x24
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023798 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _0802379C @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023694
	ldr r5, _080237A0 @ =gMain
	ldr r0, [r5, #0x44]
	ldr r7, [r0, #0x14]
	movs r5, #0
	ldr r0, _080237A4 @ =gOamBuffer
	mov sb, r0
_08023772:
	mov r1, r8
	ldr r3, [r1]
	lsls r2, r5, #0x10
	asrs r4, r2, #0x10
	lsls r1, r4, #1
	ldr r5, _080237A8 @ =0x000013D4
	adds r0, r3, r5
	adds r1, r0, r1
	ldrh r0, [r1]
	adds r6, r2, #0
	cmp r0, #0
	beq _080237AC
	subs r0, #1
	strh r0, [r1]
	b _080237D0
	.align 2, 0
_08023790: .4byte 0x0000020E
_08023794: .4byte 0x000006E6
_08023798: .4byte 0x000001FF
_0802379C: .4byte 0xFFFFFE00
_080237A0: .4byte gMain
_080237A4: .4byte gOamBuffer
_080237A8: .4byte 0x000013D4
_080237AC:
	lsls r4, r4, #2
	adds r4, r3, r4
	ldr r0, _0802384C @ =0x000013E8
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xfa
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_080237D0:
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	ldr r1, _0802384C @ =0x000013E8
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r4, r4, r0
	strh r4, [r7, #2]
	ldr r4, _08023850 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x34
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023854 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _08023858 @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023772
	b _08023934
	.align 2, 0
_0802384C: .4byte 0x000013E8
_08023850: .4byte 0x000006E6
_08023854: .4byte 0x000001FF
_08023858: .4byte 0xFFFFFE00
_0802385C:
	ldr r0, _08023944 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r7, [r1, #0x10]
	ldrh r1, [r7]
	cmp r1, #0
	beq _080238BA
	strh r4, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _08023948 @ =gOamBuffer
	ldr r0, _0802394C @ =0xFFFFFE00
	mov sb, r0
_08023876:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08023950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _08023876
_080238BA:
	ldr r3, _08023944 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x14]
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802391A
	movs r0, #0
	strh r0, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _08023948 @ =gOamBuffer
	ldr r4, _0802394C @ =0xFFFFFE00
	mov sb, r4
_080238D6:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08023950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _080238D6
_0802391A:
	ldr r3, _08023944 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x10]
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x14]
	strh r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r0, #0xe4
	strb r2, [r0]
_08023934:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023944: .4byte gMain
_08023948: .4byte gOamBuffer
_0802394C: .4byte 0xFFFFFE00
_08023950: .4byte 0x000001FF

	thumb_func_start sub_23954
sub_23954: @ 0x08023954
	push {r4, lr}
	ldr r2, _08023998 @ =0x020314E0
	ldr r0, [r2]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xf7
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r2]
	ldr r1, _0802399C @ =0x000001ED
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r4, #2
	adds r1, r0, r4
	movs r4, #0
	strh r3, [r1]
	ldr r1, _080239A0 @ =0x000002DA
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r2]
	subs r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023998: .4byte 0x020314E0
_0802399C: .4byte 0x000001ED
_080239A0: .4byte 0x000002DA

	thumb_func_start sub_239A4
sub_239A4: @ 0x080239A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r6, #0
	ldr r1, _080239DC @ =0x0200D638
	mov sb, r1
	mov ip, r6
	ldr r1, _080239E0 @ =0x020314E0
	ldr r0, [r1]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bhi _08023A22
	lsls r0, r0, #2
	ldr r1, _080239E4 @ =_080239E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080239DC: .4byte 0x0200D638
_080239E0: .4byte 0x020314E0
_080239E4: .4byte _080239E8
_080239E8: @ jump table
	.4byte _08023A22 @ case 0
	.4byte _08023A22 @ case 1
	.4byte _08023A00 @ case 2
	.4byte _08023A06 @ case 3
	.4byte _08023A10 @ case 4
	.4byte _08023A1A @ case 5
_08023A00:
	movs r3, #4
	mov r8, r3
	b _08023A0A
_08023A06:
	movs r4, #8
	mov r8, r4
_08023A0A:
	movs r7, #4
	movs r6, #3
	b _08023A22
_08023A10:
	movs r6, #0xc
	mov r8, r6
	movs r7, #0xc
	movs r6, #5
	b _08023A22
_08023A1A:
	movs r0, #0x21
	mov r8, r0
	movs r7, #0
	movs r6, #0
_08023A22:
	ldr r1, _08023AD4 @ =0x020314E0
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r5, _08023AD8 @ =0x000001ED
	adds r2, r0, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	beq _08023A9A
	ldr r3, _08023ADC @ =0x086AD2EE
	lsls r0, r0, #3
	adds r1, r3, #4
	adds r0, r0, r1
	ldr r2, _08023AE0 @ =0x040000D4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023AE4 @ =0x084FB68C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023AE8 @ =0x060122A0
	str r0, [r2, #4]
	ldr r0, _08023AEC @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _08023AD4 @ =0x020314E0
	ldr r0, [r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r3, #6
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #9
	ldr r1, _08023AF0 @ =0x084FD18C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023AF4 @ =0x06011CE0
	str r0, [r2, #4]
	ldr r0, _08023AF8 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r4, _08023AD4 @ =0x020314E0
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r1, r1, r2
	strb r0, [r1]
_08023A9A:
	ldr r3, _08023AD4 @ =0x020314E0
	ldr r2, [r3]
	movs r4, #0xf6
	lsls r4, r4, #1
	mov sl, r4
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08023AB2
	b _08023C06
_08023AB2:
	ldr r0, _08023ADC @ =0x086AD2EE
	adds r3, r2, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #3
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrh r2, [r4]
	ldrh r0, [r1]
	cmp r0, r2
	bls _08023AFC
	adds r0, r2, #1
	strh r0, [r4]
	b _08023BEE
	.align 2, 0
_08023AD4: .4byte 0x020314E0
_08023AD8: .4byte 0x000001ED
_08023ADC: .4byte 0x086AD2EE
_08023AE0: .4byte 0x040000D4
_08023AE4: .4byte 0x084FB68C
_08023AE8: .4byte 0x060122A0
_08023AEC: .4byte 0x80000240
_08023AF0: .4byte 0x084FD18C
_08023AF4: .4byte 0x06011CE0
_08023AF8: .4byte 0x80000100
_08023AFC:
	ldrb r0, [r3]
	adds r0, #1
	movs r2, #0
	strb r0, [r3]
	ldr r3, _08023C94 @ =0x020314E0
	ldr r1, [r3]
	movs r4, #0xf8
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r8
	blt _08023B22
	strb r7, [r1]
	ldr r0, [r3]
	add r0, sl
	strb r6, [r0]
_08023B22:
	ldr r6, _08023C94 @ =0x020314E0
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x12
	bne _08023B36
	bl sub_32484
_08023B36:
	ldr r1, _08023C94 @ =0x020314E0
	ldr r0, [r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x13
	bne _08023B66
	bl sub_325E0
	ldr r0, _08023C98 @ =gMain
	ldrb r0, [r0, #2]
	cmp r0, #3
	beq _08023B66
	ldr r2, _08023C94 @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #1
	bl sub_52BB0
_08023B66:
	ldr r5, _08023C94 @ =0x020314E0
	ldr r0, [r5]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _08023B7C
	bl sub_28BFC
_08023B7C:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	beq _08023B8E
	cmp r0, #0x1b
	bne _08023B9E
_08023B8E:
	movs r6, #0xf8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08023B9E
	bl m4aMPlayAllStop
_08023B9E:
	ldr r0, _08023C94 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08023C9C @ =0x000001ED
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _08023BC2
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08023BC2
	movs r0, #0x16
	bl m4aSongNumStart
_08023BC2:
	ldr r5, _08023C94 @ =0x020314E0
	ldr r0, [r5]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1d
	bne _08023BDA
	movs r0, #5
	bl sub_19B64
_08023BDA:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1c
	bne _08023BEE
	movs r0, #0x92
	bl m4aSongNumStart
_08023BEE:
	ldr r2, _08023CA0 @ =0x086AD2EE
	ldr r1, _08023C94 @ =0x020314E0
	ldr r0, [r1]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	mov ip, r0
_08023C06:
	ldr r6, _08023C94 @ =0x020314E0
	ldr r3, [r6]
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x58
	subs r0, r0, r1
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r2, r3, r1
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	movs r6, #0xf5
	lsls r6, r6, #1
	adds r4, r3, r6
	strh r0, [r4]
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r2, sb
	strh r0, [r2, #2]
	adds r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08023CC4
	subs r1, #7
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	bne _08023CA4
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	cmp r0, #0xd0
	bls _08023CA4
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	cmp r0, #0
	bge _08023C74
	adds r0, #0xf
_08023C74:
	asrs r0, r0, #4
	ldr r1, _08023C98 @ =gMain
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, [r1, #0x4c]
	ands r1, r0
	cmp r1, #0
	beq _08023CC4
	movs r6, #0xfb
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrh r0, [r0]
	ldrh r4, [r4]
	adds r0, r0, r4
	b _08023CBA
	.align 2, 0
_08023C94: .4byte 0x020314E0
_08023C98: .4byte gMain
_08023C9C: .4byte 0x000001ED
_08023CA0: .4byte 0x086AD2EE
_08023CA4:
	ldr r3, _08023CC0 @ =0x020314E0
	ldr r0, [r3]
	movs r4, #0xf5
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r6, #0xfb
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
_08023CBA:
	mov r1, sb
	strh r0, [r1, #4]
	b _08023CCA
	.align 2, 0
_08023CC0: .4byte 0x020314E0
_08023CC4:
	movs r0, #0xc8
	mov r2, sb
	strh r0, [r2, #4]
_08023CCA:
	movs r2, #0
	mov r3, ip
	lsls r1, r3, #0x10
	ldr r7, _08023DFC @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
_08023CDC:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	mov r4, sb
	adds r5, r4, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r6, _08023E00 @ =0x086B4D4E
	adds r0, r0, r6
	add r0, sl
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	movs r0, #1
	lsls r0, r0, #2
	str r0, [sp]
	ldrb r2, [r1, #5]
	movs r4, #0xd
	rsbs r4, r4, #0
	mov r8, r4
	mov r0, r8
	ands r0, r2
	ldr r6, [sp]
	orrs r0, r6
	strb r0, [r1, #5]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov ip, r1
	mov r1, sb
	movs r6, #2
	ldrsh r0, [r1, r6]
	mov r6, ip
	adds r1, r6, r0
	ldr r6, _08023E04 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldr r0, _08023E08 @ =0xFFFFFE00
	mov ip, r0
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08023CDC
	ldr r6, _08023E0C @ =0x0200D918
	mov sb, r6
	ldr r1, _08023E10 @ =0x020314E0
	ldr r0, [r1]
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldr r0, [r1]
	movs r3, #0xf5
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r6, #4]
	movs r2, #0
	ldr r7, _08023DFC @ =gOamBuffer
	mov sl, r8
	mov r8, ip
_08023D92:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	ldr r6, _08023E14 @ =0x0200D920
	adds r5, r0, r6
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, sl
	ands r0, r2
	ldr r2, [sp]
	orrs r0, r2
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r6, #2
	ldrsh r1, [r5, r6]
	mov r2, sb
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r2, _08023E04 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r3, sb
	ldrb r0, [r3, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08023D92
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023DFC: .4byte gOamBuffer
_08023E00: .4byte 0x086B4D4E
_08023E04: .4byte 0x000001FF
_08023E08: .4byte 0xFFFFFE00
_08023E0C: .4byte 0x0200D918
_08023E10: .4byte 0x020314E0
_08023E14: .4byte 0x0200D920

	thumb_func_start sub_23E18
sub_23E18: @ 0x08023E18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #1
	str r0, [sp]
	ldr r1, _08023F00 @ =0x0200D860
	mov sl, r1
	ldr r5, _08023F04 @ =0xFFFFD860
	add r5, sl
	ldr r0, [r5, #0x4c]
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r7, _08023F08 @ =0x020314E0
	ldr r0, [r7]
	ldr r2, _08023F0C @ =0x00000746
	mov sb, r2
	add r0, sb
	movs r3, #0
	mov r8, r3
	mov r6, r8
	strb r6, [r0]
	ldr r0, [r7]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0]
	ldr r6, [r7]
	ldr r3, _08023F10 @ =0x000002DA
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08023F30
	ldr r5, _08023F14 @ =0x086AE0B4
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r5
	ldrh r1, [r0]
	ldr r2, _08023F0C @ =0x00000746
	adds r0, r6, r2
	strb r1, [r0]
	ldr r5, [r7]
	ldr r2, _08023F18 @ =0x086AE0A4
	ldr r3, _08023F10 @ =0x000002DA
	adds r1, r5, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r6, #0xb5
	lsls r6, r6, #2
	adds r3, r5, r6
	strh r0, [r3]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	ldr r7, _08023F1C @ =0x000002D6
	adds r2, r5, r7
	strh r0, [r2]
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sl
	strh r0, [r2, #4]
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08023EDE
	b _08024226
_08023EDE:
	ldr r2, _08023F20 @ =0x040000D4
	mov r3, sb
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023F24 @ =0x08449D8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023F28 @ =0x06013300
	str r0, [r2, #4]
	ldr r0, _08023F2C @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08024226
	.align 2, 0
_08023F00: .4byte 0x0200D860
_08023F04: .4byte 0xFFFFD860
_08023F08: .4byte 0x020314E0
_08023F0C: .4byte 0x00000746
_08023F10: .4byte 0x000002DA
_08023F14: .4byte 0x086AE0B4
_08023F18: .4byte 0x086AE0A4
_08023F1C: .4byte 0x000002D6
_08023F20: .4byte 0x040000D4
_08023F24: .4byte 0x08449D8C
_08023F28: .4byte 0x06013300
_08023F2C: .4byte 0x80000140
_08023F30:
	cmp r0, #3
	beq _08023F36
	b _080241D4
_08023F36:
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08024004
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r4, r6, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #1
	bne _08023FCA
	movs r3, #2
	strb r3, [r4]
	ldr r0, [r7]
	add r0, sb
	mov r6, sp
	ldrb r6, [r6]
	strb r6, [r0]
	ldr r2, _08023FEC @ =0x040000D4
	ldr r4, [r7]
	mov r1, sb
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023FF0 @ =0x08449D8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023FF4 @ =0x06013300
	str r0, [r2, #4]
	ldr r0, _08023FF8 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r5, #0xf]
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	mov r6, r8
	strh r6, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0x3c
	strh r0, [r1]
	subs r1, #4
	movs r0, #0x48
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe6
	strh r6, [r0]
	adds r0, #8
	strh r3, [r0]
	adds r0, #4
	strb r2, [r0]
	ldr r0, [r7]
	adds r0, #0xfa
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r0, [r7]
	ldr r2, _08023FFC @ =0x000002DE
	adds r0, r0, r2
	movs r1, #0x30
	strh r1, [r0]
_08023FCA:
	ldr r0, [r7]
	ldr r3, _08024000 @ =0x000002D9
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08023FDA
	b _080240FA
_08023FDA:
	mov r6, r8
	strb r6, [r1]
	ldr r0, [r7]
	ldr r7, _08023FFC @ =0x000002DE
	adds r0, r0, r7
	movs r1, #0x30
	strh r1, [r0]
	b _080240FA
	.align 2, 0
_08023FEC: .4byte 0x040000D4
_08023FF0: .4byte 0x08449D8C
_08023FF4: .4byte 0x06013300
_08023FF8: .4byte 0x80000140
_08023FFC: .4byte 0x000002DE
_08024000: .4byte 0x000002D9
_08024004:
	ldr r0, _0802407C @ =0x000002DE
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _080240A8
	movs r5, #0xb8
	lsls r5, r5, #2
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _0802406A
	mov r1, r8
	strb r1, [r6, #0x1f]
	ldr r1, [r7]
	movs r4, #0
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	ldr r2, _08024080 @ =0x0000132C
	adds r1, r1, r2
	ldr r2, [r1]
	movs r0, #0x14
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	movs r0, #0xc8
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	movs r0, #0x58
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0xa3
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	mov r3, r8
	strh r3, [r0, #6]
	ldr r2, [r1]
	movs r6, #0x10
	ldrsh r0, [r2, r6]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	movs r0, #0xb9
	bl m4aSongNumStart
	ldr r0, [r7]
	ldr r3, _08024084 @ =0x000005FA
	adds r0, r0, r3
	strb r4, [r0]
_0802406A:
	ldr r0, [r7]
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _08024088
	subs r0, #1
	strh r0, [r1]
	b _080240FA
	.align 2, 0
_0802407C: .4byte 0x000002DE
_08024080: .4byte 0x0000132C
_08024084: .4byte 0x000005FA
_08024088:
	bl sub_23954
	ldr r0, [r7]
	ldr r6, _080240A4 @ =0x000002DA
	adds r0, r0, r6
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r7]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r0, r2
	strb r1, [r0]
	b _080240FA
	.align 2, 0
_080240A4: .4byte 0x000002DA
_080240A8:
	ldr r3, _08024184 @ =0x0000132C
	adds r4, r6, r3
	ldr r1, [r4]
	movs r0, #0x58
	strh r0, [r1, #0x10]
	ldr r5, [r4]
	ldrh r0, [r2]
	movs r1, #3
	bl __udivsi3
	movs r1, #0xa3
	subs r1, r1, r0
	strh r1, [r5, #0x12]
	ldr r0, [r4]
	mov r7, r8
	strh r7, [r0, #6]
	ldr r1, [r4]
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r1, [r4]
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r3, _08024188 @ =0x000005FA
	adds r0, r6, r3
	mov r6, sp
	ldrb r6, [r6]
	strb r6, [r0]
_080240FA:
	ldr r6, _0802418C @ =0x020314E0
	ldr r7, [r6]
	ldr r1, _08024190 @ =0x086AE0A4
	ldr r0, _08024194 @ =0x000002DA
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r5, r7, r2
	strh r0, [r5]
	mov r3, r8
	movs r4, #0
	ldrsb r4, [r3, r4]
	lsls r4, r4, #2
	adds r4, r4, r1
	ldr r1, _08024198 @ =0x000002DE
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r1, #3
	bl __udivsi3
	ldrh r1, [r4, #2]
	subs r1, r1, r0
	ldr r3, _0802419C @ =0x000002D6
	adds r2, r7, r3
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r0, [r5]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r7, #0
	adds r1, #0x5a
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sl
	strh r0, [r2, #4]
	movs r0, #0x13
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bgt _080241AE
	mov r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #3
	bne _080241A0
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080241A0
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r0, #1
	b _080241B6
	.align 2, 0
_08024184: .4byte 0x0000132C
_08024188: .4byte 0x000005FA
_0802418C: .4byte 0x020314E0
_08024190: .4byte 0x086AE0A4
_08024194: .4byte 0x000002DA
_08024198: .4byte 0x000002DE
_0802419C: .4byte 0x000002D6
_080241A0:
	ldr r0, [r6]
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	b _080241B8
_080241AE:
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r0, #0
_080241B6:
	strb r0, [r1]
_080241B8:
	ldr r0, [r6]
	ldr r1, _080241D0 @ =0x000002DE
	adds r6, r0, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _08024226
	subs r0, #1
	strh r0, [r6]
	movs r2, #2
	str r2, [sp]
	b _08024226
	.align 2, 0
_080241D0: .4byte 0x000002DE
_080241D4:
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0802420C
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r7]
	adds r0, r0, r3
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r7]
	adds r3, #1
	adds r1, r0, r3
	movs r0, #8
	strb r0, [r1]
	ldr r0, [r7]
	movs r6, #0xf8
	lsls r6, r6, #1
	adds r0, r0, r6
	mov r1, r8
	strh r1, [r0]
_0802420C:
	ldr r0, [r7]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r0, r2
	mov r3, r8
	strh r3, [r1]
	ldr r6, _080242A4 @ =0x000002D6
	adds r0, r0, r6
	strh r3, [r0]
	mov r7, sl
	strh r3, [r7, #2]
	movs r0, #0xa0
	strh r0, [r7, #4]
_08024226:
	movs r0, #0
	ldr r6, _080242A8 @ =gOamBuffer
	ldr r1, [sp]
	lsls r1, r1, #2
	mov ip, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	mov sb, r2
	ldr r3, _080242AC @ =0xFFFFFE00
	mov r8, r3
_0802423A:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	add r4, sl
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sb
	ands r0, r2
	mov r7, ip
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _080242B0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #1
	ble _0802423A
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080242A4: .4byte 0x000002D6
_080242A8: .4byte gOamBuffer
_080242AC: .4byte 0xFFFFFE00
_080242B0: .4byte 0x000001FF

	thumb_func_start sub_242B4
sub_242B4: @ 0x080242B4
	push {r4, r5, lr}
	ldr r0, _080242C8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _080242D0
	ldr r0, _080242CC @ =0x020314E0
	ldr r0, [r0]
	movs r1, #0xb4
	lsls r1, r1, #2
	b _080242D6
	.align 2, 0
_080242C8: .4byte gMain
_080242CC: .4byte 0x020314E0
_080242D0:
	ldr r0, _0802431C @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _08024320 @ =0x00000343
_080242D6:
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r5, _0802431C @ =0x020314E0
	ldr r0, [r5]
	ldr r1, _08024324 @ =0x000005A5
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _08024328 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
	movs r2, #0
	ldr r5, _0802432C @ =0x0000071D
_080242FC:
	ldr r0, _0802431C @ =0x020314E0
	ldr r3, [r0]
	ldr r0, _08024330 @ =0x00000723
	adds r1, r3, r0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, #0
	cmp r2, r1
	bge _08024334
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _0802433A
	.align 2, 0
_0802431C: .4byte 0x020314E0
_08024320: .4byte 0x00000343
_08024324: .4byte 0x000005A5
_08024328: .4byte 0x000006C4
_0802432C: .4byte 0x0000071D
_08024330: .4byte 0x00000723
_08024334:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_0802433A:
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _080242FC
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_24350
sub_24350: @ 0x08024350
	push {r4, r5, lr}
	ldr r4, _0802439C @ =0x020314E0
	ldr r0, [r4]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r1, [r4]
	movs r5, #0
	strh r3, [r1, #0x18]
	ldr r0, _080243A0 @ =0x00000724
	adds r2, r1, r0
	subs r0, #0x1c
	strh r0, [r2]
	ldr r0, _080243A4 @ =0x000005A5
	adds r1, r1, r0
	strb r5, [r1]
	ldr r2, [r4]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	adds r1, #2
	adds r0, r2, r1
	strh r3, [r0]
	ldr r0, _080243A8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _080243B0
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _080243AC @ =0x000002EE
	str r0, [r1]
	subs r0, #0xee
	adds r1, r2, r0
	movs r0, #0x82
	lsls r0, r0, #3
	b _080243C4
	.align 2, 0
_0802439C: .4byte 0x020314E0
_080243A0: .4byte 0x00000724
_080243A4: .4byte 0x000005A5
_080243A8: .4byte gMain
_080243AC: .4byte 0x000002EE
_080243B0:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0xf5
	lsls r0, r0, #3
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	subs r0, #0xd4
_080243C4:
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r4]
	ldr r3, _080243FC @ =0x00000206
	adds r1, r0, r3
	movs r3, #0
	strh r2, [r1]
	movs r4, #0xfc
	lsls r4, r4, #1
	adds r1, r0, r4
	strh r2, [r1]
	adds r4, #2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r4, _08024400 @ =0x000005AA
	adds r1, r0, r4
	strh r2, [r1]
	ldr r1, _08024404 @ =0x000005A9
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080243FC: .4byte 0x00000206
_08024400: .4byte 0x000005AA
_08024404: .4byte 0x000005A9

	thumb_func_start sub_24408
sub_24408: @ 0x08024408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r2, _08024440 @ =gMain
	ldr r0, [r2, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	mov sb, r0
	movs r0, #1
	mov sl, r0
	ldr r1, _08024444 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bls _08024434
	bl _080252F6
_08024434:
	lsls r0, r0, #2
	ldr r1, _08024448 @ =_0802444C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08024440: .4byte gMain
_08024444: .4byte 0x020314E0
_08024448: .4byte _0802444C
_0802444C: @ jump table
	.4byte _08024470 @ case 0
	.4byte _080244A0 @ case 1
	.4byte _08024784 @ case 2
	.4byte _08024AB4 @ case 3
	.4byte _08024EFC @ case 4
	.4byte _080250E4 @ case 5
	.4byte _08025208 @ case 6
	.4byte _08025294 @ case 7
	.4byte _080252B8 @ case 8
_08024470:
	ldr r1, _08024494 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _08024498 @ =0x000006C4
	adds r0, r0, r2
	movs r1, #3
	strb r1, [r0]
	ldr r3, _0802449C @ =gMain
	ldr r0, [r3, #0x44]
	adds r0, #0xa4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	ldr r4, _08024494 @ =0x020314E0
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	bl _080252F4
	.align 2, 0
_08024494: .4byte 0x020314E0
_08024498: .4byte 0x000006C4
_0802449C: .4byte gMain
_080244A0:
	ldr r3, _080244D0 @ =0x086AD52C
	ldr r5, _080244D4 @ =0x020314E0
	ldr r2, [r5]
	movs r6, #0x81
	lsls r6, r6, #2
	adds r4, r2, r6
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r7, _080244D8 @ =0x00000206
	adds r2, r2, r7
	ldrh r1, [r2]
	cmp r0, r1
	ble _080244DC
	adds r0, r1, #1
	strh r0, [r2]
	b _080245FE
	.align 2, 0
_080244D0: .4byte 0x086AD52C
_080244D4: .4byte 0x020314E0
_080244D8: .4byte 0x00000206
_080244DC:
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	ldr r0, _0802459C @ =0x020314E0
	ldr r1, [r0]
	ldr r4, _080245A0 @ =0x00000206
	adds r2, r1, r4
	strh r5, [r2]
	ldr r4, _080245A4 @ =gMain
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080245D4
	adds r1, r1, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xd
	ble _08024520
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0802459C @ =0x020314E0
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1, #0x17]
	ldr r2, _0802459C @ =0x020314E0
	ldr r1, [r2]
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r5, [r0]
	movs r4, #0xfd
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r5, [r0]
_08024520:
	ldr r5, _0802459C @ =0x020314E0
	ldr r1, [r5]
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _0802453E
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802453E
	movs r0, #0x15
	bl m4aSongNumStart
_0802453E:
	ldr r4, _0802459C @ =0x020314E0
	ldr r3, [r4]
	movs r5, #0x81
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bne _08024576
	movs r6, #0xa7
	lsls r6, r6, #2
	adds r1, r3, r6
	movs r0, #0x8c
	strh r0, [r1]
	ldr r2, _080245A8 @ =0x086A3700
	movs r7, #0xb3
	lsls r7, r7, #3
	adds r0, r3, r7
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	bl sub_528DC
_08024576:
	ldr r2, [r4]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _080245B8
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, _080245AC @ =0x0000FFF8
	strh r1, [r0]
	movs r3, #0xfd
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _080245B0 @ =0x0000FFE2
	strh r0, [r1]
	ldr r3, _080245B4 @ =0x086AD52C
	b _080245FE
	.align 2, 0
_0802459C: .4byte 0x020314E0
_080245A0: .4byte 0x00000206
_080245A4: .4byte gMain
_080245A8: .4byte 0x086A3700
_080245AC: .4byte 0x0000FFF8
_080245B0: .4byte 0x0000FFE2
_080245B4: .4byte 0x086AD52C
_080245B8:
	movs r5, #0xfc
	lsls r5, r5, #1
	adds r0, r2, r5
	movs r1, #0
	strh r1, [r0]
	movs r6, #0xfd
	lsls r6, r6, #1
	adds r0, r2, r6
	strh r1, [r0]
	ldr r3, _080245D0 @ =0x086AD52C
	b _080245FE
	.align 2, 0
_080245D0: .4byte 0x086AD52C
_080245D4:
	adds r1, r1, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #9
	ble _080245FE
	strh r5, [r2]
	movs r0, #0xa
	strb r0, [r1]
	ldr r7, _08024754 @ =0x020314E0
	ldr r1, [r7]
	movs r0, #2
	strb r0, [r1, #0x17]
	ldr r1, [r7]
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r5, [r0]
	movs r4, #0xfd
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r5, [r0]
_080245FE:
	ldr r5, _08024754 @ =0x020314E0
	ldr r4, [r5]
	movs r6, #0x81
	lsls r6, r6, #2
	adds r2, r4, r6
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrh r5, [r1]
	adds r1, r3, #4
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0xc
	bne _08024656
	movs r7, #0xfd
	lsls r7, r7, #1
	adds r3, r4, r7
	ldrh r0, [r3]
	adds r0, #2
	strh r0, [r3]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_08024656:
	ldr r7, _08024754 @ =0x020314E0
	ldr r4, [r7]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, sb
	strh r0, [r4, #4]
	ldr r2, _08024758 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0802475C @ =0x0202C7A0
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08024760 @ =0x060112A0
	str r0, [r2, #4]
	ldr r0, _08024764 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _08024768 @ =0x020315D0
	str r0, [r2]
	ldr r0, _0802476C @ =0x050003A0
	str r0, [r2, #4]
	ldr r0, _08024770 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0
	lsls r1, r6, #0x10
	ldr r5, _08024774 @ =0x086B4B0E
	mov r8, r5
	ldr r6, _08024778 @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r0
_080246CC:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	mov r7, sb
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, r8
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	str r1, [sp, #0xc]
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r7, [sp, #0xc]
	adds r1, r7, r0
	ldr r7, _0802477C @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldr r0, _08024780 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r5, sl
	lsls r4, r5, #2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _080246CC
	bl _080252F6
	.align 2, 0
_08024754: .4byte 0x020314E0
_08024758: .4byte 0x040000D4
_0802475C: .4byte 0x0202C7A0
_08024760: .4byte 0x060112A0
_08024764: .4byte 0x80000090
_08024768: .4byte 0x020315D0
_0802476C: .4byte 0x050003A0
_08024770: .4byte 0x80000010
_08024774: .4byte 0x086B4B0E
_08024778: .4byte gOamBuffer
_0802477C: .4byte 0x000001FF
_08024780: .4byte 0xFFFFFE00
_08024784:
	ldr r0, _080247B0 @ =0x020314E0
	mov sl, r0
	ldr r4, [r0]
	ldr r1, _080247B4 @ =0x00000206
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0xef
	bhi _080247BC
	movs r2, #1
	mov sl, r2
	cmp r0, #0
	bne _080247AA
	ldr r3, _080247B8 @ =0x00000346
	adds r1, r4, r3
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xdd
	bl m4aSongNumStart
_080247AA:
	movs r5, #0
	b _0802499E
	.align 2, 0
_080247B0: .4byte 0x020314E0
_080247B4: .4byte 0x00000206
_080247B8: .4byte 0x00000346
_080247BC:
	cmp r0, #0xf0
	bne _080247F4
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, _080247F0 @ =0x000008D4
	str r0, [r1]
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0xb9
	lsls r0, r0, #2
	str r0, [r1]
	movs r7, #0x81
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
	movs r0, #2
	mov sl, r0
	movs r5, #0
	movs r0, #0x15
	bl m4aSongNumStart
	b _0802499E
	.align 2, 0
_080247F0: .4byte 0x000008D4
_080247F4:
	ldr r3, _080248A0 @ =0x086AD750
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r1, r2, r3
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r0, [r0]
	adds r0, #0x78
	ldr r1, [r1]
	subs r6, r1, r0
	adds r3, #4
	adds r2, r2, r3
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0xa0
	ldr r1, [r2]
	subs r7, r1, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r1, r0
	str r1, [sp, #8]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r7, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r4, r0, #0x10
	lsrs r2, r4, #0x10
	mov r8, r2
	mov r3, sl
	ldr r2, [r3]
	adds r5, #0xa
	adds r0, r2, r5
	ldrh r1, [r0]
	ldr r0, _080248A4 @ =0x00000143
	movs r6, #1
	mov sl, r6
	cmp r1, r0
	bhi _0802485C
	movs r7, #2
	mov sl, r7
_0802485C:
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bgt _080248AC
	movs r5, #0
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #1
	ldr r4, _080248A8 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	mov r0, r8
	bl sub_C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	rsbs r0, r0, #0
	b _080248F0
	.align 2, 0
_080248A0: .4byte 0x086AD750
_080248A4: .4byte 0x00000143
_080248A8: .4byte 0x00004E20
_080248AC:
	ldr r0, _08024934 @ =0x086AD788
	lsrs r4, r4, #0x1d
	lsls r4, r4, #1
	adds r4, r4, r0
	ldr r0, _08024938 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x18
	bl __umodsi3
	lsrs r0, r0, #3
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r4, _0802493C @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	mov r0, r8
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
_080248F0:
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp, #4]
	ldr r4, _08024940 @ =0x020314E0
	ldr r2, [r4]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, [r1]
	ldr r6, [sp]
	adds r0, r0, r6
	str r0, [r1]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r1, r2, r7
	ldr r0, [r1]
	ldr r3, [sp, #4]
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _08024944 @ =0x000009C3
	ldr r6, [sp, #8]
	cmp r6, r0
	bgt _08024964
	adds r7, #4
	adds r3, r2, r7
	ldrb r1, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #5
	bgt _08024948
	adds r0, r1, #1
	strb r0, [r3]
	b _08024964
	.align 2, 0
_08024934: .4byte 0x086AD788
_08024938: .4byte gMain
_0802493C: .4byte 0x00004E20
_08024940: .4byte 0x020314E0
_08024944: .4byte 0x000009C3
_08024948:
	movs r2, #0
	movs r1, #3
	strb r1, [r3]
	ldr r0, [r4]
	strb r1, [r0, #0x17]
	ldr r1, [r4]
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r2, [r0]
	movs r4, #0xfd
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
_08024964:
	ldr r0, _0802497C @ =0x020314E0
	ldr r1, [r0]
	ldr r6, _08024980 @ =0x00000206
	adds r0, r1, r6
	ldrh r2, [r0]
	ldr r0, _08024984 @ =0x0000017B
	cmp r2, r0
	bhi _08024988
	adds r1, #0xe6
	ldrh r0, [r1]
	adds r0, #1
	b _0802499C
	.align 2, 0
_0802497C: .4byte 0x020314E0
_08024980: .4byte 0x00000206
_08024984: .4byte 0x0000017B
_08024988:
	ldr r0, _08024A0C @ =0x0000018F
	cmp r2, r0
	bls _0802499E
	adds r1, #0xe6
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0
	ble _0802499E
	subs r0, r2, #1
_0802499C:
	strh r0, [r1]
_0802499E:
	ldr r2, _08024A10 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08024A14 @ =0x0202C7A0
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08024A18 @ =0x060112A0
	str r0, [r2, #4]
	ldr r0, _08024A1C @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _08024A20 @ =0x020314E0
	ldr r4, [r0]
	ldr r0, _08024A24 @ =0x00000206
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, sb
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _08024A28
	movs r0, #0xb4
	strh r0, [r4, #4]
	b _08024A34
	.align 2, 0
_08024A0C: .4byte 0x0000018F
_08024A10: .4byte 0x040000D4
_08024A14: .4byte 0x0202C7A0
_08024A18: .4byte 0x060112A0
_08024A1C: .4byte 0x80000090
_08024A20: .4byte 0x020314E0
_08024A24: .4byte 0x00000206
_08024A28:
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08024A34
	mov r5, sb
	strh r1, [r5, #4]
_08024A34:
	movs r2, #0
	ldr r6, _08024AA8 @ =gOamBuffer
	mov r7, sl
	lsls r7, r7, #2
	mov ip, r7
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sl, r0
	ldr r1, _08024AAC @ =0xFFFFFE00
	mov r8, r1
_08024A48:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	mov r2, sb
	adds r5, r2, r0
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sl
	ands r0, r2
	mov r3, ip
	orrs r0, r3
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r5, r7]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08024AB0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sb
	ldrb r0, [r3, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08024A48
	bl _080252F6
	.align 2, 0
_08024AA8: .4byte gOamBuffer
_08024AAC: .4byte 0xFFFFFE00
_08024AB0: .4byte 0x000001FF
_08024AB4:
	ldr r3, _08024B5C @ =0x086AD580
	ldr r5, _08024B60 @ =0x020314E0
	ldr r4, [r5]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	ldr r5, _08024B64 @ =gMain
	ldrb r1, [r5, #4]
	movs r0, #0xe8
	muls r0, r1, r0
	adds r2, r2, r0
	adds r1, r2, r3
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r0, [r0]
	adds r0, #0x78
	ldr r1, [r1]
	subs r6, r1, r0
	adds r3, #4
	adds r2, r2, r3
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0xa0
	ldr r1, [r2]
	subs r7, r1, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r1, r0
	str r1, [sp, #8]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r7, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	mov sl, r0
	mov r2, sl
	lsrs r2, r2, #0x10
	mov r8, r2
	mov r0, r8
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r4, _08024B68 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	mov r0, r8
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp, #4]
	ldr r3, _08024B60 @ =0x020314E0
	ldr r5, [r3]
	ldr r4, _08024B6C @ =0x000005A9
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _08024B70
	subs r0, #1
	strb r0, [r1]
	movs r5, #0xe
	b _08024BFA
	.align 2, 0
_08024B5C: .4byte 0x086AD580
_08024B60: .4byte 0x020314E0
_08024B64: .4byte gMain
_08024B68: .4byte 0x00004E20
_08024B6C: .4byte 0x000005A9
_08024B70:
	ldr r2, _08024BA8 @ =0x086A3700
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #0x13]
	cmp r0, #0
	beq _08024BB4
	ldr r0, _08024BAC @ =0x086AD788
	mov r2, sl
	lsrs r4, r2, #0x1d
	lsls r4, r4, #1
	adds r4, r4, r0
	ldr r3, _08024BB0 @ =gMain
	ldr r0, [r3, #0x4c]
	movs r1, #0x18
	bl __umodsi3
	lsrs r0, r0, #3
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b _08024BDA
	.align 2, 0
_08024BA8: .4byte 0x086A3700
_08024BAC: .4byte 0x086AD788
_08024BB0: .4byte gMain
_08024BB4:
	ldr r0, _08024C1C @ =0x086AD788
	mov r4, sl
	lsrs r2, r4, #0x1d
	lsls r2, r2, #1
	adds r2, r2, r0
	ldr r5, _08024C20 @ =gMain
	ldr r0, [r5, #0x4c]
	movs r1, #0x1f
	ands r0, r1
	lsrs r4, r0, #3
	ldrh r2, [r2]
	adds r4, r4, r2
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
_08024BDA:
	ldr r0, _08024C24 @ =0x020314E0
	ldr r2, [r0]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	ldr r3, [sp]
	adds r0, r0, r3
	str r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r2, r4
	ldr r0, [r1]
	ldr r2, [sp, #4]
	adds r0, r0, r2
	str r0, [r1]
_08024BFA:
	ldr r0, _08024C28 @ =0x000009C3
	ldr r3, [sp, #8]
	cmp r3, r0
	bgt _08024C40
	ldr r4, _08024C24 @ =0x020314E0
	ldr r0, [r4]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x1b
	bgt _08024C2C
	adds r0, r2, #1
	strb r0, [r1]
	b _08024C40
	.align 2, 0
_08024C1C: .4byte 0x086AD788
_08024C20: .4byte gMain
_08024C24: .4byte 0x020314E0
_08024C28: .4byte 0x000009C3
_08024C2C:
	bl m4aMPlayAllStop
	movs r0, #0xd
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #6
	strb r1, [r0, #0x17]
_08024C40:
	ldr r0, _08024C68 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08024C70
	ldr r0, _08024C6C @ =0x020314E0
	ldr r1, [r0]
	movs r3, #0x81
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r4, #1
	mov sl, r4
	cmp r1, #0x1a
	ble _08024CA0
	movs r0, #2
	mov sl, r0
	b _08024CA0
	.align 2, 0
_08024C68: .4byte gMain
_08024C6C: .4byte 0x020314E0
_08024C70:
	ldr r0, _08024C94 @ =0x020314E0
	ldr r3, [r0]
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0x1b
	ble _08024C9C
	movs r4, #3
	mov sl, r4
	ldr r0, _08024C98 @ =0x00000367
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _08024CA0
	.align 2, 0
_08024C94: .4byte 0x020314E0
_08024C98: .4byte 0x00000367
_08024C9C:
	movs r1, #1
	mov sl, r1
_08024CA0:
	ldr r2, _08024CE8 @ =0x020314E0
	ldr r4, [r2]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r3, sb
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _08024CEC
	movs r0, #0xb4
	strh r0, [r3, #4]
	b _08024CF8
	.align 2, 0
_08024CE8: .4byte 0x020314E0
_08024CEC:
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08024CF8
	mov r4, sb
	strh r1, [r4, #4]
_08024CF8:
	ldr r2, _08024DA0 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08024DA4 @ =0x0202C7A0
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08024DA8 @ =0x060112A0
	str r0, [r2, #4]
	ldr r0, _08024DAC @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0
	ldr r5, _08024DB0 @ =gOamBuffer
	mov r8, r5
	mov r0, sl
	lsls r0, r0, #2
	mov sl, r0
	ldr r1, _08024DB4 @ =0xFFFFFE00
	mov ip, r1
_08024D24:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	mov r2, sb
	adds r5, r2, r0
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	mov r3, sl
	orrs r0, r3
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, r8
	movs r1, #2
	ldrsh r0, [r5, r1]
	str r0, [sp, #0xc]
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	ldr r2, [sp, #0xc]
	adds r1, r2, r0
	ldr r2, _08024DB8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	mov r3, sb
	ldrb r0, [r3, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08024D24
	ldr r4, _08024DBC @ =0x020314E0
	ldr r4, [r4]
	mov r8, r4
	ldr r5, _08024DC0 @ =0x000005AA
	mov sl, r5
	mov r1, r8
	add r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	beq _08024DC4
	subs r0, #1
	strh r0, [r1]
	b _080252F6
	.align 2, 0
_08024DA0: .4byte 0x040000D4
_08024DA4: .4byte 0x0202C7A0
_08024DA8: .4byte 0x060112A0
_08024DAC: .4byte 0x80000090
_08024DB0: .4byte gOamBuffer
_08024DB4: .4byte 0xFFFFFE00
_08024DB8: .4byte 0x000001FF
_08024DBC: .4byte 0x020314E0
_08024DC0: .4byte 0x000005AA
_08024DC4:
	ldr r0, _08024EA0 @ =0x0000132C
	mov sb, r0
	mov r0, r8
	add r0, sb
	ldr r5, [r0]
	movs r1, #0x10
	ldrsh r4, [r5, r1]
	subs r4, #0xc
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	subs r6, r4, r0
	movs r2, #0x12
	ldrsh r4, [r5, r2]
	subs r4, #0xe
	movs r0, #0x80
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	subs r7, r4, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r1, r0
	cmp r1, #0x51
	ble _08024E0A
	b _080252F6
_08024E0A:
	ldr r4, _08024EA4 @ =0x000005A5
	mov r3, r8
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r5, _08024EA8 @ =0x020314E0
	ldr r1, [r5]
	mov r6, sl
	adds r2, r1, r6
	movs r0, #4
	strh r0, [r2]
	ldr r7, _08024EAC @ =0x000005A9
	adds r1, r1, r7
	movs r0, #0x14
	strb r0, [r1]
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	bls _08024E38
	movs r0, #4
	strb r0, [r1, #0x17]
_08024E38:
	movs r0, #0x75
	bl m4aSongNumStart
	ldr r1, _08024EA8 @ =0x020314E0
	ldr r0, [r1]
	add r0, sb
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x32
	ldrsh r1, [r1, r2]
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r3, _08024EA8 @ =0x020314E0
	ldr r0, [r3]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bls _08024EB0
	adds r0, r5, #0
	bl sub_C74
	ldr r4, _08024EA8 @ =0x020314E0
	ldr r1, [r4]
	add r1, sb
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	bl __divsi3
	strh r0, [r4, #0x30]
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	ldr r5, _08024EA8 @ =0x020314E0
	ldr r0, [r5]
	add r0, sb
	ldr r4, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #4
	b _08024EE2
	.align 2, 0
_08024EA0: .4byte 0x0000132C
_08024EA4: .4byte 0x000005A5
_08024EA8: .4byte 0x020314E0
_08024EAC: .4byte 0x000005A9
_08024EB0:
	adds r0, r5, #0
	bl sub_C74
	ldr r6, _08024EF4 @ =0x020314E0
	ldr r1, [r6]
	add r1, sb
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x7d
	bl __divsi3
	strh r0, [r4, #0x30]
	adds r0, r5, #0
	bl sub_C24
	adds r1, r0, #0
	ldr r0, [r6]
	add r0, sb
	ldr r4, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
_08024EE2:
	rsbs r0, r0, #0
	ldr r1, _08024EF8 @ =0x00004E20
	bl __divsi3
	strh r0, [r4, #0x32]
	movs r0, #7
	bl sub_11B0
	b _080252F6
	.align 2, 0
_08024EF4: .4byte 0x020314E0
_08024EF8: .4byte 0x00004E20
_08024EFC:
	ldr r7, _0802508C @ =0x020314E0
	ldr r0, [r7]
	adds r0, #0xe4
	movs r5, #0
	movs r1, #9
	strb r1, [r0]
	ldr r1, _08025090 @ =0x040000D4
	ldr r0, _08025094 @ =0x086ACF80
	str r0, [r1]
	ldr r0, _08025098 @ =0x050003E0
	str r0, [r1, #4]
	ldr r0, _0802509C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080250A0 @ =0x081428D4
	str r0, [r1]
	ldr r0, _080250A4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080250A8 @ =0x80000E00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r7]
	ldr r2, _080250AC @ =0x000005F6
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #9
	ldr r4, _080250B0 @ =0x08138014
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _080250B4 @ =0x060164C0
	str r0, [r1, #4]
	ldr r3, _080250B8 @ =0x80000040
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r7]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r0, #4
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _080250BC @ =0x06016760
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r7]
	subs r2, #0x50
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _080250C0 @ =0x000005A4
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	ldr r4, [r7]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r0, #8
	movs r6, #0xa2
	lsls r6, r6, #2
	adds r1, r4, r6
	strh r0, [r1]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	subs r0, #0x1f
	ldr r2, _080250C4 @ =0x0000028A
	adds r1, r4, r2
	strh r0, [r1]
	movs r2, #0
	ldr r5, _0802508C @ =0x020314E0
	ldr r4, _080250C8 @ =0x000006D3
	movs r3, #0xd
_08024FA8:
	ldr r1, [r5]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08024FA8
	ldr r3, _0802508C @ =0x020314E0
	ldr r1, [r3]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r4, [r3]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r6, sb
	strh r0, [r6, #2]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _0802500A
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802500A:
	ldr r1, _08025090 @ =0x040000D4
	ldr r0, _080250CC @ =0x0202D760
	str r0, [r1]
	ldr r0, _080250D0 @ =0x060112A0
	str r0, [r1, #4]
	ldr r0, _080250D4 @ =0x80000090
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	ldr r6, _080250D8 @ =gOamBuffer
	movs r1, #0xd
	rsbs r1, r1, #0
	mov r8, r1
	ldr r3, _080250DC @ =0xFFFFFE00
	mov sl, r3
_08025028:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	mov r7, sb
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, r8
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _080250E0 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08025028
	ldr r3, _0802508C @ =0x020314E0
	ldr r1, [r3]
	movs r0, #0
	strh r0, [r1, #0x18]
	b _080252F6
	.align 2, 0
_0802508C: .4byte 0x020314E0
_08025090: .4byte 0x040000D4
_08025094: .4byte 0x086ACF80
_08025098: .4byte 0x050003E0
_0802509C: .4byte 0x80000010
_080250A0: .4byte 0x081428D4
_080250A4: .4byte 0x06015800
_080250A8: .4byte 0x80000E00
_080250AC: .4byte 0x000005F6
_080250B0: .4byte 0x08138014
_080250B4: .4byte 0x060164C0
_080250B8: .4byte 0x80000040
_080250BC: .4byte 0x06016760
_080250C0: .4byte 0x000005A4
_080250C4: .4byte 0x0000028A
_080250C8: .4byte 0x000006D3
_080250CC: .4byte 0x0202D760
_080250D0: .4byte 0x060112A0
_080250D4: .4byte 0x80000090
_080250D8: .4byte gOamBuffer
_080250DC: .4byte 0xFFFFFE00
_080250E0: .4byte 0x000001FF
_080250E4:
	ldr r5, _080251E4 @ =0x020314E0
	ldr r4, [r5]
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r7, #0
	mov sl, r7
	cmp r0, #0x10
	bgt _08025100
	movs r0, #2
	mov sl, r0
_08025100:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	bne _0802510A
	b _080252F6
_0802510A:
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r3, sb
	strh r0, [r3, #2]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r4, r5
	ldr r0, [r0]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r6, sb
	strh r0, [r6, #4]
	movs r2, #0
	ldr r6, _080251E8 @ =gOamBuffer
	mov r7, sl
	lsls r7, r7, #2
	mov ip, r7
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sl, r0
	ldr r1, _080251EC @ =0xFFFFFE00
	mov r8, r1
_08025152:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	mov r2, sb
	adds r5, r2, r0
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sl
	ands r0, r2
	mov r3, ip
	orrs r0, r3
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r5, r7]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _080251F0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sb
	ldrb r0, [r3, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08025152
	ldr r1, _080251F4 @ =0x040000D4
	ldr r4, _080251F8 @ =0x0202D760
	str r4, [r1]
	ldr r0, _080251FC @ =0x060112A0
	str r0, [r1, #4]
	ldr r0, _08025200 @ =0x80000090
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r5, _080251E4 @ =0x020314E0
	ldr r0, [r5]
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	beq _080251D4
	b _080252F6
_080251D4:
	ldr r7, _08025204 @ =gMain
	ldr r0, [r7, #0x44]
	adds r0, #0xa4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	b _080252F6
	.align 2, 0
_080251E4: .4byte 0x020314E0
_080251E8: .4byte gOamBuffer
_080251EC: .4byte 0xFFFFFE00
_080251F0: .4byte 0x000001FF
_080251F4: .4byte 0x040000D4
_080251F8: .4byte 0x0202D760
_080251FC: .4byte 0x060112A0
_08025200: .4byte 0x80000090
_08025204: .4byte gMain
_08025208:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _08025268
	movs r0, #0
	strh r0, [r1, #2]
	movs r0, #0xc8
	strh r0, [r1, #4]
	movs r2, #0
	ldr r6, _08025280 @ =gOamBuffer
	ldr r3, _08025284 @ =0xFFFFFE00
	mov r8, r3
_08025220:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	mov r7, sb
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _08025288 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08025220
_08025268:
	ldr r3, _0802528C @ =gMain
	ldr r0, [r3, #0x44]
	adds r0, #0xa4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08025290 @ =0x020314E0
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080252F4
	.align 2, 0
_08025280: .4byte gOamBuffer
_08025284: .4byte 0xFFFFFE00
_08025288: .4byte 0x000001FF
_0802528C: .4byte gMain
_08025290: .4byte 0x020314E0
_08025294:
	bl sub_242B4
	ldr r2, _080252B0 @ =0x020314E0
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	movs r3, #0
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	ldr r5, _080252B4 @ =0x00000367
	adds r0, r0, r5
	strb r3, [r0]
	b _080252F6
	.align 2, 0
_080252B0: .4byte 0x020314E0
_080252B4: .4byte 0x00000367
_080252B8:
	ldr r6, _080252C8 @ =0x020314E0
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080252CC
	subs r0, #1
	strh r0, [r1, #0x18]
	b _080252F6
	.align 2, 0
_080252C8: .4byte 0x020314E0
_080252CC:
	ldr r7, _080252E4 @ =0x0000071F
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080252E8
	movs r0, #3
	bl sub_19B64
	b _080252EE
	.align 2, 0
_080252E4: .4byte 0x0000071F
_080252E8:
	movs r0, #1
	bl sub_19B64
_080252EE:
	ldr r0, _08025308 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0
_080252F4:
	strb r0, [r1, #0x17]
_080252F6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025308: .4byte 0x020314E0

	thumb_func_start sub_2530C
sub_2530C: @ 0x0802530C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080253D0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r5, [r1, #0x48]
	ldrh r1, [r5]
	mov r8, r0
	ldr r0, _080253D4 @ =0x020314E0
	mov sb, r0
	cmp r1, #0
	beq _08025360
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025330:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _08025330
_08025360:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x48]
	movs r0, #0
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r5, [r0, #0x30]
	ldrh r0, [r5]
	cmp r0, #0
	beq _080253B0
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025380:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _08025380
_080253B0:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x30]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xe4
	strb r2, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080253D0: .4byte gMain
_080253D4: .4byte 0x020314E0
_080253D8: .4byte gOamBuffer
_080253DC: .4byte 0xFFFFFE00

	thumb_func_start sub_253E0
sub_253E0: @ 0x080253E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #1
	mov r8, r0
	ldr r0, _08025490 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x48]
	mov r1, r8
	strh r1, [r0]
	ldr r4, _08025494 @ =0x020314E0
	ldr r0, [r4]
	ldr r5, _08025498 @ =0x000006CC
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08025410
	bl sub_2971C
_08025410:
	ldr r3, [r4]
	ldr r2, _0802549C @ =0x000006C7
	adds r0, r3, r2
	ldr r4, _080254A0 @ =0x000006C6
	adds r1, r3, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	blt _08025428
	b _0802564C
_08025428:
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08025464
	ldr r1, _080254A4 @ =0x000006CA
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08025464
	adds r1, r3, #0
	adds r1, #0xe4
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _080254A8 @ =0x040000D4
	ldr r0, _080254AC @ =0x083A05CC
	str r0, [r1]
	ldr r0, _080254B0 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080254B4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080254B8 @ =0x0839DDAC
	str r0, [r1]
	ldr r0, _080254BC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080254C0 @ =0x80001400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08025464:
	ldr r1, _080254C4 @ =0x086AD3FE
	ldr r3, _08025494 @ =0x020314E0
	ldr r2, [r3]
	ldr r6, _08025498 @ =0x000006CC
	adds r4, r2, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _080254A4 @ =0x000006CA
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r5, r3, #0
	cmp r0, r1
	ble _080254C8
	adds r0, r1, #1
	strh r0, [r2]
	b _08025650
	.align 2, 0
_08025490: .4byte gMain
_08025494: .4byte 0x020314E0
_08025498: .4byte 0x000006CC
_0802549C: .4byte 0x000006C7
_080254A0: .4byte 0x000006C6
_080254A4: .4byte 0x000006CA
_080254A8: .4byte 0x040000D4
_080254AC: .4byte 0x083A05CC
_080254B0: .4byte 0x050003C0
_080254B4: .4byte 0x80000010
_080254B8: .4byte 0x0839DDAC
_080254BC: .4byte 0x06015800
_080254C0: .4byte 0x80001400
_080254C4: .4byte 0x086AD3FE
_080254C8:
	movs r7, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r3, [r5]
	ldr r2, _0802559C @ =0x000006CC
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bgt _080254E6
	b _0802562C
_080254E6:
	subs r2, #5
	adds r1, r3, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	strb r7, [r0]
	movs r3, #0
	mov r8, r3
	ldr r1, [r5]
	ldr r4, _080255A0 @ =0x000006C9
	adds r1, r1, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r3, [r5]
	adds r2, r3, r2
	ldr r1, _080255A4 @ =0x000006C6
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0802552E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0802553A
	adds r0, r3, #0
	adds r0, #0xe4
	strb r7, [r0]
_0802552E:
	ldr r0, [r5]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080255B4
_0802553A:
	ldr r0, [r5]
	ldr r2, _080255A4 @ =0x000006C6
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _080255A8 @ =0x000006C7
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _080255AC @ =0x00000625
	adds r0, r0, r4
	strb r1, [r0]
	movs r2, #0
	ldr r6, _080255B0 @ =gMain
	adds r4, r5, #0
	adds r3, #6
_0802555C:
	ldr r1, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r3
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0802555C
	ldr r0, [r6, #0x4c]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r5]
	ldr r1, _080255A0 @ =0x000006C9
	adds r0, r0, r1
	movs r2, #0
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r6, #0x44]
	ldr r0, [r0, #0x48]
	strh r2, [r0]
	b _080255CE
	.align 2, 0
_0802559C: .4byte 0x000006CC
_080255A0: .4byte 0x000006C9
_080255A4: .4byte 0x000006C6
_080255A8: .4byte 0x000006C7
_080255AC: .4byte 0x00000625
_080255B0: .4byte gMain
_080255B4:
	cmp r0, #0
	bne _080255BC
	movs r3, #0
	b _080255CE
_080255BC:
	ldr r0, _08025620 @ =gMain
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r0, [r0, #0x4c]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_080255CE:
	ldr r1, [r5]
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	ldr r7, _08025624 @ =0x000006CD
	adds r0, r1, r7
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldr r6, _08025628 @ =0x000006C9
	adds r0, r0, r6
	asrs r1, r3, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _08025650
	adds r4, r5, #0
	adds r5, r7, #0
_080255FA:
	ldr r0, [r4]
	asrs r1, r3, #0x10
	adds r0, r0, r5
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, [r4]
	adds r0, r0, r6
	lsls r3, r1, #0x10
	asrs r1, r3, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _080255FA
	b _08025650
	.align 2, 0
_08025620: .4byte gMain
_08025624: .4byte 0x000006CD
_08025628: .4byte 0x000006C9
_0802562C:
	cmp r0, #1
	bne _0802566C
	movs r4, #0xd9
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, _08025648 @ =0x000006D3
	adds r0, r3, r2
	adds r0, r0, r1
	movs r1, #0xd
	strb r1, [r0]
	b _08025650
	.align 2, 0
_08025648: .4byte 0x000006D3
_0802564C:
	movs r3, #0
	mov r8, r3
_08025650:
	ldr r0, _080256CC @ =0x020314E0
	ldr r0, [r0]
	ldr r4, _080256D0 @ =0x000006CC
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0802566C
	movs r0, #0x8c
	bl m4aSongNumStart
	bl sub_29664
_0802566C:
	ldr r0, _080256CC @ =0x020314E0
	ldr r5, [r0]
	ldr r1, _080256D0 @ =0x000006CC
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _08025682
	movs r2, #0
	mov r8, r2
_08025682:
	ldr r0, _080256D4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r7, [r0, #0x48]
	mov r3, r8
	cmp r3, #0
	beq _080256DC
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x14
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r1, #0x60
	subs r0, r0, r1
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x14
	adds r2, r5, #0
	adds r2, #0x5a
	ldr r3, _080256D8 @ =0xFFFFFED4
	adds r1, r3, #0
	ldrh r2, [r2]
	adds r1, r1, r2
	subs r0, r0, r1
	b _080256DE
	.align 2, 0
_080256CC: .4byte 0x020314E0
_080256D0: .4byte 0x000006CC
_080256D4: .4byte gMain
_080256D8: .4byte 0xFFFFFED4
_080256DC:
	movs r0, #0xc8
_080256DE:
	strh r0, [r7, #4]
	movs r4, #4
	ldrsh r0, [r7, r4]
	cmp r0, #0xc7
	ble _080256EC
	movs r0, #0xc8
	strh r0, [r7, #4]
_080256EC:
	movs r2, #0
	ldr r0, _080257EC @ =gOamBuffer
	mov ip, r0
	ldr r1, _080257F0 @ =0x086AD3FE
	mov sl, r1
	ldr r3, _080257F4 @ =0x020314E0
	mov sb, r3
	ldr r4, _080257F8 @ =0x000006CC
	mov r8, r4
_080256FE:
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	lsls r6, r5, #3
	adds r6, #8
	adds r6, r7, r6
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, ip
	lsls r3, r5, #1
	adds r3, r3, r5
	lsls r0, r3, #1
	str r0, [sp]
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	ldr r0, _080257FC @ =0x086B53E4
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, #2
	adds r2, r3, #1
	lsls r2, r2, #1
	str r2, [sp]
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	ldr r0, _080257FC @ =0x086B53E4
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r4]
	adds r3, #2
	lsls r3, r3, #1
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r3, r0
	ldr r0, _080257FC @ =0x086B53E4
	adds r3, r3, r0
	ldrh r0, [r3]
	strh r0, [r4, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r4, _08025800 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08025804 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #5
	ble _080256FE
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080257EC: .4byte gOamBuffer
_080257F0: .4byte 0x086AD3FE
_080257F4: .4byte 0x020314E0
_080257F8: .4byte 0x000006CC
_080257FC: .4byte 0x086B53E4
_08025800: .4byte 0x000001FF
_08025804: .4byte 0xFFFFFE00

	thumb_func_start sub_25808
sub_25808: @ 0x08025808
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _08025834 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _08025838 @ =0x00000602
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #8
	bls _08025828
	b _08025F36
_08025828:
	lsls r0, r0, #2
	ldr r1, _0802583C @ =_08025840
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025834: .4byte 0x020314E0
_08025838: .4byte 0x00000602
_0802583C: .4byte _08025840
_08025840: @ jump table
	.4byte _08025864 @ case 0
	.4byte _080258A8 @ case 1
	.4byte _0802592C @ case 2
	.4byte _08025A7C @ case 3
	.4byte _08025AF8 @ case 4
	.4byte _08025C18 @ case 5
	.4byte _08025C78 @ case 6
	.4byte _08025D60 @ case 7
	.4byte _08025DD0 @ case 8
_08025864:
	ldr r1, [r7]
	ldr r3, _08025878 @ =0x00000604
	adds r2, r1, r3
	ldrh r0, [r2]
	cmp r0, #0x3b
	bhi _0802587C
	adds r0, #1
	strh r0, [r2]
	b _08025890
	.align 2, 0
_08025878: .4byte 0x00000604
_0802587C:
	ldr r4, _0802589C @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r0, [r7]
	ldr r6, _080258A0 @ =0x00000604
	adds r0, r0, r6
	strh r2, [r0]
_08025890:
	ldr r0, _080258A4 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	b _08025F36
	.align 2, 0
_0802589C: .4byte 0x00000602
_080258A0: .4byte 0x00000604
_080258A4: .4byte gMain
_080258A8:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r5, #0
	movs r1, #5
	strb r1, [r0]
	ldr r1, _08025900 @ =0x040000D4
	ldr r0, _08025904 @ =0x083A07CC
	str r0, [r1]
	ldr r0, _08025908 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802590C @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025910 @ =0x083A27EC
	str r0, [r1]
	ldr r0, _08025914 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025918 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802591C @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x8c
	ldr r1, [r0]
	movs r4, #0
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x8d
	bl m4aSongNumStart
	ldr r1, [r7]
	ldr r0, _08025920 @ =0x00000602
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r2, _08025924 @ =0x00000604
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _08025928 @ =0x00000603
	adds r0, r0, r3
	strb r4, [r0]
	b _08025F36
	.align 2, 0
_08025900: .4byte 0x040000D4
_08025904: .4byte 0x083A07CC
_08025908: .4byte 0x06015800
_0802590C: .4byte 0x80001000
_08025910: .4byte 0x083A27EC
_08025914: .4byte 0x050003C0
_08025918: .4byte 0x80000010
_0802591C: .4byte gMain
_08025920: .4byte 0x00000602
_08025924: .4byte 0x00000604
_08025928: .4byte 0x00000603
_0802592C:
	ldr r2, _08025954 @ =0x086AE0C0
	ldr r1, [r7]
	ldr r4, _08025958 @ =0x00000603
	adds r3, r1, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r2, _0802595C @ =0x00000604
	adds r1, r1, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _08025964
	adds r0, r2, #1
	strh r0, [r1]
	ldr r3, _08025960 @ =gMain
	b _08025996
	.align 2, 0
_08025954: .4byte 0x086AE0C0
_08025958: .4byte 0x00000603
_0802595C: .4byte 0x00000604
_08025960: .4byte gMain
_08025964:
	movs r2, #0
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r7]
	ldr r3, _08025A60 @ =0x00000603
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r3, _08025A64 @ =gMain
	cmp r0, #7
	ble _08025996
	movs r0, #7
	strb r0, [r1]
	ldr r1, [r7]
	ldr r4, _08025A68 @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r3, #0x44]
	adds r0, #0x8c
	ldr r0, [r0]
	strh r2, [r0]
_08025996:
	ldr r2, [r7]
	ldr r6, _08025A60 @ =0x00000603
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r3, #0x44]
	adds r0, #0x8c
	ldr r6, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x7c
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r2, #0x5a
	ldrh r1, [r2]
	movs r0, #0xf4
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _080259CE
	movs r0, #0xc8
	strh r0, [r6, #4]
_080259CE:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r7, _08025A6C @ =gOamBuffer
	mov r8, r7
	ldr r1, _08025A70 @ =0x086B50AE
	mov ip, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r3, _08025A74 @ =0xFFFFFE00
	mov sb, r3
_080259E8:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r4, r8
	adds r2, r0, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025A78 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _080259E8
	b _08025F36
	.align 2, 0
_08025A60: .4byte 0x00000603
_08025A64: .4byte gMain
_08025A68: .4byte 0x00000602
_08025A6C: .4byte gOamBuffer
_08025A70: .4byte 0x086B50AE
_08025A74: .4byte 0xFFFFFE00
_08025A78: .4byte 0x000001FF
_08025A7C:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r3, #0
	movs r1, #6
	strb r1, [r0]
	ldr r1, _08025AD0 @ =0x040000D4
	ldr r0, _08025AD4 @ =0x083A29EC
	str r0, [r1]
	ldr r0, _08025AD8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025ADC @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025AE0 @ =0x083A320C
	str r0, [r1]
	ldr r0, _08025AE4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025AE8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025AEC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	ldr r1, [r7]
	ldr r4, _08025AF0 @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r6, _08025AF4 @ =0x00000604
	adds r1, r0, r6
	strh r3, [r1]
	movs r7, #0x88
	lsls r7, r7, #5
	adds r0, r0, r7
	strb r2, [r0]
	b _08025F36
	.align 2, 0
_08025AD0: .4byte 0x040000D4
_08025AD4: .4byte 0x083A29EC
_08025AD8: .4byte 0x06015800
_08025ADC: .4byte 0x80000400
_08025AE0: .4byte 0x083A320C
_08025AE4: .4byte 0x050003C0
_08025AE8: .4byte 0x80000010
_08025AEC: .4byte gMain
_08025AF0: .4byte 0x00000602
_08025AF4: .4byte 0x00000604
_08025AF8:
	ldr r1, [r7]
	ldr r0, _08025B10 @ =0x00000604
	adds r2, r1, r0
	ldrh r0, [r2]
	lsrs r5, r0, #1
	cmp r0, #0xe
	bhi _08025B18
	adds r0, #1
	strh r0, [r2]
	ldr r3, _08025B14 @ =gMain
	b _08025B3E
	.align 2, 0
_08025B10: .4byte 0x00000604
_08025B14: .4byte gMain
_08025B18:
	ldr r3, _08025BFC @ =gMain
	ldr r0, [r3, #0x44]
	adds r0, #0x90
	ldr r0, [r0]
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	ldr r6, _08025C00 @ =0x00000602
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	adds r6, #2
	adds r1, r0, r6
	strh r2, [r1]
	ldr r1, _08025C04 @ =0x00000603
	adds r0, r0, r1
	strb r4, [r0]
_08025B3E:
	ldr r0, [r3, #0x44]
	adds r0, #0x90
	ldr r6, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08025B6C
	movs r0, #0xc8
	strh r0, [r6, #4]
_08025B6C:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r3, _08025C08 @ =gOamBuffer
	mov r8, r3
	ldr r4, _08025C0C @ =0x086B4F6A
	mov ip, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r7, _08025C10 @ =0xFFFFFE00
	mov sb, r7
_08025B86:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, r8
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025C14 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _08025B86
	b _08025F36
	.align 2, 0
_08025BFC: .4byte gMain
_08025C00: .4byte 0x00000602
_08025C04: .4byte 0x00000603
_08025C08: .4byte gOamBuffer
_08025C0C: .4byte 0x086B4F6A
_08025C10: .4byte 0xFFFFFE00
_08025C14: .4byte 0x000001FF
_08025C18:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r1, #7
	strb r1, [r0]
	ldr r1, _08025C58 @ =0x040000D4
	ldr r0, _08025C5C @ =0x083A340C
	str r0, [r1]
	ldr r0, _08025C60 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025C64 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025C68 @ =0x083A542C
	str r0, [r1]
	ldr r0, _08025C6C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025C70 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, [r7]
	ldr r3, _08025C74 @ =0x00000602
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl sub_29924
	movs r0, #0x8e
	bl m4aSongNumStart
	b _08025F36
	.align 2, 0
_08025C58: .4byte 0x040000D4
_08025C5C: .4byte 0x083A340C
_08025C60: .4byte 0x06015800
_08025C64: .4byte 0x80001000
_08025C68: .4byte 0x083A542C
_08025C6C: .4byte 0x050003C0
_08025C70: .4byte 0x80000010
_08025C74: .4byte 0x00000602
_08025C78:
	ldr r2, _08025CB0 @ =gMain
	ldrh r0, [r2, #0x3c]
	movs r0, #0
	strh r0, [r2, #0x3c]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	ldrh r3, [r2, #0x38]
	orrs r0, r1
	strh r0, [r2, #0x38]
	ldr r0, [r7]
	ldr r4, _08025CB4 @ =0x00000604
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r3, r2, #0
	cmp r0, #0x48
	bhi _08025CF2
	cmp r0, #7
	bhi _08025CB8
	ldrh r0, [r3, #0x3c]
	movs r0, #0x10
	b _08025CF0
	.align 2, 0
_08025CB0: .4byte gMain
_08025CB4: .4byte 0x00000604
_08025CB8:
	movs r2, #0
	adds r6, r7, #0
	ldr r5, _08025D04 @ =0x000006D3
	movs r4, #0xd
_08025CC0:
	ldr r1, [r6]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r5
	adds r1, r1, r0
	strb r4, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08025CC0
	ldr r0, [r7]
	ldr r6, _08025D08 @ =0x00000604
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	cmp r0, #0
	bge _08025CEA
	adds r0, #3
_08025CEA:
	asrs r0, r0, #2
	adds r0, #0x10
	ldrh r1, [r3, #0x3c]
_08025CF0:
	strh r0, [r3, #0x3c]
_08025CF2:
	ldr r1, [r7]
	ldr r0, _08025D08 @ =0x00000604
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0x47
	bhi _08025D0C
	adds r0, #1
	strh r0, [r2]
	b _08025D28
	.align 2, 0
_08025D04: .4byte 0x000006D3
_08025D08: .4byte 0x00000604
_08025D0C:
	ldr r2, _08025D4C @ =0x00000602
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	ldr r0, [r7]
	ldr r4, _08025D50 @ =0x00000604
	adds r1, r0, r4
	movs r2, #0
	strh r3, [r1]
	ldr r6, _08025D54 @ =0x00000603
	adds r0, r0, r6
	strb r2, [r0]
_08025D28:
	ldr r1, [r7]
	ldr r7, _08025D50 @ =0x00000604
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #8
	bhi _08025D36
	b _08025F36
_08025D36:
	ldr r2, _08025D58 @ =0x000006CA
	adds r0, r1, r2
	ldrh r1, [r0]
	ldr r0, _08025D5C @ =0x00006FFF
	cmp r1, r0
	bls _08025D44
	b _08025F36
_08025D44:
	bl sub_29A6C
	b _08025F36
	.align 2, 0
_08025D4C: .4byte 0x00000602
_08025D50: .4byte 0x00000604
_08025D54: .4byte 0x00000603
_08025D58: .4byte 0x000006CA
_08025D5C: .4byte 0x00006FFF
_08025D60:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r1, #8
	strb r1, [r0]
	ldr r1, _08025DAC @ =0x040000D4
	ldr r0, _08025DB0 @ =0x083A562C
	str r0, [r1]
	ldr r0, _08025DB4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025DB8 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025DBC @ =0x083A6E4C
	str r0, [r1]
	ldr r0, _08025DC0 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025DC4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025DC8 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x94
	ldr r1, [r0]
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, [r7]
	ldr r3, _08025DCC @ =0x00000602
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r4, #0x88
	lsls r4, r4, #5
	adds r0, r0, r4
	strb r2, [r0]
	b _08025F36
	.align 2, 0
_08025DAC: .4byte 0x040000D4
_08025DB0: .4byte 0x083A562C
_08025DB4: .4byte 0x06015800
_08025DB8: .4byte 0x80000C00
_08025DBC: .4byte 0x083A6E4C
_08025DC0: .4byte 0x050003C0
_08025DC4: .4byte 0x80000010
_08025DC8: .4byte gMain
_08025DCC: .4byte 0x00000602
_08025DD0:
	ldr r2, _08025DF8 @ =0x086AE0D0
	ldr r1, [r7]
	ldr r5, _08025DFC @ =0x00000603
	adds r3, r1, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r2, _08025E00 @ =0x00000604
	adds r1, r1, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _08025E08
	adds r0, r2, #1
	strh r0, [r1]
	ldr r3, _08025E04 @ =gMain
	b _08025E6C
	.align 2, 0
_08025DF8: .4byte 0x086AE0D0
_08025DFC: .4byte 0x00000603
_08025E00: .4byte 0x00000604
_08025E04: .4byte gMain
_08025E08:
	movs r4, #0
	movs r2, #0
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r7]
	ldr r3, _08025F44 @ =0x00000603
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r3, _08025F48 @ =gMain
	cmp r0, #0xa
	ble _08025E6C
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r7]
	ldr r6, _08025F4C @ =0x000006C6
	adds r0, r0, r6
	strb r4, [r0]
	ldr r0, [r7]
	ldr r1, _08025F50 @ =0x000006C7
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r7]
	subs r6, #0xa1
	adds r0, r0, r6
	strb r4, [r0]
	ldrh r0, [r3, #0x38]
	movs r0, #0xce
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3c]
	strh r2, [r3, #0x3c]
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r7]
	adds r0, r0, r5
	movs r1, #0xa
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xe4
	strb r4, [r0]
_08025E6C:
	ldr r2, [r7]
	ldr r7, _08025F44 @ =0x00000603
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r6, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r2, #0x5a
	ldrh r1, [r2]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08025EA8
	movs r0, #0xc8
	strh r0, [r6, #4]
_08025EA8:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r3, _08025F54 @ =gOamBuffer
	mov r8, r3
	ldr r4, _08025F58 @ =0x086B4E62
	mov ip, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sl, r0
	ldr r7, _08025F5C @ =0xFFFFFE00
	mov sb, r7
_08025EC2:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, r8
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025F60 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _08025EC2
_08025F36:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025F44: .4byte 0x00000603
_08025F48: .4byte gMain
_08025F4C: .4byte 0x000006C6
_08025F50: .4byte 0x000006C7
_08025F54: .4byte gOamBuffer
_08025F58: .4byte 0x086B4E62
_08025F5C: .4byte 0xFFFFFE00
_08025F60: .4byte 0x000001FF

	thumb_func_start sub_25F64
sub_25F64: @ 0x08025F64
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r5, _0802607C @ =0x020314E0
	ldr r1, [r5]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r5]
	movs r3, #0
	strh r2, [r0, #0x18]
	ldr r1, _08026080 @ =0x000006DB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x36
	strb r3, [r0]
	bl sub_C00
	ldr r4, [r5]
	ldr r6, _08026084 @ =gMain
	ldr r1, [r6, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	adds r4, #0x32
	strb r0, [r4]
	ldr r2, [r5]
	ldr r0, _08026088 @ =0x08055A68
	mov sb, r0
	adds r0, r2, #0
	adds r0, #0x32
	movs r3, #0
	ldrsb r3, [r0, r3]
	ldrb r1, [r6, #4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r2, #0x35
	strb r0, [r2]
	ldr r1, [r5]
	ldr r2, _0802608C @ =0x08137928
	mov r8, r2
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _08026090 @ =0x000006DA
	adds r1, r1, r2
	strb r0, [r1]
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	movs r1, #6
	bl __modsi3
	ldrb r2, [r6, #4]
	lsls r1, r2, #3
	subs r1, r1, r2
	adds r1, r1, r0
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	adds r4, #0x35
	strb r0, [r4]
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _08026094 @ =0x000006D9
	adds r1, r1, r2
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	movs r0, #0
	movs r1, #1
	bl sub_1C7F4
	movs r2, #0
	ldr r4, _08026098 @ =0x000006D3
	movs r3, #0xd
	adds r6, r5, #0
_08026032:
	ldr r1, [r5]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08026032
	ldr r1, _0802609C @ =0x040000D4
	ldr r0, _080260A0 @ =0x083A8AAC
	str r0, [r1]
	ldr r0, _080260A4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080260A8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080260AC @ =0x084FA20C
	str r0, [r1]
	ldr r0, _080260B0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080260B4 @ =0x80000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r6]
	adds r0, #0xe4
	movs r1, #0xc
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802607C: .4byte 0x020314E0
_08026080: .4byte 0x000006DB
_08026084: .4byte gMain
_08026088: .4byte 0x08055A68
_0802608C: .4byte 0x08137928
_08026090: .4byte 0x000006DA
_08026094: .4byte 0x000006D9
_08026098: .4byte 0x000006D3
_0802609C: .4byte 0x040000D4
_080260A0: .4byte 0x083A8AAC
_080260A4: .4byte 0x050003C0
_080260A8: .4byte 0x80000010
_080260AC: .4byte 0x084FA20C
_080260B0: .4byte 0x06015800
_080260B4: .4byte 0x80000140

	thumb_func_start sub_260B8
sub_260B8: @ 0x080260B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _080260E4 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #5
	bls _080260D8
	b _0802674E
_080260D8:
	lsls r0, r0, #2
	ldr r1, _080260E8 @ =_080260EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080260E4: .4byte 0x020314E0
_080260E8: .4byte _080260EC
_080260EC: @ jump table
	.4byte _08026104 @ case 0
	.4byte _080261E0 @ case 1
	.4byte _080262E4 @ case 2
	.4byte _08026318 @ case 3
	.4byte _08026318 @ case 4
	.4byte _08026608 @ case 5
_08026104:
	ldr r3, _08026198 @ =gMain
	ldrh r0, [r3, #0x38]
	movs r5, #0
	movs r4, #0
	ldr r0, _0802619C @ =0x00001C10
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r3, #0x3a]
	mov r0, sb
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	mov r2, sb
	ldr r1, [r2]
	movs r6, #0xdc
	lsls r6, r6, #3
	adds r0, r1, r6
	strh r4, [r0]
	ldr r7, _080261A0 @ =0x000005FE
	adds r0, r1, r7
	strh r4, [r0]
	ldr r0, _080261A4 @ =0x000005FB
	adds r1, r1, r0
	movs r2, #1
	strb r2, [r1]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x50]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x54]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x5c]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x58]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x4c]
	strh r2, [r0]
	mov r1, sb
	ldr r2, [r1]
	adds r6, #0x10
	adds r0, r2, r6
	movs r1, #0x1e
	strh r1, [r0]
	adds r7, #0xf4
	adds r0, r2, r7
	strh r1, [r0]
	ldr r1, _080261A8 @ =0x000006F4
	adds r0, r2, r1
	strh r4, [r0]
	ldrb r0, [r3, #4]
	cmp r0, #0
	bne _080261B0
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0xa
	strb r1, [r0]
	mov r4, sb
	ldr r0, [r4]
	ldr r5, _080261AC @ =0x00000171
	adds r0, r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	movs r6, #0xb9
	lsls r6, r6, #1
	adds r0, r0, r6
	strb r1, [r0]
	b _080261CC
	.align 2, 0
_08026198: .4byte gMain
_0802619C: .4byte 0x00001C10
_080261A0: .4byte 0x000005FE
_080261A4: .4byte 0x000005FB
_080261A8: .4byte 0x000006F4
_080261AC: .4byte 0x00000171
_080261B0:
	movs r7, #0xb8
	lsls r7, r7, #1
	adds r0, r2, r7
	strb r5, [r0]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _080261DC @ =0x00000171
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r1]
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r5, [r0]
_080261CC:
	mov r4, sb
	ldr r0, [r4]
	movs r5, #0xba
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
	b _0802674E
	.align 2, 0
_080261DC: .4byte 0x00000171
_080261E0:
	mov r6, sb
	ldr r1, [r6]
	ldr r7, _080262CC @ =0x000005FC
	adds r0, r1, r7
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	bne _080261FA
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r6]
	strh r2, [r0, #0x18]
_080261FA:
	ldr r0, _080262D0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08026296
	mov r4, sb
	ldr r3, [r4]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r0, [r2]
	cmp r0, #0x8e
	bhi _08026224
	ldr r1, _080262D4 @ =0x08137944
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r5, #0xb8
	lsls r5, r5, #1
	adds r0, r3, r5
	strb r1, [r0]
_08026224:
	mov r6, sb
	ldr r2, [r6]
	adds r1, r2, r4
	ldrh r0, [r1]
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x8e
	bhi _08026254
	ldr r3, _080262D4 @ =0x08137944
	ldrh r1, [r1]
	adds r0, r1, #0
	subs r0, #0x12
	cmp r0, #0
	bge _08026244
	adds r0, #7
_08026244:
	asrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r7, #0xb9
	lsls r7, r7, #1
	adds r1, r2, r7
	strb r0, [r1]
_08026254:
	mov r0, sb
	ldr r2, [r0]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r0, [r1]
	subs r0, #0x24
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x8e
	bhi _08026286
	ldr r3, _080262D4 @ =0x08137944
	ldrh r1, [r1]
	adds r0, r1, #0
	subs r0, #0x24
	cmp r0, #0
	bge _08026278
	adds r0, #7
_08026278:
	asrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _080262D8 @ =0x00000171
	adds r1, r2, r4
	strb r0, [r1]
_08026286:
	mov r5, sb
	ldr r1, [r5]
	movs r6, #0xba
	lsls r6, r6, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08026296:
	mov r7, sb
	ldr r4, [r7]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r2, _080262DC @ =0x000006F2
	adds r1, r4, r2
	ldrh r1, [r1]
	bl __divsi3
	movs r3, #0xdc
	lsls r3, r3, #3
	adds r1, r4, r3
	strh r0, [r1]
	ldr r5, _080262E0 @ =0x000006C4
	adds r4, r4, r5
	movs r0, #1
	strb r0, [r4]
	ldr r1, [r7]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	bl sub_26778
	b _0802674E
	.align 2, 0
_080262CC: .4byte 0x000005FC
_080262D0: .4byte gMain
_080262D4: .4byte 0x08137944
_080262D8: .4byte 0x00000171
_080262DC: .4byte 0x000006F2
_080262E0: .4byte 0x000006C4
_080262E4:
	ldr r1, _08026338 @ =0x020314E0
	ldr r2, [r1]
	ldrh r0, [r2, #0x18]
	cmp r0, #0xe
	bhi _08026312
	adds r0, #1
	strh r0, [r2, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _08026312
	ldrb r0, [r2, #0x17]
	adds r0, #1
	strb r0, [r2, #0x17]
	ldr r1, [r1]
	ldr r6, _0802633C @ =0x000006F2
	adds r2, r1, r6
	movs r0, #6
	strh r0, [r2]
	ldr r7, _08026340 @ =0x000006F4
	adds r1, r1, r7
	movs r0, #0
	strh r0, [r1]
_08026312:
	movs r0, #0
	bl sub_26820
_08026318:
	ldr r0, _08026338 @ =0x020314E0
	ldr r5, [r0]
	movs r2, #0x17
	ldrsb r2, [r5, r2]
	mov sb, r0
	cmp r2, #3
	bne _08026344
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r2, _0802633C @ =0x000006F2
	adds r1, r5, r2
	b _0802647C
	.align 2, 0
_08026338: .4byte 0x020314E0
_0802633C: .4byte 0x000006F2
_08026340: .4byte 0x000006F4
_08026344:
	cmp r2, #4
	beq _0802634A
	b _08026494
_0802634A:
	movs r3, #0xde
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080263C0
	movs r0, #0x17
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _080263C0
	ldr r4, _08026380 @ =0x000006F4
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _080263CE
	ldr r0, _08026384 @ =gMain
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026388
	movs r0, #0x30
	b _0802638A
	.align 2, 0
_08026380: .4byte 0x000006F4
_08026384: .4byte gMain
_08026388:
	movs r0, #1
_0802638A:
	strh r0, [r1]
	mov r5, sb
	ldr r1, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r0, r1, r6
	ldrh r2, [r0]
	ldr r7, _0802642C @ =0x000006F6
	adds r0, r1, r7
	strh r2, [r0]
	ldr r2, _08026430 @ =0x00000163
	adds r0, r1, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x21
	strb r1, [r0]
	ldr r1, [r5]
	ldr r3, _08026434 @ =0x00000724
	adds r2, r1, r3
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r1, r1, r4
	movs r0, #2
	strb r0, [r1]
_080263C0:
	mov r5, sb
	ldr r0, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802646E
_080263CE:
	mov r7, sb
	ldr r2, [r7]
	ldr r0, _08026428 @ =0x000006F4
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r0, _08026438 @ =gMain
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026412
	ldr r1, _0802643C @ =0x00000283
	adds r0, r2, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, [r7]
	ldr r3, _08026428 @ =0x000006F4
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, #0x17
	bhi _08026412
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _08026412
	movs r0, #0
	strh r0, [r1]
_08026412:
	mov r5, sb
	ldr r4, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r1, r4, r6
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026440
	movs r0, #5
	strb r0, [r4, #0x17]
	b _0802646E
	.align 2, 0
_08026428: .4byte 0x000006F4
_0802642C: .4byte 0x000006F6
_08026430: .4byte 0x00000163
_08026434: .4byte 0x00000724
_08026438: .4byte gMain
_0802643C: .4byte 0x00000283
_08026440:
	movs r7, #0xde
	lsls r7, r7, #3
	adds r6, r4, r7
	ldr r0, _08026488 @ =0x000006F2
	adds r5, r4, r0
	ldrh r0, [r6]
	ldrh r2, [r5]
	cmp r0, r2
	bne _0802646E
	ldrh r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r3, _0802648C @ =0x000006F6
	adds r1, r4, r3
	ldrh r1, [r1]
	bl __divsi3
	movs r1, #0x28
	subs r1, r1, r0
	movs r0, #0
	strh r1, [r5]
	strh r0, [r6]
_0802646E:
	ldr r0, _08026490 @ =0x020314E0
	ldr r1, [r0]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r4, r1, r5
	ldr r6, _08026488 @ =0x000006F2
	adds r1, r1, r6
_0802647C:
	ldrh r0, [r4]
	ldrh r1, [r1]
	bl __umodsi3
	strh r0, [r4]
	b _080264E2
	.align 2, 0
_08026488: .4byte 0x000006F2
_0802648C: .4byte 0x000006F6
_08026490: .4byte 0x020314E0
_08026494:
	movs r7, #0xde
	lsls r7, r7, #3
	adds r4, r5, r7
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, _08026554 @ =0x000006F2
	adds r1, r5, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	bl __umodsi3
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _080264E2
	strh r2, [r5, #0x18]
	ldrb r0, [r5, #0x17]
	adds r0, #1
	strb r0, [r5, #0x17]
	ldr r1, _08026558 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x5c]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x50]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x54]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	adds r0, #0x88
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x93
	bl m4aSongNumStart
_080264E2:
	ldr r6, _0802655C @ =0x020314E0
	ldr r5, [r6]
	movs r7, #0xde
	lsls r7, r7, #3
	adds r4, r5, r7
	ldrh r0, [r4]
	lsls r0, r0, #5
	ldr r2, _08026554 @ =0x000006F2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl __divsi3
	movs r3, #0xdc
	lsls r3, r3, #3
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	bne _0802651C
	ldr r4, _08026560 @ =0x000006DA
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r2, _08026564 @ =0x000006D9
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
_0802651C:
	ldr r4, [r6]
	adds r0, r4, r7
	ldrh r5, [r0]
	cmp r5, #1
	beq _08026528
	b _0802674E
_08026528:
	ldr r0, _08026558 @ =gMain
	movs r1, #0xa
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq _08026568
	adds r4, #0x32
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #1
	movs r1, #7
	bl __modsi3
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, #0x33
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0x34
	strb r5, [r0]
	b _080265A8
	.align 2, 0
_08026554: .4byte 0x000006F2
_08026558: .4byte gMain
_0802655C: .4byte 0x020314E0
_08026560: .4byte 0x000006DA
_08026564: .4byte 0x000006D9
_08026568:
	adds r4, #0x32
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #1
	movs r1, #6
	bl __modsi3
	strb r0, [r4]
	ldr r4, [r6]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	movs r1, #6
	bl __modsi3
	adds r4, #0x33
	strb r0, [r4]
	ldr r4, [r6]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #2
	movs r1, #6
	bl __modsi3
	adds r4, #0x34
	strb r0, [r4]
_080265A8:
	ldr r5, _080265F4 @ =0x020314E0
	ldr r2, [r5]
	ldr r4, _080265F8 @ =0x08055A68
	adds r0, r2, #0
	adds r0, #0x32
	movs r3, #0
	ldrsb r3, [r0, r3]
	ldr r6, _080265FC @ =gMain
	ldrb r1, [r6, #4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r2, #0x35
	strb r0, [r2]
	ldr r1, [r5]
	ldr r2, _08026600 @ =0x08137928
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08026604 @ =0x000006DA
	adds r1, r1, r7
	strb r0, [r1]
	movs r0, #0
	movs r1, #1
	bl sub_1C7F4
	movs r0, #0x81
	bl m4aSongNumStart
	b _0802674E
	.align 2, 0
_080265F4: .4byte 0x020314E0
_080265F8: .4byte 0x08055A68
_080265FC: .4byte gMain
_08026600: .4byte 0x08137928
_08026604: .4byte 0x000006DA
_08026608:
	ldr r0, _08026640 @ =0x020314E0
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x31
	bhi _08026628
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x32
	bne _08026628
	movs r0, #0
	strb r0, [r1, #0x17]
	movs r0, #1
	bl sub_19B64
_08026628:
	ldr r0, _08026640 @ =0x020314E0
	ldr r2, [r0]
	ldrh r3, [r2, #0x18]
	mov sb, r0
	cmp r3, #0x1c
	bls _08026636
	b _08026742
_08026636:
	cmp r3, #7
	bhi _08026644
	adds r0, r3, #0
	lsrs r3, r0, #2
	b _08026654
	.align 2, 0
_08026640: .4byte 0x020314E0
_08026644:
	ldrh r0, [r2, #0x18]
	subs r0, #8
	movs r1, #3
	bl __divsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08026654:
	ldr r0, _08026760 @ =gMain
	ldr r1, [r0, #0x44]
	adds r1, #0x88
	ldr r6, [r1]
	ldrh r1, [r6]
	cmp r1, #0
	beq _08026724
	mov r0, sb
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r6, #2]
	movs r4, #0xdc
	lsls r4, r4, #3
	adds r2, r1, r4
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08026696
	movs r0, #0xc8
	strh r0, [r6, #4]
_08026696:
	movs r2, #0
	lsls r1, r3, #0x10
	ldr r7, _08026764 @ =gOamBuffer
	mov r8, r7
	ldr r0, _08026768 @ =0x086B51CE
	mov ip, r0
	asrs r1, r1, #0x10
	movs r0, #0x36
	adds r3, r1, #0
	muls r3, r0, r3
	str r3, [sp]
	ldr r4, _0802676C @ =0xFFFFFE00
	mov sl, r4
_080266B0:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r6, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, r8
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r5, [sp]
	adds r0, r0, r5
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r5
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, r8
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08026770 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #8
	ble _080266B0
_08026724:
	mov r4, sb
	ldr r3, [r4]
	ldrh r0, [r3, #0x18]
	cmp r0, #0x1c
	bne _08026742
	ldr r5, _08026760 @ =gMain
	ldr r0, [r5, #0x44]
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xe4
	strb r2, [r0]
_08026742:
	mov r6, sb
	ldr r0, [r6]
	ldr r7, _08026774 @ =0x000006C4
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0]
_0802674E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026760: .4byte gMain
_08026764: .4byte gOamBuffer
_08026768: .4byte 0x086B51CE
_0802676C: .4byte 0xFFFFFE00
_08026770: .4byte 0x000001FF
_08026774: .4byte 0x000006C4

	thumb_func_start sub_26778
sub_26778: @ 0x08026778
	push {r4, r5, lr}
	ldr r0, _080267E0 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x64
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	ldr r4, _080267E4 @ =0x020314E0
	ldr r2, [r4]
	ldr r1, _080267E8 @ =0x0000070C
	adds r3, r2, r1
	movs r5, #0
	movs r1, #0
	strh r1, [r3]
	ldr r1, _080267EC @ =0x08137AB8
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080267F0 @ =0x0000072F
	adds r2, r2, r0
	strb r1, [r2]
	ldr r0, [r4]
	ldr r2, _080267F4 @ =0x0000072E
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	subs r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	cmp r3, #7
	beq _080267C2
	cmp r3, #9
	bne _080267FC
_080267C2:
	ldr r0, [r4]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _080267F8 @ =0x0000072A
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	subs r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	b _08026816
	.align 2, 0
_080267E0: .4byte gMain
_080267E4: .4byte 0x020314E0
_080267E8: .4byte 0x0000070C
_080267EC: .4byte 0x08137AB8
_080267F0: .4byte 0x0000072F
_080267F4: .4byte 0x0000072E
_080267F8: .4byte 0x0000072A
_080267FC:
	ldr r0, [r4]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _0802681C @ =0x0000072A
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
_08026816:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802681C: .4byte 0x0000072A

	thumb_func_start sub_26820
sub_26820: @ 0x08026820
	push {r4, lr}
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08026878
	ldr r2, _0802686C @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _08026870 @ =0x0000072A
	adds r0, r0, r1
	movs r3, #1
	strb r3, [r0]
	ldr r0, [r2]
	movs r4, #0xe5
	lsls r4, r4, #3
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, #7
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r4, #6
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	subs r4, #3
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08026874 @ =0x00000729
	adds r0, r0, r1
	strb r3, [r0]
	b _080268AC
	.align 2, 0
_0802686C: .4byte 0x020314E0
_08026870: .4byte 0x0000072A
_08026874: .4byte 0x00000729
_08026878:
	ldr r2, _080268BC @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _080268C0 @ =0x00000729
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _080268C4 @ =0x0000072A
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	subs r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
_080268AC:
	ldr r0, [r2]
	ldr r1, _080268C8 @ =0x0000070E
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080268BC: .4byte 0x020314E0
_080268C0: .4byte 0x00000729
_080268C4: .4byte 0x0000072A
_080268C8: .4byte 0x0000070E

	thumb_func_start sub_268CC
sub_268CC: @ 0x080268CC
	push {r4, r5, r6, r7, lr}
	ldr r5, _08026974 @ =0x020314E0
	ldr r0, [r5]
	ldr r1, _08026978 @ =0x000006BC
	adds r0, r0, r1
	movs r6, #0
	strb r6, [r0]
	ldr r0, [r5]
	ldr r2, _0802697C @ =0x000006BD
	adds r0, r0, r2
	strb r6, [r0]
	ldr r7, _08026980 @ =gMain
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08026902
	ldr r0, [r5]
	ldr r1, _08026984 @ =0x000002BE
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	ldr r2, _08026988 @ =0x000002C2
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, #2
	adds r0, r0, r1
	strh r6, [r0]
_08026902:
	ldr r0, [r5]
	ldr r2, _0802698C @ =0x000006BE
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xd8
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r4, #0
	strh r6, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r2, _08026990 @ =0x000006C4
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r7, #0x44]
	ldr r0, [r0, #0x34]
	strh r6, [r0]
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r2, #0xd1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r2, _08026994 @ =0x00000736
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _08026998 @ =0x00000739
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _0802699C @ =0x0000073A
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _080269A0 @ =0x0000073B
	adds r0, r0, r1
	strb r4, [r0]
	bl sub_4D648
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026974: .4byte 0x020314E0
_08026978: .4byte 0x000006BC
_0802697C: .4byte 0x000006BD
_08026980: .4byte gMain
_08026984: .4byte 0x000002BE
_08026988: .4byte 0x000002C2
_0802698C: .4byte 0x000006BE
_08026990: .4byte 0x000006C4
_08026994: .4byte 0x00000736
_08026998: .4byte 0x00000739
_0802699C: .4byte 0x0000073A
_080269A0: .4byte 0x0000073B

	thumb_func_start sub_269A4
sub_269A4: @ 0x080269A4
	push {r4, r5, lr}
	ldr r2, _080269F4 @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r0, [r2]
	strh r3, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, [r2]
	adds r4, r2, #0
	adds r4, #0x6c
	movs r5, #0xe1
	lsls r5, r5, #4
	adds r0, r5, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	ldr r5, _080269F8 @ =0x00000296
	adds r1, r2, r5
	strh r0, [r1]
	strh r3, [r4]
	ldr r0, _080269FC @ =0x00000724
	adds r2, r2, r0
	subs r0, #0x1c
	strh r0, [r2]
	ldr r1, _08026A00 @ =0x040000D4
	ldr r0, _08026A04 @ =0x081C0064
	str r0, [r1]
	ldr r0, _08026A08 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08026A0C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080269F4: .4byte 0x020314E0
_080269F8: .4byte 0x00000296
_080269FC: .4byte 0x00000724
_08026A00: .4byte 0x040000D4
_08026A04: .4byte 0x081C0064
_08026A08: .4byte 0x05000180
_08026A0C: .4byte 0x80000010

	thumb_func_start sub_26A10
sub_26A10: @ 0x08026A10
	push {r4, r5, r6, lr}
	ldr r4, _08026A68 @ =0x020314E0
	ldr r1, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026A4C
	ldr r3, _08026A6C @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08026A4C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _08026A4C
	bl m4aMPlayAllStop
	movs r0, #0x13
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #6
	strb r1, [r0, #0x17]
_08026A4C:
	ldr r1, _08026A68 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #7
	bls _08026A5E
	b _08026E9E
_08026A5E:
	lsls r0, r0, #2
	ldr r1, _08026A70 @ =_08026A74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026A68: .4byte 0x020314E0
_08026A6C: .4byte 0x00000296
_08026A70: .4byte _08026A74
_08026A74: @ jump table
	.4byte _08026A94 @ case 0
	.4byte _08026AC4 @ case 1
	.4byte _08026C10 @ case 2
	.4byte _08026C68 @ case 3
	.4byte _08026C88 @ case 4
	.4byte _08026CC0 @ case 5
	.4byte _08026E5C @ case 6
	.4byte _08026E84 @ case 7
_08026A94:
	ldr r0, _08026ABC @ =gMain
	ldrb r2, [r0, #0xf]
	cmp r2, #0
	bne _08026AAE
	ldr r0, [r5]
	ldrb r1, [r0, #0x17]
	adds r1, #1
	strb r1, [r0, #0x17]
	ldr r0, [r5]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	str r2, [r0]
_08026AAE:
	ldr r0, [r5]
	ldr r2, _08026AC0 @ =0x000006BC
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	b _08026E9E
	.align 2, 0
_08026ABC: .4byte gMain
_08026AC0: .4byte 0x000006BC
_08026AC4:
	movs r0, #4
	movs r1, #0
	bl sub_1C7F4
	ldr r4, _08026B5C @ =0x020314E0
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0x23
	bne _08026ADC
	movs r0, #0x17
	bl m4aSongNumStart
_08026ADC:
	ldr r1, [r4]
	ldr r3, _08026B60 @ =0x000006BC
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026B1E
	ldrb r0, [r1, #0x17]
	adds r0, #1
	movs r5, #0
	strb r0, [r1, #0x17]
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0x22
	bhi _08026B02
	movs r0, #0x17
	bl m4aSongNumStart
_08026B02:
	ldr r0, [r4]
	ldr r1, _08026B64 @ =0x000006BD
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _08026B68 @ =0x000006BE
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r0, r0, r3
	strh r5, [r0]
_08026B1E:
	ldr r5, _08026B5C @ =0x020314E0
	ldr r6, [r5]
	ldrh r4, [r6, #0x18]
	adds r0, r4, #0
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __udivsi3
	adds r4, #1
	movs r3, #0
	strh r4, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _08026B74
	ldr r1, _08026B6C @ =0x00000736
	adds r0, r6, r1
	strb r3, [r0]
	ldr r0, [r5]
	ldr r2, _08026B70 @ =0x00000737
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r5]
	adds r1, #2
	adds r0, r0, r1
	strb r3, [r0]
	b _08026BD8
	.align 2, 0
_08026B5C: .4byte 0x020314E0
_08026B60: .4byte 0x000006BC
_08026B64: .4byte 0x000006BD
_08026B68: .4byte 0x000006BE
_08026B6C: .4byte 0x00000736
_08026B70: .4byte 0x00000737
_08026B74:
	cmp r2, #1
	bne _08026B9C
	ldr r0, _08026B94 @ =0x00000736
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08026B98 @ =0x00000737
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r3, [r0]
	b _08026BD8
	.align 2, 0
_08026B94: .4byte 0x00000736
_08026B98: .4byte 0x00000737
_08026B9C:
	cmp r2, #2
	bne _08026BC0
	ldr r3, _08026BBC @ =0x00000736
	adds r0, r6, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xe7
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	b _08026BD8
	.align 2, 0
_08026BBC: .4byte 0x00000736
_08026BC0:
	ldr r2, _08026C04 @ =0x00000736
	adds r0, r6, r2
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _08026C08 @ =0x00000737
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r0, r0, r2
	strb r1, [r0]
_08026BD8:
	ldr r0, [r5]
	ldr r3, _08026C04 @ =0x00000736
	adds r1, r0, r3
	ldrb r1, [r1]
	ldr r2, _08026C0C @ =0x00000739
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	b _08026E9E
	.align 2, 0
_08026C04: .4byte 0x00000736
_08026C08: .4byte 0x00000737
_08026C0C: .4byte 0x00000739
_08026C10:
	bl sub_219A8
	ldr r5, _08026C5C @ =0x020314E0
	ldr r0, [r5]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r4, #0
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r2, _08026C60 @ =0x00000736
	adds r1, r0, r2
	strb r4, [r1]
	ldr r3, _08026C64 @ =0x00000739
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r5]
	b _08026E72
	.align 2, 0
_08026C5C: .4byte 0x020314E0
_08026C60: .4byte 0x00000736
_08026C64: .4byte 0x00000739
_08026C68:
	bl sub_219EC
	ldr r0, _08026C84 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _08026C80
	b _08026E9E
_08026C80:
	b _08026E72
	.align 2, 0
_08026C84: .4byte 0x020314E0
_08026C88:
	ldr r0, [r5]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r1, r0, r3
	str r2, [r1]
	ldr r1, _08026CBC @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2f
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	b _08026E9E
	.align 2, 0
_08026CBC: .4byte 0x000006EC
_08026CC0:
	ldr r4, _08026D34 @ =0x020314E0
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x91
	beq _08026CCC
	b _08026DC6
_08026CCC:
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r2, _08026D38 @ =0x000006EC
	adds r1, r1, r2
	movs r0, #0x2f
	strb r0, [r1]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08026D3C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08026D92
	ldr r0, [r4]
	movs r1, #0x90
	strh r1, [r0, #0x28]
	bl m4aMPlayAllStop
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _08026D80
	adds r1, r2, #0
	adds r1, #0x34
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r3, _08026D40 @ =0x000006BC
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08026D44
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r1, [r0]
	subs r0, #1
	b _08026D4A
	.align 2, 0
_08026D34: .4byte 0x020314E0
_08026D38: .4byte 0x000006EC
_08026D3C: .4byte gMain
_08026D40: .4byte 0x000006BC
_08026D44:
	ldrb r1, [r1]
	adds r0, r2, #0
	adds r0, #0x32
_08026D4A:
	strb r1, [r0]
	ldr r6, _08026D7C @ =0x020314E0
	ldr r5, [r6]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #1
	movs r1, #6
	bl __modsi3
	adds r5, #0x33
	strb r0, [r5]
	ldr r5, [r6]
	adds r4, #2
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	adds r5, #0x34
	strb r0, [r5]
	ldr r1, [r6]
	adds r1, #0x36
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08026DC6
	.align 2, 0
_08026D7C: .4byte 0x020314E0
_08026D80:
	adds r1, r2, #0
	adds r1, #0x32
	movs r0, #6
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x36
	movs r1, #0
	strb r1, [r0]
	b _08026DC6
_08026D92:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08026DC6
	bl m4aMPlayAllStop
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x3c
	strh r0, [r1, #0x28]
	movs r0, #6
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r2, _08026E14 @ =0x00000714
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026DC6
	ldr r3, _08026E18 @ =0x000006EE
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
_08026DC6:
	ldr r0, _08026E1C @ =0x020314E0
	ldr r3, [r0]
	ldrh r4, [r3, #0x28]
	adds r2, r4, #0
	adds r5, r0, #0
	cmp r2, #0x82
	bne _08026E3A
	adds r0, r4, #1
	strh r0, [r3, #0x28]
	ldrh r1, [r3, #0x18]
	ldr r0, _08026E20 @ =0x000001E9
	cmp r1, r0
	bhi _08026E2C
	bl sub_2E094
	ldr r5, [r5]
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _08026DF8
	ldrh r1, [r5, #0x18]
	ldr r0, _08026E24 @ =0x000001AB
	cmp r1, r0
	bls _08026DF8
	adds r0, #1
	strh r0, [r5, #0x18]
_08026DF8:
	ldr r0, _08026E1C @ =0x020314E0
	ldr r3, [r0]
	ldrh r2, [r3, #0x18]
	movs r1, #0xc5
	lsls r1, r1, #1
	adds r5, r0, #0
	cmp r2, r1
	bne _08026E30
	movs r0, #1
	strb r0, [r3, #0x1c]
	ldr r1, [r5]
	ldr r0, _08026E28 @ =0x0007A120
	str r0, [r1, #0x3c]
	b _08026E30
	.align 2, 0
_08026E14: .4byte 0x00000714
_08026E18: .4byte 0x000006EE
_08026E1C: .4byte 0x020314E0
_08026E20: .4byte 0x000001E9
_08026E24: .4byte 0x000001AB
_08026E28: .4byte 0x0007A120
_08026E2C:
	movs r0, #0x78
	strh r0, [r3, #0x28]
_08026E30:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _08026E9E
_08026E3A:
	cmp r2, #0
	bne _08026E9E
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
	ldr r2, _08026E58 @ =0x0000062C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _08026E9E
	adds r0, #1
	strb r0, [r1]
	b _08026E9E
	.align 2, 0
_08026E58: .4byte 0x0000062C
_08026E5C:
	bl sub_219EC
	ldr r0, _08026E7C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r0, #0
	strh r0, [r1]
	bl sub_268CC
	ldr r0, _08026E80 @ =0x020314E0
	ldr r1, [r0]
_08026E72:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _08026E9E
	.align 2, 0
_08026E7C: .4byte gMain
_08026E80: .4byte 0x020314E0
_08026E84:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	adds r4, r0, #0
	cmp r4, #0
	beq _08026E94
	subs r0, #1
	strh r0, [r1, #0x18]
	b _08026E9E
_08026E94:
	movs r0, #1
	bl sub_19B64
	ldr r0, [r5]
	strb r4, [r0, #0x17]
_08026E9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_26EA4
sub_26EA4: @ 0x08026EA4
	push {r4, r5, r6, lr}
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08026EE0 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08026EE4 @ =0x000006C4
	adds r1, r1, r2
	movs r2, #0
	strb r2, [r1]
	adds r6, r0, #0
	ldr r5, _08026EE8 @ =0x0000071D
_08026EBE:
	ldr r0, _08026EE0 @ =0x020314E0
	ldr r3, [r0]
	ldr r0, _08026EEC @ =0x00000723
	adds r1, r3, r0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, #0
	cmp r2, r1
	bge _08026EF0
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _08026EF6
	.align 2, 0
_08026EE0: .4byte 0x020314E0
_08026EE4: .4byte 0x000006C4
_08026EE8: .4byte 0x0000071D
_08026EEC: .4byte 0x00000723
_08026EF0:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_08026EF6:
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08026EBE
	ldr r0, _08026F30 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	ldr r1, _08026F34 @ =0x000005F3
	adds r0, r0, r1
	strb r2, [r0]
	bl sub_4D648
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026F30: .4byte gMain
_08026F34: .4byte 0x000005F3

	thumb_func_start sub_26F38
sub_26F38: @ 0x08026F38
	push {r4, r5, r6, r7, lr}
	ldr r4, _08026F88 @ =0x020314E0
	ldr r0, [r4]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r0, [r4]
	movs r6, #0
	strh r3, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r5, [r4]
	adds r2, r5, #0
	adds r2, #0x6c
	movs r7, #0xe1
	lsls r7, r7, #5
	adds r0, r7, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	ldr r7, _08026F8C @ =0x00000296
	adds r1, r5, r7
	strh r0, [r1]
	strh r3, [r2]
	ldr r0, _08026F90 @ =0x00000724
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0xd
	bne _08026F94
	subs r7, #0x37
	adds r0, r5, r7
	strb r6, [r0]
	b _08026FFC
	.align 2, 0
_08026F88: .4byte 0x020314E0
_08026F8C: .4byte 0x00000296
_08026F90: .4byte 0x00000724
_08026F94:
	cmp r0, #0x58
	bne _08026FC4
	ldr r0, _08026FAC @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08026FB4
	ldr r0, _08026FB0 @ =0x0000025F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FAC: .4byte gMain
_08026FB0: .4byte 0x0000025F
_08026FB4:
	ldr r2, _08026FC0 @ =0x0000025F
	adds r1, r5, r2
	movs r0, #7
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FC0: .4byte 0x0000025F
_08026FC4:
	cmp r0, #0xaf
	bne _08026FD8
	ldr r7, _08026FD4 @ =0x0000025F
	adds r1, r5, r7
	movs r0, #3
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FD4: .4byte 0x0000025F
_08026FD8:
	ldr r2, _08027054 @ =0x086A3700
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #0x14]
	subs r0, #1
	ldr r2, _08027058 @ =0x0000025F
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08026FFC
	strb r6, [r1]
_08026FFC:
	ldr r1, _0802705C @ =0x040000D4
	ldr r0, _08027060 @ =0x081C0064
	str r0, [r1]
	ldr r0, _08027064 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08027068 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r4]
	ldr r1, _0802706C @ =0x0000072E
	adds r0, r0, r1
	movs r3, #0
	strb r3, [r0]
	ldr r0, [r4]
	ldr r2, _08027070 @ =0x0000072A
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r4]
	ldr r7, _08027074 @ =0x00000252
	adds r1, r0, r7
	movs r2, #0
	strh r3, [r1]
	ldr r1, _08027078 @ =0x0000025E
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r7, #0x19
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #0xe
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0802707C @ =0x0000026E
	adds r0, r0, r2
	strh r3, [r0]
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027054: .4byte 0x086A3700
_08027058: .4byte 0x0000025F
_0802705C: .4byte 0x040000D4
_08027060: .4byte 0x081C0064
_08027064: .4byte 0x05000180
_08027068: .4byte 0x80000010
_0802706C: .4byte 0x0000072E
_08027070: .4byte 0x0000072A
_08027074: .4byte 0x00000252
_08027078: .4byte 0x0000025E
_0802707C: .4byte 0x0000026E

	thumb_func_start sub_27080
sub_27080: @ 0x08027080
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080270E0 @ =0x020314E0
	ldr r1, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080270C0
	ldr r3, _080270E4 @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080270C0
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #7
	bgt _080270C0
	bl m4aMPlayAllStop
	movs r0, #0x13
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #8
	strb r1, [r0, #0x17]
_080270C0:
	ldr r1, _080270E0 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r1, #0
	cmp r0, #0xa
	bls _080270D4
	bl _080278E6
_080270D4:
	lsls r0, r0, #2
	ldr r1, _080270E8 @ =_080270EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080270E0: .4byte 0x020314E0
_080270E4: .4byte 0x00000296
_080270E8: .4byte _080270EC
_080270EC: @ jump table
	.4byte _08027118 @ case 0
	.4byte _08027390 @ case 1
	.4byte _08027414 @ case 2
	.4byte _08027424 @ case 3
	.4byte _08027452 @ case 4
	.4byte _08027474 @ case 5
	.4byte _080274B4 @ case 6
	.4byte _08027506 @ case 7
	.4byte _080277D8 @ case 8
	.4byte _0802789C @ case 9
	.4byte _080278B0 @ case 10
_08027118:
	ldr r0, [r6]
	movs r5, #0x94
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08027208
	movs r2, #0
	adds r3, r6, #0
	ldr r4, _080271F4 @ =0x00000263
_0802712C:
	ldr r1, [r3]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802712C
	bl sub_C00
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #5
	bl __umodsi3
	ldr r5, _080271FC @ =0x020314E0
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _080271F4 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	movs r6, #0x98
	lsls r6, r6, #2
	adds r2, r2, r6
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #6
	bgt _0802718E
	adds r3, r4, #0
_08027176:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #6
	ble _08027176
_0802718E:
	bl sub_C00
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r2, r0, r1
	movs r0, #3
	ands r2, r0
	ldr r4, _080271FC @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _080271F4 @ =0x00000263
	adds r0, r1, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r7, _08027200 @ =0x00000261
	adds r1, r1, r7
	strb r0, [r1]
	lsls r1, r2, #0x10
	cmp r2, #5
	bgt _080271CC
_080271B4:
	ldr r0, [r4]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #5
	ble _080271B4
_080271CC:
	bl sub_C00
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #3
	bl __umodsi3
	ldr r1, _080271FC @ =0x020314E0
	ldr r2, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, _080271F4 @ =0x00000263
	adds r1, r2, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	ldr r5, _08027204 @ =0x00000262
	adds r2, r2, r5
	strb r0, [r2]
	b _08027362
	.align 2, 0
_080271F4: .4byte 0x00000263
_080271F8: .4byte gMain
_080271FC: .4byte 0x020314E0
_08027200: .4byte 0x00000261
_08027204: .4byte 0x00000262
_08027208:
	movs r2, #0
	adds r3, r6, #0
	ldr r4, _08027378 @ =0x00000263
_0802720E:
	ldr r1, [r3]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802720E
	bl sub_C00
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	ldr r5, _08027380 @ =0x020314E0
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	movs r6, #0x98
	lsls r6, r6, #2
	adds r2, r2, r6
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #6
	bgt _08027270
	adds r3, r4, #0
_08027258:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #6
	ble _08027258
_08027270:
	bl sub_C00
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #7
	bl __umodsi3
	ldr r5, _08027380 @ =0x020314E0
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	ldr r7, _08027384 @ =0x00000261
	adds r2, r2, r7
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #5
	bgt _080272B8
	adds r3, r4, #0
_080272A0:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #5
	ble _080272A0
_080272B8:
	bl sub_C00
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	ldr r5, _08027380 @ =0x020314E0
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	ldr r3, _08027388 @ =0x00000262
	adds r2, r2, r3
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #4
	bgt _08027300
	adds r3, r4, #0
_080272E8:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #4
	ble _080272E8
_08027300:
	ldr r0, _0802737C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _08027362
	ldr r1, _08027380 @ =0x020314E0
	ldr r0, [r1]
	ldr r5, _0802738C @ =0x00000283
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08027362
	movs r2, #0
	adds r5, r1, #0
_0802731A:
	ldr r0, [r5]
	lsls r1, r2, #0x10
	asrs r4, r1, #0x10
	movs r6, #0x98
	lsls r6, r6, #2
	adds r0, r0, r6
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _08027356
	bl sub_C00
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #5
	bl __umodsi3
	ldr r1, [r5]
	adds r2, r1, r6
	adds r2, r2, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r7, _08027378 @ =0x00000263
	adds r1, r1, r7
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
_08027356:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0802731A
_08027362:
	ldr r0, _08027380 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_08027378: .4byte 0x00000263
_0802737C: .4byte gMain
_08027380: .4byte 0x020314E0
_08027384: .4byte 0x00000261
_08027388: .4byte 0x00000262
_0802738C: .4byte 0x00000283
_08027390:
	ldr r1, [r6]
	ldr r2, _080273FC @ =0x0000026B
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r1, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08027400 @ =0x0000025E
	adds r1, r1, r2
	strb r0, [r1]
	ldr r3, [r6]
	ldr r5, _08027404 @ =0x086ACFA0
	adds r2, r3, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #2
	ldr r4, _08027408 @ =gMain
	ldrb r0, [r4, #4]
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r3, r6
	strh r1, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	ldrb r1, [r4, #4]
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r1, [r0, #2]
	ldr r7, _0802740C @ =0x0000025A
	adds r0, r3, r7
	strh r1, [r0]
	ldr r0, _08027410 @ =0x0000026E
	adds r1, r3, r0
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0xa0
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	b _080278E6
	.align 2, 0
_080273FC: .4byte 0x0000026B
_08027400: .4byte 0x0000025E
_08027404: .4byte 0x086ACFA0
_08027408: .4byte gMain
_0802740C: .4byte 0x0000025A
_08027410: .4byte 0x0000026E
_08027414:
	bl sub_278F4
	ldr r0, _08027420 @ =0x020314E0
	ldr r1, [r0]
	b _080277B8
	.align 2, 0
_08027420: .4byte 0x020314E0
_08027424:
	ldr r0, [r6]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #7
	bhi _0802743A
	b _08027684
_0802743A:
	bl sub_219A8
	ldr r0, [r6]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
_08027452:
	bl sub_219EC
	ldr r0, _08027470 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802746A
	b _080278E6
_0802746A:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_08027470: .4byte 0x020314E0
_08027474:
	ldr r0, [r6]
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r6]
	movs r4, #0xb3
	lsls r4, r4, #3
	adds r1, r0, r4
	ldrh r1, [r1]
	movs r7, #0xb4
	lsls r7, r7, #3
	adds r0, r0, r7
	strh r1, [r0]
	movs r0, #1
	bl sub_31CF8
	ldr r1, [r6]
	adds r4, r1, r4
	ldrh r2, [r4]
	ldr r3, _080274B0 @ =0x000005A2
	adds r0, r1, r3
	strh r2, [r0]
	strh r5, [r1, #0x18]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_080274B0: .4byte 0x000005A2
_080274B4:
	ldr r1, [r6]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x94
	beq _080274BE
	b _080278E6
_080274BE:
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r0, _080274F0 @ =gMain
	movs r5, #0xc5
	lsls r5, r5, #4
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080274F4
	movs r7, #0xaf
	lsls r7, r7, #2
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0x4f
	bhi _080274DE
	b _080278E6
_080274DE:
	bl sub_2D204
	ldr r1, [r6]
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #6
	beq _080274EE
	b _080278E6
_080274EE:
	b _08027682
	.align 2, 0
_080274F0: .4byte gMain
_080274F4:
	bl sub_2D204
	ldr r1, [r6]
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #6
	beq _08027504
	b _080278E6
_08027504:
	b _08027682
_08027506:
	ldr r3, [r6]
	ldrh r0, [r3, #0x28]
	adds r1, r0, #0
	cmp r1, #0x94
	beq _08027512
	b _080276BA
_08027512:
	adds r0, #1
	strh r0, [r3, #0x28]
	ldrh r1, [r3, #0x18]
	ldr r0, _08027530 @ =0x00000117
	cmp r1, r0
	bls _08027520
	b _080276B4
_08027520:
	cmp r1, #0
	bne _08027534
	bl sub_2312C
	movs r0, #0x12
	bl m4aSongNumStart
	b _0802758E
	.align 2, 0
_08027530: .4byte 0x00000117
_08027534:
	bl sub_23300
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xe5
	bhi _08027550
	movs r0, #0x84
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0x96
	bne _08027550
	subs r0, #1
	strh r0, [r1]
_08027550:
	ldr r4, _0802768C @ =0x020314E0
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	movs r0, #0x87
	lsls r0, r0, #1
	cmp r1, r0
	bne _08027570
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	ldr r1, _08027690 @ =0x000006C4
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
_08027570:
	ldr r1, [r4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0802757C
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0802757C:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0802758E
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r4]
	ldr r0, _08027694 @ =0x004C4B40
	str r0, [r1, #0x3c]
_0802758E:
	ldr r0, _0802768C @ =0x020314E0
	ldr r2, [r0]
	ldrh r1, [r2, #0x18]
	adds r6, r0, #0
	cmp r1, #0x1d
	bhi _08027600
	ldr r1, _08027698 @ =gMain
	movs r0, #1
	strh r0, [r1, #0x2c]
	ldrh r1, [r2, #0x18]
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	movs r2, #0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r5, _0802769C @ =0x03005C00
	mov r8, r5
	cmp r2, r0
	bgt _080275F0
	adds r7, r0, #0
	movs r4, #0xc1
	lsls r4, r4, #8
_080275BE:
	movs r0, #2
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_080275C4:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xb
	ble _080275C4
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _080275BE
_080275F0:
	ldr r1, _080276A0 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _080276A4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _080276A8 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08027600:
	ldr r0, [r6]
	ldrh r0, [r0, #0x18]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _08027680
	movs r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, _0802769C @ =0x03005C00
	mov r8, r3
	cmp r2, r0
	bgt _08027654
	mov r5, r8
	ldr r4, _080276AC @ =0x000001FF
	adds r7, r0, #0
_08027622:
	movs r0, #2
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_08027628:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xb
	ble _08027628
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _08027622
_08027654:
	ldr r1, _080276A0 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _080276A4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _080276A8 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r6]
	ldrh r1, [r0, #0x18]
	ldr r0, _080276B0 @ =0x0000010D
	cmp r1, r0
	bne _08027680
	ldr r0, _08027698 @ =gMain
	movs r1, #0
	strh r1, [r0, #0x2c]
	ldrh r2, [r0, #0x38]
	strh r1, [r0, #0x38]
	ldrh r2, [r0, #0x3c]
	strh r1, [r0, #0x3c]
	ldrh r2, [r0, #0x3a]
	strh r1, [r0, #0x3a]
_08027680:
	ldr r1, [r6]
_08027682:
	ldrh r0, [r1, #0x18]
_08027684:
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080278E6
	.align 2, 0
_0802768C: .4byte 0x020314E0
_08027690: .4byte 0x000006C4
_08027694: .4byte 0x004C4B40
_08027698: .4byte gMain
_0802769C: .4byte 0x03005C00
_080276A0: .4byte 0x040000D4
_080276A4: .4byte 0x06002000
_080276A8: .4byte 0x80000400
_080276AC: .4byte 0x000001FF
_080276B0: .4byte 0x0000010D
_080276B4:
	movs r0, #0x28
	strh r0, [r3, #0x28]
	b _080278E6
_080276BA:
	cmp r1, #0x18
	beq _080276C0
	b _080278E6
_080276C0:
	ldr r5, _080277C0 @ =0x00000723
	adds r0, r3, r5
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027748
	ldr r2, _080277C4 @ =0x00000721
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, [r6]
	adds r1, r0, r5
	ldrb r1, [r1]
	ldr r3, _080277C8 @ =0x00000722
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	adds r2, r0, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldr r7, _080277CC @ =0x0000071D
	adds r0, r0, r7
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r6]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r3, #0x78
	strb r3, [r0]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r5
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027748
	adds r7, #5
	adds r0, r1, r7
	strb r2, [r0]
	ldr r0, [r6]
	adds r2, r7, #0
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r7, #5
	adds r0, r0, r7
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027748:
	ldr r2, [r6]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x2a
	bne _08027780
	adds r3, #0x58
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r5, _080277D0 @ =0x0000062B
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802776E
	adds r0, #1
	strb r0, [r1]
_0802776E:
	ldr r1, [r6]
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0xf
	bne _08027780
	ldr r7, _080277D4 @ =0x00000286
	adds r1, r1, r7
	movs r0, #0x5c
	strh r0, [r1]
_08027780:
	ldr r2, [r6]
	movs r0, #0xbe
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0802779E
	ldr r3, _080277D4 @ =0x00000286
	adds r1, r2, r3
	movs r0, #0x5c
	strh r0, [r1]
_0802779E:
	ldr r0, [r6]
	ldr r5, _080277D0 @ =0x0000062B
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080277AE
	adds r0, #1
	strb r0, [r1]
_080277AE:
	ldr r1, [r6]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, [r6]
_080277B8:
	movs r0, #0
	strh r0, [r1, #0x18]
	b _080278E6
	.align 2, 0
_080277C0: .4byte 0x00000723
_080277C4: .4byte 0x00000721
_080277C8: .4byte 0x00000722
_080277CC: .4byte 0x0000071D
_080277D0: .4byte 0x0000062B
_080277D4: .4byte 0x00000286
_080277D8:
	ldr r6, _0802787C @ =gMain
	ldr r0, [r6, #0x44]
	adds r0, #0x80
	ldr r4, [r0]
	movs r7, #8
	adds r7, r7, r4
	ldr r5, _08027880 @ =gOamBuffer
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	adds r1, r1, r5
	movs r0, #2
	ldrsh r2, [r7, r0]
	ldr r3, _08027884 @ =0x000001FF
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #2]
	ldr r0, _08027888 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	subs r0, #0x38
	movs r5, #0
	strb r0, [r1]
	ldr r0, [r6, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	movs r7, #0
	mov r8, r7
	strh r5, [r0]
	bl sub_278F4
	ldr r0, [r6, #0x44]
	adds r0, #0xa0
	ldr r0, [r0]
	strh r5, [r0]
	ldr r4, _0802788C @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0xe4
	mov r1, r8
	strb r1, [r0]
	bl sub_219EC
	ldr r0, [r6, #0x44]
	ldr r0, [r0, #0x34]
	strh r5, [r0]
	ldr r0, [r4]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	movs r3, #0xda
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r5, [r0]
	ldr r5, _08027890 @ =0x000001A5
	adds r0, r1, r5
	mov r6, r8
	strb r6, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r7, _08027894 @ =0x00000714
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080278E6
	ldr r0, _08027898 @ =0x000006EE
	adds r1, r1, r0
	movs r0, #0x78
	strh r0, [r1]
	b _080278E6
	.align 2, 0
_0802787C: .4byte gMain
_08027880: .4byte gOamBuffer
_08027884: .4byte 0x000001FF
_08027888: .4byte 0xFFFFFE00
_0802788C: .4byte 0x020314E0
_08027890: .4byte 0x000001A5
_08027894: .4byte 0x00000714
_08027898: .4byte 0x000006EE
_0802789C:
	bl sub_26EA4
	ldr r0, _080278AC @ =0x020314E0
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_080278AC: .4byte 0x020314E0
_080278B0:
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080278BE
	subs r0, #1
	strh r0, [r1, #0x18]
	b _080278E6
_080278BE:
	ldr r2, _080278D4 @ =0x0000071F
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080278D8
	movs r0, #3
	bl sub_19B64
	b _080278DE
	.align 2, 0
_080278D4: .4byte 0x0000071F
_080278D8:
	movs r0, #1
	bl sub_19B64
_080278DE:
	ldr r0, _080278F0 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0
_080278E4:
	strb r0, [r1, #0x17]
_080278E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080278F0: .4byte 0x020314E0

	thumb_func_start sub_278F4
sub_278F4: @ 0x080278F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080279C4 @ =gMain
	mov sl, r0
	ldr r0, [r0, #0x4c]
	movs r1, #0x4b
	bl __umodsi3
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sl
	ldr r2, [r1, #0x44]
	adds r0, r2, #0
	adds r0, #0x80
	ldr r7, [r0]
	ldr r6, _080279C8 @ =0x020314E0
	ldr r3, [r6]
	ldr r0, _080279CC @ =0x0000026E
	mov sb, r0
	adds r0, r3, r0
	ldrh r1, [r0]
	cmp r1, #0
	bne _08027932
	b _08027B74
_08027932:
	adds r0, r2, #0
	adds r0, #0xa0
	ldr r7, [r0]
	cmp r1, #0x50
	bne _0802798C
	adds r1, r3, #0
	adds r1, #0xe4
	movs r5, #0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _080279D0 @ =0x040000D4
	ldr r1, _080279D4 @ =0x086AD474
	ldr r3, [r6]
	ldr r0, _080279D8 @ =0x0000025F
	adds r4, r3, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _080279DC @ =0x06015800
	str r0, [r2, #4]
	ldr r0, _080279E0 @ =0x80000E00
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #5
	ldr r1, _080279E4 @ =0x0815C4C4
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080279E8 @ =0x050003E0
	str r0, [r2, #4]
	ldr r0, _080279EC @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _080279F0 @ =0x00000626
	adds r3, r3, r1
	strb r5, [r3]
	ldr r0, [r6]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r5, [r0]
_0802798C:
	ldr r0, [r6]
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0x3c
	bne _0802799E
	ldr r0, _080279F4 @ =0x02032F20
	ldr r1, _080279F8 @ =0x0869F58C
	bl MPlayStart
_0802799E:
	ldr r2, _080279FC @ =0x086AE0E6
	ldr r1, [r6]
	ldr r5, _080279F0 @ =0x00000626
	adds r3, r1, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r5, #2
	adds r1, r1, r5
	ldrh r2, [r1]
	cmp r0, r2
	ble _08027A00
	adds r0, r2, #1
	strh r0, [r1]
	b _08027A46
	.align 2, 0
_080279C4: .4byte gMain
_080279C8: .4byte 0x020314E0
_080279CC: .4byte 0x0000026E
_080279D0: .4byte 0x040000D4
_080279D4: .4byte 0x086AD474
_080279D8: .4byte 0x0000025F
_080279DC: .4byte 0x06015800
_080279E0: .4byte 0x80000E00
_080279E4: .4byte 0x0815C4C4
_080279E8: .4byte 0x050003E0
_080279EC: .4byte 0x80000010
_080279F0: .4byte 0x00000626
_080279F4: .4byte 0x02032F20
_080279F8: .4byte 0x0869F58C
_080279FC: .4byte 0x086AE0E6
_08027A00:
	movs r2, #1
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r6]
	ldr r3, _08027B48 @ =0x00000626
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x1d
	bne _08027A46
	movs r0, #0x1c
	strb r0, [r1]
	ldr r0, [r6]
	add r0, sb
	strh r2, [r0]
	mov r5, sl
	ldr r0, [r5, #0x44]
	adds r0, #0xa0
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, _08027B4C @ =0x02032F20
	ldr r1, _08027B50 @ =0x0869F5C8
	bl MPlayStart
	ldr r0, [r6]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_08027A46:
	ldr r3, _08027B54 @ =0x020314E0
	ldr r2, [r3]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r2, r6
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r0, #8
	strh r0, [r7, #2]
	ldr r1, _08027B58 @ =0x0000025A
	adds r0, r2, r1
	adds r2, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	adds r0, #8
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08027A7E
	ldr r0, _08027B5C @ =0x0000FFE2
	strh r0, [r7, #4]
_08027A7E:
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0xc8
	ble _08027A8A
	movs r0, #0xc8
	strh r0, [r7, #4]
_08027A8A:
	movs r0, #0
	ldr r3, _08027B60 @ =gOamBuffer
	mov sl, r3
	ldr r5, _08027B64 @ =0x086B4202
	mov sb, r5
	ldr r6, _08027B54 @ =0x020314E0
	mov r8, r6
	ldr r1, _08027B48 @ =0x00000626
	mov ip, r1
_08027A9C:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, sl
	lsls r3, r4, #1
	adds r3, r3, r4
	mov r5, r8
	ldr r0, [r5]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r5, r3, #1
	mov r1, r8
	ldr r0, [r1]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r3, #2
	mov r5, r8
	ldr r0, [r5]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, sl
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _08027B68 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldr r0, _08027B6C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r7, #4]
	ldrb r6, [r1]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #4
	ble _08027A9C
	ldr r0, _08027B54 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _08027B70 @ =0x0000026E
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08027CE8
	.align 2, 0
_08027B48: .4byte 0x00000626
_08027B4C: .4byte 0x02032F20
_08027B50: .4byte 0x0869F5C8
_08027B54: .4byte 0x020314E0
_08027B58: .4byte 0x0000025A
_08027B5C: .4byte 0x0000FFE2
_08027B60: .4byte gOamBuffer
_08027B64: .4byte 0x086B4202
_08027B68: .4byte 0x000001FF
_08027B6C: .4byte 0xFFFFFE00
_08027B70: .4byte 0x0000026E
_08027B74:
	ldr r6, _08027CF8 @ =0x0000132C
	adds r0, r3, r6
	ldr r2, [r0]
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	subs r0, #8
	movs r6, #0x96
	lsls r6, r6, #2
	adds r1, r3, r6
	movs r6, #0
	ldrsh r1, [r1, r6]
	subs r4, r0, r1
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	subs r0, #8
	ldr r2, _08027CFC @ =0x0000025A
	adds r1, r3, r2
	movs r6, #0
	ldrsh r1, [r1, r6]
	subs r5, r0, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	cmp r0, #0x51
	bgt _08027C38
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _08027BC4
	adds r2, #4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble _08027BD6
_08027BC4:
	cmp r1, #2
	bne _08027C38
	ldr r5, _08027D00 @ =0x0000025E
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble _08027C38
_08027BD6:
	ldr r4, _08027D04 @ =0x020314E0
	ldr r1, [r4]
	ldr r6, _08027D08 @ =0x0000026B
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027C38
	ldr r0, _08027D0C @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, _08027D10 @ =0x02032F20
	ldr r1, _08027D14 @ =0x0869F618
	bl MPlayStart
	ldr r1, [r4]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r3, _08027D18 @ =0x0000071D
	adds r0, r0, r3
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08027D1C @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r4]
	adds r2, r0, r6
	movs r1, #0
	ldrsb r1, [r2, r1]
	cmp r1, #3
	bne _08027C38
	movs r0, #0
	strb r0, [r2]
	ldr r0, [r4]
	strb r1, [r0, #0x17]
_08027C38:
	ldr r3, _08027D04 @ =0x020314E0
	ldr r2, [r3]
	movs r5, #0x96
	lsls r5, r5, #2
	adds r0, r2, r5
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	strh r0, [r7, #2]
	ldr r6, _08027CFC @ =0x0000025A
	adds r0, r2, r6
	adds r2, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	subs r0, #8
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08027C70
	ldr r0, _08027D20 @ =0x0000FFE2
	strh r0, [r7, #4]
_08027C70:
	movs r1, #4
	ldrsh r0, [r7, r1]
	cmp r0, #0xc8
	ble _08027C7C
	movs r0, #0xc8
	strh r0, [r7, #4]
_08027C7C:
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _08027C8A
	movs r5, #0xe
	mov r8, r5
_08027C8A:
	ldr r2, _08027D24 @ =0x040000D4
	ldr r1, _08027D28 @ =0x086AD49C
	ldr r0, [r3]
	ldr r6, _08027D2C @ =0x0000025F
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r1, r1, #7
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08027D30 @ =0x060116C0
	str r0, [r2, #4]
	ldr r0, _08027D34 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, r7, #0
	adds r6, #8
	ldr r4, _08027D38 @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r5, #2
	ldrsh r1, [r6, r5]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r5, _08027D3C @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08027D40 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
_08027CE8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027CF8: .4byte 0x0000132C
_08027CFC: .4byte 0x0000025A
_08027D00: .4byte 0x0000025E
_08027D04: .4byte 0x020314E0
_08027D08: .4byte 0x0000026B
_08027D0C: .4byte 0x00002710
_08027D10: .4byte 0x02032F20
_08027D14: .4byte 0x0869F618
_08027D18: .4byte 0x0000071D
_08027D1C: .4byte gMain
_08027D20: .4byte 0x0000FFE2
_08027D24: .4byte 0x040000D4
_08027D28: .4byte 0x086AD49C
_08027D2C: .4byte 0x0000025F
_08027D30: .4byte 0x060116C0
_08027D34: .4byte 0x80000100
_08027D38: .4byte gOamBuffer
_08027D3C: .4byte 0x000001FF
_08027D40: .4byte 0xFFFFFE00

	thumb_func_start sub_27D44
sub_27D44: @ 0x08027D44
	push {r4, r5, r6, lr}
	ldr r4, _08027DC8 @ =0x020314E0
	ldr r0, [r4]
	ldr r1, _08027DCC @ =0x000005A5
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08027DD0 @ =0x000005A9
	adds r0, r0, r2
	strb r1, [r0]
	ldr r2, _08027DD4 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x48]
	movs r5, #0
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x30]
	strh r1, [r0]
	ldr r0, [r4]
	ldr r1, _08027DD8 @ =0x000005F2
	adds r0, r0, r1
	strb r5, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	ldr r2, _08027DDC @ =0x000006C4
	adds r0, r0, r2
	strb r5, [r0]
	bl sub_4D648
	movs r2, #0
	ldr r5, _08027DE0 @ =0x000006D3
	movs r3, #0xd
	adds r6, r4, #0
_08027D8E:
	ldr r1, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r5
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08027D8E
	movs r2, #0
	ldr r5, _08027DE4 @ =0x0000071D
_08027DAA:
	ldr r3, [r6]
	ldr r1, _08027DE8 @ =0x00000723
	adds r0, r3, r1
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r2, r0
	bge _08027DEC
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _08027DF2
	.align 2, 0
_08027DC8: .4byte 0x020314E0
_08027DCC: .4byte 0x000005A5
_08027DD0: .4byte 0x000005A9
_08027DD4: .4byte gMain
_08027DD8: .4byte 0x000005F2
_08027DDC: .4byte 0x000006C4
_08027DE0: .4byte 0x000006D3
_08027DE4: .4byte 0x0000071D
_08027DE8: .4byte 0x00000723
_08027DEC:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_08027DF2:
	strb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r4, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08027DAA
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_27E08
sub_27E08: @ 0x08027E08
	push {r4, r5, r6, r7, lr}
	ldr r3, _08027E9C @ =0x020314E0
	ldr r0, [r3]
	movs r5, #0
	strb r5, [r0, #0x17]
	ldr r0, [r3]
	movs r6, #0
	strh r5, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r3]
	adds r4, r2, #0
	adds r4, #0x6c
	movs r7, #0xe1
	lsls r7, r7, #5
	adds r0, r7, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	ldr r7, _08027EA0 @ =0x00000296
	adds r1, r2, r7
	strh r0, [r1]
	strh r5, [r4]
	ldr r0, _08027EA4 @ =0x000005A5
	adds r2, r2, r0
	strb r6, [r2]
	ldr r0, [r3]
	ldr r2, _08027EA8 @ =0x000005AA
	adds r1, r0, r2
	strh r5, [r1]
	ldr r7, _08027EAC @ =0x000005A9
	adds r0, r0, r7
	strb r6, [r0]
	ldr r0, [r3]
	ldr r1, _08027EB0 @ =0x000006C6
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r3]
	ldr r2, _08027EB4 @ =0x000006C7
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r3]
	adds r7, #0x7c
	adds r0, r0, r7
	strb r6, [r0]
	ldr r0, [r3]
	adds r2, #3
	adds r1, r0, r2
	strh r5, [r1]
	adds r7, #0xa7
	adds r0, r0, r7
	strb r6, [r0]
	ldr r0, [r3]
	ldr r1, _08027EB8 @ =0x0000072F
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r3]
	adds r2, #0x67
	adds r0, r0, r2
	strb r6, [r0]
	ldr r1, [r3]
	ldr r7, _08027EBC @ =0x0000029A
	adds r0, r1, r7
	ldrh r0, [r0]
	adds r5, r3, #0
	cmp r0, #0
	bne _08027EC8
	ldr r0, _08027EC0 @ =0x00000724
	adds r1, r1, r0
	ldr r0, _08027EC4 @ =0x00001770
	b _08027ECE
	.align 2, 0
_08027E9C: .4byte 0x020314E0
_08027EA0: .4byte 0x00000296
_08027EA4: .4byte 0x000005A5
_08027EA8: .4byte 0x000005AA
_08027EAC: .4byte 0x000005A9
_08027EB0: .4byte 0x000006C6
_08027EB4: .4byte 0x000006C7
_08027EB8: .4byte 0x0000072F
_08027EBC: .4byte 0x0000029A
_08027EC0: .4byte 0x00000724
_08027EC4: .4byte 0x00001770
_08027EC8:
	ldr r2, _08027F6C @ =0x00000724
	adds r1, r1, r2
	ldr r0, _08027F70 @ =0x00001068
_08027ECE:
	strh r0, [r1]
	ldr r1, [r5]
	ldr r7, _08027F74 @ =0x0000029A
	adds r1, r1, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08027F78 @ =0x040000D4
	ldr r0, _08027F7C @ =0x081C0064
	str r0, [r1]
	ldr r0, _08027F80 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08027F84 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	ldr r6, _08027F88 @ =gMain
	adds r4, r5, #0
	ldr r3, _08027F8C @ =0x000006CD
_08027EF4:
	ldr r1, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r3
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08027EF4
	ldr r4, [r5]
	ldr r0, [r6, #0x4c]
	movs r1, #6
	bl __umodsi3
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r4, r4, r2
	strb r0, [r4]
	ldr r0, [r5]
	ldr r4, _08027F90 @ =0x000006C9
	adds r0, r0, r4
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r0, r4
	lsls r2, r1, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _08027F64
	adds r3, r5, #0
	ldr r5, _08027F8C @ =0x000006CD
_08027F42:
	ldr r0, [r3]
	asrs r1, r2, #0x10
	adds r0, r0, r5
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, [r3]
	adds r0, r0, r4
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08027F42
_08027F64:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027F6C: .4byte 0x00000724
_08027F70: .4byte 0x00001068
_08027F74: .4byte 0x0000029A
_08027F78: .4byte 0x040000D4
_08027F7C: .4byte 0x081C0064
_08027F80: .4byte 0x05000180
_08027F84: .4byte 0x80000010
_08027F88: .4byte gMain
_08027F8C: .4byte 0x000006CD
_08027F90: .4byte 0x000006C9

	thumb_func_start sub_27F94
sub_27F94: @ 0x08027F94
	push {r4, r5, lr}
	ldr r4, _08027FEC @ =0x020314E0
	ldr r1, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08027FD0
	ldr r3, _08027FF0 @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08027FD0
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #9
	bgt _08027FD0
	bl m4aMPlayAllStop
	movs r0, #0x13
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #0xa
	strb r1, [r0, #0x17]
_08027FD0:
	ldr r1, _08027FEC @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #0xc
	bls _08027FE2
	b _080283FA
_08027FE2:
	lsls r0, r0, #2
	ldr r1, _08027FF4 @ =_08027FF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027FEC: .4byte 0x020314E0
_08027FF0: .4byte 0x00000296
_08027FF4: .4byte _08027FF8
_08027FF8: @ jump table
	.4byte _0802802C @ case 0
	.4byte _08028040 @ case 1
	.4byte _08028074 @ case 2
	.4byte _08028094 @ case 3
	.4byte _080280E8 @ case 4
	.4byte _080281FC @ case 5
	.4byte _08028214 @ case 6
	.4byte _08028284 @ case 7
	.4byte _0802828A @ case 8
	.4byte _08028358 @ case 9
	.4byte _08028388 @ case 10
	.4byte _080283A0 @ case 11
	.4byte _080283B4 @ case 12
_0802802C:
	bl sub_31F6C
	ldr r0, _0802803C @ =0x020314E0
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080283F8
	.align 2, 0
_0802803C: .4byte 0x020314E0
_08028040:
	bl sub_3219C
	ldr r0, _0802806C @ =gMain
	ldrb r0, [r0, #2]
	cmp r0, #3
	beq _08028060
	ldr r0, _08028070 @ =0x020314E0
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #1
	bl sub_52BB0
_08028060:
	ldr r0, _08028070 @ =0x020314E0
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080283F8
	.align 2, 0
_0802806C: .4byte gMain
_08028070: .4byte 0x020314E0
_08028074:
	bl sub_28AE0
	ldr r2, _0802808C @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _08028090 @ =0x0000073D
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080283F8
	.align 2, 0
_0802808C: .4byte 0x020314E0
_08028090: .4byte 0x0000073D
_08028094:
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	ldr r2, _080280D8 @ =0x020314E0
	ldr r0, [r2]
	ldr r1, _080280DC @ =0x000006C5
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _080280E0 @ =0x00000602
	adds r0, r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	movs r3, #0
	ldr r5, _080280E4 @ =0x000006D3
	movs r4, #0xf
_080280BE:
	ldr r1, [r2]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r5
	adds r1, r1, r0
	strb r4, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _080280BE
	b _080283FA
	.align 2, 0
_080280D8: .4byte 0x020314E0
_080280DC: .4byte 0x000006C5
_080280E0: .4byte 0x00000602
_080280E4: .4byte 0x000006D3
_080280E8:
	ldr r4, _08028114 @ =gMain
	ldrb r1, [r4, #0xf]
	adds r3, r1, #0
	cmp r3, #0
	beq _080280F4
	b _080281F6
_080280F4:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _08028124
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x5e
	beq _0802812C
	cmp r0, #0x5d
	beq _08028136
	cmp r0, #0x49
	bne _08028118
	movs r0, #0x1d
	bl m4aSongNumStart
	b _080281F6
	.align 2, 0
_08028114: .4byte gMain
_08028118:
	cmp r0, #0x10
	bhi _080281F6
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r1, r2, r0
	b _080281EA
_08028124:
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x44
	bne _08028132
_0802812C:
	bl m4aMPlayAllStop
	b _080281F6
_08028132:
	cmp r0, #0x43
	bne _080281D4
_08028136:
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xf]
	adds r0, r2, #0
	adds r0, #0xea
	strh r3, [r0]
	adds r1, r2, #0
	adds r1, #0xec
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xe8
	strh r3, [r0]
	subs r0, #2
	strh r3, [r0]
	adds r0, #8
	strh r3, [r0]
	adds r1, #6
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0xfb
	strb r1, [r0]
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080281B4 @ =0x0000F63C
	strh r0, [r1]
	subs r1, #6
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	strh r3, [r0]
	ldr r1, _080281B8 @ =0x040000D4
	ldr r0, _080281BC @ =0x086ACEF8
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r0, _080281C0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080281C4 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080281C8 @ =0x086ACF18
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r0, _080281CC @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080281D0 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r4, #0x38]
	movs r0, #0xce
	strh r0, [r4, #0x38]
	b _080281F6
	.align 2, 0
_080281B4: .4byte 0x0000F63C
_080281B8: .4byte 0x040000D4
_080281BC: .4byte 0x086ACEF8
_080281C0: .4byte 0x06015800
_080281C4: .4byte 0x80001200
_080281C8: .4byte 0x086ACF18
_080281CC: .4byte 0x050003C0
_080281D0: .4byte 0x80000010
_080281D4:
	cmp r0, #0x2f
	bne _080281E0
	movs r0, #0x21
	bl m4aSongNumStart
	b _080281F6
_080281E0:
	cmp r0, #0
	bne _080281F6
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r1, r2, r3
_080281EA:
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
_080281F6:
	bl sub_29334
	b _080283FA
_080281FC:
	ldr r0, [r5]
	ldr r1, _08028210 @ =0x00000729
	adds r0, r0, r1
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	bl sub_29334
	b _08028262
	.align 2, 0
_08028210: .4byte 0x00000729
_08028214:
	ldr r0, [r5]
	ldr r2, _0802822C @ =0x00000729
	adds r0, r0, r2
	movs r4, #0
	strb r4, [r0]
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	bne _08028230
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080283FA
	.align 2, 0
_0802822C: .4byte 0x00000729
_08028230:
	adds r1, #0xe4
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _08028268 @ =0x040000D4
	ldr r0, _0802826C @ =0x0839C78C
	str r0, [r1]
	ldr r0, _08028270 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08028274 @ =0x80000A00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08028278 @ =0x0839DBAC
	str r0, [r1]
	ldr r0, _0802827C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08028280 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xa7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
_08028262:
	ldr r0, [r5]
	strh r4, [r0, #0x18]
	b _080283FA
	.align 2, 0
_08028268: .4byte 0x040000D4
_0802826C: .4byte 0x0839C78C
_08028270: .4byte 0x06015800
_08028274: .4byte 0x80000A00
_08028278: .4byte 0x0839DBAC
_0802827C: .4byte 0x050003C0
_08028280: .4byte 0x80000010
_08028284:
	bl sub_293D8
	b _080283FA
_0802828A:
	bl sub_29624
	ldr r0, _0802832C @ =0x040000D4
	ldr r1, _08028330 @ =0x086ACF80
	str r1, [r0]
	ldr r1, _08028334 @ =0x050003E0
	str r1, [r0, #4]
	ldr r2, _08028338 @ =0x80000010
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0802833C @ =0x020306D0
	str r1, [r0]
	ldr r1, _08028340 @ =0x050003A0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _08028344 @ =0x020314E0
	ldr r1, [r4]
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r2, r1, r3
	movs r3, #0
	movs r5, #0
	movs r0, #0x76
	strh r0, [r2]
	ldr r0, _08028348 @ =0x0000028A
	adds r2, r1, r0
	movs r0, #0x84
	lsls r0, r0, #1
	strh r0, [r2]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r1, r2
	strb r3, [r1]
	ldr r0, [r4]
	ldr r3, _0802834C @ =0x0000071D
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	subs r2, #2
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r3, #2
	adds r0, r0, r3
	strb r1, [r0]
	bl sub_28C90
	ldr r0, [r4]
	ldr r1, _08028350 @ =0x000005F2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r2, r1, r3
	movs r0, #0x8c
	strh r0, [r2]
	ldr r2, _08028354 @ =0x086A3700
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	bl sub_528DC
	ldr r0, [r4]
	strh r5, [r0, #0x18]
	b _080283FA
	.align 2, 0
_0802832C: .4byte 0x040000D4
_08028330: .4byte 0x086ACF80
_08028334: .4byte 0x050003E0
_08028338: .4byte 0x80000010
_0802833C: .4byte 0x020306D0
_08028340: .4byte 0x050003A0
_08028344: .4byte 0x020314E0
_08028348: .4byte 0x0000028A
_0802834C: .4byte 0x0000071D
_08028350: .4byte 0x000005F2
_08028354: .4byte 0x086A3700
_08028358:
	ldr r1, [r5]
	ldrh r2, [r1, #0x18]
	cmp r2, #0
	bne _0802836C
	adds r0, r1, #0
	adds r0, #0xec
	strh r2, [r0]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
_0802836C:
	bl sub_28C90
	ldr r0, [r5]
	ldr r2, _08028384 @ =0x000005AA
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080283FA
	subs r0, #1
	strh r0, [r1]
	b _080283FA
	.align 2, 0
_08028384: .4byte 0x000005AA
_08028388:
	bl sub_28E2C
	bl sub_2530C
	ldr r0, _0802839C @ =0x020314E0
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080283F8
	.align 2, 0
_0802839C: .4byte 0x020314E0
_080283A0:
	bl sub_27D44
	ldr r0, _080283B0 @ =0x020314E0
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080283F8
	.align 2, 0
_080283B0: .4byte 0x020314E0
_080283B4:
	ldr r0, [r5]
	ldr r3, _080283CC @ =0x00000729
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080283D0
	subs r0, #1
	strh r0, [r1, #0x18]
	b _080283FA
	.align 2, 0
_080283CC: .4byte 0x00000729
_080283D0:
	ldr r2, _080283E8 @ =0x0000071F
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080283EC
	movs r0, #3
	bl sub_19B64
	b _080283F2
	.align 2, 0
_080283E8: .4byte 0x0000071F
_080283EC:
	movs r0, #1
	bl sub_19B64
_080283F2:
	ldr r0, _08028400 @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0
_080283F8:
	strb r0, [r1, #0x17]
_080283FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028400: .4byte 0x020314E0

	thumb_func_start sub_28404
sub_28404: @ 0x08028404
	push {r4, r5, r6, r7, lr}
	ldr r5, _08028500 @ =0x020314E0
	ldr r0, [r5]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r0, [r5]
	movs r6, #0
	strh r3, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r5]
	adds r4, r2, #0
	adds r4, #0x6c
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r7, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	ldr r7, _08028504 @ =0x00000296
	adds r1, r2, r7
	strh r0, [r1]
	strh r3, [r4]
	ldr r0, _08028508 @ =0x000005A5
	adds r2, r2, r0
	strb r6, [r2]
	ldr r0, [r5]
	ldr r2, _0802850C @ =0x000005AA
	adds r1, r0, r2
	strh r3, [r1]
	ldr r7, _08028510 @ =0x000005A9
	adds r0, r0, r7
	strb r6, [r0]
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x7c
	strh r3, [r0]
	adds r1, r2, #0
	adds r1, #0x80
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08028514 @ =0x0000FA88
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x73
	strb r6, [r0]
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0xbc
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	ldr r2, _08028518 @ =0x0000072F
	adds r0, r1, r2
	strb r6, [r0]
	ldr r0, [r5]
	ldr r7, _0802851C @ =0x00000731
	adds r0, r0, r7
	strb r6, [r0]
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x74
	strh r3, [r0]
	adds r1, r2, #0
	adds r1, #0x76
	movs r0, #0xa
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x14
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08028520 @ =0x00000724
	adds r1, r2, r0
	ldr r0, _08028524 @ =0x00000CA8
	strh r0, [r1]
	ldr r1, _08028528 @ =0x00000714
	adds r0, r2, r1
	strb r6, [r0]
	ldr r0, [r5]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0802852C @ =0x00000711
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r7, #0x1f
	adds r0, r0, r7
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _08028530 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, _08028534 @ =0x040000D4
	ldr r0, _08028538 @ =0x081C0064
	str r0, [r1]
	ldr r0, _0802853C @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08028540 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028500: .4byte 0x020314E0
_08028504: .4byte 0x00000296
_08028508: .4byte 0x000005A5
_0802850C: .4byte 0x000005AA
_08028510: .4byte 0x000005A9
_08028514: .4byte 0x0000FA88
_08028518: .4byte 0x0000072F
_0802851C: .4byte 0x00000731
_08028520: .4byte 0x00000724
_08028524: .4byte 0x00000CA8
_08028528: .4byte 0x00000714
_0802852C: .4byte 0x00000711
_08028530: .4byte 0x00000713
_08028534: .4byte 0x040000D4
_08028538: .4byte 0x081C0064
_0802853C: .4byte 0x05000180
_08028540: .4byte 0x80000010

	thumb_func_start sub_28544
sub_28544: @ 0x08028544
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08028568 @ =0x020314E0
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r1
	cmp r0, #6
	bls _0802855C
	b _08028AD2
_0802855C:
	lsls r0, r0, #2
	ldr r1, _0802856C @ =_08028570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028568: .4byte 0x020314E0
_0802856C: .4byte _08028570
_08028570: @ jump table
	.4byte _0802858C @ case 0
	.4byte _080285A8 @ case 1
	.4byte _080286C8 @ case 2
	.4byte _080287E0 @ case 3
	.4byte _08028A2C @ case 4
	.4byte _08028A60 @ case 5
	.4byte _08028A88 @ case 6
_0802858C:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0xc8
	strh r1, [r0]
	bl sub_28AE0
	mov r3, r8
	ldr r1, [r3]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _08028AD0
_080285A8:
	ldr r4, _080285CC @ =gMain
	ldrb r1, [r4, #0xf]
	adds r3, r1, #0
	cmp r3, #0
	bne _0802869E
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080285D0
	mov r5, r8
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x5e
	beq _080285DA
	cmp r0, #0x5d
	beq _080285E4
	cmp r0, #0x49
	beq _08028688
	b _08028690
	.align 2, 0
_080285CC: .4byte gMain
_080285D0:
	mov r5, r8
	ldr r2, [r5]
	ldrh r0, [r2, #0x28]
	cmp r0, #0x44
	bne _080285E0
_080285DA:
	bl m4aMPlayAllStop
	b _08028AD2
_080285E0:
	cmp r0, #0x43
	bne _08028684
_080285E4:
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xf]
	adds r0, r2, #0
	adds r0, #0xea
	strh r3, [r0]
	adds r1, r2, #0
	adds r1, #0xec
	movs r0, #0x78
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xe8
	strh r3, [r0]
	subs r0, #2
	strh r3, [r0]
	adds r0, #8
	strh r3, [r0]
	adds r1, #6
	movs r0, #5
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xfb
	strb r1, [r0]
	ldr r2, [r2]
	adds r1, r2, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08028664 @ =0x0000F63C
	strh r0, [r1]
	subs r1, #6
	movs r0, #0x32
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	strh r3, [r0]
	ldr r1, _08028668 @ =0x040000D4
	ldr r0, _0802866C @ =0x086ACEF8
	ldr r0, [r0, #0x14]
	str r0, [r1]
	ldr r0, _08028670 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08028674 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08028678 @ =0x086ACF18
	ldr r0, [r0, #0x14]
	str r0, [r1]
	ldr r0, _0802867C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08028680 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r4, #0x38]
	movs r0, #0xce
	strh r0, [r4, #0x38]
	b _08028AD2
	.align 2, 0
_08028664: .4byte 0x0000F63C
_08028668: .4byte 0x040000D4
_0802866C: .4byte 0x086ACEF8
_08028670: .4byte 0x06015800
_08028674: .4byte 0x80001200
_08028678: .4byte 0x086ACF18
_0802867C: .4byte 0x050003C0
_08028680: .4byte 0x80000010
_08028684:
	cmp r0, #0x2f
	bne _08028690
_08028688:
	movs r0, #0x2f
	bl m4aSongNumStart
	b _08028AD2
_08028690:
	cmp r0, #0x28
	beq _08028696
	b _08028AD2
_08028696:
	ldrb r0, [r2, #0x17]
	adds r0, #1
	strb r0, [r2, #0x17]
	b _08028AD2
_0802869E:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080286A8
	b _08028AD2
_080286A8:
	mov r3, r8
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #1
	beq _080286B8
	b _08028AD2
_080286B8:
	ldr r4, _080286C4 @ =0x000006C4
	adds r1, r1, r4
	movs r0, #3
	strb r0, [r1]
	b _08028AD2
	.align 2, 0
_080286C4: .4byte 0x000006C4
_080286C8:
	ldr r2, _080287A4 @ =0x040000D4
	ldr r0, _080287A8 @ =0x086ACF80
	str r0, [r2]
	ldr r0, _080287AC @ =0x050003E0
	str r0, [r2, #4]
	ldr r1, _080287B0 @ =0x80000010
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _080287B4 @ =0x020306D0
	str r0, [r2]
	ldr r0, _080287B8 @ =0x050003A0
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, r8
	ldr r0, [r5]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r5]
	ldr r3, _080287BC @ =0x0000071D
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r5, _080287C0 @ =0x0000071E
	adds r0, r0, r5
	strb r1, [r0]
	mov r3, r8
	ldr r0, [r3]
	adds r5, #1
	adds r0, r0, r5
	strb r1, [r0]
	ldr r0, [r3]
	ldr r1, _080287C4 @ =0x000005F2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080287C8 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x84
	ldr r0, [r0]
	movs r3, #0
	strh r1, [r0]
	ldr r0, _080287CC @ =0x02030760
	str r0, [r2]
	ldr r0, _080287D0 @ =0x06010CA0
	str r0, [r2, #4]
	ldr r0, _080287D4 @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, r8
	ldr r2, [r5]
	movs r0, #0x28
	strh r0, [r2, #0x28]
	adds r1, r2, #0
	adds r1, #0x80
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080287D8 @ =0x0000FA88
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x73
	strb r3, [r0]
	ldr r3, [r5]
	ldr r2, _080287DC @ =0x086AE124
	adds r5, r3, #0
	adds r5, #0x73
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xbc
	strh r1, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r1, r3, #0
	adds r1, #0xbe
	strh r0, [r1]
	strh r4, [r3, #0x18]
	movs r0, #0xa2
	lsls r0, r0, #1
	bl m4aSongNumStart
	mov r0, r8
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, #0
	adds r0, #0x80
	ldrh r1, [r0]
	adds r0, #0x40
	strh r1, [r0]
	subs r0, #0x3e
	ldrh r1, [r0]
	adds r0, #0x40
	strh r1, [r0]
	b _08028AD2
	.align 2, 0
_080287A4: .4byte 0x040000D4
_080287A8: .4byte 0x086ACF80
_080287AC: .4byte 0x050003E0
_080287B0: .4byte 0x80000010
_080287B4: .4byte 0x020306D0
_080287B8: .4byte 0x050003A0
_080287BC: .4byte 0x0000071D
_080287C0: .4byte 0x0000071E
_080287C4: .4byte 0x000005F2
_080287C8: .4byte gMain
_080287CC: .4byte 0x02030760
_080287D0: .4byte 0x06010CA0
_080287D4: .4byte 0x80000240
_080287D8: .4byte 0x0000FA88
_080287DC: .4byte 0x086AE124
_080287E0:
	ldr r4, _08028824 @ =0x020314E0
	mov r8, r4
	ldr r4, [r4]
	ldr r5, _08028828 @ =0x000005A4
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #2
	bne _08028830
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x76
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r2, _0802882C @ =0x0000028A
	adds r1, r4, r2
	strh r0, [r1]
	b _08028974
	.align 2, 0
_08028824: .4byte 0x020314E0
_08028828: .4byte 0x000005A4
_0802882C: .4byte 0x0000028A
_08028830:
	adds r0, r4, #0
	adds r0, #0xbc
	movs r5, #0
	ldrsh r1, [r0, r5]
	subs r0, #0x3c
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xbe
	movs r5, #0
	ldrsh r1, [r0, r5]
	subs r0, #0x3c
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r3, r1, r0
	adds r4, r2, #0
	muls r4, r2, r4
	adds r0, r3, #0
	muls r0, r3, r0
	adds r4, r4, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r3, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0802888C @ =0x000009C3
	cmp r4, r0
	bgt _080288E8
	movs r6, #0
	movs r7, #0
	mov r5, r8
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	cmp r0, #0xc7
	bhi _08028890
	adds r0, #1
	strh r0, [r1]
	b _08028918
	.align 2, 0
_0802888C: .4byte 0x000009C3
_08028890:
	movs r0, #0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x73
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xa
	bgt _080288A6
	adds r0, r2, #1
	b _080288A8
_080288A6:
	movs r0, #0
_080288A8:
	strb r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #1
	bl m4aSongNumStart
	ldr r0, _080288E0 @ =0x020314E0
	ldr r3, [r0]
	ldr r2, _080288E4 @ =0x086AE124
	adds r4, r3, #0
	adds r4, #0x73
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xbc
	strh r1, [r0]
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r0, r3, #0
	adds r0, #0xbe
	strh r1, [r0]
	b _08028918
	.align 2, 0
_080288E0: .4byte 0x020314E0
_080288E4: .4byte 0x086AE124
_080288E8:
	adds r0, r5, #0
	bl sub_C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r4, _08028A0C @ =0x00004E20
	adds r0, r1, #0
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r5, #0
	bl sub_C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r4, #0
	bl __divsi3
	adds r7, r0, #0
_08028918:
	ldr r5, _08028A10 @ =0x020314E0
	ldr r0, [r5]
	mov r8, r0
	mov r4, r8
	adds r4, #0x80
	ldrh r0, [r4]
	adds r0, r6, r0
	strh r0, [r4]
	mov r1, r8
	adds r1, #0x82
	ldrh r0, [r1]
	adds r0, r7, r0
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #0x18]
	movs r1, #0x50
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0x50
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r4]
	mov r1, r8
	adds r1, #0xc0
	strh r2, [r1]
	bl sub_C24
	adds r1, r0, #0
	ldr r4, [r5]
	adds r5, r4, #0
	adds r5, #0x82
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08028A0C @ =0x00004E20
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r1, r0
	adds r4, #0xc2
	strh r1, [r4]
_08028974:
	ldr r0, _08028A10 @ =0x020314E0
	ldr r1, [r0]
	ldrh r2, [r1, #0x18]
	ldr r3, _08028A14 @ =0x000001F3
	mov r8, r0
	cmp r2, r3
	bhi _08028994
	movs r0, #0x28
	strh r0, [r1, #0x28]
	cmp r2, r3
	bne _08028994
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r0, #2
	strb r0, [r1]
_08028994:
	mov r3, r8
	ldr r0, [r3]
	ldrh r1, [r0, #0x18]
	adds r1, #1
	strh r1, [r0, #0x18]
	bl sub_28EA0
	mov r4, r8
	ldr r0, [r4]
	ldr r5, _08028A18 @ =0x000005AA
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080289B4
	subs r0, #1
	strh r0, [r1]
_080289B4:
	mov r0, r8
	ldr r1, [r0]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080289CA
	b _08028AD2
_080289CA:
	ldr r3, _08028A1C @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bls _080289D6
	b _08028AD2
_080289D6:
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #4
	ble _080289E0
	b _08028AD2
_080289E0:
	bl m4aMPlayAllStop
	movs r0, #0x13
	bl m4aSongNumStart
	mov r4, r8
	ldr r1, [r4]
	movs r0, #4
	strb r0, [r1, #0x17]
	ldr r0, [r4]
	movs r1, #0x96
	strh r1, [r0, #0x18]
	ldr r5, _08028A20 @ =0x000005F2
	adds r0, r0, r5
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08028A24 @ =0x02032F20
	ldr r1, _08028A28 @ =0x0869F58C
	bl MPlayStart
	b _08028AD2
	.align 2, 0
_08028A0C: .4byte 0x00004E20
_08028A10: .4byte 0x020314E0
_08028A14: .4byte 0x000001F3
_08028A18: .4byte 0x000005AA
_08028A1C: .4byte 0x00000296
_08028A20: .4byte 0x000005F2
_08028A24: .4byte 0x02032F20
_08028A28: .4byte 0x0869F58C
_08028A2C:
	mov r0, r8
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08028A3C
	subs r0, #1
	strh r0, [r1, #0x18]
	b _08028A40
_08028A3C:
	movs r0, #5
	strb r0, [r1, #0x17]
_08028A40:
	bl sub_28EA0
	ldr r0, _08028A58 @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08028A5C @ =0x000005AA
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08028AD2
	subs r0, #1
	strh r0, [r1]
	b _08028AD2
	.align 2, 0
_08028A58: .4byte 0x020314E0
_08028A5C: .4byte 0x000005AA
_08028A60:
	bl sub_28EA0
	bl sub_292A0
	bl sub_27D44
	ldr r2, _08028A84 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x72
	movs r3, #0
	movs r1, #0xf0
	strb r1, [r0]
	ldr r1, [r2]
	movs r0, #6
	strb r0, [r1, #0x17]
	ldr r0, [r2]
	strh r3, [r0, #0x18]
	b _08028AD2
	.align 2, 0
_08028A84: .4byte 0x020314E0
_08028A88:
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _08028AA4 @ =0x00000729
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08028AA8
	subs r0, #1
	strh r0, [r1, #0x18]
	b _08028AD2
	.align 2, 0
_08028AA4: .4byte 0x00000729
_08028AA8:
	ldr r5, _08028AC0 @ =0x0000071F
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08028AC4
	movs r0, #3
	bl sub_19B64
	b _08028ACA
	.align 2, 0
_08028AC0: .4byte 0x0000071F
_08028AC4:
	movs r0, #1
	bl sub_19B64
_08028ACA:
	ldr r0, _08028ADC @ =0x020314E0
	ldr r1, [r0]
	movs r0, #0
_08028AD0:
	strb r0, [r1, #0x17]
_08028AD2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028ADC: .4byte 0x020314E0

	thumb_func_start sub_28AE0
sub_28AE0: @ 0x08028AE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r2, _08028BD4 @ =0x086A3700
	ldr r0, _08028BD8 @ =0x020314E0
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r7, #0
	ldr r6, _08028BDC @ =0x086BB6F4
	add r3, sp, #0xc
	mov r8, r3
	ldr r4, _08028BE0 @ =0x02030760
	mov sl, r4
	ldr r1, _08028BE4 @ =0x020306D0
	mov sb, r1
	ldrb r5, [r0, #0x11]
	adds r0, r5, #0
	movs r1, #5
	bl __divsi3
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #5
	bl __modsi3
	lsls r4, r4, #0x10
	asrs r4, r4, #0xe
	adds r6, r4, r6
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	ldr r6, [r6]
	mov ip, r6
	ldr r3, _08028BE8 @ =0x086B15B4
	adds r4, r4, r3
	ldr r6, [r4]
_08028B3A:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #2
	mov r0, sp
	adds r4, r0, r2
	lsls r1, r5, #1
	adds r1, r1, r5
	adds r1, r3, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, ip
	str r0, [r4]
	mov r1, r8
	adds r0, r1, r2
	adds r2, r2, r3
	adds r2, r2, r5
	lsls r2, r2, #5
	adds r2, r6, r2
	str r2, [r0]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _08028B3A
	movs r7, #0
	ldr r3, _08028BEC @ =0x040000D4
_08028B72:
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #2
	mov r4, sp
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r3]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, sl
	str r0, [r3, #4]
	ldr r0, _08028BF0 @ =0x80000240
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	add r2, r8
	ldr r0, [r2]
	str r0, [r3]
	lsls r0, r1, #5
	add r0, sb
	str r0, [r3, #4]
	ldr r2, _08028BF4 @ =0x80000010
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _08028B72
	ldr r0, _08028BEC @ =0x040000D4
	ldr r3, _08028BE8 @ =0x086B15B4
	ldr r1, [r3]
	movs r4, #0xf0
	lsls r4, r4, #1
	adds r1, r1, r4
	str r1, [r0]
	ldr r1, _08028BF8 @ =0x02030730
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028BD4: .4byte 0x086A3700
_08028BD8: .4byte 0x020314E0
_08028BDC: .4byte 0x086BB6F4
_08028BE0: .4byte 0x02030760
_08028BE4: .4byte 0x020306D0
_08028BE8: .4byte 0x086B15B4
_08028BEC: .4byte 0x040000D4
_08028BF0: .4byte 0x80000240
_08028BF4: .4byte 0x80000010
_08028BF8: .4byte 0x02030730

	thumb_func_start sub_28BFC
sub_28BFC: @ 0x08028BFC
	push {r4, r5, r6, lr}
	ldr r2, _08028C6C @ =0x086A3700
	ldr r0, _08028C70 @ =0x020314E0
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r5, _08028C74 @ =gMonHatchSpriteGroupGfx
	ldrb r6, [r0, #0x12]
	adds r0, r6, #0
	movs r1, #6
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0xe
	adds r5, r4, r5
	adds r0, r6, #0
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	ldr r2, [r5]
	adds r2, r2, r1
	ldr r1, _08028C78 @ =gMonHatchSpriteGroupPals
	adds r4, r4, r1
	lsls r0, r0, #5
	ldr r3, [r4]
	adds r3, r3, r0
	ldr r0, _08028C7C @ =0x040000D4
	str r2, [r0]
	ldr r1, _08028C80 @ =0x0202C7A0
	str r1, [r0, #4]
	ldr r1, _08028C84 @ =0x80000870
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _08028C88 @ =0x020315D0
	str r1, [r0, #4]
	ldr r1, _08028C8C @ =0x80000010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028C6C: .4byte 0x086A3700
_08028C70: .4byte 0x020314E0
_08028C74: .4byte gMonHatchSpriteGroupGfx
_08028C78: .4byte gMonHatchSpriteGroupPals
_08028C7C: .4byte 0x040000D4
_08028C80: .4byte 0x0202C7A0
_08028C84: .4byte 0x80000870
_08028C88: .4byte 0x020315D0
_08028C8C: .4byte 0x80000010

	thumb_func_start sub_28C90
sub_28C90: @ 0x08028C90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08028D30 @ =gMain
	ldr r0, [r4, #0x50]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r4, #0x44]
	adds r0, #0x84
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08028CBA
	b _08028E02
_08028CBA:
	ldr r3, _08028D34 @ =0x020314E0
	ldr r4, [r3]
	adds r1, r4, #0
	adds r1, #0xc4
	movs r2, #0x60
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc6
	movs r1, #0x90
	lsls r1, r1, #1
	strh r1, [r0]
	subs r0, #0x6e
	ldrh r0, [r0]
	subs r2, r2, r0
	strh r2, [r6, #2]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r6, #4]
	ldr r1, _08028D38 @ =0x000005A9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _08028D50
	cmp r0, #0x14
	beq _08028CF6
	cmp r0, #0xc8
	bne _08028D06
_08028CF6:
	ldr r1, _08028D3C @ =0x040000D4
	ldr r0, _08028D40 @ =0x02031060
	str r0, [r1]
	ldr r0, _08028D44 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _08028D48 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08028D06:
	ldr r0, [r3]
	ldr r2, _08028D38 @ =0x000005A9
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _08028D22
	ldr r1, _08028D3C @ =0x040000D4
	ldr r0, _08028D4C @ =0x02030760
	str r0, [r1]
	ldr r0, _08028D44 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _08028D48 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08028D22:
	ldr r1, [r3]
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08028D78
	.align 2, 0
_08028D30: .4byte gMain
_08028D34: .4byte 0x020314E0
_08028D38: .4byte 0x000005A9
_08028D3C: .4byte 0x040000D4
_08028D40: .4byte 0x02031060
_08028D44: .4byte 0x06010CA0
_08028D48: .4byte 0x80000240
_08028D4C: .4byte 0x02030760
_08028D50:
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08028D78
	ldr r2, _08028E10 @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08028E14 @ =0x02030760
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08028E18 @ =0x06010CA0
	str r0, [r2, #4]
	ldr r0, _08028E1C @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08028D78:
	ldr r0, [r3]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	cmp r0, #0xc
	bgt _08028D8E
	movs r1, #2
_08028D8E:
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0xc7
	ble _08028D9A
	movs r0, #0xc8
	strh r0, [r6, #4]
_08028D9A:
	movs r0, #0
	ldr r7, _08028E20 @ =gOamBuffer
	ldr r2, _08028E24 @ =0xFFFFFE00
	mov sb, r2
	lsls r1, r1, #2
	mov ip, r1
	movs r1, #0xd
	rsbs r1, r1, #0
	mov r8, r1
_08028DAC:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08028E28 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r2, [r3, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, r8
	ands r0, r2
	mov r2, ip
	orrs r0, r2
	strb r0, [r1, #5]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _08028DAC
_08028E02:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028E10: .4byte 0x040000D4
_08028E14: .4byte 0x02030760
_08028E18: .4byte 0x06010CA0
_08028E1C: .4byte 0x80000240
_08028E20: .4byte gOamBuffer
_08028E24: .4byte 0xFFFFFE00
_08028E28: .4byte 0x000001FF

	thumb_func_start sub_28E2C
sub_28E2C: @ 0x08028E2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08028E94 @ =gMain
	ldr r1, [r0, #0x44]
	adds r1, #0x84
	ldr r5, [r1]
	ldrh r1, [r5]
	mov r8, r0
	cmp r1, #0
	beq _08028E7C
	movs r0, #0
	ldr r6, _08028E98 @ =gOamBuffer
	ldr r1, _08028E9C @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08028E4C:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r4, r2, #3
	adds r4, #8
	adds r4, r5, r4
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _08028E4C
_08028E7C:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028E94: .4byte gMain
_08028E98: .4byte gOamBuffer
_08028E9C: .4byte 0xFFFFFE00

	thumb_func_start sub_28EA0
sub_28EA0: @ 0x08028EA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08028F64 @ =gMain
	ldr r0, [r4, #0x50]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r0, [r4, #0x44]
	adds r0, #0x84
	ldr r7, [r0]
	ldrh r0, [r7]
	ldr r1, _08028F68 @ =0x020314E0
	mov sl, r1
	cmp r0, #0
	bne _08028ED4
	b _080290C4
_08028ED4:
	ldr r6, [r1]
	adds r4, r6, #0
	adds r4, #0xc0
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0xc4
	strh r0, [r1]
	movs r0, #0xc2
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	movs r2, #0x90
	lsls r2, r2, #1
	adds r5, r2, #0
	adds r0, r0, r5
	adds r1, r6, #0
	adds r1, #0xc6
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, r0, r5
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	cmp r0, #3
	ble _08028F7A
	ldrh r0, [r6, #0x18]
	cmp r0, #0x59
	bls _08028F74
	adds r1, r0, #0
	movs r0, #0x96
	subs r0, r0, r1
	cmp r0, #0
	bge _08028F52
	adds r0, #3
_08028F52:
	lsls r1, r0, #0xe
	ldr r2, _08028F6C @ =0x040000D4
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08028F70 @ =0x0844AA0C
	b _08028FFC
	.align 2, 0
_08028F64: .4byte gMain
_08028F68: .4byte 0x020314E0
_08028F6C: .4byte 0x040000D4
_08028F70: .4byte 0x0844AA0C
_08028F74:
	movs r0, #0xbe
	strh r0, [r7, #4]
	b _0802900A
_08028F7A:
	ldr r2, _08028FC8 @ =0x000005A9
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _08028FE0
	cmp r0, #0x14
	beq _08028F8C
	cmp r0, #0xc8
	bne _08028F9C
_08028F8C:
	ldr r1, _08028FCC @ =0x040000D4
	ldr r0, _08028FD0 @ =0x02031060
	str r0, [r1]
	ldr r0, _08028FD4 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _08028FD8 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08028F9C:
	mov r6, sl
	ldr r0, [r6]
	ldr r2, _08028FC8 @ =0x000005A9
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _08028FBA
	ldr r1, _08028FCC @ =0x040000D4
	ldr r0, _08028FDC @ =0x02030760
	str r0, [r1]
	ldr r0, _08028FD4 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _08028FD8 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08028FBA:
	mov r0, sl
	ldr r1, [r0]
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0802900A
	.align 2, 0
_08028FC8: .4byte 0x000005A9
_08028FCC: .4byte 0x040000D4
_08028FD0: .4byte 0x02031060
_08028FD4: .4byte 0x06010CA0
_08028FD8: .4byte 0x80000240
_08028FDC: .4byte 0x02030760
_08028FE0:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _0802900A
	ldr r2, _0802901C @ =0x040000D4
	mov r6, sb
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08029020 @ =0x02030760
_08028FFC:
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08029024 @ =0x06010CA0
	str r0, [r2, #4]
	ldr r0, _08029028 @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0802900A:
	mov r0, sl
	ldr r1, [r0]
	ldr r2, _0802902C @ =0x000005A4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08029030
	movs r3, #1
	b _08029044
	.align 2, 0
_0802901C: .4byte 0x040000D4
_08029020: .4byte 0x02030760
_08029024: .4byte 0x06010CA0
_08029028: .4byte 0x80000240
_0802902C: .4byte 0x000005A4
_08029030:
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r3, #1
	cmp r0, #0xc
	bgt _08029044
	movs r3, #2
_08029044:
	movs r1, #4
	ldrsh r0, [r7, r1]
	cmp r0, #0xc7
	ble _08029052
	movs r0, #0xc8
	strh r0, [r7, #4]
	b _0802905C
_08029052:
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0802905C
	strh r1, [r7, #4]
_0802905C:
	movs r2, #0
	ldr r6, _0802912C @ =gOamBuffer
	ldr r0, _08029130 @ =0xFFFFFE00
	mov sl, r0
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
_0802906E:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08029134 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r5, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sb
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1, #5]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0802906E
_080290C4:
	movs r1, #0
_080290C6:
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	ldr r6, _08029138 @ =gMain
	ldr r1, [r6, #0x44]
	lsls r4, r5, #2
	adds r1, r4, r1
	adds r1, #0xb4
	ldr r7, [r1]
	ldrh r1, [r7]
	mov r8, r0
	cmp r1, #0
	beq _080291D2
	ldr r0, _0802913C @ =0x020314E0
	ldr r2, [r0]
	adds r3, r2, r4
	adds r0, r3, #0
	adds r0, #0x84
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	adds r3, #0x86
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r3, [r3]
	ldrh r0, [r0]
	subs r3, r3, r0
	strh r3, [r7, #4]
	lsls r0, r5, #1
	adds r2, #0x74
	adds r2, r2, r0
	ldrh r0, [r2]
	lsrs r0, r0, #2
	movs r1, #9
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r0, r4, r5
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _08029140 @ =0x086AE154
	adds r1, r1, r2
	ldrh r1, [r1]
	lsls r3, r3, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0xc7
	ble _08029144
	movs r0, #0xc8
	strh r0, [r7, #4]
	b _0802914E
	.align 2, 0
_0802912C: .4byte gOamBuffer
_08029130: .4byte 0xFFFFFE00
_08029134: .4byte 0x000001FF
_08029138: .4byte gMain
_0802913C: .4byte 0x020314E0
_08029140: .4byte 0x086AE154
_08029144:
	movs r2, #0x3c
	rsbs r2, r2, #0
	cmp r0, r2
	bge _0802914E
	strh r2, [r7, #4]
_0802914E:
	movs r2, #0
	lsls r1, r1, #0x10
	ldr r6, _08029284 @ =0x086B263C
	mov sl, r6
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #1
	mov ip, r0
	ldr r0, _08029288 @ =0xFFFFFE00
	mov sb, r0
_08029164:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r1, _0802928C @ =gOamBuffer
	adds r2, r2, r1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r6, _0802928C @ =gOamBuffer
	adds r2, r2, r6
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	str r1, [sp]
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r6, [sp]
	adds r1, r6, r0
	ldr r6, _08029290 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	ldr r0, _0802928C @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _08029164
_080291D2:
	ldr r6, _08029294 @ =0x020314E0
	ldr r4, [r6]
	ldr r1, _08029298 @ =0x000005A4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08029228
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bgt _08029228
	mov r2, r8
	asrs r3, r2, #0x10
	lsls r0, r3, #1
	adds r1, r4, #0
	adds r1, #0x74
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0802923A
	movs r0, #0x28
	strh r0, [r1]
	lsls r3, r3, #2
	adds r2, r4, r3
	adds r0, r4, #0
	adds r0, #0xc4
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x84
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	adds r0, #0x10
	adds r2, #0x86
	strh r0, [r2]
	ldr r6, _0802929C @ =gMain
	ldr r0, [r6, #0x44]
	adds r3, r3, r0
	adds r3, #0xb4
	ldr r1, [r3]
	movs r0, #1
	strh r0, [r1]
_08029228:
	ldr r1, _08029294 @ =0x020314E0
	ldr r0, [r1]
	mov r2, r8
	asrs r1, r2, #0xf
	adds r0, #0x74
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08029264
_0802923A:
	ldr r6, _08029294 @ =0x020314E0
	ldr r0, [r6]
	mov r1, r8
	asrs r3, r1, #0x10
	lsls r1, r3, #1
	adds r0, #0x74
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0
	bne _08029264
	ldr r6, _0802929C @ =gMain
	ldr r0, [r6, #0x44]
	lsls r1, r3, #2
	adds r1, r1, r0
	adds r1, #0xb4
	ldr r0, [r1]
	strh r2, [r0]
_08029264:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08029274
	b _080290C6
_08029274:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029284: .4byte 0x086B263C
_08029288: .4byte 0xFFFFFE00
_0802928C: .4byte gOamBuffer
_08029290: .4byte 0x000001FF
_08029294: .4byte 0x020314E0
_08029298: .4byte 0x000005A4
_0802929C: .4byte gMain

	thumb_func_start sub_292A0
sub_292A0: @ 0x080292A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08029328 @ =gMain
	ldr r1, [r0, #0x44]
	adds r1, #0x84
	ldr r5, [r1]
	ldrh r1, [r5]
	mov r8, r0
	cmp r1, #0
	beq _080292F0
	movs r0, #0
	ldr r6, _0802932C @ =gOamBuffer
	ldr r1, _08029330 @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_080292C0:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r4, r2, #3
	adds r4, #8
	adds r4, r5, r4
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _080292C0
_080292F0:
	mov r1, r8
	ldr r0, [r1, #0x44]
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	mov r4, r8
	movs r3, #0
_08029300:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x44]
	lsls r0, r1, #2
	adds r0, r0, r2
	adds r0, #0xb4
	ldr r0, [r0]
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _08029300
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029328: .4byte gMain
_0802932C: .4byte gOamBuffer
_08029330: .4byte 0xFFFFFE00

	thumb_func_start sub_29334
sub_29334: @ 0x08029334
	push {r4, r5, lr}
	ldr r0, _08029384 @ =0x020314E0
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r4, r0, #0
	cmp r1, #0x8a
	ble _080293A6
	ldr r5, _08029388 @ =0x000006C5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bne _08029398
	ldr r0, _0802938C @ =0x00000625
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08029398
	adds r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	bne _08029394
	movs r0, #2
	strb r0, [r3]
	ldr r1, [r4]
	ldr r0, _08029390 @ =0x000493E0
	str r0, [r1, #0x3c]
	b _08029398
	.align 2, 0
_08029384: .4byte 0x020314E0
_08029388: .4byte 0x000006C5
_0802938C: .4byte 0x00000625
_08029390: .4byte 0x000493E0
_08029394:
	movs r0, #1
	strb r0, [r3]
_08029398:
	ldr r0, [r4]
	ldr r2, _080293BC @ =0x00000625
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _080293C0 @ =0x000006C6
	adds r0, r0, r3
	strb r1, [r0]
_080293A6:
	ldr r0, [r4]
	ldr r5, _080293C4 @ =0x000006C5
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _080293C8
	bl sub_25808
	b _080293D0
	.align 2, 0
_080293BC: .4byte 0x00000625
_080293C0: .4byte 0x000006C6
_080293C4: .4byte 0x000006C5
_080293C8:
	cmp r0, #1
	bne _080293D0
	bl sub_253E0
_080293D0:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_293D8
sub_293D8: @ 0x080293D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _0802940C @ =0x086AD436
	ldr r3, _08029410 @ =0x020314E0
	ldr r2, [r3]
	ldr r0, _08029414 @ =0x000006CC
	adds r4, r2, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _08029418 @ =0x000006CA
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0802941C
	adds r0, r1, #1
	strh r0, [r2]
	b _08029426
	.align 2, 0
_0802940C: .4byte 0x086AD436
_08029410: .4byte 0x020314E0
_08029414: .4byte 0x000006CC
_08029418: .4byte 0x000006CA
_0802941C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08029426:
	ldr r2, _080295E4 @ =0x020314E0
	ldr r1, [r2]
	ldr r4, _080295E8 @ =0x000006CC
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08029456
	ldr r2, _080295EC @ =0x000006CA
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _08029456
	subs r4, #8
	adds r1, r1, r4
	movs r0, #3
	strb r0, [r1]
	ldr r0, _080295F0 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x84
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
_08029456:
	ldr r4, _080295E4 @ =0x020314E0
	ldr r0, [r4]
	ldr r5, _080295E8 @ =0x000006CC
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0802948A
	ldr r1, _080295F4 @ =0x040000D4
	ldr r0, _080295F8 @ =0x020306D0
	str r0, [r1]
	ldr r0, _080295FC @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _08029600 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08029604 @ =0x02030760
	str r0, [r1]
	ldr r0, _08029608 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _0802960C @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_28C90
_0802948A:
	ldr r0, _080295F0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r7, [r1, #0x48]
	ldrh r1, [r7]
	cmp r1, #0
	bne _08029498
	b _080295A0
_08029498:
	ldr r0, _080295E4 @ =0x020314E0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _080294C2
	movs r0, #0xc8
	strh r0, [r7, #4]
_080294C2:
	movs r0, #0
	ldr r4, _08029610 @ =0x086B55DC
	mov sl, r4
	ldr r1, _08029614 @ =0x086AD436
	mov sb, r1
	ldr r2, _080295E4 @ =0x020314E0
	mov r8, r2
	mov ip, r5
_080294D2:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r6, r5, #3
	adds r6, #8
	adds r6, r7, r6
	ldrh r4, [r6]
	lsls r4, r4, #3
	ldr r0, _08029618 @ =gOamBuffer
	adds r4, r4, r0
	lsls r3, r5, #1
	adds r3, r3, r5
	lsls r1, r3, #1
	str r1, [sp]
	mov r2, r8
	ldr r0, [r2]
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	add r2, sl
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, #2
	adds r2, r3, #1
	lsls r2, r2, #1
	str r2, [sp]
	mov r2, r8
	ldr r0, [r2]
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	add r2, sl
	ldrh r0, [r2]
	strh r0, [r4]
	adds r3, #2
	lsls r3, r3, #1
	mov r2, r8
	ldr r0, [r2]
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r3, r0
	add r3, sl
	ldrh r0, [r3]
	strh r0, [r4, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	ldr r4, _08029618 @ =gOamBuffer
	adds r2, r2, r4
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r4, _0802961C @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08029620 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	ldr r0, _08029618 @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #5
	ble _080294D2
_080295A0:
	ldr r4, _080295F0 @ =gMain
	ldr r0, [r4, #0x44]
	ldr r1, [r0, #0x48]
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080295E4 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _080295E8 @ =0x000006CC
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _080295D4
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r4, #0x44]
	ldr r1, [r0, #0x48]
	movs r0, #0
	strh r0, [r1]
	ldr r4, _080295E4 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_080295D4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080295E4: .4byte 0x020314E0
_080295E8: .4byte 0x000006CC
_080295EC: .4byte 0x000006CA
_080295F0: .4byte gMain
_080295F4: .4byte 0x040000D4
_080295F8: .4byte 0x020306D0
_080295FC: .4byte 0x050003A0
_08029600: .4byte 0x80000010
_08029604: .4byte 0x02030760
_08029608: .4byte 0x06010CA0
_0802960C: .4byte 0x80000240
_08029610: .4byte 0x086B55DC
_08029614: .4byte 0x086AD436
_08029618: .4byte gOamBuffer
_0802961C: .4byte 0x000001FF
_08029620: .4byte 0xFFFFFE00

	thumb_func_start sub_29624
sub_29624: @ 0x08029624
	push {r4, r5, lr}
	ldr r0, _08029658 @ =0x020314E0
	ldr r1, [r0]
	ldr r2, _0802965C @ =0x000006CC
	adds r1, r1, r2
	movs r2, #0
	strb r2, [r1]
	adds r5, r0, #0
	ldr r4, _08029660 @ =0x000006D3
	movs r3, #0xd
_08029638:
	ldr r1, [r5]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08029638
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029658: .4byte 0x020314E0
_0802965C: .4byte 0x000006CC
_08029660: .4byte 0x000006D3

	thumb_func_start sub_29664
sub_29664: @ 0x08029664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	ldr r7, _08029700 @ =0x020314E0
	mov r8, r0
_08029670:
	ldr r1, [r7]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r6, r5, #2
	adds r1, r1, r6
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r0, r1, r2
	mov r2, r8
	strh r2, [r0]
	ldr r0, _08029704 @ =0x000005C2
	adds r1, r1, r0
	strh r2, [r1]
	bl sub_C00
	ldr r4, [r7]
	adds r4, r4, r6
	movs r1, #0xc8
	lsls r1, r1, #1
	bl __umodsi3
	movs r1, #0xc8
	subs r1, r1, r0
	movs r2, #0xbb
	lsls r2, r2, #3
	adds r4, r4, r2
	strh r1, [r4]
	bl sub_C00
	ldr r4, [r7]
	adds r4, r4, r6
	ldr r1, _08029708 @ =0x00000226
	bl __umodsi3
	movs r1, #0x50
	subs r1, r1, r0
	ldr r0, _0802970C @ =0x000005DA
	adds r4, r4, r0
	strh r1, [r4]
	bl sub_C00
	ldr r4, [r7]
	ldr r1, _08029710 @ =0x000005B9
	adds r4, r4, r1
	adds r4, r4, r5
	movs r1, #0xf
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #5
	ble _08029670
	ldr r0, _08029700 @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _08029714 @ =0x00000606
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08029718 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x30]
	movs r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029700: .4byte 0x020314E0
_08029704: .4byte 0x000005C2
_08029708: .4byte 0x00000226
_0802970C: .4byte 0x000005DA
_08029710: .4byte 0x000005B9
_08029714: .4byte 0x00000606
_08029718: .4byte gMain

	thumb_func_start sub_2971C
sub_2971C: @ 0x0802971C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080298B8 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r1, [r1, #0x30]
	str r1, [sp]
	ldrh r1, [r1]
	cmp r1, #0
	bne _08029738
	b _080298A2
_08029738:
	movs r3, #0
_0802973A:
	ldr r0, _080298BC @ =0x020314E0
	ldr r2, [r0]
	ldr r1, _080298C0 @ =0x00000606
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r1, r1, #2
	lsls r1, r1, #1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov sb, r0
	lsls r0, r0, #1
	add r0, sb
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r3, _080298C4 @ =0x086AE1A4
	adds r1, r1, r3
	ldrh r1, [r1]
	mov sl, r1
	mov r6, sb
	lsls r5, r6, #2
	adds r3, r2, r5
	ldr r0, _080298C8 @ =0x000005DA
	adds r4, r3, r0
	ldr r1, _080298CC @ =0x000005B9
	adds r2, r2, r1
	add r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldr r6, _080298D0 @ =0x000005C2
	adds r2, r3, r6
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080298D4 @ =0x000036AF
	cmp r1, r0
	bgt _0802979E
	subs r6, #2
	adds r1, r3, r6
	adds r6, #0x18
	adds r0, r3, r6
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r4]
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
_0802979E:
	ldr r0, _080298BC @ =0x020314E0
	ldr r6, [r0]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r0
	movs r1, #3
	bl __modsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #0x14
	adds r0, r6, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r0, #0x60
	subs r4, r4, r0
	adds r5, r6, r5
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x64
	bl __divsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080298D8 @ =0xFFFF0000
	ands r7, r0
	orrs r7, r4
	mov r0, r8
	movs r1, #3
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #0x14
	adds r6, #0x5a
	ldr r1, _080298DC @ =0xFFFFFED4
	adds r0, r1, #0
	ldrh r6, [r6]
	adds r0, r0, r6
	subs r4, r4, r0
	ldr r2, _080298D0 @ =0x000005C2
	adds r5, r5, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0x64
	bl __divsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080298E0 @ =0x0000FFFF
	ands r7, r0
	orrs r7, r4
	asrs r4, r4, #0x10
	cmp r4, #0xc7
	ble _08029824
	ands r7, r0
	movs r0, #0xc8
	lsls r0, r0, #0x10
	orrs r7, r0
_08029824:
	mov r5, sb
	lsls r4, r5, #3
	adds r4, #8
	ldr r6, [sp]
	adds r4, r6, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	ldr r0, _080298E4 @ =gOamBuffer
	adds r2, r2, r0
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r3, _080298E8 @ =0x086B53B4
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r3, #0
	adds r0, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r5, _080298EC @ =0x086B53B8
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r3, [r4]
	lsls r3, r3, #3
	ldr r6, _080298E4 @ =gOamBuffer
	adds r3, r3, r6
	ldrh r2, [r3, #2]
	lsls r1, r2, #0x17
	lsrs r1, r1, #0x17
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	ldr r5, _080298F0 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldr r6, _080298F4 @ =0xFFFFFE00
	adds r0, r6, #0
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	ldr r0, _080298E4 @ =gOamBuffer
	adds r1, r1, r0
	asrs r0, r7, #0x10
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bgt _080298A2
	b _0802973A
_080298A2:
	ldr r3, _080298BC @ =0x020314E0
	ldr r1, [r3]
	ldr r5, _080298C0 @ =0x00000606
	adds r2, r1, r5
	ldrh r0, [r2]
	cmp r0, #0x2f
	bhi _080298F8
	adds r0, #1
	strh r0, [r2]
	b _0802990C
	.align 2, 0
_080298B8: .4byte gMain
_080298BC: .4byte 0x020314E0
_080298C0: .4byte 0x00000606
_080298C4: .4byte 0x086AE1A4
_080298C8: .4byte 0x000005DA
_080298CC: .4byte 0x000005B9
_080298D0: .4byte 0x000005C2
_080298D4: .4byte 0x000036AF
_080298D8: .4byte 0xFFFF0000
_080298DC: .4byte 0xFFFFFED4
_080298E0: .4byte 0x0000FFFF
_080298E4: .4byte gOamBuffer
_080298E8: .4byte 0x086B53B4
_080298EC: .4byte 0x086B53B8
_080298F0: .4byte 0x000001FF
_080298F4: .4byte 0xFFFFFE00
_080298F8:
	ldr r6, _0802991C @ =0x000006CA
	adds r1, r1, r6
	movs r2, #0
	movs r0, #0xe2
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r1, _08029920 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x30]
	strh r2, [r0]
_0802990C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802991C: .4byte 0x000006CA
_08029920: .4byte gMain

	thumb_func_start sub_29924
sub_29924: @ 0x08029924
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	ldr r7, _08029A34 @ =0x020314E0
	movs r1, #0x64
	mov sb, r1
	ldr r2, _08029A38 @ =0x086AE2F4
	mov sl, r2
_0802993A:
	ldr r4, [r7]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r6, r5, #2
	adds r4, r4, r6
	adds r0, r5, #0
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	subs r0, #0x18
	mov r1, sb
	muls r1, r0, r1
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	subs r0, #0x1c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r2, _08029A3C @ =0x000005C2
	adds r4, r4, r2
	strh r0, [r4]
	bl sub_C00
	ldr r4, [r7]
	adds r4, r4, r6
	adds r1, r6, #0
	add r1, sl
	mov r8, r1
	movs r1, #0xc8
	bl __umodsi3
	subs r0, #0x3c
	mov r2, r8
	ldrh r1, [r2]
	subs r1, r1, r0
	movs r0, #0xbb
	lsls r0, r0, #3
	adds r4, r4, r0
	strh r1, [r4]
	bl sub_C00
	ldr r4, [r7]
	adds r4, r4, r6
	ldr r1, _08029A40 @ =0x086AE2F6
	adds r6, r6, r1
	movs r1, #0xc8
	bl __umodsi3
	subs r0, #0x3c
	ldrh r1, [r6]
	subs r1, r1, r0
	ldr r2, _08029A44 @ =0x000005DA
	adds r4, r4, r2
	strh r1, [r4]
	bl sub_C00
	ldr r1, [r7]
	ldr r2, _08029A48 @ =0x000005B9
	adds r1, r1, r2
	adds r1, r1, r5
	movs r2, #3
	ands r0, r2
	adds r0, #1
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #5
	ble _0802993A
	ldr r3, _08029A34 @ =0x020314E0
	ldr r1, [r3]
	movs r0, #0xb8
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r5, #0
	ldr r0, _08029A4C @ =0x0000EA20
	strh r0, [r2]
	ldr r0, _08029A3C @ =0x000005C2
	adds r2, r1, r0
	ldr r0, _08029A50 @ =0x0000E890
	strh r0, [r2]
	ldr r2, _08029A48 @ =0x000005B9
	adds r1, r1, r2
	movs r4, #3
	strb r4, [r1]
	ldr r1, [r3]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r1, r0
	ldr r0, _08029A54 @ =0x0000F060
	strh r0, [r2]
	ldr r0, _08029A58 @ =0x000005D2
	adds r2, r1, r0
	ldr r0, _08029A5C @ =0x0000EED0
	strh r0, [r2]
	ldr r2, _08029A60 @ =0x000005BD
	adds r1, r1, r2
	strb r4, [r1]
	ldr r0, [r3]
	ldr r1, _08029A64 @ =0x00000606
	adds r0, r0, r1
	strh r5, [r0]
	ldr r0, _08029A68 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x30]
	movs r0, #1
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029A34: .4byte 0x020314E0
_08029A38: .4byte 0x086AE2F4
_08029A3C: .4byte 0x000005C2
_08029A40: .4byte 0x086AE2F6
_08029A44: .4byte 0x000005DA
_08029A48: .4byte 0x000005B9
_08029A4C: .4byte 0x0000EA20
_08029A50: .4byte 0x0000E890
_08029A54: .4byte 0x0000F060
_08029A58: .4byte 0x000005D2
_08029A5C: .4byte 0x0000EED0
_08029A60: .4byte 0x000005BD
_08029A64: .4byte 0x00000606
_08029A68: .4byte gMain

	thumb_func_start sub_29A6C
sub_29A6C: @ 0x08029A6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08029D2C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x30]
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08029A88
	b _08029C52
_08029A88:
	movs r5, #0
	ldr r0, _08029D30 @ =gOamBuffer
	mov r8, r0
	ldr r1, _08029D34 @ =0x086B4E3E
	mov sl, r1
_08029A92:
	ldr r2, _08029D38 @ =0x020314E0
	ldr r6, [r2]
	ldr r0, _08029D3C @ =0x00000606
	adds r4, r6, r0
	ldrh r0, [r4]
	movs r1, #5
	bl __udivsi3
	lsls r3, r5, #0x10
	asrs r5, r3, #0x10
	lsls r1, r5, #1
	add r1, sp
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	lsls r1, r5, #5
	adds r0, r0, r1
	ldr r1, _08029D40 @ =0x086AE234
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, ip
	strh r0, [r2]
	ldrh r0, [r4]
	mov ip, r3
	cmp r0, #4
	bls _08029B22
	lsls r2, r5, #2
	adds r0, r6, r2
	ldr r3, _08029D44 @ =0x000005DA
	adds r0, r0, r3
	ldr r4, _08029D48 @ =0x000005B9
	adds r1, r6, r4
	adds r1, r1, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrh r4, [r0]
	adds r1, r1, r4
	strh r1, [r0]
	cmp r5, #4
	bne _08029AFC
	movs r0, #0xbd
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r4, _08029D4C @ =0x000005BD
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_08029AFC:
	ldr r0, _08029D38 @ =0x020314E0
	ldr r1, [r0]
	adds r1, r1, r2
	movs r4, #0xb8
	lsls r4, r4, #3
	adds r2, r1, r4
	adds r4, #0x18
	adds r0, r1, r4
	ldrh r0, [r0]
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	ldr r0, _08029D50 @ =0x000005C2
	adds r2, r1, r0
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
_08029B22:
	ldr r2, _08029D38 @ =0x020314E0
	ldr r5, [r2]
	mov r4, ip
	asrs r6, r4, #0x10
	lsls r4, r6, #2
	adds r4, r5, r4
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x60
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08029D54 @ =0xFFFF0000
	ands r7, r1
	orrs r7, r0
	ldr r0, _08029D50 @ =0x000005C2
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x64
	bl __divsi3
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r5, #0x5a
	ldrh r1, [r5]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08029D58 @ =0x0000FFFF
	ands r7, r1
	orrs r7, r0
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _08029B82
	ands r7, r1
	movs r0, #0xa0
	lsls r0, r0, #0x10
	orrs r7, r0
_08029B82:
	lsls r4, r6, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, r8
	lsls r5, r6, #1
	mov r0, sp
	adds r3, r0, r5
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r1, sl
	adds r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08029D5C @ =0x086B4E42
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #2]
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	ldrh r2, [r3, #2]
	lsls r1, r2, #0x17
	lsrs r1, r1, #0x17
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	ldr r0, _08029D60 @ =0x000001FF
	mov ip, r0
	mov r0, ip
	ands r1, r0
	ldr r0, _08029D64 @ =0xFFFFFE00
	mov ip, r0
	mov r0, ip
	ands r2, r0
	orrs r2, r1
	strh r2, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	asrs r0, r7, #0x10
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	ldr r1, _08029D68 @ =0x086AE30C
	adds r0, r5, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #3
	ands r2, r0
	ldrb r0, [r3, #1]
	movs r1, #4
	rsbs r1, r1, #0
	mov ip, r1
	mov r1, ip
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	ldr r2, _08029D6C @ =0x086AE318
	adds r5, r5, r2
	movs r4, #0
	ldrsh r2, [r5, r4]
	movs r0, #7
	ands r2, r0
	lsls r2, r2, #1
	ldrb r0, [r3, #3]
	movs r4, #0xf
	rsbs r4, r4, #0
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #3]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bgt _08029C52
	b _08029A92
_08029C52:
	ldr r4, _08029D38 @ =0x020314E0
	ldr r0, [r4]
	ldr r6, _08029D3C @ =0x00000606
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r0, #0xd0
	muls r0, r1, r0
	movs r5, #0xa2
	lsls r5, r5, #3
	adds r1, r5, #0
	bl __divsi3
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bne _08029C84
	lsls r0, r1, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x10
_08029C84:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #2
	bl sub_7C0
	movs r1, #0x80
	mov r0, sp
	ldrh r0, [r0, #2]
	cmp r0, #4
	bne _08029CA0
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_08029CA0:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #3
	bl sub_7C0
	ldr r0, [r4]
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r0, sp
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bne _08029CD6
	lsls r0, r1, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x10
_08029CD6:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #4
	bl sub_7C0
	ldr r0, [r4]
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	adds r1, r5, #0
	bl __divsi3
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r0, sp
	movs r4, #8
	ldrsh r0, [r0, r4]
	cmp r0, #4
	bne _08029D0E
	lsls r0, r1, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x10
_08029D0E:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #5
	bl sub_7C0
	ldr r0, _08029D38 @ =0x020314E0
	ldr r1, [r0]
	adds r2, r1, r6
	ldrh r0, [r2]
	cmp r0, #0x2e
	bhi _08029D70
	adds r0, #1
	strh r0, [r2]
	b _08029D84
	.align 2, 0
_08029D2C: .4byte gMain
_08029D30: .4byte gOamBuffer
_08029D34: .4byte 0x086B4E3E
_08029D38: .4byte 0x020314E0
_08029D3C: .4byte 0x00000606
_08029D40: .4byte 0x086AE234
_08029D44: .4byte 0x000005DA
_08029D48: .4byte 0x000005B9
_08029D4C: .4byte 0x000005BD
_08029D50: .4byte 0x000005C2
_08029D54: .4byte 0xFFFF0000
_08029D58: .4byte 0x0000FFFF
_08029D5C: .4byte 0x086B4E42
_08029D60: .4byte 0x000001FF
_08029D64: .4byte 0xFFFFFE00
_08029D68: .4byte 0x086AE30C
_08029D6C: .4byte 0x086AE318
_08029D70:
	ldr r2, _08029D94 @ =0x000006CA
	adds r1, r1, r2
	movs r2, #0
	movs r0, #0xe2
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r0, _08029D98 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x30]
	strh r2, [r0]
_08029D84:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029D94: .4byte 0x000006CA
_08029D98: .4byte gMain

	thumb_func_start sub_29D9C
sub_29D9C: @ 0x08029D9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, _08029E60 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x5c]
	movs r2, #0
	movs r5, #0
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x50]
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x54]
	strh r1, [r0]
	ldrh r0, [r3, #0x38]
	ldr r0, _08029E64 @ =0x00001C10
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r3, #0x3a]
	ldr r4, _08029E68 @ =0x020314E0
	ldr r0, [r4]
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r4]
	ldr r0, _08029E6C @ =0x000006F2
	adds r2, r1, r0
	movs r0, #8
	strh r0, [r2]
	ldr r2, _08029E70 @ =0x000006F4
	adds r0, r1, r2
	strh r5, [r0]
	subs r2, #0x14
	adds r0, r1, r2
	strh r5, [r0]
	ldr r0, _08029E74 @ =0x000006E9
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	mov r8, r3
	adds r7, r4, #0
	cmp r0, #0x19
	bne _08029E02
	movs r0, #0xa
	strb r0, [r1]
_08029E02:
	movs r3, #0
	ldr r1, _08029E78 @ =0x086AD180
	mov sb, r1
_08029E08:
	ldr r5, [r7]
	lsls r3, r3, #0x10
	asrs r2, r3, #0xf
	movs r1, #0xdf
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r4, r0, r2
	subs r1, #0xf
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r2, r2, r0
	add r2, sb
	ldrh r0, [r2]
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r3, #0
	cmp r0, #0x29
	beq _08029E38
	b _08029F2E
_08029E38:
	mov r2, r8
	ldrb r0, [r2, #4]
	cmp r0, #0
	bne _08029EBC
	ldr r1, _08029E7C @ =0x00000283
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08029E56
	b _08029F9E
_08029E56:
	lsls r0, r0, #2
	ldr r1, _08029E80 @ =_08029E84
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08029E60: .4byte gMain
_08029E64: .4byte 0x00001C10
_08029E68: .4byte 0x020314E0
_08029E6C: .4byte 0x000006F2
_08029E70: .4byte 0x000006F4
_08029E74: .4byte 0x000006E9
_08029E78: .4byte 0x086AD180
_08029E7C: .4byte 0x00000283
_08029E80: .4byte _08029E84
_08029E84: @ jump table
	.4byte _08029E98 @ case 0
	.4byte _08029EAA @ case 1
	.4byte _08029E98 @ case 2
	.4byte _08029EAA @ case 3
	.4byte _08029F1C @ case 4
_08029E98:
	ldr r0, [r7]
	asrs r1, r6, #0xf
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0x2a
	strh r1, [r0]
	b _08029F9E
_08029EAA:
	ldr r0, [r7]
	asrs r1, r6, #0xf
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0x2c
	strh r1, [r0]
	b _08029F9E
_08029EBC:
	ldr r1, _08029EDC @ =0x00000283
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08029F9E
	lsls r0, r0, #2
	ldr r1, _08029EE0 @ =_08029EE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08029EDC: .4byte 0x00000283
_08029EE0: .4byte _08029EE4
_08029EE4: @ jump table
	.4byte _08029EF8 @ case 0
	.4byte _08029F0A @ case 1
	.4byte _08029EF8 @ case 2
	.4byte _08029F0A @ case 3
	.4byte _08029F1C @ case 4
_08029EF8:
	ldr r0, [r7]
	asrs r1, r6, #0xf
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0x29
	strh r1, [r0]
	b _08029F9E
_08029F0A:
	ldr r0, [r7]
	asrs r1, r6, #0xf
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0x2b
	strh r1, [r0]
	b _08029F9E
_08029F1C:
	ldr r0, [r7]
	asrs r1, r6, #0xf
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0x2d
	strh r1, [r0]
	b _08029F9E
_08029F2E:
	cmp r0, #0xa
	bne _08029F4C
	ldr r0, _08029F44 @ =0x000005F6
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08029F48
	adds r0, #0xa
	b _08029F9C
	.align 2, 0
_08029F44: .4byte 0x000005F6
_08029F48:
	movs r0, #0xc
	b _08029F9C
_08029F4C:
	cmp r0, #3
	bne _08029F88
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08029F9E
	mov r2, r8
	ldr r0, [r2, #0x4c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08029F84
	ldr r0, _08029F7C @ =0x000005F6
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08029F80
	adds r0, #0xa
	b _08029F9C
	.align 2, 0
_08029F7C: .4byte 0x000005F6
_08029F80:
	movs r0, #0xc
	b _08029F9C
_08029F84:
	strh r1, [r4]
	b _08029F9E
_08029F88:
	cmp r0, #9
	bne _08029F9E
	ldr r1, _0802A040 @ =0x00000281
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _08029F9E
	movs r0, #8
_08029F9C:
	strh r0, [r4]
_08029F9E:
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r6, r2
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bgt _08029FAE
	b _08029E08
_08029FAE:
	ldr r2, [r7]
	ldr r0, _0802A044 @ =0x00000704
	adds r1, r2, r0
	movs r0, #0x15
	strh r0, [r1]
	ldr r1, _0802A048 @ =0x000006E9
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x18
	bgt _08029FCA
	adds r0, r1, #1
	strb r0, [r2]
_08029FCA:
	ldr r0, [r7]
	ldr r3, _0802A04C @ =0x000006EA
	adds r0, r0, r3
	movs r1, #5
	strb r1, [r0]
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08029FFE
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xb
	ble _08029FFE
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08029FFE:
	ldr r0, [r7]
	ldr r2, _0802A050 @ =0x000006EB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r2, #0xd
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #0xc
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r2, #0xe
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #0xd
	adds r0, r0, r2
	strb r1, [r0]
	movs r0, #2
	movs r1, #0
	bl sub_1C7F4
	movs r0, #2
	movs r1, #1
	bl sub_1C7F4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A040: .4byte 0x00000281
_0802A044: .4byte 0x00000704
_0802A048: .4byte 0x000006E9
_0802A04C: .4byte 0x000006EA
_0802A050: .4byte 0x000006EB

	thumb_func_start sub_2A054
sub_2A054: @ 0x0802A054
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0802A128 @ =gMain
	ldrb r3, [r0, #4]
	mov r8, r0
	ldr r0, _0802A12C @ =0x020314E0
	mov sb, r0
	cmp r3, #1
	bne _0802A0E4
	ldr r2, [r0]
	movs r4, #0xdd
	lsls r4, r4, #3
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802A07E
	b _0802A20C
_0802A07E:
	ldrb r0, [r2, #5]
	cmp r0, #0
	bne _0802A090
	mov r5, r8
	ldrh r1, [r5, #0x18]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0802A0E4
_0802A090:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802A0E4
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r2, r5
	movs r0, #2
	strb r0, [r1]
	mov r0, sb
	ldr r2, [r0]
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0x10
	bgt _0802A0C8
	adds r1, #0xc
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r5, _0802A130 @ =0x000006ED
	adds r0, r2, r5
	strb r1, [r0]
_0802A0C8:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r4
	strb r3, [r0]
	ldr r1, [r1]
	ldr r3, _0802A134 @ =0x000006F2
	adds r2, r1, r3
	movs r0, #0x28
	strh r0, [r2]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r1, r1, r5
	movs r0, #0x27
	strh r0, [r1]
_0802A0E4:
	mov r0, sb
	ldr r2, [r0]
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	beq _0802A0F8
	b _0802A20C
_0802A0F8:
	ldr r3, _0802A138 @ =0x000006C4
	adds r0, r2, r3
	movs r5, #1
	strb r5, [r0]
	mov r0, sb
	ldr r2, [r0]
	adds r3, #0x2c
	adds r4, r2, r3
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r7, _0802A13C @ =0x000006F4
	adds r3, r2, r7
	ldrh r0, [r3]
	cmp r0, #0
	beq _0802A170
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0802A140
	adds r0, r2, r1
	strb r5, [r0]
	b _0802A1CA
	.align 2, 0
_0802A128: .4byte gMain
_0802A12C: .4byte 0x020314E0
_0802A130: .4byte 0x000006ED
_0802A134: .4byte 0x000006F2
_0802A138: .4byte 0x000006C4
_0802A13C: .4byte 0x000006F4
_0802A140:
	ldr r0, _0802A168 @ =0x000006F2
	adds r5, r2, r0
	ldrh r0, [r4]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0802A1CA
	ldrh r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r3, _0802A16C @ =0x000006F6
	adds r1, r2, r3
	ldrh r1, [r1]
	bl __divsi3
	movs r1, #0x28
	subs r1, r1, r0
	strh r1, [r5]
	strh r6, [r4]
	b _0802A1CA
	.align 2, 0
_0802A168: .4byte 0x000006F2
_0802A16C: .4byte 0x000006F6
_0802A170:
	ldrb r0, [r2, #5]
	cmp r0, #0
	bne _0802A182
	mov r0, r8
	ldrh r1, [r0, #0x18]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0802A1CA
_0802A182:
	bl sub_C00
	mov r1, sb
	ldr r4, [r1]
	movs r1, #0xc8
	bl __umodsi3
	adds r0, #0x64
	adds r2, r4, r7
	strh r0, [r2]
	ldr r0, _0802A1F8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0802A1BA
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #1
	bne _0802A1BA
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r2]
	movs r5, #0xdf
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
_0802A1BA:
	ldr r0, _0802A1FC @ =0x020314E0
	ldr r0, [r0]
	ldr r2, _0802A200 @ =0x000006F4
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, _0802A204 @ =0x000006F6
	adds r0, r0, r3
	strh r1, [r0]
_0802A1CA:
	ldr r0, _0802A1FC @ =0x020314E0
	ldr r5, [r0]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r1, _0802A208 @ =0x000006F2
	adds r6, r5, r1
	ldrh r0, [r4]
	ldrh r1, [r6]
	bl __umodsi3
	strh r0, [r4]
	ldrh r0, [r4]
	lsls r0, r0, #5
	ldrh r1, [r6]
	bl __divsi3
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r5, r5, r2
	strh r0, [r5]
	b _0802A27C
	.align 2, 0
_0802A1F8: .4byte gMain
_0802A1FC: .4byte 0x020314E0
_0802A200: .4byte 0x000006F4
_0802A204: .4byte 0x000006F6
_0802A208: .4byte 0x000006F2
_0802A20C:
	ldr r7, _0802A2DC @ =0x020314E0
	ldr r6, [r7]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r4, r6, r3
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, _0802A2E0 @ =0x000006F2
	adds r5, r6, r0
	ldrh r0, [r4]
	ldrh r1, [r5]
	bl __umodsi3
	strh r0, [r4]
	ldrh r0, [r4]
	lsls r0, r0, #5
	ldrh r1, [r5]
	bl __divsi3
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	ldrh r4, [r4]
	cmp r4, #0
	bne _0802A2AC
	movs r0, #0x8c
	strh r0, [r6, #0x28]
	mov r3, r8
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x5c]
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x50]
	strh r4, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x54]
	strh r4, [r0]
	strh r4, [r1]
	ldr r5, _0802A2E4 @ =0x000006C4
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0802A2E8 @ =0x02032EE0
	bl m4aMPlayStop
	ldr r0, [r7]
	ldr r1, _0802A2EC @ =0x000006DD
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	ldr r2, _0802A2F0 @ =0x000006DE
	adds r0, r0, r2
	strh r4, [r0]
_0802A27C:
	ldr r5, _0802A2DC @ =0x020314E0
	ldr r2, [r5]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802A2AC
	ldr r1, _0802A2F4 @ =0x000006ED
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r4, _0802A2F8 @ =0x000006EC
	adds r0, r2, r4
	strb r1, [r0]
	movs r0, #2
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	adds r4, r0, r4
	ldrb r1, [r4]
	ldr r2, _0802A2FC @ =0x000006DC
	adds r0, r0, r2
	strb r1, [r0]
_0802A2AC:
	ldr r0, _0802A2DC @ =0x020314E0
	ldr r3, [r0]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r1, r3, r5
	ldrh r1, [r1]
	mov sb, r0
	cmp r1, #1
	bne _0802A33A
	ldr r0, _0802A300 @ =0x000006EB
	adds r2, r3, r0
	ldr r1, _0802A304 @ =0x000006EA
	adds r0, r3, r1
	ldrb r3, [r2]
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _0802A308
	adds r0, r3, #1
	b _0802A30A
	.align 2, 0
_0802A2DC: .4byte 0x020314E0
_0802A2E0: .4byte 0x000006F2
_0802A2E4: .4byte 0x000006C4
_0802A2E8: .4byte 0x02032EE0
_0802A2EC: .4byte 0x000006DD
_0802A2F0: .4byte 0x000006DE
_0802A2F4: .4byte 0x000006ED
_0802A2F8: .4byte 0x000006EC
_0802A2FC: .4byte 0x000006DC
_0802A300: .4byte 0x000006EB
_0802A304: .4byte 0x000006EA
_0802A308:
	movs r0, #0
_0802A30A:
	strb r0, [r2]
	mov r3, sb
	ldr r2, [r3]
	ldr r5, _0802A348 @ =0x000006EB
	adds r0, r2, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #1
	movs r3, #0xdf
	lsls r3, r3, #3
	adds r0, r2, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, #2
	adds r2, r2, r5
	strb r0, [r2]
	movs r0, #2
	movs r1, #1
	bl sub_1C7F4
	ldr r0, _0802A34C @ =0x02032F20
	ldr r1, _0802A350 @ =0x0869F45C
	bl MPlayStart
_0802A33A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A348: .4byte 0x000006EB
_0802A34C: .4byte 0x02032F20
_0802A350: .4byte 0x0869F45C

	thumb_func_start sub_2A354
sub_2A354: @ 0x0802A354
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802A3C4 @ =0x020314E0
	ldr r0, [r4]
	ldr r5, _0802A3C8 @ =0x000006DE
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0xb3
	bhi _0802A3A6
	cmp r0, #4
	bne _0802A36E
	movs r0, #0x14
	bl m4aSongNumStart
_0802A36E:
	ldr r1, [r4]
	ldr r2, _0802A3CC @ =0x000006DC
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802A388
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _0802A388
	movs r0, #0xb2
	bl m4aSongNumStart
_0802A388:
	ldr r0, _0802A3C4 @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _0802A3C8 @ =0x000006DE
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bhi _0802A3A6
	movs r0, #8
	movs r1, #0
	bl sub_1C7F4
_0802A3A6:
	ldr r1, _0802A3C4 @ =0x020314E0
	ldr r0, [r1]
	ldr r4, _0802A3CC @ =0x000006DC
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #0x2d
	bls _0802A3B8
	b _0802AAD2
_0802A3B8:
	lsls r0, r0, #2
	ldr r1, _0802A3D0 @ =_0802A3D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A3C4: .4byte 0x020314E0
_0802A3C8: .4byte 0x000006DE
_0802A3CC: .4byte 0x000006DC
_0802A3D0: .4byte _0802A3D4
_0802A3D4: @ jump table
	.4byte _0802A48C @ case 0
	.4byte _0802A48C @ case 1
	.4byte _0802A48C @ case 2
	.4byte _0802A4B0 @ case 3
	.4byte _0802A648 @ case 4
	.4byte _0802A668 @ case 5
	.4byte _0802A690 @ case 6
	.4byte _0802A718 @ case 7
	.4byte _0802A778 @ case 8
	.4byte _0802A798 @ case 9
	.4byte _0802A830 @ case 10
	.4byte _0802A830 @ case 11
	.4byte _0802A830 @ case 12
	.4byte _0802A864 @ case 13
	.4byte _0802AAD2 @ case 14
	.4byte _0802AAD2 @ case 15
	.4byte _0802AAD2 @ case 16
	.4byte _0802A8CC @ case 17
	.4byte _0802A8CC @ case 18
	.4byte _0802A8CC @ case 19
	.4byte _0802A924 @ case 20
	.4byte _0802A940 @ case 21
	.4byte _0802A964 @ case 22
	.4byte _0802A9A8 @ case 23
	.4byte _0802A9E0 @ case 24
	.4byte _0802A9E0 @ case 25
	.4byte _0802A9E0 @ case 26
	.4byte _0802A9E0 @ case 27
	.4byte _0802A9E0 @ case 28
	.4byte _0802A9E0 @ case 29
	.4byte _0802A9E0 @ case 30
	.4byte _0802A9E0 @ case 31
	.4byte _0802A9E0 @ case 32
	.4byte _0802AA24 @ case 33
	.4byte _0802AA44 @ case 34
	.4byte _0802AA64 @ case 35
	.4byte _0802AA84 @ case 36
	.4byte _0802AA84 @ case 37
	.4byte _0802AA84 @ case 38
	.4byte _0802AA84 @ case 39
	.4byte _0802AA84 @ case 40
	.4byte _0802AAC0 @ case 41
	.4byte _0802AAC0 @ case 42
	.4byte _0802AAC0 @ case 43
	.4byte _0802AAC0 @ case 44
	.4byte _0802AAC0 @ case 45
_0802A48C:
	ldr r2, [r5]
	ldr r1, _0802A4A8 @ =0x000006DC
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, _0802A4AC @ =0x00000724
	adds r2, r2, r3
	strh r0, [r2]
	b _0802AAD2
	.align 2, 0
_0802A4A8: .4byte 0x000006DC
_0802A4AC: .4byte 0x00000724
_0802A4B0:
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0802A578
	ldr r2, _0802A560 @ =0x000006DE
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x7c
	bls _0802A4E2
	movs r0, #0xd7
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x63
	bhi _0802A4E2
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r2
	movs r1, #0x7c
	strh r1, [r0]
_0802A4E2:
	ldr r3, [r5]
	ldr r1, _0802A560 @ =0x000006DE
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #4
	beq _0802A4F0
	b _0802AAD2
_0802A4F0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	movs r1, #0xa8
	strh r1, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #0xd
	strh r1, [r0]
	adds r4, #2
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r2, [r0]
	adds r4, #0xc
	adds r1, r3, r4
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _0802A564 @ =0x040000D4
	ldr r0, _0802A568 @ =0x084C156C
	str r0, [r1]
	ldr r0, _0802A56C @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _0802A570 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5]
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802A574 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r5]
	subs r4, #0x16
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	b _0802AAD2
	.align 2, 0
_0802A560: .4byte 0x000006DE
_0802A564: .4byte 0x040000D4
_0802A568: .4byte 0x084C156C
_0802A56C: .4byte 0x06010600
_0802A570: .4byte 0x800000C0
_0802A574: .4byte gMain
_0802A578:
	ldr r7, _0802A640 @ =0x000006DE
	adds r0, r4, r7
	ldrh r6, [r0]
	cmp r6, #0x78
	bne _0802A61E
	ldr r2, _0802A644 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	strh r3, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0xfa
	strh r0, [r1]
	subs r1, #4
	adds r0, #0x16
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe6
	strh r3, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf2
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r0, [r5]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r4, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, [r5]
	movs r4, #0xe3
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r1, #0xa8
	strh r1, [r0]
	adds r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0xd
	strh r1, [r0]
	adds r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r6, [r0]
	adds r4, #0x12
	adds r1, r2, r4
	movs r0, #0x3c
	strh r0, [r1]
_0802A61E:
	ldr r1, [r5]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802A62E
	b _0802AAD2
_0802A62E:
	adds r1, r1, r7
	ldrh r0, [r1]
	cmp r0, #0xaf
	bhi _0802A638
	b _0802AAD2
_0802A638:
	movs r0, #0xb0
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A640: .4byte 0x000006DE
_0802A644: .4byte gMain
_0802A648:
	ldr r1, [r5]
	ldr r3, _0802A660 @ =0x000006DE
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A656
	b _0802AAD2
_0802A656:
	ldr r4, _0802A664 @ =0x00000286
	adds r1, r1, r4
	movs r0, #0x5a
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A660: .4byte 0x000006DE
_0802A664: .4byte 0x00000286
_0802A668:
	ldr r4, [r5]
	ldr r0, _0802A688 @ =0x000006DE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A676
	b _0802AAD2
_0802A676:
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, _0802A68C @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x21
	b _0802A744
	.align 2, 0
_0802A688: .4byte 0x000006DE
_0802A68C: .4byte gMain
_0802A690:
	ldr r4, [r5]
	ldr r3, _0802A6BC @ =0x000006DE
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A69E
	b _0802AAD2
_0802A69E:
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, _0802A6C0 @ =0x000006E9
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0802A6C8
	ldr r0, _0802A6C4 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x18
	b _0802A744
	.align 2, 0
_0802A6BC: .4byte 0x000006DE
_0802A6C0: .4byte 0x000006E9
_0802A6C4: .4byte gMain
_0802A6C8:
	cmp r0, #0xa
	bgt _0802A6E0
	ldr r0, _0802A6DC @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x18
	b _0802A768
	.align 2, 0
_0802A6DC: .4byte gMain
_0802A6E0:
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A704
	ldr r0, _0802A700 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x1c
	b _0802A744
	.align 2, 0
_0802A700: .4byte gMain
_0802A704:
	ldr r0, _0802A714 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #7
	bl __umodsi3
	adds r0, #0x18
	b _0802A768
	.align 2, 0
_0802A714: .4byte gMain
_0802A718:
	ldr r4, [r5]
	ldr r0, _0802A74C @ =0x000006DE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A726
	b _0802AAD2
_0802A726:
	movs r0, #0xc
	strh r0, [r1]
	ldr r1, _0802A750 @ =0x000006E9
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bgt _0802A75C
	ldr r0, _0802A754 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x24
_0802A744:
	ldr r2, _0802A758 @ =0x000006DC
	adds r1, r4, r2
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A74C: .4byte 0x000006DE
_0802A750: .4byte 0x000006E9
_0802A754: .4byte gMain
_0802A758: .4byte 0x000006DC
_0802A75C:
	ldr r0, _0802A770 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x24
_0802A768:
	ldr r3, _0802A774 @ =0x000006DC
	adds r1, r4, r3
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A770: .4byte gMain
_0802A774: .4byte 0x000006DC
_0802A778:
	ldr r0, [r5]
	ldr r4, _0802A794 @ =0x000006DE
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A786
	b _0802AAD2
_0802A786:
	movs r0, #4
	bl sub_19B64
	ldr r1, [r5]
	movs r0, #0x64
	strh r0, [r1, #0x28]
	b _0802AAD2
	.align 2, 0
_0802A794: .4byte 0x000006DE
_0802A798:
	ldr r1, [r5]
	ldr r2, _0802A818 @ =0x00000281
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0802A7AA
	b _0802AAD2
_0802A7AA:
	ldr r4, _0802A81C @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0802A7C6
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0xb4
	strh r0, [r2]
	ldr r0, _0802A820 @ =0x000006C4
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
_0802A7C6:
	ldr r2, [r5]
	adds r1, r2, r4
	ldrh r0, [r1]
	cmp r0, #0x96
	bne _0802A7F2
	movs r0, #0x95
	strh r0, [r1]
	ldr r3, _0802A824 @ =0x000001A5
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	bl sub_1B140
	ldr r0, [r5]
	ldr r1, _0802A828 @ =0x0000036A
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0802A82C @ =0x0000036B
	adds r0, r0, r2
	strb r1, [r0]
_0802A7F2:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0xaa
	beq _0802A7FE
	b _0802AAD2
_0802A7FE:
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _0802A824 @ =0x000001A5
	adds r0, r0, r4
	strb r1, [r0]
	movs r0, #6
	bl sub_19B64
	b _0802AAD2
	.align 2, 0
_0802A818: .4byte 0x00000281
_0802A81C: .4byte 0x000006DE
_0802A820: .4byte 0x000006C4
_0802A824: .4byte 0x000001A5
_0802A828: .4byte 0x0000036A
_0802A82C: .4byte 0x0000036B
_0802A830:
	ldr r1, [r5]
	ldr r2, _0802A85C @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A83E
	b _0802AAD2
_0802A83E:
	ldr r4, _0802A860 @ =0x000005F6
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _0802A850
	adds r0, r2, #1
	strb r0, [r1]
_0802A850:
	ldr r0, [r5]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r0, r3
	b _0802A882
	.align 2, 0
_0802A85C: .4byte 0x000006DE
_0802A860: .4byte 0x000005F6
_0802A864:
	ldr r1, [r5]
	ldr r4, _0802A8B0 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A872
	b _0802AAD2
_0802A872:
	subs r4, #0xe8
	adds r1, r1, r4
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r0, r1
_0802A882:
	movs r1, #0xe1
	lsls r1, r1, #4
	strh r1, [r0]
	ldr r0, _0802A8B4 @ =0x02032F20
	ldr r1, _0802A8B8 @ =0x0869F664
	bl MPlayStart
	ldr r2, _0802A8BC @ =0x040000D4
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802A8C0 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802A8C4 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802A8C8 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802AAD2
	.align 2, 0
_0802A8B0: .4byte 0x000006DE
_0802A8B4: .4byte 0x02032F20
_0802A8B8: .4byte 0x0869F664
_0802A8BC: .4byte 0x040000D4
_0802A8C0: .4byte 0x08137E14
_0802A8C4: .4byte 0x05000220
_0802A8C8: .4byte 0x80000010
_0802A8CC:
	ldr r1, [r5]
	ldr r4, _0802A918 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	bne _0802A906
	ldr r2, _0802A91C @ =0x0000072B
	adds r1, r1, r2
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r2, [r5]
	ldr r1, _0802A920 @ =0x000006DC
	adds r0, r2, r1
	ldrb r1, [r0]
	subs r1, #0x11
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xa
	movs r1, #0xca
	lsls r1, r1, #1
	adds r2, r2, r1
	strb r0, [r2]
	ldr r0, [r5]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r3, [r0]
_0802A906:
	ldr r0, [r5]
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0x8c
	beq _0802A912
	b _0802AAD2
_0802A912:
	movs r0, #0x8b
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A918: .4byte 0x000006DE
_0802A91C: .4byte 0x0000072B
_0802A920: .4byte 0x000006DC
_0802A924:
	ldr r1, [r5]
	ldr r3, _0802A93C @ =0x000006DE
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A932
	b _0802AAD2
_0802A932:
	adds r1, #0x6c
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A93C: .4byte 0x000006DE
_0802A940:
	ldr r1, [r5]
	ldr r4, _0802A960 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A94E
	b _0802AAD2
_0802A94E:
	movs r0, #0x64
	strh r0, [r1, #0x28]
	adds r1, #0x72
	movs r0, #0xf
	strb r0, [r1]
	movs r0, #8
	bl sub_19B64
	b _0802AAD2
	.align 2, 0
_0802A960: .4byte 0x000006DE
_0802A964:
	ldr r1, [r5]
	ldr r2, _0802A9A0 @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A972
	b _0802AAD2
_0802A972:
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0802A982
	b _0802AAD2
_0802A982:
	movs r4, #0xba
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	ldr r2, _0802A9A4 @ =0x0000016F
	adds r0, r1, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	b _0802AAD2
	.align 2, 0
_0802A9A0: .4byte 0x000006DE
_0802A9A4: .4byte 0x0000016F
_0802A9A8:
	ldr r2, [r5]
	ldr r4, _0802A9D8 @ =0x000006DE
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A9B6
	b _0802AAD2
_0802A9B6:
	movs r0, #0xc2
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x64
	strh r0, [r1]
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r4, _0802A9DC @ =0x00000306
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A9D8: .4byte 0x000006DE
_0802A9DC: .4byte 0x00000306
_0802A9E0:
	ldr r1, [r5]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0802A9F0
	ldr r0, _0802AA1C @ =0x000006DE
	adds r1, r1, r0
	movs r0, #0x51
	strh r0, [r1]
_0802A9F0:
	ldr r1, [r5]
	ldr r2, _0802AA1C @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r3, [r5]
	ldr r4, _0802AA20 @ =0x000006DC
	adds r0, r3, r4
	ldrb r2, [r0]
	subs r2, #0x17
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #6
	str r0, [r3, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA1C: .4byte 0x000006DE
_0802AA20: .4byte 0x000006DC
_0802AA24:
	ldr r0, [r5]
	ldr r1, _0802AA40 @ =0x000006DE
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, #0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0x64
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA40: .4byte 0x000006DE
_0802AA44:
	ldr r0, [r5]
	ldr r2, _0802AA60 @ =0x000006DE
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, #0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA60: .4byte 0x000006DE
_0802AA64:
	ldr r0, [r5]
	ldr r3, _0802AA80 @ =0x000006DE
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, #0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA80: .4byte 0x000006DE
_0802AA84:
	ldr r4, [r5]
	ldr r1, _0802AAB4 @ =0x000006DE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	ldr r2, _0802AAB8 @ =0x0000070E
	adds r1, r4, r2
	ldr r3, _0802AABC @ =0x000006DC
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #0xdd
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x63
	ble _0802AAD2
	movs r0, #0x63
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802AAB4: .4byte 0x000006DE
_0802AAB8: .4byte 0x0000070E
_0802AABC: .4byte 0x000006DC
_0802AAC0:
	ldr r0, [r5]
	ldr r1, _0802AAD8 @ =0x000006DE
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x96
	bne _0802AAD2
	movs r0, #3
	bl sub_19B64
_0802AAD2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AAD8: .4byte 0x000006DE

	thumb_func_start sub_2AADC
sub_2AADC: @ 0x0802AADC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0802AB5C @ =0x020314E0
	ldr r3, [r0]
	ldrb r5, [r3, #0x1e]
	cmp r5, #0
	beq _0802AAF6
	bl sub_2C518
_0802AAF6:
	ldr r0, _0802AB60 @ =0x000005A6
	adds r4, r3, r0
	ldrh r1, [r4]
	ldr r6, _0802AB64 @ =0x086ACF38
	adds r0, #2
	adds r2, r3, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _0802AB38
	adds r0, r1, #1
	strh r0, [r4]
	ldrh r1, [r4]
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _0802AB38
	strh r5, [r4]
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x22
	bgt _0802AB38
	adds r0, r1, #1
	strb r0, [r2]
_0802AB38:
	ldr r4, _0802AB5C @ =0x020314E0
	ldr r0, [r4]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x22
	bls _0802AB50
	bl _0802C4D2
_0802AB50:
	lsls r0, r0, #2
	ldr r1, _0802AB68 @ =_0802AB6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802AB5C: .4byte 0x020314E0
_0802AB60: .4byte 0x000005A6
_0802AB64: .4byte 0x086ACF38
_0802AB68: .4byte _0802AB6C
_0802AB6C: @ jump table
	.4byte _0802ABF8 @ case 0
	.4byte _0802AD18 @ case 1
	.4byte _0802ADB4 @ case 2
	.4byte _0802AE98 @ case 3
	.4byte _0802AF6C @ case 4
	.4byte _0802AF6C @ case 5
	.4byte _0802AF6C @ case 6
	.4byte _0802AF6C @ case 7
	.4byte _0802AF6C @ case 8
	.4byte _0802AF6C @ case 9
	.4byte _0802AF6C @ case 10
	.4byte _0802B200 @ case 11
	.4byte _0802B33C @ case 12
	.4byte _0802B42C @ case 13
	.4byte _0802B460 @ case 14
	.4byte _0802B4B8 @ case 15
	.4byte _0802B510 @ case 16
	.4byte _0802B574 @ case 17
	.4byte _0802B574 @ case 18
	.4byte _0802B574 @ case 19
	.4byte _0802B574 @ case 20
	.4byte _0802B574 @ case 21
	.4byte _0802B574 @ case 22
	.4byte _0802B574 @ case 23
	.4byte _0802B574 @ case 24
	.4byte _0802B574 @ case 25
	.4byte _0802B8D0 @ case 26
	.4byte _0802B574 @ case 27
	.4byte _0802B574 @ case 28
	.4byte _0802BA7C @ case 29
	.4byte _0802BB4C @ case 30
	.4byte _0802BE94 @ case 31
	.4byte _0802BEB4 @ case 32
	.4byte _0802C04C @ case 33
	.4byte _0802C314 @ case 34
_0802ABF8:
	ldr r0, _0802ACDC @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	ldrb r0, [r0, #4]
	cmp r0, #1
	bhi _0802AC20
	ldr r2, _0802ACE0 @ =0x020314E0
	ldr r0, [r2]
	movs r3, #0x13
	ldrsb r3, [r0, r3]
	cmp r3, #4
	beq _0802AC16
	cmp r3, #8
	bne _0802AC20
_0802AC16:
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r1, r0, r3
	movs r0, #1
	strb r0, [r1]
_0802AC20:
	ldr r7, _0802ACE0 @ =0x020314E0
	ldr r0, [r7]
	movs r4, #1
	mov r8, r4
	mov r1, r8
	strb r1, [r0, #0x1f]
	ldr r6, [r7]
	ldr r2, _0802ACE4 @ =0x0000132C
	adds r4, r6, r2
	ldr r5, [r4]
	movs r3, #0x30
	ldrsh r0, [r5, r3]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r5, #0x30]
	ldr r5, [r4]
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r5, #0x32]
	ldr r1, [r4]
	movs r3, #0x30
	ldrsh r2, [r1, r3]
	ldr r0, [r1, #0x34]
	adds r0, r0, r2
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r4, #0x32
	ldrsh r2, [r1, r4]
	ldr r0, [r1, #0x38]
	adds r0, r0, r2
	str r0, [r1, #0x38]
	adds r6, #0xe4
	movs r0, #9
	strb r0, [r6]
	ldr r1, _0802ACE8 @ =0x040000D4
	ldr r0, _0802ACEC @ =0x081428D4
	str r0, [r1]
	ldr r0, _0802ACF0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802ACF4 @ =0x80000E00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, [r7]
	ldr r0, _0802ACF8 @ =0x000005F6
	adds r3, r2, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #9
	ldr r5, _0802ACFC @ =0x08138014
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0802AD00 @ =0x060164C0
	str r0, [r1, #4]
	ldr r4, _0802AD04 @ =0x80000040
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r0, #4
	lsls r0, r0, #6
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0802AD08 @ =0x06016760
	str r0, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0802AD0C @ =0x000005F7
	adds r2, r2, r1
	mov r3, r8
	strb r3, [r2]
	ldr r0, [r7]
	ldr r4, _0802AD10 @ =0x000005A6
	adds r0, r0, r4
	ldrh r4, [r0]
	cmp r4, #1
	beq _0802ACCA
	bl _0802C4D2
_0802ACCA:
	ldr r0, _0802AD14 @ =0x02032EE0
	bl m4aMPlayStop
	ldr r0, [r7]
	adds r0, #0x71
	strb r4, [r0]
	bl _0802C4D2
	.align 2, 0
_0802ACDC: .4byte gMain
_0802ACE0: .4byte 0x020314E0
_0802ACE4: .4byte 0x0000132C
_0802ACE8: .4byte 0x040000D4
_0802ACEC: .4byte 0x081428D4
_0802ACF0: .4byte 0x06015800
_0802ACF4: .4byte 0x80000E00
_0802ACF8: .4byte 0x000005F6
_0802ACFC: .4byte 0x08138014
_0802AD00: .4byte 0x060164C0
_0802AD04: .4byte 0x80000040
_0802AD08: .4byte 0x06016760
_0802AD0C: .4byte 0x000005F7
_0802AD10: .4byte 0x000005A6
_0802AD14: .4byte 0x02032EE0
_0802AD18:
	ldr r4, _0802AD94 @ =0x020314E0
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0802AD48
	movs r7, #0xe4
	lsls r7, r7, #3
	adds r1, r1, r7
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0802AD98 @ =0x0000071D
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _0802AD9C @ =0x0000071E
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0802ADA0 @ =0x0000071F
	adds r0, r0, r3
	strb r1, [r0]
_0802AD48:
	ldr r0, [r4]
	ldr r2, _0802ADA4 @ =0x0000132C
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0
	strb r1, [r0, #1]
	ldr r4, [r4]
	adds r2, r4, r2
	ldr r0, [r2]
	strh r1, [r0, #0x30]
	ldr r0, [r2]
	strh r1, [r0, #0x32]
	ldr r1, [r2]
	movs r7, #0x30
	ldrsh r3, [r1, r7]
	ldr r0, [r1, #0x34]
	adds r0, r0, r3
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	ldr r0, [r1, #0x38]
	adds r0, r0, r2
	str r0, [r1, #0x38]
	ldr r1, _0802ADA8 @ =0x000005A6
	adds r4, r4, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _0802AD86
	bl _0802C4D2
_0802AD86:
	ldr r0, _0802ADAC @ =0x02032F20
	ldr r1, _0802ADB0 @ =0x0869FCE4
	bl MPlayStart
	bl _0802C4D2
	.align 2, 0
_0802AD94: .4byte 0x020314E0
_0802AD98: .4byte 0x0000071D
_0802AD9C: .4byte 0x0000071E
_0802ADA0: .4byte 0x0000071F
_0802ADA4: .4byte 0x0000132C
_0802ADA8: .4byte 0x000005A6
_0802ADAC: .4byte 0x02032F20
_0802ADB0: .4byte 0x0869FCE4
_0802ADB4:
	ldr r2, _0802AE14 @ =0x040000D4
	ldr r3, _0802AE18 @ =0x020314E0
	ldr r0, [r3]
	ldr r4, _0802AE1C @ =0x000005F6
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #4
	lsls r0, r0, #5
	ldr r1, _0802AE20 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802AE24 @ =0x05000220
	str r0, [r2, #4]
	ldr r5, _0802AE28 @ =0x80000010
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r4, _0802AE2C @ =gMain
	ldrh r0, [r4, #0x3c]
	movs r0, #4
	strh r0, [r4, #0x3c]
	ldr r0, [r3]
	ldr r7, _0802AE30 @ =0x000005A6
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #1
	bhi _0802ADF0
	bl _0802C4D2
_0802ADF0:
	ldr r1, _0802AE34 @ =0x02031520
	ldr r3, [r1, #0x30]
	str r3, [r2]
	ldr r0, _0802AE38 @ =0x05000200
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r4, #4]
	adds r4, r1, #0
	cmp r0, #1
	bne _0802AE44
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802AE3C @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802AE40 @ =0x80000060
	b _0802AE50
	.align 2, 0
_0802AE14: .4byte 0x040000D4
_0802AE18: .4byte 0x020314E0
_0802AE1C: .4byte 0x000005F6
_0802AE20: .4byte 0x08137E14
_0802AE24: .4byte 0x05000220
_0802AE28: .4byte 0x80000010
_0802AE2C: .4byte gMain
_0802AE30: .4byte 0x000005A6
_0802AE34: .4byte 0x02031520
_0802AE38: .4byte 0x05000200
_0802AE3C: .4byte 0x05000240
_0802AE40: .4byte 0x80000060
_0802AE44:
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802AE80 @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802AE84 @ =0x80000070
_0802AE50:
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _0802AE88 @ =0x040000D4
	ldr r0, [r4, #0x30]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0802AE8C @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0802AE90 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0802AE94 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x70
	strb r1, [r0]
	bl _0802C4D2
	.align 2, 0
_0802AE80: .4byte 0x05000240
_0802AE84: .4byte 0x80000070
_0802AE88: .4byte 0x040000D4
_0802AE8C: .4byte 0x05000340
_0802AE90: .4byte 0x80000030
_0802AE94: .4byte 0x020314E0
_0802AE98:
	ldr r4, _0802AED8 @ =gMain
	ldrh r0, [r4, #0x3c]
	movs r0, #7
	strh r0, [r4, #0x3c]
	ldr r3, _0802AEDC @ =0x020314E0
	ldr r0, [r3]
	ldr r7, _0802AEE0 @ =0x000005A6
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #1
	bls _0802AF34
	ldr r2, _0802AEE4 @ =0x040000D4
	ldr r1, _0802AEE8 @ =0x02031520
	ldr r3, [r1, #0x34]
	str r3, [r2]
	ldr r0, _0802AEEC @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _0802AEF0 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r4, #4]
	adds r4, r1, #0
	cmp r0, #1
	bne _0802AEFC
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802AEF4 @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802AEF8 @ =0x80000060
	b _0802AF08
	.align 2, 0
_0802AED8: .4byte gMain
_0802AEDC: .4byte 0x020314E0
_0802AEE0: .4byte 0x000005A6
_0802AEE4: .4byte 0x040000D4
_0802AEE8: .4byte 0x02031520
_0802AEEC: .4byte 0x05000200
_0802AEF0: .4byte 0x80000010
_0802AEF4: .4byte 0x05000240
_0802AEF8: .4byte 0x80000060
_0802AEFC:
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802AF48 @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802AF4C @ =0x80000070
_0802AF08:
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _0802AF50 @ =0x040000D4
	ldr r0, [r4, #0x34]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0802AF54 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0802AF58 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0802AF5C @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x6f
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x70
	movs r1, #1
	strb r1, [r0]
_0802AF34:
	ldr r1, _0802AF50 @ =0x040000D4
	ldr r0, _0802AF60 @ =0x08137F14
	str r0, [r1]
	ldr r0, _0802AF64 @ =0x05000220
	str r0, [r1, #4]
	ldr r0, _0802AF68 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl _0802C4D2
	.align 2, 0
_0802AF48: .4byte 0x05000240
_0802AF4C: .4byte 0x80000070
_0802AF50: .4byte 0x040000D4
_0802AF54: .4byte 0x05000340
_0802AF58: .4byte 0x80000030
_0802AF5C: .4byte 0x020314E0
_0802AF60: .4byte 0x08137F14
_0802AF64: .4byte 0x05000220
_0802AF68: .4byte 0x80000010
_0802AF6C:
	ldr r3, _0802AFDC @ =0x020314E0
	ldr r4, [r3]
	movs r7, #0xb5
	lsls r7, r7, #3
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq _0802AF8C
	cmp r0, #6
	bne _0802AFFC
_0802AF8C:
	ldr r0, _0802AFE0 @ =gMain
	ldrb r1, [r0, #4]
	mov ip, r0
	cmp r1, #3
	bhi _0802AFC2
	movs r1, #0x13
	ldrsb r1, [r4, r1]
	cmp r1, #4
	bne _0802AFA6
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #9
	beq _0802AFB2
_0802AFA6:
	cmp r1, #8
	bne _0802AFC2
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _0802AFC2
_0802AFB2:
	ldr r1, _0802AFE4 @ =0x040000D4
	ldr r0, _0802AFE8 @ =0x02030710
	str r0, [r1]
	ldr r0, _0802AFEC @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0802AFF0 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802AFC2:
	ldr r1, _0802AFE4 @ =0x040000D4
	ldr r0, _0802AFF4 @ =0x08137F14
	str r0, [r1]
	ldr r0, _0802AFF8 @ =0x05000220
	str r0, [r1, #4]
	ldr r0, _0802AFF0 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, ip
	ldrh r0, [r1, #0x3c]
	movs r0, #6
	strh r0, [r1, #0x3c]
	b _0802B026
	.align 2, 0
_0802AFDC: .4byte 0x020314E0
_0802AFE0: .4byte gMain
_0802AFE4: .4byte 0x040000D4
_0802AFE8: .4byte 0x02030710
_0802AFEC: .4byte 0x050003A0
_0802AFF0: .4byte 0x80000010
_0802AFF4: .4byte 0x08137F14
_0802AFF8: .4byte 0x05000220
_0802AFFC:
	ldr r2, _0802B0EC @ =0x040000D4
	ldr r7, _0802B0F0 @ =0x000005F6
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #4
	lsls r0, r0, #5
	ldr r1, _0802B0F4 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802B0F8 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802B0FC @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0802B100 @ =gMain
	ldrh r1, [r0, #0x3c]
	movs r1, #7
	strh r1, [r0, #0x3c]
	mov ip, r0
_0802B026:
	mov r1, ip
	ldr r0, [r1, #0x44]
	ldr r6, [r0, #0xc]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802B034
	b _0802B1AC
_0802B034:
	ldr r4, _0802B104 @ =0x020314E0
	ldr r2, [r4]
	ldr r7, _0802B108 @ =0x0000132C
	adds r1, r2, r7
	ldr r0, [r1]
	ldrh r0, [r0, #0x24]
	strh r0, [r6, #2]
	ldr r0, [r1]
	ldrh r0, [r0, #0x26]
	strh r0, [r6, #4]
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #5
	bne _0802B11C
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r1, _0802B10C @ =gOamBuffer
	mov r8, r1
	ldr r2, _0802B110 @ =0x081B0FE4
	mov sb, r2
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sl, r0
_0802B066:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r4, r8
	adds r2, r0, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, sb
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802B114 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldr r0, _0802B118 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B066
	b _0802B1AC
	.align 2, 0
_0802B0EC: .4byte 0x040000D4
_0802B0F0: .4byte 0x000005F6
_0802B0F4: .4byte 0x08137E14
_0802B0F8: .4byte 0x05000220
_0802B0FC: .4byte 0x80000010
_0802B100: .4byte gMain
_0802B104: .4byte 0x020314E0
_0802B108: .4byte 0x0000132C
_0802B10C: .4byte gOamBuffer
_0802B110: .4byte 0x081B0FE4
_0802B114: .4byte 0x000001FF
_0802B118: .4byte 0xFFFFFE00
_0802B11C:
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r3, _0802B1E8 @ =gOamBuffer
	mov sb, r3
	ldr r4, _0802B1EC @ =0x081B0FE4
	mov r8, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	str r0, [sp]
	ldr r7, _0802B1F0 @ =0xFFFFFE00
	mov sl, r7
_0802B136:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, sb
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r4, [sp]
	adds r0, r0, r4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802B1F4 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B136
_0802B1AC:
	mov r3, ip
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0xc]
	movs r0, #1
	strh r0, [r1]
	ldr r0, _0802B1F8 @ =0x020314E0
	ldr r1, [r0]
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	beq _0802B1CE
	bl _0802C4D2
_0802B1CE:
	ldr r7, _0802B1FC @ =0x000005A6
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #3
	beq _0802B1DC
	bl _0802C4D2
_0802B1DC:
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0xc]
	movs r0, #0
	strh r0, [r1]
	bl _0802C4D2
	.align 2, 0
_0802B1E8: .4byte gOamBuffer
_0802B1EC: .4byte 0x081B0FE4
_0802B1F0: .4byte 0xFFFFFE00
_0802B1F4: .4byte 0x000001FF
_0802B1F8: .4byte 0x020314E0
_0802B1FC: .4byte 0x000005A6
_0802B200:
	ldr r2, _0802B29C @ =0x040000D4
	ldr r6, _0802B2A0 @ =0x020314E0
	ldr r3, [r6]
	ldr r1, _0802B2A4 @ =0x000005F6
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #4
	lsls r0, r0, #5
	ldr r1, _0802B2A8 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802B2AC @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802B2B0 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r2, r2, #8
	ldr r4, _0802B2B4 @ =0x0000132C
	adds r0, r3, r4
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldr r7, _0802B2B8 @ =0x0000028A
	adds r0, r3, r7
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, [r1, #0x38]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r2, #0x10
	orrs r7, r0
	ldr r5, _0802B2BC @ =0x000005AC
	adds r3, r3, r5
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r4, r7, #0x10
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r0, #2
	bl Sqrt
	ldr r1, [r6]
	adds r1, r1, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	str r0, [r1]
	rsbs r0, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0
	bl ArcTan2
	ldr r6, [r6]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _0802B2C0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #3
	bls _0802B2C8
	ldr r3, _0802B2C4 @ =0x00000389
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	b _0802B2F4
	.align 2, 0
_0802B29C: .4byte 0x040000D4
_0802B2A0: .4byte 0x020314E0
_0802B2A4: .4byte 0x000005F6
_0802B2A8: .4byte 0x08137E14
_0802B2AC: .4byte 0x05000220
_0802B2B0: .4byte 0x80000010
_0802B2B4: .4byte 0x0000132C
_0802B2B8: .4byte 0x0000028A
_0802B2BC: .4byte 0x000005AC
_0802B2C0: .4byte gMain
_0802B2C4: .4byte 0x00000389
_0802B2C8:
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	cmp r1, #4
	bne _0802B2D8
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	cmp r0, #9
	beq _0802B2E4
_0802B2D8:
	cmp r1, #8
	bne _0802B2F4
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bne _0802B2F4
_0802B2E4:
	ldr r1, _0802B324 @ =0x040000D4
	ldr r0, _0802B328 @ =0x020306D0
	str r0, [r1]
	ldr r0, _0802B32C @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0802B330 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802B2F4:
	movs r5, #0
	ldr r7, _0802B334 @ =0x020314E0
	ldr r6, _0802B338 @ =0x0000132C
_0802B2FA:
	ldr r4, [r7]
	adds r4, r4, r6
	ldr r0, [r4]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #2
	adds r3, r0, r2
	ldrh r0, [r0, #0x10]
	strh r0, [r3, #0x14]
	ldr r0, [r4]
	adds r2, r0, r2
	ldrh r0, [r0, #0x12]
	strh r0, [r2, #0x16]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _0802B2FA
	bl _0802C4D2
	.align 2, 0
_0802B324: .4byte 0x040000D4
_0802B328: .4byte 0x020306D0
_0802B32C: .4byte 0x050003A0
_0802B330: .4byte 0x80000010
_0802B334: .4byte 0x020314E0
_0802B338: .4byte 0x0000132C
_0802B33C:
	ldr r4, _0802B410 @ =0x020314E0
	mov sl, r4
	ldr r5, [r4]
	ldr r7, _0802B414 @ =0x000005A6
	adds r0, r5, r7
	ldrh r0, [r0]
	movs r4, #0x63
	subs r4, r4, r0
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r6, r5, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0xd
	movs r1, #0x64
	bl __divsi3
	ldr r1, _0802B418 @ =0xFFFFE000
	adds r2, r1, #0
	adds r0, r0, r2
	ldrh r1, [r6]
	subs r1, r1, r0
	strh r1, [r6]
	ldr r7, _0802B41C @ =0x0000132C
	adds r1, r5, r7
	ldr r0, [r1]
	ldrh r3, [r0, #0xa]
	adds r2, r2, r3
	strh r2, [r0, #0xa]
	subs r4, #0x14
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	cmp r4, #0
	bge _0802B388
	movs r5, #0
	ldr r1, [r1]
	movs r0, #0
	strb r0, [r1]
_0802B388:
	mov r0, sl
	ldr r4, [r0]
	ldr r2, _0802B420 @ =0x000005AC
	adds r1, r4, r2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r1]
	muls r0, r1, r0
	movs r1, #0x50
	bl __divsi3
	mov sb, r0
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r4, r4, r3
	ldrh r0, [r4]
	bl sub_C74
	mov r4, sl
	ldr r5, [r4]
	adds r1, r5, r7
	ldr r6, [r1]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r3, #0
	ldrsh r4, [r1, r3]
	lsls r4, r4, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r2, _0802B424 @ =0x00004E20
	mov r8, r2
	mov r1, r8
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x34]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r5, r5, r3
	ldrh r0, [r5]
	bl sub_C24
	mov r4, sl
	ldr r1, [r4]
	adds r2, r1, r7
	ldr r5, [r2]
	ldr r7, _0802B428 @ =0x0000028A
	adds r1, r1, r7
	movs r2, #0
	ldrsh r4, [r1, r2]
	lsls r4, r4, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	mov r1, r8
	bl __divsi3
	subs r4, r4, r0
	str r4, [r5, #0x38]
	bl _0802C4D2
	.align 2, 0
_0802B410: .4byte 0x020314E0
_0802B414: .4byte 0x000005A6
_0802B418: .4byte 0xFFFFE000
_0802B41C: .4byte 0x0000132C
_0802B420: .4byte 0x000005AC
_0802B424: .4byte 0x00004E20
_0802B428: .4byte 0x0000028A
_0802B42C:
	ldr r5, _0802B454 @ =0x020314E0
	ldr r1, [r5]
	ldr r4, _0802B458 @ =0x0000132C
	adds r0, r1, r4
	ldr r2, [r0]
	movs r3, #0
	movs r0, #0
	strh r0, [r2, #6]
	adds r1, #0x71
	strb r3, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r4, _0802B45C @ =0xFFFFE000
	adds r0, r4, #0
	ldrh r7, [r1, #0xa]
	adds r0, r0, r7
	strh r0, [r1, #0xa]
	bl _0802C4D2
	.align 2, 0
_0802B454: .4byte 0x020314E0
_0802B458: .4byte 0x0000132C
_0802B45C: .4byte 0xFFFFE000
_0802B460:
	ldr r2, _0802B498 @ =0x040000D4
	ldr r0, _0802B49C @ =0x020314E0
	ldr r3, [r0]
	ldr r1, _0802B4A0 @ =0x000005F6
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802B4A4 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802B4A8 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802B4AC @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r2, _0802B4B0 @ =0x0000132C
	adds r3, r3, r2
	ldr r1, [r3]
	ldr r3, _0802B4B4 @ =0xFFFFE000
	adds r0, r3, #0
	ldrh r4, [r1, #0xa]
	adds r0, r0, r4
	strh r0, [r1, #0xa]
	bl _0802C4D2
	.align 2, 0
_0802B498: .4byte 0x040000D4
_0802B49C: .4byte 0x020314E0
_0802B4A0: .4byte 0x000005F6
_0802B4A4: .4byte 0x08137E14
_0802B4A8: .4byte 0x05000220
_0802B4AC: .4byte 0x80000010
_0802B4B0: .4byte 0x0000132C
_0802B4B4: .4byte 0xFFFFE000
_0802B4B8:
	ldr r2, _0802B4F0 @ =0x040000D4
	ldr r0, _0802B4F4 @ =0x020314E0
	ldr r3, [r0]
	ldr r7, _0802B4F8 @ =0x000005F6
	adds r0, r3, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #4
	lsls r0, r0, #5
	ldr r1, _0802B4FC @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802B500 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802B504 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0802B508 @ =0x0000132C
	adds r3, r3, r0
	ldr r1, [r3]
	ldr r2, _0802B50C @ =0xFFFFE000
	adds r0, r2, #0
	ldrh r3, [r1, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #0xa]
	bl _0802C4D2
	.align 2, 0
_0802B4F0: .4byte 0x040000D4
_0802B4F4: .4byte 0x020314E0
_0802B4F8: .4byte 0x000005F6
_0802B4FC: .4byte 0x08137E14
_0802B500: .4byte 0x05000220
_0802B504: .4byte 0x80000010
_0802B508: .4byte 0x0000132C
_0802B50C: .4byte 0xFFFFE000
_0802B510:
	ldr r4, _0802B554 @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0802B558 @ =0x000005A6
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802B524
	movs r0, #0x9b
	bl m4aSongNumStart
_0802B524:
	ldr r2, _0802B55C @ =0x040000D4
	ldr r3, [r4]
	ldr r1, _0802B560 @ =0x000005F6
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802B564 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802B568 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802B56C @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r2, _0802B570 @ =0x0000132C
	adds r3, r3, r2
	ldr r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #7
	strh r0, [r1, #0xa]
	bl _0802C4D2
	.align 2, 0
_0802B554: .4byte 0x020314E0
_0802B558: .4byte 0x000005A6
_0802B55C: .4byte 0x040000D4
_0802B560: .4byte 0x000005F6
_0802B564: .4byte 0x08137E14
_0802B568: .4byte 0x05000220
_0802B56C: .4byte 0x80000010
_0802B570: .4byte 0x0000132C
_0802B574:
	ldr r0, _0802B664 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0xc]
	ldrh r1, [r6]
	mov ip, r0
	cmp r1, #0
	bne _0802B584
	b _0802B714
_0802B584:
	ldr r3, _0802B668 @ =0x020314E0
	ldr r0, [r3]
	ldr r1, _0802B66C @ =0x0000132C
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #1
	strb r0, [r2]
	ldr r2, [r3]
	adds r1, r2, r1
	ldr r0, [r1]
	ldrh r0, [r0, #0x24]
	strh r0, [r6, #2]
	ldr r0, [r1]
	ldrh r0, [r0, #0x26]
	strh r0, [r6, #4]
	ldr r1, _0802B670 @ =0x086ACFF4
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #0x11
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #7
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #5
	bne _0802B684
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r7, _0802B674 @ =gOamBuffer
	mov r8, r7
	ldr r1, _0802B678 @ =0x081B0FE4
	mov sb, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sl, r0
_0802B5DE:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r4, r8
	adds r2, r0, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, sb
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802B67C @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldr r0, _0802B680 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B5DE
	b _0802B714
	.align 2, 0
_0802B664: .4byte gMain
_0802B668: .4byte 0x020314E0
_0802B66C: .4byte 0x0000132C
_0802B670: .4byte 0x086ACFF4
_0802B674: .4byte gOamBuffer
_0802B678: .4byte 0x081B0FE4
_0802B67C: .4byte 0x000001FF
_0802B680: .4byte 0xFFFFFE00
_0802B684:
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r3, _0802B75C @ =gOamBuffer
	mov sb, r3
	ldr r4, _0802B760 @ =0x081B0FE4
	mov r8, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	str r0, [sp]
	ldr r7, _0802B764 @ =0xFFFFFE00
	mov sl, r7
_0802B69E:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, sb
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r4, [sp]
	adds r0, r0, r4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r4
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802B768 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B69E
_0802B714:
	mov r3, ip
	ldr r0, [r3, #0x44]
	ldr r1, [r0, #0xc]
	movs r0, #1
	strh r0, [r1]
	ldr r4, _0802B76C @ =0x020314E0
	ldr r1, [r4]
	movs r7, #0xb5
	lsls r7, r7, #3
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x12
	beq _0802B73A
	cmp r0, #0x14
	beq _0802B73A
	cmp r0, #0x15
	bne _0802B7AC
_0802B73A:
	ldr r1, _0802B76C @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _0802B770 @ =0x000005A9
	adds r0, r0, r2
	movs r1, #0xc8
	strb r1, [r0]
	mov r3, ip
	ldrb r0, [r3, #4]
	cmp r0, #3
	bls _0802B778
	ldr r4, _0802B76C @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0802B774 @ =0x00000389
	adds r0, r0, r7
	movs r1, #1
	strb r1, [r0]
	b _0802B7F8
	.align 2, 0
_0802B75C: .4byte gOamBuffer
_0802B760: .4byte 0x081B0FE4
_0802B764: .4byte 0xFFFFFE00
_0802B768: .4byte 0x000001FF
_0802B76C: .4byte 0x020314E0
_0802B770: .4byte 0x000005A9
_0802B774: .4byte 0x00000389
_0802B778:
	ldr r0, _0802B7A0 @ =0x020314E0
	ldr r1, [r0]
	movs r2, #0x13
	ldrsb r2, [r1, r2]
	cmp r2, #4
	bne _0802B78C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #9
	beq _0802B798
_0802B78C:
	cmp r2, #8
	bne _0802B7F8
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0802B7F8
_0802B798:
	ldr r1, _0802B7A4 @ =0x040000D4
	ldr r0, _0802B7A8 @ =0x020306F0
	b _0802B7EC
	.align 2, 0
_0802B7A0: .4byte 0x020314E0
_0802B7A4: .4byte 0x040000D4
_0802B7A8: .4byte 0x020306F0
_0802B7AC:
	cmp r0, #0x13
	beq _0802B7B4
	cmp r0, #0x16
	bne _0802B7F8
_0802B7B4:
	mov r2, ip
	ldrb r0, [r2, #4]
	cmp r0, #3
	bls _0802B7CC
	ldr r3, _0802B7C8 @ =0x00000389
	adds r1, r1, r3
	movs r0, #3
	strb r0, [r1]
	b _0802B7F8
	.align 2, 0
_0802B7C8: .4byte 0x00000389
_0802B7CC:
	movs r2, #0x13
	ldrsb r2, [r1, r2]
	cmp r2, #4
	bne _0802B7DC
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #9
	beq _0802B7E8
_0802B7DC:
	cmp r2, #8
	bne _0802B7F8
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0802B7F8
_0802B7E8:
	ldr r1, _0802B820 @ =0x040000D4
	ldr r0, _0802B824 @ =0x02030730
_0802B7EC:
	str r0, [r1]
	ldr r0, _0802B828 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0802B82C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802B7F8:
	ldr r4, _0802B830 @ =0x020314E0
	ldr r1, [r4]
	movs r7, #0xb5
	lsls r7, r7, #3
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _0802B880
	mov r2, ip
	ldrb r0, [r2, #4]
	cmp r0, #3
	bls _0802B838
	ldr r3, _0802B834 @ =0x00000389
	adds r1, r1, r3
	movs r0, #0xa
	strb r0, [r1]
	b _0802B880
	.align 2, 0
_0802B820: .4byte 0x040000D4
_0802B824: .4byte 0x02030730
_0802B828: .4byte 0x050003A0
_0802B82C: .4byte 0x80000010
_0802B830: .4byte 0x020314E0
_0802B834: .4byte 0x00000389
_0802B838:
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0802B85A
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #9
	bne _0802B85A
	bl sub_28E2C
	ldr r0, [r4]
	ldr r4, _0802B8C4 @ =0x000005F2
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	bl m4aMPlayAllStop
_0802B85A:
	ldr r4, _0802B8C8 @ =0x020314E0
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bne _0802B880
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0802B880
	bl sub_292A0
	ldr r0, [r4]
	ldr r7, _0802B8C4 @ =0x000005F2
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0]
	bl m4aMPlayAllStop
_0802B880:
	ldr r5, _0802B8C8 @ =0x020314E0
	ldr r1, [r5]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1c
	beq _0802B898
	bl _0802C4D2
_0802B898:
	ldr r4, _0802B8CC @ =0x000005A6
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802B8AC
	bl m4aMPlayAllStop
	movs r0, #8
	bl sub_11B0
_0802B8AC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	beq _0802B8BA
	bl _0802C4D2
_0802B8BA:
	movs r0, #0x9c
	bl m4aSongNumStart
	bl _0802C4D2
	.align 2, 0
_0802B8C4: .4byte 0x000005F2
_0802B8C8: .4byte 0x020314E0
_0802B8CC: .4byte 0x000005A6
_0802B8D0:
	ldr r0, _0802B9B8 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r6, [r0, #0xc]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802B8E0
	bl _0802C4D2
_0802B8E0:
	ldr r3, _0802B9BC @ =0x020314E0
	ldr r2, [r3]
	ldr r4, _0802B9C0 @ =0x0000132C
	adds r1, r2, r4
	ldr r0, [r1]
	ldrh r0, [r0, #0x24]
	strh r0, [r6, #2]
	ldr r0, [r1]
	ldrh r0, [r0, #0x26]
	strh r0, [r6, #4]
	ldr r1, _0802B9C4 @ =0x086ACFF4
	movs r7, #0xb5
	lsls r7, r7, #3
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #0x11
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #7
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #5
	bne _0802B9D8
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r1, _0802B9C8 @ =gOamBuffer
	mov r8, r1
	ldr r2, _0802B9CC @ =0x081B0FE4
	mov sb, r2
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sl, r0
_0802B930:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r4, r8
	adds r2, r0, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, sb
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802B9D0 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldr r0, _0802B9D4 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, r8
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B930
	bl _0802C4D2
	.align 2, 0
_0802B9B8: .4byte gMain
_0802B9BC: .4byte 0x020314E0
_0802B9C0: .4byte 0x0000132C
_0802B9C4: .4byte 0x086ACFF4
_0802B9C8: .4byte gOamBuffer
_0802B9CC: .4byte 0x081B0FE4
_0802B9D0: .4byte 0x000001FF
_0802B9D4: .4byte 0xFFFFFE00
_0802B9D8:
	movs r5, #0
	lsls r0, r3, #0x10
	ldr r3, _0802BA6C @ =gOamBuffer
	mov sb, r3
	ldr r4, _0802BA70 @ =0x081B0FE4
	mov r8, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov ip, r0
	ldr r7, _0802BA74 @ =0xFFFFFE00
	mov sl, r7
_0802B9F2:
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, sb
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, ip
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, ip
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802BA78 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0xf
	ble _0802B9F2
	bl _0802C4D2
	.align 2, 0
_0802BA6C: .4byte gOamBuffer
_0802BA70: .4byte 0x081B0FE4
_0802BA74: .4byte 0xFFFFFE00
_0802BA78: .4byte 0x000001FF
_0802BA7C:
	ldr r3, _0802BB28 @ =gMain
	ldrh r0, [r3, #0x3c]
	movs r0, #4
	strh r0, [r3, #0x3c]
	ldr r2, _0802BB2C @ =0x040000D4
	ldr r4, _0802BB30 @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0802BB34 @ =0x000005F6
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802BB38 @ =0x08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802BB3C @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802BB40 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #0x44]
	ldr r6, [r0, #0xc]
	ldrh r0, [r6]
	mov ip, r3
	cmp r0, #0
	beq _0802BAD6
	movs r5, #0
	ldr r3, _0802BB44 @ =gOamBuffer
	movs r2, #0xbe
_0802BAB8:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	adds r1, #8
	adds r5, r6, r1
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r3
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0802BAB8
_0802BAD6:
	mov r1, ip
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0xc]
	movs r5, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0802BB30 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _0802BB48 @ =0x0000132C
	adds r0, r0, r2
	ldr r0, [r0]
	strb r5, [r0]
	ldr r4, [r1]
	adds r2, r4, r2
	ldr r1, [r2]
	movs r0, #0xff
	lsls r0, r0, #8
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	movs r0, #0x28
	strh r0, [r1, #0x30]
	ldr r1, [r2]
	adds r0, #0xd8
	strh r0, [r1, #6]
	ldr r1, [r2]
	movs r7, #0x32
	ldrsh r3, [r1, r7]
	ldr r0, [r1, #0x38]
	adds r0, r0, r3
	str r0, [r1, #0x38]
	ldr r1, [r2]
	movs r0, #0x30
	ldrsh r2, [r1, r0]
	ldr r0, [r1, #0x34]
	adds r0, r0, r2
	str r0, [r1, #0x34]
	adds r4, #0xe4
	strb r5, [r4]
	bl _0802C4D2
	.align 2, 0
_0802BB28: .4byte gMain
_0802BB2C: .4byte 0x040000D4
_0802BB30: .4byte 0x020314E0
_0802BB34: .4byte 0x000005F6
_0802BB38: .4byte 0x08137E14
_0802BB3C: .4byte 0x05000220
_0802BB40: .4byte 0x80000010
_0802BB44: .4byte gOamBuffer
_0802BB48: .4byte 0x0000132C
_0802BB4C:
	ldr r1, _0802BB90 @ =0x020314E0
	ldr r0, [r1]
	ldr r2, _0802BB94 @ =0x000005A6
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #7
	bls _0802BB5C
	b _0802BC92
_0802BB5C:
	cmp r0, #3
	bhi _0802BC04
	cmp r0, #0
	beq _0802BB66
	b _0802BC92
_0802BB66:
	ldr r2, _0802BB98 @ =0x040000D4
	ldr r1, _0802BB9C @ =0x02031520
	ldr r3, [r1, #0x30]
	str r3, [r2]
	ldr r0, _0802BBA0 @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _0802BBA4 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0802BBA8 @ =gMain
	ldrb r0, [r0, #4]
	adds r4, r1, #0
	cmp r0, #1
	bne _0802BBB4
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802BBAC @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802BBB0 @ =0x80000060
	b _0802BBC0
	.align 2, 0
_0802BB90: .4byte 0x020314E0
_0802BB94: .4byte 0x000005A6
_0802BB98: .4byte 0x040000D4
_0802BB9C: .4byte 0x02031520
_0802BBA0: .4byte 0x05000200
_0802BBA4: .4byte 0x80000010
_0802BBA8: .4byte gMain
_0802BBAC: .4byte 0x05000240
_0802BBB0: .4byte 0x80000060
_0802BBB4:
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802BBEC @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802BBF0 @ =0x80000070
_0802BBC0:
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _0802BBF4 @ =0x040000D4
	ldr r0, [r4, #0x30]
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0802BBF8 @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0802BBFC @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, _0802BC00 @ =0x020314E0
	ldr r0, [r4]
	adds r0, #0x6f
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x70
	b _0802BC90
	.align 2, 0
_0802BBEC: .4byte 0x05000240
_0802BBF0: .4byte 0x80000070
_0802BBF4: .4byte 0x040000D4
_0802BBF8: .4byte 0x05000340
_0802BBFC: .4byte 0x80000030
_0802BC00: .4byte 0x020314E0
_0802BC04:
	ldr r4, _0802BC3C @ =gMain
	ldrh r0, [r4, #0x3c]
	movs r0, #0
	strh r0, [r4, #0x3c]
	ldrh r0, [r1]
	cmp r0, #4
	bls _0802BC92
	ldr r2, _0802BC40 @ =0x040000D4
	ldr r1, _0802BC44 @ =0x02031520
	ldr r3, [r1, #0x2c]
	str r3, [r2]
	ldr r0, _0802BC48 @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _0802BC4C @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r4, #4]
	adds r4, r1, #0
	cmp r0, #1
	bne _0802BC58
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802BC50 @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802BC54 @ =0x80000060
	b _0802BC64
	.align 2, 0
_0802BC3C: .4byte gMain
_0802BC40: .4byte 0x040000D4
_0802BC44: .4byte 0x02031520
_0802BC48: .4byte 0x05000200
_0802BC4C: .4byte 0x80000010
_0802BC50: .4byte 0x05000240
_0802BC54: .4byte 0x80000060
_0802BC58:
	adds r0, r3, #0
	adds r0, #0x40
	str r0, [r2]
	ldr r0, _0802BDA0 @ =0x05000240
	str r0, [r2, #4]
	ldr r0, _0802BDA4 @ =0x80000070
_0802BC64:
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _0802BDA8 @ =0x040000D4
	ldr r0, [r4, #0x2c]
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r0, r7
	str r0, [r1]
	ldr r0, _0802BDAC @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _0802BDB0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0802BDB4 @ =0x020314E0
	ldr r0, [r1]
	adds r0, #0x6f
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0802BDB4 @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x70
	movs r1, #1
_0802BC90:
	strb r1, [r0]
_0802BC92:
	ldr r3, _0802BDB4 @ =0x020314E0
	ldr r5, [r3]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	cmp r0, #5
	beq _0802BCA4
	cmp r0, #8
	beq _0802BCA4
	b _0802BDC4
_0802BCA4:
	ldr r7, _0802BDB8 @ =0x0000132C
	adds r5, r5, r7
	ldr r1, [r5]
	ldrh r0, [r1, #0x32]
	adds r0, #0x10
	strh r0, [r1, #0x32]
	ldr r1, [r5]
	movs r4, #0x32
	ldrsh r2, [r1, r4]
	ldr r0, [r1, #0x38]
	adds r0, r0, r2
	str r0, [r1, #0x38]
	ldr r6, [r5]
	ldr r4, [r6, #0x34]
	movs r0, #0xec
	lsls r0, r0, #7
	subs r0, r0, r4
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x34]
	ldr r3, [r5]
	ldr r1, [r3, #0x38]
	ldr r0, _0802BDBC @ =0x000139FF
	cmp r1, r0
	ble _0802BD70
	movs r1, #0x32
	ldrsh r0, [r3, r1]
	cmp r0, #0x31
	ble _0802BCE8
	movs r0, #0x9d
	bl m4aSongNumStart
_0802BCE8:
	ldr r2, _0802BDB4 @ =0x020314E0
	ldr r0, [r2]
	adds r0, r0, r7
	ldr r0, [r0]
	movs r3, #0x32
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _0802BD02
	movs r0, #0x9d
	bl m4aSongNumStart
_0802BD02:
	ldr r0, _0802BDB4 @ =0x020314E0
	ldr r4, [r0]
	adds r4, r4, r7
	ldr r1, [r4]
	movs r0, #0x9d
	lsls r0, r0, #9
	str r0, [r1, #0x38]
	ldr r5, [r4]
	movs r2, #0x32
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0x32]
	ldr r5, [r4]
	movs r3, #6
	ldrsh r1, [r5, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	strh r0, [r5, #6]
	ldr r4, [r4]
	ldrh r1, [r4, #6]
	movs r2, #6
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0802BD48
	rsbs r0, r1, #0
	strh r0, [r4, #6]
_0802BD48:
	ldr r3, _0802BDB4 @ =0x020314E0
	ldr r4, [r3]
	adds r4, r4, r7
	ldr r5, [r4]
	movs r7, #0x30
	ldrsh r1, [r5, r7]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	strh r0, [r5, #0x30]
	ldr r4, [r4]
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0802BD70
	rsbs r0, r1, #0
	strh r0, [r4, #0x30]
_0802BD70:
	ldr r3, _0802BDB4 @ =0x020314E0
	ldr r2, [r3]
	ldr r4, _0802BDB8 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	ldrh r1, [r0, #0x32]
	movs r7, #0x32
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bge _0802BD8A
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0802BD8A:
	lsls r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0802BE78
	ldr r0, _0802BDC0 @ =0x000005A6
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _0802BE78
	.align 2, 0
_0802BDA0: .4byte 0x05000240
_0802BDA4: .4byte 0x80000070
_0802BDA8: .4byte 0x040000D4
_0802BDAC: .4byte 0x05000340
_0802BDB0: .4byte 0x80000030
_0802BDB4: .4byte 0x020314E0
_0802BDB8: .4byte 0x0000132C
_0802BDBC: .4byte 0x000139FF
_0802BDC0: .4byte 0x000005A6
_0802BDC4:
	ldr r6, _0802BE88 @ =0x0000132C
	adds r3, r5, r6
	ldr r1, [r3]
	ldrh r0, [r1, #0x32]
	adds r0, #0x10
	strh r0, [r1, #0x32]
	ldr r1, [r3]
	movs r4, #0x32
	ldrsh r2, [r1, r4]
	ldr r0, [r1, #0x38]
	adds r0, r0, r2
	str r0, [r1, #0x38]
	ldr r1, [r3]
	movs r7, #0x30
	ldrsh r2, [r1, r7]
	ldr r0, [r1, #0x34]
	adds r0, r0, r2
	str r0, [r1, #0x34]
	ldr r1, [r3]
	ldr r2, _0802BE8C @ =0x0000028A
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x32
	lsls r0, r0, #8
	ldr r1, [r1, #0x38]
	cmp r1, r0
	blt _0802BE78
	movs r0, #0x9d
	bl m4aSongNumStart
	ldr r4, _0802BE90 @ =0x020314E0
	ldr r0, [r4]
	adds r5, r0, r6
	ldr r1, [r5]
	ldr r7, _0802BE8C @ =0x0000028A
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x32
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r4, [r5]
	movs r3, #0x32
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #4
	subs r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	strh r0, [r4, #0x32]
	ldr r4, [r5]
	movs r7, #6
	ldrsh r1, [r4, r7]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #6]
	ldr r5, [r5]
	ldrh r1, [r5, #6]
	movs r2, #6
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _0802BE50
	rsbs r0, r1, #0
	strh r0, [r5, #6]
_0802BE50:
	ldr r3, _0802BE90 @ =0x020314E0
	ldr r4, [r3]
	adds r4, r4, r6
	ldr r5, [r4]
	movs r7, #0x30
	ldrsh r1, [r5, r7]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	strh r0, [r5, #0x30]
	ldr r1, [r4]
	ldrh r2, [r1, #0x30]
	movs r3, #0x30
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0802BE78
	rsbs r0, r2, #0
	strh r0, [r1, #0x30]
_0802BE78:
	ldr r0, _0802BE90 @ =0x020314E0
	ldr r0, [r0]
	movs r4, #0xb6
	lsls r4, r4, #3
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
	b _0802C4D2
	.align 2, 0
_0802BE88: .4byte 0x0000132C
_0802BE8C: .4byte 0x0000028A
_0802BE90: .4byte 0x020314E0
_0802BE94:
	ldr r0, _0802BEAC @ =0x020314E0
	ldr r1, [r0]
	ldr r7, _0802BEB0 @ =0x0000132C
	adds r1, r1, r7
	ldr r0, [r1]
	movs r2, #0
	strh r2, [r0, #0x30]
	ldr r0, [r1]
	strh r2, [r0, #0x32]
	ldr r0, [r1]
	strh r2, [r0, #6]
	b _0802C4D2
	.align 2, 0
_0802BEAC: .4byte 0x020314E0
_0802BEB0: .4byte 0x0000132C
_0802BEB4:
	ldr r6, _0802BF00 @ =0x020314E0
	ldr r2, [r6]
	ldr r1, _0802BF04 @ =0x000005A6
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0xed
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0xbf
	ble _0802BECE
	b _0802C036
_0802BECE:
	cmp r4, #0xb7
	ble _0802BF10
	cmp r4, #0xb9
	bne _0802BEDC
	movs r0, #6
	bl sub_11B0
_0802BEDC:
	cmp r4, #0xb8
	bne _0802BEE6
	movs r0, #0x9e
	bl m4aSongNumStart
_0802BEE6:
	ldr r1, [r6]
	ldr r2, _0802BF08 @ =0x0000132C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r0, [r2, #0x34]
	subs r0, #0x60
	str r0, [r2, #0x34]
	ldr r1, [r1]
	ldr r3, _0802BF0C @ =0xFFFFFC00
	adds r0, r3, #0
	ldrh r4, [r1, #0xa]
	adds r0, r0, r4
	b _0802C034
	.align 2, 0
_0802BF00: .4byte 0x020314E0
_0802BF04: .4byte 0x000005A6
_0802BF08: .4byte 0x0000132C
_0802BF0C: .4byte 0xFFFFFC00
_0802BF10:
	cmp r4, #0xaf
	ble _0802BF20
	ldr r7, _0802BF1C @ =0x0000132C
	adds r2, r2, r7
	b _0802C020
	.align 2, 0
_0802BF1C: .4byte 0x0000132C
_0802BF20:
	cmp r4, #0xa7
	ble _0802BF5C
	cmp r4, #0xa9
	bne _0802BF2E
	movs r0, #6
	bl sub_11B0
_0802BF2E:
	cmp r4, #0xa8
	bne _0802BF38
	movs r0, #0x9e
	bl m4aSongNumStart
_0802BF38:
	ldr r1, [r6]
	ldr r4, _0802BF54 @ =0x0000132C
	adds r1, r1, r4
	ldr r2, [r1]
	ldr r0, [r2, #0x34]
	subs r0, #0x60
	str r0, [r2, #0x34]
	ldr r1, [r1]
	ldr r7, _0802BF58 @ =0xFFFFFC00
	adds r0, r7, #0
	ldrh r2, [r1, #0xa]
	adds r0, r0, r2
	b _0802C034
	.align 2, 0
_0802BF54: .4byte 0x0000132C
_0802BF58: .4byte 0xFFFFFC00
_0802BF5C:
	cmp r4, #0x9f
	ble _0802BF80
	ldr r3, _0802BF7C @ =0x0000132C
	adds r2, r2, r3
	ldr r1, [r2]
	ldr r0, [r1, #0x34]
	adds r0, #0x60
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	ldrh r7, [r1, #0xa]
	adds r0, r0, r7
	b _0802C034
	.align 2, 0
_0802BF7C: .4byte 0x0000132C
_0802BF80:
	cmp r4, #0x7b
	bgt _0802C036
	cmp r4, #0x73
	ble _0802BFB8
	cmp r4, #0x75
	bne _0802BF92
	movs r0, #6
	bl sub_11B0
_0802BF92:
	cmp r4, #0x74
	bne _0802BF9C
	movs r0, #0x9e
	bl m4aSongNumStart
_0802BF9C:
	ldr r1, [r6]
	ldr r0, _0802BFB0 @ =0x0000132C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, [r2, #0x34]
	subs r0, #0x60
	str r0, [r2, #0x34]
	ldr r1, [r1]
	ldr r2, _0802BFB4 @ =0xFFFFFC00
	b _0802C02E
	.align 2, 0
_0802BFB0: .4byte 0x0000132C
_0802BFB4: .4byte 0xFFFFFC00
_0802BFB8:
	cmp r4, #0x6b
	ble _0802BFDC
	ldr r4, _0802BFD8 @ =0x0000132C
	adds r2, r2, r4
	ldr r1, [r2]
	ldr r0, [r1, #0x34]
	adds r0, #0x60
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r7, #0x80
	lsls r7, r7, #3
	adds r0, r7, #0
	ldrh r2, [r1, #0xa]
	adds r0, r0, r2
	b _0802C034
	.align 2, 0
_0802BFD8: .4byte 0x0000132C
_0802BFDC:
	cmp r4, #0x63
	ble _0802C018
	cmp r4, #0x65
	bne _0802BFEA
	movs r0, #6
	bl sub_11B0
_0802BFEA:
	cmp r4, #0x64
	bne _0802BFF4
	movs r0, #0x9e
	bl m4aSongNumStart
_0802BFF4:
	ldr r1, [r6]
	ldr r3, _0802C010 @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	ldr r0, [r2, #0x34]
	subs r0, #0x60
	str r0, [r2, #0x34]
	ldr r1, [r1]
	ldr r4, _0802C014 @ =0xFFFFFC00
	adds r0, r4, #0
	ldrh r7, [r1, #0xa]
	adds r0, r0, r7
	b _0802C034
	.align 2, 0
_0802C010: .4byte 0x0000132C
_0802C014: .4byte 0xFFFFFC00
_0802C018:
	cmp r4, #0x5b
	ble _0802C036
	ldr r0, _0802C048 @ =0x0000132C
	adds r2, r2, r0
_0802C020:
	ldr r1, [r2]
	ldr r0, [r1, #0x34]
	adds r0, #0x60
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
_0802C02E:
	adds r0, r2, #0
	ldrh r3, [r1, #0xa]
	adds r0, r0, r3
_0802C034:
	strh r0, [r1, #0xa]
_0802C036:
	cmp r5, #0
	beq _0802C03C
	b _0802C4D2
_0802C03C:
	movs r0, #0x11
	bl m4aSongNumStart
	bl sub_2312C
	b _0802C4D2
	.align 2, 0
_0802C048: .4byte 0x0000132C
_0802C04C:
	ldr r4, _0802C208 @ =0x020314E0
	ldr r0, [r4]
	ldr r7, _0802C20C @ =0x0000132C
	adds r0, r0, r7
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1, #1]
	bl sub_23300
	ldr r4, [r4]
	ldr r1, _0802C210 @ =0x000005A6
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0xe5
	bhi _0802C07A
	movs r2, #0x84
	lsls r2, r2, #2
	adds r4, r4, r2
	ldrh r0, [r4]
	cmp r0, #0x96
	bne _0802C07A
	subs r0, #1
	strh r0, [r4]
_0802C07A:
	ldr r4, _0802C208 @ =0x020314E0
	ldr r0, [r4]
	ldr r3, _0802C210 @ =0x000005A6
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #0x87
	lsls r0, r0, #1
	cmp r1, r0
	bne _0802C0A6
	ldr r0, _0802C214 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bhi _0802C0A6
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	ldr r4, _0802C218 @ =0x000006C4
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
_0802C0A6:
	ldr r1, _0802C208 @ =0x020314E0
	ldr r3, [r1]
	ldr r7, _0802C210 @ =0x000005A6
	adds r4, r3, r7
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _0802C11C
	ldr r1, _0802C214 @ =gMain
	movs r0, #1
	strh r0, [r1, #0x2c]
	ldrh r5, [r4]
	movs r1, #0xa6
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r5, [r0]
	movs r1, #0
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ldr r2, _0802C21C @ =0x03005C00
	mov r8, r2
	cmp r1, r0
	bgt _0802C10C
	mov r7, r8
	adds r4, r0, #0
	movs r6, #0xc1
	lsls r6, r6, #8
_0802C0DA:
	movs r5, #1
	lsls r2, r1, #0x10
	asrs r3, r2, #0x10
_0802C0E0:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r7
	strh r6, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802C0E0
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r2, r3
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	ble _0802C0DA
_0802C10C:
	ldr r1, _0802C220 @ =0x040000D4
	mov r4, r8
	str r4, [r1]
	ldr r0, _0802C224 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802C228 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802C11C:
	ldr r7, _0802C208 @ =0x020314E0
	ldr r0, [r7]
	ldr r1, _0802C210 @ =0x000005A6
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0802C1AE
	movs r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, _0802C21C @ =0x03005C00
	mov r8, r2
	cmp r1, r0
	bgt _0802C176
	mov r6, r8
	ldr r4, _0802C22C @ =0x000001FF
	adds r7, r0, #0
_0802C144:
	movs r5, #1
	lsls r2, r1, #0x10
	asrs r3, r2, #0x10
_0802C14A:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802C14A
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r2, r3
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _0802C144
_0802C176:
	ldr r1, _0802C220 @ =0x040000D4
	mov r4, r8
	str r4, [r1]
	ldr r0, _0802C224 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802C228 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r7, _0802C208 @ =0x020314E0
	ldr r0, [r7]
	ldr r1, _0802C210 @ =0x000005A6
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _0802C230 @ =0x0000010D
	cmp r1, r0
	bne _0802C1AE
	ldr r1, _0802C214 @ =gMain
	movs r2, #0
	strh r2, [r1, #0x2c]
	ldrb r0, [r1, #4]
	cmp r0, #1
	bhi _0802C1AE
	ldrh r0, [r1, #0x38]
	strh r2, [r1, #0x38]
	ldrh r0, [r1, #0x3c]
	strh r2, [r1, #0x3c]
	ldrh r0, [r1, #0x3a]
	strh r2, [r1, #0x3a]
_0802C1AE:
	ldr r2, _0802C208 @ =0x020314E0
	ldr r1, [r2]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0802C1C0
	ldr r3, _0802C210 @ =0x000005A6
	adds r1, r1, r3
	movs r0, #0xb5
	strh r0, [r1]
_0802C1C0:
	ldr r4, _0802C208 @ =0x020314E0
	ldr r1, [r4]
	ldr r7, _0802C210 @ =0x000005A6
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0xb4
	beq _0802C1D0
	b _0802C4D2
_0802C1D0:
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	beq _0802C1DC
	cmp r0, #8
	bne _0802C28C
_0802C1DC:
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r0, _0802C208 @ =0x020314E0
	ldr r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x8d
	beq _0802C268
	cmp r0, #0x8d
	bgt _0802C23E
	cmp r0, #0x84
	beq _0802C268
	cmp r0, #0x84
	bgt _0802C234
	cmp r0, #0x3b
	beq _0802C268
	cmp r0, #0x72
	beq _0802C268
	b _0802C284
	.align 2, 0
_0802C208: .4byte 0x020314E0
_0802C20C: .4byte 0x0000132C
_0802C210: .4byte 0x000005A6
_0802C214: .4byte gMain
_0802C218: .4byte 0x000006C4
_0802C21C: .4byte 0x03005C00
_0802C220: .4byte 0x040000D4
_0802C224: .4byte 0x06002000
_0802C228: .4byte 0x80000400
_0802C22C: .4byte 0x000001FF
_0802C230: .4byte 0x0000010D
_0802C234:
	cmp r0, #0x86
	beq _0802C268
	cmp r0, #0x8b
	beq _0802C268
	b _0802C284
_0802C23E:
	cmp r0, #0xa0
	beq _0802C268
	cmp r0, #0xa0
	bgt _0802C250
	cmp r0, #0x90
	beq _0802C268
	cmp r0, #0x97
	beq _0802C268
	b _0802C284
_0802C250:
	cmp r0, #0xc4
	bgt _0802C284
	cmp r0, #0xc3
	blt _0802C284
	ldr r0, _0802C260 @ =0x000222E0
	str r0, [r1, #0x38]
	ldr r0, _0802C264 @ =0x00989680
	b _0802C28A
	.align 2, 0
_0802C260: .4byte 0x000222E0
_0802C264: .4byte 0x00989680
_0802C268:
	ldr r3, _0802C278 @ =0x020314E0
	ldr r0, [r3]
	ldr r1, _0802C27C @ =0x00013880
	str r1, [r0, #0x38]
	ldr r1, _0802C280 @ =0x004C4B40
	str r1, [r0, #0x3c]
	b _0802C28C
	.align 2, 0
_0802C278: .4byte 0x020314E0
_0802C27C: .4byte 0x00013880
_0802C280: .4byte 0x004C4B40
_0802C284:
	ldr r4, _0802C2B4 @ =0x020314E0
	ldr r1, [r4]
	ldr r0, _0802C2B8 @ =0x000F4240
_0802C28A:
	str r0, [r1, #0x3c]
_0802C28C:
	ldr r7, _0802C2B4 @ =0x020314E0
	ldr r1, [r7]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _0802C2C8
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r7]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x9a
	bne _0802C2C4
	ldr r0, _0802C2BC @ =0x000222E0
	str r0, [r1, #0x38]
	ldr r0, _0802C2C0 @ =0x00989680
	b _0802C2C6
	.align 2, 0
_0802C2B4: .4byte 0x020314E0
_0802C2B8: .4byte 0x000F4240
_0802C2BC: .4byte 0x000222E0
_0802C2C0: .4byte 0x00989680
_0802C2C4:
	ldr r0, _0802C2EC @ =0x002DC6C0
_0802C2C6:
	str r0, [r1, #0x3c]
_0802C2C8:
	ldr r3, _0802C2F0 @ =gMain
	ldrb r0, [r3, #4]
	cmp r0, #2
	bhi _0802C2D2
	b _0802C4D2
_0802C2D2:
	ldr r2, _0802C2F4 @ =0x020314E0
	ldr r0, [r2]
	movs r1, #1
	strb r1, [r0, #0x1c]
	ldrb r0, [r3, #4]
	cmp r0, #6
	bne _0802C300
	ldr r0, [r2]
	ldr r1, _0802C2F8 @ =0x00061A80
	str r1, [r0, #0x38]
	ldr r1, _0802C2FC @ =0x01C9C380
	str r1, [r0, #0x3c]
	b _0802C4D2
	.align 2, 0
_0802C2EC: .4byte 0x002DC6C0
_0802C2F0: .4byte gMain
_0802C2F4: .4byte 0x020314E0
_0802C2F8: .4byte 0x00061A80
_0802C2FC: .4byte 0x01C9C380
_0802C300:
	ldr r0, [r2]
	ldr r1, _0802C30C @ =0x00061A80
	str r1, [r0, #0x38]
	ldr r1, _0802C310 @ =0x00989680
	str r1, [r0, #0x3c]
	b _0802C4D2
	.align 2, 0
_0802C30C: .4byte 0x00061A80
_0802C310: .4byte 0x00989680
_0802C314:
	ldr r3, _0802C38C @ =0x020314E0
	ldr r0, [r3]
	ldr r4, _0802C390 @ =0x000005F7
	adds r0, r0, r4
	movs r3, #0
	strb r3, [r0]
	ldr r7, _0802C38C @ =0x020314E0
	ldr r0, [r7]
	ldr r1, _0802C394 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r4, #3
	strb r4, [r0, #1]
	ldr r0, [r7]
	ldr r2, _0802C398 @ =0x000005A4
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r7]
	ldr r7, _0802C39C @ =0x000005A6
	adds r1, r0, r7
	movs r2, #0
	strh r3, [r1]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, _0802C3A0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bls _0802C352
	b _0802C48C
_0802C352:
	ldr r3, _0802C38C @ =0x020314E0
	ldr r0, [r3]
	strb r2, [r0, #0x1f]
	ldr r0, [r3]
	ldr r4, _0802C394 @ =0x0000132C
	adds r0, r0, r4
	ldr r2, [r0]
	ldr r1, _0802C3A4 @ =0x0000FFF6
	strh r1, [r2, #0x32]
	ldr r1, [r0]
	movs r0, #0x14
	strh r0, [r1, #0x30]
	movs r5, #0
	ldr r3, _0802C3A8 @ =0x0000071D
_0802C36E:
	ldr r7, _0802C38C @ =0x020314E0
	ldr r2, [r7]
	ldr r1, _0802C3AC @ =0x00000723
	adds r0, r2, r1
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _0802C3B0
	adds r0, r2, r3
	adds r0, r0, r1
	movs r1, #1
	b _0802C3B6
	.align 2, 0
_0802C38C: .4byte 0x020314E0
_0802C390: .4byte 0x000005F7
_0802C394: .4byte 0x0000132C
_0802C398: .4byte 0x000005A4
_0802C39C: .4byte 0x000005A6
_0802C3A0: .4byte gMain
_0802C3A4: .4byte 0x0000FFF6
_0802C3A8: .4byte 0x0000071D
_0802C3AC: .4byte 0x00000723
_0802C3B0:
	adds r0, r2, r3
	adds r0, r0, r1
	movs r1, #0
_0802C3B6:
	strb r1, [r0]
	lsls r0, r5, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0802C36E
	ldr r4, _0802C474 @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _0802C478 @ =0x00000723
	adds r0, r1, r3
	ldrb r3, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0802C41A
	ldr r2, _0802C47C @ =0x00000721
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, [r4]
	ldr r7, _0802C478 @ =0x00000723
	adds r1, r0, r7
	ldrb r1, [r1]
	ldr r3, _0802C480 @ =0x00000722
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r4]
	adds r2, r0, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	subs r7, #6
	adds r0, r0, r7
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x78
	strb r1, [r0]
	ldr r1, [r4]
	ldr r2, _0802C478 @ =0x00000723
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802C41A:
	ldr r2, [r4]
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0802C438
	ldr r7, _0802C484 @ =0x00000286
	adds r1, r2, r7
	movs r0, #0x5a
	strh r0, [r1]
_0802C438:
	ldr r0, [r4]
	ldr r2, _0802C488 @ =0x0000062A
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802C448
	adds r0, #1
	strb r0, [r1]
_0802C448:
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0802C456
	movs r0, #0xa
	strb r0, [r1, #0x17]
_0802C456:
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bne _0802C464
	movs r0, #5
	strb r0, [r1, #0x17]
_0802C464:
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _0802C4CC
	movs r0, #6
	strb r0, [r1, #0x17]
	b _0802C4CC
	.align 2, 0
_0802C474: .4byte 0x020314E0
_0802C478: .4byte 0x00000723
_0802C47C: .4byte 0x00000721
_0802C480: .4byte 0x00000722
_0802C484: .4byte 0x00000286
_0802C488: .4byte 0x0000062A
_0802C48C:
	ldr r7, _0802C528 @ =0x020314E0
	ldr r1, [r7]
	movs r0, #1
	strb r0, [r1, #0x1f]
	ldr r1, [r7]
	ldr r0, _0802C52C @ =0x0000132C
	adds r2, r1, r0
	ldr r0, [r2]
	strh r3, [r0, #0x32]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r2, _0802C530 @ =0x000006C4
	adds r1, r1, r2
	strb r4, [r1]
	ldr r1, [r7]
	movs r0, #4
	strb r0, [r1, #0x13]
	ldr r2, [r7]
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0802C4CC
	ldr r4, _0802C534 @ =0x00000286
	adds r1, r2, r4
	movs r0, #0x5b
	strh r0, [r1]
_0802C4CC:
	movs r0, #0
	bl sub_31CF8
_0802C4D2:
	ldr r4, _0802C528 @ =0x020314E0
	ldr r1, [r4]
	ldr r3, _0802C52C @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	ldrh r0, [r2, #0x10]
	strh r0, [r2, #0x14]
	ldr r1, [r1]
	ldrh r0, [r1, #0x12]
	strh r0, [r1, #0x16]
	movs r5, #2
	adds r7, r4, #0
	adds r6, r3, #0
_0802C4EC:
	ldr r3, [r7]
	adds r3, r3, r6
	ldr r0, [r3]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, #1
	lsls r2, r2, #2
	adds r4, r0, r2
	lsls r5, r1, #2
	adds r0, r0, r5
	ldrh r0, [r0, #0x14]
	strh r0, [r4, #0x14]
	ldr r0, [r3]
	adds r2, r0, r2
	adds r0, r0, r5
	ldrh r0, [r0, #0x16]
	strh r0, [r2, #0x16]
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r1, #0
	bge _0802C4EC

	thumb_func_start sub_2C518
sub_2C518: @ 0x0802C518
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C528: .4byte 0x020314E0
_0802C52C: .4byte 0x0000132C
_0802C530: .4byte 0x000006C4
_0802C534: .4byte 0x00000286

	thumb_func_start sub_2C538
sub_2C538: @ 0x0802C538
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov sb, r0
	ldr r1, _0802C568 @ =0x020314E0
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #5
	bls _0802C55C
	b _0802C784
_0802C55C:
	lsls r0, r0, #2
	ldr r1, _0802C56C @ =_0802C570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C568: .4byte 0x020314E0
_0802C56C: .4byte _0802C570
_0802C570: @ jump table
	.4byte _0802C588 @ case 0
	.4byte _0802C5BC @ case 1
	.4byte _0802C614 @ case 2
	.4byte _0802C650 @ case 3
	.4byte _0802C6C0 @ case 4
	.4byte _0802C708 @ case 5
_0802C588:
	ldr r5, [r7]
	movs r3, #0xc1
	lsls r3, r3, #2
	adds r6, r5, r3
	ldrh r4, [r6]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r0, #0
	strh r4, [r6]
	ldr r1, _0802C5B8 @ =0x00000301
	adds r5, r5, r1
	strb r0, [r5]
	b _0802C784
	.align 2, 0
_0802C5B8: .4byte 0x00000301
_0802C5BC:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	ldr r2, _0802C610 @ =0x00000301
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C608
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
_0802C608:
	ldr r0, [r7]
	adds r0, r0, r2
	b _0802C780
	.align 2, 0
_0802C610: .4byte 0x00000301
_0802C614:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __udivsi3
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #9
	beq _0802C646
	b _0802C784
_0802C646:
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #3
	b _0802C6F8
_0802C650:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	mov r8, r2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r2, #0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x41
	bls _0802C698
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
_0802C698:
	ldr r1, [r7]
	mov r3, r8
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #6
	bls _0802C784
	ldr r3, _0802C6BC @ =0x00000301
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C784
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #4
	b _0802C772
	.align 2, 0
_0802C6BC: .4byte 0x00000301
_0802C6C0:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __udivsi3
	adds r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #9
	bne _0802C784
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #5
_0802C6F8:
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	b _0802C784
_0802C708:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	mov r8, r2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r2, #0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x41
	bls _0802C750
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
_0802C750:
	ldr r1, [r7]
	mov r3, r8
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #6
	bls _0802C784
	ldr r3, _0802C7B8 @ =0x00000301
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C784
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #2
_0802C772:
	strb r0, [r1]
	ldr r0, [r7]
	mov r3, r8
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0802C7B8 @ =0x00000301
	adds r0, r0, r1
_0802C780:
	movs r1, #0
	strb r1, [r0]
_0802C784:
	ldr r6, _0802C7BC @ =0x0200E498
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802C83C
	ldr r1, [r7]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0802C7C4
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xbc
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r3, _0802C7C0 @ =0x00000119
	adds r0, r3, #0
	b _0802C7DC
	.align 2, 0
_0802C7B8: .4byte 0x00000301
_0802C7BC: .4byte 0x0200E498
_0802C7C0: .4byte 0x00000119
_0802C7C4:
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xc0
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r2, #0
_0802C7DC:
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r7]
	ldr r3, _0802C95C @ =0x00000302
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0802C808
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0802C808
	ldr r0, _0802C960 @ =gMain
	ldr r2, _0802C964 @ =0x000033D8
	adds r0, r0, r2
	strh r1, [r0]
_0802C808:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802C968 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802C96C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802C970 @ =0xFFFFFE00
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
_0802C83C:
	ldr r2, [r7]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802C852
	cmp r0, #2
	bne _0802C8C0
_0802C852:
	ldr r4, _0802C974 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r3, #0x10
	ldrsh r1, [r0, r3]
	subs r1, #0xbe
	movs r3, #0x12
	ldrsh r0, [r0, r3]
	ldr r3, _0802C978 @ =0xFFFFFEE3
	adds r0, r0, r3
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0x8c
	bhi _0802C8C0
	ldr r1, _0802C95C @ =0x00000302
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0802C8C0
	movs r0, #0xc5
	bl m4aSongNumStart
	ldr r1, [r7]
	ldr r0, _0802C97C @ =0x00002710
	str r0, [r1, #0x3c]
	adds r1, r1, r4
	ldr r2, [r1]
	movs r3, #0
	ldr r0, _0802C980 @ =0x0000FDA8
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldr r0, _0802C984 @ =0x0000FED4
	strh r0, [r2, #0x32]
	ldr r0, [r1]
	strh r3, [r0, #6]
	ldr r0, _0802C960 @ =gMain
	ldr r2, _0802C964 @ =0x000033D8
	adds r0, r0, r2
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r7]
	ldr r3, _0802C95C @ =0x00000302
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	movs r0, #8
	bl sub_11B0
_0802C8C0:
	ldr r6, _0802C988 @ =0x0200DD68
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802C94E
	ldr r2, _0802C98C @ =0x020314E0
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb8
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0802C990 @ =0x00000115
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _0802C994 @ =0x040000D4
	mov r3, sb
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0802C998 @ =0x0847DF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802C99C @ =0x06013580
	str r0, [r2, #4]
	ldr r0, _0802C9A0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r7, _0802C968 @ =gOamBuffer
	ldr r1, _0802C970 @ =0xFFFFFE00
	mov r8, r1
_0802C90A:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802C96C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #2
	ble _0802C90A
_0802C94E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C95C: .4byte 0x00000302
_0802C960: .4byte gMain
_0802C964: .4byte 0x000033D8
_0802C968: .4byte gOamBuffer
_0802C96C: .4byte 0x000001FF
_0802C970: .4byte 0xFFFFFE00
_0802C974: .4byte 0x0000132C
_0802C978: .4byte 0xFFFFFEE3
_0802C97C: .4byte 0x00002710
_0802C980: .4byte 0x0000FDA8
_0802C984: .4byte 0x0000FED4
_0802C988: .4byte 0x0200DD68
_0802C98C: .4byte 0x020314E0
_0802C990: .4byte 0x00000115
_0802C994: .4byte 0x040000D4
_0802C998: .4byte 0x0847DF0C
_0802C99C: .4byte 0x06013580
_0802C9A0: .4byte 0x80000180

	thumb_func_start sub_2C9A4
sub_2C9A4: @ 0x0802C9A4
	push {r4, r5, r6, lr}
	ldr r6, _0802C9E0 @ =0x0200E328
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802CA7A
	ldr r0, _0802C9E4 @ =0x020314E0
	ldr r2, [r0]
	ldr r3, _0802C9E8 @ =0x0000029F
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r1, #0
	beq _0802C9EC
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	lsrs r1, r1, #3
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r0, #0x34
	subs r1, r1, r0
	strh r1, [r6, #4]
	b _0802C9F0
	.align 2, 0
_0802C9E0: .4byte 0x0200E328
_0802C9E4: .4byte 0x020314E0
_0802C9E8: .4byte 0x0000029F
_0802C9EC:
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802C9F0:
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _0802CA20 @ =0x0000029F
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0802CA24
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	adds r0, #4
	b _0802CA32
	.align 2, 0
_0802CA20: .4byte 0x0000029F
_0802CA24:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
_0802CA32:
	ldr r2, _0802CA80 @ =0x040000D4
	lsls r0, r0, #7
	ldr r1, _0802CA84 @ =0x084FEF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802CA88 @ =0x06014B00
	str r0, [r2, #4]
	ldr r0, _0802CA8C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802CA90 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802CA94 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802CA98 @ =0xFFFFFE00
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
_0802CA7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA80: .4byte 0x040000D4
_0802CA84: .4byte 0x084FEF0C
_0802CA88: .4byte 0x06014B00
_0802CA8C: .4byte 0x80000040
_0802CA90: .4byte gOamBuffer
_0802CA94: .4byte 0x000001FF
_0802CA98: .4byte 0xFFFFFE00

	thumb_func_start sub_2CA9C
sub_2CA9C: @ 0x0802CA9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov ip, r0
	ldr r0, _0802CADC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xc8
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802CAB8
	b _0802CCF2
_0802CAB8:
	movs r0, #0xca
	strh r0, [r6, #2]
	ldr r0, _0802CAE0 @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _0802CAE4 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x30
	bls _0802CB44
	subs r0, #0x30
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x21
	ble _0802CAE8
	movs r1, #0x2a
	subs r1, r1, r0
	lsls r1, r1, #1
	b _0802CB12
	.align 2, 0
_0802CADC: .4byte gMain
_0802CAE0: .4byte 0x020314E0
_0802CAE4: .4byte 0x00000286
_0802CAE8:
	cmp r0, #0x17
	ble _0802CAFC
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #1
	ldr r3, _0802CAF8 @ =0x0000FFF7
	mov ip, r3
	b _0802CB1A
	.align 2, 0
_0802CAF8: .4byte 0x0000FFF7
_0802CAFC:
	cmp r0, #7
	ble _0802CB10
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #2
	ldr r1, _0802CB0C @ =0x0000FFFC
	mov ip, r1
	b _0802CB1A
	.align 2, 0
_0802CB0C: .4byte 0x0000FFFC
_0802CB10:
	lsls r1, r0, #1
_0802CB12:
	movs r0, #0x92
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
_0802CB1A:
	ldr r2, _0802CB34 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _0802CB38 @ =0x08455E8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802CB3C @ =0x060152A0
	str r0, [r2, #4]
	ldr r0, _0802CB40 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802CB48
	.align 2, 0
_0802CB34: .4byte 0x040000D4
_0802CB38: .4byte 0x08455E8C
_0802CB3C: .4byte 0x060152A0
_0802CB40: .4byte 0x80000100
_0802CB44:
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802CB48:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802CB90 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802CB94 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802CB98 @ =0xFFFFFE00
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
	ldr r0, _0802CB9C @ =0x020314E0
	ldr r0, [r0]
	ldr r1, _0802CBA0 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x38
	bls _0802CBA4
	movs r7, #0x80
	lsls r7, r7, #1
	b _0802CBD6
	.align 2, 0
_0802CB90: .4byte gOamBuffer
_0802CB94: .4byte 0x000001FF
_0802CB98: .4byte 0xFFFFFE00
_0802CB9C: .4byte 0x020314E0
_0802CBA0: .4byte 0x00000286
_0802CBA4:
	subs r0, #0x24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802CBCC
	lsls r0, r0, #7
	movs r1, #0x14
	bl __divsi3
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0x82
	strh r0, [r6, #4]
	ldr r3, _0802CBC8 @ =0x0000FFFE
	mov ip, r3
	b _0802CBD6
	.align 2, 0
_0802CBC8: .4byte 0x0000FFFE
_0802CBCC:
	movs r7, #0x80
	movs r0, #0xb4
	strh r0, [r6, #4]
	movs r0, #0
	mov ip, r0
_0802CBD6:
	adds r5, r6, #0
	adds r5, #0x10
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r0, _0802CCA8 @ =0x000001FF
	mov r8, r0
	mov r3, r8
	ands r1, r3
	ldrh r3, [r2, #2]
	ldr r0, _0802CCAC @ =0xFFFFFE00
	mov sb, r0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x10]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	add r0, ip
	strb r0, [r1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #3]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #6
	bl sub_7C0
	ldr r0, _0802CCB0 @ =0x020314E0
	ldr r1, [r0]
	ldr r0, _0802CCB4 @ =0x00000286
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0x39
	bhi _0802CCC8
	adds r0, r1, #0
	adds r0, #0x30
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrh r1, [r3]
	movs r0, #0xf
	ands r1, r0
	lsrs r1, r1, #3
	lsls r0, r1, #3
	adds r0, r0, r1
	subs r0, #1
	ldr r1, _0802CCB8 @ =0x040000D4
	adds r2, r2, r0
	lsls r2, r2, #6
	ldr r0, _0802CCBC @ =0x0845648C
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, _0802CCC0 @ =0x06015520
	str r0, [r1, #4]
	ldr r0, _0802CCC4 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x70
	b _0802CCF0
	.align 2, 0
_0802CCA8: .4byte 0x000001FF
_0802CCAC: .4byte 0xFFFFFE00
_0802CCB0: .4byte 0x020314E0
_0802CCB4: .4byte 0x00000286
_0802CCB8: .4byte 0x040000D4
_0802CCBC: .4byte 0x0845648C
_0802CCC0: .4byte 0x06015520
_0802CCC4: .4byte 0x80000020
_0802CCC8:
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x4c
_0802CCF0:
	strb r0, [r1]
_0802CCF2:
	ldr r5, _0802CD74 @ =0x020314E0
	ldr r0, [r5]
	ldr r4, _0802CD78 @ =0x00000286
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802CD68
	cmp r0, #0x5a
	bne _0802CD18
	movs r0, #1
	strh r0, [r6]
	ldr r1, _0802CD7C @ =0x040000D4
	ldr r0, _0802CD80 @ =0x086AE324
	str r0, [r1]
	ldr r0, _0802CD84 @ =0x05000380
	str r0, [r1, #4]
	ldr r0, _0802CD88 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802CD18:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x55
	bne _0802CD2A
	ldr r0, _0802CD8C @ =0x02032F20
	ldr r1, _0802CD90 @ =0x086A1ABC
	bl MPlayStart
_0802CD2A:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x3a
	bne _0802CD50
	ldr r0, _0802CD8C @ =0x02032F20
	ldr r1, _0802CD94 @ =0x0869F2A0
	bl MPlayStart
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bgt _0802CD50
	adds r0, r2, #1
	strb r0, [r1]
_0802CD50:
	ldr r0, _0802CD74 @ =0x020314E0
	ldr r1, [r0]
	ldr r3, _0802CD78 @ =0x00000286
	adds r1, r1, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0802CD68
	strh r0, [r6]
_0802CD68:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD74: .4byte 0x020314E0
_0802CD78: .4byte 0x00000286
_0802CD7C: .4byte 0x040000D4
_0802CD80: .4byte 0x086AE324
_0802CD84: .4byte 0x05000380
_0802CD88: .4byte 0x80000010
_0802CD8C: .4byte 0x02032F20
_0802CD90: .4byte 0x086A1ABC
_0802CD94: .4byte 0x0869F2A0

	thumb_func_start sub_2CD98
sub_2CD98: @ 0x0802CD98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0802CE6C @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0x28]
	ldrh r1, [r6]
	mov sb, r0
	ldr r0, _0802CE70 @ =0x020314E0
	mov ip, r0
	cmp r1, #0
	beq _0802CE0E
	ldr r0, [r0]
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r0, #0x2c
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0802CE74 @ =gOamBuffer
	ldr r2, _0802CE78 @ =0xFFFFFE00
	mov r8, r2
_0802CDCA:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802CE7C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #6
	ble _0802CDCA
_0802CE0E:
	mov r4, ip
	ldr r0, [r4]
	adds r0, #0xf4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0802CE5E
	cmp r0, #0x78
	bne _0802CE2A
	mov r2, sb
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x28]
	movs r0, #1
	strh r0, [r1]
_0802CE2A:
	mov r4, ip
	ldr r3, [r4]
	adds r2, r3, #0
	adds r2, #0xf4
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x78
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r4, #0x87
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	adds r4, #0x5c
	adds r1, r3, r4
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _0802CE5E
	mov r2, sb
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x28]
	movs r0, #0
	strh r0, [r1]
_0802CE5E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CE6C: .4byte gMain
_0802CE70: .4byte 0x020314E0
_0802CE74: .4byte gOamBuffer
_0802CE78: .4byte 0xFFFFFE00
_0802CE7C: .4byte 0x000001FF

	thumb_func_start sub_2CE80
sub_2CE80: @ 0x0802CE80
	push {r4, r5, lr}
	ldr r0, _0802CEC0 @ =0x020314E0
	ldr r4, [r0]
	adds r1, r4, #0
	adds r1, #0x68
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r5, r0, #0
	cmp r1, #0xa9
	bgt _0802CED8
	ldr r3, _0802CEC4 @ =0x040000D4
	ldr r0, _0802CEC8 @ =gMain
	ldrb r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #6
	ldr r2, _0802CECC @ =0x08137B3C
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r3]
	ldr r0, _0802CED0 @ =0x05000360
	str r0, [r3, #4]
	ldr r0, _0802CED4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	b _0802CF02
	.align 2, 0
_0802CEC0: .4byte 0x020314E0
_0802CEC4: .4byte 0x040000D4
_0802CEC8: .4byte gMain
_0802CECC: .4byte 0x08137B3C
_0802CED0: .4byte 0x05000360
_0802CED4: .4byte 0x80000010
_0802CED8:
	ldr r2, _0802CF20 @ =0x040000D4
	ldr r0, _0802CF24 @ =gMain
	ldrb r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	ldr r0, _0802CF28 @ =0x08137B5C
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #6
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0802CF2C @ =0x05000360
	str r0, [r2, #4]
	ldr r0, _0802CF30 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0802CF02:
	ldr r0, [r5]
	ldr r3, _0802CF34 @ =0x00000163
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bls _0802CF14
	b _0802D0FA
_0802CF14:
	lsls r0, r0, #2
	ldr r1, _0802CF38 @ =_0802CF3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CF20: .4byte 0x040000D4
_0802CF24: .4byte gMain
_0802CF28: .4byte 0x08137B5C
_0802CF2C: .4byte 0x05000360
_0802CF30: .4byte 0x80000010
_0802CF34: .4byte 0x00000163
_0802CF38: .4byte _0802CF3C
_0802CF3C: @ jump table
	.4byte _0802CF50 @ case 0
	.4byte _0802CFAC @ case 1
	.4byte _0802D02C @ case 2
	.4byte _0802D074 @ case 3
	.4byte _0802D0A4 @ case 4
_0802CF50:
	ldr r0, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r4, [r5]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _0802CF90 @ =0x00000165
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq _0802CF94
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _0802CF9C
	.align 2, 0
_0802CF90: .4byte 0x00000165
_0802CF94:
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r1, [r0]
_0802CF9C:
	ldr r0, [r5]
	ldr r4, _0802CFA8 @ =0x00000165
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802CFA8: .4byte 0x00000165
_0802CFAC:
	ldr r1, [r5]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #4
	bhi _0802D00A
	cmp r0, #1
	bhi _0802CFD4
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #3
	b _0802CFE8
_0802CFD4:
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #5
_0802CFE8:
	strh r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802CFFE
	movs r0, #0xcc
	bl m4aSongNumStart
_0802CFFE:
	ldr r1, [r5]
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0802D0FA
_0802D00A:
	ldr r3, _0802D028 @ =0x00000163
	adds r1, r1, r3
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xb4
	lsls r1, r1, #1
	b _0802D09A
	.align 2, 0
_0802D028: .4byte 0x00000163
_0802D02C:
	ldr r0, _0802D070 @ =0x086AE344
	ldr r2, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r3, r2, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r2, [r1]
	cmp r0, r2
	bgt _0802D0C8
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #7
	ble _0802D0FA
	movs r0, #4
	strb r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802D070: .4byte 0x086AE344
_0802D074:
	ldr r0, [r5]
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r2, #0
	movs r1, #8
	strb r1, [r0]
	ldr r1, [r5]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	ldr r0, _0802D0A0 @ =0x00000163
	adds r1, r1, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xb3
	lsls r1, r1, #1
_0802D09A:
	adds r0, r0, r1
	strh r2, [r0]
	b _0802D0FA
	.align 2, 0
_0802D0A0: .4byte 0x00000163
_0802D0A4:
	ldr r0, _0802D0D0 @ =0x086AE344
	ldr r2, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r3, r2, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r2, [r1]
	cmp r0, r2
	ble _0802D0D4
_0802D0C8:
	adds r0, r2, #1
	strh r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802D0D0: .4byte 0x086AE344
_0802D0D4:
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r5]
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x13
	ble _0802D0FA
	strb r2, [r1]
	ldr r0, [r5]
	ldr r4, _0802D100 @ =0x00000163
	adds r0, r0, r4
	strb r2, [r0]
_0802D0FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D100: .4byte 0x00000163

	thumb_func_start sub_2D104
sub_2D104: @ 0x0802D104
	push {r4, r5, r6, r7, lr}
	ldr r0, _0802D144 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xb0
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802D1DC
	ldr r1, _0802D148 @ =0x020314E0
	ldr r3, [r1]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r4, r1, #0
	cmp r0, #0
	bne _0802D14C
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0802D158
	.align 2, 0
_0802D144: .4byte gMain
_0802D148: .4byte 0x020314E0
_0802D14C:
	ldr r1, _0802D1E4 @ =0x086AE344
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
_0802D158:
	ldr r2, _0802D1E8 @ =0x040000D4
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _0802D1EC @ =0x083C076C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802D1F0 @ =0x060120E0
	str r0, [r2, #4]
	ldr r0, _0802D1F4 @ =0x800000E0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xe7
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0802D1F8 @ =gOamBuffer
	ldr r1, _0802D1FC @ =0xFFFFFE00
	mov ip, r1
_0802D198:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802D200 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _0802D198
_0802D1DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D1E4: .4byte 0x086AE344
_0802D1E8: .4byte 0x040000D4
_0802D1EC: .4byte 0x083C076C
_0802D1F0: .4byte 0x060120E0
_0802D1F4: .4byte 0x800000E0
_0802D1F8: .4byte gOamBuffer
_0802D1FC: .4byte 0xFFFFFE00
_0802D200: .4byte 0x000001FF

	thumb_func_start sub_2D204
sub_2D204: @ 0x0802D204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0802D358 @ =0xFFFFFDE0
	add sp, r4
	ldr r1, _0802D35C @ =0x020314E0
	ldr r2, [r1]
	ldrh r3, [r2, #0x18]
	adds r4, r3, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	cmp r4, r0
	bls _0802D226
	bl sub_2DE54
_0802D226:
	cmp r4, #0
	bne _0802D254
	bl m4aMPlayAllStop
	ldr r1, _0802D360 @ =0x040000D4
	ldr r0, _0802D364 @ =0x05000200
	str r0, [r1]
	ldr r2, _0802D35C @ =0x020314E0
	ldr r0, [r2]
	ldr r3, _0802D368 @ =0x0000111A
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r0, _0802D36C @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2]
	ldr r1, _0802D370 @ =0x000006DB
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r2]
	ldr r2, _0802D374 @ =0x000005FA
	adds r0, r0, r2
	strb r4, [r0]
_0802D254:
	ldr r3, _0802D35C @ =0x020314E0
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xa
	bne _0802D2AA
	adds r1, #0xe4
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0802D360 @ =0x040000D4
	ldr r0, _0802D378 @ =0x08158284
	str r0, [r1]
	ldr r0, _0802D37C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802D380 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802D384 @ =0x0815A6A4
	str r0, [r1]
	ldr r0, _0802D388 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0802D38C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0802D390 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x60]
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x64]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x68]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x6c]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x70]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x3c]
	strh r1, [r0]
_0802D2AA:
	ldr r4, _0802D35C @ =0x020314E0
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xeb
	bgt _0802D2C2
	ldrh r0, [r1, #0x18]
	lsrs r0, r0, #1
	adds r1, #0xe6
	strh r0, [r1]
_0802D2C2:
	ldr r3, _0802D35C @ =0x020314E0
	ldr r0, [r3]
	ldrh r0, [r0, #0x18]
	adds r3, r0, #0
	cmp r3, #0x23
	bhi _0802D2D0
	b _0802D3F6
_0802D2D0:
	cmp r3, #0x43
	bhi _0802D3A0
	subs r0, #0x24
	lsls r0, r0, #0x10
	movs r3, #0
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	ldr r4, _0802D394 @ =0x03005C00
	mov sb, r4
	cmp r3, r0
	bgt _0802D320
	mov r2, sb
	mov r8, r0
	movs r7, #0xc1
	lsls r7, r7, #8
_0802D2EE:
	movs r6, #1
	lsls r3, r3, #0x10
	asrs r4, r3, #0x10
_0802D2F4:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r7, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802D2F4
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	ble _0802D2EE
_0802D320:
	ldr r1, _0802D360 @ =0x040000D4
	mov r2, sb
	str r2, [r1]
	ldr r0, _0802D398 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802D39C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	cmp r5, #0x1e
	bne _0802D33A
	movs r0, #0x1a
	bl m4aSongNumStart
_0802D33A:
	ldr r0, _0802D390 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0802D3F6
	ldr r0, _0802D35C @ =0x020314E0
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x43
	bne _0802D3F6
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
	b _0802D3F6
	.align 2, 0
_0802D358: .4byte 0xFFFFFDE0
_0802D35C: .4byte 0x020314E0
_0802D360: .4byte 0x040000D4
_0802D364: .4byte 0x05000200
_0802D368: .4byte 0x0000111A
_0802D36C: .4byte 0x80000100
_0802D370: .4byte 0x000006DB
_0802D374: .4byte 0x000005FA
_0802D378: .4byte 0x08158284
_0802D37C: .4byte 0x06015800
_0802D380: .4byte 0x80001200
_0802D384: .4byte 0x0815A6A4
_0802D388: .4byte 0x050003C0
_0802D38C: .4byte 0x80000010
_0802D390: .4byte gMain
_0802D394: .4byte 0x03005C00
_0802D398: .4byte 0x06002000
_0802D39C: .4byte 0x80000400
_0802D3A0:
	movs r0, #0xac
	lsls r0, r0, #1
	cmp r3, r0
	bhi _0802D3F6
	movs r3, #0
	ldr r4, _0802D484 @ =0x03005C00
	mov sb, r4
	mov r5, sb
	movs r4, #0xc1
	lsls r4, r4, #8
_0802D3B4:
	movs r6, #1
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
_0802D3BA:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802D3BA
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	ble _0802D3B4
	ldr r1, _0802D488 @ =0x040000D4
	mov r2, sb
	str r2, [r1]
	ldr r0, _0802D48C @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802D490 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802D3F6:
	ldr r2, _0802D494 @ =0x020314E0
	ldr r1, [r2]
	ldr r3, _0802D498 @ =0xFFFFFEF2
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0802D40C
	b _0802D54C
_0802D40C:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _0802D4A4
	movs r6, #0
	mov sl, r0
	ldr r4, _0802D49C @ =0x020028A8
	mov sb, r4
	adds r0, r2, #0
	mov r8, r0
	ldr r7, _0802D4A0 @ =0x000012BA
	movs r1, #2
	add r1, sb
	mov ip, r1
_0802D428:
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r5, r2, #1
	adds r4, r5, r2
	mov r0, sb
	adds r3, r4, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	strb r0, [r3]
	mov r3, sb
	adds r3, #1
	adds r3, r4, r3
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strb r0, [r3]
	add r4, ip
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	lsrs r0, r0, #0xa
	strb r0, [r4]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xf
	ble _0802D428
	b _0802D53E
	.align 2, 0
_0802D484: .4byte 0x03005C00
_0802D488: .4byte 0x040000D4
_0802D48C: .4byte 0x06002000
_0802D490: .4byte 0x80000400
_0802D494: .4byte 0x020314E0
_0802D498: .4byte 0xFFFFFEF2
_0802D49C: .4byte 0x020028A8
_0802D4A0: .4byte 0x000012BA
_0802D4A4:
	movs r6, #0
	mov sl, r0
	movs r4, #0xd8
	lsls r4, r4, #1
	add r4, sp
	str r4, [sp, #0x214]
	add r7, sp, #0x210
	mov sb, r1
_0802D4B4:
	lsls r5, r6, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #1
	mov r8, r0
	adds r6, r0, r5
	ldr r1, _0802D5B8 @ =0x020028A8
	adds r0, r6, r1
	ldrb r4, [r0]
	movs r2, #0x1f
	subs r0, r2, r4
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7]
	ldr r0, _0802D5B8 @ =0x020028A8
	adds r0, #1
	adds r0, r6, r0
	ldrb r4, [r0]
	movs r1, #0x1f
	subs r0, r1, r4
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7, #1]
	ldr r3, _0802D5BC @ =0x020028AA
	adds r6, r6, r3
	ldrb r4, [r6]
	movs r1, #0x1f
	subs r0, r1, r4
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7, #2]
	ldr r3, [sp, #0x214]
	add r8, r3
	ldrb r1, [r7]
	ldrb r0, [r7, #1]
	lsls r0, r0, #5
	orrs r1, r0
	ldrb r0, [r7, #2]
	lsls r0, r0, #0xa
	orrs r1, r0
	mov r4, r8
	strh r1, [r4]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r6, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #0xf
	ble _0802D4B4
	ldr r1, _0802D5C0 @ =0x040000D4
	str r3, [r1]
	ldr r0, _0802D5C4 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0802D5C8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802D53E:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0xa
	bne _0802D54C
	movs r0, #0xb0
	bl m4aSongNumStart
_0802D54C:
	ldr r1, _0802D5CC @ =0x020314E0
	ldr r3, [r1]
	ldr r4, _0802D5D0 @ =0xFFFFFED4
	adds r2, r4, #0
	ldrh r4, [r3, #0x18]
	adds r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bhi _0802D582
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D5CC @ =0x020314E0
	ldr r0, [r1]
	ldrh r0, [r0, #0x18]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0802D5D4 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0x9f
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r5, [r0, #0x3c]
_0802D582:
	ldr r2, _0802D5CC @ =0x020314E0
	ldr r0, [r2]
	ldrh r2, [r0, #0x18]
	cmp r2, #0xa
	bhi _0802D58E
	b _0802DD32
_0802D58E:
	ldr r1, _0802D5D4 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x60]
	ldr r3, _0802D5D8 @ =0x0000FF88
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0802D5DC
	mov r4, sp
	subs r0, #0x16
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa0
	strh r1, [r4]
	b _0802D5E2
	.align 2, 0
_0802D5B8: .4byte 0x020028A8
_0802D5BC: .4byte 0x020028AA
_0802D5C0: .4byte 0x040000D4
_0802D5C4: .4byte 0x050003A0
_0802D5C8: .4byte 0x80000010
_0802D5CC: .4byte 0x020314E0
_0802D5D0: .4byte 0xFFFFFED4
_0802D5D4: .4byte gMain
_0802D5D8: .4byte 0x0000FF88
_0802D5DC:
	mov r1, sp
	ldr r0, _0802D604 @ =0x0000FF5E
	strh r0, [r1]
_0802D5E2:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0
	blt _0802D608
	mov r4, sp
	adds r0, r1, #0
	movs r1, #0x66
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #2]
	b _0802D60E
	.align 2, 0
_0802D604: .4byte 0x0000FF5E
_0802D608:
	mov r1, sp
	ldr r0, _0802D62C @ =0x0000FF5E
	strh r0, [r1, #2]
_0802D60E:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x47
	ble _0802D630
	mov r4, sp
	subs r0, #0x48
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #4]
	b _0802D636
	.align 2, 0
_0802D62C: .4byte 0x0000FF5E
_0802D630:
	mov r1, sp
	ldr r0, _0802D654 @ =0x0000FF5E
	strh r0, [r1, #4]
_0802D636:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x32
	ble _0802D658
	mov r4, sp
	subs r0, #0x33
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa1
	strh r1, [r4, #6]
	b _0802D65E
	.align 2, 0
_0802D654: .4byte 0x0000FF5E
_0802D658:
	mov r1, sp
	ldr r0, _0802D6F8 @ =0x0000FF5F
	strh r0, [r1, #6]
_0802D65E:
	ldr r2, _0802D6FC @ =0x020314E0
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D700 @ =gOamBuffer
	ldr r4, _0802D704 @ =0xFFFFFE00
	mov r8, r4
_0802D684:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r0, #2
	ldrsh r2, [r7, r0]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D708 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D684
	ldr r2, _0802D6FC @ =0x020314E0
	ldr r1, [r2]
	ldr r3, _0802D70C @ =0x0000FFC4
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0802D710
	mov r4, sp
	subs r0, #0x16
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa0
	strh r1, [r4]
	b _0802D716
	.align 2, 0
_0802D6F8: .4byte 0x0000FF5F
_0802D6FC: .4byte 0x020314E0
_0802D700: .4byte gOamBuffer
_0802D704: .4byte 0xFFFFFE00
_0802D708: .4byte 0x000001FF
_0802D70C: .4byte 0x0000FFC4
_0802D710:
	mov r1, sp
	ldr r0, _0802D738 @ =0x0000FF5E
	strh r0, [r1]
_0802D716:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0
	blt _0802D73C
	mov r4, sp
	adds r0, r1, #0
	movs r1, #0x66
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #2]
	b _0802D742
	.align 2, 0
_0802D738: .4byte 0x0000FF5E
_0802D73C:
	mov r1, sp
	ldr r0, _0802D760 @ =0x0000FF5E
	strh r0, [r1, #2]
_0802D742:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x47
	ble _0802D764
	mov r4, sp
	subs r0, #0x48
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #4]
	b _0802D76A
	.align 2, 0
_0802D760: .4byte 0x0000FF5E
_0802D764:
	mov r1, sp
	ldr r0, _0802D788 @ =0x0000FF5E
	strh r0, [r1, #4]
_0802D76A:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x32
	ble _0802D78C
	mov r4, sp
	subs r0, #0x33
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa1
	strh r1, [r4, #6]
	b _0802D792
	.align 2, 0
_0802D788: .4byte 0x0000FF5E
_0802D78C:
	mov r1, sp
	ldr r0, _0802D834 @ =0x0000FF5F
	strh r0, [r1, #6]
_0802D792:
	ldr r2, _0802D838 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x64]
	ldr r3, _0802D83C @ =0x020314E0
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D840 @ =gOamBuffer
	ldr r0, _0802D844 @ =0xFFFFFE00
	mov r8, r0
_0802D7BE:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D848 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D7BE
	ldr r2, _0802D838 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x68]
	ldr r3, _0802D83C @ =0x020314E0
	ldr r1, [r3]
	ldr r4, _0802D84C @ =0x0000FF9C
	adds r0, r4, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802D850
	mov r4, sp
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	subs r0, #0xa0
	strh r0, [r4]
	b _0802D856
	.align 2, 0
_0802D834: .4byte 0x0000FF5F
_0802D838: .4byte gMain
_0802D83C: .4byte 0x020314E0
_0802D840: .4byte gOamBuffer
_0802D844: .4byte 0xFFFFFE00
_0802D848: .4byte 0x000001FF
_0802D84C: .4byte 0x0000FF9C
_0802D850:
	mov r1, sp
	ldr r0, _0802D874 @ =0x0000FF60
	strh r0, [r1]
_0802D856:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0x25
	ble _0802D878
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0x26
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #2]
	b _0802D87E
	.align 2, 0
_0802D874: .4byte 0x0000FF60
_0802D878:
	mov r1, sp
	ldr r0, _0802D898 @ =0x0000FF60
	strh r0, [r1, #2]
_0802D87E:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x4b
	ble _0802D89C
	mov r4, sp
	subs r0, #0x4c
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #4]
	b _0802D8A2
	.align 2, 0
_0802D898: .4byte 0x0000FF60
_0802D89C:
	mov r1, sp
	ldr r0, _0802D8BC @ =0x0000FF60
	strh r0, [r1, #4]
_0802D8A2:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x71
	ble _0802D8C0
	mov r4, sp
	subs r0, #0x72
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #6]
	b _0802D8C6
	.align 2, 0
_0802D8BC: .4byte 0x0000FF60
_0802D8C0:
	mov r1, sp
	ldr r0, _0802D964 @ =0x0000FF60
	strh r0, [r1, #6]
_0802D8C6:
	ldr r3, _0802D968 @ =0x020314E0
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D96C @ =gOamBuffer
	ldr r0, _0802D970 @ =0xFFFFFE00
	mov r8, r0
_0802D8EC:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D974 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D8EC
	ldr r2, _0802D978 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x6c]
	ldr r3, _0802D968 @ =0x020314E0
	ldr r1, [r3]
	ldr r4, _0802D97C @ =0x0000FFB0
	adds r0, r4, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802D980
	mov r4, sp
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	subs r0, #0xa0
	strh r0, [r4]
	b _0802D986
	.align 2, 0
_0802D964: .4byte 0x0000FF60
_0802D968: .4byte 0x020314E0
_0802D96C: .4byte gOamBuffer
_0802D970: .4byte 0xFFFFFE00
_0802D974: .4byte 0x000001FF
_0802D978: .4byte gMain
_0802D97C: .4byte 0x0000FFB0
_0802D980:
	mov r1, sp
	ldr r0, _0802D9A4 @ =0x0000FF60
	strh r0, [r1]
_0802D986:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0x25
	ble _0802D9A8
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0x26
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #2]
	b _0802D9AE
	.align 2, 0
_0802D9A4: .4byte 0x0000FF60
_0802D9A8:
	mov r1, sp
	ldr r0, _0802D9C8 @ =0x0000FF60
	strh r0, [r1, #2]
_0802D9AE:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x4b
	ble _0802D9CC
	mov r4, sp
	subs r0, #0x4c
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #4]
	b _0802D9D2
	.align 2, 0
_0802D9C8: .4byte 0x0000FF60
_0802D9CC:
	mov r1, sp
	ldr r0, _0802D9EC @ =0x0000FF60
	strh r0, [r1, #4]
_0802D9D2:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x71
	ble _0802D9F0
	mov r4, sp
	subs r0, #0x72
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #6]
	b _0802D9F6
	.align 2, 0
_0802D9EC: .4byte 0x0000FF60
_0802D9F0:
	mov r1, sp
	ldr r0, _0802DA8C @ =0x0000FF60
	strh r0, [r1, #6]
_0802D9F6:
	ldr r3, _0802DA90 @ =0x020314E0
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802DA94 @ =gOamBuffer
	ldr r0, _0802DA98 @ =0xFFFFFE00
	mov r8, r0
_0802DA1C:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802DA9C @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802DA1C
	ldr r2, _0802DA90 @ =0x020314E0
	ldr r1, [r2]
	ldr r3, _0802DAA0 @ =0x0000FFA6
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xeb
	ble _0802DAA4
	mov r4, sp
	subs r0, #0xec
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4]
	b _0802DAAA
	.align 2, 0
_0802DA8C: .4byte 0x0000FF60
_0802DA90: .4byte 0x020314E0
_0802DA94: .4byte gOamBuffer
_0802DA98: .4byte 0xFFFFFE00
_0802DA9C: .4byte 0x000001FF
_0802DAA0: .4byte 0x0000FFA6
_0802DAA4:
	mov r1, sp
	ldr r0, _0802DAC8 @ =0x0000FF80
	strh r0, [r1]
_0802DAAA:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0xcb
	ble _0802DACC
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0xcc
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #2]
	b _0802DAD2
	.align 2, 0
_0802DAC8: .4byte 0x0000FF80
_0802DACC:
	mov r1, sp
	ldr r0, _0802DAEC @ =0x0000FF80
	strh r0, [r1, #2]
_0802DAD2:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0xa7
	ble _0802DAF0
	mov r4, sp
	subs r0, #0xa8
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #4]
	b _0802DAF6
	.align 2, 0
_0802DAEC: .4byte 0x0000FF80
_0802DAF0:
	mov r1, sp
	ldr r0, _0802DB10 @ =0x0000FF80
	strh r0, [r1, #4]
_0802DAF6:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x87
	ble _0802DB14
	mov r4, sp
	subs r0, #0x88
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #6]
	b _0802DB1A
	.align 2, 0
_0802DB10: .4byte 0x0000FF80
_0802DB14:
	mov r1, sp
	ldr r0, _0802DB34 @ =0x0000FF80
	strh r0, [r1, #6]
_0802DB1A:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x63
	ble _0802DB38
	mov r4, sp
	subs r0, #0x64
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #8]
	b _0802DB3E
	.align 2, 0
_0802DB34: .4byte 0x0000FF80
_0802DB38:
	mov r1, sp
	ldr r0, _0802DB58 @ =0x0000FF80
	strh r0, [r1, #8]
_0802DB3E:
	mov r3, sl
	asrs r0, r3, #0x10
	cmp r0, #0x43
	ble _0802DB5C
	mov r4, sp
	subs r0, #0x44
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xa]
	b _0802DB62
	.align 2, 0
_0802DB58: .4byte 0x0000FF80
_0802DB5C:
	mov r1, sp
	ldr r0, _0802DB7C @ =0x0000FF80
	strh r0, [r1, #0xa]
_0802DB62:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x1f
	ble _0802DB80
	mov r4, sp
	subs r0, #0x20
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xc]
	b _0802DB86
	.align 2, 0
_0802DB7C: .4byte 0x0000FF80
_0802DB80:
	mov r1, sp
	ldr r0, _0802DBA0 @ =0x0000FF80
	strh r0, [r1, #0xc]
_0802DB86:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _0802DBA4
	mov r4, sp
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xe]
	b _0802DBAA
	.align 2, 0
_0802DBA0: .4byte 0x0000FF80
_0802DBA4:
	mov r1, sp
	ldr r0, _0802DC74 @ =0x0000FF80
	strh r0, [r1, #0xe]
_0802DBAA:
	ldr r2, _0802DC78 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x70]
	ldr r3, _0802DC7C @ =0x020314E0
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802DC80 @ =gOamBuffer
	mov r8, r0