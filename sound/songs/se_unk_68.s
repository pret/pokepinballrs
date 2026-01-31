	.include "sound/MPlayDef.s"

	.equ	se_unk_68_grp, gUnknown_08532310
	.equ	se_unk_68_pri, 5
	.equ	se_unk_68_rev, reverb_set+50
	.equ	se_unk_68_mvl, 127
	.equ	se_unk_68_key, 0
	.equ	se_unk_68_tbs, 1
	.equ	se_unk_68_exg, 0
	.equ	se_unk_68_cmp, 1

	.section .rodata
	.global	se_unk_68
	.align	2

@*********************** Track 01 ***********************@

se_unk_68_0:  @ 0x0869EF58
	.byte	KEYSH , se_unk_68_key+0
	.byte	TEMPO , 150*se_unk_68_tbs/2
	.byte		VOL   , 100*se_unk_68_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 13
	.byte		N12   , An2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_68:  @ 0x0869EF68
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_68_pri	@ Priority
	.byte	se_unk_68_rev	@ Reverb

	.word	se_unk_68_grp

	.word	se_unk_68_0
@ 0x0869EF74
