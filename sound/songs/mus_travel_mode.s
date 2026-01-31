	.include "sound/MPlayDef.s"

	.equ	mus_travel_mode_grp, gUnknown_08532808
	.equ	mus_travel_mode_pri, 0
	.equ	mus_travel_mode_rev, reverb_set+50
	.equ	mus_travel_mode_mvl, 127
	.equ	mus_travel_mode_key, 0
	.equ	mus_travel_mode_tbs, 1
	.equ	mus_travel_mode_exg, 0
	.equ	mus_travel_mode_cmp, 1

	.section .rodata
	.global	mus_travel_mode
	.align	2

@*********************** Track 01 ***********************@

mus_travel_mode_0:  @ 0x0868FDC0
	.byte	KEYSH , mus_travel_mode_key+0
	.byte	TEMPO , 138*mus_travel_mode_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 85*mus_travel_mode_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
mus_travel_mode_0_B1:
	.byte		N12   , Dn3 , v080
	.byte	W24
	.byte		N14   , Dn3 , v076
	.byte	W24
	.byte		N16
	.byte	W24
	.byte		N12   , Dn3 , v072
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B2:
	.byte		N13   , Dn3 , v068
	.byte	W24
	.byte		N14   , Dn3 , v072
	.byte	W24
	.byte		N15
	.byte	W24
	.byte		N13
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B3:
	.byte		N11   , Dn3 , v076
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N12   , Dn3 , v072
	.byte	W24
	.byte		N16   , Dn3 , v076
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B4:
	.byte		N11   , Dn3 , v076
	.byte	W24
	.byte		N13   , Dn3 , v072
	.byte	W24
	.byte		N11
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B5:
	.byte		N13   , Dn3 , v076
	.byte	W24
	.byte		N11   , Dn3 , v072
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N10   , Dn3 , v076
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B6:
	.byte		N13   , Dn3 , v076
	.byte	W24
	.byte		N12   , Dn3 , v072
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte		N12
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B7:
	.byte		N10   , Dn3 , v076
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N11   , Dn3 , v072
	.byte	W24
	.byte		N12
	.byte	W24
	.byte	PEND
mus_travel_mode_0_B8:
	.byte		N12   , Dn3 , v072
	.byte	W24
	.byte		N13   , Dn3 , v076
	.byte	W24
	.byte		N10
	.byte	W24
	.byte		N11
	.byte	W24
	.byte	PEND
	.byte		N12   , En3 , v080
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N11   , En3 , v076
	.byte	W24
	.byte		N11
	.byte	W24
	.byte		N10   , Fn3 , v084
	.byte	W24
	.byte		N13   , Fn3 , v080
	.byte	W24
	.byte		N11
	.byte	W24
	.byte		N09   , Fn3 , v084
	.byte	W24
	.byte		N13   , Fs3 
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N10
	.byte	W24
	.byte		N07   , Fs3 , v076
	.byte	W24
	.byte		N09   , Gn3 , v084
	.byte	W24
	.byte		N08
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        An3 , v088
	.byte	W24
	.byte		N12   , Dn3 , v080
	.byte	W24
	.byte		N08   , Dn3 , v072
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PATT
	 .word	mus_travel_mode_0_B1
	.byte	PATT
	 .word	mus_travel_mode_0_B1
	.byte	PATT
	 .word	mus_travel_mode_0_B2
	.byte	PATT
	 .word	mus_travel_mode_0_B3
	.byte	PATT
	 .word	mus_travel_mode_0_B4
	.byte	PATT
	 .word	mus_travel_mode_0_B5
	.byte	PATT
	 .word	mus_travel_mode_0_B6
	.byte	PATT
	 .word	mus_travel_mode_0_B7
	.byte	PATT
	 .word	mus_travel_mode_0_B8
	.byte		N15   , En3 , v084
	.byte	W24
	.byte		        En3 , v080
	.byte	W24
	.byte		N16   , En3 , v084
	.byte	W24
	.byte		N14
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N15
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N14
	.byte	W24
	.byte		N13   , An2 , v088
	.byte	W24
	.byte		N14   , An2 , v092
	.byte	W24
	.byte		N13   , An2 , v088
	.byte	W24
	.byte		N15
	.byte	W24
	.byte		N16   , An3 , v084
	.byte	W24
	.byte		N15
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N11   , An3 , v088
	.byte	W24
	.byte		N13   , Gn2 , v084
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N13
	.byte	W24
	.byte		N14   , As2 , v092
	.byte	W24
	.byte		N12   , As2 , v084
	.byte	W24
	.byte		        As2 , v080
	.byte	W24
	.byte		N13   , As2 , v084
	.byte	W24
	.byte		N15   , Cs3 
	.byte	W24
	.byte		N13   , Cs3 , v080
	.byte	W24
	.byte		N12   , Cs3 , v084
	.byte	W24
	.byte		N13   , Cs3 , v080
	.byte	W24
	.byte		N12   , Ds3 , v084
	.byte	W24
	.byte		        Ds3 , v080
	.byte	W24
	.byte		N13   , Ds3 , v084
	.byte	W24
	.byte		N12
	.byte	W24
	.byte		N16   , En3 
	.byte	W23
	.byte		N17
	.byte	W24
	.byte	W02
	.byte		N14   , En3 , v080
	.byte	W23
	.byte		N24
	.byte	W24
mus_travel_mode_0_B9:
	.byte		N14   , En2 , v084
	.byte	W24
	.byte	W01
	.byte		N12
	.byte	W23
	.byte		N10
	.byte	W24
	.byte		N11
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_travel_mode_0_B9
	.byte	GOTO
	 .word	mus_travel_mode_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_travel_mode_1:  @ 0x0868FF2D
	.byte	KEYSH , mus_travel_mode_key+0
	.byte		VOICE , 58
	.byte		VOL   , 102*mus_travel_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 5
	.byte	W72
	.byte		N07   , Dn4 , v076
	.byte	W06
	.byte		N05   , Ds4 , v064
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N08   , Fn4 , v072
	.byte	W06
mus_travel_mode_1_B1:
	.byte		N12   , Fs4 , v088
	.byte	W18
	.byte		N06   , An4 
	.byte	W16
	.byte		N40   , Dn4 , v084
	.byte	W48
	.byte	W01
	.byte		N05   , Dn4 , v076
	.byte	W12
	.byte		N14   , Fs4 , v092
	.byte	W01
	.byte	PEND
mus_travel_mode_1_B2:
	.byte	W18
	.byte		N08   , An4 , v088
	.byte	W16
	.byte		N24   , Dn4 , v080
	.byte	W24
	.byte	W02
	.byte		N14   , An4 
	.byte	W12
	.byte		N12   , Gn4 , v084
	.byte	W12
	.byte		N13   , Fs4 , v080
	.byte	W12
	.byte	PEND
mus_travel_mode_1_B3:
	.byte		N19   , Fn4 , v080
	.byte	W18
	.byte		N08   , As4 , v088
	.byte	W14
	.byte		TIE   , As4 , v084
	.byte	W64
	.byte	PEND
	.byte	W48
	.byte	W03
	.byte		EOT
	.byte	W09
	.byte		N07   , Fn5 
	.byte	W12
	.byte		        As4 , v080
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , Fs4 , v084
	.byte	W16
	.byte		N05   , An4 , v080
	.byte	W17
	.byte		N36   , Dn4 
	.byte	W48
	.byte	W01
	.byte		N05
	.byte	W14
mus_travel_mode_1_B4:
	.byte		N15   , Fs4 , v088
	.byte	W18
	.byte		N07   , An4 
	.byte	W18
	.byte		N19   , Dn4 , v080
	.byte	W24
	.byte		N14   , An4 , v084
	.byte	W12
	.byte		N12   , Gn4 , v080
	.byte	W12
	.byte		N13   , Fs4 
	.byte	W12
	.byte	PEND
mus_travel_mode_1_B5:
	.byte		N21   , Fn4 , v084
	.byte	W19
	.byte		N15   , As4 , v092
	.byte	W16
	.byte		N10   , Fn5 , v088
	.byte	W13
	.byte		TIE   , Fn5 , v096
	.byte	W48
	.byte	PEND
	.byte	W56
	.byte	W03
	.byte		EOT
	.byte	W01
	.byte		N13   , Fn4 , v080
	.byte	W12
	.byte		N11   , En4 
	.byte	W12
	.byte		N13   , Dn4 , v076
	.byte	W12
mus_travel_mode_1_B6:
	.byte		N18   , En4 , v084
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		N08   , Cn5 
	.byte	W16
	.byte		N20
	.byte	W16
	.byte		N16   , Gn4 , v080
	.byte	W16
	.byte		N14   , En4 
	.byte	W16
	.byte	PEND
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N05   , En4 , v064
	.byte	W06
	.byte		N06   , Fn4 , v076
	.byte	W06
	.byte		N08   , As4 , v072
	.byte	W06
	.byte		N05   , Dn5 , v084
	.byte	W12
	.byte		N24
	.byte	W24
	.byte		N13   , As4 , v088
	.byte	W12
	.byte		        Dn5 , v080
	.byte	W12
	.byte		N14   , Fn5 , v084
	.byte	W12
	.byte		N19   , Fs4 , v080
	.byte	W16
	.byte		N18   , Bn4 , v084
	.byte	W16
	.byte		N20   , Ds5 , v080
	.byte	W16
	.byte		N24   , Fs5 , v076
	.byte	W16
	.byte		N17   , Ds5 , v080
	.byte	W16
	.byte		N12   , Bn4 , v084
	.byte	W16
	.byte		N07   , Gn4 , v076
	.byte	W05
	.byte		N06   , Fs4 , v072
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W04
	.byte		        Fs4 , v072
	.byte	W06
	.byte		N04   , Gn4 , v076
	.byte	W14
	.byte		N24   , Bn4 , v092
	.byte	W24
	.byte		N13   , Dn5 , v080
	.byte	W13
	.byte		N12   , Cs5 
	.byte	W11
	.byte		N14   , En5 , v084
	.byte	W12
	.byte		N30   , Dn5 , v080
	.byte	W01
	.byte	W96
	.byte	W72
	.byte		N07   , Dn4 , v076
	.byte	W06
	.byte		N05   , Ds4 , v064
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N08   , Fn4 , v072
	.byte	W06
	.byte	PATT
	 .word	mus_travel_mode_1_B1
	.byte	PATT
	 .word	mus_travel_mode_1_B2
	.byte	PATT
	 .word	mus_travel_mode_1_B3
	.byte	W48
	.byte	W03
	.byte		EOT   , As4 
	.byte	W09
	.byte		N07   , Fn5 , v084
	.byte	W12
	.byte		        As4 , v080
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , Fs4 , v084
	.byte	W16
	.byte		N06   , An4 
	.byte	W17
	.byte		N40   , Dn4 
	.byte	W48
	.byte	W02
	.byte		N06   , Dn4 , v080
	.byte	W13
	.byte	PATT
	 .word	mus_travel_mode_1_B4
	.byte	PATT
	 .word	mus_travel_mode_1_B5
	.byte	W56
	.byte	W03
	.byte		EOT   , Fn5 
	.byte	W01
	.byte		N13   , Fn4 , v080
	.byte	W12
	.byte		N11   , En4 
	.byte	W12
	.byte		N13   , Dn4 , v076
	.byte	W12
	.byte	PATT
	 .word	mus_travel_mode_1_B6
	.byte		N19   , Fn4 , v084
	.byte	W16
	.byte		N18   , As4 , v088
	.byte	W16
	.byte		N08   , Dn5 , v076
	.byte	W14
	.byte		N22
	.byte	W19
	.byte		N17   , As4 , v084
	.byte	W15
	.byte		N16   , Fn4 , v080
	.byte	W15
	.byte		N60   , En5 , v092
	.byte	W01
	.byte	W56
	.byte	W02
	.byte		N14   , Dn5 , v080
	.byte	W13
	.byte		N11   , Cs5 , v084
	.byte	W11
	.byte		N12   , Bn4 , v088
	.byte	W12
	.byte		N05   , An4 , v068
	.byte	W02
	.byte	W04
	.byte		N07   , Bn4 
	.byte	W06
	.byte		N64   , Cs5 , v088
	.byte	W84
	.byte	W02
	.byte		N18   , Bn3 , v084
	.byte	W16
	.byte		N17   , An3 , v080
	.byte	W16
	.byte		N12   , Gn3 , v072
	.byte	W16
	.byte		N20   , Gn3 , v092
	.byte	W16
	.byte		N17   , An3 , v088
	.byte	W16
	.byte		N16   , Bn3 , v080
	.byte	W16
	.byte		N20   , Dn4 , v096
	.byte	W16
	.byte		N19   , Cn4 , v084
	.byte	W16
	.byte		N10   , As3 
	.byte	W16
	.byte		N20
	.byte	W16
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N15   , Dn4 
	.byte	W16
	.byte		N20   , Fn4 , v096
	.byte	W16
	.byte		        Ds4 , v092
	.byte	W16
	.byte		N10   , Cs4 , v080
	.byte	W16
	.byte		N20   , Cs4 , v088
	.byte	W16
	.byte		N18   , Ds4 
	.byte	W16
	.byte		N20   , Fn4 , v092
	.byte	W16
	.byte		N04   , Gn4 , v080
	.byte	W03
	.byte		N07   , Ds4 , v076
	.byte	W06
	.byte		N06   , Gn4 , v080
	.byte	W05
	.byte		N07   , Ds4 , v072
	.byte	W06
	.byte		N05   , Gn4 , v076
	.byte	W14
	.byte		N24   , As4 , v092
	.byte	W24
	.byte	W02
	.byte		N14   , Gn4 , v088
	.byte	W12
	.byte		N10   , As4 
	.byte	W10
	.byte		N17   , Ds5 
	.byte	W13
	.byte		N60   , En5 , v100
	.byte	W01
	.byte	W60
	.byte		N05   , En4 , v076
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		N12   , En4 , v076
	.byte	W12
	.byte	W01
	.byte		N07   , En5 , v100
	.byte	W17
	.byte		N02   , En4 , v076
	.byte	W06
	.byte		N54   , En4 , v100
	.byte	W72
	.byte	W96
	.byte	GOTO
	 .word	mus_travel_mode_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_travel_mode_2:  @ 0x0869015B
	.byte	KEYSH , mus_travel_mode_key+0
	.byte		VOICE , 60
	.byte		VOL   , 85*mus_travel_mode_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
mus_travel_mode_2_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Fn3 , v080
	.byte	W16
	.byte		N11   , Dn3 , v072
	.byte	W16
	.byte		N12   , As2 , v076
	.byte	W16
	.byte		N13   , Fn2 
	.byte	W16
	.byte		N12   , As2 , v080
	.byte	W16
	.byte		N10   , Dn3 
	.byte	W16
	.byte		N22   , An3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N17   , As3 , v084
	.byte	W16
	.byte		N15   , Fn3 , v080
	.byte	W16
	.byte		N13   , Dn3 , v072
	.byte	W16
	.byte		N18   , As2 , v084
	.byte	W16
	.byte		N13   , Dn3 , v080
	.byte	W16
	.byte		N11   , Fn3 
	.byte	W16
	.byte		N20   , Gn3 , v084
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W44
	.byte	W02
	.byte		N14   , Dn3 
	.byte	W17
	.byte		N07   , Fs3 
	.byte	W18
	.byte		N40   , An2 
	.byte	W15
	.byte	W44
	.byte	W03
	.byte		N13   , Dn3 , v088
	.byte	W18
	.byte		N05   , Fs3 , v084
	.byte	W17
	.byte		        An2 
	.byte	W13
	.byte		N66   , Fn3 , v088
	.byte	W01
	.byte	W60
	.byte	W03
	.byte		N12   , Dn3 , v080
	.byte	W16
	.byte		        As2 , v084
	.byte	W16
	.byte		N14   , Fn2 
	.byte	W01
	.byte	W17
	.byte		N12   , As2 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W14
	.byte		N40   , Fn3 , v088
	.byte	W48
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N14   , Dn3 
	.byte	W19
	.byte		N07   , Fs3 , v084
	.byte	W16
	.byte		N44   , An2 , v088
	.byte	W15
	.byte	W48
	.byte		N12   , Dn3 , v084
	.byte	W17
	.byte		N07   , Fs3 
	.byte	W19
	.byte		N06   , An2 
	.byte	W12
	.byte		TIE   , Fn3 , v088
	.byte	W96
	.byte		N18   , As3 
	.byte	W01
	.byte		EOT   , Fn3 
	.byte	W17
	.byte		N12   , Fn3 , v084
	.byte	W14
	.byte		        Dn3 , v076
	.byte	W16
	.byte		N15   , As2 , v084
	.byte	W16
	.byte		N12   , Dn3 , v080
	.byte	W16
	.byte		N10   , Fn3 
	.byte	W16
	.byte		N72   , Gn3 , v092
	.byte	W72
	.byte		N24   , Cn3 , v084
	.byte	W24
	.byte		N72   , Fn3 , v088
	.byte	W72
	.byte		N21   , As2 , v084
	.byte	W24
	.byte		N72   , An2 
	.byte	W72
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N72   , Cs3 
	.byte	W72
	.byte		N22   , An3 , v080
	.byte	W24
	.byte	W48
	.byte		N21   , Dn3 
	.byte	W16
	.byte		N18   , Bn2 , v084
	.byte	W16
	.byte		N15   , Gn2 , v076
	.byte	W16
	.byte	W48
	.byte		N20   , Fn3 , v088
	.byte	W16
	.byte		N17   , Dn3 , v080
	.byte	W16
	.byte		N14   , As2 , v084
	.byte	W16
	.byte	W48
	.byte		N21   , Gs3 
	.byte	W16
	.byte		N19   , Fn3 , v080
	.byte	W16
	.byte		N15   , Cs3 , v076
	.byte	W16
	.byte	W48
	.byte		N21   , As3 , v084
	.byte	W16
	.byte		N18   , Gn3 , v080
	.byte	W16
	.byte		N12   , Ds3 
	.byte	W16
	.byte	W48
	.byte		N21   , Bn3 , v088
	.byte	W16
	.byte		N18   , Gs3 , v080
	.byte	W16
	.byte		N09   , En3 , v076
	.byte	W16
	.byte	W02
	.byte		N20   , En3 , v080
	.byte	W21
	.byte		N14   , Bn2 , v076
	.byte	W15
	.byte		        Gs2 
	.byte	W14
	.byte		N30   , En2 , v088
	.byte	W44
	.byte	W96
	.byte	GOTO
	 .word	mus_travel_mode_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_travel_mode_3:  @ 0x0869027C
	.byte	KEYSH , mus_travel_mode_key+0
	.byte		VOICE , 80
	.byte		VOL   , 85*mus_travel_mode_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N05   , An3 , v068
	.byte	W05
	.byte		N04   , An4 , v076
	.byte	W14
	.byte		        An3 , v068
	.byte	W05
	.byte		        An4 , v080
	.byte	W13
	.byte		N05   , An4 , v072
	.byte	W05
	.byte		N04   , An5 , v084
	.byte	W12
	.byte		        An4 , v072
	.byte	W06
	.byte		        An5 , v084
	.byte	W13
	.byte		N07   , An4 
	.byte	W23
mus_travel_mode_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
mus_travel_mode_3_B2:
	.byte		N08   , Dn3 , v060
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 , v064
	.byte	W06
	.byte		N06   , Dn4 , v068
	.byte	W06
	.byte		N07   , As3 
	.byte	W06
	.byte		N06   , Dn4 , v048
	.byte	W06
	.byte		N07   , Fn4 , v068
	.byte	W06
	.byte		N05   , As4 
	.byte	W06
	.byte		N06   , Dn4 , v076
	.byte	W06
	.byte		N07   , Fn4 , v068
	.byte	W06
	.byte		        As4 , v072
	.byte	W06
	.byte		N05   , Dn5 , v060
	.byte	W06
	.byte		        Fn4 , v068
	.byte	W06
	.byte		N08   , As4 , v072
	.byte	W06
	.byte		N09   , Dn5 , v068
	.byte	W06
	.byte		N13   , Fn5 , v052
	.byte	W06
	.byte	PEND
	.byte		N12   , An5 , v080
	.byte	W96
	.byte	W96
	.byte	W96
mus_travel_mode_3_B3:
	.byte		N08   , Fn5 , v068
	.byte	W06
	.byte		N09   , Dn5 , v060
	.byte	W06
	.byte		N06   , As4 , v064
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N08   , Dn5 , v076
	.byte	W06
	.byte		        As4 , v072
	.byte	W06
	.byte		N06   , Fn4 , v064
	.byte	W06
	.byte		N08   , Dn4 , v060
	.byte	W06
	.byte		N07   , As4 , v072
	.byte	W06
	.byte		N05   , Fn4 , v052
	.byte	W06
	.byte		        Dn4 , v056
	.byte	W06
	.byte		N07   , As3 , v064
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		N08   , Dn4 , v064
	.byte	W06
	.byte		N07   , As3 , v060
	.byte	W06
	.byte		        Fn3 , v068
	.byte	W06
	.byte	PEND
	.byte	W23
	.byte		        En2 , v064
	.byte	W06
	.byte		N08   , Gn2 , v072
	.byte	W07
	.byte		N06   , Cn3 , v064
	.byte	W05
	.byte		N08   , En3 , v068
	.byte	W07
	.byte		N06   , Cn4 , v072
	.byte	W06
	.byte		        Gn3 , v068
	.byte	W06
	.byte		        Cn4 , v056
	.byte	W05
	.byte		        Gn3 , v068
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		N08   , Cn4 , v072
	.byte	W05
	.byte		N07   , Gn3 , v064
	.byte	W07
	.byte		N05   , En3 , v060
	.byte	W07
	.byte	W22
	.byte		N08   , Fn2 , v068
	.byte	W06
	.byte		N07   , As2 , v076
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W07
	.byte		N09   , Fn3 
	.byte	W07
	.byte		N06   , Dn4 , v076
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 , v060
	.byte	W05
	.byte		N08   , As3 , v068
	.byte	W07
	.byte		N06   , Fn4 , v084
	.byte	W05
	.byte		N09   , Dn4 , v068
	.byte	W07
	.byte		N07   , As3 , v072
	.byte	W07
	.byte		        Fn3 
	.byte	W05
	.byte	W22
	.byte		N09   , Fs2 , v056
	.byte	W07
	.byte		N08   , Bn2 , v060
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W05
	.byte		        Fs3 
	.byte	W07
	.byte		N06   , Ds4 , v072
	.byte	W07
	.byte		        Bn3 , v056
	.byte	W05
	.byte		        Ds4 
	.byte	W06
	.byte		N07   , Bn3 , v064
	.byte	W06
	.byte		N11   , Fs4 , v080
	.byte	W06
	.byte		N08   , Ds4 , v072
	.byte	W07
	.byte		N09   , Bn3 , v064
	.byte	W07
	.byte		N07   , Fs3 
	.byte	W05
	.byte	W22
	.byte		N09   , Gn2 
	.byte	W06
	.byte		N07   , Cn3 , v060
	.byte	W06
	.byte		N06   , En3 
	.byte	W05
	.byte		N07   , Gn3 
	.byte	W32
	.byte		N10   , An2 , v072
	.byte	W06
	.byte		N07   , En3 , v064
	.byte	W05
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W08
	.byte	W22
	.byte		N05   , An2 , v064
	.byte	W06
	.byte		N07   , Dn3 , v060
	.byte	W05
	.byte		        Fs3 , v068
	.byte	W06
	.byte		N06   , An3 , v076
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N07   , Dn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn5 , v080
	.byte	W06
	.byte		N08   , An4 , v076
	.byte	W05
	.byte		N07   , Fs4 , v072
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W10
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_travel_mode_3_B2
	.byte		N12   , An5 , v080
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_travel_mode_3_B3
	.byte	W23
	.byte		N07   , Gn2 , v060
	.byte	W05
	.byte		N08   , Cn3 
	.byte	W05
	.byte		        En3 
	.byte	W07
	.byte		N07   , Gn3 , v068
	.byte	W07
	.byte		N06   , Cn4 
	.byte	W05
	.byte		        Gn3 , v060
	.byte	W06
	.byte		N07   , Cn4 
	.byte	W07
	.byte		N06   , Gn3 , v064
	.byte	W06
	.byte		N09   , En4 , v080
	.byte	W07
	.byte		        Cn4 , v064
	.byte	W06
	.byte		N08   , Gn3 
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte	W23
	.byte		N09   , Fn2 , v060
	.byte	W05
	.byte		        As2 , v068
	.byte	W07
	.byte		N06   , Dn3 , v060
	.byte	W05
	.byte		N08   , Fn3 , v068
	.byte	W07
	.byte		N06   , Dn4 , v072
	.byte	W06
	.byte		N07   , As3 , v064
	.byte	W06
	.byte		        Dn4 , v060
	.byte	W06
	.byte		N08   , As3 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W07
	.byte		N09   , Dn4 , v072
	.byte	W06
	.byte		N07   , As3 
	.byte	W06
	.byte		N06   , Fn3 , v068
	.byte	W06
	.byte	W23
	.byte		N09   , En2 , v060
	.byte	W07
	.byte		N07   , An2 , v068
	.byte	W06
	.byte		N06   , Bn2 , v064
	.byte	W06
	.byte		N07   , En3 , v060
	.byte	W06
	.byte		N05   , Bn3 , v068
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N05   , Bn3 , v060
	.byte	W05
	.byte		N07   , An3 , v064
	.byte	W06
	.byte		N06   , En4 , v084
	.byte	W07
	.byte		N07   , Bn3 , v072
	.byte	W05
	.byte		N06   , An3 , v060
	.byte	W06
	.byte		        En3 
	.byte	W07
	.byte	W22
	.byte		N07   , En2 , v064
	.byte	W08
	.byte		N08   , An2 
	.byte	W05
	.byte		N07   , Cs3 , v056
	.byte	W07
	.byte		N08   , En3 , v072
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        An3 , v068
	.byte	W05
	.byte		N07   , Cs4 
	.byte	W06
	.byte		N08   , An3 
	.byte	W07
	.byte		N07   , En4 , v080
	.byte	W05
	.byte		N09   , Cs4 , v076
	.byte	W07
	.byte		N07   , An3 , v064
	.byte	W05
	.byte		        En3 
	.byte	W07
	.byte	W22
	.byte		N08   , Bn2 
	.byte	W07
	.byte		N07   , Dn3 , v060
	.byte	W05
	.byte		N08   , Gn3 , v064
	.byte	W06
	.byte		N03   , Bn3 , v060
	.byte	W06
	.byte		N05   , Dn3 , v072
	.byte	W06
	.byte		N07   , Gn3 , v064
	.byte	W06
	.byte		N06   , Bn3 , v068
	.byte	W06
	.byte		N05   , Dn4 , v060
	.byte	W05
	.byte		N06   , Gn3 , v076
	.byte	W07
	.byte		N08   , Bn3 , v068
	.byte	W06
	.byte		        Dn4 , v072
	.byte	W06
	.byte		N05   , Gn4 , v076
	.byte	W08
	.byte	W24
	.byte		N08   , Dn3 , v064
	.byte	W06
	.byte		        Fn3 , v068
	.byte	W06
	.byte		N07   , As3 , v064
	.byte	W05
	.byte		N04   , Dn4 , v068
	.byte	W06
	.byte		N05   , Fn3 , v076
	.byte	W06
	.byte		N08   , As3 , v064
	.byte	W06
	.byte		N06   , Dn4 , v072
	.byte	W05
	.byte		N04   , Fn4 , v076
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N09   , Dn4 , v072
	.byte	W07
	.byte		N08   , Fn4 , v068
	.byte	W06
	.byte		N07   , As4 , v080
	.byte	W07
	.byte	W23
	.byte		        Fn3 , v072
	.byte	W07
	.byte		        Gs3 , v060
	.byte	W05
	.byte		N08   , Cs4 
	.byte	W06
	.byte		N04   , Fn4 , v068
	.byte	W05
	.byte		N06   , Gs3 , v076
	.byte	W06
	.byte		N08   , Cs4 , v064
	.byte	W06
	.byte		N07   , Fn4 
	.byte	W06
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		        Cs4 , v076
	.byte	W06
	.byte		N08   , Fn4 
	.byte	W07
	.byte		        Gs4 , v080
	.byte	W06
	.byte		N07   , Cs5 , v084
	.byte	W07
	.byte	W22
	.byte		N08   , Gn3 , v076
	.byte	W06
	.byte		N06   , As3 , v064
	.byte	W05
	.byte		        Ds4 , v072
	.byte	W06
	.byte		N05   , Gn4 , v076
	.byte	W05
	.byte		N07   , As3 , v080
	.byte	W05
	.byte		N09   , Ds4 , v072
	.byte	W07
	.byte		N07   , Gn4 , v068
	.byte	W05
	.byte		N06   , As4 , v072
	.byte	W06
	.byte		        Ds4 , v084
	.byte	W07
	.byte		N08   , Gn4 , v080
	.byte	W07
	.byte		        As4 , v084
	.byte	W05
	.byte		N12   , Ds5 , v076
	.byte	W10
	.byte		N08   , En5 
	.byte	W07
	.byte		N06   , Bn4 
	.byte	W05
	.byte		N05   , Gs4 , v068
	.byte	W06
	.byte		N06   , En4 , v060
	.byte	W05
	.byte		N07   , Bn4 , v080
	.byte	W06
	.byte		N09   , Gs4 , v068
	.byte	W06
	.byte		N07   , En4 , v060
	.byte	W06
	.byte		        Bn3 , v064
	.byte	W06
	.byte		N08   , Gs4 , v072
	.byte	W08
	.byte		N04   , En4 , v052
	.byte	W05
	.byte		N06   , Bn3 , v060
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        En4 , v076
	.byte	W06
	.byte		N07   , Bn3 , v060
	.byte	W05
	.byte		N06   , Gs3 , v072
	.byte	W06
	.byte		        En3 , v060
	.byte	W07
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_travel_mode_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_travel_mode_4:  @ 0x086905A0
	.byte	KEYSH , mus_travel_mode_key+0
	.byte		VOICE , 26
	.byte		VOL   , 85*mus_travel_mode_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
mus_travel_mode_4_B1:
	.byte		N02   , An2 , v080
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		N04   , An2 , v068
	.byte	W12
	.byte		N05   , Dn3 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N04   , Dn3 
	.byte	W12
	.byte		        An2 , v068
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B2:
	.byte		N05   , An2 , v072
	.byte	W12
	.byte		N04   , Dn3 , v056
	.byte	W12
	.byte		N05   , An2 , v072
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		N04   , An2 , v076
	.byte	W12
	.byte		N05   , Dn3 , v064
	.byte	W12
	.byte		N03   , An2 , v072
	.byte	W12
	.byte		N05   , Dn3 , v060
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B3:
	.byte		N04   , As2 , v072
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        As2 , v072
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 , v068
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B4:
	.byte		N04   , As2 , v068
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N02   , As2 
	.byte	W12
	.byte		N04   , Fn3 , v072
	.byte	W12
	.byte		N05   , As2 , v068
	.byte	W12
	.byte		N04   , Fn3 , v072
	.byte	W12
	.byte		        As2 , v064
	.byte	W12
	.byte		N05   , Fn3 , v068
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B5:
	.byte		N04   , An2 , v072
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		N05   , An2 , v068
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		N02   , An2 
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N02   , Dn3 , v060
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B6:
	.byte		N04   , An2 , v072
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		N02   , An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N01   , An2 , v068
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B7:
	.byte		N04   , As2 , v072
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 , v068
	.byte	W12
	.byte		        Fn3 , v072
	.byte	W12
	.byte		        As2 , v068
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N02   , As2 , v064
	.byte	W12
	.byte		N05   , Fn3 , v068
	.byte	W12
	.byte	PEND
mus_travel_mode_4_B8:
	.byte		N05   , As2 , v068
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		        Fn3 , v068
	.byte	W12
	.byte		N03   , As2 , v064
	.byte	W12
	.byte		N04   , Fn3 , v076
	.byte	W12
	.byte		N02   , As2 , v068
	.byte	W12
	.byte		N04   , Fn3 , v072
	.byte	W12
	.byte	PEND
	.byte		        Gn2 , v068
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N05   , Gn2 , v072
	.byte	W12
	.byte		N03   , Cn3 , v068
	.byte	W12
	.byte		N04   , Gn2 , v064
	.byte	W12
	.byte		N02   , Cn3 , v072
	.byte	W12
	.byte		N04   , Fn2 
	.byte	W12
	.byte		N05   , As2 
	.byte	W12
	.byte		N04   , Fn2 , v060
	.byte	W12
	.byte		N05   , As2 , v072
	.byte	W12
	.byte		        Fn2 , v068
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N04   , Fn2 , v064
	.byte	W12
	.byte		        As2 , v068
	.byte	W12
	.byte		        Bn2 , v076
	.byte	W12
	.byte		N05   , Fs3 , v072
	.byte	W12
	.byte		N04   , Bn2 , v076
	.byte	W12
	.byte		        Fs3 , v068
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		N04   , Bn2 
	.byte	W11
	.byte		N05   , Gn3 , v064
	.byte	W13
	.byte		N04   , Bn2 , v072
	.byte	W11
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		N05   , Cs3 , v068
	.byte	W12
	.byte		N04   , An3 , v076
	.byte	W13
	.byte		        An2 , v072
	.byte	W11
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        An2 , v072
	.byte	W11
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		N05   , Dn3 , v068
	.byte	W12
	.byte		N01   , An2 , v072
	.byte	W02
	.byte		N03   , An2 , v080
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		N04   , An2 , v068
	.byte	W12
	.byte		N05   , Dn3 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N04   , Dn3 
	.byte	W12
	.byte		        An2 , v068
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte	PATT
	 .word	mus_travel_mode_4_B1
	.byte	PATT
	 .word	mus_travel_mode_4_B2
	.byte	PATT
	 .word	mus_travel_mode_4_B3
	.byte	PATT
	 .word	mus_travel_mode_4_B4
	.byte	PATT
	 .word	mus_travel_mode_4_B5
	.byte	PATT
	 .word	mus_travel_mode_4_B6
	.byte	PATT
	 .word	mus_travel_mode_4_B7
	.byte	PATT
	 .word	mus_travel_mode_4_B8
	.byte		N03   , Gn2 , v060
	.byte	W12
	.byte		N04   , Cn3 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N04   , Cn3 , v064
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N05   , Cn3 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N05   , As2 , v072
	.byte	W12
	.byte		N04   , Dn3 , v068
	.byte	W12
	.byte		        As2 , v072
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        As2 , v072
	.byte	W12
	.byte		N02   , Dn3 , v064
	.byte	W12
	.byte		N05   , As2 , v072
	.byte	W12
	.byte		N02   , Dn3 , v068
	.byte	W12
	.byte		N04   , Bn2 , v076
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Bn2 , v076
	.byte	W12
	.byte		        En3 , v068
	.byte	W12
	.byte		N03   , Bn2 , v072
	.byte	W12
	.byte		N04   , En3 
	.byte	W12
	.byte		        An2 , v076
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		N05   , An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N03   , An2 
	.byte	W12
	.byte		N05   , En3 , v068
	.byte	W12
	.byte		N02   , An2 
	.byte	W12
	.byte		N03   , En3 
	.byte	W12
	.byte		        Dn2 , v064
	.byte	W12
	.byte		N02   , Bn2 , v068
	.byte	W12
	.byte		N04   , Dn2 
	.byte	W12
	.byte		N03   , Bn2 , v064
	.byte	W12
	.byte		        Dn2 , v068
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W11
	.byte		N02   , Dn2 , v068
	.byte	W11
	.byte		N04   , Bn2 
	.byte	W12
	.byte		N05   , Fn2 
	.byte	W02
	.byte	W11
	.byte		N04   , Dn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N05   , Dn3 , v072
	.byte	W13
	.byte		N04   , Fn2 , v064
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W13
	.byte		        Fn2 , v068
	.byte	W11
	.byte		        Dn3 , v076
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
	.byte		        Fn3 
	.byte	W13
	.byte		        Gs2 , v076
	.byte	W11
	.byte		        Fn3 
	.byte	W13
	.byte		        Gs2 , v072
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W11
	.byte		        Fn3 , v080
	.byte	W11
	.byte		N05   , As2 , v076
	.byte	W01
	.byte	W12
	.byte		N04   , Gn3 , v080
	.byte	W12
	.byte		        As2 , v072
	.byte	W11
	.byte		        Gn3 , v076
	.byte	W12
	.byte		        As2 , v072
	.byte	W12
	.byte		        Gn3 , v076
	.byte	W12
	.byte		        As2 , v072
	.byte	W11
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 , v076
	.byte	W02
	.byte	W11
	.byte		N05   , En3 , v068
	.byte	W12
	.byte		N04   , Bn2 , v076
	.byte	W12
	.byte		        En3 , v068
	.byte	W13
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W13
	.byte		        Bn2 
	.byte	W11
	.byte		        En3 
	.byte	W12
	.byte	W01
	.byte		N05   , Gs2 , v072
	.byte	W11
	.byte		N04   , En3 , v076
	.byte	W12
	.byte		N03   , Gs2 , v072
	.byte	W12
	.byte		N04   , En3 
	.byte	W13
	.byte		        Gs2 , v076
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N02   , Gs2 , v072
	.byte	W11
	.byte		N05   , En3 
	.byte	W12
	.byte	W96
	.byte	GOTO
	 .word	mus_travel_mode_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_travel_mode_5:  @ 0x08690857
	.byte	KEYSH , mus_travel_mode_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_travel_mode_mvl/mxv
	.byte	W96
mus_travel_mode_5_B1:
	.byte		N04   , Cn1 , v100
	.byte	W06
	.byte		        Fs1 , v052
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Fs1 , v052
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Fs1 , v052
	.byte	W06
	.byte		        Fs1 , v100
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N04
	.byte	W06
	.byte		        Fs1 , v052
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	PATT
	 .word	mus_travel_mode_5_B1
	.byte	W96
	.byte	GOTO
	 .word	mus_travel_mode_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_travel_mode:  @ 0x08690930
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_travel_mode_pri	@ Priority
	.byte	mus_travel_mode_rev	@ Reverb

	.word	mus_travel_mode_grp

	.word	mus_travel_mode_0
	.word	mus_travel_mode_1
	.word	mus_travel_mode_2
	.word	mus_travel_mode_3
	.word	mus_travel_mode_4
	.word	mus_travel_mode_5
