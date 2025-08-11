#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_350F0
sub_350F0: @ 0x080350F0
	push {r4, r5, lr}
	ldr r5, _08035118 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	ldr r3, [r5]
	movs r4, #0x17
	ldrsb r4, [r3, r4]
	cmp r4, #1
	beq _08035138
	cmp r4, #1
	bgt _0803511C
	cmp r4, #0
	beq _08035122
	b _080351A0
	.align 2, 0
_08035118: .4byte gCurrentPinballGame
_0803511C:
	cmp r4, #2
	beq _08035164
	b _080351A0
_08035122:
	movs r0, #0x41
	strh r0, [r3, #0x18]
	strb r1, [r3, #0x17]
	ldr r1, _08035134 @ =gMain
	ldrh r0, [r1, #0x38]
	movs r0, #0x9f
	strh r0, [r1, #0x38]
	b _080351A0
	.align 2, 0
_08035134: .4byte gMain
_08035138:
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	beq _080351A0
	subs r0, #1
	strh r0, [r3, #0x18]
	ldr r2, _08035160 @ =gMain
	ldrh r0, [r3, #0x18]
	lsrs r0, r0, #2
	movs r1, #0x10
	subs r1, r1, r0
	ldrh r0, [r2, #0x3c]
	strh r1, [r2, #0x3c]
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	bne _080351A0
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	b _080351A0
	.align 2, 0
_08035160: .4byte gMain
_08035164:
	ldrh r0, [r3, #0x18]
	cmp r0, #0x1d
	bhi _08035170
	adds r0, #1
	strh r0, [r3, #0x18]
	b _080351A0
_08035170:
	movs r0, #0
	strh r2, [r3, #0x18]
	strb r0, [r3, #0x17]
	ldr r1, _08035194 @ =gMain
	movs r3, #0xe9
	lsls r3, r3, #3
	adds r0, r1, r3
	strh r2, [r0]
	subs r3, #0xb8
	adds r0, r1, r3
	strh r2, [r0]
	ldrb r0, [r1, #5]
	ldrb r1, [r1, #4]
	cmp r0, r1
	beq _08035198
	bl sub_357B8
	b _080351A0
	.align 2, 0
_08035194: .4byte gMain
_08035198:
	bl ResetSomeGraphicsRelatedStuff
	ldr r0, [r5]
	strb r4, [r0, #0x1d]
_080351A0:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_351A8
sub_351A8: @ 0x080351A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r4, #8
	movs r0, #0
	mov r8, r0
	ldr r7, _080351F8 @ =gMain+0x748 @gMain.spriteGroups[6]
	ldr r0, _080351FC @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r2, r1, r3
	ldrh r3, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov sb, r0
	cmp r1, #0
	ble _080351E0
	subs r0, r3, #6
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080351E0
	mov r6, r8
	strh r6, [r2]
_080351E0:
	ldr r1, _08035200 @ =gMain
	ldrb r0, [r1, #4]
	subs r0, #2
	cmp r0, #4
	bls _080351EC
	b _08035314
_080351EC:
	lsls r0, r0, #2
	ldr r1, _08035204 @ =_08035208
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080351F8: .4byte gMain+0x748 @gMain.spriteGroups[6]
_080351FC: .4byte gCurrentPinballGame
_08035200: .4byte gMain
_08035204: .4byte _08035208
_08035208: @ jump table
	.4byte _0803521C @ case 0
	.4byte _08035250 @ case 1
	.4byte _08035280 @ case 2
	.4byte _080352B4 @ case 3
	.4byte _080352E8 @ case 4
_0803521C:
	mov r0, sb
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _08035244
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb3
	bhi _08035244
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08035244:
	ldr r1, _0803524C @ =0x01C9C380
	mov r8, r1
	b _08035314
	.align 2, 0
_0803524C: .4byte 0x01C9C380
_08035250:
	mov r2, sb
	ldr r1, [r2]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _08035278
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb3
	bhi _08035278
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08035278:
	ldr r3, _0803527C @ =0x01C9C380
	b _08035312
	.align 2, 0
_0803527C: .4byte 0x01C9C380
_08035280:
	mov r5, sb
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _080352A8
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb3
	bhi _080352A8
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080352A8:
	ldr r6, _080352B0 @ =gUnknown_02FAF080
	mov r8, r6
	b _08035314
	.align 2, 0
_080352B0: .4byte gUnknown_02FAF080
_080352B4:
	mov r0, sb
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _080352DC
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb3
	bhi _080352DC
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080352DC:
	ldr r1, _080352E4 @ =gUnknown_02FAF080
	mov r8, r1
	b _08035314
	.align 2, 0
_080352E4: .4byte gUnknown_02FAF080
_080352E8:
	mov r2, sb
	ldr r1, [r2]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _08035310
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb3
	bhi _08035310
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc
	bl __udivsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08035310:
	ldr r3, _080354A0 @ =0x05F5E0FF
_08035312:
	mov r8, r3
_08035314:
	ldr r2, _080354A4 @ =0x040000D4
	ldr r0, _080354A8 @ =gUnknown_02031520
	lsls r1, r4, #0x10
	asrs r1, r1, #0xb
	ldr r0, [r0, #0x2c]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080354AC @ =0x05000300
	str r0, [r2, #4]
	ldr r0, _080354B0 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrh r0, [r7]
	cmp r0, #0
	beq _080353F8
	movs r0, #0x78
	strh r0, [r7, #2]
	mov r5, sb
	ldr r0, [r5]
	movs r6, #0xe5
	lsls r6, r6, #2
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, #0x32
	strh r0, [r7, #4]
	movs r0, #0
	ldr r1, _080354B4 @ =gMain+0x690 @gMain.spriteGroups[5]
	mov sl, r1
	ldr r6, _080354B8 @ =gOamBuffer
	ldr r2, _080354BC @ =0xFFFFFE00
	mov ip, r2
_08035352:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080354C0 @ =0x000001FF
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
	cmp r4, #2
	ble _08035352
	mov r7, sl
	movs r0, #0x78
	strh r0, [r7, #2]
	mov r3, sb
	ldr r0, [r3]
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r0, #0x32
	strh r0, [r7, #4]
	movs r0, #0
	ldr r6, _080354B8 @ =gOamBuffer
	ldr r1, _080354BC @ =0xFFFFFE00
	mov ip, r1
_080353B4:
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
	ldr r2, _080354C0 @ =0x000001FF
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
	cmp r4, #0x11
	ble _080353B4
_080353F8:
	mov r5, sp
	ldr r4, _080354C4 @ =0x00989680
	mov r0, r8
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5]
	mov r5, sp
	mov r0, r8
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080354C8 @ =0x000F4240
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #2]
	mov r5, sp
	mov r0, r8
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080354CC @ =0x000186A0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #4]
	mov r5, sp
	mov r0, r8
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080354D0 @ =0x00002710
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #6]
	mov r5, sp
	mov r0, r8
	adds r1, r4, #0
	bl __modsi3
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #8]
	mov r5, sp
	mov r0, r8
	adds r1, r4, #0
	bl __modsi3
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0xa]
	mov r4, sp
	mov r0, r8
	movs r1, #0x64
	bl __modsi3
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0xc]
	mov r4, sp
	mov r0, r8
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #0xe]
	ldr r3, _080354D4 @ =gMain
	ldrb r0, [r3, #4]
	subs r0, #2
	cmp r0, #4
	bls _08035494
	b _08035678
_08035494:
	lsls r0, r0, #2
	ldr r1, _080354D8 @ =_080354DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080354A0: .4byte 0x05F5E0FF
_080354A4: .4byte 0x040000D4
_080354A8: .4byte gUnknown_02031520
_080354AC: .4byte 0x05000300
_080354B0: .4byte 0x80000010
_080354B4: .4byte gMain+0x690 @gMain.spriteGroups[5]
_080354B8: .4byte gOamBuffer
_080354BC: .4byte 0xFFFFFE00
_080354C0: .4byte 0x000001FF
_080354C4: .4byte 0x00989680
_080354C8: .4byte 0x000F4240
_080354CC: .4byte 0x000186A0
_080354D0: .4byte 0x00002710
_080354D4: .4byte gMain
_080354D8: .4byte _080354DC
_080354DC: @ jump table
	.4byte _080354F0 @ case 0
	.4byte _0803553C @ case 1
	.4byte _08035588 @ case 2
	.4byte _080355D4 @ case 3
	.4byte _08035620 @ case 4
_080354F0:
	movs r0, #0
	ldr r5, _0803552C @ =gUnknown_08138834
	ldr r3, _08035530 @ =0x040000D4
	adds r4, r5, #0
_080354F8:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	mov r6, sp
	adds r0, r6, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r0, #0x70
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r3]
	lsls r2, r2, #5
	ldr r0, _08035534 @ =0x06017180
	adds r2, r2, r0
	str r2, [r3, #4]
	ldr r2, _08035538 @ =0x80000020
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble _080354F8
	b _08035658
	.align 2, 0
_0803552C: .4byte gUnknown_08138834
_08035530: .4byte 0x040000D4
_08035534: .4byte 0x06017180
_08035538: .4byte 0x80000020
_0803553C:
	movs r0, #0
	ldr r5, _08035578 @ =gUnknown_0813A854
	ldr r3, _0803557C @ =0x040000D4
	adds r4, r5, #0
_08035544:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	mov r6, sp
	adds r0, r6, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r0, #0x70
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r3]
	lsls r2, r2, #5
	ldr r0, _08035580 @ =0x06017180
	adds r2, r2, r0
	str r2, [r3, #4]
	ldr r2, _08035584 @ =0x80000020
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble _08035544
	b _08035658
	.align 2, 0
_08035578: .4byte gUnknown_0813A854
_0803557C: .4byte 0x040000D4
_08035580: .4byte 0x06017180
_08035584: .4byte 0x80000020
_08035588:
	movs r0, #0
	ldr r5, _080355C4 @ =gUnknown_0813C874
	ldr r3, _080355C8 @ =0x040000D4
	adds r4, r5, #0
_08035590:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	mov r6, sp
	adds r0, r6, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r0, #0x70
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r3]
	lsls r2, r2, #5
	ldr r0, _080355CC @ =0x06017180
	adds r2, r2, r0
	str r2, [r3, #4]
	ldr r2, _080355D0 @ =0x80000020
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble _08035590
	b _08035658
	.align 2, 0
_080355C4: .4byte gUnknown_0813C874
_080355C8: .4byte 0x040000D4
_080355CC: .4byte 0x06017180
_080355D0: .4byte 0x80000020
_080355D4:
	movs r0, #0
	ldr r5, _08035610 @ =gUnknown_0813E894
	ldr r3, _08035614 @ =0x040000D4
	adds r4, r5, #0
_080355DC:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	mov r6, sp
	adds r0, r6, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r0, #0x70
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r3]
	lsls r2, r2, #5
	ldr r0, _08035618 @ =0x06017180
	adds r2, r2, r0
	str r2, [r3, #4]
	ldr r2, _0803561C @ =0x80000020
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble _080355DC
	b _08035658
	.align 2, 0
_08035610: .4byte gUnknown_0813E894
_08035614: .4byte 0x040000D4
_08035618: .4byte 0x06017180
_0803561C: .4byte 0x80000020
_08035620:
	movs r0, #0
	ldr r5, _08035688 @ =gUnknown_081408B4
	ldr r3, _0803568C @ =0x040000D4
	adds r4, r5, #0
_08035628:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	mov r6, sp
	adds r0, r6, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r0, #0x70
	lsls r0, r0, #6
	adds r0, r0, r4
	str r0, [r3]
	lsls r2, r2, #5
	ldr r0, _08035690 @ =0x06017180
	adds r2, r2, r0
	str r2, [r3, #4]
	ldr r2, _08035694 @ =0x80000020
	str r2, [r3, #8]
	ldr r0, [r3, #8]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	ble _08035628
_08035658:
	mov r1, sb
	ldr r0, [r1]
	ldr r3, _08035698 @ =0x000005F6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0803568C @ =0x040000D4
	adds r0, #0x71
	lsls r0, r0, #6
	adds r0, r0, r5
	str r0, [r1]
	ldr r0, _0803569C @ =0x06017380
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
_08035678:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035688: .4byte gUnknown_081408B4
_0803568C: .4byte 0x040000D4
_08035690: .4byte 0x06017180
_08035694: .4byte 0x80000020
_08035698: .4byte 0x000005F6
_0803569C: .4byte 0x06017380

	.section .text36CB4

	thumb_func_start sub_372B4
sub_372B4: @ 0x080372B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08037478 @ =gMain+0x1438 @gMain.spriteGroups[24]
	mov sl, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _080372CA
	b _08037500
_080372CA:
	ldr r1, _0803747C @ =gCurrentPinballGame
	mov sb, r1
	ldr r1, [r1]
	ldr r2, _08037480 @ =0x00000404
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080372E0
	b _080374C0
_080372E0:
	ldr r3, _08037484 @ =0x0000040A
	mov r8, r3
	adds r0, r1, r3
	ldrh r5, [r0]
	cmp r5, #0
	bne _08037318
	bl Random
	mov r1, sb
	ldr r4, [r1]
	ldr r1, _08037488 @ =0xFFFFEBC8
	add r1, sl
	ldr r1, [r1, #0x4c]
	muls r0, r1, r0
	movs r1, #5
	bl __umodsi3
	ldr r2, _0803748C @ =0x00000405
	adds r4, r4, r2
	strb r0, [r4]
	mov r3, sb
	ldr r0, [r3]
	adds r2, #0x11
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _08037490 @ =0x0000041A
	adds r0, r0, r3
	strh r5, [r0]
_08037318:
	mov r1, sb
	ldr r0, [r1]
	mov r2, r8
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0x27
	bhi _0803732A
	adds r0, #1
	strh r0, [r1]
_0803732A:
	mov r3, sb
	ldr r0, [r3]
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0x14
	bne _0803733C
	ldr r0, _08037494 @ =gMPlayInfo_SE2
	bl m4aMPlayStop
_0803733C:
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0x16
	bne _0803734E
	ldr r0, _08037498 @ =0x00000105
	bl m4aSongNumStart
_0803734E:
	mov r2, sb
	ldr r4, [r2]
	mov r3, r8
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x14
	bhi _0803735E
	b _080374B4
_0803735E:
	ldr r0, _0803749C @ =0x00000414
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	ldr r1, _080374A0 @ =0x00000416
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r0, #3
	strh r0, [r5]
	ldr r3, _080374A4 @ =gUnknown_086AEA3C
	ldr r0, _0803748C @ =0x00000405
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r8, r0
	adds r1, #2
	adds r0, r4, r1
	mov r1, r8
	strh r1, [r0]
	ldr r0, _08037490 @ =0x0000041A
	adds r4, r4, r0
	ldrh r0, [r5]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #2
	adds r1, r1, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r1, #2]
	movs r3, #2
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble _080373BC
	strh r2, [r4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #6
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r5]
_080373BC:
	mov r2, sb
	ldr r2, [r2]
	mov r8, r2
	ldr r0, _080374A8 @ =0x0000132C
	add r0, r8
	ldr r5, [r0]
	movs r3, #0x10
	ldrsh r4, [r5, r3]
	subs r4, #8
	movs r0, #0x83
	lsls r0, r0, #3
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r6, r4, r0
	movs r2, #0x12
	ldrsh r4, [r5, r2]
	subs r4, #8
	ldr r0, _08037490 @ =0x0000041A
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r7, r4, r0
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r7, #0
	muls r1, r7, r1
	adds r0, r0, r1
	cmp r0, #0x78
	bgt _08037438
	ldr r1, _08037480 @ =0x00000404
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	mov r6, sb
	ldr r0, [r6]
	ldr r1, _080374AC @ =0x00000406
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r6]
	movs r3, #0x81
	lsls r3, r3, #3
	adds r1, r2, r3
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080374B0 @ =0x00002710
	str r0, [r2, #0x3c]
	movs r0, #0x83
	lsls r0, r0, #1
	bl m4aSongNumStart
_08037438:
	mov r6, sb
	ldr r5, [r6]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r4, [r0]
	rsbs r4, r4, #0
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	mov r3, sl
	strh r4, [r3, #2]
	adds r0, r5, #0
	adds r0, #0x5a
	ldrh r4, [r0]
	rsbs r4, r4, #0
	ldr r6, _08037490 @ =0x0000041A
	adds r5, r5, r6
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	mov r2, sl
	strh r4, [r2, #4]
	b _080374C8
	.align 2, 0
_08037478: .4byte gMain+0x1438 @gMain.spriteGroups[24]
_0803747C: .4byte gCurrentPinballGame
_08037480: .4byte 0x00000404
_08037484: .4byte 0x0000040A
_08037488: .4byte 0xFFFFEBC8
_0803748C: .4byte 0x00000405
_08037490: .4byte 0x0000041A
_08037494: .4byte gMPlayInfo_SE2
_08037498: .4byte 0x00000105
_0803749C: .4byte 0x00000414
_080374A0: .4byte 0x00000416
_080374A4: .4byte gUnknown_086AEA3C
_080374A8: .4byte 0x0000132C
_080374AC: .4byte 0x00000406
_080374B0: .4byte 0x00002710
_080374B4:
	movs r0, #0
	mov r3, sl
	strh r0, [r3, #2]
	movs r0, #0xb4
	strh r0, [r3, #4]
	b _080374C8
_080374C0:
	mov r6, sl
	strh r0, [r6, #2]
	movs r0, #0xb4
	strh r0, [r6, #4]
_080374C8:
	mov r5, sl
	adds r5, #8
	ldr r4, _08037510 @ =gOamBuffer
	mov r0, sl
	ldrh r2, [r0, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r6, #2
	ldrsh r0, [r0, r6]
	adds r1, r1, r0
	ldr r3, _08037514 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08037518 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r6, sl
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
_08037500:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037510: .4byte gOamBuffer
_08037514: .4byte 0x000001FF
_08037518: .4byte 0xFFFFFE00

	thumb_func_start sub_3751C
sub_3751C: @ 0x0803751C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _08037550 @ =gCurrentPinballGame
	ldr r3, [r1]
	ldr r0, _08037554 @ =0x00000406
	adds r4, r3, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	mov sb, r1
	cmp r0, #0
	beq _08037564
	movs r1, #0x81
	lsls r1, r1, #3
	adds r2, r3, r1
	ldrh r1, [r2]
	ldr r0, _08037558 @ =0x00000257
	cmp r1, r0
	bhi _0803755C
	adds r0, r1, #1
	strh r0, [r2]
	b _08037564
	.align 2, 0
_08037550: .4byte gCurrentPinballGame
_08037554: .4byte 0x00000406
_08037558: .4byte 0x00000257
_0803755C:
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
_08037564:
	mov r2, sb
	ldr r1, [r2]
	ldr r3, _08037588 @ =0x00000406
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08037590
	ldr r0, _0803758C @ =0x0000040E
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080375AE
	adds r0, #1
	strh r0, [r1]
	b _080375AE
	.align 2, 0
_08037588: .4byte 0x00000406
_0803758C: .4byte 0x0000040E
_08037590:
	ldr r2, _080375A4 @ =0x0000040E
	adds r3, r1, r2
	ldrh r0, [r3]
	adds r2, r0, #0
	cmp r2, #0
	beq _080375A8
	subs r0, #1
	strh r0, [r3]
	b _080375AE
	.align 2, 0
_080375A4: .4byte 0x0000040E
_080375A8:
	ldr r3, _08037804 @ =0x000003F5
	adds r0, r1, r3
	strb r2, [r0]
_080375AE:
	ldr r3, _08037808 @ =gMain
	mov r0, sb
	ldr r2, [r0]
	ldr r0, _0803780C @ =0x0000040E
	adds r1, r2, r0
	ldrh r0, [r1]
	lsls r0, r0, #4
	strh r0, [r3, #0x2e]
	ldrh r1, [r1]
	lsls r0, r1, #0x16
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #1
	movs r0, #0x14
	subs r0, r0, r1
	lsls r0, r0, #0x15
	lsrs r4, r0, #0x10
	movs r1, #0x81
	lsls r1, r1, #3
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #9
	bl __udivsi3
	ldr r2, _08037810 @ =gUnknown_086AEA60
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _08037814 @ =gUnknown_086AEA50
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r2, #0
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	cmp r2, r1
	bge _0803763A
	ldr r0, _08037818 @ =gUnknown_03006400
	ldr r3, _0803781C @ =0xFFFFF800
	adds r7, r0, r3
	movs r6, #0x80
	lsls r6, r6, #3
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	adds r3, r1, #0
_0803761A:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r6
	lsls r2, r2, #1
	adds r2, r2, r7
	adds r0, r4, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r3
	blt _0803761A
_0803763A:
	mov r0, r8
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	ldr r2, _08037820 @ =0x0000027F
	cmp r0, r2
	bgt _08037662
	ldr r5, _08037824 @ =gUnknown_03005C00
	movs r4, #0x80
	lsls r4, r4, #3
	ldr r3, _08037828 @ =0x000003FF
_0803764E:
	asrs r0, r1, #0x10
	adds r1, r0, r4
	lsls r1, r1, #1
	adds r1, r1, r5
	strh r3, [r1]
	adds r0, #1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, r2
	ble _0803764E
_08037662:
	mov r1, sb
	ldr r0, [r1]
	movs r4, #0x81
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x96
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r0, #0x10
	ldr r2, _0803782C @ =0xFFF60000
	adds r0, r1, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x45
	bhi _08037726
	movs r3, #0
	mov sb, r1
	ldr r0, [sp]
	lsls r1, r0, #0x10
	ldr r2, _08037824 @ =gUnknown_03005C00
	mov r8, r2
	ldr r0, _08037830 @ =gUnknown_08327994
	mov ip, r0
	asrs r6, r1, #0xe
	adds r7, r4, #0
_0803769A:
	movs r2, #0
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	adds r0, r1, #6
	lsls r5, r0, #5
	adds r1, #0x15
	lsls r4, r1, #5
_080376A8:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r7
	adds r2, r5, r2
	lsls r2, r2, #1
	add r2, r8
	adds r0, r1, r6
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	ble _080376A8
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0803769A
	mov r2, sb
	asrs r0, r2, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _080376F0
	movs r1, #5
_080376F0:
	movs r2, #0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _08037726
	ldr r7, _08037824 @ =gUnknown_03005C00
	ldr r6, _08037834 @ =0x000004C3
	ldr r5, _08037830 @ =gUnknown_08327994
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r3, r0, #0
_08037706:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r6
	lsls r2, r2, #1
	adds r2, r2, r7
	adds r0, r1, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r3
	blt _08037706
_08037726:
	mov r3, sl
	lsls r1, r3, #0x10
	ldr r2, _08037838 @ =0xFFB00000
	adds r0, r1, r2
	lsrs r0, r0, #0x10
	mov sb, r1
	cmp r0, #0x45
	bhi _080377E2
	movs r3, #0
	ldr r0, [sp]
	lsls r1, r0, #0x10
	ldr r2, _08037824 @ =gUnknown_03005C00
	mov ip, r2
	ldr r0, _08037830 @ =gUnknown_08327994
	mov r8, r0
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r6, r0, #0
	adds r6, #0xc
	ldr r7, _0803783C @ =0x00000411
_08037752:
	movs r2, #0
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	adds r0, r1, #0
	adds r0, #0xe
	lsls r5, r0, #5
	adds r1, #0x15
	lsls r4, r1, #5
_08037762:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r7
	adds r2, r5, r2
	lsls r2, r2, #1
	add r2, ip
	adds r0, r1, r6
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #5
	ble _08037762
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08037752
	mov r2, sb
	asrs r0, r2, #0x10
	subs r0, #0x46
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _080377AC
	movs r1, #5
_080377AC:
	movs r2, #0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _080377E2
	ldr r7, _08037824 @ =gUnknown_03005C00
	ldr r6, _08037840 @ =0x000005F7
	ldr r5, _08037830 @ =gUnknown_08327994
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r3, r0, #0
_080377C2:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r6
	lsls r2, r2, #1
	adds r2, r2, r7
	adds r0, r1, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r3
	blt _080377C2
_080377E2:
	ldr r1, _08037844 @ =0x040000D4
	ldr r3, _08037818 @ =gUnknown_03006400
	str r3, [r1]
	ldr r0, _08037848 @ =0x06001000
	str r0, [r1, #4]
	ldr r0, _0803784C @ =0x80000280
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037804: .4byte 0x000003F5
_08037808: .4byte gMain
_0803780C: .4byte 0x0000040E
_08037810: .4byte gUnknown_086AEA60
_08037814: .4byte gUnknown_086AEA50
_08037818: .4byte gUnknown_03006400
_0803781C: .4byte 0xFFFFF800
_08037820: .4byte 0x0000027F
_08037824: .4byte gUnknown_03005C00
_08037828: .4byte 0x000003FF
_0803782C: .4byte 0xFFF60000
_08037830: .4byte gUnknown_08327994
_08037834: .4byte 0x000004C3
_08037838: .4byte 0xFFB00000
_0803783C: .4byte 0x00000411
_08037840: .4byte 0x000005F7
_08037844: .4byte 0x040000D4
_08037848: .4byte 0x06001000
_0803784C: .4byte 0x80000280

	thumb_func_start sub_37850
sub_37850: @ 0x08037850
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08037C18 @ =gCurrentPinballGame
	ldr r3, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #0x11
	lsrs r1, r1, #0x10
	ldr r2, _08037C1C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r5, _08037C20 @ =0x00000402
	adds r3, r3, r5
	movs r2, #0
	ldrsh r1, [r3, r2]
	lsls r1, r1, #0x11
	ldr r2, _08037C24 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sp
	bl sub_17C1C
	ldr r0, _08037C28 @ =gUnknown_02031590
	ldrb r1, [r0, #0x10]
	movs r0, #0xb8
	muls r1, r0, r1
	ldr r0, _08037C2C @ =gMain+0x2F8 @gMain.spriteGroups
	adds r6, r1, r0
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x78
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r0, [r1]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r2, #0
	ldr r5, _08037C30 @ =gOamBuffer
	ldr r3, _08037C34 @ =0xFFFFFE00
	mov sb, r3
_080378BC:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r0, _08037C38 @ =0x000001FF
	mov r8, r0
	mov r2, r8
	ands r1, r2
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _080378BC
	ldr r0, _08037C28 @ =gUnknown_02031590
	ldrb r1, [r0, #0x11]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r3, _08037C2C @ =gMain+0x2F8 @gMain.spriteGroups
	mov sb, r3
	adds r6, r0, r3
	ldr r5, _08037C18 @ =gCurrentPinballGame
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x78
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r0, [r1]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	adds r7, r6, #0
	adds r7, #8
	ldr r4, _08037C30 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08037C34 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	movs r6, #0xa1
	lsls r6, r6, #3
	add r6, sb
	ldr r0, [r5]
	ldr r1, _08037C3C @ =0x0000040C
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	movs r1, #5
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r7, #0x14
	cmp r4, #0x1e
	bhi _08037988
	movs r7, #5
	cmp r4, #0xa
	bls _08037988
	movs r7, #0xa
_08037988:
	ldr r4, _08037C18 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _08037C3C @ =0x0000040C
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0x28
	bne _080379A4
	movs r0, #0x82
	lsls r0, r0, #1
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_080379A4:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080379B2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080379B2:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	movs r0, #5
	subs r0, r0, r1
	muls r0, r7, r0
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x78
	ldr r2, [r4]
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r2, #0x5a
	ldrh r0, [r2]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r2, #0
	ldr r5, _08037C30 @ =gOamBuffer
	ldr r3, _08037C34 @ =0xFFFFFE00
	mov r8, r3
_080379E2:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08037C38 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #4
	ble _080379E2
	ldr r3, _08037C18 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r5, _08037C3C @ =0x0000040C
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _08037A38
	subs r0, #1
	strh r0, [r1]
_08037A38:
	movs r0, #0
	mov r8, r0
_08037A3C:
	mov r1, r8
	lsls r3, r1, #0x10
	asrs r3, r3, #0x10
	adds r0, r3, #0
	adds r0, #0xa
	ldr r2, _08037C28 @ =gUnknown_02031590
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r5, _08037C2C @ =gMain+0x2F8 @gMain.spriteGroups
	adds r6, r0, r5
	ldr r0, _08037C18 @ =gCurrentPinballGame
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r1, #0
	mov sb, r1
	movs r5, #0x84
	lsls r5, r5, #3
	adds r2, r2, r5
	adds r4, r2, r3
	ldrb r5, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _08037AA6
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	ldr r1, _08037C40 @ =gUnknown_086AEA68
	adds r0, r0, r1
	ldrh r0, [r0]
	mov sb, r0
	subs r0, r5, #1
	strb r0, [r4]
_08037AA6:
	movs r2, #0
	mov r3, sb
	lsls r0, r3, #0x10
	ldr r5, _08037C30 @ =gOamBuffer
	mov ip, r5
	ldr r1, _08037C34 @ =0xFFFFFE00
	mov sl, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd2
	mov sb, r0
_08037AC0:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	adds r0, r5, #0
	adds r0, #8
	adds r7, r6, r0
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r7, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08037C38 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r6, #4]
	ldrb r2, [r7, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	add r5, sb
	ldr r3, _08037C44 @ =0x000003FF
	adds r0, r3, #0
	ands r5, r0
	ldrh r0, [r2, #4]
	ldr r3, _08037C48 @ =0xFFFFFC00
	adds r1, r3, #0
	ands r0, r1
	orrs r0, r5
	strh r0, [r2, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08037AC0
	mov r5, r8
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	mov r8, r2
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08037A3C
	movs r3, #6
	mov r8, r3
_08037B38:
	mov r5, r8
	lsls r4, r5, #0x10
	asrs r3, r4, #0x10
	adds r0, r3, #0
	adds r0, #0xc
	ldr r1, _08037C28 @ =gUnknown_02031590
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r2, _08037C2C @ =gMain+0x2F8 @gMain.spriteGroups
	adds r6, r0, r2
	ldr r5, _08037C18 @ =gCurrentPinballGame
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r0, #0
	mov sb, r0
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r5, r2, r3
	ldrb r7, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	mov sl, r4
	cmp r0, #0
	beq _08037BA4
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	ldr r2, _08037C40 @ =gUnknown_086AEA68
	adds r0, r0, r2
	ldrh r0, [r0]
	mov sb, r0
	subs r0, r7, #1
	strb r0, [r5]
_08037BA4:
	movs r2, #0
	mov r3, sb
	lsls r0, r3, #0x10
	ldr r5, _08037C30 @ =gOamBuffer
	mov ip, r5
	ldr r1, _08037C34 @ =0xFFFFFE00
	mov sb, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd2
	mov r8, r0
_08037BBE:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	adds r0, r5, #0
	adds r0, #8
	adds r7, r6, r0
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	movs r3, #2
	ldrsh r1, [r7, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08037C38 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r6, #4]
	ldrb r2, [r7, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	add r5, r8
	ldr r3, _08037C44 @ =0x000003FF
	adds r0, r3, #0
	ands r5, r0
	ldrh r0, [r2, #4]
	ldr r3, _08037C48 @ =0xFFFFFC00
	adds r1, r3, #0
	ands r0, r1
	orrs r0, r5
	strh r0, [r2, #4]
	adds r4, #1
	b _08037C4C
	.align 2, 0
_08037C18: .4byte gCurrentPinballGame
_08037C1C: .4byte 0xFFFF0000
_08037C20: .4byte 0x00000402
_08037C24: .4byte 0x0000FFFF
_08037C28: .4byte gUnknown_02031590
_08037C2C: .4byte gMain+0x2F8 @gMain.spriteGroups
_08037C30: .4byte gOamBuffer
_08037C34: .4byte 0xFFFFFE00
_08037C38: .4byte 0x000001FF
_08037C3C: .4byte 0x0000040C
_08037C40: .4byte gUnknown_086AEA68
_08037C44: .4byte 0x000003FF
_08037C48: .4byte 0xFFFFFC00
_08037C4C:
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08037BBE
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r5, r0, #0x10
	mov r8, r5
	asrs r0, r0, #0x10
	cmp r0, #9
	bgt _08037C68
	b _08037B38
_08037C68:
	ldr r6, _08037F58 @ =gMain+0x14F0 @gMain.spriteGroups[25]
	ldr r1, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r2, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r0, [r0]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r3, #0
	mov sb, r3
	ldr r0, [r2]
	ldr r1, _08037F60 @ =0x0000041C
	adds r5, r0, r1
	ldrb r7, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08037CBA
	ldr r4, _08037F64 @ =gUnknown_086AEA68
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	mov sb, r0
	subs r0, r7, #1
	strb r0, [r5]
_08037CBA:
	movs r2, #0
	mov r3, sb
	lsls r0, r3, #0x10
	ldr r5, _08037F68 @ =gOamBuffer
	mov r8, r5
	ldr r1, _08037F6C @ =0xFFFFFE00
	mov ip, r1
	asrs r0, r0, #0xd
	adds r0, #0xf6
	mov sb, r0
	ldr r3, _08037F70 @ =0xFFFFFC00
	mov sl, r3
_08037CD2:
	lsls r4, r2, #0x10
	asrs r5, r4, #0x10
	lsls r0, r5, #3
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, r8
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08037F74 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r3, [r7, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, r8
	lsls r1, r5, #2
	lsrs r4, r4, #0x1f
	adds r4, r5, r4
	asrs r4, r4, #1
	lsls r4, r4, #1
	subs r1, r1, r4
	add r1, sb
	ldr r2, _08037F78 @ =0x000003FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #4]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _08037CD2
	movs r3, #0
	mov r8, r3
_08037D3E:
	mov r5, r8
	lsls r4, r5, #0x10
	asrs r3, r4, #0x10
	movs r0, #0xb8
	muls r0, r3, r0
	ldr r1, _08037F7C @ =gMain+0x15A8 @gMain.spriteGroups[26]
	adds r6, r0, r1
	ldr r5, _08037F5C @ =gCurrentPinballGame
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r0, #0
	mov sb, r0
	adds r2, r2, r3
	ldr r1, _08037F80 @ =0x0000041D
	adds r5, r2, r1
	ldrb r7, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	mov sl, r4
	cmp r0, #0
	beq _08037D9E
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	ldr r2, _08037F64 @ =gUnknown_086AEA68
	adds r0, r0, r2
	ldrh r0, [r0]
	mov sb, r0
	subs r0, r7, #1
	strb r0, [r5]
_08037D9E:
	movs r2, #0
	mov r3, sb
	lsls r0, r3, #0x10
	ldr r5, _08037F68 @ =gOamBuffer
	mov ip, r5
	ldr r1, _08037F6C @ =0xFFFFFE00
	mov sb, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r3, #0x87
	lsls r3, r3, #1
	adds r3, r3, r0
	mov r8, r3
_08037DBC:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	adds r0, r5, #0
	adds r0, #8
	adds r7, r6, r0
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08037F74 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r6, #4]
	ldrb r2, [r7, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, ip
	add r5, r8
	ldr r3, _08037F78 @ =0x000003FF
	adds r0, r3, #0
	ands r5, r0
	ldrh r0, [r2, #4]
	ldr r3, _08037F70 @ =0xFFFFFC00
	adds r1, r3, #0
	ands r0, r1
	orrs r0, r5
	strh r0, [r2, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08037DBC
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sl
	lsrs r5, r0, #0x10
	mov r8, r5
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08037D3E
	ldr r6, _08037F84 @ =gMain+0x1718 @gMain.spriteGroups[28]
	ldr r1, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r2, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r0, [r0]
	rsbs r0, r0, #0
	subs r0, #0x80
	strh r0, [r6, #4]
	movs r3, #0
	mov sb, r3
	ldr r0, [r2]
	ldr r1, _08037F88 @ =0x0000041F
	adds r5, r0, r1
	ldrb r7, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _08037E7E
	ldr r4, _08037F64 @ =gUnknown_086AEA68
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	mov sb, r0
	subs r0, r7, #1
	strb r0, [r5]
_08037E7E:
	movs r2, #0
	mov r3, sb
	lsls r0, r3, #0x10
	ldr r5, _08037F68 @ =gOamBuffer
	mov r8, r5
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x99
	lsls r1, r1, #1
	adds r1, r1, r0
	mov ip, r1
_08037E98:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r5, r4, #3
	adds r0, r5, #0
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	add r3, r8
	movs r2, #2
	ldrsh r1, [r7, r2]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r0, _08037F74 @ =0x000001FF
	mov sl, r0
	mov r2, sl
	ands r1, r2
	ldrh r2, [r3, #2]
	ldr r0, _08037F6C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r6, #4]
	ldrb r3, [r7, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, r8
	add r5, ip
	ldr r2, _08037F78 @ =0x000003FF
	adds r0, r2, #0
	ands r5, r0
	ldrh r2, [r1, #4]
	ldr r0, _08037F70 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r5
	strh r0, [r1, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08037E98
	ldr r6, _08037F8C @ =gMain+0x19F8 @gMain.spriteGroups[32]
	ldr r3, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r4, _08037F90 @ =0x0000132C
	adds r0, r0, r4
	ldr r0, [r0]
	ldrh r0, [r0, #0x24]
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r0, r0, r4
	ldr r0, [r0]
	ldrh r0, [r0, #0x26]
	adds r0, #0xe
	strh r0, [r6, #4]
	adds r7, r6, #0
	adds r7, #8
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	ldr r5, _08037F68 @ =gOamBuffer
	adds r2, r2, r5
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	mov r5, sl
	ands r1, r5
	ldrh r3, [r2, #2]
	ldr r0, _08037F6C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldr r1, _08037F5C @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r4
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08037F94
	ldrh r0, [r6, #8]
	lsls r0, r0, #3
	ldr r2, _08037F68 @ =gOamBuffer
	adds r0, r0, r2
	movs r1, #0xc8
	strb r1, [r0]
	b _08037FA4
	.align 2, 0
_08037F58: .4byte gMain+0x14F0 @gMain.spriteGroups[25]
_08037F5C: .4byte gCurrentPinballGame
_08037F60: .4byte 0x0000041C
_08037F64: .4byte gUnknown_086AEA68
_08037F68: .4byte gOamBuffer
_08037F6C: .4byte 0xFFFFFE00
_08037F70: .4byte 0xFFFFFC00
_08037F74: .4byte 0x000001FF
_08037F78: .4byte 0x000003FF
_08037F7C: .4byte gMain+0x15A8 @gMain.spriteGroups[26]
_08037F80: .4byte 0x0000041D
_08037F84: .4byte gMain+0x1718 @gMain.spriteGroups[28]
_08037F88: .4byte 0x0000041F
_08037F8C: .4byte gMain+0x19F8 @gMain.spriteGroups[32]
_08037F90: .4byte 0x0000132C
_08037F94:
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	ldr r3, _08037FC0 @ =gOamBuffer
	adds r1, r1, r3
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
_08037FA4:
	ldr r6, _08037FC4 @ =gMain+0x17D0 @gMain.spriteGroups[29]
	ldr r5, _08037FC8 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r2, #0x82
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xb
	bgt _08037FCC
	adds r0, r2, #1
	b _08037FCE
	.align 2, 0
_08037FC0: .4byte gOamBuffer
_08037FC4: .4byte gMain+0x17D0 @gMain.spriteGroups[29]
_08037FC8: .4byte gCurrentPinballGame
_08037FCC:
	movs r0, #0
_08037FCE:
	strh r0, [r1]
	movs r5, #0
	mov r8, r5
	ldr r0, _08038048 @ =gCurrentPinballGame
	mov sl, r0
	ldr r5, _0803804C @ =gOamBuffer
	ldr r1, _08038050 @ =0xFFFFFE00
	mov ip, r1
_08037FDE:
	mov r2, sl
	ldr r0, [r2]
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r2, r1, #0x10
	ldr r1, _08038054 @ =0x0000042A
	adds r0, r0, r1
	adds r3, r0, r2
	ldrb r4, [r3]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _0803805C
	adds r1, r0, #0
	cmp r1, #0
	bge _08038000
	adds r1, #3
_08038000:
	asrs r1, r1, #2
	movs r0, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	subs r0, r4, #1
	strb r0, [r3]
	mov r0, sl
	ldr r3, [r0]
	lsls r2, r2, #2
	adds r2, r3, r2
	adds r0, r2, #0
	adds r0, #0xd0
	adds r1, r3, #0
	adds r1, #0x4c
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r0, #4
	strh r0, [r6, #2]
	adds r2, #0xd2
	adds r1, r3, #0
	adds r1, #0x4e
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r2, _08038058 @ =0x000005FC
	adds r1, r3, r2
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #0xe6
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #4
	b _08038062
	.align 2, 0
_08038048: .4byte gCurrentPinballGame
_0803804C: .4byte gOamBuffer
_08038050: .4byte 0xFFFFFE00
_08038054: .4byte 0x0000042A
_08038058: .4byte 0x000005FC
_0803805C:
	movs r0, #0xf0
	strh r0, [r6, #2]
	movs r0, #0xb4
_08038062:
	strh r0, [r6, #4]
	mov r3, r8
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _080380E8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r6, #4]
	ldrb r3, [r7, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r3, [r7]
	lsls r3, r3, #3
	adds r3, r3, r5
	mov r0, sb
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r2, _080380EC @ =0x000003FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #4]
	ldr r0, _080380F0 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r3, r4, #0x10
	mov r8, r3
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08037FDE
	ldr r6, _080380F4 @ =gMain+0x1888 @gMain.spriteGroups[30]
	ldr r5, _080380F8 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, _080380FC @ =0x00000412
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x17
	bgt _08038100
	adds r0, r2, #1
	b _08038102
	.align 2, 0
_080380E8: .4byte 0x000001FF
_080380EC: .4byte 0x000003FF
_080380F0: .4byte 0xFFFFFC00
_080380F4: .4byte gMain+0x1888 @gMain.spriteGroups[30]
_080380F8: .4byte gCurrentPinballGame
_080380FC: .4byte 0x00000412
_08038100:
	movs r0, #0
_08038102:
	strh r0, [r1]
	movs r5, #0
	mov r8, r5
_08038108:
	ldr r1, _08038168 @ =gCurrentPinballGame
	ldr r0, [r1]
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r4, r1, #0x10
	adds r0, r0, r4
	ldr r3, _0803816C @ =0x0000042E
	adds r5, r0, r3
	ldrb r7, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	mov sl, r1
	cmp r0, #0
	beq _08038178
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	subs r0, r7, #1
	strb r0, [r5]
	ldr r5, _08038168 @ =gCurrentPinballGame
	ldr r3, [r5]
	lsls r2, r4, #2
	adds r2, r3, r2
	ldr r1, _08038170 @ =0x00000434
	adds r0, r2, r1
	adds r1, r3, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #4
	strh r0, [r6, #2]
	ldr r5, _08038174 @ =0x00000436
	adds r2, r2, r5
	adds r3, #0x5a
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #2
	b _0803817E
	.align 2, 0
_08038168: .4byte gCurrentPinballGame
_0803816C: .4byte 0x0000042E
_08038170: .4byte 0x00000434
_08038174: .4byte 0x00000436
_08038178:
	movs r0, #0xf0
	strh r0, [r6, #2]
	movs r0, #0xb4
_0803817E:
	strh r0, [r6, #4]
	mov r0, sl
	asrs r4, r0, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r7, r6, r0
	ldrh r3, [r7]
	lsls r3, r3, #3
	ldr r1, _08038204 @ =gOamBuffer
	adds r3, r3, r1
	movs r5, #2
	ldrsh r2, [r7, r5]
	movs r1, #2
	ldrsh r0, [r6, r1]
	adds r2, r2, r0
	ldr r5, _08038208 @ =0x000001FF
	adds r0, r5, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r5, _0803820C @ =0xFFFFFE00
	adds r1, r5, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	ldr r0, _08038204 @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r6, #4]
	ldrb r2, [r7, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r3, [r7]
	lsls r3, r3, #3
	ldr r5, _08038204 @ =gOamBuffer
	adds r3, r3, r5
	mov r0, sb
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r5, _08038210 @ =0x000003FF
	adds r0, r5, #0
	ands r1, r0
	ldrh r0, [r3, #4]
	ldr r5, _08038214 @ =0xFFFFFC00
	adds r2, r5, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	mov r8, r0
	asrs r4, r4, #0x10
	cmp r4, #2
	ble _08038108
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038204: .4byte gOamBuffer
_08038208: .4byte 0x000001FF
_0803820C: .4byte 0xFFFFFE00
_08038210: .4byte 0x000003FF
_08038214: .4byte 0xFFFFFC00

	thumb_func_start sub_38218
sub_38218: @ 0x08038218
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	movs r5, #0
	ldr r0, _080382D8 @ =gUnknown_086AEA70
	mov sl, r0
	ldr r1, _080382DC @ =gCurrentPinballGame
	mov r8, r1
	add r6, sp, #0x64
	ldr r4, _080382E0 @ =gUnknown_0202D880
	ldr r3, _080382E4 @ =gUnknown_086BB420
_08038234:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r2, r0, r4
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x20
	ble _08038234
	mov r2, sl
	ldr r0, [r2, #0x60]
	ldr r1, [r2, #0x64]
	str r0, [sp, #0x60]
	str r1, [sp, #0x64]
	mov r3, r8
	ldr r0, [r3]
	ldr r1, _080382E8 @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	strb r0, [r6]
	movs r5, #0
	mov r7, sl
	mov r4, r8
	ldr r0, [r4]
	mov ip, r1
	add r0, ip
	str r0, [sp, #0x70]
	mov sb, sl
_08038276:
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	lsls r2, r3, #3
	adds r4, r2, r7
	ldrb r1, [r4, #4]
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	movs r6, #0x12
	ldrsh r0, [r0, r6]
	cmp r1, r0
	bge _080382EC
	movs r0, #0xb
	cmp r0, r3
	blt _080382BA
	mov r6, sb
	adds r4, r3, #0
_08038296:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r2, #1
	lsls r0, r0, #3
	mov r1, sp
	adds r3, r1, r0
	lsls r0, r2, #3
	adds r0, r0, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, r4
	bge _08038296
_080382BA:
	lsls r0, r5, #0x10
	asrs r0, r0, #0xd
	mov r3, sp
	adds r2, r3, r0
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, r8
	ldr r0, [r4]
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	strb r0, [r2, #4]
	b _08038304
	.align 2, 0
_080382D8: .4byte gUnknown_086AEA70
_080382DC: .4byte gCurrentPinballGame
_080382E0: .4byte gUnknown_0202D880
_080382E4: .4byte gUnknown_086BB420
_080382E8: .4byte 0x0000132C
_080382EC:
	mov r6, sp
	adds r0, r6, r2
	ldr r1, [r4]
	ldr r2, [r4, #4]
	str r1, [r0]
	str r2, [r0, #4]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _08038276
_08038304:
	mov r2, sl
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6c]
	str r0, [sp, #0x68]
	str r1, [sp, #0x6c]
	movs r5, #0
	ldr r7, _08038374 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r6, _08038378 @ =0x00000402
	adds r3, r0, r6
_08038318:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #3
	add r0, sp
	ldrb r1, [r0, #4]
	movs r4, #0
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bge _0803837C
	movs r0, #0xc
	cmp r0, r2
	blt _08038356
	adds r4, r2, #0
_08038332:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r2, #1
	lsls r0, r0, #3
	mov r1, sp
	adds r3, r1, r0
	lsls r0, r2, #3
	add r0, sp
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, r4
	bge _08038332
_08038356:
	lsls r0, r5, #0x10
	asrs r0, r0, #0xd
	mov r3, sp
	adds r2, r3, r0
	mov r4, sl
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r7]
	adds r0, r0, r6
	ldrh r0, [r0]
	strb r0, [r2, #4]
	b _08038388
	.align 2, 0
_08038374: .4byte gCurrentPinballGame
_08038378: .4byte 0x00000402
_0803837C:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _08038318
_08038388:
	movs r5, #0
	ldr r6, _080383D8 @ =gUnknown_02031590
	ldr r4, _080383DC @ =gUnknown_0202D880
_0803838E:
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	mov r1, sp
	adds r3, r1, r0
	ldrb r0, [r3, #5]
	adds r0, #0xa
	adds r0, r0, r6
	adds r1, r5, #0
	adds r1, #0xa
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r3]
	str r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xd
	ble _0803838E
	ldr r0, _080383DC @ =gUnknown_0202D880
	movs r1, #0x21
	ldr r2, _080383E0 @ =gMain+0x2F8 @gMain.spriteGroups
	bl LoadSpriteSets
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080383D8: .4byte gUnknown_02031590
_080383DC: .4byte gUnknown_0202D880
_080383E0: .4byte gMain+0x2F8 @gMain.spriteGroups

	thumb_func_start sub_383E4
sub_383E4: @ 0x080383E4
	push {r4, r5, r6, r7, lr}
	ldr r4, _08038438 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r1, #0
	movs r3, #0
	strh r3, [r0, #0x18]
	strb r1, [r0, #0x17]
	ldr r0, [r4]
	strb r1, [r0, #0x13]
	ldr r0, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r0, r2
	strb r1, [r0]
	ldr r5, [r4]
	adds r2, r5, #0
	adds r2, #0x6c
	ldr r6, _0803843C @ =0x00002A30
	adds r0, r6, #0
	ldrh r7, [r2]
	adds r0, r0, r7
	ldr r6, _08038440 @ =0x00000296
	adds r1, r5, r6
	strh r0, [r1]
	strh r3, [r2]
	ldr r7, _08038444 @ =0x00000283
	adds r0, r5, r7
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r4, #0
	cmp r0, #3
	bne _08038448
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x12
	b _08038450
	.align 2, 0
_08038438: .4byte gCurrentPinballGame
_0803843C: .4byte 0x00002A30
_08038440: .4byte 0x00000296
_08038444: .4byte 0x00000283
_08038448:
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0xf
_08038450:
	strb r0, [r1]
	ldr r0, [r6]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r0, r3
	movs r2, #0
	movs r3, #0
	strh r3, [r1]
	ldr r4, _08038634 @ =0x00000389
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	ldr r5, _08038638 @ =0x00000383
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r6]
	ldr r7, _0803863C @ =0x00000382
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r6]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r4, #3
	strb r4, [r0]
	ldr r0, [r6]
	adds r5, #0xf
	adds r1, r0, r5
	strh r3, [r1]
	ldr r7, _08038640 @ =0x0000132C
	adds r0, r0, r7
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, _08038644 @ =0x00000386
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r5, #2
	adds r1, r0, r5
	strh r3, [r1]
	ldr r7, _08038648 @ =0x0000038E
	adds r1, r0, r7
	strh r3, [r1]
	ldr r1, _0803864C @ =0x00000385
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	subs r5, #0xd
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r6]
	ldr r7, _08038650 @ =0x000006C4
	adds r0, r0, r7
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #0x5a
	adds r0, r0, r1
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, [r6]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	adds r5, #0x61
	adds r1, r0, r5
	strh r3, [r1]
	ldr r7, _08038654 @ =0x000003EA
	adds r1, r0, r7
	strh r3, [r1]
	ldr r1, _08038658 @ =0x000003DE
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r4, #4
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	subs r5, #6
	adds r1, r0, r5
	strh r3, [r1]
	subs r7, #6
	adds r1, r0, r7
	strh r3, [r1]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r4, #0x65
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	adds r5, #0x64
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r6]
	adds r7, #0x63
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, #8
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r4, #4
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	adds r5, #4
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r6]
	adds r7, #7
	adds r1, r0, r7
	strh r3, [r1]
	ldr r2, _0803865C @ =0x00000452
	adds r1, r0, r2
	strh r3, [r1]
	adds r4, #0xb
	adds r1, r0, r4
	strh r3, [r1]
	adds r5, #0xc
	adds r1, r0, r5
	strh r3, [r1]
	adds r7, #2
	adds r0, r0, r7
	strh r3, [r0]
	movs r1, #0
	adds r5, r6, #0
	movs r4, #0
_0803855C:
	ldr r0, [r5]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	ldr r1, _08038660 @ =0x00000441
	adds r0, r0, r1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r3, _08038664 @ =0x00000443
	adds r0, r0, r3
	adds r0, r0, r2
	strb r4, [r0]
	ldr r1, [r5]
	lsls r3, r2, #1
	movs r7, #0x8b
	lsls r7, r7, #3
	adds r0, r1, r7
	adds r0, r0, r3
	strh r4, [r0]
	lsls r0, r2, #2
	adds r1, r1, r0
	ldr r3, _08038668 @ =0x0000045C
	adds r0, r1, r3
	strh r4, [r0]
	adds r7, #6
	adds r0, r1, r7
	strh r4, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r4, [r0]
	adds r7, #8
	adds r1, r1, r7
	strh r4, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0803855C
	movs r1, #0
	ldr r7, _0803866C @ =gCurrentPinballGame
	ldr r5, _08038670 @ =0x0000046C
	movs r3, #0
	ldr r4, _08038674 @ =0x0000046E
_080385B4:
	ldr r2, [r7]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r2, r2, r1
	adds r1, r2, r5
	strh r3, [r1]
	adds r2, r2, r4
	strh r3, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _080385B4
	ldr r1, [r6]
	movs r0, #1
	strb r0, [r1, #0x1a]
	bl sub_38A20
	bl sub_395D8
	bl sub_39A40
	bl sub_3AE14
	movs r0, MUS_BONUS_FIELD_KYOGRE
	bl m4aSongNumStart
	ldr r2, _08038678 @ =0x040000D4
	ldr r0, [r6]
	ldr r1, _0803867C @ =0x000005F6
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _08038680 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08038684 @ =0x05000220
	str r0, [r2, #4]
	ldr r1, _08038688 @ =0x80000010
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0803868C @ =gUnknown_086AEAE0
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r2, #4]
	ldr r0, _08038690 @ =0x80000080
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _08038694 @ =gUnknown_081B36A4
	str r0, [r2]
	ldr r0, _08038698 @ =0x05000320
	str r0, [r2, #4]
	str r1, [r2, #8]
	ldr r0, [r2, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038634: .4byte 0x00000389
_08038638: .4byte 0x00000383
_0803863C: .4byte 0x00000382
_08038640: .4byte 0x0000132C
_08038644: .4byte 0x00000386
_08038648: .4byte 0x0000038E
_0803864C: .4byte 0x00000385
_08038650: .4byte 0x000006C4
_08038654: .4byte 0x000003EA
_08038658: .4byte 0x000003DE
_0803865C: .4byte 0x00000452
_08038660: .4byte 0x00000441
_08038664: .4byte 0x00000443
_08038668: .4byte 0x0000045C
_0803866C: .4byte gCurrentPinballGame
_08038670: .4byte 0x0000046C
_08038674: .4byte 0x0000046E
_08038678: .4byte 0x040000D4
_0803867C: .4byte 0x000005F6
_08038680: .4byte gUnknown_08137E14
_08038684: .4byte 0x05000220
_08038688: .4byte 0x80000010
_0803868C: .4byte gUnknown_086AEAE0
_08038690: .4byte 0x80000080
_08038694: .4byte gUnknown_081B36A4
_08038698: .4byte 0x05000320

	thumb_func_start sub_3869C
sub_3869C: @ 0x0803869C
	push {r4, r5, r6, lr}
	ldr r0, _080386B8 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bls _080386AE
	b _0803899C
_080386AE:
	lsls r0, r0, #2
	ldr r1, _080386BC @ =_080386C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080386B8: .4byte gCurrentPinballGame
_080386BC: .4byte _080386C0
_080386C0: @ jump table
	.4byte _080386DC @ case 0
	.4byte _0803899C @ case 1
	.4byte _080387D2 @ case 2
	.4byte _08038848 @ case 3
	.4byte _080388C8 @ case 4
	.4byte _08038924 @ case 5
	.4byte _08038984 @ case 6
_080386DC:
	ldr r6, _08038704 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r1, _08038708 @ =0x000005F7
	adds r0, r0, r1
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r5, [r6]
	ldrh r1, [r5, #0x18]
	ldr r0, _0803870C @ =0x000001F3
	cmp r1, r0
	bhi _08038714
	adds r1, r5, #0
	adds r1, #0xe6
	ldr r0, _08038710 @ =0x0000FFC0
	strh r0, [r1]
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	b _0803899C
	.align 2, 0
_08038704: .4byte gCurrentPinballGame
_08038708: .4byte 0x000005F7
_0803870C: .4byte 0x000001F3
_08038710: .4byte 0x0000FFC0
_08038714:
	ldr r0, _080387A4 @ =0x00000333
	cmp r1, r0
	bhi _080387C4
	ldrh r0, [r5, #0x18]
	ldr r4, _080387A8 @ =0xFFFFFE0C
	adds r0, r0, r4
	movs r1, #5
	bl __divsi3
	subs r0, #0x40
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	ldrh r0, [r5, #0x18]
	adds r0, r0, r4
	movs r1, #0x18
	bl __divsi3
	ldr r2, _080387AC @ =0x00000382
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	ble _0803874E
	movs r0, #5
	strb r0, [r1]
_0803874E:
	ldr r4, [r6]
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	ldr r1, _080387B0 @ =0x040000D4
	ldr r3, _080387B4 @ =gUnknown_086AEAE0
	adds r2, r4, r2
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080387B8 @ =0x80000030
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	adds r0, #0x80
	str r0, [r1]
	ldr r0, _080387BC @ =0x05000080
	str r0, [r1, #4]
	ldr r0, _080387C0 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r0, r4, #0
	adds r0, #0xe6
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0803879E
	b _0803899C
_0803879E:
	movs r0, #0
	strb r0, [r4, #0x1a]
	b _0803899C
	.align 2, 0
_080387A4: .4byte 0x00000333
_080387A8: .4byte 0xFFFFFE0C
_080387AC: .4byte 0x00000382
_080387B0: .4byte 0x040000D4
_080387B4: .4byte gUnknown_086AEAE0
_080387B8: .4byte 0x80000030
_080387BC: .4byte 0x05000080
_080387C0: .4byte 0x80000040
_080387C4:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r3, [r0]
	strb r2, [r5, #0x13]
	ldr r0, [r6]
	strh r3, [r0, #0x18]
	b _0803899C
_080387D2:
	ldr r2, _080387E4 @ =gCurrentPinballGame
	ldr r3, [r2]
	ldrh r0, [r3, #0x18]
	cmp r0, #0x77
	bhi _080387E8
	adds r0, #1
	strh r0, [r3, #0x18]
	b _0803899C
	.align 2, 0
_080387E4: .4byte gCurrentPinballGame
_080387E8:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0x13]
	ldr r2, [r2]
	strh r1, [r2, #0x18]
	ldr r3, _08038830 @ =gMain
	movs r4, #0xe9
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r4, #1
	movs r1, #1
	strh r1, [r0]
	movs r5, #0xd2
	lsls r5, r5, #3
	adds r0, r3, r5
	strh r1, [r0]
	ldr r1, _08038834 @ =0x040000D4
	ldr r0, _08038838 @ =gUnknown_0813C874
	str r0, [r1]
	ldr r0, _0803883C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08038840 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x88
	strh r0, [r1]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	ldr r1, _08038844 @ =0x000005FA
	adds r2, r2, r1
	strb r4, [r2]
	b _0803899C
	.align 2, 0
_08038830: .4byte gMain
_08038834: .4byte 0x040000D4
_08038838: .4byte gUnknown_0813C874
_0803883C: .4byte 0x06015800
_08038840: .4byte 0x80001000
_08038844: .4byte 0x000005FA
_08038848:
	bl sub_351A8
	ldr r4, _08038890 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0803885A
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0803885A:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _08038870
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r4]
	ldr r0, _08038894 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _08038898 @ =gUnknown_02FAF080
	str r0, [r1, #0x3c]
_08038870:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _0803889C
	cmp r0, #0x14
	bne _08038886
	bl m4aMPlayAllStop
	movs r0, MUS_SUCCESS3
	bl m4aSongNumStart
_08038886:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080388B0
	.align 2, 0
_08038890: .4byte gCurrentPinballGame
_08038894: .4byte 0x00061A80
_08038898: .4byte gUnknown_02FAF080
_0803889C:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r4]
	ldr r2, _080388BC @ =0x00000283
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080388B0:
	ldr r0, _080388C0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r4, _080388C4 @ =0x000005FA
	adds r0, r0, r4
	movs r1, #1
	b _0803899A
	.align 2, 0
_080388BC: .4byte 0x00000283
_080388C0: .4byte gCurrentPinballGame
_080388C4: .4byte 0x000005FA
_080388C8:
	ldr r2, _0803890C @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r0, #5
	strb r0, [r1, #0x13]
	ldr r2, [r2]
	movs r0, #0x8c
	strh r0, [r2, #0x18]
	ldr r3, _08038910 @ =gMain
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #1
	strh r1, [r0]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r3, r4
	strh r1, [r0]
	ldr r1, _08038914 @ =0x040000D4
	ldr r0, _08038918 @ =gUnknown_0813C874
	str r0, [r1]
	ldr r0, _0803891C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08038920 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r0, #0x88
	strh r0, [r2]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	b _0803899C
	.align 2, 0
_0803890C: .4byte gCurrentPinballGame
_08038910: .4byte gMain
_08038914: .4byte 0x040000D4
_08038918: .4byte gUnknown_0813C874
_0803891C: .4byte 0x06015800
_08038920: .4byte 0x80001000
_08038924:
	bl sub_351A8
	ldr r2, _0803895C @ =gCurrentPinballGame
	ldr r1, [r2]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _08038936
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_08038936:
	ldr r1, [r2]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0803894C
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r2]
	ldr r0, _08038960 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _08038964 @ =gUnknown_02FAF080
	str r0, [r1, #0x3c]
_0803894C:
	ldr r1, [r2]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _08038968
	adds r0, #1
	strh r0, [r1, #0x18]
	b _0803899C
	.align 2, 0
_0803895C: .4byte gCurrentPinballGame
_08038960: .4byte 0x00061A80
_08038964: .4byte gUnknown_02FAF080
_08038968:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r2]
	ldr r0, _08038980 @ =0x00000283
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803899C
	.align 2, 0
_08038980: .4byte 0x00000283
_08038984:
	bl sub_351A8
	ldr r2, _08038A0C @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08038A10 @ =0x00000386
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _08038A14 @ =0x000005FA
	adds r0, r0, r2
_0803899A:
	strb r1, [r0]
_0803899C:
	bl sub_39A40
	bl sub_38A20
	bl sub_395D8
	bl sub_3AE14
	ldr r0, _08038A0C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r4, #0xa5
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080389E4
	ldr r5, _08038A18 @ =0x00000296
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080389E4
	ldr r4, _08038A1C @ =gMain
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _080389E4
	bl m4aMPlayAllStop
	movs r0, MUS_END_OF_BALL3
	bl m4aSongNumStart
	ldrb r1, [r4, #0xf]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xf]
_080389E4:
	ldr r0, _08038A0C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08038A10 @ =0x00000386
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08038A02
	ldr r4, _08038A14 @ =0x000005FA
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	bl sub_350F0
_08038A02:
	bl sub_472E4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08038A0C: .4byte gCurrentPinballGame
_08038A10: .4byte 0x00000386
_08038A14: .4byte 0x000005FA
_08038A18: .4byte 0x00000296
_08038A1C: .4byte gMain
