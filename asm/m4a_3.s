	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"
	.include "constants/m4a_constants.inc"

	.syntax unified

	@ extern
	.set gCgb3Vol, 0x0852DAFC

	.text

	thumb_func_start CgbSound
CgbSound: @ 8054920
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	ldr r0, =SOUND_INFO_PTR
	ldr r0, [r0]
	str r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08054944
	subs r0, 0x1
	ldr r1, [sp, 0x4]
	strb r0, [r1, 0xA]
	b _0805494A
	.pool
_08054944:
	movs r0, 0xE
	ldr r2, [sp, 0x4]
	strb r0, [r2, 0xA]
_0805494A:
	movs r6, 0x1
	ldr r0, [sp, 0x4]
	ldr r4, [r0, 0x1C]
_08054950:
	ldrb r1, [r4]
	movs r0, 0xC7
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	bne _08054966
	b _08054D50
_08054966:
	cmp r6, 0x2
	beq _08054988
	cmp r6, 0x2
	bgt _08054974
	cmp r6, 0x1
	beq _0805497A
	b _080549D0
_08054974:
	cmp r6, 0x3
	beq _080549B0
	b _080549D0
_0805497A:
	ldr r0, =REG_NR10
	str r0, [sp, 0x8]
	ldr r7, =REG_NR11
	ldr r2, =REG_NR12
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080549E0
	.pool
_08054988:
	ldr r0, =REG_NR10 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR21
	ldr r2, =REG_NR22
	b _080549D8
	.pool
_080549B0:
	ldr r0, =REG_NR30
	str r0, [sp, 0x8]
	ldr r7, =REG_NR31
	ldr r2, =REG_NR32
	str r2, [sp, 0xC]
	adds r0, 0x4
	str r0, [sp, 0x10]
	adds r2, 0x2
	b _080549E0
	.pool
_080549D0:
	ldr r0, =REG_NR30 + 1
	str r0, [sp, 0x8]
	ldr r7, =REG_NR41
	ldr r2, =REG_NR42
_080549D8:
	str r2, [sp, 0xC]
	adds r0, 0xB
	str r0, [sp, 0x10]
	adds r2, 0x4
_080549E0:
	str r2, [sp, 0x14]
	ldr r0, [sp, 0x4]
	ldrb r0, [r0, 0xA]
	str r0, [sp]
	ldr r2, [sp, 0xC]
	ldrb r0, [r2]
	mov r8, r0
	adds r2, r1, 0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08054AD6
	movs r3, 0x40
	adds r0, r3, 0
	ands r0, r2
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r6, 0x1
	mov r10, r0
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r5, 0
	bne _08054AFA
	movs r0, 0x3
	strb r0, [r4]
	strb r0, [r4, 0x1D]
	adds r0, r4, 0
	str r3, [sp, 0x18]
	bl CgbModVol
	ldr r3, [sp, 0x18]
	cmp r6, 0x2
	beq _08054A48
	cmp r6, 0x2
	bgt _08054A3C
	cmp r6, 0x1
	beq _08054A42
	b _08054A9C
	.pool
_08054A3C:
	cmp r6, 0x3
	beq _08054A54
	b _08054A9C
_08054A42:
	ldrb r0, [r4, 0x1F]
	ldr r2, [sp, 0x8]
	strb r0, [r2]
_08054A48:
	ldr r0, [r4, 0x24]
	lsls r0, 6
	ldrb r1, [r4, 0x1E]
	adds r0, r1, r0
	strb r0, [r7]
	b _08054AA8
_08054A54:
	ldr r1, [r4, 0x24]
	ldr r0, [r4, 0x28]
	cmp r1, r0
	beq _08054A7C
	ldr r2, [sp, 0x8]
	strb r3, [r2]
	ldr r1, =REG_WAVE_RAM
	ldr r2, [r4, 0x24]
	ldr r0, [r2]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x4]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0x8]
	str r0, [r1]
	adds r1, 0x4
	ldr r0, [r2, 0xC]
	str r0, [r1]
	str r2, [r4, 0x28]
_08054A7C:
	ldr r0, [sp, 0x8]
	strb r5, [r0]
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _08054A94
	movs r0, 0xC0
	b _08054AB6
	.pool
_08054A94:
	movs r1, 0x80
	negs r1, r1
	strb r1, [r4, 0x1A]
	b _08054AB8
_08054A9C:
	ldrb r0, [r4, 0x1E]
	strb r0, [r7]
	ldr r0, [r4, 0x24]
	lsls r0, 3
	ldr r2, [sp, 0x10]
	strb r0, [r2]
_08054AA8:
	ldrb r0, [r4, 0x4]
	adds r0, 0x8
	mov r8, r0
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _08054AB6
	movs r0, 0x40
_08054AB6:
	strb r0, [r4, 0x1A]
_08054AB8:
	ldrb r1, [r4, 0x4]
	movs r2, 0
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	adds r1, r6, 0x1
	mov r10, r1
	movs r1, 0x40
	adds r1, r4
	mov r9, r1
	cmp r0, 0
	bne _08054AD2
	b _08054C0E
_08054AD2:
	strb r2, [r4, 0x9]
	b _08054C3C
_08054AD6:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _08054B08
	ldrb r0, [r4, 0xD]
	subs r0, 0x1
	strb r0, [r4, 0xD]
	movs r2, 0xFF
	ands r0, r2
	lsls r0, 24
	adds r1, r6, 0x1
	mov r10, r1
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	ble _08054AFA
	b _08054C4E
_08054AFA:
	lsls r0, r6, 24
	lsrs r0, 24
	bl CgbOscOff
	movs r0, 0
	strb r0, [r4]
	b _08054D4C
_08054B08:
	movs r0, 0x40
	ands r0, r1
	adds r2, r6, 0x1
	mov r10, r2
	movs r2, 0x40
	adds r2, r4
	mov r9, r2
	cmp r0, 0
	beq _08054B48
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _08054B48
	movs r0, 0xFC
	ands r0, r1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x7]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _08054B7A
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _08054C3C
	ldrb r2, [r4, 0x7]
	mov r8, r2
	b _08054C3C
_08054B48:
	ldrb r0, [r4, 0xB]
	cmp r0, 0
	bne _08054C3C
	cmp r6, 0x3
	bne _08054B5A
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
_08054B5A:
	adds r0, r4, 0
	bl CgbModVol
	movs r0, 0x3
	ldrb r2, [r4]
	ands r0, r2
	cmp r0, 0
	bne _08054BAE
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	cmp r0, 0
	bgt _08054BAA
_08054B7A:
	ldrb r2, [r4, 0xC]
	ldrb r1, [r4, 0xA]
	adds r0, r2, 0
	muls r0, r1
	adds r0, 0xFF
	asrs r0, 8
	movs r1, 0
	strb r0, [r4, 0x9]
	lsls r0, 24
	cmp r0, 0
	beq _08054AFA
	movs r0, 0x4
	ldrb r2, [r4]
	orrs r0, r2
	strb r0, [r4]
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _08054C4E
	movs r2, 0x8
	mov r8, r2
	b _08054C4E
_08054BAA:
	ldrb r0, [r4, 0x7]
	b _08054C3A
_08054BAE:
	cmp r0, 0x1
	bne _08054BBA
_08054BB2:
	ldrb r0, [r4, 0x19]
	strb r0, [r4, 0x9]
	movs r0, 0x7
	b _08054C3A
_08054BBA:
	cmp r0, 0x2
	bne _08054BFE
	ldrb r0, [r4, 0x9]
	subs r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	lsls r0, 24
	ldrb r2, [r4, 0x19]
	lsls r1, r2, 24
	cmp r0, r1
	bgt _08054BFA
_08054BD2:
	ldrb r0, [r4, 0x6]
	cmp r0, 0
	bne _08054BE2
	movs r0, 0xFC
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	b _08054B7A
_08054BE2:
	ldrb r0, [r4]
	subs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	orrs r0, r2
	strb r0, [r4, 0x1D]
	cmp r6, 0x3
	beq _08054BB2
	movs r0, 0x8
	mov r8, r0
	b _08054BB2
_08054BFA:
	ldrb r0, [r4, 0x5]
	b _08054C3A
_08054BFE:
	ldrb r0, [r4, 0x9]
	adds r0, 0x1
	strb r0, [r4, 0x9]
	movs r1, 0xFF
	ands r0, r1
	ldrb r2, [r4, 0xA]
	cmp r0, r2
	bcc _08054C38
_08054C0E:
	ldrb r0, [r4]
	subs r0, 0x1
	movs r2, 0
	strb r0, [r4]
	ldrb r1, [r4, 0x5]
	strb r1, [r4, 0xB]
	movs r0, 0xFF
	ands r0, r1
	cmp r0, 0
	beq _08054BD2
	movs r0, 0x1
	ldrb r1, [r4, 0x1D]
	orrs r0, r1
	strb r0, [r4, 0x1D]
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	cmp r6, 0x3
	beq _08054C3C
	ldrb r2, [r4, 0x5]
	mov r8, r2
	b _08054C3C
_08054C38:
	ldrb r0, [r4, 0x4]
_08054C3A:
	strb r0, [r4, 0xB]
_08054C3C:
	ldrb r0, [r4, 0xB]
	subs r0, 0x1
	strb r0, [r4, 0xB]
	ldr r0, [sp]
	cmp r0, 0
	bne _08054C4E
	subs r0, 0x1
	str r0, [sp]
	b _08054B48
_08054C4E:
	movs r0, 0x2
	ldrb r1, [r4, 0x1D]
	ands r0, r1
	cmp r0, 0
	beq _08054CC6
	cmp r6, 0x3
	bgt _08054C8E
	movs r0, 0x8
	ldrb r2, [r4, 0x1]
	ands r0, r2
	cmp r0, 0
	beq _08054C8E
	ldr r0, =REG_SOUNDBIAS + 1
	ldrb r0, [r0]
	cmp r0, 0x3F
	bgt _08054C80
	ldr r0, [r4, 0x20]
	adds r0, 0x2
	ldr r1, =0x000007fc
	b _08054C8A
	.pool
_08054C80:
	cmp r0, 0x7F
	bgt _08054C8E
	ldr r0, [r4, 0x20]
	adds r0, 0x1
	ldr r1, =0x000007fe
_08054C8A:
	ands r0, r1
	str r0, [r4, 0x20]
_08054C8E:
	cmp r6, 0x4
	beq _08054CA0
	ldr r0, [r4, 0x20]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	b _08054CAE
	.pool
_08054CA0:
	ldr r2, [sp, 0x10]
	ldrb r0, [r2]
	movs r1, 0x8
	ands r1, r0
	ldr r0, [r4, 0x20]
	orrs r0, r1
	strb r0, [r2]
_08054CAE:
	movs r0, 0xC0
	ldrb r1, [r4, 0x1A]
	ands r0, r1
	adds r1, r4, 0
	adds r1, 0x21
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r4, 0x1A]
	movs r2, 0xFF
	ands r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_08054CC6:
	movs r0, 0x1
	ldrb r2, [r4, 0x1D]
	ands r0, r2
	cmp r0, 0
	beq _08054D4C
	ldr r1, =REG_NR51
	ldrb r0, [r1]
	ldrb r2, [r4, 0x1C]
	bics r0, r2
	ldrb r2, [r4, 0x1B]
	orrs r0, r2
	strb r0, [r1]
	cmp r6, 0x3
	bne _08054D18
	ldr r0, =gCgb3Vol
	ldrb r1, [r4, 0x9]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, [sp, 0xC]
	strb r0, [r2]
	movs r1, 0x80
	adds r0, r1, 0
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	cmp r0, 0
	beq _08054D4C
	ldr r0, [sp, 0x8]
	strb r1, [r0]
	ldrb r0, [r4, 0x1A]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	movs r0, 0x7F
	ldrb r2, [r4, 0x1A]
	ands r0, r2
	strb r0, [r4, 0x1A]
	b _08054D4C
	.pool
_08054D18:
	movs r0, 0xF
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldrb r2, [r4, 0x9]
	lsls r0, r2, 4
	add r0, r8
	ldr r1, [sp, 0xC]
	strb r0, [r1]
	movs r2, 0x80
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	cmp r6, 0x1
	bne _08054D4C
	ldr r0, [sp, 0x8]
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08054D4C
	ldrb r0, [r4, 0x1A]
	orrs r0, r2
	ldr r1, [sp, 0x14]
	strb r0, [r1]
_08054D4C:
	movs r0, 0
	strb r0, [r4, 0x1D]
_08054D50:
	mov r6, r10
	mov r4, r9
	cmp r6, 0x4
	bgt _08054D5A
	b _08054950
_08054D5A:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end CgbSound

	.align 2, 0 @ Don't pad with nop.
