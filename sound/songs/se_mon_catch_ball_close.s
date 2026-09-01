	.include "sound/MPlayDef.s"

	.equ	se_mon_catch_ball_close_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_mon_catch_ball_close_pri, 5
	.equ	se_mon_catch_ball_close_rev, reverb_set+50
	.equ	se_mon_catch_ball_close_mvl, 127
	.equ	se_mon_catch_ball_close_key, 0
	.equ	se_mon_catch_ball_close_tbs, 1
	.equ	se_mon_catch_ball_close_exg, 0
	.equ	se_mon_catch_ball_close_cmp, 1

	.section .rodata
	.global	se_mon_catch_ball_close
	.align	2

@*********************** Track 01 ***********************@

se_mon_catch_ball_close_0:  @ 0x0869FD88
	.byte	KEYSH , se_mon_catch_ball_close_key+0
	.byte	TEMPO , 150*se_mon_catch_ball_close_tbs/2
	.byte		VOICE , 14
	.byte		VOL   , 80*se_mon_catch_ball_close_mvl/mxv
	.byte		BEND  , c_v+17
	.byte		N03   , En3 , v096
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N24   , Cn6 
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_mon_catch_ball_close_1:  @ 0x0869FDA6
	.byte	KEYSH , se_mon_catch_ball_close_key+0
	.byte		VOICE , 17
	.byte		VOL   , 80*se_mon_catch_ball_close_mvl/mxv
	.byte		N03   , En3 , v100
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N24   , Cn6 
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_mon_catch_ball_close:  @ 0x0869FDC0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mon_catch_ball_close_pri	@ Priority
	.byte	se_mon_catch_ball_close_rev	@ Reverb

	.word	se_mon_catch_ball_close_grp

	.word	se_mon_catch_ball_close_0
	.word	se_mon_catch_ball_close_1
@ 0x0869FDD0
