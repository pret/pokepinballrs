	.include "sound/MPlayDef.s"

	.equ	mus_unk_14_grp, gUnknown_0852DDE0
	.equ	mus_unk_14_pri, 0
	.equ	mus_unk_14_rev, reverb_set+50
	.equ	mus_unk_14_mvl, 127
	.equ	mus_unk_14_key, 0
	.equ	mus_unk_14_tbs, 1
	.equ	mus_unk_14_exg, 0
	.equ	mus_unk_14_cmp, 1

	.section .rodata
	.global	mus_unk_14
	.align	2

@*********************** Track 01 ***********************@

mus_unk_14_0:  @ 0x0868E87C
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte	TEMPO , 190*mus_unk_14_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 02 ***********************@

mus_unk_14_1:  @ 0x0868E8B1
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte		VOICE , 46
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 03 ***********************@

mus_unk_14_2:  @ 0x0868E8E3
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte	W24
	.byte	FINE

@*********************** Track 04 ***********************@

mus_unk_14_3:  @ 0x0868E909
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte		VOICE , 82
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 05 ***********************@

mus_unk_14_4:  @ 0x0868E941
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte		VOICE , 83
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@*********************** Track 06 ***********************@

mus_unk_14_5:  @ 0x0868E979
	.byte	KEYSH , mus_unk_14_key+0
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v+24
	.byte		VOL   , 76*mus_unk_14_mvl/mxv
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
	.byte		VOL   , 69*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        61*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		        34*mus_unk_14_mvl/mxv
	.byte	W05
	.byte		        12*mus_unk_14_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

mus_unk_14:  @ 0x0868E9AC
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_unk_14_pri	@ Priority
	.byte	mus_unk_14_rev	@ Reverb

	.word	mus_unk_14_grp

	.word	mus_unk_14_0
	.word	mus_unk_14_1
	.word	mus_unk_14_2
	.word	mus_unk_14_3
	.word	mus_unk_14_4
	.word	mus_unk_14_5
