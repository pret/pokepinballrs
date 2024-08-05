	.include "asm/macros.inc"

	.syntax unified

	.text

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
