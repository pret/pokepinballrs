	.include "sound/MPlayDef.s"

	.equ	se_unk_11e_grp, gUnknown_08531D4C
	.equ	se_unk_11e_pri, 5
	.equ	se_unk_11e_rev, reverb_set+50
	.equ	se_unk_11e_mvl, 127
	.equ	se_unk_11e_key, 0
	.equ	se_unk_11e_tbs, 1
	.equ	se_unk_11e_exg, 0
	.equ	se_unk_11e_cmp, 1

	.section .rodata
	.global	se_unk_11e
	.align	2

@*********************** Track 01 ***********************@

se_unk_11e_0:  @ 0x086A2554
	.byte	KEYSH , se_unk_11e_key+0
	.byte	TEMPO , 190*se_unk_11e_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 28*se_unk_11e_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N15   , An1 , v127
	.byte	W01
	.byte		VOL   , 60*se_unk_11e_mvl/mxv
	.byte	W01
	.byte		        111*se_unk_11e_mvl/mxv
	.byte	W01
	.byte		        120*se_unk_11e_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 109*se_unk_11e_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-10
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-14
	.byte	W01
	.byte		VOL   , 95*se_unk_11e_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		VOL   , 71*se_unk_11e_mvl/mxv
	.byte		BEND  , c_v-29
	.byte	W01
	.byte		VOL   , 41*se_unk_11e_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		VOL   , 15*se_unk_11e_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unk_11e:  @ 0x086A25A0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_11e_pri	@ Priority
	.byte	se_unk_11e_rev	@ Reverb

	.word	se_unk_11e_grp

	.word	se_unk_11e_0
@ 0x086A25AC
