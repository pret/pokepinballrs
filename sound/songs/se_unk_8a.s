	.include "sound/MPlayDef.s"

	.equ	se_unk_8a_grp, gUnknown_0853174C
	.equ	se_unk_8a_pri, 5
	.equ	se_unk_8a_rev, reverb_set+50
	.equ	se_unk_8a_mvl, 127
	.equ	se_unk_8a_key, 0
	.equ	se_unk_8a_tbs, 1
	.equ	se_unk_8a_exg, 0
	.equ	se_unk_8a_cmp, 1

	.section .rodata
	.global	se_unk_8a
	.align	2

@*********************** Track 01 ***********************@

se_unk_8a_0:  @ 0x0869F6DC
	.byte	KEYSH , se_unk_8a_key+0
	.byte	TEMPO , 240*se_unk_8a_tbs/2
	.byte		VOICE , 92
	.byte		BENDR , 12
	.byte		VOL   , 120*se_unk_8a_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn2 , v127
	.byte	W03
	.byte		        Cn2 , v020
	.byte	W03
	.byte		N18   , Cn2 , v127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N09   , Cn2 , v020
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_8a:  @ 0x0869F700
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_8a_pri	@ Priority
	.byte	se_unk_8a_rev	@ Reverb

	.word	se_unk_8a_grp

	.word	se_unk_8a_0
@ 0x0869F70C
