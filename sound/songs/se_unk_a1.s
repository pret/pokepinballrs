	.include "sound/MPlayDef.s"

	.equ	se_unk_a1_grp, gUnknown_08532310
	.equ	se_unk_a1_pri, 5
	.equ	se_unk_a1_rev, reverb_set+50
	.equ	se_unk_a1_mvl, 127
	.equ	se_unk_a1_key, 0
	.equ	se_unk_a1_tbs, 1
	.equ	se_unk_a1_exg, 0
	.equ	se_unk_a1_cmp, 1

	.section .rodata
	.global	se_unk_a1
	.align	2

@*********************** Track 01 ***********************@

se_unk_a1_0:  @ 0x0869FE98
	.byte	KEYSH , se_unk_a1_key+0
	.byte	TEMPO , 150*se_unk_a1_tbs/2
	.byte		VOL   , 100*se_unk_a1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_a1:  @ 0x0869FEA8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_a1_pri	@ Priority
	.byte	se_unk_a1_rev	@ Reverb

	.word	se_unk_a1_grp

	.word	se_unk_a1_0
@ 0x0869FEB4
