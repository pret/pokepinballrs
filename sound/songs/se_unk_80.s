	.include "sound/MPlayDef.s"

	.equ	se_unk_80_grp, gUnknown_08531D4C
	.equ	se_unk_80_pri, 5
	.equ	se_unk_80_rev, reverb_set+50
	.equ	se_unk_80_mvl, 127
	.equ	se_unk_80_key, 0
	.equ	se_unk_80_tbs, 1
	.equ	se_unk_80_exg, 0
	.equ	se_unk_80_cmp, 1

	.section .rodata
	.global	se_unk_80
	.align	2

@*********************** Track 01 ***********************@

se_unk_80_0:  @ 0x0869F3CC
	.byte	KEYSH , se_unk_80_key+0
	.byte	TEMPO , 220*se_unk_80_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 110*se_unk_80_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+0
	.byte		N02   , Cn4 , v127
	.byte	W03
	.byte		VOL   , 104*se_unk_80_mvl/mxv
	.byte	W03
	.byte		        93*se_unk_80_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N02   , Cn5 
	.byte	W03
	.byte		VOL   , 110*se_unk_80_mvl/mxv
	.byte	W01
	.byte		VOICE , 22
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v060
	.byte	W02
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v+1
	.byte	W01
	.byte		VOL   , 105*se_unk_80_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 103*se_unk_80_mvl/mxv
	.byte	W02
	.byte		        91*se_unk_80_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 77*se_unk_80_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 61*se_unk_80_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 38*se_unk_80_mvl/mxv
	.byte	W01
	.byte		        15*se_unk_80_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_80_1:  @ 0x0869F419
	.byte	KEYSH , se_unk_80_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_unk_80_mvl/mxv
	.byte		N02   , Cn3 , v060
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Gs4 
	.byte	W04
	.byte		        Gs4 , v020
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_80:  @ 0x0869F430
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_80_pri	@ Priority
	.byte	se_unk_80_rev	@ Reverb

	.word	se_unk_80_grp

	.word	se_unk_80_0
	.word	se_unk_80_1
@ 0x0869F440
