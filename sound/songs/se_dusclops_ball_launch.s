	.include "sound/MPlayDef.s"

	.equ	se_dusclops_ball_launch_grp, gUnknown_08531D4C
	.equ	se_dusclops_ball_launch_pri, 5
	.equ	se_dusclops_ball_launch_rev, reverb_set+50
	.equ	se_dusclops_ball_launch_mvl, 127
	.equ	se_dusclops_ball_launch_key, 0
	.equ	se_dusclops_ball_launch_tbs, 1
	.equ	se_dusclops_ball_launch_exg, 0
	.equ	se_dusclops_ball_launch_cmp, 1

	.section .rodata
	.global	se_dusclops_ball_launch
	.align	2

@*********************** Track 01 ***********************@

se_dusclops_ball_launch_0:  @ 0x086A18E4
	.byte	KEYSH , se_dusclops_ball_launch_key+0
	.byte	TEMPO , 150*se_dusclops_ball_launch_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 110*se_dusclops_ball_launch_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , En3 , v127
	.byte	W03
	.byte		N01   , As3 
	.byte	W03
	.byte		N02   , Gn3 
	.byte	W03
	.byte		N01   , Cs4 
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		N01   , As3 
	.byte	W03
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v040
	.byte	W03
	.byte		N01   , Cs4 
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_dusclops_ball_launch_1:  @ 0x086A1912
	.byte	KEYSH , se_dusclops_ball_launch_key+0
	.byte		VOICE , 5
	.byte		VOL   , 110*se_dusclops_ball_launch_mvl/mxv
	.byte		N01   , Cn3 , v040
	.byte	W02
	.byte		N01
	.byte	W04
	.byte		N01
	.byte	W02
	.byte		N01
	.byte	W04
se_dusclops_ball_launch_1_B1:
	.byte		N01   , Cn3 , v020
	.byte	W02
	.byte		N01
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	se_dusclops_ball_launch_1_B1
	.byte	FINE

@******************************************************@

	.align	2

se_dusclops_ball_launch:  @ 0x086A1930
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_dusclops_ball_launch_pri	@ Priority
	.byte	se_dusclops_ball_launch_rev	@ Reverb

	.word	se_dusclops_ball_launch_grp

	.word	se_dusclops_ball_launch_0
	.word	se_dusclops_ball_launch_1
@ 0x086A1940
