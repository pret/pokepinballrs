	.include "sound/MPlayDef.s"

	.equ	se_unk_96_grp, gUnknown_08531D4C
	.equ	se_unk_96_pri, 5
	.equ	se_unk_96_rev, reverb_set+50
	.equ	se_unk_96_mvl, 127
	.equ	se_unk_96_key, 0
	.equ	se_unk_96_tbs, 1
	.equ	se_unk_96_exg, 0
	.equ	se_unk_96_cmp, 1

	.section .rodata
	.global	se_unk_96
	.align	2

@*********************** Track 01 ***********************@

se_unk_96_0:  @ 0x0869FB64
	.byte	KEYSH , se_unk_96_key+0
	.byte	TEMPO , 150*se_unk_96_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_96_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_96:  @ 0x0869FB7C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_96_pri	@ Priority
	.byte	se_unk_96_rev	@ Reverb

	.word	se_unk_96_grp

	.word	se_unk_96_0
@ 0x0869FB88
