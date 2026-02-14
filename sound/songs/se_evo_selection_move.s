	.include "sound/MPlayDef.s"

	.equ	se_evo_selection_move_grp, gUnknown_0853174C
	.equ	se_evo_selection_move_pri, 5
	.equ	se_evo_selection_move_rev, reverb_set+50
	.equ	se_evo_selection_move_mvl, 127
	.equ	se_evo_selection_move_key, 0
	.equ	se_evo_selection_move_tbs, 1
	.equ	se_evo_selection_move_exg, 0
	.equ	se_evo_selection_move_cmp, 1

	.section .rodata
	.global	se_evo_selection_move
	.align	2

@*********************** Track 01 ***********************@

se_evo_selection_move_0:  @ 0x0869F46C
	.byte	KEYSH , se_evo_selection_move_key+0
	.byte		VOICE , 13
	.byte		BENDR , 12
	.byte		VOL   , 12*se_evo_selection_move_mvl/mxv
	.byte		BEND  , c_v+49
	.byte		N06   , Gn4 , v080
	.byte	W01
	.byte		VOL   , 44*se_evo_selection_move_mvl/mxv
	.byte		BEND  , c_v+22
	.byte	W01
	.byte		VOL   , 75*se_evo_selection_move_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		VOL   , 87*se_evo_selection_move_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		VOL   , 100*se_evo_selection_move_mvl/mxv
	.byte		BEND  , c_v+54
	.byte	W01
	.byte		        c_v+63
	.byte	W01
	.byte	W03
	.byte		N03   , Gn4 , v040
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_evo_selection_move_1:  @ 0x0869F496
	.byte	KEYSH , se_evo_selection_move_key+0
	.byte		VOICE , 123
	.byte		VOL   , 59*se_evo_selection_move_mvl/mxv
	.byte		N06   , Gs4 , v052
	.byte	W01
	.byte		VOL   , 72*se_evo_selection_move_mvl/mxv
	.byte	W01
	.byte		        90*se_evo_selection_move_mvl/mxv
	.byte	W01
	.byte		        100*se_evo_selection_move_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		N03   , Gs4 , v024
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_evo_selection_move:  @ 0x0869F4B0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_evo_selection_move_pri	@ Priority
	.byte	se_evo_selection_move_rev	@ Reverb

	.word	se_evo_selection_move_grp

	.word	se_evo_selection_move_0
	.word	se_evo_selection_move_1
@ 0x0869F4C0
