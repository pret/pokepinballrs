	.include "sound/MPlayDef.s"

	.equ	se_unk_c2_grp, gUnknown_08532310
	.equ	se_unk_c2_pri, 5
	.equ	se_unk_c2_rev, reverb_set+50
	.equ	se_unk_c2_mvl, 127
	.equ	se_unk_c2_key, 0
	.equ	se_unk_c2_tbs, 1
	.equ	se_unk_c2_exg, 0
	.equ	se_unk_c2_cmp, 1

	.section .rodata
	.global	se_unk_c2
	.align	2

@*********************** Track 01 ***********************@

se_unk_c2_0:  @ 0x086A070C
	.byte	KEYSH , se_unk_c2_key+0
	.byte	TEMPO , 150*se_unk_c2_tbs/2
	.byte		VOL   , 110*se_unk_c2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 30
	.byte		N02   , Gn0 , v127
	.byte	W02
	.byte		N04   , Cn1 , v127
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c2:  @ 0x086A0720
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c2_pri	@ Priority
	.byte	se_unk_c2_rev	@ Reverb

	.word	se_unk_c2_grp

	.word	se_unk_c2_0
@ 0x086A072C
