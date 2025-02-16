#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_4ABEC
sub_4ABEC: @ 0x0804ABEC
	push {r4, r5, lr}
	bl sub_4B280
	ldr r5, _0804AC50 @ =gUnknown_020028D8
	ldr r0, [r5, #0xc]
	bl _call_via_r0
	ldr r4, _0804AC54 @ =gMain
	ldrh r1, [r4, #0xe]
	ldr r0, _0804AC58 @ =0x000002FF
	ands r0, r1
	cmp r0, #0
	bne _0804ACDE
	ldr r0, [r5, #0x14]
	bl _call_via_r0
	ldr r0, [r5, #4]
	bl _call_via_r0
	ldr r0, [r5, #0x1c]
	bl _call_via_r0
	ldr r0, [r5, #0x24]
	bl _call_via_r0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804AC60
	ldr r0, _0804AC5C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	bne _0804ACD0
	movs r4, #0
_0804AC30:
	ldr r0, _0804AC5C @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, _0804AC50 @ =gUnknown_020028D8
	ldr r0, [r0, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AC30
	b _0804ACD0
	.align 2, 0
_0804AC50: .4byte gUnknown_020028D8
_0804AC54: .4byte gMain
_0804AC58: .4byte 0x000002FF
_0804AC5C: .4byte gCurrentPinballGame
_0804AC60:
	ldr r0, [r4, #0x50]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r0, _0804ACA4 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldrb r0, [r2, #0x1f]
	cmp r0, #0
	beq _0804ACAC
	cmp r0, #2
	beq _0804ACD0
	movs r4, #0
_0804AC82:
	ldr r0, _0804ACA4 @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, _0804ACA8 @ =gUnknown_020028D8
	ldr r0, [r0, #0x2c]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AC82
	b _0804ACD0
	.align 2, 0
_0804ACA4: .4byte gCurrentPinballGame
_0804ACA8: .4byte gUnknown_020028D8
_0804ACAC:
	movs r4, #0
_0804ACAE:
	ldr r0, _0804ACE8 @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, [r5, #0x2c]
	bl _call_via_r0
	ldr r0, [r5, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804ACAE
_0804ACD0:
	ldr r4, _0804ACEC @ =gUnknown_020028D8
	ldr r0, [r4, #0x3c]
	bl _call_via_r0
	ldr r0, [r4, #0x44]
	bl _call_via_r0
_0804ACDE:
	bl sub_47030
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804ACE8: .4byte gCurrentPinballGame
_0804ACEC: .4byte gUnknown_020028D8

	thumb_func_start sub_4ACF0
sub_4ACF0: @ 0x0804ACF0
	push {r4, r5, r6, r7, lr}
	bl sub_4B334
	ldr r5, _0804AD54 @ =gUnknown_020028D8
	ldr r0, [r5, #0xc]
	bl _call_via_r0
	ldr r4, _0804AD58 @ =gMain
	ldrb r1, [r4, #0xf]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804ADDE
	ldr r0, [r5, #0x14]
	bl _call_via_r0
	ldr r0, [r5, #4]
	bl _call_via_r0
	ldr r0, [r5, #0x1c]
	bl _call_via_r0
	ldr r0, [r5, #0x24]
	bl _call_via_r0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804AD60
	ldr r0, _0804AD5C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	bne _0804ADD0
	movs r4, #0
_0804AD34:
	ldr r0, _0804AD5C @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, _0804AD54 @ =gUnknown_020028D8
	ldr r0, [r0, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AD34
	b _0804ADD0
	.align 2, 0
_0804AD54: .4byte gUnknown_020028D8
_0804AD58: .4byte gMain
_0804AD5C: .4byte gCurrentPinballGame
_0804AD60:
	ldr r0, [r4, #0x50]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r0, _0804ADA4 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldrb r0, [r2, #0x1f]
	cmp r0, #0
	beq _0804ADAC
	cmp r0, #2
	beq _0804ADD0
	movs r4, #0
_0804AD82:
	ldr r0, _0804ADA4 @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, _0804ADA8 @ =gUnknown_020028D8
	ldr r0, [r0, #0x2c]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AD82
	b _0804ADD0
	.align 2, 0
_0804ADA4: .4byte gCurrentPinballGame
_0804ADA8: .4byte gUnknown_020028D8
_0804ADAC:
	movs r4, #0
_0804ADAE:
	ldr r0, _0804AE1C @ =gCurrentPinballGame
	ldr r0, [r0]
	strb r4, [r0, #0x1e]
	ldr r0, [r5, #0x2c]
	bl _call_via_r0
	ldr r0, [r5, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804ADAE
_0804ADD0:
	ldr r4, _0804AE20 @ =gUnknown_020028D8
	ldr r0, [r4, #0x3c]
	bl _call_via_r0
	ldr r0, [r4, #0x44]
	bl _call_via_r0
_0804ADDE:
	bl sub_47030
	ldr r0, _0804AE24 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #4
	cmp r0, #0
	beq _0804AE38
	movs r4, #0
	ldr r7, _0804AE28 @ =gUnknown_03006280
	ldr r0, _0804AE2C @ =0xFFFFF980
	adds r6, r7, r0
	ldr r5, _0804AE30 @ =0x0000034A
	ldr r1, _0804AE34 @ =0xFFFFC156
	adds r3, r1, #0
_0804ADFE:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r5
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r2, r0, r3
	strh r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0804ADFE
	b _0804AE5C
	.align 2, 0
_0804AE1C: .4byte gCurrentPinballGame
_0804AE20: .4byte gUnknown_020028D8
_0804AE24: .4byte gMain
_0804AE28: .4byte gUnknown_03006280
_0804AE2C: .4byte 0xFFFFF980
_0804AE30: .4byte 0x0000034A
_0804AE34: .4byte 0xFFFFC156
_0804AE38:
	movs r4, #0
	ldr r7, _0804AE70 @ =gUnknown_03006280
	ldr r0, _0804AE74 @ =0xFFFFF980
	adds r5, r7, r0
	ldr r3, _0804AE78 @ =0x0000034A
	ldr r2, _0804AE7C @ =0x000001FF
_0804AE44:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _0804AE44
_0804AE5C:
	ldr r1, _0804AE80 @ =0x040000D4
	str r7, [r1]
	ldr r0, _0804AE84 @ =0x06002680
	str r0, [r1, #4]
	ldr r0, _0804AE88 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AE70: .4byte gUnknown_03006280
_0804AE74: .4byte 0xFFFFF980
_0804AE78: .4byte 0x0000034A
_0804AE7C: .4byte 0x000001FF
_0804AE80: .4byte 0x040000D4
_0804AE84: .4byte 0x06002680
_0804AE88: .4byte 0x80000020

	thumb_func_start sub_4AE8C
sub_4AE8C: @ 0x0804AE8C
	push {r4, r5, r6, lr}
	bl sub_4B280
	ldr r6, _0804AF0C @ =gUnknown_020028D8
	ldr r0, [r6, #0xc]
	bl _call_via_r0
	ldr r5, _0804AF10 @ =gMain
	ldrb r1, [r5, #0xf]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804AEA8
	b _0804AFEA
_0804AEA8:
	ldr r0, [r6, #4]
	bl _call_via_r0
	ldr r0, [r6, #0x14]
	bl _call_via_r0
	ldr r0, [r6, #0x1c]
	bl _call_via_r0
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldrb r4, [r5, #0xf]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r4, r0
	cmp r4, #0
	beq _0804AF20
	ldr r0, _0804AF14 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	beq _0804AED8
	b _0804AFDC
_0804AED8:
	movs r4, #0
_0804AEDA:
	ldr r0, _0804AF14 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804AF18 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804AF1C @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, _0804AF0C @ =gUnknown_020028D8
	ldr r0, [r0, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AEDA
	b _0804AFDC
	.align 2, 0
_0804AF0C: .4byte gUnknown_020028D8
_0804AF10: .4byte gMain
_0804AF14: .4byte gCurrentPinballGame
_0804AF18: .4byte 0x0000132C
_0804AF1C: .4byte 0x00001334
_0804AF20:
	ldr r0, [r5, #0x50]
	adds r0, #1
	str r0, [r5, #0x50]
	ldr r0, _0804AF58 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	beq _0804AFA4
	cmp r0, #2
	bne _0804AF60
	adds r0, r3, #0
	adds r0, #0x66
	movs r2, #0
	strh r4, [r0]
	ldr r4, _0804AF5C @ =0x0000132C
	adds r1, r3, r4
	adds r4, #8
	adds r0, r3, r4
	str r0, [r1]
	strb r2, [r3, #0x1e]
	b _0804AFDC
	.align 2, 0
_0804AF58: .4byte gCurrentPinballGame
_0804AF5C: .4byte 0x0000132C
_0804AF60:
	movs r4, #0
_0804AF62:
	ldr r0, _0804AF94 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804AF98 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804AF9C @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, _0804AFA0 @ =gUnknown_020028D8
	ldr r0, [r0, #0x2c]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AF62
	b _0804AFDC
	.align 2, 0
_0804AF94: .4byte gCurrentPinballGame
_0804AF98: .4byte 0x0000132C
_0804AF9C: .4byte 0x00001334
_0804AFA0: .4byte gUnknown_020028D8
_0804AFA4:
	movs r4, #0
	adds r5, r6, #0
_0804AFA8:
	ldr r0, _0804AFF0 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804AFF4 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804AFF8 @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, [r5, #0x2c]
	bl _call_via_r0
	ldr r0, [r5, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804AFA8
_0804AFDC:
	ldr r4, _0804AFFC @ =gUnknown_020028D8
	ldr r0, [r4, #0x3c]
	bl _call_via_r0
	ldr r0, [r4, #0x44]
	bl _call_via_r0
_0804AFEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AFF0: .4byte gCurrentPinballGame
_0804AFF4: .4byte 0x0000132C
_0804AFF8: .4byte 0x00001334
_0804AFFC: .4byte gUnknown_020028D8

	thumb_func_start sub_4B000
sub_4B000: @ 0x0804B000
	push {r4, r5, r6, r7, lr}
	bl sub_4B334
	ldr r5, _0804B07C @ =gMain
	ldrb r1, [r5, #0xf]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804B014
	b _0804B15A
_0804B014:
	ldr r6, _0804B080 @ =gUnknown_020028D8
	ldr r0, [r6, #4]
	bl _call_via_r0
	ldr r0, [r6, #0x14]
	bl _call_via_r0
	ldr r0, [r6, #0x1c]
	bl _call_via_r0
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldrb r4, [r5, #0xf]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r4, r0
	cmp r4, #0
	beq _0804B090
	ldr r0, _0804B084 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	beq _0804B046
	b _0804B14C
_0804B046:
	movs r4, #0
_0804B048:
	ldr r0, _0804B084 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804B088 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804B08C @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, _0804B080 @ =gUnknown_020028D8
	ldr r0, [r0, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804B048
	b _0804B14C
	.align 2, 0
_0804B07C: .4byte gMain
_0804B080: .4byte gUnknown_020028D8
_0804B084: .4byte gCurrentPinballGame
_0804B088: .4byte 0x0000132C
_0804B08C: .4byte 0x00001334
_0804B090:
	ldr r0, [r5, #0x50]
	adds r0, #1
	str r0, [r5, #0x50]
	ldr r0, _0804B0C8 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	beq _0804B114
	cmp r0, #2
	bne _0804B0D0
	adds r0, r3, #0
	adds r0, #0x66
	movs r2, #0
	strh r4, [r0]
	ldr r4, _0804B0CC @ =0x0000132C
	adds r1, r3, r4
	adds r4, #8
	adds r0, r3, r4
	str r0, [r1]
	strb r2, [r3, #0x1e]
	b _0804B14C
	.align 2, 0
_0804B0C8: .4byte gCurrentPinballGame
_0804B0CC: .4byte 0x0000132C
_0804B0D0:
	movs r4, #0
_0804B0D2:
	ldr r0, _0804B104 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804B108 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804B10C @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, _0804B110 @ =gUnknown_020028D8
	ldr r0, [r0, #0x2c]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804B0D2
	b _0804B14C
	.align 2, 0
_0804B104: .4byte gCurrentPinballGame
_0804B108: .4byte 0x0000132C
_0804B10C: .4byte 0x00001334
_0804B110: .4byte gUnknown_020028D8
_0804B114:
	movs r4, #0
	adds r5, r6, #0
_0804B118:
	ldr r0, _0804B194 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0804B198 @ =0x0000132C
	adds r2, r1, r0
	ldr r3, _0804B19C @ =0x00001334
	adds r0, r1, r3
	str r0, [r2]
	strb r4, [r1, #0x1e]
	ldr r0, [r5, #0x2c]
	bl _call_via_r0
	ldr r0, [r5, #0x34]
	bl _call_via_r0
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804B118
_0804B14C:
	ldr r4, _0804B1A0 @ =gUnknown_020028D8
	ldr r0, [r4, #0x3c]
	bl _call_via_r0
	ldr r0, [r4, #0x44]
	bl _call_via_r0
_0804B15A:
	ldr r0, _0804B1A4 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #4
	cmp r0, #0
	beq _0804B1B8
	movs r4, #0
	ldr r7, _0804B1A8 @ =gUnknown_03006240
	ldr r0, _0804B1AC @ =0xFFFFF9C0
	adds r6, r7, r0
	ldr r5, _0804B1B0 @ =0x0000032B
	ldr r1, _0804B1B4 @ =0xFFFFC156
	adds r3, r1, #0
_0804B176:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r5
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r2, r0, r3
	strh r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0804B176
	b _0804B1DC
	.align 2, 0
_0804B194: .4byte gCurrentPinballGame
_0804B198: .4byte 0x0000132C
_0804B19C: .4byte 0x00001334
_0804B1A0: .4byte gUnknown_020028D8
_0804B1A4: .4byte gMain
_0804B1A8: .4byte gUnknown_03006240
_0804B1AC: .4byte 0xFFFFF9C0
_0804B1B0: .4byte 0x0000032B
_0804B1B4: .4byte 0xFFFFC156
_0804B1B8:
	movs r4, #0
	ldr r7, _0804B1F0 @ =gUnknown_03006240
	ldr r3, _0804B1F4 @ =0xFFFFF9C0
	adds r5, r7, r3
	ldr r3, _0804B1F8 @ =0x0000032B
	ldr r2, _0804B1FC @ =0x000001FF
_0804B1C4:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #8
	ble _0804B1C4
_0804B1DC:
	ldr r1, _0804B200 @ =0x040000D4
	str r7, [r1]
	ldr r0, _0804B204 @ =0x06002640
	str r0, [r1, #4]
	ldr r0, _0804B208 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B1F0: .4byte gUnknown_03006240
_0804B1F4: .4byte 0xFFFFF9C0
_0804B1F8: .4byte 0x0000032B
_0804B1FC: .4byte 0x000001FF
_0804B200: .4byte 0x040000D4
_0804B204: .4byte 0x06002640
_0804B208: .4byte 0x80000020

	thumb_func_start sub_4B20C
sub_4B20C: @ 0x0804B20C
	push {r4, lr}
	ldr r4, _0804B250 @ =gMain
	adds r1, r4, #0
	adds r1, #0x36
	movs r0, #0
	strb r0, [r1]
	bl sub_02B4
	bl m4aMPlayAllStop
	bl sub_0D10
	ldr r0, _0804B254 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x48]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _0804B23A
	bl sub_4B654
_0804B23A:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0804B262
	ldrb r0, [r4, #4]
	cmp r0, #1
	bls _0804B258
	movs r0, STATE_BONUS_FIELD_SELECT
	bl SetMainGameState
	b _0804B276
	.align 2, 0
_0804B250: .4byte gMain
_0804B254: .4byte gCurrentPinballGame
_0804B258:
	ldr r0, [r4, #8]
	ldr r1, _0804B26C @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	beq _0804B270
_0804B262:
	movs r0, STATE_INTRO
	bl SetMainGameState
	b _0804B276
	.align 2, 0
_0804B26C: .4byte 0x00FFFF00
_0804B270:
	movs r0, STATE_SCORES_MAIN
	bl SetMainGameState
_0804B276:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nullsub_19
nullsub_19: @ 0x0804B27C
	bx lr

	thumb_func_start sub_4B280
sub_4B280: @ 0x0804B280
	push {r4, r5, lr}
	movs r3, #0
	ldr r4, _0804B2F8 @ =gCurrentPinballGame
	ldr r0, _0804B2FC @ =gMain
	mov ip, r0
	adds r2, r4, #0
	movs r1, #0
_0804B28E:
	ldr r0, [r2]
	adds r0, #4
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #9
	adds r0, r0, r3
	strb r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls _0804B28E
	mov r1, ip
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	bne _0804B32E
	movs r3, #0
	movs r5, #1
_0804B2B4:
	lsls r2, r3, #2
	mov r1, ip
	adds r1, #0x60
	adds r1, r2, r1
	mov r0, ip
	adds r0, #0x62
	adds r2, r2, r0
	ldrh r1, [r1]
	ldrh r0, [r2]
	orrs r1, r0
	ldr r2, _0804B300 @ =0x000003FF
	adds r0, r2, #0
	ands r1, r0
	mov r2, ip
	ldrh r0, [r2, #0x1c]
	ands r0, r1
	cmp r1, r0
	bne _0804B304
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xe
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804B2EC
	adds r0, r1, #4
	adds r0, r0, r3
	strb r5, [r0]
_0804B2EC:
	ldr r0, [r4]
	adds r0, #0xe
	adds r0, r0, r3
	strb r5, [r0]
	b _0804B324
	.align 2, 0
_0804B2F8: .4byte gCurrentPinballGame
_0804B2FC: .4byte gMain
_0804B300: .4byte 0x000003FF
_0804B304:
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xe
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804B31A
	adds r0, r1, #0
	adds r0, #9
	adds r0, r0, r3
	strb r5, [r0]
_0804B31A:
	ldr r0, [r4]
	adds r0, #0xe
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
_0804B324:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls _0804B2B4
_0804B32E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_4B334
sub_4B334: @ 0x0804B334
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r3, #0
	ldr r0, _0804B3F4 @ =gCurrentPinballGame
	mov r8, r0
	ldr r1, _0804B3F8 @ =gMain
	mov sb, r1
	mov r2, r8
	movs r1, #0
_0804B34A:
	ldr r0, [r2]
	adds r0, #4
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #9
	adds r0, r0, r3
	strb r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls _0804B34A
	mov r1, sb
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	bne _0804B3E6
	ldr r0, _0804B3FC @ =gUnknown_02031510
	ldr r2, [r0]
	ldr r1, _0804B400 @ =0x00000E0F
	mov ip, r0
	cmp r2, r1
	bhi _0804B3D6
	movs r3, #0
	ldr r7, _0804B3F4 @ =gCurrentPinballGame
	ldr r6, _0804B404 @ =gUnknown_02031520
	mov r5, ip
	movs r4, #1
_0804B382:
	ldr r2, [r7]
	adds r2, #4
	adds r2, r2, r3
	ldr r0, [r5]
	ldr r1, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	asrs r0, r3
	ands r0, r4
	strb r0, [r2]
	ldr r2, [r7]
	adds r2, #9
	adds r2, r2, r3
	ldr r0, [r5]
	ldr r1, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	asrs r0, r3
	ands r0, r4
	strb r0, [r2]
	ldr r2, [r7]
	adds r2, #0xe
	adds r2, r2, r3
	ldr r0, [r5]
	ldr r1, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	asrs r0, r3
	ands r0, r4
	strb r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bls _0804B382
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804B3D6:
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _0804B3E6
	movs r0, #1
	mov r1, sb
	strh r0, [r1, #0x18]
_0804B3E6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B3F4: .4byte gCurrentPinballGame
_0804B3F8: .4byte gMain
_0804B3FC: .4byte gUnknown_02031510
_0804B400: .4byte 0x00000E0F
_0804B404: .4byte gUnknown_02031520

	thumb_func_start sub_4B408
sub_4B408: @ 0x0804B408
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r2, _0804B430 @ =gMPlayInfo_BGM
	ldr r0, [r2, #4]
	cmp r0, #0
	blt _0804B43C
	ldr r0, _0804B434 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0804B438 @ =0x00000F4C
	adds r0, r0, r1
	ldr r1, [r2]
	str r1, [r0]
	adds r0, r2, #0
	bl m4aMPlayStop
	b _0804B448
	.align 2, 0
_0804B430: .4byte gMPlayInfo_BGM
_0804B434: .4byte gCurrentPinballGame
_0804B438: .4byte 0x00000F4C
_0804B43C:
	ldr r0, _0804B5EC @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0804B5F0 @ =0x00000F4C
	adds r0, r0, r2
	movs r1, #0
	str r1, [r0]
_0804B448:
	movs r3, #0
	ldr r6, _0804B5EC @ =gCurrentPinballGame
	ldr r0, _0804B5F4 @ =gMain
	mov ip, r0
	lsls r4, r4, #0x10
	mov r8, r4
	mov r5, ip
	adds r7, r6, #0
_0804B458:
	ldr r4, [r7]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	ldrb r3, [r5, #6]
	movs r0, #0xc8
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r3, _0804B5F8 @ =0x00000F68
	adds r4, r4, r3
	adds r4, r4, r2
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r5
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x63
	ble _0804B458
	ldr r2, _0804B5FC @ =0x040000D4
	ldr r0, _0804B600 @ =0x05000200
	str r0, [r2]
	mov r3, ip
	ldrb r1, [r3, #6]
	lsls r1, r1, #9
	ldr r0, _0804B604 @ =0x0000074C
	adds r1, r1, r0
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r3, _0804B608 @ =0x80000100
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r2]
	mov r0, ip
	ldrb r1, [r0, #6]
	lsls r1, r1, #9
	ldr r0, _0804B60C @ =0x00000B4C
	adds r1, r1, r0
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	mov r1, r8
	cmp r1, #0
	bne _0804B4C8
	b _0804B5E0
_0804B4C8:
	ldr r1, [r6]
	ldr r3, _0804B610 @ =0x00000F58
	adds r2, r1, r3
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0804B614 @ =0x00000F5C
	adds r2, r1, r0
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	adds r3, #8
	adds r2, r1, r3
	movs r0, #0xbc
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0804B618 @ =0x00000F64
	adds r2, r1, r0
	movs r0, #0xbd
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	mov r2, ip
	ldrb r0, [r2, #4]
	ldr r3, _0804B61C @ =0x000010FD
	adds r1, r1, r3
	strb r0, [r1]
	ldr r0, [r6]
	ldrb r1, [r2, #5]
	ldr r2, _0804B620 @ =0x000010FE
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r6]
	mov r3, ip
	ldrb r1, [r3, #6]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r6]
	ldrb r1, [r3, #0xf]
	ldr r3, _0804B624 @ =0x00001101
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	mov r2, ip
	ldrb r1, [r2, #0x10]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	ldrb r1, [r2, #0x11]
	ldr r2, _0804B628 @ =0x00001103
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r6]
	mov r3, ip
	ldrh r2, [r3, #0x12]
	movs r3, #0x99
	lsls r3, r3, #5
	adds r0, r1, r3
	strh r2, [r0]
	mov r0, ip
	ldrh r2, [r0, #0x14]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	mov r0, ip
	ldrh r2, [r0, #0x28]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	mov r0, ip
	ldrh r2, [r0, #0x2a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, _0804B62C @ =0x00001106
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0804B630 @ =0x00001110
	adds r0, r1, r3
	ldrh r3, [r0]
	strh r2, [r0]
	ldr r2, _0804B634 @ =0x00001108
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0804B638 @ =0x00001112
	adds r0, r1, r3
	ldrh r3, [r0]
	strh r2, [r0]
	ldr r2, _0804B63C @ =0x0000110A
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0804B640 @ =0x00001114
	adds r0, r1, r3
	ldrh r3, [r0]
	strh r2, [r0]
	ldr r2, _0804B644 @ =0x0000110C
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0804B648 @ =0x00001116
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, _0804B64C @ =0x0000110E
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	movs r0, #0xa1
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	adds r1, #0x31
	strb r0, [r1]
	movs r3, #0
	ldr r5, _0804B650 @ =0x000010F8
	mov r4, ip
	adds r4, #7
_0804B5C4:
	ldr r2, [r6]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r2, r5
	adds r2, r2, r0
	adds r1, r0, r4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0804B5C4
_0804B5E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B5EC: .4byte gCurrentPinballGame
_0804B5F0: .4byte 0x00000F4C
_0804B5F4: .4byte gMain
_0804B5F8: .4byte 0x00000F68
_0804B5FC: .4byte 0x040000D4
_0804B600: .4byte 0x05000200
_0804B604: .4byte 0x0000074C
_0804B608: .4byte 0x80000100
_0804B60C: .4byte 0x00000B4C
_0804B610: .4byte 0x00000F58
_0804B614: .4byte 0x00000F5C
_0804B618: .4byte 0x00000F64
_0804B61C: .4byte 0x000010FD
_0804B620: .4byte 0x000010FE
_0804B624: .4byte 0x00001101
_0804B628: .4byte 0x00001103
_0804B62C: .4byte 0x00001106
_0804B630: .4byte 0x00001110
_0804B634: .4byte 0x00001108
_0804B638: .4byte 0x00001112
_0804B63C: .4byte 0x0000110A
_0804B640: .4byte 0x00001114
_0804B644: .4byte 0x0000110C
_0804B648: .4byte 0x00001116
_0804B64C: .4byte 0x0000110E
_0804B650: .4byte 0x000010F8

	thumb_func_start sub_4B654
sub_4B654: @ 0x0804B654
	push {lr}
	ldr r0, _0804B66C @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #1
	str r1, [r0]
	ldr r1, _0804B670 @ =0x0E000544
	ldr r2, _0804B674 @ =0x00001410
	bl WriteAndVerifySramFast
	pop {r0}
	bx r0
	.align 2, 0
_0804B66C: .4byte gCurrentPinballGame
_0804B670: .4byte 0x0E000544
_0804B674: .4byte 0x00001410

	thumb_func_start sub_4B678
sub_4B678: @ 0x0804B678
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #1
	bne _0804B6B0
	ldr r3, _0804B6A0 @ =ReadSramFast
	ldr r0, _0804B6A4 @ =0x0E000544
	ldr r1, _0804B6A8 @ =gCurrentPinballGame
	ldr r1, [r1]
	ldr r2, _0804B6AC @ =0x00001410
	ldr r3, [r3]
	bl _call_via_r3
	b _0804B746
	.align 2, 0
_0804B6A0: .4byte ReadSramFast
_0804B6A4: .4byte 0x0E000544
_0804B6A8: .4byte gCurrentPinballGame
_0804B6AC: .4byte 0x00001410
_0804B6B0:
	mov r0, r8
	cmp r0, #2
	bne _0804B746
	ldr r1, _0804B87C @ =0x040000D4
	ldr r0, _0804B880 @ =gUnknown_02031520
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r4, _0804B884 @ =gCurrentPinballGame
	ldr r3, [r4]
	str r3, [r1, #4]
	ldr r0, _0804B888 @ =0x80000A08
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0804B88C @ =0x0000132C
	adds r0, r3, r1
	ldr r2, _0804B890 @ =0x00001334
	adds r1, r3, r2
	str r1, [r0]
	ldr r5, _0804B894 @ =0x00001330
	adds r0, r3, r5
	str r1, [r0]
	ldr r0, _0804B898 @ =gMain
	ldrh r0, [r0, #0x30]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bne _0804B746
	ldr r1, _0804B89C @ =0x00000614
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r5, #0x82
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strb r2, [r0]
	ldr r3, [r4]
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r3, r2
	strh r1, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	subs r5, #0x3e
	adds r0, r3, r5
	strh r1, [r0]
	adds r2, #4
	adds r0, r3, r2
	strh r1, [r0]
	adds r4, #0xc
	adds r0, r3, r4
	strh r1, [r0]
	adds r5, #0xa
	adds r2, r3, r5
	ldr r0, _0804B8A0 @ =0x0000FFFC
	strh r0, [r2]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r3, r2
	subs r2, #0xd8
	strh r2, [r0]
	adds r4, #6
	adds r0, r3, r4
	strh r2, [r0]
	subs r5, #8
	adds r0, r3, r5
	strh r1, [r0]
	adds r2, #0xd0
	adds r0, r3, r2
	strh r1, [r0]
_0804B746:
	mov r3, r8
	cmp r3, #0
	bne _0804B74E
	b _0804B8CC
_0804B74E:
	ldr r4, _0804B898 @ =gMain
	ldr r3, _0804B884 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r5, _0804B8A4 @ =0x000010FD
	adds r0, r1, r5
	ldrb r0, [r0]
	strb r0, [r4, #4]
	ldr r2, _0804B8A8 @ =0x000010FE
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4, #5]
	adds r5, #2
	adds r0, r1, r5
	ldrb r0, [r0]
	strb r0, [r4, #6]
	adds r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4, #0xf]
	adds r5, #3
	adds r0, r1, r5
	ldrb r0, [r0]
	strb r0, [r4, #0x10]
	adds r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	strb r0, [r4, #0x11]
	movs r5, #0x99
	lsls r5, r5, #5
	adds r0, r1, r5
	ldrh r0, [r0]
	strh r0, [r4, #0x12]
	ldr r2, _0804B8AC @ =0x00001322
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r5, #4
	adds r0, r1, r5
	ldrh r0, [r0]
	strh r0, [r4, #0x28]
	adds r2, #4
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x2a]
	ldr r5, _0804B8B0 @ =0x00001110
	adds r0, r1, r5
	ldrh r0, [r0]
	ldrh r2, [r4, #0x38]
	strh r0, [r4, #0x38]
	ldr r2, _0804B8B4 @ =0x00001112
	adds r0, r1, r2
	ldrh r0, [r0]
	ldrh r2, [r4, #0x3a]
	strh r0, [r4, #0x3a]
	adds r5, #4
	adds r0, r1, r5
	ldrh r0, [r0]
	ldrh r2, [r4, #0x3c]
	strh r0, [r4, #0x3c]
	ldr r2, _0804B8B8 @ =0x00001116
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x2c]
	adds r5, #4
	adds r0, r1, r5
	ldrh r0, [r0]
	strh r0, [r4, #0x26]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r5, _0804B8BC @ =0x00000F58
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r5, #4
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r5, #4
	adds r0, r1, r5
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r5, #4
	adds r1, r1, r5
	ldr r0, [r1]
	str r0, [r2]
	movs r5, #0
	mov sl, r3
	adds r7, r4, #0
	adds r6, r7, #7
	mov r4, sl
	ldr r3, _0804B8C0 @ =0x000010F8
_0804B818:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r6
	ldr r0, [r4]
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #4
	ble _0804B818
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0x88
	lsls r2, r2, #5
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	mov r3, r8
	cmp r3, #1
	bne _0804B8DA
	ldrb r0, [r7, #4]
	cmp r0, #1
	bhi _0804B8DA
	mov r4, sl
	ldr r3, [r4]
	adds r2, r3, #0
	adds r2, #0x4e
	ldr r5, _0804B8C4 @ =0x00000121
	adds r0, r3, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r2, _0804B8C8 @ =0x000005FC
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r2, r3, #0
	adds r2, #0xe6
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x68
	strh r0, [r1]
	b _0804B8DA
	.align 2, 0
_0804B87C: .4byte 0x040000D4
_0804B880: .4byte gUnknown_02031520
_0804B884: .4byte gCurrentPinballGame
_0804B888: .4byte 0x80000A08
_0804B88C: .4byte 0x0000132C
_0804B890: .4byte 0x00001334
_0804B894: .4byte 0x00001330
_0804B898: .4byte gMain
_0804B89C: .4byte 0x00000614
_0804B8A0: .4byte 0x0000FFFC
_0804B8A4: .4byte 0x000010FD
_0804B8A8: .4byte 0x000010FE
_0804B8AC: .4byte 0x00001322
_0804B8B0: .4byte 0x00001110
_0804B8B4: .4byte 0x00001112
_0804B8B8: .4byte 0x00001116
_0804B8BC: .4byte 0x00000F58
_0804B8C0: .4byte 0x000010F8
_0804B8C4: .4byte 0x00000121
_0804B8C8: .4byte 0x000005FC
_0804B8CC:
	ldr r0, _0804B958 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x6a
	ldrh r1, [r1]
	adds r0, #0x68
	strh r1, [r0]
_0804B8DA:
	ldr r5, _0804B958 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r1, #0
	strb r1, [r0, #0x1d]
	ldr r4, _0804B95C @ =gMain
	strb r1, [r4, #0xd]
	bl sub_467F4
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _0804B902
	ldr r0, [r5]
	ldr r3, _0804B960 @ =0x0000029E
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804B902
	movs r0, #1
	bl sub_46FD4
_0804B902:
	ldr r0, _0804B95C @ =gMain
	ldrb r1, [r0, #4]
	ldr r4, _0804B958 @ =gCurrentPinballGame
	mov sl, r4
	adds r7, r0, #0
	ldr r5, _0804B964 @ =gUnknown_03005C00
	mov sb, r5
	cmp r1, #1
	bhi _0804B9A0
	movs r5, #0
	ldr r6, _0804B968 @ =0x040000D4
_0804B918:
	mov r0, sl
	ldr r2, [r0]
	adds r2, #0x64
	ldrh r1, [r2]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r1, #0xa
	adds r0, r0, r1
	movs r1, #0x16
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _0804B974
	lsls r0, r0, #0xa
	ldr r1, _0804B96C @ =gUnknown_0200FBB0
	adds r0, r0, r1
	str r0, [r6]
	lsls r0, r2, #0x10
	asrs r0, r0, #6
	ldr r4, _0804B970 @ =0x06008000
	adds r0, r0, r4
	b _0804B988
	.align 2, 0
_0804B958: .4byte gCurrentPinballGame
_0804B95C: .4byte gMain
_0804B960: .4byte 0x0000029E
_0804B964: .4byte gUnknown_03005C00
_0804B968: .4byte 0x040000D4
_0804B96C: .4byte gUnknown_0200FBB0
_0804B970: .4byte 0x06008000
_0804B974:
	subs r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #6
	ldr r1, _0804BA38 @ =gUnknown_020030A0
	adds r0, r0, r1
	str r0, [r6]
	lsls r0, r2, #0x10
	asrs r0, r0, #6
	ldr r1, _0804BA3C @ =0x06008000
	adds r0, r0, r1
_0804B988:
	str r0, [r6, #4]
	ldr r0, _0804BA40 @ =0x80000200
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	lsls r0, r5, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0804B918
_0804B9A0:
	movs r5, #0
	ldr r4, _0804BA44 @ =gUnknown_03005C00
	ldr r3, _0804BA48 @ =0x000001FF
	ldr r2, _0804BA4C @ =0x000007FF
_0804B9A8:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r2
	ble _0804B9A8
	ldr r1, _0804BA50 @ =0x040000D4
	mov r3, sb
	str r3, [r1]
	ldr r0, _0804BA54 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0804BA58 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r4, #0x2c
	ldrsh r0, [r7, r4]
	cmp r0, #0
	beq _0804BABE
	mov r5, sl
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bne _0804BA5C
	movs r2, #0
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bgt _0804BAAE
	mov r6, sb
	movs r4, #0xc1
	lsls r4, r4, #8
_0804B9F6:
	movs r5, #2
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_0804B9FC:
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
	cmp r1, #0xb
	ble _0804B9FC
	movs r5, #0x80
	lsls r5, r5, #9
	adds r1, r2, r5
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	mov r3, sl
	ldr r0, [r3]
	movs r5, #0xa6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r1, r0
	ble _0804B9F6
	b _0804BAAE
	.align 2, 0
_0804BA38: .4byte gUnknown_020030A0
_0804BA3C: .4byte 0x06008000
_0804BA40: .4byte 0x80000200
_0804BA44: .4byte gUnknown_03005C00
_0804BA48: .4byte 0x000001FF
_0804BA4C: .4byte 0x000007FF
_0804BA50: .4byte 0x040000D4
_0804BA54: .4byte 0x06002000
_0804BA58: .4byte 0x80000800
_0804BA5C:
	movs r2, #0
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bgt _0804BAAE
	mov r6, sb
	movs r4, #0xc1
	lsls r4, r4, #8
_0804BA70:
	movs r5, #1
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_0804BA76:
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
	ble _0804BA76
	movs r5, #0x80
	lsls r5, r5, #9
	adds r1, r2, r5
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	mov r3, sl
	ldr r0, [r3]
	movs r5, #0xa6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r1, r0
	ble _0804BA70
_0804BAAE:
	ldr r1, _0804BB20 @ =0x040000D4
	mov r0, sb
	str r0, [r1]
	ldr r0, _0804BB24 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0804BB28 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804BABE:
	ldr r1, _0804BB20 @ =0x040000D4
	ldr r2, _0804BB2C @ =gCurrentPinballGame
	ldr r4, _0804BB30 @ =gMain
	ldrb r0, [r4, #6]
	lsls r0, r0, #9
	ldr r3, _0804BB34 @ =0x0000074C
	adds r0, r0, r3
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [r1]
	ldr r0, _0804BB38 @ =0x05000200
	str r0, [r1, #4]
	ldr r3, _0804BB3C @ =0x80000100
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r4, #6]
	lsls r0, r0, #9
	ldr r5, _0804BB40 @ =0x00000B4C
	adds r0, r0, r5
	adds r0, r2, r0
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0804BB44 @ =0x000005F6
	adds r2, r2, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #5
	ldr r2, _0804BB48 @ =gUnknown_08137E14
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0804BB4C @ =0x05000220
	str r0, [r1, #4]
	ldr r0, _0804BB50 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_4BC34
	ldrb r0, [r4, #4]
	cmp r0, #7
	bhi _0804BBC0
	lsls r0, r0, #2
	ldr r1, _0804BB54 @ =_0804BB58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BB20: .4byte 0x040000D4
_0804BB24: .4byte 0x06002000
_0804BB28: .4byte 0x80000400
_0804BB2C: .4byte gCurrentPinballGame
_0804BB30: .4byte gMain
_0804BB34: .4byte 0x0000074C
_0804BB38: .4byte 0x05000200
_0804BB3C: .4byte 0x80000100
_0804BB40: .4byte 0x00000B4C
_0804BB44: .4byte 0x000005F6
_0804BB48: .4byte gUnknown_08137E14
_0804BB4C: .4byte 0x05000220
_0804BB50: .4byte 0x80000010
_0804BB54: .4byte _0804BB58
_0804BB58: @ jump table
	.4byte _0804BB78 @ case 0
	.4byte _0804BB98 @ case 1
	.4byte _0804BB9E @ case 2
	.4byte _0804BBA4 @ case 3
	.4byte _0804BBAA @ case 4
	.4byte _0804BBB0 @ case 5
	.4byte _0804BBB6 @ case 6
	.4byte _0804BBBC @ case 7
_0804BB78:
	bl sub_50848
	ldr r0, _0804BB90 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r3, _0804BB94 @ =0x000001A5
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_4E9F0
	b _0804BBC0
	.align 2, 0
_0804BB90: .4byte gCurrentPinballGame
_0804BB94: .4byte 0x000001A5
_0804BB98:
	bl sub_50AD4
	b _0804BBC0
_0804BB9E:
	bl sub_50D48
	b _0804BBC0
_0804BBA4:
	bl sub_50DE0
	b _0804BBC0
_0804BBAA:
	bl sub_50F04
	b _0804BBC0
_0804BBB0:
	bl sub_50FD4
	b _0804BBC0
_0804BBB6:
	bl sub_51090
	b _0804BBC0
_0804BBBC:
	bl sub_51150
_0804BBC0:
	movs r5, #0
	ldr r4, _0804BC24 @ =gCurrentPinballGame
	mov sl, r4
	ldr r7, _0804BC28 @ =gMain
	movs r0, #0xb8
	mov ip, r0
_0804BBCC:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	mov r4, ip
	muls r4, r1, r4
	adds r4, r4, r7
	mov r2, sl
	ldr r6, [r2]
	lsls r2, r1, #1
	ldrb r3, [r7, #6]
	movs r0, #0xc8
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r3, _0804BC2C @ =0x00000F68
	adds r0, r6, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r5, #0xbe
	lsls r5, r5, #2
	adds r4, r4, r5
	strh r0, [r4]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x63
	ble _0804BBCC
	mov r0, r8
	cmp r0, #1
	bne _0804BC14
	movs r0, #0
	str r0, [r6]
	ldr r1, _0804BC30 @ =0x0E000544
	adds r0, r6, #0
	movs r2, #4
	bl WriteAndVerifySramFast
_0804BC14:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804BC24: .4byte gCurrentPinballGame
_0804BC28: .4byte gMain
_0804BC2C: .4byte 0x00000F68
_0804BC30: .4byte 0x0E000544

	thumb_func_start sub_4BC34
sub_4BC34: @ 0x0804BC34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0804BC50 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #7
	bhi _0804BCC6
	lsls r0, r0, #2
	ldr r1, _0804BC54 @ =_0804BC58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BC50: .4byte gMain
_0804BC54: .4byte _0804BC58
_0804BC58: @ jump table
	.4byte _0804BC78 @ case 0
	.4byte _0804BC82 @ case 1
	.4byte _0804BC8C @ case 2
	.4byte _0804BC96 @ case 3
	.4byte _0804BCA0 @ case 4
	.4byte _0804BCAA @ case 5
	.4byte _0804BCB4 @ case 6
	.4byte _0804BCBE @ case 7
_0804BC78:
	bl sub_4C290
	bl sub_4C808
	b _0804BCC6
_0804BC82:
	bl sub_4C290
	bl sub_4CA18
	b _0804BCC6
_0804BC8C:
	bl nullsub_18
	bl sub_4CAE8
	b _0804BCC6
_0804BC96:
	bl nullsub_18
	bl sub_4CB0C
	b _0804BCC6
_0804BCA0:
	bl nullsub_18
	bl sub_4CB30
	b _0804BCC6
_0804BCAA:
	bl nullsub_18
	bl sub_4CBB4
	b _0804BCC6
_0804BCB4:
	bl nullsub_18
	bl sub_4CC58
	b _0804BCC6
_0804BCBE:
	bl nullsub_18
	bl sub_4CD60
_0804BCC6:
	ldr r0, _0804BCE4 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r1, #0xe4
	ldrb r1, [r1]
	subs r1, #1
	adds r3, r0, #0
	cmp r1, #0x15
	bls _0804BCD8
	b _0804C274
_0804BCD8:
	lsls r0, r1, #2
	ldr r1, _0804BCE8 @ =_0804BCEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BCE4: .4byte gCurrentPinballGame
_0804BCE8: .4byte _0804BCEC
_0804BCEC: @ jump table
	.4byte _0804BD44 @ case 0
	.4byte _0804BDA4 @ case 1
	.4byte _0804BDC4 @ case 2
	.4byte _0804BDE4 @ case 3
	.4byte _0804BE14 @ case 4
	.4byte _0804BE34 @ case 5
	.4byte _0804BE54 @ case 6
	.4byte _0804BE74 @ case 7
	.4byte _0804BE94 @ case 8
	.4byte _0804BEB4 @ case 9
	.4byte _0804BED4 @ case 10
	.4byte _0804BEF4 @ case 11
	.4byte _0804BFB0 @ case 12
	.4byte _0804BF14 @ case 13
	.4byte _0804C094 @ case 14
	.4byte _0804C0C8 @ case 15
	.4byte _0804C0E8 @ case 16
	.4byte _0804C108 @ case 17
	.4byte _0804C1A8 @ case 18
	.4byte _0804C1C8 @ case 19
	.4byte _0804C1E8 @ case 20
	.4byte _0804C264 @ case 21
_0804BD44:
	ldr r1, [r3]
	movs r2, #0xf1
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0804BD84
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0804BD84
	ldr r1, _0804BD74 @ =0x040000D4
	ldr r0, _0804BD78 @ =gUnknown_08395A4C
	str r0, [r1]
	ldr r0, _0804BD7C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BD80 @ =0x80001200
	b _0804C270
	.align 2, 0
_0804BD74: .4byte 0x040000D4
_0804BD78: .4byte gUnknown_08395A4C
_0804BD7C: .4byte 0x06015800
_0804BD80: .4byte 0x80001200
_0804BD84:
	ldr r1, _0804BD94 @ =0x040000D4
	ldr r0, _0804BD98 @ =gUnknown_08397E6C
	str r0, [r1]
	ldr r0, _0804BD9C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BDA0 @ =0x80001200
	b _0804C270
	.align 2, 0
_0804BD94: .4byte 0x040000D4
_0804BD98: .4byte gUnknown_08397E6C
_0804BD9C: .4byte 0x06015800
_0804BDA0: .4byte 0x80001200
_0804BDA4:
	ldr r1, _0804BDB4 @ =0x040000D4
	ldr r0, _0804BDB8 @ =gUnknown_083A704C
	str r0, [r1]
	ldr r0, _0804BDBC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BDC0 @ =0x80000800
	b _0804C270
	.align 2, 0
_0804BDB4: .4byte 0x040000D4
_0804BDB8: .4byte gUnknown_083A704C
_0804BDBC: .4byte 0x06015800
_0804BDC0: .4byte 0x80000800
_0804BDC4:
	ldr r1, _0804BDD4 @ =0x040000D4
	ldr r0, _0804BDD8 @ =gUnknown_0848FD8C
	str r0, [r1]
	ldr r0, _0804BDDC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BDE0 @ =0x80000650
	b _0804C270
	.align 2, 0
_0804BDD4: .4byte 0x040000D4
_0804BDD8: .4byte gUnknown_0848FD8C
_0804BDDC: .4byte 0x06015800
_0804BDE0: .4byte 0x80000650
_0804BDE4:
	ldr r1, _0804BE04 @ =0x040000D4
	ldr r2, _0804BE08 @ =gUnknown_086ACEF8
	ldr r0, [r3]
	adds r0, #0xf2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0804BE0C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BE10 @ =0x800012F0
	b _0804C270
	.align 2, 0
_0804BE04: .4byte 0x040000D4
_0804BE08: .4byte gUnknown_086ACEF8
_0804BE0C: .4byte 0x06015800
_0804BE10: .4byte 0x800012F0
_0804BE14:
	ldr r1, _0804BE24 @ =0x040000D4
	ldr r0, _0804BE28 @ =gUnknown_083A07CC
	str r0, [r1]
	ldr r0, _0804BE2C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BE30 @ =0x80001000
	b _0804C270
	.align 2, 0
_0804BE24: .4byte 0x040000D4
_0804BE28: .4byte gUnknown_083A07CC
_0804BE2C: .4byte 0x06015800
_0804BE30: .4byte 0x80001000
_0804BE34:
	ldr r1, _0804BE44 @ =0x040000D4
	ldr r0, _0804BE48 @ =gUnknown_083A29EC
	str r0, [r1]
	ldr r0, _0804BE4C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BE50 @ =0x80000400
	b _0804C270
	.align 2, 0
_0804BE44: .4byte 0x040000D4
_0804BE48: .4byte gUnknown_083A29EC
_0804BE4C: .4byte 0x06015800
_0804BE50: .4byte 0x80000400
_0804BE54:
	ldr r1, _0804BE64 @ =0x040000D4
	ldr r0, _0804BE68 @ =gUnknown_083A340C
	str r0, [r1]
	ldr r0, _0804BE6C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BE70 @ =0x80001000
	b _0804C270
	.align 2, 0
_0804BE64: .4byte 0x040000D4
_0804BE68: .4byte gUnknown_083A340C
_0804BE6C: .4byte 0x06015800
_0804BE70: .4byte 0x80001000
_0804BE74:
	ldr r1, _0804BE84 @ =0x040000D4
	ldr r0, _0804BE88 @ =gUnknown_083A562C
	str r0, [r1]
	ldr r0, _0804BE8C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BE90 @ =0x80000C00
	b _0804C270
	.align 2, 0
_0804BE84: .4byte 0x040000D4
_0804BE88: .4byte gUnknown_083A562C
_0804BE8C: .4byte 0x06015800
_0804BE90: .4byte 0x80000C00
_0804BE94:
	ldr r1, _0804BEA4 @ =0x040000D4
	ldr r0, _0804BEA8 @ =gUnknown_081428D4
	str r0, [r1]
	ldr r0, _0804BEAC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BEB0 @ =0x80000E00
	b _0804C270
	.align 2, 0
_0804BEA4: .4byte 0x040000D4
_0804BEA8: .4byte gUnknown_081428D4
_0804BEAC: .4byte 0x06015800
_0804BEB0: .4byte 0x80000E00
_0804BEB4:
	ldr r1, _0804BEC4 @ =0x040000D4
	ldr r0, _0804BEC8 @ =gUnknown_0839C78C
	str r0, [r1]
	ldr r0, _0804BECC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BED0 @ =0x80000A00
	b _0804C270
	.align 2, 0
_0804BEC4: .4byte 0x040000D4
_0804BEC8: .4byte gUnknown_0839C78C
_0804BECC: .4byte 0x06015800
_0804BED0: .4byte 0x80000A00
_0804BED4:
	ldr r1, _0804BEE4 @ =0x040000D4
	ldr r0, _0804BEE8 @ =gUnknown_0839DDAC
	str r0, [r1]
	ldr r0, _0804BEEC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BEF0 @ =0x80001400
	b _0804C270
	.align 2, 0
_0804BEE4: .4byte 0x040000D4
_0804BEE8: .4byte gUnknown_0839DDAC
_0804BEEC: .4byte 0x06015800
_0804BEF0: .4byte 0x80001400
_0804BEF4:
	ldr r1, _0804BF04 @ =0x040000D4
	ldr r0, _0804BF08 @ =gUnknown_084FA20C
	str r0, [r1]
	ldr r0, _0804BF0C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804BF10 @ =0x80000140
	b _0804C270
	.align 2, 0
_0804BF04: .4byte 0x040000D4
_0804BF08: .4byte gUnknown_084FA20C
_0804BF0C: .4byte 0x06015800
_0804BF10: .4byte 0x80000140
_0804BF14:
	movs r2, #0
	ldr r7, _0804BF50 @ =gUnknown_084F61EC
	mov r8, r7
	ldr r0, _0804BF54 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r1, r0
	mov sb, r1
	ldr r3, _0804BF58 @ =gSpeciesInfo+7 (PokemonSpecies.name)
	mov ip, r3
	ldr r4, _0804BF5C @ =0x040000D4
	ldr r6, _0804BF60 @ =0x06015800
	ldr r5, _0804BF64 @ =0x80000020
_0804BF30:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	mov r7, sb
	ldrh r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _0804BF6C
	ldr r0, _0804BF68 @ =gUnknown_083FFD4C
	b _0804BF76
	.align 2, 0
_0804BF50: .4byte gUnknown_084F61EC
_0804BF54: .4byte gCurrentPinballGame
_0804BF58: .4byte gSpeciesInfo+7
_0804BF5C: .4byte 0x040000D4
_0804BF60: .4byte 0x06015800
_0804BF64: .4byte 0x80000020
_0804BF68: .4byte gUnknown_083FFD4C
_0804BF6C:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _0804BFA0 @ =gUnknown_083FF04C
	adds r0, r0, r1
_0804BF76:
	str r0, [r4]
	lsls r0, r3, #6
	adds r0, r0, r6
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0804BF30
	ldr r1, _0804BFA4 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _0804BFA8 @ =0x06015C00
	str r0, [r1, #4]
	ldr r0, _0804BFAC @ =0x800004A0
	b _0804C270
	.align 2, 0
_0804BFA0: .4byte gUnknown_083FF04C
_0804BFA4: .4byte 0x040000D4
_0804BFA8: .4byte 0x06015C00
_0804BFAC: .4byte 0x800004A0
_0804BFB0:
	movs r2, #0
	ldr r0, _0804BFE8 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r3, r3, r0
	mov r8, r3
	ldr r7, _0804BFEC @ =gSpeciesInfo+7 (PokemonSpecies.name)
	mov ip, r7
	ldr r4, _0804BFF0 @ =0x040000D4
	ldr r6, _0804BFF4 @ =0x06015800
	ldr r5, _0804BFF8 @ =0x80000020
_0804BFC8:
	lsls r0, r2, #0x10
	asrs r3, r0, #0x10
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _0804C000
	ldr r0, _0804BFFC @ =gUnknown_083FFD4C
	b _0804C00A
	.align 2, 0
_0804BFE8: .4byte gCurrentPinballGame
_0804BFEC: .4byte gSpeciesInfo+7
_0804BFF0: .4byte 0x040000D4
_0804BFF4: .4byte 0x06015800
_0804BFF8: .4byte 0x80000020
_0804BFFC: .4byte gUnknown_083FFD4C
_0804C000:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _0804C04C @ =gUnknown_083FF04C
	adds r0, r0, r1
_0804C00A:
	str r0, [r4]
	lsls r0, r3, #6
	adds r0, r0, r6
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	lsls r0, r2, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0804BFC8
	movs r2, #0
	ldr r3, _0804C050 @ =gUnknown_086ACFE0
	mov ip, r3
	ldr r5, _0804C054 @ =0x040000D4
	ldr r7, _0804C058 @ =0x06015800
	ldr r6, _0804C05C @ =0x80000020
_0804C032:
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	mov r2, ip
	adds r3, r1, r2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r0, #0
	cmp r1, #0x20
	bne _0804C064
	ldr r0, _0804C060 @ =gUnknown_083FFD4C
	b _0804C070
	.align 2, 0
_0804C04C: .4byte gUnknown_083FF04C
_0804C050: .4byte gUnknown_086ACFE0
_0804C054: .4byte 0x040000D4
_0804C058: .4byte 0x06015800
_0804C05C: .4byte 0x80000020
_0804C060: .4byte gUnknown_083FFD4C
_0804C064:
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _0804C090 @ =gUnknown_083FF04C
	adds r0, r0, r1
_0804C070:
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xa
	lsls r0, r0, #6
	adds r0, r0, r7
	str r0, [r5, #4]
	str r6, [r5, #8]
	ldr r0, [r5, #8]
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r2, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0804C032
	b _0804C274
	.align 2, 0
_0804C090: .4byte gUnknown_083FF04C
_0804C094:
	ldr r1, _0804C0B4 @ =0x040000D4
	ldr r2, _0804C0B8 @ =gUnknown_086AD474
	ldr r0, [r3]
	ldr r7, _0804C0BC @ =0x0000025F
	adds r0, r0, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0804C0C0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C0C4 @ =0x80000E00
	b _0804C270
	.align 2, 0
_0804C0B4: .4byte 0x040000D4
_0804C0B8: .4byte gUnknown_086AD474
_0804C0BC: .4byte 0x0000025F
_0804C0C0: .4byte 0x06015800
_0804C0C4: .4byte 0x80000E00
_0804C0C8:
	ldr r1, _0804C0D8 @ =0x040000D4
	ldr r0, _0804C0DC @ =gUnknown_08158284
	str r0, [r1]
	ldr r0, _0804C0E0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C0E4 @ =0x80001200
	b _0804C270
	.align 2, 0
_0804C0D8: .4byte 0x040000D4
_0804C0DC: .4byte gUnknown_08158284
_0804C0E0: .4byte 0x06015800
_0804C0E4: .4byte 0x80001200
_0804C0E8:
	ldr r1, _0804C0F8 @ =0x040000D4
	ldr r0, _0804C0FC @ =gUnknown_083A562C
	str r0, [r1]
	ldr r0, _0804C100 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C104 @ =0x80000C00
	b _0804C270
	.align 2, 0
_0804C0F8: .4byte 0x040000D4
_0804C0FC: .4byte gUnknown_083A562C
_0804C100: .4byte 0x06015800
_0804C104: .4byte 0x80000C00
_0804C108:
	ldr r7, _0804C17C @ =0x040000D4
	ldr r0, _0804C180 @ =gUnknown_084F61EC
	str r0, [r7]
	ldr r0, _0804C184 @ =0x06015C00
	str r0, [r7, #4]
	ldr r0, _0804C188 @ =0x800004A0
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	ldr r2, [r3]
	ldr r1, _0804C18C @ =0x000001A5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0804C12A
	b _0804C274
_0804C12A:
	ldr r1, _0804C190 @ =gUnknown_086AD2DE
	movs r3, #0xd3
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	lsls r4, r4, #3
	ldr r0, _0804C194 @ =gUnknown_086AD000
	adds r4, r4, r0
	ldrh r0, [r4, #6]
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	ldr r6, _0804C198 @ =gUnknown_08480E0C
	adds r0, r0, r6
	str r0, [r7]
	ldr r0, _0804C19C @ =0x06015DA0
	str r0, [r7, #4]
	ldr r5, _0804C1A0 @ =0x80000020
	str r5, [r7, #8]
	ldr r0, [r7, #8]
	ldrh r0, [r4, #6]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xa
	adds r0, r0, r6
	str r0, [r7]
	ldr r0, _0804C1A4 @ =0x06015E60
	str r0, [r7, #4]
	str r5, [r7, #8]
	ldr r0, [r7, #8]
	b _0804C274
	.align 2, 0
_0804C17C: .4byte 0x040000D4
_0804C180: .4byte gUnknown_084F61EC
_0804C184: .4byte 0x06015C00
_0804C188: .4byte 0x800004A0
_0804C18C: .4byte 0x000001A5
_0804C190: .4byte gUnknown_086AD2DE
_0804C194: .4byte gUnknown_086AD000
_0804C198: .4byte gUnknown_08480E0C
_0804C19C: .4byte 0x06015DA0
_0804C1A0: .4byte 0x80000020
_0804C1A4: .4byte 0x06015E60
_0804C1A8:
	ldr r1, _0804C1B8 @ =0x040000D4
	ldr r0, _0804C1BC @ =gUnknown_0850100C
	str r0, [r1]
	ldr r0, _0804C1C0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C1C4 @ =0x80001200
	b _0804C270
	.align 2, 0
_0804C1B8: .4byte 0x040000D4
_0804C1BC: .4byte gUnknown_0850100C
_0804C1C0: .4byte 0x06015800
_0804C1C4: .4byte 0x80001200
_0804C1C8:
	ldr r1, _0804C1D8 @ =0x040000D4
	ldr r0, _0804C1DC @ =gUnknown_0850398C
	str r0, [r1]
	ldr r0, _0804C1E0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C1E4 @ =0x80001400
	b _0804C270
	.align 2, 0
_0804C1D8: .4byte 0x040000D4
_0804C1DC: .4byte gUnknown_0850398C
_0804C1E0: .4byte 0x06015800
_0804C1E4: .4byte 0x80001400
_0804C1E8:
	ldr r0, _0804C20C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0804C22C
	ldr r1, _0804C210 @ =0x040000D4
	ldr r0, _0804C214 @ =gUnknown_081BCAA4
	str r0, [r1]
	ldr r0, _0804C218 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C21C @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0804C220 @ =gUnknown_081BE2C4
	str r0, [r1]
	ldr r0, _0804C224 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0804C228 @ =0x80000010
	b _0804C270
	.align 2, 0
_0804C20C: .4byte gMain
_0804C210: .4byte 0x040000D4
_0804C214: .4byte gUnknown_081BCAA4
_0804C218: .4byte 0x06015800
_0804C21C: .4byte 0x80000C00
_0804C220: .4byte gUnknown_081BE2C4
_0804C224: .4byte 0x050003C0
_0804C228: .4byte 0x80000010
_0804C22C:
	ldr r1, _0804C248 @ =0x040000D4
	ldr r0, _0804C24C @ =gUnknown_081BE4C4
	str r0, [r1]
	ldr r0, _0804C250 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C254 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0804C258 @ =gUnknown_081BFCE4
	str r0, [r1]
	ldr r0, _0804C25C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0804C260 @ =0x80000010
	b _0804C270
	.align 2, 0
_0804C248: .4byte 0x040000D4
_0804C24C: .4byte gUnknown_081BE4C4
_0804C250: .4byte 0x06015800
_0804C254: .4byte 0x80000C00
_0804C258: .4byte gUnknown_081BFCE4
_0804C25C: .4byte 0x050003C0
_0804C260: .4byte 0x80000010
_0804C264:
	ldr r1, _0804C280 @ =0x040000D4
	ldr r0, _0804C284 @ =gUnknown_08526DCC
	str r0, [r1]
	ldr r0, _0804C288 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804C28C @ =0x80000600
_0804C270:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804C274:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C280: .4byte 0x040000D4
_0804C284: .4byte gUnknown_08526DCC
_0804C288: .4byte 0x06015800
_0804C28C: .4byte 0x80000600

	thumb_func_start sub_4C290
sub_4C290: @ 0x0804C290
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_28AE0
	bl sub_28BFC
	movs r1, #0
	ldr r0, _0804C3B8 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r3, _0804C3BC @ =0x040000D4
	mov sb, r0
_0804C2AE:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _0804C3C0 @ =0x000013BC
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0804C3C4 @ =gUnknown_083FE44C
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #9
	ldr r5, _0804C3C8 @ =0x06010000
	adds r0, r0, r5
	str r0, [r3, #4]
	ldr r0, _0804C3CC @ =0x80000100
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0804C2AE
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0804C3D0 @ =0x0000132C
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	ldr r2, _0804C3BC @ =0x040000D4
	lsrs r0, r0, #0xc
	lsls r0, r0, #7
	ldr r1, _0804C3D4 @ =gUnknown_083BB16C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C3D8 @ =0x06010400
	str r0, [r2, #4]
	ldr r0, _0804C3DC @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r5, _0804C3E0 @ =gUnknown_084C07EC
	ldr r6, _0804C3E4 @ =gUnknown_084FA48C
	ldr r7, _0804C3E8 @ =gUnknown_084C00EC
	adds r3, r2, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r2, _0804C3EC @ =0x00000744
	adds r4, r0, r2
_0804C320:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r5
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r1, _0804C3F0 @ =0x06010480
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0804C3F4 @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0804C320
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _0804C3F8 @ =0x000001E5
	adds r0, r0, r3
	ldr r2, _0804C3BC @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r6
	str r0, [r2]
	ldr r0, _0804C3FC @ =0x06010780
	str r0, [r2, #4]
	ldr r0, _0804C400 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	mov sl, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #7
	adds r0, r0, r7
	str r0, [r2]
	ldr r0, _0804C404 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _0804C3DC @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
_0804C396:
	mov r2, sb
	ldr r0, [r2]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	ldr r3, _0804C408 @ =0x00000747
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r7, r2, #0
	cmp r0, #9
	bls _0804C3AE
	b _0804C602
_0804C3AE:
	lsls r0, r0, #2
	ldr r1, _0804C40C @ =_0804C410
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804C3B8: .4byte gCurrentPinballGame
_0804C3BC: .4byte 0x040000D4
_0804C3C0: .4byte 0x000013BC
_0804C3C4: .4byte gUnknown_083FE44C
_0804C3C8: .4byte 0x06010000
_0804C3CC: .4byte 0x80000100
_0804C3D0: .4byte 0x0000132C
_0804C3D4: .4byte gUnknown_083BB16C
_0804C3D8: .4byte 0x06010400
_0804C3DC: .4byte 0x80000040
_0804C3E0: .4byte gUnknown_084C07EC
_0804C3E4: .4byte gUnknown_084FA48C
_0804C3E8: .4byte gUnknown_084C00EC
_0804C3EC: .4byte 0x00000744
_0804C3F0: .4byte 0x06010480
_0804C3F4: .4byte 0x800000C0
_0804C3F8: .4byte 0x000001E5
_0804C3FC: .4byte 0x06010780
_0804C400: .4byte 0x80000090
_0804C404: .4byte 0x06010AE0
_0804C408: .4byte 0x00000747
_0804C40C: .4byte _0804C410
_0804C410: @ jump table
	.4byte _0804C438 @ case 0
	.4byte _0804C5D4 @ case 1
	.4byte _0804C5D4 @ case 2
	.4byte _0804C55E @ case 3
	.4byte _0804C5D4 @ case 4
	.4byte _0804C602 @ case 5
	.4byte _0804C5D4 @ case 6
	.4byte _0804C5D4 @ case 7
	.4byte _0804C5D4 @ case 8
	.4byte _0804C460 @ case 9
_0804C438:
	ldr r3, _0804C454 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	asrs r2, r7, #0x10
	ldr r1, _0804C458 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804C45C @ =gUnknown_0848D68C
	b _0804C5EC
	.align 2, 0
_0804C454: .4byte 0x040000D4
_0804C458: .4byte 0x00000749
_0804C45C: .4byte gUnknown_0848D68C
_0804C460:
	mov r5, sb
	ldr r4, [r5]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0804C510
	ldr r1, _0804C498 @ =gMain+0x74
	ldr r2, _0804C49C @ =0x0000059A
	adds r0, r4, r2
	ldrh r3, [r0]
	adds r1, r3, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804C4AC
	asrs r3, r7, #0x10
	ldr r2, _0804C4A0 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r3
	movs r1, #0xcd
	strb r1, [r0]
	ldr r6, _0804C4A4 @ =0x040000D4
	ldr r5, _0804C4A8 @ =gMonPortraitGroupPals
	mov r8, r5
	b _0804C528
	.align 2, 0
_0804C498: .4byte gMain+0x74
_0804C49C: .4byte 0x0000059A
_0804C4A0: .4byte 0x00000749
_0804C4A4: .4byte 0x040000D4
_0804C4A8: .4byte gMonPortraitGroupPals
_0804C4AC:
	cmp r0, #3
	bhi _0804C4E8
	asrs r1, r7, #0x10
	ldr r2, _0804C4D4 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, _0804C4D8 @ =0x040000D4
	ldr r0, _0804C4DC @ =gMonPortraitGroupPals
	ldr r0, [r0]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0804C4E0 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0804C4E4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0804C55E
	.align 2, 0
_0804C4D4: .4byte 0x00000749
_0804C4D8: .4byte 0x040000D4
_0804C4DC: .4byte gMonPortraitGroupPals
_0804C4E0: .4byte 0x050003A0
_0804C4E4: .4byte 0x80000010
_0804C4E8:
	asrs r2, r7, #0x10
	ldr r1, _0804C504 @ =0x00000749
	adds r0, r4, r1
	adds r0, r0, r2
	strb r3, [r0]
	ldr r6, _0804C508 @ =0x040000D4
	ldr r5, _0804C50C @ =gMonPortraitGroupPals
	mov r8, r5
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	adds r0, r0, r2
	b _0804C530
	.align 2, 0
_0804C504: .4byte 0x00000749
_0804C508: .4byte 0x040000D4
_0804C50C: .4byte gMonPortraitGroupPals
_0804C510:
	asrs r3, r7, #0x10
	ldr r2, _0804C5B4 @ =0x00000749
	adds r1, r4, r2
	adds r1, r1, r3
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r6, _0804C5B8 @ =0x040000D4
	ldr r0, _0804C5BC @ =gMonPortraitGroupPals
	mov r8, r0
_0804C528:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r2
	adds r0, r0, r3
_0804C530:
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r6]
	ldr r0, _0804C5C0 @ =0x050003A0
	str r0, [r6, #4]
	ldr r0, _0804C5C4 @ =0x80000010
	str r0, [r6, #8]
	ldr r0, [r6, #8]
_0804C55E:
	ldr r2, _0804C5B8 @ =0x040000D4
	ldr r3, _0804C5C8 @ =gMonPortraitGroupGfx
	mov r8, r3
	mov r5, sb
	ldr r0, [r5]
	asrs r6, r7, #0x10
	ldr r1, _0804C5B4 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r6
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	str r2, [sp]
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	ldr r2, [sp]
	str r0, [r2]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r3, _0804C5CC @ =0x06010CA0
	adds r0, r0, r3
	str r0, [r2, #4]
	ldr r0, _0804C5D0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0804C602
	.align 2, 0
_0804C5B4: .4byte 0x00000749
_0804C5B8: .4byte 0x040000D4
_0804C5BC: .4byte gMonPortraitGroupPals
_0804C5C0: .4byte 0x050003A0
_0804C5C4: .4byte 0x80000010
_0804C5C8: .4byte gMonPortraitGroupGfx
_0804C5CC: .4byte 0x06010CA0
_0804C5D0: .4byte 0x80000180
_0804C5D4:
	ldr r3, _0804C630 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	asrs r2, r7, #0x10
	ldr r1, _0804C634 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804C638 @ =gUnknown_083A8EEC
_0804C5EC:
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #8
	ldr r2, _0804C63C @ =0x06010CA0
	adds r0, r0, r2
	str r0, [r3, #4]
	ldr r0, _0804C640 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_0804C602:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r7, r3
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0804C612
	b _0804C396
_0804C612:
	mov r5, sb
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0804C69C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #7
	blt _0804C69C
	cmp r0, #8
	ble _0804C644
	cmp r0, #9
	beq _0804C660
	b _0804C69C
	.align 2, 0
_0804C630: .4byte 0x040000D4
_0804C634: .4byte 0x00000749
_0804C638: .4byte gUnknown_083A8EEC
_0804C63C: .4byte 0x06010CA0
_0804C640: .4byte 0x80000180
_0804C644:
	ldr r2, _0804C654 @ =0x000005A9
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C68C
	ldr r1, _0804C658 @ =0x040000D4
	ldr r0, _0804C65C @ =gUnknown_02031060
	b _0804C690
	.align 2, 0
_0804C654: .4byte 0x000005A9
_0804C658: .4byte 0x040000D4
_0804C65C: .4byte gUnknown_02031060
_0804C660:
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	bgt _0804C69C
	ldr r5, _0804C680 @ =0x000005A9
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C68C
	ldr r1, _0804C684 @ =0x040000D4
	ldr r0, _0804C688 @ =gUnknown_02031060
	b _0804C690
	.align 2, 0
_0804C680: .4byte 0x000005A9
_0804C684: .4byte 0x040000D4
_0804C688: .4byte gUnknown_02031060
_0804C68C:
	ldr r1, _0804C6B8 @ =0x040000D4
	ldr r0, _0804C6BC @ =gUnknown_02030760
_0804C690:
	str r0, [r1]
	ldr r0, _0804C6C0 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _0804C6C4 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804C69C:
	mov r0, sb
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bne _0804C720
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #2
	beq _0804C6C8
	cmp r0, #3
	beq _0804C6E4
	b _0804C720
	.align 2, 0
_0804C6B8: .4byte 0x040000D4
_0804C6BC: .4byte gUnknown_02030760
_0804C6C0: .4byte 0x06010CA0
_0804C6C4: .4byte 0x80000240
_0804C6C8:
	ldr r2, _0804C6D8 @ =0x000005A9
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C710
	ldr r1, _0804C6DC @ =0x040000D4
	ldr r0, _0804C6E0 @ =gUnknown_02031060
	b _0804C714
	.align 2, 0
_0804C6D8: .4byte 0x000005A9
_0804C6DC: .4byte 0x040000D4
_0804C6E0: .4byte gUnknown_02031060
_0804C6E4:
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	bgt _0804C720
	ldr r5, _0804C704 @ =0x000005A9
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C710
	ldr r1, _0804C708 @ =0x040000D4
	ldr r0, _0804C70C @ =gUnknown_02031060
	b _0804C714
	.align 2, 0
_0804C704: .4byte 0x000005A9
_0804C708: .4byte 0x040000D4
_0804C70C: .4byte gUnknown_02031060
_0804C710:
	ldr r1, _0804C7C4 @ =0x040000D4
	ldr r0, _0804C7C8 @ =gUnknown_02030760
_0804C714:
	str r0, [r1]
	ldr r0, _0804C7CC @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _0804C7D0 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804C720:
	ldr r2, _0804C7C4 @ =0x040000D4
	mov r1, sb
	ldr r0, [r1]
	ldr r3, _0804C7D4 @ =0x0000020B
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r5, _0804C7D8 @ =gUnknown_0844838C
	adds r0, r0, r5
	str r0, [r2]
	ldr r0, _0804C7DC @ =0x060113C0
	str r0, [r2, #4]
	ldr r0, _0804C7E0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r1, sb
	ldr r0, [r1]
	adds r3, #0x54
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r5, _0804C7E4 @ =gUnknown_086AD49C
	adds r0, r0, r5
	mov r3, sl
	lsls r1, r3, #0x10
	asrs r1, r1, #7
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C7E8 @ =0x060116C0
	str r0, [r2, #4]
	ldr r3, _0804C7EC @ =0x80000100
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _0804C7F0 @ =0x000001ED
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0804C7F4 @ =gUnknown_086AD2EE
	adds r1, #6
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #9
	ldr r1, _0804C7F8 @ =gUnknown_084FD18C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C7FC @ =0x06011CE0
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #9
	ldr r1, _0804C800 @ =gUnknown_083BD36C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C804 @ =0x06011EE0
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C7C4: .4byte 0x040000D4
_0804C7C8: .4byte gUnknown_02030760
_0804C7CC: .4byte 0x06010CA0
_0804C7D0: .4byte 0x80000240
_0804C7D4: .4byte 0x0000020B
_0804C7D8: .4byte gUnknown_0844838C
_0804C7DC: .4byte 0x060113C0
_0804C7E0: .4byte 0x80000180
_0804C7E4: .4byte gUnknown_086AD49C
_0804C7E8: .4byte 0x060116C0
_0804C7EC: .4byte 0x80000100
_0804C7F0: .4byte 0x000001ED
_0804C7F4: .4byte gUnknown_086AD2EE
_0804C7F8: .4byte gUnknown_084FD18C
_0804C7FC: .4byte 0x06011CE0
_0804C800: .4byte gUnknown_083BD36C
_0804C804: .4byte 0x06011EE0

	thumb_func_start sub_4C808
sub_4C808: @ 0x0804C808
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0804C90C @ =gUnknown_086AD2EE
	ldr r6, _0804C910 @ =gCurrentPinballGame
	ldr r5, [r6]
	ldr r2, _0804C914 @ =0x000001ED
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r4, _0804C918 @ =0x040000D4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0804C91C @ =gUnknown_084FB68C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0804C920 @ =0x060122A0
	str r0, [r4, #4]
	ldr r0, _0804C924 @ =0x80000240
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0804C928 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r2, _0804C92C @ =gUnknown_083C3C2C
	adds r1, r1, r2
	str r1, [r4]
	ldr r1, _0804C930 @ =0x06012720
	str r1, [r4, #4]
	ldr r1, _0804C934 @ =0x80000180
	str r1, [r4, #8]
	ldr r1, [r4, #8]
	ldr r1, _0804C938 @ =0x000002F5
	adds r5, r5, r1
	movs r2, #0
	ldrsb r2, [r5, r2]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r1, r1, #5
	ldr r2, _0804C93C @ =gUnknown_084F5ACC
	adds r1, r1, r2
	str r1, [r4]
	ldr r1, _0804C940 @ =0x06012C20
	str r1, [r4, #4]
	ldr r1, _0804C944 @ =0x80000130
	str r1, [r4, #8]
	ldr r1, [r4, #8]
	movs r2, #0
	mov ip, r6
	ldr r1, _0804C948 @ =gUnknown_084ED0CC
	mov r8, r1
	ldr r1, _0804C94C @ =gUnknown_08449D8C
	mov sb, r1
	ldr r1, _0804C950 @ =gUnknown_086AD456
	mov sl, r1
	lsls r0, r0, #8
	ldr r1, _0804C954 @ =gUnknown_083C806C
	adds r3, r0, r1
	movs r7, #0xba
	lsls r7, r7, #1
	ldr r6, _0804C958 @ =0x06010000
	ldr r5, _0804C95C @ =0x80000080
_0804C8AE:
	str r3, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r1, r6
	str r1, [r4, #4]
	str r5, [r4, #8]
	ldr r1, [r4, #8]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0804C8AE
	mov r2, ip
	ldr r0, [r2]
	ldr r1, _0804C960 @ =0x000002F1
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xf
	ldr r2, _0804C918 @ =0x040000D4
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, r8
	str r0, [r2]
	ldr r0, _0804C964 @ =0x06013180
	str r0, [r2, #4]
	ldr r0, _0804C968 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, ip
	ldr r1, [r2]
	ldr r2, _0804C96C @ =0x000002DA
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0804C974
	ldr r0, _0804C970 @ =0x00000746
	adds r1, r1, r0
	movs r0, #0
	b _0804C97A
	.align 2, 0
_0804C90C: .4byte gUnknown_086AD2EE
_0804C910: .4byte gCurrentPinballGame
_0804C914: .4byte 0x000001ED
_0804C918: .4byte 0x040000D4
_0804C91C: .4byte gUnknown_084FB68C
_0804C920: .4byte 0x060122A0
_0804C924: .4byte 0x80000240
_0804C928: .4byte gMain
_0804C92C: .4byte gUnknown_083C3C2C
_0804C930: .4byte 0x06012720
_0804C934: .4byte 0x80000180
_0804C938: .4byte 0x000002F5
_0804C93C: .4byte gUnknown_084F5ACC
_0804C940: .4byte 0x06012C20
_0804C944: .4byte 0x80000130
_0804C948: .4byte gUnknown_084ED0CC
_0804C94C: .4byte gUnknown_08449D8C
_0804C950: .4byte gUnknown_086AD456
_0804C954: .4byte gUnknown_083C806C
_0804C958: .4byte 0x06010000
_0804C95C: .4byte 0x80000080
_0804C960: .4byte 0x000002F1
_0804C964: .4byte 0x06013180
_0804C968: .4byte 0x800000C0
_0804C96C: .4byte 0x000002DA
_0804C970: .4byte 0x00000746
_0804C974:
	ldr r2, _0804C9F8 @ =0x00000746
	adds r1, r1, r2
	movs r0, #1
_0804C97A:
	strb r0, [r1]
	ldr r4, _0804C9FC @ =0x040000D4
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0804C9F8 @ =0x00000746
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, sb
	str r0, [r4]
	ldr r0, _0804CA00 @ =0x06013300
	str r0, [r4, #4]
	ldr r0, _0804CA04 @ =0x80000140
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, ip
	ldr r5, [r0]
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	ldr r2, _0804CA08 @ =0x000001A5
	adds r1, r5, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804CA0C @ =gUnknown_084F6B0C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0804CA10 @ =0x06013D00
	str r0, [r4, #4]
	ldr r0, _0804CA14 @ =0x80000280
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C9F8: .4byte 0x00000746
_0804C9FC: .4byte 0x040000D4
_0804CA00: .4byte 0x06013300
_0804CA04: .4byte 0x80000140
_0804CA08: .4byte 0x000001A5
_0804CA0C: .4byte gUnknown_084F6B0C
_0804CA10: .4byte 0x06013D00
_0804CA14: .4byte 0x80000280

	thumb_func_start sub_4CA18
sub_4CA18: @ 0x0804CA18
	ldr r1, _0804CA38 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0804CA3C @ =0x00000346
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #6
	bhi _0804CACE
	lsls r0, r0, #2
	ldr r1, _0804CA40 @ =_0804CA44
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804CA38: .4byte gCurrentPinballGame
_0804CA3C: .4byte 0x00000346
_0804CA40: .4byte _0804CA44
_0804CA44: @ jump table
	.4byte _0804CA60 @ case 0
	.4byte _0804CA60 @ case 1
	.4byte _0804CA60 @ case 2
	.4byte _0804CA78 @ case 3
	.4byte _0804CA78 @ case 4
	.4byte _0804CAA0 @ case 5
	.4byte _0804CACE @ case 6
_0804CA60:
	ldr r0, [r2]
	ldr r3, _0804CA70 @ =0x00000345
	adds r0, r0, r3
	ldr r2, _0804CA74 @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0804CAB8
	.align 2, 0
_0804CA70: .4byte 0x00000345
_0804CA74: .4byte 0x040000D4
_0804CA78:
	ldr r1, _0804CA90 @ =0x040000D4
	ldr r0, _0804CA94 @ =gUnknown_08490A4C
	movs r2, #0xff
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0804CA98 @ =0x0600D900
	str r0, [r1, #4]
	ldr r0, _0804CA9C @ =0x80000220
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0804CACE
	.align 2, 0
_0804CA90: .4byte 0x040000D4
_0804CA94: .4byte gUnknown_08490A4C
_0804CA98: .4byte 0x0600D900
_0804CA9C: .4byte 0x80000220
_0804CAA0:
	ldr r1, _0804CAD0 @ =gUnknown_086AE5A0
	ldr r0, [r2]
	ldr r3, _0804CAD4 @ =0x00000345
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, _0804CAD8 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
_0804CAB8:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _0804CADC @ =gUnknown_08490A4C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804CAE0 @ =0x0600D900
	str r0, [r2, #4]
	ldr r0, _0804CAE4 @ =0x80000220
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804CACE:
	bx lr
	.align 2, 0
_0804CAD0: .4byte gUnknown_086AE5A0
_0804CAD4: .4byte 0x00000345
_0804CAD8: .4byte 0x040000D4
_0804CADC: .4byte gUnknown_08490A4C
_0804CAE0: .4byte 0x0600D900
_0804CAE4: .4byte 0x80000220

	thumb_func_start sub_4CAE8
sub_4CAE8: @ 0x0804CAE8
	ldr r1, _0804CAFC @ =0x040000D4
	ldr r0, _0804CB00 @ =gUnknown_08138834
	str r0, [r1]
	ldr r0, _0804CB04 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CB08 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0804CAFC: .4byte 0x040000D4
_0804CB00: .4byte gUnknown_08138834
_0804CB04: .4byte 0x06015800
_0804CB08: .4byte 0x80001000

	thumb_func_start sub_4CB0C
sub_4CB0C: @ 0x0804CB0C
	ldr r1, _0804CB20 @ =0x040000D4
	ldr r0, _0804CB24 @ =gUnknown_0813A854
	str r0, [r1]
	ldr r0, _0804CB28 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CB2C @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0804CB20: .4byte 0x040000D4
_0804CB24: .4byte gUnknown_0813A854
_0804CB28: .4byte 0x06015800
_0804CB2C: .4byte 0x80001000

	thumb_func_start sub_4CB30
sub_4CB30: @ 0x0804CB30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r5, _0804CB90 @ =0x040000D4
	ldr r0, _0804CB94 @ =gUnknown_0813C874
	str r0, [r5]
	ldr r0, _0804CB98 @ =0x06015800
	str r0, [r5, #4]
	ldr r0, _0804CB9C @ =0x80001000
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _0804CBA0 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, _0804CBA4 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0804CBA8 @ =0x00000749
	adds r0, r0, r1
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
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, _0804CBAC @ =0x06010CA0
	str r0, [r5, #4]
	ldr r0, _0804CBB0 @ =0x80000180
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CB90: .4byte 0x040000D4
_0804CB94: .4byte gUnknown_0813C874
_0804CB98: .4byte 0x06015800
_0804CB9C: .4byte 0x80001000
_0804CBA0: .4byte gMonPortraitGroupGfx
_0804CBA4: .4byte gCurrentPinballGame
_0804CBA8: .4byte 0x00000749
_0804CBAC: .4byte 0x06010CA0
_0804CBB0: .4byte 0x80000180

	thumb_func_start sub_4CBB4
sub_4CBB4: @ 0x0804CBB4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _0804CBD0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, #0
	cmp r1, #1
	bgt _0804CBDC
	ldr r1, _0804CBD4 @ =0x040000D4
	ldr r0, _0804CBD8 @ =gUnknown_0849F1CC
	b _0804CBE0
	.align 2, 0
_0804CBD0: .4byte gCurrentPinballGame
_0804CBD4: .4byte 0x040000D4
_0804CBD8: .4byte gUnknown_0849F1CC
_0804CBDC:
	ldr r1, _0804CC38 @ =0x040000D4
	ldr r0, _0804CC3C @ =gUnknown_0813E894
_0804CBE0:
	str r0, [r1]
	ldr r0, _0804CC40 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CC44 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _0804CC38 @ =0x040000D4
	ldr r0, _0804CC48 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, [r2]
	ldr r1, _0804CC4C @ =0x00000749
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r6]
	ldr r0, _0804CC50 @ =0x06010CA0
	str r0, [r6, #4]
	ldr r0, _0804CC54 @ =0x80000180
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CC38: .4byte 0x040000D4
_0804CC3C: .4byte gUnknown_0813E894
_0804CC40: .4byte 0x06015800
_0804CC44: .4byte 0x80001000
_0804CC48: .4byte gMonPortraitGroupGfx
_0804CC4C: .4byte 0x00000749
_0804CC50: .4byte 0x06010CA0
_0804CC54: .4byte 0x80000180

	thumb_func_start sub_4CC58
sub_4CC58: @ 0x0804CC58
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r1, _0804CC7C @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #0
	bne _0804CC90
	ldr r1, _0804CC80 @ =0x040000D4
	ldr r0, _0804CC84 @ =gUnknown_083C5A2C
	str r0, [r1]
	ldr r0, _0804CC88 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CC8C @ =0x80001400
	b _0804CCC0
	.align 2, 0
_0804CC7C: .4byte gCurrentPinballGame
_0804CC80: .4byte 0x040000D4
_0804CC84: .4byte gUnknown_083C5A2C
_0804CC88: .4byte 0x06015800
_0804CC8C: .4byte 0x80001400
_0804CC90:
	cmp r0, #1
	bne _0804CCB4
	ldr r1, _0804CCA4 @ =0x040000D4
	ldr r0, _0804CCA8 @ =gUnknown_084A856C
	str r0, [r1]
	ldr r0, _0804CCAC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CCB0 @ =0x80000E00
	b _0804CCC0
	.align 2, 0
_0804CCA4: .4byte 0x040000D4
_0804CCA8: .4byte gUnknown_084A856C
_0804CCAC: .4byte 0x06015800
_0804CCB0: .4byte 0x80000E00
_0804CCB4:
	ldr r1, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD38 @ =gUnknown_081408B4
	str r0, [r1]
	ldr r0, _0804CD3C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CD40 @ =0x80001000
_0804CCC0:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0804CCE8
	ldr r1, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD44 @ =gUnknown_084AA18C
	str r0, [r1]
	ldr r0, _0804CD48 @ =0x06011620
	str r0, [r1, #4]
	ldr r0, _0804CD4C @ =0x80000430
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804CCE8:
	ldr r6, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD50 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, [r2]
	ldr r1, _0804CD54 @ =0x00000749
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r6]
	ldr r0, _0804CD58 @ =0x06010CA0
	str r0, [r6, #4]
	ldr r0, _0804CD5C @ =0x80000180
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CD34: .4byte 0x040000D4
_0804CD38: .4byte gUnknown_081408B4
_0804CD3C: .4byte 0x06015800
_0804CD40: .4byte 0x80001000
_0804CD44: .4byte gUnknown_084AA18C
_0804CD48: .4byte 0x06011620
_0804CD4C: .4byte 0x80000430
_0804CD50: .4byte gMonPortraitGroupGfx
_0804CD54: .4byte 0x00000749
_0804CD58: .4byte 0x06010CA0
_0804CD5C: .4byte 0x80000180

	thumb_func_start sub_4CD60
sub_4CD60: @ 0x0804CD60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r3, _0804CE5C @ =gUnknown_03006400
	ldr r6, _0804CE60 @ =gMain
	movs r0, #0x80
	lsls r0, r0, #4
	adds r0, r0, r3
	mov r8, r0
	ldr r1, _0804CE64 @ =gUnknown_084B77EC
	mov sb, r1
	ldr r0, _0804CE68 @ =0xFFFFF800
	adds r0, r0, r3
	mov ip, r0
	movs r7, #0x80
	lsls r7, r7, #3
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r4, _0804CE6C @ =0x000007FF
_0804CD8A:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r7
	lsls r0, r0, #1
	add r0, ip
	strh r5, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r4
	ble _0804CD8A
	ldr r1, _0804CE70 @ =0x040000D4
	str r3, [r1]
	ldr r0, _0804CE74 @ =0x06001000
	str r0, [r1, #4]
	ldr r0, _0804CE78 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r6, #0x38]
	ldr r0, _0804CE7C @ =0x00001C42
	strh r0, [r6, #0x38]
	ldrh r0, [r6, #0x3a]
	ldr r0, _0804CE80 @ =0x00000C04
	strh r0, [r6, #0x3a]
	movs r2, #0
	ldr r1, _0804CE68 @ =0xFFFFF800
	adds r4, r3, r1
	ldr r3, _0804CE84 @ =0x0000013F
_0804CDC4:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	cmp r2, #0
	bge _0804CDD0
	adds r0, #0x1f
_0804CDD0:
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _0804CDF0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r2, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0x90
	lsls r1, r1, #8
	strh r1, [r0]
_0804CDF0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	ble _0804CDC4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, _0804CE88 @ =0x000002EE
	adds r1, r6, r0
	movs r0, #0x7e
	strh r0, [r1]
	ldr r1, _0804CE70 @ =0x040000D4
	mov r0, r8
	str r0, [r1]
	ldr r0, _0804CE8C @ =0x06001140
	str r0, [r1, #4]
	ldr r0, _0804CE90 @ =0x80000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	ldr r5, _0804CE94 @ =0xFFFFF000
	add r5, r8
	ldr r4, _0804CE98 @ =0x000001FF
	ldr r3, _0804CE6C @ =0x000007FF
_0804CE28:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r3
	ble _0804CE28
	ldr r1, _0804CE70 @ =0x040000D4
	mov r0, sb
	str r0, [r1]
	ldr r0, _0804CE9C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CEA0 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804CE5C: .4byte gUnknown_03006400
_0804CE60: .4byte gMain
_0804CE64: .4byte gUnknown_084B77EC
_0804CE68: .4byte 0xFFFFF800
_0804CE6C: .4byte 0x000007FF
_0804CE70: .4byte 0x040000D4
_0804CE74: .4byte 0x06001000
_0804CE78: .4byte 0x80000800
_0804CE7C: .4byte 0x00001C42
_0804CE80: .4byte 0x00000C04
_0804CE84: .4byte 0x0000013F
_0804CE88: .4byte 0x000002EE
_0804CE8C: .4byte 0x06001140
_0804CE90: .4byte 0x80000140
_0804CE94: .4byte 0xFFFFF000
_0804CE98: .4byte 0x000001FF
_0804CE9C: .4byte 0x06015800
_0804CEA0: .4byte 0x80000400

	thumb_func_start nullsub_18
nullsub_18: @ 0x0804CEA4
	bx lr

    .align 2, 0
