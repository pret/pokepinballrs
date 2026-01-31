	.include "sound/MPlayDef.s"

	.equ	se_unk_a7_grp, gUnknown_0853174C
	.equ	se_unk_a7_pri, 5
	.equ	se_unk_a7_rev, reverb_set+50
	.equ	se_unk_a7_mvl, 127
	.equ	se_unk_a7_key, 0
	.equ	se_unk_a7_tbs, 1
	.equ	se_unk_a7_exg, 0
	.equ	se_unk_a7_cmp, 1

	.section .rodata
	.global	se_unk_a7
	.align	2

@*********************** Track 01 ***********************@

se_unk_a7_0:  @ 0x086A003C
	.byte	KEYSH , se_unk_a7_key+0
	.byte	TEMPO , 90*se_unk_a7_tbs/2
	.byte		VOICE , 86
	.byte		VOL   , 100*se_unk_a7_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Gn1 , v100
	.byte	W03
	.byte		N05   , Fn2 
	.byte	W03
	.byte	W03
	.byte		N06   , Fn2 , v052
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_a7_1:  @ 0x086A0054
	.byte	KEYSH , se_unk_a7_key+0
	.byte		VOICE , 0
	.byte		VOL   , 100*se_unk_a7_mvl/mxv
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v052
	.byte	W03
	.byte		        Cn2 , v112
	.byte	W03
	.byte	W03
	.byte		        Cn1 , v092
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 03 ***********************@

se_unk_a7_2:  @ 0x086A006B
	.byte	KEYSH , se_unk_a7_key+0
	.byte		VOICE , 124
	.byte		VOL   , 100*se_unk_a7_mvl/mxv
	.byte		N03   , Gn3 , v052
	.byte	W03
	.byte		N06   , Gs4 
	.byte	W03
	.byte	W03
	.byte		        Gs4 , v020
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_a7:  @ 0x086A0080
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_a7_pri	@ Priority
	.byte	se_unk_a7_rev	@ Reverb

	.word	se_unk_a7_grp

	.word	se_unk_a7_0
	.word	se_unk_a7_1
	.word	se_unk_a7_2
@ 0x086A0094
