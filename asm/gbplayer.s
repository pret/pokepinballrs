	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_1668
sub_1668: @ 0x08001668
	push {r4, r5, lr}
	ldr r2, _0800169C @ =0x00FFFFFF
	ands r2, r0
	lsls r4, r2, #4
	lsls r1, r1, #0x1c
	orrs r4, r1
	lsrs r3, r4, #0x1c
	movs r2, #6
	movs r5, #0xf
_0800167A:
	lsls r0, r2, #2
	adds r1, r4, #0
	lsrs r1, r0
	ands r1, r5
	eors r3, r1
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0800167A
	movs r0, #0xf
	ands r3, r0
	orrs r4, r3
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800169C: .4byte 0x00FFFFFF

	thumb_func_start sub_16A0
sub_16A0: @ 0x080016A0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r6, _080016C4 @ =gUnknown_02002818
	ldr r0, [r6]
	lsrs r5, r0, #0x1c
	bl sub_170C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080016DE
	cmp r4, #2
	beq _080016E8
	cmp r4, #2
	bgt _080016C8
	cmp r4, #1
	beq _080016CE
	b _080016DE
	.align 2, 0
_080016C4: .4byte gUnknown_02002818
_080016C8:
	cmp r4, #3
	beq _08001700
	b _080016DE
_080016CE:
	ldr r1, _080016E4 @ =gUnknown_0200281C
	ldr r0, [r6]
	lsls r0, r0, #4
	lsrs r0, r0, #8
	ands r0, r4
	str r0, [r1]
	cmp r5, #1
	beq _08001704
_080016DE:
	movs r0, #1
	b _08001706
	.align 2, 0
_080016E4: .4byte gUnknown_0200281C
_080016E8:
	cmp r5, #2
	bne _080016DE
	ldr r0, _080016FC @ =gUnknown_0200281C
	ldr r1, [r6]
	lsls r1, r1, #4
	lsrs r1, r1, #8
	ldr r0, [r0]
	cmp r0, r1
	beq _08001704
	b _080016DE
	.align 2, 0
_080016FC: .4byte gUnknown_0200281C
_08001700:
	cmp r5, #3
	bne _080016DE
_08001704:
	movs r0, #0
_08001706:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_170C
sub_170C: @ 0x0800170C
	push {r4, r5, r6, lr}
	ldr r0, _0800173C @ =gUnknown_02002818
	ldr r0, [r0]
	lsrs r4, r0, #4
	movs r5, #0xf
	ands r5, r0
	lsrs r3, r4, #0x18
	movs r0, #6
	movs r6, #0xf
_0800171E:
	subs r0, #1
	lsls r2, r0, #2
	adds r1, r4, #0
	lsrs r1, r2
	ands r1, r6
	eors r3, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0800171E
	cmp r3, r5
	beq _08001740
	movs r0, #1
	b _08001742
	.align 2, 0
_0800173C: .4byte gUnknown_02002818
_08001740:
	movs r0, #0
_08001742:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_1748
sub_1748: @ 0x08001748
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #4
	bhi _080017CE
	lsls r0, r0, #2
	ldr r1, _08001760 @ =_08001764
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001760: .4byte _08001764
_08001764: @ jump table
	.4byte _080017C4 @ case 0
	.4byte _08001778 @ case 1
	.4byte _08001784 @ case 2
	.4byte _080017C4 @ case 3
	.4byte _080017C4 @ case 4
_08001778:
	ldr r0, _08001780 @ =gUnknown_0200281C
	ldr r0, [r0]
	movs r1, #2
	b _080017C8
	.align 2, 0
_08001780: .4byte gUnknown_0200281C
_08001784:
	ldr r4, _080017C0 @ =gUnknown_02019C00
	ldr r0, [r4]
	cmp r0, #0
	bne _0800179A
	movs r0, #0
	bl sub_17D8
	movs r1, #4
	bl sub_1668
	adds r2, r0, #0
_0800179A:
	ldr r0, [r4]
	cmp r0, #1
	bne _080017AE
	movs r0, #1
	bl sub_17D8
	movs r1, #4
	bl sub_1668
	adds r2, r0, #0
_080017AE:
	ldr r0, [r4]
	cmp r0, #2
	bne _080017CE
	movs r0, #2
	bl sub_17D8
	movs r1, #4
	b _080017C8
	.align 2, 0
_080017C0: .4byte gUnknown_02019C00
_080017C4:
	movs r0, #1
	movs r1, #1
_080017C8:
	bl sub_1668
	adds r2, r0, #0
_080017CE:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1

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
