	.include "sound/MPlayDef.s"

	.equ	se_unk_b6_grp, gUnknown_08531D4C
	.equ	se_unk_b6_pri, 5
	.equ	se_unk_b6_rev, reverb_set+50
	.equ	se_unk_b6_mvl, 127
	.equ	se_unk_b6_key, 0
	.equ	se_unk_b6_tbs, 1
	.equ	se_unk_b6_exg, 0
	.equ	se_unk_b6_cmp, 1

	.section .rodata
	.global	se_unk_b6
	.align	2

@*********************** Track 01 ***********************@

se_unk_b6_0:  @ 0x086A03AC
	.byte	KEYSH , se_unk_b6_key+0
	.byte	TEMPO , 240*se_unk_b6_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_unk_b6_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Fn3 , v127
	.byte	W02
	.byte		N01   , Cn4 , v112
	.byte	W02
	.byte		N03   , Fn3 , v052
	.byte	W02
	.byte	W02
	.byte		VOICE , 23
	.byte		N01   , En4 , v092
	.byte	W01
	.byte		        Cn5 
	.byte	W03
	.byte		        Gn3 
	.byte	W01
	.byte		        En4 
	.byte	W02
	.byte		        En3 , v048
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_b6:  @ 0x086A03D8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_b6_pri	@ Priority
	.byte	se_unk_b6_rev	@ Reverb

	.word	se_unk_b6_grp

	.word	se_unk_b6_0
@ 0x086A03E4
