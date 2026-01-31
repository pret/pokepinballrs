	.include "sound/MPlayDef.s"

	.equ	se_unk_149_grp, gUnknown_0853174C
	.equ	se_unk_149_pri, 5
	.equ	se_unk_149_rev, reverb_set+50
	.equ	se_unk_149_mvl, 127
	.equ	se_unk_149_key, 0
	.equ	se_unk_149_tbs, 1
	.equ	se_unk_149_exg, 0
	.equ	se_unk_149_cmp, 1

	.section .rodata
	.global	se_unk_149
	.align	2

@*********************** Track 01 ***********************@

se_unk_149_0:  @ 0x086A3230
	.byte	KEYSH , se_unk_149_key+0
	.byte	TEMPO , 150*se_unk_149_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 120*se_unk_149_mvl/mxv
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W08
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_unk_149:  @ 0x086A3254
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_149_pri	@ Priority
	.byte	se_unk_149_rev	@ Reverb

	.word	se_unk_149_grp

	.word	se_unk_149_0
@ 0x086A3260
