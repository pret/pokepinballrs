	.include "sound/MPlayDef.s"

	.equ	se_unk_75_grp, gUnknown_08532310
	.equ	se_unk_75_pri, 5
	.equ	se_unk_75_rev, reverb_set+50
	.equ	se_unk_75_mvl, 127
	.equ	se_unk_75_key, 0
	.equ	se_unk_75_tbs, 1
	.equ	se_unk_75_exg, 0
	.equ	se_unk_75_cmp, 1

	.section .rodata
	.global	se_unk_75
	.align	2

@*********************** Track 01 ***********************@

se_unk_75_0:  @ 0x0869F18C
	.byte	KEYSH , se_unk_75_key+0
	.byte	TEMPO , 150*se_unk_75_tbs/2
	.byte		VOL   , 90*se_unk_75_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 23
	.byte		N02   , Fn6 , v127
	.byte	W02
	.byte		N02   , Fn7 , v127
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_75:  @ 0x0869F1A0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_75_pri	@ Priority
	.byte	se_unk_75_rev	@ Reverb

	.word	se_unk_75_grp

	.word	se_unk_75_0
@ 0x0869F1AC
