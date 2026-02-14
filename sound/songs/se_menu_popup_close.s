	.include "sound/MPlayDef.s"

	.equ	se_menu_popup_close_grp, gUnknown_08532310
	.equ	se_menu_popup_close_pri, 5
	.equ	se_menu_popup_close_rev, reverb_set+50
	.equ	se_menu_popup_close_mvl, 127
	.equ	se_menu_popup_close_key, 0
	.equ	se_menu_popup_close_tbs, 1
	.equ	se_menu_popup_close_exg, 0
	.equ	se_menu_popup_close_cmp, 1

	.section .rodata
	.global	se_menu_popup_close
	.align	2

@*********************** Track 01 ***********************@

se_menu_popup_close_0:  @ 0x0869EF74
	.byte	KEYSH , se_menu_popup_close_key+0
	.byte	TEMPO , 150*se_menu_popup_close_tbs/2
	.byte		VOL   , 100*se_menu_popup_close_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 14
	.byte		N12   , An3 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_menu_popup_close:  @ 0x0869EF84
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_menu_popup_close_pri	@ Priority
	.byte	se_menu_popup_close_rev	@ Reverb

	.word	se_menu_popup_close_grp

	.word	se_menu_popup_close_0
@ 0x0869EF90
