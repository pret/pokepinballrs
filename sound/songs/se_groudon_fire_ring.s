	.include "sound/MPlayDef.s"

	.equ	se_groudon_fire_ring_grp, gUnknown_0853174C
	.equ	se_groudon_fire_ring_pri, 5
	.equ	se_groudon_fire_ring_rev, reverb_set+50
	.equ	se_groudon_fire_ring_mvl, 127
	.equ	se_groudon_fire_ring_key, 0
	.equ	se_groudon_fire_ring_tbs, 1
	.equ	se_groudon_fire_ring_exg, 0
	.equ	se_groudon_fire_ring_cmp, 1

	.section .rodata
	.global	se_groudon_fire_ring
	.align	2

@*********************** Track 01 ***********************@

se_groudon_fire_ring_0:  @ 0x086A2500
	.byte	KEYSH , se_groudon_fire_ring_key+0
	.byte	TEMPO , 220*se_groudon_fire_ring_tbs/2
	.byte		VOICE , 123
	.byte		VOL   , 75*se_groudon_fire_ring_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		TIE   , Cn4 
	.byte	W21
	.byte	W24
	.byte	W18
	.byte		VOL   , 75*se_groudon_fire_ring_mvl/mxv
	.byte	W06
	.byte		        71*se_groudon_fire_ring_mvl/mxv
	.byte	W05
	.byte		        67*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        62*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte		        59*se_groudon_fire_ring_mvl/mxv
	.byte	W05
	.byte		        57*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        54*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        50*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        49*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        44*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte		        41*se_groudon_fire_ring_mvl/mxv
	.byte	W02
	.byte		        38*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        35*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        32*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte		        28*se_groudon_fire_ring_mvl/mxv
	.byte	W02
	.byte		        24*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        21*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        18*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte		        14*se_groudon_fire_ring_mvl/mxv
	.byte	W02
	.byte		        11*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        9*se_groudon_fire_ring_mvl/mxv
	.byte	W03
	.byte		        6*se_groudon_fire_ring_mvl/mxv
	.byte	W04
	.byte		        3*se_groudon_fire_ring_mvl/mxv
	.byte	W02
	.byte		        1*se_groudon_fire_ring_mvl/mxv
	.byte	W22
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_groudon_fire_ring:  @ 0x086A2548
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_groudon_fire_ring_pri	@ Priority
	.byte	se_groudon_fire_ring_rev	@ Reverb

	.word	se_groudon_fire_ring_grp

	.word	se_groudon_fire_ring_0
@ 0x086A2554
