	.equ	mus_dummy_grp, 0
	.equ	mus_dummy_pri, 0
	.equ	mus_dummy_rev, 0

	.section .rodata
	.global	mus_dummy
	.align	2

@******************************************************@
	.align	2

mus_dummy:
	.byte	0	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_dummy_pri	@ Priority
	.byte	mus_dummy_rev	@ Reverb.
