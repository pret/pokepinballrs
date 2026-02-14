	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_ti_grp, gUnknown_08531D4C
	.equ	se_pika_charge_ti_pri, 5
	.equ	se_pika_charge_ti_rev, reverb_set+50
	.equ	se_pika_charge_ti_mvl, 127
	.equ	se_pika_charge_ti_key, 0
	.equ	se_pika_charge_ti_tbs, 1
	.equ	se_pika_charge_ti_exg, 0
	.equ	se_pika_charge_ti_cmp, 1

	.section .rodata
	.global	se_pika_charge_ti
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_ti_0:  @ 0x086A01E4
	.byte	KEYSH , se_pika_charge_ti_key+0
	.byte	TEMPO , 150*se_pika_charge_ti_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_ti_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Bn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Bn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_ti_1:  @ 0x086A01F8
	.byte	KEYSH , se_pika_charge_ti_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_ti_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Fs6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Fs6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_ti:  @ 0x086A020C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_ti_pri	@ Priority
	.byte	se_pika_charge_ti_rev	@ Reverb

	.word	se_pika_charge_ti_grp

	.word	se_pika_charge_ti_0
	.word	se_pika_charge_ti_1
@ 0x086A021C
