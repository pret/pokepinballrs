	.include "sound/MPlayDef.s"

	.equ	se_unk_aa_grp, gUnknown_08531D4C
	.equ	se_unk_aa_pri, 5
	.equ	se_unk_aa_rev, reverb_set+50
	.equ	se_unk_aa_mvl, 127
	.equ	se_unk_aa_key, 0
	.equ	se_unk_aa_tbs, 1
	.equ	se_unk_aa_exg, 0
	.equ	se_unk_aa_cmp, 1

	.section .rodata
	.global	se_unk_aa
	.align	2

@*********************** Track 01 ***********************@

se_unk_aa_0:  @ 0x086A0104
	.byte	KEYSH , se_unk_aa_key+0
	.byte	TEMPO , 150*se_unk_aa_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_unk_aa_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , En5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , En5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_aa_1:  @ 0x086A0118
	.byte	KEYSH , se_unk_aa_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_unk_aa_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Bn5 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Bn5 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_aa:  @ 0x086A012C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_aa_pri	@ Priority
	.byte	se_unk_aa_rev	@ Reverb

	.word	se_unk_aa_grp

	.word	se_unk_aa_0
	.word	se_unk_aa_1
@ 0x086A013C
