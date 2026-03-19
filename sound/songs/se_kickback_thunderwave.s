	.include "sound/MPlayDef.s"

	.equ	se_kickback_thunderwave_grp, gUnknown_08531D4C
	.equ	se_kickback_thunderwave_pri, 5
	.equ	se_kickback_thunderwave_rev, reverb_set+50
	.equ	se_kickback_thunderwave_mvl, 127
	.equ	se_kickback_thunderwave_key, 0
	.equ	se_kickback_thunderwave_tbs, 1
	.equ	se_kickback_thunderwave_exg, 0
	.equ	se_kickback_thunderwave_cmp, 1

	.section .rodata
	.global	se_kickback_thunderwave
	.align	2

@*********************** Track 01 ***********************@

se_kickback_thunderwave_0:  @ 0x0869F2D4
	.byte	KEYSH , se_kickback_thunderwave_key+0
	.byte	TEMPO , 150*se_kickback_thunderwave_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 2
	.byte		VOL   , 100*se_kickback_thunderwave_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fs4 , v080
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte		EOT
	.byte	FINE

@*********************** Track 02 ***********************@

se_kickback_thunderwave_1:  @ 0x0869F2E9
	.byte	KEYSH , se_kickback_thunderwave_key+0
	.byte		VOICE , 27
	.byte		VOL   , 100*se_kickback_thunderwave_mvl/mxv
	.byte		TIE   , Fn3 , v032
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_kickback_thunderwave:  @ 0x0869F2F8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kickback_thunderwave_pri	@ Priority
	.byte	se_kickback_thunderwave_rev	@ Reverb

	.word	se_kickback_thunderwave_grp

	.word	se_kickback_thunderwave_0
	.word	se_kickback_thunderwave_1
@ 0x0869F308
