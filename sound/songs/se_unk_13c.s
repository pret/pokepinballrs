	.include "sound/MPlayDef.s"

	.equ	se_unk_13c_grp, gUnknown_0853174C
	.equ	se_unk_13c_pri, 5
	.equ	se_unk_13c_rev, reverb_set+50
	.equ	se_unk_13c_mvl, 127
	.equ	se_unk_13c_key, 0
	.equ	se_unk_13c_tbs, 1
	.equ	se_unk_13c_exg, 0
	.equ	se_unk_13c_cmp, 1

	.section .rodata
	.global	se_unk_13c
	.align	2

@*********************** Track 01 ***********************@

se_unk_13c_0:  @ 0x086A2E9C
	.byte	KEYSH , se_unk_13c_key+0
	.byte	TEMPO , 220*se_unk_13c_tbs/2
	.byte		VOICE , 89
	.byte		VOL   , 80*se_unk_13c_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unk_13c:  @ 0x086A2EAC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_13c_pri	@ Priority
	.byte	se_unk_13c_rev	@ Reverb

	.word	se_unk_13c_grp

	.word	se_unk_13c_0
@ 0x086A2EB8
