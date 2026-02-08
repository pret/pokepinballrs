	.include "sound/MPlayDef.s"

	.equ	mus_success3_grp, gUnknown_0852DDE0
	.equ	mus_success3_pri, 0
	.equ	mus_success3_rev, reverb_set+50
	.equ	mus_success3_mvl, 127
	.equ	mus_success3_key, 0
	.equ	mus_success3_tbs, 1
	.equ	mus_success3_exg, 0
	.equ	mus_success3_cmp, 1

	.section .rodata
	.global	mus_success3
	.align	2

@*********************** Track 01 ***********************@

mus_success3_0:  @ 0x0869B258
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte	TEMPO , 150*mus_success3_tbs/2
	.byte		VOICE , 56
	.byte		PAN   , c_v+18
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N22   , Ds4 , v092
	.byte	W16
	.byte		VOL   , 57*mus_success3_mvl/mxv
	.byte	W04
	.byte		        31*mus_success3_mvl/mxv
	.byte	W04
	.byte		        76*mus_success3_mvl/mxv
	.byte		N22   , Cn4 
	.byte	W16
	.byte		VOL   , 57*mus_success3_mvl/mxv
	.byte	W04
	.byte		        31*mus_success3_mvl/mxv
	.byte	W04
	.byte		        76*mus_success3_mvl/mxv
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N06   , Ds3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N48   , Gs4 
	.byte	W16
	.byte		MOD   , 6
	.byte	W32
	.byte		        0
	.byte	W24
	.byte	FINE

@*********************** Track 02 ***********************@

mus_success3_1:  @ 0x0869B298
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v-16
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N22   , Cn5 , v100
	.byte	W16
	.byte		VOL   , 57*mus_success3_mvl/mxv
	.byte	W04
	.byte		        31*mus_success3_mvl/mxv
	.byte	W04
	.byte		        76*mus_success3_mvl/mxv
	.byte		N22   , Gs4 
	.byte	W16
	.byte		VOL   , 57*mus_success3_mvl/mxv
	.byte	W04
	.byte		        31*mus_success3_mvl/mxv
	.byte	W04
	.byte		        76*mus_success3_mvl/mxv
	.byte		N40   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W28
	.byte		VOL   , 57*mus_success3_mvl/mxv
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 31*mus_success3_mvl/mxv
	.byte	W04
	.byte		        76*mus_success3_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N48   , Cn5 
	.byte	W16
	.byte		MOD   , 6
	.byte	W32
	.byte		        0
	.byte	W24
	.byte	FINE

@*********************** Track 03 ***********************@

mus_success3_2:  @ 0x0869B2D9
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 88
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N12   , Ds1 , v080
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N24   , As1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		N40   , Cn2 
	.byte	W48
	.byte	W24
	.byte	FINE

@*********************** Track 04 ***********************@

mus_success3_3:  @ 0x0869B2F9
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v-48
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N08   , Gs4 , v040
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N48   , Ds3 
	.byte	W16
	.byte		MOD   , 6
	.byte	W32
	.byte		        0
	.byte	W24
	.byte	FINE

@*********************** Track 05 ***********************@

mus_success3_4:  @ 0x0869B334
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 83
	.byte		PAN   , c_v+48
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte	W04
	.byte		N08   , Gs4 , v040
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte	W04
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W04
	.byte	W04
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N44   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W32
	.byte		        0
	.byte	W24
	.byte	FINE

@*********************** Track 06 ***********************@

mus_success3_5:  @ 0x0869B372
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte	W24
	.byte		        76*mus_success3_mvl/mxv
	.byte	W56
	.byte		N08   , Cn2 , v127
	.byte	W08
	.byte		N08
	.byte	W08
	.byte		        Fs2 
	.byte	W24
	.byte		        Cs2 
	.byte	W08
	.byte		        As1 , v112
	.byte	W08
	.byte		N08
	.byte	W08
	.byte		N12   , Cn2 , v127
	.byte	W48
	.byte	W24
	.byte	FINE

@*********************** Track 07 ***********************@

mus_success3_6:  @ 0x0869B391
	.byte	KEYSH , mus_success3_key+0
	.byte	W12
	.byte		VOICE , 0
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N04   , En1 , v112
	.byte		N80   , An2 , v120
	.byte	W24
	.byte		VOL   , 76*mus_success3_mvl/mxv
	.byte		N04   , En1 , v112
	.byte	W08
	.byte		        En1 , v092
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v092
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v092
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v092
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v092
	.byte	W04
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v092
	.byte	W04
	.byte		N04
	.byte	W04
	.byte		        En1 , v112
	.byte	W48
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

mus_success3:  @ 0x0869B3D4
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_success3_pri	@ Priority
	.byte	mus_success3_rev	@ Reverb

	.word	mus_success3_grp

	.word	mus_success3_0
	.word	mus_success3_1
	.word	mus_success3_2
	.word	mus_success3_3
	.word	mus_success3_4
	.word	mus_success3_5
	.word	mus_success3_6
@ 0x0869B3F8
