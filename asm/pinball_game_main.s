#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
