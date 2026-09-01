	.include "sound/MPlayDef.s"

	.equ	se_spheal_end_whistle_grp, gVoiceGroup_Inst_08532808
	.equ	se_spheal_end_whistle_pri, 5
	.equ	se_spheal_end_whistle_rev, reverb_set+50
	.equ	se_spheal_end_whistle_mvl, 127
	.equ	se_spheal_end_whistle_key, 0
	.equ	se_spheal_end_whistle_tbs, 1
	.equ	se_spheal_end_whistle_exg, 0
	.equ	se_spheal_end_whistle_cmp, 1

	.section .rodata
	.global	se_spheal_end_whistle
	.align	2

@*********************** Track 01 ***********************@

se_spheal_end_whistle_0:  @ 0x086A2E7C
	.byte	KEYSH , se_spheal_end_whistle_key+0
	.byte	TEMPO , 150*se_spheal_end_whistle_tbs/2
	.byte		VOL   , 110*se_spheal_end_whistle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 78
	.byte		N04   , Cn4 , v127
	.byte	W12
	.byte		TIE   , Cn4 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_spheal_end_whistle:  @ 0x086A2E90
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_spheal_end_whistle_pri	@ Priority
	.byte	se_spheal_end_whistle_rev	@ Reverb

	.word	se_spheal_end_whistle_grp

	.word	se_spheal_end_whistle_0
@ 0x086A2E9C
