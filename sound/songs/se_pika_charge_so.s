	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_so_grp, gUnknown_08531D4C
	.equ	se_pika_charge_so_pri, 5
	.equ	se_pika_charge_so_rev, reverb_set+50
	.equ	se_pika_charge_so_mvl, 127
	.equ	se_pika_charge_so_key, 0
	.equ	se_pika_charge_so_tbs, 1
	.equ	se_pika_charge_so_exg, 0
	.equ	se_pika_charge_so_cmp, 1

	.section .rodata
	.global	se_pika_charge_so
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_so_0:  @ 0x086A0174
	.byte	KEYSH , se_pika_charge_so_key+0
	.byte	TEMPO , 150*se_pika_charge_so_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_so_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Gn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_so_1:  @ 0x086A0188
	.byte	KEYSH , se_pika_charge_so_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_so_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Dn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Dn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_so:  @ 0x086A019C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_so_pri	@ Priority
	.byte	se_pika_charge_so_rev	@ Reverb

	.word	se_pika_charge_so_grp

	.word	se_pika_charge_so_0
	.word	se_pika_charge_so_1
@ 0x086A01AC
