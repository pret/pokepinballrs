	.include "sound/MPlayDef.s"

	.equ	mus_catch_em_mode_grp, gUnknown_08532808
	.equ	mus_catch_em_mode_pri, 0
	.equ	mus_catch_em_mode_rev, reverb_set+50
	.equ	mus_catch_em_mode_mvl, 127
	.equ	mus_catch_em_mode_key, 0
	.equ	mus_catch_em_mode_tbs, 1
	.equ	mus_catch_em_mode_exg, 0
	.equ	mus_catch_em_mode_cmp, 1

	.section .rodata
	.global	mus_catch_em_mode
	.align	2

@*********************** Track 01 ***********************@

mus_catch_em_mode_0:  @ 0x08692AC4
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte	TEMPO , 144*mus_catch_em_mode_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Cn6 , v068
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N07   , An5 , v076
	.byte	W06
	.byte		N06   , Cn6 
	.byte	W06
	.byte		        Bn5 , v072
	.byte	W06
	.byte		        As5 , v068
	.byte	W06
	.byte		N08   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N08   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N09   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N05   , As5 , v068
	.byte	W06
	.byte		N06   , An5 , v072
	.byte	W06
	.byte		N05   , Gs5 , v068
	.byte	W06
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N07   , Fs5 , v072
	.byte	W06
	.byte		N05   , Fn5 
	.byte	W06
	.byte		N07   , En5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W06
	.byte		        Cs5 , v076
	.byte	W06
	.byte		N05   , Cn5 , v068
	.byte	W06
	.byte		N06   , Bn4 , v072
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N05   , An4 , v076
	.byte	W06
mus_catch_em_mode_0_B1:
	.byte	W12
	.byte		N02   , Cn2 , v056
	.byte		N02   , En2 , v064
	.byte		N02   , Gn2 
	.byte	W24
	.byte		        Cs2 , v052
	.byte		N02   , Fn2 
	.byte		N04   , Gs2 , v068
	.byte	W24
	.byte		N01   , Dn2 , v048
	.byte		N04   , Fs2 , v064
	.byte		N03   , An2 
	.byte	W24
	.byte		N01   , Cs2 , v048
	.byte		N02   , Fn2 , v052
	.byte		N04   , Gs2 , v072
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode_0_B1
mus_catch_em_mode_0_B2:
	.byte	W12
	.byte		N02   , Gn2 , v048
	.byte		N03   , Cn3 , v060
	.byte	W24
	.byte		N02   , Gn2 , v048
	.byte		N03   , Cn3 , v064
	.byte	W24
	.byte		N02   , Gn2 , v052
	.byte		N02   , Cn3 , v060
	.byte	W24
	.byte		        Gn2 , v048
	.byte		N02   , Cn3 , v064
	.byte	W12
	.byte	PEND
mus_catch_em_mode_0_B3:
	.byte	W12
	.byte		N02   , Fn2 , v048
	.byte		N02   , As2 , v064
	.byte	W24
	.byte		        Fn2 , v056
	.byte		N01   , As2 , v060
	.byte	W24
	.byte		N02   , Fn2 , v040
	.byte		N02   , As2 , v060
	.byte	W24
	.byte		        Fn2 , v052
	.byte		N03   , As2 , v064
	.byte	W12
	.byte	PEND
mus_catch_em_mode_0_B4:
	.byte	W12
	.byte		N01   , Gn2 , v052
	.byte		N02   , Cn3 
	.byte	W24
	.byte		        Gn2 , v060
	.byte		N02   , Cn3 
	.byte	W24
	.byte		N01   , Gn2 
	.byte		N04   , Cn3 , v072
	.byte	W24
	.byte		N02   , Gn2 , v052
	.byte		N03   , Cn3 , v060
	.byte	W12
	.byte	PEND
mus_catch_em_mode_0_B5:
	.byte	W12
	.byte		N01   , As2 , v048
	.byte		N03   , Dn3 , v064
	.byte	W24
	.byte		N01   , As2 
	.byte		N04   , Dn3 , v068
	.byte	W24
	.byte		N02   , As2 , v056
	.byte		N04   , Dn3 , v068
	.byte	W24
	.byte		N02   , As2 , v060
	.byte		N02   , Dn3 
	.byte	W12
	.byte	PEND
mus_catch_em_mode_0_B6:
	.byte	W12
	.byte		N02   , Cn2 , v048
	.byte		N01   , En2 , v052
	.byte		N03   , Gn2 , v060
	.byte	W24
	.byte		N02   , Cs2 , v052
	.byte		N02   , Fn2 , v048
	.byte		N03   , Gs2 , v060
	.byte	W24
	.byte		N01   , Dn2 , v064
	.byte		N02   , Fs2 , v060
	.byte		N02   , An2 , v068
	.byte	W24
	.byte		        Cs2 , v052
	.byte		N02   , Fn2 
	.byte		N03   , Gs2 , v064
	.byte	W12
	.byte	PEND
mus_catch_em_mode_0_B7:
	.byte	W12
	.byte		N02   , Cn2 , v060
	.byte		N01   , En2 , v056
	.byte		N01   , Gn2 , v060
	.byte	W24
	.byte		        Cs2 , v056
	.byte		N02   , Fn2 
	.byte		N02   , Gs2 , v060
	.byte	W24
	.byte		N01   , Dn2 
	.byte		N01   , Fs2 
	.byte		N02   , An2 
	.byte	W24
	.byte		        Cs2 , v044
	.byte		N01   , Fn2 , v048
	.byte		N02   , Gs2 , v064
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode_0_B2
	.byte	PATT
	 .word	mus_catch_em_mode_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode_0_B5
	.byte	PATT
	 .word	mus_catch_em_mode_0_B6
	.byte	PATT
	 .word	mus_catch_em_mode_0_B7
	.byte	W12
	.byte		N01   , Gs2 , v056
	.byte		N01   , Bn2 , v064
	.byte	W24
	.byte		        Gs2 , v056
	.byte		N03   , Bn2 , v064
	.byte	W24
	.byte		N01   , Gn2 , v060
	.byte		N02   , Cn3 , v068
	.byte	W24
	.byte		N01   , Gn2 , v056
	.byte		N02   , Cn3 , v064
	.byte	W12
	.byte	W12
	.byte		N01   , En2 , v060
	.byte		N04   , Cs3 , v068
	.byte	W24
	.byte		N01   , En2 , v064
	.byte		N04   , Cs3 , v068
	.byte	W24
	.byte		N01   , Gn2 , v060
	.byte		N02   , Cn3 
	.byte	W24
	.byte		        Gn2 
	.byte		N03   , Cn3 
	.byte	W12
	.byte	W12
	.byte		N01   , Gs2 , v068
	.byte		N01   , Bn2 , v064
	.byte	W24
	.byte		        Gs2 , v068
	.byte		N02   , Bn2 , v072
	.byte	W24
	.byte		        Gn2 , v048
	.byte		N02   , Cn3 , v060
	.byte	W24
	.byte		        Gn2 , v052
	.byte		N02   , Cn3 , v064
	.byte	W12
	.byte	W12
	.byte		        En2 , v060
	.byte		N04   , Cs3 , v072
	.byte	W24
	.byte		N02   , En2 , v064
	.byte		N04   , Cs3 , v068
	.byte	W24
	.byte		N01   , Gn2 , v064
	.byte		N04   , Cn3 , v068
	.byte	W24
	.byte		N01   , Gn2 
	.byte		N03   , Cn3 
	.byte	W12
	.byte	W12
	.byte		N02   , Cn2 , v036
	.byte		N01   , En2 , v056
	.byte		N02   , Gn2 , v064
	.byte	W24
	.byte		N03   , Cs2 , v060
	.byte		N03   , Fn2 , v048
	.byte		N05   , Gs2 , v068
	.byte	W24
	.byte		N01   , Dn2 , v052
	.byte		N01   , Fs2 , v064
	.byte		N02   , An2 , v076
	.byte	W24
	.byte		N01   , Cs2 , v052
	.byte		N01   , Fn2 , v056
	.byte		N03   , Gs2 , v068
	.byte	W12
	.byte	W12
	.byte		N02   , Cn2 , v056
	.byte		N01   , En2 , v064
	.byte		N02   , Gn2 , v072
	.byte	W24
	.byte		N01   , Cs2 , v048
	.byte		N01   , Fn2 , v052
	.byte		N03   , Gs2 , v068
	.byte	W24
	.byte		N01   , Dn2 , v060
	.byte		N01   , Fs2 , v064
	.byte		N01   , An2 
	.byte	W24
	.byte		N02   , Cs2 , v048
	.byte		N02   , Fn2 
	.byte		N03   , Gs2 , v072
	.byte	W12
	.byte	PATT
	 .word	mus_catch_em_mode_0_B2
	.byte	PATT
	 .word	mus_catch_em_mode_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode_0_B5
	.byte	PATT
	 .word	mus_catch_em_mode_0_B6
	.byte	PATT
	 .word	mus_catch_em_mode_0_B7
	.byte	PATT
	 .word	mus_catch_em_mode_0_B2
	.byte	PATT
	 .word	mus_catch_em_mode_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode_0_B5
	.byte	PATT
	 .word	mus_catch_em_mode_0_B6
	.byte	PATT
	 .word	mus_catch_em_mode_0_B7
	.byte	GOTO
	 .word	mus_catch_em_mode_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_catch_em_mode_1:  @ 0x08692D3C
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 47
	.byte		VOL   , 85*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
mus_catch_em_mode_1_B1:
	.byte		N07   , Cn1 , v084
	.byte	W24
	.byte		N08   , Cn1 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		        Cn1 , v080
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode_1_B1
	.byte	PATT
	 .word	mus_catch_em_mode_1_B1
mus_catch_em_mode_1_B2:
	.byte		N04   , Dn1 , v064
	.byte	W24
	.byte		        Dn1 , v068
	.byte	W24
	.byte		        Dn1 , v064
	.byte	W24
	.byte		        Dn1 , v068
	.byte	W24
	.byte	PEND
mus_catch_em_mode_1_B3:
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Cn1 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
mus_catch_em_mode_1_B4:
	.byte		N06   , As0 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        As0 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
mus_catch_em_mode_1_B5:
	.byte		N09   , Cn1 , v084
	.byte	W24
	.byte		N11   , Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N10
	.byte	W24
	.byte	PEND
mus_catch_em_mode_1_B6:
	.byte		N11   , Cn1 , v072
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W24
	.byte		N10   , Cn1 , v064
	.byte	W24
	.byte		N09   , Cn1 , v068
	.byte	W24
	.byte	PEND
	.byte		N11   , Cn1 , v076
	.byte	W24
	.byte		N10   , Cn1 , v068
	.byte	W24
	.byte		        Cn1 , v064
	.byte	W24
	.byte		N12   , Cn1 , v060
	.byte	W24
	.byte		N08   , Dn1 , v076
	.byte	W24
	.byte		N08
	.byte	W24
	.byte		N09   , Dn1 , v072
	.byte	W24
	.byte		N08   , Dn1 , v068
	.byte	W24
	.byte	PATT
	 .word	mus_catch_em_mode_1_B1
	.byte	PATT
	 .word	mus_catch_em_mode_1_B4
	.byte	PATT
	 .word	mus_catch_em_mode_1_B5
	.byte	PATT
	 .word	mus_catch_em_mode_1_B6
	.byte		N05   , En1 , v072
	.byte	W24
	.byte		        En1 , v076
	.byte	W24
	.byte		N04   , Cn1 
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N05   , An1 , v080
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        Cn1 , v076
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        En1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        An1 , v084
	.byte	W24
	.byte		N04   , An1 , v076
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W24
	.byte		        Cn1 , v084
	.byte	W24
	.byte		N04   , Cn1 , v068
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W24
	.byte		N05   , Cn1 , v076
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N05   , Cn1 , v068
	.byte	W24
	.byte		N04   , Cn1 , v076
	.byte	W24
	.byte	PATT
	 .word	mus_catch_em_mode_1_B1
	.byte	PATT
	 .word	mus_catch_em_mode_1_B2
	.byte	PATT
	 .word	mus_catch_em_mode_1_B3
	.byte	PATT
	 .word	mus_catch_em_mode_1_B4
	.byte	PATT
	 .word	mus_catch_em_mode_1_B5
	.byte	PATT
	 .word	mus_catch_em_mode_1_B6
	.byte	PATT
	 .word	mus_catch_em_mode_1_B1
	.byte	PATT
	 .word	mus_catch_em_mode_1_B2
	.byte	PATT
	 .word	mus_catch_em_mode_1_B3
	.byte	PATT
	 .word	mus_catch_em_mode_1_B4
	.byte	PATT
	 .word	mus_catch_em_mode_1_B5
	.byte	PATT
	 .word	mus_catch_em_mode_1_B6
	.byte	GOTO
	 .word	mus_catch_em_mode_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_catch_em_mode_2:  @ 0x08692E60
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 56
	.byte		VOL   , 102*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_catch_em_mode_2_B1:
	.byte	W96
	.byte	W96
	.byte		N19   , Cn4 , v084
	.byte	W18
	.byte		        Dn4 , v080
	.byte	W16
	.byte		N18   , Gn4 , v084
	.byte	W15
	.byte		N08   , Fs4 , v068
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N05   , Dn4 , v064
	.byte	W04
	.byte		N07   , Cn4 , v060
	.byte	W06
	.byte		N08   , En4 , v076
	.byte	W08
	.byte		N05   , Dn4 , v056
	.byte	W04
	.byte		N04   , Cn4 , v060
	.byte	W06
	.byte		N07   , Gn3 , v064
	.byte	W06
	.byte		N30   , As3 , v084
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N20   , Fn3 
	.byte	W18
	.byte		N18   , As3 
	.byte	W18
	.byte		N14   , Fn4 
	.byte	W13
	.byte	W01
	.byte		N06   , En4 , v076
	.byte	W05
	.byte		N07   , Fn4 , v068
	.byte	W06
	.byte		N32   , Gn4 , v084
	.byte	W44
	.byte	W01
	.byte		N15   , Gn4 , v080
	.byte	W13
	.byte		N12   , Fn4 , v084
	.byte	W11
	.byte		N11   , En4 , v076
	.byte	W12
	.byte		N06   , Dn4 , v072
	.byte	W03
	.byte	W01
	.byte		N08   , En4 
	.byte	W07
	.byte		N40   , Fn4 , v088
	.byte	W48
	.byte	W02
	.byte		N15   , Fn4 , v072
	.byte	W13
	.byte		N13   , En4 , v080
	.byte	W11
	.byte		N14   , Dn4 
	.byte	W12
	.byte		N18   , En4 , v084
	.byte	W02
	.byte	W96
	.byte	W96
	.byte		N19   , Cn4 
	.byte	W17
	.byte		N17   , Dn4 
	.byte	W16
	.byte		N16   , Gn4 
	.byte	W13
	.byte		N08   , Fs4 , v076
	.byte	W06
	.byte		N06   , En4 , v052
	.byte	W06
	.byte		N05   , Dn4 , v060
	.byte	W05
	.byte		N06   , Cn4 , v064
	.byte	W06
	.byte		N09   , En4 , v080
	.byte	W07
	.byte		N08   , Dn4 , v056
	.byte	W06
	.byte		N05   , Cn4 , v060
	.byte	W05
	.byte		N07   , Gn3 
	.byte	W06
	.byte		N30   , As3 , v084
	.byte	W03
	.byte	W48
	.byte		N19   , Fn4 , v088
	.byte	W17
	.byte		        En4 , v084
	.byte	W18
	.byte		N15   , Dn4 , v080
	.byte	W13
	.byte	W01
	.byte		N06   , En4 
	.byte	W05
	.byte		N08   , Fn4 , v076
	.byte	W05
	.byte		N36   , Gn4 , v092
	.byte	W48
	.byte		N13   , Gn4 , v088
	.byte	W12
	.byte		N12   , Fn4 , v084
	.byte	W12
	.byte		        En4 , v080
	.byte	W12
	.byte		N05   , Fn4 , v072
	.byte	W01
	.byte	W04
	.byte		N08   , As4 , v080
	.byte	W06
	.byte		N42   , Fn4 
	.byte	W48
	.byte	W02
	.byte		N13   , As4 , v092
	.byte	W12
	.byte		N12   , Cn5 , v084
	.byte	W11
	.byte		N15   , Dn5 
	.byte	W13
	.byte		N23   , Cn5 , v096
	.byte	W96
	.byte	W96
	.byte		N04   , Bn3 , v064
	.byte	W03
	.byte		N06   , As3 
	.byte	W05
	.byte		        Bn3 
	.byte	W06
	.byte		N09   , As3 
	.byte	W08
	.byte		N16   , Bn3 , v072
	.byte	W14
	.byte		N05   , An3 , v068
	.byte	W05
	.byte		N08   , Gs3 , v072
	.byte	W06
	.byte		N36   , Gn3 
	.byte	W48
	.byte	W01
	.byte		N05   , En3 , v068
	.byte	W05
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        En3 , v064
	.byte	W04
	.byte		N07   , Ds3 
	.byte	W07
	.byte		N15   , En3 , v072
	.byte	W13
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N08   , Fs3 , v076
	.byte	W06
	.byte		N30   , Gn3 
	.byte	W44
	.byte	W02
	.byte		N06   , Bn3 
	.byte	W03
	.byte	W03
	.byte		N07   , As3 
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W05
	.byte		N08   , As3 
	.byte	W07
	.byte		N15   , Bn3 
	.byte	W14
	.byte		N06   , An3 
	.byte	W06
	.byte		N07   , Gs3 
	.byte	W06
	.byte		N32   , Gn3 , v076
	.byte	W48
	.byte		N06   , En3 
	.byte	W01
	.byte	W05
	.byte		        Ds3 , v068
	.byte	W06
	.byte		        En3 , v064
	.byte	W04
	.byte		N07   , Ds3 , v072
	.byte	W07
	.byte		N14   , En3 , v064
	.byte	W13
	.byte		N06   , Fn3 , v068
	.byte	W06
	.byte		N07   , Fs3 , v080
	.byte	W06
	.byte		N24   , Gn3 , v076
	.byte	W48
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
	.byte	GOTO
	 .word	mus_catch_em_mode_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_catch_em_mode_3:  @ 0x08692FD0
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 80
	.byte		VOL   , 85*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_catch_em_mode_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	.byte		N04   , Cn3 , v076
	.byte	W36
	.byte	W01
	.byte		N02   , Cn3 , v064
	.byte	W11
	.byte		N04   , Gn3 , v076
	.byte	W24
	.byte	W02
	.byte	W11
	.byte		N03   , Fn3 , v072
	.byte	W12
	.byte		        As2 , v068
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W12
	.byte		N02   , As2 
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W11
	.byte		N05   , Fn3 , v072
	.byte	W13
	.byte		N04   , As2 , v064
	.byte	W13
	.byte	W22
	.byte		N05   , Cn3 
	.byte	W36
	.byte		N03   , Cn3 , v068
	.byte	W13
	.byte		N04   , Gn3 , v076
	.byte	W24
	.byte	W01
	.byte	W11
	.byte		        Fn3 , v072
	.byte	W12
	.byte		N05   , As3 
	.byte	W13
	.byte		N02   , Fn3 , v060
	.byte	W11
	.byte		N05   , As3 , v068
	.byte	W13
	.byte		N02   , Fn3 , v060
	.byte	W12
	.byte		N05   , As2 
	.byte	W11
	.byte		N03   , Fn3 , v068
	.byte	W13
	.byte	W23
	.byte		N04   , Cn3 , v076
	.byte	W72
	.byte	W01
	.byte	W96
	.byte	GOTO
	 .word	mus_catch_em_mode_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_catch_em_mode_4:  @ 0x08693052
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 12
	.byte		VOL   , 94*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Cn6 , v068
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N07   , An5 , v076
	.byte	W06
	.byte		N06   , Cn6 
	.byte	W06
	.byte		        Bn5 , v072
	.byte	W06
	.byte		        As5 , v068
	.byte	W06
	.byte		N08   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N08   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N09   , An5 , v072
	.byte	W06
	.byte		N07   , Cn6 , v076
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N05   , As5 , v068
	.byte	W06
	.byte		N06   , An5 , v072
	.byte	W06
	.byte		N05   , Gs5 , v068
	.byte	W06
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N07   , Fs5 , v072
	.byte	W06
	.byte		N05   , Fn5 
	.byte	W06
	.byte		N07   , En5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W06
	.byte		        Cs5 , v076
	.byte	W06
	.byte		N05   , Cn5 , v068
	.byte	W06
	.byte		N06   , Bn4 , v072
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N05   , An4 , v076
	.byte	W06
mus_catch_em_mode_4_B1:
	.byte	W96
	.byte	W96
	.byte	W44
	.byte	W03
	.byte		N04   , Cn3 , v080
	.byte	W19
	.byte		N05   , Gn2 , v076
	.byte	W18
	.byte		N04   , En3 , v068
	.byte	W12
	.byte	W02
	.byte		N03   , Dn3 , v060
	.byte	W11
	.byte		        As2 , v072
	.byte	W13
	.byte		        Fn2 , v052
	.byte	W11
	.byte		N04   , As2 , v076
	.byte	W12
	.byte		N03   , Dn3 , v072
	.byte	W12
	.byte		N05   , As2 , v076
	.byte	W12
	.byte		N04   , Dn3 
	.byte	W12
	.byte		        Fn3 , v072
	.byte	W11
	.byte	W01
	.byte		N05   , En3 , v064
	.byte	W06
	.byte		        Cn3 , v052
	.byte	W05
	.byte		N06   , En3 , v056
	.byte	W06
	.byte		N07   , Gn3 , v060
	.byte	W06
	.byte		N04   , Cn4 , v076
	.byte	W12
	.byte		        Gn3 
	.byte	W13
	.byte		N05   , En3 , v072
	.byte	W11
	.byte		        Gn3 , v076
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte		N04   , En4 , v076
	.byte	W12
	.byte		N07   , Dn4 , v064
	.byte	W06
	.byte		N06   , As3 
	.byte	W05
	.byte		N07   , Fn3 , v060
	.byte	W06
	.byte		        As3 , v068
	.byte	W07
	.byte		N03   , Dn4 , v064
	.byte	W11
	.byte		N07   , Dn4 , v068
	.byte	W05
	.byte		N06   , As3 , v064
	.byte	W06
	.byte		N07   , Fn3 , v056
	.byte	W06
	.byte		N06   , As3 , v064
	.byte	W06
	.byte		N04   , Dn4 , v072
	.byte	W13
	.byte		        As3 , v076
	.byte	W12
	.byte		N03   , Fn4 , v084
	.byte	W12
	.byte		N04   , En4 
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W44
	.byte	W01
	.byte		N05   , Cn3 , v092
	.byte	W20
	.byte		N03   , Dn3 , v084
	.byte	W15
	.byte		N05   , Gn3 
	.byte	W14
	.byte		N07   , Fn3 
	.byte	W02
	.byte	W04
	.byte		N06   , En3 , v068
	.byte	W06
	.byte		N05   , Dn3 , v064
	.byte	W05
	.byte		N07   , Cn3 
	.byte	W07
	.byte		N08   , En3 , v076
	.byte	W07
	.byte		N07   , Dn3 , v060
	.byte	W05
	.byte		N04   , Cn3 , v064
	.byte	W05
	.byte		N05   , Gn2 , v068
	.byte	W07
	.byte		N04   , As2 , v080
	.byte	W06
	.byte		        Fn2 , v064
	.byte	W03
	.byte		N03   , As2 , v068
	.byte	W05
	.byte		        Fn2 , v056
	.byte	W02
	.byte		N02   , As2 , v068
	.byte	W06
	.byte		        Fn2 , v056
	.byte	W02
	.byte		N03   , As2 
	.byte	W04
	.byte		N02   , Fn2 , v060
	.byte	W12
	.byte		N04   , Fn3 , v080
	.byte	W10
	.byte	W02
	.byte		N02   , En3 , v072
	.byte	W12
	.byte		N03   , Cn3 , v052
	.byte	W11
	.byte		N02   , En3 , v076
	.byte	W12
	.byte		N04   , Gn3 
	.byte	W12
	.byte		N06   , En3 , v072
	.byte	W05
	.byte		N07   , Gn3 , v076
	.byte	W06
	.byte		N04   , Cn4 
	.byte	W13
	.byte		N07   , Gn3 , v072
	.byte	W06
	.byte		N06   , Cn4 , v068
	.byte	W05
	.byte		N04   , En4 , v076
	.byte	W12
	.byte	W44
	.byte	W03
	.byte		        Dn4 , v080
	.byte	W13
	.byte		        Fn4 , v076
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N05   , As4 , v092
	.byte	W12
	.byte		N04   , Cn5 , v084
	.byte	W12
	.byte		N05   , Gn4 , v068
	.byte	W06
	.byte		N03   , En4 , v072
	.byte	W12
	.byte		N06   , Gs4 , v068
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		N02   , Cs4 , v056
	.byte	W12
	.byte		N07   , An4 , v076
	.byte	W06
	.byte		N06   , Fs4 , v068
	.byte	W06
	.byte		N01   , Dn4 , v064
	.byte	W06
	.byte		N04   , Cs4 , v080
	.byte	W12
	.byte		        Gs3 , v072
	.byte	W12
	.byte		        Cn4 , v084
	.byte	W12
	.byte		N05   , Gn3 , v068
	.byte	W06
	.byte		N03   , En3 , v072
	.byte	W12
	.byte		N06   , Gs3 , v068
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		N02   , Cs3 , v056
	.byte	W12
	.byte		N07   , An3 , v076
	.byte	W06
	.byte		N06   , Fs3 , v068
	.byte	W06
	.byte		N01   , Dn3 , v064
	.byte	W06
	.byte		N04   , Cs3 , v080
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W12
	.byte	W12
	.byte		N02   , Gs2 , v044
	.byte	W12
	.byte		        Bn2 , v052
	.byte	W12
	.byte		N03   , En3 , v056
	.byte	W24
	.byte		N04   , Gn2 , v060
	.byte	W12
	.byte		N02   , Cn3 
	.byte	W12
	.byte		        En3 , v052
	.byte	W12
	.byte	W12
	.byte		        An2 , v044
	.byte	W12
	.byte		        Cs3 , v060
	.byte	W12
	.byte		        En3 , v056
	.byte	W24
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N01   , Cn3 , v060
	.byte	W12
	.byte		N02   , En3 
	.byte	W12
	.byte	W12
	.byte		N01   , Gs2 , v064
	.byte	W12
	.byte		        Bn2 , v060
	.byte	W12
	.byte		N04   , En3 , v064
	.byte	W24
	.byte		N02   , Gn2 , v060
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		N04   , En3 , v060
	.byte	W12
	.byte	W11
	.byte		N01   , An2 
	.byte	W12
	.byte		N02   , Cs3 
	.byte	W12
	.byte		N03   , En3 , v064
	.byte	W24
	.byte		N02   , Gn2 , v056
	.byte	W13
	.byte		        Cn3 
	.byte	W11
	.byte		N03   , En3 , v060
	.byte	W13
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        Cn4 , v088
	.byte	W16
	.byte		N05   , Dn4 
	.byte	W17
	.byte		        Gn4 
	.byte	W14
	.byte		N08   , Fs4 , v072
	.byte	W07
	.byte		N06   , En4 , v064
	.byte	W05
	.byte		        Dn4 
	.byte	W06
	.byte		N05   , Cn4 
	.byte	W06
	.byte		N09   , En4 , v076
	.byte	W07
	.byte		N07   , Dn4 , v060
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W06
	.byte		        Gn3 
	.byte	W07
	.byte		N04   , As3 , v076
	.byte	W01
	.byte	W11
	.byte		N07   , Fn3 , v072
	.byte	W06
	.byte		N04   , As3 , v076
	.byte	W12
	.byte		N07   , Fn3 , v072
	.byte	W05
	.byte		N04   , As3 , v080
	.byte	W13
	.byte		        Fn4 , v084
	.byte	W12
	.byte		N03   , As3 , v068
	.byte	W12
	.byte		N04   , Fn3 
	.byte	W12
	.byte		        Fn4 , v076
	.byte	W12
	.byte		N06   , En4 
	.byte	W01
	.byte	W05
	.byte		N07   , Fn4 , v068
	.byte	W07
	.byte		N24   , Gn4 , v080
	.byte	W24
	.byte		N11   , En4 
	.byte	W23
	.byte		N05   , Gn4 , v076
	.byte	W13
	.byte		N04   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N28   , Fn4 , v080
	.byte	W44
	.byte	W03
	.byte		N04   , As4 , v084
	.byte	W12
	.byte		        Fn4 , v076
	.byte	W11
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W02
	.byte	W03
	.byte		        En4 , v060
	.byte	W03
	.byte		        Cn5 , v080
	.byte	W05
	.byte		N02   , En4 , v044
	.byte	W03
	.byte		N03   , Cn5 , v064
	.byte	W03
	.byte		N04   , En4 , v068
	.byte	W78
	.byte	W01
	.byte	W96
	.byte	GOTO
	 .word	mus_catch_em_mode_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_catch_em_mode_5:  @ 0x0869330B
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 6
	.byte		VOL   , 85*mus_catch_em_mode_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_catch_em_mode_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W11
	.byte		N04   , Cn5 , v064
	.byte	W12
	.byte		N05   , Gn4 , v068
	.byte	W13
	.byte		        Cn4 , v064
	.byte	W24
	.byte		        Cn4 , v068
	.byte	W12
	.byte		N04   , Gn4 
	.byte	W12
	.byte		N05   , Cn5 , v076
	.byte	W12
	.byte	W12
	.byte		N03   , As4 
	.byte	W12
	.byte		        Fn4 , v056
	.byte	W11
	.byte		N05   , As3 , v060
	.byte	W24
	.byte		        As3 , v056
	.byte	W13
	.byte		N04   , Fn4 , v060
	.byte	W12
	.byte		        As4 , v072
	.byte	W12
	.byte	W12
	.byte		N05   , Cn5 , v064
	.byte	W12
	.byte		N03   , Gn4 , v068
	.byte	W12
	.byte		N05   , Cn4 , v060
	.byte	W24
	.byte		N05
	.byte	W11
	.byte		        Gn4 , v068
	.byte	W12
	.byte		N04   , Cn5 , v076
	.byte	W13
	.byte	W11
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn4 , v060
	.byte	W12
	.byte		N06   , Dn4 , v064
	.byte	W24
	.byte		N05   , Dn4 , v076
	.byte	W12
	.byte		N04   , Fn4 , v064
	.byte	W11
	.byte		        Dn5 , v072
	.byte	W12
	.byte		N06   , Cn5 , v076
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_catch_em_mode_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_catch_em_mode_6:  @ 0x08693393
	.byte	KEYSH , mus_catch_em_mode_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_catch_em_mode_mvl/mxv
	.byte	W12
	.byte		N03   , Fs1 , v100
	.byte	W06
	.byte		N03
	.byte	W18
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W18
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W12
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
mus_catch_em_mode_6_B1:
	.byte	W12
	.byte		N03   , Fs1 , v100
	.byte	W06
	.byte		N03
	.byte	W18
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W18
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W12
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte	PEND
mus_catch_em_mode_6_B2:
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	PATT
	 .word	mus_catch_em_mode_6_B1
	.byte	GOTO
	 .word	mus_catch_em_mode_6_B2
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_catch_em_mode:  @ 0x0869346C
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_catch_em_mode_pri	@ Priority
	.byte	mus_catch_em_mode_rev	@ Reverb

	.word	mus_catch_em_mode_grp

	.word	mus_catch_em_mode_0
	.word	mus_catch_em_mode_1
	.word	mus_catch_em_mode_2
	.word	mus_catch_em_mode_3
	.word	mus_catch_em_mode_4
	.word	mus_catch_em_mode_5
	.word	mus_catch_em_mode_6
