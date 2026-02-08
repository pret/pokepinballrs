	.include "sound/MPlayDef.s"

	.equ	se_unk_100_grp, gUnknown_08531D4C
	.equ	se_unk_100_pri, 5
	.equ	se_unk_100_rev, reverb_set+50
	.equ	se_unk_100_mvl, 127
	.equ	se_unk_100_key, 0
	.equ	se_unk_100_tbs, 1
	.equ	se_unk_100_exg, 0
	.equ	se_unk_100_cmp, 1

	.section .rodata
	.global	se_unk_100
	.align	2

@*********************** Track 01 ***********************@

se_unk_100_0:  @ 0x086A1C0C
	.byte	KEYSH , se_unk_100_key+0
	.byte	TEMPO , 150*se_unk_100_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_100_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Gn5 , v092
	.byte	W02
	.byte		        Cn5 
	.byte	W04
	.byte		VOICE , 36
	.byte		VOL   , 84*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		N15   , Gn5 , v040
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		VOL   , 94*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		VOL   , 110*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W02
	.byte		VOL   , 96*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		VOL   , 68*se_unk_100_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		VOL   , 15*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		        c_v-10
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_100_1:  @ 0x086A1C55
	.byte	KEYSH , se_unk_100_key+0
	.byte		VOICE , 25
	.byte		VOL   , 110*se_unk_100_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn3 , v040
	.byte	W02
	.byte		N01
	.byte	W22
	.byte	FINE

@******************************************************@

	.align	2

se_unk_100:  @ 0x086A1C64
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_100_pri	@ Priority
	.byte	se_unk_100_rev	@ Reverb

	.word	se_unk_100_grp

	.word	se_unk_100_0
	.word	se_unk_100_1
@ 0x086A1C74
