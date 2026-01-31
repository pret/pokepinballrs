	.include "sound/MPlayDef.s"

	.equ	mus_high_score_grp, gUnknown_08532808
	.equ	mus_high_score_pri, 0
	.equ	mus_high_score_rev, reverb_set+50
	.equ	mus_high_score_mvl, 127
	.equ	mus_high_score_key, 0
	.equ	mus_high_score_tbs, 1
	.equ	mus_high_score_exg, 0
	.equ	mus_high_score_cmp, 1

	.section .rodata
	.global	mus_high_score
	.align	2

@*********************** Track 01 ***********************@

mus_high_score_0:  @ 0x0868B0C8
	.byte	KEYSH , mus_high_score_key+0
	.byte	TEMPO , 120*mus_high_score_tbs/2
	.byte		VOICE , 60
	.byte		VOL   , 85*mus_high_score_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N03   , Cn2 , v076
	.byte		N04   , Gs2 , v080
	.byte	W18
	.byte		N03   , Cn2 , v060
	.byte		N04   , Gs2 , v064
	.byte	W07
	.byte		N24   , Cn2 , v056
	.byte		N32   , Gs2 , v076
	.byte	W32
	.byte	W03
	.byte		N14   , Ds2 , v064
	.byte	W12
	.byte		N11   , Gs2 , v072
	.byte	W12
	.byte		N14   , Cn3 , v076
	.byte	W12
	.byte		N06   , Fs2 , v072
	.byte		N06   , Cs3 , v080
	.byte	W18
	.byte		N02   , Fs2 , v064
	.byte		N03   , Cs3 , v076
	.byte	W06
	.byte		N24   , Fs2 , v072
	.byte		N32   , Cs3 , v080
	.byte	W36
	.byte		N12   , As2 , v072
	.byte	W12
	.byte		        Cs3 , v076
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N04   , An2 , v072
	.byte		N06   , Dn3 , v076
	.byte	W18
	.byte		N03   , An2 , v060
	.byte		N05   , Dn3 , v056
	.byte	W06
	.byte		N06   , An2 , v064
	.byte		N08   , Dn3 , v076
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N09   , Fs3 , v072
	.byte	W08
	.byte		N06   , En3 , v076
	.byte	W01
	.byte		N05   , Bn2 , v072
	.byte	W16
	.byte		N01   , Bn2 , v056
	.byte		N02   , En3 , v068
	.byte	W06
	.byte		N09   , En3 , v072
	.byte	W01
	.byte		N08   , Bn2 , v056
	.byte	W08
	.byte		N07   , Fs3 , v072
	.byte	W07
	.byte		N10   , Gn3 
	.byte	W09
	.byte		N04   , Cn3 
	.byte		N06   , Gs3 , v088
	.byte	W24
	.byte		        Gs2 
	.byte	W19
	.byte		N03   , Gs2 , v080
	.byte	W06
	.byte		N28   , Gs2 , v084
	.byte	W44
	.byte	W03
mus_high_score_0_B1:
	.byte	W24
	.byte		N02   , Gs2 , v064
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W08
	.byte		        Fn3 , v060
	.byte	W08
	.byte		N24   , Gs3 , v068
	.byte	W48
	.byte	W24
	.byte		N02   , Gs2 
	.byte	W08
	.byte		N01   , Cn3 , v056
	.byte	W08
	.byte		        Ds3 , v064
	.byte	W08
	.byte		N28   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N03   , Gs2 , v072
	.byte	W08
	.byte		N02   , Cs3 , v068
	.byte	W08
	.byte		N04   , Fn3 , v072
	.byte	W08
	.byte		N36   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N02   , Gs2 , v068
	.byte	W08
	.byte		N01   , Cn3 , v060
	.byte	W08
	.byte		N03   , Ds3 , v068
	.byte	W08
	.byte		N36   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N02   , Gs2 , v072
	.byte	W08
	.byte		N01   , Cs3 , v064
	.byte	W08
	.byte		N02   , Fn3 , v068
	.byte	W08
	.byte		N36   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N02   , Gs2 , v068
	.byte	W08
	.byte		N01   , Cn3 , v052
	.byte	W08
	.byte		N02   , Ds3 , v060
	.byte	W08
	.byte		N42   , Gs3 , v080
	.byte	W48
	.byte	W24
	.byte		N01   , Fs2 , v064
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cs3 , v056
	.byte	W08
	.byte		N42   , Fs3 , v076
	.byte	W48
	.byte	W24
	.byte		N03   , Fs2 , v068
	.byte	W08
	.byte		N01   , An2 
	.byte	W08
	.byte		N04   , Cs3 , v064
	.byte	W08
	.byte		N48   , Fs3 , v072
	.byte	W48
mus_high_score_0_B2:
	.byte	W24
	.byte		N02   , Gs2 , v068
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N03   , Ds3 
	.byte	W08
	.byte		N48   , Gs3 , v076
	.byte	W48
	.byte	PEND
mus_high_score_0_B3:
	.byte	W24
	.byte		N03   , Gs2 , v064
	.byte	W08
	.byte		N01   , Cn3 , v060
	.byte	W08
	.byte		N04   , Ds3 , v068
	.byte	W08
	.byte		N36   , Gs3 , v072
	.byte	W48
	.byte	PEND
mus_high_score_0_B4:
	.byte	W22
	.byte		N04   , Gs2 , v068
	.byte	W08
	.byte		N03   , Cs3 , v064
	.byte	W07
	.byte		N04   , Fn3 , v068
	.byte	W08
	.byte		N44   , Gs3 , v072
	.byte	W48
	.byte	W03
	.byte	PEND
mus_high_score_0_B5:
	.byte	W23
	.byte		N04   , Fs2 , v068
	.byte	W08
	.byte		N01   , Bn2 , v056
	.byte	W07
	.byte		N04   , Ds3 , v068
	.byte	W09
	.byte		N42   , Fs3 , v076
	.byte	W48
	.byte	W01
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_0_B4
	.byte	PATT
	 .word	mus_high_score_0_B5
	.byte	W22
	.byte		N04   , An2 , v068
	.byte	W08
	.byte		N03   , Dn3 , v064
	.byte	W07
	.byte		N04   , Fs3 , v068
	.byte	W08
	.byte		N44   , An3 , v072
	.byte	W48
	.byte	W03
	.byte	W22
	.byte		N04   , Bn2 , v068
	.byte	W08
	.byte		N03   , En3 , v064
	.byte	W07
	.byte		N04   , Gs3 , v068
	.byte	W08
	.byte		N44   , Bn3 , v072
	.byte	W48
	.byte	W03
	.byte	PATT
	 .word	mus_high_score_0_B2
	.byte	PATT
	 .word	mus_high_score_0_B3
	.byte	W24
	.byte		N03   , Gs2 , v060
	.byte	W08
	.byte		N01   , Cs3 , v064
	.byte	W08
	.byte		N02   , Fn3 , v068
	.byte	W08
	.byte		N44   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N04   , Gs2 , v068
	.byte	W08
	.byte		N01   , Cs3 , v060
	.byte	W08
	.byte		N03   , Fn3 , v068
	.byte	W08
	.byte		N48   , Gs3 , v072
	.byte	W48
	.byte	W24
	.byte		N03   , As2 , v064
	.byte	W08
	.byte		N01   , Cs3 , v056
	.byte	W08
	.byte		N03   , Fs3 , v068
	.byte	W08
	.byte		N48   , As3 , v072
	.byte	W48
	.byte	W24
	.byte		N01   , An2 , v068
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Fs3 , v076
	.byte	W08
	.byte		N44   , An3 
	.byte	W48
	.byte	W24
	.byte		N04   , Gs2 , v064
	.byte	W08
	.byte		N01   , Cs3 , v060
	.byte	W08
	.byte		N04   , Fn3 , v068
	.byte	W08
	.byte		N48   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N03   , As2 , v064
	.byte	W08
	.byte		N01   , Ds3 , v056
	.byte	W08
	.byte		N02   , Gn3 , v052
	.byte	W08
	.byte		N52   , As3 , v076
	.byte	W48
	.byte	W24
	.byte		N04   , Gs2 , v064
	.byte	W08
	.byte		N01   , Cs3 
	.byte	W08
	.byte		N02   , Ds3 
	.byte	W08
	.byte		N48   , Gs3 , v076
	.byte	W48
	.byte	W24
	.byte		N04   , Gs2 , v068
	.byte	W08
	.byte		N01   , Cn3 , v060
	.byte	W08
	.byte		N05   , Ds3 , v068
	.byte	W08
	.byte		N36   , Gs3 , v076
	.byte	W48
	.byte	GOTO
	 .word	mus_high_score_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_high_score_1:  @ 0x0868B2E8
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 61
	.byte		VOL   , 85*mus_high_score_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Gs1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Gs1 , v064
	.byte	W07
	.byte		N02   , Gs1 , v076
	.byte	W06
	.byte		N05   , Gs1 , v080
	.byte	W36
	.byte		N06   , Fs1 , v088
	.byte	W48
	.byte		N01   , Fs1 , v076
	.byte	W06
	.byte		N03   , Fs1 , v080
	.byte	W06
	.byte		N04   , Fs1 , v088
	.byte	W36
	.byte		N06   , Dn1 , v092
	.byte	W24
	.byte		N03   , Dn1 , v084
	.byte	W08
	.byte		N04   , Dn1 , v076
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N06   , En1 , v084
	.byte	W24
	.byte		N03   , En1 , v080
	.byte	W07
	.byte		        En1 , v076
	.byte	W08
	.byte		N04   , En1 , v068
	.byte	W09
	.byte		        Gs1 , v084
	.byte	W23
	.byte		N03   , Gs1 , v076
	.byte	W08
	.byte		N03
	.byte	W07
	.byte		N03
	.byte	W10
	.byte		N21   , Gs1 , v084
	.byte	W24
	.byte	W01
	.byte		N08   , Gs1 , v076
	.byte	W08
	.byte		N07   , As1 
	.byte	W07
	.byte		N09   , Cn2 , v080
	.byte	W08
mus_high_score_1_B1:
	.byte		N04   , Cs2 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Cs2 , v064
	.byte	W07
	.byte		N02   , Cs2 , v076
	.byte	W06
	.byte		N05   , Cs2 , v080
	.byte	W36
	.byte	PEND
mus_high_score_1_B2:
	.byte		N04   , Gs1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Gs1 , v064
	.byte	W07
	.byte		N02   , Gs1 , v076
	.byte	W06
	.byte		N05   , Gs1 , v080
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_1_B1
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B1
	.byte	PATT
	 .word	mus_high_score_1_B2
mus_high_score_1_B3:
	.byte		N04   , Fs1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Fs1 , v064
	.byte	W07
	.byte		N02   , Fs1 , v076
	.byte	W06
	.byte		N05   , Fs1 , v080
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_1_B3
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B1
mus_high_score_1_B4:
	.byte		N04   , Bn1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Bn1 , v064
	.byte	W07
	.byte		N02   , Bn1 , v076
	.byte	W06
	.byte		N05   , Bn1 , v080
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_1_B1
	.byte	PATT
	 .word	mus_high_score_1_B4
	.byte		N04   , Dn1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Dn1 , v064
	.byte	W07
	.byte		N02   , Dn1 , v076
	.byte	W06
	.byte		N05   , Dn1 , v080
	.byte	W36
	.byte		N04   , En1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , En1 , v064
	.byte	W07
	.byte		N02   , En1 , v076
	.byte	W06
	.byte		N05   , En1 , v080
	.byte	W36
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B1
	.byte	PATT
	 .word	mus_high_score_1_B4
	.byte		N04   , As1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , As1 , v064
	.byte	W07
	.byte		N02   , As1 , v076
	.byte	W06
	.byte		N05   , As1 , v080
	.byte	W36
	.byte		N04   , An1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , An1 , v064
	.byte	W07
	.byte		N02   , An1 , v076
	.byte	W06
	.byte		N05   , An1 , v080
	.byte	W36
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte		N04   , Gn1 , v084
	.byte	W44
	.byte	W03
	.byte		N01   , Gn1 , v064
	.byte	W07
	.byte		N02   , Gn1 , v076
	.byte	W06
	.byte		N05   , Gn1 , v080
	.byte	W36
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	PATT
	 .word	mus_high_score_1_B2
	.byte	GOTO
	 .word	mus_high_score_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_high_score_2:  @ 0x0868B445
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 56
	.byte		VOL   , 85*mus_high_score_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N03   , Gs3 , v088
	.byte	W17
	.byte		        Gs3 , v080
	.byte	W07
	.byte		N24   , Gs3 , v088
	.byte	W36
	.byte		N12   , Ds3 , v072
	.byte	W12
	.byte		N11   , Gs3 , v076
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N05   , Cs4 , v084
	.byte	W18
	.byte		N04   , Cs4 , v076
	.byte	W06
	.byte		N28   , Cs4 , v088
	.byte	W36
	.byte		N12   , As3 , v072
	.byte	W12
	.byte		N13   , Cs4 , v076
	.byte	W12
	.byte		N11   , Fs4 , v072
	.byte	W12
	.byte		N05   , Dn4 , v084
	.byte	W18
	.byte		N04   , Dn4 , v072
	.byte	W06
	.byte		N10   , Dn4 , v076
	.byte	W08
	.byte		N09   , En4 
	.byte	W07
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N05   , En4 , v084
	.byte	W16
	.byte		N04   , En4 , v076
	.byte	W09
	.byte		N10   , En4 , v072
	.byte	W08
	.byte		N07   , Fs4 , v080
	.byte	W06
	.byte		N10   , Gn4 , v084
	.byte	W10
	.byte		N06   , Gs4 , v092
	.byte	W24
	.byte		N04   , Gs3 , v088
	.byte	W18
	.byte		N05   , Gs3 , v076
	.byte	W08
	.byte		N30   , Gs3 , v096
	.byte	W44
	.byte	W02
mus_high_score_2_B1:
	.byte	W96
	.byte	W96
	.byte		N03   , Gs3 , v084
	.byte	W17
	.byte		N08   , Fn3 , v056
	.byte	W06
	.byte		N32   , Cs4 , v080
	.byte	W36
	.byte	W01
	.byte		N15   , Cn4 , v068
	.byte	W12
	.byte		N13   , As3 , v076
	.byte	W12
	.byte		N14   , Gs3 
	.byte	W12
	.byte		N06   , Fs3 , v084
	.byte	W18
	.byte		N08   , Fn3 , v076
	.byte	W06
	.byte		N48   , Fs3 , v080
	.byte	W68
	.byte	W03
	.byte		N01   , Gs3 , v084
	.byte	W01
	.byte		N04
	.byte	W17
	.byte		N08   , Fn3 , v056
	.byte	W06
	.byte		N32   , Cs4 , v080
	.byte	W36
	.byte	W01
	.byte		N15   , Cn4 , v068
	.byte	W12
	.byte		N13   , As3 , v076
	.byte	W12
	.byte		N14   , Gs3 
	.byte	W12
	.byte		N02   , Fs3 
	.byte	W15
	.byte		N07   , Fn3 
	.byte	W06
	.byte		N44   , Ds3 , v080
	.byte	W72
	.byte	W03
	.byte		N30   , As3 , v088
	.byte	W36
	.byte	W01
	.byte		N05   , As3 , v064
	.byte	W05
	.byte		N07   , Cn4 , v076
	.byte	W06
	.byte		N20   , Cs4 , v084
	.byte	W18
	.byte		N18   , Cn4 , v076
	.byte	W18
	.byte		N13   , As3 , v084
	.byte	W12
	.byte	W02
	.byte		N24   , An3 , v088
	.byte	W32
	.byte	W02
	.byte		N06   , An3 , v064
	.byte	W05
	.byte		N08   , Bn3 , v076
	.byte	W07
	.byte		N19   , Cs4 , v084
	.byte	W19
	.byte		N15   , Bn3 
	.byte	W16
	.byte		        An3 , v080
	.byte	W13
	.byte	W01
	.byte		TIE   , Gs3 , v088
	.byte	W92
	.byte	W03
	.byte	W72
	.byte	W03
	.byte		EOT
	.byte	W21
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W68
	.byte	W02
	.byte		N10   , Gs3 , v076
	.byte	W10
	.byte		        As3 
	.byte	W08
	.byte		N11   , Cn4 
	.byte	W08
	.byte		N07   , Cs4 , v084
	.byte	W18
	.byte		N08   , Gs3 , v072
	.byte	W06
	.byte		N30   , Fn4 , v084
	.byte	W32
	.byte	W03
	.byte		N14
	.byte	W13
	.byte		N12   , Ds4 , v080
	.byte	W12
	.byte		N16   , Cs4 , v076
	.byte	W12
	.byte		N09   , Gs4 , v084
	.byte	W18
	.byte		N08   , Fn4 , v068
	.byte	W06
	.byte		N32   , Cs4 , v080
	.byte	W36
	.byte		N13   , Cs4 , v072
	.byte	W12
	.byte		        Ds4 , v076
	.byte	W12
	.byte		        Fn4 , v072
	.byte	W12
	.byte		N20   , Fs4 , v084
	.byte	W16
	.byte		N17   , Cs4 , v076
	.byte	W16
	.byte		N16   , As3 , v080
	.byte	W16
	.byte		N18   , Fs3 
	.byte	W16
	.byte		N16   , As3 , v076
	.byte	W16
	.byte		        Cs4 , v072
	.byte	W16
	.byte		N21   , Fs4 , v076
	.byte	W16
	.byte		N18   , Gs4 
	.byte	W16
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N20   , An4 , v084
	.byte	W16
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N13   , Fs4 , v080
	.byte	W16
	.byte		N07   , Fn4 , v076
	.byte	W04
	.byte		N08   , Fs4 , v072
	.byte	W06
	.byte		N44   , Gs4 , v088
	.byte	W48
	.byte	W01
	.byte		N15   , Gs4 , v084
	.byte	W13
	.byte		N12   , Fs4 
	.byte	W11
	.byte		N13   , Fn4 , v080
	.byte	W12
	.byte		N07   , As4 , v088
	.byte	W01
	.byte	W16
	.byte		        Gn4 , v068
	.byte	W06
	.byte		N32   , Ds4 , v088
	.byte	W36
	.byte	W01
	.byte		N16   , Ds4 , v084
	.byte	W13
	.byte		N14   , Cs4 , v080
	.byte	W12
	.byte		N13   , Ds4 , v076
	.byte	W12
	.byte		N60   , Gs4 , v084
	.byte	W56
	.byte	W03
	.byte		N12   , As4 , v072
	.byte	W11
	.byte		        Gs4 , v076
	.byte	W12
	.byte		N15   , As4 
	.byte	W12
	.byte		N07   , Gs4 , v084
	.byte	W02
	.byte	W16
	.byte		N03   , Gs4 , v080
	.byte	W07
	.byte		N52   , Gs4 , v092
	.byte	W72
	.byte	W01
	.byte	GOTO
	 .word	mus_high_score_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_high_score_3:  @ 0x0868B5FB
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 72
	.byte		VOL   , 89*mus_high_score_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N05   , Gs5 , v084
	.byte	W17
	.byte		N04   , Gs5 , v076
	.byte	W07
	.byte		N08   , Gs5 , v068
	.byte	W08
	.byte		        Ds5 , v072
	.byte	W07
	.byte		N07   , Cn5 , v068
	.byte	W08
	.byte		N03   , Gs4 , v072
	.byte	W05
	.byte		N02   , As4 
	.byte	W05
	.byte		N03   , Gs4 , v060
	.byte	W03
	.byte		        As4 , v068
	.byte	W07
	.byte		N02   , As4 , v056
	.byte	W04
	.byte		N03   , Gs4 , v060
	.byte	W03
	.byte		        As4 , v064
	.byte	W03
	.byte		        Gs4 , v056
	.byte	W04
	.byte		N01   , As4 
	.byte	W03
	.byte		N02   , Gs4 , v048
	.byte	W02
	.byte		N04   , As4 , v068
	.byte	W04
	.byte		N05   , Gs4 , v072
	.byte	W06
	.byte		N03   , Gs4 , v056
	.byte	W03
	.byte		N05   , Fs5 , v088
	.byte	W14
	.byte		N04   , Fs5 , v076
	.byte	W08
	.byte		N08   , Fs5 , v084
	.byte	W07
	.byte		N07   , Cs5 , v076
	.byte	W06
	.byte		N09   , As4 , v072
	.byte	W08
	.byte		N06   , Fs4 , v080
	.byte	W06
	.byte		N04   , Gs4 
	.byte	W05
	.byte		        Fs4 , v068
	.byte	W04
	.byte		N02   , Gs4 , v060
	.byte	W03
	.byte		N04   , Fs4 , v064
	.byte	W04
	.byte		N03   , Gs4 , v068
	.byte	W04
	.byte		N04   , Fs4 , v060
	.byte	W03
	.byte		N02   , Gs4 , v064
	.byte	W06
	.byte		N04   , Fs4 , v060
	.byte	W03
	.byte		N02   , Gs4 , v064
	.byte	W03
	.byte		        Fs4 , v056
	.byte	W09
	.byte		N06   , Fs5 , v080
	.byte	W16
	.byte		N04   , Fs5 , v076
	.byte	W08
	.byte		N09   , Fs5 , v072
	.byte	W08
	.byte		N08   , En5 , v080
	.byte	W08
	.byte		N09   , Dn5 , v076
	.byte	W08
	.byte		N06   , Gs5 , v084
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N10
	.byte	W08
	.byte		N09   , Fs5 
	.byte	W08
	.byte		N10   , En5 , v072
	.byte	W08
	.byte		N05   , Gs5 , v080
	.byte	W18
	.byte		N02   , Gs5 , v060
	.byte	W07
	.byte		N07
	.byte	W07
	.byte		        As5 , v072
	.byte	W07
	.byte		N08   , Gs5 , v080
	.byte	W08
	.byte		N02   , As5 , v060
	.byte	W03
	.byte		N05   , Gs5 , v076
	.byte	W05
	.byte		N03   , As5 , v064
	.byte	W03
	.byte		N04   , Gs5 , v056
	.byte	W04
	.byte		N03   , As5 , v064
	.byte	W03
	.byte		N04   , Gs5 , v056
	.byte	W04
	.byte		N02   , As5 , v064
	.byte	W02
	.byte		N04   , Gs5 , v036
	.byte	W04
	.byte		N03   , As5 , v068
	.byte	W03
	.byte		N04   , Gs5 , v044
	.byte	W04
	.byte		N01   , As5 , v060
	.byte	W02
	.byte		N03   , Gs5 , v036
	.byte	W04
	.byte		N02   , As5 , v060
	.byte	W02
	.byte		N05   , Gs5 , v036
	.byte	W06
mus_high_score_3_B1:
	.byte		N08   , Gs5 , v076
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N03   , Gs5 , v084
	.byte	W17
	.byte		N08   , Fn5 , v056
	.byte	W06
	.byte		N32   , Cs6 , v080
	.byte	W36
	.byte	W01
	.byte		N15   , Cn6 , v068
	.byte	W12
	.byte		N13   , As5 , v076
	.byte	W12
	.byte		N14   , Gs5 
	.byte	W12
	.byte		N06   , Fs5 , v084
	.byte	W18
	.byte		N08   , Fn5 , v076
	.byte	W06
	.byte		N48   , Fs5 , v080
	.byte	W68
	.byte	W03
	.byte		N01   , Gs5 , v084
	.byte	W01
	.byte		N04
	.byte	W17
	.byte		N08   , Fn5 , v056
	.byte	W06
	.byte		N32   , Cs6 , v080
	.byte	W36
	.byte	W01
	.byte		N15   , Cn6 , v068
	.byte	W12
	.byte		N13   , As5 , v076
	.byte	W12
	.byte		N14   , Gs5 
	.byte	W12
	.byte		N02   , Fs5 
	.byte	W15
	.byte		N07   , Fn5 
	.byte	W06
	.byte		N44   , Ds5 , v080
	.byte	W72
	.byte	W03
	.byte		N04   , Fs5 , v084
	.byte	W17
	.byte		N07   , En5 , v076
	.byte	W06
	.byte		N36   , Fs5 , v084
	.byte	W36
	.byte		N14   , Dn5 , v076
	.byte	W13
	.byte		N12   , En5 , v080
	.byte	W10
	.byte		N13   , Fs5 
	.byte	W12
	.byte		N04   , Gs5 , v088
	.byte	W02
	.byte	W16
	.byte		N07   , Fs5 , v064
	.byte	W05
	.byte		N36   , Gs5 , v088
	.byte	W36
	.byte	W02
	.byte		N14   , En5 , v076
	.byte	W12
	.byte		N11   , Fs5 , v080
	.byte	W12
	.byte		N15   , Gn5 , v084
	.byte	W13
mus_high_score_3_B2:
	.byte		N04   , Gs5 , v068
	.byte	W04
	.byte		N03   , As5 , v072
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        As5 , v064
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        As5 , v064
	.byte	W04
	.byte		N04   , Gs5 , v068
	.byte	W04
	.byte		N03   , As5 , v072
	.byte	W04
	.byte		        Gs5 , v064
	.byte	W04
	.byte		N02   , As5 , v068
	.byte	W04
	.byte		N03   , Gs5 , v060
	.byte	W04
	.byte		        As5 , v068
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		        As5 , v072
	.byte	W04
	.byte		        Gs5 , v068
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        As5 , v068
	.byte	W04
	.byte		N04   , Gs5 , v064
	.byte	W04
	.byte		N03   , As5 , v068
	.byte	W04
	.byte		        Gs5 , v064
	.byte	W04
	.byte		        As5 , v068
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        As5 , v072
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_3_B2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_high_score_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_high_score_4:  @ 0x0868B7DC
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 65
	.byte		VOL   , 74*mus_high_score_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_high_score_4_B1:
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N04   , Fn3 , v080
	.byte	W16
	.byte		        Gs3 
	.byte	W06
	.byte		N24   , Cs4 , v084
	.byte	W24
	.byte	W02
	.byte		N04   , Cn4 , v080
	.byte	W48
	.byte		N03   , Cn4 , v084
	.byte	W08
	.byte		        Cs4 , v072
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W09
	.byte		N24   , Ds4 , v088
	.byte	W24
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N03   , Fn3 , v084
	.byte	W16
	.byte		        Gs3 , v072
	.byte	W07
	.byte		N28   , Cs4 , v084
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N04   , Cn4 , v076
	.byte	W08
	.byte		N03   , Cs4 , v068
	.byte	W06
	.byte		N04   , Dn4 , v076
	.byte	W09
	.byte		N23   , Ds4 , v088
	.byte	W24
	.byte	W02
	.byte	W22
	.byte		N36   , Fs4 , v092
	.byte	W44
	.byte		N13   , As4 
	.byte	W17
	.byte		N14   , Fs4 , v088
	.byte	W13
	.byte	W24
	.byte		N36   , Fs4 , v092
	.byte	W42
	.byte		N13   , An4 , v088
	.byte	W18
	.byte		N09   , Fs4 , v084
	.byte	W12
	.byte	W01
	.byte		N48   , Cs4 
	.byte	W44
	.byte	W02
	.byte		N23   , Gs4 , v088
	.byte	W23
	.byte		        Cs4 , v080
	.byte	W24
	.byte	W02
	.byte		N04   , Cn4 
	.byte	W18
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N54   , Gs4 , v088
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , Fn3 
	.byte	W17
	.byte		N07   , Fs3 , v080
	.byte	W06
	.byte		N32   , Gs3 
	.byte	W36
	.byte		N14
	.byte	W12
	.byte		N11   , Fs3 
	.byte	W11
	.byte		N08   , Fn3 
	.byte	W13
	.byte		N06
	.byte	W01
	.byte	W17
	.byte		        Fs3 
	.byte	W06
	.byte		N32   , Gs3 , v084
	.byte	W36
	.byte		N14
	.byte	W12
	.byte		N12   , Fs3 , v080
	.byte	W13
	.byte		N13   , Fn3 
	.byte	W12
	.byte		N06   , Fs3 , v076
	.byte	W06
	.byte		        Cs3 , v056
	.byte	W05
	.byte		        Fs3 , v064
	.byte	W05
	.byte		N07   , Cs3 , v060
	.byte	W07
	.byte		N04   , Fs3 , v068
	.byte	W12
	.byte		N24   , Fs3 , v080
	.byte	W24
	.byte	W01
	.byte		N13   , As2 , v076
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W11
	.byte		N09   , Fs3 
	.byte	W13
	.byte		N06
	.byte	W06
	.byte		        Cs3 , v068
	.byte	W05
	.byte		        Fs3 
	.byte	W05
	.byte		N08   , Cs3 , v064
	.byte	W07
	.byte		N05   , Fs3 , v080
	.byte	W12
	.byte		N24   , An3 , v088
	.byte	W24
	.byte	W01
	.byte		N14   , Cs3 , v076
	.byte	W11
	.byte		N13   , Fs3 , v080
	.byte	W13
	.byte		N07   , Cs3 , v076
	.byte	W11
	.byte		N05   , Cs3 , v072
	.byte	W01
	.byte	W18
	.byte		N07   , Fn3 
	.byte	W05
	.byte		N32   , Gs3 , v084
	.byte	W36
	.byte		N15   , Gs3 , v064
	.byte	W12
	.byte		N12   , Fn3 , v080
	.byte	W12
	.byte		N14   , Cs3 , v072
	.byte	W12
	.byte		N06   , Ds3 , v084
	.byte	W01
	.byte	W16
	.byte		N04   , Ds3 , v076
	.byte	W06
	.byte		N36   , As3 , v088
	.byte	W36
	.byte	W02
	.byte		N13   , As2 , v084
	.byte	W12
	.byte		N12   , Ds3 , v080
	.byte	W11
	.byte		N14   , As2 , v076
	.byte	W12
	.byte		N05   , Gs3 , v088
	.byte	W01
	.byte	W18
	.byte		N03   , Gs3 , v076
	.byte	W04
	.byte		N36   , Gs3 , v084
	.byte	W36
	.byte	W01
	.byte		N13   , Cs3 , v080
	.byte	W13
	.byte		N11   , Ds3 
	.byte	W10
	.byte		        Cs3 
	.byte	W12
	.byte		N07   , Cn3 , v084
	.byte	W02
	.byte	W16
	.byte		N03   , Ds3 , v068
	.byte	W06
	.byte		N54   , Gs3 , v084
	.byte	W72
	.byte	W02
	.byte	GOTO
	 .word	mus_high_score_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_high_score_5:  @ 0x0868B928
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 73
	.byte		VOL   , 72*mus_high_score_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_high_score_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N10   , Fn4 , v072
	.byte	W08
	.byte		N08   , Cs4 , v060
	.byte	W08
	.byte		N09   , Fn4 , v064
	.byte	W08
	.byte		N05   , Gs4 , v084
	.byte	W16
	.byte		N07   , Fn4 , v060
	.byte	W08
	.byte		N28   , Cs5 , v084
	.byte	W24
	.byte	W24
	.byte		N08   , Ds4 , v072
	.byte	W08
	.byte		        Bn3 , v060
	.byte	W08
	.byte		N10   , Ds4 , v076
	.byte	W08
	.byte		N05   , Fs4 , v084
	.byte	W16
	.byte		N08   , Ds4 , v076
	.byte	W08
	.byte		N24   , Bn4 , v088
	.byte	W24
	.byte	W24
	.byte		N09   , Fn4 , v076
	.byte	W08
	.byte		N08   , Cs4 , v064
	.byte	W08
	.byte		N09   , Fn4 , v056
	.byte	W08
	.byte		N05   , Gs4 , v084
	.byte	W16
	.byte		N07   , Fn4 , v052
	.byte	W08
	.byte		N24   , Cs5 , v084
	.byte	W24
	.byte	W24
	.byte		N09   , Ds4 , v072
	.byte	W08
	.byte		N08   , Bn3 , v044
	.byte	W08
	.byte		N10   , Ds4 , v072
	.byte	W08
	.byte		N05   , Fs4 , v084
	.byte	W16
	.byte		N08   , Ds4 , v076
	.byte	W08
	.byte		N24   , Bn4 , v084
	.byte	W24
	.byte	W24
	.byte		N08   , Dn4 , v076
	.byte	W08
	.byte		        An3 , v060
	.byte	W08
	.byte		N09   , Dn4 , v068
	.byte	W08
	.byte		N08   , Fs4 , v076
	.byte	W08
	.byte		N09   , Dn4 , v072
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N09   , An4 , v076
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N05   , An4 , v084
	.byte	W08
	.byte	W24
	.byte		N08   , En4 , v076
	.byte	W08
	.byte		        Bn3 , v056
	.byte	W08
	.byte		N09   , En4 , v068
	.byte	W08
	.byte		N10   , Gs4 , v084
	.byte	W08
	.byte		        En4 , v068
	.byte	W08
	.byte		N09   , Gs4 , v076
	.byte	W08
	.byte		        Bn4 , v084
	.byte	W08
	.byte		N08   , Gs4 , v080
	.byte	W08
	.byte		N04   , Bn4 , v084
	.byte	W08
	.byte	W24
	.byte		N08   , Cs4 , v068
	.byte	W08
	.byte		N09   , Gs3 
	.byte	W08
	.byte		        Cs4 , v064
	.byte	W08
	.byte		        Ds4 , v084
	.byte	W08
	.byte		N10   , Cs4 , v064
	.byte	W08
	.byte		        Ds4 , v072
	.byte	W08
	.byte		N09   , Gs4 , v080
	.byte	W08
	.byte		N10   , Ds4 , v072
	.byte	W08
	.byte		N07   , Gs4 , v076
	.byte	W08
	.byte	W23
	.byte		N09   , Cn4 
	.byte	W08
	.byte		N10   , Gs3 , v060
	.byte	W09
	.byte		N09   , Cn4 , v068
	.byte	W07
	.byte		        Ds4 , v076
	.byte	W09
	.byte		        Cn4 , v064
	.byte	W08
	.byte		        Ds4 , v072
	.byte	W09
	.byte		N10   , Gs4 , v084
	.byte	W08
	.byte		N09   , Ds4 , v072
	.byte	W07
	.byte		N07   , Gs4 , v080
	.byte	W08
	.byte	W24
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		N09   , Gs4 
	.byte	W08
	.byte		        Fn5 , v072
	.byte	W08
	.byte		N07   , Cs5 , v068
	.byte	W08
	.byte		N10   , Fn5 , v076
	.byte	W08
	.byte		N28   , Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N08   , Gs4 , v068
	.byte	W08
	.byte		N09   , Cs5 , v072
	.byte	W08
	.byte		        Gs4 , v068
	.byte	W08
	.byte		        Fn5 , v076
	.byte	W08
	.byte		N08   , Cs5 , v072
	.byte	W08
	.byte		N11   , Fn5 , v068
	.byte	W08
	.byte		N28   , Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N09   , Fs4 , v056
	.byte	W08
	.byte		N08   , As4 , v068
	.byte	W08
	.byte		N09   , Cs5 
	.byte	W08
	.byte		N10   , Fs5 
	.byte	W08
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N09   , As4 , v072
	.byte	W08
	.byte		N10   , Fs4 , v064
	.byte	W08
	.byte		N08   , As4 , v068
	.byte	W08
	.byte		N10   , Cs5 , v064
	.byte	W08
	.byte		        Fs5 , v068
	.byte	W08
	.byte		N09   , Cs5 , v060
	.byte	W08
	.byte		N08   , An4 , v064
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        An4 , v060
	.byte	W08
	.byte		N11   , Cs5 , v064
	.byte	W08
	.byte		N10   , Fs5 , v068
	.byte	W08
	.byte		        Cs5 , v056
	.byte	W08
	.byte		N09   , An4 , v064
	.byte	W08
	.byte		N11   , Fs4 , v056
	.byte	W08
	.byte		N07   , An4 
	.byte	W08
	.byte		N10   , Cs5 , v068
	.byte	W08
	.byte		N09   , Gs4 , v064
	.byte	W08
	.byte		N08   , Cs5 , v068
	.byte	W08
	.byte		        Gs4 , v072
	.byte	W08
	.byte		        Cs5 , v064
	.byte	W08
	.byte		N09   , Gs4 , v072
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs5 , v064
	.byte	W08
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		N09   , As4 , v076
	.byte	W08
	.byte		N08   , Ds5 , v068
	.byte	W08
	.byte		N09   , As4 , v072
	.byte	W08
	.byte		        Ds5 , v068
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Ds5 , v068
	.byte	W08
	.byte		        As4 , v072
	.byte	W08
	.byte		        Ds5 , v068
	.byte	W08
	.byte		N08   , As4 
	.byte	W08
	.byte		N09   , Ds5 
	.byte	W08
	.byte		        As4 , v060
	.byte	W08
	.byte		        Ds5 , v068
	.byte	W08
	.byte		        Gs4 , v072
	.byte	W08
	.byte		        Ds5 , v064
	.byte	W08
	.byte		        Gs4 , v068
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N09   , Ds5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N10   , Ds5 , v060
	.byte	W08
	.byte		N09   , Gs4 , v064
	.byte	W08
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N07   , Gs4 , v068
	.byte	W08
	.byte		N09   , Ds5 , v056
	.byte	W08
	.byte		N11   , Gs5 , v076
	.byte	W08
	.byte		N09   , Ds5 , v068
	.byte	W08
	.byte		N10   , Gs5 , v076
	.byte	W08
	.byte		N09   , Ds5 , v068
	.byte	W08
	.byte		N10   , Gs5 , v072
	.byte	W08
	.byte		N09   , Ds5 , v068
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gs4 , v064
	.byte	W08
	.byte		N07   , Ds5 , v068
	.byte	W08
	.byte	GOTO
	 .word	mus_high_score_5_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_high_score_6:  @ 0x0868BB4C
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 9
	.byte		VOL   , 86*mus_high_score_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W24
	.byte		N04   , Gs4 , v072
	.byte	W23
	.byte		N03   , Ds5 , v080
	.byte	W23
	.byte		N04   , Gs5 , v088
	.byte	W24
	.byte	W02
	.byte	W24
	.byte		N03   , Fs4 , v072
	.byte	W23
	.byte		        Cs5 , v076
	.byte	W23
	.byte		N04   , Fs5 , v080
	.byte	W24
	.byte	W02
	.byte	W23
	.byte		N04
	.byte	W48
	.byte		        Gs5 , v084
	.byte	W24
	.byte	W01
	.byte	W23
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W24
	.byte	W02
	.byte		N03   , Gs5 , v076
	.byte	W23
mus_high_score_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N03   , Gs4 , v072
	.byte	W24
	.byte		N04   , Cs5 , v076
	.byte	W24
	.byte		        Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N03   , Gs4 , v076
	.byte	W24
	.byte		        Cs5 , v072
	.byte	W24
	.byte		N04   , Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N03   , Fs4 , v076
	.byte	W24
	.byte		        Cs5 , v080
	.byte	W24
	.byte		        Fs5 , v084
	.byte	W24
	.byte	W24
	.byte		        Fs4 , v072
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		N04   , Fs5 , v076
	.byte	W24
	.byte	W24
	.byte		N03   , Gs4 
	.byte	W24
	.byte		        Cs5 , v080
	.byte	W24
	.byte		N04   , Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N03   , As4 , v076
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N04   , As5 , v084
	.byte	W24
	.byte	W24
	.byte		N03   , Gs4 , v068
	.byte	W24
	.byte		        Cs5 , v076
	.byte	W24
	.byte		N04   , Gs5 , v084
	.byte	W24
	.byte	W24
	.byte		N03   , Gs4 , v068
	.byte	W24
	.byte		N04   , Ds5 , v072
	.byte	W24
	.byte		N03   , Gs5 , v080
	.byte	W24
	.byte	GOTO
	 .word	mus_high_score_6_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_high_score_7:  @ 0x0868BBF8
	.byte	KEYSH , mus_high_score_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_high_score_mvl/mxv
	.byte		N03   , Dn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W16
	.byte		N03   , Dn1 , v060
	.byte	W08
	.byte		        Dn1 , v100
	.byte	W04
	.byte		        Dn1 , v060
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
mus_high_score_7_B1:
	.byte		N03   , Dn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W16
	.byte		N03   , Dn1 , v060
	.byte	W08
	.byte		        Dn1 , v100
	.byte	W04
	.byte		        Dn1 , v060
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte	PEND
	.byte		        Dn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W16
	.byte		N03   , Dn1 , v060
	.byte	W08
	.byte		        Dn1 , v100
	.byte	W04
	.byte		        Dn1 , v060
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Dn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W12
	.byte		N03   , Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte	PATT
	 .word	mus_high_score_7_B1
mus_high_score_7_B2:
	.byte		N03   , Cn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W16
	.byte		N03   , Dn1 , v060
	.byte	W08
	.byte		        Cn1 , v100
	.byte	W04
	.byte		        Dn1 , v060
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
	.byte	PATT
	 .word	mus_high_score_7_B2
mus_high_score_7_B3:
	.byte		N03   , Cn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W16
	.byte		N03   , Dn1 , v060
	.byte	W08
	.byte		        Cn1 , v100
	.byte		N19   , Ds2 , v080
	.byte	W04
	.byte		N03   , Dn1 , v060
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		        Cn1 , v100
	.byte		N19   , Cs2 , v080
	.byte	W12
	.byte		N03   , Dn1 , v060
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N19   , Ds2 , v080
	.byte	W12
	.byte		N03   , Dn1 , v060
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	PATT
	 .word	mus_high_score_7_B3
	.byte	GOTO
	 .word	mus_high_score_7_B2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_high_score:  @ 0x0868BD50
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_high_score_pri	@ Priority
	.byte	mus_high_score_rev	@ Reverb

	.word	mus_high_score_grp

	.word	mus_high_score_0
	.word	mus_high_score_1
	.word	mus_high_score_2
	.word	mus_high_score_3
	.word	mus_high_score_4
	.word	mus_high_score_5
	.word	mus_high_score_6
	.word	mus_high_score_7
@ 0x0868BD78
