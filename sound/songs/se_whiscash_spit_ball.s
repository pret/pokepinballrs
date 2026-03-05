	.include "sound/MPlayDef.s"

	.equ	se_whiscash_spit_ball_grp, gUnknown_08531D4C
	.equ	se_whiscash_spit_ball_pri, 5
	.equ	se_whiscash_spit_ball_rev, reverb_set+50
	.equ	se_whiscash_spit_ball_mvl, 127
	.equ	se_whiscash_spit_ball_key, 0
	.equ	se_whiscash_spit_ball_tbs, 1
	.equ	se_whiscash_spit_ball_exg, 0
	.equ	se_whiscash_spit_ball_cmp, 1

	.section .rodata
	.global	se_whiscash_spit_ball
	.align	2

@*********************** Track 01 ***********************@

se_whiscash_spit_ball_0:  @ 0x086A0E50
	.byte	KEYSH , se_whiscash_spit_ball_key+0
	.byte	TEMPO , 220*se_whiscash_spit_ball_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_whiscash_spit_ball_mvl/mxv
	.byte		PAN   , c_v+14
	.byte		BEND  , c_v+0
	.byte		N09   , Cn5 , v092
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+28
	.byte	W03
	.byte		VOICE , 2
	.byte		BEND  , c_v-64
	.byte		N21   , Bn2 , v108
	.byte	W03
	.byte		BEND  , c_v-55
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-45
	.byte	W03
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+30
	.byte	W03
	.byte		PAN   , c_v+15
	.byte		BEND  , c_v+39
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v+54
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+63
	.byte	W21
	.byte	FINE

@*********************** Track 02 ***********************@

se_whiscash_spit_ball_1:  @ 0x086A0E93
	.byte	KEYSH , se_whiscash_spit_ball_key+0
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_whiscash_spit_ball_mvl/mxv
	.byte		N06   , Fn3 , v040
	.byte	W09
	.byte		N24   , Gn3 
	.byte	W15
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_whiscash_spit_ball:  @ 0x086A0EA4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_whiscash_spit_ball_pri	@ Priority
	.byte	se_whiscash_spit_ball_rev	@ Reverb

	.word	se_whiscash_spit_ball_grp

	.word	se_whiscash_spit_ball_0
	.word	se_whiscash_spit_ball_1
@ 0x086A0EB4
