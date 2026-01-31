	.include "sound/MPlayDef.s"

	.equ	se_unk_7c_grp, gUnknown_08531D4C
	.equ	se_unk_7c_pri, 5
	.equ	se_unk_7c_rev, reverb_set+50
	.equ	se_unk_7c_mvl, 127
	.equ	se_unk_7c_key, 0
	.equ	se_unk_7c_tbs, 1
	.equ	se_unk_7c_exg, 0
	.equ	se_unk_7c_cmp, 1

	.section .rodata
	.global	se_unk_7c
	.align	2

@*********************** Track 01 ***********************@

se_unk_7c_0:  @ 0x0869F2D4
	.byte	KEYSH , se_unk_7c_key+0
	.byte	TEMPO , 150*se_unk_7c_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 2
	.byte		VOL   , 100*se_unk_7c_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fs4 , v080
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte		EOT
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_7c_1:  @ 0x0869F2E9
	.byte	KEYSH , se_unk_7c_key+0
	.byte		VOICE , 27
	.byte		VOL   , 100*se_unk_7c_mvl/mxv
	.byte		TIE   , Fn3 , v032
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_7c:  @ 0x0869F2F8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_7c_pri	@ Priority
	.byte	se_unk_7c_rev	@ Reverb

	.word	se_unk_7c_grp

	.word	se_unk_7c_0
	.word	se_unk_7c_1
@ 0x0869F308
