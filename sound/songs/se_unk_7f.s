	.include "sound/MPlayDef.s"

	.equ	se_unk_7f_grp, gUnknown_08531D4C
	.equ	se_unk_7f_pri, 5
	.equ	se_unk_7f_rev, reverb_set+50
	.equ	se_unk_7f_mvl, 127
	.equ	se_unk_7f_key, 0
	.equ	se_unk_7f_tbs, 1
	.equ	se_unk_7f_exg, 0
	.equ	se_unk_7f_cmp, 1

	.section .rodata
	.global	se_unk_7f
	.align	2

@*********************** Track 01 ***********************@

se_unk_7f_0:  @ 0x0869F364
	.byte		VOL   , 110*se_unk_7f_mvl/mxv
	.byte	KEYSH , se_unk_7f_key+0
	.byte	TEMPO , 150*se_unk_7f_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N24   , Cn4 , v108
	.byte	W01
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+0
	.byte	W04
	.byte		PAN   , c_v-4
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W04
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v+6
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_7f_1:  @ 0x0869F39C
	.byte	KEYSH , se_unk_7f_key+0
	.byte		VOICE , 66
	.byte		BENDR , 44
	.byte		PAN   , c_v+1
	.byte		VOL   , 110*se_unk_7f_mvl/mxv
	.byte		N48   , Dn3 , v020
	.byte	W24
	.byte	W03
	.byte		VOL   , 103*se_unk_7f_mvl/mxv
	.byte	W04
	.byte		        96*se_unk_7f_mvl/mxv
	.byte	W03
	.byte		        83*se_unk_7f_mvl/mxv
	.byte	W04
	.byte		        67*se_unk_7f_mvl/mxv
	.byte	W04
	.byte		        49*se_unk_7f_mvl/mxv
	.byte	W03
	.byte		        23*se_unk_7f_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_7f:  @ 0x0869F3BC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_7f_pri	@ Priority
	.byte	se_unk_7f_rev	@ Reverb

	.word	se_unk_7f_grp

	.word	se_unk_7f_0
	.word	se_unk_7f_1
@ 0x0869F3CC
