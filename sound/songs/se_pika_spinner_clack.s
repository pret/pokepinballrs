	.include "sound/MPlayDef.s"

	.equ	se_pika_spinner_clack_grp, gUnknown_08531D4C
	.equ	se_pika_spinner_clack_pri, 5
	.equ	se_pika_spinner_clack_rev, reverb_set+50
	.equ	se_pika_spinner_clack_mvl, 127
	.equ	se_pika_spinner_clack_key, 0
	.equ	se_pika_spinner_clack_tbs, 1
	.equ	se_pika_spinner_clack_exg, 0
	.equ	se_pika_spinner_clack_cmp, 1

	.section .rodata
	.global	se_pika_spinner_clack
	.align	2

@*********************** Track 01 ***********************@

se_pika_spinner_clack_0:  @ 0x0869F228
	.byte	KEYSH , se_pika_spinner_clack_key+0
	.byte	TEMPO , 150*se_pika_spinner_clack_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 95*se_pika_spinner_clack_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W03
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_pika_spinner_clack:  @ 0x0869F240
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pika_spinner_clack_pri	@ Priority
	.byte	se_pika_spinner_clack_rev	@ Reverb

	.word	se_pika_spinner_clack_grp

	.word	se_pika_spinner_clack_0
@ 0x0869F24C
