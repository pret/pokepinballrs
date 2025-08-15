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
