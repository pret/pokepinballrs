	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_17D8
sub_17D8: @ 0x080017D8
	adds r2, r0, #0
	ldr r0, _080017EC @ =gUnknown_02019BEC
	ldr r0, [r0]
	cmp r0, #4
	bhi _08001824
	lsls r0, r0, #2
	ldr r1, _080017F0 @ =_080017F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080017EC: .4byte gUnknown_02019BEC
_080017F0: .4byte _080017F4
_080017F4: @ jump table
	.4byte _08001808 @ case 0
	.4byte _0800180C @ case 1
	.4byte _08001810 @ case 2
	.4byte _08001814 @ case 3
	.4byte _08001818 @ case 4
_08001808:
	adds r1, r2, #0
	b _08001824
_0800180C:
	lsls r1, r2, #2
	b _08001824
_08001810:
	lsls r1, r2, #4
	b _08001824
_08001814:
	lsls r1, r2, #6
	b _08001824
_08001818:
	lsls r1, r2, #2
	orrs r1, r2
	lsls r0, r2, #4
	orrs r1, r0
	lsls r0, r2, #6
	orrs r1, r0
_08001824:
	adds r0, r1, #0
	bx lr

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
