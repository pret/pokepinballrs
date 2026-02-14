	.include "sound/MPlayDef.s"

	.equ	se_kecleon_scope_activated_grp, gUnknown_0853174C
	.equ	se_kecleon_scope_activated_pri, 5
	.equ	se_kecleon_scope_activated_rev, reverb_set+50
	.equ	se_kecleon_scope_activated_mvl, 127
	.equ	se_kecleon_scope_activated_key, 0
	.equ	se_kecleon_scope_activated_tbs, 1
	.equ	se_kecleon_scope_activated_exg, 0
	.equ	se_kecleon_scope_activated_cmp, 1

	.section .rodata
	.global	se_kecleon_scope_activated
	.align	2

@*********************** Track 01 ***********************@

se_kecleon_scope_activated_0:  @ 0x086A1E14
	.byte	KEYSH , se_kecleon_scope_activated_key+0
	.byte	TEMPO , 132*se_kecleon_scope_activated_tbs/2
	.byte		VOICE , 91
	.byte		VOL   , 100*se_kecleon_scope_activated_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v112
	.byte	W04
	.byte		N02
	.byte	W04
	.byte		VOICE , 90
	.byte		N15
	.byte	W16
	.byte	FINE

@******************************************************@

	.align	2

se_kecleon_scope_activated:  @ 0x086A1E2C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kecleon_scope_activated_pri	@ Priority
	.byte	se_kecleon_scope_activated_rev	@ Reverb

	.word	se_kecleon_scope_activated_grp

	.word	se_kecleon_scope_activated_0
@ 0x086A1E38
