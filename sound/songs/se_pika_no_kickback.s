	.include "sound/MPlayDef.s"

	.equ	se_pika_no_kickback_grp, gUnknown_08532310
	.equ	se_pika_no_kickback_pri, 5
	.equ	se_pika_no_kickback_rev, reverb_set+50
	.equ	se_pika_no_kickback_mvl, 127
	.equ	se_pika_no_kickback_key, 0
	.equ	se_pika_no_kickback_tbs, 1
	.equ	se_pika_no_kickback_exg, 0
	.equ	se_pika_no_kickback_cmp, 1

	.section .rodata
	.global	se_pika_no_kickback
	.align	2

@*********************** Track 01 ***********************@

se_pika_no_kickback_0:  @ 0x086A2F90
	.byte	KEYSH , se_pika_no_kickback_key+0
	.byte	TEMPO , 150*se_pika_no_kickback_tbs/2
	.byte		VOL   , 127*se_pika_no_kickback_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 102
	.byte		TIE   , Cn3 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_pika_no_kickback:  @ 0x086A2FA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_no_kickback_pri	@ Priority
	.byte	se_pika_no_kickback_rev	@ Reverb

	.word	se_pika_no_kickback_grp

	.word	se_pika_no_kickback_0
@ 0x086A2FAC
