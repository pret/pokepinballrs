	.include "sound/MPlayDef.s"

	.equ	se_seedot_leaves_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_seedot_leaves_pri, 5
	.equ	se_seedot_leaves_rev, reverb_set+50
	.equ	se_seedot_leaves_mvl, 127
	.equ	se_seedot_leaves_key, 0
	.equ	se_seedot_leaves_tbs, 1
	.equ	se_seedot_leaves_exg, 0
	.equ	se_seedot_leaves_cmp, 1

	.section .rodata
	.global	se_seedot_leaves
	.align	2

@*********************** Track 01 ***********************@

se_seedot_leaves_0:  @ 0x086A13C4
	.byte	KEYSH , se_seedot_leaves_key+0
	.byte	TEMPO , 150*se_seedot_leaves_tbs/2
	.byte		VOICE , 65
	.byte		BENDR , 12
	.byte		VOL   , 110*se_seedot_leaves_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v112
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-17
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-36
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Gn4 
	.byte	W02
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+15
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+28
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Gn4 , v064
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+15
	.byte	W02
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+28
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_seedot_leaves_1:  @ 0x086A1405
	.byte	KEYSH , se_seedot_leaves_key+0
	.byte		VOICE , 57
	.byte		VOL   , 110*se_seedot_leaves_mvl/mxv
	.byte		N03   , En3 , v052
	.byte	W03
	.byte	W01
	.byte		N03
	.byte	W02
	.byte	W03
	.byte		        En3 , v032
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_seedot_leaves:  @ 0x086A1418
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_seedot_leaves_pri	@ Priority
	.byte	se_seedot_leaves_rev	@ Reverb

	.word	se_seedot_leaves_grp

	.word	se_seedot_leaves_0
	.word	se_seedot_leaves_1
@ 0x086A1428
