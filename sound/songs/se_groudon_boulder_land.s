	.include "sound/MPlayDef.s"

	.equ	se_groudon_boulder_land_grp, gUnknown_08531D4C
	.equ	se_groudon_boulder_land_pri, 5
	.equ	se_groudon_boulder_land_rev, reverb_set+50
	.equ	se_groudon_boulder_land_mvl, 127
	.equ	se_groudon_boulder_land_key, 0
	.equ	se_groudon_boulder_land_tbs, 1
	.equ	se_groudon_boulder_land_exg, 0
	.equ	se_groudon_boulder_land_cmp, 1

	.section .rodata
	.global	se_groudon_boulder_land
	.align	2

@*********************** Track 01 ***********************@

se_groudon_boulder_land_0:  @ 0x086A2718
	.byte	KEYSH , se_groudon_boulder_land_key+0
	.byte	TEMPO , 150*se_groudon_boulder_land_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 115*se_groudon_boulder_land_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Gn3 , v127
	.byte	W01
	.byte		        Cn3 
	.byte	W01
	.byte		N24   , An3 
	.byte	W06
	.byte		PAN   , c_v+6
	.byte	W04
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 102*se_groudon_boulder_land_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		VOL   , 88*se_groudon_boulder_land_mvl/mxv
	.byte	W03
	.byte		        78*se_groudon_boulder_land_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 67*se_groudon_boulder_land_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		PAN   , c_v+7
	.byte		VOL   , 45*se_groudon_boulder_land_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 13*se_groudon_boulder_land_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-15
	.byte	W22
	.byte	FINE

@******************************************************@

	.align	2

se_groudon_boulder_land:  @ 0x086A2758
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_groudon_boulder_land_pri	@ Priority
	.byte	se_groudon_boulder_land_rev	@ Reverb

	.word	se_groudon_boulder_land_grp

	.word	se_groudon_boulder_land_0
@ 0x086A2764
