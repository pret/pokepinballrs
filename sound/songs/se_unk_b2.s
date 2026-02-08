	.include "sound/MPlayDef.s"

	.equ	se_unk_b2_grp, gUnknown_08532310
	.equ	se_unk_b2_pri, 5
	.equ	se_unk_b2_rev, reverb_set+50
	.equ	se_unk_b2_mvl, 127
	.equ	se_unk_b2_key, 0
	.equ	se_unk_b2_tbs, 1
	.equ	se_unk_b2_exg, 0
	.equ	se_unk_b2_cmp, 1

	.section .rodata
	.global	se_unk_b2
	.align	2

@*********************** Track 01 ***********************@

se_unk_b2_0:  @ 0x086A0334
	.byte	KEYSH , se_unk_b2_key+0
	.byte	TEMPO , 150*se_unk_b2_tbs/2
	.byte		VOL   , 127*se_unk_b2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 103
	.byte		TIE   , Cn3 , v127
	.byte	W96
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_b2:  @ 0x086A0348
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b2_pri	@ Priority
	.byte	se_unk_b2_rev	@ Reverb

	.word	se_unk_b2_grp

	.word	se_unk_b2_0
@ 0x086A0354
