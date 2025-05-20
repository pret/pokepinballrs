#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

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
