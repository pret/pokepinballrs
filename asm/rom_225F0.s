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

	thumb_func_start sub_2312C
sub_2312C: @ 0x0802312C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080231B8 @ =gCurrentPinballGame
	ldr r0, [r4]
	ldr r2, _080231BC @ =0x0000020E
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0
	strh r3, [r1]
	ldr r7, _080231C0 @ =0x000006DB
	adds r0, r0, r7
	strb r2, [r0]
	ldr r0, [r4]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r3, [r0]
	movs r0, #3
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r4]
	adds r0, #0xe4
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, _080231C4 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x10]
	movs r0, #1
	strh r0, [r1]
	movs r5, #0
	mov r8, r4
	ldr r2, _080231C8 @ =gSpeciesInfo+7 (PokemonSpecies.name)
	mov ip, r2
	ldr r3, _080231CC @ =0x040000D4
	ldr r7, _080231D0 @ =0x06015800
	mov sb, r7
	ldr r6, _080231D4 @ =0x80000020
_0802317C:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	mov r0, r8
	ldr r4, [r0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r2, r0
	mov r7, ip
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0x20
	bne _080231DC
	ldr r0, _080231D8 @ =gUnknown_083FFD4C
	str r0, [r3]
	lsls r0, r2, #6
	add r0, sb
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
	ldr r0, _080231BC @ =0x0000020E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	b _080231F2
	.align 2, 0
_080231B8: .4byte gCurrentPinballGame
_080231BC: .4byte 0x0000020E
_080231C0: .4byte 0x000006DB
_080231C4: .4byte gMain
_080231C8: .4byte gSpeciesInfo+7
_080231CC: .4byte 0x040000D4
_080231D0: .4byte 0x06015800
_080231D4: .4byte 0x80000020
_080231D8: .4byte gUnknown_083FFD4C
_080231DC:
	ldrb r0, [r1]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _08023230 @ =gUnknown_083FF04C
	adds r0, r0, r1
	str r0, [r3]
	lsls r0, r2, #6
	add r0, sb
	str r0, [r3, #4]
	str r6, [r3, #8]
	ldr r0, [r3, #8]
_080231F2:
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0802317C
	ldr r0, _08023234 @ =gMain
	ldr r0, [r0, #0x44]
	ldr r1, [r0, #0x14]
	movs r0, #1
	strh r0, [r1]
	movs r5, #0
	ldr r2, _08023238 @ =gUnknown_086ACFE0
	mov r8, r2
	ldr r3, _0802323C @ =0x040000D4
	ldr r6, _08023240 @ =0x06015800
	ldr r4, _08023244 @ =0x80000020
_08023218:
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #1
	mov r7, r8
	adds r1, r0, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #0x20
	bne _0802324C
	ldr r0, _08023248 @ =gUnknown_083FFD4C
	b _08023258
	.align 2, 0
_08023230: .4byte gUnknown_083FF04C
_08023234: .4byte gMain
_08023238: .4byte gUnknown_086ACFE0
_0802323C: .4byte 0x040000D4
_08023240: .4byte 0x06015800
_08023244: .4byte 0x80000020
_08023248: .4byte gUnknown_083FFD4C
_0802324C:
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #0x41
	lsls r0, r0, #6
	ldr r1, _080232EC @ =gUnknown_083FF04C
	adds r0, r0, r1
_08023258:
	str r0, [r3]
	adds r0, r2, #0
	adds r0, #0xa
	lsls r0, r0, #6
	adds r0, r0, r6
	str r0, [r3, #4]
	str r4, [r3, #8]
	ldr r0, [r3, #8]
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08023218
	movs r5, #0
	ldr r2, _080232F0 @ =gCurrentPinballGame
	mov ip, r2
	ldr r7, _080232F4 @ =0x00000212
	movs r6, #0
	movs r4, #0x8a
	lsls r4, r4, #2
_08023286:
	mov r0, ip
	ldr r2, [r0]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #1
	adds r0, r2, r7
	adds r0, r0, r3
	strh r3, [r0]
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r2, r2, r4
	strh r6, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023286
	movs r5, #0
	ldr r1, _080232F0 @ =gCurrentPinballGame
	mov ip, r1
	movs r7, #0
	ldr r6, _080232F8 @ =0x000013D4
	ldr r4, _080232FC @ =0x000013E8
_080232B6:
	mov r2, ip
	ldr r3, [r2]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r2, r3, r6
	adds r2, r2, r0
	adds r0, r1, #0
	adds r0, #0xa
	lsls r0, r0, #1
	strh r0, [r2]
	lsls r0, r1, #2
	adds r3, r3, r0
	adds r3, r3, r4
	strh r7, [r3]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _080232B6
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080232EC: .4byte gUnknown_083FF04C
_080232F0: .4byte gCurrentPinballGame
_080232F4: .4byte 0x00000212
_080232F8: .4byte 0x000013D4
_080232FC: .4byte 0x000013E8

	thumb_func_start sub_23300
sub_23300: @ 0x08023300
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080233E4 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _080233E8 @ =0x000006C4
	adds r1, r1, r2
	movs r4, #0
	strb r4, [r1]
	ldr r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	adds r3, r2, #0
	mov r8, r0
	cmp r3, #0
	bne _080233FC
	adds r0, r2, #1
	strh r0, [r1]
	ldr r1, _080233EC @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	strh r4, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _080233F0 @ =gOamBuffer
	ldr r4, _080233F4 @ =0xFFFFFE00
	mov r8, r4
_08023342:
	lsls r4, r5, #0x10
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
	ldr r2, _080233F8 @ =0x000001FF
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
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _08023342
	ldr r3, _080233EC @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x14]
	movs r0, #0
	strh r0, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _080233F0 @ =gOamBuffer
	ldr r4, _080233F4 @ =0xFFFFFE00
	mov r8, r4
_0802339C:
	lsls r4, r5, #0x10
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
	ldr r2, _080233F8 @ =0x000001FF
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
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _0802339C
	b _08023934
	.align 2, 0
_080233E4: .4byte gCurrentPinballGame
_080233E8: .4byte 0x000006C4
_080233EC: .4byte gMain
_080233F0: .4byte gOamBuffer
_080233F4: .4byte 0xFFFFFE00
_080233F8: .4byte 0x000001FF
_080233FC:
	cmp r3, #0xc2
	bls _08023402
	b _0802385C
_08023402:
	adds r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x9b
	bls _08023410
	b _08023688
_08023410:
	ldr r1, _0802343C @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	movs r5, #0
	ldr r3, _08023440 @ =gOamBuffer
	mov sb, r3
	ldr r4, _08023444 @ =0x00000637
	mov sl, r4
_08023420:
	mov r0, r8
	ldr r3, [r0]
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #1
	ldr r4, _08023448 @ =0x00000212
	adds r0, r3, r4
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802344C
	subs r0, #1
	strh r0, [r1]
	b _0802347C
	.align 2, 0
_0802343C: .4byte gMain
_08023440: .4byte gOamBuffer
_08023444: .4byte 0x00000637
_08023448: .4byte 0x00000212
_0802344C:
	lsls r0, r2, #2
	adds r0, r3, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r6, #0xc8
	lsls r6, r6, #3
	subs r1, r6, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, sl
	ble _0802347C
	strh r6, [r4]
_0802347C:
	lsls r6, r5, #0x10
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r0, #0xa0
	ldr r3, _08023530 @ =0x0000020E
	adds r1, r5, r3
	subs r4, r4, r0
	ldrh r1, [r1]
	adds r4, r4, r1
	strh r4, [r7, #2]
	ldr r4, _08023534 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x24
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023538 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _0802353C @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023420
	ldr r5, _08023540 @ =gMain
	ldr r0, [r5, #0x44]
	ldr r7, [r0, #0x14]
	movs r5, #0
	ldr r0, _08023544 @ =0x00000637
	mov sl, r0
	ldr r1, _08023548 @ =gOamBuffer
	mov sb, r1
_08023512:
	mov r2, r8
	ldr r4, [r2]
	lsls r2, r5, #0x10
	asrs r3, r2, #0x10
	lsls r1, r3, #1
	ldr r5, _0802354C @ =0x000013D4
	adds r0, r4, r5
	adds r1, r0, r1
	ldrh r0, [r1]
	adds r6, r2, #0
	cmp r0, #0
	beq _08023550
	subs r0, #1
	strh r0, [r1]
	b _0802357E
	.align 2, 0
_08023530: .4byte 0x0000020E
_08023534: .4byte 0x000006E6
_08023538: .4byte 0x000001FF
_0802353C: .4byte 0xFFFFFE00
_08023540: .4byte gMain
_08023544: .4byte 0x00000637
_08023548: .4byte gOamBuffer
_0802354C: .4byte 0x000013D4
_08023550:
	lsls r0, r3, #2
	adds r0, r4, r0
	ldr r1, _0802366C @ =0x000013E8
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r5, #0xc8
	lsls r5, r5, #3
	subs r1, r5, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, sl
	ble _0802357E
	strh r5, [r4]
_0802357E:
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	ldr r1, _0802366C @ =0x000013E8
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r0, #0xa0
	subs r4, r4, r0
	strh r4, [r7, #2]
	ldr r4, _08023670 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x34
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023674 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _08023678 @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023512
	mov r5, r8
	ldr r0, [r5]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x9b
	beq _0802360A
	b _08023934
_0802360A:
	movs r0, #0
	ldr r7, _0802367C @ =0x00000212
	movs r6, #0
	movs r4, #0x8a
	lsls r4, r4, #2
_08023614:
	ldr r2, [r5]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #1
	adds r0, r2, r7
	adds r0, r0, r3
	strh r3, [r0]
	lsls r0, r1, #2
	adds r2, r2, r0
	adds r2, r2, r4
	strh r6, [r2]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023614
	movs r0, #0
	ldr r7, _08023680 @ =gCurrentPinballGame
	movs r6, #0
	ldr r5, _08023684 @ =0x000013D4
	ldr r4, _0802366C @ =0x000013E8
_08023640:
	ldr r3, [r7]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r2, r3, r5
	adds r2, r2, r0
	adds r0, r1, #0
	adds r0, #0xa
	lsls r0, r0, #1
	strh r0, [r2]
	lsls r0, r1, #2
	adds r3, r3, r0
	adds r3, r3, r4
	strh r6, [r3]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #9
	ble _08023640
	b _08023934
	.align 2, 0
_0802366C: .4byte 0x000013E8
_08023670: .4byte 0x000006E6
_08023674: .4byte 0x000001FF
_08023678: .4byte 0xFFFFFE00
_0802367C: .4byte 0x00000212
_08023680: .4byte gCurrentPinballGame
_08023684: .4byte 0x000013D4
_08023688:
	ldr r1, _080236B0 @ =gMain
	ldr r0, [r1, #0x44]
	ldr r7, [r0, #0x10]
	movs r5, #0
	ldr r2, _080236B4 @ =gOamBuffer
	mov sb, r2
_08023694:
	mov r3, r8
	ldr r2, [r3]
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
	lsls r1, r4, #1
	ldr r3, _080236B8 @ =0x00000212
	adds r0, r2, r3
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	beq _080236BC
	subs r0, #1
	strh r0, [r1]
	b _080236E2
	.align 2, 0
_080236B0: .4byte gMain
_080236B4: .4byte gOamBuffer
_080236B8: .4byte 0x00000212
_080236BC:
	lsls r4, r4, #2
	adds r4, r2, r4
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xfa
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_080236E2:
	lsls r6, r5, #0x10
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	ldr r3, _08023790 @ =0x0000020E
	adds r1, r5, r3
	subs r4, r4, r0
	ldrh r1, [r1]
	adds r4, r4, r1
	strh r4, [r7, #2]
	ldr r4, _08023794 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x24
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023798 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _0802379C @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023694
	ldr r5, _080237A0 @ =gMain
	ldr r0, [r5, #0x44]
	ldr r7, [r0, #0x14]
	movs r5, #0
	ldr r0, _080237A4 @ =gOamBuffer
	mov sb, r0
_08023772:
	mov r1, r8
	ldr r3, [r1]
	lsls r2, r5, #0x10
	asrs r4, r2, #0x10
	lsls r1, r4, #1
	ldr r5, _080237A8 @ =0x000013D4
	adds r0, r3, r5
	adds r1, r0, r1
	ldrh r0, [r1]
	adds r6, r2, #0
	cmp r0, #0
	beq _080237AC
	subs r0, #1
	strh r0, [r1]
	b _080237D0
	.align 2, 0
_08023790: .4byte 0x0000020E
_08023794: .4byte 0x000006E6
_08023798: .4byte 0x000001FF
_0802379C: .4byte 0xFFFFFE00
_080237A0: .4byte gMain
_080237A4: .4byte gOamBuffer
_080237A8: .4byte 0x000013D4
_080237AC:
	lsls r4, r4, #2
	adds r4, r3, r4
	ldr r0, _0802384C @ =0x000013E8
	adds r4, r4, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xfa
	lsls r1, r1, #3
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl __divsi3
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
_080237D0:
	asrs r6, r6, #0x10
	lsls r2, r6, #3
	adds r4, r2, #0
	adds r4, #0x50
	mov r3, r8
	ldr r5, [r3]
	adds r0, r5, #0
	adds r0, #0x58
	ldrh r0, [r0]
	subs r4, r4, r0
	lsls r0, r6, #2
	adds r0, r5, r0
	ldr r1, _0802384C @ =0x000013E8
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	str r2, [sp]
	bl __divsi3
	subs r4, r4, r0
	strh r4, [r7, #2]
	ldr r4, _08023850 @ =0x000006E6
	adds r5, r5, r4
	ldrh r0, [r5]
	adds r0, #0x34
	strh r0, [r7, #4]
	ldr r2, [sp]
	adds r2, #8
	adds r5, r7, r2
	ldrh r3, [r5]
	lsls r3, r3, #3
	add r3, sb
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	adds r2, r2, r0
	ldr r4, _08023854 @ =0x000001FF
	adds r0, r4, #0
	ands r2, r0
	ldrh r0, [r3, #2]
	ldr r4, _08023858 @ =0xFFFFFE00
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	add r1, sb
	ldrb r0, [r7, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r6, #1
	lsls r6, r6, #0x10
	lsrs r5, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #9
	ble _08023772
	b _08023934
	.align 2, 0
_0802384C: .4byte 0x000013E8
_08023850: .4byte 0x000006E6
_08023854: .4byte 0x000001FF
_08023858: .4byte 0xFFFFFE00
_0802385C:
	ldr r0, _08023944 @ =gMain
	ldr r1, [r0, #0x44]
	ldr r7, [r1, #0x10]
	ldrh r1, [r7]
	cmp r1, #0
	beq _080238BA
	strh r4, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _08023948 @ =gOamBuffer
	ldr r0, _0802394C @ =0xFFFFFE00
	mov sb, r0
_08023876:
	lsls r4, r5, #0x10
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
	ldr r2, _08023950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
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
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _08023876
_080238BA:
	ldr r3, _08023944 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r7, [r0, #0x14]
	ldrh r0, [r7]
	cmp r0, #0
	beq _0802391A
	movs r0, #0
	strh r0, [r7, #2]
	movs r0, #0xb4
	strh r0, [r7, #4]
	movs r5, #0
	ldr r6, _08023948 @ =gOamBuffer
	ldr r4, _0802394C @ =0xFFFFFE00
	mov sb, r4
_080238D6:
	lsls r4, r5, #0x10
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
	ldr r2, _08023950 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
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
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #9
	ble _080238D6
_0802391A:
	ldr r3, _08023944 @ =gMain
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x10]
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r3, #0x44]
	ldr r0, [r0, #0x14]
	strh r1, [r0]
	mov r4, r8
	ldr r0, [r4]
	adds r0, #0xe4
	strb r2, [r0]
_08023934:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023944: .4byte gMain
_08023948: .4byte gOamBuffer
_0802394C: .4byte 0xFFFFFE00
_08023950: .4byte 0x000001FF

	thumb_func_start sub_23954
sub_23954: @ 0x08023954
	push {r4, lr}
	ldr r2, _08023998 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	movs r4, #0xf7
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r2]
	ldr r1, _0802399C @ =0x000001ED
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r4, #2
	adds r1, r0, r4
	movs r4, #0
	strh r3, [r1]
	ldr r1, _080239A0 @ =0x000002DA
	adds r0, r0, r1
	strb r4, [r0]
	ldr r0, [r2]
	subs r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023998: .4byte gCurrentPinballGame
_0802399C: .4byte 0x000001ED
_080239A0: .4byte 0x000002DA

	thumb_func_start sub_239A4
sub_239A4: @ 0x080239A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r6, #0
	ldr r1, _080239DC @ =gMain+0x2578 @gMain.spriteGroups[48]
	mov sb, r1
	mov ip, r6
	ldr r1, _080239E0 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bhi _08023A22
	lsls r0, r0, #2
	ldr r1, _080239E4 @ =_080239E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080239DC: .4byte gMain+0x2578 @gMain.spriteGroups[48]
_080239E0: .4byte gCurrentPinballGame
_080239E4: .4byte _080239E8
_080239E8: @ jump table
	.4byte _08023A22 @ case 0
	.4byte _08023A22 @ case 1
	.4byte _08023A00 @ case 2
	.4byte _08023A06 @ case 3
	.4byte _08023A10 @ case 4
	.4byte _08023A1A @ case 5
_08023A00:
	movs r3, #4
	mov r8, r3
	b _08023A0A
_08023A06:
	movs r4, #8
	mov r8, r4
_08023A0A:
	movs r7, #4
	movs r6, #3
	b _08023A22
_08023A10:
	movs r6, #0xc
	mov r8, r6
	movs r7, #0xc
	movs r6, #5
	b _08023A22
_08023A1A:
	movs r0, #0x21
	mov r8, r0
	movs r7, #0
	movs r6, #0
_08023A22:
	ldr r1, _08023AD4 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r5, _08023AD8 @ =0x000001ED
	adds r2, r0, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	beq _08023A9A
	ldr r3, _08023ADC @ =gUnknown_086AD2EE
	lsls r0, r0, #3
	adds r1, r3, #4
	adds r0, r0, r1
	ldr r2, _08023AE0 @ =0x040000D4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023AE4 @ =gUnknown_084FB68C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023AE8 @ =0x060122A0
	str r0, [r2, #4]
	ldr r0, _08023AEC @ =0x80000240
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _08023AD4 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r3, #6
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #9
	ldr r1, _08023AF0 @ =gUnknown_084FD18C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023AF4 @ =0x06011CE0
	str r0, [r2, #4]
	ldr r0, _08023AF8 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r4, _08023AD4 @ =gCurrentPinballGame
	ldr r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r1, r1, r2
	strb r0, [r1]
_08023A9A:
	ldr r3, _08023AD4 @ =gCurrentPinballGame
	ldr r2, [r3]
	movs r4, #0xf6
	lsls r4, r4, #1
	mov sl, r4
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08023AB2
	b _08023C06
_08023AB2:
	ldr r0, _08023ADC @ =gUnknown_086AD2EE
	adds r3, r2, r5
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #3
	adds r0, #2
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrh r2, [r4]
	ldrh r0, [r1]
	cmp r0, r2
	bls _08023AFC
	adds r0, r2, #1
	strh r0, [r4]
	b _08023BEE
	.align 2, 0
_08023AD4: .4byte gCurrentPinballGame
_08023AD8: .4byte 0x000001ED
_08023ADC: .4byte gUnknown_086AD2EE
_08023AE0: .4byte 0x040000D4
_08023AE4: .4byte gUnknown_084FB68C
_08023AE8: .4byte 0x060122A0
_08023AEC: .4byte 0x80000240
_08023AF0: .4byte gUnknown_084FD18C
_08023AF4: .4byte 0x06011CE0
_08023AF8: .4byte 0x80000100
_08023AFC:
	ldrb r0, [r3]
	adds r0, #1
	movs r2, #0
	strb r0, [r3]
	ldr r3, _08023C94 @ =gCurrentPinballGame
	ldr r1, [r3]
	movs r4, #0xf8
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	adds r1, r1, r5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r8
	blt _08023B22
	strb r7, [r1]
	ldr r0, [r3]
	add r0, sl
	strb r6, [r0]
_08023B22:
	ldr r6, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x12
	bne _08023B36
	bl BuildSpeciesWeightsForEggMode
_08023B36:
	ldr r1, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x13
	bne _08023B66
	bl PickSpeciesForEggMode
	ldr r0, _08023C98 @ =gMain
	ldrb r0, [r0, #2]
	cmp r0, #3
	beq _08023B66
	ldr r2, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r2]
	movs r3, #0xb3
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r1, #1
	bl SaveFile_SetPokedexFlags
_08023B66:
	ldr r5, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x14
	bne _08023B7C
	bl sub_28BFC
_08023B7C:
	ldr r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #8
	beq _08023B8E
	cmp r0, #0x1b
	bne _08023B9E
_08023B8E:
	movs r6, #0xf8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08023B9E
	bl m4aMPlayAllStop
_08023B9E:
	ldr r0, _08023C94 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r2, _08023C9C @ =0x000001ED
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _08023BC2
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08023BC2
	movs r0, 0x16 @ =MUS_EGG_MODE_START
	bl m4aSongNumStart
_08023BC2:
	ldr r5, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1d
	bne _08023BDA
	movs r0, #5
	bl sub_19B64
_08023BDA:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1c
	bne _08023BEE
	movs r0, 0x92 @=SE_UNKNOWN_0x92
	bl m4aSongNumStart
_08023BEE:
	ldr r2, _08023CA0 @ =gUnknown_086AD2EE
	ldr r1, _08023C94 @ =gCurrentPinballGame
	ldr r0, [r1]
	ldr r4, _08023C9C @ =0x000001ED
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	mov ip, r0
_08023C06:
	ldr r6, _08023C94 @ =gCurrentPinballGame
	ldr r3, [r6]
	adds r0, r3, #0
	adds r0, #0x58
	ldrh r1, [r0]
	movs r0, #0x58
	subs r0, r0, r1
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r2, r3, r1
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x5a
	ldrh r1, [r0]
	movs r0, #0x90
	subs r0, r0, r1
	movs r6, #0xf5
	lsls r6, r6, #1
	adds r4, r3, r6
	strh r0, [r4]
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r2, sb
	strh r0, [r2, #2]
	adds r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08023CC4
	subs r1, #7
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x20
	bne _08023CA4
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	cmp r0, #0xd0
	bls _08023CA4
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	cmp r0, #0
	bge _08023C74
	adds r0, #0xf
_08023C74:
	asrs r0, r0, #4
	ldr r1, _08023C98 @ =gMain
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, [r1, #0x4c]
	ands r1, r0
	cmp r1, #0
	beq _08023CC4
	movs r6, #0xfb
	lsls r6, r6, #1
	adds r0, r3, r6
	ldrh r0, [r0]
	ldrh r4, [r4]
	adds r0, r0, r4
	b _08023CBA
	.align 2, 0
_08023C94: .4byte gCurrentPinballGame
_08023C98: .4byte gMain
_08023C9C: .4byte 0x000001ED
_08023CA0: .4byte gUnknown_086AD2EE
_08023CA4:
	ldr r3, _08023CC0 @ =gCurrentPinballGame
	ldr r0, [r3]
	movs r4, #0xf5
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r6, #0xfb
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
_08023CBA:
	mov r1, sb
	strh r0, [r1, #4]
	b _08023CCA
	.align 2, 0
_08023CC0: .4byte gCurrentPinballGame
_08023CC4:
	movs r0, #0xc8
	mov r2, sb
	strh r0, [r2, #4]
_08023CCA:
	movs r2, #0
	mov r3, ip
	lsls r1, r3, #0x10
	ldr r7, _08023DFC @ =gOamBuffer
	asrs r1, r1, #0x10
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	mov sl, r0
_08023CDC:
	lsls r3, r2, #0x10
	asrs r3, r3, #0x10
	lsls r0, r3, #3
	adds r0, #8
	mov r4, sb
	adds r5, r4, r0
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	ldr r6, _08023E00 @ =gUnknown_086B4D4E
	adds r0, r0, r6
	add r0, sl
	ldrh r1, [r0]
	strh r1, [r2]
	adds r0, #2
	adds r2, #2
	ldrh r1, [r0]
	strh r1, [r2]
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	movs r0, #1
	lsls r0, r0, #2
	str r0, [sp]
	ldrb r2, [r1, #5]
	movs r4, #0xd
	rsbs r4, r4, #0
	mov r8, r4
	mov r0, r8
	ands r0, r2
	ldr r6, [sp]
	orrs r0, r6
	strb r0, [r1, #5]
	ldrh r2, [r5]
	lsls r2, r2, #3
	adds r2, r2, r7
	ldrh r4, [r2, #2]
	lsls r1, r4, #0x17
	lsrs r1, r1, #0x17
	mov ip, r1
	mov r1, sb
	movs r6, #2
	ldrsh r0, [r1, r6]
	mov r6, ip
	adds r1, r6, r0
	ldr r6, _08023E04 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldr r0, _08023E08 @ =0xFFFFFE00
	mov ip, r0
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
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
	ble _08023CDC
	ldr r6, _08023E0C @ =gMain+0x2858 @gMain.spriteGroups[52]
	mov sb, r6
	ldr r1, _08023E10 @ =gCurrentPinballGame
	ldr r0, [r1]
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldr r0, [r1]
	movs r3, #0xf5
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r6, #4]
	movs r2, #0
	ldr r7, _08023DFC @ =gOamBuffer
	mov sl, r8
	mov r8, ip
_08023D92:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #3
	ldr r6, _08023E14 @ =gMain+0x2860 @gMain.spriteGroups[52].oam
	adds r5, r0, r6
	ldrh r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, sl
	ands r0, r2
	ldr r2, [sp]
	orrs r0, r2
	strb r0, [r1, #5]
	ldrh r3, [r5]
	lsls r3, r3, #3
	adds r3, r3, r7
	movs r6, #2
	ldrsh r1, [r5, r6]
	mov r2, sb
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r2, _08023E04 @ =0x000001FF
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
	mov r3, sb
	ldrb r0, [r3, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	strb r0, [r1]
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _08023D92
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023DFC: .4byte gOamBuffer
_08023E00: .4byte gUnknown_086B4D4E
_08023E04: .4byte 0x000001FF
_08023E08: .4byte 0xFFFFFE00
_08023E0C: .4byte gMain+0x2858 @gMain.spriteGroups[52]
_08023E10: .4byte gCurrentPinballGame
_08023E14: .4byte gMain+0x2860 @gMain.spriteGroups[52].oam

	thumb_func_start sub_23E18
sub_23E18: @ 0x08023E18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #1
	str r0, [sp]
	ldr r1, _08023F00 @ =gMain+0x27A0 @gMain.spriteGroups[51]
	mov sl, r1
	ldr r5, _08023F04 @ =0xFFFFD860
	add r5, sl
	ldr r0, [r5, #0x4c]
	movs r1, #0x24
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r7, _08023F08 @ =gCurrentPinballGame
	ldr r0, [r7]
	ldr r2, _08023F0C @ =0x00000746
	mov sb, r2
	add r0, sb
	movs r3, #0
	mov r8, r3
	mov r6, r8
	strb r6, [r0]
	ldr r0, [r7]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0]
	ldr r6, [r7]
	ldr r3, _08023F10 @ =0x000002DA
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bgt _08023F30
	ldr r5, _08023F14 @ =gUnknown_086AE0B4
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	adds r0, r0, r5
	ldrh r1, [r0]
	ldr r2, _08023F0C @ =0x00000746
	adds r0, r6, r2
	strb r1, [r0]
	ldr r5, [r7]
	ldr r2, _08023F18 @ =gUnknown_086AE0A4
	ldr r3, _08023F10 @ =0x000002DA
	adds r1, r5, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r6, #0xb5
	lsls r6, r6, #2
	adds r3, r5, r6
	strh r0, [r3]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	ldr r7, _08023F1C @ =0x000002D6
	adds r2, r5, r7
	strh r0, [r2]
	adds r1, r5, #0
	adds r1, #0x58
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r5, #0
	adds r1, #0x5a
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sl
	strh r0, [r2, #4]
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08023EDE
	b _08024226
_08023EDE:
	ldr r2, _08023F20 @ =0x040000D4
	mov r3, sb
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023F24 @ =gUnknown_08449D8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023F28 @ =0x06013300
	str r0, [r2, #4]
	ldr r0, _08023F2C @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08024226
	.align 2, 0
_08023F00: .4byte gMain+0x27A0 @gMain.spriteGroups[51]
_08023F04: .4byte 0xFFFFD860
_08023F08: .4byte gCurrentPinballGame
_08023F0C: .4byte 0x00000746
_08023F10: .4byte 0x000002DA
_08023F14: .4byte gUnknown_086AE0B4
_08023F18: .4byte gUnknown_086AE0A4
_08023F1C: .4byte 0x000002D6
_08023F20: .4byte 0x040000D4
_08023F24: .4byte gUnknown_08449D8C
_08023F28: .4byte 0x06013300
_08023F2C: .4byte 0x80000140
_08023F30:
	cmp r0, #3
	beq _08023F36
	b _080241D4
_08023F36:
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08024004
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r4, r6, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #1
	bne _08023FCA
	movs r3, #2
	strb r3, [r4]
	ldr r0, [r7]
	add r0, sb
	mov r6, sp
	ldrb r6, [r6]
	strb r6, [r0]
	ldr r2, _08023FEC @ =0x040000D4
	ldr r4, [r7]
	mov r1, sb
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08023FF0 @ =gUnknown_08449D8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08023FF4 @ =0x06013300
	str r0, [r2, #4]
	ldr r0, _08023FF8 @ =0x80000140
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldrb r0, [r5, #0xf]
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xf]
	adds r0, r4, #0
	adds r0, #0xea
	movs r2, #0
	mov r6, r8
	strh r6, [r0]
	adds r1, r4, #0
	adds r1, #0xec
	movs r0, #0x3c
	strh r0, [r1]
	subs r1, #4
	movs r0, #0x48
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe6
	strh r6, [r0]
	adds r0, #8
	strh r3, [r0]
	adds r0, #4
	strb r2, [r0]
	ldr r0, [r7]
	adds r0, #0xfa
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0xfb
	strb r2, [r0]
	ldr r0, [r7]
	ldr r2, _08023FFC @ =0x000002DE
	adds r0, r0, r2
	movs r1, #0x30
	strh r1, [r0]
_08023FCA:
	ldr r0, [r7]
	ldr r3, _08024000 @ =0x000002D9
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08023FDA
	b _080240FA
_08023FDA:
	mov r6, r8
	strb r6, [r1]
	ldr r0, [r7]
	ldr r7, _08023FFC @ =0x000002DE
	adds r0, r0, r7
	movs r1, #0x30
	strh r1, [r0]
	b _080240FA
	.align 2, 0
_08023FEC: .4byte 0x040000D4
_08023FF0: .4byte gUnknown_08449D8C
_08023FF4: .4byte 0x06013300
_08023FF8: .4byte 0x80000140
_08023FFC: .4byte 0x000002DE
_08024000: .4byte 0x000002D9
_08024004:
	ldr r0, _0802407C @ =0x000002DE
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _080240A8
	movs r5, #0xb8
	lsls r5, r5, #2
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _0802406A
	mov r1, r8
	strb r1, [r6, #0x1f]
	ldr r1, [r7]
	movs r4, #0
	movs r0, #0x3c
	strh r0, [r1, #0x26]
	ldr r2, _08024080 @ =0x0000132C
	adds r1, r1, r2
	ldr r2, [r1]
	movs r0, #0x14
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	movs r0, #0xc8
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	movs r0, #0x58
	strh r0, [r2, #0x10]
	ldr r2, [r1]
	movs r0, #0xa3
	strh r0, [r2, #0x12]
	ldr r0, [r1]
	mov r3, r8
	strh r3, [r0, #6]
	ldr r2, [r1]
	movs r6, #0x10
	ldrsh r0, [r2, r6]
	lsls r0, r0, #1
	strh r0, [r2, #0x28]
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	movs r0, 0xB9 @=SE_UNKNOWN_0xB9
	bl m4aSongNumStart
	ldr r0, [r7]
	ldr r3, _08024084 @ =0x000005FA
	adds r0, r0, r3
	strb r4, [r0]
_0802406A:
	ldr r0, [r7]
	adds r1, r0, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _08024088
	subs r0, #1
	strh r0, [r1]
	b _080240FA
	.align 2, 0
_0802407C: .4byte 0x000002DE
_08024080: .4byte 0x0000132C
_08024084: .4byte 0x000005FA
_08024088:
	bl sub_23954
	ldr r0, [r7]
	ldr r6, _080240A4 @ =0x000002DA
	adds r0, r0, r6
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r7]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r0, r2
	strb r1, [r0]
	b _080240FA
	.align 2, 0
_080240A4: .4byte 0x000002DA
_080240A8:
	ldr r3, _08024184 @ =0x0000132C
	adds r4, r6, r3
	ldr r1, [r4]
	movs r0, #0x58
	strh r0, [r1, #0x10]
	ldr r5, [r4]
	ldrh r0, [r2]
	movs r1, #3
	bl __udivsi3
	movs r1, #0xa3
	subs r1, r1, r0
	strh r1, [r5, #0x12]
	ldr r0, [r4]
	mov r7, r8
	strh r7, [r0, #6]
	ldr r1, [r4]
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	strh r0, [r1, #0x28]
	ldr r1, [r4]
	movs r3, #0x12
	ldrsh r0, [r1, r3]
	lsls r0, r0, #1
	strh r0, [r1, #0x2a]
	ldr r1, [r4]
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	lsls r0, r0, #8
	str r0, [r1, #0x34]
	ldr r1, [r4]
	movs r2, #0x12
	ldrsh r0, [r1, r2]
	lsls r0, r0, #8
	str r0, [r1, #0x38]
	ldr r3, _08024188 @ =0x000005FA
	adds r0, r6, r3
	mov r6, sp
	ldrb r6, [r6]
	strb r6, [r0]
_080240FA:
	ldr r6, _0802418C @ =gCurrentPinballGame
	ldr r7, [r6]
	ldr r1, _08024190 @ =gUnknown_086AE0A4
	ldr r0, _08024194 @ =0x000002DA
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r5, r7, r2
	strh r0, [r5]
	mov r3, r8
	movs r4, #0
	ldrsb r4, [r3, r4]
	lsls r4, r4, #2
	adds r4, r4, r1
	ldr r1, _08024198 @ =0x000002DE
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r1, #3
	bl __udivsi3
	ldrh r1, [r4, #2]
	subs r1, r1, r0
	ldr r3, _0802419C @ =0x000002D6
	adds r2, r7, r3
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0x58
	ldrh r0, [r5]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r7, #0
	adds r1, #0x5a
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r2, sl
	strh r0, [r2, #4]
	movs r0, #0x13
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bgt _080241AE
	mov r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #3
	bne _080241A0
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080241A0
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r0, #1
	b _080241B6
	.align 2, 0
_08024184: .4byte 0x0000132C
_08024188: .4byte 0x000005FA
_0802418C: .4byte gCurrentPinballGame
_08024190: .4byte gUnknown_086AE0A4
_08024194: .4byte 0x000002DA
_08024198: .4byte 0x000002DE
_0802419C: .4byte 0x000002D6
_080241A0:
	ldr r0, [r6]
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	b _080241B8
_080241AE:
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r0, #0
_080241B6:
	strb r0, [r1]
_080241B8:
	ldr r0, [r6]
	ldr r1, _080241D0 @ =0x000002DE
	adds r6, r0, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _08024226
	subs r0, #1
	strh r0, [r6]
	movs r2, #2
	str r2, [sp]
	b _08024226
	.align 2, 0
_080241D0: .4byte 0x000002DE
_080241D4:
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0802420C
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r7]
	adds r0, r0, r3
	movs r1, #4
	strb r1, [r0]
	ldr r0, [r7]
	adds r3, #1
	adds r1, r0, r3
	movs r0, #8
	strb r0, [r1]
	ldr r0, [r7]
	movs r6, #0xf8
	lsls r6, r6, #1
	adds r0, r0, r6
	mov r1, r8
	strh r1, [r0]
_0802420C:
	ldr r0, [r7]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r0, r2
	mov r3, r8
	strh r3, [r1]
	ldr r6, _080242A4 @ =0x000002D6
	adds r0, r0, r6
	strh r3, [r0]
	mov r7, sl
	strh r3, [r7, #2]
	movs r0, #0xa0
	strh r0, [r7, #4]
_08024226:
	movs r0, #0
	ldr r6, _080242A8 @ =gOamBuffer
	ldr r1, [sp]
	lsls r1, r1, #2
	mov ip, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	mov sb, r2
	ldr r3, _080242AC @ =0xFFFFFE00
	mov r8, r3
_0802423A:
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	lsls r4, r5, #3
	adds r4, #8
	add r4, sl
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	ldrb r2, [r1, #5]
	mov r0, sb
	ands r0, r2
	mov r7, ip
	orrs r0, r7
	strb r0, [r1, #5]
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r4, r0]
	mov r2, sl
	movs r7, #2
	ldrsh r0, [r2, r7]
	adds r1, r1, r0
	ldr r2, _080242B0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, sl
	ldrb r0, [r3, #4]
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	strb r0, [r1]
	adds r5, #1
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	asrs r5, r5, #0x10
	cmp r5, #1
	ble _0802423A
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080242A4: .4byte 0x000002D6
_080242A8: .4byte gOamBuffer
_080242AC: .4byte 0xFFFFFE00
_080242B0: .4byte 0x000001FF

	thumb_func_start sub_242B4
sub_242B4: @ 0x080242B4
	push {r4, r5, lr}
	ldr r0, _080242C8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _080242D0
	ldr r0, _080242CC @ =gCurrentPinballGame
	ldr r0, [r0]
	movs r1, #0xb4
	lsls r1, r1, #2
	b _080242D6
	.align 2, 0
_080242C8: .4byte gMain
_080242CC: .4byte gCurrentPinballGame
_080242D0:
	ldr r0, _0802431C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _08024320 @ =0x00000343
_080242D6:
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r5, _0802431C @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r1, _08024324 @ =0x000005A5
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	movs r0, #0
	movs r1, #0
	bl sub_1C7F4
	ldr r0, [r5]
	ldr r1, _08024328 @ =0x000006C4
	adds r0, r0, r1
	strb r4, [r0]
	movs r2, #0
	ldr r5, _0802432C @ =0x0000071D
_080242FC:
	ldr r0, _0802431C @ =gCurrentPinballGame
	ldr r3, [r0]
	ldr r0, _08024330 @ =0x00000723
	adds r1, r3, r0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r4, r0, #0
	cmp r2, r1
	bge _08024334
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #1
	b _0802433A
	.align 2, 0
_0802431C: .4byte gCurrentPinballGame
_08024320: .4byte 0x00000343
_08024324: .4byte 0x000005A5
_08024328: .4byte 0x000006C4
_0802432C: .4byte 0x0000071D
_08024330: .4byte 0x00000723
_08024334:
	adds r0, r3, r5
	adds r0, r0, r2
	movs r1, #0
_0802433A:
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _080242FC
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_24350
sub_24350: @ 0x08024350
	push {r4, r5, lr}
	ldr r4, _0802439C @ =gCurrentPinballGame
	ldr r0, [r4]
	movs r3, #0
	strb r3, [r0, #0x17]
	ldr r1, [r4]
	movs r5, #0
	strh r3, [r1, #0x18]
	ldr r0, _080243A0 @ =0x00000724
	adds r2, r1, r0
	subs r0, #0x1c
	strh r0, [r2]
	ldr r0, _080243A4 @ =0x000005A5
	adds r1, r1, r0
	strb r5, [r1]
	ldr r2, [r4]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	adds r1, #2
	adds r0, r2, r1
	strh r3, [r0]
	ldr r0, _080243A8 @ =gMain
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _080243B0
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _080243AC @ =0x000002EE
	str r0, [r1]
	subs r0, #0xee
	adds r1, r2, r0
	movs r0, #0x82
	lsls r0, r0, #3
	b _080243C4
	.align 2, 0
_0802439C: .4byte gCurrentPinballGame
_080243A0: .4byte 0x00000724
_080243A4: .4byte 0x000005A5
_080243A8: .4byte gMain
_080243AC: .4byte 0x000002EE
_080243B0:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0xf5
	lsls r0, r0, #3
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r2, r0
	subs r0, #0xd4
_080243C4:
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	strb r2, [r0]
	ldr r0, [r4]
	ldr r3, _080243FC @ =0x00000206
	adds r1, r0, r3
	movs r3, #0
	strh r2, [r1]
	movs r4, #0xfc
	lsls r4, r4, #1
	adds r1, r0, r4
	strh r2, [r1]
	adds r4, #2
	adds r1, r0, r4
	strh r2, [r1]
	ldr r4, _08024400 @ =0x000005AA
	adds r1, r0, r4
	strh r2, [r1]
	ldr r1, _08024404 @ =0x000005A9
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080243FC: .4byte 0x00000206
_08024400: .4byte 0x000005AA
_08024404: .4byte 0x000005A9
