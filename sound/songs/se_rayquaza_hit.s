	.include "sound/MPlayDef.s"

	.equ	se_rayquaza_hit_grp, gUnknown_0853174C
	.equ	se_rayquaza_hit_pri, 5
	.equ	se_rayquaza_hit_rev, reverb_set+50
	.equ	se_rayquaza_hit_mvl, 127
	.equ	se_rayquaza_hit_key, 0
	.equ	se_rayquaza_hit_tbs, 1
	.equ	se_rayquaza_hit_exg, 0
	.equ	se_rayquaza_hit_cmp, 1

	.section .rodata
	.global	se_rayquaza_hit
	.align	2

@*********************** Track 01 ***********************@

se_rayquaza_hit_0:  @ 0x086A2820
	.byte	KEYSH , se_rayquaza_hit_key+0
	.byte	TEMPO , 90*se_rayquaza_hit_tbs/2
	.byte		VOICE , 125
	.byte		VOL   , 110*se_rayquaza_hit_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , As2 , v100
	.byte	W03
	.byte		BEND  , c_v-33
	.byte		N36   , Ds3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_rayquaza_hit_1:  @ 0x086A2842
	.byte	KEYSH , se_rayquaza_hit_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_rayquaza_hit_mvl/mxv
	.byte		N03   , Cn3 , v127
	.byte	W03
	.byte		N18
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_rayquaza_hit:  @ 0x086A285C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rayquaza_hit_pri	@ Priority
	.byte	se_rayquaza_hit_rev	@ Reverb

	.word	se_rayquaza_hit_grp

	.word	se_rayquaza_hit_0
	.word	se_rayquaza_hit_1
@ 0x086A286C
