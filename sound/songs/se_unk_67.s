	.include "sound/MPlayDef.s"

	.equ	se_unk_67_grp, gUnknown_0853174C
	.equ	se_unk_67_pri, 5
	.equ	se_unk_67_rev, reverb_set+50
	.equ	se_unk_67_mvl, 127
	.equ	se_unk_67_key, 0
	.equ	se_unk_67_tbs, 1
	.equ	se_unk_67_exg, 0
	.equ	se_unk_67_cmp, 1

	.section .rodata
	.global	se_unk_67
	.align	2

@*********************** Track 01 ***********************@

se_unk_67_0:  @ 0x0869EF2C
	.byte	KEYSH , se_unk_67_key+0
	.byte	TEMPO , 300*se_unk_67_tbs/2
	.byte		VOICE , 87
	.byte		VOL   , 80*se_unk_67_mvl/mxv
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

se_unk_67:  @ 0x0869EF4C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_67_pri	@ Priority
	.byte	se_unk_67_rev	@ Reverb

	.word	se_unk_67_grp

	.word	se_unk_67_0
@ 0x0869EF58
