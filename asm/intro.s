	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start IntroMain
IntroMain: @ 0x0800927C
	push {lr}
	ldr r1, _08009294 @ =gUnknown_080792CC
	ldr r0, _08009298 @ =gMain
	ldrb r0, [r0, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08009294: .4byte gUnknown_080792CC
_08009298: .4byte gMain

	thumb_func_start sub_929C
sub_929C: @ 0x0800929C
	push {r4, lr}
	bl ResetSomeGraphicsRelatedStuff
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r0, #0x80
	strh r0, [r3]
	ldr r1, _08009318 @ =0x0400000A
	movs r0, #5
	strh r0, [r1]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _0800931C @ =0x040000D4
	ldr r0, _08009320 @ =gUnknown_080798C0
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r2, _08009324 @ =0x80000400
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08009328 @ =gIntroCopyright_Gfx
	str r0, [r1]
	ldr r0, _0800932C @ =0x06004000
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08009330 @ =gIntroCopyright_Pal
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08009334 @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, _08009338 @ =gMain
	ldrh r0, [r3]
	movs r2, #0
	movs r1, #0
	strh r0, [r4, #0x16]
	ldr r0, _0800933C @ =gUnknown_0202BF10
	strh r1, [r0]
	ldr r0, _08009340 @ =gUnknown_0202C790
	strb r2, [r0]
	ldr r0, _08009344 @ =sub_93F8 + 1
	bl SetMainCallback
	bl sub_CBC
	bl sub_24C
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009318: .4byte 0x0400000A
_0800931C: .4byte 0x040000D4
_08009320: .4byte gUnknown_080798C0
_08009324: .4byte 0x80000400
_08009328: .4byte gIntroCopyright_Gfx
_0800932C: .4byte 0x06004000
_08009330: .4byte gIntroCopyright_Pal
_08009334: .4byte 0x80000100
_08009338: .4byte gMain
_0800933C: .4byte gUnknown_0202BF10
_08009340: .4byte gUnknown_0202C790
_08009344: .4byte sub_93F8 + 1

	thumb_func_start sub_9348
sub_9348: @ 0x08009348
	ldr r1, _08009368 @ =gUnknown_0202BF10
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble _08009364
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800936C @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
_08009364:
	bx lr
	.align 2, 0
_08009368: .4byte gUnknown_0202BF10
_0800936C: .4byte gMain

	thumb_func_start sub_9370
sub_9370: @ 0x08009370
	push {lr}
	movs r0, #0
	bl sub_FF74
	bl sub_D10
	ldr r1, _08009388 @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	pop {r0}
	bx r0
	.align 2, 0
_08009388: .4byte gMain

	thumb_func_start sub_938C
sub_938C: @ 0x0800938C
	push {lr}
	ldr r1, _080093C0 @ =gUnknown_080792E0
	ldr r0, _080093C4 @ =gUnknown_0202C790
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r1, _080093C8 @ =gUnknown_0202BF10
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080093CC @ =gMain
	ldrh r1, [r2, #0x18]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _080093BA
	movs r0, #4
	strb r0, [r2, #3]
_080093BA:
	pop {r0}
	bx r0
	.align 2, 0
_080093C0: .4byte gUnknown_080792E0
_080093C4: .4byte gUnknown_0202C790
_080093C8: .4byte gUnknown_0202BF10
_080093CC: .4byte gMain

	thumb_func_start sub_93D0
sub_93D0: @ 0x080093D0
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	bl ResetMainCallback
	ldr r1, _080093F4 @ =gAutoDisplayTitlescreenMenu
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	bl SetMainGameState
	pop {r0}
	bx r0
	.align 2, 0
_080093F4: .4byte gAutoDisplayTitlescreenMenu

	thumb_func_start sub_93F8
sub_93F8: @ 0x080093F8
	push {lr}
	ldr r0, _08009480 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800947C
	bl m4aSoundMain
	bl VBlankIntrWait
	ldr r1, _08009484 @ =0x040000D4
	ldr r0, _08009488 @ =gOamBuffer
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800948C @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldr r1, _08009490 @ =gMain
	ldrh r0, [r1, #0x16]
	strh r0, [r2]
	adds r2, #0x10
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	ldr r0, _08009494 @ =0x000002F6
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
_0800947C:
	pop {r0}
	bx r0
	.align 2, 0
_08009480: .4byte 0x04000004
_08009484: .4byte 0x040000D4
_08009488: .4byte gOamBuffer
_0800948C: .4byte 0x84000100
_08009490: .4byte gMain
_08009494: .4byte 0x000002F6

	thumb_func_start sub_9498
sub_9498: @ 0x08009498
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl ClearGraphicsMemory
	bl sub_518
	bl ClearSprites
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800961C @ =0x04000008
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08009620 @ =0x0400000A
	ldr r3, _08009624 @ =0x00005B01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08009628 @ =0x0400000C
	ldr r3, _0800962C @ =0x00005D02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #3
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08009630 @ =0x0400000E
	ldr r3, _08009634 @ =0x00001F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #4
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08009638 @ =0x040000D4
	ldr r0, _0800963C @ =gUnknown_080B9CC0
	str r0, [r4]
	ldr r0, _08009640 @ =0x0600D000
	str r0, [r4, #4]
	ldr r2, _08009644 @ =0x80000400
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08009648 @ =gUnknown_080BC4C0
	str r0, [r4]
	ldr r0, _0800964C @ =0x0600D800
	str r0, [r4, #4]
	ldr r1, _08009650 @ =0x80000800
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08009654 @ =gUnknown_080BB4C0
	str r0, [r4]
	ldr r0, _08009658 @ =0x0600E800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800965C @ =gUnknown_080B3CA0
	str r0, [r4]
	ldr r0, _08009660 @ =0x0600F800
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08009664 @ =gUnknown_080B44A0
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08009668 @ =0x80002C00
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0800966C @ =gUnknown_080BD4C0
	str r0, [r4]
	ldr r0, _08009670 @ =gUnknown_0201C1C0
	str r0, [r4, #4]
	ldr r0, _08009674 @ =0x80003400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r6, _08009678 @ =gIntroScene1Sprites_Pals
	movs r0, #0xa0
	lsls r0, r0, #0x13
	mov sl, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, #0
	mov r1, sl
	movs r3, #0x20
	bl sub_10170
	ldr r0, _0800967C @ =gIntroScene1Sprites_Gfx
	str r0, [r4]
	ldr r0, _08009680 @ =0x06010000
	str r0, [r4, #4]
	ldr r0, _08009684 @ =0x80004000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	str r6, [r4]
	ldr r5, _08009688 @ =0x05000200
	str r5, [r4, #4]
	ldr r1, _0800968C @ =0x80000100
	mov r8, r1
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_96A8
	ldr r1, _08009690 @ =gMain
	ldr r2, _08009694 @ =gUnknown_0202ADA0
	ldrh r3, [r2]
	movs r7, #0xba
	lsls r7, r7, #2
	adds r0, r1, r7
	movs r7, #0
	mov sb, r7
	strh r3, [r0]
	ldrh r3, [r2, #2]
	ldr r7, _08009698 @ =0x000002EA
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #0x24]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #0x26]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #0xc]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #0xe]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r3, [r2, #0x18]
	adds r7, #2
	adds r0, r1, r7
	strh r3, [r0]
	ldrh r0, [r2, #0x1a]
	ldr r2, _0800969C @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_CBC
	mov r0, sl
	adds r1, r6, #0
	movs r2, #0
	bl sub_FEB8
	str r6, [r4]
	str r5, [r4, #4]
	mov r3, r8
	str r3, [r4, #8]
	ldr r0, [r4, #8]
	mov r7, sb
	str r7, [r4]
	str r5, [r4, #4]
	ldr r0, _080096A0 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _080096A4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800961C: .4byte 0x04000008
_08009620: .4byte 0x0400000A
_08009624: .4byte 0x00005B01
_08009628: .4byte 0x0400000C
_0800962C: .4byte 0x00005D02
_08009630: .4byte 0x0400000E
_08009634: .4byte 0x00001F03
_08009638: .4byte 0x040000D4
_0800963C: .4byte gUnknown_080B9CC0
_08009640: .4byte 0x0600D000
_08009644: .4byte 0x80000400
_08009648: .4byte gUnknown_080BC4C0
_0800964C: .4byte 0x0600D800
_08009650: .4byte 0x80000800
_08009654: .4byte gUnknown_080BB4C0
_08009658: .4byte 0x0600E800
_0800965C: .4byte gUnknown_080B3CA0
_08009660: .4byte 0x0600F800
_08009664: .4byte gUnknown_080B44A0
_08009668: .4byte 0x80002C00
_0800966C: .4byte gUnknown_080BD4C0
_08009670: .4byte gUnknown_0201C1C0
_08009674: .4byte 0x80003400
_08009678: .4byte gIntroScene1Sprites_Pals
_0800967C: .4byte gIntroScene1Sprites_Gfx
_08009680: .4byte 0x06010000
_08009684: .4byte 0x80004000
_08009688: .4byte 0x05000200
_0800968C: .4byte 0x80000100
_08009690: .4byte gMain
_08009694: .4byte gUnknown_0202ADA0
_08009698: .4byte 0x000002EA
_0800969C: .4byte 0x000002F6
_080096A0: .4byte 0x80000010
_080096A4: .4byte gUnknown_0202C790

	thumb_func_start sub_96A8
sub_96A8: @ 0x080096A8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _0800975C @ =gUnknown_0201A450
	mov ip, r0
	movs r5, #0
	movs r2, #0
	movs r1, #0x78
	mov r8, r1
	mov r1, r8
	strh r1, [r0, #0x10]
	movs r6, #0x50
	strh r6, [r0, #0x12]
	strh r2, [r0, #0x18]
	movs r4, #1
	strb r4, [r0, #0x1c]
	movs r0, #0x9c
	mov r1, ip
	strh r0, [r1, #0x30]
	movs r0, #0x92
	strh r0, [r1, #0x32]
	mov r0, ip
	adds r0, #0x3c
	strb r5, [r0]
	strh r2, [r1, #0x3a]
	movs r0, #0x9d
	strh r0, [r1, #0x20]
	movs r0, #0x93
	strh r0, [r1, #0x22]
	mov r0, ip
	adds r0, #0x2c
	strb r5, [r0]
	adds r0, #0x14
	movs r1, #0x80
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #0xa
	strb r4, [r0]
	ldr r0, _08009760 @ =gUnknown_0202ADA0
	ldr r1, _08009764 @ =0x0000FFA8
	strh r1, [r0]
	adds r1, #0x22
	strh r1, [r0, #2]
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	movs r3, #0x80
	lsls r3, r3, #1
	strh r3, [r0, #0xc]
	strh r2, [r0, #0xe]
	strh r2, [r0, #0x14]
	movs r1, #0xfb
	strh r1, [r0, #0x24]
	strh r2, [r0, #0x26]
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	mov r1, r8
	mov r0, ip
	strh r1, [r0]
	strh r6, [r0, #2]
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strb r4, [r0, #0xc]
	ldr r0, _08009768 @ =gUnknown_0201C1B8
	strb r5, [r0]
	ldr r1, _0800976C @ =gUnknown_0202ADD4
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _08009770 @ =gUnknown_0202C594
	strh r2, [r0]
	ldr r0, _08009774 @ =gUnknown_02019C30
	str r3, [r0]
	ldr r0, _08009778 @ =gUnknown_0201C188
	str r3, [r0]
	ldr r0, _0800977C @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _08009780 @ =gUnknown_0202A578
	strh r2, [r0]
	ldr r1, _08009784 @ =gUnknown_0202BEF0
	movs r0, #0x20
	str r0, [r1]
	ldr r1, _08009788 @ =gUnknown_0202C5A8
	movs r0, #8
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800975C: .4byte gUnknown_0201A450
_08009760: .4byte gUnknown_0202ADA0
_08009764: .4byte 0x0000FFA8
_08009768: .4byte gUnknown_0201C1B8
_0800976C: .4byte gUnknown_0202ADD4
_08009770: .4byte gUnknown_0202C594
_08009774: .4byte gUnknown_02019C30
_08009778: .4byte gUnknown_0201C188
_0800977C: .4byte gUnknown_0202BF10
_08009780: .4byte gUnknown_0202A578
_08009784: .4byte gUnknown_0202BEF0
_08009788: .4byte gUnknown_0202C5A8

	thumb_func_start sub_978C
sub_978C: @ 0x0800978C
	push {r4, r5, r6, lr}
	bl sub_9CB8
	ldr r1, _080097C0 @ =gUnknown_0201A450
	ldrh r2, [r1, #8]
	movs r3, #8
	ldrsh r0, [r1, r3]
	cmp r0, #0x24
	bne _080097CC
	ldrh r0, [r1, #0xa]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1b
	ble _0800981A
	strh r2, [r1, #0xa]
	ldr r0, _080097C4 @ =gUnknown_0202A578
	strh r2, [r0]
	ldr r1, _080097C8 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0800981A
	.align 2, 0
_080097C0: .4byte gUnknown_0201A450
_080097C4: .4byte gUnknown_0202A578
_080097C8: .4byte gUnknown_0202C790
_080097CC:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080097E2
	movs r0, #0
	strh r0, [r1, #0xa]
	adds r0, r2, #1
	strh r0, [r1, #8]
_080097E2:
	ldr r3, _08009820 @ =gUnknown_0202BF10
	ldr r5, _08009824 @ =gUnknown_086A77A8
	ldr r4, _08009828 @ =gUnknown_0202A578
	movs r6, #0
	ldrsh r2, [r4, r6]
	lsls r2, r2, #2
	ldr r0, _0800982C @ =gUnknown_0202C5A8
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r0, r5, #2
	adds r0, r2, r0
	movs r6, #0
	ldrsh r1, [r3, r6]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _0800981A
	adds r0, r2, r5
	ldrh r0, [r0]
	bl m4aSongNumStart
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0800981A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08009820: .4byte gUnknown_0202BF10
_08009824: .4byte gUnknown_086A77A8
_08009828: .4byte gUnknown_0202A578
_0800982C: .4byte gUnknown_0202C5A8

	thumb_func_start sub_9830
sub_9830: @ 0x08009830
	push {lr}
	ldr r0, _08009868 @ =gUnknown_02019C30
	ldr r2, [r0]
	subs r2, #0x10
	str r2, [r0]
	ldr r1, _0800986C @ =gUnknown_0201C188
	ldr r0, [r1]
	subs r0, #0x10
	str r0, [r1]
	ldr r1, _08009870 @ =gUnknown_0201A450
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	cmp r2, #0x1f
	bgt _0800985E
	movs r0, #0
	strh r0, [r1, #0xa]
	movs r0, #0x25
	strh r0, [r1, #8]
	ldr r1, _08009874 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800985E:
	bl sub_9D70
	pop {r0}
	bx r0
	.align 2, 0
_08009868: .4byte gUnknown_02019C30
_0800986C: .4byte gUnknown_0201C188
_08009870: .4byte gUnknown_0201A450
_08009874: .4byte gUnknown_0202C790

	thumb_func_start sub_9878
sub_9878: @ 0x08009878
	push {lr}
	ldr r1, _080098AC @ =gUnknown_0201A450
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080098A8
	movs r0, #0
	strh r0, [r1, #0xa]
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0x58
	strh r0, [r1, #2]
	movs r0, #1
	strb r0, [r1, #0xc]
	movs r0, #0xd8
	bl m4aSongNumStart
	ldr r1, _080098B0 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080098A8:
	pop {r0}
	bx r0
	.align 2, 0
_080098AC: .4byte gUnknown_0201A450
_080098B0: .4byte gUnknown_0202C790

	thumb_func_start sub_98B4
sub_98B4: @ 0x080098B4
	push {lr}
	ldr r1, _080098F0 @ =gUnknown_0201A450
	ldrh r2, [r1, #8]
	movs r3, #8
	ldrsh r0, [r1, r3]
	cmp r0, #0x2b
	bne _08009900
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08009916
	movs r0, #0
	strb r0, [r1, #0xc]
	ldr r0, _080098F4 @ =gIntroScene1Sprites_Pals+0x1C0
	ldr r1, _080098F8 @ =0x050000E0
	movs r2, #0x20
	movs r3, #0
	bl sub_10170
	movs r0, #8
	bl m4aSongNumStart
	ldr r1, _080098FC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08009916
	.align 2, 0
_080098F0: .4byte gUnknown_0201A450
_080098F4: .4byte gIntroScene1Sprites_Pals+0x1C0
_080098F8: .4byte 0x050000E0
_080098FC: .4byte gUnknown_0202C790
_08009900:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08009916
	movs r0, #0
	strh r0, [r1, #0xa]
	adds r0, r2, #1
	strh r0, [r1, #8]
_08009916:
	bl sub_9CB8
	pop {r0}
	bx r0

	thumb_func_start sub_9920
sub_9920: @ 0x08009920
	push {lr}
	ldr r0, _08009954 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08009982
	ldr r1, _08009958 @ =gUnknown_0202C594
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #7
	bgt _08009964
	adds r0, r2, #1
	strh r0, [r1]
	ldr r1, _0800995C @ =gUnknown_0201C1B8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08009960 @ =gUnknown_0202ADD4
	ldrb r0, [r1]
	subs r0, #1
	b _08009976
	.align 2, 0
_08009954: .4byte gUnknown_0202BF10
_08009958: .4byte gUnknown_0202C594
_0800995C: .4byte gUnknown_0201C1B8
_08009960: .4byte gUnknown_0202ADD4
_08009964:
	ldr r0, _0800998C @ =gUnknown_0201C1C0
	ldr r1, _08009990 @ =0x060036E0
	movs r2, #8
	movs r3, #8
	bl sub_10708
	ldr r1, _08009994 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
_08009976:
	strb r0, [r1]
	ldr r2, _08009998 @ =gUnknown_0201A450
	ldrh r1, [r2, #0x18]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2, #0x18]
_08009982:
	bl sub_9E90
	pop {r0}
	bx r0
	.align 2, 0
_0800998C: .4byte gUnknown_0201C1C0
_08009990: .4byte 0x060036E0
_08009994: .4byte gUnknown_0202C790
_08009998: .4byte gUnknown_0201A450

	thumb_func_start sub_999C
sub_999C: @ 0x0800999C
	push {r4, r5, lr}
	ldr r5, _08009A84 @ =gUnknown_0202BEF0
	ldr r0, [r5]
	cmp r0, #0
	ble _080099D0
	subs r0, #2
	str r0, [r5]
	cmp r0, #0
	bgt _080099B2
	movs r0, #0
	str r0, [r5]
_080099B2:
	ldr r4, _08009A88 @ =gIntroScene1Sprites_Pals
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	ldrh r3, [r5]
	adds r0, r4, #0
	bl sub_10170
	ldr r1, _08009A8C @ =0x05000200
	ldrh r3, [r5]
	adds r0, r4, #0
	movs r2, #0x20
	bl sub_10170
_080099D0:
	ldr r5, _08009A90 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080099EC
	ldr r2, _08009A94 @ =gUnknown_0201A450
	ldrh r1, [r2, #0x18]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2, #0x18]
_080099EC:
	ldr r4, _08009A98 @ =gUnknown_0202ADA0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldrh r0, [r5]
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	bne _08009A04
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
_08009A04:
	ldr r1, _08009A9C @ =gMain
	ldrh r2, [r4]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #2]
	ldr r2, _08009AA0 @ =0x000002EA
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	ldr r2, _08009AA4 @ =gUnknown_086A7768
	movs r1, #8
	ldrsh r3, [r4, r1]
	lsls r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _08009A78
	ldr r1, _08009AA8 @ =gUnknown_086A7788
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, _08009AAC @ =gUnknown_0201C1C0
	adds r0, r0, r1
	ldr r1, _08009AB0 @ =0x060036E0
	movs r2, #8
	movs r3, #8
	bl sub_10708
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08009A78
	ldr r1, _08009A94 @ =gUnknown_0201A450
	adds r0, r1, #0
	adds r0, #0x3c
	strb r5, [r0]
	subs r0, #0x10
	strb r5, [r0]
	movs r0, #0
	strb r0, [r1, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x14]
	ldr r1, _08009AB4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08009A78:
	bl sub_9E90
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08009A84: .4byte gUnknown_0202BEF0
_08009A88: .4byte gIntroScene1Sprites_Pals
_08009A8C: .4byte 0x05000200
_08009A90: .4byte gUnknown_0202BF10
_08009A94: .4byte gUnknown_0201A450
_08009A98: .4byte gUnknown_0202ADA0
_08009A9C: .4byte gMain
_08009AA0: .4byte 0x000002EA
_08009AA4: .4byte gUnknown_086A7768
_08009AA8: .4byte gUnknown_086A7788
_08009AAC: .4byte gUnknown_0201C1C0
_08009AB0: .4byte 0x060036E0
_08009AB4: .4byte gUnknown_0202C790

	thumb_func_start sub_9AB8
sub_9AB8: @ 0x08009AB8
	push {r4, lr}
	ldr r1, _08009B54 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x30]
	subs r0, #0xe
	strh r0, [r1, #0x30]
	ldrh r0, [r1, #0x32]
	subs r0, #0xd
	strh r0, [r1, #0x32]
	ldr r3, _08009B58 @ =gUnknown_0202ADA0
	ldrh r0, [r3, #0x24]
	subs r0, #0x10
	strh r0, [r3, #0x24]
	ldrh r0, [r3, #0x26]
	adds r0, #1
	strh r0, [r3, #0x26]
	ldrh r0, [r3, #0xc]
	subs r0, #0x10
	strh r0, [r3, #0xc]
	ldrh r0, [r1, #0x20]
	subs r0, #0xe
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	subs r0, #0xd
	strh r0, [r1, #0x22]
	adds r2, r1, #0
	adds r2, #0x40
	ldrh r0, [r2]
	adds r0, #0xb
	strh r0, [r2]
	adds r1, #0x42
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	ldr r0, _08009B5C @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	bne _08009B14
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
_08009B14:
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	ldr r2, _08009B60 @ =gUnknown_086A7768
	movs r1, #8
	ldrsh r3, [r4, r1]
	lsls r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _08009B94
	adds r0, r3, #0
	cmp r0, #6
	bgt _08009B70
	ldr r1, _08009B64 @ =gUnknown_086A7788
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	ldr r1, _08009B68 @ =gUnknown_0201C1C0
	adds r0, r0, r1
	ldr r1, _08009B6C @ =0x060036E0
	movs r2, #8
	movs r3, #8
	bl sub_10708
	b _08009B8A
	.align 2, 0
_08009B54: .4byte gUnknown_0201A450
_08009B58: .4byte gUnknown_0202ADA0
_08009B5C: .4byte gUnknown_0202BF10
_08009B60: .4byte gUnknown_086A7768
_08009B64: .4byte gUnknown_086A7788
_08009B68: .4byte gUnknown_0201C1C0
_08009B6C: .4byte 0x060036E0
_08009B70:
	ldr r1, _08009BF0 @ =gUnknown_086A7788
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	ldr r1, _08009BF4 @ =gUnknown_0201C1C0
	adds r0, r0, r1
	ldr r1, _08009BF8 @ =0x060032C0
	movs r2, #0xa
	movs r3, #0xa
	bl sub_10708
_08009B8A:
	ldr r1, _08009BFC @ =gUnknown_0202ADA0
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	adds r4, r1, #0
_08009B94:
	adds r1, r4, #0
	ldrh r0, [r1, #0x14]
	adds r0, #1
	strh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08009BB0
	movs r0, #0
	strh r0, [r1, #0x14]
	ldr r1, _08009C00 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_08009BB0:
	bl sub_9E90
	ldr r1, _08009C04 @ =gMain
	ldrh r2, [r4]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x26]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0xe]
	ldr r2, _08009C08 @ =0x000002F2
	adds r1, r1, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009BF0: .4byte gUnknown_086A7788
_08009BF4: .4byte gUnknown_0201C1C0
_08009BF8: .4byte 0x060032C0
_08009BFC: .4byte gUnknown_0202ADA0
_08009C00: .4byte gUnknown_0202C790
_08009C04: .4byte gMain
_08009C08: .4byte 0x000002F2

	thumb_func_start nullsub_4
nullsub_4: @ 0x08009C0C
	bx lr

	thumb_func_start sub_9C10
sub_9C10: @ 0x08009C10
	push {r4, lr}
	ldr r4, _08009C7C @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	ldr r0, _08009C80 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08009C40
	ldr r1, _08009C84 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x30]
	subs r0, #1
	strh r0, [r1, #0x30]
	ldrh r0, [r1, #0x32]
	subs r0, #1
	strh r0, [r1, #0x32]
	ldrh r0, [r1, #0x20]
	subs r0, #2
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	subs r0, #2
	strh r0, [r1, #0x22]
_08009C40:
	bl sub_9E90
	ldr r1, _08009C88 @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x1a]
	ldr r2, _08009C8C @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	ldr r1, _08009C84 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x3a]
	adds r0, #1
	strh r0, [r1, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _08009C74
	movs r0, #0
	strh r0, [r1, #0x3a]
	ldr r1, _08009C90 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
_08009C74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009C7C: .4byte gUnknown_0202ADA0
_08009C80: .4byte gUnknown_0202BF10
_08009C84: .4byte gUnknown_0201A450
_08009C88: .4byte gMain
_08009C8C: .4byte 0x000002F6
_08009C90: .4byte gUnknown_0202C790

	thumb_func_start nullsub_5
nullsub_5: @ 0x08009C94
	bx lr

	thumb_func_start nullsub_17
nullsub_17: @ 0x08009C98
	bx lr

	thumb_func_start sub_9C9C
sub_9C9C: @ 0x08009C9C
	push {lr}
	bl sub_10480
	bl sub_10544
	ldr r1, _08009CB4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08009CB4: .4byte gUnknown_0202C790

	thumb_func_start sub_9CB8
sub_9CB8: @ 0x08009CB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08009D54 @ =gUnknown_0201A450
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, _08009D58 @ =gUnknown_0200B698
	adds r5, r0, r2
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	strh r0, [r5]
	ldr r6, _08009D5C @ =gUnknown_086A769C
	ldr r1, _08009D60 @ =0xFFFFFD20
	adds r2, r2, r1
	adds r0, r6, #0
	movs r1, #0x31
	bl LoadSpriteSets
	ldrh r0, [r5]
	cmp r0, #1
	bne _08009D46
	ldrh r0, [r4]
	strh r0, [r5, #2]
	ldrh r0, [r4, #2]
	strh r0, [r5, #4]
	movs r2, #8
	ldrsh r0, [r4, r2]
	adds r0, #4
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r7, [r0]
	movs r6, #0
	ldrh r0, [r7]
	cmp r6, r0
	bge _08009D46
	ldr r1, _08009D64 @ =gOamBuffer
	mov ip, r1
	ldr r2, _08009D68 @ =0xFFFFFE00
	mov r8, r2
	adds r4, r5, #0
	adds r4, #8
_08009D0E:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, ip
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	ldr r2, _08009D6C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r5, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r6, #1
	ldrh r0, [r7]
	cmp r6, r0
	blt _08009D0E
_08009D46:
	movs r0, #0
	strh r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009D54: .4byte gUnknown_0201A450
_08009D58: .4byte gUnknown_0200B698
_08009D5C: .4byte gUnknown_086A769C
_08009D60: .4byte 0xFFFFFD20
_08009D64: .4byte gOamBuffer
_08009D68: .4byte 0xFFFFFE00
_08009D6C: .4byte 0x000001FF

	thumb_func_start sub_9D70
sub_9D70: @ 0x08009D70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08009E68 @ =gUnknown_0200D078
	mov r8, r0
	ldr r6, _08009E6C @ =gUnknown_0201A450
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r0, _08009E70 @ =gUnknown_086A769C
	ldr r2, _08009E74 @ =0xFFFFE340
	add r2, r8
	movs r1, #0x31
	bl LoadSpriteSets
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, #1
	bne _08009E50
	ldr r5, _08009E78 @ =gUnknown_02019C30
	movs r3, #0
	ldrsh r0, [r5, r3]
	ldr r4, _08009E7C @ =gUnknown_0201C188
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r2, #0
	bl SetMatrixScale
	ldrh r0, [r6]
	mov r3, r8
	strh r0, [r3, #2]
	ldrh r0, [r6, #2]
	strh r0, [r3, #4]
	movs r7, #0
	ldr r6, _08009E80 @ =gOamBuffer
	mov sl, r5
	mov sb, r4
	mov r5, r8
	adds r5, #8
	movs r0, #0xf
	rsbs r0, r0, #0
	mov ip, r0
_08009DCC:
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r3, r0, r6
	lsls r0, r7, #2
	ldr r1, _08009E84 @ =gUnknown_086A7798
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	mov r2, sl
	ldr r0, [r2]
	muls r1, r0, r1
	cmp r1, #0
	bge _08009DE8
	adds r1, #0xff
_08009DE8:
	asrs r1, r1, #8
	str r1, [sp]
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [sp]
	adds r1, r2, r0
	ldr r2, _08009E88 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08009E8C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r6
	movs r3, #2
	ldrsh r1, [r4, r3]
	mov r3, sb
	ldr r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	bge _08009E1C
	adds r0, #0xff
_08009E1C:
	asrs r0, r0, #8
	mov r1, r8
	ldrb r1, [r1, #4]
	adds r0, r0, r1
	strb r0, [r2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #3]
	mov r0, ip
	ands r0, r2
	strb r0, [r1, #3]
	adds r5, #8
	adds r7, #1
	cmp r7, #3
	ble _08009DCC
_08009E50:
	movs r0, #0
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
_08009E68: .4byte gUnknown_0200D078
_08009E6C: .4byte gUnknown_0201A450
_08009E70: .4byte gUnknown_086A769C
_08009E74: .4byte 0xFFFFE340
_08009E78: .4byte gUnknown_02019C30
_08009E7C: .4byte gUnknown_0201C188
_08009E80: .4byte gOamBuffer
_08009E84: .4byte gUnknown_086A7798
_08009E88: .4byte 0x000001FF
_08009E8C: .4byte 0xFFFFFE00

	thumb_func_start sub_9E90
sub_9E90: @ 0x08009E90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r3, _0800A12C @ =gMain
	ldrh r0, [r3, #0x38]
	movs r0, #0xf1
	lsls r0, r0, #4
	strh r0, [r3, #0x38]
	ldr r0, _0800A130 @ =gUnknown_0201C1B8
	ldrb r1, [r0]
	ldr r0, _0800A134 @ =gUnknown_0202ADD4
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	ldrh r0, [r3, #0x3a]
	strh r1, [r3, #0x3a]
	ldr r1, _0800A138 @ =0x04000050
	ldrh r0, [r3, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r3, #0x3a]
	strh r0, [r1]
	ldr r4, _0800A13C @ =gUnknown_0201A450
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	movs r0, #0xb8
	muls r0, r1, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r2, r3, r1
	adds r0, r0, r2
	mov r8, r0
	movs r6, #0xa4
	lsls r6, r6, #3
	adds r6, r6, r3
	mov sb, r6
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r7, r7, r3
	mov sl, r7
	movs r0, #0x1c
	ldrsb r0, [r4, r0]
	mov r1, r8
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r6]
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r7]
	adds r0, r4, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r6, _0800A140 @ =gUnknown_0200D638
	strh r0, [r6]
	ldr r5, _0800A144 @ =gUnknown_086A769C
	adds r0, r5, #0
	movs r1, #0x31
	bl LoadSpriteSets
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _08009F9E
	ldrh r0, [r4, #0x10]
	strh r0, [r7, #2]
	ldrh r0, [r4, #0x12]
	strh r0, [r7, #4]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [sp]
	movs r5, #0
	ldrh r2, [r0]
	cmp r5, r2
	bge _08009F9E
	ldr r7, _0800A148 @ =gOamBuffer
	ldr r6, _0800A14C @ =0xFFFFFE00
	mov ip, r6
	mov r4, r8
	adds r4, #8
_08009F4C:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r1, [r2, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, r8
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r2, _0800A150 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r6, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	adds r5, #1
	ldr r6, [sp]
	ldrh r6, [r6]
	cmp r5, r6
	blt _08009F4C
_08009F9E:
	mov r7, sb
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800A01C
	ldr r0, _0800A13C @ =gUnknown_0201A450
	ldrh r1, [r0, #0x20]
	strh r1, [r7, #2]
	ldrh r0, [r0, #0x22]
	strh r0, [r7, #4]
	ldr r6, _0800A148 @ =gOamBuffer
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	mov r4, sb
	adds r4, #8
	movs r5, #3
_08009FBE:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	mov r0, ip
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, ip
	ands r0, r2
	movs r7, #4
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800A150 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800A14C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, sb
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _08009FBE
_0800A01C:
	mov r6, sl
	ldrh r0, [r6]
	cmp r0, #1
	bne _0800A098
	ldr r0, _0800A13C @ =gUnknown_0201A450
	ldrh r1, [r0, #0x30]
	strh r1, [r6, #2]
	ldrh r0, [r0, #0x32]
	strh r0, [r6, #4]
	ldr r6, _0800A148 @ =gOamBuffer
	ldr r7, _0800A14C @ =0xFFFFFE00
	mov ip, r7
	mov r4, sl
	adds r4, #8
	movs r5, #3
_0800A03A:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800A150 @ =0x000001FF
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
	mov r7, sl
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800A03A
_0800A098:
	ldr r6, _0800A140 @ =gUnknown_0200D638
	ldrh r0, [r6]
	cmp r0, #1
	bne _0800A10A
	ldr r0, _0800A13C @ =gUnknown_0201A450
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r1, [r1]
	strh r1, [r6, #2]
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldr r6, _0800A148 @ =gOamBuffer
	movs r7, #0xd
	rsbs r7, r7, #0
	mov ip, r7
	ldr r4, _0800A140 @ =gUnknown_0200D638
	adds r4, #8
	movs r5, #7
_0800A0BE:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, ip
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	ldr r2, _0800A140 @ =gUnknown_0200D638
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800A150 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800A14C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldr r7, _0800A140 @ =gUnknown_0200D638
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800A0BE
_0800A10A:
	movs r0, #0
	mov r6, r8
	strh r0, [r6]
	mov r7, sb
	strh r0, [r7]
	mov r1, sl
	strh r0, [r1]
	ldr r2, _0800A140 @ =gUnknown_0200D638
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
_0800A12C: .4byte gMain
_0800A130: .4byte gUnknown_0201C1B8
_0800A134: .4byte gUnknown_0202ADD4
_0800A138: .4byte 0x04000050
_0800A13C: .4byte gUnknown_0201A450
_0800A140: .4byte gUnknown_0200D638
_0800A144: .4byte gUnknown_086A769C
_0800A148: .4byte gOamBuffer
_0800A14C: .4byte 0xFFFFFE00
_0800A150: .4byte 0x000001FF

	thumb_func_start sub_A154
sub_A154: @ 0x0800A154
	push {lr}
	bl sub_518
	ldr r1, _0800A168 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800A168: .4byte gUnknown_0202C790

	thumb_func_start sub_A16C
sub_A16C: @ 0x0800A16C
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0
	strh r0, [r2]
	ldr r1, _0800A250 @ =0x04000008
	movs r3, #0xcc
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800A254 @ =0x0400000A
	ldr r3, _0800A258 @ =0x0000DA01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800A25C @ =0x0400000E
	ldr r3, _0800A260 @ =0x00001E03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800A264 @ =0x040000D4
	ldr r1, _0800A268 @ =gUnknown_080D0700
	str r1, [r0]
	ldr r1, _0800A26C @ =0x06006000
	str r1, [r0, #4]
	ldr r2, _0800A270 @ =0x80001000
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A274 @ =gUnknown_080D2700
	str r1, [r0]
	ldr r1, _0800A278 @ =0x0600D000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A27C @ =gUnknown_080CBEE0
	str r1, [r0]
	ldr r1, _0800A280 @ =0x0600F000
	str r1, [r0, #4]
	ldr r1, _0800A284 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A288 @ =gUnknown_080CC6E0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800A28C @ =0x80001E00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A290 @ =gUnknown_080CBCE0
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800A294 @ =0x80000040
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_A2A8
	ldr r1, _0800A298 @ =gMain
	ldr r3, _0800A29C @ =gUnknown_0202ADA0
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #6
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x1a]
	ldr r2, _0800A2A0 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800A2A4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A250: .4byte 0x04000008
_0800A254: .4byte 0x0400000A
_0800A258: .4byte 0x0000DA01
_0800A25C: .4byte 0x0400000E
_0800A260: .4byte 0x00001E03
_0800A264: .4byte 0x040000D4
_0800A268: .4byte gUnknown_080D0700
_0800A26C: .4byte 0x06006000
_0800A270: .4byte 0x80001000
_0800A274: .4byte gUnknown_080D2700
_0800A278: .4byte 0x0600D000
_0800A27C: .4byte gUnknown_080CBEE0
_0800A280: .4byte 0x0600F000
_0800A284: .4byte 0x80000400
_0800A288: .4byte gUnknown_080CC6E0
_0800A28C: .4byte 0x80001E00
_0800A290: .4byte gUnknown_080CBCE0
_0800A294: .4byte 0x80000040
_0800A298: .4byte gMain
_0800A29C: .4byte gUnknown_0202ADA0
_0800A2A0: .4byte 0x000002F6
_0800A2A4: .4byte gUnknown_0202C790

	thumb_func_start sub_A2A8
sub_A2A8: @ 0x0800A2A8
	ldr r0, _0800A2D8 @ =gUnknown_0202ADA0
	movs r2, #0
	movs r1, #0x1c
	strh r1, [r0]
	ldr r1, _0800A2DC @ =0x0000FF2C
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	movs r1, #0xe
	strh r1, [r0, #6]
	ldr r1, _0800A2E0 @ =0x0000FF5C
	strh r1, [r0, #0xc]
	subs r1, #0x54
	strh r1, [r0, #0xe]
	strh r2, [r0, #0x10]
	movs r1, #0x10
	strh r1, [r0, #0x12]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	strh r2, [r0, #0x20]
	ldr r0, _0800A2E4 @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _0800A2E8 @ =gUnknown_0202A578
	strh r2, [r0]
	bx lr
	.align 2, 0
_0800A2D8: .4byte gUnknown_0202ADA0
_0800A2DC: .4byte 0x0000FF2C
_0800A2E0: .4byte 0x0000FF5C
_0800A2E4: .4byte gUnknown_0202BF10
_0800A2E8: .4byte gUnknown_0202A578

	thumb_func_start nullsub_6
nullsub_6: @ 0x0800A2EC
	bx lr

	thumb_func_start sub_A2F0
sub_A2F0: @ 0x0800A2F0
	push {r4, lr}
	ldr r3, _0800A384 @ =gUnknown_0202ADA0
	ldrh r4, [r3, #6]
	ldrh r1, [r3, #2]
	adds r0, r4, r1
	strh r0, [r3, #2]
	ldrh r2, [r3, #0x12]
	ldrh r1, [r3, #0xe]
	adds r0, r2, r1
	strh r0, [r3, #0xe]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x1a]
	subs r0, #1
	strh r0, [r3, #0x1a]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	ldr r0, _0800A388 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800A330
	subs r0, r4, #1
	strh r0, [r3, #6]
	subs r0, r2, #1
	strh r0, [r3, #0x12]
_0800A330:
	ldr r1, _0800A38C @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #6
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x1a]
	ldr r2, _0800A390 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r3, #0x20]
	adds r0, #1
	strh r0, [r3, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x27
	ble _0800A37E
	movs r0, #0
	strh r0, [r3, #0x20]
	ldr r1, _0800A394 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800A37E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A384: .4byte gUnknown_0202ADA0
_0800A388: .4byte gUnknown_0202BF10
_0800A38C: .4byte gMain
_0800A390: .4byte 0x000002F6
_0800A394: .4byte gUnknown_0202C790

	thumb_func_start nullsub_7
nullsub_7: @ 0x0800A398
	bx lr

	thumb_func_start sub_A39C
sub_A39C: @ 0x0800A39C
	push {r4, lr}
	ldr r3, _0800A428 @ =gUnknown_0202ADA0
	ldrh r0, [r3, #2]
	adds r0, #1
	strh r0, [r3, #2]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x1a]
	subs r0, #1
	strh r0, [r3, #0x1a]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	ldr r0, _0800A42C @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800A3DC
	ldrh r0, [r3, #6]
	subs r0, #1
	strh r0, [r3, #6]
	ldrh r0, [r3, #0x12]
	subs r0, #1
	strh r0, [r3, #0x12]
_0800A3DC:
	ldr r1, _0800A430 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #6
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x1a]
	ldr r2, _0800A434 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_10480
	bl sub_10544
	ldr r1, _0800A438 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A428: .4byte gUnknown_0202ADA0
_0800A42C: .4byte gUnknown_0202BF10
_0800A430: .4byte gMain
_0800A434: .4byte 0x000002F6
_0800A438: .4byte gUnknown_0202C790

	thumb_func_start sub_A43C
sub_A43C: @ 0x0800A43C
	push {lr}
	bl sub_518
	ldr r1, _0800A450 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800A450: .4byte gUnknown_0202C790

	thumb_func_start sub_A454
sub_A454: @ 0x0800A454
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800A5A0 @ =0x04000008
	movs r3, #0xb4
	lsls r3, r3, #7
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800A5A4 @ =0x0400000A
	ldr r3, _0800A5A8 @ =0x00001C01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800A5AC @ =0x0400000C
	ldr r3, _0800A5B0 @ =0x00005D02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800A5B4 @ =0x0400000E
	ldr r3, _0800A5B8 @ =0x00001F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800A5BC @ =0x040000D4
	ldr r1, _0800A5C0 @ =gUnknown_080DE520
	str r1, [r0]
	ldr r1, _0800A5C4 @ =0x0600D000
	str r1, [r0, #4]
	ldr r3, _0800A5C8 @ =0x80000800
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5CC @ =gUnknown_080DCD20
	str r1, [r0]
	ldr r1, _0800A5D0 @ =0x0600E000
	str r1, [r0, #4]
	ldr r2, _0800A5D4 @ =0x80000400
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5D8 @ =gUnknown_080D4900
	str r1, [r0]
	ldr r1, _0800A5DC @ =0x0600E800
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5E0 @ =gUnknown_080D5900
	str r1, [r0]
	ldr r1, _0800A5E4 @ =0x0600F800
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5E8 @ =gUnknown_080DD520
	str r1, [r0]
	ldr r1, _0800A5EC @ =gUnknown_03005C00
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5F0 @ =gUnknown_080DDD20
	str r1, [r0]
	ldr r1, _0800A5F4 @ =gUnknown_0201B180
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A5F8 @ =gUnknown_080D6100
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800A5FC @ =0x80003600
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r3, _0800A600 @ =gUnknown_080D4700
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800A604 @ =0x80000070
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800A608 @ =gUnknown_080DF520
	str r1, [r0]
	ldr r1, _0800A60C @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800A610 @ =0x80001000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0800A614 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_A628
	bl sub_A87C
	ldr r1, _0800A618 @ =gMain
	ldr r2, _0800A61C @ =gUnknown_0202ADA0
	ldrh r3, [r2]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x18]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x1a]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x24]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r0, [r2, #0x26]
	ldr r2, _0800A620 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800A624 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A5A0: .4byte 0x04000008
_0800A5A4: .4byte 0x0400000A
_0800A5A8: .4byte 0x00001C01
_0800A5AC: .4byte 0x0400000C
_0800A5B0: .4byte 0x00005D02
_0800A5B4: .4byte 0x0400000E
_0800A5B8: .4byte 0x00001F03
_0800A5BC: .4byte 0x040000D4
_0800A5C0: .4byte gUnknown_080DE520
_0800A5C4: .4byte 0x0600D000
_0800A5C8: .4byte 0x80000800
_0800A5CC: .4byte gUnknown_080DCD20
_0800A5D0: .4byte 0x0600E000
_0800A5D4: .4byte 0x80000400
_0800A5D8: .4byte gUnknown_080D4900
_0800A5DC: .4byte 0x0600E800
_0800A5E0: .4byte gUnknown_080D5900
_0800A5E4: .4byte 0x0600F800
_0800A5E8: .4byte gUnknown_080DD520
_0800A5EC: .4byte gUnknown_03005C00
_0800A5F0: .4byte gUnknown_080DDD20
_0800A5F4: .4byte gUnknown_0201B180
_0800A5F8: .4byte gUnknown_080D6100
_0800A5FC: .4byte 0x80003600
_0800A600: .4byte gUnknown_080D4700
_0800A604: .4byte 0x80000070
_0800A608: .4byte gUnknown_080DF520
_0800A60C: .4byte 0x06010000
_0800A610: .4byte 0x80001000
_0800A614: .4byte 0x05000200
_0800A618: .4byte gMain
_0800A61C: .4byte gUnknown_0202ADA0
_0800A620: .4byte 0x000002F6
_0800A624: .4byte gUnknown_0202C790

	thumb_func_start sub_A628
sub_A628: @ 0x0800A628
	ldr r1, _0800A65C @ =gUnknown_0202ADA0
	movs r2, #0
	movs r0, #0x2c
	strh r0, [r1]
	ldr r0, _0800A660 @ =0x0000FF8E
	strh r0, [r1, #2]
	ldr r3, _0800A664 @ =gUnknown_0201A450
	adds r0, #0x46
	strh r0, [r3]
	movs r0, #0x72
	strh r0, [r3, #2]
	ldr r0, _0800A668 @ =0x0000FFCE
	strh r0, [r1, #0xc]
	movs r0, #0x1e
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x18]
	strh r2, [r1, #0x1a]
	strh r2, [r1, #0x20]
	strh r2, [r1, #0x24]
	strh r2, [r1, #0x26]
	ldr r0, _0800A66C @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _0800A670 @ =gUnknown_0202A578
	strh r2, [r0]
	bx lr
	.align 2, 0
_0800A65C: .4byte gUnknown_0202ADA0
_0800A660: .4byte 0x0000FF8E
_0800A664: .4byte gUnknown_0201A450
_0800A668: .4byte 0x0000FFCE
_0800A66C: .4byte gUnknown_0202BF10
_0800A670: .4byte gUnknown_0202A578

	thumb_func_start sub_A674
sub_A674: @ 0x0800A674
	push {r4, lr}
	ldr r4, _0800A6FC @ =gUnknown_0202ADA0
	ldrh r0, [r4]
	subs r0, #0x11
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #0xa
	strh r0, [r4, #2]
	ldr r1, _0800A700 @ =gUnknown_0201A450
	ldrh r0, [r1]
	adds r0, #0x11
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #0xa
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x18]
	adds r0, #0x10
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0xc]
	adds r0, #4
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	subs r0, #8
	strh r0, [r4, #0xe]
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0800A6BE
	movs r0, #0
	strh r0, [r4, #0x20]
	ldr r1, _0800A704 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800A6BE:
	bl sub_A87C
	ldr r1, _0800A708 @ =gMain
	ldrh r2, [r4]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x18]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x1a]
	ldr r2, _0800A70C @ =0x000002F2
	adds r1, r1, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A6FC: .4byte gUnknown_0202ADA0
_0800A700: .4byte gUnknown_0201A450
_0800A704: .4byte gUnknown_0202C790
_0800A708: .4byte gMain
_0800A70C: .4byte 0x000002F2

	thumb_func_start sub_A710
sub_A710: @ 0x0800A710
	push {r4, r5, r6, lr}
	ldr r5, _0800A7C8 @ =gUnknown_0202ADA0
	ldrh r0, [r5, #0x24]
	subs r0, #1
	movs r6, #0
	strh r0, [r5, #0x24]
	ldr r2, _0800A7CC @ =gUnknown_0202BF10
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800A742
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
	ldr r1, _0800A7D0 @ =gUnknown_0201A450
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #2
	strh r0, [r1, #2]
_0800A742:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800A776
	ldr r0, _0800A7D4 @ =0x040000D4
	movs r3, #0xa0
	lsls r3, r3, #0x13
	str r3, [r0]
	ldr r4, _0800A7D8 @ =gUnknown_0202BE70
	str r4, [r0, #4]
	ldr r1, _0800A7DC @ =0x80000010
	str r1, [r0, #8]
	ldr r2, [r0, #8]
	ldr r2, _0800A7E0 @ =0x05000040
	str r2, [r0]
	str r3, [r0, #4]
	str r1, [r0, #8]
	ldr r3, [r0, #8]
	str r4, [r0]
	str r2, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [r0, #8]
_0800A776:
	ldr r4, _0800A7E4 @ =gMain
	ldrh r1, [r5]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r5, #2]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r5, #0x24]
	adds r2, #0xa
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r5, #0x26]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	bl sub_A87C
	movs r1, #0x20
	ldrsh r0, [r5, r1]
	cmp r0, #2
	bne _0800A7F4
	ldr r1, _0800A7D4 @ =0x040000D4
	ldr r0, _0800A7E8 @ =gUnknown_03005C00
	str r0, [r1]
	ldr r0, _0800A7EC @ =0x0600E000
	str r0, [r1, #4]
	ldr r0, _0800A7F0 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	strh r6, [r5, #0xc]
	strh r6, [r5, #0xe]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	movs r1, #0
	adds r2, #2
	b _0800A818
	.align 2, 0
_0800A7C8: .4byte gUnknown_0202ADA0
_0800A7CC: .4byte gUnknown_0202BF10
_0800A7D0: .4byte gUnknown_0201A450
_0800A7D4: .4byte 0x040000D4
_0800A7D8: .4byte gUnknown_0202BE70
_0800A7DC: .4byte 0x80000010
_0800A7E0: .4byte 0x05000040
_0800A7E4: .4byte gMain
_0800A7E8: .4byte gUnknown_03005C00
_0800A7EC: .4byte 0x0600E000
_0800A7F0: .4byte 0x80000400
_0800A7F4:
	cmp r0, #4
	bne _0800A81C
	ldr r1, _0800A840 @ =0x040000D4
	ldr r0, _0800A844 @ =gUnknown_0201B180
	str r0, [r1]
	ldr r0, _0800A848 @ =0x0600E000
	str r0, [r1, #4]
	ldr r0, _0800A84C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	strh r6, [r5, #0xc]
	strh r6, [r5, #0xe]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
	movs r1, #0
	ldr r2, _0800A850 @ =0x000002EE
_0800A818:
	adds r0, r4, r2
	strh r1, [r0]
_0800A81C:
	ldr r1, _0800A854 @ =gUnknown_0202ADA0
	ldrh r0, [r1, #0x20]
	adds r0, #1
	strh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	ble _0800A838
	movs r0, #0
	strh r0, [r1, #0x20]
	ldr r1, _0800A858 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800A838:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800A840: .4byte 0x040000D4
_0800A844: .4byte gUnknown_0201B180
_0800A848: .4byte 0x0600E000
_0800A84C: .4byte 0x80000400
_0800A850: .4byte 0x000002EE
_0800A854: .4byte gUnknown_0202ADA0
_0800A858: .4byte gUnknown_0202C790

	thumb_func_start nullsub_8
nullsub_8: @ 0x0800A85C
	bx lr

	thumb_func_start sub_A860
sub_A860: @ 0x0800A860
	push {lr}
	bl sub_10480
	bl sub_10544
	ldr r1, _0800A878 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800A878: .4byte gUnknown_0202C790

	thumb_func_start sub_A87C
sub_A87C: @ 0x0800A87C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0800A92C @ =gMain
	ldrh r0, [r4, #0x38]
	ldr r0, _0800A930 @ =0x00001F50
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	ldr r0, _0800A934 @ =0x00000808
	strh r0, [r4, #0x3a]
	ldr r1, _0800A938 @ =0x04000050
	ldrh r0, [r4, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x3a]
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #1
	strh r0, [r5]
	ldr r0, _0800A93C @ =gUnknown_086A795C
	movs r1, #1
	adds r2, r5, #0
	bl LoadSpriteSets
	ldrh r0, [r5]
	cmp r0, #1
	bne _0800A91C
	ldr r0, _0800A940 @ =gUnknown_0201A450
	ldrh r1, [r0]
	strh r1, [r5, #2]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	ldr r7, _0800A944 @ =gOamBuffer
	movs r2, #0xd
	rsbs r2, r2, #0
	mov r8, r2
	ldr r0, _0800A948 @ =0xFFFFFE00
	mov ip, r0
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r4, r4, r2
	movs r6, #3
_0800A8D4:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r1, [r2, #5]
	mov r0, r8
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	ldr r2, _0800A94C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	bge _0800A8D4
_0800A91C:
	movs r0, #0
	strh r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800A92C: .4byte gMain
_0800A930: .4byte 0x00001F50
_0800A934: .4byte 0x00000808
_0800A938: .4byte 0x04000050
_0800A93C: .4byte gUnknown_086A795C
_0800A940: .4byte gUnknown_0201A450
_0800A944: .4byte gOamBuffer
_0800A948: .4byte 0xFFFFFE00
_0800A94C: .4byte 0x000001FF

	thumb_func_start sub_A950
sub_A950: @ 0x0800A950
	push {lr}
	bl sub_518
	ldr r1, _0800A964 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800A964: .4byte gUnknown_0202C790

	thumb_func_start sub_A968
sub_A968: @ 0x0800A968
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0
	strh r0, [r2]
	ldr r1, _0800AA50 @ =0x04000008
	movs r3, #0xcc
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800AA54 @ =0x0400000A
	ldr r3, _0800AA58 @ =0x0000DA01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800AA5C @ =0x0400000E
	ldr r3, _0800AA60 @ =0x00001E03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800AA64 @ =0x040000D4
	ldr r1, _0800AA68 @ =gUnknown_080E5F60
	str r1, [r0]
	ldr r1, _0800AA6C @ =0x06006000
	str r1, [r0, #4]
	ldr r3, _0800AA70 @ =0x80001000
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800AA74 @ =gUnknown_080E7F60
	str r1, [r0]
	ldr r1, _0800AA78 @ =0x0600D000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800AA7C @ =gUnknown_080E1740
	str r1, [r0]
	ldr r1, _0800AA80 @ =0x0600F000
	str r1, [r0, #4]
	ldr r1, _0800AA84 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800AA88 @ =gUnknown_080E1F40
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800AA8C @ =0x80002000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800AA90 @ =gUnknown_080E1540
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800AA94 @ =0x80000030
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0800AA98 @ =gMain
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	bl sub_AAA8
	ldr r2, _0800AA9C @ =gUnknown_0202ADA0
	ldrh r1, [r2]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r1, [r2, #2]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r1, [r2, #0xc]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r1, [r2, #0xe]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r1, [r2, #0x18]
	adds r3, #6
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x1a]
	ldr r1, _0800AAA0 @ =0x000002F6
	adds r4, r4, r1
	strh r0, [r4]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800AAA4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AA50: .4byte 0x04000008
_0800AA54: .4byte 0x0400000A
_0800AA58: .4byte 0x0000DA01
_0800AA5C: .4byte 0x0400000E
_0800AA60: .4byte 0x00001E03
_0800AA64: .4byte 0x040000D4
_0800AA68: .4byte gUnknown_080E5F60
_0800AA6C: .4byte 0x06006000
_0800AA70: .4byte 0x80001000
_0800AA74: .4byte gUnknown_080E7F60
_0800AA78: .4byte 0x0600D000
_0800AA7C: .4byte gUnknown_080E1740
_0800AA80: .4byte 0x0600F000
_0800AA84: .4byte 0x80000400
_0800AA88: .4byte gUnknown_080E1F40
_0800AA8C: .4byte 0x80002000
_0800AA90: .4byte gUnknown_080E1540
_0800AA94: .4byte 0x80000030
_0800AA98: .4byte gMain
_0800AA9C: .4byte gUnknown_0202ADA0
_0800AAA0: .4byte 0x000002F6
_0800AAA4: .4byte gUnknown_0202C790

	thumb_func_start sub_AAA8
sub_AAA8: @ 0x0800AAA8
	ldr r0, _0800AAD8 @ =gUnknown_0202ADA0
	movs r2, #0
	movs r1, #0x1c
	strh r1, [r0]
	ldr r1, _0800AADC @ =0x0000FF20
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	movs r1, #0xf
	strh r1, [r0, #6]
	ldr r1, _0800AAE0 @ =0x0000FF64
	strh r1, [r0, #0xc]
	movs r1, #0xe0
	strh r1, [r0, #0xe]
	strh r2, [r0, #0x10]
	ldr r1, _0800AAE4 @ =0x0000FFF1
	strh r1, [r0, #0x12]
	strh r2, [r0, #0x18]
	strh r2, [r0, #0x1a]
	strh r2, [r0, #0x20]
	ldr r0, _0800AAE8 @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _0800AAEC @ =gUnknown_0202A578
	strh r2, [r0]
	bx lr
	.align 2, 0
_0800AAD8: .4byte gUnknown_0202ADA0
_0800AADC: .4byte 0x0000FF20
_0800AAE0: .4byte 0x0000FF64
_0800AAE4: .4byte 0x0000FFF1
_0800AAE8: .4byte gUnknown_0202BF10
_0800AAEC: .4byte gUnknown_0202A578

	thumb_func_start nullsub_9
nullsub_9: @ 0x0800AAF0
	bx lr

	thumb_func_start sub_AAF4
sub_AAF4: @ 0x0800AAF4
	push {r4, lr}
	ldr r3, _0800AB7C @ =gUnknown_0202ADA0
	ldrh r4, [r3, #6]
	ldrh r1, [r3, #2]
	adds r0, r4, r1
	strh r0, [r3, #2]
	ldrh r2, [r3, #0x12]
	ldrh r1, [r3, #0xe]
	adds r0, r2, r1
	strh r0, [r3, #0xe]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	ldr r0, _0800AB80 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800AB2E
	subs r0, r4, #1
	strh r0, [r3, #6]
	adds r0, r2, #1
	strh r0, [r3, #0x12]
_0800AB2E:
	ldr r1, _0800AB84 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x18]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r3, #0x20]
	adds r0, #1
	strh r0, [r3, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x27
	ble _0800AB76
	movs r0, #0
	strh r0, [r3, #0x20]
	ldr r1, _0800AB88 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800AB76:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AB7C: .4byte gUnknown_0202ADA0
_0800AB80: .4byte gUnknown_0202BF10
_0800AB84: .4byte gMain
_0800AB88: .4byte gUnknown_0202C790

	thumb_func_start nullsub_10
nullsub_10: @ 0x0800AB8C
	bx lr

	thumb_func_start sub_AB90
sub_AB90: @ 0x0800AB8E
	push {r4, lr}
	ldr r3, _0800AC10 @ =gUnknown_0202ADA0
	ldrh r4, [r3, #6]
	ldrh r1, [r3, #2]
	adds r0, r4, r1
	strh r0, [r3, #2]
	ldrh r2, [r3, #0x12]
	ldrh r1, [r3, #0xe]
	adds r0, r2, r1
	strh r0, [r3, #0xe]
	ldrh r0, [r3, #0x18]
	subs r0, #1
	strh r0, [r3, #0x18]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	ldr r0, _0800AC14 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800ABCA
	subs r0, r4, #1
	strh r0, [r3, #6]
	adds r0, r2, #1
	strh r0, [r3, #0x12]
_0800ABCA:
	ldr r1, _0800AC18 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x18]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_10480
	bl sub_10544
	ldr r1, _0800AC1C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AC10: .4byte gUnknown_0202ADA0
_0800AC14: .4byte gUnknown_0202BF10
_0800AC18: .4byte gMain
_0800AC1C: .4byte gUnknown_0202C790

	thumb_func_start sub_AC20
sub_AC20: @ 0x0800AC20
	push {lr}
	bl sub_518
	ldr r1, _0800AC34 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800AC34: .4byte gUnknown_0202C790

	thumb_func_start sub_AC38
sub_AC38: @ 0x0800AC38
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800AD78 @ =0x04000008
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800AD7C @ =0x0400000A
	ldr r3, _0800AD80 @ =0x00004E01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800AD84 @ =0x0400000C
	ldr r3, _0800AD88 @ =0x00005C02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800AD8C @ =0x0400000E
	ldr r3, _0800AD90 @ =0x00001E03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800AD94 @ =0x040000D4
	ldr r1, _0800AD98 @ =gUnknown_080F1980
	str r1, [r0]
	ldr r1, _0800AD9C @ =0x06006000
	str r1, [r0, #4]
	ldr r3, _0800ADA0 @ =0x80000400
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADA4 @ =gUnknown_080EB160
	str r1, [r0]
	ldr r1, _0800ADA8 @ =0x06007000
	str r1, [r0, #4]
	ldr r2, _0800ADAC @ =0x80000800
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADB0 @ =gUnknown_080EA160
	str r1, [r0]
	ldr r1, _0800ADB4 @ =0x0600E000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADB8 @ =gUnknown_080EC160
	str r1, [r0]
	ldr r1, _0800ADBC @ =0x0600F000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADC0 @ =gUnknown_080EC960
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800ADC4 @ =0x80001400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADC8 @ =gUnknown_080BD4C0
	str r1, [r0]
	ldr r1, _0800ADCC @ =gUnknown_03000000
	str r1, [r0, #4]
	ldr r1, _0800ADD0 @ =0x80002000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r3, _0800ADD4 @ =gUnknown_080E9F60
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800ADD8 @ =0x800000C0
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800ADDC @ =gUnknown_080F2180
	str r1, [r0]
	ldr r1, _0800ADE0 @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800ADE4 @ =0x80001800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0800ADE8 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_ADFC
	bl sub_B0E8
	ldr r1, _0800ADEC @ =gMain
	ldr r2, _0800ADF0 @ =gUnknown_0202ADA0
	ldrh r3, [r2]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x18]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x1a]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x24]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r0, [r2, #0x26]
	ldr r2, _0800ADF4 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800ADF8 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AD78: .4byte 0x04000008
_0800AD7C: .4byte 0x0400000A
_0800AD80: .4byte 0x00004E01
_0800AD84: .4byte 0x0400000C
_0800AD88: .4byte 0x00005C02
_0800AD8C: .4byte 0x0400000E
_0800AD90: .4byte 0x00001E03
_0800AD94: .4byte 0x040000D4
_0800AD98: .4byte gUnknown_080F1980
_0800AD9C: .4byte 0x06006000
_0800ADA0: .4byte 0x80000400
_0800ADA4: .4byte gUnknown_080EB160
_0800ADA8: .4byte 0x06007000
_0800ADAC: .4byte 0x80000800
_0800ADB0: .4byte gUnknown_080EA160
_0800ADB4: .4byte 0x0600E000
_0800ADB8: .4byte gUnknown_080EC160
_0800ADBC: .4byte 0x0600F000
_0800ADC0: .4byte gUnknown_080EC960
_0800ADC4: .4byte 0x80001400
_0800ADC8: .4byte gUnknown_080BD4C0
_0800ADCC: .4byte gUnknown_03000000
_0800ADD0: .4byte 0x80002000
_0800ADD4: .4byte gUnknown_080E9F60
_0800ADD8: .4byte 0x800000C0
_0800ADDC: .4byte gUnknown_080F2180
_0800ADE0: .4byte 0x06010000
_0800ADE4: .4byte 0x80001800
_0800ADE8: .4byte 0x05000200
_0800ADEC: .4byte gMain
_0800ADF0: .4byte gUnknown_0202ADA0
_0800ADF4: .4byte 0x000002F6
_0800ADF8: .4byte gUnknown_0202C790

	thumb_func_start sub_ADFC
sub_ADFC: @ 0x0800ADFC
	push {r4, r5, lr}
	ldr r1, _0800AE54 @ =gUnknown_0201A450
	movs r5, #0
	movs r2, #0xb4
	strh r2, [r1, #0x10]
	ldr r0, _0800AE58 @ =0x0000FFBC
	strh r0, [r1, #0x12]
	strh r2, [r1]
	strh r0, [r1, #2]
	movs r0, #0x80
	strh r0, [r1, #0x20]
	movs r0, #0x88
	strh r0, [r1, #0x22]
	ldr r4, _0800AE5C @ =gUnknown_0202ADA0
	ldr r0, _0800AE60 @ =0x0000FF58
	strh r0, [r4]
	adds r0, #0x40
	strh r0, [r4, #2]
	strh r5, [r4, #8]
	strh r5, [r4, #0xa]
	strh r5, [r4, #4]
	ldr r0, _0800AE64 @ =gUnknown_03002300
	ldr r1, _0800AE68 @ =0x06002EE0
	movs r2, #8
	movs r3, #8
	bl sub_10708
	movs r0, #0xa5
	strh r0, [r4, #0xc]
	strh r5, [r4, #0xe]
	strh r5, [r4, #0x14]
	movs r0, #0xa0
	strh r0, [r4, #0x18]
	strh r5, [r4, #0x1a]
	strh r5, [r4, #0x20]
	strh r5, [r4, #0x24]
	strh r5, [r4, #0x26]
	ldr r0, _0800AE6C @ =gUnknown_0202BF10
	strh r5, [r0]
	ldr r0, _0800AE70 @ =gUnknown_0202A578
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800AE54: .4byte gUnknown_0201A450
_0800AE58: .4byte 0x0000FFBC
_0800AE5C: .4byte gUnknown_0202ADA0
_0800AE60: .4byte 0x0000FF58
_0800AE64: .4byte gUnknown_03002300
_0800AE68: .4byte 0x06002EE0
_0800AE6C: .4byte gUnknown_0202BF10
_0800AE70: .4byte gUnknown_0202A578

	thumb_func_start sub_AE74
sub_AE74: @ 0x0800AE74
	push {r4, lr}
	ldr r1, _0800AF5C @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #0x10
	strh r0, [r1, #0x10]
	ldrh r0, [r1, #0x12]
	adds r0, #0xa
	strh r0, [r1, #0x12]
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	ldrh r0, [r1, #2]
	adds r0, #0xa
	strh r0, [r1, #2]
	ldrh r0, [r1, #0x20]
	adds r0, #5
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	subs r0, #3
	strh r0, [r1, #0x22]
	ldr r4, _0800AF60 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0xc]
	subs r0, #0x10
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldrh r0, [r4, #0x18]
	subs r0, #0x10
	strh r0, [r4, #0x18]
	ldrh r1, [r4, #4]
	ldrh r2, [r4]
	adds r0, r1, r2
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #9
	strh r0, [r4, #2]
	adds r1, #1
	strh r1, [r4, #4]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	ldr r2, _0800AF64 @ =gUnknown_086A79FC
	movs r3, #8
	ldrsh r1, [r4, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _0800AF02
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ldr r1, _0800AF68 @ =gUnknown_086A7A1C
	movs r3, #8
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	ldr r1, _0800AF6C @ =gUnknown_03000000
	adds r0, r0, r1
	ldr r1, _0800AF70 @ =0x06002EE0
	movs r2, #8
	movs r3, #8
	bl sub_10708
_0800AF02:
	bl sub_B0E8
	ldr r1, _0800AF74 @ =gMain
	ldrh r2, [r4]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x18]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x1a]
	ldr r2, _0800AF78 @ =0x000002F2
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0800AF54
	movs r0, #0
	strh r0, [r4, #0x20]
	ldr r1, _0800AF7C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800AF54:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AF5C: .4byte gUnknown_0201A450
_0800AF60: .4byte gUnknown_0202ADA0
_0800AF64: .4byte gUnknown_086A79FC
_0800AF68: .4byte gUnknown_086A7A1C
_0800AF6C: .4byte gUnknown_03000000
_0800AF70: .4byte 0x06002EE0
_0800AF74: .4byte gMain
_0800AF78: .4byte 0x000002F2
_0800AF7C: .4byte gUnknown_0202C790

	thumb_func_start sub_AF80
sub_AF80: @ 0x0800AF80
	push {r4, lr}
	ldr r3, _0800B064 @ =gUnknown_0202ADA0
	ldrh r0, [r3, #0xa]
	adds r0, #1
	strh r0, [r3, #0xa]
	ldr r2, _0800B068 @ =gUnknown_086A79FC
	movs r4, #8
	ldrsh r1, [r3, r4]
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #2
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _0800AFCC
	ldrh r1, [r3, #8]
	movs r4, #8
	ldrsh r0, [r3, r4]
	cmp r0, #6
	bgt _0800AFCC
	adds r0, r1, #1
	strh r0, [r3, #8]
	ldr r1, _0800B06C @ =gUnknown_086A7A1C
	movs r2, #8
	ldrsh r0, [r3, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	ldr r1, _0800B070 @ =gUnknown_03000000
	adds r0, r0, r1
	ldr r1, _0800B074 @ =0x06002EE0
	movs r2, #8
	movs r3, #8
	bl sub_10708
_0800AFCC:
	bl sub_B0E8
	ldr r3, _0800B064 @ =gUnknown_0202ADA0
	ldrh r0, [r3, #0x24]
	adds r0, #1
	strh r0, [r3, #0x24]
	ldr r0, _0800B078 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800AFFE
	ldr r1, _0800B07C @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #1
	strh r0, [r1, #0x10]
	ldrh r0, [r1, #0x12]
	adds r0, #1
	strh r0, [r1, #0x12]
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	ldrh r0, [r1, #2]
	adds r0, #2
	strh r0, [r1, #2]
_0800AFFE:
	ldr r1, _0800B080 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x1a]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0x24]
	adds r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x26]
	ldr r2, _0800B084 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	ble _0800B05C
	movs r0, #0
	strh r0, [r3, #0x2c]
	ldr r1, _0800B088 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800B05C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B064: .4byte gUnknown_0202ADA0
_0800B068: .4byte gUnknown_086A79FC
_0800B06C: .4byte gUnknown_086A7A1C
_0800B070: .4byte gUnknown_03000000
_0800B074: .4byte 0x06002EE0
_0800B078: .4byte gUnknown_0202BF10
_0800B07C: .4byte gUnknown_0201A450
_0800B080: .4byte gMain
_0800B084: .4byte 0x000002F6
_0800B088: .4byte gUnknown_0202C790

	thumb_func_start nullsub_11
nullsub_11: @ 0x0800B08C
	bx lr

	thumb_func_start sub_B090
sub_B090: @ 0x0800B090
	push {lr}
	sub sp, #8
	bl sub_10480
	bl ClearSprites
	movs r2, #0
	str r2, [sp]
	ldr r1, _0800B0D4 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800B0D8 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, _0800B0DC @ =0x06010000
	str r0, [r1, #4]
	ldr r0, _0800B0E0 @ =0x81002800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_10544
	ldr r1, _0800B0E4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800B0D4: .4byte 0x040000D4
_0800B0D8: .4byte 0x85000100
_0800B0DC: .4byte 0x06010000
_0800B0E0: .4byte 0x81002800
_0800B0E4: .4byte gUnknown_0202C790

	thumb_func_start sub_B0E8
sub_B0E8: @ 0x0800B0E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0800B2C0 @ =gMain
	ldrh r0, [r4, #0x38]
	movs r0, #0xf1
	lsls r0, r0, #4
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	ldr r0, _0800B2C4 @ =0x00000808
	strh r0, [r4, #0x3a]
	ldr r1, _0800B2C8 @ =0x04000050
	ldrh r0, [r4, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x3a]
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #2
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r8, r1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r2, r4
	mov sb, r2
	movs r0, #1
	mov r7, sl
	strh r0, [r7]
	strh r0, [r1]
	strh r0, [r2]
	ldr r0, _0800B2CC @ =gUnknown_086A79EC
	movs r1, #3
	mov r2, r8
	bl LoadSpriteSets
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800B1B8
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0]
	strh r1, [r7, #2]
	ldrh r0, [r0, #2]
	strh r0, [r7, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0xee
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r5, #3
_0800B15A:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	mov r0, ip
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, ip
	ands r0, r2
	movs r7, #4
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800B2D8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800B2DC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, sl
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B15A
_0800B1B8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800B234
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	strh r1, [r7, #2]
	ldrh r0, [r0, #0x12]
	strh r0, [r7, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	ldr r0, _0800B2DC @ =0xFFFFFE00
	mov ip, r0
	mov r4, r8
	adds r4, #8
	movs r5, #3
_0800B1D6:
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r4, r2]
	mov r7, r8
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _0800B2D8 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B1D6
_0800B234:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800B2A2
	ldr r0, _0800B2D0 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x20]
	mov r2, sb
	strh r1, [r2, #2]
	ldrh r0, [r0, #0x22]
	strh r0, [r2, #4]
	ldr r6, _0800B2D4 @ =gOamBuffer
	movs r7, #0xd
	rsbs r7, r7, #0
	mov ip, r7
	mov r4, sb
	adds r4, #8
	movs r5, #7
_0800B256:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	mov r0, ip
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sb
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800B2D8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0800B2DC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, sb
	ldrb r0, [r7, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800B256
_0800B2A2:
	movs r0, #0
	mov r7, sl
	strh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	mov r2, sb
	strh r0, [r2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B2C0: .4byte gMain
_0800B2C4: .4byte 0x00000808
_0800B2C8: .4byte 0x04000050
_0800B2CC: .4byte gUnknown_086A79EC
_0800B2D0: .4byte gUnknown_0201A450
_0800B2D4: .4byte gOamBuffer
_0800B2D8: .4byte 0x000001FF
_0800B2DC: .4byte 0xFFFFFE00

	thumb_func_start sub_B2E0
sub_B2E0: @ 0x0800B2E0
	push {lr}
	bl sub_518
	ldr r1, _0800B2F4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800B2F4: .4byte gUnknown_0202C790

	thumb_func_start sub_B2F8
sub_B2F8: @ 0x0800B2F8
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800B428 @ =0x04000008
	movs r3, #0xf0
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B42C @ =0x0400000A
	ldr r3, _0800B430 @ =0x0000DA01
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B434 @ =0x0400000C
	ldr r3, _0800B438 @ =0x00001E02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800B43C @ =0x0400000E
	ldr r3, _0800B440 @ =0x00001F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800B444 @ =0x040000D4
	ldr r1, _0800B448 @ =gUnknown_080FD7C0
	str r1, [r0]
	ldr r1, _0800B44C @ =0x06007800
	str r1, [r0, #4]
	ldr r2, _0800B450 @ =0x80000400
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B454 @ =gUnknown_080FDFC0
	str r1, [r0]
	ldr r1, _0800B458 @ =0x0600D000
	str r1, [r0, #4]
	ldr r1, _0800B45C @ =0x80001000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B460 @ =gUnknown_080FCFC0
	str r1, [r0]
	ldr r1, _0800B464 @ =0x0600F000
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B468 @ =gUnknown_080F63A0
	str r1, [r0]
	ldr r1, _0800B46C @ =0x0600F800
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B470 @ =gUnknown_080F6BA0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800B474 @ =0x80003200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r3, _0800B478 @ =gUnknown_080F61A0
	str r3, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800B47C @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800B480 @ =gUnknown_080FFFC0
	str r1, [r0]
	ldr r1, _0800B484 @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800B488 @ =0x80000800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _0800B48C @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	bl sub_B4A0
	ldr r1, _0800B490 @ =gMain
	ldr r2, _0800B494 @ =gUnknown_0202ADA0
	ldrh r3, [r2]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xc]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0xe]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x18]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x1a]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r3, [r2, #0x24]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldrh r0, [r2, #0x26]
	ldr r2, _0800B498 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800B49C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800B428: .4byte 0x04000008
_0800B42C: .4byte 0x0400000A
_0800B430: .4byte 0x0000DA01
_0800B434: .4byte 0x0400000C
_0800B438: .4byte 0x00001E02
_0800B43C: .4byte 0x0400000E
_0800B440: .4byte 0x00001F03
_0800B444: .4byte 0x040000D4
_0800B448: .4byte gUnknown_080FD7C0
_0800B44C: .4byte 0x06007800
_0800B450: .4byte 0x80000400
_0800B454: .4byte gUnknown_080FDFC0
_0800B458: .4byte 0x0600D000
_0800B45C: .4byte 0x80001000
_0800B460: .4byte gUnknown_080FCFC0
_0800B464: .4byte 0x0600F000
_0800B468: .4byte gUnknown_080F63A0
_0800B46C: .4byte 0x0600F800
_0800B470: .4byte gUnknown_080F6BA0
_0800B474: .4byte 0x80003200
_0800B478: .4byte gUnknown_080F61A0
_0800B47C: .4byte 0x80000040
_0800B480: .4byte gUnknown_080FFFC0
_0800B484: .4byte 0x06010000
_0800B488: .4byte 0x80000800
_0800B48C: .4byte 0x05000200
_0800B490: .4byte gMain
_0800B494: .4byte gUnknown_0202ADA0
_0800B498: .4byte 0x000002F6
_0800B49C: .4byte gUnknown_0202C790

	thumb_func_start sub_B4A0
sub_B4A0: @ 0x0800B4A0
	push {r4, r5, r6, r7, lr}
	ldr r1, _0800B540 @ =gUnknown_0202ADA0
	movs r3, #0
	movs r4, #0x1e
	strh r4, [r1, #0xc]
	ldr r0, _0800B544 @ =0x0000FF6A
	strh r0, [r1, #0xe]
	movs r0, #1
	strh r0, [r1, #0x14]
	ldr r0, _0800B548 @ =0x0000FFFE
	strh r0, [r1]
	subs r0, #3
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	movs r2, #8
	strh r2, [r1, #6]
	subs r0, #0x6b
	strh r0, [r1, #0x18]
	adds r0, #0x44
	strh r0, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r3, [r1, #0x1e]
	strh r3, [r1, #0x24]
	strh r3, [r1, #0x26]
	ldr r3, _0800B54C @ =gUnknown_0201A450
	movs r0, #0x32
	strh r0, [r3]
	movs r1, #0x3c
	strh r1, [r3, #2]
	movs r0, #0x50
	strh r0, [r3, #0x10]
	strh r1, [r3, #0x12]
	movs r0, #0x8c
	strh r0, [r3, #0x20]
	movs r2, #0x64
	strh r2, [r3, #0x22]
	movs r0, #0xc8
	strh r0, [r3, #0x30]
	movs r0, #0x5a
	strh r0, [r3, #0x32]
	adds r0, r3, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	movs r0, #0x96
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x52
	strh r2, [r0]
	ldr r5, _0800B550 @ =gUnknown_0202C548
	ldr r6, _0800B554 @ =gUnknown_0202BF10
	ldr r7, _0800B558 @ =gUnknown_0202A578
	ldr r0, _0800B55C @ =gUnknown_0202BEB4
	mov ip, r0
	movs r4, #0
	movs r2, #0
	adds r0, r3, #0
	adds r0, #8
	movs r1, #5
_0800B51C:
	strh r2, [r0]
	strh r2, [r0, #2]
	strb r4, [r0, #4]
	adds r0, #0x10
	subs r1, #1
	cmp r1, #0
	bge _0800B51C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0
	strh r0, [r6]
	strh r0, [r7]
	mov r1, ip
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B540: .4byte gUnknown_0202ADA0
_0800B544: .4byte 0x0000FF6A
_0800B548: .4byte 0x0000FFFE
_0800B54C: .4byte gUnknown_0201A450
_0800B550: .4byte gUnknown_0202C548
_0800B554: .4byte gUnknown_0202BF10
_0800B558: .4byte gUnknown_0202A578
_0800B55C: .4byte gUnknown_0202BEB4

	thumb_func_start sub_B560
sub_B560: @ 0x0800B560
	push {r4, r5, lr}
	ldr r2, _0800B694 @ =gUnknown_0202ADA0
	ldr r3, _0800B698 @ =gUnknown_086A7AC0
	ldr r1, _0800B69C @ =gUnknown_0202C548
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r2, #0xc]
	adds r0, r0, r4
	strh r0, [r2, #0xc]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r5, [r2, #0xe]
	adds r0, r0, r5
	strh r0, [r2, #0xe]
	ldr r3, _0800B6A0 @ =gUnknown_086A7AE4
	ldr r4, _0800B6A4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _0800B5C2
	ldrh r0, [r5, #6]
	ldrh r2, [r5, #2]
	adds r1, r0, r2
	strh r1, [r5, #2]
	subs r0, #2
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B5C2
	movs r0, #8
	strh r0, [r5, #6]
_0800B5C2:
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B5EE
	ldrh r0, [r5, #0x1c]
	ldrh r2, [r5, #0x18]
	adds r1, r0, r2
	strh r1, [r5, #0x18]
	subs r0, #2
	strh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B5EE
	movs r0, #8
	strh r0, [r5, #0x1c]
_0800B5EE:
	ldr r1, _0800B6A8 @ =gMain
	ldrh r2, [r5]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0xc]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r5, #0x18]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r5, #0x1a]
	ldr r5, _0800B6AC @ =0x000002F2
	adds r1, r1, r5
	strh r0, [r1]
	ldr r1, _0800B6B0 @ =gUnknown_086A7B34
	ldr r3, _0800B6B4 @ =gUnknown_0202BEB4
	movs r2, #0
	ldrsb r2, [r3, r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r5, #0
	ldrsh r1, [r4, r5]
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0800B64C
	ldr r1, _0800B6B8 @ =gUnknown_0201A450
	lsls r0, r2, #4
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0, #0xc]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0800B64C:
	bl sub_B7F8
	ldr r4, _0800B6BC @ =gUnknown_0202A578
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r2, _0800B698 @ =gUnknown_086A7AC0
	ldr r3, _0800B69C @ =gUnknown_0202C548
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrb r1, [r1, #2]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	ble _0800B68C
	movs r0, #0
	strh r0, [r4]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	ble _0800B68C
	ldr r1, _0800B6C0 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800B68C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800B694: .4byte gUnknown_0202ADA0
_0800B698: .4byte gUnknown_086A7AC0
_0800B69C: .4byte gUnknown_0202C548
_0800B6A0: .4byte gUnknown_086A7AE4
_0800B6A4: .4byte gUnknown_0202BF10
_0800B6A8: .4byte gMain
_0800B6AC: .4byte 0x000002F2
_0800B6B0: .4byte gUnknown_086A7B34
_0800B6B4: .4byte gUnknown_0202BEB4
_0800B6B8: .4byte gUnknown_0201A450
_0800B6BC: .4byte gUnknown_0202A578
_0800B6C0: .4byte gUnknown_0202C790

	thumb_func_start sub_B6C4
sub_B6C4: @ 0x0800B6C4
	push {r4, r5, lr}
	ldr r2, _0800B784 @ =gUnknown_086A7AE4
	ldr r3, _0800B788 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	adds r4, r2, #0
	adds r2, r3, #0
	ldr r3, _0800B78C @ =gUnknown_0202ADA0
	cmp r0, #0
	beq _0800B6FC
	ldrh r0, [r3, #6]
	ldrh r5, [r3, #2]
	adds r1, r0, r5
	strh r1, [r3, #2]
	subs r0, #2
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B6FC
	movs r0, #8
	strh r0, [r3, #6]
_0800B6FC:
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B728
	ldrh r0, [r3, #0x1c]
	ldrh r2, [r3, #0x18]
	adds r1, r0, r2
	strh r1, [r3, #0x18]
	subs r0, #2
	strh r0, [r3, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0800B728
	movs r0, #8
	strh r0, [r3, #0x1c]
_0800B728:
	ldr r1, _0800B790 @ =gMain
	ldrh r2, [r3]
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #2]
	ldr r5, _0800B794 @ =0x000002EA
	adds r0, r1, r5
	strh r2, [r0]
	ldrh r2, [r3, #0xc]
	adds r4, #4
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r2, [r3, #0xe]
	adds r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	ldrh r2, [r3, #0x18]
	adds r4, #4
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #0x1a]
	adds r5, #4
	adds r1, r1, r5
	strh r0, [r1]
	bl sub_B7F8
	ldr r1, _0800B798 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _0800B77C
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800B79C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800B77C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800B784: .4byte gUnknown_086A7AE4
_0800B788: .4byte gUnknown_0202BF10
_0800B78C: .4byte gUnknown_0202ADA0
_0800B790: .4byte gMain
_0800B794: .4byte 0x000002EA
_0800B798: .4byte gUnknown_0202A578
_0800B79C: .4byte gUnknown_0202C790

	thumb_func_start sub_B7A0
sub_B7A0: @ 0x0800B7A0
	push {lr}
	sub sp, #8
	bl ClearSprites
	movs r2, #0
	str r2, [sp]
	ldr r1, _0800B7E4 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800B7E8 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, _0800B7EC @ =0x06010000
	str r0, [r1, #4]
	ldr r0, _0800B7F0 @ =0x81002800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_10480
	bl sub_10544
	ldr r1, _0800B7F4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800B7E4: .4byte 0x040000D4
_0800B7E8: .4byte 0x85000100
_0800B7EC: .4byte 0x06010000
_0800B7F0: .4byte 0x81002800
_0800B7F4: .4byte gUnknown_0202C790

	thumb_func_start sub_B7F8
sub_B7F8: @ 0x0800B7F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r6, _0800BA0C @ =gUnknown_0201A450
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r0
	lsls r2, r2, #4
	ldr r3, _0800BA10 @ =gUnknown_0200B3B8
	adds r2, r2, r3
	str r2, [sp]
	movs r4, #0x18
	ldrsh r1, [r6, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r3, #0
	adds r1, #0xb8
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x28
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xb8
	lsls r4, r4, #1
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #8]
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r4, #0xb8
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x48
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x58
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	movs r4, #0xe6
	lsls r4, r4, #2
	adds r1, r3, r4
	adds r0, r0, r1
	str r0, [sp, #0x14]
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	strh r0, [r2]
	ldr r1, [sp, #4]
	movs r0, #0x1c
	ldrsb r0, [r6, r0]
	strh r0, [r1]
	ldr r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x14]
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r4, _0800BA14 @ =gUnknown_086A7A78
	adds r0, r4, #0
	movs r1, #0x12
	adds r2, r3, #0
	bl LoadSpriteSets
	movs r5, #0
	str r6, [sp, #0x18]
_0800B8EC:
	lsls r0, r5, #2
	mov r6, sp
	adds r4, r6, r0
	ldr r1, [r4]
	ldrh r1, [r1]
	str r0, [sp, #0x20]
	adds r0, r5, #1
	str r0, [sp, #0x1c]
	cmp r1, #1
	bne _0800B9DA
	lsls r3, r5, #4
	ldr r1, [sp, #0x18]
	adds r2, r3, r1
	ldr r6, [sp, #0x20]
	ldr r1, _0800BA18 @ =gUnknown_086A7B34
	adds r0, r6, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r6, [r2]
	adds r1, r1, r6
	strh r1, [r2]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldr r0, [r4]
	strh r1, [r0, #2]
	ldr r1, [r4]
	ldrh r0, [r2, #2]
	strh r0, [r1, #4]
	movs r0, #8
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	ldr r1, _0800BA14 @ =gUnknown_086A7A78
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r7, #0
	mov sb, r3
	ldrh r2, [r0]
	cmp r7, r2
	bge _0800B998
	adds r5, r4, #0
	ldr r3, _0800BA1C @ =gOamBuffer
	mov ip, r3
	ldr r4, _0800BA20 @ =0xFFFFFE00
	mov sl, r4
	movs r6, #8
_0800B958:
	ldr r0, [r5]
	adds r4, r0, r6
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r4, r3]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _0800BA24 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sl
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
	adds r6, #8
	adds r7, #1
	mov r4, r8
	ldrh r4, [r4]
	cmp r7, r4
	blt _0800B958
_0800B998:
	ldr r1, [sp, #0x18]
	add r1, sb
	ldrh r0, [r1, #0xa]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800B9BC
	strh r2, [r1, #0xa]
	ldrh r2, [r1, #8]
	movs r6, #8
	ldrsh r0, [r1, r6]
	cmp r0, #1
	bgt _0800B9BC
	adds r0, r2, #1
	strh r0, [r1, #8]
_0800B9BC:
	ldr r1, [sp, #0x20]
	ldr r2, _0800BA18 @ =gUnknown_086A7B34
	adds r0, r1, r2
	ldr r3, _0800BA28 @ =gUnknown_0202BF10
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldrb r0, [r0, #3]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0800B9DA
	ldr r1, [sp, #0x18]
	add r1, sb
	movs r0, #0
	strb r0, [r1, #0xc]
_0800B9DA:
	ldr r5, [sp, #0x1c]
	cmp r5, #5
	ble _0800B8EC
	ldr r0, [sp]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [sp, #4]
	strh r1, [r0]
	ldr r0, [sp, #8]
	strh r1, [r0]
	ldr r0, [sp, #0xc]
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	strh r1, [r0]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BA0C: .4byte gUnknown_0201A450
_0800BA10: .4byte gUnknown_0200B3B8
_0800BA14: .4byte gUnknown_086A7A78
_0800BA18: .4byte gUnknown_086A7B34
_0800BA1C: .4byte gOamBuffer
_0800BA20: .4byte 0xFFFFFE00
_0800BA24: .4byte 0x000001FF
_0800BA28: .4byte gUnknown_0202BF10

	thumb_func_start sub_BA2C
sub_BA2C: @ 0x0800BA2C
	ldr r1, _0800BA38 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0800BA38: .4byte gUnknown_0202C790

	thumb_func_start sub_BA3C
sub_BA3C: @ 0x0800BA3C
	push {r4, r5, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r1, _0800BB6C @ =0x04000008
	movs r3, #0xd4
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB70 @ =0x0400000A
	ldr r3, _0800BB74 @ =0x0000D801
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB78 @ =0x0400000C
	ldr r3, _0800BB7C @ =0x0000DC02
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800BB80 @ =0x0400000E
	ldr r3, _0800BB84 @ =0x00000F03
	adds r0, r3, #0
	strh r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0800BB88 @ =0x040000D4
	ldr r1, _0800BB8C @ =gUnknown_08108A00
	str r1, [r0]
	ldr r1, _0800BB90 @ =0x0600A000
	str r1, [r0, #4]
	ldr r3, _0800BB94 @ =0x80001000
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BB98 @ =gUnknown_0810AA00
	str r1, [r0]
	ldr r1, _0800BB9C @ =0x0600C000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBA0 @ =gUnknown_08106A00
	str r1, [r0]
	ldr r1, _0800BBA4 @ =0x0600E000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBA8 @ =gUnknown_081011E0
	str r1, [r0]
	ldr r1, _0800BBAC @ =0x06007800
	str r1, [r0, #4]
	ldr r1, _0800BBB0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBB4 @ =gUnknown_081019E0
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800BBB8 @ =0x80002800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r5, _0800BBBC @ =gUnknown_08100FE0
	str r5, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r4, _0800BBC0 @ =0x800000B0
	str r4, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800BBC4 @ =gUnknown_0810CA00
	str r1, [r0]
	ldr r1, _0800BBC8 @ =0x06010000
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r5, [r0]
	ldr r1, _0800BBCC @ =0x05000200
	str r1, [r0, #4]
	str r4, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0800BBD0 @ =gMain
	ldrh r0, [r2]
	strh r0, [r4, #0x16]
	bl sub_BBE0
	ldr r1, _0800BBD4 @ =gUnknown_0202ADA0
	ldrh r2, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #2]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0xc]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0xe]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x18]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x1a]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r2, [r1, #0x24]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r0, [r1, #0x26]
	ldr r1, _0800BBD8 @ =0x000002F6
	adds r4, r4, r1
	strh r0, [r4]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800BBDC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800BB6C: .4byte 0x04000008
_0800BB70: .4byte 0x0400000A
_0800BB74: .4byte 0x0000D801
_0800BB78: .4byte 0x0400000C
_0800BB7C: .4byte 0x0000DC02
_0800BB80: .4byte 0x0400000E
_0800BB84: .4byte 0x00000F03
_0800BB88: .4byte 0x040000D4
_0800BB8C: .4byte gUnknown_08108A00
_0800BB90: .4byte 0x0600A000
_0800BB94: .4byte 0x80001000
_0800BB98: .4byte gUnknown_0810AA00
_0800BB9C: .4byte 0x0600C000
_0800BBA0: .4byte gUnknown_08106A00
_0800BBA4: .4byte 0x0600E000
_0800BBA8: .4byte gUnknown_081011E0
_0800BBAC: .4byte 0x06007800
_0800BBB0: .4byte 0x80000400
_0800BBB4: .4byte gUnknown_081019E0
_0800BBB8: .4byte 0x80002800
_0800BBBC: .4byte gUnknown_08100FE0
_0800BBC0: .4byte 0x800000B0
_0800BBC4: .4byte gUnknown_0810CA00
_0800BBC8: .4byte 0x06010000
_0800BBCC: .4byte 0x05000200
_0800BBD0: .4byte gMain
_0800BBD4: .4byte gUnknown_0202ADA0
_0800BBD8: .4byte 0x000002F6
_0800BBDC: .4byte gUnknown_0202C790

	thumb_func_start sub_BBE0
sub_BBE0: @ 0x0800BBE0
	ldr r1, _0800BC30 @ =gUnknown_0202ADA0
	movs r2, #0
	ldr r0, _0800BC34 @ =0x0000FEFC
	strh r0, [r1]
	movs r0, #0x46
	strh r0, [r1, #2]
	strh r2, [r1, #6]
	ldr r0, _0800BC38 @ =0x0000FEE8
	strh r0, [r1, #0xc]
	movs r0, #0x5a
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x12]
	ldr r0, _0800BC3C @ =0x0000FF10
	strh r0, [r1, #0x18]
	adds r0, #0xbe
	strh r0, [r1, #0x1a]
	adds r0, #0x2f
	strh r0, [r1, #0x1e]
	strh r2, [r1, #0x24]
	strh r2, [r1, #0x26]
	ldr r1, _0800BC40 @ =gUnknown_0201A450
	movs r0, #0x94
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x2c
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	ldr r0, _0800BC44 @ =gUnknown_0202BF10
	strh r2, [r0]
	ldr r0, _0800BC48 @ =gUnknown_0202A578
	strh r2, [r0]
	ldr r0, _0800BC4C @ =gUnknown_0202C5E4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0800BC50 @ =gUnknown_0202ADD8
	strh r1, [r0]
	bx lr
	.align 2, 0
_0800BC30: .4byte gUnknown_0202ADA0
_0800BC34: .4byte 0x0000FEFC
_0800BC38: .4byte 0x0000FEE8
_0800BC3C: .4byte 0x0000FF10
_0800BC40: .4byte gUnknown_0201A450
_0800BC44: .4byte gUnknown_0202BF10
_0800BC48: .4byte gUnknown_0202A578
_0800BC4C: .4byte gUnknown_0202C5E4
_0800BC50: .4byte gUnknown_0202ADD8

	thumb_func_start sub_BC54
sub_BC54: @ 0x0800BC54
	push {r4, r5, r6, lr}
	ldr r4, _0800BCD0 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BCD4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BC88
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BC88
	ldr r0, _0800BCD8 @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BC88:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BCDC @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BCE0 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0x20
	ble _0800BCC8
	ldr r1, _0800BCE4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BCC8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800BCD0: .4byte gUnknown_0202ADA0
_0800BCD4: .4byte gUnknown_0202BF10
_0800BCD8: .4byte 0x0000FFFD
_0800BCDC: .4byte gMain
_0800BCE0: .4byte 0x000002F6
_0800BCE4: .4byte gUnknown_0202C790

	thumb_func_start sub_BCE8
sub_BCE8: @ 0x0800BCE8
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BDA4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BDA8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BD1E
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BD1E
	ldr r0, _0800BDAC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BD1E:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BD4C
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BD4C
	ldr r0, _0800BDB0 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BD4C:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BDB4 @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BDB8 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r0, #0x50
	ble _0800BD9C
	ldr r1, _0800BDBC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BD9C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BDA4: .4byte gUnknown_0202ADA0
_0800BDA8: .4byte gUnknown_0202BF10
_0800BDAC: .4byte 0x0000FFFD
_0800BDB0: .4byte 0x0000FFFA
_0800BDB4: .4byte gMain
_0800BDB8: .4byte 0x000002F6
_0800BDBC: .4byte gUnknown_0202C790

	thumb_func_start sub_BDC0
sub_BDC0: @ 0x0800BDC0
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BEB4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BEB8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BDF6
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BDF6
	ldr r0, _0800BEBC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BDF6:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BE24
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BE24
	ldr r0, _0800BEC0 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BE24:
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r4, #6]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BE4C
	adds r0, r2, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BE4C
	ldr r0, _0800BEBC @ =0x0000FFFD
	strh r0, [r4, #6]
_0800BE4C:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800BEC4 @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #0xa
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800BEC8 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r0, #0x64
	ble _0800BEAC
	ldr r1, _0800BECC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BEAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BEB4: .4byte gUnknown_0202ADA0
_0800BEB8: .4byte gUnknown_0202BF10
_0800BEBC: .4byte 0x0000FFFD
_0800BEC0: .4byte 0x0000FFFA
_0800BEC4: .4byte gMain
_0800BEC8: .4byte 0x000002F6
_0800BECC: .4byte gUnknown_0202C790

	thumb_func_start sub_BED0
sub_BED0: @ 0x0800BED0
	push {r4, r5, r6, r7, lr}
	ldr r4, _0800BFF4 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x18]
	adds r0, #2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	ldrh r6, [r4, #0x1e]
	subs r0, r0, r6
	strh r0, [r4, #0x1a]
	ldr r5, _0800BFF8 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	adds r7, r5, #0
	cmp r0, #0
	bne _0800BF06
	adds r0, r6, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BF06
	ldr r0, _0800BFFC @ =0x0000FFFD
	strh r0, [r4, #0x1e]
_0800BF06:
	ldrh r0, [r4, #0xc]
	adds r0, #3
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	ldrh r5, [r4, #0x12]
	subs r0, r0, r5
	strh r0, [r4, #0xe]
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BF34
	adds r0, r5, #1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BF34
	ldr r0, _0800C000 @ =0x0000FFFA
	strh r0, [r4, #0x12]
_0800BF34:
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r4, #6]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BF5C
	adds r0, r2, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0800BF5C
	ldr r0, _0800BFFC @ =0x0000FFFD
	strh r0, [r4, #6]
_0800BF5C:
	ldr r2, _0800C004 @ =gUnknown_0201A450
	ldrh r0, [r2]
	subs r0, #2
	strh r0, [r2]
	ldrh r3, [r2, #6]
	ldrh r1, [r2, #2]
	adds r0, r3, r1
	strh r0, [r2, #2]
	ldrh r0, [r7]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0800BF86
	adds r0, r3, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800BF86
	ldr r0, _0800C008 @ =0x0000FFFC
	strh r0, [r2, #6]
_0800BF86:
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r1, _0800C00C @ =gMain
	ldrh r2, [r4, #0x18]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x1a]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xc]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0xe]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4]
	subs r3, #6
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #2]
	adds r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r2, [r4, #0x24]
	adds r3, #0xa
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800C010 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_C0D8
	ldr r0, _0800BFF8 @ =gUnknown_0202BF10
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xc0
	ble _0800BFEC
	ldr r1, _0800C014 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800BFEC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BFF4: .4byte gUnknown_0202ADA0
_0800BFF8: .4byte gUnknown_0202BF10
_0800BFFC: .4byte 0x0000FFFD
_0800C000: .4byte 0x0000FFFA
_0800C004: .4byte gUnknown_0201A450
_0800C008: .4byte 0x0000FFFC
_0800C00C: .4byte gMain
_0800C010: .4byte 0x000002F6
_0800C014: .4byte gUnknown_0202C790

	thumb_func_start sub_C018
sub_C018: @ 0x0800C018
	push {r4, r5, lr}
	ldr r4, _0800C044 @ =gUnknown_0202ADA0
	ldrh r0, [r4, #0x24]
	subs r0, #1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x26]
	subs r0, #1
	strh r0, [r4, #0x26]
	ldr r5, _0800C048 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0800C050
	ldr r1, _0800C04C @ =gUnknown_0201A450
	ldrh r0, [r1]
	subs r0, #3
	b _0800C05A
	.align 2, 0
_0800C044: .4byte gUnknown_0202ADA0
_0800C048: .4byte gUnknown_0202BF10
_0800C04C: .4byte gUnknown_0201A450
_0800C050:
	cmp r0, #3
	bne _0800C05C
	ldr r1, _0800C0A4 @ =gUnknown_0201A450
	ldrh r0, [r1]
	adds r0, #3
_0800C05A:
	strh r0, [r1]
_0800C05C:
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0xca
	ble _0800C074
	ldr r1, _0800C0A8 @ =gUnknown_0202C5E4
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, _0800C0AC @ =gUnknown_0202ADD8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0800C074:
	ldr r1, _0800C0B0 @ =gMain
	ldrh r2, [r4, #0x24]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r4, #0x26]
	ldr r2, _0800C0B4 @ =0x000002F6
	adds r1, r1, r2
	strh r0, [r1]
	bl sub_C0D8
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r0, #0xde
	ble _0800C09C
	ldr r1, _0800C0B8 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C09C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800C0A4: .4byte gUnknown_0201A450
_0800C0A8: .4byte gUnknown_0202C5E4
_0800C0AC: .4byte gUnknown_0202ADD8
_0800C0B0: .4byte gMain
_0800C0B4: .4byte 0x000002F6
_0800C0B8: .4byte gUnknown_0202C790

	thumb_func_start sub_C0BC
sub_C0BC: @ 0x0800C0BC
	push {lr}
	bl sub_10480
	bl sub_10544
	ldr r1, _0800C0D4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800C0D4: .4byte gUnknown_0202C790

	thumb_func_start sub_C0D8
sub_C0D8: @ 0x0800C0D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0800C1EC @ =gUnknown_0200B3B8
	mov r8, r0
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	ldr r0, _0800C1F0 @ =gUnknown_086A7B74
	movs r1, #1
	mov r2, r8
	bl LoadSpriteSets
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, #1
	bne _0800C1D4
	ldr r5, _0800C1F4 @ =gUnknown_0202C5E4
	movs r3, #0
	ldrsh r0, [r5, r3]
	ldr r4, _0800C1F8 @ =gUnknown_0202ADD8
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r2, #0
	bl SetMatrixScale
	ldr r1, _0800C1FC @ =gUnknown_0201A450
	ldrh r0, [r1]
	mov r3, r8
	strh r0, [r3, #2]
	ldrh r0, [r1, #2]
	strh r0, [r3, #4]
	movs r7, #0
	ldr r6, _0800C200 @ =gOamBuffer
	mov sl, r4
	mov r5, r8
	adds r5, #8
	ldr r4, _0800C204 @ =0xFFFFFE00
	mov sb, r4
	movs r0, #4
	rsbs r0, r0, #0
	mov ip, r0
_0800C132:
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r3, r0, r6
	lsls r0, r7, #2
	ldr r1, _0800C208 @ =gUnknown_086A7B7C
	adds r4, r0, r1
	movs r0, #0
	ldrsh r2, [r4, r0]
	str r2, [sp]
	ldr r1, _0800C1F4 @ =gUnknown_0202C5E4
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r2, [sp]
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _0800C16A
	adds r1, #0xff
_0800C16A:
	asrs r1, r1, #8
	str r1, [sp]
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [sp]
	adds r1, r2, r0
	ldr r2, _0800C20C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r6
	movs r3, #2
	ldrsh r1, [r4, r3]
	mov r4, sl
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r1, r0
	cmp r0, #0
	bge _0800C1A0
	adds r0, #0xff
_0800C1A0:
	asrs r0, r0, #8
	mov r4, r8
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrb r1, [r2, #1]
	mov r0, ip
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #3]
	adds r5, #8
	adds r7, #1
	cmp r7, #3
	ble _0800C132
_0800C1D4:
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C1EC: .4byte gUnknown_0200B3B8
_0800C1F0: .4byte gUnknown_086A7B74
_0800C1F4: .4byte gUnknown_0202C5E4
_0800C1F8: .4byte gUnknown_0202ADD8
_0800C1FC: .4byte gUnknown_0201A450
_0800C200: .4byte gOamBuffer
_0800C204: .4byte 0xFFFFFE00
_0800C208: .4byte gUnknown_086A7B7C
_0800C20C: .4byte 0x000001FF

	thumb_func_start sub_C210
sub_C210: @ 0x0800C210
	push {lr}
	bl sub_518
	ldr r1, _0800C224 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800C224: .4byte gUnknown_0202C790

	thumb_func_start sub_C228
sub_C228: @ 0x0800C228
	push {r4, lr}
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r3]
	ldr r1, _0800C2B4 @ =0x0400000C
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0800C2B8 @ =0x040000D4
	ldr r1, _0800C2BC @ =gUnknown_0810EC20
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800C2C0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C2C4 @ =gUnknown_0810F420
	str r1, [r0]
	ldr r1, _0800C2C8 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _0800C2CC @ =0x80001A00
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r4, _0800C2D0 @ =gUnknown_0810EA20
	str r4, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800C2D4 @ =0x800000A0
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C2D8 @ =gUnknown_08112840
	str r1, [r0]
	ldr r1, _0800C2DC @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800C2E0 @ =0x80001600
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [r0]
	ldr r1, _0800C2E4 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _0800C2E8 @ =gMain
	ldrh r0, [r3]
	strh r0, [r1, #0x16]
	bl sub_C2F0
	bl sub_C4F0
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800C2EC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C2B4: .4byte 0x0400000C
_0800C2B8: .4byte 0x040000D4
_0800C2BC: .4byte gUnknown_0810EC20
_0800C2C0: .4byte 0x80000400
_0800C2C4: .4byte gUnknown_0810F420
_0800C2C8: .4byte 0x06004000
_0800C2CC: .4byte 0x80001A00
_0800C2D0: .4byte gUnknown_0810EA20
_0800C2D4: .4byte 0x800000A0
_0800C2D8: .4byte gUnknown_08112840
_0800C2DC: .4byte 0x06010000
_0800C2E0: .4byte 0x80001600
_0800C2E4: .4byte 0x05000200
_0800C2E8: .4byte gMain
_0800C2EC: .4byte gUnknown_0202C790

	thumb_func_start sub_C2F0
sub_C2F0: @ 0x0800C2F0
	push {r4, r5, r6, lr}
	ldr r0, _0800C380 @ =gUnknown_0201A450
	mov ip, r0
	movs r4, #0
	movs r1, #0
	movs r5, #0x78
	strh r5, [r0, #0x10]
	movs r2, #0x50
	strh r2, [r0, #0x12]
	movs r0, #4
	mov r3, ip
	strh r0, [r3, #0x14]
	strh r0, [r3, #0x16]
	strh r1, [r3, #0x18]
	strh r5, [r3]
	strh r2, [r3, #2]
	strb r4, [r3, #0xc]
	movs r2, #0x80
	strh r2, [r3, #0x20]
	movs r3, #0x58
	mov r0, ip
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x28]
	strh r1, [r0, #0x2a]
	adds r0, #0x2c
	strb r4, [r0]
	mov r0, ip
	strh r2, [r0, #0x30]
	movs r6, #0x48
	strh r6, [r0, #0x32]
	strh r1, [r0, #0x38]
	strh r1, [r0, #0x3a]
	adds r0, #0x3c
	strb r4, [r0]
	adds r0, #4
	movs r2, #0x70
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	adds r0, #4
	strh r5, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	adds r0, #4
	strh r2, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #6
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strb r4, [r0]
	ldr r0, _0800C384 @ =gUnknown_0202BF10
	strh r1, [r0]
	ldr r0, _0800C388 @ =gUnknown_0202A578
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800C380: .4byte gUnknown_0201A450
_0800C384: .4byte gUnknown_0202BF10
_0800C388: .4byte gUnknown_0202A578

	thumb_func_start sub_C38C
sub_C38C: @ 0x0800C38C
	push {lr}
	bl sub_C4F0
	ldr r0, _0800C3C4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	ble _0800C3C0
	ldr r2, _0800C3C8 @ =gUnknown_0201A450
	movs r1, #1
	strb r1, [r2, #0xc]
	adds r0, r2, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	adds r0, #0x10
	strb r1, [r0]
	ldr r1, _0800C3CC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C3C0:
	pop {r0}
	bx r0
	.align 2, 0
_0800C3C4: .4byte gUnknown_0202BF10
_0800C3C8: .4byte gUnknown_0201A450
_0800C3CC: .4byte gUnknown_0202C790

	thumb_func_start sub_C3D0
sub_C3D0: @ 0x0800C3D0
	push {r4, lr}
	ldr r3, _0800C408 @ =gUnknown_0201A450
	ldrh r0, [r3]
	subs r0, #9
	strh r0, [r3]
	ldrh r0, [r3, #2]
	subs r0, #6
	strh r0, [r3, #2]
	ldrh r0, [r3, #0x18]
	adds r0, #1
	strh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _0800C40C
	ldrh r2, [r3, #0x14]
	ldrh r1, [r3, #0x10]
	adds r0, r2, r1
	strh r0, [r3, #0x10]
	ldrh r1, [r3, #0x16]
	ldrh r4, [r3, #0x12]
	adds r0, r1, r4
	strh r0, [r3, #0x12]
	subs r2, #1
	strh r2, [r3, #0x14]
	subs r1, #1
	strh r1, [r3, #0x16]
	b _0800C424
	.align 2, 0
_0800C408: .4byte gUnknown_0201A450
_0800C40C:
	ldr r0, _0800C444 @ =gUnknown_0202BF10
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800C424
	ldrh r0, [r3, #0x10]
	adds r0, #1
	strh r0, [r3, #0x10]
	ldrh r0, [r3, #0x12]
	adds r0, #1
	strh r0, [r3, #0x12]
_0800C424:
	bl sub_C4F0
	ldr r0, _0800C448 @ =gUnknown_0201A450
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800C43E
	ldr r1, _0800C44C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800C43E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C444: .4byte gUnknown_0202BF10
_0800C448: .4byte gUnknown_0201A450
_0800C44C: .4byte gUnknown_0202C790

	thumb_func_start sub_C450
sub_C450: @ 0x0800C450
	push {lr}
	bl sub_C4F0
	ldr r2, _0800C484 @ =gUnknown_0202BF10
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800C470
	ldr r0, _0800C488 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	adds r1, #1
	strh r1, [r0, #0x10]
	ldrh r1, [r0, #0x12]
	adds r1, #1
	strh r1, [r0, #0x12]
_0800C470:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x14
	ble _0800C480
	ldr r1, _0800C48C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
_0800C480:
	pop {r0}
	bx r0
	.align 2, 0
_0800C484: .4byte gUnknown_0202BF10
_0800C488: .4byte gUnknown_0201A450
_0800C48C: .4byte gUnknown_0202C790

	thumb_func_start nullsub_12
nullsub_12: @ 0x0800C490
	bx lr

	thumb_func_start nullsub_13
nullsub_13: @ 0x0800C494
	bx lr

	thumb_func_start sub_C498
sub_C498: @ 0x0800C498
	push {lr}
	sub sp, #8
	bl sub_10480
	bl ClearSprites
	movs r2, #0
	str r2, [sp]
	ldr r1, _0800C4DC @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800C4E0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	ldr r0, _0800C4E4 @ =0x06010000
	str r0, [r1, #4]
	ldr r0, _0800C4E8 @ =0x81002800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl sub_10544
	ldr r1, _0800C4EC @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800C4DC: .4byte 0x040000D4
_0800C4E0: .4byte 0x85000100
_0800C4E4: .4byte 0x06010000
_0800C4E8: .4byte 0x81002800
_0800C4EC: .4byte gUnknown_0202C790

	thumb_func_start sub_C4F0
sub_C4F0: @ 0x0800C4F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r0, _0800C64C @ =gUnknown_0200B3B8
	mov r8, r0
	ldr r6, _0800C650 @ =gUnknown_0201A450
	movs r1, #0x28
	ldrsh r0, [r6, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r3, r0, #0
	muls r3, r2, r3
	movs r0, #0xb8
	lsls r0, r0, #1
	add r0, r8
	adds r3, r3, r0
	str r3, [sp]
	movs r7, #0x38
	ldrsh r0, [r6, r7]
	muls r0, r2, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	movs r1, #0xb8
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x58
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r2, r0
	adds r1, r2, #0
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	movs r1, #0x8a
	lsls r1, r1, #3
	add r1, r8
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xc
	ldrsb r0, [r6, r0]
	mov r2, r8
	strh r0, [r2]
	movs r0, #1
	ldr r7, _0800C654 @ =gUnknown_0200B470
	strh r0, [r7]
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r3]
	ldr r1, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	adds r0, r6, #0
	adds r0, #0x6c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r0, _0800C658 @ =gUnknown_086A7C24
	movs r1, #0x11
	bl LoadSpriteSets
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800C614
	ldrh r0, [r6]
	strh r0, [r1, #2]
	ldrh r0, [r6, #2]
	strh r0, [r1, #4]
	mov r5, r8
	adds r5, #8
	ldr r4, _0800C65C @ =gOamBuffer
	ldrh r1, [r1, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	mov r3, r8
	ldrh r2, [r3, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r7, #2
	ldrsh r1, [r5, r7]
	movs r7, #2
	ldrsh r0, [r3, r7]
	adds r1, r1, r0
	ldr r3, _0800C660 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800C664 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r7, r8
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_0800C614:
	movs r5, #0
	str r6, [sp, #0x14]
_0800C618:
	lsls r1, r5, #2
	mov r2, sp
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	adds r4, r1, #0
	adds r3, r5, #1
	str r3, [sp, #0x18]
	cmp r0, #1
	beq _0800C62E
	b _0800C75A
_0800C62E:
	ldr r1, _0800C668 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0800C670
	lsls r1, r5, #3
	ldr r6, _0800C66C @ =gUnknown_086A7C68
	adds r0, r1, r6
	ldrb r2, [r0, #2]
	ldrb r0, [r0, #3]
	b _0800C67A
	.align 2, 0
_0800C64C: .4byte gUnknown_0200B3B8
_0800C650: .4byte gUnknown_0201A450
_0800C654: .4byte gUnknown_0200B470
_0800C658: .4byte gUnknown_086A7C24
_0800C65C: .4byte gOamBuffer
_0800C660: .4byte 0x000001FF
_0800C664: .4byte 0xFFFFFE00
_0800C668: .4byte gUnknown_0202A578
_0800C66C: .4byte gUnknown_086A7C68
_0800C670:
	lsls r1, r5, #3
	ldr r7, _0800C7F8 @ =gUnknown_086A7C68
	adds r0, r1, r7
	ldrb r2, [r0]
	ldrb r0, [r0, #1]
_0800C67A:
	adds r7, r1, #0
	adds r3, r5, #2
	lsls r1, r3, #4
	ldr r6, [sp, #0x14]
	adds r1, r1, r6
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldrh r6, [r1]
	adds r2, r2, r6
	strh r2, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r6, [r1, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	add r4, sp
	ldr r0, [r4]
	strh r2, [r0, #2]
	ldr r2, [r4]
	ldrh r0, [r1, #2]
	strh r0, [r2, #4]
	movs r0, #8
	ldrsh r1, [r1, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, #2
	adds r0, r5, r0
	lsls r0, r0, #2
	ldr r1, _0800C7FC @ =gUnknown_086A7C24
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r6, #0
	str r3, [sp, #0x1c]
	adds r5, #1
	str r5, [sp, #0x18]
	ldrh r2, [r0]
	cmp r6, r2
	bge _0800C732
	ldr r3, _0800C800 @ =gOamBuffer
	mov ip, r3
	ldr r0, _0800C7F8 @ =gUnknown_086A7C68
	adds r7, r7, r0
	mov sl, r7
	movs r7, #8
_0800C6D4:
	ldr r0, [r4]
	adds r5, r0, r7
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	mov r0, sl
	ldrb r1, [r0, #5]
	movs r3, #3
	ands r1, r3
	lsls r1, r1, #2
	ldrb r3, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #2
	ldrsh r1, [r5, r0]
	ldr r0, [r4]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _0800C804 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800C808 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, ip
	ldr r0, [r4]
	ldrb r0, [r0, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r7, #8
	adds r6, #1
	mov r0, sb
	ldrh r0, [r0]
	cmp r6, r0
	blt _0800C6D4
_0800C732:
	ldr r1, [sp, #0x1c]
	lsls r0, r1, #4
	ldr r2, [sp, #0x14]
	adds r3, r0, r2
	ldrh r0, [r3, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0800C75A
	strh r1, [r3, #0xa]
	ldrh r1, [r3, #8]
	movs r6, #8
	ldrsh r0, [r3, r6]
	cmp r0, #1
	bgt _0800C75A
	adds r0, r1, #1
	strh r0, [r3, #8]
_0800C75A:
	ldr r5, [sp, #0x18]
	cmp r5, #4
	bgt _0800C762
	b _0800C618
_0800C762:
	ldr r7, _0800C80C @ =gUnknown_0200B470
	ldrh r0, [r7]
	cmp r0, #1
	bne _0800C7C8
	ldr r0, _0800C810 @ =gUnknown_0201A450
	ldrh r1, [r0, #0x10]
	strh r1, [r7, #2]
	ldrh r0, [r0, #0x12]
	strh r0, [r7, #4]
	ldr r5, _0800C800 @ =gOamBuffer
	ldr r0, _0800C808 @ =0xFFFFFE00
	mov sb, r0
	adds r4, r7, #0
	adds r4, #8
	movs r6, #3
_0800C780:
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r7, _0800C80C @ =gUnknown_0200B470
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _0800C804 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, _0800C80C @ =gUnknown_0200B470
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _0800C780
_0800C7C8:
	movs r0, #0
	ldr r6, _0800C80C @ =gUnknown_0200B470
	strh r0, [r6]
	mov r7, r8
	strh r0, [r7]
	ldr r1, [sp]
	strh r0, [r1]
	ldr r1, [sp, #4]
	strh r0, [r1]
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r1, [sp, #0xc]
	strh r0, [r1]
	ldr r1, [sp, #0x10]
	strh r0, [r1]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C7F8: .4byte gUnknown_086A7C68
_0800C7FC: .4byte gUnknown_086A7C24
_0800C800: .4byte gOamBuffer
_0800C804: .4byte 0x000001FF
_0800C808: .4byte 0xFFFFFE00
_0800C80C: .4byte gUnknown_0200B470
_0800C810: .4byte gUnknown_0201A450

	thumb_func_start sub_C814
sub_C814: @ 0x0800C814
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_518
	movs r0, #0
	str r0, [sp]
	ldr r1, _0800C924 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0800C928 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0
	ldr r6, _0800C92C @ =gMain
	movs r1, #0xb8
	mov sb, r1
	movs r4, #0
	movs r3, #0xc0
	lsls r3, r3, #2
	mov r8, r3
	ldr r7, _0800C930 @ =0x00000302
	mov ip, r7
	movs r0, #0xc1
	lsls r0, r0, #2
	mov sl, r0
_0800C854:
	mov r2, sb
	muls r2, r5, r2
	adds r1, r2, r6
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r1, r3
	strh r4, [r0]
	ldr r7, _0800C934 @ =0x000002FA
	adds r0, r1, r7
	strh r4, [r0]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r4, [r1]
	movs r3, #0
_0800C872:
	lsls r0, r3, #3
	adds r0, r0, r2
	adds r0, r0, r6
	mov r7, r8
	adds r1, r0, r7
	strh r4, [r1]
	mov r7, ip
	adds r1, r0, r7
	strh r4, [r1]
	add r0, sl
	strh r4, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x15
	bls _0800C872
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls _0800C854
	movs r5, #0
	mov sl, r5
	movs r0, #0xd
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	mov sb, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	mov r8, r3
	movs r4, #0x3f
	ldr r6, _0800C938 @ =0xFFFFFE00
	adds r3, #0x12
_0800C8B8:
	lsls r2, r5, #3
	ldr r7, _0800C93C @ =gOamBuffer
	adds r2, r2, r7
	movs r0, #0xf4
	strb r0, [r2]
	movs r0, #0
	strb r0, [r2, #1]
	ldrh r1, [r2, #2]
	adds r0, r6, #0
	ands r0, r1
	movs r7, #0xfa
	lsls r7, r7, #1
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrb r1, [r2, #3]
	adds r0, r3, #0
	ands r0, r1
	mov r1, sb
	ands r0, r1
	mov r7, r8
	ands r0, r7
	ands r0, r4
	strb r0, [r2, #3]
	ldrh r1, [r2, #4]
	ldr r0, _0800C940 @ =0xFFFFFC00
	ands r0, r1
	strh r0, [r2, #4]
	ldrb r1, [r2, #5]
	mov r0, ip
	ands r0, r1
	movs r1, #0xf
	ands r0, r1
	strb r0, [r2, #5]
	mov r0, sl
	strh r0, [r2, #6]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls _0800C8B8
	ldr r1, _0800C944 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C924: .4byte 0x040000D4
_0800C928: .4byte 0x85000100
_0800C92C: .4byte gMain
_0800C930: .4byte 0x00000302
_0800C934: .4byte 0x000002FA
_0800C938: .4byte 0xFFFFFE00
_0800C93C: .4byte gOamBuffer
_0800C940: .4byte 0xFFFFFC00
_0800C944: .4byte gUnknown_0202C790

	thumb_func_start sub_C948
sub_C948: @ 0x0800C948
	push {r4, lr}
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r3]
	ldr r1, _0800C9E4 @ =0x0400000E
	movs r0, #7
	strh r0, [r1]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0800C9E8 @ =0x040000D4
	ldr r1, _0800C9EC @ =gUnknown_08115A60
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0800C9F0 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800C9F4 @ =gUnknown_08116260
	str r1, [r0]
	ldr r1, _0800C9F8 @ =0x06004000
	str r1, [r0, #4]
	ldr r1, _0800C9FC @ =0x80001200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r4, _0800CA00 @ =gUnknown_08115860
	str r4, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r2, _0800CA04 @ =0x80000020
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _0800CA08 @ =gUnknown_08118680
	str r1, [r0]
	ldr r1, _0800CA0C @ =0x06010000
	str r1, [r0, #4]
	ldr r1, _0800CA10 @ =0x80003800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [r0]
	ldr r1, _0800CA14 @ =0x05000200
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _0800CA18 @ =gMain
	ldrh r0, [r3]
	strh r0, [r4, #0x16]
	bl sub_CA28
	ldr r2, _0800CA1C @ =gUnknown_0202ADA0
	ldrh r1, [r2]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldr r1, _0800CA20 @ =0x000002F6
	adds r4, r4, r1
	strh r0, [r4]
	bl sub_CBC
	bl sub_10424
	ldr r1, _0800CA24 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800C9E4: .4byte 0x0400000E
_0800C9E8: .4byte 0x040000D4
_0800C9EC: .4byte gUnknown_08115A60
_0800C9F0: .4byte 0x80000400
_0800C9F4: .4byte gUnknown_08116260
_0800C9F8: .4byte 0x06004000
_0800C9FC: .4byte 0x80001200
_0800CA00: .4byte gUnknown_08115860
_0800CA04: .4byte 0x80000020
_0800CA08: .4byte gUnknown_08118680
_0800CA0C: .4byte 0x06010000
_0800CA10: .4byte 0x80003800
_0800CA14: .4byte 0x05000200
_0800CA18: .4byte gMain
_0800CA1C: .4byte gUnknown_0202ADA0
_0800CA20: .4byte 0x000002F6
_0800CA24: .4byte gUnknown_0202C790

	thumb_func_start sub_CA28
sub_CA28: @ 0x0800CA28
	push {r4, lr}
	ldr r0, _0800CA80 @ =gUnknown_0202ADA0
	movs r4, #0
	movs r3, #0
	strh r3, [r0]
	strh r3, [r0, #2]
	ldr r1, _0800CA84 @ =gUnknown_0201A450
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0x1e
	strh r0, [r1, #2]
	movs r0, #0xe
	strh r0, [r1, #4]
	movs r2, #1
	movs r0, #1
	strh r0, [r1, #8]
	strb r2, [r1, #0xc]
	movs r0, #0x84
	lsls r0, r0, #1
	strh r0, [r1, #0x10]
	movs r0, #0x50
	strh r0, [r1, #0x12]
	movs r0, #6
	strh r0, [r1, #0x14]
	strb r4, [r1, #0x1c]
	ldr r0, _0800CA88 @ =gUnknown_0202BF10
	strh r3, [r0]
	ldr r0, _0800CA8C @ =gUnknown_0202A578
	strh r3, [r0]
	ldr r0, _0800CA90 @ =gUnknown_0202C5E4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0800CA94 @ =gUnknown_0202ADD8
	strh r1, [r0]
	ldr r0, _0800CA98 @ =gUnknown_0202BEDC
	strb r4, [r0]
	ldr r0, _0800CA9C @ =gUnknown_0202A56C
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CA80: .4byte gUnknown_0202ADA0
_0800CA84: .4byte gUnknown_0201A450
_0800CA88: .4byte gUnknown_0202BF10
_0800CA8C: .4byte gUnknown_0202A578
_0800CA90: .4byte gUnknown_0202C5E4
_0800CA94: .4byte gUnknown_0202ADD8
_0800CA98: .4byte gUnknown_0202BEDC
_0800CA9C: .4byte gUnknown_0202A56C

	thumb_func_start sub_CAA0
sub_CAA0: @ 0x0800CAA0
	push {r4, r5, lr}
	ldr r4, _0800CB48 @ =gUnknown_0202ADA0
	ldrh r0, [r4]
	subs r0, #0x24
	strh r0, [r4]
	ldr r5, _0800CB4C @ =gUnknown_0201A450
	ldr r1, _0800CB50 @ =gUnknown_086A7D4C
	ldr r2, _0800CB54 @ =gUnknown_0202A578
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r0, _0800CB58 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800CAEA
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble _0800CAEA
	movs r0, #1
	strh r0, [r5, #8]
_0800CAEA:
	ldr r0, _0800CB5C @ =gMain
	ldrh r1, [r4]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bl sub_CD18
	ldr r2, _0800CB58 @ =gUnknown_0202BF10
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x28
	ble _0800CB26
	ldr r1, _0800CB60 @ =gUnknown_0202C5E4
	ldrh r0, [r1]
	adds r0, #6
	strh r0, [r1]
	ldr r1, _0800CB64 @ =gUnknown_0202ADD8
	ldrh r0, [r1]
	adds r0, #6
	strh r0, [r1]
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800CB26
	ldr r1, _0800CB4C @ =gUnknown_0201A450
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_0800CB26:
	ldr r0, _0800CB58 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x5a
	ble _0800CB42
	ldr r1, _0800CB4C @ =gUnknown_0201A450
	movs r0, #0
	strb r0, [r1, #0xc]
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, _0800CB68 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CB42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800CB48: .4byte gUnknown_0202ADA0
_0800CB4C: .4byte gUnknown_0201A450
_0800CB50: .4byte gUnknown_086A7D4C
_0800CB54: .4byte gUnknown_0202A578
_0800CB58: .4byte gUnknown_0202BF10
_0800CB5C: .4byte gMain
_0800CB60: .4byte gUnknown_0202C5E4
_0800CB64: .4byte gUnknown_0202ADD8
_0800CB68: .4byte gUnknown_0202C790

	thumb_func_start sub_CB6C
sub_CB6C: @ 0x0800CB6C
	ldr r0, _0800CB94 @ =gUnknown_0202ADA0
	ldrh r1, [r0]
	subs r1, #0x24
	strh r1, [r0]
	ldr r0, _0800CB98 @ =gMain
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	ldr r0, _0800CB9C @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	ble _0800CB90
	ldr r1, _0800CBA0 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CB90:
	bx lr
	.align 2, 0
_0800CB94: .4byte gUnknown_0202ADA0
_0800CB98: .4byte gMain
_0800CB9C: .4byte gUnknown_0202BF10
_0800CBA0: .4byte gUnknown_0202C790

	thumb_func_start sub_CBA4
sub_CBA4: @ 0x0800CBA4
	push {r4, lr}
	ldr r0, _0800CBBC @ =gUnknown_0202BF10
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r0, #0
	cmp r1, #0x86
	bgt _0800CBC4
	ldr r1, _0800CBC0 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #0xc
	b _0800CBCA
	.align 2, 0
_0800CBBC: .4byte gUnknown_0202BF10
_0800CBC0: .4byte gUnknown_0201A450
_0800CBC4:
	ldr r1, _0800CC68 @ =gUnknown_0201A450
	ldrh r0, [r1, #0x10]
	subs r0, #1
_0800CBCA:
	strh r0, [r1, #0x10]
	ldrh r0, [r2]
	movs r1, #1
	ands r0, r1
	ldr r2, _0800CC6C @ =gUnknown_0202BEDC
	cmp r0, #0
	bne _0800CBEA
	ldrb r0, [r2]
	adds r0, #3
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	ble _0800CBEA
	movs r0, #0x20
	strb r0, [r2]
_0800CBEA:
	ldr r4, _0800CC70 @ =gUnknown_08115860
	ldr r1, _0800CC74 @ =0x05000200
	movs r3, #0
	ldrsb r3, [r2, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r2, #0x20
	bl sub_102A8
	ldr r0, _0800CC78 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x88
	ble _0800CC30
	ldr r2, _0800CC7C @ =gUnknown_0202A56C
	ldrb r0, [r2]
	adds r0, #2
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	ble _0800CC1C
	movs r0, #0x20
	strb r0, [r2]
_0800CC1C:
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r3, #0
	ldrsb r3, [r2, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	movs r2, #0x40
	bl sub_102A8
_0800CC30:
	ldr r0, _0800CC80 @ =gUnknown_0202ADA0
	ldrh r1, [r0]
	subs r1, #0x24
	strh r1, [r0]
	ldr r0, _0800CC84 @ =gMain
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bl sub_CD18
	ldr r1, _0800CC78 @ =gUnknown_0202BF10
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x98
	ble _0800CC62
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0800CC88 @ =gUnknown_0202A578
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0800CC8C @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0800CC62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800CC68: .4byte gUnknown_0201A450
_0800CC6C: .4byte gUnknown_0202BEDC
_0800CC70: .4byte gUnknown_08115860
_0800CC74: .4byte 0x05000200
_0800CC78: .4byte gUnknown_0202BF10
_0800CC7C: .4byte gUnknown_0202A56C
_0800CC80: .4byte gUnknown_0202ADA0
_0800CC84: .4byte gMain
_0800CC88: .4byte gUnknown_0202A578
_0800CC8C: .4byte gUnknown_0202C790

	thumb_func_start nullsub_14
nullsub_14: @ 0x0800CC90
	bx lr

	thumb_func_start sub_CC94
sub_CC94: @ 0x0800CC94
	push {r4, r5, r6, lr}
	ldr r6, _0800CCE4 @ =gUnknown_0202BF10
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800CCCE
	ldr r1, _0800CCE8 @ =gUnknown_0202A578
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r4, _0800CCEC @ =gMPlayInfo_BGM
	ldr r5, _0800CCF0 @ =0x0000FFFF
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl __divsi3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl m4aMPlayVolumeControl
_0800CCCE:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0x2d
	ble _0800CCDE
	ldr r1, _0800CCF4 @ =gUnknown_0202C790
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800CCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800CCE4: .4byte gUnknown_0202BF10
_0800CCE8: .4byte gUnknown_0202A578
_0800CCEC: .4byte gMPlayInfo_BGM
_0800CCF0: .4byte 0x0000FFFF
_0800CCF4: .4byte gUnknown_0202C790

	thumb_func_start sub_CCF8
sub_CCF8: @ 0x0800CCF8
	push {lr}
	bl sub_2B4
	bl m4aMPlayAllStop
	bl sub_D10
	ldr r1, _0800CD14 @ =gMain
	ldrb r0, [r1, #3]
	adds r0, #1
	strb r0, [r1, #3]
	pop {r0}
	bx r0
	.align 2, 0
_0800CD14: .4byte gMain

	thumb_func_start sub_CD18
sub_CD18: @ 0x0800CD18
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _0800CE28 @ =gUnknown_0201A450
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r0, #0xb8
	muls r1, r0, r1
	ldr r0, _0800CE2C @ =gUnknown_0200B3B8
	adds r6, r1, r0
	mov r8, r0
	movs r0, #0xc
	ldrsb r0, [r7, r0]
	strh r0, [r6]
	movs r0, #0x1c
	ldrsb r0, [r7, r0]
	mov r1, r8
	strh r0, [r1]
	ldr r0, _0800CE30 @ =gUnknown_086A7D20
	movs r1, #0xb
	mov r2, r8
	bl LoadSpriteSets
	ldrh r0, [r6]
	cmp r0, #1
	bne _0800CDBA
	ldr r0, _0800CE34 @ =gUnknown_0202C5E4
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, _0800CE38 @ =gUnknown_0202ADD8
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #0
	bl SetMatrixScale
	ldrh r0, [r7]
	strh r0, [r6, #2]
	ldrh r0, [r7, #2]
	strh r0, [r6, #4]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0800CE3C @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0800CE40 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0800CE44 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r1, #1]
	movs r2, #3
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r2, [r1, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #3]
_0800CDBA:
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #1
	bne _0800CE12
	ldrh r0, [r7, #0x10]
	strh r0, [r1, #2]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	ldr r2, _0800CE3C @ =gOamBuffer
	mov sb, r2
	ldr r3, _0800CE44 @ =0xFFFFFE00
	mov ip, r3
	mov r4, r8
	adds r4, #8
	movs r5, #3
_0800CDD8:
	ldrh r3, [r4]
	lsls r3, r3, #3
	add r3, sb
	movs r7, #2
	ldrsh r1, [r4, r7]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0800CE40 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, sb
	mov r3, r8
	ldrb r0, [r3, #4]
	ldrb r7, [r4, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _0800CDD8
_0800CE12:
	movs r0, #0
	strh r0, [r6]
	mov r1, r8
	strh r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800CE28: .4byte gUnknown_0201A450
_0800CE2C: .4byte gUnknown_0200B3B8
_0800CE30: .4byte gUnknown_086A7D20
_0800CE34: .4byte gUnknown_0202C5E4
_0800CE38: .4byte gUnknown_0202ADD8
_0800CE3C: .4byte gOamBuffer
_0800CE40: .4byte 0x000001FF
_0800CE44: .4byte 0xFFFFFE00
