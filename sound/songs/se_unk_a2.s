	.include "sound/MPlayDef.s"

	.equ	se_unk_a2_grp, gUnknown_08531D4C
	.equ	se_unk_a2_pri, 5
	.equ	se_unk_a2_rev, reverb_set+50
	.equ	se_unk_a2_mvl, 127
	.equ	se_unk_a2_key, 0
	.equ	se_unk_a2_tbs, 1
	.equ	se_unk_a2_exg, 0
	.equ	se_unk_a2_cmp, 1

	.section .rodata
	.global	se_unk_a2
	.align	2

@*********************** Track 01 ***********************@

se_unk_a2_0:  @ 0x0869FEB4
	.byte	KEYSH , se_unk_a2_key+0
	.byte	TEMPO , 150*se_unk_a2_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 16*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N09   , Gn5 , v032
	.byte	W01
	.byte		VOL   , 63*se_unk_a2_mvl/mxv
	.byte	W01
	.byte		        98*se_unk_a2_mvl/mxv
	.byte	W01
	.byte		        110*se_unk_a2_mvl/mxv
	.byte	W01
	.byte		        99*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		VOL   , 63*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 22*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+21
	.byte	W01
	.byte		VOL   , 9*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W04
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_a2_1:  @ 0x0869FEE1
	.byte	KEYSH , se_unk_a2_key+0
	.byte		VOICE , 71
	.byte		PAN   , c_v+32
	.byte		VOL   , 110*se_unk_a2_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N09   , Fs4 , v060
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_a2:  @ 0x0869FEF4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_a2_pri	@ Priority
	.byte	se_unk_a2_rev	@ Reverb

	.word	se_unk_a2_grp

	.word	se_unk_a2_0
	.word	se_unk_a2_1
@ 0x0869FF04
