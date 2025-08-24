#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_2530C
sub_2530C: @ 0x0802530C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080253D0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r5, [r1, #0x48]
	ldrh r1, [r5]
	mov r8, r0
	ldr r0, _080253D4 @ =gCurrentPinballGame
	mov sb, r0
	cmp r1, #0
	beq _08025360
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025330:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
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
	cmp r2, #5
	ble _08025330
_08025360:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x48]
	movs r0, #0
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r5, [r0, #0x30]
	ldrh r0, [r5]
	cmp r0, #0
	beq _080253B0
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025380:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
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
	cmp r2, #5
	ble _08025380
_080253B0:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x30]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xe4
	strb r2, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080253D0: .4byte gMain
_080253D4: .4byte gCurrentPinballGame
_080253D8: .4byte gOamBuffer
_080253DC: .4byte 0xFFFFFE00
