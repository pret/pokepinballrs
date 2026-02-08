	.include "sound/MPlayDef.s"

	.equ	mus_field_sapphire_grp, gUnknown_08532808
	.equ	mus_field_sapphire_pri, 0
	.equ	mus_field_sapphire_rev, reverb_set+50
	.equ	mus_field_sapphire_mvl, 127
	.equ	mus_field_sapphire_key, 0
	.equ	mus_field_sapphire_tbs, 1
	.equ	mus_field_sapphire_exg, 0
	.equ	mus_field_sapphire_cmp, 1

	.section .rodata
	.global	mus_field_sapphire
	.align	2

@*********************** Track 01 ***********************@

mus_field_sapphire_0:  @ 0x08694578
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte	TEMPO , 144*mus_field_sapphire_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 108*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N22   , Cn4 , v100
	.byte	W22
	.byte		N04   , Dn4 , v064
	.byte	W05
	.byte		N05   , Ds4 , v084
	.byte	W06
	.byte		N03   , En4 , v088
	.byte	W15
	.byte		        Bn4 , v104
	.byte	W02
	.byte		N24   , Cn5 , v108
	.byte	W24
	.byte	W01
	.byte		N02   , Gn4 , v080
	.byte	W08
	.byte		N15   , En4 , v092
	.byte	W15
	.byte		N02   , Cn4 , v076
	.byte	W09
	.byte		N13   , Gn3 , v096
	.byte	W15
	.byte		N03   , Cn3 , v084
	.byte	W23
	.byte		N04   , Cn2 , v096
	.byte	W07
	.byte		N05   , Cn1 , v084
	.byte	W24
	.byte	W03
	.byte	W96
	.byte	W96
mus_field_sapphire_0_B1:
	.byte		N04   , Fn3 , v100
	.byte	W23
	.byte		        Fn3 , v096
	.byte	W24
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N11   , Fn3 , v076
	.byte	W08
	.byte		N17   , Gn3 , v088
	.byte	W16
	.byte		N48   , An3 , v096
	.byte	W09
	.byte	W60
	.byte	W02
	.byte		N10   , Fn3 , v068
	.byte	W09
	.byte		N18   , Gn3 , v088
	.byte	W17
	.byte		N10   , An3 , v072
	.byte	W08
	.byte		N05   , Dn4 , v088
	.byte	W23
	.byte		N04   , An3 
	.byte	W23
	.byte		N17   , Gn3 , v096
	.byte	W17
	.byte		N04   , Fs3 , v092
	.byte	W22
	.byte		N23   , Gn3 , v096
	.byte	W11
	.byte	W12
	.byte		N05   , Dn3 , v088
	.byte	W48
	.byte	W03
	.byte		N09   , Dn3 , v092
	.byte	W09
	.byte		N18   , En3 , v076
	.byte	W16
	.byte		N10   , Fs3 , v080
	.byte	W08
	.byte		N06   , Gn3 , v096
	.byte	W24
	.byte		N04   , Gn3 , v100
	.byte	W23
	.byte		N16   , An3 
	.byte	W16
	.byte		N10   , Gn3 , v080
	.byte	W08
	.byte		N17   , An3 , v096
	.byte	W16
	.byte		N48   , As3 , v108
	.byte	W09
	.byte	W60
	.byte	W02
	.byte		N10   , Gn3 , v084
	.byte	W09
	.byte		N16   , An3 , v096
	.byte	W15
	.byte		N09   , As3 , v084
	.byte	W07
	.byte		N04   , En4 , v092
	.byte	W03
	.byte	W21
	.byte		N06   , Dn4 , v104
	.byte	W24
	.byte	W02
	.byte		N18   , Cn4 , v108
	.byte	W16
	.byte		N04   , As3 , v092
	.byte	W23
	.byte		N24   , Gs3 , v104
	.byte	W10
	.byte	W13
	.byte		N05   , An3 , v084
	.byte	W80
	.byte	W03
	.byte		        Fn3 , v104
	.byte	W24
	.byte	W01
	.byte		N04   , Fn3 , v100
	.byte	W23
	.byte		N16   , Gn3 , v092
	.byte	W16
	.byte		N08   , Fn3 , v072
	.byte	W07
	.byte		N17   , Gn3 , v084
	.byte	W16
	.byte		N24   , Gs3 , v100
	.byte	W09
	.byte	W14
	.byte		N05   , An3 , v088
	.byte	W48
	.byte		N10   , Fn3 , v076
	.byte	W09
	.byte		N16   , Gn3 , v088
	.byte	W16
	.byte		N10   , An3 , v076
	.byte	W08
	.byte		N06   , Cn4 , v100
	.byte	W01
	.byte	W22
	.byte		N05   , Fn3 
	.byte	W24
	.byte		N18   , An3 , v096
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W24
	.byte	W01
	.byte		N24   , Fn4 , v108
	.byte	W09
	.byte	W13
	.byte		N11   , Dn4 , v100
	.byte	W08
	.byte		N17   , As3 , v088
	.byte	W17
	.byte		N04   , Fn3 , v092
	.byte	W24
	.byte		N10   , Fn3 , v076
	.byte	W08
	.byte		N17   , As3 , v088
	.byte	W16
	.byte		N09   , Dn4 , v084
	.byte	W07
	.byte		N03   , Gn4 , v104
	.byte	W03
	.byte	W21
	.byte		N05   , Fn4 , v108
	.byte	W24
	.byte	W01
	.byte		N04   , En4 , v104
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N07   , Cn4 
	.byte	W02
	.byte	W23
	.byte		N16   , Cn4 , v096
	.byte	W15
	.byte		N13   , Dn4 , v100
	.byte	W24
	.byte		N09   , An3 , v092
	.byte	W08
	.byte		N15   , Fs3 , v096
	.byte	W15
	.byte		N11   , Dn4 , v088
	.byte	W09
	.byte		N05   , Cn4 , v092
	.byte	W02
	.byte	W21
	.byte		N06   , As3 , v100
	.byte	W24
	.byte	W01
	.byte		N07   , An3 , v096
	.byte	W24
	.byte		N06   , Gn3 , v092
	.byte	W24
	.byte		        Fn3 , v096
	.byte	W02
	.byte	W22
	.byte		N05   , Cn4 , v100
	.byte	W15
	.byte		N03   , Fn4 , v104
	.byte	W56
	.byte	W03
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
	.byte		N06   , Fn4 , v096
	.byte	W24
	.byte		        Fn4 , v100
	.byte	W24
	.byte		N15
	.byte	W16
	.byte		N08   , Dn4 , v080
	.byte	W07
	.byte		N14   , Fn4 , v092
	.byte	W15
	.byte		N23   , En4 
	.byte	W10
	.byte	W14
	.byte		N05   , Fn4 , v076
	.byte	W04
	.byte		N09   , Fs4 , v088
	.byte	W06
	.byte		N24   , Gn4 , v092
	.byte	W36
	.byte	W03
	.byte		N08
	.byte	W08
	.byte		N17   , En4 , v088
	.byte	W17
	.byte		N09   , Gn4 , v080
	.byte	W07
	.byte		N07   , An4 , v100
	.byte	W01
	.byte	W24
	.byte		        An4 , v092
	.byte	W24
	.byte		N17   , An4 , v104
	.byte	W18
	.byte		N09   , Gn4 , v084
	.byte	W07
	.byte		N17   , Fn4 , v092
	.byte	W16
	.byte		N24   , Gn4 , v100
	.byte	W07
	.byte	W36
	.byte	W03
	.byte		        Cn5 
	.byte	W24
	.byte	W01
	.byte		N09   , Gn4 , v080
	.byte	W07
	.byte		N16   , En4 , v092
	.byte	W16
	.byte		N09   , Cn4 , v076
	.byte	W08
	.byte		N05   , Fn4 , v104
	.byte	W01
	.byte	W23
	.byte		        Fn4 , v096
	.byte	W24
	.byte		N16   , Fn4 , v100
	.byte	W16
	.byte		N09   , En4 , v084
	.byte	W09
	.byte		N16   , Dn4 , v092
	.byte	W16
	.byte		N20   , En4 , v096
	.byte	W08
	.byte	W13
	.byte		N05   , Fn4 , v076
	.byte	W04
	.byte		N09   , Fs4 
	.byte	W05
	.byte		N24   , Gn4 , v104
	.byte	W40
	.byte	W01
	.byte		N10   , Gn4 , v096
	.byte	W08
	.byte		N17   , En4 , v092
	.byte	W16
	.byte		N10   , Gn4 
	.byte	W08
	.byte		N09   , Gs4 , v104
	.byte	W01
	.byte	W23
	.byte		N11
	.byte	W24
	.byte		N16
	.byte	W16
	.byte		N11   , Gn4 , v092
	.byte	W08
	.byte		N18   , Fn4 
	.byte	W16
	.byte		N48   , Gn4 , v100
	.byte	W09
	.byte	W36
	.byte	W02
	.byte		N24   , Gs4 , v104
	.byte	W24
	.byte		N10   , Gn4 , v092
	.byte	W08
	.byte		N16   , Gs4 , v104
	.byte	W15
	.byte		N14   , As4 , v092
	.byte	W09
	.byte		N10   , Cn5 , v116
	.byte	W02
	.byte	W17
	.byte		N07   , Cn5 , v104
	.byte	W16
	.byte		        Cn5 , v100
	.byte	W16
	.byte		N08   , Cn5 , v108
	.byte	W17
	.byte		N07
	.byte	W15
	.byte		        Cn5 , v104
	.byte	W15
	.byte	W01
	.byte		N19   , Cn5 , v108
	.byte	W17
	.byte		N18   , Dn5 , v104
	.byte	W17
	.byte		N17   , Ds5 
	.byte	W16
	.byte		N14   , En5 , v112
	.byte	W44
	.byte	W01
	.byte	GOTO
	 .word	mus_field_sapphire_0_B1
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_field_sapphire_1:  @ 0x086947C9
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 32
	.byte		VOL   , 85*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
	.byte	W96
mus_field_sapphire_1_B1:
	.byte		N36   , Fn1 , v076
	.byte	W36
	.byte		N40   , Cn2 , v072
	.byte	W36
	.byte		N24   , Cn1 , v060
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_1_B1
mus_field_sapphire_1_B2:
	.byte		N40   , Fn1 , v072
	.byte	W36
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N23   , Cn1 , v060
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
mus_field_sapphire_1_B3:
	.byte		N40   , Fs1 , v072
	.byte	W36
	.byte		N32   , Dn2 
	.byte	W36
	.byte		N24   , Dn1 , v064
	.byte	W24
	.byte	PEND
mus_field_sapphire_1_B4:
	.byte		N40   , Gn1 , v072
	.byte	W36
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N23   , Dn1 , v060
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_1_B4
	.byte	PATT
	 .word	mus_field_sapphire_1_B4
mus_field_sapphire_1_B5:
	.byte		N40   , Gn1 , v076
	.byte	W36
	.byte		N36   , Cn2 , v072
	.byte	W36
	.byte		N24   , Cn1 , v056
	.byte	W24
	.byte	PEND
mus_field_sapphire_1_B6:
	.byte		N36   , Fn1 , v068
	.byte	W36
	.byte		        Cn2 , v060
	.byte	W36
	.byte		N17   , Cn1 , v056
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
mus_field_sapphire_1_B7:
	.byte		N36   , Fn1 , v076
	.byte	W36
	.byte		N32   , Ds2 , v064
	.byte	W36
	.byte		N24   , Fn1 
	.byte	W24
	.byte	PEND
mus_field_sapphire_1_B8:
	.byte		N36   , As1 , v072
	.byte	W36
	.byte		        Fn2 , v060
	.byte	W36
	.byte		N17   , As1 , v064
	.byte	W24
	.byte	PEND
	.byte		N32   , As1 , v072
	.byte	W36
	.byte		N28   , Bn1 
	.byte	W36
	.byte		N24   , Bn1 , v056
	.byte	W24
	.byte		N14   , Cn2 , v064
	.byte	W24
	.byte		        Cn2 , v060
	.byte	W12
	.byte		N32   , Dn2 , v076
	.byte	W60
	.byte		N11   , Gn1 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N09   , Cn2 , v072
	.byte	W24
	.byte		N10   , Cn2 , v068
	.byte	W24
	.byte		N36   , Fn2 , v064
	.byte	W36
	.byte		N07   , Fn1 , v068
	.byte	W24
	.byte		N11
	.byte	W12
	.byte		N05   , Fn0 
	.byte	W24
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
	.byte	PATT
	 .word	mus_field_sapphire_1_B3
	.byte	PATT
	 .word	mus_field_sapphire_1_B4
	.byte	PATT
	 .word	mus_field_sapphire_1_B4
	.byte	PATT
	 .word	mus_field_sapphire_1_B4
	.byte	PATT
	 .word	mus_field_sapphire_1_B5
	.byte	PATT
	 .word	mus_field_sapphire_1_B6
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
	.byte	PATT
	 .word	mus_field_sapphire_1_B2
	.byte	PATT
	 .word	mus_field_sapphire_1_B7
	.byte	PATT
	 .word	mus_field_sapphire_1_B8
	.byte		N32   , As1 , v072
	.byte	W32
	.byte	W03
	.byte		N28   , Bn1 
	.byte	W32
	.byte	W02
	.byte		N24   , Bn1 , v056
	.byte	W24
	.byte	W03
	.byte		N14   , Cn2 , v064
	.byte	W23
	.byte		        Cn2 , v060
	.byte	W12
	.byte		N32   , Dn2 , v076
	.byte	W60
	.byte	W01
	.byte		N11   , Gn1 
	.byte	W24
	.byte		N24
	.byte	W21
	.byte		N09   , Cn2 , v072
	.byte	W24
	.byte		N10   , Cn2 , v068
	.byte	W24
	.byte		N36   , Fn2 , v064
	.byte	W03
	.byte	W96
	.byte		N42   , Gn1 , v084
	.byte	W36
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N24   , Gn1 , v076
	.byte	W24
	.byte		N36   , An1 
	.byte	W36
	.byte		        En2 , v080
	.byte	W36
	.byte		N24   , An1 , v072
	.byte	W24
	.byte		N36   , As1 
	.byte	W36
	.byte		        Fn2 , v076
	.byte	W36
	.byte		N24   , As1 
	.byte	W24
	.byte		N36   , An1 
	.byte	W36
	.byte		        En2 
	.byte	W36
	.byte		N24   , An1 , v072
	.byte	W24
	.byte		N42   , Gn1 , v076
	.byte	W36
	.byte		N32   , Dn2 , v080
	.byte	W36
	.byte		N28   , Gn1 , v076
	.byte	W24
	.byte		N42   , An1 , v080
	.byte	W36
	.byte		N36   , En2 , v088
	.byte	W36
	.byte		N24   , An1 , v080
	.byte	W24
	.byte		N36   , As1 
	.byte	W36
	.byte		N32   , Fn2 
	.byte	W36
	.byte		N28   , As1 , v072
	.byte	W24
	.byte		N42   , Ds1 , v076
	.byte	W36
	.byte		N32   , Ds2 , v080
	.byte	W36
	.byte		N22   , Ds1 , v076
	.byte	W24
	.byte		N36   , Cn2 , v080
	.byte	W36
	.byte		        Cn1 , v076
	.byte	W36
	.byte		N28   , Cn2 , v072
	.byte	W24
	.byte		N36   , Cn1 , v080
	.byte	W36
	.byte		N32   , Cn2 , v076
	.byte	W36
	.byte		N13   , Cn1 , v072
	.byte	W24
	.byte	GOTO
	 .word	mus_field_sapphire_1_B2
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_field_sapphire_2:  @ 0x0869495E
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 24
	.byte		VOL   , 85*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W84
	.byte	W96
mus_field_sapphire_2_B1:
	.byte	W24
	.byte		N08   , Cn2 , v056
	.byte	W08
	.byte		N07   , Fn2 , v060
	.byte	W08
	.byte		N10   , An2 , v064
	.byte	W08
	.byte		N03   , Cn3 , v068
	.byte	W24
	.byte		N02   , An2 , v064
	.byte	W24
	.byte	PEND
mus_field_sapphire_2_B2:
	.byte	W24
	.byte		N08   , Cn2 , v052
	.byte	W08
	.byte		N06   , Fn2 , v064
	.byte	W08
	.byte		N11   , An2 
	.byte	W08
	.byte		N03   , Cn3 , v060
	.byte	W24
	.byte		N02   , An2 , v072
	.byte	W24
	.byte	PEND
mus_field_sapphire_2_B3:
	.byte	PATT
	 .word	mus_field_sapphire_2_B1
	.byte	PATT
	 .word	mus_field_sapphire_2_B2
	.byte	W24
	.byte		N08   , Dn2 , v072
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		N09   , An2 , v072
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte	W24
	.byte		N08   , Dn2 , v068
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N09   , As2 , v064
	.byte	W08
	.byte		N05   , Dn3 , v076
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte	W24
	.byte		N08   , Dn2 , v068
	.byte	W08
	.byte		N07   , Gn2 , v064
	.byte	W08
	.byte		N10   , As2 , v068
	.byte	W08
	.byte		N06   , Dn3 , v072
	.byte	W24
	.byte		N05   , Gn2 , v068
	.byte	W24
	.byte	W24
	.byte		N07   , Dn2 , v064
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N10   , As2 , v072
	.byte	W08
	.byte		N05   , Dn3 
	.byte	W24
	.byte		        Gn2 , v076
	.byte	W24
	.byte	W22
	.byte		N09   , En2 , v072
	.byte	W08
	.byte		N06   , Gn2 , v060
	.byte	W07
	.byte		N12   , Cn3 
	.byte	W09
	.byte		N04   , En3 , v064
	.byte	W24
	.byte	W02
	.byte		N05   , Gn2 , v076
	.byte	W24
	.byte	W22
	.byte		N09   , Fn2 , v072
	.byte	W09
	.byte		N05   , An2 , v064
	.byte	W07
	.byte		N11   , Cn3 
	.byte	W08
	.byte		N05   , Fn3 , v080
	.byte	W24
	.byte	W01
	.byte		N04   , An2 , v076
	.byte	W24
	.byte	W01
	.byte	PATT
	 .word	mus_field_sapphire_2_B1
	.byte	PATT
	 .word	mus_field_sapphire_2_B2
	.byte	W24
	.byte		N08   , Cn2 , v064
	.byte	W08
	.byte		N06   , Fn2 
	.byte	W08
	.byte		N11   , An2 , v068
	.byte	W08
	.byte		N05   , Cn3 
	.byte	W24
	.byte		        Ds2 , v080
	.byte	W24
	.byte	W24
	.byte		N07   , Dn2 , v072
	.byte	W08
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N09   , As2 , v076
	.byte	W08
	.byte		N05   , Dn3 , v080
	.byte	W24
	.byte		        Fn2 , v076
	.byte	W24
	.byte		        Dn2 , v084
	.byte	W23
	.byte		N15   , Dn3 , v088
	.byte	W14
	.byte		N05   , Dn2 , v076
	.byte	W23
	.byte		N10   , Dn3 , v080
	.byte	W09
	.byte		N06   , Dn2 
	.byte	W24
	.byte	W01
	.byte		N07   , Fn2 , v088
	.byte	W02
	.byte	W20
	.byte		N18   , Cn3 
	.byte	W17
	.byte		N05   , Fs2 , v084
	.byte	W23
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N07   , Fs2 , v088
	.byte	W24
	.byte	W01
	.byte		N05   , Gn2 
	.byte	W03
	.byte	W23
	.byte		N08   , Dn3 
	.byte	W07
	.byte		N10   , As2 , v076
	.byte	W08
	.byte		N09   , Gn2 
	.byte	W09
	.byte		N07   , Dn2 , v084
	.byte	W24
	.byte		N06   , En2 , v092
	.byte	W24
	.byte	W01
	.byte		N04   , Fn2 , v072
	.byte	W06
	.byte		N07   , An2 , v084
	.byte	W08
	.byte		N09   , Cn3 , v068
	.byte	W08
	.byte		N04   , Fn3 , v096
	.byte	W17
	.byte		N05   , An2 , v088
	.byte	W56
	.byte	W01
	.byte		        Cn3 , v104
	.byte	W24
	.byte		N06   , Cn3 , v112
	.byte	W24
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N09   , Cn3 , v092
	.byte	W08
	.byte		N16   , As2 , v108
	.byte	W16
	.byte		N24   , An2 , v120
	.byte	W08
	.byte	W15
	.byte		N10   , As2 , v092
	.byte	W10
	.byte		N16   , Bn2 
	.byte	W15
	.byte		N07   , Cn3 , v104
	.byte	W24
	.byte		N09   , Cn3 , v092
	.byte	W09
	.byte		N16   , Dn3 , v100
	.byte	W16
	.byte		N09   , Cn3 , v092
	.byte	W07
	.byte	W01
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N05   , Dn3 
	.byte	W07
	.byte		N09   , Cn3 , v088
	.byte	W08
	.byte		N08   , Ds3 , v104
	.byte	W08
	.byte		N06   , Dn3 , v088
	.byte	W07
	.byte		N09   , Cn3 
	.byte	W08
	.byte		N17   , An3 , v116
	.byte	W17
	.byte		N10   , Fs3 , v080
	.byte	W08
	.byte		N14   , Ds3 , v100
	.byte	W15
	.byte		N22   , Dn3 
	.byte	W09
	.byte	W14
	.byte		N09   , Cn3 , v072
	.byte	W08
	.byte		N15   , As2 , v112
	.byte	W16
	.byte		N09   , An2 , v100
	.byte	W08
	.byte		N07   , As2 , v112
	.byte	W48
	.byte	W02
	.byte		N05   , Dn3 , v084
	.byte	W21
	.byte		        Fs3 , v092
	.byte	W03
	.byte		N12   , Gn3 , v112
	.byte	W13
	.byte		N09   , Dn3 , v092
	.byte	W08
	.byte		N16   , As2 , v100
	.byte	W17
	.byte		N05   , Gn2 , v080
	.byte	W24
	.byte	W02
	.byte		N03   , En3 , v052
	.byte	W02
	.byte		N21   , Fn3 , v112
	.byte	W06
	.byte	W15
	.byte		N09   , Dn3 , v084
	.byte	W08
	.byte		N14   , As2 , v104
	.byte	W16
	.byte		N05   , Gn2 , v092
	.byte	W23
	.byte		N32   , Fn3 , v108
	.byte	W32
	.byte	W02
	.byte	W01
	.byte		N07   , En3 , v100
	.byte	W08
	.byte		N08   , Fn3 , v084
	.byte	W07
	.byte		N07   , En3 , v092
	.byte	W08
	.byte		N09   , Dn3 , v080
	.byte	W08
	.byte		N07   , En3 , v092
	.byte	W06
	.byte		N08   , Dn3 , v076
	.byte	W09
	.byte		N05   , Cn3 , v100
	.byte	W15
	.byte		N06   , Cn4 , v112
	.byte	W08
	.byte		N05   , Cn3 , v092
	.byte	W17
	.byte		N02   , Cn4 , v108
	.byte	W08
	.byte		N09   , An2 , v088
	.byte	W01
	.byte	W07
	.byte		N07   , As2 
	.byte	W08
	.byte		N08   , Bn2 , v080
	.byte	W06
	.byte		N04   , Cn3 , v092
	.byte	W16
	.byte		        Fn3 , v116
	.byte	W56
	.byte	W03
	.byte		N05   , Cn3 , v092
	.byte	W23
	.byte		N07   , Cn3 , v096
	.byte	W23
	.byte		N17   , Dn3 , v104
	.byte	W17
	.byte		N09   , Cn3 , v076
	.byte	W08
	.byte		N15   , As2 , v108
	.byte	W16
	.byte		N24   , An2 
	.byte	W09
	.byte	W14
	.byte		N08   , As2 , v092
	.byte	W08
	.byte		N17   , Bn2 , v108
	.byte	W16
	.byte		N07   , Cn3 , v100
	.byte	W24
	.byte		N08   , Cn3 , v088
	.byte	W07
	.byte		N17   , Dn3 , v104
	.byte	W17
	.byte		N07   , Cn3 , v072
	.byte	W08
	.byte		N09   , Fn2 , v092
	.byte	W02
	.byte	W06
	.byte		        An2 , v104
	.byte	W08
	.byte		N10   , Cn3 , v092
	.byte	W07
	.byte		N05   , Ds3 , v104
	.byte	W16
	.byte		N09   , Fn3 
	.byte	W08
	.byte		        Cn3 , v072
	.byte	W07
	.byte		N08   , Ds3 , v088
	.byte	W07
	.byte		N09   , Fn3 , v092
	.byte	W08
	.byte		N05   , An3 , v104
	.byte	W16
	.byte		N10   , Cn4 , v100
	.byte	W08
	.byte		N08   , As3 , v096
	.byte	W05
	.byte	W03
	.byte		        Fn3 , v092
	.byte	W07
	.byte		        As3 , v104
	.byte	W08
	.byte		N05   , Fn3 
	.byte	W17
	.byte		N06   , Dn4 , v124
	.byte	W60
	.byte	W01
	.byte		N08   , Dn3 , v072
	.byte	W08
	.byte		N07   , Fn3 , v068
	.byte	W08
	.byte		N08   , Dn3 , v088
	.byte	W07
	.byte		        Fn3 , v068
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Fn3 , v068
	.byte	W08
	.byte		        Dn3 , v088
	.byte	W08
	.byte		N06   , Gn3 
	.byte	W07
	.byte		N09   , Dn3 , v076
	.byte	W09
	.byte		N07   , Gn3 , v084
	.byte	W08
	.byte		N08   , Dn3 , v080
	.byte	W07
	.byte		N06   , Gn3 , v092
	.byte	W08
	.byte		N08   , Cn3 , v096
	.byte	W02
	.byte	W06
	.byte		N07   , An3 , v100
	.byte	W08
	.byte		        Cn3 , v092
	.byte	W08
	.byte		        An3 , v104
	.byte	W09
	.byte		        Cn3 , v088
	.byte	W06
	.byte		N08   , An3 , v100
	.byte	W09
	.byte		        Cn3 , v084
	.byte	W07
	.byte		        Fs3 , v088
	.byte	W08
	.byte		        Cn3 , v084
	.byte	W08
	.byte		        Fs3 , v088
	.byte	W09
	.byte		N07   , Cn3 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W09
	.byte		N08   , As2 , v100
	.byte	W03
	.byte	W05
	.byte		N07   , Gn3 , v088
	.byte	W08
	.byte		N08   , As2 , v092
	.byte	W08
	.byte		N06   , Gn3 , v088
	.byte	W08
	.byte		N08   , As2 , v092
	.byte	W08
	.byte		N06   , Gn3 , v088
	.byte	W08
	.byte		N08   , As2 , v100
	.byte	W09
	.byte		N07   , En3 , v076
	.byte	W07
	.byte		N08   , As2 , v100
	.byte	W09
	.byte		N07   , En3 , v084
	.byte	W08
	.byte		        As2 , v088
	.byte	W06
	.byte		N06   , En3 , v068
	.byte	W09
	.byte		N08   , An2 , v092
	.byte	W03
	.byte	W06
	.byte		N07   , As2 , v088
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W17
	.byte		N04   , Fn3 , v116
	.byte	W24
	.byte	W01
	.byte		N05   , Fn3 , v104
	.byte	W09
	.byte		N02   , Fn4 , v120
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		        Fn2 , v076
	.byte		N06   , As2 , v092
	.byte	W48
	.byte		N09   , Fn2 , v076
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N05   , Dn3 , v072
	.byte	W08
	.byte	W24
	.byte		N03   , Gn2 , v080
	.byte		N05   , Cn3 , v084
	.byte	W48
	.byte		N09   , Gn2 , v072
	.byte	W08
	.byte		N10   , Cn3 , v076
	.byte	W08
	.byte		N05   , En3 , v088
	.byte	W08
	.byte	W24
	.byte		N02   , An2 , v068
	.byte		N06   , Dn3 , v084
	.byte	W44
	.byte	W03
	.byte		N09   , An2 
	.byte	W09
	.byte		N10   , Dn3 , v072
	.byte	W08
	.byte		N05   , Fn3 , v088
	.byte	W08
	.byte	W24
	.byte		N09   , En3 , v084
	.byte	W08
	.byte		N08   , Cn3 , v068
	.byte	W08
	.byte		N09   , Gn2 , v064
	.byte	W08
	.byte		        Cn3 , v068
	.byte	W08
	.byte		        En3 , v064
	.byte	W08
	.byte		N08   , Gn3 , v076
	.byte	W08
	.byte		N09   , En3 , v068
	.byte	W08
	.byte		N08   , Cn3 , v072
	.byte	W08
	.byte		N05   , Gn2 , v080
	.byte	W08
	.byte	W24
	.byte		N03   , Fn2 , v072
	.byte		N05   , As2 , v080
	.byte	W48
	.byte		N09   , Fn2 , v084
	.byte	W08
	.byte		N08   , As2 , v076
	.byte	W08
	.byte		N05   , Dn3 , v072
	.byte	W08
	.byte	W24
	.byte		N02   , Gn2 , v076
	.byte		N04   , Cn3 , v084
	.byte	W48
	.byte		N08   , Gn2 , v080
	.byte	W08
	.byte		N09   , Cn3 , v072
	.byte	W08
	.byte		N04   , En3 , v084
	.byte	W08
	.byte	W24
	.byte		        Gs2 , v076
	.byte		N04   , Cs3 , v088
	.byte	W48
	.byte		N09   , Gs2 , v080
	.byte	W08
	.byte		        Cs3 , v072
	.byte	W08
	.byte		N04   , Fn3 , v092
	.byte	W08
	.byte	W24
	.byte		N05   , As2 , v088
	.byte		N06   , Ds3 , v092
	.byte	W48
	.byte		N10   , As2 , v072
	.byte	W08
	.byte		N08   , Ds3 , v060
	.byte	W08
	.byte		N05   , Gn3 , v076
	.byte	W08
	.byte		N08   , Cn3 , v068
	.byte	W08
	.byte		N09   , Fn3 , v056
	.byte	W08
	.byte		        Gn3 , v064
	.byte	W08
	.byte		        Cn3 , v052
	.byte	W08
	.byte		N08   , Fn3 , v068
	.byte	W08
	.byte		N09   , Gn3 , v072
	.byte	W08
	.byte		        Cn4 , v088
	.byte	W08
	.byte		        Gn3 , v072
	.byte	W08
	.byte		N07   , Fn3 , v076
	.byte	W08
	.byte		N10   , Cn3 
	.byte	W08
	.byte		        Fn3 , v064
	.byte	W08
	.byte		N08   , Gn3 , v068
	.byte	W08
	.byte		N09   , Cn3 , v076
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		N09   , Gn3 
	.byte	W08
	.byte		N08   , Cn4 , v084
	.byte	W08
	.byte		N09   , Gn3 , v060
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		N10   , Cn3 , v064
	.byte	W08
	.byte		N09   , En3 , v052
	.byte	W08
	.byte		N08   , Gn3 , v068
	.byte	W08
	.byte	GOTO
	 .word	mus_field_sapphire_2_B3
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_field_sapphire_3:  @ 0x08694D72
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 68
	.byte		VOL   , 85*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_sapphire_3_B1:
	.byte	W96
	.byte		N05   , Cn3 , v080
	.byte	W24
	.byte	W01
	.byte		N05
	.byte	W21
	.byte		N16   , Dn3 
	.byte	W17
	.byte		N08   , Cn3 , v064
	.byte	W08
	.byte		N10   , Dn3 , v076
	.byte	W15
	.byte		N08   , Ds3 , v080
	.byte	W10
	.byte	W13
	.byte		N17
	.byte	W23
	.byte		N10   , Ds3 , v068
	.byte	W09
	.byte		N15   , Fs3 , v076
	.byte	W16
	.byte		N10   , Ds3 , v060
	.byte	W08
	.byte		N14   , Dn3 , v064
	.byte	W15
	.byte		N12   , Cn3 
	.byte	W10
	.byte		N15   , As2 , v072
	.byte	W02
	.byte	W13
	.byte		N10   , An2 
	.byte	W09
	.byte		N16   , As2 , v076
	.byte	W16
	.byte		N07   , Gn2 , v072
	.byte	W56
	.byte	W02
	.byte	W92
	.byte	W03
	.byte		N06   , Dn3 , v076
	.byte	W01
	.byte	W23
	.byte		N04
	.byte	W23
	.byte		N16   , Gn3 , v080
	.byte	W17
	.byte		N08   , Fs3 , v060
	.byte	W08
	.byte		N17   , Gn3 , v068
	.byte	W15
	.byte		N08   , As3 
	.byte	W10
	.byte	W12
	.byte		N09
	.byte	W09
	.byte		N14   , An3 
	.byte	W15
	.byte		N09   , As3 , v064
	.byte	W09
	.byte		N12   , En4 
	.byte	W08
	.byte		N09   , Ds4 , v052
	.byte	W07
	.byte		        Dn4 
	.byte	W09
	.byte		N05   , Cn4 , v068
	.byte	W17
	.byte		        As3 , v056
	.byte	W08
	.byte		        An3 , v064
	.byte	W02
	.byte	W14
	.byte		        Fn4 , v080
	.byte	W80
	.byte	W02
	.byte		N07   , An3 , v068
	.byte	W24
	.byte		N06   , An3 , v072
	.byte	W23
	.byte		N15   , As3 , v064
	.byte	W15
	.byte		N11   , An3 
	.byte	W09
	.byte		N17   , As3 
	.byte	W17
	.byte		N23   , Bn3 , v076
	.byte	W08
	.byte	W14
	.byte		N05   , Cn4 , v068
	.byte	W24
	.byte		N08   , Cn4 , v052
	.byte	W07
	.byte		N19   , Fn4 
	.byte	W19
	.byte		N07   , Gn4 , v072
	.byte	W08
	.byte		N04   , Gs4 , v060
	.byte	W05
	.byte		N08   , An4 , v064
	.byte	W08
	.byte		N10   , Cn5 , v076
	.byte	W08
	.byte		N06   , Fn5 , v080
	.byte	W03
	.byte	W13
	.byte		N09   , En5 , v068
	.byte	W09
	.byte		N05   , Ds5 , v072
	.byte	W15
	.byte		N08   , Cn5 , v068
	.byte	W23
	.byte		N19   , An4 
	.byte	W24
	.byte	W01
	.byte		N03   , Cn5 , v060
	.byte	W08
	.byte		N09   , As4 , v064
	.byte	W03
	.byte	W06
	.byte		N08   , An4 
	.byte	W08
	.byte		N07   , As4 , v068
	.byte	W08
	.byte		N06   , Cn5 
	.byte	W15
	.byte		N05   , Dn5 , v076
	.byte	W56
	.byte	W03
	.byte		N08   , Dn4 , v060
	.byte	W24
	.byte		        Dn4 , v068
	.byte	W22
	.byte		        Dn5 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N10   , Cn5 , v068
	.byte	W02
	.byte	W05
	.byte		N09   , An4 , v072
	.byte	W07
	.byte		N10   , Fn4 , v060
	.byte	W10
	.byte		N06   , Cn4 
	.byte	W16
	.byte		N24   , Cs4 , v076
	.byte	W24
	.byte	W01
	.byte		N09   , Dn4 , v064
	.byte	W08
	.byte		N11   , Fs4 
	.byte	W16
	.byte		N04   , An4 , v072
	.byte	W09
	.byte	W24
	.byte		N06   , Gn4 , v068
	.byte	W07
	.byte		        Gs4 
	.byte	W08
	.byte		N07   , An4 , v064
	.byte	W07
	.byte		        As4 , v068
	.byte	W08
	.byte		N08   , Bn4 , v072
	.byte	W08
	.byte		N09   , Cn5 , v064
	.byte	W09
	.byte		N06   , Cs5 , v060
	.byte	W07
	.byte		N09   , Dn5 , v044
	.byte	W07
	.byte		N12   , En5 , v068
	.byte	W09
	.byte		N05   , Fn5 , v080
	.byte	W02
	.byte	W14
	.byte		N03   , Cn5 , v060
	.byte	W08
	.byte		N05   , An4 , v076
	.byte	W16
	.byte		        Fn4 
	.byte	W56
	.byte	W02
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
	 .word	mus_field_sapphire_3_B1
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_field_sapphire_4:  @ 0x08694ED4
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 46
	.byte		VOL   , 85*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_sapphire_4_B1:
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
	.byte		N10   , Gn3 , v048
	.byte	W07
	.byte		N08   , Dn4 , v056
	.byte	W08
	.byte		N09   , Gn4 , v060
	.byte	W07
	.byte		N08   , As4 , v072
	.byte	W09
	.byte		N09   , Dn5 , v056
	.byte	W07
	.byte		N05   , Gn5 , v076
	.byte	W10
	.byte		N07   , Dn5 , v064
	.byte	W06
	.byte		N08   , Gn5 , v068
	.byte	W08
	.byte		        As5 , v060
	.byte	W08
	.byte		N09   , Gn5 , v064
	.byte	W07
	.byte		N08   , As5 
	.byte	W08
	.byte		        Dn6 
	.byte	W09
	.byte		N04   , Gn6 , v076
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N07   , Fn3 , v048
	.byte	W08
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N04   , Fn4 , v076
	.byte	W08
	.byte		N08   , An4 , v068
	.byte	W07
	.byte		        Cn5 , v056
	.byte	W08
	.byte		N07   , Fn5 , v060
	.byte	W08
	.byte		        Cn5 
	.byte	W07
	.byte		N08   , Fn5 , v048
	.byte	W08
	.byte		N05   , An5 , v064
	.byte	W08
	.byte		N08   , Fn5 , v060
	.byte	W08
	.byte		N09   , An5 , v052
	.byte	W09
	.byte		        Cn6 , v072
	.byte	W08
	.byte		N04   , Fn6 , v076
	.byte	W01
	.byte	W96
	.byte	W96
	.byte		N10   , Fn5 , v064
	.byte	W08
	.byte		N08   , Cn5 , v060
	.byte	W08
	.byte		N07   , An4 , v072
	.byte	W08
	.byte		        Fn4 , v060
	.byte	W08
	.byte		N08   , Cn4 , v056
	.byte	W08
	.byte		N06   , An3 , v052
	.byte	W08
	.byte		N08   , Fn3 , v056
	.byte	W08
	.byte		N09   , An3 , v060
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N08   , An4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N10   , Fn5 , v064
	.byte	W08
	.byte		        Dn5 , v060
	.byte	W08
	.byte		N08   , As4 , v064
	.byte	W08
	.byte		N07   , Fn4 , v060
	.byte	W08
	.byte		N08   , Dn4 , v056
	.byte	W08
	.byte		        As3 , v060
	.byte	W08
	.byte		N12   , Fn3 , v056
	.byte	W08
	.byte		N07   , As3 , v060
	.byte	W08
	.byte		N08   , Dn4 , v064
	.byte	W08
	.byte		N09   , Fn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N13   , Dn5 
	.byte	W08
	.byte		N07   , Fn5 , v072
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Fn3 , v052
	.byte	W07
	.byte		N10   , An3 , v056
	.byte	W08
	.byte		N08   , Cn4 , v060
	.byte	W07
	.byte		N07   , Fn4 
	.byte	W08
	.byte		N09   , An4 , v064
	.byte	W07
	.byte		N10   , Cn5 
	.byte	W08
	.byte		N14   , Fn5 
	.byte	W06
	.byte		N10   , An5 , v068
	.byte	W08
	.byte		N12   , Cn6 , v072
	.byte	W09
	.byte		N07   , Fn6 , v084
	.byte	W28
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
	 .word	mus_field_sapphire_4_B1
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_field_sapphire_5:  @ 0x08694FE5
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 40
	.byte		VOL   , 46*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_sapphire_5_B1:
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
	.byte	W96
	.byte	W96
	.byte		N48   , As3 , v068
	.byte	W48
	.byte		        Dn4 , v060
	.byte	W48
	.byte		        Cn4 , v068
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N52   , Fn4 , v076
	.byte	W48
	.byte		N24   , En4 , v068
	.byte	W24
	.byte		        Cn4 , v064
	.byte	W24
	.byte		        An3 , v052
	.byte	W24
	.byte		        En4 , v060
	.byte	W24
	.byte		N48   , As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Cn4 , v068
	.byte	W48
	.byte		        En4 , v076
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte		        Ds4 , v080
	.byte	W48
	.byte		N44   , Gn4 , v076
	.byte	W48
	.byte		N48   , Fn4 , v068
	.byte	W48
	.byte		        Cn4 , v072
	.byte	W48
	.byte		        Gn4 , v080
	.byte	W48
	.byte		N32   , Cn4 , v068
	.byte	W48
	.byte	GOTO
	 .word	mus_field_sapphire_5_B1
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_field_sapphire_6:  @ 0x0869505B
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 80
	.byte		VOL   , 68*mus_field_sapphire_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
mus_field_sapphire_6_B1:
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
	.byte		N18   , An4 , v084
	.byte	W16
	.byte		N10   , Fn4 , v068
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W15
	.byte		N05   , An3 , v060
	.byte	W24
	.byte		N10   , Fn4 , v076
	.byte	W08
	.byte		N17   , Cn4 
	.byte	W16
	.byte		N12   , An3 , v060
	.byte	W09
	.byte		N11   , Fs3 , v072
	.byte	W92
	.byte	W03
	.byte		N20   , As4 , v084
	.byte	W01
	.byte	W15
	.byte		N10   , Gn4 , v064
	.byte	W08
	.byte		N16   , Dn4 , v056
	.byte	W14
	.byte		N07   , As3 , v064
	.byte	W24
	.byte		N10   , Gn4 , v076
	.byte	W09
	.byte		N18   , Dn4 
	.byte	W16
	.byte		N13   , As3 , v060
	.byte	W10
	.byte		N09   , Gn3 , v064
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		N17   , Fn4 , v084
	.byte	W01
	.byte	W15
	.byte		N11   , Cn4 , v064
	.byte	W09
	.byte		N15   , An3 , v068
	.byte	W14
	.byte		N05   , Fn3 , v072
	.byte	W23
	.byte		N12   , Cn4 
	.byte	W09
	.byte		N18   , An3 
	.byte	W17
	.byte		N10   , Fn3 , v064
	.byte	W09
	.byte	W92
	.byte	W03
	.byte		N18   , An4 , v084
	.byte	W01
	.byte	W15
	.byte		N10   , Fn4 , v064
	.byte	W09
	.byte		N15   , Cn4 
	.byte	W14
	.byte		N06   , An3 , v068
	.byte	W23
	.byte		N12   , Fn4 , v076
	.byte	W10
	.byte		N17   , Cn4 
	.byte	W16
	.byte		N08   , An3 , v068
	.byte	W08
	.byte		N10   , Fn3 , v076
	.byte	W01
	.byte	W96
	.byte	W96
	.byte		N08   , Dn5 , v068
	.byte	W24
	.byte		        Dn4 , v072
	.byte	W24
	.byte		N07   , Gn4 , v076
	.byte	W24
	.byte		N08   , Dn5 , v072
	.byte	W24
	.byte		N07   , Cn5 , v080
	.byte	W24
	.byte		N08   , Cn4 , v064
	.byte	W24
	.byte		N07   , Fs4 , v080
	.byte	W24
	.byte		N08   , Cn5 , v076
	.byte	W24
	.byte		N09   , As4 
	.byte	W24
	.byte		        As3 , v068
	.byte	W24
	.byte		N06   , Cn4 , v072
	.byte	W12
	.byte		N05   , Cs4 , v068
	.byte	W12
	.byte		N04   , Dn4 , v076
	.byte	W12
	.byte		N05   , En4 
	.byte	W12
	.byte		N08   , Fn4 
	.byte	W24
	.byte		N07   , Cn4 
	.byte	W24
	.byte		N09   , Fn3 , v072
	.byte	W48
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
	 .word	mus_field_sapphire_6_B1
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_field_sapphire_7:  @ 0x08695147
	.byte	KEYSH , mus_field_sapphire_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_field_sapphire_mvl/mxv
	.byte	W84
	.byte	W72
	.byte		N04   , Dn1 , v100
	.byte	W24
mus_field_sapphire_7_B1:
	.byte		N04   , Cn1 , v100
	.byte	W40
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
mus_field_sapphire_7_B2:
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
	.byte	PATT
	 .word	mus_field_sapphire_7_B1
mus_field_sapphire_7_B3:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N04
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
mus_field_sapphire_7_B4:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		        Dn1 
	.byte	W24
	.byte	PATT
	 .word	mus_field_sapphire_7_B4
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		N04
	.byte	W24
	.byte		        Cn1 
	.byte	W08
	.byte		N04
	.byte	W24
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
	.byte	PATT
	 .word	mus_field_sapphire_7_B3
mus_field_sapphire_7_B5:
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte	PATT
	 .word	mus_field_sapphire_7_B5
	.byte		N04   , Cn1 , v100
	.byte	W24
	.byte		N20   , As1 
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	GOTO
	 .word	mus_field_sapphire_7_B2
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_field_sapphire:  @ 0x08695268
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_field_sapphire_pri	@ Priority
	.byte	mus_field_sapphire_rev	@ Reverb

	.word	mus_field_sapphire_grp

	.word	mus_field_sapphire_0
	.word	mus_field_sapphire_1
	.word	mus_field_sapphire_2
	.word	mus_field_sapphire_3
	.word	mus_field_sapphire_4
	.word	mus_field_sapphire_5
	.word	mus_field_sapphire_6
	.word	mus_field_sapphire_7
