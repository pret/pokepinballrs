	.include "sound/MPlayDef.s"

	.equ	se_unk_6d_grp, gUnknown_08532310
	.equ	se_unk_6d_pri, 5
	.equ	se_unk_6d_rev, reverb_set+50
	.equ	se_unk_6d_mvl, 127
	.equ	se_unk_6d_key, 0
	.equ	se_unk_6d_tbs, 1
	.equ	se_unk_6d_exg, 0
	.equ	se_unk_6d_cmp, 1

	.section .rodata
	.global	se_unk_6d
	.align	2

@*********************** Track 01 ***********************@

se_unk_6d_0:  @ 0x0869EFF8
	.byte	KEYSH , se_unk_6d_key+0
	.byte	TEMPO , 150*se_unk_6d_tbs/2
	.byte		VOICE , 4
	.byte		VOL   , 100*se_unk_6d_mvl/mxv
	.byte		N04   , Fs4 , v127
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_6d:  @ 0x0869F008
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_6d_pri	@ Priority
	.byte	se_unk_6d_rev	@ Reverb

	.word	se_unk_6d_grp

	.word	se_unk_6d_0
@ 0x0869F014
