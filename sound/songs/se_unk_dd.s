	.include "sound/MPlayDef.s"

	.equ	se_unk_dd_grp, gUnknown_08532310
	.equ	se_unk_dd_pri, 5
	.equ	se_unk_dd_rev, reverb_set+50
	.equ	se_unk_dd_mvl, 127
	.equ	se_unk_dd_key, 0
	.equ	se_unk_dd_tbs, 1
	.equ	se_unk_dd_exg, 0
	.equ	se_unk_dd_cmp, 1

	.section .rodata
	.global	se_unk_dd
	.align	2

@*********************** Track 01 ***********************@

se_unk_dd_0:  @ 0x086A0FC8
	.byte	KEYSH , se_unk_dd_key+0
	.byte	TEMPO , 150*se_unk_dd_tbs/2
	.byte		VOL   , 100*se_unk_dd_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 30
	.byte		N48   , Cn1 , v127
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_unk_dd:  @ 0x086A0FD8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_dd_pri	@ Priority
	.byte	se_unk_dd_rev	@ Reverb

	.word	se_unk_dd_grp

	.word	se_unk_dd_0
@ 0x086A0FE4
