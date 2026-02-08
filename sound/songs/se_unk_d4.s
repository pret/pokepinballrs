	.include "sound/MPlayDef.s"

	.equ	se_unk_d4_grp, gUnknown_08531D4C
	.equ	se_unk_d4_pri, 5
	.equ	se_unk_d4_rev, reverb_set+50
	.equ	se_unk_d4_mvl, 127
	.equ	se_unk_d4_key, 0
	.equ	se_unk_d4_tbs, 1
	.equ	se_unk_d4_exg, 0
	.equ	se_unk_d4_cmp, 1

	.section .rodata
	.global	se_unk_d4
	.align	2

@*********************** Track 01 ***********************@

se_unk_d4_0:  @ 0x086A0D04
	.byte	KEYSH , se_unk_d4_key+0
	.byte	TEMPO , 150*se_unk_d4_tbs/2
	.byte		VOICE , 31
	.byte		VOL   , 110*se_unk_d4_mvl/mxv
	.byte		BENDR , 24
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N06   , Gn0 , v127
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+46
	.byte	W02
	.byte		VOICE , 23
	.byte		PAN   , c_v+11
	.byte		N01   , Cn1 
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		N01   , Cn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-37
	.byte		N06   , Dn1 
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v-1
	.byte		N01   , Fn1 
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		N01   , Fn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N02   , Gn0 
	.byte	W02
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+27
	.byte		N02
	.byte	W01
	.byte		BEND  , c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v+10
	.byte		N01   , Cn1 
	.byte	W02
	.byte		PAN   , c_v-9
	.byte		N01   , Cn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N06   , Dn1 
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+27
	.byte	W02
	.byte		        c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v+5
	.byte		N01   , Cn1 
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		N01   , Cn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N06   , Gn0 , v112
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v+11
	.byte		N01   , Cn1 , v100
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		N01   , Cn2 , v096
	.byte	W02
	.byte		VOICE , 31
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-37
	.byte		N06   , Dn1 
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+46
	.byte	W02
	.byte		VOICE , 23
	.byte		PAN   , c_v-1
	.byte		N01   , Fn1 , v084
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		N01   , Fn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N02   , Gn0 , v080
	.byte	W01
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+27
	.byte		N02   , Gn0 , v072
	.byte	W01
	.byte		BEND  , c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v+10
	.byte		N01   , Cn1 , v068
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		N01   , Cn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-37
	.byte		N06   , Dn1 , v064
	.byte	W02
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v+5
	.byte		N01   , Cn1 , v056
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		N01   , Cn2 , v052
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_d4:  @ 0x086A0E14
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_d4_pri	@ Priority
	.byte	se_unk_d4_rev	@ Reverb

	.word	se_unk_d4_grp

	.word	se_unk_d4_0
@ 0x086A0E20
