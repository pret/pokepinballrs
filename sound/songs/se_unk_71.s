	.include "sound/MPlayDef.s"

	.equ	se_unk_71_grp, gUnknown_08531D4C
	.equ	se_unk_71_pri, 5
	.equ	se_unk_71_rev, reverb_set+50
	.equ	se_unk_71_mvl, 127
	.equ	se_unk_71_key, 0
	.equ	se_unk_71_tbs, 1
	.equ	se_unk_71_exg, 0
	.equ	se_unk_71_cmp, 1

	.section .rodata
	.global	se_unk_71
	.align	2

@*********************** Track 01 ***********************@

se_unk_71_0:  @ 0x0869F0E4
	.byte	KEYSH , se_unk_71_key+0
	.byte	TEMPO , 150*se_unk_71_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_71_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_71:  @ 0x0869F0FC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_71_pri	@ Priority
	.byte	se_unk_71_rev	@ Reverb

	.word	se_unk_71_grp

	.word	se_unk_71_0
@ 0x0869F108
