	.include "sound/MPlayDef.s"

	.equ	se_pichu_kickback_grp, gUnknown_08532310
	.equ	se_pichu_kickback_pri, 5
	.equ	se_pichu_kickback_rev, reverb_set+50
	.equ	se_pichu_kickback_mvl, 127
	.equ	se_pichu_kickback_key, 0
	.equ	se_pichu_kickback_tbs, 1
	.equ	se_pichu_kickback_exg, 0
	.equ	se_pichu_kickback_cmp, 1

	.section .rodata
	.global	se_pichu_kickback
	.align	2

@*********************** Track 01 ***********************@

se_pichu_kickback_0:  @ 0x086A0354
	.byte	KEYSH , se_pichu_kickback_key+0
	.byte	TEMPO , 150*se_pichu_kickback_tbs/2
	.byte		VOL   , 127*se_pichu_kickback_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 105
	.byte		TIE   , Cn3 , v127
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_pichu_kickback:  @ 0x086A0368
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pichu_kickback_pri	@ Priority
	.byte	se_pichu_kickback_rev	@ Reverb

	.word	se_pichu_kickback_grp

	.word	se_pichu_kickback_0
@ 0x086A0374
