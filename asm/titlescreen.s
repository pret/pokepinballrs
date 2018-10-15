	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start TitlescreenMain
TitlescreenMain: @ 0x08010924
	push {lr}
	ldr r1, _0801093C @ =0x08079890
	ldr r0, _08010940 @ =0x0200B0C0
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0801093C: .4byte 0x08079890
_08010940: .4byte 0x0200B0C0

	thumb_func_start LoadTitlescreenGraphics
LoadTitlescreenGraphics: @ 0x08010944
	push {r4, r5, lr}
	bl sub_438
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _080109BC @ =0x0400000A
	movs r0, #0x85
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _080109C0 @ =0x0200B0C0
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	ldr r5, _080109C4 @ =0x040000D4
	ldr r0, _080109C8 @ =gTitlescreenBg_Gfx
	str r0, [r5]
	ldr r0, _080109CC @ =0x06004000
	str r0, [r5, #4]
	ldr r0, _080109D0 @ =0x80005000
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _080109D4 @ =gTitlescreenBg_Pals
	str r0, [r5]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r5, #4]
	ldr r0, _080109D8 @ =0x80000100
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _080109DC @ =gTitlescreenBgTilemap
	str r0, [r5]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r5, #4]
	ldr r0, _080109E0 @ =0x80000400
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	bl sub_52C44
	ldr r0, [r4, #0x40]
	cmp r0, #1
	bne _080109F4
	ldr r0, _080109E4 @ =gTitlescreenSprites_Pals
	str r0, [r5]
	ldr r0, _080109E8 @ =0x05000200
	str r0, [r5, #4]
	ldr r0, _080109EC @ =0x80000050
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _080109F0 @ =gTitlescreenSpritesSavedGame_Gfx
	b _08010A04
	.align 2, 0
_080109BC: .4byte 0x0400000A
_080109C0: .4byte 0x0200B0C0
_080109C4: .4byte 0x040000D4
_080109C8: .4byte gTitlescreenBg_Gfx
_080109CC: .4byte 0x06004000
_080109D0: .4byte 0x80005000
_080109D4: .4byte gTitlescreenBg_Pals
_080109D8: .4byte 0x80000100
_080109DC: .4byte gTitlescreenBgTilemap
_080109E0: .4byte 0x80000400
_080109E4: .4byte gTitlescreenSprites_Pals
_080109E8: .4byte 0x05000200
_080109EC: .4byte 0x80000050
_080109F0: .4byte gTitlescreenSpritesSavedGame_Gfx
_080109F4:
	ldr r0, _08010A5C @ =gTitlescreenSprites_Pals
	str r0, [r5]
	ldr r0, _08010A60 @ =0x05000200
	str r0, [r5, #4]
	ldr r0, _08010A64 @ =0x80000050
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _08010A68 @ =gTitlescreenSpritesNoSavedGame_Gfx
_08010A04:
	str r0, [r5]
	ldr r0, _08010A6C @ =0x06010000
	str r0, [r5, #4]
	ldr r0, _08010A70 @ =0x80003800
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _08010A74 @ =0x0852B668
	str r0, [r5]
	ldr r0, _08010A78 @ =0x050002A0
	str r0, [r5, #4]
	ldr r0, _08010A7C @ =0x80000020
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _08010A80 @ =0x0852B868
	str r0, [r5]
	ldr r0, _08010A84 @ =0x06017000
	str r0, [r5, #4]
	ldr r0, _08010A88 @ =0x80000200
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	bl sub_10AC0
	ldr r0, _08010A8C @ =0x0201A4B4
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	bne _08010A9C
	ldr r1, _08010A90 @ =0x0202BE24
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08010A94 @ =0x02002888
	movs r0, #0
	strb r0, [r1, #9]
	strb r2, [r1, #0xb]
	ldr r1, _08010A98 @ =0x0200B0C0
	movs r0, #3
	strb r0, [r1, #3]
	bl sub_CBC
	movs r0, #0
	bl sub_FD5C
	b _08010AAC
	.align 2, 0
_08010A5C: .4byte gTitlescreenSprites_Pals
_08010A60: .4byte 0x05000200
_08010A64: .4byte 0x80000050
_08010A68: .4byte gTitlescreenSpritesNoSavedGame_Gfx
_08010A6C: .4byte 0x06010000
_08010A70: .4byte 0x80003800
_08010A74: .4byte 0x0852B668
_08010A78: .4byte 0x050002A0
_08010A7C: .4byte 0x80000020
_08010A80: .4byte 0x0852B868
_08010A84: .4byte 0x06017000
_08010A88: .4byte 0x80000200
_08010A8C: .4byte 0x0201A4B4
_08010A90: .4byte 0x0202BE24
_08010A94: .4byte 0x02002888
_08010A98: .4byte 0x0200B0C0
_08010A9C:
	ldr r0, _08010AB8 @ =0x0200B0C0
	movs r1, #1
	strb r1, [r0, #3]
	bl sub_CBC
	ldr r0, _08010ABC @ =sub_11640 + 1
	bl sub_FD5C
_08010AAC:
	movs r0, #1
	bl m4aSongNumStart
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010AB8: .4byte 0x0200B0C0
_08010ABC: .4byte sub_11640 + 1

	thumb_func_start sub_10AC0
sub_10AC0: @ 0x08010AC0
	push {r4, r5, r6, r7, lr}
	ldr r1, _08010B28 @ =0x02002888
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	strb r2, [r1, #6]
	strb r2, [r1, #8]
	movs r0, #4
	strb r0, [r1, #0x10]
	movs r3, #1
	strb r3, [r1, #9]
	strb r2, [r1, #0x11]
	movs r0, #6
	strb r0, [r1, #0xa]
	strb r2, [r1, #0xc]
	movs r0, #3
	strb r0, [r1, #0xe]
	strb r2, [r1, #0xb]
	strb r2, [r1, #0xd]
	strb r2, [r1, #0xf]
	ldr r0, _08010B2C @ =0x0202C588
	strh r3, [r0]
	ldr r0, _08010B30 @ =0x020028A0
	strb r2, [r0]
	ldr r0, _08010B34 @ =0x020028A1
	strb r2, [r0]
	ldr r0, _08010B38 @ =0x020028A2
	strb r2, [r0]
	ldr r0, _08010B3C @ =0x020028A3
	strb r2, [r0]
	ldr r0, _08010B40 @ =0x0200B0C0
	ldr r2, [r0, #0x40]
	adds r6, r0, #0
	cmp r2, #1
	bne _08010B58
	ldr r7, _08010B44 @ =0x020028A4
	ldr r5, _08010B48 @ =0x020028A5
	ldr r0, _08010B4C @ =0x0202BE24
	mov ip, r0
	ldr r4, _08010B50 @ =0x086A975C
	ldr r3, _08010B54 @ =0x0202BE00
	movs r2, #6
_08010B16:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _08010B16
	movs r0, #1
	strb r0, [r1]
	strb r0, [r1, #7]
	b _08010B78
	.align 2, 0
_08010B28: .4byte 0x02002888
_08010B2C: .4byte 0x0202C588
_08010B30: .4byte 0x020028A0
_08010B34: .4byte 0x020028A1
_08010B38: .4byte 0x020028A2
_08010B3C: .4byte 0x020028A3
_08010B40: .4byte 0x0200B0C0
_08010B44: .4byte 0x020028A4
_08010B48: .4byte 0x020028A5
_08010B4C: .4byte 0x0202BE24
_08010B50: .4byte 0x086A975C
_08010B54: .4byte 0x0202BE00
_08010B58:
	ldr r7, _08010B94 @ =0x020028A4
	ldr r5, _08010B98 @ =0x020028A5
	ldr r0, _08010B9C @ =0x0202BE24
	mov ip, r0
	ldr r4, _08010BA0 @ =0x086A96F8
	ldr r3, _08010BA4 @ =0x0201C190
	movs r2, #6
_08010B66:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _08010B66
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #7]
	strb r0, [r6, #0xd]
_08010B78:
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x14]
	movs r0, #1
	strh r0, [r1, #0x12]
	strb r2, [r7]
	ldrh r1, [r6, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08010BA8
	movs r0, #1
	strb r0, [r5]
	b _08010BAA
	.align 2, 0
_08010B94: .4byte 0x020028A4
_08010B98: .4byte 0x020028A5
_08010B9C: .4byte 0x0202BE24
_08010BA0: .4byte 0x086A96F8
_08010BA4: .4byte 0x0201C190
_08010BA8:
	strb r2, [r5]
_08010BAA:
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_10BB8
sub_10BB8: @ 0x08010BB8
	push {r4, r5, r6, r7, lr}
	ldr r2, _08010BE8 @ =0x0200B0C0
	ldrh r1, [r2, #0x1c]
	movs r0, #0xf
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0xf
	bne _08010BF8
	ldr r0, _08010BEC @ =0x020028A5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _08010BF0 @ =0x020028A4
	cmp r0, #0
	bne _08010C00
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08010BF4 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r7, #3]
	b _08010C00
	.align 2, 0
_08010BE8: .4byte 0x0200B0C0
_08010BEC: .4byte 0x020028A5
_08010BF0: .4byte 0x020028A4
_08010BF4: .4byte 0x02002888
_08010BF8:
	ldr r1, _08010CD4 @ =0x020028A5
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08010CD8 @ =0x020028A4
_08010C00:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08010CC8
	ldr r2, _08010CDC @ =0x02002888
	ldrh r0, [r2, #4]
	adds r0, #1
	strh r0, [r2, #4]
	ldr r3, _08010CE0 @ =0x086A9662
	movs r1, #8
	ldrsb r1, [r2, r1]
	adds r1, r1, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08010C3A
	strh r4, [r2, #4]
	ldrb r0, [r2, #8]
	adds r0, #1
	strb r0, [r2, #8]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _08010C3A
	movs r0, #0
	strb r0, [r2, #8]
_08010C3A:
	adds r4, r7, #0
	ldrh r1, [r4, #0x1c]
	ldr r0, _08010CE4 @ =0x000003FF
	ands r0, r1
	cmp r0, #0
	beq _08010C4A
	movs r0, #0
	strh r0, [r2, #0x14]
_08010C4A:
	ldrh r1, [r4, #0x18]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _08010C66
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _08010CDC @ =0x02002888
	movs r0, #0
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	movs r0, #2
	strb r0, [r4, #3]
_08010C66:
	bl sub_114FC
	bl sub_1157C
	ldr r6, _08010CDC @ =0x02002888
	ldrh r0, [r6, #0x14]
	adds r0, #1
	strh r0, [r6, #0x14]
	lsls r0, r0, #0x10
	movs r1, #0xe1
	lsls r1, r1, #0x13
	cmp r0, r1
	ble _08010CC8
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08010CB4
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
	ldr r4, _08010CE8 @ =0x02032EE0
	ldr r5, _08010CEC @ =0x0000FFFF
	movs r0, #0x12
	ldrsh r1, [r6, r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl __divsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl m4aMPlayVolumeControl
_08010CB4:
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	cmp r0, #9
	ble _08010CC8
	movs r0, #0
	strh r0, [r6, #0x14]
	movs r0, #7
	strb r0, [r6, #6]
	movs r0, #0xb
	strb r0, [r7, #3]
_08010CC8:
	bl sub_11640
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010CD4: .4byte 0x020028A5
_08010CD8: .4byte 0x020028A4
_08010CDC: .4byte 0x02002888
_08010CE0: .4byte 0x086A9662
_08010CE4: .4byte 0x000003FF
_08010CE8: .4byte 0x02032EE0
_08010CEC: .4byte 0x0000FFFF

	thumb_func_start sub_10CF0
sub_10CF0: @ 0x08010CF0
	push {r4, r5, r6, r7, lr}
	ldr r6, _08010D70 @ =0x0200B0C0
	ldrh r1, [r6, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _08010D74 @ =0x020028A4
	cmp r0, #0xf
	bne _08010D0E
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08010D78 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r6, #3]
_08010D0E:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08010D66
	ldr r3, _08010D78 @ =0x02002888
	ldrh r0, [r3, #4]
	adds r0, #1
	movs r7, #0
	strh r0, [r3, #4]
	ldr r5, _08010D7C @ =0x086A9666
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	adds r2, r5, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08010D66
	strh r4, [r3, #4]
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r3, #8]
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08010D66
	strh r4, [r3, #2]
	ldr r0, _08010D80 @ =0x0202BE24
	strb r7, [r0]
	strb r7, [r3, #9]
	movs r0, #1
	strb r0, [r3, #0xb]
	movs r0, #3
	strb r0, [r6, #3]
_08010D66:
	bl sub_11640
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010D70: .4byte 0x0200B0C0
_08010D74: .4byte 0x020028A4
_08010D78: .4byte 0x02002888
_08010D7C: .4byte 0x086A9666
_08010D80: .4byte 0x0202BE24

	thumb_func_start sub_10D84
sub_10D84: @ 0x08010D84
	push {r4, r5, r6, lr}
	ldr r6, _08010DD0 @ =0x0200B0C0
	ldrh r1, [r6, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _08010DD4 @ =0x020028A4
	cmp r0, #0xf
	bne _08010DA2
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08010DD8 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xa
	strb r0, [r6, #3]
_08010DA2:
	movs r5, #0
	ldrsb r5, [r2, r5]
	cmp r5, #0
	bne _08010DF2
	ldrh r1, [r6, #0x18]
	movs r4, #1
	ands r4, r1
	cmp r4, #0
	beq _08010DDC
	movs r0, #0x65
	bl m4aSongNumStart
	bl sub_11B74
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	strb r5, [r6, #3]
	b _08010DF2
	.align 2, 0
_08010DD0: .4byte 0x0200B0C0
_08010DD4: .4byte 0x020028A4
_08010DD8: .4byte 0x02002888
_08010DDC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08010DF2
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r0, _08010DFC @ =0x02002888
	strb r4, [r0, #0x11]
	movs r0, #1
	strb r0, [r6, #3]
_08010DF2:
	bl sub_11640
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010DFC: .4byte 0x02002888

	thumb_func_start sub_10E00
sub_10E00: @ 0x08010E00
	push {r4, r5, r6, lr}
	ldr r5, _08010E7C @ =0x0200B0C0
	ldrh r1, [r5, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _08010E80 @ =0x020028A4
	cmp r0, #0xf
	bne _08010E1E
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08010E84 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r5, #3]
_08010E1E:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08010EE0
	ldr r3, _08010E84 @ =0x02002888
	ldrb r0, [r3, #7]
	cmp r0, #0
	bne _08010E94
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r2, _08010E88 @ =0x086A9748
	movs r6, #2
	ldrsh r1, [r3, r6]
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08010E76
	strh r4, [r3, #4]
	ldr r2, _08010E8C @ =0x0201C190
	ldr r1, _08010E90 @ =0x086A9714
	movs r6, #2
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #0x18]
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _08010E76
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xf]
	movs r0, #4
	strb r0, [r5, #3]
_08010E76:
	bl sub_1175C
	b _08010EE0
	.align 2, 0
_08010E7C: .4byte 0x0200B0C0
_08010E80: .4byte 0x020028A4
_08010E84: .4byte 0x02002888
_08010E88: .4byte 0x086A9748
_08010E8C: .4byte 0x0201C190
_08010E90: .4byte 0x086A9714
_08010E94:
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r2, _08010EE8 @ =0x086A9748
	movs r6, #2
	ldrsh r1, [r3, r6]
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08010EDC
	strh r4, [r3, #4]
	ldr r2, _08010EEC @ =0x0202BE00
	ldr r1, _08010EF0 @ =0x086A9778
	movs r6, #2
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #0x18]
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _08010EDC
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3, #0xd]
	strb r0, [r3, #0xf]
	movs r0, #5
	strb r0, [r5, #3]
_08010EDC:
	bl sub_11968
_08010EE0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010EE8: .4byte 0x086A9748
_08010EEC: .4byte 0x0202BE00
_08010EF0: .4byte 0x086A9778

	thumb_func_start sub_10EF4
sub_10EF4: @ 0x08010EF4
	push {r4, r5, lr}
	ldr r3, _08010F94 @ =0x0200B0C0
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _08010F98 @ =0x020028A4
	cmp r0, #0xf
	bne _08010F12
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08010F9C @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xa
	strb r0, [r3, #3]
_08010F12:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08011010
	ldr r3, _08010F9C @ =0x02002888
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r5, _08010FA0 @ =0x086A9672
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	adds r2, r5, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08010F68
	strh r4, [r3, #4]
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _08010F4E
	strh r4, [r3, #2]
_08010F4E:
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r3, #0xc]
	movs r2, #2
	ldrsh r0, [r3, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #3
	strb r0, [r3, #0xe]
_08010F68:
	ldr r0, _08010F94 @ =0x0200B0C0
	ldrh r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08010FA4
	movs r0, #0x67
	bl m4aSongNumStart
	ldr r1, _08010F9C @ =0x02002888
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08010FC4
	movs r0, #3
	strb r0, [r1]
	b _08010FC4
	.align 2, 0
_08010F94: .4byte 0x0200B0C0
_08010F98: .4byte 0x020028A4
_08010F9C: .4byte 0x02002888
_08010FA0: .4byte 0x086A9672
_08010FA4:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08010FC4
	movs r0, #0x67
	bl m4aSongNumStart
	ldr r1, _08010FE4 @ =0x02002888
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _08010FC4
	strb r4, [r1]
_08010FC4:
	ldr r5, _08010FE8 @ =0x0200B0C0
	ldrh r1, [r5, #0x18]
	movs r4, #9
	ands r4, r1
	cmp r4, #0
	beq _08010FEC
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _08010FE4 @ =0x02002888
	movs r0, #0
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	movs r0, #7
	b _0801100A
	.align 2, 0
_08010FE4: .4byte 0x02002888
_08010FE8: .4byte 0x0200B0C0
_08010FEC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801100C
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r1, _0801101C @ =0x02002888
	movs r2, #0
	strh r4, [r1, #4]
	movs r0, #0xc
	strh r0, [r1, #2]
	strb r2, [r1, #0xd]
	strb r2, [r1, #0xf]
	movs r0, #6
_0801100A:
	strb r0, [r5, #3]
_0801100C:
	bl sub_1157C
_08011010:
	bl sub_1175C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801101C: .4byte 0x02002888

	thumb_func_start sub_11020
sub_11020: @ 0x08011020
	push {r4, r5, lr}
	ldr r3, _08011088 @ =0x0200B0C0
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _0801108C @ =0x020028A4
	cmp r0, #0xf
	bne _0801103E
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08011090 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r3, #3]
_0801103E:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _080110DE
	ldr r5, _08011090 @ =0x02002888
	ldrh r1, [r5, #4]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080110B6
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bne _080110A0
	movs r0, #1
	strh r0, [r5, #2]
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0xb
	ldr r4, _08011094 @ =0x060101E0
	adds r0, r0, r4
	ldr r1, _08011098 @ =0x03000000
	movs r2, #8
	movs r3, #2
	bl sub_10708
	ldr r0, _0801109C @ =0x060161E0
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #0xb
	adds r1, r1, r4
	movs r2, #8
	movs r3, #2
	bl sub_10708
	b _080110B6
	.align 2, 0
_08011088: .4byte 0x0200B0C0
_0801108C: .4byte 0x020028A4
_08011090: .4byte 0x02002888
_08011094: .4byte 0x060101E0
_08011098: .4byte 0x03000000
_0801109C: .4byte 0x060161E0
_080110A0:
	strh r1, [r5, #2]
	ldr r0, _080110E8 @ =0x03000000
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #0xb
	ldr r2, _080110EC @ =0x060101E0
	adds r1, r1, r2
	movs r2, #8
	movs r3, #2
	bl sub_10708
_080110B6:
	ldr r3, _080110F0 @ =0x02002888
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0x14
	ble _080110D8
	ldr r2, _080110F4 @ =0x0200B0C0
	movs r0, #0
	strb r0, [r2, #0xd]
	ldr r1, _080110F8 @ =0x086A96A4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #6]
	movs r0, #0xa
	strb r0, [r2, #3]
_080110D8:
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
_080110DE:
	bl sub_1175C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080110E8: .4byte 0x03000000
_080110EC: .4byte 0x060101E0
_080110F0: .4byte 0x02002888
_080110F4: .4byte 0x0200B0C0
_080110F8: .4byte 0x086A96A4

	thumb_func_start sub_110FC
sub_110FC: @ 0x080110FC
	push {r4, r5, lr}
	ldr r3, _0801119C @ =0x0200B0C0
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _080111A0 @ =0x020028A4
	cmp r0, #0xf
	bne _0801111A
	movs r0, #1
	strb r0, [r2]
	ldr r1, _080111A4 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xa
	strb r0, [r3, #3]
_0801111A:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08011218
	ldr r3, _080111A4 @ =0x02002888
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r5, _080111A8 @ =0x086A9672
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	adds r2, r5, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _08011170
	strh r4, [r3, #4]
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _08011156
	strh r4, [r3, #2]
_08011156:
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r3, #0xc]
	movs r2, #2
	ldrsh r0, [r3, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #3
	strb r0, [r3, #0xe]
_08011170:
	ldr r0, _0801119C @ =0x0200B0C0
	ldrh r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080111AC
	movs r0, #0x67
	bl m4aSongNumStart
	ldr r1, _080111A4 @ =0x02002888
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080111CC
	movs r0, #4
	strb r0, [r1]
	b _080111CC
	.align 2, 0
_0801119C: .4byte 0x0200B0C0
_080111A0: .4byte 0x020028A4
_080111A4: .4byte 0x02002888
_080111A8: .4byte 0x086A9672
_080111AC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080111CC
	movs r0, #0x67
	bl m4aSongNumStart
	ldr r1, _080111EC @ =0x02002888
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _080111CC
	strb r4, [r1]
_080111CC:
	ldr r5, _080111F0 @ =0x0200B0C0
	ldrh r1, [r5, #0x18]
	movs r4, #9
	ands r4, r1
	cmp r4, #0
	beq _080111F4
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _080111EC @ =0x02002888
	movs r0, #0
	strh r0, [r1, #4]
	strh r0, [r1, #2]
	movs r0, #8
	b _08011212
	.align 2, 0
_080111EC: .4byte 0x02002888
_080111F0: .4byte 0x0200B0C0
_080111F4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08011214
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r1, _08011224 @ =0x02002888
	movs r2, #0
	strh r4, [r1, #4]
	movs r0, #0xc
	strh r0, [r1, #2]
	strb r2, [r1, #0xd]
	strb r2, [r1, #0xf]
	movs r0, #6
_08011212:
	strb r0, [r5, #3]
_08011214:
	bl sub_1157C
_08011218:
	bl sub_11968
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011224: .4byte 0x02002888

	thumb_func_start sub_11228
sub_11228: @ 0x08011228
	push {r4, r5, lr}
	ldr r3, _08011290 @ =0x0200B0C0
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _08011294 @ =0x020028A4
	cmp r0, #0xf
	bne _08011246
	movs r0, #1
	strb r0, [r2]
	ldr r1, _08011298 @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r3, #3]
_08011246:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0801130C
	ldr r5, _08011298 @ =0x02002888
	ldrh r1, [r5, #4]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080112BE
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bne _080112A8
	movs r0, #1
	strh r0, [r5, #2]
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0xb
	ldr r4, _0801129C @ =0x060101E0
	adds r0, r0, r4
	ldr r1, _080112A0 @ =0x03000000
	movs r2, #8
	movs r3, #2
	bl sub_10708
	ldr r0, _080112A4 @ =0x060161E0
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #0xb
	adds r1, r1, r4
	movs r2, #8
	movs r3, #2
	bl sub_10708
	b _080112BE
	.align 2, 0
_08011290: .4byte 0x0200B0C0
_08011294: .4byte 0x020028A4
_08011298: .4byte 0x02002888
_0801129C: .4byte 0x060101E0
_080112A0: .4byte 0x03000000
_080112A4: .4byte 0x060161E0
_080112A8:
	strh r1, [r5, #2]
	ldr r0, _080112DC @ =0x03000000
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #0xb
	ldr r2, _080112E0 @ =0x060101E0
	adds r1, r1, r2
	movs r2, #8
	movs r3, #2
	bl sub_10708
_080112BE:
	ldr r0, _080112E4 @ =0x02002888
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r3, r0, #0
	cmp r1, #0x14
	ble _08011306
	movs r2, #0
	ldrsb r2, [r3, r2]
	cmp r2, #1
	bne _080112EC
	ldr r0, _080112E8 @ =0x0200B0C0
	strb r2, [r0, #0xd]
	adds r2, r0, #0
	b _080112F4
	.align 2, 0
_080112DC: .4byte 0x03000000
_080112E0: .4byte 0x060101E0
_080112E4: .4byte 0x02002888
_080112E8: .4byte 0x0200B0C0
_080112EC:
	ldr r1, _08011318 @ =0x0200B0C0
	movs r0, #0
	strb r0, [r1, #0xd]
	adds r2, r1, #0
_080112F4:
	ldr r1, _0801131C @ =0x086A96D4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #6]
	movs r0, #0xa
	strb r0, [r2, #3]
_08011306:
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
_0801130C:
	bl sub_11968
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011318: .4byte 0x0200B0C0
_0801131C: .4byte 0x086A96D4

	thumb_func_start sub_11320
sub_11320: @ 0x08011320
	push {r4, r5, r6, r7, lr}
	ldr r5, _080113A4 @ =0x0200B0C0
	ldrh r1, [r5, #0x1c]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _080113A8 @ =0x020028A4
	cmp r0, #0xf
	bne _0801133E
	movs r0, #1
	strb r0, [r2]
	ldr r1, _080113AC @ =0x02002888
	movs r0, #9
	strb r0, [r1, #6]
	movs r0, #0xb
	strb r0, [r5, #3]
_0801133E:
	movs r4, #0
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08011410
	ldr r3, _080113AC @ =0x02002888
	ldrb r0, [r3, #7]
	cmp r0, #0
	bne _080113C0
	ldrh r0, [r3, #4]
	adds r0, #1
	movs r6, #0
	strh r0, [r3, #4]
	ldr r2, _080113B0 @ =0x086A9748
	movs r7, #2
	ldrsh r1, [r3, r7]
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _0801139C
	strh r4, [r3, #4]
	ldrh r0, [r3, #2]
	subs r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801138C
	strh r4, [r3, #2]
	strb r6, [r3]
	ldr r0, _080113B4 @ =0x0202BE24
	movs r1, #1
	strb r1, [r0]
	movs r0, #1
	strb r0, [r3, #9]
	strb r6, [r3, #0xb]
	strb r0, [r5, #3]
_0801138C:
	ldr r2, _080113B8 @ =0x0201C190
	ldr r1, _080113BC @ =0x086A9714
	movs r4, #2
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #0x18]
_0801139C:
	bl sub_1175C
	b _08011410
	.align 2, 0
_080113A4: .4byte 0x0200B0C0
_080113A8: .4byte 0x020028A4
_080113AC: .4byte 0x02002888
_080113B0: .4byte 0x086A9748
_080113B4: .4byte 0x0202BE24
_080113B8: .4byte 0x0201C190
_080113BC: .4byte 0x086A9714
_080113C0:
	ldrh r0, [r3, #4]
	adds r0, #1
	strh r0, [r3, #4]
	ldr r2, _08011418 @ =0x086A9748
	movs r6, #2
	ldrsh r1, [r3, r6]
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	blt _0801140C
	strh r4, [r3, #4]
	ldrh r0, [r3, #2]
	subs r0, #1
	strh r0, [r3, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080113FC
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3]
	ldr r1, _0801141C @ =0x0202BE24
	strb r0, [r1]
	strb r0, [r3, #9]
	movs r1, #0
	strb r1, [r3, #0xb]
	strb r0, [r5, #3]
_080113FC:
	ldr r2, _08011420 @ =0x0202BE00
	ldr r1, _08011424 @ =0x086A9778
	movs r7, #2
	ldrsh r0, [r3, r7]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #0x18]
_0801140C:
	bl sub_11968
_08011410:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011418: .4byte 0x086A9748
_0801141C: .4byte 0x0202BE24
_08011420: .4byte 0x0202BE00
_08011424: .4byte 0x086A9778

	thumb_func_start sub_11428
sub_11428: @ 0x08011428
	push {lr}
	ldr r0, _0801143C @ =0x02002888
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _08011444
	ldr r0, _08011440 @ =sub_1175C + 1
	bl sub_FE04
	b _0801144A
	.align 2, 0
_0801143C: .4byte 0x02002888
_08011440: .4byte sub_1175C + 1
_08011444:
	ldr r0, _08011470 @ =sub_11968 + 1
	bl sub_FE04
_0801144A:
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _08011474 @ =0x086A964C
	ldr r0, _08011478 @ =0x02002888
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #8
	bne _08011480
	ldr r1, _0801147C @ =0x0202C588
	movs r0, #0
	b _08011484
	.align 2, 0
_08011470: .4byte sub_11968 + 1
_08011474: .4byte 0x086A964C
_08011478: .4byte 0x02002888
_0801147C: .4byte 0x0202C588
_08011480:
	ldr r1, _080114A4 @ =0x0202C588
	movs r0, #1
_08011484:
	strh r0, [r1]
	ldr r1, _080114A8 @ =0x0201A4B4
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080114AC @ =0x086A964C
	ldr r0, _080114B0 @ =0x02002888
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_23C
	pop {r0}
	bx r0
	.align 2, 0
_080114A4: .4byte 0x0202C588
_080114A8: .4byte 0x0201A4B4
_080114AC: .4byte 0x086A964C
_080114B0: .4byte 0x02002888

	thumb_func_start sub_114B4
sub_114B4: @ 0x080114B4
	push {lr}
	ldr r0, _080114E8 @ =sub_11640 + 1
	bl sub_FE04
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _080114EC @ =0x0202C588
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080114F0 @ =0x0201A4B4
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080114F4 @ =0x086A964C
	ldr r0, _080114F8 @ =0x02002888
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl sub_23C
	pop {r0}
	bx r0
	.align 2, 0
_080114E8: .4byte sub_11640 + 1
_080114EC: .4byte 0x0202C588
_080114F0: .4byte 0x0201A4B4
_080114F4: .4byte 0x086A964C
_080114F8: .4byte 0x02002888

	thumb_func_start sub_114FC
sub_114FC: @ 0x080114FC
	push {r4, lr}
	ldr r4, _0801156C @ =0x0200B0C0
	ldrh r2, [r4, #0x1c]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r1, #0
	ands r0, r2
	cmp r0, r1
	bne _08011546
	ldrh r1, [r4, #0x18]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08011546
	ldr r2, _08011570 @ =0x020028A1
	movs r0, #0x28
	strb r0, [r2]
	ldr r1, _08011574 @ =0x020028A0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08011546
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
	movs r0, #0x68
	bl m4aSongNumStart
	ldr r1, _08011578 @ =0x02002888
	movs r0, #1
	strb r0, [r1, #0x11]
	movs r0, #9
	strb r0, [r4, #3]
_08011546:
	ldr r2, _08011570 @ =0x020028A1
	ldrb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _08011564
	subs r0, r1, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08011564
	movs r1, #0
	strb r1, [r2]
	ldr r0, _08011574 @ =0x020028A0
	strb r1, [r0]
_08011564:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801156C: .4byte 0x0200B0C0
_08011570: .4byte 0x020028A1
_08011574: .4byte 0x020028A0
_08011578: .4byte 0x02002888

	thumb_func_start sub_1157C
sub_1157C: @ 0x0801157C
	push {r4, r5, r6, r7, lr}
	ldr r6, _080115E4 @ =0x086A97AC
	ldr r3, _080115E8 @ =0x020028A2
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	ldr r2, _080115EC @ =0x0200B0C0
	ldrh r1, [r2, #0x1c]
	movs r0, #0x10
	ands r0, r1
	adds r4, r2, #0
	ldr r7, _080115F0 @ =0x020028A3
	cmp r0, #0
	beq _080115FC
	ldrh r1, [r4, #0x18]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	ands r1, r0
	cmp r1, r0
	bne _080115FC
	movs r0, #0x28
	strb r0, [r7]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _080115FC
	movs r0, #0
	strb r0, [r3]
	strb r0, [r7]
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _080115F4 @ =0x02002888
	movs r0, #5
	strb r0, [r1, #6]
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _080115F8
	movs r0, #0xb
	b _080115FA
	.align 2, 0
_080115E4: .4byte 0x086A97AC
_080115E8: .4byte 0x020028A2
_080115EC: .4byte 0x0200B0C0
_080115F0: .4byte 0x020028A3
_080115F4: .4byte 0x02002888
_080115F8:
	movs r0, #0xa
_080115FA:
	strb r0, [r4, #3]
_080115FC:
	ldrh r0, [r4, #0x18]
	ldr r1, _08011638 @ =0x000003FF
	ands r0, r1
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bics r0, r1
	cmp r0, #0
	beq _08011614
	movs r1, #0
	strb r1, [r7]
	ldr r0, _0801163C @ =0x020028A2
	strb r1, [r0]
_08011614:
	ldrb r1, [r7]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	ble _08011630
	subs r0, r1, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08011630
	movs r1, #0
	strb r1, [r7]
	ldr r0, _0801163C @ =0x020028A2
	strb r1, [r0]
_08011630:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011638: .4byte 0x000003FF
_0801163C: .4byte 0x020028A2

	thumb_func_start sub_11640
sub_11640: @ 0x08011640
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08011744 @ =0x02002888
	movs r0, #8
	ldrsb r0, [r4, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	ldr r2, _08011748 @ =0x0200B3B8
	adds r7, r0, r2
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	muls r0, r1, r0
	adds r6, r0, r2
	movs r0, #9
	ldrsb r0, [r4, r0]
	strh r0, [r7]
	movs r0, #0x11
	ldrsb r0, [r4, r0]
	strh r0, [r6]
	ldr r5, _0801174C @ =0x086A96E4
	adds r0, r5, #0
	movs r1, #5
	bl sub_358
	ldrh r0, [r7]
	cmp r0, #1
	bne _080116DC
	movs r0, #0x78
	strh r0, [r7, #2]
	movs r0, #0x66
	strh r0, [r7, #4]
	movs r0, #8
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	mov ip, r0
	movs r5, #0
	ldrh r0, [r0]
	cmp r5, r0
	bge _080116DC
	ldr r1, _08011750 @ =0x03005000
	mov r8, r1
	ldr r2, _08011754 @ =0xFFFFFE00
	mov sb, r2
	adds r4, r7, #0
	adds r4, #8
_080116A2:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _08011758 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	mov r0, ip
	ldrh r0, [r0]
	cmp r5, r0
	blt _080116A2
_080116DC:
	ldrh r0, [r6]
	cmp r0, #1
	bne _08011730
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x50
	strh r0, [r6, #4]
	ldr r1, _08011750 @ =0x03005000
	mov r8, r1
	ldr r2, _08011754 @ =0xFFFFFE00
	mov sb, r2
	adds r4, r6, #0
	adds r4, #8
	ldr r0, _08011758 @ =0x000001FF
	mov ip, r0
	movs r5, #1
_080116FC:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, r8
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	mov r0, ip
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _080116FC
_08011730:
	movs r0, #0
	strh r0, [r7]
	strh r0, [r6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011744: .4byte 0x02002888
_08011748: .4byte 0x0200B3B8
_0801174C: .4byte 0x086A96E4
_08011750: .4byte 0x03005000
_08011754: .4byte 0xFFFFFE00
_08011758: .4byte 0x000001FF

	thumb_func_start sub_1175C
sub_1175C: @ 0x0801175C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _08011810 @ =0x0200B0C0
	ldrh r0, [r2, #0x38]
	movs r0, #0x84
	lsls r0, r0, #2
	strh r0, [r2, #0x38]
	ldrh r0, [r2, #0x3a]
	ldr r0, _08011814 @ =0x00000808
	strh r0, [r2, #0x3a]
	ldr r1, _08011818 @ =0x04000050
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	ldr r3, _0801181C @ =0x02002888
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r2, r2, r4
	adds r0, r0, r2
	mov sl, r0
	movs r0, #0xc
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov sb, r0
	movs r0, #0xe
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	mov r6, sl
	strh r0, [r6]
	movs r0, #0xd
	ldrsb r0, [r3, r0]
	mov r7, sb
	strh r0, [r7]
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08011820 @ =0x0201C190
	adds r0, r4, #0
	movs r1, #7
	bl sub_358
	ldrh r0, [r6]
	cmp r0, #1
	bne _0801187C
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x66
	strh r0, [r6, #4]
	ldr r4, [r4, #0x18]
	mov ip, r4
	movs r2, #0
	str r2, [sp]
	ldrh r3, [r4]
	cmp r2, r3
	bge _0801187C
	ldr r6, _08011824 @ =0x03005000
	mov r4, sl
	adds r4, #8
	mov r5, ip
_080117F2:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _08011828
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	b _08011838
	.align 2, 0
_08011810: .4byte 0x0200B0C0
_08011814: .4byte 0x00000808
_08011818: .4byte 0x04000050
_0801181C: .4byte 0x02002888
_08011820: .4byte 0x0201C190
_08011824: .4byte 0x03005000
_08011828:
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #1]
_08011838:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08011950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	adds r5, #8
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	mov r1, ip
	ldrh r1, [r1]
	cmp r0, r1
	blt _080117F2
_0801187C:
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #1
	bne _080118D8
	ldr r2, _08011958 @ =0x086A9684
	ldr r1, _0801195C @ =0x02002888
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	mov r5, sb
	adds r5, #8
	ldr r4, _08011960 @ =0x03005000
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _08011950 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r6, sb
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_080118D8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08011930
	ldr r2, _08011964 @ =0x086A9694
	ldr r1, _0801195C @ =0x02002888
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _08011960 @ =0x03005000
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r6, _08011950 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011954 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011930:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, sb
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011950: .4byte 0x000001FF
_08011954: .4byte 0xFFFFFE00
_08011958: .4byte 0x086A9684
_0801195C: .4byte 0x02002888
_08011960: .4byte 0x03005000
_08011964: .4byte 0x086A9694

	thumb_func_start sub_11968
sub_11968: @ 0x08011968
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r2, _08011A1C @ =0x0200B0C0
	ldrh r0, [r2, #0x38]
	movs r0, #0x84
	lsls r0, r0, #2
	strh r0, [r2, #0x38]
	ldrh r0, [r2, #0x3a]
	ldr r0, _08011A20 @ =0x00000808
	strh r0, [r2, #0x3a]
	ldr r1, _08011A24 @ =0x04000050
	ldrh r0, [r2, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r2, #0x3a]
	strh r0, [r1]
	ldr r3, _08011A28 @ =0x02002888
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	movs r1, #0xb8
	muls r0, r1, r0
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r2, r2, r4
	adds r0, r0, r2
	mov sl, r0
	movs r0, #0xc
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov sb, r0
	movs r0, #0xe
	ldrsb r0, [r3, r0]
	muls r0, r1, r0
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	mov r6, sl
	strh r0, [r6]
	movs r0, #0xd
	ldrsb r0, [r3, r0]
	mov r7, sb
	strh r0, [r7]
	movs r0, #0xf
	ldrsb r0, [r3, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r4, _08011A2C @ =0x0202BE00
	adds r0, r4, #0
	movs r1, #7
	bl sub_358
	ldrh r0, [r6]
	cmp r0, #1
	bne _08011A88
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x66
	strh r0, [r6, #4]
	ldr r4, [r4, #0x18]
	mov ip, r4
	movs r2, #0
	str r2, [sp]
	ldrh r3, [r4]
	cmp r2, r3
	bge _08011A88
	ldr r6, _08011A30 @ =0x03005000
	mov r4, sl
	adds r4, #8
	mov r5, ip
_080119FE:
	ldrh r0, [r5, #8]
	cmp r0, #1
	bne _08011A34
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	b _08011A44
	.align 2, 0
_08011A1C: .4byte 0x0200B0C0
_08011A20: .4byte 0x00000808
_08011A24: .4byte 0x04000050
_08011A28: .4byte 0x02002888
_08011A2C: .4byte 0x0202BE00
_08011A30: .4byte 0x03005000
_08011A34:
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #1]
_08011A44:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08011B5C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	adds r5, #8
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	mov r1, ip
	ldrh r1, [r1]
	cmp r0, r1
	blt _080119FE
_08011A88:
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #1
	bne _08011AE4
	ldr r2, _08011B64 @ =0x086A96AC
	ldr r1, _08011B68 @ =0x02002888
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	mov r5, sb
	adds r5, #8
	ldr r4, _08011B6C @ =0x03005000
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r6, #2
	ldrsh r1, [r5, r6]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _08011B5C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r6, sb
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011AE4:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08011B3C
	ldr r2, _08011B70 @ =0x086A96C0
	ldr r1, _08011B68 @ =0x02002888
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _08011B6C @ =0x03005000
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r6, _08011B5C @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08011B60 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08011B3C:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, sb
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011B5C: .4byte 0x000001FF
_08011B60: .4byte 0xFFFFFE00
_08011B64: .4byte 0x086A96AC
_08011B68: .4byte 0x02002888
_08011B6C: .4byte 0x03005000
_08011B70: .4byte 0x086A96C0

	thumb_func_start sub_11B74
sub_11B74: @ 0x08011B74
	push {lr}
	bl sub_52C64
	bl sub_52B30
	ldr r0, _08011B94 @ =0x0200B0C0
	movs r1, #0
	str r1, [r0, #0x40]
	adds r0, #0x40
	ldr r1, _08011B98 @ =0x0E000544
	movs r2, #4
	bl sub_55654
	pop {r0}
	bx r0
	.align 2, 0
_08011B94: .4byte 0x0200B0C0
_08011B98: .4byte 0x0E000544
