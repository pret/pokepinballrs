	.include "sound/MPlayDef.s"

	.equ	se_unk_f6_grp, gUnknown_0853174C
	.equ	se_unk_f6_pri, 5
	.equ	se_unk_f6_rev, reverb_set+50
	.equ	se_unk_f6_mvl, 127
	.equ	se_unk_f6_key, 0
	.equ	se_unk_f6_tbs, 1
	.equ	se_unk_f6_exg, 0
	.equ	se_unk_f6_cmp, 1

	.section .rodata
	.global	se_unk_f6
	.align	2

@*********************** Track 01 ***********************@

se_unk_f6_0:  @ 0x086A17E4
	.byte	KEYSH , se_unk_f6_key+0
	.byte	TEMPO , 90*se_unk_f6_tbs/2
	.byte		VOICE , 125
	.byte		VOL   , 110*se_unk_f6_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , As2 , v100
	.byte	W03
	.byte		BEND  , c_v-33
	.byte		N36   , Ds3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_f6_1:  @ 0x086A1806
	.byte	KEYSH , se_unk_f6_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_unk_f6_mvl/mxv
	.byte		N03   , Cn3 , v127
	.byte	W03
	.byte		N18
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_f6:  @ 0x086A1820
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_f6_pri	@ Priority
	.byte	se_unk_f6_rev	@ Reverb

	.word	se_unk_f6_grp

	.word	se_unk_f6_0
	.word	se_unk_f6_1
@ 0x086A1830
