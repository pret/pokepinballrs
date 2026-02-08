	.include "sound/MPlayDef.s"

	.equ	mus_field_ruby_grp, gUnknown_08532808
	.equ	mus_field_ruby_pri, 0
	.equ	mus_field_ruby_rev, reverb_set+50
	.equ	mus_field_ruby_mvl, 127
	.equ	mus_field_ruby_key, 0
	.equ	mus_field_ruby_tbs, 1
	.equ	mus_field_ruby_exg, 0
	.equ	mus_field_ruby_cmp, 1

	.section .rodata
	.global	mus_field_ruby
	.align	2

@*********************** Track 01 ***********************@

mus_field_ruby_0:  @ 0x08691ECC
	.byte	KEYSH , mus_field_ruby_key+0
	.byte	TEMPO , 136*mus_field_ruby_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 86*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N07   , As3 , v096
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N07   , Gs3 
	.byte	W08
	.byte		N08   , Gn3 , v088
	.byte	W08
	.byte		        Fs3 , v084
	.byte	W08
	.byte		N07   , Fn3 , v072
	.byte	W08
	.byte		        En3 , v088
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N09   , Dn3 , v084
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		        Cn3 , v088
	.byte	W08
	.byte		N03   , Bn2 
	.byte	W08
	.byte	W13
	.byte		N24   , Gs2 , v096
	.byte		N32   , As2 , v108
	.byte	W32
	.byte	W01
	.byte		N06   , Cn3 , v088
	.byte	W01
	.byte		N04   , Gs2 , v084
	.byte	W24
	.byte		N05   , Gs2 , v092
	.byte		N06   , Cn3 , v096
	.byte	W24
	.byte		N05   , Gs2 , v104
	.byte		N06   , Cs3 , v108
	.byte	W01
	.byte	W23
	.byte		N07   , Gs2 , v100
	.byte	W01
	.byte		N20   , Cs3 
	.byte	W16
	.byte		N01   , Gs2 
	.byte		N04   , Dn3 , v116
	.byte	W22
	.byte		N11   , As3 , v096
	.byte	W09
	.byte		N12   , As4 , v127
	.byte	W24
	.byte	W01
mus_field_ruby_0_B1:
	.byte		N18   , Gn3 , v124
	.byte	W17
	.byte		N06   , As2 , v112
	.byte	W44
	.byte	W02
	.byte		N05   , As2 , v092
	.byte	W22
	.byte		N07   , As2 , v088
	.byte	W09
	.byte		N17   , Gs3 , v092
	.byte	W02
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W24
	.byte	W01
	.byte		N05   , Fn3 
	.byte	W23
	.byte		N10   , En3 , v100
	.byte	W09
	.byte		N16   , Dn3 , v088
	.byte	W17
	.byte		N07   , En3 , v080
	.byte	W08
	.byte		N08   , Cn3 , v088
	.byte	W02
	.byte	W06
	.byte		        Fn3 , v084
	.byte	W07
	.byte		N10   , Gn3 , v120
	.byte	W08
	.byte		N19   , Gs3 , v112
	.byte	W16
	.byte		N04   , Cn4 , v084
	.byte	W24
	.byte		N10   , Fn3 , v096
	.byte	W09
	.byte		N17   , Gs3 , v112
	.byte	W16
	.byte		N04   , Cn4 , v100
	.byte	W10
	.byte	W14
	.byte		N24   , An3 , v112
	.byte		N36   , Ds4 , v127
	.byte	W32
	.byte	W03
	.byte		N05   , An3 , v088
	.byte		N05   , Dn4 , v104
	.byte	W23
	.byte		        An3 , v100
	.byte		N05   , Cn4 , v108
	.byte	W24
	.byte	W01
	.byte		N04   , Ds3 , v088
	.byte		N05   , As3 , v100
	.byte	W24
	.byte		        Ds3 , v096
	.byte		N05   , As3 , v104
	.byte	W24
	.byte		N04   , En3 , v108
	.byte		N06   , As3 , v104
	.byte	W23
	.byte		N04   , En3 , v108
	.byte		N06   , As3 , v104
	.byte	W24
	.byte	W01
	.byte		N05   , Fn3 , v112
	.byte		N06   , As3 , v108
	.byte	W23
	.byte		N17   , Cn4 , v112
	.byte	W01
	.byte		N08   , Fn3 , v096
	.byte	W15
	.byte		N04   , Fn3 , v084
	.byte		N04   , As3 , v100
	.byte	W23
	.byte		N09   , Fn3 , v108
	.byte	W08
	.byte		N18   , Gn3 , v112
	.byte	W16
	.byte		N06   , Gs3 , v108
	.byte	W09
	.byte	W14
	.byte		N24   , Ds3 , v104
	.byte		N24   , As3 , v120
	.byte	W32
	.byte	W02
	.byte		N04   , En3 , v104
	.byte		N05   , As3 
	.byte	W24
	.byte		        En3 , v112
	.byte		N05   , As3 , v100
	.byte	W24
	.byte		        Fn3 , v108
	.byte		N05   , As3 
	.byte	W24
	.byte		N09   , Fn3 , v100
	.byte		N18   , Cn4 , v112
	.byte	W16
	.byte		N04   , Fn3 , v080
	.byte		N07   , As3 , v108
	.byte	W32
	.byte	W02
	.byte		N08   , As3 , v088
	.byte	W07
	.byte		        An3 , v092
	.byte	W07
	.byte		N12   , Gs3 , v096
	.byte	W08
	.byte	W01
	.byte		N72   , Gn3 , v104
	.byte	W68
	.byte	W02
	.byte		N24   , As3 , v112
	.byte	W24
	.byte	W01
	.byte		N44   , Cs4 
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gs3 , v116
	.byte	W44
	.byte	W03
	.byte		N10   , Fn3 , v064
	.byte	W09
	.byte		N08   , Gn3 , v084
	.byte	W07
	.byte		N04   , Gs3 , v096
	.byte	W08
	.byte		N07
	.byte	W08
	.byte		N08   , As3 , v092
	.byte	W07
	.byte		        Cn4 , v104
	.byte	W08
	.byte		N10   , Ds4 
	.byte	W02
	.byte	W07
	.byte		        Fn4 , v096
	.byte	W08
	.byte		N09   , Ds4 , v100
	.byte	W08
	.byte		N08   , Dn4 , v096
	.byte	W08
	.byte		N09   , Ds4 , v116
	.byte	W08
	.byte		N23   , Dn4 , v104
	.byte	W23
	.byte		N11   , Cn4 , v092
	.byte	W09
	.byte		N19   , Dn4 , v100
	.byte	W16
	.byte		N10   , Cn4 , v088
	.byte	W09
	.byte		N09   , As3 , v092
	.byte	W23
	.byte		N24   , Gn4 , v116
	.byte	W24
	.byte		N17   , Fn4 , v112
	.byte	W17
	.byte		N09   , Ds4 , v092
	.byte	W08
	.byte		N17   , Dn4 , v096
	.byte	W16
	.byte		N08   , Ds4 , v092
	.byte	W08
	.byte		N12   , Dn4 , v088
	.byte	W24
	.byte		N08   , Gn4 , v104
	.byte	W08
	.byte		        As4 , v108
	.byte	W06
	.byte		N10   , Gn4 , v092
	.byte	W10
	.byte		N17   , Fn4 , v104
	.byte	W16
	.byte		N08   , Ds4 , v100
	.byte	W07
	.byte		N09   , Dn4 
	.byte	W08
	.byte		N07   , Ds4 , v104
	.byte	W08
	.byte		        Cn4 , v092
	.byte	W09
	.byte	W13
	.byte		N06   , Cn4 , v084
	.byte		N14   , Gs4 , v108
	.byte	W11
	.byte		N07   , Cn4 , v092
	.byte	W11
	.byte		N05   , Ds4 , v108
	.byte	W13
	.byte		N06   , As3 , v092
	.byte		N07   , Gn4 , v116
	.byte	W24
	.byte		        As3 , v088
	.byte		N06   , Gn4 , v120
	.byte	W23
	.byte		N07   , Ds4 , v116
	.byte	W01
	.byte		N06   , As3 , v096
	.byte	W24
	.byte		        Cn4 , v084
	.byte		N08   , Ds4 , v120
	.byte	W17
	.byte		N21   , As3 , v104
	.byte		N22   , Ds4 , v112
	.byte	W54
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_field_ruby_1:  @ 0x086920EC
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 8
	.byte		VOL   , 77*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
	.byte	W56
	.byte	W03
	.byte		N07   , As4 , v076
	.byte	W08
	.byte		N04   , As3 
	.byte	W28
	.byte	W01
mus_field_ruby_1_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W23
	.byte		N08   , Gs3 , v056
	.byte	W09
	.byte		N07   , Cn4 , v044
	.byte	W07
	.byte		N09   , Ds4 , v060
	.byte	W08
	.byte		N02   , Gn4 , v068
	.byte	W24
	.byte		N11   , Gs4 
	.byte	W08
	.byte		N07   , Ds4 , v056
	.byte	W07
	.byte		        Bn3 , v060
	.byte	W09
	.byte		N05   , As3 , v064
	.byte	W01
	.byte	W22
	.byte		N08   , Gn3 , v048
	.byte	W07
	.byte		        As3 , v060
	.byte	W08
	.byte		N11   , Ds4 , v052
	.byte	W10
	.byte		N05   , As4 , v068
	.byte	W13
	.byte		N02   , Gn4 
	.byte	W12
	.byte		N05   , Ds4 , v060
	.byte	W11
	.byte		        As3 
	.byte	W13
	.byte	W20
	.byte		N10   , Gs3 , v064
	.byte	W09
	.byte		N09   , Cn4 
	.byte	W07
	.byte		N12   , Ds4 , v072
	.byte	W11
	.byte		N05   , Gn4 , v068
	.byte	W23
	.byte		N12   , Gs4 , v076
	.byte	W08
	.byte		N09   , Ds4 , v064
	.byte	W09
	.byte		N06   , Bn3 
	.byte	W09
	.byte		        As3 
	.byte	W22
	.byte		N10   , As3 , v052
	.byte	W09
	.byte		N08   , Ds4 , v060
	.byte	W07
	.byte		N10   , Gn4 , v064
	.byte	W09
	.byte		N05   , As4 , v076
	.byte	W12
	.byte		        Gn4 , v064
	.byte	W13
	.byte		        Ds5 , v076
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_field_ruby_2:  @ 0x086921A2
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 5
	.byte		VOL   , 68*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W13
	.byte		N32   , Dn2 , v084
	.byte	W32
	.byte	W02
	.byte		N04   , Ds2 
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        En2 , v088
	.byte	W01
	.byte	W24
	.byte		N17   , En2 , v084
	.byte	W15
	.byte		N04   , Fn2 , v080
	.byte	W32
	.byte	W01
	.byte		N24   , As1 , v076
	.byte	W24
mus_field_ruby_2_B1:
	.byte		N48   , Ds2 , v084
	.byte	W48
	.byte		        As2 , v080
	.byte	W48
	.byte		        En2 
	.byte	W44
	.byte	W01
	.byte		        Cn3 , v076
	.byte	W03
	.byte		N44   , Gn2 , v068
	.byte	W44
	.byte	W01
	.byte		N28   , Fn2 , v076
	.byte	W03
	.byte	W44
	.byte		N09   , Fn2 , v064
	.byte	W07
	.byte		N10   , Gn2 
	.byte	W08
	.byte		        Gs2 , v076
	.byte	W09
	.byte		N18   , Cn3 , v072
	.byte	W16
	.byte		N04   , Fn3 , v080
	.byte	W12
	.byte	W13
	.byte		N36   , Cn3 , v084
	.byte	W32
	.byte	W02
	.byte		N04   , Ds3 , v080
	.byte	W24
	.byte	W01
	.byte		N05   , Cn3 , v076
	.byte	W24
	.byte		N06   , As2 , v080
	.byte	W24
	.byte		N05   , As2 , v076
	.byte	W23
	.byte		N06   , As2 , v080
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , As2 , v084
	.byte	W01
	.byte	W24
	.byte		N06   , As2 , v080
	.byte	W15
	.byte		N05
	.byte	W24
	.byte		N11   , Dn3 , v076
	.byte	W08
	.byte		N17   , Cn3 
	.byte	W16
	.byte		N09   , Bn2 , v072
	.byte	W08
	.byte		N23   , As2 , v080
	.byte	W01
	.byte	W23
	.byte		N21   , Ds2 
	.byte	W22
	.byte		N24   , En2 , v076
	.byte	W24
	.byte	W01
	.byte		        As2 , v084
	.byte	W24
	.byte		N06   , Gs2 , v080
	.byte	W02
	.byte	W24
	.byte		N19   , Gs2 , v084
	.byte	W16
	.byte		N04   , As2 , v080
	.byte	W56
	.byte	W24
	.byte		N23   , Ds2 , v076
	.byte	W23
	.byte		N24   , Dn2 
	.byte	W24
	.byte	W01
	.byte		        Ds2 
	.byte	W24
	.byte	W01
	.byte		N48   , Cn2 , v064
	.byte	W44
	.byte	W01
	.byte		N24   , Dn2 , v076
	.byte	W24
	.byte	W01
	.byte		N23   , En2 
	.byte	W23
	.byte		N32   , Fn2 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N10   , Fn2 , v068
	.byte	W09
	.byte		N07   , Gn2 , v064
	.byte	W08
	.byte		N03   , Gs2 
	.byte	W07
	.byte		N08   , Gs2 , v080
	.byte	W07
	.byte		N09   , As2 , v064
	.byte	W09
	.byte		N04   , Cn3 
	.byte	W09
	.byte		N08
	.byte	W01
	.byte	W06
	.byte		N09   , Dn3 
	.byte	W08
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N09   , As2 , v068
	.byte	W08
	.byte		N10   , Cn3 , v060
	.byte	W08
	.byte		N23   , As2 , v064
	.byte	W24
	.byte		N09   , An2 , v076
	.byte	W07
	.byte		N18   , As2 , v068
	.byte	W18
	.byte		N09   , An2 , v076
	.byte	W07
	.byte		N28   , Gn2 
	.byte	W02
	.byte	W36
	.byte	W03
	.byte		N11   , Gn2 , v068
	.byte	W09
	.byte		N28   , Cn3 , v072
	.byte	W36
	.byte	W02
	.byte		N06
	.byte	W09
	.byte		N16   , As2 , v084
	.byte	W01
	.byte	W15
	.byte		N09   , Gn2 , v076
	.byte	W08
	.byte		N18   , Dn2 , v072
	.byte	W15
	.byte		N09   , Gn2 , v068
	.byte	W09
	.byte		N24   , Cn3 , v076
	.byte	W24
	.byte	W01
	.byte		N22   , Gn2 , v072
	.byte	W24
	.byte		N24   , Fn2 , v076
	.byte	W36
	.byte		N12
	.byte	W11
	.byte		N06   , Gs2 , v084
	.byte	W01
	.byte		N04   , As1 , v072
	.byte	W23
	.byte		N06
	.byte		N06   , Gs2 , v076
	.byte	W24
	.byte	W01
	.byte		N04   , Gn2 , v084
	.byte	W23
	.byte		        Gn2 , v076
	.byte	W14
	.byte		N18   , Gn2 , v084
	.byte	W56
	.byte	W03
	.byte	W23
	.byte		N24   , Gn3 , v100
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N14   , Ds3 , v088
	.byte	W13
	.byte		N11   , Dn3 , v084
	.byte	W12
	.byte		        As2 , v088
	.byte	W09
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N06   , Fn3 , v092
	.byte	W06
	.byte		N08   , Ds3 
	.byte	W09
	.byte		N09   , Fn3 , v096
	.byte	W07
	.byte		N11   , Ds3 , v088
	.byte	W09
	.byte		N24   , Gn3 , v092
	.byte	W23
	.byte		N13   , Fn3 , v080
	.byte	W11
	.byte		N12   , Ds3 , v084
	.byte	W14
	.byte		N09   , Cn3 , v092
	.byte	W07
	.byte		N08   , Ds3 , v088
	.byte	W08
	.byte		N07   , Fn3 
	.byte	W07
	.byte		N09   , Ds3 
	.byte	W10
	.byte		N11   , Fn3 , v072
	.byte	W07
	.byte		N08   , Ds3 , v096
	.byte	W09
	.byte		N09   , Bn2 
	.byte	W07
	.byte		        Ds3 , v088
	.byte	W09
	.byte		N07   , Fn3 , v096
	.byte	W07
	.byte		N09   , Ds3 , v088
	.byte	W09
	.byte		N11   , Fn3 
	.byte	W07
	.byte		N09   , Ds3 
	.byte	W08
	.byte		        As2 , v092
	.byte	W01
	.byte	W06
	.byte		N08   , Ds3 , v080
	.byte	W09
	.byte		N07   , Fn3 , v084
	.byte	W07
	.byte		N09   , Ds3 , v092
	.byte	W09
	.byte		N07   , Fn3 , v076
	.byte	W06
	.byte		N10   , Ds3 , v084
	.byte	W10
	.byte		        Gn3 , v088
	.byte	W09
	.byte		N07   , Fn3 , v092
	.byte	W07
	.byte		N10   , Ds3 
	.byte	W09
	.byte		N08   , As2 , v084
	.byte	W07
	.byte		N09   , Ds3 , v076
	.byte	W09
	.byte		N12   , Fn3 , v096
	.byte	W08
	.byte	W01
	.byte		N36   , Gn3 , v088
	.byte	W32
	.byte	W02
	.byte		N12   , Gs3 , v080
	.byte	W24
	.byte		N15   , Dn3 , v064
	.byte	W12
	.byte		N13   , Gn3 , v076
	.byte	W11
	.byte		N07   , Fn3 
	.byte	W13
	.byte		N28   , Fn3 , v080
	.byte	W01
	.byte	W24
	.byte		N18   , Ds3 , v072
	.byte	W23
	.byte		        Ds3 , v068
	.byte	W01
	.byte		        Gn3 , v084
	.byte	W24
	.byte		N15   , Gn3 , v068
	.byte		N16   , Cn4 , v088
	.byte	W24
	.byte	W12
	.byte		N14   , An3 , v084
	.byte	W11
	.byte		N18   , As3 , v092
	.byte	W18
	.byte		N01   , An3 , v080
	.byte	W06
	.byte		N12   , An3 , v084
	.byte	W13
	.byte		N13   , Gn3 
	.byte	W11
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N15   , Ds3 , v084
	.byte	W13
	.byte		TIE   , Dn3 , v092
	.byte	W96
	.byte	W02
	.byte		EOT
	.byte	W92
	.byte	W02
	.byte	GOTO
	 .word	mus_field_ruby_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_field_ruby_3:  @ 0x086923D8
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 12
	.byte		VOL   , 96*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W01
	.byte		N09   , As3 , v076
	.byte	W07
	.byte		N08   , An3 , v064
	.byte	W08
	.byte		N07   , Gs3 , v060
	.byte	W07
	.byte		N08   , Gn3 , v064
	.byte	W07
	.byte		        Fs3 , v060
	.byte	W08
	.byte		N07   , Fn3 , v072
	.byte	W07
	.byte		N09   , En3 , v068
	.byte	W09
	.byte		N08   , Ds3 , v060
	.byte	W08
	.byte		N09   , Dn3 , v064
	.byte	W09
	.byte		N08   , Cs3 , v056
	.byte	W07
	.byte		N07   , Cn3 , v060
	.byte	W08
	.byte		N04   , Bn2 , v072
	.byte	W10
	.byte	W13
	.byte		N24   , As2 , v088
	.byte	W32
	.byte	W02
	.byte		N05   , As2 , v084
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N03
	.byte	W01
	.byte	W24
	.byte		N05   , As2 , v076
	.byte	W15
	.byte		        As2 , v080
	.byte	W32
	.byte	W01
	.byte		N08   , As2 , v072
	.byte	W08
	.byte		N07   , Cn3 , v048
	.byte	W07
	.byte		N10   , Dn3 , v064
	.byte	W08
	.byte		N08   , Ds3 , v076
	.byte	W01
mus_field_ruby_3_B1:
	.byte	W15
	.byte		N05   , Ds3 , v088
	.byte	W48
	.byte		N10   , Ds3 , v076
	.byte	W09
	.byte		N16   , Dn3 
	.byte	W15
	.byte		N08   , Ds3 
	.byte	W07
	.byte		N10   , Cn3 , v080
	.byte	W02
	.byte	W14
	.byte		N04   , Cn3 , v076
	.byte	W22
	.byte		        Cn3 , v080
	.byte	W23
	.byte		N08   , Cn3 , v072
	.byte	W09
	.byte		N14   , Cn4 , v084
	.byte	W28
	.byte	W21
	.byte		N03   , Fn4 , v092
	.byte	W24
	.byte		N04   , Cn4 , v084
	.byte	W24
	.byte	W02
	.byte		N03   , Fn3 , v080
	.byte	W24
	.byte	W01
	.byte	W13
	.byte		N24   , Fs3 , v092
	.byte	W32
	.byte	W02
	.byte		N04   , Fs3 , v076
	.byte	W24
	.byte		        Fs3 , v084
	.byte	W24
	.byte	W01
	.byte	W01
	.byte		N05   , Gn3 
	.byte	W22
	.byte		        Gn3 , v080
	.byte	W24
	.byte	W01
	.byte		        Fs3 
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W23
	.byte		N05   , Fn3 , v084
	.byte	W01
	.byte		N02   , Ds3 , v072
	.byte	W23
	.byte		N08   , Fn3 , v080
	.byte	W01
	.byte		N07   , Ds3 , v068
	.byte	W15
	.byte		N01   , Dn3 , v064
	.byte		N04   , Fn3 , v084
	.byte	W23
	.byte		N10   , Fn3 , v076
	.byte	W09
	.byte		N17   , Gn3 , v080
	.byte	W15
	.byte		N04   , Gs3 
	.byte	W09
	.byte	W14
	.byte		N09   , As3 , v076
	.byte	W08
	.byte		N15   , Ds4 , v080
	.byte	W15
	.byte		N10   , Gn4 , v076
	.byte	W09
	.byte		        As4 
	.byte	W07
	.byte		N07   , Gn4 , v052
	.byte	W07
	.byte		N05   , En4 , v072
	.byte	W09
	.byte		N04   , Dn4 , v076
	.byte	W16
	.byte		N10   , Cn4 , v072
	.byte	W08
	.byte		N04   , As3 , v084
	.byte	W03
	.byte	W14
	.byte		N10   , Fn3 , v072
	.byte	W09
	.byte		N04   , Gn3 , v076
	.byte	W16
	.byte		N09   , Gs3 
	.byte	W08
	.byte		N03   , As3 , v084
	.byte	W24
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		N05   , As4 , v092
	.byte	W22
	.byte		N17   , Gn3 , v084
	.byte	W01
	.byte	W16
	.byte		N05   , As2 , v076
	.byte	W44
	.byte	W02
	.byte		N04
	.byte	W24
	.byte	W01
	.byte		N08   , As2 , v064
	.byte	W07
	.byte		N18   , Gs3 , v072
	.byte	W02
	.byte	W14
	.byte		N04   , Gn3 , v076
	.byte	W23
	.byte		        Fn3 , v084
	.byte	W23
	.byte		N10   , En3 , v068
	.byte	W09
	.byte		N15   , Dn3 , v072
	.byte	W17
	.byte		N06   , En3 , v064
	.byte	W08
	.byte		N07   , Cn3 
	.byte	W02
	.byte	W05
	.byte		N08   , Fn3 , v072
	.byte	W08
	.byte		N10   , Gn3 , v076
	.byte	W08
	.byte		N04   , Gs3 , v072
	.byte	W17
	.byte		        Cn4 , v080
	.byte	W32
	.byte	W03
	.byte		        Fn4 , v092
	.byte	W23
	.byte		N24   , An3 , v084
	.byte	W36
	.byte	W01
	.byte		N12   , An3 , v076
	.byte	W10
	.byte		N21   , Cn4 , v084
	.byte	W23
	.byte		N24   , Fs3 , v072
	.byte	W24
	.byte	W01
	.byte		N08   , Gn3 , v064
	.byte	W01
	.byte	W07
	.byte		N09   , Dn3 , v068
	.byte	W09
	.byte		N02   , Gn3 
	.byte	W07
	.byte		N07   , Gn3 , v080
	.byte	W08
	.byte		N08   , As3 , v076
	.byte	W07
	.byte		N03   , Dn4 , v064
	.byte	W09
	.byte		N16   , Dn4 , v068
	.byte	W15
	.byte		N11   , Cn4 , v076
	.byte	W09
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N11   , Cn4 
	.byte	W08
	.byte		N17   , As3 , v072
	.byte	W01
	.byte	W24
	.byte		N08   , As3 , v076
	.byte	W09
	.byte		        Cn4 , v064
	.byte	W06
	.byte		N11   , Dn4 , v072
	.byte	W08
	.byte		N06   , Cn4 , v080
	.byte	W24
	.byte	W01
	.byte		N05   , Cn5 , v088
	.byte	W11
	.byte		N03   , Cn4 , v076
	.byte	W13
	.byte	W12
	.byte		N04   , Fn3 , v072
	.byte	W12
	.byte		N03   , Gn3 , v060
	.byte	W11
	.byte		N04   , Gs3 , v072
	.byte	W12
	.byte		        As3 , v076
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 , v080
	.byte	W12
	.byte		        Dn4 , v076
	.byte	W13
	.byte		        Ds3 
	.byte		N04   , Ds4 , v088
	.byte	W24
	.byte		        Ds3 , v072
	.byte		N06   , Ds4 , v088
	.byte	W14
	.byte		N02   , Ds3 , v072
	.byte	W06
	.byte		N01   , Ds4 , v060
	.byte	W01
	.byte		N04   , Ds3 , v072
	.byte	W05
	.byte		N02   , Ds4 , v064
	.byte	W02
	.byte		N03   , Ds3 , v060
	.byte	W05
	.byte		N02   , Ds4 , v072
	.byte	W03
	.byte		N03   , Ds3 , v068
	.byte	W04
	.byte		N04   , Ds4 , v080
	.byte	W03
	.byte		N06   , Ds3 , v068
	.byte	W28
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_field_ruby_4:  @ 0x086925E8
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 32
	.byte		VOL   , 86*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W12
	.byte		N28   , As1 , v080
	.byte	W36
	.byte		N06   , As1 , v084
	.byte	W24
	.byte		N04   , As1 , v080
	.byte	W24
	.byte		        As1 , v084
	.byte	W24
	.byte		N12
	.byte	W12
	.byte		N05
	.byte	W36
	.byte		N24   , As1 , v080
	.byte	W24
mus_field_ruby_4_B1:
	.byte		N42   , Ds1 , v080
	.byte	W36
	.byte		N32   , As1 
	.byte	W36
	.byte		N24   , Ds2 , v076
	.byte	W24
	.byte		N36   , En1 
	.byte	W36
	.byte		N32   , Cn2 , v072
	.byte	W36
	.byte		N24   , Gn2 , v076
	.byte	W24
	.byte		N42   , Fn1 , v068
	.byte	W36
	.byte		N32   , Cn2 , v060
	.byte	W36
	.byte		N24   , Fn2 , v072
	.byte	W24
	.byte		N42   , Fs1 
	.byte	W36
	.byte		N36   , Ds2 , v076
	.byte	W36
	.byte		N24   , An2 , v080
	.byte	W24
	.byte		N06   , Gn1 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        Fs1 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , Fn1 
	.byte	W23
	.byte		N19   , Fn1 , v080
	.byte	W18
	.byte		N03   , As1 
	.byte	W22
	.byte		N09   , As1 , v072
	.byte	W08
	.byte		N16   , As2 , v084
	.byte	W16
	.byte		N09   , As1 , v064
	.byte	W07
	.byte		N24   , Gn1 , v076
	.byte	W02
	.byte	W22
	.byte		        Gn2 
	.byte	W24
	.byte		        Fs2 , v080
	.byte	W24
	.byte	W01
	.byte		        Fs1 , v076
	.byte	W24
	.byte	W01
	.byte		N05   , Fn1 , v080
	.byte	W24
	.byte		N17   , Fn1 , v084
	.byte	W16
	.byte		N04   , As1 
	.byte	W32
	.byte		N09   , As1 , v076
	.byte	W08
	.byte		N08   , Cn2 , v060
	.byte	W08
	.byte		N11   , Dn2 , v068
	.byte	W08
	.byte		N36   , Ds1 , v080
	.byte		N40   , Ds2 
	.byte	W36
	.byte		N32   , As1 , v076
	.byte	W36
	.byte		N28   , Ds2 , v080
	.byte	W24
	.byte		N36   , En1 , v076
	.byte	W36
	.byte		        Cn2 , v072
	.byte	W36
	.byte		N24   , Gn2 , v076
	.byte	W24
	.byte		N40   , Fn1 
	.byte	W36
	.byte		N32   , Cn2 , v068
	.byte	W36
	.byte		N24   , Fn2 , v072
	.byte	W24
	.byte		N42   , Fs1 , v076
	.byte	W36
	.byte		N36   , Ds2 , v080
	.byte	W36
	.byte		N24   , An2 
	.byte	W24
	.byte		        Gn1 , v076
	.byte	W40
	.byte		N10   , Gn1 , v068
	.byte	W08
	.byte		N24   , Cn2 , v076
	.byte	W36
	.byte	W02
	.byte		N06   , Cn2 , v064
	.byte	W09
	.byte		N24   , Gn1 , v076
	.byte	W01
	.byte	W36
	.byte	W03
	.byte		N10   , Gn1 , v068
	.byte	W08
	.byte		N17   , Cn2 , v076
	.byte	W16
	.byte		N10   , Gn2 , v064
	.byte	W08
	.byte		N17   , Cn3 , v080
	.byte	W16
	.byte		N08   , Gn2 , v064
	.byte	W07
	.byte		N30   , Fn2 , v080
	.byte	W02
	.byte	W32
	.byte	W03
	.byte		N13   , Fn1 , v072
	.byte	W13
	.byte		N05   , As1 , v084
	.byte	W24
	.byte		        As1 , v076
	.byte	W24
	.byte		        Ds1 , v080
	.byte	W24
	.byte		N19   , Ds2 , v092
	.byte	W17
	.byte		N06   , Ds1 , v080
	.byte	W24
	.byte	W01
	.byte		N09   , Ds1 , v068
	.byte	W09
	.byte		N13   , Fn1 
	.byte	W15
	.byte		N09   , Gn1 
	.byte	W06
	.byte		N36   , Gs1 
	.byte	W36
	.byte		N17   , Ds2 
	.byte	W12
	.byte		N13   , Gs2 , v072
	.byte	W12
	.byte		N04   , Gn2 , v064
	.byte	W12
	.byte		N12   , Gn2 , v052
	.byte	W12
	.byte		N05   , Fn2 , v068
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N03   , Ds2 , v072
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N02   , Gn1 , v064
	.byte	W12
	.byte		N23   , Ds1 , v068
	.byte	W48
	.byte		N40   , Gs1 , v076
	.byte	W36
	.byte		N16   , Ds2 , v068
	.byte	W12
	.byte		N10   , Gs2 , v076
	.byte	W12
	.byte		N05   , Bn2 , v072
	.byte	W12
	.byte		N03   , As2 
	.byte	W12
	.byte		N05   , Gs2 , v068
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N03   , Ds2 , v068
	.byte	W12
	.byte		N02   , As1 , v064
	.byte	W12
	.byte		        Gn1 , v060
	.byte	W12
	.byte		N24   , Ds1 , v064
	.byte	W24
	.byte		        Ds2 , v068
	.byte	W24
	.byte		N36   , Gn1 , v076
	.byte	W36
	.byte		N15   , Dn2 , v068
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Gn1 , v064
	.byte	W24
	.byte		        Cn2 , v068
	.byte	W36
	.byte		N15   , Cn2 , v060
	.byte	W12
	.byte		N24   , Gn2 , v068
	.byte	W24
	.byte		N22   , Cn2 
	.byte	W24
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N15   , Fn1 , v072
	.byte	W16
	.byte		N06   , Fn2 , v068
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W12
	.byte		N04   , Gn1 , v072
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W14
	.byte		N84   , As1 , v084
	.byte	W96
	.byte		N09   , As1 , v056
	.byte	W08
	.byte		N06   , Bn1 , v060
	.byte	W07
	.byte		N08   , Cn2 
	.byte	W07
	.byte		N07   , Cs2 , v064
	.byte	W08
	.byte		        Dn2 , v072
	.byte	W08
	.byte		        Ds2 , v068
	.byte	W08
	.byte		N08   , En2 , v064
	.byte	W08
	.byte		N07   , Fn2 , v060
	.byte	W07
	.byte		        Fs2 , v068
	.byte	W08
	.byte		N08   , Gn2 , v056
	.byte	W08
	.byte		N10   , Gs2 , v072
	.byte	W09
	.byte		N09   , An2 , v076
	.byte	W10
	.byte	GOTO
	 .word	mus_field_ruby_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_field_ruby_5:  @ 0x086927D6
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 48
	.byte		VOL   , 47*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_ruby_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N44   , Cn3 , v048
	.byte		N40   , Ds3 
	.byte	W44
	.byte	W01
	.byte		        Ds3 , v056
	.byte	W01
	.byte		        Bn2 , v044
	.byte	W48
	.byte		N48   , Ds3 , v056
	.byte	W01
	.byte		N36   , As2 , v048
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N24   , Ds2 , v060
	.byte	W24
	.byte	W01
	.byte		N13   , Fn2 , v056
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N42   , Cn3 , v048
	.byte		N40   , Ds3 , v052
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N40
	.byte	W01
	.byte		N44   , Bn2 
	.byte	W44
	.byte	W01
	.byte		N52   , Ds3 , v056
	.byte	W01
	.byte		N48   , As2 
	.byte	W03
	.byte	W44
	.byte	W02
	.byte		N36   , Gn2 
	.byte	W48
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_5_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_field_ruby_6:  @ 0x08692857
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 73
	.byte		VOL   , 88*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_ruby_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N40   , Gn4 , v068
	.byte	W36
	.byte		N12   , Gs4 , v060
	.byte	W24
	.byte		        Dn4 , v056
	.byte	W11
	.byte		N11   , Gn4 , v064
	.byte	W11
	.byte		N06   , Fn4 , v076
	.byte	W12
	.byte		N15   , Cn4 , v048
	.byte		N24   , Fn4 , v056
	.byte	W02
	.byte	W22
	.byte		N17   , Cn4 , v048
	.byte	W01
	.byte		N24   , Ds4 , v064
	.byte	W23
	.byte		        Dn4 , v056
	.byte	W24
	.byte		N17   , Ds4 , v060
	.byte	W24
	.byte	W02
	.byte	W10
	.byte		N15   , Fn4 , v056
	.byte	W13
	.byte		N18   , Gn4 , v076
	.byte	W18
	.byte		N07   , Fn4 , v060
	.byte	W06
	.byte		N14   , Fn3 
	.byte	W12
	.byte		N11   , Gn3 , v064
	.byte	W11
	.byte		N12   , Gs3 , v068
	.byte	W11
	.byte		N11   , An3 , v060
	.byte	W15
	.byte		N92   , Gs3 , v076
	.byte		N90   , As3 , v072
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_6_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_field_ruby_7:  @ 0x086928E7
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 11
	.byte		VOL   , 86*mus_field_ruby_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_ruby_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W23
	.byte		N24   , Bn2 , v072
	.byte	W24
	.byte	W01
	.byte		        Cn3 
	.byte	W24
	.byte	W01
	.byte		N22   , Dn3 
	.byte	W22
	.byte		N07   , Gn2 , v068
	.byte	W01
	.byte	W06
	.byte		N09   , Ds2 , v060
	.byte	W08
	.byte		N08   , Fn2 , v068
	.byte	W09
	.byte		N16   , Gn2 , v072
	.byte	W14
	.byte		N11   , Cn3 , v068
	.byte	W10
	.byte		N24   , Gn2 , v076
	.byte	W24
	.byte	W01
	.byte		N21   , Cn3 , v072
	.byte	W24
	.byte		N06   , Fn2 
	.byte	W08
	.byte		        Gn2 , v068
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N07   , Gn2 , v064
	.byte	W08
	.byte		        Fn2 , v068
	.byte	W08
	.byte		N09   , Gn2 , v064
	.byte	W08
	.byte		N08   , An2 , v072
	.byte	W08
	.byte		N07   , As2 
	.byte	W08
	.byte		N09   , An2 , v068
	.byte	W08
	.byte		N10   , As2 
	.byte	W08
	.byte		N05   , Cn3 , v056
	.byte	W08
	.byte		N09   , Fn2 , v060
	.byte	W08
	.byte		N08   , As2 , v072
	.byte	W08
	.byte		        An2 , v068
	.byte	W08
	.byte		        As2 , v072
	.byte	W08
	.byte		        An2 , v076
	.byte	W08
	.byte		N07   , As2 , v068
	.byte	W08
	.byte		N11   , An2 , v072
	.byte	W08
	.byte		N08   , As2 , v076
	.byte	W08
	.byte		N06   , An2 , v072
	.byte	W08
	.byte		N07   , As2 , v064
	.byte	W08
	.byte		N08   , An2 , v072
	.byte	W08
	.byte		N06   , As2 , v060
	.byte	W08
	.byte		N10   , An2 , v064
	.byte	W08
	.byte		N20   , As2 , v076
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby_7_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 09 ***********************@

mus_field_ruby_8:  @ 0x086929AC
	.byte	KEYSH , mus_field_ruby_key+0
	.byte		VOICE , 0
	.byte		VOL   , 43*mus_field_ruby_mvl/mxv
	.byte	W96
	.byte	W16
	.byte		N04   , Cn1 , v100
	.byte		N22   , As1 
	.byte	W32
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N22   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N22   , As1 
	.byte	W16
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		        Dn1 
	.byte		N22   , As1 
	.byte	W24
mus_field_ruby_8_B1:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W14
	.byte		        Cn1 
	.byte	W32
	.byte	W02
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B1
mus_field_ruby_8_B2:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
mus_field_ruby_8_B3:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby_8_B2
	.byte	PATT
	 .word	mus_field_ruby_8_B3
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B1
	.byte	PATT
	 .word	mus_field_ruby_8_B2
	.byte	PATT
	 .word	mus_field_ruby_8_B3
	.byte	PATT
	 .word	mus_field_ruby_8_B2
	.byte	PATT
	 .word	mus_field_ruby_8_B3
mus_field_ruby_8_B4:
	.byte		N04   , Cn1 , v100
	.byte	W40
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte	PATT
	 .word	mus_field_ruby_8_B4
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N20   , As1 
	.byte	W24
	.byte	GOTO
	 .word	mus_field_ruby_8_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_field_ruby:  @ 0x08692A98
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_field_ruby_pri	@ Priority
	.byte	mus_field_ruby_rev	@ Reverb

	.word	mus_field_ruby_grp

	.word	mus_field_ruby_0
	.word	mus_field_ruby_1
	.word	mus_field_ruby_2
	.word	mus_field_ruby_3
	.word	mus_field_ruby_4
	.word	mus_field_ruby_5
	.word	mus_field_ruby_6
	.word	mus_field_ruby_7
	.word	mus_field_ruby_8
