	.include "sound/MPlayDef.s"

	.equ	se_unk_fc_grp, gUnknown_08531D4C
	.equ	se_unk_fc_pri, 5
	.equ	se_unk_fc_rev, reverb_set+50
	.equ	se_unk_fc_mvl, 127
	.equ	se_unk_fc_key, 0
	.equ	se_unk_fc_tbs, 1
	.equ	se_unk_fc_exg, 0
	.equ	se_unk_fc_cmp, 1

	.section .rodata
	.global	se_unk_fc
	.align	2

@*********************** Track 01 ***********************@

se_unk_fc_0:  @ 0x086A1A68
	.byte	KEYSH , se_unk_fc_key+0
	.byte	TEMPO , 150*se_unk_fc_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 5*se_unk_fc_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N07   , Bn5 , v080
	.byte	W01
	.byte		VOL   , 55*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 67*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 90*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-14
	.byte	W02
	.byte		VOL   , 4*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v-22
	.byte		BEND  , c_v-23
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v+0
	.byte		N04   , Cn6 
	.byte	W01
	.byte		VOL   , 66*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		VOL   , 90*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 4*se_unk_fc_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		BEND  , c_v+5
	.byte	W14
	.byte		VOL   , 90*se_unk_fc_mvl/mxv
	.byte	FINE

@******************************************************@

	.align	2

se_unk_fc:  @ 0x086A1ABC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_fc_pri	@ Priority
	.byte	se_unk_fc_rev	@ Reverb

	.word	se_unk_fc_grp

	.word	se_unk_fc_0
@ 0x086A1AC8
