	.include "sound/MPlayDef.s"

	.equ	se_unk_106_grp, gUnknown_0853174C
	.equ	se_unk_106_pri, 5
	.equ	se_unk_106_rev, reverb_set+50
	.equ	se_unk_106_mvl, 127
	.equ	se_unk_106_key, 0
	.equ	se_unk_106_tbs, 1
	.equ	se_unk_106_exg, 0
	.equ	se_unk_106_cmp, 1

	.section .rodata
	.global	se_unk_106
	.align	2

@*********************** Track 01 ***********************@

se_unk_106_0:  @ 0x086A1E14
	.byte	KEYSH , se_unk_106_key+0
	.byte	TEMPO , 132*se_unk_106_tbs/2
	.byte		VOICE , 91
	.byte		VOL   , 100*se_unk_106_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v112
	.byte	W04
	.byte		N02
	.byte	W04
	.byte		VOICE , 90
	.byte		N15
	.byte	W16
	.byte	FINE

@******************************************************@

	.align	2

se_unk_106:  @ 0x086A1E2C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_106_pri	@ Priority
	.byte	se_unk_106_rev	@ Reverb

	.word	se_unk_106_grp

	.word	se_unk_106_0
@ 0x086A1E38
