	.include "sound/MPlayDef.s"

	.equ	se_unk_9f_grp, gUnknown_0853174C
	.equ	se_unk_9f_pri, 5
	.equ	se_unk_9f_rev, reverb_set+50
	.equ	se_unk_9f_mvl, 127
	.equ	se_unk_9f_key, 0
	.equ	se_unk_9f_tbs, 1
	.equ	se_unk_9f_exg, 0
	.equ	se_unk_9f_cmp, 1

	.section .rodata
	.global	se_unk_9f
	.align	2

@*********************** Track 01 ***********************@

se_unk_9f_0:  @ 0x0869FE20
	.byte	KEYSH , se_unk_9f_key+0
	.byte	TEMPO , 110*se_unk_9f_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 90*se_unk_9f_mvl/mxv
	.byte		N06   , En4 , v127
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v088
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v064
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_9f:  @ 0x0869FE4C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_9f_pri	@ Priority
	.byte	se_unk_9f_rev	@ Reverb

	.word	se_unk_9f_grp

	.word	se_unk_9f_0
@ 0x0869FE58
