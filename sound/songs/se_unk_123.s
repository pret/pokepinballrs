	.include "sound/MPlayDef.s"

	.equ	se_unk_123_grp, gUnknown_0853174C
	.equ	se_unk_123_pri, 5
	.equ	se_unk_123_rev, reverb_set+50
	.equ	se_unk_123_mvl, 127
	.equ	se_unk_123_key, 0
	.equ	se_unk_123_tbs, 1
	.equ	se_unk_123_exg, 0
	.equ	se_unk_123_cmp, 1

	.section .rodata
	.global	se_unk_123
	.align	2

@*********************** Track 01 ***********************@

se_unk_123_0:  @ 0x086A27F0
	.byte	KEYSH , se_unk_123_key+0
	.byte	TEMPO , 90*se_unk_123_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_unk_123_mvl/mxv
	.byte		N03   , Gn2 , v100
	.byte	W03
	.byte		N06   , As2 
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_123_1:  @ 0x086A2801
	.byte	KEYSH , se_unk_123_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_unk_123_mvl/mxv
	.byte		N09   , As1 , v127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_123:  @ 0x086A2810
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_123_pri	@ Priority
	.byte	se_unk_123_rev	@ Reverb

	.word	se_unk_123_grp

	.word	se_unk_123_0
	.word	se_unk_123_1
@ 0x086A2820
