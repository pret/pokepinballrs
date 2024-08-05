	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_13FC
sub_13FC: @ 0x080013FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r1, _08001434 @ =gUnknown_02002818
	ldr r0, _08001438 @ =0x04000120
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800143C @ =0x0400010E
	movs r0, #0
	strh r0, [r1]
	subs r1, #2
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08001440 @ =gUnknown_02019C10
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #5
	bls _0800142A
	b _0800161C
_0800142A:
	lsls r0, r1, #2
	ldr r1, _08001444 @ =_08001448
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001434: .4byte gUnknown_02002818
_08001438: .4byte 0x04000120
_0800143C: .4byte 0x0400010E
_08001440: .4byte gUnknown_02019C10
_08001444: .4byte _08001448
_08001448: @ jump table
	.4byte _08001460 @ case 0
	.4byte _08001520 @ case 1
	.4byte _08001574 @ case 2
	.4byte _080015C8 @ case 3
	.4byte _0800161C @ case 4
	.4byte _0800161C @ case 5
_08001460:
	ldr r0, _080014B0 @ =0x04000120
	mov r8, r0
	ldr r6, [r0]
	ldr r3, _080014B4 @ =gUnknown_02002808
	ldrb r1, [r3]
	lsls r2, r1, #4
	adds r0, r6, #0
	lsls r0, r2
	lsrs r0, r0, #0x10
	movs r7, #1
	subs r1, r7, r1
	lsls r1, r1, #4
	lsls r6, r1
	adds r1, r6, #0
	lsrs r6, r1, #0x10
	ldrh r5, [r3, #0xa]
	adds r4, r3, #0
	cmp r5, #0
	bne _080014E4
	ldrh r2, [r4, #6]
	adds r1, r0, #0
	cmp r1, r2
	bne _080014E2
	ldrh r3, [r4, #2]
	cmp r3, #3
	bhi _080014B8
	ldrh r0, [r4, #4]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne _080014E4
	mvns r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bne _080014E4
	adds r0, r3, #1
	strh r0, [r4, #2]
	b _080014E4
	.align 2, 0
_080014B0: .4byte 0x04000120
_080014B4: .4byte gUnknown_02002808
_080014B8:
	strh r6, [r4, #0xa]
	ldr r0, _080014D8 @ =0x00008002
	cmp r6, r0
	bne _080014E0
	mov r1, sb
	strb r7, [r1]
	movs r0, #1
	bl sub_1748
	ldr r1, _080014DC @ =gUnknown_02002814
	str r0, [r1]
	mov r2, r8
	str r0, [r2]
	strh r5, [r4, #2]
	b _08001640
	.align 2, 0
_080014D8: .4byte 0x00008002
_080014DC: .4byte gUnknown_02002814
_080014E0:
	strh r5, [r4, #0xa]
_080014E2:
	strh r5, [r4, #2]
_080014E4:
	ldrh r0, [r4, #2]
	cmp r0, #3
	bhi _080014F8
	lsls r0, r0, #1
	ldr r1, _080014F4 @ =gUnknown_0805C748
	adds r0, r0, r1
	ldrh r0, [r0]
	b _080014FC
	.align 2, 0
_080014F4: .4byte gUnknown_0805C748
_080014F8:
	movs r0, #0x80
	lsls r0, r0, #8
_080014FC:
	strh r0, [r4, #4]
	mvns r0, r6
	strh r0, [r4, #6]
	ldr r3, _0800151C @ =0x04000120
	ldrh r2, [r4, #4]
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	lsls r2, r0
	ldrh r0, [r4, #6]
	lsls r1, r1, #4
	lsls r0, r1
	adds r2, r2, r0
	str r2, [r3]
	b _08001640
	.align 2, 0
_0800151C: .4byte 0x04000120
_08001520:
	ldr r5, _08001544 @ =gUnknown_02019C10
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _08001550
	ldr r1, _08001548 @ =gUnknown_02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp]
	ldr r2, _0800154C @ =0x05000003
	mov r0, sp
	bl CpuSet
	strb r4, [r5]
	b _08001554
	.align 2, 0
_08001544: .4byte gUnknown_02019C10
_08001548: .4byte gUnknown_02002808
_0800154C: .4byte 0x05000003
_08001550:
	movs r0, #2
	strb r0, [r5]
_08001554:
	ldr r0, _0800156C @ =gUnknown_02019BF4
	ldr r0, [r0]
	ldr r1, _08001570 @ =gUnknown_02019C10
	mov sb, r1
	cmp r0, #0
	bne _08001564
	movs r0, #4
	strb r0, [r1]
_08001564:
	mov r2, sb
	ldrb r0, [r2]
	b _080015F8
	.align 2, 0
_0800156C: .4byte gUnknown_02019BF4
_08001570: .4byte gUnknown_02019C10
_08001574:
	ldr r5, _08001598 @ =gUnknown_02019C10
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _080015A4
	ldr r1, _0800159C @ =gUnknown_02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, _080015A0 @ =0x05000003
	bl CpuSet
	strb r4, [r5]
	b _080015A8
	.align 2, 0
_08001598: .4byte gUnknown_02019C10
_0800159C: .4byte gUnknown_02002808
_080015A0: .4byte 0x05000003
_080015A4:
	movs r0, #3
	strb r0, [r5]
_080015A8:
	ldr r0, _080015C0 @ =gUnknown_02019BF4
	ldr r0, [r0]
	ldr r1, _080015C4 @ =gUnknown_02019C10
	mov sb, r1
	cmp r0, #0
	bne _080015B8
	movs r0, #4
	strb r0, [r1]
_080015B8:
	mov r2, sb
	ldrb r0, [r2]
	b _080015F8
	.align 2, 0
_080015C0: .4byte gUnknown_02019BF4
_080015C4: .4byte gUnknown_02019C10
_080015C8:
	mov r5, sb
	ldrb r0, [r5]
	bl sub_16A0
	cmp r0, #0
	beq _080015E8
	ldr r1, _08001608 @ =gUnknown_02002808
	movs r4, #0
	movs r0, #0
	strh r0, [r1, #2]
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _0800160C @ =0x05000003
	bl CpuSet
	strb r4, [r5]
_080015E8:
	ldr r0, _08001610 @ =gUnknown_02019BF4
	ldr r0, [r0]
	cmp r0, #0
	bne _080015F4
	movs r0, #4
	strb r0, [r5]
_080015F4:
	mov r1, sb
	ldrb r0, [r1]
_080015F8:
	bl sub_1748
	ldr r1, _08001614 @ =gUnknown_02002814
	str r0, [r1]
	ldr r1, _08001618 @ =0x04000120
	str r0, [r1]
	b _08001640
	.align 2, 0
_08001608: .4byte gUnknown_02002808
_0800160C: .4byte 0x05000003
_08001610: .4byte gUnknown_02019BF4
_08001614: .4byte gUnknown_02002814
_08001618: .4byte 0x04000120
_0800161C:
	ldr r3, _08001634 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08001638 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0800163C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	b _08001650
	.align 2, 0
_08001634: .4byte 0x04000208
_08001638: .4byte 0x04000200
_0800163C: .4byte 0x0000FF7F
_08001640:
	ldr r2, _08001660 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08001664 @ =0x0400010E
	movs r0, #0xc1
	strh r0, [r1]
_08001650:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001660: .4byte 0x04000128
_08001664: .4byte 0x0400010E

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
