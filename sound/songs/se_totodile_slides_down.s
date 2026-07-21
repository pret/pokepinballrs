	.include "sound/MPlayDef.s"

	.equ	se_totodile_slides_down_grp, gUnknown_08531D4C
	.equ	se_totodile_slides_down_pri, 5
	.equ	se_totodile_slides_down_rev, reverb_set+50
	.equ	se_totodile_slides_down_mvl, 127
	.equ	se_totodile_slides_down_key, 0
	.equ	se_totodile_slides_down_tbs, 1
	.equ	se_totodile_slides_down_exg, 0
	.equ	se_totodile_slides_down_cmp, 1

	.section .rodata
	.global	se_totodile_slides_down
	.align	2

@*********************** Track 01 ***********************@

se_totodile_slides_down_0:  @ 0x086A31CC
	.byte	KEYSH , se_totodile_slides_down_key+0
	.byte	TEMPO , 150*se_totodile_slides_down_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		VOL   , 120*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v+12
	.byte		N06   , An2 , v127
	.byte	W03
	.byte		VOL   , 78*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W03
	.byte		VOL   , 120*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v+36
	.byte		N18   , Cn3 
	.byte	W02
	.byte		BEND  , c_v+35
	.byte	W03
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+26
	.byte	W03
	.byte		VOL   , 102*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W02
	.byte		VOL   , 68*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		VOL   , 34*se_totodile_slides_down_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_totodile_slides_down:  @ 0x086A3200
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_totodile_slides_down_pri	@ Priority
	.byte	se_totodile_slides_down_rev	@ Reverb

	.word	se_totodile_slides_down_grp

	.word	se_totodile_slides_down_0
@ 0x086A320C
