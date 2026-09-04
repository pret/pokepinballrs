	.include "sound/MPlayDef.s"

	.equ	se_mon_catch_ball_hit_ground_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_mon_catch_ball_hit_ground_pri, 5
	.equ	se_mon_catch_ball_hit_ground_rev, reverb_set+50
	.equ	se_mon_catch_ball_hit_ground_mvl, 127
	.equ	se_mon_catch_ball_hit_ground_key, 0
	.equ	se_mon_catch_ball_hit_ground_tbs, 1
	.equ	se_mon_catch_ball_hit_ground_exg, 0
	.equ	se_mon_catch_ball_hit_ground_cmp, 1

	.section .rodata
	.global	se_mon_catch_ball_hit_ground
	.align	2

@*********************** Track 01 ***********************@

se_mon_catch_ball_hit_ground_0:  @ 0x0869FDD0
	.byte	KEYSH , se_mon_catch_ball_hit_ground_key+0
	.byte	TEMPO , 150*se_mon_catch_ball_hit_ground_tbs/2
	.byte		VOICE , 16
	.byte		VOL   , 100*se_mon_catch_ball_hit_ground_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Fn4 , v088
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_mon_catch_ball_hit_ground_1:  @ 0x0869FDDF
	.byte	KEYSH , se_mon_catch_ball_hit_ground_key+0
	.byte		VOICE , 17
	.byte		VOL   , 100*se_mon_catch_ball_hit_ground_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Fn4 , v072
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_mon_catch_ball_hit_ground:  @ 0x0869FDEC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mon_catch_ball_hit_ground_pri	@ Priority
	.byte	se_mon_catch_ball_hit_ground_rev	@ Reverb

	.word	se_mon_catch_ball_hit_ground_grp

	.word	se_mon_catch_ball_hit_ground_0
	.word	se_mon_catch_ball_hit_ground_1
@ 0x0869FDFC
