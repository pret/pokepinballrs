	.include "sound/MPlayDef.s"

	.equ	mus_bonus_chance_grp, gUnknown_08532808
	.equ	mus_bonus_chance_pri, 0
	.equ	mus_bonus_chance_rev, reverb_set+50
	.equ	mus_bonus_chance_mvl, 127
	.equ	mus_bonus_chance_key, 0
	.equ	mus_bonus_chance_tbs, 1
	.equ	mus_bonus_chance_exg, 0
	.equ	mus_bonus_chance_cmp, 1

	.section .rodata
	.global	mus_bonus_chance
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_chance_0:  @ 0x0868CA68
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte	TEMPO , 136*mus_bonus_chance_tbs/2
	.byte		VOICE , 65
	.byte		VOL   , 102*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_0_B1:
	.byte	W96
	.byte	W92
	.byte	W02
	.byte		N04   , En4 , v084
	.byte	W02
	.byte	W17
	.byte		N07   , Cs4 , v076
	.byte	W05
	.byte		N24   , An3 , v080
	.byte	W36
	.byte		N04   , An3 , v076
	.byte	W12
	.byte		        Cs4 
	.byte	W11
	.byte		        En4 
	.byte	W12
	.byte		N05   , Dn4 , v080
	.byte	W03
	.byte	W18
	.byte		N04   , Bn3 , v068
	.byte	W04
	.byte		N44   , Gn3 , v076
	.byte	W72
	.byte		N04   , En4 , v084
	.byte	W02
	.byte	W18
	.byte		N06   , Cs4 , v072
	.byte	W05
	.byte		N24   , An3 , v080
	.byte	W32
	.byte	W03
	.byte		N04   , Cs4 , v076
	.byte	W12
	.byte		N03   , En4 
	.byte	W10
	.byte		N04   , An4 , v080
	.byte	W12
	.byte		N03   , Gn4 , v084
	.byte	W04
	.byte	W16
	.byte		N05   , Dn4 , v060
	.byte	W05
	.byte		N28   , Bn4 , v092
	.byte	W36
	.byte		N04   , Bn4 , v084
	.byte	W13
	.byte		N05   , Cs5 , v080
	.byte	W11
	.byte		        Dn5 , v076
	.byte	W13
	.byte		N23   , Cs5 , v084
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
	.byte		N03   , Fn3 , v076
	.byte		N03   , Dn4 , v084
	.byte	W15
	.byte		N02   , As3 , v072
	.byte	W07
	.byte		N24   , Fn3 , v080
	.byte		N28   , Dn4 , v084
	.byte	W36
	.byte		N05   , Dn4 , v072
	.byte	W01
	.byte		N02   , Fn3 , v060
	.byte	W11
	.byte		N04   , Fn3 , v068
	.byte		N05   , En4 , v064
	.byte	W12
	.byte		        Fn4 , v080
	.byte	W12
	.byte		N06   , En4 , v084
	.byte	W01
	.byte		N02   , Cn4 , v076
	.byte	W01
	.byte	W23
	.byte		N28   , Cn4 , v088
	.byte	W01
	.byte		N23   , Gn3 , v076
	.byte	W36
	.byte		N02   , Cn4 , v060
	.byte		N04   , En4 , v080
	.byte	W11
	.byte		N07   , Fs4 , v072
	.byte	W01
	.byte		N02   , Dn4 , v052
	.byte	W11
	.byte		N05   , Gn4 , v068
	.byte	W01
	.byte		N02   , En4 , v044
	.byte	W11
	.byte		N06   , Fs4 , v084
	.byte	W01
	.byte		N02   , Dn4 , v076
	.byte	W17
	.byte		N03   , En4 , v068
	.byte	W06
	.byte		N28   , Fs4 , v092
	.byte	W01
	.byte		N24   , Dn4 , v084
	.byte	W32
	.byte	W02
	.byte		N06   , Fs4 , v064
	.byte	W01
	.byte		N02   , Dn4 , v048
	.byte	W11
	.byte		N07   , Gn4 , v072
	.byte	W01
	.byte		N02   , En4 , v064
	.byte	W11
	.byte		N04   , Fs4 , v068
	.byte		N05   , An4 , v076
	.byte	W13
	.byte		N14   , En4 , v068
	.byte		N15   , Gs4 , v084
	.byte	W01
	.byte	W18
	.byte		N09   , Fs4 , v072
	.byte		N09   , An4 , v080
	.byte	W14
	.byte		N11   , Gs4 , v084
	.byte	W01
	.byte		N08   , Bn4 , v080
	.byte	W15
	.byte		N09   , Gs4 , v076
	.byte		N10   , Bn4 , v080
	.byte	W17
	.byte		N11   , Cs5 , v084
	.byte	W01
	.byte		N09   , An4 , v072
	.byte	W15
	.byte		N11   , Dn5 , v080
	.byte	W01
	.byte		        Bn4 , v084
	.byte	W14
	.byte	W01
	.byte		N24   , Cs5 , v088
	.byte	W01
	.byte		N23   , An4 , v076
	.byte	W92
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
	.byte	GOTO
	 .word	mus_bonus_chance_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_chance_1:  @ 0x0868CB9B
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 47
	.byte		VOL   , 102*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , En1 , v036
	.byte	W24
	.byte		        En1 , v044
	.byte	W24
	.byte		        En1 , v056
	.byte	W24
	.byte		        En1 , v068
	.byte	W06
	.byte		        En1 , v044
	.byte	W06
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v068
	.byte	W05
	.byte		        An1 , v104
	.byte	W01
	.byte	W12
	.byte		N02   , Bn1 , v088
	.byte	W12
	.byte		N05   , An1 , v092
	.byte	W12
	.byte		N02   , Bn1 , v096
	.byte	W12
	.byte		N05   , An1 , v092
	.byte	W06
	.byte		N03   , Bn1 , v068
	.byte	W06
	.byte		N02   , Bn1 , v084
	.byte	W12
	.byte		N04   , An1 , v092
	.byte	W12
	.byte		N02   , Bn1 
	.byte	W12
	.byte		N05   , Gn1 
	.byte	W12
	.byte		N03   , An1 , v096
	.byte	W12
	.byte		N05   , Gn1 , v088
	.byte	W12
	.byte		N02   , An1 , v100
	.byte	W12
	.byte		N04   , Gn1 , v084
	.byte	W06
	.byte		N03   , An1 , v068
	.byte	W06
	.byte		N02   , An1 , v096
	.byte	W12
	.byte		N05   , Gn1 , v080
	.byte	W12
	.byte		N02   , An1 , v096
	.byte	W12
mus_bonus_chance_1_B1:
	.byte		N05   , An1 , v104
	.byte	W12
	.byte		        Bn1 , v096
	.byte	W12
	.byte		N04   , An1 , v100
	.byte	W12
	.byte		N02   , Bn1 , v092
	.byte	W12
	.byte		N04   , An1 , v088
	.byte	W06
	.byte		N03   , Bn1 , v068
	.byte	W06
	.byte		N02   , Bn1 , v084
	.byte	W12
	.byte		N04   , An1 , v096
	.byte	W12
	.byte		N02   , Bn1 , v088
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W12
	.byte		N02   , An1 , v092
	.byte	W12
	.byte		N04   , Gn1 , v088
	.byte	W12
	.byte		N01   , An1 , v080
	.byte	W12
	.byte		N04   , Gn1 , v088
	.byte	W06
	.byte		N03   , An1 , v068
	.byte	W06
	.byte		N05   , An1 , v104
	.byte	W12
	.byte		N04   , Gn1 , v088
	.byte	W12
	.byte		N02   , An1 , v096
	.byte	W12
	.byte		N05   , An1 , v100
	.byte	W12
	.byte		N03   , Bn1 , v092
	.byte	W12
	.byte		N05   , An1 , v096
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N05   , An1 
	.byte	W06
	.byte		N03   , Bn1 , v068
	.byte	W06
	.byte		        Bn1 , v096
	.byte	W12
	.byte		N04   , An1 , v092
	.byte	W12
	.byte		N02   , Bn1 
	.byte	W12
	.byte		N05   , Gn1 , v084
	.byte	W12
	.byte		N02   , An1 , v080
	.byte	W12
	.byte		N05   , Gn1 , v084
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		N05   , Gn1 
	.byte	W06
	.byte		N03   , An1 , v068
	.byte	W06
	.byte		N02   , An1 , v092
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		N05   , An1 , v096
	.byte	W12
	.byte		N03   , Bn1 , v084
	.byte	W12
	.byte		N05   , An1 , v092
	.byte	W12
	.byte		N02   , Bn1 
	.byte	W12
	.byte		N05   , An1 
	.byte	W06
	.byte		N03   , Bn1 , v068
	.byte	W06
	.byte		        Bn1 , v096
	.byte	W12
	.byte		        An1 , v084
	.byte	W12
	.byte		N02   , Bn1 , v088
	.byte	W12
	.byte		N05   , Gn1 , v092
	.byte	W12
	.byte		N02   , An1 , v088
	.byte	W12
	.byte		N05   , Gn1 
	.byte	W12
	.byte		N02   , An1 , v096
	.byte	W12
	.byte		N03   , Gn1 , v080
	.byte	W06
	.byte		        An1 , v068
	.byte	W06
	.byte		        An1 , v096
	.byte	W12
	.byte		N04   , Gn1 , v084
	.byte	W12
	.byte		N02   , An1 , v092
	.byte	W12
	.byte		N05   , An1 , v100
	.byte	W12
	.byte		N03   , Bn1 , v092
	.byte	W12
	.byte		        An1 , v084
	.byte	W12
	.byte		N02   , Bn1 , v092
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		        Bn1 , v068
	.byte	W06
	.byte		        Bn1 , v100
	.byte	W12
	.byte		N04   , An1 
	.byte	W12
	.byte		N03   , Bn1 , v096
	.byte	W12
	.byte		N05   , Gn1 , v104
	.byte	W12
	.byte		N03   , An1 , v088
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N02   , An1 , v088
	.byte	W12
	.byte		        Gn1 , v084
	.byte	W06
	.byte		N03   , An1 , v068
	.byte	W06
	.byte		        An1 , v096
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 , v092
	.byte	W12
	.byte		N04   , An1 , v100
	.byte	W12
	.byte		N03   , Bn1 , v096
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		N04   , Bn1 
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		        Bn1 , v068
	.byte	W06
	.byte		N04   , Bn1 , v096
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte		        Gn1 , v100
	.byte	W12
	.byte		N03   , An1 , v092
	.byte	W12
	.byte		N02   , Gn1 , v088
	.byte	W12
	.byte		N04   , An1 , v092
	.byte	W12
	.byte		N03   , Gn1 , v100
	.byte	W06
	.byte		        An1 , v068
	.byte	W06
	.byte		N05   , An1 , v092
	.byte	W12
	.byte		N02   , Gn1 
	.byte	W12
	.byte		N03   , An1 , v096
	.byte	W12
	.byte		N01   , An1 , v100
	.byte	W12
	.byte		N04   , En2 , v096
	.byte	W12
	.byte		N02   , An1 
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N04   , En2 , v092
	.byte	W12
	.byte		N02   , An1 , v096
	.byte	W12
	.byte		N03   , En2 , v092
	.byte	W12
	.byte		        An1 , v096
	.byte	W06
	.byte		        En2 , v068
	.byte	W06
	.byte		N02   , En2 , v096
	.byte	W12
	.byte		N04   , Gn1 , v104
	.byte	W12
	.byte		N02   , Dn2 , v084
	.byte	W12
	.byte		N03   , Gn1 , v096
	.byte	W06
	.byte		        Dn2 , v068
	.byte	W06
	.byte		N02   , Dn2 , v092
	.byte	W12
	.byte		N03   , Gn1 , v088
	.byte	W12
	.byte		N02   , Dn2 
	.byte	W12
	.byte		        Gn1 , v092
	.byte	W06
	.byte		N03   , Dn2 , v068
	.byte	W06
	.byte		N02   , Dn2 , v092
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte		        En2 , v088
	.byte	W12
	.byte		        An1 , v084
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N02   , En2 , v092
	.byte	W12
	.byte		N01   , An1 , v084
	.byte	W12
	.byte		N02   , En2 
	.byte	W12
	.byte		N01   , An1 , v088
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N02   , En2 , v096
	.byte	W12
	.byte		        Gn1 , v092
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 , v088
	.byte	W06
	.byte		N03   , Dn2 , v068
	.byte	W06
	.byte		N02   , Dn2 , v088
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N03   , Dn2 , v084
	.byte	W12
	.byte		        Gn1 , v088
	.byte	W06
	.byte		        Dn2 , v068
	.byte	W06
	.byte		        Dn2 , v092
	.byte	W12
	.byte		N02   , An1 , v100
	.byte	W12
	.byte		N03   , En2 , v088
	.byte	W12
	.byte		N02   , An1 , v084
	.byte	W12
	.byte		N03   , En2 , v092
	.byte	W12
	.byte		N02   , An1 , v088
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N04   , En2 , v088
	.byte	W12
	.byte		N02   , An1 , v080
	.byte	W12
	.byte		        En2 , v084
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W12
	.byte		N02   , Dn2 
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W12
	.byte		N04   , Dn2 , v080
	.byte	W12
	.byte		N03   , Gn1 , v084
	.byte	W06
	.byte		        Dn2 , v068
	.byte	W06
	.byte		N04   , Dn2 , v084
	.byte	W12
	.byte		N03   , Gn1 , v088
	.byte	W12
	.byte		N02   , Dn2 , v084
	.byte	W12
	.byte		N04   , An1 , v100
	.byte	W12
	.byte		N02   , En2 , v088
	.byte	W12
	.byte		        An1 , v080
	.byte	W12
	.byte		N03   , En2 , v092
	.byte	W12
	.byte		N02   , An1 , v088
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N05   , En2 , v084
	.byte	W12
	.byte		N03   , An1 , v088
	.byte	W12
	.byte		N02   , En2 
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W12
	.byte		        Dn2 , v084
	.byte	W12
	.byte		N05   , Gn1 
	.byte	W12
	.byte		N02   , Dn2 , v088
	.byte	W12
	.byte		N04   , Gn1 , v084
	.byte	W06
	.byte		N03   , Dn2 , v068
	.byte	W06
	.byte		        Dn2 , v092
	.byte	W12
	.byte		        Gn1 , v076
	.byte	W12
	.byte		        Dn2 , v092
	.byte	W12
	.byte		N02   , As1 , v112
	.byte	W12
	.byte		N03   , Fn2 , v092
	.byte	W12
	.byte		N04   , As1 , v112
	.byte	W06
	.byte		N03   , Fn2 , v068
	.byte	W06
	.byte		        Fn2 , v092
	.byte	W12
	.byte		        As1 , v104
	.byte	W12
	.byte		        Fn2 , v084
	.byte	W12
	.byte		        As1 , v100
	.byte	W06
	.byte		        Fn2 , v068
	.byte	W06
	.byte		N04   , Fn2 , v100
	.byte	W12
	.byte		        Cn2 , v104
	.byte	W12
	.byte		N02   , Gn2 , v088
	.byte	W12
	.byte		        Cn2 , v096
	.byte	W06
	.byte		N03   , Gn2 , v068
	.byte	W06
	.byte		        Gn2 , v092
	.byte	W12
	.byte		N04   , Cn2 , v104
	.byte	W12
	.byte		        Gn2 , v084
	.byte	W12
	.byte		N05   , Cn2 , v100
	.byte	W06
	.byte		N03   , Gn2 , v068
	.byte	W06
	.byte		N04   , Gn2 , v096
	.byte	W12
	.byte		        Dn2 , v104
	.byte	W12
	.byte		        An2 , v100
	.byte	W12
	.byte		        Dn2 , v104
	.byte	W06
	.byte		N03   , An2 , v068
	.byte	W06
	.byte		N05   , An2 , v100
	.byte	W12
	.byte		N02   , Dn2 
	.byte	W12
	.byte		N03   , An2 , v096
	.byte	W12
	.byte		N04   , Dn2 , v100
	.byte	W06
	.byte		N03   , An2 , v068
	.byte	W06
	.byte		N02   , An2 , v100
	.byte	W12
	.byte		N03   , En2 , v096
	.byte	W12
	.byte		        Bn2 , v092
	.byte	W12
	.byte		N04   , En2 , v096
	.byte	W06
	.byte		N03   , Bn2 , v068
	.byte	W06
	.byte		N02   , Bn2 , v092
	.byte	W12
	.byte		N04   , En2 , v104
	.byte	W06
	.byte		N03   , En2 , v068
	.byte	W06
	.byte		N04   , Bn1 , v100
	.byte	W06
	.byte		N03   , Bn1 , v068
	.byte	W06
	.byte		N01   , En1 , v088
	.byte	W06
	.byte		N03   , En1 , v068
	.byte	W06
	.byte		N02   , En2 , v096
	.byte	W12
	.byte		N04   , An1 , v104
	.byte	W12
	.byte		N02   , En2 , v092
	.byte	W12
	.byte		N04   , An1 , v100
	.byte	W12
	.byte		N02   , En2 , v096
	.byte	W12
	.byte		N03   , An1 , v100
	.byte	W06
	.byte		        En2 , v068
	.byte	W06
	.byte		        En2 , v088
	.byte	W12
	.byte		N04   , An1 , v080
	.byte	W12
	.byte		        En2 , v092
	.byte	W12
	.byte		N05   , Gn1 , v096
	.byte	W12
	.byte		N03   , Dn2 , v084
	.byte	W12
	.byte		N04   , Gn1 , v092
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W06
	.byte		N03   , Dn2 , v068
	.byte	W06
	.byte		N05   , Dn2 , v084
	.byte	W12
	.byte		N04   , Gn1 , v092
	.byte	W12
	.byte		N03   , Dn2 , v084
	.byte	W12
	.byte		N04   , An1 , v096
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v092
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		        En2 , v068
	.byte	W06
	.byte		N04   , En2 , v088
	.byte	W12
	.byte		N03   , An1 , v092
	.byte	W12
	.byte		N04   , En2 
	.byte	W12
	.byte		N03   , Gn1 , v096
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N02   , Gn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn2 , v068
	.byte	W06
	.byte		        Dn2 , v088
	.byte	W12
	.byte		N05   , Gn1 , v104
	.byte	W12
	.byte		N03   , Dn2 , v088
	.byte	W12
	.byte		N02   , An1 , v096
	.byte	W12
	.byte		        Bn1 , v080
	.byte	W12
	.byte		        An1 , v100
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte		        Bn1 , v088
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte		N03   , Gn1 , v104
	.byte	W12
	.byte		        An1 , v100
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		        Gn1 , v088
	.byte	W12
	.byte		N03   , An1 , v096
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		N03   , An1 , v104
	.byte	W12
	.byte		N02   , Bn1 , v096
	.byte	W12
	.byte		        An1 , v100
	.byte	W12
	.byte		        Bn1 , v096
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte		        Bn1 , v092
	.byte	W12
	.byte		N03   , Gn1 , v096
	.byte	W12
	.byte		N02   , An1 , v092
	.byte	W12
	.byte		N03   , Gn1 , v096
	.byte	W12
	.byte		N01   , An1 , v092
	.byte	W12
	.byte		N02   , Gn1 , v084
	.byte	W12
	.byte		N01   , An1 , v088
	.byte	W12
	.byte		N02   , Gn1 , v080
	.byte	W12
	.byte		N01   , An1 , v088
	.byte	W12
	.byte		N04   , An1 , v104
	.byte	W12
	.byte		N02   , Bn1 , v084
	.byte	W12
	.byte		        An1 , v092
	.byte	W12
	.byte		        Bn1 , v084
	.byte	W12
	.byte		N03   , An1 , v096
	.byte	W12
	.byte		N02   , Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N04   , Gn1 , v100
	.byte	W12
	.byte		N03   , An1 , v096
	.byte	W12
	.byte		N04   , Gn1 
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		        Gn1 , v092
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte		        Gn1 , v088
	.byte	W12
	.byte		        An1 , v096
	.byte	W12
	.byte	GOTO
	 .word	mus_bonus_chance_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_chance_2:  @ 0x0868D00D
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 11
	.byte		VOL   , 86*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , En4 , v060
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		N05   , En4 , v064
	.byte	W05
	.byte		N06   , Fs4 , v060
	.byte	W07
	.byte		        En4 , v064
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		N05   , En4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N05   , En4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N05   , En4 , v064
	.byte	W05
	.byte		N07   , Fs4 , v060
	.byte	W07
	.byte		N06   , En4 
	.byte	W05
	.byte		        Fs4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v068
	.byte	W06
	.byte		N09   , Gs4 , v072
	.byte	W07
	.byte		N12   , An4 , v064
	.byte	W06
	.byte		N05   , Bn4 , v068
	.byte	W06
	.byte		        An4 , v060
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N04   , An4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N05   , An4 , v068
	.byte	W06
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N04   , An4 , v064
	.byte	W06
	.byte		N06   , Bn4 , v060
	.byte	W06
	.byte		N05   , An4 , v068
	.byte	W06
	.byte		        Bn4 , v064
	.byte	W06
	.byte		        An4 , v060
	.byte		N08   , Bn4 , v056
	.byte	W12
	.byte		N06   , Gn4 , v064
	.byte	W06
	.byte		        An4 , v060
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		N06   , An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v064
	.byte	W06
	.byte		N06   , An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v064
	.byte	W06
	.byte		        An4 , v056
	.byte	W06
	.byte		N06   , Gn4 , v060
	.byte	W06
	.byte		        An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v060
	.byte	W06
	.byte		        An4 , v052
	.byte	W06
	.byte		N04   , Gn4 , v060
	.byte	W06
	.byte		N02   , An4 
	.byte	W06
mus_bonus_chance_2_B1:
	.byte		N05   , An4 , v060
	.byte	W06
	.byte		        Bn4 , v056
	.byte	W06
	.byte		N04   , An4 , v060
	.byte	W06
	.byte		N06   , Bn4 , v064
	.byte	W06
	.byte		N05   , An4 , v060
	.byte	W06
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 , v060
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N05   , An4 
	.byte	W06
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 , v060
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N05   , An4 
	.byte	W06
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 
	.byte	W06
	.byte		        Bn4 , v060
	.byte	W06
mus_bonus_chance_2_B2:
	.byte	W01
	.byte		N05   , Gn4 , v056
	.byte	W05
	.byte		        An4 , v060
	.byte	W06
	.byte		        Gn4 , v056
	.byte	W05
	.byte		N06   , An4 
	.byte	W07
	.byte		N05   , Gn4 
	.byte	W05
	.byte		N06   , An4 
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W05
	.byte		N06   , An4 , v060
	.byte	W06
	.byte		        Gn4 , v052
	.byte	W06
	.byte		        An4 
	.byte	W07
	.byte		N05   , Gn4 , v056
	.byte	W05
	.byte		N06   , An4 
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		        An4 , v052
	.byte	W08
	.byte	PEND
mus_bonus_chance_2_B3:
	.byte		N05   , An4 , v060
	.byte	W06
	.byte		        Bn4 , v056
	.byte	W06
	.byte		N04   , An4 , v060
	.byte	W04
	.byte		N06   , Bn4 , v064
	.byte	W08
	.byte		N05   , An4 , v060
	.byte	W05
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 , v060
	.byte	W05
	.byte		N06   , Bn4 
	.byte	W08
	.byte		N05   , An4 
	.byte	W05
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 , v060
	.byte	W05
	.byte		N06   , Bn4 
	.byte	W07
	.byte		N05   , An4 
	.byte	W06
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		N05   , An4 
	.byte	W06
	.byte		        Bn4 , v060
	.byte	W07
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte		N05   , As4 , v060
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		N04   , As4 , v060
	.byte	W04
	.byte		N06   , Cn5 , v064
	.byte	W08
	.byte		N05   , As4 , v060
	.byte	W05
	.byte		N06   , Cn5 , v056
	.byte	W06
	.byte		N05   , As4 , v060
	.byte	W05
	.byte		N06   , Cn5 
	.byte	W08
	.byte		N05   , As4 
	.byte	W05
	.byte		N06   , Cn5 , v056
	.byte	W06
	.byte		N05   , As4 , v060
	.byte	W05
	.byte		N06   , Cn5 
	.byte	W07
	.byte		N05   , As4 
	.byte	W06
	.byte		N06   , Cn5 , v056
	.byte	W06
	.byte		N05   , As4 
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W07
	.byte		N05
	.byte	W06
	.byte		        Dn5 , v056
	.byte	W06
	.byte		N04   , Cn5 , v060
	.byte	W04
	.byte		N06   , Dn5 , v064
	.byte	W08
	.byte		N05   , Cn5 , v060
	.byte	W05
	.byte		N06   , Dn5 , v056
	.byte	W06
	.byte		N05   , Cn5 , v060
	.byte	W05
	.byte		N06   , Dn5 
	.byte	W08
	.byte		N05   , Cn5 
	.byte	W05
	.byte		N06   , Dn5 , v056
	.byte	W06
	.byte		N05   , Cn5 , v060
	.byte	W05
	.byte		N06   , Dn5 
	.byte	W07
	.byte		N05   , Cn5 
	.byte	W06
	.byte		N06   , Dn5 , v056
	.byte	W06
	.byte		N05   , Cn5 
	.byte	W06
	.byte		        Dn5 , v060
	.byte	W07
	.byte		N05
	.byte	W06
	.byte		        En5 , v056
	.byte	W06
	.byte		N04   , Dn5 , v060
	.byte	W04
	.byte		N06   , En5 , v064
	.byte	W08
	.byte		N05   , Dn5 , v060
	.byte	W05
	.byte		N06   , En5 , v056
	.byte	W06
	.byte		N05   , Dn5 , v060
	.byte	W05
	.byte		N06   , En5 
	.byte	W08
	.byte		N05   , Dn5 
	.byte	W05
	.byte		N06   , En5 , v056
	.byte	W06
	.byte		N05   , Dn5 , v060
	.byte	W05
	.byte		N06   , En5 
	.byte	W07
	.byte		N05   , Dn5 
	.byte	W06
	.byte		N06   , En5 , v056
	.byte	W06
	.byte		N05   , Dn5 
	.byte	W06
	.byte		        En5 , v060
	.byte	W07
	.byte		N05
	.byte	W06
	.byte		        Fs5 , v056
	.byte	W06
	.byte		N04   , En5 , v060
	.byte	W04
	.byte		N06   , Fs5 , v064
	.byte	W08
	.byte		N05   , En5 , v060
	.byte	W05
	.byte		N06   , Fs5 , v056
	.byte	W06
	.byte		N05   , En5 , v060
	.byte	W05
	.byte		N06   , Fs5 
	.byte	W08
	.byte		N05   , En5 
	.byte	W05
	.byte		N06   , Fs5 , v056
	.byte	W06
	.byte		N05   , En5 , v060
	.byte	W05
	.byte		N06   , Fs5 
	.byte	W07
	.byte		N05   , En5 
	.byte	W06
	.byte		N06   , Fs5 , v056
	.byte	W06
	.byte		N05   , En5 
	.byte	W06
	.byte		        Fs5 , v060
	.byte	W07
mus_bonus_chance_2_B4:
	.byte		N01   , An4 , v064
	.byte	W01
	.byte		N11
	.byte	W05
	.byte		N05   , Bn4 , v068
	.byte	W06
	.byte		        An4 , v060
	.byte	W06
	.byte		        Bn4 
	.byte	W05
	.byte		        An4 
	.byte	W05
	.byte		        Bn4 
	.byte	W06
	.byte		N04   , An4 
	.byte	W05
	.byte		N06   , Bn4 
	.byte	W07
	.byte		N05   , An4 , v068
	.byte	W05
	.byte		N06   , Bn4 , v056
	.byte	W07
	.byte		N04   , An4 , v064
	.byte	W05
	.byte		N06   , Bn4 , v060
	.byte	W06
	.byte		N05   , An4 , v068
	.byte	W06
	.byte		        Bn4 , v064
	.byte	W06
	.byte		        An4 , v060
	.byte	W05
	.byte		N08   , Bn4 , v056
	.byte	W08
	.byte		N06   , Gn4 , v064
	.byte	W02
	.byte	PEND
mus_bonus_chance_2_B5:
	.byte	W06
	.byte		N06   , An4 , v060
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N05   , Gn4 
	.byte	W06
	.byte		N06   , An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v064
	.byte	W06
	.byte		N06   , An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v064
	.byte	W06
	.byte		        An4 , v056
	.byte	W06
	.byte		N06   , Gn4 , v060
	.byte	W06
	.byte		        An4 , v056
	.byte	W06
	.byte		N05   , Gn4 , v060
	.byte	W06
	.byte		        An4 , v052
	.byte	W06
	.byte		N04   , Gn4 , v060
	.byte	W06
	.byte		N02   , An4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B4
	.byte	PATT
	 .word	mus_bonus_chance_2_B5
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	PATT
	 .word	mus_bonus_chance_2_B3
	.byte	PATT
	 .word	mus_bonus_chance_2_B2
	.byte	GOTO
	 .word	mus_bonus_chance_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_chance_3:  @ 0x0868D32B
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 12
	.byte		VOL   , 108*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , En5 , v060
	.byte	W06
	.byte		        Fs5 , v056
	.byte	W06
	.byte		N05   , En5 , v064
	.byte	W05
	.byte		N06   , Fs5 , v060
	.byte	W07
	.byte		        En5 , v064
	.byte	W06
	.byte		        Fs5 , v060
	.byte	W06
	.byte		N05   , En5 
	.byte	W06
	.byte		N06   , Fs5 
	.byte	W06
	.byte		N05   , En5 
	.byte	W06
	.byte		N06   , Fs5 
	.byte	W06
	.byte		N05   , En5 , v064
	.byte	W05
	.byte		N07   , Fs5 , v060
	.byte	W07
	.byte		N06   , En5 
	.byte	W05
	.byte		        Fs5 , v056
	.byte	W06
	.byte		N05   , Gn5 , v068
	.byte	W06
	.byte		N09   , Gs5 , v072
	.byte	W07
	.byte	W01
	.byte		N17   , An5 , v064
	.byte	W92
	.byte	W03
	.byte	W96
mus_bonus_chance_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_chance_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_chance_4:  @ 0x0868D399
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 60
	.byte		VOL   , 85*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_4_B2:
	.byte		N08   , En5 , v076
	.byte	W06
	.byte		N07   , Cs5 , v072
	.byte	W07
	.byte		N06   , An4 , v060
	.byte	W05
	.byte		N08   , Cs5 , v072
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W13
	.byte		N07   , En5 , v076
	.byte	W05
	.byte		N06   , Cs5 , v072
	.byte	W06
	.byte		N05   , An4 , v056
	.byte	W04
	.byte		N07   , Cs5 , v060
	.byte	W06
	.byte		N04   , En5 , v072
	.byte	W13
	.byte		        Gs5 
	.byte	W02
	.byte		N15   , An5 , v084
	.byte	W22
	.byte		N05   , Dn5 , v064
	.byte	W01
	.byte	PEND
mus_bonus_chance_4_B3:
	.byte	W04
	.byte		N05   , Bn4 , v072
	.byte	W05
	.byte		N06   , Gn4 , v068
	.byte	W07
	.byte		N07   , Bn4 , v064
	.byte	W06
	.byte		N05   , Dn5 , v068
	.byte	W13
	.byte		N06   , Dn5 , v072
	.byte	W05
	.byte		        Bn4 , v080
	.byte	W06
	.byte		N02   , Gn4 , v068
	.byte	W05
	.byte		N06   , Bn4 , v072
	.byte	W05
	.byte		N04   , Dn5 
	.byte	W15
	.byte		        Fs5 
	.byte	W01
	.byte		N16   , Gn5 , v084
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_chance_4_B2
	.byte	PATT
	 .word	mus_bonus_chance_4_B3
	.byte		N14   , En5 , v084
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_chance_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_bonus_chance_5:  @ 0x0868D432
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 58
	.byte		VOL   , 85*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_5_B1:
	.byte	W96
	.byte	W96
	.byte		N04   , Cs3 , v072
	.byte	W18
	.byte		N06   , An2 , v040
	.byte	W03
	.byte		N30   , Cs3 , v076
	.byte	W36
	.byte	W01
	.byte		N05   , Cs3 , v056
	.byte	W12
	.byte		N03   , En3 , v072
	.byte	W11
	.byte		N05   , An3 
	.byte	W13
	.byte		N04   , Gn3 , v080
	.byte	W02
	.byte	W17
	.byte		N03   , Dn3 , v048
	.byte	W04
	.byte		N30   , Bn3 , v084
	.byte	W36
	.byte	W01
	.byte		N05   , Bn3 , v068
	.byte	W13
	.byte		N03   , Gn3 , v072
	.byte	W12
	.byte		N04   , Dn3 , v056
	.byte	W12
	.byte		        An3 , v076
	.byte	W01
	.byte	W18
	.byte		N06   , En3 , v064
	.byte	W04
	.byte		N24   , An3 , v088
	.byte	W36
	.byte		N02   , An3 , v072
	.byte	W12
	.byte		N04   , Cs4 
	.byte	W11
	.byte		        En4 
	.byte	W13
	.byte		N05   , Dn4 , v080
	.byte	W02
	.byte	W15
	.byte		N06   , Bn3 , v072
	.byte	W05
	.byte		N30   , Dn4 , v084
	.byte	W36
	.byte	W03
	.byte		N05   , Dn4 , v072
	.byte	W11
	.byte		        Gn4 , v076
	.byte	W12
	.byte		N04   , Dn4 
	.byte	W13
	.byte		N24   , En4 , v084
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_chance_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_bonus_chance_6:  @ 0x0868D4C4
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 60
	.byte		VOL   , 85*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte		N22   , En2 , v056
	.byte		N22   , Cs3 
	.byte	W36
	.byte		N03   , En2 , v052
	.byte		N02   , Cs3 
	.byte	W12
	.byte		N18   , En2 , v060
	.byte		N19   , Cs3 , v056
	.byte	W36
	.byte		N04   , En2 , v060
	.byte		N06   , Cs3 , v056
	.byte	W12
	.byte		N19   , Gn2 , v060
	.byte		N19   , Dn3 , v064
	.byte	W36
	.byte		N02   , Gn2 , v052
	.byte		N05   , Dn3 , v064
	.byte	W12
	.byte		N20   , Gn2 , v056
	.byte		N21   , Dn3 , v064
	.byte	W36
	.byte		N04   , Bn2 , v068
	.byte		N02   , Dn3 , v060
	.byte	W12
mus_bonus_chance_6_B1:
	.byte		N22   , En2 , v060
	.byte		N22   , Cs3 
	.byte	W36
	.byte		N05   , En2 , v056
	.byte		N05   , Cs3 
	.byte	W12
	.byte		N20   , En2 , v064
	.byte		N21   , Cs3 , v068
	.byte	W36
	.byte		N02   , En2 , v060
	.byte		N05   , Cs3 
	.byte	W12
	.byte		N22   , Gn2 
	.byte		N22   , Dn3 
	.byte	W36
	.byte		N04   , Gn2 , v056
	.byte		N05   , Dn3 , v060
	.byte	W12
	.byte		N20   , Gn2 , v056
	.byte		N21   , Dn3 , v064
	.byte	W36
	.byte		N02   , Bn2 , v068
	.byte		N04   , Dn3 , v056
	.byte	W12
mus_bonus_chance_6_B2:
	.byte		N20   , En2 , v064
	.byte		N21   , Cs3 
	.byte	W60
	.byte		N04   , En2 , v068
	.byte		N05   , Cs3 
	.byte	W12
	.byte		N04   , En2 
	.byte		N05   , Cs3 
	.byte	W12
	.byte		N04   , En2 , v060
	.byte		N06   , Cs3 , v056
	.byte	W12
	.byte	PEND
mus_bonus_chance_6_B3:
	.byte		N20   , Bn2 , v068
	.byte		N19   , Dn3 
	.byte	W60
	.byte		N04   , Bn2 , v064
	.byte		N05   , Dn3 , v060
	.byte	W12
	.byte		N04   , Bn2 , v068
	.byte		N04   , Dn3 , v048
	.byte	W12
	.byte		        Bn2 , v056
	.byte		N04   , Dn3 , v064
	.byte	W12
	.byte	PEND
mus_bonus_chance_6_B4:
	.byte		N16   , En2 , v072
	.byte		N18   , Cs3 
	.byte	W60
	.byte		N04   , En2 , v060
	.byte		N05   , Cs3 , v064
	.byte	W12
	.byte		N04   , En2 
	.byte		N05   , Cs3 , v068
	.byte	W12
	.byte		        En2 , v060
	.byte		N06   , Cs3 , v064
	.byte	W12
	.byte	PEND
mus_bonus_chance_6_B5:
	.byte		N16   , Bn2 , v064
	.byte		N15   , Dn3 , v068
	.byte	W60
	.byte		N04   , Bn2 , v064
	.byte		N05   , Dn3 , v056
	.byte	W12
	.byte		N04   , Bn2 , v068
	.byte		N04   , Dn3 , v064
	.byte	W12
	.byte		        Bn2 , v060
	.byte		N04   , Dn3 
	.byte	W12
	.byte	PEND
	.byte		N15   , En2 , v068
	.byte		N19   , Cs3 
	.byte	W60
	.byte		N03   , En2 , v060
	.byte		N05   , Cs3 , v064
	.byte	W12
	.byte		N04   , En2 , v068
	.byte		N05   , Cs3 , v072
	.byte	W12
	.byte		N04   , En2 , v060
	.byte		N07   , Cs3 , v064
	.byte	W12
	.byte		N19   , Bn2 
	.byte		N16   , Dn3 , v068
	.byte	W60
	.byte		N02   , Bn2 , v056
	.byte		N04   , Dn3 , v060
	.byte	W12
	.byte		N03   , Bn2 , v064
	.byte		N04   , Dn3 
	.byte	W12
	.byte		        Bn2 , v060
	.byte		N02   , Dn3 , v056
	.byte	W12
	.byte		N16   , En2 , v064
	.byte		N20   , Cs3 , v068
	.byte	W60
	.byte		N03   , En2 
	.byte		N05   , Cs3 , v060
	.byte	W12
	.byte		N03   , En2 , v072
	.byte		N04   , Cs3 
	.byte	W12
	.byte		N02   , En2 , v052
	.byte		N06   , Cs3 , v064
	.byte	W12
	.byte		N23   , Bn2 , v068
	.byte		N20   , Dn3 , v064
	.byte	W60
	.byte		N01   , Bn2 , v060
	.byte		N03   , Dn3 , v056
	.byte	W12
	.byte		N02   , Bn2 , v064
	.byte		N03   , Dn3 , v052
	.byte	W12
	.byte		        Bn2 , v044
	.byte		N03   , Dn3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_bonus_chance_6_B4
	.byte	PATT
	 .word	mus_bonus_chance_6_B3
	.byte	PATT
	 .word	mus_bonus_chance_6_B4
	.byte	PATT
	 .word	mus_bonus_chance_6_B5
	.byte		N21   , As2 , v064
	.byte		N21   , Fn3 , v076
	.byte	W60
	.byte		N03   , As2 , v064
	.byte		N05   , Fn3 
	.byte	W12
	.byte		N04   , As2 , v060
	.byte		N04   , Fn3 , v068
	.byte	W12
	.byte		N06   , As2 , v056
	.byte		N05   , Fn3 , v072
	.byte	W12
	.byte		N21   , Cn3 , v068
	.byte		N21   , Gn3 , v080
	.byte	W60
	.byte		N04   , Cn3 , v064
	.byte		N05   , Gn3 , v072
	.byte	W12
	.byte		        Cn3 , v060
	.byte		N04   , Gn3 , v064
	.byte	W12
	.byte		N05   , Cn3 , v060
	.byte		N06   , Gn3 , v068
	.byte	W12
	.byte		N21   , Dn3 
	.byte		N22   , An3 , v076
	.byte	W60
	.byte		N05   , Dn3 , v060
	.byte		N04   , An3 , v072
	.byte	W12
	.byte		N05   , Dn3 , v056
	.byte		N04   , An3 , v068
	.byte	W12
	.byte		N05   , Dn3 , v060
	.byte		N06   , An3 , v068
	.byte	W12
	.byte		N19   , En3 , v064
	.byte		N18   , Bn3 , v080
	.byte	W48
	.byte		N23   , En2 , v076
	.byte		N23   , En3 
	.byte	W48
	.byte	PATT
	 .word	mus_bonus_chance_6_B2
	.byte	PATT
	 .word	mus_bonus_chance_6_B3
	.byte	PATT
	 .word	mus_bonus_chance_6_B4
	.byte	PATT
	 .word	mus_bonus_chance_6_B5
	.byte	PATT
	 .word	mus_bonus_chance_6_B2
	.byte	PATT
	 .word	mus_bonus_chance_6_B3
	.byte	PATT
	 .word	mus_bonus_chance_6_B4
	.byte	PATT
	 .word	mus_bonus_chance_6_B5
	.byte	PATT
	 .word	mus_bonus_chance_6_B2
	.byte	PATT
	 .word	mus_bonus_chance_6_B3
	.byte	GOTO
	 .word	mus_bonus_chance_6_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_bonus_chance_7:  @ 0x0868D6B7
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 67
	.byte		VOL   , 93*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N03   , An2 , v064
	.byte		N03   , En3 , v068
	.byte	W11
	.byte		N05   , An2 , v064
	.byte		N05   , Cs3 , v060
	.byte	W13
	.byte		N24   , En2 , v068
	.byte		N24   , An2 , v064
	.byte	W32
	.byte	W01
	.byte		N04   , En2 , v056
	.byte		N07   , An2 , v060
	.byte	W13
	.byte		N06   , Cs3 , v064
	.byte	W01
	.byte		N04   , An2 , v056
	.byte	W10
	.byte		N06   , Cs3 , v040
	.byte	W01
	.byte		N04   , En3 , v072
	.byte	W13
	.byte		N07   , Bn2 , v068
	.byte		N07   , Dn3 , v060
	.byte	W01
	.byte	W23
	.byte		N52   , Gn2 , v064
	.byte		N48   , Bn2 , v072
	.byte	W72
	.byte		N05   , Cs3 , v064
	.byte	W01
	.byte		N04   , En2 , v060
	.byte	W10
	.byte		N05   , En2 , v052
	.byte		N02   , An2 , v064
	.byte	W13
	.byte		N28   , En2 , v060
	.byte		N28   , Cs3 , v068
	.byte	W32
	.byte	W03
	.byte		N05   , En2 , v048
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N05   , En2 , v056
	.byte	W01
	.byte		N04   , An2 , v060
	.byte	W13
	.byte		N05   , En2 
	.byte		N05   , Cs3 , v068
	.byte	W12
	.byte		N08   , Dn2 
	.byte		N07   , Bn2 
	.byte	W24
	.byte		N32   , Bn1 , v060
	.byte		N32   , Gn2 , v068
	.byte	W44
	.byte	W03
	.byte		N11   , Bn2 , v072
	.byte	W01
	.byte		N10   , Dn2 , v060
	.byte	W24
	.byte		N28   , Cs2 , v064
	.byte		N24   , An2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_chance_7_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 09 ***********************@

mus_bonus_chance_8:  @ 0x0868D767
	.byte	KEYSH , mus_bonus_chance_key+0
	.byte		VOICE , 73
	.byte		VOL   , 85*mus_bonus_chance_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_chance_8_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W22
	.byte		N03   , En3 , v060
	.byte	W06
	.byte		N07   , An3 , v048
	.byte	W05
	.byte		        Cs4 , v064
	.byte	W07
	.byte		        En4 
	.byte	W06
	.byte		N03   , An4 , v080
	.byte	W48
	.byte	W02
	.byte	W22
	.byte		N06   , Gn3 , v064
	.byte	W07
	.byte		N05   , Bn3 , v072
	.byte	W06
	.byte		N07   , Dn4 , v056
	.byte	W06
	.byte		N06   , Gn4 , v076
	.byte	W06
	.byte		N04   , Bn4 , v084
	.byte	W48
	.byte	W01
	.byte	W24
	.byte		N05   , An3 , v060
	.byte	W05
	.byte		        Cs4 , v068
	.byte	W05
	.byte		N08   , En4 , v064
	.byte	W06
	.byte		N07   , An4 , v072
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W48
	.byte	W02
	.byte	W23
	.byte		N07   , Bn3 , v056
	.byte	W07
	.byte		N05   , Dn4 , v072
	.byte	W04
	.byte		N07   , Gn4 , v064
	.byte	W06
	.byte		N06   , Bn4 , v080
	.byte	W05
	.byte		N07   , Dn5 , v072
	.byte	W48
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
	.byte	W23
	.byte		N04   , An3 , v076
	.byte	W12
	.byte		N03   , En3 , v052
	.byte	W12
	.byte		N05   , Cs4 , v072
	.byte	W12
	.byte		N03   , An3 , v068
	.byte	W13
	.byte		N04   , En4 , v076
	.byte	W24
	.byte	W24
	.byte		N02   , Bn3 , v068
	.byte	W12
	.byte		N03   , Gn3 , v056
	.byte	W11
	.byte		N02   , Dn4 , v076
	.byte	W12
	.byte		        Bn3 , v068
	.byte	W12
	.byte		N03   , Gn4 , v084
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		N02   , An3 , v072
	.byte	W12
	.byte		        En3 , v064
	.byte	W11
	.byte		N03   , Cs4 , v068
	.byte	W11
	.byte		N02   , An3 , v060
	.byte	W13
	.byte		N04   , En4 , v084
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		N03   , Bn3 , v072
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W11
	.byte		N02   , Dn4 , v076
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N04   , Gn4 , v084
	.byte	W24
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_chance_8_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_chance:  @ 0x0868D838
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_chance_pri	@ Priority
	.byte	mus_bonus_chance_rev	@ Reverb

	.word	mus_bonus_chance_grp

	.word	mus_bonus_chance_0
	.word	mus_bonus_chance_1
	.word	mus_bonus_chance_2
	.word	mus_bonus_chance_3
	.word	mus_bonus_chance_4
	.word	mus_bonus_chance_5
	.word	mus_bonus_chance_6
	.word	mus_bonus_chance_7
	.word	mus_bonus_chance_8
