	.include "sound/MPlayDef.s"

	.equ	se_unk_ca_grp, gUnknown_08532310
	.equ	se_unk_ca_pri, 5
	.equ	se_unk_ca_rev, reverb_set+50
	.equ	se_unk_ca_mvl, 127
	.equ	se_unk_ca_key, 0
	.equ	se_unk_ca_tbs, 1
	.equ	se_unk_ca_exg, 0
	.equ	se_unk_ca_cmp, 1

	.section .rodata
	.global	se_unk_ca
	.align	2

@*********************** Track 01 ***********************@

se_unk_ca_0:  @ 0x086A0900
	.byte	KEYSH , se_unk_ca_key+0
	.byte	TEMPO , 150*se_unk_ca_tbs/2
	.byte		VOL   , 110*se_unk_ca_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ca:  @ 0x086A0910
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ca_pri	@ Priority
	.byte	se_unk_ca_rev	@ Reverb

	.word	se_unk_ca_grp

	.word	se_unk_ca_0
@ 0x086A091C
