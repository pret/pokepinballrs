#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text
	.align 2, 0


	thumb_func_start sub_11C14
sub_11C14: @ 0x08011C14
	push {r4, r5, lr}
	ldr r3, _08011C6C @ =gCurrentPinballGame
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _08011C70 @ =0x00001334
	adds r1, r1, r0
	ldr r0, [r3]
	adds r4, r0, r1
	ldr r1, _08011C74 @ =gUnknown_02031520
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
_08011C6C: .4byte gCurrentPinballGame
_08011C70: .4byte 0x00001334
_08011C74: .4byte gUnknown_02031520
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
	ldr r0, _08011CE0 @ =gCurrentPinballGame
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
	ldr r0, _08011CEC @ =gUnknown_08137910
	b _08011CFE
	.align 2, 0
_08011CE0: .4byte gCurrentPinballGame
_08011CE4: .4byte 0x0000132C
_08011CE8: .4byte 0x000005A4
_08011CEC: .4byte gUnknown_08137910
_08011CF0:
	cmp r0, #0x50
	ble _08011CFC
	ldr r0, _08011CF8 @ =gUnknown_08137908
	b _08011CFE
	.align 2, 0
_08011CF8: .4byte gUnknown_08137908
_08011CFC:
	ldr r0, _08011D8C @ =gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
_08011D8C: .4byte gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r0, _08011E18 @ =gUnknown_08137910
	b _08011E2A
	.align 2, 0
_08011E18: .4byte gUnknown_08137910
_08011E1C:
	cmp r0, #0x64
	ble _08011E28
	ldr r0, _08011E24 @ =gUnknown_08137908
	b _08011E2A
	.align 2, 0
_08011E24: .4byte gUnknown_08137908
_08011E28:
	ldr r0, _08011EB8 @ =gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
_08011EB8: .4byte gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r2, _08011FD0 @ =gCurrentPinballGame
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
	ldr r0, _08011FE0 @ =gUnknown_08137910
	b _08011FF2
	.align 2, 0
_08011FD0: .4byte gCurrentPinballGame
_08011FD4: .4byte 0x0000132C
_08011FD8: .4byte 0x000005A4
_08011FDC: .4byte 0x00000383
_08011FE0: .4byte gUnknown_08137910
_08011FE4:
	cmp r0, #0x4b
	ble _08011FF0
	ldr r0, _08011FEC @ =gUnknown_08137908
	b _08011FF2
	.align 2, 0
_08011FEC: .4byte gUnknown_08137908
_08011FF0:
	ldr r0, _0801208C @ =gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
_0801208C: .4byte gUnknown_08137900
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r2, _080125F0 @ =gCurrentPinballGame
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
	ldr r6, _080125F0 @ =gCurrentPinballGame
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
	ldr r0, _080125F0 @ =gCurrentPinballGame
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
	ldr r1, _080125F0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _080125FC @ =0x000005F6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _08012604 @ =gUnknown_08137E14
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
	ldr r6, _080125F0 @ =gCurrentPinballGame
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
_080125F0: .4byte gCurrentPinballGame
_080125F4: .4byte 0x0000132C
_080125F8: .4byte 0x000005F7
_080125FC: .4byte 0x000005F6
_08012600: .4byte 0x040000D4
_08012604: .4byte gUnknown_08137E14
_08012608: .4byte 0x05000220
_0801260C: .4byte 0x80000010
_08012610: .4byte 0x000005B2
_08012614:
	ldr r4, _080126C8 @ =gCurrentPinballGame
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
	bl SetMatrixScale
	ldr r0, _080126C8 @ =gCurrentPinballGame
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
_080126C8: .4byte gCurrentPinballGame
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
	ldr r4, _0801276C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _08012770 @ =0x000005F6
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r0, r2, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r1, r1, #7
	ldr r0, _08012774 @ =gUnknown_083BB16C
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
_0801276C: .4byte gCurrentPinballGame
_08012770: .4byte 0x000005F6
_08012774: .4byte gUnknown_083BB16C
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
	bl SetMatrixScale
	ldr r0, _08012828 @ =gCurrentPinballGame
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
_08012828: .4byte gCurrentPinballGame
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
	ldr r4, _080128C4 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _080128C8 @ =0x000005F6
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r0, r2, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r1, r1, #7
	ldr r0, _080128CC @ =gUnknown_083BB16C
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
_080128C4: .4byte gCurrentPinballGame
_080128C8: .4byte 0x000005F6
_080128CC: .4byte gUnknown_083BB16C
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
	ldr r5, _080129D0 @ =gCurrentPinballGame
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
	ldr r0, _080129D0 @ =gCurrentPinballGame
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
	ldr r6, _080129D0 @ =gCurrentPinballGame
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
_080129D0: .4byte gCurrentPinballGame
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
	ldr r1, _08012B20 @ =gCurrentPinballGame
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
	ldr r4, _08012B20 @ =gCurrentPinballGame
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
_08012B20: .4byte gCurrentPinballGame
_08012B24: .4byte 0x000001FF
_08012B28: .4byte 0x0000071C
_08012B2C:
	movs r0, #0
	strh r0, [r6, #2]
	movs r0, #0xb4
_08012B32:
	strh r0, [r6, #4]
	ldr r3, _08012BD0 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x6e
	ldr r2, _08012BD4 @ =0x040000D4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #9
	ldr r1, _08012BD8 @ =gUnknown_083BD36C
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
	ldr r3, _08012BD0 @ =gCurrentPinballGame
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
_08012BD0: .4byte gCurrentPinballGame
_08012BD4: .4byte 0x040000D4
_08012BD8: .4byte gUnknown_083BD36C
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
	ldr r3, _08012C30 @ =gCurrentPinballGame
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
_08012C30: .4byte gCurrentPinballGame
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
	ldr r0, _08012C70 @ =gUnknown_02031590
	ldrb r1, [r0, #0x16]
	movs r0, #0xb8
	muls r1, r0, r1
	ldr r0, _08012C74 @ =gUnknown_0200B3B8
	adds r6, r1, r0
	b _08012CAC
	.align 2, 0
_08012C70: .4byte gUnknown_02031590
_08012C74: .4byte gUnknown_0200B3B8
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
	ldr r1, _08012DD0 @ =gUnknown_083BB16C
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
_08012DD0: .4byte gUnknown_083BB16C
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
	movs r0, SE_UNKNOWN_0xF9
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
	ldr r1, _08012F98 @ =gUnknown_083BF16C
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
	ldr r1, _08012FAC @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08012FB0 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _08012FB4 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08012F30:
	ldr r3, _08012FB8 @ =gCurrentPinballGame
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
_08012F98: .4byte gUnknown_083BF16C
_08012F9C: .4byte 0x06010720
_08012FA0: .4byte 0x80000100
_08012FA4: .4byte 0xFFF90000
_08012FA8: .4byte 0x000005F6
_08012FAC: .4byte gUnknown_08137E14
_08012FB0: .4byte 0x05000220
_08012FB4: .4byte 0x80000010
_08012FB8: .4byte gCurrentPinballGame
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
	ldr r1, _08013084 @ =gUnknown_083BDF6C
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
	movs r0, SE_UNKNOWN_0xF9
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
	ldr r0, _08013094 @ =gCurrentPinballGame
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
	ldr r3, _08013094 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r4, _08013098 @ =0x000005F6
	adds r0, r0, r4
	b _080130F2
	.align 2, 0
_0801307C: .4byte 0x00000392
_08013080: .4byte 0x040000D4
_08013084: .4byte gUnknown_083BDF6C
_08013088: .4byte 0x06010720
_0801308C: .4byte 0x80000100
_08013090: .4byte gMain
_08013094: .4byte gCurrentPinballGame
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
	ldr r1, _08013210 @ =gUnknown_08137E14
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
	ldr r0, _08013220 @ =gCurrentPinballGame
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
_08013210: .4byte gUnknown_08137E14
_08013214: .4byte 0x05000220
_08013218: .4byte 0x80000010
_0801321C: .4byte gMain
_08013220: .4byte gCurrentPinballGame
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
	ldr r0, _08013338 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	bx lr
	.align 2, 0
_08013338: .4byte gCurrentPinballGame

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
	ldr r0, _0801336C @ =gCurrentPinballGame
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
_0801336C: .4byte gCurrentPinballGame
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
	ldr r0, _080133A4 @ =gCurrentPinballGame
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
_080133A4: .4byte gCurrentPinballGame
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
	ldr r0, _0801341C @ =gCurrentPinballGame
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
	ldr r2, _08013424 @ =gUnknown_086ACD50
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
	ldr r0, _0801341C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _08013420 @ =0x0000132C
	adds r1, r1, r3
	ldr r2, [r1]
	mov r6, r8
	ldrh r0, [r6]
	b _080134DA
	.align 2, 0
_0801341C: .4byte gCurrentPinballGame
_08013420: .4byte 0x0000132C
_08013424: .4byte gUnknown_086ACD50
_08013428:
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r0, _08013464 @ =gCurrentPinballGame
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
_08013464: .4byte gCurrentPinballGame
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
	ldr r0, _080134F0 @ =gCurrentPinballGame
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
	ldr r2, _080134F8 @ =gUnknown_086ACD50
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
	ldr r0, _080134F0 @ =gCurrentPinballGame
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
_080134F0: .4byte gCurrentPinballGame
_080134F4: .4byte 0x0000132C
_080134F8: .4byte gUnknown_086ACD50
_080134FC:
	mov r4, sp
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r2, _08013560 @ =gUnknown_02031520
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
	ldr r6, _08013564 @ =gCurrentPinballGame
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
_08013560: .4byte gUnknown_02031520
_08013564: .4byte gCurrentPinballGame
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
	ldr r0, _08013608 @ =gCurrentPinballGame
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
	ldr r2, _0801360C @ =gUnknown_086ACD74
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
	ldr r3, _08013610 @ =gUnknown_02031520
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
_08013608: .4byte gCurrentPinballGame
_0801360C: .4byte gUnknown_086ACD74
_08013610: .4byte gUnknown_02031520
_08013614:
	mov r4, sp
	add r5, sp, #4
	mov r0, sp
	adds r1, r5, #0
	adds r2, r7, #0
	bl sub_13934
	ldr r2, _08013674 @ =gUnknown_02031520
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
	ldr r6, _08013678 @ =gCurrentPinballGame
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
_08013674: .4byte gUnknown_02031520
_08013678: .4byte gCurrentPinballGame
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
	ldr r0, _0801374C @ =gCurrentPinballGame
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
	ldr r2, _08013750 @ =gUnknown_086ACD74
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
	ldr r3, _08013754 @ =gUnknown_02031520
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
_0801374C: .4byte gCurrentPinballGame
_08013750: .4byte gUnknown_086ACD74
_08013754: .4byte gUnknown_02031520
_08013758:
	ldr r0, _08013788 @ =gCurrentPinballGame
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
_08013788: .4byte gCurrentPinballGame
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
	ldr r0, _0801381C @ =gCurrentPinballGame
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
	ldr r0, _0801381C @ =gCurrentPinballGame
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
_0801381C: .4byte gCurrentPinballGame
_08013820: .4byte 0x000005F3

	thumb_func_start sub_13824
sub_13824: @ 0x08013824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _0801391C @ =gCurrentPinballGame
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
_0801391C: .4byte gCurrentPinballGame
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
	ldr r7, _0801399C @ =gCurrentPinballGame
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
	bl sub_0C74
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080139D6
	adds r0, r4, #0
	bl sub_0C74
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
_0801399C: .4byte gCurrentPinballGame
_080139A0: .4byte 0x00004E20
_080139A4:
	cmp r0, #0
	bge _080139D6
	adds r0, r4, #0
	bl sub_0C74
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080139D6
	adds r0, r4, #0
	bl sub_0C74
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
	ldr r1, _08013A34 @ =gCurrentPinballGame
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
	bl sub_0C24
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #1
	b _08013A52
	.align 2, 0
_08013A30: .4byte 0x00004E20
_08013A34: .4byte gCurrentPinballGame
_08013A38: .4byte 0x00000123
_08013A3C: .4byte 0x00000125
_08013A40: .4byte 0x0000132C
_08013A44:
	adds r0, r4, #0
	bl sub_0C24
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
	bl sub_0C24
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
	bl sub_0C24
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
	ldr r0, _08013AC0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _08013AC4 @ =0x0000132C
	adds r0, r0, r1
	b _08013AD4
	.align 2, 0
_08013ABC: .4byte 0x00004E20
_08013AC0: .4byte gCurrentPinballGame
_08013AC4: .4byte 0x0000132C
_08013AC8:
	cmp r1, #0x45
	ble _08013AE4
	ldr r0, _08013B1C @ =gCurrentPinballGame
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
	ldr r0, _08013B1C @ =gCurrentPinballGame
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
_08013B1C: .4byte gCurrentPinballGame
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
	ldr r0, _08013C1C @ =gCurrentPinballGame
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
_08013C1C: .4byte gCurrentPinballGame
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
	ldr r0, _08013CAC @ =gCurrentPinballGame
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
	ldr r3, _08013CC0 @ =gUnknown_086ACD84
	adds r0, r0, r3
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	b _08013CDC
	.align 2, 0
_08013CAC: .4byte gCurrentPinballGame
_08013CB0: .4byte 0x000013BC
_08013CB4: .4byte 0x000013BD
_08013CB8: .4byte 0x000013BE
_08013CBC: .4byte 0x000013C1
_08013CC0: .4byte gUnknown_086ACD84
_08013CC4:
	ldr r6, _08013CE8 @ =0x000013C1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #2
	ldr r1, _08013CEC @ =gUnknown_086ACD86
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
_08013CEC: .4byte gUnknown_086ACD86
_08013CF0:
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt _08013D08
	ldr r0, _08013D04 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #5
	strb r1, [r0]
	b _08013D14
	.align 2, 0
_08013D04: .4byte gCurrentPinballGame
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
	bl sub_0C24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	ldr r5, _08013E40 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	str r0, [sp, #0x1c]
	adds r0, r4, #0
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	adds r7, r0, #0
	adds r0, r4, #0
	bl sub_0C74
	lsls r0, r0, #0x10
	ldr r1, _08013E44 @ =0x1F3F0000
	cmp r0, r1
	ble _08013E2A
	cmp r7, #0x46
	ble _08013E02
	movs r0, SE_UNKNOWN_0x77
	bl m4aSongNumStart
_08013E02:
	movs r0, #0x8c
	lsls r0, r0, #1
	cmp r7, r0
	ble _08013E2A
	ldr r0, _08013E48 @ =gCurrentPinballGame
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
	ldr r0, _08013E48 @ =gCurrentPinballGame
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
_08013E48: .4byte gCurrentPinballGame
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
	ldr r2, _08014004 @ =gCurrentPinballGame
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
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	str r0, [sp]
	ldr r0, [sp, #8]
	bl sub_0C24
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
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x1c]
	muls r0, r2, r0
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r5, #0
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r0, _08014004 @ =gCurrentPinballGame
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
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	adds r1, r7, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl sub_0C24
	ldr r2, [sp, #0x18]
	rsbs r1, r2, #0
	b _0801403E
	.align 2, 0
_08014004: .4byte gCurrentPinballGame
_08014008: .4byte 0x0000132C
_0801400C: .4byte 0x00000EB8
_08014010: .4byte 0x00004E20
_08014014: .4byte 0xFFFF0000
_08014018: .4byte 0x0000FFFF
_0801401C: .4byte gMain
_08014020:
	adds r0, r5, #0
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r6, r0
	ldr r4, _08014070 @ =0x00004E20
	adds r1, r4, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r5, #0
	bl sub_0C24
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
	ldr r0, _080140CC @ =gCurrentPinballGame
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
_080140CC: .4byte gCurrentPinballGame
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
	ldr r0, _08014180 @ =gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
_08014180: .4byte gCurrentPinballGame
_08014184: .4byte 0x0000132C
_08014188: .4byte 0x00004E20
_0801418C: .4byte 0xFFFF0000
_08014190:
	adds r0, r7, #0
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r2, _08014210 @ =gCurrentPinballGame
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
_08014210: .4byte gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
	ldr r5, _080143D4 @ =gUnknown_086ACDF4
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
	bl sub_0C24
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
	ldr r1, _080143E4 @ =gCurrentPinballGame
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
_080143D4: .4byte gUnknown_086ACDF4
_080143D8: .4byte 0x00004E20
_080143DC: .4byte 0xFFFF0000
_080143E0: .4byte 0x0000FFFF
_080143E4: .4byte gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r2, _08014518 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x22
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x23
	strb r1, [r0]
	ldr r1, _0801451C @ =gUnknown_086ACE0C
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
_08014518: .4byte gCurrentPinballGame
_0801451C: .4byte gUnknown_086ACE0C
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
	ldr r5, _080145A0 @ =gCurrentPinballGame
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
_080145A0: .4byte gCurrentPinballGame
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
	ldr r0, _0801465C @ =gCurrentPinballGame
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
	ldr r0, _08014660 @ =gUnknown_086ACE60
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
	ldr r0, _0801465C @ =gCurrentPinballGame
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
_0801465C: .4byte gCurrentPinballGame
_08014660: .4byte gUnknown_086ACE60
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
	ldr r4, _08014734 @ =gUnknown_02031520
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
	ldr r4, _08014738 @ =gCurrentPinballGame
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
	ldr r4, _08014738 @ =gCurrentPinballGame
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
_08014734: .4byte gUnknown_02031520
_08014738: .4byte gCurrentPinballGame
_0801473C: .4byte 0xFFFF0000

	thumb_func_start sub_14740
sub_14740: @ 0x08014740
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r7, r1, #0
	movs r6, #0
	ldr r0, _080147E8 @ =gCurrentPinballGame
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
	ldr r1, _080147F0 @ =gUnknown_0839A28C
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
_080147E8: .4byte gCurrentPinballGame
_080147EC: .4byte 0x000005A4
_080147F0: .4byte gUnknown_0839A28C
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
	movs r0, SE_UNKNOWN_0x74
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
	ldr r0, _08014A28 @ =gCurrentPinballGame
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
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	ldr r6, _08014A38 @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp]
	adds r0, r4, #0
	bl sub_0C24
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
	ldr r0, _08014A28 @ =gCurrentPinballGame
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
_08014A28: .4byte gCurrentPinballGame
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
	ldr r2, _08014AEC @ =gCurrentPinballGame
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
_08014AEC: .4byte gCurrentPinballGame
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
	ldr r2, _08014B70 @ =gCurrentPinballGame
	lsls r3, r3, #0x10
	asrs r6, r3, #0x10
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r3, _08014B74 @ =0x000013BC
	adds r0, r0, r3
	ldr r3, [r2]
	adds r3, r3, r0
	ldr r5, _08014B78 @ =gUnknown_086ACDB8
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
	ldr r0, _08014B7C @ =gUnknown_02031520
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
_08014B70: .4byte gCurrentPinballGame
_08014B74: .4byte 0x000013BC
_08014B78: .4byte gUnknown_086ACDB8
_08014B7C: .4byte gUnknown_02031520
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
	ldr r0, _08014C20 @ =gCurrentPinballGame
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
_08014C20: .4byte gCurrentPinballGame
_08014C24: .4byte 0x000013C1
_08014C28: .4byte 0x000013C4
_08014C2C: .4byte 0x00000B21
_08014C30: .4byte 0xFFFFF5D8
_08014C34:
	ldr r0, _08014D14 @ =gUnknown_086ACE2C
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
	ldr r2, _08014D20 @ =gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
	ldr r2, _08014D20 @ =gCurrentPinballGame
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
_08014D14: .4byte gUnknown_086ACE2C
_08014D18: .4byte 0xFFFFF5D8
_08014D1C: .4byte 0x00001518
_08014D20: .4byte gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
	bl sub_0C74
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	mov r3, r8
	strh r0, [r3]
	adds r0, r4, #0
	bl sub_0C24
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
	ldr r0, _08014F0C @ =gCurrentPinballGame
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
	ldr r7, _08014F1C @ =gUnknown_02031520
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
_08014F0C: .4byte gCurrentPinballGame
_08014F10: .4byte 0x0000132C
_08014F14: .4byte 0xFFFF0000
_08014F18: .4byte 0x0000FFFF
_08014F1C: .4byte gUnknown_02031520
_08014F20: .4byte _08014F24
_08014F24: @ jump table
	.4byte _08014F3C @ case 0
	.4byte _08014FE8 @ case 1
	.4byte _08014FE8 @ case 2
	.4byte _08014F3C @ case 3
	.4byte _08015018 @ case 4
	.4byte _08014F3C @ case 5
_08014F3C:
	ldr r2, _08014FB4 @ =gCurrentPinballGame
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
	ldr r4, _08014FC0 @ =gUnknown_02031520
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
_08014FB4: .4byte gCurrentPinballGame
_08014FB8: .4byte 0xFFFFC010
_08014FBC: .4byte 0x0000132C
_08014FC0: .4byte gUnknown_02031520
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
	ldr r2, _08015010 @ =gCurrentPinballGame
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
_08015010: .4byte gCurrentPinballGame
_08015014: .4byte 0x0000FFF0
_08015018:
	ldr r2, _0801504C @ =gCurrentPinballGame
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
_0801504C: .4byte gCurrentPinballGame
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
	ldr r0, _08015128 @ =gCurrentPinballGame
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
	ldr r2, _08015134 @ =gUnknown_08259C10
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
_08015128: .4byte gCurrentPinballGame
_0801512C: .4byte 0x000005B2
_08015130: .4byte 0x000002A3
_08015134: .4byte gUnknown_08259C10
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
	ldr r2, _08015288 @ =gUnknown_08252B10
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
	ldr r2, _08015288 @ =gUnknown_08252B10
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
	ldr r2, _08015288 @ =gUnknown_08252B10
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
_08015288: .4byte gUnknown_08252B10
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
	ldr r2, _080153B4 @ =gUnknown_08254B10
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
	ldr r2, _080153C8 @ =gUnknown_08257390
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
_080153B4: .4byte gUnknown_08254B10
_080153B8: .4byte 0x0000FFF0
_080153BC: .4byte 0x000002E2
_080153C0: .4byte 0x000002E6
_080153C4: .4byte 0x000002EE
_080153C8: .4byte gUnknown_08257390

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
	ldr r0, _0801545C @ =gCurrentPinballGame
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
_0801545C: .4byte gCurrentPinballGame
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
	ldr r0, _08015490 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	movs r0, #1
	strh r0, [r7]
	bl _08016082
	.align 2, 0
_08015490: .4byte gCurrentPinballGame
_08015494:
	ldr r3, _080154B8 @ =gCurrentPinballGame
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
_080154B8: .4byte gCurrentPinballGame
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
	ldr r1, _08015508 @ =gCurrentPinballGame
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
_08015508: .4byte gCurrentPinballGame
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
	ldr r1, _080155B8 @ =gCurrentPinballGame
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
_080155B8: .4byte gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0x76
	bl m4aSongNumStart
	bl _08016082
	.align 2, 0
_0801561C: .4byte 0x000002B2
_08015620:
	ldr r1, _08015640 @ =gCurrentPinballGame
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
_08015640: .4byte gCurrentPinballGame
_08015644: .4byte 0x00000165
_08015648: .4byte 0x00000732
_0801564C:
	ldr r4, _08015670 @ =gCurrentPinballGame
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
_08015670: .4byte gCurrentPinballGame
_08015674: .4byte 0x000005B2
_08015678: .4byte 0x0000029E
_0801567C:
	ldr r5, _080156C4 @ =gCurrentPinballGame
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
_080156C4: .4byte gCurrentPinballGame
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
	ldr r0, _0801575C @ =gCurrentPinballGame
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
_0801575C: .4byte gCurrentPinballGame
_08015760: .4byte 0x00000732
_08015764:
	ldr r0, _080157A8 @ =gCurrentPinballGame
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
_080157A8: .4byte gCurrentPinballGame
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
	ldr r0, _080157FC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r4, _08015800 @ =0x0000072E
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x99
	bl m4aSongNumStart
_080157DC:
	ldr r0, _080157FC @ =gCurrentPinballGame
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
_080157FC: .4byte gCurrentPinballGame
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
	ldr r5, _08015A88 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r4, _08015A8C @ =0x0000072F
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08015A90 @ =gMPlayInfo_SE1
	ldr r1, _08015A94 @ =gUnknown_0869FC0C
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
	ldr r0, _08015A88 @ =gCurrentPinballGame
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
_08015A88: .4byte gCurrentPinballGame
_08015A8C: .4byte 0x0000072F
_08015A90: .4byte gMPlayInfo_SE1
_08015A94: .4byte gUnknown_0869FC0C
_08015A98: .4byte 0x00000731
_08015A9C: .4byte 0x000006BC
_08015AA0: .4byte 0x00000732
_08015AA4:
	ldr r0, _08015AC0 @ =gCurrentPinballGame
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
_08015AC0: .4byte gCurrentPinballGame
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
	ldr r4, _08015B48 @ =gCurrentPinballGame
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
_08015B48: .4byte gCurrentPinballGame
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
	ldr r1, _08015D18 @ =gCurrentPinballGame
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
_08015D18: .4byte gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0xD8
	bl m4aSongNumStart
_08015DB6:
	ldr r2, _08015DD8 @ =gCurrentPinballGame
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
_08015DD8: .4byte gCurrentPinballGame
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
	ldr r6, _08015EA4 @ =gCurrentPinballGame
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
_08015EA4: .4byte gCurrentPinballGame
_08015EA8: .4byte 0x00000616
_08015EAC: .4byte 0x0000132C
_08015EB0: .4byte 0x00000614
_08015EB4:
	ldr r3, _08015F14 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	b _08016020
	.align 2, 0
_08015F14: .4byte gCurrentPinballGame
_08015F18: .4byte 0x000002DA
_08015F1C: .4byte 0x00001388
_08015F20:
	ldr r4, _08015F80 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r1, [r4]
	ldr r0, _08015F88 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015F80: .4byte gCurrentPinballGame
_08015F84: .4byte 0x000002DA
_08015F88: .4byte 0x00001388
_08015F8C:
	ldr r0, _08015FE8 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0xB7
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _08015FF0 @ =0x00001388
	str r0, [r1, #0x3c]
	b _08016020
	.align 2, 0
_08015FE8: .4byte gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0xB7
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
	movs r0, SE_UNKNOWN_0xB7
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
	ldr r0, _08016190 @ =gCurrentPinballGame
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
	ldr r7, _080161A0 @ =gUnknown_02031520
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
_08016190: .4byte gCurrentPinballGame
_08016194: .4byte 0x0000132C
_08016198: .4byte 0xFFFF0000
_0801619C: .4byte 0x0000FFFF
_080161A0: .4byte gUnknown_02031520
_080161A4:
	cmp r1, #4
	bne _08016290
_080161A8:
	ldr r2, _08016208 @ =gCurrentPinballGame
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
	ldr r4, _08016214 @ =gUnknown_02031520
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
_08016208: .4byte gCurrentPinballGame
_0801620C: .4byte 0xFFFFC010
_08016210: .4byte 0x0000132C
_08016214: .4byte gUnknown_02031520
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
	ldr r2, _080162B0 @ =gCurrentPinballGame
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
_080162B0: .4byte gCurrentPinballGame
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
	ldr r0, _08016418 @ =gCurrentPinballGame
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
	ldr r2, _08016420 @ =gUnknown_08252B10
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
	ldr r2, _08016420 @ =gUnknown_08252B10
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
	ldr r2, _08016420 @ =gUnknown_08252B10
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
_08016418: .4byte gCurrentPinballGame
_0801641C: .4byte 0x000005B2
_08016420: .4byte gUnknown_08252B10
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
	ldr r0, _080164B4 @ =gCurrentPinballGame
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
_080164B4: .4byte gCurrentPinballGame
_080164B8: .4byte 0x0000132C
_080164BC:
	adds r1, #0x25
	movs r0, #3
_080164C0:
	strb r0, [r1]
	bl sub_32914
	ldr r0, _080164D4 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	b _080168A4
	.align 2, 0
_080164D4: .4byte gCurrentPinballGame
_080164D8:
	ldr r3, _080164F0 @ =gCurrentPinballGame
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
_080164F0: .4byte gCurrentPinballGame
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
	ldr r3, _08016558 @ =gCurrentPinballGame
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
_08016558: .4byte gCurrentPinballGame
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
	ldr r5, _080165D4 @ =gCurrentPinballGame
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
_080165D4: .4byte gCurrentPinballGame
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
	ldr r5, _08016618 @ =gCurrentPinballGame
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
_08016618: .4byte gCurrentPinballGame
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
	ldr r5, _080166BC @ =gCurrentPinballGame
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
_080166BC: .4byte gCurrentPinballGame
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
	ldr r0, _08016788 @ =gCurrentPinballGame
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
	ldr r0, _08016788 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, SE_UNKNOWN_0x76
	bl m4aSongNumStart
	bl _080171B8
	.align 2, 0
_08016788: .4byte gCurrentPinballGame
_0801678C: .4byte 0x0000132C
_08016790: .4byte 0x00000BB8
_08016794:
	ldr r1, _080167BC @ =gCurrentPinballGame
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
_080167BC: .4byte gCurrentPinballGame
_080167C0: .4byte 0x00000165
_080167C4: .4byte 0x00000732
_080167C8: .4byte 0x00000342
_080167CC:
	ldr r0, _08016850 @ =gCurrentPinballGame
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
	bl sub_0C74
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
	bl sub_0C24
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
_08016850: .4byte gCurrentPinballGame
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
	ldr r4, _080168AC @ =gCurrentPinballGame
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
_080168AC: .4byte gCurrentPinballGame
_080168B0: .4byte 0x00000366
_080168B4:
	ldr r1, _0801690C @ =gCurrentPinballGame
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
_0801690C: .4byte gCurrentPinballGame
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
	ldr r0, _08016A04 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _08016A08 @ =0x0000072E
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x99
	bl m4aSongNumStart
_080169E0:
	ldr r0, _08016A04 @ =gCurrentPinballGame
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
_08016A04: .4byte gCurrentPinballGame
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
	ldr r4, _08016C14 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0x99
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
_08016C14: .4byte gCurrentPinballGame
_08016C18: .4byte 0x0000072F
_08016C1C: .4byte 0x00000731
_08016C20: .4byte 0x000006BC
_08016C24: .4byte 0x00000732
_08016C28:
	ldr r0, _08016C4C @ =gCurrentPinballGame
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
_08016C4C: .4byte gCurrentPinballGame
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
	ldr r4, _08016CD8 @ =gCurrentPinballGame
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
_08016CD8: .4byte gCurrentPinballGame
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
	ldr r0, _08016E54 @ =gCurrentPinballGame
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
_08016E54: .4byte gCurrentPinballGame
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
	ldr r6, _08016EF8 @ =gCurrentPinballGame
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
_08016EF8: .4byte gCurrentPinballGame
_08016EFC: .4byte 0x00000616
_08016F00: .4byte 0x0000132C
_08016F04: .4byte 0x00000614
_08016F08:
	ldr r5, _08017058 @ =gCurrentPinballGame
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
	ldr r3, _08017060 @ =gUnknown_086ACE70
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
	ldr r0, _08017058 @ =gCurrentPinballGame
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
_08017058: .4byte gCurrentPinballGame
_0801705C: .4byte 0x00000732
_08017060: .4byte gUnknown_086ACE70
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
	ldr r5, _08017144 @ =gCurrentPinballGame
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
	ldr r2, _0801714C @ =gUnknown_086ACE70
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
_08017144: .4byte gCurrentPinballGame
_08017148: .4byte 0x00000732
_0801714C: .4byte gUnknown_086ACE70
_08017150: .4byte 0x0000034A
_08017154: .4byte 0x0000034B
_08017158: .4byte gMain
_0801715C: .4byte 0x00000355
_08017160: .4byte 0x0000035E
_08017164: .4byte 0x00000359
_08017168: .4byte 0x0000132C
_0801716C:
	ldr r3, _08017190 @ =gCurrentPinballGame
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
_08017190: .4byte gCurrentPinballGame
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
	ldr r0, _080172CC @ =gCurrentPinballGame
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
	ldr r7, _080172DC @ =gUnknown_02031520
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
_080172CC: .4byte gCurrentPinballGame
_080172D0: .4byte 0x0000132C
_080172D4: .4byte 0xFFFF0000
_080172D8: .4byte 0x0000FFFF
_080172DC: .4byte gUnknown_02031520
_080172E0: .4byte _080172E4
_080172E4: @ jump table
	.4byte _080172FC @ case 0
	.4byte _080173A8 @ case 1
	.4byte _080173A8 @ case 2
	.4byte _080172FC @ case 3
	.4byte _080173D8 @ case 4
	.4byte _080172FC @ case 5
_080172FC:
	ldr r2, _08017374 @ =gCurrentPinballGame
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
	ldr r4, _08017380 @ =gUnknown_02031520
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
_08017374: .4byte gCurrentPinballGame
_08017378: .4byte 0xFFFFC010
_0801737C: .4byte 0x0000132C
_08017380: .4byte gUnknown_02031520
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
	ldr r2, _080173D0 @ =gCurrentPinballGame
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
_080173D0: .4byte gCurrentPinballGame
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
	ldr r1, _08017494 @ =gCurrentPinballGame
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
	ldr r2, _080174A0 @ =gUnknown_083071D4
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
_08017494: .4byte gCurrentPinballGame
_08017498: .4byte 0x00000387
_0801749C: .4byte 0x000003F2
_080174A0: .4byte gUnknown_083071D4
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
	ldr r2, _08017614 @ =gUnknown_08252B10
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
	ldr r2, _08017614 @ =gUnknown_08252B10
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
	ldr r2, _08017614 @ =gUnknown_08252B10
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
_08017614: .4byte gUnknown_08252B10
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
	ldr r2, _080176A8 @ =gCurrentPinballGame
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
_080176A8: .4byte gCurrentPinballGame
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
	ldr r0, _080177B0 @ =gCurrentPinballGame
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
	ldr r0, _080177C0 @ =gUnknown_02031520
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
_080177B0: .4byte gCurrentPinballGame
_080177B4: .4byte 0x0000132C
_080177B8: .4byte 0xFFFF0000
_080177BC: .4byte 0x0000FFFF
_080177C0: .4byte gUnknown_02031520
_080177C4: .4byte _080177C8
_080177C8: @ jump table
	.4byte _080177E0 @ case 0
	.4byte _08017804 @ case 1
	.4byte _08017804 @ case 2
	.4byte _080177E0 @ case 3
	.4byte _08017874 @ case 4
	.4byte _080177E0 @ case 5
_080177E0:
	ldr r2, _08017800 @ =gCurrentPinballGame
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
_08017800: .4byte gCurrentPinballGame
_08017804:
	ldr r2, _0801785C @ =gCurrentPinballGame
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
_0801785C: .4byte gCurrentPinballGame
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
	ldr r0, _08017924 @ =gCurrentPinballGame
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
	ldr r2, _08017930 @ =gUnknown_0832D604
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
_08017924: .4byte gCurrentPinballGame
_08017928: .4byte 0x00000387
_0801792C: .4byte 0x000003F2
_08017930: .4byte gUnknown_0832D604
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
	ldr r2, _080179C4 @ =gUnknown_08330204
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
_080179C4: .4byte gUnknown_08330204
_080179C8: .4byte 0x0000FFF0
_080179CC: .4byte 0x0000132C

	thumb_func_start sub_179D0
sub_179D0: @ 0x080179D0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080179F8 @ =gCurrentPinballGame
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
_080179F8: .4byte gCurrentPinballGame
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
	ldr r0, _08017CF8 @ =gCurrentPinballGame
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
	ldr r4, _08017D04 @ =gUnknown_02031520
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
_08017CF8: .4byte gCurrentPinballGame
_08017CFC: .4byte 0xFFFF0000
_08017D00: .4byte 0x0000FFFF
_08017D04: .4byte gUnknown_02031520
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
	ldr r0, _08018018 @ =gCurrentPinballGame
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
	ldr r7, _0801802C @ =gUnknown_02031520
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
_08018018: .4byte gCurrentPinballGame
_0801801C: .4byte 0x0000132C
_08018020: .4byte 0x000001FF
_08018024: .4byte 0xFFFF0000
_08018028: .4byte 0x0000FFFF
_0801802C: .4byte gUnknown_02031520
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
	ldr r2, _080180F8 @ =gCurrentPinballGame
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
	ldr r4, _08018104 @ =gUnknown_02031520
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
_080180F8: .4byte gCurrentPinballGame
_080180FC: .4byte 0xFFFFC010
_08018100: .4byte 0x0000132C
_08018104: .4byte gUnknown_02031520
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
	ldr r2, _08018154 @ =gCurrentPinballGame
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
_08018154: .4byte gCurrentPinballGame
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
	ldr r0, _080181DC @ =gCurrentPinballGame
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
	ldr r2, _080181E8 @ =gUnknown_08340B58
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	b _08018278
	.align 2, 0
_080181DC: .4byte gCurrentPinballGame
_080181E0: .4byte 0x00000387
_080181E4: .4byte 0x000003F2
_080181E8: .4byte gUnknown_08340B58
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
	ldr r2, _08018230 @ =gUnknown_083499D8
	b _08018270
	.align 2, 0
_0801822C: .4byte 0x000003F2
_08018230: .4byte gUnknown_083499D8
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
	ldr r2, _080182A8 @ =gUnknown_0834DBD8
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
_080182A8: .4byte gUnknown_0834DBD8
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
	ldr r2, _08018320 @ =gCurrentPinballGame
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
_08018320: .4byte gCurrentPinballGame

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
	ldr r0, _08018414 @ =gCurrentPinballGame
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
	ldr r7, _08018428 @ =gUnknown_02031520
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
_08018414: .4byte gCurrentPinballGame
_08018418: .4byte 0x0000132C
_0801841C: .4byte 0x000001FF
_08018420: .4byte 0xFFFF0000
_08018424: .4byte 0x0000FFFF
_08018428: .4byte gUnknown_02031520
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
	ldr r2, _080184F4 @ =gCurrentPinballGame
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
	ldr r4, _08018500 @ =gUnknown_02031520
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
_080184F4: .4byte gCurrentPinballGame
_080184F8: .4byte 0xFFFFC010
_080184FC: .4byte 0x0000132C
_08018500: .4byte gUnknown_02031520
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
	ldr r2, _08018550 @ =gCurrentPinballGame
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
_08018550: .4byte gCurrentPinballGame
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
	ldr r0, _08018758 @ =gCurrentPinballGame
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
	ldr r2, _08018760 @ =gUnknown_083579C8
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
	ldr r3, _08018758 @ =gCurrentPinballGame
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
	ldr r1, _08018770 @ =gUnknown_0835E9C8
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
	ldr r0, _08018758 @ =gCurrentPinballGame
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
	ldr r1, _08018770 @ =gUnknown_0835E9C8
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
_08018758: .4byte gCurrentPinballGame
_0801875C: .4byte 0x00000387
_08018760: .4byte gUnknown_083579C8
_08018764: .4byte 0x0000FFF0
_08018768: .4byte 0x00000452
_0801876C: .4byte 0x000004FA
_08018770: .4byte gUnknown_0835E9C8
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
	ldr r2, _080187F0 @ =gCurrentPinballGame
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
_080187F0: .4byte gCurrentPinballGame

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
	ldr r0, _080188E4 @ =gCurrentPinballGame
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
	ldr r7, _080188F8 @ =gUnknown_02031520
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
_080188E4: .4byte gCurrentPinballGame
_080188E8: .4byte 0x0000132C
_080188EC: .4byte 0x000001FF
_080188F0: .4byte 0xFFFF0000
_080188F4: .4byte 0x0000FFFF
_080188F8: .4byte gUnknown_02031520
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
	ldr r2, _080189C4 @ =gCurrentPinballGame
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
	ldr r4, _080189D0 @ =gUnknown_02031520
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
_080189C4: .4byte gCurrentPinballGame
_080189C8: .4byte 0xFFFFC010
_080189CC: .4byte 0x0000132C
_080189D0: .4byte gUnknown_02031520
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
	ldr r2, _08018A20 @ =gCurrentPinballGame
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
_08018A20: .4byte gCurrentPinballGame
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
	ldr r0, _08018AC8 @ =gCurrentPinballGame
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
	ldr r2, _08018AD4 @ =gUnknown_083722E8
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
_08018AC8: .4byte gCurrentPinballGame
_08018ACC: .4byte 0x00000387
_08018AD0: .4byte 0x000003F2
_08018AD4: .4byte gUnknown_083722E8
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
	ldr r2, _08018B4C @ =gCurrentPinballGame
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
_08018B4C: .4byte gCurrentPinballGame

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
	ldr r0, _08018C54 @ =gCurrentPinballGame
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
	ldr r7, _08018C64 @ =gUnknown_02031520
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
_08018C54: .4byte gCurrentPinballGame
_08018C58: .4byte 0x0000132C
_08018C5C: .4byte 0xFFFF0000
_08018C60: .4byte 0x0000FFFF
_08018C64: .4byte gUnknown_02031520
_08018C68: .4byte _08018C6C
_08018C6C: @ jump table
	.4byte _08018C84 @ case 0
	.4byte _08018D30 @ case 1
	.4byte _08018D30 @ case 2
	.4byte _08018C84 @ case 3
	.4byte _08018D88 @ case 4
	.4byte _08018C84 @ case 5
_08018C84:
	ldr r3, _08018CFC @ =gCurrentPinballGame
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
	ldr r4, _08018D08 @ =gUnknown_02031520
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
_08018CFC: .4byte gCurrentPinballGame
_08018D00: .4byte 0xFFFFC010
_08018D04: .4byte 0x0000132C
_08018D08: .4byte gUnknown_02031520
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
	ldr r2, _08018D68 @ =gCurrentPinballGame
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
_08018D68: .4byte gCurrentPinballGame
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
	ldr r0, _08018E5C @ =gCurrentPinballGame
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
	ldr r2, _08018E68 @ =gUnknown_08393A4C
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
	ldr r1, _08018E5C @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08018E70 @ =0x00000553
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #4
	b _08018F14
	.align 2, 0
_08018E5C: .4byte gCurrentPinballGame
_08018E60: .4byte 0x0000054F
_08018E64: .4byte 0x00000572
_08018E68: .4byte gUnknown_08393A4C
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
	ldr r2, _08018EF8 @ =gUnknown_08391A4C
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
	ldr r3, _08018F00 @ =gCurrentPinballGame
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
_08018EF8: .4byte gUnknown_08391A4C
_08018EFC: .4byte 0x0000FFF0
_08018F00: .4byte gCurrentPinballGame
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
	ldr r2, _08018FA4 @ =gCurrentPinballGame
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
_08018FA4: .4byte gCurrentPinballGame
_08018FA8: .4byte 0x00000532
_08018FAC:
	ldr r2, _08018FC8 @ =gCurrentPinballGame
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
_08018FC8: .4byte gCurrentPinballGame
_08018FCC: .4byte 0x00000532
_08018FD0:
	ldr r2, _08018FF4 @ =gCurrentPinballGame
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
_08018FF4: .4byte gCurrentPinballGame
_08018FF8: .4byte 0x00000532
_08018FFC:
	ldr r1, _08019020 @ =gCurrentPinballGame
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
_08019020: .4byte gCurrentPinballGame
_08019024: .4byte 0x00000532

	thumb_func_start IdlePinballGameMain
IdlePinballGameMain: @ 0x08019028
	push {lr}
	ldr r1, _08019040 @ =gIdlePinballGameStateFuncs
	ldr r0, _08019044 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08019040: .4byte gIdlePinballGameStateFuncs
_08019044: .4byte gMain

	thumb_func_start sub_19048
sub_19048: @ 0x08019048
	push {r4, r5, lr}
	ldr r1, _080190A4 @ =gMain
	movs r2, #0
	str r2, [r1, #0x54]
	movs r0, #1
	strb r0, [r1, #0xd]
	ldr r0, _080190A8 @ =gUnknown_02031510
	str r2, [r0]
	adds r5, r1, #0
	ldr r4, _080190AC @ =gUnknown_02031520
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
	bl Random
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
_080190A8: .4byte gUnknown_02031510
_080190AC: .4byte gUnknown_02031520
_080190B0:
	cmp r0, #2
	beq _080190F4
	cmp r0, #3
	beq _08019110
	b _0801911E
_080190BA:
	ldr r1, _080190C8 @ =gUnknown_02031520
	ldr r0, _080190CC @ =0x00000A14
	strh r0, [r1, #6]
	ldr r0, _080190D0 @ =gUnknown_081450F4
	str r0, [r1, #0x10]
	ldr r0, _080190D4 @ =gUnknown_081531F4
	b _0801911C
	.align 2, 0
_080190C8: .4byte gUnknown_02031520
_080190CC: .4byte 0x00000A14
_080190D0: .4byte gUnknown_081450F4
_080190D4: .4byte gUnknown_081531F4
_080190D8:
	ldr r1, _080190E8 @ =gUnknown_02031520
	movs r0, #0xf0
	lsls r0, r0, #4
	strh r0, [r1, #6]
	ldr r0, _080190EC @ =gUnknown_0814F9B4
	str r0, [r1, #0x10]
	ldr r0, _080190F0 @ =gUnknown_08156E60
	b _0801911C
	.align 2, 0
_080190E8: .4byte gUnknown_02031520
_080190EC: .4byte gUnknown_0814F9B4
_080190F0: .4byte gUnknown_08156E60
_080190F4:
	ldr r1, _08019104 @ =gUnknown_02031520
	movs r0, #0xd2
	lsls r0, r0, #4
	strh r0, [r1, #6]
	ldr r0, _08019108 @ =gUnknown_08148934
	str r0, [r1, #0x10]
	ldr r0, _0801910C @ =gUnknown_08154618
	b _0801911C
	.align 2, 0
_08019104: .4byte gUnknown_02031520
_08019108: .4byte gUnknown_08148934
_0801910C: .4byte gUnknown_08154618
_08019110:
	ldr r1, _08019134 @ =gUnknown_02031520
	ldr r0, _08019138 @ =0x00000E4C
	strh r0, [r1, #6]
	ldr r0, _0801913C @ =gUnknown_0814C174
	str r0, [r1, #0x10]
	ldr r0, _08019140 @ =gUnknown_08155A3C
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
_08019134: .4byte gUnknown_02031520
_08019138: .4byte 0x00000E4C
_0801913C: .4byte gUnknown_0814C174
_08019140: .4byte gUnknown_08155A3C
_08019144:
	cmp r1, #2
	beq _08019156
	cmp r1, #3
	beq _0801915E
	b _08019164
_0801914E:
	movs r0, MUS_FIELD_SAPPHIRE
	bl m4aSongNumStart
	b _08019164
_08019156:
	movs r0, MUS_FIELD_RUBY
	bl m4aSongNumStart
	b _08019164
_0801915E:
	movs r0, MUS_FIELD_SAPPHIRE
	bl m4aSongNumStart
_08019164:
	ldr r3, _08019188 @ =gUnknown_02031520
	ldr r1, _0801918C @ =gMain+0x74
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
_08019188: .4byte gUnknown_02031520
_0801918C: .4byte gMain+0x74

	thumb_func_start sub_19190
sub_19190: @ 0x08019190
	push {r4, r5, lr}
	ldr r0, _080191A8 @ =gCurrentPinballGame
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
_080191A8: .4byte gCurrentPinballGame
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
	ldr r1, _08019218 @ =gUnknown_02031520
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
_08019218: .4byte gUnknown_02031520
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
	ldr r2, _08019260 @ =gCurrentPinballGame
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
_08019260: .4byte gCurrentPinballGame
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
	ldr r2, _080192E4 @ =gUnknown_02031520
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
	bl sub_02B4
	bl m4aMPlayAllStop
	bl sub_0D10
	ldr r2, _080192E0 @ =gMain
	ldr r0, _080192E4 @ =gUnknown_02031520
	movs r3, #6
	ldrsh r1, [r0, r3]
	ldr r0, [r2, #0x54]
	cmp r0, r1
	bhs _080192EC
	movs r0, STATE_TITLE
	bl SetMainGameState
	b _080192F2
	.align 2, 0
_080192E0: .4byte gMain
_080192E4: .4byte gUnknown_02031520
_080192E8: .4byte 0x00000141
_080192EC:
	movs r0, STATE_SCORES_IDLE
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
	ldr r0, _080193BC @ =gCurrentPinballGame
	mov r8, r0
	ldr r1, [r0]
	mov sb, r1
	ldr r0, _080193C0 @ =0x000013BC
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r2, _080193C4 @ =gUnknown_086ACE8C
	adds r7, r0, r2
	ldrh r0, [r7]
	adds r0, #0x53
	lsls r0, r0, #0x10
	ldr r3, _080193C8 @ =0xFFFF0000
	ldr r2, _080193CC @ =gUnknown_02031520
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
	ldr r3, _080193C4 @ =gUnknown_086ACE8C
	ldr r4, _080193CC @ =gUnknown_02031520
	cmp r0, #0
	blt _080193D8
	ldr r1, _080193D4 @ =0x000013C4
	add r1, sb
	movs r0, #1
	b _080193DE
	.align 2, 0
_080193BC: .4byte gCurrentPinballGame
_080193C0: .4byte 0x000013BC
_080193C4: .4byte gUnknown_086ACE8C
_080193C8: .4byte 0xFFFF0000
_080193CC: .4byte gUnknown_02031520
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
	ldr r0, _080194E0 @ =gCurrentPinballGame
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
_080194E0: .4byte gCurrentPinballGame
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
	ldr r0, _080195A8 @ =gUnknown_086ACEF4
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldr r0, _080195AC @ =gUnknown_02031520
	adds r4, #0x5a
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	asrs r2, r2, #1
	lsls r2, r2, #9
	ldr r0, _080195B0 @ =gUnknown_083FE44C
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
_080195A8: .4byte gUnknown_086ACEF4
_080195AC: .4byte gUnknown_02031520
_080195B0: .4byte gUnknown_083FE44C
_080195B4: .4byte 0x06010000
_080195B8: .4byte 0x80000100
_080195BC: .4byte 0x000001FF
_080195C0: .4byte 0xFFFFFE00

	thumb_func_start sub_195C4
sub_195C4: @ 0x080195C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08019630 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0x72
	bl m4aSongNumStart
_08019624:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #6]
	strb r1, [r4, #7]
	b _08019650
	.align 2, 0
_08019630: .4byte gCurrentPinballGame
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
	ldr r1, _08019784 @ =gCurrentPinballGame
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
_08019784: .4byte gCurrentPinballGame
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
	ldr r1, _08019870 @ =gUnknown_0200B5E0
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
	ldr r0, _08019878 @ =gUnknown_086ACEF4
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldr r0, _0801987C @ =gUnknown_02031520
	adds r4, #0x5a
	ldrh r0, [r0, #0x1c]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	asrs r2, r2, #1
	lsls r2, r2, #9
	ldr r0, _08019880 @ =gUnknown_083FE44C
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
_08019870: .4byte gUnknown_0200B5E0
_08019874: .4byte 0x000013BC
_08019878: .4byte gUnknown_086ACEF4
_0801987C: .4byte gUnknown_02031520
_08019880: .4byte gUnknown_083FE44C
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
	ldr r4, _08019914 @ =gCurrentPinballGame
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
	movs r0, SE_UNKNOWN_0x72
	bl m4aSongNumStart
_08019908:
	movs r0, #1
	strb r0, [r4, #6]
	mov r1, r8
	strb r1, [r4, #7]
	b _0801993A
	.align 2, 0
_08019914: .4byte gCurrentPinballGame
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
	ldr r4, _08019AF0 @ =gCurrentPinballGame
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
_08019AF0: .4byte gCurrentPinballGame
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
	ldr r0, _08019B58 @ =gCurrentPinballGame
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
	ldr r0, _08019B5C @ =gMPlayInfo_BGM
	ldr r1, _08019B60 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_08019B50:
	pop {r0}
	bx r0
	.align 2, 0
_08019B54: .4byte gMain
_08019B58: .4byte gCurrentPinballGame
_08019B5C: .4byte gMPlayInfo_BGM
_08019B60: .4byte 0x0000FFFF
