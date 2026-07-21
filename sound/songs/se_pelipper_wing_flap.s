	.include "sound/MPlayDef.s"

	.equ	se_pelipper_wing_flap_grp, gUnknown_08531D4C
	.equ	se_pelipper_wing_flap_pri, 5
	.equ	se_pelipper_wing_flap_rev, reverb_set+50
	.equ	se_pelipper_wing_flap_mvl, 127
	.equ	se_pelipper_wing_flap_key, 0
	.equ	se_pelipper_wing_flap_tbs, 1
	.equ	se_pelipper_wing_flap_exg, 0
	.equ	se_pelipper_wing_flap_cmp, 1

	.section .rodata
	.global	se_pelipper_wing_flap
	.align	2

@*********************** Track 01 ***********************@

se_pelipper_wing_flap_0:  @ 0x086A1124
	.byte	KEYSH , se_pelipper_wing_flap_key+0
	.byte	TEMPO , 220*se_pelipper_wing_flap_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*se_pelipper_wing_flap_mvl/mxv
	.byte		BEND  , c_v-32
	.byte		N07   , An1 , v127
	.byte	W01
	.byte		VOL   , 52*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		VOL   , 68*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 82*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 105*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+37
	.byte	W02
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v+63
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 40*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		BEND  , c_v+1
	.byte		N06
	.byte	W02
	.byte		VOL   , 52*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		VOL   , 79*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v+48
	.byte	W01
	.byte		VOL   , 105*se_pelipper_wing_flap_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+63
	.byte	W10
	.byte	W12
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_pelipper_wing_flap_1:  @ 0x086A117A
	.byte	KEYSH , se_pelipper_wing_flap_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*se_pelipper_wing_flap_mvl/mxv
	.byte		N07   , Gn2 , v040
	.byte	W01
	.byte		VOL   , 69*se_pelipper_wing_flap_mvl/mxv
	.byte	W01
	.byte		        83*se_pelipper_wing_flap_mvl/mxv
	.byte	W01
	.byte		        105*se_pelipper_wing_flap_mvl/mxv
	.byte	W01
	.byte		        67*se_pelipper_wing_flap_mvl/mxv
	.byte	W02
	.byte		        23*se_pelipper_wing_flap_mvl/mxv
	.byte	W04
	.byte		VOICE , 25
	.byte		VOL   , 52*se_pelipper_wing_flap_mvl/mxv
	.byte		N06   , Gs4 
	.byte	W02
	.byte		VOL   , 81*se_pelipper_wing_flap_mvl/mxv
	.byte	W01
	.byte		        105*se_pelipper_wing_flap_mvl/mxv
	.byte	W02
	.byte		        52*se_pelipper_wing_flap_mvl/mxv
	.byte	W09
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_pelipper_wing_flap:  @ 0x086A11A4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pelipper_wing_flap_pri	@ Priority
	.byte	se_pelipper_wing_flap_rev	@ Reverb

	.word	se_pelipper_wing_flap_grp

	.word	se_pelipper_wing_flap_0
	.word	se_pelipper_wing_flap_1
@ 0x086A11B4
