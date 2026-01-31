	.include "sound/MPlayDef.s"

	.equ	se_unk_c9_grp, gUnknown_08531D4C
	.equ	se_unk_c9_pri, 5
	.equ	se_unk_c9_rev, reverb_set+50
	.equ	se_unk_c9_mvl, 127
	.equ	se_unk_c9_key, 0
	.equ	se_unk_c9_tbs, 1
	.equ	se_unk_c9_exg, 0
	.equ	se_unk_c9_cmp, 1

	.section .rodata
	.global	se_unk_c9
	.align	2

@*********************** Track 01 ***********************@

se_unk_c9_0:  @ 0x086A08CC
	.byte	KEYSH , se_unk_c9_key+0
	.byte	TEMPO , 220*se_unk_c9_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_unk_c9_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , Cn3 , v127
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+48
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte		N03   , En3 
	.byte	W15
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c9:  @ 0x086A08F4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c9_pri	@ Priority
	.byte	se_unk_c9_rev	@ Reverb

	.word	se_unk_c9_grp

	.word	se_unk_c9_0
@ 0x086A0900
