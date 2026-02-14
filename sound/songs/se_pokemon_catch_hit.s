	.include "sound/MPlayDef.s"

	.equ	se_pokemon_catch_hit_grp, gUnknown_08532310
	.equ	se_pokemon_catch_hit_pri, 5
	.equ	se_pokemon_catch_hit_rev, reverb_set+50
	.equ	se_pokemon_catch_hit_mvl, 127
	.equ	se_pokemon_catch_hit_key, 0
	.equ	se_pokemon_catch_hit_tbs, 1
	.equ	se_pokemon_catch_hit_exg, 0
	.equ	se_pokemon_catch_hit_cmp, 1

	.section .rodata
	.global	se_pokemon_catch_hit
	.align	2

@*********************** Track 01 ***********************@

se_pokemon_catch_hit_0:  @ 0x0869F168
	.byte	KEYSH , se_pokemon_catch_hit_key+0
	.byte	TEMPO , 150*se_pokemon_catch_hit_tbs/2
	.byte		VOL   , 90*se_pokemon_catch_hit_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 11
	.byte		LFOS  , 48
	.byte		MOD   , 24
	.byte		N02   , Cn4 , v127
	.byte	W02
	.byte		N06   , En4 , v064
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pokemon_catch_hit:  @ 0x0869F180
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pokemon_catch_hit_pri	@ Priority
	.byte	se_pokemon_catch_hit_rev	@ Reverb

	.word	se_pokemon_catch_hit_grp

	.word	se_pokemon_catch_hit_0
@ 0x0869F18C
