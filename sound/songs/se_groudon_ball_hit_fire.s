	.include "sound/MPlayDef.s"

	.equ	se_groudon_ball_hit_fire_grp, gUnknown_0853174C
	.equ	se_groudon_ball_hit_fire_pri, 5
	.equ	se_groudon_ball_hit_fire_rev, reverb_set+50
	.equ	se_groudon_ball_hit_fire_mvl, 127
	.equ	se_groudon_ball_hit_fire_key, 0
	.equ	se_groudon_ball_hit_fire_tbs, 1
	.equ	se_groudon_ball_hit_fire_exg, 0
	.equ	se_groudon_ball_hit_fire_cmp, 1

	.section .rodata
	.global	se_groudon_ball_hit_fire
	.align	2

@*********************** Track 01 ***********************@

se_groudon_ball_hit_fire_0:  @ 0x086A27F0
	.byte	KEYSH , se_groudon_ball_hit_fire_key+0
	.byte	TEMPO , 90*se_groudon_ball_hit_fire_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_groudon_ball_hit_fire_mvl/mxv
	.byte		N03   , Gn2 , v100
	.byte	W03
	.byte		N06   , As2 
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_groudon_ball_hit_fire_1:  @ 0x086A2801
	.byte	KEYSH , se_groudon_ball_hit_fire_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_groudon_ball_hit_fire_mvl/mxv
	.byte		N09   , As1 , v127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_groudon_ball_hit_fire:  @ 0x086A2810
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_groudon_ball_hit_fire_pri	@ Priority
	.byte	se_groudon_ball_hit_fire_rev	@ Reverb

	.word	se_groudon_ball_hit_fire_grp

	.word	se_groudon_ball_hit_fire_0
	.word	se_groudon_ball_hit_fire_1
@ 0x086A2820
