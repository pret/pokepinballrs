	.include "sound/MPlayDef.s"

	.equ	se_kyogre_freeze_hits_ball_grp, gUnknown_08531D4C
	.equ	se_kyogre_freeze_hits_ball_pri, 5
	.equ	se_kyogre_freeze_hits_ball_rev, reverb_set+50
	.equ	se_kyogre_freeze_hits_ball_mvl, 127
	.equ	se_kyogre_freeze_hits_ball_key, 0
	.equ	se_kyogre_freeze_hits_ball_tbs, 1
	.equ	se_kyogre_freeze_hits_ball_exg, 0
	.equ	se_kyogre_freeze_hits_ball_cmp, 1

	.section .rodata
	.global	se_kyogre_freeze_hits_ball
	.align	2

@*********************** Track 01 ***********************@

se_kyogre_freeze_hits_ball_0:  @ 0x086A2104
	.byte	KEYSH , se_kyogre_freeze_hits_ball_key+0
	.byte	TEMPO , 150*se_kyogre_freeze_hits_ball_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 90*se_kyogre_freeze_hits_ball_mvl/mxv
	.byte		BEND  , c_v+16
	.byte		N03   , En3 , v112
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		N12   , En4 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_kyogre_freeze_hits_ball_1:  @ 0x086A211D
	.byte	KEYSH , se_kyogre_freeze_hits_ball_key+0
	.byte		VOICE , 4
	.byte		VOL   , 90*se_kyogre_freeze_hits_ball_mvl/mxv
	.byte		N03   , Gs3 , v096
	.byte	W04
	.byte		N12   , Gs4 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_kyogre_freeze_hits_ball:  @ 0x086A2130
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kyogre_freeze_hits_ball_pri	@ Priority
	.byte	se_kyogre_freeze_hits_ball_rev	@ Reverb

	.word	se_kyogre_freeze_hits_ball_grp

	.word	se_kyogre_freeze_hits_ball_0
	.word	se_kyogre_freeze_hits_ball_1
@ 0x086A2140
