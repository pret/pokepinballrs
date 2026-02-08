	.include "sound/MPlayDef.s"

	.equ	se_unk_eb_grp, gUnknown_08531D4C
	.equ	se_unk_eb_pri, 5
	.equ	se_unk_eb_rev, reverb_set+50
	.equ	se_unk_eb_mvl, 127
	.equ	se_unk_eb_key, 0
	.equ	se_unk_eb_tbs, 1
	.equ	se_unk_eb_exg, 0
	.equ	se_unk_eb_cmp, 1

	.section .rodata
	.global	se_unk_eb
	.align	2

@*********************** Track 01 ***********************@

se_unk_eb_0:  @ 0x086A13C4
	.byte	KEYSH , se_unk_eb_key+0
	.byte	TEMPO , 150*se_unk_eb_tbs/2
	.byte		VOICE , 65
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_eb_mvl/mxv
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

se_unk_eb_1:  @ 0x086A1405
	.byte	KEYSH , se_unk_eb_key+0
	.byte		VOICE , 57
	.byte		VOL   , 110*se_unk_eb_mvl/mxv
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

se_unk_eb:  @ 0x086A1418
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_eb_pri	@ Priority
	.byte	se_unk_eb_rev	@ Reverb

	.word	se_unk_eb_grp

	.word	se_unk_eb_0
	.word	se_unk_eb_1
@ 0x086A1428
