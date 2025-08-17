#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

    thumb_func_start sub_1D5D8
sub_1D5D8: @ 0x0801D5D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0801D60C @ =gMain+0x3600 @gMain.spriteGroups[71]
	mov sb, r0
	movs r1, #0
	mov r8, r1
	movs r5, #0
	ldr r1, _0801D610 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0801D614 @ =0x000002FB
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bls _0801D600
	b _0801D930
_0801D600:
	lsls r0, r0, #2
	ldr r1, _0801D618 @ =_0801D61C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D60C: .4byte gMain+0x3600 @gMain.spriteGroups[71]
_0801D610: .4byte gCurrentPinballGame
_0801D614: .4byte 0x000002FB
_0801D618: .4byte _0801D61C
_0801D61C: @ jump table
	.4byte _0801D63C @ case 0
	.4byte _0801D65C @ case 1
	.4byte _0801D6C4 @ case 2
	.4byte _0801D760 @ case 3
	.4byte _0801D7C8 @ case 4
	.4byte _0801D860 @ case 5
	.4byte _0801D860 @ case 6
	.4byte _0801D8E0 @ case 7
_0801D63C:
	ldr r0, _0801D658 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x24
	bl __umodsi3
	movs r1, #0x12
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r5, r8
	b _0801D930
	.align 2, 0
_0801D658: .4byte gMain
_0801D65C:
	ldr r4, _0801D6AC @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r3, _0801D6B0 @ =0x000002FE
	adds r2, r1, r3
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldr r5, _0801D6B4 @ =0x000002FD
	adds r1, r1, r5
	strb r3, [r1]
	ldr r0, [r4]
	ldr r7, _0801D6B8 @ =0x000002FB
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
	ldr r2, _0801D6BC @ =gUnknown_086AD7C0
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r0, 0xCF @=SE_UNKNOWN_0xCF
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	ldr r0, _0801D6C0 @ =0x0000C350
	str r0, [r1, #0x3c]
	b _0801D930
	.align 2, 0
_0801D6AC: .4byte gCurrentPinballGame
_0801D6B0: .4byte 0x000002FE
_0801D6B4: .4byte 0x000002FD
_0801D6B8: .4byte 0x000002FB
_0801D6BC: .4byte gUnknown_086AD7C0
_0801D6C0: .4byte 0x0000C350
_0801D6C4:
	ldr r3, _0801D6F0 @ =gUnknown_086AD7C0
	ldr r0, _0801D6F4 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r6, _0801D6F8 @ =0x000002FD
	adds r4, r2, r6
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _0801D6FC @ =0x000002FE
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801D700
	adds r0, r1, #1
	strh r0, [r2]
	b _0801D736
	.align 2, 0
_0801D6F0: .4byte gUnknown_086AD7C0
_0801D6F4: .4byte gCurrentPinballGame
_0801D6F8: .4byte 0x000002FD
_0801D6FC: .4byte 0x000002FE
_0801D700:
	movs r5, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r7, _0801D754 @ =gCurrentPinballGame
	ldr r1, [r7]
	ldr r2, _0801D758 @ =0x000002FD
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801D736
	ldr r7, _0801D75C @ =0x000002FB
	adds r0, r1, r7
	strb r5, [r0]
	ldr r1, _0801D754 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r6
	strb r5, [r0]
	ldr r0, [r1]
	subs r2, #4
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
_0801D736:
	ldr r0, _0801D754 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r5, _0801D758 @ =0x000002FD
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrh r5, [r1]
	adds r1, r3, #4
	adds r0, r0, r1
	b _0801D92C
	.align 2, 0
_0801D754: .4byte gCurrentPinballGame
_0801D758: .4byte 0x000002FD
_0801D75C: .4byte 0x000002FB
_0801D760:
	ldr r4, _0801D7B0 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r7, _0801D7B4 @ =0x000002FE
	adds r2, r1, r7
	movs r0, #0
	strh r0, [r2]
	ldr r3, _0801D7B8 @ =0x000002FD
	adds r1, r1, r3
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801D7BC @ =0x000002FB
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _0801D7C0 @ =gUnknown_086AD7C0
	ldr r0, [r4]
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r0
	movs r0, 0xCF @=SE_UNKNOWN_0xCF
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	ldr r0, _0801D7C4 @ =0x000186A0
	str r0, [r1, #0x3c]
	b _0801D930
	.align 2, 0
_0801D7B0: .4byte gCurrentPinballGame
_0801D7B4: .4byte 0x000002FE
_0801D7B8: .4byte 0x000002FD
_0801D7BC: .4byte 0x000002FB
_0801D7C0: .4byte gUnknown_086AD7C0
_0801D7C4: .4byte 0x000186A0
_0801D7C8:
	ldr r2, _0801D7F4 @ =gUnknown_086AD7C0
	ldr r5, _0801D7F8 @ =gCurrentPinballGame
	ldr r3, [r5]
	ldr r7, _0801D7FC @ =0x000002FD
	adds r4, r3, r7
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, _0801D800 @ =0x000002FE
	adds r3, r3, r2
	ldrh r1, [r3]
	cmp r0, r1
	ble _0801D804
	adds r0, r1, #1
	strh r0, [r3]
	b _0801D82C
	.align 2, 0
_0801D7F4: .4byte gUnknown_086AD7C0
_0801D7F8: .4byte gCurrentPinballGame
_0801D7FC: .4byte 0x000002FD
_0801D800: .4byte 0x000002FE
_0801D804:
	movs r0, #0
	strh r0, [r3]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, [r5]
	ldr r3, _0801D84C @ =0x000002FD
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x12
	bne _0801D82C
	ldr r5, _0801D850 @ =0x000002FB
	adds r1, r1, r5
	movs r0, #5
	strb r0, [r1]
	movs r0, 0xD1 @=SE_UNKNOWN_0xD1
	bl m4aSongNumStart
_0801D82C:
	ldr r4, _0801D854 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r7, _0801D858 @ =0x000002FE
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #6
	bne _0801D840
	movs r0, 0xD0 @=SE_UNKNOWN_0xD0
	bl m4aSongNumStart
_0801D840:
	ldr r2, _0801D85C @ =gUnknown_086AD7C0
	ldr r0, [r4]
	ldr r1, _0801D84C @ =0x000002FD
	adds r0, r0, r1
	b _0801D91A
	.align 2, 0
_0801D84C: .4byte 0x000002FD
_0801D850: .4byte 0x000002FB
_0801D854: .4byte gCurrentPinballGame
_0801D858: .4byte 0x000002FE
_0801D85C: .4byte gUnknown_086AD7C0
_0801D860:
	ldr r3, _0801D88C @ =gUnknown_086AD7C0
	ldr r5, _0801D890 @ =gCurrentPinballGame
	ldr r2, [r5]
	ldr r7, _0801D894 @ =0x000002FD
	adds r4, r2, r7
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r3, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _0801D898 @ =0x000002FE
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801D89C
	adds r0, r1, #1
	strh r0, [r2]
	b _0801D8BA
	.align 2, 0
_0801D88C: .4byte gUnknown_086AD7C0
_0801D890: .4byte gCurrentPinballGame
_0801D894: .4byte 0x000002FD
_0801D898: .4byte 0x000002FE
_0801D89C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r7, _0801D8D8 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r2, _0801D8DC @ =0x000002FD
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x18
	bne _0801D8BA
	movs r0, #0x12
	strb r0, [r1]
_0801D8BA:
	ldr r0, _0801D8D8 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r5, _0801D8DC @ =0x000002FD
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrh r5, [r1]
	adds r1, r3, #4
	adds r0, r0, r1
	b _0801D92C
	.align 2, 0
_0801D8D8: .4byte gCurrentPinballGame
_0801D8DC: .4byte 0x000002FD
_0801D8E0:
	ldr r4, _0801DA3C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r7, _0801DA40 @ =0x000002FA
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _0801DA44 @ =0x000002F9
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0801DA48 @ =0x000002FE
	adds r2, r0, r3
	movs r5, #0
	strh r1, [r2]
	subs r3, #1
	adds r0, r0, r3
	strb r5, [r0]
	ldr r0, [r4]
	adds r7, #1
	adds r0, r0, r7
	strb r5, [r0]
	ldr r0, [r4]
	adds r0, r0, r3
	movs r1, #0x18
	strb r1, [r0]
	ldr r2, _0801DA4C @ =gUnknown_086AD7C0
	ldr r0, [r4]
	adds r0, r0, r3
_0801D91A:
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrh r5, [r1]
	adds r2, #4
	adds r0, r0, r2
_0801D92C:
	ldrh r0, [r0]
	mov r8, r0
_0801D930:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801DA20
	ldr r2, _0801DA50 @ =gUnknown_086AD856
	ldr r3, _0801DA3C @ =gCurrentPinballGame
	ldr r4, [r3]
	ldr r7, _0801DA44 @ =0x000002F9
	adds r3, r4, r7
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sb
	strh r0, [r2, #4]
	ldr r2, _0801DA54 @ =0x040000D4
	movs r3, #0xbf
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DA58 @ =gUnknown_0845710C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DA5C @ =0x06014380
	str r0, [r2, #4]
	ldr r0, _0801DA60 @ =0x80000130
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0
	lsls r1, r5, #0x10
	ldr r5, _0801DA64 @ =gOamBuffer
	mov ip, r5
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r6, r0, #2
	ldr r7, _0801DA68 @ =0xFFFFFE00
	mov sl, r7
_0801D9A6:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldr r5, _0801DA6C @ =gUnknown_086B2E64
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r1, r1, r5
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r7, [r2, #2]
	lsls r1, r7, #0x17
	lsrs r1, r1, #0x17
	mov r5, sb
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _0801DA70 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, sl
	ldrh r7, [r2, #2]
	ands r0, r7
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r1]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _0801D9A6
_0801DA20:
	ldr r7, _0801DA3C @ =gCurrentPinballGame
	ldr r0, [r7]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, r8
	strb r2, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DA3C: .4byte gCurrentPinballGame
_0801DA40: .4byte 0x000002FA
_0801DA44: .4byte 0x000002F9
_0801DA48: .4byte 0x000002FE
_0801DA4C: .4byte gUnknown_086AD7C0
_0801DA50: .4byte gUnknown_086AD856
_0801DA54: .4byte 0x040000D4
_0801DA58: .4byte gUnknown_0845710C
_0801DA5C: .4byte 0x06014380
_0801DA60: .4byte 0x80000130
_0801DA64: .4byte gOamBuffer
_0801DA68: .4byte 0xFFFFFE00
_0801DA6C: .4byte gUnknown_086B2E64
_0801DA70: .4byte 0x000001FF

	thumb_func_start sub_1DA74
sub_1DA74: @ 0x0801DA74
	ldr r0, _0801DAB0 @ =gCurrentPinballGame
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	beq _0801DAD4
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _0801DAC6
	ldr r1, _0801DAB4 @ =0x000001A5
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801DABC
	ldr r3, _0801DAB8 @ =0x000001AB
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	b _0801DAD4
	.align 2, 0
_0801DAB0: .4byte gCurrentPinballGame
_0801DAB4: .4byte 0x000001A5
_0801DAB8: .4byte 0x000001AB
_0801DABC:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #3
	b _0801DAD2
_0801DAC6:
	cmp r0, #6
	beq _0801DAD4
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0
_0801DAD2:
	strb r0, [r1]
_0801DAD4:
	bx lr

	thumb_func_start sub_1DAD8
sub_1DAD8: @ 0x0801DAD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0801DB64 @ =gMain+0x31B0 @gMain.spriteGroups[65]
	mov r8, r0
	ldr r0, _0801DB68 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r5, #0xf
	ldr r7, _0801DB6C @ =0x000002F1
	adds r3, r4, r7
	ldrb r2, [r3]
	ands r5, r1
	adds r1, r2, #0
	adds r7, r0, #0
	cmp r5, r1
	beq _0801DBAC
	ldr r6, _0801DB70 @ =0x000002F2
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801DB78
	cmp r0, #5
	bne _0801DB58
	ldr r3, _0801DB74 @ =0xFFFFCE50
	add r3, r8
	ldrb r1, [r3, #0xf]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r3, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r3, #0
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	adds r0, #8
	strh r2, [r0]
	adds r0, #4
	strb r3, [r0]
	ldr r0, [r7]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r3, [r0]
	movs r0, 0xBD @=SE_UNKNOWN_0xBD
	bl m4aSongNumStart
_0801DB58:
	ldr r1, [r7]
	adds r1, r1, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _0801DBAC
	.align 2, 0
_0801DB64: .4byte gMain+0x31B0 @gMain.spriteGroups[65]
_0801DB68: .4byte gCurrentPinballGame
_0801DB6C: .4byte 0x000002F1
_0801DB70: .4byte 0x000002F2
_0801DB74: .4byte 0xFFFFCE50
_0801DB78:
	cmp r1, r5
	bls _0801DB80
	subs r0, r2, #1
	b _0801DB82
_0801DB80:
	adds r0, r2, #1
_0801DB82:
	strb r0, [r3]
	ldr r0, [r7]
	adds r0, r0, r6
	movs r1, #4
	strh r1, [r0]
	ldr r2, _0801DC58 @ =0x040000D4
	ldr r0, [r7]
	ldr r1, _0801DC5C @ =0x000002F1
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DC60 @ =gUnknown_084ED0CC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DC64 @ =0x06013180
	str r0, [r2, #4]
	ldr r0, _0801DC68 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801DBAC:
	ldr r2, [r7]
	ldr r7, _0801DC5C @ =0x000002F1
	adds r0, r2, r7
	ldrb r0, [r0]
	movs r3, #2
	cmp r0, #2
	bhi _0801DBBC
	movs r3, #3
_0801DBBC:
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xd0
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x50
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r0, #0
	ldr r7, _0801DC6C @ =gMain+0x31B8 @gMain.spriteGroups[65].oam
	mov sl, r7
	ldr r6, _0801DC70 @ =gOamBuffer
	lsls r3, r3, #2
	str r3, [sp]
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
	ldr r2, _0801DC74 @ =0xFFFFFE00
	mov ip, r2
_0801DBEE:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	add r5, sl
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sb
	ands r0, r2
	ldr r7, [sp]
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	mov r2, r8
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0801DC78 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r7, r8
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801DBEE
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DC58: .4byte 0x040000D4
_0801DC5C: .4byte 0x000002F1
_0801DC60: .4byte gUnknown_084ED0CC
_0801DC64: .4byte 0x06013180
_0801DC68: .4byte 0x800000C0
_0801DC6C: .4byte gMain+0x31B8 @gMain.spriteGroups[65].oam
_0801DC70: .4byte gOamBuffer
_0801DC74: .4byte 0xFFFFFE00
_0801DC78: .4byte 0x000001FF

	thumb_func_start sub_1DC7C
sub_1DC7C: @ 0x0801DC7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r6, _0801DD7C @ =gMain+0x3040 @gMain.spriteGroups[63]
	ldr r2, _0801DD80 @ =gCurrentPinballGame
	ldr r3, [r2]
	ldr r1, _0801DD84 @ =0x000002A5
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0801DD88 @ =gUnknown_086AD862
	adds r4, r0, r1
	ldrh r0, [r6]
	mov sb, r2
	cmp r0, #0
	bne _0801DCA4
	b _0801DDCC
_0801DCA4:
	ldrh r2, [r4]
	mov r8, r2
	ldr r2, _0801DD8C @ =0x040000D4
	adds r0, r3, #0
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801DD90 @ =gUnknown_081379D8
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DD94 @ =0x05000320
	str r0, [r2, #4]
	ldr r0, _0801DD98 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r0, r8
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0801DD9C @ =gUnknown_084B7FEC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801DDA0 @ =0x06014680
	str r0, [r2, #4]
	ldr r0, _0801DDA4 @ =0x80000230
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, _0801DDA8 @ =0x0000FF08
	strh r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0801DDAC @ =0x0000FEC4
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x7c
	adds r1, r3, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #6]
	adds r0, #0x96
	adds r1, r3, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0801DDB0 @ =gOamBuffer
	ldr r1, _0801DDB4 @ =0xFFFFFE00
	mov ip, r1
_0801DD1C:
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
	ldr r2, _0801DDB8 @ =0x000001FF
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
	cmp r5, #3
	ble _0801DD1C
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	beq _0801DD6E
	cmp r0, #0xa
	bne _0801DDC0
_0801DD6E:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, _0801DDBC @ =0x000002A3
	adds r0, r0, r1
	movs r1, #0
	b _0801DDCA
	.align 2, 0
_0801DD7C: .4byte gMain+0x3040 @gMain.spriteGroups[63]
_0801DD80: .4byte gCurrentPinballGame
_0801DD84: .4byte 0x000002A5
_0801DD88: .4byte gUnknown_086AD862
_0801DD8C: .4byte 0x040000D4
_0801DD90: .4byte gUnknown_081379D8
_0801DD94: .4byte 0x05000320
_0801DD98: .4byte 0x80000010
_0801DD9C: .4byte gUnknown_084B7FEC
_0801DDA0: .4byte 0x06014680
_0801DDA4: .4byte 0x80000230
_0801DDA8: .4byte 0x0000FF08
_0801DDAC: .4byte 0x0000FEC4
_0801DDB0: .4byte gOamBuffer
_0801DDB4: .4byte 0xFFFFFE00
_0801DDB8: .4byte 0x000001FF
_0801DDBC: .4byte 0x000002A3
_0801DDC0:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, _0801DDD8 @ =0x000002A3
	adds r0, r0, r1
	movs r1, #1
_0801DDCA:
	strb r1, [r0]
_0801DDCC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DDD8: .4byte 0x000002A3

	thumb_func_start sub_1DDDC
sub_1DDDC: @ 0x0801DDDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, _0801DE70 @ =gCurrentPinballGame
	ldr r4, [r1]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	ldrsb r3, [r0, r3]
	mov sl, r1
	cmp r3, #0
	bne _0801DDFE
	b _0801E518
_0801DDFE:
	movs r0, #0x13
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _0801DE0E
	ldr r3, _0801DE74 @ =0x0000016F
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0801DE0E:
	mov r4, sl
	ldr r1, [r4]
	ldr r3, _0801DE74 @ =0x0000016F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801DE4E
	ldr r5, _0801DE78 @ =0x000002A2
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _0801DE44
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0801DE7C @ =0x000002A5
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _0801DE80 @ =0x000002A6
	adds r0, r0, r4
	strh r2, [r0]
_0801DE44:
	mov r5, sl
	ldr r0, [r5]
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
_0801DE4E:
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _0801DE78 @ =0x000002A2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bls _0801DE64
	bl _0801E780
_0801DE64:
	lsls r0, r0, #2
	ldr r1, _0801DE84 @ =_0801DE88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801DE70: .4byte gCurrentPinballGame
_0801DE74: .4byte 0x0000016F
_0801DE78: .4byte 0x000002A2
_0801DE7C: .4byte 0x000002A5
_0801DE80: .4byte 0x000002A6
_0801DE84: .4byte _0801DE88
_0801DE88: @ jump table
	.4byte _0801DEB4 @ case 0
	.4byte _0801DF2C @ case 1
	.4byte _0801DF68 @ case 2
	.4byte _0801DFC0 @ case 3
	.4byte _0801E0D0 @ case 4
	.4byte _0801E174 @ case 5
	.4byte _0801E1B4 @ case 6
	.4byte _0801E2F8 @ case 7
	.4byte _0801E34C @ case 8
	.4byte _0801E44C @ case 9
	.4byte _0801E4CC @ case 10
_0801DEB4:
	ldr r1, _0801DF18 @ =gUnknown_086AD862
	ldr r4, _0801DF1C @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801DF20 @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801DF24 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801DED8
	b _0801E46E
_0801DED8:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	ldr r2, _0801DF20 @ =0x000002A5
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801DEFA
	ldr r3, _0801DF28 @ =0x000002A2
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
_0801DEFA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _0801DF0C
	bl _0801E780
_0801DF0C:
	movs r0, 0xD3 @=SE_UNKNOWN_0xD3
	bl m4aSongNumStart
	bl _0801E780
	.align 2, 0
_0801DF18: .4byte gUnknown_086AD862
_0801DF1C: .4byte gCurrentPinballGame
_0801DF20: .4byte 0x000002A5
_0801DF24: .4byte 0x000002A6
_0801DF28: .4byte 0x000002A2
_0801DF2C:
	ldr r6, _0801DF5C @ =gCurrentPinballGame
	ldr r4, [r6]
	ldr r5, _0801DF60 @ =0x000002A6
	adds r0, r4, r5
	ldrh r0, [r0]
	movs r1, #0x2c
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x16
	bl __udivsi3
	adds r0, #4
	ldr r1, _0801DF64 @ =0x000002A5
	adds r4, r4, r1
	strb r0, [r4]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl _0801E780
	.align 2, 0
_0801DF5C: .4byte gCurrentPinballGame
_0801DF60: .4byte 0x000002A6
_0801DF64: .4byte 0x000002A5
_0801DF68:
	ldr r2, _0801DFA8 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _0801DFAC @ =0x000002A5
	adds r0, r0, r3
	movs r3, #0
	movs r1, #6
	strb r1, [r0]
	ldr r1, [r2]
	ldr r4, _0801DFB0 @ =0x000002A6
	adds r0, r1, r4
	movs r4, #0
	strh r3, [r0]
	ldr r5, _0801DFB4 @ =0x000002A2
	adds r1, r1, r5
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, _0801DFB8 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	strb r4, [r0, #1]
	ldr r1, [r2]
	ldr r0, _0801DFBC @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, 0xD5 @=SE_UNKNOWN_0xD5
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	bl _0801E780
	.align 2, 0
_0801DFA8: .4byte gCurrentPinballGame
_0801DFAC: .4byte 0x000002A5
_0801DFB0: .4byte 0x000002A6
_0801DFB4: .4byte 0x000002A2
_0801DFB8: .4byte 0x0000132C
_0801DFBC: .4byte 0x00001388
_0801DFC0:
	ldr r1, _0801DFE8 @ =gUnknown_086AD862
	ldr r4, _0801DFEC @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r6, _0801DFF0 @ =0x000002A5
	adds r3, r2, r6
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r5, _0801DFF4 @ =0x000002A6
	adds r2, r2, r5
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801DFF8
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E038
	.align 2, 0
_0801DFE8: .4byte gUnknown_086AD862
_0801DFEC: .4byte gCurrentPinballGame
_0801DFF0: .4byte 0x000002A5
_0801DFF4: .4byte 0x000002A6
_0801DFF8:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E0C0 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xd
	bne _0801E024
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, [r4]
	adds r2, r1, r5
	movs r0, #0x41
	strh r0, [r2]
	ldr r3, _0801E0C4 @ =0x000002A2
	adds r1, r1, r3
	movs r0, #4
	strb r0, [r1]
_0801E024:
	ldr r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _0801E038
	movs r0, 0xD4 @=SE_UNKNOWN_0xD4
	bl m4aSongNumStart
_0801E038:
	ldr r5, _0801E0C8 @ =gCurrentPinballGame
	ldr r2, [r5]
	ldr r4, _0801E0C0 @ =0x000002A5
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801E070
	ldr r0, _0801E0CC @ =0x0000132C
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	adds r0, #0x40
	movs r3, #0
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x89
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xbd
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
_0801E070:
	ldr r2, [r5]
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0801E0A4
	ldr r1, _0801E0CC @ =0x0000132C
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	adds r0, #0x40
	movs r3, #0
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x8c
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xb7
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
_0801E0A4:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	beq _0801E0B4
	b _0801E780
_0801E0B4:
	ldr r2, _0801E0CC @ =0x0000132C
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1]
	b _0801E780
	.align 2, 0
_0801E0C0: .4byte 0x000002A5
_0801E0C4: .4byte 0x000002A2
_0801E0C8: .4byte gCurrentPinballGame
_0801E0CC: .4byte 0x0000132C
_0801E0D0:
	ldr r5, _0801E154 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r3, #0x88
	lsls r3, r3, #5
	adds r0, r0, r3
	movs r7, #1
	strb r7, [r0]
	ldr r0, [r5]
	ldr r6, _0801E158 @ =0x000002A6
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0x41
	bne _0801E0F8
	movs r0, 0x9F @=SE_UNKNOWN_0x9F
	bl m4aSongNumStart
	ldr r0, _0801E15C @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0x9e
	strh r1, [r0, #0x38]
_0801E0F8:
	ldr r4, [r5]
	adds r3, r4, r6
	ldrh r0, [r3]
	cmp r0, #0
	bne _0801E104
	b _0801E780
_0801E104:
	subs r0, #1
	strh r0, [r3]
	ldr r2, _0801E15C @ =gMain
	ldrh r0, [r3]
	lsrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r2, #0x3c]
	strh r1, [r2, #0x3c]
	ldrh r0, [r3]
	cmp r0, #0
	beq _0801E11E
	b _0801E780
_0801E11E:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0801E160 @ =0x00000282
	adds r0, r0, r1
	strb r7, [r0]
	ldr r0, [r5]
	ldr r2, _0801E164 @ =0x0000072E
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0801E168 @ =0x0000073C
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _0801E16C @ =0x0000072F
	adds r1, r0, r4
	ldrb r1, [r1]
	ldr r5, _0801E170 @ =0x0000073D
	adds r0, r0, r5
	strb r1, [r0]
	bl sub_1C73C
	b _0801E780
	.align 2, 0
_0801E154: .4byte gCurrentPinballGame
_0801E158: .4byte 0x000002A6
_0801E15C: .4byte gMain
_0801E160: .4byte 0x00000282
_0801E164: .4byte 0x0000072E
_0801E168: .4byte 0x0000073C
_0801E16C: .4byte 0x0000072F
_0801E170: .4byte 0x0000073D
_0801E174:
	ldr r2, _0801E1A0 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _0801E1A4 @ =0x000002A5
	adds r0, r0, r1
	movs r3, #0
	movs r1, #0xc
	strb r1, [r0]
	ldr r1, [r2]
	ldr r4, _0801E1A8 @ =0x000002A6
	adds r0, r1, r4
	movs r4, #0
	strh r3, [r0]
	ldr r5, _0801E1AC @ =0x000002A2
	adds r1, r1, r5
	movs r0, #6
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, _0801E1B0 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	strb r4, [r0, #1]
	b _0801E780
	.align 2, 0
_0801E1A0: .4byte gCurrentPinballGame
_0801E1A4: .4byte 0x000002A5
_0801E1A8: .4byte 0x000002A6
_0801E1AC: .4byte 0x000002A2
_0801E1B0: .4byte 0x0000132C
_0801E1B4:
	ldr r1, _0801E1DC @ =gUnknown_086AD862
	ldr r4, _0801E1E0 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801E1E4 @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E1E8 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E1EC
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E28A
	.align 2, 0
_0801E1DC: .4byte gUnknown_086AD862
_0801E1E0: .4byte gCurrentPinballGame
_0801E1E4: .4byte 0x000002A5
_0801E1E8: .4byte 0x000002A6
_0801E1EC:
	movs r6, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E2E4 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x1f
	bne _0801E212
	strb r6, [r1]
	ldr r0, [r4]
	ldr r3, _0801E2E8 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E212:
	ldr r2, [r4]
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _0801E24E
	ldr r0, _0801E2EC @ =0x0000132C
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	subs r0, #0x40
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xc7
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r1, [r2]
	ldr r0, _0801E2F0 @ =0x0000FF88
	strh r0, [r1, #0x30]
	ldr r1, [r2]
	movs r0, #0xd2
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	movs r0, #3
	strb r0, [r1, #1]
_0801E24E:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bne _0801E262
	movs r0, 0xD3 @=SE_UNKNOWN_0xD3
	bl m4aSongNumStart
_0801E262:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1b
	bne _0801E276
	movs r0, 0xD4 @=SE_UNKNOWN_0xD4
	bl m4aSongNumStart
_0801E276:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801E2CA
	movs r0, 0xD6 @=SE_UNKNOWN_0xD6
	bl m4aSongNumStart
_0801E28A:
	ldr r1, _0801E2F4 @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r2, _0801E2E4 @ =0x000002A5
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801E2CA
	ldr r2, _0801E2EC @ =0x0000132C
	adds r0, r3, r2
	ldr r0, [r0]
	movs r3, #0
	strb r3, [r0]
	ldr r1, [r1]
	adds r1, r1, r2
	ldr r2, [r1]
	ldrh r0, [r2, #0xa]
	subs r0, #0x40
	strh r0, [r2, #0xa]
	ldr r2, [r1]
	movs r0, #0x85
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r2, [r1]
	movs r0, #0xc0
	lsls r0, r0, #8
	str r0, [r2, #0x38]
	ldr r0, [r1]
	strh r3, [r0, #0x30]
	ldr r0, [r1]
	strh r3, [r0, #0x32]
_0801E2CA:
	ldr r0, _0801E2F4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _0801E2E4 @ =0x000002A5
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x16
	beq _0801E2DE
	b _0801E780
_0801E2DE:
	movs r0, #0
	strb r0, [r1, #0x1f]
	b _0801E780
	.align 2, 0
_0801E2E4: .4byte 0x000002A5
_0801E2E8: .4byte 0x000002A2
_0801E2EC: .4byte 0x0000132C
_0801E2F0: .4byte 0x0000FF88
_0801E2F4: .4byte gCurrentPinballGame
_0801E2F8:
	ldr r4, _0801E33C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _0801E340 @ =0x000002A5
	adds r0, r0, r5
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r3, _0801E344 @ =0x000002A6
	adds r1, r0, r3
	strh r2, [r1]
	subs r5, #3
	adds r0, r0, r5
	movs r1, #8
	strb r1, [r0]
	ldr r1, [r4]
	movs r0, #0xa
	str r0, [r1, #0x3c]
	movs r0, 0xB6 @=SE_UNKNOWN_0xB6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r0, [r4]
	ldr r2, _0801E348 @ =0x00000724
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _0801E336
	b _0801E780
_0801E336:
	movs r0, #1
	strh r0, [r1]
	b _0801E780
	.align 2, 0
_0801E33C: .4byte gCurrentPinballGame
_0801E340: .4byte 0x000002A5
_0801E344: .4byte 0x000002A6
_0801E348: .4byte 0x00000724
_0801E34C:
	ldr r1, _0801E374 @ =gUnknown_086AD862
	ldr r4, _0801E378 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801E37C @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E380 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E384
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E3D4
	.align 2, 0
_0801E374: .4byte gUnknown_086AD862
_0801E378: .4byte gCurrentPinballGame
_0801E37C: .4byte 0x000002A5
_0801E380: .4byte 0x000002A6
_0801E384:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E430 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x2e
	bne _0801E3AA
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801E434 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E3AA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x2a
	bne _0801E3BE
	movs r0, 0xD4 @=SE_UNKNOWN_0xD4
	bl m4aSongNumStart
_0801E3BE:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x21
	bne _0801E3D4
	movs r0, #0xa6
	lsls r0, r0, #1
	bl m4aSongNumStart
_0801E3D4:
	ldr r6, _0801E438 @ =gCurrentPinballGame
	ldr r4, [r6]
	ldr r5, _0801E430 @ =0x000002A5
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x2d
	beq _0801E3E8
	b _0801E780
_0801E3E8:
	ldr r3, _0801E43C @ =gUnknown_086AD9EC
	adds r5, #1
	adds r2, r4, r5
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r3, _0801E440 @ =0x000002AA
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0801E412
	ldr r0, _0801E444 @ =gUnknown_02032FB0
	ldr r1, _0801E448 @ =gUnknown_086A0F30
	bl MPlayStart
_0801E412:
	ldr r0, [r6]
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0801E426
	b _0801E780
_0801E426:
	movs r0, #0xc
	bl sub_11B0
	b _0801E780
	.align 2, 0
_0801E430: .4byte 0x000002A5
_0801E434: .4byte 0x000002A2
_0801E438: .4byte gCurrentPinballGame
_0801E43C: .4byte gUnknown_086AD9EC
_0801E440: .4byte 0x000002AA
_0801E444: .4byte gUnknown_02032FB0
_0801E448: .4byte gUnknown_086A0F30
_0801E44C:
	ldr r1, _0801E474 @ =gUnknown_086AD862
	ldr r4, _0801E478 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801E47C @ =0x000002A5
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #3
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0801E480 @ =0x000002A6
	adds r2, r2, r1
	ldrh r1, [r2]
	cmp r0, r1
	ble _0801E484
_0801E46E:
	adds r0, r1, #1
	strh r0, [r2]
	b _0801E780
	.align 2, 0
_0801E474: .4byte gUnknown_086AD862
_0801E478: .4byte gCurrentPinballGame
_0801E47C: .4byte 0x000002A5
_0801E480: .4byte 0x000002A6
_0801E484:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	ldr r2, _0801E4C4 @ =0x000002A5
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xd
	bne _0801E4AA
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r4]
	ldr r3, _0801E4C8 @ =0x000002A2
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
_0801E4AA:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	beq _0801E4BA
	b _0801E780
_0801E4BA:
	movs r0, 0xD4 @=SE_UNKNOWN_0xD4
	bl m4aSongNumStart
	b _0801E780
	.align 2, 0
_0801E4C4: .4byte 0x000002A5
_0801E4C8: .4byte 0x000002A2
_0801E4CC:
	ldr r2, _0801E508 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r3, #0
	strb r3, [r0]
	ldr r0, [r2]
	ldr r5, _0801E50C @ =0x000002A5
	adds r0, r0, r5
	strb r3, [r0]
	ldr r1, [r2]
	adds r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	ldr r5, _0801E510 @ =0x0000016F
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r2, r0, r1
	movs r1, #0x40
	strh r1, [r2]
	ldr r2, _0801E514 @ =0x000002AA
	adds r0, r0, r2
	strh r3, [r0]
	b _0801E780
	.align 2, 0
_0801E508: .4byte gCurrentPinballGame
_0801E50C: .4byte 0x000002A5
_0801E510: .4byte 0x0000016F
_0801E514: .4byte 0x000002AA
_0801E518:
	ldr r5, _0801E560 @ =0x0000016F
	adds r1, r4, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _0801E526
	b _0801E780
_0801E526:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0x8f
	bhi _0801E56C
	ldr r1, _0801E564 @ =gUnknown_08137968
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	mov r3, sl
	ldr r2, [r3]
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r4, _0801E568 @ =0x00000171
	adds r2, r2, r4
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, r1
	ldrb r1, [r1]
	adds r5, #3
	adds r0, r0, r5
	strb r1, [r0]
	b _0801E56E
	.align 2, 0
_0801E560: .4byte 0x0000016F
_0801E564: .4byte gUnknown_08137968
_0801E568: .4byte 0x00000171
_0801E56C:
	strb r3, [r1]
_0801E56E:
	mov r0, sl
	ldr r4, [r0]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	beq _0801E584
	b _0801E6C4
_0801E584:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _0801E596
	b _0801E6C4
_0801E596:
	lsrs r0, r1, #3
	cmp r0, #8
	beq _0801E59E
	b _0801E6C4
_0801E59E:
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _0801E5BA
	movs r0, #0x13
	ldrsb r0, [r4, r0]
	cmp r0, #2
	ble _0801E5E8
_0801E5BA:
	ldr r0, _0801E5E4 @ =gMain
	ldr r5, [r0, #0x4c]
	adds r0, r5, #0
	movs r1, #5
	bl __umodsi3
	adds r0, #1
	lsls r0, r0, #0x10
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r4, r4, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bne _0801E61C
	adds r0, r5, #1
	movs r1, #5
	b _0801E60E
	.align 2, 0
_0801E5E4: .4byte gMain
_0801E5E8:
	ldr r0, _0801E618 @ =gMain
	ldr r5, [r0, #0x4c]
	adds r0, r5, #0
	movs r1, #6
	bl __umodsi3
	adds r0, #1
	lsls r0, r0, #0x10
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r4, r4, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bne _0801E61C
	adds r0, r5, #1
	movs r1, #6
_0801E60E:
	bl __umodsi3
	adds r0, #1
	strb r0, [r4]
	b _0801E61E
	.align 2, 0
_0801E618: .4byte gMain
_0801E61C:
	strb r2, [r4]
_0801E61E:
	mov r3, sl
	ldr r0, [r3]
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0801E640
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r3]
	movs r5, #0xb6
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r1, #6
	strb r1, [r0]
_0801E640:
	mov r0, sl
	ldr r1, [r0]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801E68E
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	mov r5, sl
	ldr r0, [r5]
	ldr r1, _0801E700 @ =0x000002A2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r1, r0, r2
	movs r2, #0
	strh r3, [r1]
	ldr r5, _0801E704 @ =0x000002A5
	adds r0, r0, r5
	strb r2, [r0]
	mov r1, sl
	ldr r0, [r1]
	ldr r5, _0801E708 @ =0x0000016F
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r3, [r0]
_0801E68E:
	mov r2, sl
	ldr r3, [r2]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _0801E6C4
	ldr r2, _0801E70C @ =gUnknown_086AD9DC
	movs r4, #0
	ldrsh r1, [r2, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
_0801E6C4:
	ldr r5, _0801E710 @ =gCurrentPinballGame
	ldr r1, [r5]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bne _0801E6E2
	movs r0, 0xC9 @=SE_UNKNOWN_0xC9
	bl m4aSongNumStart
_0801E6E2:
	ldr r1, [r5]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0801E742
	cmp r0, #4
	ble _0801E714
	cmp r0, #5
	beq _0801E772
	b _0801E780
	.align 2, 0
_0801E700: .4byte 0x000002A2
_0801E704: .4byte 0x000002A5
_0801E708: .4byte 0x0000016F
_0801E70C: .4byte gUnknown_086AD9DC
_0801E710: .4byte gCurrentPinballGame
_0801E714:
	cmp r0, #0
	blt _0801E780
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x66
	bne _0801E726
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
_0801E726:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x74
	bne _0801E736
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
_0801E736:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x82
	bne _0801E780
	b _0801E76A
_0801E742:
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x66
	bne _0801E750
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
_0801E750:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x76
	bne _0801E760
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
_0801E760:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x86
	bne _0801E780
_0801E76A:
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
	b _0801E780
_0801E772:
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0x68
	bne _0801E780
	movs r0, 0xC8 @=SE_UNKNOWN_0xC8
	bl m4aSongNumStart
_0801E780:
	ldr r1, _0801E7A4 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sl, r1
	cmp r0, #6
	bls _0801E798
	b _0801EC32
_0801E798:
	lsls r0, r0, #2
	ldr r1, _0801E7A8 @ =_0801E7AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801E7A4: .4byte gCurrentPinballGame
_0801E7A8: .4byte _0801E7AC
_0801E7AC: @ jump table
	.4byte _0801E7C8 @ case 0
	.4byte _0801E814 @ case 1
	.4byte _0801E8D0 @ case 2
	.4byte _0801E998 @ case 3
	.4byte _0801EA50 @ case 4
	.4byte _0801EB00 @ case 5
	.4byte _0801EC00 @ case 6
_0801E7C8:
	mov r5, sl
	ldr r2, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0801E80C @ =0x000004E2
	strh r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r1, r2, r3
	adds r0, #0x14
	strh r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r1]
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r1, r2, r5
	subs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _0801E810 @ =0x0000055A
	strh r0, [r1]
	adds r3, #4
	adds r1, r2, r3
	adds r0, #0xf0
	strh r0, [r1]
	b _0801EC32
	.align 2, 0
_0801E80C: .4byte 0x000004E2
_0801E810: .4byte 0x0000055A
_0801E814:
	movs r6, #0
	ldr r4, _0801E8C0 @ =gCurrentPinballGame
	mov sb, r4
	movs r5, #0xc8
	lsls r5, r5, #1
	mov r8, r5
	ldr r0, _0801E8C4 @ =0x00004E20
	mov sl, r0
_0801E824:
	mov r1, sb
	ldr r4, [r1]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x7f
	ands r3, r0
	lsls r3, r3, #9
	lsls r1, r6, #0x10
	asrs r7, r1, #0x10
	lsls r6, r7, #2
	adds r1, r6, r7
	lsls r2, r1, #4
	adds r1, r1, r2
	lsls r2, r1, #8
	adds r1, r1, r2
	adds r3, r3, r1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	movs r1, #0x3c
	bl __umodsi3
	subs r0, #0x1e
	lsls r0, r0, #0x10
	mov r3, r8
	adds r1, r4, r3
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, r5, #0
	bl Cos
	mov r4, sb
	ldr r1, [r4]
	adds r4, r1, r6
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r3, _0801E8C8 @ =0x00000564
	adds r0, r0, r3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r4, r1
	strh r0, [r4]
	adds r0, r5, #0
	bl Sin
	mov r2, sb
	ldr r1, [r2]
	adds r4, r1, r6
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r5, _0801E8CC @ =0x000005DC
	adds r0, r0, r5
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0801E824
	b _0801EC32
	.align 2, 0
_0801E8C0: .4byte gCurrentPinballGame
_0801E8C4: .4byte 0x00004E20
_0801E8C8: .4byte 0x00000564
_0801E8CC: .4byte 0x000005DC
_0801E8D0:
	movs r6, #0
	ldr r3, _0801E984 @ =gCurrentPinballGame
	mov sb, r3
	movs r4, #0xc8
	lsls r4, r4, #1
	mov r8, r4
	ldr r5, _0801E988 @ =0x00004E20
	mov sl, r5
_0801E8E0:
	mov r0, sb
	ldr r4, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x7f
	ands r3, r0
	lsls r3, r3, #9
	lsls r1, r6, #0x10
	asrs r7, r1, #0x10
	lsls r6, r7, #2
	adds r1, r6, r7
	lsls r2, r1, #4
	adds r1, r1, r2
	lsls r2, r1, #8
	adds r1, r1, r2
	adds r3, r3, r1
	ldr r2, _0801E98C @ =0x00002710
	adds r1, r2, #0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r1, #0x3c
	bl __umodsi3
	subs r0, #0x1e
	lsls r0, r0, #0x10
	mov r3, r8
	adds r1, r4, r3
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, r5, #0
	bl Cos
	mov r4, sb
	ldr r1, [r4]
	adds r4, r1, r6
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r3, _0801E990 @ =0x00000564
	adds r0, r0, r3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r4, r1
	strh r0, [r4]
	adds r0, r5, #0
	bl Sin
	mov r2, sb
	ldr r1, [r2]
	adds r4, r1, r6
	add r1, r8
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	mov r1, sl
	bl __divsi3
	ldr r5, _0801E994 @ =0x000005DC
	adds r0, r0, r5
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0801E8E0
	b _0801EC32
	.align 2, 0
_0801E984: .4byte gCurrentPinballGame
_0801E988: .4byte 0x00004E20
_0801E98C: .4byte 0x00002710
_0801E990: .4byte 0x00000564
_0801E994: .4byte 0x000005DC
_0801E998:
	movs r6, #0
_0801E99A:
	mov r3, sl
	ldr r5, [r3]
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #0x2e
	bl __umodsi3
	movs r7, #0x17
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9C0
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0801E9C0:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, #1
	lsls r0, r2, #2
	adds r3, r5, r0
	lsls r0, r1, #5
	adds r0, r0, r1
	adds r0, #0x79
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r3, r5
	strh r1, [r0]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, _0801EA44 @ =0x0000053C
	adds r1, r1, r0
	movs r4, #0xbd
	lsls r4, r4, #1
	adds r3, r3, r4
	strh r1, [r3]
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0801E99A
	mov r0, sl
	ldr r5, [r0]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0x17
	movs r1, #0x2e
	bl __umodsi3
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801EA22
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0801EA22:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _0801EA48 @ =0x0000055A
	strh r0, [r1]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r3, _0801EA4C @ =0x00000654
	adds r1, r1, r3
	movs r4, #0xbd
	lsls r4, r4, #1
	adds r2, r5, r4
	strh r1, [r2]
	b _0801EC32
	.align 2, 0
_0801EA44: .4byte 0x0000053C
_0801EA48: .4byte 0x0000055A
_0801EA4C: .4byte 0x00000654
_0801EA50:
	mov r5, sl
	ldr r6, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0801EAE8 @ =0x000004BA
	strh r0, [r1]
	ldr r5, _0801EAEC @ =gUnknown_0813798C
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAF0 @ =0x00000514
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x14
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAF4 @ =0x00000582
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0801EAF8 @ =0x0000055A
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #0x28
	movs r1, #0x3c
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r2, _0801EAFC @ =0x0000067C
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0801EC30
	.align 2, 0
_0801EAE8: .4byte 0x000004BA
_0801EAEC: .4byte gUnknown_0813798C
_0801EAF0: .4byte 0x00000514
_0801EAF4: .4byte 0x00000582
_0801EAF8: .4byte 0x0000055A
_0801EAFC: .4byte 0x0000067C
_0801EB00:
	ldr r0, _0801EBF0 @ =gUnknown_086AD9DC
	mov r4, sl
	ldr r3, [r4]
	movs r5, #0xb7
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r5, #0xa
	adds r1, r3, r5
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r1, r0, r1
	str r1, [sp]
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xbd
	lsls r1, r1, #1
	mov sb, r1
	add r3, sb
	movs r2, #0
	ldrsh r1, [r3, r2]
	subs r1, r0, r1
	str r1, [sp, #4]
	ldr r4, [sp]
	adds r3, r4, #0
	muls r3, r4, r3
	mov r8, r3
	adds r0, r1, #0
	muls r0, r1, r0
	add r8, r0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r6, _0801EBF4 @ =0x00004E20
	adds r0, r1, #0
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Sin
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	subs r0, r0, r1
	adds r1, r6, #0
	bl __divsi3
	str r0, [sp, #0xc]
	mov r0, sl
	ldr r1, [r0]
	adds r5, r1, r5
	ldrh r0, [r5]
	ldr r2, [sp, #8]
	adds r0, r2, r0
	movs r4, #0
	strh r0, [r5]
	add r1, sb
	ldrh r0, [r1]
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	strh r0, [r1]
	ldr r0, _0801EBF8 @ =0x000009C3
	cmp r8, r0
	bgt _0801EBCA
	bl Random
	mov r5, sl
	ldr r2, [r5]
	movs r1, #3
	ands r1, r0
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
_0801EBCA:
	mov r5, sl
	ldr r2, [r5]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r4, [r0]
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, _0801EBFC @ =0x0000FED4
	strh r1, [r0]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r2, r5
	strh r4, [r0]
	adds r3, #4
	adds r0, r2, r3
	b _0801EC30
	.align 2, 0
_0801EBF0: .4byte gUnknown_086AD9DC
_0801EBF4: .4byte 0x00004E20
_0801EBF8: .4byte 0x000009C3
_0801EBFC: .4byte 0x0000FED4
_0801EC00:
	mov r4, sl
	ldr r3, [r4]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r2, #0
	strh r2, [r0]
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, _0801EC44 @ =0x0000FED4
	strh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r3, r4
	strh r2, [r0]
	adds r5, #6
	adds r0, r3, r5
	strh r1, [r0]
	adds r4, #4
	adds r0, r3, r4
	strh r2, [r0]
	adds r5, #4
	adds r0, r3, r5
_0801EC30:
	strh r1, [r0]
_0801EC32:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801EC44: .4byte 0x0000FED4

	thumb_func_start sub_1EC48
sub_1EC48: @ 0x0801EC48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0801ECAC @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r2, _0801ECB0 @ =0x00000624
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bgt _0801EC66
	b _0801EE4A
_0801EC66:
	cmp r0, #2
	beq _0801EC6C
	b _0801EE3C
_0801EC6C:
	movs r0, #0xfa
	lsls r0, r0, #1
	str r0, [r3, #0x3c]
	movs r0, 0xB6 @=SE_UNKNOWN_0xB6
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
	ldr r3, _0801ECAC @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	beq _0801EC8C
	b _0801EE1E
_0801EC8C:
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	beq _0801EC96
	b _0801EE1E
_0801EC96:
	ldr r5, _0801ECB4 @ =0x00000625
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	ble _0801ECA4
	b _0801EE1E
_0801ECA4:
	cmp r0, #0
	bne _0801ECB8
	movs r0, #1
	b _0801ECC2
	.align 2, 0
_0801ECAC: .4byte gCurrentPinballGame
_0801ECB0: .4byte 0x00000624
_0801ECB4: .4byte 0x00000625
_0801ECB8:
	cmp r0, #1
	bne _0801ECC0
	movs r0, #3
	b _0801ECC2
_0801ECC0:
	movs r0, #6
_0801ECC2:
	strb r0, [r1]
	ldr r6, _0801ED70 @ =gCurrentPinballGame
	ldr r5, [r6]
	ldr r1, _0801ED74 @ =0x00000625
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #6
	beq _0801ECDA
	b _0801EE1E
_0801ECDA:
	ldr r2, _0801ED78 @ =0x000006C6
	adds r0, r5, r2
	movs r7, #0
	ldrsb r7, [r0, r7]
	cmp r7, #0
	beq _0801ECE8
	b _0801EE1E
_0801ECE8:
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #4
	bne _0801ED98
	ldr r2, _0801ED7C @ =gMain
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
	strh r7, [r0]
	adds r0, #8
	mov r1, r8
	strh r1, [r0]
	adds r0, #4
	mov r5, sb
	strb r5, [r0]
	ldr r0, [r6]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r6]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801ED80 @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r7, [r0]
	ldr r1, _0801ED84 @ =0x040000D4
	ldr r0, _0801ED88 @ =gUnknown_086ACEF8
	ldr r0, [r0, #0x18]
	str r0, [r1]
	ldr r0, _0801ED8C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801ED90 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801ED94 @ =gUnknown_086ACF18
	ldr r0, [r0, #0x18]
	b _0801EE0C
	.align 2, 0
_0801ED70: .4byte gCurrentPinballGame
_0801ED74: .4byte 0x00000625
_0801ED78: .4byte 0x000006C6
_0801ED7C: .4byte gMain
_0801ED80: .4byte 0x0000F63C
_0801ED84: .4byte 0x040000D4
_0801ED88: .4byte gUnknown_086ACEF8
_0801ED8C: .4byte 0x06015800
_0801ED90: .4byte 0x80001200
_0801ED94: .4byte gUnknown_086ACF18
_0801ED98:
	ldr r2, _0801EEA8 @ =gMain
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
	strh r7, [r0]
	adds r1, #6
	movs r0, #4
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xf2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfa
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0xfb
	strb r4, [r0]
	ldr r4, [r6]
	adds r1, r4, #0
	adds r1, #0xf4
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0801EEAC @ =0x0000F63C
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf0
	strh r3, [r0]
	adds r0, #8
	strh r7, [r0]
	ldr r1, _0801EEB0 @ =0x040000D4
	ldr r0, _0801EEB4 @ =gUnknown_086ACEF8
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r0, _0801EEB8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0801EEBC @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0801EEC0 @ =gUnknown_086ACF18
	ldr r0, [r0, #4]
_0801EE0C:
	str r0, [r1]
	ldr r0, _0801EEC4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _0801EEC8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0x38]
	movs r0, #0xce
	strh r0, [r2, #0x38]
_0801EE1E:
	ldr r2, _0801EECC @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r6, #0xbb
	lsls r6, r6, #1
	adds r1, r0, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #0xc2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0801EE3C:
	ldr r2, _0801EECC @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0801EED0 @ =0x00000624
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0801EE4A:
	ldr r5, _0801EED4 @ =gMain+0x2F88 @gMain.spriteGroups[62]
	mov sl, r5
	ldr r6, _0801EECC @ =gCurrentPinballGame
	ldr r0, [r6]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0801EF4C
	movs r6, #0
	ldr r2, _0801EED8 @ =gUnknown_0844928C
	mov sb, r2
	ldr r3, _0801EECC @ =gCurrentPinballGame
	mov r8, r3
	movs r7, #0xb8
	lsls r7, r7, #1
	ldr r5, _0801EEB0 @ =0x040000D4
_0801EE72:
	mov r0, r8
	ldr r3, [r0]
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	adds r0, r3, r7
	adds r2, r0, r4
	ldrb r0, [r2]
	movs r1, #0
	ldrsb r1, [r2, r1]
	cmp r1, #0
	beq _0801EEE2
	cmp r1, #0x64
	ble _0801EEDC
	subs r0, #1
	movs r3, #0
	strb r0, [r2]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x64
	bne _0801EEA4
	strb r3, [r1]
_0801EEA4:
	movs r1, #8
	b _0801EEFA
	.align 2, 0
_0801EEA8: .4byte gMain
_0801EEAC: .4byte 0x0000F63C
_0801EEB0: .4byte 0x040000D4
_0801EEB4: .4byte gUnknown_086ACEF8
_0801EEB8: .4byte 0x06015800
_0801EEBC: .4byte 0x80001200
_0801EEC0: .4byte gUnknown_086ACF18
_0801EEC4: .4byte 0x050003C0
_0801EEC8: .4byte 0x80000010
_0801EECC: .4byte gCurrentPinballGame
_0801EED0: .4byte 0x00000624
_0801EED4: .4byte gMain+0x2F88 @gMain.spriteGroups[62]
_0801EED8: .4byte gUnknown_0844928C
_0801EEDC:
	movs r0, #0
	ldrsb r0, [r2, r0]
	b _0801EEF6
_0801EEE2:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r3, r2
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
_0801EEF6:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0801EEFA:
	lsls r0, r1, #0x10
	asrs r0, r0, #8
	add r0, sb
	str r0, [r5]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #8
	ldr r3, _0801EF38 @ =0x06012E80
	adds r0, r0, r3
	str r0, [r5, #4]
	ldr r0, _0801EF3C @ =0x80000080
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _0801EE72
	ldr r2, _0801EF40 @ =0x040000D4
	ldr r5, _0801EF44 @ =gCurrentPinballGame
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _0801EF48 @ =gUnknown_081379B8
	b _0801F006
	.align 2, 0
_0801EF38: .4byte 0x06012E80
_0801EF3C: .4byte 0x80000080
_0801EF40: .4byte 0x040000D4
_0801EF44: .4byte gCurrentPinballGame
_0801EF48: .4byte gUnknown_081379B8
_0801EF4C:
	movs r6, #0
	movs r0, #0xb8
	lsls r0, r0, #1
	mov sb, r0
	ldr r1, _0801EFA0 @ =0x040000D4
	mov r8, r1
_0801EF58:
	ldr r2, _0801EFA4 @ =gCurrentPinballGame
	ldr r1, [r2]
	lsls r0, r6, #0x10
	asrs r5, r0, #0x10
	mov r3, sb
	adds r0, r1, r3
	adds r4, r0, r5
	ldrb r7, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _0801EFAE
	cmp r0, #0x64
	ble _0801EFA8
	movs r1, #0x69
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #9
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	subs r0, r7, #1
	movs r3, #0
	strb r0, [r4]
	ldr r2, _0801EFA4 @ =gCurrentPinballGame
	ldr r0, [r2]
	add r0, sb
	adds r2, r0, r5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0x64
	bne _0801EFC6
	strb r3, [r2]
	b _0801EFC6
	.align 2, 0
_0801EFA0: .4byte 0x040000D4
_0801EFA4: .4byte gCurrentPinballGame
_0801EFA8:
	movs r0, #0
	ldrsb r0, [r4, r0]
	b _0801EFC2
_0801EFAE:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
_0801EFC2:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_0801EFC6:
	lsls r0, r1, #0x10
	asrs r0, r0, #8
	ldr r5, _0801F128 @ =gUnknown_083C806C
	adds r0, r0, r5
	mov r1, r8
	str r0, [r1]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #8
	ldr r2, _0801F12C @ =0x06012E80
	adds r0, r0, r2
	mov r3, r8
	str r0, [r3, #4]
	ldr r0, _0801F130 @ =0x80000080
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _0801EF58
	ldr r2, _0801F134 @ =0x040000D4
	ldr r5, _0801F138 @ =gCurrentPinballGame
	ldr r0, [r5]
	adds r0, #0x6f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _0801F13C @ =gUnknown_08137998
_0801F006:
	adds r0, r0, r6
	str r0, [r2]
	ldr r0, _0801F140 @ =0x05000320
	str r0, [r2, #4]
	ldr r0, _0801F144 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r6, #0
_0801F016:
	ldr r0, _0801F138 @ =gCurrentPinballGame
	ldr r4, [r0]
	lsls r6, r6, #0x10
	asrs r1, r6, #0x10
	mov sb, r1
	lsls r0, r1, #2
	adds r7, r4, r0
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	mov r1, sl
	strh r0, [r1, #2]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r0, #4
	mov r1, sl
	strh r0, [r1, #4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #8
	lsls r0, r0, #1
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r5, r8
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	adds r0, #7
	lsls r0, r0, #1
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	mov r3, sl
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r0, #0x28
	rsbs r0, r0, #0
	mov r8, r6
	cmp r1, r0
	bge _0801F0AE
	ldr r0, _0801F148 @ =0x0000FFD8
	strh r0, [r3, #4]
_0801F0AE:
	movs r0, #0
	mov r6, sb
	lsls r6, r6, #1
	mov ip, r6
	ldr r7, _0801F14C @ =gOamBuffer
	ldr r1, _0801F150 @ =0xFFFFFE00
	mov sb, r1
_0801F0BC:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	mov r3, ip
	adds r2, r4, r3
	lsls r2, r2, #3
	adds r2, #8
	add r2, sl
	ldrh r3, [r2]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r5, #2
	ldrsh r1, [r2, r5]
	mov r6, sl
	movs r5, #2
	ldrsh r0, [r6, r5]
	adds r1, r1, r0
	ldr r6, _0801F154 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r5, [r3, #2]
	mov r0, sb
	ands r0, r5
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r2]
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r2, [r2, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801F0BC
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0801F118
	b _0801F016
_0801F118:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F128: .4byte gUnknown_083C806C
_0801F12C: .4byte 0x06012E80
_0801F130: .4byte 0x80000080
_0801F134: .4byte 0x040000D4
_0801F138: .4byte gCurrentPinballGame
_0801F13C: .4byte gUnknown_08137998
_0801F140: .4byte 0x05000320
_0801F144: .4byte 0x80000010
_0801F148: .4byte 0x0000FFD8
_0801F14C: .4byte gOamBuffer
_0801F150: .4byte 0xFFFFFE00
_0801F154: .4byte 0x000001FF

	thumb_func_start sub_1F158
sub_1F158: @ 0x0801F158
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0801F270 @ =gMain
	ldr r0, [r4, #0x4c]
	movs r1, #0x37
	bl __umodsi3
	movs r1, #0xb
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0801F274 @ =0x00002ED0
	adds r7, r4, r0
	ldr r2, _0801F278 @ =0x040000D4
	ldr r6, _0801F27C @ =gCurrentPinballGame
	ldr r3, [r6]
	ldr r0, _0801F280 @ =0x000002F5
	adds r4, r3, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801F284 @ =gUnknown_084F5ACC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F288 @ =0x06012C20
	str r0, [r2, #4]
	ldr r0, _0801F28C @ =0x80000130
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r3, r3, r2
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _0801F1B4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0801F1B4:
	ldr r2, _0801F290 @ =gUnknown_086AD9FC
	lsls r0, r5, #0x10
	asrs r0, r0, #0xe
	adds r1, r0, r2
	ldrh r3, [r1]
	adds r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r4]
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0xb3
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0xae
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldr r5, _0801F294 @ =gUnknown_086B3A04
	mov sb, r5
	ldr r6, _0801F298 @ =gOamBuffer
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #1
	mov ip, r0
	ldr r0, _0801F29C @ =0xFFFFFE00
	mov r8, r0
_0801F1F6:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	adds r4, r7, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r5, [r2, #2]
	mov sl, r5
	mov r0, sl
	lsls r1, r0, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _0801F2A0 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	mov r5, sl
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0801F1F6
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F270: .4byte gMain
_0801F274: .4byte 0x00002ED0
_0801F278: .4byte 0x040000D4
_0801F27C: .4byte gCurrentPinballGame
_0801F280: .4byte 0x000002F5
_0801F284: .4byte gUnknown_084F5ACC
_0801F288: .4byte 0x06012C20
_0801F28C: .4byte 0x80000130
_0801F290: .4byte gUnknown_086AD9FC
_0801F294: .4byte gUnknown_086B3A04
_0801F298: .4byte gOamBuffer
_0801F29C: .4byte 0xFFFFFE00
_0801F2A0: .4byte 0x000001FF

	thumb_func_start sub_1F2A4
sub_1F2A4: @ 0x0801F2A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _0801F3E8 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	mov sb, r2
	adds r2, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r3, [r2]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	beq _0801F39A
	adds r0, r3, #2
	strh r0, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #0xe
	bl __divsi3
	movs r6, #0xe5
	lsls r6, r6, #1
	adds r2, r4, r6
	strh r0, [r2]
	movs r3, #0xe8
	lsls r3, r3, #1
	mov r8, r3
	adds r1, r4, r3
	movs r0, #0x50
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	mov ip, r0
	adds r0, r4, r0
	subs r3, #0xd0
	strh r3, [r0]
	movs r7, #0xed
	lsls r7, r7, #1
	adds r0, r4, r7
	strh r3, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xb
	bne _0801F314
	movs r2, #0xe7
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x78
	strh r0, [r1]
_0801F314:
	ldr r2, [r5]
	adds r1, r2, r6
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0xb
	ble _0801F336
	movs r0, #0xc
	strh r0, [r1]
	mov r6, r8
	adds r1, r2, r6
	movs r0, #0x78
	strh r0, [r1]
	mov r1, ip
	adds r0, r2, r1
	strh r3, [r0]
	adds r0, r2, r7
	strh r3, [r0]
_0801F336:
	ldr r0, [r5]
	mov r3, sb
	adds r2, r0, r3
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0xa7
	bgt _0801F368
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801F368
	movs r5, #0
	ldrsh r0, [r2, r5]
	movs r1, #0x15
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #8
	movs r6, #0xa8
	lsls r6, r6, #0x10
	adds r0, r0, r6
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
_0801F368:
	ldr r4, _0801F3E8 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bgt _0801F39A
	strh r3, [r2]
	cmp r1, #0xa7
	ble _0801F39A
	ldr r0, _0801F3EC @ =gMPlayInfo_SE1
	ldr r1, _0801F3F0 @ =gUnknown_0869F2A0
	bl MPlayStart
	ldr r1, [r4]
	ldr r0, _0801F3F4 @ =0x00000BB8
	str r0, [r1, #0x3c]
_0801F39A:
	ldr r5, _0801F3E8 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _0801F3F8 @ =0x00000616
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801F3AC
	subs r0, #1
	strh r0, [r1]
_0801F3AC:
	ldr r4, [r5]
	ldr r3, _0801F3FC @ =0x00000614
	adds r2, r4, r3
	ldrh r0, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	cmp r1, #0
	ble _0801F478
	subs r0, #3
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801F3CA
	strh r3, [r2]
_0801F3CA:
	ldr r0, [r5]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r4, _0801F400 @ =0x0000061A
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r0, #1
	cmp r2, r0
	bge _0801F404
	adds r0, r2, #1
	strh r0, [r1]
	b _0801F44E
	.align 2, 0
_0801F3E8: .4byte gCurrentPinballGame
_0801F3EC: .4byte gMPlayInfo_SE1
_0801F3F0: .4byte gUnknown_0869F2A0
_0801F3F4: .4byte 0x00000BB8
_0801F3F8: .4byte 0x00000616
_0801F3FC: .4byte 0x00000614
_0801F400: .4byte 0x0000061A
_0801F404:
	strh r3, [r1]
	ldr r0, _0801F464 @ =gUnknown_02032FB0
	ldr r1, _0801F468 @ =gUnknown_0869F240
	bl MPlayStart
	ldr r2, [r5]
	movs r0, #0x64
	str r0, [r2, #0x3c]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xb
	bgt _0801F44E
	ldr r4, _0801F46C @ =0x0000061C
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801F44E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x50
	strh r0, [r1]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
_0801F44E:
	ldr r5, _0801F470 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _0801F474 @ =0x00000614
	adds r0, r4, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xe1
	lsls r0, r0, #1
	subs r0, r0, r1
	b _0801F508
	.align 2, 0
_0801F464: .4byte gUnknown_02032FB0
_0801F468: .4byte gUnknown_0869F240
_0801F46C: .4byte 0x0000061C
_0801F470: .4byte gCurrentPinballGame
_0801F474: .4byte 0x00000614
_0801F478:
	cmp r1, #0
	bge _0801F55C
	adds r0, #3
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0801F48A
	strh r3, [r2]
_0801F48A:
	ldr r0, [r5]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r4, _0801F4A8 @ =0x0000061A
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r0, #1
	cmp r2, r0
	bge _0801F4AC
	adds r0, r2, #1
	strh r0, [r1]
	b _0801F4F6
	.align 2, 0
_0801F4A8: .4byte 0x0000061A
_0801F4AC:
	strh r3, [r1]
	ldr r0, _0801F540 @ =gUnknown_02032FB0
	ldr r1, _0801F544 @ =gUnknown_0869F240
	bl MPlayStart
	ldr r2, [r5]
	movs r0, #0x64
	str r0, [r2, #0x3c]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xb
	bgt _0801F4F6
	ldr r4, _0801F548 @ =0x0000061C
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801F4F6
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x50
	strh r0, [r1]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r2, r6
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
_0801F4F6:
	ldr r5, _0801F54C @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _0801F550 @ =0x00000614
	adds r0, r4, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r0, r0, r2
_0801F508:
	movs r1, #0xa
	bl __divsi3
	ldr r1, _0801F554 @ =0x0000061A
	adds r4, r4, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0801F520
	movs r0, #5
	strh r0, [r4]
_0801F520:
	ldr r4, [r5]
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #4
	adds r1, r4, r1
	movs r5, #0
	ldrsh r1, [r1, r5]
	bl __divsi3
	ldr r6, _0801F558 @ =0x000001E5
	adds r1, r4, r6
	strb r0, [r1]
	b _0801F58A
	.align 2, 0
_0801F540: .4byte gUnknown_02032FB0
_0801F544: .4byte gUnknown_0869F240
_0801F548: .4byte 0x0000061C
_0801F54C: .4byte gCurrentPinballGame
_0801F550: .4byte 0x00000614
_0801F554: .4byte 0x0000061A
_0801F558: .4byte 0x000001E5
_0801F55C:
	ldr r0, _0801F598 @ =0x000001E5
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _0801F58A
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r4, r4, r1
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0x28
	bl __umodsi3
	strh r0, [r4]
	ldrh r0, [r4]
	lsls r0, r0, #4
	movs r1, #0x28
	bl __divsi3
	strb r0, [r5]
_0801F58A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F598: .4byte 0x000001E5

	thumb_func_start sub_1F59C
sub_1F59C: @ 0x0801F59C
	push {r4, r5, r6, r7, lr}
	ldr r3, _0801F5D4 @ =gCurrentPinballGame
	ldr r4, [r3]
	ldr r1, _0801F5D8 @ =0x000001E5
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, _0801F5DC @ =gMain
	ldr r0, [r2, #0x44]
	ldr r6, [r0, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xce
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrb r0, [r2, #4]
	cmp r0, #0
	bne _0801F5E0
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0xae
	b _0801F5E8
	.align 2, 0
_0801F5D4: .4byte gCurrentPinballGame
_0801F5D8: .4byte 0x000001E5
_0801F5DC: .4byte gMain
_0801F5E0:
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x9a
_0801F5E8:
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, [r3]
	ldr r2, _0801F678 @ =0x000001E5
	adds r0, r1, r2
	movs r3, #0xf3
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrb r3, [r0]
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	beq _0801F624
	strb r3, [r2]
	ldr r2, _0801F67C @ =0x040000D4
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0801F680 @ =gUnknown_084FA48C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F684 @ =0x06010780
	str r0, [r2, #4]
	ldr r0, _0801F688 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801F624:
	movs r0, #0
	ldr r7, _0801F68C @ =gOamBuffer
	ldr r1, _0801F690 @ =0xFFFFFE00
	mov ip, r1
_0801F62C:
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
	ldr r2, _0801F694 @ =0x000001FF
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
	cmp r5, #3
	ble _0801F62C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801F678: .4byte 0x000001E5
_0801F67C: .4byte 0x040000D4
_0801F680: .4byte gUnknown_084FA48C
_0801F684: .4byte 0x06010780
_0801F688: .4byte 0x80000090
_0801F68C: .4byte gOamBuffer
_0801F690: .4byte 0xFFFFFE00
_0801F694: .4byte 0x000001FF

	thumb_func_start sub_1F698
sub_1F698: @ 0x0801F698
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r7, _0801F6EC @ =gMain+0xD08 @gMain.spriteGroups[14]
	ldr r0, _0801F6F0 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r3, r4, r1
	ldrh r1, [r3]
	mov sb, r0
	cmp r1, #0x3b
	bhi _0801F712
	adds r0, r1, #0
	subs r0, #0x1b
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _0801F704
	ldrh r0, [r3]
	subs r0, #0x1b
	movs r1, #5
	bl __divsi3
	ldr r2, _0801F6F4 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	ldr r1, _0801F6F8 @ =gUnknown_083C562C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F6FC @ =0x06014280
	str r0, [r2, #4]
	ldr r0, _0801F700 @ =0x80000080
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb0
	b _0801F760
	.align 2, 0
_0801F6EC: .4byte gMain+0xD08 @gMain.spriteGroups[14]
_0801F6F0: .4byte gCurrentPinballGame
_0801F6F4: .4byte 0x040000D4
_0801F6F8: .4byte gUnknown_083C562C
_0801F6FC: .4byte 0x06014280
_0801F700: .4byte 0x80000080
_0801F704:
	strh r2, [r7]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0xb0
	b _0801F760
_0801F712:
	adds r0, r1, #0
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _0801F754
	ldrh r0, [r3]
	subs r0, #0x64
	movs r1, #5
	bl __divsi3
	ldr r2, _0801F744 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #8
	ldr r1, _0801F748 @ =gUnknown_083C562C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F74C @ =0x06014280
	str r0, [r2, #4]
	ldr r0, _0801F750 @ =0x80000080
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r0, r4, #0
	b _0801F75A
	.align 2, 0
_0801F744: .4byte 0x040000D4
_0801F748: .4byte gUnknown_083C562C
_0801F74C: .4byte 0x06014280
_0801F750: .4byte 0x80000080
_0801F754:
	strh r2, [r7]
	mov r3, sb
	ldr r0, [r3]
_0801F75A:
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x20
_0801F760:
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r7]
	ldr r1, _0801F880 @ =gMain+0xC50 @gMain.spriteGroups[13]
	mov r8, r1
	cmp r0, #0
	beq _0801F7D8
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _0801F78C
	movs r0, #0xb4
	strh r0, [r7, #4]
_0801F78C:
	movs r0, #0
	ldr r6, _0801F884 @ =gOamBuffer
	ldr r1, _0801F888 @ =0xFFFFFE00
	mov ip, r1
_0801F794:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r2, #2
	ldrsh r1, [r5, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0801F88C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _0801F794
_0801F7D8:
	mov r7, r8
	ldrh r0, [r7]
	cmp r0, #0
	bne _0801F7E2
	b _0801FA26
_0801F7E2:
	mov r0, sb
	ldr r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r1, r3, r6
	ldrh r0, [r1]
	cmp r0, #0x77
	bls _0801F7F4
	b _0801F990
_0801F7F4:
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801F802
	movs r0, 0xC6 @=SE_UNKNOWN_0xC6
	bl m4aSongNumStart
_0801F802:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r2, _0801F890 @ =0x040000D4
	lsrs r0, r0, #2
	lsls r0, r0, #7
	ldr r1, _0801F894 @ =gUnknown_083C542C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801F898 @ =0x06014200
	str r0, [r2, #4]
	ldr r0, _0801F89C @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, sb
	ldr r4, [r2]
	adds r5, r4, r6
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	movs r1, #0x5a
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	subs r1, #2
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5]
	cmp r0, #0x1d
	bhi _0801F8A8
	adds r0, r2, #0
	bl Sin
	adds r1, r0, #0
	mov r2, sb
	ldr r4, [r2]
	adds r5, r4, r6
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0801F8A0 @ =0x00004E20
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r1, r0
	ldr r3, _0801F8A4 @ =0x000002B6
	adds r4, r4, r3
	strh r1, [r4]
	b _0801F8CC
	.align 2, 0
_0801F880: .4byte gMain+0xC50 @gMain.spriteGroups[13]
_0801F884: .4byte gOamBuffer
_0801F888: .4byte 0xFFFFFE00
_0801F88C: .4byte 0x000001FF
_0801F890: .4byte 0x040000D4
_0801F894: .4byte gUnknown_083C542C
_0801F898: .4byte 0x06014200
_0801F89C: .4byte 0x80000040
_0801F8A0: .4byte 0x00004E20
_0801F8A4: .4byte 0x000002B6
_0801F8A8:
	adds r0, r2, #0
	bl Sin
	adds r1, r0, #0
	mov r0, sb
	ldr r4, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0801F910 @ =0x00004E20
	bl __divsi3
	adds r0, #0x1e
	ldr r1, _0801F914 @ =0x000002B6
	adds r4, r4, r1
	strh r0, [r4]
_0801F8CC:
	ldr r2, _0801F918 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r3, #0xaf
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r2
	cmp r0, #0x1b
	bne _0801F934
	ldr r0, _0801F91C @ =gMain
	ldr r1, _0801F920 @ =0x00000D08
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	movs r0, 0xC7 @=SE_UNKNOWN_0xC7
	bl m4aSongNumStart
	mov r2, sb
	ldr r0, [r2]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801F924
	adds r0, r2, #1
	strb r0, [r1]
	b _0801F934
	.align 2, 0
_0801F910: .4byte 0x00004E20
_0801F914: .4byte 0x000002B6
_0801F918: .4byte gCurrentPinballGame
_0801F91C: .4byte gMain
_0801F920: .4byte 0x00000D08
_0801F924:
	movs r0, #2
	strb r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0801F96C @ =0x000002EA
	adds r0, r0, r2
	movs r1, #0xbe
	strh r1, [r0]
_0801F934:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x64
	bne _0801F9B6
	ldr r0, _0801F970 @ =gMain
	ldr r2, _0801F974 @ =0x00000D08
	adds r0, r0, r2
	movs r1, #1
	strh r1, [r0]
	movs r0, 0xC7 @=SE_UNKNOWN_0xC7
	bl m4aSongNumStart
	mov r3, sb
	ldr r0, [r3]
	ldr r2, _0801F978 @ =0x000002E3
	adds r1, r0, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0801F97C
	adds r0, r2, #1
	strb r0, [r1]
	b _0801F9B6
	.align 2, 0
_0801F96C: .4byte 0x000002EA
_0801F970: .4byte gMain
_0801F974: .4byte 0x00000D08
_0801F978: .4byte 0x000002E3
_0801F97C:
	movs r0, #2
	strb r0, [r1]
	mov r3, sb
	ldr r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0xbe
	strh r1, [r0]
	b _0801F9B6
_0801F990:
	movs r2, #0
	strh r2, [r1]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _0801FA34 @ =0x000002B6
	adds r1, r3, r0
	movs r0, #0xbe
	strh r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r1, _0801FA38 @ =0x000002BA
	adds r0, r3, r1
	strh r2, [r0]
	strh r2, [r7]
_0801F9B6:
	mov r2, sb
	ldr r4, [r2]
	movs r3, #0xad
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl __divsi3
	adds r0, #0x47
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r2, _0801FA34 @ =0x000002B6
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r0, #0xf8
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xbe
	ble _0801F9F2
	movs r0, #0xbe
	strh r0, [r7, #4]
_0801F9F2:
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _0801FA3C @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r3, _0801FA40 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0801FA44 @ =0xFFFFFE00
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
_0801FA26:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FA34: .4byte 0x000002B6
_0801FA38: .4byte 0x000002BA
_0801FA3C: .4byte gOamBuffer
_0801FA40: .4byte 0x000001FF
_0801FA44: .4byte 0xFFFFFE00

	thumb_func_start sub_1FA48
sub_1FA48: @ 0x0801FA48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r7, _0801FAD0 @ =gMain+0x2910 @gMain.spriteGroups[53]
	ldr r0, _0801FAD4 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r1, _0801FAD8 @ =0x000002B2
	mov sb, r1
	adds r1, r6, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov sl, r0
	cmp r1, #0
	beq _0801FAF0
	ldr r5, _0801FADC @ =gUnknown_086ADA58
	movs r2, #0xac
	lsls r2, r2, #2
	mov r8, r2
	adds r0, r6, r2
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #5
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r5
	ldrh r3, [r0]
	cmp r4, #0x28
	bne _0801FABA
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0x64
	strh r0, [r2]
	ldr r2, _0801FAE0 @ =0x000002BA
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0801FAE4 @ =0xFFFFE340
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_0801FABA:
	mov r2, sl
	ldr r1, [r2]
	mov r0, r8
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0x35
	bhi _0801FAE8
	adds r0, #1
	strh r0, [r2]
	b _0801FB12
	.align 2, 0
_0801FAD0: .4byte gMain+0x2910 @gMain.spriteGroups[53]
_0801FAD4: .4byte gCurrentPinballGame
_0801FAD8: .4byte 0x000002B2
_0801FADC: .4byte gUnknown_086ADA58
_0801FAE0: .4byte 0x000002BA
_0801FAE4: .4byte 0xFFFFE340
_0801FAE8:
	add r1, sb
	movs r0, #0
	strb r0, [r1]
	b _0801FB12
_0801FAF0:
	ldr r1, _0801FBA4 @ =0xFFFFD6F0
	adds r0, r7, r1
	ldr r0, [r0, #0x4c]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _0801FB2E
_0801FB12:
	ldr r2, _0801FBA8 @ =0x040000D4
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0801FBAC @ =gUnknown_083C3C2C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0801FBB0 @ =0x06012720
	str r0, [r2, #4]
	ldr r0, _0801FBB4 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0801FB2E:
	mov r0, sl
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x37
	subs r0, r0, r2
	strh r0, [r7, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0xdd
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r0, #0
	ldr r6, _0801FBB8 @ =gOamBuffer
	ldr r1, _0801FBBC @ =0xFFFFFE00
	mov ip, r1
_0801FB50:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r4, [r3]
	lsls r4, r4, #3
	adds r4, r4, r6
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0801FBC0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r4, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r3, [r3, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #1
	ble _0801FB50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FBA4: .4byte 0xFFFFD6F0
_0801FBA8: .4byte 0x040000D4
_0801FBAC: .4byte gUnknown_083C3C2C
_0801FBB0: .4byte 0x06012720
_0801FBB4: .4byte 0x80000180
_0801FBB8: .4byte gOamBuffer
_0801FBBC: .4byte 0xFFFFFE00
_0801FBC0: .4byte 0x000001FF

	thumb_func_start sub_1FBC4
sub_1FBC4: @ 0x0801FBC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0801FC74 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0801FC78 @ =0x000002C2
	adds r3, r2, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0801FC7C @ =gUnknown_086ADA6E
	adds r7, r0, r1
	ldr r0, _0801FC80 @ =gMain+0x2BF0 @gMain.spriteGroups[57]
	mov sb, r0
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #9
	subs r0, r0, r1
	movs r1, #0
	mov r8, r1
	mov r6, sb
	strh r0, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r6, #0x90
	lsls r6, r6, #1
	adds r0, r6, #0
	subs r0, r0, r1
	mov r1, sb
	strh r0, [r1, #4]
	ldr r6, _0801FC84 @ =0x000002BE
	mov ip, r6
	adds r1, r2, r6
	ldr r6, _0801FC88 @ =0x000006BD
	adds r0, r2, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	ble _0801FCDC
	ldr r0, _0801FC8C @ =0x000006BE
	mov sl, r0
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0801FC38
	b _0801FDFC
_0801FC38:
	adds r6, #3
	adds r0, r2, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _0801FC5A
	movs r0, #0x3b
	strb r0, [r3]
	ldr r1, [r4]
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	strh r3, [r0]
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0801FC5A:
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r4]
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r2, r1, r3
	ldrh r3, [r2]
	cmp r0, r3
	ble _0801FC90
	adds r0, r3, #1
	strh r0, [r2]
	b _0801FDFC
	.align 2, 0
_0801FC74: .4byte gCurrentPinballGame
_0801FC78: .4byte 0x000002C2
_0801FC7C: .4byte gUnknown_086ADA6E
_0801FC80: .4byte gMain+0x2BF0 @gMain.spriteGroups[57]
_0801FC84: .4byte 0x000002BE
_0801FC88: .4byte 0x000006BD
_0801FC8C: .4byte 0x000006BE
_0801FC90:
	movs r0, #1
	strh r0, [r2]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x54
	bne _0801FCC2
	mov r0, r8
	strb r0, [r1]
	ldr r0, [r4]
	add r0, sl
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r1, r0, r6
	movs r2, #0
	strh r2, [r1]
	add r0, ip
	mov r3, r8
	strb r3, [r0]
_0801FCC2:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3c
	beq _0801FD8E
	cmp r0, #0x45
	beq _0801FD8E
	cmp r0, #0x4e
	beq _0801FCDA
	b _0801FDFC
_0801FCDA:
	b _0801FD8E
_0801FCDC:
	cmp r1, r0
	bge _0801FD96
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r8, r0
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r2, [r1]
	cmp r8, r2
	bgt _0801FDAC
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, r6
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	bne _0801FD32
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _0801FD22
	add r1, ip
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0x54
	strb r1, [r0]
_0801FD22:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _0801FDFC
	b _0801FD8E
_0801FD32:
	cmp r2, #2
	bne _0801FD60
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x17
	bne _0801FD50
	mov r3, ip
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0x5f
	strb r1, [r0]
_0801FD50:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0801FDFC
	b _0801FD8E
_0801FD60:
	cmp r2, #3
	bne _0801FDFC
	adds r0, r1, r5
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0x23
	bne _0801FD80
	mov r6, ip
	adds r0, r1, r6
	strb r2, [r0]
	ldr r0, [r4]
	adds r0, r0, r5
	strb r3, [r0]
	movs r0, #7
	bl sub_19B64
_0801FD80:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	bne _0801FDFC
_0801FD8E:
	movs r0, 0xD2 @=SE_UNKNOWN_0xD2
	bl m4aSongNumStart
	b _0801FDFC
_0801FD96:
	cmp r0, #0
	beq _0801FDFC
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r8, r0
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r2, [r1]
	cmp r8, r2
	ble _0801FDB2
_0801FDAC:
	adds r0, r2, #1
	strh r0, [r1]
	b _0801FDFC
_0801FDB2:
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0801FDD8
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x5f
	bne _0801FDFC
	movs r0, #0x54
	b _0801FDFA
_0801FDD8:
	cmp r0, #2
	bne _0801FDEA
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x6d
	bne _0801FDFC
	movs r0, #0x5f
	b _0801FDFA
_0801FDEA:
	cmp r0, #3
	bne _0801FDFC
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x3c
	bne _0801FDFC
	movs r0, #0x23
_0801FDFA:
	strb r0, [r1]
_0801FDFC:
	ldrh r5, [r7]
	ldr r2, _0801FEE4 @ =0x040000D4
	movs r3, #4
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r4, _0801FEE8 @ =gUnknown_08447A8C
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEEC @ =0x06013B80
	str r0, [r2, #4]
	ldr r3, _0801FEF0 @ =0x800000C0
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r6, #6
	ldrsh r1, [r7, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEF4 @ =0x06013A00
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #8
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r4
	str r0, [r2]
	ldr r0, _0801FEF8 @ =0x06013880
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r2, _0801FEFC @ =gOamBuffer
	mov ip, r2
	ldr r3, _0801FF00 @ =gUnknown_086B2FC0
	mov sl, r3
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r6, r0, #2
	ldr r5, _0801FF04 @ =0xFFFFFE00
	mov r8, r5
_0801FE5E:
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	adds r1, r1, r6
	add r1, sl
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r4]
	lsls r2, r2, #3
	add r2, ip
	ldrh r7, [r2, #2]
	lsls r1, r7, #0x17
	lsrs r1, r1, #0x17
	mov r5, sb
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _0801FF08 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	ldrh r7, [r2, #2]
	ands r0, r7
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r5, [r1]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _0801FE5E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FEE4: .4byte 0x040000D4
_0801FEE8: .4byte gUnknown_08447A8C
_0801FEEC: .4byte 0x06013B80
_0801FEF0: .4byte 0x800000C0
_0801FEF4: .4byte 0x06013A00
_0801FEF8: .4byte 0x06013880
_0801FEFC: .4byte gOamBuffer
_0801FF00: .4byte gUnknown_086B2FC0
_0801FF04: .4byte 0xFFFFFE00
_0801FF08: .4byte 0x000001FF

