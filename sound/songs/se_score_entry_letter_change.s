	.include "sound/MPlayDef.s"

	.equ	se_score_entry_letter_change_grp, gUnknown_0853174C
	.equ	se_score_entry_letter_change_pri, 5
	.equ	se_score_entry_letter_change_rev, reverb_set+50
	.equ	se_score_entry_letter_change_mvl, 127
	.equ	se_score_entry_letter_change_key, 0
	.equ	se_score_entry_letter_change_tbs, 1
	.equ	se_score_entry_letter_change_exg, 0
	.equ	se_score_entry_letter_change_cmp, 1

	.section .rodata
	.global	se_score_entry_letter_change
	.align	2

@*********************** Track 01 ***********************@

se_score_entry_letter_change_0:  @ 0x0869EFAC
	.byte	KEYSH , se_score_entry_letter_change_key+0
	.byte	TEMPO , 100*se_score_entry_letter_change_tbs/2
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 40*se_score_entry_letter_change_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N01   , Gn4 , v127
	.byte	W01
	.byte		        Gn4 , v020
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_score_entry_letter_change:  @ 0x0869EFC8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_score_entry_letter_change_pri	@ Priority
	.byte	se_score_entry_letter_change_rev	@ Reverb

	.word	se_score_entry_letter_change_grp

	.word	se_score_entry_letter_change_0
@ 0x0869EFD4
