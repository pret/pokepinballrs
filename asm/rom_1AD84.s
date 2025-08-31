#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
	ldr r2, _0801C824 @ =gCurrentPinballGame
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
_0801C824: .4byte gCurrentPinballGame
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
	ldr r6, _0801C8D0 @ =gCurrentPinballGame
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
	ldr r1, _0801C8E4 @ =gUnknown_0848D68C
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
	ldr r1, _0801C8F0 @ =gUnknown_081C00E4
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0801C8F4 @ =gUnknown_086AD798
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
_0801C8D0: .4byte gCurrentPinballGame
_0801C8D4: .4byte 0x000006DB
_0801C8D8: .4byte 0x00000749
_0801C8DC: .4byte 0x000006D9
_0801C8E0: .4byte 0x040000D4
_0801C8E4: .4byte gUnknown_0848D68C
_0801C8E8: .4byte 0x06010CA0
_0801C8EC: .4byte 0x80000180
_0801C8F0: .4byte gUnknown_081C00E4
_0801C8F4: .4byte gUnknown_086AD798
_0801C8F8: .4byte 0x05000200
_0801C8FC: .4byte 0x80000010
_0801C900:
	ldr r7, _0801C97C @ =gUnknown_086AD070
	ldr r6, _0801C980 @ =gCurrentPinballGame
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
	ldr r1, _0801C98C @ =gUnknown_083A8EEC
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
	ldr r0, _0801C998 @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801C99C @ =gUnknown_086AD798
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
_0801C97C: .4byte gUnknown_086AD070
_0801C980: .4byte gCurrentPinballGame
_0801C984: .4byte 0x00000749
_0801C988: .4byte 0x040000D4
_0801C98C: .4byte gUnknown_083A8EEC
_0801C990: .4byte 0x06010CA0
_0801C994: .4byte 0x80000180
_0801C998: .4byte gUnknown_081C02E4
_0801C99C: .4byte gUnknown_086AD798
_0801C9A0: .4byte 0x05000200
_0801C9A4: .4byte 0x80000010
_0801C9A8:
	ldr r5, _0801CA1C @ =gCurrentPinballGame
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
	ldr r1, _0801CA24 @ =gUnknown_086AD000
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
	ldr r1, _0801CA30 @ =gUnknown_083A8EEC
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
	ldr r0, _0801CA3C @ =gUnknown_081C02E4
	adds r3, r3, r0
	str r3, [r4]
	ldr r0, _0801CA40 @ =gUnknown_086AD798
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
_0801CA1C: .4byte gCurrentPinballGame
_0801CA20: .4byte 0x000006EC
_0801CA24: .4byte gUnknown_086AD000
_0801CA28: .4byte 0x00000749
_0801CA2C: .4byte 0x040000D4
_0801CA30: .4byte gUnknown_083A8EEC
_0801CA34: .4byte 0x06010CA0
_0801CA38: .4byte 0x80000180
_0801CA3C: .4byte gUnknown_081C02E4
_0801CA40: .4byte gUnknown_086AD798
_0801CA44: .4byte 0x05000200
_0801CA48: .4byte 0x80000010
_0801CA4C:
	ldr r7, _0801CAFC @ =gCurrentPinballGame
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
_0801CAFC: .4byte gCurrentPinballGame
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
	ldr r0, _0801CB68 @ =gCurrentPinballGame
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
	ldr r0, _0801CB6C @ =gMain+0x74
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
_0801CB68: .4byte gCurrentPinballGame
_0801CB6C: .4byte gMain+0x74
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
	ldr r0, _0801CD28 @ =gCurrentPinballGame
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
	ldr r6, _0801CD30 @ =gUnknown_086AD000
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
	ldr r1, _0801CD38 @ =gUnknown_083A8EEC
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
_0801CD28: .4byte gCurrentPinballGame
_0801CD2C: .4byte 0x00000749
_0801CD30: .4byte gUnknown_086AD000
_0801CD34: .4byte 0x040000D4
_0801CD38: .4byte gUnknown_083A8EEC
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
	ldr r6, _0801CDAC @ =gUnknown_086AD000
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
	ldr r1, _0801CDB4 @ =gUnknown_083A8EEC
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
_0801CDAC: .4byte gUnknown_086AD000
_0801CDB0: .4byte 0x040000D4
_0801CDB4: .4byte gUnknown_083A8EEC
_0801CDB8: .4byte 0x06010CA0
_0801CDBC: .4byte 0x80000180
_0801CDC0:
	ldr r4, _0801CEF8 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801CEFC @ =0x000001A7
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801CF00 @ =gUnknown_086AD000
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
	ldr r1, _0801CF0C @ =gUnknown_083A8EEC
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
	ldr r1, _0801CF18 @ =gUnknown_086AD2DE
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
	ldr r1, _0801CF20 @ =gUnknown_081C02E4
	adds r0, r0, r1
	str r0, [r2]
	mov r4, sp
	str r4, [r2, #4]
	ldr r0, _0801CF24 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r5, _0801CF28 @ =gUnknown_086AD798
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
_0801CEF8: .4byte gCurrentPinballGame
_0801CEFC: .4byte 0x000001A7
_0801CF00: .4byte gUnknown_086AD000
_0801CF04: .4byte 0x00000749
_0801CF08: .4byte 0x040000D4
_0801CF0C: .4byte gUnknown_083A8EEC
_0801CF10: .4byte 0x06010CA0
_0801CF14: .4byte 0x80000180
_0801CF18: .4byte gUnknown_086AD2DE
_0801CF1C: .4byte 0x000001AF
_0801CF20: .4byte gUnknown_081C02E4
_0801CF24: .4byte 0x80000010
_0801CF28: .4byte gUnknown_086AD798
_0801CF2C: .4byte 0x05000200
_0801CF30:
	ldr r2, _0801CF58 @ =0x040000D4
	lsls r0, r5, #1
	ldr r1, _0801CF5C @ =gUnknown_081C02E4
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0801CF60 @ =gUnknown_086AD798
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
_0801CF5C: .4byte gUnknown_081C02E4
_0801CF60: .4byte gUnknown_086AD798
_0801CF64: .4byte 0x05000200
_0801CF68: .4byte 0x80000010
_0801CF6C:
	ldr r5, _0801CFFC @ =gCurrentPinballGame
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
	ldr r1, _0801D004 @ =gUnknown_086AD000
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
	ldr r1, _0801D010 @ =gUnknown_083A8EEC
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
	ldr r0, _0801D01C @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D020 @ =gUnknown_086AD798
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
_0801CFFC: .4byte gCurrentPinballGame
_0801D000: .4byte 0x000006EC
_0801D004: .4byte gUnknown_086AD000
_0801D008: .4byte 0x00000749
_0801D00C: .4byte 0x040000D4
_0801D010: .4byte gUnknown_083A8EEC
_0801D014: .4byte 0x06010CA0
_0801D018: .4byte 0x80000180
_0801D01C: .4byte gUnknown_081C02E4
_0801D020: .4byte gUnknown_086AD798
_0801D024: .4byte 0x05000200
_0801D028: .4byte 0x80000010
_0801D02C:
	ldr r2, _0801D0EC @ =gCurrentPinballGame
	mov sb, r2
	ldr r2, [r2]
	ldr r3, _0801D0F0 @ =0x000006DC
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _0801D0F4 @ =gUnknown_086AD000
	adds r7, r0, r1
	ldr r5, [sp, #0x2c]
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	ldr r0, _0801D0F8 @ =0x00000749
	mov r8, r0
	adds r5, r2, r0
	adds r5, r5, r4
	ldr r6, _0801D0FC @ =gUnknown_086AD79C
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
	ldr r1, _0801D108 @ =gUnknown_083A8EEC
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
	ldr r0, _0801D114 @ =gUnknown_081C02E4
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, _0801D118 @ =gUnknown_086AD798
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
_0801D0EC: .4byte gCurrentPinballGame
_0801D0F0: .4byte 0x000006DC
_0801D0F4: .4byte gUnknown_086AD000
_0801D0F8: .4byte 0x00000749
_0801D0FC: .4byte gUnknown_086AD79C
_0801D100: .4byte 0x000006DE
_0801D104: .4byte 0x040000D4
_0801D108: .4byte gUnknown_083A8EEC
_0801D10C: .4byte 0x06010CA0
_0801D110: .4byte 0x80000180
_0801D114: .4byte gUnknown_081C02E4
_0801D118: .4byte gUnknown_086AD798
_0801D11C: .4byte 0x05000200
_0801D120: .4byte 0x80000010
_0801D124: .4byte 0x00000747
