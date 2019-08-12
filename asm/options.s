	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_51C9C
sub_51C9C: @ 0x08051C9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	ldr r0, _08051D38 @ =gUnknown_0200B3B8
	mov r8, r0
	ldr r2, _08051D3C @ =gOptionsData
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r0, #0xe6
	lsls r0, r0, #4
	muls r1, r0, r1
	movs r0, #0xa1
	lsls r0, r0, #3
	add r0, r8
	adds r1, r1, r0
	str r1, [sp, #0x60]
	add r4, sp, #0xc
	mov sl, r4
	mov r6, sp
	adds r6, #0x18
	str r6, [sp, #0x6c]
	mov r7, sp
	adds r7, #0x1c
	str r7, [sp, #0x74]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x7c]
	movs r0, #0xb8
	lsls r0, r0, #2
	add r0, r8
	mov r3, sl
	mov r1, r8
	adds r1, #0xb8
	mov r2, sp
	movs r4, #2
	mov ip, r4
_08051CEA:
	stm r2!, {r1}
	stm r3!, {r0}
	adds r0, #0xb8
	adds r1, #0xb8
	movs r6, #1
	rsbs r6, r6, #0
	add ip, r6
	mov r7, ip
	cmp r7, #0
	bge _08051CEA
	movs r0, #0
	mov ip, r0
	movs r1, #8
	add r1, r8
	mov sb, r1
	ldr r2, _08051D40 @ =gUnknown_0200B978
	adds r2, #8
	str r2, [sp, #0x70]
	ldr r0, _08051D44 @ =gUnknown_0200BAE8
	adds r4, r0, #0
	adds r4, #0xb8
	adds r5, r0, #0
	movs r3, #0
	ldr r1, [sp, #0x6c]
	adds r2, r5, #0
	subs r2, #0xb8
_08051D1E:
	ldr r0, _08051D48 @ =gUnknown_0200293A
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #1
	bne _08051D50
	ldr r6, _08051D3C @ =gOptionsData
	movs r7, #6
	ldrsh r0, [r6, r7]
	cmp r0, #1
	bne _08051D50
	ldr r0, _08051D4C @ =gUnknown_0200C7D8
	str r0, [r1]
	b _08051D52
	.align 2, 0
_08051D38: .4byte gUnknown_0200B3B8
_08051D3C: .4byte gOptionsData
_08051D40: .4byte gUnknown_0200B978
_08051D44: .4byte gUnknown_0200BAE8
_08051D48: .4byte gUnknown_0200293A
_08051D4C: .4byte gUnknown_0200C7D8
_08051D50:
	str r2, [r1]
_08051D52:
	ldr r6, [sp, #0x74]
	adds r0, r6, r3
	str r5, [r0]
	ldr r7, [sp, #0x7c]
	adds r0, r7, r3
	str r4, [r0]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r5, r5, r0
	adds r2, r2, r0
	adds r3, #0xc
	adds r1, #0xc
	movs r6, #1
	add ip, r6
	mov r7, ip
	cmp r7, #5
	ble _08051D1E
	ldr r0, _08051F64 @ =gUnknown_0200C890
	str r0, [sp, #0x64]
	movs r0, #1
	mov r1, r8
	strh r0, [r1]
	movs r2, #1
	mov r1, sp
	movs r3, #2
	mov ip, r3
_08051D88:
	ldm r1!, {r0}
	strh r2, [r0]
	movs r4, #1
	rsbs r4, r4, #0
	add ip, r4
	mov r6, ip
	cmp r6, #0
	bge _08051D88
	ldr r7, [sp, #0x64]
	adds r7, #8
	str r7, [sp, #0x78]
	movs r2, #1
	mov r1, sl
	movs r0, #2
	mov ip, r0
_08051DA6:
	ldm r1!, {r0}
	strh r2, [r0]
	movs r3, #1
	rsbs r3, r3, #0
	add ip, r3
	mov r4, ip
	cmp r4, #0
	bge _08051DA6
	movs r0, #1
	ldr r6, [sp, #0x60]
	strh r0, [r6]
	ldr r7, _08051F68 @ =gUnknown_0200B978
	strh r0, [r7]
	movs r0, #0
	mov ip, r0
	ldr r6, [sp, #0x6c]
	movs r3, #1
	movs r2, #0
_08051DCA:
	adds r1, r2, r6
	movs r5, #2
_08051DCE:
	ldm r1!, {r0}
	strh r3, [r0]
	subs r5, #1
	cmp r5, #0
	bge _08051DCE
	adds r2, #0xc
	movs r1, #1
	add ip, r1
	mov r4, ip
	cmp r4, #5
	ble _08051DCA
	movs r0, #1
	ldr r6, [sp, #0x64]
	strh r0, [r6]
	ldr r7, _08051F6C @ =gUnknown_0200C948
	strh r0, [r7]
	ldr r5, _08051F70 @ =gOptionsData
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _08051F74 @ =gUnknown_0200CA00
	strh r0, [r1]
	ldr r0, _08051F78 @ =gUnknown_086BB9EC
	movs r1, #0x20
	ldr r2, _08051F7C @ =gUnknown_0200B3B8
	bl LoadSpriteSets
	ldr r2, _08051F80 @ =gUnknown_086BB968
	movs r3, #0xa
	ldrsh r1, [r5, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r5, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r4, r8
	strh r0, [r4, #2]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	mov r7, sb
	ldr r4, _08051F84 @ =gOamBuffer
	mov r0, r8
	ldrh r2, [r0, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r3, #2
	ldrsh r1, [r7, r3]
	movs r6, #2
	ldrsh r0, [r0, r6]
	adds r1, r1, r0
	ldr r3, _08051F88 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r6, _08051F8C @ =0xFFFFFE00
	adds r0, r6, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	mov r0, r8
	ldrh r1, [r0, #8]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	movs r1, #0
	mov ip, r1
	mov r8, r4
	mov r5, sp
	movs r2, #0x48
	mov sb, r2
_08051E6C:
	ldr r0, [r5]
	mov r3, sb
	strh r3, [r0, #2]
	ldr r1, [r5]
	movs r0, #0x20
	strh r0, [r1, #4]
	ldr r4, [r5]
	adds r7, r4, #0
	adds r7, #8
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	add r2, r8
	ldr r0, _08051F90 @ =gUnknown_02002932
	add r0, ip
	ldrb r1, [r0]
	adds r1, #0x16
	ldrh r3, [r2, #4]
	ldr r0, _08051F94 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r3, [r4, #8]
	lsls r3, r3, #3
	add r3, r8
	movs r0, #2
	ldrsh r1, [r7, r0]
	ldr r0, [r5]
	movs r2, #2
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _08051F88 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	adds r0, r6, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	add r1, r8
	ldm r5!, {r0}
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	movs r3, #7
	add sb, r3
	movs r4, #1
	add ip, r4
	mov r7, ip
	cmp r7, #2
	ble _08051E6C
	movs r0, #0
	mov ip, r0
	ldr r1, _08051F84 @ =gOamBuffer
	mov r8, r1
	movs r6, #0x48
	mov r5, sl
_08051EE2:
	ldr r0, [r5]
	strh r6, [r0, #2]
	ldr r0, [r5]
	movs r2, #0x2c
	mov sb, r2
	mov r3, sb
	strh r3, [r0, #4]
	ldr r4, [r5]
	adds r7, r4, #0
	adds r7, #8
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	add r2, r8
	ldr r0, _08051F98 @ =gUnknown_02002935
	add r0, ip
	ldrb r1, [r0]
	adds r1, #0x16
	ldrh r3, [r2, #4]
	ldr r0, _08051F94 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r3, [r4, #8]
	lsls r3, r3, #3
	add r3, r8
	movs r0, #2
	ldrsh r1, [r7, r0]
	ldr r0, [r5]
	movs r2, #2
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r2, _08051F88 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _08051F8C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	add r1, r8
	ldm r5!, {r0}
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r6, #7
	movs r3, #1
	add ip, r3
	mov r4, ip
	cmp r4, #2
	ble _08051EE2
	movs r0, #0x48
	ldr r6, [sp, #0x60]
	strh r0, [r6, #2]
	ldr r7, _08051F70 @ =gOptionsData
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bne _08051F9C
	movs r0, #0x20
	strh r0, [r6, #4]
	b _08051FA6
	.align 2, 0
_08051F64: .4byte gUnknown_0200C890
_08051F68: .4byte gUnknown_0200B978
_08051F6C: .4byte gUnknown_0200C948
_08051F70: .4byte gOptionsData
_08051F74: .4byte gUnknown_0200CA00
_08051F78: .4byte gUnknown_086BB9EC
_08051F7C: .4byte gUnknown_0200B3B8
_08051F80: .4byte gUnknown_086BB968
_08051F84: .4byte gOamBuffer
_08051F88: .4byte 0x000001FF
_08051F8C: .4byte 0xFFFFFE00
_08051F90: .4byte gUnknown_02002932
_08051F94: .4byte 0xFFFFFC00
_08051F98: .4byte gUnknown_02002935
_08051F9C:
	cmp r0, #1
	bne _08051FA6
	mov r3, sb
	ldr r2, [sp, #0x60]
	strh r3, [r2, #4]
_08051FA6:
	ldr r5, _080520D0 @ =gOamBuffer
	ldr r7, _080520D4 @ =0xFFFFFE00
	ldr r4, [sp, #0x60]
	adds r4, #8
	movs r6, #1
	mov ip, r6
_08051FB2:
	ldrh r3, [r4]
	lsls r3, r3, #3
	adds r3, r3, r5
	movs r0, #2
	ldrsh r1, [r4, r0]
	ldr r2, [sp, #0x60]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r1, r1, r0
	ldr r0, _080520D8 @ =0x000001FF
	adds r6, r0, #0
	ands r1, r6
	ldrh r2, [r3, #2]
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldr r2, [sp, #0x60]
	ldrb r0, [r2, #4]
	ldrb r3, [r4, #4]
	adds r0, r0, r3
	strb r0, [r1]
	adds r4, #8
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	mov r1, ip
	cmp r1, #0
	bge _08051FB2
	movs r0, #0x48
	ldr r2, _080520DC @ =gUnknown_0200B978
	strh r0, [r2, #2]
	ldr r3, _080520E0 @ =gOptionsData
	movs r4, #0xc
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	ldr r7, _080520E4 @ =gUnknown_086BB9A8
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r2, #4]
	ldr r7, [sp, #0x70]
	ldrh r2, [r2, #8]
	lsls r2, r2, #3
	ldr r0, _080520D0 @ =gOamBuffer
	adds r2, r2, r0
	movs r3, #2
	ldrsh r1, [r7, r3]
	adds r1, #0x48
	ands r1, r6
	ldrh r3, [r2, #2]
	ldr r0, _080520D4 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldr r4, _080520DC @ =gUnknown_0200B978
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r6, _080520D0 @ =gOamBuffer
	adds r1, r1, r6
	ldrb r0, [r4, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	movs r7, #0
	mov ip, r7
	ldr r0, _080520E0 @ =gOptionsData
	str r0, [sp, #0x68]
	movs r1, #0x54
	str r1, [sp, #0x80]
	movs r2, #0
	str r2, [sp, #0x84]
	movs r3, #0
	str r3, [sp, #0x88]
	ldr r4, [sp, #0x6c]
	mov r8, r4
_0805204E:
	ldr r0, [sp, #0x68]
	adds r0, #0x1a
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #1
	bne _080520E8
	mov r6, r8
	ldr r1, [r6]
	movs r0, #0x9c
	strh r0, [r1, #2]
	ldr r0, [r6]
	add r7, sp, #0x80
	ldrh r7, [r7]
	strh r7, [r0, #4]
	movs r5, #0
	ldr r1, [sp, #0x68]
	movs r2, #6
	ldrsh r0, [r1, r2]
	adds r0, #1
	cmp r5, r0
	blt _0805207A
	b _080522E2
_0805207A:
	ldr r3, [sp, #0x6c]
	ldr r6, [sp, #0x84]
	adds r4, r3, r6
	ldr r7, _080520D0 @ =gOamBuffer
	mov sb, r7
	movs r6, #8
	ldr r0, _080520D4 @ =0xFFFFFE00
	mov sl, r0
_0805208A:
	ldr r0, [r4]
	adds r7, r0, r6
	ldrh r2, [r7]
	lsls r2, r2, #3
	add r2, sb
	movs r3, #2
	ldrsh r1, [r7, r3]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r3, _080520D8 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r7]
	lsls r1, r1, #3
	add r1, sb
	ldr r0, [r4]
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r6, #8
	adds r5, #1
	ldr r7, [sp, #0x68]
	movs r1, #6
	ldrsh r0, [r7, r1]
	adds r0, #1
	cmp r5, r0
	blt _0805208A
	b _080522E2
	.align 2, 0
_080520D0: .4byte gOamBuffer
_080520D4: .4byte 0xFFFFFE00
_080520D8: .4byte 0x000001FF
_080520DC: .4byte gUnknown_0200B978
_080520E0: .4byte gOptionsData
_080520E4: .4byte gUnknown_086BB9A8
_080520E8:
	mov r2, r8
	ldr r1, [r2]
	movs r0, #0x9c
	strh r0, [r1, #2]
	ldr r0, [r2]
	add r3, sp, #0x80
	ldrh r3, [r3]
	strh r3, [r0, #4]
	ldr r4, [r2]
	adds r7, r4, #0
	adds r7, #8
	ldr r6, [sp, #0x68]
	movs r0, #0xc
	ldrsh r1, [r6, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [sp, #0x88]
	adds r0, r1, r0
	ldr r2, _08052490 @ =gUnknown_02031AF0
	adds r0, r0, r2
	ldrb r0, [r0]
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r2, r2, r3
	lsls r0, r0, #3
	ldr r1, _08052498 @ =gUnknown_086BB910
	adds r6, r0, r1
	ldrh r0, [r6, #2]
	ldr r1, _0805249C @ =0x000003FF
	ands r1, r0
	ldrh r3, [r2, #4]
	ldr r0, _080524A0 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	ldrb r2, [r6, #4]
	lsls r2, r2, #6
	ldrb r3, [r1, #1]
	movs r0, #0x3f
	mov sl, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #1]
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	ldr r1, _08052494 @ =gOamBuffer
	adds r2, r2, r1
	ldrb r1, [r6, #5]
	lsls r1, r1, #6
	ldrb r3, [r2, #3]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #3]
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r2, r2, r3
	movs r0, #2
	ldrsh r1, [r7, r0]
	mov r3, r8
	ldr r0, [r3]
	movs r3, #2
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	ldr r0, _080524A4 @ =0x000001FF
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r0, _080524A8 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	mov r3, r8
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	ldr r4, [sp, #0x68]
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #1
	ldr r1, [sp, #0x88]
	adds r0, r1, r0
	ldr r2, _08052490 @ =gUnknown_02031AF0
	adds r0, r0, r2
	ldrb r0, [r0]
	mov sb, r0
	cmp r0, #0xa
	bne _080521B8
	b _080522E2
_080521B8:
	ldr r3, [sp, #0x74]
	ldr r4, [sp, #0x84]
	adds r5, r3, r4
	ldr r1, [r5]
	mov r7, r8
	ldr r0, [r7]
	ldrh r0, [r0, #2]
	ldrb r6, [r6, #6]
	adds r0, r0, r6
	strh r0, [r1, #2]
	ldr r1, [r5]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	ldr r4, [r5]
	adds r7, r4, #0
	adds r7, #8
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r2, r2, r0
	ldrh r1, [r2, #4]
	ldr r0, _080524A0 @ =0xFFFFFC00
	ands r0, r1
	movs r1, #0x2a
	orrs r0, r1
	strh r0, [r2, #4]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	ldrb r2, [r1, #1]
	mov r0, sl
	ands r0, r2
	strb r0, [r1, #1]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r1, r1, r3
	ldrb r2, [r1, #3]
	mov r0, sl
	ands r0, r2
	strb r0, [r1, #3]
	ldrh r3, [r4, #8]
	lsls r3, r3, #3
	ldr r6, _08052494 @ =gOamBuffer
	adds r3, r3, r6
	movs r0, #2
	ldrsh r1, [r7, r0]
	ldr r0, [r5]
	movs r2, #2
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	ldr r6, _080524A4 @ =0x000001FF
	ands r1, r6
	ldrh r2, [r3, #2]
	ldr r0, _080524A8 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #8]
	lsls r1, r1, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r1, r1, r0
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	ldr r1, [sp, #0x7c]
	ldr r2, [sp, #0x84]
	adds r6, r1, r2
	ldr r1, [r6]
	ldr r0, [r5]
	ldrh r0, [r0, #2]
	adds r0, #8
	strh r0, [r1, #2]
	ldr r1, [r6]
	mov r3, r8
	ldr r0, [r3]
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	ldr r5, [r6]
	adds r7, r5, #0
	adds r7, #8
	ldrh r3, [r5, #8]
	lsls r3, r3, #3
	ldr r4, _08052494 @ =gOamBuffer
	adds r3, r3, r4
	mov r0, sb
	lsls r4, r0, #3
	ldr r1, _08052498 @ =gUnknown_086BB910
	adds r4, r4, r1
	ldrh r0, [r4, #2]
	ldr r1, _0805249C @ =0x000003FF
	ands r1, r0
	ldrh r2, [r3, #4]
	ldr r0, _080524A0 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	ldrh r2, [r5, #8]
	lsls r2, r2, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r2, r2, r3
	ldrb r1, [r4, #4]
	lsls r1, r1, #6
	ldrb r3, [r2, #1]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r2, [r5, #8]
	lsls r2, r2, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r2, r2, r0
	ldrb r1, [r4, #5]
	lsls r1, r1, #6
	ldrb r3, [r2, #3]
	mov r0, sl
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #3]
	ldrh r3, [r5, #8]
	lsls r3, r3, #3
	ldr r1, _08052494 @ =gOamBuffer
	adds r3, r3, r1
	movs r2, #2
	ldrsh r1, [r7, r2]
	ldr r0, [r6]
	movs r4, #2
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	ldr r0, _080524A4 @ =0x000001FF
	ands r1, r0
	ldrh r2, [r3, #2]
	ldr r0, _080524A8 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	ldr r0, [r6]
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
_080522E2:
	ldr r3, [sp, #0x80]
	adds r3, #0xc
	str r3, [sp, #0x80]
	ldr r4, [sp, #0x84]
	adds r4, #0xc
	str r4, [sp, #0x84]
	ldr r6, [sp, #0x88]
	adds r6, #2
	str r6, [sp, #0x88]
	movs r7, #0xc
	add r8, r7
	movs r0, #1
	add ip, r0
	mov r1, ip
	cmp r1, #4
	bgt _08052304
	b _0805204E
_08052304:
	movs r5, #8
	movs r0, #0xaa
	ldr r2, [sp, #0x64]
	strh r0, [r2, #2]
	ldr r0, _080524AC @ =gOptionsData
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0x2c
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r7, [sp, #0x78]
	ldrh r2, [r2, #8]
	lsls r2, r2, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r2, r2, r3
	movs r4, #2
	ldrsh r1, [r7, r4]
	adds r1, #0xaa
	ldr r6, _080524A4 @ =0x000001FF
	adds r0, r6, #0
	ands r1, r0
	ldrh r3, [r2, #2]
	ldr r4, _080524A8 @ =0xFFFFFE00
	adds r0, r4, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldr r0, [sp, #0x64]
	ldrh r1, [r0, #8]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	ldrb r0, [r0, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	movs r0, #0xc0
	ldr r3, _080524B0 @ =gUnknown_0200C948
	strh r0, [r3, #2]
	strh r5, [r3, #4]
	ldr r6, _080524AC @ =gOptionsData
	adds r6, #0x2d
	mov sl, r6
	adds r5, r3, #0
	adds r5, #8
	movs r6, #0x40
	mov sb, r4
	movs r7, #1
	mov ip, r7
_0805236C:
	ldrh r3, [r5]
	lsls r3, r3, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r3, r3, r0
	mov r2, sl
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r1, r1, #2
	adds r1, r6, r1
	ldr r7, _0805249C @ =0x000003FF
	adds r4, r7, #0
	ands r1, r4
	ldrh r2, [r3, #4]
	ldr r0, _080524A0 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	ldrh r3, [r5]
	lsls r3, r3, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r3, r3, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	ldr r7, _080524B0 @ =gUnknown_0200C948
	movs r2, #2
	ldrsh r0, [r7, r2]
	adds r1, r1, r0
	ldr r7, _080524A4 @ =0x000001FF
	mov r8, r7
	mov r0, r8
	ands r1, r0
	ldrh r2, [r3, #2]
	mov r0, sb
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r5]
	lsls r1, r1, #3
	ldr r2, _08052494 @ =gOamBuffer
	adds r1, r1, r2
	ldr r3, _080524B0 @ =gUnknown_0200C948
	ldrb r0, [r3, #4]
	ldrb r7, [r5, #4]
	adds r0, r0, r7
	strb r0, [r1]
	adds r5, #8
	adds r6, #0x80
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	mov r1, ip
	cmp r1, #0
	bge _0805236C
	ldr r2, _080524B4 @ =gUnknown_0200CA00
	ldrh r0, [r2]
	cmp r0, #1
	bne _08052454
	movs r0, #0xb0
	strh r0, [r2, #2]
	movs r0, #8
	strh r0, [r2, #4]
	adds r7, r2, #0
	adds r7, #8
	ldrh r2, [r2, #8]
	lsls r2, r2, #3
	ldr r3, _08052494 @ =gOamBuffer
	adds r2, r2, r3
	ldr r5, _080524AC @ =gOptionsData
	adds r5, #0x2f
	movs r1, #0
	ldrsb r1, [r5, r1]
	lsls r1, r1, #6
	adds r1, #0x54
	ands r1, r4
	ldrh r3, [r2, #4]
	ldr r0, _080524A0 @ =0xFFFFFC00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	ldr r4, _080524B4 @ =gUnknown_0200CA00
	ldrh r2, [r4, #8]
	lsls r2, r2, #3
	ldr r6, _08052494 @ =gOamBuffer
	adds r2, r2, r6
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r1, r1, r0
	mov r4, r8
	ands r1, r4
	ldrh r3, [r2, #2]
	ldr r0, _080524A8 @ =0xFFFFFE00
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #2]
	ldr r6, _080524B4 @ =gUnknown_0200CA00
	ldrh r1, [r6, #8]
	lsls r1, r1, #3
	ldr r0, _08052494 @ =gOamBuffer
	adds r1, r1, r0
	ldrb r0, [r6, #4]
	ldrb r7, [r7, #4]
	adds r0, r0, r7
	strb r0, [r1]
	ldr r0, _080524B8 @ =gMain
	ldr r0, [r0, #0x4c]
	movs r1, #0x12
	bl __umodsi3
	cmp r0, #0
	bne _08052454
	ldrb r1, [r5]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r5]
_08052454:
	movs r0, #0
	ldr r1, [sp, #0x60]
	strh r0, [r1]
	mov ip, r0
	ldr r4, [sp, #0x6c]
	movs r3, #0
_08052460:
	mov r2, ip
	adds r2, #1
	mov r6, ip
	lsls r0, r6, #1
	add r0, ip
	lsls r0, r0, #2
	adds r1, r0, r4
	movs r5, #2
_08052470:
	ldm r1!, {r0}
	strh r3, [r0]
	subs r5, #1
	cmp r5, #0
	bge _08052470
	mov ip, r2
	cmp r2, #5
	ble _08052460
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052490: .4byte gUnknown_02031AF0
_08052494: .4byte gOamBuffer
_08052498: .4byte gUnknown_086BB910
_0805249C: .4byte 0x000003FF
_080524A0: .4byte 0xFFFFFC00
_080524A4: .4byte 0x000001FF
_080524A8: .4byte 0xFFFFFE00
_080524AC: .4byte gOptionsData
_080524B0: .4byte gUnknown_0200C948
_080524B4: .4byte gUnknown_0200CA00
_080524B8: .4byte gMain

	thumb_func_start sub_524BC
sub_524BC: @ 0x080524BC
	push {r4, r5, lr}
	ldr r1, _0805251C @ =gOptionsData
	movs r2, #0x28
	ldrsh r0, [r1, r2]
	adds r2, r1, #0
	cmp r0, #1
	bgt _08052514
	ldr r0, _08052520 @ =gMain
	ldrh r0, [r0, #0x1c]
	ldr r4, _08052524 @ =0x000003F7
	ands r4, r0
	cmp r4, #0
	beq _08052514
	movs r3, #0
_080524D8:
	movs r1, #1
	lsls r1, r3
	ands r1, r4
	cmp r1, #0
	beq _0805250E
	movs r5, #0x22
	ldrsh r0, [r2, r5]
	ands r0, r1
	cmp r0, #0
	bne _0805250E
	ldrh r0, [r2, #0x22]
	orrs r1, r0
	strh r1, [r2, #0x22]
	movs r1, #0x28
	ldrsh r0, [r2, r1]
	lsls r0, r0, #1
	adds r1, r2, #0
	adds r1, #0x24
	adds r0, r0, r1
	strh r3, [r0]
	ldrh r0, [r2, #0x28]
	adds r0, #1
	strh r0, [r2, #0x28]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq _08052514
_0805250E:
	adds r3, #1
	cmp r3, #9
	ble _080524D8
_08052514:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805251C: .4byte gOptionsData
_08052520: .4byte gMain
_08052524: .4byte 0x000003F7

	thumb_func_start sub_52528
sub_52528: @ 0x08052528
	push {r4, r5, r6, r7, lr}
	movs r0, #0
	ldr r1, _0805255C @ =gUnknown_0200B204
	mov ip, r1
	ldr r6, _08052560 @ =gUnknown_02031B18
_08052532:
	movs r2, #0
	lsls r4, r0, #2
	lsls r3, r0, #1
	adds r5, r0, #1
_0805253A:
	lsls r0, r2, #1
	adds r0, r0, r4
	add r0, ip
	movs r7, #0
	ldrsh r1, [r0, r7]
	cmp r1, #0x10
	beq _0805259A
	cmp r1, #0x10
	bgt _0805256A
	cmp r1, #2
	beq _08052592
	cmp r1, #2
	bgt _08052564
	cmp r1, #1
	beq _0805258E
	b _080525B2
	.align 2, 0
_0805255C: .4byte gUnknown_0200B204
_08052560: .4byte gUnknown_02031B18
_08052564:
	cmp r1, #4
	beq _08052596
	b _080525B2
_0805256A:
	cmp r1, #0x80
	beq _080525A6
	cmp r1, #0x80
	bgt _0805257C
	cmp r1, #0x20
	beq _0805259E
	cmp r1, #0x40
	beq _080525A2
	b _080525B2
_0805257C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _080525AA
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	beq _080525AE
	b _080525B2
_0805258E:
	movs r1, #0
	b _080525B4
_08052592:
	movs r1, #1
	b _080525B4
_08052596:
	movs r1, #2
	b _080525B4
_0805259A:
	movs r1, #4
	b _080525B4
_0805259E:
	movs r1, #5
	b _080525B4
_080525A2:
	movs r1, #6
	b _080525B4
_080525A6:
	movs r1, #7
	b _080525B4
_080525AA:
	movs r1, #8
	b _080525B4
_080525AE:
	movs r1, #9
	b _080525B4
_080525B2:
	movs r1, #0xa
_080525B4:
	adds r0, r3, r2
	adds r0, r0, r6
	strb r1, [r0]
	adds r2, #1
	cmp r2, #1
	ble _0805253A
	adds r0, r5, #0
	cmp r0, #4
	ble _08052532
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_525CC
sub_525CC: @ 0x080525CC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	asrs r0, r0, #0x18
	cmp r0, #5
	bls _080525DE
	b _080528A2
_080525DE:
	lsls r0, r0, #2
	ldr r1, _080525E8 @ =_080525EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080525E8: .4byte _080525EC
_080525EC: @ jump table
	.4byte _08052604 @ case 0
	.4byte _080526CC @ case 1
	.4byte _08052720 @ case 2
	.4byte _08052770 @ case 3
	.4byte _080527C0 @ case 4
	.4byte _08052814 @ case 5
_08052604:
	ldr r0, _080526BC @ =gMain
	mov ip, r0
	ldr r6, _080526C0 @ =gUnknown_086BB910
	ldrh r5, [r6, #0x28]
	adds r0, #0x60
	strh r5, [r0]
	adds r0, r6, #0
	adds r0, #0x50
	ldrh r2, [r0]
	mov r0, ip
	adds r0, #0x62
	strh r2, [r0]
	ldrh r4, [r6]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r3, [r0]
	mov r0, ip
	adds r0, #0x68
	strh r3, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r6, #0
	adds r0, #0x40
	ldrh r1, [r0]
	mov r0, ip
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrh r1, [r6, #8]
	movs r0, #0xa2
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r0, #0xa3
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, ip
	strh r4, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r0, #0xa6
	lsls r0, r0, #1
	add r0, ip
	strh r5, [r0]
	movs r0, #0xa7
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	ldrh r1, [r6, #0x20]
	movs r0, #0xa8
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	ldrh r1, [r6, #0x30]
	movs r0, #0xaa
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r0, #0xab
	lsls r0, r0, #1
	add r0, ip
	strh r2, [r0]
	movs r2, #0
	ldr r4, _080526C4 @ =gUnknown_02031B18
	ldr r3, _080526C8 @ =gUnknown_08527EFE
_080526AA:
	adds r0, r2, r4
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble _080526AA
	b _080528A2
	.align 2, 0
_080526BC: .4byte gMain
_080526C0: .4byte gUnknown_086BB910
_080526C4: .4byte gUnknown_02031B18
_080526C8: .4byte gUnknown_08527EFE
_080526CC:
	ldr r4, _08052718 @ =gMain
	ldr r5, _0805271C @ =gUnknown_086BB910
	ldrh r1, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x62
	strh r2, [r0]
	ldrh r1, [r5]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r3, [r0]
	adds r0, r4, #0
	adds r0, #0x68
	strh r3, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	b _080528A0
	.align 2, 0
_08052718: .4byte gMain
_0805271C: .4byte gUnknown_086BB910
_08052720:
	ldr r3, _08052768 @ =gMain
	ldr r4, _0805276C @ =gUnknown_086BB910
	ldrh r1, [r4, #0x28]
	adds r0, r3, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r2, [r0]
	adds r0, r3, #0
	adds r0, #0x62
	strh r2, [r0]
	ldrh r1, [r4]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x68
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r4, #8]
	b _08052802
	.align 2, 0
_08052768: .4byte gMain
_0805276C: .4byte gUnknown_086BB910
_08052770:
	ldr r4, _080527B8 @ =gMain
	ldr r5, _080527BC @ =gUnknown_086BB910
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x62
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r3, [r5, #0x28]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r5]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	b _080528A0
	.align 2, 0
_080527B8: .4byte gMain
_080527BC: .4byte gUnknown_086BB910
_080527C0:
	ldr r3, _0805280C @ =gMain
	ldr r4, _08052810 @ =gUnknown_086BB910
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r2, [r0]
	adds r0, r3, #0
	adds r0, #0x62
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r4, #0x28]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r4, #0x20]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	ldrh r1, [r4, #0x30]
_08052802:
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	b _080528A2
	.align 2, 0
_0805280C: .4byte gMain
_08052810: .4byte gUnknown_086BB910
_08052814:
	ldr r2, _080528A8 @ =gMain
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x60
	strh r1, [r0]
	movs r1, #0xa3
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x62
	strh r0, [r1]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x64
	strh r1, [r0]
	movs r1, #0xa5
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x66
	strh r0, [r1]
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x68
	strh r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x6a
	strh r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x6c
	strh r1, [r0]
	movs r1, #0xa9
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x6e
	strh r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x70
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x72
_080528A0:
	strh r1, [r0]
_080528A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080528A8: .4byte gMain
