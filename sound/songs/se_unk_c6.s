	.include "sound/MPlayDef.s"

	.equ	se_unk_c6_grp, gUnknown_08532310
	.equ	se_unk_c6_pri, 5
	.equ	se_unk_c6_rev, reverb_set+50
	.equ	se_unk_c6_mvl, 127
	.equ	se_unk_c6_key, 0
	.equ	se_unk_c6_tbs, 1
	.equ	se_unk_c6_exg, 0
	.equ	se_unk_c6_cmp, 1

	.section .rodata
	.global	se_unk_c6
	.align	2

@*********************** Track 01 ***********************@

se_unk_c6_0:  @ 0x086A0830
	.byte	KEYSH , se_unk_c6_key+0
	.byte	TEMPO , 150*se_unk_c6_tbs/2
	.byte		VOL   , 110*se_unk_c6_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 33
	.byte		N06   , Cn4 , v127
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c6:  @ 0x086A0840
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c6_pri	@ Priority
	.byte	se_unk_c6_rev	@ Reverb

	.word	se_unk_c6_grp

	.word	se_unk_c6_0
@ 0x086A084C
