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

	thumb_func_start sub_38A20
sub_38A20: @ 0x08038A20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08038AE8 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08038AEC @ =0x00000452
	adds r5, r1, r2
	ldrh r4, [r5]
	mov r8, r0
	cmp r4, #0
	beq _08038AC6
	subs r0, r4, #1
	strh r0, [r5]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	beq _08038AB0
	ldr r0, _08038AF0 @ =0x00000389
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #4
	bne _08038AB0
	ldr r0, _08038AF4 @ =gMPlayInfo_SE1
	ldr r1, _08038AF8 @ =gUnknown_086A1E74
	bl MPlayStart
	movs r0, #7
	bl sub_11B0
	mov r2, r8
	ldr r1, [r2]
	ldr r0, _08038AFC @ =0x0007A120
	str r0, [r1, #0x3c]
	ldr r2, _08038B00 @ =0x00000385
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r6, r8
	ldr r3, [r6]
	adds r2, r3, r2
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08038AB0
	ldr r2, _08038B04 @ =0x00000387
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08038AB0
	adds r1, r3, r4
	movs r0, #7
	strb r0, [r1]
_08038AB0:
	ldr r1, _08038AE8 @ =gCurrentPinballGame
	ldr r5, [r1]
	ldr r3, _08038AEC @ =0x00000452
	adds r0, r5, r3
	ldrh r4, [r0]
	mov r8, r1
	cmp r4, #0
	bne _08038AC6
	ldr r6, _08038AF0 @ =0x00000389
	adds r0, r5, r6
	strb r4, [r0]
_08038AC6:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xd
	bls _08038ADE
	bl _08039562
_08038ADE:
	lsls r0, r0, #2
	ldr r1, _08038B08 @ =_08038B0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038AE8: .4byte gCurrentPinballGame
_08038AEC: .4byte 0x00000452
_08038AF0: .4byte 0x00000389
_08038AF4: .4byte gMPlayInfo_SE1
_08038AF8: .4byte gUnknown_086A1E74
_08038AFC: .4byte 0x0007A120
_08038B00: .4byte 0x00000385
_08038B04: .4byte 0x00000387
_08038B08: .4byte _08038B0C
_08038B0C: @ jump table
	.4byte _08038B44 @ case 0
	.4byte _08038B88 @ case 1
	.4byte _08038CE0 @ case 2
	.4byte _08038D80 @ case 3
	.4byte _08038E0C @ case 4
	.4byte _08038EF2 @ case 5
	.4byte _08038FE4 @ case 6
	.4byte _080390D8 @ case 7
	.4byte _08039562 @ case 8
	.4byte _080391F0 @ case 9
	.4byte _0803927C @ case 10
	.4byte _08039350 @ case 11
	.4byte _08039480 @ case 12
	.4byte _08039562 @ case 13
_08038B44:
	ldr r2, _08038B80 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _08038B84 @ =0x000003E2
	adds r2, r0, r4
	movs r1, #0xc
	strh r1, [r2]
	movs r6, #0xf9
	lsls r6, r6, #2
	adds r1, r0, r6
	strh r3, [r1]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	adds r4, #8
	adds r1, r0, r4
	strh r3, [r1]
	adds r6, #0x6c
	adds r0, r0, r6
	strh r3, [r0]
	bl _08039562
	.align 2, 0
_08038B80: .4byte gCurrentPinballGame
_08038B84: .4byte 0x000003E2
_08038B88:
	ldr r5, _08038C00 @ =gUnknown_086AEDA4
	ldr r7, _08038C04 @ =gCurrentPinballGame
	ldr r6, [r7]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r4, r6, r0
	ldrh r0, [r4]
	movs r1, #0x8c
	lsls r1, r1, #1
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xe
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r5
	ldr r5, _08038C08 @ =0x040000D4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r2, _08038C0C @ =gUnknown_081B0DE4
	adds r0, r0, r2
	str r0, [r5]
	ldr r3, _08038C10 @ =0x050003E0
	mov ip, r3
	str r3, [r5, #4]
	ldr r0, _08038C14 @ =0x80000010
	mov sl, r0
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	adds r3, r6, #0
	ldrh r0, [r4]
	adds r0, #1
	movs r1, #0
	mov sb, r1
	strh r0, [r4]
	ldr r2, _08038C18 @ =gUnknown_086AEAF8
	ldr r4, _08038C1C @ =0x000003E2
	mov r8, r4
	adds r4, r3, r4
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r3, r3, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08038C20
	adds r0, r1, #1
	strh r0, [r3]
	b _08038CA4
	.align 2, 0
_08038C00: .4byte gUnknown_086AEDA4
_08038C04: .4byte gCurrentPinballGame
_08038C08: .4byte 0x040000D4
_08038C0C: .4byte gUnknown_081B0DE4
_08038C10: .4byte 0x050003E0
_08038C14: .4byte 0x80000010
_08038C18: .4byte gUnknown_086AEAF8
_08038C1C: .4byte 0x000003E2
_08038C20:
	mov r2, sb
	strh r2, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x22
	bne _08038C6E
	strh r2, [r4]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r7]
	ldr r4, _08038CC0 @ =0x000003DD
	adds r0, r0, r4
	movs r1, #6
	strb r1, [r0]
	ldr r0, [r7]
	ldr r6, _08038CC4 @ =0x000003E1
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r7]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0x3c
	strh r1, [r0]
	ldr r0, _08038CC8 @ =gUnknown_081B0DE4
	adds r0, #0xa0
	str r0, [r5]
	mov r2, ip
	str r2, [r5, #4]
	mov r3, sl
	str r3, [r5, #8]
	ldr r0, [r5, #8]
_08038C6E:
	ldr r1, [r7]
	mov r4, r8
	adds r0, r1, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0x20
	bne _08038C86
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_08038C86:
	ldr r0, [r7]
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x21
	bne _08038CA4
	ldr r0, _08038CCC @ =gMPlayInfo_SE1
	ldr r1, _08038CD0 @ =gUnknown_086A1F10
	bl MPlayStart
	ldr r0, [r7]
	ldr r2, _08038CD4 @ =0x00000387
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
_08038CA4:
	ldr r0, _08038CD8 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r3, _08038CDC @ =0x00000392
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #2
	bhi _08038CB6
	bl _08039562
_08038CB6:
	subs r0, #1
	strh r0, [r1]
	bl _08039562
	.align 2, 0
_08038CC0: .4byte 0x000003DD
_08038CC4: .4byte 0x000003E1
_08038CC8: .4byte gUnknown_081B0DE4
_08038CCC: .4byte gMPlayInfo_SE1
_08038CD0: .4byte gUnknown_086A1F10
_08038CD4: .4byte 0x00000387
_08038CD8: .4byte gCurrentPinballGame
_08038CDC: .4byte 0x00000392
_08038CE0:
	ldr r2, _08038D60 @ =gUnknown_086AEAF8
	ldr r5, _08038D64 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _08038D68 @ =0x000003E2
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08038D08
	b _080394A6
_08038D08:
	movs r2, #0
	strh r2, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne _08038D3A
	strh r2, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r5]
	ldr r4, _08038D6C @ =0x000003DD
	adds r0, r0, r4
	movs r1, #6
	strb r1, [r0]
	ldr r0, [r5]
	ldr r1, _08038D70 @ =0x000003E1
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
_08038D3A:
	ldr r1, [r5]
	adds r0, r1, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	beq _08038D4A
	bl _08039562
_08038D4A:
	ldr r3, _08038D74 @ =0x00000387
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08038D78 @ =gMPlayInfo_SE1
	ldr r1, _08038D7C @ =gUnknown_086A1F10
	bl MPlayStart
	bl _08039562
	.align 2, 0
_08038D60: .4byte gUnknown_086AEAF8
_08038D64: .4byte gCurrentPinballGame
_08038D68: .4byte 0x000003E2
_08038D6C: .4byte 0x000003DD
_08038D70: .4byte 0x000003E1
_08038D74: .4byte 0x00000387
_08038D78: .4byte gMPlayInfo_SE1
_08038D7C: .4byte gUnknown_086A1F10
_08038D80:
	ldr r2, _08038DF0 @ =gUnknown_086AEAF8
	ldr r5, _08038DF4 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _08038DF8 @ =0x000003E2
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08038DA8
	b _080394A6
_08038DA8:
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne _08038DD0
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xb
	strb r0, [r1]
	ldr r0, [r5]
	ldr r4, _08038DFC @ =0x000003E1
	adds r0, r0, r4
	strb r2, [r0]
_08038DD0:
	ldr r1, [r5]
	adds r0, r1, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #5
	beq _08038DDE
	b _08039562
_08038DDE:
	ldr r3, _08038E00 @ =0x00000387
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _08038E04 @ =gMPlayInfo_SE1
	ldr r1, _08038E08 @ =gUnknown_086A1FC4
	bl MPlayStart
	b _08039562
	.align 2, 0
_08038DF0: .4byte gUnknown_086AEAF8
_08038DF4: .4byte gCurrentPinballGame
_08038DF8: .4byte 0x000003E2
_08038DFC: .4byte 0x000003E1
_08038E00: .4byte 0x00000387
_08038E04: .4byte gMPlayInfo_SE1
_08038E08: .4byte gUnknown_086A1FC4
_08038E0C:
	ldr r2, _08038E68 @ =gUnknown_086AEAF8
	ldr r4, _08038E6C @ =gCurrentPinballGame
	mov r8, r4
	ldr r3, [r4]
	ldr r6, _08038E70 @ =0x000003E2
	adds r4, r3, r6
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08038E36
	b _080394A6
_08038E36:
	movs r6, #0
	mov sb, r6
	movs r7, #0
	strh r7, [r1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #4
	beq _08038E4E
	b _08039562
_08038E4E:
	ldr r0, _08038E74 @ =0x000003E1
	mov ip, r0
	adds r1, r3, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	bgt _08038E78
	strh r7, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08039562
	.align 2, 0
_08038E68: .4byte gUnknown_086AEAF8
_08038E6C: .4byte gCurrentPinballGame
_08038E70: .4byte 0x000003E2
_08038E74: .4byte 0x000003E1
_08038E78:
	ldr r1, _08038EB8 @ =0x000003DD
	mov sl, r1
	adds r5, r3, r1
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #3
	bne _08038ECE
	ldr r2, _08038EBC @ =0x00000385
	adds r0, r3, r2
	subs r2, #1
	adds r1, r3, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	blt _08038EC0
	strh r7, [r4]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r3, r4
	strb r6, [r0]
	mov r6, r8
	ldr r0, [r6]
	add r0, ip
	mov r1, sb
	strb r1, [r0]
	ldr r0, [r6]
	add r0, sl
	movs r1, #6
	strb r1, [r0]
	b _08039562
	.align 2, 0
_08038EB8: .4byte 0x000003DD
_08038EBC: .4byte 0x00000385
_08038EC0:
	strh r6, [r4]
	ldrb r1, [r5]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r3, r2
	strb r1, [r0]
	b _08039562
_08038ECE:
	movs r0, #0x22
	strh r0, [r4]
	ldrb r1, [r5]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r3, r4
	strb r1, [r0]
	mov r6, r8
	ldr r0, [r6]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r2, sb
	strb r2, [r0]
	ldr r0, [r6]
	add r0, ip
	strb r2, [r0]
	b _08039562
_08038EF2:
	ldr r2, _08038F44 @ =gUnknown_086AEAF8
	mov r3, r8
	ldr r4, [r3]
	ldr r6, _08038F48 @ =0x000003E2
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08038F1A
	b _080394A6
_08038F1A:
	movs r2, #0
	strh r2, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x43
	bne _08038F74
	ldr r6, _08038F4C @ =0x000003E1
	adds r1, r4, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08038F50
	movs r0, #0x2d
	strh r0, [r3]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08038F74
	.align 2, 0
_08038F44: .4byte gUnknown_086AEAF8
_08038F48: .4byte 0x000003E2
_08038F4C: .4byte 0x000003E1
_08038F50:
	strh r2, [r3]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08038FC8 @ =0x000003E1
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _08038FCC @ =0x000003DD
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
_08038F74:
	ldr r5, _08038FD0 @ =gCurrentPinballGame
	ldr r3, [r5]
	ldr r4, _08038FD4 @ =0x000003E2
	adds r0, r3, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0x34
	bne _08038FA8
	ldr r0, _08038FC8 @ =0x000003E1
	adds r2, r3, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #1
	movs r6, #0x8b
	lsls r6, r6, #3
	adds r1, r3, r6
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldr r2, _08038FD8 @ =0x00000441
	adds r0, r3, r2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
_08038FA8:
	ldr r0, [r5]
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x32
	beq _08038FBE
	cmp r0, #0x38
	beq _08038FBE
	cmp r0, #0x3e
	beq _08038FBE
	b _08039562
_08038FBE:
	ldr r0, _08038FDC @ =gMPlayInfo_SE1
	ldr r1, _08038FE0 @ =gUnknown_086A1FE4
	bl MPlayStart
	b _08039562
	.align 2, 0
_08038FC8: .4byte 0x000003E1
_08038FCC: .4byte 0x000003DD
_08038FD0: .4byte gCurrentPinballGame
_08038FD4: .4byte 0x000003E2
_08038FD8: .4byte 0x00000441
_08038FDC: .4byte gMPlayInfo_SE1
_08038FE0: .4byte gUnknown_086A1FE4
_08038FE4:
	ldr r2, _08039010 @ =gUnknown_086AEAF8
	mov r4, r8
	ldr r3, [r4]
	ldr r6, _08039014 @ =0x000003E2
	adds r4, r3, r6
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08039018
	adds r0, r2, #1
	strh r0, [r1]
	b _08039098
	.align 2, 0
_08039010: .4byte gUnknown_086AEAF8
_08039014: .4byte 0x000003E2
_08039018:
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne _08039040
	ldr r6, _080390B4 @ =0x000003E1
	adds r1, r3, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08039040
	movs r0, #0x22
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08039040:
	ldr r4, _080390B8 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r5, _080390BC @ =0x000003E2
	adds r3, r1, r5
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0x2d
	bne _08039066
	movs r2, #0
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r0, #5
	strb r0, [r1]
	ldr r0, [r4]
	ldr r6, _080390B4 @ =0x000003E1
	adds r0, r0, r6
	strb r2, [r0]
_08039066:
	ldr r2, [r4]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	cmp r3, #0
	bne _08039098
	adds r0, r2, r5
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x2a
	bne _08039098
	ldr r0, _080390C0 @ =gMain
	ldr r6, _080390C4 @ =0x00001438
	adds r0, r0, r6
	movs r1, #1
	strh r1, [r0]
	ldr r1, _080390C8 @ =0x00000456
	adds r0, r2, r1
	strh r3, [r0]
	ldr r0, _080390CC @ =gMPlayInfo_SE1
	ldr r1, _080390D0 @ =gUnknown_086A2038
	bl MPlayStart
_08039098:
	ldr r0, _080390B8 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _080390D4 @ =0x00000452
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #6
	bhi _080390A8
	b _08039562
_080390A8:
	movs r3, #0x88
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	b _08039562
	.align 2, 0
_080390B4: .4byte 0x000003E1
_080390B8: .4byte gCurrentPinballGame
_080390BC: .4byte 0x000003E2
_080390C0: .4byte gMain
_080390C4: .4byte 0x00001438
_080390C8: .4byte 0x00000456
_080390CC: .4byte gMPlayInfo_SE1
_080390D0: .4byte gUnknown_086A2038
_080390D4: .4byte 0x00000452
_080390D8:
	mov r4, r8
	ldr r0, [r4]
	movs r6, #0xa5
	lsls r6, r6, #2
	adds r0, r0, r6
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r4, [r4]
	ldr r1, _08039158 @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08039174
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xa
	strb r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _0803915C @ =0x000003E2
	adds r0, r0, r4
	movs r4, #0
	strh r5, [r0]
	ldr r3, _08039160 @ =gMain
	ldr r6, _08039164 @ =0x00000A28
	adds r0, r3, r6
	movs r1, #1
	strh r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r3, r2
	strh r1, [r0]
	mov r6, r8
	ldr r1, [r6]
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r0, #0xc5
	strh r0, [r2]
	ldr r2, _08039168 @ =0x0000038E
	adds r0, r1, r2
	strh r5, [r0]
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r1, r1, r6
	strb r4, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803916C @ =0x000005A6
	adds r1, r0, r2
	strh r5, [r1]
	ldr r4, _08039170 @ =0x000005A4
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	adds r2, r3, #0
	b _080391A4
	.align 2, 0
_08039158: .4byte 0x00000283
_0803915C: .4byte 0x000003E2
_08039160: .4byte gMain
_08039164: .4byte 0x00000A28
_08039168: .4byte 0x0000038E
_0803916C: .4byte 0x000005A6
_08039170: .4byte 0x000005A4
_08039174:
	movs r6, #0xf7
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #9
	strb r0, [r1]
	mov r0, r8
	ldr r1, [r0]
	ldr r3, _080391D4 @ =0x000003E2
	adds r2, r1, r3
	movs r0, #0x4f
	strh r0, [r2]
	ldr r2, _080391D8 @ =gMain
	movs r0, #0x80
	strb r0, [r2, #0xf]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r1, r1, r4
	movs r0, #2
	strb r0, [r1]
	mov r6, r8
	ldr r0, [r6]
	ldr r1, _080391DC @ =0x00000392
	adds r0, r0, r1
	strh r5, [r0]
_080391A4:
	ldr r3, _080391E0 @ =0x00000E78
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080391C4
	mov r4, r8
	ldr r0, [r4]
	ldr r6, _080391E4 @ =0x00000445
	adds r0, r0, r6
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080391E8 @ =0x0000044E
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
_080391C4:
	ldr r0, _080391EC @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
	b _08039562
	.align 2, 0
_080391D4: .4byte 0x000003E2
_080391D8: .4byte gMain
_080391DC: .4byte 0x00000392
_080391E0: .4byte 0x00000E78
_080391E4: .4byte 0x00000445
_080391E8: .4byte 0x0000044E
_080391EC: .4byte gCurrentPinballGame
_080391F0:
	ldr r2, _08039264 @ =gUnknown_086AEAF8
	ldr r5, _08039268 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _0803926C @ =0x000003E2
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _08039218
	b _080394A6
_08039218:
	movs r2, #0
	strh r2, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x6c
	bne _08039242
	movs r0, #0x6b
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xd
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, #2
	strb r0, [r1, #0x13]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
_08039242:
	ldr r1, [r5]
	adds r0, r1, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x61
	beq _08039250
	b _08039562
_08039250:
	ldr r6, _08039270 @ =0x00000387
	adds r1, r1, r6
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08039274 @ =gMPlayInfo_SE1
	ldr r1, _08039278 @ =gUnknown_086A20F8
	bl MPlayStart
	b _08039562
	.align 2, 0
_08039264: .4byte gUnknown_086AEAF8
_08039268: .4byte gCurrentPinballGame
_0803926C: .4byte 0x000003E2
_08039270: .4byte 0x00000387
_08039274: .4byte gMPlayInfo_SE1
_08039278: .4byte gUnknown_086A20F8
_0803927C:
	ldr r2, _080392A8 @ =gUnknown_086AEAF8
	mov r0, r8
	ldr r3, [r0]
	ldr r1, _080392AC @ =0x000003E2
	adds r4, r3, r1
	movs r6, #0
	ldrsh r1, [r4, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r3, r3, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r0, r1
	bls _080392B0
	adds r0, r1, #1
	strh r0, [r3]
	b _080392C4
	.align 2, 0
_080392A8: .4byte gUnknown_086AEAF8
_080392AC: .4byte 0x000003E2
_080392B0:
	movs r1, #0
	strh r1, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _080392C4
	strh r1, [r4]
_080392C4:
	mov r2, r8
	ldr r6, [r2]
	ldr r3, _0803933C @ =0x0000038E
	adds r4, r6, r3
	ldrh r5, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _08039340 @ =0xFFFFFE0C
	cmp r0, r1
	ble _08039304
	subs r0, r1, r0
	movs r1, #0x1e
	bl __divsi3
	adds r0, r5, r0
	strh r0, [r4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0xa
	bl __divsi3
	adds r2, r6, #0
	adds r2, #0xe6
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08039304
	ldr r0, _08039344 @ =0x0000FFCE
	strh r0, [r2]
_08039304:
	ldr r3, _08039348 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _08039320
	ldr r4, _0803934C @ =0x000003E2
	adds r1, r1, r4
	movs r0, #0x72
	strh r0, [r1]
_08039320:
	ldr r1, [r3]
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x16
	beq _08039330
	b _08039562
_08039330:
	ldr r6, _0803934C @ =0x000003E2
	adds r1, r1, r6
	movs r0, #0x73
	strh r0, [r1]
	b _08039562
	.align 2, 0
_0803933C: .4byte 0x0000038E
_08039340: .4byte 0xFFFFFE0C
_08039344: .4byte 0x0000FFCE
_08039348: .4byte gCurrentPinballGame
_0803934C: .4byte 0x000003E2
_08039350:
	ldr r5, _08039428 @ =gCurrentPinballGame
	ldr r2, [r5]
	movs r6, #0xf9
	lsls r6, r6, #2
	adds r1, r2, r6
	ldrh r3, [r1]
	ldr r0, _0803942C @ =0x0000012B
	cmp r3, r0
	bhi _08039440
	adds r0, r3, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xda
	bne _080393AE
	ldr r0, _08039430 @ =0x00000456
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bl Random
	ldr r4, [r5]
	movs r1, #0x64
	bl __umodsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r4, r4, r3
	strh r0, [r4]
	bl Random
	ldr r4, [r5]
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #2
	adds r0, #0xc8
	ldr r1, _08039434 @ =0x000003EA
	adds r4, r4, r1
	strh r0, [r4]
_080393AE:
	ldr r0, [r5]
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #0x82
	lsls r0, r0, #1
	cmp r1, r0
	beq _080393BE
	b _08039562
_080393BE:
	movs r1, #0
	mov r8, r5
	mov ip, r8
	ldr r7, _08039438 @ =0x00000441
	movs r6, #0x8b
	lsls r6, r6, #3
	movs r5, #0
_080393CC:
	mov r3, ip
	ldr r2, [r3]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	adds r0, r2, r7
	adds r3, r0, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #3
	bne _080393FE
	lsls r1, r4, #1
	adds r0, r2, r6
	adds r0, r0, r1
	strh r5, [r0]
	movs r0, #4
	strb r0, [r3]
	mov r0, r8
	ldr r2, [r0]
	ldr r1, _0803943C @ =0x000005AC
	adds r2, r2, r1
	ldr r0, [r2]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r2]
_080393FE:
	mov r2, ip
	ldr r1, [r2]
	adds r0, r1, r7
	adds r2, r0, r4
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bne _0803941A
	lsls r0, r4, #1
	adds r1, r1, r6
	adds r1, r1, r0
	strh r5, [r1]
	movs r0, #5
	strb r0, [r2]
_0803941A:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080393CC
	b _08039562
	.align 2, 0
_08039428: .4byte gCurrentPinballGame
_0803942C: .4byte 0x0000012B
_08039430: .4byte 0x00000456
_08039434: .4byte 0x000003EA
_08039438: .4byte 0x00000441
_0803943C: .4byte 0x000005AC
_08039440:
	movs r0, #0
	strh r0, [r1]
	ldr r3, _08039470 @ =0x000003E2
	adds r1, r2, r3
	movs r0, #0x43
	strh r0, [r1]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r5]
	ldr r6, _08039474 @ =0x00000387
	adds r0, r0, r6
	movs r1, #2
	strb r1, [r0]
	ldr r0, _08039478 @ =gMPlayInfo_SE1
	ldr r1, _0803947C @ =gUnknown_086A1F10
	bl MPlayStart
	movs r0, #8
	bl sub_11B0
	b _08039562
	.align 2, 0
_08039470: .4byte 0x000003E2
_08039474: .4byte 0x00000387
_08039478: .4byte gMPlayInfo_SE1
_0803947C: .4byte gUnknown_086A1F10
_08039480:
	ldr r2, _080394AC @ =gUnknown_086AEAF8
	mov r7, r8
	ldr r4, [r7]
	ldr r6, _080394B0 @ =0x000003E2
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _080394B4
_080394A6:
	adds r0, r2, #1
	strh r0, [r1]
	b _08039562
	.align 2, 0
_080394AC: .4byte gUnknown_086AEAF8
_080394B0: .4byte 0x000003E2
_080394B4:
	movs r5, #0
	strh r5, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x4f
	bne _0803951C
	ldr r0, _080394F0 @ =0x000003E1
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _080394F4
	movs r0, #0x4e
	strh r0, [r3]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, [r7]
	ldr r3, _080394F0 @ =0x000003E1
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803951C
	.align 2, 0
_080394F0: .4byte 0x000003E1
_080394F4:
	movs r0, #0
	strb r0, [r1]
	mov r4, r8
	ldr r1, [r4]
	adds r2, r1, r6
	movs r0, #8
	strh r0, [r2]
	movs r6, #0xf7
	lsls r6, r6, #2
	adds r1, r1, r6
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _080395B0 @ =0x000003EA
	adds r0, r0, r3
	strh r5, [r0]
_0803951C:
	ldr r3, _080395B4 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r2, _080395B8 @ =0x000003E2
	adds r0, r1, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x46
	bne _08039534
	ldr r6, _080395BC @ =0x00000387
	adds r1, r1, r6
	movs r0, #3
	strb r0, [r1]
_08039534:
	ldr r1, [r3]
	adds r0, r1, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x49
	bne _08039548
	ldr r6, _080395BC @ =0x00000387
	adds r1, r1, r6
	movs r0, #0
	strb r0, [r1]
_08039548:
	ldr r0, [r3]
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x48
	bne _08039562
	ldr r0, _080395C0 @ =gMPlayInfo_SE1
	ldr r1, _080395C4 @ =gUnknown_086A1FC4
	bl MPlayStart
	movs r0, #8
	bl sub_11B0
_08039562:
	ldr r5, _080395B4 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0
	beq _080395A2
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803958C
	ldr r0, _080395C8 @ =gSpeciesInfo
	ldr r2, _080395CC @ =0x00001278
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	bl PlayCry_Normal
_0803958C:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080395A2
	ldr r0, _080395D0 @ =gMPlayInfo_BGM
	ldr r1, _080395D4 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_080395A2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080395B0: .4byte 0x000003EA
_080395B4: .4byte gCurrentPinballGame
_080395B8: .4byte 0x000003E2
_080395BC: .4byte 0x00000387
_080395C0: .4byte gMPlayInfo_SE1
_080395C4: .4byte gUnknown_086A1FC4
_080395C8: .4byte gSpeciesInfo
_080395CC: .4byte 0x00001278
_080395D0: .4byte gMPlayInfo_BGM
_080395D4: .4byte 0x0000FFFF

	thumb_func_start sub_395D8
sub_395D8: @ 0x080395D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r7, _08039648 @ =gMain+0x1210 @gMain.spriteGroups[21]
	ldrh r0, [r7]
	cmp r0, #0
	bne _080395EE
	b _080398D0
_080395EE:
	ldr r1, _0803964C @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08039650 @ =0x000003DF
	adds r3, r0, r2
	movs r5, #0
	ldrsb r5, [r3, r5]
	ldr r4, _08039654 @ =gUnknown_086AEAF8
	adds r2, #3
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r4, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3]
	ldr r1, _0803964C @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r8, r0
	cmp r5, #0xe
	bgt _08039668
	ldr r2, _08039658 @ =0x040000D4
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	lsls r0, r0, #7
	ldr r1, _0803965C @ =gUnknown_0849664C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08039660 @ =0x06010FA0
	str r0, [r2, #4]
	ldr r0, _08039664 @ =0x800002C0
	b _08039684
	.align 2, 0
_08039648: .4byte gMain+0x1210 @gMain.spriteGroups[21]
_0803964C: .4byte gCurrentPinballGame
_08039650: .4byte 0x000003DF
_08039654: .4byte gUnknown_086AEAF8
_08039658: .4byte 0x040000D4
_0803965C: .4byte gUnknown_0849664C
_08039660: .4byte 0x06010FA0
_08039664: .4byte 0x800002C0
_08039668:
	ldr r2, _08039720 @ =0x040000D4
	adds r1, r5, #0
	subs r1, #0xf
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _08039724 @ =gUnknown_0849B8CC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08039728 @ =0x06010FA0
	str r0, [r2, #4]
	ldr r0, _0803972C @ =0x80000260
_08039684:
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r3, _08039730 @ =gCurrentPinballGame
	ldr r4, [r3]
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r5, r4, r6
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r2, _08039734 @ =0x000003EA
	adds r6, r4, r2
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x42
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x78
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x32
	ldr r2, _08039738 @ =0x0000028A
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _0803973C @ =0x00000387
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08039740
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xc0
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x86
	b _08039796
	.align 2, 0
_08039720: .4byte 0x040000D4
_08039724: .4byte gUnknown_0849B8CC
_08039728: .4byte 0x06010FA0
_0803972C: .4byte 0x80000260
_08039730: .4byte gCurrentPinballGame
_08039734: .4byte 0x000003EA
_08039738: .4byte 0x0000028A
_0803973C: .4byte 0x00000387
_08039740:
	cmp r0, #3
	bne _0803976E
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xc0
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x96
	b _08039796
_0803976E:
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xb4
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x74
_08039796:
	ldr r6, _080397FC @ =0x000003F2
	adds r1, r4, r6
	strh r0, [r1]
	ldr r1, _08039800 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08039804 @ =0x00000389
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	ble _08039810
	movs r2, #0
	ldr r4, _08039808 @ =gOamBuffer
	ldr r3, _0803980C @ =0xFFFFFE00
	mov r8, r3
	movs r6, #0xb0
_080397B8:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrh r1, [r2, #2]
	mov r0, r8
	ands r0, r1
	movs r1, #0xf0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0xb4
	strb r1, [r0]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r2, [r1, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #9
	ble _080397B8
	b _080398D0
	.align 2, 0
_080397FC: .4byte 0x000003F2
_08039800: .4byte gCurrentPinballGame
_08039804: .4byte 0x00000389
_08039808: .4byte gOamBuffer
_0803980C: .4byte 0xFFFFFE00
_08039810:
	cmp r0, #1
	bne _0803981C
	movs r3, #0xe
	mov r4, r8
	lsls r0, r4, #0x10
	b _0803983C
_0803981C:
	cmp r0, #3
	bne _08039828
	movs r3, #0xb
	mov r6, r8
	lsls r0, r6, #0x10
	b _0803983C
_08039828:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	movs r3, #4
	cmp r1, #0x14
	beq _0803983C
	movs r3, #0xf
	cmp r1, #0x15
	bne _0803983C
	movs r3, #3
_0803983C:
	movs r2, #0
	lsls r3, r3, #4
	mov r8, r3
	ldr r3, _080399BC @ =gUnknown_086B92FC
	mov sl, r3
	ldr r6, _080399C0 @ =gOamBuffer
	asrs r1, r0, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r4, _080399C4 @ =0xFFFFFE00
	mov sb, r4
_08039856:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r0, [r2, #2]
	lsls r1, r0, #0x17
	lsrs r1, r1, #0x17
	str r1, [sp]
	movs r4, #2
	ldrsh r1, [r7, r4]
	ldr r0, [sp]
	adds r1, r0, r1
	ldr r4, _080399C8 @ =0x000001FF
	ands r1, r4
	mov r0, sb
	ldrh r4, [r2, #2]
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	movs r0, #0xf
	ands r0, r2
	mov r4, r8
	orrs r0, r4
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #9
	ble _08039856
_080398D0:
	ldr r7, _080399CC @ =gMain+0x15A8 @gMain.spriteGroups[26]
	ldrh r0, [r7]
	cmp r0, #0
	bne _080398DA
	b _08039A08
_080398DA:
	ldr r6, _080399D0 @ =gCurrentPinballGame
	ldr r4, [r6]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r1, #0x6c
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r4, [r6]
	ldr r3, _080399D4 @ =0x000003EA
	adds r0, r4, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x52
	subs r0, r0, r1
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0803991E
	movs r0, #0xc8
	strh r0, [r7, #4]
_0803991E:
	ldr r4, _080399D8 @ =gUnknown_086AEDCC
	ldr r1, _080399D0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080399DC @ =0x00000456
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x54
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldr r2, _080399E0 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _080399E4 @ =gUnknown_083C13AC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080399E8 @ =0x06012420
	str r0, [r2, #4]
	ldr r0, _080399EC @ =0x80000060
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r2, #0
	ldr r6, _080399C0 @ =gOamBuffer
	ldr r4, _080399C4 @ =0xFFFFFE00
	mov r8, r4
_08039964:
	lsls r4, r2, #0x10
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
	ldr r2, _080399C8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
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
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08039964
	ldr r3, _080399D0 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r6, _080399DC @ =0x00000456
	adds r4, r0, r6
	ldrh r0, [r4]
	cmp r0, #0x52
	bhi _080399F0
	adds r0, #1
	strh r0, [r4]
	b _08039A2C
	.align 2, 0
_080399BC: .4byte gUnknown_086B92FC
_080399C0: .4byte gOamBuffer
_080399C4: .4byte 0xFFFFFE00
_080399C8: .4byte 0x000001FF
_080399CC: .4byte gMain+0x15A8 @gMain.spriteGroups[26]
_080399D0: .4byte gCurrentPinballGame
_080399D4: .4byte 0x000003EA
_080399D8: .4byte gUnknown_086AEDCC
_080399DC: .4byte 0x00000456
_080399E0: .4byte 0x040000D4
_080399E4: .4byte gUnknown_083C13AC
_080399E8: .4byte 0x06012420
_080399EC: .4byte 0x80000060
_080399F0:
	movs r1, #0
	strh r1, [r4]
	ldr r0, _08039A00 @ =gMain
	ldr r2, _08039A04 @ =0x000015A8
	adds r0, r0, r2
	strh r1, [r0]
	b _08039A2C
	.align 2, 0
_08039A00: .4byte gMain
_08039A04: .4byte 0x000015A8
_08039A08:
	ldr r3, _08039A3C @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xb
	bne _08039A2C
	movs r6, #0xf9
	lsls r6, r6, #2
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0xda
	bne _08039A2C
	movs r0, #1
	strh r0, [r7]
_08039A2C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039A3C: .4byte gCurrentPinballGame

	thumb_func_start sub_39A40
sub_39A40: @ 0x08039A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, _08039A84 @ =gMain+0xA28 @gMain.spriteGroups[10]
	str r1, [sp]
	ldrh r0, [r1]
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r1, r2
	mov ip, r1
	cmp r0, #0
	bne _08039A64
	b _08039BF8
_08039A64:
	ldr r0, _08039A88 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _08039A8C @ =0x000006C4
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #3
	bne _08039A90
	movs r0, #0xf0
	ldr r4, [sp]
	strh r0, [r4, #2]
	movs r0, #0xb4
	strh r0, [r4, #4]
	b _08039A9A
	.align 2, 0
_08039A84: .4byte gMain+0xA28 @gMain.spriteGroups[10]
_08039A88: .4byte gCurrentPinballGame
_08039A8C: .4byte 0x000006C4
_08039A90:
	movs r0, #0x60
	ldr r5, [sp]
	strh r0, [r5, #2]
	movs r0, #0x37
	strh r0, [r5, #4]
_08039A9A:
	ldr r6, _08039C24 @ =gCurrentPinballGame
	ldr r1, [r6]
	ldr r7, [sp]
	ldrh r2, [r7, #2]
	ldr r3, _08039C28 @ =0x000006E4
	adds r0, r1, r3
	strh r2, [r0]
	ldrh r0, [r7, #4]
	ldr r4, _08039C2C @ =0x000006E6
	adds r1, r1, r4
	strh r0, [r1]
	movs r5, #4
	ldrsh r0, [r7, r5]
	cmp r0, #0xc7
	ble _08039ABC
	movs r0, #0xc8
	strh r0, [r7, #4]
_08039ABC:
	movs r2, #0
	ldr r6, _08039C30 @ =gMain+0x970 @gMain.spriteGroups[9]
	mov sl, r6
	movs r7, #0xa1
	lsls r7, r7, #3
	add r7, sl
	mov ip, r7
	ldr r5, _08039C34 @ =gOamBuffer
	movs r0, #3
	mov r8, r0
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
_08039AD6:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r2, [sp]
	adds r6, r2, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0xd0
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	ldr r7, _08039C24 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _08039C38 @ =0x000006DB
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r2, r8
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r7, #2
	ldrsh r1, [r6, r7]
	ldr r2, [sp]
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08039C3C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08039C40 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, [sp]
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _08039AD6
	mov r4, sl
	str r4, [sp]
	ldr r5, _08039C24 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _08039C28 @ =0x000006E4
	adds r0, r0, r6
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r4, #2]
	ldr r0, [r5]
	ldr r7, _08039C2C @ =0x000006E6
	adds r0, r0, r7
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08039B7C
	movs r0, #0xc8
	strh r0, [r4, #4]
_08039B7C:
	movs r2, #0
	ldr r5, _08039C34 @ =gOamBuffer
	movs r0, #3
	mov r8, r0
	movs r1, #0xd
	rsbs r1, r1, #0
	mov sb, r1
	ldr r3, _08039C40 @ =0xFFFFFE00
	mov sl, r3
_08039B8E:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r7, [sp]
	adds r6, r7, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	ldr r1, _08039C24 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08039C38 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r7, r8
	ands r1, r7
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r6, r0]
	ldr r2, [sp]
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _08039C3C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, [sp]
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _08039B8E
_08039BF8:
	mov r4, ip
	str r4, [sp]
	ldrh r0, [r4]
	cmp r0, #0
	bne _08039C04
	b _0803A14E
_08039C04:
	ldr r1, _08039C24 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r5, _08039C44 @ =0x00000445
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bls _08039C18
	b _08039EBA
_08039C18:
	lsls r0, r0, #2
	ldr r1, _08039C48 @ =_08039C4C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039C24: .4byte gCurrentPinballGame
_08039C28: .4byte 0x000006E4
_08039C2C: .4byte 0x000006E6
_08039C30: .4byte gMain+0x970 @gMain.spriteGroups[9]
_08039C34: .4byte gOamBuffer
_08039C38: .4byte 0x000006DB
_08039C3C: .4byte 0x000001FF
_08039C40: .4byte 0xFFFFFE00
_08039C44: .4byte 0x00000445
_08039C48: .4byte _08039C4C
_08039C4C: @ jump table
	.4byte _08039C6C @ case 0
	.4byte _08039CFC @ case 1
	.4byte _08039D30 @ case 2
	.4byte _08039D90 @ case 3
	.4byte _08039DC0 @ case 4
	.4byte _08039E20 @ case 5
	.4byte _08039E50 @ case 6
	.4byte _08039EB0 @ case 7
_08039C6C:
	ldr r6, _08039CD0 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r7, _08039CD4 @ =0x00000449
	adds r0, r0, r7
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r6]
	ldr r1, _08039CD8 @ =0x00000446
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r3, _08039CDC @ =0x00000447
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, _08039CE0 @ =0x0000044A
	adds r0, r0, r4
	strb r2, [r0]
	ldr r1, [r6]
	ldr r5, _08039CE4 @ =0x0000044E
	adds r0, r1, r5
	strh r2, [r0]
	movs r6, #0x89
	lsls r6, r6, #3
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08039CAE
	b _08039EBA
_08039CAE:
	ldr r2, _08039CE8 @ =0x040000D4
	ldr r7, _08039CEC @ =0x000005F6
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #8
	lsls r0, r0, #5
	ldr r1, _08039CF0 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08039CF4 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _08039CF8 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08039EBA
	.align 2, 0
_08039CD0: .4byte gCurrentPinballGame
_08039CD4: .4byte 0x00000449
_08039CD8: .4byte 0x00000446
_08039CDC: .4byte 0x00000447
_08039CE0: .4byte 0x0000044A
_08039CE4: .4byte 0x0000044E
_08039CE8: .4byte 0x040000D4
_08039CEC: .4byte 0x000005F6
_08039CF0: .4byte gUnknown_08137E14
_08039CF4: .4byte 0x05000220
_08039CF8: .4byte 0x80000010
_08039CFC:
	ldr r1, _08039D20 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08039D24 @ =0x0000044A
	adds r0, r0, r2
	movs r1, #4
	strb r1, [r0]
	ldr r3, _08039D20 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _08039D28 @ =0x0000044E
	adds r2, r1, r4
	movs r0, #0x5a
	strh r0, [r2]
	ldr r5, _08039D2C @ =0x00000445
	adds r1, r1, r5
	movs r0, #2
	strb r0, [r1]
	b _08039EBA
	.align 2, 0
_08039D20: .4byte gCurrentPinballGame
_08039D24: .4byte 0x0000044A
_08039D28: .4byte 0x0000044E
_08039D2C: .4byte 0x00000445
_08039D30:
	ldr r0, _08039D78 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #4]
	cmp r0, #0
	beq _08039D54
	ldr r6, _08039D7C @ =0x0000044E
	adds r1, r1, r6
	ldrh r0, [r1]
	subs r0, #0x5a
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08039D4E
	movs r0, #0
	strh r0, [r1]
_08039D4E:
	ldr r0, _08039D80 @ =0x00000111
	bl m4aSongNumStart
_08039D54:
	ldr r2, _08039D78 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r7, _08039D84 @ =0x00000449
	adds r0, r0, r7
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08039D88 @ =0x00000446
	adds r0, r0, r1
	movs r1, #9
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08039D8C @ =0x00000447
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	b _08039EBA
	.align 2, 0
_08039D78: .4byte gCurrentPinballGame
_08039D7C: .4byte 0x0000044E
_08039D80: .4byte 0x00000111
_08039D84: .4byte 0x00000449
_08039D88: .4byte 0x00000446
_08039D8C: .4byte 0x00000447
_08039D90:
	ldr r4, _08039DB0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _08039DB4 @ =0x0000044A
	adds r0, r0, r5
	movs r3, #4
	strb r3, [r0]
	ldr r0, [r4]
	ldr r6, _08039DB8 @ =0x0000044E
	adds r2, r0, r6
	movs r1, #0x5a
	strh r1, [r2]
	ldr r7, _08039DBC @ =0x00000445
	adds r0, r0, r7
	strb r3, [r0]
	b _08039EBA
	.align 2, 0
_08039DB0: .4byte gCurrentPinballGame
_08039DB4: .4byte 0x0000044A
_08039DB8: .4byte 0x0000044E
_08039DBC: .4byte 0x00000445
_08039DC0:
	ldr r0, _08039E08 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #4]
	cmp r0, #0
	beq _08039DE4
	ldr r0, _08039E0C @ =0x0000044E
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #0x5a
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08039DDE
	movs r0, #0
	strh r0, [r1]
_08039DDE:
	ldr r0, _08039E10 @ =0x00000111
	bl m4aSongNumStart
_08039DE4:
	ldr r2, _08039E08 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08039E14 @ =0x00000449
	adds r0, r0, r1
	movs r1, #9
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08039E18 @ =0x00000446
	adds r0, r0, r3
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _08039E1C @ =0x00000447
	adds r0, r0, r4
	movs r1, #5
	strb r1, [r0]
	b _08039EBA
	.align 2, 0
_08039E08: .4byte gCurrentPinballGame
_08039E0C: .4byte 0x0000044E
_08039E10: .4byte 0x00000111
_08039E14: .4byte 0x00000449
_08039E18: .4byte 0x00000446
_08039E1C: .4byte 0x00000447
_08039E20:
	ldr r5, _08039E40 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _08039E44 @ =0x0000044A
	adds r0, r0, r6
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r5]
	ldr r7, _08039E48 @ =0x0000044E
	adds r2, r1, r7
	movs r0, #0x5a
	strh r0, [r2]
	ldr r0, _08039E4C @ =0x00000445
	adds r1, r1, r0
	movs r0, #6
	strb r0, [r1]
	b _08039EBA
	.align 2, 0
_08039E40: .4byte gCurrentPinballGame
_08039E44: .4byte 0x0000044A
_08039E48: .4byte 0x0000044E
_08039E4C: .4byte 0x00000445
_08039E50:
	ldr r0, _08039E98 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #4]
	cmp r0, #0
	beq _08039E74
	ldr r2, _08039E9C @ =0x0000044E
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #0x5a
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08039E6E
	movs r0, #0
	strh r0, [r1]
_08039E6E:
	ldr r0, _08039EA0 @ =0x00000111
	bl m4aSongNumStart
_08039E74:
	ldr r2, _08039E98 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _08039EA4 @ =0x00000449
	adds r0, r0, r3
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _08039EA8 @ =0x00000446
	adds r0, r0, r4
	movs r1, #0x13
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _08039EAC @ =0x00000447
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	b _08039EBA
	.align 2, 0
_08039E98: .4byte gCurrentPinballGame
_08039E9C: .4byte 0x0000044E
_08039EA0: .4byte 0x00000111
_08039EA4: .4byte 0x00000449
_08039EA8: .4byte 0x00000446
_08039EAC: .4byte 0x00000447
_08039EB0:
	ldr r0, _08039EE0 @ =gMain
	ldr r6, _08039EE4 @ =0x00000E78
	adds r0, r0, r6
	movs r1, #0
	strh r1, [r0]
_08039EBA:
	ldr r7, _08039EE8 @ =gCurrentPinballGame
	ldr r4, [r7]
	ldr r0, _08039EEC @ =0x0000044E
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08039EF4
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08039ED8
	b _08039FF4
_08039ED8:
	ldr r0, _08039EF0 @ =0x00000111
	bl m4aSongNumStart
	b _08039FF4
	.align 2, 0
_08039EE0: .4byte gMain
_08039EE4: .4byte 0x00000E78
_08039EE8: .4byte gCurrentPinballGame
_08039EEC: .4byte 0x0000044E
_08039EF0: .4byte 0x00000111
_08039EF4:
	ldr r2, _08039F20 @ =gUnknown_086AEE5E
	movs r5, #0x89
	lsls r5, r5, #3
	adds r3, r4, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r7, _08039F24 @ =0x00000454
	adds r1, r4, r7
	ldrh r2, [r1]
	cmp r0, r2
	ble _08039F28
	adds r0, r2, #1
	strh r0, [r1]
	b _08039FF4
	.align 2, 0
_08039F20: .4byte gUnknown_086AEE5E
_08039F24: .4byte 0x00000454
_08039F28:
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, _08039F74 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r1, #0x89
	lsls r1, r1, #3
	adds r3, r2, r1
	ldr r4, _08039F78 @ =0x00000446
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldrb r4, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08039FA4
	ldr r5, _08039F7C @ =0x0000044A
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08039F84
	ldr r6, _08039F80 @ =0x00000449
	adds r0, r2, r6
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r7, _08039F74 @ =gCurrentPinballGame
	ldr r1, [r7]
	adds r1, r1, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08039F98
	.align 2, 0
_08039F74: .4byte gCurrentPinballGame
_08039F78: .4byte 0x00000446
_08039F7C: .4byte 0x0000044A
_08039F80: .4byte 0x00000449
_08039F84:
	subs r0, r4, #1
	strb r0, [r3]
	ldr r1, _0803A028 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0803A02C @ =0x00000447
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0803A030 @ =0x00000445
	adds r0, r0, r3
	strb r1, [r0]
_08039F98:
	ldr r4, _0803A028 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _0803A034 @ =0x0000044E
	adds r0, r0, r5
	movs r1, #0x5a
	strh r1, [r0]
_08039FA4:
	ldr r5, _0803A028 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r4, #0x89
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08039FC0
	movs r0, #0x88
	lsls r0, r0, #1
	bl m4aSongNumStart
_08039FC0:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	bne _08039FF4
	ldr r2, _0803A038 @ =0x040000D4
	ldr r6, _0803A03C @ =0x000005F6
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	ldr r1, _0803A040 @ =gUnknown_08137E14
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0803A044 @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0803A048 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0x89
	lsls r0, r0, #1
	bl m4aSongNumStart
_08039FF4:
	ldr r0, _0803A028 @ =gCurrentPinballGame
	ldr r3, [r0]
	movs r7, #0x89
	lsls r7, r7, #3
	adds r1, r3, r7
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0x11
	bgt _0803A054
	ldr r0, _0803A04C @ =0x00000383
	adds r1, r3, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803A028 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _0803A050 @ =0x0000132C
	adds r0, r0, r3
	ldr r1, [r0]
	strh r2, [r1, #0x30]
	ldr r1, [r0]
	strh r2, [r1, #0x32]
	ldr r0, [r0]
	strh r2, [r0, #6]
	b _0803A05C
	.align 2, 0
_0803A028: .4byte gCurrentPinballGame
_0803A02C: .4byte 0x00000447
_0803A030: .4byte 0x00000445
_0803A034: .4byte 0x0000044E
_0803A038: .4byte 0x040000D4
_0803A03C: .4byte 0x000005F6
_0803A040: .4byte gUnknown_08137E14
_0803A044: .4byte 0x05000220
_0803A048: .4byte 0x80000010
_0803A04C: .4byte 0x00000383
_0803A050: .4byte 0x0000132C
_0803A054:
	ldr r4, _0803A194 @ =0x00000383
	adds r1, r3, r4
	movs r0, #0
	strb r0, [r1]
_0803A05C:
	ldr r5, _0803A198 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _0803A19C @ =0x0000132C
	adds r0, r0, r6
	ldr r1, [r0]
	ldrh r1, [r1, #0x24]
	ldr r7, [sp]
	strh r1, [r7, #2]
	ldr r0, [r0]
	ldrh r0, [r0, #0x26]
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0803A07E
	movs r0, #0xc8
	strh r0, [r7, #4]
_0803A07E:
	ldr r4, _0803A1A0 @ =gUnknown_086AEE5E
	ldr r1, _0803A198 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r3, #0x89
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r4, #4
	adds r0, r0, r1
	ldr r2, _0803A1A4 @ =0x040000D4
	ldrh r5, [r0]
	str r5, [sp, #4]
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _0803A1A8 @ =gUnknown_083C1A6C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0803A1AC @ =0x060124E0
	str r0, [r2, #4]
	ldr r0, _0803A1B0 @ =0x800001E0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r7, _0803A198 @ =gCurrentPinballGame
	ldr r0, [r7]
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldr r1, _0803A1B4 @ =gUnknown_086B91AC
	mov sb, r1
	ldr r5, _0803A1B8 @ =gOamBuffer
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sl, r0
	ldr r4, _0803A1BC @ =0xFFFFFE00
	mov r8, r4
_0803A0E2:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r7, [sp]
	adds r6, r7, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	add r0, sl
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov ip, r1
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r7, ip
	adds r1, r7, r0
	ldr r7, _0803A1C0 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0803A0E2
_0803A14E:
	movs r2, #0
_0803A150: @ 0x0803A150, bl-ed to but not subroutine?
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	movs r0, #0xb8
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, _0803A1C4 @ =gMain+0x12C8 @gMain.spriteGroups[22]
	adds r1, r1, r0
	str r1, [sp]
	ldr r5, _0803A1C8 @ =0xFFFFED38
	adds r0, r0, r5
	ldrb r1, [r0, #0xf]
	movs r0, #0x80
	ands r0, r1
	str r2, [sp, #0x3c]
	cmp r0, #0
	beq _0803A174
	bl _0803A9A6
_0803A174:
	ldr r0, _0803A198 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r6, _0803A1CC @ =0x00000441
	adds r0, r0, r6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bls _0803A18A
	b _0803A8A2
_0803A18A:
	lsls r0, r0, #2
	ldr r1, _0803A1D0 @ =_0803A1D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A194: .4byte 0x00000383
_0803A198: .4byte gCurrentPinballGame
_0803A19C: .4byte 0x0000132C
_0803A1A0: .4byte gUnknown_086AEE5E
_0803A1A4: .4byte 0x040000D4
_0803A1A8: .4byte gUnknown_083C1A6C
_0803A1AC: .4byte 0x060124E0
_0803A1B0: .4byte 0x800001E0
_0803A1B4: .4byte gUnknown_086B91AC
_0803A1B8: .4byte gOamBuffer
_0803A1BC: .4byte 0xFFFFFE00
_0803A1C0: .4byte 0x000001FF
_0803A1C4: .4byte gMain+0x12C8 @gMain.spriteGroups[22]
_0803A1C8: .4byte 0xFFFFED38
_0803A1CC: .4byte 0x00000441
_0803A1D0: .4byte _0803A1D4
_0803A1D4: @ jump table
	.4byte _0803A1EC @ case 0
	.4byte _0803A218 @ case 1
	.4byte _0803A2E4 @ case 2
	.4byte _0803A4F0 @ case 3
	.4byte _0803A6B8 @ case 4
	.4byte _0803A860 @ case 5
_0803A1EC:
	movs r7, #0
	str r7, [sp, #4]
	ldr r0, _0803A20C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, [sp, #0x3c]
	asrs r0, r2, #0xe
	adds r1, r1, r0
	ldr r3, _0803A210 @ =0x0000045C
	adds r0, r1, r3
	strh r7, [r0]
	ldr r5, _0803A214 @ =0x0000045E
	adds r1, r1, r5
	mov r6, sp
	ldrh r6, [r6, #4]
	strh r6, [r1]
	b _0803A8A2
	.align 2, 0
_0803A20C: .4byte gCurrentPinballGame
_0803A210: .4byte 0x0000045C
_0803A214: .4byte 0x0000045E
_0803A218:
	ldr r7, _0803A248 @ =gCurrentPinballGame
	mov r8, r7
	mov r0, r8
	ldr r6, [r0]
	ldr r1, [sp, #0x3c]
	asrs r7, r1, #0x10
	lsls r1, r7, #1
	movs r2, #0x8b
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r5, r0, r1
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #9
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	cmp r4, #0x61
	bhi _0803A24C
	adds r0, r4, #1
	strh r0, [r5]
	b _0803A2AA
	.align 2, 0
_0803A248: .4byte gCurrentPinballGame
_0803A24C:
	movs r0, #0
	strh r0, [r5]
	ldr r3, _0803A2C4 @ =0x00000441
	adds r0, r6, r3
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
	bl Random
	mov r4, r8
	ldr r5, [r4]
	ldr r6, _0803A2C8 @ =0x00000443
	adds r5, r5, r6
	adds r5, r5, r7
	lsls r4, r7, #3
	subs r4, r4, r7
	ldr r1, _0803A2CC @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #7
	bl __umodsi3
	adds r4, r4, r0
	strb r4, [r5]
	mov r5, r8
	ldr r1, [r5]
	lsls r3, r7, #2
	adds r3, r1, r3
	ldr r4, _0803A2D0 @ =gUnknown_086AEDE8
	adds r1, r1, r6
	adds r1, r1, r7
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r6, #0x21
	adds r0, r3, r6
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	ldr r7, _0803A2D4 @ =0x00000466
	adds r3, r3, r7
	strh r0, [r3]
_0803A2AA:
	ldr r0, _0803A2D8 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, [sp, #0x3c]
	asrs r0, r2, #0xe
	adds r1, r1, r0
	ldr r3, _0803A2DC @ =0x0000045C
	adds r0, r1, r3
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0803A2E0 @ =0x0000045E
	adds r1, r1, r4
	strh r2, [r1]
	b _0803A8A2
	.align 2, 0
_0803A2C4: .4byte 0x00000441
_0803A2C8: .4byte 0x00000443
_0803A2CC: .4byte gMain
_0803A2D0: .4byte gUnknown_086AEDE8
_0803A2D4: .4byte 0x00000466
_0803A2D8: .4byte gCurrentPinballGame
_0803A2DC: .4byte 0x0000045C
_0803A2E0: .4byte 0x0000045E
_0803A2E4:
	ldr r5, _0803A4AC @ =gCurrentPinballGame
	mov sl, r5
	ldr r7, [r5]
	ldr r6, [sp, #0x3c]
	asrs r6, r6, #0x10
	mov sb, r6
	lsls r6, r6, #1
	str r6, [sp, #0x20]
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r7, r1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x13
	adds r0, #6
	str r0, [sp, #4]
	ldr r2, _0803A4B0 @ =0x00000441
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0803A31C
	b _0803A48A
_0803A31C:
	ldr r3, _0803A4B4 @ =0x00000442
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _0803A32C
	b _0803A48A
_0803A32C:
	ldr r4, _0803A4B8 @ =0x0000132C
	adds r0, r7, r4
	ldr r6, [r0]
	movs r5, #0x10
	ldrsh r4, [r6, r5]
	subs r4, #0x78
	mov r0, sb
	lsls r0, r0, #2
	str r0, [sp, #0x24]
	adds r5, r7, r0
	ldr r1, _0803A4BC @ =0x0000045C
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, r4, r0
	str r0, [sp, #0x10]
	movs r3, #0x12
	ldrsh r4, [r6, r3]
	subs r4, #0x90
	ldr r6, _0803A4C0 @ =0x0000045E
	adds r5, r5, r6
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, r4, r0
	str r0, [sp, #0x14]
	ldr r2, [sp, #0x10]
	adds r1, r2, #0
	muls r1, r2, r1
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	mov r8, r1
	ldr r4, _0803A4C4 @ =0x00000383
	adds r0, r7, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803A48A
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803A48A
	ldr r1, _0803A4C8 @ =0x00000385
	adds r0, r7, r1
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _0803A48A
	ldr r3, _0803A4CC @ =0x00000452
	adds r0, r7, r3
	ldrh r5, [r0]
	cmp r5, #0
	bne _0803A48A
	ldr r0, _0803A4D0 @ =0x0000018F
	cmp r8, r0
	bgt _0803A48A
	subs r0, #0x7c
	bl m4aSongNumStart
	movs r0, #0xc
	bl sub_11B0
	mov r4, sl
	ldr r0, [r4]
	movs r2, #1
	strb r2, [r0, #0x1f]
	ldr r1, [r4]
	movs r7, #0x8b
	lsls r7, r7, #3
	adds r0, r1, r7
	ldr r3, [sp, #0x20]
	adds r0, r0, r3
	strh r5, [r0]
	ldr r4, _0803A4B0 @ =0x00000441
	adds r1, r1, r4
	add r1, sb
	movs r0, #3
	strb r0, [r1]
	mov r5, sl
	ldr r0, [r5]
	ldr r7, _0803A4D4 @ =0x000005FA
	adds r0, r0, r7
	strb r2, [r0]
	ldr r5, [r5]
	ldr r0, [sp, #0x24]
	adds r4, r5, r0
	ldr r1, _0803A4BC @ =0x0000045C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x78
	str r0, [sp, #8]
	adds r4, r4, r6
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x90
	str r0, [sp, #0xc]
	ldr r4, [sp, #8]
	lsls r1, r4, #8
	ldr r6, _0803A4B8 @ =0x0000132C
	adds r0, r5, r6
	ldr r2, [r0]
	ldr r0, [r2, #0x34]
	subs r0, r1, r0
	str r0, [sp, #0x10]
	ldr r7, [sp, #0xc]
	lsls r1, r7, #8
	ldr r0, [r2, #0x38]
	subs r0, r1, r0
	str r0, [sp, #0x14]
	ldr r4, _0803A4D8 @ =0x000005AC
	adds r5, r5, r4
	ldr r1, [sp, #0x10]
	adds r0, r1, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x14]
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	str r0, [r5]
	lsls r0, r0, #2
	bl Sqrt
	mov r3, sl
	ldr r1, [r3]
	adds r1, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	str r0, [r1]
	ldr r4, [sp, #0x10]
	rsbs r0, r4, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r5, [sp, #0x14]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	mov r6, sl
	ldr r1, [r6]
	movs r7, #0xb6
	lsls r7, r7, #3
	adds r1, r1, r7
	strh r0, [r1]
_0803A48A:
	ldr r0, _0803A4AC @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r0, [sp, #0x3c]
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	movs r2, #0x8b
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r1, r0, r1
	ldrh r2, [r1]
	ldr r0, _0803A4C4 @ =0x00000383
	cmp r2, r0
	bhi _0803A4DC
	adds r0, r2, #1
	strh r0, [r1]
	b _0803A8A2
	.align 2, 0
_0803A4AC: .4byte gCurrentPinballGame
_0803A4B0: .4byte 0x00000441
_0803A4B4: .4byte 0x00000442
_0803A4B8: .4byte 0x0000132C
_0803A4BC: .4byte 0x0000045C
_0803A4C0: .4byte 0x0000045E
_0803A4C4: .4byte 0x00000383
_0803A4C8: .4byte 0x00000385
_0803A4CC: .4byte 0x00000452
_0803A4D0: .4byte 0x0000018F
_0803A4D4: .4byte 0x000005FA
_0803A4D8: .4byte 0x000005AC
_0803A4DC:
	movs r0, #0
	strh r0, [r1]
	ldr r5, _0803A4EC @ =0x00000441
	adds r0, r3, r5
	adds r0, r0, r4
	movs r1, #5
	b _0803A8A0
	.align 2, 0
_0803A4EC: .4byte 0x00000441
_0803A4F0:
	ldr r6, _0803A668 @ =gCurrentPinballGame
	ldr r4, [r6]
	ldr r7, [sp, #0x3c]
	asrs r7, r7, #0x10
	str r7, [sp, #0x28]
	lsls r0, r7, #1
	str r0, [sp, #0x2c]
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [sp, #0x2c]
	adds r6, r0, r2
	ldrh r5, [r6]
	adds r0, r5, #0
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x13
	adds r0, #6
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq _0803A526
	adds r0, r5, #0
	adds r0, #8
	strh r0, [r6]
_0803A526:
	ldr r3, _0803A668 @ =gCurrentPinballGame
	ldr r7, [r3]
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [sp, #0x2c]
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x1d
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bgt _0803A546
	movs r4, #0xa
_0803A546:
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r5, r7, r6
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0xd
	movs r1, #0x1e
	bl __divsi3
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #1
	movs r1, #5
	bl __divsi3
	ldrh r1, [r5]
	subs r1, r1, r0
	strh r1, [r5]
	ldr r6, _0803A66C @ =0x0000132C
	adds r0, r7, r6
	ldr r1, [r0]
	ldr r2, _0803A670 @ =0xFFFFE000
	adds r0, r2, #0
	ldrh r3, [r1, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #0xa]
	ldr r1, _0803A674 @ =0x000005AC
	adds r0, r7, r1
	ldr r0, [r0]
	muls r0, r4, r0
	movs r1, #0x1e
	bl __divsi3
	mov sl, r0
	ldr r2, [sp, #0x28]
	lsls r4, r2, #2
	adds r4, r7, r4
	ldr r3, _0803A678 @ =0x0000045C
	adds r0, r4, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x78
	str r0, [sp, #8]
	ldr r0, _0803A67C @ =0x0000045E
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x90
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	bl Cos
	ldr r2, _0803A668 @ =gCurrentPinballGame
	ldr r5, [r2]
	adds r1, r5, r6
	ldr r1, [r1]
	mov r8, r1
	ldr r3, [sp, #8]
	lsls r4, r3, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r7, sl
	muls r7, r0, r7
	adds r0, r7, #0
	ldr r1, _0803A680 @ =0x00004E20
	mov sb, r1
	bl __divsi3
	adds r4, r4, r0
	mov r2, r8
	str r4, [r2, #0x34]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r5, r5, r3
	ldrh r0, [r5]
	bl Sin
	ldr r4, _0803A668 @ =gCurrentPinballGame
	ldr r7, [r4]
	adds r6, r7, r6
	ldr r5, [r6]
	ldr r1, [sp, #0xc]
	lsls r4, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	mov r1, sb
	bl __divsi3
	subs r4, r4, r0
	str r4, [r5, #0x38]
	ldr r4, [r6]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x30]
	ldr r4, [r6]
	movs r5, #0x32
	ldrsh r0, [r4, r5]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x32]
	movs r6, #0x8b
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [sp, #0x2c]
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r0, _0803A684 @ =0x000001DF
	cmp r2, r0
	bhi _0803A688
	adds r0, r2, #1
	strh r0, [r1]
	ldrh r0, [r1]
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803A65E
	b _0803A8A2
_0803A65E:
	movs r0, #0xc
	bl sub_11B0
	b _0803A8A2
	.align 2, 0
_0803A668: .4byte gCurrentPinballGame
_0803A66C: .4byte 0x0000132C
_0803A670: .4byte 0xFFFFE000
_0803A674: .4byte 0x000005AC
_0803A678: .4byte 0x0000045C
_0803A67C: .4byte 0x0000045E
_0803A680: .4byte 0x00004E20
_0803A684: .4byte 0x000001DF
_0803A688:
	movs r3, #0
	strh r3, [r1]
	ldr r4, _0803A6AC @ =0x00000441
	adds r0, r7, r4
	ldr r5, [sp, #0x28]
	adds r0, r0, r5
	movs r1, #4
	strb r1, [r0]
	ldr r6, _0803A6B0 @ =gCurrentPinballGame
	ldr r2, [r6]
	ldr r7, _0803A6B4 @ =0x000005AC
	adds r2, r2, r7
	ldr r0, [r2]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r2]
	b _0803A8A2
	.align 2, 0
_0803A6AC: .4byte 0x00000441
_0803A6B0: .4byte gCurrentPinballGame
_0803A6B4: .4byte 0x000005AC
_0803A6B8:
	ldr r0, _0803A7EC @ =gCurrentPinballGame
	ldr r5, [r0]
	ldr r1, [sp, #0x3c]
	asrs r1, r1, #0x10
	str r1, [sp, #0x30]
	lsls r2, r1, #1
	str r2, [sp, #0x34]
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	lsrs r1, r2, #3
	movs r0, #5
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r4, #0x2f
	subs r4, r4, r2
	movs r7, #0xb6
	lsls r7, r7, #3
	adds r6, r5, r7
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0xc
	movs r1, #0x2f
	bl __divsi3
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #1
	movs r1, #5
	bl __divsi3
	ldrh r1, [r6]
	subs r1, r1, r0
	strh r1, [r6]
	ldr r0, _0803A7F0 @ =0x0000132C
	mov sb, r0
	adds r0, r5, r0
	ldr r1, [r0]
	ldr r2, _0803A7F4 @ =0xFFFFE000
	adds r0, r2, #0
	ldrh r3, [r1, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #0xa]
	ldr r1, _0803A7F8 @ =0x000005AC
	adds r0, r5, r1
	ldr r0, [r0]
	muls r0, r4, r0
	movs r1, #0x2f
	bl __divsi3
	mov sl, r0
	ldr r2, [sp, #0x30]
	lsls r0, r2, #2
	adds r5, r5, r0
	ldr r3, _0803A7FC @ =0x0000045C
	adds r0, r5, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x78
	str r0, [sp, #8]
	ldr r0, _0803A800 @ =0x0000045E
	adds r5, r5, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x90
	str r0, [sp, #0xc]
	ldrh r0, [r6]
	bl Cos
	ldr r2, _0803A7EC @ =gCurrentPinballGame
	ldr r5, [r2]
	mov r3, sb
	adds r1, r5, r3
	ldr r6, [r1]
	ldr r1, [sp, #8]
	lsls r4, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r3, _0803A804 @ =0x00004E20
	mov r8, r3
	mov r1, r8
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x34]
	adds r5, r5, r7
	ldrh r0, [r5]
	bl Sin
	ldr r4, _0803A7EC @ =gCurrentPinballGame
	ldr r7, [r4]
	mov r5, sb
	adds r6, r7, r5
	ldr r5, [r6]
	ldr r1, [sp, #0xc]
	lsls r4, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	mov r1, r8
	bl __divsi3
	subs r4, r4, r0
	str r4, [r5, #0x38]
	ldr r4, [r6]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x30]
	ldr r4, [r6]
	movs r5, #0x32
	ldrsh r0, [r4, r5]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x32]
	movs r0, #0x8b
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x38]
	ldr r2, [sp, #0x34]
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0x2e
	bhi _0803A808
	adds r0, #1
	strh r0, [r1]
	b _0803A8A2
	.align 2, 0
_0803A7EC: .4byte gCurrentPinballGame
_0803A7F0: .4byte 0x0000132C
_0803A7F4: .4byte 0xFFFFE000
_0803A7F8: .4byte 0x000005AC
_0803A7FC: .4byte 0x0000045C
_0803A800: .4byte 0x0000045E
_0803A804: .4byte 0x00004E20
_0803A808:
	movs r3, #0
	strh r3, [r1]
	ldr r3, [r6]
	ldr r0, _0803A84C @ =gMain
	ldr r2, [r0, #0x4c]
	movs r0, #1
	ands r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0803A850 @ =0x0000FF6A
	adds r0, r0, r4
	strh r0, [r3, #0x30]
	ldr r1, [r6]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1, #0x32]
	movs r5, #0
	strb r5, [r7, #0x1f]
	ldr r6, _0803A854 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r7, _0803A858 @ =0x00000441
	adds r0, r0, r7
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r6]
	ldr r2, _0803A85C @ =0x000005FA
	adds r0, r0, r2
	strb r5, [r0]
	b _0803A8A2
	.align 2, 0
_0803A84C: .4byte gMain
_0803A850: .4byte 0x0000FF6A
_0803A854: .4byte gCurrentPinballGame
_0803A858: .4byte 0x00000441
_0803A85C: .4byte 0x000005FA
_0803A860:
	ldr r0, _0803A890 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r3, [sp, #0x3c]
	asrs r7, r3, #0x10
	lsls r1, r7, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r6, r4
	adds r5, r0, r1
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #6
	bl __udivsi3
	movs r1, #5
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #4]
	cmp r4, #0x23
	bhi _0803A894
	adds r0, r4, #1
	strh r0, [r5]
	b _0803A8A2
	.align 2, 0
_0803A890: .4byte gCurrentPinballGame
_0803A894:
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	ldr r5, _0803AA20 @ =0x00000441
	adds r0, r6, r5
	adds r0, r0, r7
_0803A8A0:
	strb r1, [r0]
_0803A8A2:
	ldr r6, _0803AA24 @ =gCurrentPinballGame
	mov sl, r6
	ldr r1, [r6]
	ldr r0, [sp, #0x3c]
	asrs r7, r0, #0x10
	ldr r2, _0803AA20 @ =0x00000441
	adds r0, r1, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0803A9A6
	lsls r3, r7, #2
	mov sb, r3
	add r1, sb
	ldr r4, _0803AA28 @ =0x00000464
	adds r0, r1, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r5, _0803AA2C @ =0x0000045C
	adds r0, r1, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r0, r2, r0
	str r0, [sp, #0x10]
	ldr r2, _0803AA30 @ =0x00000466
	adds r0, r1, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r6, _0803AA34 @ =0x0000045E
	adds r1, r1, r6
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	adds r1, r0, #0
	muls r1, r0, r1
	ldr r2, [sp, #0x14]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	mov r8, r1
	ldr r3, [sp, #0x10]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	rsbs r1, r2, #0
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
	ldr r1, _0803AA38 @ =0x00001388
	bl __divsi3
	str r0, [sp, #0x18]
	adds r0, r4, #0
	bl Sin
	lsls r0, r0, #0x10
	asrs r0, r0, #0xe
	rsbs r0, r0, #0
	ldr r1, _0803AA3C @ =0x00004E20
	bl __divsi3
	str r0, [sp, #0x1c]
	mov r4, sl
	ldr r1, [r4]
	add r1, sb
	adds r5, r1, r5
	ldrh r0, [r5]
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	strh r0, [r5]
	adds r1, r1, r6
	ldrh r0, [r1]
	ldr r3, [sp, #0x1c]
	adds r0, r3, r0
	strh r0, [r1]
	ldr r0, _0803AA40 @ =0x000009C3
	cmp r8, r0
	bgt _0803A9A6
	bl Random
	ldr r5, [r4]
	subs r6, #0x1b
	adds r5, r5, r6
	adds r5, r5, r7
	lsls r4, r7, #3
	subs r4, r4, r7
	ldr r1, _0803AA44 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #7
	bl __umodsi3
	adds r4, r4, r0
	strb r4, [r5]
	mov r4, sl
	ldr r1, [r4]
	mov r5, sb
	adds r3, r1, r5
	ldr r4, _0803AA48 @ =gUnknown_086AEDE8
	adds r1, r1, r6
	adds r1, r1, r7
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r2, [r0]
	adds r6, #0x21
	adds r0, r3, r6
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	ldr r7, _0803AA30 @ =0x00000466
	adds r3, r3, r7
	strh r0, [r3]
_0803A9A6:
	ldr r2, _0803AA4C @ =0x040000D4
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r0, r0, #7
	ldr r1, _0803AA50 @ =gUnknown_084FF90C
	adds r0, r0, r1
	str r0, [r2]
	ldr r3, [sp, #0x3c]
	asrs r4, r3, #0x10
	lsls r0, r4, #9
	ldr r5, _0803AA54 @ =0x06011520
	adds r0, r0, r5
	str r0, [r2, #4]
	ldr r0, _0803AA58 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r6, [sp]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0803AA9E
	ldr r0, _0803AA24 @ =gCurrentPinballGame
	ldr r5, [r0]
	ldr r7, _0803AA20 @ =0x00000441
	adds r0, r5, r7
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0803AA5C
	lsls r4, r4, #2
	adds r4, r5, r4
	ldr r1, _0803AA2C @ =0x0000045C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r1, #0x68
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _0803AA34 @ =0x0000045E
	adds r4, r4, r3
	movs r6, #0
	ldrsh r0, [r4, r6]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r1, #0x80
	subs r0, r0, r1
	ldr r7, [sp]
	strh r0, [r7, #4]
	b _0803AA66
	.align 2, 0
_0803AA20: .4byte 0x00000441
_0803AA24: .4byte gCurrentPinballGame
_0803AA28: .4byte 0x00000464
_0803AA2C: .4byte 0x0000045C
_0803AA30: .4byte 0x00000466
_0803AA34: .4byte 0x0000045E
_0803AA38: .4byte 0x00001388
_0803AA3C: .4byte 0x00004E20
_0803AA40: .4byte 0x000009C3
_0803AA44: .4byte gMain
_0803AA48: .4byte gUnknown_086AEDE8
_0803AA4C: .4byte 0x040000D4
_0803AA50: .4byte gUnknown_084FF90C
_0803AA54: .4byte 0x06011520
_0803AA58: .4byte 0x80000100
_0803AA5C:
	movs r0, #0xf0
	ldr r1, [sp]
	strh r0, [r1, #2]
	movs r0, #0xb4
	strh r0, [r1, #4]
_0803AA66:
	ldr r6, [sp]
	adds r6, #8
	ldr r4, _0803AB38 @ =gOamBuffer
	ldr r2, [sp]
	ldrh r3, [r2, #8]
	lsls r3, r3, #3
	adds r3, r3, r4
	movs r5, #2
	ldrsh r1, [r6, r5]
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0803AB3C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0803AB40 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldr r3, [sp]
	ldrh r1, [r3, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
_0803AA9E:
	ldr r4, [sp, #0x3c]
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r4, r5
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0803AAB2
	bl _0803A150
_0803AAB2:
	ldr r6, _0803AB44 @ =gMain+0x1438 @gMain.spriteGroups[24]
	str r6, [sp]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0803AABE
	b _0803AD44
_0803AABE:
	ldr r0, _0803AB48 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r7, _0803AB4C @ =0x00000456
	adds r3, r1, r7
	ldrh r1, [r3]
	cmp r1, #0x23
	bhi _0803AB7C
	adds r0, r1, #0
	lsls r0, r0, #9
	movs r1, #0x23
	bl __divsi3
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0803AAE8
	adds r6, r1, #0
_0803AAE8:
	lsls r5, r6, #0x10
	asrs r5, r5, #0x10
	adds r0, r5, #0
	adds r1, r5, #0
	movs r2, #1
	bl SetMatrixScale
	rsbs r4, r5, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #2
	bl SetMatrixScale
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #3
	bl SetMatrixScale
	adds r0, r4, #0
	adds r1, r4, #0
	movs r2, #4
	bl SetMatrixScale
	ldr r1, _0803AB48 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r1, r0, r7
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _0803AB50
	subs r0, #0x1e
	movs r1, #0xb
	muls r0, r1, r0
	movs r1, #5
	bl __divsi3
	movs r1, #0xc
	b _0803AB5C
	.align 2, 0
_0803AB38: .4byte gOamBuffer
_0803AB3C: .4byte 0x000001FF
_0803AB40: .4byte 0xFFFFFE00
_0803AB44: .4byte gMain+0x1438 @gMain.spriteGroups[24]
_0803AB48: .4byte gCurrentPinballGame
_0803AB4C: .4byte 0x00000456
_0803AB50:
	ldrh r0, [r1]
	lsls r0, r0, #2
	movs r1, #0x1e
	bl __divsi3
	movs r1, #0x10
_0803AB5C:
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, _0803AB74 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0803AB78 @ =0x00000456
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0803AB86
	.align 2, 0
_0803AB74: .4byte gCurrentPinballGame
_0803AB78: .4byte 0x00000456
_0803AB7C:
	movs r6, #0x80
	lsls r6, r6, #1
	movs r4, #0
	ldr r5, [sp]
	strh r4, [r5]
_0803AB86:
	ldr r7, _0803AD54 @ =gCurrentPinballGame
	ldr r1, [r7]
	lsls r0, r6, #0x10
	asrs r5, r0, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0803AB96
	adds r0, r5, #7
_0803AB96:
	asrs r3, r0, #3
	movs r0, #0x20
	subs r2, r0, r3
	ldr r6, _0803AD58 @ =0x0000046C
	adds r0, r1, r6
	strh r2, [r0]
	adds r3, #0x20
	movs r7, #0x8e
	lsls r7, r7, #3
	adds r0, r1, r7
	strh r3, [r0]
	ldr r6, _0803AD5C @ =0x00000474
	adds r0, r1, r6
	strh r2, [r0]
	movs r7, #0x8f
	lsls r7, r7, #3
	adds r0, r1, r7
	strh r3, [r0]
	ldr r6, _0803AD60 @ =0x0000046E
	adds r0, r1, r6
	strh r2, [r0]
	ldr r7, _0803AD64 @ =0x00000472
	adds r0, r1, r7
	strh r2, [r0]
	ldr r2, _0803AD68 @ =0x00000476
	adds r0, r1, r2
	strh r3, [r0]
	ldr r5, _0803AD6C @ =0x0000047A
	adds r0, r1, r5
	strh r3, [r0]
	ldr r2, _0803AD70 @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #0xc0
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	bne _0803ABF6
	ldrh r0, [r2, #0x38]
	ldr r0, _0803AD74 @ =0x00001E10
	strh r0, [r2, #0x38]
	movs r0, #0x10
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r0, r1
	ldrh r1, [r2, #0x3a]
	strh r0, [r2, #0x3a]
_0803ABF6:
	ldr r6, [sp]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0803ACAE
	ldr r7, _0803AD54 @ =gCurrentPinballGame
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x17
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0x1e
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	ldr r7, _0803AD78 @ =gOamBuffer
	ldr r0, _0803AD7C @ =0xFFFFFE00
	mov sl, r0
	movs r1, #0xf
	rsbs r1, r1, #0
	mov r8, r1
_0803AC26:
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #3
	adds r0, #8
	ldr r2, [sp]
	adds r6, r2, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r4, #2
	ldrsh r1, [r6, r4]
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r1, r1, r0
	ldr r0, _0803AD54 @ =gCurrentPinballGame
	ldr r4, [r0]
	lsls r0, r5, #2
	adds r4, r4, r0
	ldr r2, _0803AD58 @ =0x0000046C
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _0803AD80 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldr r3, [sp]
	ldrb r1, [r3, #4]
	ldrb r0, [r6, #4]
	adds r1, r1, r0
	ldr r3, _0803AD60 @ =0x0000046E
	adds r4, r4, r3
	ldrb r0, [r4]
	adds r0, r0, r1
	strb r0, [r2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r0, [r2, #1]
	movs r1, #3
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r7
	adds r5, #1
	movs r0, #7
	adds r1, r5, #0
	ands r1, r0
	lsls r1, r1, #1
	ldrb r2, [r3, #3]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #3]
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #3
	ble _0803AC26
_0803ACAE:
	ldr r4, _0803AD54 @ =gCurrentPinballGame
	ldr r3, [r4]
	ldr r5, _0803AD84 @ =0x00000456
	adds r4, r3, r5
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _0803AD30
	ldr r6, _0803AD88 @ =0x0000132C
	adds r0, r3, r6
	ldr r1, [r0]
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	subs r0, #0x77
	str r0, [sp, #0x10]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	subs r0, #0x7f
	str r0, [sp, #0x14]
	ldr r5, [sp, #0x10]
	adds r1, r5, #0
	muls r1, r5, r1
	adds r6, r0, #0
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r1, r0
	mov r8, r1
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r0, r3, r7
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #0
	bne _0803AD30
	ldr r0, _0803AD8C @ =gUnknown_086AEE20
	ldrh r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r8, r0
	bge _0803AD30
	ldr r5, _0803AD90 @ =0x00000445
	adds r0, r3, r5
	strb r2, [r0]
	ldr r6, _0803AD54 @ =gCurrentPinballGame
	ldr r0, [r6]
	adds r7, #0xc0
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r6]
	ldr r1, _0803AD94 @ =0x00000454
	adds r0, r0, r1
	strh r2, [r0]
	ldr r5, _0803AD70 @ =gMain
	ldr r2, _0803AD98 @ =0x00000E78
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _0803AD2A
	movs r0, #8
	bl sub_11B0
_0803AD2A:
	movs r0, #1
	strh r0, [r4]
	mov sb, r5
_0803AD30:
	mov r3, sb
	ldrb r1, [r3, #0xf]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0803AD44
	ldr r1, _0803AD9C @ =0x00001438
	add r1, sb
	movs r0, #0
	strh r0, [r1]
_0803AD44:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD54: .4byte gCurrentPinballGame
_0803AD58: .4byte 0x0000046C
_0803AD5C: .4byte 0x00000474
_0803AD60: .4byte 0x0000046E
_0803AD64: .4byte 0x00000472
_0803AD68: .4byte 0x00000476
_0803AD6C: .4byte 0x0000047A
_0803AD70: .4byte gMain
_0803AD74: .4byte 0x00001E10
_0803AD78: .4byte gOamBuffer
_0803AD7C: .4byte 0xFFFFFE00
_0803AD80: .4byte 0x000001FF
_0803AD84: .4byte 0x00000456
_0803AD88: .4byte 0x0000132C
_0803AD8C: .4byte gUnknown_086AEE20
_0803AD90: .4byte 0x00000445
_0803AD94: .4byte 0x00000454
_0803AD98: .4byte 0x00000E78
_0803AD9C: .4byte 0x00001438

	thumb_func_start sub_3ADA0
sub_3ADA0: @ 0x0803ADA0
	push {r4, r5, r6, r7, lr}
	ldr r6, _0803AE04 @ =gMain+0x1438 @gMain.spriteGroups[24]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0803ADFE
	movs r0, #0xf0
	strh r0, [r6, #2]
	movs r0, #0xa0
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0803AE08 @ =gOamBuffer
	ldr r1, _0803AE0C @ =0xFFFFFE00
	mov ip, r1
_0803ADBA:
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
	ldr r2, _0803AE10 @ =0x000001FF
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
	ble _0803ADBA
_0803ADFE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AE04: .4byte gMain+0x1438 @gMain.spriteGroups[24]
_0803AE08: .4byte gOamBuffer
_0803AE0C: .4byte 0xFFFFFE00
_0803AE10: .4byte 0x000001FF

	thumb_func_start sub_3AE14
sub_3AE14: @ 0x0803AE14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0803AE80 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r1, #0x13
	ldrsb r1, [r5, r1]
	cmp r1, #0
	bne _0803AEA8
	ldrh r1, [r5, #0x18]
	ldr r0, _0803AE84 @ =0x00000257
	cmp r1, r0
	bhi _0803AEA8
	ldr r4, _0803AE88 @ =gUnknown_086AEF04
	adds r0, r1, #0
	movs r1, #0xf0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r4
	ldr r1, _0803AE8C @ =0x040000D4
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #5
	ldr r0, _0803AE90 @ =gUnknown_083529D8
	adds r0, r2, r0
	str r0, [r1]
	ldr r0, _0803AE94 @ =0x05000340
	str r0, [r1, #4]
	ldr r3, _0803AE98 @ =0x80000010
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0803AE9C @ =gUnknown_0833FF58
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, _0803AEA0 @ =0x050002A0
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	movs r6, #2
	ldr r0, _0803AEA4 @ =0x0000044C
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _0803AED2
	.align 2, 0
_0803AE80: .4byte gCurrentPinballGame
_0803AE84: .4byte 0x00000257
_0803AE88: .4byte gUnknown_086AEF04
_0803AE8C: .4byte 0x040000D4
_0803AE90: .4byte gUnknown_083529D8
_0803AE94: .4byte 0x05000340
_0803AE98: .4byte 0x80000010
_0803AE9C: .4byte gUnknown_0833FF58
_0803AEA0: .4byte 0x050002A0
_0803AEA4: .4byte 0x0000044C
_0803AEA8:
	ldr r6, _0803B0C4 @ =gUnknown_086AEEE6
	ldr r1, _0803B0C8 @ =gCurrentPinballGame
	ldr r5, [r1]
	ldr r2, _0803B0CC @ =0x0000044C
	adds r5, r5, r2
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #0x60
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	ldrh r6, [r0]
	adds r4, #1
	strh r4, [r5]
_0803AED2:
	ldr r4, _0803B0D0 @ =gUnknown_086AEED6
	ldr r3, _0803B0C8 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldr r3, _0803B0D4 @ =gUnknown_03006C00
	mov r8, r3
	ldr r1, _0803B0D8 @ =gUnknown_086AEEDE
	mov sl, r1
	lsls r6, r6, #0x10
	mov sb, r6
	ldr r7, _0803B0DC @ =0xFFFFF000
	add r7, r8
	ldr r6, _0803B0E0 @ =gUnknown_08333004
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r3, r0, #2
	ldr r5, _0803B0E4 @ =0x000003FF
	movs r4, #0x80
	lsls r4, r4, #4
_0803AF10:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r4
	lsls r2, r2, #1
	adds r2, r2, r7
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r5
	ble _0803AF10
	ldr r4, _0803B0E8 @ =0x040000D4
	mov r0, r8
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0803B0EC @ =0x80000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0803B0F0 @ =gMain
	ldr r0, [r1, #0x4c]
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	add r0, sl
	ldr r2, _0803B0C8 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0803B0F4 @ =0x00000382
	adds r1, r1, r3
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r2, r2, #2
	ldr r1, _0803B0F8 @ =gUnknown_086AEAE0
	adds r2, r2, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #5
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0803B0FC @ =0x05000060
	str r0, [r4, #4]
	ldr r0, _0803B100 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r3, #0
	ldr r7, _0803B104 @ =gOamBuffer
	mov r0, sb
	asrs r0, r0, #0xd
	mov r8, r0
	ldr r1, _0803B108 @ =gUnknown_086AEEFE
	mov sb, r1
	ldr r2, _0803B10C @ =0xFFFFFC00
	mov sl, r2
_0803AF90:
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r1, _0803B110 @ =gMain+0xAE0 @gMain.spriteGroups[11]
	adds r6, r0, r1
	ldr r2, _0803B0C8 @ =gCurrentPinballGame
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x78
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0x80
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	mov ip, r3
_0803AFBA:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0803B114 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0803B118 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r2, [r5, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r0, r4, #1
	add r0, sb
	ldrh r1, [r0]
	add r1, r8
	ldr r3, _0803B0E4 @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #2
	ble _0803AFBA
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0803AF90
	ldr r6, _0803B11C @ =gMain+0xDC0 @gMain.spriteGroups[15]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0803B0B4
	ldr r1, _0803B0C8 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r2, _0803B0C8 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	ldr r7, _0803B104 @ =gOamBuffer
	ldr r3, _0803B118 @ =0xFFFFFE00
	mov r8, r3
_0803B056:
	lsls r4, r2, #0x10
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
	ldr r2, _0803B114 @ =0x000001FF
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
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #7
	ble _0803B056
	ldr r3, _0803B0C8 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldrh r1, [r0, #0x18]
	movs r0, #0xf0
	lsls r0, r0, #1
	cmp r1, r0
	bne _0803B0B4
	ldr r0, _0803B0F0 @ =gMain
	movs r2, #0xdc
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r0, #0
	strh r0, [r1]
_0803B0B4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B0C4: .4byte gUnknown_086AEEE6
_0803B0C8: .4byte gCurrentPinballGame
_0803B0CC: .4byte 0x0000044C
_0803B0D0: .4byte gUnknown_086AEED6
_0803B0D4: .4byte gUnknown_03006C00
_0803B0D8: .4byte gUnknown_086AEEDE
_0803B0DC: .4byte 0xFFFFF000
_0803B0E0: .4byte gUnknown_08333004
_0803B0E4: .4byte 0x000003FF
_0803B0E8: .4byte 0x040000D4
_0803B0EC: .4byte 0x80000400
_0803B0F0: .4byte gMain
_0803B0F4: .4byte 0x00000382
_0803B0F8: .4byte gUnknown_086AEAE0
_0803B0FC: .4byte 0x05000060
_0803B100: .4byte 0x80000010
_0803B104: .4byte gOamBuffer
_0803B108: .4byte gUnknown_086AEEFE
_0803B10C: .4byte 0xFFFFFC00
_0803B110: .4byte gMain+0xAE0 @gMain.spriteGroups[11]
_0803B114: .4byte 0x000001FF
_0803B118: .4byte 0xFFFFFE00
_0803B11C: .4byte gMain+0xDC0 @gMain.spriteGroups[15]

	thumb_func_start sub_3B120
sub_3B120: @ 0x0803B120
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0803B158 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	strb r2, [r1, #0x17]
	ldr r0, [r4]
	strb r2, [r0, #0x13]
	ldr r5, [r4]
	ldr r1, _0803B15C @ =0x00000283
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r4
	cmp r0, #3
	bne _0803B160
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0x12
	b _0803B168
	.align 2, 0
_0803B158: .4byte gCurrentPinballGame
_0803B15C: .4byte 0x00000283
_0803B160:
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0xf
_0803B168:
	strb r0, [r1]
	mov r4, ip
	ldr r0, [r4]
	movs r5, #0xa5
	lsls r5, r5, #2
	adds r0, r0, r5
	movs r3, #0
	strb r3, [r0]
	ldr r1, [r4]
	adds r5, r1, #0
	adds r5, #0x6c
	ldr r6, _0803B42C @ =0x00002A30
	adds r0, r6, #0
	ldrh r2, [r5]
	adds r0, r0, r2
	ldr r4, _0803B430 @ =0x00000296
	adds r2, r1, r4
	movs r4, #0
	strh r0, [r2]
	strh r3, [r5]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r1, r1, r5
	movs r2, #3
	strb r2, [r1]
	mov r6, ip
	ldr r0, [r6]
	adds r5, #0xa
	adds r1, r0, r5
	strh r3, [r1]
	ldr r6, _0803B434 @ =0x0000132C
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #1
	strb r1, [r0]
	mov r5, ip
	ldr r0, [r5]
	ldr r6, _0803B438 @ =0x00000386
	adds r0, r0, r6
	strb r4, [r0]
	ldr r0, [r5]
	ldr r5, _0803B43C @ =0x00000387
	adds r0, r0, r5
	strb r1, [r0]
	mov r6, ip
	ldr r0, [r6]
	ldr r1, _0803B440 @ =0x000006C4
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	ldr r2, _0803B444 @ =0x00000382
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	subs r5, #4
	adds r0, r0, r5
	strb r4, [r0]
	ldr r0, [r6]
	ldr r6, _0803B448 @ =0x00000385
	adds r0, r0, r6
	strb r4, [r0]
	mov r1, ip
	ldr r0, [r1]
	adds r2, #7
	adds r0, r0, r2
	strb r4, [r0]
	ldr r1, [r1]
	adds r5, #0xb
	adds r0, r1, r5
	strh r3, [r0]
	adds r6, #0xb
	adds r0, r1, r6
	strh r3, [r0]
	adds r2, #0xb
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #0x4e
	adds r0, r1, r5
	strb r4, [r0]
	mov r6, ip
	ldr r0, [r6]
	ldr r1, _0803B44C @ =0x000003DD
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r2, #0x4a
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	adds r5, #3
	adds r0, r0, r5
	strb r4, [r0]
	ldr r0, [r6]
	movs r6, #0xf8
	lsls r6, r6, #2
	adds r0, r0, r6
	strb r4, [r0]
	mov r1, ip
	ldr r0, [r1]
	adds r2, #4
	adds r1, r0, r2
	strh r3, [r1]
	adds r5, #2
	adds r0, r0, r5
	strb r4, [r0]
	mov r6, ip
	ldr r1, [r6]
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #5
	adds r0, r1, r5
	strh r3, [r0]
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r0, r1, r6
	strh r3, [r0]
	adds r2, #6
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #6
	adds r0, r1, r5
	strh r3, [r0]
	adds r6, #6
	adds r0, r1, r6
	strh r3, [r0]
	adds r2, #6
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #6
	adds r0, r1, r5
	strh r3, [r0]
	adds r6, #0x64
	adds r0, r1, r6
	strh r3, [r0]
	adds r2, #0x66
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #0x8a
	adds r1, r1, r5
	strb r4, [r1]
	mov r6, ip
	ldr r0, [r6]
	ldr r1, _0803B450 @ =0x0000047D
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	adds r2, #0x28
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	adds r5, #3
	adds r0, r0, r5
	strb r4, [r0]
	ldr r0, [r6]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r0, r6
	strh r3, [r1]
	adds r2, #4
	adds r1, r0, r2
	strh r3, [r1]
	adds r5, #5
	adds r1, r0, r5
	strh r3, [r1]
	adds r6, #6
	adds r1, r0, r6
	strh r3, [r1]
	adds r2, #6
	adds r1, r0, r2
	strh r3, [r1]
	adds r5, #6
	adds r1, r0, r5
	strh r3, [r1]
	adds r6, #0x3e
	adds r1, r0, r6
	strh r3, [r1]
	adds r2, #0x3e
	adds r1, r0, r2
	strh r3, [r1]
	adds r5, #0x3e
	adds r0, r0, r5
	strb r4, [r0]
	mov r6, ip
	ldr r0, [r6]
	adds r2, #4
	adds r1, r0, r2
	strh r3, [r1]
	ldr r3, _0803B454 @ =0x000004C9
	adds r0, r0, r3
	strb r4, [r0]
	movs r1, #0
	mov r5, ip
	movs r6, #0
	movs r7, #0
_0803B2EE:
	ldr r3, [r5]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r4, r2, #2
	adds r1, r3, r4
	ldr r0, _0803B458 @ =0x0000046C
	strh r7, [r0, r1]
	adds r0, #2
	adds r1, r1, r0
	strh r7, [r1]
	ldr r1, _0803B45C @ =0x0000048C
	adds r3, r3, r1
	adds r3, r3, r2
	strb r6, [r3]
	ldr r0, [r5]
	movs r3, #0x92
	lsls r3, r3, #3
	adds r0, r0, r3
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r3, #8
	adds r0, r0, r3
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r3, #8
	adds r0, r0, r3
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	strb r6, [r0]
	ldr r1, [r5]
	lsls r3, r2, #1
	mov r8, r3
	ldr r3, _0803B460 @ =0x000004AC
	adds r0, r1, r3
	add r0, r8
	strh r7, [r0]
	adds r1, r1, r4
	ldr r4, _0803B464 @ =0x000004B4
	adds r0, r1, r4
	strh r7, [r0]
	ldr r0, _0803B468 @ =0x000004B6
	adds r1, r1, r0
	strh r7, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _0803B2EE
	movs r1, #0
	ldr r5, _0803B46C @ =gCurrentPinballGame
	movs r4, #0
_0803B376:
	ldr r0, [r5]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	ldr r1, _0803B470 @ =0x000004CC
	adds r0, r0, r1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r3, _0803B474 @ =0x000004CF
	adds r0, r0, r3
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r6, _0803B478 @ =0x000004D2
	adds r0, r0, r6
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #9
	adds r0, r0, r1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r1, [r5]
	lsls r3, r2, #1
	adds r6, #6
	adds r0, r1, r6
	adds r0, r0, r3
	strh r4, [r0]
	adds r6, #6
	adds r0, r1, r6
	adds r0, r0, r3
	strh r4, [r0]
	adds r6, #6
	adds r0, r1, r6
	adds r0, r0, r3
	strh r4, [r0]
	lsls r0, r2, #2
	adds r1, r1, r0
	ldr r3, _0803B47C @ =0x000004EC
	adds r0, r1, r3
	strh r4, [r0]
	adds r6, #0xa
	adds r0, r1, r6
	strh r4, [r0]
	adds r3, #0xc
	adds r0, r1, r3
	strh r4, [r0]
	adds r6, #0xc
	adds r1, r1, r6
	strh r4, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #2
	ble _0803B376
	mov r0, ip
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x1a]
	bl sub_3CBC4
	bl sub_3B7C4
	bl sub_3C6E0
	ldr r4, _0803B480 @ =0x040000D4
	ldr r0, _0803B484 @ =gUnknown_0849F1CC
	str r0, [r4]
	ldr r0, _0803B488 @ =0x06015800
	str r0, [r4, #4]
	ldr r0, _0803B48C @ =0x80001000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_3E644
	movs r0, MUS_BONUS_FIELD_GROUDON
	bl m4aSongNumStart
	ldr r0, _0803B490 @ =gUnknown_081B36A4
	str r0, [r4]
	ldr r0, _0803B494 @ =0x05000320
	str r0, [r4, #4]
	ldr r0, _0803B498 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B42C: .4byte 0x00002A30
_0803B430: .4byte 0x00000296
_0803B434: .4byte 0x0000132C
_0803B438: .4byte 0x00000386
_0803B43C: .4byte 0x00000387
_0803B440: .4byte 0x000006C4
_0803B444: .4byte 0x00000382
_0803B448: .4byte 0x00000385
_0803B44C: .4byte 0x000003DD
_0803B450: .4byte 0x0000047D
_0803B454: .4byte 0x000004C9
_0803B458: .4byte 0x0000046C
_0803B45C: .4byte 0x0000048C
_0803B460: .4byte 0x000004AC
_0803B464: .4byte 0x000004B4
_0803B468: .4byte 0x000004B6
_0803B46C: .4byte gCurrentPinballGame
_0803B470: .4byte 0x000004CC
_0803B474: .4byte 0x000004CF
_0803B478: .4byte 0x000004D2
_0803B47C: .4byte 0x000004EC
_0803B480: .4byte 0x040000D4
_0803B484: .4byte gUnknown_0849F1CC
_0803B488: .4byte 0x06015800
_0803B48C: .4byte 0x80001000
_0803B490: .4byte gUnknown_081B36A4
_0803B494: .4byte 0x05000320
_0803B498: .4byte 0x80000010

	thumb_func_start sub_3B49C
sub_3B49C: @ 0x0803B49C
	push {r4, r5, r6, lr}
	ldr r0, _0803B4B8 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bls _0803B4AE
	b _0803B740
_0803B4AE:
	lsls r0, r0, #2
	ldr r1, _0803B4BC @ =_0803B4C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B4B8: .4byte gCurrentPinballGame
_0803B4BC: .4byte _0803B4C0
_0803B4C0: @ jump table
	.4byte _0803B4DC @ case 0
	.4byte _0803B740 @ case 1
	.4byte _0803B576 @ case 2
	.4byte _0803B5EC @ case 3
	.4byte _0803B66C @ case 4
	.4byte _0803B6C8 @ case 5
	.4byte _0803B728 @ case 6
_0803B4DC:
	ldr r5, _0803B504 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r1, _0803B508 @ =0x000005F7
	adds r0, r0, r1
	movs r2, #0
	movs r6, #1
	strb r6, [r0]
	ldr r4, [r5]
	ldrh r1, [r4, #0x18]
	ldr r0, _0803B50C @ =0x000001F3
	cmp r1, r0
	bhi _0803B514
	adds r1, r4, #0
	adds r1, #0xe6
	ldr r0, _0803B510 @ =0x0000FFC0
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	b _0803B740
	.align 2, 0
_0803B504: .4byte gCurrentPinballGame
_0803B508: .4byte 0x000005F7
_0803B50C: .4byte 0x000001F3
_0803B510: .4byte 0x0000FFC0
_0803B514:
	ldr r0, _0803B55C @ =0x00000333
	cmp r1, r0
	bhi _0803B568
	ldrh r0, [r4, #0x18]
	ldr r2, _0803B560 @ =0xFFFFFE0C
	adds r0, r0, r2
	movs r1, #5
	bl __divsi3
	subs r0, #0x40
	adds r1, r4, #0
	adds r1, #0xe6
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0803B544
	movs r0, #0
	strb r0, [r4, #0x1a]
_0803B544:
	ldr r2, [r5]
	ldrh r1, [r2, #0x18]
	ldr r0, _0803B564 @ =0x0000028A
	cmp r1, r0
	beq _0803B550
	b _0803B740
_0803B550:
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r6, [r0]
	b _0803B740
	.align 2, 0
_0803B55C: .4byte 0x00000333
_0803B560: .4byte 0xFFFFFE0C
_0803B564: .4byte 0x0000028A
_0803B568:
	adds r0, r4, #0
	adds r0, #0xe6
	strh r2, [r0]
	strb r6, [r4, #0x13]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
	b _0803B740
_0803B576:
	ldr r2, _0803B588 @ =gCurrentPinballGame
	ldr r3, [r2]
	ldrh r0, [r3, #0x18]
	cmp r0, #0x77
	bhi _0803B58C
	adds r0, #1
	strh r0, [r3, #0x18]
	b _0803B740
	.align 2, 0
_0803B588: .4byte gCurrentPinballGame
_0803B58C:
	movs r1, #0
	movs r0, #3
	strb r0, [r3, #0x13]
	ldr r2, [r2]
	strh r1, [r2, #0x18]
	ldr r3, _0803B5D4 @ =gMain
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
	ldr r1, _0803B5D8 @ =0x040000D4
	ldr r0, _0803B5DC @ =gUnknown_0813E894
	str r0, [r1]
	ldr r0, _0803B5E0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0803B5E4 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x88
	strh r0, [r1]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	ldr r1, _0803B5E8 @ =0x000005FA
	adds r2, r2, r1
	strb r4, [r2]
	b _0803B740
	.align 2, 0
_0803B5D4: .4byte gMain
_0803B5D8: .4byte 0x040000D4
_0803B5DC: .4byte gUnknown_0813E894
_0803B5E0: .4byte 0x06015800
_0803B5E4: .4byte 0x80001000
_0803B5E8: .4byte 0x000005FA
_0803B5EC:
	bl sub_351A8
	ldr r4, _0803B634 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0803B5FE
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0803B5FE:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0803B614
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r4]
	ldr r0, _0803B638 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _0803B63C @ =gUnknown_02FAF080
	str r0, [r1, #0x3c]
_0803B614:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _0803B640
	cmp r0, #0x14
	bne _0803B62A
	bl m4aMPlayAllStop
	movs r0, MUS_SUCCESS3
	bl m4aSongNumStart
_0803B62A:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _0803B654
	.align 2, 0
_0803B634: .4byte gCurrentPinballGame
_0803B638: .4byte 0x00061A80
_0803B63C: .4byte gUnknown_02FAF080
_0803B640:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r4]
	ldr r2, _0803B660 @ =0x00000283
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803B654:
	ldr r0, _0803B664 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r4, _0803B668 @ =0x000005FA
	adds r0, r0, r4
	movs r1, #1
	b _0803B73E
	.align 2, 0
_0803B660: .4byte 0x00000283
_0803B664: .4byte gCurrentPinballGame
_0803B668: .4byte 0x000005FA
_0803B66C:
	ldr r2, _0803B6B0 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r0, #5
	strb r0, [r1, #0x13]
	ldr r2, [r2]
	movs r0, #0x8c
	strh r0, [r2, #0x18]
	ldr r3, _0803B6B4 @ =gMain
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #1
	strh r1, [r0]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r3, r4
	strh r1, [r0]
	ldr r1, _0803B6B8 @ =0x040000D4
	ldr r0, _0803B6BC @ =gUnknown_0813E894
	str r0, [r1]
	ldr r0, _0803B6C0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0803B6C4 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r0, #0x88
	strh r0, [r2]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	b _0803B740
	.align 2, 0
_0803B6B0: .4byte gCurrentPinballGame
_0803B6B4: .4byte gMain
_0803B6B8: .4byte 0x040000D4
_0803B6BC: .4byte gUnknown_0813E894
_0803B6C0: .4byte 0x06015800
_0803B6C4: .4byte 0x80001000
_0803B6C8:
	bl sub_351A8
	ldr r2, _0803B700 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0803B6DA
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0803B6DA:
	ldr r1, [r2]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0803B6F0
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r2]
	ldr r0, _0803B704 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _0803B708 @ =gUnknown_02FAF080
	str r0, [r1, #0x3c]
_0803B6F0:
	ldr r1, [r2]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _0803B70C
	adds r0, #1
	strh r0, [r1, #0x18]
	b _0803B740
	.align 2, 0
_0803B700: .4byte gCurrentPinballGame
_0803B704: .4byte 0x00061A80
_0803B708: .4byte gUnknown_02FAF080
_0803B70C:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r2]
	ldr r0, _0803B724 @ =0x00000283
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803B740
	.align 2, 0
_0803B724: .4byte 0x00000283
_0803B728:
	bl sub_351A8
	ldr r2, _0803B7B0 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _0803B7B4 @ =0x00000386
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0803B7B8 @ =0x000005FA
	adds r0, r0, r2
_0803B73E:
	strb r1, [r0]
_0803B740:
	bl sub_3CBC4
	bl sub_3B7C4
	bl sub_3C6E0
	bl sub_3E644
	ldr r0, _0803B7B0 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r4, #0xa5
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803B788
	ldr r5, _0803B7BC @ =0x00000296
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #1
	bhi _0803B788
	ldr r4, _0803B7C0 @ =gMain
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0803B788
	bl m4aMPlayAllStop
	movs r0, MUS_END_OF_BALL3
	bl m4aSongNumStart
	ldrb r1, [r4, #0xf]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xf]
_0803B788:
	ldr r0, _0803B7B0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803B7B4 @ =0x00000386
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803B7A6
	ldr r4, _0803B7B8 @ =0x000005FA
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	bl sub_350F0
_0803B7A6:
	bl sub_472E4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B7B0: .4byte gCurrentPinballGame
_0803B7B4: .4byte 0x00000386
_0803B7B8: .4byte 0x000005FA
_0803B7BC: .4byte 0x00000296
_0803B7C0: .4byte gMain

	thumb_func_start sub_3B7C4
sub_3B7C4: @ 0x0803B7C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0803B874 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803B878 @ =0x00000452
	adds r4, r1, r2
	ldrh r3, [r4]
	mov r8, r0
	cmp r3, #0
	beq _0803B850
	subs r0, r3, #1
	strh r0, [r4]
	ldr r3, _0803B87C @ =0x00000389
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	mov r4, r8
	ldr r0, [r4]
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0x23
	bne _0803B838
	ldr r0, _0803B880 @ =gMPlayInfo_SE1
	ldr r1, _0803B884 @ =gUnknown_086A22D8
	bl MPlayStart
	ldr r1, [r4]
	ldr r0, _0803B888 @ =0x0007A120
	str r0, [r1, #0x3c]
	movs r0, #7
	bl sub_11B0
	ldr r1, [r4]
	ldr r2, _0803B88C @ =0x00000385
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, [r4]
	adds r2, r3, r2
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _0803B838
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #6
	strb r0, [r1]
_0803B838:
	ldr r0, _0803B874 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r4, _0803B878 @ =0x00000452
	adds r1, r3, r4
	ldrh r1, [r1]
	mov r8, r0
	cmp r1, #0x1e
	bhi _0803B850
	ldr r0, _0803B87C @ =0x00000389
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
_0803B850:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bls _0803B868
	bl _0803C476
_0803B868:
	lsls r0, r0, #2
	ldr r1, _0803B890 @ =_0803B894
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B874: .4byte gCurrentPinballGame
_0803B878: .4byte 0x00000452
_0803B87C: .4byte 0x00000389
_0803B880: .4byte gMPlayInfo_SE1
_0803B884: .4byte gUnknown_086A22D8
_0803B888: .4byte 0x0007A120
_0803B88C: .4byte 0x00000385
_0803B890: .4byte _0803B894
_0803B894: @ jump table
	.4byte _0803B8C0 @ case 0
	.4byte _0803B91C @ case 1
	.4byte _0803BB2C @ case 2
	.4byte _0803BC74 @ case 3
	.4byte _0803BEF8 @ case 4
	.4byte _0803BFD4 @ case 5
	.4byte _0803C098 @ case 6
	.4byte _0803C1BC @ case 7
	.4byte _0803C26C @ case 8
	.4byte _0803C3C0 @ case 9
	.4byte _0803C476 @ case 10
_0803B8C0:
	ldr r3, _0803B904 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r3]
	ldr r0, _0803B908 @ =0x000003E2
	adds r2, r1, r0
	movs r5, #0
	movs r0, #0x16
	strh r0, [r2]
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r0, _0803B90C @ =0x000003E1
	adds r1, r1, r0
	strb r5, [r1]
	ldr r1, [r3]
	adds r2, #4
	adds r0, r1, r2
	strh r4, [r0]
	ldr r3, _0803B910 @ =0x000003EA
	adds r2, r1, r3
	ldr r0, _0803B914 @ =0x0000FB50
	strh r0, [r2]
	ldr r0, _0803B918 @ =0x000004C6
	adds r1, r1, r0
	strh r4, [r1]
	bl _0803C476
	.align 2, 0
_0803B904: .4byte gCurrentPinballGame
_0803B908: .4byte 0x000003E2
_0803B90C: .4byte 0x000003E1
_0803B910: .4byte 0x000003EA
_0803B914: .4byte 0x0000FB50
_0803B918: .4byte 0x000004C6
_0803B91C:
	ldr r0, _0803B944 @ =gUnknown_086AF140
	mov r1, r8
	ldr r5, [r1]
	ldr r2, _0803B948 @ =0x000003E2
	adds r4, r5, r2
	movs r3, #0
	ldrsh r1, [r4, r3]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0xf9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0803B94C
	adds r0, r3, #1
	strh r0, [r2]
	b _0803B99E
	.align 2, 0
_0803B944: .4byte gUnknown_086AF140
_0803B948: .4byte 0x000003E2
_0803B94C:
	movs r3, #0
	strh r3, [r2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x24
	bne _0803B99E
	ldr r2, _0803B978 @ =0x000003E1
	adds r1, r5, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x11
	bgt _0803B97C
	movs r0, #0x22
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803B99E
	.align 2, 0
_0803B978: .4byte 0x000003E1
_0803B97C:
	strh r3, [r4]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _0803BAF8 @ =0x000003DD
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _0803BAFC @ =0x000003E1
	adds r0, r0, r2
	movs r1, #9
	strb r1, [r0]
_0803B99E:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r3, _0803BB04 @ =0x000003E2
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x16
	beq _0803B9B0
	b _0803BABA
_0803B9B0:
	adds r3, #2
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _0803BB08 @ =0x000001F3
	cmp r1, r0
	bhi _0803BA54
	cmp r1, #0x32
	beq _0803B9C6
	subs r0, #0xe5
	cmp r1, r0
	bne _0803B9E8
_0803B9C6:
	ldr r0, _0803BB0C @ =0x000004CA
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	ldrh r0, [r2]
	movs r1, #0x6e
	bl __udivsi3
	ldr r2, _0803BB10 @ =0x000004C9
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0803BB14 @ =0x00000119
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0803B9E8:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r1, [r2]
	cmp r1, #0xa0
	beq _0803BA00
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r1, r0
	bne _0803BA22
_0803BA00:
	ldr r0, _0803BB0C @ =0x000004CA
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	ldrh r0, [r2]
	movs r1, #0x6e
	bl __udivsi3
	ldr r2, _0803BB10 @ =0x000004C9
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0803BB14 @ =0x00000119
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0803BA22:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xf5
	lsls r0, r0, #1
	cmp r1, r0
	bne _0803BA54
	ldr r4, _0803BB0C @ =0x000004CA
	adds r1, r2, r4
	movs r0, #0x1f
	strh r0, [r1]
	ldr r0, _0803BB10 @ =0x000004C9
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	movs r0, #0x8d
	lsls r0, r0, #1
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0803BA54:
	ldr r2, _0803BB00 @ =gCurrentPinballGame
	ldr r3, [r2]
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _0803BB18 @ =0x00000275
	mov r8, r2
	cmp r1, r0
	bls _0803BA8E
	ldr r4, _0803BB1C @ =0x000003EA
	adds r2, r3, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _0803BA9E
	adds r4, #0xdc
	adds r0, r3, r4
	ldrh r1, [r0]
	adds r1, #4
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0803BA8E
	movs r0, #0
	strh r0, [r2]
_0803BA8E:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803BB1C @ =0x000003EA
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0803BABA
_0803BA9E:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r0, r4
	movs r1, #0x3c
	strb r1, [r0]
	ldr r0, _0803BB20 @ =gMPlayInfo_SE1
	ldr r1, _0803BB24 @ =gUnknown_086A2454
	bl MPlayStart
	movs r0, #0xd
	bl sub_11B0
_0803BABA:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803BB04 @ =0x000003E2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x21
	bne _0803BAE0
	movs r4, #0xf9
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803BAE0
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0x29
	strh r0, [r1]
_0803BAE0:
	ldr r0, _0803BB00 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0803BB28 @ =0x00000392
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0x78
	bhi _0803BAF2
	bl _0803C476
_0803BAF2:
	subs r0, #1
	bl _0803C474
	.align 2, 0
_0803BAF8: .4byte 0x000003DD
_0803BAFC: .4byte 0x000003E1
_0803BB00: .4byte gCurrentPinballGame
_0803BB04: .4byte 0x000003E2
_0803BB08: .4byte 0x000001F3
_0803BB0C: .4byte 0x000004CA
_0803BB10: .4byte 0x000004C9
_0803BB14: .4byte 0x00000119
_0803BB18: .4byte 0x00000275
_0803BB1C: .4byte 0x000003EA
_0803BB20: .4byte gMPlayInfo_SE1
_0803BB24: .4byte gUnknown_086A2454
_0803BB28: .4byte 0x00000392
_0803BB2C:
	mov r3, r8
	ldr r4, [r3]
	ldr r1, _0803BB50 @ =0x00000452
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bls _0803BB58
	ldr r2, _0803BB54 @ =0x000003E2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0x15
	strh r0, [r1]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	bl _0803C476
	.align 2, 0
_0803BB50: .4byte 0x00000452
_0803BB54: .4byte 0x000003E2
_0803BB58:
	ldr r0, _0803BB7C @ =gUnknown_086AF140
	ldr r1, _0803BB80 @ =0x000003E2
	adds r3, r4, r1
	movs r2, #0
	ldrsh r1, [r3, r2]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0xf9
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r5, [r2]
	ldrh r0, [r1]
	cmp r0, r5
	bls _0803BB84
	adds r0, r5, #1
	strh r0, [r2]
	b _0803BC50
	.align 2, 0
_0803BB7C: .4byte gUnknown_086AF140
_0803BB80: .4byte 0x000003E2
_0803BB84:
	movs r6, #0
	movs r5, #0
	strh r5, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne _0803BC50
	ldr r2, _0803BBF4 @ =0x000003E1
	adds r1, r4, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	bgt _0803BC00
	strh r5, [r3]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0803BBF4 @ =0x000003E1
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _0803BC50
	ldr r4, _0803BBF8 @ =0x000003DD
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0803BC50
	movs r3, #0
	ldr r5, _0803BBFC @ =0x0000048C
	movs r4, #9
_0803BBD2:
	ldr r0, [r2]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r5
	adds r3, r0, r1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #8
	bgt _0803BBE6
	strb r4, [r3]
_0803BBE6:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0803BBD2
	b _0803BC50
	.align 2, 0
_0803BBF4: .4byte 0x000003E1
_0803BBF8: .4byte 0x000003DD
_0803BBFC: .4byte 0x0000048C
_0803BC00:
	ldr r1, _0803BC20 @ =0x000003DD
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #4
	bne _0803BC24
	movs r0, #0x24
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	b _0803BC4C
	.align 2, 0
_0803BC20: .4byte 0x000003DD
_0803BC24:
	cmp r1, #3
	bne _0803BC3A
	movs r0, #0x4c
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	b _0803BC4C
_0803BC3A:
	movs r0, #0x3a
	strh r0, [r3]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #5
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
_0803BC4C:
	adds r0, r0, r2
	strb r6, [r0]
_0803BC50:
	ldr r0, _0803BC6C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r2, _0803BC70 @ =0x000003E2
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x15
	beq _0803BC64
	bl _0803C476
_0803BC64:
	movs r0, #0
	bl _0803C474
	.align 2, 0
_0803BC6C: .4byte gCurrentPinballGame
_0803BC70: .4byte 0x000003E2
_0803BC74:
	ldr r1, _0803BCA0 @ =gUnknown_086AF140
	mov r4, r8
	ldr r2, [r4]
	ldr r0, _0803BCA4 @ =0x000003E2
	adds r3, r2, r0
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _0803BCA8
	adds r0, r1, #1
	strh r0, [r2]
	bl _0803C476
	.align 2, 0
_0803BCA0: .4byte gUnknown_086AF140
_0803BCA4: .4byte 0x000003E2
_0803BCA8:
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x5d
	beq _0803BCC2
	cmp r0, #0x60
	beq _0803BCC2
	cmp r0, #0x63
	bne _0803BD1E
_0803BCC2:
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0803BCF4 @ =0x000003E2
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r1, r1, r4
	movs r0, #2
	strb r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	ldr r1, _0803BCF8 @ =0x0000047C
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803BCFC
	subs r3, #5
	adds r1, r2, r3
	movs r0, #4
	b _0803BD02
	.align 2, 0
_0803BCF4: .4byte 0x000003E2
_0803BCF8: .4byte 0x0000047C
_0803BCFC:
	ldr r3, _0803BDF8 @ =0x000003DD
	adds r1, r2, r3
	movs r0, #5
_0803BD02:
	strb r0, [r1]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _0803BDFC @ =0x000003E1
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0803BE00 @ =0x0000047C
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803BD1E:
	ldr r5, _0803BE04 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _0803BE08 @ =0x000003E2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x5a
	beq _0803BD30
	b _0803C476
_0803BD30:
	ldr r0, _0803BE0C @ =gMPlayInfo_SE1
	ldr r1, _0803BE10 @ =gUnknown_086A24F0
	bl MPlayStart
	ldr r0, [r5]
	ldr r2, _0803BE14 @ =0x0000047E
	adds r0, r0, r2
	movs r1, #8
	strb r1, [r0]
	ldr r4, [r5]
	ldr r3, _0803BE18 @ =0x00000482
	adds r1, r4, r3
	movs r0, #0
	mov sb, r0
	movs r0, #0x23
	strh r0, [r1]
	ldr r1, _0803BE1C @ =gMain
	mov sl, r1
	ldr r1, _0803BE20 @ =0x000012C8
	add r1, sl
	movs r0, #1
	strh r0, [r1]
	adds r2, #0xa
	mov r8, r2
	adds r2, r4, r2
	movs r0, #0x96
	lsls r0, r0, #3
	strh r0, [r2]
	adds r3, #8
	adds r1, r4, r3
	adds r0, #0x28
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, _0803BE24 @ =0x0000132C
	adds r4, r4, r2
	ldr r2, [r4]
	movs r3, #0x10
	ldrsh r1, [r2, r3]
	subs r6, r0, r1
	movs r1, #0x7c
	movs r4, #0x12
	ldrsh r0, [r2, r4]
	subs r7, r1, r0
	rsbs r0, r6, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	ldr r1, [r5]
	ldr r6, _0803BE28 @ =0x00000484
	adds r2, r1, r6
	strh r0, [r2]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0803BDE0
	bl Random
	ldr r4, [r5]
	mov r2, sl
	ldr r1, [r2, #0x4c]
	muls r0, r1, r0
	movs r1, #0x64
	bl __umodsi3
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #0xc
	movs r1, #0x64
	bl __udivsi3
	movs r3, #0x98
	lsls r3, r3, #8
	adds r0, r0, r3
	adds r4, r4, r6
	strh r0, [r4]
_0803BDE0:
	ldr r1, [r5]
	adds r3, r1, r6
	ldrh r2, [r3]
	ldr r0, _0803BE2C @ =0x00003FFF
	cmp r2, r0
	bhi _0803BE34
	movs r0, #0xe8
	lsls r0, r0, #8
	strh r0, [r3]
	ldr r4, _0803BE30 @ =0x0000047D
	adds r1, r1, r4
	b _0803BEB6
	.align 2, 0
_0803BDF8: .4byte 0x000003DD
_0803BDFC: .4byte 0x000003E1
_0803BE00: .4byte 0x0000047C
_0803BE04: .4byte gCurrentPinballGame
_0803BE08: .4byte 0x000003E2
_0803BE0C: .4byte gMPlayInfo_SE1
_0803BE10: .4byte gUnknown_086A24F0
_0803BE14: .4byte 0x0000047E
_0803BE18: .4byte 0x00000482
_0803BE1C: .4byte gMain
_0803BE20: .4byte 0x000012C8
_0803BE24: .4byte 0x0000132C
_0803BE28: .4byte 0x00000484
_0803BE2C: .4byte 0x00003FFF
_0803BE30: .4byte 0x0000047D
_0803BE34:
	ldr r0, _0803BE50 @ =0x000097FF
	cmp r2, r0
	bhi _0803BE5C
	adds r0, #1
	strh r0, [r3]
	ldr r2, _0803BE54 @ =0x0000047D
	adds r0, r1, r2
	movs r3, #1
	strb r3, [r0]
	ldr r0, [r5]
	add r0, r8
	ldr r1, _0803BE58 @ =0x00000424
	b _0803BEC0
	.align 2, 0
_0803BE50: .4byte 0x000097FF
_0803BE54: .4byte 0x0000047D
_0803BE58: .4byte 0x00000424
_0803BE5C:
	ldr r0, _0803BE74 @ =0x0000AFFF
	cmp r2, r0
	bhi _0803BE80
	ldr r4, _0803BE78 @ =0x0000047D
	adds r0, r1, r4
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	add r0, r8
	ldr r1, _0803BE7C @ =0x00000424
	b _0803BEC0
	.align 2, 0
_0803BE74: .4byte 0x0000AFFF
_0803BE78: .4byte 0x0000047D
_0803BE7C: .4byte 0x00000424
_0803BE80:
	ldr r0, _0803BE90 @ =0x0000CFFF
	cmp r2, r0
	bhi _0803BE98
	ldr r2, _0803BE94 @ =0x0000047D
	adds r0, r1, r2
	mov r3, sb
	strb r3, [r0]
	b _0803BEC2
	.align 2, 0
_0803BE90: .4byte 0x0000CFFF
_0803BE94: .4byte 0x0000047D
_0803BE98:
	ldr r0, _0803BEA4 @ =0x0000E7FF
	cmp r2, r0
	bhi _0803BEAC
	ldr r4, _0803BEA8 @ =0x0000047D
	adds r1, r1, r4
	b _0803BEB6
	.align 2, 0
_0803BEA4: .4byte 0x0000E7FF
_0803BEA8: .4byte 0x0000047D
_0803BEAC:
	movs r0, #0xe8
	lsls r0, r0, #8
	strh r0, [r3]
	ldr r0, _0803BEE8 @ =0x0000047D
	adds r1, r1, r0
_0803BEB6:
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	add r0, r8
	ldr r1, _0803BEEC @ =0x0000053C
_0803BEC0:
	strh r1, [r0]
_0803BEC2:
	ldr r0, _0803BEF0 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r1, _0803BEF4 @ =0x000003E2
	adds r3, r2, r1
	ldr r4, _0803BEE8 @ =0x0000047D
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	b _0803C476
	.align 2, 0
_0803BEE8: .4byte 0x0000047D
_0803BEEC: .4byte 0x0000053C
_0803BEF0: .4byte gCurrentPinballGame
_0803BEF4: .4byte 0x000003E2
_0803BEF8:
	ldr r0, _0803BF48 @ =gUnknown_086AF140
	mov r4, r8
	ldr r5, [r4]
	ldr r1, _0803BF4C @ =0x000003E2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0803BF1C
	b _0803C28E
_0803BF1C:
	movs r3, #0
	strh r3, [r2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x38
	bne _0803BF76
	ldr r0, _0803BF50 @ =0x000003E1
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0803BF54
	movs r0, #0x36
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803BF76
	.align 2, 0
_0803BF48: .4byte gUnknown_086AF140
_0803BF4C: .4byte 0x000003E2
_0803BF50: .4byte 0x000003E1
_0803BF54:
	strh r3, [r4]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _0803BFB0 @ =0x000003DD
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r3]
	ldr r1, _0803BFB4 @ =0x000003E1
	adds r0, r0, r1
	movs r1, #6
	strb r1, [r0]
_0803BF76:
	ldr r0, _0803BFB8 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r3, _0803BFBC @ =0x000003E2
	adds r0, r2, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x32
	beq _0803BF88
	b _0803C476
_0803BF88:
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq _0803BF96
	b _0803C476
_0803BF96:
	ldr r0, _0803BFC0 @ =gMain
	ldr r4, _0803BFC4 @ =0x00001888
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	ldr r1, _0803BFC8 @ =0x00000456
	adds r0, r2, r1
	strh r3, [r0]
	ldr r0, _0803BFCC @ =gMPlayInfo_SE1
	ldr r1, _0803BFD0 @ =gUnknown_086A2548
	bl MPlayStart
	b _0803C476
	.align 2, 0
_0803BFB0: .4byte 0x000003DD
_0803BFB4: .4byte 0x000003E1
_0803BFB8: .4byte gCurrentPinballGame
_0803BFBC: .4byte 0x000003E2
_0803BFC0: .4byte gMain
_0803BFC4: .4byte 0x00001888
_0803BFC8: .4byte 0x00000456
_0803BFCC: .4byte gMPlayInfo_SE1
_0803BFD0: .4byte gUnknown_086A2548
_0803BFD4:
	ldr r1, _0803BFFC @ =gUnknown_086AF140
	ldr r5, _0803C000 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _0803C004 @ =0x000003E2
	adds r2, r4, r6
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r7, #0xf9
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrh r3, [r1]
	ldrh r0, [r0]
	cmp r0, r3
	bls _0803C008
	adds r0, r3, #1
	b _0803C474
	.align 2, 0
_0803BFFC: .4byte gUnknown_086AF140
_0803C000: .4byte gCurrentPinballGame
_0803C004: .4byte 0x000003E2
_0803C008:
	movs r3, #0
	strh r3, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x4a
	bne _0803C03A
	strh r3, [r2]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _0803C084 @ =0x000003DD
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _0803C088 @ =0x000003E1
	adds r0, r0, r2
	movs r1, #8
	strb r1, [r0]
_0803C03A:
	ldr r1, [r5]
	adds r0, r1, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x47
	beq _0803C048
	b _0803C476
_0803C048:
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _0803C052
	b _0803C476
_0803C052:
	ldr r4, _0803C08C @ =0x00000129
	adds r1, r1, r4
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	movs r2, #0x99
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0x3c
	strb r1, [r0]
	movs r0, #0xd
	bl sub_11B0
	ldr r0, _0803C090 @ =gMPlayInfo_SE1
	ldr r1, _0803C094 @ =gUnknown_086A2454
	bl MPlayStart
	b _0803C476
	.align 2, 0
_0803C084: .4byte 0x000003DD
_0803C088: .4byte 0x000003E1
_0803C08C: .4byte 0x00000129
_0803C090: .4byte gMPlayInfo_SE1
_0803C094: .4byte gUnknown_086A2454
_0803C098:
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xa5
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r4, [r3]
	ldr r1, _0803C118 @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0803C134
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #9
	strb r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _0803C11C @ =0x000003E2
	adds r0, r0, r4
	movs r4, #0
	strh r5, [r0]
	ldr r3, _0803C120 @ =gMain
	ldr r1, _0803C124 @ =0x00000A28
	adds r0, r3, r1
	movs r1, #1
	strh r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r3, r2
	strh r1, [r0]
	mov r0, r8
	ldr r1, [r0]
	movs r0, #0xb3
	lsls r0, r0, #3
	adds r2, r1, r0
	movs r0, #0xc6
	strh r0, [r2]
	ldr r2, _0803C128 @ =0x0000038E
	adds r0, r1, r2
	strh r5, [r0]
	movs r0, #0xb5
	lsls r0, r0, #3
	adds r1, r1, r0
	strb r4, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803C12C @ =0x000005A6
	adds r1, r0, r2
	strh r5, [r1]
	ldr r4, _0803C130 @ =0x000005A4
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	b _0803C172
	.align 2, 0
_0803C118: .4byte 0x00000283
_0803C11C: .4byte 0x000003E2
_0803C120: .4byte gMain
_0803C124: .4byte 0x00000A28
_0803C128: .4byte 0x0000038E
_0803C12C: .4byte 0x000005A6
_0803C130: .4byte 0x000005A4
_0803C134:
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0803C19C @ =0x000003E2
	adds r2, r1, r3
	movs r3, #0
	movs r0, #0x20
	strh r0, [r2]
	ldr r4, _0803C1A0 @ =0x00000387
	adds r1, r1, r4
	strb r3, [r1]
	ldr r2, _0803C1A4 @ =gMain
	movs r0, #0x80
	strb r0, [r2, #0xf]
	mov r1, r8
	ldr r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _0803C1A8 @ =0x00000392
	adds r0, r0, r1
	strh r5, [r0]
	adds r3, r2, #0
_0803C172:
	ldr r2, _0803C1AC @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r4, _0803C1B0 @ =0x000003E1
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r2, [r2]
	adds r4, #3
	adds r0, r2, r4
	strh r1, [r0]
	ldr r1, _0803C1B4 @ =0x00001438
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803C192
	b _0803C476
_0803C192:
	ldr r3, _0803C1B8 @ =0x00000486
	adds r1, r2, r3
	movs r0, #1
	b _0803C474
	.align 2, 0
_0803C19C: .4byte 0x000003E2
_0803C1A0: .4byte 0x00000387
_0803C1A4: .4byte gMain
_0803C1A8: .4byte 0x00000392
_0803C1AC: .4byte gCurrentPinballGame
_0803C1B0: .4byte 0x000003E1
_0803C1B4: .4byte 0x00001438
_0803C1B8: .4byte 0x00000486
_0803C1BC:
	ldr r0, _0803C1E4 @ =gUnknown_086AF140
	mov r4, r8
	ldr r5, [r4]
	ldr r1, _0803C1E8 @ =0x000003E2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0803C1EC
	adds r0, r3, #1
	strh r0, [r2]
	b _0803C236
	.align 2, 0
_0803C1E4: .4byte gUnknown_086AF140
_0803C1E8: .4byte 0x000003E2
_0803C1EC:
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x24
	bne _0803C236
	ldr r0, _0803C218 @ =0x000003E1
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x11
	bgt _0803C21C
	movs r0, #0x22
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803C236
	.align 2, 0
_0803C218: .4byte 0x000003E1
_0803C21C:
	movs r0, #2
	strh r0, [r4]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _0803C260 @ =0x000003E1
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
_0803C236:
	ldr r0, _0803C264 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803C268 @ =0x000003E2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x21
	beq _0803C248
	b _0803C476
_0803C248:
	movs r4, #0xf9
	lsls r4, r4, #2
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _0803C256
	b _0803C476
_0803C256:
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0x29
	b _0803C474
	.align 2, 0
_0803C260: .4byte 0x000003E1
_0803C264: .4byte gCurrentPinballGame
_0803C268: .4byte 0x000003E2
_0803C26C:
	ldr r0, _0803C294 @ =gUnknown_086AF140
	mov r1, r8
	ldr r5, [r1]
	ldr r2, _0803C298 @ =0x000003E2
	adds r4, r5, r2
	movs r3, #0
	ldrsh r1, [r4, r3]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0xf9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _0803C29C
_0803C28E:
	adds r0, r3, #1
	strh r0, [r2]
	b _0803C476
	.align 2, 0
_0803C294: .4byte gUnknown_086AF140
_0803C298: .4byte 0x000003E2
_0803C29C:
	movs r3, #0
	strh r3, [r2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803C2E8
	ldr r2, _0803C2C8 @ =0x000003E1
	adds r1, r5, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bgt _0803C2CC
	movs r0, #3
	strh r0, [r4]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803C2E8
	.align 2, 0
_0803C2C8: .4byte 0x000003E1
_0803C2CC:
	movs r0, #3
	strh r0, [r4]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xa
	strb r0, [r1]
	mov r0, r8
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1, #0x13]
	mov r1, r8
	ldr r0, [r1]
	strh r3, [r0, #0x18]
_0803C2E8:
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0803C3A8 @ =0x000003E2
	adds r0, r1, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #3
	beq _0803C2FC
	cmp r0, #0xc
	bne _0803C306
_0803C2FC:
	ldr r0, _0803C3AC @ =0x000003EA
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #0xa
	strh r0, [r1]
_0803C306:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0803C3A8 @ =0x000003E2
	adds r0, r0, r2
	ldrh r1, [r0]
	subs r0, r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0803C326
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	beq _0803C326
	cmp r0, #0xe
	bne _0803C334
_0803C326:
	mov r3, r8
	ldr r1, [r3]
	ldr r4, _0803C3AC @ =0x000003EA
	adds r1, r1, r4
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
_0803C334:
	ldr r0, _0803C3B0 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r1, _0803C3A8 @ =0x000003E2
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #5
	bne _0803C36C
	movs r4, #0xf9
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803C36C
	ldr r0, _0803C3B4 @ =0x000004CA
	adds r1, r2, r0
	movs r0, #0x1f
	strh r0, [r1]
	ldr r3, _0803C3B8 @ =0x000004C9
	adds r1, r2, r3
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0803C3BC @ =0x00000119
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
_0803C36C:
	ldr r0, _0803C3B0 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r4, _0803C3A8 @ =0x000003E2
	adds r0, r2, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xe
	beq _0803C37E
	b _0803C476
_0803C37E:
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803C476
	adds r4, #0xe8
	adds r1, r2, r4
	movs r0, #0x1f
	strh r0, [r1]
	ldr r0, _0803C3B8 @ =0x000004C9
	adds r1, r2, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0803C3BC @ =0x00000119
	bl m4aSongNumStart
	movs r0, #8
	bl sub_11B0
	b _0803C476
	.align 2, 0
_0803C3A8: .4byte 0x000003E2
_0803C3AC: .4byte 0x000003EA
_0803C3B0: .4byte gCurrentPinballGame
_0803C3B4: .4byte 0x000004CA
_0803C3B8: .4byte 0x000004C9
_0803C3BC: .4byte 0x00000119
_0803C3C0:
	ldr r1, _0803C3E8 @ =gUnknown_086AF140
	mov r3, r8
	ldr r2, [r3]
	ldr r4, _0803C3EC @ =0x000003E2
	adds r3, r2, r4
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _0803C3F0
	adds r0, r1, #1
	strh r0, [r2]
	b _0803C404
	.align 2, 0
_0803C3E8: .4byte gUnknown_086AF140
_0803C3EC: .4byte 0x000003E2
_0803C3F0:
	movs r1, #0
	strh r1, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne _0803C404
	strh r1, [r3]
_0803C404:
	mov r2, r8
	ldr r6, [r2]
	ldr r3, _0803C4BC @ =0x0000038E
	adds r4, r6, r3
	ldrh r5, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _0803C4C0 @ =0xFFFFFE0C
	cmp r0, r1
	ble _0803C444
	subs r0, r1, r0
	movs r1, #0x1e
	bl __divsi3
	adds r0, r5, r0
	strh r0, [r4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0xa
	bl __divsi3
	adds r2, r6, #0
	adds r2, #0xe6
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x26
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0803C444
	ldr r0, _0803C4C4 @ =0x0000FFDA
	strh r0, [r2]
_0803C444:
	ldr r3, _0803C4C8 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _0803C460
	ldr r4, _0803C4CC @ =0x000003E2
	adds r1, r1, r4
	movs r0, #0x4a
	strh r0, [r1]
_0803C460:
	ldr r1, [r3]
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0803C476
	ldr r0, _0803C4CC @ =0x000003E2
	adds r1, r1, r0
	movs r0, #0x4b
_0803C474:
	strh r0, [r1]
_0803C476:
	ldr r0, _0803C4C8 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r2, #0x99
	lsls r2, r2, #3
	adds r3, r1, r2
	ldrb r4, [r3]
	movs r1, #0
	ldrsb r1, [r3, r1]
	mov r8, r0
	cmp r1, #0
	bgt _0803C48E
	b _0803C5BC
_0803C48E:
	subs r0, r4, #1
	strb r0, [r3]
	mov r3, r8
	ldr r5, [r3]
	adds r1, r5, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x13
	bgt _0803C4D4
	ldr r4, _0803C4D0 @ =gUnknown_086AEF28
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r5, r2
	b _0803C4F2
	.align 2, 0
_0803C4BC: .4byte 0x0000038E
_0803C4C0: .4byte 0xFFFFFE0C
_0803C4C4: .4byte 0x0000FFDA
_0803C4C8: .4byte gCurrentPinballGame
_0803C4CC: .4byte 0x000003E2
_0803C4D0: .4byte gUnknown_086AEF28
_0803C4D4:
	ldr r4, _0803C600 @ =gUnknown_086AEF28
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	movs r4, #0xab
	lsls r4, r4, #2
	adds r1, r5, r4
_0803C4F2:
	strh r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	movs r5, #0x99
	lsls r5, r5, #3
	adds r0, r2, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0803C50E
	movs r3, #0xab
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
_0803C50E:
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _0803C548
	movs r3, #0
	ldr r0, _0803C604 @ =gMain
	movs r2, #0
	movs r1, #0xdc
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	ldr r1, _0803C608 @ =0x000004CF
	adds r0, r4, r1
	strb r2, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	movs r2, #0x9b
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r3, [r0]
_0803C548:
	mov r3, r8
	ldr r4, [r3]
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0803C582
	movs r3, #1
	ldr r0, _0803C604 @ =gMain
	ldr r1, _0803C60C @ =0x00000E78
	adds r0, r0, r1
	movs r1, #0
	movs r2, #0
	strh r3, [r0]
	movs r3, #0x9a
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _0803C610 @ =0x000004D3
	adds r0, r0, r1
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, [r4]
	adds r3, #0xa
	adds r0, r0, r3
	strh r2, [r0]
_0803C582:
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x35
	bne _0803C5BC
	ldr r1, _0803C604 @ =gMain
	movs r2, #0xf3
	lsls r2, r2, #4
	adds r1, r1, r2
	movs r2, #0
	movs r3, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0803C614 @ =0x000004D1
	adds r0, r4, r1
	strb r2, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r4, _0803C618 @ =0x000004D4
	adds r0, r0, r4
	movs r1, #0x16
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _0803C61C @ =0x000004DC
	adds r0, r0, r1
	strh r3, [r0]
_0803C5BC:
	mov r2, r8
	ldr r5, [r2]
	ldr r3, _0803C620 @ =0x000004CA
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _0803C662
	subs r0, #1
	strh r0, [r1]
	ldr r4, _0803C624 @ =0x000004C9
	adds r6, r5, r4
	ldrb r0, [r6]
	cmp r0, #5
	bhi _0803C62C
	ldr r4, _0803C628 @ =gUnknown_086AEF40
	ldrh r0, [r1]
	movs r1, #0x1f
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1e
	subs r1, r1, r0
	ldrb r2, [r6]
	lsls r0, r2, #5
	subs r0, r0, r2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #2
	adds r0, r5, r2
	b _0803C64A
	.align 2, 0
_0803C600: .4byte gUnknown_086AEF28
_0803C604: .4byte gMain
_0803C608: .4byte 0x000004CF
_0803C60C: .4byte 0x00000E78
_0803C610: .4byte 0x000004D3
_0803C614: .4byte 0x000004D1
_0803C618: .4byte 0x000004D4
_0803C61C: .4byte 0x000004DC
_0803C620: .4byte 0x000004CA
_0803C624: .4byte 0x000004C9
_0803C628: .4byte gUnknown_086AEF40
_0803C62C:
	ldr r4, _0803C6C4 @ =gUnknown_086AF0B4
	ldrh r0, [r1]
	movs r1, #0x46
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x45
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r3, #0xab
	lsls r3, r3, #2
	adds r0, r5, r3
_0803C64A:
	strh r1, [r0]
	mov r4, r8
	ldr r2, [r4]
	ldr r1, _0803C6C8 @ =0x000004CA
	adds r0, r2, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _0803C662
	movs r3, #0xab
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
_0803C662:
	mov r4, r8
	ldr r0, [r4]
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0803C6B6
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803C69E
	ldr r0, _0803C6CC @ =gSpeciesInfo
	ldr r1, _0803C6D0 @ =0x00001290
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0
	bl PlayCry_Normal
	ldr r1, [r4]
	ldr r3, _0803C6C8 @ =0x000004CA
	adds r2, r1, r3
	movs r0, #0x46
	strh r0, [r2]
	ldr r4, _0803C6D4 @ =0x000004C9
	adds r1, r1, r4
	movs r0, #6
	strb r0, [r1]
_0803C69E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803C6B6
	ldr r0, _0803C6D8 @ =gMPlayInfo_BGM
	ldr r1, _0803C6DC @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_0803C6B6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C6C4: .4byte gUnknown_086AF0B4
_0803C6C8: .4byte 0x000004CA
_0803C6CC: .4byte gSpeciesInfo
_0803C6D0: .4byte 0x00001290
_0803C6D4: .4byte 0x000004C9
_0803C6D8: .4byte gMPlayInfo_BGM
_0803C6DC: .4byte 0x0000FFFF
