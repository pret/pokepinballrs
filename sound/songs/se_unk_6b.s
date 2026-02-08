	.include "sound/MPlayDef.s"

	.equ	se_unk_6b_grp, gUnknown_0853174C
	.equ	se_unk_6b_pri, 5
	.equ	se_unk_6b_rev, reverb_set+50
	.equ	se_unk_6b_mvl, 127
	.equ	se_unk_6b_key, 0
	.equ	se_unk_6b_tbs, 1
	.equ	se_unk_6b_exg, 0
	.equ	se_unk_6b_cmp, 1

	.section .rodata
	.global	se_unk_6b
	.align	2

@*********************** Track 01 ***********************@

se_unk_6b_0:  @ 0x0869EFAC
	.byte	KEYSH , se_unk_6b_key+0
	.byte	TEMPO , 100*se_unk_6b_tbs/2
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 40*se_unk_6b_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N01   , Gn4 , v127
	.byte	W01
	.byte		        Gn4 , v020
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_6b:  @ 0x0869EFC8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_6b_pri	@ Priority
	.byte	se_unk_6b_rev	@ Reverb

	.word	se_unk_6b_grp

	.word	se_unk_6b_0
@ 0x0869EFD4
