	.include "sound/MPlayDef.s"

	.equ	se_flipper_pressed_grp, gUnknown_08532310
	.equ	se_flipper_pressed_pri, 5
	.equ	se_flipper_pressed_rev, reverb_set+50
	.equ	se_flipper_pressed_mvl, 127
	.equ	se_flipper_pressed_key, 0
	.equ	se_flipper_pressed_tbs, 1
	.equ	se_flipper_pressed_exg, 0
	.equ	se_flipper_pressed_cmp, 1

	.section .rodata
	.global	se_flipper_pressed
	.align	2

@*********************** Track 01 ***********************@

se_flipper_pressed_0:  @ 0x0869F108
	.byte	KEYSH , se_flipper_pressed_key+0
	.byte	TEMPO , 150*se_flipper_pressed_tbs/2
	.byte		VOL   , 80*se_flipper_pressed_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , En2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_flipper_pressed:  @ 0x0869F118
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_flipper_pressed_pri	@ Priority
	.byte	se_flipper_pressed_rev	@ Reverb

	.word	se_flipper_pressed_grp

	.word	se_flipper_pressed_0
@ 0x0869F124
