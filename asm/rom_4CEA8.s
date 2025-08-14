#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

    .align 2, 0

	thumb_func_start AllBoardProcess_8A_4CEA8
AllBoardProcess_8A_4CEA8: @ 0x0804CEA8
	push {lr}
	bl AllBoardProcess_8B_4CEB4
	pop {r0}
	bx r0


	thumb_func_start AllBoardProcess_8B_4CEB4
AllBoardProcess_8B_4CEB4: @ 0x0804CEB4
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

	thumb_func_start AllBoardProcess_2A_4D6C4
AllBoardProcess_2A_4D6C4: @ 0x0804D6C4
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

	thumb_func_start MainBoardProcess_2B_4D960
MainBoardProcess_2B_4D960: @ 0x0804D960
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

	thumb_func_start BonusBoardProcess_2B_4DBFC
BonusBoardProcess_2B_4DBFC: @ 0x0804DBFC
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
