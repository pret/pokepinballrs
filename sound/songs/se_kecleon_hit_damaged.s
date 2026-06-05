	.include "sound/MPlayDef.s"

	.equ	se_kecleon_hit_damaged_grp, gUnknown_08531D4C
	.equ	se_kecleon_hit_damaged_pri, 5
	.equ	se_kecleon_hit_damaged_rev, reverb_set+50
	.equ	se_kecleon_hit_damaged_mvl, 127
	.equ	se_kecleon_hit_damaged_key, 0
	.equ	se_kecleon_hit_damaged_tbs, 1
	.equ	se_kecleon_hit_damaged_exg, 0
	.equ	se_kecleon_hit_damaged_cmp, 1

	.section .rodata
	.global	se_kecleon_hit_damaged
	.align	2

@*********************** Track 01 ***********************@

se_kecleon_hit_damaged_0:  @ 0x086A1C74
	.byte	KEYSH , se_kecleon_hit_damaged_key+0
	.byte	TEMPO , 240*se_kecleon_hit_damaged_tbs/2
	.byte		VOICE , 122
	.byte		BENDR , 3
	.byte		VOL   , 95*se_kecleon_hit_damaged_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , Cn4 , v127
	.byte	W24
	.byte		BEND  , c_v-64
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_kecleon_hit_damaged:  @ 0x086A1C88
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kecleon_hit_damaged_pri	@ Priority
	.byte	se_kecleon_hit_damaged_rev	@ Reverb

	.word	se_kecleon_hit_damaged_grp

	.word	se_kecleon_hit_damaged_0
@ 0x086A1C94
