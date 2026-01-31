	.include "sound/MPlayDef.s"

	.equ	mus_bonus_chance_legendary_grp, gUnknown_08532808
	.equ	mus_bonus_chance_legendary_pri, 0
	.equ	mus_bonus_chance_legendary_rev, reverb_set+50
	.equ	mus_bonus_chance_legendary_mvl, 127
	.equ	mus_bonus_chance_legendary_key, 0
	.equ	mus_bonus_chance_legendary_tbs, 1
	.equ	mus_bonus_chance_legendary_exg, 0
	.equ	mus_bonus_chance_legendary_cmp, 1

	.section .rodata
	.global	mus_bonus_chance_legendary
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_chance_legendary_0:  @ 0x0868D864
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte	TEMPO , 124*mus_bonus_chance_legendary_tbs/2
	.byte		VOICE , 19
	.byte		VOL   , 108*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N05   , An1 , v060
	.byte		N06   , An2 , v064
	.byte	W05
	.byte		N07   , Cn2 , v060
	.byte		N06   , Cn3 
	.byte	W05
	.byte		N07   , Ds3 , v072
	.byte	W01
	.byte		        Ds2 , v076
	.byte	W04
	.byte		N06   , Fs3 
	.byte	W01
	.byte		        Fs2 , v068
	.byte	W06
	.byte		N04   , An2 , v080
	.byte	W01
	.byte		        An3 , v076
	.byte	W11
	.byte		N05   , Cn4 
	.byte	W01
	.byte		N03   , Cn3 , v080
	.byte	W12
	.byte		N05   , Ds3 , v084
	.byte		N05   , Ds4 , v088
	.byte	W12
	.byte		        Dn3 , v080
	.byte		N05   , Dn4 , v084
	.byte	W14
	.byte		N22   , Bn2 , v068
	.byte		N23   , Fn3 
	.byte		N20   , Bn3 , v072
	.byte		N22   , Gs4 , v084
	.byte	W01
	.byte		        Gs3 , v076
	.byte		N22   , Dn4 
	.byte		N21   , Fn4 
	.byte	W22
mus_bonus_chance_legendary_0_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_chance_legendary_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_chance_legendary_1:  @ 0x0868D8E2
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 47
	.byte		VOL   , 102*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_bonus_chance_legendary_1_B1:
	.byte		N05   , An1 , v052
	.byte	W06
	.byte		        As1 , v060
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v060
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 , v052
	.byte	W06
	.byte		        An1 , v064
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
mus_bonus_chance_legendary_1_B2:
	.byte		N05   , An1 , v052
	.byte	W06
	.byte		        As1 , v060
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        Cs2 , v052
	.byte	W06
	.byte		        Dn2 , v060
	.byte	W06
	.byte		        Cs2 , v052
	.byte	W06
	.byte		        Dn2 , v056
	.byte	W06
	.byte		        Cs2 , v052
	.byte	W06
	.byte		        Dn2 , v048
	.byte	W06
	.byte		        Cs2 , v056
	.byte	W06
	.byte		        Dn2 , v048
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	PATT
	 .word	mus_bonus_chance_legendary_1_B1
	.byte		N05   , An1 , v052
	.byte	W06
	.byte		        As1 , v060
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte		        An1 , v052
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v056
	.byte	W06
	.byte		        As1 , v048
	.byte	W06
	.byte		        An1 , v060
	.byte	W06
	.byte		        As1 , v056
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 , v052
	.byte	W06
	.byte		        An1 , v064
	.byte	W12
	.byte	GOTO
	 .word	mus_bonus_chance_legendary_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_chance_legendary_2:  @ 0x0868DA24
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 63
	.byte		VOL   , 85*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_bonus_chance_legendary_2_B1:
	.byte	W96
	.byte	W96
	.byte		N02   , An3 , v100
	.byte		N04   , En4 , v104
	.byte	W16
	.byte		N07   , En3 , v088
	.byte	W02
	.byte		        Cn4 , v080
	.byte	W03
	.byte		N01   , An3 , v104
	.byte	W02
	.byte		N28   , An3 , v092
	.byte	W32
	.byte	W03
	.byte		N01
	.byte	W01
	.byte		N05   , An3 , v088
	.byte	W11
	.byte		N04   , En3 , v092
	.byte	W01
	.byte		N03   , Cn4 
	.byte	W11
	.byte		N04   , An3 , v096
	.byte	W01
	.byte		        En3 , v088
	.byte	W11
	.byte		N01   , Fn3 , v092
	.byte	W01
	.byte		N07   , Fn3 , v088
	.byte	W01
	.byte	W04
	.byte		N01   , En3 
	.byte	W02
	.byte		N07   , En3 , v080
	.byte	W04
	.byte		N01   , Fn3 , v088
	.byte	W01
	.byte		N05
	.byte	W84
	.byte		N03   , Cn3 , v104
	.byte	W01
	.byte		N06   , En4 , v100
	.byte	W18
	.byte		        An2 , v080
	.byte	W01
	.byte		        Cn4 , v088
	.byte	W04
	.byte		N28   , Cn3 , v096
	.byte	W01
	.byte		N24   , An3 
	.byte	W32
	.byte	W02
	.byte		N05   , An3 , v088
	.byte	W01
	.byte		        Cn3 , v092
	.byte	W11
	.byte		N04   , Cn4 , v096
	.byte	W01
	.byte		N05   , An2 , v084
	.byte	W11
	.byte		        Cn3 , v088
	.byte		N04   , En4 , v096
	.byte	W13
	.byte		N05   , Cs3 , v076
	.byte		N07   , Fn4 , v096
	.byte	W01
	.byte	W04
	.byte		        Cn3 , v084
	.byte		N07   , En4 , v096
	.byte	W05
	.byte		N06   , Cs3 , v080
	.byte	W01
	.byte		N05   , Fn4 , v096
	.byte	W84
	.byte	W01
	.byte		N04   , Cn3 
	.byte	W01
	.byte		        An4 , v100
	.byte	W04
	.byte		N07   , En4 , v076
	.byte	W07
	.byte		N06   , Cn4 , v072
	.byte	W05
	.byte		        An3 , v076
	.byte	W06
	.byte		N04   , En3 , v100
	.byte		N07   , En4 , v088
	.byte	W07
	.byte		N05   , Cn4 , v076
	.byte	W05
	.byte		        An3 
	.byte	W05
	.byte		N04   , En3 , v080
	.byte	W09
	.byte		N05   , Fn3 , v088
	.byte	W11
	.byte		        Fn3 , v096
	.byte	W01
	.byte		N04   , Gs3 
	.byte	W12
	.byte		        Ds3 , v100
	.byte		N04   , Cs4 , v088
	.byte	W12
	.byte		        Cs3 , v096
	.byte		N04   , Fn4 
	.byte	W12
	.byte		N05   , Cn3 , v104
	.byte		N07   , En4 , v088
	.byte	W06
	.byte		        Cn4 , v084
	.byte	W06
	.byte		N05   , An3 
	.byte	W06
	.byte		N06   , En3 , v068
	.byte	W06
	.byte		N05   , En3 , v104
	.byte		N07   , Cn4 , v096
	.byte	W04
	.byte		        An3 , v080
	.byte	W07
	.byte		N05   , En3 
	.byte	W04
	.byte		N07   , Cn3 , v072
	.byte	W08
	.byte		N04   , Fn3 , v100
	.byte	W11
	.byte		        Cs3 , v088
	.byte		N05   , Fn3 , v100
	.byte	W13
	.byte		        Gs2 , v096
	.byte		N05   , As3 , v104
	.byte	W11
	.byte		        Fn3 , v100
	.byte	W01
	.byte		N04   , Fn2 , v088
	.byte	W12
	.byte		N06   , En3 , v104
	.byte	W01
	.byte		        En2 
	.byte	W01
	.byte		N05   , An2 , v092
	.byte	W11
	.byte		N06   , En2 , v088
	.byte	W01
	.byte		N05   , An2 
	.byte	W80
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N04   , An4 , v116
	.byte	W17
	.byte		N03   , An4 , v108
	.byte	W05
	.byte		N24   , An4 , v116
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N04   , As4 
	.byte	W19
	.byte		N03   , As4 , v108
	.byte	W05
	.byte		N21   , As4 , v120
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N04   , En5 
	.byte	W18
	.byte		N03   , En5 , v104
	.byte	W05
	.byte		N24   , En5 , v112
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W01
	.byte		N05   , Fn5 , v116
	.byte	W19
	.byte		N03   , Fn5 , v104
	.byte	W05
	.byte		N22   , Fn5 , v100
	.byte	W24
	.byte		N17   , En5 , v116
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
	.byte		N52   , Cn3 , v096
	.byte		N52   , An3 , v112
	.byte	W68
	.byte	W03
	.byte		N03   , Cn3 , v088
	.byte		N04   , An3 , v096
	.byte	W07
	.byte		        Cn3 , v092
	.byte	W01
	.byte		        An3 , v096
	.byte	W06
	.byte		        An3 , v092
	.byte	W01
	.byte		        Cn3 , v088
	.byte	W09
	.byte		N05   , Cs3 , v104
	.byte		N06   , As3 , v108
	.byte	W01
	.byte	W22
	.byte		N48   , As3 , v104
	.byte	W01
	.byte		        Cs3 , v096
	.byte	W72
	.byte	W01
	.byte		N54   , En3 , v092
	.byte		N54   , An3 , v088
	.byte		N54   , Cn4 , v092
	.byte	W68
	.byte	W03
	.byte		N02   , En3 , v072
	.byte		N01   , An3 , v076
	.byte		N02   , Cn4 , v084
	.byte	W08
	.byte		N04   , En3 , v072
	.byte		N02   , An3 , v068
	.byte		N02   , Cn4 , v076
	.byte	W07
	.byte		N03   , An3 , v088
	.byte		N04   , Cn4 , v080
	.byte	W01
	.byte		        En3 , v068
	.byte	W08
	.byte		        As3 , v092
	.byte		N06   , Cs4 , v088
	.byte	W01
	.byte		N04   , Fn3 , v096
	.byte	W22
	.byte		N32   , As3 , v100
	.byte	W01
	.byte		        Fn3 , v096
	.byte		N32   , Cs4 , v100
	.byte	W48
	.byte	W01
	.byte		N24   , As3 , v076
	.byte		N24   , Cs4 , v084
	.byte		N24   , Fn4 , v096
	.byte	W23
	.byte		N32   , Cn4 , v088
	.byte	W01
	.byte		        An3 , v092
	.byte		N32   , En4 , v096
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_chance_legendary_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_chance_legendary_3:  @ 0x0868DC07
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 66
	.byte		VOL   , 85*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
mus_bonus_chance_legendary_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_legendary_3_B2:
	.byte		N16   , En2 , v080
	.byte	W13
	.byte		N04   , Fn2 , v036
	.byte	W02
	.byte		N05   , Fs2 , v060
	.byte	W03
	.byte		        Gn2 , v068
	.byte	W04
	.byte		N07   , Gs2 , v076
	.byte	W03
	.byte		N14   , An2 
	.byte	W12
	.byte		N06   , Gs2 , v060
	.byte	W03
	.byte		N05   , Gn2 , v064
	.byte	W04
	.byte		N06   , Fs2 , v056
	.byte	W03
	.byte		N01   , Fn2 , v064
	.byte	W01
	.byte		N16   , Fn2 , v080
	.byte	W13
	.byte		N04   , Fs2 , v036
	.byte	W02
	.byte		N05   , Gn2 , v060
	.byte	W03
	.byte		        Gs2 , v068
	.byte	W04
	.byte		N07   , An2 , v076
	.byte	W03
	.byte		N14   , As2 
	.byte	W12
	.byte		N06   , An2 , v060
	.byte	W03
	.byte		N05   , Gs2 , v064
	.byte	W04
	.byte		N06   , Gn2 , v056
	.byte	W03
	.byte		N16   , Fs2 , v064
	.byte	W01
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_legendary_3_B2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_chance_legendary_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_chance_legendary_4:  @ 0x0868DC8C
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 4
	.byte		VOL   , 108*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
mus_bonus_chance_legendary_4_B1:
	.byte	W96
	.byte	W96
mus_bonus_chance_legendary_4_B2:
	.byte		N02   , En2 , v068
	.byte		N02   , An2 , v060
	.byte	W12
	.byte		        En2 , v064
	.byte		N04   , An2 , v076
	.byte	W24
	.byte		        En2 , v064
	.byte		N05   , An2 , v068
	.byte	W12
	.byte		N04   , En2 , v060
	.byte		N04   , An2 
	.byte	W12
	.byte		N02   , En2 , v056
	.byte		N01   , An2 , v064
	.byte	W24
	.byte		        En2 , v056
	.byte		N01   , An2 , v064
	.byte	W12
	.byte	PEND
mus_bonus_chance_legendary_4_B3:
	.byte		N01   , Fn2 , v060
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		N03   , Fn2 , v060
	.byte		N05   , As2 , v056
	.byte	W24
	.byte		N03   , Fn2 , v060
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		        Fn2 , v060
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		N02   , Fn2 , v056
	.byte		N04   , As2 , v060
	.byte	W24
	.byte		N02   , Fn2 , v056
	.byte		N04   , As2 , v064
	.byte	W12
	.byte	PEND
	.byte		        En2 , v072
	.byte		N02   , An2 , v064
	.byte	W12
	.byte		        En2 , v044
	.byte		N02   , An2 , v052
	.byte	W24
	.byte		N04   , En2 , v068
	.byte		N01   , An2 , v060
	.byte	W12
	.byte		N04   , En2 , v068
	.byte		N03   , An2 
	.byte	W12
	.byte		N02   , En2 , v064
	.byte		N02   , An2 
	.byte	W24
	.byte		N01   , En2 , v068
	.byte		N01   , An2 , v064
	.byte	W12
	.byte		N04   , Fn2 , v076
	.byte		N04   , As2 , v068
	.byte	W12
	.byte		N05   , Fn2 
	.byte		N04   , As2 , v064
	.byte	W24
	.byte		N03   , Fn2 , v060
	.byte		N04   , As2 , v068
	.byte	W12
	.byte		        Fn2 , v060
	.byte		N03   , As2 , v064
	.byte	W12
	.byte		N04   , Fn2 
	.byte		N04   , As2 , v060
	.byte	W24
	.byte		N02   , Fn2 , v064
	.byte		N02   , As2 
	.byte	W12
	.byte		N05   , En2 , v076
	.byte		N05   , An2 , v068
	.byte	W12
	.byte		N04   , En2 
	.byte		N04   , An2 
	.byte	W24
	.byte		N02   , En2 
	.byte		N06   , An2 , v072
	.byte	W12
	.byte		N04   , Gs2 , v068
	.byte		N05   , Cs3 , v072
	.byte	W12
	.byte		N04   , Gs2 , v068
	.byte		N05   , Cs3 , v072
	.byte	W24
	.byte		N04   , Gs2 , v068
	.byte		N02   , Cs3 , v060
	.byte	W12
	.byte		N05   , En2 , v072
	.byte		N04   , An2 
	.byte	W12
	.byte		N05   , En2 , v064
	.byte		N04   , An2 , v072
	.byte	W24
	.byte		N01   , En2 , v064
	.byte		N02   , An2 , v076
	.byte	W12
	.byte		N04   , Gs2 , v072
	.byte		N05   , Cs3 , v068
	.byte	W12
	.byte		N04   , Gs2 , v064
	.byte		N04   , Cs3 , v068
	.byte	W24
	.byte		        Gs2 
	.byte		N04   , Cs3 , v064
	.byte	W12
	.byte		        En2 , v076
	.byte		N04   , An2 
	.byte	W12
	.byte		        En2 , v064
	.byte		N05   , An2 , v060
	.byte	W24
	.byte		N01   , En2 , v068
	.byte		N04   , An2 , v072
	.byte	W12
	.byte		N03   , Fn2 
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		N03   , Fn2 
	.byte		N05   , As2 , v056
	.byte	W24
	.byte		N02   , Fn2 , v060
	.byte		N03   , As2 , v064
	.byte	W12
	.byte		N04   , En2 , v072
	.byte		N05   , An2 , v068
	.byte	W11
	.byte		N04   , An2 , v056
	.byte	W01
	.byte		        En2 , v060
	.byte	W23
	.byte		        An2 , v064
	.byte	W01
	.byte		N01   , En2 , v056
	.byte	W12
	.byte		N04   , Fn2 , v068
	.byte		N04   , As2 , v064
	.byte	W12
	.byte		N03   , Fn2 , v068
	.byte		N04   , As2 
	.byte	W24
	.byte		N03   , Fn2 , v064
	.byte		N05   , As2 
	.byte	W12
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte		N02   , An1 , v064
	.byte		N02   , En2 , v072
	.byte	W12
	.byte		N05   , An1 , v068
	.byte		N04   , En2 , v072
	.byte	W24
	.byte		N03   , An1 , v076
	.byte		N06   , En2 , v072
	.byte	W12
	.byte		N05   , Cs2 , v064
	.byte		N05   , Gs2 , v076
	.byte	W12
	.byte		N04   , Cs2 , v060
	.byte		N04   , Gs2 , v068
	.byte	W12
	.byte		        Cn2 
	.byte		N04   , Gn2 
	.byte	W12
	.byte		        Cn2 , v060
	.byte		N03   , Gn2 , v068
	.byte	W12
	.byte		N05   , An1 , v072
	.byte		N04   , En2 , v068
	.byte	W12
	.byte		N05   , An1 
	.byte		N04   , En2 , v072
	.byte	W24
	.byte		        An1 
	.byte		N06   , En2 
	.byte	W12
	.byte		N04   , Cs2 , v064
	.byte		N05   , Gs2 , v076
	.byte	W12
	.byte		        Cs2 , v068
	.byte		N04   , Gs2 , v080
	.byte	W12
	.byte		N05   , Cn2 , v068
	.byte		N05   , Gn2 
	.byte	W12
	.byte		N04   , Cn2 , v060
	.byte		N04   , Gn2 , v072
	.byte	W12
	.byte		N05   , An1 
	.byte		N05   , En2 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte		N04   , En2 , v072
	.byte	W84
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_4_B3
	.byte	GOTO
	 .word	mus_bonus_chance_legendary_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_bonus_chance_legendary_5:  @ 0x0868DEAA
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 49
	.byte		VOL   , 102*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
mus_bonus_chance_legendary_5_B1:
	.byte		N11   , An1 , v044
	.byte	W11
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v048
	.byte	W12
	.byte		        En2 , v052
	.byte	W12
	.byte		        An1 , v048
	.byte	W12
	.byte		        En2 , v052
	.byte	W13
	.byte		        An1 , v048
	.byte	W11
	.byte		        En2 , v052
	.byte	W11
	.byte		        An1 
	.byte	W02
	.byte	W10
	.byte		        En2 , v048
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 
	.byte	W13
	.byte		        An1 , v048
	.byte	W11
	.byte		        En2 , v056
	.byte	W11
	.byte		        An1 , v052
	.byte	W13
	.byte		        En2 
	.byte	W13
	.byte		        An1 , v048
	.byte	W01
	.byte	W12
	.byte		        En2 
	.byte	W11
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v052
	.byte	W12
	.byte		        En2 , v056
	.byte	W11
	.byte		        An1 
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        As1 , v052
	.byte	W02
	.byte	W10
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W13
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 , v060
	.byte	W01
	.byte	W10
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v052
	.byte	W13
	.byte		        En2 , v060
	.byte	W11
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An1 , v052
	.byte	W11
	.byte		        En2 , v064
	.byte	W12
	.byte		        As1 , v060
	.byte	W03
	.byte	W10
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        As1 
	.byte	W13
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W01
	.byte	W10
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v056
	.byte	W11
	.byte		        En2 , v064
	.byte	W12
	.byte		        As1 , v056
	.byte	W13
	.byte		        Fn2 , v064
	.byte	W13
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        An1 , v056
	.byte	W01
	.byte	W11
	.byte		        En2 , v060
	.byte	W11
	.byte		        An1 , v056
	.byte	W13
	.byte		        En2 , v068
	.byte	W13
	.byte		        As1 , v060
	.byte	W11
	.byte		        Fn2 , v064
	.byte	W11
	.byte		        As1 , v060
	.byte	W13
	.byte		        Fn2 , v068
	.byte	W12
	.byte		        An1 , v060
	.byte	W01
	.byte	W11
	.byte		        En2 , v064
	.byte	W12
	.byte		        An1 , v052
	.byte	W13
	.byte		        En2 , v064
	.byte	W11
	.byte		        As1 , v060
	.byte	W11
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W02
	.byte	W10
	.byte		        En2 , v056
	.byte	W13
	.byte		        An1 
	.byte	W11
	.byte		        En2 , v064
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W14
	.byte		        An1 , v056
	.byte	W11
	.byte		        En2 , v052
	.byte	W11
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W13
	.byte		        An1 , v052
	.byte	W13
	.byte		        En2 , v056
	.byte	W11
	.byte		        An1 
	.byte	W12
	.byte		        En2 , v060
	.byte	W11
	.byte		        As1 
	.byte	W02
	.byte	W11
	.byte		        Fn2 , v064
	.byte	W11
	.byte		        As1 , v060
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        As1 
	.byte	W13
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W11
	.byte		        An1 
	.byte	W02
	.byte		        En4 , v072
	.byte	W04
	.byte		N10   , Cn4 , v068
	.byte	W05
	.byte		N11   , An3 
	.byte	W05
	.byte		        Cn4 , v064
	.byte	W08
	.byte		        En4 , v072
	.byte	W36
	.byte	W01
	.byte		N11
	.byte	W11
	.byte		        An4 , v080
	.byte	W12
	.byte		        En4 , v076
	.byte	W12
	.byte		        Fn4 , v092
	.byte	W02
	.byte	W17
	.byte		        En4 , v068
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W72
	.byte		        En4 , v060
	.byte	W03
	.byte	W03
	.byte		        Cn4 
	.byte	W05
	.byte		        En4 
	.byte	W05
	.byte		        An4 , v076
	.byte	W07
	.byte		        Cn5 , v084
	.byte	W36
	.byte	W02
	.byte		        Cn5 , v080
	.byte	W11
	.byte		        En5 , v076
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W13
	.byte		        Dn5 , v084
	.byte	W02
	.byte	W16
	.byte		        Cn5 , v068
	.byte	W05
	.byte		        As4 , v088
	.byte	W48
	.byte	W01
	.byte		        Dn5 , v076
	.byte	W24
	.byte	W01
	.byte		        Cn5 , v056
	.byte	W01
	.byte	W05
	.byte		        As4 , v068
	.byte	W07
	.byte		        An4 , v064
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        En2 , v056
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Cn3 , v060
	.byte	W12
	.byte		        Gn2 , v052
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs2 , v056
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		        Gn2 , v056
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v052
	.byte	W12
	.byte		        En2 , v056
	.byte	W12
	.byte		        An1 , v048
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        An1 , v052
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        An1 , v052
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        As1 , v064
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		        As1 , v056
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 , v052
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
mus_bonus_chance_legendary_5_B2:
	.byte		N11   , An1 , v056
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte	PEND
mus_bonus_chance_legendary_5_B3:
	.byte		N11   , As1 , v060
	.byte	W12
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte	PEND
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v064
	.byte	W12
	.byte		        An1 , v056
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        As1 , v064
	.byte	W12
	.byte		        Fn2 , v052
	.byte	W12
	.byte		        As1 , v060
	.byte	W11
	.byte		        Fn2 , v056
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 , v060
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W13
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B3
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B2
	.byte	PATT
	 .word	mus_bonus_chance_legendary_5_B3
	.byte	GOTO
	 .word	mus_bonus_chance_legendary_5_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_bonus_chance_legendary_6:  @ 0x0868E108
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 42
	.byte		VOL   , 46*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_bonus_chance_legendary_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N07   , An3 , v076
	.byte	W04
	.byte		N05   , En3 , v060
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W04
	.byte		N08   , En3 , v064
	.byte	W07
	.byte		N30   , An3 , v080
	.byte	W36
	.byte	W02
	.byte		N04
	.byte	W12
	.byte		N05   , Cn4 , v084
	.byte	W12
	.byte		N04   , An3 
	.byte	W12
	.byte		N05   , As3 
	.byte	W01
	.byte	W17
	.byte		N06   , Fn3 , v068
	.byte	W05
	.byte		N32   , As3 , v092
	.byte	W36
	.byte		N08   , As3 , v080
	.byte	W12
	.byte		N04   , Fn3 , v076
	.byte	W12
	.byte		N05   , As3 , v080
	.byte	W13
	.byte		N08   , An3 
	.byte	W01
	.byte	W04
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        Cn3 , v052
	.byte	W05
	.byte		N09   , En3 , v060
	.byte	W08
	.byte		N05   , An3 , v080
	.byte	W12
	.byte		N04   , En3 , v076
	.byte	W12
	.byte		N05   , Cn3 
	.byte	W13
	.byte		        An2 , v080
	.byte	W11
	.byte		N04   , Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N05   , Fn3 , v092
	.byte	W01
	.byte	W18
	.byte		N06   , Dn3 , v068
	.byte	W05
	.byte		N24   , Fn3 , v092
	.byte	W32
	.byte	W03
	.byte		N14   , Fn3 , v080
	.byte	W12
	.byte		        As3 , v088
	.byte	W12
	.byte		N15   , Dn4 , v084
	.byte	W13
	.byte		N19   , Cn4 , v088
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
	.byte	GOTO
	 .word	mus_bonus_chance_legendary_6_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_bonus_chance_legendary_7:  @ 0x0868E1AD
	.byte	KEYSH , mus_bonus_chance_legendary_key+0
	.byte		VOICE , 11
	.byte		VOL   , 64*mus_bonus_chance_legendary_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
mus_bonus_chance_legendary_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , An4 , v072
	.byte	W04
	.byte		N06   , En4 , v060
	.byte	W07
	.byte		N04   , An4 , v068
	.byte	W05
	.byte		N07   , En4 , v064
	.byte	W07
	.byte		N03   , An4 , v080
	.byte	W36
	.byte	W01
	.byte		N03
	.byte	W12
	.byte		N05   , En4 , v072
	.byte	W12
	.byte		N04   , An4 , v080
	.byte	W11
	.byte		        As4 , v076
	.byte	W01
	.byte	W05
	.byte		N05   , Fn4 , v064
	.byte	W06
	.byte		N04   , As4 , v076
	.byte	W06
	.byte		N06   , Fn4 , v064
	.byte	W06
	.byte		N04   , As4 , v084
	.byte	W36
	.byte	W01
	.byte		        As4 , v068
	.byte	W12
	.byte		N03   , Fn4 , v060
	.byte	W11
	.byte		        As4 , v080
	.byte	W13
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , En3 , v076
	.byte	W04
	.byte		N05   , An3 , v064
	.byte	W06
	.byte		        En3 , v072
	.byte	W05
	.byte		        An3 , v068
	.byte	W07
	.byte		N04   , En3 , v080
	.byte	W36
	.byte	W02
	.byte		N05   , Cn4 , v076
	.byte	W12
	.byte		N04   , En3 , v072
	.byte	W11
	.byte		        Cn4 , v076
	.byte	W13
	.byte		N06   , Fn3 , v080
	.byte	W05
	.byte		N05   , As3 , v076
	.byte	W06
	.byte		N06   , Fn3 , v072
	.byte	W05
	.byte		        As3 
	.byte	W07
	.byte		N05   , Fn3 , v076
	.byte	W36
	.byte	W01
	.byte		N04   , Dn4 , v080
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W11
	.byte		N03   , Dn4 , v080
	.byte	W12
	.byte		N06   , En3 , v064
	.byte	W01
	.byte	W05
	.byte		N05   , An3 , v076
	.byte	W06
	.byte		N06   , En3 , v068
	.byte	W05
	.byte		        An3 
	.byte	W07
	.byte		N05   , En3 , v076
	.byte	W36
	.byte		N04   , Cn4 , v080
	.byte	W12
	.byte		N05   , En3 , v076
	.byte	W12
	.byte		N04   , Cn4 
	.byte	W12
	.byte		N07   , Fn3 
	.byte	W01
	.byte	W05
	.byte		N05   , As3 , v072
	.byte	W05
	.byte		N06   , Fn3 , v068
	.byte	W06
	.byte		N07   , As3 
	.byte	W07
	.byte		N05   , Fn3 , v076
	.byte	W36
	.byte		N04   , Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 , v084
	.byte	W13
	.byte		N06   , En4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_chance_legendary_7_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_chance_legendary:  @ 0x0868E294
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_chance_legendary_pri	@ Priority
	.byte	mus_bonus_chance_legendary_rev	@ Reverb

	.word	mus_bonus_chance_legendary_grp

	.word	mus_bonus_chance_legendary_0
	.word	mus_bonus_chance_legendary_1
	.word	mus_bonus_chance_legendary_2
	.word	mus_bonus_chance_legendary_3
	.word	mus_bonus_chance_legendary_4
	.word	mus_bonus_chance_legendary_5
	.word	mus_bonus_chance_legendary_6
	.word	mus_bonus_chance_legendary_7
