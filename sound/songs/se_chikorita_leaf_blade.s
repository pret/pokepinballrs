	.include "sound/MPlayDef.s"

	.equ	se_chikorita_leaf_blade_grp, gUnknown_08532310
	.equ	se_chikorita_leaf_blade_pri, 5
	.equ	se_chikorita_leaf_blade_rev, reverb_set+50
	.equ	se_chikorita_leaf_blade_mvl, 127
	.equ	se_chikorita_leaf_blade_key, 0
	.equ	se_chikorita_leaf_blade_tbs, 1
	.equ	se_chikorita_leaf_blade_exg, 0
	.equ	se_chikorita_leaf_blade_cmp, 1

	.section .rodata
	.global	se_chikorita_leaf_blade
	.align	2

@*********************** Track 01 ***********************@

se_chikorita_leaf_blade_0:  @ 0x086A0830
	.byte	KEYSH , se_chikorita_leaf_blade_key+0
	.byte	TEMPO , 150*se_chikorita_leaf_blade_tbs/2
	.byte		VOL   , 110*se_chikorita_leaf_blade_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 33
	.byte		N06   , Cn4 , v127
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_chikorita_leaf_blade:  @ 0x086A0840
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_chikorita_leaf_blade_pri	@ Priority
	.byte	se_chikorita_leaf_blade_rev	@ Reverb

	.word	se_chikorita_leaf_blade_grp

	.word	se_chikorita_leaf_blade_0
@ 0x086A084C
