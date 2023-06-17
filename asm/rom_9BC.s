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

@ file boundary?

	thumb_func_start sub_1884
sub_1884: @ 0x08001884
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r0, _08001944 @ =gUnknown_02002822
	mov r8, r0
	ldr r5, _08001948 @ =0x04000208
	ldrh r2, [r5]
	movs r4, #0
	strh r4, [r5]
	ldr r6, _0800194C @ =0x04000200
	ldrh r1, [r6]
	ldr r0, _08001950 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r6]
	strh r2, [r5]
	ldr r0, _08001954 @ =0x04000134
	strh r4, [r0]
	ldr r2, _08001958 @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r3, _0800195C @ =0x00004003
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r5]
	mov r1, r8
	strh r0, [r1]
	ldr r0, _08001960 @ =sub_19CC + 1
	bl SetMainCallback
	ldr r0, _08001964 @ =sub_1A78 + 1
	bl SetVBlankIntrFunc
	strh r4, [r5]
	ldrh r0, [r6]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r6]
	mov r3, r8
	ldrh r0, [r3]
	strh r0, [r5]
	ldr r0, _08001968 @ =0x0400012A
	strh r4, [r0]
	ldr r2, _0800196C @ =0x04000120
	movs r0, #0
	movs r1, #0
	str r0, [r2]
	str r1, [r2, #4]
	movs r5, #0
	str r5, [sp]
	ldr r1, _08001970 @ =gUnknown_0202BF20
	ldr r2, _08001974 @ =0x05000189
	mov r0, sp
	bl CpuSet
	ldr r0, _08001978 @ =gUnknown_02002824
	strb r4, [r0]
	ldr r0, _0800197C @ =gUnknown_02002825
	strb r4, [r0]
	ldr r0, _08001980 @ =gUnknown_02002827
	strb r4, [r0]
	ldr r0, _08001984 @ =gUnknown_02019C2C
	strb r4, [r0]
	ldr r0, _08001988 @ =gUnknown_0202A554
	strb r4, [r0]
	ldr r0, _0800198C @ =gUnknown_0202C5E0
	strb r4, [r0]
	ldr r0, _08001990 @ =gUnknown_0202ADD0
	str r5, [r0]
	ldr r0, _08001994 @ =gUnknown_0201A444
	strh r5, [r0]
	ldr r0, _08001998 @ =gUnknown_0202BDF0
	str r5, [r0]
	ldr r0, _0800199C @ =gUnknown_0201C1AC
	strb r4, [r0]
	ldr r0, _080019A0 @ =gUnknown_0202ADDC
	strb r4, [r0]
	ldr r0, _080019A4 @ =gUnknown_0202BEC8
	strb r4, [r0]
	ldr r0, _080019A8 @ =gUnknown_02002820
	strb r4, [r0]
	ldr r0, _080019AC @ =gUnknown_02002828
	strh r5, [r0]
	ldr r0, _080019B0 @ =gUnknown_0200282A
	strh r5, [r0]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001944: .4byte gUnknown_02002822
_08001948: .4byte 0x04000208
_0800194C: .4byte 0x04000200
_08001950: .4byte 0x0000FF3F
_08001954: .4byte 0x04000134
_08001958: .4byte 0x04000128
_0800195C: .4byte 0x00004003
_08001960: .4byte sub_19CC + 1
_08001964: .4byte sub_1A78 + 1
_08001968: .4byte 0x0400012A
_0800196C: .4byte 0x04000120
_08001970: .4byte gUnknown_0202BF20
_08001974: .4byte 0x05000189
_08001978: .4byte gUnknown_02002824
_0800197C: .4byte gUnknown_02002825
_08001980: .4byte gUnknown_02002827
_08001984: .4byte gUnknown_02019C2C
_08001988: .4byte gUnknown_0202A554
_0800198C: .4byte gUnknown_0202C5E0
_08001990: .4byte gUnknown_0202ADD0
_08001994: .4byte gUnknown_0201A444
_08001998: .4byte gUnknown_0202BDF0
_0800199C: .4byte gUnknown_0201C1AC
_080019A0: .4byte gUnknown_0202ADDC
_080019A4: .4byte gUnknown_0202BEC8
_080019A8: .4byte gUnknown_02002820
_080019AC: .4byte gUnknown_02002828
_080019B0: .4byte gUnknown_0200282A

	thumb_func_start sub_19B4
sub_19B4: @ 0x080019B4
	push {lr}
	bl sub_24DC
	bl sub_250C
	bl sub_1884
	bl sub_1AA4
	pop {r0}
	bx r0

	thumb_func_start sub_19CC
sub_19CC: @ 0x080019CC
	push {lr}
	ldr r0, _08001A6C @ =0x04000004
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08001A64
	ldr r0, _08001A70 @ =gOamBuffer
	movs r1, #0xe0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuSet
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _08001A74 @ =gMain
	ldrh r0, [r2, #0x16]
	strh r0, [r1]
	adds r1, #0x10
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _08001A60
	adds r1, #0x32
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3c]
	strh r0, [r1]
_08001A60:
	bl VBlankIntrWait
_08001A64:
	bl m4aSoundMain
	pop {r0}
	bx r0
	.align 2, 0
_08001A6C: .4byte 0x04000004
_08001A70: .4byte gOamBuffer
_08001A74: .4byte gMain

	thumb_func_start sub_1A78
sub_1A78: @ 0x08001A78
	push {lr}
	bl sub_1EC0
	bl m4aSoundVSync
	ldr r3, _08001A98 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08001A9C @ =INTR_CHECK
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	strh r1, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_08001A98: .4byte 0x04000208
_08001A9C: .4byte 0x03007FF8 @ INTR_CHECK

	thumb_func_start nullsub_15
nullsub_15: @ 0x08001AA0
	bx lr

	thumb_func_start sub_1AA4
sub_1AA4: @ 0x08001AA4
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08001AE4 @ =gUnknown_02002822
	ldr r2, _08001AE8 @ =0x04000208
	ldrh r5, [r2]
	strh r5, [r0]
	movs r4, #0
	strh r4, [r2]
	ldr r3, _08001AEC @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _08001AF0 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r3]
	strh r5, [r2]
	ldr r0, _08001AF4 @ =0x04000128
	strh r4, [r0]
	subs r0, #0x1a
	strh r4, [r0]
	ldr r1, _08001AF8 @ =0x04000202
	movs r0, #0xc0
	strh r0, [r1]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08001AFC @ =gUnknown_0202BF20
	ldr r2, _08001B00 @ =0x05000189
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001AE4: .4byte gUnknown_02002822
_08001AE8: .4byte 0x04000208
_08001AEC: .4byte 0x04000200
_08001AF0: .4byte 0x0000FF3F
_08001AF4: .4byte 0x04000128
_08001AF8: .4byte 0x04000202
_08001AFC: .4byte gUnknown_0202BF20
_08001B00: .4byte 0x05000189

	thumb_func_start sub_1B04
sub_1B04: @ 0x08001B04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _08001B20 @ =gUnknown_0202BF20
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _08001BEE
	lsls r0, r0, #2
	ldr r1, _08001B24 @ =_08001B28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08001B20: .4byte gUnknown_0202BF20
_08001B24: .4byte _08001B28
_08001B28: @ jump table
	.4byte _08001B3C @ case 0
	.4byte _08001B4C @ case 1
	.4byte _08001B5C @ case 2
	.4byte _08001BD0 @ case 3
	.4byte _08001BDA @ case 4
_08001B3C:
	bl sub_1AA4
	ldr r1, _08001B48 @ =gUnknown_0202BF20
	movs r0, #1
	strb r0, [r1, #1]
	b _08001BEE
	.align 2, 0
_08001B48: .4byte gUnknown_0202BF20
_08001B4C:
	bl sub_1884
	ldr r1, _08001B58 @ =gUnknown_0202BF20
	movs r0, #2
	strb r0, [r1, #1]
	b _08001BEE
	.align 2, 0
_08001B58: .4byte gUnknown_0202BF20
_08001B5C:
	ldrb r1, [r6]
	cmp r1, #1
	beq _08001B98
	cmp r1, #2
	beq _08001BBC
	bl sub_1C5C
	ldr r2, _08001B90 @ =gUnknown_0202C5E0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08001BEE
	ldr r1, _08001B94 @ =gUnknown_0202BF20
	ldrb r0, [r1]
	cmp r0, #0
	beq _08001BEE
	ldrb r0, [r1, #3]
	cmp r0, #2
	bne _08001BEE
	movs r0, #1
	strb r0, [r1, #0x10]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	strb r0, [r2]
	b _08001BEE
	.align 2, 0
_08001B90: .4byte gUnknown_0202C5E0
_08001B94: .4byte gUnknown_0202BF20
_08001B98:
	ldr r2, _08001BB4 @ =gUnknown_0202BF20
	ldrb r0, [r2]
	cmp r0, #0
	beq _08001BA8
	ldrb r0, [r2, #3]
	cmp r0, #2
	bne _08001BA8
	strb r1, [r2, #0x10]
_08001BA8:
	ldr r1, _08001BB8 @ =gUnknown_0202C5E0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r1]
	b _08001BEE
	.align 2, 0
_08001BB4: .4byte gUnknown_0202BF20
_08001BB8: .4byte gUnknown_0202C5E0
_08001BBC:
	ldr r0, _08001BC8 @ =gUnknown_0202BF20
	movs r1, #0
	strb r1, [r0, #1]
	ldr r0, _08001BCC @ =0x0400012A
	strh r1, [r0]
	b _08001BEE
	.align 2, 0
_08001BC8: .4byte gUnknown_0202BF20
_08001BCC: .4byte 0x0400012A
_08001BD0:
	bl sub_1C84
	ldr r1, _08001C30 @ =gUnknown_0202BF20
	movs r0, #4
	strb r0, [r1, #1]
_08001BDA:
	ldr r0, _08001C30 @ =gUnknown_0202BF20
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	bne _08001BE8
	adds r0, r4, #0
	bl sub_1CD4
_08001BE8:
	adds r0, r5, #0
	bl sub_1DB8
_08001BEE:
	movs r0, #0
	strb r0, [r6]
	ldr r1, _08001C30 @ =gUnknown_0202BF20
	ldrb r2, [r1, #2]
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _08001C06
	movs r0, #0x20
	orrs r2, r0
_08001C06:
	ldrb r0, [r1, #0xc]
	lsls r3, r0, #8
	ldrb r0, [r1, #0x11]
	lsls r4, r0, #9
	ldrb r0, [r1, #0x12]
	lsls r5, r0, #0x10
	ldrb r0, [r1, #0x13]
	lsls r6, r0, #0x11
	ldrb r0, [r1, #0x14]
	lsls r7, r0, #0x12
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #0x14
	mov ip, r0
	ldrb r0, [r1, #1]
	cmp r0, #4
	bne _08001C34
	movs r0, #0x40
	orrs r0, r3
	orrs r0, r2
	b _08001C38
	.align 2, 0
_08001C30: .4byte gUnknown_0202BF20
_08001C34:
	adds r0, r2, #0
	orrs r0, r3
_08001C38:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	mov r2, ip
	orrs r0, r2
	adds r2, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #1
	bls _08001C52
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r2, r0
_08001C52:
	adds r0, r2, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_1C5C
sub_1C5C: @ 0x08001C5C
	ldr r0, _08001C74 @ =0x04000128
	ldr r1, [r0]
	movs r0, #0xc
	ands r1, r0
	ldr r2, _08001C78 @ =gUnknown_0202BF20
	cmp r1, #8
	bne _08001C7C
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _08001C7C
	strb r1, [r2]
	b _08001C80
	.align 2, 0
_08001C74: .4byte 0x04000128
_08001C78: .4byte gUnknown_0202BF20
_08001C7C:
	movs r0, #0
	strb r0, [r2]
_08001C80:
	bx lr

	thumb_func_start sub_1C84
sub_1C84: @ 0x08001C84
	push {r4, lr}
	ldr r0, _08001CBC @ =gUnknown_0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08001CB4
	ldr r1, _08001CC0 @ =0x0400010C
	ldr r2, _08001CC4 @ =0x0000FF3B
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x41
	strh r0, [r1]
	ldr r0, _08001CC8 @ =gUnknown_02002822
	ldr r2, _08001CCC @ =0x04000208
	ldrh r4, [r2]
	strh r4, [r0]
	movs r0, #0
	strh r0, [r2]
	ldr r3, _08001CD0 @ =0x04000200
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3]
	strh r4, [r2]
_08001CB4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001CBC: .4byte gUnknown_0202BF20
_08001CC0: .4byte 0x0400010C
_08001CC4: .4byte 0x0000FF3B
_08001CC8: .4byte gUnknown_02002822
_08001CCC: .4byte 0x04000208
_08001CD0: .4byte 0x04000200

	thumb_func_start sub_1CD4
sub_1CD4: @ 0x08001CD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	ldr r2, _08001D48 @ =gUnknown_02002822
	ldr r1, _08001D4C @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08001D50 @ =gUnknown_0202BF20
	ldr r4, _08001D54 @ =0x0000021D
	adds r0, r1, r4
	ldrb r4, [r0]
	mov sl, r2
	adds r6, r1, #0
	cmp r4, #0x1f
	bhi _08001D60
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08001D14
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08001D14:
	movs r2, #0
	ldr r4, _08001D58 @ =gUnknown_02002828
	mov r8, r4
	ldr r1, _08001D5C @ =gUnknown_02019C2C
	mov sb, r1
	lsls r5, r0, #1
	movs r0, #0x1c
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
_08001D28:
	ldrh r0, [r4]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r4]
	lsls r0, r2, #6
	adds r0, r5, r0
	add r0, ip
	strh r1, [r0]
	strh r7, [r3]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _08001D28
	b _08001D70
	.align 2, 0
_08001D48: .4byte gUnknown_02002822
_08001D4C: .4byte 0x04000208
_08001D50: .4byte gUnknown_0202BF20
_08001D54: .4byte 0x0000021D
_08001D58: .4byte gUnknown_02002828
_08001D5C: .4byte gUnknown_02019C2C
_08001D60:
	ldrb r1, [r6, #0x14]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0x14]
	ldr r1, _08001DA8 @ =gUnknown_02002828
	mov r8, r1
	ldr r2, _08001DAC @ =gUnknown_02019C2C
	mov sb, r2
_08001D70:
	mov r4, r8
	ldrh r0, [r4]
	cmp r0, #0
	beq _08001D86
	ldr r1, _08001DB0 @ =0x0000021D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strh r2, [r4]
_08001D86:
	ldr r1, _08001DB4 @ =0x04000208
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r4, _08001DB0 @ =0x0000021D
	adds r0, r6, r4
	ldrb r0, [r0]
	mov r1, sb
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001DA8: .4byte gUnknown_02002828
_08001DAC: .4byte gUnknown_02019C2C
_08001DB0: .4byte 0x0000021D
_08001DB4: .4byte 0x04000208

	thumb_func_start sub_1DB8
sub_1DB8: @ 0x08001DB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r2, _08001E18 @ =gUnknown_02002822
	ldr r1, _08001E1C @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08001E20 @ =gUnknown_0202BF20
	ldr r3, _08001E24 @ =0x00000621
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	bne _08001E28
	movs r1, #0
	mov r8, r7
	ldrb r6, [r7, #3]
_08001DE4:
	movs r2, #0
	adds r5, r1, #1
	cmp r2, r6
	bhs _08001E08
	lsls r0, r1, #2
	mov r3, ip
	adds r1, r0, r3
	movs r4, #0
	mov r0, r8
	ldrb r3, [r0, #3]
_08001DF8:
	lsls r0, r2, #1
	adds r0, r0, r1
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	blo _08001DF8
_08001E08:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls _08001DE4
	movs r0, #1
	strb r0, [r7, #0xc]
	b _08001E9A
	.align 2, 0
_08001E18: .4byte gUnknown_02002822
_08001E1C: .4byte 0x04000208
_08001E20: .4byte gUnknown_0202BF20
_08001E24: .4byte 0x00000621
_08001E28:
	movs r1, #0
	ldrb r2, [r7, #3]
	mov sb, r2
	movs r3, #0x88
	lsls r3, r3, #2
	adds r3, r3, r7
	mov r8, r3
	mov sl, r7
_08001E38:
	movs r2, #0
	adds r5, r1, #1
	cmp r2, sb
	bhs _08001E6C
	lsls r0, r1, #2
	mov r3, ip
	adds r6, r0, r3
	ldr r0, _08001EB0 @ =gUnknown_0202C540
	ldrb r0, [r0]
	lsls r0, r0, #1
	lsls r1, r1, #6
	adds r4, r0, r1
	mov r0, sl
	ldrb r3, [r0, #3]
_08001E54:
	lsls r1, r2, #1
	adds r1, r1, r6
	lsls r0, r2, #9
	adds r0, r4, r0
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r3
	blo _08001E54
_08001E6C:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls _08001E38
	adds r2, r7, #0
	ldr r3, _08001EB4 @ =0x00000621
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	movs r3, #0
	strb r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08001E98
	strb r3, [r2]
_08001E98:
	strb r3, [r7, #0xc]
_08001E9A:
	ldr r1, _08001EB8 @ =0x04000208
	ldr r2, _08001EBC @ =gUnknown_02002822
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001EB0: .4byte gUnknown_0202C540
_08001EB4: .4byte 0x00000621
_08001EB8: .4byte 0x04000208
_08001EBC: .4byte gUnknown_02002822

	thumb_func_start sub_1EC0
sub_1EC0: @ 0x08001EC0
	push {r4, lr}
	ldr r4, _08001F00 @ =gUnknown_0202BF20
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08001EDC
	ldr r1, _08001F04 @ =gUnknown_02002826
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08001F42
	strb r0, [r4, #0xe]
_08001EDC:
	ldrb r3, [r4]
	cmp r3, #0
	beq _08001F16
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08001F10
	cmp r0, #4
	bne _08001F42
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	bhi _08001F08
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08001F10
	movs r0, #1
	strb r0, [r4, #0x15]
	b _08001F42
	.align 2, 0
_08001F00: .4byte gUnknown_0202BF20
_08001F04: .4byte gUnknown_02002826
_08001F08:
	ldrb r0, [r4, #0x15]
	cmp r0, #0
	bne _08001F42
	strb r0, [r4, #0xd]
_08001F10:
	bl sub_1FEC
	b _08001F42
_08001F16:
	ldrb r2, [r4, #1]
	cmp r2, #4
	beq _08001F20
	cmp r2, #2
	bne _08001F42
_08001F20:
	ldr r1, _08001F48 @ =gUnknown_02002824
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _08001F42
	cmp r2, #4
	bne _08001F38
	movs r0, #2
	strb r0, [r4, #0x15]
_08001F38:
	cmp r2, #2
	bne _08001F42
	strb r3, [r4, #2]
	strb r3, [r4, #3]
	strb r3, [r4, #0x11]
_08001F42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001F48: .4byte gUnknown_02002824

	thumb_func_start sub_1F4C
sub_1F4C: @ 0x08001F4C
	push {lr}
	bl sub_2308
	bl sub_1FEC
	pop {r0}
	bx r0

	thumb_func_start sub_1F5C
sub_1F5C: @ 0x08001F5C
	push {r4, lr}
	ldr r0, _08001F90 @ =0x04000128
	ldr r1, [r0]
	ldr r4, _08001F94 @ =gUnknown_0202BF20
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r4, #2]
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08001F98
	cmp r0, #4
	bne _08001FB6
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	beq _08001F80
	movs r0, #1
	strb r0, [r4, #0x12]
_08001F80:
	bl sub_20FC
	bl sub_223C
	bl sub_2338
	b _08001FB6
	.align 2, 0
_08001F90: .4byte 0x04000128
_08001F94: .4byte gUnknown_0202BF20
_08001F98:
	bl sub_1FFC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08001FB6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08001FB2
	movs r0, #3
	strb r0, [r4, #1]
	movs r0, #8
	strb r0, [r4, #0xd]
	b _08001FB6
_08001FB2:
	movs r0, #4
	strb r0, [r4, #1]
_08001FB6:
	ldr r3, _08001FDC @ =gUnknown_0202BF20
	ldrb r0, [r3, #0xd]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #0xd]
	ldr r1, _08001FE0 @ =gUnknown_02002824
	strb r2, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08001FD6
	ldr r0, _08001FE4 @ =gUnknown_0202A554
	ldr r2, _08001FE8 @ =0x00000621
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
_08001FD6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001FDC: .4byte gUnknown_0202BF20
_08001FE0: .4byte gUnknown_02002824
_08001FE4: .4byte gUnknown_0202A554
_08001FE8: .4byte 0x00000621

	thumb_func_start sub_1FEC
sub_1FEC: @ 0x08001FEC
	ldr r0, _08001FF8 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08001FF8: .4byte 0x04000128

	thumb_func_start sub_1FFC
sub_1FFC: @ 0x08001FFC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r5, _08002018 @ =0x0000FFFF
	ldr r0, _0800201C @ =gUnknown_0202BF20
	ldrb r1, [r0, #0x10]
	adds r4, r0, #0
	cmp r1, #1
	bne _0800202C
	ldr r1, _08002020 @ =0x0400012A
	ldr r2, _08002024 @ =0x00008FFF
	b _08002030
	.align 2, 0
_08002018: .4byte 0x0000FFFF
_0800201C: .4byte gUnknown_0202BF20
_08002020: .4byte 0x0400012A
_08002024: .4byte 0x00008FFF
_08002028:
	movs r7, #0
	b _080020B2
_0800202C:
	ldr r1, _08002080 @ =0x0400012A
	ldr r2, _08002084 @ =0x0000D13B
_08002030:
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
	strb r0, [r4, #0x10]
	ldr r0, _08002088 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #4]
	str r1, [r4, #8]
	movs r3, #0
	ldr r0, _0800208C @ =gUnknown_02002827
	mov sb, r0
	adds r6, r4, #0
	ldr r1, _08002090 @ =0x00008FFF
	mov r8, r1
	ldr r2, _08002094 @ =0x0000FFFF
	mov ip, r2
_08002052:
	lsls r0, r3, #1
	adds r1, r6, #4
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r2
	ldr r1, _08002098 @ =0x0000D138
	cmp r0, r1
	beq _0800206C
	adds r0, r2, #0
	cmp r0, r8
	bne _0800209C
_0800206C:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r2, #0
	cmp r5, r0
	bls _080020A8
	cmp r0, #0
	beq _080020A8
	adds r5, r2, #0
	b _080020A8
	.align 2, 0
_08002080: .4byte 0x0400012A
_08002084: .4byte 0x0000D13B
_08002088: .4byte 0x04000120
_0800208C: .4byte gUnknown_02002827
_08002090: .4byte 0x00008FFF
_08002094: .4byte 0x0000FFFF
_08002098: .4byte 0x0000D138
_0800209C:
	cmp r0, ip
	bne _08002028
	ldrb r0, [r6, #2]
	cmp r3, r0
	bne _080020A8
	movs r7, #0
_080020A8:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08002052
_080020B2:
	strb r7, [r4, #3]
	adds r0, r7, #0
	cmp r0, #2
	bne _080020E2
	mov r1, sb
	ldrb r1, [r1]
	cmp r0, r1
	bne _080020D4
	ldrh r1, [r4, #4]
	ldr r0, _080020D0 @ =0x00008FFF
	cmp r1, r0
	bne _080020D4
	movs r0, #1
	b _080020EE
	.align 2, 0
_080020D0: .4byte 0x00008FFF
_080020D4:
	ldrb r0, [r4, #3]
	cmp r0, #2
	bne _080020E2
	movs r0, #3
	ands r5, r0
	adds r0, r5, #1
	b _080020E4
_080020E2:
	movs r0, #0
_080020E4:
	strb r0, [r4, #0x11]
	ldrb r0, [r4, #3]
	mov r2, sb
	strb r0, [r2]
	movs r0, #0
_080020EE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_20FC
sub_20FC: @ 0x080020FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08002158 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0800215C @ =gUnknown_0202BF20
	ldrb r1, [r0, #0x18]
	adds r6, r0, #0
	cmp r1, #0
	bne _08002164
	movs r3, #0
	ldr r7, _08002160 @ =gUnknown_02002820
	ldrb r0, [r6, #3]
	cmp r3, r0
	bhs _0800214C
	adds r5, r6, #0
	ldrh r1, [r6, #0x16]
	adds r4, r7, #0
	adds r2, r6, #0
_0800212C:
	lsls r0, r3, #1
	add r0, sp
	ldrh r0, [r0]
	cmp r1, r0
	beq _08002140
	ldrb r0, [r4]
	cmp r0, #0
	beq _08002140
	movs r0, #1
	strb r0, [r5, #0x13]
_08002140:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r0, [r2, #3]
	cmp r3, r0
	blo _0800212C
_0800214C:
	movs r0, #0
	strh r0, [r6, #0x16]
	movs r0, #1
	strb r0, [r7]
	b _08002224
	.align 2, 0
_08002158: .4byte 0x04000120
_0800215C: .4byte gUnknown_0202BF20
_08002160: .4byte gUnknown_02002820
_08002164:
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r2, #1
	adds r0, r6, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08002182
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08002182:
	cmp r2, #0x1f
	bhi _080021F8
	movs r3, #0
	ldrb r1, [r6, #3]
	cmp r3, r1
	bhs _08002200
	adds r5, r6, #0
	ldr r7, _080021F0 @ =gUnknown_0200282A
	lsls r0, r0, #1
	mov ip, r0
	movs r2, #0x88
	lsls r2, r2, #2
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _080021F4 @ =gUnknown_02002826
	mov r8, r0
_080021A2:
	lsls r0, r3, #1
	mov r1, sp
	adds r4, r1, r0
	ldrh r2, [r4]
	ldrh r1, [r5, #0x16]
	adds r0, r2, r1
	strh r0, [r5, #0x16]
	ldrh r0, [r7]
	orrs r0, r2
	strh r0, [r7]
	ldrb r0, [r5, #0x19]
	lsls r0, r0, #6
	add r0, ip
	lsls r1, r3, #9
	adds r0, r0, r1
	add r0, sb
	strh r2, [r0]
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _080021E2
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _080021E2
	ldrh r0, [r4]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #1
	bne _080021E2
	strb r1, [r5, #0xe]
	movs r0, #5
	mov r2, r8
	strb r0, [r2]
_080021E2:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r0, [r5, #3]
	cmp r3, r0
	blo _080021A2
	b _08002200
	.align 2, 0
_080021F0: .4byte gUnknown_0200282A
_080021F4: .4byte gUnknown_02002826
_080021F8:
	ldrb r1, [r6, #0x14]
	movs r0, #2
	orrs r0, r1
	strb r0, [r6, #0x14]
_08002200:
	ldrb r0, [r6, #0x19]
	adds r0, #1
	strb r0, [r6, #0x19]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08002224
	ldr r2, _08002234 @ =gUnknown_0200282A
	ldrh r0, [r2]
	cmp r0, #0
	beq _08002224
	ldr r1, _08002238 @ =0x00000621
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_08002224:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002234: .4byte gUnknown_0200282A
_08002238: .4byte 0x00000621

	thumb_func_start sub_223C
sub_223C: @ 0x0800223C
	ldr r0, _08002278 @ =gUnknown_0202BF20
	ldrb r2, [r0, #0x18]
	adds r3, r0, #0
	cmp r2, #8
	bne _0800228E
	ldr r1, _0800227C @ =0x0400012A
	ldrh r0, [r3, #0x16]
	strh r0, [r1]
	ldr r1, _08002280 @ =gUnknown_02002825
	ldrb r2, [r1]
	cmp r2, #0
	bne _08002288
	ldr r0, _08002284 @ =0x0000021D
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080022FE
	strb r2, [r1]
	b _080022FE
	.align 2, 0
_08002278: .4byte gUnknown_0202BF20
_0800227C: .4byte 0x0400012A
_08002280: .4byte gUnknown_02002825
_08002284: .4byte 0x0000021D
_08002288:
	movs r0, #0
	strb r0, [r1]
	b _080022FE
_0800228E:
	ldr r1, _080022B0 @ =gUnknown_02002825
	cmp r2, #0
	bne _080022A2
	ldr r2, _080022B4 @ =0x0000021D
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080022A2
	movs r0, #1
	strb r0, [r1]
_080022A2:
	ldrb r0, [r1]
	cmp r0, #0
	beq _080022BC
	ldr r1, _080022B8 @ =0x0400012A
	movs r0, #0
	strh r0, [r1]
	b _080022D8
	.align 2, 0
_080022B0: .4byte gUnknown_02002825
_080022B4: .4byte 0x0000021D
_080022B8: .4byte 0x0400012A
_080022BC:
	ldr r2, _08002300 @ =0x0400012A
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r3, #0x18]
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x1c
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
_080022D8:
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080022F8
	ldrb r0, [r3, #0x18]
	cmp r0, #0
	bne _080022F8
	ldr r2, _08002304 @ =0x00000621
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #3
	bls _080022F8
	ldr r0, _08002300 @ =0x0400012A
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
_080022F8:
	ldrb r0, [r3, #0x18]
	adds r0, #1
	strb r0, [r3, #0x18]
_080022FE:
	bx lr
	.align 2, 0
_08002300: .4byte 0x0400012A
_08002304: .4byte 0x00000621

	thumb_func_start sub_2308
sub_2308: @ 0x08002308
	ldr r0, _08002324 @ =gUnknown_0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08002322
	ldr r2, _08002328 @ =0x0400010E
	ldrh r1, [r2]
	ldr r0, _0800232C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08002330 @ =0x0400010C
	ldr r2, _08002334 @ =0x0000FF3B
	adds r0, r2, #0
	strh r0, [r1]
_08002322:
	bx lr
	.align 2, 0
_08002324: .4byte gUnknown_0202BF20
_08002328: .4byte 0x0400010E
_0800232C: .4byte 0x0000FF7F
_08002330: .4byte 0x0400010C
_08002334: .4byte 0x0000FF3B

	thumb_func_start sub_2338
sub_2338: @ 0x08002338
	ldr r1, _08002348 @ =gUnknown_0202BF20
	ldrb r0, [r1, #0x19]
	cmp r0, #8
	bne _0800234C
	movs r0, #0
	strb r0, [r1, #0x18]
	strb r0, [r1, #0x19]
	b _0800235C
	.align 2, 0
_08002348: .4byte gUnknown_0202BF20
_0800234C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800235C
	ldr r0, _08002360 @ =0x0400010E
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
_0800235C:
	bx lr
	.align 2, 0
_08002360: .4byte 0x0400010E

	thumb_func_start sub_2364
sub_2364: @ 0x08002364
	push {r4, r5, lr}
	ldr r1, _080023A8 @ =gUnknown_0202BF20
	ldr r2, _080023AC @ =0x0000021D
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	movs r3, #0x87
	lsls r3, r3, #2
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #0
	adds r5, r1, #0
	adds r5, #0x1c
	ldr r4, _080023B0 @ =0x0000EFFF
_08002380:
	movs r2, #0
	adds r1, r0, #1
	lsls r3, r0, #6
_08002386:
	lsls r0, r2, #1
	adds r0, r0, r3
	adds r0, r0, r5
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1f
	bls _08002386
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08002380
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080023A8: .4byte gUnknown_0202BF20
_080023AC: .4byte 0x0000021D
_080023B0: .4byte 0x0000EFFF

	thumb_func_start sub_23B4
sub_23B4: @ 0x080023B4
	push {r4, r5, r6, r7, lr}
	ldr r1, _08002408 @ =gUnknown_0202BF20
	ldr r2, _0800240C @ =0x00000621
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	adds r7, r1, r0
	ldr r6, _08002410 @ =0x0000EFFF
_080023D0:
	movs r0, #0
	adds r5, r2, #1
	lsls r4, r2, #9
_080023D6:
	movs r2, #0
	adds r1, r0, #1
	lsls r3, r0, #6
_080023DC:
	lsls r0, r2, #1
	adds r0, r0, r3
	adds r0, r0, r4
	adds r0, r0, r7
	strh r6, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1f
	bls _080023DC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080023D6
	lsls r0, r5, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls _080023D0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002408: .4byte gUnknown_0202BF20
_0800240C: .4byte 0x00000621
_08002410: .4byte 0x0000EFFF

	thumb_func_start sub_2414
sub_2414: @ 0x08002414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	str r2, [sp, #8]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	ldr r4, _080024CC @ =gOamBuffer
	movs r7, #0
	ldr r0, _080024D0 @ =gEmptyOamData
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, #0
	bl CpuSet
	movs r1, #0
	ldr r0, [sp, #4]
	cmp r7, r0
	bhs _080024B8
_08002442:
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, [sp, #8]
	adds r6, r2, r0
	ldrh r0, [r6]
	adds r2, r1, #1
	mov sl, r2
	cmp r0, #0
	beq _080024AC
	lsls r0, r1, #2
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r5, [r0]
	adds r0, #2
	lsls r1, r7, #3
	ldr r4, _080024CC @ =gOamBuffer
	adds r1, r1, r4
	lsls r2, r5, #2
	bl CpuSet
	movs r3, #0
	cmp r3, r5
	bhs _080024AC
	mov r8, r4
	ldr r2, _080024D4 @ =0x000001FF
	mov sb, r2
	movs r0, #0xff
	mov ip, r0
_0800247C:
	adds r2, r7, #0
	lsls r0, r2, #3
	mov r1, r8
	adds r4, r0, r1
	lsls r1, r3, #3
	adds r1, #8
	adds r1, r6, r1
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	strh r2, [r1]
	ldrh r2, [r4, #2]
	mov r0, sb
	ands r0, r2
	strh r0, [r1, #2]
	ldrh r2, [r4]
	mov r0, ip
	ands r0, r2
	strh r0, [r1, #4]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r5
	blo _0800247C
_080024AC:
	mov r2, sl
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	ldr r0, [sp, #4]
	cmp r1, r0
	blo _08002442
_080024B8:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080024CC: .4byte gOamBuffer
_080024D0: .4byte gEmptyOamData
_080024D4: .4byte 0x000001FF

	thumb_func_start nullsub_16
nullsub_16: @ 0x080024D8
	bx lr

	thumb_func_start sub_24DC
sub_24DC: @ 0x080024DC
	ldr r1, _08002504 @ =0x04000134
	movs r0, #0
	strh r0, [r1]
	subs r1, #0xc
	strh r0, [r1]
	ldr r2, _08002508 @ =0x0400012A
	strh r0, [r2]
	subs r1, #8
	strh r0, [r1]
	strh r0, [r2]
	strh r0, [r1]
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08002504: .4byte 0x04000134
_08002508: .4byte 0x0400012A

	thumb_func_start sub_250C
sub_250C: @ 0x0800250C
	ldr r2, _08002528 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	ldr r1, _0800252C @ =0x04000200
	ldr r3, _08002530 @ =0x00002001
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, _08002534 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08002528: .4byte 0x04000208
_0800252C: .4byte 0x04000200
_08002530: .4byte 0x00002001
_08002534: .4byte 0x04000004

	thumb_func_start sub_2538
sub_2538: @ 0x08002538
	ldr r0, _08002554 @ =gUnknown_0202ADD0
	movs r1, #0
	str r1, [r0]
	ldr r0, _08002558 @ =gUnknown_0201A444
	movs r2, #0
	strh r1, [r0]
	ldr r0, _0800255C @ =gUnknown_0202BDF0
	str r1, [r0]
	ldr r0, _08002560 @ =gUnknown_0201C1AC
	strb r2, [r0]
	ldr r0, _08002564 @ =gUnknown_0202ADDC
	strb r2, [r0]
	bx lr
	.align 2, 0
_08002554: .4byte gUnknown_0202ADD0
_08002558: .4byte gUnknown_0201A444
_0800255C: .4byte gUnknown_0202BDF0
_08002560: .4byte gUnknown_0201C1AC
_08002564: .4byte gUnknown_0202ADDC

	thumb_func_start sub_2568
sub_2568: @ 0x08002568
	push {r4, lr}
	bl sub_24DC
	ldr r4, _08002594 @ =0x04000208
	movs r0, #0
	strh r0, [r4]
	bl ResetMainCallback
	bl ResetVBlankIntrFunc
	ldr r1, _08002598 @ =0x04000200
	ldr r2, _0800259C @ =0x00002005
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080025A0 @ =0x04000004
	movs r0, #0x28
	strh r0, [r1]
	movs r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002594: .4byte 0x04000208
_08002598: .4byte 0x04000200
_0800259C: .4byte 0x00002005
_080025A0: .4byte 0x04000004
