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

	thumb_func_start sub_3C6E0
sub_3C6E0: @ 0x0803C6E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r7, _0803C820 @ =gMain+0x17D0 @gMain.spriteGroups[29]
	ldrh r0, [r7]
	ldr r1, _0803C824 @ =gCurrentPinballGame
	mov sl, r1
	cmp r0, #0
	bne _0803C6FA
	b _0803CA2E
_0803C6FA:
	ldr r1, _0803C828 @ =gUnknown_086AF140
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _0803C82C @ =0x000003E2
	adds r0, r4, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r0
	movs r6, #0xfa
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x64
	adds r4, #0x58
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r5, _0803C830 @ =0x000003EA
	adds r0, r4, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x54
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	mov r0, sl
	ldr r4, [r0]
	adds r6, r4, r6
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x76
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	adds r5, r4, r5
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x3c
	ldr r2, _0803C834 @ =0x0000028A
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xb8
	movs r6, #0xfc
	lsls r6, r6, #2
	adds r1, r4, r6
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x9c
	ldr r2, _0803C838 @ =0x000003F2
	adds r4, r4, r2
	strh r0, [r4]
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r0, #0x3c
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0803C7B2
	ldr r0, _0803C83C @ =0x0000FFC4
	strh r0, [r7, #4]
_0803C7B2:
	movs r4, #4
	ldrsh r0, [r7, r4]
	cmp r0, #0xb4
	ble _0803C7BE
	movs r0, #0xb4
	strh r0, [r7, #4]
_0803C7BE:
	mov r6, sl
	ldr r0, [r6]
	ldr r1, _0803C840 @ =0x00000389
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	ble _0803C84C
	movs r2, #0
	ldr r4, _0803C844 @ =gOamBuffer
	ldr r3, _0803C848 @ =0xFFFFFE00
	mov r8, r3
	movs r6, #0xb0
_0803C7DA:
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
	cmp r3, #0x12
	ble _0803C7DA
	b _0803CA2E
	.align 2, 0
_0803C820: .4byte gMain+0x17D0 @gMain.spriteGroups[29]
_0803C824: .4byte gCurrentPinballGame
_0803C828: .4byte gUnknown_086AF140
_0803C82C: .4byte 0x000003E2
_0803C830: .4byte 0x000003EA
_0803C834: .4byte 0x0000028A
_0803C838: .4byte 0x000003F2
_0803C83C: .4byte 0x0000FFC4
_0803C840: .4byte 0x00000389
_0803C844: .4byte gOamBuffer
_0803C848: .4byte 0xFFFFFE00
_0803C84C:
	cmp r0, #1
	bne _0803C8FC
	movs r2, #0
	mov r4, r8
	lsls r0, r4, #0x10
	ldr r6, _0803C8EC @ =gOamBuffer
	asrs r1, r0, #0x10
	movs r0, #0x72
	adds r3, r1, #0
	muls r3, r0, r3
	mov r8, r3
	ldr r4, _0803C8F0 @ =0xFFFFFE00
	mov ip, r4
	movs r0, #0xe0
	mov sb, r0
_0803C86A:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r1, _0803C8F4 @ =gUnknown_086B65EA
	adds r0, r0, r1
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
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
	ldr r4, _0803C8F8 @ =0x000001FF
	ands r1, r4
	mov r0, ip
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
	mov r4, sb
	orrs r0, r4
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x12
	ble _0803C86A
	b _0803CA2E
	.align 2, 0
_0803C8EC: .4byte gOamBuffer
_0803C8F0: .4byte 0xFFFFFE00
_0803C8F4: .4byte gUnknown_086B65EA
_0803C8F8: .4byte 0x000001FF
_0803C8FC:
	cmp r0, #3
	bne _0803C9AC
	movs r2, #0
	mov r6, r8
	lsls r0, r6, #0x10
	ldr r6, _0803C99C @ =gOamBuffer
	asrs r1, r0, #0x10
	movs r0, #0x72
	adds r3, r1, #0
	muls r3, r0, r3
	mov r8, r3
	ldr r4, _0803C9A0 @ =0xFFFFFE00
	mov ip, r4
	movs r0, #0xb0
	mov sb, r0
_0803C91A:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	adds r2, r0, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r1, _0803C9A4 @ =gUnknown_086B65EA
	adds r0, r0, r1
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
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
	ldr r4, _0803C9A8 @ =0x000001FF
	ands r1, r4
	mov r0, ip
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
	mov r4, sb
	orrs r0, r4
	strb r0, [r1, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x12
	ble _0803C91A
	b _0803CA2E
	.align 2, 0
_0803C99C: .4byte gOamBuffer
_0803C9A0: .4byte 0xFFFFFE00
_0803C9A4: .4byte gUnknown_086B65EA
_0803C9A8: .4byte 0x000001FF
_0803C9AC:
	movs r2, #0
	mov r6, r8
	lsls r0, r6, #0x10
	ldr r1, _0803CB6C @ =gOamBuffer
	mov sb, r1
	asrs r1, r0, #0x10
	movs r0, #0x72
	adds r3, r1, #0
	muls r3, r0, r3
	mov r8, r3
	ldr r4, _0803CB70 @ =0xFFFFFE00
	mov ip, r4
_0803C9C4:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r6, sb
	adds r2, r0, r6
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r1, _0803CB74 @ =gUnknown_086B65EA
	adds r0, r0, r1
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, sb
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _0803CB78 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	mov r0, ip
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x12
	ble _0803C9C4
_0803CA2E:
	ldr r7, _0803CB7C @ =gMain+0x1380 @gMain.spriteGroups[23]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0803CA38
	b _0803CB98
_0803CA38:
	mov r3, sl
	ldr r0, [r3]
	ldr r4, _0803CB80 @ =0x0000047E
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0803CA5E
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803CA5E
	strh r0, [r7]
_0803CA5E:
	mov r6, sl
	ldr r4, [r6]
	ldr r1, _0803CB84 @ =0x0000047D
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r1, r0, #1
	ldr r2, _0803CB80 @ =0x0000047E
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0803CA80
	adds r0, #3
_0803CA80:
	asrs r0, r0, #2
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r1, _0803CB88 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x54
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r2, #0
	ldr r3, _0803CB8C @ =gUnknown_086B6512
	mov sb, r3
	mov r4, r8
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r8, r0
	ldr r6, _0803CB70 @ =0xFFFFFE00
	mov ip, r6
_0803CAD8:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	ldr r1, _0803CB6C @ =gOamBuffer
	adds r2, r0, r1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	ldr r6, _0803CB6C @ =gOamBuffer
	adds r2, r2, r6
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _0803CB78 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	mov r0, ip
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	ldr r0, _0803CB6C @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _0803CAD8
	mov r3, sl
	ldr r0, [r3]
	ldr r4, _0803CB90 @ =0x000005A4
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803CBAE
	ldr r0, _0803CB94 @ =gMain
	movs r6, #0x9c
	lsls r6, r6, #5
	adds r0, r0, r6
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r3]
	ldr r1, _0803CB80 @ =0x0000047E
	adds r0, r0, r1
	strb r2, [r0]
	b _0803CBAE
	.align 2, 0
_0803CB6C: .4byte gOamBuffer
_0803CB70: .4byte 0xFFFFFE00
_0803CB74: .4byte gUnknown_086B65EA
_0803CB78: .4byte 0x000001FF
_0803CB7C: .4byte gMain+0x1380 @gMain.spriteGroups[23]
_0803CB80: .4byte 0x0000047E
_0803CB84: .4byte 0x0000047D
_0803CB88: .4byte 0x000003EA
_0803CB8C: .4byte gUnknown_086B6512
_0803CB90: .4byte 0x000005A4
_0803CB94: .4byte gMain
_0803CB98:
	mov r2, sl
	ldr r0, [r2]
	ldr r3, _0803CBC0 @ =0x0000047E
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _0803CBAE
	movs r0, #1
	strh r0, [r7]
_0803CBAE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CBC0: .4byte 0x0000047E

	thumb_func_start sub_3CBC4
sub_3CBC4: @ 0x0803CBC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	movs r0, #0
	mov sl, r0
	ldr r1, _0803CBFC @ =gMain+0xA28 @gMain.spriteGroups[10]
	str r1, [sp, #4]
	ldrh r0, [r1]
	cmp r0, #0
	bne _0803CBE0
	b _0803CD68
_0803CBE0:
	ldr r2, _0803CC00 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _0803CC04 @ =0x000006C4
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0803CC08
	movs r0, #0xf0
	strh r0, [r1, #2]
	movs r0, #0xb4
	strh r0, [r1, #4]
	b _0803CC12
	.align 2, 0
_0803CBFC: .4byte gMain+0xA28 @gMain.spriteGroups[10]
_0803CC00: .4byte gCurrentPinballGame
_0803CC04: .4byte 0x000006C4
_0803CC08:
	movs r0, #0x60
	ldr r4, [sp, #4]
	strh r0, [r4, #2]
	movs r0, #0x37
	strh r0, [r4, #4]
_0803CC12:
	ldr r5, _0803CD94 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r6, [sp, #4]
	ldrh r2, [r6, #2]
	ldr r7, _0803CD98 @ =0x000006E4
	adds r0, r1, r7
	strh r2, [r0]
	ldrh r0, [r6, #4]
	ldr r2, _0803CD9C @ =0x000006E6
	adds r1, r1, r2
	strh r0, [r1]
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc7
	ble _0803CC34
	movs r0, #0xc8
	strh r0, [r6, #4]
_0803CC34:
	movs r2, #0
	ldr r4, _0803CDA0 @ =gMain+0x970 @gMain.spriteGroups[9]
	mov ip, r4
	ldr r5, _0803CDA4 @ =gOamBuffer
	movs r6, #3
	mov r8, r6
	movs r7, #0xd
	rsbs r7, r7, #0
	mov sb, r7
_0803CC46:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r1, [sp, #4]
	adds r6, r1, r0
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
	ldr r2, _0803CD94 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r7, _0803CDA8 @ =0x000006DB
	adds r0, r0, r7
	ldrb r1, [r0]
	mov r0, r8
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldr r7, [sp, #4]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _0803CDAC @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _0803CDB0 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0803CC46
	mov r3, ip
	str r3, [sp, #4]
	ldr r4, _0803CD94 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _0803CD98 @ =0x000006E4
	adds r0, r0, r5
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r3, #2]
	ldr r0, [r4]
	ldr r6, _0803CD9C @ =0x000006E6
	adds r0, r0, r6
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _0803CCEC
	movs r0, #0xc8
	strh r0, [r3, #4]
_0803CCEC:
	movs r2, #0
	ldr r5, _0803CDA4 @ =gOamBuffer
	movs r7, #3
	mov r8, r7
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sb, r0
	ldr r1, _0803CDB0 @ =0xFFFFFE00
	mov ip, r1
_0803CCFE:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r2, [sp, #4]
	adds r6, r2, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	ldr r7, _0803CD94 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _0803CDA8 @ =0x000006DB
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
	ldr r2, [sp, #4]
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _0803CDAC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, [sp, #4]
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0803CCFE
_0803CD68:
	ldr r4, _0803CDB4 @ =gMain+0x1438 @gMain.spriteGroups[24]
	str r4, [sp, #4]
	ldrh r0, [r4]
	cmp r0, #0
	bne _0803CD74
	b _0803CFD4
_0803CD74:
	ldr r5, _0803CD94 @ =gCurrentPinballGame
	ldr r7, [r5]
	ldr r6, _0803CDB8 @ =0x00000486
	adds r4, r7, r6
	ldrh r5, [r4]
	subs r0, r5, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r0, _0803CDBC @ =0x00000257
	cmp r1, r0
	ble _0803CDC0
	movs r7, #0
	mov sl, r7
	b _0803CEC2
	.align 2, 0
_0803CD94: .4byte gCurrentPinballGame
_0803CD98: .4byte 0x000006E4
_0803CD9C: .4byte 0x000006E6
_0803CDA0: .4byte gMain+0x970 @gMain.spriteGroups[9]
_0803CDA4: .4byte gOamBuffer
_0803CDA8: .4byte 0x000006DB
_0803CDAC: .4byte 0x000001FF
_0803CDB0: .4byte 0xFFFFFE00
_0803CDB4: .4byte gMain+0x1438 @gMain.spriteGroups[24]
_0803CDB8: .4byte 0x00000486
_0803CDBC: .4byte 0x00000257
_0803CDC0:
	cmp r1, #5
	bgt _0803CDC6
	b _0803CEBE
_0803CDC6:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xf
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #5
	bl __divsi3
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r1, _0803CE04 @ =0x0000047F
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0803CE58
	cmp r0, #7
	bne _0803CE0C
	ldr r2, _0803CE08 @ =0x0000132C
	adds r0, r7, r2
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	b _0803CE3A
	.align 2, 0
_0803CE04: .4byte 0x0000047F
_0803CE08: .4byte 0x0000132C
_0803CE0C:
	cmp r0, #4
	bne _0803CE28
	ldr r4, _0803CE20 @ =0x0000132C
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	ldr r5, _0803CE24 @ =0xFFFFFE00
	adds r0, r0, r5
	b _0803CE3A
	.align 2, 0
_0803CE20: .4byte 0x0000132C
_0803CE24: .4byte 0xFFFFFE00
_0803CE28:
	cmp r0, #1
	bne _0803CE3C
	ldr r6, _0803CE4C @ =0x0000132C
	adds r0, r7, r6
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r0, r7
_0803CE3A:
	str r0, [r1, #0x34]
_0803CE3C:
	ldr r0, _0803CE50 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _0803CE54 @ =0x0000047F
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0803CE82
	.align 2, 0
_0803CE4C: .4byte 0x0000132C
_0803CE50: .4byte gCurrentPinballGame
_0803CE54: .4byte 0x0000047F
_0803CE58:
	ldrh r0, [r7, #4]
	cmp r0, #0
	beq _0803CE82
	adds r0, r5, #0
	subs r0, #0x1f
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0803CE70
	movs r0, #5
	strh r0, [r4]
_0803CE70:
	ldr r2, _0803CEA4 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	movs r0, #0x8f
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803CE82:
	ldr r0, _0803CEA4 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r1, r2, r3
	ldrh r7, [r1]
	cmp r7, #0
	beq _0803CEB2
	subs r0, r7, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x32
	bls _0803CEA8
	movs r4, #4
	mov sl, r4
	b _0803CEC2
	.align 2, 0
_0803CEA4: .4byte gCurrentPinballGame
_0803CEA8:
	cmp r0, #0x28
	bls _0803CEC2
	movs r5, #5
	mov sl, r5
	b _0803CEC2
_0803CEB2:
	ldrh r0, [r2, #4]
	cmp r0, #0
	beq _0803CEC2
	movs r0, #0x3c
	strh r0, [r1]
	b _0803CEC2
_0803CEBE:
	movs r6, #4
	mov sl, r6
_0803CEC2:
	ldr r7, _0803CEF0 @ =gCurrentPinballGame
	ldr r1, [r7]
	ldr r2, _0803CEF4 @ =0x00000486
	adds r0, r1, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	cmp r3, #0
	bne _0803CF04
	ldr r0, _0803CEF8 @ =gMain
	ldr r5, _0803CEFC @ =0x00001438
	adds r0, r0, r5
	movs r2, #0
	strh r3, [r0]
	ldr r0, [r7]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r0, r6
	strh r3, [r1]
	ldr r7, _0803CF00 @ =0x00000383
	adds r0, r0, r7
	strb r2, [r0]
	b _0803CF22
	.align 2, 0
_0803CEF0: .4byte gCurrentPinballGame
_0803CEF4: .4byte 0x00000486
_0803CEF8: .4byte gMain
_0803CEFC: .4byte 0x00001438
_0803CF00: .4byte 0x00000383
_0803CF04:
	ldr r0, _0803D10C @ =0x00000383
	adds r1, r1, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803D110 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _0803D114 @ =0x0000132C
	adds r0, r0, r3
	ldr r1, [r0]
	strh r2, [r1, #0x30]
	ldr r1, [r0]
	strh r2, [r1, #0x32]
	ldr r0, [r0]
	strh r2, [r0, #6]
_0803CF22:
	ldr r4, _0803D110 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0803D114 @ =0x0000132C
	adds r3, r2, r5
	ldr r0, [r3]
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0, #0x10]
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	ldr r6, [sp, #4]
	strh r0, [r6, #2]
	ldr r0, [r3]
	adds r2, #0x5a
	ldrh r0, [r0, #0x12]
	ldrh r1, [r2]
	subs r0, r0, r1
	subs r0, #8
	strh r0, [r6, #4]
	movs r2, #0
	mov r7, sl
	lsls r1, r7, #0x10
	ldr r0, _0803D118 @ =gUnknown_086B63AA
	mov sb, r0
	ldr r5, _0803D11C @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r1, _0803D120 @ =0xFFFFFE00
	mov r8, r1
_0803CF64:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r2, [sp, #4]
	adds r6, r2, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r2, r0, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, ip
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	str r1, [sp, #0x18]
	ldr r7, [sp, #4]
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r7, [sp, #0x18]
	adds r1, r7, r0
	ldr r7, _0803D124 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _0803CF64
_0803CFD4:
	ldr r5, _0803D128 @ =gMain+0x12C8 @gMain.spriteGroups[22]
	str r5, [sp, #4]
	ldrh r0, [r5]
	cmp r0, #0
	bne _0803CFE0
	b _0803D2C6
_0803CFE0:
	ldr r6, _0803D110 @ =gCurrentPinballGame
	ldr r5, [r6]
	movs r7, #0x91
	lsls r7, r7, #3
	adds r6, r5, r7
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, _0803D114 @ =0x0000132C
	adds r2, r2, r5
	mov sb, r2
	ldr r4, [r2]
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	subs r1, r0, r1
	str r1, [sp, #8]
	ldr r0, _0803D12C @ =0x0000048A
	adds r7, r5, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x12
	ldrsh r1, [r4, r2]
	subs r1, r0, r1
	str r1, [sp, #0xc]
	ldr r3, [sp, #8]
	adds r1, r3, #0
	muls r1, r3, r1
	ldr r4, [sp, #0xc]
	adds r0, r4, #0
	muls r0, r4, r0
	adds r3, r1, r0
	ldr r4, _0803D130 @ =0x00000482
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _0803D03C
	b _0803D1E2
_0803D03C:
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _0803D04A
	b _0803D150
_0803D04A:
	ldrh r1, [r1]
	movs r0, #7
	ands r1, r0
	lsrs r1, r1, #2
	ldr r6, _0803D134 @ =0x0000047D
	adds r0, r5, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	cmp r3, #0xf0
	bgt _0803D0B6
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D0B6
	ldr r1, _0803D138 @ =0x00000486
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0803D13C @ =0x00000257
	cmp r1, r0
	bgt _0803D0B6
	ldr r0, _0803D140 @ =gMPlayInfo_SE1
	ldr r1, _0803D144 @ =gUnknown_086A26A0
	bl MPlayStart
	ldr r3, _0803D110 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r2, r1, r4
	movs r0, #0xa
	strh r0, [r2]
	ldr r4, [sp, #4]
	movs r5, #0xb8
	lsls r5, r5, #1
	adds r2, r4, r5
	movs r0, #1
	strh r0, [r2]
	adds r6, #9
	adds r1, r1, r6
	movs r0, #0x99
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #9
	bl sub_11B0
_0803D0B6:
	ldr r5, _0803D110 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r7, _0803D148 @ =0x00000484
	mov r8, r7
	add r0, r8
	ldrh r0, [r0]
	bl Cos
	ldr r4, [r5]
	movs r1, #0x91
	lsls r1, r1, #3
	adds r6, r4, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xfa
	lsls r1, r1, #1
	bl __divsi3
	ldrh r1, [r6]
	adds r1, r1, r0
	strh r1, [r6]
	add r4, r8
	ldrh r0, [r4]
	bl Sin
	adds r1, r0, #0
	ldr r4, [r5]
	ldr r2, _0803D12C @ =0x0000048A
	adds r4, r4, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	rsbs r0, r0, #0
	ldr r1, _0803D14C @ =0x00004E20
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	b _0803D1CC
	.align 2, 0
_0803D10C: .4byte 0x00000383
_0803D110: .4byte gCurrentPinballGame
_0803D114: .4byte 0x0000132C
_0803D118: .4byte gUnknown_086B63AA
_0803D11C: .4byte gOamBuffer
_0803D120: .4byte 0xFFFFFE00
_0803D124: .4byte 0x000001FF
_0803D128: .4byte gMain+0x12C8 @gMain.spriteGroups[22]
_0803D12C: .4byte 0x0000048A
_0803D130: .4byte 0x00000482
_0803D134: .4byte 0x0000047D
_0803D138: .4byte 0x00000486
_0803D13C: .4byte 0x00000257
_0803D140: .4byte gMPlayInfo_SE1
_0803D144: .4byte gUnknown_086A26A0
_0803D148: .4byte 0x00000484
_0803D14C: .4byte 0x00004E20
_0803D150:
	ldr r4, _0803D1A0 @ =0x0000047D
	adds r4, r4, r5
	mov r8, r4
	ldrb r4, [r4]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	lsls r4, r4, #1
	ldrh r5, [r1]
	adds r0, r5, #0
	movs r1, #5
	str r3, [sp, #0x14]
	bl __udivsi3
	subs r0, #7
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov sl, r4
	ldr r3, [sp, #0x14]
	cmp r5, #9
	bne _0803D1CC
	cmp r3, #0xf0
	bgt _0803D1A4
	mov r5, sb
	ldr r0, [r5]
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	adds r1, #4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	strh r0, [r6]
	ldr r0, [r5]
	movs r3, #0x12
	ldrsh r1, [r0, r3]
	adds r1, #0xe
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	b _0803D1C2
	.align 2, 0
_0803D1A0: .4byte 0x0000047D
_0803D1A4:
	mov r4, r8
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq _0803D1BE
	cmp r0, #1
	bne _0803D1B8
	ldrh r0, [r6]
	subs r0, #0x78
	b _0803D1BC
_0803D1B8:
	ldrh r0, [r6]
	adds r0, #0x78
_0803D1BC:
	strh r0, [r6]
_0803D1BE:
	ldrh r0, [r7]
	adds r0, #0xf0
_0803D1C2:
	strh r0, [r7]
	movs r0, #0x90
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803D1CC:
	ldr r1, _0803D308 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r5, _0803D30C @ =0x00000482
	adds r0, r0, r5
	ldrh r7, [r0]
	cmp r7, #0
	bne _0803D1E2
	ldr r0, _0803D310 @ =gMain
	ldr r6, _0803D314 @ =0x000012C8
	adds r0, r0, r6
	strh r7, [r0]
_0803D1E2:
	ldr r7, _0803D308 @ =gCurrentPinballGame
	ldr r4, [r7]
	movs r1, #0x91
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #0xc
	ldr r3, [sp, #4]
	strh r0, [r3, #2]
	ldr r5, _0803D318 @ =0x0000048A
	adds r0, r4, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r0, #0x16
	ldr r7, [sp, #4]
	strh r0, [r7, #4]
	movs r2, #0
	mov r0, sl
	lsls r1, r0, #0x10
	ldr r3, _0803D31C @ =gUnknown_086B63F2
	mov sb, r3
	ldr r5, _0803D320 @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sl, r0
	ldr r4, _0803D324 @ =0xFFFFFE00
	mov r8, r4
_0803D238:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r7, [sp, #4]
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r2, r0, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, sl
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
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
	ldr r7, _0803D328 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _0803D238
	ldr r5, _0803D308 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _0803D32C @ =0x000005A4
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803D2C6
	ldr r0, _0803D310 @ =gMain
	ldr r7, _0803D314 @ =0x000012C8
	adds r0, r0, r7
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r5]
	ldr r2, _0803D30C @ =0x00000482
	adds r0, r0, r2
	strh r1, [r0]
_0803D2C6:
	movs r3, #0
	str r3, [sp]
_0803D2CA:
	ldr r4, [sp]
	lsls r2, r4, #0x10
	asrs r3, r2, #0x10
	movs r0, #0xb8
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, _0803D330 @ =gMain+0xDC0 @gMain.spriteGroups[15]
	adds r1, r1, r0
	str r1, [sp, #4]
	ldrh r0, [r1]
	str r2, [sp, #0x10]
	cmp r0, #0
	bne _0803D2E8
	bl _0803DABA
_0803D2E8:
	ldr r5, _0803D308 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _0803D334 @ =0x000004CF
	adds r0, r0, r6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bls _0803D2FE
	b _0803D982
_0803D2FE:
	lsls r0, r0, #2
	ldr r1, _0803D338 @ =_0803D33C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D308: .4byte gCurrentPinballGame
_0803D30C: .4byte 0x00000482
_0803D310: .4byte gMain
_0803D314: .4byte 0x000012C8
_0803D318: .4byte 0x0000048A
_0803D31C: .4byte gUnknown_086B63F2
_0803D320: .4byte gOamBuffer
_0803D324: .4byte 0xFFFFFE00
_0803D328: .4byte 0x000001FF
_0803D32C: .4byte 0x000005A4
_0803D330: .4byte gMain+0xDC0 @gMain.spriteGroups[15]
_0803D334: .4byte 0x000004CF
_0803D338: .4byte _0803D33C
_0803D33C: @ jump table
	.4byte _0803D354 @ case 0
	.4byte _0803D4E4 @ case 1
	.4byte _0803D600 @ case 2
	.4byte _0803D710 @ case 3
	.4byte _0803D824 @ case 4
	.4byte _0803D954 @ case 5
_0803D354:
	ldr r6, _0803D4B4 @ =gCurrentPinballGame
	ldr r1, [r6]
	ldr r7, [sp, #0x10]
	asrs r5, r7, #0x10
	ldr r0, _0803D4B8 @ =0x000004D2
	adds r1, r1, r0
	adds r1, r1, r5
	ldr r2, _0803D4BC @ =gUnknown_086AF3AC
	lsls r0, r5, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	bl Random
	ldr r4, [r6]
	lsls r1, r5, #2
	adds r4, r4, r1
	movs r1, #0x65
	bl __umodsi3
	adds r1, r0, #0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r1
	movs r1, #0x64
	bl __udivsi3
	adds r0, #0x1e
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r2, _0803D4C0 @ =0x000004EC
	adds r4, r4, r2
	strh r1, [r4]
	bl Random
	ldr r2, [r6]
	ldr r3, _0803D4C4 @ =0x000004CC
	adds r2, r2, r3
	adds r2, r2, r5
	movs r1, #0xf
	ands r1, r0
	strb r1, [r2]
	ldr r4, [r6]
	adds r4, r4, r3
	adds r6, r4, r5
	adds r5, #1
	adds r0, r5, #0
	movs r1, #3
	bl __modsi3
	adds r4, r4, r0
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _0803D3E0
	adds r2, r1, #0
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _0803D3D8
	adds r0, r2, #0
	adds r0, #0x10
_0803D3D8:
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r0, r1, r0
	strb r0, [r6]
_0803D3E0:
	ldr r5, _0803D4B4 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r3, [sp, #0x10]
	asrs r0, r3, #0x10
	ldr r6, _0803D4C4 @ =0x000004CC
	adds r4, r4, r6
	adds r7, r4, r0
	adds r0, #2
	movs r1, #3
	bl __modsi3
	adds r4, r4, r0
	movs r1, #0
	ldrsb r1, [r7, r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _0803D41A
	adds r2, r1, #0
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _0803D412
	adds r0, r2, #0
	adds r0, #0x10
_0803D412:
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r0, r1, r0
	strb r0, [r7]
_0803D41A:
	ldr r7, _0803D4B4 @ =gCurrentPinballGame
	ldr r3, [r7]
	ldr r0, [sp, #0x10]
	asrs r0, r0, #0x10
	mov sb, r0
	lsls r5, r0, #2
	adds r6, r3, r5
	ldr r4, _0803D4C8 @ =gUnknown_086AF34C
	ldr r1, _0803D4C4 @ =0x000004CC
	adds r2, r3, r1
	add r2, sb
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r7, _0803D4C0 @ =0x000004EC
	adds r0, r6, r7
	movs r7, #0
	mov sl, r7
	movs r7, #0
	mov r8, r7
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r4, #2
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r4, _0803D4CC @ =0x000004EE
	adds r6, r6, r4
	strh r0, [r6]
	mov r6, sb
	lsls r2, r6, #1
	ldr r7, _0803D4D0 @ =0x000004E4
	adds r0, r3, r7
	adds r0, r0, r2
	ldr r1, _0803D4D4 @ =0x0000FB50
	strh r1, [r0]
	ldr r1, _0803D4D8 @ =0x000004DE
	adds r0, r3, r1
	adds r0, r0, r2
	mov r2, r8
	strh r2, [r0]
	subs r4, #0x1f
	adds r3, r3, r4
	add r3, sb
	movs r0, #1
	strb r0, [r3]
	ldr r6, _0803D4B4 @ =gCurrentPinballGame
	ldr r1, [r6]
	adds r5, r1, r5
	adds r7, #0x14
	adds r0, r5, r7
	strh r2, [r0]
	ldr r0, _0803D4DC @ =0x000004FA
	adds r5, r5, r0
	strh r2, [r5]
	ldr r2, _0803D4E0 @ =0x000004D5
	adds r1, r1, r2
	add r1, sb
	mov r3, sl
	strb r3, [r1]
	b _0803D982
	.align 2, 0
_0803D4B4: .4byte gCurrentPinballGame
_0803D4B8: .4byte 0x000004D2
_0803D4BC: .4byte gUnknown_086AF3AC
_0803D4C0: .4byte 0x000004EC
_0803D4C4: .4byte 0x000004CC
_0803D4C8: .4byte gUnknown_086AF34C
_0803D4CC: .4byte 0x000004EE
_0803D4D0: .4byte 0x000004E4
_0803D4D4: .4byte 0x0000FB50
_0803D4D8: .4byte 0x000004DE
_0803D4DC: .4byte 0x000004FA
_0803D4E0: .4byte 0x000004D5
_0803D4E4:
	ldr r4, _0803D568 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r5, [sp, #0x10]
	asrs r3, r5, #0xf
	ldr r5, _0803D56C @ =0x000004E4
	adds r0, r1, r5
	adds r2, r0, r3
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r0, #0
	bge _0803D526
	ldr r7, _0803D570 @ =0x000004DE
	adds r0, r1, r7
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r1, #3
	movs r4, #0
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0803D516
	strh r4, [r2]
_0803D516:
	ldr r1, _0803D568 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r5
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0803D5D0
_0803D526:
	ldr r7, _0803D568 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r3, [sp, #0x10]
	asrs r5, r3, #0x10
	lsls r4, r5, #1
	movs r6, #0x9b
	lsls r6, r6, #3
	adds r0, r0, r6
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803D54A
	ldr r0, _0803D574 @ =0x00000121
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_0803D54A:
	ldr r1, [r7]
	adds r0, r1, r6
	adds r2, r0, r4
	ldrh r0, [r2]
	cmp r0, #4
	bhi _0803D580
	ldr r6, _0803D578 @ =0x000004D2
	adds r0, r1, r6
	adds r0, r0, r5
	ldr r1, _0803D57C @ =gUnknown_086AF3AC
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, #1
	b _0803D5B8
	.align 2, 0
_0803D568: .4byte gCurrentPinballGame
_0803D56C: .4byte 0x000004E4
_0803D570: .4byte 0x000004DE
_0803D574: .4byte 0x00000121
_0803D578: .4byte 0x000004D2
_0803D57C: .4byte gUnknown_086AF3AC
_0803D580:
	cmp r0, #9
	bhi _0803D59C
	ldr r7, _0803D594 @ =0x000004D2
	adds r0, r1, r7
	adds r0, r0, r5
	ldr r1, _0803D598 @ =gUnknown_086AF3AC
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, #2
	b _0803D5B8
	.align 2, 0
_0803D594: .4byte 0x000004D2
_0803D598: .4byte gUnknown_086AF3AC
_0803D59C:
	movs r0, #0
	strh r0, [r2]
	ldr r0, _0803D5EC @ =0x000004D2
	adds r1, r1, r0
	adds r1, r1, r5
	ldr r0, _0803D5F0 @ =gUnknown_086AF3AC
	adds r0, r4, r0
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	ldr r1, _0803D5F4 @ =0x000004CF
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #2
_0803D5B8:
	strb r1, [r0]
	ldr r2, _0803D5F8 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, [sp, #0x10]
	asrs r0, r3, #0xf
	movs r4, #0x9b
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0803D5D0:
	ldr r5, _0803D5F8 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r6, [sp, #0x10]
	asrs r0, r6, #0xe
	adds r1, r1, r0
	movs r7, #0x9f
	lsls r7, r7, #3
	adds r0, r1, r7
	movs r2, #0
	strh r2, [r0]
	ldr r0, _0803D5FC @ =0x000004FA
	adds r1, r1, r0
	strh r2, [r1]
	b _0803D982
	.align 2, 0
_0803D5EC: .4byte 0x000004D2
_0803D5F0: .4byte gUnknown_086AF3AC
_0803D5F4: .4byte 0x000004CF
_0803D5F8: .4byte gCurrentPinballGame
_0803D5FC: .4byte 0x000004FA
_0803D600:
	ldr r1, _0803D694 @ =gCurrentPinballGame
	ldr r6, [r1]
	ldr r2, [sp, #0x10]
	asrs r5, r2, #0x10
	lsls r4, r5, #2
	adds r4, r6, r4
	ldr r3, _0803D698 @ =0x000004EC
	adds r0, r4, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #1
	movs r2, #0x9f
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r3, #0
	mov sl, r3
	movs r7, #0
	mov sb, r7
	strh r0, [r1]
	ldr r1, _0803D69C @ =0x000004EE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #8
	ldr r3, _0803D6A0 @ =0x000004FA
	adds r4, r4, r3
	strh r0, [r4]
	ldr r4, _0803D6A4 @ =0x000004D5
	mov r8, r4
	adds r0, r6, r4
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D65A
	b _0803D982
_0803D65A:
	lsls r7, r5, #1
	adds r4, #3
	adds r0, r6, r4
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #1
	bne _0803D674
	ldr r0, _0803D6A8 @ =0x00000121
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_0803D674:
	ldr r6, _0803D694 @ =gCurrentPinballGame
	ldr r1, [r6]
	adds r0, r1, r4
	adds r0, r0, r7
	ldrh r2, [r0]
	cmp r2, #4
	bhi _0803D6B4
	ldr r2, _0803D6AC @ =0x000004D2
	adds r0, r1, r2
	adds r0, r0, r5
	ldr r1, _0803D6B0 @ =gUnknown_086AF3AC
	adds r1, r7, r1
	ldrb r1, [r1]
	adds r1, #3
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D694: .4byte gCurrentPinballGame
_0803D698: .4byte 0x000004EC
_0803D69C: .4byte 0x000004EE
_0803D6A0: .4byte 0x000004FA
_0803D6A4: .4byte 0x000004D5
_0803D6A8: .4byte 0x00000121
_0803D6AC: .4byte 0x000004D2
_0803D6B0: .4byte gUnknown_086AF3AC
_0803D6B4:
	cmp r2, #9
	bhi _0803D6D4
	ldr r3, _0803D6CC @ =0x000004D2
	adds r0, r1, r3
	adds r0, r0, r5
	ldr r1, _0803D6D0 @ =gUnknown_086AF3AC
	adds r1, r7, r1
	ldrb r1, [r1]
	adds r1, #4
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D6CC: .4byte 0x000004D2
_0803D6D0: .4byte gUnknown_086AF3AC
_0803D6D4:
	mov r4, sb
	strh r4, [r0]
	ldr r6, _0803D700 @ =0x000004D2
	adds r1, r1, r6
	adds r1, r1, r5
	ldr r0, _0803D704 @ =gUnknown_086AF3AC
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r0, #5
	strb r0, [r1]
	ldr r7, _0803D708 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _0803D70C @ =0x000004CF
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r7]
	add r0, r8
	adds r0, r0, r5
	mov r2, sl
	b _0803D92C
	.align 2, 0
_0803D700: .4byte 0x000004D2
_0803D704: .4byte gUnknown_086AF3AC
_0803D708: .4byte gCurrentPinballGame
_0803D70C: .4byte 0x000004CF
_0803D710:
	ldr r5, _0803D7A8 @ =gCurrentPinballGame
	ldr r6, [r5]
	ldr r7, [sp, #0x10]
	asrs r5, r7, #0x10
	lsls r4, r5, #2
	adds r4, r6, r4
	ldr r1, _0803D7AC @ =0x000004EC
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #1
	movs r3, #0x9f
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r7, #0
	mov sl, r7
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	subs r3, #0xa
	adds r0, r4, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #8
	ldr r1, _0803D7B0 @ =0x000004FA
	adds r4, r4, r1
	strh r0, [r4]
	ldr r2, _0803D7B4 @ =0x000004D5
	mov r8, r2
	adds r0, r6, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D76A
	b _0803D982
_0803D76A:
	lsls r7, r5, #1
	movs r4, #0x9b
	lsls r4, r4, #3
	adds r0, r6, r4
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #1
	bne _0803D786
	ldr r0, _0803D7B8 @ =0x00000121
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_0803D786:
	ldr r3, _0803D7A8 @ =gCurrentPinballGame
	ldr r1, [r3]
	adds r0, r1, r4
	adds r0, r0, r7
	ldrh r2, [r0]
	cmp r2, #4
	bhi _0803D7C4
	ldr r4, _0803D7BC @ =0x000004D2
	adds r0, r1, r4
	adds r0, r0, r5
	ldr r1, _0803D7C0 @ =gUnknown_086AF3AC
	adds r1, r7, r1
	ldrb r1, [r1]
	adds r1, #6
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D7A8: .4byte gCurrentPinballGame
_0803D7AC: .4byte 0x000004EC
_0803D7B0: .4byte 0x000004FA
_0803D7B4: .4byte 0x000004D5
_0803D7B8: .4byte 0x00000121
_0803D7BC: .4byte 0x000004D2
_0803D7C0: .4byte gUnknown_086AF3AC
_0803D7C4:
	cmp r2, #9
	bhi _0803D7E4
	ldr r6, _0803D7DC @ =0x000004D2
	adds r0, r1, r6
	adds r0, r0, r5
	ldr r1, _0803D7E0 @ =gUnknown_086AF3AC
	adds r1, r7, r1
	ldrb r1, [r1]
	adds r1, #7
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D7DC: .4byte 0x000004D2
_0803D7E0: .4byte gUnknown_086AF3AC
_0803D7E4:
	mov r2, sb
	strh r2, [r0]
	ldr r3, _0803D814 @ =0x000004D2
	adds r1, r1, r3
	adds r1, r1, r5
	ldr r0, _0803D818 @ =gUnknown_086AF3AC
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r0, #8
	strb r0, [r1]
	ldr r4, _0803D81C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r6, _0803D820 @ =0x000004CF
	adds r0, r0, r6
	adds r0, r0, r5
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r4]
	add r0, r8
_0803D80A:
	adds r0, r0, r5
	mov r7, sl
	strb r7, [r0]
	b _0803D92E
	.align 2, 0
_0803D814: .4byte 0x000004D2
_0803D818: .4byte gUnknown_086AF3AC
_0803D81C: .4byte gCurrentPinballGame
_0803D820: .4byte 0x000004CF
_0803D824:
	ldr r5, _0803D8B4 @ =gCurrentPinballGame
	ldr r6, [r5]
	ldr r7, [sp, #0x10]
	asrs r5, r7, #0x10
	lsls r4, r5, #2
	adds r4, r6, r4
	ldr r1, _0803D8B8 @ =0x000004EC
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #0xa
	mov sl, r3
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #1
	movs r7, #0x9f
	lsls r7, r7, #3
	adds r1, r4, r7
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	ldr r3, _0803D8BC @ =0x000004EE
	adds r0, r4, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #8
	ldr r1, _0803D8C0 @ =0x000004FA
	adds r4, r4, r1
	strh r0, [r4]
	ldr r2, _0803D8C4 @ =0x000004D5
	mov r8, r2
	adds r0, r6, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803D87E
	b _0803D982
_0803D87E:
	lsls r7, r5, #1
	movs r4, #0x9b
	lsls r4, r4, #3
	adds r0, r6, r4
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #1
	bne _0803D89A
	ldr r0, _0803D8C8 @ =0x00000121
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_0803D89A:
	ldr r3, _0803D8B4 @ =gCurrentPinballGame
	ldr r2, [r3]
	adds r0, r2, r4
	adds r0, r0, r7
	ldrh r1, [r0]
	cmp r1, #2
	bhi _0803D8D0
	ldr r4, _0803D8CC @ =0x000004D2
	adds r0, r2, r4
	adds r0, r0, r5
	movs r1, #9
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D8B4: .4byte gCurrentPinballGame
_0803D8B8: .4byte 0x000004EC
_0803D8BC: .4byte 0x000004EE
_0803D8C0: .4byte 0x000004FA
_0803D8C4: .4byte 0x000004D5
_0803D8C8: .4byte 0x00000121
_0803D8CC: .4byte 0x000004D2
_0803D8D0:
	cmp r1, #7
	bhi _0803D8E0
	ldr r6, _0803D8DC @ =0x000004D2
	adds r0, r2, r6
	b _0803D80A
	.align 2, 0
_0803D8DC: .4byte 0x000004D2
_0803D8E0:
	cmp r1, #0xd
	bhi _0803D8F4
	ldr r1, _0803D8F0 @ =0x000004D2
	adds r0, r2, r1
	adds r0, r0, r5
	movs r1, #0xb
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D8F0: .4byte 0x000004D2
_0803D8F4:
	cmp r1, #0x16
	bhi _0803D908
	ldr r3, _0803D904 @ =0x000004D2
	adds r0, r2, r3
	adds r0, r0, r5
	movs r1, #0xc
	strb r1, [r0]
	b _0803D92E
	.align 2, 0
_0803D904: .4byte 0x000004D2
_0803D908:
	mov r4, sb
	strh r4, [r0]
	ldr r6, _0803D948 @ =0x000004D2
	adds r0, r2, r6
	adds r0, r0, r5
	movs r1, #0xc
	strb r1, [r0]
	ldr r7, _0803D94C @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _0803D950 @ =0x000004CF
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r7]
	add r0, r8
	adds r0, r0, r5
	movs r2, #0
_0803D92C:
	strb r2, [r0]
_0803D92E:
	ldr r2, _0803D94C @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, [sp, #0x10]
	asrs r0, r3, #0xf
	movs r4, #0x9b
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0803D982
	.align 2, 0
_0803D948: .4byte 0x000004D2
_0803D94C: .4byte gCurrentPinballGame
_0803D950: .4byte 0x000004CF
_0803D954:
	ldr r5, _0803DB14 @ =gCurrentPinballGame
	ldr r1, [r5]
	ldr r6, [sp, #0x10]
	asrs r2, r6, #0x10
	lsls r0, r2, #2
	adds r1, r1, r0
	movs r7, #0x9f
	lsls r7, r7, #3
	adds r0, r1, r7
	movs r3, #0
	strh r3, [r0]
	ldr r0, _0803DB18 @ =0x000004FA
	adds r1, r1, r0
	strh r3, [r1]
	ldr r1, _0803DB1C @ =gMain
	adds r2, #0xf
	movs r0, #0xb8
	muls r0, r2, r0
	adds r0, r0, r1
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r3, [r0]
_0803D982:
	ldr r2, _0803DB14 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, [sp, #0x10]
	asrs r4, r3, #0x10
	ldr r5, _0803DB20 @ =0x000004D2
	adds r0, r0, r5
	adds r0, r0, r4
	ldr r2, _0803DB24 @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0803DB28 @ =gUnknown_084A11EC
	adds r0, r0, r1
	str r0, [r2]
	lsls r3, r4, #1
	adds r0, r3, r4
	lsls r0, r0, #8
	ldr r6, _0803DB2C @ =0x06010FA0
	adds r0, r0, r6
	str r0, [r2, #4]
	ldr r0, _0803DB30 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r7, _0803DB14 @ =gCurrentPinballGame
	ldr r6, [r7]
	lsls r5, r4, #2
	adds r5, r6, r5
	ldr r1, _0803DB34 @ =0x000004EC
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	str r3, [sp, #0x14]
	bl __divsi3
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	ldr r7, [sp, #4]
	strh r4, [r7, #2]
	ldr r1, _0803DB38 @ =0x000004E4
	adds r0, r6, r1
	ldr r3, [sp, #0x14]
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, r0, #0
	ldr r3, _0803DB3C @ =0x000004EE
	adds r5, r5, r3
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	adds r6, #0x5a
	ldrh r0, [r6]
	subs r4, r4, r0
	ldr r0, [sp, #4]
	strh r4, [r0, #4]
	movs r2, #0
	ldr r5, _0803DB40 @ =gOamBuffer
	ldr r1, _0803DB44 @ =0xFFFFFE00
	mov r8, r1
_0803DA10:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r2, [sp, #4]
	adds r6, r2, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	movs r4, #2
	ldrsh r1, [r6, r4]
	ldr r7, [sp, #4]
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r7, _0803DB48 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _0803DA10
	ldr r3, _0803DB14 @ =gCurrentPinballGame
	ldr r6, [r3]
	ldr r4, [sp, #0x10]
	asrs r3, r4, #0x10
	ldr r5, _0803DB4C @ =0x000004CF
	adds r0, r6, r5
	adds r4, r0, r3
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0803DABA
	ldr r2, _0803DB50 @ =gUnknown_086AF34C
	ldr r7, _0803DB54 @ =0x000004CC
	adds r0, r6, r7
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r5, #0x79
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r1, r0
	bne _0803DABA
	movs r2, #0
	movs r0, #4
	strb r0, [r4]
	ldr r6, _0803DB14 @ =gCurrentPinballGame
	ldr r0, [r6]
	adds r7, #9
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r6]
	lsls r1, r3, #1
	movs r3, #0x9b
	lsls r3, r3, #3
	adds r0, r0, r3
	adds r0, r0, r1
	strh r2, [r0]
_0803DABA:
	ldr r4, [sp]
	lsls r0, r4, #0x10
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r0, r5
	lsrs r6, r0, #0x10
	str r6, [sp]
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0803DAD2
	bl _0803D2CA
_0803DAD2:
	movs r7, #0
	str r7, [sp]
_0803DAD6:
	ldr r0, [sp]
	lsls r2, r0, #0x10
	asrs r4, r2, #0x10
	movs r0, #0xb8
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, _0803DB58 @ =gMain+0xFE8 @gMain.spriteGroups[18]
	adds r1, r1, r0
	str r1, [sp, #4]
	ldrh r3, [r1]
	str r2, [sp, #0x10]
	cmp r3, #0
	bne _0803DAF2
	b _0803E1B0
_0803DAF2:
	ldr r1, _0803DB14 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0803DB5C @ =0x0000048C
	adds r0, r0, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bls _0803DB08
	b _0803DF08
_0803DB08:
	lsls r0, r0, #2
	ldr r1, _0803DB60 @ =_0803DB64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803DB14: .4byte gCurrentPinballGame
_0803DB18: .4byte 0x000004FA
_0803DB1C: .4byte gMain
_0803DB20: .4byte 0x000004D2
_0803DB24: .4byte 0x040000D4
_0803DB28: .4byte gUnknown_084A11EC
_0803DB2C: .4byte 0x06010FA0
_0803DB30: .4byte 0x80000180
_0803DB34: .4byte 0x000004EC
_0803DB38: .4byte 0x000004E4
_0803DB3C: .4byte 0x000004EE
_0803DB40: .4byte gOamBuffer
_0803DB44: .4byte 0xFFFFFE00
_0803DB48: .4byte 0x000001FF
_0803DB4C: .4byte 0x000004CF
_0803DB50: .4byte gUnknown_086AF34C
_0803DB54: .4byte 0x000004CC
_0803DB58: .4byte gMain+0xFE8 @gMain.spriteGroups[18]
_0803DB5C: .4byte 0x0000048C
_0803DB60: .4byte _0803DB64
_0803DB64: @ jump table
	.4byte _0803DB90 @ case 0
	.4byte _0803DBD4 @ case 1
	.4byte _0803DC2C @ case 2
	.4byte _0803DC80 @ case 3
	.4byte _0803DCD8 @ case 4
	.4byte _0803DD2C @ case 5
	.4byte _0803DD84 @ case 6
	.4byte _0803DDD8 @ case 7
	.4byte _0803DE34 @ case 8
	.4byte _0803DEA8 @ case 9
	.4byte _0803DEF0 @ case 10
_0803DB90:
	ldr r2, _0803DBC8 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r4, [sp, #0x10]
	asrs r3, r4, #0x10
	ldr r5, _0803DBCC @ =0x0000049C
	adds r0, r0, r5
	adds r0, r0, r3
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r2]
	movs r6, #0x92
	lsls r6, r6, #3
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #8
	strb r1, [r0]
	ldr r0, [r2]
	ldr r7, _0803DBD0 @ =0x00000494
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r0, r1
	b _0803DEDE
	.align 2, 0
_0803DBC8: .4byte gCurrentPinballGame
_0803DBCC: .4byte 0x0000049C
_0803DBD0: .4byte 0x00000494
_0803DBD4:
	ldr r2, _0803DC1C @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r4, [sp, #0x10]
	asrs r3, r4, #0x10
	ldr r5, _0803DC20 @ =0x0000049C
	adds r1, r1, r5
	adds r1, r1, r3
	movs r0, #8
	strb r0, [r1]
	ldr r0, [r2]
	movs r6, #0x92
	lsls r6, r6, #3
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #0xc
	strb r1, [r0]
	ldr r0, [r2]
	ldr r7, _0803DC24 @ =0x00000494
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _0803DC28 @ =0x0000048C
	adds r0, r0, r2
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	b _0803DF08
	.align 2, 0
_0803DC1C: .4byte gCurrentPinballGame
_0803DC20: .4byte 0x0000049C
_0803DC24: .4byte 0x00000494
_0803DC28: .4byte 0x0000048C
_0803DC2C:
	ldr r5, _0803DC70 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r3, [sp, #0x10]
	asrs r4, r3, #0x10
	ldr r6, _0803DC74 @ =0x000004A4
	adds r0, r0, r6
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0803DC46
	b _0803DF08
_0803DC46:
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	beq _0803DC5C
	b _0803DF08
_0803DC5C:
	ldr r0, _0803DC78 @ =0x00000123
	bl m4aSongNumStart
	ldr r0, [r5]
	ldr r7, _0803DC7C @ =0x0000048C
	adds r0, r0, r7
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	b _0803DE98
	.align 2, 0
_0803DC70: .4byte gCurrentPinballGame
_0803DC74: .4byte 0x000004A4
_0803DC78: .4byte 0x00000123
_0803DC7C: .4byte 0x0000048C
_0803DC80:
	ldr r2, _0803DCC8 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r0, [sp, #0x10]
	asrs r3, r0, #0x10
	ldr r4, _0803DCCC @ =0x0000049C
	adds r1, r1, r4
	adds r1, r1, r3
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r2]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #0x10
	strb r1, [r0]
	ldr r0, [r2]
	ldr r6, _0803DCD0 @ =0x00000494
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r2]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _0803DCD4 @ =0x0000048C
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #4
	strb r1, [r0]
	b _0803DF08
	.align 2, 0
_0803DCC8: .4byte gCurrentPinballGame
_0803DCCC: .4byte 0x0000049C
_0803DCD0: .4byte 0x00000494
_0803DCD4: .4byte 0x0000048C
_0803DCD8:
	ldr r5, _0803DD1C @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r2, [sp, #0x10]
	asrs r4, r2, #0x10
	ldr r3, _0803DD20 @ =0x000004A4
	adds r0, r0, r3
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0803DCF2
	b _0803DF08
_0803DCF2:
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r3
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	beq _0803DD08
	b _0803DF08
_0803DD08:
	ldr r0, _0803DD24 @ =0x00000123
	bl m4aSongNumStart
	ldr r0, [r5]
	ldr r5, _0803DD28 @ =0x0000048C
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #5
	strb r1, [r0]
	b _0803DE98
	.align 2, 0
_0803DD1C: .4byte gCurrentPinballGame
_0803DD20: .4byte 0x000004A4
_0803DD24: .4byte 0x00000123
_0803DD28: .4byte 0x0000048C
_0803DD2C:
	ldr r2, _0803DD74 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r6, [sp, #0x10]
	asrs r3, r6, #0x10
	ldr r7, _0803DD78 @ =0x0000049C
	adds r1, r1, r7
	adds r1, r1, r3
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, [r2]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0x14
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _0803DD7C @ =0x00000494
	adds r0, r0, r4
	adds r0, r0, r3
	movs r1, #7
	strb r1, [r0]
	ldr r0, [r2]
	movs r5, #0x94
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, [r2]
	ldr r6, _0803DD80 @ =0x0000048C
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	b _0803DF08
	.align 2, 0
_0803DD74: .4byte gCurrentPinballGame
_0803DD78: .4byte 0x0000049C
_0803DD7C: .4byte 0x00000494
_0803DD80: .4byte 0x0000048C
_0803DD84:
	ldr r6, _0803DDC8 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r7, [sp, #0x10]
	asrs r5, r7, #0x10
	ldr r1, _0803DDCC @ =0x000004A4
	adds r0, r0, r1
	adds r1, r0, r5
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0803DD9E
	b _0803DF08
_0803DD9E:
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, _0803DDCC @ =0x000004A4
	adds r0, r0, r2
	adds r0, r0, r5
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #7
	beq _0803DDB4
	b _0803DF08
_0803DDB4:
	ldr r0, _0803DDD0 @ =0x00000123
	bl m4aSongNumStart
	ldr r0, [r6]
	ldr r3, _0803DDD4 @ =0x0000048C
	adds r0, r0, r3
	adds r0, r0, r5
	strb r4, [r0]
	b _0803DE98
	.align 2, 0
_0803DDC8: .4byte gCurrentPinballGame
_0803DDCC: .4byte 0x000004A4
_0803DDD0: .4byte 0x00000123
_0803DDD4: .4byte 0x0000048C
_0803DDD8:
	ldr r2, _0803DE28 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r4, [sp, #0x10]
	asrs r3, r4, #0x10
	ldr r5, _0803DE2C @ =0x0000049C
	adds r1, r1, r5
	adds r1, r1, r3
	movs r4, #0
	movs r0, #0x14
	strb r0, [r1]
	ldr r0, [r2]
	movs r6, #0x92
	lsls r6, r6, #3
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #0x18
	strb r1, [r0]
	ldr r0, [r2]
	ldr r7, _0803DE30 @ =0x00000494
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #9
	strb r1, [r0]
	ldr r0, [r2]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, [r2]
	subs r5, #0x10
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #8
	strb r1, [r0]
	ldr r0, [r2]
	adds r6, #0x18
	adds r0, r0, r6
	b _0803DEDE
	.align 2, 0
_0803DE28: .4byte gCurrentPinballGame
_0803DE2C: .4byte 0x0000049C
_0803DE30: .4byte 0x00000494
_0803DE34:
	ldr r4, _0803DE7C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r7, [sp, #0x10]
	asrs r3, r7, #0x10
	ldr r1, _0803DE80 @ =0x000004A4
	adds r0, r0, r1
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _0803DF08
	subs r0, r2, #1
	movs r5, #0
	strb r0, [r1]
	ldr r1, [r4]
	ldr r2, _0803DE80 @ =0x000004A4
	adds r0, r1, r2
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _0803DF08
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r1, r6
	adds r1, r0, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0803DE84
	adds r0, r2, #1
	strb r0, [r1]
	b _0803DE92
	.align 2, 0
_0803DE7C: .4byte gCurrentPinballGame
_0803DE80: .4byte 0x000004A4
_0803DE84:
	strb r5, [r1]
	ldr r0, [r4]
	ldr r7, _0803DEA0 @ =0x0000048C
	adds r0, r0, r7
	adds r0, r0, r3
	movs r1, #9
	strb r1, [r0]
_0803DE92:
	ldr r0, _0803DEA4 @ =0x00000123
	bl m4aSongNumStart
_0803DE98:
	movs r0, #7
	bl sub_11B0
	b _0803DF08
	.align 2, 0
_0803DEA0: .4byte 0x0000048C
_0803DEA4: .4byte 0x00000123
_0803DEA8:
	ldr r2, _0803DEE4 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r0, [sp, #0x10]
	asrs r3, r0, #0x10
	ldr r4, _0803DEE8 @ =0x0000049C
	adds r1, r1, r4
	adds r1, r1, r3
	movs r4, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, [r2]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #0x1b
	strb r1, [r0]
	ldr r0, [r2]
	ldr r6, _0803DEEC @ =0x00000494
	adds r0, r0, r6
	adds r0, r0, r3
	movs r1, #0xa
	strb r1, [r0]
	ldr r0, [r2]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r0, r7
_0803DEDE:
	adds r0, r0, r3
	strb r4, [r0]
	b _0803DF08
	.align 2, 0
_0803DEE4: .4byte gCurrentPinballGame
_0803DEE8: .4byte 0x0000049C
_0803DEEC: .4byte 0x00000494
_0803DEF0:
	ldr r2, _0803DF3C @ =gMain
	ldr r1, [sp, #0x10]
	asrs r0, r1, #0x10
	adds r0, #0x12
	movs r1, #0xb8
	muls r0, r1, r0
	adds r0, r0, r2
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
_0803DF08:
	ldr r4, _0803DF40 @ =gUnknown_086AF2DC
	ldr r3, _0803DF44 @ =gCurrentPinballGame
	ldr r2, [r3]
	ldr r6, [sp, #0x10]
	asrs r5, r6, #0x10
	movs r7, #0x93
	lsls r7, r7, #3
	adds r0, r2, r7
	adds r7, r0, r5
	movs r1, #0
	ldrsb r1, [r7, r1]
	lsls r1, r1, #2
	adds r0, r4, #2
	adds r1, r1, r0
	lsls r0, r5, #1
	ldr r6, _0803DF48 @ =0x000004AC
	adds r2, r2, r6
	adds r2, r2, r0
	ldrh r6, [r2]
	ldrh r0, [r1]
	cmp r0, r6
	bls _0803DF4C
	adds r0, r6, #1
	strh r0, [r2]
	b _0803DFC8
	.align 2, 0
_0803DF3C: .4byte gMain
_0803DF40: .4byte gUnknown_086AF2DC
_0803DF44: .4byte gCurrentPinballGame
_0803DF48: .4byte 0x000004AC
_0803DF4C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	ldr r7, _0803DFA8 @ =gCurrentPinballGame
	ldr r2, [r7]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r3, r0, r5
	movs r6, #0x92
	lsls r6, r6, #3
	adds r0, r2, r6
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	ldrb r6, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0803DFC8
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r2, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0803DFB0
	ldr r1, _0803DFAC @ =0x0000049C
	adds r0, r2, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, _0803DFA8 @ =gCurrentPinballGame
	ldr r1, [r2]
	adds r3, r7, #0
	adds r1, r1, r3
	adds r1, r1, r5
	ldrb r0, [r1]
	subs r0, #1
	b _0803DFC6
	.align 2, 0
_0803DFA8: .4byte gCurrentPinballGame
_0803DFAC: .4byte 0x0000049C
_0803DFB0:
	subs r0, r6, #1
	strb r0, [r3]
	ldr r6, _0803E0EC @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r7, _0803E0F0 @ =0x0000048C
	adds r1, r0, r7
	adds r1, r1, r5
	ldr r2, _0803E0F4 @ =0x00000494
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
_0803DFC6:
	strb r0, [r1]
_0803DFC8:
	ldr r3, _0803E0EC @ =gCurrentPinballGame
	ldr r2, [r3]
	ldr r6, [sp, #0x10]
	asrs r5, r6, #0x10
	movs r7, #0x93
	lsls r7, r7, #3
	adds r0, r2, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	mov sl, r0
	ldr r0, _0803E0F8 @ =gUnknown_086AF2CC
	lsls r4, r5, #2
	adds r3, r4, r0
	ldrh r1, [r3]
	adds r1, #0x41
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r0, [sp, #4]
	strh r1, [r0, #2]
	ldrh r1, [r3, #2]
	adds r1, #0x3c
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r6, [sp, #4]
	strh r1, [r6, #4]
	subs r7, #0xc
	adds r0, r2, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bgt _0803E03A
	adds r2, r2, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r0, #0x3d
	lsls r0, r0, #1
	ldr r4, _0803E0FC @ =0x000004B4
	adds r1, r2, r4
	strh r0, [r1]
	movs r6, #2
	ldrsh r0, [r3, r6]
	adds r0, #0x60
	lsls r0, r0, #1
	adds r7, #0x2a
	adds r2, r2, r7
	strh r0, [r2]
_0803E03A:
	ldr r1, _0803E0EC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0803E100 @ =0x000004A4
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0803E114
	movs r2, #0
	mov r3, sl
	lsls r1, r3, #0x10
	ldr r4, _0803E104 @ =gUnknown_086B8AE0
	mov sb, r4
	ldr r5, _0803E108 @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r6, _0803E10C @ =0xFFFFFE00
	mov r8, r6
_0803E068:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r7, [sp, #4]
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r2, r0, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, sl
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
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
	ldr r7, _0803E110 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrb r1, [r2, #5]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2, #5]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #9
	ble _0803E068
	b _0803E1C4
	.align 2, 0
_0803E0EC: .4byte gCurrentPinballGame
_0803E0F0: .4byte 0x0000048C
_0803E0F4: .4byte 0x00000494
_0803E0F8: .4byte gUnknown_086AF2CC
_0803E0FC: .4byte 0x000004B4
_0803E100: .4byte 0x000004A4
_0803E104: .4byte gUnknown_086B8AE0
_0803E108: .4byte gOamBuffer
_0803E10C: .4byte 0xFFFFFE00
_0803E110: .4byte 0x000001FF
_0803E114:
	movs r2, #0
	mov r5, sl
	lsls r1, r5, #0x10
	ldr r6, _0803E1A0 @ =gUnknown_086B8AE0
	mov sb, r6
	ldr r5, _0803E1A4 @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r7, _0803E1A8 @ =0xFFFFFE00
	mov r8, r7
_0803E12E:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r1, [sp, #4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r2, r0, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	mov r4, sl
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov ip, r1
	ldr r7, [sp, #4]
	movs r1, #2
	ldrsh r0, [r7, r1]
	mov r7, ip
	adds r1, r7, r0
	ldr r7, _0803E1AC @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #9
	ble _0803E12E
	b _0803E1C4
	.align 2, 0
_0803E1A0: .4byte gUnknown_086B8AE0
_0803E1A4: .4byte gOamBuffer
_0803E1A8: .4byte 0xFFFFFE00
_0803E1AC: .4byte 0x000001FF
_0803E1B0:
	ldr r5, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r0, r0, r1
	ldr r6, _0803E2C0 @ =0x000004B4
	adds r1, r0, r6
	strh r3, [r1]
	ldr r7, _0803E2C4 @ =0x000004B6
	adds r0, r0, r7
	strh r3, [r0]
_0803E1C4:
	ldr r1, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r1, r2
	lsrs r3, r0, #0x10
	str r3, [sp]
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _0803E1D8
	b _0803DAD6
_0803E1D8:
	ldr r4, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r4, _0803E2C8 @ =0x000004C4
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0803E236
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x24
	bne _0803E1FA
	movs r0, #0x91
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803E1FA:
	ldr r5, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x18
	bne _0803E20E
	movs r0, #0x91
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803E20E:
	ldr r6, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r6]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0xc
	bne _0803E222
	movs r0, #0x91
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803E222:
	ldr r7, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r7]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803E236
	movs r0, #0x91
	lsls r0, r0, #1
	bl m4aSongNumStart
_0803E236:
	ldr r0, _0803E2CC @ =gMain+0x1888 @gMain.spriteGroups[30]
	str r0, [sp, #4]
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803E242
	b _0803E574
_0803E242:
	ldr r0, _0803E2BC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r6, _0803E2D0 @ =0x00000456
	adds r7, r1, r6
	ldrh r1, [r7]
	cmp r1, #0x23
	bhi _0803E300
	adds r0, r1, #0
	lsls r0, r0, #9
	movs r1, #0x23
	bl __divsi3
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0803E26C
	adds r7, r1, #0
_0803E26C:
	lsls r5, r7, #0x10
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
	ldr r1, _0803E2BC @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r1, r0, r6
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _0803E2D4
	subs r0, #0x1e
	movs r1, #0xb
	muls r0, r1, r0
	movs r1, #5
	bl __divsi3
	movs r1, #0xc
	b _0803E2E0
	.align 2, 0
_0803E2BC: .4byte gCurrentPinballGame
_0803E2C0: .4byte 0x000004B4
_0803E2C4: .4byte 0x000004B6
_0803E2C8: .4byte 0x000004C4
_0803E2CC: .4byte gMain+0x1888 @gMain.spriteGroups[30]
_0803E2D0: .4byte 0x00000456
_0803E2D4:
	ldrh r0, [r1]
	lsls r0, r0, #2
	movs r1, #0x1e
	bl __divsi3
	movs r1, #0x10
_0803E2E0:
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r2, _0803E2F8 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _0803E2FC @ =0x00000456
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0803E30A
	.align 2, 0
_0803E2F8: .4byte gCurrentPinballGame
_0803E2FC: .4byte 0x00000456
_0803E300:
	movs r7, #0x80
	lsls r7, r7, #1
	movs r6, #0
	ldr r4, [sp, #4]
	strh r6, [r4]
_0803E30A:
	ldr r5, _0803E584 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r1, _0803E588 @ =0x00000456
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, _0803E58C @ =gMain
	mov r8, r2
	lsls r7, r7, #0x10
	mov sl, r7
	cmp r0, #0x22
	bne _0803E382
	movs r3, #0
	str r3, [sp]
	mov sb, r8
	movs r4, #0
	movs r7, #0
	adds r3, r5, #0
_0803E32C:
	ldr r5, [sp]
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	adds r1, r2, #0
	adds r1, #0x12
	movs r0, #0xb8
	muls r0, r1, r0
	add r0, sb
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r3]
	ldr r5, _0803E590 @ =0x0000048C
	adds r0, r0, r5
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r3]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r3]
	lsls r1, r2, #1
	adds r5, #0x20
	adds r0, r0, r5
	adds r0, r0, r1
	strh r7, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	str r0, [sp]
	asrs r2, r2, #0x10
	cmp r2, #3
	ble _0803E32C
	ldr r1, _0803E584 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0803E594 @ =0x000004C4
	adds r0, r0, r2
	movs r1, #0x25
	strh r1, [r0]
_0803E382:
	ldr r3, _0803E584 @ =gCurrentPinballGame
	ldr r1, [r3]
	mov r4, sl
	asrs r5, r4, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0803E392
	adds r0, r5, #7
_0803E392:
	asrs r3, r0, #3
	movs r0, #0x20
	subs r2, r0, r3
	ldr r7, _0803E598 @ =0x0000046C
	adds r0, r1, r7
	strh r2, [r0]
	adds r3, #0x20
	movs r4, #0x8e
	lsls r4, r4, #3
	adds r0, r1, r4
	strh r3, [r0]
	ldr r7, _0803E59C @ =0x00000474
	adds r0, r1, r7
	strh r2, [r0]
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r0, r1, r4
	strh r3, [r0]
	ldr r7, _0803E5A0 @ =0x0000046E
	adds r0, r1, r7
	strh r2, [r0]
	ldr r4, _0803E5A4 @ =0x00000472
	adds r0, r1, r4
	strh r2, [r0]
	ldr r7, _0803E5A8 @ =0x00000476
	adds r0, r1, r7
	strh r3, [r0]
	ldr r2, _0803E5AC @ =0x0000047A
	adds r0, r1, r2
	strh r3, [r0]
	mov r3, r8
	ldrb r1, [r3, #0xf]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _0803E3F0
	ldrh r0, [r3, #0x38]
	ldr r0, _0803E5B0 @ =0x00001E10
	strh r0, [r3, #0x38]
	movs r0, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r0, r1
	ldrh r1, [r3, #0x3a]
	strh r0, [r3, #0x3a]
_0803E3F0:
	ldr r4, [sp, #4]
	ldrh r0, [r4]
	cmp r0, #0
	beq _0803E4AA
	ldr r5, _0803E584 @ =gCurrentPinballGame
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x17
	subs r0, r0, r2
	strh r0, [r4, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r0, #0x32
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldr r7, _0803E5B4 @ =gOamBuffer
	ldr r6, _0803E5B8 @ =0xFFFFFE00
	mov sb, r6
	movs r0, #0xf
	rsbs r0, r0, #0
	mov r8, r0
_0803E420:
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	lsls r0, r5, #3
	adds r0, #8
	ldr r1, [sp, #4]
	adds r6, r1, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldr r4, [sp, #4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	ldr r0, _0803E584 @ =gCurrentPinballGame
	ldr r4, [r0]
	lsls r0, r5, #2
	adds r4, r4, r0
	ldr r2, _0803E598 @ =0x0000046C
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _0803E5BC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldr r3, [sp, #4]
	ldrb r1, [r3, #4]
	ldrb r0, [r6, #4]
	adds r1, r1, r0
	ldr r3, _0803E5A0 @ =0x0000046E
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
	ble _0803E420
_0803E4AA:
	ldr r4, _0803E584 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _0803E588 @ =0x00000456
	adds r4, r2, r5
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _0803E560
	ldr r7, _0803E5C0 @ =0x0000132C
	adds r0, r2, r7
	ldr r1, [r0]
	movs r6, #0x10
	ldrsh r0, [r1, r6]
	subs r0, #0x77
	str r0, [sp, #8]
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	subs r0, #0x93
	str r0, [sp, #0xc]
	ldr r5, [sp, #8]
	adds r1, r5, #0
	muls r1, r5, r1
	adds r6, r0, #0
	adds r0, r6, #0
	muls r0, r6, r0
	adds r3, r1, r0
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803E560
	ldr r0, _0803E5C4 @ =gUnknown_086AEE20
	ldrh r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bge _0803E560
	rsbs r0, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r3, r6, #0
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	ldr r4, _0803E584 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r1, r1, r6
	strh r0, [r1]
	ldrh r0, [r1]
	bl Cos
	adds r1, r0, #0
	ldr r4, [r4]
	adds r0, r4, r7
	ldr r5, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #4
	rsbs r0, r0, #0
	ldr r1, _0803E5C8 @ =0x00004E20
	bl __divsi3
	strh r0, [r5, #0x30]
	adds r4, r4, r6
	ldrh r0, [r4]
	bl Sin
	ldr r5, _0803E584 @ =gCurrentPinballGame
	ldr r1, [r5]
	adds r1, r1, r7
	ldr r4, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	bl __divsi3
	strh r0, [r4, #0x32]
	movs r0, #9
	bl sub_11B0
_0803E560:
	ldr r2, _0803E58C @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0803E574
	ldr r6, _0803E5CC @ =0x00001888
	adds r1, r2, r6
	movs r0, #0
	strh r0, [r1]
_0803E574:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E584: .4byte gCurrentPinballGame
_0803E588: .4byte 0x00000456
_0803E58C: .4byte gMain
_0803E590: .4byte 0x0000048C
_0803E594: .4byte 0x000004C4
_0803E598: .4byte 0x0000046C
_0803E59C: .4byte 0x00000474
_0803E5A0: .4byte 0x0000046E
_0803E5A4: .4byte 0x00000472
_0803E5A8: .4byte 0x00000476
_0803E5AC: .4byte 0x0000047A
_0803E5B0: .4byte 0x00001E10
_0803E5B4: .4byte gOamBuffer
_0803E5B8: .4byte 0xFFFFFE00
_0803E5BC: .4byte 0x000001FF
_0803E5C0: .4byte 0x0000132C
_0803E5C4: .4byte gUnknown_086AEE20
_0803E5C8: .4byte 0x00004E20
_0803E5CC: .4byte 0x00001888

	thumb_func_start sub_3E5D0
sub_3E5D0: @ 0x0803E5D0
	push {r4, r5, r6, r7, lr}
	ldr r6, _0803E634 @ =gMain+0x1888 @gMain.spriteGroups[30]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0803E62E
	movs r0, #0xf0
	strh r0, [r6, #2]
	movs r0, #0xa0
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _0803E638 @ =gOamBuffer
	ldr r1, _0803E63C @ =0xFFFFFE00
	mov ip, r1
_0803E5EA:
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
	ldr r2, _0803E640 @ =0x000001FF
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
	ble _0803E5EA
_0803E62E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E634: .4byte gMain+0x1888 @gMain.spriteGroups[30]
_0803E638: .4byte gOamBuffer
_0803E63C: .4byte 0xFFFFFE00
_0803E640: .4byte 0x000001FF

	thumb_func_start sub_3E644
sub_3E644: @ 0x0803E644
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0803E760 @ =gUnknown_086AF3B2
	ldr r6, _0803E764 @ =gMain
	ldr r5, [r6, #0x4c]
	adds r0, r5, #0
	movs r1, #0x90
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r2, _0803E768 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #5
	ldr r4, _0803E76C @ =gUnknown_08352BD8
	adds r0, r0, r4
	str r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r2, #4]
	ldr r3, _0803E770 @ =0x80000010
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	adds r1, #4
	lsls r1, r1, #5
	adds r1, r1, r4
	str r1, [r2]
	ldr r0, _0803E774 @ =0x05000080
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	ldr r4, _0803E778 @ =gUnknown_086AF3BE
	adds r0, r5, #0
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldr r7, _0803E77C @ =gOamBuffer
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	mov r8, r0
	ldr r2, _0803E780 @ =gUnknown_086AF3C6
	mov sb, r2
	ldr r0, _0803E784 @ =0xFFFFFC00
	mov sl, r0
_0803E6B8:
	lsls r3, r3, #0x10
	asrs r1, r3, #0x10
	movs r0, #0xb8
	muls r0, r1, r0
	ldr r1, _0803E788 @ =gMain+0xAE0 @gMain.spriteGroups[11]
	adds r6, r0, r1
	ldr r2, _0803E78C @ =gCurrentPinballGame
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
	movs r0, #0
	mov ip, r3
_0803E6E2:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	adds r4, r6, r4
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r7
	movs r3, #2
	ldrsh r1, [r4, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0803E790 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0803E794 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r0, r5, #1
	add r0, sb
	ldrh r1, [r0]
	add r1, r8
	ldr r3, _0803E798 @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #2
	ble _0803E6E2
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, ip
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0803E6B8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E760: .4byte gUnknown_086AF3B2
_0803E764: .4byte gMain
_0803E768: .4byte 0x040000D4
_0803E76C: .4byte gUnknown_08352BD8
_0803E770: .4byte 0x80000010
_0803E774: .4byte 0x05000080
_0803E778: .4byte gUnknown_086AF3BE
_0803E77C: .4byte gOamBuffer
_0803E780: .4byte gUnknown_086AF3C6
_0803E784: .4byte 0xFFFFFC00
_0803E788: .4byte gMain+0xAE0 @gMain.spriteGroups[11]
_0803E78C: .4byte gCurrentPinballGame
_0803E790: .4byte 0x000001FF
_0803E794: .4byte 0xFFFFFE00
_0803E798: .4byte 0x000003FF

	thumb_func_start sub_3E79C
sub_3E79C: @ 0x0803E79C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0803E7FC @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0xa
	bl __umodsi3
	movs r4, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bge _0803E7C8
	adds r5, r0, #0
_0803E7B4:
	bl Random
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	blt _0803E7B4
_0803E7C8:
	ldr r4, _0803E800 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	strb r2, [r1, #0x17]
	ldr r0, [r4]
	strb r2, [r0, #0x13]
	ldr r5, [r4]
	ldr r2, _0803E804 @ =0x00000283
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r4, #0
	cmp r0, #9
	bne _0803E808
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0x12
	b _0803E810
	.align 2, 0
_0803E7FC: .4byte gMain
_0803E800: .4byte gCurrentPinballGame
_0803E804: .4byte 0x00000283
_0803E808:
	movs r4, #0xe1
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xf
_0803E810:
	strb r0, [r1]
	ldr r0, [r6]
	movs r5, #0xa5
	lsls r5, r5, #2
	adds r0, r0, r5
	movs r3, #0
	strb r3, [r0]
	ldr r1, [r6]
	adds r4, r1, #0
	adds r4, #0x6c
	ldr r7, _0803EAB4 @ =0x00002A30
	adds r0, r7, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	adds r5, #2
	adds r2, r1, r5
	movs r5, #0
	strh r0, [r2]
	strh r3, [r4]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r1, r1, r7
	movs r4, #3
	strb r4, [r1]
	ldr r0, [r6]
	ldr r2, _0803EAB8 @ =0x00000392
	adds r1, r0, r2
	strh r3, [r1]
	ldr r7, _0803EABC @ =0x0000132C
	adds r0, r0, r7
	ldr r0, [r0]
	movs r2, #1
	strb r2, [r0]
	ldr r0, [r6]
	movs r1, #0xe6
	adds r1, r1, r0
	mov ip, r1
	ldr r1, _0803EAC0 @ =0x0000FFA8
	mov r7, ip
	strh r1, [r7]
	ldr r1, _0803EAC4 @ =0x00000387
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	ldr r2, _0803EAC8 @ =0x000006C4
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r6]
	ldr r4, _0803EACC @ =0x00000382
	adds r0, r0, r4
	strb r5, [r0]
	ldr r0, [r6]
	ldr r7, _0803EAD0 @ =0x00000383
	adds r0, r0, r7
	strb r5, [r0]
	ldr r0, [r6]
	subs r1, #2
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r6]
	ldr r2, _0803EAD4 @ =0x00000386
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r6]
	adds r4, #7
	adds r0, r0, r4
	strb r5, [r0]
	ldr r0, [r6]
	ldr r5, _0803EAD8 @ =0x0000038A
	adds r1, r0, r5
	strh r3, [r1]
	adds r7, #9
	adds r1, r0, r7
	strh r3, [r1]
	adds r2, #8
	adds r1, r0, r2
	strh r3, [r1]
	adds r4, #7
	adds r1, r0, r4
	strh r3, [r1]
	adds r5, #0xa
	adds r0, r0, r5
	strh r3, [r0]
	movs r4, #0
	mov ip, r6
	adds r7, #0x38
	adds r5, #0x32
_0803E8BE:
	mov r0, ip
	ldr r2, [r0]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #2
	adds r2, r2, r1
	adds r1, r2, r7
	strh r3, [r1]
	adds r2, r2, r5
	strh r3, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0803E8BE
	ldr r0, [r6]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r6]
	ldr r3, _0803EADC @ =0x000003DD
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r6]
	ldr r4, _0803EAE0 @ =0x000003DE
	adds r0, r0, r4
	strb r2, [r0]
	ldr r0, [r6]
	ldr r5, _0803EAE4 @ =0x000003DF
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r6]
	movs r7, #0xf8
	lsls r7, r7, #2
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r6]
	adds r3, #5
	adds r1, r0, r3
	movs r3, #0
	strh r2, [r1]
	adds r4, #3
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r6]
	adds r5, #5
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #6
	adds r1, r0, r7
	strh r2, [r1]
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #9
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r2, [r1]
	adds r3, #8
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #8
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #0x28
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #0x28
	adds r1, r0, r7
	strh r2, [r1]
	adds r3, #0x28
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #0x28
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #0x3e
	adds r0, r0, r5
	strh r2, [r0]
	movs r4, #0
	adds r7, r6, #0
	movs r5, #0
_0803E974:
	ldr r0, [r7]
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	ldr r1, _0803EAE8 @ =0x00000441
	adds r0, r0, r1
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r7]
	ldr r3, _0803EAEC @ =0x00000443
	adds r0, r0, r3
	adds r0, r0, r2
	strb r5, [r0]
	ldr r1, [r7]
	lsls r3, r2, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r1, r4
	adds r0, r0, r3
	strh r5, [r0]
	lsls r0, r2, #2
	adds r1, r1, r0
	ldr r3, _0803EAF0 @ =0x0000045C
	adds r0, r1, r3
	strh r5, [r0]
	adds r4, #6
	adds r0, r1, r4
	strh r5, [r0]
	adds r3, #8
	adds r0, r1, r3
	strh r5, [r0]
	adds r4, #8
	adds r1, r1, r4
	strh r5, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0803E974
	ldr r0, [r6]
	movs r5, #0x99
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r6]
	ldr r7, _0803EAF4 @ =0x0000047F
	adds r0, r0, r7
	strb r2, [r0]
	ldr r1, [r6]
	adds r3, #0x1c
	adds r0, r1, r3
	movs r3, #0
	strh r2, [r0]
	ldr r4, _0803EAF8 @ =0x00000486
	adds r0, r1, r4
	strh r2, [r0]
	adds r5, #0x3c
	adds r1, r1, r5
	strb r3, [r1]
	ldr r0, [r6]
	adds r7, #0x86
	adds r0, r0, r7
	strb r3, [r0]
	ldr r0, [r6]
	ldr r1, _0803EAFC @ =0x00000506
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r6]
	adds r4, #0x81
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r6]
	adds r5, #4
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #5
	adds r1, r0, r7
	strh r2, [r1]
	ldr r3, _0803EB00 @ =0x0000050C
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #7
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r2, [r1]
	adds r3, #8
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #8
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r2, [r1]
	adds r3, #8
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #8
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r2, [r1]
	adds r3, #8
	adds r1, r0, r3
	strh r2, [r1]
	adds r4, #8
	adds r1, r0, r4
	strh r2, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r2, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r2, [r1]
	movs r1, #1
	strb r1, [r0, #0x1a]
	bl sub_423D8
	ldr r4, _0803EB04 @ =0x040000D4
	ldr r0, _0803EB08 @ =gUnknown_083C5A2C
	str r0, [r4]
	ldr r0, _0803EB0C @ =0x06015800
	str r0, [r4, #4]
	ldr r0, _0803EB10 @ =0x80001400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0803EB14 @ =gUnknown_084AA18C
	str r0, [r4]
	ldr r0, _0803EB18 @ =0x06011620
	str r0, [r4, #4]
	ldr r0, _0803EB1C @ =0x80000430
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_3EDF0
	bl sub_3FAE0
	ldr r0, _0803EB20 @ =gUnknown_081B36A4
	str r0, [r4]
	ldr r0, _0803EB24 @ =0x05000320
	str r0, [r4, #4]
	ldr r0, _0803EB28 @ =0x80000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EAB4: .4byte 0x00002A30
_0803EAB8: .4byte 0x00000392
_0803EABC: .4byte 0x0000132C
_0803EAC0: .4byte 0x0000FFA8
_0803EAC4: .4byte 0x00000387
_0803EAC8: .4byte 0x000006C4
_0803EACC: .4byte 0x00000382
_0803EAD0: .4byte 0x00000383
_0803EAD4: .4byte 0x00000386
_0803EAD8: .4byte 0x0000038A
_0803EADC: .4byte 0x000003DD
_0803EAE0: .4byte 0x000003DE
_0803EAE4: .4byte 0x000003DF
_0803EAE8: .4byte 0x00000441
_0803EAEC: .4byte 0x00000443
_0803EAF0: .4byte 0x0000045C
_0803EAF4: .4byte 0x0000047F
_0803EAF8: .4byte 0x00000486
_0803EAFC: .4byte 0x00000506
_0803EB00: .4byte 0x0000050C
_0803EB04: .4byte 0x040000D4
_0803EB08: .4byte gUnknown_083C5A2C
_0803EB0C: .4byte 0x06015800
_0803EB10: .4byte 0x80001400
_0803EB14: .4byte gUnknown_084AA18C
_0803EB18: .4byte 0x06011620
_0803EB1C: .4byte 0x80000430
_0803EB20: .4byte gUnknown_081B36A4
_0803EB24: .4byte 0x05000320
_0803EB28: .4byte 0x80000010

	thumb_func_start sub_3EB2C
sub_3EB2C: @ 0x0803EB2C
	push {r4, r5, lr}
	ldr r0, _0803EB48 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bls _0803EB3E
	b _0803ED6C
_0803EB3E:
	lsls r0, r0, #2
	ldr r1, _0803EB4C @ =_0803EB50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EB48: .4byte gCurrentPinballGame
_0803EB4C: .4byte _0803EB50
_0803EB50: @ jump table
	.4byte _0803EB6C @ case 0
	.4byte _0803ED6C @ case 1
	.4byte _0803EBA4 @ case 2
	.4byte _0803EC0C @ case 3
	.4byte _0803EC8C @ case 4
	.4byte _0803ECE8 @ case 5
	.4byte _0803ED54 @ case 6
_0803EB6C:
	ldr r3, _0803EB98 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r1, _0803EB9C @ =0x000005F7
	adds r0, r0, r1
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r3]
	ldr r2, _0803EBA0 @ =0x00000506
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	beq _0803EB8A
	b _0803ED6C
_0803EB8A:
	adds r0, r1, #0
	adds r0, #0xe6
	strh r4, [r0]
	strb r2, [r1, #0x13]
	ldr r0, [r3]
	strh r4, [r0, #0x18]
	b _0803ED6C
	.align 2, 0
_0803EB98: .4byte gCurrentPinballGame
_0803EB9C: .4byte 0x000005F7
_0803EBA0: .4byte 0x00000506
_0803EBA4:
	ldr r2, _0803EBF0 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r3, #0
	movs r0, #3
	strb r0, [r1, #0x13]
	ldr r2, [r2]
	strh r3, [r2, #0x18]
	ldr r3, _0803EBF4 @ =gMain
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
	ldr r1, _0803EBF8 @ =0x040000D4
	ldr r0, _0803EBFC @ =gUnknown_081408B4
	str r0, [r1]
	ldr r0, _0803EC00 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0803EC04 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x88
	strh r0, [r1]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	ldr r1, _0803EC08 @ =0x000005FA
	adds r2, r2, r1
	strb r4, [r2]
	b _0803ED6C
	.align 2, 0
_0803EBF0: .4byte gCurrentPinballGame
_0803EBF4: .4byte gMain
_0803EBF8: .4byte 0x040000D4
_0803EBFC: .4byte gUnknown_081408B4
_0803EC00: .4byte 0x06015800
_0803EC04: .4byte 0x80001000
_0803EC08: .4byte 0x000005FA
_0803EC0C:
	bl sub_351A8
	ldr r4, _0803EC54 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0803EC1E
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0803EC1E:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0803EC34
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r4]
	ldr r0, _0803EC58 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _0803EC5C @ =0x05F5E0FF
	str r0, [r1, #0x3c]
_0803EC34:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _0803EC60
	cmp r0, #0x14
	bne _0803EC4A
	bl m4aMPlayAllStop
	movs r0, MUS_SUCCESS3
	bl m4aSongNumStart
_0803EC4A:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _0803EC74
	.align 2, 0
_0803EC54: .4byte gCurrentPinballGame
_0803EC58: .4byte 0x00061A80
_0803EC5C: .4byte 0x05F5E0FF
_0803EC60:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r4]
	ldr r2, _0803EC80 @ =0x00000283
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803EC74:
	ldr r0, _0803EC84 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r4, _0803EC88 @ =0x000005FA
	adds r0, r0, r4
	movs r1, #1
	b _0803ED6A
	.align 2, 0
_0803EC80: .4byte 0x00000283
_0803EC84: .4byte gCurrentPinballGame
_0803EC88: .4byte 0x000005FA
_0803EC8C:
	ldr r2, _0803ECD0 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r0, #5
	strb r0, [r1, #0x13]
	ldr r2, [r2]
	movs r0, #0x8c
	strh r0, [r2, #0x18]
	ldr r3, _0803ECD4 @ =gMain
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #1
	strh r1, [r0]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r3, r4
	strh r1, [r0]
	ldr r1, _0803ECD8 @ =0x040000D4
	ldr r0, _0803ECDC @ =gUnknown_081408B4
	str r0, [r1]
	ldr r0, _0803ECE0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0803ECE4 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r2, r2, r5
	movs r0, #0x88
	strh r0, [r2]
	movs r0, #0x80
	strb r0, [r3, #0xf]
	b _0803ED6C
	.align 2, 0
_0803ECD0: .4byte gCurrentPinballGame
_0803ECD4: .4byte gMain
_0803ECD8: .4byte 0x040000D4
_0803ECDC: .4byte gUnknown_081408B4
_0803ECE0: .4byte 0x06015800
_0803ECE4: .4byte 0x80001000
_0803ECE8:
	bl sub_351A8
	ldr r3, _0803ED20 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0803ECFA
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0803ECFA:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0803ED10
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r3]
	ldr r0, _0803ED24 @ =0x00061A80
	str r0, [r1, #0x38]
	ldr r0, _0803ED28 @ =0x05F5E0FF
	str r0, [r1, #0x3c]
_0803ED10:
	ldr r1, [r3]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xef
	bhi _0803ED2C
	adds r0, #1
	strh r0, [r1, #0x18]
	b _0803ED6C
	.align 2, 0
_0803ED20: .4byte gCurrentPinballGame
_0803ED24: .4byte 0x00061A80
_0803ED28: .4byte 0x05F5E0FF
_0803ED2C:
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #6
	strb r0, [r1, #0x13]
	ldr r1, [r3]
	ldr r0, _0803ED4C @ =0x00000283
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _0803ED50 @ =0x000001AF
	adds r0, r0, r1
	strb r2, [r0]
	b _0803ED6C
	.align 2, 0
_0803ED4C: .4byte 0x00000283
_0803ED50: .4byte 0x000001AF
_0803ED54:
	bl sub_351A8
	ldr r2, _0803EDDC @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r4, _0803EDE0 @ =0x00000386
	adds r0, r0, r4
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _0803EDE4 @ =0x000005FA
	adds r0, r0, r5
_0803ED6A:
	strb r1, [r0]
_0803ED6C:
	bl sub_423D8
	bl sub_40288
	bl sub_3EDF0
	bl sub_3FAE0
	ldr r0, _0803EDDC @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803EDB4
	ldr r4, _0803EDE8 @ =0x00000296
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #1
	bhi _0803EDB4
	ldr r4, _0803EDEC @ =gMain
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0803EDB4
	bl m4aMPlayAllStop
	movs r0, MUS_END_OF_BALL3
	bl m4aSongNumStart
	ldrb r1, [r4, #0xf]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xf]
_0803EDB4:
	ldr r0, _0803EDDC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _0803EDE0 @ =0x00000386
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803EDD2
	ldr r0, _0803EDE4 @ =0x000005FA
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bl sub_350F0
_0803EDD2:
	bl sub_472E4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803EDDC: .4byte gCurrentPinballGame
_0803EDE0: .4byte 0x00000386
_0803EDE4: .4byte 0x000005FA
_0803EDE8: .4byte 0x00000296
_0803EDEC: .4byte gMain

	thumb_func_start sub_3EDF0
sub_3EDF0: @ 0x0803EDF0
	push {r4, r5, r6, r7, lr}
	ldr r0, _0803EE9C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _0803EEA0 @ =0x00000452
	adds r5, r1, r2
	ldrh r4, [r5]
	adds r6, r0, #0
	cmp r4, #0
	beq _0803EE80
	subs r0, r4, #1
	strh r0, [r5]
	ldr r3, _0803EEA4 @ =0x00000389
	adds r1, r1, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _0803EE60
	movs r0, #0x93
	lsls r0, r0, #1
	bl m4aSongNumStart
	ldr r1, [r6]
	ldr r0, _0803EEA8 @ =0x000F4240
	str r0, [r1, #0x3c]
	ldr r4, _0803EEAC @ =0x00000385
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #7
	bl sub_11B0
	ldr r2, [r6]
	adds r4, r2, r4
	movs r5, #0xe1
	lsls r5, r5, #2
	adds r0, r2, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _0803EE60
	movs r7, #0xf7
	lsls r7, r7, #2
	adds r1, r2, r7
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	beq _0803EE60
	movs r0, #9
	strb r0, [r1]
_0803EE60:
	ldr r2, _0803EE9C @ =gCurrentPinballGame
	ldr r5, [r2]
	ldr r0, _0803EEB0 @ =0x0000050C
	adds r1, r5, r0
	movs r0, #0x14
	strh r0, [r1]
	ldr r1, _0803EEA0 @ =0x00000452
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r6, r2, #0
	cmp r0, #0
	bne _0803EE80
	ldr r2, _0803EEA4 @ =0x00000389
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0803EE80:
	ldr r2, [r6]
	ldr r4, _0803EEB0 @ =0x0000050C
	adds r3, r2, r4
	ldrh r0, [r3]
	cmp r0, #0
	beq _0803EEB8
	subs r0, #1
	movs r1, #0
	strh r0, [r3]
	ldr r5, _0803EEB4 @ =0x00000387
	adds r0, r2, r5
	strb r1, [r0]
	b _0803EEC0
	.align 2, 0
_0803EE9C: .4byte gCurrentPinballGame
_0803EEA0: .4byte 0x00000452
_0803EEA4: .4byte 0x00000389
_0803EEA8: .4byte 0x000F4240
_0803EEAC: .4byte 0x00000385
_0803EEB0: .4byte 0x0000050C
_0803EEB4: .4byte 0x00000387
_0803EEB8:
	ldr r7, _0803EEE0 @ =0x00000387
	adds r1, r2, r7
	movs r0, #1
	strb r0, [r1]
_0803EEC0:
	ldr r0, [r6]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0803EED6
	bl _0803FA78
_0803EED6:
	lsls r0, r0, #2
	ldr r1, _0803EEE4 @ =_0803EEE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EEE0: .4byte 0x00000387
_0803EEE4: .4byte _0803EEE8
_0803EEE8: @ jump table
	.4byte _0803EF28 @ case 0
	.4byte _0803EF84 @ case 1
	.4byte _0803F00C @ case 2
	.4byte _0803F0A4 @ case 3
	.4byte _0803F154 @ case 4
	.4byte _0803F210 @ case 5
	.4byte _0803F334 @ case 6
	.4byte _0803F460 @ case 7
	.4byte _0803F550 @ case 8
	.4byte _0803F68C @ case 9
	.4byte _0803F788 @ case 10
	.4byte _0803F814 @ case 11
	.4byte _0803F8DC @ case 12
	.4byte _0803F9D0 @ case 13
	.4byte _0803FA2E @ case 14
	.4byte _0803FA78 @ case 15
_0803EF28:
	ldr r3, _0803EF74 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r2, r1, r4
	movs r5, #0
	movs r4, #0
	ldr r0, _0803EF78 @ =0x00000474
	strh r0, [r2]
	ldr r7, _0803EF7C @ =0x000003EA
	adds r2, r1, r7
	movs r0, #0x96
	lsls r0, r0, #4
	strh r0, [r2]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r3]
	subs r7, #8
	adds r2, r1, r7
	movs r0, #0xd
	strh r0, [r2]
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	subs r7, #1
	adds r1, r1, r7
	strb r5, [r1]
	ldr r0, [r3]
	ldr r1, _0803EF80 @ =0x0000051A
	adds r0, r0, r1
	strh r4, [r0]
	bl _0803FA78
	.align 2, 0
_0803EF74: .4byte gCurrentPinballGame
_0803EF78: .4byte 0x00000474
_0803EF7C: .4byte 0x000003EA
_0803EF80: .4byte 0x0000051A
_0803EF84:
	ldr r2, [r6]
	ldr r7, _0803EFF4 @ =0x00000516
	adds r0, r2, r7
	ldrh r1, [r0]
	ldr r0, _0803EFF8 @ =0x00000212
	cmp r1, r0
	bls _0803EFD2
	ldr r3, _0803EFFC @ =0x000003EA
	adds r2, r2, r3
	ldrh r5, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0803F000 @ =0xFFFFFB50
	cmp r1, r0
	ble _0803EFA8
	adds r0, r5, #0
	subs r0, #0x46
	strh r0, [r2]
_0803EFA8:
	ldr r2, [r6]
	adds r0, r2, r7
	ldrh r1, [r0]
	movs r0, #0xa8
	lsls r0, r0, #2
	cmp r1, r0
	bne _0803EFD2
	movs r5, #0xf7
	lsls r5, r5, #2
	adds r1, r2, r5
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r6]
	movs r7, #0xfa
	lsls r7, r7, #2
	adds r1, r0, r7
	strh r2, [r1]
	adds r0, r0, r3
	ldr r1, _0803F004 @ =0x0000FD80
	strh r1, [r0]
_0803EFD2:
	ldr r0, _0803F008 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r1, _0803EFF4 @ =0x00000516
	adds r0, r2, r1
	ldrh r1, [r0]
	ldr r0, _0803EFF8 @ =0x00000212
	cmp r1, r0
	beq _0803EFE6
	bl _0803FA78
_0803EFE6:
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #0x19
	strh r0, [r1]
	bl _0803FA78
	.align 2, 0
_0803EFF4: .4byte 0x00000516
_0803EFF8: .4byte 0x00000212
_0803EFFC: .4byte 0x000003EA
_0803F000: .4byte 0xFFFFFB50
_0803F004: .4byte 0x0000FD80
_0803F008: .4byte gCurrentPinballGame
_0803F00C:
	ldr r2, _0803F038 @ =gUnknown_086AF3CC
	ldr r3, [r6]
	ldr r4, _0803F03C @ =0x000003E2
	adds r5, r3, r4
	movs r7, #0
	ldrsh r1, [r5, r7]
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
	bls _0803F040
	adds r0, r2, #1
	strh r0, [r1]
	b _0803F056
	.align 2, 0
_0803F038: .4byte gUnknown_086AF3CC
_0803F03C: .4byte 0x000003E2
_0803F040:
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bne _0803F056
	movs r0, #0xd
	strh r0, [r5]
_0803F056:
	ldr r0, _0803F09C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r3, _0803F0A0 @ =0x000003EA
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge _0803F07E
	adds r0, r2, #0
	adds r0, #0x12
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0803F07E
	movs r0, #0
	strh r0, [r1]
	movs r0, MUS_BONUS_FIELD_RAYQUAZA
	bl m4aSongNumStart
_0803F07E:
	ldr r3, _0803F09C @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r5, _0803F0A0 @ =0x000003EA
	adds r0, r1, r5
	movs r7, #0
	ldrsh r2, [r0, r7]
	cmp r2, #0
	beq _0803F092
	bl _0803FA78
_0803F092:
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r1, r0
	b _0803F128
	.align 2, 0
_0803F09C: .4byte gCurrentPinballGame
_0803F0A0: .4byte 0x000003EA
_0803F0A4:
	ldr r2, _0803F0D0 @ =gUnknown_086AF3CC
	ldr r3, [r6]
	ldr r5, _0803F0D4 @ =0x000003E2
	adds r4, r3, r5
	movs r7, #0
	ldrsh r1, [r4, r7]
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
	bls _0803F0D8
	adds r0, r1, #1
	strh r0, [r3]
	b _0803F0EE
	.align 2, 0
_0803F0D0: .4byte gUnknown_086AF3CC
_0803F0D4: .4byte 0x000003E2
_0803F0D8:
	movs r0, #0
	strh r0, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bne _0803F0EE
	movs r0, #0xd
	strh r0, [r4]
_0803F0EE:
	ldr r0, [r6]
	ldr r2, _0803F144 @ =0x000003EA
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _0803F10E
	adds r0, r2, #0
	adds r0, #0x12
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0803F10E
	movs r0, #0
	strh r0, [r1]
_0803F10E:
	ldr r3, _0803F148 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r4, _0803F144 @ =0x000003EA
	adds r0, r1, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	cmp r2, #0
	beq _0803F122
	bl _0803FA78
_0803F122:
	movs r7, #0xf7
	lsls r7, r7, #2
	adds r1, r1, r7
_0803F128:
	movs r0, #5
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _0803F14C @ =0x000003E1
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	ldr r2, _0803F150 @ =0x000003DD
	adds r0, r0, r2
	movs r1, #6
	strb r1, [r0]
	bl _0803FA78
	.align 2, 0
_0803F144: .4byte 0x000003EA
_0803F148: .4byte gCurrentPinballGame
_0803F14C: .4byte 0x000003E1
_0803F150: .4byte 0x000003DD
_0803F154:
	ldr r2, _0803F180 @ =gUnknown_086AF3CC
	ldr r3, [r6]
	ldr r5, _0803F184 @ =0x000003E2
	adds r4, r3, r5
	movs r7, #0
	ldrsh r1, [r4, r7]
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
	bls _0803F188
	adds r0, r1, #1
	strh r0, [r3]
	b _0803F19E
	.align 2, 0
_0803F180: .4byte gUnknown_086AF3CC
_0803F184: .4byte 0x000003E2
_0803F188:
	movs r0, #0
	strh r0, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x22
	bne _0803F19E
	movs r0, #0x21
	strh r0, [r4]
_0803F19E:
	ldr r1, [r6]
	ldr r2, _0803F200 @ =0x000003E2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x21
	bne _0803F1D0
	ldr r4, _0803F204 @ =0x000003EA
	adds r1, r1, r4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	ldr r3, _0803F208 @ =0xFFFFFD00
	cmp r0, r3
	ble _0803F1D0
	adds r0, r2, #0
	subs r0, #0x18
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bge _0803F1D0
	movs r0, #0xfd
	lsls r0, r0, #8
	strh r0, [r1]
_0803F1D0:
	ldr r4, _0803F20C @ =gCurrentPinballGame
	ldr r3, [r4]
	ldr r7, _0803F204 @ =0x000003EA
	adds r0, r3, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0803F208 @ =0xFFFFFD00
	cmp r1, r0
	beq _0803F1E6
	bl _0803FA78
_0803F1E6:
	ldr r5, _0803F200 @ =0x000003E2
	adds r0, r3, r5
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r7, #6
	adds r0, r3, r7
	strh r1, [r0]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #7
	b _0803F8BC
	.align 2, 0
_0803F200: .4byte 0x000003E2
_0803F204: .4byte 0x000003EA
_0803F208: .4byte 0xFFFFFD00
_0803F20C: .4byte gCurrentPinballGame
_0803F210:
	ldr r2, _0803F23C @ =gUnknown_086AF3CC
	ldr r5, [r6]
	ldr r4, _0803F240 @ =0x000003E2
	adds r3, r5, r4
	movs r7, #0
	ldrsh r1, [r3, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r2, #2
	adds r0, r0, r2
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldrh r0, [r0]
	cmp r0, r2
	bls _0803F244
	adds r0, r2, #1
	strh r0, [r1]
	b _0803F2DC
	.align 2, 0
_0803F23C: .4byte gUnknown_086AF3CC
_0803F240: .4byte 0x000003E2
_0803F244:
	movs r4, #0
	mov ip, r4
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bne _0803F2DC
	ldr r4, _0803F274 @ =0x000003E1
	adds r1, r5, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0803F278
	movs r0, #0xd
	strh r0, [r3]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803F2DC
	.align 2, 0
_0803F274: .4byte 0x000003E1
_0803F278:
	ldr r7, _0803F2A8 @ =0x000003DD
	adds r0, r5, r7
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #6
	bne _0803F2C6
	ldr r1, _0803F2AC @ =0x00000385
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r7, #0x59
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r1, r0
	blt _0803F2B0
	movs r0, #0xd
	strh r0, [r3]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r5, r0
	b _0803F2D0
	.align 2, 0
_0803F2A8: .4byte 0x000003DD
_0803F2AC: .4byte 0x00000385
_0803F2B0:
	movs r0, #0x62
	strh r0, [r3]
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	ldr r0, [r6]
	adds r0, r0, r4
	mov r4, ip
	strb r4, [r0]
	b _0803F2DC
_0803F2C6:
	movs r0, #0xd
	strh r0, [r3]
	movs r7, #0xf7
	lsls r7, r7, #2
	adds r1, r5, r7
_0803F2D0:
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r4
	mov r1, ip
	strb r1, [r0]
_0803F2DC:
	ldr r4, _0803F324 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r2, _0803F328 @ =0x000003E1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0803F2F0
	b _0803FA78
_0803F2F0:
	ldr r3, _0803F32C @ =0x00000512
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldrh r0, [r1]
	bl Sin
	adds r1, r0, #0
	ldr r4, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0803F330 @ =0x00004E20
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r5, #0xfa
	lsls r5, r5, #2
	adds r4, r4, r5
	strh r1, [r4]
	b _0803FA78
	.align 2, 0
_0803F324: .4byte gCurrentPinballGame
_0803F328: .4byte 0x000003E1
_0803F32C: .4byte 0x00000512
_0803F330: .4byte 0x00004E20
_0803F334:
	ldr r0, [r6]
	ldr r7, _0803F438 @ =0x00000389
	adds r0, r0, r7
	movs r1, #2
	strb r1, [r0]
	ldr r2, _0803F43C @ =gUnknown_086AF3CC
	ldr r4, [r6]
	ldr r5, _0803F440 @ =0x000003E2
	adds r3, r4, r5
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
	bls _0803F364
	b _0803F7AE
_0803F364:
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x74
	bne _0803F390
	ldr r3, _0803F444 @ =0x000003E1
	adds r1, r4, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xe
	bgt _0803F390
	adds r0, r2, #1
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0x72
	strh r1, [r0]
_0803F390:
	ldr r3, [r6]
	ldr r5, _0803F440 @ =0x000003E2
	adds r1, r3, r5
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0x83
	bne _0803F3C8
	movs r2, #0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r7, _0803F444 @ =0x000003E1
	adds r0, r3, r7
	strb r2, [r0]
	ldr r0, [r6]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r3, _0803F448 @ =0x000003DD
	adds r0, r0, r3
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, _0803F438 @ =0x00000389
	adds r0, r0, r4
	strb r2, [r0]
_0803F3C8:
	ldr r4, [r6]
	adds r0, r4, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0x72
	bne _0803F404
	ldr r7, _0803F444 @ =0x000003E1
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803F404
	ldr r2, _0803F44C @ =gMain
	movs r1, #0xf3
	lsls r1, r1, #4
	adds r0, r2, r1
	movs r3, #1
	movs r1, #1
	strh r1, [r0]
	ldr r5, _0803F450 @ =0x00000FE8
	adds r0, r2, r5
	strh r1, [r0]
	movs r7, #0x85
	lsls r7, r7, #5
	adds r2, r2, r7
	strh r1, [r2]
	ldr r1, _0803F454 @ =0x00000507
	adds r0, r4, r1
	strb r3, [r0]
_0803F404:
	ldr r3, _0803F458 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r2, _0803F440 @ =0x000003E2
	adds r0, r1, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x78
	bne _0803F41E
	movs r5, #0xe4
	lsls r5, r5, #2
	adds r1, r1, r5
	movs r0, #0x15
	strh r0, [r1]
_0803F41E:
	ldr r1, [r3]
	adds r0, r1, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0x7c
	beq _0803F42C
	b _0803FA78
_0803F42C:
	ldr r0, _0803F45C @ =0x0000050A
	adds r1, r1, r0
	movs r0, #0x10
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F438: .4byte 0x00000389
_0803F43C: .4byte gUnknown_086AF3CC
_0803F440: .4byte 0x000003E2
_0803F444: .4byte 0x000003E1
_0803F448: .4byte 0x000003DD
_0803F44C: .4byte gMain
_0803F450: .4byte 0x00000FE8
_0803F454: .4byte 0x00000507
_0803F458: .4byte gCurrentPinballGame
_0803F45C: .4byte 0x0000050A
_0803F460:
	ldr r2, [r6]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, #0x77
	bhi _0803F470
	b _0803F9EA
_0803F470:
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0803F4B0 @ =0x040000D4
	ldr r0, _0803F4B4 @ =gUnknown_084A856C
	str r0, [r1]
	ldr r0, _0803F4B8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0803F4BC @ =0x80000E00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r6]
	ldr r5, _0803F4C0 @ =0x00000504
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803F4D4
	ldr r0, _0803F4C4 @ =gMain
	ldr r7, _0803F4C8 @ =0x000012C8
	adds r1, r0, r7
	strh r2, [r1]
	ldr r3, _0803F4CC @ =0x00001438
	adds r1, r0, r3
	strh r2, [r1]
	ldr r4, _0803F4D0 @ =0x000014F0
	adds r0, r0, r4
	b _0803F4EA
	.align 2, 0
_0803F4B0: .4byte 0x040000D4
_0803F4B4: .4byte gUnknown_084A856C
_0803F4B8: .4byte 0x06015800
_0803F4BC: .4byte 0x80000E00
_0803F4C0: .4byte 0x00000504
_0803F4C4: .4byte gMain
_0803F4C8: .4byte 0x000012C8
_0803F4CC: .4byte 0x00001438
_0803F4D0: .4byte 0x000014F0
_0803F4D4:
	ldr r0, _0803F530 @ =gMain
	movs r5, #0x9c
	lsls r5, r5, #5
	adds r1, r0, r5
	strh r2, [r1]
	ldr r7, _0803F534 @ =0x00001888
	adds r1, r0, r7
	strh r2, [r1]
	movs r1, #0xca
	lsls r1, r1, #5
	adds r0, r0, r1
_0803F4EA:
	strh r2, [r0]
	ldr r3, _0803F538 @ =gCurrentPinballGame
	ldr r1, [r3]
	ldr r2, _0803F53C @ =0x00000504
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r0, [r3]
	ldr r3, _0803F540 @ =0x00000524
	adds r1, r0, r3
	strh r2, [r1]
	ldr r4, _0803F544 @ =0x00000526
	adds r1, r0, r4
	strh r2, [r1]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r1, r0, r5
	strh r2, [r1]
	ldr r7, _0803F548 @ =0x0000052A
	adds r1, r0, r7
	strh r2, [r1]
	subs r3, #0x10
	adds r1, r0, r3
	strh r2, [r1]
	movs r4, #0xf9
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r2, [r0]
	ldr r0, _0803F54C @ =0x00000127
	bl m4aSongNumStart
	b _0803FA78
	.align 2, 0
_0803F530: .4byte gMain
_0803F534: .4byte 0x00001888
_0803F538: .4byte gCurrentPinballGame
_0803F53C: .4byte 0x00000504
_0803F540: .4byte 0x00000524
_0803F544: .4byte 0x00000526
_0803F548: .4byte 0x0000052A
_0803F54C: .4byte 0x00000127
_0803F550:
	ldr r7, _0803F578 @ =gMain
	ldr r0, _0803F57C @ =0x000012C8
	adds r5, r7, r0
	ldrh r4, [r5]
	cmp r4, #0
	beq _0803F5CC
	ldr r0, [r6]
	ldr r1, _0803F580 @ =0x00000524
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0803F584 @ =0x000012BF
	cmp r1, r0
	bgt _0803F588
	adds r0, r3, #0
	adds r0, #0x8c
	strh r0, [r2]
	b _0803F58C
	.align 2, 0
_0803F578: .4byte gMain
_0803F57C: .4byte 0x000012C8
_0803F580: .4byte 0x00000524
_0803F584: .4byte 0x000012BF
_0803F588:
	movs r0, #0
	strh r0, [r5]
_0803F58C:
	ldr r2, [r6]
	ldr r5, _0803F5C0 @ =0x00000524
	adds r0, r2, r5
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x96
	lsls r0, r0, #4
	cmp r1, r0
	ble _0803F62C
	movs r0, #0xa5
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0803F5C4 @ =0x0000135F
	cmp r1, r0
	bgt _0803F5B6
	adds r0, r3, #0
	adds r0, #0xc8
	strh r0, [r2]
_0803F5B6:
	ldr r1, [r6]
	ldr r5, _0803F5C8 @ =0x00000514
	adds r1, r1, r5
	b _0803F626
	.align 2, 0
_0803F5C0: .4byte 0x00000524
_0803F5C4: .4byte 0x0000135F
_0803F5C8: .4byte 0x00000514
_0803F5CC:
	ldr r0, [r6]
	ldr r1, _0803F5E8 @ =0x00000524
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldr r0, _0803F5EC @ =0xFFFFED40
	cmp r1, r0
	ble _0803F5F0
	adds r0, r3, #0
	subs r0, #0x8c
	strh r0, [r2]
	b _0803F5F8
	.align 2, 0
_0803F5E8: .4byte 0x00000524
_0803F5EC: .4byte 0xFFFFED40
_0803F5F0:
	movs r1, #0x9c
	lsls r1, r1, #5
	adds r0, r7, r1
	strh r4, [r0]
_0803F5F8:
	ldr r2, [r6]
	ldr r3, _0803F674 @ =0x00000524
	adds r0, r2, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r0, _0803F678 @ =0xFFFFF6A0
	cmp r1, r0
	bge _0803F62C
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r2, r2, r5
	ldrh r3, [r2]
	movs r7, #0
	ldrsh r1, [r2, r7]
	ldr r0, _0803F67C @ =0xFFFFECA0
	cmp r1, r0
	ble _0803F620
	adds r0, r3, #0
	subs r0, #0xc8
	strh r0, [r2]
_0803F620:
	ldr r1, [r6]
	ldr r0, _0803F680 @ =0x00000514
	adds r1, r1, r0
_0803F626:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0803F62C:
	ldr r2, _0803F684 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0x14
	bne _0803F646
	movs r4, #0x99
	lsls r4, r4, #3
	adds r1, r1, r4
	movs r0, #0x3c
	strb r0, [r1]
_0803F646:
	ldr r2, [r2]
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bhi _0803F65A
	b _0803FA78
_0803F65A:
	movs r0, #0
	strh r0, [r1]
	ldr r5, _0803F688 @ =0x000003E2
	adds r1, r2, r5
	movs r0, #0xd
	strh r0, [r1]
	movs r7, #0xf7
	lsls r7, r7, #2
	adds r1, r2, r7
	movs r0, #3
	strb r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F674: .4byte 0x00000524
_0803F678: .4byte 0xFFFFF6A0
_0803F67C: .4byte 0xFFFFECA0
_0803F680: .4byte 0x00000514
_0803F684: .4byte gCurrentPinballGame
_0803F688: .4byte 0x000003E2
_0803F68C:
	ldr r0, [r6]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r4, [r6]
	ldr r2, _0803F704 @ =0x00000283
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0803F720
	movs r3, #0xf7
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, [r6]
	ldr r4, _0803F708 @ =0x000003E2
	adds r0, r0, r4
	movs r4, #0
	strh r5, [r0]
	ldr r3, _0803F70C @ =gMain
	ldr r7, _0803F710 @ =0x00000A28
	adds r0, r3, r7
	movs r1, #1
	strh r1, [r0]
	movs r2, #0x97
	lsls r2, r2, #4
	adds r0, r3, r2
	strh r1, [r0]
	ldr r1, [r6]
	movs r7, #0xb3
	lsls r7, r7, #3
	adds r2, r1, r7
	movs r0, #0xc7
	strh r0, [r2]
	ldr r2, _0803F714 @ =0x0000038E
	adds r0, r1, r2
	strh r5, [r0]
	adds r7, #0x10
	adds r1, r1, r7
	strb r4, [r1]
	ldr r0, [r6]
	ldr r2, _0803F718 @ =0x000005A6
	adds r1, r0, r2
	strh r5, [r1]
	ldr r4, _0803F71C @ =0x000005A4
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	adds r2, r3, #0
	b _0803F74C
	.align 2, 0
_0803F704: .4byte 0x00000283
_0803F708: .4byte 0x000003E2
_0803F70C: .4byte gMain
_0803F710: .4byte 0x00000A28
_0803F714: .4byte 0x0000038E
_0803F718: .4byte 0x000005A6
_0803F71C: .4byte 0x000005A4
_0803F720:
	movs r7, #0xf7
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, [r6]
	ldr r0, _0803F770 @ =0x000003E2
	adds r2, r1, r0
	movs r0, #0x62
	strh r0, [r2]
	ldr r2, _0803F774 @ =gMain
	movs r0, #0x80
	strb r0, [r2, #0xf]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r6]
	ldr r4, _0803F778 @ =0x00000392
	adds r0, r0, r4
	strh r5, [r0]
_0803F74C:
	ldr r0, _0803F77C @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r5, #0xf9
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	ldr r7, _0803F780 @ =0x00001CD8
	adds r0, r2, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803F766
	b _0803FA78
_0803F766:
	ldr r0, _0803F784 @ =0x00000486
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F770: .4byte 0x000003E2
_0803F774: .4byte gMain
_0803F778: .4byte 0x00000392
_0803F77C: .4byte gCurrentPinballGame
_0803F780: .4byte 0x00001CD8
_0803F784: .4byte 0x00000486
_0803F788:
	ldr r2, _0803F7B4 @ =gUnknown_086AF3CC
	ldr r5, _0803F7B8 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r6, _0803F7BC @ =0x000003E2
	adds r3, r4, r6
	movs r7, #0
	ldrsh r1, [r3, r7]
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
	bls _0803F7C0
_0803F7AE:
	adds r0, r2, #1
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F7B4: .4byte gUnknown_086AF3CC
_0803F7B8: .4byte gCurrentPinballGame
_0803F7BC: .4byte 0x000003E2
_0803F7C0:
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x83
	bne _0803F7F2
	movs r0, #0xd
	strh r0, [r3]
	ldr r3, _0803F80C @ =0x000003E1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, [r5]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0xb
	strb r1, [r0]
	ldr r0, [r5]
	ldr r7, _0803F810 @ =0x00000389
	adds r0, r0, r7
	strb r2, [r0]
_0803F7F2:
	ldr r1, [r5]
	adds r0, r1, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x78
	beq _0803F800
	b _0803FA78
_0803F800:
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r0, #0x15
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F80C: .4byte 0x000003E1
_0803F810: .4byte 0x00000389
_0803F814:
	ldr r2, _0803F840 @ =gUnknown_086AF3CC
	ldr r3, [r6]
	ldr r5, _0803F844 @ =0x000003E2
	adds r4, r3, r5
	movs r7, #0
	ldrsh r1, [r4, r7]
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
	bls _0803F848
	adds r0, r1, #1
	strh r0, [r3]
	b _0803F85E
	.align 2, 0
_0803F840: .4byte gUnknown_086AF3CC
_0803F844: .4byte 0x000003E2
_0803F848:
	movs r0, #0
	strh r0, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x22
	bne _0803F85E
	movs r0, #0x21
	strh r0, [r4]
_0803F85E:
	ldr r1, [r6]
	ldr r2, _0803F8C8 @ =0x000003E2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x21
	bne _0803F890
	ldr r4, _0803F8CC @ =0x000003EA
	adds r1, r1, r4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	ldr r3, _0803F8D0 @ =0xFFFFFD00
	cmp r0, r3
	ble _0803F890
	adds r0, r2, #0
	subs r0, #0x18
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	bge _0803F890
	movs r0, #0xfd
	lsls r0, r0, #8
	strh r0, [r1]
_0803F890:
	ldr r4, _0803F8D4 @ =gCurrentPinballGame
	ldr r3, [r4]
	ldr r7, _0803F8CC @ =0x000003EA
	adds r0, r3, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0803F8D0 @ =0xFFFFFD00
	cmp r1, r0
	beq _0803F8A4
	b _0803FA78
_0803F8A4:
	ldr r5, _0803F8C8 @ =0x000003E2
	adds r0, r3, r5
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	subs r7, #6
	adds r0, r3, r7
	strh r1, [r0]
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0xc
_0803F8BC:
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, _0803F8D8 @ =0x000003E1
	adds r0, r0, r1
	strb r2, [r0]
	b _0803FA78
	.align 2, 0
_0803F8C8: .4byte 0x000003E2
_0803F8CC: .4byte 0x000003EA
_0803F8D0: .4byte 0xFFFFFD00
_0803F8D4: .4byte gCurrentPinballGame
_0803F8D8: .4byte 0x000003E1
_0803F8DC:
	ldr r1, _0803F980 @ =0x040000D4
	ldr r0, _0803F984 @ =gUnknown_084AA18C
	str r0, [r1]
	ldr r0, _0803F988 @ =0x06011620
	str r0, [r1, #4]
	ldr r0, _0803F98C @ =0x80000430
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0803F990 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r4, #0
	movs r1, #0xd
	strb r1, [r0]
	ldr r1, [r3]
	movs r5, #0xfa
	lsls r5, r5, #2
	adds r2, r1, r5
	ldr r0, _0803F994 @ =0x00000474
	strh r0, [r2]
	ldr r7, _0803F998 @ =0x000003EA
	adds r2, r1, r7
	ldr r0, _0803F99C @ =0x0000FB50
	strh r0, [r2]
	ldr r0, _0803F9A0 @ =0x00000506
	adds r1, r1, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r2, _0803F9A4 @ =0x00000516
	adds r1, r0, r2
	strh r4, [r1]
	ldr r5, _0803F9A8 @ =0x000005FA
	adds r0, r0, r5
	movs r2, #1
	strb r2, [r0]
	ldr r0, _0803F9AC @ =gMain
	movs r1, #0x80
	strb r1, [r0, #0xf]
	ldr r7, _0803F9B0 @ =0x00000D08
	adds r0, r0, r7
	strh r2, [r0]
	ldr r1, [r3]
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r3, _0803F9B4 @ =0x000003C6
	adds r2, r1, r3
	ldr r0, _0803F9B8 @ =0x0000EC78
	strh r0, [r2]
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r2, r1, r4
	movs r0, #0xaf
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r5, _0803F9BC @ =0x000003CA
	adds r2, r1, r5
	ldr r0, _0803F9C0 @ =0x0000F830
	strh r0, [r2]
	movs r7, #0x83
	lsls r7, r7, #3
	adds r2, r1, r7
	ldr r0, _0803F9C4 @ =0x0000FF38
	strh r0, [r2]
	ldr r0, _0803F9C8 @ =0x0000041A
	adds r2, r1, r0
	subs r0, #0xfa
	strh r0, [r2]
	adds r3, #0x4e
	adds r2, r1, r3
	movs r0, #0x18
	strh r0, [r2]
	adds r4, #0x4e
	adds r1, r1, r4
	ldr r0, _0803F9CC @ =0x0000FFF0
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F980: .4byte 0x040000D4
_0803F984: .4byte gUnknown_084AA18C
_0803F988: .4byte 0x06011620
_0803F98C: .4byte 0x80000430
_0803F990: .4byte gCurrentPinballGame
_0803F994: .4byte 0x00000474
_0803F998: .4byte 0x000003EA
_0803F99C: .4byte 0x0000FB50
_0803F9A0: .4byte 0x00000506
_0803F9A4: .4byte 0x00000516
_0803F9A8: .4byte 0x000005FA
_0803F9AC: .4byte gMain
_0803F9B0: .4byte 0x00000D08
_0803F9B4: .4byte 0x000003C6
_0803F9B8: .4byte 0x0000EC78
_0803F9BC: .4byte 0x000003CA
_0803F9C0: .4byte 0x0000F830
_0803F9C4: .4byte 0x0000FF38
_0803F9C8: .4byte 0x0000041A
_0803F9CC: .4byte 0x0000FFF0
_0803F9D0:
	ldr r3, _0803F9F0 @ =gCurrentPinballGame
	ldr r2, [r3]
	ldr r5, _0803F9F4 @ =0x00000516
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0xff
	bhi _0803FA18
	movs r7, #0xf9
	lsls r7, r7, #2
	adds r1, r2, r7
	ldrh r0, [r1]
	cmp r0, #0x4f
	bhi _0803F9F8
_0803F9EA:
	adds r0, #1
	strh r0, [r1]
	b _0803FA78
	.align 2, 0
_0803F9F0: .4byte gCurrentPinballGame
_0803F9F4: .4byte 0x00000516
_0803F9F8:
	ldr r0, _0803FA10 @ =0x000003EA
	adds r2, r2, r0
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0803FA14 @ =0x0000095F
	cmp r1, r0
	bgt _0803FA78
	adds r0, r3, #0
	adds r0, #0x50
	b _0803FA76
	.align 2, 0
_0803FA10: .4byte 0x000003EA
_0803FA14: .4byte 0x0000095F
_0803FA18:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0x13]
	ldr r0, [r3]
	strh r1, [r0, #0x18]
	movs r5, #0xf7
	lsls r5, r5, #2
	adds r0, r0, r5
	movs r1, #0xf
	strb r1, [r0]
	b _0803FA78
_0803FA2E:
	ldr r0, _0803FAC0 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r7, #0xe3
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #1
	strh r0, [r1]
	ldr r0, _0803FAC4 @ =0x0000038E
	adds r4, r5, r0
	ldrh r6, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _0803FAC8 @ =0xFFFFFE0C
	cmp r0, r1
	ble _0803FA78
	subs r0, r1, r0
	movs r1, #0x1e
	bl __divsi3
	adds r0, r6, r0
	strh r0, [r4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0xa
	bl __divsi3
	adds r2, r5, #0
	adds r2, #0xe6
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x26
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0803FA78
	ldr r0, _0803FACC @ =0x0000FFDA
_0803FA76:
	strh r0, [r2]
_0803FA78:
	ldr r5, _0803FAC0 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0803FAB8
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _0803FAA2
	ldr r0, _0803FAD0 @ =gSpeciesInfo
	ldr r7, _0803FAD4 @ =0x000012A8
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0
	bl PlayCry_Normal
_0803FAA2:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0803FAB8
	ldr r0, _0803FAD8 @ =gMPlayInfo_BGM
	ldr r1, _0803FADC @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
_0803FAB8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FAC0: .4byte gCurrentPinballGame
_0803FAC4: .4byte 0x0000038E
_0803FAC8: .4byte 0xFFFFFE0C
_0803FACC: .4byte 0x0000FFDA
_0803FAD0: .4byte gSpeciesInfo
_0803FAD4: .4byte 0x000012A8
_0803FAD8: .4byte gMPlayInfo_BGM
_0803FADC: .4byte 0x0000FFFF

	thumb_func_start sub_3FAE0
sub_3FAE0: @ 0x0803FAE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	ldr r7, _0803FB74 @ =gMain+0x21E0 @gMain.spriteGroups[43]
	ldrh r0, [r7]
	movs r2, #0xb8
	rsbs r2, r2, #0
	adds r2, r2, r7
	mov sb, r2
	cmp r0, #0
	beq _0803FBC4
	ldr r4, _0803FB78 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r7, #2]
	ldr r0, [r4]
	ldr r2, _0803FB7C @ =0x000003EA
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r7, #4]
	movs r2, #0
	ldr r4, _0803FB80 @ =gOamBuffer
	ldr r0, _0803FB84 @ =0xFFFFFE00
	mov r8, r0
_0803FB34:
	lsls r1, r2, #0x10
	asrs r0, r1, #0xd
	adds r0, #8
	adds r6, r7, r0
	movs r0, #4
	ldrsb r0, [r6, r0]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	movs r3, #0xf0
	lsls r3, r3, #0xe
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	adds r5, r1, #0
	cmp r0, #0xf0
	bls _0803FB88
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrh r1, [r2, #2]
	mov r0, r8
	ands r0, r1
	movs r1, #0xf0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0xb4
	strb r1, [r0]
	b _0803FBB6
	.align 2, 0
_0803FB74: .4byte gMain+0x21E0 @gMain.spriteGroups[43]
_0803FB78: .4byte gCurrentPinballGame
_0803FB7C: .4byte 0x000003EA
_0803FB80: .4byte gOamBuffer
_0803FB84: .4byte 0xFFFFFE00
_0803FB88:
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r4
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0803FC40 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
_0803FBB6:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r5, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	ble _0803FB34
_0803FBC4:
	mov r7, sb
	ldrh r4, [r7]
	mov sb, r4
	cmp r4, #0
	bne _0803FBD0
	b _0803FCD4
_0803FBD0:
	ldr r4, _0803FC44 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r7, #2]
	ldr r0, [r4]
	ldr r3, _0803FC48 @ =0x000003EA
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r7, #4]
	movs r2, #0
	ldr r4, _0803FC4C @ =gOamBuffer
	ldr r3, _0803FC50 @ =0xFFFFFE00
	mov r8, r3
_0803FC00:
	lsls r1, r2, #0x10
	asrs r0, r1, #0xd
	adds r0, #8
	adds r6, r7, r0
	movs r0, #4
	ldrsb r0, [r6, r0]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	movs r3, #0xf0
	lsls r3, r3, #0xe
	adds r0, r0, r3
	lsrs r0, r0, #0x10
	adds r5, r1, #0
	cmp r0, #0xf0
	bls _0803FC54
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrh r1, [r2, #2]
	mov r0, r8
	ands r0, r1
	movs r1, #0xf0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0xb4
	strb r1, [r0]
	b _0803FC82
	.align 2, 0
_0803FC40: .4byte 0x000001FF
_0803FC44: .4byte gCurrentPinballGame
_0803FC48: .4byte 0x000003EA
_0803FC4C: .4byte gOamBuffer
_0803FC50: .4byte 0xFFFFFE00
_0803FC54:
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r4
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _0803FCB8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
_0803FC82:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r5, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	ble _0803FC00
	ldr r4, _0803FCBC @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r1, _0803FCC0 @ =0x00000516
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _0803FCC4 @ =0x0000029F
	cmp r1, r0
	beq _0803FCA2
	b _0804024A
_0803FCA2:
	movs r0, #0
	strh r0, [r7]
	ldr r0, _0803FCC8 @ =gMain
	ldr r2, _0803FCCC @ =0x00002070
	adds r1, r0, r2
	movs r2, #1
	strh r2, [r1]
	ldr r3, _0803FCD0 @ =0x00002350
	adds r0, r0, r3
	strh r2, [r0]
	b _0804024A
	.align 2, 0
_0803FCB8: .4byte 0x000001FF
_0803FCBC: .4byte gCurrentPinballGame
_0803FCC0: .4byte 0x00000516
_0803FCC4: .4byte 0x0000029F
_0803FCC8: .4byte gMain
_0803FCCC: .4byte 0x00002070
_0803FCD0: .4byte 0x00002350
_0803FCD4:
	subs r7, #0xb8
	ldrh r0, [r7]
	cmp r0, #0
	bne _0803FCDE
	b _0803FF98
_0803FCDE:
	ldr r5, _0803FD84 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r0, #0xfa
	lsls r0, r0, #2
	mov r8, r0
	adds r0, r4, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r1, #0x58
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r4, [r5]
	ldr r6, _0803FD88 @ =0x000003EA
	adds r0, r4, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x4e
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r4, [r5]
	add r8, r4
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x74
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	adds r6, r4, r6
	movs r3, #0
	ldrsh r0, [r6, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x3c
	ldr r2, _0803FD8C @ =0x0000028A
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _0803FD90 @ =0x0000051A
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x5b
	ble _0803FD98
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, #0xac
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
	adds r0, #0xb8
	ldr r2, _0803FD94 @ =0x000003F2
	adds r1, r4, r2
	b _0803FDA8
	.align 2, 0
_0803FD84: .4byte gCurrentPinballGame
_0803FD88: .4byte 0x000003EA
_0803FD8C: .4byte 0x0000028A
_0803FD90: .4byte 0x0000051A
_0803FD94: .4byte 0x000003F2
_0803FD98:
	movs r3, #0xfc
	lsls r3, r3, #2
	adds r0, r4, r3
	mov r1, sb
	strh r1, [r0]
	ldr r2, _0803FE1C @ =0x000003F2
	adds r1, r4, r2
	ldr r0, _0803FE20 @ =0x0000FF60
_0803FDA8:
	strh r0, [r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r0, #0x46
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0803FDBA
	ldr r0, _0803FE24 @ =0x0000FFBA
	strh r0, [r7, #4]
_0803FDBA:
	movs r4, #4
	ldrsh r0, [r7, r4]
	cmp r0, #0xb4
	ble _0803FDC6
	movs r0, #0xb4
	strh r0, [r7, #4]
_0803FDC6:
	ldr r2, _0803FE28 @ =gUnknown_086AF3CC
	ldr r0, _0803FE2C @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r1, _0803FE30 @ =0x000003E2
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r4, _0803FE34 @ =0x00000389
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r2
	cmp r0, #9
	ble _0803FE40
	movs r0, #0xb
	str r0, [sp]
	ldr r3, _0803FE38 @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r3
	ldrh r1, [r2, #2]
	ldr r0, _0803FE3C @ =0xFFFFFE00
	ands r0, r1
	movs r1, #0xf0
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r7, #8]
	lsls r0, r0, #3
	adds r0, r0, r3
	movs r1, #0xb4
	strb r1, [r0]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r3
	movs r3, #0xb0
	b _0803FF24
	.align 2, 0
_0803FE1C: .4byte 0x000003F2
_0803FE20: .4byte 0x0000FF60
_0803FE24: .4byte 0x0000FFBA
_0803FE28: .4byte gUnknown_086AF3CC
_0803FE2C: .4byte gCurrentPinballGame
_0803FE30: .4byte 0x000003E2
_0803FE34: .4byte 0x00000389
_0803FE38: .4byte gOamBuffer
_0803FE3C: .4byte 0xFFFFFE00
_0803FE40:
	cmp r0, #1
	bne _0803FE4C
	movs r2, #2
	mov sl, r2
	movs r3, #0xe
	b _0803FE6C
_0803FE4C:
	cmp r0, #3
	bne _0803FE5A
	movs r4, #2
	mov sl, r4
	movs r0, #0xb
	str r0, [sp]
	b _0803FE6E
_0803FE5A:
	ldr r2, _0803FF30 @ =0x000003DF
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	movs r3, #0xf
_0803FE6C:
	str r3, [sp]
_0803FE6E:
	ldr r4, _0803FF34 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _0803FE86
	movs r3, #8
	mov sl, r3
_0803FE86:
	cmp r0, #0x16
	bne _0803FE8E
	movs r4, #9
	mov sl, r4
_0803FE8E:
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	ldr r6, _0803FF38 @ =gOamBuffer
	adds r2, r2, r6
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _0803FF3C @ =gUnknown_086B612E
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r0, [r7, #8]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, _0803FF34 @ =gCurrentPinballGame
	ldr r5, [r1]
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r4, #0x4e
	ldr r2, _0803FF40 @ =0x000003EA
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, r4, r0
	ldr r0, _0803FF44 @ =0x0000051A
	adds r5, r5, r0
	strh r4, [r5]
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r4, _0803FF48 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _0803FF4C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldr r3, _0803FF34 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r4, _0803FF50 @ =0x00000389
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0803FF54
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldr r0, [sp]
	lsls r3, r0, #4
_0803FF24:
	ldrb r2, [r1, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, #5]
	b _0803FF60
	.align 2, 0
_0803FF30: .4byte 0x000003DF
_0803FF34: .4byte gCurrentPinballGame
_0803FF38: .4byte gOamBuffer
_0803FF3C: .4byte gUnknown_086B612E
_0803FF40: .4byte 0x000003EA
_0803FF44: .4byte 0x0000051A
_0803FF48: .4byte 0x000001FF
_0803FF4C: .4byte 0xFFFFFE00
_0803FF50: .4byte 0x00000389
_0803FF54:
	ldrh r0, [r7, #8]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrb r0, [r0, #5]
	lsrs r0, r0, #4
	str r0, [sp]
_0803FF60:
	ldr r1, _0803FFB8 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r3, _0803FFBC @ =0x000003E2
	adds r0, r2, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _0803FFC0 @ =0x000003DF
	adds r2, r2, r1
	strb r0, [r2]
	ldr r2, _0803FFC4 @ =0x040000D4
	mov r3, sl
	lsls r0, r3, #0x10
	asrs r0, r0, #5
	ldr r1, _0803FFC8 @ =gUnknown_084AA9EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0803FFCC @ =0x06011620
	str r0, [r2, #4]
	ldr r0, _0803FFD0 @ =0x80000400
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0803FF98:
	ldr r7, _0803FFD4 @ =gMain+0x1210 @gMain.spriteGroups[21]
	ldrh r0, [r7]
	cmp r0, #0
	bne _0803FFA2
	b _080400C0
_0803FFA2:
	mov r4, sl
	lsls r0, r4, #0x10
	asrs r5, r0, #0x10
	cmp r5, #7
	ble _0803FFD8
	movs r0, #0
	strh r0, [r7, #2]
	strh r0, [r7, #4]
	mov sl, r0
	b _0804002E
	.align 2, 0
_0803FFB8: .4byte gCurrentPinballGame
_0803FFBC: .4byte 0x000003E2
_0803FFC0: .4byte 0x000003DF
_0803FFC4: .4byte 0x040000D4
_0803FFC8: .4byte gUnknown_084AA9EC
_0803FFCC: .4byte 0x06011620
_0803FFD0: .4byte 0x80000400
_0803FFD4: .4byte gMain+0x1210 @gMain.spriteGroups[21]
_0803FFD8:
	cmp r5, #5
	ble _08040028
	ldr r0, _08040020 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r1, #0x58
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r3, _08040024 @ =0x000003EA
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	adds r0, #0x60
	strh r0, [r7, #4]
	subs r0, r5, #6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	b _0804002E
	.align 2, 0
_08040020: .4byte gCurrentPinballGame
_08040024: .4byte 0x000003EA
_08040028:
	movs r0, #0
	strh r0, [r7, #2]
	strh r0, [r7, #4]
_0804002E:
	movs r2, #0
	ldr r3, [sp]
	lsls r3, r3, #4
	mov sb, r3
	mov r4, sl
	lsls r1, r4, #0x10
	ldr r0, _080400F0 @ =gOamBuffer
	mov r8, r0
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r1, _080400F4 @ =0xFFFFFC00
	mov sl, r1
_0804004C:
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r0, r4, #0
	adds r0, #8
	adds r6, r7, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	add r3, r8
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r2, _080400F8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _080400FC @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldrb r0, [r7, #4]
	ldrb r3, [r6, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, r8
	add r4, ip
	ldr r0, _08040100 @ =0x00000109
	adds r4, r4, r0
	ldr r1, _08040104 @ =0x000003FF
	adds r0, r1, #0
	ands r4, r0
	ldrh r1, [r2, #4]
	mov r0, sl
	ands r0, r1
	orrs r0, r4
	strh r0, [r2, #4]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldrb r2, [r1, #5]
	movs r0, #0xf
	ands r0, r2
	mov r2, sb
	orrs r0, r2
	strb r0, [r1, #5]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #1
	ble _0804004C
_080400C0:
	ldr r7, _08040108 @ =gMain+0x2350 @gMain.spriteGroups[45]
	ldrh r0, [r7]
	cmp r0, #0
	bne _080400CA
	b _0804024A
_080400CA:
	ldr r4, _0804010C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r3, _08040110 @ =0x0000051A
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #0x46
	movs r1, #3
	bl __divsi3
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08040114
	movs r1, #0
	b _0804011A
	.align 2, 0
_080400F0: .4byte gOamBuffer
_080400F4: .4byte 0xFFFFFC00
_080400F8: .4byte 0x000001FF
_080400FC: .4byte 0xFFFFFE00
_08040100: .4byte 0x00000109
_08040104: .4byte 0x000003FF
_08040108: .4byte gMain+0x2350 @gMain.spriteGroups[45]
_0804010C: .4byte gCurrentPinballGame
_08040110: .4byte 0x0000051A
_08040114:
	cmp r0, #9
	ble _0804011A
	movs r1, #9
_0804011A:
	ldr r3, _08040154 @ =gCurrentPinballGame
	ldr r2, [r3]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r6, r1, #0x10
	cmp r0, #0xe
	beq _08040180
	ldr r0, _08040158 @ =0x0000050A
	adds r3, r2, r0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _08040160
	ldr r1, _0804015C @ =gMain
	ldrh r0, [r1, #0x38]
	movs r0, #0x9e
	strh r0, [r1, #0x38]
	ldrh r0, [r3]
	ldrh r2, [r1, #0x3c]
	strh r0, [r1, #0x3c]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _08040180
	.align 2, 0
_08040154: .4byte gCurrentPinballGame
_08040158: .4byte 0x0000050A
_0804015C: .4byte gMain
_08040160:
	ldr r2, _0804025C @ =gMain
	ldrb r1, [r2, #0xf]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _08040180
	ldrh r0, [r2, #0x38]
	ldr r0, _08040260 @ =0x00001E10
	strh r0, [r2, #0x38]
	movs r0, #0x10
	asrs r1, r6, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r0, r1
	ldrh r1, [r2, #0x3a]
	strh r0, [r2, #0x3a]
_08040180:
	ldr r5, _08040264 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r1, #0x58
	subs r0, r0, r1
	movs r1, #0
	mov r8, r1
	strh r0, [r7, #2]
	ldr r2, _08040268 @ =0x000003EA
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x4e
	subs r0, r0, r1
	asrs r1, r6, #0x10
	adds r1, #0x24
	adds r0, r0, r1
	strh r0, [r7, #4]
	adds r6, r7, #0
	adds r6, #8
	ldr r4, _0804026C @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r3, _08040270 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08040274 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	ldr r0, [r5]
	movs r4, #0xf7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _08040226
	ldr r1, _0804025C @ =gMain
	ldr r0, _08040278 @ =0x000021E0
	adds r2, r1, r0
	movs r0, #1
	strh r0, [r2]
	ldr r2, _0804027C @ =0x00002070
	adds r0, r1, r2
	mov r3, r8
	strh r3, [r0]
	ldr r4, _08040280 @ =0x00002350
	adds r0, r1, r4
	strh r3, [r0]
	ldr r0, _08040284 @ =0x00001210
	adds r1, r1, r0
	strh r3, [r1]
_08040226:
	ldr r1, _08040264 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x15
	bne _0804024A
	ldr r0, _0804025C @ =gMain
	ldr r3, _08040280 @ =0x00002350
	adds r1, r0, r3
	mov r4, r8
	strh r4, [r1]
	ldr r1, _08040284 @ =0x00001210
	adds r0, r0, r1
	strh r4, [r0]
_0804024A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804025C: .4byte gMain
_08040260: .4byte 0x00001E10
_08040264: .4byte gCurrentPinballGame
_08040268: .4byte 0x000003EA
_0804026C: .4byte gOamBuffer
_08040270: .4byte 0x000001FF
_08040274: .4byte 0xFFFFFE00
_08040278: .4byte 0x000021E0
_0804027C: .4byte 0x00002070
_08040280: .4byte 0x00002350
_08040284: .4byte 0x00001210

	thumb_func_start sub_40288
sub_40288: @ 0x08040288
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	movs r7, #0
	movs r2, #0
	str r2, [sp]
	ldr r3, _080402CC @ =gMain+0xA28 @gMain.spriteGroups[10]
	str r3, [sp, #0x10]
	ldrh r0, [r3]
	cmp r0, #0
	bne _080402AE
	b _08040444
_080402AE:
	ldr r0, _080402D0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r4, _080402D4 @ =0x000006C4
	adds r1, r1, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #3
	bne _080402D8
	movs r0, #0xf0
	strh r0, [r3, #2]
	movs r0, #0xb4
	strh r0, [r3, #4]
	b _080402E2
	.align 2, 0
_080402CC: .4byte gMain+0xA28 @gMain.spriteGroups[10]
_080402D0: .4byte gCurrentPinballGame
_080402D4: .4byte 0x000006C4
_080402D8:
	movs r0, #0x60
	ldr r5, [sp, #0x10]
	strh r0, [r5, #2]
	movs r0, #0x37
	strh r0, [r5, #4]
_080402E2:
	ldr r0, _08040468 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, [sp, #0x10]
	ldrh r2, [r3, #2]
	ldr r4, _0804046C @ =0x000006E4
	adds r0, r1, r4
	strh r2, [r0]
	ldrh r0, [r3, #4]
	ldr r5, _08040470 @ =0x000006E6
	adds r1, r1, r5
	strh r0, [r1]
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0xc7
	ble _08040304
	movs r0, #0xc8
	strh r0, [r3, #4]
_08040304:
	movs r2, #0
	ldr r3, _08040474 @ =gMain+0x970 @gMain.spriteGroups[9]
	mov ip, r3
	ldr r5, _08040478 @ =gOamBuffer
	movs r4, #3
	mov sb, r4
	movs r0, #0xd
	rsbs r0, r0, #0
	mov sl, r0
	ldr r1, _0804047C @ =0xFFFFFE00
	mov r8, r1
_0804031A:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r2, [sp, #0x10]
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
	ldr r1, _08040468 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08040480 @ =0x000006DB
	adds r0, r0, r2
	ldrb r1, [r0]
	mov r0, sb
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r2, #2
	ldrsh r1, [r6, r2]
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x10]
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [sp, #0x3c]
	adds r1, r2, r0
	ldr r2, _08040484 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, [sp, #0x10]
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _0804031A
	mov r4, ip
	str r4, [sp, #0x10]
	ldr r5, _08040468 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r1, _0804046C @ =0x000006E4
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r4, #2]
	ldr r0, [r5]
	ldr r2, _08040470 @ =0x000006E6
	adds r0, r0, r2
	ldrh r0, [r0]
	subs r0, #8
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _080403C4
	movs r0, #0xc8
	strh r0, [r4, #4]
_080403C4:
	movs r2, #0
	ldr r5, _08040478 @ =gOamBuffer
	movs r3, #3
	mov sb, r3
	movs r4, #0xd
	rsbs r4, r4, #0
	mov sl, r4
	ldr r0, _0804047C @ =0xFFFFFE00
	mov r8, r0
_080403D6:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	ldr r2, _08040468 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08040480 @ =0x000006DB
	adds r0, r0, r1
	ldrb r1, [r0]
	mov r2, sb
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r1, #2
	ldrsh r0, [r6, r1]
	mov ip, r0
	ldr r2, [sp, #0x10]
	movs r1, #2
	ldrsh r0, [r2, r1]
	mov r2, ip
	adds r1, r2, r0
	ldr r2, _08040484 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r3, [sp, #0x10]
	ldrb r0, [r3, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #5
	ble _080403D6
_08040444:
	bl sub_41580
	ldr r0, _08040468 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r4, _08040488 @ =0x00000507
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bls _0804045C
	b _08040802
_0804045C:
	lsls r0, r0, #2
	ldr r1, _0804048C @ =_08040490
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040468: .4byte gCurrentPinballGame
_0804046C: .4byte 0x000006E4
_08040470: .4byte 0x000006E6
_08040474: .4byte gMain+0x970 @gMain.spriteGroups[9]
_08040478: .4byte gOamBuffer
_0804047C: .4byte 0xFFFFFE00
_08040480: .4byte 0x000006DB
_08040484: .4byte 0x000001FF
_08040488: .4byte 0x00000507
_0804048C: .4byte _08040490
_08040490: @ jump table
	.4byte _080404A4 @ case 0
	.4byte _080404C4 @ case 1
	.4byte _080405E8 @ case 2
	.4byte _080406C0 @ case 3
	.4byte _080407EC @ case 4
_080404A4:
	ldr r0, _080404C0 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r5, #0xa2
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
	movs r7, #7
	movs r0, #0xc
	str r0, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	b _08040802
	.align 2, 0
_080404C0: .4byte gCurrentPinballGame
_080404C4:
	ldr r5, _08040548 @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r4, #0xa2
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080404DC
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStart
_080404DC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #8
	bne _080404EE
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStop
_080404EE:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x18
	bne _08040500
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStart
_08040500:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x24
	bne _08040512
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStop
_08040512:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x32
	bne _08040524
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStart
_08040524:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x38
	bne _08040536
	movs r0, #0x94
	lsls r0, r0, #1
	bl m4aSongNumStop
_08040536:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r1, [r0]
	cmp r1, #0xd
	bhi _0804054C
	adds r0, r1, #0
	lsrs r7, r0, #1
	b _0804056E
	.align 2, 0
_08040548: .4byte gCurrentPinballGame
_0804054C:
	cmp r1, #0x29
	bls _0804055E
	cmp r1, #0x37
	bhi _0804055A
	ldrh r0, [r0]
	subs r0, #0x2a
	b _08040566
_0804055A:
	cmp r1, #0x3c
	bhi _08040562
_0804055E:
	movs r7, #7
	b _0804056E
_08040562:
	ldrh r0, [r0]
	subs r0, #0x3d
_08040566:
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	lsls r0, r0, #0xf
	lsrs r7, r0, #0x10
_0804056E:
	ldr r0, _08040588 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r1, #7
	bhi _0804058C
	adds r0, r1, #0
	lsrs r0, r0, #1
	str r0, [sp, #4]
	b _080405B2
	.align 2, 0
_08040588: .4byte gCurrentPinballGame
_0804058C:
	cmp r1, #0x2f
	bhi _08040596
	movs r3, #0xc
	str r3, [sp, #4]
	b _080405B2
_08040596:
	cmp r1, #0x3f
	bhi _080405AE
	ldrh r0, [r0]
	subs r0, #0x30
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	b _080405B2
_080405AE:
	movs r4, #0xc
	str r4, [sp, #4]
_080405B2:
	movs r5, #5
	str r5, [sp, #8]
	ldr r0, _080405E0 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4b
	beq _080405D0
	b _08040802
_080405D0:
	movs r0, #0
	strh r0, [r2]
	ldr r2, _080405E4 @ =0x00000507
	adds r1, r1, r2
	movs r0, #2
	strb r0, [r1]
	b _08040802
	.align 2, 0
_080405E0: .4byte gCurrentPinballGame
_080405E4: .4byte 0x00000507
_080405E8:
	movs r7, #7
	movs r3, #0xc
	str r3, [sp, #4]
	movs r4, #5
	str r4, [sp, #8]
	ldr r5, _0804065C @ =gCurrentPinballGame
	ldr r3, [r5]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0x21
	bhi _080406A4
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1c
	beq _08040610
	b _08040802
_08040610:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08040670
	bl Random
	ldr r4, [r5]
	movs r1, #0xa0
	bl __umodsi3
	movs r1, #0xc8
	subs r1, r1, r0
	ldr r2, _08040660 @ =0x0000051C
	adds r4, r4, r2
	strh r1, [r4]
	bl Random
	ldr r5, [r5]
	ldr r3, _08040664 @ =0x0000132C
	adds r1, r5, r3
	ldr r1, [r1]
	ldr r2, _08040668 @ =0xFFFFFEA5
	adds r4, r2, #0
	ldrh r1, [r1, #0x12]
	adds r4, r4, r1
	movs r1, #0x50
	bl __umodsi3
	subs r4, r4, r0
	ldr r3, _0804066C @ =0x0000051E
	adds r5, r5, r3
	strh r4, [r5]
	b _08040802
	.align 2, 0
_0804065C: .4byte gCurrentPinballGame
_08040660: .4byte 0x0000051C
_08040664: .4byte 0x0000132C
_08040668: .4byte 0xFFFFFEA5
_0804066C: .4byte 0x0000051E
_08040670:
	ldr r4, _08040694 @ =0x0000132C
	adds r2, r3, r4
	ldr r0, [r2]
	ldrh r0, [r0, #0x10]
	subs r0, #0xd
	ldr r5, _08040698 @ =0x0000051C
	adds r1, r3, r5
	strh r0, [r1]
	ldr r1, [r2]
	ldr r2, _0804069C @ =0xFFFFFEA5
	adds r0, r2, #0
	ldrh r1, [r1, #0x12]
	adds r0, r0, r1
	ldr r4, _080406A0 @ =0x0000051E
	adds r1, r3, r4
	strh r0, [r1]
	b _08040802
	.align 2, 0
_08040694: .4byte 0x0000132C
_08040698: .4byte 0x0000051C
_0804069C: .4byte 0xFFFFFEA5
_080406A0: .4byte 0x0000051E
_080406A4:
	movs r0, #0
	strh r0, [r1]
	ldr r5, _080406B8 @ =0x00000507
	adds r1, r3, r5
	movs r0, #3
	strb r0, [r1]
	ldr r0, _080406BC @ =0x00000129
	bl m4aSongNumStart
	b _08040802
	.align 2, 0
_080406B8: .4byte 0x00000507
_080406BC: .4byte 0x00000129
_080406C0:
	movs r7, #7
	movs r0, #0xc
	str r0, [sp, #4]
	ldr r4, _080406DC @ =gCurrentPinballGame
	ldr r3, [r4]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrh r1, [r0]
	cmp r1, #1
	bhi _080406E0
	adds r0, r1, #0
	str r0, [sp, #8]
	b _080407D0
	.align 2, 0
_080406DC: .4byte gCurrentPinballGame
_080406E0:
	cmp r1, #9
	bhi _080407C4
	ldrh r0, [r0]
	subs r0, #2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #2
	lsls r0, r0, #0x10
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r3, r2
	mov r5, sp
	ldrh r5, [r5, #4]
	strh r5, [r1]
	lsrs r1, r0, #0x10
	str r1, [sp, #8]
	asrs r0, r0, #0x10
	cmp r0, #2
	bne _080407D0
	ldr r2, _080407A0 @ =0x0000132C
	adds r0, r3, r2
	ldr r2, [r0]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	subs r0, #0xd
	ldr r5, _080407A4 @ =0x0000051C
	adds r1, r3, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r1, r0, r1
	str r1, [sp, #0x1c]
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	ldr r2, _080407A8 @ =0xFFFFFEA5
	adds r0, r0, r2
	ldr r5, _080407AC @ =0x0000051E
	adds r1, r3, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r1, r0, r1
	str r1, [sp, #0x20]
	ldr r3, [sp, #0x1c]
	adds r1, r3, #0
	muls r1, r3, r1
	ldr r5, [sp, #0x20]
	adds r0, r5, #0
	muls r0, r5, r0
	adds r5, r1, r0
	movs r0, #8
	bl sub_11B0
	ldr r2, [r4]
	ldr r1, _080407B0 @ =0x00000441
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080407D0
	ldr r3, _080407B4 @ =0x00000442
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _080407D0
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080407D0
	cmp r5, #0xc7
	bgt _080407D0
	ldr r0, _080407B8 @ =gMain
	ldr r5, _080407BC @ =0x00001CD8
	adds r0, r0, r5
	movs r1, #1
	strh r1, [r0]
	ldr r0, _080407C0 @ =0x00000486
	adds r1, r2, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #1
	bl m4aSongNumStart
	movs r0, #9
	bl sub_11B0
	b _080407D0
	.align 2, 0
_080407A0: .4byte 0x0000132C
_080407A4: .4byte 0x0000051C
_080407A8: .4byte 0xFFFFFEA5
_080407AC: .4byte 0x0000051E
_080407B0: .4byte 0x00000441
_080407B4: .4byte 0x00000442
_080407B8: .4byte gMain
_080407BC: .4byte 0x00001CD8
_080407C0: .4byte 0x00000486
_080407C4:
	movs r1, #5
	str r1, [sp, #8]
	ldr r2, _080407E4 @ =0x00000507
	adds r1, r3, r2
	movs r0, #4
	strb r0, [r1]
_080407D0:
	ldr r0, _080407E8 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0xa2
	lsls r3, r3, #3
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08040802
	.align 2, 0
_080407E4: .4byte 0x00000507
_080407E8: .4byte gCurrentPinballGame
_080407EC:
	ldr r0, _08040A88 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r4, #0xa2
	lsls r4, r4, #3
	adds r2, r1, r4
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldr r5, _08040A8C @ =0x00000507
	adds r1, r1, r5
	strb r3, [r1]
_08040802:
	ldr r0, _08040A90 @ =gMain+0xF30 @gMain.spriteGroups[17]
	str r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r0, #0
	beq _080408F0
	ldr r1, _08040A88 @ =gCurrentPinballGame
	ldr r4, [r1]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r1, #0x58
	subs r0, r0, r1
	ldr r4, [sp, #0x10]
	strh r0, [r4, #2]
	ldr r5, _08040A88 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r1, _08040A94 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	adds r0, #0x60
	ldr r3, [sp, #0x10]
	strh r0, [r3, #4]
	movs r2, #0
	lsls r1, r7, #0x10
	ldr r4, _08040A98 @ =gUnknown_086B609E
	mov sl, r4
	ldr r5, _08040A9C @ =gOamBuffer
	mov ip, r5
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r8, r0
	ldr r7, _08040AA0 @ =0xFFFFFE00
	mov sb, r7
_08040864:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r2, ip
	adds r5, r0, r2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sl
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, #2
	adds r5, #2
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	strh r0, [r5, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	ldr r5, [sp, #0x10]
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _08040AA4 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, ip
	ldr r7, [sp, #0x10]
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #2
	ble _08040864
	ldr r3, _08040A88 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r4, _08040A8C @ =0x00000507
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080408F0
	ldr r0, _08040AA8 @ =gMain
	movs r5, #0xf3
	lsls r5, r5, #4
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
_080408F0:
	ldr r7, _08040AAC @ =gMain+0xFE8 @gMain.spriteGroups[18]
	str r7, [sp, #0x10]
	adds r1, r7, #0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080409DC
	ldr r2, _08040A88 @ =gCurrentPinballGame
	ldr r4, [r2]
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r1, #0x58
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r0, _08040A88 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r1, _08040A94 @ =0x000003EA
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	adds r0, #0x60
	strh r0, [r7, #4]
	movs r2, #0
	ldr r3, [sp, #4]
	lsls r1, r3, #0x10
	ldr r4, _08040AB0 @ =gUnknown_086B5ECA
	mov sl, r4
	ldr r5, _08040A9C @ =gOamBuffer
	mov ip, r5
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r8, r0
	ldr r7, _08040AA0 @ =0xFFFFFE00
	mov sb, r7
_08040952:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r2, ip
	adds r5, r0, r2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sl
	mov r4, r8
	adds r1, r4, r0
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, #2
	adds r5, #2
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	strh r0, [r5, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	ldr r5, [sp, #0x10]
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _08040AA4 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, ip
	ldr r7, [sp, #0x10]
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _08040952
	ldr r3, _08040A88 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r4, _08040A8C @ =0x00000507
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080409DC
	ldr r0, _08040AA8 @ =gMain
	ldr r5, _08040AB4 @ =0x00000FE8
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
_080409DC:
	ldr r7, _08040AB8 @ =gMain+0x10A0 @gMain.spriteGroups[19]
	str r7, [sp, #0x10]
	adds r1, r7, #0
	ldrh r0, [r1]
	cmp r0, #0
	bne _080409EA
	b _08040B26
_080409EA:
	ldr r2, _08040A88 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _08040ABC @ =0x0000051C
	adds r0, r1, r3
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r4, r7, #0
	strh r0, [r4, #2]
	ldr r1, [r2]
	ldr r5, _08040AC0 @ =0x0000051E
	adds r0, r1, r5
	adds r1, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldr r7, _08040A9C @ =gOamBuffer
	mov r8, r7
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	ldr r3, _08040AC4 @ =gUnknown_086B5DCE
	mov sl, r3
	mov ip, r8
	asrs r1, r1, #0x10
	movs r0, #0x2a
	adds r4, r1, #0
	muls r4, r0, r4
	mov sb, r4
	ldr r4, _08040AA0 @ =0xFFFFFE00
_08040A2A:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	lsls r0, r1, #3
	adds r0, #8
	ldr r5, [sp, #0x10]
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r7, ip
	adds r5, r0, r7
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, sl
	mov r3, sb
	adds r1, r3, r0
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, #2
	adds r5, #2
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	strh r0, [r5, #2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	adds r5, r0, r7
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldr r7, [sp, #0x10]
	movs r3, #4
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r0, _08040AC8 @ =0xFFFFFED4
	str r2, [sp, #0x40]
	cmp r1, r0
	bge _08040ACC
	ldrh r1, [r5, #2]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	add r0, r8
	movs r1, #0xb4
	strb r1, [r0]
	b _08040AF8
	.align 2, 0
_08040A88: .4byte gCurrentPinballGame
_08040A8C: .4byte 0x00000507
_08040A90: .4byte gMain+0xF30 @gMain.spriteGroups[17]
_08040A94: .4byte 0x000003EA
_08040A98: .4byte gUnknown_086B609E
_08040A9C: .4byte gOamBuffer
_08040AA0: .4byte 0xFFFFFE00
_08040AA4: .4byte 0x000001FF
_08040AA8: .4byte gMain
_08040AAC: .4byte gMain+0xFE8 @gMain.spriteGroups[18]
_08040AB0: .4byte gUnknown_086B5ECA
_08040AB4: .4byte 0x00000FE8
_08040AB8: .4byte gMain+0x10A0 @gMain.spriteGroups[19]
_08040ABC: .4byte 0x0000051C
_08040AC0: .4byte 0x0000051E
_08040AC4: .4byte gUnknown_086B5DCE
_08040AC8: .4byte 0xFFFFFED4
_08040ACC:
	ldrh r2, [r5, #2]
	lsls r1, r2, #0x17
	lsrs r1, r1, #0x17
	ldr r7, [sp, #0x10]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r7, _08040C70 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [sp, #0x10]
	ldrb r0, [r2, #4]
	ldrb r3, [r1]
	adds r0, r0, r3
	strb r0, [r1]
_08040AF8:
	ldr r5, [sp, #0x40]
	movs r7, #0x80
	lsls r7, r7, #9
	adds r0, r5, r7
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _08040A2A
	ldr r1, _08040C74 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08040C78 @ =0x00000507
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08040B26
	ldr r0, _08040C7C @ =gMain
	movs r3, #0x85
	lsls r3, r3, #5
	adds r0, r0, r3
	movs r1, #0
	strh r1, [r0]
_08040B26:
	ldr r4, _08040C80 @ =gMain+0x12C8 @gMain.spriteGroups[22]
	str r4, [sp, #0x10]
	ldrh r0, [r4]
	cmp r0, #0
	beq _08040BBC
	ldr r5, _08040C74 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r7, _08040C84 @ =0x00000524
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x78
	subs r0, r0, r1
	ldr r2, [sp, #0x10]
	strh r0, [r2, #2]
	ldr r4, [r5]
	ldr r3, _08040C88 @ =0x00000526
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x80
	subs r0, r0, r1
	ldr r7, [sp, #0x10]
	strh r0, [r7, #4]
	movs r2, #0
	ldr r5, _08040C8C @ =gOamBuffer
	ldr r0, _08040C90 @ =0xFFFFFE00
	mov r8, r0
_08040B72:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r1, [sp, #0x10]
	adds r6, r1, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r2, #2
	ldrsh r1, [r6, r2]
	ldr r7, [sp, #0x10]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _08040C70 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #0x10]
	ldrb r0, [r2, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x11
	ble _08040B72
_08040BBC:
	ldr r3, _08040C94 @ =gMain+0x1380 @gMain.spriteGroups[23]
	str r3, [sp, #0x10]
	ldrh r0, [r3]
	cmp r0, #0
	beq _08040C54
	ldr r5, _08040C74 @ =gCurrentPinballGame
	ldr r4, [r5]
	ldr r7, _08040C84 @ =0x00000524
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08040C98 @ =0xFFFFFE98
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	ldr r3, [sp, #0x10]
	strh r0, [r3, #2]
	ldr r4, [r5]
	ldr r5, _08040C88 @ =0x00000526
	adds r0, r4, r5
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x80
	subs r0, r0, r1
	ldr r1, [sp, #0x10]
	strh r0, [r1, #4]
	movs r2, #0
	ldr r5, _08040C8C @ =gOamBuffer
	ldr r3, _08040C90 @ =0xFFFFFE00
	mov r8, r3
_08040C0C:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	ldr r7, [sp, #0x10]
	adds r6, r7, r0
	ldrh r3, [r6]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _08040C70 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #0x10]
	ldrb r0, [r2, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x11
	ble _08040C0C
_08040C54:
	ldr r0, _08040C74 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	ble _08040CA0
	ldr r5, _08040C9C @ =0x0000132C
	adds r0, r1, r5
	ldr r1, [r0]
	movs r0, #1
	b _08040CA8
	.align 2, 0
_08040C70: .4byte 0x000001FF
_08040C74: .4byte gCurrentPinballGame
_08040C78: .4byte 0x00000507
_08040C7C: .4byte gMain
_08040C80: .4byte gMain+0x12C8 @gMain.spriteGroups[22]
_08040C84: .4byte 0x00000524
_08040C88: .4byte 0x00000526
_08040C8C: .4byte gOamBuffer
_08040C90: .4byte 0xFFFFFE00
_08040C94: .4byte gMain+0x1380 @gMain.spriteGroups[23]
_08040C98: .4byte 0xFFFFFE98
_08040C9C: .4byte 0x0000132C
_08040CA0:
	ldr r7, _08040CE4 @ =0x0000132C
	adds r0, r1, r7
	ldr r1, [r0]
	movs r0, #2
_08040CA8:
	strb r0, [r1, #1]
	movs r0, #0
	str r0, [sp, #0xc]
_08040CAE:
	ldr r1, [sp, #0xc]
	lsls r3, r1, #0x10
	asrs r2, r3, #0x10
	movs r0, #0xb8
	adds r1, r2, #0
	muls r1, r0, r1
	ldr r0, _08040CE8 @ =gMain+0xDC0 @gMain.spriteGroups[15]
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r1, _08040CEC @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r4, _08040CF0 @ =0x00000441
	adds r0, r0, r4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r3, [sp, #0x34]
	cmp r0, #5
	bls _08040CD8
	b _0804131A
_08040CD8:
	lsls r0, r0, #2
	ldr r1, _08040CF4 @ =_08040CF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040CE4: .4byte 0x0000132C
_08040CE8: .4byte gMain+0xDC0 @gMain.spriteGroups[15]
_08040CEC: .4byte gCurrentPinballGame
_08040CF0: .4byte 0x00000441
_08040CF4: .4byte _08040CF8
_08040CF8: @ jump table
	.4byte _08040D10 @ case 0
	.4byte _08040D3C @ case 1
	.4byte _08040D7C @ case 2
	.4byte _0804103C @ case 3
	.4byte _0804120C @ case 4
	.4byte _080412D8 @ case 5
_08040D10:
	movs r5, #0
	str r5, [sp]
	ldr r0, _08040D30 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r7, [sp, #0x34]
	asrs r0, r7, #0xe
	adds r1, r1, r0
	ldr r2, _08040D34 @ =0x0000045C
	adds r0, r1, r2
	strh r5, [r0]
	ldr r4, _08040D38 @ =0x0000045E
	adds r1, r1, r4
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1]
	b _0804131A
	.align 2, 0
_08040D30: .4byte gCurrentPinballGame
_08040D34: .4byte 0x0000045C
_08040D38: .4byte 0x0000045E
_08040D3C:
	ldr r0, _08040D74 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r0, [sp, #0x34]
	asrs r7, r0, #0x10
	lsls r1, r7, #1
	movs r2, #0x8b
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r5, r0, r1
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #5
	bl __udivsi3
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	cmp r4, #0xd
	bhi _08040D66
	b _08041300
_08040D66:
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08040D78 @ =0x00000441
	adds r0, r6, r3
	adds r0, r0, r7
	movs r1, #2
	b _08041318
	.align 2, 0
_08040D74: .4byte gCurrentPinballGame
_08040D78: .4byte 0x00000441
_08040D7C:
	ldr r4, _08040FE0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, [sp, #0x34]
	asrs r1, r5, #0xf
	movs r7, #0x8b
	lsls r7, r7, #3
	adds r0, r0, r7
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	movs r0, #4
	str r0, [sp]
	cmp r1, #3
	ble _08040DA6
	movs r2, #6
	str r2, [sp]
	cmp r1, #9
	bgt _08040DA6
	movs r3, #5
	str r3, [sp]
_08040DA6:
	ldr r4, _08040FE0 @ =gCurrentPinballGame
	mov sl, r4
	ldr r0, [r4]
	ldr r5, [sp, #0x34]
	asrs r5, r5, #0x10
	mov sb, r5
	ldr r7, _08040FE4 @ =0x00000441
	adds r0, r0, r7
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _08040DC4
	b _08040FC0
_08040DC4:
	ldr r0, _08040FE8 @ =gMain
	lsls r1, r5, #4
	subs r1, r1, r5
	lsls r1, r1, #3
	ldr r0, [r0, #0x4c]
	adds r0, r0, r1
	movs r1, #0xf0
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0xf0
	bl __udivsi3
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0
	bl Cos
	ldr r4, [r4]
	mov r1, sb
	lsls r1, r1, #2
	str r1, [sp, #0x24]
	adds r4, r4, r1
	ldr r2, _08040FEC @ =0x00000464
	adds r6, r4, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0xfa
	lsls r3, r3, #1
	mov r8, r3
	mov r1, r8
	bl __divsi3
	ldrh r1, [r6]
	adds r1, r1, r0
	adds r7, #0x1b
	adds r4, r4, r7
	strh r1, [r4]
	adds r0, r5, #0
	bl Sin
	mov r1, sl
	ldr r7, [r1]
	ldr r2, [sp, #0x24]
	adds r5, r7, r2
	ldr r3, _08040FF0 @ =0x00000466
	adds r4, r5, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	ldr r4, _08040FF4 @ =0x0000045E
	mov r8, r4
	adds r2, r5, r4
	strh r1, [r2]
	ldr r1, _08040FF8 @ =0x0000132C
	adds r0, r7, r1
	ldr r6, [r0]
	movs r3, #0x10
	ldrsh r4, [r6, r3]
	ldr r0, _08040FFC @ =0x0000045C
	adds r5, r5, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	str r2, [sp, #0x38]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r4, r4, r0
	subs r4, #0x10
	str r4, [sp, #0x1c]
	movs r3, #0x12
	ldrsh r4, [r6, r3]
	ldr r2, [sp, #0x38]
	movs r5, #0
	ldrsh r0, [r2, r5]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r4, r4, r0
	subs r4, #0x20
	str r4, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r5, r1, r0
	ldr r1, _08041000 @ =0x00000383
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08040E94
	b _08040FC0
_08040E94:
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08040EA6
	b _08040FC0
_08040EA6:
	ldr r3, _08041004 @ =0x00000385
	adds r0, r7, r3
	movs r4, #0xe1
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	blt _08040EBE
	b _08040FC0
_08040EBE:
	ldr r1, _08041008 @ =0x00000452
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _08040FC0
	ldr r6, _0804100C @ =0x0000012B
	cmp r5, r6
	bgt _08040FC0
	ldr r2, _08041010 @ =0x00000486
	adds r1, r7, r2
	movs r0, #6
	strh r0, [r1]
	movs r3, #1
	strb r3, [r7, #0x1f]
	mov r5, sl
	ldr r1, [r5]
	mov r7, sb
	lsls r2, r7, #1
	movs r5, #0x8b
	lsls r5, r5, #3
	adds r0, r1, r5
	adds r0, r0, r2
	strh r4, [r0]
	ldr r7, _08040FE4 @ =0x00000441
	adds r1, r1, r7
	add r1, sb
	movs r0, #3
	strb r0, [r1]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _08041014 @ =0x000005FA
	adds r0, r0, r2
	strb r3, [r0]
	ldr r5, [r1]
	ldr r3, [sp, #0x24]
	adds r4, r5, r3
	adds r7, #0x1b
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x10
	str r0, [sp, #0x14]
	add r4, r8
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x20
	str r0, [sp, #0x18]
	ldr r3, [sp, #0x14]
	lsls r1, r3, #8
	ldr r4, _08040FF8 @ =0x0000132C
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r0, [r2, #0x34]
	subs r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r7, [sp, #0x18]
	lsls r1, r7, #8
	ldr r0, [r2, #0x38]
	subs r0, r1, r0
	str r0, [sp, #0x20]
	ldr r4, _08041018 @ =0x000005AC
	adds r5, r5, r4
	ldr r1, [sp, #0x1c]
	adds r0, r1, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x20]
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
	ldr r4, [sp, #0x1c]
	rsbs r0, r4, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r5, [sp, #0x20]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	mov r7, sl
	ldr r2, [r7]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r2, r3
	strh r0, [r1]
	ldr r0, [sp, #0xc]
	adds r0, #1
	ldr r4, _0804101C @ =0x00000505
	adds r2, r2, r4
	strb r0, [r2]
	ldr r2, [r7]
	ldr r5, [sp, #0x24]
	adds r1, r2, r5
	ldr r7, _08040FFC @ =0x0000045C
	adds r0, r1, r7
	ldrh r3, [r0]
	adds r4, #0x1b
	adds r0, r2, r4
	strh r3, [r0]
	add r1, r8
	ldrh r0, [r1]
	ldr r5, _08041020 @ =0x00000522
	adds r2, r2, r5
	strh r0, [r2]
	adds r0, r6, #0
	bl m4aSongNumStart
	movs r0, #0xd
	bl sub_11B0
_08040FC0:
	ldr r0, _08040FE0 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r7, [sp, #0x34]
	asrs r4, r7, #0x10
	lsls r1, r4, #1
	movs r2, #0x8b
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r1, r0, r1
	ldrh r2, [r1]
	ldr r0, _08041024 @ =0x00000347
	cmp r2, r0
	bhi _08041028
	adds r0, r2, #1
	strh r0, [r1]
	b _0804131A
	.align 2, 0
_08040FE0: .4byte gCurrentPinballGame
_08040FE4: .4byte 0x00000441
_08040FE8: .4byte gMain
_08040FEC: .4byte 0x00000464
_08040FF0: .4byte 0x00000466
_08040FF4: .4byte 0x0000045E
_08040FF8: .4byte 0x0000132C
_08040FFC: .4byte 0x0000045C
_08041000: .4byte 0x00000383
_08041004: .4byte 0x00000385
_08041008: .4byte 0x00000452
_0804100C: .4byte 0x0000012B
_08041010: .4byte 0x00000486
_08041014: .4byte 0x000005FA
_08041018: .4byte 0x000005AC
_0804101C: .4byte 0x00000505
_08041020: .4byte 0x00000522
_08041024: .4byte 0x00000347
_08041028:
	movs r0, #0
	strh r0, [r1]
	ldr r5, _08041038 @ =0x00000441
	adds r0, r3, r5
	adds r0, r0, r4
	movs r1, #5
	b _08041318
	.align 2, 0
_08041038: .4byte 0x00000441
_0804103C:
	ldr r7, _080411E4 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r2, [sp, #0x34]
	asrs r1, r2, #0xf
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	movs r4, #4
	str r4, [sp]
	cmp r1, #3
	ble _08041066
	movs r5, #6
	str r5, [sp]
	cmp r1, #9
	bgt _08041066
	movs r7, #5
	str r7, [sp]
_08041066:
	ldr r0, _080411E4 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r1, [sp, #0x34]
	asrs r1, r1, #0x10
	str r1, [sp, #0x28]
	lsls r2, r1, #1
	str r2, [sp, #0x2c]
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r6, r3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x1d
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bgt _0804108E
	movs r4, #0xa
_0804108E:
	movs r5, #0xb6
	lsls r5, r5, #3
	mov sl, r5
	adds r5, r6, r5
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
	ldr r7, _080411E8 @ =0x0000132C
	adds r0, r6, r7
	ldr r1, [r0]
	ldr r2, _080411EC @ =0xFFFFE000
	adds r0, r2, #0
	ldrh r3, [r1, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #0xa]
	ldr r7, _080411F0 @ =0x000005AC
	adds r0, r6, r7
	ldr r0, [r0]
	muls r0, r4, r0
	movs r1, #0x1e
	bl __divsi3
	mov sb, r0
	ldr r0, [sp, #0x28]
	lsls r4, r0, #2
	adds r4, r6, r4
	ldr r1, _080411F4 @ =0x0000045C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x10
	str r0, [sp, #0x14]
	ldr r3, _080411F8 @ =0x0000045E
	adds r4, r4, r3
	movs r7, #0
	ldrsh r0, [r4, r7]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x20
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	bl Cos
	ldr r1, _080411E4 @ =gCurrentPinballGame
	ldr r5, [r1]
	ldr r2, _080411E8 @ =0x0000132C
	adds r1, r5, r2
	ldr r6, [r1]
	ldr r3, [sp, #0x14]
	lsls r4, r3, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	ldr r1, _080411FC @ =0x00004E20
	mov r8, r1
	bl __divsi3
	adds r4, r4, r0
	str r4, [r6, #0x34]
	add r5, sl
	ldrh r0, [r5]
	bl Sin
	ldr r2, _080411E4 @ =gCurrentPinballGame
	ldr r7, [r2]
	ldr r3, _080411E8 @ =0x0000132C
	adds r5, r7, r3
	ldr r6, [r5]
	ldr r1, [sp, #0x18]
	lsls r4, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	mov r1, r8
	bl __divsi3
	subs r4, r4, r0
	str r4, [r6, #0x38]
	ldr r4, [r5]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x30]
	ldr r4, [r5]
	movs r5, #0x32
	ldrsh r0, [r4, r5]
	lsls r0, r0, #2
	movs r1, #5
	bl __divsi3
	strh r0, [r4, #0x32]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, _08041200 @ =0x00000707
	cmp r1, r0
	bgt _0804119C
	ldr r4, _08041204 @ =0x0000038A
	adds r0, r7, r4
	movs r5, #0
	strh r5, [r0]
	ldrh r0, [r2]
	adds r0, #0x20
	strh r0, [r2]
_0804119C:
	ldr r7, _080411E4 @ =gCurrentPinballGame
	ldr r2, [r7]
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, [sp, #0x2c]
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, #0xb3
	bhi _080411B2
	b _080412BE
_080411B2:
	movs r4, #0
	strh r4, [r1]
	ldr r5, _08041208 @ =0x00000441
	adds r0, r2, r5
	ldr r7, [sp, #0x28]
	adds r0, r0, r7
	movs r1, #4
	strb r1, [r0]
	ldr r0, _080411E4 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r1, _080411F0 @ =0x000005AC
	adds r3, r2, r1
	ldr r0, [r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r3]
	ldr r3, _080411E8 @ =0x0000132C
	adds r2, r2, r3
	ldr r1, [r2]
	movs r0, #0xa5
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	b _0804131A
	.align 2, 0
_080411E4: .4byte gCurrentPinballGame
_080411E8: .4byte 0x0000132C
_080411EC: .4byte 0xFFFFE000
_080411F0: .4byte 0x000005AC
_080411F4: .4byte 0x0000045C
_080411F8: .4byte 0x0000045E
_080411FC: .4byte 0x00004E20
_08041200: .4byte 0x00000707
_08041204: .4byte 0x0000038A
_08041208: .4byte 0x00000441
_0804120C:
	ldr r4, _080412C4 @ =gCurrentPinballGame
	mov sl, r4
	ldr r0, [r4]
	ldr r5, [sp, #0x34]
	asrs r5, r5, #0x10
	str r5, [sp, #0x30]
	lsls r7, r5, #1
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0x81
	bhi _0804131A
	cmp r0, #0xa
	bne _08041234
	movs r0, #0x96
	lsls r0, r0, #1
	bl m4aSongNumStart
_08041234:
	mov r2, sl
	ldr r6, [r2]
	ldr r4, _080412C8 @ =0x0000038A
	adds r3, r6, r4
	ldrh r1, [r3]
	subs r1, #1
	movs r5, #0
	mov sb, r5
	movs r0, #0
	mov r8, r0
	strh r1, [r3]
	adds r4, #2
	adds r2, r6, r4
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080412B0
	mov r5, r8
	strh r5, [r2]
	ldr r4, _080412CC @ =0x0000132C
	adds r0, r6, r4
	ldr r5, [r0]
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #7
	movs r1, #0xa
	bl __divsi3
	rsbs r0, r0, #0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r5, #0x32]
	mov r2, sb
	strb r2, [r6, #0x1f]
	mov r3, sl
	ldr r1, [r3]
	movs r5, #0x8b
	lsls r5, r5, #3
	adds r0, r1, r5
	adds r0, r0, r7
	mov r2, r8
	strh r2, [r0]
	adds r4, r1, r4
	ldr r0, [r4]
	strh r2, [r0, #0x30]
	ldr r3, _080412D0 @ =0x00000441
	adds r1, r1, r3
	ldr r4, [sp, #0x30]
	adds r1, r1, r4
	mov r5, sb
	strb r5, [r1]
	mov r1, sl
	ldr r0, [r1]
	ldr r2, _080412D4 @ =0x000005FA
	adds r0, r0, r2
	strb r5, [r0]
	movs r0, #8
	bl sub_11B0
_080412B0:
	mov r3, sl
	ldr r1, [r3]
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r1, r1, r7
	ldrh r0, [r1]
_080412BE:
	adds r0, #1
	strh r0, [r1]
	b _0804131A
	.align 2, 0
_080412C4: .4byte gCurrentPinballGame
_080412C8: .4byte 0x0000038A
_080412CC: .4byte 0x0000132C
_080412D0: .4byte 0x00000441
_080412D4: .4byte 0x000005FA
_080412D8:
	ldr r0, _08041308 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r5, [sp, #0x34]
	asrs r7, r5, #0x10
	lsls r1, r7, #1
	movs r2, #0x8b
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r5, r0, r1
	ldrh r4, [r5]
	adds r0, r4, #0
	movs r1, #6
	bl __udivsi3
	adds r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	cmp r4, #0xa
	bhi _0804130C
_08041300:
	adds r0, r4, #1
	strh r0, [r5]
	b _0804131A
	.align 2, 0
_08041308: .4byte gCurrentPinballGame
_0804130C:
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08041540 @ =0x00000441
	adds r0, r6, r3
	adds r0, r0, r7
_08041318:
	strb r1, [r0]
_0804131A:
	ldr r4, [sp, #0x10]
	ldrh r0, [r4]
	cmp r0, #0
	beq _08041400
	ldr r2, _08041544 @ =0x040000D4
	ldr r5, [sp]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08041548 @ =gUnknown_084A6EEC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804154C @ =0x06011EA0
	str r0, [r2, #4]
	ldr r0, _08041550 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _08041554 @ =gCurrentPinballGame
	ldr r5, [r0]
	ldr r7, [sp, #0x34]
	asrs r4, r7, #0xe
	adds r4, r5, r4
	ldr r1, _08041558 @ =0x0000045C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, [sp, #0x10]
	strh r0, [r3, #2]
	ldr r7, _0804155C @ =0x0000045E
	adds r4, r4, r7
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	adds r5, #0x5a
	ldrh r1, [r5]
	subs r0, r0, r1
	ldr r2, [sp, #0x10]
	strh r0, [r2, #4]
	movs r2, #0
	ldr r5, _08041560 @ =gOamBuffer
	ldr r3, _08041564 @ =0xFFFFFE00
	mov r8, r3
_08041384:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r4, [sp, #0x10]
	adds r6, r4, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	adds r2, r2, r5
	movs r7, #2
	ldrsh r1, [r6, r7]
	movs r7, #2
	ldrsh r0, [r4, r7]
	adds r1, r1, r0
	ldr r4, _08041568 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, r8
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r7, [sp, #0x10]
	ldrb r0, [r7, #4]
	ldrb r6, [r6, #4]
	adds r0, r0, r6
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08041384
	ldr r1, _08041554 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, [sp, #0x34]
	asrs r2, r3, #0x10
	ldr r4, _08041540 @ =0x00000441
	adds r0, r0, r4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080413E6
	strh r0, [r7]
_080413E6:
	ldr r0, [r1]
	ldr r5, _0804156C @ =0x00000505
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _08041400
	subs r0, #1
	cmp r2, r0
	bne _08041400
	movs r0, #0
	ldr r7, [sp, #0x10]
	strh r0, [r7]
_08041400:
	ldr r1, [sp, #0x34]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r1, r2
	lsrs r3, r0, #0x10
	str r3, [sp, #0xc]
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08041414
	b _08040CAE
_08041414:
	bl sub_417F8
	ldr r4, _08041570 @ =gMain+0x1158 @gMain.spriteGroups[20]
	str r4, [sp, #0x10]
	ldrh r0, [r4]
	cmp r0, #0
	beq _0804150E
	ldr r5, _08041554 @ =gCurrentPinballGame
	ldr r4, [r5]
	movs r7, #0xa4
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r0, r0, r1
	ldr r2, [sp, #0x10]
	strh r0, [r2, #2]
	ldr r4, [r5]
	ldr r3, _08041574 @ =0x00000522
	adds r0, r4, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	ldr r1, [sp, #0x10]
	strh r0, [r1, #4]
	ldr r0, [r5]
	ldr r2, _08041578 @ =0x0000050E
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #5
	bl __udivsi3
	movs r2, #0
	ldr r3, _0804157C @ =gUnknown_086B5CC0
	mov sl, r3
	ldr r4, _08041560 @ =gOamBuffer
	mov ip, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	mov r8, r1
	ldr r5, _08041564 @ =0xFFFFFE00
	mov sb, r5
_08041482:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	ldr r7, [sp, #0x10]
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	mov r1, ip
	adds r5, r0, r1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sl
	mov r2, r8
	adds r1, r2, r0
	ldrh r0, [r1]
	strh r0, [r5]
	adds r1, #2
	adds r5, #2
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	strh r0, [r5, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r7, _08041568 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, ip
	ldr r2, [sp, #0x10]
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #4
	ble _08041482
	ldr r0, _08041554 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r5, _08041578 @ =0x0000050E
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0x18
	bhi _0804150E
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x19
	bne _0804150E
	movs r0, #0
	ldr r7, [sp, #0x10]
	strh r0, [r7]
_0804150E:
	ldr r1, _08041554 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _0804156C @ =0x00000505
	adds r2, r0, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08041530
	movs r0, #0
	strb r0, [r2]
	ldr r1, [r1]
	ldr r4, _08041578 @ =0x0000050E
	adds r1, r1, r4
	strh r0, [r1]
	movs r0, #1
	ldr r5, [sp, #0x10]
	strh r0, [r5]
_08041530:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041540: .4byte 0x00000441
_08041544: .4byte 0x040000D4
_08041548: .4byte gUnknown_084A6EEC
_0804154C: .4byte 0x06011EA0
_08041550: .4byte 0x80000140
_08041554: .4byte gCurrentPinballGame
_08041558: .4byte 0x0000045C
_0804155C: .4byte 0x0000045E
_08041560: .4byte gOamBuffer
_08041564: .4byte 0xFFFFFE00
_08041568: .4byte 0x000001FF
_0804156C: .4byte 0x00000505
_08041570: .4byte gMain+0x1158 @gMain.spriteGroups[20]
_08041574: .4byte 0x00000522
_08041578: .4byte 0x0000050E
_0804157C: .4byte gUnknown_086B5CC0

	thumb_func_start sub_41580
sub_41580: @ 0x08041580
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080415F4 @ =gMain+0x1CD8 @gMain.spriteGroups[36]
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08041596
	b _080417D0
_08041596:
	ldr r1, _080415F8 @ =gCurrentPinballGame
	ldr r5, [r1]
	ldr r2, _080415FC @ =0x00000486
	adds r6, r5, r2
	ldrh r7, [r6]
	subs r0, r7, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sl, r1
	cmp r0, #5
	bgt _080415B0
	b _080416C2
_080415B0:
	ldr r4, _08041600 @ =gUnknown_08137D48
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0x21
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r8, r0
	ldr r1, _08041604 @ =0x0000047F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08041658
	cmp r0, #7
	bne _0804160C
	ldr r2, _08041608 @ =0x0000132C
	adds r0, r5, r2
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r0, r4
	b _0804163A
	.align 2, 0
_080415F4: .4byte gMain+0x1CD8 @gMain.spriteGroups[36]
_080415F8: .4byte gCurrentPinballGame
_080415FC: .4byte 0x00000486
_08041600: .4byte gUnknown_08137D48
_08041604: .4byte 0x0000047F
_08041608: .4byte 0x0000132C
_0804160C:
	cmp r0, #4
	bne _08041628
	ldr r7, _08041620 @ =0x0000132C
	adds r0, r5, r7
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	ldr r2, _08041624 @ =0xFFFFFE00
	adds r0, r0, r2
	b _0804163A
	.align 2, 0
_08041620: .4byte 0x0000132C
_08041624: .4byte 0xFFFFFE00
_08041628:
	cmp r0, #1
	bne _0804163C
	ldr r4, _0804164C @ =0x0000132C
	adds r0, r5, r4
	ldr r1, [r0]
	ldr r0, [r1, #0x34]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
_0804163A:
	str r0, [r1, #0x34]
_0804163C:
	ldr r0, _08041650 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r7, _08041654 @ =0x0000047F
	adds r1, r1, r7
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08041682
	.align 2, 0
_0804164C: .4byte 0x0000132C
_08041650: .4byte gCurrentPinballGame
_08041654: .4byte 0x0000047F
_08041658:
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq _08041682
	adds r0, r7, #0
	subs r0, #0x1f
	strh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _08041670
	movs r0, #5
	strh r0, [r6]
_08041670:
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #7
	strb r1, [r0]
	movs r0, #0x95
	lsls r0, r0, #1
	bl m4aSongNumStart
_08041682:
	ldr r0, _080416A8 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r7, #0x90
	lsls r7, r7, #3
	adds r4, r5, r7
	ldrh r3, [r4]
	mov sl, r0
	cmp r3, #0
	beq _080416B6
	subs r0, r3, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x34
	bls _080416AC
	movs r0, #8
	mov r8, r0
	b _080416C6
	.align 2, 0
_080416A8: .4byte gCurrentPinballGame
_080416AC:
	cmp r0, #0x2a
	bls _080416C6
	movs r1, #9
	mov r8, r1
	b _080416C6
_080416B6:
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq _080416C6
	movs r0, #0x3c
	strh r0, [r4]
	b _080416C6
_080416C2:
	movs r2, #8
	mov r8, r2
_080416C6:
	mov r4, sl
	ldr r1, [r4]
	ldr r5, _080416F4 @ =0x00000486
	adds r0, r1, r5
	movs r7, #0
	ldrsh r3, [r0, r7]
	cmp r3, #0
	bne _08041704
	ldr r0, _080416F8 @ =gMain
	ldr r1, _080416FC @ =0x00001CD8
	adds r0, r0, r1
	movs r2, #0
	strh r3, [r0]
	ldr r0, [r4]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r1, r0, r4
	strh r3, [r1]
	ldr r5, _08041700 @ =0x00000383
	adds r0, r0, r5
	strb r2, [r0]
	b _08041722
	.align 2, 0
_080416F4: .4byte 0x00000486
_080416F8: .4byte gMain
_080416FC: .4byte 0x00001CD8
_08041700: .4byte 0x00000383
_08041704:
	ldr r7, _080417E0 @ =0x00000383
	adds r1, r1, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	mov r1, sl
	ldr r0, [r1]
	ldr r4, _080417E4 @ =0x0000132C
	adds r0, r0, r4
	ldr r1, [r0]
	strh r2, [r1, #0x30]
	ldr r1, [r0]
	strh r2, [r1, #0x32]
	ldr r0, [r0]
	strh r2, [r0, #6]
_08041722:
	mov r5, sl
	ldr r2, [r5]
	ldr r7, _080417E4 @ =0x0000132C
	adds r3, r2, r7
	ldr r0, [r3]
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0, #0x10]
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	ldr r0, [r3]
	adds r2, #0x5a
	ldrh r0, [r0, #0x12]
	ldrh r1, [r2]
	subs r0, r0, r1
	subs r0, #8
	mov r2, sb
	strh r0, [r2, #4]
	movs r2, #0
	mov r4, r8
	lsls r1, r4, #0x10
	ldr r5, _080417E8 @ =gUnknown_086B5D56
	mov sl, r5
	ldr r6, _080417EC @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r7, _080417F0 @ =0xFFFFFE00
	mov r8, r7
_08041766:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, sb
	ldrh r2, [r4]
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
	ldrh r2, [r4]
	lsls r2, r2, #3
	adds r2, r2, r6
	ldrh r0, [r2, #2]
	lsls r1, r0, #0x17
	lsrs r1, r1, #0x17
	mov r5, sb
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	ldr r5, _080417F4 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	mov r0, r8
	ldrh r7, [r2, #2]
	ands r0, r7
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, sb
	ldrb r0, [r2, #4]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08041766
_080417D0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080417E0: .4byte 0x00000383
_080417E4: .4byte 0x0000132C
_080417E8: .4byte gUnknown_086B5D56
_080417EC: .4byte gOamBuffer
_080417F0: .4byte 0xFFFFFE00
_080417F4: .4byte 0x000001FF

	thumb_func_start sub_417F8
sub_417F8: @ 0x080417F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _08041BD0 @ =gMain+0x1438 @gMain.spriteGroups[24]
	ldrh r0, [r6]
	ldr r1, _08041BD4 @ =gCurrentPinballGame
	mov sl, r1
	cmp r0, #0
	bne _08041810
	b _08041922
_08041810:
	ldr r4, [r1]
	movs r2, #0xa5
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r5, sl
	ldr r4, [r5]
	ldr r1, _08041BD8 @ =0x0000052A
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r3, #0xb8
	adds r3, r3, r6
	mov sb, r3
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r4, _08041BE0 @ =0xFFFFFE00
	mov r8, r4
_08041856:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041856
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _08041BD8 @ =0x0000052A
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r1, _08041BE0 @ =0xFFFFFE00
	mov r8, r1
_080418DE:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #0xd
	ble _080418DE
_08041922:
	ldr r6, _08041BE8 @ =gMain+0x15A8 @gMain.spriteGroups[26]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0804192C
	b _08041A40
_0804192C:
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _08041BD8 @ =0x0000052A
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r2, _08041BE0 @ =0xFFFFFE00
	mov r8, r2
_08041974:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041974
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _08041BD8 @ =0x0000052A
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r1, _08041BE0 @ =0xFFFFFE00
	mov r8, r1
_080419FC:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #8
	ble _080419FC
_08041A40:
	ldr r6, _08041BEC @ =gMain+0x1718 @gMain.spriteGroups[28]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08041A4A
	b _08041B5E
_08041A4A:
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _08041BD8 @ =0x0000052A
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r2, _08041BE0 @ =0xFFFFFE00
	mov r8, r2
_08041A92:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041A92
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	adds r1, #0x80
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r2, sl
	ldr r4, [r2]
	ldr r3, _08041BD8 @ =0x0000052A
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r1, _08041BE0 @ =0xFFFFFE00
	mov r8, r1
_08041B1A:
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
	ldr r2, _08041BE4 @ =0x000001FF
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
	cmp r4, #0xb
	ble _08041B1A
_08041B5E:
	ldr r6, _08041BF0 @ =gMain+0x1888 @gMain.spriteGroups[30]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08041B68
	b _08041CB0
_08041B68:
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041BF4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r2, #0xb8
	adds r2, r2, r6
	mov sb, r2
	ldr r7, _08041BDC @ =gOamBuffer
	ldr r3, _08041BE0 @ =0xFFFFFE00
	mov r8, r3
_08041BB4:
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
	b _08041BF8
	.align 2, 0
_08041BD0: .4byte gMain+0x1438 @gMain.spriteGroups[24]
_08041BD4: .4byte gCurrentPinballGame
_08041BD8: .4byte 0x0000052A
_08041BDC: .4byte gOamBuffer
_08041BE0: .4byte 0xFFFFFE00
_08041BE4: .4byte 0x000001FF
_08041BE8: .4byte gMain+0x15A8 @gMain.spriteGroups[26]
_08041BEC: .4byte gMain+0x1718 @gMain.spriteGroups[28]
_08041BF0: .4byte gMain+0x1888 @gMain.spriteGroups[30]
_08041BF4: .4byte 0xFFFFFE90
_08041BF8:
	adds r1, r1, r0
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041BB4
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041FB4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041FB8 @ =gOamBuffer
	ldr r2, _08041FBC @ =0xFFFFFE00
	mov r8, r2
_08041C6C:
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
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #0xd
	ble _08041C6C
_08041CB0:
	ldr r6, _08041FC0 @ =gMain+0x19F8 @gMain.spriteGroups[32]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08041CBA
	b _08041DD6
_08041CBA:
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041FB4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r2, #0xb8
	adds r2, r2, r6
	mov sb, r2
	ldr r7, _08041FB8 @ =gOamBuffer
	ldr r3, _08041FBC @ =0xFFFFFE00
	mov r8, r3
_08041D06:
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
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041D06
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041FB4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041FB8 @ =gOamBuffer
	ldr r2, _08041FBC @ =0xFFFFFE00
	mov r8, r2
_08041D92:
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
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #8
	ble _08041D92
_08041DD6:
	ldr r6, _08041FC4 @ =gMain+0x1B68 @gMain.spriteGroups[34]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08041DE0
	b _08041EFC
_08041DE0:
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041FB4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	movs r2, #0xb8
	adds r2, r2, r6
	mov sb, r2
	ldr r7, _08041FB8 @ =gOamBuffer
	ldr r3, _08041FBC @ =0xFFFFFE00
	mov r8, r3
_08041E2C:
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
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #0xe
	ble _08041E2C
	mov r6, sb
	mov r3, sl
	ldr r4, [r3]
	movs r5, #0xa5
	lsls r5, r5, #3
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldr r2, _08041FB4 @ =0xFFFFFE90
	adds r1, r2, #0
	ldrh r4, [r4]
	adds r1, r1, r4
	subs r0, r0, r1
	strh r0, [r6, #2]
	mov r3, sl
	ldr r4, [r3]
	adds r5, #2
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r1, #0x5a
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08041FB8 @ =gOamBuffer
	ldr r2, _08041FBC @ =0xFFFFFE00
	mov r8, r2
_08041EB8:
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
	ldr r2, _08041FB0 @ =0x000001FF
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
	cmp r4, #0xb
	ble _08041EB8
_08041EFC:
	ldr r3, _08041FC8 @ =gMain
	ldr r4, _08041FCC @ =0x000012C8
	adds r0, r3, r4
	ldrh r1, [r0]
	cmp r1, #0
	bne _08041F0A
	b _08042014
_08041F0A:
	ldr r0, _08041FD0 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r5, _08041FD4 @ =0x00000514
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #6
	bne _08041F7A
	ldr r1, _08041FD8 @ =0x00001438
	adds r0, r3, r1
	movs r1, #0
	strh r1, [r0]
	ldr r4, _08041FDC @ =0x000014F0
	adds r0, r3, r4
	strh r1, [r0]
	ldr r5, _08041FE0 @ =0x000015A8
	adds r0, r3, r5
	movs r1, #1
	strh r1, [r0]
	movs r4, #0xb3
	lsls r4, r4, #5
	adds r0, r3, r4
	strh r1, [r0]
	ldr r5, _08041FE4 @ =0x00000441
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08041F7A
	ldr r1, _08041FE8 @ =0x00000442
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08041F7A
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08041F7A
	ldr r4, _08041FEC @ =0x0000132C
	adds r0, r2, r4
	ldr r1, [r0]
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r2, [r1, #0x30]
	adds r0, r0, r2
	strh r0, [r1, #0x30]
	movs r0, #0xd
	bl sub_11B0
_08041F7A:
	ldr r4, _08041FD0 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r3, _08041FD4 @ =0x00000514
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0xb
	bne _08041FA6
	ldr r1, _08041FC8 @ =gMain
	ldr r5, _08041FE0 @ =0x000015A8
	adds r0, r1, r5
	movs r2, #0
	strh r2, [r0]
	adds r5, #0xb8
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _08041FF0 @ =0x00001718
	adds r0, r1, r2
	movs r2, #1
	strh r2, [r0]
	ldr r5, _08041FF4 @ =0x000017D0
	adds r1, r1, r5
	strh r2, [r1]
_08041FA6:
	ldr r0, [r4]
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0xe
	b _08041FF8
	.align 2, 0
_08041FB0: .4byte 0x000001FF
_08041FB4: .4byte 0xFFFFFE90
_08041FB8: .4byte gOamBuffer
_08041FBC: .4byte 0xFFFFFE00
_08041FC0: .4byte gMain+0x19F8 @gMain.spriteGroups[32]
_08041FC4: .4byte gMain+0x1B68 @gMain.spriteGroups[34]
_08041FC8: .4byte gMain
_08041FCC: .4byte 0x000012C8
_08041FD0: .4byte gCurrentPinballGame
_08041FD4: .4byte 0x00000514
_08041FD8: .4byte 0x00001438
_08041FDC: .4byte 0x000014F0
_08041FE0: .4byte 0x000015A8
_08041FE4: .4byte 0x00000441
_08041FE8: .4byte 0x00000442
_08041FEC: .4byte 0x0000132C
_08041FF0: .4byte 0x00001718
_08041FF4: .4byte 0x000017D0
_08041FF8:
	bne _080420CC
	ldr r0, _08042008 @ =gMain
	ldr r2, _0804200C @ =0x00001718
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	ldr r3, _08042010 @ =0x000017D0
	b _080420C8
	.align 2, 0
_08042008: .4byte gMain
_0804200C: .4byte 0x00001718
_08042010: .4byte 0x000017D0
_08042014:
	ldr r0, _08042274 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r4, _08042278 @ =0x00000514
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r0, #6
	bne _08042082
	ldr r5, _0804227C @ =gMain
	ldr r3, _08042280 @ =0x00001888
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xca
	lsls r4, r4, #5
	adds r0, r5, r4
	strh r1, [r0]
	ldr r1, _08042284 @ =0x000019F8
	adds r0, r5, r1
	movs r1, #1
	strh r1, [r0]
	ldr r3, _08042288 @ =0x00001AB0
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _0804228C @ =0x00000441
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08042082
	ldr r5, _08042290 @ =0x00000442
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08042082
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08042082
	ldr r3, _08042294 @ =0x0000132C
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r4, _08042298 @ =0xFFFFFE0C
	adds r0, r4, #0
	ldrh r5, [r1, #0x30]
	adds r0, r0, r5
	strh r0, [r1, #0x30]
	movs r0, #0xd
	bl sub_11B0
_08042082:
	ldr r4, _08042274 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r3, _08042278 @ =0x00000514
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0xb
	bne _080420B0
	ldr r1, _0804227C @ =gMain
	ldr r2, _08042284 @ =0x000019F8
	adds r0, r1, r2
	movs r2, #0
	strh r2, [r0]
	ldr r5, _08042288 @ =0x00001AB0
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _0804229C @ =0x00001B68
	adds r0, r1, r2
	movs r2, #1
	strh r2, [r0]
	movs r5, #0xe1
	lsls r5, r5, #5
	adds r1, r1, r5
	strh r2, [r1]
_080420B0:
	ldr r0, [r4]
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0xe
	bne _080420CC
	ldr r0, _0804227C @ =gMain
	ldr r2, _0804229C @ =0x00001B68
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	movs r3, #0xe1
	lsls r3, r3, #5
_080420C8:
	adds r0, r0, r3
	strh r2, [r0]
_080420CC:
	ldr r4, _08042274 @ =gCurrentPinballGame
	mov sb, r4
	ldr r1, [r4]
	ldr r5, _08042278 @ =0x00000514
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xa
	bne _08042184
	ldr r0, _0804228C @ =0x00000441
	adds r2, r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _08042184
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r0, #0
	strh r0, [r1]
	movs r1, #1
	strb r1, [r2]
	ldr r4, _0804227C @ =gMain
	movs r5, #0xdc
	lsls r5, r5, #4
	adds r0, r4, r5
	strh r1, [r0]
	bl Random
	adds r5, r0, #0
	movs r0, #7
	ands r5, r0
	ldr r0, [r4, #0x4c]
	movs r1, #0xf0
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0xf0
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, sb
	ldr r2, [r0]
	ldr r0, _080422A0 @ =gUnknown_086AF744
	lsls r1, r5, #2
	adds r1, r1, r0
	ldrh r3, [r1]
	ldr r5, _080422A4 @ =0x00000464
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r0, [r1, #2]
	ldr r6, _080422A8 @ =0x00000466
	adds r2, r2, r6
	strh r0, [r2]
	adds r0, r7, #0
	bl Cos
	mov r1, sb
	ldr r4, [r1]
	adds r5, r4, r5
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xfa
	lsls r2, r2, #1
	mov r8, r2
	mov r1, r8
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r1, r0
	ldr r3, _080422AC @ =0x0000045C
	adds r4, r4, r3
	strh r1, [r4]
	adds r0, r7, #0
	bl Sin
	mov r5, sb
	ldr r4, [r5]
	adds r6, r4, r6
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	bl __divsi3
	ldrh r1, [r6]
	adds r1, r1, r0
	ldr r0, _080422B0 @ =0x0000045E
	adds r4, r4, r0
	strh r1, [r4]
	ldr r0, _080422B4 @ =0x0000012D
	bl m4aSongNumStart
_08042184:
	ldr r1, _08042274 @ =gCurrentPinballGame
	mov sb, r1
	ldr r1, [r1]
	ldr r2, _08042278 @ =0x00000514
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _08042240
	ldr r3, _08042290 @ =0x00000442
	adds r2, r1, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #2
	bgt _08042240
	ldr r4, _080422B8 @ =0x0000045A
	adds r1, r1, r4
	movs r0, #0
	strh r0, [r1]
	movs r1, #1
	strb r1, [r2]
	ldr r4, _0804227C @ =gMain
	ldr r5, _080422BC @ =0x00000E78
	adds r0, r4, r5
	strh r1, [r0]
	bl Random
	movs r1, #7
	ands r1, r0
	adds r1, #8
	adds r5, r1, #0
	ldr r0, [r4, #0x4c]
	adds r0, #0x78
	movs r1, #0xf0
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0xf0
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, sb
	ldr r2, [r0]
	ldr r0, _080422A0 @ =gUnknown_086AF744
	lsls r1, r5, #2
	adds r1, r1, r0
	ldrh r3, [r1]
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r2, r5
	strh r3, [r0]
	ldrh r0, [r1, #2]
	ldr r6, _080422C0 @ =0x0000046A
	adds r2, r2, r6
	strh r0, [r2]
	adds r0, r7, #0
	bl Cos
	mov r1, sb
	ldr r4, [r1]
	adds r5, r4, r5
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0xfa
	lsls r2, r2, #1
	mov r8, r2
	mov r1, r8
	bl __divsi3
	ldrh r1, [r5]
	adds r1, r1, r0
	movs r3, #0x8c
	lsls r3, r3, #3
	adds r4, r4, r3
	strh r1, [r4]
	adds r0, r7, #0
	bl Sin
	mov r5, sb
	ldr r4, [r5]
	adds r6, r4, r6
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r1, r8
	bl __divsi3
	ldrh r1, [r6]
	adds r1, r1, r0
	ldr r0, _080422C4 @ =0x00000462
	adds r4, r4, r0
	strh r1, [r4]
	ldr r0, _080422B4 @ =0x0000012D
	bl m4aSongNumStart
_08042240:
	ldr r0, _08042274 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r3, #0x99
	lsls r3, r3, #3
	adds r2, r1, r3
	ldrb r3, [r2]
	movs r1, #0
	ldrsb r1, [r2, r1]
	mov sl, r0
	cmp r1, #0
	bgt _08042258
	b _0804235E
_08042258:
	subs r0, r3, #1
	strb r0, [r2]
	mov r4, sl
	ldr r5, [r4]
	movs r0, #0x99
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	bgt _080422CC
	ldr r4, _080422C8 @ =gUnknown_086AEF28
	b _0804232E
	.align 2, 0
_08042274: .4byte gCurrentPinballGame
_08042278: .4byte 0x00000514
_0804227C: .4byte gMain
_08042280: .4byte 0x00001888
_08042284: .4byte 0x000019F8
_08042288: .4byte 0x00001AB0
_0804228C: .4byte 0x00000441
_08042290: .4byte 0x00000442
_08042294: .4byte 0x0000132C
_08042298: .4byte 0xFFFFFE0C
_0804229C: .4byte 0x00001B68
_080422A0: .4byte gUnknown_086AF744
_080422A4: .4byte 0x00000464
_080422A8: .4byte 0x00000466
_080422AC: .4byte 0x0000045C
_080422B0: .4byte 0x0000045E
_080422B4: .4byte 0x0000012D
_080422B8: .4byte 0x0000045A
_080422BC: .4byte 0x00000E78
_080422C0: .4byte 0x0000046A
_080422C4: .4byte 0x00000462
_080422C8: .4byte gUnknown_086AEF28
_080422CC:
	cmp r0, #0x17
	ble _08042300
	cmp r0, #0x23
	bgt _080422FC
	ldr r4, _080422F8 @ =gUnknown_086AEF28
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _08042344
	.align 2, 0
_080422F8: .4byte gUnknown_086AEF28
_080422FC:
	cmp r0, #0x2f
	bgt _08042328
_08042300:
	ldr r4, _08042324 @ =gUnknown_086AEF28
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	movs r4, #0xab
	lsls r4, r4, #2
	adds r1, r5, r4
	strh r0, [r1]
	b _08042344
	.align 2, 0
_08042324: .4byte gUnknown_086AEF28
_08042328:
	ldr r4, _08042394 @ =gUnknown_086AEF28
	movs r0, #0
	ldrsb r0, [r1, r0]
_0804232E:
	movs r1, #0xc
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r2, #0xab
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_08042344:
	mov r3, sl
	ldr r2, [r3]
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r2, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0804235E
	movs r5, #0xab
	lsls r5, r5, #2
	adds r0, r2, r5
	strh r1, [r0]
_0804235E:
	mov r0, sl
	ldr r2, [r0]
	movs r3, #0xa1
	lsls r3, r3, #3
	adds r1, r2, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _080423C2
	adds r1, r0, #0
	cmp r1, #0
	bge _08042378
	adds r0, r1, #3
_08042378:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	cmp r1, #0
	beq _0804239C
	ldr r0, _08042398 @ =0x000002AA
	adds r1, r2, r0
	movs r0, #2
	b _080423A2
	.align 2, 0
_08042394: .4byte gUnknown_086AEF28
_08042398: .4byte 0x000002AA
_0804239C:
	ldr r3, _080423D0 @ =0x000002AA
	adds r1, r2, r3
	ldr r0, _080423D4 @ =0x0000FFFE
_080423A2:
	strh r0, [r1]
	mov r5, sl
	ldr r4, [r5]
	movs r0, #0xa1
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _080423C2
	ldr r2, _080423D0 @ =0x000002AA
	adds r0, r4, r2
	strh r1, [r0]
_080423C2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080423D0: .4byte 0x000002AA
_080423D4: .4byte 0x0000FFFE

	thumb_func_start sub_423D8
sub_423D8: @ 0x080423D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0804267C @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r2, _08042680 @ =0x00000506
	adds r1, r3, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r1, #0
	beq _080423F8
	b _08042AB2
_080423F8:
	ldr r4, _08042684 @ =0x00000516
	adds r1, r3, r4
	ldrh r2, [r1]
	movs r0, #0xac
	lsls r0, r0, #2
	cmp r2, r0
	bls _08042408
	b _08042AB2
_08042408:
	subs r0, #0x78
	cmp r2, r0
	bhi _08042484
	adds r0, r2, #0
	movs r1, #0xa0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x14
	bne _08042428
	ldr r0, _08042688 @ =gMPlayInfo_SE1
	ldr r1, _0804268C @ =0x0000FFFF
	movs r2, #0x80
	bl m4aMPlayVolumeControl
_08042428:
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xa0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5a
	bne _08042446
	ldr r0, _08042688 @ =gMPlayInfo_SE1
	movs r1, #5
	bl m4aMPlayFadeOutTemporarily
_08042446:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xa0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08042464
	movs r0, #0x97
	lsls r0, r0, #1
	bl m4aSongNumStart
_08042464:
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xa0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne _08042484
	ldr r0, _08042688 @ =gMPlayInfo_SE1
	ldr r1, _0804268C @ =0x0000FFFF
	movs r2, #0x33
	bl m4aMPlayVolumeControl
_08042484:
	ldr r2, _0804267C @ =gCurrentPinballGame
	ldr r5, [r2]
	ldr r4, _08042684 @ =0x00000516
	adds r3, r5, r4
	ldrh r1, [r3]
	ldr r0, _08042690 @ =0x000001FF
	mov r8, r2
	cmp r1, r0
	bls _080424AA
	adds r0, r1, #0
	ldr r3, _08042694 @ =0xFFFFFE00
	adds r0, r0, r3
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, #0x58
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
_080424AA:
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r0, #0x9c
	lsls r0, r0, #2
	cmp r1, r0
	bne _080424C4
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
_080424C4:
	mov r0, r8
	ldr r3, [r0]
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bhi _080424E0
	adds r0, r1, #0
	lsrs r0, r0, #1
	movs r2, #0xa3
	lsls r2, r2, #3
	adds r1, r3, r2
	strh r0, [r1]
_080424E0:
	mov r3, r8
	ldr r2, [r3]
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #2
	cmp r1, r0
	bne _080424F8
	ldr r0, _08042680 @ =0x00000506
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
_080424F8:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x8e
	lsls r0, r0, #0x12
	cmp r1, r0
	bhi _0804251C
	ldr r3, _08042698 @ =0x00000392
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, #5
	bls _0804251C
	subs r0, #1
	strh r0, [r1]
_0804251C:
	mov r4, r8
	ldr r2, [r4]
	ldr r3, _08042684 @ =0x00000516
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #1
	bne _08042562
	movs r0, #0xf1
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _0804269C @ =0x000003C6
	adds r0, r2, r1
	adds r1, #0xea
	strh r1, [r0]
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, _080426A0 @ =0x000003CA
	adds r1, r2, r0
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	adds r4, #4
	adds r1, r2, r4
	movs r0, #0xfa
	lsls r0, r0, #2
	strh r0, [r1]
	subs r0, #0x1a
	adds r1, r2, r0
	ldr r0, _080426A4 @ =0x000009C4
	strh r0, [r1]
_08042562:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x58
	bne _08042584
	movs r4, #0xf1
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, _0804269C @ =0x000003C6
	adds r1, r2, r0
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
_08042584:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _080425A6
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r0, _080426A0 @ =0x000003CA
	adds r1, r2, r0
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
_080425A6:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0xaa
	bne _080425C8
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
	ldr r0, _080426A8 @ =0x000003CE
	adds r1, r2, r0
	movs r0, #0xfa
	lsls r0, r0, #3
	strh r0, [r1]
_080425C8:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0xd7
	bne _080425E8
	movs r4, #0xf1
	lsls r4, r4, #2
	adds r1, r2, r4
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0804269C @ =0x000003C6
	adds r1, r2, r0
	movs r0, #0xfa
	lsls r0, r0, #3
	strh r0, [r1]
_080425E8:
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r3
	ldrh r1, [r0]
	ldr r0, _080426AC @ =0x00000131
	cmp r1, r0
	bne _08042608
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r1, #0xe1
	lsls r1, r1, #3
	strh r1, [r0]
	adds r4, #2
	adds r0, r2, r4
	strh r1, [r0]
_08042608:
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r3
	ldrh r1, [r0]
	ldr r0, _080426B0 @ =0x0000013B
	cmp r1, r0
	bne _0804262A
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r2, r3
	subs r0, #0xf
	strh r0, [r1]
	ldr r4, _080426A8 @ =0x000003CE
	adds r1, r2, r4
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r1]
_0804262A:
	ldr r6, _080426B4 @ =gMain+0xAE0 @gMain.spriteGroups[11]
	ldrh r0, [r6]
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r2, r2, r6
	mov sl, r2
	cmp r0, #0
	beq _08042728
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xf1
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _0804269C @ =0x000003C6
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _080426B8
	strh r1, [r6, #4]
	b _080426C6
	.align 2, 0
_0804267C: .4byte gCurrentPinballGame
_08042680: .4byte 0x00000506
_08042684: .4byte 0x00000516
_08042688: .4byte gMPlayInfo_SE1
_0804268C: .4byte 0x0000FFFF
_08042690: .4byte 0x000001FF
_08042694: .4byte 0xFFFFFE00
_08042698: .4byte 0x00000392
_0804269C: .4byte 0x000003C6
_080426A0: .4byte 0x000003CA
_080426A4: .4byte 0x000009C4
_080426A8: .4byte 0x000003CE
_080426AC: .4byte 0x00000131
_080426B0: .4byte 0x0000013B
_080426B4: .4byte gMain+0xAE0 @gMain.spriteGroups[11]
_080426B8:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, _0804276C @ =0x000003C6
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
_080426C6:
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc8
	ble _080426D2
	movs r0, #0xb4
	strh r0, [r6, #4]
_080426D2:
	movs r0, #0
	ldr r4, _08042770 @ =gMain+0xB98 @gMain.spriteGroups[12]
	mov sb, r4
	movs r1, #0xb8
	add r1, sb
	mov sl, r1
	ldr r7, _08042774 @ =gOamBuffer
	ldr r2, _08042778 @ =0xFFFFFE00
	mov ip, r2
_080426E4:
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
	ldr r2, _0804277C @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	cmp r4, #3
	ble _080426E4
_08042728:
	mov r6, sb
	ldrh r0, [r6]
	cmp r0, #0
	beq _080427EE
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _08042780 @ =0x000003CA
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _08042788
	ldr r0, _08042784 @ =0x0000FFC4
	strh r0, [r6, #4]
	b _08042796
	.align 2, 0
_0804276C: .4byte 0x000003C6
_08042770: .4byte gMain+0xB98 @gMain.spriteGroups[12]
_08042774: .4byte gOamBuffer
_08042778: .4byte 0xFFFFFE00
_0804277C: .4byte 0x000001FF
_08042780: .4byte 0x000003CA
_08042784: .4byte 0x0000FFC4
_08042788:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, _08042834 @ =0x000003CA
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #0xc
	strh r0, [r1]
_08042796:
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc8
	ble _080427A2
	movs r0, #0xb4
	strh r0, [r6, #4]
_080427A2:
	movs r0, #0
	ldr r7, _08042838 @ =gOamBuffer
	ldr r4, _0804283C @ =0xFFFFFE00
	mov ip, r4
_080427AA:
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
	ldr r2, _08042840 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	cmp r4, #5
	ble _080427AA
_080427EE:
	mov r6, sl
	ldrh r0, [r6]
	cmp r0, #0
	beq _080428B2
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _08042844 @ =0x000003CE
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0804284C
	ldr r0, _08042848 @ =0x0000FFC4
	strh r0, [r6, #4]
	b _0804285A
	.align 2, 0
_08042834: .4byte 0x000003CA
_08042838: .4byte gOamBuffer
_0804283C: .4byte 0xFFFFFE00
_08042840: .4byte 0x000001FF
_08042844: .4byte 0x000003CE
_08042848: .4byte 0x0000FFC4
_0804284C:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, _0804290C @ =0x000003CE
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #0x12
	strh r0, [r1]
_0804285A:
	movs r3, #4
	ldrsh r0, [r6, r3]
	cmp r0, #0xc8
	ble _08042866
	movs r0, #0xb4
	strh r0, [r6, #4]
_08042866:
	movs r0, #0
	ldr r7, _08042910 @ =gOamBuffer
	ldr r4, _08042914 @ =0xFFFFFE00
	mov ip, r4
_0804286E:
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
	ldr r2, _08042918 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	cmp r4, #4
	ble _0804286E
_080428B2:
	mov r3, r8
	ldr r0, [r3]
	ldr r2, _0804291C @ =0x00000516
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0xa5
	lsls r0, r0, #2
	cmp r1, r0
	bne _080428DC
	ldr r4, _08042920 @ =gMain
	movs r1, #0xae
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _08042924 @ =0x00000B98
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #0xb8
	adds r0, r4, r3
	strh r1, [r0]
_080428DC:
	ldr r6, _08042928 @ =gMain+0xD08 @gMain.spriteGroups[14]
	ldrh r0, [r6]
	cmp r0, #0
	beq _080429CA
	mov r4, r8
	ldr r0, [r4]
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r0, #0xc3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _08042930
	ldr r0, _0804292C @ =gUnknown_086AF784
	ldrh r1, [r1]
	subs r1, #0xc3
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r7, [r1]
	b _08042938
	.align 2, 0
_0804290C: .4byte 0x000003CE
_08042910: .4byte gOamBuffer
_08042914: .4byte 0xFFFFFE00
_08042918: .4byte 0x000001FF
_0804291C: .4byte 0x00000516
_08042920: .4byte gMain
_08042924: .4byte 0x00000B98
_08042928: .4byte gMain+0xD08 @gMain.spriteGroups[14]
_0804292C: .4byte gUnknown_086AF784
_08042930:
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	lsrs r7, r0, #1
_08042938:
	mov r0, r8
	ldr r4, [r0]
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	ldr r3, _08042A40 @ =0x0000041A
	adds r4, r4, r3
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0804296E
	ldr r0, _08042A44 @ =0x0000FFC4
	strh r0, [r6, #4]
_0804296E:
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0xb4
	ble _0804297A
	movs r0, #0xb4
	strh r0, [r6, #4]
_0804297A:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _08042A48 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08042A4C @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08042A50 @ =0xFFFFFE00
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
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	lsls r1, r7, #0x10
	asrs r1, r1, #0xe
	adds r1, #0x7d
	ldr r4, _08042A54 @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	ldr r0, _08042A58 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
_080429CA:
	mov r1, r8
	ldr r0, [r1]
	ldr r4, _08042A5C @ =0x00000516
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x96
	bne _08042A0A
	ldr r2, _08042A60 @ =gMain
	ldr r3, _08042A64 @ =0x00000D08
	adds r1, r2, r3
	movs r0, #1
	strh r0, [r1]
	mov r0, r8
	ldr r1, [r0]
	movs r3, #0x83
	lsls r3, r3, #3
	adds r2, r1, r3
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r0, _08042A40 @ =0x0000041A
	adds r2, r1, r0
	ldr r0, _08042A68 @ =0x0000FF9C
	strh r0, [r2]
	subs r3, #4
	adds r2, r1, r3
	adds r0, #0x4f
	strh r0, [r2]
	ldr r0, _08042A6C @ =0x00000416
	adds r1, r1, r0
	movs r0, #0xe
	strh r0, [r1]
_08042A0A:
	mov r1, r8
	ldr r3, [r1]
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0xcd
	bls _08042A70
	ldr r4, _08042A6C @ =0x00000416
	adds r2, r3, r4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r0, #0x83
	lsls r0, r0, #3
	adds r1, r3, r0
	subs r4, #2
	adds r0, r3, r4
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r0, _08042A40 @ =0x0000041A
	adds r1, r3, r0
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _08042A94
	.align 2, 0
_08042A40: .4byte 0x0000041A
_08042A44: .4byte 0x0000FFC4
_08042A48: .4byte gOamBuffer
_08042A4C: .4byte 0x000001FF
_08042A50: .4byte 0xFFFFFE00
_08042A54: .4byte 0x000003FF
_08042A58: .4byte 0xFFFFFC00
_08042A5C: .4byte 0x00000516
_08042A60: .4byte gMain
_08042A64: .4byte 0x00000D08
_08042A68: .4byte 0x0000FF9C
_08042A6C: .4byte 0x00000416
_08042A70:
	cmp r0, #0x96
	bls _08042A96
	movs r4, #0x83
	lsls r4, r4, #3
	adds r1, r3, r4
	ldr r2, _08042B2C @ =0x00000414
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r0, _08042B30 @ =0x0000041A
	adds r1, r3, r0
	adds r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
_08042A94:
	strh r0, [r1]
_08042A96:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _08042B34 @ =0x00000516
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #1
	cmp r1, r0
	bne _08042AB2
	ldr r0, _08042B38 @ =gMain
	ldr r2, _08042B3C @ =0x00000D08
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
_08042AB2:
	mov r3, r8
	ldr r1, [r3]
	ldr r4, _08042B40 @ =0x00000506
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08042AC6
	b _08042DA0
_08042AC6:
	ldr r5, _08042B34 @ =0x00000516
	adds r2, r1, r5
	ldrh r0, [r2]
	cmp r0, #0xff
	bhi _08042ADE
	asrs r0, r0, #1
	rsbs r0, r0, #0
	adds r1, #0xe6
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_08042ADE:
	ldr r0, _08042B38 @ =gMain
	movs r1, #0xae
	lsls r1, r1, #4
	adds r6, r0, r1
	ldrh r0, [r6]
	ldr r2, _08042B38 @ =gMain
	ldr r3, _08042B44 @ =0x00000B98
	adds r2, r2, r3
	mov sb, r2
	cmp r0, #0
	beq _08042BC0
	mov r4, r8
	ldr r0, [r4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	ldr r0, [r4]
	ldr r4, _08042B48 @ =0x000003C6
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _08042B4C
	movs r0, #0xb4
	strh r0, [r6, #4]
	b _08042B60
	.align 2, 0
_08042B2C: .4byte 0x00000414
_08042B30: .4byte 0x0000041A
_08042B34: .4byte 0x00000516
_08042B38: .4byte gMain
_08042B3C: .4byte 0x00000D08
_08042B40: .4byte 0x00000506
_08042B44: .4byte 0x00000B98
_08042B48: .4byte 0x000003C6
_08042B4C:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0xff
	bhi _08042B60
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #0x14
	strh r0, [r1]
_08042B60:
	movs r2, #4
	ldrsh r1, [r6, r2]
	movs r0, #0x3c
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08042B70
	ldr r0, _08042C00 @ =0x0000FFC4
	strh r0, [r6, #4]
_08042B70:
	movs r0, #0
	ldr r3, _08042C04 @ =gMain+0xB98 @gMain.spriteGroups[12]
	mov sb, r3
	ldr r7, _08042C08 @ =gOamBuffer
	ldr r4, _08042C0C @ =0xFFFFFE00
	mov ip, r4
_08042B7C:
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
	ldr r2, _08042C10 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	cmp r4, #3
	ble _08042B7C
_08042BC0:
	mov r6, sb
	ldrh r0, [r6]
	cmp r0, #0
	beq _08042C86
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xf2
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	mov r2, r8
	ldr r0, [r2]
	adds r4, #2
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb4
	ble _08042C14
	movs r0, #0xb4
	strh r0, [r6, #4]
	b _08042C2A
	.align 2, 0
_08042C00: .4byte 0x0000FFC4
_08042C04: .4byte gMain+0xB98 @gMain.spriteGroups[12]
_08042C08: .4byte gOamBuffer
_08042C0C: .4byte 0xFFFFFE00
_08042C10: .4byte 0x000001FF
_08042C14:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, _08042CB8 @ =0x00000516
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0xff
	bhi _08042C2A
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #0xa
	strh r0, [r1]
_08042C2A:
	movs r3, #4
	ldrsh r1, [r6, r3]
	movs r0, #0x3c
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08042C3A
	ldr r0, _08042CBC @ =0x0000FFC4
	strh r0, [r6, #4]
_08042C3A:
	movs r0, #0
	ldr r7, _08042CC0 @ =gOamBuffer
	ldr r4, _08042CC4 @ =0xFFFFFE00
	mov ip, r4
_08042C42:
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
	ldr r2, _08042CC8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	cmp r4, #5
	ble _08042C42
_08042C86:
	ldr r6, _08042CCC @ =gMain+0xD08 @gMain.spriteGroups[14]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08042C90
	b _08042DA0
_08042C90:
	mov r3, r8
	ldr r0, [r3]
	ldr r4, _08042CB8 @ =0x00000516
	adds r1, r0, r4
	ldrh r0, [r1]
	subs r0, #0xbe
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _08042CD4
	ldr r0, _08042CD0 @ =gUnknown_086AF784
	ldrh r1, [r1]
	subs r1, #0xbe
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r7, [r1]
	b _08042CDC
	.align 2, 0
_08042CB8: .4byte 0x00000516
_08042CBC: .4byte 0x0000FFC4
_08042CC0: .4byte gOamBuffer
_08042CC4: .4byte 0xFFFFFE00
_08042CC8: .4byte 0x000001FF
_08042CCC: .4byte gMain+0xD08 @gMain.spriteGroups[14]
_08042CD0: .4byte gUnknown_086AF784
_08042CD4:
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	lsrs r7, r0, #1
_08042CDC:
	mov r0, r8
	ldr r4, [r0]
	movs r1, #0x83
	lsls r1, r1, #3
	mov sl, r1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #2]
	ldr r3, _08042DB8 @ =0x0000041A
	mov sb, r3
	add r4, sb
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08042D16
	ldr r0, _08042DBC @ =0x0000FFC4
	strh r0, [r6, #4]
_08042D16:
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0xb4
	ble _08042D22
	movs r0, #0xb4
	strh r0, [r6, #4]
_08042D22:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _08042DC0 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08042DC4 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08042DC8 @ =0xFFFFFE00
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
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	lsls r1, r7, #0x10
	asrs r1, r1, #0xe
	adds r1, #0x7d
	ldr r4, _08042DCC @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldrh r3, [r2, #4]
	ldr r0, _08042DD0 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	mov r0, r8
	ldr r2, [r0]
	ldr r1, _08042DD4 @ =0x00000516
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0xa0
	bls _08042DA0
	mov r3, sl
	adds r1, r2, r3
	adds r4, #0x15
	adds r0, r2, r4
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r4, sb
	adds r1, r2, r4
	ldr r3, _08042DD8 @ =0x00000416
	adds r0, r2, r3
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_08042DA0:
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0xe6
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r1, r0
	blt _08042DDC
	movs r0, #0
	b _08042DDE
	.align 2, 0
_08042DB8: .4byte 0x0000041A
_08042DBC: .4byte 0x0000FFC4
_08042DC0: .4byte gOamBuffer
_08042DC4: .4byte 0x000001FF
_08042DC8: .4byte 0xFFFFFE00
_08042DCC: .4byte 0x000003FF
_08042DD0: .4byte 0xFFFFFC00
_08042DD4: .4byte 0x00000516
_08042DD8: .4byte 0x00000416
_08042DDC:
	movs r0, #1
_08042DDE:
	strb r0, [r2, #0x1a]
	ldr r4, _08042E38 @ =gMain
	ldr r0, _08042E3C @ =0x000002F2
	adds r2, r4, r0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldr r0, _08042E40 @ =0x000002EE
	adds r2, r4, r0
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	ldr r0, _08042E38 @ =gMain
	ldr r3, _08042E44 @ =0x000002F6
	adds r2, r0, r3
	mov r4, r8
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _08042E20
	adds r0, #3
_08042E20:
	asrs r0, r0, #2
	adds r0, #0xe0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042E38: .4byte gMain
_08042E3C: .4byte 0x000002F2
_08042E40: .4byte 0x000002EE
_08042E44: .4byte 0x000002F6

	thumb_func_start sub_42E48
sub_42E48: @ 0x08042E48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08043198 @ =gMain
	ldr r1, [r0, #0x4c]
	movs r0, #0xf
	movs r5, #0
	ands r1, r0
	cmp r5, r1
	bge _08042E72
	adds r4, r1, #0
_08042E5E:
	bl Random
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	blt _08042E5E
_08042E72:
	ldr r1, _08043198 @ =gMain
	ldr r0, [r1, #0x4c]
	str r0, [r1, #0x48]
	ldr r4, _0804319C @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r6, #0
	movs r3, #0
	strh r3, [r0, #0x18]
	strb r6, [r0, #0x17]
	ldr r0, [r4]
	strb r6, [r0, #0x13]
	ldr r0, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r5, #1
	mov r8, r5
	mov r7, r8
	strb r7, [r0]
	ldr r2, [r4]
	adds r5, r2, #0
	adds r5, #0x6c
	movs r1, #0xe1
	lsls r1, r1, #5
	adds r0, r1, #0
	ldrh r7, [r5]
	adds r0, r0, r7
	ldr r7, _080431A0 @ =0x00000296
	adds r1, r2, r7
	strh r0, [r1]
	strh r3, [r5]
	ldr r1, _080431A4 @ =0x00000392
	adds r0, r2, r1
	strh r3, [r0]
	ldr r5, _080431A8 @ =0x00000383
	adds r2, r2, r5
	strb r6, [r2]
	ldr r0, [r4]
	adds r7, #0xf2
	adds r0, r0, r7
	strb r6, [r0]
	ldr r0, [r4]
	ldr r1, _080431AC @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r4]
	strb r2, [r0, #0x1f]
	ldr r2, [r4]
	adds r1, r2, r1
	ldr r0, [r1]
	strh r3, [r0, #0x30]
	ldr r0, [r1]
	strh r3, [r0, #0x32]
	ldr r0, [r1]
	strh r3, [r0, #6]
	adds r5, #3
	adds r2, r2, r5
	strb r6, [r2]
	ldr r1, [r4]
	ldr r7, _080431B0 @ =0x0000053A
	adds r0, r1, r7
	strh r3, [r0]
	ldr r2, _080431B4 @ =0x00000542
	adds r0, r1, r2
	strh r3, [r0]
	ldr r5, _080431B8 @ =0x00000544
	adds r0, r1, r5
	str r3, [r0]
	adds r7, #0x10
	adds r1, r1, r7
	strb r6, [r1]
	ldr r0, [r4]
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	adds r5, #0x4c
	adds r0, r0, r5
	strb r6, [r0]
	ldr r0, [r4]
	adds r7, #0x47
	adds r0, r0, r7
	strb r6, [r0]
	ldr r1, [r4]
	ldr r2, _080431BC @ =0x00000592
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #4
	adds r0, r1, r5
	strh r3, [r0]
	adds r7, #5
	adds r0, r1, r7
	strh r3, [r0]
	adds r1, #0x7e
	mov r0, r8
	strh r0, [r1]
	movs r5, #0
	movs r6, #0xe8
	lsls r6, r6, #2
_08042F3C:
	ldr r0, [r4]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r6
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	ldr r2, _080431C0 @ =0x000003A3
	adds r0, r0, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	lsls r2, r1, #1
	movs r5, #0xec
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r0, r0, r2
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _08042F3C
	movs r5, #0
	ldr r4, _0804319C @ =gCurrentPinballGame
	movs r3, #0
_08042F72:
	ldr r0, [r4]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	movs r7, #0xa6
	lsls r7, r7, #3
	adds r0, r0, r7
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	ldr r2, _080431C4 @ =0x00000533
	adds r0, r0, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	ldr r5, _080431C8 @ =0x00000536
	adds r0, r0, r5
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r4]
	lsls r2, r1, #1
	adds r7, #0xc
	adds r0, r0, r7
	adds r0, r0, r2
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	ble _08042F72
	movs r5, #0
	ldr r6, _0804319C @ =gCurrentPinballGame
	movs r4, #0
_08042FB4:
	ldr r0, [r6]
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	ldr r1, _080431CC @ =0x0000052C
	adds r0, r0, r1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	ldr r2, _080431D0 @ =0x0000052E
	adds r0, r0, r2
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	ldr r7, _080431D4 @ =0x0000054B
	adds r0, r0, r7
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #0x21
	adds r0, r0, r1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r2, #0x21
	adds r0, r0, r2
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r5, #9
	adds r0, r0, r5
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r7, #8
	adds r0, r0, r7
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r2, #8
	adds r0, r0, r2
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r5, #8
	adds r0, r0, r5
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r7, #8
	adds r0, r0, r7
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r6]
	adds r2, #8
	adds r0, r0, r2
	adds r0, r0, r3
	strb r4, [r0]
	ldr r2, [r6]
	lsls r1, r3, #1
	adds r5, #9
	adds r0, r2, r5
	adds r0, r0, r1
	strh r4, [r0]
	adds r7, #0xb
	adds r0, r2, r7
	adds r0, r0, r1
	strh r4, [r0]
	adds r5, #8
	adds r0, r2, r5
	adds r0, r0, r1
	strh r4, [r0]
	lsls r0, r3, #2
	adds r0, r2, r0
	adds r7, #0xa
	adds r1, r0, r7
	strh r4, [r1]
	adds r5, #8
	adds r1, r0, r5
	strh r4, [r1]
	adds r7, #8
	adds r1, r0, r7
	strh r4, [r1]
	ldr r1, _080431D8 @ =0x0000057A
	adds r0, r0, r1
	strh r4, [r0]
	lsls r1, r3, #3
	adds r5, #0xe
	adds r0, r2, r5
	adds r0, r0, r1
	str r4, [r0]
	adds r7, #0xc
	adds r2, r2, r7
	adds r2, r2, r1
	str r4, [r2]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #1
	ble _08042FB4
	ldr r0, _0804319C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #0x1a]
	bl sub_4387C
	bl sub_43500
	bl sub_44D58
	bl sub_45E08
	movs r5, #0
	ldr r6, _080431DC @ =gUnknown_03005C00
	movs r4, #0x80
	lsls r4, r4, #3
	movs r3, #0x80
	lsls r3, r3, #2
	ldr r2, _080431E0 @ =0x000007FF
_080430C2:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r2
	ble _080430C2
	ldr r1, _080431E4 @ =0x040000D4
	ldr r2, _080431E8 @ =gUnknown_03006400
	str r2, [r1]
	ldr r0, _080431EC @ =0x06001000
	str r0, [r1, #4]
	ldr r0, _080431F0 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08043198 @ =gMain
	ldrh r0, [r1, #0x38]
	ldr r0, _080431F4 @ =0x00001C42
	strh r0, [r1, #0x38]
	ldrh r0, [r1, #0x3a]
	ldr r0, _080431F8 @ =0x00000C04
	strh r0, [r1, #0x3a]
	movs r5, #0
	adds r6, r1, #0
	ldr r0, _0804319C @ =gCurrentPinballGame
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r7, r2, r1
	ldr r0, _080431FC @ =gUnknown_08137E14
	mov ip, r0
	ldr r1, _08043200 @ =0xFFFFF800
	adds r2, r2, r1
	ldr r4, _08043204 @ =0x0000013F
_08043110:
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0
	cmp r3, #0
	bge _0804311C
	adds r0, #0x1f
_0804311C:
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _0804313C
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r3, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0x90
	lsls r1, r1, #8
	strh r1, [r0]
_0804313C:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	ble _08043110
	ldr r0, _08043208 @ =0x000002EE
	adds r1, r6, r0
	movs r0, #0x7e
	strh r0, [r1]
	ldr r4, _080431E4 @ =0x040000D4
	str r7, [r4]
	ldr r0, _0804320C @ =0x06001140
	str r0, [r4, #4]
	ldr r0, _08043210 @ =0x80000140
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08043214 @ =0x000005F6
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	add r0, ip
	str r0, [r4]
	ldr r0, _08043218 @ =0x05000220
	str r0, [r4, #4]
	ldr r5, _0804321C @ =0x80000010
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, MUS_BONUS_FIELD_SPHEAL
	bl m4aSongNumStart
	ldr r0, _08043220 @ =gUnknown_081B36A4
	str r0, [r4]
	ldr r0, _08043224 @ =0x05000320
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043198: .4byte gMain
_0804319C: .4byte gCurrentPinballGame
_080431A0: .4byte 0x00000296
_080431A4: .4byte 0x00000392
_080431A8: .4byte 0x00000383
_080431AC: .4byte 0x0000132C
_080431B0: .4byte 0x0000053A
_080431B4: .4byte 0x00000542
_080431B8: .4byte 0x00000544
_080431BC: .4byte 0x00000592
_080431C0: .4byte 0x000003A3
_080431C4: .4byte 0x00000533
_080431C8: .4byte 0x00000536
_080431CC: .4byte 0x0000052C
_080431D0: .4byte 0x0000052E
_080431D4: .4byte 0x0000054B
_080431D8: .4byte 0x0000057A
_080431DC: .4byte gUnknown_03005C00
_080431E0: .4byte 0x000007FF
_080431E4: .4byte 0x040000D4
_080431E8: .4byte gUnknown_03006400
_080431EC: .4byte 0x06001000
_080431F0: .4byte 0x80000800
_080431F4: .4byte 0x00001C42
_080431F8: .4byte 0x00000C04
_080431FC: .4byte gUnknown_08137E14
_08043200: .4byte 0xFFFFF800
_08043204: .4byte 0x0000013F
_08043208: .4byte 0x000002EE
_0804320C: .4byte 0x06001140
_08043210: .4byte 0x80000140
_08043214: .4byte 0x000005F6
_08043218: .4byte 0x05000220
_0804321C: .4byte 0x80000010
_08043220: .4byte gUnknown_081B36A4
_08043224: .4byte 0x05000320

	thumb_func_start sub_43228
sub_43228: @ 0x08043228
	push {r4, r5, lr}
	ldr r1, _08043248 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #5
	bls _0804323C
	b _080434BA
_0804323C:
	lsls r0, r0, #2
	ldr r1, _0804324C @ =_08043250
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08043248: .4byte gCurrentPinballGame
_0804324C: .4byte _08043250
_08043250: @ jump table
	.4byte _08043268 @ case 0
	.4byte _080432CE @ case 1
	.4byte _08043342 @ case 2
	.4byte _080433D4 @ case 3
	.4byte _08043470 @ case 4
	.4byte _080434A2 @ case 5
_08043268:
	ldr r0, [r5]
	ldr r1, _080432B0 @ =0x000005F7
	adds r0, r0, r1
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r4, [r5]
	ldrh r1, [r4, #0x18]
	ldr r0, _080432B4 @ =0x00000153
	cmp r1, r0
	bhi _080432C0
	subs r0, #0x13
	cmp r1, r0
	bhi _08043296
	adds r0, r1, #0
	movs r1, #5
	bl __udivsi3
	ldr r2, _080432B8 @ =0x0000FFC0
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xe6
	strh r0, [r1]
_08043296:
	ldr r2, [r5]
	ldrh r1, [r2, #0x18]
	ldr r0, _080432BC @ =0x00000145
	cmp r1, r0
	bne _080432AA
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r0, #2
	strb r0, [r1]
_080432AA:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	b _0804331C
	.align 2, 0
_080432B0: .4byte 0x000005F7
_080432B4: .4byte 0x00000153
_080432B8: .4byte 0x0000FFC0
_080432BC: .4byte 0x00000145
_080432C0:
	adds r0, r4, #0
	adds r0, #0xe6
	strh r3, [r0]
	strb r2, [r4, #0x13]
	ldr r0, [r5]
	strh r3, [r0, #0x18]
	b _080434BA
_080432CE:
	ldr r1, [r5]
	ldr r4, _08043324 @ =0x00000296
	adds r0, r1, r4
	ldrh r4, [r0]
	cmp r4, #0
	beq _080432DC
	b _080434BA
_080432DC:
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	bne _08043314
	bl m4aMPlayAllStop
	ldr r0, _08043328 @ =gMPlayInfo_SE1
	ldr r1, _0804332C @ =gUnknown_086A2E90
	bl MPlayStart
	ldr r1, _08043330 @ =gMain
	movs r0, #0x80
	strb r0, [r1, #0xf]
	ldr r0, [r5]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r5]
	ldr r2, _08043334 @ =0x00000392
	adds r0, r0, r2
	strh r4, [r0]
_08043314:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x3b
	bhi _08043338
_0804331C:
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080434BA
	.align 2, 0
_08043324: .4byte 0x00000296
_08043328: .4byte gMPlayInfo_SE1
_0804332C: .4byte gUnknown_086A2E90
_08043330: .4byte gMain
_08043334: .4byte 0x00000392
_08043338:
	movs r0, #2
	strb r0, [r1, #0x13]
	ldr r0, [r5]
	strh r4, [r0, #0x18]
	b _080434BA
_08043342:
	ldr r0, [r5]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	bne _08043354
	bl m4aMPlayAllStop
	movs r0, MUS_SUCCESS3
	bl m4aSongNumStart
_08043354:
	ldr r2, [r5]
	ldrh r0, [r2, #0x18]
	cmp r0, #0x13
	bhi _08043362
	adds r0, #1
	strh r0, [r2, #0x18]
	b _080434BA
_08043362:
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0x13]
	ldr r0, [r5]
	strh r1, [r0, #0x18]
	ldr r2, _080433B0 @ =gMain
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r2, r3
	movs r3, #1
	movs r1, #1
	strh r1, [r0]
	ldr r4, _080433B4 @ =0x000008B8
	adds r0, r2, r4
	strh r1, [r0]
	adds r4, #0xb8
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, _080433B8 @ =0x00000A28
	adds r2, r2, r0
	strh r1, [r2]
	ldr r1, _080433BC @ =0x040000D4
	ldr r0, _080433C0 @ =gUnknown_084B77EC
	str r0, [r1]
	ldr r0, _080433C4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080433C8 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r5]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r1, _080433CC @ =0x0000FF82
	strh r1, [r2]
	ldr r2, _080433D0 @ =0x000005FA
	adds r0, r0, r2
	strb r3, [r0]
	b _080434BA
	.align 2, 0
_080433B0: .4byte gMain
_080433B4: .4byte 0x000008B8
_080433B8: .4byte 0x00000A28
_080433BC: .4byte 0x040000D4
_080433C0: .4byte gUnknown_084B77EC
_080433C4: .4byte 0x06015800
_080433C8: .4byte 0x80000400
_080433CC: .4byte 0x0000FF82
_080433D0: .4byte 0x000005FA
_080433D4:
	bl sub_45E90
	ldr r1, _08043444 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	beq _080433E6
	movs r0, #0xb5
	strh r0, [r2, #0x18]
_080433E6:
	ldr r2, [r1]
	ldrh r0, [r2, #0x18]
	cmp r0, #0xb4
	bne _08043408
	ldr r3, _08043448 @ =0x00000544
	adds r0, r2, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08043408
	movs r0, #1
	strb r0, [r2, #0x1c]
	ldr r1, [r1]
	ldr r0, _0804344C @ =0x00061A80
	str r0, [r1, #0x38]
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r1, #0x3c]
_08043408:
	ldr r0, _08043444 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldrh r1, [r2, #0x18]
	adds r5, r0, #0
	cmp r1, #0xbd
	bls _08043426
	ldr r0, _08043450 @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08043426
	movs r0, #0x87
	lsls r0, r0, #2
	strh r0, [r2, #0x18]
_08043426:
	ldr r1, [r5]
	ldrh r2, [r1, #0x18]
	ldr r0, _08043454 @ =0x0000021B
	cmp r2, r0
	bhi _08043458
	cmp r2, #4
	bne _0804343A
	movs r0, SE_UNKNOWN_0xA4
	bl m4aSongNumStart
_0804343A:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _08043460
	.align 2, 0
_08043444: .4byte gCurrentPinballGame
_08043448: .4byte 0x00000544
_0804344C: .4byte 0x00061A80
_08043450: .4byte gMain
_08043454: .4byte 0x0000021B
_08043458:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #4
	strb r0, [r1, #0x13]
_08043460:
	ldr r0, [r5]
	ldr r4, _0804346C @ =0x000005FA
	adds r0, r0, r4
	movs r1, #1
	b _080434B8
	.align 2, 0
_0804346C: .4byte 0x000005FA
_08043470:
	bl sub_45E90
	ldr r0, _08043494 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x1d
	bhi _08043498
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne _080434BA
	movs r0, SE_UNKNOWN_0xA4
	bl m4aSongNumStart
	b _080434BA
	.align 2, 0
_08043494: .4byte gCurrentPinballGame
_08043498:
	movs r0, #0
	strh r0, [r1, #0x18]
	movs r0, #5
	strb r0, [r1, #0x13]
	b _080434BA
_080434A2:
	bl sub_45E90
	ldr r2, _080434F4 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _080434F8 @ =0x00000386
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _080434FC @ =0x000005FA
	adds r0, r0, r2
_080434B8:
	strb r1, [r0]
_080434BA:
	bl sub_4387C
	bl sub_43500
	bl sub_44D58
	bl sub_45E08
	ldr r0, _080434F4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _080434F8 @ =0x00000386
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080434E8
	ldr r4, _080434FC @ =0x000005FA
	adds r1, r1, r4
	movs r0, #1
	strb r0, [r1]
	bl sub_350F0
_080434E8:
	bl sub_472E4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080434F4: .4byte gCurrentPinballGame
_080434F8: .4byte 0x00000386
_080434FC: .4byte 0x000005FA

	thumb_func_start sub_43500
sub_43500: @ 0x08043500
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08043594 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08043524
	ldr r0, _08043598 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _08043524
	bl sub_455D0
_08043524:
	ldr r2, _08043594 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _08043534
	b _080436E8
_08043534:
	ldr r0, _08043598 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	beq _0804353E
	b _080436E8
_0804353E:
	movs r1, #0
	adds r7, r2, #0
	movs r0, #0xa9
	lsls r0, r0, #3
	mov r8, r0
	ldr r2, _0804359C @ =gUnknown_086AFAE2
	mov sl, r2
_0804354C:
	ldr r0, [r7]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	add r0, r8
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #0x17
	bne _08043576
	ldr r0, _080435A0 @ =gMPlayInfo_SE1
	ldr r1, _080435A4 @ =gUnknown_086A2EAC
	bl MPlayStart
	ldr r1, [r7]
	ldr r0, _080435A8 @ =0x00001388
	str r0, [r1, #0x3c]
	movs r0, #8
	bl sub_11B0
_08043576:
	ldr r3, [r7]
	movs r6, #0xe8
	lsls r6, r6, #2
	adds r0, r3, r6
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	cmp r2, #1
	beq _080435D4
	cmp r2, #1
	bgt _080435AC
	cmp r2, #0
	beq _080435B6
	b _080436D8
	.align 2, 0
_08043594: .4byte gCurrentPinballGame
_08043598: .4byte gMain
_0804359C: .4byte gUnknown_086AFAE2
_080435A0: .4byte gMPlayInfo_SE1
_080435A4: .4byte gUnknown_086A2EAC
_080435A8: .4byte 0x00001388
_080435AC:
	cmp r2, #2
	beq _08043628
	cmp r2, #3
	beq _0804366C
	b _080436D8
_080435B6:
	lsls r1, r4, #1
	movs r5, #0xec
	lsls r5, r5, #2
	adds r0, r3, r5
	adds r0, r0, r1
	strh r2, [r0]
	ldr r1, _080435D0 @ =0x000003A3
	adds r0, r3, r1
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	b _080436CE
	.align 2, 0
_080435D0: .4byte 0x000003A3
_080435D4:
	mov r2, r8
	adds r0, r3, r2
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0804367C
	ldr r5, _08043624 @ =0x000003A3
	adds r0, r3, r5
	adds r5, r0, r4
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #2
	add r1, sl
	lsls r2, r4, #1
	movs r6, #0xec
	lsls r6, r6, #2
	adds r0, r3, r6
	adds r2, r0, r2
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bhi _080436A6
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, [r7]
	ldr r1, _08043624 @ =0x000003A3
	adds r0, r0, r1
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #6
	bne _080436D8
	movs r0, #4
	strb r0, [r1]
	b _080436D8
	.align 2, 0
_08043624: .4byte 0x000003A3
_08043628:
	mov r2, r8
	adds r0, r3, r2
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _0804367C
	lsls r1, r4, #1
	movs r5, #0xec
	lsls r5, r5, #2
	adds r0, r3, r5
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _0804365C
	subs r0, #1
	strh r0, [r1]
	ldr r6, _08043658 @ =0x000003A3
	adds r0, r3, r6
	adds r0, r0, r4
	movs r1, #8
	b _080436D6
	.align 2, 0
_08043658: .4byte 0x000003A3
_0804365C:
	ldr r1, _08043668 @ =0x000003A3
	adds r0, r3, r1
	adds r0, r0, r4
	movs r1, #7
	b _080436D6
	.align 2, 0
_08043668: .4byte 0x000003A3
_0804366C:
	mov r2, r8
	adds r0, r3, r2
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08043682
_0804367C:
	subs r0, r2, #1
	strb r0, [r1]
	b _080436D8
_08043682:
	ldr r5, _080436AC @ =0x000003A3
	adds r0, r3, r5
	adds r5, r0, r4
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #2
	add r1, sl
	lsls r0, r4, #1
	mov ip, r0
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r3, r2
	mov r3, ip
	adds r2, r0, r3
	ldrh r3, [r2]
	ldrh r0, [r1]
	cmp r0, r3
	bls _080436B0
_080436A6:
	adds r0, r3, #1
	strh r0, [r2]
	b _080436D8
	.align 2, 0
_080436AC: .4byte 0x000003A3
_080436B0:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, [r7]
	ldr r5, _08043720 @ =0x000003A3
	adds r0, r0, r5
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xe
	ble _080436D8
	movs r0, #4
	strb r0, [r1]
_080436CE:
	ldr r0, [r7]
	adds r0, r0, r6
	adds r0, r0, r4
	movs r1, #1
_080436D6:
	strb r1, [r0]
_080436D8:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _080436E8
	b _0804354C
_080436E8:
	ldr r6, _08043724 @ =gMain+0x12C8 @gMain.spriteGroups[22]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08043788
	ldr r2, _08043728 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x64
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x5e
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, [r2]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0804372C
	movs r0, #0
	b _0804373E
	.align 2, 0
_08043720: .4byte 0x000003A3
_08043724: .4byte gMain+0x12C8 @gMain.spriteGroups[22]
_08043728: .4byte gCurrentPinballGame
_0804372C:
	ldr r1, _080437C0 @ =gUnknown_086AFAE0
	ldr r3, _080437C4 @ =0x000003A3
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
_0804373E:
	ldr r2, _080437C8 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #5
	ldr r1, _080437CC @ =gUnknown_084B47EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080437D0 @ =0x060114A0
	str r0, [r2, #4]
	ldr r0, _080437D4 @ =0x80000300
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _080437D8 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _080437DC @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080437E0 @ =0xFFFFFE00
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
_08043788:
	ldr r6, _080437E4 @ =gMain+0x1210 @gMain.spriteGroups[21]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0804384E
	ldr r2, _080437E8 @ =gCurrentPinballGame
	ldr r0, [r2]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x8c
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r2]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x5e
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, [r2]
	ldr r5, _080437EC @ =0x00000549
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _080437F0
	movs r0, #0
	b _08043804
	.align 2, 0
_080437C0: .4byte gUnknown_086AFAE0
_080437C4: .4byte 0x000003A3
_080437C8: .4byte 0x040000D4
_080437CC: .4byte gUnknown_084B47EC
_080437D0: .4byte 0x060114A0
_080437D4: .4byte 0x80000300
_080437D8: .4byte gOamBuffer
_080437DC: .4byte 0x000001FF
_080437E0: .4byte 0xFFFFFE00
_080437E4: .4byte gMain+0x1210 @gMain.spriteGroups[21]
_080437E8: .4byte gCurrentPinballGame
_080437EC: .4byte 0x00000549
_080437F0:
	ldr r1, _0804385C @ =gUnknown_086AFAE0
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
_08043804:
	ldr r2, _08043860 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #5
	ldr r1, _08043864 @ =gUnknown_084B47EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08043868 @ =0x06010CA0
	str r0, [r2, #4]
	ldr r0, _0804386C @ =0x80000300
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _08043870 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08043874 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08043878 @ =0xFFFFFE00
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
_0804384E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804385C: .4byte gUnknown_086AFAE0
_08043860: .4byte 0x040000D4
_08043864: .4byte gUnknown_084B47EC
_08043868: .4byte 0x06010CA0
_0804386C: .4byte 0x80000300
_08043870: .4byte gOamBuffer
_08043874: .4byte 0x000001FF
_08043878: .4byte 0xFFFFFE00

	thumb_func_start sub_4387C
sub_4387C: @ 0x0804387C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _080438D4 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0804389A
	bl _080448FC
_0804389A:
	ldr r0, _080438D8 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	beq _080438A6
	bl _080448FC
_080438A6:
	movs r0, #0
	str r0, [sp]
_080438AA:
	ldr r3, _080438D4 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r1, [sp]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	ldr r4, _080438DC @ =0x00000553
	adds r0, r0, r4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #0xe
	bls _080438CA
	bl _080448E4
_080438CA:
	lsls r0, r0, #2
	ldr r1, _080438E0 @ =_080438E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080438D4: .4byte gCurrentPinballGame
_080438D8: .4byte gMain
_080438DC: .4byte 0x00000553
_080438E0: .4byte _080438E4
_080438E4: @ jump table
	.4byte _08043920 @ case 0
	.4byte _08043980 @ case 1
	.4byte _08043BF8 @ case 2
	.4byte _08043CB0 @ case 3
	.4byte _08043DC0 @ case 4
	.4byte _08043EB8 @ case 5
	.4byte _08043F04 @ case 6
	.4byte _08043FB0 @ case 7
	.4byte _0804409C @ case 8
	.4byte _080442A6 @ case 9
	.4byte _08044344 @ case 10
	.4byte _08044450 @ case 11
	.4byte _080445BC @ case 12
	.4byte _08044624 @ case 13
	.4byte _080446AC @ case 14
_08043920:
	ldr r5, _08043968 @ =gCurrentPinballGame
	ldr r1, [r5]
	mov r6, sb
	asrs r3, r6, #0x10
	ldr r7, _0804396C @ =0x00000553
	adds r1, r1, r7
	adds r1, r1, r3
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08043970 @ =0x0000055B
	adds r0, r0, r1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r5]
	lsls r2, r3, #1
	ldr r5, _08043974 @ =0x00000562
	adds r0, r1, r5
	adds r0, r0, r2
	movs r2, #0
	strh r4, [r0]
	ldr r6, _08043978 @ =0x0000054F
	adds r1, r1, r6
	adds r1, r1, r3
	strb r2, [r1]
	ldr r7, _08043968 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _0804397C @ =0x00000557
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0xff
	strb r1, [r0]
	bl _080448E4
	.align 2, 0
_08043968: .4byte gCurrentPinballGame
_0804396C: .4byte 0x00000553
_08043970: .4byte 0x0000055B
_08043974: .4byte 0x00000562
_08043978: .4byte 0x0000054F
_0804397C: .4byte 0x00000557
_08043980:
	ldr r2, _080439A4 @ =gCurrentPinballGame
	ldr r0, [r2]
	mov r3, sb
	asrs r5, r3, #0x10
	lsls r1, r5, #1
	ldr r4, _080439A8 @ =0x00000562
	adds r0, r0, r4
	adds r2, r0, r1
	ldrh r1, [r2]
	lsls r0, r5, #4
	subs r0, r0, r5
	lsls r0, r0, #1
	adds r0, #0x78
	cmp r1, r0
	bge _080439AC
	adds r0, r1, #1
	strh r0, [r2]
	b _08043BCA
	.align 2, 0
_080439A4: .4byte gCurrentPinballGame
_080439A8: .4byte 0x00000562
_080439AC:
	bl Random
	adds r1, r0, #0
	ldr r6, _08043A34 @ =gMain
	ldr r0, [r6, #0x4c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r7, _08043A38 @ =gCurrentPinballGame
	ldr r4, [r7]
	ldr r7, _08043A3C @ =0x00000557
	adds r4, r4, r7
	adds r4, r4, r5
	movs r1, #6
	bl __umodsi3
	strb r0, [r4]
	ldr r1, _08043A38 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r4, r0, r7
	movs r2, #0xab
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _080439F8
	adds r4, r4, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #2
	movs r1, #6
	bl __modsi3
	strb r0, [r4]
_080439F8:
	ldr r4, _08043A38 @ =gCurrentPinballGame
	ldr r3, [r4]
	adds r0, r3, r7
	adds r0, r0, r5
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #1
	bgt _08043AA0
	cmp r4, #0
	bne _08043A48
	lsls r2, r5, #3
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r0, r3, r6
	adds r0, r0, r2
	movs r1, #0x92
	lsls r1, r1, #7
	str r1, [r0]
	ldr r7, _08043A40 @ =0x00000584
	adds r0, r3, r7
	adds r0, r0, r2
	movs r1, #0xab
	lsls r1, r1, #8
	str r1, [r0]
	ldr r1, _08043A44 @ =0x00000551
	adds r0, r3, r1
	adds r0, r0, r5
	strb r4, [r0]
	b _08043A6E
	.align 2, 0
_08043A34: .4byte gMain
_08043A38: .4byte gCurrentPinballGame
_08043A3C: .4byte 0x00000557
_08043A40: .4byte 0x00000584
_08043A44: .4byte 0x00000551
_08043A48:
	lsls r2, r5, #3
	movs r4, #0xb0
	lsls r4, r4, #3
	adds r0, r3, r4
	adds r0, r0, r2
	movs r1, #0xa7
	lsls r1, r1, #8
	str r1, [r0]
	ldr r6, _08043A8C @ =0x00000584
	adds r0, r3, r6
	adds r0, r0, r2
	movs r1, #0xac
	lsls r1, r1, #8
	str r1, [r0]
	ldr r7, _08043A90 @ =0x00000551
	adds r0, r3, r7
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
_08043A6E:
	ldr r2, _08043A94 @ =gCurrentPinballGame
	ldr r1, [r2]
	mov r0, sb
	asrs r3, r0, #0x10
	ldr r4, _08043A98 @ =0x0000055B
	adds r1, r1, r4
	adds r1, r1, r3
	movs r0, #9
	strb r0, [r1]
	ldr r0, [r2]
	ldr r5, _08043A9C @ =0x00000553
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #7
	b _08043BB6
	.align 2, 0
_08043A8C: .4byte 0x00000584
_08043A90: .4byte 0x00000551
_08043A94: .4byte gCurrentPinballGame
_08043A98: .4byte 0x0000055B
_08043A9C: .4byte 0x00000553
_08043AA0:
	bl Random
	ldr r1, _08043AF8 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldr r3, _08043AFC @ =0x00000551
	adds r2, r2, r3
	adds r2, r2, r5
	ldr r1, [r6, #0x4c]
	adds r1, r1, r0
	movs r0, #1
	ands r1, r0
	strb r1, [r2]
	ldr r2, _08043AF8 @ =gCurrentPinballGame
	ldr r1, [r2]
	adds r3, r1, r3
	adds r3, r3, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _08043B24
	adds r0, r1, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _08043B00
	bl Random
	ldr r3, _08043AF8 @ =gCurrentPinballGame
	ldr r4, [r3]
	lsls r1, r5, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r4, r4, r5
	adds r4, r4, r1
	movs r1, #0x65
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	adds r0, #0x50
	b _08043B74
	.align 2, 0
_08043AF8: .4byte gCurrentPinballGame
_08043AFC: .4byte 0x00000551
_08043B00:
	bl Random
	ldr r6, _08043B20 @ =gCurrentPinballGame
	ldr r4, [r6]
	lsls r1, r5, #3
	movs r7, #0xb0
	lsls r7, r7, #3
	adds r4, r4, r7
	adds r4, r4, r1
	movs r1, #0x65
	bl __umodsi3
	lsrs r0, r0, #1
	adds r0, #0x32
	b _08043B74
	.align 2, 0
_08043B20: .4byte gCurrentPinballGame
_08043B24:
	adds r0, r1, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _08043B58
	bl Random
	ldr r1, _08043B54 @ =gCurrentPinballGame
	ldr r4, [r1]
	lsls r1, r5, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r4, r4, r2
	adds r4, r4, r1
	movs r1, #0x65
	bl __umodsi3
	movs r1, #5
	bl __udivsi3
	b _08043B72
	.align 2, 0
_08043B54: .4byte gCurrentPinballGame
_08043B58:
	bl Random
	ldr r3, _08043BE0 @ =gCurrentPinballGame
	ldr r4, [r3]
	lsls r1, r5, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r4, r4, r5
	adds r4, r4, r1
	movs r1, #0x65
	bl __umodsi3
	lsrs r0, r0, #1
_08043B72:
	adds r0, #0x8c
_08043B74:
	lsls r0, r0, #8
	str r0, [r4]
	ldr r5, _08043BE0 @ =gCurrentPinballGame
	ldr r2, [r5]
	mov r6, sb
	asrs r4, r6, #0x10
	lsls r0, r4, #3
	ldr r7, _08043BE4 @ =0x00000584
	adds r3, r2, r7
	adds r3, r3, r0
	ldr r1, _08043BE8 @ =0x00000557
	adds r0, r2, r1
	adds r0, r0, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r1, #2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #9
	movs r6, #0xaf
	lsls r6, r6, #8
	adds r0, r0, r6
	str r0, [r3]
	subs r7, #0x29
	adds r2, r2, r7
	adds r2, r2, r4
	movs r0, #0
	strb r0, [r2]
	ldr r0, [r5]
	ldr r1, _08043BEC @ =0x00000553
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #2
_08043BB6:
	strb r1, [r0]
	ldr r2, _08043BE0 @ =gCurrentPinballGame
	ldr r0, [r2]
	mov r3, sb
	asrs r1, r3, #0xf
	ldr r4, _08043BF0 @ =0x00000562
	adds r0, r0, r4
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
_08043BCA:
	ldr r5, _08043BE0 @ =gCurrentPinballGame
	ldr r0, [r5]
	mov r6, sb
	asrs r1, r6, #0x10
	ldr r7, _08043BF4 @ =0x0000054F
	adds r0, r0, r7
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bl _080448E4
	.align 2, 0
_08043BE0: .4byte gCurrentPinballGame
_08043BE4: .4byte 0x00000584
_08043BE8: .4byte 0x00000557
_08043BEC: .4byte 0x00000553
_08043BF0: .4byte 0x00000562
_08043BF4: .4byte 0x0000054F
_08043BF8:
	ldr r3, _08043C2C @ =gUnknown_086AFB2C
	ldr r7, _08043C30 @ =gCurrentPinballGame
	ldr r2, [r7]
	mov r0, sb
	asrs r5, r0, #0x10
	ldr r6, _08043C34 @ =0x0000055B
	adds r0, r2, r6
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, #2
	adds r0, r0, r3
	lsls r1, r5, #1
	ldr r3, _08043C38 @ =0x00000562
	adds r2, r2, r3
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08043C3C
	adds r0, r1, #1
	strh r0, [r2]
	b _08043C7A
	.align 2, 0
_08043C2C: .4byte gUnknown_086AFB2C
_08043C30: .4byte gCurrentPinballGame
_08043C34: .4byte 0x0000055B
_08043C38: .4byte 0x00000562
_08043C3C:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r0, [r7]
	ldr r4, _08043C9C @ =0x0000055B
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #3
	bne _08043C62
	strb r1, [r0]
	ldr r0, [r7]
	ldr r2, _08043CA0 @ =0x00000553
	adds r0, r0, r2
	adds r0, r0, r5
	strb r1, [r0]
_08043C62:
	ldr r0, [r7]
	adds r0, r0, r6
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08043C7A
	movs r0, #0x9a
	lsls r0, r0, #1
	bl m4aSongNumStart
_08043C7A:
	ldr r0, _08043CA4 @ =gCurrentPinballGame
	ldr r2, [r0]
	mov r4, sb
	asrs r3, r4, #0x10
	lsls r1, r3, #1
	ldr r5, _08043CA8 @ =0x0000056A
	adds r0, r2, r5
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r6, _08043CAC @ =0x0000054F
	adds r2, r2, r6
	adds r2, r2, r3
	movs r0, #1
	strb r0, [r2]
	bl _080448E4
	.align 2, 0
_08043C9C: .4byte 0x0000055B
_08043CA0: .4byte 0x00000553
_08043CA4: .4byte gCurrentPinballGame
_08043CA8: .4byte 0x0000056A
_08043CAC: .4byte 0x0000054F
_08043CB0:
	ldr r3, _08043CE4 @ =gUnknown_086AFB2C
	ldr r7, _08043CE8 @ =gCurrentPinballGame
	ldr r2, [r7]
	mov r0, sb
	asrs r5, r0, #0x10
	ldr r1, _08043CEC @ =0x0000055B
	adds r0, r2, r1
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, #2
	adds r0, r0, r3
	lsls r1, r5, #1
	ldr r3, _08043CF0 @ =0x00000562
	adds r2, r2, r3
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08043CF4
	adds r0, r1, #1
	strh r0, [r2]
	b _08043D14
	.align 2, 0
_08043CE4: .4byte gUnknown_086AFB2C
_08043CE8: .4byte gCurrentPinballGame
_08043CEC: .4byte 0x0000055B
_08043CF0: .4byte 0x00000562
_08043CF4:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r4, _08043D58 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r6, _08043D5C @ =0x0000055B
	adds r0, r0, r6
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bne _08043D14
	movs r0, #3
	strb r0, [r1]
_08043D14:
	ldr r7, _08043D58 @ =gCurrentPinballGame
	ldr r3, [r7]
	mov r0, sb
	asrs r4, r0, #0x10
	lsls r7, r4, #1
	ldr r1, _08043D60 @ =0x0000056A
	adds r0, r3, r1
	adds r2, r0, r7
	ldrh r5, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r0, _08043D64 @ =0x0000018F
	cmp r1, r0
	bgt _08043D7E
	adds r0, r5, #1
	strh r0, [r2]
	ldr r7, _08043D68 @ =0x00000551
	adds r0, r3, r7
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08043D6C
	lsls r0, r4, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r1, r3, r2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0x23
	str r0, [r1]
	b _08043D9E
	.align 2, 0
_08043D58: .4byte gCurrentPinballGame
_08043D5C: .4byte 0x0000055B
_08043D60: .4byte 0x0000056A
_08043D64: .4byte 0x0000018F
_08043D68: .4byte 0x00000551
_08043D6C:
	lsls r0, r4, #3
	movs r4, #0xb0
	lsls r4, r4, #3
	adds r1, r3, r4
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #0x23
	str r0, [r1]
	b _08043D9E
_08043D7E:
	ldr r5, _08043DB0 @ =0x0000055B
	adds r0, r3, r5
	adds r0, r0, r4
	movs r3, #0
	movs r2, #6
	strb r2, [r0]
	ldr r6, _08043DB4 @ =gCurrentPinballGame
	ldr r1, [r6]
	adds r5, #7
	adds r0, r1, r5
	adds r0, r0, r7
	strh r3, [r0]
	ldr r6, _08043DB8 @ =0x00000553
	adds r1, r1, r6
	adds r1, r1, r4
	strb r2, [r1]
_08043D9E:
	ldr r7, _08043DB4 @ =gCurrentPinballGame
	ldr r0, [r7]
	mov r2, sb
	asrs r1, r2, #0x10
	ldr r3, _08043DBC @ =0x0000054F
	adds r0, r0, r3
	adds r0, r0, r1
	bl _080446E8
	.align 2, 0
_08043DB0: .4byte 0x0000055B
_08043DB4: .4byte gCurrentPinballGame
_08043DB8: .4byte 0x00000553
_08043DBC: .4byte 0x0000054F
_08043DC0:
	ldr r0, _08043E00 @ =gMPlayInfo_SE1
	ldr r1, _08043E04 @ =gUnknown_086A2D28
	bl MPlayStart
	ldr r2, _08043E08 @ =gCurrentPinballGame
	ldr r5, [r2]
	mov r4, sb
	asrs r6, r4, #0x10
	ldr r7, _08043E0C @ =0x0000054F
	adds r0, r5, r7
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08043E1C
	lsls r1, r6, #1
	ldr r3, _08043E10 @ =0x00000562
	adds r0, r5, r3
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r4, _08043E14 @ =0x0000055B
	adds r0, r5, r4
	adds r0, r0, r6
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _08043E18 @ =0x00000553
	adds r0, r0, r5
	adds r0, r0, r6
	b _08043E80
	.align 2, 0
_08043E00: .4byte gMPlayInfo_SE1
_08043E04: .4byte gUnknown_086A2D28
_08043E08: .4byte gCurrentPinballGame
_08043E0C: .4byte 0x0000054F
_08043E10: .4byte 0x00000562
_08043E14: .4byte 0x0000055B
_08043E18: .4byte 0x00000553
_08043E1C:
	lsls r0, r6, #3
	ldr r7, _08043E4C @ =0x00000584
	adds r1, r5, r7
	adds r1, r1, r0
	ldr r2, _08043E50 @ =0x0000055F
	adds r0, r5, r2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _08043E54 @ =0x0000132C
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r0, [r0, #0x38]
	cmp r1, r0
	bge _08043E5C
	ldr r4, _08043E58 @ =0x00000553
	adds r0, r5, r4
	adds r0, r0, r6
	movs r1, #0xa
	b _08043E80
	.align 2, 0
_08043E4C: .4byte 0x00000584
_08043E50: .4byte 0x0000055F
_08043E54: .4byte 0x0000132C
_08043E58: .4byte 0x00000553
_08043E5C:
	lsls r0, r6, #1
	ldr r7, _08043EA4 @ =0x00000562
	adds r4, r5, r7
	adds r4, r4, r0
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0xa0
	bl __divsi3
	movs r1, #0xac
	subs r1, r1, r0
	strh r1, [r4]
	ldr r1, _08043EA8 @ =0x00000553
	adds r0, r5, r1
	adds r0, r0, r6
	movs r1, #8
_08043E80:
	strb r1, [r0]
	movs r0, #7
	bl sub_11B0
	ldr r2, _08043EAC @ =gCurrentPinballGame
	ldr r1, [r2]
	mov r3, sb
	asrs r0, r3, #0x10
	ldr r4, _08043EB0 @ =0x0000054F
	adds r1, r1, r4
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r2]
	ldr r0, _08043EB4 @ =0x00000BB8
	str r0, [r1, #0x3c]
	bl _080448E4
	.align 2, 0
_08043EA4: .4byte 0x00000562
_08043EA8: .4byte 0x00000553
_08043EAC: .4byte gCurrentPinballGame
_08043EB0: .4byte 0x0000054F
_08043EB4: .4byte 0x00000BB8
_08043EB8:
	ldr r5, _08043EE0 @ =gCurrentPinballGame
	ldr r2, [r5]
	mov r6, sb
	asrs r3, r6, #0x10
	lsls r1, r3, #1
	ldr r7, _08043EE4 @ =0x00000562
	adds r0, r2, r7
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #9
	bhi _08043EEC
	adds r0, #1
	strh r0, [r1]
	ldr r1, _08043EE8 @ =0x0000055B
	adds r0, r2, r1
	adds r0, r0, r3
	movs r1, #5
	strb r1, [r0]
	bl _080448E4
	.align 2, 0
_08043EE0: .4byte gCurrentPinballGame
_08043EE4: .4byte 0x00000562
_08043EE8: .4byte 0x0000055B
_08043EEC:
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08043F00 @ =0x00000553
	adds r0, r2, r4
	adds r0, r0, r3
	movs r1, #6
	strb r1, [r0]
	bl _080448E4
	.align 2, 0
_08043F00: .4byte 0x00000553
_08043F04:
	ldr r3, _08043F38 @ =gUnknown_086AFB2C
	ldr r7, _08043F3C @ =gCurrentPinballGame
	ldr r2, [r7]
	mov r6, sb
	asrs r5, r6, #0x10
	ldr r6, _08043F40 @ =0x0000055B
	adds r0, r2, r6
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, #2
	adds r0, r0, r3
	lsls r1, r5, #1
	ldr r3, _08043F44 @ =0x00000562
	adds r2, r2, r3
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08043F48
	adds r0, r1, #1
	strh r0, [r2]
	b _08043F86
	.align 2, 0
_08043F38: .4byte gUnknown_086AFB2C
_08043F3C: .4byte gCurrentPinballGame
_08043F40: .4byte 0x0000055B
_08043F44: .4byte 0x00000562
_08043F48:
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r0, [r7]
	ldr r4, _08043F9C @ =0x0000055B
	adds r0, r0, r4
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #9
	bne _08043F70
	strb r3, [r1]
	ldr r0, [r7]
	ldr r1, _08043FA0 @ =0x00000553
	adds r0, r0, r1
	adds r0, r0, r5
	strb r3, [r0]
_08043F70:
	ldr r0, [r7]
	adds r0, r0, r6
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _08043F86
	ldr r0, _08043FA4 @ =0x00000135
	bl m4aSongNumStart
_08043F86:
	ldr r0, _08043FA8 @ =gCurrentPinballGame
	ldr r1, [r0]
	mov r2, sb
	asrs r0, r2, #0x10
	ldr r3, _08043FAC @ =0x0000054F
	adds r1, r1, r3
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	bl _080448E4
	.align 2, 0
_08043F9C: .4byte 0x0000055B
_08043FA0: .4byte 0x00000553
_08043FA4: .4byte 0x00000135
_08043FA8: .4byte gCurrentPinballGame
_08043FAC: .4byte 0x0000054F
_08043FB0:
	ldr r3, _08043FE4 @ =gUnknown_086AFB2C
	ldr r6, _08043FE8 @ =gCurrentPinballGame
	ldr r2, [r6]
	mov r4, sb
	asrs r5, r4, #0x10
	ldr r7, _08043FEC @ =0x0000055B
	adds r0, r2, r7
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, #2
	adds r0, r0, r3
	lsls r1, r5, #1
	ldr r3, _08043FF0 @ =0x00000562
	adds r2, r2, r3
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08043FF4
	adds r0, r1, #1
	strh r0, [r2]
	b _08044068
	.align 2, 0
_08043FE4: .4byte gUnknown_086AFB2C
_08043FE8: .4byte gCurrentPinballGame
_08043FEC: .4byte 0x0000055B
_08043FF0: .4byte 0x00000562
_08043FF4:
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, [r6]
	ldr r4, _08044080 @ =0x0000055B
	adds r0, r1, r4
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bne _08044050
	ldr r2, _08044084 @ =0x00000553
	adds r0, r1, r2
	adds r0, r0, r5
	movs r1, #8
	strb r1, [r0]
	ldr r2, [r6]
	lsls r4, r5, #3
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r3, r2, r0
	adds r3, r3, r4
	ldr r1, _08044088 @ =0x0000055D
	adds r0, r2, r1
	adds r0, r0, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0804408C @ =0x00000584
	adds r3, r2, r0
	adds r3, r3, r4
	ldr r1, _08044090 @ =0x0000055F
	adds r2, r2, r1
	adds r2, r2, r5
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #8
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
_08044050:
	ldr r0, [r6]
	adds r0, r0, r7
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bne _08044068
	movs r0, #0xa0
	lsls r0, r0, #1
	bl m4aSongNumStart
_08044068:
	ldr r0, _08044094 @ =gCurrentPinballGame
	ldr r1, [r0]
	mov r2, sb
	asrs r0, r2, #0x10
	ldr r3, _08044098 @ =0x0000054F
	adds r1, r1, r3
	adds r1, r1, r0
	movs r0, #2
	strb r0, [r1]
	bl _080448E4
	.align 2, 0
_08044080: .4byte 0x0000055B
_08044084: .4byte 0x00000553
_08044088: .4byte 0x0000055D
_0804408C: .4byte 0x00000584
_08044090: .4byte 0x0000055F
_08044094: .4byte gCurrentPinballGame
_08044098: .4byte 0x0000054F
_0804409C:
	ldr r4, _080440D8 @ =gCurrentPinballGame
	ldr r1, [r4]
	mov r5, sb
	asrs r3, r5, #0x10
	lsls r4, r3, #1
	ldr r6, _080440DC @ =0x00000562
	adds r0, r1, r6
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0xb7
	bls _080440B4
	b _0804423C
_080440B4:
	cmp r0, #0x9f
	bhi _0804417C
	ldr r7, _080440E0 @ =0x00000551
	adds r0, r1, r7
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080440E4
	lsls r0, r3, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #0x10
	b _080440F2
	.align 2, 0
_080440D8: .4byte gCurrentPinballGame
_080440DC: .4byte 0x00000562
_080440E0: .4byte 0x00000551
_080440E4:
	lsls r0, r3, #3
	movs r3, #0xb0
	lsls r3, r3, #3
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0x10
_080440F2:
	str r0, [r1]
	ldr r4, _0804411C @ =gCurrentPinballGame
	ldr r3, [r4]
	mov r5, sb
	asrs r2, r5, #0x10
	lsls r1, r2, #1
	ldr r6, _08044120 @ =0x00000562
	adds r0, r3, r6
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08044128
	lsls r0, r2, #3
	ldr r7, _08044124 @ =0x00000584
	adds r1, r3, r7
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #0x10
	b _08044134
	.align 2, 0
_0804411C: .4byte gCurrentPinballGame
_08044120: .4byte 0x00000562
_08044124: .4byte 0x00000584
_08044128:
	lsls r0, r2, #3
	ldr r2, _08044160 @ =0x00000584
	adds r1, r3, r2
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #0x20
_08044134:
	str r0, [r1]
	ldr r3, _08044164 @ =gCurrentPinballGame
	ldr r4, [r3]
	mov r6, sb
	asrs r5, r6, #0x10
	lsls r1, r5, #1
	ldr r7, _08044168 @ =0x00000562
	adds r0, r4, r7
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x13
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _08044170
	ldr r1, _0804416C @ =0x0000055B
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #0xe
	b _08044216
	.align 2, 0
_08044160: .4byte 0x00000584
_08044164: .4byte gCurrentPinballGame
_08044168: .4byte 0x00000562
_0804416C: .4byte 0x0000055B
_08044170:
	ldr r2, _08044178 @ =0x0000055B
	adds r0, r4, r2
	adds r0, r0, r5
	b _08044214
	.align 2, 0
_08044178: .4byte 0x0000055B
_0804417C:
	ldr r4, _080441A0 @ =0x00000551
	adds r0, r1, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080441A4
	lsls r0, r3, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r1, r1, r5
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #0xa0
	lsls r6, r6, #1
	adds r0, r0, r6
	b _080441B4
	.align 2, 0
_080441A0: .4byte 0x00000551
_080441A4:
	lsls r0, r3, #3
	movs r7, #0xb0
	lsls r7, r7, #3
	adds r1, r1, r7
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r2, _080441E4 @ =0xFFFFFEC0
	adds r0, r0, r2
_080441B4:
	str r0, [r1]
	ldr r4, _080441E8 @ =gCurrentPinballGame
	ldr r3, [r4]
	mov r5, sb
	asrs r2, r5, #0x10
	lsls r1, r2, #1
	ldr r6, _080441EC @ =0x00000562
	adds r0, r3, r6
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080441F4
	lsls r0, r2, #3
	ldr r7, _080441F0 @ =0x00000584
	adds r1, r3, r7
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08044204
	.align 2, 0
_080441E4: .4byte 0xFFFFFEC0
_080441E8: .4byte gCurrentPinballGame
_080441EC: .4byte 0x00000562
_080441F0: .4byte 0x00000584
_080441F4:
	lsls r0, r2, #3
	ldr r4, _0804422C @ =0x00000584
	adds r1, r3, r4
	adds r1, r1, r0
	ldr r0, [r1]
	movs r5, #0xf0
	lsls r5, r5, #1
	adds r0, r0, r5
_08044204:
	str r0, [r1]
	ldr r6, _08044230 @ =gCurrentPinballGame
	ldr r0, [r6]
	mov r7, sb
	asrs r1, r7, #0x10
	ldr r2, _08044234 @ =0x0000055B
	adds r0, r0, r2
	adds r0, r0, r1
_08044214:
	movs r1, #0xf
_08044216:
	strb r1, [r0]
	ldr r3, _08044230 @ =gCurrentPinballGame
	ldr r0, [r3]
	mov r4, sb
	asrs r1, r4, #0xf
	ldr r5, _08044238 @ =0x00000562
	adds r0, r0, r5
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	b _080448E2
	.align 2, 0
_0804422C: .4byte 0x00000584
_08044230: .4byte gCurrentPinballGame
_08044234: .4byte 0x0000055B
_08044238: .4byte 0x00000562
_0804423C:
	ldr r6, _08044284 @ =0x00000553
	adds r1, r1, r6
	adds r1, r1, r3
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r7, _08044288 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _0804428C @ =0x0000055B
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0x10
	strb r1, [r0]
	ldr r1, [r7]
	ldr r5, _08044290 @ =0x00000562
	adds r0, r1, r5
	adds r0, r0, r4
	strh r2, [r0]
	subs r6, #2
	adds r0, r1, r6
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08044294
	lsls r0, r3, #3
	movs r7, #0xb0
	lsls r7, r7, #3
	adds r1, r1, r7
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0xf0
	str r0, [r1]
	b _080448E4
	.align 2, 0
_08044284: .4byte 0x00000553
_08044288: .4byte gCurrentPinballGame
_0804428C: .4byte 0x0000055B
_08044290: .4byte 0x00000562
_08044294:
	lsls r0, r3, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #0xf0
	str r0, [r1]
	b _080448E4
_080442A6:
	ldr r3, _080442DC @ =gUnknown_086AFB2C
	ldr r4, _080442E0 @ =gCurrentPinballGame
	ldr r2, [r4]
	mov r6, sb
	asrs r5, r6, #0x10
	ldr r6, _080442E4 @ =0x0000055B
	adds r0, r2, r6
	adds r4, r0, r5
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, #2
	adds r0, r0, r3
	lsls r1, r5, #1
	ldr r7, _080442E8 @ =0x00000562
	adds r2, r2, r7
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _080442EC
	adds r0, r1, #1
	strh r0, [r2]
	b _080448E4
	.align 2, 0
_080442DC: .4byte gUnknown_086AFB2C
_080442E0: .4byte gCurrentPinballGame
_080442E4: .4byte 0x0000055B
_080442E8: .4byte 0x00000562
_080442EC:
	movs r3, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _08044334 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08044338 @ =0x0000055B
	adds r0, r0, r2
	adds r1, r0, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x14
	bne _08044318
	strb r3, [r1]
	ldr r4, _08044334 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r7, _0804433C @ =0x00000553
	adds r0, r0, r7
	adds r0, r0, r5
	strb r3, [r0]
_08044318:
	ldr r1, _08044334 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r6
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x11
	beq _0804432C
	b _080448E4
_0804432C:
	ldr r0, _08044340 @ =0x00000135
	bl m4aSongNumStart
	b _080448E4
	.align 2, 0
_08044334: .4byte gCurrentPinballGame
_08044338: .4byte 0x0000055B
_0804433C: .4byte 0x00000553
_08044340: .4byte 0x00000135
_08044344:
	ldr r2, _0804442C @ =gCurrentPinballGame
	ldr r6, [r2]
	mov r3, sb
	asrs r4, r3, #0x10
	ldr r5, _08044430 @ =0x00000551
	adds r0, r6, r5
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #0
	bne _08044360
	movs r2, #3
_08044360:
	ldr r1, _08044434 @ =gUnknown_086AFAC0
	lsls r2, r2, #0x10
	lsrs r0, r2, #0xd
	adds r3, r0, r1
	ldrh r0, [r3, #4]
	lsls r5, r0, #0x10
	movs r7, #0
	mov ip, r1
	mov sl, r2
	cmp r5, #0
	ble _0804439E
	ldr r3, [r3]
	lsls r1, r4, #1
	ldr r2, _08044438 @ =0x00000566
	adds r0, r6, r2
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
_08044384:
	lsls r0, r7, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #2
	adds r0, r0, r3
	movs r6, #2
	ldrsh r0, [r0, r6]
	cmp r0, r1
	ble _0804439E
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r0, r5
	blt _08044384
_0804439E:
	ldr r1, _0804442C @ =gCurrentPinballGame
	ldr r0, [r1]
	mov r2, sb
	asrs r5, r2, #0x10
	ldr r4, _0804443C @ =0x00000559
	adds r0, r0, r4
	adds r0, r0, r5
	movs r3, #0
	strb r7, [r0]
	ldr r0, [r1]
	ldr r6, _08044440 @ =0x00000553
	adds r0, r0, r6
	adds r0, r0, r5
	movs r1, #0xb
	strb r1, [r0]
	ldr r7, _0804442C @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r1, _08044444 @ =0x0000055B
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #0x1d
	strb r1, [r0]
	ldr r2, [r7]
	lsls r1, r5, #1
	adds r6, #0xf
	adds r0, r2, r6
	adds r0, r0, r1
	movs r7, #0
	mov r8, r7
	strh r3, [r0]
	lsls r6, r5, #3
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r3, r2, r0
	adds r3, r3, r6
	mov r7, sl
	lsrs r1, r7, #0xd
	add r1, ip
	adds r4, r2, r4
	adds r4, r4, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #8
	str r0, [r3]
	ldr r0, _08044448 @ =0x00000584
	adds r2, r2, r0
	adds r2, r2, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	str r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r2, _0804442C @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _0804444C @ =0x0000054F
	adds r0, r0, r3
	adds r0, r0, r5
	mov r4, r8
	strb r4, [r0]
	b _080448E4
	.align 2, 0
_0804442C: .4byte gCurrentPinballGame
_08044430: .4byte 0x00000551
_08044434: .4byte gUnknown_086AFAC0
_08044438: .4byte 0x00000566
_0804443C: .4byte 0x00000559
_08044440: .4byte 0x00000553
_08044444: .4byte 0x0000055B
_08044448: .4byte 0x00000584
_0804444C: .4byte 0x0000054F
_08044450:
	ldr r5, _08044528 @ =gCurrentPinballGame
	ldr r6, [r5]
	mov r7, sb
	asrs r4, r7, #0x10
	ldr r0, _0804452C @ =0x00000551
	mov sl, r0
	adds r0, r6, r0
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #0
	bne _0804446E
	movs r2, #3
_0804446E:
	ldr r1, _08044530 @ =0x00000559
	adds r0, r6, r1
	adds r5, r0, r4
	movs r3, #0
	ldrsb r3, [r5, r3]
	mov r8, r3
	ldr r1, _08044534 @ =gUnknown_086AFAC0
	lsls r0, r2, #3
	adds r0, r0, r1
	mov ip, r0
	movs r7, #4
	ldrsh r0, [r0, r7]
	cmp r8, r0
	bge _08044566
	lsls r2, r4, #3
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r1, r1, r2
	mov r7, ip
	ldr r3, [r7]
	mov r7, r8
	lsls r0, r7, #2
	adds r0, r0, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #8
	str r0, [r1]
	ldr r0, _08044538 @ =0x00000584
	adds r1, r6, r0
	adds r1, r1, r2
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r2, #2
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	str r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r3, _08044528 @ =gCurrentPinballGame
	ldr r2, [r3]
	ldr r5, _08044530 @ =0x00000559
	adds r0, r2, r5
	adds r0, r0, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r6, ip
	movs r7, #4
	ldrsh r0, [r6, r7]
	cmp r1, r0
	bne _08044566
	ldr r1, _0804453C @ =0x00000553
	adds r0, r2, r1
	adds r0, r0, r4
	movs r1, #0xc
	strb r1, [r0]
	ldr r0, [r3]
	movs r2, #0xa6
	lsls r2, r2, #3
	adds r1, r0, r2
	adds r1, r1, r4
	add r0, sl
	adds r0, r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r3]
	ldr r3, _08044540 @ =0x00000536
	adds r0, r0, r3
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
	ldr r5, _08044528 @ =gCurrentPinballGame
	ldr r1, [r5]
	mov r6, sl
	adds r0, r1, r6
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08044544
	lsls r0, r4, #2
	adds r0, r1, r0
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r0, r7
	movs r1, #0xa0
	lsls r1, r1, #1
	b _08044550
	.align 2, 0
_08044528: .4byte gCurrentPinballGame
_0804452C: .4byte 0x00000551
_08044530: .4byte 0x00000559
_08044534: .4byte gUnknown_086AFAC0
_08044538: .4byte 0x00000584
_0804453C: .4byte 0x00000553
_08044540: .4byte 0x00000536
_08044544:
	lsls r0, r4, #2
	adds r0, r1, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _080445A4 @ =0x0000FEC0
_08044550:
	strh r1, [r0]
	ldr r2, _080445A8 @ =gCurrentPinballGame
	ldr r0, [r2]
	mov r3, sb
	asrs r1, r3, #0xe
	adds r0, r0, r1
	ldr r4, _080445AC @ =0x0000057A
	adds r0, r0, r4
	movs r1, #0xe8
	lsls r1, r1, #1
	strh r1, [r0]
_08044566:
	ldr r5, _080445A8 @ =gCurrentPinballGame
	ldr r0, [r5]
	mov r6, sb
	asrs r4, r6, #0x10
	ldr r7, _080445B0 @ =0x0000055B
	adds r3, r0, r7
	adds r3, r3, r4
	lsls r5, r4, #1
	ldr r2, _080445B4 @ =0x00000562
	adds r0, r0, r2
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #2
	adds r0, #0x1e
	strb r0, [r3]
	ldr r0, _080445A8 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, r2
	adds r2, r2, r5
	ldrh r0, [r2]
	adds r0, #1
	movs r3, #0
	strh r0, [r2]
	ldr r2, _080445B8 @ =0x0000054F
	adds r1, r1, r2
	adds r1, r1, r4
	strb r3, [r1]
	b _080448E4
	.align 2, 0
_080445A4: .4byte 0x0000FEC0
_080445A8: .4byte gCurrentPinballGame
_080445AC: .4byte 0x0000057A
_080445B0: .4byte 0x0000055B
_080445B4: .4byte 0x00000562
_080445B8: .4byte 0x0000054F
_080445BC:
	ldr r3, _08044610 @ =gCurrentPinballGame
	ldr r4, [r3]
	mov r5, sb
	asrs r6, r5, #0x10
	lsls r5, r6, #3
	movs r7, #0xb0
	lsls r7, r7, #3
	adds r3, r4, r7
	adds r3, r3, r5
	lsls r2, r6, #2
	adds r2, r4, r2
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _08044614 @ =0x00000584
	adds r1, r4, r0
	adds r1, r1, r5
	ldr r3, _08044618 @ =0x0000057A
	adds r2, r2, r3
	movs r5, #0
	ldrsh r2, [r2, r5]
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r7, _0804461C @ =0x0000055B
	adds r3, r4, r7
	adds r3, r3, r6
	lsls r5, r6, #1
	ldr r2, _08044620 @ =0x00000562
	adds r4, r4, r2
	adds r4, r4, r5
	ldrh r0, [r4]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #2
	adds r0, #0x1e
	b _08044676
	.align 2, 0
_08044610: .4byte gCurrentPinballGame
_08044614: .4byte 0x00000584
_08044618: .4byte 0x0000057A
_0804461C: .4byte 0x0000055B
_08044620: .4byte 0x00000562
_08044624:
	ldr r3, _08044694 @ =gCurrentPinballGame
	ldr r4, [r3]
	mov r5, sb
	asrs r6, r5, #0x10
	lsls r5, r6, #3
	movs r7, #0xb0
	lsls r7, r7, #3
	adds r3, r4, r7
	adds r3, r3, r5
	lsls r2, r6, #2
	adds r2, r4, r2
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _08044698 @ =0x00000584
	adds r1, r4, r0
	adds r1, r1, r5
	ldr r3, _0804469C @ =0x0000057A
	adds r2, r2, r3
	movs r5, #0
	ldrsh r2, [r2, r5]
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r7, _080446A0 @ =0x0000055B
	adds r3, r4, r7
	adds r3, r3, r6
	lsls r5, r6, #1
	ldr r2, _080446A4 @ =0x00000562
	adds r4, r4, r2
	adds r4, r4, r5
	ldrh r0, [r4]
	movs r1, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	adds r0, #0x1a
_08044676:
	strb r0, [r3]
	ldr r0, _08044694 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r2, r1, r2
	adds r2, r2, r5
	ldrh r0, [r2]
	adds r0, #1
	movs r3, #0
	strh r0, [r2]
	ldr r2, _080446A8 @ =0x0000054F
	adds r1, r1, r2
	adds r1, r1, r6
	strb r3, [r1]
	b _080448E4
	.align 2, 0
_08044694: .4byte gCurrentPinballGame
_08044698: .4byte 0x00000584
_0804469C: .4byte 0x0000057A
_080446A0: .4byte 0x0000055B
_080446A4: .4byte 0x00000562
_080446A8: .4byte 0x0000054F
_080446AC:
	ldr r3, _080446F0 @ =gCurrentPinballGame
	ldr r1, [r3]
	mov r5, sb
	asrs r4, r5, #0x10
	ldr r6, _080446F4 @ =0x00000557
	adds r1, r1, r6
	adds r1, r1, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r5, [r3]
	ldr r7, _080446F8 @ =0x0000054D
	adds r0, r5, r7
	adds r1, r0, r4
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _08044704
	subs r0, r2, #1
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _080446FC @ =0x0000055B
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #0x26
	strb r1, [r0]
	ldr r0, [r3]
	ldr r2, _08044700 @ =0x0000054B
	adds r0, r0, r2
	adds r0, r0, r4
_080446E8:
	movs r1, #1
	strb r1, [r0]
	b _080448E4
	.align 2, 0
_080446F0: .4byte gCurrentPinballGame
_080446F4: .4byte 0x00000557
_080446F8: .4byte 0x0000054D
_080446FC: .4byte 0x0000055B
_08044700: .4byte 0x0000054B
_08044704:
	lsls r2, r4, #1
	ldr r6, _08044748 @ =0x00000562
	adds r0, r5, r6
	adds r3, r0, r2
	ldrh r1, [r3]
	ldr r0, _0804474C @ =0x0000014D
	cmp r1, r0
	bls _08044716
	b _080448C4
_08044716:
	cmp r1, #0xf
	bhi _0804475C
	ldr r3, _08044750 @ =0x0000055B
	adds r0, r5, r3
	adds r0, r0, r4
	movs r1, #0x15
	strb r1, [r0]
	ldr r5, _08044754 @ =gCurrentPinballGame
	ldr r0, [r5]
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _0804473A
	movs r0, #0x9f
	lsls r0, r0, #1
	bl m4aSongNumStart
_0804473A:
	ldr r6, _08044754 @ =gCurrentPinballGame
	ldr r0, [r6]
	ldr r7, _08044758 @ =0x0000054F
	adds r0, r0, r7
	adds r0, r0, r4
	b _08044824
	.align 2, 0
_08044748: .4byte 0x00000562
_0804474C: .4byte 0x0000014D
_08044750: .4byte 0x0000055B
_08044754: .4byte gCurrentPinballGame
_08044758: .4byte 0x0000054F
_0804475C:
	ldr r0, _0804479C @ =0x0000013B
	cmp r1, r0
	bhi _08044840
	ldr r1, _080447A0 @ =0x0000054B
	adds r0, r5, r1
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080447B8
	lsls r0, r4, #3
	ldr r2, _080447A4 @ =0x00000584
	adds r1, r5, r2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0x40
	str r0, [r1]
	ldrh r0, [r3]
	movs r1, #0x13
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _080447AC
	ldr r3, _080447A8 @ =0x0000055B
	adds r0, r5, r3
	adds r0, r0, r4
	movs r1, #0x16
	b _080447F0
	.align 2, 0
_0804479C: .4byte 0x0000013B
_080447A0: .4byte 0x0000054B
_080447A4: .4byte 0x00000584
_080447A8: .4byte 0x0000055B
_080447AC:
	ldr r6, _080447B4 @ =0x0000055B
	adds r0, r5, r6
	b _080447EC
	.align 2, 0
_080447B4: .4byte 0x0000055B
_080447B8:
	lsls r0, r4, #3
	ldr r7, _080447E0 @ =0x00000584
	adds r1, r5, r7
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0x80
	str r0, [r1]
	ldrh r0, [r3]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080447E8
	ldr r1, _080447E4 @ =0x0000055B
	adds r0, r5, r1
	adds r0, r0, r4
	movs r1, #0x16
	b _080447F0
	.align 2, 0
_080447E0: .4byte 0x00000584
_080447E4: .4byte 0x0000055B
_080447E8:
	ldr r2, _0804482C @ =0x0000055B
	adds r0, r5, r2
_080447EC:
	adds r0, r0, r4
	movs r1, #0x17
_080447F0:
	strb r1, [r0]
	ldr r4, _08044830 @ =gCurrentPinballGame
	ldr r3, [r4]
	mov r5, sb
	asrs r2, r5, #0x10
	lsls r1, r2, #3
	ldr r6, _08044834 @ =0x00000584
	adds r0, r3, r6
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #8
	cmp r1, r0
	ble _0804481A
	lsls r0, r2, #1
	ldr r7, _08044838 @ =0x00000562
	adds r1, r3, r7
	adds r1, r1, r0
	movs r0, #0x9e
	lsls r0, r0, #1
	strh r0, [r1]
_0804481A:
	ldr r1, _08044830 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _0804483C @ =0x0000054F
	adds r0, r0, r3
	adds r0, r0, r2
_08044824:
	movs r1, #3
	strb r1, [r0]
	b _080448A0
	.align 2, 0
_0804482C: .4byte 0x0000055B
_08044830: .4byte gCurrentPinballGame
_08044834: .4byte 0x00000584
_08044838: .4byte 0x00000562
_0804483C: .4byte 0x0000054F
_08044840:
	lsls r0, r4, #3
	ldr r6, _0804486C @ =0x00000584
	adds r1, r5, r6
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #0x30
	str r0, [r1]
	ldr r7, _08044870 @ =0xFFFFFEC4
	adds r0, r7, #0
	ldrh r3, [r3]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bgt _08044878
	ldr r1, _08044874 @ =0x0000055B
	adds r0, r5, r1
	adds r0, r0, r4
	movs r1, #0x18
	b _08044880
	.align 2, 0
_0804486C: .4byte 0x00000584
_08044870: .4byte 0xFFFFFEC4
_08044874: .4byte 0x0000055B
_08044878:
	ldr r3, _080448B4 @ =0x0000055B
	adds r0, r5, r3
	adds r0, r0, r4
	movs r1, #0x19
_08044880:
	strb r1, [r0]
	cmp r2, #1
	bne _0804488E
	movs r0, #0x9b
	lsls r0, r0, #1
	bl m4aSongNumStart
_0804488E:
	ldr r2, _080448B8 @ =gCurrentPinballGame
	ldr r1, [r2]
	mov r4, sb
	asrs r0, r4, #0x10
	ldr r5, _080448BC @ =0x0000054F
	adds r1, r1, r5
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
_080448A0:
	ldr r6, _080448B8 @ =gCurrentPinballGame
	ldr r0, [r6]
	mov r7, sb
	asrs r1, r7, #0xf
	ldr r2, _080448C0 @ =0x00000562
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	b _080448E2
	.align 2, 0
_080448B4: .4byte 0x0000055B
_080448B8: .4byte gCurrentPinballGame
_080448BC: .4byte 0x0000054F
_080448C0: .4byte 0x00000562
_080448C4:
	ldr r3, _08044A9C @ =0x00000553
	adds r0, r5, r3
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08044AA0 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r6, _08044AA4 @ =0x0000055B
	adds r0, r0, r6
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r5]
	ldr r7, _08044AA8 @ =0x00000562
	adds r0, r0, r7
	adds r0, r0, r2
_080448E2:
	strh r1, [r0]
_080448E4:
	ldr r1, [sp]
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r3, r0, #0x10
	str r3, [sp]
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _080448FC
	bl _080438AA
_080448FC:
	movs r4, #0
	str r4, [sp]
_08044900:
	ldr r5, [sp]
	lsls r1, r5, #0x10
	asrs r4, r1, #0x10
	movs r0, #0xb8
	muls r0, r4, r0
	ldr r6, _08044AAC @ =gMain+0xD08 @gMain.spriteGroups[14]
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	mov sb, r1
	cmp r0, #0
	bne _0804491A
	b _08044D12
_0804491A:
	ldr r7, _08044AA0 @ =gCurrentPinballGame
	ldr r1, [r7]
	ldr r0, _08044AB0 @ =0x00000555
	adds r3, r1, r0
	adds r3, r3, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r2, _08044AA4 @ =0x0000055B
	adds r0, r1, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #1
	ldr r0, _08044AB4 @ =gUnknown_086AFB2C
	adds r0, #4
	adds r2, r2, r0
	ldr r5, _08044AB8 @ =0x00000551
	adds r1, r1, r5
	adds r1, r1, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #1
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	ldrb r2, [r2]
	adds r0, r0, r2
	strb r0, [r3]
	ldr r2, [r7]
	ldr r6, _08044AA4 @ =0x0000055B
	adds r0, r2, r6
	adds r0, r0, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r7, _08044AB4 @ =gUnknown_086AFB2C
	adds r0, r0, r7
	ldrh r5, [r0]
	lsls r3, r4, #3
	movs r1, #0xb0
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bge _0804498A
	adds r0, #0xff
_0804498A:
	asrs r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r0, #0xc
	subs r1, r1, r0
	mov r6, r8
	strh r1, [r6, #2]
	ldr r7, _08044ABC @ =0x00000584
	adds r0, r2, r7
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bge _080449A8
	adds r0, #0xff
_080449A8:
	asrs r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	adds r0, #0xe
	subs r1, r1, r0
	mov r0, r8
	strh r1, [r0, #4]
	ldr r2, [sp, #4]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08044AC0 @ =gUnknown_084B046C
	adds r0, r0, r1
	ldr r6, _08044AC4 @ =0x040000D4
	str r0, [r6]
	adds r0, r3, r4
	lsls r0, r0, #5
	ldr r7, _08044AC8 @ =0x06011CA0
	adds r0, r0, r7
	str r0, [r6, #4]
	ldr r0, _08044ACC @ =0x80000090
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	movs r7, #0
	lsls r0, r5, #0x10
	ldr r1, _08044AD0 @ =gOamBuffer
	mov ip, r1
	adds r6, r4, #0
	asrs r0, r0, #0x10
	mov sl, r0
_080449EA:
	lsls r0, r7, #0x10
	asrs r3, r0, #0x10
	lsls r0, r3, #3
	adds r0, #8
	mov r2, r8
	adds r5, r2, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	mov r4, sl
	lsls r1, r4, #1
	add r1, sl
	lsls r1, r1, #3
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r4, _08044AD4 @ =gUnknown_086B56D8
	adds r0, r0, r4
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldr r0, _08044AA0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08044AB8 @ =0x00000551
	adds r0, r1, r2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08044AE8
	cmp r3, #0
	bne _08044A5E
	ldr r3, _08044AD8 @ =0x0000055D
	adds r1, r1, r3
	adds r1, r1, r6
	ldrh r0, [r5]
	lsls r0, r0, #3
	add r0, ip
	ldrb r0, [r0, #2]
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r4, _08044AA0 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r0, _08044ADC @ =0x0000055F
	adds r1, r1, r0
	adds r1, r1, r6
	ldrh r0, [r5]
	lsls r0, r0, #3
	add r0, ip
	ldrb r0, [r0]
	strb r0, [r1]
_08044A5E:
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, ip
	ldrh r4, [r3, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov r2, r8
	movs r0, #2
	ldrsh r2, [r2, r0]
	str r2, [sp, #8]
	ldr r2, _08044AA0 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r2, _08044AD8 @ =0x0000055D
	adds r0, r0, r2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	ldr r2, [sp, #8]
	adds r0, r2, r0
	adds r1, r1, r0
	ldr r2, _08044AE0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldr r0, _08044AE4 @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r3, #2]
	b _08044B36
	.align 2, 0
_08044A9C: .4byte 0x00000553
_08044AA0: .4byte gCurrentPinballGame
_08044AA4: .4byte 0x0000055B
_08044AA8: .4byte 0x00000562
_08044AAC: .4byte gMain+0xD08 @gMain.spriteGroups[14]
_08044AB0: .4byte 0x00000555
_08044AB4: .4byte gUnknown_086AFB2C
_08044AB8: .4byte 0x00000551
_08044ABC: .4byte 0x00000584
_08044AC0: .4byte gUnknown_084B046C
_08044AC4: .4byte 0x040000D4
_08044AC8: .4byte 0x06011CA0
_08044ACC: .4byte 0x80000090
_08044AD0: .4byte gOamBuffer
_08044AD4: .4byte gUnknown_086B56D8
_08044AD8: .4byte 0x0000055D
_08044ADC: .4byte 0x0000055F
_08044AE0: .4byte 0x000001FF
_08044AE4: .4byte 0xFFFFFE00
_08044AE8:
	cmp r3, #0
	bne _08044B10
	ldr r3, _08044C24 @ =0x0000055D
	adds r1, r1, r3
	adds r1, r1, r6
	ldrh r0, [r5]
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0, #2]
	strb r0, [r1]
	ldr r4, _08044C28 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r0, _08044C2C @ =0x0000055F
	adds r1, r1, r0
	adds r1, r1, r6
	ldrh r0, [r5]
	lsls r0, r0, #3
	add r0, ip
	ldrb r0, [r0]
	strb r0, [r1]
_08044B10:
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	str r1, [sp, #0xc]
	mov r1, r8
	movs r4, #2
	ldrsh r0, [r1, r4]
	ldr r4, [sp, #0xc]
	adds r1, r4, r0
	ldr r4, _08044C30 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08044C34 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
_08044B36:
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, ip
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r3, [r1]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, ip
	ldrh r3, [r2, #4]
	lsls r1, r3, #0x16
	lsrs r1, r1, #0x16
	lsls r0, r6, #3
	adds r0, r0, r6
	adds r1, r1, r0
	ldr r4, _08044C38 @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08044C3C @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	lsls r0, r7, #0x10
	movs r5, #0x80
	lsls r5, r5, #9
	adds r0, r0, r5
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt _08044B78
	b _080449EA
_08044B78:
	ldr r6, _08044C28 @ =gCurrentPinballGame
	ldr r2, [r6]
	mov r7, sb
	asrs r3, r7, #0x10
	lsls r0, r3, #2
	adds r6, r2, r0
	lsls r4, r3, #3
	movs r1, #0xb0
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bge _08044B96
	adds r0, #0xff
_08044B96:
	asrs r1, r0, #8
	ldr r5, _08044C24 @ =0x0000055D
	adds r0, r2, r5
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r7, #0xae
	lsls r7, r7, #3
	adds r0, r6, r7
	strh r1, [r0]
	ldr r1, _08044C40 @ =0x00000584
	adds r0, r2, r1
	adds r7, r0, r4
	ldr r1, [r7]
	cmp r1, #0
	bge _08044BC0
	adds r1, #0xff
_08044BC0:
	asrs r1, r1, #8
	ldr r4, _08044C2C @ =0x0000055F
	adds r0, r2, r4
	adds r5, r0, r3
	movs r0, #0
	ldrsb r0, [r5, r0]
	subs r0, #0x12
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r4, #0x13
	adds r0, r6, r4
	strh r1, [r0]
	lsls r1, r3, #1
	ldr r6, _08044C44 @ =0x00000566
	adds r0, r2, r6
	adds r4, r0, r1
	ldr r0, [r7]
	cmp r0, #0
	bge _08044BE8
	adds r0, #0xff
_08044BE8:
	asrs r1, r0, #8
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r0, r0, r1
	strh r0, [r4]
	movs r0, #0xb8
	muls r0, r3, r0
	ldr r7, _08044C48 @ =gMain+0xE78 @gMain.spriteGroups[16]
	adds r0, r0, r7
	mov r8, r0
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	beq _08044C0A
	cmp r0, #0x2a
	bne _08044C50
_08044C0A:
	ldr r4, _08044C4C @ =0x0000055B
	adds r0, r2, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r5, #9
	str r5, [sp, #4]
	cmp r0, #0xb
	bne _08044C54
	movs r6, #8
	str r6, [sp, #4]
	b _08044C54
	.align 2, 0
_08044C24: .4byte 0x0000055D
_08044C28: .4byte gCurrentPinballGame
_08044C2C: .4byte 0x0000055F
_08044C30: .4byte 0x000001FF
_08044C34: .4byte 0xFFFFFE00
_08044C38: .4byte 0x000003FF
_08044C3C: .4byte 0xFFFFFC00
_08044C40: .4byte 0x00000584
_08044C44: .4byte 0x00000566
_08044C48: .4byte gMain+0xE78 @gMain.spriteGroups[16]
_08044C4C: .4byte 0x0000055B
_08044C50:
	movs r7, #0
	str r7, [sp, #4]
_08044C54:
	ldr r0, _08044D34 @ =gCurrentPinballGame
	ldr r2, [r0]
	mov r1, sb
	asrs r4, r1, #0x10
	lsls r3, r4, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r0, r2, r5
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bge _08044C6E
	adds r0, #0xff
_08044C6E:
	asrs r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	adds r0, #0xc
	subs r1, r1, r0
	mov r6, r8
	strh r1, [r6, #2]
	ldr r7, _08044D38 @ =0x00000584
	adds r0, r2, r7
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bge _08044C8C
	adds r0, #0xff
_08044C8C:
	asrs r1, r0, #8
	adds r0, r2, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	adds r0, #0xe
	subs r1, r1, r0
	mov r0, r8
	strh r1, [r0, #4]
	ldr r2, [sp, #4]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r5, _08044D3C @ =gUnknown_084B046C
	adds r0, r0, r5
	ldr r6, _08044D40 @ =0x040000D4
	str r0, [r6]
	adds r0, r3, r4
	lsls r0, r0, #5
	ldr r7, _08044D44 @ =0x06011EE0
	adds r0, r0, r7
	str r0, [r6, #4]
	ldr r0, _08044D48 @ =0x80000090
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	movs r7, #0
	ldr r6, _08044D4C @ =gOamBuffer
	ldr r0, _08044D50 @ =0xFFFFFE00
	mov sl, r0
_08044CC8:
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	mov r1, r8
	adds r5, r1, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r6
	movs r4, #2
	ldrsh r1, [r5, r4]
	mov r7, r8
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r7, _08044D54 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	ldrh r4, [r2, #2]
	mov r0, sl
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r2, r8
	ldrb r0, [r2, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #3
	ble _08044CC8
_08044D12:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r3, r0, #0x10
	str r3, [sp]
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _08044D24
	b _08044900
_08044D24:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044D34: .4byte gCurrentPinballGame
_08044D38: .4byte 0x00000584
_08044D3C: .4byte gUnknown_084B046C
_08044D40: .4byte 0x040000D4
_08044D44: .4byte 0x06011EE0
_08044D48: .4byte 0x80000090
_08044D4C: .4byte gOamBuffer
_08044D50: .4byte 0xFFFFFE00
_08044D54: .4byte 0x000001FF

	thumb_func_start sub_44D58
sub_44D58: @ 0x08044D58
	push {r4, r5, r6, r7, lr}
	movs r0, #0
	mov ip, r0
	ldr r6, _08044EE4 @ =gMain+0xFE8 @gMain.spriteGroups[18]
	ldrh r0, [r6]
	ldr r7, _08044EE8 @ =gCurrentPinballGame
	cmp r0, #0
	beq _08044DE8
	ldr r0, [r7]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x68
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x56
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r0, [r7]
	ldr r2, _08044EEC @ =0x00000542
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0x15
	bhi _08044D9C
	ldr r0, _08044EF0 @ =gUnknown_08137D60
	ldrh r1, [r1]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
_08044D9C:
	ldr r2, _08044EF4 @ =0x040000D4
	mov r3, ip
	lsls r0, r3, #0x10
	asrs r0, r0, #7
	ldr r1, _08044EF8 @ =gUnknown_084AF9EC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08044EFC @ =0x06010920
	str r0, [r2, #4]
	ldr r0, _08044F00 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _08044F04 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08044F08 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08044F0C @ =0xFFFFFE00
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
_08044DE8:
	ldr r6, _08044F10 @ =gMain+0xAE0 @gMain.spriteGroups[11]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08044E72
	ldr r0, [r7]
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x68
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r0, [r7]
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x5e
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _08044EF4 @ =0x040000D4
	mov r0, ip
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08044F14 @ =gUnknown_084AFFEC
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08044F18 @ =0x06010B20
	str r0, [r2, #4]
	ldr r0, _08044F1C @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r7, _08044F04 @ =gOamBuffer
	ldr r1, _08044F0C @ =0xFFFFFE00
	mov ip, r1
_08044E2E:
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
	ldr r2, _08044F08 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	ble _08044E2E
_08044E72:
	ldr r4, _08044EE8 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	cmp r1, #1
	bne _08044E88
	ldr r0, _08044F20 @ =gMain
	movs r3, #0xae
	lsls r3, r3, #4
	adds r0, r0, r3
	strh r1, [r0]
_08044E88:
	ldr r1, [r4]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bgt _08044EC8
	ldr r0, _08044F20 @ =gMain
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	bne _08044EC8
	ldr r5, _08044EEC @ =0x00000542
	adds r0, r1, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _08044EC8
	cmp r0, #0x15
	bne _08044EB0
	ldr r0, _08044F24 @ =gMPlayInfo_SE1
	ldr r1, _08044F28 @ =gUnknown_086A2D94
	bl MPlayStart
_08044EB0:
	ldr r1, [r4]
	adds r1, r1, r5
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08044EC8
	ldr r0, _08044F24 @ =gMPlayInfo_SE1
	ldr r1, _08044F2C @ =gUnknown_086A2E70
	bl MPlayStart
_08044EC8:
	ldr r0, _08044EE8 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _08044F34
	ldr r0, _08044F20 @ =gMain
	ldrb r0, [r0, #5]
	cmp r0, #0
	bne _08044F30
	bl sub_44F3C
	b _08044F34
	.align 2, 0
_08044EE4: .4byte gMain+0xFE8 @gMain.spriteGroups[18]
_08044EE8: .4byte gCurrentPinballGame
_08044EEC: .4byte 0x00000542
_08044EF0: .4byte gUnknown_08137D60
_08044EF4: .4byte 0x040000D4
_08044EF8: .4byte gUnknown_084AF9EC
_08044EFC: .4byte 0x06010920
_08044F00: .4byte 0x80000100
_08044F04: .4byte gOamBuffer
_08044F08: .4byte 0x000001FF
_08044F0C: .4byte 0xFFFFFE00
_08044F10: .4byte gMain+0xAE0 @gMain.spriteGroups[11]
_08044F14: .4byte gUnknown_084AFFEC
_08044F18: .4byte 0x06010B20
_08044F1C: .4byte 0x800000C0
_08044F20: .4byte gMain
_08044F24: .4byte gMPlayInfo_SE1
_08044F28: .4byte gUnknown_086A2D94
_08044F2C: .4byte gUnknown_086A2E70
_08044F30:
	bl sub_45164
_08044F34:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_44F3C
sub_44F3C: @ 0x08044F3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r6, _08045010 @ =gMain+0x10A0 @gMain.spriteGroups[19]
	ldrh r0, [r6]
	ldr r1, _08045014 @ =gCurrentPinballGame
	mov sb, r1
	ldr r2, _08045018 @ =gUnknown_086AFC16
	mov r8, r2
	cmp r0, #0
	beq _08044FE6
	ldr r1, [r1]
	ldr r3, _0804501C @ =0x00000591
	adds r0, r1, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	add r2, r8
	ldrh r0, [r2, #4]
	adds r0, #0x86
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r1, [r2, #6]
	adds r1, #0x9a
	mov r3, sb
	ldr r0, [r3]
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r6, #4]
	ldr r3, _08045020 @ =0x040000D4
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08045024 @ =gUnknown_084B7FEC
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _08045028 @ =0x06012120
	str r0, [r3, #4]
	ldr r0, _0804502C @ =0x80000230
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	movs r0, #0
	ldr r7, _08045030 @ =gOamBuffer
	ldr r1, _08045034 @ =0xFFFFFE00
	mov ip, r1
_08044FA2:
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
	ldr r2, _08045038 @ =0x000001FF
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
	ble _08044FA2
_08044FE6:
	mov r5, sb
	ldr r2, [r5]
	ldr r6, _0804501C @ =0x00000591
	adds r4, r2, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #3
	mov r1, r8
	adds r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldr r1, _0804503C @ =0x00000592
	adds r2, r2, r1
	ldrh r3, [r2]
	cmp r0, r3
	ble _08045040
	adds r0, r3, #1
	strh r0, [r2]
	b _08045148
	.align 2, 0
_08045010: .4byte gMain+0x10A0 @gMain.spriteGroups[19]
_08045014: .4byte gCurrentPinballGame
_08045018: .4byte gUnknown_086AFC16
_0804501C: .4byte 0x00000591
_08045020: .4byte 0x040000D4
_08045024: .4byte gUnknown_084B7FEC
_08045028: .4byte 0x06012120
_0804502C: .4byte 0x80000230
_08045030: .4byte gOamBuffer
_08045034: .4byte 0xFFFFFE00
_08045038: .4byte 0x000001FF
_0804503C: .4byte 0x00000592
_08045040:
	movs r3, #0
	mov r8, r3
	movs r7, #0
	strh r7, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r0, [r5]
	ldr r1, _08045154 @ =0x00000591
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #1
	bne _08045066
	ldr r0, _08045158 @ =gMain
	movs r2, #0x85
	lsls r2, r2, #5
	adds r0, r0, r2
	strh r1, [r0]
_08045066:
	ldr r0, [r5]
	adds r1, r0, r6
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x13
	bne _08045086
	movs r0, #0x12
	strb r0, [r1]
	ldr r0, _08045158 @ =gMain
	movs r3, #0x85
	lsls r3, r3, #5
	adds r0, r0, r3
	strh r7, [r0]
	ldr r0, [r5]
	adds r0, #0x7e
	strh r7, [r0]
_08045086:
	ldr r2, [r5]
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #9
	bne _080450C8
	ldr r0, _0804515C @ =0x0000132C
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0xa]
	subs r0, #0x40
	strh r0, [r1, #0xa]
	ldr r1, [r2]
	movs r0, #0x8d
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r2]
	movs r0, #0xc8
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r1, [r2]
	ldr r0, _08045160 @ =0x0000FFA0
	strh r0, [r1, #0x30]
	ldr r1, [r2]
	movs r0, #0x54
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	movs r0, #3
	strb r0, [r1, #1]
	movs r0, #7
	bl sub_11B0
_080450C8:
	ldr r0, [r5]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _080450DC
	movs r0, SE_UNKNOWN_0xD3
	bl m4aSongNumStart
_080450DC:
	ldr r0, [r5]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xf
	bne _080450F0
	movs r0, SE_UNKNOWN_0xD4
	bl m4aSongNumStart
_080450F0:
	ldr r0, [r5]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	bne _08045134
	movs r0, SE_UNKNOWN_0xD6
	bl m4aSongNumStart
	ldr r0, [r5]
	ldr r2, _0804515C @ =0x0000132C
	adds r0, r0, r2
	ldr r0, [r0]
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r5]
	adds r1, r1, r2
	ldr r2, [r1]
	ldrh r0, [r2, #0xa]
	subs r0, #0x40
	strh r0, [r2, #0xa]
	ldr r2, [r1]
	movs r0, #0x8f
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r2, [r1]
	movs r0, #0xc3
	lsls r0, r0, #8
	str r0, [r2, #0x38]
	ldr r0, [r1]
	strh r7, [r0, #0x30]
	ldr r0, [r1]
	strh r7, [r0, #0x32]
_08045134:
	mov r2, sb
	ldr r1, [r2]
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	bne _08045148
	mov r3, r8
	strb r3, [r1, #0x1f]
_08045148:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045154: .4byte 0x00000591
_08045158: .4byte gMain
_0804515C: .4byte 0x0000132C
_08045160: .4byte 0x0000FFA0

	thumb_func_start sub_45164
sub_45164: @ 0x08045164
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _080452A0 @ =gMain+0x1158 @gMain.spriteGroups[20]
	ldrh r0, [r6]
	cmp r0, #0
	beq _08045234
	ldr r0, _080452A4 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r4, #0x58
	ldrh r1, [r4]
	subs r1, #0x92
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldr r3, _080452A4 @ =gCurrentPinballGame
	ldr r4, [r3]
	ldr r1, _080452A8 @ =0x00000322
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r5, r0, #0
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	subs r0, #0x6e
	subs r5, r5, r0
	ldr r3, _080452AC @ =0x0000030E
	adds r4, r4, r3
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	adds r5, r5, r0
	strh r5, [r6, #4]
	ldr r2, _080452A4 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _080452B0 @ =0x00000591
	adds r0, r0, r3
	ldr r2, _080452B4 @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _080452B8 @ =gUnknown_084BB16C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080452BC @ =0x060125A0
	str r0, [r2, #4]
	ldr r0, _080452C0 @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldr r7, _080452C4 @ =gOamBuffer
	ldr r1, _080452C8 @ =0xFFFFFE00
	mov r8, r1
_080451F0:
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
	ldr r2, _080452CC @ =0x000001FF
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
	cmp r5, #3
	ble _080451F0
_08045234:
	ldr r3, _080452A4 @ =gCurrentPinballGame
	ldr r4, [r3]
	ldr r1, _080452D0 @ =0x00000592
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0xfa
	bhi _080452F0
	cmp r0, #0xfa
	beq _08045248
	b _08045594
_08045248:
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0xe6
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r3, _080452A8 @ =0x00000322
	adds r1, r4, r3
	ldr r0, _080452D4 @ =0x0000FF9C
	strh r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _080452D8 @ =0x0000FFAE
	strh r0, [r1]
	ldr r1, _080452DC @ =0x0000031E
	adds r0, r4, r1
	strh r2, [r0]
	subs r3, #0x16
	adds r0, r4, r3
	strh r2, [r0]
	ldr r0, _080452E0 @ =0x00000306
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080452A4 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080452B0 @ =0x00000591
	adds r0, r0, r2
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, _080452E4 @ =gMain
	ldr r3, _080452E8 @ =0x00001158
	adds r0, r0, r3
	movs r2, #1
	movs r1, #1
	strh r1, [r0]
	ldr r1, _080452A4 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r3, _080452EC @ =0x000005FA
	adds r0, r0, r3
	strb r2, [r0]
	b _08045594
	.align 2, 0
_080452A0: .4byte gMain+0x1158 @gMain.spriteGroups[20]
_080452A4: .4byte gCurrentPinballGame
_080452A8: .4byte 0x00000322
_080452AC: .4byte 0x0000030E
_080452B0: .4byte 0x00000591
_080452B4: .4byte 0x040000D4
_080452B8: .4byte gUnknown_084BB16C
_080452BC: .4byte 0x060125A0
_080452C0: .4byte 0x80000240
_080452C4: .4byte gOamBuffer
_080452C8: .4byte 0xFFFFFE00
_080452CC: .4byte 0x000001FF
_080452D0: .4byte 0x00000592
_080452D4: .4byte 0x0000FF9C
_080452D8: .4byte 0x0000FFAE
_080452DC: .4byte 0x0000031E
_080452E0: .4byte 0x00000306
_080452E4: .4byte gMain
_080452E8: .4byte 0x00001158
_080452EC: .4byte 0x000005FA
_080452F0:
	movs r5, #0xc3
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r0, [r0]
	movs r1, #0x18
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	adds r0, #0xd
	ldr r2, _0804537C @ =0x00000591
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08045380 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, r0, r5
	ldrh r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x10
	bl Sin
	adds r1, r0, #0
	ldr r0, _08045380 @ =gCurrentPinballGame
	ldr r4, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08045384 @ =0x00004E20
	bl __divsi3
	ldr r2, _08045388 @ =0x0000030E
	adds r1, r4, r2
	strh r0, [r1]
	adds r4, r4, r5
	ldrh r0, [r4]
	cmp r0, #0
	bne _0804534A
	movs r0, SE_UNKNOWN_0xE4
	bl m4aSongNumStart
_0804534A:
	ldr r3, _08045380 @ =gCurrentPinballGame
	ldr r4, [r3]
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x27
	bhi _08045390
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _0804538C @ =0x00000322
	adds r1, r4, r0
	adds r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	b _0804539A
	.align 2, 0
_0804537C: .4byte 0x00000591
_08045380: .4byte gCurrentPinballGame
_08045384: .4byte 0x00004E20
_08045388: .4byte 0x0000030E
_0804538C: .4byte 0x00000322
_08045390:
	ldr r0, _0804547C @ =gMain
	ldr r1, _08045480 @ =0x00001158
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
_0804539A:
	ldr r0, _08045484 @ =gCurrentPinballGame
	ldr r2, [r0]
	movs r6, #0xc3
	lsls r6, r6, #2
	adds r1, r2, r6
	ldrh r1, [r1]
	cmp r1, #0xd
	bne _08045416
	ldr r5, _08045488 @ =0x0000132C
	adds r0, r2, r5
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045484 @ =gCurrentPinballGame
	ldr r4, [r2]
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r1, r4, r3
	ldr r0, _0804548C @ =0x0000FFF6
	strh r0, [r1]
	ldr r0, _08045490 @ =0x00000316
	adds r1, r4, r0
	ldr r0, _08045494 @ =0x0000FFE7
	strh r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x9d
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _08045498 @ =0x00000322
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, #0x86
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r3, _0804549C @ =0x0000031A
	adds r0, r4, r3
	strh r1, [r0]
	adds r4, r4, r5
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #1]
_08045416:
	ldr r0, _08045484 @ =gCurrentPinballGame
	ldr r7, [r0]
	ldrb r0, [r7, #0x1f]
	cmp r0, #0
	bne _08045422
	b _08045584
_08045422:
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #0xc
	bhi _080454A0
	ldr r1, _08045488 @ =0x0000132C
	adds r4, r7, r1
	ldr r5, [r4]
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x9d
	strh r0, [r5, #0x10]
	ldr r5, [r4]
	ldr r1, _08045498 @ =0x00000322
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xa
	bl __divsi3
	adds r0, #0x86
	strh r0, [r5, #0x12]
	ldr r1, [r4]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r1, [r4]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r4]
	b _0804557C
	.align 2, 0
_0804547C: .4byte gMain
_08045480: .4byte 0x00001158
_08045484: .4byte gCurrentPinballGame
_08045488: .4byte 0x0000132C
_0804548C: .4byte 0x0000FFF6
_08045490: .4byte 0x00000316
_08045494: .4byte 0x0000FFE7
_08045498: .4byte 0x00000322
_0804549C: .4byte 0x0000031A
_080454A0:
	ldr r3, _080455B0 @ =0x00000316
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #2
	movs r2, #0
	mov r8, r2
	movs r3, #0
	mov sl, r3
	strh r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldr r0, _080455B4 @ =0x0000031A
	adds r4, r7, r0
	ldrh r0, [r1]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldr r3, _080455B8 @ =0x0000132C
	mov sb, r3
	adds r5, r7, r3
	ldr r6, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #0x10]
	ldr r6, [r5]
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #0x12]
	ldr r5, [r5]
	movs r3, #0x12
	ldrsh r0, [r5, r3]
	cmp r0, #0xb4
	ble _08045556
	movs r0, #0xb5
	strh r0, [r5, #0x12]
	ldr r1, _080455BC @ =0x000005F7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _080455C0 @ =gCurrentPinballGame
	ldr r0, [r3]
	strb r2, [r0, #0x1f]
	ldr r1, [r3]
	ldr r0, _080455B8 @ =0x0000132C
	adds r3, r1, r0
	ldr r2, [r3]
	ldr r0, _080455C4 @ =0x0000FFF6
	strh r0, [r2, #0x30]
	ldr r0, [r3]
	mov r2, sl
	strh r2, [r0, #0x32]
	ldr r3, _080455C8 @ =0x000005FA
	adds r1, r1, r3
	mov r0, r8
	strb r0, [r1]
	ldr r1, _080455C0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080455B8 @ =0x0000132C
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1, #1]
	ldr r3, _080455C0 @ =gCurrentPinballGame
	ldr r0, [r3]
	adds r0, #0x24
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x7e
	mov r2, sl
	strh r2, [r0]
	movs r0, SE_UNKNOWN_0xE5
	bl m4aSongNumStart
	movs r0, #7
	bl sub_11B0
_08045556:
	ldr r3, _080455C0 @ =gCurrentPinballGame
	ldr r1, [r3]
	add r1, sb
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r2, [r1]
	movs r3, #0x12
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	strh r0, [r2, #0x2a]
	ldr r2, [r1]
	movs r3, #0x10
	ldrsh r0, [r2, r3]
	lsls r0, r0, #8
	str r0, [r2, #0x34]
	ldr r1, [r1]
_0804557C:
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
_08045584:
	ldr r3, _080455C0 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r0, #0xc3
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08045594:
	ldr r2, _080455C0 @ =gCurrentPinballGame
	ldr r1, [r2]
	ldr r3, _080455CC @ =0x00000592
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080455B0: .4byte 0x00000316
_080455B4: .4byte 0x0000031A
_080455B8: .4byte 0x0000132C
_080455BC: .4byte 0x000005F7
_080455C0: .4byte gCurrentPinballGame
_080455C4: .4byte 0x0000FFF6
_080455C8: .4byte 0x000005FA
_080455CC: .4byte 0x00000592

	thumb_func_start sub_455D0
sub_455D0: @ 0x080455D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r2, #0
_080455DE:
	ldr r3, _08045608 @ =gCurrentPinballGame
	ldr r0, [r3]
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldr r4, _0804560C @ =0x00000536
	adds r0, r0, r4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r8, r3
	str r2, [sp]
	cmp r0, #5
	bls _080455FE
	bl _08045DE0
_080455FE:
	lsls r0, r0, #2
	ldr r1, _08045610 @ =_08045614
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08045608: .4byte gCurrentPinballGame
_0804560C: .4byte 0x00000536
_08045610: .4byte _08045614
_08045614: @ jump table
	.4byte _0804562C @ case 0
	.4byte _08045642 @ case 1
	.4byte _080456E0 @ case 2
	.4byte _08045778 @ case 3
	.4byte _08045B00 @ case 4
	.4byte _08045C4C @ case 5
_0804562C:
	mov r5, r8
	ldr r0, [r5]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	movs r3, #0xa6
	lsls r3, r3, #3
	adds r0, r0, r3
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	b _08045DE0
_08045642:
	mov r4, r8
	ldr r1, [r4]
	ldr r5, [sp]
	asrs r6, r5, #0x10
	movs r2, #0xa6
	lsls r2, r2, #3
	adds r0, r1, r2
	adds r0, r0, r6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r4, #0xe8
	lsls r4, r4, #2
	mov sl, r4
	add r1, sl
	adds r1, r1, r3
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	mov r5, r8
	ldr r1, [r5]
	lsls r7, r3, #1
	movs r0, #0xec
	lsls r0, r0, #2
	mov sb, r0
	adds r0, r1, r0
	adds r0, r0, r7
	movs r4, #0
	mov ip, r4
	strh r2, [r0]
	ldr r2, _080456D4 @ =0x000003A3
	adds r1, r1, r2
	adds r1, r1, r3
	movs r0, #7
	strb r0, [r1]
	ldr r5, [r5]
	lsls r1, r6, #1
	ldr r4, _080456D8 @ =0x0000053C
	adds r0, r5, r4
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	bne _08045698
	b _08045DE0
_08045698:
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080456A6
	b _08045DE0
_080456A6:
	ldr r1, _080456DC @ =0x00000536
	adds r0, r5, r1
	adds r0, r0, r6
	mov r5, ip
	strb r5, [r0]
	mov r1, r8
	ldr r0, [r1]
	add r0, sl
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	mov r5, r8
	ldr r1, [r5]
	mov r5, sb
	adds r0, r1, r5
	adds r0, r0, r7
	strh r4, [r0]
	adds r1, r1, r2
	adds r1, r1, r3
	movs r0, #4
	strb r0, [r1]
	b _08045DE0
	.align 2, 0
_080456D4: .4byte 0x000003A3
_080456D8: .4byte 0x0000053C
_080456DC: .4byte 0x00000536
_080456E0:
	mov r0, r8
	ldr r1, [r0]
	ldr r2, [sp]
	asrs r6, r2, #0x10
	movs r3, #0xa6
	lsls r3, r3, #3
	adds r0, r1, r3
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r6, #2
	bne _0804571E
	movs r0, #1
	strb r0, [r1, #0x1f]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _08045768 @ =0x0000132C
	adds r0, r0, r1
	ldr r3, [r0]
	ldrh r2, [r3, #0x30]
	adds r2, #5
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r2, r2, r0
	strh r2, [r3, #0x30]
_0804571E:
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _0804576C @ =0x00000536
	adds r1, r1, r3
	adds r1, r1, r6
	movs r4, #0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r2]
	ldr r1, _08045770 @ =0x00000533
	adds r0, r0, r1
	adds r0, r0, r6
	strb r4, [r0]
	ldr r1, [r2]
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r1, r1, r3
	movs r0, #2
	strb r0, [r1]
	mov r5, r8
	ldr r1, [r5]
	lsls r2, r3, #1
	movs r5, #0xec
	lsls r5, r5, #2
	adds r0, r1, r5
	adds r0, r0, r2
	strh r4, [r0]
	ldr r0, _08045774 @ =0x000003A3
	adds r1, r1, r0
	adds r1, r1, r3
	movs r0, #7
	strb r0, [r1]
	b _08045DE0
	.align 2, 0
_08045768: .4byte 0x0000132C
_0804576C: .4byte 0x00000536
_08045770: .4byte 0x00000533
_08045774: .4byte 0x000003A3
_08045778:
	mov r1, r8
	ldr r2, [r1]
	ldr r4, [sp]
	asrs r3, r4, #0x10
	movs r5, #0xa6
	lsls r5, r5, #3
	adds r0, r2, r5
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r3, #1
	ble _08045798
	b _0804599C
_08045798:
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	mov sb, r0
	cmp r4, #0
	bne _080457C8
	lsls r1, r3, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r0, r2, r5
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _080457C4 @ =0x000055FF
	cmp r1, r0
	ble _080457EA
	lsls r0, r3, #2
	adds r0, r2, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r0, r1
	strh r4, [r0]
	b _080457EA
	.align 2, 0
_080457C4: .4byte 0x000055FF
_080457C8:
	lsls r1, r3, #3
	movs r4, #0xb0
	lsls r4, r4, #3
	adds r0, r2, r4
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x9c
	lsls r0, r0, #8
	cmp r1, r0
	bgt _080457EA
	lsls r0, r3, #2
	adds r0, r2, r0
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
_080457EA:
	mov r0, r8
	ldr r2, [r0]
	ldr r1, [sp]
	asrs r5, r1, #0x10
	lsls r7, r5, #2
	adds r1, r2, r7
	ldr r3, _08045870 @ =0x0000057A
	mov sl, r3
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0xc
	strh r0, [r1]
	mov r4, sb
	asrs r6, r4, #0x10
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08045880
	lsls r1, r5, #3
	adds r3, #0xa
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08045874 @ =0x000065FF
	cmp r1, r0
	bgt _0804582A
	b _08045DE0
_0804582A:
	ldr r4, _08045878 @ =0x00000533
	adds r0, r2, r4
	adds r0, r0, r5
	movs r1, #0
	strb r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	subs r3, #0x4e
	adds r0, r0, r3
	adds r0, r0, r5
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r0, r0, r6
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r5, _0804587C @ =0x000003A3
	adds r0, r0, r5
	adds r0, r0, r6
	movs r1, #0xf
	strb r1, [r0]
	ldr r0, [r2]
	lsls r1, r6, #1
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r0, r2
	adds r0, r0, r1
	movs r3, #0
	strh r3, [r0]
	b _08045DE0
	.align 2, 0
_08045870: .4byte 0x0000057A
_08045874: .4byte 0x000065FF
_08045878: .4byte 0x00000533
_0804587C: .4byte 0x000003A3
_08045880:
	lsls r3, r5, #3
	ldr r4, _08045904 @ =0x00000584
	mov sb, r4
	adds r0, r2, r4
	adds r0, r0, r3
	ldr r1, [r0]
	ldr r0, _08045908 @ =0x000065FF
	cmp r1, r0
	bgt _08045894
	b _08045DE0
_08045894:
	subs r4, #0x51
	adds r1, r2, r4
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _0804590C @ =gMPlayInfo_SE1
	ldr r1, _08045910 @ =gUnknown_086A2EE4
	str r3, [sp, #4]
	bl MPlayStart
	mov r0, r8
	ldr r2, [r0]
	adds r4, r2, r4
	adds r4, r4, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r3, [sp, #4]
	cmp r0, #2
	bgt _08045920
	mov r1, sb
	adds r0, r2, r1
	adds r0, r0, r3
	movs r1, #0xcc
	lsls r1, r1, #7
	str r1, [r0]
	adds r0, r2, r7
	add r0, sl
	ldr r1, _08045914 @ =0x0000FED4
	strh r1, [r0]
	ldr r3, _08045918 @ =0x00000553
	adds r0, r2, r3
	adds r0, r0, r5
	movs r1, #0xd
	strb r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r0, r0, r6
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0804591C @ =0x000003A3
	adds r0, r0, r1
	adds r0, r0, r6
	movs r1, #8
	strb r1, [r0]
	ldr r1, [r4]
	lsls r0, r6, #1
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r1, r1, r0
	b _08045A5C
	.align 2, 0
_08045904: .4byte 0x00000584
_08045908: .4byte 0x000065FF
_0804590C: .4byte gMPlayInfo_SE1
_08045910: .4byte gUnknown_086A2EE4
_08045914: .4byte 0x0000FED4
_08045918: .4byte 0x00000553
_0804591C: .4byte 0x000003A3
_08045920:
	adds r2, r2, r7
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	movs r1, #0x1e
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r2, r3
	strh r1, [r0]
	add r2, sl
	ldr r0, _08045988 @ =0x0000FE70
	strh r0, [r2]
	movs r0, #0
	strb r0, [r4]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _0804598C @ =0x00000536
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #4
	strb r1, [r0]
	mov r3, r8
	ldr r0, [r3]
	movs r4, #0xe8
	lsls r4, r4, #2
	adds r0, r0, r4
	adds r0, r0, r6
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r3]
	ldr r5, _08045990 @ =0x000003A3
	adds r0, r0, r5
	adds r0, r0, r6
	movs r1, #0xb
	strb r1, [r0]
	ldr r2, [r3]
	lsls r1, r6, #1
	movs r3, #0xec
	lsls r3, r3, #2
	adds r0, r2, r3
	adds r0, r0, r1
	movs r4, #0
	strh r4, [r0]
	ldr r5, _08045994 @ =0x00000542
	adds r1, r2, r5
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, _08045998 @ =0x0000052C
	adds r2, r2, r0
	b _08045AE2
	.align 2, 0
_08045988: .4byte 0x0000FE70
_0804598C: .4byte 0x00000536
_08045990: .4byte 0x000003A3
_08045994: .4byte 0x00000542
_08045998: .4byte 0x0000052C
_0804599C:
	lsls r0, r5, #0x10
	asrs r3, r0, #0x10
	mov sb, r0
	cmp r3, #0
	bne _080459C0
	ldr r1, _080459B8 @ =0x0000132C
	adds r0, r2, r1
	ldr r2, [r0]
	ldr r1, [r2, #0x34]
	ldr r0, _080459BC @ =0x000055FF
	cmp r1, r0
	ble _080459D4
	strh r3, [r2, #0x30]
	b _080459D4
	.align 2, 0
_080459B8: .4byte 0x0000132C
_080459BC: .4byte 0x000055FF
_080459C0:
	ldr r3, _08045A64 @ =0x0000132C
	adds r0, r2, r3
	ldr r2, [r0]
	ldr r1, [r2, #0x34]
	movs r0, #0x9c
	lsls r0, r0, #8
	cmp r1, r0
	bgt _080459D4
	movs r0, #0
	strh r0, [r2, #0x30]
_080459D4:
	mov r4, r8
	ldr r3, [r4]
	ldr r7, _08045A64 @ =0x0000132C
	adds r2, r3, r7
	ldr r1, [r2]
	ldrh r0, [r1, #0x32]
	adds r0, #3
	movs r5, #0
	mov sl, r5
	strh r0, [r1, #0x32]
	ldr r0, [r2]
	ldr r1, [r0, #0x38]
	ldr r0, _08045A68 @ =0x000064FF
	cmp r1, r0
	bgt _080459F4
	b _08045DE0
_080459F4:
	ldr r0, [sp]
	asrs r5, r0, #0x10
	ldr r4, _08045A6C @ =0x00000533
	adds r1, r3, r4
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08045A70 @ =gMPlayInfo_SE1
	ldr r1, _08045A74 @ =gUnknown_086A2EE4
	bl MPlayStart
	movs r0, #7
	bl sub_11B0
	mov r1, r8
	ldr r3, [r1]
	adds r4, r3, r4
	adds r6, r4, r5
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #2
	bgt _08045A80
	adds r2, r3, r7
	ldr r1, [r2]
	movs r0, #0xca
	lsls r0, r0, #7
	str r0, [r1, #0x38]
	ldr r1, [r2]
	ldr r0, _08045A78 @ =0x0000FFA6
	strh r0, [r1, #0x32]
	mov r4, sb
	asrs r2, r4, #0x10
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	ldr r3, _08045A7C @ =0x000003A3
	adds r0, r0, r3
	adds r0, r0, r2
	movs r1, #8
	strb r1, [r0]
	mov r4, r8
	ldr r1, [r4]
	lsls r2, r2, #1
	adds r5, #0x10
	adds r1, r1, r5
	adds r1, r1, r2
_08045A5C:
	movs r0, #0xc
	strh r0, [r1]
	b _08045DE0
	.align 2, 0
_08045A64: .4byte 0x0000132C
_08045A68: .4byte 0x000064FF
_08045A6C: .4byte 0x00000533
_08045A70: .4byte gMPlayInfo_SE1
_08045A74: .4byte gUnknown_086A2EE4
_08045A78: .4byte 0x0000FFA6
_08045A7C: .4byte 0x000003A3
_08045A80:
	adds r2, r3, r7
	ldr r4, [r2]
	mov r0, sb
	asrs r3, r0, #0x10
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #3
	movs r0, #0x1c
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	ldr r1, [r2]
	ldr r0, _08045AEC @ =0x0000FF88
	strh r0, [r1, #0x32]
	mov r1, sl
	strb r1, [r6]
	mov r2, r8
	ldr r0, [r2]
	ldr r4, _08045AF0 @ =0x00000536
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r2]
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08045AF4 @ =0x000003A3
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0xb
	strb r1, [r0]
	ldr r2, [r2]
	lsls r3, r3, #1
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r2, r4
	adds r0, r0, r3
	movs r5, #0
	strh r5, [r0]
	ldr r0, _08045AF8 @ =0x00000542
	adds r1, r2, r0
	movs r0, #0x6a
	strh r0, [r1]
	ldr r1, _08045AFC @ =0x0000052D
	adds r2, r2, r1
_08045AE2:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _08045DE0
	.align 2, 0
_08045AEC: .4byte 0x0000FF88
_08045AF0: .4byte 0x00000536
_08045AF4: .4byte 0x000003A3
_08045AF8: .4byte 0x00000542
_08045AFC: .4byte 0x0000052D
_08045B00:
	mov r2, r8
	ldr r3, [r2]
	ldr r4, [sp]
	asrs r2, r4, #0x10
	movs r5, #0xa6
	lsls r5, r5, #3
	adds r0, r3, r5
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r2, #1
	bgt _08045B90
	lsls r0, r2, #2
	adds r4, r3, r0
	ldr r0, _08045B4C @ =0x0000057A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0xc
	movs r6, #0
	strh r0, [r1]
	cmp r5, #0
	bne _08045B54
	lsls r1, r2, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08045B50 @ =0x000077FF
	cmp r1, r0
	ble _08045B70
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08045B6E
	.align 2, 0
_08045B4C: .4byte 0x0000057A
_08045B50: .4byte 0x000077FF
_08045B54:
	lsls r1, r2, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r0, r3, r5
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	bgt _08045B70
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
_08045B6E:
	strh r6, [r0]
_08045B70:
	mov r3, r8
	ldr r2, [r3]
	ldr r5, [sp]
	asrs r4, r5, #0x10
	lsls r1, r4, #3
	ldr r3, _08045B88 @ =0x00000584
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08045B8C @ =0x000083FF
	b _08045CD0
	.align 2, 0
_08045B88: .4byte 0x00000584
_08045B8C: .4byte 0x000083FF
_08045B90:
	ldr r1, _08045BB4 @ =0x0000132C
	adds r2, r3, r1
	ldr r0, [r2]
	ldrh r1, [r0, #0x32]
	adds r1, #3
	movs r3, #0
	strh r1, [r0, #0x32]
	lsls r0, r5, #0x10
	mov sb, r0
	cmp r0, #0
	bne _08045BBC
	ldr r2, [r2]
	ldr r1, [r2, #0x34]
	ldr r0, _08045BB8 @ =0x000077FF
	cmp r1, r0
	ble _08045BCA
	b _08045BC8
	.align 2, 0
_08045BB4: .4byte 0x0000132C
_08045BB8: .4byte 0x000077FF
_08045BBC:
	ldr r2, [r2]
	ldr r1, [r2, #0x34]
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	bgt _08045BCA
_08045BC8:
	strh r3, [r2, #0x30]
_08045BCA:
	mov r2, r8
	ldr r3, [r2]
	ldr r7, _08045C34 @ =0x0000132C
	adds r0, r3, r7
	ldr r0, [r0]
	ldr r1, [r0, #0x38]
	ldr r0, _08045C38 @ =0x000083FF
	cmp r1, r0
	bgt _08045BDE
	b _08045DE0
_08045BDE:
	ldr r4, [sp]
	asrs r5, r4, #0x10
	ldr r2, _08045C3C @ =0x00000533
	adds r1, r3, r2
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	mov sl, r3
	strb r0, [r1]
	mov r0, r8
	ldr r4, [r0]
	adds r2, r4, r2
	adds r6, r2, r5
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #1
	bgt _08045C40
	adds r4, r4, r7
	ldr r1, [r4]
	movs r0, #0x84
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r5, [r4]
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	rsbs r0, r0, #0
	movs r1, #3
	bl __divsi3
	strh r0, [r5, #0x32]
	ldr r0, [r4]
	mov r2, sl
	strh r2, [r0, #0x30]
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #1
	beq _08045C2C
	b _08045DE0
_08045C2C:
	movs r0, #7
	bl sub_11B0
	b _08045DE0
	.align 2, 0
_08045C34: .4byte 0x0000132C
_08045C38: .4byte 0x000083FF
_08045C3C: .4byte 0x00000533
_08045C40:
	adds r1, r4, r7
	ldr r0, [r1]
	movs r3, #0
	mov r2, sl
	strh r2, [r0, #0x32]
	b _08045DC0
_08045C4C:
	mov r5, r8
	ldr r3, [r5]
	ldr r0, [sp]
	asrs r2, r0, #0x10
	movs r1, #0xa6
	lsls r1, r1, #3
	adds r0, r3, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r2, #1
	bgt _08045D20
	lsls r0, r2, #2
	adds r4, r3, r0
	ldr r0, _08045C98 @ =0x0000057A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0xc
	movs r6, #0
	strh r0, [r1]
	cmp r5, #0
	bne _08045CA0
	lsls r1, r2, #3
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r0, r3, r2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08045C9C @ =0x000077FF
	cmp r1, r0
	ble _08045CBC
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08045CBA
	.align 2, 0
_08045C98: .4byte 0x0000057A
_08045C9C: .4byte 0x000077FF
_08045CA0:
	lsls r1, r2, #3
	movs r5, #0xb0
	lsls r5, r5, #3
	adds r0, r3, r5
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	bgt _08045CBC
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
_08045CBA:
	strh r6, [r0]
_08045CBC:
	mov r3, r8
	ldr r2, [r3]
	ldr r5, [sp]
	asrs r4, r5, #0x10
	lsls r1, r4, #3
	ldr r3, _08045D08 @ =0x00000584
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _08045D0C @ =0x00008DFF
_08045CD0:
	cmp r1, r0
	bgt _08045CD6
	b _08045DE0
_08045CD6:
	ldr r5, _08045D10 @ =0x00000536
	adds r0, r2, r5
	adds r0, r0, r4
	movs r3, #0
	strb r3, [r0]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08045D14 @ =0x00000553
	adds r0, r0, r2
	adds r0, r0, r4
	movs r1, #0xe
	strb r1, [r0]
	mov r5, r8
	ldr r1, [r5]
	lsls r2, r4, #1
	ldr r5, _08045D18 @ =0x00000562
	adds r0, r1, r5
	adds r0, r0, r2
	movs r2, #0
	strh r3, [r0]
	ldr r0, _08045D1C @ =0x0000054B
	adds r1, r1, r0
	adds r1, r1, r4
	strb r2, [r1]
	b _08045DE0
	.align 2, 0
_08045D08: .4byte 0x00000584
_08045D0C: .4byte 0x00008DFF
_08045D10: .4byte 0x00000536
_08045D14: .4byte 0x00000553
_08045D18: .4byte 0x00000562
_08045D1C: .4byte 0x0000054B
_08045D20:
	ldr r1, _08045D44 @ =0x0000132C
	adds r2, r3, r1
	ldr r0, [r2]
	ldrh r1, [r0, #0x32]
	adds r1, #3
	movs r3, #0
	strh r1, [r0, #0x32]
	lsls r0, r5, #0x10
	mov sb, r0
	cmp r0, #0
	bne _08045D4C
	ldr r2, [r2]
	ldr r1, [r2, #0x34]
	ldr r0, _08045D48 @ =0x000077FF
	cmp r1, r0
	ble _08045D5A
	b _08045D58
	.align 2, 0
_08045D44: .4byte 0x0000132C
_08045D48: .4byte 0x000077FF
_08045D4C:
	ldr r2, [r2]
	ldr r1, [r2, #0x34]
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	bgt _08045D5A
_08045D58:
	strh r3, [r2, #0x30]
_08045D5A:
	mov r4, r8
	ldr r3, [r4]
	ldr r6, _08045DAC @ =0x0000132C
	adds r0, r3, r6
	ldr r0, [r0]
	ldr r1, [r0, #0x38]
	ldr r0, _08045DB0 @ =0x00008DFF
	cmp r1, r0
	ble _08045DE0
	ldr r2, [sp]
	asrs r5, r2, #0x10
	ldr r2, _08045DB4 @ =0x00000533
	adds r1, r3, r2
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r7, #0
	strb r0, [r1]
	ldr r4, [r4]
	adds r2, r4, r2
	adds r2, r2, r5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #1
	bgt _08045DB8
	adds r4, r4, r6
	ldr r1, [r4]
	movs r0, #0x8e
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r5, [r4]
	movs r3, #0x32
	ldrsh r0, [r5, r3]
	rsbs r0, r0, #0
	movs r1, #3
	bl __divsi3
	strh r0, [r5, #0x32]
	ldr r0, [r4]
	strh r7, [r0, #0x30]
	b _08045DE0
	.align 2, 0
_08045DAC: .4byte 0x0000132C
_08045DB0: .4byte 0x00008DFF
_08045DB4: .4byte 0x00000533
_08045DB8:
	adds r1, r4, r6
	ldr r0, [r1]
	movs r3, #0
	strh r7, [r0, #0x32]
_08045DC0:
	ldr r2, [r1]
	mov r1, sb
	asrs r0, r1, #0x10
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r0, #5
	subs r0, r0, r1
	strh r0, [r2, #0x30]
	strb r3, [r4, #0x1f]
	mov r2, r8
	ldr r0, [r2]
	ldr r4, _08045E04 @ =0x00000536
	adds r0, r0, r4
	adds r0, r0, r5
	strb r3, [r0]
_08045DE0:
	ldr r5, [sp]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r5, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _08045DF4
	bl _080455DE
_08045DF4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045E04: .4byte 0x00000536

	thumb_func_start sub_45E08
sub_45E08: @ 0x08045E08
	push {r4, r5, r6, r7, lr}
	ldr r4, _08045E70 @ =gUnknown_086AEED6
	ldr r0, _08045E74 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x60
	bl __umodsi3
	movs r1, #0x18
	bl __udivsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0x80
	lsls r2, r2, #0x11
	ldr r1, _08045E78 @ =gUnknown_03006C00
	mov ip, r1
	ldr r7, _08045E7C @ =0xFFFFF000
	add r7, ip
	ldr r6, _08045E80 @ =gUnknown_0837A4E8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r3, r0, #2
	ldr r5, _08045E84 @ =0x000003FF
	movs r4, #0x80
	lsls r4, r4, #4
_08045E3A:
	asrs r2, r2, #0x10
	adds r1, r2, r4
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	asrs r0, r2, #0x10
	cmp r0, r5
	ble _08045E3A
	ldr r1, _08045E88 @ =0x040000D4
	mov r0, ip
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08045E8C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045E70: .4byte gUnknown_086AEED6
_08045E74: .4byte gMain
_08045E78: .4byte gUnknown_03006C00
_08045E7C: .4byte 0xFFFFF000
_08045E80: .4byte gUnknown_0837A4E8
_08045E84: .4byte 0x000003FF
_08045E88: .4byte 0x040000D4
_08045E8C: .4byte 0x80000400

	thumb_func_start sub_45E90
sub_45E90: @ 0x08045E90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	ldr r0, _08045ED0 @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r1, #0x13
	ldrsb r1, [r4, r1]
	cmp r1, #3
	ble _08045EDC
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x7e
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08045F12
	subs r0, r3, #6
	strh r0, [r2]
	ldr r1, _08045ED4 @ =gMain
	rsbs r0, r0, #0
	adds r0, #4
	ldr r2, _08045ED8 @ =0x000002EE
	adds r1, r1, r2
	strh r0, [r1]
	b _08045F12
	.align 2, 0
_08045ED0: .4byte gCurrentPinballGame
_08045ED4: .4byte gMain
_08045ED8: .4byte 0x000002EE
_08045EDC:
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _08045EFA
	adds r0, r2, #6
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _08045EFA
	movs r0, #0
	strh r0, [r1]
_08045EFA:
	ldr r0, _08045F84 @ =gMain
	ldr r2, _08045F88 @ =gCurrentPinballGame
	ldr r1, [r2]
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r1, [r1]
	rsbs r1, r1, #0
	adds r1, #4
	ldr r2, _08045F8C @ =0x000002EE
	adds r0, r0, r2
	strh r1, [r0]
_08045F12:
	ldr r3, _08045F88 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _08045F2E
	ldr r1, _08045F84 @ =gMain
	ldrh r0, [r1, #0x38]
	ldr r0, _08045F90 @ =0x00001C42
	strh r0, [r1, #0x38]
	ldrh r0, [r1, #0x3a]
	ldr r0, _08045F94 @ =0x00000C04
	strh r0, [r1, #0x3a]
_08045F2E:
	ldr r0, _08045F88 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _08045F3C
	ldrh r0, [r1, #0x18]
_08045F3C:
	ldr r0, _08045F88 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r1, _08045F98 @ =0x0000053A
	adds r3, r2, r1
	ldrh r0, [r3]
	subs r0, #0x65
	lsls r0, r0, #0x10
	movs r1, #0xae
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _08045FAA
	ldr r0, _08045F9C @ =0x0000052E
	adds r4, r2, r0
	ldr r1, _08045FA0 @ =0x0000052C
	adds r0, r2, r1
	ldrb r5, [r4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _08045FA4
	ldrh r0, [r3]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08045FAA
	adds r0, r5, #1
	strb r0, [r4]
	movs r0, SE_UNKNOWN_0x91
	bl m4aSongNumStart
	b _08045FAA
	.align 2, 0
_08045F84: .4byte gMain
_08045F88: .4byte gCurrentPinballGame
_08045F8C: .4byte 0x000002EE
_08045F90: .4byte 0x00001C42
_08045F94: .4byte 0x00000C04
_08045F98: .4byte 0x0000053A
_08045F9C: .4byte 0x0000052E
_08045FA0: .4byte 0x0000052C
_08045FA4:
	movs r0, #0xf5
	lsls r0, r0, #1
	strh r0, [r3]
_08045FAA:
	ldr r0, _08045FF8 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldr r0, _08045FFC @ =0x0000053A
	adds r3, r2, r0
	ldr r1, _08046000 @ =0xFFFFFE0B
	adds r0, r1, #0
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	movs r1, #0x95
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _08046012
	ldr r0, _08046004 @ =0x0000052F
	adds r4, r2, r0
	ldr r1, _08046008 @ =0x0000052D
	adds r0, r2, r1
	ldrb r5, [r4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _0804600C
	ldrh r0, [r3]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046012
	adds r0, r5, #1
	strb r0, [r4]
	movs r0, SE_UNKNOWN_0x91
	bl m4aSongNumStart
	b _08046012
	.align 2, 0
_08045FF8: .4byte gCurrentPinballGame
_08045FFC: .4byte 0x0000053A
_08046000: .4byte 0xFFFFFE0B
_08046004: .4byte 0x0000052F
_08046008: .4byte 0x0000052D
_0804600C:
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r3]
_08046012:
	ldr r2, _080463D0 @ =gCurrentPinballGame
	ldr r4, [r2]
	ldr r3, _080463D4 @ =0x0000053A
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r0, _080463D8 @ =0x0000031F
	cmp r1, r0
	bhi _0804602C
	ldrh r0, [r4, #0x18]
	cmp r0, #0xa0
	bls _0804602C
	movs r0, #0xa0
	strh r0, [r4, #0x18]
_0804602C:
	ldr r1, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080463D4 @ =0x0000053A
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r6, _080463DC @ =gMain+0x800 @gMain.spriteGroups[7]
	ldrh r0, [r6]
	cmp r0, #0
	bne _08046044
	b _0804679A
_08046044:
	movs r0, #0x78
	strh r0, [r6, #2]
	ldr r3, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0x3c
	strh r0, [r6, #4]
	movs r1, #0
	add r2, sp, #0x18
	mov r8, r2
	movs r3, #0xb8
	adds r3, r3, r6
	mov sb, r3
	ldr r7, _080463E0 @ =gOamBuffer
	ldr r0, _080463E4 @ =0xFFFFFE00
	mov ip, r0
_0804606A:
	lsls r4, r1, #0x10
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
	ldr r2, _080463E8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
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
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x15
	ble _0804606A
	ldr r3, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r1, _080463EC @ =0x0000052E
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _080463F0 @ =0x004C4B40
	adds r7, r1, #0
	muls r7, r0, r7
	mov r5, sp
	ldr r4, _080463F4 @ =0x00989680
	adds r0, r7, #0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080463F8 @ =0x000F4240
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #2]
	mov r0, sp
	movs r6, #0xa
	strh r6, [r0, #4]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080463FC @ =0x000186A0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #6]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _08046400 @ =0x00002710
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #8]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #0xa]
	mov r0, sp
	strh r6, [r0, #0xc]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0xe]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0x64
	bl __modsi3
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x10]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #0x12]
	movs r1, #0
_0804615C:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #1
	mov r2, sp
	adds r5, r2, r0
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046186
	movs r0, #0x14
	strh r0, [r5]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0804615C
_08046186:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r5, r2, #0
	adds r0, r0, r5
	mov r3, r8
	strh r0, [r3]
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r3, #2]
	mov r0, sp
	movs r2, #4
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r3, #4]
	mov r0, sp
	movs r3, #6
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r1, r8
	strh r0, [r1, #6]
	mov r0, sp
	movs r2, #8
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r1, #8]
	mov r0, sp
	movs r3, #0xa
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r1, #0xa]
	mov r0, sp
	movs r1, #0xc
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r2, r8
	strh r0, [r2, #0xc]
	mov r0, sp
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r2, #0xe]
	mov r0, sp
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r2, #0x10]
	mov r0, sp
	movs r2, #0x12
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r3, r8
	strh r0, [r3, #0x12]
	ldr r1, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _080463EC @ =0x0000052E
	adds r0, r0, r2
	movs r7, #0
	ldrsb r7, [r0, r7]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #2]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _08046240
	mov r1, sp
	movs r0, #0x14
	strh r0, [r1]
_08046240:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r2, r8
	strh r0, [r2, #0x14]
	mov r0, sp
	movs r3, #2
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r2, #0x16]
	mov r6, sb
	movs r0, #0x78
	strh r0, [r6, #2]
	ldr r1, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0x3c
	strh r0, [r6, #4]
	movs r1, #0
	ldr r7, _080463E0 @ =gOamBuffer
	ldr r3, _08046404 @ =0x000003FF
	mov sl, r3
	mov ip, r8
	ldr r0, _08046408 @ =0xFFFFFC00
	mov sb, r0
_0804627E:
	lsls r4, r1, #0x10
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
	ldr r2, _080463E8 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _080463E4 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r5, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	lsls r0, r4, #1
	add r0, ip
	ldrh r0, [r0]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r3, #4]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0xb
	ble _0804627E
	ldr r1, _080463D0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0804640C @ =0x0000052F
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r7, r0, #6
	mov r5, sp
	ldr r4, _080463F4 @ =0x00989680
	adds r0, r7, #0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080463F8 @ =0x000F4240
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #2]
	mov r0, sp
	movs r6, #0xa
	strh r6, [r0, #4]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080463FC @ =0x000186A0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #6]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _08046400 @ =0x00002710
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #8]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #0xa]
	mov r0, sp
	strh r6, [r0, #0xc]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0xe]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0x64
	bl __modsi3
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x10]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #0x12]
	movs r1, #0
_08046392:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #1
	mov r3, sp
	adds r5, r3, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080463BC
	movs r0, #0x14
	strh r0, [r5]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _08046392
_080463BC:
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r5, r3, #0
	adds r0, r0, r5
	b _08046410
	.align 2, 0
_080463D0: .4byte gCurrentPinballGame
_080463D4: .4byte 0x0000053A
_080463D8: .4byte 0x0000031F
_080463DC: .4byte gMain+0x800 @gMain.spriteGroups[7]
_080463E0: .4byte gOamBuffer
_080463E4: .4byte 0xFFFFFE00
_080463E8: .4byte 0x000001FF
_080463EC: .4byte 0x0000052E
_080463F0: .4byte 0x004C4B40
_080463F4: .4byte 0x00989680
_080463F8: .4byte 0x000F4240
_080463FC: .4byte 0x000186A0
_08046400: .4byte 0x00002710
_08046404: .4byte 0x000003FF
_08046408: .4byte 0xFFFFFC00
_0804640C: .4byte 0x0000052F
_08046410:
	mov r1, r8
	strh r0, [r1]
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r1, #2]
	mov r0, sp
	movs r3, #4
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r1, #4]
	mov r0, sp
	movs r1, #6
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r2, r8
	strh r0, [r2, #6]
	mov r0, sp
	movs r3, #8
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r2, #8]
	mov r0, sp
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r2, #0xa]
	mov r0, sp
	movs r2, #0xc
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r3, r8
	strh r0, [r3, #0xc]
	mov r0, sp
	movs r1, #0xe
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r3, #0xe]
	mov r0, sp
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r3, #0x10]
	mov r0, sp
	movs r3, #0x12
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r1, r8
	strh r0, [r1, #0x12]
	ldr r2, _080467AC @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _080467B0 @ =0x0000052F
	adds r0, r0, r3
	movs r7, #0
	ldrsb r7, [r0, r7]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #2]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080464BA
	mov r1, sp
	movs r0, #0x14
	strh r0, [r1]
_080464BA:
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r3, r8
	strh r0, [r3, #0x14]
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r0, [r3, #0x16]
	ldr r6, _080467B4 @ =gMain+0x970 @gMain.spriteGroups[9]
	movs r0, #0x78
	strh r0, [r6, #2]
	ldr r2, _080467AC @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #0x3c
	strh r0, [r6, #4]
	movs r1, #0
	ldr r7, _080467B8 @ =gOamBuffer
	ldr r0, _080467BC @ =0x000003FF
	mov sl, r0
	mov ip, r8
	ldr r2, _080467C0 @ =0xFFFFFC00
	mov sb, r2
_080464F8:
	lsls r4, r1, #0x10
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
	ldr r2, _080467C4 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _080467C8 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r5, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	lsls r0, r4, #1
	add r0, ip
	ldrh r0, [r0]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r3, #4]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0xb
	ble _080464F8
	ldr r0, _080467AC @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r1, _080467CC @ =0x0000052E
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _080467D0 @ =0x004C4B40
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r2, _080467B0 @ =0x0000052F
	adds r0, r3, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #6
	adds r7, r4, r0
	ldr r0, _080467D4 @ =0x00000544
	adds r3, r3, r0
	str r7, [r3]
	mov r5, sp
	ldr r4, _080467D8 @ =0x05F5E100
	adds r0, r7, #0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080467DC @ =0x00989680
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #2]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080467E0 @ =0x000F4240
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #4]
	mov r0, sp
	movs r6, #0xa
	strh r6, [r0, #6]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080467E4 @ =0x000186A0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #8]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	ldr r4, _080467E8 @ =0x00002710
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #0xa]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r5, #0xc]
	mov r0, sp
	strh r6, [r0, #0xe]
	mov r5, sp
	adds r0, r7, #0
	adds r1, r4, #0
	bl __modsi3
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0x10]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0x64
	bl __modsi3
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x12]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	strh r0, [r4, #0x14]
	movs r1, #0
_08046636:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #1
	mov r1, sp
	adds r5, r1, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046660
	movs r0, #0x14
	strh r0, [r5]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08046636
_08046660:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r0, [r3, #2]
	mov r0, sp
	movs r3, #4
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #6
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r0, [r2, #6]
	mov r0, sp
	movs r2, #8
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r3, r8
	strh r0, [r3, #8]
	mov r0, sp
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r0, [r3, #0xa]
	mov r0, sp
	movs r3, #0xc
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #0xc]
	mov r0, sp
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r0, [r2, #0xe]
	mov r0, sp
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r3, r8
	strh r0, [r3, #0x10]
	mov r0, sp
	movs r2, #0x12
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r0, [r3, #0x12]
	mov r0, sp
	movs r3, #0x14
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #0x14]
	ldr r3, _080467AC @ =gCurrentPinballGame
	ldr r0, [r3]
	ldr r2, _080467EC @ =0x000005F6
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r0, #1
	mov r0, sp
	strh r7, [r0]
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x16]
	ldr r6, _080467F0 @ =gMain+0xA28 @gMain.spriteGroups[10]
	movs r0, #0x78
	strh r0, [r6, #2]
	ldr r2, _080467AC @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xe5
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #0x3c
	strh r0, [r6, #4]
	movs r1, #0
	ldr r7, _080467B8 @ =gOamBuffer
	ldr r0, _080467C8 @ =0xFFFFFE00
	mov ip, r0
	ldr r2, _080467BC @ =0x000003FF
	mov sl, r2
	ldr r3, _080467C0 @ =0xFFFFFC00
	mov sb, r3
_0804673C:
	lsls r4, r1, #0x10
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
	ldr r2, _080467C4 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r5, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	lsls r0, r4, #1
	add r0, r8
	ldrh r0, [r0]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r3, #4]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0xb
	ble _0804673C
_0804679A:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080467AC: .4byte gCurrentPinballGame
_080467B0: .4byte 0x0000052F
_080467B4: .4byte gMain+0x970 @gMain.spriteGroups[9]
_080467B8: .4byte gOamBuffer
_080467BC: .4byte 0x000003FF
_080467C0: .4byte 0xFFFFFC00
_080467C4: .4byte 0x000001FF
_080467C8: .4byte 0xFFFFFE00
_080467CC: .4byte 0x0000052E
_080467D0: .4byte 0x004C4B40
_080467D4: .4byte 0x00000544
_080467D8: .4byte 0x05F5E100
_080467DC: .4byte 0x00989680
_080467E0: .4byte 0x000F4240
_080467E4: .4byte 0x000186A0
_080467E8: .4byte 0x00002710
_080467EC: .4byte 0x000005F6
_080467F0: .4byte gMain+0xA28 @gMain.spriteGroups[10]

	thumb_func_start sub_467F4
sub_467F4: @ 0x080467F4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r0, _08046824 @ =gUnknown_02031520
	ldr r3, _08046828 @ =gUnknown_086AFD70
	ldr r4, _0804682C @ =gMain
	ldrb r2, [r4, #4]
	movs r1, #0x54
	muls r1, r2, r1
	adds r1, r1, r3
	adds r0, #0x14
	movs r2, #0x54
	bl memcpy
	ldrb r0, [r4, #4]
	cmp r0, #7
	bls _0804681A
	b _08046F66
_0804681A:
	lsls r0, r0, #2
	ldr r1, _08046830 @ =_08046834
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08046824: .4byte gUnknown_02031520
_08046828: .4byte gUnknown_086AFD70
_0804682C: .4byte gMain
_08046830: .4byte _08046834
_08046834: @ jump table
	.4byte _08046854 @ case 0
	.4byte _0804698C @ case 1
	.4byte _08046AC0 @ case 2
	.4byte _08046B9C @ case 3
	.4byte _08046C78 @ case 4
	.4byte _08046D40 @ case 5
	.4byte _08046E08 @ case 6
	.4byte _08046EE8 @ case 7
_08046854:
	ldr r4, _08046914 @ =0x040000D4
	ldr r0, _08046918 @ =gUnknown_081BFEE4
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0804691C @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046920 @ =gUnknown_08265C10
	str r0, [r4]
	ldr r0, _08046924 @ =0x06008000
	mov r8, r0
	str r0, [r4, #4]
	ldr r1, _08046928 @ =0x80004000
	mov sb, r1
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0804692C @ =gUnknown_0826DC10
	str r0, [r4]
	ldr r0, _08046930 @ =0x06003000
	str r0, [r4, #4]
	ldr r6, _08046934 @ =0x80000800
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046938 @ =gUnknown_0824C1E4
	ldr r5, _0804693C @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046940 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046944 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046948 @ =gUnknown_0824DD60
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, _0804694C @ =gUnknown_08250934
	ldr r1, _08046950 @ =gUnknown_020030A0
	bl LZ77UnCompWram
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	str r0, [r4]
	ldr r0, _08046954 @ =0x0600B400
	str r0, [r4, #4]
	ldr r0, _08046958 @ =0x80001200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #0xc0
	lsls r0, r0, #6
	adds r5, r5, r0
	str r5, [r4]
	mov r1, r8
	str r1, [r4, #4]
	ldr r0, _0804695C @ =0x80001A00
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046960 @ =gUnknown_081C08E4
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046964 @ =gUnknown_0822E424
	str r0, [r4]
	ldr r0, _08046968 @ =0x06001000
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0804696C @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046970 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046974 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046978 @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _0804697C @ =0x06006C00
	str r0, [r4, #4]
	ldr r0, _08046980 @ =0x80000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046984 @ =gUnknown_0845A48C
	str r0, [r4]
	ldr r0, _08046988 @ =0x06010000
	str r0, [r4, #4]
	mov r0, sb
	str r0, [r4, #8]
	b _08046F64
	.align 2, 0
_08046914: .4byte 0x040000D4
_08046918: .4byte gUnknown_081BFEE4
_0804691C: .4byte 0x80000100
_08046920: .4byte gUnknown_08265C10
_08046924: .4byte 0x06008000
_08046928: .4byte 0x80004000
_0804692C: .4byte gUnknown_0826DC10
_08046930: .4byte 0x06003000
_08046934: .4byte 0x80000800
_08046938: .4byte gUnknown_0824C1E4
_0804693C: .4byte gUnknown_0200FBB0
_08046940: .4byte 0x06004000
_08046944: .4byte 0x80002000
_08046948: .4byte gUnknown_0824DD60
_0804694C: .4byte gUnknown_08250934
_08046950: .4byte gUnknown_020030A0
_08046954: .4byte 0x0600B400
_08046958: .4byte 0x80001200
_0804695C: .4byte 0x80001A00
_08046960: .4byte gUnknown_081C08E4
_08046964: .4byte gUnknown_0822E424
_08046968: .4byte 0x06001000
_0804696C: .4byte gUnknown_083A8ACC
_08046970: .4byte 0x06006800
_08046974: .4byte 0x80000200
_08046978: .4byte gUnknown_083A826C
_0804697C: .4byte 0x06006C00
_08046980: .4byte 0x80000400
_08046984: .4byte gUnknown_0845A48C
_08046988: .4byte 0x06010000
_0804698C:
	ldr r4, _08046A48 @ =0x040000D4
	ldr r0, _08046A4C @ =gUnknown_0826EC10
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046A50 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A54 @ =gUnknown_082E4EE0
	str r0, [r4]
	ldr r1, _08046A58 @ =0x06008000
	mov r8, r1
	str r1, [r4, #4]
	ldr r0, _08046A5C @ =0x80004000
	mov sb, r0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A60 @ =gUnknown_082ECEE0
	str r0, [r4]
	ldr r0, _08046A64 @ =0x06003000
	str r0, [r4, #4]
	ldr r6, _08046A68 @ =0x80000800
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A6C @ =gUnknown_082D34D0
	ldr r5, _08046A70 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046A74 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046A78 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A7C @ =gUnknown_082D523C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, _08046A80 @ =gUnknown_082D8998
	ldr r1, _08046A84 @ =gUnknown_020030A0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046A88 @ =0x0600A800
	str r0, [r4, #4]
	ldr r0, _08046A8C @ =0x80001800
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r5, r5, r1
	str r5, [r4]
	mov r0, r8
	str r0, [r4, #4]
	ldr r0, _08046A90 @ =0x80001400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A94 @ =gUnknown_0826EE10
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046A98 @ =gUnknown_082AE6D0
	str r0, [r4]
	ldr r0, _08046A9C @ =0x06001000
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046AA0 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046AA4 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046AA8 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046AAC @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046AB0 @ =0x06006C00
	str r0, [r4, #4]
	ldr r0, _08046AB4 @ =0x80000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046AB8 @ =gUnknown_0845F9EC
	str r0, [r4]
	ldr r0, _08046ABC @ =0x06010000
	str r0, [r4, #4]
	mov r1, sb
	str r1, [r4, #8]
	b _08046F64
	.align 2, 0
_08046A48: .4byte 0x040000D4
_08046A4C: .4byte gUnknown_0826EC10
_08046A50: .4byte 0x80000100
_08046A54: .4byte gUnknown_082E4EE0
_08046A58: .4byte 0x06008000
_08046A5C: .4byte 0x80004000
_08046A60: .4byte gUnknown_082ECEE0
_08046A64: .4byte 0x06003000
_08046A68: .4byte 0x80000800
_08046A6C: .4byte gUnknown_082D34D0
_08046A70: .4byte gUnknown_0200FBB0
_08046A74: .4byte 0x06004000
_08046A78: .4byte 0x80002000
_08046A7C: .4byte gUnknown_082D523C
_08046A80: .4byte gUnknown_082D8998
_08046A84: .4byte gUnknown_020030A0
_08046A88: .4byte 0x0600A800
_08046A8C: .4byte 0x80001800
_08046A90: .4byte 0x80001400
_08046A94: .4byte gUnknown_0826EE10
_08046A98: .4byte gUnknown_082AE6D0
_08046A9C: .4byte 0x06001000
_08046AA0: .4byte gUnknown_083A8ACC
_08046AA4: .4byte 0x06006800
_08046AA8: .4byte 0x80000200
_08046AAC: .4byte gUnknown_083A826C
_08046AB0: .4byte 0x06006C00
_08046AB4: .4byte 0x80000400
_08046AB8: .4byte gUnknown_0845F9EC
_08046ABC: .4byte 0x06010000
_08046AC0:
	ldr r4, _08046B44 @ =0x040000D4
	ldr r0, _08046B48 @ =gUnknown_082EDEE0
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046B4C @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B50 @ =gUnknown_08302700
	ldr r5, _08046B54 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046B58 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046B5C @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B60 @ =gUnknown_08303928
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046B64 @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046B68 @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B6C @ =gUnknown_082EE4C0
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046B70 @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B74 @ =gUnknown_08301700
	str r0, [r4]
	ldr r0, _08046B78 @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B7C @ =gUnknown_08301F00
	str r0, [r4]
	ldr r0, _08046B80 @ =0x06001000
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B84 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046B88 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046B8C @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B90 @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046B94 @ =0x06006C00
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046B98 @ =gUnknown_08464F4C
	b _08046F5C
	.align 2, 0
_08046B44: .4byte 0x040000D4
_08046B48: .4byte gUnknown_082EDEE0
_08046B4C: .4byte 0x80000100
_08046B50: .4byte gUnknown_08302700
_08046B54: .4byte gUnknown_0200FBB0
_08046B58: .4byte 0x06004000
_08046B5C: .4byte 0x80002000
_08046B60: .4byte gUnknown_08303928
_08046B64: .4byte 0x06008000
_08046B68: .4byte 0x80004000
_08046B6C: .4byte gUnknown_082EE4C0
_08046B70: .4byte 0x80000400
_08046B74: .4byte gUnknown_08301700
_08046B78: .4byte 0x06000800
_08046B7C: .4byte gUnknown_08301F00
_08046B80: .4byte 0x06001000
_08046B84: .4byte gUnknown_083A8ACC
_08046B88: .4byte 0x06006800
_08046B8C: .4byte 0x80000200
_08046B90: .4byte gUnknown_083A826C
_08046B94: .4byte 0x06006C00
_08046B98: .4byte gUnknown_08464F4C
_08046B9C:
	ldr r4, _08046C20 @ =0x040000D4
	ldr r0, _08046C24 @ =gUnknown_0830CBD4
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046C28 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C2C @ =gUnknown_08302700
	ldr r5, _08046C30 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046C34 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046C38 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C3C @ =gUnknown_0832A194
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046C40 @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046C44 @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C48 @ =gUnknown_08329994
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046C4C @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C50 @ =gUnknown_0830CDD4
	str r0, [r4]
	ldr r0, _08046C54 @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C58 @ =gUnknown_08327994
	str r0, [r4]
	ldr r0, _08046C5C @ =0x06001000
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C60 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046C64 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046C68 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C6C @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046C70 @ =0x06006C00
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046C74 @ =gUnknown_084675EC
	b _08046F5C
	.align 2, 0
_08046C20: .4byte 0x040000D4
_08046C24: .4byte gUnknown_0830CBD4
_08046C28: .4byte 0x80000100
_08046C2C: .4byte gUnknown_08302700
_08046C30: .4byte gUnknown_0200FBB0
_08046C34: .4byte 0x06004000
_08046C38: .4byte 0x80002000
_08046C3C: .4byte gUnknown_0832A194
_08046C40: .4byte 0x06008000
_08046C44: .4byte 0x80004000
_08046C48: .4byte gUnknown_08329994
_08046C4C: .4byte 0x80000400
_08046C50: .4byte gUnknown_0830CDD4
_08046C54: .4byte 0x06000800
_08046C58: .4byte gUnknown_08327994
_08046C5C: .4byte 0x06001000
_08046C60: .4byte gUnknown_083A8ACC
_08046C64: .4byte 0x06006800
_08046C68: .4byte 0x80000200
_08046C6C: .4byte gUnknown_083A826C
_08046C70: .4byte 0x06006C00
_08046C74: .4byte gUnknown_084675EC
_08046C78:
	ldr r4, _08046CF0 @ =0x040000D4
	ldr r0, _08046CF4 @ =gUnknown_08332E04
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046CF8 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046CFC @ =gUnknown_08302700
	ldr r5, _08046D00 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046D04 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046D08 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D0C @ =gUnknown_0833E044
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046D10 @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046D14 @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D18 @ =gUnknown_08333004
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046D1C @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D20 @ =gUnknown_0833D844
	str r0, [r4]
	ldr r0, _08046D24 @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D28 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046D2C @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046D30 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D34 @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046D38 @ =0x06006C00
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046D3C @ =gUnknown_0846A40C
	b _08046F5C
	.align 2, 0
_08046CF0: .4byte 0x040000D4
_08046CF4: .4byte gUnknown_08332E04
_08046CF8: .4byte 0x80000100
_08046CFC: .4byte gUnknown_08302700
_08046D00: .4byte gUnknown_0200FBB0
_08046D04: .4byte 0x06004000
_08046D08: .4byte 0x80002000
_08046D0C: .4byte gUnknown_0833E044
_08046D10: .4byte 0x06008000
_08046D14: .4byte 0x80004000
_08046D18: .4byte gUnknown_08333004
_08046D1C: .4byte 0x80000400
_08046D20: .4byte gUnknown_0833D844
_08046D24: .4byte 0x06000800
_08046D28: .4byte gUnknown_083A8ACC
_08046D2C: .4byte 0x06006800
_08046D30: .4byte 0x80000200
_08046D34: .4byte gUnknown_083A826C
_08046D38: .4byte 0x06006C00
_08046D3C: .4byte gUnknown_0846A40C
_08046D40:
	ldr r4, _08046DB8 @ =0x040000D4
	ldr r0, _08046DBC @ =gUnknown_08352BD8
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046DC0 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DC4 @ =gUnknown_08302700
	ldr r5, _08046DC8 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046DCC @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046DD0 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DD4 @ =gUnknown_08353DD8
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046DD8 @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046DDC @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DE0 @ =gUnknown_08352DD8
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046DE4 @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DE8 @ =gUnknown_083535D8
	str r0, [r4]
	ldr r0, _08046DEC @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DF0 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046DF4 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046DF8 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046DFC @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046E00 @ =0x06006C00
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046E04 @ =gUnknown_0846D2AC
	b _08046F5C
	.align 2, 0
_08046DB8: .4byte 0x040000D4
_08046DBC: .4byte gUnknown_08352BD8
_08046DC0: .4byte 0x80000100
_08046DC4: .4byte gUnknown_08302700
_08046DC8: .4byte gUnknown_0200FBB0
_08046DCC: .4byte 0x06004000
_08046DD0: .4byte 0x80002000
_08046DD4: .4byte gUnknown_08353DD8
_08046DD8: .4byte 0x06008000
_08046DDC: .4byte 0x80004000
_08046DE0: .4byte gUnknown_08352DD8
_08046DE4: .4byte 0x80000400
_08046DE8: .4byte gUnknown_083535D8
_08046DEC: .4byte 0x06000800
_08046DF0: .4byte gUnknown_083A8ACC
_08046DF4: .4byte 0x06006800
_08046DF8: .4byte 0x80000200
_08046DFC: .4byte gUnknown_083A826C
_08046E00: .4byte 0x06006C00
_08046E04: .4byte gUnknown_0846D2AC
_08046E08:
	ldr r4, _08046E8C @ =0x040000D4
	ldr r0, _08046E90 @ =gUnknown_08363EC8
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046E94 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046E98 @ =gUnknown_08302700
	ldr r5, _08046E9C @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046EA0 @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046EA4 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046EA8 @ =gUnknown_08370808
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046EAC @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046EB0 @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046EB4 @ =gUnknown_083640C8
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046EB8 @ =0x80000800
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046EBC @ =gUnknown_0836F808
	str r0, [r4]
	ldr r0, _08046EC0 @ =0x06001000
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046EC4 @ =gUnknown_0836E808
	str r0, [r4]
	ldr r0, _08046EC8 @ =0x06003000
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046ECC @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046ED0 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046ED4 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046ED8 @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046EDC @ =0x06006C00
	str r0, [r4, #4]
	ldr r0, _08046EE0 @ =0x80000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046EE4 @ =gUnknown_08472A6C
	b _08046F5C
	.align 2, 0
_08046E8C: .4byte 0x040000D4
_08046E90: .4byte gUnknown_08363EC8
_08046E94: .4byte 0x80000100
_08046E98: .4byte gUnknown_08302700
_08046E9C: .4byte gUnknown_0200FBB0
_08046EA0: .4byte 0x06004000
_08046EA4: .4byte 0x80002000
_08046EA8: .4byte gUnknown_08370808
_08046EAC: .4byte 0x06008000
_08046EB0: .4byte 0x80004000
_08046EB4: .4byte gUnknown_083640C8
_08046EB8: .4byte 0x80000800
_08046EBC: .4byte gUnknown_0836F808
_08046EC0: .4byte 0x06001000
_08046EC4: .4byte gUnknown_0836E808
_08046EC8: .4byte 0x06003000
_08046ECC: .4byte gUnknown_083A8ACC
_08046ED0: .4byte 0x06006800
_08046ED4: .4byte 0x80000200
_08046ED8: .4byte gUnknown_083A826C
_08046EDC: .4byte 0x06006C00
_08046EE0: .4byte 0x80000400
_08046EE4: .4byte gUnknown_08472A6C
_08046EE8:
	ldr r4, _08046F78 @ =0x040000D4
	ldr r0, _08046F7C @ =gUnknown_0837A2E8
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08046F80 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046F84 @ =gUnknown_08302700
	ldr r5, _08046F88 @ =gUnknown_0200FBB0
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046F8C @ =0x06004000
	str r0, [r4, #4]
	ldr r0, _08046F90 @ =0x80002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046F94 @ =gUnknown_0838E828
	adds r1, r5, #0
	bl LZ77UnCompWram
	str r5, [r4]
	ldr r0, _08046F98 @ =0x06008000
	str r0, [r4, #4]
	ldr r2, _08046F9C @ =0x80004000
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046FA0 @ =gUnknown_0837A4E8
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r1, _08046FA4 @ =0x80000400
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046FA8 @ =gUnknown_0838E028
	str r0, [r4]
	ldr r0, _08046FAC @ =0x06000800
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046FB0 @ =gUnknown_083A8ACC
	str r0, [r4]
	ldr r0, _08046FB4 @ =0x06006800
	str r0, [r4, #4]
	ldr r0, _08046FB8 @ =0x80000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046FBC @ =gUnknown_083A826C
	str r0, [r4]
	ldr r0, _08046FC0 @ =0x06006C00
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08046FC4 @ =gUnknown_084779EC
_08046F5C:
	str r0, [r4]
	ldr r0, _08046FC8 @ =0x06010000
	str r0, [r4, #4]
	str r2, [r4, #8]
_08046F64:
	ldr r0, [r4, #8]
_08046F66:
	ldr r1, _08046FCC @ =gUnknown_02031520
	ldr r0, _08046FD0 @ =gUnknown_0816C3E4
	str r0, [r1, #0x68]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08046F78: .4byte 0x040000D4
_08046F7C: .4byte gUnknown_0837A2E8
_08046F80: .4byte 0x80000100
_08046F84: .4byte gUnknown_08302700
_08046F88: .4byte gUnknown_0200FBB0
_08046F8C: .4byte 0x06004000
_08046F90: .4byte 0x80002000
_08046F94: .4byte gUnknown_0838E828
_08046F98: .4byte 0x06008000
_08046F9C: .4byte 0x80004000
_08046FA0: .4byte gUnknown_0837A4E8
_08046FA4: .4byte 0x80000400
_08046FA8: .4byte gUnknown_0838E028
_08046FAC: .4byte 0x06000800
_08046FB0: .4byte gUnknown_083A8ACC
_08046FB4: .4byte 0x06006800
_08046FB8: .4byte 0x80000200
_08046FBC: .4byte gUnknown_083A826C
_08046FC0: .4byte 0x06006C00
_08046FC4: .4byte gUnknown_084779EC
_08046FC8: .4byte 0x06010000
_08046FCC: .4byte gUnknown_02031520
_08046FD0: .4byte gUnknown_0816C3E4

	thumb_func_start sub_46FD4
sub_46FD4: @ 0x08046FD4
	push {r4, r5, lr}
	ldr r5, _08047024 @ =gUnknown_02031520
	ldr r4, _08047028 @ =gUnknown_086AFCB0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	ldr r3, _0804702C @ =gMain
	ldrb r1, [r3, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r2, r0
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [r5, #0x38]
	ldrb r1, [r3, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r2, r0
	adds r1, r4, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x48]
	ldrb r1, [r3, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	adds r4, #0x20
	adds r2, r2, r4
	ldr r0, [r2]
	str r0, [r5, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08047024: .4byte gUnknown_02031520
_08047028: .4byte gUnknown_086AFCB0
_0804702C: .4byte gMain

	thumb_func_start sub_47030
sub_47030: @ 0x08047030
	push {r4, r5, lr}
	ldr r0, _08047074 @ =gMain
	ldr r1, _08047078 @ =0x000002F6
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r4, r0, #3
	adds r2, r4, #0
	lsls r1, r2, #3
	ldr r0, _0804707C @ =gUnknown_086B0010
	adds r3, r1, r0
	ldr r1, _08047080 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, #0x64
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r5, r1, #0
	cmp r2, r0
	beq _080470EA
	cmp r2, r0
	ble _080470A8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0x1f
	ble _0804708C
	ldr r2, _08047084 @ =0x040000D4
	subs r0, #0x20
	lsls r0, r0, #0xa
	ldr r1, _08047088 @ =gUnknown_020030A0
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #2
	ldrsh r0, [r3, r1]
	b _080470D6
	.align 2, 0
_08047074: .4byte gMain
_08047078: .4byte 0x000002F6
_0804707C: .4byte gUnknown_086B0010
_08047080: .4byte gCurrentPinballGame
_08047084: .4byte 0x040000D4
_08047088: .4byte gUnknown_020030A0
_0804708C:
	ldr r2, _080470A0 @ =0x040000D4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #0xa
	ldr r1, _080470A4 @ =gUnknown_0200FBB0
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #2
	ldrsh r0, [r3, r1]
	b _080470D6
	.align 2, 0
_080470A0: .4byte 0x040000D4
_080470A4: .4byte gUnknown_0200FBB0
_080470A8:
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0x1f
	ble _080470C4
	ldr r2, _080470BC @ =0x040000D4
	subs r0, #0x20
	lsls r0, r0, #0xa
	ldr r1, _080470C0 @ =gUnknown_020030A0
	b _080470CE
	.align 2, 0
_080470BC: .4byte 0x040000D4
_080470C0: .4byte gUnknown_020030A0
_080470C4:
	ldr r2, _080470F0 @ =0x040000D4
	movs r1, #4
	ldrsh r0, [r3, r1]
	lsls r0, r0, #0xa
	ldr r1, _080470F4 @ =gUnknown_0200FBB0
_080470CE:
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #6
	ldrsh r0, [r3, r1]
_080470D6:
	lsls r0, r0, #0xa
	ldr r1, _080470F8 @ =0x06008000
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _080470FC @ =0x80000200
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, [r5]
	adds r0, #0x64
	strh r4, [r0]
_080470EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080470F0: .4byte 0x040000D4
_080470F4: .4byte gUnknown_0200FBB0
_080470F8: .4byte 0x06008000
_080470FC: .4byte 0x80000200

	thumb_func_start sub_47100
sub_47100: @ 0x08047100
	ldr r0, _0804710C @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0xfc
	movs r1, #0x80
	strh r1, [r0]
	bx lr
	.align 2, 0
_0804710C: .4byte gCurrentPinballGame

	thumb_func_start sub_47110
sub_47110: @ 0x08047110
	push {r4, r5, lr}
	movs r0, #0
	ldr r5, _08047148 @ =gUnknown_03005C00
	adds r4, r5, #0
	ldr r3, _0804714C @ =0x000001FF
	ldr r2, _08047150 @ =0x000007FF
_0804711C:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r2
	ble _0804711C
	ldr r1, _08047154 @ =0x040000D4
	str r5, [r1]
	ldr r0, _08047158 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _0804715C @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08047148: .4byte gUnknown_03005C00
_0804714C: .4byte 0x000001FF
_08047150: .4byte 0x000007FF
_08047154: .4byte 0x040000D4
_08047158: .4byte 0x06002000
_0804715C: .4byte 0x80000800

	thumb_func_start sub_47160
sub_47160: @ 0x08047160
	push {r4, r5, lr}
	ldr r2, _0804719C @ =gMain
	ldrh r1, [r2, #0x18]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080471B6
	ldrb r0, [r2, #2]
	cmp r0, #3
	beq _080471B6
	ldr r0, _080471A0 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080471B6
	ldrb r1, [r2, #0xf]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080471A4
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2, #0xf]
	bl sub_497BC
	b _080471B6
	.align 2, 0
_0804719C: .4byte gMain
_080471A0: .4byte gCurrentPinballGame
_080471A4:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080471B6
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0xf]
	bl sub_495A0
_080471B6:
	ldr r4, _080472B0 @ =gMain
	ldrb r1, [r4, #0xf]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08047274
	ldrh r1, [r4, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080471E4
	ldr r0, _080472B4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _080472B8 @ =0x00001104
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #1
	eors r0, r2
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0xA3
	bl m4aSongNumStart
_080471E4:
	ldrh r1, [r4, #0x18]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08047204
	ldr r0, _080472B4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _080472B8 @ =0x00001104
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #1
	eors r0, r2
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0xA3
	bl m4aSongNumStart
_08047204:
	ldrh r1, [r4, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08047244
	ldrh r1, [r4, #0x1c]
	movs r0, #0xe
	ands r0, r1
	cmp r0, #0
	bne _08047244
	ldr r0, _080472B4 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _080472B8 @ =0x00001104
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08047230
	strb r5, [r4, #0xe]
	bl sub_49850
_08047230:
	ldrb r1, [r4, #0xf]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r4, #0xf]
	bl sub_497BC
	ldrh r1, [r4, #0x18]
	ldr r0, _080472BC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4, #0x18]
_08047244:
	ldr r4, _080472B0 @ =gMain
	ldrh r1, [r4, #0x18]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08047266
	ldrb r1, [r4, #0xf]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r4, #0xf]
	bl sub_497BC
	ldrh r1, [r4, #0x18]
	ldr r0, _080472C0 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r4, #0x18]
_08047266:
	ldrb r1, [r4, #0xf]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08047274
	bl sub_49A34
_08047274:
	ldr r0, _080472B0 @ =gMain
	ldrb r1, [r0, #0xf]
	adds r2, r0, #0
	cmp r1, #0
	bne _080472DC
	ldr r3, _080472B4 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r4, #0xe8
	lsls r4, r4, #3
	adds r0, r0, r4
	strb r1, [r0]
	ldrh r0, [r2, #0x14]
	cmp r0, #0
	beq _080472DC
	subs r0, #1
	strh r0, [r2, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080472D2
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0xe4
	ldrb r0, [r1]
	cmp r0, #0
	beq _080472C4
	movs r0, #0xa
	strh r0, [r2, #0x14]
	b _080472D2
	.align 2, 0
_080472B0: .4byte gMain
_080472B4: .4byte gCurrentPinballGame
_080472B8: .4byte 0x00001104
_080472BC: .4byte 0x0000FFFE
_080472C0: .4byte 0x0000FFFD
_080472C4:
	ldrb r0, [r2, #0x11]
	cmp r0, #8
	bne _080472CE
	movs r0, #0x13
	b _080472D0
_080472CE:
	movs r0, #0x14
_080472D0:
	strb r0, [r1]
_080472D2:
	ldrh r0, [r2, #0x14]
	cmp r0, #0
	bne _080472DC
	ldrb r0, [r2, #0x11]
	strb r0, [r2, #0xf]
_080472DC:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_472E4
sub_472E4: @ 0x080472E4
	push {r4, lr}
	ldr r4, _080472FC @ =gMain
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	beq _08047338
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08047300
	bl sub_478D8
	b _08047338
	.align 2, 0
_080472FC: .4byte gMain
_08047300:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804730E
	bl sub_47670
	b _08047338
_0804730E:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804731C
	bl sub_474F4
	b _08047338
_0804731C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08047338
	bl sub_47344
	ldr r0, _08047340 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrb r0, [r4, #0x10]
	adds r0, #1
	movs r2, #0xe8
	lsls r2, r2, #3
	adds r1, r1, r2
	strb r0, [r1]
_08047338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08047340: .4byte gCurrentPinballGame

	thumb_func_start sub_47344
sub_47344: @ 0x08047344
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x44
	ldr r1, _08047448 @ =gUnknown_08137DBE
	mov r0, sp
	movs r2, #0x2a
	bl memcpy
	add r4, sp, #0x2c
	ldr r1, _0804744C @ =gUnknown_08137DE8
	adds r0, r4, #0
	movs r2, #0x18
	bl memcpy
	mov sb, r4
	mov r1, sp
	adds r1, #0x2d
	mov r6, sp
	adds r6, #0x31
	mov r7, sp
	adds r7, #0x39
	add r0, sp, #0x38
	mov r8, r0
	ldr r0, _08047450 @ =gUnknown_03005C00
	movs r3, #0
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r2, #0x40
_08047382:
	strh r3, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bne _08047382
	ldr r5, _08047454 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _08047458 @ =0x0000132C
	adds r0, r0, r4
	ldr r0, [r0]
	movs r2, #0x10
	ldrsh r0, [r0, r2]
	movs r2, #3
	movs r3, #1
	bl sub_06CC
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl sub_06CC
	mov r0, sb
	movs r1, #0x1a
	movs r2, #9
	bl sub_0678
	ldr r0, [r5]
	adds r0, #0x68
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r7, #0
	movs r2, #3
	movs r3, #1
	bl sub_06CC
	mov r0, r8
	movs r1, #0x1a
	movs r2, #0x12
	bl sub_0678
	mov r0, sp
	movs r1, #0x1a
	movs r2, #0
	bl sub_0678
	ldr r4, _0804745C @ =gMain
	ldrh r1, [r4, #0x1c]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08047464
	ldr r0, [r4, #0x4c]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08047408
	ldr r0, _08047460 @ =gUnknown_08137E00
	ldrb r1, [r4, #0x10]
	adds r1, #0x1a
	movs r2, #0
	bl sub_0678
_08047408:
	ldrh r1, [r4, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804741C
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0804741C
	subs r0, #1
	strb r0, [r4, #0x10]
_0804741C:
	ldr r2, _0804745C @ =gMain
	ldrh r1, [r2, #0x18]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08047432
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	bne _08047432
	adds r0, #1
	strb r0, [r2, #0x10]
_08047432:
	ldr r0, _08047454 @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r6, #0xe8
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #2
	bne _08047490
	bl sub_48124
	b _08047490
	.align 2, 0
_08047448: .4byte gUnknown_08137DBE
_0804744C: .4byte gUnknown_08137DE8
_08047450: .4byte gUnknown_03005C00
_08047454: .4byte gCurrentPinballGame
_08047458: .4byte 0x0000132C
_0804745C: .4byte gMain
_08047460: .4byte gUnknown_08137E00
_08047464:
	ldr r0, [r5]
	movs r1, #0xe8
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08047478
	cmp r0, #2
	beq _0804747E
	b _08047482
_08047478:
	bl sub_47FF8
	b _08047482
_0804747E:
	bl sub_48124
_08047482:
	ldr r0, _080474DC @ =gUnknown_08137E00
	ldr r1, _080474E0 @ =gMain
	ldrb r1, [r1, #0x10]
	adds r1, #0x1a
	movs r2, #0
	bl sub_0678
_08047490:
	ldr r4, _080474E4 @ =gUnknown_03005C00
	ldr r5, _080474E0 @ =gMain
	movs r2, #0xc1
	lsls r2, r2, #8
	adds r3, r2, #0
	movs r6, #0xd0
	lsls r6, r6, #3
	adds r1, r4, r6
	movs r2, #0x40
_080474A2:
	ldrh r6, [r1]
	adds r0, r3, r6
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _080474A2
	ldr r1, _080474E8 @ =0x040000D4
	str r4, [r1]
	ldr r0, _080474EC @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _080474F0 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r5, #0x1c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080474CC
	bl sub_47FBC
_080474CC:
	add sp, #0x44
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080474DC: .4byte gUnknown_08137E00
_080474E0: .4byte gMain
_080474E4: .4byte gUnknown_03005C00
_080474E8: .4byte 0x040000D4
_080474EC: .4byte 0x06002000
_080474F0: .4byte 0x80000400

	thumb_func_start sub_474F4
sub_474F4: @ 0x080474F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08047638 @ =gMain
	ldr r1, [r0, #0x44]
	adds r1, #0xa8
	ldr r5, [r1]
	ldrh r1, [r5]
	mov sb, r0
	cmp r1, #0
	beq _08047558
	movs r0, #0x3f
	strh r0, [r5, #2]
	movs r0, #0x34
	strh r0, [r5, #4]
	ldr r7, _0804763C @ =gOamBuffer
	ldr r0, _08047640 @ =0xFFFFFE00
	mov ip, r0
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08047644 @ =0x000001FF
	mov r8, r1
	movs r6, #7
_08047524:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r2, #2
	ldrsh r1, [r4, r2]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	mov r0, r8
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r5, #4]
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	strb r0, [r1]
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge _08047524
_08047558:
	mov r1, sb
	ldr r0, [r1, #0x4c]
	lsls r0, r0, #0x1c
	lsrs r7, r0, #0x10
	movs r6, #0
_08047562:
	adds r0, r7, #0
	bl Cos
	ldr r4, _08047648 @ =gUnknown_02031500
	lsls r2, r6, #1
	adds r4, r2, r4
	ldr r1, _0804764C @ =gUnknown_02030750
	adds r5, r2, r1
	movs r2, #0
	ldrsh r1, [r5, r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	movs r1, #0xc8
	bl __divsi3
	strh r0, [r4]
	ldr r0, _08047638 @ =gMain
	ldr r1, [r0, #0x4c]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0804759E
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0804759E
	strh r1, [r5]
_0804759E:
	adds r6, #1
	cmp r6, #7
	ble _08047562
	ldr r2, _08047638 @ =gMain
	ldrh r1, [r2, #0x12]
	movs r0, #0xe1
	lsls r0, r0, #4
	cmp r1, r0
	bne _080475FA
	ldr r1, _08047650 @ =0x040000D4
	ldr r0, _08047654 @ =gUnknown_08509F4C
	str r0, [r1]
	ldr r0, _08047658 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804765C @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2, #0x44]
	adds r0, #0xa8
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r6, #0
	mov r8, r6
	ldr r5, _08047648 @ =gUnknown_02031500
	ldr r7, _08047660 @ =0x0000E0C0
_080475D2:
	lsls r4, r6, #1
	strh r7, [r5]
	ldr r0, _08047664 @ =gUnknown_020306C0
	adds r0, r4, r0
	mov r1, r8
	strh r1, [r0]
	bl Random
	ldr r1, _0804764C @ =gUnknown_02030750
	adds r4, r4, r1
	movs r1, #0x1e
	bl __umodsi3
	ldr r2, _08047668 @ =0x0000FFCE
	adds r0, r0, r2
	strh r0, [r4]
	adds r5, #2
	adds r6, #1
	cmp r6, #7
	ble _080475D2
_080475FA:
	ldr r0, _08047638 @ =gMain
	ldrh r1, [r0, #0x12]
	mov sb, r0
	cmp r1, #0
	beq _08047618
	subs r0, r1, #1
	mov r1, sb
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08047618
	ldr r0, _0804766C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1, #0x1d]
_08047618:
	mov r2, sb
	ldrh r1, [r2, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804762C
	ldr r0, _0804766C @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #2
	strb r0, [r1, #0x1d]
_0804762C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047638: .4byte gMain
_0804763C: .4byte gOamBuffer
_08047640: .4byte 0xFFFFFE00
_08047644: .4byte 0x000001FF
_08047648: .4byte gUnknown_02031500
_0804764C: .4byte gUnknown_02030750
_08047650: .4byte 0x040000D4
_08047654: .4byte gUnknown_08509F4C
_08047658: .4byte 0x06015800
_0804765C: .4byte 0x80000200
_08047660: .4byte 0x0000E0C0
_08047664: .4byte gUnknown_020306C0
_08047668: .4byte 0x0000FFCE
_0804766C: .4byte gCurrentPinballGame

	thumb_func_start sub_47670
sub_47670: @ 0x08047670
	push {r4, r5, r6, r7, lr}
	ldr r4, _080476A4 @ =gMain
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _0804767C
	b _080477C4
_0804767C:
	cmp r0, #0x14
	bhi _080476AC
	cmp r0, #0x14
	bne _0804768A
	movs r0, SE_UNKNOWN_0xA4
	bl m4aSongNumStart
_0804768A:
	ldr r0, _080476A8 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xfc
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x7f
	bgt _080476C4
	adds r0, r2, #0
	adds r0, #8
	b _080476C2
	.align 2, 0
_080476A4: .4byte gMain
_080476A8: .4byte gCurrentPinballGame
_080476AC:
	ldr r0, _0804771C @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xfc
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080476C4
	adds r0, r2, #0
	subs r0, #8
_080476C2:
	strh r0, [r1]
_080476C4:
	bl sub_48190
	ldr r2, _08047720 @ =gMain
	ldrh r0, [r2, #0x12]
	subs r0, #1
	movs r1, #0
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bne _080477A0
	ldr r0, _0804771C @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0xfc
	movs r1, #0x80
	strh r1, [r0]
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r2, r1
	movs r1, #1
	strh r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #3
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #0xb8
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #0xb8
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _08047724 @ =0x040000D4
	ldr r0, _08047728 @ =gUnknown_0850398C
	str r0, [r1]
	ldr r0, _0804772C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08047730 @ =0x80001400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r2, #4]
	cmp r0, #0
	bne _08047738
	ldr r0, _08047734 @ =gUnknown_08521FAC
	b _0804773A
	.align 2, 0
_0804771C: .4byte gCurrentPinballGame
_08047720: .4byte gMain
_08047724: .4byte 0x040000D4
_08047728: .4byte gUnknown_0850398C
_0804772C: .4byte 0x06015800
_08047730: .4byte 0x80001400
_08047734: .4byte gUnknown_08521FAC
_08047738:
	ldr r0, _0804778C @ =gUnknown_08521FCC
_0804773A:
	str r0, [r1]
	ldr r0, _08047790 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08047794 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, SE_UNKNOWN_0xA4
	bl m4aSongNumStart
	movs r1, #0
	ldr r7, _08047798 @ =gCurrentPinballGame
	ldr r6, _0804779C @ =0x0000063C
	movs r5, #0
_08047754:
	movs r2, #0
	lsls r4, r1, #0x10
	asrs r1, r4, #0x10
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r3, r0, #2
_08047760:
	ldr r0, [r7]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, r3
	adds r0, r0, r6
	adds r0, r0, r2
	strb r5, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x13
	ble _08047760
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08047754
	b _080478D0
	.align 2, 0
_0804778C: .4byte gUnknown_08521FCC
_08047790: .4byte 0x050003C0
_08047794: .4byte 0x80000010
_08047798: .4byte gCurrentPinballGame
_0804779C: .4byte 0x0000063C
_080477A0:
	cmp r0, #1
	beq _080477A6
	b _080478D0
_080477A6:
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #3
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #0xb8
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #0xb8
	adds r0, r2, r3
	strh r1, [r0]
	b _080478D0
_080477C4:
	ldrb r0, [r4, #0xf]
	movs r1, #0xef
	ands r1, r0
	strb r1, [r4, #0xf]
	bl sub_47FBC
	ldr r5, _08047860 @ =gCurrentPinballGame
	ldr r1, [r5]
	adds r2, r1, #0
	adds r2, #0x30
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	ble _080478BC
	ldr r0, _08047864 @ =0x00000724
	adds r1, r1, r0
	movs r4, #0
	subs r0, #0x1c
	strh r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0x3c
	strh r1, [r0, #0x26]
	ldr r1, _08047868 @ =0x0000062A
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	ldr r2, _0804786C @ =0x0000062B
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r3, _08047870 @ =0x0000062C
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #3
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	adds r3, #3
	adds r0, r0, r3
	strb r4, [r0]
	movs r0, #0
	bl sub_11C14
	movs r0, #0
	bl sub_46FD4
	ldr r0, [r5]
	ldr r1, _08047874 @ =0x0000029E
	adds r0, r0, r1
	strb r4, [r0]
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _080478A4
	ldr r2, _08047878 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080478AA
	lsls r0, r0, #2
	ldr r1, _0804787C @ =_08047880
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08047860: .4byte gCurrentPinballGame
_08047864: .4byte 0x00000724
_08047868: .4byte 0x0000062A
_0804786C: .4byte 0x0000062B
_08047870: .4byte 0x0000062C
_08047874: .4byte 0x0000029E
_08047878: .4byte 0x00000283
_0804787C: .4byte _08047880
_08047880: @ jump table
	.4byte _08047894 @ case 0
	.4byte _0804789C @ case 1
	.4byte _08047894 @ case 2
	.4byte _0804789C @ case 3
	.4byte _0804789C @ case 4
_08047894:
	movs r0, MUS_BONUS_CHANCE
	bl m4aSongNumStart
	b _080478AA
_0804789C:
	movs r0, MUS_BONUS_CHANCE_LEGENDARY
	bl m4aSongNumStart
	b _080478AA
_080478A4:
	movs r0, #1
	bl sub_19B64
_080478AA:
	ldr r0, _080478B8 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
	b _080478D0
	.align 2, 0
_080478B8: .4byte gCurrentPinballGame
_080478BC:
	ldrb r0, [r4, #0xf]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r4, #0xf]
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r4, #0x12]
	movs r0, MUS_GAME_OVER
	bl m4aSongNumStart
_080478D0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_478D8
sub_478D8: @ 0x080478D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r7, _08047AEC @ =gMain
	ldrh r0, [r7, #0x12]
	cmp r0, #0
	bne _080478EE
	b _08047F2E
_080478EE:
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r6, r7, r0
	ldrh r0, [r6]
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq _08047984
	movs r0, #0x58
	strh r0, [r6, #2]
	ldr r0, _08047AF0 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0xfe
	ldrh r0, [r0]
	adds r0, #0x14
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08047AF4 @ =gOamBuffer
	ldr r2, _08047AF8 @ =0xFFFFFE00
	mov sl, r2
	movs r3, #0xf
	rsbs r3, r3, #0
	mov sb, r3
_08047920:
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
	ldr r2, _08047AFC @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sl
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r3, [r5, #4]
	adds r0, r0, r3
	strb r0, [r1]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r0, [r2, #1]
	movs r1, #3
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrb r1, [r2, #3]
	mov r0, sb
	ands r0, r1
	movs r1, #6
	orrs r0, r1
	strb r0, [r2, #3]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #1
	ble _08047920
_08047984:
	mov r6, r8
	ldrh r0, [r6]
	cmp r0, #0
	beq _08047A14
	ldr r4, _08047AF0 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x18
	strh r0, [r6, #2]
	ldr r0, [r4]
	adds r4, r0, #0
	adds r4, #0xfe
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x14
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _08047AF4 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _08047AFC @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08047AF8 @ =0xFFFFFE00
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
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r1, #1]
	movs r2, #3
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #3]
_08047A14:
	subs r6, #0xb8
	ldrh r0, [r6]
	cmp r0, #0
	beq _08047A9A
	ldr r4, _08047AF0 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x38
	strh r0, [r6, #2]
	ldr r0, [r4]
	adds r4, r0, #0
	adds r4, #0xfe
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x34
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	movs r0, #0
	ldr r7, _08047AF4 @ =gOamBuffer
	ldr r2, _08047AF8 @ =0xFFFFFE00
	mov r8, r2
_08047A56:
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
	ldr r2, _08047AFC @ =0x000001FF
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
	ble _08047A56
_08047A9A:
	ldr r1, _08047AEC @ =gMain
	ldrh r0, [r1, #0x12]
	subs r0, #1
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x46
	bls _08047B00
	ldrh r1, [r1, #0x12]
	adds r2, r1, #0
	adds r2, #0x14
	adds r0, r2, #0
	asrs r0, r0, #6
	lsls r0, r0, #6
	subs r0, r2, r0
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x10
	bl Sin
	ldr r1, _08047AF0 @ =gCurrentPinballGame
	ldr r5, [r1]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r4, r5, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x28
	bl __divsi3
	str r0, [r4]
	movs r4, #0x84
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, #0x86
	strh r0, [r1]
	b _08047B3C
	.align 2, 0
_08047AEC: .4byte gMain
_08047AF0: .4byte gCurrentPinballGame
_08047AF4: .4byte gOamBuffer
_08047AF8: .4byte 0xFFFFFE00
_08047AFC: .4byte 0x000001FF
_08047B00:
	ldr r0, _08047B6C @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x85
	lsls r5, r5, #1
	adds r3, r4, r5
	ldrh r0, [r3]
	subs r0, #0x23
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_08047B3C:
	ldr r1, _08047B70 @ =gMain
	ldrh r2, [r1, #0x12]
	adds r0, r2, #0
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r1, #0
	cmp r0, #0x1d
	bhi _08047B74
	ldrh r1, [r6, #0x12]
	movs r0, #0x3c
	subs r0, r0, r1
	lsls r0, r0, #8
	movs r1, #0x1e
	bl __divsi3
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	b _08047B8C
	.align 2, 0
_08047B6C: .4byte gCurrentPinballGame
_08047B70: .4byte gMain
_08047B74:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _08047B8C
	movs r2, #0xbb
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
_08047B8C:
	ldrh r0, [r6, #0x12]
	cmp r0, #0x1e
	bhi _08047BBE
	cmp r0, #0xa
	bls _08047BAE
	adds r1, r0, #0
	subs r1, #0xa
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x14
	bl __divsi3
	adds r0, #8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08047BE4
_08047BAE:
	movs r3, #8
	mov sl, r3
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r1, r6, r4
	movs r0, #0
	strh r0, [r1]
	b _08047BE6
_08047BBE:
	ldr r0, _08047C48 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xfe
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0
	ble _08047BE0
	adds r0, r2, #0
	subs r0, #8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08047BE0
	movs r0, #0
	strh r0, [r1]
_08047BE0:
	movs r0, #0x80
	lsls r0, r0, #1
_08047BE4:
	mov sl, r0
_08047BE6:
	adds r3, r6, #0
	ldrh r0, [r3, #0x12]
	cmp r0, #0xca
	bls _08047BF0
	b _08047DBA
_08047BF0:
	cmp r0, #0x37
	bls _08047C50
	ldr r7, _08047C48 @ =gCurrentPinballGame
	ldr r2, [r7]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r1, [r0]
	movs r5, #0x85
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	subs r0, #0x5a
	adds r4, #2
	adds r1, r2, r4
	strh r0, [r1]
	adds r5, #6
	mov r8, r5
	adds r1, r2, r5
	subs r4, #0xe
	adds r0, r2, r4
	ldr r0, [r0]
	str r0, [r1]
	adds r5, #4
	mov sb, r5
	adds r1, r2, r5
	adds r4, #4
	adds r0, r2, r4
	ldr r0, [r0]
	str r0, [r1]
	ldrh r0, [r3, #0x12]
	cmp r0, #0x38
	bne _08047C40
	movs r0, SE_UNKNOWN_0x95
	bl m4aSongNumStart
_08047C40:
	ldr r5, [r7]
	ldr r0, _08047C4C @ =0x0000132C
	adds r4, r5, r0
	b _08047CBC
	.align 2, 0
_08047C48: .4byte gCurrentPinballGame
_08047C4C: .4byte 0x0000132C
_08047C50:
	cmp r0, #0x1f
	bls _08047D00
	ldr r7, _08047CF4 @ =gCurrentPinballGame
	ldr r5, [r7]
	movs r0, #0x87
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #6
	movs r1, #0
	mov ip, r1
	strh r0, [r4]
	movs r2, #0x88
	lsls r2, r2, #1
	mov r8, r2
	adds r2, r5, r2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #1
	mov sb, r0
	adds r2, r5, r0
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r4, #0xa4
	lsls r4, r4, #3
	adds r0, r6, r4
	mov r1, ip
	strh r1, [r0]
	ldrh r0, [r6, #0x12]
	cmp r0, #0x20
	bne _08047CB6
	ldr r2, _08047CF8 @ =0x000005FA
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, SE_UNKNOWN_0x96
	bl m4aSongNumStart
	movs r0, #6
	bl sub_11B0
_08047CB6:
	ldr r5, [r7]
	ldr r3, _08047CFC @ =0x0000132C
	adds r4, r5, r3
_08047CBC:
	ldr r6, [r4]
	mov r1, r8
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x56
	lsls r0, r0, #8
	str r0, [r6, #0x34]
	ldr r6, [r4]
	adds r0, r5, #0
	adds r0, #0xfe
	movs r2, #0
	ldrsh r4, [r0, r2]
	add r5, sb
	ldr r0, [r5]
	movs r1, #0x64
	bl __divsi3
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r4, r4, r0
	lsls r4, r4, #8
	str r4, [r6, #0x38]
	adds r2, r7, #0
	b _08047D80
	.align 2, 0
_08047CF4: .4byte gCurrentPinballGame
_08047CF8: .4byte 0x000005FA
_08047CFC: .4byte 0x0000132C
_08047D00:
	ldr r4, _08047E68 @ =gCurrentPinballGame
	mov sb, r4
	ldr r7, [r4]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	adds r0, #0x14
	strh r0, [r3]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, _08047E6C @ =0x0000132C
	adds r6, r7, r0
	ldr r4, [r6]
	ldr r0, [r2]
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x56
	lsls r0, r0, #8
	str r0, [r4, #0x34]
	ldr r1, [r6]
	mov r8, r1
	adds r0, r7, #0
	adds r0, #0xfe
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldr r0, [r5]
	movs r1, #0x64
	bl __divsi3
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r4, r4, r0
	lsls r4, r4, #8
	mov r5, r8
	str r4, [r5, #0x38]
	ldr r6, [r6]
	ldr r0, [r6, #0x38]
	ldr r1, _08047E70 @ =0x00017100
	mov r2, sb
	cmp r0, r1
	ble _08047D80
	str r1, [r6, #0x38]
_08047D80:
	ldr r0, [r2]
	ldr r1, _08047E6C @ =0x0000132C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0
	strb r3, [r0, #1]
	ldr r0, [r2]
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	ldr r1, [r2]
	ldr r0, [r1, #0x34]
	cmp r0, #0
	bge _08047DA0
	adds r0, #0x7f
_08047DA0:
	asrs r0, r0, #7
	strh r0, [r1, #0x28]
	ldr r1, [r2]
	ldr r0, [r1, #0x38]
	cmp r0, #0
	bge _08047DAE
	adds r0, #0x7f
_08047DAE:
	asrs r0, r0, #7
	strh r0, [r1, #0x2a]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, [r2]
	strh r3, [r0, #0x32]
_08047DBA:
	movs r0, #0x80
	lsls r0, r0, #1
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r2, #3
	bl SetMatrixScale
	ldr r3, [sp]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #4
	bl SetMatrixScale
	ldr r4, _08047E74 @ =gMain
	ldrh r1, [r4, #0x12]
	cmp r1, #0xcb
	beq _08047DE2
	b _08047F18
_08047DE2:
	ldr r2, _08047E68 @ =gCurrentPinballGame
	ldr r3, [r2]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r1, #0
	str r1, [r0]
	adds r5, #4
	adds r0, r3, r5
	str r1, [r0]
	adds r5, #4
	adds r0, r3, r5
	strh r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0xfe
	movs r0, #0x64
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #1
	strh r1, [r0]
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r1, [r0]
	movs r5, #0xa4
	lsls r5, r5, #3
	adds r0, r4, r5
	strh r1, [r0]
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _08047EAC
	ldr r0, _08047E78 @ =0x040000D4
	ldr r1, _08047E7C @ =gUnknown_0850100C
	str r1, [r0]
	ldr r1, _08047E80 @ =0x06015800
	str r1, [r0, #4]
	ldr r1, _08047E84 @ =0x80001200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08047E88 @ =gUnknown_085028CC
	str r1, [r0]
	ldr r1, _08047E8C @ =0x06016800
	str r1, [r0, #4]
	ldr r1, _08047E90 @ =0x80000400
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08047E94 @ =gUnknown_085038CC
	str r1, [r0]
	ldr r1, _08047E98 @ =0x06017000
	str r1, [r0, #4]
	ldr r1, _08047E9C @ =0x80000060
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08047EA0 @ =gUnknown_08514F4C
	str r1, [r0]
	ldr r1, _08047EA4 @ =0x050003C0
	str r1, [r0, #4]
	ldr r1, _08047EA8 @ =0x80000010
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	b _08047ECA
	.align 2, 0
_08047E68: .4byte gCurrentPinballGame
_08047E6C: .4byte 0x0000132C
_08047E70: .4byte 0x00017100
_08047E74: .4byte gMain
_08047E78: .4byte 0x040000D4
_08047E7C: .4byte gUnknown_0850100C
_08047E80: .4byte 0x06015800
_08047E84: .4byte 0x80001200
_08047E88: .4byte gUnknown_085028CC
_08047E8C: .4byte 0x06016800
_08047E90: .4byte 0x80000400
_08047E94: .4byte gUnknown_085038CC
_08047E98: .4byte 0x06017000
_08047E9C: .4byte 0x80000060
_08047EA0: .4byte gUnknown_08514F4C
_08047EA4: .4byte 0x050003C0
_08047EA8: .4byte 0x80000010
_08047EAC:
	ldr r1, _08047EF4 @ =0x040000D4
	ldr r0, _08047EF8 @ =gUnknown_0850100C
	str r0, [r1]
	ldr r0, _08047EFC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08047F00 @ =0x80001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08047F04 @ =gUnknown_08514F6C
	str r0, [r1]
	ldr r0, _08047F08 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08047F0C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08047ECA:
	ldr r1, [r2]
	movs r0, #2
	strb r0, [r1, #0x1f]
	ldr r0, [r2]
	ldr r1, _08047F10 @ =0x000005FA
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _08047F14 @ =0x000005F7
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0x88
	lsls r4, r4, #5
	adds r0, r0, r4
	strb r1, [r0]
	movs r0, SE_UNKNOWN_0x94
	bl m4aSongNumStart
	b _08047FA0
	.align 2, 0
_08047EF4: .4byte 0x040000D4
_08047EF8: .4byte gUnknown_0850100C
_08047EFC: .4byte 0x06015800
_08047F00: .4byte 0x80001200
_08047F04: .4byte gUnknown_08514F6C
_08047F08: .4byte 0x050003C0
_08047F0C: .4byte 0x80000010
_08047F10: .4byte 0x000005FA
_08047F14: .4byte 0x000005F7
_08047F18:
	cmp r1, #0
	bne _08047FA0
	movs r5, #0xd2
	lsls r5, r5, #3
	adds r0, r4, r5
	strh r1, [r0]
	movs r2, #0xbb
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	b _08047FA0
_08047F2E:
	ldrb r1, [r7, #0xf]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xf]
	ldr r5, _08047F6C @ =gCurrentPinballGame
	ldr r1, [r5]
	movs r4, #0
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	movs r0, #0
	bl sub_11C14
	ldr r0, [r5]
	strb r4, [r0, #0x1f]
	movs r0, #0
	bl sub_46FD4
	ldr r0, [r5]
	ldr r3, _08047F70 @ =0x0000029E
	adds r0, r0, r3
	strb r4, [r0]
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08047F78
	ldr r0, [r5]
	ldr r4, _08047F74 @ =0x0000132C
	adds r0, r0, r4
	ldr r1, [r0]
	movs r0, #3
	b _08047F82
	.align 2, 0
_08047F6C: .4byte gCurrentPinballGame
_08047F70: .4byte 0x0000029E
_08047F74: .4byte 0x0000132C
_08047F78:
	ldr r0, [r5]
	ldr r5, _08047FB0 @ =0x0000132C
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #1
_08047F82:
	strb r0, [r1, #1]
	ldr r2, _08047FB4 @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08047FB8 @ =0x000005F7
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xe4
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, #0x88
	lsls r2, r2, #5
	adds r0, r0, r2
	strb r1, [r0]
_08047FA0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047FB0: .4byte 0x0000132C
_08047FB4: .4byte gCurrentPinballGame
_08047FB8: .4byte 0x000005F7
