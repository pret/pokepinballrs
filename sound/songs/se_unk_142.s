	.include "sound/MPlayDef.s"

	.equ	se_unk_142_grp, gUnknown_08532310
	.equ	se_unk_142_pri, 5
	.equ	se_unk_142_rev, reverb_set+50
	.equ	se_unk_142_mvl, 127
	.equ	se_unk_142_key, 0
	.equ	se_unk_142_tbs, 1
	.equ	se_unk_142_exg, 0
	.equ	se_unk_142_cmp, 1

	.section .rodata
	.global	se_unk_142
	.align	2

@*********************** Track 01 ***********************@

se_unk_142_0:  @ 0x086A2F90
	.byte	KEYSH , se_unk_142_key+0
	.byte	TEMPO , 150*se_unk_142_tbs/2
	.byte		VOL   , 127*se_unk_142_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 102
	.byte		TIE   , Cn3 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_142:  @ 0x086A2FA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_142_pri	@ Priority
	.byte	se_unk_142_rev	@ Reverb

	.word	se_unk_142_grp

	.word	se_unk_142_0
@ 0x086A2FAC
