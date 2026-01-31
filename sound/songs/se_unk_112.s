	.include "sound/MPlayDef.s"

	.equ	se_unk_112_grp, gUnknown_08532310
	.equ	se_unk_112_pri, 5
	.equ	se_unk_112_rev, reverb_set+50
	.equ	se_unk_112_mvl, 127
	.equ	se_unk_112_key, 0
	.equ	se_unk_112_tbs, 1
	.equ	se_unk_112_exg, 0
	.equ	se_unk_112_cmp, 1

	.section .rodata
	.global	se_unk_112
	.align	2

@*********************** Track 01 ***********************@

se_unk_112_0:  @ 0x086A217C
	.byte	KEYSH , se_unk_112_key+0
	.byte	TEMPO , 150*se_unk_112_tbs/2
	.byte		VOL   , 100*se_unk_112_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 30
	.byte		N48   , Cn3 , v127
	.byte	W48
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_112_1:  @ 0x086A218B
	.byte	KEYSH , se_unk_112_key+0
	.byte	TEMPO , 150*se_unk_112_tbs/2
	.byte		VOL   , 100*se_unk_112_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 19
	.byte		N06   , Cn7 , v100
	.byte	W06
	.byte		N48   , Cs7 , v100
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_unk_112:  @ 0x086A21A0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_112_pri	@ Priority
	.byte	se_unk_112_rev	@ Reverb

	.word	se_unk_112_grp

	.word	se_unk_112_0
	.word	se_unk_112_1
@ 0x086A21B0
