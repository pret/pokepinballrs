	.include "sound/MPlayDef.s"

	.equ	se_wall_hit_grp, gUnknown_08532310
	.equ	se_wall_hit_pri, 5
	.equ	se_wall_hit_rev, reverb_set+50
	.equ	se_wall_hit_mvl, 127
	.equ	se_wall_hit_key, 0
	.equ	se_wall_hit_tbs, 1
	.equ	se_wall_hit_exg, 0
	.equ	se_wall_hit_cmp, 1

	.section .rodata
	.global	se_wall_hit
	.align	2

@*********************** Track 01 ***********************@

se_wall_hit_0:  @ 0x0869F1D0
	.byte	KEYSH , se_wall_hit_key+0
	.byte	TEMPO , 150*se_wall_hit_tbs/2
	.byte		VOL   , 80*se_wall_hit_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 31
	.byte		N06   , Bn0 , v127
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_wall_hit:  @ 0x0869F1E0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_wall_hit_pri	@ Priority
	.byte	se_wall_hit_rev	@ Reverb

	.word	se_wall_hit_grp

	.word	se_wall_hit_0
@ 0x0869F1EC
