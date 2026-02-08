	.include "sound/MPlayDef.s"

	.equ	se_unk_ba_grp, gUnknown_0853174C
	.equ	se_unk_ba_pri, 5
	.equ	se_unk_ba_rev, reverb_set+50
	.equ	se_unk_ba_mvl, 127
	.equ	se_unk_ba_key, 0
	.equ	se_unk_ba_tbs, 1
	.equ	se_unk_ba_exg, 0
	.equ	se_unk_ba_cmp, 1

	.section .rodata
	.global	se_unk_ba
	.align	2

@*********************** Track 01 ***********************@

se_unk_ba_0:  @ 0x086A0500
	.byte	KEYSH , se_unk_ba_key+0
	.byte	TEMPO , 220*se_unk_ba_tbs/2
	.byte		VOICE , 89
	.byte		VOL   , 80*se_unk_ba_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ba:  @ 0x086A0510
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ba_pri	@ Priority
	.byte	se_unk_ba_rev	@ Reverb

	.word	se_unk_ba_grp

	.word	se_unk_ba_0
@ 0x086A051C
