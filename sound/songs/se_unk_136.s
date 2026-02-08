	.include "sound/MPlayDef.s"

	.equ	se_unk_136_grp, gUnknown_08532310
	.equ	se_unk_136_pri, 5
	.equ	se_unk_136_rev, reverb_set+50
	.equ	se_unk_136_mvl, 127
	.equ	se_unk_136_key, 0
	.equ	se_unk_136_tbs, 1
	.equ	se_unk_136_exg, 0
	.equ	se_unk_136_cmp, 1

	.section .rodata
	.global	se_unk_136
	.align	2

@*********************** Track 01 ***********************@

se_unk_136_0:  @ 0x086A2CC8
	.byte	KEYSH , se_unk_136_key+0
	.byte	TEMPO , 150*se_unk_136_tbs/2
	.byte		VOL   , 110*se_unk_136_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		N08   , Dn3 , v127
	.byte	W08
	.byte		TIE   , An2 , v127
	.byte	W36
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_136:  @ 0x086A2CDC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_136_pri	@ Priority
	.byte	se_unk_136_rev	@ Reverb

	.word	se_unk_136_grp

	.word	se_unk_136_0
@ 0x086A2CE8
