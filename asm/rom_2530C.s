#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_2530C
sub_2530C: @ 0x0802530C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080253D0 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r5, [r1, #0x48]
	ldrh r1, [r5]
	mov r8, r0
	ldr r0, _080253D4 @ =gCurrentPinballGame
	mov sb, r0
	cmp r1, #0
	beq _08025360
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025330:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _08025330
_08025360:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x48]
	movs r0, #0
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r5, [r0, #0x30]
	ldrh r0, [r5]
	cmp r0, #0
	beq _080253B0
	movs r0, #0
	ldr r6, _080253D8 @ =gOamBuffer
	ldr r1, _080253DC @ =0xFFFFFE00
	mov ip, r1
	movs r7, #0xc8
_08025380:
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #3
	adds r0, #8
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrh r3, [r1, #2]
	mov r0, ip
	ands r0, r3
	orrs r0, r7
	strh r0, [r1, #2]
	ldrh r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r6
	movs r1, #0xb4
	strb r1, [r0]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #5
	ble _08025380
_080253B0:
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x30]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xe4
	strb r2, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080253D0: .4byte gMain
_080253D4: .4byte gCurrentPinballGame
_080253D8: .4byte gOamBuffer
_080253DC: .4byte 0xFFFFFE00

	thumb_func_start sub_253E0
sub_253E0: @ 0x080253E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #1
	mov r8, r0
	ldr r0, _08025490 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x48]
	mov r1, r8
	strh r1, [r0]
	ldr r4, _08025494 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r5, _08025498 @ =0x000006CC
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08025410
	bl sub_2971C
_08025410:
	ldr r3, [r4]
	ldr r2, _0802549C @ =0x000006C7
	adds r0, r3, r2
	ldr r4, _080254A0 @ =0x000006C6
	adds r1, r3, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	blt _08025428
	b _0802564C
_08025428:
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08025464
	ldr r1, _080254A4 @ =0x000006CA
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08025464
	adds r1, r3, #0
	adds r1, #0xe4
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _080254A8 @ =0x040000D4
	ldr r0, _080254AC @ =gUnknown_083A05CC
	str r0, [r1]
	ldr r0, _080254B0 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080254B4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080254B8 @ =gUnknown_0839DDAC
	str r0, [r1]
	ldr r0, _080254BC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080254C0 @ =0x80001400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08025464:
	ldr r1, _080254C4 @ =gUnknown_086AD3FE
	ldr r3, _08025494 @ =gCurrentPinballGame
	ldr r2, [r3]
	ldr r6, _08025498 @ =0x000006CC
	adds r4, r2, r6
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _080254A4 @ =0x000006CA
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r5, r3, #0
	cmp r0, r1
	ble _080254C8
	adds r0, r1, #1
	strh r0, [r2]
	b _08025650
	.align 2, 0
_08025490: .4byte gMain
_08025494: .4byte gCurrentPinballGame
_08025498: .4byte 0x000006CC
_0802549C: .4byte 0x000006C7
_080254A0: .4byte 0x000006C6
_080254A4: .4byte 0x000006CA
_080254A8: .4byte 0x040000D4
_080254AC: .4byte gUnknown_083A05CC
_080254B0: .4byte 0x050003C0
_080254B4: .4byte 0x80000010
_080254B8: .4byte gUnknown_0839DDAC
_080254BC: .4byte 0x06015800
_080254C0: .4byte 0x80001400
_080254C4: .4byte gUnknown_086AD3FE
_080254C8:
	movs r7, #0
	movs r0, #0
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r3, [r5]
	ldr r2, _0802559C @ =0x000006CC
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bgt _080254E6
	b _0802562C
_080254E6:
	subs r2, #5
	adds r1, r3, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r6
	strb r7, [r0]
	movs r3, #0
	mov r8, r3
	ldr r1, [r5]
	ldr r4, _080255A0 @ =0x000006C9
	adds r1, r1, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r3, [r5]
	adds r2, r3, r2
	ldr r1, _080255A4 @ =0x000006C6
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0802552E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0802553A
	adds r0, r3, #0
	adds r0, #0xe4
	strb r7, [r0]
_0802552E:
	ldr r0, [r5]
	adds r1, r0, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080255B4
_0802553A:
	ldr r0, [r5]
	ldr r2, _080255A4 @ =0x000006C6
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _080255A8 @ =0x000006C7
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r4, _080255AC @ =0x00000625
	adds r0, r0, r4
	strb r1, [r0]
	movs r2, #0
	ldr r6, _080255B0 @ =gMain
	adds r4, r5, #0
	adds r3, #6
_0802555C:
	ldr r1, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r3
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0802555C
	ldr r0, [r6, #0x4c]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r5]
	ldr r1, _080255A0 @ =0x000006C9
	adds r0, r0, r1
	movs r2, #0
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r6, #0x44]
	ldr r0, [r0, #0x48]
	strh r2, [r0]
	b _080255CE
	.align 2, 0
_0802559C: .4byte 0x000006CC
_080255A0: .4byte 0x000006C9
_080255A4: .4byte 0x000006C6
_080255A8: .4byte 0x000006C7
_080255AC: .4byte 0x00000625
_080255B0: .4byte gMain
_080255B4:
	cmp r0, #0
	bne _080255BC
	movs r3, #0
	b _080255CE
_080255BC:
	ldr r0, _08025620 @ =gMain
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r0, [r0, #0x4c]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_080255CE:
	ldr r1, [r5]
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	ldr r7, _08025624 @ =0x000006CD
	adds r0, r1, r7
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldr r6, _08025628 @ =0x000006C9
	adds r0, r0, r6
	asrs r1, r3, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge _08025650
	adds r4, r5, #0
	adds r5, r7, #0
_080255FA:
	ldr r0, [r4]
	asrs r1, r3, #0x10
	adds r0, r0, r5
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, [r4]
	adds r0, r0, r6
	lsls r3, r1, #0x10
	asrs r1, r3, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _080255FA
	b _08025650
	.align 2, 0
_08025620: .4byte gMain
_08025624: .4byte 0x000006CD
_08025628: .4byte 0x000006C9
_0802562C:
	cmp r0, #1
	bne _0802566C
	movs r4, #0xd9
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, _08025648 @ =0x000006D3
	adds r0, r3, r2
	adds r0, r0, r1
	movs r1, #0xd
	strb r1, [r0]
	b _08025650
	.align 2, 0
_08025648: .4byte 0x000006D3
_0802564C:
	movs r3, #0
	mov r8, r3
_08025650:
	ldr r0, _080256CC @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r4, _080256D0 @ =0x000006CC
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0802566C
	movs r0, 0x8C @=SE_UNKNOWN_0x8C
	bl m4aSongNumStart
	bl sub_29664
_0802566C:
	ldr r0, _080256CC @ =gCurrentPinballGame
	ldr r5, [r0]
	ldr r1, _080256D0 @ =0x000006CC
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _08025682
	movs r2, #0
	mov r8, r2
_08025682:
	ldr r0, _080256D4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r7, [r0, #0x48]
	mov r3, r8
	cmp r3, #0
	beq _080256DC
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x14
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r1, #0x60
	subs r0, r0, r1
	strh r0, [r7, #2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x14
	adds r2, r5, #0
	adds r2, #0x5a
	ldr r3, _080256D8 @ =0xFFFFFED4
	adds r1, r3, #0
	ldrh r2, [r2]
	adds r1, r1, r2
	subs r0, r0, r1
	b _080256DE
	.align 2, 0
_080256CC: .4byte gCurrentPinballGame
_080256D0: .4byte 0x000006CC
_080256D4: .4byte gMain
_080256D8: .4byte 0xFFFFFED4
_080256DC:
	movs r0, #0xc8
_080256DE:
	strh r0, [r7, #4]
	movs r4, #4
	ldrsh r0, [r7, r4]
	cmp r0, #0xc7
	ble _080256EC
	movs r0, #0xc8
	strh r0, [r7, #4]
_080256EC:
	movs r2, #0
	ldr r0, _080257EC @ =gOamBuffer
	mov ip, r0
	ldr r1, _080257F0 @ =gUnknown_086AD3FE
	mov sl, r1
	ldr r3, _080257F4 @ =gCurrentPinballGame
	mov sb, r3
	ldr r4, _080257F8 @ =0x000006CC
	mov r8, r4
_080256FE:
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	lsls r6, r5, #3
	adds r6, #8
	adds r6, r7, r6
	ldrh r4, [r6]
	lsls r4, r4, #3
	add r4, ip
	lsls r3, r5, #1
	adds r3, r3, r5
	lsls r0, r3, #1
	str r0, [sp]
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	ldr r0, _080257FC @ =gUnknown_086B53E4
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r4]
	adds r4, #2
	adds r2, r3, #1
	lsls r2, r2, #1
	str r2, [sp]
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp]
	adds r2, r1, r0
	ldr r0, _080257FC @ =gUnknown_086B53E4
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r4]
	adds r3, #2
	lsls r3, r3, #1
	mov r1, sb
	ldr r0, [r1]
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r3, r0
	ldr r0, _080257FC @ =gUnknown_086B53E4
	adds r3, r3, r0
	ldrh r0, [r3]
	strh r0, [r4, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrb r0, [r2, #5]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #5]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, ip
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r4, #2
	ldrsh r0, [r7, r4]
	adds r1, r1, r0
	ldr r4, _08025800 @ =0x000001FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08025804 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r2, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #5
	ble _080256FE
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080257EC: .4byte gOamBuffer
_080257F0: .4byte gUnknown_086AD3FE
_080257F4: .4byte gCurrentPinballGame
_080257F8: .4byte 0x000006CC
_080257FC: .4byte gUnknown_086B53E4
_08025800: .4byte 0x000001FF
_08025804: .4byte 0xFFFFFE00

	thumb_func_start sub_25808
sub_25808: @ 0x08025808
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _08025834 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _08025838 @ =0x00000602
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #8
	bls _08025828
	b _08025F36
_08025828:
	lsls r0, r0, #2
	ldr r1, _0802583C @ =_08025840
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08025834: .4byte gCurrentPinballGame
_08025838: .4byte 0x00000602
_0802583C: .4byte _08025840
_08025840: @ jump table
	.4byte _08025864 @ case 0
	.4byte _080258A8 @ case 1
	.4byte _0802592C @ case 2
	.4byte _08025A7C @ case 3
	.4byte _08025AF8 @ case 4
	.4byte _08025C18 @ case 5
	.4byte _08025C78 @ case 6
	.4byte _08025D60 @ case 7
	.4byte _08025DD0 @ case 8
_08025864:
	ldr r1, [r7]
	ldr r3, _08025878 @ =0x00000604
	adds r2, r1, r3
	ldrh r0, [r2]
	cmp r0, #0x3b
	bhi _0802587C
	adds r0, #1
	strh r0, [r2]
	b _08025890
	.align 2, 0
_08025878: .4byte 0x00000604
_0802587C:
	ldr r4, _0802589C @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r0, [r7]
	ldr r6, _080258A0 @ =0x00000604
	adds r0, r0, r6
	strh r2, [r0]
_08025890:
	ldr r0, _080258A4 @ =gMain
	ldrh r1, [r0, #0x38]
	movs r1, #0xce
	strh r1, [r0, #0x38]
	b _08025F36
	.align 2, 0
_0802589C: .4byte 0x00000602
_080258A0: .4byte 0x00000604
_080258A4: .4byte gMain
_080258A8:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r5, #0
	movs r1, #5
	strb r1, [r0]
	ldr r1, _08025900 @ =0x040000D4
	ldr r0, _08025904 @ =gUnknown_083A07CC
	str r0, [r1]
	ldr r0, _08025908 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0802590C @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025910 @ =gUnknown_083A27EC
	str r0, [r1]
	ldr r0, _08025914 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025918 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0802591C @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x8c
	ldr r1, [r0]
	movs r4, #0
	movs r0, #1
	strh r0, [r1]
	movs r0, 0x8D @=SE_UNKNOWN_0x8D
	bl m4aSongNumStart
	ldr r1, [r7]
	ldr r0, _08025920 @ =0x00000602
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r2, _08025924 @ =0x00000604
	adds r1, r0, r2
	strh r5, [r1]
	ldr r3, _08025928 @ =0x00000603
	adds r0, r0, r3
	strb r4, [r0]
	b _08025F36
	.align 2, 0
_08025900: .4byte 0x040000D4
_08025904: .4byte gUnknown_083A07CC
_08025908: .4byte 0x06015800
_0802590C: .4byte 0x80001000
_08025910: .4byte gUnknown_083A27EC
_08025914: .4byte 0x050003C0
_08025918: .4byte 0x80000010
_0802591C: .4byte gMain
_08025920: .4byte 0x00000602
_08025924: .4byte 0x00000604
_08025928: .4byte 0x00000603
_0802592C:
	ldr r2, _08025954 @ =gUnknown_086AE0C0
	ldr r1, [r7]
	ldr r4, _08025958 @ =0x00000603
	adds r3, r1, r4
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r2, _0802595C @ =0x00000604
	adds r1, r1, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _08025964
	adds r0, r2, #1
	strh r0, [r1]
	ldr r3, _08025960 @ =gMain
	b _08025996
	.align 2, 0
_08025954: .4byte gUnknown_086AE0C0
_08025958: .4byte 0x00000603
_0802595C: .4byte 0x00000604
_08025960: .4byte gMain
_08025964:
	movs r2, #0
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r7]
	ldr r3, _08025A60 @ =0x00000603
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r3, _08025A64 @ =gMain
	cmp r0, #7
	ble _08025996
	movs r0, #7
	strb r0, [r1]
	ldr r1, [r7]
	ldr r4, _08025A68 @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r3, #0x44]
	adds r0, #0x8c
	ldr r0, [r0]
	strh r2, [r0]
_08025996:
	ldr r2, [r7]
	ldr r6, _08025A60 @ =0x00000603
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r3, #0x44]
	adds r0, #0x8c
	ldr r6, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x7c
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r2, #0x5a
	ldrh r1, [r2]
	movs r0, #0xf4
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _080259CE
	movs r0, #0xc8
	strh r0, [r6, #4]
_080259CE:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r7, _08025A6C @ =gOamBuffer
	mov r8, r7
	ldr r1, _08025A70 @ =gUnknown_086B50AE
	mov ip, r1
	asrs r1, r0, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r3, _08025A74 @ =0xFFFFFE00
	mov sb, r3
_080259E8:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r4, r8
	adds r2, r0, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025A78 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
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
	ble _080259E8
	b _08025F36
	.align 2, 0
_08025A60: .4byte 0x00000603
_08025A64: .4byte gMain
_08025A68: .4byte 0x00000602
_08025A6C: .4byte gOamBuffer
_08025A70: .4byte gUnknown_086B50AE
_08025A74: .4byte 0xFFFFFE00
_08025A78: .4byte 0x000001FF
_08025A7C:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r3, #0
	movs r1, #6
	strb r1, [r0]
	ldr r1, _08025AD0 @ =0x040000D4
	ldr r0, _08025AD4 @ =gUnknown_083A29EC
	str r0, [r1]
	ldr r0, _08025AD8 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025ADC @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025AE0 @ =gUnknown_083A320C
	str r0, [r1]
	ldr r0, _08025AE4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025AE8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025AEC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	ldr r1, [r7]
	ldr r4, _08025AF0 @ =0x00000602
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	ldr r6, _08025AF4 @ =0x00000604
	adds r1, r0, r6
	strh r3, [r1]
	movs r7, #0x88
	lsls r7, r7, #5
	adds r0, r0, r7
	strb r2, [r0]
	b _08025F36
	.align 2, 0
_08025AD0: .4byte 0x040000D4
_08025AD4: .4byte gUnknown_083A29EC
_08025AD8: .4byte 0x06015800
_08025ADC: .4byte 0x80000400
_08025AE0: .4byte gUnknown_083A320C
_08025AE4: .4byte 0x050003C0
_08025AE8: .4byte 0x80000010
_08025AEC: .4byte gMain
_08025AF0: .4byte 0x00000602
_08025AF4: .4byte 0x00000604
_08025AF8:
	ldr r1, [r7]
	ldr r0, _08025B10 @ =0x00000604
	adds r2, r1, r0
	ldrh r0, [r2]
	lsrs r5, r0, #1
	cmp r0, #0xe
	bhi _08025B18
	adds r0, #1
	strh r0, [r2]
	ldr r3, _08025B14 @ =gMain
	b _08025B3E
	.align 2, 0
_08025B10: .4byte 0x00000604
_08025B14: .4byte gMain
_08025B18:
	ldr r3, _08025BFC @ =gMain
	ldr r0, [r3, #0x44]
	adds r0, #0x90
	ldr r0, [r0]
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	ldr r6, _08025C00 @ =0x00000602
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	adds r6, #2
	adds r1, r0, r6
	strh r2, [r1]
	ldr r1, _08025C04 @ =0x00000603
	adds r0, r0, r1
	strb r4, [r0]
_08025B3E:
	ldr r0, [r3, #0x44]
	adds r0, #0x90
	ldr r6, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r6, #2]
	adds r1, #0x5a
	ldrh r1, [r1]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08025B6C
	movs r0, #0xc8
	strh r0, [r6, #4]
_08025B6C:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r3, _08025C08 @ =gOamBuffer
	mov r8, r3
	ldr r4, _08025C0C @ =gUnknown_086B4F6A
	mov ip, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
	ldr r7, _08025C10 @ =0xFFFFFE00
	mov sb, r7
_08025B86:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, r8
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025C14 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
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
	ble _08025B86
	b _08025F36
	.align 2, 0
_08025BFC: .4byte gMain
_08025C00: .4byte 0x00000602
_08025C04: .4byte 0x00000603
_08025C08: .4byte gOamBuffer
_08025C0C: .4byte gUnknown_086B4F6A
_08025C10: .4byte 0xFFFFFE00
_08025C14: .4byte 0x000001FF
_08025C18:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r1, #7
	strb r1, [r0]
	ldr r1, _08025C58 @ =0x040000D4
	ldr r0, _08025C5C @ =gUnknown_083A340C
	str r0, [r1]
	ldr r0, _08025C60 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025C64 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025C68 @ =gUnknown_083A542C
	str r0, [r1]
	ldr r0, _08025C6C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025C70 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, [r7]
	ldr r3, _08025C74 @ =0x00000602
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl sub_29924
	movs r0, 0x8E @=SE_UNKNOWN_0x8E
	bl m4aSongNumStart
	b _08025F36
	.align 2, 0
_08025C58: .4byte 0x040000D4
_08025C5C: .4byte gUnknown_083A340C
_08025C60: .4byte 0x06015800
_08025C64: .4byte 0x80001000
_08025C68: .4byte gUnknown_083A542C
_08025C6C: .4byte 0x050003C0
_08025C70: .4byte 0x80000010
_08025C74: .4byte 0x00000602
_08025C78:
	ldr r2, _08025CB0 @ =gMain
	ldrh r0, [r2, #0x3c]
	movs r0, #0
	strh r0, [r2, #0x3c]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsrs r0, r0, #8
	movs r1, #0xa0
	ldrh r3, [r2, #0x38]
	orrs r0, r1
	strh r0, [r2, #0x38]
	ldr r0, [r7]
	ldr r4, _08025CB4 @ =0x00000604
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r3, r2, #0
	cmp r0, #0x48
	bhi _08025CF2
	cmp r0, #7
	bhi _08025CB8
	ldrh r0, [r3, #0x3c]
	movs r0, #0x10
	b _08025CF0
	.align 2, 0
_08025CB0: .4byte gMain
_08025CB4: .4byte 0x00000604
_08025CB8:
	movs r2, #0
	adds r6, r7, #0
	ldr r5, _08025D04 @ =0x000006D3
	movs r4, #0xd
_08025CC0:
	ldr r1, [r6]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r5
	adds r1, r1, r0
	strb r4, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08025CC0
	ldr r0, [r7]
	ldr r6, _08025D08 @ =0x00000604
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	cmp r0, #0
	bge _08025CEA
	adds r0, #3
_08025CEA:
	asrs r0, r0, #2
	adds r0, #0x10
	ldrh r1, [r3, #0x3c]
_08025CF0:
	strh r0, [r3, #0x3c]
_08025CF2:
	ldr r1, [r7]
	ldr r0, _08025D08 @ =0x00000604
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0x47
	bhi _08025D0C
	adds r0, #1
	strh r0, [r2]
	b _08025D28
	.align 2, 0
_08025D04: .4byte 0x000006D3
_08025D08: .4byte 0x00000604
_08025D0C:
	ldr r2, _08025D4C @ =0x00000602
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	ldr r0, [r7]
	ldr r4, _08025D50 @ =0x00000604
	adds r1, r0, r4
	movs r2, #0
	strh r3, [r1]
	ldr r6, _08025D54 @ =0x00000603
	adds r0, r0, r6
	strb r2, [r0]
_08025D28:
	ldr r1, [r7]
	ldr r7, _08025D50 @ =0x00000604
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #8
	bhi _08025D36
	b _08025F36
_08025D36:
	ldr r2, _08025D58 @ =0x000006CA
	adds r0, r1, r2
	ldrh r1, [r0]
	ldr r0, _08025D5C @ =0x00006FFF
	cmp r1, r0
	bls _08025D44
	b _08025F36
_08025D44:
	bl sub_29A6C
	b _08025F36
	.align 2, 0
_08025D4C: .4byte 0x00000602
_08025D50: .4byte 0x00000604
_08025D54: .4byte 0x00000603
_08025D58: .4byte 0x000006CA
_08025D5C: .4byte 0x00006FFF
_08025D60:
	ldr r0, [r7]
	adds r0, #0xe4
	movs r1, #8
	strb r1, [r0]
	ldr r1, _08025DAC @ =0x040000D4
	ldr r0, _08025DB0 @ =gUnknown_083A562C
	str r0, [r1]
	ldr r0, _08025DB4 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08025DB8 @ =0x80000C00
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025DBC @ =gUnknown_083A6E4C
	str r0, [r1]
	ldr r0, _08025DC0 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08025DC4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08025DC8 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x94
	ldr r1, [r0]
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, [r7]
	ldr r3, _08025DCC @ =0x00000602
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r7]
	movs r4, #0x88
	lsls r4, r4, #5
	adds r0, r0, r4
	strb r2, [r0]
	b _08025F36
	.align 2, 0
_08025DAC: .4byte 0x040000D4
_08025DB0: .4byte gUnknown_083A562C
_08025DB4: .4byte 0x06015800
_08025DB8: .4byte 0x80000C00
_08025DBC: .4byte gUnknown_083A6E4C
_08025DC0: .4byte 0x050003C0
_08025DC4: .4byte 0x80000010
_08025DC8: .4byte gMain
_08025DCC: .4byte 0x00000602
_08025DD0:
	ldr r2, _08025DF8 @ =gUnknown_086AE0D0
	ldr r1, [r7]
	ldr r5, _08025DFC @ =0x00000603
	adds r3, r1, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r2, _08025E00 @ =0x00000604
	adds r1, r1, r2
	ldrh r2, [r1]
	cmp r0, r2
	ble _08025E08
	adds r0, r2, #1
	strh r0, [r1]
	ldr r3, _08025E04 @ =gMain
	b _08025E6C
	.align 2, 0
_08025DF8: .4byte gUnknown_086AE0D0
_08025DFC: .4byte 0x00000603
_08025E00: .4byte 0x00000604
_08025E04: .4byte gMain
_08025E08:
	movs r4, #0
	movs r2, #0
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r7]
	ldr r3, _08025F44 @ =0x00000603
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r3, _08025F48 @ =gMain
	cmp r0, #0xa
	ble _08025E6C
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r7]
	ldr r6, _08025F4C @ =0x000006C6
	adds r0, r0, r6
	strb r4, [r0]
	ldr r0, [r7]
	ldr r1, _08025F50 @ =0x000006C7
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r7]
	subs r6, #0xa1
	adds r0, r0, r6
	strb r4, [r0]
	ldrh r0, [r3, #0x38]
	movs r0, #0xce
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3c]
	strh r2, [r3, #0x3c]
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r7]
	adds r0, r0, r5
	movs r1, #0xa
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xe4
	strb r4, [r0]
_08025E6C:
	ldr r2, [r7]
	ldr r7, _08025F44 @ =0x00000603
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r3, #0x44]
	adds r0, #0x94
	ldr r6, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	strh r0, [r6, #2]
	adds r2, #0x5a
	ldrh r1, [r2]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08025EA8
	movs r0, #0xc8
	strh r0, [r6, #4]
_08025EA8:
	movs r2, #0
	lsls r0, r5, #0x10
	ldr r3, _08025F54 @ =gOamBuffer
	mov r8, r3
	ldr r4, _08025F58 @ =gUnknown_086B4E62
	mov ip, r4
	asrs r1, r0, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sl, r0
	ldr r7, _08025F5C @ =0xFFFFFE00
	mov sb, r7
_08025EC2:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	adds r5, r6, r0
	ldrh r0, [r5]
	lsls r0, r0, #3
	mov r1, r8
	adds r2, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r0, r1, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #1
	add r0, sl
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, #2
	lsls r1, r1, #1
	add r1, sl
	add r1, ip
	ldrh r0, [r1]
	strh r0, [r2, #2]
	ldrh r2, [r5]
	lsls r2, r2, #3
	add r2, r8
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r7, #2
	ldrsh r0, [r6, r7]
	adds r1, r1, r0
	ldr r7, _08025F60 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
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
	cmp r3, #3
	ble _08025EC2
_08025F36:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025F44: .4byte 0x00000603
_08025F48: .4byte gMain
_08025F4C: .4byte 0x000006C6
_08025F50: .4byte 0x000006C7
_08025F54: .4byte gOamBuffer
_08025F58: .4byte gUnknown_086B4E62
_08025F5C: .4byte 0xFFFFFE00
_08025F60: .4byte 0x000001FF

	thumb_func_start sub_25F64
sub_25F64: @ 0x08025F64
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r5, _0802607C @ =gCurrentPinballGame
	ldr r1, [r5]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r5]
	movs r3, #0
	strh r2, [r0, #0x18]
	ldr r1, _08026080 @ =0x000006DB
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x36
	strb r3, [r0]
	bl Random
	ldr r4, [r5]
	ldr r6, _08026084 @ =gMain
	ldr r1, [r6, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	adds r4, #0x32
	strb r0, [r4]
	ldr r2, [r5]
	ldr r0, _08026088 @ =gUnknown_08055A68
	mov sb, r0
	adds r0, r2, #0
	adds r0, #0x32
	movs r3, #0
	ldrsb r3, [r0, r3]
	ldrb r1, [r6, #4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r2, #0x35
	strb r0, [r2]
	ldr r1, [r5]
	ldr r2, _0802608C @ =gUnknown_08137928
	mov r8, r2
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _08026090 @ =0x000006DA
	adds r1, r1, r2
	strb r0, [r1]
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	movs r1, #6
	bl __modsi3
	ldrb r2, [r6, #4]
	lsls r1, r2, #3
	subs r1, r1, r2
	adds r1, r1, r0
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	adds r4, #0x35
	strb r0, [r4]
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _08026094 @ =0x000006D9
	adds r1, r1, r2
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	movs r0, #0
	movs r1, #1
	bl sub_1C7F4
	movs r2, #0
	ldr r4, _08026098 @ =0x000006D3
	movs r3, #0xd
	adds r6, r5, #0
_08026032:
	ldr r1, [r5]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08026032
	ldr r1, _0802609C @ =0x040000D4
	ldr r0, _080260A0 @ =gUnknown_083A8AAC
	str r0, [r1]
	ldr r0, _080260A4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080260A8 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080260AC @ =gUnknown_084FA20C
	str r0, [r1]
	ldr r0, _080260B0 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _080260B4 @ =0x80000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r6]
	adds r0, #0xe4
	movs r1, #0xc
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802607C: .4byte gCurrentPinballGame
_08026080: .4byte 0x000006DB
_08026084: .4byte gMain
_08026088: .4byte gUnknown_08055A68
_0802608C: .4byte gUnknown_08137928
_08026090: .4byte 0x000006DA
_08026094: .4byte 0x000006D9
_08026098: .4byte 0x000006D3
_0802609C: .4byte 0x040000D4
_080260A0: .4byte gUnknown_083A8AAC
_080260A4: .4byte 0x050003C0
_080260A8: .4byte 0x80000010
_080260AC: .4byte gUnknown_084FA20C
_080260B0: .4byte 0x06015800
_080260B4: .4byte 0x80000140

	thumb_func_start sub_260B8
sub_260B8: @ 0x080260B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _080260E4 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sb, r1
	cmp r0, #5
	bls _080260D8
	b _0802674E
_080260D8:
	lsls r0, r0, #2
	ldr r1, _080260E8 @ =_080260EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080260E4: .4byte gCurrentPinballGame
_080260E8: .4byte _080260EC
_080260EC: @ jump table
	.4byte _08026104 @ case 0
	.4byte _080261E0 @ case 1
	.4byte _080262E4 @ case 2
	.4byte _08026318 @ case 3
	.4byte _08026318 @ case 4
	.4byte _08026608 @ case 5
_08026104:
	ldr r3, _08026198 @ =gMain
	ldrh r0, [r3, #0x38]
	movs r5, #0
	movs r4, #0
	ldr r0, _0802619C @ =0x00001C10
	strh r0, [r3, #0x38]
	ldrh r0, [r3, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r3, #0x3a]
	mov r0, sb
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	mov r2, sb
	ldr r1, [r2]
	movs r6, #0xdc
	lsls r6, r6, #3
	adds r0, r1, r6
	strh r4, [r0]
	ldr r7, _080261A0 @ =0x000005FE
	adds r0, r1, r7
	strh r4, [r0]
	ldr r0, _080261A4 @ =0x000005FB
	adds r1, r1, r0
	movs r2, #1
	strb r2, [r1]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x50]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x54]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x5c]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x58]
	strh r2, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x4c]
	strh r2, [r0]
	mov r1, sb
	ldr r2, [r1]
	adds r6, #0x10
	adds r0, r2, r6
	movs r1, #0x1e
	strh r1, [r0]
	adds r7, #0xf4
	adds r0, r2, r7
	strh r1, [r0]
	ldr r1, _080261A8 @ =0x000006F4
	adds r0, r2, r1
	strh r4, [r0]
	ldrb r0, [r3, #4]
	cmp r0, #0
	bne _080261B0
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r1, #0xa
	strb r1, [r0]
	mov r4, sb
	ldr r0, [r4]
	ldr r5, _080261AC @ =0x00000171
	adds r0, r0, r5
	strb r1, [r0]
	ldr r0, [r4]
	movs r6, #0xb9
	lsls r6, r6, #1
	adds r0, r0, r6
	strb r1, [r0]
	b _080261CC
	.align 2, 0
_08026198: .4byte gMain
_0802619C: .4byte 0x00001C10
_080261A0: .4byte 0x000005FE
_080261A4: .4byte 0x000005FB
_080261A8: .4byte 0x000006F4
_080261AC: .4byte 0x00000171
_080261B0:
	movs r7, #0xb8
	lsls r7, r7, #1
	adds r0, r2, r7
	strb r5, [r0]
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _080261DC @ =0x00000171
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r1]
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r5, [r0]
_080261CC:
	mov r4, sb
	ldr r0, [r4]
	movs r5, #0xba
	lsls r5, r5, #1
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
	b _0802674E
	.align 2, 0
_080261DC: .4byte 0x00000171
_080261E0:
	mov r6, sb
	ldr r1, [r6]
	ldr r7, _080262CC @ =0x000005FC
	adds r0, r1, r7
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	bne _080261FA
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r6]
	strh r2, [r0, #0x18]
_080261FA:
	ldr r0, _080262D0 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08026296
	mov r4, sb
	ldr r3, [r4]
	movs r4, #0xba
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r0, [r2]
	cmp r0, #0x8e
	bhi _08026224
	ldr r1, _080262D4 @ =gUnknown_08137944
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r5, #0xb8
	lsls r5, r5, #1
	adds r0, r3, r5
	strb r1, [r0]
_08026224:
	mov r6, sb
	ldr r2, [r6]
	adds r1, r2, r4
	ldrh r0, [r1]
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x8e
	bhi _08026254
	ldr r3, _080262D4 @ =gUnknown_08137944
	ldrh r1, [r1]
	adds r0, r1, #0
	subs r0, #0x12
	cmp r0, #0
	bge _08026244
	adds r0, #7
_08026244:
	asrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r7, #0xb9
	lsls r7, r7, #1
	adds r1, r2, r7
	strb r0, [r1]
_08026254:
	mov r0, sb
	ldr r2, [r0]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r0, [r1]
	subs r0, #0x24
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x8e
	bhi _08026286
	ldr r3, _080262D4 @ =gUnknown_08137944
	ldrh r1, [r1]
	adds r0, r1, #0
	subs r0, #0x24
	cmp r0, #0
	bge _08026278
	adds r0, #7
_08026278:
	asrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _080262D8 @ =0x00000171
	adds r1, r2, r4
	strb r0, [r1]
_08026286:
	mov r5, sb
	ldr r1, [r5]
	movs r6, #0xba
	lsls r6, r6, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08026296:
	mov r7, sb
	ldr r4, [r7]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r2, _080262DC @ =0x000006F2
	adds r1, r4, r2
	ldrh r1, [r1]
	bl __divsi3
	movs r3, #0xdc
	lsls r3, r3, #3
	adds r1, r4, r3
	strh r0, [r1]
	ldr r5, _080262E0 @ =0x000006C4
	adds r4, r4, r5
	movs r0, #1
	strb r0, [r4]
	ldr r1, [r7]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	bl sub_26778
	b _0802674E
	.align 2, 0
_080262CC: .4byte 0x000005FC
_080262D0: .4byte gMain
_080262D4: .4byte gUnknown_08137944
_080262D8: .4byte 0x00000171
_080262DC: .4byte 0x000006F2
_080262E0: .4byte 0x000006C4
_080262E4:
	ldr r1, _08026338 @ =gCurrentPinballGame
	ldr r2, [r1]
	ldrh r0, [r2, #0x18]
	cmp r0, #0xe
	bhi _08026312
	adds r0, #1
	strh r0, [r2, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _08026312
	ldrb r0, [r2, #0x17]
	adds r0, #1
	strb r0, [r2, #0x17]
	ldr r1, [r1]
	ldr r6, _0802633C @ =0x000006F2
	adds r2, r1, r6
	movs r0, #6
	strh r0, [r2]
	ldr r7, _08026340 @ =0x000006F4
	adds r1, r1, r7
	movs r0, #0
	strh r0, [r1]
_08026312:
	movs r0, #0
	bl sub_26820
_08026318:
	ldr r0, _08026338 @ =gCurrentPinballGame
	ldr r5, [r0]
	movs r2, #0x17
	ldrsb r2, [r5, r2]
	mov sb, r0
	cmp r2, #3
	bne _08026344
	movs r0, #0xde
	lsls r0, r0, #3
	adds r4, r5, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r2, _0802633C @ =0x000006F2
	adds r1, r5, r2
	b _0802647C
	.align 2, 0
_08026338: .4byte gCurrentPinballGame
_0802633C: .4byte 0x000006F2
_08026340: .4byte 0x000006F4
_08026344:
	cmp r2, #4
	beq _0802634A
	b _08026494
_0802634A:
	movs r3, #0xde
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080263C0
	movs r0, #0x17
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _080263C0
	ldr r4, _08026380 @ =0x000006F4
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _080263CE
	ldr r0, _08026384 @ =gMain
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026388
	movs r0, #0x30
	b _0802638A
	.align 2, 0
_08026380: .4byte 0x000006F4
_08026384: .4byte gMain
_08026388:
	movs r0, #1
_0802638A:
	strh r0, [r1]
	mov r5, sb
	ldr r1, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r0, r1, r6
	ldrh r2, [r0]
	ldr r7, _0802642C @ =0x000006F6
	adds r0, r1, r7
	strh r2, [r0]
	ldr r2, _08026430 @ =0x00000163
	adds r0, r1, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, #0x21
	strb r1, [r0]
	ldr r1, [r5]
	ldr r3, _08026434 @ =0x00000724
	adds r2, r1, r3
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r1, r1, r4
	movs r0, #2
	strb r0, [r1]
_080263C0:
	mov r5, sb
	ldr r0, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802646E
_080263CE:
	mov r7, sb
	ldr r2, [r7]
	ldr r0, _08026428 @ =0x000006F4
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r0, _08026438 @ =gMain
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026412
	ldr r1, _0802643C @ =0x00000283
	adds r0, r2, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, [r7]
	ldr r3, _08026428 @ =0x000006F4
	adds r1, r2, r3
	ldrh r0, [r1]
	cmp r0, #0x17
	bhi _08026412
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _08026412
	movs r0, #0
	strh r0, [r1]
_08026412:
	mov r5, sb
	ldr r4, [r5]
	ldr r6, _08026428 @ =0x000006F4
	adds r1, r4, r6
	ldrh r0, [r1]
	cmp r0, #0
	bne _08026440
	movs r0, #5
	strb r0, [r4, #0x17]
	b _0802646E
	.align 2, 0
_08026428: .4byte 0x000006F4
_0802642C: .4byte 0x000006F6
_08026430: .4byte 0x00000163
_08026434: .4byte 0x00000724
_08026438: .4byte gMain
_0802643C: .4byte 0x00000283
_08026440:
	movs r7, #0xde
	lsls r7, r7, #3
	adds r6, r4, r7
	ldr r0, _08026488 @ =0x000006F2
	adds r5, r4, r0
	ldrh r0, [r6]
	ldrh r2, [r5]
	cmp r0, r2
	bne _0802646E
	ldrh r1, [r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r3, _0802648C @ =0x000006F6
	adds r1, r4, r3
	ldrh r1, [r1]
	bl __divsi3
	movs r1, #0x28
	subs r1, r1, r0
	movs r0, #0
	strh r1, [r5]
	strh r0, [r6]
_0802646E:
	ldr r0, _08026490 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r4, r1, r5
	ldr r6, _08026488 @ =0x000006F2
	adds r1, r1, r6
_0802647C:
	ldrh r0, [r4]
	ldrh r1, [r1]
	bl __umodsi3
	strh r0, [r4]
	b _080264E2
	.align 2, 0
_08026488: .4byte 0x000006F2
_0802648C: .4byte 0x000006F6
_08026490: .4byte gCurrentPinballGame
_08026494:
	movs r7, #0xde
	lsls r7, r7, #3
	adds r4, r5, r7
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, _08026554 @ =0x000006F2
	adds r1, r5, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	bl __umodsi3
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _080264E2
	strh r2, [r5, #0x18]
	ldrb r0, [r5, #0x17]
	adds r0, #1
	strb r0, [r5, #0x17]
	ldr r1, _08026558 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x5c]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x50]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	ldr r0, [r0, #0x54]
	strh r2, [r0]
	ldr r0, [r1, #0x44]
	adds r0, #0x88
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r0, 0x93 @=SE_UNKNOWN_0x93
	bl m4aSongNumStart
_080264E2:
	ldr r6, _0802655C @ =gCurrentPinballGame
	ldr r5, [r6]
	movs r7, #0xde
	lsls r7, r7, #3
	adds r4, r5, r7
	ldrh r0, [r4]
	lsls r0, r0, #5
	ldr r2, _08026554 @ =0x000006F2
	adds r1, r5, r2
	ldrh r1, [r1]
	bl __divsi3
	movs r3, #0xdc
	lsls r3, r3, #3
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	bne _0802651C
	ldr r4, _08026560 @ =0x000006DA
	adds r0, r5, r4
	ldrb r1, [r0]
	ldr r2, _08026564 @ =0x000006D9
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
_0802651C:
	ldr r4, [r6]
	adds r0, r4, r7
	ldrh r5, [r0]
	cmp r5, #1
	beq _08026528
	b _0802674E
_08026528:
	ldr r0, _08026558 @ =gMain
	movs r1, #0xa
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq _08026568
	adds r4, #0x32
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #1
	movs r1, #7
	bl __modsi3
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, #0x33
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0x34
	strb r5, [r0]
	b _080265A8
	.align 2, 0
_08026554: .4byte 0x000006F2
_08026558: .4byte gMain
_0802655C: .4byte gCurrentPinballGame
_08026560: .4byte 0x000006DA
_08026564: .4byte 0x000006D9
_08026568:
	adds r4, #0x32
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #1
	movs r1, #6
	bl __modsi3
	strb r0, [r4]
	ldr r4, [r6]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #1
	movs r1, #6
	bl __modsi3
	adds r4, #0x33
	strb r0, [r4]
	ldr r4, [r6]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #2
	movs r1, #6
	bl __modsi3
	adds r4, #0x34
	strb r0, [r4]
_080265A8:
	ldr r5, _080265F4 @ =gCurrentPinballGame
	ldr r2, [r5]
	ldr r4, _080265F8 @ =gUnknown_08055A68
	adds r0, r2, #0
	adds r0, #0x32
	movs r3, #0
	ldrsb r3, [r0, r3]
	ldr r6, _080265FC @ =gMain
	ldrb r1, [r6, #4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	adds r2, #0x35
	strb r0, [r2]
	ldr r1, [r5]
	ldr r2, _08026600 @ =gUnknown_08137928
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r7, _08026604 @ =0x000006DA
	adds r1, r1, r7
	strb r0, [r1]
	movs r0, #0
	movs r1, #1
	bl sub_1C7F4
	movs r0, 0x81 @=SE_UNKNOWN_0x81
	bl m4aSongNumStart
	b _0802674E
	.align 2, 0
_080265F4: .4byte gCurrentPinballGame
_080265F8: .4byte gUnknown_08055A68
_080265FC: .4byte gMain
_08026600: .4byte gUnknown_08137928
_08026604: .4byte 0x000006DA
_08026608:
	ldr r0, _08026640 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrh r0, [r1, #0x18]
	cmp r0, #0x31
	bhi _08026628
	adds r0, #1
	strh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x32
	bne _08026628
	movs r0, #0
	strb r0, [r1, #0x17]
	movs r0, #1
	bl sub_19B64
_08026628:
	ldr r0, _08026640 @ =gCurrentPinballGame
	ldr r2, [r0]
	ldrh r3, [r2, #0x18]
	mov sb, r0
	cmp r3, #0x1c
	bls _08026636
	b _08026742
_08026636:
	cmp r3, #7
	bhi _08026644
	adds r0, r3, #0
	lsrs r3, r0, #2
	b _08026654
	.align 2, 0
_08026640: .4byte gCurrentPinballGame
_08026644:
	ldrh r0, [r2, #0x18]
	subs r0, #8
	movs r1, #3
	bl __divsi3
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08026654:
	ldr r0, _08026760 @ =gMain
	ldr r1, [r0, #0x44]
	adds r1, #0x88
	ldr r6, [r1]
	ldrh r1, [r6]
	cmp r1, #0
	beq _08026724
	mov r0, sb
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	ldrh r2, [r0]
	movs r0, #0x60
	subs r0, r0, r2
	strh r0, [r6, #2]
	movs r4, #0xdc
	lsls r4, r4, #3
	adds r2, r1, r4
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc7
	ble _08026696
	movs r0, #0xc8
	strh r0, [r6, #4]
_08026696:
	movs r2, #0
	lsls r1, r3, #0x10
	ldr r7, _08026764 @ =gOamBuffer
	mov r8, r7
	ldr r0, _08026768 @ =gUnknown_086B51CE
	mov ip, r0
	asrs r1, r1, #0x10
	movs r0, #0x36
	adds r3, r1, #0
	muls r3, r0, r3
	str r3, [sp]
	ldr r4, _0802676C @ =0xFFFFFE00
	mov sl, r4
_080266B0:
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
	ldr r7, _08026770 @ =0x000001FF
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
	cmp r3, #8
	ble _080266B0
_08026724:
	mov r4, sb
	ldr r3, [r4]
	ldrh r0, [r3, #0x18]
	cmp r0, #0x1c
	bne _08026742
	ldr r5, _08026760 @ =gMain
	ldr r0, [r5, #0x44]
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xe4
	strb r2, [r0]
_08026742:
	mov r6, sb
	ldr r0, [r6]
	ldr r7, _08026774 @ =0x000006C4
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0]
_0802674E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026760: .4byte gMain
_08026764: .4byte gOamBuffer
_08026768: .4byte gUnknown_086B51CE
_0802676C: .4byte 0xFFFFFE00
_08026770: .4byte 0x000001FF
_08026774: .4byte 0x000006C4

	thumb_func_start sub_26778
sub_26778: @ 0x08026778
	push {r4, r5, lr}
	ldr r0, _080267E0 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x64
	bl __umodsi3
	movs r1, #0xa
	bl __udivsi3
	ldr r4, _080267E4 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r1, _080267E8 @ =0x0000070C
	adds r3, r2, r1
	movs r5, #0
	movs r1, #0
	strh r1, [r3]
	ldr r1, _080267EC @ =gUnknown_08137AB8
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080267F0 @ =0x0000072F
	adds r2, r2, r0
	strb r1, [r2]
	ldr r0, [r4]
	ldr r2, _080267F4 @ =0x0000072E
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	subs r2, #3
	adds r0, r0, r2
	strb r1, [r0]
	cmp r3, #7
	beq _080267C2
	cmp r3, #9
	bne _080267FC
_080267C2:
	ldr r0, [r4]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _080267F8 @ =0x0000072A
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r4]
	subs r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	b _08026816
	.align 2, 0
_080267E0: .4byte gMain
_080267E4: .4byte gCurrentPinballGame
_080267E8: .4byte 0x0000070C
_080267EC: .4byte gUnknown_08137AB8
_080267F0: .4byte 0x0000072F
_080267F4: .4byte 0x0000072E
_080267F8: .4byte 0x0000072A
_080267FC:
	ldr r0, [r4]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _0802681C @ =0x0000072A
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strb r5, [r0]
_08026816:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802681C: .4byte 0x0000072A

	thumb_func_start sub_26820
sub_26820: @ 0x08026820
	push {r4, lr}
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq _08026878
	ldr r2, _0802686C @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r1, _08026870 @ =0x0000072A
	adds r0, r0, r1
	movs r3, #1
	strb r3, [r0]
	ldr r0, [r2]
	movs r4, #0xe5
	lsls r4, r4, #3
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r2]
	adds r1, #7
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r4, #6
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	subs r4, #3
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _08026874 @ =0x00000729
	adds r0, r0, r1
	strb r3, [r0]
	b _080268AC
	.align 2, 0
_0802686C: .4byte gCurrentPinballGame
_08026870: .4byte 0x0000072A
_08026874: .4byte 0x00000729
_08026878:
	ldr r2, _080268BC @ =gCurrentPinballGame
	ldr r0, [r2]
	ldr r3, _080268C0 @ =0x00000729
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r4, _080268C4 @ =0x0000072A
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	subs r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #3
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	movs r1, #2
	strb r1, [r0]
_080268AC:
	ldr r0, [r2]
	ldr r1, _080268C8 @ =0x0000070E
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080268BC: .4byte gCurrentPinballGame
_080268C0: .4byte 0x00000729
_080268C4: .4byte 0x0000072A
_080268C8: .4byte 0x0000070E

	thumb_func_start sub_268CC
sub_268CC: @ 0x080268CC
	push {r4, r5, r6, r7, lr}
	ldr r5, _08026974 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r1, _08026978 @ =0x000006BC
	adds r0, r0, r1
	movs r6, #0
	strb r6, [r0]
	ldr r0, [r5]
	ldr r2, _0802697C @ =0x000006BD
	adds r0, r0, r2
	strb r6, [r0]
	ldr r7, _08026980 @ =gMain
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08026902
	ldr r0, [r5]
	ldr r1, _08026984 @ =0x000002BE
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r5]
	ldr r2, _08026988 @ =0x000002C2
	adds r0, r0, r2
	strb r6, [r0]
	ldr r0, [r5]
	adds r1, #2
	adds r0, r0, r1
	strh r6, [r0]
_08026902:
	ldr r0, [r5]
	ldr r2, _0802698C @ =0x000006BE
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xd8
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r4, #0
	strh r6, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r2, _08026990 @ =0x000006C4
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r7, #0x44]
	ldr r0, [r0, #0x34]
	strh r6, [r0]
	ldr r0, [r5]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	subs r2, #0xd1
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r5]
	ldr r2, _08026994 @ =0x00000736
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _08026998 @ =0x00000739
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _0802699C @ =0x0000073A
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _080269A0 @ =0x0000073B
	adds r0, r0, r1
	strb r4, [r0]
	bl sub_4D648
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026974: .4byte gCurrentPinballGame
_08026978: .4byte 0x000006BC
_0802697C: .4byte 0x000006BD
_08026980: .4byte gMain
_08026984: .4byte 0x000002BE
_08026988: .4byte 0x000002C2
_0802698C: .4byte 0x000006BE
_08026990: .4byte 0x000006C4
_08026994: .4byte 0x00000736
_08026998: .4byte 0x00000739
_0802699C: .4byte 0x0000073A
_080269A0: .4byte 0x0000073B

	thumb_func_start sub_269A4
sub_269A4: @ 0x080269A4
	push {r4, r5, lr}
	ldr r2, _080269F4 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r0, [r2]
	strh r3, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, [r2]
	adds r4, r2, #0
	adds r4, #0x6c
	movs r5, #0xe1
	lsls r5, r5, #4
	adds r0, r5, #0
	ldrh r1, [r4]
	adds r0, r0, r1
	ldr r5, _080269F8 @ =0x00000296
	adds r1, r2, r5
	strh r0, [r1]
	strh r3, [r4]
	ldr r0, _080269FC @ =0x00000724
	adds r2, r2, r0
	subs r0, #0x1c
	strh r0, [r2]
	ldr r1, _08026A00 @ =0x040000D4
	ldr r0, _08026A04 @ =gUnknown_081C0064
	str r0, [r1]
	ldr r0, _08026A08 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08026A0C @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080269F4: .4byte gCurrentPinballGame
_080269F8: .4byte 0x00000296
_080269FC: .4byte 0x00000724
_08026A00: .4byte 0x040000D4
_08026A04: .4byte gUnknown_081C0064
_08026A08: .4byte 0x05000180
_08026A0C: .4byte 0x80000010

	thumb_func_start sub_26A10
sub_26A10: @ 0x08026A10
	push {r4, r5, r6, lr}
	ldr r4, _08026A68 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026A4C
	ldr r3, _08026A6C @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08026A4C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _08026A4C
	bl m4aMPlayAllStop
	movs r0, 0x13 @ =MUS_END_OF_BALL2
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #6
	strb r1, [r0, #0x17]
_08026A4C:
	ldr r1, _08026A68 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #7
	bls _08026A5E
	b _08026E9E
_08026A5E:
	lsls r0, r0, #2
	ldr r1, _08026A70 @ =_08026A74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026A68: .4byte gCurrentPinballGame
_08026A6C: .4byte 0x00000296
_08026A70: .4byte _08026A74
_08026A74: @ jump table
	.4byte _08026A94 @ case 0
	.4byte _08026AC4 @ case 1
	.4byte _08026C10 @ case 2
	.4byte _08026C68 @ case 3
	.4byte _08026C88 @ case 4
	.4byte _08026CC0 @ case 5
	.4byte _08026E5C @ case 6
	.4byte _08026E84 @ case 7
_08026A94:
	ldr r0, _08026ABC @ =gMain
	ldrb r2, [r0, #0xf]
	cmp r2, #0
	bne _08026AAE
	ldr r0, [r5]
	ldrb r1, [r0, #0x17]
	adds r1, #1
	strb r1, [r0, #0x17]
	ldr r0, [r5]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	str r2, [r0]
_08026AAE:
	ldr r0, [r5]
	ldr r2, _08026AC0 @ =0x000006BC
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	b _08026E9E
	.align 2, 0
_08026ABC: .4byte gMain
_08026AC0: .4byte 0x000006BC
_08026AC4:
	movs r0, #4
	movs r1, #0
	bl sub_1C7F4
	ldr r4, _08026B5C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0x23
	bne _08026ADC
	movs r0, 0x17 @ =MUS_TRAVEL_MODE
	bl m4aSongNumStart
_08026ADC:
	ldr r1, [r4]
	ldr r3, _08026B60 @ =0x000006BC
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026B1E
	ldrb r0, [r1, #0x17]
	adds r0, #1
	movs r5, #0
	strb r0, [r1, #0x17]
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0x22
	bhi _08026B02
	movs r0, 0x17 @ =MUS_TRAVEL_MODE
	bl m4aSongNumStart
_08026B02:
	ldr r0, [r4]
	ldr r1, _08026B64 @ =0x000006BD
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _08026B68 @ =0x000006BE
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r0, r0, r3
	strh r5, [r0]
_08026B1E:
	ldr r5, _08026B5C @ =gCurrentPinballGame
	ldr r6, [r5]
	ldrh r4, [r6, #0x18]
	adds r0, r4, #0
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __udivsi3
	adds r4, #1
	movs r3, #0
	strh r4, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _08026B74
	ldr r1, _08026B6C @ =0x00000736
	adds r0, r6, r1
	strb r3, [r0]
	ldr r0, [r5]
	ldr r2, _08026B70 @ =0x00000737
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r5]
	adds r1, #2
	adds r0, r0, r1
	strb r3, [r0]
	b _08026BD8
	.align 2, 0
_08026B5C: .4byte gCurrentPinballGame
_08026B60: .4byte 0x000006BC
_08026B64: .4byte 0x000006BD
_08026B68: .4byte 0x000006BE
_08026B6C: .4byte 0x00000736
_08026B70: .4byte 0x00000737
_08026B74:
	cmp r2, #1
	bne _08026B9C
	ldr r0, _08026B94 @ =0x00000736
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _08026B98 @ =0x00000737
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r5]
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r0, r0, r2
	strb r3, [r0]
	b _08026BD8
	.align 2, 0
_08026B94: .4byte 0x00000736
_08026B98: .4byte 0x00000737
_08026B9C:
	cmp r2, #2
	bne _08026BC0
	ldr r3, _08026BBC @ =0x00000736
	adds r0, r6, r3
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	movs r1, #0xe7
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	b _08026BD8
	.align 2, 0
_08026BBC: .4byte 0x00000736
_08026BC0:
	ldr r2, _08026C04 @ =0x00000736
	adds r0, r6, r2
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _08026C08 @ =0x00000737
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r5]
	adds r2, #2
	adds r0, r0, r2
	strb r1, [r0]
_08026BD8:
	ldr r0, [r5]
	ldr r3, _08026C04 @ =0x00000736
	adds r1, r0, r3
	ldrb r1, [r1]
	ldr r2, _08026C0C @ =0x00000739
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r3, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	b _08026E9E
	.align 2, 0
_08026C04: .4byte 0x00000736
_08026C08: .4byte 0x00000737
_08026C0C: .4byte 0x00000739
_08026C10:
	bl sub_219A8
	ldr r5, _08026C5C @ =gCurrentPinballGame
	ldr r0, [r5]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r4, #0
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r2, _08026C60 @ =0x00000736
	adds r1, r0, r2
	strb r4, [r1]
	ldr r3, _08026C64 @ =0x00000739
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r5]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	adds r3, #1
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r5]
	b _08026E72
	.align 2, 0
_08026C5C: .4byte gCurrentPinballGame
_08026C60: .4byte 0x00000736
_08026C64: .4byte 0x00000739
_08026C68:
	bl sub_219EC
	ldr r0, _08026C84 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _08026C80
	b _08026E9E
_08026C80:
	b _08026E72
	.align 2, 0
_08026C84: .4byte gCurrentPinballGame
_08026C88:
	ldr r0, [r5]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r1, r0, r3
	str r2, [r1]
	ldr r1, _08026CBC @ =0x000006EC
	adds r0, r0, r1
	movs r1, #0x2f
	strb r1, [r0]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	b _08026E9E
	.align 2, 0
_08026CBC: .4byte 0x000006EC
_08026CC0:
	ldr r4, _08026D34 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x91
	beq _08026CCC
	b _08026DC6
_08026CCC:
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r2, _08026D38 @ =0x000006EC
	adds r1, r1, r2
	movs r0, #0x2f
	strb r0, [r1]
	movs r0, #7
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08026D3C @ =gMain
	ldrh r1, [r0, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08026D92
	ldr r0, [r4]
	movs r1, #0x90
	strh r1, [r0, #0x28]
	bl m4aMPlayAllStop
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _08026D80
	adds r1, r2, #0
	adds r1, #0x34
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r3, _08026D40 @ =0x000006BC
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08026D44
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r1, [r0]
	subs r0, #1
	b _08026D4A
	.align 2, 0
_08026D34: .4byte gCurrentPinballGame
_08026D38: .4byte 0x000006EC
_08026D3C: .4byte gMain
_08026D40: .4byte 0x000006BC
_08026D44:
	ldrb r1, [r1]
	adds r0, r2, #0
	adds r0, #0x32
_08026D4A:
	strb r1, [r0]
	ldr r6, _08026D7C @ =gCurrentPinballGame
	ldr r5, [r6]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #1
	movs r1, #6
	bl __modsi3
	adds r5, #0x33
	strb r0, [r5]
	ldr r5, [r6]
	adds r4, #2
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	adds r5, #0x34
	strb r0, [r5]
	ldr r1, [r6]
	adds r1, #0x36
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08026DC6
	.align 2, 0
_08026D7C: .4byte gCurrentPinballGame
_08026D80:
	adds r1, r2, #0
	adds r1, #0x32
	movs r0, #6
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x36
	movs r1, #0
	strb r1, [r0]
	b _08026DC6
_08026D92:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08026DC6
	bl m4aMPlayAllStop
	movs r0, 0x66 @=SE_UNKNOWN_0x66
	bl m4aSongNumStart
	ldr r1, [r4]
	movs r0, #0x3c
	strh r0, [r1, #0x28]
	movs r0, #6
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r2, _08026E14 @ =0x00000714
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08026DC6
	ldr r3, _08026E18 @ =0x000006EE
	adds r1, r1, r3
	movs r0, #0x78
	strh r0, [r1]
_08026DC6:
	ldr r0, _08026E1C @ =gCurrentPinballGame
	ldr r3, [r0]
	ldrh r4, [r3, #0x28]
	adds r2, r4, #0
	adds r5, r0, #0
	cmp r2, #0x82
	bne _08026E3A
	adds r0, r4, #1
	strh r0, [r3, #0x28]
	ldrh r1, [r3, #0x18]
	ldr r0, _08026E20 @ =0x000001E9
	cmp r1, r0
	bhi _08026E2C
	bl sub_2E094
	ldr r5, [r5]
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _08026DF8
	ldrh r1, [r5, #0x18]
	ldr r0, _08026E24 @ =0x000001AB
	cmp r1, r0
	bls _08026DF8
	adds r0, #1
	strh r0, [r5, #0x18]
_08026DF8:
	ldr r0, _08026E1C @ =gCurrentPinballGame
	ldr r3, [r0]
	ldrh r2, [r3, #0x18]
	movs r1, #0xc5
	lsls r1, r1, #1
	adds r5, r0, #0
	cmp r2, r1
	bne _08026E30
	movs r0, #1
	strb r0, [r3, #0x1c]
	ldr r1, [r5]
	ldr r0, _08026E28 @ =0x0007A120
	str r0, [r1, #0x3c]
	b _08026E30
	.align 2, 0
_08026E14: .4byte 0x00000714
_08026E18: .4byte 0x000006EE
_08026E1C: .4byte gCurrentPinballGame
_08026E20: .4byte 0x000001E9
_08026E24: .4byte 0x000001AB
_08026E28: .4byte 0x0007A120
_08026E2C:
	movs r0, #0x78
	strh r0, [r3, #0x28]
_08026E30:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	b _08026E9E
_08026E3A:
	cmp r2, #0
	bne _08026E9E
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	ldr r0, [r5]
	strh r2, [r0, #0x18]
	ldr r2, _08026E58 @ =0x0000062C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _08026E9E
	adds r0, #1
	strb r0, [r1]
	b _08026E9E
	.align 2, 0
_08026E58: .4byte 0x0000062C
_08026E5C:
	bl sub_219EC
	ldr r0, _08026E7C @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r0, #0
	strh r0, [r1]
	bl sub_268CC
	ldr r0, _08026E80 @ =gCurrentPinballGame
	ldr r1, [r0]
_08026E72:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	b _08026E9E
	.align 2, 0
_08026E7C: .4byte gMain
_08026E80: .4byte gCurrentPinballGame
_08026E84:
	ldr r1, [r5]
	ldrh r0, [r1, #0x18]
	adds r4, r0, #0
	cmp r4, #0
	beq _08026E94
	subs r0, #1
	strh r0, [r1, #0x18]
	b _08026E9E
_08026E94:
	movs r0, #1
	bl sub_19B64
	ldr r0, [r5]
	strb r4, [r0, #0x17]
_08026E9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_26EA4
sub_26EA4: @ 0x08026EA4
	push {r4, r5, r6, lr}
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, _08026EE0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08026EE4 @ =0x000006C4
	adds r1, r1, r2
	movs r2, #0
	strb r2, [r1]
	adds r6, r0, #0
	ldr r5, _08026EE8 @ =0x0000071D
_08026EBE:
	ldr r0, _08026EE0 @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r0, _08026EEC @ =0x00000723
	adds r1, r3, r0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, #0
	cmp r2, r1
	bge _08026EF0
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _08026EF6
	.align 2, 0
_08026EE0: .4byte gCurrentPinballGame
_08026EE4: .4byte 0x000006C4
_08026EE8: .4byte 0x0000071D
_08026EEC: .4byte 0x00000723
_08026EF0:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_08026EF6:
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08026EBE
	ldr r0, _08026F30 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x34]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	ldr r1, _08026F34 @ =0x000005F3
	adds r0, r0, r1
	strb r2, [r0]
	bl sub_4D648
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026F30: .4byte gMain
_08026F34: .4byte 0x000005F3

	thumb_func_start sub_26F38
sub_26F38: @ 0x08026F38
	push {r4, r5, r6, r7, lr}
	ldr r4, _08026F88 @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r0, [r4]
	movs r6, #0
	strh r3, [r0, #0x18]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r5, [r4]
	adds r2, r5, #0
	adds r2, #0x6c
	movs r7, #0xe1
	lsls r7, r7, #5
	adds r0, r7, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	ldr r7, _08026F8C @ =0x00000296
	adds r1, r5, r7
	strh r0, [r1]
	strh r3, [r2]
	ldr r0, _08026F90 @ =0x00000724
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0xd
	bne _08026F94
	subs r7, #0x37
	adds r0, r5, r7
	strb r6, [r0]
	b _08026FFC
	.align 2, 0
_08026F88: .4byte gCurrentPinballGame
_08026F8C: .4byte 0x00000296
_08026F90: .4byte 0x00000724
_08026F94:
	cmp r0, #0x58
	bne _08026FC4
	ldr r0, _08026FAC @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08026FB4
	ldr r0, _08026FB0 @ =0x0000025F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FAC: .4byte gMain
_08026FB0: .4byte 0x0000025F
_08026FB4:
	ldr r2, _08026FC0 @ =0x0000025F
	adds r1, r5, r2
	movs r0, #7
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FC0: .4byte 0x0000025F
_08026FC4:
	cmp r0, #0xaf
	bne _08026FD8
	ldr r7, _08026FD4 @ =0x0000025F
	adds r1, r5, r7
	movs r0, #3
	strb r0, [r1]
	b _08026FFC
	.align 2, 0
_08026FD4: .4byte 0x0000025F
_08026FD8:
	ldr r2, _08027054 @ =gSpeciesInfo
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #0x14]
	subs r0, #1
	ldr r2, _08027058 @ =0x0000025F
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08026FFC
	strb r6, [r1]
_08026FFC:
	ldr r1, _0802705C @ =0x040000D4
	ldr r0, _08027060 @ =gUnknown_081C0064
	str r0, [r1]
	ldr r0, _08027064 @ =0x05000180
	str r0, [r1, #4]
	ldr r0, _08027068 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r4]
	ldr r1, _0802706C @ =0x0000072E
	adds r0, r0, r1
	movs r3, #0
	strb r3, [r0]
	ldr r0, [r4]
	ldr r2, _08027070 @ =0x0000072A
	adds r0, r0, r2
	strb r3, [r0]
	ldr r0, [r4]
	ldr r7, _08027074 @ =0x00000252
	adds r1, r0, r7
	movs r2, #0
	strh r3, [r1]
	ldr r1, _08027078 @ =0x0000025E
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r7, #0x19
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #0xe
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	ldr r2, _0802707C @ =0x0000026E
	adds r0, r0, r2
	strh r3, [r0]
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027054: .4byte gSpeciesInfo
_08027058: .4byte 0x0000025F
_0802705C: .4byte 0x040000D4
_08027060: .4byte gUnknown_081C0064
_08027064: .4byte 0x05000180
_08027068: .4byte 0x80000010
_0802706C: .4byte 0x0000072E
_08027070: .4byte 0x0000072A
_08027074: .4byte 0x00000252
_08027078: .4byte 0x0000025E
_0802707C: .4byte 0x0000026E

	thumb_func_start sub_27080
sub_27080: @ 0x08027080
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _080270E0 @ =gCurrentPinballGame
	ldr r1, [r4]
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080270C0
	ldr r3, _080270E4 @ =0x00000296
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080270C0
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #7
	bgt _080270C0
	bl m4aMPlayAllStop
	movs r0, 0x13 @ =MUS_END_OF_BALL2
	bl m4aSongNumStart
	ldr r0, [r4]
	movs r1, #0xc8
	strh r1, [r0, #0x18]
	movs r1, #8
	strb r1, [r0, #0x17]
_080270C0:
	ldr r1, _080270E0 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r1, #0
	cmp r0, #0xa
	bls _080270D4
	bl _080278E6
_080270D4:
	lsls r0, r0, #2
	ldr r1, _080270E8 @ =_080270EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080270E0: .4byte gCurrentPinballGame
_080270E4: .4byte 0x00000296
_080270E8: .4byte _080270EC
_080270EC: @ jump table
	.4byte _08027118 @ case 0
	.4byte _08027390 @ case 1
	.4byte _08027414 @ case 2
	.4byte _08027424 @ case 3
	.4byte _08027452 @ case 4
	.4byte _08027474 @ case 5
	.4byte _080274B4 @ case 6
	.4byte _08027506 @ case 7
	.4byte _080277D8 @ case 8
	.4byte _0802789C @ case 9
	.4byte _080278B0 @ case 10
_08027118:
	ldr r0, [r6]
	movs r5, #0x94
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08027208
	movs r2, #0
	adds r3, r6, #0
	ldr r4, _080271F4 @ =0x00000263
_0802712C:
	ldr r1, [r3]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802712C
	bl Random
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #5
	bl __umodsi3
	ldr r5, _080271FC @ =gCurrentPinballGame
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _080271F4 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	movs r6, #0x98
	lsls r6, r6, #2
	adds r2, r2, r6
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #6
	bgt _0802718E
	adds r3, r4, #0
_08027176:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #6
	ble _08027176
_0802718E:
	bl Random
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r2, r0, r1
	movs r0, #3
	ands r2, r0
	ldr r4, _080271FC @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r3, _080271F4 @ =0x00000263
	adds r0, r1, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r7, _08027200 @ =0x00000261
	adds r1, r1, r7
	strb r0, [r1]
	lsls r1, r2, #0x10
	cmp r2, #5
	bgt _080271CC
_080271B4:
	ldr r0, [r4]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #5
	ble _080271B4
_080271CC:
	bl Random
	ldr r1, _080271F8 @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #3
	bl __umodsi3
	ldr r1, _080271FC @ =gCurrentPinballGame
	ldr r2, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, _080271F4 @ =0x00000263
	adds r1, r2, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	ldr r5, _08027204 @ =0x00000262
	adds r2, r2, r5
	strb r0, [r2]
	b _08027362
	.align 2, 0
_080271F4: .4byte 0x00000263
_080271F8: .4byte gMain
_080271FC: .4byte gCurrentPinballGame
_08027200: .4byte 0x00000261
_08027204: .4byte 0x00000262
_08027208:
	movs r2, #0
	adds r3, r6, #0
	ldr r4, _08027378 @ =0x00000263
_0802720E:
	ldr r1, [r3]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r4
	adds r1, r1, r0
	strb r2, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802720E
	bl Random
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	ldr r5, _08027380 @ =gCurrentPinballGame
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	movs r6, #0x98
	lsls r6, r6, #2
	adds r2, r2, r6
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #6
	bgt _08027270
	adds r3, r4, #0
_08027258:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #6
	ble _08027258
_08027270:
	bl Random
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #7
	bl __umodsi3
	ldr r5, _08027380 @ =gCurrentPinballGame
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	ldr r7, _08027384 @ =0x00000261
	adds r2, r2, r7
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #5
	bgt _080272B8
	adds r3, r4, #0
_080272A0:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #5
	ble _080272A0
_080272B8:
	bl Random
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #6
	bl __umodsi3
	ldr r5, _08027380 @ =gCurrentPinballGame
	ldr r2, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	ldr r4, _08027378 @ =0x00000263
	adds r1, r2, r4
	adds r1, r1, r3
	ldrb r1, [r1]
	ldr r3, _08027388 @ =0x00000262
	adds r2, r2, r3
	strb r1, [r2]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, #4
	bgt _08027300
	adds r3, r4, #0
_080272E8:
	ldr r0, [r5]
	asrs r1, r1, #0x10
	adds r0, r0, r3
	adds r2, r0, r1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #4
	ble _080272E8
_08027300:
	ldr r0, _0802737C @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _08027362
	ldr r1, _08027380 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r5, _0802738C @ =0x00000283
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08027362
	movs r2, #0
	adds r5, r1, #0
_0802731A:
	ldr r0, [r5]
	lsls r1, r2, #0x10
	asrs r4, r1, #0x10
	movs r6, #0x98
	lsls r6, r6, #2
	adds r0, r0, r6
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _08027356
	bl Random
	ldr r1, _0802737C @ =gMain
	ldr r1, [r1, #0x4c]
	adds r0, r0, r1
	movs r1, #5
	bl __umodsi3
	ldr r1, [r5]
	adds r2, r1, r6
	adds r2, r2, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r7, _08027378 @ =0x00000263
	adds r1, r1, r7
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
_08027356:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0802731A
_08027362:
	ldr r0, _08027380 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0x94
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_08027378: .4byte 0x00000263
_0802737C: .4byte gMain
_08027380: .4byte gCurrentPinballGame
_08027384: .4byte 0x00000261
_08027388: .4byte 0x00000262
_0802738C: .4byte 0x00000283
_08027390:
	ldr r1, [r6]
	ldr r2, _080273FC @ =0x0000026B
	adds r0, r1, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r1, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08027400 @ =0x0000025E
	adds r1, r1, r2
	strb r0, [r1]
	ldr r3, [r6]
	ldr r5, _08027404 @ =gUnknown_086ACFA0
	adds r2, r3, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #2
	ldr r4, _08027408 @ =gMain
	ldrb r0, [r4, #4]
	lsls r0, r0, #5
	adds r1, r1, r0
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r3, r6
	strh r1, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	ldrb r1, [r4, #4]
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r5
	ldrh r1, [r0, #2]
	ldr r7, _0802740C @ =0x0000025A
	adds r0, r3, r7
	strh r1, [r0]
	ldr r0, _08027410 @ =0x0000026E
	adds r1, r3, r0
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0xa0
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1]
	ldrb r0, [r3, #0x17]
	adds r0, #1
	strb r0, [r3, #0x17]
	b _080278E6
	.align 2, 0
_080273FC: .4byte 0x0000026B
_08027400: .4byte 0x0000025E
_08027404: .4byte gUnknown_086ACFA0
_08027408: .4byte gMain
_0802740C: .4byte 0x0000025A
_08027410: .4byte 0x0000026E
_08027414:
	bl sub_278F4
	ldr r0, _08027420 @ =gCurrentPinballGame
	ldr r1, [r0]
	b _080277B8
	.align 2, 0
_08027420: .4byte gCurrentPinballGame
_08027424:
	ldr r0, [r6]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #7
	bhi _0802743A
	b _08027684
_0802743A:
	bl sub_219A8
	ldr r0, [r6]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
_08027452:
	bl sub_219EC
	ldr r0, _08027470 @ =gCurrentPinballGame
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _0802746A
	b _080278E6
_0802746A:
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_08027470: .4byte gCurrentPinballGame
_08027474:
	ldr r0, [r6]
	movs r3, #0xa5
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r6]
	movs r4, #0xb3
	lsls r4, r4, #3
	adds r1, r0, r4
	ldrh r1, [r1]
	movs r7, #0xb4
	lsls r7, r7, #3
	adds r0, r0, r7
	strh r1, [r0]
	movs r0, #1
	bl sub_31CF8
	ldr r1, [r6]
	adds r4, r1, r4
	ldrh r2, [r4]
	ldr r3, _080274B0 @ =0x000005A2
	adds r0, r1, r3
	strh r2, [r0]
	strh r5, [r1, #0x18]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_080274B0: .4byte 0x000005A2
_080274B4:
	ldr r1, [r6]
	ldrh r0, [r1, #0x28]
	cmp r0, #0x94
	beq _080274BE
	b _080278E6
_080274BE:
	adds r0, #1
	strh r0, [r1, #0x28]
	ldr r0, _080274F0 @ =gMain
	movs r5, #0xc5
	lsls r5, r5, #4
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080274F4
	movs r7, #0xaf
	lsls r7, r7, #2
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0x4f
	bhi _080274DE
	b _080278E6
_080274DE:
	bl sub_2D204
	ldr r1, [r6]
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #6
	beq _080274EE
	b _080278E6
_080274EE:
	b _08027682
	.align 2, 0
_080274F0: .4byte gMain
_080274F4:
	bl sub_2D204
	ldr r1, [r6]
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #6
	beq _08027504
	b _080278E6
_08027504:
	b _08027682
_08027506:
	ldr r3, [r6]
	ldrh r0, [r3, #0x28]
	adds r1, r0, #0
	cmp r1, #0x94
	beq _08027512
	b _080276BA
_08027512:
	adds r0, #1
	strh r0, [r3, #0x28]
	ldrh r1, [r3, #0x18]
	ldr r0, _08027530 @ =0x00000117
	cmp r1, r0
	bls _08027520
	b _080276B4
_08027520:
	cmp r1, #0
	bne _08027534
	bl sub_2312C
	movs r0, 0x12 @ =MUS_SUCCESS2
	bl m4aSongNumStart
	b _0802758E
	.align 2, 0
_08027530: .4byte 0x00000117
_08027534:
	bl sub_23300
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xe5
	bhi _08027550
	movs r0, #0x84
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0x96
	bne _08027550
	subs r0, #1
	strh r0, [r1]
_08027550:
	ldr r4, _0802768C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	movs r0, #0x87
	lsls r0, r0, #1
	cmp r1, r0
	bne _08027570
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	ldr r1, _08027690 @ =0x000006C4
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
_08027570:
	ldr r1, [r4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _0802757C
	movs r0, #0xb5
	strh r0, [r1, #0x18]
_0802757C:
	ldr r1, [r4]
	ldrh r0, [r1, #0x18]
	cmp r0, #0xb4
	bne _0802758E
	movs r0, #1
	strb r0, [r1, #0x1c]
	ldr r1, [r4]
	ldr r0, _08027694 @ =0x004C4B40
	str r0, [r1, #0x3c]
_0802758E:
	ldr r0, _0802768C @ =gCurrentPinballGame
	ldr r2, [r0]
	ldrh r1, [r2, #0x18]
	adds r6, r0, #0
	cmp r1, #0x1d
	bhi _08027600
	ldr r1, _08027698 @ =gMain
	movs r0, #1
	strh r0, [r1, #0x2c]
	ldrh r1, [r2, #0x18]
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	movs r2, #0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r5, _0802769C @ =gUnknown_03005C00
	mov r8, r5
	cmp r2, r0
	bgt _080275F0
	adds r7, r0, #0
	movs r4, #0xc1
	lsls r4, r4, #8
_080275BE:
	movs r0, #2
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_080275C4:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xb
	ble _080275C4
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _080275BE
_080275F0:
	ldr r1, _080276A0 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _080276A4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _080276A8 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08027600:
	ldr r0, [r6]
	ldrh r0, [r0, #0x18]
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _08027680
	movs r2, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, _0802769C @ =gUnknown_03005C00
	mov r8, r3
	cmp r2, r0
	bgt _08027654
	mov r5, r8
	ldr r4, _080276AC @ =0x000001FF
	adds r7, r0, #0
_08027622:
	movs r0, #2
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
_08027628:
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0xf
	lsls r0, r0, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xb
	ble _08027628
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _08027622
_08027654:
	ldr r1, _080276A0 @ =0x040000D4
	mov r2, r8
	str r2, [r1]
	ldr r0, _080276A4 @ =0x06002000
	str r0, [r1, #4]
	ldr r0, _080276A8 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r6]
	ldrh r1, [r0, #0x18]
	ldr r0, _080276B0 @ =0x0000010D
	cmp r1, r0
	bne _08027680
	ldr r0, _08027698 @ =gMain
	movs r1, #0
	strh r1, [r0, #0x2c]
	ldrh r2, [r0, #0x38]
	strh r1, [r0, #0x38]
	ldrh r2, [r0, #0x3c]
	strh r1, [r0, #0x3c]
	ldrh r2, [r0, #0x3a]
	strh r1, [r0, #0x3a]
_08027680:
	ldr r1, [r6]
_08027682:
	ldrh r0, [r1, #0x18]
_08027684:
	adds r0, #1
	strh r0, [r1, #0x18]
	b _080278E6
	.align 2, 0
_0802768C: .4byte gCurrentPinballGame
_08027690: .4byte 0x000006C4
_08027694: .4byte 0x004C4B40
_08027698: .4byte gMain
_0802769C: .4byte gUnknown_03005C00
_080276A0: .4byte 0x040000D4
_080276A4: .4byte 0x06002000
_080276A8: .4byte 0x80000400
_080276AC: .4byte 0x000001FF
_080276B0: .4byte 0x0000010D
_080276B4:
	movs r0, #0x28
	strh r0, [r3, #0x28]
	b _080278E6
_080276BA:
	cmp r1, #0x18
	beq _080276C0
	b _080278E6
_080276C0:
	ldr r5, _080277C0 @ =0x00000723
	adds r0, r3, r5
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027748
	ldr r2, _080277C4 @ =0x00000721
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, [r6]
	adds r1, r0, r5
	ldrb r1, [r1]
	ldr r3, _080277C8 @ =0x00000722
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	adds r2, r0, r2
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldr r7, _080277CC @ =0x0000071D
	adds r0, r0, r7
	adds r0, r0, r1
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r6]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r3, #0x78
	strb r3, [r0]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r5
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027748
	adds r7, #5
	adds r0, r1, r7
	strb r2, [r0]
	ldr r0, [r6]
	adds r2, r7, #0
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r7, #5
	adds r0, r0, r7
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r6]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, [r6]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08027748:
	ldr r2, [r6]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0x2a
	bne _08027780
	adds r3, #0x58
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r5, _080277D0 @ =0x0000062B
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _0802776E
	adds r0, #1
	strb r0, [r1]
_0802776E:
	ldr r1, [r6]
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0xf
	bne _08027780
	ldr r7, _080277D4 @ =0x00000286
	adds r1, r1, r7
	movs r0, #0x5c
	strh r0, [r1]
_08027780:
	ldr r2, [r6]
	movs r0, #0xbe
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0802779E
	ldr r3, _080277D4 @ =0x00000286
	adds r1, r2, r3
	movs r0, #0x5c
	strh r0, [r1]
_0802779E:
	ldr r0, [r6]
	ldr r5, _080277D0 @ =0x0000062B
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080277AE
	adds r0, #1
	strb r0, [r1]
_080277AE:
	ldr r1, [r6]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, [r6]
_080277B8:
	movs r0, #0
	strh r0, [r1, #0x18]
	b _080278E6
	.align 2, 0
_080277C0: .4byte 0x00000723
_080277C4: .4byte 0x00000721
_080277C8: .4byte 0x00000722
_080277CC: .4byte 0x0000071D
_080277D0: .4byte 0x0000062B
_080277D4: .4byte 0x00000286
_080277D8:
	ldr r6, _0802787C @ =gMain
	ldr r0, [r6, #0x44]
	adds r0, #0x80
	ldr r4, [r0]
	movs r7, #8
	adds r7, r7, r4
	ldr r5, _08027880 @ =gOamBuffer
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	adds r1, r1, r5
	movs r0, #2
	ldrsh r2, [r7, r0]
	ldr r3, _08027884 @ =0x000001FF
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #2]
	ldr r0, _08027888 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r0, [r7, #4]
	subs r0, #0x38
	movs r5, #0
	strb r0, [r1]
	ldr r0, [r6, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	movs r7, #0
	mov r8, r7
	strh r5, [r0]
	bl sub_278F4
	ldr r0, [r6, #0x44]
	adds r0, #0xa0
	ldr r0, [r0]
	strh r5, [r0]
	ldr r4, _0802788C @ =gCurrentPinballGame
	ldr r0, [r4]
	adds r0, #0xe4
	mov r1, r8
	strb r1, [r0]
	bl sub_219EC
	ldr r0, [r6, #0x44]
	ldr r0, [r0, #0x34]
	strh r5, [r0]
	ldr r0, [r4]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	movs r3, #0xda
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r5, [r0]
	ldr r5, _08027890 @ =0x000001A5
	adds r0, r1, r5
	mov r6, r8
	strb r6, [r0]
	ldr r1, [r4]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	strb r0, [r1, #0x17]
	ldr r1, [r4]
	ldr r7, _08027894 @ =0x00000714
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080278E6
	ldr r0, _08027898 @ =0x000006EE
	adds r1, r1, r0
	movs r0, #0x78
	strh r0, [r1]
	b _080278E6
	.align 2, 0
_0802787C: .4byte gMain
_08027880: .4byte gOamBuffer
_08027884: .4byte 0x000001FF
_08027888: .4byte 0xFFFFFE00
_0802788C: .4byte gCurrentPinballGame
_08027890: .4byte 0x000001A5
_08027894: .4byte 0x00000714
_08027898: .4byte 0x000006EE
_0802789C:
	bl sub_26EA4
	ldr r0, _080278AC @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrb r0, [r1, #0x17]
	adds r0, #1
	b _080278E4
	.align 2, 0
_080278AC: .4byte gCurrentPinballGame
_080278B0:
	ldr r1, [r6]
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _080278BE
	subs r0, #1
	strh r0, [r1, #0x18]
	b _080278E6
_080278BE:
	ldr r2, _080278D4 @ =0x0000071F
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080278D8
	movs r0, #3
	bl sub_19B64
	b _080278DE
	.align 2, 0
_080278D4: .4byte 0x0000071F
_080278D8:
	movs r0, #1
	bl sub_19B64
_080278DE:
	ldr r0, _080278F0 @ =gCurrentPinballGame
	ldr r1, [r0]
	movs r0, #0
_080278E4:
	strb r0, [r1, #0x17]
_080278E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080278F0: .4byte gCurrentPinballGame

	thumb_func_start sub_278F4
sub_278F4: @ 0x080278F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080279C4 @ =gMain
	mov sl, r0
	ldr r0, [r0, #0x4c]
	movs r1, #0x4b
	bl __umodsi3
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sl
	ldr r2, [r1, #0x44]
	adds r0, r2, #0
	adds r0, #0x80
	ldr r7, [r0]
	ldr r6, _080279C8 @ =gCurrentPinballGame
	ldr r3, [r6]
	ldr r0, _080279CC @ =0x0000026E
	mov sb, r0
	adds r0, r3, r0
	ldrh r1, [r0]
	cmp r1, #0
	bne _08027932
	b _08027B74
_08027932:
	adds r0, r2, #0
	adds r0, #0xa0
	ldr r7, [r0]
	cmp r1, #0x50
	bne _0802798C
	adds r1, r3, #0
	adds r1, #0xe4
	movs r5, #0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _080279D0 @ =0x040000D4
	ldr r1, _080279D4 @ =gUnknown_086AD474
	ldr r3, [r6]
	ldr r0, _080279D8 @ =0x0000025F
	adds r4, r3, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _080279DC @ =0x06015800
	str r0, [r2, #4]
	ldr r0, _080279E0 @ =0x80000E00
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #5
	ldr r1, _080279E4 @ =gUnknown_0815C4C4
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _080279E8 @ =0x050003E0
	str r0, [r2, #4]
	ldr r0, _080279EC @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _080279F0 @ =0x00000626
	adds r3, r3, r1
	strb r5, [r3]
	ldr r0, [r6]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r5, [r0]
_0802798C:
	ldr r0, [r6]
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0x3c
	bne _0802799E
	ldr r0, _080279F4 @ =gMPlayInfo_SE1
	ldr r1, _080279F8 @ =gUnknown_0869F58C
	bl MPlayStart
_0802799E:
	ldr r2, _080279FC @ =gUnknown_086AE0E6
	ldr r1, [r6]
	ldr r5, _080279F0 @ =0x00000626
	adds r3, r1, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r5, #2
	adds r1, r1, r5
	ldrh r2, [r1]
	cmp r0, r2
	ble _08027A00
	adds r0, r2, #1
	strh r0, [r1]
	b _08027A46
	.align 2, 0
_080279C4: .4byte gMain
_080279C8: .4byte gCurrentPinballGame
_080279CC: .4byte 0x0000026E
_080279D0: .4byte 0x040000D4
_080279D4: .4byte gUnknown_086AD474
_080279D8: .4byte 0x0000025F
_080279DC: .4byte 0x06015800
_080279E0: .4byte 0x80000E00
_080279E4: .4byte gUnknown_0815C4C4
_080279E8: .4byte 0x050003E0
_080279EC: .4byte 0x80000010
_080279F0: .4byte 0x00000626
_080279F4: .4byte gMPlayInfo_SE1
_080279F8: .4byte gUnknown_0869F58C
_080279FC: .4byte gUnknown_086AE0E6
_08027A00:
	movs r2, #1
	strh r2, [r1]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, [r6]
	ldr r3, _08027B48 @ =0x00000626
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x1d
	bne _08027A46
	movs r0, #0x1c
	strb r0, [r1]
	ldr r0, [r6]
	add r0, sb
	strh r2, [r0]
	mov r5, sl
	ldr r0, [r5, #0x44]
	adds r0, #0xa0
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, _08027B4C @ =gMPlayInfo_SE1
	ldr r1, _08027B50 @ =gUnknown_0869F5C8
	bl MPlayStart
	ldr r0, [r6]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_08027A46:
	ldr r3, _08027B54 @ =gCurrentPinballGame
	ldr r2, [r3]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r2, r6
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r0, #8
	strh r0, [r7, #2]
	ldr r1, _08027B58 @ =0x0000025A
	adds r0, r2, r1
	adds r2, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	adds r0, #8
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08027A7E
	ldr r0, _08027B5C @ =0x0000FFE2
	strh r0, [r7, #4]
_08027A7E:
	movs r2, #4
	ldrsh r0, [r7, r2]
	cmp r0, #0xc8
	ble _08027A8A
	movs r0, #0xc8
	strh r0, [r7, #4]
_08027A8A:
	movs r0, #0
	ldr r3, _08027B60 @ =gOamBuffer
	mov sl, r3
	ldr r5, _08027B64 @ =gUnknown_086B4202
	mov sb, r5
	ldr r6, _08027B54 @ =gCurrentPinballGame
	mov r8, r6
	ldr r1, _08027B48 @ =0x00000626
	mov ip, r1
_08027A9C:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	adds r0, #8
	adds r6, r7, r0
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, sl
	lsls r3, r4, #1
	adds r3, r3, r4
	mov r5, r8
	ldr r0, [r5]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r5, r3, #1
	mov r1, r8
	ldr r0, [r1]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2]
	adds r3, #2
	mov r5, r8
	ldr r0, [r5]
	add r0, ip
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r0, r0, r3
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r2, #2]
	ldrh r2, [r6]
	lsls r2, r2, #3
	add r2, sl
	ldrh r3, [r2, #2]
	lsls r1, r3, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _08027B68 @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldr r0, _08027B6C @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6]
	lsls r1, r1, #3
	add r1, sl
	ldrb r0, [r7, #4]
	ldrb r6, [r1]
	adds r0, r0, r6
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #4
	ble _08027A9C
	ldr r0, _08027B54 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08027B70 @ =0x0000026E
	adds r1, r1, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08027CE8
	.align 2, 0
_08027B48: .4byte 0x00000626
_08027B4C: .4byte gMPlayInfo_SE1
_08027B50: .4byte gUnknown_0869F5C8
_08027B54: .4byte gCurrentPinballGame
_08027B58: .4byte 0x0000025A
_08027B5C: .4byte 0x0000FFE2
_08027B60: .4byte gOamBuffer
_08027B64: .4byte gUnknown_086B4202
_08027B68: .4byte 0x000001FF
_08027B6C: .4byte 0xFFFFFE00
_08027B70: .4byte 0x0000026E
_08027B74:
	ldr r6, _08027CF8 @ =0x0000132C
	adds r0, r3, r6
	ldr r2, [r0]
	movs r1, #0x10
	ldrsh r0, [r2, r1]
	subs r0, #8
	movs r6, #0x96
	lsls r6, r6, #2
	adds r1, r3, r6
	movs r6, #0
	ldrsh r1, [r1, r6]
	subs r4, r0, r1
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	subs r0, #8
	ldr r2, _08027CFC @ =0x0000025A
	adds r1, r3, r2
	movs r6, #0
	ldrsh r1, [r1, r6]
	subs r5, r0, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	cmp r0, #0x51
	bgt _08027C38
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _08027BC4
	adds r2, #4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble _08027BD6
_08027BC4:
	cmp r1, #2
	bne _08027C38
	ldr r5, _08027D00 @ =0x0000025E
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	ble _08027C38
_08027BD6:
	ldr r4, _08027D04 @ =gCurrentPinballGame
	ldr r1, [r4]
	ldr r6, _08027D08 @ =0x0000026B
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08027C38
	ldr r0, _08027D0C @ =0x00002710
	str r0, [r1, #0x3c]
	ldr r0, _08027D10 @ =gMPlayInfo_SE1
	ldr r1, _08027D14 @ =gUnknown_0869F618
	bl MPlayStart
	ldr r1, [r4]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #0x17]
	ldr r0, [r4]
	adds r1, r0, r6
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r3, _08027D18 @ =0x0000071D
	adds r0, r0, r3
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, r1, r6
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08027D1C @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x80
	ldr r0, [r0]
	strh r2, [r0]
	ldr r0, [r4]
	adds r2, r0, r6
	movs r1, #0
	ldrsb r1, [r2, r1]
	cmp r1, #3
	bne _08027C38
	movs r0, #0
	strb r0, [r2]
	ldr r0, [r4]
	strb r1, [r0, #0x17]
_08027C38:
	ldr r3, _08027D04 @ =gCurrentPinballGame
	ldr r2, [r3]
	movs r5, #0x96
	lsls r5, r5, #2
	adds r0, r2, r5
	adds r1, r2, #0
	adds r1, #0x58
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	subs r0, #8
	strh r0, [r7, #2]
	ldr r6, _08027CFC @ =0x0000025A
	adds r0, r2, r6
	adds r2, #0x5a
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	subs r0, #8
	strh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x1e
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08027C70
	ldr r0, _08027D20 @ =0x0000FFE2
	strh r0, [r7, #4]
_08027C70:
	movs r1, #4
	ldrsh r0, [r7, r1]
	cmp r0, #0xc8
	ble _08027C7C
	movs r0, #0xc8
	strh r0, [r7, #4]
_08027C7C:
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _08027C8A
	movs r5, #0xe
	mov r8, r5
_08027C8A:
	ldr r2, _08027D24 @ =0x040000D4
	ldr r1, _08027D28 @ =gUnknown_086AD49C
	ldr r0, [r3]
	ldr r6, _08027D2C @ =0x0000025F
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r1, r1, #7
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08027D30 @ =0x060116C0
	str r0, [r2, #4]
	ldr r0, _08027D34 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r6, r7, #0
	adds r6, #8
	ldr r4, _08027D38 @ =gOamBuffer
	ldrh r2, [r7, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r5, #2
	ldrsh r1, [r6, r5]
	movs r3, #2
	ldrsh r0, [r7, r3]
	adds r1, r1, r0
	ldr r5, _08027D3C @ =0x000001FF
	adds r0, r5, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _08027D40 @ =0xFFFFFE00
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
_08027CE8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027CF8: .4byte 0x0000132C
_08027CFC: .4byte 0x0000025A
_08027D00: .4byte 0x0000025E
_08027D04: .4byte gCurrentPinballGame
_08027D08: .4byte 0x0000026B
_08027D0C: .4byte 0x00002710
_08027D10: .4byte gMPlayInfo_SE1
_08027D14: .4byte gUnknown_0869F618
_08027D18: .4byte 0x0000071D
_08027D1C: .4byte gMain
_08027D20: .4byte 0x0000FFE2
_08027D24: .4byte 0x040000D4
_08027D28: .4byte gUnknown_086AD49C
_08027D2C: .4byte 0x0000025F
_08027D30: .4byte 0x060116C0
_08027D34: .4byte 0x80000100
_08027D38: .4byte gOamBuffer
_08027D3C: .4byte 0x000001FF
_08027D40: .4byte 0xFFFFFE00

	thumb_func_start sub_27D44
sub_27D44: @ 0x08027D44
	push {r4, r5, r6, lr}
	ldr r4, _08027DC8 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r1, _08027DCC @ =0x000005A5
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08027DD0 @ =0x000005A9
	adds r0, r0, r2
	strb r1, [r0]
	ldr r2, _08027DD4 @ =gMain
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x48]
	movs r5, #0
	strh r1, [r0]
	ldr r0, [r2, #0x44]
	ldr r0, [r0, #0x30]
	strh r1, [r0]
	ldr r0, [r4]
	ldr r1, _08027DD8 @ =0x000005F2
	adds r0, r0, r1
	strb r5, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	ldr r2, _08027DDC @ =0x000006C4
	adds r0, r0, r2
	strb r5, [r0]
	bl sub_4D648
	movs r2, #0
	ldr r5, _08027DE0 @ =0x000006D3
	movs r3, #0xd
	adds r6, r4, #0
_08027D8E:
	ldr r1, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r5
	adds r1, r1, r0
	strb r3, [r1]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08027D8E
	movs r2, #0
	ldr r5, _08027DE4 @ =0x0000071D
_08027DAA:
	ldr r3, [r6]
	ldr r1, _08027DE8 @ =0x00000723
	adds r0, r3, r1
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r2, r0
	bge _08027DEC
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _08027DF2
	.align 2, 0
_08027DC8: .4byte gCurrentPinballGame
_08027DCC: .4byte 0x000005A5
_08027DD0: .4byte 0x000005A9
_08027DD4: .4byte gMain
_08027DD8: .4byte 0x000005F2
_08027DDC: .4byte 0x000006C4
_08027DE0: .4byte 0x000006D3
_08027DE4: .4byte 0x0000071D
_08027DE8: .4byte 0x00000723
_08027DEC:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_08027DF2:
	strb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r4, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08027DAA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	    