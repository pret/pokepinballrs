	.include "sound/MPlayDef.s"

	.equ	se_unk_e8_grp, gUnknown_08531D4C
	.equ	se_unk_e8_pri, 5
	.equ	se_unk_e8_rev, reverb_set+50
	.equ	se_unk_e8_mvl, 127
	.equ	se_unk_e8_key, 0
	.equ	se_unk_e8_tbs, 1
	.equ	se_unk_e8_exg, 0
	.equ	se_unk_e8_cmp, 1

	.section .rodata
	.global	se_unk_e8
	.align	2

@*********************** Track 01 ***********************@

se_unk_e8_0:  @ 0x086A1294
	.byte	KEYSH , se_unk_e8_key+0
	.byte	TEMPO , 220*se_unk_e8_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 100*se_unk_e8_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		PAN   , c_v-9
	.byte		N03   , Cn4 , v080
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N03   , Cn4 , v072
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn4 , v060
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v052
	.byte	W18
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_e8_1:  @ 0x086A12C5
	.byte	KEYSH , se_unk_e8_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_unk_e8_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v072
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v068
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v064
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v060
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v056
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v048
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e8:  @ 0x086A12F0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e8_pri	@ Priority
	.byte	se_unk_e8_rev	@ Reverb

	.word	se_unk_e8_grp

	.word	se_unk_e8_0
	.word	se_unk_e8_1
@ 0x086A1300
