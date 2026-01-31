	.include "sound/MPlayDef.s"

	.equ	se_unk_10c_grp, gUnknown_08531D4C
	.equ	se_unk_10c_pri, 5
	.equ	se_unk_10c_rev, reverb_set+50
	.equ	se_unk_10c_mvl, 127
	.equ	se_unk_10c_key, 0
	.equ	se_unk_10c_tbs, 1
	.equ	se_unk_10c_exg, 0
	.equ	se_unk_10c_cmp, 1

	.section .rodata
	.global	se_unk_10c
	.align	2

@*********************** Track 01 ***********************@

se_unk_10c_0:  @ 0x086A1F20
	.byte	KEYSH , se_unk_10c_key+0
	.byte	TEMPO , 150*se_unk_10c_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 115*se_unk_10c_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N60   , Gn2 , v127
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-16
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-14
	.byte	W03
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v-11
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-8
	.byte	W04
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-2
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v+7
	.byte	W02
	.byte		VOL   , 109*se_unk_10c_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+10
	.byte	W02
	.byte		VOL   , 103*se_unk_10c_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v+13
	.byte	W03
	.byte		VOL   , 92*se_unk_10c_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOL   , 79*se_unk_10c_mvl/mxv
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+18
	.byte	W02
	.byte	W02
	.byte		VOL   , 62*se_unk_10c_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+21
	.byte	W04
	.byte		VOL   , 40*se_unk_10c_mvl/mxv
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+26
	.byte	W02
	.byte		VOL   , 22*se_unk_10c_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 8*se_unk_10c_mvl/mxv
	.byte		BEND  , c_v+43
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_10c_1:  @ 0x086A1F9D
	.byte	KEYSH , se_unk_10c_key+0
	.byte		VOICE , 25
	.byte		VOL   , 115*se_unk_10c_mvl/mxv
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		        Gn2 
	.byte	W06
se_unk_10c_1_B1:
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	se_unk_10c_1_B1
	.byte		N06   , Cn3 , v032
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 , v012
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_10c:  @ 0x086A1FC4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_10c_pri	@ Priority
	.byte	se_unk_10c_rev	@ Reverb

	.word	se_unk_10c_grp

	.word	se_unk_10c_0
	.word	se_unk_10c_1
@ 0x086A1FD4
