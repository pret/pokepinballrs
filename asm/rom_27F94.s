#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
	ldr r3, _08028D34 @ =gCurrentPinballGame
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
	ldr r0, _08028D40 @ =gUnknown_02031060
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
	ldr r0, _08028D4C @ =gUnknown_02030760
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
_08028D34: .4byte gCurrentPinballGame
_08028D38: .4byte 0x000005A9
_08028D3C: .4byte 0x040000D4
_08028D40: .4byte gUnknown_02031060
_08028D44: .4byte 0x06010CA0
_08028D48: .4byte 0x80000240
_08028D4C: .4byte gUnknown_02030760
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
	ldr r1, _08028E14 @ =gUnknown_02030760
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
_08028E14: .4byte gUnknown_02030760
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
	ldr r1, _08028F68 @ =gCurrentPinballGame
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
	ldr r1, _08028F70 @ =gUnknown_0844AA0C
	b _08028FFC
	.align 2, 0
_08028F64: .4byte gMain
_08028F68: .4byte gCurrentPinballGame
_08028F6C: .4byte 0x040000D4
_08028F70: .4byte gUnknown_0844AA0C
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
	ldr r0, _08028FD0 @ =gUnknown_02031060
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
	ldr r0, _08028FDC @ =gUnknown_02030760
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
_08028FD0: .4byte gUnknown_02031060
_08028FD4: .4byte 0x06010CA0
_08028FD8: .4byte 0x80000240
_08028FDC: .4byte gUnknown_02030760
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
	ldr r1, _08029020 @ =gUnknown_02030760
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
_08029020: .4byte gUnknown_02030760
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
	ldr r0, _0802913C @ =gCurrentPinballGame
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
	ldr r2, _08029140 @ =gUnknown_086AE154
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
_0802913C: .4byte gCurrentPinballGame
_08029140: .4byte gUnknown_086AE154
_08029144:
	movs r2, #0x3c
	rsbs r2, r2, #0
	cmp r0, r2
	bge _0802914E
	strh r2, [r7, #4]
_0802914E:
	movs r2, #0
	lsls r1, r1, #0x10
	ldr r6, _08029284 @ =gUnknown_086B263C
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
	ldr r6, _08029294 @ =gCurrentPinballGame
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
	ldr r1, _08029294 @ =gCurrentPinballGame
	ldr r0, [r1]
	mov r2, r8
	asrs r1, r2, #0xf
	adds r0, #0x74
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08029264
_0802923A:
	ldr r6, _08029294 @ =gCurrentPinballGame
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
_08029284: .4byte gUnknown_086B263C
_08029288: .4byte 0xFFFFFE00
_0802928C: .4byte gOamBuffer
_08029290: .4byte 0x000001FF
_08029294: .4byte gCurrentPinballGame
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
	ldr r0, _08029384 @ =gCurrentPinballGame
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
_08029384: .4byte gCurrentPinballGame
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
	ldr r1, _0802940C @ =gUnknown_086AD436
	ldr r3, _08029410 @ =gCurrentPinballGame
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
_0802940C: .4byte gUnknown_086AD436
_08029410: .4byte gCurrentPinballGame
_08029414: .4byte 0x000006CC
_08029418: .4byte 0x000006CA
_0802941C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08029426:
	ldr r2, _080295E4 @ =gCurrentPinballGame
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
	ldr r4, _080295E4 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _080295E8 @ =0x000006CC
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0802948A
	ldr r1, _080295F4 @ =0x040000D4
	ldr r0, _080295F8 @ =gUnknown_020306D0
	str r0, [r1]
	ldr r0, _080295FC @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _08029600 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08029604 @ =gUnknown_02030760
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
	ldr r0, _080295E4 @ =gCurrentPinballGame
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
	ldr r4, _08029610 @ =gUnknown_086B55DC
	mov sl, r4
	ldr r1, _08029614 @ =gUnknown_086AD436
	mov sb, r1
	ldr r2, _080295E4 @ =gCurrentPinballGame
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
	ldr r0, _080295E4 @ =gCurrentPinballGame
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
	ldr r4, _080295E4 @ =gCurrentPinballGame
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
_080295E4: .4byte gCurrentPinballGame
_080295E8: .4byte 0x000006CC
_080295EC: .4byte 0x000006CA
_080295F0: .4byte gMain
_080295F4: .4byte 0x040000D4
_080295F8: .4byte gUnknown_020306D0
_080295FC: .4byte 0x050003A0
_08029600: .4byte 0x80000010
_08029604: .4byte gUnknown_02030760
_08029608: .4byte 0x06010CA0
_0802960C: .4byte 0x80000240
_08029610: .4byte gUnknown_086B55DC
_08029614: .4byte gUnknown_086AD436
_08029618: .4byte gOamBuffer
_0802961C: .4byte 0x000001FF
_08029620: .4byte 0xFFFFFE00

	thumb_func_start sub_29624
sub_29624: @ 0x08029624
	push {r4, r5, lr}
	ldr r0, _08029658 @ =gCurrentPinballGame
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
_08029658: .4byte gCurrentPinballGame
_0802965C: .4byte 0x000006CC
_08029660: .4byte 0x000006D3

	thumb_func_start sub_29664
sub_29664: @ 0x08029664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	ldr r7, _08029700 @ =gCurrentPinballGame
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
	bl Random
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
	bl Random
	ldr r4, [r7]
	adds r4, r4, r6
	ldr r1, _08029708 @ =0x00000226
	bl __umodsi3
	movs r1, #0x50
	subs r1, r1, r0
	ldr r0, _0802970C @ =0x000005DA
	adds r4, r4, r0
	strh r1, [r4]
	bl Random
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
	ldr r0, _08029700 @ =gCurrentPinballGame
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
_08029700: .4byte gCurrentPinballGame
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
	ldr r0, _080298BC @ =gCurrentPinballGame
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
	ldr r3, _080298C4 @ =gUnknown_086AE1A4
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
	ldr r0, _080298BC @ =gCurrentPinballGame
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
	ldr r3, _080298E8 @ =gUnknown_086B53B4
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r3, #0
	adds r0, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r5, _080298EC @ =gUnknown_086B53B8
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
	ldr r3, _080298BC @ =gCurrentPinballGame
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
_080298BC: .4byte gCurrentPinballGame
_080298C0: .4byte 0x00000606
_080298C4: .4byte gUnknown_086AE1A4
_080298C8: .4byte 0x000005DA
_080298CC: .4byte 0x000005B9
_080298D0: .4byte 0x000005C2
_080298D4: .4byte 0x000036AF
_080298D8: .4byte 0xFFFF0000
_080298DC: .4byte 0xFFFFFED4
_080298E0: .4byte 0x0000FFFF
_080298E4: .4byte gOamBuffer
_080298E8: .4byte gUnknown_086B53B4
_080298EC: .4byte gUnknown_086B53B8
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
	ldr r7, _08029A34 @ =gCurrentPinballGame
	movs r1, #0x64
	mov sb, r1
	ldr r2, _08029A38 @ =gUnknown_086AE2F4
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
	bl Random
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
	bl Random
	ldr r4, [r7]
	adds r4, r4, r6
	ldr r1, _08029A40 @ =gUnknown_086AE2F6
	adds r6, r6, r1
	movs r1, #0xc8
	bl __umodsi3
	subs r0, #0x3c
	ldrh r1, [r6]
	subs r1, r1, r0
	ldr r2, _08029A44 @ =0x000005DA
	adds r4, r4, r2
	strh r1, [r4]
	bl Random
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
	ldr r3, _08029A34 @ =gCurrentPinballGame
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
_08029A34: .4byte gCurrentPinballGame
_08029A38: .4byte gUnknown_086AE2F4
_08029A3C: .4byte 0x000005C2
_08029A40: .4byte gUnknown_086AE2F6
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
	ldr r1, _08029D34 @ =gUnknown_086B4E3E
	mov sl, r1
_08029A92:
	ldr r2, _08029D38 @ =gCurrentPinballGame
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
	ldr r1, _08029D40 @ =gUnknown_086AE234
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
	ldr r0, _08029D38 @ =gCurrentPinballGame
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
	ldr r2, _08029D38 @ =gCurrentPinballGame
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
	ldr r1, _08029D5C @ =gUnknown_086B4E42
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
	ldr r1, _08029D68 @ =gUnknown_086AE30C
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
	ldr r2, _08029D6C @ =gUnknown_086AE318
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
	ldr r4, _08029D38 @ =gCurrentPinballGame
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
	bl SetMatrixScale
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
	bl SetMatrixScale
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
	bl SetMatrixScale
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
	bl SetMatrixScale
	ldr r0, _08029D38 @ =gCurrentPinballGame
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
_08029D34: .4byte gUnknown_086B4E3E
_08029D38: .4byte gCurrentPinballGame
_08029D3C: .4byte 0x00000606
_08029D40: .4byte gUnknown_086AE234
_08029D44: .4byte 0x000005DA
_08029D48: .4byte 0x000005B9
_08029D4C: .4byte 0x000005BD
_08029D50: .4byte 0x000005C2
_08029D54: .4byte 0xFFFF0000
_08029D58: .4byte 0x0000FFFF
_08029D5C: .4byte gUnknown_086B4E42
_08029D60: .4byte 0x000001FF
_08029D64: .4byte 0xFFFFFE00
_08029D68: .4byte gUnknown_086AE30C
_08029D6C: .4byte gUnknown_086AE318
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
	ldr r4, _08029E68 @ =gCurrentPinballGame
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
	ldr r1, _08029E78 @ =gUnknown_086AD180
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
_08029E68: .4byte gCurrentPinballGame
_08029E6C: .4byte 0x000006F2
_08029E70: .4byte 0x000006F4
_08029E74: .4byte 0x000006E9
_08029E78: .4byte gUnknown_086AD180
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
	ldr r0, _0802A12C @ =gCurrentPinballGame
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
_0802A12C: .4byte gCurrentPinballGame
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
	bl Random
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
	ldr r0, _0802A1FC @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0802A200 @ =0x000006F4
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, _0802A204 @ =0x000006F6
	adds r0, r0, r3
	strh r1, [r0]
_0802A1CA:
	ldr r0, _0802A1FC @ =gCurrentPinballGame
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
_0802A1FC: .4byte gCurrentPinballGame
_0802A200: .4byte 0x000006F4
_0802A204: .4byte 0x000006F6
_0802A208: .4byte 0x000006F2
_0802A20C:
	ldr r7, _0802A2DC @ =gCurrentPinballGame
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
	ldr r0, _0802A2E8 @ =gMPlayInfo_BGM
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
	ldr r5, _0802A2DC @ =gCurrentPinballGame
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
	ldr r0, _0802A2DC @ =gCurrentPinballGame
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
_0802A2DC: .4byte gCurrentPinballGame
_0802A2E0: .4byte 0x000006F2
_0802A2E4: .4byte 0x000006C4
_0802A2E8: .4byte gMPlayInfo_BGM
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
	ldr r0, _0802A34C @ =gMPlayInfo_SE1
	ldr r1, _0802A350 @ =gUnknown_0869F45C
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
_0802A34C: .4byte gMPlayInfo_SE1
_0802A350: .4byte gUnknown_0869F45C

	thumb_func_start sub_2A354
sub_2A354: @ 0x0802A354
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802A3C4 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _0802A3C8 @ =0x000006DE
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0xb3
	bhi _0802A3A6
	cmp r0, #4
	bne _0802A36E
	movs r0, 0x14 @ =MUS_UNKNOWN_0x14
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
	movs r0, 0xB2 @=SE_UNKNOWN_0xB2
	bl m4aSongNumStart
_0802A388:
	ldr r0, _0802A3C4 @ =gCurrentPinballGame
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
	ldr r1, _0802A3C4 @ =gCurrentPinballGame
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
_0802A3C4: .4byte gCurrentPinballGame
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
	ldr r0, _0802A568 @ =gUnknown_084C156C
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
_0802A568: .4byte gUnknown_084C156C
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
	ldr r0, _0802A8B4 @ =gMPlayInfo_SE1
	ldr r1, _0802A8B8 @ =gUnknown_0869F664
	bl MPlayStart
	ldr r2, _0802A8BC @ =0x040000D4
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802A8C0 @ =gUnknown_08137E14
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
_0802A8B4: .4byte gMPlayInfo_SE1
_0802A8B8: .4byte gUnknown_0869F664
_0802A8BC: .4byte 0x040000D4
_0802A8C0: .4byte gUnknown_08137E14
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
	movs r0, 0x91 @=SE_UNKNOWN_0x91
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
	movs r0, 0x91 @=SE_UNKNOWN_0x91
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
	movs r0, 0x91 @=SE_UNKNOWN_0x91
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

	