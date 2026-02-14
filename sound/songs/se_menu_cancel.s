	.include "sound/MPlayDef.s"

	.equ	se_menu_cancel_grp, gUnknown_0853174C
	.equ	se_menu_cancel_pri, 5
	.equ	se_menu_cancel_rev, reverb_set+50
	.equ	se_menu_cancel_mvl, 127
	.equ	se_menu_cancel_key, 0
	.equ	se_menu_cancel_tbs, 1
	.equ	se_menu_cancel_exg, 0
	.equ	se_menu_cancel_cmp, 1

	.section .rodata
	.global	se_menu_cancel
	.align	2

@*********************** Track 01 ***********************@

se_menu_cancel_0:  @ 0x0869EEC4
	.byte	KEYSH , se_menu_cancel_key+0
	.byte	TEMPO , 144*se_menu_cancel_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_menu_cancel_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W03
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W04
	.byte	FINE

@*********************** Track 02 ***********************@

se_menu_cancel_1:  @ 0x0869EEF1
	.byte	KEYSH , se_menu_cancel_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_menu_cancel_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_menu_cancel:  @ 0x0869EF1C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_menu_cancel_pri	@ Priority
	.byte	se_menu_cancel_rev	@ Reverb

	.word	se_menu_cancel_grp

	.word	se_menu_cancel_0
	.word	se_menu_cancel_1
@ 0x0869EF2C
