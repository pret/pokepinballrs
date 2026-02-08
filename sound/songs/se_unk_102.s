	.include "sound/MPlayDef.s"

	.equ	se_unk_102_grp, gUnknown_08531D4C
	.equ	se_unk_102_pri, 5
	.equ	se_unk_102_rev, reverb_set+50
	.equ	se_unk_102_mvl, 127
	.equ	se_unk_102_key, 0
	.equ	se_unk_102_tbs, 1
	.equ	se_unk_102_exg, 0
	.equ	se_unk_102_cmp, 1

	.section .rodata
	.global	se_unk_102
	.align	2

@*********************** Track 01 ***********************@

se_unk_102_0:  @ 0x086A1C94
	.byte	KEYSH , se_unk_102_key+0
	.byte	TEMPO , 150*se_unk_102_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 100*se_unk_102_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W02
	.byte		N02   , Gn2 
	.byte	W04
	.byte		N17   , Cn3 
	.byte	W06
	.byte		VOL   , 98*se_unk_102_mvl/mxv
	.byte	W01
	.byte		        91*se_unk_102_mvl/mxv
	.byte	W01
	.byte		        81*se_unk_102_mvl/mxv
	.byte	W02
	.byte		        75*se_unk_102_mvl/mxv
	.byte	W01
	.byte		        60*se_unk_102_mvl/mxv
	.byte	W01
	.byte		        42*se_unk_102_mvl/mxv
	.byte	W01
	.byte		        25*se_unk_102_mvl/mxv
	.byte	W02
	.byte		        10*se_unk_102_mvl/mxv
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_102_1:  @ 0x086A1CBA
	.byte		VOL   , 100*se_unk_102_mvl/mxv
	.byte	KEYSH , se_unk_102_key+0
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

se_unk_102:  @ 0x086A1CCC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_102_pri	@ Priority
	.byte	se_unk_102_rev	@ Reverb

	.word	se_unk_102_grp

	.word	se_unk_102_0
	.word	se_unk_102_1
@ 0x086A1CDC
