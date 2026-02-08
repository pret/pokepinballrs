	.include "sound/MPlayDef.s"

	.equ	se_unk_85_grp, gUnknown_0853174C
	.equ	se_unk_85_pri, 5
	.equ	se_unk_85_rev, reverb_set+50
	.equ	se_unk_85_mvl, 127
	.equ	se_unk_85_key, 0
	.equ	se_unk_85_tbs, 1
	.equ	se_unk_85_exg, 0
	.equ	se_unk_85_cmp, 1

	.section .rodata
	.global	se_unk_85
	.align	2

@*********************** Track 01 ***********************@

se_unk_85_0:  @ 0x0869F59C
	.byte	KEYSH , se_unk_85_key+0
	.byte	TEMPO , 128*se_unk_85_tbs/2
	.byte		VOICE , 6
	.byte		BENDR , 12
	.byte		VOL   , 90*se_unk_85_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N01   , Ds3 , v127
	.byte	W02
	.byte		N03   , Gs3 , v100
	.byte	W05
	.byte		N16   , Fn5 , v072
	.byte	W05
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_85_1:  @ 0x0869F5B6
	.byte	KEYSH , se_unk_85_key+0
	.byte		VOICE , 14
	.byte		VOL   , 90*se_unk_85_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		N03   , Gs3 , v060
	.byte	W05
	.byte		N16   , Fn5 
	.byte	W05
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_85:  @ 0x0869F5C8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_85_pri	@ Priority
	.byte	se_unk_85_rev	@ Reverb

	.word	se_unk_85_grp

	.word	se_unk_85_0
	.word	se_unk_85_1
@ 0x0869F5D8
