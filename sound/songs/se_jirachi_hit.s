	.include "sound/MPlayDef.s"

	.equ	se_jirachi_hit_grp, gUnknown_08531D4C
	.equ	se_jirachi_hit_pri, 5
	.equ	se_jirachi_hit_rev, reverb_set+50
	.equ	se_jirachi_hit_mvl, 127
	.equ	se_jirachi_hit_key, 0
	.equ	se_jirachi_hit_tbs, 1
	.equ	se_jirachi_hit_exg, 0
	.equ	se_jirachi_hit_cmp, 1

	.section .rodata
	.global	se_jirachi_hit
	.align	2

@*********************** Track 01 ***********************@

se_jirachi_hit_0:  @ 0x086A30C0
	.byte	KEYSH , se_jirachi_hit_key+0
	.byte	TEMPO , 220*se_jirachi_hit_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 95*se_jirachi_hit_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N03   , Cn6 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Gn6 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W02
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , Cn6 , v104
	.byte	W01
	.byte		PAN   , c_v-2
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Gn6 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W04
	.byte	W01
	.byte		BEND  , c_v+1
	.byte		N03   , Cs6 , v080
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Gs6 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		BEND  , c_v+1
	.byte		N03   , Cs6 , v048
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte		N06   , Gs6 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte	W02
	.byte		        c_v+4
	.byte		BEND  , c_v+1
	.byte		N03   , Cs6 , v032
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W02
	.byte		        c_v+0
	.byte		N06   , Gs6 
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_jirachi_hit:  @ 0x086A3130
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_jirachi_hit_pri	@ Priority
	.byte	se_jirachi_hit_rev	@ Reverb

	.word	se_jirachi_hit_grp

	.word	se_jirachi_hit_0
@ 0x086A313C
