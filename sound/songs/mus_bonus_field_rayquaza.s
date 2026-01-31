	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_rayquaza_grp, gUnknown_08532808
	.equ	mus_bonus_field_rayquaza_pri, 0
	.equ	mus_bonus_field_rayquaza_rev, reverb_set+50
	.equ	mus_bonus_field_rayquaza_mvl, 127
	.equ	mus_bonus_field_rayquaza_key, 0
	.equ	mus_bonus_field_rayquaza_tbs, 1
	.equ	mus_bonus_field_rayquaza_exg, 0
	.equ	mus_bonus_field_rayquaza_cmp, 1

	.section .rodata
	.global	mus_bonus_field_rayquaza
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_rayquaza_0:  @ 0x0869A948
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte	TEMPO , 120*mus_bonus_field_rayquaza_tbs/2
	.byte		VOICE , 30
	.byte		VOL   , 85*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		MOD   , 7
	.byte	W96
	.byte	W96
mus_bonus_field_rayquaza_0_B1:
	.byte		N04   , Bn2 , v084
	.byte		N05   , Fs3 , v080
	.byte	W24
	.byte		N14   , Bn2 , v084
	.byte		N16   , Fs3 , v076
	.byte	W12
	.byte		N06   , Cn3 
	.byte		N04   , Gn3 
	.byte	W24
	.byte		N24   , Gn2 , v072
	.byte		N21   , Cn3 , v080
	.byte	W36
	.byte		N05   , Bn2 , v072
	.byte		N07   , Fs3 , v084
	.byte	W24
	.byte		N14   , Bn2 , v068
	.byte		N14   , Fs3 , v080
	.byte	W12
	.byte		N06   , Cn3 , v068
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		N24   , Gn3 , v076
	.byte		N24   , Cn4 , v088
	.byte	W36
	.byte		N05   , Bn2 , v068
	.byte		N06   , Fs3 , v076
	.byte	W24
	.byte		N15   , Bn2 , v060
	.byte		N15   , Fs3 , v072
	.byte	W12
	.byte		N04   , Cn3 , v060
	.byte		N06   , Gn3 , v068
	.byte	W24
	.byte		N24   , Gn2 , v052
	.byte		N24   , Cn3 , v072
	.byte	W36
	.byte		N04   , Bn2 , v076
	.byte		N07   , Fs3 , v084
	.byte	W24
	.byte		N13   , Bn2 , v072
	.byte		N13   , Fs3 , v080
	.byte	W12
	.byte		N06   , Cn3 , v072
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		N24   , Gn3 , v076
	.byte		N24   , Cn4 , v084
	.byte	W36
	.byte		N04   , Dn3 , v080
	.byte		N07   , An3 , v084
	.byte	W24
	.byte		N14   , Dn3 , v076
	.byte		N14   , An3 , v084
	.byte	W12
	.byte		N06   , Ds3 , v076
	.byte		N06   , As3 , v084
	.byte	W24
	.byte		N24   , As2 , v080
	.byte		N24   , Ds3 , v084
	.byte	W36
	.byte		N06   , Dn3 , v076
	.byte		N05   , An3 , v084
	.byte	W24
	.byte		N14   , Dn3 , v072
	.byte		N14   , An3 , v084
	.byte	W12
	.byte		N05   , Ds3 , v076
	.byte		N06   , As3 , v084
	.byte	W24
	.byte		N28   , Gs3 , v080
	.byte		N32   , Cs4 
	.byte	W36
	.byte		N06   , Dn3 , v076
	.byte		N07   , An3 , v084
	.byte	W24
	.byte		N14   , Dn3 , v072
	.byte		N15   , An3 , v084
	.byte	W12
	.byte		N06   , Ds3 , v076
	.byte		N06   , As3 
	.byte	W24
	.byte		N24   , As2 
	.byte		N24   , Ds3 
	.byte	W36
	.byte		N04   , Dn3 
	.byte		N05   , An3 , v080
	.byte	W24
	.byte		N13   , Dn3 , v072
	.byte		N14   , An3 , v084
	.byte	W12
	.byte		N05   , Ds3 , v076
	.byte		N05   , As3 , v080
	.byte	W24
	.byte		N23   , Gs3 , v076
	.byte		N21   , Cs4 , v088
	.byte	W36
	.byte		        Bn3 , v084
	.byte	W18
	.byte		N16   , Fs4 
	.byte	W18
	.byte		N05   , Fn4 
	.byte	W24
	.byte		N24   , Cn5 , v092
	.byte	W36
	.byte		N20   , Bn3 , v080
	.byte	W18
	.byte		N19   , Fs4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W24
	.byte		N24   , Cn4 , v084
	.byte	W36
	.byte		N21   , Bn3 , v080
	.byte	W18
	.byte		N16   , Fs4 , v084
	.byte	W18
	.byte		N13   , Fn4 , v076
	.byte	W12
	.byte		N17   , Cn5 , v084
	.byte	W18
	.byte		N15   , Gn4 , v080
	.byte	W12
	.byte		N05   , Fs4 , v064
	.byte	W06
	.byte		N11   , En4 , v072
	.byte	W12
	.byte		N04   , Ds4 , v060
	.byte	W06
	.byte		N07   , En4 
	.byte	W06
	.byte		N40   , Fs4 , v076
	.byte	W84
	.byte		N18   , An3 
	.byte	W16
	.byte		N19   , Dn4 , v080
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W28
	.byte		N24   , Gn4 , v088
	.byte	W36
	.byte		N18   , An3 , v068
	.byte	W16
	.byte		N19   , Dn4 , v080
	.byte	W16
	.byte		N08   , Fs4 , v076
	.byte	W28
	.byte		N14   , Gn4 , v080
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        Gn4 , v076
	.byte	W12
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		N07   , En4 , v068
	.byte	W06
	.byte		N36   , Ds4 , v080
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N14   , Bn3 , v076
	.byte	W12
	.byte		N12   , Ds4 , v084
	.byte	W12
	.byte		N14   , Fs4 , v076
	.byte	W12
	.byte		N21   , En4 , v084
	.byte	W18
	.byte		N07   , Gn4 
	.byte	W30
	.byte	W12
	.byte		N14   , Ds4 , v080
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N14   , Bn4 
	.byte	W12
	.byte		N19   , Gn4 
	.byte	W18
	.byte		N07   , Cn5 , v088
	.byte	W18
	.byte		N15   , En5 
	.byte	W12
	.byte		TIE   , Ds5 , v092
	.byte	W96
	.byte	W12
	.byte		EOT
	.byte	W84
	.byte		N19   , Bn3 , v080
	.byte	W18
	.byte		N17   , Fs4 , v084
	.byte	W18
	.byte		N10   , Fn4 , v080
	.byte	W24
	.byte		N30   , Cn4 
	.byte	W36
	.byte		N20   , Bn3 , v068
	.byte	W18
	.byte		N19   , Fs4 , v084
	.byte	W18
	.byte		N07   , Fn4 , v080
	.byte	W24
	.byte		N24   , Cn5 , v084
	.byte	W36
	.byte		N15   , Bn4 , v088
	.byte	W12
	.byte		N05   , Fs4 , v072
	.byte	W06
	.byte		N04   , Fn4 
	.byte	W12
	.byte		N05   , Bn3 , v076
	.byte	W30
	.byte		N14   , Fs4 , v080
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N14   , Cn4 , v076
	.byte	W12
	.byte		N18   , En4 
	.byte	W18
	.byte		        Ds4 , v080
	.byte	W18
	.byte		N15   , Cs4 
	.byte	W12
	.byte		N13   , Ds4 , v084
	.byte	W12
	.byte		        Bn3 , v080
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_rayquaza_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_rayquaza_1:  @ 0x0869AB29
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 38
	.byte		VOL   , 85*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		N01   , Fs2 , v056
	.byte	W01
mus_bonus_field_rayquaza_1_B1:
	.byte		N05   , Fs2 , v072
	.byte	W06
	.byte		N06   , Bn2 , v060
	.byte	W06
	.byte		        Fs2 , v068
	.byte	W06
	.byte		N07   , Bn2 , v048
	.byte	W06
	.byte		N06   , Ds3 , v064
	.byte	W06
	.byte		        Bn2 , v056
	.byte	W06
	.byte		N05   , Fs2 , v064
	.byte	W06
	.byte		        Bn2 , v044
	.byte	W06
	.byte		        Gn2 , v064
	.byte	W06
	.byte		N06   , Cn3 , v056
	.byte	W06
	.byte		N05   , Gn2 , v068
	.byte	W06
	.byte		N07   , Cn3 , v056
	.byte	W06
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        Cn3 , v052
	.byte	W06
	.byte		N04   , Gn2 , v064
	.byte	W06
	.byte		N05   , Cn3 , v056
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
mus_bonus_field_rayquaza_1_B2:
	.byte		N05   , An2 , v064
	.byte	W06
	.byte		N06   , Dn3 , v068
	.byte	W06
	.byte		        An2 , v064
	.byte	W06
	.byte		N07   , Dn3 , v052
	.byte	W06
	.byte		N06   , Fs3 , v072
	.byte	W06
	.byte		        Dn3 , v048
	.byte	W06
	.byte		N04   , An2 , v056
	.byte	W06
	.byte		N06   , Dn3 , v052
	.byte	W06
	.byte		N05   , As2 , v068
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W06
	.byte		N06   , As2 , v068
	.byte	W06
	.byte		N07   , Ds3 , v060
	.byte	W06
	.byte		N06   , Gn3 , v068
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		N05   , As2 , v064
	.byte	W06
	.byte		        Ds3 , v056
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B2
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B2
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B2
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B2
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B2
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
mus_bonus_field_rayquaza_1_B3:
	.byte		N06   , An2 , v064
	.byte	W06
	.byte		N05   , Dn3 , v048
	.byte	W06
	.byte		N06   , An2 , v064
	.byte	W06
	.byte		N07   , Dn3 , v056
	.byte	W06
	.byte		N08   , Fs3 , v072
	.byte	W06
	.byte		N05   , Dn3 , v052
	.byte	W06
	.byte		        An2 , v064
	.byte	W06
	.byte		N04   , Dn3 , v056
	.byte	W06
	.byte		N05   , Gn2 
	.byte	W06
	.byte		N06   , Cn3 , v064
	.byte	W06
	.byte		        Gn2 , v060
	.byte	W06
	.byte		N07   , Cn3 , v056
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		N06   , Cn3 , v056
	.byte	W06
	.byte		N05   , Gn2 
	.byte	W06
	.byte		N10   , Cn3 , v052
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B3
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	PATT
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	GOTO
	 .word	mus_bonus_field_rayquaza_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_rayquaza_2:  @ 0x0869AC7B
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 98
	.byte		VOL   , 85*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N05   , Bn1 , v084
	.byte	W48
	.byte		N06
	.byte	W48
	.byte		N04
	.byte	W96
mus_bonus_field_rayquaza_2_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_rayquaza_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_rayquaza_3:  @ 0x0869ACB1
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 47
	.byte		VOL   , 102*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_bonus_field_rayquaza_3_B1:
	.byte		N11   , Bn1 , v072
	.byte	W11
	.byte		        Fs2 , v076
	.byte	W12
	.byte		        Bn1 , v068
	.byte	W11
	.byte		        Fs2 , v076
	.byte	W12
	.byte		        Cn2 , v064
	.byte	W13
	.byte		N09   , Gn2 , v072
	.byte	W11
	.byte		        Cn2 , v064
	.byte	W12
	.byte		N10   , Gn2 , v072
	.byte	W12
	.byte		        Bn1 , v076
	.byte	W02
	.byte	W10
	.byte		N09   , Fs2 , v068
	.byte	W13
	.byte		N11   , Bn1 , v076
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W13
	.byte		        Cn2 
	.byte	W11
	.byte		N09   , Gn2 
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N10   , Gn2 
	.byte	W13
	.byte		        Bn1 , v076
	.byte	W11
	.byte		        Fs2 , v068
	.byte	W13
	.byte		N09   , Bn1 , v072
	.byte	W12
	.byte		N11   , Fs2 , v068
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N10   , Cn2 , v064
	.byte	W11
	.byte		N09   , Gn2 , v068
	.byte	W13
	.byte		N11   , Bn1 , v072
	.byte	W11
	.byte		N08   , Fs2 , v068
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W11
	.byte		N11   , Fs2 , v064
	.byte	W12
	.byte		N10   , Cn2 
	.byte	W13
	.byte		N08   , Gn2 , v068
	.byte	W11
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W13
	.byte		N10   , Dn2 , v080
	.byte	W01
	.byte	W10
	.byte		N08   , An2 , v076
	.byte	W13
	.byte		        Dn2 , v072
	.byte	W11
	.byte		        An2 , v076
	.byte	W12
	.byte		N07   , Ds2 , v080
	.byte	W12
	.byte		N05   , As2 , v076
	.byte	W12
	.byte		N06   , Ds2 , v072
	.byte	W12
	.byte		N05   , As2 , v076
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W02
	.byte	W10
	.byte		N05   , An2 , v072
	.byte	W13
	.byte		N04   , Dn2 , v076
	.byte	W11
	.byte		N05   , An2 
	.byte	W14
	.byte		N04   , Ds2 , v072
	.byte	W11
	.byte		        As2 
	.byte	W12
	.byte		N05   , Ds2 , v064
	.byte	W12
	.byte		N04   , As2 , v072
	.byte	W12
	.byte		N06   , Dn2 , v076
	.byte	W01
	.byte	W12
	.byte		N05   , An2 
	.byte	W11
	.byte		N04   , Dn2 
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		N03   , Ds2 , v080
	.byte	W13
	.byte		N04   , As2 , v076
	.byte	W12
	.byte		        Ds2 , v072
	.byte	W11
	.byte		        As2 
	.byte	W12
	.byte		N03   , Dn2 , v080
	.byte	W01
	.byte	W11
	.byte		N05   , An2 , v072
	.byte	W12
	.byte		N03   , Dn2 , v076
	.byte	W11
	.byte		N04   , An2 , v072
	.byte	W14
	.byte		        Ds2 , v076
	.byte	W11
	.byte		N03   , As2 , v072
	.byte	W11
	.byte		N04   , Ds2 
	.byte	W12
	.byte		        As2 , v076
	.byte	W13
	.byte		        Bn1 , v080
	.byte	W01
	.byte	W11
	.byte		        Fs2 , v068
	.byte	W11
	.byte		        Bn1 , v076
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W13
	.byte		        Cn2 , v080
	.byte	W12
	.byte		        Gn2 , v076
	.byte	W11
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N03   , Gn2 , v076
	.byte	W11
	.byte		        Bn1 , v072
	.byte	W03
	.byte	W10
	.byte		N04   , Fs2 , v076
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N04   , Cn2 
	.byte	W13
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N04   , Cn2 
	.byte	W11
	.byte		N02   , Gn2 , v072
	.byte	W13
	.byte		N04   , Bn1 , v076
	.byte	W01
	.byte	W11
	.byte		        Fs2 , v072
	.byte	W11
	.byte		N05   , Bn1 , v068
	.byte	W12
	.byte		N04   , Fs2 , v072
	.byte	W11
	.byte		        Cn2 , v060
	.byte	W14
	.byte		        Gn2 , v076
	.byte	W12
	.byte		        Cn2 , v072
	.byte	W13
	.byte		        Gn2 , v076
	.byte	W12
	.byte		        Bn1 
	.byte	W11
	.byte		        Fs2 , v072
	.byte	W11
	.byte		        Bn1 , v076
	.byte	W13
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Cn2 , v072
	.byte	W12
	.byte		        Gn2 , v076
	.byte	W11
	.byte		        Cn2 , v068
	.byte	W13
	.byte		N02   , Gn2 , v072
	.byte	W12
	.byte		N04   , Dn2 , v076
	.byte	W01
	.byte	W11
	.byte		        An2 , v068
	.byte	W12
	.byte		        Dn2 , v072
	.byte	W12
	.byte		N03   , An2 , v076
	.byte	W12
	.byte		N04   , Ds2 , v072
	.byte	W12
	.byte		        As2 , v076
	.byte	W13
	.byte		N05   , Ds2 , v068
	.byte	W12
	.byte		N04   , As2 , v076
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 , v068
	.byte	W11
	.byte		        Dn2 , v076
	.byte	W12
	.byte		        An2 
	.byte	W11
	.byte		        Ds2 , v072
	.byte	W12
	.byte		        As2 , v076
	.byte	W13
	.byte		        Ds2 , v064
	.byte	W11
	.byte		N03   , As2 , v072
	.byte	W12
	.byte		N02   , Dn2 , v068
	.byte	W02
	.byte		N11   , Bn1 , v052
	.byte	W11
	.byte		N12   , Fs2 , v064
	.byte	W13
	.byte		N08   , Bn1 , v052
	.byte	W12
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		N11   , Cn2 , v060
	.byte	W12
	.byte		N10   , Gn2 , v064
	.byte	W11
	.byte		        Cn2 , v060
	.byte	W12
	.byte		        Gn2 , v068
	.byte	W13
	.byte		N09   , Dn2 , v060
	.byte	W11
	.byte		N10   , An2 , v076
	.byte	W13
	.byte		N08   , Dn2 , v064
	.byte	W11
	.byte		N09   , An2 , v076
	.byte	W12
	.byte		N11   , Cn2 , v060
	.byte	W13
	.byte		N08   , Gn2 , v064
	.byte	W11
	.byte		N09   , Cn2 , v056
	.byte	W12
	.byte		N10   , Gn2 , v068
	.byte	W12
	.byte		        Bn1 
	.byte	W01
	.byte	W10
	.byte		N09   , Fs2 , v060
	.byte	W13
	.byte		        Bn1 , v064
	.byte	W11
	.byte		N10   , Fs2 , v068
	.byte	W13
	.byte		        Cn2 , v064
	.byte	W12
	.byte		N11   , Gn2 , v068
	.byte	W11
	.byte		N09   , Cn2 , v064
	.byte	W12
	.byte		N10   , Gn2 , v068
	.byte	W12
	.byte		        Dn2 
	.byte	W02
	.byte	W11
	.byte		N08   , An2 , v076
	.byte	W12
	.byte		N09   , Dn2 , v064
	.byte	W12
	.byte		N11   , An2 , v076
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W13
	.byte		N09   , Cn2 , v060
	.byte	W12
	.byte		N10   , Gn2 , v064
	.byte	W11
	.byte		N11   , Bn1 , v072
	.byte	W01
	.byte	W12
	.byte		N10   , Fs2 , v060
	.byte	W11
	.byte		        Bn1 , v064
	.byte	W13
	.byte		        Fs2 
	.byte	W11
	.byte		N11   , Cn2 
	.byte	W13
	.byte		N10   , Gn2 
	.byte	W12
	.byte		N09   , Cn2 , v060
	.byte	W12
	.byte		        Gn2 , v068
	.byte	W12
	.byte		N10   , Bn1 , v076
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W11
	.byte		N09   , Bn1 , v068
	.byte	W12
	.byte		N11   , Fs2 
	.byte	W11
	.byte		N10   , Cn2 , v064
	.byte	W12
	.byte		N09   , Gn2 , v068
	.byte	W12
	.byte		N10   , Cn2 , v064
	.byte	W12
	.byte		N11   , Gn2 , v068
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W02
	.byte	W10
	.byte		N10   , Fs2 , v068
	.byte	W13
	.byte		        Bn1 , v072
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		N09   , Cn2 , v072
	.byte	W11
	.byte		N10   , Gn2 , v064
	.byte	W13
	.byte		N09   , Cn2 
	.byte	W12
	.byte		N10   , Gn2 , v068
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W01
	.byte	W11
	.byte		N12   , Fs2 , v064
	.byte	W11
	.byte		N09   , Bn1 , v068
	.byte	W12
	.byte		N10   , Fs2 , v064
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 , v060
	.byte	W12
	.byte		        Cn2 , v064
	.byte	W12
	.byte		        Gn2 , v068
	.byte	W12
	.byte		N11   , Bn1 , v072
	.byte	W02
	.byte	W11
	.byte		        Fs2 , v064
	.byte	W12
	.byte		N10   , Bn1 , v068
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N11   , Cn2 , v064
	.byte	W13
	.byte		        Gn2 
	.byte	W12
	.byte		N10   , Cn2 
	.byte	W11
	.byte		        Gn2 , v072
	.byte	W13
	.byte		N11   , Bn1 
	.byte	W11
	.byte		        Fs2 , v064
	.byte	W12
	.byte		N09   , Bn1 , v068
	.byte	W11
	.byte		N11   , Fs2 , v064
	.byte	W12
	.byte		N10   , Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W13
	.byte		        Cn2 , v060
	.byte	W12
	.byte		        Gn2 , v068
	.byte	W12
	.byte		        Bn1 , v076
	.byte	W01
	.byte	W10
	.byte		        Fs2 , v064
	.byte	W13
	.byte		N09   , Bn1 , v068
	.byte	W10
	.byte		N10   , Fs2 , v064
	.byte	W12
	.byte		N12   , Cn2 , v068
	.byte	W13
	.byte		N10   , Gn2 
	.byte	W13
	.byte		        Cn2 , v064
	.byte	W11
	.byte		        Gn2 
	.byte	W12
	.byte		N12   , Bn1 , v072
	.byte	W02
	.byte	W11
	.byte		N11   , Fs2 , v060
	.byte	W12
	.byte		N10   , Bn1 , v068
	.byte	W12
	.byte		        Fs2 , v060
	.byte	W12
	.byte		N12   , Cn2 , v064
	.byte	W12
	.byte		N10   , Gn2 , v060
	.byte	W12
	.byte		N11   , Cn2 , v056
	.byte	W12
	.byte		N10   , Gn2 , v064
	.byte	W12
	.byte		N12   , Bn1 , v068
	.byte	W01
	.byte	W11
	.byte		N10   , Fs2 , v060
	.byte	W12
	.byte		N11   , Bn1 , v064
	.byte	W12
	.byte		N10   , Fs2 , v060
	.byte	W11
	.byte		N12   , Cn2 , v064
	.byte	W13
	.byte		N10   , Gn2 , v060
	.byte	W11
	.byte		N11   , Cn2 
	.byte	W13
	.byte		N10   , Gn2 , v068
	.byte	W11
	.byte		N12   , Bn1 , v072
	.byte	W02
	.byte	W11
	.byte		N10   , Fs2 , v060
	.byte	W12
	.byte		N09   , Bn1 , v068
	.byte	W11
	.byte		N10   , Fs2 , v064
	.byte	W11
	.byte		        Cn2 
	.byte	W12
	.byte		N09   , Gn2 , v060
	.byte	W12
	.byte		        Cn2 , v064
	.byte	W12
	.byte		N11   , Gn2 , v068
	.byte	W12
	.byte		        Bn1 , v076
	.byte	W03
	.byte	W09
	.byte		N08   , Fs2 , v060
	.byte	W12
	.byte		N10   , Bn1 , v064
	.byte	W12
	.byte		N11   , Fs2 , v060
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N09   , Gn2 , v060
	.byte	W12
	.byte		N11   , Cn2 
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		        Bn1 , v068
	.byte	W03
	.byte	W09
	.byte		N08   , Fs2 , v060
	.byte	W12
	.byte		N09   , Bn1 , v068
	.byte	W11
	.byte		N11   , Fs2 
	.byte	W13
	.byte		N09   , Cn2 , v060
	.byte	W11
	.byte		N10   , Gn2 
	.byte	W13
	.byte		N12   , Cn2 , v064
	.byte	W12
	.byte		N10   , Gn2 
	.byte	W15
	.byte	GOTO
	 .word	mus_bonus_field_rayquaza_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_rayquaza_4:  @ 0x0869B013
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 14
	.byte		VOL   , 85*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N04   , Bn2 , v084
	.byte	W48
	.byte		N06   , Bn2 , v080
	.byte	W44
	.byte	W03
	.byte		N05   , Bn2 , v084
	.byte	W01
	.byte	W96
mus_bonus_field_rayquaza_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_rayquaza_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_bonus_field_rayquaza_5:  @ 0x0869B04F
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 67
	.byte		VOL   , 85*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
mus_bonus_field_rayquaza_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W10
	.byte		N14   , Fs3 , v076
	.byte	W12
	.byte		N13   , Bn3 
	.byte	W13
	.byte		        Ds4 
	.byte	W11
	.byte		N20   , Cn4 , v080
	.byte	W19
	.byte		N05   , En4 
	.byte	W30
	.byte	W01
	.byte	W11
	.byte		N13   , Fs3 , v072
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N11   , Ds4 , v076
	.byte	W12
	.byte		N19   , En4 
	.byte	W19
	.byte		N05   , Gn4 , v084
	.byte	W18
	.byte		N12   , En4 , v080
	.byte	W12
	.byte	W01
	.byte		N19   , Bn3 
	.byte	W19
	.byte		N17   , Ds4 , v084
	.byte	W16
	.byte		N15   , Fs4 , v080
	.byte	W13
	.byte		N17   , En4 , v084
	.byte	W17
	.byte		N15   , Dn4 , v080
	.byte	W16
	.byte		        Cn4 , v076
	.byte	W13
	.byte		N19   , Bn3 , v080
	.byte	W01
	.byte	W18
	.byte		N16   , Fs3 , v072
	.byte	W15
	.byte		N15   , Bn3 , v076
	.byte	W14
	.byte		N24   , Cn4 
	.byte	W48
	.byte	W01
	.byte		N20   , Bn3 , v092
	.byte	W18
	.byte		N16   , Fs3 , v080
	.byte	W15
	.byte		N06   , Fn3 
	.byte	W24
	.byte	W01
	.byte		N24   , Cn3 , v084
	.byte	W36
	.byte	W02
	.byte		N19   , Bn3 , v080
	.byte	W16
	.byte		N18   , Fs3 
	.byte	W16
	.byte		N07   , Fn3 
	.byte	W24
	.byte	W01
	.byte		N23   , Cn4 , v088
	.byte	W36
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N02   , Bn2 , v064
	.byte		N04   , Fs3 , v076
	.byte	W44
	.byte	W03
	.byte		N05   , Gn3 , v080
	.byte	W01
	.byte		        Cn3 , v068
	.byte	W24
	.byte	W22
	.byte		        Bn2 
	.byte		N06   , Fs3 , v072
	.byte	W44
	.byte	W03
	.byte		N05   , Cn3 , v068
	.byte		N05   , Gn3 , v076
	.byte	W24
	.byte	W03
	.byte	W21
	.byte		        Fs3 , v068
	.byte		N06   , Bn3 , v080
	.byte	W44
	.byte	W03
	.byte		N04   , Gn3 , v072
	.byte		N06   , Cn4 , v076
	.byte	W28
	.byte	W21
	.byte		N05   , Fs3 , v068
	.byte		N06   , Bn3 , v076
	.byte	W44
	.byte	W03
	.byte		        Cn4 , v080
	.byte	W01
	.byte		N04   , Gn3 , v068
	.byte	W24
	.byte	W03
	.byte	GOTO
	 .word	mus_bonus_field_rayquaza_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_bonus_field_rayquaza_6:  @ 0x0869B125
	.byte	KEYSH , mus_bonus_field_rayquaza_key+0
	.byte		VOICE , 12
	.byte		VOL   , 68*mus_bonus_field_rayquaza_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
mus_bonus_field_rayquaza_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N21   , Bn3 , v084
	.byte	W18
	.byte		N16   , Fs4 
	.byte	W18
	.byte		N05   , Fn4 
	.byte	W24
	.byte		N24   , Cn5 , v092
	.byte	W36
	.byte		N20   , Bn3 , v080
	.byte	W18
	.byte		N19   , Fs4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W24
	.byte		N24   , Cn4 , v084
	.byte	W36
	.byte		N21   , Bn3 , v080
	.byte	W18
	.byte		N16   , Fs4 , v084
	.byte	W18
	.byte		N13   , Fn4 , v076
	.byte	W12
	.byte		N17   , Cn5 , v084
	.byte	W18
	.byte		N15   , Gn4 , v080
	.byte	W12
	.byte		N05   , Fs4 , v064
	.byte	W06
	.byte		N11   , En4 , v072
	.byte	W12
	.byte		N04   , Ds4 , v060
	.byte	W06
	.byte		N07   , En4 
	.byte	W06
	.byte		N40   , Fs4 , v076
	.byte	W84
	.byte		N18   , An3 
	.byte	W16
	.byte		N19   , Dn4 , v080
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W28
	.byte		N24   , Gn4 , v088
	.byte	W36
	.byte		N18   , An3 , v068
	.byte	W16
	.byte		N19   , Dn4 , v080
	.byte	W16
	.byte		N08   , Fs4 , v076
	.byte	W28
	.byte		N14   , Gn4 , v080
	.byte	W12
	.byte		        An4 , v084
	.byte	W12
	.byte		        Gn4 , v076
	.byte	W12
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		N07   , En4 , v068
	.byte	W06
	.byte		N36   , Ds4 , v080
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N14   , Bn3 , v076
	.byte	W12
	.byte		N12   , Ds4 , v084
	.byte	W12
	.byte		N14   , Fs4 , v076
	.byte	W12
	.byte		N21   , En4 , v084
	.byte	W18
	.byte		N07   , Gn4 
	.byte	W30
	.byte	W12
	.byte		N14   , Ds4 , v080
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N14   , Bn4 
	.byte	W12
	.byte		N19   , Gn4 
	.byte	W18
	.byte		N07   , Cn5 , v088
	.byte	W18
	.byte		N15   , En5 
	.byte	W12
	.byte		TIE   , Ds5 , v092
	.byte	W96
	.byte	W12
	.byte		EOT
	.byte	W84
	.byte		N19   , Bn3 , v080
	.byte	W18
	.byte		N17   , Fs4 , v084
	.byte	W18
	.byte		N10   , Fn4 , v080
	.byte	W24
	.byte		N30   , Cn4 
	.byte	W36
	.byte		N20   , Bn3 , v068
	.byte	W18
	.byte		N19   , Fs4 , v084
	.byte	W18
	.byte		N07   , Fn4 , v080
	.byte	W24
	.byte		N24   , Cn5 , v084
	.byte	W36
	.byte		N15   , Bn4 , v088
	.byte	W12
	.byte		N05   , Fs4 , v072
	.byte	W06
	.byte		N04   , Fn4 
	.byte	W12
	.byte		N05   , Bn3 , v076
	.byte	W30
	.byte		N14   , Fs4 , v080
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N14   , Cn4 , v076
	.byte	W12
	.byte		N18   , En4 
	.byte	W18
	.byte		        Ds4 , v080
	.byte	W18
	.byte		N15   , Cs4 
	.byte	W12
	.byte		N13   , Ds4 , v084
	.byte	W12
	.byte		        Bn3 , v080
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_rayquaza_6_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_rayquaza:  @ 0x0869B234
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_rayquaza_pri	@ Priority
	.byte	mus_bonus_field_rayquaza_rev	@ Reverb

	.word	mus_bonus_field_rayquaza_grp

	.word	mus_bonus_field_rayquaza_0
	.word	mus_bonus_field_rayquaza_1
	.word	mus_bonus_field_rayquaza_2
	.word	mus_bonus_field_rayquaza_3
	.word	mus_bonus_field_rayquaza_4
	.word	mus_bonus_field_rayquaza_5
	.word	mus_bonus_field_rayquaza_6
@ 0x0869B258
