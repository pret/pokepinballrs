	.include "sound/MPlayDef.s"

	.equ	se_unk_c3_grp, gUnknown_08531D4C
	.equ	se_unk_c3_pri, 5
	.equ	se_unk_c3_rev, reverb_set+50
	.equ	se_unk_c3_mvl, 127
	.equ	se_unk_c3_key, 0
	.equ	se_unk_c3_tbs, 1
	.equ	se_unk_c3_exg, 0
	.equ	se_unk_c3_cmp, 1

	.section .rodata
	.global	se_unk_c3
	.align	2

@*********************** Track 01 ***********************@

se_unk_c3_0:  @ 0x086A072C
	.byte	KEYSH , se_unk_c3_key+0
	.byte	TEMPO , 150*se_unk_c3_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_c3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c3:  @ 0x086A0744
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c3_pri	@ Priority
	.byte	se_unk_c3_rev	@ Reverb

	.word	se_unk_c3_grp

	.word	se_unk_c3_0
@ 0x086A0750
