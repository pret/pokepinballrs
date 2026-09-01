	.include "sound/MPlayDef.s"

	.equ	se_spheal_submerging_after_scoring_grp, gVoiceGroup_SFX_08532310
	.equ	se_spheal_submerging_after_scoring_pri, 5
	.equ	se_spheal_submerging_after_scoring_rev, reverb_set+50
	.equ	se_spheal_submerging_after_scoring_mvl, 127
	.equ	se_spheal_submerging_after_scoring_key, 0
	.equ	se_spheal_submerging_after_scoring_tbs, 1
	.equ	se_spheal_submerging_after_scoring_exg, 0
	.equ	se_spheal_submerging_after_scoring_cmp, 1

	.section .rodata
	.global	se_spheal_submerging_after_scoring
	.align	2

@*********************** Track 01 ***********************@

se_spheal_submerging_after_scoring_0:  @ 0x086A2CC8
	.byte	KEYSH , se_spheal_submerging_after_scoring_key+0
	.byte	TEMPO , 150*se_spheal_submerging_after_scoring_tbs/2
	.byte		VOL   , 110*se_spheal_submerging_after_scoring_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		N08   , Dn3 , v127
	.byte	W08
	.byte		TIE   , An2 , v127
	.byte	W36
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_spheal_submerging_after_scoring:  @ 0x086A2CDC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_spheal_submerging_after_scoring_pri	@ Priority
	.byte	se_spheal_submerging_after_scoring_rev	@ Reverb

	.word	se_spheal_submerging_after_scoring_grp

	.word	se_spheal_submerging_after_scoring_0
@ 0x086A2CE8
