	.include "sound/MPlayDef.s"

	.equ	se_seedot_falling_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_seedot_falling_pri, 5
	.equ	se_seedot_falling_rev, reverb_set+50
	.equ	se_seedot_falling_mvl, 127
	.equ	se_seedot_falling_key, 0
	.equ	se_seedot_falling_tbs, 1
	.equ	se_seedot_falling_exg, 0
	.equ	se_seedot_falling_cmp, 1

	.section .rodata
	.global	se_seedot_falling
	.align	2

@*********************** Track 01 ***********************@

se_seedot_falling_0:  @ 0x086A1300
	.byte	KEYSH , se_seedot_falling_key+0
	.byte	TEMPO , 170*se_seedot_falling_tbs/2
	.byte		VOICE , 22
	.byte		VOL   , 110*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v+60
	.byte		N44   , Gn3 , v080
	.byte	W03
	.byte		BEND  , c_v+57
	.byte	W03
	.byte		        c_v+52
	.byte	W03
	.byte		        c_v+43
	.byte	W03
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+30
	.byte	W03
	.byte		        c_v+22
	.byte	W03
	.byte		        c_v+16
	.byte	W03
	.byte		VOL   , 104*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		VOL   , 90*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		VOL   , 82*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		VOL   , 71*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		VOL   , 58*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		VOL   , 45*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-36
	.byte	W03
	.byte		VOL   , 36*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W03
	.byte		VOL   , 11*se_seedot_falling_mvl/mxv
	.byte		BEND  , c_v-63
	.byte	W03
	.byte		VOL   , 3*se_seedot_falling_mvl/mxv
	.byte	FINE

@******************************************************@

	.align	2

se_seedot_falling:  @ 0x086A1348
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_seedot_falling_pri	@ Priority
	.byte	se_seedot_falling_rev	@ Reverb

	.word	se_seedot_falling_grp

	.word	se_seedot_falling_0
@ 0x086A1354
