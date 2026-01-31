	.include "sound/MPlayDef.s"

	.equ	se_unk_ab_grp, gUnknown_08531D4C
	.equ	se_unk_ab_pri, 5
	.equ	se_unk_ab_rev, reverb_set+50
	.equ	se_unk_ab_mvl, 127
	.equ	se_unk_ab_key, 0
	.equ	se_unk_ab_tbs, 1
	.equ	se_unk_ab_exg, 0
	.equ	se_unk_ab_cmp, 1

	.section .rodata
	.global	se_unk_ab
	.align	2

@*********************** Track 01 ***********************@

se_unk_ab_0:  @ 0x086A013C
	.byte	KEYSH , se_unk_ab_key+0
	.byte	TEMPO , 150*se_unk_ab_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_unk_ab_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Fn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Fn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_ab_1:  @ 0x086A0150
	.byte	KEYSH , se_unk_ab_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_unk_ab_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Cn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ab:  @ 0x086A0164
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ab_pri	@ Priority
	.byte	se_unk_ab_rev	@ Reverb

	.word	se_unk_ab_grp

	.word	se_unk_ab_0
	.word	se_unk_ab_1
@ 0x086A0174
