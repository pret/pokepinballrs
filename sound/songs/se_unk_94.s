	.include "sound/MPlayDef.s"

	.equ	se_unk_94_grp, gUnknown_0853174C
	.equ	se_unk_94_pri, 5
	.equ	se_unk_94_rev, reverb_set+50
	.equ	se_unk_94_mvl, 127
	.equ	se_unk_94_key, 0
	.equ	se_unk_94_tbs, 1
	.equ	se_unk_94_exg, 0
	.equ	se_unk_94_cmp, 1

	.section .rodata
	.global	se_unk_94
	.align	2

@*********************** Track 01 ***********************@

se_unk_94_0:  @ 0x0869FAD0
	.byte	KEYSH , se_unk_94_key+0
	.byte	TEMPO , 90*se_unk_94_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 110*se_unk_94_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Cn4 , v100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_94_1:  @ 0x0869FAE3
	.byte	KEYSH , se_unk_94_key+0
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 82*se_unk_94_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gs4 , v060
	.byte	W03
	.byte		VOL   , 94*se_unk_94_mvl/mxv
	.byte	W03
	.byte		        103*se_unk_94_mvl/mxv
	.byte		N22
	.byte	W03
	.byte		VOL   , 110*se_unk_94_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 03 ***********************@

se_unk_94_2:  @ 0x0869FAFE
	.byte	KEYSH , se_unk_94_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_unk_94_mvl/mxv
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		N18   , Cn3 , v092
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_94:  @ 0x0869FB10
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_94_pri	@ Priority
	.byte	se_unk_94_rev	@ Reverb

	.word	se_unk_94_grp

	.word	se_unk_94_0
	.word	se_unk_94_1
	.word	se_unk_94_2
@ 0x0869FB24
