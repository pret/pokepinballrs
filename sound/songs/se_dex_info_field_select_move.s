	.include "sound/MPlayDef.s"

	.equ	se_dex_info_field_select_move_grp, gUnknown_08532310
	.equ	se_dex_info_field_select_move_pri, 5
	.equ	se_dex_info_field_select_move_rev, reverb_set+50
	.equ	se_dex_info_field_select_move_mvl, 127
	.equ	se_dex_info_field_select_move_key, 0
	.equ	se_dex_info_field_select_move_tbs, 1
	.equ	se_dex_info_field_select_move_exg, 0
	.equ	se_dex_info_field_select_move_cmp, 1

	.section .rodata
	.global	se_dex_info_field_select_move
	.align	2

@*********************** Track 01 ***********************@

se_dex_info_field_select_move_0:  @ 0x0869EFF8
	.byte	KEYSH , se_dex_info_field_select_move_key+0
	.byte	TEMPO , 150*se_dex_info_field_select_move_tbs/2
	.byte		VOICE , 4
	.byte		VOL   , 100*se_dex_info_field_select_move_mvl/mxv
	.byte		N04   , Fs4 , v127
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_dex_info_field_select_move:  @ 0x0869F008
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_dex_info_field_select_move_pri	@ Priority
	.byte	se_dex_info_field_select_move_rev	@ Reverb

	.word	se_dex_info_field_select_move_grp

	.word	se_dex_info_field_select_move_0
@ 0x0869F014
