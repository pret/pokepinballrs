	.include "sound/MPlayDef.s"

	.equ	se_unk_e7_grp, gUnknown_08531D4C
	.equ	se_unk_e7_pri, 5
	.equ	se_unk_e7_rev, reverb_set+50
	.equ	se_unk_e7_mvl, 127
	.equ	se_unk_e7_key, 0
	.equ	se_unk_e7_tbs, 1
	.equ	se_unk_e7_exg, 0
	.equ	se_unk_e7_cmp, 1

	.section .rodata
	.global	se_unk_e7
	.align	2

@*********************** Track 01 ***********************@

se_unk_e7_0:  @ 0x086A124C
	.byte	KEYSH , se_unk_e7_key+0
	.byte	TEMPO , 150*se_unk_e7_tbs/2
	.byte		VOICE , 28
	.byte		VOL   , 100*se_unk_e7_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte		N03   , Gs3 , v080
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		N17   , Gs4 , v096
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v-8
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W05
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_e7_1:  @ 0x086A1273
	.byte	KEYSH , se_unk_e7_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*se_unk_e7_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , En4 , v060
	.byte	W04
	.byte		N17   , Gs4 , v096
	.byte	W20
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e7:  @ 0x086A1284
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e7_pri	@ Priority
	.byte	se_unk_e7_rev	@ Reverb

	.word	se_unk_e7_grp

	.word	se_unk_e7_0
	.word	se_unk_e7_1
@ 0x086A1294
