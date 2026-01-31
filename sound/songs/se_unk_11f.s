	.include "sound/MPlayDef.s"

	.equ	se_unk_11f_grp, gUnknown_08531D4C
	.equ	se_unk_11f_pri, 5
	.equ	se_unk_11f_rev, reverb_set+50
	.equ	se_unk_11f_mvl, 127
	.equ	se_unk_11f_key, 0
	.equ	se_unk_11f_tbs, 1
	.equ	se_unk_11f_exg, 0
	.equ	se_unk_11f_cmp, 1

	.section .rodata
	.global	se_unk_11f
	.align	2

@*********************** Track 01 ***********************@

se_unk_11f_0:  @ 0x086A25AC
	.byte	KEYSH , se_unk_11f_key+0
	.byte	TEMPO , 150*se_unk_11f_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 23*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fn4 , v127
	.byte	W01
	.byte		VOL   , 51*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        75*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        99*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 115*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOL   , 99*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		        92*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W01
	.byte		VOL   , 97*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		        105*se_unk_11f_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 110*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		VOL   , 115*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-41
	.byte	W04
	.byte		        c_v-45
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		BEND  , c_v-39
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-35
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		BEND  , c_v-30
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-26
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W05
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-18
	.byte	W04
	.byte		        c_v-13
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+6
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		VOL   , 113*se_unk_11f_mvl/mxv
	.byte	W04
	.byte		        110*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		VOL   , 105*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		VOL   , 98*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 91*se_unk_11f_mvl/mxv
	.byte	W03
	.byte		        81*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		VOL   , 74*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-30
	.byte	W01
	.byte		VOL   , 50*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		        40*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 28*se_unk_11f_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W02
	.byte		VOL   , 17*se_unk_11f_mvl/mxv
	.byte	W03
	.byte		EOT
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_11f_1:  @ 0x086A2671
	.byte	KEYSH , se_unk_11f_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 23*se_unk_11f_mvl/mxv
	.byte		N30   , Gn2 , v032
	.byte	W01
	.byte		VOL   , 51*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        75*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        99*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        115*se_unk_11f_mvl/mxv
	.byte	W03
	.byte		        99*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		        92*se_unk_11f_mvl/mxv
	.byte	W01
	.byte		        97*se_unk_11f_mvl/mxv
	.byte	W02
	.byte		        115*se_unk_11f_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_11f:  @ 0x086A26A0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_11f_pri	@ Priority
	.byte	se_unk_11f_rev	@ Reverb

	.word	se_unk_11f_grp

	.word	se_unk_11f_0
	.word	se_unk_11f_1
@ 0x086A26B0
