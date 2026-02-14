	.include "sound/MPlayDef.s"

	.equ	se_pika_charge_fa_grp, gUnknown_08531D4C
	.equ	se_pika_charge_fa_pri, 5
	.equ	se_pika_charge_fa_rev, reverb_set+50
	.equ	se_pika_charge_fa_mvl, 127
	.equ	se_pika_charge_fa_key, 0
	.equ	se_pika_charge_fa_tbs, 1
	.equ	se_pika_charge_fa_exg, 0
	.equ	se_pika_charge_fa_cmp, 1

	.section .rodata
	.global	se_pika_charge_fa
	.align	2

@*********************** Track 01 ***********************@

se_pika_charge_fa_0:  @ 0x086A013C
	.byte	KEYSH , se_pika_charge_fa_key+0
	.byte	TEMPO , 150*se_pika_charge_fa_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_pika_charge_fa_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Fn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Fn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_pika_charge_fa_1:  @ 0x086A0150
	.byte	KEYSH , se_pika_charge_fa_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_pika_charge_fa_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Cn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_pika_charge_fa:  @ 0x086A0164
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_charge_fa_pri	@ Priority
	.byte	se_pika_charge_fa_rev	@ Reverb

	.word	se_pika_charge_fa_grp

	.word	se_pika_charge_fa_0
	.word	se_pika_charge_fa_1
@ 0x086A0174
