	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_re_grp, gUnknown_08531D4C
	.equ	se_pika_charge_re_pri, 5
	.equ	se_pika_charge_re_rev, reverb_set+50
	.equ	se_pika_charge_re_mvl, 127
	.equ	se_pika_charge_re_key, 0
	.equ	se_pika_charge_re_tbs, 1
	.equ	se_pika_charge_re_exg, 0
	.equ	se_pika_charge_re_cmp, 1

	.section .rodata
	.global	se_pika_charge_re
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_re_0:  @ 0x086A00CC
	.byte	KEYSH , se_pika_charge_re_key+0
	.byte	TEMPO , 150*se_pika_charge_re_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_re_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Dn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Dn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_re_1:  @ 0x086A00E0
	.byte	KEYSH , se_pika_charge_re_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_re_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , An5 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , An5 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_re:  @ 0x086A00F4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_re_pri	@ Priority
	.byte	se_pika_charge_re_rev	@ Reverb

	.word	se_pika_charge_re_grp

	.word	se_pika_charge_re_0
	.word	se_pika_charge_re_1
@ 0x086A0104
