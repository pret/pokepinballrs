	.include "sound/MPlayDef.s"

	.equ	se_unk_e5_grp, gUnknown_08531D4C
	.equ	se_unk_e5_pri, 5
	.equ	se_unk_e5_rev, reverb_set+50
	.equ	se_unk_e5_mvl, 127
	.equ	se_unk_e5_key, 0
	.equ	se_unk_e5_tbs, 1
	.equ	se_unk_e5_exg, 0
	.equ	se_unk_e5_cmp, 1

	.section .rodata
	.global	se_unk_e5
	.align	2

@*********************** Track 01 ***********************@

se_unk_e5_0:  @ 0x086A11F4
	.byte	KEYSH , se_unk_e5_key+0
	.byte	TEMPO , 150*se_unk_e5_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_e5_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e5:  @ 0x086A120C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e5_pri	@ Priority
	.byte	se_unk_e5_rev	@ Reverb

	.word	se_unk_e5_grp

	.word	se_unk_e5_0
@ 0x086A1218
