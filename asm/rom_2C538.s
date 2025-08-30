#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_2C538
sub_2C538: @ 0x0802C538
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov sb, r0
	ldr r1, _0802C568 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #5
	bls _0802C55C
	b _0802C784
_0802C55C:
	lsls r0, r0, #2
	ldr r1, _0802C56C @ =_0802C570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C568: .4byte gCurrentPinballGame
_0802C56C: .4byte _0802C570
_0802C570: @ jump table
	.4byte _0802C588 @ case 0
	.4byte _0802C5BC @ case 1
	.4byte _0802C614 @ case 2
	.4byte _0802C650 @ case 3
	.4byte _0802C6C0 @ case 4
	.4byte _0802C708 @ case 5
_0802C588:
	ldr r5, [r7]
	movs r3, #0xc1
	lsls r3, r3, #2
	adds r6, r5, r3
	ldrh r4, [r6]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r0, #0
	strh r4, [r6]
	ldr r1, _0802C5B8 @ =0x00000301
	adds r5, r5, r1
	strb r0, [r5]
	b _0802C784
	.align 2, 0
_0802C5B8: .4byte 0x00000301
_0802C5BC:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	ldr r2, _0802C610 @ =0x00000301
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C608
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
_0802C608:
	ldr r0, [r7]
	adds r0, r0, r2
	b _0802C780
	.align 2, 0
_0802C610: .4byte 0x00000301
_0802C614:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __udivsi3
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #9
	beq _0802C646
	b _0802C784
_0802C646:
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #3
	b _0802C6F8
_0802C650:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	mov r8, r2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r2, #0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x41
	bls _0802C698
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
_0802C698:
	ldr r1, [r7]
	mov r3, r8
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #6
	bls _0802C784
	ldr r3, _0802C6BC @ =0x00000301
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C784
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #4
	b _0802C772
	.align 2, 0
_0802C6BC: .4byte 0x00000301
_0802C6C0:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __udivsi3
	adds r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #9
	bne _0802C784
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #5
_0802C6F8:
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	b _0802C784
_0802C708:
	ldr r6, [r7]
	movs r2, #0xc1
	lsls r2, r2, #2
	mov r8, r2
	adds r5, r6, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x12
	bl __udivsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r4, #1
	movs r2, #0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #0x41
	bls _0802C750
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
_0802C750:
	ldr r1, [r7]
	mov r3, r8
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #6
	bls _0802C784
	ldr r3, _0802C7B8 @ =0x00000301
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0802C784
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #2
_0802C772:
	strb r0, [r1]
	ldr r0, [r7]
	mov r3, r8
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _0802C7B8 @ =0x00000301
	adds r0, r0, r1
_0802C780:
	movs r1, #0
	strb r1, [r0]
_0802C784:
	ldr r6, _0802C7BC @ =gMain+0x33D8 @gMain.spriteGroups[68]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802C83C
	ldr r1, [r7]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0802C7C4
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xbc
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r3, _0802C7C0 @ =0x00000119
	adds r0, r3, #0
	b _0802C7DC
	.align 2, 0
_0802C7B8: .4byte 0x00000301
_0802C7BC: .4byte gMain+0x33D8 @gMain.spriteGroups[68]
_0802C7C0: .4byte 0x00000119
_0802C7C4:
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xc0
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r2, #0
_0802C7DC:
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r7]
	ldr r3, _0802C95C @ =0x00000302
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0802C808
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0802C808
	ldr r0, _0802C960 @ =gMain
	ldr r2, _0802C964 @ =0x000033D8
	adds r0, r0, r2
	strh r1, [r0]
_0802C808:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802C968 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802C96C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802C970 @ =0xFFFFFE00
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
_0802C83C:
	ldr r2, [r7]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802C852
	cmp r0, #2
	bne _0802C8C0
_0802C852:
	ldr r4, _0802C974 @ =0x0000132C
	adds r0, r2, r4
	ldr r0, [r0]
	movs r3, #0x10
	ldrsh r1, [r0, r3]
	subs r1, #0xbe
	movs r3, #0x12
	ldrsh r0, [r0, r3]
	ldr r3, _0802C978 @ =0xFFFFFEE3
	adds r0, r0, r3
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0x8c
	bhi _0802C8C0
	ldr r1, _0802C95C @ =0x00000302
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0802C8C0
	movs r0, 0xC5 @=SE_UNKNOWN_0xC5
	bl m4aSongNumStart
	ldr r1, [r7]
	ldr r0, _0802C97C @ =0x00002710
	str r0, [r1, #0x3c]
	adds r1, r1, r4
	ldr r2, [r1]
	movs r3, #0
	ldr r0, _0802C980 @ =0x0000FDA8
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldr r0, _0802C984 @ =0x0000FED4
	strh r0, [r2, #0x32]
	ldr r0, [r1]
	strh r3, [r0, #6]
	ldr r0, _0802C960 @ =gMain
	ldr r2, _0802C964 @ =0x000033D8
	adds r0, r0, r2
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r7]
	ldr r3, _0802C95C @ =0x00000302
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	movs r0, #8
	bl sub_11B0
_0802C8C0:
	ldr r6, _0802C988 @ =gMain+0x2CA8 @gMain.spriteGroups[58]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802C94E
	ldr r2, _0802C98C @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb8
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	ldr r2, _0802C990 @ =0x00000115
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _0802C994 @ =0x040000D4
	mov r3, sb
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0802C998 @ =gUnknown_0847DF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802C99C @ =0x06013580
	str r0, [r2, #4]
	ldr r0, _0802C9A0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r7, _0802C968 @ =gOamBuffer
	ldr r1, _0802C970 @ =0xFFFFFE00
	mov r8, r1
_0802C90A:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802C96C @ =0x000001FF
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
	cmp r4, #2
	ble _0802C90A
_0802C94E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C95C: .4byte 0x00000302
_0802C960: .4byte gMain
_0802C964: .4byte 0x000033D8
_0802C968: .4byte gOamBuffer
_0802C96C: .4byte 0x000001FF
_0802C970: .4byte 0xFFFFFE00
_0802C974: .4byte 0x0000132C
_0802C978: .4byte 0xFFFFFEE3
_0802C97C: .4byte 0x00002710
_0802C980: .4byte 0x0000FDA8
_0802C984: .4byte 0x0000FED4
_0802C988: .4byte gMain+0x2CA8 @gMain.spriteGroups[58]
_0802C98C: .4byte gCurrentPinballGame
_0802C990: .4byte 0x00000115
_0802C994: .4byte 0x040000D4
_0802C998: .4byte gUnknown_0847DF0C
_0802C99C: .4byte 0x06013580
_0802C9A0: .4byte 0x80000180

	thumb_func_start sub_2C9A4
sub_2C9A4: @ 0x0802C9A4
	push {r4, r5, r6, lr}
	ldr r6, _0802C9E0 @ =gMain+0x3268 @gMain.spriteGroups[66]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802CA7A
	ldr r0, _0802C9E4 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0802C9E8 @ =0x0000029F
	adds r1, r2, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r1, #0
	beq _0802C9EC
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	lsrs r1, r1, #3
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r0, #0x34
	subs r1, r1, r0
	strh r1, [r6, #4]
	b _0802C9F0
	.align 2, 0
_0802C9E0: .4byte gMain+0x3268 @gMain.spriteGroups[66]
_0802C9E4: .4byte gCurrentPinballGame
_0802C9E8: .4byte 0x0000029F
_0802C9EC:
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802C9F0:
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _0802CA20 @ =0x0000029F
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0802CA24
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	adds r0, #4
	b _0802CA32
	.align 2, 0
_0802CA20: .4byte 0x0000029F
_0802CA24:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
_0802CA32:
	ldr r2, _0802CA80 @ =0x040000D4
	lsls r0, r0, #7
	ldr r1, _0802CA84 @ =gUnknown_084FEF0C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802CA88 @ =0x06014B00
	str r0, [r2, #4]
	ldr r0, _0802CA8C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802CA90 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802CA94 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802CA98 @ =0xFFFFFE00
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
_0802CA7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA80: .4byte 0x040000D4
_0802CA84: .4byte gUnknown_084FEF0C
_0802CA88: .4byte 0x06014B00
_0802CA8C: .4byte 0x80000040
_0802CA90: .4byte gOamBuffer
_0802CA94: .4byte 0x000001FF
_0802CA98: .4byte 0xFFFFFE00

	thumb_func_start sub_2CA9C
sub_2CA9C: @ 0x0802CA9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov ip, r0
	ldr r0, _0802CADC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xc8
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802CAB8
	b _0802CCF2
_0802CAB8:
	movs r0, #0xca
	strh r0, [r6, #2]
	ldr r0, _0802CAE0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0802CAE4 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x30
	bls _0802CB44
	subs r0, #0x30
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x21
	ble _0802CAE8
	movs r1, #0x2a
	subs r1, r1, r0
	lsls r1, r1, #1
	b _0802CB12
	.align 2, 0
_0802CADC: .4byte gMain
_0802CAE0: .4byte gCurrentPinballGame
_0802CAE4: .4byte 0x00000286
_0802CAE8:
	cmp r0, #0x17
	ble _0802CAFC
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #1
	ldr r3, _0802CAF8 @ =0x0000FFF7
	mov ip, r3
	b _0802CB1A
	.align 2, 0
_0802CAF8: .4byte 0x0000FFF7
_0802CAFC:
	cmp r0, #7
	ble _0802CB10
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #2
	ldr r1, _0802CB0C @ =0x0000FFFC
	mov ip, r1
	b _0802CB1A
	.align 2, 0
_0802CB0C: .4byte 0x0000FFFC
_0802CB10:
	lsls r1, r0, #1
_0802CB12:
	movs r0, #0x92
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
_0802CB1A:
	ldr r2, _0802CB34 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _0802CB38 @ =gUnknown_08455E8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802CB3C @ =0x060152A0
	str r0, [r2, #4]
	ldr r0, _0802CB40 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802CB48
	.align 2, 0
_0802CB34: .4byte 0x040000D4
_0802CB38: .4byte gUnknown_08455E8C
_0802CB3C: .4byte 0x060152A0
_0802CB40: .4byte 0x80000100
_0802CB44:
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802CB48:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802CB90 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802CB94 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802CB98 @ =0xFFFFFE00
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
	ldr r0, _0802CB9C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0802CBA0 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x38
	bls _0802CBA4
	movs r7, #0x80
	lsls r7, r7, #1
	b _0802CBD6
	.align 2, 0
_0802CB90: .4byte gOamBuffer
_0802CB94: .4byte 0x000001FF
_0802CB98: .4byte 0xFFFFFE00
_0802CB9C: .4byte gCurrentPinballGame
_0802CBA0: .4byte 0x00000286
_0802CBA4:
	subs r0, #0x24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802CBCC
	lsls r0, r0, #7
	movs r1, #0x14
	bl __divsi3
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0x82
	strh r0, [r6, #4]
	ldr r3, _0802CBC8 @ =0x0000FFFE
	mov ip, r3
	b _0802CBD6
	.align 2, 0
_0802CBC8: .4byte 0x0000FFFE
_0802CBCC:
	movs r7, #0x80
	movs r0, #0xb4
	strh r0, [r6, #4]
	movs r0, #0
	mov ip, r0
_0802CBD6:
	adds r5, r6, #0
	adds r5, #0x10
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r0, _0802CCA8 @ =0x000001FF
	mov r8, r0
	mov r3, r8
	ands r1, r3
	ldrh r3, [r2, #2]
	ldr r0, _0802CCAC @ =0xFFFFFE00
	mov sb, r0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x10]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	add r0, ip
	strb r0, [r1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #3]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #6
	bl SetMatrixScale
	ldr r0, _0802CCB0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _0802CCB4 @ =0x00000286
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0x39
	bhi _0802CCC8
	adds r0, r1, #0
	adds r0, #0x30
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrh r1, [r3]
	movs r0, #0xf
	ands r1, r0
	lsrs r1, r1, #3
	lsls r0, r1, #3
	adds r0, r0, r1
	subs r0, #1
	ldr r1, _0802CCB8 @ =0x040000D4
	adds r2, r2, r0
	lsls r2, r2, #6
	ldr r0, _0802CCBC @ =gUnknown_0845648C
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, _0802CCC0 @ =0x06015520
	str r0, [r1, #4]
	ldr r0, _0802CCC4 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x70
	b _0802CCF0
	.align 2, 0
_0802CCA8: .4byte 0x000001FF
_0802CCAC: .4byte 0xFFFFFE00
_0802CCB0: .4byte gCurrentPinballGame
_0802CCB4: .4byte 0x00000286
_0802CCB8: .4byte 0x040000D4
_0802CCBC: .4byte gUnknown_0845648C
_0802CCC0: .4byte 0x06015520
_0802CCC4: .4byte 0x80000020
_0802CCC8:
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x4c
_0802CCF0:
	strb r0, [r1]
_0802CCF2:
	ldr r5, _0802CD74 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _0802CD78 @ =0x00000286
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802CD68
	cmp r0, #0x5a
	bne _0802CD18
	movs r0, #1
	strh r0, [r6]
	ldr r1, _0802CD7C @ =0x040000D4
	ldr r0, _0802CD80 @ =gUnknown_086AE324
	str r0, [r1]
	ldr r0, _0802CD84 @ =0x05000380
	str r0, [r1, #4]
	ldr r0, _0802CD88 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802CD18:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x55
	bne _0802CD2A
	ldr r0, _0802CD8C @ =gMPlayInfo_SE1
	ldr r1, _0802CD90 @ =gUnknown_086A1ABC
	bl MPlayStart
_0802CD2A:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x3a
	bne _0802CD50
	ldr r0, _0802CD8C @ =gMPlayInfo_SE1
	ldr r1, _0802CD94 @ =gUnknown_0869F2A0
	bl MPlayStart
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bgt _0802CD50
	adds r0, r2, #1
	strb r0, [r1]
_0802CD50:
	ldr r0, _0802CD74 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _0802CD78 @ =0x00000286
	adds r1, r1, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0802CD68
	strh r0, [r6]
_0802CD68:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD74: .4byte gCurrentPinballGame
_0802CD78: .4byte 0x00000286
_0802CD7C: .4byte 0x040000D4
_0802CD80: .4byte gUnknown_086AE324
_0802CD84: .4byte 0x05000380
_0802CD88: .4byte 0x80000010
_0802CD8C: .4byte gMPlayInfo_SE1
_0802CD90: .4byte gUnknown_086A1ABC
_0802CD94: .4byte gUnknown_0869F2A0

	thumb_func_start sub_2CD98
sub_2CD98: @ 0x0802CD98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0802CE6C @ =gMain
	ldr r1, [r0, #0x44]
	ldr r6, [r1, #0x28]
	ldrh r1, [r6]
	mov sb, r0
	ldr r0, _0802CE70 @ =gCurrentPinballGame
	mov ip, r0
	cmp r1, #0
	beq _0802CE0E
	ldr r0, [r0]
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #2]
	movs r0, #0x2c
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0802CE74 @ =gOamBuffer
	ldr r2, _0802CE78 @ =0xFFFFFE00
	mov r8, r2
_0802CDCA:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802CE7C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #6
	ble _0802CDCA
_0802CE0E:
	mov r4, ip
	ldr r0, [r4]
	adds r0, #0xf4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0802CE5E
	cmp r0, #0x78
	bne _0802CE2A
	mov r2, sb
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x28]
	movs r0, #1
	strh r0, [r1]
_0802CE2A:
	mov r4, ip
	ldr r3, [r4]
	adds r2, r3, #0
	adds r2, #0xf4
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x78
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r4, #0x87
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	adds r4, #0x5c
	adds r1, r3, r4
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _0802CE5E
	mov r2, sb
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x28]
	movs r0, #0
	strh r0, [r1]
_0802CE5E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CE6C: .4byte gMain
_0802CE70: .4byte gCurrentPinballGame
_0802CE74: .4byte gOamBuffer
_0802CE78: .4byte 0xFFFFFE00
_0802CE7C: .4byte 0x000001FF

	thumb_func_start sub_2CE80
sub_2CE80: @ 0x0802CE80
	push {r4, r5, lr}
	ldr r0, _0802CEC0 @ =gCurrentPinballGame
	ldr r4, [r0]
	adds r1, r4, #0
	adds r1, #0x68
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r5, r0, #0
	cmp r1, #0xa9
	bgt _0802CED8
	ldr r3, _0802CEC4 @ =0x040000D4
	ldr r0, _0802CEC8 @ =gMain
	ldrb r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #6
	ldr r2, _0802CECC @ =gUnknown_08137B3C
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r3]
	ldr r0, _0802CED0 @ =0x05000360
	str r0, [r3, #4]
	ldr r0, _0802CED4 @ =0x80000010
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	b _0802CF02
	.align 2, 0
_0802CEC0: .4byte gCurrentPinballGame
_0802CEC4: .4byte 0x040000D4
_0802CEC8: .4byte gMain
_0802CECC: .4byte gUnknown_08137B3C
_0802CED0: .4byte 0x05000360
_0802CED4: .4byte 0x80000010
_0802CED8:
	ldr r2, _0802CF20 @ =0x040000D4
	ldr r0, _0802CF24 @ =gMain
	ldrb r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	ldr r0, _0802CF28 @ =gUnknown_08137B5C
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #6
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0802CF2C @ =0x05000360
	str r0, [r2, #4]
	ldr r0, _0802CF30 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0802CF02:
	ldr r0, [r5]
	ldr r3, _0802CF34 @ =0x00000163
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bls _0802CF14
	b _0802D0FA
_0802CF14:
	lsls r0, r0, #2
	ldr r1, _0802CF38 @ =_0802CF3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CF20: .4byte 0x040000D4
_0802CF24: .4byte gMain
_0802CF28: .4byte gUnknown_08137B5C
_0802CF2C: .4byte 0x05000360
_0802CF30: .4byte 0x80000010
_0802CF34: .4byte 0x00000163
_0802CF38: .4byte _0802CF3C
_0802CF3C: @ jump table
	.4byte _0802CF50 @ case 0
	.4byte _0802CFAC @ case 1
	.4byte _0802D02C @ case 2
	.4byte _0802D074 @ case 3
	.4byte _0802D0A4 @ case 4
_0802CF50:
	ldr r0, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r4, [r5]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _0802CF90 @ =0x00000165
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq _0802CF94
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _0802CF9C
	.align 2, 0
_0802CF90: .4byte 0x00000165
_0802CF94:
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r1, [r0]
_0802CF9C:
	ldr r0, [r5]
	ldr r4, _0802CFA8 @ =0x00000165
	adds r1, r0, r4
	movs r0, #0
	strb r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802CFA8: .4byte 0x00000165
_0802CFAC:
	ldr r1, [r5]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #4
	bhi _0802D00A
	cmp r0, #1
	bhi _0802CFD4
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #3
	b _0802CFE8
_0802CFD4:
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #5
_0802CFE8:
	strh r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802CFFE
	movs r0, 0xCC @=SE_UNKNOWN_0xCC
	bl m4aSongNumStart
_0802CFFE:
	ldr r1, [r5]
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0802D0FA
_0802D00A:
	ldr r3, _0802D028 @ =0x00000163
	adds r1, r1, r3
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xb4
	lsls r1, r1, #1
	b _0802D09A
	.align 2, 0
_0802D028: .4byte 0x00000163
_0802D02C:
	ldr r0, _0802D070 @ =gUnknown_086AE344
	ldr r2, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r3, r2, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r2, [r1]
	cmp r0, r2
	bgt _0802D0C8
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #7
	ble _0802D0FA
	movs r0, #4
	strb r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802D070: .4byte gUnknown_086AE344
_0802D074:
	ldr r0, [r5]
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r2, #0
	movs r1, #8
	strb r1, [r0]
	ldr r1, [r5]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	ldr r0, _0802D0A0 @ =0x00000163
	adds r1, r1, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0xb3
	lsls r1, r1, #1
_0802D09A:
	adds r0, r0, r1
	strh r2, [r0]
	b _0802D0FA
	.align 2, 0
_0802D0A0: .4byte 0x00000163
_0802D0A4:
	ldr r0, _0802D0D0 @ =gUnknown_086AE344
	ldr r2, [r5]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r3, r2, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	movs r4, #0xb4
	lsls r4, r4, #1
	adds r1, r2, r4
	ldrh r2, [r1]
	cmp r0, r2
	ble _0802D0D4
_0802D0C8:
	adds r0, r2, #1
	strh r0, [r1]
	b _0802D0FA
	.align 2, 0
_0802D0D0: .4byte gUnknown_086AE344
_0802D0D4:
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r5]
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x13
	ble _0802D0FA
	strb r2, [r1]
	ldr r0, [r5]
	ldr r4, _0802D100 @ =0x00000163
	adds r0, r0, r4
	strb r2, [r0]
_0802D0FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D100: .4byte 0x00000163

	thumb_func_start sub_2D104
sub_2D104: @ 0x0802D104
	push {r4, r5, r6, r7, lr}
	ldr r0, _0802D144 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xb0
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0802D1DC
	ldr r1, _0802D148 @ =gCurrentPinballGame
	ldr r3, [r1]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r4, r1, #0
	cmp r0, #0
	bne _0802D14C
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x1e
	bl __umodsi3
	movs r1, #0xf
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0802D158
	.align 2, 0
_0802D144: .4byte gMain
_0802D148: .4byte gCurrentPinballGame
_0802D14C:
	ldr r1, _0802D1E4 @ =gUnknown_086AE344
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
_0802D158:
	ldr r2, _0802D1E8 @ =0x040000D4
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _0802D1EC @ =gUnknown_083C076C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802D1F0 @ =0x060120E0
	str r0, [r2, #4]
	ldr r0, _0802D1F4 @ =0x800000E0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xe7
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0802D1F8 @ =gOamBuffer
	ldr r1, _0802D1FC @ =0xFFFFFE00
	mov ip, r1
_0802D198:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r6, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r7
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _0802D200 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _0802D198
_0802D1DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D1E4: .4byte gUnknown_086AE344
_0802D1E8: .4byte 0x040000D4
_0802D1EC: .4byte gUnknown_083C076C
_0802D1F0: .4byte 0x060120E0
_0802D1F4: .4byte 0x800000E0
_0802D1F8: .4byte gOamBuffer
_0802D1FC: .4byte 0xFFFFFE00
_0802D200: .4byte 0x000001FF

	thumb_func_start sub_2D204
sub_2D204: @ 0x0802D204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0802D358 @ =0xFFFFFDE0
	add sp, r4
	ldr r1, _0802D35C @ =gCurrentPinballGame
	ldr r2, [r1]
	ldrh r3, [r2, #0x18]
	adds r4, r3, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	cmp r4, r0
	bls _0802D226
	bl sub_2DE54
_0802D226:
	cmp r4, #0
	bne _0802D254
	bl m4aMPlayAllStop
	ldr r1, _0802D360 @ =0x040000D4
	ldr r0, _0802D364 @ =0x05000200
	str r0, [r1]
	ldr r2, _0802D35C @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _0802D368 @ =0x0000111A
	adds r0, r0, r3
	str r0, [r1, #4]
	ldr r0, _0802D36C @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2]
	ldr r1, _0802D370 @ =0x000006DB
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r2]
	ldr r2, _0802D374 @ =0x000005FA
	adds r0, r0, r2
	strb r4, [r0]
_0802D254:
	ldr r3, _0802D35C @ =gCurrentPinballGame
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xa
	bne _0802D2AA
	adds r1, #0xe4
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0802D360 @ =0x040000D4
	ldr r0, _0802D378 @ =gUnknown_08158284
	str r0, [r1]
	ldr r0, _0802D37C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802D380 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802D384 @ =gUnknown_0815A6A4
	str r0, [r1]
	ldr r0, _0802D388 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0802D38C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0802D390 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x60]
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x64]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x68]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x6c]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x70]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x3c]
	strh r1, [r0]
_0802D2AA:
	ldr r4, _0802D35C @ =gCurrentPinballGame
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xeb
	bgt _0802D2C2
	ldrh r0, [r1, #0x18]
	lsrs r0, r0, #1
	adds r1, #0xe6
	strh r0, [r1]
_0802D2C2:
	ldr r3, _0802D35C @ =gCurrentPinballGame
	ldr r0, [r3]
	ldrh r0, [r0, #0x18]
	adds r3, r0, #0
	cmp r3, #0x23
	bhi _0802D2D0
	b _0802D3F6
_0802D2D0:
	cmp r3, #0x43
	bhi _0802D3A0
	subs r0, #0x24
	lsls r0, r0, #0x10
	movs r3, #0
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	ldr r4, _0802D394 @ =gUnknown_03005C00
	mov sb, r4
	cmp r3, r0
	bgt _0802D320
	mov r2, sb
	mov r8, r0
	movs r7, #0xc1
	lsls r7, r7, #8
_0802D2EE:
	movs r6, #1
	lsls r3, r3, #0x10
	asrs r4, r3, #0x10
_0802D2F4:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r7, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802D2F4
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	ble _0802D2EE
_0802D320:
	ldr r1, _0802D360 @ =0x040000D4
	mov r2, sb
	str r2, [r1]
	ldr r0, _0802D398 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802D39C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	cmp r5, #0x1e
	bne _0802D33A
	movs r0, 0x1A @ =MUS_EVOLUTION
	bl m4aSongNumStart
_0802D33A:
	ldr r0, _0802D390 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0802D3F6
	ldr r0, _0802D35C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x43
	bne _0802D3F6
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
	b _0802D3F6
	.align 2, 0
_0802D358: .4byte 0xFFFFFDE0
_0802D35C: .4byte gCurrentPinballGame
_0802D360: .4byte 0x040000D4
_0802D364: .4byte 0x05000200
_0802D368: .4byte 0x0000111A
_0802D36C: .4byte 0x80000100
_0802D370: .4byte 0x000006DB
_0802D374: .4byte 0x000005FA
_0802D378: .4byte gUnknown_08158284
_0802D37C: .4byte 0x06015800
_0802D380: .4byte 0x80001200
_0802D384: .4byte gUnknown_0815A6A4
_0802D388: .4byte 0x050003C0
_0802D38C: .4byte 0x80000010
_0802D390: .4byte gMain
_0802D394: .4byte gUnknown_03005C00
_0802D398: .4byte 0x06002000
_0802D39C: .4byte 0x80000400
_0802D3A0:
	movs r0, #0xac
	lsls r0, r0, #1
	cmp r3, r0
	bhi _0802D3F6
	movs r3, #0
	ldr r4, _0802D484 @ =gUnknown_03005C00
	mov sb, r4
	mov r5, sb
	movs r4, #0xc1
	lsls r4, r4, #8
_0802D3B4:
	movs r6, #1
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
_0802D3BA:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	ble _0802D3BA
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	ble _0802D3B4
	ldr r1, _0802D488 @ =0x040000D4
	mov r2, sb
	str r2, [r1]
	ldr r0, _0802D48C @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802D490 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802D3F6:
	ldr r2, _0802D494 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0802D498 @ =0xFFFFFEF2
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0802D40C
	b _0802D54C
_0802D40C:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _0802D4A4
	movs r6, #0
	mov sl, r0
	ldr r4, _0802D49C @ =gUnknown_020028A8
	mov sb, r4
	adds r0, r2, #0
	mov r8, r0
	ldr r7, _0802D4A0 @ =0x000012BA
	movs r1, #2
	add r1, sb
	mov ip, r1
_0802D428:
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r5, r2, #1
	adds r4, r5, r2
	mov r0, sb
	adds r3, r4, r0
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	strb r0, [r3]
	mov r3, sb
	adds r3, #1
	adds r3, r4, r3
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	lsrs r0, r0, #5
	strb r0, [r3]
	add r4, ip
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	lsrs r0, r0, #0xa
	strb r0, [r4]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xf
	ble _0802D428
	b _0802D53E
	.align 2, 0
_0802D484: .4byte gUnknown_03005C00
_0802D488: .4byte 0x040000D4
_0802D48C: .4byte 0x06002000
_0802D490: .4byte 0x80000400
_0802D494: .4byte gCurrentPinballGame
_0802D498: .4byte 0xFFFFFEF2
_0802D49C: .4byte gUnknown_020028A8
_0802D4A0: .4byte 0x000012BA
_0802D4A4:
	movs r6, #0
	mov sl, r0
	movs r4, #0xd8
	lsls r4, r4, #1
	add r4, sp
	str r4, [sp, #0x214]
	add r7, sp, #0x210
	mov sb, r1
_0802D4B4:
	lsls r5, r6, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #1
	mov r8, r0
	adds r6, r0, r5
	ldr r1, _0802D5B8 @ =gUnknown_020028A8
	adds r0, r6, r1
	ldrb r4, [r0]
	movs r2, #0x1f
	subs r0, r2, r4
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7]
	ldr r0, _0802D5B8 @ =gUnknown_020028A8
	adds r0, #1
	adds r0, r6, r0
	ldrb r4, [r0]
	movs r1, #0x1f
	subs r0, r1, r4
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7, #1]
	ldr r3, _0802D5BC @ =gUnknown_020028AA
	adds r6, r6, r3
	ldrb r4, [r6]
	movs r1, #0x1f
	subs r0, r1, r4
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x1e
	bl __divsi3
	adds r4, r4, r0
	strb r4, [r7, #2]
	ldr r3, [sp, #0x214]
	add r8, r3
	ldrb r1, [r7]
	ldrb r0, [r7, #1]
	lsls r0, r0, #5
	orrs r1, r0
	ldrb r0, [r7, #2]
	lsls r0, r0, #0xa
	orrs r1, r0
	mov r4, r8
	strh r1, [r4]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r6, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #0xf
	ble _0802D4B4
	ldr r1, _0802D5C0 @ =0x040000D4
	str r3, [r1]
	ldr r0, _0802D5C4 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0802D5C8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802D53E:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0xa
	bne _0802D54C
	movs r0, 0xB0 @=SE_UNKNOWN_0xB0
	bl m4aSongNumStart
_0802D54C:
	ldr r1, _0802D5CC @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r4, _0802D5D0 @ =0xFFFFFED4
	adds r2, r4, #0
	ldrh r4, [r3, #0x18]
	adds r0, r2, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bhi _0802D582
	movs r0, #0x88
	lsls r0, r0, #5
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D5CC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrh r0, [r0, #0x18]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0802D5D4 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0x9f
	strh r1, [r0, #0x38]
	ldrh r1, [r0, #0x3c]
	strh r5, [r0, #0x3c]
_0802D582:
	ldr r2, _0802D5CC @ =gCurrentPinballGame
	ldr r0, [r2]
	ldrh r2, [r0, #0x18]
	cmp r2, #0xa
	bhi _0802D58E
	b _0802DD32
_0802D58E:
	ldr r1, _0802D5D4 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x60]
	ldr r3, _0802D5D8 @ =0x0000FF88
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0802D5DC
	mov r4, sp
	subs r0, #0x16
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa0
	strh r1, [r4]
	b _0802D5E2
	.align 2, 0
_0802D5B8: .4byte gUnknown_020028A8
_0802D5BC: .4byte gUnknown_020028AA
_0802D5C0: .4byte 0x040000D4
_0802D5C4: .4byte 0x050003A0
_0802D5C8: .4byte 0x80000010
_0802D5CC: .4byte gCurrentPinballGame
_0802D5D0: .4byte 0xFFFFFED4
_0802D5D4: .4byte gMain
_0802D5D8: .4byte 0x0000FF88
_0802D5DC:
	mov r1, sp
	ldr r0, _0802D604 @ =0x0000FF5E
	strh r0, [r1]
_0802D5E2:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0
	blt _0802D608
	mov r4, sp
	adds r0, r1, #0
	movs r1, #0x66
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #2]
	b _0802D60E
	.align 2, 0
_0802D604: .4byte 0x0000FF5E
_0802D608:
	mov r1, sp
	ldr r0, _0802D62C @ =0x0000FF5E
	strh r0, [r1, #2]
_0802D60E:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x47
	ble _0802D630
	mov r4, sp
	subs r0, #0x48
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #4]
	b _0802D636
	.align 2, 0
_0802D62C: .4byte 0x0000FF5E
_0802D630:
	mov r1, sp
	ldr r0, _0802D654 @ =0x0000FF5E
	strh r0, [r1, #4]
_0802D636:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x32
	ble _0802D658
	mov r4, sp
	subs r0, #0x33
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa1
	strh r1, [r4, #6]
	b _0802D65E
	.align 2, 0
_0802D654: .4byte 0x0000FF5E
_0802D658:
	mov r1, sp
	ldr r0, _0802D6F8 @ =0x0000FF5F
	strh r0, [r1, #6]
_0802D65E:
	ldr r2, _0802D6FC @ =gCurrentPinballGame
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D700 @ =gOamBuffer
	ldr r4, _0802D704 @ =0xFFFFFE00
	mov r8, r4
_0802D684:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r0, #2
	ldrsh r2, [r7, r0]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D708 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D684
	ldr r2, _0802D6FC @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0802D70C @ =0x0000FFC4
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	ble _0802D710
	mov r4, sp
	subs r0, #0x16
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa0
	strh r1, [r4]
	b _0802D716
	.align 2, 0
_0802D6F8: .4byte 0x0000FF5F
_0802D6FC: .4byte gCurrentPinballGame
_0802D700: .4byte gOamBuffer
_0802D704: .4byte 0xFFFFFE00
_0802D708: .4byte 0x000001FF
_0802D70C: .4byte 0x0000FFC4
_0802D710:
	mov r1, sp
	ldr r0, _0802D738 @ =0x0000FF5E
	strh r0, [r1]
_0802D716:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0
	blt _0802D73C
	mov r4, sp
	adds r0, r1, #0
	movs r1, #0x66
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #2]
	b _0802D742
	.align 2, 0
_0802D738: .4byte 0x0000FF5E
_0802D73C:
	mov r1, sp
	ldr r0, _0802D760 @ =0x0000FF5E
	strh r0, [r1, #2]
_0802D742:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x47
	ble _0802D764
	mov r4, sp
	subs r0, #0x48
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa2
	strh r1, [r4, #4]
	b _0802D76A
	.align 2, 0
_0802D760: .4byte 0x0000FF5E
_0802D764:
	mov r1, sp
	ldr r0, _0802D788 @ =0x0000FF5E
	strh r0, [r1, #4]
_0802D76A:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x32
	ble _0802D78C
	mov r4, sp
	subs r0, #0x33
	movs r1, #0x66
	bl __modsi3
	lsls r1, r0, #1
	adds r1, r1, r0
	subs r1, #0xa1
	strh r1, [r4, #6]
	b _0802D792
	.align 2, 0
_0802D788: .4byte 0x0000FF5E
_0802D78C:
	mov r1, sp
	ldr r0, _0802D834 @ =0x0000FF5F
	strh r0, [r1, #6]
_0802D792:
	ldr r2, _0802D838 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x64]
	ldr r3, _0802D83C @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D840 @ =gOamBuffer
	ldr r0, _0802D844 @ =0xFFFFFE00
	mov r8, r0
_0802D7BE:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D848 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D7BE
	ldr r2, _0802D838 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x68]
	ldr r3, _0802D83C @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _0802D84C @ =0x0000FF9C
	adds r0, r4, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802D850
	mov r4, sp
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	subs r0, #0xa0
	strh r0, [r4]
	b _0802D856
	.align 2, 0
_0802D834: .4byte 0x0000FF5F
_0802D838: .4byte gMain
_0802D83C: .4byte gCurrentPinballGame
_0802D840: .4byte gOamBuffer
_0802D844: .4byte 0xFFFFFE00
_0802D848: .4byte 0x000001FF
_0802D84C: .4byte 0x0000FF9C
_0802D850:
	mov r1, sp
	ldr r0, _0802D874 @ =0x0000FF60
	strh r0, [r1]
_0802D856:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0x25
	ble _0802D878
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0x26
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #2]
	b _0802D87E
	.align 2, 0
_0802D874: .4byte 0x0000FF60
_0802D878:
	mov r1, sp
	ldr r0, _0802D898 @ =0x0000FF60
	strh r0, [r1, #2]
_0802D87E:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x4b
	ble _0802D89C
	mov r4, sp
	subs r0, #0x4c
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #4]
	b _0802D8A2
	.align 2, 0
_0802D898: .4byte 0x0000FF60
_0802D89C:
	mov r1, sp
	ldr r0, _0802D8BC @ =0x0000FF60
	strh r0, [r1, #4]
_0802D8A2:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x71
	ble _0802D8C0
	mov r4, sp
	subs r0, #0x72
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #6]
	b _0802D8C6
	.align 2, 0
_0802D8BC: .4byte 0x0000FF60
_0802D8C0:
	mov r1, sp
	ldr r0, _0802D964 @ =0x0000FF60
	strh r0, [r1, #6]
_0802D8C6:
	ldr r3, _0802D968 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802D96C @ =gOamBuffer
	ldr r0, _0802D970 @ =0xFFFFFE00
	mov r8, r0
_0802D8EC:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802D974 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802D8EC
	ldr r2, _0802D978 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x6c]
	ldr r3, _0802D968 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _0802D97C @ =0x0000FFB0
	adds r0, r4, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802D980
	mov r4, sp
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	subs r0, #0xa0
	strh r0, [r4]
	b _0802D986
	.align 2, 0
_0802D964: .4byte 0x0000FF60
_0802D968: .4byte gCurrentPinballGame
_0802D96C: .4byte gOamBuffer
_0802D970: .4byte 0xFFFFFE00
_0802D974: .4byte 0x000001FF
_0802D978: .4byte gMain
_0802D97C: .4byte 0x0000FFB0
_0802D980:
	mov r1, sp
	ldr r0, _0802D9A4 @ =0x0000FF60
	strh r0, [r1]
_0802D986:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0x25
	ble _0802D9A8
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0x26
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #2]
	b _0802D9AE
	.align 2, 0
_0802D9A4: .4byte 0x0000FF60
_0802D9A8:
	mov r1, sp
	ldr r0, _0802D9C8 @ =0x0000FF60
	strh r0, [r1, #2]
_0802D9AE:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x4b
	ble _0802D9CC
	mov r4, sp
	subs r0, #0x4c
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #4]
	b _0802D9D2
	.align 2, 0
_0802D9C8: .4byte 0x0000FF60
_0802D9CC:
	mov r1, sp
	ldr r0, _0802D9EC @ =0x0000FF60
	strh r0, [r1, #4]
_0802D9D2:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x71
	ble _0802D9F0
	mov r4, sp
	subs r0, #0x72
	movs r1, #0x98
	bl __modsi3
	lsls r0, r0, #1
	subs r0, #0xa0
	strh r0, [r4, #6]
	b _0802D9F6
	.align 2, 0
_0802D9EC: .4byte 0x0000FF60
_0802D9F0:
	mov r1, sp
	ldr r0, _0802DA8C @ =0x0000FF60
	strh r0, [r1, #6]
_0802D9F6:
	ldr r3, _0802DA90 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802DA94 @ =gOamBuffer
	ldr r0, _0802DA98 @ =0xFFFFFE00
	mov r8, r0
_0802DA1C:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802DA9C @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802DA1C
	ldr r2, _0802DA90 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0802DAA0 @ =0x0000FFA6
	adds r0, r3, #0
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xeb
	ble _0802DAA4
	mov r4, sp
	subs r0, #0xec
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4]
	b _0802DAAA
	.align 2, 0
_0802DA8C: .4byte 0x0000FF60
_0802DA90: .4byte gCurrentPinballGame
_0802DA94: .4byte gOamBuffer
_0802DA98: .4byte 0xFFFFFE00
_0802DA9C: .4byte 0x000001FF
_0802DAA0: .4byte 0x0000FFA6
_0802DAA4:
	mov r1, sp
	ldr r0, _0802DAC8 @ =0x0000FF80
	strh r0, [r1]
_0802DAAA:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	mov sl, r0
	cmp r1, #0xcb
	ble _0802DACC
	mov r4, sp
	adds r0, r1, #0
	subs r0, #0xcc
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #2]
	b _0802DAD2
	.align 2, 0
_0802DAC8: .4byte 0x0000FF80
_0802DACC:
	mov r1, sp
	ldr r0, _0802DAEC @ =0x0000FF80
	strh r0, [r1, #2]
_0802DAD2:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0xa7
	ble _0802DAF0
	mov r4, sp
	subs r0, #0xa8
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #4]
	b _0802DAF6
	.align 2, 0
_0802DAEC: .4byte 0x0000FF80
_0802DAF0:
	mov r1, sp
	ldr r0, _0802DB10 @ =0x0000FF80
	strh r0, [r1, #4]
_0802DAF6:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0x87
	ble _0802DB14
	mov r4, sp
	subs r0, #0x88
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #6]
	b _0802DB1A
	.align 2, 0
_0802DB10: .4byte 0x0000FF80
_0802DB14:
	mov r1, sp
	ldr r0, _0802DB34 @ =0x0000FF80
	strh r0, [r1, #6]
_0802DB1A:
	mov r2, sl
	asrs r0, r2, #0x10
	cmp r0, #0x63
	ble _0802DB38
	mov r4, sp
	subs r0, #0x64
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #8]
	b _0802DB3E
	.align 2, 0
_0802DB34: .4byte 0x0000FF80
_0802DB38:
	mov r1, sp
	ldr r0, _0802DB58 @ =0x0000FF80
	strh r0, [r1, #8]
_0802DB3E:
	mov r3, sl
	asrs r0, r3, #0x10
	cmp r0, #0x43
	ble _0802DB5C
	mov r4, sp
	subs r0, #0x44
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xa]
	b _0802DB62
	.align 2, 0
_0802DB58: .4byte 0x0000FF80
_0802DB5C:
	mov r1, sp
	ldr r0, _0802DB7C @ =0x0000FF80
	strh r0, [r1, #0xa]
_0802DB62:
	mov r4, sl
	asrs r0, r4, #0x10
	cmp r0, #0x1f
	ble _0802DB80
	mov r4, sp
	subs r0, #0x20
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xc]
	b _0802DB86
	.align 2, 0
_0802DB7C: .4byte 0x0000FF80
_0802DB80:
	mov r1, sp
	ldr r0, _0802DBA0 @ =0x0000FF80
	strh r0, [r1, #0xc]
_0802DB86:
	mov r1, sl
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _0802DBA4
	mov r4, sp
	movs r1, #0x88
	lsls r1, r1, #1
	bl __modsi3
	subs r0, #0x80
	strh r0, [r4, #0xe]
	b _0802DBAA
	.align 2, 0
_0802DBA0: .4byte 0x0000FF80
_0802DBA4:
	mov r1, sp
	ldr r0, _0802DC74 @ =0x0000FF80
	strh r0, [r1, #0xe]
_0802DBAA:
	ldr r2, _0802DC78 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x70]
	ldr r3, _0802DC7C @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r6, #0
	ldr r5, _0802DC80 @ =gOamBuffer
	ldr r0, _0802DC84 @ =0xFFFFFE00
	mov r8, r0
_0802DBD6:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r4, [r6]
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r1, #2
	ldrsh r2, [r7, r1]
	lsls r0, r3, #1
	add r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r2, r0
	ldr r1, _0802DC88 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	ldrh r1, [r4, #2]
	mov r0, r8
	ands r0, r1
	orrs r0, r2
	strh r0, [r4, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #7
	ble _0802DBD6
	ldr r2, _0802DC78 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r7, [r0, #0x3c]
	ldr r3, _0802DC7C @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	strh r0, [r7, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r1, _0802DC8C @ =0x0000FF88
	adds r0, r1, #0
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	ble _0802DC90
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	adds r0, r2, #0
	movs r1, #0x46
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #7
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b _0802DC98
	.align 2, 0
_0802DC74: .4byte 0x0000FF80
_0802DC78: .4byte gMain
_0802DC7C: .4byte gCurrentPinballGame
_0802DC80: .4byte gOamBuffer
_0802DC84: .4byte 0xFFFFFE00
_0802DC88: .4byte 0x000001FF
_0802DC8C: .4byte 0x0000FF88
_0802DC90:
	mov r1, sp
	ldr r0, _0802DE04 @ =0x0000FF60
	strh r0, [r1]
	movs r3, #0
_0802DC98:
	movs r6, #0
	lsls r0, r3, #0x10
	ldr r2, _0802DE08 @ =gOamBuffer
	mov sl, r2
	ldr r3, _0802DE0C @ =gUnknown_086B4112
	mov sb, r3
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov r8, r0
	ldr r4, _0802DE10 @ =0xFFFFFE00
	mov ip, r4
_0802DCB2:
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r1, sl
	adds r2, r0, r1
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r0, r1, #1
	add r0, r8
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, r8
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, r8
	add r1, sb
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, sl
	ldrh r5, [r3, #2]
	lsls r2, r5, #0x17
	lsrs r2, r2, #0x17
	str r2, [sp, #0x218]
	movs r2, #2
	ldrsh r1, [r7, r2]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r0, [sp, #0x218]
	adds r2, r0, r1
	ldr r1, _0802DE14 @ =0x000001FF
	adds r0, r1, #0
	ands r2, r0
	mov r0, ip
	ands r0, r5
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0802DCB2
_0802DD32:
	ldr r3, _0802DE18 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldrh r1, [r0, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #1
	cmp r1, r0
	bne _0802DD84
	movs r1, #0xf0
	lsls r1, r1, #0x11
	ldr r4, _0802DE1C @ =gUnknown_03005C00
	mov sb, r4
	ldr r3, _0802DE14 @ =0x000001FF
	ldr r2, _0802DE20 @ =0x0000033F
_0802DD4C:
	asrs r0, r1, #0x10
	lsls r1, r0, #1
	adds r1, r1, r4
	strh r3, [r1]
	adds r0, #1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, r2
	ble _0802DD4C
	ldr r1, _0802DE24 @ =0x040000D4
	mov r0, sb
	str r0, [r1]
	ldr r0, _0802DE28 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0802DE2C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0802DE30 @ =gMain
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _0802DD84
	ldr r2, _0802DE18 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	strh r1, [r0]
_0802DD84:
	ldr r4, _0802DE18 @ =gCurrentPinballGame
	ldr r3, [r4]
	ldrh r1, [r3, #0x18]
	movs r0, #0xb4
	lsls r0, r0, #1
	cmp r1, r0
	beq _0802DD94
	b _0802E052
_0802DD94:
	ldr r2, _0802DE30 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x60]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x64]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x68]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x6c]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x70]
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x3c]
	strh r1, [r0]
	ldr r1, _0802DE34 @ =0x000005A2
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0x11
	strb r1, [r0]
	ldr r1, _0802DE24 @ =0x040000D4
	ldr r0, _0802DE38 @ =gUnknown_083A562C
	str r0, [r1]
	ldr r0, _0802DE3C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802DE40 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802DE44 @ =gUnknown_083A6E4C
	str r0, [r1]
	ldr r0, _0802DE48 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0802DE4C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r4]
	ldr r3, _0802DE50 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	b _0802E052
	.align 2, 0
_0802DE04: .4byte 0x0000FF60
_0802DE08: .4byte gOamBuffer
_0802DE0C: .4byte gUnknown_086B4112
_0802DE10: .4byte 0xFFFFFE00
_0802DE14: .4byte 0x000001FF
_0802DE18: .4byte gCurrentPinballGame
_0802DE1C: .4byte gUnknown_03005C00
_0802DE20: .4byte 0x0000033F
_0802DE24: .4byte 0x040000D4
_0802DE28: .4byte 0x06002000
_0802DE2C: .4byte 0x80000400
_0802DE30: .4byte gMain
_0802DE34: .4byte 0x000005A2
_0802DE38: .4byte gUnknown_083A562C
_0802DE3C: .4byte 0x06015800
_0802DE40: .4byte 0x80000C00
_0802DE44: .4byte gUnknown_083A6E4C
_0802DE48: .4byte 0x050003C0
_0802DE4C: .4byte 0x80000010
_0802DE50: .4byte 0x000006DB

	thumb_func_start sub_2DE54
sub_2DE54: @ 0x0802DE54
	ldr r4, _0802DED4 @ =0xFFFFFE98
	adds r0, r3, r4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x40
	bgt _0802DEF0
	cmp r4, #1
	bne _0802DE6A
	ldr r0, _0802DED8 @ =gMPlayInfo_BGM
	bl m4aMPlayStop
_0802DE6A:
	ldr r5, _0802DEDC @ =gMain
	ldrh r0, [r5, #0x38]
	movs r0, #0x9f
	strh r0, [r5, #0x38]
	adds r0, r4, #0
	cmp r4, #0
	bge _0802DE7A
	adds r0, r4, #3
_0802DE7A:
	asrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r5, #0x3c]
	strh r1, [r5, #0x3c]
	cmp r4, #0x20
	bne _0802DEB0
	ldr r0, _0802DEE0 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r2, r1, r3
	movs r0, #0x8c
	strh r0, [r2]
	ldr r2, _0802DEE4 @ =gSpeciesInfo
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	bl PlayCry_Normal
_0802DEB0:
	cmp r4, #0x40
	beq _0802DEB6
	b _0802E052
_0802DEB6:
	ldr r2, _0802DEE0 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0802DEE8 @ =0x00000604
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	ldr r4, _0802DEEC @ =0x00000603
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x94
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	b _0802E052
	.align 2, 0
_0802DED4: .4byte 0xFFFFFE98
_0802DED8: .4byte gMPlayInfo_BGM
_0802DEDC: .4byte gMain
_0802DEE0: .4byte gCurrentPinballGame
_0802DEE4: .4byte gSpeciesInfo
_0802DEE8: .4byte 0x00000604
_0802DEEC: .4byte 0x00000603
_0802DEF0:
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r2, r1
	movs r4, #0
	strb r4, [r0]
	ldr r2, _0802DF20 @ =gUnknown_086AE0D0
	ldr r3, _0802DF24 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r0, _0802DF28 @ =0x00000603
	adds r3, r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, _0802DF2C @ =0x00000604
	adds r1, r1, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _0802DF30
	adds r0, r2, #1
	strh r0, [r1]
	b _0802DF80
	.align 2, 0
_0802DF20: .4byte gUnknown_086AE0D0
_0802DF24: .4byte gCurrentPinballGame
_0802DF28: .4byte 0x00000603
_0802DF2C: .4byte 0x00000604
_0802DF30:
	strh r4, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r3, _0802E068 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r2, _0802E06C @ =0x00000603
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xa
	ble _0802DF80
	ldr r3, _0802E070 @ =gMain
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r0, [r0]
	strh r4, [r0]
	movs r0, #0xa
	strb r0, [r1]
	ldr r0, _0802E068 @ =gCurrentPinballGame
	ldr r1, [r0]
	strh r4, [r1, #0x18]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, _0802E074 @ =0x040000D4
	ldr r2, _0802E068 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _0802E078 @ =0x0000111A
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0802E07C @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _0802E080 @ =0x800000C0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_0802DF80:
	ldr r4, _0802E068 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r1, _0802E06C @ =0x00000603
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r4, _0802E070 @ =gMain
	ldr r0, [r4, #0x44]
	adds r0, #0x94
	ldr r7, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	strh r0, [r7, #2]
	adds r2, #0x5a
	ldrh r1, [r2]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0802DFC0
	movs r0, #0xc8
	strh r0, [r7, #4]
_0802DFC0:
	movs r6, #0
	lsls r0, r3, #0x10
	ldr r3, _0802E084 @ =gOamBuffer
	mov sb, r3
	ldr r4, _0802E088 @ =gUnknown_086B4E62
	mov r8, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r5, r0, #3
	ldr r0, _0802E08C @ =0xFFFFFE00
	mov sl, r0
_0802DFD8:
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r1, sb
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r5
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov ip, r1
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r1, r0, #0
	add r1, ip
	ldr r0, _0802E090 @ =0x000001FF
	mov ip, r0
	mov r0, ip
	ands r1, r0
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0802DFD8
_0802E052:
	movs r3, #0x88
	lsls r3, r3, #2
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E068: .4byte gCurrentPinballGame
_0802E06C: .4byte 0x00000603
_0802E070: .4byte gMain
_0802E074: .4byte 0x040000D4
_0802E078: .4byte 0x0000111A
_0802E07C: .4byte 0x05000200
_0802E080: .4byte 0x800000C0
_0802E084: .4byte gOamBuffer
_0802E088: .4byte gUnknown_086B4E62
_0802E08C: .4byte 0xFFFFFE00
_0802E090: .4byte 0x000001FF

	thumb_func_start sub_2E094
sub_2E094: @ 0x0802E094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r7, #0
	ldr r0, _0802E0FC @ =gCurrentPinballGame
	ldr r6, [r0]
	ldrh r3, [r6, #0x18]
	adds r2, r3, #0
	mov sb, r0
	cmp r2, #0
	bne _0802E180
	ldr r2, _0802E100 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x40]
	movs r0, #1
	strh r0, [r1]
	ldr r0, _0802E104 @ =0x0000060C
	adds r1, r6, r0
	subs r0, #0x94
	strh r0, [r1]
	ldr r3, _0802E108 @ =0x0000060E
	adds r1, r6, r3
	ldr r0, _0802E10C @ =0x0000FDA8
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0xe4
	movs r0, #0x15
	strb r0, [r1]
	ldrb r0, [r2, #4]
	cmp r0, #0
	bne _0802E130
	ldr r1, _0802E110 @ =0x040000D4
	ldr r0, _0802E114 @ =gUnknown_081BCAA4
	str r0, [r1]
	ldr r2, _0802E118 @ =0x06015800
	str r2, [r1, #4]
	ldr r0, _0802E11C @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802E120 @ =gUnknown_081BE2C4
	str r0, [r1]
	ldr r0, _0802E124 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0802E128 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802E12C @ =gUnknown_08483D8C
	b _0802E150
	.align 2, 0
_0802E0FC: .4byte gCurrentPinballGame
_0802E100: .4byte gMain
_0802E104: .4byte 0x0000060C
_0802E108: .4byte 0x0000060E
_0802E10C: .4byte 0x0000FDA8
_0802E110: .4byte 0x040000D4
_0802E114: .4byte gUnknown_081BCAA4
_0802E118: .4byte 0x06015800
_0802E11C: .4byte 0x80000C00
_0802E120: .4byte gUnknown_081BE2C4
_0802E124: .4byte 0x050003C0
_0802E128: .4byte 0x80000010
_0802E12C: .4byte gUnknown_08483D8C
_0802E130:
	ldr r1, _0802E15C @ =0x040000D4
	ldr r0, _0802E160 @ =gUnknown_081BE4C4
	str r0, [r1]
	ldr r2, _0802E164 @ =0x06015800
	str r2, [r1, #4]
	ldr r0, _0802E168 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802E16C @ =gUnknown_081BFCE4
	str r0, [r1]
	ldr r0, _0802E170 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0802E174 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802E178 @ =gUnknown_08488A0C
_0802E150:
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _0802E17C @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0802E610
	.align 2, 0
_0802E15C: .4byte 0x040000D4
_0802E160: .4byte gUnknown_081BE4C4
_0802E164: .4byte 0x06015800
_0802E168: .4byte 0x80000C00
_0802E16C: .4byte gUnknown_081BFCE4
_0802E170: .4byte 0x050003C0
_0802E174: .4byte 0x80000010
_0802E178: .4byte gUnknown_08488A0C
_0802E17C: .4byte 0x80000240
_0802E180:
	cmp r2, #0x3b
	bhi _0802E234
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0xe
	movs r1, #0x3c
	bl __divsi3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Cos
	adds r1, r0, #0
	mov r6, sb
	ldr r5, [r6]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r6, _0802E218 @ =0x00004E20
	adds r1, r6, #0
	bl __divsi3
	ldr r7, _0802E21C @ =0x000001E7
	adds r0, r0, r7
	ldr r1, _0802E220 @ =0x0000060C
	adds r5, r5, r1
	strh r0, [r5]
	adds r0, r4, #0
	bl Sin
	mov r2, sb
	ldr r4, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r1, r6, #0
	bl __divsi3
	ldr r3, _0802E224 @ =0xFFFFFD8B
	adds r0, r0, r3
	ldr r5, _0802E228 @ =0x0000060E
	adds r1, r4, r5
	strh r0, [r1]
	movs r6, #0xc2
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r0, _0802E22C @ =0x0000FFEF
	strh r0, [r1]
	ldr r7, _0802E230 @ =0x00000612
	adds r1, r4, r7
	subs r0, #0xd
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	movs r1, #3
	ands r1, r0
	lsrs r7, r1, #1
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802E210
	b _0802E4E0
_0802E210:
	movs r0, 0x97 @=SE_UNKNOWN_0x97
	bl m4aSongNumStart
	b _0802E4E0
	.align 2, 0
_0802E218: .4byte 0x00004E20
_0802E21C: .4byte 0x000001E7
_0802E220: .4byte 0x0000060C
_0802E224: .4byte 0xFFFFFD8B
_0802E228: .4byte 0x0000060E
_0802E22C: .4byte 0x0000FFEF
_0802E230: .4byte 0x00000612
_0802E234:
	cmp r2, #0x59
	bhi _0802E2D0
	adds r0, r3, #0
	subs r0, #0x3c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	bgt _0802E25C
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r1, #2
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	b _0802E278
_0802E25C:
	subs r0, #0xc
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x12
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
_0802E278:
	ldr r4, _0802E2BC @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r0, _0802E2C0 @ =0x00000612
	adds r3, r1, r0
	ldrh r0, [r3]
	adds r0, #2
	movs r5, #0
	movs r2, #0
	mov r8, r2
	strh r0, [r3]
	ldr r6, _0802E2C4 @ =0x0000060C
	adds r2, r1, r6
	adds r6, #4
	adds r0, r1, r6
	ldrh r0, [r0]
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	ldr r0, _0802E2C8 @ =0x0000060E
	adds r2, r1, r0
	ldrh r0, [r3]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldr r6, _0802E2CC @ =0x0000060A
	adds r1, r1, r6
	strb r5, [r1]
	ldr r0, [r4]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r2, r8
	strh r2, [r0]
	b _0802E4E0
	.align 2, 0
_0802E2BC: .4byte gCurrentPinballGame
_0802E2C0: .4byte 0x00000612
_0802E2C4: .4byte 0x0000060C
_0802E2C8: .4byte 0x0000060E
_0802E2CC: .4byte 0x0000060A
_0802E2D0:
	cmp r2, #0xbd
	bls _0802E2D6
	b _0802E41C
_0802E2D6:
	ldr r2, _0802E300 @ =gUnknown_086AE394
	ldr r5, _0802E304 @ =0x0000060A
	adds r3, r6, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #4
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _0802E308
	adds r0, r2, #1
	strh r0, [r1]
	b _0802E37A
	.align 2, 0
_0802E300: .4byte gUnknown_086AE394
_0802E304: .4byte 0x0000060A
_0802E308:
	strh r7, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r3, sb
	ldr r4, [r3]
	ldr r6, _0802E3C4 @ =0x0000060A
	adds r0, r4, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0802E366
	ldr r3, _0802E3C8 @ =gUnknown_08055A68
	adds r0, r4, #0
	adds r0, #0x32
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldr r0, _0802E3CC @ =gMain
	ldrb r1, [r0, #4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x35
	strb r1, [r0]
	mov r7, sb
	ldr r1, [r7]
	ldr r2, _0802E3D0 @ =gUnknown_08137928
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _0802E3D4 @ =0x000006D9
	adds r1, r1, r2
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
_0802E366:
	mov r3, sb
	ldr r1, [r3]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xb
	bne _0802E37A
	movs r0, #0xbd
	strh r0, [r1, #0x18]
_0802E37A:
	ldr r2, _0802E3D8 @ =gUnknown_086AE394
	ldr r0, _0802E3DC @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r5, _0802E3C4 @ =0x0000060A
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r2, #2
	adds r0, r1, r0
	ldrh r7, [r0]
	adds r2, #4
	adds r1, r1, r2
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #5
	bne _0802E3B4
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _0802E3B4
	movs r0, 0x98 @=SE_UNKNOWN_0x98
	bl m4aSongNumStart
_0802E3B4:
	cmp r7, #0x10
	bne _0802E3E8
	ldr r0, _0802E3DC @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0802E3E0 @ =0x0000060C
	adds r0, r0, r2
	ldr r1, _0802E3E4 @ =0x0000FFB0
	b _0802E3F2
	.align 2, 0
_0802E3C4: .4byte 0x0000060A
_0802E3C8: .4byte gUnknown_08055A68
_0802E3CC: .4byte gMain
_0802E3D0: .4byte gUnknown_08137928
_0802E3D4: .4byte 0x000006D9
_0802E3D8: .4byte gUnknown_086AE394
_0802E3DC: .4byte gCurrentPinballGame
_0802E3E0: .4byte 0x0000060C
_0802E3E4: .4byte 0x0000FFB0
_0802E3E8:
	ldr r0, _0802E40C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r3, _0802E410 @ =0x0000060C
	adds r0, r0, r3
	movs r1, #0
_0802E3F2:
	strh r1, [r0]
	ldr r0, _0802E40C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r5, #0xc2
	lsls r5, r5, #3
	adds r2, r1, r5
	ldr r0, _0802E414 @ =0x0000FFE8
	strh r0, [r2]
	ldr r6, _0802E418 @ =0x00000612
	adds r1, r1, r6
	movs r0, #0xe
	strh r0, [r1]
	b _0802E4E0
	.align 2, 0
_0802E40C: .4byte gCurrentPinballGame
_0802E410: .4byte 0x0000060C
_0802E414: .4byte 0x0000FFE8
_0802E418: .4byte 0x00000612
_0802E41C:
	ldr r0, _0802E454 @ =0x000001AD
	cmp r2, r0
	bhi _0802E496
	adds r0, r3, #0
	subs r0, #0xbe
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0x17
	bgt _0802E45C
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	rsbs r0, r0, #0
	ldr r7, _0802E458 @ =0x0000060C
	adds r1, r6, r7
	strh r0, [r1]
	adds r0, r3, #0
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0802E44E
	adds r0, #3
_0802E44E:
	asrs r0, r0, #2
	adds r0, #2
	b _0802E48C
	.align 2, 0
_0802E454: .4byte 0x000001AD
_0802E458: .4byte 0x0000060C
_0802E45C:
	cmp r3, #0x1d
	bgt _0802E46E
	movs r7, #0xc
	cmp r3, #0x18
	bne _0802E4E0
	movs r0, 0x11 @ =MUS_SUCCESS
	bl m4aSongNumStart
	b _0802E4E0
_0802E46E:
	cmp r3, #0x29
	bgt _0802E492
	adds r0, r3, #0
	subs r0, #0x1e
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #6
	bl __divsi3
	adds r0, #0xd
_0802E48C:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	b _0802E4E0
_0802E492:
	movs r7, #0xf
	b _0802E4E0
_0802E496:
	ldr r0, _0802E4F8 @ =0x000001E9
	cmp r2, r0
	bhi _0802E4E0
	ldrh r0, [r6, #0x18]
	movs r1, #3
	ands r0, r1
	lsrs r7, r0, #1
	ldr r0, _0802E4FC @ =0x00000612
	adds r2, r6, r0
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	ldr r3, _0802E500 @ =0x0000060C
	adds r1, r6, r3
	movs r5, #0xc2
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	subs r5, #2
	adds r1, r6, r5
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r6, #0x18]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0802E4E0
	movs r0, 0x97 @=SE_UNKNOWN_0x97
	bl m4aSongNumStart
_0802E4E0:
	ldr r0, _0802E504 @ =gMain
	ldrb r1, [r0, #4]
	cmp r1, #0
	bne _0802E510
	ldr r2, _0802E508 @ =0x040000D4
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0802E50C @ =gUnknown_08483D8C
	b _0802E51E
	.align 2, 0
_0802E4F8: .4byte 0x000001E9
_0802E4FC: .4byte 0x00000612
_0802E500: .4byte 0x0000060C
_0802E504: .4byte gMain
_0802E508: .4byte 0x040000D4
_0802E50C: .4byte gUnknown_08483D8C
_0802E510:
	ldr r2, _0802E640 @ =0x040000D4
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0802E644 @ =gUnknown_08488A0C
_0802E51E:
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802E648 @ =0x06015800
	str r0, [r2, #4]
	ldr r0, _0802E64C @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r2, _0802E650 @ =gUnknown_086AE394
	ldr r5, _0802E654 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r3, _0802E658 @ =0x0000060A
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r7, [r0]
	ldr r6, _0802E65C @ =gMain
	ldr r0, [r6, #0x44]
	ldr r6, [r0, #0x40]
	ldr r1, _0802E660 @ =0x0000060C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x60
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _0802E664 @ =0x0000060E
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	mov sb, r5
	ldr r3, _0802E668 @ =gOamBuffer
	mov r8, r3
	ldr r5, _0802E66C @ =gUnknown_086B3FE6
	mov ip, r5
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	str r0, [sp]
	ldr r7, _0802E670 @ =0xFFFFFE00
	mov sl, r7
_0802E59C:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r6, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, r8
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	ldr r5, [sp]
	adds r0, r0, r5
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r5
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, r8
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _0802E674 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sl
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _0802E59C
_0802E610:
	mov r3, sb
	ldr r4, [r3]
	ldrh r1, [r4, #0x18]
	ldr r0, _0802E678 @ =0x000001E9
	cmp r1, r0
	bne _0802E62E
	ldr r5, _0802E65C @ =gMain
	ldr r0, [r5, #0x44]
	ldr r1, [r0, #0x40]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe4
	strb r2, [r0]
_0802E62E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E640: .4byte 0x040000D4
_0802E644: .4byte gUnknown_08488A0C
_0802E648: .4byte 0x06015800
_0802E64C: .4byte 0x80000240
_0802E650: .4byte gUnknown_086AE394
_0802E654: .4byte gCurrentPinballGame
_0802E658: .4byte 0x0000060A
_0802E65C: .4byte gMain
_0802E660: .4byte 0x0000060C
_0802E664: .4byte 0x0000060E
_0802E668: .4byte gOamBuffer
_0802E66C: .4byte gUnknown_086B3FE6
_0802E670: .4byte 0xFFFFFE00
_0802E674: .4byte 0x000001FF
_0802E678: .4byte 0x000001E9