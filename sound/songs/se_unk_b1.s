	.include "sound/MPlayDef.s"

	.equ	se_unk_b1_grp, gUnknown_08532310
	.equ	se_unk_b1_pri, 5
	.equ	se_unk_b1_rev, reverb_set+50
	.equ	se_unk_b1_mvl, 127
	.equ	se_unk_b1_key, 0
	.equ	se_unk_b1_tbs, 1
	.equ	se_unk_b1_exg, 0
	.equ	se_unk_b1_cmp, 1

	.section .rodata
	.global	se_unk_b1
	.align	2

@*********************** Track 01 ***********************@

se_unk_b1_0:  @ 0x086A0314
	.byte	KEYSH , se_unk_b1_key+0
	.byte	TEMPO , 150*se_unk_b1_tbs/2
	.byte		VOL   , 127*se_unk_b1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 101
	.byte		TIE   , Cn3 , v127
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_b1:  @ 0x086A0328
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b1_pri	@ Priority
	.byte	se_unk_b1_rev	@ Reverb

	.word	se_unk_b1_grp

	.word	se_unk_b1_0
@ 0x086A0334
