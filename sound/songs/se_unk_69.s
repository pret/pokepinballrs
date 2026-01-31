	.include "sound/MPlayDef.s"

	.equ	se_unk_69_grp, gUnknown_08532310
	.equ	se_unk_69_pri, 5
	.equ	se_unk_69_rev, reverb_set+50
	.equ	se_unk_69_mvl, 127
	.equ	se_unk_69_key, 0
	.equ	se_unk_69_tbs, 1
	.equ	se_unk_69_exg, 0
	.equ	se_unk_69_cmp, 1

	.section .rodata
	.global	se_unk_69
	.align	2

@*********************** Track 01 ***********************@

se_unk_69_0:  @ 0x0869EF74
	.byte	KEYSH , se_unk_69_key+0
	.byte	TEMPO , 150*se_unk_69_tbs/2
	.byte		VOL   , 100*se_unk_69_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 14
	.byte		N12   , An3 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_69:  @ 0x0869EF84
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_69_pri	@ Priority
	.byte	se_unk_69_rev	@ Reverb

	.word	se_unk_69_grp

	.word	se_unk_69_0
@ 0x0869EF90
