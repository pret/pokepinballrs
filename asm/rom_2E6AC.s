#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_2FCD0
sub_2FCD0: @ 0x0802FCD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _0802FDCC @ =gMain+0x2ED0 @gMain.spriteGroups[61]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802FCE4
	b _080300B2
_0802FCE4:
	ldr r3, _0802FDD0 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x44
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r4, _0802FDD4 @ =gUnknown_086AE4FC
	ldr r0, [r3]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, _0802FDD8 @ =0x040000D4
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0802FDDC @ =gUnknown_0847A40C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FDE0 @ =0x06012DA0
	str r0, [r2, #4]
	ldr r0, _0802FDE4 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	mov ip, r3
	ldr r1, _0802FDE8 @ =gOamBuffer
	mov sb, r1
	ldr r2, _0802FDEC @ =0xFFFFFDD8
	adds r2, r2, r6
	mov sl, r2
	mov r7, sb
	ldr r3, _0802FDF0 @ =0xFFFFFE00
	mov r8, r3
_0802FD42:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802FDF4 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0802FD42
	mov r6, sl
	mov r3, ip
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x44
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r3]
	ldr r5, _0802FDF8 @ =0x00000372
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _0802FE08
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802FDD8 @ =0x040000D4
	lsrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0802FDFC @ =gUnknown_0847D10C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FE00 @ =0x06014720
	str r0, [r2, #4]
	ldr r0, _0802FE04 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802FE0C
	.align 2, 0
_0802FDCC: .4byte gMain+0x2ED0 @gMain.spriteGroups[61]
_0802FDD0: .4byte gCurrentPinballGame
_0802FDD4: .4byte gUnknown_086AE4FC
_0802FDD8: .4byte 0x040000D4
_0802FDDC: .4byte gUnknown_0847A40C
_0802FDE0: .4byte 0x06012DA0
_0802FDE4: .4byte 0x80000140
_0802FDE8: .4byte gOamBuffer
_0802FDEC: .4byte 0xFFFFFDD8
_0802FDF0: .4byte 0xFFFFFE00
_0802FDF4: .4byte 0x000001FF
_0802FDF8: .4byte 0x00000372
_0802FDFC: .4byte gUnknown_0847D10C
_0802FE00: .4byte 0x06014720
_0802FE04: .4byte 0x800000C0
_0802FE08:
	movs r0, #0xc8
	strh r0, [r6, #4]
_0802FE0C:
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802FF1C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r4, _0802FF20 @ =0xFFFFFE00
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r6, _0802FF24 @ =gMain+0x2F88 @gMain.spriteGroups[62]
	mov r5, ip
	ldr r0, [r5]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x24
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r5]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xa3
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r5]
	ldr r1, _0802FF28 @ =0x0000036D
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r2, _0802FF2C @ =gUnknown_086AE4FC
	adds r0, r0, r2
	ldr r2, _0802FF30 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r5, _0802FF34 @ =gUnknown_084C1E6C
	adds r0, r0, r5
	str r0, [r2]
	ldr r0, _0802FF38 @ =0x060130A0
	str r0, [r2, #4]
	ldr r0, _0802FF3C @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	mov r7, sb
	mov r8, r4
_0802FE90:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802FF1C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0802FE90
	ldr r6, _0802FF40 @ =gMain+0x2D60 @gMain.spriteGroups[59]
	mov r3, ip
	ldr r0, [r3]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x24
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r1, [r3]
	movs r5, #0xdd
	lsls r5, r5, #2
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _0802FF50
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xa3
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r2, _0802FF30 @ =0x040000D4
	lsrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0802FF44 @ =gUnknown_084C4B6C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802FF48 @ =0x06014920
	str r0, [r2, #4]
	ldr r0, _0802FF4C @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802FF54
	.align 2, 0
_0802FF1C: .4byte 0x000001FF
_0802FF20: .4byte 0xFFFFFE00
_0802FF24: .4byte gMain+0x2F88 @gMain.spriteGroups[62]
_0802FF28: .4byte 0x0000036D
_0802FF2C: .4byte gUnknown_086AE4FC
_0802FF30: .4byte 0x040000D4
_0802FF34: .4byte gUnknown_084C1E6C
_0802FF38: .4byte 0x060130A0
_0802FF3C: .4byte 0x80000140
_0802FF40: .4byte gMain+0x2D60 @gMain.spriteGroups[59]
_0802FF44: .4byte gUnknown_084C4B6C
_0802FF48: .4byte 0x06014920
_0802FF4C: .4byte 0x800000C0
_0802FF50:
	movs r0, #0xc8
	strh r0, [r6, #4]
_0802FF54:
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802FFBC @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802FFC0 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	ldr r6, _0802FFC4 @ =gMain+0x3998 @gMain.spriteGroups[76]
	mov r5, ip
	ldr r0, [r5]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x3d
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r5]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xba
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, [r5]
	ldr r2, _0802FFC8 @ =0x00000367
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802FFD0
	ldr r3, _0802FFCC @ =0x00000366
	adds r1, r1, r3
	movs r0, #3
	b _08030032
	.align 2, 0
_0802FFBC: .4byte 0x000001FF
_0802FFC0: .4byte 0xFFFFFE00
_0802FFC4: .4byte gMain+0x3998 @gMain.spriteGroups[76]
_0802FFC8: .4byte 0x00000367
_0802FFCC: .4byte 0x00000366
_0802FFD0:
	ldr r5, _0802FFF4 @ =0x0000036A
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803000C
	ldr r2, _0802FFF8 @ =0x0000036B
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08030000
	ldr r3, _0802FFFC @ =0x00000366
	adds r1, r1, r3
	movs r0, #3
	b _08030032
	.align 2, 0
_0802FFF4: .4byte 0x0000036A
_0802FFF8: .4byte 0x0000036B
_0802FFFC: .4byte 0x00000366
_08030000:
	ldr r5, _08030008 @ =0x00000366
	adds r1, r1, r5
	movs r0, #2
	b _08030032
	.align 2, 0
_08030008: .4byte 0x00000366
_0803000C:
	ldr r2, _08030024 @ =0x0000036B
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803002C
	ldr r3, _08030028 @ =0x00000366
	adds r1, r1, r3
	movs r0, #1
	b _08030032
	.align 2, 0
_08030024: .4byte 0x0000036B
_08030028: .4byte 0x00000366
_0803002C:
	ldr r5, _08030064 @ =0x00000366
	adds r1, r1, r5
	movs r0, #0
_08030032:
	strb r0, [r1]
	mov r0, ip
	ldr r3, [r0]
	ldr r2, _08030064 @ =0x00000366
	adds r1, r3, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08030068
	lsls r4, r0, #1
	adds r4, r4, r0
	movs r5, #0xa4
	lsls r5, r5, #2
	adds r0, r3, r5
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	b _0803006A
	.align 2, 0
_08030064: .4byte 0x00000366
_08030068:
	movs r0, #9
_0803006A:
	ldr r1, _080300C0 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #9
	ldr r2, _080300C4 @ =gUnknown_084FEA0C
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _080300C8 @ =0x060146A0
	str r0, [r1, #4]
	ldr r0, _080300CC @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r6, #0
	adds r5, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	add r2, sb
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _080300D0 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080300D4 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_080300B2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080300C0: .4byte 0x040000D4
_080300C4: .4byte gUnknown_084FEA0C
_080300C8: .4byte 0x060146A0
_080300CC: .4byte 0x80000040
_080300D0: .4byte 0x000001FF
_080300D4: .4byte 0xFFFFFE00

	thumb_func_start sub_300D8
sub_300D8: @ 0x080300D8
	push {r4, r5, lr}
	ldr r0, _08030170 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xe6
	lsls r0, r0, #2
	strh r0, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0x85
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08030174 @ =0x000004EC
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0xa
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0x83
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x87
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x14
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0x1e
	bl __udivsi3
	movs r1, #0xa1
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030170: .4byte gCurrentPinballGame
_08030174: .4byte 0x000004EC

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
	