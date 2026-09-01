	.include "sound/MPlayDef.s"

	.equ	se_ruby_mart_sign_changed_grp, gVoiceGroup_SFX_08532310
	.equ	se_ruby_mart_sign_changed_pri, 5
	.equ	se_ruby_mart_sign_changed_rev, reverb_set+50
	.equ	se_ruby_mart_sign_changed_mvl, 127
	.equ	se_ruby_mart_sign_changed_key, 0
	.equ	se_ruby_mart_sign_changed_tbs, 1
	.equ	se_ruby_mart_sign_changed_exg, 0
	.equ	se_ruby_mart_sign_changed_cmp, 1

	.section .rodata
	.global	se_ruby_mart_sign_changed
	.align	2

@*********************** Track 01 ***********************@

se_ruby_mart_sign_changed_0:  @ 0x086A0900
	.byte	KEYSH , se_ruby_mart_sign_changed_key+0
	.byte	TEMPO , 150*se_ruby_mart_sign_changed_tbs/2
	.byte		VOL   , 110*se_ruby_mart_sign_changed_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 32
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

se_ruby_mart_sign_changed:  @ 0x086A0910
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ruby_mart_sign_changed_pri	@ Priority
	.byte	se_ruby_mart_sign_changed_rev	@ Reverb

	.word	se_ruby_mart_sign_changed_grp

	.word	se_ruby_mart_sign_changed_0
@ 0x086A091C
