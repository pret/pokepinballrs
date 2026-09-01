	.include "sound/MPlayDef.s"

	.equ	se_sealeo_hit_thud_grp, gVoiceGroup_SFX_0853174C
	.equ	se_sealeo_hit_thud_pri, 5
	.equ	se_sealeo_hit_thud_rev, reverb_set+50
	.equ	se_sealeo_hit_thud_mvl, 127
	.equ	se_sealeo_hit_thud_key, 0
	.equ	se_sealeo_hit_thud_tbs, 1
	.equ	se_sealeo_hit_thud_exg, 0
	.equ	se_sealeo_hit_thud_cmp, 1

	.section .rodata
	.global	se_sealeo_hit_thud
	.align	2

@*********************** Track 01 ***********************@

se_sealeo_hit_thud_0:  @ 0x086A2E9C
	.byte	KEYSH , se_sealeo_hit_thud_key+0
	.byte	TEMPO , 220*se_sealeo_hit_thud_tbs/2
	.byte		VOICE , 89
	.byte		VOL   , 80*se_sealeo_hit_thud_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_sealeo_hit_thud:  @ 0x086A2EAC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_sealeo_hit_thud_pri	@ Priority
	.byte	se_sealeo_hit_thud_rev	@ Reverb

	.word	se_sealeo_hit_thud_grp

	.word	se_sealeo_hit_thud_0
@ 0x086A2EB8
