#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_4C290
sub_4C290: @ 0x0804C290
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_28AE0
	bl sub_28BFC
	movs r1, #0
	ldr r0, _0804C3B8 @ =gCurrentPinballGame
	ldr r4, [r0]
	ldr r3, _0804C3BC @ =0x040000D4
	mov sb, r0
_0804C2AE:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r1, _0804C3C0 @ =0x000013BC
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	lsls r0, r0, #9
	ldr r1, _0804C3C4 @ =gUnknown_083FE44C
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #9
	ldr r5, _0804C3C8 @ =0x06010000
	adds r0, r0, r5
	str r0, [r3, #4]
	ldr r0, _0804C3CC @ =0x80000100
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0804C2AE
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0804C3D0 @ =0x0000132C
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	ldr r2, _0804C3BC @ =0x040000D4
	lsrs r0, r0, #0xc
	lsls r0, r0, #7
	ldr r1, _0804C3D4 @ =gUnknown_083BB16C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C3D8 @ =0x06010400
	str r0, [r2, #4]
	ldr r0, _0804C3DC @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
	ldr r5, _0804C3E0 @ =gUnknown_084C07EC
	ldr r6, _0804C3E4 @ =gUnknown_084FA48C
	ldr r7, _0804C3E8 @ =gUnknown_084C00EC
	adds r3, r2, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r2, _0804C3EC @ =0x00000744
	adds r4, r0, r2
_0804C320:
	lsls r2, r1, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	adds r0, r0, r5
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r1, _0804C3F0 @ =0x06010480
	adds r0, r0, r1
	str r0, [r3, #4]
	ldr r0, _0804C3F4 @ =0x800000C0
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #1
	ble _0804C320
	mov r2, sb
	ldr r0, [r2]
	ldr r3, _0804C3F8 @ =0x000001E5
	adds r0, r0, r3
	ldr r2, _0804C3BC @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r6
	str r0, [r2]
	ldr r0, _0804C3FC @ =0x06010780
	str r0, [r2, #4]
	ldr r0, _0804C400 @ =0x80000090
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	mov sl, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #7
	adds r0, r0, r7
	str r0, [r2]
	ldr r0, _0804C404 @ =0x06010AE0
	str r0, [r2, #4]
	ldr r0, _0804C3DC @ =0x80000040
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0
_0804C396:
	mov r2, sb
	ldr r0, [r2]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	ldr r3, _0804C408 @ =0x00000747
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r7, r2, #0
	cmp r0, #9
	bls _0804C3AE
	b _0804C602
_0804C3AE:
	lsls r0, r0, #2
	ldr r1, _0804C40C @ =_0804C410
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804C3B8: .4byte gCurrentPinballGame
_0804C3BC: .4byte 0x040000D4
_0804C3C0: .4byte 0x000013BC
_0804C3C4: .4byte gUnknown_083FE44C
_0804C3C8: .4byte 0x06010000
_0804C3CC: .4byte 0x80000100
_0804C3D0: .4byte 0x0000132C
_0804C3D4: .4byte gUnknown_083BB16C
_0804C3D8: .4byte 0x06010400
_0804C3DC: .4byte 0x80000040
_0804C3E0: .4byte gUnknown_084C07EC
_0804C3E4: .4byte gUnknown_084FA48C
_0804C3E8: .4byte gUnknown_084C00EC
_0804C3EC: .4byte 0x00000744
_0804C3F0: .4byte 0x06010480
_0804C3F4: .4byte 0x800000C0
_0804C3F8: .4byte 0x000001E5
_0804C3FC: .4byte 0x06010780
_0804C400: .4byte 0x80000090
_0804C404: .4byte 0x06010AE0
_0804C408: .4byte 0x00000747
_0804C40C: .4byte _0804C410
_0804C410: @ jump table
	.4byte _0804C438 @ case 0
	.4byte _0804C5D4 @ case 1
	.4byte _0804C5D4 @ case 2
	.4byte _0804C55E @ case 3
	.4byte _0804C5D4 @ case 4
	.4byte _0804C602 @ case 5
	.4byte _0804C5D4 @ case 6
	.4byte _0804C5D4 @ case 7
	.4byte _0804C5D4 @ case 8
	.4byte _0804C460 @ case 9
_0804C438:
	ldr r3, _0804C454 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	asrs r2, r7, #0x10
	ldr r1, _0804C458 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804C45C @ =gUnknown_0848D68C
	b _0804C5EC
	.align 2, 0
_0804C454: .4byte 0x040000D4
_0804C458: .4byte 0x00000749
_0804C45C: .4byte gUnknown_0848D68C
_0804C460:
	mov r5, sb
	ldr r4, [r5]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0804C510
	ldr r1, _0804C498 @ =gMain+0x74
	ldr r2, _0804C49C @ =0x0000059A
	adds r0, r4, r2
	ldrh r3, [r0]
	adds r1, r3, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804C4AC
	asrs r3, r7, #0x10
	ldr r2, _0804C4A0 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r3
	movs r1, #0xcd
	strb r1, [r0]
	ldr r6, _0804C4A4 @ =0x040000D4
	ldr r5, _0804C4A8 @ =gMonPortraitGroupPals
	mov r8, r5
	b _0804C528
	.align 2, 0
_0804C498: .4byte gMain+0x74
_0804C49C: .4byte 0x0000059A
_0804C4A0: .4byte 0x00000749
_0804C4A4: .4byte 0x040000D4
_0804C4A8: .4byte gMonPortraitGroupPals
_0804C4AC:
	cmp r0, #3
	bhi _0804C4E8
	asrs r1, r7, #0x10
	ldr r2, _0804C4D4 @ =0x00000749
	adds r0, r4, r2
	adds r0, r0, r1
	strb r3, [r0]
	ldr r1, _0804C4D8 @ =0x040000D4
	ldr r0, _0804C4DC @ =gMonPortraitGroupPals
	ldr r0, [r0]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _0804C4E0 @ =0x050003A0
	str r0, [r1, #4]
	ldr r0, _0804C4E4 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0804C55E
	.align 2, 0
_0804C4D4: .4byte 0x00000749
_0804C4D8: .4byte 0x040000D4
_0804C4DC: .4byte gMonPortraitGroupPals
_0804C4E0: .4byte 0x050003A0
_0804C4E4: .4byte 0x80000010
_0804C4E8:
	asrs r2, r7, #0x10
	ldr r1, _0804C504 @ =0x00000749
	adds r0, r4, r1
	adds r0, r0, r2
	strb r3, [r0]
	ldr r6, _0804C508 @ =0x040000D4
	ldr r5, _0804C50C @ =gMonPortraitGroupPals
	mov r8, r5
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	adds r0, r0, r2
	b _0804C530
	.align 2, 0
_0804C504: .4byte 0x00000749
_0804C508: .4byte 0x040000D4
_0804C50C: .4byte gMonPortraitGroupPals
_0804C510:
	asrs r3, r7, #0x10
	ldr r2, _0804C5B4 @ =0x00000749
	adds r1, r4, r2
	adds r1, r1, r3
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r6, _0804C5B8 @ =0x040000D4
	ldr r0, _0804C5BC @ =gMonPortraitGroupPals
	mov r8, r0
_0804C528:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r2
	adds r0, r0, r3
_0804C530:
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r6]
	ldr r0, _0804C5C0 @ =0x050003A0
	str r0, [r6, #4]
	ldr r0, _0804C5C4 @ =0x80000010
	str r0, [r6, #8]
	ldr r0, [r6, #8]
_0804C55E:
	ldr r2, _0804C5B8 @ =0x040000D4
	ldr r3, _0804C5C8 @ =gMonPortraitGroupGfx
	mov r8, r3
	mov r5, sb
	ldr r0, [r5]
	asrs r6, r7, #0x10
	ldr r1, _0804C5B4 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r6
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	str r2, [sp]
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	ldr r2, [sp]
	str r0, [r2]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r3, _0804C5CC @ =0x06010CA0
	adds r0, r0, r3
	str r0, [r2, #4]
	ldr r0, _0804C5D0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0804C602
	.align 2, 0
_0804C5B4: .4byte 0x00000749
_0804C5B8: .4byte 0x040000D4
_0804C5BC: .4byte gMonPortraitGroupPals
_0804C5C0: .4byte 0x050003A0
_0804C5C4: .4byte 0x80000010
_0804C5C8: .4byte gMonPortraitGroupGfx
_0804C5CC: .4byte 0x06010CA0
_0804C5D0: .4byte 0x80000180
_0804C5D4:
	ldr r3, _0804C630 @ =0x040000D4
	mov r5, sb
	ldr r0, [r5]
	asrs r2, r7, #0x10
	ldr r1, _0804C634 @ =0x00000749
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804C638 @ =gUnknown_083A8EEC
_0804C5EC:
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #8
	ldr r2, _0804C63C @ =0x06010CA0
	adds r0, r0, r2
	str r0, [r3, #4]
	ldr r0, _0804C640 @ =0x80000180
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_0804C602:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r7, r3
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0804C612
	b _0804C396
_0804C612:
	mov r5, sb
	ldr r1, [r5]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #4
	bne _0804C69C
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #7
	blt _0804C69C
	cmp r0, #8
	ble _0804C644
	cmp r0, #9
	beq _0804C660
	b _0804C69C
	.align 2, 0
_0804C630: .4byte 0x040000D4
_0804C634: .4byte 0x00000749
_0804C638: .4byte gUnknown_083A8EEC
_0804C63C: .4byte 0x06010CA0
_0804C640: .4byte 0x80000180
_0804C644:
	ldr r2, _0804C654 @ =0x000005A9
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C68C
	ldr r1, _0804C658 @ =0x040000D4
	ldr r0, _0804C65C @ =gUnknown_02031060
	b _0804C690
	.align 2, 0
_0804C654: .4byte 0x000005A9
_0804C658: .4byte 0x040000D4
_0804C65C: .4byte gUnknown_02031060
_0804C660:
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	bgt _0804C69C
	ldr r5, _0804C680 @ =0x000005A9
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C68C
	ldr r1, _0804C684 @ =0x040000D4
	ldr r0, _0804C688 @ =gUnknown_02031060
	b _0804C690
	.align 2, 0
_0804C680: .4byte 0x000005A9
_0804C684: .4byte 0x040000D4
_0804C688: .4byte gUnknown_02031060
_0804C68C:
	ldr r1, _0804C6B8 @ =0x040000D4
	ldr r0, _0804C6BC @ =gUnknown_02030760
_0804C690:
	str r0, [r1]
	ldr r0, _0804C6C0 @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _0804C6C4 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804C69C:
	mov r0, sb
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bne _0804C720
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	cmp r0, #2
	beq _0804C6C8
	cmp r0, #3
	beq _0804C6E4
	b _0804C720
	.align 2, 0
_0804C6B8: .4byte 0x040000D4
_0804C6BC: .4byte gUnknown_02030760
_0804C6C0: .4byte 0x06010CA0
_0804C6C4: .4byte 0x80000240
_0804C6C8:
	ldr r2, _0804C6D8 @ =0x000005A9
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C710
	ldr r1, _0804C6DC @ =0x040000D4
	ldr r0, _0804C6E0 @ =gUnknown_02031060
	b _0804C714
	.align 2, 0
_0804C6D8: .4byte 0x000005A9
_0804C6DC: .4byte 0x040000D4
_0804C6E0: .4byte gUnknown_02031060
_0804C6E4:
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	bgt _0804C720
	ldr r5, _0804C704 @ =0x000005A9
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _0804C710
	ldr r1, _0804C708 @ =0x040000D4
	ldr r0, _0804C70C @ =gUnknown_02031060
	b _0804C714
	.align 2, 0
_0804C704: .4byte 0x000005A9
_0804C708: .4byte 0x040000D4
_0804C70C: .4byte gUnknown_02031060
_0804C710:
	ldr r1, _0804C7C4 @ =0x040000D4
	ldr r0, _0804C7C8 @ =gUnknown_02030760
_0804C714:
	str r0, [r1]
	ldr r0, _0804C7CC @ =0x06010CA0
	str r0, [r1, #4]
	ldr r0, _0804C7D0 @ =0x80000240
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804C720:
	ldr r2, _0804C7C4 @ =0x040000D4
	mov r1, sb
	ldr r0, [r1]
	ldr r3, _0804C7D4 @ =0x0000020B
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r5, _0804C7D8 @ =gUnknown_0844838C
	adds r0, r0, r5
	str r0, [r2]
	ldr r0, _0804C7DC @ =0x060113C0
	str r0, [r2, #4]
	ldr r0, _0804C7E0 @ =0x80000180
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r1, sb
	ldr r0, [r1]
	adds r3, #0x54
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldr r5, _0804C7E4 @ =gUnknown_086AD49C
	adds r0, r0, r5
	mov r3, sl
	lsls r1, r3, #0x10
	asrs r1, r1, #7
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C7E8 @ =0x060116C0
	str r0, [r2, #4]
	ldr r3, _0804C7EC @ =0x80000100
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	ldr r1, _0804C7F0 @ =0x000001ED
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _0804C7F4 @ =gUnknown_086AD2EE
	adds r1, #6
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #9
	ldr r1, _0804C7F8 @ =gUnknown_084FD18C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C7FC @ =0x06011CE0
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	mov r5, sb
	ldr r0, [r5]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #9
	ldr r1, _0804C800 @ =gUnknown_083BD36C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804C804 @ =0x06011EE0
	str r0, [r2, #4]
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C7C4: .4byte 0x040000D4
_0804C7C8: .4byte gUnknown_02030760
_0804C7CC: .4byte 0x06010CA0
_0804C7D0: .4byte 0x80000240
_0804C7D4: .4byte 0x0000020B
_0804C7D8: .4byte gUnknown_0844838C
_0804C7DC: .4byte 0x060113C0
_0804C7E0: .4byte 0x80000180
_0804C7E4: .4byte gUnknown_086AD49C
_0804C7E8: .4byte 0x060116C0
_0804C7EC: .4byte 0x80000100
_0804C7F0: .4byte 0x000001ED
_0804C7F4: .4byte gUnknown_086AD2EE
_0804C7F8: .4byte gUnknown_084FD18C
_0804C7FC: .4byte 0x06011CE0
_0804C800: .4byte gUnknown_083BD36C
_0804C804: .4byte 0x06011EE0

	thumb_func_start sub_4C808
sub_4C808: @ 0x0804C808
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _0804C90C @ =gUnknown_086AD2EE
	ldr r6, _0804C910 @ =gCurrentPinballGame
	ldr r5, [r6]
	ldr r2, _0804C914 @ =0x000001ED
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r4, _0804C918 @ =0x040000D4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _0804C91C @ =gUnknown_084FB68C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0804C920 @ =0x060122A0
	str r0, [r4, #4]
	ldr r0, _0804C924 @ =0x80000240
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0804C928 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x32
	bl __umodsi3
	movs r1, #0x19
	bl __udivsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r2, _0804C92C @ =gUnknown_083C3C2C
	adds r1, r1, r2
	str r1, [r4]
	ldr r1, _0804C930 @ =0x06012720
	str r1, [r4, #4]
	ldr r1, _0804C934 @ =0x80000180
	str r1, [r4, #8]
	ldr r1, [r4, #8]
	ldr r1, _0804C938 @ =0x000002F5
	adds r5, r5, r1
	movs r2, #0
	ldrsb r2, [r5, r2]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r1, r1, r2
	lsls r1, r1, #5
	ldr r2, _0804C93C @ =gUnknown_084F5ACC
	adds r1, r1, r2
	str r1, [r4]
	ldr r1, _0804C940 @ =0x06012C20
	str r1, [r4, #4]
	ldr r1, _0804C944 @ =0x80000130
	str r1, [r4, #8]
	ldr r1, [r4, #8]
	movs r2, #0
	mov ip, r6
	ldr r1, _0804C948 @ =gUnknown_084ED0CC
	mov r8, r1
	ldr r1, _0804C94C @ =gUnknown_08449D8C
	mov sb, r1
	ldr r1, _0804C950 @ =gUnknown_086AD456
	mov sl, r1
	lsls r0, r0, #8
	ldr r1, _0804C954 @ =gUnknown_083C806C
	adds r3, r0, r1
	movs r7, #0xba
	lsls r7, r7, #1
	ldr r6, _0804C958 @ =0x06010000
	ldr r5, _0804C95C @ =0x80000080
_0804C8AE:
	str r3, [r4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #3
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r1, r6
	str r1, [r4, #4]
	str r5, [r4, #8]
	ldr r1, [r4, #8]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0804C8AE
	mov r2, ip
	ldr r0, [r2]
	ldr r1, _0804C960 @ =0x000002F1
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xf
	ldr r2, _0804C918 @ =0x040000D4
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, r8
	str r0, [r2]
	ldr r0, _0804C964 @ =0x06013180
	str r0, [r2, #4]
	ldr r0, _0804C968 @ =0x800000C0
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r2, ip
	ldr r1, [r2]
	ldr r2, _0804C96C @ =0x000002DA
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _0804C974
	ldr r0, _0804C970 @ =0x00000746
	adds r1, r1, r0
	movs r0, #0
	b _0804C97A
	.align 2, 0
_0804C90C: .4byte gUnknown_086AD2EE
_0804C910: .4byte gCurrentPinballGame
_0804C914: .4byte 0x000001ED
_0804C918: .4byte 0x040000D4
_0804C91C: .4byte gUnknown_084FB68C
_0804C920: .4byte 0x060122A0
_0804C924: .4byte 0x80000240
_0804C928: .4byte gMain
_0804C92C: .4byte gUnknown_083C3C2C
_0804C930: .4byte 0x06012720
_0804C934: .4byte 0x80000180
_0804C938: .4byte 0x000002F5
_0804C93C: .4byte gUnknown_084F5ACC
_0804C940: .4byte 0x06012C20
_0804C944: .4byte 0x80000130
_0804C948: .4byte gUnknown_084ED0CC
_0804C94C: .4byte gUnknown_08449D8C
_0804C950: .4byte gUnknown_086AD456
_0804C954: .4byte gUnknown_083C806C
_0804C958: .4byte 0x06010000
_0804C95C: .4byte 0x80000080
_0804C960: .4byte 0x000002F1
_0804C964: .4byte 0x06013180
_0804C968: .4byte 0x800000C0
_0804C96C: .4byte 0x000002DA
_0804C970: .4byte 0x00000746
_0804C974:
	ldr r2, _0804C9F8 @ =0x00000746
	adds r1, r1, r2
	movs r0, #1
_0804C97A:
	strb r0, [r1]
	ldr r4, _0804C9FC @ =0x040000D4
	mov r1, ip
	ldr r0, [r1]
	ldr r2, _0804C9F8 @ =0x00000746
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	add r0, sb
	str r0, [r4]
	ldr r0, _0804CA00 @ =0x06013300
	str r0, [r4, #4]
	ldr r0, _0804CA04 @ =0x80000140
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, ip
	ldr r5, [r0]
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0x2a
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	ldr r2, _0804CA08 @ =0x000001A5
	adds r1, r5, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0804CA0C @ =gUnknown_084F6B0C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0804CA10 @ =0x06013D00
	str r0, [r4, #4]
	ldr r0, _0804CA14 @ =0x80000280
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804C9F8: .4byte 0x00000746
_0804C9FC: .4byte 0x040000D4
_0804CA00: .4byte 0x06013300
_0804CA04: .4byte 0x80000140
_0804CA08: .4byte 0x000001A5
_0804CA0C: .4byte gUnknown_084F6B0C
_0804CA10: .4byte 0x06013D00
_0804CA14: .4byte 0x80000280

	thumb_func_start sub_4CA18
sub_4CA18: @ 0x0804CA18
	ldr r1, _0804CA38 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r2, _0804CA3C @ =0x00000346
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #6
	bhi _0804CACE
	lsls r0, r0, #2
	ldr r1, _0804CA40 @ =_0804CA44
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804CA38: .4byte gCurrentPinballGame
_0804CA3C: .4byte 0x00000346
_0804CA40: .4byte _0804CA44
_0804CA44: @ jump table
	.4byte _0804CA60 @ case 0
	.4byte _0804CA60 @ case 1
	.4byte _0804CA60 @ case 2
	.4byte _0804CA78 @ case 3
	.4byte _0804CA78 @ case 4
	.4byte _0804CAA0 @ case 5
	.4byte _0804CACE @ case 6
_0804CA60:
	ldr r0, [r2]
	ldr r3, _0804CA70 @ =0x00000345
	adds r0, r0, r3
	ldr r2, _0804CA74 @ =0x040000D4
	movs r1, #0
	ldrsb r1, [r0, r1]
	b _0804CAB8
	.align 2, 0
_0804CA70: .4byte 0x00000345
_0804CA74: .4byte 0x040000D4
_0804CA78:
	ldr r1, _0804CA90 @ =0x040000D4
	ldr r0, _0804CA94 @ =gUnknown_08490A4C
	movs r2, #0xff
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, _0804CA98 @ =0x0600D900
	str r0, [r1, #4]
	ldr r0, _0804CA9C @ =0x80000220
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0804CACE
	.align 2, 0
_0804CA90: .4byte 0x040000D4
_0804CA94: .4byte gUnknown_08490A4C
_0804CA98: .4byte 0x0600D900
_0804CA9C: .4byte 0x80000220
_0804CAA0:
	ldr r1, _0804CAD0 @ =gUnknown_086AE5A0
	ldr r0, [r2]
	ldr r3, _0804CAD4 @ =0x00000345
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, _0804CAD8 @ =0x040000D4
	movs r3, #0
	ldrsh r1, [r0, r3]
_0804CAB8:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #6
	ldr r1, _0804CADC @ =gUnknown_08490A4C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0804CAE0 @ =0x0600D900
	str r0, [r2, #4]
	ldr r0, _0804CAE4 @ =0x80000220
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0804CACE:
	bx lr
	.align 2, 0
_0804CAD0: .4byte gUnknown_086AE5A0
_0804CAD4: .4byte 0x00000345
_0804CAD8: .4byte 0x040000D4
_0804CADC: .4byte gUnknown_08490A4C
_0804CAE0: .4byte 0x0600D900
_0804CAE4: .4byte 0x80000220

	thumb_func_start sub_4CAE8
sub_4CAE8: @ 0x0804CAE8
	ldr r1, _0804CAFC @ =0x040000D4
	ldr r0, _0804CB00 @ =gUnknown_08138834
	str r0, [r1]
	ldr r0, _0804CB04 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CB08 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0804CAFC: .4byte 0x040000D4
_0804CB00: .4byte gUnknown_08138834
_0804CB04: .4byte 0x06015800
_0804CB08: .4byte 0x80001000

	thumb_func_start sub_4CB0C
sub_4CB0C: @ 0x0804CB0C
	ldr r1, _0804CB20 @ =0x040000D4
	ldr r0, _0804CB24 @ =gUnknown_0813A854
	str r0, [r1]
	ldr r0, _0804CB28 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CB2C @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0804CB20: .4byte 0x040000D4
_0804CB24: .4byte gUnknown_0813A854
_0804CB28: .4byte 0x06015800
_0804CB2C: .4byte 0x80001000

	thumb_func_start sub_4CB30
sub_4CB30: @ 0x0804CB30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r5, _0804CB90 @ =0x040000D4
	ldr r0, _0804CB94 @ =gUnknown_0813C874
	str r0, [r5]
	ldr r0, _0804CB98 @ =0x06015800
	str r0, [r5, #4]
	ldr r0, _0804CB9C @ =0x80001000
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _0804CBA0 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, _0804CBA4 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0804CBA8 @ =0x00000749
	adds r0, r0, r1
	ldrb r6, [r0]
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r5]
	ldr r0, _0804CBAC @ =0x06010CA0
	str r0, [r5, #4]
	ldr r0, _0804CBB0 @ =0x80000180
	str r0, [r5, #8]
	ldr r0, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CB90: .4byte 0x040000D4
_0804CB94: .4byte gUnknown_0813C874
_0804CB98: .4byte 0x06015800
_0804CB9C: .4byte 0x80001000
_0804CBA0: .4byte gMonPortraitGroupGfx
_0804CBA4: .4byte gCurrentPinballGame
_0804CBA8: .4byte 0x00000749
_0804CBAC: .4byte 0x06010CA0
_0804CBB0: .4byte 0x80000180

	thumb_func_start sub_4CBB4
sub_4CBB4: @ 0x0804CBB4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _0804CBD0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, #0
	cmp r1, #1
	bgt _0804CBDC
	ldr r1, _0804CBD4 @ =0x040000D4
	ldr r0, _0804CBD8 @ =gUnknown_0849F1CC
	b _0804CBE0
	.align 2, 0
_0804CBD0: .4byte gCurrentPinballGame
_0804CBD4: .4byte 0x040000D4
_0804CBD8: .4byte gUnknown_0849F1CC
_0804CBDC:
	ldr r1, _0804CC38 @ =0x040000D4
	ldr r0, _0804CC3C @ =gUnknown_0813E894
_0804CBE0:
	str r0, [r1]
	ldr r0, _0804CC40 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CC44 @ =0x80001000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _0804CC38 @ =0x040000D4
	ldr r0, _0804CC48 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, [r2]
	ldr r1, _0804CC4C @ =0x00000749
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r6]
	ldr r0, _0804CC50 @ =0x06010CA0
	str r0, [r6, #4]
	ldr r0, _0804CC54 @ =0x80000180
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CC38: .4byte 0x040000D4
_0804CC3C: .4byte gUnknown_0813E894
_0804CC40: .4byte 0x06015800
_0804CC44: .4byte 0x80001000
_0804CC48: .4byte gMonPortraitGroupGfx
_0804CC4C: .4byte 0x00000749
_0804CC50: .4byte 0x06010CA0
_0804CC54: .4byte 0x80000180

	thumb_func_start sub_4CC58
sub_4CC58: @ 0x0804CC58
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r1, _0804CC7C @ =gCurrentPinballGame
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #0
	bne _0804CC90
	ldr r1, _0804CC80 @ =0x040000D4
	ldr r0, _0804CC84 @ =gUnknown_083C5A2C
	str r0, [r1]
	ldr r0, _0804CC88 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CC8C @ =0x80001400
	b _0804CCC0
	.align 2, 0
_0804CC7C: .4byte gCurrentPinballGame
_0804CC80: .4byte 0x040000D4
_0804CC84: .4byte gUnknown_083C5A2C
_0804CC88: .4byte 0x06015800
_0804CC8C: .4byte 0x80001400
_0804CC90:
	cmp r0, #1
	bne _0804CCB4
	ldr r1, _0804CCA4 @ =0x040000D4
	ldr r0, _0804CCA8 @ =gUnknown_084A856C
	str r0, [r1]
	ldr r0, _0804CCAC @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CCB0 @ =0x80000E00
	b _0804CCC0
	.align 2, 0
_0804CCA4: .4byte 0x040000D4
_0804CCA8: .4byte gUnknown_084A856C
_0804CCAC: .4byte 0x06015800
_0804CCB0: .4byte 0x80000E00
_0804CCB4:
	ldr r1, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD38 @ =gUnknown_081408B4
	str r0, [r1]
	ldr r0, _0804CD3C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CD40 @ =0x80001000
_0804CCC0:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0804CCE8
	ldr r1, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD44 @ =gUnknown_084AA18C
	str r0, [r1]
	ldr r0, _0804CD48 @ =0x06011620
	str r0, [r1, #4]
	ldr r0, _0804CD4C @ =0x80000430
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0804CCE8:
	ldr r6, _0804CD34 @ =0x040000D4
	ldr r0, _0804CD50 @ =gMonPortraitGroupGfx
	mov r8, r0
	ldr r0, [r2]
	ldr r1, _0804CD54 @ =0x00000749
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	add r4, r8
	adds r0, r5, #0
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r6]
	ldr r0, _0804CD58 @ =0x06010CA0
	str r0, [r6, #4]
	ldr r0, _0804CD5C @ =0x80000180
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CD34: .4byte 0x040000D4
_0804CD38: .4byte gUnknown_081408B4
_0804CD3C: .4byte 0x06015800
_0804CD40: .4byte 0x80001000
_0804CD44: .4byte gUnknown_084AA18C
_0804CD48: .4byte 0x06011620
_0804CD4C: .4byte 0x80000430
_0804CD50: .4byte gMonPortraitGroupGfx
_0804CD54: .4byte 0x00000749
_0804CD58: .4byte 0x06010CA0
_0804CD5C: .4byte 0x80000180

	thumb_func_start sub_4CD60
sub_4CD60: @ 0x0804CD60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r2, #0
	ldr r3, _0804CE5C @ =gUnknown_03006400
	ldr r6, _0804CE60 @ =gMain
	movs r0, #0x80
	lsls r0, r0, #4
	adds r0, r0, r3
	mov r8, r0
	ldr r1, _0804CE64 @ =gUnknown_084B77EC
	mov sb, r1
	ldr r0, _0804CE68 @ =0xFFFFF800
	adds r0, r0, r3
	mov ip, r0
	movs r7, #0x80
	lsls r7, r7, #3
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r4, _0804CE6C @ =0x000007FF
_0804CD8A:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, r7
	lsls r0, r0, #1
	add r0, ip
	strh r5, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r4
	ble _0804CD8A
	ldr r1, _0804CE70 @ =0x040000D4
	str r3, [r1]
	ldr r0, _0804CE74 @ =0x06001000
	str r0, [r1, #4]
	ldr r0, _0804CE78 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r6, #0x38]
	ldr r0, _0804CE7C @ =0x00001C42
	strh r0, [r6, #0x38]
	ldrh r0, [r6, #0x3a]
	ldr r0, _0804CE80 @ =0x00000C04
	strh r0, [r6, #0x3a]
	movs r2, #0
	ldr r1, _0804CE68 @ =0xFFFFF800
	adds r4, r3, r1
	ldr r3, _0804CE84 @ =0x0000013F
_0804CDC4:
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	cmp r2, #0
	bge _0804CDD0
	adds r0, #0x1f
_0804CDD0:
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _0804CDF0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r2, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0x90
	lsls r1, r1, #8
	strh r1, [r0]
_0804CDF0:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	ble _0804CDC4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, _0804CE88 @ =0x000002EE
	adds r1, r6, r0
	movs r0, #0x7e
	strh r0, [r1]
	ldr r1, _0804CE70 @ =0x040000D4
	mov r0, r8
	str r0, [r1]
	ldr r0, _0804CE8C @ =0x06001140
	str r0, [r1, #4]
	ldr r0, _0804CE90 @ =0x80000140
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	ldr r5, _0804CE94 @ =0xFFFFF000
	add r5, r8
	ldr r4, _0804CE98 @ =0x000001FF
	ldr r3, _0804CE6C @ =0x000007FF
_0804CE28:
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r5
	strh r4, [r0]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r3
	ble _0804CE28
	ldr r1, _0804CE70 @ =0x040000D4
	mov r0, sb
	str r0, [r1]
	ldr r0, _0804CE9C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _0804CEA0 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804CE5C: .4byte gUnknown_03006400
_0804CE60: .4byte gMain
_0804CE64: .4byte gUnknown_084B77EC
_0804CE68: .4byte 0xFFFFF800
_0804CE6C: .4byte 0x000007FF
_0804CE70: .4byte 0x040000D4
_0804CE74: .4byte 0x06001000
_0804CE78: .4byte 0x80000800
_0804CE7C: .4byte 0x00001C42
_0804CE80: .4byte 0x00000C04
_0804CE84: .4byte 0x0000013F
_0804CE88: .4byte 0x000002EE
_0804CE8C: .4byte 0x06001140
_0804CE90: .4byte 0x80000140
_0804CE94: .4byte 0xFFFFF000
_0804CE98: .4byte 0x000001FF
_0804CE9C: .4byte 0x06015800
_0804CEA0: .4byte 0x80000400

	thumb_func_start nullsub_18
nullsub_18: @ 0x0804CEA4
	bx lr

    .align 2, 0
