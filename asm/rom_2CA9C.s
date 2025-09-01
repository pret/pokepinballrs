#include "constants/global.h"
#include "constants/bg_music.h"
	.include "asm/macros.inc"

	.syntax unified
	.text

	thumb_func_start sub_2CA9C
sub_2CA9C: @ 0x0802CA9C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov ip, r0
	ldr r0, _0802CADC @ =gMain
	ldr r0, [r0, #0x44]
	adds r0, #0xc8
	ldr r6, [r0]
	ldrh r0, [r6]
	cmp r0, #0
	bne _0802CAB8
	b _0802CCF2
_0802CAB8:
	movs r0, #0xca
	strh r0, [r6, #2]
	ldr r0, _0802CAE0 @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0802CAE4 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x30
	bls _0802CB44
	subs r0, #0x30
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x21
	ble _0802CAE8
	movs r1, #0x2a
	subs r1, r1, r0
	lsls r1, r1, #1
	b _0802CB12
	.align 2, 0
_0802CADC: .4byte gMain
_0802CAE0: .4byte gCurrentPinballGame
_0802CAE4: .4byte 0x00000286
_0802CAE8:
	cmp r0, #0x17
	ble _0802CAFC
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #1
	ldr r3, _0802CAF8 @ =0x0000FFF7
	mov ip, r3
	b _0802CB1A
	.align 2, 0
_0802CAF8: .4byte 0x0000FFF7
_0802CAFC:
	cmp r0, #7
	ble _0802CB10
	movs r0, #0x82
	strh r0, [r6, #4]
	movs r0, #2
	ldr r1, _0802CB0C @ =0x0000FFFC
	mov ip, r1
	b _0802CB1A
	.align 2, 0
_0802CB0C: .4byte 0x0000FFFC
_0802CB10:
	lsls r1, r0, #1
_0802CB12:
	movs r0, #0x92
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r0, #0
_0802CB1A:
	ldr r2, _0802CB34 @ =0x040000D4
	lsls r0, r0, #0x10
	asrs r0, r0, #7
	ldr r1, _0802CB38 @ =gUnknown_08455E8C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802CB3C @ =0x060152A0
	str r0, [r2, #4]
	ldr r0, _0802CB40 @ =0x80000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0802CB48
	.align 2, 0
_0802CB34: .4byte 0x040000D4
_0802CB38: .4byte gUnknown_08455E8C
_0802CB3C: .4byte 0x060152A0
_0802CB40: .4byte 0x80000100
_0802CB44:
	movs r0, #0xb4
	strh r0, [r6, #4]
_0802CB48:
	adds r5, r6, #0
	adds r5, #8
	ldr r4, _0802CB90 @ =gOamBuffer
	ldrh r2, [r6, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r3, _0802CB94 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _0802CB98 @ =0xFFFFFE00
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
	ldr r0, _0802CB9C @ =gCurrentPinballGame
	ldr r0, [r0]
	ldr r1, _0802CBA0 @ =0x00000286
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0x38
	bls _0802CBA4
	movs r7, #0x80
	lsls r7, r7, #1
	b _0802CBD6
	.align 2, 0
_0802CB90: .4byte gOamBuffer
_0802CB94: .4byte 0x000001FF
_0802CB98: .4byte 0xFFFFFE00
_0802CB9C: .4byte gCurrentPinballGame
_0802CBA0: .4byte 0x00000286
_0802CBA4:
	subs r0, #0x24
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _0802CBCC
	lsls r0, r0, #7
	movs r1, #0x14
	bl __divsi3
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0x82
	strh r0, [r6, #4]
	ldr r3, _0802CBC8 @ =0x0000FFFE
	mov ip, r3
	b _0802CBD6
	.align 2, 0
_0802CBC8: .4byte 0x0000FFFE
_0802CBCC:
	movs r7, #0x80
	movs r0, #0xb4
	strh r0, [r6, #4]
	movs r0, #0
	mov ip, r0
_0802CBD6:
	adds r5, r6, #0
	adds r5, #0x10
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r0, [r6, r3]
	adds r1, r1, r0
	ldr r0, _0802CCA8 @ =0x000001FF
	mov r8, r0
	mov r3, r8
	ands r1, r3
	ldrh r3, [r2, #2]
	ldr r0, _0802CCAC @ =0xFFFFFE00
	mov sb, r0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x10]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r6, #4]
	ldrb r5, [r5, #4]
	adds r0, r0, r5
	add r0, ip
	strb r0, [r1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r6, #0x10]
	lsls r2, r2, #3
	adds r2, r2, r4
	ldrb r1, [r2, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2, #3]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	movs r2, #6
	bl SetMatrixScale
	ldr r0, _0802CCB0 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r0, _0802CCB4 @ =0x00000286
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0x39
	bhi _0802CCC8
	adds r0, r1, #0
	adds r0, #0x30
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrh r1, [r3]
	movs r0, #0xf
	ands r1, r0
	lsrs r1, r1, #3
	lsls r0, r1, #3
	adds r0, r0, r1
	subs r0, #1
	ldr r1, _0802CCB8 @ =0x040000D4
	adds r2, r2, r0
	lsls r2, r2, #6
	ldr r0, _0802CCBC @ =gUnknown_0845648C
	adds r2, r2, r0
	str r2, [r1]
	ldr r0, _0802CCC0 @ =0x06015520
	str r0, [r1, #4]
	ldr r0, _0802CCC4 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x70
	b _0802CCF0
	.align 2, 0
_0802CCA8: .4byte 0x000001FF
_0802CCAC: .4byte 0xFFFFFE00
_0802CCB0: .4byte gCurrentPinballGame
_0802CCB4: .4byte 0x00000286
_0802CCB8: .4byte 0x040000D4
_0802CCBC: .4byte gUnknown_0845648C
_0802CCC0: .4byte 0x06015520
_0802CCC4: .4byte 0x80000020
_0802CCC8:
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r2, [r6, #0x18]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r5, r3]
	adds r1, #0xd8
	mov r0, r8
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sb
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x18]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r5, #4]
	subs r0, #0x4c
_0802CCF0:
	strb r0, [r1]
_0802CCF2:
	ldr r5, _0802CD74 @ =gCurrentPinballGame
	ldr r0, [r5]
	ldr r4, _0802CD78 @ =0x00000286
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _0802CD68
	cmp r0, #0x5a
	bne _0802CD18
	movs r0, #1
	strh r0, [r6]
	ldr r1, _0802CD7C @ =0x040000D4
	ldr r0, _0802CD80 @ =gUnknown_086AE324
	str r0, [r1]
	ldr r0, _0802CD84 @ =0x05000380
	str r0, [r1, #4]
	ldr r0, _0802CD88 @ =0x80000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0802CD18:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x55
	bne _0802CD2A
	ldr r0, _0802CD8C @ =gMPlayInfo_SE1
	ldr r1, _0802CD90 @ =gUnknown_086A1ABC
	bl MPlayStart
_0802CD2A:
	ldr r0, [r5]
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x3a
	bne _0802CD50
	ldr r0, _0802CD8C @ =gMPlayInfo_SE1
	ldr r1, _0802CD94 @ =gUnknown_0869F2A0
	bl MPlayStart
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #8
	bgt _0802CD50
	adds r0, r2, #1
	strb r0, [r1]
_0802CD50:
	ldr r0, _0802CD74 @ =gCurrentPinballGame
	ldr r1, [r0]
	ldr r3, _0802CD78 @ =0x00000286
	adds r1, r1, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0802CD68
	strh r0, [r6]
_0802CD68:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD74: .4byte gCurrentPinballGame
_0802CD78: .4byte 0x00000286
_0802CD7C: .4byte 0x040000D4
_0802CD80: .4byte gUnknown_086AE324
_0802CD84: .4byte 0x05000380
_0802CD88: .4byte 0x80000010
_0802CD8C: .4byte gMPlayInfo_SE1
_0802CD90: .4byte gUnknown_086A1ABC
_0802CD94: .4byte gUnknown_0869F2A0
