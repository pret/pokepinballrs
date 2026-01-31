	.include "sound/MPlayDef.s"

	.equ	se_unk_10d_grp, gUnknown_08532310
	.equ	se_unk_10d_pri, 5
	.equ	se_unk_10d_rev, reverb_set+50
	.equ	se_unk_10d_mvl, 127
	.equ	se_unk_10d_key, 0
	.equ	se_unk_10d_tbs, 1
	.equ	se_unk_10d_exg, 0
	.equ	se_unk_10d_cmp, 1

	.section .rodata
	.global	se_unk_10d
	.align	2

@*********************** Track 01 ***********************@

se_unk_10d_0:  @ 0x086A1FD4
	.byte	KEYSH , se_unk_10d_key+0
	.byte	TEMPO , 150*se_unk_10d_tbs/2
	.byte		VOL   , 110*se_unk_10d_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 5
	.byte		N48   , En3 , v127
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_unk_10d:  @ 0x086A1FE4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_10d_pri	@ Priority
	.byte	se_unk_10d_rev	@ Reverb

	.word	se_unk_10d_grp

	.word	se_unk_10d_0
@ 0x086A1FF0
