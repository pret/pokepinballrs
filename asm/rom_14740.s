#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_162B8
sub_162B8: @ 0x080162B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	movs r7, #0
	movs r6, #0
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08016418 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801641C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _080162E8
	b _08016408
_080162E8:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _080162FA
	b _08016408
_080162FA:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	adds r5, #2
	adds r0, r2, r5
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	mov r8, r3
	mov sb, r2
	cmp r0, #0x3f
	bhi _08016342
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08016342
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	mov r0, ip
	str r0, [sp, #8]
_08016342:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #1
	str r0, [sp, #8]
_0801638C:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc7
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #2
	str r0, [sp, #8]
_080163D6:
	cmp r6, #0
	beq _08016408
_080163DA:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [sp, #8]
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	ldr r5, [sp]
	strh r7, [r5]
	ldr r0, [sp, #4]
	strb r6, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08016428 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08016408
	movs r0, #2
	strb r0, [r1]
_08016408:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016418: .4byte gCurrentPinballGame
_0801641C: .4byte 0x000005B2
_08016420: .4byte gUnknown_08252B10
_08016424: .4byte 0x0000FFF0
_08016428: .4byte 0x00000624
