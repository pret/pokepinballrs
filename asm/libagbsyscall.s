	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ArcTan2
ArcTan2:
	swi 0xA
	bx lr
	thumb_func_end ArcTan2

	thumb_func_start CpuSet
CpuSet:
	swi 0xB
	bx lr
	thumb_func_end CpuSet

	thumb_func_start LZ77UnCompWram
LZ77UnCompWram:
	swi 0x11
	bx lr
	thumb_func_end LZ77UnCompWram

	thumb_func_start RegisterRamReset
RegisterRamReset:
	swi 0x1
	bx lr
	thumb_func_end RegisterRamReset

	thumb_func_start Sqrt
Sqrt:
	swi 0x8
	bx lr
	thumb_func_end Sqrt

	thumb_func_start VBlankIntrWait
VBlankIntrWait:
	movs r2, 0
	swi 0x5
	bx lr
	thumb_func_end VBlankIntrWait

	.align 2, 0 @ Don't pad with nop.
