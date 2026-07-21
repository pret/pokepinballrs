	.include "sound/MPlayDef.s"

	.equ	se_bonus_score_tallied_grp, gUnknown_0853174C
	.equ	se_bonus_score_tallied_pri, 5
	.equ	se_bonus_score_tallied_rev, reverb_set+50
	.equ	se_bonus_score_tallied_mvl, 127
	.equ	se_bonus_score_tallied_key, 0
	.equ	se_bonus_score_tallied_tbs, 1
	.equ	se_bonus_score_tallied_exg, 0
	.equ	se_bonus_score_tallied_cmp, 1

	.section .rodata
	.global	se_bonus_score_tallied
	.align	2

@*********************** Track 01 ***********************@

se_bonus_score_tallied_0:  @ 0x0869F950
	.byte	KEYSH , se_bonus_score_tallied_key+0
	.byte	TEMPO , 100*se_bonus_score_tallied_tbs/2
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 90*se_bonus_score_tallied_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N01   , Cn5 , v064
	.byte	W01
	.byte		        Cn5 , v020
	.byte	W01
	.byte		        Cn5 , v064
	.byte	W01
	.byte		        Cn5 , v020
	.byte	W01
	.byte		        Cn6 , v064
	.byte	W02
	.byte		        Cn6 , v020
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_bonus_score_tallied:  @ 0x0869F978
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_bonus_score_tallied_pri	@ Priority
	.byte	se_bonus_score_tallied_rev	@ Reverb

	.word	se_bonus_score_tallied_grp

	.word	se_bonus_score_tallied_0
@ 0x0869F984
