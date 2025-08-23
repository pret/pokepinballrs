#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_30178
sub_30178: @ 0x08030178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080301DC @ =gMain+0x3040 @gMain.spriteGroups[63]
	mov sl, r0
	ldr r1, _080301E0 @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r2, _080301E4 @ =0x00000624
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0803019A
	b _080302D4
_0803019A:
	cmp r0, #2
	beq _080301A0
	b _080302C6
_080301A0:
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r3, #0x3c]
	movs r0, 0xB6 @=SE_UNKNOWN_0xB6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r3, _080301E0 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0803029C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _0803029C
	ldr r6, _080301E8 @ =0x00000625
	adds r1, r1, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0803029C
	cmp r0, #0
	bne _080301EC
	movs r0, #1
	b _080301F6
	.align 2, 0
_080301DC: .4byte gMain+0x3040 @gMain.spriteGroups[63]
_080301E0: .4byte gCurrentPinballGame
_080301E4: .4byte 0x00000624
_080301E8: .4byte 0x00000625
_080301EC:
	cmp r0, #1
	bne _080301F4
	movs r0, #3
	b _080301F6
_080301F4:
	movs r0, #6
_080301F6:
	strb r0, [r1]
	ldr r7, _08030318 @ =gCurrentPinballGame
	ldr r5, [r7]
	ldr r1, _0803031C @ =0x00000625
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0803029C
	ldr r2, _08030320 @ =0x000006C6
	adds r0, r5, r2
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #0
	bne _0803029C
	ldr r2, _08030324 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2, #0xf]
	adds r0, r5, #0
	adds r0, #0xea
	movs r4, #0
	movs r3, #0x32
	strh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xec
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	subs r1, #4
	movs r0, #0xec
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xe6
	strh r6, [r0]
	adds r1, #6
	movs r0, #4
	strh r0, [r1]
	adds r1, #4
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r7]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08030328 @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r6, [r0]
	ldr r1, _0803032C @ =0x040000D4
	ldr r0, _08030330 @ =gUnknown_086ACEF8
	ldr r0, [r0, #0x1c]
	str r0, [r1]
	ldr r0, _08030334 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08030338 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0803033C @ =gUnknown_086ACF18
	ldr r0, [r0, #0x1c]
	str r0, [r1]
	ldr r0, _08030340 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08030344 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_0803029C:
	ldr r2, _08030318 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xbb
	lsls r3, r3, #1
	adds r1, r0, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, [r2]
	movs r6, #0xc2
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bne _080302C6
	ldr r0, _08030348 @ =0x0000C350
	str r0, [r3, #0x3c]
_080302C6:
	ldr r0, _08030318 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803034C @ =0x00000624
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080302D4:
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	bne _080302DE
	b _08030456
_080302DE:
	movs r0, #0
	ldr r6, _0803032C @ =0x040000D4
	mov sb, r6
_080302E4:
	ldr r1, _08030318 @ =gCurrentPinballGame
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r1, r4, r3
	adds r3, r1, r2
	ldrb r6, [r3]
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r5, r0, #0
	cmp r1, #0
	ble _08030350
	adds r0, r1, #0
	cmp r0, #0
	bge _08030308
	adds r0, #3
_08030308:
	asrs r0, r0, #2
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	subs r0, r6, #1
	strb r0, [r3]
	b _08030370
	.align 2, 0
_08030318: .4byte gCurrentPinballGame
_0803031C: .4byte 0x00000625
_08030320: .4byte 0x000006C6
_08030324: .4byte gMain
_08030328: .4byte 0x0000F63C
_0803032C: .4byte 0x040000D4
_08030330: .4byte gUnknown_086ACEF8
_08030334: .4byte 0x06015800
_08030338: .4byte 0x80001200
_0803033C: .4byte gUnknown_086ACF18
_08030340: .4byte 0x050003C0
_08030344: .4byte 0x80000010
_08030348: .4byte 0x0000C350
_0803034C: .4byte 0x00000624
_08030350:
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r4, r6
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_08030370:
	lsls r0, r1, #0x10
	asrs r0, r0, #7
	ldr r1, _08030464 @ =gUnknown_0845690C
	adds r0, r0, r1
	mov r2, sb
	str r0, [r2]
	asrs r5, r5, #0x10
	lsls r0, r5, #9
	ldr r3, _08030468 @ =0x060133A0
	adds r0, r0, r3
	str r0, [r2, #4]
	ldr r0, _0803046C @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r6, _08030470 @ =gCurrentPinballGame
	ldr r4, [r6]
	lsls r0, r5, #2
	adds r7, r4, r0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r6, r7, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	mov r2, sl
	strh r0, [r2, #2]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r0, #0xa
	mov r2, sl
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #8
	lsls r0, r0, #1
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #3
	lsls r0, r0, #1
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	lsls r3, r5, #3
	adds r3, #8
	add r3, sl
	ldrh r4, [r3]
	lsls r4, r4, #3
	ldr r6, _08030474 @ =gOamBuffer
	adds r4, r4, r6
	movs r0, #2
	ldrsh r2, [r3, r0]
	mov r1, sl
	movs r6, #2
	ldrsh r0, [r1, r6]
	adds r2, r2, r0
	ldr r1, _08030478 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r0, [r4, #2]
	ldr r6, _0803047C @ =0xFFFFFE00
	adds r1, r6, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	ldr r0, _08030474 @ =gOamBuffer
	adds r1, r1, r0
	mov r2, sl
	ldrb r0, [r2, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	bgt _08030456
	b _080302E4
_08030456:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030464: .4byte gUnknown_0845690C
_08030468: .4byte 0x060133A0
_0803046C: .4byte 0x80000100
_08030470: .4byte gCurrentPinballGame
_08030474: .4byte gOamBuffer
_08030478: .4byte 0x000001FF
_0803047C: .4byte 0xFFFFFE00
	