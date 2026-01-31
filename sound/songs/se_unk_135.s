	.include "sound/MPlayDef.s"

	.equ	se_unk_135_grp, gUnknown_08532310
	.equ	se_unk_135_pri, 5
	.equ	se_unk_135_rev, reverb_set+50
	.equ	se_unk_135_mvl, 127
	.equ	se_unk_135_key, 0
	.equ	se_unk_135_tbs, 1
	.equ	se_unk_135_exg, 0
	.equ	se_unk_135_cmp, 1

	.section .rodata
	.global	se_unk_135
	.align	2

@*********************** Track 01 ***********************@

se_unk_135_0:  @ 0x086A2CAC
	.byte	KEYSH , se_unk_135_key+0
	.byte	TEMPO , 150*se_unk_135_tbs/2
	.byte		VOL   , 110*se_unk_135_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		TIE   , Cn3 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_135:  @ 0x086A2CBC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_135_pri	@ Priority
	.byte	se_unk_135_rev	@ Reverb

	.word	se_unk_135_grp

	.word	se_unk_135_0
@ 0x086A2CC8
