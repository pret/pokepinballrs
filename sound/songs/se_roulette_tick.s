	.include "sound/MPlayDef.s"

	.equ	se_roulette_tick_grp, gUnknown_08531D4C
	.equ	se_roulette_tick_pri, 5
	.equ	se_roulette_tick_rev, reverb_set+50
	.equ	se_roulette_tick_mvl, 127
	.equ	se_roulette_tick_key, 0
	.equ	se_roulette_tick_tbs, 1
	.equ	se_roulette_tick_exg, 0
	.equ	se_roulette_tick_cmp, 1

	.section .rodata
	.global	se_roulette_tick
	.align	2

@*********************** Track 01 ***********************@

se_roulette_tick_0:  @ 0x0869F440
	.byte	KEYSH , se_roulette_tick_key+0
	.byte	TEMPO , 150*se_roulette_tick_tbs/2
	.byte		VOICE , 16
	.byte		VOL   , 100*se_roulette_tick_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Dn4 , v088
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_roulette_tick_1:  @ 0x0869F44F
	.byte	KEYSH , se_roulette_tick_key+0
	.byte		VOICE , 17
	.byte		VOL   , 100*se_roulette_tick_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Dn4 , v072
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_roulette_tick:  @ 0x0869F45C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_roulette_tick_pri	@ Priority
	.byte	se_roulette_tick_rev	@ Reverb

	.word	se_roulette_tick_grp

	.word	se_roulette_tick_0
	.word	se_roulette_tick_1
@ 0x0869F46C
