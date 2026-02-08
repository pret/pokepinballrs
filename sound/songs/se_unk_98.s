	.include "sound/MPlayDef.s"

	.equ	se_unk_98_grp, gUnknown_0853174C
	.equ	se_unk_98_pri, 5
	.equ	se_unk_98_rev, reverb_set+50
	.equ	se_unk_98_mvl, 127
	.equ	se_unk_98_key, 0
	.equ	se_unk_98_tbs, 1
	.equ	se_unk_98_exg, 0
	.equ	se_unk_98_cmp, 1

	.section .rodata
	.global	se_unk_98
	.align	2

@*********************** Track 01 ***********************@

se_unk_98_0:  @ 0x0869FBC4
	.byte	KEYSH , se_unk_98_key+0
	.byte	TEMPO , 220*se_unk_98_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_unk_98_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		N15   , Gn4 
	.byte	W21
	.byte	FINE

@******************************************************@

	.align	2

se_unk_98:  @ 0x0869FBD4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_98_pri	@ Priority
	.byte	se_unk_98_rev	@ Reverb

	.word	se_unk_98_grp

	.word	se_unk_98_0
@ 0x0869FBE0
