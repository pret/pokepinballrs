	.include "sound/MPlayDef.s"

	.equ	se_unk_12b_grp, gUnknown_08531D4C
	.equ	se_unk_12b_pri, 5
	.equ	se_unk_12b_rev, reverb_set+50
	.equ	se_unk_12b_mvl, 127
	.equ	se_unk_12b_key, 0
	.equ	se_unk_12b_tbs, 1
	.equ	se_unk_12b_exg, 0
	.equ	se_unk_12b_cmp, 1

	.section .rodata
	.global	se_unk_12b
	.align	2

@*********************** Track 01 ***********************@

se_unk_12b_0:  @ 0x086A29F4
	.byte	KEYSH , se_unk_12b_key+0
	.byte	TEMPO , 150*se_unk_12b_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		VOL   , 27*se_unk_12b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N96   , Cn3 , v112
	.byte	W04
	.byte		VOL   , 45*se_unk_12b_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-4
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		VOL   , 60*se_unk_12b_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-10
	.byte	W02
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		VOL   , 88*se_unk_12b_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte	W02
	.byte		BEND  , c_v+14
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 110*se_unk_12b_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+19
	.byte	W03
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		BEND  , c_v+24
	.byte	W04
	.byte		PAN   , c_v+11
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-4
	.byte	W02
	.byte		BEND  , c_v+19
	.byte	W04
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		VOL   , 98*se_unk_12b_mvl/mxv
	.byte	W05
	.byte		        81*se_unk_12b_mvl/mxv
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+12
	.byte	W06
	.byte		VOL   , 68*se_unk_12b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 50*se_unk_12b_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		VOL   , 31*se_unk_12b_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+22
	.byte	W02
	.byte		VOL   , 11*se_unk_12b_mvl/mxv
	.byte	W04
	.byte		        6*se_unk_12b_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+30
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_12b:  @ 0x086A2A68
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_12b_pri	@ Priority
	.byte	se_unk_12b_rev	@ Reverb

	.word	se_unk_12b_grp

	.word	se_unk_12b_0
@ 0x086A2A74
