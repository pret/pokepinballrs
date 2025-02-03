#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_599C
sub_599C: @ 0x0800599C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r7, _08005CFC @ =gUnknown_0200B3B8
	adds r6, r7, #0
	adds r6, #0xb8
	ldr r0, _08005D00 @ =gUnknown_0201A448
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xb8
	adds r1, r0, #0
	muls r1, r2, r1
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r7, r3
	adds r1, r1, r0
	str r1, [sp]
	ldr r0, _08005D04 @ =gUnknown_0202BEFC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r4, _08005D08 @ =0x00000C38
	adds r0, r7, r4
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r2, #0
	movs r0, #1
	strh r0, [r7]
	strh r0, [r6]
	ldr r0, _08005D0C @ =gUnknown_0202A55C
	ldrh r0, [r0]
	ldr r5, _08005D10 @ =gUnknown_0200B528
	strh r0, [r5]
	ldr r1, _08005D14 @ =gUnknown_0202A568
	ldrh r0, [r1]
	ldr r3, _08005D18 @ =gUnknown_0200B5E0
	strh r0, [r3]
	ldrh r0, [r1, #2]
	ldr r4, _08005D1C @ =gUnknown_0200B698
	strh r0, [r4]
	ldr r5, [sp]
	strh r2, [r5]
	ldr r0, _08005D20 @ =gUnknown_0202BEC4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [sp, #4]
	strh r0, [r1]
	ldr r0, _08005D24 @ =gUnknown_0202C590
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _08005D28 @ =gUnknown_0200C4F8
	strh r0, [r2]
	ldr r0, _08005D2C @ =gUnknown_086A6148
	movs r1, #0x1d
	adds r2, r7, #0
	bl sub_2414
	ldr r0, _08005D30 @ =gUnknown_0201A4F0
	ldrh r0, [r0]
	adds r0, #0x14
	strh r0, [r7, #2]
	ldr r0, _08005D34 @ =gUnknown_0202A57C
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #4
	adds r0, #0x54
	strh r0, [r7, #4]
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _08005D38 @ =gOamBuffer
	mov sl, r4
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	add r1, sl
	ldrb r2, [r1, #5]
	movs r4, #0xd
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r2
	movs r2, #8
	mov sb, r2
	mov r3, sb
	orrs r0, r3
	strb r0, [r1, #5]
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	add r2, sl
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r0, _08005D3C @ =0x000001FF
	mov r8, r0
	mov r3, r8
	ands r1, r3
	ldrh r3, [r2, #2]
	ldr r0, _08005D40 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r5, _08005D44 @ =gUnknown_0202BF08
	ldr r0, _08005D48 @ =gPokedexSelectedMon
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #3
	bl __divsi3
	adds r0, #0x56
	strh r0, [r5]
	movs r1, #0xd
	strh r1, [r6, #2]
	strh r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xc0
	ldrh r0, [r5]
	lsls r0, r0, #3
	add r0, sl
	ldrb r1, [r0, #5]
	ands r4, r1
	mov r2, sb
	orrs r4, r2
	strb r4, [r0, #5]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sl
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r4, #2
	ldrsh r0, [r6, r4]
	adds r1, r1, r0
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08005D40 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r1, _08005D10 @ =gUnknown_0200B528
	ldrh r0, [r1]
	cmp r0, #1
	bne _08005B30
	movs r0, #0x24
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	mov r4, sl
	ldr r2, _08005D40 @ =0xFFFFFE00
	mov r8, r2
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r6, r7, r3
	movs r7, #5
_08005AF6:
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r4
	movs r5, #2
	ldrsh r1, [r6, r5]
	ldr r2, _08005D10 @ =gUnknown_0200B528
	movs r5, #2
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	ldr r2, _08005D3C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r3, _08005D10 @ =gUnknown_0200B528
	ldrb r0, [r3, #4]
	ldrb r5, [r6, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _08005AF6
_08005B30:
	ldr r6, _08005D18 @ =gUnknown_0200B5E0
	ldrh r0, [r6]
	cmp r0, #1
	bne _08005BD4
	movs r0, #0x24
	strh r0, [r6, #2]
	movs r0, #0x1c
	strh r0, [r6, #4]
	movs r7, #0
	ldr r0, _08005D4C @ =gUnknown_0202BF0C
	mov ip, r0
	ldr r6, _08005D38 @ =gOamBuffer
	ldr r1, _08005D50 @ =gUnknown_086A5DF2
	mov sb, r1
	ldr r2, _08005D54 @ =0xFFFFFC00
	mov sl, r2
	ldr r5, _08005D18 @ =gUnknown_0200B5E0
	adds r5, #8
	ldr r3, _08005D40 @ =0xFFFFFE00
	mov r8, r3
_08005B58:
	ldrh r4, [r5]
	lsls r4, r4, #3
	adds r4, r4, r6
	lsls r3, r7, #1
	ldr r0, _08005D58 @ =gUnknown_0202BF14
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r0, r2, #3
	adds r3, r3, r0
	ldr r0, _08005D5C @ =gUnknown_086A5DDA
	adds r3, r3, r0
	str r3, [sp, #8]
	mov r3, ip
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r1, r1, #1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	add r1, sb
	ldrh r1, [r1]
	ldr r2, [sp, #8]
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r3, _08005D60 @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r2, [r4, #4]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #4]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r4, #2
	ldrsh r1, [r5, r4]
	ldr r2, _08005D18 @ =gUnknown_0200B5E0
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r1, r1, r0
	ldr r2, _08005D3C @ =0x000001FF
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
	ldr r3, _08005D18 @ =gUnknown_0200B5E0
	ldrb r0, [r3, #4]
	ldrb r4, [r5, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #8
	adds r7, #1
	cmp r7, #3
	ble _08005B58
_08005BD4:
	ldr r5, _08005D1C @ =gUnknown_0200B698
	ldrh r0, [r5]
	cmp r0, #1
	bne _08005C68
	movs r0, #0x30
	strh r0, [r5, #2]
	movs r0, #0x28
	strh r0, [r5, #4]
	ldr r6, _08005D4C @ =gUnknown_0202BF0C
	mov ip, r6
	ldr r0, _08005D5C @ =gUnknown_086A5DDA
	ldr r1, _08005D64 @ =gUnknown_086A5E1A
	mov sl, r1
	adds r4, r5, #0
	adds r4, #8
	adds r5, r0, #0
	adds r5, #8
	ldr r2, _08005D54 @ =0xFFFFFC00
	mov sb, r2
	ldr r3, _08005D40 @ =0xFFFFFE00
	mov r8, r3
	movs r7, #3
_08005C00:
	ldrh r3, [r4]
	lsls r3, r3, #3
	ldr r6, _08005D38 @ =gOamBuffer
	adds r3, r3, r6
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	add r0, sl
	ldrh r1, [r0]
	ldrh r6, [r5]
	adds r1, r1, r6
	ldr r2, _08005D60 @ =0x000003FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #4]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	ldrh r3, [r4]
	lsls r3, r3, #3
	ldr r6, _08005D38 @ =gOamBuffer
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	ldr r2, _08005D1C @ =gUnknown_0200B698
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r2, _08005D3C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	ldr r3, _08005D38 @ =gOamBuffer
	adds r1, r1, r3
	ldr r6, _08005D1C @ =gUnknown_0200B698
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #2
	subs r7, #1
	cmp r7, #0
	bge _08005C00
_08005C68:
	ldr r3, [sp]
	ldrh r0, [r3]
	cmp r0, #1
	bne _08005CD8
	movs r0, #0x24
	strh r0, [r3, #2]
	movs r0, #0x40
	strh r0, [r3, #4]
	ldr r1, _08005D2C @ =gUnknown_086A6148
	ldr r0, _08005D00 @ =gUnknown_0201A448
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r0, #5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r7, #0
	ldrh r6, [r5]
	cmp r7, r6
	bge _08005CD8
	ldr r0, _08005D38 @ =gOamBuffer
	mov sb, r0
	ldr r1, _08005D40 @ =0xFFFFFE00
	mov r8, r1
	adds r4, r3, #0
	adds r4, #8
_08005C9C:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r6, [sp]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r6, _08005D3C @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	ldr r2, [sp]
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	adds r7, #1
	ldrh r6, [r5]
	cmp r7, r6
	blt _08005C9C
_08005CD8:
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	cmp r0, #1
	bne _08005DD0
	ldr r0, _08005D04 @ =gUnknown_0202BEFC
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _08005CF0
	cmp r1, #4
	bne _08005D68
_08005CF0:
	movs r0, #0x78
	ldr r3, [sp, #4]
	strh r0, [r3, #2]
	movs r0, #0x64
	strh r0, [r3, #4]
	b _08005D72
	.align 2, 0
_08005CFC: .4byte gUnknown_0200B3B8
_08005D00: .4byte gUnknown_0201A448
_08005D04: .4byte gUnknown_0202BEFC
_08005D08: .4byte 0x00000C38
_08005D0C: .4byte gUnknown_0202A55C
_08005D10: .4byte gUnknown_0200B528
_08005D14: .4byte gUnknown_0202A568
_08005D18: .4byte gUnknown_0200B5E0
_08005D1C: .4byte gUnknown_0200B698
_08005D20: .4byte gUnknown_0202BEC4
_08005D24: .4byte gUnknown_0202C590
_08005D28: .4byte gUnknown_0200C4F8
_08005D2C: .4byte gUnknown_086A6148
_08005D30: .4byte gUnknown_0201A4F0
_08005D34: .4byte gUnknown_0202A57C
_08005D38: .4byte gOamBuffer
_08005D3C: .4byte 0x000001FF
_08005D40: .4byte 0xFFFFFE00
_08005D44: .4byte gUnknown_0202BF08
_08005D48: .4byte gPokedexSelectedMon
_08005D4C: .4byte gUnknown_0202BF0C
_08005D50: .4byte gUnknown_086A5DF2
_08005D54: .4byte 0xFFFFFC00
_08005D58: .4byte gUnknown_0202BF14
_08005D5C: .4byte gUnknown_086A5DDA
_08005D60: .4byte 0x000003FF
_08005D64: .4byte gUnknown_086A5E1A
_08005D68:
	movs r0, #0x78
	ldr r4, [sp, #4]
	strh r0, [r4, #2]
	movs r0, #0x50
	strh r0, [r4, #4]
_08005D72:
	ldr r1, _08005E4C @ =gUnknown_086A6148
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #0x11
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r7, #0
	ldrh r6, [r5]
	cmp r7, r6
	bge _08005DD0
	ldr r0, _08005E50 @ =gOamBuffer
	mov sb, r0
	ldr r1, _08005E54 @ =0xFFFFFE00
	mov r8, r1
	ldr r4, [sp, #4]
	adds r4, #8
_08005D94:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r6, [sp, #4]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r6, _08005E58 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	adds r7, #1
	ldrh r6, [r5]
	cmp r7, r6
	blt _08005D94
_08005DD0:
	ldr r1, _08005E5C @ =gUnknown_0200C4F8
	ldrh r0, [r1]
	cmp r0, #1
	bne _08005E34
	movs r0, #0xa8
	strh r0, [r1, #2]
	movs r0, #0x54
	strh r0, [r1, #4]
	ldr r5, _08005E50 @ =gOamBuffer
	ldr r2, _08005E54 @ =0xFFFFFE00
	mov r8, r2
	adds r4, r1, #0
	adds r4, #8
	movs r7, #2
_08005DEC:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r6, #2
	ldrsh r1, [r4, r6]
	ldr r2, _08005E5C @ =gUnknown_0200C4F8
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r2, _08005E58 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, _08005E5C @ =gUnknown_0200C4F8
	ldrb r0, [r3, #4]
	ldrb r6, [r4, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #8
	subs r7, #1
	cmp r7, #0
	bge _08005DEC
_08005E34:
	movs r0, #0
	ldr r1, [sp, #4]
	strh r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005E4C: .4byte gUnknown_086A6148
_08005E50: .4byte gOamBuffer
_08005E54: .4byte 0xFFFFFE00
_08005E58: .4byte 0x000001FF
_08005E5C: .4byte gUnknown_0200C4F8

	thumb_func_start sub_5E60
sub_5E60: @ 0x08005E60
	ldr r1, _08005E84 @ =gUnknown_0202C5F0
	movs r2, #0
	ldr r0, _08005E88 @ =0x0000DDDD
	strh r0, [r1]
	ldr r0, _08005E8C @ =gUnknown_0202C5B4
	movs r1, #1
	strh r1, [r0]
	ldr r0, _08005E90 @ =gUnknown_0201C180
	strh r1, [r0]
	ldr r0, _08005E94 @ =gUnknown_0201B128
	strb r2, [r0]
	ldr r0, _08005E98 @ =gUnknown_0201C1BC
	strb r2, [r0]
	ldr r0, _08005E9C @ =gUnknown_0202C544
	strb r2, [r0]
	ldr r0, _08005EA0 @ =gUnknown_0202BECC
	strb r2, [r0]
	bx lr
	.align 2, 0
_08005E84: .4byte gUnknown_0202C5F0
_08005E88: .4byte 0x0000DDDD
_08005E8C: .4byte gUnknown_0202C5B4
_08005E90: .4byte gUnknown_0201C180
_08005E94: .4byte gUnknown_0201B128
_08005E98: .4byte gUnknown_0201C1BC
_08005E9C: .4byte gUnknown_0202C544
_08005EA0: .4byte gUnknown_0202BECC

	thumb_func_start sub_5EA4
sub_5EA4: @ 0x08005EA4
	push {lr}
	ldr r0, _08005EB4 @ =gLink
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005EB8
	bl sub_639C
	b _08005EBC
	.align 2, 0
_08005EB4: .4byte gLink
_08005EB8:
	bl sub_65DC
_08005EBC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start sub_5EC8
sub_5EC8: @ 0x08005EC8
	push {lr}
	ldr r0, _08005ED8 @ =gLink
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005EDC
	bl sub_5EEC
	b _08005EE0
	.align 2, 0
_08005ED8: .4byte gLink
_08005EDC:
	bl sub_6144
_08005EE0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start sub_5EEC
sub_5EEC: @ 0x08005EEC
	push {r4, r5, lr}
	ldr r0, _08005F0C @ =gUnknown_0201B128
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08005F5C
	ldr r0, _08005F10 @ =gUnknown_0201C1BC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08005F14
	cmp r0, #1
	beq _08005F4C
	b _08006136
	.align 2, 0
_08005F0C: .4byte gUnknown_0201B128
_08005F10: .4byte gUnknown_0201C1BC
_08005F14:
	ldr r0, _08005F28 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08005F34
	ldr r1, _08005F2C @ =gUnknown_0202C5F0
	ldr r0, _08005F30 @ =0x0000FEFE
	strh r0, [r1]
	b _08006136
	.align 2, 0
_08005F28: .4byte gMain
_08005F2C: .4byte gUnknown_0202C5F0
_08005F30: .4byte 0x0000FEFE
_08005F34:
	ldr r1, _08005F48 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08005F3C:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08005F3C
	b _08006136
	.align 2, 0
_08005F48: .4byte gUnknown_0202C5F0
_08005F4C:
	ldr r1, _08005F54 @ =gUnknown_0202C5F0
	ldr r0, _08005F58 @ =0x0000ECEC
	strh r0, [r1]
	b _08006136
	.align 2, 0
_08005F54: .4byte gUnknown_0202C5F0
_08005F58: .4byte 0x0000ECEC
_08005F5C:
	ldr r0, _08005F78 @ =gUnknown_0201C180
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #7
	bhi _08005F84
	ldr r1, _08005F7C @ =gUnknown_0202C5F0
	ldr r2, _08005F80 @ =0x0000DDDD
	adds r0, r1, #0
	adds r0, #0xe
_08005F6E:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08005F6E
	b _08006130
	.align 2, 0
_08005F78: .4byte gUnknown_0201C180
_08005F7C: .4byte gUnknown_0202C5F0
_08005F80: .4byte 0x0000DDDD
_08005F84:
	cmp r1, #0xf
	bls _08005F8A
	b _08006120
_08005F8A:
	ldrh r2, [r5]
	adds r1, r2, #0
	subs r1, #8
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r4, _08006118 @ =gUnknown_0202C5F0
	strh r2, [r4]
	ldr r3, _0800611C @ =gUnknown_0202A1C0
	lsls r2, r0, #1
	adds r2, r2, r3
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #2]
	mov r2, ip
	adds r2, #4
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #6
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #7
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #4]
	mov r2, ip
	adds r2, #8
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #9
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0xa
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0xb
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #6]
	mov r2, ip
	adds r2, #0xc
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0xd
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0xe
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0xf
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #8]
	mov r2, ip
	adds r2, #0x10
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x11
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x12
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x13
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xa]
	mov r2, ip
	adds r2, #0x14
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x15
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x16
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x17
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xc]
	mov r2, ip
	adds r2, #0x18
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x19
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x1a
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x1b
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xe]
	b _08006130
	.align 2, 0
_08006118: .4byte gUnknown_0202C5F0
_0800611C: .4byte gUnknown_0202A1C0
_08006120:
	ldr r1, _08006140 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08006128:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08006128
_08006130:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08006136:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08006140: .4byte gUnknown_0202C5F0

	thumb_func_start sub_6144
sub_6144: @ 0x08006144
	push {r4, r5, lr}
	ldr r0, _08006164 @ =gUnknown_0201B128
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080061B4
	ldr r0, _08006168 @ =gUnknown_0202C544
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0800616C
	cmp r0, #1
	beq _080061A4
	b _0800638E
	.align 2, 0
_08006164: .4byte gUnknown_0201B128
_08006168: .4byte gUnknown_0202C544
_0800616C:
	ldr r0, _08006180 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800618C
	ldr r1, _08006184 @ =gUnknown_0202C5F0
	ldr r0, _08006188 @ =0x0000FEFE
	strh r0, [r1]
	b _0800638E
	.align 2, 0
_08006180: .4byte gMain
_08006184: .4byte gUnknown_0202C5F0
_08006188: .4byte 0x0000FEFE
_0800618C:
	ldr r1, _080061A0 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08006194:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08006194
	b _0800638E
	.align 2, 0
_080061A0: .4byte gUnknown_0202C5F0
_080061A4:
	ldr r1, _080061AC @ =gUnknown_0202C5F0
	ldr r0, _080061B0 @ =0x0000ECEC
	strh r0, [r1]
	b _0800638E
	.align 2, 0
_080061AC: .4byte gUnknown_0202C5F0
_080061B0: .4byte 0x0000ECEC
_080061B4:
	ldr r0, _080061D0 @ =gUnknown_0201C180
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #7
	bhi _080061DC
	ldr r1, _080061D4 @ =gUnknown_0202C5F0
	ldr r2, _080061D8 @ =0x0000DDDD
	adds r0, r1, #0
	adds r0, #0xe
_080061C6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080061C6
	b _08006388
	.align 2, 0
_080061D0: .4byte gUnknown_0201C180
_080061D4: .4byte gUnknown_0202C5F0
_080061D8: .4byte 0x0000DDDD
_080061DC:
	cmp r1, #0xf
	bls _080061E2
	b _08006378
_080061E2:
	ldrh r2, [r5]
	adds r1, r2, #0
	subs r1, #8
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x10
	mov ip, r0
	ldr r4, _08006370 @ =gUnknown_0202C5F0
	strh r2, [r4]
	ldr r3, _08006374 @ =gUnknown_0202A1C0
	lsls r2, r0, #1
	adds r2, r2, r3
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #2]
	mov r2, ip
	adds r2, #4
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #5
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #6
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #7
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #4]
	mov r2, ip
	adds r2, #8
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #9
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0xa
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0xb
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #6]
	mov r2, ip
	adds r2, #0xc
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0xd
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0xe
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0xf
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #8]
	mov r2, ip
	adds r2, #0x10
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x11
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x12
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x13
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xa]
	mov r2, ip
	adds r2, #0x14
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x15
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x16
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x17
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xc]
	mov r2, ip
	adds r2, #0x18
	lsls r2, r2, #1
	adds r2, r2, r3
	mov r0, ip
	adds r0, #0x19
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r1, r1, #4
	ldrh r0, [r2]
	orrs r1, r0
	mov r0, ip
	adds r0, #0x1a
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	mov r0, ip
	adds r0, #0x1b
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0xe]
	b _08006388
	.align 2, 0
_08006370: .4byte gUnknown_0202C5F0
_08006374: .4byte gUnknown_0202A1C0
_08006378:
	ldr r1, _08006398 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_08006380:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08006380
_08006388:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0800638E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08006398: .4byte gUnknown_0202C5F0

	thumb_func_start sub_639C
sub_639C: @ 0x0800639C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	ldr r4, _080063C0 @ =gUnknown_0201B128
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _08006438
	ldr r3, _080063C4 @ =gUnknown_0201C1BC
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r1, #0
	beq _080063C8
	cmp r1, #1
	beq _080063E8
	b _080065AA
	.align 2, 0
_080063C0: .4byte gUnknown_0201B128
_080063C4: .4byte gUnknown_0201C1BC
_080063C8:
	ldr r2, _080063E0 @ =gUnknown_0201A4D0
	ldrh r0, [r2]
	ldr r1, _080063E4 @ =0x0000FEFE
	cmp r0, r1
	beq _080063DA
	ldrh r0, [r2, #2]
	cmp r0, r1
	beq _080063DA
	b _080065AA
_080063DA:
	movs r0, #1
	strb r0, [r3]
	b _080065AA
	.align 2, 0
_080063E0: .4byte gUnknown_0201A4D0
_080063E4: .4byte 0x0000FEFE
_080063E8:
	ldr r3, _0800640C @ =gUnknown_0201A4D0
	ldrh r2, [r3]
	ldr r0, _08006410 @ =0x0000ECEC
	cmp r2, r0
	bne _0800641C
	ldrh r0, [r3, #2]
	cmp r0, r2
	bne _0800641C
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r4]
	ldr r0, _08006414 @ =gUnknown_0202BEFC
	strb r1, [r0]
	ldr r0, _08006418 @ =gUnknown_0201C180
	strh r1, [r0]
	b _080065AA
	.align 2, 0
_0800640C: .4byte gUnknown_0201A4D0
_08006410: .4byte 0x0000ECEC
_08006414: .4byte gUnknown_0202BEFC
_08006418: .4byte gUnknown_0201C180
_0800641C:
	ldr r1, _08006434 @ =gUnknown_0202BECC
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bgt _0800642E
	b _080065AA
_0800642E:
	movs r0, #1
	b _080065CC
	.align 2, 0
_08006434: .4byte gUnknown_0202BECC
_08006438:
	ldr r7, _0800656C @ =gUnknown_0201A4D0
	ldrh r1, [r7, #2]
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0800644A
	b _080065CA
_0800644A:
	ldr r0, _08006570 @ =gUnknown_0202C5B4
	mov r8, r0
	strh r1, [r0]
	mov r2, sp
	ldrh r1, [r7, #6]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xf0
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #2]
	movs r4, #0xf0
	lsls r4, r4, #4
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #4]
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #6]
	ldrh r1, [r7, #0xa]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #8]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0xa]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0xc]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0xe]
	ldrh r1, [r7, #0xe]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x10]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x12]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x14]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x16]
	ldrh r1, [r7, #0x12]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x18]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x1a]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x1c]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x1e]
	ldrh r1, [r7, #0x16]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x20]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x22]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x24]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x26]
	ldrh r1, [r7, #0x1a]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x28]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x2a]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x2c]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x2e]
	mov r1, sp
	ldrh r0, [r7, #0x1e]
	ands r6, r0
	strh r6, [r1, #0x30]
	ands r5, r0
	lsrs r5, r5, #4
	strh r5, [r1, #0x32]
	ands r4, r0
	lsrs r4, r4, #8
	strh r4, [r1, #0x34]
	ands r3, r0
	lsrs r3, r3, #0xc
	strh r3, [r1, #0x36]
	movs r3, #0
	ldr r6, _08006574 @ =gUnknown_0202A1C0
	ldr r5, _08006578 @ =gUnknown_0202A390
	mov r4, sp
_08006540:
	mov r2, r8
	ldrh r1, [r2]
	subs r1, #8
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r2, #1
	adds r0, r1, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bne _0800657C
	ldrh r0, [r4]
	cmp r0, #4
	bne _0800657C
	adds r1, r1, r5
	movs r0, #2
	b _08006592
	.align 2, 0
_0800656C: .4byte gUnknown_0201A4D0
_08006570: .4byte gUnknown_0202C5B4
_08006574: .4byte gUnknown_0202A1C0
_08006578: .4byte gUnknown_0202A390
_0800657C:
	lsls r1, r2, #1
	adds r0, r1, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bne _08006594
	ldrh r0, [r4]
	cmp r0, #4
	bne _08006594
	adds r1, r1, r5
	movs r0, #3
_08006592:
	strh r0, [r1]
_08006594:
	adds r4, #2
	adds r3, #1
	cmp r3, #0x1b
	ble _08006540
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #0xf
	bne _080065AA
	movs r0, #1
	rsbs r0, r0, #0
	b _080065CC
_080065AA:
	movs r3, #0
	ldr r5, _080065D8 @ =gUnknown_0201A4D0
	movs r4, #0
_080065B0:
	adds r2, r3, #1
	lsls r0, r3, #2
	movs r1, #1
	adds r0, r0, r5
	adds r0, #2
_080065BA:
	strh r4, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080065BA
	adds r3, r2, #0
	cmp r3, #7
	ble _080065B0
_080065CA:
	movs r0, #0
_080065CC:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080065D8: .4byte gUnknown_0201A4D0

	thumb_func_start sub_65DC
sub_65DC: @ 0x080065DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	ldr r4, _08006600 @ =gUnknown_0201B128
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _08006678
	ldr r3, _08006604 @ =gUnknown_0202C544
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r1, #0
	beq _08006608
	cmp r1, #1
	beq _08006628
	b _080067EA
	.align 2, 0
_08006600: .4byte gUnknown_0201B128
_08006604: .4byte gUnknown_0202C544
_08006608:
	ldr r2, _08006620 @ =gUnknown_0201A4D0
	ldrh r0, [r2]
	ldr r1, _08006624 @ =0x0000FEFE
	cmp r0, r1
	beq _0800661A
	ldrh r0, [r2, #2]
	cmp r0, r1
	beq _0800661A
	b _080067EA
_0800661A:
	movs r0, #1
	strb r0, [r3]
	b _080067EA
	.align 2, 0
_08006620: .4byte gUnknown_0201A4D0
_08006624: .4byte 0x0000FEFE
_08006628:
	ldr r3, _0800664C @ =gUnknown_0201A4D0
	ldrh r2, [r3]
	ldr r0, _08006650 @ =0x0000ECEC
	cmp r2, r0
	bne _0800665C
	ldrh r0, [r3, #2]
	cmp r0, r2
	bne _0800665C
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r4]
	ldr r0, _08006654 @ =gUnknown_0202BEFC
	strb r1, [r0]
	ldr r0, _08006658 @ =gUnknown_0201C180
	strh r1, [r0]
	b _080067EA
	.align 2, 0
_0800664C: .4byte gUnknown_0201A4D0
_08006650: .4byte 0x0000ECEC
_08006654: .4byte gUnknown_0202BEFC
_08006658: .4byte gUnknown_0201C180
_0800665C:
	ldr r1, _08006674 @ =gUnknown_0202BECC
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bgt _0800666E
	b _080067EA
_0800666E:
	movs r0, #1
	b _0800680C
	.align 2, 0
_08006674: .4byte gUnknown_0202BECC
_08006678:
	ldr r7, _080067AC @ =gUnknown_0201A4D0
	ldrh r1, [r7]
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _0800668A
	b _0800680A
_0800668A:
	ldr r0, _080067B0 @ =gUnknown_0202C5B4
	mov r8, r0
	strh r1, [r0]
	mov r2, sp
	ldrh r1, [r7, #4]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xf0
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #2]
	movs r4, #0xf0
	lsls r4, r4, #4
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #4]
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #6]
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #8]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0xa]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0xc]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0xe]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x10]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x12]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x14]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x16]
	ldrh r1, [r7, #0x10]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x18]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x1a]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x1c]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x1e]
	ldrh r1, [r7, #0x14]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x20]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x22]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x24]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x26]
	ldrh r1, [r7, #0x18]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2, #0x28]
	adds r0, r5, #0
	ands r0, r1
	lsrs r0, r0, #4
	strh r0, [r2, #0x2a]
	adds r0, r4, #0
	ands r0, r1
	lsrs r0, r0, #8
	strh r0, [r2, #0x2c]
	adds r0, r3, #0
	ands r0, r1
	lsrs r0, r0, #0xc
	strh r0, [r2, #0x2e]
	mov r1, sp
	ldrh r0, [r7, #0x1c]
	ands r6, r0
	strh r6, [r1, #0x30]
	ands r5, r0
	lsrs r5, r5, #4
	strh r5, [r1, #0x32]
	ands r4, r0
	lsrs r4, r4, #8
	strh r4, [r1, #0x34]
	ands r3, r0
	lsrs r3, r3, #0xc
	strh r3, [r1, #0x36]
	movs r3, #0
	ldr r6, _080067B4 @ =gUnknown_0202A1C0
	ldr r5, _080067B8 @ =gUnknown_0202A390
	mov r4, sp
_08006780:
	mov r2, r8
	ldrh r1, [r2]
	subs r1, #8
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r2, #1
	adds r0, r1, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bne _080067BC
	ldrh r0, [r4]
	cmp r0, #4
	bne _080067BC
	adds r1, r1, r5
	movs r0, #2
	b _080067D2
	.align 2, 0
_080067AC: .4byte gUnknown_0201A4D0
_080067B0: .4byte gUnknown_0202C5B4
_080067B4: .4byte gUnknown_0202A1C0
_080067B8: .4byte gUnknown_0202A390
_080067BC:
	lsls r1, r2, #1
	adds r0, r1, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bne _080067D4
	ldrh r0, [r4]
	cmp r0, #4
	bne _080067D4
	adds r1, r1, r5
	movs r0, #3
_080067D2:
	strh r0, [r1]
_080067D4:
	adds r4, #2
	adds r3, #1
	cmp r3, #0x1b
	ble _08006780
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #0xf
	bne _080067EA
	movs r0, #1
	rsbs r0, r0, #0
	b _0800680C
_080067EA:
	movs r3, #0
	ldr r5, _08006818 @ =gUnknown_0201A4D0
	movs r4, #0
_080067F0:
	adds r2, r3, #1
	lsls r0, r3, #2
	movs r1, #1
	adds r0, r0, r5
	adds r0, #2
_080067FA:
	strh r4, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080067FA
	adds r3, r2, #0
	cmp r3, #7
	ble _080067F0
_0800680A:
	movs r0, #0
_0800680C:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08006818: .4byte gUnknown_0201A4D0

	thumb_func_start sub_681C
sub_681C: @ 0x0800681C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	add r2, sp, #8
	movs r1, #0
	strh r1, [r2]
	ldr r2, _08006884 @ =0x040000D4
	add r1, sp, #8
	str r1, [r2]
	ldr r1, _08006888 @ =gUnknown_03000000
	str r1, [r2, #4]
	ldr r1, _0800688C @ =0x81000400
	str r1, [r2, #8]
	ldr r1, [r2, #8]
	movs r2, #0
	mov r8, r2
	lsls r7, r0, #0x10
	asrs r2, r7, #0x10
	cmp r2, #0xc8
	bne _080068CC
	ldr r0, _08006890 @ =gUnknown_0202A1C0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08006894
	movs r5, #1
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r0, #0x22
	movs r1, #1
	movs r2, #5
	movs r3, #2
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x21
	b _080068BE
	.align 2, 0
_08006884: .4byte 0x040000D4
_08006888: .4byte gUnknown_03000000
_0800688C: .4byte 0x81000400
_08006890: .4byte gUnknown_0202A1C0
_08006894:
	movs r5, #1
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r0, #0x2a
	movs r1, #1
	movs r2, #5
	movs r3, #2
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x2a
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x2a
_080068BE:
	movs r1, #1
	movs r2, #7
	movs r3, #2
	bl sub_105A0
	mov sb, r7
	b _08006900
_080068CC:
	movs r6, #0
	mov sb, r7
	ldr r1, _08006998 @ =gUnknown_0805C8B4
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r4, r0, r1
_080068DE:
	ldrh r0, [r4]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #5
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #1
	movs r3, #2
	bl sub_105A0
	adds r4, #2
	adds r6, #1
	cmp r6, #2
	ble _080068DE
_08006900:
	ldr r0, _0800699C @ =gUnknown_0202A1C0
	mov r3, sb
	asrs r2, r3, #0x10
	lsls r1, r2, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080069C4
	movs r6, #0
	ldr r1, _080069A0 @ =gUnknown_0805C8CC
	ldr r5, _080069A4 @ =0x040000D4
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r7, r0, r1
_08006924:
	ldrh r1, [r7]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r2, #0
	adds r3, r0, #0
	ands r3, r1
	movs r4, #0xf
	ands r4, r1
	cmp r4, #0
	bne _0800693A
	movs r4, #4
_0800693A:
	ldr r1, _080069A8 @ =gUnknown_08090780
	adds r0, r3, r1
	str r0, [r5]
	ldr r0, _080069AC @ =gUnknown_0202BE30
	str r0, [r5, #4]
	ldr r2, _080069B0 @ =0x80000010
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r3, r1
	str r1, [r5]
	ldr r0, _080069B4 @ =gUnknown_0201B130
	str r0, [r5, #4]
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl sub_71DC
	add r8, r4
	adds r7, #2
	adds r6, #1
	cmp r6, #9
	ble _08006924
	ldr r4, _080069B8 @ =gUnknown_03000000
	ldr r1, _080069BC @ =0x06004C00
	adds r0, r4, #0
	movs r2, #8
	movs r3, #2
	bl sub_10708
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080069A4 @ =0x040000D4
	str r1, [r0]
	str r4, [r0, #4]
	ldr r1, _080069C0 @ =0x81000400
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r1, #0
	mov r8, r1
	b _080069DC
	.align 2, 0
_08006998: .4byte gUnknown_0805C8B4
_0800699C: .4byte gUnknown_0202A1C0
_080069A0: .4byte gUnknown_0805C8CC
_080069A4: .4byte 0x040000D4
_080069A8: .4byte gUnknown_08090780
_080069AC: .4byte gUnknown_0202BE30
_080069B0: .4byte 0x80000010
_080069B4: .4byte gUnknown_0201B130
_080069B8: .4byte gUnknown_03000000
_080069BC: .4byte 0x06004C00
_080069C0: .4byte 0x81000400
_080069C4:
	ldr r4, _08006A74 @ =0x06004C00
	movs r6, #9
_080069C8:
	ldr r0, _08006A78 @ =gUnknown_08092FA0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080069C8
_080069DC:
	ldr r1, _08006A7C @ =gUnknown_0202A1C0
	mov r3, sb
	asrs r2, r3, #0x10
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _080069F2
	cmp r0, #2
	ble _08006AA4
_080069F2:
	movs r6, #0
	ldr r1, _08006A80 @ =gUnknown_0805C8E0
	ldr r5, _08006A84 @ =0x040000D4
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r7, r0, r1
_08006A04:
	ldrh r1, [r7]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r2, #0
	adds r3, r0, #0
	ands r3, r1
	movs r4, #0xf
	ands r4, r1
	cmp r4, #0
	bne _08006A1A
	movs r4, #6
_08006A1A:
	ldr r1, _08006A88 @ =gUnknown_08090780
	adds r0, r3, r1
	str r0, [r5]
	ldr r0, _08006A8C @ =gUnknown_0202BE30
	str r0, [r5, #4]
	ldr r2, _08006A90 @ =0x80000010
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r3, r1
	str r1, [r5]
	ldr r0, _08006A94 @ =gUnknown_0201B130
	str r0, [r5, #4]
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl sub_71DC
	add r8, r4
	adds r7, #2
	adds r6, #1
	cmp r6, #0xa
	ble _08006A04
	ldr r4, _08006A98 @ =gUnknown_03000000
	ldr r1, _08006A9C @ =0x06004D00
	adds r0, r4, #0
	movs r2, #9
	movs r3, #2
	bl sub_10708
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08006A84 @ =0x040000D4
	str r1, [r0]
	str r4, [r0, #4]
	ldr r1, _08006AA0 @ =0x81000400
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	b _08006ABC
	.align 2, 0
_08006A74: .4byte 0x06004C00
_08006A78: .4byte gUnknown_08092FA0
_08006A7C: .4byte gUnknown_0202A1C0
_08006A80: .4byte gUnknown_0805C8E0
_08006A84: .4byte 0x040000D4
_08006A88: .4byte gUnknown_08090780
_08006A8C: .4byte gUnknown_0202BE30
_08006A90: .4byte 0x80000010
_08006A94: .4byte gUnknown_0201B130
_08006A98: .4byte gUnknown_03000000
_08006A9C: .4byte 0x06004D00
_08006AA0: .4byte 0x81000400
_08006AA4:
	ldr r4, _08006B6C @ =0x06004D00
	movs r6, #8
_08006AA8:
	ldr r0, _08006B70 @ =gUnknown_08092FA0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _08006AA8
_08006ABC:
	ldr r0, _08006B74 @ =gUnknown_0202A1C0
	mov r1, sb
	asrs r2, r1, #0x10
	lsls r1, r2, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #4
	bne _08006B7C
	ldr r0, _08006B78 @ =gUnknown_0805C8B4
	mov sb, r0
	lsls r4, r2, #3
	adds r4, r4, r2
	lsls r4, r4, #4
	subs r4, r4, r2
	lsls r4, r4, #2
	adds r1, r4, #0
	add r1, sb
	mov r8, r1
	ldrh r0, [r1, #6]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r6, #1
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r1, #1
	movs r2, #0x10
	movs r3, #6
	bl sub_105A0
	mov r2, r8
	ldrh r0, [r2, #8]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #1
	movs r2, #0x11
	movs r3, #6
	bl sub_105A0
	mov r3, r8
	ldrh r0, [r3, #0xa]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #1
	movs r2, #0x13
	movs r3, #6
	bl sub_105A0
	mov r1, r8
	ldrh r0, [r1, #0xc]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #1
	movs r2, #0x14
	movs r3, #6
	bl sub_105A0
	movs r6, #0
	movs r2, #0xe
	add sb, r2
	add r4, sb
	movs r5, #1
_08006B4E:
	ldrh r0, [r4]
	adds r2, r6, #0
	adds r2, #0x10
	str r5, [sp]
	str r5, [sp, #4]
	movs r1, #1
	movs r3, #8
	bl sub_105A0
	adds r4, #2
	adds r6, #1
	cmp r6, #4
	ble _08006B4E
	b _08006BDC
	.align 2, 0
_08006B6C: .4byte 0x06004D00
_08006B70: .4byte gUnknown_08092FA0
_08006B74: .4byte gUnknown_0202A1C0
_08006B78: .4byte gUnknown_0805C8B4
_08006B7C:
	movs r5, #1
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	movs r0, #0x2b
	movs r1, #1
	movs r2, #0x10
	movs r3, #6
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x2b
	movs r1, #1
	movs r2, #0x11
	movs r3, #6
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x2b
	movs r1, #1
	movs r2, #0x13
	movs r3, #6
	bl sub_105A0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0x2b
	movs r1, #1
	movs r2, #0x14
	movs r3, #6
	bl sub_105A0
	movs r6, #0
	movs r4, #1
_08006BC4:
	adds r2, r6, #0
	adds r2, #0x10
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0xb
	movs r1, #1
	movs r3, #8
	bl sub_105A0
	adds r6, #1
	cmp r6, #4
	ble _08006BC4
_08006BDC:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_6BEC
sub_6BEC: @ 0x08006BEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r6, #0
	movs r1, #0x64
	bl __divsi3
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #0x64
	bl __modsi3
	adds r5, r0, #0
	movs r1, #0xa
	bl __divsi3
	str r0, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0xa
	bl __modsi3
	str r0, [sp, #0x10]
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	add r5, sp, #0x14
	adds r0, r6, #0
	movs r1, #0x64
	bl __divsi3
	str r0, [sp, #0x14]
	adds r0, r6, #0
	movs r1, #0x64
	bl __modsi3
	adds r4, r0, #0
	movs r1, #0xa
	bl __divsi3
	str r0, [r5, #4]
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	str r0, [r5, #8]
	movs r6, #0
	movs r7, #1
	mov r8, r5
	add r5, sp, #8
_08006C58:
	ldm r5!, {r0}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r6, #0
	adds r4, #0x19
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #2
	adds r2, r4, #0
	movs r3, #0xf
	bl sub_105A0
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r0}
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	adds r2, r4, #0
	movs r3, #0x10
	bl sub_105A0
	adds r6, #1
	cmp r6, #2
	ble _08006C58
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_6CA0
sub_6CA0: @ 0x08006CA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08006D2C @ =0x040000D4
	add r0, sp, #8
	str r0, [r1]
	ldr r0, _08006D30 @ =gUnknown_03000000
	str r0, [r1, #4]
	ldr r0, _08006D34 @ =0x81000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0
	str r1, [sp, #0x10]
	mov r8, r1
	ldr r2, [sp, #0xc]
	lsls r2, r2, #0x10
	str r2, [sp, #0x14]
	movs r3, #1
	mov sb, r3
	movs r5, #2
	movs r4, #0
	str r4, [sp, #0x18]
	movs r4, #0xa
_08006CE0:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	add r0, r8
	cmp r0, #0xc8
	bne _08006D74
	ldr r0, _08006D38 @ =gUnknown_0202A1C0
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _08006D3C
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x22
	movs r1, #2
	movs r2, #8
	adds r3, r4, #0
	bl sub_105A0
	mov r1, sb
	str r1, [sp]
	str r5, [sp, #4]
	movs r0, #0x20
	movs r1, #2
	movs r2, #9
	adds r3, r4, #0
	bl sub_105A0
	mov r2, sb
	str r2, [sp]
	str r5, [sp, #4]
	movs r0, #0x21
	b _08006D68
	.align 2, 0
_08006D2C: .4byte 0x040000D4
_08006D30: .4byte gUnknown_03000000
_08006D34: .4byte 0x81000400
_08006D38: .4byte gUnknown_0202A1C0
_08006D3C:
	mov r3, sb
	str r3, [sp]
	str r5, [sp, #4]
	movs r0, #0x2a
	movs r1, #2
	movs r2, #8
	adds r3, r4, #0
	bl sub_105A0
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x2a
	movs r1, #2
	movs r2, #9
	adds r3, r4, #0
	bl sub_105A0
	mov r1, sb
	str r1, [sp]
	str r5, [sp, #4]
	movs r0, #0x2a
_08006D68:
	movs r1, #2
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_105A0
	b _08006DB6
_08006D74:
	movs r6, #0
	ldr r7, [sp, #0x18]
	ldr r2, _08006E94 @ =gUnknown_0805C8B4
	mov sl, r2
_08006D7C:
	lsls r2, r6, #1
	ldr r0, _08006E98 @ =gUnknown_0202C5B0
	movs r3, #0
	ldrsh r1, [r0, r3]
	add r1, r8
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	add r2, sl
	ldrh r0, [r2]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #0
	adds r2, #8
	mov r1, sb
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #2
	adds r3, r7, #0
	adds r3, #0xa
	bl sub_105A0
	adds r6, #1
	cmp r6, #2
	ble _08006D7C
_08006DB6:
	ldr r2, [sp, #0x18]
	adds r2, #2
	str r2, [sp, #0x18]
	adds r4, #2
	movs r3, #1
	add r8, r3
	mov r0, r8
	cmp r0, #4
	ble _08006CE0
	movs r1, #0
	mov r8, r1
_08006DCC:
	ldr r0, _08006E9C @ =gUnknown_0202A1C0
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	add r1, r8
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08006EC4
	movs r6, #0
	mov r4, r8
	lsls r7, r4, #1
	movs r0, #1
	add r0, r8
	mov sb, r0
	ldr r5, _08006EA0 @ =0x040000D4
	ldr r3, _08006EA4 @ =gUnknown_08090780
	movs r1, #0x80
	lsls r1, r1, #3
	adds r1, r1, r3
	mov sl, r1
_08006DF8:
	lsls r2, r6, #1
	ldr r0, _08006E98 @ =gUnknown_0202C5B0
	movs r4, #0
	ldrsh r1, [r0, r4]
	add r1, r8
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _08006EA8 @ =gUnknown_0805C8CC
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r2, #0
	adds r2, r1, #0
	ands r2, r0
	movs r4, #0xf
	ands r4, r1
	cmp r4, #0
	bne _08006E28
	movs r4, #4
_08006E28:
	adds r0, r2, r3
	str r0, [r5]
	ldr r0, _08006EAC @ =gUnknown_0202BE30
	str r0, [r5, #4]
	ldr r0, _08006EB0 @ =0x80000010
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	mov r1, sl
	adds r0, r2, r1
	str r0, [r5]
	ldr r0, _08006EB4 @ =gUnknown_0201B130
	str r0, [r5, #4]
	ldr r2, _08006EB0 @ =0x80000010
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	adds r0, r4, #0
	ldr r1, [sp, #0x10]
	movs r2, #0
	str r3, [sp, #0x1c]
	bl sub_71DC
	ldr r0, [sp, #0x10]
	adds r0, r0, r4
	str r0, [sp, #0x10]
	adds r6, #1
	ldr r3, [sp, #0x1c]
	cmp r6, #9
	ble _08006DF8
	ldr r1, _08006EB8 @ =gUnknown_086A64F0
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xc0
	lsls r3, r3, #0x13
	adds r1, r1, r3
	ldr r0, _08006EBC @ =gUnknown_03000000
	movs r2, #8
	movs r3, #2
	bl sub_10708
	add r1, sp, #8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08006EA0 @ =0x040000D4
	add r4, sp, #8
	str r4, [r1]
	ldr r0, _08006EBC @ =gUnknown_03000000
	str r0, [r1, #4]
	ldr r0, _08006EC0 @ =0x81000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0
	str r1, [sp, #0x10]
	b _08006F06
	.align 2, 0
_08006E94: .4byte gUnknown_0805C8B4
_08006E98: .4byte gUnknown_0202C5B0
_08006E9C: .4byte gUnknown_0202A1C0
_08006EA0: .4byte 0x040000D4
_08006EA4: .4byte gUnknown_08090780
_08006EA8: .4byte gUnknown_0805C8CC
_08006EAC: .4byte gUnknown_0202BE30
_08006EB0: .4byte 0x80000010
_08006EB4: .4byte gUnknown_0201B130
_08006EB8: .4byte gUnknown_086A64F0
_08006EBC: .4byte gUnknown_03000000
_08006EC0: .4byte 0x81000400
_08006EC4:
	mov r2, r8
	lsls r7, r2, #1
	movs r3, #1
	add r3, r8
	mov sb, r3
	ldr r4, _08006F20 @ =gUnknown_086A64F0
	adds r5, r7, r4
	movs r4, #0xc0
	lsls r4, r4, #0x13
	movs r6, #6
_08006ED8:
	movs r0, #0
	ldrsh r1, [r5, r0]
	adds r1, r1, r4
	ldr r0, _08006F24 @ =gUnknown_08092FA0
	movs r2, #1
	movs r3, #2
	bl sub_10708
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _08006ED8
	ldr r1, _08006F20 @ =gUnknown_086A64F0
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08006F28 @ =0x060000E0
	adds r1, r1, r3
	ldr r0, _08006F2C @ =gUnknown_08090780
	movs r2, #1
	movs r3, #2
	bl sub_10708
_08006F06:
	mov r8, sb
	mov r4, r8
	cmp r4, #4
	bgt _08006F10
	b _08006DCC
_08006F10:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006F20: .4byte gUnknown_086A64F0
_08006F24: .4byte gUnknown_08092FA0
_08006F28: .4byte 0x060000E0
_08006F2C: .4byte gUnknown_08090780

	thumb_func_start sub_6F30
sub_6F30: @ 0x08006F30
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _08006F74 @ =gUnknown_0202A1C0
	lsls r0, r0, #0x10
	movs r6, #0xa
	asrs r0, r0, #0xf
	adds r4, r0, r1
	movs r7, #2
	movs r5, #4
_08006F42:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	cmp r0, #4
	bne _08006F50
	adds r1, #2
_08006F50:
	adds r0, r1, #0
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #1
	movs r2, #4
	adds r3, r6, #0
	bl sub_105A0
	adds r6, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _08006F42
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006F74: .4byte gUnknown_0202A1C0

	thumb_func_start sub_6F78
sub_6F78: @ 0x08006F78
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08006FBC @ =gUnknown_0202A1C0
	ldr r0, _08006FC0 @ =gPokedexSelectedMon
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0xf
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xf
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r5, #0x10
	asrs r0, r5, #0x10
	cmp r0, #4
	bls _08006FB0
	b _080070C0
_08006FB0:
	lsls r0, r0, #2
	ldr r1, _08006FC4 @ =_08006FC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006FBC: .4byte gUnknown_0202A1C0
_08006FC0: .4byte gPokedexSelectedMon
_08006FC4: .4byte _08006FC8
_08006FC8: @ jump table
	.4byte _08006FDC @ case 0
	.4byte _08007000 @ case 1
	.4byte _08007040 @ case 2
	.4byte _08007040 @ case 3
	.4byte _08007088 @ case 4
_08006FDC:
	ldr r0, _08006FF0 @ =gUnknown_0808F760
	ldr r1, _08006FF4 @ =0x06013400
	movs r2, #0x18
	movs r3, #1
	bl sub_10708
	ldr r1, _08006FF8 @ =0x040000D4
	ldr r0, _08006FFC @ =gUnknown_08089960
	b _080070B4
	.align 2, 0
_08006FF0: .4byte gUnknown_0808F760
_08006FF4: .4byte 0x06013400
_08006FF8: .4byte 0x040000D4
_08006FFC: .4byte gUnknown_08089960
_08007000:
	ldr r0, _08007030 @ =gMonPortraitGroupGfx
	lsls r2, r6, #0x10
	asrs r2, r2, #0xe
	adds r2, r2, r0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _08007034 @ =0x06013400
	movs r2, #0x18
	movs r3, #1
	bl sub_10708
	ldr r1, _08007038 @ =0x040000D4
	ldr r0, _0800703C @ =gMonPortraitGroupPals
	ldr r0, [r0]
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r0, r0, r2
	b _080070B4
	.align 2, 0
_08007030: .4byte gMonPortraitGroupGfx
_08007034: .4byte 0x06013400
_08007038: .4byte 0x040000D4
_0800703C: .4byte gMonPortraitGroupPals
_08007040:
	ldr r0, _08007078 @ =gMonPortraitGroupGfx
	lsls r5, r6, #0x10
	asrs r5, r5, #0xe
	adds r0, r5, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _0800707C @ =0x06013400
	movs r2, #0x18
	movs r3, #1
	bl sub_10708
	ldr r0, _08007080 @ =gMonPortraitGroupPals
	adds r5, r5, r0
	lsls r4, r4, #5
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r1, _08007084 @ =0x05000220
	movs r2, #0x20
	movs r3, #0xe
	bl sub_10170
	b _080070C0
	.align 2, 0
_08007078: .4byte gMonPortraitGroupGfx
_0800707C: .4byte 0x06013400
_08007080: .4byte gMonPortraitGroupPals
_08007084: .4byte 0x05000220
_08007088:
	ldr r0, _080070C8 @ =gMonPortraitGroupGfx
	lsls r5, r6, #0x10
	asrs r5, r5, #0xe
	adds r0, r5, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #8
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _080070CC @ =0x06013400
	movs r2, #0x18
	movs r3, #1
	bl sub_10708
	ldr r1, _080070D0 @ =0x040000D4
	ldr r0, _080070D4 @ =gMonPortraitGroupPals
	adds r5, r5, r0
	lsls r4, r4, #5
	ldr r0, [r5]
	adds r0, r0, r4
_080070B4:
	str r0, [r1]
	ldr r0, _080070D8 @ =0x05000220
	str r0, [r1, #4]
	ldr r0, _080070DC @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_080070C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080070C8: .4byte gMonPortraitGroupGfx
_080070CC: .4byte 0x06013400
_080070D0: .4byte 0x040000D4
_080070D4: .4byte gMonPortraitGroupPals
_080070D8: .4byte 0x05000220
_080070DC: .4byte 0x80000010

	thumb_func_start sub_70E0
sub_70E0: @ 0x080070E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r2, #0
	mov r8, r2
	mov r2, sp
	mov r3, r8
	strh r3, [r2]
	ldr r3, _080071B4 @ =0x040000D4
	str r2, [r3]
	ldr r2, _080071B8 @ =gUnknown_03000000
	str r2, [r3, #4]
	ldr r2, _080071BC @ =0x81000C00
	str r2, [r3, #8]
	ldr r2, [r3, #8]
	movs r7, #0
	lsls r2, r1, #6
	lsls r0, r0, #0x10
	str r0, [sp, #8]
	subs r2, r2, r1
	lsls r2, r2, #1
	str r2, [sp, #4]
	adds r5, r3, #0
_08007114:
	movs r6, #0
	adds r0, r7, #1
	mov sl, r0
	movs r1, #0x2a
	adds r0, r7, #0
	muls r0, r1, r0
	ldr r2, [sp, #4]
	adds r2, r2, r0
	mov sb, r2
_08007126:
	mov r3, sb
	adds r1, r3, r6
	lsls r1, r1, #1
	ldr r0, [sp, #8]
	asrs r2, r0, #0x10
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _080071C0 @ =gUnknown_0805C8F6
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r3, #0x10
	rsbs r3, r3, #0
	adds r0, r3, #0
	adds r3, r1, #0
	ands r3, r0
	movs r4, #0xf
	ands r4, r1
	cmp r4, #0
	bne _08007156
	movs r4, #4
_08007156:
	ldr r1, _080071C4 @ =gUnknown_08090780
	adds r0, r3, r1
	str r0, [r5]
	ldr r0, _080071C8 @ =gUnknown_0202BE30
	str r0, [r5, #4]
	ldr r2, _080071CC @ =0x80000010
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r3, r1
	str r1, [r5]
	ldr r0, _080071D0 @ =gUnknown_0201B130
	str r0, [r5, #4]
	str r2, [r5, #8]
	ldr r0, [r5, #8]
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl sub_71DC
	add r8, r4
	adds r6, #1
	cmp r6, #0x29
	ble _08007126
	movs r1, #0
	mov r8, r1
	mov r7, sl
	cmp r7, #2
	ble _08007114
	ldr r1, _080071B4 @ =0x040000D4
	ldr r0, _080071B8 @ =gUnknown_03000000
	str r0, [r1]
	ldr r0, _080071D4 @ =0x06005C00
	str r0, [r1, #4]
	ldr r0, _080071D8 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080071B4: .4byte 0x040000D4
_080071B8: .4byte gUnknown_03000000
_080071BC: .4byte 0x81000C00
_080071C0: .4byte gUnknown_0805C8F6
_080071C4: .4byte gUnknown_08090780
_080071C8: .4byte gUnknown_0202BE30
_080071CC: .4byte 0x80000010
_080071D0: .4byte gUnknown_0201B130
_080071D4: .4byte 0x06005C00
_080071D8: .4byte 0x80000C00

	thumb_func_start sub_71DC
sub_71DC: @ 0x080071DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	adds r3, r1, #0
	adds r0, r3, #0
	cmp r3, #0
	bge _080071F4
	adds r0, r3, #7
_080071F4:
	asrs r0, r0, #3
	lsls r0, r0, #4
	lsls r1, r2, #0xa
	adds r2, r0, r1
	subs r0, r4, #2
	cmp r0, #4
	bls _08007206
	bl _080088C8
_08007206:
	lsls r0, r0, #2
	ldr r1, _08007210 @ =_08007214
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08007210: .4byte _08007214
_08007214: @ jump table
	.4byte _08008580 @ case 0
	.4byte _0800819C @ case 1
	.4byte _08007D50 @ case 2
	.4byte _0800780C @ case 3
	.4byte _08007228 @ case 4
_08007228:
	adds r0, r3, #0
	cmp r3, #0
	bge _08007230
	adds r0, r3, #7
_08007230:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r3, r0
	cmp r0, #7
	bls _0800723E
	bl _080088C8
_0800723E:
	lsls r0, r0, #2
	ldr r1, _08007248 @ =_0800724C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08007248: .4byte _0800724C
_0800724C: @ jump table
	.4byte _0800726C @ case 0
	.4byte _080072EC @ case 1
	.4byte _08007398 @ case 2
	.4byte _0800744C @ case 3
	.4byte _08007548 @ case 4
	.4byte _080075C0 @ case 5
	.4byte _0800766C @ case 6
	.4byte _08007714 @ case 7
_0800726C:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	ldr r1, _080072E0 @ =gUnknown_03000000
	mov sb, r1
	movs r0, #0xff
	mov sl, r0
	ldr r1, _080072E4 @ =gUnknown_0201B130
	mov r8, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r5, r0, r2
	ldr r6, _080072E8 @ =gUnknown_0202BE30
	lsls r1, r1, #1
	adds r4, r1, r2
_08007290:
	lsls r3, r7, #1
	ldrh r0, [r5]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r5]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	ldrh r1, [r6, #2]
	mov r0, sl
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r3, r0
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r2, #2]
	mov r0, sl
	ands r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #4
	add r8, r1
	adds r4, #4
	adds r5, #4
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007290
	bl _080088C8
	.align 2, 0
_080072E0: .4byte gUnknown_03000000
_080072E4: .4byte gUnknown_0201B130
_080072E8: .4byte gUnknown_0202BE30
_080072EC:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	ldr r1, _08007388 @ =gUnknown_03000000
	mov sl, r1
	ldr r0, _0800738C @ =gUnknown_0201B130
	mov sb, r0
	ldr r1, _08007390 @ =gUnknown_0202BE30
	mov r8, r1
	lsls r0, r2, #1
	mov r2, sl
	adds r6, r0, r2
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r5, r0, r2
_0800730C:
	lsls r4, r7, #1
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _08007394 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r4, ip
	lsls r3, r4, #1
	add r3, sl
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r2, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, _08007394 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #1
	add r4, sl
	mov r2, sb
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r2, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r0, #4
	add sb, r0
	add r8, r0
	adds r6, #4
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _0800730C
	bl _080088C8
	.align 2, 0
_08007388: .4byte gUnknown_03000000
_0800738C: .4byte gUnknown_0201B130
_08007390: .4byte gUnknown_0202BE30
_08007394: .4byte 0x00000FFF
_08007398:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	movs r0, #0xff
	mov sl, r0
	ldr r1, _08007440 @ =gUnknown_0201B130
	mov sb, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08007444 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r0, r2, #1
	ldr r2, _08007448 @ =gUnknown_03000000
	adds r6, r0, r2
	lsls r1, r1, #1
	adds r5, r1, r2
_080073BA:
	lsls r4, r7, #1
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r4, ip
	lsls r3, r4, #1
	ldr r1, _08007448 @ =gUnknown_03000000
	adds r3, r3, r1
	mov r2, r8
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r2, #2]
	mov r0, sl
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	mov r0, sb
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #1
	ldr r2, _08007448 @ =gUnknown_03000000
	adds r4, r4, r2
	mov r1, sb
	ldrh r0, [r1]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	mov r0, sb
	ldrh r2, [r0, #2]
	mov r0, sl
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #4
	add sb, r1
	adds r5, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _080073BA
	bl _080088C8
	.align 2, 0
_08007440: .4byte gUnknown_0201B130
_08007444: .4byte gUnknown_0202BE30
_08007448: .4byte gUnknown_03000000
_0800744C:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	movs r1, #0x10
	adds r1, r1, r2
	mov sb, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #2
	str r0, [sp, #8]
	ldr r0, _08007538 @ =gUnknown_0202BE30
	mov sl, r0
	lsls r0, r2, #1
	ldr r2, _0800753C @ =gUnknown_03000000
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _08007540 @ =gUnknown_0201B130
	str r0, [sp, #0x10]
	lsls r1, r1, #1
	adds r6, r1, r2
_08007476:
	lsls r5, r7, #1
	mov r2, sl
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r0, ip
	adds r4, r5, r0
	lsls r3, r4, #1
	ldr r1, _0800753C @ =gUnknown_03000000
	adds r3, r3, r1
	mov r2, sl
	ldrh r0, [r2]
	ldr r1, _08007544 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	add r5, sb
	lsls r2, r5, #1
	ldr r0, _0800753C @ =gUnknown_03000000
	adds r2, r2, r0
	mov r0, sl
	ldrh r1, [r0, #2]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #1
	ldr r1, _0800753C @ =gUnknown_03000000
	adds r4, r4, r1
	ldrh r0, [r2]
	ldr r1, _08007544 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldr r2, [sp, #8]
	ldr r0, _08007540 @ =gUnknown_0201B130
	adds r3, r2, r0
	ldrh r2, [r3]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r5, r5, r1
	lsls r5, r5, #1
	ldr r2, _0800753C @ =gUnknown_03000000
	adds r5, r5, r2
	ldrh r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	adds r6, #4
	ldr r0, [sp, #8]
	adds r0, #4
	str r0, [sp, #8]
	movs r1, #4
	add sl, r1
	add r8, r1
	ldr r2, [sp, #0x10]
	adds r2, #4
	str r2, [sp, #0x10]
	adds r7, #1
	cmp r7, #7
	ble _08007476
	bl _080088C8
	.align 2, 0
_08007538: .4byte gUnknown_0202BE30
_0800753C: .4byte gUnknown_03000000
_08007540: .4byte gUnknown_0201B130
_08007544: .4byte 0x0000FFF0
_08007548:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _080075B4 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _080075B8 @ =gUnknown_0201B130
	ldr r5, _080075BC @ =gUnknown_0202BE30
_08007560:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r5, #2]
	movs r0, #0xff
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldrh r0, [r3]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r6, #2]
	movs r0, #0xff
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _08007560
	bl _080088C8
	.align 2, 0
_080075B4: .4byte gUnknown_03000000
_080075B8: .4byte gUnknown_0201B130
_080075BC: .4byte gUnknown_0202BE30
_080075C0:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	adds r2, #0x10
	mov sb, r2
	ldr r2, _0800765C @ =gUnknown_03000000
	mov sl, r2
	ldr r0, _08007660 @ =gUnknown_0201B130
	mov r8, r0
	ldr r6, _08007664 @ =gUnknown_0202BE30
_080075D4:
	lsls r5, r7, #1
	mov r1, ip
	adds r3, r5, r1
	lsls r2, r3, #1
	add r2, sl
	ldrh r1, [r6]
	ldr r0, _08007668 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r5, sb
	lsls r4, r5, #1
	add r4, sl
	ldrh r0, [r6]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r6, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sl
	mov r0, r8
	ldrh r1, [r0]
	ldr r0, _08007668 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, r5, r2
	lsls r5, r5, #1
	add r5, sl
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	mov r0, r8
	ldrh r2, [r0, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _080075D4
	bl _080088C8
	.align 2, 0
_0800765C: .4byte gUnknown_03000000
_08007660: .4byte gUnknown_0201B130
_08007664: .4byte gUnknown_0202BE30
_08007668: .4byte 0x00000FFF
_0800766C:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08007708 @ =gUnknown_03000000
	mov sl, r1
	ldr r2, _0800770C @ =gUnknown_0201B130
	mov r8, r2
	ldr r6, _08007710 @ =gUnknown_0202BE30
_08007680:
	lsls r5, r7, #1
	mov r0, ip
	adds r3, r5, r0
	lsls r2, r3, #1
	add r2, sl
	ldrh r1, [r6]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r5, sb
	lsls r4, r5, #1
	add r4, sl
	ldrh r0, [r6]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r6, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #1
	add r3, sl
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r5, r0
	lsls r5, r5, #1
	add r5, sl
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r2, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007680
	bl _080088C8
	.align 2, 0
_08007708: .4byte gUnknown_03000000
_0800770C: .4byte gUnknown_0201B130
_08007710: .4byte gUnknown_0202BE30
_08007714:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	movs r1, #0x10
	adds r1, r1, r2
	mov sb, r1
	adds r2, #0x11
	str r2, [sp]
	ldr r2, _080077FC @ =gUnknown_03000000
	mov sl, r2
	movs r0, #2
	str r0, [sp, #4]
	ldr r1, _08007800 @ =gUnknown_0202BE30
	mov r8, r1
	ldr r2, _08007804 @ =gUnknown_0201B130
	str r2, [sp, #0xc]
_08007734:
	lsls r6, r7, #1
	mov r0, ip
	adds r4, r6, r0
	lsls r2, r4, #1
	add r2, sl
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r1, sb
	adds r5, r6, r1
	lsls r3, r5, #1
	add r3, sl
	mov r2, r8
	ldrh r0, [r2]
	ldr r1, _08007808 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	ldr r0, [sp]
	adds r6, r6, r0
	lsls r2, r6, #1
	add r2, sl
	mov r0, r8
	ldrh r1, [r0, #2]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #1
	add r4, sl
	ldr r2, [sp, #0xc]
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r5, r0
	lsls r5, r5, #1
	add r5, sl
	ldrh r0, [r2]
	ldr r1, _08007808 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldr r2, [sp, #4]
	ldr r0, _08007804 @ =gUnknown_0201B130
	adds r3, r2, r0
	ldrh r2, [r3]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r6, r6, r1
	lsls r6, r6, #1
	add r6, sl
	ldrh r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	ldr r2, [sp, #4]
	adds r2, #4
	str r2, [sp, #4]
	movs r0, #4
	add r8, r0
	ldr r1, [sp, #0xc]
	adds r1, #4
	str r1, [sp, #0xc]
	adds r7, #1
	cmp r7, #7
	ble _08007734
	bl _080088C8
	.align 2, 0
_080077FC: .4byte gUnknown_03000000
_08007800: .4byte gUnknown_0202BE30
_08007804: .4byte gUnknown_0201B130
_08007808: .4byte 0x0000FFF0
_0800780C:
	adds r0, r3, #0
	cmp r3, #0
	bge _08007814
	adds r0, r3, #7
_08007814:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r3, r0
	cmp r0, #7
	bls _08007822
	bl _080088C8
_08007822:
	lsls r0, r0, #2
	ldr r1, _0800782C @ =_08007830
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800782C: .4byte _08007830
_08007830: @ jump table
	.4byte _08007850 @ case 0
	.4byte _080078D0 @ case 1
	.4byte _0800797C @ case 2
	.4byte _08007A28 @ case 3
	.4byte _08007ADC @ case 4
	.4byte _08007B54 @ case 5
	.4byte _08007C00 @ case 6
	.4byte _08007CA8 @ case 7
_08007850:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	ldr r1, _080078C4 @ =gUnknown_03000000
	mov sb, r1
	movs r0, #0xf
	mov sl, r0
	ldr r1, _080078C8 @ =gUnknown_0201B130
	mov r8, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r5, r0, r2
	ldr r6, _080078CC @ =gUnknown_0202BE30
	lsls r1, r1, #1
	adds r4, r1, r2
_08007874:
	lsls r3, r7, #1
	ldrh r0, [r5]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r5]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	ldrh r1, [r6, #2]
	mov r0, sl
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	mov r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r3, r0
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r2, #2]
	mov r0, sl
	ands r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #4
	add r8, r1
	adds r4, #4
	adds r5, #4
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007874
	bl _080088C8
	.align 2, 0
_080078C4: .4byte gUnknown_03000000
_080078C8: .4byte gUnknown_0201B130
_080078CC: .4byte gUnknown_0202BE30
_080078D0:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	ldr r1, _0800796C @ =gUnknown_03000000
	mov sl, r1
	ldr r0, _08007970 @ =gUnknown_0201B130
	mov sb, r0
	ldr r1, _08007974 @ =gUnknown_0202BE30
	mov r8, r1
	lsls r0, r2, #1
	mov r2, sl
	adds r6, r0, r2
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r5, r0, r2
_080078F0:
	lsls r4, r7, #1
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _08007978 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r4, ip
	lsls r3, r4, #1
	add r3, sl
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, _08007978 @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #1
	add r4, sl
	mov r2, sb
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r0, #4
	add sb, r0
	add r8, r0
	adds r6, #4
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _080078F0
	bl _080088C8
	.align 2, 0
_0800796C: .4byte gUnknown_03000000
_08007970: .4byte gUnknown_0201B130
_08007974: .4byte gUnknown_0202BE30
_08007978: .4byte 0x00000FFF
_0800797C:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _08007A1C @ =gUnknown_03000000
	mov sl, r0
	ldr r1, _08007A20 @ =gUnknown_0201B130
	mov sb, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08007A24 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r0, r2, #1
	mov r2, sl
	adds r6, r0, r2
	lsls r1, r1, #1
	adds r5, r1, r2
_0800799E:
	lsls r4, r7, #1
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r4, ip
	lsls r3, r4, #1
	add r3, sl
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	mov r0, r8
	ldrh r2, [r0, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	mov r2, sb
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #1
	add r4, sl
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #4
	add sb, r1
	adds r5, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _0800799E
	bl _080088C8
	.align 2, 0
_08007A1C: .4byte gUnknown_03000000
_08007A20: .4byte gUnknown_0201B130
_08007A24: .4byte gUnknown_0202BE30
_08007A28:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	movs r1, #0xf
	mov sl, r1
	ldr r0, _08007ACC @ =gUnknown_0201B130
	mov sb, r0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08007AD0 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r0, r2, #1
	ldr r2, _08007AD4 @ =gUnknown_03000000
	adds r6, r0, r2
	lsls r1, r1, #1
	adds r5, r1, r2
_08007A4A:
	lsls r4, r7, #1
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r4, ip
	lsls r3, r4, #1
	ldr r1, _08007AD4 @ =gUnknown_03000000
	adds r3, r3, r1
	mov r2, r8
	ldrh r0, [r2]
	ldr r1, _08007AD8 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldrh r2, [r2, #2]
	mov r0, sl
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r3]
	orrs r1, r0
	strh r1, [r3]
	mov r0, sb
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #1
	ldr r2, _08007AD4 @ =gUnknown_03000000
	adds r4, r4, r2
	mov r1, sb
	ldrh r0, [r1]
	ldr r1, _08007AD8 @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	mov r0, sb
	ldrh r2, [r0, #2]
	mov r0, sl
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #4
	add sb, r1
	adds r5, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007A4A
	bl _080088C8
	.align 2, 0
_08007ACC: .4byte gUnknown_0201B130
_08007AD0: .4byte gUnknown_0202BE30
_08007AD4: .4byte gUnknown_03000000
_08007AD8: .4byte 0x0000FFF0
_08007ADC:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08007B48 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _08007B4C @ =gUnknown_0201B130
	ldr r5, _08007B50 @ =gUnknown_0202BE30
_08007AF4:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r5, #2]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldrh r0, [r3]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r6, #2]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _08007AF4
	bl _080088C8
	.align 2, 0
_08007B48: .4byte gUnknown_03000000
_08007B4C: .4byte gUnknown_0201B130
_08007B50: .4byte gUnknown_0202BE30
_08007B54:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	adds r2, #0x10
	mov sb, r2
	ldr r2, _08007BF0 @ =gUnknown_03000000
	mov sl, r2
	ldr r0, _08007BF4 @ =gUnknown_0201B130
	mov r8, r0
	ldr r6, _08007BF8 @ =gUnknown_0202BE30
_08007B68:
	lsls r5, r7, #1
	mov r1, ip
	adds r3, r5, r1
	lsls r2, r3, #1
	add r2, sl
	ldrh r1, [r6]
	ldr r0, _08007BFC @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r5, sb
	lsls r4, r5, #1
	add r4, sl
	ldrh r0, [r6]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	ldrh r2, [r6, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sl
	mov r0, r8
	ldrh r1, [r0]
	ldr r0, _08007BFC @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, r5, r2
	lsls r5, r5, #1
	add r5, sl
	mov r1, r8
	ldrh r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #0xc
	mov r0, r8
	ldrh r2, [r0, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #4
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007B68
	bl _080088C8
	.align 2, 0
_08007BF0: .4byte gUnknown_03000000
_08007BF4: .4byte gUnknown_0201B130
_08007BF8: .4byte gUnknown_0202BE30
_08007BFC: .4byte 0x00000FFF
_08007C00:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08007C9C @ =gUnknown_03000000
	mov sl, r1
	ldr r2, _08007CA0 @ =gUnknown_0201B130
	mov r8, r2
	ldr r6, _08007CA4 @ =gUnknown_0202BE30
_08007C14:
	lsls r5, r7, #1
	mov r0, ip
	adds r3, r5, r0
	lsls r2, r3, #1
	add r2, sl
	ldrh r1, [r6]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r5, sb
	lsls r4, r5, #1
	add r4, sl
	ldrh r0, [r6]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r6, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #1
	add r3, sl
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r5, r0
	lsls r5, r5, #1
	add r5, sl
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r1, r1, #8
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007C14
	bl _080088C8
	.align 2, 0
_08007C9C: .4byte gUnknown_03000000
_08007CA0: .4byte gUnknown_0201B130
_08007CA4: .4byte gUnknown_0202BE30
_08007CA8:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08007D40 @ =gUnknown_03000000
	mov sl, r1
	ldr r2, _08007D44 @ =gUnknown_0201B130
	mov r8, r2
	ldr r6, _08007D48 @ =gUnknown_0202BE30
_08007CBC:
	lsls r5, r7, #1
	mov r0, ip
	adds r3, r5, r0
	lsls r2, r3, #1
	add r2, sl
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r5, sb
	lsls r4, r5, #1
	add r4, sl
	ldrh r0, [r6]
	ldr r1, _08007D4C @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldrh r2, [r6, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r4]
	orrs r1, r0
	strh r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #1
	add r3, sl
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r5, r0
	lsls r5, r5, #1
	add r5, sl
	ldrh r0, [r2]
	ldr r1, _08007D4C @ =0x0000FFF0
	ands r1, r0
	lsrs r1, r1, #4
	ldrh r2, [r2, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #0xc
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r5]
	movs r1, #4
	add r8, r1
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08007CBC
	bl _080088C8
	.align 2, 0
_08007D40: .4byte gUnknown_03000000
_08007D44: .4byte gUnknown_0201B130
_08007D48: .4byte gUnknown_0202BE30
_08007D4C: .4byte 0x0000FFF0
_08007D50:
	adds r0, r3, #0
	cmp r3, #0
	bge _08007D58
	adds r0, r3, #7
_08007D58:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r3, r0
	cmp r0, #7
	bls _08007D66
	bl _080088C8
_08007D66:
	lsls r0, r0, #2
	ldr r1, _08007D70 @ =_08007D74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08007D70: .4byte _08007D74
_08007D74: @ jump table
	.4byte _08007D94 @ case 0
	.4byte _08007DD8 @ case 1
	.4byte _08007E74 @ case 2
	.4byte _08007F0C @ case 3
	.4byte _08007FA4 @ case 4
	.4byte _08007FF4 @ case 5
	.4byte _08008084 @ case 6
	.4byte _08008110 @ case 7
_08007D94:
	movs r7, #0
	ldr r1, _08007DCC @ =gUnknown_03000000
	lsls r0, r2, #1
	adds r3, r0, r1
	ldr r5, _08007DD0 @ =gUnknown_0202BE30
	ldr r4, _08007DD4 @ =gUnknown_0201B130
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r2, r0, r1
_08007DA8:
	ldrh r0, [r3]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r2]
	adds r3, #4
	adds r5, #4
	adds r2, #4
	adds r4, #4
	adds r7, #1
	cmp r7, #7
	ble _08007DA8
	bl _080088C8
	.align 2, 0
_08007DCC: .4byte gUnknown_03000000
_08007DD0: .4byte gUnknown_0202BE30
_08007DD4: .4byte gUnknown_0201B130
_08007DD8:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	ldr r1, _08007E64 @ =gUnknown_03000000
	mov sb, r1
	movs r0, #0xf0
	lsls r0, r0, #8
	mov sl, r0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _08007E68 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_08007DFC:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _08007E6C @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007E70 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	ldr r0, _08007E6C @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xc
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _08007DFC
	bl _080088C8
	.align 2, 0
_08007E64: .4byte gUnknown_03000000
_08007E68: .4byte gUnknown_0202BE30
_08007E6C: .4byte 0x00000FFF
_08007E70: .4byte gUnknown_0201B130
_08007E74:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _08007F00 @ =gUnknown_03000000
	mov sb, r0
	movs r1, #0xff
	lsls r1, r1, #8
	mov sl, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _08007F04 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_08007E98:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007F08 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _08007E98
	bl _080088C8
	.align 2, 0
_08007F00: .4byte gUnknown_03000000
_08007F04: .4byte gUnknown_0202BE30
_08007F08: .4byte gUnknown_0201B130
_08007F0C:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _08007F94 @ =gUnknown_03000000
	mov sb, r0
	ldr r1, _08007F98 @ =0x0000FFF0
	mov sl, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _08007F9C @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_08007F2E:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007FA0 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _08007F2E
	bl _080088C8
	.align 2, 0
_08007F94: .4byte gUnknown_03000000
_08007F98: .4byte 0x0000FFF0
_08007F9C: .4byte gUnknown_0202BE30
_08007FA0: .4byte gUnknown_0201B130
_08007FA4:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r1, _08007FE8 @ =gUnknown_03000000
	mov r8, r1
	ldr r6, _08007FEC @ =gUnknown_0202BE30
	lsls r0, r2, #1
	adds r4, r0, r1
	mov r5, ip
_08007FB6:
	lsls r3, r7, #2
	ldrh r0, [r4]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	lsls r2, r2, #1
	add r2, r8
	ldr r1, _08007FF0 @ =gUnknown_0201B130
	adds r3, r3, r1
	ldrh r0, [r2]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r2]
	adds r6, #4
	adds r4, #4
	adds r5, #2
	adds r7, #1
	cmp r7, #7
	ble _08007FB6
	bl _080088C8
	.align 2, 0
_08007FE8: .4byte gUnknown_03000000
_08007FEC: .4byte gUnknown_0202BE30
_08007FF0: .4byte gUnknown_0201B130
_08007FF4:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08008074 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _08008078 @ =gUnknown_0202BE30
_0800800A:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	ldr r0, _0800807C @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _08008080 @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	ldr r0, _0800807C @ =0x00000FFF
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #0xc
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _0800800A
	bl _080088C8
	.align 2, 0
_08008074: .4byte gUnknown_03000000
_08008078: .4byte gUnknown_0202BE30
_0800807C: .4byte 0x00000FFF
_08008080: .4byte gUnknown_0201B130
_08008084:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08008104 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _08008108 @ =gUnknown_0202BE30
_0800809A:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _0800810C @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _0800809A
	bl _080088C8
	.align 2, 0
_08008104: .4byte gUnknown_03000000
_08008108: .4byte gUnknown_0202BE30
_0800810C: .4byte gUnknown_0201B130
_08008110:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _0800818C @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _08008190 @ =gUnknown_0202BE30
_08008126:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	ldr r0, _08008194 @ =0x0000FFF0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _08008198 @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	ldr r0, _08008194 @ =0x0000FFF0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08008126
	b _080088C8
	.align 2, 0
_0800818C: .4byte gUnknown_03000000
_08008190: .4byte gUnknown_0202BE30
_08008194: .4byte 0x0000FFF0
_08008198: .4byte gUnknown_0201B130
_0800819C:
	adds r0, r3, #0
	cmp r3, #0
	bge _080081A4
	adds r0, r3, #7
_080081A4:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r3, r0
	cmp r0, #7
	bls _080081B0
	b _080088C8
_080081B0:
	lsls r0, r0, #2
	ldr r1, _080081BC @ =_080081C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080081BC: .4byte _080081C0
_080081C0: @ jump table
	.4byte _080081E0 @ case 0
	.4byte _08008230 @ case 1
	.4byte _08008284 @ case 2
	.4byte _08008318 @ case 3
	.4byte _080083AC @ case 4
	.4byte _0800840C @ case 5
	.4byte _08008468 @ case 6
	.4byte _080084F4 @ case 7
_080081E0:
	movs r7, #0
	ldr r1, _08008220 @ =gUnknown_03000000
	ldr r6, _08008224 @ =0x00000FFF
	lsls r0, r2, #1
	adds r4, r0, r1
	ldr r5, _08008228 @ =gUnknown_0202BE30
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r3, r0, r1
_080081F4:
	lsls r2, r7, #2
	ldrh r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _0800822C @ =gUnknown_0201B130
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r4, #4
	adds r5, #4
	adds r3, #4
	adds r7, #1
	cmp r7, #7
	ble _080081F4
	b _080088C8
	.align 2, 0
_08008220: .4byte gUnknown_03000000
_08008224: .4byte 0x00000FFF
_08008228: .4byte gUnknown_0202BE30
_0800822C: .4byte gUnknown_0201B130
_08008230:
	movs r7, #0
	ldr r1, _08008274 @ =gUnknown_03000000
	ldr r6, _08008278 @ =0x00000FFF
	lsls r0, r2, #1
	adds r4, r0, r1
	ldr r5, _0800827C @ =gUnknown_0202BE30
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r3, r0, r1
_08008244:
	lsls r2, r7, #2
	ldrh r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08008280 @ =gUnknown_0201B130
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r4, #4
	adds r5, #4
	adds r3, #4
	adds r7, #1
	cmp r7, #7
	ble _08008244
	b _080088C8
	.align 2, 0
_08008274: .4byte gUnknown_03000000
_08008278: .4byte 0x00000FFF
_0800827C: .4byte gUnknown_0202BE30
_08008280: .4byte gUnknown_0201B130
_08008284:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _0800830C @ =gUnknown_03000000
	mov sb, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	mov sl, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _08008310 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_080082A8:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08008314 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _080082A8
	b _080088C8
	.align 2, 0
_0800830C: .4byte gUnknown_03000000
_08008310: .4byte gUnknown_0202BE30
_08008314: .4byte gUnknown_0201B130
_08008318:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _080083A0 @ =gUnknown_03000000
	mov sb, r0
	movs r1, #0xff
	lsls r1, r1, #4
	mov sl, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _080083A4 @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_0800833C:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080083A8 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _0800833C
	b _080088C8
	.align 2, 0
_080083A0: .4byte gUnknown_03000000
_080083A4: .4byte gUnknown_0202BE30
_080083A8: .4byte gUnknown_0201B130
_080083AC:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r1, _080083FC @ =gUnknown_03000000
	mov sb, r1
	ldr r2, _08008400 @ =0x00000FFF
	mov r8, r2
	ldr r6, _08008404 @ =gUnknown_0202BE30
	mov r1, ip
	lsls r0, r1, #1
	mov r2, sb
	adds r4, r0, r2
	mov r5, ip
_080083C6:
	lsls r3, r7, #2
	ldrh r1, [r6]
	mov r0, r8
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	lsls r2, r2, #1
	add r2, sb
	ldr r1, _08008408 @ =gUnknown_0201B130
	adds r3, r3, r1
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r6, #4
	adds r4, #4
	adds r5, #2
	adds r7, #1
	cmp r7, #7
	ble _080083C6
	b _080088C8
	.align 2, 0
_080083FC: .4byte gUnknown_03000000
_08008400: .4byte 0x00000FFF
_08008404: .4byte gUnknown_0202BE30
_08008408: .4byte gUnknown_0201B130
_0800840C:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r6, _08008458 @ =gUnknown_03000000
	ldr r2, _0800845C @ =0x00000FFF
	mov r8, r2
	ldr r5, _08008460 @ =gUnknown_0202BE30
_0800841A:
	lsls r2, r7, #1
	add r2, ip
	lsls r3, r2, #1
	adds r3, r3, r6
	lsls r4, r7, #2
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #1
	adds r2, r2, r6
	ldr r1, _08008464 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _0800841A
	b _080088C8
	.align 2, 0
_08008458: .4byte gUnknown_03000000
_0800845C: .4byte 0x00000FFF
_08008460: .4byte gUnknown_0202BE30
_08008464: .4byte gUnknown_0201B130
_08008468:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _080084E8 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _080084EC @ =gUnknown_0202BE30
_0800847E:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _080084F0 @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	lsrs r0, r0, #8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _0800847E
	b _080088C8
	.align 2, 0
_080084E8: .4byte gUnknown_03000000
_080084EC: .4byte gUnknown_0202BE30
_080084F0: .4byte gUnknown_0201B130
_080084F4:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _08008574 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _08008578 @ =gUnknown_0202BE30
_0800850A:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _0800857C @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	movs r0, #0xff
	lsls r0, r0, #4
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _0800850A
	b _080088C8
	.align 2, 0
_08008574: .4byte gUnknown_03000000
_08008578: .4byte gUnknown_0202BE30
_0800857C: .4byte gUnknown_0201B130
_08008580:
	adds r0, r3, #0
	cmp r3, #0
	bge _08008588
	adds r0, r3, #7
_08008588:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r3, r0
	cmp r0, #7
	bls _08008594
	b _080088C8
_08008594:
	lsls r0, r0, #2
	ldr r1, _080085A0 @ =_080085A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080085A0: .4byte _080085A4
_080085A4: @ jump table
	.4byte _080085C4 @ case 0
	.4byte _08008610 @ case 1
	.4byte _08008660 @ case 2
	.4byte _080086B0 @ case 3
	.4byte _08008744 @ case 4
	.4byte _080087A0 @ case 5
	.4byte _080087F8 @ case 6
	.4byte _08008850 @ case 7
_080085C4:
	movs r7, #0
	ldr r1, _08008604 @ =gUnknown_03000000
	movs r6, #0xff
	lsls r0, r2, #1
	adds r4, r0, r1
	ldr r5, _08008608 @ =gUnknown_0202BE30
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r3, r0, r1
_080085D8:
	lsls r2, r7, #2
	ldrh r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _0800860C @ =gUnknown_0201B130
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r4, #4
	adds r5, #4
	adds r3, #4
	adds r7, #1
	cmp r7, #7
	ble _080085D8
	b _080088C8
	.align 2, 0
_08008604: .4byte gUnknown_03000000
_08008608: .4byte gUnknown_0202BE30
_0800860C: .4byte gUnknown_0201B130
_08008610:
	movs r7, #0
	ldr r1, _08008654 @ =gUnknown_03000000
	movs r6, #0xff
	lsls r0, r2, #1
	adds r4, r0, r1
	ldr r5, _08008658 @ =gUnknown_0202BE30
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r3, r0, r1
_08008624:
	lsls r2, r7, #2
	ldrh r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _0800865C @ =gUnknown_0201B130
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r4, #4
	adds r5, #4
	adds r3, #4
	adds r7, #1
	cmp r7, #7
	ble _08008624
	b _080088C8
	.align 2, 0
_08008654: .4byte gUnknown_03000000
_08008658: .4byte gUnknown_0202BE30
_0800865C: .4byte gUnknown_0201B130
_08008660:
	movs r7, #0
	ldr r1, _080086A4 @ =gUnknown_03000000
	movs r6, #0xff
	lsls r0, r2, #1
	adds r4, r0, r1
	ldr r5, _080086A8 @ =gUnknown_0202BE30
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r3, r0, r1
_08008674:
	lsls r2, r7, #2
	ldrh r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _080086AC @ =gUnknown_0201B130
	adds r2, r2, r0
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r4, #4
	adds r5, #4
	adds r3, #4
	adds r7, #1
	cmp r7, #7
	ble _08008674
	b _080088C8
	.align 2, 0
_080086A4: .4byte gUnknown_03000000
_080086A8: .4byte gUnknown_0202BE30
_080086AC: .4byte gUnknown_0201B130
_080086B0:
	movs r7, #0
	adds r1, r2, #1
	mov ip, r1
	ldr r0, _08008738 @ =gUnknown_03000000
	mov sb, r0
	movs r1, #0xf0
	mov sl, r1
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	lsls r0, r2, #1
	mov r2, sb
	adds r6, r0, r2
	ldr r0, _0800873C @ =gUnknown_0202BE30
	mov r8, r0
	lsls r1, r1, #1
	adds r5, r1, r2
_080086D2:
	lsls r3, r7, #1
	lsls r4, r7, #2
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	add r3, ip
	lsls r2, r3, #1
	add r2, sb
	mov r0, r8
	ldrh r1, [r0]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08008740 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #1
	add r3, sb
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	adds r5, #4
	adds r6, #4
	movs r0, #4
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _080086D2
	b _080088C8
	.align 2, 0
_08008738: .4byte gUnknown_03000000
_0800873C: .4byte gUnknown_0202BE30
_08008740: .4byte gUnknown_0201B130
_08008744:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r1, _08008794 @ =gUnknown_03000000
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
	ldr r6, _08008798 @ =gUnknown_0202BE30
	mov r1, ip
	lsls r0, r1, #1
	mov r2, sb
	adds r4, r0, r2
	mov r5, ip
_0800875E:
	lsls r3, r7, #2
	ldrh r1, [r6]
	mov r0, r8
	ands r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r5, r0
	lsls r2, r2, #1
	add r2, sb
	ldr r1, _0800879C @ =gUnknown_0201B130
	adds r3, r3, r1
	ldrh r1, [r3]
	mov r0, r8
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r6, #4
	adds r4, #4
	adds r5, #2
	adds r7, #1
	cmp r7, #7
	ble _0800875E
	b _080088C8
	.align 2, 0
_08008794: .4byte gUnknown_03000000
_08008798: .4byte gUnknown_0202BE30
_0800879C: .4byte gUnknown_0201B130
_080087A0:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r6, _080087EC @ =gUnknown_03000000
	movs r2, #0xff
	mov r8, r2
	ldr r5, _080087F0 @ =gUnknown_0202BE30
_080087AE:
	lsls r2, r7, #1
	add r2, ip
	lsls r3, r2, #1
	adds r3, r3, r6
	lsls r4, r7, #2
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #1
	adds r2, r2, r6
	ldr r1, _080087F4 @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _080087AE
	b _080088C8
	.align 2, 0
_080087EC: .4byte gUnknown_03000000
_080087F0: .4byte gUnknown_0202BE30
_080087F4: .4byte gUnknown_0201B130
_080087F8:
	movs r7, #0
	adds r2, #1
	mov ip, r2
	ldr r6, _08008844 @ =gUnknown_03000000
	movs r2, #0xff
	mov r8, r2
	ldr r5, _08008848 @ =gUnknown_0202BE30
_08008806:
	lsls r2, r7, #1
	add r2, ip
	lsls r3, r2, #1
	adds r3, r3, r6
	lsls r4, r7, #2
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #1
	adds r2, r2, r6
	ldr r1, _0800884C @ =gUnknown_0201B130
	adds r4, r4, r1
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	lsls r0, r0, #8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r5, #4
	adds r7, #1
	cmp r7, #7
	ble _08008806
	b _080088C8
	.align 2, 0
_08008844: .4byte gUnknown_03000000
_08008848: .4byte gUnknown_0202BE30
_0800884C: .4byte gUnknown_0201B130
_08008850:
	movs r7, #0
	adds r0, r2, #1
	mov ip, r0
	adds r2, #0x10
	mov sb, r2
	ldr r1, _080088D8 @ =gUnknown_03000000
	mov r8, r1
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	ldr r6, _080088DC @ =gUnknown_0202BE30
_08008866:
	lsls r4, r7, #1
	mov r0, ip
	adds r3, r4, r0
	lsls r2, r3, #1
	add r2, r8
	lsls r5, r7, #2
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r4, sb
	lsls r2, r4, #1
	add r2, r8
	ldrh r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	add r3, sl
	lsls r3, r3, #1
	add r3, r8
	ldr r1, _080088E0 @ =gUnknown_0201B130
	adds r5, r5, r1
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	add r4, sl
	lsls r4, r4, #1
	add r4, r8
	ldrh r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #4
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r6, #4
	adds r7, #1
	cmp r7, #7
	ble _08008866
_080088C8:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080088D8: .4byte gUnknown_03000000
_080088DC: .4byte gUnknown_0202BE30
_080088E0: .4byte gUnknown_0201B130

	thumb_func_start sub_88E4
sub_88E4: @ 0x080088E4
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r6, _08008934 @ =gUnknown_0202A1C0
	ldr r5, _08008938 @ =gUnknown_0201A514
	ldr r4, _0800893C @ =gUnknown_0202BEB8
	ldr r3, _08008940 @ =gMain+0x74
	adds r1, r6, #0
_080088F2:
	adds r0, r2, r3
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0xcc
	ble _080088F2
	ldr r0, _08008934 @ =gUnknown_0202A1C0
	movs r1, #0
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0x13
_0800890C:
	strh r1, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0800890C
	movs r0, #0
	strh r0, [r5]
	strh r0, [r4]
	movs r2, #0
_0800891E:
	lsls r0, r2, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi _08008968
	lsls r0, r0, #2
	ldr r1, _08008944 @ =_08008948
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08008934: .4byte gUnknown_0202A1C0
_08008938: .4byte gUnknown_0201A514
_0800893C: .4byte gUnknown_0202BEB8
_08008940: .4byte gMain+0x74
_08008944: .4byte _08008948
_08008948: @ jump table
	.4byte _08008968 @ case 0
	.4byte _08008962 @ case 1
	.4byte _08008968 @ case 2
	.4byte _08008962 @ case 3
	.4byte _0800895C @ case 4
_0800895C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08008962:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08008968:
	adds r2, #1
	cmp r2, #0xcc
	ble _0800891E
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8974
sub_8974: @ 0x08008974
	push {r4, r5, lr}
	ldr r1, _080089E0 @ =gUnknown_086A61BC
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq _08008A56
	cmp r4, #0x63
	bgt _080089FC
	ldr r1, _080089E4 @ =gUnknown_0202BF14
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #5
	bl __modsi3
	adds r4, r0, #0
	ldr r0, _080089E8 @ =gUnknown_086BB6F4
	lsls r5, r5, #0x10
	asrs r5, r5, #0xe
	adds r0, r5, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	subs r1, r1, r4
	lsls r1, r1, #7
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _080089EC @ =0x06013800
	movs r2, #0x6c
	movs r3, #1
	bl sub_10708
	ldr r1, _080089F0 @ =0x040000D4
	ldr r0, _080089F4 @ =gUnknown_086B15B4
	adds r5, r5, r0
	lsls r4, r4, #5
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _080089F8 @ =0x05000240
	b _08008A4E
	.align 2, 0
_080089E0: .4byte gUnknown_086A61BC
_080089E4: .4byte gUnknown_0202BF14
_080089E8: .4byte gUnknown_086BB6F4
_080089EC: .4byte 0x06013800
_080089F0: .4byte 0x040000D4
_080089F4: .4byte gUnknown_086B15B4
_080089F8: .4byte 0x05000240
_080089FC:
	ldr r1, _08008A5C @ =gUnknown_0202BF14
	movs r0, #1
	strh r0, [r1]
	subs r4, #0x64
	adds r0, r4, #0
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	adds r4, r0, #0
	ldr r0, _08008A60 @ =gMonHatchSpriteGroupGfx
	lsls r5, r5, #0x10
	asrs r5, r5, #0xe
	adds r0, r5, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #4
	adds r1, r1, r4
	lsls r1, r1, #3
	subs r1, r1, r4
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _08008A64 @ =0x06014800
	movs r2, #0x87
	movs r3, #1
	bl sub_10708
	ldr r1, _08008A68 @ =0x040000D4
	ldr r0, _08008A6C @ =gMonHatchSpriteGroupPals
	adds r5, r5, r0
	lsls r4, r4, #5
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _08008A70 @ =0x05000260
_08008A4E:
	str r0, [r1, #4]
	ldr r0, _08008A74 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08008A56:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008A5C: .4byte gUnknown_0202BF14
_08008A60: .4byte gMonHatchSpriteGroupGfx
_08008A64: .4byte 0x06014800
_08008A68: .4byte 0x040000D4
_08008A6C: .4byte gMonHatchSpriteGroupPals
_08008A70: .4byte 0x05000260
_08008A74: .4byte 0x80000010
