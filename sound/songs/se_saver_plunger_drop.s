	.include "sound/MPlayDef.s"

	.equ	se_saver_plunger_drop_grp, gUnknown_08531D4C
	.equ	se_saver_plunger_drop_pri, 5
	.equ	se_saver_plunger_drop_rev, reverb_set+50
	.equ	se_saver_plunger_drop_mvl, 127
	.equ	se_saver_plunger_drop_key, 0
	.equ	se_saver_plunger_drop_tbs, 1
	.equ	se_saver_plunger_drop_exg, 0
	.equ	se_saver_plunger_drop_cmp, 1

	.section .rodata
	.global	se_saver_plunger_drop
	.align	2

@*********************** Track 01 ***********************@

se_saver_plunger_drop_0:  @ 0x0869FB64
	.byte	KEYSH , se_saver_plunger_drop_key+0
	.byte	TEMPO , 150*se_saver_plunger_drop_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_saver_plunger_drop_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_saver_plunger_drop:  @ 0x0869FB7C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_saver_plunger_drop_pri	@ Priority
	.byte	se_saver_plunger_drop_rev	@ Reverb

	.word	se_saver_plunger_drop_grp

	.word	se_saver_plunger_drop_0
@ 0x0869FB88
