	.include "sound/MPlayDef.s"

	.equ	se_totodile_climbs_rope_grp, gUnknown_0853174C
	.equ	se_totodile_climbs_rope_pri, 5
	.equ	se_totodile_climbs_rope_rev, reverb_set+50
	.equ	se_totodile_climbs_rope_mvl, 127
	.equ	se_totodile_climbs_rope_key, 0
	.equ	se_totodile_climbs_rope_tbs, 1
	.equ	se_totodile_climbs_rope_exg, 0
	.equ	se_totodile_climbs_rope_cmp, 1

	.section .rodata
	.global	se_totodile_climbs_rope
	.align	2

@*********************** Track 01 ***********************@

se_totodile_climbs_rope_0:  @ 0x086A3230
	.byte	KEYSH , se_totodile_climbs_rope_key+0
	.byte	TEMPO , 150*se_totodile_climbs_rope_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 120*se_totodile_climbs_rope_mvl/mxv
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W08
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_totodile_climbs_rope:  @ 0x086A3254
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_totodile_climbs_rope_pri	@ Priority
	.byte	se_totodile_climbs_rope_rev	@ Reverb

	.word	se_totodile_climbs_rope_grp

	.word	se_totodile_climbs_rope_0
@ 0x086A3260
