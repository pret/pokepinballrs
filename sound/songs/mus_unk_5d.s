	.include "sound/MPlayDef.s"

	.equ	mus_unk_5d_grp, gUnknown_08532808
	.equ	mus_unk_5d_pri, 0
	.equ	mus_unk_5d_rev, reverb_set+50
	.equ	mus_unk_5d_mvl, 127
	.equ	mus_unk_5d_key, 0
	.equ	mus_unk_5d_tbs, 1
	.equ	mus_unk_5d_exg, 0
	.equ	mus_unk_5d_cmp, 1

	.section .rodata
	.global	mus_unk_5d
	.align	2

@*********************** Track 01 ***********************@

mus_unk_5d_0:  @ 0x0869E270
	.byte	KEYSH , mus_unk_5d_key+0
	.byte	TEMPO , 144*mus_unk_5d_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 93*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Dn2 , v072
	.byte		N04   , En3 , v076
	.byte	W16
	.byte		N07   , Bn1 , v052
	.byte		N08   , Dn3 , v056
	.byte	W06
	.byte		N07   , Gs1 , v064
	.byte	W02
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W01
	.byte		        As2 , v072
	.byte	W06
	.byte		N10   , Fs1 , v064
	.byte	W01
	.byte		        An2 , v072
	.byte	W08
	.byte		N24   , Fn1 
	.byte		N24   , Gs2 , v080
	.byte	W24
	.byte	W01
	.byte		N05   , En1 , v076
	.byte		N05   , En3 
	.byte	W24
	.byte	W01
mus_unk_5d_0_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_unk_5d_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_unk_5d_1:  @ 0x0869E2D6
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 68
	.byte		VOL   , 68*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
mus_unk_5d_1_B1:
	.byte		N12   , Cn3 , v048
	.byte	W12
	.byte		N13   , Fs3 , v056
	.byte	W12
	.byte		        Cn3 , v052
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N12   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N14   , Cn3 , v052
	.byte	W12
	.byte		N13   , Fs3 , v056
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N14   , Fs3 , v060
	.byte	W12
	.byte		N15   , Cn3 , v056
	.byte	W12
	.byte		N13   , Fs3 , v064
	.byte	W12
	.byte		        Cn3 , v060
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fn3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N11   , Fn3 
	.byte	W12
	.byte		N13   , Cn3 , v060
	.byte	W12
	.byte		N11   , Fn3 , v064
	.byte	W12
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W12
	.byte		N13   , Bn2 , v060
	.byte	W12
	.byte		N11   , En3 
	.byte	W12
	.byte		N13   , Bn2 , v064
	.byte	W12
	.byte		N12   , En3 , v060
	.byte	W12
	.byte		N13   , Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N14   , Gs3 , v068
	.byte	W12
	.byte		N11   , En3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v064
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v060
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 , v052
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N14   , Cn3 , v052
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		        Cn3 , v056
	.byte	W12
	.byte		N10   , Fn3 , v052
	.byte	W12
	.byte		N14   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fn3 , v068
	.byte	W12
	.byte		N13   , Cn3 , v064
	.byte	W12
	.byte		N12   , Fn3 , v068
	.byte	W12
	.byte		N13   , Cn3 , v064
	.byte	W12
	.byte		N12   , Fn3 , v060
	.byte	W12
	.byte		N13   , Bn2 , v064
	.byte	W12
	.byte		N14   , En3 
	.byte	W12
	.byte		        An3 , v072
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		N12   , An3 , v068
	.byte	W12
	.byte		N14   , Gs3 
	.byte	W12
	.byte		N11   , En3 , v064
	.byte	W12
	.byte		N12   , Bn2 , v068
	.byte	W12
	.byte		N13   , Cn3 , v064
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N15   , Cn3 , v068
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N13   , Fs3 , v064
	.byte	W12
	.byte		N14   , Cn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 
	.byte	W12
	.byte		N11   , Fs3 , v064
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N11   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		N12   , Bn2 , v060
	.byte	W12
	.byte		N13   , En3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        En3 , v068
	.byte	W12
	.byte		N13   , Bn2 , v060
	.byte	W12
	.byte		N12   , En3 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N11   , En3 
	.byte	W12
	.byte		N14   , Cn3 
	.byte	W12
	.byte		N12   , Fs3 , v068
	.byte	W12
	.byte		N14   , Cn3 , v060
	.byte	W12
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N13   , Cn3 
	.byte	W12
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N11   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N13   , Gn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		N11   , En3 , v056
	.byte	W12
	.byte		N13   , Gn3 , v064
	.byte	W12
	.byte		N12   , En3 , v060
	.byte	W12
	.byte		N11   , Gn3 , v068
	.byte	W12
	.byte		N13   , Cn3 , v064
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N14   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		        Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		        Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N14   , Cn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		        Cn3 , v056
	.byte	W12
	.byte		N11   , Fs3 
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N14   , Cn3 , v052
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		        Cn3 , v052
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N11   , Fn3 , v064
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fn3 , v068
	.byte	W12
	.byte		        Cn3 , v060
	.byte	W12
	.byte		        Fn3 , v068
	.byte	W12
	.byte		N11   , Cn3 , v060
	.byte	W12
	.byte		        Fn3 , v052
	.byte	W12
	.byte		N13   , Bn2 , v056
	.byte	W12
	.byte		        En3 , v064
	.byte	W12
	.byte		N14   , An3 , v068
	.byte	W12
	.byte		N10   , Bn3 , v072
	.byte	W12
	.byte		N13   , Bn2 , v064
	.byte	W12
	.byte		N14   , En3 , v060
	.byte	W12
	.byte		N15   , Gs3 , v068
	.byte	W12
	.byte		N11   , Bn3 , v064
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N13   , Cn3 , v052
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N11   , Cn3 , v056
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N13   , Cn3 , v056
	.byte	W12
	.byte		        Fs3 , v060
	.byte	W12
	.byte		N10   , Cn3 , v052
	.byte	W12
	.byte		N11   , Fs3 , v060
	.byte	W12
	.byte		N12   , Cs3 , v056
	.byte	W12
	.byte		N14   , En3 , v048
	.byte	W12
	.byte		N13   , Cs3 , v060
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N14   , Cs3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        Cs3 , v056
	.byte	W12
	.byte		        En3 , v064
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 , v072
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        An3 , v072
	.byte	W12
	.byte		N10   , Dn3 , v056
	.byte	W12
	.byte		        An3 , v068
	.byte	W12
	.byte		N14   , Bn2 , v064
	.byte	W12
	.byte		N13   , Dn3 , v060
	.byte	W12
	.byte		N12   , Bn2 , v064
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        Bn2 , v064
	.byte	W12
	.byte		N13   , Dn3 , v060
	.byte	W12
	.byte		N11   , Bn2 , v064
	.byte	W12
	.byte		N13   , Dn3 , v056
	.byte	W12
	.byte		        Cn3 , v068
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		N14   , Cn3 , v060
	.byte	W12
	.byte		N13   , Gn3 , v068
	.byte	W12
	.byte		        Cn3 , v060
	.byte	W12
	.byte		N12   , Gn3 , v072
	.byte	W12
	.byte		N10   , Cn3 , v056
	.byte	W12
	.byte		N11   , Gn3 , v068
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N14   , Cn3 , v060
	.byte	W12
	.byte		N12   , Fn3 , v072
	.byte	W12
	.byte		N11   , Cn3 , v060
	.byte	W12
	.byte		N14   , Fn2 , v068
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N10   , Fn3 , v076
	.byte	W12
	.byte		N14   , As2 , v068
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N13   , As2 , v064
	.byte	W12
	.byte		N12   , Ds3 , v072
	.byte	W12
	.byte		        As2 , v064
	.byte	W12
	.byte		N14   , Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds3 , v072
	.byte	W12
	.byte		N13   , Gs2 , v064
	.byte	W12
	.byte		N14   , Cs2 , v060
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N13   , Cs3 , v072
	.byte	W12
	.byte		        Gs2 , v060
	.byte	W12
	.byte		        Cs2 , v072
	.byte	W12
	.byte		N15   , Fs2 , v056
	.byte	W12
	.byte		N14   , Cs3 , v076
	.byte	W12
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		N04   , Fs2 , v056
	.byte	W11
	.byte		N05   , Fs2 , v064
	.byte	W12
	.byte		        En2 , v068
	.byte	W11
	.byte		        En2 , v060
	.byte	W13
	.byte		        Dn2 , v064
	.byte	W11
	.byte		N05
	.byte	W13
	.byte		        Dn2 , v060
	.byte	W11
	.byte		N05
	.byte	W13
	.byte		N12   , Cn2 
	.byte	W01
	.byte	W10
	.byte		        Gn2 , v068
	.byte	W12
	.byte		N13   , Cn2 , v064
	.byte	W13
	.byte		N05   , Gn2 
	.byte	W13
	.byte		N12   , Gn2 , v072
	.byte	W11
	.byte		N13   , Cn3 , v076
	.byte	W13
	.byte		        Gn2 , v068
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N14   , En2 , v076
	.byte	W12
	.byte		N11   , Bn2 , v068
	.byte	W12
	.byte		N12   , En2 , v072
	.byte	W11
	.byte		N15   , Bn2 
	.byte	W13
	.byte		N12   , En3 , v076
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W13
	.byte		N13   , En2 , v064
	.byte	W11
	.byte		        Bn2 , v068
	.byte	W12
	.byte		        Cn2 , v060
	.byte	W11
	.byte		N11   , Fs2 
	.byte	W11
	.byte		N14   , Cn2 
	.byte	W12
	.byte		N12   , Fs2 , v068
	.byte	W12
	.byte		N14   , Cn2 , v056
	.byte	W13
	.byte		N12   , Fs2 , v064
	.byte	W11
	.byte		N14   , Cn2 , v056
	.byte	W13
	.byte		N10   , Fs2 , v064
	.byte	W10
	.byte		N13   , Cn2 
	.byte	W03
	.byte	W10
	.byte		N12   , Fn2 , v060
	.byte	W12
	.byte		N13   , Cn2 
	.byte	W12
	.byte		N11   , Fn2 , v064
	.byte	W11
	.byte		N13   , Cn2 
	.byte	W13
	.byte		N11   , Fn2 
	.byte	W11
	.byte		N12   , Cn2 
	.byte	W13
	.byte		N10   , Fn2 , v068
	.byte	W12
	.byte		N14   , Cn2 , v064
	.byte	W02
	.byte	W10
	.byte		N11   , Fs2 , v056
	.byte	W12
	.byte		N13   , Cn2 , v060
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N13   , Cn2 
	.byte	W13
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N13   , Cn2 
	.byte	W12
	.byte		N11   , Fs2 
	.byte	W12
	.byte		N13   , Cn2 , v064
	.byte	W01
	.byte	W11
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N13   , Cn2 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N11   , Cn2 
	.byte	W11
	.byte		N12   , Fn2 , v060
	.byte	W13
	.byte		N11   , Cn2 , v064
	.byte	W11
	.byte		N08   , Fn2 
	.byte	W14
	.byte	GOTO
	 .word	mus_unk_5d_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_unk_5d_2:  @ 0x0869E6D3
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 81
	.byte		VOL   , 93*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_unk_5d_2_B1:
	.byte		N36   , An4 , v084
	.byte	W32
	.byte	W02
	.byte		N13   , Ds4 , v068
	.byte	W13
	.byte		N12   , Dn4 , v072
	.byte	W11
	.byte		        Cn4 , v068
	.byte	W12
	.byte		N13   , Bn3 , v060
	.byte	W12
	.byte		N14   , Cn4 , v072
	.byte	W13
	.byte		N06   , An3 
	.byte	W01
	.byte	W16
	.byte		N02   , Ds3 , v060
	.byte	W06
	.byte		N48   , Ds3 , v068
	.byte	W56
	.byte	W03
	.byte		N07   , Fs3 , v060
	.byte	W07
	.byte		        Gs3 , v064
	.byte	W07
	.byte		N24   , An3 , v068
	.byte	W01
	.byte	W24
	.byte	W01
	.byte		        Bn3 , v072
	.byte	W23
	.byte		N23   , Cn4 , v076
	.byte	W24
	.byte		N24   , An3 
	.byte	W23
	.byte		N80   , Bn3 
	.byte	W01
	.byte	W96
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N13   , Ds4 , v084
	.byte	W12
	.byte		N10   , An4 , v080
	.byte	W12
	.byte		N12   , Dn4 , v076
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
	.byte		        Bn3 , v072
	.byte	W12
	.byte		N13   , Cn4 , v076
	.byte	W12
	.byte		        An3 , v072
	.byte	W12
	.byte		N07   , Gs3 , v064
	.byte	W06
	.byte		N09   , Fs3 , v068
	.byte	W06
	.byte		N60   , Fn3 , v080
	.byte	W60
	.byte		N07   , Fs3 , v064
	.byte	W06
	.byte		N08   , Gs3 , v068
	.byte	W06
	.byte		N07   , An3 , v076
	.byte	W06
	.byte		N08   , Gs3 , v068
	.byte	W12
	.byte		N09   , An3 , v072
	.byte	W06
	.byte		N08   , Bn3 , v076
	.byte	W06
	.byte		N09   , An3 , v068
	.byte	W12
	.byte		N10   , Bn3 , v076
	.byte	W06
	.byte		N23   , Cn4 , v080
	.byte	W24
	.byte		N09   , Dn4 , v072
	.byte	W06
	.byte		N08   , En4 , v068
	.byte	W06
	.byte		N11   , Fn4 , v080
	.byte	W12
	.byte		N72   , En4 , v084
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N36   , An4 , v076
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W11
	.byte		N11   , Dn4 
	.byte	W12
	.byte		N13   , Cn4 , v068
	.byte	W12
	.byte		N11   , Bn3 , v072
	.byte	W11
	.byte		N14   , Cn4 , v076
	.byte	W12
	.byte		N08   , An3 
	.byte	W02
	.byte	W16
	.byte		N04   , Ds3 , v064
	.byte	W06
	.byte		N48   , Ds3 , v068
	.byte	W60
	.byte		N05   , Fs3 , v056
	.byte	W06
	.byte		N08   , Gs3 , v068
	.byte	W07
	.byte		N11   , An3 , v072
	.byte	W01
	.byte	W09
	.byte		N07   , Gs3 , v064
	.byte	W08
	.byte		N08   , An3 , v056
	.byte	W07
	.byte		        Bn3 , v072
	.byte	W06
	.byte		N10   , An3 , v052
	.byte	W08
	.byte		N09   , Bn3 , v056
	.byte	W09
	.byte		N23   , Cn4 , v076
	.byte	W23
	.byte		N10   , Dn4 , v064
	.byte	W09
	.byte		N08   , En4 , v068
	.byte	W08
	.byte		N11   , Fn4 , v076
	.byte	W08
	.byte		N78   , En4 
	.byte	W01
	.byte	W96
	.byte	W11
	.byte		N14   , An4 
	.byte	W13
	.byte		N15   , Ds4 
	.byte	W12
	.byte		N11   , An4 
	.byte	W11
	.byte		N12   , Dn4 , v068
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte		        Bn3 
	.byte	W11
	.byte		        Cn4 
	.byte	W13
	.byte		N07   , An3 , v076
	.byte	W01
	.byte	W16
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N42   , Ds4 , v068
	.byte	W60
	.byte	W01
	.byte		N07   , Fs3 , v056
	.byte	W07
	.byte		N14   , Gs3 , v064
	.byte	W06
	.byte		N52   , An3 , v080
	.byte	W60
	.byte		N13   , An3 , v072
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W11
	.byte		N19   , Cs4 
	.byte	W12
	.byte		N07   , Dn4 
	.byte	W01
	.byte	W18
	.byte		N03   , An3 
	.byte	W06
	.byte		N30   , An3 , v060
	.byte	W32
	.byte	W03
	.byte		N14   , Dn3 
	.byte	W12
	.byte		N12   , An3 , v068
	.byte	W11
	.byte		        Dn4 , v080
	.byte	W14
	.byte		N48   , Gn3 , v072
	.byte	W60
	.byte		N13
	.byte	W12
	.byte		N11   , An3 , v080
	.byte	W12
	.byte		N14   , Bn3 , v076
	.byte	W12
	.byte		N07   , Cn4 , v080
	.byte	W18
	.byte		N02   , Gn3 , v064
	.byte	W06
	.byte		N42
	.byte	W36
	.byte		N14   , Cn3 
	.byte	W12
	.byte		N12   , Gn3 , v068
	.byte	W12
	.byte		N15   , Cn4 , v076
	.byte	W12
	.byte		N18   , An3 
	.byte	W16
	.byte		N04   , Fn3 , v060
	.byte	W08
	.byte		N10   , Fn3 , v064
	.byte	W08
	.byte		N07   , Gn3 , v072
	.byte	W07
	.byte		N10   , An3 , v076
	.byte	W09
	.byte		N07   , As3 
	.byte	W15
	.byte		N02   , Fn3 , v072
	.byte	W07
	.byte		N24
	.byte	W24
	.byte	W01
	.byte		N16   , Gn3 , v076
	.byte	W01
	.byte	W14
	.byte		N05   , Ds3 , v072
	.byte	W08
	.byte		N12   , Ds3 , v056
	.byte	W09
	.byte		N10   , Fn3 , v064
	.byte	W07
	.byte		N11   , Gn3 , v072
	.byte	W10
	.byte		N07   , Gs3 , v076
	.byte	W16
	.byte		N02   , Ds3 , v064
	.byte	W07
	.byte		N24   , Ds3 , v068
	.byte	W24
	.byte	W01
	.byte		N18   , Fn3 , v072
	.byte	W18
	.byte		N03   , Cs3 , v064
	.byte	W06
	.byte		N11   , Cs3 , v056
	.byte	W07
	.byte		N09   , Ds3 , v068
	.byte	W07
	.byte		N10   , Fn3 , v076
	.byte	W09
	.byte		N07   , Fs3 
	.byte	W16
	.byte		N02   , Cs3 , v060
	.byte	W07
	.byte		N24   , Cs3 , v072
	.byte	W24
	.byte	W02
	.byte		N13   , Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N12   , En3 , v068
	.byte	W11
	.byte		N13   , Bn2 
	.byte	W12
	.byte		N12   , Dn3 , v064
	.byte	W12
	.byte		        An2 , v068
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		N14   , Gn2 , v064
	.byte	W13
	.byte		N60   , Cn3 , v072
	.byte	W56
	.byte	W03
	.byte		N14   , Gn2 , v064
	.byte	W12
	.byte		        Cn3 , v068
	.byte	W11
	.byte		        Gn3 , v080
	.byte	W13
	.byte		N04   , En3 , v084
	.byte	W01
	.byte	W19
	.byte		N07   , Bn2 , v048
	.byte	W05
	.byte		N36   , Gs3 , v084
	.byte	W36
	.byte		N15   , En3 , v076
	.byte	W12
	.byte		N13   , Fs3 
	.byte	W11
	.byte		N11   , Gs3 , v080
	.byte	W13
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_5d_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_unk_5d_3:  @ 0x0869E8F4
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 39
	.byte		VOL   , 85*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_unk_5d_3_B1:
	.byte		N08   , An1 , v080
	.byte	W24
	.byte		N08
	.byte	W24
	.byte		N09   , An1 , v072
	.byte	W24
	.byte		N10
	.byte	W24
	.byte	PEND
mus_unk_5d_3_B2:
	.byte		N10   , An1 , v076
	.byte	W24
	.byte		N09
	.byte	W24
	.byte		N08
	.byte	W24
	.byte		N07   , An1 , v080
	.byte	W24
	.byte	PEND
mus_unk_5d_3_B3:
	.byte		N09   , Fn1 , v084
	.byte	W24
	.byte		N08   , Fn1 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
mus_unk_5d_3_B4:
	.byte		N09   , En1 , v080
	.byte	W24
	.byte		N07   , En1 , v076
	.byte	W24
	.byte		N06   , En1 , v080
	.byte	W24
	.byte		N07   , En1 , v076
	.byte	W24
	.byte	PEND
mus_unk_5d_3_B5:
	.byte		N08   , An1 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N08
	.byte	W24
	.byte	PEND
mus_unk_5d_3_B6:
	.byte		N08   , An1 , v080
	.byte	W24
	.byte		N07   , An1 , v076
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	PEND
	.byte		N08   , Fn1 , v080
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		        Fn1 , v076
	.byte	W24
	.byte		N06   , Fn1 , v080
	.byte	W24
	.byte		N08   , En1 
	.byte	W24
	.byte		N07   , En1 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        En1 , v080
	.byte	W24
	.byte		        An1 , v084
	.byte	W24
	.byte		N07   , An1 , v076
	.byte	W24
	.byte		N06   , An1 , v080
	.byte	W24
	.byte		        An1 , v076
	.byte	W24
	.byte		N07   , An1 , v080
	.byte	W24
	.byte		N06   , An1 , v076
	.byte	W24
	.byte		N05   , An1 , v080
	.byte	W24
	.byte		N06   , An1 , v076
	.byte	W24
	.byte		N07   , Gs1 , v088
	.byte	W24
	.byte		N06   , Gs1 , v076
	.byte	W24
	.byte		N05   , Gs1 , v080
	.byte	W24
	.byte		N06   , Gs1 , v076
	.byte	W24
	.byte		N05   , An1 , v084
	.byte	W24
	.byte		        An1 , v080
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , An1 , v076
	.byte	W24
	.byte		N06   , An1 , v084
	.byte	W24
	.byte		N05   , An1 , v080
	.byte	W24
	.byte		        An1 , v084
	.byte	W24
	.byte		        An1 , v080
	.byte	W24
	.byte		        An1 , v084
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , An1 , v080
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , As1 , v088
	.byte	W24
	.byte		        As1 , v084
	.byte	W24
	.byte		        As1 , v076
	.byte	W24
	.byte		N07   , As1 , v072
	.byte	W24
	.byte		N05   , An1 , v084
	.byte	W24
	.byte		        An1 , v076
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N05
	.byte	W24
	.byte	PATT
	 .word	mus_unk_5d_3_B1
	.byte	PATT
	 .word	mus_unk_5d_3_B2
	.byte	PATT
	 .word	mus_unk_5d_3_B3
	.byte	PATT
	 .word	mus_unk_5d_3_B4
	.byte	PATT
	 .word	mus_unk_5d_3_B5
	.byte	PATT
	 .word	mus_unk_5d_3_B6
	.byte		N05   , Gn1 , v072
	.byte	W24
	.byte		        Gn1 , v064
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , Fn1 , v068
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        Fn1 , v064
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        Fn1 , v060
	.byte	W24
	.byte		N07   , Ds1 , v072
	.byte	W24
	.byte		N06   , Ds1 , v064
	.byte	W24
	.byte		N07   , Ds1 , v068
	.byte	W24
	.byte		N06   , Ds1 , v072
	.byte	W24
	.byte		        Ds2 , v084
	.byte	W24
	.byte		        Ds2 , v076
	.byte	W24
	.byte		        Dn2 , v080
	.byte	W24
	.byte		        Dn2 , v076
	.byte	W24
	.byte		N07   , Cs2 , v072
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , Cn2 , v076
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , Bn1 
	.byte	W24
	.byte		N05   , Bn1 , v072
	.byte	W24
	.byte		N06   , As1 , v076
	.byte	W24
	.byte		        As1 , v072
	.byte	W24
	.byte		N05   , An1 , v068
	.byte	W24
	.byte		N06   , Gn1 , v072
	.byte	W24
	.byte		N05   , Fs1 , v068
	.byte	W24
	.byte		N04   , Fn1 , v072
	.byte	W24
	.byte		N05   , En1 , v080
	.byte	W24
	.byte		        En1 , v072
	.byte	W24
	.byte		        En1 , v068
	.byte	W24
	.byte		N04   , En1 , v072
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N04   , En1 , v076
	.byte	W24
	.byte		        An1 
	.byte	W23
	.byte		        An1 , v072
	.byte	W24
	.byte		N05
	.byte	W24
	.byte	W01
	.byte		        An1 , v076
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Fn1 , v072
	.byte	W24
	.byte		        Fn1 , v076
	.byte	W24
	.byte		        Fn1 , v072
	.byte	W24
	.byte		N06   , An1 , v068
	.byte	W24
	.byte	W01
	.byte		N05   , An1 , v072
	.byte	W23
	.byte		N05
	.byte	W24
	.byte		        An1 , v068
	.byte	W24
	.byte		N04   , Fn1 , v064
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N03   , Fn1 , v056
	.byte	W23
	.byte		N05   , Fn1 , v064
	.byte	W24
	.byte	W01
	.byte	GOTO
	 .word	mus_unk_5d_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_unk_5d_4:  @ 0x0869EAA9
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 12
	.byte		VOL   , 94*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
mus_unk_5d_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
mus_unk_5d_4_B2:
	.byte		N10   , En2 , v048
	.byte	W08
	.byte		N08   , An2 , v064
	.byte	W07
	.byte		N07   , Bn2 
	.byte	W08
	.byte		N10   , En3 , v060
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N09   , Bn3 
	.byte	W08
	.byte		        En4 , v068
	.byte	W09
	.byte		N08   , Bn3 , v060
	.byte	W07
	.byte		N09   , Gs3 , v068
	.byte	W08
	.byte		        En3 , v064
	.byte	W08
	.byte		        Bn2 , v060
	.byte	W09
	.byte		N11   , Gs2 , v064
	.byte	W08
	.byte	PEND
mus_unk_5d_4_B3:
	.byte	W02
	.byte		N12   , Fs2 , v076
	.byte	W92
	.byte	W02
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_unk_5d_4_B2
	.byte	PATT
	 .word	mus_unk_5d_4_B3
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_unk_5d_4_B2
	.byte	PATT
	 .word	mus_unk_5d_4_B3
	.byte	W96
	.byte	W96
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
	.byte	W01
	.byte		N02   , En3 , v064
	.byte	W44
	.byte	W03
	.byte		N04   , En3 , v068
	.byte		N04   , An3 , v072
	.byte	W24
	.byte	W01
	.byte	W23
	.byte		N02   , Ds3 , v068
	.byte		N04   , An3 , v072
	.byte	W48
	.byte	W01
	.byte		N02   , Ds3 , v068
	.byte		N04   , An3 , v076
	.byte	W24
	.byte	W23
	.byte		N02   , En3 , v060
	.byte		N05   , An3 , v072
	.byte	W48
	.byte	W01
	.byte		N02   , En3 
	.byte		N04   , An3 , v076
	.byte	W24
	.byte	W23
	.byte		N02   , Ds3 , v068
	.byte		N04   , An3 , v076
	.byte	W48
	.byte	W01
	.byte		N02   , An3 , v072
	.byte	W01
	.byte		N04   , Ds3 , v068
	.byte	W23
	.byte	GOTO
	 .word	mus_unk_5d_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_unk_5d_5:  @ 0x0869EB5C
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 73
	.byte		VOL   , 85*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		MOD   , 5
	.byte	W96
mus_unk_5d_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48   , Cs4 , v080
	.byte	W44
	.byte	W03
	.byte		N24   , En4 , v076
	.byte	W24
	.byte	W01
	.byte		N23   , Cs4 
	.byte	W23
	.byte		N48   , Dn4 , v080
	.byte	W01
	.byte	W48
	.byte	W01
	.byte		N24   , An4 
	.byte	W23
	.byte		        Dn5 , v076
	.byte	W23
	.byte		N48   , Bn4 , v084
	.byte	W01
	.byte	W48
	.byte	W01
	.byte		N24   , Gn4 , v076
	.byte	W23
	.byte		        Dn4 , v072
	.byte	W24
	.byte		        Cn5 , v080
	.byte	W23
	.byte		        Gn4 , v076
	.byte	W24
	.byte	W01
	.byte		        Cn4 , v068
	.byte	W24
	.byte	W01
	.byte		        Cn5 , v080
	.byte	W23
	.byte		        An4 , v084
	.byte	W24
	.byte	W01
	.byte		N08   , Fn4 , v072
	.byte	W07
	.byte		        Gn4 , v068
	.byte	W07
	.byte		N09   , An4 , v084
	.byte	W09
	.byte		N24   , As4 , v080
	.byte	W24
	.byte		        Fn4 , v076
	.byte	W23
	.byte		        Gn4 
	.byte	W01
	.byte	W23
	.byte		N09   , Ds4 , v068
	.byte	W09
	.byte		N08   , Fn4 , v064
	.byte	W07
	.byte		N11   , Gn4 , v072
	.byte	W08
	.byte		N24   , Gs4 , v080
	.byte	W24
	.byte	W01
	.byte		        Ds4 , v068
	.byte	W24
	.byte		N28   , Fn4 , v076
	.byte	W24
	.byte		N10   , Cs4 , v064
	.byte	W08
	.byte		N09   , Ds4 , v072
	.byte	W07
	.byte		N10   , Fn4 , v076
	.byte	W08
	.byte		N24   , Fs4 , v072
	.byte	W23
	.byte		        Cs4 , v068
	.byte	W24
	.byte	W02
	.byte		        Ds4 , v080
	.byte	W23
	.byte		N23   , En4 
	.byte	W24
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N23   , Gn4 , v084
	.byte	W24
	.byte		N10   , Cn4 , v068
	.byte	W01
	.byte	W08
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N09   , Cn4 , v064
	.byte	W09
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Cn5 , v080
	.byte	W07
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Cn4 
	.byte	W07
	.byte		N08   , Gn4 , v072
	.byte	W09
	.byte		N09   , Cn4 
	.byte	W08
	.byte		N08   , Gn4 , v068
	.byte	W09
	.byte		N07   , Cn4 , v064
	.byte	W07
	.byte		        Gn4 
	.byte	W08
	.byte	W01
	.byte		N09   , En4 , v076
	.byte	W08
	.byte		N07   , Gs4 , v060
	.byte	W08
	.byte		N09   , En4 , v064
	.byte	W08
	.byte		N08   , Gs4 , v076
	.byte	W08
	.byte		        En4 , v068
	.byte	W08
	.byte		        Gs4 , v076
	.byte	W08
	.byte		N07   , Bn4 , v068
	.byte	W07
	.byte		N09   , En4 , v064
	.byte	W08
	.byte		N08   , Bn4 , v076
	.byte	W07
	.byte		N09   , En4 , v068
	.byte	W09
	.byte		        Bn4 , v076
	.byte	W08
	.byte		N06   , En4 , v072
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_unk_5d_5_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_unk_5d_6:  @ 0x0869EC65
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 71
	.byte		VOL   , 85*mus_unk_5d_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_unk_5d_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N05   , Ds3 , v064
	.byte	W12
	.byte		N04   , Cn4 , v072
	.byte	W12
	.byte		N05   , Ds3 , v064
	.byte	W24
	.byte		        Ds3 , v060
	.byte	W12
	.byte		N04   , Cn4 , v064
	.byte	W12
	.byte		N05   , Ds3 , v060
	.byte	W12
	.byte	W10
	.byte		N15   , Cn4 
	.byte	W13
	.byte		N14   , Bn3 , v068
	.byte	W12
	.byte		N08   , An3 
	.byte	W24
	.byte		N15   , Cn4 , v064
	.byte	W13
	.byte		N13   , Bn3 , v068
	.byte	W11
	.byte		N10   , An3 , v072
	.byte	W13
	.byte	W12
	.byte		N12   , Bn3 , v068
	.byte	W11
	.byte		        An3 
	.byte	W12
	.byte		N08   , Gs3 , v072
	.byte	W24
	.byte		N14   , Bn3 , v060
	.byte	W13
	.byte		N11   , An3 , v064
	.byte	W10
	.byte		N09   , Gs3 , v072
	.byte	W14
	.byte	W12
	.byte		N13   , Cn4 , v064
	.byte	W12
	.byte		N14   , Bn3 , v072
	.byte	W12
	.byte		N07   , An3 , v068
	.byte	W24
	.byte		N15   , Cn4 , v064
	.byte	W12
	.byte		N14   , Bn3 , v068
	.byte	W12
	.byte		N07   , An3 , v076
	.byte	W12
	.byte	W12
	.byte		N11   , Cn4 , v060
	.byte	W12
	.byte		N13   , Bn3 , v072
	.byte	W12
	.byte		N09   , An3 , v064
	.byte	W24
	.byte		N14   , Cn4 , v056
	.byte	W12
	.byte		        Bn3 , v072
	.byte	W12
	.byte		N08   , An3 
	.byte	W12
	.byte	W12
	.byte		N15   , Cn4 , v064
	.byte	W12
	.byte		N13   , Bn3 , v072
	.byte	W12
	.byte		N08   , An3 
	.byte	W24
	.byte		N14   , Cn4 , v068
	.byte	W12
	.byte		N13   , Bn3 
	.byte	W12
	.byte		N07   , An3 , v076
	.byte	W12
	.byte	W12
	.byte		N13   , Cs4 , v064
	.byte	W12
	.byte		N12   , Cn4 , v072
	.byte	W12
	.byte		N08   , As3 , v076
	.byte	W24
	.byte		N14   , Cs4 , v064
	.byte	W12
	.byte		N12   , Cn4 , v072
	.byte	W12
	.byte		N07   , As3 , v076
	.byte	W12
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N14   , Bn3 
	.byte	W12
	.byte		N07   , An3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N14   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_unk_5d_6_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 08 ***********************@

mus_unk_5d_7:  @ 0x0869ED4A
	.byte	KEYSH , mus_unk_5d_key+0
	.byte		VOICE , 0
	.byte		VOL   , 54*mus_unk_5d_mvl/mxv
	.byte		N06   , Dn1 , v100
	.byte	W42
	.byte		N05   , Cn1 
	.byte	W06
	.byte		N06
	.byte	W24
	.byte		        Dn1 
	.byte	W24
mus_unk_5d_7_B1:
	.byte		N06   , Cn1 , v100
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W06
	.byte		N05
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W06
	.byte		N05
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W06
	.byte		N05
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W06
	.byte		N05
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	PATT
	 .word	mus_unk_5d_7_B1
	.byte	GOTO
	 .word	mus_unk_5d_7_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_unk_5d:  @ 0x0869EE34
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_unk_5d_pri	@ Priority
	.byte	mus_unk_5d_rev	@ Reverb

	.word	mus_unk_5d_grp

	.word	mus_unk_5d_0
	.word	mus_unk_5d_1
	.word	mus_unk_5d_2
	.word	mus_unk_5d_3
	.word	mus_unk_5d_4
	.word	mus_unk_5d_5
	.word	mus_unk_5d_6
	.word	mus_unk_5d_7
@ 0x0869EE5C
