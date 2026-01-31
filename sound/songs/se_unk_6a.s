	.include "sound/MPlayDef.s"

	.equ	se_unk_6a_grp, gUnknown_08532310
	.equ	se_unk_6a_pri, 5
	.equ	se_unk_6a_rev, reverb_set+50
	.equ	se_unk_6a_mvl, 127
	.equ	se_unk_6a_key, 0
	.equ	se_unk_6a_tbs, 1
	.equ	se_unk_6a_exg, 0
	.equ	se_unk_6a_cmp, 1

	.section .rodata
	.global	se_unk_6a
	.align	2

@*********************** Track 01 ***********************@

se_unk_6a_0:  @ 0x0869EF90
	.byte	KEYSH , se_unk_6a_key+0
	.byte	TEMPO , 150*se_unk_6a_tbs/2
	.byte		VOL   , 100*se_unk_6a_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn5 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_6a:  @ 0x0869EFA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_6a_pri	@ Priority
	.byte	se_unk_6a_rev	@ Reverb

	.word	se_unk_6a_grp

	.word	se_unk_6a_0
@ 0x0869EFAC
