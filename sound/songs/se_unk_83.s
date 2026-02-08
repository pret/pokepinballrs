	.include "sound/MPlayDef.s"

	.equ	se_unk_83_grp, gUnknown_0853174C
	.equ	se_unk_83_pri, 5
	.equ	se_unk_83_rev, reverb_set+50
	.equ	se_unk_83_mvl, 127
	.equ	se_unk_83_key, 0
	.equ	se_unk_83_tbs, 1
	.equ	se_unk_83_exg, 0
	.equ	se_unk_83_cmp, 1

	.section .rodata
	.global	se_unk_83
	.align	2

@*********************** Track 01 ***********************@

se_unk_83_0:  @ 0x0869F4C0
	.byte	KEYSH , se_unk_83_key+0
	.byte	TEMPO , 240*se_unk_83_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 80*se_unk_83_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gn5 , v127
	.byte	W06
	.byte		N18   , Ds5 
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_unk_83:  @ 0x0869F4D4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_83_pri	@ Priority
	.byte	se_unk_83_rev	@ Reverb

	.word	se_unk_83_grp

	.word	se_unk_83_0
@ 0x0869F4E0
