	.include "sound/MPlayDef.s"

	.equ	se_unk_7e_grp, gUnknown_0853174C
	.equ	se_unk_7e_pri, 5
	.equ	se_unk_7e_rev, reverb_set+50
	.equ	se_unk_7e_mvl, 127
	.equ	se_unk_7e_key, 0
	.equ	se_unk_7e_tbs, 1
	.equ	se_unk_7e_exg, 0
	.equ	se_unk_7e_cmp, 1

	.section .rodata
	.global	se_unk_7e
	.align	2

@*********************** Track 01 ***********************@

se_unk_7e_0:  @ 0x0869F338
	.byte	KEYSH , se_unk_7e_key+0
	.byte	TEMPO , 300*se_unk_7e_tbs/2
	.byte		VOICE , 87
	.byte		VOL   , 80*se_unk_7e_mvl/mxv
	.byte		BEND  , c_v+13
	.byte		N03   , As5 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		VOICE , 88
	.byte		N06   , Gn6 , v068
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_7e:  @ 0x0869F358
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_7e_pri	@ Priority
	.byte	se_unk_7e_rev	@ Reverb

	.word	se_unk_7e_grp

	.word	se_unk_7e_0
@ 0x0869F364
