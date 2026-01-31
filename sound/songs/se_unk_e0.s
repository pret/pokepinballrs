	.include "sound/MPlayDef.s"

	.equ	se_unk_e0_grp, gUnknown_08531D4C
	.equ	se_unk_e0_pri, 5
	.equ	se_unk_e0_rev, reverb_set+50
	.equ	se_unk_e0_mvl, 127
	.equ	se_unk_e0_key, 0
	.equ	se_unk_e0_tbs, 1
	.equ	se_unk_e0_exg, 0
	.equ	se_unk_e0_cmp, 1

	.section .rodata
	.global	se_unk_e0
	.align	2

@*********************** Track 01 ***********************@

se_unk_e0_0:  @ 0x086A1028
	.byte	KEYSH , se_unk_e0_key+0
	.byte	TEMPO , 150*se_unk_e0_tbs/2
	.byte		VOICE , 10
	.byte		VOL   , 127*se_unk_e0_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Cs3 , v127
	.byte	W09
	.byte		BEND  , c_v-9
	.byte	W09
	.byte		        c_v-18
	.byte	W06
	.byte	W09
	.byte		        c_v-26
	.byte	W09
	.byte		        c_v-34
	.byte	W06
	.byte	W06
	.byte		        c_v-43
	.byte	W05
	.byte		VOL   , 123*se_unk_e0_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v-54
	.byte	W02
	.byte		VOL   , 117*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		        110*se_unk_e0_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-64
	.byte	W08
	.byte		VOL   , 101*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		        89*se_unk_e0_mvl/mxv
	.byte	W09
	.byte		        77*se_unk_e0_mvl/mxv
	.byte	W01
	.byte	W05
	.byte		        60*se_unk_e0_mvl/mxv
	.byte	W09
	.byte		        48*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		        36*se_unk_e0_mvl/mxv
	.byte	W04
	.byte	W03
	.byte		        23*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		        8*se_unk_e0_mvl/mxv
	.byte	W09
	.byte		        0*se_unk_e0_mvl/mxv
	.byte	W01
	.byte		EOT
	.byte	W05
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_e0_1:  @ 0x086A1069
	.byte	KEYSH , se_unk_e0_key+0
	.byte		VOICE , 13
	.byte		VOL   , 90*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		N09   , Gs6 , v024
	.byte	W18
	.byte	W05
	.byte		N15
	.byte	W19
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@*********************** Track 03 ***********************@

se_unk_e0_2:  @ 0x086A107C
	.byte	KEYSH , se_unk_e0_key+0
	.byte		VOICE , 12
	.byte		VOL   , 90*se_unk_e0_mvl/mxv
	.byte	W06
	.byte		N09   , An6 , v024
	.byte	W18
	.byte	W05
	.byte		N15
	.byte	W19
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_unk_e0:  @ 0x086A1090
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_e0_pri	@ Priority
	.byte	se_unk_e0_rev	@ Reverb

	.word	se_unk_e0_grp

	.word	se_unk_e0_0
	.word	se_unk_e0_1
	.word	se_unk_e0_2
@ 0x086A10A4
