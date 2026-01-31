	.include "sound/MPlayDef.s"

	.equ	se_unk_b9_grp, gUnknown_08532310
	.equ	se_unk_b9_pri, 5
	.equ	se_unk_b9_rev, reverb_set+50
	.equ	se_unk_b9_mvl, 127
	.equ	se_unk_b9_key, 0
	.equ	se_unk_b9_tbs, 1
	.equ	se_unk_b9_exg, 0
	.equ	se_unk_b9_cmp, 1

	.section .rodata
	.global	se_unk_b9
	.align	2

@*********************** Track 01 ***********************@

se_unk_b9_0:  @ 0x086A04E0
	.byte	KEYSH , se_unk_b9_key+0
	.byte	TEMPO , 132*se_unk_b9_tbs/2
	.byte		VOICE , 20
	.byte		VOL   , 100*se_unk_b9_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v112
	.byte	W03
	.byte		N02
	.byte	W03
	.byte		N08
	.byte	W08
	.byte	FINE

@******************************************************@

	.align	2

se_unk_b9:  @ 0x086A04F4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b9_pri	@ Priority
	.byte	se_unk_b9_rev	@ Reverb

	.word	se_unk_b9_grp

	.word	se_unk_b9_0
@ 0x086A0500
