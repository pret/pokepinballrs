	.include "sound/MPlayDef.s"

	.equ	se_unk_bf_grp, gUnknown_08531D4C
	.equ	se_unk_bf_pri, 5
	.equ	se_unk_bf_rev, reverb_set+50
	.equ	se_unk_bf_mvl, 127
	.equ	se_unk_bf_key, 0
	.equ	se_unk_bf_tbs, 1
	.equ	se_unk_bf_exg, 0
	.equ	se_unk_bf_cmp, 1

	.section .rodata
	.global	se_unk_bf
	.align	2

@*********************** Track 01 ***********************@

se_unk_bf_0:  @ 0x086A0640
	.byte	KEYSH , se_unk_bf_key+0
	.byte	TEMPO , 150*se_unk_bf_tbs/2
	.byte		VOICE , 45
	.byte		VOL   , 100*se_unk_bf_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+14
	.byte		BEND  , c_v-5
	.byte		N06   , En3 , v112
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+55
	.byte	W03
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v-5
	.byte		N06   , Ds3 , v096
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+55
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		BEND  , c_v-5
	.byte		N06   , Dn3 , v080
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+55
	.byte	W03
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-5
	.byte		N06   , Cs3 , v060
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+55
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-5
	.byte		N06   , Cn3 , v040
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+55
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_bf:  @ 0x086A0698
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_bf_pri	@ Priority
	.byte	se_unk_bf_rev	@ Reverb

	.word	se_unk_bf_grp

	.word	se_unk_bf_0
@ 0x086A06A4
