	.include "sound/MPlayDef.s"

	.equ	se_unk_103_grp, gUnknown_08531D4C
	.equ	se_unk_103_pri, 5
	.equ	se_unk_103_rev, reverb_set+50
	.equ	se_unk_103_mvl, 127
	.equ	se_unk_103_key, 0
	.equ	se_unk_103_tbs, 1
	.equ	se_unk_103_exg, 0
	.equ	se_unk_103_cmp, 1

	.section .rodata
	.global	se_unk_103
	.align	2

@*********************** Track 01 ***********************@

se_unk_103_0:  @ 0x086A1CDC
	.byte	KEYSH , se_unk_103_key+0
	.byte	TEMPO , 150*se_unk_103_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_103_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+2
	.byte		N54   , Dn4 , v080
	.byte	W12
	.byte		PAN   , c_v-4
	.byte	W12
	.byte		        c_v-10
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W06
	.byte		PAN   , c_v+6
	.byte	W12
	.byte		        c_v+9
	.byte	W12
	.byte		        c_v+5
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-4
	.byte		N54   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-10
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+6
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W06
	.byte		PAN   , c_v+9
	.byte	W12
	.byte		        c_v+5
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_103_1:  @ 0x086A1D1F
	.byte	KEYSH , se_unk_103_key+0
	.byte		VOICE , 62
	.byte		BENDR , 44
	.byte		VOL   , 110*se_unk_103_mvl/mxv
	.byte		MOD   , 30
	.byte		PAN   , c_v+1
	.byte		BEND  , c_v+1
	.byte		N24   , Dn4 , v040
	.byte	W24
	.byte	W02
	.byte		PAN   , c_v+47
	.byte		N24   , Dn4 , v032
	.byte	W22
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v040
	.byte	W18
	.byte	W08
	.byte		PAN   , c_v-49
	.byte		N24   , Cn4 , v032
	.byte	W16
	.byte	W12
	.byte		PAN   , c_v+1
	.byte		N24   , Dn4 , v040
	.byte	W12
	.byte	W14
	.byte		PAN   , c_v+47
	.byte		N24   , Dn4 , v032
	.byte	W10
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v040
	.byte	W06
	.byte	W20
	.byte		PAN   , c_v-48
	.byte		N24   , Cn4 , v032
	.byte	W04
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unk_103:  @ 0x086A1D64
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_103_pri	@ Priority
	.byte	se_unk_103_rev	@ Reverb

	.word	se_unk_103_grp

	.word	se_unk_103_0
	.word	se_unk_103_1
@ 0x086A1D74
