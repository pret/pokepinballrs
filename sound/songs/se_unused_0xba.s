	.include "sound/MPlayDef.s"

	.equ	se_unused_0xba_grp, gUnknown_0853174C
	.equ	se_unused_0xba_pri, 5
	.equ	se_unused_0xba_rev, reverb_set+50
	.equ	se_unused_0xba_mvl, 127
	.equ	se_unused_0xba_key, 0
	.equ	se_unused_0xba_tbs, 1
	.equ	se_unused_0xba_exg, 0
	.equ	se_unused_0xba_cmp, 1

	.section .rodata
	.global	se_unused_0xba
	.align	2

@*********************** Track 01 ***********************@

se_unused_0xba_0:  @ 0x086A0500
	.byte	KEYSH , se_unused_0xba_key+0
	.byte	TEMPO , 220*se_unused_0xba_tbs/2
	.byte		VOICE , 89
	.byte		VOL   , 80*se_unused_0xba_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0xba:  @ 0x086A0510
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0xba_pri	@ Priority
	.byte	se_unused_0xba_rev	@ Reverb

	.word	se_unused_0xba_grp

	.word	se_unused_0xba_0
@ 0x086A051C
