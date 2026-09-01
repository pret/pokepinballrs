	.include "sound/MPlayDef.s"

	.equ	se_unused_0x88_grp, gVoiceGroup_SFX_08532310
	.equ	se_unused_0x88_pri, 5
	.equ	se_unused_0x88_rev, reverb_set+50
	.equ	se_unused_0x88_mvl, 127
	.equ	se_unused_0x88_key, 0
	.equ	se_unused_0x88_tbs, 1
	.equ	se_unused_0x88_exg, 0
	.equ	se_unused_0x88_cmp, 1

	.section .rodata
	.global	se_unused_0x88
	.align	2

@*********************** Track 01 ***********************@

se_unused_0x88_0:  @ 0x0869F670
	.byte	KEYSH , se_unused_0x88_key+0
	.byte	TEMPO , 150*se_unused_0x88_tbs/2
	.byte		VOL   , 100*se_unused_0x88_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 16
	.byte		N04   , As4 , v127
	.byte	W04
	.byte		N04   , Gn4 , v127
	.byte	W04
	.byte		N04   , En4 , v127
	.byte	W04
	.byte		N04   , Cs4 , v127
	.byte	W04
	.byte		N04   , As4 , v070
	.byte	W04
	.byte		N04   , Gn4 , v070
	.byte	W04
	.byte		N04   , En4 , v070
	.byte	W04
	.byte		N04   , Cs4 , v070
	.byte	W04
	.byte		N04   , As4 , v030
	.byte	W04
	.byte		N04   , Gn4 , v030
	.byte	W04
	.byte		N04   , En4 , v030
	.byte	W04
	.byte		N04   , Cs4 , v030
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0x88:  @ 0x0869F6AC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0x88_pri	@ Priority
	.byte	se_unused_0x88_rev	@ Reverb

	.word	se_unused_0x88_grp

	.word	se_unused_0x88_0
@ 0x0869F6B8
