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
