	.include "sound/MPlayDef.s"

	.equ	se_unused_0x89_grp, gVoiceGroup_SFX_08532310
	.equ	se_unused_0x89_pri, 5
	.equ	se_unused_0x89_rev, reverb_set+50
	.equ	se_unused_0x89_mvl, 127
	.equ	se_unused_0x89_key, 0
	.equ	se_unused_0x89_tbs, 1
	.equ	se_unused_0x89_exg, 0
	.equ	se_unused_0x89_cmp, 1

	.section .rodata
	.global	se_unused_0x89
	.align	2

@*********************** Track 01 ***********************@

se_unused_0x89_0:  @ 0x0869F6B8
	.byte	KEYSH , se_unused_0x89_key+0
	.byte	TEMPO , 150*se_unused_0x89_tbs/2
	.byte		VOL   , 80*se_unused_0x89_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 21
	.byte		N02   , As5 , v127
	.byte	W03
	.byte		N02   , As5 , v127
	.byte	W03
	.byte		N12   , Fn6 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0x89:  @ 0x0869F6D0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0x89_pri	@ Priority
	.byte	se_unused_0x89_rev	@ Reverb

	.word	se_unused_0x89_grp

	.word	se_unused_0x89_0
@ 0x0869F6DC
