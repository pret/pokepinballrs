	.include "sound/MPlayDef.s"

	.equ	mus_field_ruby2_grp, gUnknown_08532808
	.equ	mus_field_ruby2_pri, 0
	.equ	mus_field_ruby2_rev, reverb_set+50
	.equ	mus_field_ruby2_mvl, 127
	.equ	mus_field_ruby2_key, 0
	.equ	mus_field_ruby2_tbs, 1
	.equ	mus_field_ruby2_exg, 0
	.equ	mus_field_ruby2_cmp, 1

	.section .rodata
	.global	mus_field_ruby2
	.align	2

@*********************** Track 01 ***********************@

mus_field_ruby2_0:  @ 0x0869CAA4
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_0_B1:
	.byte	TEMPO , 114*mus_field_ruby2_tbs/2
	.byte		VOICE , 78
	.byte		VOL   , 85*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N13   , Cn4 , v088
	.byte	W18
	.byte		N04   , Cn4 , v080
	.byte	W17
	.byte		N06   , Cn4 , v084
	.byte	W13
	.byte		N04
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		N03   , Cn4 , v080
	.byte	W06
	.byte		N15
	.byte	W18
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
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_field_ruby2_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_field_ruby2_1:  @ 0x0869CAEA
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_1_B1:
	.byte		VOICE , 1
	.byte		VOL   , 71*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
mus_field_ruby2_1_B2:
	.byte		N10   , An1 , v080
	.byte	W13
	.byte		N01   , An2 , v068
	.byte		N01   , Cs3 , v056
	.byte		N02   , En3 , v060
	.byte	W06
	.byte		N03   , An1 , v076
	.byte	W11
	.byte		N01   , Cs3 , v060
	.byte		N01   , En3 , v064
	.byte	W01
	.byte		        An2 , v056
	.byte	W05
	.byte		N02   , An1 , v080
	.byte	W12
	.byte		N11   , Dn2 , v084
	.byte	W12
	.byte		N01   , An2 , v068
	.byte		N01   , Bn2 , v060
	.byte		N01   , Dn3 
	.byte	W06
	.byte		N03   , Dn2 , v084
	.byte	W12
	.byte		N01   , An2 , v064
	.byte		N01   , Bn2 , v056
	.byte		N01   , Dn3 , v052
	.byte	W05
	.byte		N03   , Dn2 , v084
	.byte	W13
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte		N11   , En2 , v084
	.byte	W12
	.byte		N01   , An2 , v072
	.byte		N01   , Bn2 , v064
	.byte		N02   , En3 , v060
	.byte	W07
	.byte		N03   , En2 , v076
	.byte	W10
	.byte		N01   , An2 , v064
	.byte		N01   , Bn2 , v060
	.byte		N02   , En3 
	.byte	W07
	.byte		N01   , En2 , v080
	.byte	W12
	.byte		N11   , En2 , v092
	.byte	W12
	.byte		N01   , Gs2 , v064
	.byte	W01
	.byte		        Bn2 , v052
	.byte		N01   , En3 , v048
	.byte	W05
	.byte		N03   , En2 , v076
	.byte	W10
	.byte		N01   , Gs2 , v060
	.byte		N02   , En3 
	.byte	W01
	.byte		N01   , Bn2 , v048
	.byte	W06
	.byte		N04   , En2 , v084
	.byte	W12
	.byte		N01   , An1 , v092
	.byte	W01
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	PATT
	 .word	mus_field_ruby2_1_B2
	.byte	W12
	.byte		N05   , Cs2 , v072
	.byte		N04   , An2 , v076
	.byte	W24
	.byte	W01
	.byte		N06   , Bn2 , v080
	.byte	W01
	.byte		N04   , Dn2 , v076
	.byte	W22
	.byte		N07   , Ds2 , v080
	.byte	W01
	.byte		        Cn3 
	.byte	W23
	.byte		N05   , En2 , v076
	.byte		N06   , Cs3 , v080
	.byte	W12
	.byte	W12
	.byte		        Fs2 , v076
	.byte		N05   , Dn3 , v080
	.byte	W24
	.byte		N06   , Gn2 , v076
	.byte		N06   , En3 , v080
	.byte	W24
	.byte		        Fn3 , v084
	.byte	W01
	.byte		N05   , Gs2 , v080
	.byte	W23
	.byte		N04   , An2 , v076
	.byte		N05   , Fs3 , v084
	.byte	W12
	.byte	W12
	.byte		        An2 , v088
	.byte	W01
	.byte		        Cs2 , v072
	.byte	W24
	.byte		N06   , Dn2 , v080
	.byte		N06   , Bn2 , v084
	.byte	W23
	.byte		N07   , Cn3 , v080
	.byte	W01
	.byte		N06   , Ds2 
	.byte	W22
	.byte		N07   , Cs3 
	.byte	W01
	.byte		N05   , En2 
	.byte	W12
	.byte	W13
	.byte		N06   , Fs2 , v072
	.byte		N05   , Dn3 , v076
	.byte	W23
	.byte		N04   , Gn2 
	.byte		N06   , En3 , v080
	.byte	W23
	.byte		        Fn3 , v084
	.byte	W01
	.byte		        Gs2 , v076
	.byte	W23
	.byte		N05   , An2 , v080
	.byte		N06   , Fs3 
	.byte	W13
	.byte	W11
	.byte		N04   , Bn2 
	.byte	W01
	.byte		N05   , Ds2 
	.byte	W23
	.byte		N06   , Cs3 
	.byte	W01
	.byte		N04   , En2 , v076
	.byte	W24
	.byte		        Fn2 
	.byte		N04   , Dn3 , v080
	.byte	W23
	.byte		        Ds3 
	.byte	W01
	.byte		        Fs2 , v076
	.byte	W12
	.byte	W12
	.byte		        Gn2 
	.byte		N05   , En3 , v080
	.byte	W22
	.byte		        Fs3 , v084
	.byte	W01
	.byte		N03   , An2 , v076
	.byte	W24
	.byte		N04   , Bn2 , v080
	.byte		N04   , Gn3 , v084
	.byte	W24
	.byte		        Bn2 , v076
	.byte		N04   , Gs3 , v084
	.byte	W13
	.byte	W12
	.byte		        En2 , v076
	.byte		N04   , En3 , v080
	.byte	W12
	.byte		N04
	.byte	W01
	.byte		        En2 
	.byte	W11
	.byte		N03   , Bn3 
	.byte	W24
	.byte		        En2 
	.byte	W01
	.byte		N04   , En3 , v076
	.byte	W11
	.byte		        En2 , v080
	.byte		N04   , En3 , v076
	.byte	W12
	.byte		N03   , Bn3 , v084
	.byte	W12
	.byte	W12
	.byte		N05   , An3 , v076
	.byte	W05
	.byte		N06   , En3 , v072
	.byte	W06
	.byte		N03   , Cs3 , v060
	.byte	W04
	.byte		N08   , An2 
	.byte	W07
	.byte		N06   , En2 , v064
	.byte	W05
	.byte		N08   , Cs2 , v068
	.byte	W07
	.byte		N04   , An1 , v076
	.byte	W24
	.byte	W03
	.byte		N03   , En2 , v092
	.byte		N03   , Cs3 , v088
	.byte	W23
	.byte	GOTO
	 .word	mus_field_ruby2_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_field_ruby2_2:  @ 0x0869CCC5
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_2_B1:
	.byte		VOICE , 3
	.byte		VOL   , 102*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W02
	.byte		N32   , En4 , v084
	.byte	W02
	.byte	W30
	.byte	W01
	.byte		N05   , Dn4 , v068
	.byte	W05
	.byte		        Cs4 
	.byte	W05
	.byte		N08   , Dn4 , v076
	.byte	W07
	.byte		N30   , En4 , v080
	.byte	W30
	.byte		N05   , Dn4 , v064
	.byte	W05
	.byte		N06   , Cs4 , v068
	.byte	W05
	.byte		N07   , Dn4 
	.byte	W06
	.byte		N03   , En4 , v080
	.byte	W02
	.byte	W11
	.byte		N06   , Gs4 , v076
	.byte	W05
	.byte		N03   , Fs4 , v080
	.byte	W13
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Cs4 , v076
	.byte	W13
	.byte		N18   , Dn4 , v088
	.byte	W16
	.byte		N03   , En4 , v080
	.byte	W19
	.byte		        Cs4 , v084
	.byte	W13
	.byte		N19   , Dn4 , v092
	.byte	W18
	.byte		N05   , En4 , v084
	.byte	W17
	.byte		N04   , Cs4 , v080
	.byte	W13
	.byte		N19   , Dn4 , v088
	.byte	W18
	.byte		N04   , Cs4 , v080
	.byte	W16
	.byte		        Bn3 
	.byte	W14
	.byte		N03   , Cs4 , v076
	.byte	W11
	.byte		N07   , Bn3 
	.byte	W05
	.byte		N36   , An3 
	.byte	W60
	.byte	W02
	.byte		N05   , Cs4 , v060
	.byte	W05
	.byte		N07   , Dn4 , v068
	.byte	W05
	.byte		N05   , Ds4 , v072
	.byte	W08
	.byte		N32   , En4 , v084
	.byte	W30
	.byte	W01
	.byte		N05   , Dn4 , v068
	.byte	W05
	.byte		N06   , Cs4 
	.byte	W05
	.byte		N08   , Dn4 , v064
	.byte	W07
	.byte		N28   , En4 , v084
	.byte	W28
	.byte	W01
	.byte		N06   , Dn4 , v068
	.byte	W05
	.byte		        Cs4 
	.byte	W05
	.byte		N08   , Dn4 , v064
	.byte	W07
	.byte		N03   , En4 , v084
	.byte	W02
	.byte	W10
	.byte		N06   , Gs4 , v076
	.byte	W04
	.byte		N05   , Fs4 , v080
	.byte	W14
	.byte		N06   , En4 
	.byte	W05
	.byte		N04   , Cs4 , v076
	.byte	W13
	.byte		N21   , Dn4 , v088
	.byte	W20
	.byte		N05   , Ds4 
	.byte	W17
	.byte		N07   , En4 
	.byte	W13
	.byte		N04   , En4 , v080
	.byte	W12
	.byte		N06   , An4 
	.byte	W05
	.byte		N05   , Cs5 , v084
	.byte	W13
	.byte		N07   , Dn5 , v080
	.byte	W06
	.byte		N04   , Cs5 , v084
	.byte	W13
	.byte		N19   , Bn4 , v088
	.byte	W17
	.byte		N04   , An4 
	.byte	W17
	.byte		N05   , Gs4 , v084
	.byte	W13
	.byte	W01
	.byte		N04   , An4 , v092
	.byte	W13
	.byte		N32   , En4 , v088
	.byte	W80
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N09   , En4 , v072
	.byte	W12
	.byte		N03   , En4 , v068
	.byte	W06
	.byte		N02   , En5 , v076
	.byte	W13
	.byte		N05   , Dn4 , v060
	.byte	W05
	.byte		        Cs4 , v068
	.byte	W05
	.byte		N08   , Dn4 , v060
	.byte	W07
	.byte		N07   , En4 , v076
	.byte	W12
	.byte		N04
	.byte	W05
	.byte		N03   , En5 
	.byte	W13
	.byte		N05   , Dn4 , v060
	.byte	W05
	.byte		        Cs4 , v064
	.byte	W05
	.byte		N06   , Dn4 , v060
	.byte	W07
	.byte		N03   , En4 , v072
	.byte	W01
	.byte	W11
	.byte		        Gs4 , v068
	.byte	W05
	.byte		        Fs4 , v072
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		N04   , Cs4 , v076
	.byte	W12
	.byte		N14   , Dn4 
	.byte	W14
	.byte		N06   , Ds4 , v064
	.byte	W05
	.byte		N04   , En4 , v076
	.byte	W19
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N12   , Dn4 , v080
	.byte	W12
	.byte		N06   , Ds4 , v060
	.byte	W06
	.byte		N04   , En4 , v072
	.byte	W17
	.byte		N03   , Cs4 , v076
	.byte	W14
	.byte		N04   , Dn4 , v080
	.byte	W06
	.byte		N05   , Bn3 , v068
	.byte	W05
	.byte		N04   , En3 , v064
	.byte	W06
	.byte		N03   , Dn4 , v076
	.byte	W12
	.byte		N04   , En3 , v060
	.byte	W06
	.byte		N05   , Cs4 , v064
	.byte	W07
	.byte		N07   , Bn3 , v056
	.byte	W05
	.byte		N04   , Cs4 , v068
	.byte	W12
	.byte		N06   , Bn3 , v076
	.byte	W06
	.byte		N56   , An3 
	.byte	W78
	.byte		        An3 , v084
	.byte	W56
	.byte	W03
	.byte		N14   , An3 , v076
	.byte	W13
	.byte		N12   , Bn3 
	.byte	W11
	.byte		N13   , An3 , v072
	.byte	W13
	.byte		N20   , Fs3 , v076
	.byte	W19
	.byte		N17   , An3 
	.byte	W15
	.byte		N16   , Bn3 , v068
	.byte	W14
	.byte		N22   , An3 
	.byte	W22
	.byte		N24   , Dn4 , v080
	.byte	W24
	.byte	W02
	.byte	W12
	.byte		N13   , Cs4 , v076
	.byte	W13
	.byte		        Dn4 
	.byte	W12
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N15   , En4 , v080
	.byte	W17
	.byte		N04   , As4 , v072
	.byte	W01
	.byte		N18   , Bn4 , v088
	.byte	W17
	.byte		N15   , An4 , v080
	.byte	W13
	.byte	W01
	.byte		N11   , Gn4 , v084
	.byte	W17
	.byte		N10   , Fs4 , v080
	.byte	W14
	.byte		N08   , En4 
	.byte	W15
	.byte		N28   , Dn4 , v076
	.byte	W48
	.byte		N21   , Bn3 , v084
	.byte	W01
	.byte	W22
	.byte		N07   , Cn4 , v080
	.byte	W13
	.byte		N08   , Bn3 
	.byte	W22
	.byte		N05   , Cs4 , v076
	.byte	W04
	.byte		        Bn3 
	.byte	W11
	.byte		N03   , Ds4 , v084
	.byte	W12
	.byte		N04   , Fs4 , v080
	.byte	W12
	.byte	W01
	.byte		N17   , Bn4 , v088
	.byte	W16
	.byte		N06   , As4 
	.byte	W15
	.byte		N05   , An4 , v080
	.byte	W15
	.byte		N28   , Gn4 , v084
	.byte	W36
	.byte	W01
	.byte		N05   , En4 , v072
	.byte	W06
	.byte		N07   , Fs4 , v064
	.byte	W06
	.byte		N03   , En4 , v080
	.byte	W11
	.byte		N04   , En5 , v084
	.byte	W24
	.byte	W01
	.byte		N06   , En4 , v068
	.byte	W05
	.byte		N07   , Fs4 , v072
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W12
	.byte		N04   , Dn5 , v080
	.byte	W24
	.byte	W01
	.byte		        En4 , v076
	.byte	W12
	.byte	W12
	.byte		        Cs5 , v080
	.byte	W12
	.byte		N03   , Bn4 , v084
	.byte	W12
	.byte		N04   , As4 
	.byte	W12
	.byte		N05   , An4 , v092
	.byte	W48
	.byte	GOTO
	 .word	mus_field_ruby2_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_field_ruby2_3:  @ 0x0869CEDE
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_3_B1:
	.byte		VOICE , 12
	.byte		VOL   , 102*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N05   , En3 , v064
	.byte	W05
	.byte		N06   , An3 , v072
	.byte	W06
	.byte		N05   , Cs4 , v068
	.byte	W05
	.byte		N01   , En4 , v076
	.byte	W07
	.byte		N03   , An4 , v088
	.byte	W01
	.byte	W13
	.byte		N05   , En4 , v064
	.byte	W05
	.byte		        Cs4 , v072
	.byte	W06
	.byte		N02   , An3 , v052
	.byte	W11
	.byte		N03   , An4 , v088
	.byte	W24
	.byte		N04   , Fs4 , v072
	.byte	W13
	.byte		        Dn4 , v080
	.byte	W12
	.byte		N03   , An3 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		N05   , Cs4 , v068
	.byte	W04
	.byte		N08   , En4 , v064
	.byte	W08
	.byte		N04   , An4 , v084
	.byte	W07
	.byte		N03   , En4 , v076
	.byte	W12
	.byte		        An4 
	.byte	W05
	.byte		N07   , Cs5 , v060
	.byte	W06
	.byte		N03   , Dn5 , v084
	.byte	W12
	.byte		N04   , An4 
	.byte	W12
	.byte		        Fs4 , v076
	.byte	W12
	.byte		N03   , Dn4 , v080
	.byte	W12
	.byte		        En4 , v084
	.byte	W68
	.byte	W03
	.byte		N06   , En4 , v080
	.byte	W07
	.byte		N05   , An4 , v072
	.byte	W06
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		        An4 , v072
	.byte	W06
	.byte		N04   , En4 , v068
	.byte	W12
	.byte		N06   , Cs5 , v084
	.byte	W06
	.byte		N04   , An4 , v076
	.byte	W11
	.byte		N06   , En5 , v088
	.byte	W05
	.byte		N03   , Cs5 , v076
	.byte	W12
	.byte		N06   , Dn5 , v088
	.byte	W05
	.byte		        An4 , v076
	.byte	W07
	.byte		N05   , Fs4 , v064
	.byte	W06
	.byte		N06   , Dn4 , v056
	.byte	W06
	.byte		N08   , An4 , v084
	.byte	W08
	.byte		N07   , Fs4 , v060
	.byte	W06
	.byte		N06   , Dn4 , v064
	.byte	W06
	.byte		        An3 , v056
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        Cs4 , v060
	.byte	W06
	.byte		N05   , An3 
	.byte	W06
	.byte		N07   , En3 , v052
	.byte	W06
	.byte		        Cs4 , v072
	.byte	W05
	.byte		N04   , An3 , v056
	.byte	W05
	.byte		N03   , En3 
	.byte	W06
	.byte		        Cs3 , v060
	.byte	W06
	.byte		N06   , An3 , v080
	.byte	W06
	.byte		N07   , Fs3 , v068
	.byte	W06
	.byte		N06   , Dn3 , v056
	.byte	W07
	.byte		        An2 , v060
	.byte	W05
	.byte		N07   , Fs3 , v072
	.byte	W06
	.byte		N04   , Dn3 , v056
	.byte	W05
	.byte		N02   , An2 , v064
	.byte	W07
	.byte		N03   , Fs2 , v068
	.byte	W07
	.byte		N04   , En2 , v084
	.byte	W01
	.byte	W12
	.byte		N02   , An2 
	.byte	W13
	.byte		N01   , Cs3 , v072
	.byte	W13
	.byte		N04   , En3 , v060
	.byte	W13
	.byte		N03   , Dn3 
	.byte	W11
	.byte		N04   , Fs3 , v076
	.byte	W11
	.byte		N01   , An3 
	.byte	W13
	.byte		N03   , Dn4 
	.byte	W10
	.byte	W11
	.byte		N05   , Cs4 
	.byte	W13
	.byte		N02   , An3 , v068
	.byte	W12
	.byte		N03   , En3 , v076
	.byte	W23
	.byte		N04   , Fs3 
	.byte	W13
	.byte		N02   , Dn3 , v064
	.byte	W12
	.byte		N04   , An2 , v076
	.byte	W12
	.byte	W14
	.byte		N03   , An3 , v084
	.byte	W19
	.byte		N04   , En3 
	.byte	W24
	.byte	W02
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 , v080
	.byte	W13
	.byte		        Dn4 , v092
	.byte	W12
	.byte	W12
	.byte		        Cs4 , v084
	.byte	W19
	.byte		        An3 , v080
	.byte	W18
	.byte		        Fs3 , v088
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		N03   , An2 , v084
	.byte	W11
	.byte	W01
	.byte		N04   , En3 , v080
	.byte	W12
	.byte		N05   , Cs3 , v072
	.byte	W05
	.byte		        En3 , v076
	.byte	W04
	.byte		N04   , An3 
	.byte	W13
	.byte		N06   , En3 
	.byte	W05
	.byte		        An3 
	.byte	W07
	.byte		N05   , Cs4 , v064
	.byte	W05
	.byte		N07   , An3 
	.byte	W06
	.byte		N06   , Cs4 , v076
	.byte	W06
	.byte		N09   , Dn4 , v084
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W14
	.byte		        Bn3 , v092
	.byte	W12
	.byte		N05   , Cs4 , v088
	.byte	W14
	.byte		N04   , Bn3 
	.byte	W05
	.byte		N48   , An3 , v080
	.byte	W76
	.byte	W01
	.byte	W72
	.byte		N06   , Cs4 
	.byte	W07
	.byte		N04   , Dn4 , v064
	.byte	W04
	.byte		N05   , Cs4 , v068
	.byte	W05
	.byte		N08   , Dn4 , v072
	.byte	W07
	.byte		N04   , En4 , v088
	.byte	W01
	.byte	W11
	.byte		N05   , Cs4 , v068
	.byte	W06
	.byte		        Dn4 
	.byte	W05
	.byte		N06   , Cs4 , v060
	.byte	W05
	.byte		N08   , Dn4 , v068
	.byte	W07
	.byte		N03   , En4 , v084
	.byte	W24
	.byte	W02
	.byte		N03
	.byte	W13
	.byte		N04
	.byte	W12
	.byte		N05
	.byte	W11
	.byte		N06   , En4 , v092
	.byte	W24
	.byte	W01
	.byte		N04   , Dn4 , v080
	.byte	W11
	.byte		        Cs4 
	.byte	W13
	.byte		        Bn3 
	.byte	W22
	.byte		        En4 , v088
	.byte	W24
	.byte	W01
	.byte		N30   , Cs4 
	.byte	W30
	.byte	W01
	.byte		N05   , Bn3 , v064
	.byte	W06
	.byte		N04   , An3 , v056
	.byte	W03
	.byte		N08   , Bn3 , v064
	.byte	W07
	.byte		N30   , Cs4 , v084
	.byte	W30
	.byte		N05   , Bn3 , v064
	.byte	W05
	.byte		        An3 
	.byte	W05
	.byte		N07   , Bn3 , v068
	.byte	W07
	.byte		N03   , Cs4 , v084
	.byte	W02
	.byte	W10
	.byte		N04   , Bn3 , v072
	.byte	W05
	.byte		        An3 , v068
	.byte	W13
	.byte		N06   , Bn3 , v076
	.byte	W05
	.byte		N03   , Cs4 , v080
	.byte	W13
	.byte		N04   , An3 , v084
	.byte	W12
	.byte		        Fs3 , v080
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        Fs3 , v084
	.byte	W13
	.byte		N06   , En3 , v076
	.byte	W01
	.byte	W05
	.byte		        An3 , v072
	.byte	W06
	.byte		N03   , Cs4 , v068
	.byte	W14
	.byte		N06   , An3 , v076
	.byte	W05
	.byte		        Cs4 , v072
	.byte	W06
	.byte		N03   , En4 , v080
	.byte	W24
	.byte		N02   , Dn4 , v076
	.byte	W13
	.byte		N04   , En4 , v080
	.byte	W11
	.byte		N03   , Fs4 , v084
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        An4 
	.byte	W13
	.byte		N04   , Cs5 , v088
	.byte	W12
	.byte		N03   , An4 , v084
	.byte	W12
	.byte		        En5 , v088
	.byte	W04
	.byte		N04   , An4 , v064
	.byte	W03
	.byte		N03   , En5 , v072
	.byte	W05
	.byte		N02   , An4 , v056
	.byte	W03
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		N03   , An4 , v056
	.byte	W03
	.byte		N02   , En5 , v064
	.byte	W03
	.byte		N03   , An4 , v056
	.byte	W03
	.byte		        En5 , v064
	.byte	W04
	.byte		N01   , An4 , v044
	.byte	W16
	.byte		N07   , An3 , v080
	.byte	W06
	.byte		N05   , Bn3 , v072
	.byte	W06
	.byte		N06   , An3 , v064
	.byte	W05
	.byte		N07   , Bn3 
	.byte	W07
	.byte		N04   , An3 , v076
	.byte	W11
	.byte		N06   , Cs4 , v068
	.byte	W06
	.byte		N04   , An3 , v072
	.byte	W13
	.byte		N06   , En4 , v080
	.byte	W05
	.byte		N03   , Cs4 , v076
	.byte	W12
	.byte		        An4 , v088
	.byte	W24
	.byte	W01
	.byte	W02
	.byte		N06   , An3 , v076
	.byte	W06
	.byte		N05   , Bn3 , v072
	.byte	W06
	.byte		N06   , An3 , v068
	.byte	W05
	.byte		        Bn3 , v056
	.byte	W07
	.byte		N04   , An3 , v068
	.byte	W11
	.byte		N05   , Dn4 , v072
	.byte	W05
	.byte		N03   , An3 , v068
	.byte	W15
	.byte		N04   , Fs4 , v076
	.byte	W04
	.byte		N03   , Dn4 , v072
	.byte	W13
	.byte		        An4 , v088
	.byte	W22
	.byte	W01
	.byte		N06   , An3 , v072
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N05   , An3 
	.byte	W05
	.byte		        Bn3 , v060
	.byte	W06
	.byte		N03   , An3 
	.byte	W11
	.byte		N06   , Cs4 , v076
	.byte	W06
	.byte		N04   , An3 , v072
	.byte	W13
	.byte		N07   , En4 , v076
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W13
	.byte		        An4 , v088
	.byte	W23
	.byte	W01
	.byte		N06   , An3 , v080
	.byte	W06
	.byte		N05   , Bn3 , v076
	.byte	W05
	.byte		N06   , An3 , v064
	.byte	W05
	.byte		        Bn3 , v060
	.byte	W07
	.byte		N04   , An3 , v064
	.byte	W11
	.byte		N05   , Dn4 , v072
	.byte	W06
	.byte		N02   , An3 , v068
	.byte	W14
	.byte		N05   , Fs4 , v076
	.byte	W05
	.byte		N02   , Dn4 , v072
	.byte	W12
	.byte		N04   , An4 , v092
	.byte	W23
	.byte		N06   , Bn3 , v080
	.byte	W01
	.byte	W05
	.byte		N07   , Cs4 , v076
	.byte	W06
	.byte		N06   , Bn3 , v064
	.byte	W05
	.byte		N07   , Cs4 , v068
	.byte	W07
	.byte		N04   , Bn3 
	.byte	W12
	.byte		N06   , Ds4 , v080
	.byte	W05
	.byte		N04   , Bn3 , v072
	.byte	W14
	.byte		N07   , Fs4 , v084
	.byte	W06
	.byte		N02   , Ds4 , v076
	.byte	W12
	.byte		N04   , Bn4 , v092
	.byte	W23
	.byte		N06   , Bn3 , v076
	.byte	W01
	.byte	W05
	.byte		        En4 
	.byte	W07
	.byte		        Bn3 , v068
	.byte	W06
	.byte		        En4 
	.byte	W07
	.byte		N03   , Bn3 , v080
	.byte	W11
	.byte		N05   , Gn4 , v084
	.byte	W06
	.byte		N02   , En4 , v068
	.byte	W12
	.byte		N05   , Bn4 , v088
	.byte	W06
	.byte		N03   , Gn4 , v076
	.byte	W12
	.byte		N05   , En5 , v096
	.byte	W23
	.byte		N06   , Gs4 , v076
	.byte	W01
	.byte	W05
	.byte		N07   , Bn4 , v072
	.byte	W07
	.byte		N06   , Gs4 , v068
	.byte	W05
	.byte		N05   , Bn4 , v072
	.byte	W07
	.byte		N04   , En5 , v088
	.byte	W23
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		N07   , Bn4 , v076
	.byte	W07
	.byte		N05   , Gs4 , v072
	.byte	W05
	.byte		N07   , Bn4 , v076
	.byte	W06
	.byte		N04   , En5 , v088
	.byte	W24
	.byte	W01
	.byte		N05   , An4 , v080
	.byte	W05
	.byte		N07   , Cs5 , v072
	.byte	W06
	.byte		N06   , An4 
	.byte	W05
	.byte		N09   , Cs5 
	.byte	W54
	.byte	W01
	.byte		N03   , Gs5 , v088
	.byte		N05   , An5 , v100
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_field_ruby2_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_field_ruby2_4:  @ 0x0869D248
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_4_B1:
	.byte		VOICE , 32
	.byte		VOL   , 85*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v+0
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
	.byte		N21   , An1 , v088
	.byte	W24
	.byte		        Bn1 , v084
	.byte	W24
	.byte		N20   , Cn2 
	.byte	W24
	.byte		N22   , Cs2 
	.byte	W24
	.byte		N16   , Dn2 
	.byte	W24
	.byte		N18   , En2 
	.byte	W24
	.byte		N17   , Fn2 , v080
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte	W01
	.byte		        An1 , v084
	.byte	W22
	.byte		N18   , Bn1 , v080
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		N19   , Cs2 
	.byte	W24
	.byte	W01
	.byte		N18   , Dn2 , v084
	.byte	W23
	.byte		N20   , En2 
	.byte	W24
	.byte	W01
	.byte		N18   , Fn2 , v080
	.byte	W24
	.byte		        Fs2 , v084
	.byte	W24
	.byte		N19   , Bn1 
	.byte	W24
	.byte		        Cs2 
	.byte	W23
	.byte		N20   , Dn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte	W01
	.byte		        En2 
	.byte	W23
	.byte		N19   , Fs2 , v080
	.byte	W24
	.byte		N20   , Gn2 , v084
	.byte	W24
	.byte		        Gs2 , v088
	.byte	W24
	.byte	W01
	.byte	W01
	.byte		N08   , En2 , v092
	.byte	W23
	.byte		N05   , En1 , v084
	.byte	W13
	.byte		N04   , En2 , v092
	.byte	W23
	.byte		        En1 , v084
	.byte	W13
	.byte		        En2 , v088
	.byte	W23
	.byte	W01
	.byte		N05   , An1 , v084
	.byte	W18
	.byte		N04   , An1 , v080
	.byte	W05
	.byte		        En2 , v084
	.byte	W12
	.byte		        An1 , v088
	.byte	W22
	.byte		N03   , En2 , v084
	.byte	W13
	.byte		N05   , An1 , v092
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_field_ruby2_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_field_ruby2_5:  @ 0x0869D2E9
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_5_B1:
	.byte		VOICE , 16
	.byte		VOL   , 33*mus_field_ruby2_mvl/mxv
	.byte		PAN   , c_v+0
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
	.byte	W24
	.byte		N05   , An5 , v084
	.byte	W48
	.byte		N05
	.byte	W24
	.byte	W12
	.byte		N02   , An5 , v072
	.byte	W12
	.byte		N04   , An5 , v068
	.byte	W12
	.byte		        An5 , v072
	.byte	W32
	.byte	W03
	.byte		N05   , An5 , v080
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		N04   , An5 , v084
	.byte	W48
	.byte	W01
	.byte		N05
	.byte	W23
	.byte	W11
	.byte		N04   , An5 , v076
	.byte	W12
	.byte		N05
	.byte	W12
	.byte		N04   , An5 , v072
	.byte	W36
	.byte	W01
	.byte		        An5 , v080
	.byte	W24
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W44
	.byte	W02
	.byte		N03
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		        An5 , v072
	.byte	W36
	.byte		        An5 , v068
	.byte	W12
	.byte		N04   , Dn6 , v080
	.byte	W12
	.byte		N03   , An5 , v072
	.byte	W12
	.byte	W24
	.byte		N04   , An5 , v076
	.byte	W48
	.byte		N04
	.byte	W24
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N02   , Bn5 , v064
	.byte	W12
	.byte		N04   , En6 , v080
	.byte	W12
	.byte		        Bn5 , v072
	.byte	W12
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
	.byte	GOTO
	 .word	mus_field_ruby2_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_field_ruby2_6:  @ 0x0869D36E
	.byte	KEYSH , mus_field_ruby2_key+0
mus_field_ruby2_6_B1:
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_field_ruby2_mvl/mxv
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 , v052
	.byte		N03   , En3 , v028
	.byte	W06
mus_field_ruby2_6_B2:
	.byte		N03   , Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 , v052
	.byte		N03   , En3 , v028
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_6_B2
mus_field_ruby2_6_B3:
	.byte		N03   , Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 , v052
	.byte		N03   , En3 , v028
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
	.byte	PATT
	 .word	mus_field_ruby2_6_B3
mus_field_ruby2_6_B4:
	.byte		N03   , Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
	.byte	PATT
	 .word	mus_field_ruby2_6_B4
mus_field_ruby2_6_B5:
	.byte		N03   , Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Dn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_6_B5
	.byte	PATT
	 .word	mus_field_ruby2_6_B5
	.byte		N03   , Cn1 , v100
	.byte		N03   , En3 , v028
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N03   , Dn3 , v028
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W08
	.byte		N01   , Dn1 , v100
	.byte	W02
	.byte		N01
	.byte	W02
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
mus_field_ruby2_6_B6:
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		        Dn3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W06
	.byte		        Dn3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Dn3 , v028
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Dn3 , v028
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W06
	.byte		        Dn3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_field_ruby2_6_B6
	.byte	PATT
	 .word	mus_field_ruby2_6_B6
	.byte	PATT
	 .word	mus_field_ruby2_6_B6
	.byte	PATT
	 .word	mus_field_ruby2_6_B6
	.byte	PATT
	 .word	mus_field_ruby2_6_B6
	.byte		N03   , Cn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N03
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N03
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03
	.byte	W12
	.byte		N03
	.byte	W12
	.byte		N03
	.byte	W12
	.byte		N03
	.byte		N03   , En3 , v052
	.byte	W04
	.byte		        En3 , v028
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Dn1 , v100
	.byte		N03   , En3 , v052
	.byte	W24
	.byte	GOTO
	 .word	mus_field_ruby2_6_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_field_ruby2:  @ 0x0869D57C
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_field_ruby2_pri	@ Priority
	.byte	mus_field_ruby2_rev	@ Reverb

	.word	mus_field_ruby2_grp

	.word	mus_field_ruby2_0
	.word	mus_field_ruby2_1
	.word	mus_field_ruby2_2
	.word	mus_field_ruby2_3
	.word	mus_field_ruby2_4
	.word	mus_field_ruby2_5
	.word	mus_field_ruby2_6
@ 0x0869D5A0
