	.include "sound/MPlayDef.s"

	.equ	se_unk_d6_grp, gUnknown_08531D4C
	.equ	se_unk_d6_pri, 5
	.equ	se_unk_d6_rev, reverb_set+50
	.equ	se_unk_d6_mvl, 127
	.equ	se_unk_d6_key, 0
	.equ	se_unk_d6_tbs, 1
	.equ	se_unk_d6_exg, 0
	.equ	se_unk_d6_cmp, 1

	.section .rodata
	.global	se_unk_d6
	.align	2

@*********************** Track 01 ***********************@

se_unk_d6_0:  @ 0x086A0E50
	.byte	KEYSH , se_unk_d6_key+0
	.byte	TEMPO , 220*se_unk_d6_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_d6_mvl/mxv
	.byte		PAN   , c_v+14
	.byte		BEND  , c_v+0
	.byte		N09   , Cn5 , v092
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+28
	.byte	W03
	.byte		VOICE , 2
	.byte		BEND  , c_v-64
	.byte		N21   , Bn2 , v108
	.byte	W03
	.byte		BEND  , c_v-55
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-45
	.byte	W03
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+30
	.byte	W03
	.byte		PAN   , c_v+15
	.byte		BEND  , c_v+39
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v+54
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+63
	.byte	W21
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_d6_1:  @ 0x086A0E93
	.byte	KEYSH , se_unk_d6_key+0
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_d6_mvl/mxv
	.byte		N06   , Fn3 , v040
	.byte	W09
	.byte		N24   , Gn3 
	.byte	W15
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unk_d6:  @ 0x086A0EA4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_d6_pri	@ Priority
	.byte	se_unk_d6_rev	@ Reverb

	.word	se_unk_d6_grp

	.word	se_unk_d6_0
	.word	se_unk_d6_1
@ 0x086A0EB4
