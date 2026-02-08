	.include "sound/MPlayDef.s"

	.equ	se_unk_9e_grp, gUnknown_0853174C
	.equ	se_unk_9e_pri, 5
	.equ	se_unk_9e_rev, reverb_set+50
	.equ	se_unk_9e_mvl, 127
	.equ	se_unk_9e_key, 0
	.equ	se_unk_9e_tbs, 1
	.equ	se_unk_9e_exg, 0
	.equ	se_unk_9e_cmp, 1

	.section .rodata
	.global	se_unk_9e
	.align	2

@*********************** Track 01 ***********************@

se_unk_9e_0:  @ 0x0869FDFC
	.byte	KEYSH , se_unk_9e_key+0
	.byte	TEMPO , 128*se_unk_9e_tbs/2
	.byte		VOICE , 7
	.byte		BENDR , 12
	.byte		VOL   , 70*se_unk_9e_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N04   , Fn2 , v127
	.byte	W04
	.byte		N01   , Dn3 
	.byte	W02
	.byte		VOICE , 8
	.byte	FINE

@******************************************************@

	.align	2

se_unk_9e:  @ 0x0869FE14
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_9e_pri	@ Priority
	.byte	se_unk_9e_rev	@ Reverb

	.word	se_unk_9e_grp

	.word	se_unk_9e_0
@ 0x0869FE20
