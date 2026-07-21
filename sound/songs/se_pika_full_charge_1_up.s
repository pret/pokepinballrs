	.include "sound/MPlayDef.s"

	.equ	se_pika_full_charge_1_up_grp, gUnknown_08532310
	.equ	se_pika_full_charge_1_up_pri, 5
	.equ	se_pika_full_charge_1_up_rev, reverb_set+50
	.equ	se_pika_full_charge_1_up_mvl, 127
	.equ	se_pika_full_charge_1_up_key, 0
	.equ	se_pika_full_charge_1_up_tbs, 1
	.equ	se_pika_full_charge_1_up_exg, 0
	.equ	se_pika_full_charge_1_up_cmp, 1

	.section .rodata
	.global	se_pika_full_charge_1_up
	.align	2

@*********************** Track 01 ***********************@

se_pika_full_charge_1_up_0:  @ 0x0869F24C
	.byte	KEYSH , se_pika_full_charge_1_up_key+0
	.byte	TEMPO , 150*se_pika_full_charge_1_up_tbs/2
	.byte		VOL   , 80*se_pika_full_charge_1_up_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 12
	.byte		N03   , An5 , v127
	.byte	W03
	.byte		N03   , An6 , v127
	.byte	W03
	.byte		N03   , An5 , v115
	.byte	W03
	.byte		N03   , An6 , v115
	.byte	W03
	.byte		N03   , An5 , v100
	.byte	W03
	.byte		N03   , An6 , v100
	.byte	W03
	.byte		N03   , An5 , v095
	.byte	W03
	.byte		N03   , An6 , v095
	.byte	W03
	.byte		N03   , An5 , v070
	.byte	W03
	.byte		N03   , An6 , v070
	.byte	W03
	.byte		N03   , An5 , v055
	.byte	W03
	.byte		N03   , An6 , v055
	.byte	W03
	.byte		N03   , An5 , v040
	.byte	W03
	.byte		N03   , An6 , v040
	.byte	W03
	.byte		N03   , An5 , v025
	.byte	W03
	.byte		N03   , An6 , v025
	.byte	W03
	.byte		N03   , An5 , v010
	.byte	W03
	.byte		N03   , An6 , v010
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_pika_full_charge_1_up:  @ 0x0869F2A0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_full_charge_1_up_pri	@ Priority
	.byte	se_pika_full_charge_1_up_rev	@ Reverb

	.word	se_pika_full_charge_1_up_grp

	.word	se_pika_full_charge_1_up_0
@ 0x0869F2AC
