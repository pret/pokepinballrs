	.include "sound/MPlayDef.s"

	.equ	se_ball_summary_text_progress_grp, gUnknown_08532310
	.equ	se_ball_summary_text_progress_pri, 5
	.equ	se_ball_summary_text_progress_rev, reverb_set+50
	.equ	se_ball_summary_text_progress_mvl, 127
	.equ	se_ball_summary_text_progress_key, 0
	.equ	se_ball_summary_text_progress_tbs, 1
	.equ	se_ball_summary_text_progress_exg, 0
	.equ	se_ball_summary_text_progress_cmp, 1

	.section .rodata
	.global	se_ball_summary_text_progress
	.align	2

@*********************** Track 01 ***********************@

se_ball_summary_text_progress_0:  @ 0x0869FE98
	.byte	KEYSH , se_ball_summary_text_progress_key+0
	.byte	TEMPO , 150*se_ball_summary_text_progress_tbs/2
	.byte		VOL   , 100*se_ball_summary_text_progress_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_ball_summary_text_progress:  @ 0x0869FEA8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ball_summary_text_progress_pri	@ Priority
	.byte	se_ball_summary_text_progress_rev	@ Reverb

	.word	se_ball_summary_text_progress_grp

	.word	se_ball_summary_text_progress_0
@ 0x0869FEB4
