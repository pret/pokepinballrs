	.include "sound/MPlayDef.s"

	.equ	se_unk_134_grp, gUnknown_08532310
	.equ	se_unk_134_pri, 5
	.equ	se_unk_134_rev, reverb_set+50
	.equ	se_unk_134_mvl, 127
	.equ	se_unk_134_key, 0
	.equ	se_unk_134_tbs, 1
	.equ	se_unk_134_exg, 0
	.equ	se_unk_134_cmp, 1

	.section .rodata
	.global	se_unk_134
	.align	2

@*********************** Track 01 ***********************@

se_unk_134_0:  @ 0x086A2C90
	.byte	KEYSH , se_unk_134_key+0
	.byte	TEMPO , 150*se_unk_134_tbs/2
	.byte		VOL   , 110*se_unk_134_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		TIE   , En3 , v127
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_134:  @ 0x086A2CA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_134_pri	@ Priority
	.byte	se_unk_134_rev	@ Reverb

	.word	se_unk_134_grp

	.word	se_unk_134_0
@ 0x086A2CAC
