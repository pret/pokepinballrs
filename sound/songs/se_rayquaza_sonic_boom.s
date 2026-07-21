	.include "sound/MPlayDef.s"

	.equ	se_rayquaza_sonic_boom_grp, gUnknown_08531D4C
	.equ	se_rayquaza_sonic_boom_pri, 5
	.equ	se_rayquaza_sonic_boom_rev, reverb_set+50
	.equ	se_rayquaza_sonic_boom_mvl, 127
	.equ	se_rayquaza_sonic_boom_key, 0
	.equ	se_rayquaza_sonic_boom_tbs, 1
	.equ	se_rayquaza_sonic_boom_exg, 0
	.equ	se_rayquaza_sonic_boom_cmp, 1

	.section .rodata
	.global	se_rayquaza_sonic_boom
	.align	2

@*********************** Track 01 ***********************@

se_rayquaza_sonic_boom_0:  @ 0x086A2AC8
	.byte	KEYSH , se_rayquaza_sonic_boom_key+0
	.byte	TEMPO , 150*se_rayquaza_sonic_boom_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 125*se_rayquaza_sonic_boom_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Ds3 , v127
	.byte	W01
	.byte		        As2 
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		N02   , Gn3 
	.byte	W01
	.byte		PAN   , c_v+7
	.byte	W03
	.byte		        c_v+0
	.byte		N01   , Ds3 
	.byte	W01
	.byte		        As2 
	.byte	W02
	.byte		N54   , Fn3 
	.byte	W11
	.byte		BEND  , c_v+3
	.byte	W03
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+7
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BEND  , c_v+20
	.byte	W02
	.byte		PAN   , c_v+7
	.byte	W02
	.byte		BEND  , c_v+25
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		        c_v-8
	.byte		BEND  , c_v+20
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		PAN   , c_v+7
	.byte	W04
	.byte		        c_v-8
	.byte	W10
	.byte	FINE

@*********************** Track 02 ***********************@

se_rayquaza_sonic_boom_1:  @ 0x086A2B27
	.byte	KEYSH , se_rayquaza_sonic_boom_key+0
	.byte		VOICE , 4
	.byte		VOL   , 125*se_rayquaza_sonic_boom_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N02   , Cn3 , v052
	.byte	W01
	.byte		VOL   , 74*se_rayquaza_sonic_boom_mvl/mxv
	.byte	W06
	.byte		        125*se_rayquaza_sonic_boom_mvl/mxv
	.byte		N02
	.byte	W01
	.byte		VOL   , 74*se_rayquaza_sonic_boom_mvl/mxv
	.byte	W16
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_rayquaza_sonic_boom:  @ 0x086A2B44
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rayquaza_sonic_boom_pri	@ Priority
	.byte	se_rayquaza_sonic_boom_rev	@ Reverb

	.word	se_rayquaza_sonic_boom_grp

	.word	se_rayquaza_sonic_boom_0
	.word	se_rayquaza_sonic_boom_1
@ 0x086A2B54
