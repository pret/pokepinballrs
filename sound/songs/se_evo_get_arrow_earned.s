	.include "sound/MPlayDef.s"

	.equ	se_evo_get_arrow_earned_grp, gVoiceGroup_SFX_0853174C
	.equ	se_evo_get_arrow_earned_pri, 5
	.equ	se_evo_get_arrow_earned_rev, reverb_set+50
	.equ	se_evo_get_arrow_earned_mvl, 127
	.equ	se_evo_get_arrow_earned_key, 0
	.equ	se_evo_get_arrow_earned_tbs, 1
	.equ	se_evo_get_arrow_earned_exg, 0
	.equ	se_evo_get_arrow_earned_cmp, 1

	.section .rodata
	.global	se_evo_get_arrow_earned
	.align	2

@*********************** Track 01 ***********************@

se_evo_get_arrow_earned_0:  @ 0x0869FBE0
	.byte	KEYSH , se_evo_get_arrow_earned_key+0
	.byte	TEMPO , 128*se_evo_get_arrow_earned_tbs/2
	.byte		VOICE , 6
	.byte		BENDR , 12
	.byte		VOL   , 90*se_evo_get_arrow_earned_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		N03   , Gs3 , v100
	.byte	W05
	.byte		N16   , Fn5 , v072
	.byte	W05
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_evo_get_arrow_earned_1:  @ 0x0869FBFA
	.byte	KEYSH , se_evo_get_arrow_earned_key+0
	.byte		VOICE , 14
	.byte		VOL   , 90*se_evo_get_arrow_earned_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		N03   , Gs3 , v060
	.byte	W05
	.byte		N16   , Fn5 
	.byte	W05
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_evo_get_arrow_earned:  @ 0x0869FC0C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_evo_get_arrow_earned_pri	@ Priority
	.byte	se_evo_get_arrow_earned_rev	@ Reverb

	.word	se_evo_get_arrow_earned_grp

	.word	se_evo_get_arrow_earned_0
	.word	se_evo_get_arrow_earned_1
@ 0x0869FC1C
