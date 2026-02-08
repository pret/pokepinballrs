	.include "sound/MPlayDef.s"

	.equ	se_unk_148_grp, gUnknown_0853174C
	.equ	se_unk_148_pri, 5
	.equ	se_unk_148_rev, reverb_set+50
	.equ	se_unk_148_mvl, 127
	.equ	se_unk_148_key, 0
	.equ	se_unk_148_tbs, 1
	.equ	se_unk_148_exg, 0
	.equ	se_unk_148_cmp, 1

	.section .rodata
	.global	se_unk_148
	.align	2

@*********************** Track 01 ***********************@

se_unk_148_0:  @ 0x086A320C
	.byte	KEYSH , se_unk_148_key+0
	.byte	TEMPO , 150*se_unk_148_tbs/2
	.byte		VOICE , 122
	.byte		VOL   , 100*se_unk_148_mvl/mxv
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		VOICE , 126
	.byte		N01   , Gs4 
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        Gs4 , v088
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_148:  @ 0x086A3224
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_148_pri	@ Priority
	.byte	se_unk_148_rev	@ Reverb

	.word	se_unk_148_grp

	.word	se_unk_148_0
@ 0x086A3230
