	.include "sound/MPlayDef.s"

	.equ	se_unk_a0_grp, gUnknown_0853174C
	.equ	se_unk_a0_pri, 5
	.equ	se_unk_a0_rev, reverb_set+50
	.equ	se_unk_a0_mvl, 127
	.equ	se_unk_a0_key, 0
	.equ	se_unk_a0_tbs, 1
	.equ	se_unk_a0_exg, 0
	.equ	se_unk_a0_cmp, 1

	.section .rodata
	.global	se_unk_a0
	.align	2

@*********************** Track 01 ***********************@

se_unk_a0_0:  @ 0x0869FE58
	.byte	KEYSH , se_unk_a0_key+0
	.byte	TEMPO , 110*se_unk_a0_tbs/2
	.byte		VOICE , 93
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		VOL   , 90*se_unk_a0_mvl/mxv
	.byte		N06   , En5 , v064
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v088
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte		N06   , En5 , v127
	.byte	W03
	.byte	W03
	.byte		N03   , En5 , v016
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_a0:  @ 0x0869FE8C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_a0_pri	@ Priority
	.byte	se_unk_a0_rev	@ Reverb

	.word	se_unk_a0_grp

	.word	se_unk_a0_0
@ 0x0869FE98
