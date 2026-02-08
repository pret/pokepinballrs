	.include "sound/MPlayDef.s"

	.equ	se_unk_b4_grp, gUnknown_0853174C
	.equ	se_unk_b4_pri, 5
	.equ	se_unk_b4_rev, reverb_set+50
	.equ	se_unk_b4_mvl, 127
	.equ	se_unk_b4_key, 0
	.equ	se_unk_b4_tbs, 1
	.equ	se_unk_b4_exg, 0
	.equ	se_unk_b4_cmp, 1

	.section .rodata
	.global	se_unk_b4
	.align	2

@*********************** Track 01 ***********************@

se_unk_b4_0:  @ 0x086A0374
	.byte	KEYSH , se_unk_b4_key+0
	.byte	TEMPO , 110*se_unk_b4_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 90*se_unk_b4_mvl/mxv
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

se_unk_b4:  @ 0x086A03A0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b4_pri	@ Priority
	.byte	se_unk_b4_rev	@ Reverb

	.word	se_unk_b4_grp

	.word	se_unk_b4_0
@ 0x086A03AC
