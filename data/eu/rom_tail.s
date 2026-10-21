@ Leftover block at the end of the European ROM (unreferenced ARM code), followed
@ by 0x800 zero bytes at 0x08FFF000. Everything else up to 16 MiB is 0xFF padding.
.section .rodata

gUnusedRomTailCode:: @ 0x08FE0000
	.incbin "data/eu/bin/rom_tail_08FE0000.bin"
	.fill 0x08FFF000 - 0x08FE4000, 1, 0xFF
gUnusedRomTailZeros:: @ 0x08FFF000
	.fill 0x800, 1, 0
