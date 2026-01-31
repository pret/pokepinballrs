	.include "sound/MPlayDef.s"

	.equ	mus_unk_6_grp, gUnknown_08532808
	.equ	mus_unk_6_pri, 0
	.equ	mus_unk_6_rev, reverb_set+50
	.equ	mus_unk_6_mvl, 127
	.equ	mus_unk_6_key, 0
	.equ	mus_unk_6_tbs, 1
	.equ	mus_unk_6_exg, 0
	.equ	mus_unk_6_cmp, 1

	.section .rodata
	.global	mus_unk_6
	.align	2

@*********************** Track 01 ***********************@

mus_unk_6_0:  @ 0x0868A5BC
	.byte	KEYSH , mus_unk_6_key+0
	.byte	TEMPO , 120*mus_unk_6_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 85*mus_unk_6_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W24
mus_unk_6_0_B1:
	.byte		N09   , Ds2 , v052
	.byte	W08
	.byte		N07   , Gn2 
	.byte	W08
	.byte		N08   , As2 , v060
	.byte	W08
	.byte		N10   , Dn3 , v052
	.byte	W08
	.byte		N08   , As2 , v056
	.byte	W08
	.byte		N09   , Gn2 , v052
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N07   , Gn2 , v044
	.byte	W08
	.byte		        As2 , v060
	.byte	W08
	.byte		N08   , Dn3 , v048
	.byte	W08
	.byte		        As2 , v052
	.byte	W08
	.byte		        Gn2 , v044
	.byte	W08
	.byte	PEND
mus_unk_6_0_B2:
	.byte		N10   , Ds2 , v056
	.byte	W08
	.byte		N08   , Gn2 , v048
	.byte	W08
	.byte		N07   , As2 , v052
	.byte	W08
	.byte		N08   , Dn3 , v044
	.byte	W08
	.byte		N07   , As2 , v052
	.byte	W08
	.byte		N08   , Gn2 
	.byte	W08
	.byte		N10   , Ds2 , v048
	.byte	W08
	.byte		N08   , Gn2 , v056
	.byte	W08
	.byte		N07   , As2 
	.byte	W08
	.byte		N09   , Dn3 , v048
	.byte	W08
	.byte		N08   , As2 , v052
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte	PEND
mus_unk_6_0_B3:
	.byte		N09   , Ds2 , v056
	.byte	W08
	.byte		N07   , Fn2 , v048
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		N09   , Cn3 , v056
	.byte	W08
	.byte		N07   , An2 
	.byte	W08
	.byte		N08   , Fn2 , v048
	.byte	W08
	.byte		N09   , Ds2 , v052
	.byte	W08
	.byte		N08   , Fn2 , v048
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N09   , An2 
	.byte	W08
	.byte		        Fn2 , v048
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_unk_6_0_B3
mus_unk_6_0_B4:
	.byte		N09   , Dn2 , v056
	.byte	W08
	.byte		        Fn2 , v052
	.byte	W08
	.byte		N07   , An2 , v056
	.byte	W08
	.byte		N09   , Cn3 , v052
	.byte	W08
	.byte		N07   , An2 
	.byte	W08
	.byte		        Fn2 , v048
	.byte	W08
	.byte		N08   , Dn2 , v056
	.byte	W08
	.byte		        Fn2 , v048
	.byte	W08
	.byte		N05   , An2 , v052
	.byte	W08
	.byte		N08   , Cn3 , v056
	.byte	W08
	.byte		N07   , An2 , v048
	.byte	W08
	.byte		N08   , Fn2 , v052
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_unk_6_0_B4
mus_unk_6_0_B5:
	.byte		N09   , Gn1 , v060
	.byte	W08
	.byte		        Dn2 , v064
	.byte	W08
	.byte		N08   , Gn2 , v052
	.byte	W08
	.byte		        As2 , v056
	.byte	W08
	.byte		N09   , Gn2 , v048
	.byte	W08
	.byte		N07   , Dn2 , v056
	.byte	W08
	.byte		N09   , Gn1 
	.byte	W08
	.byte		N08   , Dn2 , v068
	.byte	W08
	.byte		N07   , Gn2 , v056
	.byte	W08
	.byte		N08   , As2 , v060
	.byte	W08
	.byte		N06   , Gn2 , v052
	.byte	W08
	.byte		N08   , Dn2 , v056
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_unk_6_0_B5
mus_unk_6_0_B6:
	.byte		N06   , Cn2 , v052
	.byte	W08
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N07   , Gn2 
	.byte	W08
	.byte		N08   , Cn3 , v056
	.byte	W08
	.byte		N07   , Gn2 , v044
	.byte	W08
	.byte		N06   , Ds2 , v056
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		N08   , Ds2 , v060
	.byte	W08
	.byte		N06   , Gn2 , v052
	.byte	W08
	.byte		N08   , Cn3 , v056
	.byte	W08
	.byte		        Gn2 , v040
	.byte	W08
	.byte		N07   , Ds2 , v060
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_unk_6_0_B6
mus_unk_6_0_B7:
	.byte		N08   , Fn1 , v048
	.byte	W08
	.byte		N07   , Cn2 , v052
	.byte	W08
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		N09   , Ds2 , v060
	.byte	W08
	.byte		N08   , Cn2 , v048
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N09   , Cn2 , v056
	.byte	W08
	.byte		N08   , Ds2 , v060
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		N09   , Ds2 , v060
	.byte	W08
	.byte		N08   , Cn2 , v048
	.byte	W08
	.byte	PEND
mus_unk_6_0_B8:
	.byte		N08   , Fn1 , v052
	.byte	W08
	.byte		N09   , Cn2 , v056
	.byte	W08
	.byte		N08   , Ds2 , v060
	.byte	W08
	.byte		N07   , An2 , v052
	.byte	W08
	.byte		N08   , Ds2 , v056
	.byte	W08
	.byte		        Cn2 , v048
	.byte	W08
	.byte		N07   , Fn1 
	.byte	W08
	.byte		N08   , Cn2 , v056
	.byte	W08
	.byte		        Ds2 , v068
	.byte	W08
	.byte		        An2 , v060
	.byte	W08
	.byte		N07   , Ds2 , v068
	.byte	W08
	.byte		N08   , Cn2 , v052
	.byte	W08
	.byte	PEND
mus_unk_6_0_B9:
	.byte		N08   , As1 , v056
	.byte	W08
	.byte		N05   , Dn2 , v052
	.byte	W08
	.byte		N08   , Fn2 , v048
	.byte	W08
	.byte		N09   , As2 , v064
	.byte	W08
	.byte		N06   , Fn2 , v052
	.byte	W08
	.byte		N08   , Dn2 , v056
	.byte	W08
	.byte		N09   , As1 , v052
	.byte	W08
	.byte		N08   , Dn2 , v048
	.byte	W08
	.byte		N07   , Fn2 
	.byte	W08
	.byte		N08   , As2 , v060
	.byte	W08
	.byte		N07   , Fn2 , v044
	.byte	W08
	.byte		N09   , Dn2 , v056
	.byte	W08
	.byte	PEND
	.byte		        As1 , v048
	.byte	W08
	.byte		N06   , Dn2 
	.byte	W08
	.byte		N08   , Fn2 , v052
	.byte	W08
	.byte		N09   , As2 , v064
	.byte	W08
	.byte		N08   , Fn2 , v044
	.byte	W08
	.byte		N09   , Dn2 , v056
	.byte	W08
	.byte		N08   , As1 
	.byte	W08
	.byte		N07   , Dn2 , v044
	.byte	W08
	.byte		        Fn2 , v052
	.byte	W08
	.byte		N08   , As2 , v064
	.byte	W08
	.byte		N09   , Fn2 , v044
	.byte	W08
	.byte		N05   , Dn2 , v060
	.byte	W08
	.byte	PATT
	 .word	mus_unk_6_0_B1
	.byte	PATT
	 .word	mus_unk_6_0_B2
	.byte	PATT
	 .word	mus_unk_6_0_B3
	.byte	PATT
	 .word	mus_unk_6_0_B3
	.byte	PATT
	 .word	mus_unk_6_0_B4
	.byte	PATT
	 .word	mus_unk_6_0_B4
	.byte	PATT
	 .word	mus_unk_6_0_B5
	.byte	PATT
	 .word	mus_unk_6_0_B5
	.byte	PATT
	 .word	mus_unk_6_0_B6
	.byte	PATT
	 .word	mus_unk_6_0_B6
	.byte	PATT
	 .word	mus_unk_6_0_B7
	.byte	PATT
	 .word	mus_unk_6_0_B8
	.byte	PATT
	 .word	mus_unk_6_0_B9
	.byte	PATT
	 .word	mus_unk_6_0_B9
	.byte	PATT
	 .word	mus_unk_6_0_B9
	.byte	PATT
	 .word	mus_unk_6_0_B9
	.byte	GOTO
	 .word	mus_unk_6_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_unk_6_1:  @ 0x0868A7F2
	.byte	KEYSH , mus_unk_6_key+0
	.byte		VOICE , 73
	.byte		VOL   , 85*mus_unk_6_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		MOD   , 5
	.byte		N08   , As3 , v056
	.byte	W07
	.byte		        Cn4 , v060
	.byte	W07
	.byte		N11   , Cs4 , v064
	.byte	W09
	.byte		TIE   , Dn4 , v076
	.byte	W01
mus_unk_6_1_B1:
	.byte	W96
	.byte	W12
	.byte		EOT   , Dn4 
	.byte	W10
	.byte		N24   , Dn4 , v056
	.byte	W23
	.byte		N28   , Cn4 , v060
	.byte	W24
	.byte		N24   , As3 , v064
	.byte	W24
	.byte	W01
	.byte		N08   , Cn4 
	.byte	W02
	.byte	W15
	.byte		N04   , Fn3 , v060
	.byte	W09
	.byte		TIE   , Fn3 , v068
	.byte	W72
	.byte	W48
	.byte	W03
	.byte		EOT
	.byte	W21
	.byte		N08   , An3 , v056
	.byte	W08
	.byte		        As3 , v064
	.byte	W07
	.byte		N10   , Bn3 , v072
	.byte	W09
	.byte	W01
	.byte		TIE   , Cn4 , v068
	.byte	W92
	.byte	W03
	.byte	W13
	.byte		EOT
	.byte	W10
	.byte		N24   , Cn4 , v060
	.byte	W23
	.byte		        As3 
	.byte	W24
	.byte		        An3 , v072
	.byte	W24
	.byte	W02
	.byte		N07   , As3 , v064
	.byte	W16
	.byte		N02   , Dn3 , v068
	.byte	W08
	.byte		TIE
	.byte	W72
	.byte	W52
	.byte		EOT
	.byte	W20
	.byte		N09   , Gn3 
	.byte	W09
	.byte		N08   , Fs3 , v072
	.byte	W08
	.byte		N10   , Gn3 , v060
	.byte	W07
	.byte		TIE   , As3 , v068
	.byte	W96
	.byte	W56
	.byte		EOT
	.byte	W14
	.byte		N11   , Gn3 
	.byte	W10
	.byte		N09   , An3 , v064
	.byte	W08
	.byte		        As3 , v068
	.byte	W08
	.byte		N48   , Dn4 , v076
	.byte	W48
	.byte		        Cn4 , v064
	.byte	W48
	.byte		N52   , As3 , v068
	.byte	W48
	.byte		N48   , An3 , v064
	.byte	W48
	.byte		TIE   , As3 , v056
	.byte	W96
	.byte	W96
	.byte	W02
	.byte		EOT
	.byte	W92
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W22
	.byte		N10   , Cn4 
	.byte	W09
	.byte		N08   , Cn5 , v064
	.byte	W08
	.byte		N10   , Cn4 , v052
	.byte	W10
	.byte		N07   , Cn5 , v064
	.byte	W44
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N08   , Dn4 , v060
	.byte	W07
	.byte		N09   , Dn5 , v064
	.byte	W09
	.byte		N10   , Dn4 , v068
	.byte	W08
	.byte		N07   , Dn5 
	.byte	W96
	.byte	W22
	.byte		N06   , Ds4 , v060
	.byte	W24
	.byte		N05   , Gn4 , v064
	.byte	W23
	.byte		N06   , Cn5 
	.byte	W24
	.byte	W01
	.byte		N10   , Ds5 , v068
	.byte	W02
	.byte	W96
	.byte	W22
	.byte		N06   , Fn4 , v056
	.byte	W23
	.byte		N05   , An4 , v060
	.byte	W24
	.byte	W02
	.byte		        Cn5 , v064
	.byte	W23
	.byte		N08   , Fn5 
	.byte	W02
	.byte	W96
	.byte	W21
	.byte		        As4 , v060
	.byte	W08
	.byte		N09   , As5 , v068
	.byte	W08
	.byte		N10   , As4 , v064
	.byte	W09
	.byte		N06   , As5 , v068
	.byte	W48
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W68
	.byte	W02
	.byte		N08   , As3 , v056
	.byte	W09
	.byte		        Cn4 , v060
	.byte	W07
	.byte		N11   , Cs4 , v064
	.byte	W09
	.byte		TIE   , Dn4 , v076
	.byte	W01
	.byte	GOTO
	 .word	mus_unk_6_1_B1
	.byte	W96
	.byte	W12
	.byte		EOT   , Dn4 
	.byte	W84
	.byte	FINE

@*********************** Track 03 ***********************@

mus_unk_6_2:  @ 0x0868A903
	.byte	KEYSH , mus_unk_6_key+0
	.byte		VOICE , 8
	.byte		VOL   , 75*mus_unk_6_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W24
mus_unk_6_2_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W68
	.byte	W02
	.byte		N08   , As4 , v056
	.byte	W09
	.byte		        Cn5 , v060
	.byte	W07
	.byte		N11   , Cs5 , v064
	.byte	W09
	.byte		TIE   , Dn5 , v076
	.byte	W01
	.byte	W96
	.byte	W12
	.byte		EOT
	.byte	W10
	.byte		N24   , Dn5 , v056
	.byte	W23
	.byte		N28   , Cn5 , v060
	.byte	W24
	.byte		N24   , As4 , v064
	.byte	W24
	.byte	W01
	.byte		N08   , Cn5 
	.byte	W02
	.byte	W15
	.byte		N04   , Fn4 , v060
	.byte	W09
	.byte		TIE   , Fn4 , v068
	.byte	W72
	.byte	W48
	.byte	W03
	.byte		EOT
	.byte	W21
	.byte		N08   , An4 , v056
	.byte	W08
	.byte		        As4 , v064
	.byte	W07
	.byte		N10   , Bn4 , v072
	.byte	W09
	.byte	W01
	.byte		TIE   , Cn5 , v068
	.byte	W92
	.byte	W03
	.byte	W13
	.byte		EOT
	.byte	W10
	.byte		N24   , Cn5 , v060
	.byte	W23
	.byte		        As4 
	.byte	W24
	.byte		        An4 , v072
	.byte	W24
	.byte	W02
	.byte		N07   , As4 , v064
	.byte	W16
	.byte		N02   , Dn4 , v068
	.byte	W08
	.byte		TIE
	.byte	W72
	.byte	W52
	.byte		EOT
	.byte	W20
	.byte		N09   , Gn4 
	.byte	W09
	.byte		N08   , Fs4 , v072
	.byte	W08
	.byte		N10   , Gn4 , v060
	.byte	W07
	.byte		TIE   , As4 , v068
	.byte	W96
	.byte	W56
	.byte		EOT
	.byte	W14
	.byte		N11   , Gn4 
	.byte	W10
	.byte		N09   , An4 , v064
	.byte	W08
	.byte		        As4 , v068
	.byte	W08
	.byte		N19   , Dn5 , v076
	.byte	W32
	.byte	W02
	.byte		N06   , Ds5 , v068
	.byte	W06
	.byte		N09   , Dn5 , v072
	.byte	W08
	.byte		N19   , Cn5 , v076
	.byte	W32
	.byte	W01
	.byte		N07   , Dn5 , v060
	.byte	W06
	.byte		N09   , Cn5 , v068
	.byte	W07
	.byte		N24   , As4 , v076
	.byte	W02
	.byte	W32
	.byte		N09   , Cn5 , v056
	.byte	W07
	.byte		N08   , As4 , v068
	.byte	W09
	.byte		N05   , An4 , v076
	.byte	W23
	.byte		N04   , Gn4 , v068
	.byte	W11
	.byte		        An4 , v076
	.byte	W13
	.byte		N03   , As4 , v080
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N04   , As5 , v076
	.byte	W48
	.byte	W01
	.byte		N05   , As4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_6_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_unk_6_3:  @ 0x0868A9DC
	.byte	KEYSH , mus_unk_6_key+0
	.byte		VOICE , 71
	.byte		VOL   , 85*mus_unk_6_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		MOD   , 3
	.byte	W24
mus_unk_6_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	.byte		N24   , Dn4 , v060
	.byte	W24
	.byte		        As3 , v056
	.byte	W23
	.byte		        Gn3 , v060
	.byte	W23
	.byte		N92   , Ds3 
	.byte	W04
	.byte	W96
	.byte	W22
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	W01
	.byte		        Fn3 , v056
	.byte	W24
	.byte		N54   , Cn3 , v048
	.byte	W01
	.byte	W48
	.byte	W01
	.byte		N24   , Fn3 , v056
	.byte	W24
	.byte		N20   , An3 , v052
	.byte	W23
	.byte	W24
	.byte		N24   , Cn4 , v060
	.byte	W24
	.byte		        An3 , v056
	.byte	W23
	.byte		        Fn3 , v052
	.byte	W22
	.byte		N80   , Dn3 
	.byte	W03
	.byte	W96
	.byte	W23
	.byte		N24   , As3 , v064
	.byte	W24
	.byte		        Gn3 , v052
	.byte	W24
	.byte		        Dn3 , v060
	.byte	W24
	.byte		N52   , As2 , v064
	.byte	W01
	.byte	W48
	.byte	W01
	.byte		N24   , Dn3 , v056
	.byte	W23
	.byte		N18   , Gn3 
	.byte	W24
	.byte	W24
	.byte		N24   , As3 , v064
	.byte	W23
	.byte		        Gn3 , v056
	.byte	W24
	.byte		        Ds3 , v060
	.byte	W23
	.byte		N52   , Cn3 , v056
	.byte	W02
	.byte	W96
	.byte	W22
	.byte		N24   , Cn4 , v068
	.byte	W24
	.byte	W01
	.byte		        An3 , v064
	.byte	W24
	.byte		        Fn3 , v060
	.byte	W23
	.byte		N48   , Cn3 , v056
	.byte	W02
	.byte	W44
	.byte	W01
	.byte		N24   , Fn3 , v064
	.byte	W24
	.byte	W01
	.byte		N21   , An3 
	.byte	W24
	.byte	W02
	.byte	W22
	.byte		N24   , As3 , v060
	.byte	W24
	.byte	W02
	.byte		        Fn3 , v056
	.byte	W23
	.byte		        Dn3 
	.byte	W23
	.byte		N01   , As2 , v052
	.byte	W02
	.byte		N54   , As2 , v064
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_6_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_unk_6:  @ 0x0868AA8C
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_unk_6_pri	@ Priority
	.byte	mus_unk_6_rev	@ Reverb

	.word	mus_unk_6_grp

	.word	mus_unk_6_0
	.word	mus_unk_6_1
	.word	mus_unk_6_2
	.word	mus_unk_6_3
@ 0x0868AAA4
