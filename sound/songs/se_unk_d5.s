	.include "sound/MPlayDef.s"

	.equ	se_unk_d5_grp, gUnknown_08531D4C
	.equ	se_unk_d5_pri, 5
	.equ	se_unk_d5_rev, reverb_set+50
	.equ	se_unk_d5_mvl, 127
	.equ	se_unk_d5_key, 0
	.equ	se_unk_d5_tbs, 1
	.equ	se_unk_d5_exg, 0
	.equ	se_unk_d5_cmp, 1

	.section .rodata
	.global	se_unk_d5
	.align	2

@*********************** Track 01 ***********************@

se_unk_d5_0:  @ 0x086A0E20
	.byte	KEYSH , se_unk_d5_key+0
	.byte	TEMPO , 240*se_unk_d5_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_unk_d5_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Cn4 , v127
	.byte	W06
	.byte		VOICE , 23
	.byte		N02   , Cn3 , v112
	.byte	W07
	.byte		N01   , Cn4 
	.byte	W05
	.byte		        Cn3 , v100
	.byte	W02
	.byte		        Gn3 , v092
	.byte	W02
	.byte		        Cn3 , v072
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_d5:  @ 0x086A0E44
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_d5_pri	@ Priority
	.byte	se_unk_d5_rev	@ Reverb

	.word	se_unk_d5_grp

	.word	se_unk_d5_0
@ 0x086A0E50
