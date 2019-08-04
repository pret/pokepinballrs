	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_528AC
sub_528AC: @ 0x080528AC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #0xfa
	bls _080528DA
	ldr r0, _080528CC @ =0x00000113
	cmp r1, r0
	bls _080528D8
	ldr r0, _080528D0 @ =gUnknown_08527F18
	ldr r2, _080528D4 @ =0xFFFFFEEC
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b _080528DA
	.align 2, 0
_080528CC: .4byte 0x00000113
_080528D0: .4byte gUnknown_08527F18
_080528D4: .4byte 0xFFFFFEEC
_080528D8:
	movs r0, #0xc8
_080528DA:
	bx lr

	thumb_func_start sub_528DC
sub_528DC: @ 0x080528DC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08052914 @ =gMPlayInfo_BGM
	ldr r1, _08052918 @ =0x0000FFFF
	movs r2, #0x99
	bl m4aMPlayVolumeControl
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x7d
	movs r3, #0xa
	bl sub_52940
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052914: .4byte gMPlayInfo_BGM
_08052918: .4byte 0x0000FFFF

	thumb_func_start sub_5291C
sub_5291C: @ 0x0805291C
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r4, #0
	str r4, [sp]
	bl sub_52940
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_52940
sub_52940: @ 0x08052940
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r2, #0
	adds r6, r3, #0
	lsls r5, r5, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r1, _080529BC @ =0xFFFF0000
	adds r5, r5, r1
	lsrs r5, r5, #0x10
	movs r1, #0xf0
	lsls r1, r1, #6
	mov r8, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl SetPokemonCryVolume
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	bl SetPokemonCryPanpot
	mov r0, r8
	bl SetPokemonCryPitch
	movs r0, #0x8c
	bl SetPokemonCryLength
	movs r0, #0
	bl SetPokemonCryProgress
	movs r0, #0
	bl SetPokemonCryRelease
	movs r0, #0
	bl SetPokemonCryChorus
	adds r0, r6, #0
	bl SetPokemonCryPriority
	adds r0, r5, #0
	bl sub_528AC
	movs r1, #0x7f
	ands r1, r0
	lsrs r0, r0, #7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	cmp r0, #1
	beq _080529D8
	cmp r0, #1
	bgt _080529C0
	cmp r0, #0
	beq _080529CA
	b _08052A0A
	.align 2, 0
_080529BC: .4byte 0xFFFF0000
_080529C0:
	cmp r2, #2
	beq _080529E8
	cmp r2, #3
	beq _080529FC
	b _08052A0A
_080529CA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080529D4 @ =gUnknown_08532D6C
	b _080529F0
	.align 2, 0
_080529D4: .4byte gUnknown_08532D6C
_080529D8:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080529E4 @ =gUnknown_08533360
	b _080529F0
	.align 2, 0
_080529E4: .4byte gUnknown_08533360
_080529E8:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080529F8 @ =gUnknown_08533960
_080529F0:
	adds r0, r0, r1
	bl SetPokemonCryTone
	b _08052A0A
	.align 2, 0
_080529F8: .4byte gUnknown_08533960
_080529FC:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08052A14 @ =gUnknown_08533F60
	adds r0, r0, r1
	bl SetPokemonCryTone
_08052A0A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052A14: .4byte gUnknown_08533F60

	thumb_func_start sub_52A18
sub_52A18: @ 0x08052A18
	push {r4, lr}
	bl sub_555BC
	ldr r4, _08052A4C @ =gMain
	movs r0, #0
	strb r0, [r4, #0xc]
	bl sub_52A68
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08052A50
	bl sub_52C64
	bl sub_52B30
	bl sub_52A68
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08052A5E
	movs r0, #1
	strb r0, [r4, #0xc]
	bl sub_52C64
	b _08052A5E
	.align 2, 0
_08052A4C: .4byte gMain
_08052A50:
	ldr r1, _08052A64 @ =0x00000143
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_525CC
_08052A5E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052A64: .4byte 0x00000143

	thumb_func_start sub_52A68
sub_52A68: @ 0x08052A68
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #0
	mov r8, r0
	movs r7, #0
	ldr r1, _08052B04 @ =gUnknown_02032FF0
	mov sb, r1
_08052A7A:
	ldr r5, _08052B08 @ =gUnknown_0200B134
	movs r4, #0x9d
	lsls r4, r4, #2
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r3, _08052B0C @ =0x0E000004
	adds r0, r0, r3
	mov r6, sb
	ldr r3, [r6]
	adds r1, r5, #0
	adds r2, r4, #0
	bl _call_via_r3
	movs r2, #0
	movs r0, #0x99
	lsls r0, r0, #2
	adds r3, r5, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r1, _08052B10 @ =gUnknown_086BBA6C
	ldrb r6, [r1]
	cmp r0, r6
	bne _08052ACA
	adds r6, r3, #0
	adds r3, r1, #0
_08052AB2:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #9
	bhi _08052ACA
	adds r0, r2, r6
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	beq _08052AB2
_08052ACA:
	cmp r2, #0xa
	bne _08052B18
	movs r2, #0
	cmp r4, #1
	bls _08052AE0
_08052AD4:
	ldrh r0, [r5]
	adds r2, r2, r0
	adds r5, #2
	subs r4, #2
	cmp r4, #1
	bhi _08052AD4
_08052AE0:
	cmp r4, #0
	beq _08052AF0
	ldrh r1, [r5]
	movs r3, #0xff
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r0, r1
	adds r2, r2, r0
_08052AF0:
	ldr r0, _08052B14 @ =0x0000FFFF
	adds r1, r2, #0
	ands r1, r0
	lsrs r2, r2, #0x10
	adds r2, r1, r2
	cmp r2, r0
	bne _08052B18
	movs r6, #1
	mov r8, r6
	b _08052B22
	.align 2, 0
_08052B04: .4byte gUnknown_02032FF0
_08052B08: .4byte gUnknown_0200B134
_08052B0C: .4byte 0x0E000004
_08052B10: .4byte gUnknown_086BBA6C
_08052B14: .4byte 0x0000FFFF
_08052B18:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #1
	bls _08052A7A
_08052B22:
	mov r0, r8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_52B30
sub_52B30: @ 0x08052B30
	push {r4, r5, lr}
	ldr r3, _08052B9C @ =gUnknown_0200B134
	movs r4, #0x9d
	lsls r4, r4, #2
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r2, _08052BA0 @ =0x0000026E
	adds r1, r3, r2
	movs r0, #0
	strh r0, [r1]
	movs r2, #0
	adds r5, r3, #0
_08052B50:
	ldrh r0, [r3]
	adds r2, r2, r0
	adds r3, #2
	subs r4, #2
	cmp r4, #1
	bhi _08052B50
	cmp r4, #0
	beq _08052B6A
	ldrh r1, [r3]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	adds r2, r2, r0
_08052B6A:
	ldr r0, _08052BA4 @ =0x0000FFFF
	ands r0, r2
	lsrs r1, r2, #0x10
	adds r2, r0, r1
	lsrs r0, r2, #0x10
	adds r0, r0, r2
	mvns r0, r0
	ldr r2, _08052BA0 @ =0x0000026E
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _08052BA8 @ =0x0E000004
	movs r4, #0x9d
	lsls r4, r4, #2
	adds r0, r5, #0
	adds r2, r4, #0
	bl sub_55654
	ldr r1, _08052BAC @ =0x0E0002A4
	adds r0, r5, #0
	adds r2, r4, #0
	bl sub_55654
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052B9C: .4byte gUnknown_0200B134
_08052BA0: .4byte 0x0000026E
_08052BA4: .4byte 0x0000FFFF
_08052BA8: .4byte 0x0E000004
_08052BAC: .4byte 0x0E0002A4

	thumb_func_start sub_52BB0
sub_52BB0: @ 0x08052BB0
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r3, _08052C30 @ =gUnknown_0200B134
	movs r4, #0x9d
	lsls r4, r4, #2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r3
	ldrb r0, [r2]
	adds r6, r3, #0
	cmp r0, r5
	bhs _08052C28
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r1, #0
	strb r5, [r2]
	ldr r2, _08052C34 @ =0x0000026E
	adds r0, r6, r2
	strh r1, [r0]
	movs r2, #0
_08052BE2:
	ldrh r0, [r3]
	adds r2, r2, r0
	adds r3, #2
	subs r4, #2
	cmp r4, #1
	bhi _08052BE2
	cmp r4, #0
	beq _08052BFC
	ldrh r1, [r3]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	adds r2, r2, r0
_08052BFC:
	ldr r0, _08052C38 @ =0x0000FFFF
	ands r0, r2
	lsrs r1, r2, #0x10
	adds r2, r0, r1
	lsrs r0, r2, #0x10
	adds r0, r0, r2
	mvns r0, r0
	ldr r2, _08052C34 @ =0x0000026E
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08052C3C @ =0x0E000004
	movs r4, #0x9d
	lsls r4, r4, #2
	adds r0, r6, #0
	adds r2, r4, #0
	bl sub_55654
	ldr r1, _08052C40 @ =0x0E0002A4
	adds r0, r6, #0
	adds r2, r4, #0
	bl sub_55654
_08052C28:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052C30: .4byte gUnknown_0200B134
_08052C34: .4byte 0x0000026E
_08052C38: .4byte 0x0000FFFF
_08052C3C: .4byte 0x0E000004
_08052C40: .4byte 0x0E0002A4

	thumb_func_start sub_52C44
sub_52C44: @ 0x08052C44
	push {lr}
	ldr r2, _08052C58 @ =gUnknown_02032FF0
	ldr r0, _08052C5C @ =0x0E000544
	ldr r1, _08052C60 @ =gUnknown_0200B100
	ldr r3, [r2]
	movs r2, #4
	bl _call_via_r3
	pop {r0}
	bx r0
	.align 2, 0
_08052C58: .4byte gUnknown_02032FF0
_08052C5C: .4byte 0x0E000544
_08052C60: .4byte gUnknown_0200B100

	thumb_func_start sub_52C64
sub_52C64: @ 0x08052C64
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _08052CBC @ =gUnknown_0200B134
	movs r0, #0x99
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r3, _08052CC0 @ =gUnknown_086BBA6C
_08052C72:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, r4
	adds r1, r0, r3
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08052C72
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #0
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0xcd
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_525CC
	bl sub_F6E0
	bl sub_8ABC
	adds r0, r5, #0
	adds r0, #0xcf
	strb r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052CBC: .4byte gUnknown_0200B134
_08052CC0: .4byte gUnknown_086BBA6C
