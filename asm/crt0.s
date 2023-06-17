	.include "constants/gba_constants.inc"

	.syntax unified
	.arm

Start: @ 8000000
	b Init

.incbin "baserom.gba", 0x4, 0xBC

	.arm
	.align 2
Init: @ 80000C0
	mov r0, #0x12
	msr cpsr_cf, r0
	ldr sp, sp_irq
	mov r0, #0x1F
	msr cpsr_cf, r0
	ldr sp, sp_sys
	ldr r1, =INTR_VECTOR
	adr r0, IntrMain
	str r0, [r1]
	ldr r1, =0x800095C + 1
	mov lr, pc
	bx r1
	b Init
sp_sys: .4byte IWRAM_END - 0x100
sp_irq: .4byte IWRAM_END - 0x60
	.pool

	.global IntrMain
IntrMain: @ 8000104
	mov r3, REG_BASE
	add r3, r3, OFFSET_REG_IE
	ldr r2, [r3]
	ldrh r1, [r3, OFFSET_REG_IME - OFFSET_REG_IE]
	mrs r0, spsr
	stmdb sp!, {r0-r3,lr}
	mov r0, 1
	strh r0, [r3, OFFSET_REG_IME - OFFSET_REG_IE]
	and r1, r2, r2, lsr 16
	mov r12, 0
	ands r0, r1, INTR_FLAG_SERIAL
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_TIMER3
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_VBLANK
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_HBLANK
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_VCOUNT
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_TIMER0
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_TIMER1
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_TIMER2
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_DMA0
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_DMA1
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_DMA2
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_DMA3
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_KEYPAD
	bne IntrMain_FoundIntr
	add r12, r12, 4
	ands r0, r1, INTR_FLAG_GAMEPAK
	strbne  r0, [r3, OFFSET_REG_SOUNDCNT_X - OFFSET_REG_IE]
	bne . @ spin
IntrMain_FoundIntr: @ 80001D4
	strh r0, [r3, OFFSET_REG_IF - OFFSET_REG_IE]
	mov r1, INTR_FLAG_GAMEPAK | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_SYS_MODE
	msr cpsr_cf, r3
	ldr r1, =gIntrTable
	add r1, r1, r12
	ldr r0, [r1]
	stmdb sp!, {lr}
	adr lr, IntrMain_RetAddr
	bx r0
IntrMain_RetAddr: @ 8000210
	ldmfd sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK
	orr r3, r3, PSR_I_BIT | PSR_IRQ_MODE
	msr cpsr_cf, r3
	ldmfd sp!, {r0-r3,lr}
	strh r2, [r3]
	strh r1, [r3, OFFSET_REG_IME - OFFSET_REG_IE]
	msr spsr_cf, r0
	bx lr
	.pool
