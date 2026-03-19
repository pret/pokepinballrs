	.include "sound/MPlayDef.s"

	.equ	se_pichu_in_position_chirp_grp, gUnknown_08532310
	.equ	se_pichu_in_position_chirp_pri, 5
	.equ	se_pichu_in_position_chirp_rev, reverb_set+50
	.equ	se_pichu_in_position_chirp_mvl, 127
	.equ	se_pichu_in_position_chirp_key, 0
	.equ	se_pichu_in_position_chirp_tbs, 1
	.equ	se_pichu_in_position_chirp_exg, 0
	.equ	se_pichu_in_position_chirp_cmp, 1

	.section .rodata
	.global	se_pichu_in_position_chirp
	.align	2

@*********************** Track 01 ***********************@

se_pichu_in_position_chirp_0:  @ 0x0869F18C
	.byte	KEYSH , se_pichu_in_position_chirp_key+0
	.byte	TEMPO , 150*se_pichu_in_position_chirp_tbs/2
	.byte		VOL   , 90*se_pichu_in_position_chirp_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 23
	.byte		N02   , Fn6 , v127
	.byte	W02
	.byte		N02   , Fn7 , v127
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_pichu_in_position_chirp:  @ 0x0869F1A0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pichu_in_position_chirp_pri	@ Priority
	.byte	se_pichu_in_position_chirp_rev	@ Reverb

	.word	se_pichu_in_position_chirp_grp

	.word	se_pichu_in_position_chirp_0
@ 0x0869F1AC
