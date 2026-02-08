	.include "sound/MPlayDef.s"

	.equ	mus_egg_mode_grp, gUnknown_0853075C
	.equ	mus_egg_mode_pri, 0
	.equ	mus_egg_mode_rev, reverb_set+50
	.equ	mus_egg_mode_mvl, 127
	.equ	mus_egg_mode_key, 0
	.equ	mus_egg_mode_tbs, 1
	.equ	mus_egg_mode_exg, 0
	.equ	mus_egg_mode_cmp, 1

	.section .rodata
	.global	mus_egg_mode
	.align	2

@*********************** Track 01 ***********************@

mus_egg_mode_0:  @ 0x0868E9CC
	.byte	KEYSH , mus_egg_mode_key+0
	.byte	TEMPO , 134*mus_egg_mode_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_egg_mode_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		        En5 , v060
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v060
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W03
	.byte		        En5 , v072
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v112
	.byte	W48
	.byte		N03
	.byte	W12
	.byte		        En5 , v068
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
mus_egg_mode_0_B1:
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v088
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v088
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		        En5 , v096
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		N03
	.byte	W06
	.byte		        En5 , v088
	.byte	W24
	.byte		        En5 , v112
	.byte	W03
	.byte		        En5 , v088
	.byte	W03
	.byte		        En5 , v084
	.byte	W06
	.byte		N03
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		N03
	.byte	W12
	.byte	GOTO
	 .word	mus_egg_mode_0_B1
	.byte	FINE

@*********************** Track 02 ***********************@

mus_egg_mode_1:  @ 0x0868EA77
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_egg_mode_mvl/mxv
	.byte	W96
	.byte	W24
	.byte		N06   , Gn5 , v096
	.byte	W72
mus_egg_mode_1_B1:
	.byte	W96
	.byte	W36
	.byte		N06   , Gn5 , v080
	.byte	W48
	.byte		        Gn5 , v096
	.byte	W12
	.byte	W84
	.byte		        Gn5 , v084
	.byte	W12
	.byte	W36
	.byte		N06
	.byte	W60
	.byte	GOTO
	 .word	mus_egg_mode_1_B1
	.byte	FINE

@*********************** Track 03 ***********************@

mus_egg_mode_2:  @ 0x0868EA9D
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*mus_egg_mode_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v+0
	.byte	W92
	.byte	W01
	.byte		N54   , Dn1 , v112
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
mus_egg_mode_2_B1:
	.byte		N24   , Gn1 , v112
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N36   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N36   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Fs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	GOTO
	 .word	mus_egg_mode_2_B1
	.byte	FINE

@*********************** Track 04 ***********************@

mus_egg_mode_3:  @ 0x0868EB3D
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v-35
	.byte		VOL   , 39*mus_egg_mode_mvl/mxv
	.byte		N06   , An3 , v112
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N60   , An3 
	.byte	W60
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
mus_egg_mode_3_B1:
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N03   , Dn3 , v068
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N03
	.byte	W12
	.byte		N03
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		N24   , Cn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		N24   , Dn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W24
	.byte		N03   , An1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N24   , Fs2 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte	GOTO
	 .word	mus_egg_mode_3_B1
	.byte	FINE

@*********************** Track 05 ***********************@

mus_egg_mode_4:  @ 0x0868EBE5
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		VOL   , 47*mus_egg_mode_mvl/mxv
	.byte	W12
	.byte		N03   , Cs5 , v112
	.byte	W24
	.byte		N03
	.byte	W60
	.byte	W96
mus_egg_mode_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W36
	.byte		N03   , Cs4 , v112
	.byte	W24
	.byte		        Cs5 , v080
	.byte	W36
	.byte	GOTO
	 .word	mus_egg_mode_4_B1
	.byte	FINE

@*********************** Track 06 ***********************@

mus_egg_mode_5:  @ 0x0868EC06
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 47*mus_egg_mode_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Dn3 
	.byte		N06   , Gn4 
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N60   , Dn4 
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
mus_egg_mode_5_B1:
	.byte		N24   , Bn3 , v112
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N36   , Cn4 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N24   , Bn3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W24
	.byte		N03   , Dn2 , v080
	.byte		N06   , Dn5 
	.byte	W03
	.byte		N03   , Fs2 , v112
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N24   , Dn3 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte	GOTO
	 .word	mus_egg_mode_5_B1
	.byte	FINE

@*********************** Track 07 ***********************@

mus_egg_mode_6:  @ 0x0868ECC6
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 34*mus_egg_mode_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N36   , Dn3 
	.byte	W72
mus_egg_mode_6_B1:
	.byte		PAN   , c_v+0
	.byte		N03   , Dn3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
mus_egg_mode_6_B2:
	.byte		N03   , Cn3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PATT
	 .word	mus_egg_mode_6_B2
	.byte	GOTO
	 .word	mus_egg_mode_6_B1
	.byte	FINE

@*********************** Track 08 ***********************@

mus_egg_mode_7:  @ 0x0868ED3D
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*mus_egg_mode_mvl/mxv
	.byte	W96
	.byte		N03   , Fs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , An3 
	.byte	W72
mus_egg_mode_7_B1:
	.byte		PAN   , c_v+63
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N03   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
mus_egg_mode_7_B2:
	.byte		PAN   , c_v+63
	.byte		N03   , An3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Fn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N03   , Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_7_B1
	.byte	PATT
	 .word	mus_egg_mode_7_B2
	.byte	GOTO
	 .word	mus_egg_mode_7_B1
	.byte	FINE

@*********************** Track 09 ***********************@

mus_egg_mode_8:  @ 0x0868EDB6
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 0
	.byte		VOL   , 49*mus_egg_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn3 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W72
mus_egg_mode_8_B1:
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W36
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W12
	.byte	PEND
	.byte		        En3 
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W36
	.byte		N06
	.byte	W36
	.byte	PATT
	 .word	mus_egg_mode_8_B1
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W12
	.byte	GOTO
	 .word	mus_egg_mode_8_B1
	.byte	FINE

@*********************** Track 10 ***********************@

mus_egg_mode_9:  @ 0x0868EE11
	.byte	KEYSH , mus_egg_mode_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		VOL   , 23*mus_egg_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Dn3 
	.byte		N06   , Gn4 
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N60   , Dn4 
	.byte	W60
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
mus_egg_mode_9_B1:
	.byte		N06   , Bn3 , v112
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W12
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W24
	.byte		N03   , Dn2 
	.byte		N06   , Dn5 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W24
	.byte	GOTO
	 .word	mus_egg_mode_9_B1
	.byte	FINE

@******************************************************@

	.align	2

mus_egg_mode:  @ 0x0868EEAC
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_egg_mode_pri	@ Priority
	.byte	mus_egg_mode_rev	@ Reverb

	.word	mus_egg_mode_grp

	.word	mus_egg_mode_0
	.word	mus_egg_mode_1
	.word	mus_egg_mode_2
	.word	mus_egg_mode_3
	.word	mus_egg_mode_4
	.word	mus_egg_mode_5
	.word	mus_egg_mode_6
	.word	mus_egg_mode_7
	.word	mus_egg_mode_8
	.word	mus_egg_mode_9
