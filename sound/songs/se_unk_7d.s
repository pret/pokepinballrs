	.include "sound/MPlayDef.s"

	.equ	se_unk_7d_grp, gUnknown_08531D4C
	.equ	se_unk_7d_pri, 5
	.equ	se_unk_7d_rev, reverb_set+50
	.equ	se_unk_7d_mvl, 127
	.equ	se_unk_7d_key, 0
	.equ	se_unk_7d_tbs, 1
	.equ	se_unk_7d_exg, 0
	.equ	se_unk_7d_cmp, 1

	.section .rodata
	.global	se_unk_7d
	.align	2

@*********************** Track 01 ***********************@

se_unk_7d_0:  @ 0x0869F308
	.byte	KEYSH , se_unk_7d_key+0
	.byte	TEMPO , 240*se_unk_7d_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_unk_7d_mvl/mxv
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

se_unk_7d:  @ 0x0869F32C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_7d_pri	@ Priority
	.byte	se_unk_7d_rev	@ Reverb

	.word	se_unk_7d_grp

	.word	se_unk_7d_0
@ 0x0869F338
