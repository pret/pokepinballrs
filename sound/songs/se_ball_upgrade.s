	.include "sound/MPlayDef.s"

	.equ	se_ball_upgrade_grp, gUnknown_08532310
	.equ	se_ball_upgrade_pri, 5
	.equ	se_ball_upgrade_rev, reverb_set+50
	.equ	se_ball_upgrade_mvl, 127
	.equ	se_ball_upgrade_key, 0
	.equ	se_ball_upgrade_tbs, 1
	.equ	se_ball_upgrade_exg, 0
	.equ	se_ball_upgrade_cmp, 1

	.section .rodata
	.global	se_ball_upgrade
	.align	2

@*********************** Track 01 ***********************@

se_ball_upgrade_0:  @ 0x0869F628
	.byte	KEYSH , se_ball_upgrade_key+0
	.byte	TEMPO , 150*se_ball_upgrade_tbs/2
	.byte		VOL   , 100*se_ball_upgrade_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 17
	.byte		N04   , Cs4 , v127
	.byte	W04
	.byte		N04   , En4 , v127
	.byte	W04
	.byte		N04   , Gn4 , v127
	.byte	W04
	.byte		N04   , As4 , v127
	.byte	W04
	.byte		N04   , Cs4 , v070
	.byte	W04
	.byte		N04   , En4 , v070
	.byte	W04
	.byte		N04   , Gn4 , v070
	.byte	W04
	.byte		N04   , As4 , v070
	.byte	W04
	.byte		N04   , Cs4 , v030
	.byte	W04
	.byte		N04   , En4 , v030
	.byte	W04
	.byte		N04   , Gn4 , v030
	.byte	W04
	.byte		N04   , As4 , v030
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_ball_upgrade:  @ 0x0869F664
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ball_upgrade_pri	@ Priority
	.byte	se_ball_upgrade_rev	@ Reverb

	.word	se_ball_upgrade_grp

	.word	se_ball_upgrade_0
@ 0x0869F670
