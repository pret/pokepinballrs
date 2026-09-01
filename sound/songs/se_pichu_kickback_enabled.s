	.include "sound/MPlayDef.s"

	.equ	se_pichu_kickback_enabled_grp, gVoiceGroup_SFX_08532310
	.equ	se_pichu_kickback_enabled_pri, 5
	.equ	se_pichu_kickback_enabled_rev, reverb_set+50
	.equ	se_pichu_kickback_enabled_mvl, 127
	.equ	se_pichu_kickback_enabled_key, 0
	.equ	se_pichu_kickback_enabled_tbs, 1
	.equ	se_pichu_kickback_enabled_exg, 0
	.equ	se_pichu_kickback_enabled_cmp, 1

	.section .rodata
	.global	se_pichu_kickback_enabled
	.align	2

@*********************** Track 01 ***********************@

se_pichu_kickback_enabled_0:  @ 0x086A0334
	.byte	KEYSH , se_pichu_kickback_enabled_key+0
	.byte	TEMPO , 150*se_pichu_kickback_enabled_tbs/2
	.byte		VOL   , 127*se_pichu_kickback_enabled_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 103
	.byte		TIE   , Cn3 , v127
	.byte	W96
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_pichu_kickback_enabled:  @ 0x086A0348
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pichu_kickback_enabled_pri	@ Priority
	.byte	se_pichu_kickback_enabled_rev	@ Reverb

	.word	se_pichu_kickback_enabled_grp

	.word	se_pichu_kickback_enabled_0
@ 0x086A0354
