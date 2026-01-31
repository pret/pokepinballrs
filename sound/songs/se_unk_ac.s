	.include "sound/MPlayDef.s"

	.equ	se_unk_ac_grp, gUnknown_08531D4C
	.equ	se_unk_ac_pri, 5
	.equ	se_unk_ac_rev, reverb_set+50
	.equ	se_unk_ac_mvl, 127
	.equ	se_unk_ac_key, 0
	.equ	se_unk_ac_tbs, 1
	.equ	se_unk_ac_exg, 0
	.equ	se_unk_ac_cmp, 1

	.section .rodata
	.global	se_unk_ac
	.align	2

@*********************** Track 01 ***********************@

se_unk_ac_0:  @ 0x086A0174
	.byte	KEYSH , se_unk_ac_key+0
	.byte	TEMPO , 150*se_unk_ac_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_unk_ac_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Gn5 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_ac_1:  @ 0x086A0188
	.byte	KEYSH , se_unk_ac_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_unk_ac_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Dn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Dn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ac:  @ 0x086A019C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ac_pri	@ Priority
	.byte	se_unk_ac_rev	@ Reverb

	.word	se_unk_ac_grp

	.word	se_unk_ac_0
	.word	se_unk_ac_1
@ 0x086A01AC
