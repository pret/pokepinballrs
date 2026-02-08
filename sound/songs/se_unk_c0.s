	.include "sound/MPlayDef.s"

	.equ	se_unk_c0_grp, gUnknown_08531D4C
	.equ	se_unk_c0_pri, 5
	.equ	se_unk_c0_rev, reverb_set+50
	.equ	se_unk_c0_mvl, 127
	.equ	se_unk_c0_key, 0
	.equ	se_unk_c0_tbs, 1
	.equ	se_unk_c0_exg, 0
	.equ	se_unk_c0_cmp, 1

	.section .rodata
	.global	se_unk_c0
	.align	2

@*********************** Track 01 ***********************@

se_unk_c0_0:  @ 0x086A06A4
	.byte	KEYSH , se_unk_c0_key+0
	.byte	TEMPO , 240*se_unk_c0_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_unk_c0_mvl/mxv
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

se_unk_c0:  @ 0x086A06D0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c0_pri	@ Priority
	.byte	se_unk_c0_rev	@ Reverb

	.word	se_unk_c0_grp

	.word	se_unk_c0_0
@ 0x086A06DC
