	.include "sound/MPlayDef.s"

	.equ	mus_field_sapphire2_grp, gUnknown_08532808
	.equ	mus_field_sapphire2_pri, 0
	.equ	mus_field_sapphire2_rev, reverb_set+50
	.equ	mus_field_sapphire2_mvl, 127
	.equ	mus_field_sapphire2_key, 0
	.equ	mus_field_sapphire2_tbs, 1
	.equ	mus_field_sapphire2_exg, 0
	.equ	mus_field_sapphire2_cmp, 1

	.section .rodata
	.global	mus_field_sapphire2
	.align	2

@*********************** Track 01 ***********************@

mus_field_sapphire2_0:  @ 0x0869D5A0
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte	TEMPO , 120*mus_field_sapphire2_tbs/2
	.byte		VOICE , 71
	.byte		VOL   , 108*mus_field_sapphire2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 5
	.byte	W02
	.byte		N02   , Cn3 , v056
	.byte	W03
	.byte		N04   , Dn3 , v052
	.byte	W04
	.byte		N05   , Cn3 , v068
	.byte	W06
	.byte		N04   , Bn2 , v060
	.byte	W03
	.byte		N06   , Cn3 , v048
	.byte	W06
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		N06   , Ds3 , v064
	.byte	W06
mus_field_sapphire2_0_B1:
	.byte		N18   , Fn3 , v080
	.byte	W18
	.byte		N07   , Dn3 , v072
	.byte	W06
	.byte		N17   , Fn3 , v080
	.byte	W18
	.byte		N20   , As3 , v076
	.byte	W21
	.byte		N01   , An3 , v060
	.byte	W03
	.byte		N02   , As3 , v052
	.byte	W03
	.byte		N04   , An3 , v068
	.byte	W03
	.byte		N15   , Gn3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N52   , Ds3 , v076
	.byte	W68
	.byte	W03
	.byte		N09   , Ds3 , v060
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W07
	.byte		        Ds3 , v064
	.byte	W10
	.byte		N16   , Gn3 , v076
	.byte	W17
	.byte		N04   , Fn3 
	.byte	W07
	.byte		N07   , Fn3 , v068
	.byte	W07
	.byte		        Gn3 , v072
	.byte	W07
	.byte		N08   , An3 
	.byte	W08
	.byte		N13   , Dn4 , v076
	.byte	W14
	.byte		N02   , Cn4 , v056
	.byte	W04
	.byte		N03   , Dn4 , v064
	.byte	W02
	.byte		N05   , Cn4 , v072
	.byte	W04
	.byte		N15   , An3 , v076
	.byte	W14
	.byte		N06   , Gn3 , v056
	.byte	W12
	.byte		N54   , Fn3 , v076
	.byte	W68
	.byte	W01
	.byte		N08   , Cn3 , v048
	.byte	W08
	.byte		        Dn3 , v056
	.byte	W07
	.byte		N09   , Ds3 , v060
	.byte	W09
	.byte		N16   , Fn3 , v064
	.byte	W03
	.byte	W14
	.byte		N09   , Dn3 , v060
	.byte	W07
	.byte		N17   , Fn3 , v068
	.byte	W17
	.byte		N22   , As3 , v072
	.byte	W22
	.byte		N02   , An3 , v060
	.byte	W04
	.byte		        As3 , v068
	.byte	W03
	.byte		N04   , An3 
	.byte	W04
	.byte		N15   , Gn3 
	.byte	W15
	.byte		N02   , Fn3 , v060
	.byte	W07
	.byte		N16   , Fn3 , v068
	.byte	W03
	.byte	W14
	.byte		N07   , Ds3 , v064
	.byte	W08
	.byte		N32   , Ds4 , v068
	.byte	W48
	.byte	W02
	.byte		N07   , Ds4 , v060
	.byte	W08
	.byte		N08   , Fn4 
	.byte	W06
	.byte		N09   , Ds4 
	.byte	W09
	.byte		N06   , Dn4 , v068
	.byte	W01
	.byte	W16
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N09   , Dn5 , v072
	.byte	W08
	.byte		N08   , As4 
	.byte	W07
	.byte		N09   , Fn4 , v064
	.byte	W09
	.byte		N10   , Dn4 , v068
	.byte	W22
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Cn4 , v044
	.byte	W04
	.byte		N05   , As3 , v068
	.byte	W05
	.byte		N09   , Cn4 , v060
	.byte	W08
	.byte		N56   , As3 , v072
	.byte	W01
	.byte	W96
	.byte	W23
	.byte		N02   , Dn3 , v060
	.byte		N05   , Fn3 , v068
	.byte	W48
	.byte		N02   , Dn3 , v052
	.byte		N06   , Fn3 , v068
	.byte	W24
	.byte	W01
	.byte	W21
	.byte		N05   , Ds3 , v064
	.byte	W01
	.byte		N06   , Cn3 , v056
	.byte	W44
	.byte	W03
	.byte		        Ds3 , v064
	.byte	W01
	.byte		N02   , Cn3 , v048
	.byte	W24
	.byte	W02
	.byte	W23
	.byte		N04   , Ds3 , v056
	.byte		N06   , Gn3 , v060
	.byte	W44
	.byte	W03
	.byte		N05   , Gn3 , v056
	.byte	W01
	.byte		        Ds3 , v048
	.byte	W24
	.byte	W01
	.byte	W21
	.byte		        Fn3 , v060
	.byte	W01
	.byte		N04   , Dn3 , v048
	.byte	W48
	.byte		N07   , Fn3 , v060
	.byte	W01
	.byte		N04   , Dn3 , v048
	.byte	W22
	.byte		N09   , Fn3 , v060
	.byte	W03
	.byte	W06
	.byte		N07   , Gn3 , v064
	.byte	W06
	.byte		N08   , Fn3 , v068
	.byte	W08
	.byte		        En3 , v064
	.byte	W08
	.byte		        Fn3 , v060
	.byte	W08
	.byte		N09   , Gn3 , v056
	.byte	W10
	.byte		N24   , Fn3 , v052
	.byte	W24
	.byte		N06   , As3 , v060
	.byte	W18
	.byte		N02   , As3 , v064
	.byte	W08
	.byte		N08   , As3 , v060
	.byte	W08
	.byte		N07   , Cn4 , v064
	.byte	W06
	.byte		N09   , As3 
	.byte	W09
	.byte		N08   , An3 
	.byte	W07
	.byte		        As3 
	.byte	W08
	.byte		N10   , Cn4 , v068
	.byte	W09
	.byte		N20   , Ds4 , v076
	.byte	W18
	.byte		N19   , Fn4 , v072
	.byte	W17
	.byte		N15   , Ds4 , v064
	.byte	W14
	.byte	W01
	.byte		        Dn4 , v076
	.byte	W15
	.byte		N06   , Ds4 , v068
	.byte	W06
	.byte		N16   , Dn4 , v064
	.byte	W16
	.byte		N04   , Fn4 , v056
	.byte	W23
	.byte		N12   , Gn4 , v060
	.byte	W11
	.byte		N11   , Fn4 , v064
	.byte	W11
	.byte		N13   , En4 , v068
	.byte	W13
	.byte		N68   , Fn4 , v072
	.byte	W96
	.byte		N36   , Dn3 , v056
	.byte	W36
	.byte		N12   , Ds3 , v060
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N13   , Fn3 , v056
	.byte	W12
	.byte		        As3 , v064
	.byte	W12
	.byte		N14   , Fn3 
	.byte	W12
	.byte		N72   , Ds3 
	.byte	W96
	.byte		N36   , Dn3 , v068
	.byte	W36
	.byte	W01
	.byte		N12   , Ds3 , v052
	.byte	W12
	.byte		N08   , Dn3 , v056
	.byte	W07
	.byte		N06   , Fn3 , v068
	.byte	W07
	.byte		N08   , As3 
	.byte	W08
	.byte		N05   , Cn4 , v064
	.byte	W13
	.byte		N09   , Dn4 , v060
	.byte	W12
	.byte		N48   , Ds4 , v076
	.byte	W68
	.byte	W03
	.byte		N08   , Ds4 , v060
	.byte	W09
	.byte		N07   , Fn4 , v052
	.byte	W06
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N04   , Dn4 , v068
	.byte	W02
	.byte	W14
	.byte		N08   , Cn4 , v052
	.byte	W08
	.byte		N28   , As3 , v064
	.byte	W36
	.byte		N14   , As3 , v056
	.byte	W13
	.byte		N12   , Cn4 , v060
	.byte	W12
	.byte		N14   , As3 , v064
	.byte	W13
	.byte		N19   , Gn3 
	.byte	W18
	.byte		N16   , An3 
	.byte	W15
	.byte		N11   , As3 
	.byte	W15
	.byte		N15   , As3 , v060
	.byte	W15
	.byte		N17   , Cn4 , v064
	.byte	W17
	.byte		        Dn4 , v068
	.byte	W15
	.byte		N36   , Ds4 , v072
	.byte	W01
	.byte	W36
	.byte		N04   , Dn4 , v060
	.byte	W05
	.byte		N08   , Cn4 , v064
	.byte	W07
	.byte		N23   , As3 , v068
	.byte	W23
	.byte		N19   , Cn4 
	.byte	W19
	.byte		N07   , Dn4 , v064
	.byte	W06
	.byte	W01
	.byte		N68   , Cn4 , v076
	.byte	W92
	.byte	W03
	.byte		N15   , Fn3 , v072
	.byte	W16
	.byte		N07   , Dn3 , v056
	.byte	W06
	.byte		N05   , Fn3 , v068
	.byte	W15
	.byte		N18   , As3 
	.byte	W20
	.byte		N07   , Cn4 , v052
	.byte	W07
	.byte		N06   , Cs4 , v068
	.byte	W06
	.byte		N08   , Dn4 , v072
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W07
	.byte		N09   , Dn4 , v060
	.byte	W08
	.byte		N72   , Ds4 , v068
	.byte	W03
	.byte	W92
	.byte	W03
	.byte		N22   , Gn3 
	.byte	W01
	.byte	W21
	.byte		N08   , Dn4 , v060
	.byte	W09
	.byte		N07   , Ds4 , v064
	.byte	W07
	.byte		N09   , Cn4 , v060
	.byte	W09
	.byte		N15   , As3 , v064
	.byte	W15
	.byte		N09   , An3 , v060
	.byte	W08
	.byte		N16   , Gn3 , v064
	.byte	W17
	.byte		N06   , An3 , v060
	.byte	W07
	.byte		N52   , Fn4 , v068
	.byte	W03
	.byte	W68
	.byte	W02
	.byte		N09   , Fn4 , v064
	.byte	W09
	.byte		N07   , Gn4 , v068
	.byte	W08
	.byte		N09   , Fn4 , v072
	.byte	W08
	.byte		N23   , Gs4 
	.byte	W01
	.byte	W23
	.byte		N09   , Gn4 , v060
	.byte	W08
	.byte		N08   , Gs4 , v064
	.byte	W07
	.byte		        Gn4 , v060
	.byte	W09
	.byte		N18   , Fn4 , v064
	.byte	W23
	.byte		N07   , Fn4 , v056
	.byte	W07
	.byte		N08   , Ds4 , v064
	.byte	W08
	.byte		N10   , Dn4 , v060
	.byte	W10
	.byte		N36   , Ds4 , v068
	.byte	W01
	.byte	W32
	.byte	W02
	.byte		N13   , Gn4 , v064
	.byte	W13
	.byte		N07   , Cn5 , v080
	.byte	W24
	.byte		N08   , Ds4 , v076
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		N07   , Fn4 
	.byte	W07
	.byte		N06   , En4 , v068
	.byte	W07
	.byte		N07   , Ds4 
	.byte	W07
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Cs4 , v060
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Bn3 , v064
	.byte	W09
	.byte		N06   , As3 , v060
	.byte	W07
	.byte		N10   , An3 
	.byte	W10
	.byte		N56   , As3 , v080
	.byte	W01
	.byte	W60
	.byte	W02
	.byte		N02   , Cn3 , v056
	.byte	W03
	.byte		N04   , Dn3 , v052
	.byte	W04
	.byte		N05   , Cn3 , v068
	.byte	W06
	.byte		N04   , Bn2 , v060
	.byte	W03
	.byte		N06   , Cn3 , v048
	.byte	W06
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		N06   , Ds3 , v064
	.byte	W06
	.byte	GOTO
	 .word	mus_field_sapphire2_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_field_sapphire2_1:  @ 0x0869D8A4
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte		VOICE , 32
	.byte		VOL   , 85*mus_field_sapphire2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W36
mus_field_sapphire2_1_B1:
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N02   , Fn2 
	.byte	W12
	.byte		        Fn1 , v064
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		N01   , Fn1 
	.byte	W12
	.byte		N02   , Fn2 , v060
	.byte	W12
	.byte	PEND
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N03   , Gn1 , v068
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N03   , An1 , v072
	.byte	W12
	.byte		N04   , Fn2 , v064
	.byte	W12
	.byte		N03   , Fn1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v056
	.byte	W12
	.byte		N03   , Cn2 , v064
	.byte	W12
	.byte		N04   , Fn2 , v060
	.byte	W12
	.byte		N02   , Fn1 , v064
	.byte	W12
	.byte		N04   , Fn2 , v060
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		N01   , Fn2 , v064
	.byte	W11
	.byte		N02   , Fn1 , v076
	.byte	W13
	.byte		N01   , Fn2 , v064
	.byte	W13
	.byte		N04   , Cn2 , v068
	.byte	W16
	.byte		        Cn2 , v060
	.byte	W07
	.byte		N19   , Fn1 , v064
	.byte	W24
	.byte		N03   , As1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v064
	.byte	W12
	.byte		N01   , Fn1 , v060
	.byte	W12
	.byte		N03   , Fn2 , v052
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		N02   , Fn2 , v060
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W12
	.byte		        Cn2 , v072
	.byte	W12
	.byte		N02   , Gn2 , v064
	.byte	W12
	.byte		        Gn1 , v072
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N03   , Cn2 , v068
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N04   , Gn1 , v072
	.byte	W12
	.byte		N02   , Gn2 , v068
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N03   , Fn2 , v064
	.byte	W12
	.byte		N04   , As1 , v076
	.byte	W12
	.byte		N02   , Fn2 , v060
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N04   , Fn2 
	.byte	W12
	.byte		N03   , Cn2 , v064
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v060
	.byte	W12
	.byte		N02   , Fn1 , v064
	.byte	W12
	.byte		N04   , Fn2 , v060
	.byte	W12
	.byte		        As1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v060
	.byte	W12
	.byte		        Fn1 , v076
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte	PATT
	 .word	mus_field_sapphire2_1_B1
	.byte		N02   , Cn2 , v068
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N02   , Cn2 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N04   , Gn1 , v060
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N03   , Cn2 , v068
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N04   , Gn1 , v060
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N01   , Cn2 , v052
	.byte	W12
	.byte		N03   , Gn2 , v060
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		N02   , Fn1 
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v060
	.byte	W12
	.byte		N02   , Fn1 , v064
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N02   , Gs1 , v076
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v060
	.byte	W12
	.byte		N04   , Gs1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v048
	.byte	W12
	.byte		        As1 , v064
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        Gn1 , v072
	.byte	W12
	.byte		N04   , Ds2 , v060
	.byte	W12
	.byte		        As1 , v072
	.byte	W12
	.byte		N03   , Ds2 , v064
	.byte	W12
	.byte		N04   , Fs1 
	.byte	W12
	.byte		N05   , Ds2 , v068
	.byte	W12
	.byte		N04   , As1 , v060
	.byte	W12
	.byte		        Ds2 , v068
	.byte	W12
	.byte		N01   , Fn1 , v052
	.byte	W12
	.byte		N05   , Fn2 , v068
	.byte	W12
	.byte		N04   , As1 
	.byte	W12
	.byte		N03   , Fn2 , v064
	.byte	W12
	.byte		N02   , En1 , v068
	.byte	W12
	.byte		N04   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N03   , Gn2 , v064
	.byte	W12
	.byte		N04   , Fn1 , v072
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		N02   , Cn2 , v064
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N02   , Fn1 , v060
	.byte	W12
	.byte		N04   , Fn2 , v052
	.byte	W12
	.byte		N03   , Cn2 , v056
	.byte	W12
	.byte		N05   , Fn2 
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		        Fn2 , v052
	.byte	W12
	.byte		N03   , Fn1 , v064
	.byte	W12
	.byte		N04   , Fn2 , v056
	.byte	W12
	.byte		N02   , As1 , v072
	.byte	W12
	.byte		N04   , Fn2 , v052
	.byte	W12
	.byte		N02   , Fn1 , v060
	.byte	W12
	.byte		N03   , Fn2 , v048
	.byte	W12
	.byte		N01   , Cn2 , v060
	.byte	W12
	.byte		N05   , Gn2 , v056
	.byte	W12
	.byte		N04   , Gn1 , v068
	.byte	W12
	.byte		N03   , Gn2 , v060
	.byte	W12
	.byte		N04   , Cn2 , v068
	.byte	W12
	.byte		N02   , Gn2 , v056
	.byte	W12
	.byte		N04   , Gn1 , v060
	.byte	W12
	.byte		N03   , Gn2 , v056
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		N02   , Fn1 , v064
	.byte	W12
	.byte		N04   , Fn2 , v056
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		N05   , Fn2 , v052
	.byte	W12
	.byte		N04   , Fn1 , v068
	.byte	W12
	.byte		N05   , Fn2 , v052
	.byte	W12
	.byte		N03   , Gs1 , v076
	.byte	W12
	.byte		        Ds2 , v060
	.byte	W12
	.byte		N02   , Ds1 
	.byte	W12
	.byte		N04   , Ds2 
	.byte	W12
	.byte		        Gs1 , v068
	.byte	W12
	.byte		        Ds2 , v060
	.byte	W12
	.byte		N02   , Ds1 , v068
	.byte	W12
	.byte		N04   , Ds2 , v060
	.byte	W12
	.byte		        Gn1 , v076
	.byte	W12
	.byte		N02   , Dn2 , v060
	.byte	W12
	.byte		N04   , Dn1 , v072
	.byte	W12
	.byte		        Dn2 , v060
	.byte	W12
	.byte		N02   , Gn1 , v076
	.byte	W12
	.byte		N03   , Dn2 , v060
	.byte	W12
	.byte		        Dn1 , v068
	.byte	W12
	.byte		N02   , Dn2 , v060
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		N03   , As1 , v056
	.byte	W12
	.byte		N01   , As0 , v068
	.byte	W12
	.byte		N05   , As1 , v060
	.byte	W12
	.byte		N01   , Ds1 , v064
	.byte	W12
	.byte		N05   , As1 , v060
	.byte	W12
	.byte		N02   , As0 , v064
	.byte	W12
	.byte		N05   , As1 , v060
	.byte	W12
	.byte		N02   , Cn1 , v056
	.byte	W12
	.byte		N05   , Cn2 , v064
	.byte	W12
	.byte		N03   , Gn1 , v068
	.byte	W12
	.byte		        Cn2 , v056
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W12
	.byte		        Cn2 , v048
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W12
	.byte		N04   , Cn2 , v056
	.byte	W12
	.byte		        Fn1 , v060
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		N03   , Cn2 , v064
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        Fn1 , v064
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        Cn2 , v060
	.byte	W12
	.byte		        Fn2 , v048
	.byte	W12
	.byte		N04   , As1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v048
	.byte	W12
	.byte		        Fn1 , v060
	.byte	W12
	.byte		N02   , Fn2 , v048
	.byte	W12
	.byte		N04   , As1 , v072
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N04   , Fn1 , v064
	.byte	W12
	.byte		        Fn2 , v048
	.byte	W12
	.byte		        Cn2 , v064
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N03   , Gn1 , v068
	.byte	W12
	.byte		        Gn2 , v060
	.byte	W12
	.byte		N04   , Cn2 , v064
	.byte	W12
	.byte		N02   , Gn2 , v060
	.byte	W12
	.byte		N05   , Gn1 , v056
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		N04   , Cn2 , v064
	.byte	W12
	.byte		N05   , Gn2 , v060
	.byte	W12
	.byte		N04   , Gn1 , v064
	.byte	W12
	.byte		N02   , Gn2 , v060
	.byte	W12
	.byte		N04   , Ds2 , v072
	.byte	W12
	.byte		N02   , An2 , v060
	.byte	W12
	.byte		N05   , Ds2 , v064
	.byte	W12
	.byte		N03   , An2 , v068
	.byte	W12
	.byte		N04   , Dn2 , v072
	.byte	W12
	.byte		        As2 , v056
	.byte	W12
	.byte		N05   , Cs2 , v076
	.byte	W12
	.byte		N04   , As2 , v060
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N02   , As2 , v060
	.byte	W12
	.byte		N04   , Fn1 , v068
	.byte	W12
	.byte		N01   , An2 , v060
	.byte	W12
	.byte		N04   , Gn1 , v064
	.byte	W12
	.byte		N03   , Gn2 , v060
	.byte	W12
	.byte		        Gn1 , v068
	.byte	W12
	.byte		N02   , Gn2 , v056
	.byte	W12
	.byte		N03   , Dn2 , v068
	.byte	W12
	.byte		N02   , Gn2 , v056
	.byte	W12
	.byte		N04   , Gn1 , v076
	.byte	W12
	.byte		N01   , Gn2 , v056
	.byte	W12
	.byte		N03   , Cn1 
	.byte	W12
	.byte		N02   , Cn2 , v052
	.byte	W12
	.byte		N04   , Cn1 , v056
	.byte	W12
	.byte		N03   , Cn2 , v060
	.byte	W12
	.byte		        Gn1 , v068
	.byte	W12
	.byte		N05   , Cn2 , v056
	.byte	W12
	.byte		N03   , Cn1 , v064
	.byte	W12
	.byte		N04   , Cn2 , v056
	.byte	W12
	.byte		N03   , Fn1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v060
	.byte	W12
	.byte		N02   , As2 
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte		N02   , Dn3 
	.byte	W12
	.byte		        As2 , v060
	.byte	W12
	.byte		N03   , Fn1 , v072
	.byte	W12
	.byte		N04   , Fn2 , v064
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte		N02   , Fn1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v060
	.byte	W12
	.byte		N04   , As1 , v072
	.byte	W24
	.byte		N03   , Fn1 , v076
	.byte	W24
	.byte	GOTO
	 .word	mus_field_sapphire2_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_field_sapphire2_2:  @ 0x0869DC2F
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte		VOICE , 1
	.byte		VOL   , 81*mus_field_sapphire2_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W36
mus_field_sapphire2_2_B1:
	.byte		N04   , Fn2 , v076
	.byte	W44
	.byte	W03
	.byte		N04
	.byte	W48
	.byte		        Cn3 
	.byte	W01
	.byte	W22
	.byte		        Bn2 , v072
	.byte	W24
	.byte	W01
	.byte		        As2 
	.byte	W24
	.byte		N01   , An2 
	.byte	W12
	.byte		N04   , Gn2 , v068
	.byte	W12
	.byte		N05   , Fn2 , v072
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N04   , Fn2 , v076
	.byte	W48
	.byte		N04
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N04
	.byte	W19
	.byte		N05   , Fn2 , v064
	.byte	W07
	.byte		N16   , Gs2 , v072
	.byte	W16
	.byte		N03   , Fs2 , v064
	.byte	W08
	.byte		N06   , Fn2 , v072
	.byte	W44
	.byte	W03
	.byte		N04   , Fn2 , v076
	.byte	W48
	.byte		        Gn2 
	.byte	W01
	.byte	W48
	.byte		N03   , Cn3 , v064
	.byte	W24
	.byte		N04   , Gn2 , v060
	.byte	W23
	.byte		        Fn2 , v064
	.byte	W01
	.byte	W23
	.byte		        As2 , v072
	.byte	W23
	.byte		        Fn2 , v060
	.byte	W24
	.byte	W01
	.byte		N03   , Cn3 , v068
	.byte	W23
	.byte		N05   , As2 , v072
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N04   , As2 , v068
	.byte	W48
	.byte		        As2 , v072
	.byte	W01
	.byte	W48
	.byte		N04
	.byte	W44
	.byte	W02
	.byte		N05   , Cn3 
	.byte	W02
	.byte	W23
	.byte		        Bn2 
	.byte	W24
	.byte		N04   , As2 , v068
	.byte	W24
	.byte		        An2 
	.byte	W23
	.byte		N05   , Gn2 , v072
	.byte	W02
	.byte	W48
	.byte		N06
	.byte	W44
	.byte	W03
	.byte		N05   , As2 , v068
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		        As2 , v072
	.byte	W48
	.byte		N04   , As2 , v068
	.byte	W01
	.byte	W44
	.byte		N05   , As2 , v072
	.byte	W48
	.byte	W02
	.byte		N04   , As2 , v076
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		        As2 , v072
	.byte	W48
	.byte	W01
	.byte		        As2 , v076
	.byte	W01
	.byte	W22
	.byte		        Fn2 
	.byte	W24
	.byte		        Cn3 , v072
	.byte	W24
	.byte	W01
	.byte		N05   , Gn2 
	.byte	W24
	.byte		N04   , Fn2 , v064
	.byte	W01
	.byte	W24
	.byte		        An2 , v068
	.byte	W24
	.byte		N05   , Fn2 
	.byte	W24
	.byte		N04   , Fn3 , v076
	.byte	W23
	.byte		N05   , As2 , v072
	.byte	W01
	.byte	W24
	.byte	W01
	.byte		N04   , Fn2 , v064
	.byte	W11
	.byte		        As2 
	.byte	W13
	.byte		        Fn2 , v060
	.byte	W11
	.byte		        As2 , v064
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N03   , Fn2 , v056
	.byte	W12
	.byte	W12
	.byte		N02   , Cn3 , v060
	.byte	W11
	.byte		N04   , Gn2 , v064
	.byte	W12
	.byte		N02   , Cn3 , v068
	.byte	W12
	.byte		N05   , Ds3 , v064
	.byte	W12
	.byte		N03   , Cn3 , v056
	.byte	W12
	.byte		        Gn2 , v060
	.byte	W12
	.byte		N02   , Cn3 
	.byte	W13
	.byte	W11
	.byte		N03   , Fn2 , v052
	.byte	W12
	.byte		        As2 , v064
	.byte	W13
	.byte		        Fn2 , v060
	.byte	W11
	.byte		N02   , Dn3 , v068
	.byte	W11
	.byte		N03   , As2 , v060
	.byte	W12
	.byte		        Fn2 , v048
	.byte	W13
	.byte		N05   , As2 , v064
	.byte	W13
	.byte	W11
	.byte		        Ds2 , v072
	.byte	W13
	.byte		N01   , Gs2 , v064
	.byte	W11
	.byte		N04   , Ds2 , v068
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		N02   , Gs2 , v056
	.byte	W12
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		N02   , Cn3 , v068
	.byte	W13
	.byte	W11
	.byte		        Gn2 , v060
	.byte	W12
	.byte		N03   , As2 , v064
	.byte	W12
	.byte		N02   , Dn3 , v056
	.byte	W13
	.byte		N04   , Gn3 , v068
	.byte	W23
	.byte		        Gn2 , v072
	.byte	W24
	.byte	W01
	.byte	W11
	.byte		N05   , Ds2 , v064
	.byte	W12
	.byte		N02   , Gn2 , v060
	.byte	W12
	.byte		N03   , As2 , v064
	.byte	W13
	.byte		        Ds3 , v068
	.byte	W23
	.byte		N04   , Gn2 , v072
	.byte	W24
	.byte	W01
	.byte	W10
	.byte		N04
	.byte	W13
	.byte		        Cn3 , v064
	.byte	W12
	.byte		N02   , Ds3 , v068
	.byte	W13
	.byte		N03   , Gn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn2 , v064
	.byte	W13
	.byte		N02   , As2 , v060
	.byte	W11
	.byte		N01   , Cn3 , v068
	.byte	W12
	.byte		N02   , As2 , v060
	.byte	W12
	.byte		N04   , Fn2 
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		        Fn3 , v072
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte	W01
	.byte		N04   , As2 , v072
	.byte	W68
	.byte	W02
	.byte		        As2 , v076
	.byte	W24
	.byte		        Cn3 
	.byte	W01
	.byte	W22
	.byte		        Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	W01
	.byte		N03   , An2 
	.byte	W24
	.byte		N04   , Gn2 
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		        Gn2 , v072
	.byte	W48
	.byte	W01
	.byte		        Fn2 , v076
	.byte	W23
	.byte		N05   , As2 , v068
	.byte	W24
	.byte		N04   , As2 , v072
	.byte	W24
	.byte		N03   , An2 , v076
	.byte	W24
	.byte		N05   , Gn2 
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		        Gn2 , v068
	.byte	W48
	.byte	W01
	.byte		        Cn3 , v076
	.byte	W44
	.byte	W03
	.byte		N04
	.byte	W48
	.byte		N02   , Dn3 , v060
	.byte	W01
	.byte	W24
	.byte	W01
	.byte		N04   , Fn2 
	.byte	W21
	.byte		        Fn3 , v076
	.byte	W24
	.byte	W01
	.byte		        Fn2 , v060
	.byte	W23
	.byte		N05   , As2 , v072
	.byte	W02
	.byte	W22
	.byte		N04   , Fn2 , v064
	.byte	W24
	.byte		N03   , As2 
	.byte	W24
	.byte	W01
	.byte		N04   , Fn3 , v084
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_field_sapphire2_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_field_sapphire2_3:  @ 0x0869DE0F
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte		VOICE , 80
	.byte		VOL   , 86*mus_field_sapphire2_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W32
	.byte	W02
	.byte		N04   , Dn4 , v080
	.byte	W02
mus_field_sapphire2_3_B1:
	.byte	W23
	.byte		N04   , Dn4 , v076
	.byte	W12
	.byte		N03   , Fn4 , v084
	.byte	W23
	.byte		        Dn4 , v072
	.byte	W12
	.byte		N04   , As3 , v068
	.byte	W12
	.byte		        Fn3 , v056
	.byte	W13
	.byte		N03   , Cn4 , v072
	.byte	W01
	.byte	W11
	.byte		N05   , Cn4 , v064
	.byte	W05
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N02   , Cn4 , v072
	.byte	W12
	.byte		        Dn4 , v076
	.byte	W12
	.byte		N04   , Ds4 , v080
	.byte	W13
	.byte		N02   , Cn4 , v076
	.byte	W11
	.byte		N04   , Gn3 , v072
	.byte	W12
	.byte		N03   , Ds3 , v068
	.byte	W13
	.byte		N04   , Cn3 , v076
	.byte	W01
	.byte	W24
	.byte		N05   , Cn3 , v056
	.byte	W11
	.byte		N04   , Fn3 , v068
	.byte	W12
	.byte		N03   , An3 , v072
	.byte	W12
	.byte		N04   , Fn3 , v064
	.byte	W12
	.byte		N03   , Cn4 , v072
	.byte	W12
	.byte		N04   , Fn4 , v080
	.byte	W13
	.byte	W11
	.byte		N01   , Dn4 , v064
	.byte	W13
	.byte		N02   , As3 , v072
	.byte	W11
	.byte		N04   , Fn3 , v068
	.byte	W13
	.byte		N03   , As3 , v080
	.byte	W17
	.byte		N05   , As3 , v056
	.byte	W05
	.byte		N17   , Gs3 , v080
	.byte	W18
	.byte		N05   , Fs3 , v060
	.byte	W06
	.byte		N04   , Fn3 , v076
	.byte	W02
	.byte	W13
	.byte		N03   , Fn3 , v064
	.byte	W11
	.byte		N04   , As3 , v076
	.byte	W12
	.byte		N01   , Fn3 , v048
	.byte	W23
	.byte		        Dn4 , v068
	.byte	W12
	.byte		N04   , Fn4 , v076
	.byte	W12
	.byte		N03   , Dn4 , v064
	.byte	W12
	.byte		N06   , Ds4 , v068
	.byte	W01
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W05
	.byte		N05   , Ds4 
	.byte	W06
	.byte		N06   , Dn4 , v060
	.byte	W07
	.byte		N01   , Ds4 , v064
	.byte	W11
	.byte		N03   , Fn4 , v076
	.byte	W12
	.byte		        Gn4 , v072
	.byte	W12
	.byte		N01   , Ds4 , v068
	.byte	W12
	.byte		N02   , Cn4 
	.byte	W12
	.byte		N04   , Gn3 
	.byte	W13
	.byte	W12
	.byte		N06   , Fn3 , v060
	.byte	W05
	.byte		N05   , As3 , v064
	.byte	W05
	.byte		N04   , Dn4 
	.byte	W12
	.byte		N03   , Fn4 , v076
	.byte	W24
	.byte	W01
	.byte		N05   , Fn3 , v064
	.byte	W06
	.byte		        An3 , v068
	.byte	W05
	.byte		N01   , Cn4 , v060
	.byte	W12
	.byte		N03   , Fn4 , v076
	.byte	W12
	.byte		N04   , Dn4 , v072
	.byte	W02
	.byte	W10
	.byte		N03   , As3 
	.byte	W12
	.byte		N04   , Fn3 
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W13
	.byte		        As2 , v076
	.byte	W24
	.byte		N13   , As3 , v088
	.byte	W24
	.byte	W01
	.byte	W23
	.byte		N04   , As3 , v076
	.byte	W36
	.byte		N03   , Dn3 , v072
	.byte	W12
	.byte		N04   , Dn4 , v068
	.byte	W12
	.byte		N03   , As3 , v072
	.byte	W11
	.byte		N04   , Cn4 , v068
	.byte	W02
	.byte	W10
	.byte		N02   , Gn3 
	.byte	W12
	.byte		N04   , Ds3 
	.byte	W12
	.byte		        Cn3 , v072
	.byte	W13
	.byte		        Cn4 , v080
	.byte	W48
	.byte	W01
	.byte	W23
	.byte		        Gn3 , v084
	.byte	W36
	.byte		        Gn3 , v068
	.byte	W12
	.byte		N05   , Ds4 , v076
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte		N03   , Dn4 , v064
	.byte	W01
	.byte	W11
	.byte		N04   , As3 , v076
	.byte	W12
	.byte		        Fn3 , v068
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 , v080
	.byte	W48
	.byte	W01
	.byte		N07   , Dn3 , v072
	.byte	W07
	.byte		N08   , Ds3 , v068
	.byte	W08
	.byte		        Dn3 , v060
	.byte	W08
	.byte		N07   , Cs3 
	.byte	W06
	.byte		N09   , Dn3 , v048
	.byte	W08
	.byte		N08   , Ds3 , v068
	.byte	W08
	.byte		N24   , Dn3 , v072
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W18
	.byte		N07
	.byte	W07
	.byte		N08   , Ds3 , v068
	.byte	W02
	.byte	W06
	.byte		N09   , Fn3 , v064
	.byte	W07
	.byte		        Ds3 , v056
	.byte	W09
	.byte		        Dn3 , v064
	.byte	W07
	.byte		N08   , Ds3 , v060
	.byte	W08
	.byte		N10   , Fn3 , v072
	.byte	W09
	.byte		N05   , Fs3 , v076
	.byte	W18
	.byte		N06   , As3 , v080
	.byte	W16
	.byte		N07   , Ds4 , v076
	.byte	W15
	.byte		N08   , Dn4 
	.byte	W01
	.byte	W16
	.byte		N07   , Fn4 , v080
	.byte	W17
	.byte		N06   , As4 , v084
	.byte	W15
	.byte		        Cn5 
	.byte	W14
	.byte		        Gn4 , v076
	.byte	W15
	.byte		N08   , En4 , v072
	.byte	W18
	.byte		N05   , Fn4 , v064
	.byte	W01
	.byte	W11
	.byte		        Cn4 , v072
	.byte	W11
	.byte		N04   , An3 , v060
	.byte	W11
	.byte		N05   , Fn3 
	.byte	W12
	.byte		N04   , Fn4 , v068
	.byte	W12
	.byte		N05   , Ds4 
	.byte	W12
	.byte		N04   , Cn4 , v064
	.byte	W12
	.byte		N05   , An3 , v068
	.byte	W14
	.byte		N04   , As3 , v072
	.byte	W01
	.byte	W48
	.byte	W01
	.byte		N48   , Dn3 , v064
	.byte	W44
	.byte	W03
	.byte	W01
	.byte		N32   , Cn3 , v056
	.byte	W32
	.byte	W02
	.byte		N12   , Dn3 , v060
	.byte	W13
	.byte		N11   , Cn3 
	.byte	W10
	.byte		N14   , Ds3 , v064
	.byte	W12
	.byte		N13   , Gn3 , v072
	.byte	W12
	.byte		N15   , Cn4 , v068
	.byte	W13
	.byte		N48   , As3 
	.byte	W01
	.byte	W48
	.byte		N23   , Fn3 , v056
	.byte	W23
	.byte		N24   , As3 , v064
	.byte	W24
	.byte		N36   , Gs3 , v072
	.byte	W01
	.byte	W36
	.byte		N11   , As3 , v060
	.byte	W11
	.byte		N13   , Gs3 , v064
	.byte	W12
	.byte		N11   , Cn4 , v068
	.byte	W11
	.byte		N14   , Ds4 , v076
	.byte	W13
	.byte		N13   , Gs4 , v080
	.byte	W13
	.byte		N56   , Gn4 
	.byte	W56
	.byte	W02
	.byte		N14   , Dn4 , v064
	.byte	W13
	.byte		N13   , As3 , v068
	.byte	W12
	.byte		N07   , Gn3 , v072
	.byte	W12
	.byte		N20   , Gn3 , v068
	.byte	W01
	.byte	W18
	.byte		N18   , Fn3 , v072
	.byte	W17
	.byte		N11   , Ds3 
	.byte	W13
	.byte		N18   , Ds3 , v076
	.byte	W18
	.byte		N14   , Dn3 
	.byte	W15
	.byte		N10   , Cn3 
	.byte	W14
	.byte		N36   , Cn3 , v080
	.byte	W01
	.byte	W32
	.byte	W02
	.byte		N05   , Bn2 , v068
	.byte	W05
	.byte		N03   , Cn3 , v072
	.byte	W07
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W13
	.byte		N12   , Ds3 
	.byte	W11
	.byte		N13   , Gn3 
	.byte	W13
	.byte		N12   , Fn3 , v072
	.byte	W01
	.byte	W12
	.byte		N13   , En3 , v068
	.byte	W11
	.byte		        Fn3 , v072
	.byte	W13
	.byte		N10   , Gn3 , v064
	.byte	W11
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N05   , Gs3 , v068
	.byte	W06
	.byte		N06   , An3 , v072
	.byte	W06
	.byte		N04   , As3 
	.byte	W05
	.byte		N06   , Bn3 , v076
	.byte	W06
	.byte		        Cn4 , v068
	.byte	W06
	.byte		N05   , Cs4 
	.byte	W07
	.byte		N24   , Dn4 , v080
	.byte	W01
	.byte	W32
	.byte	W03
	.byte		N02   , Fn4 , v072
	.byte	W12
	.byte		N05   , Dn4 , v060
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N04   , As4 , v072
	.byte	W12
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        Ds4 
	.byte	W01
	.byte	W11
	.byte		N05   , Gn4 , v072
	.byte	W05
	.byte		N07   , Cn5 , v076
	.byte	W06
	.byte		N04   , Gn4 , v072
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 , v076
	.byte	W12
	.byte		        Ds3 , v068
	.byte	W12
	.byte		N05   , Cn3 , v072
	.byte	W14
	.byte	W11
	.byte		N04   , Cn3 , v064
	.byte	W12
	.byte		N05   , Ds3 , v068
	.byte	W12
	.byte		N04   , Gn3 
	.byte	W11
	.byte		        Fn3 , v072
	.byte	W12
	.byte		N05   , An3 , v076
	.byte	W12
	.byte		N04   , Cn4 , v072
	.byte	W13
	.byte		N03   , An3 
	.byte	W12
	.byte		N05   , Fn3 , v068
	.byte	W01
	.byte	W11
	.byte		N04   , Fn4 , v076
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W12
	.byte		N03   , Fn4 , v076
	.byte	W11
	.byte		N04   , Fn3 , v060
	.byte	W13
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W11
	.byte		N02   , Fn4 , v072
	.byte	W13
	.byte		N32   , Gn3 , v064
	.byte	W01
	.byte	W32
	.byte	W02
	.byte		N13   , An3 , v068
	.byte	W14
	.byte		N23   , Bn3 , v064
	.byte	W24
	.byte		N12   , Cn4 , v068
	.byte	W11
	.byte		N13   , Dn4 , v060
	.byte	W13
	.byte		N48   , Ds4 , v076
	.byte	W48
	.byte		N24   , Gn4 , v072
	.byte	W23
	.byte		        Ds4 , v064
	.byte	W24
	.byte	W01
	.byte	W23
	.byte		N10   , Dn4 
	.byte	W08
	.byte		N08   , Cs4 , v060
	.byte	W08
	.byte		N06   , Cn4 , v068
	.byte	W07
	.byte		N08   , Bn3 , v072
	.byte	W08
	.byte		N07   , As3 , v064
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 , v060
	.byte	W08
	.byte		N07   , Gn3 
	.byte	W07
	.byte		N09   , Fn3 
	.byte	W10
	.byte		N04   , As3 , v072
	.byte	W01
	.byte	W10
	.byte		        Fn3 , v060
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte		N05   , As2 , v064
	.byte	W13
	.byte		        Fn2 , v068
	.byte	W24
	.byte		N03   , As3 , v060
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_field_sapphire2_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_field_sapphire2_4:  @ 0x0869E13F
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte		VOICE , 114
	.byte		VOL   , 86*mus_field_sapphire2_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W36
mus_field_sapphire2_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W56
	.byte	W03
	.byte		N04   , Cn4 , v056
	.byte	W11
	.byte		N05   , Ds4 , v072
	.byte	W12
	.byte		N04   , Gn4 , v068
	.byte	W13
	.byte		        Cn5 
	.byte	W01
	.byte	W96
	.byte	W60
	.byte		        Fn4 
	.byte	W11
	.byte		        As4 , v072
	.byte	W12
	.byte		N03   , Dn5 , v064
	.byte	W12
	.byte		        Fn5 , v080
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
	.byte	W96
	.byte	W96
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
	 .word	mus_field_sapphire2_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_field_sapphire2_5:  @ 0x0869E18E
	.byte	KEYSH , mus_field_sapphire2_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_field_sapphire2_mvl/mxv
	.byte	W36
mus_field_sapphire2_5_B1:
	.byte		N06   , Cn1 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	PATT
	 .word	mus_field_sapphire2_5_B1
	.byte	GOTO
	 .word	mus_field_sapphire2_5_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_field_sapphire2:  @ 0x0869E250
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_field_sapphire2_pri	@ Priority
	.byte	mus_field_sapphire2_rev	@ Reverb

	.word	mus_field_sapphire2_grp

	.word	mus_field_sapphire2_0
	.word	mus_field_sapphire2_1
	.word	mus_field_sapphire2_2
	.word	mus_field_sapphire2_3
	.word	mus_field_sapphire2_4
	.word	mus_field_sapphire2_5
@ 0x0869E270
