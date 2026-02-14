	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_do_grp, gUnknown_08531D4C
	.equ	se_pika_charge_do_pri, 5
	.equ	se_pika_charge_do_rev, reverb_set+50
	.equ	se_pika_charge_do_mvl, 127
	.equ	se_pika_charge_do_key, 0
	.equ	se_pika_charge_do_tbs, 1
	.equ	se_pika_charge_do_exg, 0
	.equ	se_pika_charge_do_cmp, 1

	.section .rodata
	.global	se_pika_charge_do
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_do_0:  @ 0x086A0094
	.byte	KEYSH , se_pika_charge_do_key+0
	.byte	TEMPO , 150*se_pika_charge_do_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_do_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Cn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_do_1:  @ 0x086A00A8
	.byte	KEYSH , se_pika_charge_do_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_do_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn5 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Gn5 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_do:  @ 0x086A00BC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_do_pri	@ Priority
	.byte	se_pika_charge_do_rev	@ Reverb

	.word	se_pika_charge_do_grp

	.word	se_pika_charge_do_0
	.word	se_pika_charge_do_1
@ 0x086A00CC
