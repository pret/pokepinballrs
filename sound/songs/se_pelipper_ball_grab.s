	.include "sound/MPlayDef.s"

	.equ	se_pelipper_ball_grab_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_pelipper_ball_grab_pri, 5
	.equ	se_pelipper_ball_grab_rev, reverb_set+50
	.equ	se_pelipper_ball_grab_mvl, 127
	.equ	se_pelipper_ball_grab_key, 0
	.equ	se_pelipper_ball_grab_tbs, 1
	.equ	se_pelipper_ball_grab_exg, 0
	.equ	se_pelipper_ball_grab_cmp, 1

	.section .rodata
	.global	se_pelipper_ball_grab
	.align	2

@*********************** Track 01 ***********************@

se_pelipper_ball_grab_0:  @ 0x086A10EC
	.byte	KEYSH , se_pelipper_ball_grab_key+0
	.byte	TEMPO , 150*se_pelipper_ball_grab_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 100*se_pelipper_ball_grab_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N02   , Dn3 , v127
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+6
	.byte		N02   , Dn3 , v084
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v+32
	.byte		N02   , Dn3 , v056
	.byte	W16
	.byte	FINE

@******************************************************@

	.align	2

se_pelipper_ball_grab:  @ 0x086A1118
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pelipper_ball_grab_pri	@ Priority
	.byte	se_pelipper_ball_grab_rev	@ Reverb

	.word	se_pelipper_ball_grab_grp

	.word	se_pelipper_ball_grab_0
@ 0x086A1124
