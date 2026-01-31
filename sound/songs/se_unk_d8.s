	.include "sound/MPlayDef.s"

	.equ	se_unk_d8_grp, gUnknown_08531D4C
	.equ	se_unk_d8_pri, 5
	.equ	se_unk_d8_rev, reverb_set+50
	.equ	se_unk_d8_mvl, 127
	.equ	se_unk_d8_key, 0
	.equ	se_unk_d8_tbs, 1
	.equ	se_unk_d8_exg, 0
	.equ	se_unk_d8_cmp, 1

	.section .rodata
	.global	se_unk_d8
	.align	2

@*********************** Track 01 ***********************@

se_unk_d8_0:  @ 0x086A0F40
	.byte	KEYSH , se_unk_d8_key+0
	.byte	TEMPO , 150*se_unk_d8_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 94*se_unk_d8_mvl/mxv
	.byte		BENDR , 2
	.byte		LFOS  , 40
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , An5 , v112
	.byte	W01
	.byte		N15   , En6 , v104
	.byte	W02
	.byte	W01
	.byte		MOD   , 5
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        0
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_d8_1:  @ 0x086A0F63
	.byte	KEYSH , se_unk_d8_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_unk_d8_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , An4 , v108
	.byte	W01
	.byte		N12   , Cs6 , v104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_d8:  @ 0x086A0F80
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_d8_pri	@ Priority
	.byte	se_unk_d8_rev	@ Reverb

	.word	se_unk_d8_grp

	.word	se_unk_d8_0
	.word	se_unk_d8_1
@ 0x086A0F90
