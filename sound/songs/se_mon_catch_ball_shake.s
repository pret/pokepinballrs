	.include "sound/MPlayDef.s"

	.equ	se_mon_catch_ball_shake_grp, gUnknown_0853174C
	.equ	se_mon_catch_ball_shake_pri, 5
	.equ	se_mon_catch_ball_shake_rev, reverb_set+50
	.equ	se_mon_catch_ball_shake_mvl, 127
	.equ	se_mon_catch_ball_shake_key, 0
	.equ	se_mon_catch_ball_shake_tbs, 1
	.equ	se_mon_catch_ball_shake_exg, 0
	.equ	se_mon_catch_ball_shake_cmp, 1

	.section .rodata
	.global	se_mon_catch_ball_shake
	.align	2

@*********************** Track 01 ***********************@

se_mon_catch_ball_shake_0:  @ 0x0869FDFC
	.byte	KEYSH , se_mon_catch_ball_shake_key+0
	.byte	TEMPO , 128*se_mon_catch_ball_shake_tbs/2
	.byte		VOICE , 7
	.byte		BENDR , 12
	.byte		VOL   , 70*se_mon_catch_ball_shake_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N04   , Fn2 , v127
	.byte	W04
	.byte		N01   , Dn3 
	.byte	W02
	.byte		VOICE , 8
	.byte	FINE

@******************************************************@

	.align	2

se_mon_catch_ball_shake:  @ 0x0869FE14
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mon_catch_ball_shake_pri	@ Priority
	.byte	se_mon_catch_ball_shake_rev	@ Reverb

	.word	se_mon_catch_ball_shake_grp

	.word	se_mon_catch_ball_shake_0
@ 0x0869FE20
