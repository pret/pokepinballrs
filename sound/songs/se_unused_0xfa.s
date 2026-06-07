	.include "sound/MPlayDef.s"

	.equ	se_unused_0xfa_grp, gUnknown_08531D4C
	.equ	se_unused_0xfa_pri, 5
	.equ	se_unused_0xfa_rev, reverb_set+50
	.equ	se_unused_0xfa_mvl, 127
	.equ	se_unused_0xfa_key, 0
	.equ	se_unused_0xfa_tbs, 1
	.equ	se_unused_0xfa_exg, 0
	.equ	se_unused_0xfa_cmp, 1

	.section .rodata
	.global	se_unused_0xfa
	.align	2

@*********************** Track 01 ***********************@

se_unused_0xfa_0:  @ 0x086A19FC
	.byte	KEYSH , se_unused_0xfa_key+0
	.byte	TEMPO , 220*se_unused_0xfa_tbs/2
	.byte		VOICE , 54
	.byte		VOL   , 100*se_unused_0xfa_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W02
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v104
	.byte	W01
	.byte		PAN   , c_v-2
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W04
	.byte	W01
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v080
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		BEND  , c_v+1
	.byte		N03   , As5 , v048
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Bn5 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0xfa:  @ 0x086A1A5C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0xfa_pri	@ Priority
	.byte	se_unused_0xfa_rev	@ Reverb

	.word	se_unused_0xfa_grp

	.word	se_unused_0xfa_0
@ 0x086A1A68
