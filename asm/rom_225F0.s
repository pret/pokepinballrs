#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified

	.text


	thumb_func_start sub_225F0
sub_225F0: @ 0x080225F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r5, _08022680 @ =gMain
	ldr r0, [r5, #0x44]
	adds r0, #0x9c
	ldr r7, [r0]
	ldr r2, _08022684 @ =gCurrentPinballGame
	ldr r3, [r2]
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r4, [r0]
	movs r6, #0xca
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	lsls r1, r0, #3
	adds r1, r1, r0
	adds r1, #0x13
	mov sl, r2
	cmp r4, r1
	blt _0802262A
	b _08022958
_0802262A:
	cmp r4, #0
	bne _08022690
	movs r1, #0
	movs r0, #1
	strh r0, [r7]
	ldr r2, _08022688 @ =0x00000193
	adds r0, r3, r2
	strb r1, [r0]
	movs r2, #0
_0802263C:
	mov r3, sl
	ldr r4, [r3]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #1
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r0, r4, r5
	adds r0, r0, r2
	movs r5, #0
	strh r5, [r0]
	lsls r0, r1, #2
	adds r3, r4, r0
	movs r6, #0xce
	lsls r6, r6, #1
	adds r2, r3, r6
	movs r0, #0x46
	strh r0, [r2]
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0xb4
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #1
	ble _0802263C
	ldr r1, _0802268C @ =0x00000195
	adds r0, r4, r1
	strb r5, [r0]
	b _08022908
	.align 2, 0
_08022680: .4byte gMain
_08022684: .4byte gCurrentPinballGame
_08022688: .4byte 0x00000193
_0802268C: .4byte 0x00000195
_08022690:
	adds r0, r3, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080226B6
	ldrb r0, [r3, #5]
	cmp r0, #0
	bne _080226AE
	ldrh r1, [r5, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080226B6
_080226AE:
	ldr r2, _0802279C @ =0x00000195
	adds r1, r3, r2
	movs r0, #1
	strb r0, [r1]
_080226B6:
	mov r3, sl
	ldr r5, [r3]
	ldr r4, _080227A0 @ =0x00000193
	mov sb, r4
	adds r6, r5, r4
	movs r0, #0xca
	lsls r0, r0, #1
	mov r8, r0
	adds r0, r5, r0
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _080226D8
	b _0802280E
_080226D8:
	movs r1, #0xcb
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r4, r0, #1
	adds r0, r4, #0
	movs r1, #9
	bl __modsi3
	cmp r0, #0
	beq _080226F0
	b _0802280E
_080226F0:
	ldr r2, _0802279C @ =0x00000195
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080227A4
	adds r0, r4, #0
	movs r1, #0x12
	bl __modsi3
	movs r1, #9
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	movs r2, #0x11
	strh r2, [r1]
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #0xce
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xbc
	strh r0, [r1]
	movs r5, #0xcf
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x8c
	strh r0, [r1]
	movs r0, 0x7E @=SE_UNKNOWN_0x7E
	bl m4aSongNumStart
	mov r6, sl
	ldr r1, [r6]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r2, r1, r3
	mov r4, r8
	adds r0, r1, r4
	add r1, sb
	ldrb r0, [r0]
	ldrb r1, [r1]
	subs r0, r0, r1
	ldrb r5, [r2]
	adds r0, r0, r5
	strb r0, [r2]
	ldr r0, [r6]
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _08022766
	movs r0, #0x63
	strb r0, [r1]
_08022766:
	mov r6, sl
	ldr r2, [r6]
	mov r0, r8
	adds r3, r2, r0
	movs r1, #0
	ldrsb r1, [r3, r1]
	mov r5, sb
	adds r4, r2, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	subs r1, r1, r0
	movs r0, #0x64
	muls r0, r1, r0
	str r0, [r2, #0x3c]
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r0, #1
	movs r6, #0xcb
	lsls r6, r6, #1
	adds r2, r2, r6
	strh r0, [r2]
	ldrb r0, [r3]
	strb r0, [r4]
	b _0802280E
	.align 2, 0
_0802279C: .4byte 0x00000195
_080227A0: .4byte 0x00000193
_080227A4:
	adds r0, r4, #0
	movs r1, #0x12
	bl __modsi3
	movs r1, #9
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	movs r2, #0x11
	strh r2, [r1]
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #0xce
	lsls r4, r4, #1
	adds r1, r2, r4
	movs r0, #0xbc
	strh r0, [r1]
	movs r5, #0xcf
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x8c
	strh r0, [r1]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, 0x7E @=SE_UNKNOWN_0x7E
	bl m4aSongNumStart
	mov r6, sl
	ldr r1, [r6]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x63
	bls _08022806
	movs r0, #0x63
	strb r0, [r1]
_08022806:
	mov r0, sl
	ldr r1, [r0]
	movs r0, #0x64
	str r0, [r1, #0x3c]
_0802280E:
	movs r2, #0
	ldr r1, _08022848 @ =gUnknown_086B481A
	mov r8, r1
	ldr r3, _0802284C @ =gOamBuffer
	mov ip, r3
_08022818:
	mov r5, sl
	ldr r4, [r5]
	lsls r1, r2, #0x10
	asrs r3, r1, #0x10
	lsls r0, r3, #2
	adds r2, r4, r0
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r2, r6
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r7, #4]
	movs r5, #0
	ldrsh r0, [r2, r5]
	mov sb, r1
	cmp r0, #0xa0
	ble _08022850
	movs r0, #0
	b _0802286A
	.align 2, 0
_08022848: .4byte gUnknown_086B481A
_0802284C: .4byte gOamBuffer
_08022850:
	lsls r1, r3, #1
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r0, r4, r6
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x11
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x10
_0802286A:
	mov r3, sb
	asrs r5, r3, #0x10
	lsls r3, r5, #3
	adds r3, #8
	adds r3, r7, r3
	ldrh r2, [r3]
	lsls r2, r2, #3
	add r2, ip
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r2, [r3]
	lsls r2, r2, #3
	add r2, ip
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	movs r6, #2
	ldrsh r0, [r7, r6]
	adds r1, r1, r0
	ldr r6, _08022968 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldr r0, _0802296C @ =0xFFFFFE00
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r3]
	lsls r1, r1, #3
	add r1, ip
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	mov r4, sl
	ldr r3, [r4]
	lsls r1, r5, #1
	subs r6, #0x67
	adds r0, r3, r6
	adds r1, r0, r1
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _080228FA
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080228FA
	lsls r0, r5, #2
	adds r2, r3, r0
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r2, r5
	movs r0, #0x46
	strh r0, [r1]
	adds r6, #6
	adds r1, r2, r6
	movs r0, #0xb4
	strh r0, [r1]
_080228FA:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, sb
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08022818
_08022908:
	mov r0, sl
	ldr r3, [r0]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r2, [r1]
	movs r4, #0xca
	lsls r4, r4, #1
	adds r3, r3, r4
	movs r1, #0
	ldrsb r1, [r3, r1]
	subs r1, #1
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r0, #0x13
	cmp r2, r0
	bne _08022958
	ldr r0, _08022970 @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0x9c
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1]
	strb r0, [r3]
	mov r5, sl
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x25
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08022958
	ldr r6, _08022974 @ =0x000006DE
	adds r1, r1, r6
	movs r0, #0xaa
	strh r0, [r1]
_08022958:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022968: .4byte 0x000001FF
_0802296C: .4byte 0xFFFFFE00
_08022970: .4byte gMain
_08022974: .4byte 0x000006DE

	thumb_func_start sub_22978
sub_22978: @ 0x08022978
	push {r4, r5, lr}
	ldr r3, _08022A00 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r4, #0
	movs r5, #0
	movs r0, #0xc8
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r0, _08022A04 @ =0x000002CA
	adds r2, r1, r0
	movs r0, #0x82
	lsls r0, r0, #4
	strh r0, [r2]
	ldr r0, _08022A08 @ =0x000002C3
	adds r1, r1, r0
	strb r4, [r1]
	ldr r4, [r3]
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r0, _08022A0C @ =gMain
	ldr r1, _08022A10 @ =0x00003DE8
	adds r0, r0, r1
	movs r2, #1
	movs r1, #1
	strh r1, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, [r3]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xa0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0xe4
	movs r0, #3
	strb r0, [r1]
	ldr r1, _08022A14 @ =0x040000D4
	ldr r0, _08022A18 @ =gUnknown_083A808C
	str r0, [r1]
	ldr r0, _08022A1C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08022A20 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08022A24 @ =gUnknown_0848FD8C
	str r0, [r1]
	ldr r0, _08022A28 @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08022A2C @ =0x80000650
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08022A00: .4byte gCurrentPinballGame
_08022A04: .4byte 0x000002CA
_08022A08: .4byte 0x000002C3
_08022A0C: .4byte gMain
_08022A10: .4byte 0x00003DE8
_08022A14: .4byte 0x040000D4
_08022A18: .4byte gUnknown_083A808C
_08022A1C: .4byte 0x050003C0
_08022A20: .4byte 0x80000010
_08022A24: .4byte gUnknown_0848FD8C
_08022A28: .4byte 0x06015800
_08022A2C: .4byte 0x80000650

	thumb_func_start sub_22A30
sub_22A30: @ 0x08022A30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r7, _08022A68 @ =gMain+0x3DE8 @gMain.spriteGroups[82]
	ldr r1, _08022A6C @ =gUnknown_086ADFE2
	ldr r4, _08022A70 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r5, _08022A74 @ =0x000002C3
	adds r3, r2, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r0, r1
	bls _08022A78
	adds r0, r1, #1
	strh r0, [r2]
	b _08022B2E
	.align 2, 0
_08022A68: .4byte gMain+0x3DE8 @gMain.spriteGroups[82]
_08022A6C: .4byte gUnknown_086ADFE2
_08022A70: .4byte gCurrentPinballGame
_08022A74: .4byte 0x000002C3
_08022A78:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r1, [r4]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r3, _08022C30 @ =0x000002C3
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x29
	bne _08022AAE
	movs r0, #0x28
	strb r0, [r1]
	strh r6, [r7]
	ldr r0, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0
	strb r1, [r0]
_08022AAE:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08022AC4
	movs r0, #0xa3
	lsls r0, r0, #1
	bl m4aSongNumStart
_08022AC4:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	bne _08022AD8
	ldr r0, _08022C34 @ =0x00000147
	bl m4aSongNumStart
_08022AD8:
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xd
	bne _08022AEE
	movs r0, #0xa4
	lsls r0, r0, #1
	bl m4aSongNumStart
_08022AEE:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x27
	bne _08022B1C
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r1, r2
	strh r6, [r0]
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r6, [r0]
	ldr r1, _08022C38 @ =0x040000D4
	ldr r0, _08022C3C @ =gUnknown_084FD18C
	str r0, [r1]
	ldr r0, _08022C40 @ =0x06011CE0
	str r0, [r1, #4]
	ldr r0, _08022C44 @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08022B1C:
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bne _08022B2E
	ldr r0, _08022C48 @ =0x001E8480
	str r0, [r1, #0x3c]
_08022B2E:
	ldr r0, _08022C4C @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r5, _08022C30 @ =0x000002C3
	adds r0, r1, r5
	ldrb r0, [r0]
	subs r0, #0xe
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _08022B5A
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #7
	bl __umodsi3
	cmp r0, #0
	bne _08022B5A
	ldr r0, _08022C50 @ =0x00000149
	bl m4aSongNumStart
_08022B5A:
	ldr r0, _08022C4C @ =gCurrentPinballGame
	ldr r4, [r0]
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r1, _08022C54 @ =0x000002CA
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x5a
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r7, #4]
	ldr r1, _08022C58 @ =gUnknown_086ADFE2
	ldr r3, _08022C30 @ =0x000002C3
	adds r4, r4, r3
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldr r5, _08022C5C @ =gUnknown_086B28A0
	mov sb, r5
	ldr r6, _08022C60 @ =gOamBuffer
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	mov ip, r0
	ldr r5, _08022C64 @ =0xFFFFFE00
	mov r8, r5
_08022BB6:
	lsls r3, r2, #0x10
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
	ldrh r0, [r2, #2]
	mov sl, r0
	mov r5, sl
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r5, _08022C68 @ =0x000001FF
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
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #5
	ble _08022BB6
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022C30: .4byte 0x000002C3
_08022C34: .4byte 0x00000147
_08022C38: .4byte 0x040000D4
_08022C3C: .4byte gUnknown_084FD18C
_08022C40: .4byte 0x06011CE0
_08022C44: .4byte 0x80000100
_08022C48: .4byte 0x001E8480
_08022C4C: .4byte gCurrentPinballGame
_08022C50: .4byte 0x00000149
_08022C54: .4byte 0x000002CA
_08022C58: .4byte gUnknown_086ADFE2
_08022C5C: .4byte gUnknown_086B28A0
_08022C60: .4byte gOamBuffer
_08022C64: .4byte 0xFFFFFE00
_08022C68: .4byte 0x000001FF

	thumb_func_start sub_22C6C
sub_22C6C: @ 0x08022C6C
	push {r4, r5, r6, lr}
	ldr r4, _08022D14 @ =gCurrentPinballGame
	ldr r2, [r4]
	ldr r0, _08022D18 @ =0x000002C6
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r5, #0xb2
	lsls r5, r5, #2
	adds r1, r2, r5
	movs r0, #0xe1
	lsls r0, r0, #4
	strh r0, [r1]
	ldr r6, _08022D1C @ =0x000002CA
	adds r1, r2, r6
	ldr r0, _08022D20 @ =0x0000FFD8
	strh r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08022D24 @ =0x0000FFDC
	strh r0, [r1]
	ldr r0, _08022D28 @ =0x000002CE
	adds r1, r2, r0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _08022D2C @ =gMain
	ldr r1, _08022D30 @ =0x00000B98
	adds r0, r0, r1
	movs r3, #1
	movs r1, #1
	strh r1, [r0]
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r2, r2, r0
	strb r3, [r2]
	ldr r4, [r4]
	adds r5, r4, r5
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0x14
	bl __divsi3
	ldr r5, _08022D34 @ =gUnknown_086AE088
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r6, r4, r6
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #0x14
	bl __divsi3
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r4, #0xe4
	movs r0, #2
	strb r0, [r4]
	ldr r1, _08022D38 @ =0x040000D4
	ldr r0, _08022D3C @ =gUnknown_083A806C
	str r0, [r1]
	ldr r0, _08022D40 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08022D44 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08022D48 @ =gUnknown_083A704C
	str r0, [r1]
	ldr r0, _08022D4C @ =0x06015800
	str r0, [r1, #4]
	ldr r0, _08022D50 @ =0x80000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08022D14: .4byte gCurrentPinballGame
_08022D18: .4byte 0x000002C6
_08022D1C: .4byte 0x000002CA
_08022D20: .4byte 0x0000FFD8
_08022D24: .4byte 0x0000FFDC
_08022D28: .4byte 0x000002CE
_08022D2C: .4byte gMain
_08022D30: .4byte 0x00000B98
_08022D34: .4byte gUnknown_086AE088
_08022D38: .4byte 0x040000D4
_08022D3C: .4byte gUnknown_083A806C
_08022D40: .4byte 0x050003C0
_08022D44: .4byte 0x80000010
_08022D48: .4byte gUnknown_083A704C
_08022D4C: .4byte 0x06015800
_08022D50: .4byte 0x80000800

	thumb_func_start sub_22D54
sub_22D54: @ 0x08022D54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08022E38 @ =gCurrentPinballGame
	ldr r5, [r4]
	ldr r0, _08022E3C @ =0x000002C6
	mov sb, r0
	adds r0, r5, r0
	ldrh r6, [r0]
	adds r0, r6, #0
	movs r1, #0x38
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x13
	ldr r1, _08022E40 @ =gMain+0xB98 @gMain.spriteGroups[12]
	mov r8, r1
	mov sl, r4
	cmp r6, #0x81
	bls _08022D82
	b _08022EA0
_08022D82:
	adds r0, r6, #0
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08022D96
	movs r0, 0xB8 @=SE_UNKNOWN_0xB8
	bl m4aSongNumStart
_08022D96:
	mov r2, sl
	ldr r1, [r2]
	mov r3, sb
	adds r2, r1, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r5, #0xb2
	lsls r5, r5, #2
	adds r2, r1, r5
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	ldrh r5, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	ldr r0, _08022E44 @ =0x000002CA
	adds r2, r1, r0
	adds r3, #2
	adds r4, r1, r3
	ldrh r0, [r4]
	ldrh r5, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	ldrh r6, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bgt _08022DE2
	ldr r0, _08022E48 @ =0xFFFFF468
	add r0, r8
	ldr r0, [r0, #0x4c]
	movs r1, #3
	bl __umodsi3
	cmp r0, #0
	bne _08022DE6
_08022DE2:
	subs r0, r6, #1
	strh r0, [r4]
_08022DE6:
	ldr r0, _08022E38 @ =gCurrentPinballGame
	ldr r6, [r0]
	ldr r2, _08022E3C @ =0x000002C6
	adds r1, r6, r2
	ldrh r1, [r1]
	mov sl, r0
	cmp r1, #0x4d
	bhi _08022E50
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r1, #0x14
	bl __divsi3
	ldr r1, _08022E4C @ =gUnknown_086AE088
	lsls r5, r7, #0x10
	lsrs r4, r5, #0xe
	adds r4, r4, r1
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r7, #0xfa
	lsls r7, r7, #1
	adds r1, r6, r7
	strh r0, [r1]
	ldr r1, _08022E44 @ =0x000002CA
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	b _08022E64
	.align 2, 0
_08022E38: .4byte gCurrentPinballGame
_08022E3C: .4byte 0x000002C6
_08022E40: .4byte gMain+0xB98 @gMain.spriteGroups[12]
_08022E44: .4byte 0x000002CA
_08022E48: .4byte 0xFFFFF468
_08022E4C: .4byte gUnknown_086AE088
_08022E50:
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	lsls r5, r7, #0x10
_08022E64:
	mov r3, sl
	ldr r1, [r3]
	ldr r7, _08022E88 @ =0x000002C6
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0x4e
	bne _08022E76
	ldr r0, _08022E8C @ =0x000186A0
	str r0, [r1, #0x3c]
_08022E76:
	ldr r1, _08022E90 @ =0x040000D4
	ldr r0, _08022E94 @ =gUnknown_084FD18C
	str r0, [r1]
	ldr r0, _08022E98 @ =0x06011CE0
	str r0, [r1, #4]
	ldr r0, _08022E9C @ =0x80000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08022EBA
	.align 2, 0
_08022E88: .4byte 0x000002C6
_08022E8C: .4byte 0x000186A0
_08022E90: .4byte 0x040000D4
_08022E94: .4byte gUnknown_084FD18C
_08022E98: .4byte 0x06011CE0
_08022E9C: .4byte 0x80000100
_08022EA0:
	movs r2, #0
	mov r0, r8
	strh r2, [r0]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	mov r5, sl
	ldr r0, [r5]
	adds r0, #0xe4
	strb r2, [r0]
	lsls r5, r7, #0x10
_08022EBA:
	mov r7, sl
	ldr r4, [r7]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x14
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3, #2]
	ldr r7, _08022F90 @ =0x000002CA
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x14
	bl __divsi3
	adds r4, #0x5a
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #4]
	movs r2, #0
	ldr r3, _08022F94 @ =gOamBuffer
	mov ip, r3
	ldr r7, _08022F98 @ =gUnknown_086B4850
	mov sl, r7
	asrs r1, r5, #0x10
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r6, r0, #1
	ldr r0, _08022F9C @ =0xFFFFFE00
	mov sb, r0
_08022F08:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #3
	adds r4, #8
	add r4, r8
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
	ldrh r5, [r2, #2]
	lsls r1, r5, #0x17
	lsrs r1, r1, #0x17
	mov r7, r8
	movs r5, #2
	ldrsh r0, [r7, r5]
	adds r1, r1, r0
	ldr r7, _08022FA0 @ =0x000001FF
	adds r0, r7, #0
	ands r1, r0
	mov r0, sb
	ldrh r5, [r2, #2]
	ands r0, r5
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	add r1, ip
	mov r7, r8
	ldrb r0, [r7, #4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r2, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #4
	ble _08022F08
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022F90: .4byte 0x000002CA
_08022F94: .4byte gOamBuffer
_08022F98: .4byte gUnknown_086B4850
_08022F9C: .4byte 0xFFFFFE00
_08022FA0: .4byte 0x000001FF

	thumb_func_start sub_22FA4
sub_22FA4: @ 0x08022FA4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _0802301C @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r1, _08023020 @ =0x0000020E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #9
	bl sub_1C7F4
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, _08023024 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r0, #1
	strh r0, [r1]
	movs r2, #0
	mov r8, r4
	ldr r7, _08023028 @ =gSpeciesInfo+7 (PokemonSpecies.name)
	mov ip, r7
	ldr r4, _0802302C @ =0x040000D4
	ldr r0, _08023030 @ =0x06015800
	mov sb, r0
	ldr r6, _08023034 @ =0x80000020
_08022FE0:
	lsls r2, r2, #0x10
	asrs r3, r2, #0x10
	mov r1, r8
	ldr r5, [r1]
	movs r7, #0xb3
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _0802303C
	ldr r0, _08023038 @ =gUnknown_083FFD4C
	str r0, [r4]
	lsls r0, r3, #6
	add r0, sb
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08023020 @ =0x0000020E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	b _08023052
	.align 2, 0
_0802301C: .4byte gCurrentPinballGame
_08023020: .4byte 0x0000020E
_08023024: .4byte gMain
_08023028: .4byte gSpeciesInfo+7
_0802302C: .4byte 0x040000D4
_08023030: .4byte 0x06015800
_08023034: .4byte 0x80000020
_08023038: .4byte gUnknown_083FFD4C
_0802303C:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _0802306C @ =gUnknown_083FF04C
	adds r0, r0, r1
	str r0, [r4]
	lsls r0, r3, #6
	add r0, sb
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
_08023052:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08022FE0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802306C: .4byte gUnknown_083FF04C

	thumb_func_start sub_23070
sub_23070: @ 0x08023070
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080230F4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r6, [r0, #0x10]
	movs r0, #0
	ldr r1, _080230F8 @ =gCurrentPinballGame
	mov r8, r1
	ldr r7, _080230FC @ =gOamBuffer
	ldr r2, _08023100 @ =0xFFFFFE00
	mov ip, r2
_08023088:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	mov r3, r8
	ldr r1, [r3]
	ldr r2, _08023104 @ =0x0000020E
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, #0x98
	movs r3, #0xdb
	lsls r3, r3, #1
	adds r2, r1, r3
	adds r0, r4, r0
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	movs r0, #0x60
	strh r0, [r6, #4]
	adds r4, #8
	adds r4, r6, r4
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r1, r0
	ldr r2, _08023108 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, ip
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r0, [r6, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #9
	ble _08023088
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080230F4: .4byte gMain
_080230F8: .4byte gCurrentPinballGame
_080230FC: .4byte gOamBuffer
_08023100: .4byte 0xFFFFFE00
_08023104: .4byte 0x0000020E
_08023108: .4byte 0x000001FF

	thumb_func_start sub_2310C
sub_2310C: @ 0x0802310C
	ldr r0, _08023124 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08023128 @ =gCurrentPinballGame
	ldr r0, [r0]
	adds r0, #0xe4
	strb r2, [r0]
	bx lr
	.align 2, 0
_08023124: .4byte gMain
_08023128: .4byte gCurrentPinballGame
