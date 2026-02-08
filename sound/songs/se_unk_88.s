	.include "sound/MPlayDef.s"

	.equ	se_unk_88_grp, gUnknown_08532310
	.equ	se_unk_88_pri, 5
	.equ	se_unk_88_rev, reverb_set+50
	.equ	se_unk_88_mvl, 127
	.equ	se_unk_88_key, 0
	.equ	se_unk_88_tbs, 1
	.equ	se_unk_88_exg, 0
	.equ	se_unk_88_cmp, 1

	.section .rodata
	.global	se_unk_88
	.align	2

@*********************** Track 01 ***********************@

se_unk_88_0:  @ 0x0869F670
	.byte	KEYSH , se_unk_88_key+0
	.byte	TEMPO , 150*se_unk_88_tbs/2
	.byte		VOL   , 100*se_unk_88_mvl/mxv
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

se_unk_88:  @ 0x0869F6AC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_88_pri	@ Priority
	.byte	se_unk_88_rev	@ Reverb

	.word	se_unk_88_grp

	.word	se_unk_88_0
@ 0x0869F6B8
