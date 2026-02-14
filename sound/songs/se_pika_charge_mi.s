	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_mi_grp, gUnknown_08531D4C
	.equ	se_pika_charge_mi_pri, 5
	.equ	se_pika_charge_mi_rev, reverb_set+50
	.equ	se_pika_charge_mi_mvl, 127
	.equ	se_pika_charge_mi_key, 0
	.equ	se_pika_charge_mi_tbs, 1
	.equ	se_pika_charge_mi_exg, 0
	.equ	se_pika_charge_mi_cmp, 1

	.section .rodata
	.global	se_pika_charge_mi
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_mi_0:  @ 0x086A0104
	.byte	KEYSH , se_pika_charge_mi_key+0
	.byte	TEMPO , 150*se_pika_charge_mi_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_mi_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , En5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , En5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_mi_1:  @ 0x086A0118
	.byte	KEYSH , se_pika_charge_mi_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_mi_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Bn5 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Bn5 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_mi:  @ 0x086A012C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_mi_pri	@ Priority
	.byte	se_pika_charge_mi_rev	@ Reverb

	.word	se_pika_charge_mi_grp

	.word	se_pika_charge_mi_0
	.word	se_pika_charge_mi_1
@ 0x086A013C
