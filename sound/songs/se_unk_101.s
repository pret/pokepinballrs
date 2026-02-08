	.include "sound/MPlayDef.s"

	.equ	se_unk_101_grp, gUnknown_08531D4C
	.equ	se_unk_101_pri, 5
	.equ	se_unk_101_rev, reverb_set+50
	.equ	se_unk_101_mvl, 127
	.equ	se_unk_101_key, 0
	.equ	se_unk_101_tbs, 1
	.equ	se_unk_101_exg, 0
	.equ	se_unk_101_cmp, 1

	.section .rodata
	.global	se_unk_101
	.align	2

@*********************** Track 01 ***********************@

se_unk_101_0:  @ 0x086A1C74
	.byte	KEYSH , se_unk_101_key+0
	.byte	TEMPO , 240*se_unk_101_tbs/2
	.byte		VOICE , 122
	.byte		BENDR , 3
	.byte		VOL   , 95*se_unk_101_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , Cn4 , v127
	.byte	W24
	.byte		BEND  , c_v-64
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_101:  @ 0x086A1C88
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_101_pri	@ Priority
	.byte	se_unk_101_rev	@ Reverb

	.word	se_unk_101_grp

	.word	se_unk_101_0
@ 0x086A1C94
