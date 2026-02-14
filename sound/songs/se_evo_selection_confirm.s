	.include "sound/MPlayDef.s"

	.equ	se_evo_selection_confirm_grp, gUnknown_0853174C
	.equ	se_evo_selection_confirm_pri, 5
	.equ	se_evo_selection_confirm_rev, reverb_set+50
	.equ	se_evo_selection_confirm_mvl, 127
	.equ	se_evo_selection_confirm_key, 0
	.equ	se_evo_selection_confirm_tbs, 1
	.equ	se_evo_selection_confirm_exg, 0
	.equ	se_evo_selection_confirm_cmp, 1

	.section .rodata
	.global	se_evo_selection_confirm
	.align	2

@*********************** Track 01 ***********************@

se_evo_selection_confirm_0:  @ 0x0869F4C0
	.byte	KEYSH , se_evo_selection_confirm_key+0
	.byte	TEMPO , 240*se_evo_selection_confirm_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 80*se_evo_selection_confirm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gn5 , v127
	.byte	W06
	.byte		N18   , Ds5 
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_evo_selection_confirm:  @ 0x0869F4D4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_evo_selection_confirm_pri	@ Priority
	.byte	se_evo_selection_confirm_rev	@ Reverb

	.word	se_evo_selection_confirm_grp

	.word	se_evo_selection_confirm_0
@ 0x0869F4E0
