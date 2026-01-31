	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_dusclops_grp, gUnknown_08532808
	.equ	mus_bonus_field_dusclops_pri, 0
	.equ	mus_bonus_field_dusclops_rev, reverb_set+50
	.equ	mus_bonus_field_dusclops_mvl, 127
	.equ	mus_bonus_field_dusclops_key, 0
	.equ	mus_bonus_field_dusclops_tbs, 1
	.equ	mus_bonus_field_dusclops_exg, 0
	.equ	mus_bonus_field_dusclops_cmp, 1

	.section .rodata
	.global	mus_bonus_field_dusclops
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_dusclops_0:  @ 0x08697FAC
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte	TEMPO , 134*mus_bonus_field_dusclops_tbs/2
	.byte		VOICE , 56
	.byte		VOL   , 100*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v068
	.byte	W06
	.byte		        Gs4 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		N05   , Bn4 , v076
	.byte	W06
	.byte		N06   , Fs4 , v060
	.byte	W06
	.byte		N07   , As4 , v072
	.byte	W06
	.byte		N06   , Fn4 , v064
	.byte	W06
	.byte		N05   , An4 , v072
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N07   , Gs4 , v068
	.byte	W06
	.byte		        Ds4 , v060
	.byte	W06
	.byte		N06   , Gn4 , v072
	.byte	W06
	.byte		N07   , Dn4 , v068
	.byte	W06
	.byte		N08   , Fs4 , v064
	.byte	W06
	.byte		N06   , Cs4 , v060
	.byte	W06
	.byte		N05   , Fn4 , v064
	.byte	W06
	.byte		N07   , Cn4 , v060
	.byte	W06
	.byte		N05   , En4 , v072
	.byte	W05
	.byte		N07   , Bn3 , v064
	.byte	W06
	.byte		        Ds4 , v068
	.byte	W07
	.byte		N06   , As3 , v060
	.byte	W06
	.byte		        Dn4 , v068
	.byte	W05
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Gs3 , v060
	.byte	W06
	.byte		N05   , Cn4 , v072
	.byte	W06
	.byte		N06   , Gn3 , v064
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		N07   , As3 
	.byte	W07
	.byte		PAN   , c_v+0
	.byte		N06   , Fn3 , v072
	.byte	W06
mus_bonus_field_dusclops_0_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		N72   , Cs3 , v088
	.byte	W01
	.byte	W68
	.byte	W03
	.byte		N15   , An3 , v076
	.byte	W12
	.byte		N16   , Gs3 , v084
	.byte	W13
	.byte		N48   , Bn3 , v080
	.byte	W44
	.byte	W02
	.byte		N15   , An3 , v076
	.byte	W12
	.byte		N14   , Gs3 , v084
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N16   , An3 , v080
	.byte	W13
	.byte		N07   , Gs3 , v084
	.byte	W01
	.byte	W17
	.byte		        Fs3 , v080
	.byte	W04
	.byte		TIE   , Gs3 , v088
	.byte	W72
	.byte	W03
	.byte	W44
	.byte	W03
	.byte		EOT
	.byte	W48
	.byte		N72   , Cs4 
	.byte	W01
	.byte	W68
	.byte	W01
	.byte		N13   , An4 , v084
	.byte	W12
	.byte		N14   , Gs4 , v088
	.byte	W13
	.byte		N48   , Bn4 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N13   , An4 , v080
	.byte	W11
	.byte		        Gs4 , v088
	.byte	W12
	.byte		N14   , Fs4 
	.byte	W13
	.byte		N15   , An4 , v084
	.byte	W14
	.byte	W01
	.byte		N07   , Gs4 , v080
	.byte	W06
	.byte		N06   , Fs4 , v072
	.byte	W07
	.byte		N05   , Fn4 , v064
	.byte	W04
	.byte		N06   , Fs4 , v072
	.byte	W04
	.byte		N78   , Gs4 , v092
	.byte	W72
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N72   , Dn3 , v096
	.byte	W68
	.byte	W01
	.byte		N15   , As3 , v084
	.byte	W13
	.byte		N16   , An3 , v088
	.byte	W13
	.byte		N48   , Cn4 , v096
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N15   , As3 , v084
	.byte	W12
	.byte		N14   , An3 
	.byte	W12
	.byte		N13   , Gn3 , v080
	.byte	W11
	.byte		        As3 , v088
	.byte	W12
	.byte		N05   , An3 , v092
	.byte	W03
	.byte	W16
	.byte		N07   , Dn4 , v080
	.byte	W05
	.byte		N72   , An4 , v104
	.byte	W72
	.byte	W03
	.byte	W92
	.byte	W03
	.byte		        Dn4 , v096
	.byte	W01
	.byte	W68
	.byte	W02
	.byte		N13   , An4 , v088
	.byte	W12
	.byte		N14   , Gn4 , v084
	.byte	W13
	.byte		N11   , As4 , v088
	.byte	W01
	.byte	W08
	.byte		N08   , An4 , v080
	.byte	W06
	.byte		N11   , Gn4 
	.byte	W10
	.byte		N12   , Cn5 , v068
	.byte	W09
	.byte		N08   , As4 , v084
	.byte	W06
	.byte		N10   , An4 
	.byte	W08
	.byte		N24   , Gn4 , v088
	.byte	W24
	.byte		        As4 , v092
	.byte	W24
	.byte		N04   , An4 , v080
	.byte	W01
	.byte	W04
	.byte		N06   , Gn4 , v072
	.byte	W06
	.byte		N05   , Fs4 , v080
	.byte	W05
	.byte		N09   , Gn4 
	.byte	W07
	.byte		TIE   , An4 , v096
	.byte	W72
	.byte	W02
	.byte	W72
	.byte	W01
	.byte		EOT
	.byte	W23
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_dusclops_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_dusclops_1:  @ 0x08698121
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
mus_bonus_field_dusclops_1_B1:
	.byte		N03   , Gs2 , v084
	.byte		N03   , Cs3 
	.byte	W10
	.byte		N05
	.byte	W01
	.byte		N04   , Gs2 , v088
	.byte	W24
	.byte		        Gs2 , v084
	.byte		N05   , Cs3 
	.byte	W24
	.byte	W01
	.byte		N05
	.byte	W01
	.byte		N03   , Gs2 , v088
	.byte	W24
	.byte		N04   , Gs2 , v080
	.byte		N04   , Cs3 , v084
	.byte	W11
	.byte	PEND
mus_bonus_field_dusclops_1_B2:
	.byte		N04   , Dn3 , v088
	.byte	W01
	.byte		N03   , An2 
	.byte	W11
	.byte		N04
	.byte		N04   , Dn3 
	.byte	W23
	.byte		N04
	.byte	W01
	.byte		N03   , An2 
	.byte	W24
	.byte		N04   , Dn3 , v084
	.byte	W01
	.byte		N03   , An2 , v088
	.byte	W22
	.byte		N04   , Dn3 
	.byte	W01
	.byte		N03   , An2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte		N04   , Dn3 , v088
	.byte	W01
	.byte		N03   , An2 
	.byte	W11
	.byte		N04   , An2 , v060
	.byte		N04   , Dn3 , v080
	.byte	W23
	.byte		        Dn3 , v088
	.byte	W01
	.byte		N03   , An2 
	.byte	W24
	.byte		N04   , Dn3 , v084
	.byte	W01
	.byte		N03   , An2 , v088
	.byte	W22
	.byte		N04   , Dn3 
	.byte	W01
	.byte		N03   , An2 
	.byte	W12
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B2
mus_bonus_field_dusclops_1_B3:
	.byte		N03   , An2 , v084
	.byte		N03   , Dn3 
	.byte	W10
	.byte		N05
	.byte	W01
	.byte		N04   , An2 , v088
	.byte	W24
	.byte		        An2 , v084
	.byte		N05   , Dn3 
	.byte	W24
	.byte	W01
	.byte		N05
	.byte	W01
	.byte		N03   , An2 , v088
	.byte	W24
	.byte		N04   , An2 , v080
	.byte		N04   , Dn3 , v084
	.byte	W11
	.byte	PEND
mus_bonus_field_dusclops_1_B4:
	.byte		N04   , Ds3 , v088
	.byte	W01
	.byte		N03   , As2 
	.byte	W11
	.byte		N04
	.byte		N04   , Ds3 
	.byte	W23
	.byte		N04
	.byte	W01
	.byte		N03   , As2 
	.byte	W24
	.byte		N04   , Ds3 , v084
	.byte	W01
	.byte		N03   , As2 , v088
	.byte	W22
	.byte		N04   , Ds3 
	.byte	W01
	.byte		N03   , As2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_1_B4
	.byte	GOTO
	 .word	mus_bonus_field_dusclops_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_dusclops_2:  @ 0x0869825A
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 47
	.byte		VOL   , 102*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
mus_bonus_field_dusclops_2_B1:
	.byte		N04   , Cs1 , v084
	.byte	W11
	.byte		N05   , Cs1 , v088
	.byte	W24
	.byte		N04   , Cs1 , v092
	.byte	W24
	.byte		        Cs1 , v088
	.byte	W24
	.byte	W01
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
mus_bonus_field_dusclops_2_B2:
	.byte		N03   , Dn1 , v088
	.byte	W12
	.byte		N05   , Dn1 , v092
	.byte	W21
	.byte		N04   , Dn1 , v088
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W24
	.byte	W01
	.byte		        An1 
	.byte	W12
	.byte		N01   , Cs1 , v084
	.byte	W01
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte		N03   , Dn1 , v088
	.byte	W12
	.byte		N05   , Dn1 , v080
	.byte	W21
	.byte		N04   , Dn1 , v088
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W24
	.byte	W01
	.byte		        An1 
	.byte	W12
	.byte		N01   , Cs1 , v084
	.byte	W01
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B2
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B1
	.byte		N03   , Dn1 , v088
	.byte	W12
	.byte		N05   , Dn1 , v092
	.byte	W21
	.byte		N04   , Dn1 , v088
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W24
	.byte	W01
	.byte		        An1 
	.byte	W12
	.byte		        Cs1 , v084
	.byte	W01
mus_bonus_field_dusclops_2_B3:
	.byte		N04   , Dn1 , v084
	.byte	W11
	.byte		N05   , Dn1 , v088
	.byte	W24
	.byte		N04   , Dn1 , v092
	.byte	W24
	.byte		        Dn1 , v088
	.byte	W24
	.byte	W01
	.byte		        An1 
	.byte	W12
	.byte	PEND
mus_bonus_field_dusclops_2_B4:
	.byte		N03   , Ds1 , v088
	.byte	W12
	.byte		N05   , Ds1 , v092
	.byte	W21
	.byte		N04   , Ds1 , v088
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W24
	.byte	W01
	.byte		        As1 
	.byte	W12
	.byte		N01   , Dn1 , v084
	.byte	W01
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B4
	.byte	PATT
	 .word	mus_bonus_field_dusclops_2_B3
	.byte		N03   , Ds1 , v088
	.byte	W12
	.byte		N05   , Ds1 , v092
	.byte	W21
	.byte		N04   , Ds1 , v088
	.byte	W24
	.byte	W01
	.byte		N04
	.byte	W24
	.byte	W02
	.byte		        As1 
	.byte	W12
	.byte	GOTO
	 .word	mus_bonus_field_dusclops_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_dusclops_3:  @ 0x0869837A
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 1
	.byte		VOL   , 108*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
mus_bonus_field_dusclops_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Cs6 , v080
	.byte	W06
	.byte		N07   , Gs5 , v060
	.byte	W06
	.byte		N05   , Cn6 , v080
	.byte	W06
	.byte		N08   , Gn5 , v076
	.byte	W06
	.byte		N05   , Bn5 , v080
	.byte	W04
	.byte		N07   , Fs5 , v072
	.byte	W06
	.byte		N06   , As5 
	.byte	W07
	.byte		        Fn5 
	.byte	W05
	.byte		N05   , An5 , v080
	.byte	W06
	.byte		N07   , En5 , v076
	.byte	W06
	.byte		N06   , Gs5 
	.byte	W06
	.byte		N08   , Ds5 
	.byte	W06
	.byte		N07   , Gn5 
	.byte	W07
	.byte		        Dn5 
	.byte	W05
	.byte		N06   , Fs5 , v072
	.byte	W05
	.byte		N02   , Cs5 
	.byte	W08
	.byte		N04   , An4 , v088
	.byte		N04   , Dn5 
	.byte	W01
	.byte	W12
	.byte		N03   , An4 , v060
	.byte		N04   , Dn5 , v080
	.byte	W23
	.byte		N03   , An4 , v088
	.byte		N05   , Dn5 
	.byte	W24
	.byte	W01
	.byte		N04   , An4 
	.byte		N06   , Dn5 , v084
	.byte	W24
	.byte		N05   , Dn5 , v076
	.byte		N03   , An5 , v084
	.byte	W12
	.byte		N07   , Cs5 , v076
	.byte	W06
	.byte		N08   , Gs4 , v064
	.byte	W06
	.byte		N04   , Cn5 , v076
	.byte	W06
	.byte		N07   , Gn4 
	.byte	W06
	.byte		N05   , Bn4 , v080
	.byte	W06
	.byte		N07   , Fs4 , v076
	.byte	W06
	.byte		N06   , As4 , v072
	.byte	W06
	.byte		N07   , Fn4 , v076
	.byte	W06
	.byte		N05   , An4 , v080
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N05   , Gs4 , v072
	.byte	W06
	.byte		N08   , Ds4 
	.byte	W06
	.byte		N05   , Gn4 , v076
	.byte	W06
	.byte		N07   , Dn4 , v072
	.byte	W06
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		N02   , Cs4 , v068
	.byte	W06
	.byte		N05   , An3 , v084
	.byte		N04   , Dn4 
	.byte	W13
	.byte		        An3 
	.byte		N04   , Dn4 , v088
	.byte	W23
	.byte		N02   , An3 , v080
	.byte		N05   , Dn4 , v092
	.byte	W24
	.byte	W01
	.byte		N03   , An3 , v084
	.byte		N07   , Dn4 , v088
	.byte	W24
	.byte		N05   , Dn4 , v084
	.byte		N04   , An4 , v088
	.byte	W11
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_dusclops_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_dusclops_4:  @ 0x0869845F
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 10
	.byte		VOL   , 86*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Cs5 , v068
	.byte	W06
	.byte		        Gs4 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		N05   , Bn4 , v076
	.byte	W06
	.byte		N06   , Fs4 , v060
	.byte	W06
	.byte		N07   , As4 , v072
	.byte	W06
	.byte		N06   , Fn4 , v064
	.byte	W06
	.byte		N05   , An4 , v072
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N07   , Gs4 , v068
	.byte	W06
	.byte		        Ds4 , v060
	.byte	W06
	.byte		N06   , Gn4 , v072
	.byte	W06
	.byte		N07   , Dn4 , v068
	.byte	W06
	.byte		N08   , Fs4 , v064
	.byte	W06
	.byte		N06   , Cs4 , v060
	.byte	W06
	.byte		N05   , Fn4 , v064
	.byte	W06
	.byte		N07   , Cn4 , v060
	.byte	W06
	.byte		N05   , En4 , v072
	.byte	W05
	.byte		N07   , Bn3 , v064
	.byte	W06
	.byte		        Ds4 , v068
	.byte	W07
	.byte		N06   , As3 , v060
	.byte	W06
	.byte		        Dn4 , v068
	.byte	W05
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Gs3 , v060
	.byte	W06
	.byte		N05   , Cn4 , v072
	.byte	W06
	.byte		N06   , Gn3 , v064
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		N07   , As3 
	.byte	W07
	.byte		N06   , Fn3 , v072
	.byte	W06
mus_bonus_field_dusclops_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_dusclops_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_bonus_field_dusclops_5:  @ 0x08698501
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 49
	.byte		VOL   , 85*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_bonus_field_dusclops_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W02
	.byte		N01   , Cs3 , v064
	.byte	W02
	.byte		N68   , Cs3 , v072
	.byte	W44
	.byte	W03
	.byte		N24   , Gs2 , v064
	.byte	W24
	.byte		        Cs3 , v068
	.byte	W23
	.byte		N48   , Dn3 , v072
	.byte	W02
	.byte	W44
	.byte		N24   , An2 , v068
	.byte	W24
	.byte	W02
	.byte		        Dn3 
	.byte	W24
	.byte		N48   , Cs3 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N24   , Gs2 , v072
	.byte	W24
	.byte		        Cs3 , v068
	.byte	W24
	.byte	W01
	.byte		N48   , Dn3 
	.byte	W01
	.byte	W44
	.byte	W01
	.byte		N24   , An2 , v076
	.byte	W24
	.byte	W01
	.byte		        Dn3 , v068
	.byte	W24
	.byte	W01
	.byte		N48   , Cs3 , v076
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N24   , Gs2 , v072
	.byte	W24
	.byte		N28   , Cs3 , v068
	.byte	W24
	.byte	W02
	.byte		N48   , Dn3 , v072
	.byte	W44
	.byte	W01
	.byte		N24   , An2 , v076
	.byte	W24
	.byte	W01
	.byte		N20   , Dn3 , v072
	.byte	W24
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W01
	.byte		N48   , An2 
	.byte	W03
	.byte	W44
	.byte	W02
	.byte		N24   , Dn3 , v060
	.byte	W23
	.byte		        Fs3 , v068
	.byte	W24
	.byte	W01
	.byte		N48   , Ds3 , v064
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N44   , Gn3 , v068
	.byte	W48
	.byte		N48   , An2 , v052
	.byte	W02
	.byte	W44
	.byte		N24   , Dn3 , v056
	.byte	W24
	.byte		        Fs3 , v068
	.byte	W24
	.byte		N48   , Ds3 , v060
	.byte	W04
	.byte	W44
	.byte	W03
	.byte		N24   , Gn3 , v068
	.byte	W24
	.byte	W01
	.byte		        As3 , v076
	.byte	W24
	.byte		N32   , An3 , v068
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_dusclops_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_bonus_field_dusclops_6:  @ 0x086985B4
	.byte	KEYSH , mus_bonus_field_dusclops_key+0
	.byte		VOICE , 65
	.byte		VOL   , 85*mus_bonus_field_dusclops_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
mus_bonus_field_dusclops_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , Gs4 , v096
	.byte	W16
	.byte		N07   , Fs4 , v080
	.byte	W06
	.byte		N48   , Gs4 , v096
	.byte	W72
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W01
	.byte		N08   , Gs5 , v088
	.byte	W03
	.byte	W04
	.byte		N07   , Fs5 , v080
	.byte	W06
	.byte		        Fn5 , v060
	.byte	W05
	.byte		N09   , Fs5 , v084
	.byte	W07
	.byte		N48   , Gs5 , v092
	.byte	W72
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N72   , An2 , v088
	.byte	W72
	.byte		N13   , Ds3 , v084
	.byte	W11
	.byte		N11   , Dn3 
	.byte	W12
	.byte		N42   , Gn3 , v092
	.byte	W01
	.byte	W48
	.byte		N10   , Gn3 , v084
	.byte	W11
	.byte		N12   , Fn3 
	.byte	W11
	.byte		N10   , Ds3 , v080
	.byte	W11
	.byte		N15   , Gn3 , v088
	.byte	W12
	.byte		N05   , Fs3 , v092
	.byte	W03
	.byte	W14
	.byte		N08   , En3 , v076
	.byte	W06
	.byte		N52   , Fs3 , v092
	.byte	W48
	.byte	W02
	.byte		N04   , An3 , v084
	.byte	W13
	.byte		        Dn4 , v096
	.byte	W12
	.byte		        Cn4 
	.byte	W01
	.byte	W18
	.byte		N06   , As3 , v076
	.byte	W05
	.byte		N16   , An3 , v084
	.byte	W17
	.byte		N06   , As3 , v076
	.byte	W06
	.byte		N15   , An3 , v080
	.byte	W16
	.byte		N04   , Gn3 , v072
	.byte	W07
	.byte		N18   , Fn3 , v084
	.byte	W18
	.byte		N06   , Ds3 , v076
	.byte	W06
	.byte		N72   , Dn3 , v088
	.byte	W03
	.byte	W68
	.byte	W02
	.byte		N13   , An3 , v084
	.byte	W12
	.byte		        Dn4 , v080
	.byte	W14
	.byte		N05   , As3 , v088
	.byte	W18
	.byte		N07   , Gn3 , v076
	.byte	W05
	.byte		N52   , Ds4 , v096
	.byte	W48
	.byte	W02
	.byte		N24   , Gn4 , v100
	.byte	W23
	.byte		N05   , Dn4 , v088
	.byte	W23
	.byte		N32   , Dn4 , v100
	.byte	W36
	.byte	W02
	.byte		N14   , Dn4 , v084
	.byte	W12
	.byte		N12   , En4 
	.byte	W11
	.byte		N14   , Fs4 , v088
	.byte	W12
	.byte	W01
	.byte		N06   , Gn4 , v100
	.byte	W16
	.byte		N08   , Fn4 , v084
	.byte	W06
	.byte		N56   , Ds4 , v092
	.byte	W72
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_dusclops_6_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_dusclops:  @ 0x08698694
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_dusclops_pri	@ Priority
	.byte	mus_bonus_field_dusclops_rev	@ Reverb

	.word	mus_bonus_field_dusclops_grp

	.word	mus_bonus_field_dusclops_0
	.word	mus_bonus_field_dusclops_1
	.word	mus_bonus_field_dusclops_2
	.word	mus_bonus_field_dusclops_3
	.word	mus_bonus_field_dusclops_4
	.word	mus_bonus_field_dusclops_5
	.word	mus_bonus_field_dusclops_6
@ 0x086986B8
