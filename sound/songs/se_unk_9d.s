	.include "sound/MPlayDef.s"

	.equ	se_unk_9d_grp, gUnknown_08531D4C
	.equ	se_unk_9d_pri, 5
	.equ	se_unk_9d_rev, reverb_set+50
	.equ	se_unk_9d_mvl, 127
	.equ	se_unk_9d_key, 0
	.equ	se_unk_9d_tbs, 1
	.equ	se_unk_9d_exg, 0
	.equ	se_unk_9d_cmp, 1

	.section .rodata
	.global	se_unk_9d
	.align	2

@*********************** Track 01 ***********************@

se_unk_9d_0:  @ 0x0869FDD0
	.byte	KEYSH , se_unk_9d_key+0
	.byte	TEMPO , 150*se_unk_9d_tbs/2
	.byte		VOICE , 16
	.byte		VOL   , 100*se_unk_9d_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Fn4 , v088
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_9d_1:  @ 0x0869FDDF
	.byte	KEYSH , se_unk_9d_key+0
	.byte		VOICE , 17
	.byte		VOL   , 100*se_unk_9d_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Fn4 , v072
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_9d:  @ 0x0869FDEC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_9d_pri	@ Priority
	.byte	se_unk_9d_rev	@ Reverb

	.word	se_unk_9d_grp

	.word	se_unk_9d_0
	.word	se_unk_9d_1
@ 0x0869FDFC
