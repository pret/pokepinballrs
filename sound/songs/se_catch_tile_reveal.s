	.include "sound/MPlayDef.s"

	.equ	se_catch_tile_reveal_grp, gUnknown_0853174C
	.equ	se_catch_tile_reveal_pri, 5
	.equ	se_catch_tile_reveal_rev, reverb_set+50
	.equ	se_catch_tile_reveal_mvl, 127
	.equ	se_catch_tile_reveal_key, 0
	.equ	se_catch_tile_reveal_tbs, 1
	.equ	se_catch_tile_reveal_exg, 0
	.equ	se_catch_tile_reveal_cmp, 1

	.section .rodata
	.global	se_catch_tile_reveal
	.align	2

@*********************** Track 01 ***********************@

se_catch_tile_reveal_0:  @ 0x0869F7D4
	.byte	KEYSH , se_catch_tile_reveal_key+0
	.byte	TEMPO , 90*se_catch_tile_reveal_tbs/2
	.byte		VOICE , 125
	.byte		VOL   , 110*se_catch_tile_reveal_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , As2 , v100
	.byte	W03
	.byte		BEND  , c_v-33
	.byte		N36   , Ds3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_catch_tile_reveal_1:  @ 0x0869F7F6
	.byte	KEYSH , se_catch_tile_reveal_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_catch_tile_reveal_mvl/mxv
	.byte		N03   , Cn3 , v127
	.byte	W03
	.byte		N18
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_catch_tile_reveal:  @ 0x0869F810
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_catch_tile_reveal_pri	@ Priority
	.byte	se_catch_tile_reveal_rev	@ Reverb

	.word	se_catch_tile_reveal_grp

	.word	se_catch_tile_reveal_0
	.word	se_catch_tile_reveal_1
@ 0x0869F820
