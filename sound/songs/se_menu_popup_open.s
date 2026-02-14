	.include "sound/MPlayDef.s"

	.equ	se_menu_popup_open_grp, gUnknown_08532310
	.equ	se_menu_popup_open_pri, 5
	.equ	se_menu_popup_open_rev, reverb_set+50
	.equ	se_menu_popup_open_mvl, 127
	.equ	se_menu_popup_open_key, 0
	.equ	se_menu_popup_open_tbs, 1
	.equ	se_menu_popup_open_exg, 0
	.equ	se_menu_popup_open_cmp, 1

	.section .rodata
	.global	se_menu_popup_open
	.align	2

@*********************** Track 01 ***********************@

se_menu_popup_open_0:  @ 0x0869EF58
	.byte	KEYSH , se_menu_popup_open_key+0
	.byte	TEMPO , 150*se_menu_popup_open_tbs/2
	.byte		VOL   , 100*se_menu_popup_open_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 13
	.byte		N12   , An2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_menu_popup_open:  @ 0x0869EF68
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_menu_popup_open_pri	@ Priority
	.byte	se_menu_popup_open_rev	@ Reverb

	.word	se_menu_popup_open_grp

	.word	se_menu_popup_open_0
@ 0x0869EF74
