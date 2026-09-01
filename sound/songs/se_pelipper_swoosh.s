	.include "sound/MPlayDef.s"

	.equ	se_pelipper_swoosh_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_pelipper_swoosh_pri, 5
	.equ	se_pelipper_swoosh_rev, reverb_set+50
	.equ	se_pelipper_swoosh_mvl, 127
	.equ	se_pelipper_swoosh_key, 0
	.equ	se_pelipper_swoosh_tbs, 1
	.equ	se_pelipper_swoosh_exg, 0
	.equ	se_pelipper_swoosh_cmp, 1

	.section .rodata
	.global	se_pelipper_swoosh
	.align	2

@*********************** Track 01 ***********************@

se_pelipper_swoosh_0:  @ 0x086A11B4
	.byte	KEYSH , se_pelipper_swoosh_key+0
	.byte	TEMPO , 150*se_pelipper_swoosh_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		VOL   , 120*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v+12
	.byte		N06   , An2 , v127
	.byte	W03
	.byte		VOL   , 78*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W03
	.byte		VOL   , 120*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v+36
	.byte		N18   , Cn3 
	.byte	W02
	.byte		BEND  , c_v+35
	.byte	W03
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+26
	.byte	W03
	.byte		VOL   , 102*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W02
	.byte		VOL   , 68*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		VOL   , 34*se_pelipper_swoosh_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_pelipper_swoosh:  @ 0x086A11E8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pelipper_swoosh_pri	@ Priority
	.byte	se_pelipper_swoosh_rev	@ Reverb

	.word	se_pelipper_swoosh_grp

	.word	se_pelipper_swoosh_0
@ 0x086A11F4
