	.include "sound/MPlayDef.s"

	.equ	se_travel_painter_paints_grp, gUnknown_0853174C
	.equ	se_travel_painter_paints_pri, 5
	.equ	se_travel_painter_paints_rev, reverb_set+50
	.equ	se_travel_painter_paints_mvl, 127
	.equ	se_travel_painter_paints_key, 0
	.equ	se_travel_painter_paints_tbs, 1
	.equ	se_travel_painter_paints_exg, 0
	.equ	se_travel_painter_paints_cmp, 1

	.section .rodata
	.global	se_travel_painter_paints
	.align	2

@*********************** Track 01 ***********************@

se_travel_painter_paints_0:  @ 0x0869FBC4
	.byte	KEYSH , se_travel_painter_paints_key+0
	.byte	TEMPO , 220*se_travel_painter_paints_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_travel_painter_paints_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		N15   , Gn4 
	.byte	W21
	.byte	FINE

@******************************************************@

	.align	2

se_travel_painter_paints:  @ 0x0869FBD4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_travel_painter_paints_pri	@ Priority
	.byte	se_travel_painter_paints_rev	@ Reverb

	.word	se_travel_painter_paints_grp

	.word	se_travel_painter_paints_0
@ 0x0869FBE0
