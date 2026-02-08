	.include "sound/MPlayDef.s"

	.equ	se_unk_13b_grp, gUnknown_08532808
	.equ	se_unk_13b_pri, 5
	.equ	se_unk_13b_rev, reverb_set+50
	.equ	se_unk_13b_mvl, 127
	.equ	se_unk_13b_key, 0
	.equ	se_unk_13b_tbs, 1
	.equ	se_unk_13b_exg, 0
	.equ	se_unk_13b_cmp, 1

	.section .rodata
	.global	se_unk_13b
	.align	2

@*********************** Track 01 ***********************@

se_unk_13b_0:  @ 0x086A2E7C
	.byte	KEYSH , se_unk_13b_key+0
	.byte	TEMPO , 150*se_unk_13b_tbs/2
	.byte		VOL   , 110*se_unk_13b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 78
	.byte		N04   , Cn4 , v127
	.byte	W12
	.byte		TIE   , Cn4 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_13b:  @ 0x086A2E90
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_13b_pri	@ Priority
	.byte	se_unk_13b_rev	@ Reverb

	.word	se_unk_13b_grp

	.word	se_unk_13b_0
@ 0x086A2E9C
