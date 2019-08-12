	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start BonusFieldSelectMain
BonusFieldSelectMain: @ 0x080025A4
	push {lr}
	ldr r1, _080025BC @ =gUnknown_0805C750
	ldr r0, _080025C0 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080025BC: .4byte gUnknown_0805C750
_080025C0: .4byte gMain

	thumb_func_start sub_25C4
sub_25C4: @ 0x080025C4
	push {r4, lr}
	bl ResetSomeGraphicsRelatedStuff
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x84
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _080026A8 @ =0x04000008
	movs r0, #5
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080026AC @ =0x0400000A
	adds r3, #6
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	adds r3, #0xfa
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080026B0 @ =0x0400000C
	adds r3, #0xb
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _080026B4 @ =gMain
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	ldr r0, _080026B8 @ =0x040000D4
	ldr r1, _080026BC @ =gUnknown_0807C2E0
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _080026C0 @ =0x80000100
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026C4 @ =gFieldSelectWindow_Gfx
	str r1, [r0]
	ldr r1, _080026C8 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _080026CC @ =0x80002000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026D0 @ =gUnknown_0807C4E0
	str r1, [r0]
	ldr r1, _080026D4 @ =0x06008000
	str r1, [r0, #4]
	ldr r1, _080026D8 @ =0x80000C00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026DC @ =gUnknown_0807AAE0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _080026E0 @ =0x80000400
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026E4 @ =gUnknown_0807B2E0
	str r1, [r0]
	ldr r1, _080026E8 @ =0x06000800
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026EC @ =gUnknown_0807BAE0
	str r1, [r0]
	ldr r1, _080026F0 @ =0x06001000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080026F4 @ =gFieldSelectSpritePals
	str r1, [r0]
	ldr r1, _080026F8 @ =0x05000200
	str r1, [r0, #4]
	ldr r1, _080026FC @ =0x80000030
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08002700 @ =gFieldSelectSpriteGfx
	str r1, [r0]
	ldr r1, _08002704 @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _08002708 @ =0x80002010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_CBC
	bl sub_2710
	ldr r0, _0800270C @ =sub_29C8 + 1
	bl sub_FD5C
	movs r0, #3
	bl m4aSongNumStart
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080026A8: .4byte 0x04000008
_080026AC: .4byte 0x0400000A
_080026B0: .4byte 0x0400000C
_080026B4: .4byte gMain
_080026B8: .4byte 0x040000D4
_080026BC: .4byte gUnknown_0807C2E0
_080026C0: .4byte 0x80000100
_080026C4: .4byte gFieldSelectWindow_Gfx
_080026C8: .4byte 0x06004000
_080026CC: .4byte 0x80002000
_080026D0: .4byte gUnknown_0807C4E0
_080026D4: .4byte 0x06008000
_080026D8: .4byte 0x80000C00
_080026DC: .4byte gUnknown_0807AAE0
_080026E0: .4byte 0x80000400
_080026E4: .4byte gUnknown_0807B2E0
_080026E8: .4byte 0x06000800
_080026EC: .4byte gUnknown_0807BAE0
_080026F0: .4byte 0x06001000
_080026F4: .4byte gFieldSelectSpritePals
_080026F8: .4byte 0x05000200
_080026FC: .4byte 0x80000030
_08002700: .4byte gFieldSelectSpriteGfx
_08002704: .4byte 0x06010000
_08002708: .4byte 0x80002010
_0800270C: .4byte sub_29C8 + 1

	thumb_func_start sub_2710
sub_2710: @ 0x08002710
	ldr r0, _08002740 @ =gUnknown_0201A4F8
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08002744 @ =gUnknown_0202BED0
	strb r1, [r0]
	ldr r0, _08002748 @ =gUnknown_0202A560
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0800274C @ =gUnknown_0202BE1C
	strh r1, [r0]
	ldr r0, _08002750 @ =gUnknown_0202BEE8
	strb r1, [r0]
	ldr r0, _08002754 @ =gUnknown_0201A4F4
	strh r1, [r0]
	ldr r0, _08002758 @ =gUnknown_0201A4B0
	strb r1, [r0]
	ldr r0, _0800275C @ =gUnknown_0202BEE4
	strb r1, [r0]
	ldr r1, _08002760 @ =gUnknown_0201A4C0
	ldr r0, _08002764 @ =gMain+0x74
	adds r0, #0xce
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	.align 2, 0
_08002740: .4byte gUnknown_0201A4F8
_08002744: .4byte gUnknown_0202BED0
_08002748: .4byte gUnknown_0202A560
_0800274C: .4byte gUnknown_0202BE1C
_08002750: .4byte gUnknown_0202BEE8
_08002754: .4byte gUnknown_0201A4F4
_08002758: .4byte gUnknown_0201A4B0
_0800275C: .4byte gUnknown_0202BEE4
_08002760: .4byte gUnknown_0201A4C0
_08002764: .4byte gMain+0x74

	thumb_func_start sub_2768
sub_2768: @ 0x08002768
	push {r4, r5, r6, lr}
	bl sub_29C8
	ldr r6, _08002784 @ =gUnknown_0202BED0
	movs r4, #0
	ldrsb r4, [r6, r4]
	cmp r4, #1
	bne _0800277A
	b _08002884
_0800277A:
	cmp r4, #1
	bgt _08002788
	cmp r4, #0
	beq _08002790
	b _0800296E
	.align 2, 0
_08002784: .4byte gUnknown_0202BED0
_08002788:
	cmp r4, #2
	bne _0800278E
	b _0800291C
_0800278E:
	b _0800296E
_08002790:
	ldr r0, _080027B8 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080027C0
	ldr r4, _080027BC @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _080027E2
	cmp r0, #3
	beq _080027E2
	movs r0, #0x6d
	bl m4aSongNumStart
	ldrb r0, [r4]
	subs r0, #1
	b _080027E0
	.align 2, 0
_080027B8: .4byte gMain
_080027BC: .4byte gUnknown_0201A4F8
_080027C0:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080027E2
	ldr r4, _08002804 @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	beq _080027E2
	cmp r0, #5
	beq _080027E2
	movs r0, #0x6d
	bl m4aSongNumStart
	ldrb r0, [r4]
	adds r0, #1
_080027E0:
	strb r0, [r4]
_080027E2:
	ldr r0, _08002808 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800280C
	ldr r4, _08002804 @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _0800282A
	movs r0, #0x6d
	bl m4aSongNumStart
	ldrb r0, [r4]
	subs r0, #3
	b _08002828
	.align 2, 0
_08002804: .4byte gUnknown_0201A4F8
_08002808: .4byte gMain
_0800280C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800282A
	ldr r4, _0800286C @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bgt _0800282A
	movs r0, #0x6d
	bl m4aSongNumStart
	ldrb r0, [r4]
	adds r0, #3
_08002828:
	strb r0, [r4]
_0800282A:
	ldr r4, _08002870 @ =gMain
	ldrh r1, [r4, #0x18]
	movs r5, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800284C
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r0, _08002874 @ =gUnknown_0202BED0
	strb r5, [r0]
	ldr r0, _08002878 @ =gUnknown_0201A4B0
	strb r5, [r0]
	ldr r1, _0800287C @ =gUnknown_0202A560
	movs r0, #0
	strh r0, [r1]
_0800284C:
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08002858
	b _0800296E
_08002858:
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r0, _08002880 @ =gUnknown_0202BEE4
	strb r5, [r0]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	b _0800296E
	.align 2, 0
_0800286C: .4byte gUnknown_0201A4F8
_08002870: .4byte gMain
_08002874: .4byte gUnknown_0202BED0
_08002878: .4byte gUnknown_0201A4B0
_0800287C: .4byte gUnknown_0202A560
_08002880: .4byte gUnknown_0202BEE4
_08002884:
	ldr r5, _08002904 @ =gMain
	ldrh r1, [r5, #0x18]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080028A0
	movs r0, #0x67
	bl m4aSongNumStart
	ldr r2, _08002908 @ =gUnknown_0201A4C0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_080028A0:
	ldrh r0, [r5, #0x18]
	ands r4, r0
	cmp r4, #0
	beq _080028CC
	movs r0, #0x65
	bl m4aSongNumStart
	ldr r0, _0800290C @ =gUnknown_0202A560
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08002910 @ =gUnknown_0202BE1C
	strh r1, [r0]
	ldr r0, _08002908 @ =gUnknown_0201A4C0
	ldrb r0, [r0]
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	bl SaveFile_WriteToSram
	movs r0, #2
	strb r0, [r6]
_080028CC:
	ldrh r1, [r5, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080028E4
	movs r0, #0x66
	bl m4aSongNumStart
	ldr r1, _08002914 @ =gUnknown_0201A4B0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r6]
_080028E4:
	ldr r1, _0800290C @ =gUnknown_0202A560
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800296E
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08002918 @ =gUnknown_0201A4F4
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	b _0800296E
	.align 2, 0
_08002904: .4byte gMain
_08002908: .4byte gUnknown_0201A4C0
_0800290C: .4byte gUnknown_0202A560
_08002910: .4byte gUnknown_0202BE1C
_08002914: .4byte gUnknown_0201A4B0
_08002918: .4byte gUnknown_0201A4F4
_0800291C:
	ldr r1, _08002974 @ =gUnknown_0202A560
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0800296E
	movs r3, #0
	strh r3, [r1]
	ldr r2, _08002978 @ =gUnknown_0202BEE8
	ldrb r1, [r2]
	movs r0, #2
	subs r0, r0, r1
	strb r0, [r2]
	ldr r1, _0800297C @ =gUnknown_0202BE1C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0800296E
	ldr r1, _08002980 @ =gMain
	strb r3, [r1, #0xd]
	ldr r2, _08002984 @ =gUnknown_086A4CF0
	ldr r0, _08002988 @ =gUnknown_0201A4F8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	movs r0, #1
	strb r0, [r1, #6]
	ldr r0, _0800298C @ =gUnknown_0202BEE4
	strb r4, [r0]
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_0800296E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002974: .4byte gUnknown_0202A560
_08002978: .4byte gUnknown_0202BEE8
_0800297C: .4byte gUnknown_0202BE1C
_08002980: .4byte gMain
_08002984: .4byte gUnknown_086A4CF0
_08002988: .4byte gUnknown_0201A4F8
_0800298C: .4byte gUnknown_0202BEE4

	thumb_func_start sub_2990
sub_2990: @ 0x08002990
	push {lr}
	ldr r0, _080029BC @ =sub_29C8 + 1
	bl sub_FE04
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _080029C0 @ =gAutoDisplayTitlescreenMenu
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080029C4 @ =gUnknown_0202BEE4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_080029BC: .4byte sub_29C8 + 1
_080029C0: .4byte gAutoDisplayTitlescreenMenu
_080029C4: .4byte gUnknown_0202BEE4

	thumb_func_start sub_29C8
sub_29C8: @ 0x080029C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r1, _08002C14 @ =gMain
	ldrh r0, [r1, #0x38]
	ldr r0, _08002C18 @ =0x00000C14
	strh r0, [r1, #0x38]
	ldrh r0, [r1, #0x3a]
	ldr r0, _08002C1C @ =0x00000808
	strh r0, [r1, #0x3a]
	ldr r2, _08002C20 @ =0x04000050
	ldrh r0, [r1, #0x38]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0x3a]
	strh r0, [r2]
	ldr r7, _08002C24 @ =gUnknown_0201A4F8
	movs r0, #0xe9
	lsls r0, r0, #3
	adds r3, r1, r0
	ldr r4, _08002C28 @ =gUnknown_0201A4C0
	ldr r5, _08002C2C @ =gUnknown_0201A4F4
	ldr r2, _08002C30 @ =gUnknown_0201A4B0
	mov sb, r2
	ldr r0, _08002C34 @ =gUnknown_086A4C80
	mov ip, r0
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r1, r2
	add r0, sp, #0x14
_08002A0A:
	str r1, [r0]
	subs r1, #0xb8
	subs r0, #4
	cmp r0, sp	 @ warning: use of r13 is deprecated
	bge _08002A0A
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #0xb8
	muls r0, r2, r0
	adds r0, r0, r3
	mov sl, r0
	ldrb r1, [r4]
	lsls r1, r1, #1
	movs r4, #0
	ldrsh r0, [r5, r4]
	adds r0, #0xc
	adds r1, r1, r0
	muls r1, r2, r1
	ldr r2, _08002C38 @ =0xFFFFFBB0
	adds r0, r3, r2
	adds r1, r1, r0
	mov r8, r1
	movs r2, #1
	mov r1, sp
	movs r6, #5
_08002A3C:
	ldm r1!, {r0}
	strh r2, [r0]
	subs r6, #1
	cmp r6, #0
	bge _08002A3C
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	mov r3, sl
	strh r0, [r3]
	mov r4, sb
	movs r0, #0
	ldrsb r0, [r4, r0]
	mov r7, r8
	strh r0, [r7]
	mov r0, ip
	movs r1, #0x10
	ldr r2, _08002C3C @ =gUnknown_0200B3B8
	bl LoadSpriteSets
	movs r1, #0
_08002A70:
	lsls r2, r1, #2
	mov r0, sp
	adds r4, r0, r2
	ldr r3, [r4]
	ldrh r0, [r3]
	adds r1, #1
	mov sb, r1
	cmp r0, #1
	bne _08002AEC
	ldr r1, _08002C40 @ =gUnknown_086A4CC0
	adds r1, r2, r1
	ldrh r0, [r1]
	strh r0, [r3, #2]
	ldr r2, [r4]
	ldrh r0, [r1, #2]
	strh r0, [r2, #4]
	adds r5, r4, #0
	ldr r1, _08002C44 @ =gOamBuffer
	mov ip, r1
	movs r7, #8
	movs r6, #3
_08002A9A:
	ldr r4, [r5]
	adds r4, r4, r7
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r4, r3]
	ldr r0, [r5]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _08002C48 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08002C4C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r7, #8
	subs r6, #1
	cmp r6, #0
	bge _08002A9A
_08002AEC:
	mov r1, sb
	cmp r1, #5
	ble _08002A70
	movs r0, #0x58
	mov r4, sl
	strh r0, [r4, #2]
	movs r0, #0x85
	strh r0, [r4, #4]
	ldr r5, _08002C44 @ =gOamBuffer
	movs r7, #0xd
	rsbs r7, r7, #0
	mov sb, r7
	ldr r0, _08002C4C @ =0xFFFFFE00
	mov ip, r0
	adds r4, #8
	movs r6, #1
_08002B0C:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldr r3, _08002C50 @ =gUnknown_0202BEE8
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r3, [r2, #5]
	movs r0, #0xf
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08002C48 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08002B0C
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _08002BEA
	ldr r2, _08002C54 @ =gUnknown_086A4CD8
	ldr r1, _08002C24 @ =gUnknown_0201A4F8
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3, #2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	ldr r5, _08002C44 @ =gOamBuffer
	movs r4, #0xd
	rsbs r4, r4, #0
	mov sb, r4
	ldr r7, _08002C4C @ =0xFFFFFE00
	mov ip, r7
	mov r4, r8
	adds r4, #8
	movs r6, #4
_08002BA2:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08002C48 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08002BA2
_08002BEA:
	movs r2, #0
	mov r1, sp
	movs r6, #5
_08002BF0:
	ldm r1!, {r0}
	strh r2, [r0]
	subs r6, #1
	cmp r6, #0
	bge _08002BF0
	movs r0, #0
	mov r1, sl
	strh r0, [r1]
	mov r2, r8
	strh r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002C14: .4byte gMain
_08002C18: .4byte 0x00000C14
_08002C1C: .4byte 0x00000808
_08002C20: .4byte 0x04000050
_08002C24: .4byte gUnknown_0201A4F8
_08002C28: .4byte gUnknown_0201A4C0
_08002C2C: .4byte gUnknown_0201A4F4
_08002C30: .4byte gUnknown_0201A4B0
_08002C34: .4byte gUnknown_086A4C80
_08002C38: .4byte 0xFFFFFBB0
_08002C3C: .4byte gUnknown_0200B3B8
_08002C40: .4byte gUnknown_086A4CC0
_08002C44: .4byte gOamBuffer
_08002C48: .4byte 0x000001FF
_08002C4C: .4byte 0xFFFFFE00
_08002C50: .4byte gUnknown_0202BEE8
_08002C54: .4byte gUnknown_086A4CD8
