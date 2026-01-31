	.include "sound/MPlayDef.s"

	.equ	se_unk_b3_grp, gUnknown_08532310
	.equ	se_unk_b3_pri, 5
	.equ	se_unk_b3_rev, reverb_set+50
	.equ	se_unk_b3_mvl, 127
	.equ	se_unk_b3_key, 0
	.equ	se_unk_b3_tbs, 1
	.equ	se_unk_b3_exg, 0
	.equ	se_unk_b3_cmp, 1

	.section .rodata
	.global	se_unk_b3
	.align	2

@*********************** Track 01 ***********************@

se_unk_b3_0:  @ 0x086A0354
	.byte	KEYSH , se_unk_b3_key+0
	.byte	TEMPO , 150*se_unk_b3_tbs/2
	.byte		VOL   , 127*se_unk_b3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 105
	.byte		TIE   , Cn3 , v127
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_b3:  @ 0x086A0368
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b3_pri	@ Priority
	.byte	se_unk_b3_rev	@ Reverb

	.word	se_unk_b3_grp

	.word	se_unk_b3_0
@ 0x086A0374
