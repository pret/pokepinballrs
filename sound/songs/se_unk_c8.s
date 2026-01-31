	.include "sound/MPlayDef.s"

	.equ	se_unk_c8_grp, gUnknown_08531D4C
	.equ	se_unk_c8_pri, 5
	.equ	se_unk_c8_rev, reverb_set+50
	.equ	se_unk_c8_mvl, 127
	.equ	se_unk_c8_key, 0
	.equ	se_unk_c8_tbs, 1
	.equ	se_unk_c8_exg, 0
	.equ	se_unk_c8_cmp, 1

	.section .rodata
	.global	se_unk_c8
	.align	2

@*********************** Track 01 ***********************@

se_unk_c8_0:  @ 0x086A0890
	.byte	KEYSH , se_unk_c8_key+0
	.byte	TEMPO , 220*se_unk_c8_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_unk_c8_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , Gn2 , v127
	.byte	W06
	.byte		PAN   , c_v-17
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte	W03
	.byte		N06
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+13
	.byte	W05
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c8:  @ 0x086A08C0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c8_pri	@ Priority
	.byte	se_unk_c8_rev	@ Reverb

	.word	se_unk_c8_grp

	.word	se_unk_c8_0
@ 0x086A08CC
