	.include "sound/MPlayDef.s"

	.equ	se_unk_c5_grp, gUnknown_0853174C
	.equ	se_unk_c5_pri, 5
	.equ	se_unk_c5_rev, reverb_set+50
	.equ	se_unk_c5_mvl, 127
	.equ	se_unk_c5_key, 0
	.equ	se_unk_c5_tbs, 1
	.equ	se_unk_c5_exg, 0
	.equ	se_unk_c5_cmp, 1

	.section .rodata
	.global	se_unk_c5
	.align	2

@*********************** Track 01 ***********************@

se_unk_c5_0:  @ 0x086A07DC
	.byte	KEYSH , se_unk_c5_key+0
	.byte	TEMPO , 90*se_unk_c5_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 110*se_unk_c5_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Cn4 , v100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_c5_1:  @ 0x086A07EF
	.byte	KEYSH , se_unk_c5_key+0
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 82*se_unk_c5_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gs4 , v060
	.byte	W03
	.byte		VOL   , 94*se_unk_c5_mvl/mxv
	.byte	W03
	.byte		        103*se_unk_c5_mvl/mxv
	.byte		N22
	.byte	W03
	.byte		VOL   , 110*se_unk_c5_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 03 ***********************@

se_unk_c5_2:  @ 0x086A080A
	.byte	KEYSH , se_unk_c5_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_unk_c5_mvl/mxv
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

se_unk_c5:  @ 0x086A081C
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c5_pri	@ Priority
	.byte	se_unk_c5_rev	@ Reverb

	.word	se_unk_c5_grp

	.word	se_unk_c5_0
	.word	se_unk_c5_1
	.word	se_unk_c5_2
@ 0x086A0830
