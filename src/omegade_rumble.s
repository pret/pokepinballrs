	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start InitCartridgeRumble
InitCartridgeRumble:
	push {r0, r1}
	ldr r0, =gGameBoyPlayerEnabled
	ldrb r0, [r0]
	cmp r0, #1
	beq .Linit_done
	ldr r0, =0x080000C8
	movs r1, #1
	strb r1, [r0]
	ldr r0, =0x080000C6
	movs r1, #8
	strb r1, [r0]
.Linit_done:
	pop {r0, r1}
	bx lr
	.pool
	thumb_func_end InitCartridgeRumble

	thumb_func_start EmitOmegaDEPulse
EmitOmegaDEPulse:
	push {r1-r5}
	ldr r1, =0xD200
	ldr r2, =0x1500
	ldr r3, =0x09FE0000
	strh r1, [r3]
	ldr r3, =0x08000000
	strh r2, [r3]
	ldr r3, =0x08020000
	strh r1, [r3]
	ldr r3, =0x08040000
	strh r2, [r3]
	ldr r3, =0x09E20000
	movs r1, #0xF1
	strh r1, [r3]
	ldr r3, =0x09FC0000
	strh r2, [r3]
    ldr r4, =0x08001000
	movs r5, #2
	strb r5, [r4]
	nop
	nop
	nop
	nop
	movs r5, #0
	strb r5, [r4]
	pop {r1-r5}
	bx lr
	.pool
	thumb_func_end EmitOmegaDEPulse
