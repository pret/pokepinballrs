	.include "sound/MPlayDef.s"

	.equ	se_unk_e2_grp, gUnknown_08531D4C
	.equ	se_unk_e2_pri, 5
	.equ	se_unk_e2_rev, reverb_set+50
	.equ	se_unk_e2_mvl, 127
	.equ	se_unk_e2_key, 0
	.equ	se_unk_e2_tbs, 1
	.equ	se_unk_e2_exg, 0
	.equ	se_unk_e2_cmp, 1

	.section .rodata
	.global	se_unk_e2
	.align	2

@*********************** Track 01 ***********************@

se_unk_e2_0:  @ 0x086A10EC
	.byte	KEYSH , se_unk_e2_key+0
	.byte	TEMPO , 150*se_unk_e2_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 100*se_unk_e2_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N02   , Dn3 , v127
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+6
	.byte		N02   , Dn3 , v084
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W02
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v+32
	.byte		N02   , Dn3 , v056
	.byte	W16
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e2:  @ 0x086A1118
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e2_pri	@ Priority
	.byte	se_unk_e2_rev	@ Reverb

	.word	se_unk_e2_grp

	.word	se_unk_e2_0
@ 0x086A1124
