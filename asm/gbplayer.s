	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1828
sub_1828: @ 0x08001828
	push {r4, r5, lr}
	ldr r3, _08001868 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _0800186C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08001870 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
	movs r5, #1
	strh r5, [r3]
	strh r4, [r3]
	subs r2, #0xd8
	ldrh r1, [r2]
	ldr r0, _08001874 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	strh r5, [r3]
	ldr r0, _08001878 @ =0x0400010E
	strh r4, [r0]
	ldr r1, _0800187C @ =0x0400010C
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08001880 @ =gUnknown_02019C10
	movs r0, #5
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001868: .4byte 0x04000208
_0800186C: .4byte 0x04000200
_08001870: .4byte 0x0000FFBF
_08001874: .4byte 0x0000FF7F
_08001878: .4byte 0x0400010E
_0800187C: .4byte 0x0400010C
_08001880: .4byte gUnknown_02019C10
