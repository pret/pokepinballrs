@ Leftover block at the end of the European ROM, followed by 0x800 zero bytes at 0x08FFF000.
@ Everything else up to 16 MiB is 0xFF padding (the US ROM is 8 MiB and has none of this).
@ The game never references it. It looks like a development tool linked to run at 0x09FE0000:
@ ARM branches at the start jump to a stub that calls Thumb code at 0x09FE2051, its literals
@ point into 0x09FE2xxx, IWRAM (0x03000800) and WAITCNT (0x04000204), and its Thumb functions
@ have agbcc-style prologues. Without symbols it is kept as bytes.
.section .rodata

gUnusedRomTailCode:: @ 0x08FE0000
	.incbin "data/eu/bin/rom_tail_08FE0000.bin"
	.fill 0x08FFF000 - 0x08FE4000, 1, 0xFF
gUnusedRomTailZeros:: @ 0x08FFF000
	.fill 0x800, 1, 0
