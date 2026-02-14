	.include "sound/MPlayDef.s"

	.equ	se_tilt_triggered_grp, gUnknown_08531D4C
	.equ	se_tilt_triggered_pri, 5
	.equ	se_tilt_triggered_rev, reverb_set+50
	.equ	se_tilt_triggered_mvl, 127
	.equ	se_tilt_triggered_key, 0
	.equ	se_tilt_triggered_tbs, 1
	.equ	se_tilt_triggered_exg, 0
	.equ	se_tilt_triggered_cmp, 1

	.section .rodata
	.global	se_tilt_triggered
	.align	2

@*********************** Track 01 ***********************@

se_tilt_triggered_0:  @ 0x0869F1EC
	.byte	KEYSH , se_tilt_triggered_key+0
	.byte	TEMPO , 150*se_tilt_triggered_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		VOL   , 55*se_tilt_triggered_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N01   , Cn6 , v100
	.byte	W01
	.byte		VOL   , 110*se_tilt_triggered_mvl/mxv
	.byte	W01
	.byte		VOICE , 36
	.byte		VOL   , 55*se_tilt_triggered_mvl/mxv
	.byte		N02   , Gn6 , v080
	.byte	W01
	.byte		VOL   , 110*se_tilt_triggered_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+20
	.byte		N01   , Gn6 , v024
	.byte	W03
	.byte		        Gn6 , v016
	.byte	W02
	.byte		PAN   , c_v-21
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_tilt_triggered:  @ 0x0869F21C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tilt_triggered_pri	@ Priority
	.byte	se_tilt_triggered_rev	@ Reverb

	.word	se_tilt_triggered_grp

	.word	se_tilt_triggered_0
@ 0x0869F228
