	.include "sound/MPlayDef.s"

	.equ	se_score_entry_a_b_move_grp, gUnknown_08532310
	.equ	se_score_entry_a_b_move_pri, 5
	.equ	se_score_entry_a_b_move_rev, reverb_set+50
	.equ	se_score_entry_a_b_move_mvl, 127
	.equ	se_score_entry_a_b_move_key, 0
	.equ	se_score_entry_a_b_move_tbs, 1
	.equ	se_score_entry_a_b_move_exg, 0
	.equ	se_score_entry_a_b_move_cmp, 1

	.section .rodata
	.global	se_score_entry_a_b_move
	.align	2

@*********************** Track 01 ***********************@

se_score_entry_a_b_move_0:  @ 0x0869EF90
	.byte	KEYSH , se_score_entry_a_b_move_key+0
	.byte	TEMPO , 150*se_score_entry_a_b_move_tbs/2
	.byte		VOL   , 100*se_score_entry_a_b_move_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_score_entry_a_b_move:  @ 0x0869EFA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_score_entry_a_b_move_pri	@ Priority
	.byte	se_score_entry_a_b_move_rev	@ Reverb

	.word	se_score_entry_a_b_move_grp

	.word	se_score_entry_a_b_move_0
@ 0x0869EFAC
