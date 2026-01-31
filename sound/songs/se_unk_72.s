	.include "sound/MPlayDef.s"

	.equ	se_unk_72_grp, gUnknown_08532310
	.equ	se_unk_72_pri, 5
	.equ	se_unk_72_rev, reverb_set+50
	.equ	se_unk_72_mvl, 127
	.equ	se_unk_72_key, 0
	.equ	se_unk_72_tbs, 1
	.equ	se_unk_72_exg, 0
	.equ	se_unk_72_cmp, 1

	.section .rodata
	.global	se_unk_72
	.align	2

@*********************** Track 01 ***********************@

se_unk_72_0:  @ 0x0869F108
	.byte	KEYSH , se_unk_72_key+0
	.byte	TEMPO , 150*se_unk_72_tbs/2
	.byte		VOL   , 80*se_unk_72_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , En2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_72:  @ 0x0869F118
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_72_pri	@ Priority
	.byte	se_unk_72_rev	@ Reverb

	.word	se_unk_72_grp

	.word	se_unk_72_0
@ 0x0869F124
