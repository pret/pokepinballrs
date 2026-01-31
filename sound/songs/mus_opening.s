	.include "sound/MPlayDef.s"

	.equ	mus_opening_grp, gUnknown_08532808
	.equ	mus_opening_pri, 0
	.equ	mus_opening_rev, reverb_set+50
	.equ	mus_opening_mvl, 127
	.equ	mus_opening_key, 0
	.equ	mus_opening_tbs, 1
	.equ	mus_opening_exg, 0
	.equ	mus_opening_cmp, 1

	.section .rodata
	.global	mus_opening
	.align	2

@*********************** Track 01 ***********************@

mus_opening_0:  @ 0x0868AAA4
	.byte	KEYSH , mus_opening_key+0
	.byte	TEMPO , 168*mus_opening_tbs/2
	.byte		VOICE , 66
	.byte		VOL   , 93*mus_opening_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N05   , Dn4 , v064
	.byte		N05   , Fs4 , v068
	.byte	W06
	.byte		        Cs4 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N05   , Cn4 , v064
	.byte		N06   , En4 , v072
	.byte	W06
	.byte		N05   , Bn3 
	.byte		N06   , Ds4 , v076
	.byte	W06
	.byte		N05   , Cs4 , v064
	.byte		N05   , Fn4 , v068
	.byte	W06
	.byte		        Cn4 
	.byte		N06   , En4 
	.byte	W06
	.byte		N05   , Bn3 , v064
	.byte		N06   , Ds4 , v072
	.byte	W06
	.byte		N05   , As3 
	.byte		N06   , Dn4 , v076
	.byte	W06
	.byte		N05   , Cn4 , v064
	.byte		N05   , En4 , v068
	.byte	W06
	.byte		        Bn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N05   , As3 , v064
	.byte		N06   , Dn4 , v072
	.byte	W06
	.byte		N05   , An3 
	.byte		N06   , Cs4 , v076
	.byte	W06
	.byte		N05   , Bn3 , v064
	.byte		N05   , Ds4 , v068
	.byte	W06
	.byte		        As3 
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N05   , An3 , v064
	.byte		N06   , Cs4 , v072
	.byte	W06
	.byte		N05   , Gs3 
	.byte		N06   , Cn4 , v076
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N10   , Bn2 
	.byte		N09   , Fs3 , v084
	.byte	W12
	.byte		N03   , Bn2 , v072
	.byte		N03   , Fs3 , v080
	.byte	W36
	.byte		N13   , An2 
	.byte		N14   , En3 , v088
	.byte	W18
	.byte		N03   , An2 , v076
	.byte		N04   , En3 , v080
	.byte	W30
	.byte		N13   , Bn2 
	.byte		N14   , Fs3 , v092
	.byte	W18
	.byte		N04   , Bn2 , v072
	.byte		N04   , Fs3 , v084
	.byte	W30
	.byte		N14   , An2 , v080
	.byte		N15   , En3 , v084
	.byte	W18
	.byte		N05   , An2 , v068
	.byte		N05   , En3 , v084
	.byte	W30
	.byte		PAN   , c_v+16
	.byte		N16   , Bn2 , v076
	.byte		N15   , Fs3 , v084
	.byte	W18
	.byte		N03   , Bn2 , v072
	.byte		N03   , Fs3 , v080
	.byte	W30
	.byte		N13   , An2 
	.byte		N14   , En3 , v088
	.byte	W18
	.byte		N03   , An2 , v076
	.byte		N04   , En3 , v080
	.byte	W30
	.byte		N13   , Bn2 
	.byte		N14   , Fs3 , v092
	.byte	W18
	.byte		N04   , Bn2 , v072
	.byte		N04   , Fs3 , v084
	.byte	W30
	.byte		N14   , An2 , v080
	.byte		N15   , En3 , v084
	.byte	W24
	.byte		N14   , As2 , v080
	.byte		N15   , Fn3 , v084
	.byte	W24
	.byte		N08   , Bn4 , v080
	.byte	W06
	.byte		N07   , Fs4 , v064
	.byte	W06
	.byte		N05   , Ds4 , v056
	.byte	W06
	.byte		N07   , Bn3 , v064
	.byte	W06
	.byte		N08   , Cn5 , v076
	.byte	W06
	.byte		N06   , Gn4 , v072
	.byte	W06
	.byte		N04   , En4 , v060
	.byte	W06
	.byte		N05   , Cn4 
	.byte	W06
	.byte		N07   , Cs5 , v076
	.byte	W06
	.byte		        Gs4 , v072
	.byte	W06
	.byte		N05   , Fn4 , v064
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N08   , Dn5 , v080
	.byte	W06
	.byte		N06   , An4 , v072
	.byte	W06
	.byte		N04   , Fs4 , v060
	.byte	W06
	.byte		N07   , Dn4 , v064
	.byte	W06
	.byte		N08   , Bn4 , v084
	.byte	W06
	.byte		N07   , Fs4 , v068
	.byte	W06
	.byte		N05   , Ds4 , v060
	.byte	W06
	.byte		N07   , Bn3 , v064
	.byte	W06
	.byte		N08   , Cn5 , v080
	.byte	W06
	.byte		N06   , Gn4 , v068
	.byte	W06
	.byte		N04   , En4 , v060
	.byte	W06
	.byte		N08   , Cn4 , v068
	.byte	W06
	.byte		N07   , Cs5 , v080
	.byte	W06
	.byte		N06   , Gs4 , v072
	.byte	W06
	.byte		N04   , Fn4 , v068
	.byte	W06
	.byte		N07   , Cs4 
	.byte	W06
	.byte		N08   , Dn5 , v076
	.byte	W06
	.byte		N06   , An4 , v072
	.byte	W06
	.byte		N07   , Fs4 , v056
	.byte	W06
	.byte		N06   , Dn4 , v068
	.byte	W06
	.byte		N04   , Ds4 , v080
	.byte	W06
	.byte		N05   , Ds5 , v064
	.byte	W06
	.byte		N04   , Ds4 , v068
	.byte	W06
	.byte		N06   , Ds5 , v072
	.byte	W06
	.byte		N04   , Ds4 
	.byte	W06
	.byte		N05   , Ds5 , v076
	.byte	W06
	.byte		N04   , Ds4 , v068
	.byte	W06
	.byte		N05   , Ds5 , v072
	.byte	W06
	.byte		N04   , Ds4 
	.byte	W06
	.byte		N05   , Ds5 
	.byte	W06
	.byte		N04   , Ds4 , v064
	.byte	W06
	.byte		N05   , Ds5 , v072
	.byte	W06
	.byte		N04   , Ds4 , v064
	.byte	W06
	.byte		N06   , Ds5 , v076
	.byte	W06
	.byte		N05   , Ds4 , v068
	.byte	W06
	.byte		N04   , Ds5 , v080
	.byte	W06
	.byte		N06   , Ds5 , v076
	.byte	W06
	.byte		N05   , Ds6 , v068
	.byte	W06
	.byte		        Ds5 , v076
	.byte	W06
	.byte		N07   , Ds6 , v080
	.byte	W06
	.byte		N05   , Ds5 , v072
	.byte	W06
	.byte		N07   , Ds6 
	.byte	W06
	.byte		N05   , Ds5 
	.byte	W06
	.byte		N07   , Ds6 , v060
	.byte	W06
	.byte		N05   , Ds5 , v076
	.byte	W06
	.byte		N08   , Ds6 , v064
	.byte	W06
	.byte		N04   , Ds5 , v076
	.byte	W06
	.byte		N07   , Ds6 , v068
	.byte	W06
	.byte		N05   , Ds5 , v072
	.byte	W06
	.byte		N07   , Ds6 , v064
	.byte	W06
	.byte		N04   , Ds5 , v060
	.byte	W06
	.byte		        Ds6 , v076
	.byte	W06
	.byte		N09   , Ds5 
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening_1:  @ 0x0868AC81
	.byte	KEYSH , mus_opening_key+0
	.byte		VOICE , 70
	.byte		VOL   , 85*mus_opening_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
mus_opening_1_B1:
	.byte		N04   , Bn1 , v100
	.byte	W18
	.byte		        Ds2 
	.byte	W18
	.byte		        Fs2 
	.byte	W12
	.byte		        An1 
	.byte	W18
	.byte		        Cs2 
	.byte	W18
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_opening_1_B1
	.byte	PATT
	 .word	mus_opening_1_B1
	.byte		N04   , Bn1 , v100
	.byte	W18
	.byte		        Ds2 
	.byte	W18
	.byte		        Fs2 
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N11   , Bn1 , v076
	.byte	W12
	.byte		N03   , Bn2 , v064
	.byte	W12
	.byte		N13   , Cn2 , v076
	.byte	W12
	.byte		N04   , Cn3 , v064
	.byte	W12
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		N03   , Cs3 , v064
	.byte	W12
	.byte		N13   , Dn2 , v084
	.byte	W12
	.byte		N04   , Dn3 , v064
	.byte	W12
	.byte		N11   , Bn1 , v080
	.byte	W12
	.byte		N03   , Bn2 , v064
	.byte	W12
	.byte		N11   , Cn2 , v080
	.byte	W12
	.byte		N01   , Cn3 , v060
	.byte	W06
	.byte		N03   , Cn3 , v064
	.byte	W06
	.byte		N11   , Cs2 , v084
	.byte	W12
	.byte		N03   , Cs3 , v064
	.byte	W12
	.byte		N11   , Dn2 , v084
	.byte	W12
	.byte		N03   , Dn3 , v068
	.byte	W12
	.byte		N11   , Ds2 , v088
	.byte	W12
	.byte		N03   , Ds3 , v068
	.byte	W12
	.byte		N10   , Ds2 , v084
	.byte	W12
	.byte		N01   , Ds3 , v060
	.byte	W06
	.byte		N03   , Ds3 , v076
	.byte	W06
	.byte		N12   , Ds2 , v080
	.byte	W12
	.byte		N03   , Ds3 , v068
	.byte	W12
	.byte		N13   , Ds2 , v076
	.byte	W12
	.byte		N03   , Ds3 , v064
	.byte	W12
	.byte		N10   , Ds2 , v080
	.byte	W12
	.byte		N03   , Ds3 , v064
	.byte	W12
	.byte		N10   , Ds2 , v076
	.byte	W12
	.byte		N01   , Ds3 , v068
	.byte	W06
	.byte		N03   , Ds3 , v064
	.byte	W06
	.byte		N13   , Ds2 , v076
	.byte	W12
	.byte		N01   , Ds3 , v068
	.byte	W06
	.byte		N03   , Ds3 , v060
	.byte	W06
	.byte		N11   , Ds2 , v076
	.byte	W12
	.byte		N01   , Ds3 , v060
	.byte	W06
	.byte		N03   , Ds3 , v064
	.byte	W06
	.byte		N10   , Ds2 , v080
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening_2:  @ 0x0868AD53
	.byte	KEYSH , mus_opening_key+0
	.byte		VOICE , 12
	.byte		VOL   , 85*mus_opening_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
mus_opening_2_B1:
	.byte		N05   , Bn3 , v068
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn3 , v060
	.byte	W06
	.byte		        Fs4 , v064
	.byte	W06
	.byte		        Bn3 , v056
	.byte	W06
	.byte		        Fs4 , v064
	.byte	W06
	.byte		N05   , Bn3 , v072
	.byte	W06
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		N05   , Bn3 , v060
	.byte	W06
	.byte		        Fs4 , v064
	.byte	W06
	.byte		        Bn3 , v060
	.byte	W06
	.byte		N04   , Fs4 , v064
	.byte	W06
	.byte		        Bn3 , v056
	.byte	W06
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte	PEND
	.byte		N04   , Bn3 , v072
	.byte	W06
	.byte		N05   , Fs4 , v068
	.byte	W06
	.byte		N04   , Bn3 , v056
	.byte	W06
	.byte		N05   , Fs4 , v060
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N05   , Fs4 , v060
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N04   , Bn3 , v060
	.byte	W06
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		N05   , Bn3 
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		N04   , Bn3 , v056
	.byte	W06
	.byte		N05   , Fs4 , v064
	.byte	W06
	.byte	PATT
	 .word	mus_opening_2_B1
	.byte		N04   , Bn3 , v072
	.byte	W06
	.byte		N05   , Fs4 , v068
	.byte	W06
	.byte		N04   , Bn3 , v056
	.byte	W06
	.byte		N05   , Fs4 , v060
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N05   , Fs4 , v060
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N04   , Bn3 , v060
	.byte	W06
	.byte		N05   , Fs4 , v064
	.byte	W06
	.byte		N05
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W06
	.byte		N04   , Fs4 , v056
	.byte	W06
	.byte		N05   , Cs5 , v064
	.byte	W06
	.byte		N04   , Bn4 , v060
	.byte	W06
	.byte		N05   , Fs5 , v068
	.byte	W06
	.byte		N04   , Bn4 , v060
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W06
	.byte		N07   , Cn5 , v072
	.byte	W06
	.byte		N08   , Gn5 , v068
	.byte	W06
	.byte		N06   , Cn5 , v064
	.byte	W06
	.byte		N05   , Gn5 , v068
	.byte	W06
	.byte		N06   , Cs5 , v076
	.byte	W06
	.byte		N05   , Gs5 
	.byte	W06
	.byte		N04   , Cs5 , v068
	.byte	W06
	.byte		N03   , Gs5 , v076
	.byte	W06
	.byte		N06   , Dn5 , v080
	.byte	W06
	.byte		N07   , An5 , v076
	.byte	W06
	.byte		N06   , Dn5 , v068
	.byte	W06
	.byte		N04   , An5 , v072
	.byte	W06
	.byte		N05   , Bn4 , v076
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Bn4 , v068
	.byte	W06
	.byte		N03   , Fs5 
	.byte	W06
	.byte		N06   , Cn5 , v080
	.byte	W06
	.byte		        Gn5 , v076
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte		N05   , Gn5 , v068
	.byte	W06
	.byte		N06   , Cs5 , v076
	.byte	W06
	.byte		        Gs5 , v080
	.byte	W06
	.byte		N05   , Cs5 , v068
	.byte	W06
	.byte		N03   , Gs5 
	.byte	W06
	.byte		N06   , Dn5 , v072
	.byte	W06
	.byte		N05   , An5 , v068
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N03   , An5 , v076
	.byte	W06
	.byte		        Ds6 , v084
	.byte	W06
	.byte		N02   , Ds6 , v068
	.byte	W06
	.byte		N01
	.byte	W06
	.byte		N03   , Ds6 , v064
	.byte	W06
	.byte		N02   , Ds6 , v072
	.byte	W06
	.byte		N01   , Ds6 , v068
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N01   , Ds6 , v072
	.byte	W06
	.byte		N03   , Ds6 , v068
	.byte	W06
	.byte		N02   , Ds6 , v076
	.byte	W06
	.byte		N02
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N02
	.byte	W06
	.byte		N02
	.byte	W06
	.byte		N02
	.byte	W06
	.byte		N01   , Ds6 , v072
	.byte	W06
	.byte		N02   , Ds6 , v076
	.byte	W06
	.byte		        Ds6 , v072
	.byte	W06
	.byte		        Ds6 , v080
	.byte	W06
	.byte		        Ds6 , v076
	.byte	W06
	.byte		N02
	.byte	W06
	.byte		        Ds6 , v072
	.byte	W06
	.byte		N01   , Ds6 , v068
	.byte	W06
	.byte		        Ds6 , v072
	.byte	W06
	.byte		        Ds6 , v068
	.byte	W06
	.byte		N01
	.byte	W06
	.byte		        Ds6 , v072
	.byte	W06
	.byte		        Ds6 , v068
	.byte	W06
	.byte		N02   , Ds6 , v072
	.byte	W06
	.byte		        Ds6 , v068
	.byte	W06
	.byte		N03   , Ds6 , v076
	.byte	W06
	.byte		        Ds6 , v080
	.byte	W06
	.byte		N08   , Ds6 , v076
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening_3:  @ 0x0868AEF0
	.byte	KEYSH , mus_opening_key+0
	.byte		VOICE , 80
	.byte		VOL   , 85*mus_opening_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
mus_opening_3_B1:
	.byte		N02   , Bn2 , v072
	.byte	W12
	.byte		        Fs3 , v076
	.byte	W12
	.byte		N04   , Bn3 
	.byte	W12
	.byte		N02   , Bn2 , v064
	.byte	W12
	.byte		N04   , Bn2 , v072
	.byte	W12
	.byte		        En3 , v068
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		N03   , Bn2 , v060
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_opening_3_B1
	.byte	PATT
	 .word	mus_opening_3_B1
	.byte		N02   , Bn2 , v072
	.byte	W12
	.byte		        Fs3 , v076
	.byte	W12
	.byte		N04   , Bn3 
	.byte	W12
	.byte		N02   , Bn2 , v064
	.byte	W12
	.byte		N04   , Bn2 , v072
	.byte	W12
	.byte		        En3 , v068
	.byte	W12
	.byte		        Cs3 , v076
	.byte	W12
	.byte		N03   , Fs3 , v060
	.byte	W12
	.byte		N05   , Bn2 , v076
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W12
	.byte		N04   , As2 
	.byte	W12
	.byte		N03   , As3 
	.byte	W12
	.byte		N05   , An2 
	.byte	W12
	.byte		N04   , An3 
	.byte	W12
	.byte		        Gs2 , v084
	.byte	W12
	.byte		        Gs3 , v072
	.byte	W12
	.byte		        Bn2 , v076
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As2 , v084
	.byte	W12
	.byte		N05   , As3 , v076
	.byte	W12
	.byte		N04   , An2 
	.byte	W12
	.byte		N05   , An3 , v072
	.byte	W12
	.byte		N04   , Gs2 , v080
	.byte	W12
	.byte		N03   , Gs3 , v076
	.byte	W12
	.byte		N04   , Gn2 , v084
	.byte	W12
	.byte		N05   , Gn3 , v072
	.byte	W12
	.byte		N04   , Gn2 , v084
	.byte	W12
	.byte		N05   , Gn3 , v072
	.byte	W12
	.byte		        Gn2 , v080
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		        Gn2 , v076
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte		N04   , Gn2 , v080
	.byte	W12
	.byte		        Gn3 , v068
	.byte	W12
	.byte		        Gn2 , v076
	.byte	W12
	.byte		        Gn3 , v072
	.byte	W12
	.byte		        Gn2 , v076
	.byte	W12
	.byte		N03   , Gn3 , v068
	.byte	W12
	.byte		N04   , Gn2 , v080
	.byte	W12
	.byte		        Gn3 , v076
	.byte	W12
	.byte		N10   , Gn2 , v080
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening_4:  @ 0x0868AFB8
	.byte	KEYSH , mus_opening_key+0
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_opening_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		N07   , Bn0 , v080
	.byte	W48
	.byte		        Bn0 , v076
	.byte	W48
	.byte		N06   , Bn0 , v080
	.byte	W48
	.byte		        Bn0 , v084
	.byte	W48
	.byte		N06
	.byte	W48
	.byte		N07
	.byte	W48
	.byte		N06
	.byte	W48
	.byte		        An0 , v080
	.byte	W24
	.byte		        As0 
	.byte	W24
	.byte		N07   , Bn0 
	.byte	W24
	.byte		N08   , Cn1 
	.byte	W24
	.byte		N07   , Cs1 , v072
	.byte	W24
	.byte		        Dn1 , v080
	.byte	W24
	.byte		N09   , Bn0 , v076
	.byte	W24
	.byte		        Cn1 , v080
	.byte	W24
	.byte		N08   , Cs1 , v076
	.byte	W24
	.byte		N07   , Dn1 , v080
	.byte	W24
	.byte		N06   , Ds1 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , Ds1 , v076
	.byte	W24
	.byte		N06   , Ds1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Ds1 , v084
	.byte	W24
	.byte		N06   , Ds1 , v080
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N08   , Gn1 
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening_5:  @ 0x0868B01D
	.byte	KEYSH , mus_opening_key+0
	.byte		VOICE , 0
	.byte		VOL   , 54*mus_opening_mvl/mxv
	.byte		N12   , Cs2 , v040
	.byte	W12
	.byte		N24   , Cs2 , v052
	.byte	W24
	.byte		        Cs2 , v072
	.byte	W24
	.byte		        Cs2 , v092
	.byte	W24
	.byte		        Cs2 , v100
	.byte	W12
mus_opening_5_B1:
	.byte		N04   , Cn1 , v100
	.byte	W18
	.byte		N04
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		N04
	.byte	W18
	.byte		N04
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N04
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_opening_5_B1
	.byte	PATT
	 .word	mus_opening_5_B1
	.byte	PATT
	 .word	mus_opening_5_B1
mus_opening_5_B2:
	.byte		N04   , Cn1 , v100
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_opening_5_B2
	.byte	PATT
	 .word	mus_opening_5_B2
	.byte		N04   , Cn1 , v100
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		N07   , Dn1 , v100
	.byte	W96
	.byte	W96
	.byte	W96
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

mus_opening:  @ 0x0868B0A8
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_opening_pri	@ Priority
	.byte	mus_opening_rev	@ Reverb

	.word	mus_opening_grp

	.word	mus_opening_0
	.word	mus_opening_1
	.word	mus_opening_2
	.word	mus_opening_3
	.word	mus_opening_4
	.word	mus_opening_5
