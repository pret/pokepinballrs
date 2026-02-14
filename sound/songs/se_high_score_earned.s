	.include "sound/MPlayDef.s"

	.equ	se_high_score_earned_grp, gUnknown_0852DDE0
	.equ	se_high_score_earned_pri, 5
	.equ	se_high_score_earned_rev, reverb_set+50
	.equ	se_high_score_earned_mvl, 127
	.equ	se_high_score_earned_key, 0
	.equ	se_high_score_earned_tbs, 1
	.equ	se_high_score_earned_exg, 0
	.equ	se_high_score_earned_cmp, 1

	.section .rodata
	.global	se_high_score_earned
	.align	2

@*********************** Track 01 ***********************@

se_high_score_earned_0:  @ 0x086A3260
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte	TEMPO , 190*se_high_score_earned_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N16   , Gs4 , v080
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N06   , Ds4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N48   , Gs4 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 02 ***********************@

se_high_score_earned_1:  @ 0x086A3295
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte		VOICE , 46
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N16   , Cn5 , v104
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N06
	.byte	W08
	.byte		N06
	.byte	W08
	.byte		N06
	.byte	W08
	.byte		N08   , Cs5 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N48   , Cn5 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 03 ***********************@

se_high_score_earned_2:  @ 0x086A32C7
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		N16   , Gs1 , v120
	.byte	W24
	.byte		N06
	.byte	W08
	.byte		N06
	.byte	W08
	.byte		N06
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		        Gn1 
	.byte	W16
	.byte		N48   , Gs1 
	.byte	W24
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte	W24
	.byte	FINE

@*********************** Track 04 ***********************@

se_high_score_earned_3:  @ 0x086A32ED
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte		VOICE , 82
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v-48
	.byte		N16   , Cn4 , v036
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N06   , Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , As3 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N48   , Gs3 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 05 ***********************@

se_high_score_earned_4:  @ 0x086A3325
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte		VOICE , 83
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		N16   , Gs3 , v036
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N06   , Ds3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N48   , Ds3 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 06 ***********************@

se_high_score_earned_5:  @ 0x086A335D
	.byte	KEYSH , se_high_score_earned_key+0
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v+24
	.byte		VOL   , 80*se_high_score_earned_mvl/mxv
	.byte		N16   , Ds4 , v080
	.byte	W08
	.byte		MOD   , 5
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N06   , Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N08
	.byte	W16
	.byte		N48   , Ds4 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 73*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        64*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		        36*se_high_score_earned_mvl/mxv
	.byte	W05
	.byte		        13*se_high_score_earned_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_high_score_earned:  @ 0x086A3390
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_high_score_earned_pri	@ Priority
	.byte	se_high_score_earned_rev	@ Reverb

	.word	se_high_score_earned_grp

	.word	se_high_score_earned_0
	.word	se_high_score_earned_1
	.word	se_high_score_earned_2
	.word	se_high_score_earned_3
	.word	se_high_score_earned_4
	.word	se_high_score_earned_5
@ 0x086A33B0
