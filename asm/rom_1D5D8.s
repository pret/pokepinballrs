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
