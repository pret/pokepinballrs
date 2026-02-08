	.include "sound/MPlayDef.s"

	.equ	se_unk_d1_grp, gUnknown_08531D4C
	.equ	se_unk_d1_pri, 5
	.equ	se_unk_d1_rev, reverb_set+50
	.equ	se_unk_d1_mvl, 127
	.equ	se_unk_d1_key, 0
	.equ	se_unk_d1_tbs, 1
	.equ	se_unk_d1_exg, 0
	.equ	se_unk_d1_cmp, 1

	.section .rodata
	.global	se_unk_d1
	.align	2

@*********************** Track 01 ***********************@

se_unk_d1_0:  @ 0x086A0C0C
	.byte	KEYSH , se_unk_d1_key+0
	.byte	TEMPO , 150*se_unk_d1_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 100*se_unk_d1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W01
	.byte		N02   , Gn2 
	.byte	W02
	.byte		N04   , Cn3 
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unk_d1:  @ 0x086A0C24
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_d1_pri	@ Priority
	.byte	se_unk_d1_rev	@ Reverb

	.word	se_unk_d1_grp

	.word	se_unk_d1_0
@ 0x086A0C30
