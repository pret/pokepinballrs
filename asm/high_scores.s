	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start HighScoresMain
HighScoresMain: @ 0x0800CE48
	push {lr}
	ldr r1, _0800CE60 @ =gUnknown_080793E8
	ldr r0, _0800CE64 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800CE60: .4byte gUnknown_080793E8
_0800CE64: .4byte gMain

@ This is triggered after the idle pinball game catches its first pokemon
	thumb_func_start IdleHighScoresMain
IdleHighScoresMain: @ 0x0800CE68
	push {lr}
	ldr r1, _0800CE80 @ =gUnknown_08079424
	ldr r0, _0800CE84 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800CE80: .4byte gUnknown_08079424
_0800CE84: .4byte gMain

	thumb_func_start sub_CE88
sub_CE88: @ 0x0800CE88
	push {r4, r5, r6, r7, lr}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800CF68 @ =0x0400000C
	ldr r3, _0800CF6C @ =0x00004006
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800CF70 @ =0x0400000E
	ldr r3, _0800CF74 @ =0x0000420F
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r7, _0800CF78 @ =gMain
	ldrh r0, [r2]
	strh r0, [r7, #0x16]
	ldr r4, _0800CF7C @ =0x040000D4
	ldr r0, _0800CF80 @ =gUnknown_0809DBE0
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0800CF84 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CF88 @ =gUnknown_080957A0
	str r0, [r4]
	ldr r0, _0800CF8C @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _0800CF90 @ =0x80002400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CF94 @ =gUnknown_0809AFC0
	str r0, [r4]
	ldr r0, _0800CF98 @ =0x0600C000
	str r0, [r4, #4]
	ldr r0, _0800CF9C @ =0x80001600
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CFA0 @ =gUnknown_080947A0
	str r0, [r4]
	ldr r6, _0800CFA4 @ =gUnknown_03005C00
	str r6, [r4, #4]
	ldr r5, _0800CFA8 @ =0x80000800
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CFAC @ =gUnknown_08099FC0
	str r0, [r4]
	ldr r0, _0800CFB0 @ =0x06001000
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CFB4 @ =gUnknown_0809DDE0
	str r0, [r4]
	ldr r0, _0800CFB8 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0800CFBC @ =0x80000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800CFC0 @ =gUnknown_0809DFE0
	str r0, [r4]
	ldr r0, _0800CFC4 @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _0800CFC8 @ =0x80002210
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_CFD4
	bl sub_EE64
	str r6, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r4, _0800CFCC @ =gUnknown_0202C588
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0800CF50
	movs r0, #9
	bl m4aSongNumStart
_0800CF50:
	movs r0, #0
	strh r0, [r4]
	bl sub_CBC
	bl sub_24C
	ldr r0, _0800CFD0 @ =gUnknown_02002858
	ldrb r0, [r0, #0xa]
	strb r0, [r7, #3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800CF68: .4byte 0x0400000C
_0800CF6C: .4byte 0x00004006
_0800CF70: .4byte 0x0400000E
_0800CF74: .4byte 0x0000420F
_0800CF78: .4byte gMain
_0800CF7C: .4byte 0x040000D4
_0800CF80: .4byte gUnknown_0809DBE0
_0800CF84: .4byte 0x80000100
_0800CF88: .4byte gUnknown_080957A0
_0800CF8C: .4byte 0x06004000
_0800CF90: .4byte 0x80002400
_0800CF94: .4byte gUnknown_0809AFC0
_0800CF98: .4byte 0x0600C000
_0800CF9C: .4byte 0x80001600
_0800CFA0: .4byte gUnknown_080947A0
_0800CFA4: .4byte gUnknown_03005C00
_0800CFA8: .4byte 0x80000800
_0800CFAC: .4byte gUnknown_08099FC0
_0800CFB0: .4byte 0x06001000
_0800CFB4: .4byte gUnknown_0809DDE0
_0800CFB8: .4byte 0x05000200
_0800CFBC: .4byte 0x80000080
_0800CFC0: .4byte gUnknown_0809DFE0
_0800CFC4: .4byte 0x06010000
_0800CFC8: .4byte 0x80002210
_0800CFCC: .4byte gUnknown_0202C588
_0800CFD0: .4byte gUnknown_02002858

	thumb_func_start sub_CFD4
sub_CFD4: @ 0x0800CFD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r7, #0
	ldr r0, _0800D0B0 @ =gUnknown_02002858
	mov r8, r0
	ldr r1, _0800D0B4 @ =gUnknown_0202C610
	mov sl, r1
	ldr r2, _0800D0B8 @ =gMain+0x74
	mov sb, r2
	movs r3, #0
	mov ip, r3
_0800CFF0:
	movs r3, #0
	mov r4, ip
	movs r6, #0
_0800CFF6:
	adds r0, r4, #0
	adds r0, #0xe4
	adds r0, r6, r0
	mov r1, sb
	adds r5, r0, r1
	adds r0, r6, r4
	mov r1, sl
	adds r2, r0, r1
	movs r1, #5
_0800D008:
	ldm r5!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800D008
	adds r6, #0x18
	adds r3, #1
	cmp r3, #7
	ble _0800CFF6
	movs r2, #0xc0
	add ip, r2
	adds r7, #1
	cmp r7, #1
	ble _0800CFF0
	movs r7, #0
	ldr r6, _0800D0BC @ =gUnknown_0202C550
	ldr r5, _0800D0B4 @ =gUnknown_0202C610
_0800D02A:
	lsls r0, r7, #1
	adds r4, r7, #1
	adds r0, r0, r7
	lsls r1, r0, #3
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r1, r1, r6
	movs r3, #5
_0800D03A:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r3, #1
	cmp r3, #0
	bge _0800D03A
	adds r7, r4, #0
	cmp r7, #1
	ble _0800D02A
	movs r3, #0
	movs r2, #0
	mov r4, r8
	strh r2, [r4, #0x10]
	strh r2, [r4, #0x12]
	strh r2, [r4, #0x14]
	strh r2, [r4, #0x18]
	strh r2, [r4, #0x1a]
	strh r2, [r4, #0x1e]
	strh r2, [r4, #0x1c]
	strh r2, [r4, #0x20]
	strh r2, [r4, #0x22]
	mov r0, r8
	adds r0, #0x25
	strb r3, [r0]
	mov r1, r8
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0800D0C0 @ =gUnknown_0201B178
	strb r3, [r1]
	ldr r4, _0800D0C4 @ =gUnknown_0202BEBC
	strb r0, [r4]
	ldr r0, _0800D0C8 @ =gUnknown_0201C18C
	strb r3, [r0]
	ldr r1, _0800D0CC @ =gUnknown_02002884
	strb r3, [r1]
	ldr r4, _0800D0D0 @ =gUnknown_02002885
	strb r3, [r4]
	ldr r1, _0800D0D4 @ =gUnknown_0202C588
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #1
	beq _0800D090
	b _0800D1C0
_0800D090:
	ldr r0, _0800D0D8 @ =gMain
	ldr r1, [r0, #0x5c]
	mov r4, r8
	str r1, [r4]
	ldr r1, [r0, #0x58]
	str r1, [r4, #4]
	ldrb r1, [r0, #4]
	cmp r1, #1
	bne _0800D0E4
	strb r1, [r4, #0xb]
	movs r0, #0xf0
	ldr r2, _0800D0DC @ =gUnknown_02002882
	strh r0, [r2]
	ldr r3, _0800D0E0 @ =gUnknown_02002880
	strh r1, [r3]
	b _0800D0F6
	.align 2, 0
_0800D0B0: .4byte gUnknown_02002858
_0800D0B4: .4byte gUnknown_0202C610
_0800D0B8: .4byte gMain+0x74
_0800D0BC: .4byte gUnknown_0202C550
_0800D0C0: .4byte gUnknown_0201B178
_0800D0C4: .4byte gUnknown_0202BEBC
_0800D0C8: .4byte gUnknown_0201C18C
_0800D0CC: .4byte gUnknown_02002884
_0800D0D0: .4byte gUnknown_02002885
_0800D0D4: .4byte gUnknown_0202C588
_0800D0D8: .4byte gMain
_0800D0DC: .4byte gUnknown_02002882
_0800D0E0: .4byte gUnknown_02002880
_0800D0E4:
	mov r4, r8
	strb r3, [r4, #0xb]
	ldr r0, _0800D178 @ =gUnknown_02002882
	strh r2, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldr r2, _0800D17C @ =gUnknown_02002880
	strh r0, [r2]
_0800D0F6:
	ldr r4, _0800D180 @ =gUnknown_02002858
	ldr r0, [r4]
	ldr r1, [r4, #4]
	ldrb r2, [r4, #0xb]
	bl sub_F3DC
	adds r3, r0, #0
	str r3, [r4, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	beq _0800D14A
	ldr r0, [r4]
	ldr r1, [r4, #4]
	ldrb r2, [r4, #0xb]
	bl sub_F434
	movs r7, #0
	ldr r5, _0800D184 @ =gUnknown_0202C610
	adds r3, r4, #0
	ldr r6, _0800D188 @ =gUnknown_0201A500
	adds r4, r6, #0
_0800D122:
	lsls r2, r7, #2
	ldr r1, [r3, #0xc]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r1, [r3, #0xb]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r2, r5
	ldm r4!, {r0}
	str r0, [r2]
	adds r7, #1
	cmp r7, #3
	ble _0800D122
	ldr r1, _0800D180 @ =gUnknown_02002858
	ldr r0, [r6]
	strh r0, [r1, #0x16]
_0800D14A:
	bl sub_FD20
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	cmp r3, #1
	bne _0800D1A8
	ldr r0, _0800D18C @ =gUnknown_0202BEB0
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	bne _0800D1A0
	ldr r0, _0800D190 @ =gUnknown_0201C18C
	strb r3, [r0]
	ldr r1, _0800D194 @ =gUnknown_0201A4B8
	movs r0, #0xb8
	strh r0, [r1]
	ldr r0, _0800D198 @ =gUnknown_0202C580
	strb r2, [r0]
	ldr r0, _0800D19C @ =gUnknown_0202BED4
	strb r2, [r0]
	ldr r0, _0800D180 @ =gUnknown_02002858
	strb r3, [r0, #0xa]
	b _0800D1DA
	.align 2, 0
_0800D178: .4byte gUnknown_02002882
_0800D17C: .4byte gUnknown_02002880
_0800D180: .4byte gUnknown_02002858
_0800D184: .4byte gUnknown_0202C610
_0800D188: .4byte gUnknown_0201A500
_0800D18C: .4byte gUnknown_0202BEB0
_0800D190: .4byte gUnknown_0201C18C
_0800D194: .4byte gUnknown_0201A4B8
_0800D198: .4byte gUnknown_0202C580
_0800D19C: .4byte gUnknown_0202BED4
_0800D1A0:
	ldr r1, _0800D1A4 @ =gUnknown_0201C18C
	b _0800D1AA
	.align 2, 0
_0800D1A4: .4byte gUnknown_0201C18C
_0800D1A8:
	ldr r1, _0800D1B8 @ =gUnknown_0202BEB0
_0800D1AA:
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0800D1BC @ =gUnknown_02002858
	movs r0, #2
	strb r0, [r1, #0xa]
	b _0800D1DA
	.align 2, 0
_0800D1B8: .4byte gUnknown_0202BEB0
_0800D1BC: .4byte gUnknown_02002858
_0800D1C0:
	mov r4, r8
	strb r3, [r4, #0xb]
	ldr r0, _0800D200 @ =gUnknown_02002882
	strh r2, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldr r2, _0800D204 @ =gUnknown_02002880
	strh r0, [r2]
	bl sub_E464
	movs r0, #3
	strb r0, [r4, #0xa]
_0800D1DA:
	ldr r2, _0800D208 @ =gMain
	ldr r0, _0800D200 @ =gUnknown_02002882
	ldrh r1, [r0]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D200: .4byte gUnknown_02002882
_0800D204: .4byte gUnknown_02002880
_0800D208: .4byte gMain

	thumb_func_start sub_D20C
sub_D20C: @ 0x0800D20C
	push {r4, r5, lr}
	ldr r4, _0800D224 @ =gUnknown_0202BED4
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r5, r4, #0
	cmp r0, #1
	beq _0800D248
	cmp r0, #1
	bgt _0800D228
	cmp r0, #0
	beq _0800D232
	b _0800D2E0
	.align 2, 0
_0800D224: .4byte gUnknown_0202BED4
_0800D228:
	cmp r0, #2
	beq _0800D290
	cmp r0, #3
	beq _0800D2B4
	b _0800D2E0
_0800D232:
	ldr r0, _0800D244 @ =gUnknown_02002858
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bne _0800D2E0
	movs r0, #0x11
	bl m4aSongNumStart
	b _0800D2A2
	.align 2, 0
_0800D244: .4byte gUnknown_02002858
_0800D248:
	ldr r1, _0800D284 @ =gUnknown_0201A4B8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r0, _0800D288 @ =gUnknown_02002858
	ldrh r2, [r0, #0x18]
	movs r0, #3
	ands r2, r0
	cmp r2, #0
	bne _0800D26E
	ldr r3, _0800D28C @ =gUnknown_0202C580
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _0800D26E
	strb r2, [r3]
_0800D26E:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x50
	bne _0800D2E0
	ldr r1, _0800D28C @ =gUnknown_0202C580
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0800D2E0
	.align 2, 0
_0800D284: .4byte gUnknown_0201A4B8
_0800D288: .4byte gUnknown_02002858
_0800D28C: .4byte gUnknown_0202C580
_0800D290:
	ldr r0, _0800D2AC @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800D2E0
	ldr r1, _0800D2B0 @ =gUnknown_0202C580
	movs r0, #0
	strb r0, [r1]
_0800D2A2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0800D2E0
	.align 2, 0
_0800D2AC: .4byte gMain
_0800D2B0: .4byte gUnknown_0202C580
_0800D2B4:
	ldr r0, _0800D2F4 @ =gUnknown_0201A4B8
	ldrh r1, [r0]
	subs r1, #4
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0x18
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800D2E0
	ldr r1, _0800D2F8 @ =gUnknown_02002858
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	ldr r1, _0800D2FC @ =gUnknown_0202BEB0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0800D300 @ =gUnknown_0201C18C
	strb r2, [r0]
	ldr r1, _0800D304 @ =gMain
	movs r0, #2
	strb r0, [r1, #3]
_0800D2E0:
	ldr r1, _0800D2F8 @ =gUnknown_02002858
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	bl sub_E860
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D2F4: .4byte gUnknown_0201A4B8
_0800D2F8: .4byte gUnknown_02002858
_0800D2FC: .4byte gUnknown_0202BEB0
_0800D300: .4byte gUnknown_0201C18C
_0800D304: .4byte gMain

	thumb_func_start sub_D308
sub_D308: @ 0x0800D308
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r4, _0800D32C @ =gUnknown_02002858
	movs r0, #0x1a
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _0800D35E
	ldr r1, [r4, #0xc]
	cmp r1, #0
	bne _0800D330
	movs r0, #0xa5
	lsls r0, r0, #1
	bl m4aSongNumStart
	movs r0, #0xa0
	b _0800D35C
	.align 2, 0
_0800D32C: .4byte gUnknown_02002858
_0800D330:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0800D354
	ldr r0, _0800D34C @ =0x000003E7
	strh r0, [r4, #0x18]
	strh r2, [r4, #0x1a]
	movs r0, #9
	bl m4aSongNumStart
	ldr r1, _0800D350 @ =gMain
	movs r0, #3
	strb r0, [r1, #3]
	b _0800D35E
	.align 2, 0
_0800D34C: .4byte 0x000003E7
_0800D350: .4byte gMain
_0800D354:
	ldr r0, _0800D3C8 @ =0x0000014B
	bl m4aSongNumStart
	movs r0, #0x5a
_0800D35C:
	strh r0, [r4, #0x18]
_0800D35E:
	ldr r7, _0800D3CC @ =gUnknown_02002858
	ldrh r0, [r7, #0x14]
	adds r0, #1
	movs r1, #0
	strh r0, [r7, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800D3FC
	strh r1, [r7, #0x14]
	movs r2, #0x12
	ldrsh r0, [r7, r2]
	cmp r0, #0
	bne _0800D3D4
	movs r0, #1
	strh r0, [r7, #0x12]
	ldrb r2, [r7, #0xb]
	lsls r0, r2, #1
	movs r4, #6
	subs r0, r4, r0
	ldr r3, _0800D3D0 @ =gUnknown_08079870
	mov r8, r3
	ldr r1, [r7, #0xc]
	lsls r1, r1, #2
	add r1, r8
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	movs r6, #4
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r2, #0
	movs r3, #0x15
	bl sub_10618
	ldrb r1, [r7, #0xb]
	lsls r0, r1, #1
	subs r4, r4, r0
	ldr r0, [r7, #0xc]
	lsls r0, r0, #2
	add r0, r8
	lsls r1, r1, #5
	ldr r3, [r0]
	adds r3, r3, r1
	str r6, [sp]
	str r5, [sp, #4]
	movs r0, #0
	movs r1, #0x17
	adds r2, r4, #0
	bl sub_10618
	b _0800D3FC
	.align 2, 0
_0800D3C8: .4byte 0x0000014B
_0800D3CC: .4byte gUnknown_02002858
_0800D3D0: .4byte gUnknown_08079870
_0800D3D4:
	strh r1, [r7, #0x12]
	ldrb r1, [r7, #0xb]
	lsls r0, r1, #1
	movs r2, #6
	subs r2, r2, r0
	ldr r3, _0800D4A0 @ =gUnknown_08079870
	ldr r0, [r7, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r1, r1, #5
	ldr r3, [r0]
	adds r3, r3, r1
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x15
	bl sub_10618
_0800D3FC:
	ldr r4, _0800D4A4 @ =gUnknown_02002858
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800D42C
	strh r5, [r4, #0x1e]
	ldrb r0, [r4, #0xb]
	ldr r1, [r4, #0xc]
	movs r3, #0x1c
	ldrsh r2, [r4, r3]
	bl sub_F8B0
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800D42C
	strh r5, [r4, #0x1c]
_0800D42C:
	ldr r4, _0800D4A4 @ =gUnknown_02002858
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	movs r2, #0
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x18
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _0800D482
	strh r2, [r4, #0x1a]
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	cmp r0, #1
	bne _0800D476
	strh r2, [r4, #0x12]
	strh r2, [r4, #0x14]
	ldrb r1, [r4, #0xb]
	lsls r0, r1, #1
	movs r2, #6
	subs r2, r2, r0
	ldr r3, _0800D4A0 @ =gUnknown_08079870
	ldr r0, [r4, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r3
	lsls r1, r1, #5
	ldr r3, [r0]
	adds r3, r3, r1
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x15
	bl sub_10618
_0800D476:
	movs r0, #9
	bl m4aSongNumStart
	ldr r1, _0800D4A8 @ =gMain
	movs r0, #4
	strb r0, [r1, #3]
_0800D482:
	ldr r1, _0800D4AC @ =0x040000D4
	ldr r0, _0800D4B0 @ =gUnknown_03005C00
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800D4B4 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D4A0: .4byte gUnknown_08079870
_0800D4A4: .4byte gUnknown_02002858
_0800D4A8: .4byte gMain
_0800D4AC: .4byte 0x040000D4
_0800D4B0: .4byte gUnknown_03005C00
_0800D4B4: .4byte 0x80000800

	thumb_func_start sub_D4B8
sub_D4B8: @ 0x0800D4B8
	push {r4, lr}
	bl sub_E464
	ldr r4, _0800D500 @ =gMain
	ldr r0, [r4, #0x4c]
	movs r1, #0xc
	bl __umodsi3
	cmp r0, #0
	bne _0800D4E0
	ldr r1, _0800D504 @ =gUnknown_02002858
	ldrh r2, [r1, #0x1a]
	movs r0, #1
	subs r0, r0, r2
	strh r0, [r1, #0x1a]
	adds r1, #0x25
	ldrb r2, [r1]
	movs r0, #1
	subs r0, r0, r2
	strb r0, [r1]
_0800D4E0:
	ldrh r1, [r4, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D50C
	ldr r0, _0800D508 @ =gUnknown_02002880
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #1
	rsbs r2, r2, #0
	adds r3, r0, #0
	cmp r1, r2
	beq _0800D522
	strh r2, [r3]
	b _0800D522
	.align 2, 0
_0800D500: .4byte gMain
_0800D504: .4byte gUnknown_02002858
_0800D508: .4byte gUnknown_02002880
_0800D50C:
	movs r0, #0x10
	ands r0, r1
	ldr r3, _0800D53C @ =gUnknown_02002880
	cmp r0, #0
	beq _0800D522
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #1
	beq _0800D522
	movs r0, #1
	strh r0, [r3]
_0800D522:
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _0800D544
	ldr r1, _0800D540 @ =gUnknown_02002882
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xef
	bgt _0800D55A
	adds r0, r2, #0
	adds r0, #8
	b _0800D558
	.align 2, 0
_0800D53C: .4byte gUnknown_02002880
_0800D540: .4byte gUnknown_02002882
_0800D544:
	cmp r0, #0
	bge _0800D55A
	ldr r1, _0800D608 @ =gUnknown_02002882
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0800D55A
	adds r0, r2, #0
	subs r0, #8
_0800D558:
	strh r0, [r1]
_0800D55A:
	ldr r4, _0800D60C @ =gMain
	ldrh r1, [r4, #0x18]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800D570
	movs r0, #0x66
	bl m4aSongNumStart
	movs r0, #0xb
	strb r0, [r4, #3]
_0800D570:
	ldrh r1, [r4, #0x18]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D59E
	ldr r0, _0800D608 @ =gUnknown_02002882
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0800D588
	cmp r0, #0xf0
	bne _0800D59E
_0800D588:
	movs r0, #0x68
	bl m4aSongNumStart
	ldr r1, _0800D610 @ =gUnknown_0201B178
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0800D614 @ =gUnknown_0202BEBC
	movs r0, #0
	strb r0, [r1]
	movs r0, #5
	strb r0, [r4, #3]
_0800D59E:
	ldr r3, _0800D60C @ =gMain
	ldrh r2, [r3, #0x1c]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r1, #0
	ands r0, r2
	adds r4, r3, #0
	cmp r0, r1
	bne _0800D620
	ldrh r1, [r4, #0x18]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800D63E
	ldr r0, _0800D608 @ =gUnknown_02002882
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0800D5CA
	cmp r0, #0xf0
	bne _0800D5FC
_0800D5CA:
	ldr r2, _0800D618 @ =gUnknown_02002884
	movs r0, #0x28
	strb r0, [r2]
	ldr r1, _0800D61C @ =gUnknown_02002885
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0800D5FC
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
	movs r0, #0x68
	bl m4aSongNumStart
	ldr r1, _0800D610 @ =gUnknown_0201B178
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0800D614 @ =gUnknown_0202BEBC
	movs r0, #4
	strb r0, [r1]
	movs r0, #0xa
	strb r0, [r4, #3]
_0800D5FC:
	ldr r2, _0800D618 @ =gUnknown_02002884
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r4, _0800D60C @ =gMain
	b _0800D628
	.align 2, 0
_0800D608: .4byte gUnknown_02002882
_0800D60C: .4byte gMain
_0800D610: .4byte gUnknown_0201B178
_0800D614: .4byte gUnknown_0202BEBC
_0800D618: .4byte gUnknown_02002884
_0800D61C: .4byte gUnknown_02002885
_0800D620:
	ldr r2, _0800D658 @ =gUnknown_02002884
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
_0800D628:
	cmp r0, #0
	ble _0800D63E
	subs r0, r1, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0800D63E
	movs r1, #0
	strb r1, [r2]
	ldr r0, _0800D65C @ =gUnknown_02002885
	strb r1, [r0]
_0800D63E:
	ldr r0, _0800D660 @ =gUnknown_02002882
	ldrh r1, [r0]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800D658: .4byte gUnknown_02002884
_0800D65C: .4byte gUnknown_02002885
_0800D660: .4byte gUnknown_02002882

	thumb_func_start sub_D664
sub_D664: @ 0x0800D664
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl sub_E3A8
	ldr r4, _0800D6E8 @ =gUnknown_02002858
	ldrh r0, [r4, #0x14]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _0800D68C
	strh r5, [r4, #0x14]
	ldrh r1, [r4, #0x12]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r4, #0x12]
_0800D68C:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800D6B8
	strh r5, [r4, #0x1e]
	ldrb r0, [r4, #0xb]
	ldr r1, [r4, #0xc]
	movs r3, #0x1c
	ldrsh r2, [r4, r3]
	bl sub_F8B0
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800D6B8
	strh r5, [r4, #0x1c]
_0800D6B8:
	ldr r0, _0800D6EC @ =gMain
	ldrh r1, [r0, #0x1c]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800D6F0
	ldr r4, _0800D6E8 @ =gUnknown_02002858
	movs r7, #0x20
	ldrsh r0, [r4, r7]
	cmp r0, #0
	bne _0800D72C
	movs r0, #0x6b
	bl m4aSongNumStart
	ldrh r0, [r4, #0x16]
	subs r0, #1
	strh r0, [r4, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800D718
	movs r0, #0x29
	strh r0, [r4, #0x16]
	b _0800D718
	.align 2, 0
_0800D6E8: .4byte gUnknown_02002858
_0800D6EC: .4byte gMain
_0800D6F0:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800D72C
	ldr r4, _0800D788 @ =gUnknown_02002858
	movs r7, #0x20
	ldrsh r5, [r4, r7]
	cmp r5, #0
	bne _0800D72C
	movs r0, #0x6b
	bl m4aSongNumStart
	ldrh r0, [r4, #0x16]
	adds r0, #1
	strh r0, [r4, #0x16]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x29
	ble _0800D718
	strh r5, [r4, #0x16]
_0800D718:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	ldr r1, [r4, #0xc]
	movs r3, #0x10
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xb]
	bl sub_F670
	movs r0, #9
	strh r0, [r4, #0x20]
_0800D72C:
	ldr r0, _0800D78C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D794
	ldr r4, _0800D788 @ =gUnknown_02002858
	movs r7, #0x10
	ldrsh r0, [r4, r7]
	cmp r0, #3
	beq _0800D7A6
	movs r0, #0x67
	bl m4aSongNumStart
	movs r0, #1
	strh r0, [r4, #0x12]
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	ldr r1, [r4, #0xc]
	movs r3, #0x10
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xb]
	bl sub_F670
	ldr r3, _0800D790 @ =gUnknown_0202C610
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	str r0, [r1]
	ldrh r0, [r4, #0x10]
	adds r0, #1
	b _0800D7F6
	.align 2, 0
_0800D788: .4byte gUnknown_02002858
_0800D78C: .4byte gMain
_0800D790: .4byte gUnknown_0202C610
_0800D794:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D818
	ldr r4, _0800D7B0 @ =gUnknown_02002858
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0800D7B4
_0800D7A6:
	movs r0, #0x8a
	bl m4aSongNumStart
	b _0800D818
	.align 2, 0
_0800D7B0: .4byte gUnknown_02002858
_0800D7B4:
	movs r0, #0x67
	bl m4aSongNumStart
	movs r0, #1
	strh r0, [r4, #0x12]
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	ldr r1, [r4, #0xc]
	movs r3, #0x10
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xb]
	bl sub_F670
	ldr r3, _0800D8F8 @ =gUnknown_0202C610
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	str r0, [r1]
	ldrh r0, [r4, #0x10]
	subs r0, #1
_0800D7F6:
	strh r0, [r4, #0x10]
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
	ldr r0, [r1]
	strh r0, [r4, #0x16]
_0800D818:
	ldr r0, _0800D8FC @ =gMain
	ldrh r1, [r0, #0x18]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0800D828
	b _0800D936
_0800D828:
	ldr r4, _0800D900 @ =gUnknown_02002858
	strh r5, [r4, #0x12]
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	ldr r1, [r4, #0xc]
	movs r3, #0x10
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xb]
	bl sub_F670
	ldr r5, _0800D8F8 @ =gUnknown_0202C610
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r5
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r3, #0x10
	ldrsh r0, [r4, r3]
	cmp r0, #3
	bne _0800D90C
	movs r0, #0x65
	bl m4aSongNumStart
	ldrb r0, [r4, #0xb]
	ldr r1, [r4, #0xc]
	movs r7, #0x1c
	ldrsh r2, [r4, r7]
	bl sub_FAE8
	movs r3, #0
	adds r6, r5, #0
	ldr r5, _0800D904 @ =gUnknown_0201A500
_0800D880:
	lsls r2, r3, #2
	ldr r1, [r4, #0xc]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r1, [r4, #0xb]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r2, r6
	ldr r0, [r2]
	stm r5!, {r0}
	adds r3, #1
	cmp r3, #3
	ble _0800D880
	movs r3, #0
	ldr r0, _0800D908 @ =gMain+0x74
	mov r8, r0
	ldr r1, _0800D8F8 @ =gUnknown_0202C610
	mov ip, r1
_0800D8AC:
	movs r1, #0
	adds r2, r3, #1
	mov sb, r2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r5, r0, #6
	adds r6, r5, #0
	adds r6, #0xe4
_0800D8BC:
	lsls r0, r1, #1
	adds r4, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r6
	mov r3, r8
	adds r2, r1, r3
	adds r3, r0, r5
	movs r1, #5
_0800D8CE:
	mov r7, ip
	adds r0, r3, r7
	ldr r0, [r0]
	stm r2!, {r0}
	adds r3, #4
	subs r1, #1
	cmp r1, #0
	bge _0800D8CE
	adds r1, r4, #0
	cmp r1, #7
	ble _0800D8BC
	mov r3, sb
	cmp r3, #1
	ble _0800D8AC
	bl SaveFile_WriteToSram
	ldr r1, _0800D8FC @ =gMain
	movs r0, #3
	strb r0, [r1, #3]
	b _0800D9B6
	.align 2, 0
_0800D8F8: .4byte gUnknown_0202C610
_0800D8FC: .4byte gMain
_0800D900: .4byte gUnknown_02002858
_0800D904: .4byte gUnknown_0201A500
_0800D908: .4byte gMain+0x74
_0800D90C:
	movs r0, #0x6a
	bl m4aSongNumStart
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0x10
	ldrsh r1, [r4, r0]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r5
	b _0800D9B2
_0800D936:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D9B6
	ldr r4, _0800D950 @ =gUnknown_02002858
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0800D954
	movs r0, #0x8a
	bl m4aSongNumStart
	b _0800D9B6
	.align 2, 0
_0800D950: .4byte gUnknown_02002858
_0800D954:
	movs r0, #0x6a
	bl m4aSongNumStart
	strh r5, [r4, #0x12]
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	ldr r1, [r4, #0xc]
	movs r3, #0x10
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xb]
	bl sub_F670
	ldr r3, _0800D9E4 @ =gUnknown_0202C610
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	str r0, [r1]
	ldrh r0, [r4, #0x10]
	subs r0, #1
	strh r0, [r4, #0x10]
	movs r7, #0x10
	ldrsh r1, [r4, r7]
	lsls r1, r1, #2
	ldr r2, [r4, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r2, [r4, #0xb]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r1, r1, r3
_0800D9B2:
	ldr r0, [r1]
	strh r0, [r4, #0x16]
_0800D9B6:
	ldr r1, _0800D9E8 @ =0x040000D4
	ldr r0, _0800D9EC @ =gUnknown_03005C00
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800D9F0 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0800D9F4 @ =gUnknown_02002858
	ldrh r2, [r1, #0x20]
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0800D9D8
	subs r0, r2, #1
	strh r0, [r1, #0x20]
_0800D9D8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D9E4: .4byte gUnknown_0202C610
_0800D9E8: .4byte 0x040000D4
_0800D9EC: .4byte gUnknown_03005C00
_0800D9F0: .4byte 0x80000800
_0800D9F4: .4byte gUnknown_02002858

	thumb_func_start sub_D9F8
sub_D9F8: @ 0x0800D9F8
	push {lr}
	bl sub_19B4
	bl sub_E908
	ldr r1, _0800DA18 @ =gUnknown_0201B124
	movs r0, #0
	strb r0, [r1]
	bl sub_E464
	ldr r1, _0800DA1C @ =gMain
	movs r0, #6
	strb r0, [r1, #3]
	pop {r0}
	bx r0
	.align 2, 0
_0800DA18: .4byte gUnknown_0201B124
_0800DA1C: .4byte gMain

	thumb_func_start sub_DA20
sub_DA20: @ 0x0800DA20
	push {r4, r5, lr}
	bl sub_E464
	ldr r4, _0800DA4C @ =gMain
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DA58
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r0, _0800DA50 @ =gUnknown_0201B178
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0800DA54 @ =gUnknown_0202BEBC
	strb r1, [r0]
	bl sub_2568
	movs r0, #3
	strb r0, [r4, #3]
	b _0800DB2E
	.align 2, 0
_0800DA4C: .4byte gMain
_0800DA50: .4byte gUnknown_0201B178
_0800DA54: .4byte gUnknown_0202BEBC
_0800DA58:
	ldr r5, _0800DAB8 @ =gUnknown_0202ADD0
	ldr r0, _0800DABC @ =gUnknown_0202BEC8
	ldr r1, _0800DAC0 @ =gUnknown_0202C5F0
	ldr r2, _0800DAC4 @ =gUnknown_0201A4D0
	bl sub_1B04
	str r0, [r5]
	ldr r1, _0800DAC8 @ =gUnknown_0202BDF0
	movs r3, #3
	ands r3, r0
	str r3, [r1]
	ldr r2, _0800DACC @ =gUnknown_0201C1AC
	movs r1, #0x1c
	ands r1, r0
	lsrs r1, r1, #2
	strb r1, [r2]
	ldr r2, _0800DAD0 @ =gUnknown_0202ADDC
	movs r1, #0xe0
	lsls r1, r1, #4
	ands r1, r0
	lsrs r1, r1, #9
	strb r1, [r2]
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0
	beq _0800DB2E
	cmp r3, #1
	bhi _0800DB2E
	bl sub_E970
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800DAE8
	bl sub_E94C
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0800DAD4
	movs r0, #8
	strb r0, [r4, #3]
	b _0800DAE8
	.align 2, 0
_0800DAB8: .4byte gUnknown_0202ADD0
_0800DABC: .4byte gUnknown_0202BEC8
_0800DAC0: .4byte gUnknown_0202C5F0
_0800DAC4: .4byte gUnknown_0201A4D0
_0800DAC8: .4byte gUnknown_0202BDF0
_0800DACC: .4byte gUnknown_0201C1AC
_0800DAD0: .4byte gUnknown_0202ADDC
_0800DAD4:
	cmp r1, #1
	bne _0800DAE8
	ldr r0, _0800DB34 @ =gUnknown_0202BEBC
	movs r1, #2
	strb r1, [r0]
	movs r0, #7
	strb r0, [r4, #3]
	movs r0, #0x8a
	bl m4aSongNumStart
_0800DAE8:
	ldr r1, _0800DB38 @ =gUnknown_0201A510
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _0800DB3C @ =gUnknown_0202ADD0
	ldr r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0800DB2E
	ldr r0, _0800DB40 @ =gUnknown_0202ADE4
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0800DB2E
	ldr r1, _0800DB44 @ =gUnknown_0201A444
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _0800DB2E
	ldr r1, _0800DB34 @ =gUnknown_0202BEBC
	movs r0, #2
	strb r0, [r1]
	ldr r1, _0800DB48 @ =gMain
	movs r0, #7
	strb r0, [r1, #3]
	movs r0, #0x8a
	bl m4aSongNumStart
_0800DB2E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800DB34: .4byte gUnknown_0202BEBC
_0800DB38: .4byte gUnknown_0201A510
_0800DB3C: .4byte gUnknown_0202ADD0
_0800DB40: .4byte gUnknown_0202ADE4
_0800DB44: .4byte gUnknown_0201A444
_0800DB48: .4byte gMain

	thumb_func_start sub_DB4C
sub_DB4C: @ 0x0800DB4C
	ldr r1, _0800DB68 @ =gUnknown_0201A444
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800DB66
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800DB6C @ =gMain
	movs r0, #5
	strb r0, [r1, #3]
_0800DB66:
	bx lr
	.align 2, 0
_0800DB68: .4byte gUnknown_0201A444
_0800DB6C: .4byte gMain

	thumb_func_start sub_DB70
sub_DB70: @ 0x0800DB70
	push {r4, r5, r6, lr}
	bl sub_E464
	ldr r1, _0800DBDC @ =gUnknown_02002858
	ldrh r0, [r1, #0x22]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x22]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x5a
	ble _0800DBD4
	movs r0, #0
	strh r0, [r1, #0x22]
	ldr r0, _0800DBE0 @ =gUnknown_0201B178
	strb r2, [r0]
	ldr r0, _0800DBE4 @ =gUnknown_0202BEBC
	strb r2, [r0]
	bl sub_2568
	bl sub_1AA4
	movs r1, #0
	ldr r6, _0800DBE8 @ =gUnknown_0202C550
	ldr r5, _0800DBEC @ =gUnknown_0202C610
_0800DBA2:
	lsls r0, r1, #1
	adds r4, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #3
	lsls r0, r0, #6
	adds r3, r0, r5
	adds r1, r1, r6
	movs r2, #5
_0800DBB2:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _0800DBB2
	adds r1, r4, #0
	cmp r1, #1
	ble _0800DBA2
	movs r4, #0
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r0, _0800DBF0 @ =gMain
	strb r4, [r0, #3]
_0800DBD4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DBDC: .4byte gUnknown_02002858
_0800DBE0: .4byte gUnknown_0201B178
_0800DBE4: .4byte gUnknown_0202BEBC
_0800DBE8: .4byte gUnknown_0202C550
_0800DBEC: .4byte gUnknown_0202C610
_0800DBF0: .4byte gMain

	thumb_func_start sub_DBF4
sub_DBF4: @ 0x0800DBF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl sub_E464
	ldr r2, _0800DC14 @ =gUnknown_02002858
	movs r1, #0x22
	ldrsh r0, [r2, r1]
	cmp r0, #0x82
	beq _0800DC28
	cmp r0, #0x82
	bgt _0800DC18
	cmp r0, #4
	beq _0800DC1E
	b _0800DCBA
	.align 2, 0
_0800DC14: .4byte gUnknown_02002858
_0800DC18:
	cmp r0, #0xfa
	beq _0800DC3C
	b _0800DCBA
_0800DC1E:
	bl sub_2568
	bl sub_1AA4
	b _0800DCBA
_0800DC28:
	ldr r1, _0800DC38 @ =gUnknown_0202BEBC
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x65
	bl m4aSongNumStart
	b _0800DCBA
	.align 2, 0
_0800DC38: .4byte gUnknown_0202BEBC
_0800DC3C:
	movs r1, #0
	movs r0, #0
	strh r0, [r2, #0x22]
	ldr r0, _0800DCD0 @ =gUnknown_0201B178
	strb r1, [r0]
	ldr r0, _0800DCD4 @ =gUnknown_0202BEBC
	strb r1, [r0]
	movs r0, #0
	bl sub_F4FC
	ldr r1, _0800DCD8 @ =gUnknown_0202BED8
	str r0, [r1]
	movs r0, #1
	bl sub_F4FC
	ldr r1, _0800DCDC @ =gUnknown_0201B170
	str r0, [r1]
	movs r2, #0
	ldr r3, _0800DCE0 @ =gMain+0x74
	mov r8, r3
	ldr r7, _0800DCE4 @ =gUnknown_0202C610
	mov ip, r7
_0800DC68:
	movs r1, #0
	lsls r0, r2, #1
	adds r3, r2, #1
	mov sb, r3
	adds r0, r0, r2
	lsls r5, r0, #6
	adds r6, r5, #0
	adds r6, #0xe4
_0800DC78:
	lsls r0, r1, #1
	adds r4, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r6
	add r1, r8
	adds r2, r0, r5
	movs r3, #5
_0800DC88:
	mov r7, ip
	adds r0, r2, r7
	ldr r0, [r0]
	stm r1!, {r0}
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _0800DC88
	adds r1, r4, #0
	cmp r1, #7
	ble _0800DC78
	mov r2, sb
	cmp r2, #1
	ble _0800DC68
	bl SaveFile_WriteToSram
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _0800DCE8 @ =gMain
	movs r0, #0xc
	strb r0, [r1, #3]
_0800DCBA:
	ldr r1, _0800DCEC @ =gUnknown_02002858
	ldrh r0, [r1, #0x22]
	adds r0, #1
	strh r0, [r1, #0x22]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800DCD0: .4byte gUnknown_0201B178
_0800DCD4: .4byte gUnknown_0202BEBC
_0800DCD8: .4byte gUnknown_0202BED8
_0800DCDC: .4byte gUnknown_0201B170
_0800DCE0: .4byte gMain+0x74
_0800DCE4: .4byte gUnknown_0202C610
_0800DCE8: .4byte gMain
_0800DCEC: .4byte gUnknown_02002858

	thumb_func_start sub_DCF0
sub_DCF0: @ 0x0800DCF0
	push {r4, r5, lr}
	bl sub_E464
	ldr r5, _0800DD20 @ =gMain
	ldrh r1, [r5, #0x18]
	movs r4, #1
	ands r4, r1
	cmp r4, #0
	beq _0800DD24
	movs r0, #0x65
	bl m4aSongNumStart
	bl sub_F6E0
	bl SaveFile_WriteToSram
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	movs r0, #0
	b _0800DD3C
	.align 2, 0
_0800DD20: .4byte gMain
_0800DD24:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DD3E
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r0, _0800DD44 @ =gUnknown_0201B178
	strb r4, [r0]
	ldr r0, _0800DD48 @ =gUnknown_0202BEBC
	strb r4, [r0]
	movs r0, #3
_0800DD3C:
	strb r0, [r5, #3]
_0800DD3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800DD44: .4byte gUnknown_0201B178
_0800DD48: .4byte gUnknown_0202BEBC

	thumb_func_start sub_DD4C
sub_DD4C: @ 0x0800DD4C
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _0800DD6C @ =gAutoDisplayTitlescreenMenu
	movs r0, #1
	strb r0, [r1]
	movs r0, #1
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_0800DD6C: .4byte gAutoDisplayTitlescreenMenu

	thumb_func_start sub_DD70
sub_DD70: @ 0x0800DD70
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800DE50 @ =0x0400000C
	ldr r3, _0800DE54 @ =0x00004006
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800DE58 @ =0x0400000E
	ldr r3, _0800DE5C @ =0x0000420F
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r6, _0800DE60 @ =gMain
	ldrh r0, [r2]
	strh r0, [r6, #0x16]
	ldr r4, _0800DE64 @ =0x040000D4
	ldr r0, _0800DE68 @ =gUnknown_0809DBE0
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0800DE6C @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DE70 @ =gUnknown_080957A0
	str r0, [r4]
	ldr r0, _0800DE74 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _0800DE78 @ =0x80002400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DE7C @ =gUnknown_0809AFC0
	str r0, [r4]
	ldr r0, _0800DE80 @ =0x0600C000
	str r0, [r4, #4]
	ldr r0, _0800DE84 @ =0x80001600
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DE88 @ =gUnknown_080947A0
	str r0, [r4]
	ldr r0, _0800DE8C @ =gUnknown_03005C00
	mov r8, r0
	str r0, [r4, #4]
	ldr r5, _0800DE90 @ =0x80000800
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DE94 @ =gUnknown_08099FC0
	str r0, [r4]
	ldr r0, _0800DE98 @ =0x06001000
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DE9C @ =gUnknown_0809DDE0
	str r0, [r4]
	ldr r0, _0800DEA0 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0800DEA4 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800DEA8 @ =gUnknown_0809DFE0
	str r0, [r4]
	ldr r0, _0800DEAC @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _0800DEB0 @ =0x80002210
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_DEB4
	bl sub_EE64
	mov r1, r8
	str r1, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #9
	bl m4aSongNumStart
	bl sub_CBC
	bl sub_24C
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DE50: .4byte 0x0400000C
_0800DE54: .4byte 0x00004006
_0800DE58: .4byte 0x0400000E
_0800DE5C: .4byte 0x0000420F
_0800DE60: .4byte gMain
_0800DE64: .4byte 0x040000D4
_0800DE68: .4byte gUnknown_0809DBE0
_0800DE6C: .4byte 0x80000100
_0800DE70: .4byte gUnknown_080957A0
_0800DE74: .4byte 0x06004000
_0800DE78: .4byte 0x80002400
_0800DE7C: .4byte gUnknown_0809AFC0
_0800DE80: .4byte 0x0600C000
_0800DE84: .4byte 0x80001600
_0800DE88: .4byte gUnknown_080947A0
_0800DE8C: .4byte gUnknown_03005C00
_0800DE90: .4byte 0x80000800
_0800DE94: .4byte gUnknown_08099FC0
_0800DE98: .4byte 0x06001000
_0800DE9C: .4byte gUnknown_0809DDE0
_0800DEA0: .4byte 0x05000200
_0800DEA4: .4byte 0x80000010
_0800DEA8: .4byte gUnknown_0809DFE0
_0800DEAC: .4byte 0x06010000
_0800DEB0: .4byte 0x80002210

	thumb_func_start sub_DEB4
sub_DEB4: @ 0x0800DEB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r0, _0800DF54 @ =gUnknown_02002858
	mov r8, r0
	ldr r0, _0800DF58 @ =gMain
	mov ip, r0
	ldr r0, _0800DF5C @ =gUnknown_0202C610
	mov sl, r0
	movs r0, #0x74
	add r0, ip
	mov sb, r0
_0800DED2:
	movs r1, #0
	lsls r0, r2, #1
	adds r7, r2, #1
	adds r0, r0, r2
	lsls r5, r0, #6
	adds r6, r5, #0
	adds r6, #0xe4
_0800DEE0:
	lsls r0, r1, #1
	adds r4, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r6
	add r1, sb
	adds r0, r0, r5
	mov r2, sl
	adds r3, r0, r2
	movs r2, #5
_0800DEF4:
	ldm r1!, {r0}
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _0800DEF4
	adds r1, r4, #0
	cmp r1, #7
	ble _0800DEE0
	adds r2, r7, #0
	cmp r2, #1
	ble _0800DED2
	movs r0, #0
	movs r1, #0
	mov r2, r8
	strh r0, [r2, #8]
	strh r0, [r2, #0x1e]
	strh r0, [r2, #0x1c]
	strb r1, [r2, #0xb]
	ldr r2, _0800DF60 @ =gUnknown_02002882
	strh r0, [r2]
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	ldr r2, _0800DF64 @ =gUnknown_02002880
	strh r0, [r2]
	mov r0, r8
	adds r0, #0x24
	strb r1, [r0]
	mov r0, r8
	strb r1, [r0, #0xa]
	ldr r2, _0800DF60 @ =gUnknown_02002882
	ldrh r1, [r2]
	movs r0, #0xbd
	lsls r0, r0, #2
	add r0, ip
	strh r1, [r0]
	ldrh r1, [r2]
	movs r0, #0xbc
	lsls r0, r0, #2
	add r0, ip
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800DF54: .4byte gUnknown_02002858
_0800DF58: .4byte gMain
_0800DF5C: .4byte gUnknown_0202C610
_0800DF60: .4byte gUnknown_02002882
_0800DF64: .4byte gUnknown_02002880

	thumb_func_start sub_DF68
sub_DF68: @ 0x0800DF68
	push {r4, r5, lr}
	ldr r0, _0800DF80 @ =gUnknown_02002858
	ldrb r4, [r0, #0xa]
	adds r5, r0, #0
	cmp r4, #1
	beq _0800DFE8
	cmp r4, #1
	bgt _0800DF88
	cmp r4, #0
	beq _0800DF94
	ldr r4, _0800DF84 @ =gMain
	b _0800E072
	.align 2, 0
_0800DF80: .4byte gUnknown_02002858
_0800DF84: .4byte gMain
_0800DF88:
	cmp r4, #2
	beq _0800E020
	ldr r4, _0800DF90 @ =gMain
	b _0800E072
	.align 2, 0
_0800DF90: .4byte gMain
_0800DF94:
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800DFC0
	strh r4, [r5, #0x1e]
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r0, #0
	movs r1, #0
	bl sub_F8B0
	ldrh r0, [r5, #0x1c]
	adds r0, #1
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800DFC0
	strh r4, [r5, #0x1c]
_0800DFC0:
	ldr r0, _0800DFE0 @ =gUnknown_02002858
	movs r1, #8
	ldrsh r2, [r0, r1]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r5, r0, #0
	ldr r4, _0800DFE4 @ =gMain
	cmp r2, r1
	ble _0800E072
	movs r0, #0
	strh r0, [r5, #8]
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0xa]
	b _0800E072
	.align 2, 0
_0800DFE0: .4byte gUnknown_02002858
_0800DFE4: .4byte gMain
_0800DFE8:
	ldr r2, _0800E018 @ =gUnknown_02002882
	ldrh r0, [r2]
	adds r0, #8
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xef
	ble _0800E000
	movs r0, #0
	strh r0, [r5, #8]
	movs r0, #2
	strb r0, [r5, #0xa]
_0800E000:
	ldr r1, _0800E01C @ =gMain
	ldrh r2, [r2]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #4
	adds r0, r1, r3
	strh r2, [r0]
	adds r4, r1, #0
	b _0800E072
	.align 2, 0
_0800E018: .4byte gUnknown_02002882
_0800E01C: .4byte gMain
_0800E020:
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800E04E
	strh r4, [r5, #0x1e]
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r0, #1
	movs r1, #0
	bl sub_F8B0
	ldrh r0, [r5, #0x1c]
	adds r0, #1
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800E04E
	strh r4, [r5, #0x1c]
_0800E04E:
	ldr r0, _0800E0B0 @ =gUnknown_02002858
	movs r1, #8
	ldrsh r2, [r0, r1]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r5, r0, #0
	ldr r4, _0800E0B4 @ =gMain
	cmp r2, r1
	ble _0800E072
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
_0800E072:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ldr r1, _0800E0B8 @ =0x040000D4
	ldr r0, _0800E0BC @ =gUnknown_03005C00
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800E0C0 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r4, #0x18]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0800E0A8
	movs r0, #0x66
	bl m4aSongNumStart
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
_0800E0A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E0B0: .4byte gUnknown_02002858
_0800E0B4: .4byte gMain
_0800E0B8: .4byte 0x040000D4
_0800E0BC: .4byte gUnknown_03005C00
_0800E0C0: .4byte 0x80000800

	thumb_func_start sub_E0C4
sub_E0C4: @ 0x0800E0C4
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r0, _0800E0E8 @ =gUnknown_02002858
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_0800E0E8: .4byte gUnknown_02002858

	thumb_func_start sub_E0EC
sub_E0EC: @ 0x0800E0EC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800E1CC @ =0x0400000C
	ldr r3, _0800E1D0 @ =0x00004006
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800E1D4 @ =0x0400000E
	ldr r3, _0800E1D8 @ =0x0000420F
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r6, _0800E1DC @ =gMain
	ldrh r0, [r2]
	strh r0, [r6, #0x16]
	ldr r4, _0800E1E0 @ =0x040000D4
	ldr r0, _0800E1E4 @ =gUnknown_0809DBE0
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0800E1E8 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E1EC @ =gUnknown_080957A0
	str r0, [r4]
	ldr r0, _0800E1F0 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _0800E1F4 @ =0x80002400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E1F8 @ =gUnknown_0809AFC0
	str r0, [r4]
	ldr r0, _0800E1FC @ =0x0600C000
	str r0, [r4, #4]
	ldr r0, _0800E200 @ =0x80001600
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E204 @ =gUnknown_080947A0
	str r0, [r4]
	ldr r0, _0800E208 @ =gUnknown_03005C00
	mov r8, r0
	str r0, [r4, #4]
	ldr r5, _0800E20C @ =0x80000800
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E210 @ =gUnknown_08099FC0
	str r0, [r4]
	ldr r0, _0800E214 @ =0x06001000
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E218 @ =gUnknown_0809DDE0
	str r0, [r4]
	ldr r0, _0800E21C @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0800E220 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800E224 @ =gUnknown_0809DFE0
	str r0, [r4]
	ldr r0, _0800E228 @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _0800E22C @ =0x80002210
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_DEB4
	bl sub_EE64
	mov r1, r8
	str r1, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #9
	bl m4aSongNumStart
	bl sub_CBC
	bl sub_24C
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800E1CC: .4byte 0x0400000C
_0800E1D0: .4byte 0x00004006
_0800E1D4: .4byte 0x0400000E
_0800E1D8: .4byte 0x0000420F
_0800E1DC: .4byte gMain
_0800E1E0: .4byte 0x040000D4
_0800E1E4: .4byte gUnknown_0809DBE0
_0800E1E8: .4byte 0x80000100
_0800E1EC: .4byte gUnknown_080957A0
_0800E1F0: .4byte 0x06004000
_0800E1F4: .4byte 0x80002400
_0800E1F8: .4byte gUnknown_0809AFC0
_0800E1FC: .4byte 0x0600C000
_0800E200: .4byte 0x80001600
_0800E204: .4byte gUnknown_080947A0
_0800E208: .4byte gUnknown_03005C00
_0800E20C: .4byte 0x80000800
_0800E210: .4byte gUnknown_08099FC0
_0800E214: .4byte 0x06001000
_0800E218: .4byte gUnknown_0809DDE0
_0800E21C: .4byte 0x05000200
_0800E220: .4byte 0x80000010
_0800E224: .4byte gUnknown_0809DFE0
_0800E228: .4byte 0x06010000
_0800E22C: .4byte 0x80002210

	thumb_func_start sub_E230
sub_E230: @ 0x0800E230
	push {r4, r5, lr}
	ldr r0, _0800E248 @ =gUnknown_02002858
	ldrb r4, [r0, #0xa]
	adds r5, r0, #0
	cmp r4, #1
	beq _0800E2BC
	cmp r4, #1
	bgt _0800E250
	cmp r4, #0
	beq _0800E25C
	ldr r4, _0800E24C @ =gMain
	b _0800E344
	.align 2, 0
_0800E248: .4byte gUnknown_02002858
_0800E24C: .4byte gMain
_0800E250:
	cmp r4, #2
	beq _0800E2F4
	ldr r4, _0800E258 @ =gMain
	b _0800E344
	.align 2, 0
_0800E258: .4byte gMain
_0800E25C:
	ldr r0, _0800E2B0 @ =gUnknown_0202BED8
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0800E292
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800E292
	strh r4, [r5, #0x1e]
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r0, #0
	bl sub_F8B0
	ldrh r0, [r5, #0x1c]
	adds r0, #1
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800E292
	strh r4, [r5, #0x1c]
_0800E292:
	ldr r0, _0800E2B4 @ =gUnknown_02002858
	movs r2, #8
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	ldr r4, _0800E2B8 @ =gMain
	cmp r1, #0x78
	ble _0800E344
	movs r0, #0
	strh r0, [r5, #8]
	strh r0, [r5, #0x1e]
	strh r0, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0xa]
	b _0800E344
	.align 2, 0
_0800E2B0: .4byte gUnknown_0202BED8
_0800E2B4: .4byte gUnknown_02002858
_0800E2B8: .4byte gMain
_0800E2BC:
	ldr r2, _0800E2EC @ =gUnknown_02002882
	ldrh r0, [r2]
	adds r0, #8
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xef
	ble _0800E2D4
	movs r0, #0
	strh r0, [r5, #8]
	movs r0, #2
	strb r0, [r5, #0xa]
_0800E2D4:
	ldr r1, _0800E2F0 @ =gMain
	ldrh r2, [r2]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #4
	adds r0, r1, r3
	strh r2, [r0]
	adds r4, r1, #0
	b _0800E344
	.align 2, 0
_0800E2EC: .4byte gUnknown_02002882
_0800E2F0: .4byte gMain
_0800E2F4:
	ldr r0, _0800E378 @ =gUnknown_0201B170
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0800E32C
	ldrh r0, [r5, #0x1e]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0800E32C
	strh r4, [r5, #0x1e]
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r0, #1
	bl sub_F8B0
	ldrh r0, [r5, #0x1c]
	adds r0, #1
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0800E32C
	strh r4, [r5, #0x1c]
_0800E32C:
	ldr r0, _0800E37C @ =gUnknown_02002858
	movs r2, #8
	ldrsh r1, [r0, r2]
	adds r5, r0, #0
	ldr r4, _0800E380 @ =gMain
	cmp r1, #0x78
	ble _0800E344
	movs r0, #0
	strh r0, [r5, #8]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
_0800E344:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ldr r1, _0800E384 @ =0x040000D4
	ldr r0, _0800E388 @ =gUnknown_03005C00
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800E38C @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r4, #0x18]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0800E372
	movs r0, #0x66
	bl m4aSongNumStart
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
_0800E372:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800E378: .4byte gUnknown_0201B170
_0800E37C: .4byte gUnknown_02002858
_0800E380: .4byte gMain
_0800E384: .4byte 0x040000D4
_0800E388: .4byte gUnknown_03005C00
_0800E38C: .4byte 0x80000800

	thumb_func_start sub_E390
sub_E390: @ 0x0800E390
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	movs r0, #8
	bl SetMainGameState
	pop {r0}
	bx r0

	thumb_func_start sub_E3A8
sub_E3A8: @ 0x0800E3A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0800E448 @ =gUnknown_02002858
	movs r0, #0x12
	ldrsh r1, [r4, r0]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, _0800E44C @ =gUnknown_0200B3B8
	adds r5, r0, r2
	movs r0, #1
	strh r0, [r5]
	ldr r0, _0800E450 @ =gUnknown_086A7DA8
	movs r1, #2
	bl LoadSpriteSets
	ldr r2, _0800E454 @ =gUnknown_080797F0
	ldr r0, [r4, #0xc]
	lsls r0, r0, #3
	ldrb r1, [r4, #0xb]
	lsls r1, r1, #6
	adds r0, r0, r1
	adds r0, r0, r2
	ldr r1, [r0]
	movs r3, #0x10
	ldrsh r0, [r4, r3]
	lsls r0, r0, #3
	adds r1, r1, r0
	strh r1, [r5, #2]
	ldr r1, [r4, #0xc]
	lsls r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsls r0, r0, #6
	adds r1, r1, r0
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r1]
	strh r0, [r5, #4]
	ldr r7, _0800E458 @ =gOamBuffer
	ldr r0, _0800E45C @ =0xFFFFFE00
	mov r8, r0
	adds r4, r5, #0
	adds r4, #8
	ldr r2, _0800E460 @ =0x000001FF
	mov ip, r2
	movs r6, #1
_0800E404:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	mov r0, ip
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r5, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _0800E404
	movs r0, #0
	strh r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E448: .4byte gUnknown_02002858
_0800E44C: .4byte gUnknown_0200B3B8
_0800E450: .4byte gUnknown_086A7DA8
_0800E454: .4byte gUnknown_080797F0
_0800E458: .4byte gOamBuffer
_0800E45C: .4byte 0xFFFFFE00
_0800E460: .4byte 0x000001FF

	thumb_func_start sub_E464
sub_E464: @ 0x0800E464
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _0800E5CC @ =gUnknown_0200B3B8
	adds r4, r6, #0
	movs r0, #0xb8
	adds r0, r0, r6
	mov sl, r0
	mov r5, sl
	ldr r0, _0800E5D0 @ =gUnknown_0202BEBC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0xb8
	adds r1, r0, #0
	muls r1, r2, r1
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r7, r1, r0
	ldr r0, _0800E5D4 @ =gUnknown_02002858
	mov sb, r0
	ldr r1, _0800E5D8 @ =gUnknown_0200287D
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r1, r1, r0
	mov r8, r1
	ldr r0, _0800E5DC @ =gUnknown_02002882
	movs r3, #0
	ldrsh r1, [r0, r3]
	cmp r1, #0
	beq _0800E4B4
	b _0800E674
_0800E4B4:
	movs r0, #1
	strh r0, [r6]
	strh r1, [r5]
	ldr r0, _0800E5E0 @ =gUnknown_0201B178
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r7]
	mov r0, sb
	adds r0, #0x26
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, r8
	strh r0, [r1]
	ldr r0, _0800E5E4 @ =gUnknown_086A7DB0
	movs r1, #9
	adds r2, r6, #0
	bl LoadSpriteSets
	movs r0, #0xdc
	strh r0, [r6, #2]
	movs r0, #0x90
	strh r0, [r6, #4]
	adds r4, #8
	ldr r2, _0800E5E8 @ =gOamBuffer
	mov sl, r2
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, sl
	mov r3, sb
	movs r5, #0x1a
	ldrsh r1, [r3, r5]
	lsls r1, r1, #1
	adds r1, #2
	ldr r3, _0800E5EC @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	ldr r0, _0800E5F0 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, sl
	movs r5, #2
	ldrsh r1, [r4, r5]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r5, _0800E5F4 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800E5F8 @ =0xFFFFFE00
	mov ip, r0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r6, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800E5AA
	movs r0, #0x54
	strh r0, [r1, #2]
	movs r0, #0x96
	strh r0, [r1, #4]
	ldr r2, _0800E5D8 @ =gUnknown_0200287D
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #7
	lsls r0, r0, #2
	ldr r3, _0800E5E4 @ =gUnknown_086A7DB0
	adds r0, r0, r3
	ldr r6, [r0]
	movs r5, #0
	ldrh r0, [r6]
	cmp r5, r0
	bge _0800E5AA
	mov sb, sl
	mov sl, ip
	mov r4, r8
	adds r4, #8
_0800E56A:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r2, #2
	ldrsh r1, [r4, r2]
	mov ip, r1
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	mov r2, ip
	adds r1, r2, r0
	ldr r2, _0800E5F4 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r3, [r6]
	cmp r5, r3
	blt _0800E56A
_0800E5AA:
	ldrh r0, [r7]
	cmp r0, #1
	beq _0800E5B2
	b _0800E846
_0800E5B2:
	ldr r0, _0800E5D0 @ =gUnknown_0202BEBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0800E5C2
	cmp r1, #4
	bne _0800E5FC
_0800E5C2:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x64
	b _0800E602
	.align 2, 0
_0800E5CC: .4byte gUnknown_0200B3B8
_0800E5D0: .4byte gUnknown_0202BEBC
_0800E5D4: .4byte gUnknown_02002858
_0800E5D8: .4byte gUnknown_0200287D
_0800E5DC: .4byte gUnknown_02002882
_0800E5E0: .4byte gUnknown_0201B178
_0800E5E4: .4byte gUnknown_086A7DB0
_0800E5E8: .4byte gOamBuffer
_0800E5EC: .4byte 0x000003FF
_0800E5F0: .4byte 0xFFFFFC00
_0800E5F4: .4byte 0x000001FF
_0800E5F8: .4byte 0xFFFFFE00
_0800E5FC:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x50
_0800E602:
	strh r0, [r7, #4]
	ldr r1, _0800E664 @ =gUnknown_086A7DB0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r0, [r6]
	cmp r5, r0
	blt _0800E61C
	b _0800E846
_0800E61C:
	ldr r1, _0800E668 @ =gOamBuffer
	mov sb, r1
	ldr r2, _0800E66C @ =0xFFFFFE00
	mov sl, r2
	adds r4, r7, #0
	adds r4, #8
_0800E628:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0800E670 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _0800E628
	b _0800E846
	.align 2, 0
_0800E664: .4byte gUnknown_086A7DB0
_0800E668: .4byte gOamBuffer
_0800E66C: .4byte 0xFFFFFE00
_0800E670: .4byte 0x000001FF
_0800E674:
	cmp r1, #0xf0
	beq _0800E67A
	b _0800E834
_0800E67A:
	movs r0, #0
	strh r0, [r6]
	movs r0, #1
	mov r1, sl
	strh r0, [r1]
	ldr r0, _0800E79C @ =gUnknown_0201B178
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r7]
	mov r0, sb
	adds r0, #0x26
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r2, r8
	strh r0, [r2]
	ldr r0, _0800E7A0 @ =gUnknown_086A7DB0
	movs r1, #9
	adds r2, r6, #0
	bl LoadSpriteSets
	movs r0, #4
	mov r3, sl
	strh r0, [r3, #2]
	movs r0, #0x90
	strh r0, [r3, #4]
	adds r4, r5, #0
	adds r4, #8
	ldr r5, _0800E7A4 @ =gOamBuffer
	mov ip, r5
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	mov r0, sb
	movs r3, #0x1a
	ldrsh r1, [r0, r3]
	lsls r1, r1, #1
	adds r1, #2
	ldr r5, _0800E7A8 @ =0x000003FF
	adds r0, r5, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	ldr r0, _0800E7AC @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r3, sl
	movs r5, #2
	ldrsh r0, [r3, r5]
	adds r1, r1, r0
	ldr r3, _0800E7B0 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800E7B4 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r5, sl
	ldrb r0, [r5, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800E77C
	movs r0, #0x54
	strh r0, [r1, #2]
	movs r0, #0x96
	strh r0, [r1, #4]
	ldr r2, _0800E7B8 @ =gUnknown_0200287D
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #7
	lsls r0, r0, #2
	ldr r3, _0800E7A0 @ =gUnknown_086A7DB0
	adds r0, r0, r3
	ldr r6, [r0]
	movs r5, #0
	ldrh r0, [r6]
	cmp r5, r0
	bge _0800E77C
	mov sb, ip
	ldr r1, _0800E7B4 @ =0xFFFFFE00
	mov sl, r1
	mov r4, r8
	adds r4, #8
_0800E73C:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r4, r0]
	mov ip, r2
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	mov r2, ip
	adds r1, r2, r0
	ldr r2, _0800E7B0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r3, [r6]
	cmp r5, r3
	blt _0800E73C
_0800E77C:
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800E846
	ldr r0, _0800E7BC @ =gUnknown_0202BEBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0800E792
	cmp r1, #4
	bne _0800E7C0
_0800E792:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x64
	b _0800E7C6
	.align 2, 0
_0800E79C: .4byte gUnknown_0201B178
_0800E7A0: .4byte gUnknown_086A7DB0
_0800E7A4: .4byte gOamBuffer
_0800E7A8: .4byte 0x000003FF
_0800E7AC: .4byte 0xFFFFFC00
_0800E7B0: .4byte 0x000001FF
_0800E7B4: .4byte 0xFFFFFE00
_0800E7B8: .4byte gUnknown_0200287D
_0800E7BC: .4byte gUnknown_0202BEBC
_0800E7C0:
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x50
_0800E7C6:
	strh r0, [r7, #4]
	ldr r1, _0800E824 @ =gUnknown_086A7DB0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r5, #0
	ldrh r0, [r6]
	cmp r5, r0
	bge _0800E846
	ldr r1, _0800E828 @ =gOamBuffer
	mov sb, r1
	ldr r2, _0800E82C @ =0xFFFFFE00
	mov sl, r2
	adds r4, r7, #0
	adds r4, #8
_0800E7EA:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0800E830 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r0, [r6]
	cmp r5, r0
	blt _0800E7EA
	b _0800E846
	.align 2, 0
_0800E824: .4byte gUnknown_086A7DB0
_0800E828: .4byte gOamBuffer
_0800E82C: .4byte 0xFFFFFE00
_0800E830: .4byte 0x000001FF
_0800E834:
	movs r0, #0
	strh r0, [r6]
	mov r1, sl
	strh r0, [r1]
	ldr r0, _0800E85C @ =gUnknown_086A7DB0
	movs r1, #9
	adds r2, r6, #0
	bl LoadSpriteSets
_0800E846:
	movs r0, #0
	strh r0, [r7]
	mov r2, r8
	strh r0, [r2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E85C: .4byte gUnknown_086A7DB0

	thumb_func_start sub_E860
sub_E860: @ 0x0800E860
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0800E8E8 @ =gUnknown_0202C580
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, _0800E8EC @ =gUnknown_0200B3B8
	adds r5, r0, r2
	ldr r0, _0800E8F0 @ =gUnknown_0201C18C
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5]
	ldr r0, _0800E8F4 @ =gUnknown_086A7DD4
	movs r1, #5
	bl LoadSpriteSets
	ldrh r0, [r5]
	cmp r0, #1
	bne _0800E8DA
	movs r0, #0x78
	strh r0, [r5, #2]
	ldr r0, _0800E8F8 @ =gUnknown_0201A4B8
	ldrh r0, [r0]
	strh r0, [r5, #4]
	ldr r7, _0800E8FC @ =gOamBuffer
	ldr r0, _0800E900 @ =0xFFFFFE00
	mov r8, r0
	adds r4, r5, #0
	adds r4, #8
	ldr r2, _0800E904 @ =0x000001FF
	mov ip, r2
	movs r6, #3
_0800E8A6:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	mov r0, ip
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r5, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _0800E8A6
_0800E8DA:
	movs r0, #0
	strh r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800E8E8: .4byte gUnknown_0202C580
_0800E8EC: .4byte gUnknown_0200B3B8
_0800E8F0: .4byte gUnknown_0201C18C
_0800E8F4: .4byte gUnknown_086A7DD4
_0800E8F8: .4byte gUnknown_0201A4B8
_0800E8FC: .4byte gOamBuffer
_0800E900: .4byte 0xFFFFFE00
_0800E904: .4byte 0x000001FF

	thumb_func_start sub_E908
sub_E908: @ 0x0800E908
	ldr r1, _0800E92C @ =gUnknown_0202C5F0
	movs r2, #0
	ldr r0, _0800E930 @ =0x0000CFCF
	strh r0, [r1]
	ldr r0, _0800E934 @ =gUnknown_0201C1B0
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0800E938 @ =gUnknown_0202C59C
	strh r1, [r0]
	ldr r0, _0800E93C @ =gUnknown_0202ADE4
	strb r2, [r0]
	ldr r0, _0800E940 @ =gUnknown_0201A4BC
	strb r2, [r0]
	ldr r0, _0800E944 @ =gUnknown_0202C598
	strb r2, [r0]
	ldr r0, _0800E948 @ =gUnknown_0202C54C
	strb r2, [r0]
	bx lr
	.align 2, 0
_0800E92C: .4byte gUnknown_0202C5F0
_0800E930: .4byte 0x0000CFCF
_0800E934: .4byte gUnknown_0201C1B0
_0800E938: .4byte gUnknown_0202C59C
_0800E93C: .4byte gUnknown_0202ADE4
_0800E940: .4byte gUnknown_0201A4BC
_0800E944: .4byte gUnknown_0202C598
_0800E948: .4byte gUnknown_0202C54C

	thumb_func_start sub_E94C
sub_E94C: @ 0x0800E94C
	push {lr}
	ldr r0, _0800E95C @ =gUnknown_0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E960
	bl sub_EBEC
	b _0800E964
	.align 2, 0
_0800E95C: .4byte gUnknown_0202BF20
_0800E960:
	bl sub_ED28
_0800E964:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start sub_E970
sub_E970: @ 0x0800E970
	push {lr}
	ldr r0, _0800E980 @ =gUnknown_0202BF20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800E984
	bl sub_E994
	b _0800E988
	.align 2, 0
_0800E980: .4byte gUnknown_0202BF20
_0800E984:
	bl sub_EAC0
_0800E988:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1

	thumb_func_start sub_E994
sub_E994: @ 0x0800E994
	push {r4, r5, lr}
	ldr r0, _0800E9B4 @ =gUnknown_0202ADE4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0800EA04
	ldr r0, _0800E9B8 @ =gUnknown_0201A4BC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0800E9BC
	cmp r0, #1
	beq _0800E9F4
	b _0800EAB2
	.align 2, 0
_0800E9B4: .4byte gUnknown_0202ADE4
_0800E9B8: .4byte gUnknown_0201A4BC
_0800E9BC:
	ldr r0, _0800E9D0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800E9DC
	ldr r1, _0800E9D4 @ =gUnknown_0202C5F0
	ldr r0, _0800E9D8 @ =0x0000DEDE
	strh r0, [r1]
	b _0800EAB2
	.align 2, 0
_0800E9D0: .4byte gMain
_0800E9D4: .4byte gUnknown_0202C5F0
_0800E9D8: .4byte 0x0000DEDE
_0800E9DC:
	ldr r1, _0800E9F0 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_0800E9E4:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800E9E4
	b _0800EAB2
	.align 2, 0
_0800E9F0: .4byte gUnknown_0202C5F0
_0800E9F4:
	ldr r1, _0800E9FC @ =gUnknown_0202C5F0
	ldr r0, _0800EA00 @ =0x0000EDED
	strh r0, [r1]
	b _0800EAB2
	.align 2, 0
_0800E9FC: .4byte gUnknown_0202C5F0
_0800EA00: .4byte 0x0000EDED
_0800EA04:
	ldr r0, _0800EA24 @ =gUnknown_0202C59C
	ldrh r2, [r0]
	adds r1, r2, #0
	adds r5, r0, #0
	cmp r1, #7
	bhi _0800EA30
	ldr r1, _0800EA28 @ =gUnknown_0202C5F0
	ldr r2, _0800EA2C @ =0x0000CFCF
	adds r0, r1, #0
	adds r0, #0xe
_0800EA18:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800EA18
	b _0800EAAC
	.align 2, 0
_0800EA24: .4byte gUnknown_0202C59C
_0800EA28: .4byte gUnknown_0202C5F0
_0800EA2C: .4byte 0x0000CFCF
_0800EA30:
	cmp r1, #9
	bhi _0800EA9C
	adds r0, r2, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0800EA94 @ =gUnknown_0202C5F0
	movs r4, #0
	strh r2, [r3]
	ldr r1, _0800EA98 @ =gUnknown_0202C610
	mov ip, r1
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r1, r1, #8
	mov r0, ip
	adds r0, #4
	adds r0, r2, r0
	ldr r0, [r0]
	orrs r0, r1
	strh r0, [r3, #2]
	mov r0, ip
	adds r0, #8
	adds r0, r2, r0
	ldr r1, [r0]
	lsls r1, r1, #8
	mov r0, ip
	adds r0, #0xc
	adds r0, r2, r0
	ldr r0, [r0]
	orrs r0, r1
	strh r0, [r3, #4]
	mov r0, ip
	adds r0, #0x10
	adds r0, r2, r0
	ldrh r1, [r0, #2]
	strh r1, [r3, #6]
	ldr r0, [r0]
	strh r0, [r3, #8]
	mov r0, ip
	adds r0, #0x14
	adds r2, r2, r0
	ldrh r0, [r2, #2]
	strh r0, [r3, #0xa]
	ldr r0, [r2]
	strh r0, [r3, #0xc]
	strh r4, [r3, #0xe]
	b _0800EAAC
	.align 2, 0
_0800EA94: .4byte gUnknown_0202C5F0
_0800EA98: .4byte gUnknown_0202C610
_0800EA9C:
	ldr r1, _0800EABC @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_0800EAA4:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800EAA4
_0800EAAC:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0800EAB2:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800EABC: .4byte gUnknown_0202C5F0

	thumb_func_start sub_EAC0
sub_EAC0: @ 0x0800EAC0
	push {r4, r5, lr}
	ldr r0, _0800EAE0 @ =gUnknown_0202ADE4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0800EB30
	ldr r0, _0800EAE4 @ =gUnknown_0202C598
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0800EAE8
	cmp r0, #1
	beq _0800EB20
	b _0800EBDE
	.align 2, 0
_0800EAE0: .4byte gUnknown_0202ADE4
_0800EAE4: .4byte gUnknown_0202C598
_0800EAE8:
	ldr r0, _0800EAFC @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800EB08
	ldr r1, _0800EB00 @ =gUnknown_0202C5F0
	ldr r0, _0800EB04 @ =0x0000DEDE
	strh r0, [r1]
	b _0800EBDE
	.align 2, 0
_0800EAFC: .4byte gMain
_0800EB00: .4byte gUnknown_0202C5F0
_0800EB04: .4byte 0x0000DEDE
_0800EB08:
	ldr r1, _0800EB1C @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_0800EB10:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800EB10
	b _0800EBDE
	.align 2, 0
_0800EB1C: .4byte gUnknown_0202C5F0
_0800EB20:
	ldr r1, _0800EB28 @ =gUnknown_0202C5F0
	ldr r0, _0800EB2C @ =0x0000EDED
	strh r0, [r1]
	b _0800EBDE
	.align 2, 0
_0800EB28: .4byte gUnknown_0202C5F0
_0800EB2C: .4byte 0x0000EDED
_0800EB30:
	ldr r0, _0800EB50 @ =gUnknown_0202C59C
	ldrh r2, [r0]
	adds r1, r2, #0
	adds r5, r0, #0
	cmp r1, #7
	bhi _0800EB5C
	ldr r1, _0800EB54 @ =gUnknown_0202C5F0
	ldr r2, _0800EB58 @ =0x0000CFCF
	adds r0, r1, #0
	adds r0, #0xe
_0800EB44:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800EB44
	b _0800EBD8
	.align 2, 0
_0800EB50: .4byte gUnknown_0202C59C
_0800EB54: .4byte gUnknown_0202C5F0
_0800EB58: .4byte 0x0000CFCF
_0800EB5C:
	cmp r1, #9
	bhi _0800EBC8
	adds r0, r2, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0800EBC0 @ =gUnknown_0202C5F0
	movs r4, #0
	strh r2, [r3]
	ldr r1, _0800EBC4 @ =gUnknown_0202C610
	mov ip, r1
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r0, r2, r1
	ldr r1, [r0]
	lsls r1, r1, #8
	mov r0, ip
	adds r0, #4
	adds r0, r2, r0
	ldr r0, [r0]
	orrs r0, r1
	strh r0, [r3, #2]
	mov r0, ip
	adds r0, #8
	adds r0, r2, r0
	ldr r1, [r0]
	lsls r1, r1, #8
	mov r0, ip
	adds r0, #0xc
	adds r0, r2, r0
	ldr r0, [r0]
	orrs r0, r1
	strh r0, [r3, #4]
	mov r0, ip
	adds r0, #0x10
	adds r0, r2, r0
	ldrh r1, [r0, #2]
	strh r1, [r3, #6]
	ldr r0, [r0]
	strh r0, [r3, #8]
	mov r0, ip
	adds r0, #0x14
	adds r2, r2, r0
	ldrh r0, [r2, #2]
	strh r0, [r3, #0xa]
	ldr r0, [r2]
	strh r0, [r3, #0xc]
	strh r4, [r3, #0xe]
	b _0800EBD8
	.align 2, 0
_0800EBC0: .4byte gUnknown_0202C5F0
_0800EBC4: .4byte gUnknown_0202C610
_0800EBC8:
	ldr r1, _0800EBE8 @ =gUnknown_0202C5F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xe
_0800EBD0:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800EBD0
_0800EBD8:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0800EBDE:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800EBE8: .4byte gUnknown_0202C5F0

	thumb_func_start sub_EBEC
sub_EBEC: @ 0x0800EBEC
	push {r4, r5, lr}
	ldr r4, _0800EC08 @ =gUnknown_0202ADE4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _0800EC7C
	ldr r3, _0800EC0C @ =gUnknown_0201A4BC
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r1, #0
	beq _0800EC10
	cmp r1, #1
	beq _0800EC30
	b _0800ECFC
	.align 2, 0
_0800EC08: .4byte gUnknown_0202ADE4
_0800EC0C: .4byte gUnknown_0201A4BC
_0800EC10:
	ldr r2, _0800EC28 @ =gUnknown_0201A4D0
	ldrh r0, [r2]
	ldr r1, _0800EC2C @ =0x0000DEDE
	cmp r0, r1
	beq _0800EC20
	ldrh r0, [r2, #2]
	cmp r0, r1
	bne _0800ECFC
_0800EC20:
	movs r0, #1
	strb r0, [r3]
	b _0800ECFC
	.align 2, 0
_0800EC28: .4byte gUnknown_0201A4D0
_0800EC2C: .4byte 0x0000DEDE
_0800EC30:
	ldr r3, _0800EC54 @ =gUnknown_0201A4D0
	ldrh r2, [r3]
	ldr r0, _0800EC58 @ =0x0000EDED
	cmp r2, r0
	bne _0800EC64
	ldrh r0, [r3, #2]
	cmp r0, r2
	bne _0800EC64
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r4]
	ldr r0, _0800EC5C @ =gUnknown_0202BEBC
	strb r1, [r0]
	ldr r0, _0800EC60 @ =gUnknown_0202C59C
	strh r1, [r0]
	b _0800ECFC
	.align 2, 0
_0800EC54: .4byte gUnknown_0201A4D0
_0800EC58: .4byte 0x0000EDED
_0800EC5C: .4byte gUnknown_0202BEBC
_0800EC60: .4byte gUnknown_0202C59C
_0800EC64:
	ldr r1, _0800EC78 @ =gUnknown_0202C54C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	ble _0800ECFC
	movs r0, #1
	b _0800ED1E
	.align 2, 0
_0800EC78: .4byte gUnknown_0202C54C
_0800EC7C:
	ldr r4, _0800ECF0 @ =gUnknown_0201A4D0
	ldrh r5, [r4, #2]
	adds r0, r5, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #1
	bhi _0800ED1C
	ldr r0, _0800ECF4 @ =gUnknown_0201C1B0
	strh r5, [r0]
	ldr r0, _0800ECF8 @ =gUnknown_0202C550
	mov ip, r0
	lsls r3, r1, #1
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r1, r3, r0
	ldrh r0, [r4, #6]
	lsrs r0, r0, #8
	str r0, [r1]
	mov r0, ip
	adds r0, #4
	adds r0, r3, r0
	ldrb r1, [r4, #6]
	str r1, [r0]
	mov r1, ip
	adds r1, #8
	adds r1, r3, r1
	ldrh r0, [r4, #0xa]
	lsrs r0, r0, #8
	str r0, [r1]
	mov r0, ip
	adds r0, #0xc
	adds r0, r3, r0
	ldrb r1, [r4, #0xa]
	str r1, [r0]
	mov r2, ip
	adds r2, #0x10
	adds r2, r3, r2
	ldrh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x12]
	orrs r0, r1
	str r0, [r2]
	mov r0, ip
	adds r0, #0x14
	adds r3, r3, r0
	ldrh r0, [r4, #0x16]
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x1a]
	orrs r0, r1
	str r0, [r3]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bne _0800ECFC
	movs r0, #1
	rsbs r0, r0, #0
	b _0800ED1E
	.align 2, 0
_0800ECF0: .4byte gUnknown_0201A4D0
_0800ECF4: .4byte gUnknown_0201C1B0
_0800ECF8: .4byte gUnknown_0202C550
_0800ECFC:
	movs r1, #0
	ldr r4, _0800ED24 @ =gUnknown_0201A4D0
	movs r3, #0
_0800ED02:
	lsls r0, r1, #2
	adds r2, r1, #1
	movs r1, #1
	adds r0, r0, r4
	adds r0, #2
_0800ED0C:
	strh r3, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0800ED0C
	adds r1, r2, #0
	cmp r1, #7
	ble _0800ED02
_0800ED1C:
	movs r0, #0
_0800ED1E:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800ED24: .4byte gUnknown_0201A4D0

	thumb_func_start sub_ED28
sub_ED28: @ 0x0800ED28
	push {r4, r5, lr}
	ldr r4, _0800ED44 @ =gUnknown_0202ADE4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _0800EDB8
	ldr r3, _0800ED48 @ =gUnknown_0202C598
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r1, #0
	beq _0800ED4C
	cmp r1, #1
	beq _0800ED6C
	b _0800EE38
	.align 2, 0
_0800ED44: .4byte gUnknown_0202ADE4
_0800ED48: .4byte gUnknown_0202C598
_0800ED4C:
	ldr r2, _0800ED64 @ =gUnknown_0201A4D0
	ldrh r0, [r2]
	ldr r1, _0800ED68 @ =0x0000DEDE
	cmp r0, r1
	beq _0800ED5C
	ldrh r0, [r2, #2]
	cmp r0, r1
	bne _0800EE38
_0800ED5C:
	movs r0, #1
	strb r0, [r3]
	b _0800EE38
	.align 2, 0
_0800ED64: .4byte gUnknown_0201A4D0
_0800ED68: .4byte 0x0000DEDE
_0800ED6C:
	ldr r3, _0800ED90 @ =gUnknown_0201A4D0
	ldrh r2, [r3]
	ldr r0, _0800ED94 @ =0x0000EDED
	cmp r2, r0
	bne _0800EDA0
	ldrh r0, [r3, #2]
	cmp r0, r2
	bne _0800EDA0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	strb r0, [r4]
	ldr r0, _0800ED98 @ =gUnknown_0202BEBC
	strb r1, [r0]
	ldr r0, _0800ED9C @ =gUnknown_0202C59C
	strh r1, [r0]
	b _0800EE38
	.align 2, 0
_0800ED90: .4byte gUnknown_0201A4D0
_0800ED94: .4byte 0x0000EDED
_0800ED98: .4byte gUnknown_0202BEBC
_0800ED9C: .4byte gUnknown_0202C59C
_0800EDA0:
	ldr r1, _0800EDB4 @ =gUnknown_0202C54C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	ble _0800EE38
	movs r0, #1
	b _0800EE5A
	.align 2, 0
_0800EDB4: .4byte gUnknown_0202C54C
_0800EDB8:
	ldr r4, _0800EE2C @ =gUnknown_0201A4D0
	ldrh r5, [r4]
	adds r0, r5, #0
	subs r0, #8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #1
	bhi _0800EE58
	ldr r0, _0800EE30 @ =gUnknown_0201C1B0
	strh r5, [r0]
	ldr r0, _0800EE34 @ =gUnknown_0202C550
	mov ip, r0
	lsls r3, r1, #1
	adds r3, r3, r1
	lsls r3, r3, #3
	adds r1, r3, r0
	ldrh r0, [r4, #4]
	lsrs r0, r0, #8
	str r0, [r1]
	mov r0, ip
	adds r0, #4
	adds r0, r3, r0
	ldrb r1, [r4, #4]
	str r1, [r0]
	mov r1, ip
	adds r1, #8
	adds r1, r3, r1
	ldrh r0, [r4, #8]
	lsrs r0, r0, #8
	str r0, [r1]
	mov r0, ip
	adds r0, #0xc
	adds r0, r3, r0
	ldrb r1, [r4, #8]
	str r1, [r0]
	mov r2, ip
	adds r2, #0x10
	adds r2, r3, r2
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	str r0, [r2]
	mov r0, ip
	adds r0, #0x14
	adds r3, r3, r0
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x18]
	orrs r0, r1
	str r0, [r3]
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bne _0800EE38
	movs r0, #1
	rsbs r0, r0, #0
	b _0800EE5A
	.align 2, 0
_0800EE2C: .4byte gUnknown_0201A4D0
_0800EE30: .4byte gUnknown_0201C1B0
_0800EE34: .4byte gUnknown_0202C550
_0800EE38:
	movs r1, #0
	ldr r4, _0800EE60 @ =gUnknown_0201A4D0
	movs r3, #0
_0800EE3E:
	lsls r0, r1, #2
	adds r2, r1, #1
	movs r1, #1
	adds r0, r0, r4
	adds r0, #2
_0800EE48:
	strh r3, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0800EE48
	adds r1, r2, #0
	cmp r1, #7
	ble _0800EE3E
_0800EE58:
	movs r0, #0
_0800EE5A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800EE60: .4byte gUnknown_0201A4D0

	thumb_func_start sub_EE64
sub_EE64: @ 0x0800EE64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r6, #0
	ldr r4, _0800EF20 @ =gUnknown_086A7FAC
	ldr r5, _0800EF24 @ =gUnknown_0202C610
_0800EE76:
	ldm r5!, {r0}
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #6
	movs r1, #1
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #8
	movs r3, #3
	bl sub_105A0
	adds r6, #1
	cmp r6, #3
	ble _0800EE76
	movs r5, #1
	ldr r0, _0800EF20 @ =gUnknown_086A7FAC
	mov sb, r0
	ldr r1, _0800EF24 @ =gUnknown_0202C610
	mov sl, r1
_0800EEA4:
	movs r6, #0
	lsls r7, r5, #1
	adds r2, r5, #1
	mov r8, r2
	adds r4, r7, #0
	adds r0, r4, r5
	lsls r0, r0, #3
	mov r1, sl
	adds r5, r0, r1
_0800EEB6:
	ldm r5!, {r0}
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r0, #0xa0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #6
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #8
	adds r3, r4, #3
	bl sub_105A0
	adds r6, #1
	cmp r6, #3
	ble _0800EEB6
	mov r5, r8
	cmp r5, #7
	ble _0800EEA4
	ldr r1, _0800EF24 @ =gUnknown_0202C610
	ldr r0, [r1, #0x10]
	ldr r1, [r1, #0x14]
	bl sub_F21C
	movs r6, #0
	movs r5, #0xc
	ldr r4, _0800EF28 @ =gUnknown_0202C5C0
	movs r7, #1
_0800EEF4:
	adds r0, r6, #1
	movs r1, #3
	bl __modsi3
	cmp r0, #0
	bne _0800EF2C
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	movs r3, #2
	bl sub_105A0
	b _0800EF44
	.align 2, 0
_0800EF20: .4byte gUnknown_086A7FAC
_0800EF24: .4byte gUnknown_0202C610
_0800EF28: .4byte gUnknown_0202C5C0
_0800EF2C:
	ldrh r0, [r4]
	adds r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	movs r3, #2
	bl sub_105A0
_0800EF44:
	adds r5, #1
	adds r4, #2
	adds r6, #1
	cmp r6, #0xd
	ble _0800EEF4
	ldr r4, _0800EFC8 @ =gUnknown_0202C5C0
	ldrh r0, [r4, #0x1c]
	adds r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	movs r2, #0x1a
	movs r3, #2
	bl sub_105A0
	movs r5, #1
	ldr r2, _0800EFCC @ =gUnknown_0202C610
	str r2, [sp, #8]
	mov sl, r5
	movs r0, #2
	mov sb, r0
_0800EF76:
	lsls r4, r5, #1
	adds r1, r4, r5
	lsls r1, r1, #3
	ldr r0, [sp, #8]
	adds r0, #0x10
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, _0800EFD0 @ =gUnknown_0202C624
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_F21C
	movs r6, #0
	adds r7, r4, #0
	adds r5, #1
	mov r8, r5
	movs r5, #0xc
	ldr r4, _0800EFC8 @ =gUnknown_0202C5C0
_0800EF9A:
	adds r0, r6, #1
	movs r1, #3
	bl __modsi3
	cmp r0, #0
	bne _0800EFD4
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sl
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	adds r3, r7, #3
	bl sub_105A0
	b _0800EFF4
	.align 2, 0
_0800EFC8: .4byte gUnknown_0202C5C0
_0800EFCC: .4byte gUnknown_0202C610
_0800EFD0: .4byte gUnknown_0202C624
_0800EFD4:
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sl
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	adds r3, r7, #3
	bl sub_105A0
_0800EFF4:
	adds r5, #1
	adds r4, #2
	adds r6, #1
	cmp r6, #0xd
	ble _0800EF9A
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r1, #0
	ldr r2, _0800F0E4 @ =gUnknown_0202C5C0
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r7, #3
	mov r1, sl
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r1, #9
	movs r2, #0x1a
	bl sub_105A0
	mov r5, r8
	cmp r5, #7
	ble _0800EF76
	movs r6, #0
	ldr r7, _0800F0E8 @ =gUnknown_086A7FAC
	ldr r0, _0800F0EC @ =gUnknown_0202C610
	adds r5, r0, #0
	adds r5, #0xc0
	movs r4, #1
_0800F032:
	ldm r5!, {r0}
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #4
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #8
	movs r3, #0x23
	bl sub_105A0
	adds r6, #1
	cmp r6, #3
	ble _0800F032
	movs r5, #1
	ldr r0, _0800F0E8 @ =gUnknown_086A7FAC
	mov sb, r0
	ldr r1, _0800F0F0 @ =gUnknown_0202C6D0
	mov sl, r1
_0800F05E:
	movs r6, #0
	lsls r7, r5, #1
	adds r2, r5, #1
	mov r8, r2
	adds r4, r7, #0
	adds r0, r4, r5
	lsls r0, r0, #3
	mov r1, sl
	adds r5, r0, r1
_0800F070:
	ldm r5!, {r0}
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r0, #0xa0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #4
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #8
	adds r3, r4, #0
	adds r3, #0x23
	bl sub_105A0
	adds r6, #1
	cmp r6, #3
	ble _0800F070
	mov r5, r8
	cmp r5, #7
	ble _0800F05E
	ldr r1, _0800F0EC @ =gUnknown_0202C610
	adds r0, r1, #0
	adds r0, #0xd0
	ldr r0, [r0]
	adds r1, #0xd4
	ldr r1, [r1]
	bl sub_F21C
	movs r6, #0
	movs r5, #0xa
	ldr r4, _0800F0E4 @ =gUnknown_0202C5C0
	movs r7, #1
_0800F0B6:
	adds r0, r6, #1
	movs r1, #3
	bl __modsi3
	cmp r0, #0
	bne _0800F0F4
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	movs r3, #0x22
	bl sub_105A0
	b _0800F10C
	.align 2, 0
_0800F0E4: .4byte gUnknown_0202C5C0
_0800F0E8: .4byte gUnknown_086A7FAC
_0800F0EC: .4byte gUnknown_0202C610
_0800F0F0: .4byte gUnknown_0202C6D0
_0800F0F4:
	ldrh r0, [r4]
	adds r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r7, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	adds r2, r5, #0
	movs r3, #0x22
	bl sub_105A0
_0800F10C:
	adds r5, #1
	adds r4, #2
	adds r6, #1
	cmp r6, #0xd
	ble _0800F0B6
	ldr r4, _0800F19C @ =gUnknown_0202C5C0
	lsls r0, r6, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r0, #0xe0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #9
	movs r2, #0x18
	movs r3, #0x22
	bl sub_105A0
	movs r5, #1
	ldr r2, _0800F1A0 @ =gUnknown_0202C610
	str r2, [sp, #0xc]
	mov sl, r5
	movs r0, #2
	mov sb, r0
_0800F142:
	lsls r4, r5, #1
	adds r1, r4, r5
	lsls r1, r1, #3
	ldr r0, [sp, #0xc]
	adds r0, #0xd0
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, _0800F1A4 @ =gUnknown_0202C6E4
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_F21C
	movs r6, #0
	adds r7, r4, #0
	adds r5, #1
	mov r8, r5
_0800F162:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #3
	bl __modsi3
	cmp r0, #0
	bne _0800F1A8
	lsls r1, r6, #1
	ldr r0, _0800F19C @ =gUnknown_0202C5C0
	adds r1, r1, r0
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #0
	adds r2, #0xa
	mov r1, sl
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #9
	adds r3, r7, #0
	adds r3, #0x23
	bl sub_105A0
	b _0800F1D2
	.align 2, 0
_0800F19C: .4byte gUnknown_0202C5C0
_0800F1A0: .4byte gUnknown_0202C610
_0800F1A4: .4byte gUnknown_0202C6E4
_0800F1A8:
	lsls r1, r6, #1
	ldr r2, _0800F218 @ =gUnknown_0202C5C0
	adds r1, r1, r2
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r6, #0
	adds r2, #0xa
	mov r1, sl
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #9
	adds r3, r7, #0
	adds r3, #0x23
	bl sub_105A0
_0800F1D2:
	adds r6, r4, #0
	cmp r4, #0xd
	ble _0800F162
	lsls r1, r4, #1
	ldr r2, _0800F218 @ =gUnknown_0202C5C0
	adds r1, r1, r2
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r7, #0
	adds r3, #0x23
	mov r1, sl
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r1, #9
	movs r2, #0x18
	bl sub_105A0
	mov r5, r8
	cmp r5, #7
	ble _0800F142
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F218: .4byte gUnknown_0202C5C0

	thumb_func_start sub_F21C
sub_F21C: @ 0x0800F21C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	cmp r5, #0
	bne _0800F250
	cmp r7, #0
	bne _0800F250
	ldr r4, _0800F24C @ =gUnknown_0202C5C0
	adds r2, r4, #0
	movs r1, #0xa
	adds r0, r4, #0
	adds r0, #0x1a
_0800F23E:
	strh r1, [r0]
	subs r0, #2
	cmp r0, r2
	bge _0800F23E
	movs r0, #0
	strh r0, [r4, #0x1c]
	b _0800F392
	.align 2, 0
_0800F24C: .4byte gUnknown_0202C5C0
_0800F250:
	ldr r0, _0800F25C @ =0x0098967F
	cmp r5, r0
	bls _0800F260
	adds r5, r0, #0
	b _0800F266
	.align 2, 0
_0800F25C: .4byte 0x0098967F
_0800F260:
	ldr r0, _0800F3A4 @ =0x05F5E0FF
	cmp r7, r0
	bls _0800F268
_0800F266:
	ldr r7, _0800F3A4 @ =0x05F5E0FF
_0800F268:
	ldr r4, _0800F3A8 @ =gUnknown_0202C5C0
	ldr r0, _0800F3AC @ =0x000F4240
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl __udivsi3
	str r0, [sp]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r4]
	adds r0, r5, #0
	mov r1, sl
	bl __umodsi3
	adds r5, r0, #0
	ldr r0, _0800F3B0 @ =0x000186A0
	mov sb, r0
	adds r0, r5, #0
	mov r1, sb
	bl __udivsi3
	strh r0, [r4, #2]
	adds r0, r5, #0
	mov r1, sb
	bl __umodsi3
	adds r5, r0, #0
	ldr r1, _0800F3B4 @ =0x00002710
	mov r8, r1
	bl __udivsi3
	strh r0, [r4, #4]
	adds r0, r5, #0
	mov r1, r8
	bl __umodsi3
	adds r5, r0, #0
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r1, r6, #0
	bl __udivsi3
	strh r0, [r4, #6]
	adds r0, r5, #0
	adds r1, r6, #0
	bl __umodsi3
	adds r5, r0, #0
	movs r1, #0x64
	bl __udivsi3
	strh r0, [r4, #8]
	adds r0, r5, #0
	movs r1, #0x64
	bl __umodsi3
	adds r5, r0, #0
	movs r1, #0xa
	bl __udivsi3
	strh r0, [r4, #0xa]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strh r0, [r4, #0xc]
	ldr r5, _0800F3B8 @ =0x00989680
	adds r0, r7, #0
	adds r1, r5, #0
	bl __udivsi3
	strh r0, [r4, #0xe]
	adds r0, r7, #0
	adds r1, r5, #0
	bl __umodsi3
	adds r5, r0, #0
	mov r1, sl
	bl __udivsi3
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	mov r1, sl
	bl __umodsi3
	adds r5, r0, #0
	mov r1, sb
	bl __udivsi3
	strh r0, [r4, #0x12]
	adds r0, r5, #0
	mov r1, sb
	bl __umodsi3
	adds r5, r0, #0
	mov r1, r8
	bl __udivsi3
	strh r0, [r4, #0x14]
	adds r0, r5, #0
	mov r1, r8
	bl __umodsi3
	adds r5, r0, #0
	adds r1, r6, #0
	bl __udivsi3
	strh r0, [r4, #0x16]
	adds r0, r5, #0
	adds r1, r6, #0
	bl __umodsi3
	adds r5, r0, #0
	movs r1, #0x64
	bl __udivsi3
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	movs r1, #0x64
	bl __umodsi3
	adds r5, r0, #0
	movs r1, #0xa
	bl __udivsi3
	strh r0, [r4, #0x1a]
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	strh r0, [r4, #0x1c]
	ldr r5, [sp]
	lsls r0, r5, #0x10
	cmp r0, #0
	bne _0800F392
	movs r3, #0xa
	adds r1, r4, #0
	adds r2, r4, #0
	adds r2, #0x1c
_0800F380:
	strh r3, [r1]
	adds r4, #2
	adds r1, #2
	cmp r1, r2
	bgt _0800F392
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0
	beq _0800F380
_0800F392:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F3A4: .4byte 0x05F5E0FF
_0800F3A8: .4byte gUnknown_0202C5C0
_0800F3AC: .4byte 0x000F4240
_0800F3B0: .4byte 0x000186A0
_0800F3B4: .4byte 0x00002710
_0800F3B8: .4byte 0x00989680

	thumb_func_start sub_F3BC
sub_F3BC: @ 0x0800F3BC
	cmp r0, r2
	bhi _0800F3C8
	cmp r0, r2
	blo _0800F3D4
	cmp r1, r3
	bls _0800F3CC
_0800F3C8:
	movs r0, #1
	b _0800F3D8
_0800F3CC:
	cmp r1, r3
	blo _0800F3D4
	movs r0, #0
	b _0800F3D8
_0800F3D4:
	movs r0, #1
	rsbs r0, r0, #0
_0800F3D8:
	bx lr

	thumb_func_start sub_F3DC
sub_F3DC: @ 0x0800F3DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	movs r6, #0
	ldr r7, _0800F414 @ =gUnknown_0202C610
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r1, r7, #0
	adds r1, #0x14
	adds r5, r0, r1
	adds r4, r0, #0
_0800F3FA:
	adds r0, r7, #0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r2, [r0]
	ldr r3, [r5]
	mov r0, sb
	mov r1, r8
	bl sub_F3BC
	cmp r0, #0
	blt _0800F418
	adds r0, r6, #0
	b _0800F426
	.align 2, 0
_0800F414: .4byte gUnknown_0202C610
_0800F418:
	adds r5, #0x18
	adds r4, #0x18
	adds r6, #1
	cmp r6, #7
	ble _0800F3FA
	movs r0, #1
	rsbs r0, r0, #0
_0800F426:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_F434
sub_F434: @ 0x0800F434
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	mov r8, r2
	mov sb, r3
	movs r5, #7
	ldr r0, _0800F4F8 @ =gUnknown_0202C610
	mov ip, r0
	cmp r5, sb
	ble _0800F4A4
	mov sl, ip
	lsls r0, r2, #1
	add r0, r8
	lsls r1, r0, #6
	mov r2, ip
	adds r0, r2, r1
	adds r3, r0, #0
	adds r3, #0x90
	adds r7, r1, #0
	adds r7, #0x90
	adds r6, r1, #0
	adds r6, #0xa8
	adds r0, r1, #0
	adds r0, #0xac
	adds r4, r0, r2
	subs r0, #0x18
	adds r2, r0, r2
_0800F474:
	ldr r0, [r3]
	str r0, [r3, #0x18]
	ldr r0, [r2]
	str r0, [r4]
	ldr r0, [r2, #4]
	str r0, [r4, #4]
	ldr r0, [r2, #8]
	str r0, [r4, #8]
	mov r0, sl
	adds r0, #0x10
	adds r1, r6, r0
	adds r0, r7, r0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r3, #0x14]
	str r0, [r3, #0x2c]
	subs r3, #0x18
	subs r2, #0x18
	subs r7, #0x18
	subs r4, #0x18
	subs r6, #0x18
	subs r5, #1
	cmp r5, sb
	bgt _0800F474
_0800F4A4:
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #3
	mov r2, r8
	lsls r0, r2, #1
	add r0, r8
	lsls r0, r0, #6
	adds r1, r1, r0
	mov r2, ip
	adds r0, r1, r2
	movs r2, #0
	str r2, [r0]
	mov r0, ip
	adds r0, #4
	adds r0, r1, r0
	str r2, [r0]
	mov r0, ip
	adds r0, #8
	adds r0, r1, r0
	str r2, [r0]
	mov r0, ip
	adds r0, #0xc
	adds r0, r1, r0
	str r2, [r0]
	mov r0, ip
	adds r0, #0x10
	adds r0, r1, r0
	ldr r2, [sp]
	str r2, [r0]
	mov r0, ip
	adds r0, #0x14
	adds r1, r1, r0
	ldr r0, [sp, #4]
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F4F8: .4byte gUnknown_0202C610

	thumb_func_start sub_F4FC
sub_F4FC: @ 0x0800F4FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	ldr r0, _0800F668 @ =gUnknown_0202C550
	mov r8, r0
	ldr r1, [sp]
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r0, r4, #3
	mov sb, r0
	mov r6, r8
	adds r6, #0x10
	add r6, sb
	ldr r0, [r6]
	mov r5, r8
	adds r5, #0x14
	add r5, sb
	ldr r1, [r5]
	ldr r2, [sp]
	bl sub_F3DC
	mov sl, r0
	ldr r7, _0800F66C @ =gUnknown_0202C610
	lsls r0, r0, #1
	add r0, sl
	lsls r0, r0, #3
	lsls r4, r4, #6
	adds r4, r0, r4
	adds r0, r7, #0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0]
	adds r1, r7, #0
	adds r1, #0x14
	adds r1, r4, r1
	ldr r1, [r1]
	ldr r2, [r6]
	ldr r3, [r5]
	bl sub_F3BC
	mov ip, r8
	cmp r0, #0
	bne _0800F5A2
	adds r0, r4, r7
	mov r1, sb
	add r1, ip
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne _0800F5A2
	adds r1, r7, #4
	adds r1, r4, r1
	mov r0, ip
	adds r0, #4
	add r0, sb
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	bne _0800F5A2
	adds r1, r7, #0
	adds r1, #8
	adds r1, r4, r1
	mov r0, ip
	adds r0, #8
	add r0, sb
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	bne _0800F5A2
	adds r1, r7, #0
	adds r1, #0xc
	adds r1, r4, r1
	mov r0, ip
	adds r0, #0xc
	add r0, sb
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800F656
_0800F5A2:
	movs r0, #1
	rsbs r0, r0, #0
	cmp sl, r0
	beq _0800F656
	movs r4, #7
	ldr r1, _0800F668 @ =gUnknown_0202C550
	mov ip, r1
	ldr r0, [sp]
	lsls r3, r0, #1
	ldr r1, _0800F66C @ =gUnknown_0202C610
	mov r8, r1
	cmp r4, sl
	ble _0800F5EA
	mov r7, r8
	adds r0, r3, r0
	lsls r6, r0, #6
_0800F5C2:
	movs r5, #0
	lsls r0, r4, #1
	subs r1, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r2, r0, r7
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r4, r0, r7
_0800F5DA:
	ldm r4!, {r0}
	stm r2!, {r0}
	adds r5, #1
	cmp r5, #5
	ble _0800F5DA
	adds r4, r1, #0
	cmp r4, sl
	bgt _0800F5C2
_0800F5EA:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #3
	ldr r4, [sp]
	adds r3, r3, r4
	lsls r0, r3, #6
	adds r2, r2, r0
	mov r0, r8
	adds r1, r2, r0
	lsls r3, r3, #3
	mov r4, ip
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r8
	adds r1, #4
	adds r1, r2, r1
	mov r0, ip
	adds r0, #4
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r8
	adds r1, #8
	adds r1, r2, r1
	mov r0, ip
	adds r0, #8
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r8
	adds r1, #0xc
	adds r1, r2, r1
	mov r0, ip
	adds r0, #0xc
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	mov r1, r8
	adds r1, #0x10
	adds r1, r2, r1
	mov r0, ip
	adds r0, #0x10
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r8
	adds r0, #0x14
	adds r2, r2, r0
	mov r0, ip
	adds r0, #0x14
	adds r3, r3, r0
	ldr r0, [r3]
	str r0, [r2]
_0800F656:
	mov r0, sl
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F668: .4byte gUnknown_0202C550
_0800F66C: .4byte gUnknown_0202C610

	thumb_func_start sub_F670
sub_F670: @ 0x0800F670
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r2
	ldr r2, _0800F6D8 @ =gUnknown_086A7FAC
	lsls r0, r7, #1
	adds r0, r0, r2
	ldrh r7, [r0]
	ldr r6, _0800F6DC @ =gUnknown_08079730
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r4, r0
	ldr r5, [r0]
	lsls r0, r5, #5
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, r6
	mov r2, r8
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r8, r2
	ldr r2, [r1]
	add r2, r8
	adds r6, #4
	adds r4, r4, r6
	ldr r3, [r4]
	movs r1, #1
	str r1, [sp]
	adds r5, #1
	str r5, [sp, #4]
	movs r1, #8
	bl sub_105A0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F6D8: .4byte gUnknown_086A7FAC
_0800F6DC: .4byte gUnknown_08079730

	thumb_func_start sub_F6E0
sub_F6E0: @ 0x0800F6E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r1, _0800F740 @ =gUnknown_0202BEB0
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	ldr r0, _0800F744 @ =gMain+0x74
	mov r8, r0
	ldr r3, _0800F748 @ =gUnknown_08079430
	mov ip, r3
_0800F6F8:
	movs r1, #0
	lsls r0, r2, #1
	adds r7, r2, #1
	mov sb, r7
	adds r0, r0, r2
	lsls r5, r0, #6
	adds r6, r5, #0
	adds r6, #0xe4
_0800F708:
	lsls r0, r1, #1
	adds r4, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r6
	add r1, r8
	adds r2, r0, r5
	movs r3, #5
_0800F718:
	mov r7, ip
	adds r0, r2, r7
	ldr r0, [r0]
	stm r1!, {r0}
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _0800F718
	adds r1, r4, #0
	cmp r1, #7
	ble _0800F708
	mov r2, sb
	cmp r2, #1
	ble _0800F6F8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F740: .4byte gUnknown_0202BEB0
_0800F744: .4byte gMain+0x74
_0800F748: .4byte gUnknown_08079430

	thumb_func_start sub_F74C
sub_F74C: @ 0x0800F74C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	movs r0, #0
	mov r8, r0
	ldr r1, _0800F85C @ =gMain+0x74
	str r1, [sp]
_0800F760:
	bl Random
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r3, r8
	lsls r2, r3, #1
	adds r1, r2, r3
	lsls r1, r1, #6
	ldr r3, _0800F860 @ =gUnknown_0200B218
	adds r0, r1, r3
	str r4, [r0]
	mov sb, r2
	mov r0, r8
	adds r0, #1
	str r0, [sp, #8]
	ldr r2, [sp]
	adds r1, r2, r1
	adds r6, r1, #0
	adds r6, #0xe8
	movs r5, #2
_0800F78E:
	bl Random
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _0800F7AE
	bl Random
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0800F7AE:
	stm r6!, {r4}
	subs r5, #1
	cmp r5, #0
	bge _0800F78E
	bl Random
	adds r7, r0, #0
	bl Random
	adds r6, r0, #0
	mov r0, sb
	add r0, r8
	lsls r0, r0, #6
	ldr r1, [sp]
	adds r1, #0xf4
	adds r1, r0, r1
	str r7, [r1]
	ldr r3, _0800F864 @ =gUnknown_0200B22C
	adds r1, r0, r3
	str r6, [r1]
	movs r1, #1
	mov r8, r1
	ldr r2, [sp]
	str r2, [sp, #4]
	mov sl, r0
_0800F7E0:
	bl Random
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r3, r8
	lsls r2, r3, #1
	adds r1, r2, r3
	lsls r1, r1, #3
	mov r3, sl
	adds r0, r1, r3
	ldr r3, _0800F860 @ =gUnknown_0200B218
	adds r0, r0, r3
	str r4, [r0]
	str r2, [sp, #0x10]
	mov r0, r8
	adds r0, #1
	str r0, [sp, #0xc]
	adds r1, #4
	movs r5, #2
	adds r0, r3, #0
	add r0, sl
	adds r1, r1, r0
	mov sb, r1
_0800F814:
	bl Random
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _0800F834
	bl Random
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0800F834:
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	stm r1!, {r4}
	subs r5, #1
	cmp r5, #0
	bge _0800F814
	bl Random
	adds r1, r7, #0
	bl __umodsi3
	adds r7, r0, #0
	cmp r7, #0
	beq _0800F868
	bl Random
	b _0800F872
	.align 2, 0
_0800F85C: .4byte gMain+0x74
_0800F860: .4byte gUnknown_0200B218
_0800F864: .4byte gUnknown_0200B22C
_0800F868:
	bl Random
	adds r1, r6, #0
	bl __umodsi3
_0800F872:
	adds r6, r0, #0
	ldr r1, [sp, #0x10]
	add r1, r8
	lsls r1, r1, #3
	add r1, sl
	ldr r0, [sp, #4]
	adds r0, #0xf4
	adds r0, r1, r0
	str r7, [r0]
	ldr r2, _0800F8AC @ =gUnknown_0200B22C
	adds r1, r1, r2
	str r6, [r1]
	ldr r3, [sp, #0xc]
	mov r8, r3
	cmp r3, #7
	ble _0800F7E0
	ldr r0, [sp, #8]
	mov r8, r0
	cmp r0, #1
	bgt _0800F89C
	b _0800F760
_0800F89C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800F8AC: .4byte gUnknown_0200B22C

	thumb_func_start sub_F8B0
sub_F8B0: @ 0x0800F8B0
	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	cmp r0, #0
	beq _0800F8BC
	b _0800F9CC
_0800F8BC:
	cmp r1, #0
	bne _0800F93C
	ldr r0, _0800F924 @ =gUnknown_03005C00
	ldr r7, _0800F928 @ =0x000090EA
	ldr r6, _0800F92C @ =0x0000912A
	ldr r1, _0800F930 @ =gUnknown_086A7FA4
	adds r2, r0, #0
	adds r2, #0x98
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800F8D4:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F8E8
	cmp r0, r6
	beq _0800F8E8
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800F8E8:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F8D4
	ldr r0, _0800F924 @ =gUnknown_03005C00
	ldr r7, _0800F934 @ =0x0000910A
	ldr r6, _0800F938 @ =0x0000914A
	ldr r1, _0800F930 @ =gUnknown_086A7FA4
	adds r3, r0, #0
	adds r3, #0xd8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800F904:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F918
	cmp r0, r6
	beq _0800F918
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800F918:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F904
	b _0800FAC2
	.align 2, 0
_0800F924: .4byte gUnknown_03005C00
_0800F928: .4byte 0x000090EA
_0800F92C: .4byte 0x0000912A
_0800F930: .4byte gUnknown_086A7FA4
_0800F934: .4byte 0x0000910A
_0800F938: .4byte 0x0000914A
_0800F93C:
	lsls r1, r1, #1
	adds r0, r1, #3
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	adds r6, r1, #0
	ldr r1, _0800F9B4 @ =gUnknown_03005C00
	ldr r0, _0800F9B8 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800F9BC @ =0x000091AA
	ldr r2, _0800F9C0 @ =gUnknown_086A7FA4
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800F95E:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800F972
	cmp r0, r7
	beq _0800F972
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800F972:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F95E
	adds r0, r6, #4
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	ldr r1, _0800F9B4 @ =gUnknown_03005C00
	ldr r7, _0800F9C4 @ =0x0000918A
	ldr r6, _0800F9C8 @ =0x000091CA
	ldr r2, _0800F9C0 @ =gUnknown_086A7FA4
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800F996:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800F9AA
	cmp r0, r6
	beq _0800F9AA
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800F9AA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F996
	b _0800FAC2
	.align 2, 0
_0800F9B4: .4byte gUnknown_03005C00
_0800F9B8: .4byte 0x0000916A
_0800F9BC: .4byte 0x000091AA
_0800F9C0: .4byte gUnknown_086A7FA4
_0800F9C4: .4byte 0x0000918A
_0800F9C8: .4byte 0x000091CA
_0800F9CC:
	cmp r1, #0
	bne _0800FA54
	ldr r0, _0800FA34 @ =gUnknown_03005C00
	ldr r7, _0800FA38 @ =0x000090EA
	ldr r6, _0800FA3C @ =0x0000912A
	ldr r1, _0800FA40 @ =gUnknown_086A7FA4
	ldr r3, _0800FA44 @ =0x00000894
	adds r2, r0, r3
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800F9E4:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800F9F8
	cmp r0, r6
	beq _0800F9F8
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800F9F8:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800F9E4
	ldr r0, _0800FA34 @ =gUnknown_03005C00
	ldr r7, _0800FA48 @ =0x0000910A
	ldr r6, _0800FA4C @ =0x0000914A
	ldr r1, _0800FA40 @ =gUnknown_086A7FA4
	ldr r4, _0800FA50 @ =0x000008D4
	adds r3, r0, r4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FA14:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FA28
	cmp r0, r6
	beq _0800FA28
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FA28:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FA14
	b _0800FAC2
	.align 2, 0
_0800FA34: .4byte gUnknown_03005C00
_0800FA38: .4byte 0x000090EA
_0800FA3C: .4byte 0x0000912A
_0800FA40: .4byte gUnknown_086A7FA4
_0800FA44: .4byte 0x00000894
_0800FA48: .4byte 0x0000910A
_0800FA4C: .4byte 0x0000914A
_0800FA50: .4byte 0x000008D4
_0800FA54:
	lsls r0, r1, #1
	lsls r3, r0, #6
	adds r6, r0, #0
	ldr r1, _0800FAC8 @ =gUnknown_03005C00
	ldr r0, _0800FACC @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FAD0 @ =0x000091AA
	ldr r2, _0800FAD4 @ =gUnknown_086A7FA4
	ldr r4, _0800FAD8 @ =0x000008D4
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FA72:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FA86
	cmp r0, r7
	beq _0800FA86
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FA86:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FA72
	lsls r3, r6, #6
	ldr r1, _0800FAC8 @ =gUnknown_03005C00
	ldr r7, _0800FADC @ =0x0000918A
	ldr r6, _0800FAE0 @ =0x000091CA
	ldr r2, _0800FAD4 @ =gUnknown_086A7FA4
	ldr r4, _0800FAE4 @ =0x00000914
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FAA6:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FABA
	cmp r0, r6
	beq _0800FABA
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FABA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FAA6
_0800FAC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FAC8: .4byte gUnknown_03005C00
_0800FACC: .4byte 0x0000916A
_0800FAD0: .4byte 0x000091AA
_0800FAD4: .4byte gUnknown_086A7FA4
_0800FAD8: .4byte 0x000008D4
_0800FADC: .4byte 0x0000918A
_0800FAE0: .4byte 0x000091CA
_0800FAE4: .4byte 0x00000914

	thumb_func_start sub_FAE8
sub_FAE8: @ 0x0800FAE8
	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	cmp r0, #0
	beq _0800FAF4
	b _0800FC04
_0800FAF4:
	cmp r1, #0
	bne _0800FB74
	ldr r0, _0800FB5C @ =gUnknown_03005C00
	ldr r7, _0800FB60 @ =0x000090EA
	ldr r6, _0800FB64 @ =0x0000912A
	ldr r1, _0800FB68 @ =gUnknown_086A7FA8
	adds r2, r0, #0
	adds r2, #0x98
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800FB0C:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FB20
	cmp r0, r6
	beq _0800FB20
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800FB20:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB0C
	ldr r0, _0800FB5C @ =gUnknown_03005C00
	ldr r7, _0800FB6C @ =0x0000910A
	ldr r6, _0800FB70 @ =0x0000914A
	ldr r1, _0800FB68 @ =gUnknown_086A7FA8
	adds r3, r0, #0
	adds r3, #0xd8
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FB3C:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FB50
	cmp r0, r6
	beq _0800FB50
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FB50:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB3C
	b _0800FCFA
	.align 2, 0
_0800FB5C: .4byte gUnknown_03005C00
_0800FB60: .4byte 0x000090EA
_0800FB64: .4byte 0x0000912A
_0800FB68: .4byte gUnknown_086A7FA8
_0800FB6C: .4byte 0x0000910A
_0800FB70: .4byte 0x0000914A
_0800FB74:
	lsls r1, r1, #1
	adds r0, r1, #3
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	adds r6, r1, #0
	ldr r1, _0800FBEC @ =gUnknown_03005C00
	ldr r0, _0800FBF0 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FBF4 @ =0x000091AA
	ldr r2, _0800FBF8 @ =gUnknown_086A7FA8
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FB96:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FBAA
	cmp r0, r7
	beq _0800FBAA
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FBAA:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FB96
	adds r0, r6, #4
	lsls r0, r0, #5
	adds r3, r0, #0
	adds r3, #0xc
	ldr r1, _0800FBEC @ =gUnknown_03005C00
	ldr r7, _0800FBFC @ =0x0000918A
	ldr r6, _0800FC00 @ =0x000091CA
	ldr r2, _0800FBF8 @ =gUnknown_086A7FA8
	lsls r0, r3, #1
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FBCE:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FBE2
	cmp r0, r6
	beq _0800FBE2
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FBE2:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FBCE
	b _0800FCFA
	.align 2, 0
_0800FBEC: .4byte gUnknown_03005C00
_0800FBF0: .4byte 0x0000916A
_0800FBF4: .4byte 0x000091AA
_0800FBF8: .4byte gUnknown_086A7FA8
_0800FBFC: .4byte 0x0000918A
_0800FC00: .4byte 0x000091CA
_0800FC04:
	cmp r1, #0
	bne _0800FC8C
	ldr r0, _0800FC6C @ =gUnknown_03005C00
	ldr r7, _0800FC70 @ =0x000090EA
	ldr r6, _0800FC74 @ =0x0000912A
	ldr r1, _0800FC78 @ =gUnknown_086A7FA8
	ldr r3, _0800FC7C @ =0x00000894
	adds r2, r0, r3
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r1
	movs r4, #0xe
_0800FC1C:
	ldrh r1, [r2]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FC30
	cmp r0, r6
	beq _0800FC30
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r1, r0
	strh r0, [r2]
_0800FC30:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FC1C
	ldr r0, _0800FC6C @ =gUnknown_03005C00
	ldr r7, _0800FC80 @ =0x0000910A
	ldr r6, _0800FC84 @ =0x0000914A
	ldr r1, _0800FC78 @ =gUnknown_086A7FA8
	ldr r4, _0800FC88 @ =0x000008D4
	adds r3, r0, r4
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r1
	movs r4, #0xe
_0800FC4C:
	ldrh r1, [r3]
	adds r0, r1, #0
	cmp r0, r7
	beq _0800FC60
	cmp r0, r6
	beq _0800FC60
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r1, r0
	strh r0, [r3]
_0800FC60:
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FC4C
	b _0800FCFA
	.align 2, 0
_0800FC6C: .4byte gUnknown_03005C00
_0800FC70: .4byte 0x000090EA
_0800FC74: .4byte 0x0000912A
_0800FC78: .4byte gUnknown_086A7FA8
_0800FC7C: .4byte 0x00000894
_0800FC80: .4byte 0x0000910A
_0800FC84: .4byte 0x0000914A
_0800FC88: .4byte 0x000008D4
_0800FC8C:
	lsls r0, r1, #1
	lsls r3, r0, #6
	adds r6, r0, #0
	ldr r1, _0800FD00 @ =gUnknown_03005C00
	ldr r0, _0800FD04 @ =0x0000916A
	mov ip, r0
	ldr r7, _0800FD08 @ =0x000091AA
	ldr r2, _0800FD0C @ =gUnknown_086A7FA8
	ldr r4, _0800FD10 @ =0x000008D4
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, r2
	movs r4, #0xe
_0800FCAA:
	ldrh r2, [r1]
	adds r0, r2, #0
	cmp r0, ip
	beq _0800FCBE
	cmp r0, r7
	beq _0800FCBE
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r2, r0
	strh r0, [r1]
_0800FCBE:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FCAA
	lsls r3, r6, #6
	ldr r1, _0800FD00 @ =gUnknown_03005C00
	ldr r7, _0800FD14 @ =0x0000918A
	ldr r6, _0800FD18 @ =0x000091CA
	ldr r2, _0800FD0C @ =gUnknown_086A7FA8
	ldr r4, _0800FD1C @ =0x00000914
	adds r0, r3, r4
	adds r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r2
	movs r4, #0xe
_0800FCDE:
	ldrh r3, [r1]
	adds r0, r3, #0
	cmp r0, r7
	beq _0800FCF2
	cmp r0, r6
	beq _0800FCF2
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r3, r0
	strh r0, [r1]
_0800FCF2:
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0800FCDE
_0800FCFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD00: .4byte gUnknown_03005C00
_0800FD04: .4byte 0x0000916A
_0800FD08: .4byte 0x000091AA
_0800FD0C: .4byte gUnknown_086A7FA8
_0800FD10: .4byte 0x000008D4
_0800FD14: .4byte 0x0000918A
_0800FD18: .4byte 0x000091CA
_0800FD1C: .4byte 0x00000914

	thumb_func_start sub_FD20
sub_FD20: @ 0x0800FD20
	sub sp, #0x19c
	movs r2, #0
	ldr r3, _0800FD48 @ =gMain+0x74
	mov r1, sp
_0800FD28:
	adds r0, r2, r3
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0xcc
	ble _0800FD28
	movs r2, #0
	mov r1, sp
_0800FD3A:
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #4
	beq _0800FD4C
	movs r0, #0
	b _0800FD56
	.align 2, 0
_0800FD48: .4byte gMain+0x74
_0800FD4C:
	adds r1, #2
	adds r2, #1
	cmp r2, #0xc8
	ble _0800FD3A
	movs r0, #1
_0800FD56:
	add sp, #0x19c
	bx lr

	thumb_func_start sub_FD5C
sub_FD5C: @ 0x0800FD5C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r4, _0800FDC8 @ =0x040000D4
	movs r6, #0xa0
	lsls r6, r6, #0x13
	str r6, [r4]
	ldr r2, _0800FDCC @ =gUnknown_0201A920
	str r2, [r4, #4]
	ldr r5, _0800FDD0 @ =0x80000200
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sp
	ldr r3, _0800FDD4 @ =0x00007FFF
	adds r0, r3, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _0800FDD8 @ =0xFFFFFC00
	adds r1, r2, r0
	str r1, [r4, #4]
	ldr r0, _0800FDDC @ =0x81000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r1, [r4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r2, r3
	str r2, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	str r2, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_1050C
	movs r7, #0
_0800FDAA:
	mov r0, r8
	cmp r0, #0
	beq _0800FDB4
	bl _call_via_r8
_0800FDB4:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FDE0
	ldr r0, _0800FDCC @ =gUnknown_0201A920
	b _0800FDE2
	.align 2, 0
_0800FDC8: .4byte 0x040000D4
_0800FDCC: .4byte gUnknown_0201A920
_0800FDD0: .4byte 0x80000200
_0800FDD4: .4byte 0x00007FFF
_0800FDD8: .4byte 0xFFFFFC00
_0800FDDC: .4byte 0x81000200
_0800FDE0:
	ldr r0, _0800FE00 @ =gUnknown_0201AD20
_0800FDE2:
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FDAA
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE00: .4byte gUnknown_0201AD20

	thumb_func_start sub_FE04
sub_FE04: @ 0x0800FE04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FE6C @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov r8, r0
	str r0, [r1]
	ldr r3, _0800FE70 @ =gUnknown_0201A520
	str r3, [r1, #4]
	ldr r4, _0800FE74 @ =0x80000200
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sp
	ldr r6, _0800FE78 @ =0x00007FFF
	adds r0, r6, #0
	strh r0, [r2]
	str r2, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r3, r2
	str r0, [r1, #4]
	ldr r0, _0800FE7C @ =0x81000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r3, [r1]
	movs r6, #0x80
	lsls r6, r6, #4
	adds r3, r3, r6
	str r3, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	adds r6, r1, #0
_0800FE4C:
	cmp r5, #0
	beq _0800FE54
	bl _call_via_r5
_0800FE54:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FE84
	ldr r0, _0800FE80 @ =gUnknown_0201A920
	str r0, [r6]
	mov r0, r8
	str r0, [r6, #4]
	b _0800FE8C
	.align 2, 0
_0800FE6C: .4byte 0x040000D4
_0800FE70: .4byte gUnknown_0201A520
_0800FE74: .4byte 0x80000200
_0800FE78: .4byte 0x00007FFF
_0800FE7C: .4byte 0x81000200
_0800FE80: .4byte gUnknown_0201A920
_0800FE84:
	ldr r0, _0800FEB4 @ =gUnknown_0201AD20
	str r0, [r6]
	mov r2, r8
	str r2, [r6, #4]
_0800FE8C:
	str r4, [r6, #8]
	ldr r0, [r6, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FE4C
	bl sub_10528
	bl MainLoopIter
	bl ClearGraphicsMemory
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FEB4: .4byte gUnknown_0201AD20

	thumb_func_start sub_FEB8
sub_FEB8: @ 0x0800FEB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r2
	ldr r4, _0800FF34 @ =0x040000D4
	str r0, [r4]
	ldr r2, _0800FF38 @ =gUnknown_0201A920
	str r2, [r4, #4]
	ldr r0, _0800FF3C @ =0x80000100
	str r0, [r4, #8]
	ldr r3, [r4, #8]
	str r1, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r2, r1
	str r3, [r4, #4]
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _0800FF40 @ =0xFFFFFC00
	adds r2, r2, r0
	str r2, [r4, #4]
	ldr r0, _0800FF44 @ =0x81000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r2, [r4]
	str r3, [r4, #4]
	ldr r5, _0800FF48 @ =0x80000200
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	str r3, [r4]
	movs r6, #0xa0
	lsls r6, r6, #0x13
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_1050C
	ldr r1, _0800FF4C @ =gMain
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r0, [r0]
	strh r0, [r1, #0x16]
	movs r7, #0
_0800FF18:
	mov r1, r8
	cmp r1, #0
	beq _0800FF22
	bl _call_via_r8
_0800FF22:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FF50
	ldr r0, _0800FF38 @ =gUnknown_0201A920
	b _0800FF52
	.align 2, 0
_0800FF34: .4byte 0x040000D4
_0800FF38: .4byte gUnknown_0201A920
_0800FF3C: .4byte 0x80000100
_0800FF40: .4byte 0xFFFFFC00
_0800FF44: .4byte 0x81000200
_0800FF48: .4byte 0x80000200
_0800FF4C: .4byte gMain
_0800FF50:
	ldr r0, _0800FF70 @ =gUnknown_0201AD20
_0800FF52:
	str r0, [r4]
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FF18
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FF70: .4byte gUnknown_0201AD20

	thumb_func_start sub_FF74
sub_FF74: @ 0x0800FF74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FFDC @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov r8, r0
	str r0, [r1]
	ldr r3, _0800FFE0 @ =gUnknown_0201A520
	str r3, [r1, #4]
	ldr r4, _0800FFE4 @ =0x80000200
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	mov r2, sp
	movs r0, #0
	strh r0, [r2]
	str r2, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r3, r2
	str r0, [r1, #4]
	ldr r0, _0800FFE8 @ =0x81000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	str r3, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r3, r0
	str r3, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	adds r6, r1, #0
_0800FFBA:
	cmp r5, #0
	beq _0800FFC2
	bl _call_via_r5
_0800FFC2:
	adds r0, r7, #0
	bl sub_1001C
	bl MainLoopIter
	cmp r7, #0x1f
	bne _0800FFF0
	ldr r0, _0800FFEC @ =gUnknown_0201A920
	str r0, [r6]
	mov r2, r8
	str r2, [r6, #4]
	b _0800FFF8
	.align 2, 0
_0800FFDC: .4byte 0x040000D4
_0800FFE0: .4byte gUnknown_0201A520
_0800FFE4: .4byte 0x80000200
_0800FFE8: .4byte 0x81000200
_0800FFEC: .4byte gUnknown_0201A920
_0800FFF0:
	ldr r0, _08010018 @ =gUnknown_0201AD20
	str r0, [r6]
	mov r0, r8
	str r0, [r6, #4]
_0800FFF8:
	str r4, [r6, #8]
	ldr r0, [r6, #8]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0x1f
	bls _0800FFBA
	bl MainLoopIter
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010018: .4byte gUnknown_0201AD20

	thumb_func_start sub_1001C
sub_1001C: @ 0x0801001C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	add r1, sp, #0xc
	movs r0, #0
	strh r0, [r1]
	movs r0, #2
	strh r0, [r1, #2]
	movs r0, #1
	strh r0, [r1, #4]
	movs r2, #3
	strh r2, [r1, #6]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	lsls r0, r0, #0x17
	lsrs r1, r0, #0x10
	mov ip, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _080100D8 @ =0x0000FFFC
	ands r7, r0
	adds r0, r7, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp ip, r8
	bhs _08010160
	add r5, sp, #8
	ldr r0, _080100DC @ =gUnknown_0201A520
	mov sb, r0
	add r4, sp, #4
	mov r6, sp
	movs r1, #0xf8
	lsls r1, r1, #7
	mov sl, r1
_08010076:
	mov r0, ip
	lsls r3, r0, #1
	mov r1, sb
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6, #2]
	ldrh r1, [r6]
	cmp r1, r0
	bhs _080100E0
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r6]
	b _080100EE
	.align 2, 0
_080100D8: .4byte 0x0000FFFC
_080100DC: .4byte gUnknown_0201A520
_080100E0:
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r6]
_080100EE:
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bhs _08010106
	ldrh r0, [r4, #2]
	ldrh r1, [r4]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r4]
	b _08010114
_08010106:
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r4]
_08010114:
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bhs _0801012C
	ldrh r0, [r5, #2]
	ldrh r1, [r5]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5]
	b _0801013A
_0801012C:
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r5]
_0801013A:
	movs r2, #0x80
	lsls r2, r2, #4
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, r8
	blo _08010076
_08010160:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_10170
sub_10170: @ 0x08010170
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r1, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	mov r8, r1
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov ip, r3
	ldr r1, _08010298 @ =0x040000D4
	str r0, [r1]
	ldr r4, _0801029C @ =gUnknown_0201A520
	str r4, [r1, #4]
	lsrs r2, r2, #0x11
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r3, sp, #0xc
	movs r0, #0
	strh r0, [r3]
	str r3, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r3, r4, r0
	str r3, [r1, #4]
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #0
	cmp r7, r8
	bhs _08010270
	add r5, sp, #8
	add r4, sp, #4
	movs r1, #0xf8
	lsls r1, r1, #2
	mov sl, r1
	mov r6, sp
	movs r0, #0xf8
	lsls r0, r0, #7
	mov sb, r0
_080101D0:
	lsls r3, r7, #1
	ldr r1, _0801029C @ =gUnknown_0201A520
	adds r2, r3, r1
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	ldr r0, _080102A0 @ =gUnknown_0201A920
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	lsrs r1, r0, #0xa
	strh r1, [r6, #2]
	ldrh r0, [r6]
	cmp r0, r1
	bls _08010222
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_08010222:
	strh r1, [r6]
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bls _08010236
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_08010236:
	strh r1, [r4]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bls _0801024A
	adds r1, r0, #0
	mov r0, ip
	muls r0, r1, r0
	asrs r0, r0, #5
	subs r1, r1, r0
_0801024A:
	strh r1, [r5]
	ldr r1, _0801029C @ =gUnknown_0201A520
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r1, r0
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, r8
	blo _080101D0
_08010270:
	ldr r2, _08010298 @ =0x040000D4
	ldr r1, _080102A4 @ =gUnknown_0201AD20
	str r1, [r2]
	ldr r0, [sp, #0x10]
	str r0, [r2, #4]
	mov r1, r8
	lsrs r0, r1, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010298: .4byte 0x040000D4
_0801029C: .4byte gUnknown_0201A520
_080102A0: .4byte gUnknown_0201A920
_080102A4: .4byte gUnknown_0201AD20

	thumb_func_start sub_102A8
sub_102A8: @ 0x080102A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r1, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	mov r8, r1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	ldr r1, _08010368 @ =0x040000D4
	str r0, [r1]
	ldr r4, _0801036C @ =gUnknown_0201A520
	str r4, [r1, #4]
	lsrs r2, r2, #0x11
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r3, sp, #0xc
	ldr r5, _08010370 @ =0x00007FFF
	adds r0, r5, #0
	strh r0, [r3]
	str r3, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r4, r3
	str r0, [r1, #4]
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r2, r0
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0
	mov ip, r5
	cmp ip, r8
	bhs _080103F4
	add r5, sp, #8
	mov sb, r4
	add r4, sp, #4
	mov r6, sp
	movs r0, #0xf8
	lsls r0, r0, #7
	mov sl, r0
_08010306:
	mov r1, ip
	lsls r3, r1, #1
	mov r0, sb
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #3
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r2]
	movs r0, #0x1f
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strh r0, [r4, #2]
	ldrh r1, [r2]
	mov r0, sl
	ands r0, r1
	lsrs r0, r0, #0xa
	strh r0, [r6, #2]
	ldrh r1, [r6]
	cmp r1, r0
	bhs _08010374
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r6]
	b _08010382
	.align 2, 0
_08010368: .4byte 0x040000D4
_0801036C: .4byte gUnknown_0201A520
_08010370: .4byte 0x00007FFF
_08010374:
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r6]
_08010382:
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	cmp r0, r1
	bhs _0801039A
	ldrh r0, [r4, #2]
	ldrh r1, [r4]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r4]
	b _080103A8
_0801039A:
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r4]
_080103A8:
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r0, r1
	bhs _080103C0
	ldrh r0, [r5, #2]
	ldrh r1, [r5]
	subs r0, r0, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5]
	b _080103CE
_080103C0:
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	subs r1, r0, r1
	muls r1, r7, r1
	asrs r1, r1, #5
	subs r0, r0, r1
	strh r0, [r5]
_080103CE:
	movs r2, #0x80
	lsls r2, r2, #4
	add r2, sb
	adds r2, r3, r2
	ldrh r1, [r6]
	lsls r1, r1, #0xa
	ldrh r0, [r4]
	lsls r0, r0, #5
	orrs r1, r0
	ldrh r0, [r5]
	orrs r1, r0
	strh r1, [r2]
	mov r0, ip
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	cmp ip, r8
	blo _08010306
_080103F4:
	ldr r2, _0801041C @ =0x040000D4
	ldr r1, _08010420 @ =gUnknown_0201AD20
	str r1, [r2]
	ldr r3, [sp, #0x10]
	str r3, [r2, #4]
	mov r5, r8
	lsrs r0, r5, #1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801041C: .4byte 0x040000D4
_08010420: .4byte gUnknown_0201AD20

	thumb_func_start sub_10424
sub_10424: @ 0x08010424
	push {r4, r5, r6, lr}
	ldr r4, _08010470 @ =0x04000054
	movs r3, #0x10
	strh r3, [r4]
	ldr r6, _08010474 @ =0x04000050
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r6]
	ldrh r1, [r2]
	ldr r0, _08010478 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0801047C @ =gMain
	ldrh r0, [r2]
	movs r5, #0
	strh r0, [r1, #0x16]
	strh r3, [r4]
	bl MainLoopIter
	movs r0, #8
	strh r0, [r4]
	bl MainLoopIter
	strh r5, [r4]
	bl MainLoopIter
	strh r5, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010470: .4byte 0x04000054
_08010474: .4byte 0x04000050
_08010478: .4byte 0x0000FF7F
_0801047C: .4byte gMain

	thumb_func_start sub_10480
sub_10480: @ 0x08010480
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, _080104F8 @ =0x04000054
	movs r4, #0
	strh r4, [r5]
	ldr r2, _080104FC @ =0x04000050
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r2]
	strh r4, [r5]
	bl MainLoopIter
	movs r0, #8
	strh r0, [r5]
	bl MainLoopIter
	movs r0, #0x10
	strh r0, [r5]
	bl MainLoopIter
	mov r0, sp
	strh r4, [r0]
	ldr r1, _08010500 @ =0x040000D4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08010504 @ =0x8100C000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08010508 @ =0x04000010
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	bl MainLoopIter
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080104F8: .4byte 0x04000054
_080104FC: .4byte 0x04000050
_08010500: .4byte 0x040000D4
_08010504: .4byte 0x8100C000
_08010508: .4byte 0x04000010

	thumb_func_start sub_1050C
sub_1050C: @ 0x0801050C
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _08010520 @ =0x0000FF7F
	ands r0, r2
	strh r0, [r1]
	ldr r2, _08010524 @ =gMain
	ldrh r0, [r1]
	strh r0, [r2, #0x16]
	bx lr
	.align 2, 0
_08010520: .4byte 0x0000FF7F
_08010524: .4byte gMain

	thumb_func_start sub_10528
sub_10528: @ 0x08010528
	ldr r1, _08010540 @ =gMain
	ldrh r0, [r1, #0x16]
	movs r2, #0x80
	orrs r0, r2
	strh r0, [r1, #0x16]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08010540: .4byte gMain

	thumb_func_start sub_10544
sub_10544: @ 0x08010544
	ldr r1, _08010580 @ =0x04000004
	ldrh r2, [r1]
	ldr r0, _08010584 @ =0x0000FFF7
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08010588 @ =0x0000FFDF
	ands r0, r2
	strh r0, [r1]
	ldr r1, _0801058C @ =0x04000200
	ldrh r2, [r1]
	ldr r0, _08010590 @ =0x00003FFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08010594 @ =0x00003FFE
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	bne _08010574
	ldr r0, _08010598 @ =0x04000208
	strh r1, [r0]
_08010574:
	ldr r0, _0801059C @ =0x04000202
	ldrh r1, [r0]
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08010580: .4byte 0x04000004
_08010584: .4byte 0x0000FFF7
_08010588: .4byte 0x0000FFDF
_0801058C: .4byte 0x04000200
_08010590: .4byte 0x00003FFF
_08010594: .4byte 0x00003FFE
_08010598: .4byte 0x04000208
_0801059C: .4byte 0x04000202

	thumb_func_start sub_105A0
sub_105A0: @ 0x080105A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x24]
	mov ip, r4
	ldr r4, [sp, #0x28]
	mov sb, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	movs r1, #0
	cmp r1, sb
	bge _08010602
	lsls r0, r3, #5
	adds r0, r0, r2
	mov r8, r0
_080105CC:
	movs r2, #0
	adds r6, r1, #1
	cmp r2, ip
	bge _080105FA
	ldr r7, _08010614 @ =gUnknown_03005C00
	lsls r0, r1, #5
	mov r1, r8
	adds r5, r1, r0
	ldr r1, [sp]
	adds r4, r1, r0
	mov r0, sl
	lsls r3, r0, #0xc
_080105E4:
	adds r0, r5, r2
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r1, r2, r4
	orrs r1, r3
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, ip
	blt _080105E4
_080105FA:
	lsls r0, r6, #0x10
	lsrs r1, r0, #0x10
	cmp r1, sb
	blt _080105CC
_08010602:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010614: .4byte gUnknown_03005C00

	thumb_func_start sub_10618
sub_10618: @ 0x08010618
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r7, [sp, #0x20]
	ldr r0, [sp, #0x24]
	mov ip, r0
	movs r1, #0
	cmp r1, ip
	bge _08010678
	ldr r0, _08010688 @ =gUnknown_03005C00
	mov sl, r0
	lsls r0, r3, #5
	adds r0, r0, r2
	mov sb, r0
	lsls r0, r4, #5
	adds r0, r0, r5
	mov r8, r0
_08010642:
	movs r2, #0
	adds r6, r1, #1
	cmp r2, r7
	bge _08010670
	mov r4, sl
	lsls r0, r1, #5
	mov r1, sb
	adds r5, r1, r0
	mov r1, r8
	adds r3, r1, r0
_08010656:
	adds r1, r5, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	adds r0, r3, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r7
	blt _08010656
_08010670:
	lsls r0, r6, #0x10
	lsrs r1, r0, #0x10
	cmp r1, ip
	blt _08010642
_08010678:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010688: .4byte gUnknown_03005C00
