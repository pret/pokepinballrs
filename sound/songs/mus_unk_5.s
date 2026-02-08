	.include "sound/MPlayDef.s"

	.equ	mus_unk_5_grp, gUnknown_08532808
	.equ	mus_unk_5_pri, 0
	.equ	mus_unk_5_rev, reverb_set+50
	.equ	mus_unk_5_mvl, 127
	.equ	mus_unk_5_key, 0
	.equ	mus_unk_5_tbs, 1
	.equ	mus_unk_5_exg, 0
	.equ	mus_unk_5_cmp, 1

	.section .rodata
	.global	mus_unk_5
	.align	2

@*********************** Track 01 ***********************@

mus_unk_5_0:  @ 0x08689CE4
	.byte	KEYSH , mus_unk_5_key+0
mus_unk_5_0_B1:
	.byte	TEMPO , 130*mus_unk_5_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_unk_5_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , An1 , v080
	.byte	W36
	.byte		N03   , En2 
	.byte	W12
	.byte		N18   , En2 , v084
	.byte	W24
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		N28   , En1 , v068
	.byte	W36
	.byte		N04   , En2 
	.byte	W12
	.byte		N21   , En2 , v072
	.byte	W24
	.byte		N18   , En1 , v064
	.byte	W24
	.byte		N24   , An1 , v076
	.byte	W36
	.byte		N04   , En2 , v072
	.byte	W12
	.byte		N16   , En2 , v080
	.byte	W24
	.byte		N17   , An1 , v072
	.byte	W24
	.byte		N28   , An1 , v076
	.byte	W36
	.byte		N04   , En2 , v072
	.byte	W12
	.byte		N16   , En2 , v076
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		N24   , Dn2 
	.byte	W36
	.byte		N03   , An2 , v080
	.byte	W12
	.byte		N15
	.byte	W24
	.byte		N17   , Dn2 , v076
	.byte	W24
	.byte		N28   , Dn2 , v080
	.byte	W36
	.byte		N03   , An2 , v076
	.byte	W12
	.byte		N13   , An2 , v080
	.byte	W24
	.byte		N18   , Dn2 , v076
	.byte	W24
	.byte		N24   , En1 
	.byte	W36
	.byte		N02   , Bn1 , v072
	.byte	W12
	.byte		N16   , Bn1 , v076
	.byte	W24
	.byte		N15   , En1 , v068
	.byte	W24
	.byte		N30   , En1 , v072
	.byte	W36
	.byte		N05   , Bn1 , v076
	.byte	W12
	.byte		N20
	.byte	W24
	.byte		        En1 , v064
	.byte	W24
	.byte		N24   , An1 , v080
	.byte	W36
	.byte		N03   , En2 , v072
	.byte	W12
	.byte		N15   , En2 , v080
	.byte	W24
	.byte		N19   , As1 , v076
	.byte	W24
	.byte		N24   , Bn1 , v080
	.byte	W36
	.byte		N03   , En2 
	.byte	W12
	.byte		N19   , En2 , v076
	.byte	W24
	.byte		N17   , En1 
	.byte	W24
	.byte		N28   , An1 
	.byte	W36
	.byte		N02   , En2 
	.byte	W12
	.byte		N18   , En2 , v080
	.byte	W24
	.byte		N19   , En1 , v072
	.byte	W24
	.byte		N28   , An1 , v080
	.byte	W36
	.byte		N03   , En2 , v072
	.byte	W12
	.byte		N17   , En2 , v076
	.byte	W24
	.byte		N16   , An1 , v080
	.byte	W24
	.byte		N24   , Dn2 , v076
	.byte	W36
	.byte		N03   , An2 
	.byte	W12
	.byte		N16   , An2 , v080
	.byte	W24
	.byte		N17   , Dn2 , v076
	.byte	W24
	.byte		N24
	.byte	W36
	.byte		N04   , An2 , v080
	.byte	W12
	.byte		N15   , An2 , v076
	.byte	W24
	.byte		N17   , Dn2 , v080
	.byte	W24
	.byte		N24   , En1 , v076
	.byte	W36
	.byte		N04   , Bn1 
	.byte	W12
	.byte		N18
	.byte	W24
	.byte		N17   , En1 , v064
	.byte	W24
	.byte		N30   , En1 , v076
	.byte	W36
	.byte		N03   , Bn1 , v080
	.byte	W12
	.byte		N20
	.byte	W24
	.byte		N19   , En1 , v064
	.byte	W24
	.byte		N24   , An1 , v076
	.byte	W36
	.byte		N03   , En2 , v072
	.byte	W12
	.byte		N17   , En2 , v076
	.byte	W24
	.byte		N19   , Fn1 , v072
	.byte	W24
	.byte		N24   , An1 , v076
	.byte	W36
	.byte		N03   , En2 , v072
	.byte	W12
	.byte		N15   , En2 , v080
	.byte	W24
	.byte		N16   , An1 , v076
	.byte	W24
	.byte		N24   , Dn2 , v084
	.byte	W36
	.byte		N02   , Dn1 , v072
	.byte	W12
	.byte		N19   , Dn1 , v068
	.byte	W24
	.byte		N15   , En1 , v076
	.byte	W24
	.byte		N24   , Fs1 , v080
	.byte	W36
	.byte		N06   , Fs1 , v076
	.byte	W12
	.byte		N16   , Gn1 , v080
	.byte	W24
	.byte		N15   , Gs1 
	.byte	W24
	.byte		N28   , An1 
	.byte	W36
	.byte		N03   , En2 , v076
	.byte	W12
	.byte		N16
	.byte	W24
	.byte		N17   , Gs1 
	.byte	W24
	.byte		N24   , An1 , v080
	.byte	W36
	.byte		N04   , An1 , v076
	.byte	W12
	.byte		N16
	.byte	W24
	.byte		N15   , En2 , v080
	.byte	W24
	.byte		N23   , Dn2 
	.byte	W36
	.byte		N05   , Dn1 , v076
	.byte	W12
	.byte		N17
	.byte	W24
	.byte		        En1 , v080
	.byte	W24
	.byte		N24   , Fs1 
	.byte	W36
	.byte		N07   , Fs1 , v064
	.byte	W12
	.byte		N16   , Gn1 , v076
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N24   , An1 , v080
	.byte	W36
	.byte		N05   , En2 , v076
	.byte	W12
	.byte		N17
	.byte	W24
	.byte		N18   , An1 , v080
	.byte	W24
	.byte		N28   , Fs1 , v084
	.byte	W36
	.byte		N04   , Cs2 , v072
	.byte	W12
	.byte		N17   , Cs2 , v076
	.byte	W24
	.byte		N14   , Fs1 , v072
	.byte	W24
	.byte		N24   , Bn1 , v080
	.byte	W36
	.byte		N06   , Fs2 , v060
	.byte	W12
	.byte		N18   , Fs2 , v076
	.byte	W24
	.byte		N19   , Bn1 , v080
	.byte	W24
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N04   , Dn2 , v076
	.byte	W12
	.byte		N16
	.byte	W24
	.byte		        Gn1 , v080
	.byte	W24
	.byte		N24   , Fn1 , v084
	.byte	W36
	.byte		N04   , As1 , v076
	.byte	W12
	.byte		N18   , As1 , v080
	.byte	W24
	.byte		N16   , Fn1 
	.byte	W24
	.byte		N24   , En1 
	.byte	W36
	.byte		N02   , En2 , v076
	.byte	W12
	.byte		N16   , En2 , v084
	.byte	W24
	.byte		N14   , En1 , v076
	.byte	W24
	.byte		N24   , An1 , v072
	.byte	W36
	.byte		N01   , En2 , v068
	.byte	W12
	.byte		N24   , En2 , v072
	.byte	W24
	.byte		N15   , An1 , v068
	.byte	W24
	.byte		N28
	.byte	W36
	.byte		N04   , En2 , v072
	.byte	W12
	.byte		N17
	.byte	W24
	.byte		N15   , An1 
	.byte	W24
	.byte	GOTO
	 .word	mus_unk_5_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_unk_5_1:  @ 0x08689EC4
	.byte	KEYSH , mus_unk_5_key+0
mus_unk_5_1_B1:
	.byte		VOICE , 71
	.byte		VOL   , 108*mus_unk_5_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		MOD   , 3
	.byte	W96
	.byte	W36
	.byte		N22   , Gs3 , v080
	.byte	W24
	.byte		N06   , An3 , v068
	.byte	W06
	.byte		N09   , Bn3 , v072
	.byte	W06
	.byte		N08   , An3 , v060
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W06
	.byte		N10   , Gs3 , v068
	.byte	W12
	.byte		N36   , En3 
	.byte	W60
	.byte		N06
	.byte	W12
	.byte		N13   , En3 , v048
	.byte	W12
	.byte		N14   , Fs4 , v076
	.byte	W12
	.byte		N04   , En4 , v060
	.byte	W06
	.byte		N08   , Dn4 , v072
	.byte	W06
	.byte		N48   , Cs4 
	.byte	W48
	.byte		N15   , An3 , v064
	.byte	W12
	.byte		N14   , Bn3 , v076
	.byte	W12
	.byte		N15   , Cn4 
	.byte	W12
	.byte		N54   , Cs4 , v068
	.byte	W60
	.byte		N14   , Cs4 , v064
	.byte	W12
	.byte		N15   , Dn4 , v076
	.byte	W12
	.byte		        Cs4 , v072
	.byte	W12
	.byte		N14   , Bn3 
	.byte	W12
	.byte		N42   , Fs3 , v060
	.byte	W48
	.byte		N13   , Fs3 , v068
	.byte	W12
	.byte		N14   , Gs3 , v076
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		N60   , En3 
	.byte	W60
	.byte		N13   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N08   , Gn3 , v076
	.byte	W12
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W24
	.byte		N05   , Bn3 
	.byte	W24
	.byte		N04   , Gs3 , v080
	.byte	W24
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		N56   , En3 , v076
	.byte	W56
	.byte	W01
	.byte		N09   , Cs3 , v060
	.byte	W07
	.byte		N10   , En3 , v056
	.byte	W08
	.byte		N09   , Gn3 , v060
	.byte	W07
	.byte		N08   , Fs3 , v064
	.byte	W08
	.byte		N10   , Fn3 , v072
	.byte	W08
	.byte		N78   , En3 
	.byte	W01
	.byte	W96
	.byte		N07
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N40   , En3 
	.byte	W48
	.byte		N08   , En3 , v076
	.byte	W12
	.byte		N14   , En3 , v060
	.byte	W12
	.byte		N13   , Fs4 , v072
	.byte	W12
	.byte		N06   , En4 , v076
	.byte	W06
	.byte		N07   , Dn4 , v068
	.byte	W06
	.byte		N44   , Cs4 , v080
	.byte	W48
	.byte		N14   , An3 , v076
	.byte	W12
	.byte		N13   , Bn3 , v080
	.byte	W12
	.byte		N15   , Cn4 
	.byte	W12
	.byte		N52   , Cs4 , v084
	.byte	W56
	.byte	W03
	.byte		N14   , Cs4 , v072
	.byte	W12
	.byte		N13   , Dn4 , v076
	.byte	W11
	.byte		        Cs4 , v064
	.byte	W11
	.byte		N04   , As3 , v068
	.byte	W02
	.byte		N13   , Bn3 , v076
	.byte	W01
	.byte	W11
	.byte		N32   , Fs3 , v064
	.byte	W48
	.byte	W01
	.byte		N14   , Fs3 , v072
	.byte	W13
	.byte		N13   , Gs3 , v076
	.byte	W11
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N36   , En3 , v080
	.byte	W32
	.byte	W03
	.byte		N13   , Fn3 
	.byte	W12
	.byte		N18   , Fs3 , v076
	.byte	W18
	.byte		N06   , Gn3 , v072
	.byte	W05
	.byte		N12   , Gs3 , v080
	.byte	W13
	.byte		N07   , An3 , v076
	.byte	W13
	.byte	W23
	.byte		N08   , Cs4 , v072
	.byte	W08
	.byte		N09   , En4 , v076
	.byte	W08
	.byte		        Cs4 
	.byte	W07
	.byte		N24   , Bn3 
	.byte	W24
	.byte	W01
	.byte		        En3 , v072
	.byte	W23
	.byte		N48   , An3 , v080
	.byte	W02
	.byte	W56
	.byte	W03
	.byte		N13   , An3 , v076
	.byte	W12
	.byte		N10   , Cn4 
	.byte	W08
	.byte		N08   , Bn3 , v068
	.byte	W06
	.byte		N09   , As3 , v072
	.byte	W09
	.byte		N52   , An3 , v076
	.byte	W02
	.byte	W56
	.byte	W03
	.byte		N04   , An3 , v068
	.byte	W13
	.byte		        An3 , v064
	.byte	W11
	.byte		N05   , An3 , v076
	.byte	W13
	.byte	W01
	.byte		N56   , Fs3 , v080
	.byte	W56
	.byte	W02
	.byte		N13   , En3 , v068
	.byte	W12
	.byte		N12   , Dn3 , v064
	.byte	W11
	.byte		N14   , En3 , v072
	.byte	W12
	.byte		N60   , Fs3 , v076
	.byte	W02
	.byte	W56
	.byte	W03
	.byte		N14   , Dn3 , v064
	.byte	W13
	.byte		N12   , En3 , v072
	.byte	W10
	.byte		N14   , Fs3 
	.byte	W14
	.byte		N36   , En3 , v076
	.byte	W32
	.byte	W03
	.byte		N22   , An3 
	.byte	W24
	.byte	W01
	.byte		N06   , An2 , v060
	.byte	W11
	.byte		N13   , An2 , v076
	.byte	W12
	.byte		N12   , Bn2 , v072
	.byte	W12
	.byte		N13   , Dn3 , v064
	.byte	W01
	.byte	W11
	.byte		N06   , Cs3 , v060
	.byte	W04
	.byte		N07   , Bn2 , v068
	.byte	W07
	.byte		N13   , An2 , v072
	.byte	W12
	.byte		N21   , En3 , v064
	.byte	W60
	.byte	W02
	.byte	W01
	.byte		TIE   , Dn4 , v080
	.byte	W92
	.byte	W03
	.byte	W92
	.byte		EOT
	.byte	W04
	.byte		N32   , En4 
	.byte	W32
	.byte	W03
	.byte		N08   , An3 , v072
	.byte	W13
	.byte		N24   , An3 , v068
	.byte	W24
	.byte		N23   , Bn3 , v080
	.byte	W22
	.byte		N13   , En4 
	.byte	W02
	.byte	W12
	.byte		N06   , Fs4 , v068
	.byte	W04
	.byte		N08   , En4 
	.byte	W07
	.byte		N13   , Cs4 , v076
	.byte	W12
	.byte		N12   , Fs4 , v080
	.byte	W32
	.byte	W03
	.byte		N24   , Fs3 , v084
	.byte	W24
	.byte	W02
	.byte		N48   , Dn3 , v076
	.byte	W48
	.byte		N10   , Bn2 , v068
	.byte	W08
	.byte		N09   , Fs2 , v064
	.byte	W08
	.byte		N05   , Bn2 , v056
	.byte	W08
	.byte		N07
	.byte	W08
	.byte		N08   , Cs3 , v064
	.byte	W08
	.byte		N02   , Dn3 , v068
	.byte	W08
	.byte		N48   , Dn3 , v076
	.byte	W48
	.byte		N08   , Bn2 , v064
	.byte	W08
	.byte		        Gn2 , v060
	.byte	W08
	.byte		N03   , Bn2 , v068
	.byte	W08
	.byte		N09   , Bn2 , v076
	.byte	W08
	.byte		N08   , Cs3 , v072
	.byte	W08
	.byte		N04   , Dn3 , v076
	.byte	W08
	.byte	W24
	.byte		N12   , Dn3 , v060
	.byte	W12
	.byte		        Ds3 , v068
	.byte	W12
	.byte		N13   , Fn3 
	.byte	W12
	.byte		N12   , Gn3 , v072
	.byte	W12
	.byte		N13   , Gs3 , v068
	.byte	W12
	.byte		N17   , As3 , v072
	.byte	W12
	.byte		N60   , Bn3 , v084
	.byte	W60
	.byte		N13   , Fs4 , v076
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N16   , Fs4 
	.byte	W12
	.byte		N44   , En4 , v084
	.byte	W54
	.byte		N03   , An4 , v068
	.byte	W07
	.byte		N01   , En4 , v064
	.byte	W07
	.byte		N03   , Cs4 , v068
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		N03   , En3 , v064
	.byte	W11
	.byte		N24   , An2 , v076
	.byte	W01
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_5_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_unk_5_2:  @ 0x0868A104
	.byte	KEYSH , mus_unk_5_key+0
mus_unk_5_2_B1:
	.byte		VOICE , 68
	.byte		VOL   , 97*mus_unk_5_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N32   , En3 , v076
	.byte	W30
	.byte	W01
	.byte		N09   , Fs3 , v052
	.byte	W08
	.byte		N06   , Gs3 , v056
	.byte	W07
	.byte		        En3 , v048
	.byte	W07
	.byte		N07   , Cs3 , v056
	.byte	W08
	.byte		N09   , Dn3 
	.byte	W08
	.byte		N44   , En3 , v068
	.byte	W03
	.byte	W56
	.byte	W03
	.byte		N13
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W13
	.byte		N13   , En3 , v064
	.byte	W12
	.byte		N44   , Dn3 , v072
	.byte	W60
	.byte		N15   , Dn3 , v068
	.byte	W12
	.byte		N12   , En3 , v072
	.byte	W12
	.byte		N13   , Fn3 , v076
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Dn3 , v064
	.byte	W24
	.byte		        An2 , v076
	.byte	W24
	.byte		N44   , Bn2 
	.byte	W60
	.byte		N13   , Bn2 , v060
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		N05   , Bn2 , v064
	.byte	W12
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W24
	.byte		N13
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N13   , Dn3 , v064
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		N15   , En3 , v064
	.byte	W12
	.byte		N32   , Cs3 , v076
	.byte	W36
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Cs3 , v072
	.byte	W12
	.byte		N21   , En3 
	.byte	W24
	.byte	W24
	.byte		N32   , En3 , v076
	.byte	W32
	.byte	W01
	.byte		N05   , Cs3 , v052
	.byte	W05
	.byte		N08   , Dn3 , v056
	.byte	W08
	.byte		N09   , En3 , v060
	.byte	W07
	.byte		N08   , Fs3 , v064
	.byte	W07
	.byte		N04   , En3 , v060
	.byte	W11
	.byte		N40   , En3 , v072
	.byte	W01
	.byte	W60
	.byte		N05   , Cs3 , v068
	.byte	W12
	.byte		N13   , Cs3 , v060
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		N40   , Cs3 , v048
	.byte	W36
	.byte		N17   , An3 , v076
	.byte	W24
	.byte		N14   , An3 , v064
	.byte	W12
	.byte		N10   , Gs3 , v076
	.byte	W12
	.byte		N14   , Gn3 , v072
	.byte	W12
	.byte	W01
	.byte		N24   , Fs3 , v080
	.byte	W24
	.byte		N23   , An3 , v072
	.byte	W23
	.byte		N24   , Dn4 , v076
	.byte	W24
	.byte	W01
	.byte		        Cs4 
	.byte	W23
	.byte	W01
	.byte		        Bn3 
	.byte	W22
	.byte		N23   , Fs3 , v068
	.byte	W36
	.byte	W01
	.byte		N14   , Fs3 , v064
	.byte	W13
	.byte		N11   , En3 , v068
	.byte	W11
	.byte		N13   , Dn3 , v060
	.byte	W12
	.byte		N36   , Bn2 , v076
	.byte	W56
	.byte	W03
	.byte		N13   , En3 , v068
	.byte	W13
	.byte		N12   , Fn3 , v076
	.byte	W11
	.byte		N14   , Fs3 , v068
	.byte	W13
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , An3 , v052
	.byte	W06
	.byte		N23   , Bn3 , v076
	.byte	W36
	.byte	W01
	.byte		N12   , En4 , v068
	.byte	W11
	.byte		N13   , En3 , v064
	.byte	W12
	.byte		N09   , En4 , v060
	.byte	W12
	.byte		N44   , En3 , v064
	.byte	W60
	.byte		N13   , En3 , v068
	.byte	W12
	.byte		N24   , Ds3 , v064
	.byte		N24   , Fn3 , v076
	.byte	W24
	.byte		N60   , En3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N13   , An2 
	.byte	W12
	.byte		N56   , Fs3 , v080
	.byte	W56
	.byte	W02
	.byte		N14   , En3 , v072
	.byte	W13
	.byte		N11   , Dn3 , v064
	.byte	W10
	.byte		N08   , En3 , v068
	.byte	W07
	.byte		N10   , Dn3 , v060
	.byte	W08
	.byte	W01
	.byte		N09   , Fs3 , v076
	.byte	W08
	.byte		        Gn3 , v068
	.byte	W08
	.byte		        Gs3 , v080
	.byte	W09
	.byte		N32   , An3 , v084
	.byte	W32
	.byte	W03
	.byte		N10   , An3 , v076
	.byte	W12
	.byte		N13   , Dn3 , v064
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W11
	.byte		N20   , En3 
	.byte	W18
	.byte		N08   , En4 
	.byte	W06
	.byte		N19   , Cs4 , v076
	.byte	W18
	.byte		N06   , An3 , v064
	.byte	W06
	.byte		N14   , En3 , v068
	.byte	W16
	.byte		N07   , Cs3 , v064
	.byte	W07
	.byte		N18   , An2 , v052
	.byte	W18
	.byte		N16   , Cs3 
	.byte	W07
	.byte		N42   , Fs3 , v076
	.byte	W68
	.byte	W03
	.byte		N28   , As2 , v064
	.byte	W24
	.byte	W01
	.byte		N60   , Bn2 , v076
	.byte	W60
	.byte	W01
	.byte		N13   , Dn3 , v068
	.byte	W12
	.byte		N14   , Bn3 , v076
	.byte	W12
	.byte		N15   , Fs3 , v068
	.byte	W11
	.byte	W02
	.byte		N60   , Bn2 , v076
	.byte	W56
	.byte	W02
	.byte		N12   , Dn3 , v064
	.byte	W12
	.byte		N14   , Bn3 , v072
	.byte	W11
	.byte		N12   , Fs3 , v068
	.byte	W13
	.byte	W24
	.byte	W02
	.byte		N11   , As2 , v072
	.byte	W11
	.byte		N13   , Cn3 
	.byte	W11
	.byte		N12   , Dn3 , v068
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N13   , Fn3 , v076
	.byte	W11
	.byte		N14   , Fs3 , v072
	.byte	W13
	.byte	W01
	.byte		N44   , Gs3 , v084
	.byte	W56
	.byte	W02
	.byte		N13   , Gs3 , v076
	.byte	W12
	.byte		        Fs3 , v072
	.byte	W12
	.byte		        Gs3 , v068
	.byte	W13
	.byte		N56   , An3 , v080
	.byte	W72
	.byte		N09   , En3 , v060
	.byte	W08
	.byte		N08   , An3 , v068
	.byte	W08
	.byte		N12   , Cs4 , v060
	.byte	W08
	.byte		N24   , En4 , v072
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_5_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_unk_5_3:  @ 0x0868A2E0
	.byte	KEYSH , mus_unk_5_key+0
mus_unk_5_3_B1:
	.byte		VOICE , 84
	.byte		VOL   , 62*mus_unk_5_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W23
	.byte		N02   , En2 , v064
	.byte		N04   , Cs3 , v072
	.byte	W36
	.byte	W01
	.byte		N01   , An2 , v068
	.byte	W11
	.byte		N04   , En3 , v060
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W13
	.byte	W24
	.byte		N02   , Gs2 
	.byte		N05   , En3 
	.byte	W32
	.byte	W03
	.byte		N03   , Bn2 , v072
	.byte	W12
	.byte		N05   , Gs3 , v064
	.byte	W12
	.byte		N04   , En3 
	.byte	W13
	.byte	W23
	.byte		N03   , En2 , v060
	.byte		N06   , Cs3 , v068
	.byte	W36
	.byte		N01   , An2 , v076
	.byte	W12
	.byte		N05   , En3 , v064
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W13
	.byte	W22
	.byte		N04   , En2 , v064
	.byte		N05   , Cs3 
	.byte	W36
	.byte	W01
	.byte		N02   , An2 , v068
	.byte	W12
	.byte		N05   , En3 , v064
	.byte	W13
	.byte		        Cs3 , v060
	.byte	W12
	.byte	W23
	.byte		N03   , Fs2 
	.byte		N05   , Dn3 , v072
	.byte	W36
	.byte		N01   , Bn2 , v060
	.byte	W12
	.byte		N05   , Fs3 , v072
	.byte	W12
	.byte		N04   , Dn3 , v068
	.byte	W13
	.byte	W22
	.byte		        Fs2 , v064
	.byte		N06   , Bn2 , v068
	.byte	W36
	.byte	W01
	.byte		N02   , Bn2 , v064
	.byte	W12
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		N03   , Dn3 , v064
	.byte	W13
	.byte	W23
	.byte		N05   , Gs2 , v068
	.byte	W01
	.byte		N02   , En2 , v052
	.byte	W32
	.byte	W03
	.byte		N03   , Bn2 , v068
	.byte	W13
	.byte		        En3 , v064
	.byte	W11
	.byte		N02   , Bn2 
	.byte	W13
	.byte	W22
	.byte		N04   , Gs2 , v072
	.byte	W01
	.byte		N01   , En2 , v056
	.byte	W36
	.byte	W01
	.byte		N03   , Bn2 , v068
	.byte	W12
	.byte		N05   , En3 , v064
	.byte	W11
	.byte		N02   , Bn2 
	.byte	W13
	.byte	W24
	.byte		        En2 , v056
	.byte		N05   , Cs3 , v068
	.byte	W36
	.byte		N01   , An2 , v072
	.byte	W11
	.byte		N04   , Fn3 , v068
	.byte	W12
	.byte		N05   , Ds3 , v064
	.byte	W13
	.byte	W22
	.byte		        Gs2 , v060
	.byte	W01
	.byte		        En3 , v064
	.byte	W36
	.byte	W01
	.byte		N04   , Bn2 
	.byte	W12
	.byte		N05   , Gs3 
	.byte	W12
	.byte		N04   , En3 , v068
	.byte	W12
	.byte	W22
	.byte		N06   , Cs3 
	.byte	W01
	.byte		N01   , En2 , v060
	.byte	W32
	.byte	W03
	.byte		        An2 , v072
	.byte	W13
	.byte		N04   , En3 , v068
	.byte	W11
	.byte		N05   , Cs3 , v064
	.byte	W14
	.byte	W23
	.byte		        En2 
	.byte		N06   , Cs3 , v060
	.byte	W36
	.byte	W01
	.byte		N01   , An2 , v072
	.byte	W11
	.byte		N04   , En3 , v064
	.byte	W12
	.byte		N05   , Cs3 , v068
	.byte	W13
	.byte	W24
	.byte		N02   , Fs2 , v056
	.byte		N05   , Dn3 , v064
	.byte	W36
	.byte		N01   , Bn2 , v052
	.byte	W12
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte	W24
	.byte		N04   , Fs2 , v056
	.byte		N06   , Bn2 , v064
	.byte	W32
	.byte	W03
	.byte		N01
	.byte	W12
	.byte		N05   , Fs3 , v060
	.byte	W13
	.byte		N04   , Dn3 , v068
	.byte	W12
	.byte	W23
	.byte		N02   , En2 , v060
	.byte		N05   , Bn2 , v068
	.byte	W36
	.byte		N02   , Gs2 
	.byte	W12
	.byte		N04   , En3 
	.byte	W12
	.byte		N02   , Bn2 
	.byte	W13
	.byte	W24
	.byte		        En2 , v060
	.byte		N06   , Bn2 , v072
	.byte	W32
	.byte	W02
	.byte		N05   , Gs2 , v064
	.byte	W13
	.byte		        En3 
	.byte	W13
	.byte		N02   , Bn2 , v060
	.byte	W12
	.byte	W12
	.byte		        Cs3 , v056
	.byte	W12
	.byte		N04   , En2 , v068
	.byte	W12
	.byte		N03   , An2 , v064
	.byte	W11
	.byte		        An2 , v068
	.byte	W13
	.byte		N05   , Cs3 , v060
	.byte	W12
	.byte		        En3 , v064
	.byte	W11
	.byte		N04   , Fn3 , v072
	.byte	W13
	.byte	W11
	.byte		N05   , En3 , v064
	.byte	W13
	.byte		N03   , An2 
	.byte	W12
	.byte		N05   , Cs3 
	.byte	W12
	.byte		N02   , En3 
	.byte	W12
	.byte		N04   , An3 
	.byte	W11
	.byte		        Cs4 , v072
	.byte	W12
	.byte		N03   , En4 , v080
	.byte	W13
	.byte	W12
	.byte		N13   , Fs3 , v064
	.byte	W12
	.byte		N14   , Dn3 
	.byte	W13
	.byte		N13   , An2 , v068
	.byte	W12
	.byte		N12   , Dn3 , v060
	.byte	W11
	.byte		N13   , An2 , v064
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W11
	.byte		N08   , An2 , v064
	.byte	W13
	.byte	W12
	.byte		N14   , Fs3 , v068
	.byte	W12
	.byte		N12   , Dn3 , v064
	.byte	W12
	.byte		N13   , An2 , v068
	.byte	W12
	.byte		N12   , Dn3 , v060
	.byte	W11
	.byte		N13   , An2 , v064
	.byte	W12
	.byte		N12   , Dn3 , v060
	.byte	W12
	.byte		N06   , An2 , v064
	.byte	W13
	.byte	W12
	.byte		N14   , Cs3 , v060
	.byte	W12
	.byte		N11   , An2 , v072
	.byte	W11
	.byte		N14   , En2 , v068
	.byte	W12
	.byte		        Cs3 , v064
	.byte	W12
	.byte		N13   , An2 , v068
	.byte	W12
	.byte		        Cs3 , v060
	.byte	W12
	.byte		N06   , An2 , v068
	.byte	W13
	.byte	W12
	.byte		N13   , Cs3 
	.byte	W12
	.byte		N11   , An2 
	.byte	W11
	.byte		N13   , En2 
	.byte	W12
	.byte		        En3 , v064
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
	.byte		N15   , En3 , v064
	.byte	W12
	.byte		N08   , Cs3 , v060
	.byte	W13
	.byte	W13
	.byte		N13   , Fs3 , v064
	.byte	W12
	.byte		N12   , Dn3 , v056
	.byte	W11
	.byte		        An2 , v064
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        An2 
	.byte	W11
	.byte		        Dn3 , v064
	.byte	W12
	.byte		N07   , An2 
	.byte	W13
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W11
	.byte		N13   , Dn3 , v060
	.byte	W12
	.byte		        An2 , v068
	.byte	W13
	.byte		N12   , Dn3 , v060
	.byte	W12
	.byte		        An2 , v064
	.byte	W12
	.byte		N13   , Dn3 , v060
	.byte	W12
	.byte		N07   , An2 , v064
	.byte	W12
	.byte	W13
	.byte		N13   , Cs3 
	.byte	W11
	.byte		N12   , An2 , v068
	.byte	W12
	.byte		N14   , En2 , v064
	.byte	W12
	.byte		N12   , Cs3 , v060
	.byte	W12
	.byte		N13   , An2 , v064
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N06   , An2 , v068
	.byte	W12
	.byte	W12
	.byte		N14   , Cs3 , v060
	.byte	W13
	.byte		N12   , As2 , v064
	.byte	W11
	.byte		N14   , Fs2 , v060
	.byte	W11
	.byte		N13   , Cs3 , v064
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N14   , Cs3 , v060
	.byte	W12
	.byte		N07   , As2 , v064
	.byte	W13
	.byte	W13
	.byte		N11   , Dn3 , v072
	.byte	W12
	.byte		N13   , Bn2 , v068
	.byte	W11
	.byte		N14   , Fs2 , v060
	.byte	W12
	.byte		N13   , Fs3 , v068
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W11
	.byte		        Fs3 , v068
	.byte	W12
	.byte		N05   , Dn3 , v060
	.byte	W13
	.byte	W14
	.byte		N11   , Bn2 , v064
	.byte	W11
	.byte		        Gn2 
	.byte	W11
	.byte		N13   , Dn2 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W11
	.byte		N13   , Bn2 
	.byte	W12
	.byte		N05   , Gn2 , v060
	.byte	W13
	.byte	W12
	.byte		N12   , Dn3 , v064
	.byte	W12
	.byte		        As2 , v068
	.byte	W11
	.byte		N13   , Fn2 , v064
	.byte	W13
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        As2 , v064
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W11
	.byte		N06   , As2 , v068
	.byte	W13
	.byte	W12
	.byte		N13   , En2 , v060
	.byte	W12
	.byte		N11   , Fs2 , v064
	.byte	W12
	.byte		N13   , Gn2 , v072
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N13   , An2 , v076
	.byte	W12
	.byte		N12   , As2 , v072
	.byte	W12
	.byte		N13   , Bn2 
	.byte	W12
	.byte		N48   , Cs3 , v068
	.byte	W48
	.byte		N11   , An2 , v072
	.byte	W12
	.byte		N13   , En3 , v064
	.byte	W12
	.byte		N14   , Cs3 , v060
	.byte	W12
	.byte		N16   , An2 , v064
	.byte	W12
	.byte		N19   , Cs2 , v060
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_5_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_unk_5:  @ 0x0868A5A4
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_unk_5_pri	@ Priority
	.byte	mus_unk_5_rev	@ Reverb

	.word	mus_unk_5_grp

	.word	mus_unk_5_0
	.word	mus_unk_5_1
	.word	mus_unk_5_2
	.word	mus_unk_5_3
