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
