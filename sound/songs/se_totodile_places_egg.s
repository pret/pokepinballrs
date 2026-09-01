	.include "sound/MPlayDef.s"

	.equ	se_totodile_places_egg_grp, gVoiceGroup_SFX_0853174C
	.equ	se_totodile_places_egg_pri, 5
	.equ	se_totodile_places_egg_rev, reverb_set+50
	.equ	se_totodile_places_egg_mvl, 127
	.equ	se_totodile_places_egg_key, 0
	.equ	se_totodile_places_egg_tbs, 1
	.equ	se_totodile_places_egg_exg, 0
	.equ	se_totodile_places_egg_cmp, 1

	.section .rodata
	.global	se_totodile_places_egg
	.align	2

@*********************** Track 01 ***********************@

se_totodile_places_egg_0:  @ 0x086A320C
	.byte	KEYSH , se_totodile_places_egg_key+0
	.byte	TEMPO , 150*se_totodile_places_egg_tbs/2
	.byte		VOICE , 122
	.byte		VOL   , 100*se_totodile_places_egg_mvl/mxv
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		VOICE , 126
	.byte		N01   , Gs4 
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        Gs4 , v088
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_totodile_places_egg:  @ 0x086A3224
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_totodile_places_egg_pri	@ Priority
	.byte	se_totodile_places_egg_rev	@ Reverb

	.word	se_totodile_places_egg_grp

	.word	se_totodile_places_egg_0
@ 0x086A3230
