#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_2F140
sub_2F140: @ 0x0802F140
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802F240 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r6, _0802F244 @ =gMain+0x38E0 @gMain.spriteGroups[75]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0802F170
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0802F170:
	ldr r2, _0802F248 @ =gUnknown_086AE462
	lsls r0, r4, #0x10
	asrs r0, r0, #0xe
	adds r1, r0, r2
	ldrh r3, [r1]
	adds r2, #2
	adds r0, r0, r2
	ldrh r4, [r0]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xa4
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r0, r5, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xa6
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _0802F24C @ =0x040000D4
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0802F250 @ =gUnknown_083FFD8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802F254 @ =0x06012720
	str r0, [r2, #4]
	ldr r0, _0802F258 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r7, _0802F25C @ =gUnknown_086B4A72
	mov sb, r7
	ldr r0, _0802F260 @ =gOamBuffer
	mov sl, r0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	mov ip, r0
	ldr r2, _0802F264 @ =0xFFFFFE00
	mov r8, r2
_0802F1CE:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r6, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, sl
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
	add r2, sl
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802F268 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _0802F1CE
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F240: .4byte gCurrentPinballGame
_0802F244: .4byte gMain+0x38E0 @gMain.spriteGroups[75]
_0802F248: .4byte gUnknown_086AE462
_0802F24C: .4byte 0x040000D4
_0802F250: .4byte gUnknown_083FFD8C
_0802F254: .4byte 0x06012720
_0802F258: .4byte 0x80000180
_0802F25C: .4byte gUnknown_086B4A72
_0802F260: .4byte gOamBuffer
_0802F264: .4byte 0xFFFFFE00
_0802F268: .4byte 0x000001FF

	thumb_func_start sub_2F26C
sub_2F26C: @ 0x0802F26C
	push {r4, r5, r6, lr}
	ldr r1, _0802F290 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #4
	bls _0802F286
	b _0802F4FA
_0802F286:
	lsls r0, r0, #2
	ldr r1, _0802F294 @ =_0802F298
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802F290: .4byte gCurrentPinballGame
_0802F294: .4byte _0802F298
_0802F298: @ jump table
	.4byte _0802F2AC @ case 0
	.4byte _0802F2F0 @ case 1
	.4byte _0802F384 @ case 2
	.4byte _0802F408 @ case 3
	.4byte _0802F4DC @ case 4
_0802F2AC:
	ldr r4, [r5]
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	adds r0, #2
	ldr r2, _0802F2E8 @ =0x00000379
	adds r4, r4, r2
	movs r3, #0
	strb r0, [r4]
	ldr r1, [r5]
	adds r2, r1, r2
	ldrb r0, [r2]
	adds r0, #1
	ldr r2, _0802F2EC @ =0x0000037A
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r3, [r0]
	b _0802F4FA
	.align 2, 0
_0802F2E8: .4byte 0x00000379
_0802F2EC: .4byte 0x0000037A
_0802F2F0:
	ldr r4, [r5]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0x21
	bl __umodsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bgt _0802F320
	ldr r3, _0802F318 @ =0x00000379
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0802F31C @ =0x0000037A
	adds r0, r0, r2
	b _0802F360
	.align 2, 0
_0802F318: .4byte 0x00000379
_0802F31C: .4byte 0x0000037A
_0802F320:
	cmp r0, #0x13
	bgt _0802F330
	ldr r3, _0802F32C @ =0x00000379
	adds r1, r4, r3
	b _0802F354
	.align 2, 0
_0802F32C: .4byte 0x00000379
_0802F330:
	cmp r0, #0x19
	bgt _0802F350
	ldr r2, _0802F348 @ =0x00000379
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _0802F34C @ =0x0000037A
	adds r0, r0, r3
	movs r1, #2
	b _0802F360
	.align 2, 0
_0802F348: .4byte 0x00000379
_0802F34C: .4byte 0x0000037A
_0802F350:
	ldr r0, _0802F37C @ =0x00000379
	adds r1, r4, r0
_0802F354:
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0802F380 @ =0x0000037A
	adds r0, r0, r1
	movs r1, #1
_0802F360:
	strb r1, [r0]
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0802F374
	b _0802F4FA
_0802F374:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r1, r2
	b _0802F4D0
	.align 2, 0
_0802F37C: .4byte 0x00000379
_0802F380: .4byte 0x0000037A
_0802F384:
	ldr r0, [r5]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r5]
	ldr r1, _0802F3E8 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, [r5]
	adds r3, #2
	adds r0, r1, r3
	movs r3, #0
	strh r2, [r0]
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0802F3EC @ =0x0000037B
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, _0802F3F0 @ =gMain
	movs r2, #0xb3
	lsls r2, r2, #5
	adds r0, r0, r2
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r5]
	adds r0, #0xe4
	movs r1, #0x16
	strb r1, [r0]
	ldr r1, _0802F3F4 @ =0x040000D4
	ldr r0, _0802F3F8 @ =gUnknown_08526DCC
	str r0, [r1]
	ldr r0, _0802F3FC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802F400 @ =0x80000600
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, 0xEC @=SE_UNKNOWN_0xEC
	bl m4aSongNumStart
	ldr r1, [r5]
	ldr r0, _0802F404 @ =0x00001388
	str r0, [r1, #0x3c]
	b _0802F4FA
	.align 2, 0
_0802F3E8: .4byte 0x0000037D
_0802F3EC: .4byte 0x0000037B
_0802F3F0: .4byte gMain
_0802F3F4: .4byte 0x040000D4
_0802F3F8: .4byte gUnknown_08526DCC
_0802F3FC: .4byte 0x06015800
_0802F400: .4byte 0x80000600
_0802F404: .4byte 0x00001388
_0802F408:
	ldr r3, _0802F434 @ =gUnknown_086AE496
	ldr r2, [r5]
	ldr r0, _0802F438 @ =0x0000037D
	adds r4, r2, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0802F43C @ =0x0000037E
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r6, r3, #0
	cmp r0, r1
	ble _0802F440
	adds r0, r1, #1
	strh r0, [r2]
	b _0802F46C
	.align 2, 0
_0802F434: .4byte gUnknown_086AE496
_0802F438: .4byte 0x0000037D
_0802F43C: .4byte 0x0000037E
_0802F440:
	ldrb r0, [r4]
	adds r0, #1
	movs r2, #0
	strb r0, [r4]
	ldr r1, [r5]
	ldr r3, _0802F4B8 @ =0x0000037E
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _0802F4BC @ =0x0000037D
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x10
	ble _0802F46C
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
_0802F46C:
	ldr r2, [r5]
	ldr r3, _0802F4BC @ =0x0000037D
	adds r0, r2, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r1, _0802F4C0 @ =0x0000037A
	adds r2, r2, r1
	strb r0, [r2]
	ldr r2, [r5]
	adds r0, r2, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r6, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _0802F4C4 @ =0x00000379
	adds r2, r2, r1
	strb r0, [r2]
	ldr r2, [r5]
	adds r3, r2, r3
	ldrb r1, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #5
	bgt _0802F4CC
	adds r1, #1
	ldr r3, _0802F4C8 @ =0x0000037B
	adds r0, r2, r3
	strb r1, [r0]
	b _0802F4FA
	.align 2, 0
_0802F4B8: .4byte 0x0000037E
_0802F4BC: .4byte 0x0000037D
_0802F4C0: .4byte 0x0000037A
_0802F4C4: .4byte 0x00000379
_0802F4C8: .4byte 0x0000037B
_0802F4CC:
	ldr r0, _0802F4D8 @ =0x0000037B
	adds r1, r2, r0
_0802F4D0:
	movs r0, #0
	strb r0, [r1]
	b _0802F4FA
	.align 2, 0
_0802F4D8: .4byte 0x0000037B
_0802F4DC:
	ldr r0, [r5]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0802F500 @ =gMain
	movs r2, #0xb3
	lsls r2, r2, #5
	adds r0, r0, r2
	movs r2, #0
	strh r1, [r0]
	ldr r0, [r5]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r0, r3
	strb r2, [r0]
_0802F4FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802F500: .4byte gMain

	thumb_func_start sub_2F504
sub_2F504: @ 0x0802F504
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _0802F700 @ =gMain+0x15A8 @gMain.spriteGroups[26]
	ldrh r0, [r6]
	movs r1, #0xb8
	adds r1, r1, r6
	mov sl, r1
	cmp r0, #0
	beq _0802F5EC
	ldr r3, _0802F704 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xc6
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r3]
	movs r4, #0xe0
	lsls r4, r4, #2
	adds r2, r1, r4
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r0, r7, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r3, [r3]
	ldr r1, _0802F708 @ =0x00000379
	adds r0, r3, r1
	ldr r2, _0802F70C @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0802F710 @ =gUnknown_08512C4C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802F714 @ =0x06012A20
	str r0, [r2, #4]
	ldr r0, _0802F718 @ =0x800001C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r2, _0802F71C @ =0x0000037A
	adds r3, r3, r2
	movs r2, #0
	ldr r4, _0802F720 @ =gUnknown_086B3CA4
	mov sb, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #1
	mov ip, r0
	ldr r7, _0802F724 @ =0xFFFFFE00
	mov r8, r7
_0802F580:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	ldr r1, _0802F728 @ =gOamBuffer
	adds r2, r0, r1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, ip
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r7, _0802F728 @ =gOamBuffer
	adds r2, r2, r7
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802F72C @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	ldr r0, _0802F728 @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0802F580
_0802F5EC:
	mov r6, sl
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802F69A
	ldr r2, _0802F704 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xc6
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r2]
	ldr r4, _0802F730 @ =0x0000037B
	adds r0, r0, r4
	movs r2, #0
	ldr r7, _0802F734 @ =gUnknown_086B3B7E
	mov sb, r7
	ldr r1, _0802F728 @ =gOamBuffer
	mov sl, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x2a
	adds r3, r1, #0
	muls r3, r0, r3
	mov ip, r3
	ldr r4, _0802F724 @ =0xFFFFFE00
	mov r8, r4
_0802F632:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r7, sl
	adds r2, r0, r7
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, ip
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sl
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802F72C @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #6
	ble _0802F632
_0802F69A:
	ldr r6, _0802F738 @ =gMain+0x3548 @gMain.spriteGroups[70]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802F780
	ldr r2, _0802F704 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xce
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r2]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802F748
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r2]
	movs r7, #0xa4
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	ldr r2, _0802F70C @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _0802F73C @ =gUnknown_084ED6CC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802F740 @ =0x06014FA0
	str r0, [r2, #4]
	ldr r0, _0802F744 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802F74C
	.align 2, 0
_0802F700: .4byte gMain+0x15A8 @gMain.spriteGroups[26]
_0802F704: .4byte gCurrentPinballGame
_0802F708: .4byte 0x00000379
_0802F70C: .4byte 0x040000D4
_0802F710: .4byte gUnknown_08512C4C
_0802F714: .4byte 0x06012A20
_0802F718: .4byte 0x800001C0
_0802F71C: .4byte 0x0000037A
_0802F720: .4byte gUnknown_086B3CA4
_0802F724: .4byte 0xFFFFFE00
_0802F728: .4byte gOamBuffer
_0802F72C: .4byte 0x000001FF
_0802F730: .4byte 0x0000037B
_0802F734: .4byte gUnknown_086B3B7E
_0802F738: .4byte gMain+0x3548 @gMain.spriteGroups[70]
_0802F73C: .4byte gUnknown_084ED6CC
_0802F740: .4byte 0x06014FA0
_0802F744: .4byte 0x80000100
_0802F748:
	movs r0, #0xc8
	strh r0, [r6, #4]
_0802F74C:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802F790 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r7, _0802F794 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802F798 @ =0xFFFFFE00
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
_0802F780:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F790: .4byte gOamBuffer
_0802F794: .4byte 0x000001FF
_0802F798: .4byte 0xFFFFFE00

	thumb_func_start sub_2F79C
sub_2F79C: @ 0x0802F79C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0
	ldr r0, _0802F7D0 @ =gCurrentPinballGame
	mov r8, r0
_0802F7A8:
	mov r2, r8
	ldr r0, [r2]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	ldr r3, _0802F7D4 @ =0x0000036A
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r2, #0
	cmp r0, #5
	bls _0802F7C4
	b _0802FB26
_0802F7C4:
	lsls r0, r0, #2
	ldr r1, _0802F7D8 @ =_0802F7DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802F7D0: .4byte gCurrentPinballGame
_0802F7D4: .4byte 0x0000036A
_0802F7D8: .4byte _0802F7DC
_0802F7DC: @ jump table
	.4byte _0802F7F4 @ case 0
	.4byte _0802F87E @ case 1
	.4byte _0802F944 @ case 2
	.4byte _0802F9E4 @ case 3
	.4byte _0802FA28 @ case 4
	.4byte _0802FAA2 @ case 5
_0802F7F4:
	ldr r1, _0802F828 @ =gUnknown_086AE4FC
	mov r4, r8
	ldr r2, [r4]
	asrs r4, r6, #0x10
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r0, r2, r5
	adds r3, r0, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r5, r4, #1
	ldr r1, _0802F82C @ =0x0000036E
	adds r2, r2, r1
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0802F830
	adds r0, r1, #1
	strh r0, [r2]
	b _0802F858
	.align 2, 0
_0802F828: .4byte gUnknown_086AE4FC
_0802F82C: .4byte 0x0000036E
_0802F830:
	ldrb r0, [r3]
	adds r0, #1
	movs r2, #0
	strb r0, [r3]
	mov r3, r8
	ldr r1, [r3]
	ldr r3, _0802F870 @ =0x0000036E
	adds r0, r1, r3
	adds r0, r0, r5
	movs r3, #0
	strh r2, [r0]
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r1, r1, r5
	adds r1, r1, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	ble _0802F858
	strb r3, [r1]
_0802F858:
	mov r1, r8
	ldr r0, [r1]
	asrs r1, r6, #0xf
	ldr r2, _0802F874 @ =0x00000372
	adds r0, r0, r2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0x97
	bhi _0802F878
	adds r0, #1
	strh r0, [r1]
	b _0802FB26
	.align 2, 0
_0802F870: .4byte 0x0000036E
_0802F874: .4byte 0x00000372
_0802F878:
	movs r0, #0
	strh r0, [r1]
	b _0802FB26
_0802F87E:
	ldr r2, _0802F8B0 @ =gUnknown_086AE4FC
	ldr r7, _0802F8B4 @ =gCurrentPinballGame
	ldr r1, [r7]
	asrs r4, r6, #0x10
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r1, r3
	adds r3, r0, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r5, r4, #1
	ldr r2, _0802F8B8 @ =0x0000036E
	adds r1, r1, r2
	adds r1, r1, r5
	ldrh r2, [r1]
	cmp r0, r2
	ble _0802F8BC
	adds r0, r2, #1
	strh r0, [r1]
	b _0802F8EC
	.align 2, 0
_0802F8B0: .4byte gUnknown_086AE4FC
_0802F8B4: .4byte gCurrentPinballGame
_0802F8B8: .4byte 0x0000036E
_0802F8BC:
	ldrb r0, [r3]
	adds r0, #1
	movs r2, #0
	strb r0, [r3]
	ldr r1, [r7]
	ldr r3, _0802F938 @ =0x0000036E
	adds r0, r1, r3
	adds r0, r0, r5
	strh r2, [r0]
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r1, r1, r5
	adds r1, r1, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _0802F8EC
	movs r0, 0xE6 @=SE_UNKNOWN_0xE6
	bl m4aSongNumStart
	ldr r1, [r7]
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
_0802F8EC:
	ldr r0, _0802F93C @ =gCurrentPinballGame
	ldr r3, [r0]
	asrs r2, r6, #0x10
	movs r4, #0xdb
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r5, r1, r2
	movs r1, #0
	ldrsb r1, [r5, r1]
	mov r8, r0
	cmp r1, #6
	beq _0802F906
	b _0802FB16
_0802F906:
	ldr r1, _0802F940 @ =0x00000376
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802F926
	cmp r0, #1
	bne _0802F926
	movs r0, #7
	strb r0, [r5]
	mov r3, r8
	ldr r0, [r3]
	subs r4, #2
	adds r0, r0, r4
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
_0802F926:
	mov r5, r8
	ldr r0, [r5]
	asrs r1, r6, #0xf
	ldr r2, _0802F938 @ =0x0000036E
	adds r0, r0, r2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	b _0802FB16
	.align 2, 0
_0802F938: .4byte 0x0000036E
_0802F93C: .4byte gCurrentPinballGame
_0802F940: .4byte 0x00000376
_0802F944:
	ldr r1, _0802F978 @ =gUnknown_086AE4FC
	mov r5, r8
	ldr r2, [r5]
	asrs r5, r6, #0x10
	movs r7, #0xdb
	lsls r7, r7, #2
	adds r0, r2, r7
	adds r3, r0, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r4, r5, #1
	ldr r1, _0802F97C @ =0x0000036E
	adds r2, r2, r1
	adds r2, r2, r4
	ldrh r1, [r2]
	cmp r0, r1
	ble _0802F980
	adds r0, r1, #1
	strh r0, [r2]
	b _0802F9CA
	.align 2, 0
_0802F978: .4byte gUnknown_086AE4FC
_0802F97C: .4byte 0x0000036E
_0802F980:
	ldrb r0, [r3]
	adds r0, #1
	movs r2, #0
	strb r0, [r3]
	mov r3, r8
	ldr r1, [r3]
	ldr r3, _0802F9D8 @ =0x0000036E
	adds r0, r1, r3
	adds r0, r0, r4
	movs r4, #0
	strh r2, [r0]
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bne _0802F9AC
	movs r0, 0xE7 @=SE_UNKNOWN_0xE7
	bl m4aSongNumStart
_0802F9AC:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	ble _0802F9CA
	strb r4, [r1]
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _0802F9DC @ =0x0000036A
	adds r0, r0, r3
	adds r0, r0, r5
	strb r4, [r0]
_0802F9CA:
	mov r4, r8
	ldr r0, [r4]
	asrs r1, r6, #0xf
	ldr r5, _0802F9E0 @ =0x00000372
	adds r0, r0, r5
	b _0802FB20
	.align 2, 0
_0802F9D8: .4byte 0x0000036E
_0802F9DC: .4byte 0x0000036A
_0802F9E0: .4byte 0x00000372
_0802F9E4:
	mov r0, r8
	ldr r1, [r0]
	asrs r2, r6, #0x10
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r1, r1, r3
	adds r1, r1, r2
	movs r4, #0
	movs r0, #9
	strb r0, [r1]
	mov r5, r8
	ldr r1, [r5]
	lsls r3, r2, #1
	ldr r5, _0802FA1C @ =0x0000036E
	adds r0, r1, r5
	adds r0, r0, r3
	strh r4, [r0]
	ldr r0, _0802FA20 @ =0x0000036A
	adds r1, r1, r0
	adds r1, r1, r2
	movs r0, #4
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0802FA24 @ =0x00000372
	adds r0, r0, r2
	adds r0, r0, r3
	b _0802FB22
	.align 2, 0
_0802FA1C: .4byte 0x0000036E
_0802FA20: .4byte 0x0000036A
_0802FA24: .4byte 0x00000372
_0802FA28:
	ldr r1, _0802FA90 @ =gUnknown_086AE4FC
	mov r3, r8
	ldr r2, [r3]
	asrs r5, r6, #0x10
	movs r4, #0xdb
	lsls r4, r4, #2
	adds r0, r2, r4
	adds r3, r0, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r4, r5, #1
	ldr r1, _0802FA94 @ =0x0000036E
	adds r2, r2, r1
	adds r2, r2, r4
	ldrh r1, [r2]
	cmp r0, r1
	bgt _0802FACE
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	mov r3, r8
	ldr r2, [r3]
	ldr r3, _0802FA94 @ =0x0000036E
	adds r0, r2, r3
	adds r0, r0, r4
	movs r3, #0
	strh r1, [r0]
	movs r4, #0xdb
	lsls r4, r4, #2
	adds r0, r2, r4
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x11
	ble _0802FB16
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #6
	bne _0802FA9C
	strb r3, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0802FA98 @ =0x0000036A
	adds r0, r0, r2
	adds r0, r0, r5
	b _0802FB14
	.align 2, 0
_0802FA90: .4byte gUnknown_086AE4FC
_0802FA94: .4byte 0x0000036E
_0802FA98: .4byte 0x0000036A
_0802FA9C:
	movs r0, #9
	strb r0, [r1]
	b _0802FB16
_0802FAA2:
	ldr r1, _0802FAD4 @ =gUnknown_086AE4FC
	mov r5, r8
	ldr r2, [r5]
	asrs r4, r6, #0x10
	movs r7, #0xdb
	lsls r7, r7, #2
	adds r0, r2, r7
	adds r3, r0, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r5, r4, #1
	ldr r1, _0802FAD8 @ =0x0000036E
	adds r2, r2, r1
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0802FADC
_0802FACE:
	adds r0, r1, #1
	strh r0, [r2]
	b _0802FB16
	.align 2, 0
_0802FAD4: .4byte gUnknown_086AE4FC
_0802FAD8: .4byte 0x0000036E
_0802FADC:
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	mov r3, r8
	ldr r2, [r3]
	ldr r3, _0802FC24 @ =0x0000036E
	adds r0, r2, r3
	adds r0, r0, r5
	movs r3, #0
	strh r1, [r0]
	movs r5, #0xdb
	lsls r5, r5, #2
	adds r0, r2, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x11
	ble _0802FB16
	ldr r1, _0802FC28 @ =0x0000036A
	adds r0, r2, r1
	adds r0, r0, r4
	strb r3, [r0]
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r7
	adds r0, r0, r4
_0802FB14:
	strb r3, [r0]
_0802FB16:
	mov r3, r8
	ldr r0, [r3]
	asrs r1, r6, #0xf
	ldr r4, _0802FC2C @ =0x00000372
	adds r0, r0, r4
_0802FB20:
	adds r0, r0, r1
_0802FB22:
	movs r1, #0x14
	strh r1, [r0]
_0802FB26:
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r6, r5
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0802FB36
	b _0802F7A8
_0802FB36:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	beq _0802FB56
	ldr r2, _0802FC30 @ =0x00000376
	adds r1, r1, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802FB56
	subs r0, #1
	strh r0, [r1]
_0802FB56:
	mov r3, r8
	ldr r2, [r3]
	ldr r4, _0802FC34 @ =0x00001328
	adds r1, r2, r4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802FB78
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0802FB78
	ldr r5, _0802FC38 @ =0x00001330
	adds r1, r2, r5
	ldr r3, _0802FC3C @ =0x00001334
	adds r0, r2, r3
	str r0, [r1]
_0802FB78:
	mov r4, r8
	ldr r0, [r4]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802FBCE
	cmp r0, #0x11
	bne _0802FB9E
	movs r0, 0xE8 @=SE_UNKNOWN_0xE8
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0xa
	str r0, [r1, #0x3c]
	movs r0, #0xd
	bl sub_11B0
_0802FB9E:
	ldr r5, _0802FC40 @ =gUnknown_08137CD6
	mov r0, r8
	ldr r4, [r0]
	adds r4, r4, r6
	ldrh r0, [r4]
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r3, _0802FC44 @ =0x0400004C
	lsls r0, r2, #0xc
	lsls r1, r2, #8
	orrs r0, r1
	lsls r1, r2, #4
	orrs r0, r1
	orrs r0, r2
	strh r0, [r3]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_0802FBCE:
	mov r3, r8
	ldr r1, [r3]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #2
	ble _0802FC48
	cmp r0, #6
	beq _0802FCB8
	movs r1, #0
	movs r3, #0
_0802FBE2:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	ldr r4, _0802FC28 @ =0x0000036A
	adds r0, r0, r4
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0802FC14
	strb r3, [r1]
	mov r5, r8
	ldr r0, [r5]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r4, #4
	adds r0, r0, r4
	adds r0, r0, r1
	strh r3, [r0]
_0802FC14:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0802FBE2
	b _0802FCB8
	.align 2, 0
_0802FC24: .4byte 0x0000036E
_0802FC28: .4byte 0x0000036A
_0802FC2C: .4byte 0x00000372
_0802FC30: .4byte 0x00000376
_0802FC34: .4byte 0x00001328
_0802FC38: .4byte 0x00001330
_0802FC3C: .4byte 0x00001334
_0802FC40: .4byte gUnknown_08137CD6
_0802FC44: .4byte 0x0400004C
_0802FC48:
	ldr r5, _0802FC7C @ =0x0000072E
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0802FC8C
	ldr r2, _0802FC80 @ =0x00000281
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0802FCB8
	ldr r4, _0802FC84 @ =0x0000036A
	adds r2, r1, r4
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _0802FCB8
	movs r1, #3
	strb r1, [r2]
	ldr r0, [r3]
	ldr r5, _0802FC88 @ =0x0000036B
	b _0802FCB4
	.align 2, 0
_0802FC7C: .4byte 0x0000072E
_0802FC80: .4byte 0x00000281
_0802FC84: .4byte 0x0000036A
_0802FC88: .4byte 0x0000036B
_0802FC8C:
	ldr r0, _0802FCC4 @ =0x0000036A
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	ble _0802FCB8
	movs r1, #0
	strb r1, [r2]
	mov r2, r8
	ldr r0, [r2]
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _0802FCC8 @ =0x0000036B
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _0802FCCC @ =0x0000036D
_0802FCB4:
	adds r0, r0, r5
	strb r1, [r0]
_0802FCB8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FCC4: .4byte 0x0000036A
_0802FCC8: .4byte 0x0000036B
_0802FCCC: .4byte 0x0000036D

	thumb_func_start sub_2FCD0
sub_2FCD0: @ 0x0802FCD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _0802FDCC @ =gMain+0x2ED0 @gMain.spriteGroups[61]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802FCE4
	b _080300B2
_0802FCE4:
	ldr r3, _0802FDD0 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x44
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r4, _0802FDD4 @ =gUnknown_086AE4FC
	ldr r0, [r3]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, _0802FDD8 @ =0x040000D4
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0802FDDC @ =gUnknown_0847A40C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FDE0 @ =0x06012DA0
	str r0, [r2, #4]
	ldr r0, _0802FDE4 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	mov ip, r3
	ldr r1, _0802FDE8 @ =gOamBuffer
	mov sb, r1
	ldr r2, _0802FDEC @ =0xFFFFFDD8
	adds r2, r2, r6
	mov sl, r2
	mov r7, sb
	ldr r3, _0802FDF0 @ =0xFFFFFE00
	mov r8, r3
_0802FD42:
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
	ldr r2, _0802FDF4 @ =0x000001FF
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
	cmp r4, #1
	ble _0802FD42
	mov r6, sl
	mov r3, ip
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x44
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r3]
	ldr r5, _0802FDF8 @ =0x00000372
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _0802FE08
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802FDD8 @ =0x040000D4
	lsrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0802FDFC @ =gUnknown_0847D10C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FE00 @ =0x06014720
	str r0, [r2, #4]
	ldr r0, _0802FE04 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802FE0C
	.align 2, 0
_0802FDCC: .4byte gMain+0x2ED0 @gMain.spriteGroups[61]
_0802FDD0: .4byte gCurrentPinballGame
_0802FDD4: .4byte gUnknown_086AE4FC
_0802FDD8: .4byte 0x040000D4
_0802FDDC: .4byte gUnknown_0847A40C
_0802FDE0: .4byte 0x06012DA0
_0802FDE4: .4byte 0x80000140
_0802FDE8: .4byte gOamBuffer
_0802FDEC: .4byte 0xFFFFFDD8
_0802FDF0: .4byte 0xFFFFFE00
_0802FDF4: .4byte 0x000001FF
_0802FDF8: .4byte 0x00000372
_0802FDFC: .4byte gUnknown_0847D10C
_0802FE00: .4byte 0x06014720
_0802FE04: .4byte 0x800000C0
_0802FE08:
	movs r0, #0xc8
	strh r0, [r6, #4]
_0802FE0C:
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802FF1C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r4, _0802FF20 @ =0xFFFFFE00
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r6, _0802FF24 @ =gMain+0x2F88 @gMain.spriteGroups[62]
	mov r5, ip
	ldr r0, [r5]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x24
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r5]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xa3
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r5]
	ldr r1, _0802FF28 @ =0x0000036D
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r2, _0802FF2C @ =gUnknown_086AE4FC
	adds r0, r0, r2
	ldr r2, _0802FF30 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r5, _0802FF34 @ =gUnknown_084C1E6C
	adds r0, r0, r5
	str r0, [r2]
	ldr r0, _0802FF38 @ =0x060130A0
	str r0, [r2, #4]
	ldr r0, _0802FF3C @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	mov r7, sb
	mov r8, r4
_0802FE90:
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
	ldr r2, _0802FF1C @ =0x000001FF
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
	cmp r4, #1
	ble _0802FE90
	ldr r6, _0802FF40 @ =gMain+0x2D60 @gMain.spriteGroups[59]
	mov r3, ip
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x24
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r3]
	movs r5, #0xdd
	lsls r5, r5, #2
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _0802FF50
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xa3
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802FF30 @ =0x040000D4
	lsrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0802FF44 @ =gUnknown_084C4B6C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FF48 @ =0x06014920
	str r0, [r2, #4]
	ldr r0, _0802FF4C @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802FF54
	.align 2, 0
_0802FF1C: .4byte 0x000001FF
_0802FF20: .4byte 0xFFFFFE00
_0802FF24: .4byte gMain+0x2F88 @gMain.spriteGroups[62]
_0802FF28: .4byte 0x0000036D
_0802FF2C: .4byte gUnknown_086AE4FC
_0802FF30: .4byte 0x040000D4
_0802FF34: .4byte gUnknown_084C1E6C
_0802FF38: .4byte 0x060130A0
_0802FF3C: .4byte 0x80000140
_0802FF40: .4byte gMain+0x2D60 @gMain.spriteGroups[59]
_0802FF44: .4byte gUnknown_084C4B6C
_0802FF48: .4byte 0x06014920
_0802FF4C: .4byte 0x800000C0
_0802FF50:
	movs r0, #0xc8
	strh r0, [r6, #4]
_0802FF54:
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802FFBC @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802FFC0 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r6, _0802FFC4 @ =gMain+0x3998 @gMain.spriteGroups[76]
	mov r5, ip
	ldr r0, [r5]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x3d
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r5]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xba
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, [r5]
	ldr r2, _0802FFC8 @ =0x00000367
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802FFD0
	ldr r3, _0802FFCC @ =0x00000366
	adds r1, r1, r3
	movs r0, #3
	b _08030032
	.align 2, 0
_0802FFBC: .4byte 0x000001FF
_0802FFC0: .4byte 0xFFFFFE00
_0802FFC4: .4byte gMain+0x3998 @gMain.spriteGroups[76]
_0802FFC8: .4byte 0x00000367
_0802FFCC: .4byte 0x00000366
_0802FFD0:
	ldr r5, _0802FFF4 @ =0x0000036A
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803000C
	ldr r2, _0802FFF8 @ =0x0000036B
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08030000
	ldr r3, _0802FFFC @ =0x00000366
	adds r1, r1, r3
	movs r0, #3
	b _08030032
	.align 2, 0
_0802FFF4: .4byte 0x0000036A
_0802FFF8: .4byte 0x0000036B
_0802FFFC: .4byte 0x00000366
_08030000:
	ldr r5, _08030008 @ =0x00000366
	adds r1, r1, r5
	movs r0, #2
	b _08030032
	.align 2, 0
_08030008: .4byte 0x00000366
_0803000C:
	ldr r2, _08030024 @ =0x0000036B
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803002C
	ldr r3, _08030028 @ =0x00000366
	adds r1, r1, r3
	movs r0, #1
	b _08030032
	.align 2, 0
_08030024: .4byte 0x0000036B
_08030028: .4byte 0x00000366
_0803002C:
	ldr r5, _08030064 @ =0x00000366
	adds r1, r1, r5
	movs r0, #0
_08030032:
	strb r0, [r1]
	mov r0, ip
	ldr r3, [r0]
	ldr r2, _08030064 @ =0x00000366
	adds r1, r3, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08030068
	lsls r4, r0, #1
	adds r4, r4, r0
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r3, r5
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	b _0803006A
	.align 2, 0
_08030064: .4byte 0x00000366
_08030068:
	movs r0, #9
_0803006A:
	ldr r1, _080300C0 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #9
	ldr r2, _080300C4 @ =gUnknown_084FEA0C
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _080300C8 @ =0x060146A0
	str r0, [r1, #4]
	ldr r0, _080300CC @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _080300D0 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080300D4 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_080300B2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080300C0: .4byte 0x040000D4
_080300C4: .4byte gUnknown_084FEA0C
_080300C8: .4byte 0x060146A0
_080300CC: .4byte 0x80000040
_080300D0: .4byte 0x000001FF
_080300D4: .4byte 0xFFFFFE00

	thumb_func_start sub_300D8
sub_300D8: @ 0x080300D8
	push {r4, r5, lr}
	ldr r0, _08030170 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xe6
	lsls r0, r0, #2
	strh r0, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0x85
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08030174 @ =0x000004EC
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0xa
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0x83
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x87
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x14
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0xa1
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030170: .4byte gCurrentPinballGame
_08030174: .4byte 0x000004EC

	thumb_func_start sub_30178
sub_30178: @ 0x08030178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080301DC @ =gMain+0x3040 @gMain.spriteGroups[63]
	mov sl, r0
	ldr r1, _080301E0 @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r2, _080301E4 @ =0x00000624
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0803019A
	b _080302D4
_0803019A:
	cmp r0, #2
	beq _080301A0
	b _080302C6
_080301A0:
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r3, #0x3c]
	movs r0, 0xB6 @=SE_UNKNOWN_0xB6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r3, _080301E0 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0803029C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _0803029C
	ldr r6, _080301E8 @ =0x00000625
	adds r1, r1, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0803029C
	cmp r0, #0
	bne _080301EC
	movs r0, #1
	b _080301F6
	.align 2, 0
_080301DC: .4byte gMain+0x3040 @gMain.spriteGroups[63]
_080301E0: .4byte gCurrentPinballGame
_080301E4: .4byte 0x00000624
_080301E8: .4byte 0x00000625
_080301EC:
	cmp r0, #1
	bne _080301F4
	movs r0, #3
	b _080301F6
_080301F4:
	movs r0, #6
_080301F6:
	strb r0, [r1]
	ldr r7, _08030318 @ =gCurrentPinballGame
	ldr r5, [r7]
	ldr r1, _0803031C @ =0x00000625
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0803029C
	ldr r2, _08030320 @ =0x000006C6
	adds r0, r5, r2
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne _0803029C
	ldr r2, _08030324 @ =gMain
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
	strh r6, [r0]
	adds r1, #6
	movs r0, #4
	strh r0, [r1]
	adds r1, #4
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r7]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08030328 @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r6, [r0]
	ldr r1, _0803032C @ =0x040000D4
	ldr r0, _08030330 @ =gUnknown_086ACEF8
	ldr r0, [r0, #0x1c]
	str r0, [r1]
	ldr r0, _08030334 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08030338 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0803033C @ =gUnknown_086ACF18
	ldr r0, [r0, #0x1c]
	str r0, [r1]
	ldr r0, _08030340 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08030344 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_0803029C:
	ldr r2, _08030318 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xbb
	lsls r3, r3, #1
	adds r1, r0, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, [r2]
	movs r6, #0xc2
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bne _080302C6
	ldr r0, _08030348 @ =0x0000C350
	str r0, [r3, #0x3c]
_080302C6:
	ldr r0, _08030318 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803034C @ =0x00000624
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080302D4:
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	bne _080302DE
	b _08030456
_080302DE:
	movs r0, #0
	ldr r6, _0803032C @ =0x040000D4
	mov sb, r6
_080302E4:
	ldr r1, _08030318 @ =gCurrentPinballGame
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r4, r3
	adds r3, r1, r2
	ldrb r6, [r3]
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r5, r0, #0
	cmp r1, #0
	ble _08030350
	adds r0, r1, #0
	cmp r0, #0
	bge _08030308
	adds r0, #3
_08030308:
	asrs r0, r0, #2
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	subs r0, r6, #1
	strb r0, [r3]
	b _08030370
	.align 2, 0
_08030318: .4byte gCurrentPinballGame
_0803031C: .4byte 0x00000625
_08030320: .4byte 0x000006C6
_08030324: .4byte gMain
_08030328: .4byte 0x0000F63C
_0803032C: .4byte 0x040000D4
_08030330: .4byte gUnknown_086ACEF8
_08030334: .4byte 0x06015800
_08030338: .4byte 0x80001200
_0803033C: .4byte gUnknown_086ACF18
_08030340: .4byte 0x050003C0
_08030344: .4byte 0x80000010
_08030348: .4byte 0x0000C350
_0803034C: .4byte 0x00000624
_08030350:
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r4, r6
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_08030370:
	lsls r0, r1, #0x10
	asrs r0, r0, #7
	ldr r1, _08030464 @ =gUnknown_0845690C
	adds r0, r0, r1
	mov r2, sb
	str r0, [r2]
	asrs r5, r5, #0x10
	lsls r0, r5, #9
	ldr r3, _08030468 @ =0x060133A0
	adds r0, r0, r3
	str r0, [r2, #4]
	ldr r0, _0803046C @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r6, _08030470 @ =gCurrentPinballGame
	ldr r4, [r6]
	lsls r0, r5, #2
	adds r7, r4, r0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r6, r7, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	mov r2, sl
	strh r0, [r2, #2]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r0, #0xa
	mov r2, sl
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #8
	lsls r0, r0, #1
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #3
	lsls r0, r0, #1
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	lsls r3, r5, #3
	adds r3, #8
	add r3, sl
	ldrh r4, [r3]
	lsls r4, r4, #3
	ldr r6, _08030474 @ =gOamBuffer
	adds r4, r4, r6
	movs r0, #2
	ldrsh r2, [r3, r0]
	mov r1, sl
	movs r6, #2
	ldrsh r0, [r1, r6]
	adds r2, r2, r0
	ldr r1, _08030478 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r0, [r4, #2]
	ldr r6, _0803047C @ =0xFFFFFE00
	adds r1, r6, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	ldr r0, _08030474 @ =gOamBuffer
	adds r1, r1, r0
	mov r2, sl
	ldrb r0, [r2, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	bgt _08030456
	b _080302E4
_08030456:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030464: .4byte gUnknown_0845690C
_08030468: .4byte 0x060133A0
_0803046C: .4byte 0x80000100
_08030470: .4byte gCurrentPinballGame
_08030474: .4byte gOamBuffer
_08030478: .4byte 0x000001FF
_0803047C: .4byte 0xFFFFFE00
	