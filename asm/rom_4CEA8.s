#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

    .align 2, 0

	thumb_func_start sub_4CEA8
sub_4CEA8: @ 0x0804CEA8
	push {lr}
	bl sub_4CEB4
	pop {r0}
	bx r0


	thumb_func_start sub_4CEB4
sub_4CEB4: @ 0x0804CEB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	bl sub_4D3D0
	ldr r5, _0804CF34 @ =gCurrentPinballGame
	ldr r2, [r5]
	ldr r1, _0804CF38 @ =0x000005F6
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	ldr r1, [r2, #0x3c]
	muls r1, r0, r1
	ldr r0, [r2, #0x40]
	adds r3, r0, r1
	str r3, [r2, #0x40]
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	beq _0804CF56
	ldrb r0, [r2, #5]
	ldr r4, _0804CF3C @ =gMain
	cmp r0, #0
	bne _0804CEF6
	ldrh r1, [r4, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804CF08
_0804CEF6:
	ldr r0, [r2, #0x44]
	adds r0, r0, r3
	str r0, [r2, #0x44]
	movs r0, #0
	str r0, [r2, #0x40]
	strb r0, [r2, #0x1c]
	ldr r1, [r5]
	ldr r0, _0804CF40 @ =0x00009C40
	str r0, [r1, #0x38]
_0804CF08:
	ldr r5, [r4, #0x4c]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne _0804CF5E
	ldr r1, _0804CF34 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r4, [r2, #0x40]
	cmp r4, #0
	beq _0804CF5E
	ldr r3, [r2, #0x38]
	cmp r4, r3
	bhi _0804CF44
	ldr r0, [r2, #0x44]
	adds r0, r0, r4
	str r0, [r2, #0x44]
	str r5, [r2, #0x40]
	strb r5, [r2, #0x1c]
	ldr r1, [r1]
	ldr r0, _0804CF40 @ =0x00009C40
	str r0, [r1, #0x38]
	b _0804CF5E
	.align 2, 0
_0804CF34: .4byte gCurrentPinballGame
_0804CF38: .4byte 0x000005F6
_0804CF3C: .4byte gMain
_0804CF40: .4byte 0x00009C40
_0804CF44:
	ldr r0, [r2, #0x44]
	adds r0, r0, r3
	str r0, [r2, #0x44]
	subs r0, r4, r3
	str r0, [r2, #0x40]
	movs r0, SE_UNKNOWN_0x91
	bl m4aSongNumStart
	b _0804CF5E
_0804CF56:
	ldr r0, [r2, #0x44]
	adds r0, r0, r3
	str r0, [r2, #0x44]
	str r1, [r2, #0x40]
_0804CF5E:
	ldr r4, _0804CF84 @ =gCurrentPinballGame
	ldr r6, [r4]
	ldr r7, [r6, #0x44]
	ldr r1, _0804CF88 @ =0x05F5E100
	adds r0, r7, #0
	bl __udivsi3
	mov sb, r4
	cmp r0, #0
	beq _0804CF9C
	ldr r1, [r6, #0x48]
	ldr r0, _0804CF8C @ =0x0000270E
	cmp r1, r0
	bhi _0804CF94
	adds r0, r1, #1
	str r0, [r6, #0x48]
	ldr r2, _0804CF90 @ =0xFA0A1F00
	adds r0, r7, r2
	b _0804CF9A
	.align 2, 0
_0804CF84: .4byte gCurrentPinballGame
_0804CF88: .4byte 0x05F5E100
_0804CF8C: .4byte 0x0000270E
_0804CF90: .4byte 0xFA0A1F00
_0804CF94:
	ldr r0, _0804D2EC @ =0x0000270F
	str r0, [r6, #0x48]
	ldr r0, _0804D2F0 @ =0x05F5E0FF
_0804CF9A:
	str r0, [r6, #0x44]
_0804CF9C:
	mov r7, sb
	ldr r5, [r7]
	movs r0, #0
	str r0, [r5, #0x3c]
	ldr r7, [r5, #0x48]
	mov r4, sp
	ldr r0, _0804D2F4 @ =0x00002710
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	bl __umodsi3
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r1, r6, #0
	bl __udivsi3
	adds r0, #5
	strh r0, [r4]
	mov r4, sp
	adds r0, r7, #0
	adds r1, r6, #0
	bl __umodsi3
	movs r1, #0x64
	bl __udivsi3
	adds r0, #5
	strh r0, [r4, #2]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0x64
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	adds r0, #0x13
	strh r0, [r4, #4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __umodsi3
	adds r0, #5
	strh r0, [r4, #6]
	ldr r7, [r5, #0x44]
	mov r5, sp
	ldr r4, _0804D2F8 @ =0x00989680
	adds r0, r7, #0
	adds r1, r4, #0
	bl __udivsi3
	adds r0, #5
	strh r0, [r5, #8]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __umodsi3
	ldr r4, _0804D2FC @ =0x000F4240
	adds r1, r4, #0
	bl __udivsi3
	adds r0, #0x13
	strh r0, [r5, #0xa]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __umodsi3
	ldr r4, _0804D300 @ =0x000186A0
	adds r1, r4, #0
	bl __udivsi3
	adds r0, #5
	strh r0, [r5, #0xc]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __umodsi3
	mov r1, r8
	bl __udivsi3
	adds r0, #5
	strh r0, [r5, #0xe]
	mov r4, sp
	adds r0, r7, #0
	mov r1, r8
	bl __umodsi3
	adds r1, r6, #0
	bl __udivsi3
	adds r0, #0x13
	strh r0, [r4, #0x10]
	mov r4, sp
	adds r0, r7, #0
	adds r1, r6, #0
	bl __umodsi3
	movs r1, #0x64
	bl __udivsi3
	adds r0, #5
	strh r0, [r4, #0x12]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0x64
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	adds r0, #5
	strh r0, [r4, #0x14]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __umodsi3
	adds r0, #5
	strh r0, [r4, #0x16]
	movs r3, #0
	ldr r1, _0804D304 @ =gUnknown_03005C00
	mov sl, r1
	movs r4, #0x1e
_0804D09C:
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #1
	mov r5, sp
	adds r1, r5, r0
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #5
	beq _0804D0B2
	cmp r0, #0x13
	bne _0804D0C0
_0804D0B2:
	strh r4, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0804D09C
_0804D0C0:
	lsls r1, r3, #0x10
	adds r3, r1, #0
	asrs r0, r3, #0x10
	cmp r0, #0xb
	bgt _0804D10A
	ldr r5, _0804D304 @ =gUnknown_03005C00
	asrs r6, r1, #0x10
_0804D0CE:
	asrs r3, r3, #0x10
	subs r1, r3, r6
	ldr r0, _0804D308 @ =0x000007C1
	adds r2, r1, r0
	lsls r2, r2, #1
	adds r2, r2, r5
	lsls r0, r3, #1
	mov r7, sp
	adds r4, r7, r0
	movs r7, #0
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	ldr r7, _0804D30C @ =0xFFFFC160
	adds r0, r0, r7
	strh r0, [r2]
	ldr r0, _0804D310 @ =0x000007E1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r7, #1
	adds r0, r0, r7
	strh r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0xb
	ble _0804D0CE
_0804D10A:
	mov r1, sb
	ldr r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r2, r0, r3
	ldrh r0, [r2]
	ldr r1, _0804D314 @ =0x000003E7
	cmp r0, r1
	bls _0804D11E
	strh r1, [r2]
_0804D11E:
	mov r5, sp
	mov r2, sb
	ldr r4, [r2]
	adds r4, r4, r3
	ldrh r0, [r4]
	movs r1, #0x64
	bl __udivsi3
	strh r0, [r5, #4]
	mov r5, sp
	ldrh r0, [r4]
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __udivsi3
	strh r0, [r5, #2]
	mov r5, sp
	ldrh r0, [r4]
	movs r1, #0xa
	bl __umodsi3
	strh r0, [r5]
	mov r6, sl
	ldr r5, _0804D318 @ =0x00000FA2
	adds r1, r6, r5
	ldr r0, _0804D31C @ =0x0000C17E
	strh r0, [r1]
	ldr r7, _0804D320 @ =0x00000FE2
	adds r1, r6, r7
	adds r0, #1
	strh r0, [r1]
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r0, #5
	lsls r0, r0, #1
	ldr r2, _0804D30C @ =0xFFFFC160
	adds r7, r2, #0
	adds r0, r0, r7
	adds r5, #2
	adds r1, r6, r5
	strh r0, [r1]
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r0, #5
	lsls r0, r0, #1
	adds r2, #1
	mov r8, r2
	add r0, r8
	adds r5, #0x40
	adds r1, r6, r5
	strh r0, [r1]
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r7
	ldr r2, _0804D324 @ =0x00000FA6
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #2
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	add r0, r8
	adds r2, #0x40
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r7
	subs r2, #0x3e
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	add r0, r8
	adds r2, #0x40
	adds r1, r6, r2
	strh r0, [r1]
	mov r5, sb
	ldr r0, [r5]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _0804D1EC
	movs r0, #0x63
	strb r0, [r1]
_0804D1EC:
	mov r5, sp
	mov r0, sb
	ldr r4, [r0]
	adds r4, r4, r2
	ldrb r0, [r4]
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #2]
	mov r5, sp
	ldrb r0, [r4]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5]
	ldr r2, _0804D328 @ =0x00000FAC
	adds r1, r6, r2
	ldr r0, _0804D32C @ =0x0000C19C
	strh r0, [r1]
	ldr r5, _0804D330 @ =0x00000FEC
	adds r1, r6, r5
	adds r0, #1
	strh r0, [r1]
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #2
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	add r0, r8
	adds r2, #0x40
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r7
	subs r2, #0x3e
	adds r1, r6, r2
	strh r0, [r1]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #5
	lsls r0, r0, #1
	add r0, r8
	adds r2, #0x40
	adds r1, r6, r2
	strh r0, [r1]
	mov r5, sb
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x30
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #9
	ble _0804D27E
	movs r0, #9
	strb r0, [r1]
_0804D27E:
	ldr r0, _0804D334 @ =0x00000FB4
	adds r1, r6, r0
	ldr r0, _0804D338 @ =0x0000C180
	strh r0, [r1]
	ldr r2, _0804D33C @ =0x00000FF4
	adds r1, r6, r2
	adds r0, #1
	strh r0, [r1]
	mov r5, sb
	ldr r0, [r5]
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r7
	ldr r7, _0804D340 @ =0x00000FB6
	adds r1, r6, r7
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #5
	lsls r0, r0, #1
	add r0, r8
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, [r5]
	movs r5, #0xe5
	lsls r5, r5, #1
	adds r0, r1, r5
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0xd
	bne _0804D384
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0804D350
	ldr r5, _0804D344 @ =0x00000FBA
	adds r1, r6, r5
	ldr r0, _0804D348 @ =0x0000C19A
	strh r0, [r1]
	ldr r7, _0804D34C @ =0x00000FFA
	adds r1, r6, r7
	b _0804D35C
	.align 2, 0
_0804D2EC: .4byte 0x0000270F
_0804D2F0: .4byte 0x05F5E0FF
_0804D2F4: .4byte 0x00002710
_0804D2F8: .4byte 0x00989680
_0804D2FC: .4byte 0x000F4240
_0804D300: .4byte 0x000186A0
_0804D304: .4byte gUnknown_03005C00
_0804D308: .4byte 0x000007C1
_0804D30C: .4byte 0xFFFFC160
_0804D310: .4byte 0x000007E1
_0804D314: .4byte 0x000003E7
_0804D318: .4byte 0x00000FA2
_0804D31C: .4byte 0x0000C17E
_0804D320: .4byte 0x00000FE2
_0804D324: .4byte 0x00000FA6
_0804D328: .4byte 0x00000FAC
_0804D32C: .4byte 0x0000C19C
_0804D330: .4byte 0x00000FEC
_0804D334: .4byte 0x00000FB4
_0804D338: .4byte 0x0000C180
_0804D33C: .4byte 0x00000FF4
_0804D340: .4byte 0x00000FB6
_0804D344: .4byte 0x00000FBA
_0804D348: .4byte 0x0000C19A
_0804D34C: .4byte 0x00000FFA
_0804D350:
	ldr r0, _0804D378 @ =0x00000FBA
	adds r1, r6, r0
	ldr r0, _0804D37C @ =0x0000C182
	strh r0, [r1]
	ldr r2, _0804D380 @ =0x00000FFA
	adds r1, r6, r2
_0804D35C:
	adds r0, #1
	strh r0, [r1]
	mov r5, sb
	ldr r0, [r5]
	movs r7, #0xee
	lsls r7, r7, #1
	adds r4, r0, r7
	ldrh r0, [r4]
	cmp r0, #0
	beq _0804D394
	subs r0, #1
	strh r0, [r4]
	b _0804D394
	.align 2, 0
_0804D378: .4byte 0x00000FBA
_0804D37C: .4byte 0x0000C182
_0804D380: .4byte 0x00000FFA
_0804D384:
	ldr r1, _0804D3B4 @ =0x00000FBA
	add r1, sl
	ldr r0, _0804D3B8 @ =0x0000C19E
	strh r0, [r1]
	ldr r1, _0804D3BC @ =0x00000FFA
	add r1, sl
	adds r0, #1
	strh r0, [r1]
_0804D394:
	ldr r1, _0804D3C0 @ =0x040000D4
	ldr r0, _0804D3C4 @ =gUnknown_03006B80
	str r0, [r1]
	ldr r0, _0804D3C8 @ =0x06002F80
	str r0, [r1, #4]
	ldr r0, _0804D3CC @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D3B4: .4byte 0x00000FBA
_0804D3B8: .4byte 0x0000C19E
_0804D3BC: .4byte 0x00000FFA
_0804D3C0: .4byte 0x040000D4
_0804D3C4: .4byte gUnknown_03006B80
_0804D3C8: .4byte 0x06002F80
_0804D3CC: .4byte 0x80000040

	thumb_func_start sub_4D3D0
sub_4D3D0: @ 0x0804D3D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r1, _0804D4C8 @ =gCurrentPinballGame
	ldr r2, [r1]
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #0
	bne _0804D3F2
	b _0804D628
_0804D3F2:
	ldr r5, _0804D4CC @ =0x00000296
	adds r1, r2, r5
	ldrh r2, [r1]
	cmp r2, #0
	bne _0804D3FE
	b _0804D628
_0804D3FE:
	cmp r0, #2
	bne _0804D40E
	ldr r0, _0804D4D0 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _0804D40E
	subs r0, r2, #1
	strh r0, [r1]
_0804D40E:
	mov r5, sp
	mov r0, sb
	ldr r6, [r0]
	ldr r1, _0804D4CC @ =0x00000296
	adds r7, r6, r1
	ldrh r0, [r7]
	movs r4, #0xe1
	lsls r4, r4, #4
	adds r1, r4, #0
	bl __udivsi3
	strh r0, [r5]
	ldrh r0, [r7]
	adds r1, r4, #0
	bl __umodsi3
	adds r4, r0, #0
	mov r1, sp
	movs r0, #0xa
	strh r0, [r1, #2]
	mov r8, sp
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r5, #0x96
	lsls r5, r5, #2
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	mov r2, r8
	strh r0, [r2, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	bl __modsi3
	mov r4, sp
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	bl __divsi3
	strh r0, [r4, #6]
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r6, r6, r3
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bne _0804D4F4
	movs r1, #0
	ldr r6, _0804D4D4 @ =gUnknown_03005EC0
	ldr r5, _0804D4D8 @ =0xFFFFFD40
	adds r3, r6, r5
	ldr r5, _0804D4DC @ =0x00000179
	ldr r2, _0804D4E0 @ =0x000001FF
	ldr r4, _0804D4E4 @ =0x00000199
_0804D47E:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r5
	lsls r1, r1, #1
	adds r1, r1, r3
	strh r2, [r1]
	adds r1, r0, r4
	lsls r1, r1, #1
	adds r1, r1, r3
	strh r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804D47E
	ldr r1, _0804D4E8 @ =0x040000D4
	str r6, [r1]
	ldr r0, _0804D4EC @ =0x060022C0
	str r0, [r1, #4]
	ldr r0, _0804D4F0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, sb
	ldr r0, [r1]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	mov r3, sb
	ldr r0, [r3]
	ldr r5, _0804D4CC @ =0x00000296
	adds r0, r0, r5
	strh r1, [r0]
	b _0804D556
	.align 2, 0
_0804D4C8: .4byte gCurrentPinballGame
_0804D4CC: .4byte 0x00000296
_0804D4D0: .4byte gMain
_0804D4D4: .4byte gUnknown_03005EC0
_0804D4D8: .4byte 0xFFFFFD40
_0804D4DC: .4byte 0x00000179
_0804D4E0: .4byte 0x000001FF
_0804D4E4: .4byte 0x00000199
_0804D4E8: .4byte 0x040000D4
_0804D4EC: .4byte 0x060022C0
_0804D4F0: .4byte 0x80000040
_0804D4F4:
	ldrh r0, [r7]
	cmp r0, #0
	bne _0804D500
	bl sub_4D648
	b _0804D542
_0804D500:
	movs r1, #0
	ldr r4, _0804D578 @ =gUnknown_03005C00
_0804D504:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	ldr r0, _0804D57C @ =0x00000179
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	lsls r0, r2, #1
	mov r5, sp
	adds r3, r5, r0
	movs r5, #0
	ldrsh r0, [r3, r5]
	lsls r0, r0, #1
	ldr r5, _0804D580 @ =0xFFFFC140
	adds r0, r0, r5
	strh r0, [r1]
	ldr r0, _0804D584 @ =0x00000199
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r5, #0
	ldrsh r0, [r3, r5]
	lsls r0, r0, #1
	ldr r3, _0804D588 @ =0xFFFFC141
	adds r0, r0, r3
	strh r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _0804D504
_0804D542:
	ldr r1, _0804D58C @ =0x040000D4
	ldr r0, _0804D590 @ =gUnknown_03005EC0
	str r0, [r1]
	ldr r0, _0804D594 @ =0x060022C0
	str r0, [r1, #4]
	ldr r0, _0804D598 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r5, _0804D59C @ =gCurrentPinballGame
	mov sb, r5
_0804D556:
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0804D5A0 @ =0x00000296
	adds r3, r0, r2
	ldrh r2, [r3]
	adds r1, r2, #0
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r1, r0
	bhi _0804D5E8
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0804D5A8
	ldr r1, _0804D58C @ =0x040000D4
	ldr r0, _0804D5A4 @ =gUnknown_086B0884
	b _0804D5AC
	.align 2, 0
_0804D578: .4byte gUnknown_03005C00
_0804D57C: .4byte 0x00000179
_0804D580: .4byte 0xFFFFC140
_0804D584: .4byte 0x00000199
_0804D588: .4byte 0xFFFFC141
_0804D58C: .4byte 0x040000D4
_0804D590: .4byte gUnknown_03005EC0
_0804D594: .4byte 0x060022C0
_0804D598: .4byte 0x80000040
_0804D59C: .4byte gCurrentPinballGame
_0804D5A0: .4byte 0x00000296
_0804D5A4: .4byte gUnknown_086B0884
_0804D5A8:
	ldr r1, _0804D5D4 @ =0x040000D4
	ldr r0, _0804D5D8 @ =gUnknown_081C0064
_0804D5AC:
	str r0, [r1]
	ldr r0, _0804D5DC @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0804D5E0 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, sb
	ldr r0, [r3]
	ldr r5, _0804D5E4 @ =0x00000296
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r1, r0
	bne _0804D628
	movs r0, MUS_HURRY_UP
	bl m4aSongNumStart
	b _0804D628
	.align 2, 0
_0804D5D4: .4byte 0x040000D4
_0804D5D8: .4byte gUnknown_081C0064
_0804D5DC: .4byte 0x05000180
_0804D5E0: .4byte 0x80000010
_0804D5E4: .4byte 0x00000296
_0804D5E8:
	movs r0, #0xe1
	lsls r0, r0, #3
	cmp r1, r0
	bhi _0804D628
	ldrh r0, [r3]
	movs r1, #0x16
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xb
	bl __udivsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804D618
	ldr r1, _0804D610 @ =0x040000D4
	ldr r0, _0804D614 @ =gUnknown_086B08A4
	b _0804D61C
	.align 2, 0
_0804D610: .4byte 0x040000D4
_0804D614: .4byte gUnknown_086B08A4
_0804D618:
	ldr r1, _0804D638 @ =0x040000D4
	ldr r0, _0804D63C @ =gUnknown_081C0064
_0804D61C:
	str r0, [r1]
	ldr r0, _0804D640 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _0804D644 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804D628:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D638: .4byte 0x040000D4
_0804D63C: .4byte gUnknown_081C0064
_0804D640: .4byte 0x05000180
_0804D644: .4byte 0x80000010

	thumb_func_start sub_4D648
sub_4D648: @ 0x0804D648
	push {r4, r5, r6, lr}
	ldr r2, _0804D6A0 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0804D6A4 @ =0x00000296
	adds r0, r0, r2
	strh r1, [r0]
	ldr r6, _0804D6A8 @ =gUnknown_03005EC0
	ldr r0, _0804D6AC @ =0xFFFFFD40
	adds r3, r6, r0
	ldr r5, _0804D6B0 @ =0x00000179
	subs r2, #0x97
	ldr r4, _0804D6B4 @ =0x00000199
_0804D66C:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, r5
	lsls r1, r1, #1
	adds r1, r1, r3
	strh r2, [r1]
	adds r1, r0, r4
	lsls r1, r1, #1
	adds r1, r1, r3
	strh r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0804D66C
	ldr r1, _0804D6B8 @ =0x040000D4
	str r6, [r1]
	ldr r0, _0804D6BC @ =0x060022C0
	str r0, [r1, #4]
	ldr r0, _0804D6C0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D6A0: .4byte gCurrentPinballGame
_0804D6A4: .4byte 0x00000296
_0804D6A8: .4byte gUnknown_03005EC0
_0804D6AC: .4byte 0xFFFFFD40
_0804D6B0: .4byte 0x00000179
_0804D6B4: .4byte 0x00000199
_0804D6B8: .4byte 0x040000D4
_0804D6BC: .4byte 0x060022C0
_0804D6C0: .4byte 0x80000040

	thumb_func_start sub_4D6C4
sub_4D6C4: @ 0x0804D6C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov ip, r0
	ldr r0, _0804D7B0 @ =gMain
	ldrb r2, [r0, #4]
	movs r3, #0
	adds r7, r0, #0
	cmp r2, #0
	beq _0804D6E6
	ldr r3, _0804D7B4 @ =0x0000FFE8
	cmp r2, #1
	beq _0804D6E6
	movs r3, #0
	movs r1, #8
	mov ip, r1
_0804D6E6:
	ldrb r0, [r7, #4]
	cmp r0, #1
	bls _0804D6EE
	b _0804D810
_0804D6EE:
	ldr r6, _0804D7B8 @ =gCurrentPinballGame
	ldr r1, [r6]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	subs r0, #0xf4
	ldr r4, _0804D7BC @ =0x000005FC
	adds r2, r1, r4
	movs r5, #0
	movs r3, #0
	strh r0, [r2]
	ldr r2, _0804D7C0 @ =0x000005FE
	adds r0, r1, r2
	strh r3, [r0]
	ldr r0, _0804D7C4 @ =0x000005FB
	adds r1, r1, r0
	strb r5, [r1]
	ldr r6, [r6]
	ldr r0, _0804D7C8 @ =gUnknown_02031520
	ldrh r1, [r0, #0x14]
	adds r3, r6, #0
	adds r3, #0x4c
	strh r1, [r3]
	ldrh r1, [r0, #0x16]
	adds r5, r6, #0
	adds r5, #0x4e
	strh r1, [r5]
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	str r0, [r6, #0x54]
	ldrh r1, [r3]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r4, r6, r4
	ldrh r0, [r4]
	ldrh r2, [r5]
	adds r0, r0, r2
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r1, [r3]
	mov r0, ip
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r1, r2, r1
	mov ip, r1
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r1, ip
	strh r1, [r0]
	ldrh r0, [r4]
	ldrh r1, [r5]
	adds r0, r0, r1
	ldr r1, _0804D7CC @ =0x000002F2
	strh r0, [r1, r7]
	ldrh r0, [r3]
	adds r0, r2, r0
	adds r1, #2
	strh r0, [r1, r7]
	ldrh r0, [r4]
	ldrh r1, [r5]
	adds r0, r0, r1
	ldr r1, _0804D7D0 @ =0x000002F6
	strh r0, [r1, r7]
	ldrh r0, [r3]
	adds r2, r2, r0
	subs r1, #0xa
	adds r0, r7, r1
	strh r2, [r0]
	ldrh r0, [r4]
	ldrh r5, [r5]
	adds r0, r0, r5
	ldr r2, _0804D7D4 @ =0x000002EE
	adds r1, r7, r2
	strh r0, [r1]
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _0804D7E4
	ldr r5, _0804D7D8 @ =0x00000283
	adds r0, r6, r5
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0804D7DC
	movs r0, MUS_FIELD_RUBY
	bl m4aSongNumStart
	b _0804D90E
	.align 2, 0
_0804D7B0: .4byte gMain
_0804D7B4: .4byte 0x0000FFE8
_0804D7B8: .4byte gCurrentPinballGame
_0804D7BC: .4byte 0x000005FC
_0804D7C0: .4byte 0x000005FE
_0804D7C4: .4byte 0x000005FB
_0804D7C8: .4byte gUnknown_02031520
_0804D7CC: .4byte 0x000002F2
_0804D7D0: .4byte 0x000002F6
_0804D7D4: .4byte 0x000002EE
_0804D7D8: .4byte 0x00000283
_0804D7DC:
	movs r0, MUS_FIELD_RUBY2
	bl m4aSongNumStart
	b _0804D90E
_0804D7E4:
	ldr r7, _0804D804 @ =0x00000283
	adds r0, r6, r7
	ldrb r0, [r0]
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0804D808
	movs r0, MUS_FIELD_SAPPHIRE
	bl m4aSongNumStart
	b _0804D90E
	.align 2, 0
_0804D804: .4byte 0x00000283
_0804D808:
	movs r0, MUS_FIELD_SAPPHIRE2
	bl m4aSongNumStart
	b _0804D90E
_0804D810:
	ldr r3, _0804D838 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r2, _0804D83C @ =0x000005FC
	adds r0, r1, r2
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	ldr r5, _0804D840 @ =0x000005FE
	adds r0, r1, r5
	strh r2, [r0]
	ldr r0, _0804D844 @ =0x000005FB
	adds r1, r1, r0
	strb r4, [r1]
	ldrb r0, [r7, #4]
	cmp r0, #3
	bhi _0804D84C
	ldr r0, [r3]
	adds r0, #0xe6
	ldr r1, _0804D848 @ =0x0000FFE8
	b _0804D862
	.align 2, 0
_0804D838: .4byte gCurrentPinballGame
_0804D83C: .4byte 0x000005FC
_0804D840: .4byte 0x000005FE
_0804D844: .4byte 0x000005FB
_0804D848: .4byte 0x0000FFE8
_0804D84C:
	cmp r0, #6
	bne _0804D85C
	ldr r0, [r3]
	adds r0, #0xe6
	ldr r1, _0804D858 @ =0x0000FFA8
	b _0804D862
	.align 2, 0
_0804D858: .4byte 0x0000FFA8
_0804D85C:
	ldr r0, [r3]
	adds r0, #0xe6
	ldr r1, _0804D93C @ =0x0000FFC0
_0804D862:
	strh r1, [r0]
	ldr r0, _0804D940 @ =gCurrentPinballGame
	ldr r5, [r0]
	ldr r1, _0804D944 @ =gUnknown_02031520
	ldrh r0, [r1, #0x14]
	adds r4, r5, #0
	adds r4, #0x4c
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0xe6
	ldrh r0, [r0]
	ldrh r2, [r1, #0x16]
	adds r0, r0, r2
	adds r6, r5, #0
	adds r6, #0x4e
	strh r0, [r6]
	movs r7, #0x16
	ldrsh r0, [r1, r7]
	lsls r0, r0, #8
	str r0, [r5, #0x54]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0x58
	strh r1, [r0]
	ldr r1, _0804D948 @ =0x000005FC
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r6]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldr r3, _0804D94C @ =gMain
	ldrh r0, [r4]
	mov r7, ip
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r0
	mov r8, r0
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r3, r2
	mov r7, r8
	strh r7, [r0]
	ldrh r2, [r6]
	ldr r7, _0804D950 @ =0x000002F2
	adds r0, r3, r7
	strh r2, [r0]
	ldrh r0, [r4]
	adds r0, r1, r0
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r2, r2, r3
	mov ip, r2
	strh r0, [r2]
	ldrh r2, [r6]
	adds r7, #4
	adds r0, r3, r7
	strh r2, [r0]
	ldrh r0, [r4]
	adds r1, r1, r0
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r6, r7]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r2, #2
	adds r1, r3, r2
	strh r0, [r1]
	ldrb r0, [r3, #4]
	cmp r0, #3
	bne _0804D90E
	movs r7, #0xa4
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r0, [r0]
	ldr r1, _0804D954 @ =0x000007FF
	ands r0, r1
	lsrs r0, r0, #3
	add r0, r8
	mov r1, ip
	strh r0, [r1]
_0804D90E:
	ldr r1, _0804D94C @ =gMain
	ldr r5, _0804D958 @ =0x000002EA
	adds r2, r1, r5
	movs r0, #0x50
	strh r0, [r2]
	ldr r0, _0804D940 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r7, _0804D95C @ =0x000002F6
	adds r1, r1, r7
	ldrh r1, [r1]
	adds r0, r2, #0
	adds r0, #0xcc
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	str r0, [r2, #0x2c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D93C: .4byte 0x0000FFC0
_0804D940: .4byte gCurrentPinballGame
_0804D944: .4byte gUnknown_02031520
_0804D948: .4byte 0x000005FC
_0804D94C: .4byte gMain
_0804D950: .4byte 0x000002F2
_0804D954: .4byte 0x000007FF
_0804D958: .4byte 0x000002EA
_0804D95C: .4byte 0x000002F6

	thumb_func_start sub_4D960
sub_4D960: @ 0x0804D960
	push {r4, r5, r6, r7, lr}
	movs r7, #0x80
	lsls r7, r7, #5
	ldr r0, _0804D9A4 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _0804D972
	bl sub_4E2F8
_0804D972:
	ldr r1, _0804D9A8 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r0, _0804D9AC @ =0x000005FB
	adds r4, r2, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r6, r1, #0
	cmp r0, #0
	beq _0804D9C2
	ldr r3, _0804D9B0 @ =0x000005FC
	adds r1, r2, r3
	ldr r5, _0804D9B4 @ =0x000005FE
	adds r0, r2, r5
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r2, [r1, r5]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	beq _0804D9BE
	cmp r2, r0
	ble _0804D9B8
	subs r0, r3, #1
	strh r0, [r1]
	b _0804D9C2
	.align 2, 0
_0804D9A4: .4byte gMain
_0804D9A8: .4byte gCurrentPinballGame
_0804D9AC: .4byte 0x000005FB
_0804D9B0: .4byte 0x000005FC
_0804D9B4: .4byte 0x000005FE
_0804D9B8:
	adds r0, r3, #1
	strh r0, [r1]
	b _0804D9C2
_0804D9BE:
	movs r0, #0
	strb r0, [r4]
_0804D9C2:
	ldr r5, [r6]
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	bne _0804D9E0
	ldr r1, _0804DA2C @ =0x00001330
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0x32
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0x80
	lsls r3, r3, #5
	adds r7, r0, r3
_0804D9E0:
	ldr r4, [r5, #0x2c]
	subs r0, r7, r4
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	str r4, [r5, #0x2c]
	ldr r1, _0804DA2C @ =0x00001330
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x38]
	adds r1, r0, r4
	ldr r2, _0804DA30 @ =gUnknown_02031520
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	lsls r0, r0, #8
	cmp r1, r0
	bgt _0804DA0E
	movs r4, #0x1a
	ldrsh r0, [r2, r4]
	lsls r0, r0, #8
	cmp r1, r0
	bge _0804DA10
_0804DA0E:
	adds r1, r0, #0
_0804DA10:
	ldr r5, _0804DA34 @ =0xFFFFB000
	adds r1, r1, r5
	ldr r0, [r6]
	ldr r4, [r0, #0x54]
	subs r0, r1, r4
	movs r1, #0xc
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	ble _0804DA38
	cmp r1, #0x4f
	bgt _0804DA42
	b _0804DA40
	.align 2, 0
_0804DA2C: .4byte 0x00001330
_0804DA30: .4byte gUnknown_02031520
_0804DA34: .4byte 0xFFFFB000
_0804DA38:
	movs r0, #0x50
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0804DA42
_0804DA40:
	movs r1, #0
_0804DA42:
	adds r4, r4, r1
	ldr r1, [r6]
	ldr r2, _0804DA7C @ =0x000005FA
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804DAAC
	str r4, [r1, #0x54]
	adds r0, r4, #0
	cmp r0, #0
	bge _0804DA5E
	adds r0, #0xff
_0804DA5E:
	asrs r0, r0, #8
	adds r2, r1, #0
	adds r2, #0x4e
	strh r0, [r2]
	ldr r3, _0804DA80 @ =0x00001330
	adds r0, r1, r3
	ldr r0, [r0]
	movs r4, #0x10
	ldrsh r0, [r0, r4]
	cmp r0, #0xe5
	ble _0804DA84
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, #1
	b _0804DA8A
	.align 2, 0
_0804DA7C: .4byte 0x000005FA
_0804DA80: .4byte 0x00001330
_0804DA84:
	adds r1, #0x4c
	ldrh r0, [r1]
	subs r0, #1
_0804DA8A:
	strh r0, [r1]
	ldr r0, _0804DAA0 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x10
	ble _0804DAA4
	movs r0, #0x10
	b _0804DAAA
	.align 2, 0
_0804DAA0: .4byte gCurrentPinballGame
_0804DAA4:
	cmp r0, #0
	bge _0804DAAC
	movs r0, #0
_0804DAAA:
	strh r0, [r1]
_0804DAAC:
	bl sub_4DFA0
	ldr r3, _0804DB14 @ =gMain
	ldr r0, _0804DB18 @ =gCurrentPinballGame
	ldr r4, [r0]
	adds r2, r4, #0
	adds r2, #0x4c
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r2, _0804DB1C @ =0x000002AA
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r0, r0, r1
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r1, r3, r5
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x4e
	ldr r2, _0804DB20 @ =0x00000121
	adds r0, r4, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrh r1, [r1]
	adds r2, r2, r1
	ldr r5, _0804DB24 @ =0x000005FC
	adds r0, r4, r5
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0xe6
	adds r1, r1, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xcc
	strh r1, [r0]
	ldr r0, _0804DB28 @ =0x000002F6
	adds r3, r3, r0
	ldrh r0, [r3]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #8
	ble _0804DB2C
	movs r2, #8
	b _0804DB36
	.align 2, 0
_0804DB14: .4byte gMain
_0804DB18: .4byte gCurrentPinballGame
_0804DB1C: .4byte 0x000002AA
_0804DB20: .4byte 0x00000121
_0804DB24: .4byte 0x000005FC
_0804DB28: .4byte 0x000002F6
_0804DB2C:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0804DB36
	ldr r2, _0804DBE0 @ =0x0000FFF8
_0804DB36:
	ldr r3, _0804DBE4 @ =gMain
	cmp r2, #0
	beq _0804DB46
	ldr r4, _0804DBE8 @ =0x000002F6
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_0804DB46:
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrh r2, [r0]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r4, _0804DBE8 @ =0x000002F6
	adds r0, r3, r4
	ldrh r1, [r0]
	subs r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	subs r4, #0xa
	adds r0, r3, r4
	strh r2, [r0]
	subs r5, #4
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _0804DBEC @ =gCurrentPinballGame
	ldr r4, [r0]
	adds r2, r4, #0
	adds r2, #0x4c
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r2, _0804DBF0 @ =0x000002AA
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x58
	strh r0, [r1]
	adds r6, r4, #0
	adds r6, #0x4e
	ldr r3, _0804DBF4 @ =0x00000121
	adds r3, r3, r4
	mov ip, r3
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldrh r5, [r6]
	adds r1, r1, r5
	ldr r0, _0804DBF8 @ =0x000005FC
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r5, r4, #0
	adds r5, #0xe6
	adds r0, r0, r1
	ldrh r1, [r5]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x68
	ldrh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x6a
	strh r1, [r0]
	mov r4, ip
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrh r6, [r6]
	adds r1, r1, r6
	ldrh r0, [r3]
	adds r0, r0, r1
	ldrh r5, [r5]
	adds r0, r0, r5
	strh r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804DBE0: .4byte 0x0000FFF8
_0804DBE4: .4byte gMain
_0804DBE8: .4byte 0x000002F6
_0804DBEC: .4byte gCurrentPinballGame
_0804DBF0: .4byte 0x000002AA
_0804DBF4: .4byte 0x00000121
_0804DBF8: .4byte 0x000005FC

	thumb_func_start sub_4DBFC
sub_4DBFC: @ 0x0804DBFC
	push {r4, r5, r6, r7, lr}
	movs r6, #0x80
	lsls r6, r6, #5
	ldr r0, _0804DC48 @ =gMain
	ldrb r0, [r0, #0xf]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	cmp r0, #0
	bne _0804DC14
	bl sub_4E468
_0804DC14:
	ldr r1, _0804DC4C @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r0, _0804DC50 @ =0x000005FB
	adds r4, r2, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r7, r1, #0
	cmp r0, #0
	beq _0804DC66
	ldr r3, _0804DC54 @ =0x000005FC
	adds r1, r2, r3
	ldr r5, _0804DC58 @ =0x000005FE
	adds r0, r2, r5
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r2, [r1, r5]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	beq _0804DC62
	cmp r2, r0
	ble _0804DC5C
	subs r0, r3, #1
	strh r0, [r1]
	b _0804DC66
	.align 2, 0
_0804DC48: .4byte gMain
_0804DC4C: .4byte gCurrentPinballGame
_0804DC50: .4byte 0x000005FB
_0804DC54: .4byte 0x000005FC
_0804DC58: .4byte 0x000005FE
_0804DC5C:
	adds r0, r3, #1
	strh r0, [r1]
	b _0804DC66
_0804DC62:
	movs r0, #0
	strb r0, [r4]
_0804DC66:
	ldr r5, [r7]
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	bne _0804DC84
	ldr r6, _0804DCD0 @ =0x00001330
	adds r0, r5, r6
	ldr r0, [r0]
	movs r2, #0x32
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0x80
	lsls r3, r3, #5
	adds r6, r0, r3
_0804DC84:
	ldr r4, [r5, #0x2c]
	subs r0, r6, r4
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	str r4, [r5, #0x2c]
	ldr r6, _0804DCD0 @ =0x00001330
	adds r0, r5, r6
	ldr r0, [r0]
	ldr r0, [r0, #0x38]
	adds r2, r0, r4
	ldr r1, _0804DCD4 @ =gUnknown_02031520
	movs r3, #0x18
	ldrsh r0, [r1, r3]
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0804DCB2
	movs r4, #0x1a
	ldrsh r0, [r1, r4]
	lsls r0, r0, #8
	cmp r2, r0
	bge _0804DCB4
_0804DCB2:
	adds r2, r0, #0
_0804DCB4:
	ldr r5, _0804DCD8 @ =0xFFFFB000
	adds r2, r2, r5
	ldr r0, [r7]
	ldr r4, [r0, #0x54]
	subs r0, r2, r4
	movs r1, #0xc
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	ble _0804DCDC
	cmp r1, #0x4f
	bgt _0804DCE6
	b _0804DCE4
	.align 2, 0
_0804DCD0: .4byte 0x00001330
_0804DCD4: .4byte gUnknown_02031520
_0804DCD8: .4byte 0xFFFFB000
_0804DCDC:
	movs r0, #0x50
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0804DCE6
_0804DCE4:
	movs r1, #0
_0804DCE6:
	adds r4, r4, r1
	ldr r0, _0804DD80 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r6, _0804DD84 @ =0x000005FA
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804DD0C
	str r4, [r2, #0x54]
	adds r0, r4, #0
	cmp r0, #0
	bge _0804DD04
	adds r0, #0xff
_0804DD04:
	asrs r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x4e
	strh r1, [r0]
_0804DD0C:
	bl sub_4DFA0
	ldr r2, _0804DD88 @ =gMain
	ldr r0, _0804DD80 @ =gCurrentPinballGame
	ldr r3, [r0]
	adds r1, r3, #0
	adds r1, #0x4c
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r5, _0804DD8C @ =0x000002AA
	adds r1, r3, r5
	adds r0, #8
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r6, #0xbc
	lsls r6, r6, #2
	adds r2, r2, r6
	strh r0, [r2]
	adds r2, r3, #0
	adds r2, #0x4e
	ldr r1, _0804DD90 @ =0x00000121
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r2, _0804DD94 @ =0x000005FC
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r2, r3, #0
	adds r2, #0xe6
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xab
	lsls r4, r4, #2
	adds r1, r3, r4
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0xcc
	strh r1, [r0]
	subs r0, #2
	ldrh r0, [r0]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #8
	ble _0804DD98
	movs r2, #8
	b _0804DDA2
	.align 2, 0
_0804DD80: .4byte gCurrentPinballGame
_0804DD84: .4byte 0x000005FA
_0804DD88: .4byte gMain
_0804DD8C: .4byte 0x000002AA
_0804DD90: .4byte 0x00000121
_0804DD94: .4byte 0x000005FC
_0804DD98:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0804DDA2
	ldr r2, _0804DDDC @ =0x0000FFF8
_0804DDA2:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	ldr r7, _0804DDE0 @ =gCurrentPinballGame
	cmp r2, #0
	beq _0804DDB6
	ldr r1, [r7]
	adds r1, #0xca
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_0804DDB6:
	ldr r1, _0804DDE4 @ =gMain
	ldr r0, [r7]
	adds r0, #0xca
	ldrh r2, [r0]
	ldr r5, _0804DDE8 @ =0x000002F2
	adds r0, r1, r5
	strh r2, [r0]
	ldrb r0, [r1, #4]
	subs r0, #2
	adds r4, r1, #0
	cmp r0, #5
	bls _0804DDD0
	b _0804DF18
_0804DDD0:
	lsls r0, r0, #2
	ldr r1, _0804DDEC @ =_0804DDF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DDDC: .4byte 0x0000FFF8
_0804DDE0: .4byte gCurrentPinballGame
_0804DDE4: .4byte gMain
_0804DDE8: .4byte 0x000002F2
_0804DDEC: .4byte _0804DDF0
_0804DDF0: @ jump table
	.4byte _0804DE08 @ case 0
	.4byte _0804DE4C @ case 1
	.4byte _0804DE98 @ case 2
	.4byte _0804DE98 @ case 3
	.4byte _0804DEC8 @ case 4
	.4byte _0804DEFC @ case 5
_0804DE08:
	movs r6, #0xbc
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r2, [r0]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	ldr r3, _0804DE40 @ =0x000002F2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r5, _0804DE44 @ =0x000002F6
	adds r0, r4, r5
	strh r1, [r0]
	subs r6, #4
	adds r0, r4, r6
	strh r2, [r0]
	ldr r0, [r7]
	adds r0, #0xca
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0804DE48 @ =0x000002EE
	adds r1, r4, r2
	strh r0, [r1]
	b _0804DF18
	.align 2, 0
_0804DE40: .4byte 0x000002F2
_0804DE44: .4byte 0x000002F6
_0804DE48: .4byte 0x000002EE
_0804DE4C:
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r4, r3
	ldr r0, [r7]
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r1, _0804DE8C @ =0x000007FF
	ands r0, r1
	lsrs r0, r0, #3
	ldrh r2, [r2]
	adds r0, r2, r0
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r3, #0
	strh r0, [r1]
	ldr r1, _0804DE90 @ =0x000002F2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x66
	adds r0, r4, r5
	strh r1, [r0]
	subs r6, #8
	adds r0, r4, r6
	strh r2, [r0]
	ldr r1, _0804DE94 @ =0x000002EE
	adds r0, r4, r1
	strh r3, [r0]
	b _0804DF18
	.align 2, 0
_0804DE8C: .4byte 0x000007FF
_0804DE90: .4byte 0x000002F2
_0804DE94: .4byte 0x000002EE
_0804DE98:
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r2, [r0]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldr r5, _0804DEC0 @ =0x000002F2
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r6, _0804DEC4 @ =0x000002F6
	adds r0, r4, r6
	strh r1, [r0]
	subs r3, #8
	adds r0, r4, r3
	strh r2, [r0]
	subs r5, #4
	adds r0, r4, r5
	b _0804DF16
	.align 2, 0
_0804DEC0: .4byte 0x000002F2
_0804DEC4: .4byte 0x000002F6
_0804DEC8:
	movs r6, #0xbc
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r3, [r0]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	ldr r5, _0804DEF4 @ =0x000002F2
	adds r2, r4, r5
	ldrh r0, [r2]
	lsrs r0, r0, #2
	adds r6, #6
	adds r1, r4, r6
	strh r0, [r1]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	ldrh r1, [r2]
	ldr r2, _0804DEF8 @ =0x000002EE
	b _0804DF14
	.align 2, 0
_0804DEF4: .4byte 0x000002F2
_0804DEF8: .4byte 0x000002EE
_0804DEFC:
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _0804DF8C @ =0x000002F2
	adds r0, r4, r6
	ldrh r1, [r0]
	ldr r2, _0804DF90 @ =0x000002F6
_0804DF14:
	adds r0, r4, r2
_0804DF16:
	strh r1, [r0]
_0804DF18:
	ldr r3, [r7]
	adds r2, r3, #0
	adds r2, #0x4c
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r5, _0804DF94 @ =0x000002AA
	adds r0, r3, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x58
	strh r0, [r1]
	movs r6, #0x4e
	adds r6, r6, r3
	mov ip, r6
	ldr r0, _0804DF98 @ =0x00000121
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	ldrh r1, [r6]
	adds r0, r0, r1
	ldr r4, _0804DF9C @ =0x000005FC
	adds r2, r3, r4
	ldrh r1, [r2]
	adds r4, r3, #0
	adds r4, #0xe6
	adds r1, r1, r0
	ldrh r6, [r4]
	adds r1, r1, r6
	movs r6, #0xab
	lsls r6, r6, #2
	adds r0, r3, r6
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x5a
	strh r0, [r1]
	movs r1, #0
	ldrsb r1, [r5, r1]
	mov r0, ip
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r2]
	adds r0, r0, r1
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r1, r3, #0
	adds r1, #0x68
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804DF8C: .4byte 0x000002F2
_0804DF90: .4byte 0x000002F6
_0804DF94: .4byte 0x000002AA
_0804DF98: .4byte 0x00000121
_0804DF9C: .4byte 0x000005FC

	thumb_func_start sub_4DFA0
sub_4DFA0: @ 0x0804DFA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r3, _0804E0C8 @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804E084
	ldr r1, _0804E0CC @ =0x000005A4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0804E084
	ldr r4, _0804E0D0 @ =0x0000061C
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804E084
	ldrb r0, [r2, #6]
	cmp r0, #0
	beq _0804E008
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0804E008
	ldr r4, _0804E0D4 @ =0x00000129
	adds r0, r2, r4
	strb r1, [r0]
	ldr r0, [r3]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804E008
	movs r0, #4
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x78
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0804E008:
	ldr r2, _0804E0C8 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0804E044
	movs r3, #0x95
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804E044
	ldr r4, _0804E0D4 @ =0x00000129
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804E044
	movs r0, #4
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x78
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0804E044:
	ldr r0, _0804E0C8 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldrb r1, [r3, #8]
	mov r8, r0
	cmp r1, #0
	beq _0804E084
	movs r4, #0x95
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804E084
	ldr r0, _0804E0D4 @ =0x00000129
	adds r1, r3, r0
	movs r0, #2
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804E096
	movs r0, #4
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x78
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0804E084:
	ldr r0, _0804E0C8 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #0
	beq _0804E174
_0804E096:
	mov r4, r8
	ldr r0, [r4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	adds r2, r1, r2
	ldrb r3, [r2]
	cmp r3, #0
	bne _0804E174
	ldr r2, _0804E0D4 @ =0x00000129
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	beq _0804E10C
	cmp r2, #1
	bgt _0804E0D8
	cmp r2, #0
	beq _0804E0DE
	b _0804E166
	.align 2, 0
_0804E0C8: .4byte gCurrentPinballGame
_0804E0CC: .4byte 0x000005A4
_0804E0D0: .4byte 0x0000061C
_0804E0D4: .4byte 0x00000129
_0804E0D8:
	cmp r2, #2
	beq _0804E13C
	b _0804E166
_0804E0DE:
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r1, r3
	movs r2, #6
	strb r2, [r0]
	mov r4, r8
	ldr r0, [r4]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
	ldr r0, [r4]
	adds r3, #2
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	movs r4, #0x8f
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	b _0804E166
_0804E10C:
	ldr r3, _0804E134 @ =0x00000119
	adds r0, r1, r3
	movs r1, #6
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r3, #4
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	ldr r4, _0804E138 @ =0x0000011B
	adds r0, r0, r4
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r3, #2
	adds r0, r0, r3
	strb r2, [r0]
	b _0804E166
	.align 2, 0
_0804E134: .4byte 0x00000119
_0804E138: .4byte 0x0000011B
_0804E13C:
	movs r4, #0x8d
	lsls r4, r4, #1
	adds r1, r1, r4
	movs r0, #6
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	subs r2, #3
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r4]
	ldr r3, _0804E1CC @ =0x0000011F
	adds r0, r0, r3
	strb r1, [r0]
_0804E166:
	mov r4, r8
	ldr r0, [r4]
	movs r2, #0x95
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0x18
	strb r0, [r1]
_0804E174:
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0x95
	lsls r4, r4, #1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804E188
	subs r0, #1
	strb r0, [r1]
_0804E188:
	movs r5, #0
	mov ip, r8
	movs r7, #0x8c
	lsls r7, r7, #1
	movs r6, #0x8e
	lsls r6, r6, #1
	mov r4, sp
_0804E196:
	mov r1, ip
	ldr r0, [r1]
	adds r0, r0, r7
	adds r1, r0, r5
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0804E1AC
	subs r0, r2, #1
	strb r0, [r1]
_0804E1AC:
	mov r2, ip
	ldr r1, [r2]
	adds r0, r1, r7
	adds r3, r0, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _0804E1D0
	adds r0, r1, r6
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	b _0804E1E2
	.align 2, 0
_0804E1CC: .4byte 0x0000011F
_0804E1D0:
	adds r0, r1, r6
	adds r0, r0, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #6
	subs r0, r0, r1
	muls r0, r2, r0
_0804E1E2:
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
	cmp r5, #3
	ble _0804E196
	mov r3, r8
	ldr r1, [r3]
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0, #2]
	ldrb r2, [r2]
	adds r0, r0, r2
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r1, r3
	strb r0, [r1]
	mov r4, r8
	ldr r2, [r4]
	mov r1, sp
	mov r0, sp
	ldrb r0, [r0, #6]
	ldrb r1, [r1, #4]
	adds r0, r0, r1
	ldr r4, _0804E254 @ =0x00000121
	adds r1, r2, r4
	strb r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r3
	ldrh r1, [r0]
	cmp r1, #0
	bne _0804E232
	adds r4, #5
	adds r0, r2, r4
	strb r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
_0804E232:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	ble _0804E258
	movs r3, #0x91
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _0804E270
	subs r0, r3, #1
	b _0804E26E
	.align 2, 0
_0804E254: .4byte 0x00000121
_0804E258:
	cmp r2, #0
	bge _0804E270
	movs r4, #0x91
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	ble _0804E270
	adds r0, r3, #1
_0804E26E:
	strb r0, [r1]
_0804E270:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, _0804E294 @ =0x00000121
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	ble _0804E29C
	ldr r3, _0804E298 @ =0x00000123
	adds r1, r1, r3
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _0804E2B2
	subs r0, r3, #1
	b _0804E2B0
	.align 2, 0
_0804E294: .4byte 0x00000121
_0804E298: .4byte 0x00000123
_0804E29C:
	cmp r2, #0
	bge _0804E2B2
	ldr r4, _0804E2F4 @ =0x00000123
	adds r1, r1, r4
	ldrb r3, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	ble _0804E2B2
	adds r0, r3, #1
_0804E2B0:
	strb r0, [r1]
_0804E2B2:
	mov r0, r8
	ldr r1, [r0]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804E2E6
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r4, #0x91
	lsls r4, r4, #1
	adds r1, r1, r4
	strb r0, [r1]
	mov r0, r8
	ldr r1, [r0]
	subs r2, #5
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r3, #3
	adds r1, r1, r3
	strb r0, [r1]
_0804E2E6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E2F4: .4byte 0x00000123

	thumb_func_start sub_4E2F8
sub_4E2F8: @ 0x0804E2F8
	push {r4, r5, r6, r7, lr}
	ldr r0, _0804E3E4 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	adds r5, r0, #0
	cmp r1, #0
	beq _0804E328
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _0804E328
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E328
	adds r0, r2, #0
	adds r0, #0x21
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0804E3E8 @ =0x00000163
	adds r0, r0, r2
	strb r1, [r0]
_0804E328:
	adds r4, r5, #0
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E372
	ldrb r0, [r1, #0xa]
	cmp r0, #0
	beq _0804E372
	ldr r0, _0804E3E8 @ =0x00000163
	adds r1, r1, r0
	movs r6, #0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E36C
	movs r0, #7
	bl sub_11B0
	ldr r0, [r4]
	ldr r1, _0804E3EC @ =0x0000132C
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _0804E3F0 @ =0x0000FDB2
	strh r1, [r2, #0x32]
	ldr r0, [r0]
	strh r6, [r0, #0x30]
	movs r0, SE_UNKNOWN_0xCD
	bl m4aSongNumStart
_0804E36C:
	ldr r0, [r5]
	adds r0, #0x21
	strb r6, [r0]
_0804E372:
	ldr r7, _0804E3E4 @ =gCurrentPinballGame
	ldr r6, [r7]
	ldr r2, _0804E3EC @ =0x0000132C
	adds r3, r6, r2
	ldr r0, _0804E3F4 @ =0x00001334
	adds r4, r6, r0
	str r4, [r3]
	ldr r0, _0804E3F8 @ =gUnknown_02031520
	movs r2, #0x12
	ldrsh r1, [r4, r2]
	ldrh r5, [r0, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _0804E452
	movs r2, #0
	strh r5, [r4, #0x12]
	ldr r1, [r3]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r3]
	movs r4, #0x12
	ldrsh r0, [r1, r4]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r1, [r3]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r3]
	movs r4, #0x12
	ldrsh r0, [r1, r4]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r0, [r3]
	strh r2, [r0, #0x30]
	ldr r0, [r3]
	strh r2, [r0, #0x32]
	ldr r4, _0804E3FC @ =gMain
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _0804E452
	ldr r1, _0804E400 @ =0x00000724
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804E404
	movs r0, #4
	strh r0, [r4, #0x14]
	movs r0, #8
	strb r0, [r4, #0x11]
	movs r0, #0xcc
	strh r0, [r4, #0x12]
	b _0804E452
	.align 2, 0
_0804E3E4: .4byte gCurrentPinballGame
_0804E3E8: .4byte 0x00000163
_0804E3EC: .4byte 0x0000132C
_0804E3F0: .4byte 0x0000FDB2
_0804E3F4: .4byte 0x00001334
_0804E3F8: .4byte gUnknown_02031520
_0804E3FC: .4byte gMain
_0804E400: .4byte 0x00000724
_0804E404:
	movs r0, #0x50
	strh r0, [r4, #0x14]
	movs r0, #0x10
	strb r0, [r4, #0x11]
	movs r0, #0xc8
	strh r0, [r4, #0x12]
	bl m4aMPlayAllStop
	movs r0, MUS_END_OF_BALL
	bl m4aSongNumStart
	bl sub_4E598
	ldr r2, [r7]
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #2
	bne _0804E452
	movs r0, #9
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _0804E452
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	ldr r1, [r7]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r2]
	adds r1, r1, r3
	movs r0, #0
	strb r0, [r1]
_0804E452:
	ldr r0, _0804E464 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x20
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E464: .4byte gCurrentPinballGame

	thumb_func_start sub_4E468
sub_4E468: @ 0x0804E468
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0804E4C4 @ =gCurrentPinballGame
	ldr r5, [r2]
	ldr r0, _0804E4C8 @ =0x0000132C
	mov r8, r0
	adds r4, r5, r0
	ldr r1, _0804E4CC @ =0x00001334
	adds r3, r5, r1
	str r3, [r4]
	ldr r6, _0804E4D0 @ =gUnknown_02031520
	movs r7, #0x12
	ldrsh r1, [r3, r7]
	movs r7, #0x2a
	ldrsh r0, [r6, r7]
	mov ip, r2
	cmp r1, r0
	blt _0804E572
	movs r1, #0
	strh r1, [r3, #0x30]
	ldr r0, [r4]
	strh r1, [r0, #0x32]
	ldr r3, _0804E4D4 @ =gMain
	ldrb r1, [r3, #0xf]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0804E4DC
	ldr r0, _0804E4D8 @ =0x00000386
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	mov r1, ip
	ldr r0, [r1]
	add r0, r8
	ldr r1, [r0]
	ldrh r0, [r6, #0x2a]
	subs r0, #0xa
	strh r0, [r1, #0x12]
	b _0804E542
	.align 2, 0
_0804E4C4: .4byte gCurrentPinballGame
_0804E4C8: .4byte 0x0000132C
_0804E4CC: .4byte 0x00001334
_0804E4D0: .4byte gUnknown_02031520
_0804E4D4: .4byte gMain
_0804E4D8: .4byte 0x00000386
_0804E4DC:
	ldr r0, [r4]
	movs r1, #1
	strb r1, [r0]
	mov r3, ip
	ldr r0, [r3]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r0, r0, r7
	strb r1, [r0]
	ldr r3, [r3]
	ldr r1, _0804E57C @ =0x00000392
	adds r0, r3, r1
	strh r2, [r0]
	mov r7, r8
	adds r2, r3, r7
	ldr r1, [r2]
	ldrh r0, [r6, #0x26]
	strh r0, [r1, #0x10]
	ldr r1, [r2]
	ldrh r0, [r6, #0x28]
	strh r0, [r1, #0x12]
	ldr r4, _0804E580 @ =0x000005F6
	adds r3, r3, r4
	ldrb r1, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _0804E518
	subs r0, r1, #1
	strb r0, [r3]
_0804E518:
	mov r0, ip
	ldr r1, [r0]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r2, r1, r3
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r2]
	ldr r2, _0804E584 @ =0x040000D4
	adds r1, r1, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #5
	ldr r1, _0804E588 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804E58C @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0804E590 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804E542:
	mov r7, ip
	ldr r1, [r7]
	ldr r0, _0804E594 @ =0x0000132C
	adds r1, r1, r0
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r2, [r1]
	movs r7, #0x12
	ldrsh r0, [r2, r7]
	lsls r0, r0, #1
	strh r0, [r2, #0x2a]
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r1, [r1]
	movs r7, #0x12
	ldrsh r0, [r1, r7]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
_0804E572:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804E57C: .4byte 0x00000392
_0804E580: .4byte 0x000005F6
_0804E584: .4byte 0x040000D4
_0804E588: .4byte gUnknown_08137E14
_0804E58C: .4byte 0x05000220
_0804E590: .4byte 0x80000010
_0804E594: .4byte 0x0000132C

	.section .text4E598

	thumb_func_start sub_4E814
sub_4E814: @ 0x0804E814
	push {r4, r5, r6, lr}
	ldr r6, _0804E910 @ =gCurrentPinballGame
	ldr r4, [r6]
	ldr r0, _0804E914 @ =0x0000070C
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x14
	bl __udivsi3
	ldr r1, _0804E918 @ =0x00000734
	adds r4, r4, r1
	strh r0, [r4]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	bl sub_4EA44
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xe7
	bgt _0804E854
	bl sub_4EDC0
	bl sub_4EE74
_0804E854:
	ldr r0, [r6]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #0x51
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa6
	bhi _0804E868
	bl sub_4EF38
_0804E868:
	bl sub_4F0F0
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x6f
	bgt _0804E87C
	bl sub_4F258
_0804E87C:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x70
	ble _0804E88C
	bl sub_4F028
_0804E88C:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x68
	ble _0804E8A0
	bl sub_4F4B4
	bl sub_4F660
_0804E8A0:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xff
	bgt _0804E8B0
	bl sub_4F30C
_0804E8B0:
	bl sub_4F2B8
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x6e
	ble _0804E8C4
	bl sub_4EAB0
_0804E8C4:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xb2
	ble _0804E8DC
	bl sub_4EAF8
	bl sub_4EBD0
	bl sub_4E920
_0804E8DC:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xca
	ble _0804E8EC
	bl sub_4ECDC
_0804E8EC:
	ldr r0, [r6]
	ldr r1, _0804E91C @ =0x00000724
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, #0
	beq _0804E908
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804E908
	subs r0, r1, #1
	strh r0, [r2]
_0804E908:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804E910: .4byte gCurrentPinballGame
_0804E914: .4byte 0x0000070C
_0804E918: .4byte 0x00000734
_0804E91C: .4byte 0x00000724

	thumb_func_start sub_4E920
sub_4E920: @ 0x0804E920
	push {r4, r5, lr}
	ldr r1, _0804E9CC @ =gUnknown_086B08CA
	ldr r4, _0804E9D0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _0804E9D4 @ =0x00000716
	adds r3, r0, r2
	ldrb r2, [r3]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	cmp r2, #0
	beq _0804E95C
	subs r0, r2, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r1, _0804E9D4 @ =0x00000716
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E95C
	movs r0, SE_UNKNOWN_0x73
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1, #0x3c]
	movs r0, #7
	bl sub_11B0
_0804E95C:
	ldr r0, _0804E9D0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0804E9D8 @ =0x00000717
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r3, r0, #4
	subs r3, r3, r0
	lsls r3, r3, #2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _0804E9DC @ =gUnknown_086B08D4
	adds r2, r2, r0
	adds r2, r3, r2
	adds r0, #0x28
	adds r3, r3, r0
	ldr r0, _0804E9E0 @ =0x040000D4
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r3]
	str r1, [r0, #4]
	ldr r1, _0804E9E4 @ =0x80000010
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #4]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #4]
	ldr r5, _0804E9E8 @ =0x80000020
	str r5, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #8]
	str r1, [r0]
	ldr r1, [r3, #8]
	str r1, [r0, #4]
	ldr r4, _0804E9EC @ =0x80000030
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #0xc]
	str r1, [r0]
	ldr r1, [r3, #0xc]
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #0x10]
	str r1, [r0]
	ldr r1, [r3, #0x10]
	str r1, [r0, #4]
	str r5, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E9CC: .4byte gUnknown_086B08CA
_0804E9D0: .4byte gCurrentPinballGame
_0804E9D4: .4byte 0x00000716
_0804E9D8: .4byte 0x00000717
_0804E9DC: .4byte gUnknown_086B08D4
_0804E9E0: .4byte 0x040000D4
_0804E9E4: .4byte 0x80000010
_0804E9E8: .4byte 0x80000020
_0804E9EC: .4byte 0x80000030

	thumb_func_start sub_4E9F0
sub_4E9F0: @ 0x0804E9F0
	push {r4, lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r3, _0804EA34 @ =gUnknown_086B094C
	adds r2, r2, r3
	adds r4, r3, #0
	adds r4, #0x18
	ldr r1, _0804EA38 @ =0x040000D4
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r3, #0x18]
	str r0, [r1, #4]
	ldr r3, _0804EA3C @ =0x80000060
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2, #8]
	str r0, [r1]
	ldr r0, [r4, #8]
	str r0, [r1, #4]
	ldr r0, _0804EA40 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EA34: .4byte gUnknown_086B094C
_0804EA38: .4byte 0x040000D4
_0804EA3C: .4byte 0x80000060
_0804EA40: .4byte 0x80000010

	thumb_func_start sub_4EA44
sub_4EA44: @ 0x0804EA44
	push {r4, r5, lr}
	ldr r0, _0804EA9C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0804EAA0 @ =0x0000070E
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r0, r5, #0
	movs r1, #0xa
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	asrs r4, r4, #8
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	lsls r4, r4, #0x10
	asrs r4, r4, #0xd
	ldr r3, _0804EAA4 @ =gUnknown_086B0970
	adds r4, r4, r3
	ldr r2, _0804EAA8 @ =0x040000D4
	ldr r1, [r4]
	str r1, [r2]
	ldr r1, [r3, #0x50]
	str r1, [r2, #4]
	ldr r1, _0804EAAC @ =0x80000010
	str r1, [r2, #8]
	ldr r4, [r2, #8]
	asrs r0, r0, #0x15
	adds r4, r0, r3
	ldr r0, [r4, #4]
	str r0, [r2]
	ldr r0, [r3, #0x54]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EA9C: .4byte gCurrentPinballGame
_0804EAA0: .4byte 0x0000070E
_0804EAA4: .4byte gUnknown_086B0970
_0804EAA8: .4byte 0x040000D4
_0804EAAC: .4byte 0x80000010

	thumb_func_start sub_4EAB0
sub_4EAB0: @ 0x0804EAB0
	push {r4, lr}
	ldr r0, _0804EAE8 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	ldr r3, _0804EAEC @ =gUnknown_086B09C8
	adds r2, r2, r3
	ldr r0, _0804EAF0 @ =0x040000D4
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r3, #0x18]
	str r1, [r0, #4]
	ldr r4, _0804EAF4 @ =0x80000020
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #4]
	str r1, [r0]
	ldr r1, [r3, #0x1c]
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EAE8: .4byte gCurrentPinballGame
_0804EAEC: .4byte gUnknown_086B09C8
_0804EAF0: .4byte 0x040000D4
_0804EAF4: .4byte 0x80000020

	thumb_func_start sub_4EAF8
sub_4EAF8: @ 0x0804EAF8
	push {r4, r5, r6, r7, lr}
	ldr r7, _0804EBB4 @ =gCurrentPinballGame
	ldr r5, [r7]
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804EB5E
	ldr r6, _0804EBB8 @ =0x00000721
	adds r0, r5, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r4, _0804EBBC @ =0x0000071D
	adds r5, r5, r4
	adds r5, r5, r0
	ldrb r0, [r1]
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x12
	bl __udivsi3
	movs r1, #1
	subs r1, r1, r0
	strb r1, [r5]
	ldr r0, [r7]
	ldr r2, _0804EBC0 @ =0x00000722
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, r4
	adds r1, r4, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r1, [r7]
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0804EB5E:
	movs r1, #0
	ldr r0, [r7]
	ldr r2, _0804EBBC @ =0x0000071D
	adds r7, r0, r2
	ldr r6, _0804EBC4 @ =gUnknown_086B09E8
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldr r4, _0804EBC8 @ =0x040000D4
	ldr r5, _0804EBCC @ =0x80000020
_0804EB72:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #3
	subs r2, r2, r3
	lsls r2, r2, #3
	adds r0, r7, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, r2, r1
	add r2, ip
	ldr r0, [r1]
	str r0, [r4]
	ldr r0, [r2]
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [r1, #4]
	str r0, [r4]
	ldr r0, [r2, #4]
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0804EB72
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBB4: .4byte gCurrentPinballGame
_0804EBB8: .4byte 0x00000721
_0804EBBC: .4byte 0x0000071D
_0804EBC0: .4byte 0x00000722
_0804EBC4: .4byte gUnknown_086B09E8
_0804EBC8: .4byte 0x040000D4
_0804EBCC: .4byte 0x80000020

	thumb_func_start sub_4EBD0
sub_4EBD0: @ 0x0804EBD0
	push {r4, r5, r6, r7, lr}
	ldr r5, _0804EC38 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r1, _0804EC3C @ =0x00000714
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0804EC7A
	ldr r2, _0804EC40 @ =0x00000715
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804EC4C
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x12
	bl __udivsi3
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0804EC44 @ =0x00000711
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _0804EC48 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	adds r3, #3
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0804EC7A
	.align 2, 0
_0804EC38: .4byte gCurrentPinballGame
_0804EC3C: .4byte 0x00000714
_0804EC40: .4byte 0x00000715
_0804EC44: .4byte 0x00000711
_0804EC48: .4byte 0x00000713
_0804EC4C:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0804ECC4 @ =0x00000711
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _0804ECC8 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
_0804EC7A:
	movs r2, #0
	ldr r0, _0804ECCC @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r5, r0, r3
	ldr r4, _0804ECD0 @ =gUnknown_086B0BC4
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _0804ECD4 @ =0x040000D4
	ldr r6, _0804ECD8 @ =0x80000020
_0804EC90:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r2, r0
	adds r2, r2, r7
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, [r2]
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _0804EC90
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804ECC4: .4byte 0x00000711
_0804ECC8: .4byte 0x00000713
_0804ECCC: .4byte gCurrentPinballGame
_0804ECD0: .4byte gUnknown_086B0BC4
_0804ECD4: .4byte 0x040000D4
_0804ECD8: .4byte 0x80000020

	thumb_func_start sub_4ECDC
sub_4ECDC: @ 0x0804ECDC
	push {r4, r5, lr}
	ldr r0, _0804ECF8 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r2, _0804ECFC @ =0x00000724
	adds r1, r3, r2
	ldrh r2, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r5, r0, #0
	cmp r2, r1
	bls _0804ED04
	ldr r0, _0804ED00 @ =0x00000726
	adds r1, r3, r0
	b _0804ED1A
	.align 2, 0
_0804ECF8: .4byte gCurrentPinballGame
_0804ECFC: .4byte 0x00000724
_0804ED00: .4byte 0x00000726
_0804ED04:
	cmp r2, #0
	beq _0804ED40
	adds r0, r3, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0804ED24
	ldr r2, _0804ED20 @ =0x00000726
	adds r1, r3, r2
_0804ED1A:
	movs r0, #1
	strb r0, [r1]
	b _0804ED46
	.align 2, 0
_0804ED20: .4byte 0x00000726
_0804ED24:
	ldr r0, _0804ED38 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0xf
	ands r0, r1
	lsrs r0, r0, #3
	ldr r2, _0804ED3C @ =0x00000726
	adds r1, r3, r2
	strb r0, [r1]
	b _0804ED46
	.align 2, 0
_0804ED38: .4byte gMain
_0804ED3C: .4byte 0x00000726
_0804ED40:
	ldr r1, _0804EDA8 @ =0x00000726
	adds r0, r3, r1
	strb r2, [r0]
_0804ED46:
	ldr r0, [r5]
	ldr r2, _0804EDA8 @ =0x00000726
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #4
	ldr r1, _0804EDAC @ =gUnknown_086B0A90
	adds r3, r0, r1
	adds r4, r1, #0
	adds r4, #0x20
	ldr r2, _0804EDB0 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r1, #0x20]
	str r0, [r2, #4]
	ldr r1, _0804EDB4 @ =0x80000060
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd7
	ble _0804EDA0
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	ldr r0, _0804EDB8 @ =0x80000050
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #0xc]
	str r0, [r2]
	ldr r0, [r4, #0xc]
	str r0, [r2, #4]
	ldr r0, _0804EDBC @ =0x80000020
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804EDA0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EDA8: .4byte 0x00000726
_0804EDAC: .4byte gUnknown_086B0A90
_0804EDB0: .4byte 0x040000D4
_0804EDB4: .4byte 0x80000060
_0804EDB8: .4byte 0x80000050
_0804EDBC: .4byte 0x80000020

	thumb_func_start sub_4EDC0
sub_4EDC0: @ 0x0804EDC0
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r0, _0804EE60 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r4, #0xe5
	lsls r4, r4, #3
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r1, #0
	ble _0804EDE8
	ldr r1, _0804EE64 @ =0x00000734
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0804EDE8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r3, _0804EE68 @ =gUnknown_086B0AC0
	adds r4, r0, r3
	adds r5, r3, #0
	adds r5, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x30
	ble _0804EE30
	cmp r0, #0xd7
	bgt _0804EE14
	ldr r1, _0804EE6C @ =0x040000D4
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r3, #0x20]
	str r0, [r1, #4]
	ldr r0, _0804EE70 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EE14:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xdf
	bgt _0804EE30
	ldr r1, _0804EE6C @ =0x040000D4
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804EE70 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EE30:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x40
	ble _0804EE58
	ldr r0, _0804EE6C @ =0x040000D4
	ldr r1, [r4, #8]
	str r1, [r0]
	ldr r1, [r5, #8]
	str r1, [r0, #4]
	ldr r2, _0804EE70 @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r4, #0xc]
	str r1, [r0]
	ldr r1, [r5, #0xc]
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
_0804EE58:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804EE60: .4byte gCurrentPinballGame
_0804EE64: .4byte 0x00000734
_0804EE68: .4byte gUnknown_086B0AC0
_0804EE6C: .4byte 0x040000D4
_0804EE70: .4byte 0x80000040

	thumb_func_start sub_4EE74
sub_4EE74: @ 0x0804EE74
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r0, _0804EF18 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r4, _0804EF1C @ =0x00000729
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r6, r0, #0
	cmp r1, #0
	ble _0804EE9A
	ldr r1, _0804EF20 @ =0x00000734
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0804EE9A:
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r3, _0804EF24 @ =gUnknown_086B0AF0
	adds r4, r0, r3
	adds r5, r3, #0
	adds r5, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x28
	ble _0804EEE2
	cmp r0, #0xcf
	bgt _0804EEC6
	ldr r1, _0804EF28 @ =0x040000D4
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r3, #0x20]
	str r0, [r1, #4]
	ldr r0, _0804EF2C @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EEC6:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd7
	bgt _0804EEE2
	ldr r1, _0804EF28 @ =0x040000D4
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804EF30 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EEE2:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x38
	ble _0804EF12
	cmp r0, #0xdf
	bgt _0804EF02
	ldr r1, _0804EF28 @ =0x040000D4
	ldr r0, [r4, #8]
	str r0, [r1]
	ldr r0, [r5, #8]
	str r0, [r1, #4]
	ldr r0, _0804EF30 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EF02:
	ldr r1, _0804EF28 @ =0x040000D4
	ldr r0, [r4, #0xc]
	str r0, [r1]
	ldr r0, [r5, #0xc]
	str r0, [r1, #4]
	ldr r0, _0804EF34 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EF12:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804EF18: .4byte gCurrentPinballGame
_0804EF1C: .4byte 0x00000729
_0804EF20: .4byte 0x00000734
_0804EF24: .4byte gUnknown_086B0AF0
_0804EF28: .4byte 0x040000D4
_0804EF2C: .4byte 0x80000020
_0804EF30: .4byte 0x80000040
_0804EF34: .4byte 0x80000030

	thumb_func_start sub_4EF38
sub_4EF38: @ 0x0804EF38
	push {r4, r5, lr}
	movs r3, #0
	ldr r0, _0804EF58 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #2
	bls _0804EF60
	ldr r0, _0804EF5C @ =0x0000072A
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	b _0804EF6E
	.align 2, 0
_0804EF58: .4byte gCurrentPinballGame
_0804EF5C: .4byte 0x0000072A
_0804EF60:
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _0804EF6E
	ldr r1, _0804EF98 @ =0x0000072A
	adds r0, r2, r1
	strb r3, [r0]
_0804EF6E:
	ldr r1, [r5]
	ldr r2, _0804EF98 @ =0x0000072A
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0804EFA0
	ldr r4, _0804EF9C @ =0x000001A5
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r2, #0xa
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	b _0804EFAC
	.align 2, 0
_0804EF98: .4byte 0x0000072A
_0804EF9C: .4byte 0x000001A5
_0804EFA0:
	ldr r4, _0804F014 @ =0x000001A5
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x11
_0804EFAC:
	lsrs r3, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r2, _0804F018 @ =gUnknown_086B0B20
	adds r3, r0, r2
	adds r4, r2, #0
	adds r4, #0x40
	ldr r0, [r5]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xef
	bgt _0804EFD6
	ldr r1, _0804F01C @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x40]
	str r0, [r1, #4]
	ldr r0, _0804F020 @ =0x80000050
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804EFD6:
	ldr r2, _0804F01C @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	ldr r1, _0804F020 @ =0x80000050
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x58
	ble _0804F00C
	ldr r0, [r3, #0xc]
	str r0, [r2]
	ldr r0, [r4, #0xc]
	str r0, [r2, #4]
	ldr r0, _0804F024 @ =0x80000030
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804F00C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F014: .4byte 0x000001A5
_0804F018: .4byte gUnknown_086B0B20
_0804F01C: .4byte 0x040000D4
_0804F020: .4byte 0x80000050
_0804F024: .4byte 0x80000030

	thumb_func_start sub_4F028
sub_4F028: @ 0x0804F028
	push {r4, r5, lr}
	movs r3, #0
	ldr r1, _0804F0CC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r4, _0804F0D0 @ =0x00000731
	adds r0, r0, r4
	strb r3, [r0]
	ldr r2, [r1]
	ldr r5, _0804F0D4 @ =0x0000072F
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #1
	ble _0804F056
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _0804F056
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
_0804F056:
	ldr r2, [r5]
	ldr r1, _0804F0D0 @ =0x00000731
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0804F074
	ldr r5, _0804F0D8 @ =0x00000734
	adds r0, r2, r5
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0804F074:
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r4, _0804F0DC @ =gUnknown_086B0B94
	adds r3, r0, r4
	adds r5, r4, #0
	adds r5, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0804F0E0 @ =0x00000107
	cmp r1, r0
	bgt _0804F09E
	ldr r1, _0804F0E4 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r4, #0x20]
	str r0, [r1, #4]
	ldr r0, _0804F0E8 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F09E:
	ldr r0, _0804F0E4 @ =0x040000D4
	ldr r1, [r3, #4]
	str r1, [r0]
	ldr r1, [r5, #4]
	str r1, [r0, #4]
	ldr r2, _0804F0EC @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r3, #8]
	str r1, [r0]
	ldr r1, [r5, #8]
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r3, #0xc]
	str r1, [r0]
	ldr r1, [r5, #0xc]
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F0CC: .4byte gCurrentPinballGame
_0804F0D0: .4byte 0x00000731
_0804F0D4: .4byte 0x0000072F
_0804F0D8: .4byte 0x00000734
_0804F0DC: .4byte gUnknown_086B0B94
_0804F0E0: .4byte 0x00000107
_0804F0E4: .4byte 0x040000D4
_0804F0E8: .4byte 0x80000020
_0804F0EC: .4byte 0x80000040

	thumb_func_start sub_4F0F0
sub_4F0F0: @ 0x0804F0F0
	push {r4, r5, r6, r7, lr}
	ldr r5, _0804F1E8 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r0, _0804F1EC @ =0x0000071B
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r7, r5, #0
	cmp r0, #0
	bne _0804F106
	b _0804F24C
_0804F106:
	ldr r6, _0804F1F0 @ =0x0000071C
	adds r0, r4, r6
	ldrb r3, [r0]
	cmp r3, #0
	bne _0804F112
	b _0804F220
_0804F112:
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804F152
	ldr r0, _0804F1F4 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0x14
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	movs r2, #0xe3
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0804F1F8 @ =0x00000719
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r4, _0804F1FC @ =0x0000071A
	adds r0, r0, r4
	strb r1, [r0]
_0804F152:
	ldr r1, [r5]
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0x1c
	bne _0804F196
	ldr r3, _0804F200 @ =0x000005F6
	adds r1, r1, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _0804F16E
	adds r0, r2, #1
	strb r0, [r1]
_0804F16E:
	ldr r1, [r5]
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r2]
	ldr r2, _0804F204 @ =0x040000D4
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #5
	ldr r1, _0804F208 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804F20C @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0804F210 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804F196:
	adds r5, r7, #0
	ldr r0, [r5]
	ldr r4, _0804F1F0 @ =0x0000071C
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x28
	bne _0804F1AC
	ldr r0, _0804F214 @ =gMPlayInfo_SE1
	ldr r1, _0804F218 @ =gUnknown_0869F664
	bl MPlayStart
_0804F1AC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _0804F1C2
	ldr r0, _0804F1F4 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xac
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
_0804F1C2:
	ldr r2, [r7]
	ldr r3, _0804F21C @ =gUnknown_086B0E20
	adds r0, r2, r4
	ldrb r1, [r0]
	lsrs r1, r1, #1
	movs r0, #0x1e
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r2, #0x6e
	strb r0, [r2]
	ldr r1, [r7]
	adds r1, r1, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0804F24C
	.align 2, 0
_0804F1E8: .4byte gCurrentPinballGame
_0804F1EC: .4byte 0x0000071B
_0804F1F0: .4byte 0x0000071C
_0804F1F4: .4byte gMain
_0804F1F8: .4byte 0x00000719
_0804F1FC: .4byte 0x0000071A
_0804F200: .4byte 0x000005F6
_0804F204: .4byte 0x040000D4
_0804F208: .4byte gUnknown_08137E14
_0804F20C: .4byte 0x05000220
_0804F210: .4byte 0x80000010
_0804F214: .4byte gMPlayInfo_SE1
_0804F218: .4byte gUnknown_0869F664
_0804F21C: .4byte gUnknown_086B0E20
_0804F220:
	strb r3, [r1]
	ldr r2, [r5]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804F246
	ldr r4, _0804F254 @ =0x0000071A
	adds r0, r2, r4
	strb r3, [r0]
	subs r4, #1
	adds r0, r2, r4
	strb r3, [r0]
	subs r4, #1
	adds r0, r2, r4
	strb r3, [r0]
_0804F246:
	ldr r0, [r5]
	adds r0, r0, r1
	strb r3, [r0]
_0804F24C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F254: .4byte 0x0000071A

	thumb_func_start sub_4F258
sub_4F258: @ 0x0804F258
	push {r4, r5, r6, r7, lr}
	movs r1, #0
	ldr r0, _0804F2A8 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r2, #0xe3
	lsls r2, r2, #3
	adds r5, r0, r2
	ldr r4, _0804F2AC @ =gUnknown_086B0B70
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _0804F2B0 @ =0x040000D4
	ldr r6, _0804F2B4 @ =0x80000020
_0804F270:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r1, r0
	adds r1, r1, r7
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, [r1]
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #2
	ble _0804F270
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F2A8: .4byte gCurrentPinballGame
_0804F2AC: .4byte gUnknown_086B0B70
_0804F2B0: .4byte 0x040000D4
_0804F2B4: .4byte 0x80000020

	thumb_func_start sub_4F2B8
sub_4F2B8: @ 0x0804F2B8
	push {r4, r5, lr}
	ldr r0, _0804F2EC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _0804F2F0 @ =0x0000072B
	adds r3, r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _0804F306
	ldr r5, _0804F2F4 @ =0x0000072C
	adds r2, r1, r5
	ldrh r4, [r2]
	ldr r0, _0804F2F8 @ =gUnknown_086B08C4
	movs r1, #0
	ldrsb r1, [r3, r1]
	subs r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r4, r0
	bge _0804F2FC
	adds r0, r4, #1
	strh r0, [r2]
	b _0804F306
	.align 2, 0
_0804F2EC: .4byte gCurrentPinballGame
_0804F2F0: .4byte 0x0000072B
_0804F2F4: .4byte 0x0000072C
_0804F2F8: .4byte gUnknown_086B08C4
_0804F2FC:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
_0804F306:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_4F30C
sub_4F30C: @ 0x0804F30C
	push {r4, r5, lr}
	sub sp, #8
	ldr r1, _0804F33C @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r3, _0804F340 @ =0x0000072B
	adds r0, r2, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r4, r1, #0
	cmp r3, #0
	bne _0804F348
	mov r1, sp
	ldr r5, _0804F344 @ =0x00000734
	adds r2, r2, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	lsls r0, r0, #1
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r1, #2]
	mov r0, sp
	strh r3, [r0, #4]
	b _0804F396
	.align 2, 0
_0804F33C: .4byte gCurrentPinballGame
_0804F340: .4byte 0x0000072B
_0804F344: .4byte 0x00000734
_0804F348:
	cmp r3, #1
	bne _0804F36C
	mov r1, sp
	movs r0, #3
	strh r0, [r1]
	ldr r0, _0804F368 @ =0x00000734
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r1, #2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r1, #4]
	b _0804F396
	.align 2, 0
_0804F368: .4byte 0x00000734
_0804F36C:
	cmp r3, #2
	bne _0804F38C
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, sp
	ldr r5, _0804F388 @ =0x00000734
	adds r0, r2, r5
	ldrh r0, [r0]
	adds r0, #2
	strh r0, [r1, #4]
	b _0804F396
	.align 2, 0
_0804F388: .4byte 0x00000734
_0804F38C:
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
_0804F396:
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _0804F4A8 @ =gUnknown_086B0CB8
	adds r3, r0, r2
	adds r5, r2, #0
	adds r5, #0x30
	ldr r0, [r4]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #0x2a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F3CA
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x30]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F3CA:
	ldr r0, [r4]
	adds r4, r0, #0
	adds r4, #0x6a
	ldrh r0, [r4]
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F3EC
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F3EC:
	mov r0, sp
	movs r3, #2
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, #0
	adds r1, #0x3c
	adds r3, r0, r1
	adds r5, r2, #0
	adds r5, #0x6c
	ldrh r0, [r4]
	subs r0, #0x3a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F41E
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x6c]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F41E:
	ldrh r0, [r4]
	subs r0, #0x42
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F43A
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F43A:
	mov r0, sp
	movs r5, #4
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, #0
	adds r1, #0x78
	adds r3, r0, r1
	adds r5, r2, #0
	adds r5, #0xa8
	ldrh r0, [r4]
	subs r0, #0x4a
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F46C
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r5]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F46C:
	ldrh r0, [r4]
	subs r0, #0x52
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bhi _0804F488
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F488:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x59
	ble _0804F4A0
	ldr r1, _0804F4AC @ =0x040000D4
	ldr r0, [r3, #8]
	str r0, [r1]
	ldr r0, [r5, #8]
	str r0, [r1, #4]
	ldr r0, _0804F4B0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F4A0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F4A8: .4byte gUnknown_086B0CB8
_0804F4AC: .4byte 0x040000D4
_0804F4B0: .4byte 0x80000030

	thumb_func_start sub_4F4B4
sub_4F4B4: @ 0x0804F4B4
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0804F4E8 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	adds r6, r0, #0
	cmp r1, #2
	bgt _0804F53C
	ldr r1, _0804F4EC @ =0x0000072E
	adds r0, r2, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _0804F4F4
	mov r1, sp
	ldr r4, _0804F4F0 @ =0x00000734
	adds r0, r2, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	strh r0, [r1]
	mov r0, sp
	strh r3, [r0, #2]
	strh r3, [r0, #4]
	b _0804F562
	.align 2, 0
_0804F4E8: .4byte gCurrentPinballGame
_0804F4EC: .4byte 0x0000072E
_0804F4F0: .4byte 0x00000734
_0804F4F4:
	cmp r3, #1
	bne _0804F514
	mov r1, sp
	movs r0, #3
	strh r0, [r1]
	ldr r3, _0804F510 @ =0x00000734
	adds r2, r2, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r1, #2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	b _0804F560
	.align 2, 0
_0804F510: .4byte 0x00000734
_0804F514:
	cmp r3, #2
	bne _0804F530
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, sp
	ldr r3, _0804F52C @ =0x00000734
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #2
	b _0804F560
	.align 2, 0
_0804F52C: .4byte 0x00000734
_0804F530:
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	b _0804F562
_0804F53C:
	mov r1, sp
	ldr r4, _0804F648 @ =0x00000739
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r3, _0804F64C @ =0x0000073A
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	adds r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_0804F560:
	strh r0, [r1, #4]
_0804F562:
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0804F650 @ =gUnknown_086B0C04
	mov ip, r3
	adds r3, r0, r3
	mov r4, ip
	adds r4, #0x30
	ldr r0, [r6]
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0804F654 @ =0x00000107
	cmp r1, r0
	bgt _0804F598
	ldr r1, _0804F658 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	mov r2, ip
	ldr r0, [r2, #0x30]
	str r0, [r1, #4]
	ldr r0, _0804F65C @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F598:
	ldr r2, _0804F658 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	ldr r5, _0804F65C @ =0x80000030
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r6]
	adds r6, r0, #0
	adds r6, #0x6a
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0x78
	ble _0804F5FE
	mov r0, sp
	movs r4, #2
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x3c
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0x6c
	ldr r0, [r3]
	str r0, [r2]
	mov r1, ip
	ldr r0, [r1, #0x6c]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
_0804F5FE:
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0x88
	ble _0804F640
	mov r0, sp
	movs r4, #4
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x78
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0xa8
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
_0804F640:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F648: .4byte 0x00000739
_0804F64C: .4byte 0x0000073A
_0804F650: .4byte gUnknown_086B0C04
_0804F654: .4byte 0x00000107
_0804F658: .4byte 0x040000D4
_0804F65C: .4byte 0x80000030

	thumb_func_start sub_4F660
sub_4F660: @ 0x0804F660
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0804F694 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	adds r5, r0, #0
	cmp r1, #2
	bgt _0804F6E8
	ldr r1, _0804F698 @ =0x0000072F
	adds r0, r2, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _0804F6A0
	mov r1, sp
	ldr r4, _0804F69C @ =0x00000734
	adds r0, r2, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	strh r0, [r1]
	mov r0, sp
	strh r3, [r0, #2]
	strh r3, [r0, #4]
	b _0804F70E
	.align 2, 0
_0804F694: .4byte gCurrentPinballGame
_0804F698: .4byte 0x0000072F
_0804F69C: .4byte 0x00000734
_0804F6A0:
	cmp r3, #1
	bne _0804F6C0
	mov r1, sp
	movs r0, #3
	strh r0, [r1]
	ldr r3, _0804F6BC @ =0x00000734
	adds r2, r2, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r1, #2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	b _0804F70C
	.align 2, 0
_0804F6BC: .4byte 0x00000734
_0804F6C0:
	cmp r3, #2
	bne _0804F6DC
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, sp
	ldr r3, _0804F6D8 @ =0x00000734
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #2
	b _0804F70C
	.align 2, 0
_0804F6D8: .4byte 0x00000734
_0804F6DC:
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	b _0804F70E
_0804F6E8:
	mov r1, sp
	ldr r4, _0804F7F8 @ =0x00000736
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r3, _0804F7FC @ =0x00000737
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	adds r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_0804F70C:
	strh r0, [r1, #4]
_0804F70E:
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0804F800 @ =gUnknown_086B0D6C
	mov ip, r3
	adds r3, r0, r3
	mov r4, ip
	adds r4, #0x30
	ldr r0, [r5]
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0804F804 @ =0x00000107
	cmp r1, r0
	bgt _0804F744
	ldr r1, _0804F808 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	mov r2, ip
	ldr r0, [r2, #0x30]
	str r0, [r1, #4]
	ldr r0, _0804F80C @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804F744:
	ldr r2, _0804F808 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	ldr r6, _0804F80C @ =0x80000030
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r5, r0, #0
	adds r5, #0x6a
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x78
	ble _0804F7AC
	mov r0, sp
	movs r4, #2
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x3c
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0x6c
	ldr r0, [r3]
	str r0, [r2]
	mov r1, ip
	ldr r0, [r1, #0x6c]
	str r0, [r2, #4]
	ldr r1, _0804F810 @ =0x80000020
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
_0804F7AC:
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x88
	ble _0804F7F0
	mov r0, sp
	movs r4, #4
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x78
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0xa8
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4]
	str r0, [r2, #4]
	ldr r0, _0804F810 @ =0x80000020
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
_0804F7F0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F7F8: .4byte 0x00000736
_0804F7FC: .4byte 0x00000737
_0804F800: .4byte gUnknown_086B0D6C
_0804F804: .4byte 0x00000107
_0804F808: .4byte 0x040000D4
_0804F80C: .4byte 0x80000030
_0804F810: .4byte 0x80000020

	thumb_func_start sub_4F814
sub_4F814: @ 0x0804F814
	push {r4, r5, r6, lr}
	ldr r6, _0804F94C @ =gCurrentPinballGame
	ldr r4, [r6]
	ldr r0, _0804F950 @ =0x0000070C
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x14
	bl __udivsi3
	ldr r1, _0804F954 @ =0x00000734
	adds r4, r4, r1
	strh r0, [r4]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	bl sub_50710
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x53
	ble _0804F850
	bl sub_50000
_0804F850:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x12
	ble _0804F860
	bl sub_500B4
_0804F860:
	ldr r0, [r6]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #0x38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xba
	bhi _0804F874
	bl sub_505A4
_0804F874:
	bl sub_4F0F0
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x6f
	bgt _0804F888
	bl sub_506B0
_0804F888:
	ldr r0, [r6]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xbd
	bhi _0804F89C
	bl sub_504C0
_0804F89C:
	ldr r0, [r6]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb7
	bhi _0804F8B4
	bl sub_4FB08
	bl sub_4F95C
_0804F8B4:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x68
	ble _0804F8C8
	bl sub_50154
	bl sub_5030C
_0804F8C8:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x48
	ble _0804F8D8
	bl sub_4FE6C
_0804F8D8:
	bl sub_4F2B8
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x6e
	ble _0804F8EC
	bl sub_4FAC0
_0804F8EC:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xb2
	ble _0804F904
	bl sub_4FBA4
	bl sub_4FC7C
	bl sub_4F9F0
_0804F904:
	ldr r0, [r6]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xca
	ble _0804F914
	bl sub_4FD88
_0804F914:
	ldr r0, [r6]
	adds r0, #0x6a
	ldrh r0, [r0]
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xad
	bhi _0804F928
	bl sub_507D4
_0804F928:
	ldr r0, [r6]
	ldr r1, _0804F958 @ =0x00000724
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, #0
	beq _0804F944
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804F944
	subs r0, r1, #1
	strh r0, [r2]
_0804F944:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F94C: .4byte gCurrentPinballGame
_0804F950: .4byte 0x0000070C
_0804F954: .4byte 0x00000734
_0804F958: .4byte 0x00000724

	thumb_func_start sub_4F95C
sub_4F95C: @ 0x0804F95C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0804F9DC @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r1, _0804F9E0 @ =0x0000070E
	adds r0, r4, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r0, r5, #0
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	lsrs r6, r0, #0x10
	adds r0, r5, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	lsrs r7, r0, #0x10
	adds r4, #0x6a
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x24
	ble _0804F9D6
	lsls r0, r6, #0x10
	asrs r0, r0, #0xc
	ldr r3, _0804F9E4 @ =gUnknown_086B0E9C
	adds r5, r0, r3
	adds r4, r3, #0
	adds r4, #0xa0
	ldr r1, _0804F9E8 @ =0x040000D4
	ldr r0, [r5]
	str r0, [r1]
	ldr r0, [r4]
	str r0, [r1, #4]
	ldr r2, _0804F9EC @ =0x80000010
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5, #4]
	str r0, [r1]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	lsls r0, r7, #0x10
	asrs r0, r0, #0xc
	adds r5, r0, r3
	ldr r0, [r5, #8]
	str r0, [r1]
	ldr r0, [r4, #8]
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5, #0xc]
	str r0, [r1]
	ldr r0, [r4, #0xc]
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
_0804F9D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F9DC: .4byte gCurrentPinballGame
_0804F9E0: .4byte 0x0000070E
_0804F9E4: .4byte gUnknown_086B0E9C
_0804F9E8: .4byte 0x040000D4
_0804F9EC: .4byte 0x80000010

	thumb_func_start sub_4F9F0
sub_4F9F0: @ 0x0804F9F0
	push {r4, r5, lr}
	ldr r1, _0804FA9C @ =gUnknown_086B0E60
	ldr r4, _0804FAA0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _0804FAA4 @ =0x00000716
	adds r3, r0, r2
	ldrb r2, [r3]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	cmp r2, #0
	beq _0804FA2C
	subs r0, r2, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r1, _0804FAA4 @ =0x00000716
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804FA2C
	movs r0, SE_UNKNOWN_0x73
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1, #0x3c]
	movs r0, #7
	bl sub_11B0
_0804FA2C:
	ldr r0, _0804FAA0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0804FAA8 @ =0x00000717
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r3, r0, #4
	subs r3, r3, r0
	lsls r3, r3, #2
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _0804FAAC @ =gUnknown_086B108C
	adds r2, r2, r0
	adds r2, r3, r2
	adds r0, #0x28
	adds r3, r3, r0
	ldr r0, _0804FAB0 @ =0x040000D4
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r3]
	str r1, [r0, #4]
	ldr r1, _0804FAB4 @ =0x80000010
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #4]
	str r1, [r0]
	ldr r1, [r3, #4]
	str r1, [r0, #4]
	ldr r5, _0804FAB8 @ =0x80000020
	str r5, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #8]
	str r1, [r0]
	ldr r1, [r3, #8]
	str r1, [r0, #4]
	ldr r4, _0804FABC @ =0x80000030
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #0xc]
	str r1, [r0]
	ldr r1, [r3, #0xc]
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #0x10]
	str r1, [r0]
	ldr r1, [r3, #0x10]
	str r1, [r0, #4]
	str r5, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FA9C: .4byte gUnknown_086B0E60
_0804FAA0: .4byte gCurrentPinballGame
_0804FAA4: .4byte 0x00000716
_0804FAA8: .4byte 0x00000717
_0804FAAC: .4byte gUnknown_086B108C
_0804FAB0: .4byte 0x040000D4
_0804FAB4: .4byte 0x80000010
_0804FAB8: .4byte 0x80000020
_0804FABC: .4byte 0x80000030

	thumb_func_start sub_4FAC0
sub_4FAC0: @ 0x0804FAC0
	push {r4, lr}
	ldr r0, _0804FAF8 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	ldr r3, _0804FAFC @ =gUnknown_086B1104
	adds r2, r2, r3
	ldr r0, _0804FB00 @ =0x040000D4
	ldr r1, [r2]
	str r1, [r0]
	ldr r1, [r3, #0x18]
	str r1, [r0, #4]
	ldr r4, _0804FB04 @ =0x80000020
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r2, #4]
	str r1, [r0]
	ldr r1, [r3, #0x1c]
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r0, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804FAF8: .4byte gCurrentPinballGame
_0804FAFC: .4byte gUnknown_086B1104
_0804FB00: .4byte 0x040000D4
_0804FB04: .4byte 0x80000020

	thumb_func_start sub_4FB08
sub_4FB08: @ 0x0804FB08
	push {r4, r5, lr}
	ldr r0, _0804FB88 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x3f
	ands r0, r1
	lsrs r0, r0, #4
	lsls r0, r0, #4
	ldr r2, _0804FB8C @ =gUnknown_086B0F4C
	adds r3, r0, r2
	adds r5, r2, #0
	adds r5, #0x40
	ldr r4, _0804FB90 @ =gCurrentPinballGame
	ldr r0, [r4]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xbf
	bgt _0804FB3C
	ldr r1, _0804FB94 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x40]
	str r0, [r1, #4]
	ldr r0, _0804FB98 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FB3C:
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x6a
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xc7
	bgt _0804FB5A
	ldr r1, _0804FB94 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _0804FB9C @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FB5A:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xcf
	bgt _0804FB72
	ldr r1, _0804FB94 @ =0x040000D4
	ldr r0, [r3, #8]
	str r0, [r1]
	ldr r0, [r5, #8]
	str r0, [r1, #4]
	ldr r0, _0804FBA0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FB72:
	ldr r1, _0804FB94 @ =0x040000D4
	ldr r0, [r3, #0xc]
	str r0, [r1]
	ldr r0, [r5, #0xc]
	str r0, [r1, #4]
	ldr r0, _0804FBA0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FB88: .4byte gMain
_0804FB8C: .4byte gUnknown_086B0F4C
_0804FB90: .4byte gCurrentPinballGame
_0804FB94: .4byte 0x040000D4
_0804FB98: .4byte 0x80000020
_0804FB9C: .4byte 0x80000040
_0804FBA0: .4byte 0x80000030

	thumb_func_start sub_4FBA4
sub_4FBA4: @ 0x0804FBA4
	push {r4, r5, r6, r7, lr}
	ldr r7, _0804FC60 @ =gCurrentPinballGame
	ldr r5, [r7]
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804FC0A
	ldr r6, _0804FC64 @ =0x00000721
	adds r0, r5, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r4, _0804FC68 @ =0x0000071D
	adds r5, r5, r4
	adds r5, r5, r0
	ldrb r0, [r1]
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x12
	bl __udivsi3
	movs r1, #1
	subs r1, r1, r0
	strb r1, [r5]
	ldr r0, [r7]
	ldr r2, _0804FC6C @ =0x00000722
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, r4
	adds r1, r4, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r1, [r7]
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0804FC0A:
	movs r1, #0
	ldr r0, [r7]
	ldr r2, _0804FC68 @ =0x0000071D
	adds r7, r0, r2
	ldr r6, _0804FC70 @ =gUnknown_086B1124
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldr r4, _0804FC74 @ =0x040000D4
	ldr r5, _0804FC78 @ =0x80000020
_0804FC1E:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r2, r3, #3
	subs r2, r2, r3
	lsls r2, r2, #3
	adds r0, r7, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, r2, r1
	add r2, ip
	ldr r0, [r1]
	str r0, [r4]
	ldr r0, [r2]
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [r1, #4]
	str r0, [r4]
	ldr r0, [r2, #4]
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0804FC1E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC60: .4byte gCurrentPinballGame
_0804FC64: .4byte 0x00000721
_0804FC68: .4byte 0x0000071D
_0804FC6C: .4byte 0x00000722
_0804FC70: .4byte gUnknown_086B1124
_0804FC74: .4byte 0x040000D4
_0804FC78: .4byte 0x80000020

	thumb_func_start sub_4FC7C
sub_4FC7C: @ 0x0804FC7C
	push {r4, r5, r6, r7, lr}
	ldr r5, _0804FCE4 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r1, _0804FCE8 @ =0x00000714
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0804FD26
	ldr r2, _0804FCEC @ =0x00000715
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804FCF8
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x12
	bl __udivsi3
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0804FCF0 @ =0x00000711
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _0804FCF4 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r5]
	adds r3, #3
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0804FD26
	.align 2, 0
_0804FCE4: .4byte gCurrentPinballGame
_0804FCE8: .4byte 0x00000714
_0804FCEC: .4byte 0x00000715
_0804FCF0: .4byte 0x00000711
_0804FCF4: .4byte 0x00000713
_0804FCF8:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0804FD70 @ =0x00000711
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, r0, r2
	ldrb r1, [r2]
	ldr r2, _0804FD74 @ =0x00000713
	adds r0, r0, r2
	strb r1, [r0]
_0804FD26:
	movs r2, #0
	ldr r0, _0804FD78 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r5, r0, r3
	ldr r4, _0804FD7C @ =gUnknown_086B1300
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _0804FD80 @ =0x040000D4
	ldr r6, _0804FD84 @ =0x80000020
_0804FD3C:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r2, r0
	adds r2, r2, r7
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, [r2]
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _0804FD3C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FD70: .4byte 0x00000711
_0804FD74: .4byte 0x00000713
_0804FD78: .4byte gCurrentPinballGame
_0804FD7C: .4byte gUnknown_086B1300
_0804FD80: .4byte 0x040000D4
_0804FD84: .4byte 0x80000020

	thumb_func_start sub_4FD88
sub_4FD88: @ 0x0804FD88
	push {r4, r5, lr}
	ldr r0, _0804FDA4 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r2, _0804FDA8 @ =0x00000724
	adds r1, r3, r2
	ldrh r2, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r5, r0, #0
	cmp r2, r1
	bls _0804FDB0
	ldr r0, _0804FDAC @ =0x00000726
	adds r1, r3, r0
	b _0804FDC6
	.align 2, 0
_0804FDA4: .4byte gCurrentPinballGame
_0804FDA8: .4byte 0x00000724
_0804FDAC: .4byte 0x00000726
_0804FDB0:
	cmp r2, #0
	beq _0804FDEC
	adds r0, r3, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0804FDD0
	ldr r2, _0804FDCC @ =0x00000726
	adds r1, r3, r2
_0804FDC6:
	movs r0, #1
	strb r0, [r1]
	b _0804FDF2
	.align 2, 0
_0804FDCC: .4byte 0x00000726
_0804FDD0:
	ldr r0, _0804FDE4 @ =gMain
	ldr r0, [r0, #0x50]
	movs r1, #0xf
	ands r0, r1
	lsrs r0, r0, #3
	ldr r2, _0804FDE8 @ =0x00000726
	adds r1, r3, r2
	strb r0, [r1]
	b _0804FDF2
	.align 2, 0
_0804FDE4: .4byte gMain
_0804FDE8: .4byte 0x00000726
_0804FDEC:
	ldr r1, _0804FE54 @ =0x00000726
	adds r0, r3, r1
	strb r2, [r0]
_0804FDF2:
	ldr r0, [r5]
	ldr r2, _0804FE54 @ =0x00000726
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #4
	ldr r1, _0804FE58 @ =gUnknown_086B11CC
	adds r3, r0, r1
	adds r4, r1, #0
	adds r4, #0x20
	ldr r2, _0804FE5C @ =0x040000D4
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r1, #0x20]
	str r0, [r2, #4]
	ldr r1, _0804FE60 @ =0x80000070
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd7
	ble _0804FE4C
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	ldr r0, _0804FE64 @ =0x80000060
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #0xc]
	str r0, [r2]
	ldr r0, [r4, #0xc]
	str r0, [r2, #4]
	ldr r0, _0804FE68 @ =0x80000020
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804FE4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE54: .4byte 0x00000726
_0804FE58: .4byte gUnknown_086B11CC
_0804FE5C: .4byte 0x040000D4
_0804FE60: .4byte 0x80000070
_0804FE64: .4byte 0x80000060
_0804FE68: .4byte 0x80000020

	thumb_func_start sub_4FE6C
sub_4FE6C: @ 0x0804FE6C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _0804FE94 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r3, _0804FE98 @ =0x0000072B
	adds r0, r2, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r7, r1, #0
	cmp r3, #0
	bne _0804FEA0
	mov r1, sp
	ldr r4, _0804FE9C @ =0x00000734
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sp
	strh r3, [r0, #2]
	strh r3, [r0, #4]
	b _0804FEE2
	.align 2, 0
_0804FE94: .4byte gCurrentPinballGame
_0804FE98: .4byte 0x0000072B
_0804FE9C: .4byte 0x00000734
_0804FEA0:
	cmp r3, #1
	bne _0804FEBC
	mov r0, sp
	strh r3, [r0]
	mov r1, sp
	ldr r0, _0804FEB8 @ =0x00000734
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r1, #2]
	ldrh r0, [r2]
	strh r0, [r1, #4]
	b _0804FEE2
	.align 2, 0
_0804FEB8: .4byte 0x00000734
_0804FEBC:
	cmp r3, #2
	bne _0804FED8
	mov r0, sp
	strh r3, [r0]
	strh r3, [r0, #2]
	mov r1, sp
	ldr r3, _0804FED4 @ =0x00000734
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #1
	strh r0, [r1, #4]
	b _0804FEE2
	.align 2, 0
_0804FED4: .4byte 0x00000734
_0804FED8:
	mov r0, sp
	movs r1, #2
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
_0804FEE2:
	mov r0, sp
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0804FFE4 @ =gUnknown_086B13F4
	adds r2, r0, r3
	adds r6, r3, #0
	adds r6, #0x24
	ldr r0, [r7]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xef
	bgt _0804FF12
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r3, #0x24]
	str r0, [r1, #4]
	ldr r0, _0804FFEC @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FF12:
	ldr r0, [r7]
	adds r5, r0, #0
	adds r5, #0x6a
	movs r4, #0
	ldrsh r0, [r5, r4]
	cmp r0, #0xf7
	bgt _0804FF30
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, [r6, #4]
	str r0, [r1, #4]
	ldr r0, _0804FFF0 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FF30:
	movs r0, #0
	ldrsh r4, [r5, r0]
	cmp r4, #0x58
	ble _0804FF7C
	mov r0, sp
	movs r2, #2
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x3c
	adds r2, r0, r1
	adds r6, r3, #0
	adds r6, #0x60
	cmp r4, #0xfd
	bgt _0804FF62
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r3, #0x60]
	str r0, [r1, #4]
	ldr r0, _0804FFEC @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FF62:
	movs r3, #0
	ldrsh r1, [r5, r3]
	ldr r0, _0804FFF4 @ =0x00000105
	cmp r1, r0
	bgt _0804FF7C
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, [r6, #4]
	str r0, [r1, #4]
	ldr r0, _0804FFEC @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FF7C:
	ldr r0, [r7]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0x60
	ble _0804FFDA
	mov r0, sp
	movs r2, #4
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0804FFF8 @ =gUnknown_086B146C
	adds r2, r0, r3
	adds r6, r3, #0
	adds r6, #0x24
	ldr r0, _0804FFFC @ =0x00000107
	cmp r4, r0
	bgt _0804FFB2
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, [r3, #0x24]
	str r0, [r1, #4]
	ldr r0, _0804FFEC @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804FFB2:
	ldr r1, _0804FFE8 @ =0x040000D4
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, [r6, #4]
	str r0, [r1, #4]
	ldr r3, _0804FFEC @ =0x80000020
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r7]
	adds r0, #0x6a
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x68
	ble _0804FFDA
	ldr r0, [r2, #8]
	str r0, [r1]
	ldr r0, [r6, #8]
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
_0804FFDA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FFE4: .4byte gUnknown_086B13F4
_0804FFE8: .4byte 0x040000D4
_0804FFEC: .4byte 0x80000020
_0804FFF0: .4byte 0x80000030
_0804FFF4: .4byte 0x00000105
_0804FFF8: .4byte gUnknown_086B146C
_0804FFFC: .4byte 0x00000107

	thumb_func_start sub_50000
sub_50000: @ 0x08050000
	push {r4, r5, r6, lr}
	movs r1, #0
	ldr r6, _0805009C @ =gCurrentPinballGame
	ldr r2, [r6]
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08050026
	ldr r1, _080500A0 @ =0x00000734
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_08050026:
	lsls r0, r1, #0x10
	asrs r0, r0, #0xc
	ldr r3, _080500A4 @ =gUnknown_086B11FC
	adds r4, r0, r3
	adds r5, r3, #0
	adds r5, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xff
	bgt _0805004E
	ldr r1, _080500A8 @ =0x040000D4
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r3, #0x20]
	str r0, [r1, #4]
	ldr r0, _080500AC @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805004E:
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x6a
	ldrh r0, [r2]
	subs r0, #0x61
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa6
	bhi _08050070
	ldr r1, _080500A8 @ =0x040000D4
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _080500B0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050070:
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x67
	ble _08050094
	ldr r0, _080500A8 @ =0x040000D4
	ldr r1, [r4, #8]
	str r1, [r0]
	ldr r1, [r5, #8]
	str r1, [r0, #4]
	ldr r2, _080500B0 @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, [r4, #0xc]
	str r1, [r0]
	ldr r1, [r5, #0xc]
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
_08050094:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805009C: .4byte gCurrentPinballGame
_080500A0: .4byte 0x00000734
_080500A4: .4byte gUnknown_086B11FC
_080500A8: .4byte 0x040000D4
_080500AC: .4byte 0x80000020
_080500B0: .4byte 0x80000040

	thumb_func_start sub_500B4
sub_500B4: @ 0x080500B4
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _0805013C @ =gCurrentPinballGame
	ldr r2, [r5]
	ldr r3, _08050140 @ =0x00000729
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080500D8
	ldr r1, _08050144 @ =0x00000734
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_080500D8:
	lsls r0, r1, #0x10
	asrs r0, r0, #0xc
	ldr r1, _08050148 @ =gUnknown_086B122C
	adds r3, r0, r1
	adds r4, r1, #0
	adds r4, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc2
	bgt _08050100
	ldr r1, _0805014C @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
	ldr r0, _08050150 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050100:
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x6a
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x1e
	ble _0805011E
	ldr r1, _0805014C @ =0x040000D4
	ldr r0, [r3, #8]
	str r0, [r1]
	ldr r0, [r4, #8]
	str r0, [r1, #4]
	ldr r0, _08050150 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805011E:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x26
	ble _08050136
	ldr r1, _0805014C @ =0x040000D4
	ldr r0, [r3, #0xc]
	str r0, [r1]
	ldr r0, [r4, #0xc]
	str r0, [r1, #4]
	ldr r0, _08050150 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050136:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805013C: .4byte gCurrentPinballGame
_08050140: .4byte 0x00000729
_08050144: .4byte 0x00000734
_08050148: .4byte gUnknown_086B122C
_0805014C: .4byte 0x040000D4
_08050150: .4byte 0x80000040

	thumb_func_start sub_50154
sub_50154: @ 0x08050154
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0805018C @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	adds r6, r0, #0
	cmp r1, #2
	bgt _080501E0
	ldr r1, _08050190 @ =0x0000072E
	adds r0, r2, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _08050198
	mov r1, sp
	ldr r4, _08050194 @ =0x00000734
	adds r2, r2, r4
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r1, #2]
	mov r0, sp
	strh r3, [r0, #4]
	b _08050206
	.align 2, 0
_0805018C: .4byte gCurrentPinballGame
_08050190: .4byte 0x0000072E
_08050194: .4byte 0x00000734
_08050198:
	cmp r3, #1
	bne _080501B8
	mov r1, sp
	movs r0, #3
	strh r0, [r1]
	ldr r0, _080501B4 @ =0x00000734
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r1, #2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	b _08050204
	.align 2, 0
_080501B4: .4byte 0x00000734
_080501B8:
	cmp r3, #2
	bne _080501D4
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, sp
	ldr r4, _080501D0 @ =0x00000734
	adds r0, r2, r4
	ldrh r0, [r0]
	adds r0, #2
	b _08050204
	.align 2, 0
_080501D0: .4byte 0x00000734
_080501D4:
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	b _08050206
_080501E0:
	mov r1, sp
	ldr r3, _080502F0 @ =0x00000739
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r4, _080502F4 @ =0x0000073A
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	adds r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_08050204:
	strh r0, [r1, #4]
_08050206:
	mov r0, sp
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080502F8 @ =gUnknown_086B1340
	mov ip, r1
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0x30
	ldr r0, [r6]
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080502FC @ =0x00000107
	cmp r1, r0
	bgt _0805023C
	ldr r1, _08050300 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	mov r2, ip
	ldr r0, [r2, #0x30]
	str r0, [r1, #4]
	ldr r0, _08050304 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805023C:
	ldr r2, _08050300 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	ldr r5, _08050304 @ =0x80000030
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r6]
	adds r6, r0, #0
	adds r6, #0x6a
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0x78
	ble _080502A2
	mov r0, sp
	movs r4, #2
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x3c
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0x6c
	ldr r0, [r3]
	str r0, [r2]
	mov r1, ip
	ldr r0, [r1, #0x6c]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
_080502A2:
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0x88
	ble _080502E6
	mov r0, sp
	movs r4, #4
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x78
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0xa8
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r5, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	ldr r0, _08050308 @ =0x80000020
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_080502E6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080502F0: .4byte 0x00000739
_080502F4: .4byte 0x0000073A
_080502F8: .4byte gUnknown_086B1340
_080502FC: .4byte 0x00000107
_08050300: .4byte 0x040000D4
_08050304: .4byte 0x80000030
_08050308: .4byte 0x80000020

	thumb_func_start sub_5030C
sub_5030C: @ 0x0805030C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _08050340 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x13
	ldrsb r1, [r2, r1]
	adds r5, r0, #0
	cmp r1, #2
	bgt _08050394
	ldr r1, _08050344 @ =0x0000072F
	adds r0, r2, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _0805034C
	mov r1, sp
	ldr r4, _08050348 @ =0x00000734
	adds r0, r2, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	strh r0, [r1]
	mov r0, sp
	strh r3, [r0, #2]
	strh r3, [r0, #4]
	b _080503BA
	.align 2, 0
_08050340: .4byte gCurrentPinballGame
_08050344: .4byte 0x0000072F
_08050348: .4byte 0x00000734
_0805034C:
	cmp r3, #1
	bne _0805036C
	mov r1, sp
	movs r0, #3
	strh r0, [r1]
	ldr r3, _08050368 @ =0x00000734
	adds r2, r2, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r1, #2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	b _080503B8
	.align 2, 0
_08050368: .4byte 0x00000734
_0805036C:
	cmp r3, #2
	bne _08050388
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, sp
	ldr r3, _08050384 @ =0x00000734
	adds r0, r2, r3
	ldrh r0, [r0]
	adds r0, #2
	b _080503B8
	.align 2, 0
_08050384: .4byte 0x00000734
_08050388:
	mov r0, sp
	movs r1, #3
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	b _080503BA
_08050394:
	mov r1, sp
	ldr r4, _080504A4 @ =0x00000736
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r3, _080504A8 @ =0x00000737
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	adds r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_080503B8:
	strh r0, [r1, #4]
_080503BA:
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _080504AC @ =gUnknown_086B14A8
	mov ip, r3
	adds r3, r0, r3
	mov r4, ip
	adds r4, #0x30
	ldr r0, [r5]
	adds r0, #0x6a
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080504B0 @ =0x00000107
	cmp r1, r0
	bgt _080503F0
	ldr r1, _080504B4 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	mov r2, ip
	ldr r0, [r2, #0x30]
	str r0, [r1, #4]
	ldr r0, _080504B8 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_080503F0:
	ldr r2, _080504B4 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	ldr r6, _080504B8 @ =0x80000030
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r5, r0, #0
	adds r5, #0x6a
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x78
	ble _08050458
	mov r0, sp
	movs r4, #2
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x3c
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0x6c
	ldr r0, [r3]
	str r0, [r2]
	mov r1, ip
	ldr r0, [r1, #0x6c]
	str r0, [r2, #4]
	ldr r1, _080504BC @ =0x80000020
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
_08050458:
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x88
	ble _0805049C
	mov r0, sp
	movs r4, #4
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x78
	adds r3, r0, r1
	mov r4, ip
	adds r4, #0xa8
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4]
	str r0, [r2, #4]
	ldr r1, _080504BC @ =0x80000020
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #4]
	str r0, [r2]
	ldr r0, [r4, #4]
	str r0, [r2, #4]
	str r6, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r3, #8]
	str r0, [r2]
	ldr r0, [r4, #8]
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
_0805049C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080504A4: .4byte 0x00000736
_080504A8: .4byte 0x00000737
_080504AC: .4byte gUnknown_086B14A8
_080504B0: .4byte 0x00000107
_080504B4: .4byte 0x040000D4
_080504B8: .4byte 0x80000030
_080504BC: .4byte 0x80000020

	thumb_func_start sub_504C0
sub_504C0: @ 0x080504C0
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _08050584 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r4, _08050588 @ =0x00000731
	adds r0, r0, r4
	strb r3, [r0]
	ldr r2, [r1]
	ldr r5, _0805058C @ =0x0000072F
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r1, #0
	cmp r0, #1
	ble _080504EE
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _080504EE
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
_080504EE:
	ldr r2, [r6]
	ldr r1, _08050588 @ =0x00000731
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0805050C
	ldr r5, _08050590 @ =0x00000734
	adds r0, r2, r5
	ldrh r1, [r0]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0805050C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r3, _08050594 @ =gUnknown_086B12D0
	adds r4, r0, r3
	adds r5, r3, #0
	adds r5, #0x20
	adds r0, r2, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xe7
	bgt _08050534
	ldr r1, _08050598 @ =0x040000D4
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r3, #0x20]
	str r0, [r1, #4]
	ldr r0, _0805059C @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050534:
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x6a
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xef
	bgt _08050552
	ldr r1, _08050598 @ =0x040000D4
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _080505A0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050552:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x4f
	ble _0805057E
	cmp r0, #0xf7
	bgt _0805056E
	ldr r1, _08050598 @ =0x040000D4
	ldr r0, [r4, #8]
	str r0, [r1]
	ldr r0, [r5, #8]
	str r0, [r1, #4]
	ldr r0, _080505A0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805056E:
	ldr r1, _08050598 @ =0x040000D4
	ldr r0, [r4, #0xc]
	str r0, [r1]
	ldr r0, [r5, #0xc]
	str r0, [r1, #4]
	ldr r0, _0805059C @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805057E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08050584: .4byte gCurrentPinballGame
_08050588: .4byte 0x00000731
_0805058C: .4byte 0x0000072F
_08050590: .4byte 0x00000734
_08050594: .4byte gUnknown_086B12D0
_08050598: .4byte 0x040000D4
_0805059C: .4byte 0x80000030
_080505A0: .4byte 0x80000040

	thumb_func_start sub_505A4
sub_505A4: @ 0x080505A4
	push {r4, r5, lr}
	movs r3, #0
	ldr r0, _080505C8 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r4, _080505CC @ =0x00000366
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r1, #3
	bne _080505D4
	ldr r0, _080505D0 @ =0x0000072A
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	b _080505E2
	.align 2, 0
_080505C8: .4byte gCurrentPinballGame
_080505CC: .4byte 0x00000366
_080505D0: .4byte 0x0000072A
_080505D4:
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _080505E2
	ldr r1, _0805060C @ =0x0000072A
	adds r0, r2, r1
	strb r3, [r0]
_080505E2:
	ldr r1, [r5]
	ldr r2, _0805060C @ =0x0000072A
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08050614
	ldr r4, _08050610 @ =0x000001A5
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r2, #0xa
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r1, #1
	subs r0, r0, r1
	lsls r0, r0, #0x10
	b _08050620
	.align 2, 0
_0805060C: .4byte 0x0000072A
_08050610: .4byte 0x000001A5
_08050614:
	ldr r4, _0805069C @ =0x000001A5
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x11
_08050620:
	lsrs r3, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0xc
	ldr r2, _080506A0 @ =gUnknown_086B125C
	adds r3, r0, r2
	adds r4, r2, #0
	adds r4, #0x40
	ldr r0, [r5]
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xdf
	bgt _0805064A
	ldr r1, _080506A4 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x40]
	str r0, [r1, #4]
	ldr r0, _080506A8 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805064A:
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x6a
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xe7
	bgt _08050668
	ldr r1, _080506A4 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r4, #4]
	str r0, [r1, #4]
	ldr r0, _080506A8 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050668:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x47
	ble _08050694
	cmp r0, #0xef
	bgt _08050684
	ldr r1, _080506A4 @ =0x040000D4
	ldr r0, [r3, #8]
	str r0, [r1]
	ldr r0, [r4, #8]
	str r0, [r1, #4]
	ldr r0, _080506A8 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050684:
	ldr r1, _080506A4 @ =0x040000D4
	ldr r0, [r3, #0xc]
	str r0, [r1]
	ldr r0, [r4, #0xc]
	str r0, [r1, #4]
	ldr r0, _080506AC @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08050694:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805069C: .4byte 0x000001A5
_080506A0: .4byte gUnknown_086B125C
_080506A4: .4byte 0x040000D4
_080506A8: .4byte 0x80000040
_080506AC: .4byte 0x80000030

	thumb_func_start sub_506B0
sub_506B0: @ 0x080506B0
	push {r4, r5, r6, r7, lr}
	movs r1, #0
	ldr r0, _08050700 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r2, #0xe3
	lsls r2, r2, #3
	adds r5, r0, r2
	ldr r4, _08050704 @ =gUnknown_086B12AC
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _08050708 @ =0x040000D4
	ldr r6, _0805070C @ =0x80000020
_080506C8:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r1, r0
	adds r1, r1, r7
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, [r1]
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #2
	ble _080506C8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050700: .4byte gCurrentPinballGame
_08050704: .4byte gUnknown_086B12AC
_08050708: .4byte 0x040000D4
_0805070C: .4byte 0x80000020

	thumb_func_start sub_50710
sub_50710: @ 0x08050710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _08050770 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08050774 @ =0x00000346
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	beq _080507C0
	movs r1, #0
	mov sb, r2
	ldr r2, _08050778 @ =0x0000034B
	mov r8, r2
	ldr r5, _0805077C @ =0x040000D4
	ldr r0, _08050780 @ =gUnknown_086B0F9C
	mov sl, r0
	ldr r7, _08050784 @ =0x80000020
_0805073C:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	add r0, r8
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r1, #0
	cmp r0, #0
	ble _08050788
	cmp r0, #0xa
	bne _0805075E
	movs r0, SE_UNKNOWN_0xDC
	bl m4aSongNumStart
_0805075E:
	mov r0, sb
	ldr r1, [r0]
	add r1, r8
	adds r1, r1, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r2, #1
	b _0805078A
	.align 2, 0
_08050770: .4byte gCurrentPinballGame
_08050774: .4byte 0x00000346
_08050778: .4byte 0x0000034B
_0805077C: .4byte 0x040000D4
_08050780: .4byte gUnknown_086B0F9C
_08050784: .4byte 0x80000020
_08050788:
	movs r2, #0
_0805078A:
	asrs r3, r6, #0x10
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	lsls r2, r2, #3
	add r2, sl
	adds r2, r1, r2
	ldr r0, _080507D0 @ =gUnknown_086B0FAC
	adds r1, r1, r0
	ldr r0, [r2]
	str r0, [r5]
	ldr r0, [r1]
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, [r2, #4]
	str r0, [r5]
	ldr r0, [r1, #4]
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #9
	ble _0805073C
_080507C0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080507D0: .4byte gUnknown_086B0FAC

	thumb_func_start sub_507D4
sub_507D4: @ 0x080507D4
	push {r4, r5, lr}
	movs r1, #0
	ldr r0, _08050834 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x63
	bls _080507F8
	ldr r1, _08050838 @ =0x0000070C
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x12
_080507F8:
	lsls r0, r1, #3
	ldr r2, _0805083C @ =gUnknown_086B0E6C
	adds r3, r0, r2
	adds r5, r2, #0
	adds r5, #0x28
	adds r0, r4, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xaf
	bgt _0805081E
	ldr r1, _08050840 @ =0x040000D4
	ldr r0, [r3]
	str r0, [r1]
	ldr r0, [r2, #0x28]
	str r0, [r1, #4]
	ldr r0, _08050844 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0805081E:
	ldr r1, _08050840 @ =0x040000D4
	ldr r0, [r3, #4]
	str r0, [r1]
	ldr r0, [r5, #4]
	str r0, [r1, #4]
	ldr r0, _08050844 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050834: .4byte gCurrentPinballGame
_08050838: .4byte 0x0000070C
_0805083C: .4byte gUnknown_086B0E6C
_08050840: .4byte 0x040000D4
_08050844: .4byte 0x80000020

	thumb_func_start sub_50848
sub_50848: @ 0x08050848
	push {r4, r5, r6, r7, lr}
	movs r0, #0
	ldr r4, _080508E8 @ =gMain
	ldr r7, _080508EC @ =gUnknown_086B155C
	adds r6, r4, #0
	movs r5, #0xb8
	movs r3, #0xbe
	lsls r3, r3, #2
	movs r2, #0
_0805085A:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, r0, r3
	strh r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x53
	ble _0805085A
	ldr r0, _080508F0 @ =0x000030F8
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080508F4 @ =0x00002578
	adds r3, r4, r1
	ldr r2, _080508F8 @ =0x00003548
	adds r1, r4, r2
	strh r0, [r1]
	movs r5, #0xbe
	lsls r5, r5, #2
	adds r2, r4, r5
	strh r0, [r2]
	adds r5, #0xb8
	adds r1, r4, r5
	strh r0, [r1]
	adds r5, #0xb8
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _080508FC @ =0x00001718
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _08050900 @ =0x00003D30
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _08050904 @ =0x000031B0
	adds r1, r4, r5
	strh r0, [r1]
	movs r5, #0xd8
	lsls r5, r5, #6
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _08050908 @ =0x00003268
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _0805090C @ =0x000027A0
	adds r1, r4, r5
	strh r0, [r1]
	ldr r5, _08050910 @ =0x00002ED0
	adds r1, r4, r5
	strh r0, [r1]
	strh r0, [r3]
	ldr r3, _08050914 @ =0x00002858
	adds r1, r4, r3
	strh r0, [r1]
	adds r5, #0xb8
	adds r1, r4, r5
	strh r0, [r1]
	ldrb r1, [r4, #4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldr r0, [r1]
	ldrh r1, [r1, #4]
	bl LoadSpriteSets
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080508E8: .4byte gMain
_080508EC: .4byte gUnknown_086B155C
_080508F0: .4byte 0x000030F8
_080508F4: .4byte 0x00002578
_080508F8: .4byte 0x00003548
_080508FC: .4byte 0x00001718
_08050900: .4byte 0x00003D30
_08050904: .4byte 0x000031B0
_08050908: .4byte 0x00003268
_0805090C: .4byte 0x000027A0
_08050910: .4byte 0x00002ED0
_08050914: .4byte 0x00002858

	thumb_func_start sub_50918
sub_50918: @ 0x08050918
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _080509EC @ =gMain
	ldr r1, _080509F0 @ =0x00000A28
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	ldr r4, _080509F4 @ =0x00002578
	adds r0, r2, r4
	strh r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #6
	adds r0, r2, r3
	strh r1, [r0]
	movs r0, #0x33
	adds r5, r2, #0
	ldr r7, _080509F8 @ =gCurrentPinballGame
	ldr r4, _080509FC @ =gUnknown_086B155C
	mov r8, r4
	adds r6, r5, #0
	movs r4, #0xb8
	movs r3, #0xbe
	lsls r3, r3, #2
	movs r2, #0
_08050952:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r6
	adds r0, r0, r3
	strh r2, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x42
	ble _08050952
	ldr r4, [r7]
	ldr r0, [r5, #0x4c]
	movs r1, #0x19
	bl __umodsi3
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r4, #0x68
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0x6d
	bgt _0805099E
	ldr r4, _08050A00 @ =0x000031B0
	adds r0, r5, r4
	movs r1, #1
	strh r1, [r0]
	movs r2, #0xd8
	lsls r2, r2, #6
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _08050A04 @ =0x00003268
	adds r0, r5, r3
	strh r1, [r0]
_0805099E:
	ldr r3, [r7]
	adds r2, r3, #0
	adds r2, #0x68
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0xa7
	bgt _080509BA
	ldr r1, _080509F4 @ =0x00002578
	adds r0, r5, r1
	movs r1, #1
	strh r1, [r0]
	ldr r4, _08050A08 @ =0x00002858
	adds r0, r5, r4
	strh r1, [r0]
_080509BA:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xdb
	bgt _08050A1E
	ldr r2, _08050A0C @ =0x000027A0
	adds r0, r5, r2
	movs r1, #1
	strh r1, [r0]
	ldr r4, _08050A10 @ =0x00002ED0
	adds r0, r5, r4
	strh r1, [r0]
	ldr r2, _08050A14 @ =0x000030F8
	adds r0, r5, r2
	strh r1, [r0]
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08050A18
	subs r2, #0xb8
	adds r0, r5, r2
	b _08050A1C
	.align 2, 0
_080509EC: .4byte gMain
_080509F0: .4byte 0x00000A28
_080509F4: .4byte 0x00002578
_080509F8: .4byte gCurrentPinballGame
_080509FC: .4byte gUnknown_086B155C
_08050A00: .4byte 0x000031B0
_08050A04: .4byte 0x00003268
_08050A08: .4byte 0x00002858
_08050A0C: .4byte 0x000027A0
_08050A10: .4byte 0x00002ED0
_08050A14: .4byte 0x000030F8
_08050A18:
	ldr r3, _08050AB0 @ =0x00002F88
	adds r0, r5, r3
_08050A1C:
	strh r1, [r0]
_08050A1E:
	ldr r0, [r7]
	adds r0, #0x68
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x3f
	ble _08050A38
	ldr r1, _08050AB4 @ =0x00002910
	adds r0, r5, r1
	movs r1, #1
	strh r1, [r0]
	ldr r2, _08050AB8 @ =0x00002BF0
	adds r0, r5, r2
	strh r1, [r0]
_08050A38:
	ldr r0, [r7]
	adds r4, r0, #0
	adds r4, #0x68
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0x73
	ble _08050A4E
	ldr r0, _08050ABC @ =0x00002CA8
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
_08050A4E:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x82
	ble _08050A64
	ldr r2, _08050AC0 @ =0x00002D60
	adds r0, r5, r2
	movs r1, #1
	strh r1, [r0]
	ldr r3, _08050AC4 @ =0x00002E18
	adds r0, r5, r3
	strh r1, [r0]
_08050A64:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0xd8
	ble _08050A90
	ldr r2, _08050AC8 @ =0x00002B38
	adds r0, r5, r2
	movs r1, #1
	strh r1, [r0]
	ldr r3, _08050ACC @ =0x000029C8
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xaa
	lsls r4, r4, #6
	adds r0, r5, r4
	strh r1, [r0]
	ldr r2, _08050AD0 @ =0x00000A28
	adds r0, r5, r2
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
_08050A90:
	ldrb r1, [r5, #4]
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	ldrh r1, [r1, #4]
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r2, r5, r4
	bl LoadSpriteSets
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050AB0: .4byte 0x00002F88
_08050AB4: .4byte 0x00002910
_08050AB8: .4byte 0x00002BF0
_08050ABC: .4byte 0x00002CA8
_08050AC0: .4byte 0x00002D60
_08050AC4: .4byte 0x00002E18
_08050AC8: .4byte 0x00002B38
_08050ACC: .4byte 0x000029C8
_08050AD0: .4byte 0x00000A28

