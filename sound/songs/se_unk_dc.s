	.include "sound/MPlayDef.s"

	.equ	se_unk_dc_grp, gUnknown_08531D4C
	.equ	se_unk_dc_pri, 5
	.equ	se_unk_dc_rev, reverb_set+50
	.equ	se_unk_dc_mvl, 127
	.equ	se_unk_dc_key, 0
	.equ	se_unk_dc_tbs, 1
	.equ	se_unk_dc_exg, 0
	.equ	se_unk_dc_cmp, 1

	.section .rodata
	.global	se_unk_dc
	.align	2

@*********************** Track 01 ***********************@

se_unk_dc_0:  @ 0x086A0F90
	.byte	KEYSH , se_unk_dc_key+0
	.byte	TEMPO , 150*se_unk_dc_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_unk_dc_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn6 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Cn6 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_dc_1:  @ 0x086A0FA4
	.byte	KEYSH , se_unk_dc_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_unk_dc_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Gn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_dc:  @ 0x086A0FB8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_dc_pri	@ Priority
	.byte	se_unk_dc_rev	@ Reverb

	.word	se_unk_dc_grp

	.word	se_unk_dc_0
	.word	se_unk_dc_1
@ 0x086A0FC8
