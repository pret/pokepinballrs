	.include "sound/MPlayDef.s"

	.equ	se_ruby_bumper_emerges_grp, gUnknown_08531D4C
	.equ	se_ruby_bumper_emerges_pri, 5
	.equ	se_ruby_bumper_emerges_rev, reverb_set+50
	.equ	se_ruby_bumper_emerges_mvl, 127
	.equ	se_ruby_bumper_emerges_key, 0
	.equ	se_ruby_bumper_emerges_tbs, 1
	.equ	se_ruby_bumper_emerges_exg, 0
	.equ	se_ruby_bumper_emerges_cmp, 1

	.section .rodata
	.global	se_ruby_bumper_emerges
	.align	2

@*********************** Track 01 ***********************@

se_ruby_bumper_emerges_0:  @ 0x086A0890
	.byte	KEYSH , se_ruby_bumper_emerges_key+0
	.byte	TEMPO , 220*se_ruby_bumper_emerges_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_ruby_bumper_emerges_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , Gn2 , v127
	.byte	W06
	.byte		PAN   , c_v-17
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte	W03
	.byte		N06
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+13
	.byte	W05
	.byte	FINE

@******************************************************@

	.align	2

se_ruby_bumper_emerges:  @ 0x086A08C0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ruby_bumper_emerges_pri	@ Priority
	.byte	se_ruby_bumper_emerges_rev	@ Reverb

	.word	se_ruby_bumper_emerges_grp

	.word	se_ruby_bumper_emerges_0
@ 0x086A08CC
