	.include "sound/MPlayDef.s"

	.equ	se_unk_ff_grp, gUnknown_08531D4C
	.equ	se_unk_ff_pri, 5
	.equ	se_unk_ff_rev, reverb_set+50
	.equ	se_unk_ff_mvl, 127
	.equ	se_unk_ff_key, 0
	.equ	se_unk_ff_tbs, 1
	.equ	se_unk_ff_exg, 0
	.equ	se_unk_ff_cmp, 1

	.section .rodata
	.global	se_unk_ff
	.align	2

@*********************** Track 01 ***********************@

se_unk_ff_0:  @ 0x086A1BD4
	.byte	KEYSH , se_unk_ff_key+0
	.byte	TEMPO , 150*se_unk_ff_tbs/2
	.byte		VOICE , 56
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 65*se_unk_ff_mvl/mxv
	.byte		BEND  , c_v+8
	.byte		N01   , Cs6 , v112
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , Dn6 , v100
	.byte	W01
	.byte		        Dn6 , v060
	.byte	W04
	.byte		BEND  , c_v-8
	.byte		N01   , Ds6 , v112
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , En6 , v100
	.byte	W01
	.byte		        En6 , v060
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ff:  @ 0x086A1C00
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ff_pri	@ Priority
	.byte	se_unk_ff_rev	@ Reverb

	.word	se_unk_ff_grp

	.word	se_unk_ff_0
@ 0x086A1C0C
