	.include "sound/MPlayDef.s"

	.equ	se_warp_grp, gUnknown_0853174C
	.equ	se_warp_pri, 5
	.equ	se_warp_rev, reverb_set+50
	.equ	se_warp_mvl, 127
	.equ	se_warp_key, 0
	.equ	se_warp_tbs, 1
	.equ	se_warp_exg, 0
	.equ	se_warp_cmp, 1

	.section .rodata
	.global	se_warp
	.align	2

@*********************** Track 01 ***********************@

se_warp_0:  @ 0x0869FE20
	.byte	KEYSH , se_warp_key+0
	.byte	TEMPO , 110*se_warp_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 90*se_warp_mvl/mxv
	.byte		N06   , En4 , v127
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v088
	.byte	W03
	.byte	W03
	.byte		N03   , En4 , v016
	.byte	W03
	.byte		N06   , En4 , v064
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_warp:  @ 0x0869FE4C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_warp_pri	@ Priority
	.byte	se_warp_rev	@ Reverb

	.word	se_warp_grp

	.word	se_warp_0
@ 0x0869FE58
