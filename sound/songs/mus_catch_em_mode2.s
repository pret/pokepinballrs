	.include "sound/MPlayDef.s"

	.equ	mus_catch_em_mode2_grp, gUnknown_08532808
	.equ	mus_catch_em_mode2_pri, 0
	.equ	mus_catch_em_mode2_rev, reverb_set+50
	.equ	mus_catch_em_mode2_mvl, 127
	.equ	mus_catch_em_mode2_key, 0
	.equ	mus_catch_em_mode2_tbs, 1
	.equ	mus_catch_em_mode2_exg, 0
	.equ	mus_catch_em_mode2_cmp, 1

	.section .rodata
	.global	mus_catch_em_mode2
	.align	2

@*********************** Track 01 ***********************@

mus_catch_em_mode2_0:  @ 0x08695290
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte	TEMPO , 144*mus_catch_em_mode2_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_catch_em_mode2_mvl/mxv
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
mus_catch_em_mode2_0_B1:
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
mus_catch_em_mode2_0_B2:
	.byte		N01   , Cn2 , v068
	.byte		N01   , En2 
	.byte		N01   , Gn2 , v064
	.byte	W10
	.byte		N02   , Cn2 , v060
	.byte		N01   , En2 
	.byte		N02   , Gn2 , v064
	.byte	W24
	.byte	W01
	.byte		N01   , Cs2 , v056
	.byte		N03   , Gs2 , v072
	.byte	W01
	.byte		N01   , Fn2 , v060
	.byte	W24
	.byte		        Dn2 , v064
	.byte		N01   , Fs2 
	.byte		N02   , An2 , v076
	.byte	W24
	.byte		N01   , Cs2 , v064
	.byte		N02   , Fn2 , v060
	.byte		N03   , Gs2 , v076
	.byte	W12
	.byte	PEND
mus_catch_em_mode2_0_B3:
	.byte	W12
	.byte		N01   , Gn2 , v064
	.byte		N01   , Cn3 , v060
	.byte	W06
	.byte		        Gn2 , v068
	.byte		N02   , Cn3 , v076
	.byte	W18
	.byte		N01   , Gn2 , v060
	.byte		N02   , Cn3 , v064
	.byte	W24
	.byte		N01   , Gn2 , v060
	.byte		N02   , Cn3 , v064
	.byte	W24
	.byte		N01   , Gn2 , v068
	.byte		N02   , Cn3 
	.byte	W12
	.byte	PEND
mus_catch_em_mode2_0_B4:
	.byte	W12
	.byte		N01   , Fn2 , v056
	.byte		N01   , As2 
	.byte	W06
	.byte		        Fn2 , v068
	.byte		N02   , As2 , v076
	.byte	W18
	.byte		        Fn2 , v060
	.byte		N03   , As2 , v064
	.byte	W24
	.byte		N01   , Fn2 , v052
	.byte		N03   , As2 , v068
	.byte	W24
	.byte		N01   , Fn2 , v064
	.byte		N01   , As2 , v068
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B4
mus_catch_em_mode2_0_B5:
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
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B2
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B5
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B2
	.byte	W12
	.byte		N01   , Fs2 , v056
	.byte		N01   , As2 , v052
	.byte	W06
	.byte		        Fs2 , v072
	.byte		N02   , As2 , v068
	.byte	W18
	.byte		N01   , Fs2 , v076
	.byte		N01   , As2 
	.byte	W24
	.byte		        Fn2 , v056
	.byte		N02   , Cs3 , v076
	.byte	W24
	.byte		        Fn2 , v064
	.byte		N02   , Cs3 , v068
	.byte	W12
	.byte	W12
	.byte		N01   , En2 
	.byte		N01   , Gs2 
	.byte	W06
	.byte		        En2 
	.byte		N02   , Gs2 , v072
	.byte	W18
	.byte		N01   , En2 , v060
	.byte		N02   , Gs2 , v072
	.byte	W24
	.byte		N01   , Ds2 , v060
	.byte		N01   , Bn2 
	.byte	W24
	.byte		        Ds2 , v072
	.byte		N02   , Bn2 
	.byte	W12
	.byte	W12
	.byte		N01   , Ds2 , v060
	.byte		N01   , Fs2 
	.byte	W06
	.byte		N04   , Ds2 , v076
	.byte		N04   , Fs2 
	.byte	W18
	.byte		N01   , Ds2 , v068
	.byte		N02   , Fs2 
	.byte	W24
	.byte		        Dn2 , v056
	.byte		N02   , Fn2 , v060
	.byte	W24
	.byte		N01   , Dn2 , v064
	.byte		N01   , Fn2 , v068
	.byte	W12
	.byte	W12
	.byte		N02   , Cn2 , v060
	.byte		N02   , Fs2 , v072
	.byte	W24
	.byte		        Cn2 , v056
	.byte		N03   , Fs2 , v068
	.byte	W24
	.byte		N02   , Cn2 , v060
	.byte		N03   , Fs2 , v068
	.byte	W24
	.byte		N01   , Cn2 , v060
	.byte		N02   , Fs2 , v072
	.byte	W12
	.byte	W12
	.byte		N01   , Bn1 , v064
	.byte		N02   , Gn2 , v068
	.byte	W24
	.byte		        Bn1 , v064
	.byte		N03   , Gn2 , v068
	.byte	W24
	.byte		N01   , Bn1 , v064
	.byte		N02   , Gn2 , v068
	.byte	W24
	.byte		        Bn1 , v072
	.byte		N03   , Gn2 
	.byte	W12
	.byte	W12
	.byte		N01   , Cn2 
	.byte		N01   , En2 , v064
	.byte		N02   , Gn2 , v076
	.byte	W24
	.byte		N01   , Cs2 , v056
	.byte		N02   , Fn2 
	.byte		N01   , Gs2 , v060
	.byte	W24
	.byte		N02   , Dn2 , v064
	.byte		N03   , Fs2 
	.byte		N01   , An2 , v060
	.byte	W24
	.byte		        Cs2 , v056
	.byte		N01   , Fn2 , v048
	.byte		N01   , Gs2 , v064
	.byte	W12
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B2
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B4
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_0_B4
	.byte	W11
	.byte		N01   , Cn3 , v060
	.byte	W01
	.byte		        Ds2 
	.byte	W05
	.byte		N03   , Ds2 , v076
	.byte		N03   , Cn3 , v068
	.byte	W19
	.byte		N01   , Ds2 
	.byte		N02   , Cn3 , v076
	.byte	W23
	.byte		N04   , Cn3 , v072
	.byte	W01
	.byte		N01   , Ds2 , v068
	.byte	W23
	.byte		N03
	.byte		N02   , Cn3 , v064
	.byte	W13
	.byte	W11
	.byte		N01   , As2 
	.byte	W01
	.byte		        Cs2 , v056
	.byte	W05
	.byte		N02   , Cs2 , v068
	.byte		N04   , As2 , v076
	.byte	W20
	.byte		N02   , Cs2 , v064
	.byte		N03   , As2 , v072
	.byte	W24
	.byte		N02   , Cs2 , v060
	.byte		N02   , As2 , v072
	.byte	W23
	.byte		N01   , As2 , v068
	.byte	W01
	.byte		N02   , Cs2 , v052
	.byte	W11
	.byte	W13
	.byte		N01   , Cn2 , v064
	.byte		N01   , An2 
	.byte	W05
	.byte		N02   , Cn2 , v060
	.byte		N02   , An2 , v076
	.byte	W19
	.byte		        Cn2 , v056
	.byte		N02   , An2 , v072
	.byte	W22
	.byte		        Cn2 , v060
	.byte		N02   , An2 , v072
	.byte	W24
	.byte		        Cn2 , v064
	.byte		N04   , An2 , v072
	.byte	W13
	.byte	W12
	.byte		N01   , Dn2 , v068
	.byte		N01   , Bn2 , v072
	.byte	W06
	.byte		        Dn2 , v068
	.byte		N02   , Bn2 , v076
	.byte	W18
	.byte		N01   , Dn2 , v060
	.byte		N01   , Bn2 , v064
	.byte	W23
	.byte		        Dn2 , v068
	.byte		N03   , Bn2 
	.byte	W24
	.byte		N02   , Dn2 , v064
	.byte		N02   , Bn2 , v068
	.byte	W13
	.byte	W11
	.byte		N01   , Gn2 , v060
	.byte	W01
	.byte		N02   , Cn2 , v048
	.byte		N01   , En2 , v056
	.byte	W24
	.byte		        Cs2 , v052
	.byte		N02   , Fn2 , v060
	.byte		N02   , Gs2 , v064
	.byte	W23
	.byte		N01   , Dn2 
	.byte		N01   , Fs2 , v068
	.byte		N01   , An2 
	.byte	W24
	.byte		        Cs2 , v052
	.byte		N01   , Fn2 , v056
	.byte		N02   , Gs2 , v064
	.byte	W11
	.byte		N04   , En2 , v072
	.byte	W01
	.byte		N02   , Cn2 , v060
	.byte		N02   , Gn2 , v068
	.byte	W01
	.byte	W11
	.byte		        Cn2 
	.byte		N01   , En2 
	.byte		N03   , Gn2 , v072
	.byte	W24
	.byte		N02   , Cs2 , v056
	.byte		N03   , Fn2 , v060
	.byte		N02   , Gs2 , v068
	.byte	W24
	.byte		N01   , Dn2 , v064
	.byte		N01   , Fs2 , v068
	.byte		N01   , An2 
	.byte	W23
	.byte		        Gs2 
	.byte	W01
	.byte		N02   , Cs2 , v056
	.byte		N01   , Fn2 , v052
	.byte	W13
	.byte	W11
	.byte		        Cn2 , v056
	.byte		N01   , En2 
	.byte		N02   , Gn2 , v060
	.byte	W24
	.byte	W01
	.byte		N01   , En2 
	.byte		N04   , Cn3 , v068
	.byte	W01
	.byte		N01   , Gn2 , v056
	.byte	W23
	.byte		N03   , Ds2 
	.byte		N04   , Fs2 , v060
	.byte		N03   , Bn2 
	.byte	W23
	.byte		N02   , Dn2 , v052
	.byte		N02   , Fn2 , v048
	.byte		N01   , As2 , v052
	.byte	W12
	.byte		N03   , Cn2 , v068
	.byte		N04   , En2 , v064
	.byte		N04   , Gn2 , v068
	.byte	W01
	.byte	W11
	.byte		N02   , Cn2 
	.byte		N01   , En2 , v064
	.byte		N04   , Gn2 , v072
	.byte	W24
	.byte		N02   , Cn3 , v068
	.byte	W01
	.byte		N01   , En2 
	.byte		N01   , Gn2 , v060
	.byte	W23
	.byte		        Ds2 , v064
	.byte		N02   , Bn2 
	.byte	W01
	.byte		N01   , Fs2 , v056
	.byte	W23
	.byte		N02   , Dn2 
	.byte		N02   , Fn2 , v060
	.byte		N03   , As2 , v064
	.byte	W13
	.byte	GOTO
	 .word	mus_catch_em_mode2_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_catch_em_mode2_1:  @ 0x08695601
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte		VOICE , 47
	.byte		VOL   , 93*mus_catch_em_mode2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_catch_em_mode2_1_B1:
	.byte		N04   , Cn1 , v064
	.byte	W24
	.byte		N05   , Cn1 , v072
	.byte	W24
	.byte		N04   , Cn1 , v068
	.byte	W24
	.byte		        Cn1 , v064
	.byte	W24
mus_catch_em_mode2_1_B2:
	.byte		N04   , Cn1 , v072
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N05   , Cn1 , v068
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B2
mus_catch_em_mode2_1_B3:
	.byte		N04   , Dn1 , v064
	.byte	W24
	.byte		        Dn1 , v068
	.byte	W24
	.byte		        Dn1 , v064
	.byte	W24
	.byte		        Dn1 , v068
	.byte	W24
	.byte	PEND
mus_catch_em_mode2_1_B4:
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Cn1 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
mus_catch_em_mode2_1_B5:
	.byte		N06   , As0 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        As0 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
mus_catch_em_mode2_1_B6:
	.byte		N09   , Cn1 , v084
	.byte	W24
	.byte		N11   , Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N10
	.byte	W24
	.byte	PEND
mus_catch_em_mode2_1_B7:
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
	.byte		N07   , Cn1 , v084
	.byte	W24
	.byte		N08   , Cn1 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		        Cn1 , v080
	.byte	W24
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B5
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B6
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B7
	.byte		N03   , Ds1 , v076
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte	W01
	.byte		        As1 , v068
	.byte	W23
	.byte		N03   , Cs1 , v076
	.byte	W24
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W24
	.byte		        Gs1 , v076
	.byte	W24
	.byte		        Gs1 , v072
	.byte	W23
	.byte		N03   , Bn1 , v080
	.byte	W24
	.byte		N04   , Bn1 , v076
	.byte	W24
	.byte		        As1 , v080
	.byte	W24
	.byte		        As1 , v072
	.byte	W24
	.byte		        An1 , v076
	.byte	W24
	.byte		N05   , An1 , v072
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        An1 , v068
	.byte	W24
	.byte		N05   , Gn1 , v076
	.byte	W24
	.byte		        Gn1 , v072
	.byte	W24
	.byte		N04   , Gn1 , v068
	.byte	W24
	.byte		N03
	.byte	W24
	.byte		N04   , Cn1 , v080
	.byte	W24
	.byte		N03   , Cn1 , v076
	.byte	W24
	.byte		        Cn1 , v068
	.byte	W24
	.byte		N03
	.byte	W24
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B2
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B2
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B3
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B4
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B5
	.byte		N05   , Gs1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Gs1 , v076
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N04   , Fs1 
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        Fs1 , v068
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Fn1 , v080
	.byte	W24
	.byte		N04   , Fn1 , v076
	.byte	W24
	.byte		N03
	.byte	W24
	.byte		        Fn1 , v072
	.byte	W24
	.byte		N04   , Gn1 , v080
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N03   , Gn1 , v072
	.byte	W24
	.byte		N04   , Gn1 , v076
	.byte	W24
	.byte		N03   , Cn1 , v080
	.byte	W24
	.byte		N02   , Cn1 , v076
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        Cn1 , v080
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		        Cn1 , v076
	.byte	W24
mus_catch_em_mode2_1_B8:
	.byte		N03   , Cn1 , v068
	.byte	W24
	.byte		N11
	.byte	W24
	.byte		N10   , Cn1 , v064
	.byte	W24
	.byte		N09   , Cn1 , v068
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_catch_em_mode2_1_B8
	.byte	GOTO
	 .word	mus_catch_em_mode2_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_catch_em_mode2_2:  @ 0x08695773
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte		VOICE , 56
	.byte		VOL   , 102*mus_catch_em_mode2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_catch_em_mode2_2_B1:
	.byte	W96
	.byte	W96
	.byte		N28   , Cn4 , v100
	.byte	W32
	.byte	W02
	.byte		N04   , Cn4 , v084
	.byte	W24
	.byte		N12   , En4 , v100
	.byte	W13
	.byte		        Dn4 , v088
	.byte	W12
	.byte		        Cn4 , v096
	.byte	W11
	.byte		N03   , Dn4 , v100
	.byte	W02
	.byte	W17
	.byte		N07   , As3 , v092
	.byte	W06
	.byte		N32   , Fn4 , v108
	.byte	W36
	.byte		N13   , Fn4 , v104
	.byte	W11
	.byte		        En4 , v100
	.byte	W13
	.byte		        Dn4 , v092
	.byte	W12
	.byte		N06   , En4 , v088
	.byte	W01
	.byte	W05
	.byte		        Dn4 , v084
	.byte	W05
	.byte		        Cn4 , v080
	.byte	W05
	.byte		N07   , Dn4 , v092
	.byte	W06
	.byte		N32   , En4 , v100
	.byte	W36
	.byte	W02
	.byte		N14   , En4 , v092
	.byte	W13
	.byte		N12   , Fn4 , v104
	.byte	W11
	.byte		N15   , Gn4 
	.byte	W13
	.byte		N05   , Fn4 
	.byte	W17
	.byte		N06   , En4 , v088
	.byte	W06
	.byte		N32   , Dn4 , v104
	.byte	W36
	.byte		N13   , As3 , v100
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn4 , v096
	.byte	W12
	.byte		N22   , En4 , v104
	.byte	W01
	.byte	W96
	.byte	W96
	.byte		N30   , Cn4 , v096
	.byte	W32
	.byte	W03
	.byte		N05
	.byte	W24
	.byte		N13   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N12   , Cn4 , v092
	.byte	W12
	.byte		N06   , Dn4 , v104
	.byte	W01
	.byte	W17
	.byte		N07   , As3 , v076
	.byte	W04
	.byte		N24   , Fn4 , v112
	.byte	W36
	.byte	W01
	.byte		N13   , Fn4 , v100
	.byte	W12
	.byte		        As4 , v104
	.byte	W12
	.byte		N15   , Dn5 , v092
	.byte	W14
	.byte		N48   , Cn5 , v100
	.byte	W56
	.byte	W03
	.byte		N14   , Cn5 , v104
	.byte	W13
	.byte		N13   , Dn5 
	.byte	W11
	.byte		N14   , En5 , v100
	.byte	W12
	.byte		N08   , Dn5 , v088
	.byte	W01
	.byte	W05
	.byte		N07   , As4 
	.byte	W07
	.byte		        Fn4 , v076
	.byte	W05
	.byte		        As4 , v100
	.byte	W06
	.byte		N30   , Dn5 , v104
	.byte	W32
	.byte	W03
	.byte		N14   , Dn5 , v096
	.byte	W13
	.byte		        En5 , v108
	.byte	W12
	.byte		N15   , Fn5 
	.byte	W12
	.byte		N23   , En5 , v104
	.byte	W01
	.byte	W96
	.byte	W96
	.byte		N19   , As3 , v108
	.byte	W18
	.byte		        Fs3 , v100
	.byte	W17
	.byte		N16   , As3 , v096
	.byte	W14
	.byte		N15   , Cs4 
	.byte	W16
	.byte		N18   , Cn4 , v088
	.byte	W17
	.byte		N17   , As3 , v092
	.byte	W14
	.byte	W01
	.byte		        Gs3 , v100
	.byte	W16
	.byte		N18   , En3 
	.byte	W16
	.byte		N16   , Gs3 , v104
	.byte	W15
	.byte		N19   , Bn3 , v096
	.byte	W17
	.byte		        As3 , v100
	.byte	W16
	.byte		N16   , Gs3 , v092
	.byte	W15
	.byte		N18   , Fs3 , v104
	.byte	W18
	.byte		N16   , Bn2 , v096
	.byte	W15
	.byte		N17   , Fs3 
	.byte	W14
	.byte		N48   , Fn3 , v108
	.byte	W48
	.byte	W01
	.byte	W09
	.byte		N15   , Fs3 , v092
	.byte	W14
	.byte		N13   , En3 , v100
	.byte	W12
	.byte		N36   , Dn3 
	.byte	W36
	.byte	W01
	.byte		N12   , En3 
	.byte	W11
	.byte		N13   , Fs3 , v104
	.byte	W13
	.byte		N48   , Gn3 , v108
	.byte	W44
	.byte	W03
	.byte		N24   , An3 , v100
	.byte	W24
	.byte		N23   , Bn3 , v104
	.byte	W23
	.byte		        Cn4 , v108
	.byte	W02
	.byte	W96
	.byte	W96
	.byte		N30
	.byte	W36
	.byte		N20   , Cn4 , v100
	.byte	W22
	.byte		N14   , En4 , v108
	.byte	W13
	.byte		N11   , Dn4 , v104
	.byte	W11
	.byte		N14   , Cn4 , v092
	.byte	W12
	.byte		N07   , Dn4 , v108
	.byte	W02
	.byte	W17
	.byte		N06   , As3 , v088
	.byte	W05
	.byte		N32   , Fn4 , v112
	.byte	W36
	.byte		N14   , Fn4 , v104
	.byte	W12
	.byte		N12   , En4 
	.byte	W11
	.byte		N13   , Dn4 , v100
	.byte	W14
	.byte		N06   , En4 , v084
	.byte	W01
	.byte	W05
	.byte		N07   , Dn4 , v080
	.byte	W06
	.byte		N06   , Cn4 , v084
	.byte	W05
	.byte		N07   , Dn4 , v092
	.byte	W05
	.byte		N32   , En4 , v100
	.byte	W36
	.byte	W01
	.byte		N15   , En4 , v104
	.byte	W13
	.byte		N13   , Fn4 
	.byte	W13
	.byte		N14   , Gn4 , v108
	.byte	W12
	.byte		N18   , Fn4 , v100
	.byte	W16
	.byte		N19   , En4 
	.byte	W17
	.byte		N12   , Dn4 , v092
	.byte	W16
	.byte		N20   , Dn4 , v104
	.byte	W18
	.byte		N16   , En4 , v100
	.byte	W15
	.byte		N13   , Fn4 , v092
	.byte	W14
	.byte		N21   , Ds4 , v100
	.byte	W18
	.byte		N19   , Gs4 , v104
	.byte	W17
	.byte		N15   , As4 , v108
	.byte	W14
	.byte		N19   , Cn5 
	.byte	W17
	.byte		        As4 , v104
	.byte	W16
	.byte		N14   , Gs4 , v108
	.byte	W14
	.byte		N52   , Fs4 , v104
	.byte	W56
	.byte	W02
	.byte		N14   , Fs4 , v100
	.byte	W12
	.byte		N13   , Cs4 , v088
	.byte	W12
	.byte		        Fs4 , v096
	.byte	W14
	.byte		N48   , Fn4 , v116
	.byte	W56
	.byte	W02
	.byte		N14   , Fn4 , v108
	.byte	W13
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		N14   , An3 
	.byte	W12
	.byte		N20   , Bn3 , v104
	.byte	W01
	.byte	W17
	.byte		N15   , Cn4 
	.byte	W14
	.byte		N12   , Dn4 , v100
	.byte	W15
	.byte		N19   , Dn4 , v116
	.byte	W19
	.byte		N17   , En4 , v108
	.byte	W16
	.byte		N15   , Fn4 , v112
	.byte	W14
	.byte		N06   , En4 , v096
	.byte	W01
	.byte	W04
	.byte		N08   , Dn4 , v100
	.byte	W06
	.byte		N24   , Cn4 , v096
	.byte	W84
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_catch_em_mode2_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_catch_em_mode2_3:  @ 0x08695969
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte		VOICE , 12
	.byte		VOL   , 94*mus_catch_em_mode2_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Cn7 , v068
	.byte	W06
	.byte		        Bn6 
	.byte	W06
	.byte		        As6 
	.byte	W06
	.byte		N07   , An6 , v076
	.byte	W06
	.byte		N06   , Cn7 
	.byte	W06
	.byte		        Bn6 , v072
	.byte	W06
	.byte		        As6 , v068
	.byte	W06
	.byte		N08   , An6 , v072
	.byte	W06
	.byte		N07   , Cn7 , v076
	.byte	W06
	.byte		N06   , Bn6 , v064
	.byte	W06
	.byte		        As6 
	.byte	W06
	.byte		N08   , An6 , v072
	.byte	W06
	.byte		N07   , Cn7 , v076
	.byte	W06
	.byte		N06   , Bn6 , v064
	.byte	W06
	.byte		        As6 
	.byte	W06
	.byte		N09   , An6 , v072
	.byte	W06
	.byte		N07   , Cn7 , v076
	.byte	W06
	.byte		N06   , Bn6 , v064
	.byte	W06
	.byte		N05   , As6 , v068
	.byte	W06
	.byte		N06   , An6 , v072
	.byte	W06
	.byte		N05   , Gs6 , v068
	.byte	W06
	.byte		N06   , Gn6 
	.byte	W06
	.byte		N07   , Fs6 , v072
	.byte	W06
	.byte		N05   , Fn6 
	.byte	W06
	.byte		N07   , En6 
	.byte	W06
	.byte		N06   , Ds6 
	.byte	W06
	.byte		        Dn6 , v068
	.byte	W06
	.byte		        Cs6 , v076
	.byte	W06
	.byte		N05   , Cn6 , v068
	.byte	W06
	.byte		N06   , Bn5 , v072
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		N05   , An5 , v076
	.byte	W06
mus_catch_em_mode2_3_B1:
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
	.byte		N21   , Fs3 , v076
	.byte	W19
	.byte		N16   , Ds3 , v080
	.byte	W17
	.byte		N15   , Fs3 , v076
	.byte	W13
	.byte		N07   , As3 
	.byte	W19
	.byte		N06   , As3 , v080
	.byte	W16
	.byte		        As3 , v076
	.byte	W12
	.byte	W01
	.byte		N16   , En3 
	.byte	W17
	.byte		N17   , Cs3 
	.byte	W16
	.byte		N15   , En3 
	.byte	W14
	.byte		N10   , Gs3 , v084
	.byte	W17
	.byte		N08   , Gs3 , v080
	.byte	W17
	.byte		N07   , Gs3 , v076
	.byte	W14
	.byte		N18   , Ds3 , v084
	.byte	W19
	.byte		N09   , Bn2 , v080
	.byte	W14
	.byte		        Ds3 , v076
	.byte	W14
	.byte		N28   , Dn3 , v080
	.byte	W48
	.byte	W01
	.byte	W11
	.byte		N05   , Dn3 , v068
	.byte	W12
	.byte		N01   , En3 , v064
	.byte	W12
	.byte		N04   , Dn3 
	.byte	W12
	.byte		N02   , Fn3 , v076
	.byte	W12
	.byte		N04   , Dn3 , v060
	.byte	W12
	.byte		        Fs3 , v080
	.byte	W12
	.byte		        Dn3 , v076
	.byte	W13
	.byte	W11
	.byte		        Gn2 , v064
	.byte	W13
	.byte		N02   , An2 , v076
	.byte	W10
	.byte		N04   , As2 
	.byte	W13
	.byte		        Bn2 , v080
	.byte	W13
	.byte		N05   , Cn3 , v072
	.byte	W12
	.byte		        Cs3 , v076
	.byte	W11
	.byte		N04   , Dn3 
	.byte	W13
	.byte	W11
	.byte		        Cn3 
	.byte	W12
	.byte		N05   , Dn3 
	.byte	W11
	.byte		N04   , Ds3 
	.byte	W13
	.byte		        En3 
	.byte	W11
	.byte		N05   , Fn3 , v080
	.byte	W12
	.byte		        Fs3 
	.byte	W13
	.byte		N04   , Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W01
	.byte	W23
	.byte		        Cn3 , v076
	.byte	W72
	.byte	W01
	.byte		N06   , Cn4 , v068
	.byte	W05
	.byte		N05   , Gn3 , v060
	.byte	W06
	.byte		N06   , En3 , v056
	.byte	W06
	.byte		N07   , Gn3 , v052
	.byte	W07
	.byte		N02   , Cn4 , v072
	.byte	W12
	.byte		N06   , Cn4 , v060
	.byte	W05
	.byte		N05   , Gn3 , v052
	.byte	W05
	.byte		N07   , En3 , v056
	.byte	W07
	.byte		N06   , Gn3 
	.byte	W05
	.byte		N04   , Cn4 , v072
	.byte	W13
	.byte		        Gn3 , v076
	.byte	W11
	.byte		        Cn4 , v072
	.byte	W12
	.byte		N06   , As3 , v064
	.byte	W02
	.byte	W04
	.byte		N05   , Fn3 
	.byte	W05
	.byte		        As3 , v060
	.byte	W06
	.byte		N07   , Fn3 , v064
	.byte	W07
	.byte		N03   , As3 , v072
	.byte	W14
	.byte		N04   , As3 , v068
	.byte	W05
	.byte		N06   , Fn3 , v064
	.byte	W07
	.byte		N04   , As3 , v072
	.byte	W05
	.byte		N05   , Fn3 , v064
	.byte	W07
	.byte		N04   , As3 , v076
	.byte	W12
	.byte		        Fn3 
	.byte	W11
	.byte		N03   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W01
	.byte	W11
	.byte		N02   , Gn3 , v072
	.byte	W12
	.byte		        En3 , v068
	.byte	W12
	.byte		N04   , Cn3 
	.byte	W11
	.byte		        Gn3 , v072
	.byte	W13
	.byte		N03   , En3 , v068
	.byte	W12
	.byte		N02   , Cn3 , v040
	.byte	W12
	.byte		N03   , Gn2 , v060
	.byte	W13
	.byte	W11
	.byte		N05   , Fn2 , v076
	.byte	W12
	.byte		N03   , As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		N04   , Fn2 , v068
	.byte	W12
	.byte		N03   , As2 , v076
	.byte	W13
	.byte		N04   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W19
	.byte		        Cn3 , v080
	.byte	W17
	.byte		        Ds3 , v072
	.byte	W14
	.byte		        Gs3 , v080
	.byte	W18
	.byte		        Gs3 , v076
	.byte	W17
	.byte		        Gs3 , v072
	.byte	W11
	.byte		N03   , Fs3 , v076
	.byte	W18
	.byte		N04   , Cs3 
	.byte	W16
	.byte		        As2 
	.byte	W15
	.byte		N04
	.byte	W17
	.byte		        Cs3 
	.byte	W17
	.byte		        Fs3 , v080
	.byte	W13
	.byte	W01
	.byte		        Fn3 
	.byte	W18
	.byte		        Cn3 , v076
	.byte	W17
	.byte		        An2 , v080
	.byte	W14
	.byte		N04
	.byte	W18
	.byte		        Cn3 , v076
	.byte	W16
	.byte		        Fn3 , v080
	.byte	W12
	.byte		N05   , Dn3 , v056
	.byte	W05
	.byte		        Bn2 
	.byte	W06
	.byte		N04   , Gn2 , v044
	.byte	W04
	.byte		N07   , Bn2 , v060
	.byte	W07
	.byte		N02   , Dn3 , v056
	.byte	W13
	.byte		N03   , Dn3 , v060
	.byte	W12
	.byte		N01   , Bn2 , v072
	.byte	W12
	.byte		N04   , Gn3 
	.byte	W12
	.byte		N03   , Dn3 , v060
	.byte	W11
	.byte		        Bn3 , v068
	.byte	W14
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N02   , Dn3 , v064
	.byte	W11
	.byte		N03   , Ds3 , v072
	.byte	W12
	.byte		N04   , En3 
	.byte	W12
	.byte		N05   , Fn3 , v068
	.byte	W12
	.byte		N04   , Fs3 , v072
	.byte	W12
	.byte		        Gn3 , v076
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W01
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_catch_em_mode2_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_catch_em_mode2_4:  @ 0x08695CC8
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte		VOICE , 7
	.byte		VOL   , 68*mus_catch_em_mode2_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
mus_catch_em_mode2_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	.byte		N06   , Cn5 , v072
	.byte	W12
	.byte		N02   , Gn4 , v068
	.byte	W11
	.byte		N06   , Cn4 
	.byte	W24
	.byte	W01
	.byte		N05   , Cn4 , v064
	.byte	W11
	.byte		N04   , Gn4 
	.byte	W12
	.byte		        Cn5 , v076
	.byte	W14
	.byte	W10
	.byte		N05   , Cn5 , v072
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W11
	.byte		N06   , Cn4 , v068
	.byte	W24
	.byte	W02
	.byte		N05
	.byte	W12
	.byte		N04   , Gn4 , v072
	.byte	W11
	.byte		        Cn5 , v068
	.byte	W14
	.byte	W96
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
	.byte		N05   , Cn4 , v072
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W24
	.byte	W01
	.byte		        As3 , v076
	.byte	W24
	.byte	W01
	.byte	W24
	.byte		        Cn4 
	.byte	W23
	.byte		        Bn3 
	.byte	W24
	.byte		N05   , As3 
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_catch_em_mode2_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_catch_em_mode2_5:  @ 0x08695D3A
	.byte	KEYSH , mus_catch_em_mode2_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_catch_em_mode2_mvl/mxv
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
mus_catch_em_mode2_5_B1:
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
mus_catch_em_mode2_5_B2:
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	PATT
	 .word	mus_catch_em_mode2_5_B1
	.byte	GOTO
	 .word	mus_catch_em_mode2_5_B2
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_catch_em_mode2:  @ 0x08695E18
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_catch_em_mode2_pri	@ Priority
	.byte	mus_catch_em_mode2_rev	@ Reverb

	.word	mus_catch_em_mode2_grp

	.word	mus_catch_em_mode2_0
	.word	mus_catch_em_mode2_1
	.word	mus_catch_em_mode2_2
	.word	mus_catch_em_mode2_3
	.word	mus_catch_em_mode2_4
	.word	mus_catch_em_mode2_5
