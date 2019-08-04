	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start FieldSelectMain
FieldSelectMain: @ 0x08008AD4
	push {lr}
	ldr r1, _08008AEC @ =gUnknown_080792C0
	ldr r0, _08008AF0 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08008AEC: .4byte gUnknown_080792C0
_08008AF0: .4byte gMain

	thumb_func_start LoadFieldSelectGraphics
LoadFieldSelectGraphics: @ 0x08008AF4
	push {r4, lr}
	bl sub_438
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _08008BD4 @ =0x04000008
	movs r0, #4
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08008BD8 @ =0x0400000A
	adds r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	adds r3, #0xfb
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08008BDC @ =0x0400000C
	adds r3, #0xa
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08008BE0 @ =gMain
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	ldr r0, _08008BE4 @ =0x040000D4
	ldr r1, _08008BE8 @ =gFieldSelectBGPals
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r3, _08008BEC @ =0x80000100
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008BF0 @ =gFieldSelectWindow_Gfx
	str r1, [r0]
	ldr r1, _08008BF4 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _08008BF8 @ =0x80000A00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008BFC @ =gFieldSelectMiniFields_Gfx
	str r1, [r0]
	ldr r1, _08008C00 @ =0x06008000
	str r1, [r0, #4]
	ldr r1, _08008C04 @ =0x80001C00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008C08 @ =gUnknown_080A2400
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _08008C0C @ =0x80000400
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008C10 @ =gFieldSelectFrameShadowTilemap
	str r1, [r0]
	ldr r1, _08008C14 @ =0x06000800
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008C18 @ =gFieldSelectWindowTilemap
	str r1, [r0]
	ldr r1, _08008C1C @ =0x06001000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008C20 @ =gFieldSelectSpritePals
	str r1, [r0]
	ldr r1, _08008C24 @ =0x05000200
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08008C28 @ =gFieldSelectSpriteGfx
	str r1, [r0]
	ldr r1, _08008C2C @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _08008C30 @ =0x80002010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_CBC
	bl sub_8C38
	ldr r0, _08008C34 @ =sub_8F94 + 1
	bl sub_FD5C
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	movs r0, #3
	bl m4aSongNumStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008BD4: .4byte 0x04000008
_08008BD8: .4byte 0x0400000A
_08008BDC: .4byte 0x0400000C
_08008BE0: .4byte gMain
_08008BE4: .4byte 0x040000D4
_08008BE8: .4byte gFieldSelectBGPals
_08008BEC: .4byte 0x80000100
_08008BF0: .4byte gFieldSelectWindow_Gfx
_08008BF4: .4byte 0x06004000
_08008BF8: .4byte 0x80000A00
_08008BFC: .4byte gFieldSelectMiniFields_Gfx
_08008C00: .4byte 0x06008000
_08008C04: .4byte 0x80001C00
_08008C08: .4byte gUnknown_080A2400
_08008C0C: .4byte 0x80000400
_08008C10: .4byte gFieldSelectFrameShadowTilemap
_08008C14: .4byte 0x06000800
_08008C18: .4byte gFieldSelectWindowTilemap
_08008C1C: .4byte 0x06001000
_08008C20: .4byte gFieldSelectSpritePals
_08008C24: .4byte 0x05000200
_08008C28: .4byte gFieldSelectSpriteGfx
_08008C2C: .4byte 0x06010000
_08008C30: .4byte 0x80002010
_08008C34: .4byte sub_8F94 + 1

	thumb_func_start sub_8C38
sub_8C38: @ 0x08008C38
	ldr r2, _08008C70 @ =gUnknown_02002838
	movs r3, #0
	movs r1, #0
	movs r0, #2
	strh r0, [r2]
	movs r0, #3
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	movs r0, #1
	strh r0, [r2, #6]
	strh r1, [r2, #8]
	strh r1, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r1, [r2, #0x16]
	strh r1, [r2, #0x12]
	strb r3, [r2, #0x14]
	ldr r0, _08008C74 @ =gUnknown_0200B134
	adds r1, r0, #0
	adds r1, #0xce
	ldrb r1, [r1]
	strb r1, [r2, #0x10]
	subs r0, #0x74
	strb r3, [r0, #4]
	ldr r0, _08008C78 @ =gUnknown_02002850
	strb r3, [r0]
	bx lr
	.align 2, 0
_08008C70: .4byte gUnknown_02002838
_08008C74: .4byte gUnknown_0200B134
_08008C78: .4byte gUnknown_02002850

	thumb_func_start sub_8C7C
sub_8C7C: @ 0x08008C7C
	push {r4, r5, r6, r7, lr}
	bl sub_8F94
	ldr r7, _08008CC4 @ =gMain
	ldrh r1, [r7, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08008CA0
	ldr r1, _08008CC8 @ =gUnknown_02002850
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08008CCC @ =gUnknown_02002838
	movs r0, #0
	strh r0, [r1, #0x16]
	ldrb r0, [r7, #3]
	adds r0, #1
	strb r0, [r7, #3]
_08008CA0:
	ldr r0, _08008CC8 @ =gUnknown_02002850
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	beq _08008CAC
	b _08008F56
_08008CAC:
	ldr r5, _08008CCC @ =gUnknown_02002838
	ldrh r4, [r5, #0xa]
	adds r3, r5, #0
	cmp r4, #1
	bne _08008CB8
	b _08008E2E
_08008CB8:
	cmp r4, #1
	bgt _08008CD0
	cmp r4, #0
	beq _08008CDC
	b _08008F4C
	.align 2, 0
_08008CC4: .4byte gMain
_08008CC8: .4byte gUnknown_02002850
_08008CCC: .4byte gUnknown_02002838
_08008CD0:
	cmp r4, #2
	beq _08008DC2
	cmp r4, #3
	bne _08008CDA
	b _08008F08
_08008CDA:
	b _08008F4C
_08008CDC:
	ldrh r1, [r7, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08008CFC
	ldrh r4, [r5, #8]
	cmp r4, #1
	bne _08008D1A
	movs r0, #0x6d
	bl m4aSongNumStart
	strh r6, [r5, #8]
	strh r6, [r5, #4]
	strh r4, [r5, #6]
	strh r4, [r5, #0xa]
	b _08008D1A
_08008CFC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08008D1A
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08008D1A
	movs r0, #0x6d
	bl m4aSongNumStart
	movs r0, #1
	strh r0, [r5, #8]
	strh r0, [r5, #4]
	strh r6, [r5, #6]
	strh r0, [r5, #0xa]
_08008D1A:
	ldr r2, _08008D50 @ =gMain
	ldrh r1, [r2, #0x18]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _08008D66
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r1, _08008D54 @ =gUnknown_02002838
	movs r2, #0
	movs r3, #2
	strh r3, [r1, #0xa]
	movs r0, #1
	strb r0, [r1, #0x14]
	strh r2, [r1, #0xe]
	ldrh r0, [r1, #8]
	cmp r0, #0
	bne _08008D58
	strh r2, [r1, #4]
	strh r4, [r1, #6]
	strh r3, [r1]
	movs r0, #3
	b _08008D62
	.align 2, 0
_08008D50: .4byte gMain
_08008D54: .4byte gUnknown_02002838
_08008D58:
	strh r4, [r1, #4]
	strh r2, [r1, #6]
	movs r0, #7
	strh r0, [r1]
	movs r0, #0xb
_08008D62:
	strh r0, [r1, #2]
	strh r2, [r1, #0xc]
_08008D66:
	ldrh r1, [r5, #0x18]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08008DAA
	movs r0, #0x66
	bl m4aSongNumStart
	ldrb r0, [r5, #3]
	adds r0, #1
	movs r3, #0
	strb r0, [r5, #3]
	ldr r1, _08008D98 @ =gUnknown_02002838
	movs r2, #1
	strh r2, [r1, #0x16]
	ldrh r0, [r1, #8]
	cmp r0, #0
	bne _08008D9C
	strh r3, [r1, #4]
	strh r2, [r1, #6]
	strh r4, [r1]
	movs r0, #3
	b _08008DA6
	.align 2, 0
_08008D98: .4byte gUnknown_02002838
_08008D9C:
	strh r2, [r1, #4]
	strh r3, [r1, #6]
	movs r0, #7
	strh r0, [r1]
	movs r0, #0xb
_08008DA6:
	strh r0, [r1, #2]
	strh r3, [r1, #0xc]
_08008DAA:
	ldr r1, _08008DB8 @ =gMain
	ldrb r0, [r1, #4]
	cmp r0, #1
	bhi _08008DBC
	movs r0, #0
	strb r0, [r1, #6]
	b _08008F4C
	.align 2, 0
_08008DB8: .4byte gMain
_08008DBC:
	movs r0, #1
	strb r0, [r1, #6]
	b _08008F4C
_08008DC2:
	ldrh r1, [r7, #0x18]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _08008DDA
	movs r0, #0x67
	bl m4aSongNumStart
	ldrb r1, [r5, #0x10]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r5, #0x10]
_08008DDA:
	ldrh r1, [r7, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08008E00
	movs r0, #0x65
	bl m4aSongNumStart
	strh r6, [r5, #0xe]
	strh r6, [r5, #0xc]
	ldrb r0, [r5, #0x10]
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl sub_52B30
	movs r0, #3
	strh r0, [r5, #0xa]
_08008E00:
	ldrh r0, [r7, #0x18]
	ands r4, r0
	cmp r4, #0
	beq _08008E12
	movs r0, #0x66
	bl m4aSongNumStart
	strb r6, [r5, #0x14]
	strh r6, [r5, #0xa]
_08008E12:
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _08008E22
	b _08008F4C
_08008E22:
	strh r6, [r5, #0xe]
	ldrh r1, [r5, #0x12]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	b _08008F4C
_08008E2E:
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08008E5C
	ldr r2, _08008E58 @ =gUnknown_086A6B14
	movs r4, #0xc
	ldrsh r0, [r5, r4]
	movs r1, #4
	subs r0, r1, r0
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5]
	movs r4, #0xc
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r2, #0xa
	adds r1, r1, r2
	ldrh r0, [r1]
	b _08008E76
	.align 2, 0
_08008E58: .4byte gUnknown_086A6B14
_08008E5C:
	ldr r1, _08008E94 @ =gUnknown_086A6B14
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5]
	movs r4, #0xc
	ldrsh r0, [r5, r4]
	lsls r0, r0, #1
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r0, [r0]
_08008E76:
	strh r0, [r5, #2]
	ldr r0, _08008E98 @ =gMain
	ldr r1, [r0, #0x4c]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08008EA0
	ldrh r2, [r3, #0xc]
	movs r4, #0xc
	ldrsh r0, [r3, r4]
	cmp r0, #3
	bgt _08008E9C
	adds r0, r2, #1
	strh r0, [r3, #0xc]
	b _08008EA0
	.align 2, 0
_08008E94: .4byte gUnknown_086A6B14
_08008E98: .4byte gMain
_08008E9C:
	strh r1, [r3, #0xc]
	strh r1, [r3, #0xa]
_08008EA0:
	ldr r0, _08008ED0 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08008ED8
	ldr r4, _08008ED4 @ =gUnknown_02002838
	ldrh r5, [r4, #8]
	cmp r5, #1
	bne _08008F4C
	movs r0, #0x6d
	bl m4aSongNumStart
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #4]
	strh r5, [r4, #6]
	movs r1, #2
	strh r1, [r4]
	movs r1, #3
	strh r1, [r4, #2]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xa]
	b _08008F4C
	.align 2, 0
_08008ED0: .4byte gMain
_08008ED4: .4byte gUnknown_02002838
_08008ED8:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08008F4C
	ldr r4, _08008F04 @ =gUnknown_02002838
	ldrh r5, [r4, #8]
	cmp r5, #0
	bne _08008F4C
	movs r0, #0x6d
	bl m4aSongNumStart
	movs r0, #1
	strh r0, [r4, #8]
	strh r0, [r4, #4]
	strh r5, [r4, #6]
	movs r0, #7
	strh r0, [r4]
	movs r0, #0xb
	strh r0, [r4, #2]
	strh r5, [r4, #0xc]
	strh r5, [r4, #0xa]
	b _08008F4C
	.align 2, 0
_08008F04: .4byte gUnknown_02002838
_08008F08:
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08008F4C
	strh r6, [r5, #0xe]
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08008F28
	ldrh r1, [r5, #4]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r5, #4]
	b _08008F30
_08008F28:
	ldrh r1, [r5, #6]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r5, #6]
_08008F30:
	ldr r1, _08008F5C @ =gUnknown_02002838
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08008F4C
	movs r0, #2
	strh r0, [r1, #0x16]
	ldr r1, _08008F60 @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_08008F4C:
	ldr r0, _08008F60 @ =gMain
	ldr r1, _08008F5C @ =gUnknown_02002838
	ldrh r1, [r1, #8]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
_08008F56:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008F5C: .4byte gUnknown_02002838
_08008F60: .4byte gMain

	thumb_func_start sub_8F64
sub_8F64: @ 0x08008F64
	push {lr}
	ldr r0, _08008F88 @ =sub_8F94 + 1
	bl sub_FE04
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _08008F8C @ =gAutoDisplayTitlescreenMenu
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08008F90 @ =gUnknown_02002838
	ldrh r0, [r0, #0x16]
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_08008F88: .4byte sub_8F94 + 1
_08008F8C: .4byte gAutoDisplayTitlescreenMenu
_08008F90: .4byte gUnknown_02002838

	thumb_func_start sub_8F94
sub_8F94: @ 0x08008F94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r5, _08009254 @ =gMain
	ldrh r0, [r5, #0x38]
	ldr r0, _08009258 @ =0x00000642
	strh r0, [r5, #0x38]
	ldrh r0, [r5, #0x3a]
	ldr r0, _0800925C @ =0x00000808
	strh r0, [r5, #0x3a]
	ldr r1, _08009260 @ =0x04000050
	ldrh r0, [r5, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0x3a]
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r6, r5, r0
	movs r1, #0xec
	lsls r1, r1, #2
	adds r1, r1, r5
	mov sb, r1
	ldr r4, _08009264 @ =gUnknown_02002838
	ldrh r0, [r4]
	movs r2, #0xb8
	muls r0, r2, r0
	adds r0, r0, r6
	str r0, [sp]
	ldrh r0, [r4, #2]
	muls r0, r2, r0
	adds r0, r0, r6
	mov sl, r0
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #1
	movs r3, #0x12
	ldrsh r0, [r4, r3]
	adds r0, #0xc
	adds r1, r1, r0
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r4, #4]
	strh r0, [r6]
	ldrh r0, [r4, #6]
	mov r7, sb
	strh r0, [r7]
	movs r0, #1
	ldr r1, [sp]
	strh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	movs r0, #0x14
	ldrsb r0, [r4, r0]
	mov r3, r8
	strh r0, [r3]
	ldr r0, _08009268 @ =gUnknown_086A6AD4
	movs r1, #0x10
	adds r2, r6, #0
	bl LoadSpriteSets
	ldrh r0, [r4, #4]
	cmp r0, #1
	bne _08009066
	movs r0, #0x25
	strh r0, [r6, #2]
	movs r0, #0x18
	strh r0, [r6, #4]
	ldr r7, _0800926C @ =gOamBuffer
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r1, _08009270 @ =0x000001FF
	mov ip, r1
	movs r5, #1
_08009032:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	mov r0, ip
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08009274 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _08009032
_08009066:
	ldr r0, _08009264 @ =gUnknown_02002838
	ldrh r1, [r0, #6]
	cmp r1, #1
	bne _080090BC
	movs r0, #0x8d
	mov r3, sb
	strh r0, [r3, #2]
	movs r0, #0x18
	strh r0, [r3, #4]
	ldr r6, _0800926C @ =gOamBuffer
	ldr r7, _08009274 @ =0xFFFFFE00
	mov ip, r7
	mov r4, sb
	adds r4, #8
	movs r5, #1
_08009084:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r0, _08009270 @ =0x000001FF
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _08009084
_080090BC:
	movs r0, #0x20
	ldr r7, [sp]
	strh r0, [r7, #2]
	strh r0, [r7, #4]
	ldr r1, _08009264 @ =gUnknown_02002838
	ldrh r0, [r1]
	lsls r0, r0, #2
	ldr r2, _08009268 @ =gUnknown_086A6AD4
	adds r0, r0, r2
	ldr r6, [r0]
	movs r5, #0
	ldrh r3, [r6]
	cmp r5, r3
	bge _0800913A
	movs r7, #0xd
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _08009274 @ =0xFFFFFE00
	mov sb, r0
	ldr r4, [sp]
	adds r4, #8
_080090E6:
	ldrh r2, [r4]
	lsls r2, r2, #3
	ldr r1, _0800926C @ =gOamBuffer
	adds r2, r2, r1
	ldrb r1, [r2, #1]
	mov r0, ip
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	ldr r2, _0800926C @ =gOamBuffer
	adds r3, r3, r2
	movs r7, #2
	ldrsh r1, [r4, r7]
	ldr r2, [sp]
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08009270 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	ldr r3, _0800926C @ =gOamBuffer
	adds r1, r1, r3
	ldr r7, [sp]
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r3, [r6]
	cmp r5, r3
	blt _080090E6
_0800913A:
	movs r0, #0x88
	mov r7, sl
	strh r0, [r7, #2]
	movs r0, #0x20
	strh r0, [r7, #4]
	ldr r1, _08009264 @ =gUnknown_02002838
	ldrh r0, [r1, #2]
	lsls r0, r0, #2
	ldr r2, _08009268 @ =gUnknown_086A6AD4
	adds r0, r0, r2
	ldr r6, [r0]
	movs r5, #0
	ldrh r3, [r6]
	cmp r5, r3
	bge _080091BA
	movs r7, #0xd
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _08009274 @ =0xFFFFFE00
	mov sb, r0
	mov r4, sl
	adds r4, #8
_08009166:
	ldrh r2, [r4]
	lsls r2, r2, #3
	ldr r1, _0800926C @ =gOamBuffer
	adds r2, r2, r1
	ldrb r1, [r2, #1]
	mov r0, ip
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	ldr r2, _0800926C @ =gOamBuffer
	adds r3, r3, r2
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08009270 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	ldr r3, _0800926C @ =gOamBuffer
	adds r1, r1, r3
	mov r7, sl
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldrh r3, [r6]
	cmp r5, r3
	blt _08009166
_080091BA:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08009234
	ldr r1, _08009278 @ =gUnknown_086A6B28
	ldr r2, _08009264 @ =gUnknown_02002838
	ldrh r0, [r2, #8]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #2]
	ldrh r0, [r2, #8]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	ldr r6, _0800926C @ =gOamBuffer
	movs r3, #0xd
	rsbs r3, r3, #0
	mov sb, r3
	ldr r7, _08009274 @ =0xFFFFFE00
	mov ip, r7
	mov r4, r8
	adds r4, #8
	movs r5, #4
_080091EC:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08009270 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _080091EC
_08009234:
	movs r0, #0
	ldr r1, [sp]
	strh r0, [r1]
	mov r2, sl
	strh r0, [r2]
	mov r3, r8
	strh r0, [r3]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009254: .4byte gMain
_08009258: .4byte 0x00000642
_0800925C: .4byte 0x00000808
_08009260: .4byte 0x04000050
_08009264: .4byte gUnknown_02002838
_08009268: .4byte gUnknown_086A6AD4
_0800926C: .4byte gOamBuffer
_08009270: .4byte 0x000001FF
_08009274: .4byte 0xFFFFFE00
_08009278: .4byte gUnknown_086A6B28
