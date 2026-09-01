	.include "sound/MPlayDef.s"

	.equ	se_kecleon_startled_grp, gVoiceGroup_SFX_0853174C
	.equ	se_kecleon_startled_pri, 5
	.equ	se_kecleon_startled_rev, reverb_set+50
	.equ	se_kecleon_startled_mvl, 127
	.equ	se_kecleon_startled_key, 0
	.equ	se_kecleon_startled_tbs, 1
	.equ	se_kecleon_startled_exg, 0
	.equ	se_kecleon_startled_cmp, 1

	.section .rodata
	.global	se_kecleon_startled
	.align	2

@*********************** Track 01 ***********************@

se_kecleon_startled_0:  @ 0x086A1BA8
	.byte	KEYSH , se_kecleon_startled_key+0
	.byte	TEMPO , 100*se_kecleon_startled_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 60*se_kecleon_startled_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn5 , v127
	.byte	W03
	.byte		        Gn6 , v112
	.byte	W03
	.byte		        Gn6 , v024
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v024
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_kecleon_startled:  @ 0x086A1BC8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kecleon_startled_pri	@ Priority
	.byte	se_kecleon_startled_rev	@ Reverb

	.word	se_kecleon_startled_grp

	.word	se_kecleon_startled_0
@ 0x086A1BD4
