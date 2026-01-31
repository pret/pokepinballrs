	.include "sound/MPlayDef.s"

	.equ	se_unk_79_grp, gUnknown_08531D4C
	.equ	se_unk_79_pri, 5
	.equ	se_unk_79_rev, reverb_set+50
	.equ	se_unk_79_mvl, 127
	.equ	se_unk_79_key, 0
	.equ	se_unk_79_tbs, 1
	.equ	se_unk_79_exg, 0
	.equ	se_unk_79_cmp, 1

	.section .rodata
	.global	se_unk_79
	.align	2

@*********************** Track 01 ***********************@

se_unk_79_0:  @ 0x0869F228
	.byte	KEYSH , se_unk_79_key+0
	.byte	TEMPO , 150*se_unk_79_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 95*se_unk_79_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W03
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_79:  @ 0x0869F240
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_79_pri	@ Priority
	.byte	se_unk_79_rev	@ Reverb

	.word	se_unk_79_grp

	.word	se_unk_79_0
@ 0x0869F24C
