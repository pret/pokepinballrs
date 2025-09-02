#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_162B8
sub_162B8: @ 0x080162B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	movs r7, #0
	movs r6, #0
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08016418 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0801641C @ =0x000005B2
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _080162E8
	b _08016408
_080162E8:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _080162FA
	b _08016408
_080162FA:
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r3, [r4]
	ldrh r1, [r0]
	adds r1, r3, r1
	adds r5, #2
	adds r0, r2, r5
	ldrh r2, [r4, #2]
	ldrh r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r5, r1, #0x10
	lsrs r0, r5, #0x10
	mov r8, r3
	mov sb, r2
	cmp r0, #0x3f
	bhi _08016342
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _08016342
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r5, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	mov r0, ip
	str r0, [sp, #8]
_08016342:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _0801638C
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #1
	str r0, [sp, #8]
_0801638C:
	cmp r6, #0
	bne _080163DA
	mov r1, sl
	ldr r2, [r1]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r1, [r0]
	add r1, r8
	movs r5, #0xc7
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	lsls r1, r4, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080163D6
	ldr r2, _08016420 @ =gUnknown_08252B10
	asrs r0, r1, #0xa
	asrs r1, r3, #0x10
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08016424 @ =0x0000FFF0
	ands r7, r0
	movs r6, #0xf
	ands r6, r0
	movs r0, #2
	str r0, [sp, #8]
_080163D6:
	cmp r6, #0
	beq _08016408
_080163DA:
	mov r1, sl
	ldr r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r3, [sp, #8]
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	ldr r5, [sp]
	strh r7, [r5]
	ldr r0, [sp, #4]
	strb r6, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08016428 @ =0x00000624
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08016408
	movs r0, #2
	strb r0, [r1]
_08016408:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016418: .4byte gCurrentPinballGame
_0801641C: .4byte 0x000005B2
_08016420: .4byte gUnknown_08252B10
_08016424: .4byte 0x0000FFF0
_08016428: .4byte 0x00000624

	thumb_func_start sub_1642C
sub_1642C: @ 0x0801642C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #0xe
	bls _08016446
	bl _080171B8
_08016446:
	lsls r0, r0, #2
	ldr r1, _08016450 @ =_08016454
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016450: .4byte _08016454
_08016454: @ jump table
	.4byte _08016490 @ case 0
	.4byte _080164D8 @ case 1
	.4byte _08016530 @ case 2
	.4byte _08016580 @ case 3
	.4byte _08016794 @ case 4
	.4byte _080167CC @ case 5
	.4byte _0801686C @ case 6
	.4byte _080168B4 @ case 7
	.4byte _08016C28 @ case 8
	.4byte _08016C80 @ case 9
	.4byte _08016E28 @ case 10
	.4byte _08016EA2 @ case 11
	.4byte _08016F08 @ case 12
	.4byte _08017094 @ case 13
	.4byte _0801716C @ case 14
_08016490:
	ldr r0, _080164B4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x26]
	cmp r0, #0
	beq _0801649E
	bl _080171B8
_0801649E:
	ldr r2, _080164B8 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0x28
	ldrsh r0, [r0, r3]
	cmp r0, #0xc7
	ble _080164BC
	adds r1, #0x25
	movs r0, #1
	b _080164C0
	.align 2, 0
_080164B4: .4byte gCurrentPinballGame
_080164B8: .4byte 0x0000132C
_080164BC:
	adds r1, #0x25
	movs r0, #3
_080164C0:
	strb r0, [r1]
	bl sub_32914
	ldr r0, _080164D4 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x22
	movs r1, #7
	strb r1, [r0]
	b _080168A4
	.align 2, 0
_080164D4: .4byte gCurrentPinballGame
_080164D8:
	ldr r3, _080164F0 @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _080164F8
	ldr r4, _080164F4 @ =0x0000132C
	adds r0, r2, r4
	b _0801656C
	.align 2, 0
_080164F0: .4byte gCurrentPinballGame
_080164F4: .4byte 0x0000132C
_080164F8:
	cmp r1, #2
	bne _08016514
	ldr r5, _08016510 @ =0x0000132C
	adds r0, r2, r5
	ldr r0, [r0]
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016510: .4byte 0x0000132C
_08016514:
	cmp r1, #3
	beq _0801651C
	bl _080171B8
_0801651C:
	ldr r1, _0801652C @ =0x0000132C
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #1]
	bl _080171B8
	.align 2, 0
_0801652C: .4byte 0x0000132C
_08016530:
	ldr r3, _08016558 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08016560
	ldr r2, _0801655C @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r2, #0
	movs r0, #3
	strb r0, [r1, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r2, [r0]
	bl _080171B8
	.align 2, 0
_08016558: .4byte gCurrentPinballGame
_0801655C: .4byte 0x0000132C
_08016560:
	cmp r0, #3
	beq _08016568
	bl _080171B8
_08016568:
	ldr r4, _0801657C @ =0x0000132C
	adds r0, r1, r4
_0801656C:
	ldr r0, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	ldr r0, [r3]
	adds r0, #0x24
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801657C: .4byte 0x0000132C
_08016580:
	ldr r5, _080165D4 @ =gCurrentPinballGame
	ldr r3, [r5]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r4, [r0]
	cmp r4, #0
	beq _08016594
	bl _080171B8
_08016594:
	ldr r6, _080165D8 @ =0x0000132C
	adds r0, r3, r6
	ldr r2, [r0]
	movs r0, #0x12
	ldrsh r1, [r2, r0]
	ldr r0, _080165DC @ =0x00000103
	cmp r1, r0
	ble _080165A6
	b _08016718
_080165A6:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x49
	bgt _08016624
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _080165B8
	b _0801676E
_080165B8:
	ldr r2, _080165E0 @ =0x0000036B
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080165C8
	b _0801676E
_080165C8:
	cmp r0, #1
	bne _080165E8
	ldr r4, _080165E4 @ =0x0000036D
	adds r1, r3, r4
	movs r0, #6
	b _080165EE
	.align 2, 0
_080165D4: .4byte gCurrentPinballGame
_080165D8: .4byte 0x0000132C
_080165DC: .4byte 0x00000103
_080165E0: .4byte 0x0000036B
_080165E4: .4byte 0x0000036D
_080165E8:
	ldr r5, _08016614 @ =0x0000036D
	adds r1, r3, r5
	movs r0, #4
_080165EE:
	strb r0, [r1]
	ldr r5, _08016618 @ =gCurrentPinballGame
	ldr r1, [r5]
	movs r0, #0xdc
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, _0801661C @ =0x0000036B
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r3, _08016620 @ =0x0000132C
	adds r4, r1, r3
	b _0801667E
	.align 2, 0
_08016614: .4byte 0x0000036D
_08016618: .4byte gCurrentPinballGame
_0801661C: .4byte 0x0000036B
_08016620: .4byte 0x0000132C
_08016624:
	cmp r0, #0x73
	bgt _080166DC
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	ble _08016632
	b _0801676E
_08016632:
	ldr r5, _08016650 @ =0x0000036A
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08016642
	b _0801676E
_08016642:
	cmp r0, #1
	bne _08016654
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #6
	b _0801665C
	.align 2, 0
_08016650: .4byte 0x0000036A
_08016654:
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #4
_0801665C:
	strb r0, [r1]
	ldr r5, _080166BC @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r3, _080166C0 @ =0x0000036E
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	ldr r4, _080166C4 @ =0x0000036A
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r5]
	ldr r0, _080166C8 @ =0x0000132C
	adds r4, r1, r0
_0801667E:
	ldr r3, [r4]
	movs r2, #0x30
	ldrsh r0, [r3, r2]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x30]
	ldr r3, [r4]
	movs r4, #0x32
	ldrsh r0, [r3, r4]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	strh r0, [r3, #0x32]
	ldr r4, _080166CC @ =0x00001378
	adds r0, r1, r4
	ldr r2, _080166D0 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r0, [r5]
	ldr r3, _080166D4 @ =0x00001330
	adds r1, r0, r3
	adds r4, r0, r4
	str r4, [r1]
	ldr r4, _080166D8 @ =0x00001328
	adds r0, r0, r4
	movs r1, #0x19
	strh r1, [r0]
	b _0801676E
	.align 2, 0
_080166BC: .4byte gCurrentPinballGame
_080166C0: .4byte 0x0000036E
_080166C4: .4byte 0x0000036A
_080166C8: .4byte 0x0000132C
_080166CC: .4byte 0x00001378
_080166D0: .4byte 0x00001334
_080166D4: .4byte 0x00001330
_080166D8: .4byte 0x00001328
_080166DC:
	movs r0, #0xc3
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r2, _0801670C @ =0x00000306
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r3, _08016710 @ =0x0000070E
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x62
	bgt _08016704
	adds r0, r2, #1
	strb r0, [r1]
_08016704:
	ldr r1, [r5]
	ldr r0, _08016714 @ =0x00001388
	str r0, [r1, #0x3c]
	b _0801676E
	.align 2, 0
_0801670C: .4byte 0x00000306
_08016710: .4byte 0x0000070E
_08016714: .4byte 0x00001388
_08016718:
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	cmp r0, #0x6d
	bgt _0801673E
	movs r2, #0xca
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	ldr r2, [r0]
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	b _0801676E
_0801673E:
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r3, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08016752
	movs r0, #1
	strb r0, [r1]
	b _08016754
_08016752:
	strb r4, [r1]
_08016754:
	ldr r0, _08016788 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r1, _0801678C @ =0x0000132C
	adds r0, r3, r1
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2, #0x32]
	ldr r0, _08016790 @ =0x00000BB8
	str r0, [r3, #0x3c]
_0801676E:
	ldr r0, _08016788 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, 0x76 @=SE_UNKNOWN_0x76
	bl m4aSongNumStart
	bl _080171B8
	.align 2, 0
_08016788: .4byte gCurrentPinballGame
_0801678C: .4byte 0x0000132C
_08016790: .4byte 0x00000BB8
_08016794:
	ldr r1, _080167BC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080167C0 @ =0x00000165
	adds r0, r0, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0x20
	strb r2, [r0]
	ldr r0, [r1]
	ldr r4, _080167C4 @ =0x00000732
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r1]
	ldr r5, _080167C8 @ =0x00000342
	adds r0, r0, r5
	strb r3, [r0]
	bl _080171B8
	.align 2, 0
_080167BC: .4byte gCurrentPinballGame
_080167C0: .4byte 0x00000165
_080167C4: .4byte 0x00000732
_080167C8: .4byte 0x00000342
_080167CC:
	ldr r0, _08016850 @ =gCurrentPinballGame
	mov sb, r0
	ldr r1, [r0]
	ldr r2, _08016854 @ =0x0000132C
	mov r8, r2
	adds r0, r1, r2
	ldr r2, [r0]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	cmp r0, #0x77
	bgt _0801685C
	movs r4, #0x32
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bgt _080167EE
	bl _080171B8
_080167EE:
	movs r6, #0xda
	lsls r6, r6, #8
	movs r5, #0x30
	ldrsh r0, [r2, r5]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #0x32
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r7, r1, r0
	lsls r0, r7, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x11
	adds r0, r6, #0
	bl Cos
	mov r5, sb
	ldr r1, [r5]
	add r1, r8
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r7, r0
	ldr r5, _08016858 @ =0x00004E20
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x30]
	adds r0, r6, #0
	bl Sin
	mov r2, sb
	ldr r1, [r2]
	add r1, r8
	ldr r4, [r1]
	rsbs r1, r7, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	strh r0, [r4, #0x32]
	bl _080171B8
	.align 2, 0
_08016850: .4byte gCurrentPinballGame
_08016854: .4byte 0x0000132C
_08016858: .4byte 0x00004E20
_0801685C:
	ldr r3, _08016868 @ =0x00000342
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	bl _080171B8
	.align 2, 0
_08016868: .4byte 0x00000342
_0801686C:
	ldr r4, _080168AC @ =gCurrentPinballGame
	ldr r3, [r4]
	ldr r1, _080168B0 @ =0x00000366
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _08016882
	bl _080171B8
_08016882:
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r2, #0
	movs r0, #0x11
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x23
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, #0x22
	movs r1, #2
	strb r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #8
	adds r0, r3, #0
	strh r0, [r5]
_080168A4:
	movs r0, #1
	strh r0, [r6]
	bl _080171B8
	.align 2, 0
_080168AC: .4byte gCurrentPinballGame
_080168B0: .4byte 0x00000366
_080168B4:
	ldr r1, _0801690C @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r4, _08016910 @ =0x0000132C
	adds r0, r3, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #0
	ble _0801697C
	ldr r5, _08016914 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801695A
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r3, #0xa
	strb r3, [r0]
	ldr r1, [r1]
	ldr r4, _08016918 @ =0x0000072B
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016946
	cmp r0, #0
	bne _0801691C
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801690C: .4byte gCurrentPinballGame
_08016910: .4byte 0x0000132C
_08016914: .4byte 0x00000732
_08016918: .4byte 0x0000072B
_0801691C:
	cmp r0, #1
	bne _08016930
	ldr r0, _0801692C @ =0x00001388
	str r0, [r1, #0x3c]
	adds r1, r1, r2
	movs r0, #5
	strb r0, [r1]
	b _08016938
	.align 2, 0
_0801692C: .4byte 0x00001388
_08016930:
	ldr r0, _0801696C @ =0x00002710
	str r0, [r1, #0x3c]
	adds r0, r1, r2
	strb r3, [r0]
_08016938:
	mov r5, sb
	ldr r1, [r5]
	ldr r0, _08016970 @ =0x0000072B
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08016946:
	mov r1, sb
	ldr r0, [r1]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r2, r0, r3
	movs r1, #0
	strh r1, [r2]
	ldr r4, _08016974 @ =0x0000072C
	adds r0, r0, r4
	strh r1, [r0]
_0801695A:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016978 @ =0x00000732
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_0801696C: .4byte 0x00002710
_08016970: .4byte 0x0000072B
_08016974: .4byte 0x0000072C
_08016978: .4byte 0x00000732
_0801697C:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x48
	bgt _08016A14
	ldr r2, _080169B4 @ =0x00000732
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _080169EE
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _080169E0
	ldr r4, _080169B8 @ =0x0000072E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080169E0
	cmp r0, #0
	bne _080169BC
	movs r0, #0xfa
	lsls r0, r0, #3
	b _080169CA
	.align 2, 0
_080169B4: .4byte 0x00000732
_080169B8: .4byte 0x0000072E
_080169BC:
	cmp r0, #1
	bne _080169C8
	ldr r0, _080169C4 @ =0x00001388
	b _080169CA
	.align 2, 0
_080169C4: .4byte 0x00001388
_080169C8:
	ldr r0, _08016A00 @ =0x00002710
_080169CA:
	str r0, [r3, #0x3c]
	ldr r0, _08016A04 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _08016A08 @ =0x0000072E
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, 0x99 @=SE_UNKNOWN_0x99
	bl m4aSongNumStart
_080169E0:
	ldr r0, _08016A04 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08016A0C @ =0x000006BC
	adds r1, r1, r2
	movs r2, #1
	strb r2, [r1]
	mov sb, r0
_080169EE:
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A10 @ =0x00000732
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	bl _080171B8
	.align 2, 0
_08016A00: .4byte 0x00002710
_08016A04: .4byte gCurrentPinballGame
_08016A08: .4byte 0x0000072E
_08016A0C: .4byte 0x000006BC
_08016A10: .4byte 0x00000732
_08016A14:
	cmp r0, #0x62
	bgt _08016A88
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016A2E
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016A2E:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016A78 @ =0x00000732
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016A7C @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016A52
	b _080171B8
_08016A52:
	ldr r5, _08016A80 @ =0x00000719
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016A66
	b _080171B8
_08016A66:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016A84 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016A78: .4byte 0x00000732
_08016A7C: .4byte 0x0000071B
_08016A80: .4byte 0x00000719
_08016A84: .4byte 0x0000071C
_08016A88:
	cmp r0, #0x76
	bgt _08016AFC
	ldr r1, _08016AEC @ =0x00000719
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016AA0
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016AA0:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016AF0 @ =0x00000732
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016AF4 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016AC4
	b _080171B8
_08016AC4:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016ADA
	b _080171B8
_08016ADA:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016AF8 @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016AEC: .4byte 0x00000719
_08016AF0: .4byte 0x00000732
_08016AF4: .4byte 0x0000071B
_08016AF8: .4byte 0x0000071C
_08016AFC:
	cmp r0, #0x92
	bgt _08016B70
	ldr r1, _08016B60 @ =0x0000071A
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08016B14
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r3, #0x3c]
_08016B14:
	mov r5, sb
	ldr r0, [r5]
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r1, _08016B64 @ =0x00000732
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, _08016B68 @ =0x0000071B
	adds r3, r1, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08016B38
	b _080171B8
_08016B38:
	movs r5, #0xe3
	lsls r5, r5, #3
	adds r0, r1, r5
	subs r2, #2
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	cmp r0, #0
	bne _08016B4E
	b _080171B8
_08016B4E:
	strb r4, [r3]
	mov r3, sb
	ldr r0, [r3]
	ldr r4, _08016B6C @ =0x0000071C
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r1, [r3]
	b _08016E0A
	.align 2, 0
_08016B60: .4byte 0x0000071A
_08016B64: .4byte 0x00000732
_08016B68: .4byte 0x0000071B
_08016B6C: .4byte 0x0000071C
_08016B70:
	ldr r5, _08016BA0 @ =0x00000732
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _08016C00
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	cmp r0, #2
	bgt _08016BF4
	ldr r1, _08016BA4 @ =0x0000072F
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08016BF4
	cmp r0, #0
	bne _08016BA8
	movs r0, #0xfa
	lsls r0, r0, #3
	b _08016BB6
	.align 2, 0
_08016BA0: .4byte 0x00000732
_08016BA4: .4byte 0x0000072F
_08016BA8:
	cmp r0, #1
	bne _08016BB4
	ldr r0, _08016BB0 @ =0x00001388
	b _08016BB6
	.align 2, 0
_08016BB0: .4byte 0x00001388
_08016BB4:
	ldr r0, _08016C10 @ =0x00002710
_08016BB6:
	str r0, [r3, #0x3c]
	ldr r4, _08016C14 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r5, _08016C18 @ =0x0000072F
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xd
	bne _08016BDC
	movs r0, 0x99 @=SE_UNKNOWN_0x99
	bl m4aSongNumStart
_08016BDC:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r4
	cmp r0, #1
	ble _08016BF4
	ldr r4, _08016C1C @ =0x00000731
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
_08016BF4:
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _08016C20 @ =0x000006BC
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
_08016C00:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _08016C24 @ =0x00000732
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	b _080171B8
	.align 2, 0
_08016C10: .4byte 0x00002710
_08016C14: .4byte gCurrentPinballGame
_08016C18: .4byte 0x0000072F
_08016C1C: .4byte 0x00000731
_08016C20: .4byte 0x000006BC
_08016C24: .4byte 0x00000732
_08016C28:
	ldr r0, _08016C4C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r4, _08016C50 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	ldrh r4, [r0, #0x10]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08016C58
	ldr r5, _08016C54 @ =0x00000732
	adds r1, r1, r5
	movs r0, #7
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C4C: .4byte gCurrentPinballGame
_08016C50: .4byte 0x0000132C
_08016C54: .4byte 0x00000732
_08016C58:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	bgt _08016C70
	ldr r0, _08016C6C @ =0x00000732
	adds r1, r1, r0
	movs r0, #8
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C6C: .4byte 0x00000732
_08016C70:
	ldr r2, _08016C7C @ =0x00000732
	adds r1, r1, r2
	movs r0, #9
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08016C7C: .4byte 0x00000732
_08016C80:
	ldr r4, _08016CD8 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r3, _08016CDC @ =0x0000132C
	adds r0, r1, r3
	ldr r0, [r0]
	movs r5, #0x10
	ldrsh r0, [r0, r5]
	cmp r0, #0x2e
	bgt _08016CF4
	ldr r2, _08016CE0 @ =0x00000732
	adds r0, r1, r2
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, [r4]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016CAC
	b _080171B8
_08016CAC:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r0, _08016CE4 @ =0x00000714
	adds r5, r3, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016CC6
	b _080171B8
_08016CC6:
	ldr r1, _08016CE8 @ =0x00000711
	adds r0, r3, r1
	ldr r2, _08016CEC @ =0x00000712
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016CF0 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016CD8: .4byte gCurrentPinballGame
_08016CDC: .4byte 0x0000132C
_08016CE0: .4byte 0x00000732
_08016CE4: .4byte 0x00000714
_08016CE8: .4byte 0x00000711
_08016CEC: .4byte 0x00000712
_08016CF0: .4byte 0x00000713
_08016CF4:
	cmp r0, #0x78
	bgt _08016D50
	ldr r5, _08016D40 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xb
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016D44 @ =0x00000711
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D10
	b _080171B8
_08016D10:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016D48 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D2A
	b _080171B8
_08016D2A:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #2
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016D4C @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D40: .4byte 0x00000732
_08016D44: .4byte 0x00000711
_08016D48: .4byte 0x00000714
_08016D4C: .4byte 0x00000713
_08016D50:
	cmp r0, #0xc1
	bgt _08016DAC
	ldr r5, _08016D9C @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016DA0 @ =0x00000712
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016D6C
	b _080171B8
_08016D6C:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016DA4 @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016D86
	b _080171B8
_08016D86:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016DA8 @ =0x00000713
	b _08016DF0
	.align 2, 0
_08016D9C: .4byte 0x00000732
_08016DA0: .4byte 0x00000712
_08016DA4: .4byte 0x00000714
_08016DA8: .4byte 0x00000713
_08016DAC:
	ldr r5, _08016E14 @ =0x00000732
	adds r0, r1, r5
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _08016E18 @ =0x00000713
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08016DC4
	b _080171B8
_08016DC4:
	movs r0, #0xfa
	lsls r0, r0, #2
	str r0, [r1, #0x3c]
	movs r6, #1
	strb r6, [r2]
	ldr r3, [r4]
	ldr r1, _08016E1C @ =0x00000714
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08016DDE
	b _080171B8
_08016DDE:
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r2, #1
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	ands r0, r2
	ldr r2, _08016E20 @ =0x00000712
_08016DF0:
	adds r1, r3, r2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08016DFC
	b _080171B8
_08016DFC:
	strb r6, [r5]
	ldr r0, [r4]
	ldr r3, _08016E24 @ =0x00000715
	adds r0, r0, r3
	movs r1, #0x7e
	strb r1, [r0]
	ldr r1, [r4]
_08016E0A:
	movs r0, #0xfa
	lsls r0, r0, #4
	str r0, [r1, #0x3c]
	b _080171B8
	.align 2, 0
_08016E14: .4byte 0x00000732
_08016E18: .4byte 0x00000713
_08016E1C: .4byte 0x00000714
_08016E20: .4byte 0x00000712
_08016E24: .4byte 0x00000715
_08016E28:
	ldr r0, _08016E54 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r1, [r1]
	mov sb, r0
	cmp r1, #0
	beq _08016E3C
	b _080171B8
_08016E3C:
	ldr r5, _08016E58 @ =0x0000132C
	adds r0, r3, r5
	ldr r0, [r0]
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _08016E5C
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r3, r2
	movs r0, #1
	b _08016E64
	.align 2, 0
_08016E54: .4byte gCurrentPinballGame
_08016E58: .4byte 0x0000132C
_08016E5C:
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #2
_08016E64:
	strb r0, [r1]
	mov r5, sb
	ldr r2, [r5]
	movs r0, #0xf1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08016E96
	adds r1, r0, #0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	beq _08016E8E
	b _080171B8
_08016E8E:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r1, r2, r4
	b _08016E9C
_08016E96:
	movs r5, #0xe2
	lsls r5, r5, #1
	adds r1, r2, r5
_08016E9C:
	movs r0, #0x78
	strh r0, [r1]
	b _080171B8
_08016EA2:
	ldr r6, _08016EF8 @ =gCurrentPinballGame
	ldr r1, [r6]
	ldr r5, _08016EFC @ =0x00000616
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08016EB2
	b _080171B8
_08016EB2:
	ldr r2, _08016F00 @ =0x0000132C
	adds r0, r1, r2
	ldr r0, [r0]
	ldrh r2, [r0, #0x32]
	ldr r3, _08016F04 @ =0x00000614
	adds r0, r1, r3
	strh r2, [r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08016ECE
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_08016ECE:
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r4, r1, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa8
	ble _08016EF0
	movs r0, #0xa8
	strh r0, [r4]
_08016EF0:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x14
	b _080171B6
	.align 2, 0
_08016EF8: .4byte gCurrentPinballGame
_08016EFC: .4byte 0x00000616
_08016F00: .4byte 0x0000132C
_08016F04: .4byte 0x00000614
_08016F08:
	ldr r5, _08017058 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _0801705C @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xe
	bne _08016F1A
	b _080171B8
_08016F1A:
	movs r0, #0xe
	strb r0, [r1]
	ldr r3, _08017060 @ =gUnknown_086ACE70
	ldr r1, [r5]
	ldr r2, _08017064 @ =0x0000034A
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r3, [r0]
	mov r8, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r3, _08017068 @ =0x0000034B
	adds r1, r1, r3
	adds r1, r1, r0
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r5]
	adds r2, r1, r2
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #3
	bne _08016F88
	ldr r4, _0801706C @ =0x00001378
	adds r0, r1, r4
	ldr r2, _08017070 @ =0x00001334
	adds r1, r1, r2
	movs r2, #0x44
	bl memcpy
	ldr r1, [r5]
	ldr r3, _08017074 @ =0x00001330
	adds r0, r1, r3
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, _08017078 @ =0x00000342
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08016F88
	movs r5, #0xd1
	lsls r5, r5, #2
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1]
_08016F88:
	ldr r0, _08017058 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r6, _08017064 @ =0x0000034A
	adds r1, r3, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r1, #0xb
	bne _08016FA6
	ldr r0, _08017074 @ =0x00001330
	adds r1, r3, r0
	ldr r2, _08017070 @ =0x00001334
	adds r0, r3, r2
	str r0, [r1]
_08016FA6:
	mov r3, sb
	ldr r5, [r3]
	adds r0, r5, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _08016FBA
	adds r3, r1, #2
_08016FBA:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _0801707C @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r7, #0
	movs r4, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _08017080 @ =0x00000355
	adds r0, r5, r1
	adds r0, r0, r3
	strb r7, [r0]
	mov r5, sb
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r5, _08017084 @ =0x0000035E
	adds r0, r2, r5
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, _08017088 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xc
	ble _0801700E
	strb r7, [r1]
_0801700E:
	mov r2, r8
	lsls r0, r2, #0x10
	adds r3, r0, #0
	cmp r3, #0
	bne _08017030
	mov r4, sb
	ldr r0, [r4]
	ldr r5, _0801708C @ =0x0000132C
	adds r0, r0, r5
	ldr r2, [r0]
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08017030
	strh r1, [r2, #0x32]
_08017030:
	asrs r0, r3, #0x10
	cmp r0, #2
	beq _08017038
	b _080171B8
_08017038:
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _0801708C @ =0x0000132C
	adds r0, r0, r3
	ldr r2, [r0]
	movs r4, #0x32
	ldrsh r1, [r2, r4]
	movs r0, #0xb4
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08017050
	b _080171B8
_08017050:
	ldr r0, _08017090 @ =0x0000FF4C
	strh r0, [r2, #0x32]
	b _080171B8
	.align 2, 0
_08017058: .4byte gCurrentPinballGame
_0801705C: .4byte 0x00000732
_08017060: .4byte gUnknown_086ACE70
_08017064: .4byte 0x0000034A
_08017068: .4byte 0x0000034B
_0801706C: .4byte 0x00001378
_08017070: .4byte 0x00001334
_08017074: .4byte 0x00001330
_08017078: .4byte 0x00000342
_0801707C: .4byte gMain
_08017080: .4byte 0x00000355
_08017084: .4byte 0x0000035E
_08017088: .4byte 0x00000359
_0801708C: .4byte 0x0000132C
_08017090: .4byte 0x0000FF4C
_08017094:
	ldr r5, _08017144 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _08017148 @ =0x00000732
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xf
	bne _080170A6
	b _080171B8
_080170A6:
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _0801714C @ =gUnknown_086ACE70
	ldr r1, [r5]
	ldr r6, _08017150 @ =0x0000034A
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r7, [r0, r3]
	ldr r4, _08017154 @ =0x0000034B
	adds r1, r1, r4
	adds r1, r1, r7
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r5]
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, [r5]
	adds r0, r4, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #1
	adds r3, r0, #0
	cmp r0, #0
	bge _080170E6
	adds r3, r1, #2
_080170E6:
	asrs r3, r3, #2
	lsls r3, r3, #2
	ldr r2, _08017158 @ =gMain
	subs r3, r0, r3
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	ldr r1, _0801715C @ =0x00000355
	adds r0, r4, r1
	adds r0, r0, r3
	strb r2, [r0]
	ldr r2, [r5]
	lsls r1, r3, #1
	ldr r4, _08017160 @ =0x0000035E
	adds r0, r2, r4
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08017164 @ =0x00000359
	adds r1, r2, r0
	adds r1, r1, r3
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r1]
	cmp r7, #1
	bne _080171B8
	ldr r0, [r5]
	ldr r1, _08017168 @ =0x0000132C
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	movs r3, #0x96
	rsbs r3, r3, #0
	cmp r0, r3
	ble _080171B8
	strh r3, [r1, #0x32]
	b _080171B8
	.align 2, 0
_08017144: .4byte gCurrentPinballGame
_08017148: .4byte 0x00000732
_0801714C: .4byte gUnknown_086ACE70
_08017150: .4byte 0x0000034A
_08017154: .4byte 0x0000034B
_08017158: .4byte gMain
_0801715C: .4byte 0x00000355
_08017160: .4byte 0x0000035E
_08017164: .4byte 0x00000359
_08017168: .4byte 0x0000132C
_0801716C:
	ldr r3, _08017190 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _08017194 @ =0x0000132C
	adds r0, r1, r4
	ldr r0, [r0]
	movs r5, #0x12
	ldrsh r0, [r0, r5]
	cmp r0, #0x4f
	bgt _0801719C
	ldr r0, _08017198 @ =0x00000306
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _080171B8
	movs r0, #2
	strb r0, [r1]
	b _080171B8
	.align 2, 0
_08017190: .4byte gCurrentPinballGame
_08017194: .4byte 0x0000132C
_08017198: .4byte 0x00000306
_0801719C:
	ldr r4, _080171C4 @ =0x00000306
	adds r2, r1, r4
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _080171B8
	movs r1, #0
	movs r0, #3
	strb r0, [r2]
	ldr r0, [r3]
	movs r5, #0xc3
	lsls r5, r5, #2
	adds r0, r0, r5
_080171B6:
	strh r1, [r0]
_080171B8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080171C4: .4byte 0x00000306
