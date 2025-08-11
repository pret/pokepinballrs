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
