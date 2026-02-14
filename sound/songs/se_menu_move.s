	.include "sound/MPlayDef.s"

	.equ	se_menu_move_grp, gUnknown_0853174C
	.equ	se_menu_move_pri, 5
	.equ	se_menu_move_rev, reverb_set+50
	.equ	se_menu_move_mvl, 127
	.equ	se_menu_move_key, 0
	.equ	se_menu_move_tbs, 1
	.equ	se_menu_move_exg, 0
	.equ	se_menu_move_cmp, 1

	.section .rodata
	.global	se_menu_move
	.align	2

@*********************** Track 01 ***********************@

se_menu_move_0:  @ 0x0869EF2C
	.byte	KEYSH , se_menu_move_key+0
	.byte	TEMPO , 300*se_menu_move_tbs/2
	.byte		VOICE , 87
	.byte		VOL   , 80*se_menu_move_mvl/mxv
	.byte		BEND  , c_v+13
	.byte		N03   , As5 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		VOICE , 88
	.byte		N06   , Gn6 , v068
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_menu_move:  @ 0x0869EF4C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_menu_move_pri	@ Priority
	.byte	se_menu_move_rev	@ Reverb

	.word	se_menu_move_grp

	.word	se_menu_move_0
@ 0x0869EF58
