	.include "sound/MPlayDef.s"

	.equ	se_unused_0x6c_grp, gUnknown_0853174C
	.equ	se_unused_0x6c_pri, 5
	.equ	se_unused_0x6c_rev, reverb_set+50
	.equ	se_unused_0x6c_mvl, 127
	.equ	se_unused_0x6c_key, 0
	.equ	se_unused_0x6c_tbs, 1
	.equ	se_unused_0x6c_exg, 0
	.equ	se_unused_0x6c_cmp, 1

	.section .rodata
	.global	se_unused_0x6c
	.align	2

@*********************** Track 01 ***********************@

se_unused_0x6c_0:  @ 0x0869EFD4
	.byte	KEYSH , se_unused_0x6c_key+0
	.byte	TEMPO , 180*se_unused_0x6c_tbs/2
	.byte		VOICE , 85
	.byte		VOL   , 90*se_unused_0x6c_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v080
	.byte	W02
	.byte		VOICE , 86
	.byte		N03   , Cn4 , v127
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0x6c:  @ 0x0869EFEC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0x6c_pri	@ Priority
	.byte	se_unused_0x6c_rev	@ Reverb

	.word	se_unused_0x6c_grp

	.word	se_unused_0x6c_0
@ 0x0869EFF8
