	.include "sound/MPlayDef.s"

	.equ	se_coin_collected_grp, gUnknown_0853174C
	.equ	se_coin_collected_pri, 5
	.equ	se_coin_collected_rev, reverb_set+50
	.equ	se_coin_collected_mvl, 127
	.equ	se_coin_collected_key, 0
	.equ	se_coin_collected_tbs, 1
	.equ	se_coin_collected_exg, 0
	.equ	se_coin_collected_cmp, 1

	.section .rodata
	.global	se_coin_collected
	.align	2

@*********************** Track 01 ***********************@

se_coin_collected_0:  @ 0x0869F338
	.byte	KEYSH , se_coin_collected_key+0
	.byte	TEMPO , 300*se_coin_collected_tbs/2
	.byte		VOICE , 87
	.byte		VOL   , 80*se_coin_collected_mvl/mxv
	.byte		BEND  , c_v+13
	.byte		N03   , As5 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v127
	.byte	W03
	.byte		VOICE , 88
	.byte		N06   , Gn6 , v068
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_coin_collected:  @ 0x0869F358
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_coin_collected_pri	@ Priority
	.byte	se_coin_collected_rev	@ Reverb

	.word	se_coin_collected_grp

	.word	se_coin_collected_0
@ 0x0869F364
