	.include "sound/MPlayDef.s"

	.equ	se_unused_0xbf_grp, gUnknown_08531D4C
	.equ	se_unused_0xbf_pri, 5
	.equ	se_unused_0xbf_rev, reverb_set+50
	.equ	se_unused_0xbf_mvl, 127
	.equ	se_unused_0xbf_key, 0
	.equ	se_unused_0xbf_tbs, 1
	.equ	se_unused_0xbf_exg, 0
	.equ	se_unused_0xbf_cmp, 1

	.section .rodata
	.global	se_unused_0xbf
	.align	2

@*********************** Track 01 ***********************@

se_unused_0xbf_0:  @ 0x086A0640
	.byte	KEYSH , se_unused_0xbf_key+0
	.byte	TEMPO , 150*se_unused_0xbf_tbs/2
	.byte		VOICE , 45
	.byte		VOL   , 100*se_unused_0xbf_mvl/mxv
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

se_unused_0xbf:  @ 0x086A0698
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0xbf_pri	@ Priority
	.byte	se_unused_0xbf_rev	@ Reverb

	.word	se_unused_0xbf_grp

	.word	se_unused_0xbf_0
@ 0x086A06A4
