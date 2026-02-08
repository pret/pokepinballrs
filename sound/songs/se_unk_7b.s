	.include "sound/MPlayDef.s"

	.equ	se_unk_7b_grp, gUnknown_08531D4C
	.equ	se_unk_7b_pri, 5
	.equ	se_unk_7b_rev, reverb_set+50
	.equ	se_unk_7b_mvl, 127
	.equ	se_unk_7b_key, 0
	.equ	se_unk_7b_tbs, 1
	.equ	se_unk_7b_exg, 0
	.equ	se_unk_7b_cmp, 1

	.section .rodata
	.global	se_unk_7b
	.align	2

@*********************** Track 01 ***********************@

se_unk_7b_0:  @ 0x0869F2AC
	.byte	KEYSH , se_unk_7b_key+0
se_unk_7b_0_B1:
	.byte	TEMPO , 150*se_unk_7b_tbs/2
	.byte		VOICE , 15
	.byte		VOL   , 90*se_unk_7b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn2 , v100
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		EOT
	.byte	GOTO
	 .word	se_unk_7b_0_B1
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_unk_7b:  @ 0x0869F2C8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_7b_pri	@ Priority
	.byte	se_unk_7b_rev	@ Reverb

	.word	se_unk_7b_grp

	.word	se_unk_7b_0
@ 0x0869F2D4
