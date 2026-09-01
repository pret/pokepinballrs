	.include "sound/MPlayDef.s"

	.equ	se_unused_0xcb_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_unused_0xcb_pri, 5
	.equ	se_unused_0xcb_rev, reverb_set+50
	.equ	se_unused_0xcb_mvl, 127
	.equ	se_unused_0xcb_key, 0
	.equ	se_unused_0xcb_tbs, 1
	.equ	se_unused_0xcb_exg, 0
	.equ	se_unused_0xcb_cmp, 1

	.section .rodata
	.global	se_unused_0xcb
	.align	2

@*********************** Track 01 ***********************@

se_unused_0xcb_0:  @ 0x086A091C
	.byte	KEYSH , se_unused_0xcb_key+0
	.byte	TEMPO , 150*se_unused_0xcb_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unused_0xcb_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0xcb:  @ 0x086A0934
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0xcb_pri	@ Priority
	.byte	se_unused_0xcb_rev	@ Reverb

	.word	se_unused_0xcb_grp

	.word	se_unused_0xcb_0
@ 0x086A0940
