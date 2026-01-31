	.include "sound/MPlayDef.s"

	.equ	se_unk_e6_grp, gUnknown_08531D4C
	.equ	se_unk_e6_pri, 5
	.equ	se_unk_e6_rev, reverb_set+50
	.equ	se_unk_e6_mvl, 127
	.equ	se_unk_e6_key, 0
	.equ	se_unk_e6_tbs, 1
	.equ	se_unk_e6_exg, 0
	.equ	se_unk_e6_cmp, 1

	.section .rodata
	.global	se_unk_e6
	.align	2

@*********************** Track 01 ***********************@

se_unk_e6_0:  @ 0x086A1218
	.byte	KEYSH , se_unk_e6_key+0
	.byte	TEMPO , 150*se_unk_e6_tbs/2
	.byte		VOICE , 59
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_e6_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , En1 , v127
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v+14
	.byte	W01
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v+0
	.byte		N03   , An1 , v048
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		        c_v-16
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e6:  @ 0x086A1240
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e6_pri	@ Priority
	.byte	se_unk_e6_rev	@ Reverb

	.word	se_unk_e6_grp

	.word	se_unk_e6_0
@ 0x086A124C
