	.include "sound/MPlayDef.s"

	.equ	se_unk_f2_grp, gUnknown_08531D4C
	.equ	se_unk_f2_pri, 5
	.equ	se_unk_f2_rev, reverb_set+50
	.equ	se_unk_f2_mvl, 127
	.equ	se_unk_f2_key, 0
	.equ	se_unk_f2_tbs, 1
	.equ	se_unk_f2_exg, 0
	.equ	se_unk_f2_cmp, 1

	.section .rodata
	.global	se_unk_f2
	.align	2

@*********************** Track 01 ***********************@

se_unk_f2_0:  @ 0x086A1594
	.byte		VOL   , 110*se_unk_f2_mvl/mxv
	.byte	KEYSH , se_unk_f2_key+0
	.byte	TEMPO , 150*se_unk_f2_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 , v108
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		PAN   , c_v-4
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+2
	.byte	W03
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-3
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_f2_1:  @ 0x086A15E8
	.byte	KEYSH , se_unk_f2_key+0
	.byte		VOICE , 66
	.byte		BENDR , 44
	.byte		PAN   , c_v+1
	.byte		VOL   , 110*se_unk_f2_mvl/mxv
	.byte		N48   , Dn3 , v020
	.byte	W24
	.byte	W03
	.byte		VOL   , 103*se_unk_f2_mvl/mxv
	.byte	W04
	.byte		        96*se_unk_f2_mvl/mxv
	.byte	W03
	.byte		        83*se_unk_f2_mvl/mxv
	.byte	W04
	.byte		        67*se_unk_f2_mvl/mxv
	.byte	W04
	.byte		        49*se_unk_f2_mvl/mxv
	.byte	W03
	.byte		        23*se_unk_f2_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_f2:  @ 0x086A1608
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_f2_pri	@ Priority
	.byte	se_unk_f2_rev	@ Reverb

	.word	se_unk_f2_grp

	.word	se_unk_f2_0
	.word	se_unk_f2_1
@ 0x086A1618
