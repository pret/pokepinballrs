#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_2A354
sub_2A354: @ 0x0802A354
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802A3C4 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _0802A3C8 @ =0x000006DE
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0xb3
	bhi _0802A3A6
	cmp r0, #4
	bne _0802A36E
	movs r0, 0x14 @ =MUS_UNKNOWN_0x14
	bl m4aSongNumStart
_0802A36E:
	ldr r1, [r4]
	ldr r2, _0802A3CC @ =0x000006DC
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802A388
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _0802A388
	movs r0, 0xB2 @=SE_UNKNOWN_0xB2
	bl m4aSongNumStart
_0802A388:
	ldr r0, _0802A3C4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _0802A3C8 @ =0x000006DE
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bhi _0802A3A6
	movs r0, #8
	movs r1, #0
	bl sub_1C7F4
_0802A3A6:
	ldr r1, _0802A3C4 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r4, _0802A3CC @ =0x000006DC
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #0x2d
	bls _0802A3B8
	b _0802AAD2
_0802A3B8:
	lsls r0, r0, #2
	ldr r1, _0802A3D0 @ =_0802A3D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A3C4: .4byte gCurrentPinballGame
_0802A3C8: .4byte 0x000006DE
_0802A3CC: .4byte 0x000006DC
_0802A3D0: .4byte _0802A3D4
_0802A3D4: @ jump table
	.4byte _0802A48C @ case 0
	.4byte _0802A48C @ case 1
	.4byte _0802A48C @ case 2
	.4byte _0802A4B0 @ case 3
	.4byte _0802A648 @ case 4
	.4byte _0802A668 @ case 5
	.4byte _0802A690 @ case 6
	.4byte _0802A718 @ case 7
	.4byte _0802A778 @ case 8
	.4byte _0802A798 @ case 9
	.4byte _0802A830 @ case 10
	.4byte _0802A830 @ case 11
	.4byte _0802A830 @ case 12
	.4byte _0802A864 @ case 13
	.4byte _0802AAD2 @ case 14
	.4byte _0802AAD2 @ case 15
	.4byte _0802AAD2 @ case 16
	.4byte _0802A8CC @ case 17
	.4byte _0802A8CC @ case 18
	.4byte _0802A8CC @ case 19
	.4byte _0802A924 @ case 20
	.4byte _0802A940 @ case 21
	.4byte _0802A964 @ case 22
	.4byte _0802A9A8 @ case 23
	.4byte _0802A9E0 @ case 24
	.4byte _0802A9E0 @ case 25
	.4byte _0802A9E0 @ case 26
	.4byte _0802A9E0 @ case 27
	.4byte _0802A9E0 @ case 28
	.4byte _0802A9E0 @ case 29
	.4byte _0802A9E0 @ case 30
	.4byte _0802A9E0 @ case 31
	.4byte _0802A9E0 @ case 32
	.4byte _0802AA24 @ case 33
	.4byte _0802AA44 @ case 34
	.4byte _0802AA64 @ case 35
	.4byte _0802AA84 @ case 36
	.4byte _0802AA84 @ case 37
	.4byte _0802AA84 @ case 38
	.4byte _0802AA84 @ case 39
	.4byte _0802AA84 @ case 40
	.4byte _0802AAC0 @ case 41
	.4byte _0802AAC0 @ case 42
	.4byte _0802AAC0 @ case 43
	.4byte _0802AAC0 @ case 44
	.4byte _0802AAC0 @ case 45
_0802A48C:
	ldr r2, [r5]
	ldr r1, _0802A4A8 @ =0x000006DC
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, _0802A4AC @ =0x00000724
	adds r2, r2, r3
	strh r0, [r2]
	b _0802AAD2
	.align 2, 0
_0802A4A8: .4byte 0x000006DC
_0802A4AC: .4byte 0x00000724
_0802A4B0:
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0802A578
	ldr r2, _0802A560 @ =0x000006DE
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x7c
	bls _0802A4E2
	movs r0, #0xd7
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x63
	bhi _0802A4E2
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r2
	movs r1, #0x7c
	strh r1, [r0]
_0802A4E2:
	ldr r3, [r5]
	ldr r1, _0802A560 @ =0x000006DE
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #4
	beq _0802A4F0
	b _0802AAD2
_0802A4F0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	movs r1, #0xa8
	strh r1, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #0xd
	strh r1, [r0]
	adds r4, #2
	adds r0, r3, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r2, [r0]
	adds r4, #0xc
	adds r1, r3, r4
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _0802A564 @ =0x040000D4
	ldr r0, _0802A568 @ =gUnknown_084C156C
	str r0, [r1]
	ldr r0, _0802A56C @ =0x06010600
	str r0, [r1, #4]
	ldr r0, _0802A570 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5]
	movs r3, #0xf1
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802A574 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xa4
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r5]
	subs r4, #0x16
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	b _0802AAD2
	.align 2, 0
_0802A560: .4byte 0x000006DE
_0802A564: .4byte 0x040000D4
_0802A568: .4byte gUnknown_084C156C
_0802A56C: .4byte 0x06010600
_0802A570: .4byte 0x800000C0
_0802A574: .4byte gMain
_0802A578:
	ldr r7, _0802A640 @ =0x000006DE
	adds r0, r4, r7
	ldrh r6, [r0]
	cmp r6, #0x78
	bne _0802A61E
	ldr r2, _0802A644 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	strh r3, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0xfa
	strh r0, [r1]
	subs r1, #4
	adds r0, #0x16
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe6
	strh r3, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf2
	strb r2, [r0]
	ldr r0, [r5]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r0, [r5]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r4, [r5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, [r5]
	movs r4, #0xe3
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r1, #0xa8
	strh r1, [r0]
	adds r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0xd
	strh r1, [r0]
	adds r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r6, [r0]
	adds r4, #0x12
	adds r1, r2, r4
	movs r0, #0x3c
	strh r0, [r1]
_0802A61E:
	ldr r1, [r5]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802A62E
	b _0802AAD2
_0802A62E:
	adds r1, r1, r7
	ldrh r0, [r1]
	cmp r0, #0xaf
	bhi _0802A638
	b _0802AAD2
_0802A638:
	movs r0, #0xb0
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A640: .4byte 0x000006DE
_0802A644: .4byte gMain
_0802A648:
	ldr r1, [r5]
	ldr r3, _0802A660 @ =0x000006DE
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A656
	b _0802AAD2
_0802A656:
	ldr r4, _0802A664 @ =0x00000286
	adds r1, r1, r4
	movs r0, #0x5a
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A660: .4byte 0x000006DE
_0802A664: .4byte 0x00000286
_0802A668:
	ldr r4, [r5]
	ldr r0, _0802A688 @ =0x000006DE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A676
	b _0802AAD2
_0802A676:
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, _0802A68C @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x21
	b _0802A744
	.align 2, 0
_0802A688: .4byte 0x000006DE
_0802A68C: .4byte gMain
_0802A690:
	ldr r4, [r5]
	ldr r3, _0802A6BC @ =0x000006DE
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A69E
	b _0802AAD2
_0802A69E:
	movs r0, #0xc
	strh r0, [r1]
	ldr r0, _0802A6C0 @ =0x000006E9
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0802A6C8
	ldr r0, _0802A6C4 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x18
	b _0802A744
	.align 2, 0
_0802A6BC: .4byte 0x000006DE
_0802A6C0: .4byte 0x000006E9
_0802A6C4: .4byte gMain
_0802A6C8:
	cmp r0, #0xa
	bgt _0802A6E0
	ldr r0, _0802A6DC @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x18
	b _0802A768
	.align 2, 0
_0802A6DC: .4byte gMain
_0802A6E0:
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A704
	ldr r0, _0802A700 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x1c
	b _0802A744
	.align 2, 0
_0802A700: .4byte gMain
_0802A704:
	ldr r0, _0802A714 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #7
	bl __umodsi3
	adds r0, #0x18
	b _0802A768
	.align 2, 0
_0802A714: .4byte gMain
_0802A718:
	ldr r4, [r5]
	ldr r0, _0802A74C @ =0x000006DE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x5f
	beq _0802A726
	b _0802AAD2
_0802A726:
	movs r0, #0xc
	strh r0, [r1]
	ldr r1, _0802A750 @ =0x000006E9
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bgt _0802A75C
	ldr r0, _0802A754 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	adds r0, #0x24
_0802A744:
	ldr r2, _0802A758 @ =0x000006DC
	adds r1, r4, r2
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A74C: .4byte 0x000006DE
_0802A750: .4byte 0x000006E9
_0802A754: .4byte gMain
_0802A758: .4byte 0x000006DC
_0802A75C:
	ldr r0, _0802A770 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #5
	bl __umodsi3
	adds r0, #0x24
_0802A768:
	ldr r3, _0802A774 @ =0x000006DC
	adds r1, r4, r3
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A770: .4byte gMain
_0802A774: .4byte 0x000006DC
_0802A778:
	ldr r0, [r5]
	ldr r4, _0802A794 @ =0x000006DE
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A786
	b _0802AAD2
_0802A786:
	movs r0, #4
	bl sub_19B64
	ldr r1, [r5]
	movs r0, #0x64
	strh r0, [r1, #0x28]
	b _0802AAD2
	.align 2, 0
_0802A794: .4byte 0x000006DE
_0802A798:
	ldr r1, [r5]
	ldr r2, _0802A818 @ =0x00000281
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0802A7AA
	b _0802AAD2
_0802A7AA:
	ldr r4, _0802A81C @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x95
	bne _0802A7C6
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r2, r1, r3
	movs r0, #0xb4
	strh r0, [r2]
	ldr r0, _0802A820 @ =0x000006C4
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
_0802A7C6:
	ldr r2, [r5]
	adds r1, r2, r4
	ldrh r0, [r1]
	cmp r0, #0x96
	bne _0802A7F2
	movs r0, #0x95
	strh r0, [r1]
	ldr r3, _0802A824 @ =0x000001A5
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	bl sub_1B140
	ldr r0, [r5]
	ldr r1, _0802A828 @ =0x0000036A
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0802A82C @ =0x0000036B
	adds r0, r0, r2
	strb r1, [r0]
_0802A7F2:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0xaa
	beq _0802A7FE
	b _0802AAD2
_0802A7FE:
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _0802A824 @ =0x000001A5
	adds r0, r0, r4
	strb r1, [r0]
	movs r0, #6
	bl sub_19B64
	b _0802AAD2
	.align 2, 0
_0802A818: .4byte 0x00000281
_0802A81C: .4byte 0x000006DE
_0802A820: .4byte 0x000006C4
_0802A824: .4byte 0x000001A5
_0802A828: .4byte 0x0000036A
_0802A82C: .4byte 0x0000036B
_0802A830:
	ldr r1, [r5]
	ldr r2, _0802A85C @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A83E
	b _0802AAD2
_0802A83E:
	ldr r4, _0802A860 @ =0x000005F6
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _0802A850
	adds r0, r2, #1
	strb r0, [r1]
_0802A850:
	ldr r0, [r5]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r0, r3
	b _0802A882
	.align 2, 0
_0802A85C: .4byte 0x000006DE
_0802A860: .4byte 0x000005F6
_0802A864:
	ldr r1, [r5]
	ldr r4, _0802A8B0 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A872
	b _0802AAD2
_0802A872:
	subs r4, #0xe8
	adds r1, r1, r4
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r0, r1
_0802A882:
	movs r1, #0xe1
	lsls r1, r1, #4
	strh r1, [r0]
	ldr r0, _0802A8B4 @ =gMPlayInfo_SE1
	ldr r1, _0802A8B8 @ =gUnknown_0869F664
	bl MPlayStart
	ldr r2, _0802A8BC @ =0x040000D4
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0802A8C0 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802A8C4 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0802A8C8 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802AAD2
	.align 2, 0
_0802A8B0: .4byte 0x000006DE
_0802A8B4: .4byte gMPlayInfo_SE1
_0802A8B8: .4byte gUnknown_0869F664
_0802A8BC: .4byte 0x040000D4
_0802A8C0: .4byte gUnknown_08137E14
_0802A8C4: .4byte 0x05000220
_0802A8C8: .4byte 0x80000010
_0802A8CC:
	ldr r1, [r5]
	ldr r4, _0802A918 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	bne _0802A906
	ldr r2, _0802A91C @ =0x0000072B
	adds r1, r1, r2
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r2, [r5]
	ldr r1, _0802A920 @ =0x000006DC
	adds r0, r2, r1
	ldrb r1, [r0]
	subs r1, #0x11
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xa
	movs r1, #0xca
	lsls r1, r1, #1
	adds r2, r2, r1
	strb r0, [r2]
	ldr r0, [r5]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r3, [r0]
_0802A906:
	ldr r0, [r5]
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0x8c
	beq _0802A912
	b _0802AAD2
_0802A912:
	movs r0, #0x8b
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A918: .4byte 0x000006DE
_0802A91C: .4byte 0x0000072B
_0802A920: .4byte 0x000006DC
_0802A924:
	ldr r1, [r5]
	ldr r3, _0802A93C @ =0x000006DE
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x82
	beq _0802A932
	b _0802AAD2
_0802A932:
	adds r1, #0x6c
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A93C: .4byte 0x000006DE
_0802A940:
	ldr r1, [r5]
	ldr r4, _0802A960 @ =0x000006DE
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A94E
	b _0802AAD2
_0802A94E:
	movs r0, #0x64
	strh r0, [r1, #0x28]
	adds r1, #0x72
	movs r0, #0xf
	strb r0, [r1]
	movs r0, #8
	bl sub_19B64
	b _0802AAD2
	.align 2, 0
_0802A960: .4byte 0x000006DE
_0802A964:
	ldr r1, [r5]
	ldr r2, _0802A9A0 @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A972
	b _0802AAD2
_0802A972:
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	beq _0802A982
	b _0802AAD2
_0802A982:
	movs r4, #0xba
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	ldr r2, _0802A9A4 @ =0x0000016F
	adds r0, r1, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	b _0802AAD2
	.align 2, 0
_0802A9A0: .4byte 0x000006DE
_0802A9A4: .4byte 0x0000016F
_0802A9A8:
	ldr r2, [r5]
	ldr r4, _0802A9D8 @ =0x000006DE
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	beq _0802A9B6
	b _0802AAD2
_0802A9B6:
	movs r0, #0xc2
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x64
	strh r0, [r1]
	movs r3, #0xc3
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r4, _0802A9DC @ =0x00000306
	adds r1, r2, r4
	movs r0, #1
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802A9D8: .4byte 0x000006DE
_0802A9DC: .4byte 0x00000306
_0802A9E0:
	ldr r1, [r5]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0802A9F0
	ldr r0, _0802AA1C @ =0x000006DE
	adds r1, r1, r0
	movs r0, #0x51
	strh r0, [r1]
_0802A9F0:
	ldr r1, [r5]
	ldr r2, _0802AA1C @ =0x000006DE
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r3, [r5]
	ldr r4, _0802AA20 @ =0x000006DC
	adds r0, r3, r4
	ldrb r2, [r0]
	subs r2, #0x17
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #6
	str r0, [r3, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA1C: .4byte 0x000006DE
_0802AA20: .4byte 0x000006DC
_0802AA24:
	ldr r0, [r5]
	ldr r1, _0802AA40 @ =0x000006DE
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, 0x91 @=SE_UNKNOWN_0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0x64
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA40: .4byte 0x000006DE
_0802AA44:
	ldr r0, [r5]
	ldr r2, _0802AA60 @ =0x000006DE
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, 0x91 @=SE_UNKNOWN_0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA60: .4byte 0x000006DE
_0802AA64:
	ldr r0, [r5]
	ldr r3, _0802AA80 @ =0x000006DE
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	movs r0, 0x91 @=SE_UNKNOWN_0x91
	bl m4aSongNumStart
	ldr r1, [r5]
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	b _0802AAD2
	.align 2, 0
_0802AA80: .4byte 0x000006DE
_0802AA84:
	ldr r4, [r5]
	ldr r1, _0802AAB4 @ =0x000006DE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x46
	bne _0802AAD2
	ldr r2, _0802AAB8 @ =0x0000070E
	adds r1, r4, r2
	ldr r3, _0802AABC @ =0x000006DC
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #0xdd
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x63
	ble _0802AAD2
	movs r0, #0x63
	strb r0, [r1]
	b _0802AAD2
	.align 2, 0
_0802AAB4: .4byte 0x000006DE
_0802AAB8: .4byte 0x0000070E
_0802AABC: .4byte 0x000006DC
_0802AAC0:
	ldr r0, [r5]
	ldr r1, _0802AAD8 @ =0x000006DE
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x96
	bne _0802AAD2
	movs r0, #3
	bl sub_19B64
_0802AAD2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AAD8: .4byte 0x000006DE

	