	.include "sound/MPlayDef.s"

	.equ	se_unk_9c_grp, gUnknown_08531D4C
	.equ	se_unk_9c_pri, 5
	.equ	se_unk_9c_rev, reverb_set+50
	.equ	se_unk_9c_mvl, 127
	.equ	se_unk_9c_key, 0
	.equ	se_unk_9c_tbs, 1
	.equ	se_unk_9c_exg, 0
	.equ	se_unk_9c_cmp, 1

	.section .rodata
	.global	se_unk_9c
	.align	2

@*********************** Track 01 ***********************@

se_unk_9c_0:  @ 0x0869FD88
	.byte	KEYSH , se_unk_9c_key+0
	.byte	TEMPO , 150*se_unk_9c_tbs/2
	.byte		VOICE , 14
	.byte		VOL   , 80*se_unk_9c_mvl/mxv
	.byte		BEND  , c_v+17
	.byte		N03   , En3 , v096
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N24   , Cn6 
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_9c_1:  @ 0x0869FDA6
	.byte	KEYSH , se_unk_9c_key+0
	.byte		VOICE , 17
	.byte		VOL   , 80*se_unk_9c_mvl/mxv
	.byte		N03   , En3 , v100
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N24   , Cn6 
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_9c:  @ 0x0869FDC0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_9c_pri	@ Priority
	.byte	se_unk_9c_rev	@ Reverb

	.word	se_unk_9c_grp

	.word	se_unk_9c_0
	.word	se_unk_9c_1
@ 0x0869FDD0
