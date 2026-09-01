	.include "sound/MPlayDef.s"

	.equ	se_shop_eject_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_shop_eject_pri, 5
	.equ	se_shop_eject_rev, reverb_set+50
	.equ	se_shop_eject_mvl, 127
	.equ	se_shop_eject_key, 0
	.equ	se_shop_eject_tbs, 1
	.equ	se_shop_eject_exg, 0
	.equ	se_shop_eject_cmp, 1

	.section .rodata
	.global	se_shop_eject
	.align	2

@*********************** Track 01 ***********************@

se_shop_eject_0:  @ 0x086A072C
	.byte	KEYSH , se_shop_eject_key+0
	.byte	TEMPO , 150*se_shop_eject_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_shop_eject_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_shop_eject:  @ 0x086A0744
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_shop_eject_pri	@ Priority
	.byte	se_shop_eject_rev	@ Reverb

	.word	se_shop_eject_grp

	.word	se_shop_eject_0
@ 0x086A0750
