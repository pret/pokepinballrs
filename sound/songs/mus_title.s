	.include "sound/MPlayDef.s"

	.equ	mus_title_grp, gUnknown_0852F55C
	.equ	mus_title_pri, 0
	.equ	mus_title_rev, reverb_set+50
	.equ	mus_title_mvl, 127
	.equ	mus_title_key, 0
	.equ	mus_title_tbs, 1
	.equ	mus_title_exg, 0
	.equ	mus_title_cmp, 1

	.section .rodata
	.global	mus_title
	.align	2

@*********************** Track 01 ***********************@

mus_title_0:  @ 0x08688FFC
	.byte	KEYSH , mus_title_key+0
	.byte	TEMPO , 142*mus_title_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_title_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
mus_title_0_B1:
	.byte		VOICE , 127
	.byte		N04   , En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v092
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04
	.byte	W06
mus_title_0_B2:
	.byte		N04   , En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		        En5 , v096
	.byte	W04
	.byte		        En5 , v064
	.byte	W04
	.byte		N04
	.byte	W04
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04
	.byte	W06
	.byte	PEND
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v092
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04
	.byte	W06
	.byte	PATT
	 .word	mus_title_0_B2
	.byte	GOTO
	 .word	mus_title_0_B1
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_title_1:  @ 0x086890AA
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 70*mus_title_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W12
	.byte	W48
	.byte	W02
	.byte		N22   , Fn3 , v112
	.byte	W22
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Ds4 , v096
	.byte	W24
mus_title_1_B1:
	.byte		VOICE , 11
	.byte		VOL   , 41*mus_title_mvl/mxv
	.byte	W02
	.byte		N44   , Fn4 , v112
	.byte	W48
	.byte		N10   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W10
	.byte	W02
	.byte		N32   , En4 
	.byte	W32
	.byte	W02
	.byte		N07   , Fn4 
	.byte	W14
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W04
	.byte		N08   , Bn3 , v036
	.byte	W08
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		N08   , An3 , v036
	.byte	W06
	.byte	W02
	.byte		N32   , Fn3 , v112
	.byte	W36
	.byte		N10   , Cn4 
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N10   , Fn3 
	.byte	W10
	.byte	W02
	.byte		        En3 
	.byte	W12
	.byte		N04   , Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N07   , Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N22   , Cn5 
	.byte	W22
	.byte		N04   , Bn4 
	.byte	W04
	.byte		N08   , Bn4 , v036
	.byte	W10
	.byte		N04   , An4 , v112
	.byte	W04
	.byte		        An4 , v036
	.byte	W06
	.byte	GOTO
	 .word	mus_title_1_B1
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_title_2:  @ 0x08689136
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 73*mus_title_mvl/mxv
	.byte		PAN   , c_v+14
	.byte	W12
	.byte		N06   , Cn4 , v120
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N04   , Gn4 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Gs4 , v096
	.byte	W24
mus_title_2_B1:
	.byte		VOICE , 1
	.byte		VOL   , 70*mus_title_mvl/mxv
	.byte		N42   , An4 , v112
	.byte	W42
	.byte		N03   , Gn4 , v100
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N10   , Gn4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N03   , Gn4 , v100
	.byte	W03
	.byte		N07   , An4 , v112
	.byte	W09
	.byte		N24   , En4 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N08   , Dn4 , v036
	.byte	W08
	.byte		N04   , Cn4 , v112
	.byte	W04
	.byte		N08   , Cn4 , v036
	.byte	W08
	.byte		N36   , An3 , v112
	.byte	W36
	.byte		N03   , Dn4 , v100
	.byte	W03
	.byte		N09   , En4 , v112
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N10   , Gn3 
	.byte	W12
	.byte		N04   , Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N07   , Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N24   , En5 
	.byte	W24
	.byte		N04   , Dn5 
	.byte	W04
	.byte		N08   , Dn5 , v036
	.byte	W08
	.byte		N04   , Cn5 , v112
	.byte	W04
	.byte		N08   , Cn5 , v036
	.byte	W08
	.byte	GOTO
	 .word	mus_title_2_B1
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_title_3:  @ 0x086891D5
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*mus_title_mvl/mxv
	.byte	W04
	.byte		N02   , Fn2 , v108
	.byte	W04
	.byte		        Fn2 , v092
	.byte	W04
	.byte	W02
	.byte		N04   , Fn2 , v112
	.byte	W36
	.byte	W02
	.byte		N02
	.byte	W04
	.byte		N02
	.byte	W04
	.byte		N04
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Fs1 
	.byte	W24
mus_title_3_B1:
	.byte		VOICE , 48
	.byte		VOL   , 30*mus_title_mvl/mxv
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		        Bn2 
	.byte	W48
mus_title_3_B2:
	.byte		N48   , Gn2 , v112
	.byte	W48
	.byte		N32   , An2 
	.byte	W32
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte	PEND
	.byte		N48   , An2 
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	PATT
	 .word	mus_title_3_B2
	.byte	GOTO
	 .word	mus_title_3_B1
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_title_4:  @ 0x08689232
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 35*mus_title_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W12
	.byte		        An2 , v112
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N48   , Fn3 
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
mus_title_4_B1:
	.byte	W12
	.byte		N04   , An3 , v112
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
mus_title_4_B2:
	.byte	W12
	.byte		N04   , Bn3 , v112
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_title_4_B1
	.byte	PATT
	 .word	mus_title_4_B2
	.byte	GOTO
	 .word	mus_title_4_B1
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_title_5:  @ 0x08689290
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 49*mus_title_mvl/mxv
	.byte	W02
	.byte		        47*mus_title_mvl/mxv
	.byte	W10
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N48   , Fn1 
	.byte	W48
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N04   , Gn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N24
	.byte	W24
	.byte		        Fs1 
	.byte	W24
mus_title_5_B1:
	.byte		N04   , Fn1 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
mus_title_5_B2:
	.byte		N04   , En1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_title_5_B1
	.byte	PATT
	 .word	mus_title_5_B2
	.byte	GOTO
	 .word	mus_title_5_B1
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_title_6:  @ 0x086892F4
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 0
	.byte		VOL   , 55*mus_title_mvl/mxv
	.byte	W12
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W96
mus_title_6_B1:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PATT
	 .word	mus_title_6_B1
	.byte		N04   , Dn1 , v088
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W12
	.byte	GOTO
	 .word	mus_title_6_B1
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_title_7:  @ 0x0868933A
	.byte	KEYSH , mus_title_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 35*mus_title_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N24   , Fs5 
	.byte	W24
	.byte	W96
mus_title_7_B1:
	.byte	W12
	.byte		N04   , Cn3 , v112
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
mus_title_7_B2:
	.byte	W12
	.byte		N04   , Dn3 , v112
	.byte	W06
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N04
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_title_7_B1
	.byte	PATT
	 .word	mus_title_7_B2
	.byte	GOTO
	 .word	mus_title_7_B1
	.byte	W96
	.byte	FINE

@*********************** Track 09 ***********************@

mus_title_8:  @ 0x08689388
	.byte	KEYSH , mus_title_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 31*mus_title_mvl/mxv
	.byte	W03
	.byte		VOICE , 46
	.byte	W09
	.byte		PAN   , c_v-40
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		PAN   , c_v+43
	.byte		N04   , Fn6 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-40
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		PAN   , c_v+38
	.byte		N04   , Fs6 
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		PAN   , c_v-7
	.byte		N04   , Fs5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v-38
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-24
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		PAN   , c_v+43
	.byte		N04   , Gn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		PAN   , c_v+13
	.byte		N04   , Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		PAN   , c_v-8
	.byte		N04   , Cn6 
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , Gs5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
mus_title_8_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_title_8_B1
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_title:  @ 0x08689430
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_title_pri	@ Priority
	.byte	mus_title_rev	@ Reverb

	.word	mus_title_grp

	.word	mus_title_0
	.word	mus_title_1
	.word	mus_title_2
	.word	mus_title_3
	.word	mus_title_4
	.word	mus_title_5
	.word	mus_title_6
	.word	mus_title_7
	.word	mus_title_8
