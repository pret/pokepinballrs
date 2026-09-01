	.include "sound/MPlayDef.s"

	.equ	se_unused_0xbc_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_unused_0xbc_pri, 5
	.equ	se_unused_0xbc_rev, reverb_set+50
	.equ	se_unused_0xbc_mvl, 127
	.equ	se_unused_0xbc_key, 0
	.equ	se_unused_0xbc_tbs, 1
	.equ	se_unused_0xbc_exg, 0
	.equ	se_unused_0xbc_cmp, 1

	.section .rodata
	.global	se_unused_0xbc
	.align	2

@*********************** Track 01 ***********************@

se_unused_0xbc_0:  @ 0x086A0570
	.byte	KEYSH , se_unused_0xbc_key+0
	.byte	TEMPO , 150*se_unused_0xbc_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 100*se_unused_0xbc_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W02
	.byte		N02   , Gn2 
	.byte	W04
	.byte		N17   , Cn3 
	.byte	W06
	.byte		VOL   , 98*se_unused_0xbc_mvl/mxv
	.byte	W01
	.byte		        91*se_unused_0xbc_mvl/mxv
	.byte	W01
	.byte		        81*se_unused_0xbc_mvl/mxv
	.byte	W02
	.byte		        75*se_unused_0xbc_mvl/mxv
	.byte	W01
	.byte		        60*se_unused_0xbc_mvl/mxv
	.byte	W01
	.byte		        42*se_unused_0xbc_mvl/mxv
	.byte	W01
	.byte		        25*se_unused_0xbc_mvl/mxv
	.byte	W02
	.byte		        10*se_unused_0xbc_mvl/mxv
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unused_0xbc_1:  @ 0x086A0596
	.byte		VOL   , 100*se_unused_0xbc_mvl/mxv
	.byte	KEYSH , se_unused_0xbc_key+0
	.byte		VOICE , 4
	.byte		N01   , Cn3 , v064
	.byte	W02
	.byte		N02
	.byte	W04
	.byte		N02
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_unused_0xbc:  @ 0x086A05A8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unused_0xbc_pri	@ Priority
	.byte	se_unused_0xbc_rev	@ Reverb

	.word	se_unused_0xbc_grp

	.word	se_unused_0xbc_0
	.word	se_unused_0xbc_1
@ 0x086A05B8
