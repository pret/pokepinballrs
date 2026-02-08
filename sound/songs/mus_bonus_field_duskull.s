	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_duskull_grp, gUnknown_08532808
	.equ	mus_bonus_field_duskull_pri, 0
	.equ	mus_bonus_field_duskull_rev, reverb_set+50
	.equ	mus_bonus_field_duskull_mvl, 127
	.equ	mus_bonus_field_duskull_key, 0
	.equ	mus_bonus_field_duskull_tbs, 1
	.equ	mus_bonus_field_duskull_exg, 0
	.equ	mus_bonus_field_duskull_cmp, 1

	.section .rodata
	.global	mus_bonus_field_duskull
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_duskull_0:  @ 0x086977BC
	.byte	KEYSH , mus_bonus_field_duskull_key+0
mus_bonus_field_duskull_0_B1:
	.byte	TEMPO , 84*mus_bonus_field_duskull_tbs/2
	.byte		VOICE , 7
	.byte		VOL   , 91*mus_bonus_field_duskull_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N03   , An1 , v060
	.byte		N04   , An2 
	.byte	W03
	.byte		        Cn2 , v056
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		        Ds2 , v064
	.byte	W01
	.byte		N03   , Ds3 
	.byte	W03
	.byte		N06   , Fs3 , v068
	.byte	W01
	.byte		N04   , Fs2 , v060
	.byte	W04
	.byte		N17   , Fn2 , v064
	.byte		N17   , Fn3 , v072
	.byte	W17
	.byte		N03   , En2 
	.byte		N03   , En3 , v076
	.byte	W08
	.byte		N04   , Ds2 , v068
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N05   , Fs2 , v064
	.byte		N04   , An3 , v068
	.byte	W08
	.byte		N03   , Fn2 
	.byte		N03   , Gs3 , v076
	.byte	W08
	.byte		N04   , Ds2 , v064
	.byte		N04   , Fs3 , v072
	.byte	W09
	.byte		N07   , An2 , v076
	.byte		N06   , Cn4 , v080
	.byte	W23
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_duskull_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_duskull_1:  @ 0x08697834
	.byte	KEYSH , mus_bonus_field_duskull_key+0
mus_bonus_field_duskull_1_B1:
	.byte		VOICE , 16
	.byte		VOL   , 88*mus_bonus_field_duskull_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W02
	.byte		N48   , As1 , v064
	.byte	W48
	.byte		N44   , Fs2 , v052
	.byte	W44
	.byte	W02
	.byte	W01
	.byte		N48   , As1 , v056
	.byte	W48
	.byte	W02
	.byte		        Fs2 , v052
	.byte	W44
	.byte	W01
	.byte	W04
	.byte		        As1 , v060
	.byte	W48
	.byte	W01
	.byte		N44   , Fs2 , v056
	.byte	W42
	.byte	W01
	.byte	W01
	.byte		N48   , As1 
	.byte	W44
	.byte	W02
	.byte		        Fs2 
	.byte	W48
	.byte		N44   , An1 , v060
	.byte	W01
	.byte	W44
	.byte	W01
	.byte		        Fn2 , v056
	.byte	W44
	.byte	W02
	.byte		N48   , Cn2 , v060
	.byte	W05
	.byte	W44
	.byte	W01
	.byte		N16   , Fn1 , v052
	.byte	W17
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N16   , Fn2 , v056
	.byte	W17
	.byte		N08   , Fn1 , v048
	.byte	W08
	.byte		N48   , As1 , v064
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W48
	.byte		        As1 
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N52   , Fs2 , v060
	.byte	W48
	.byte	W01
	.byte	W02
	.byte		N48   , An1 
	.byte	W48
	.byte		        Fn2 , v056
	.byte	W44
	.byte	W02
	.byte	W01
	.byte		N40   , Fn1 , v060
	.byte	W44
	.byte	W02
	.byte		N16
	.byte	W15
	.byte		N10   , Cn2 , v052
	.byte	W09
	.byte		N16   , Fn2 , v056
	.byte	W17
	.byte		N09   , Fn1 , v052
	.byte	W08
	.byte		N03   , As1 , v056
	.byte	W07
	.byte		N03
	.byte	W08
	.byte		N12   , As1 , v064
	.byte	W10
	.byte		N06   , Fn2 
	.byte	W24
	.byte	W01
	.byte		N24   , Fs2 , v068
	.byte	W24
	.byte		N06   , An1 , v056
	.byte	W22
	.byte	W01
	.byte		N04   , As1 , v064
	.byte	W07
	.byte		N03   , As1 , v056
	.byte	W08
	.byte		N08   , As1 , v060
	.byte	W09
	.byte		N05   , Fn2 , v064
	.byte	W22
	.byte		N24   , Fs2 , v068
	.byte	W24
	.byte		N06   , An1 , v060
	.byte	W23
	.byte		N04   , Cn2 
	.byte	W02
	.byte	W05
	.byte		N03   , Cn2 , v052
	.byte	W07
	.byte		N10   , Cn2 , v056
	.byte	W09
	.byte		N06   , Fs2 , v060
	.byte	W24
	.byte	W01
	.byte		N24   , An2 , v068
	.byte	W24
	.byte		N06   , Cn2 , v060
	.byte	W23
	.byte		N02   , Cs2 , v056
	.byte	W03
	.byte	W04
	.byte		N03   , Cs2 , v060
	.byte	W08
	.byte		N11   , Cs2 , v056
	.byte	W09
	.byte		N06   , As2 , v068
	.byte	W23
	.byte		N15   , Ds2 , v076
	.byte	W15
	.byte		N10   , En2 , v068
	.byte	W09
	.byte		N05   , Fn2 , v064
	.byte	W17
	.byte		N09   , Fn1 , v056
	.byte	W09
	.byte		N03   , As1 , v064
	.byte	W02
	.byte	W06
	.byte		N02   , As1 , v068
	.byte	W07
	.byte		N11
	.byte	W09
	.byte		N05   , Fn2 , v060
	.byte	W23
	.byte		N24   , Fs2 , v068
	.byte	W24
	.byte	W01
	.byte		N06   , An1 , v060
	.byte	W24
	.byte	W01
	.byte		N02   , As1 , v072
	.byte	W01
	.byte	W07
	.byte		N03   , As1 , v060
	.byte	W07
	.byte		N10   , As1 , v056
	.byte	W09
	.byte		N05   , Fn2 , v064
	.byte	W24
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N06   , Cn2 , v060
	.byte	W16
	.byte		N09
	.byte	W08
	.byte		N03   , Cs2 , v056
	.byte	W01
	.byte	W07
	.byte		        Cs2 , v052
	.byte	W08
	.byte		N09   , Cs2 , v060
	.byte	W08
	.byte		N05   , As2 , v064
	.byte	W24
	.byte		N24   , Bn2 , v072
	.byte	W24
	.byte		N05   , Dn2 , v064
	.byte	W18
	.byte		N09   , Dn2 , v068
	.byte	W07
	.byte	W01
	.byte		N02   , Ds2 , v064
	.byte	W08
	.byte		N03   , Ds2 , v068
	.byte	W08
	.byte		N07   , Ds2 , v064
	.byte	W08
	.byte		N05   , Fs2 
	.byte	W24
	.byte		N24   , Fn2 , v068
	.byte	W24
	.byte		N04   , Fn1 
	.byte	W23
	.byte	W01
	.byte		N48   , As1 , v072
	.byte	W44
	.byte	W03
	.byte		        Fs2 , v052
	.byte	W48
	.byte	W01
	.byte		        As1 , v060
	.byte	W48
	.byte		        Fs2 , v064
	.byte	W44
	.byte	W03
	.byte	W01
	.byte		        An1 , v068
	.byte	W48
	.byte		        Fn2 , v056
	.byte	W44
	.byte	W03
	.byte	W01
	.byte		N44   , Cn2 , v064
	.byte	W44
	.byte	W03
	.byte		N16   , Fn1 , v060
	.byte	W16
	.byte		N08   , Cn2 , v056
	.byte	W07
	.byte		N16   , Fn2 , v064
	.byte	W16
	.byte		N09   , Fn1 , v048
	.byte	W09
	.byte		N44   , As1 , v076
	.byte	W44
	.byte	W02
	.byte		N48   , Fs2 , v060
	.byte	W48
	.byte		        As1 
	.byte	W02
	.byte	W44
	.byte		        Fs2 , v056
	.byte	W48
	.byte	W02
	.byte		N44   , Cn2 , v064
	.byte	W02
	.byte	W42
	.byte	W01
	.byte		N48   , Fs2 , v060
	.byte	W48
	.byte	W01
	.byte		N40   , Cs2 
	.byte	W04
	.byte	W36
	.byte		N10   , Dn2 , v056
	.byte	W10
	.byte		N17   , Ds2 , v064
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N10   , Fn2 , v060
	.byte	W16
	.byte		        Fn1 , v052
	.byte	W08
	.byte		N52   , As1 , v060
	.byte	W02
	.byte	W48
	.byte	W01
	.byte		N48   , Fs2 , v056
	.byte	W44
	.byte	W03
	.byte	W01
	.byte		        As1 
	.byte	W44
	.byte	W03
	.byte		        Fs2 
	.byte	W48
	.byte	W01
	.byte		        As1 , v060
	.byte	W48
	.byte		        Fs2 , v056
	.byte	W44
	.byte	W03
	.byte	W02
	.byte		        As1 , v060
	.byte	W44
	.byte	W03
	.byte		        Fs2 
	.byte	W44
	.byte	W03
	.byte		N36   , As1 , v056
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_duskull_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_duskull_2:  @ 0x08697A0B
	.byte	KEYSH , mus_bonus_field_duskull_key+0
mus_bonus_field_duskull_2_B1:
	.byte		VOICE , 7
	.byte		VOL   , 91*mus_bonus_field_duskull_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	W01
	.byte		N03   , En4 , v064
	.byte	W08
	.byte		N04   , Fn4 , v072
	.byte	W03
	.byte	W06
	.byte		N24   , Fs4 , v064
	.byte	W22
	.byte		N05   , Fn4 , v056
	.byte	W08
	.byte		N04   , Cn4 , v064
	.byte	W07
	.byte		        Cs4 , v068
	.byte	W10
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N05   , Cs4 , v052
	.byte	W07
	.byte		N04   , An3 , v068
	.byte	W08
	.byte		N03   , As3 
	.byte	W04
	.byte	W04
	.byte		N08   , Cn4 
	.byte	W07
	.byte		N04   , As3 , v064
	.byte	W08
	.byte		        Fn3 , v068
	.byte	W08
	.byte		        Fs3 , v064
	.byte	W07
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 , v072
	.byte	W09
	.byte		N23   , Fn3 , v060
	.byte	W28
	.byte	W01
	.byte		N03   , En3 , v064
	.byte	W08
	.byte		N04   , Fn3 , v060
	.byte	W08
	.byte		N05   , Fs3 , v072
	.byte	W07
	.byte		N03   , Fn3 , v076
	.byte	W08
	.byte		        An3 , v056
	.byte	W07
	.byte		        Fn3 , v064
	.byte	W07
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N05   , Ds4 , v068
	.byte	W08
	.byte		N04   , Cn4 , v060
	.byte	W07
	.byte		        Fs4 , v068
	.byte	W08
	.byte		N03   , Fn4 
	.byte	W08
	.byte		N04   , An4 
	.byte	W07
	.byte		        Fn4 
	.byte	W08
	.byte		N06   , Cn5 , v072
	.byte	W05
	.byte	W10
	.byte		N05   , An4 , v064
	.byte	W09
	.byte		        Fs4 
	.byte	W14
	.byte		N03   , Fn4 
	.byte	W09
	.byte		N24   , Fn4 , v056
	.byte	W36
	.byte		N05   , En4 , v060
	.byte	W08
	.byte		N03   , Fn4 , v068
	.byte	W08
	.byte		N24   , Fs4 , v060
	.byte	W02
	.byte	W21
	.byte		N05   , Fn4 , v052
	.byte	W08
	.byte		        Cn4 , v068
	.byte	W08
	.byte		        Cs4 , v064
	.byte	W08
	.byte		N24   , Ds4 , v068
	.byte	W23
	.byte		N05   , Cs4 , v048
	.byte	W08
	.byte		N04   , An3 , v068
	.byte	W07
	.byte		        As3 , v072
	.byte	W08
	.byte		N09   , Cn4 , v064
	.byte	W05
	.byte	W03
	.byte		N04   , As3 , v060
	.byte	W08
	.byte		N03   , Fn3 , v068
	.byte	W09
	.byte		N07   , Fs3 , v060
	.byte	W17
	.byte		N09   , Fn3 
	.byte	W08
	.byte		N28   , En3 
	.byte	W36
	.byte	W03
	.byte		N09   , En3 , v068
	.byte	W09
	.byte		N18   , Fn3 , v052
	.byte	W03
	.byte	W16
	.byte		N03   , Cn3 , v056
	.byte	W09
	.byte		N05   , Cn3 , v060
	.byte	W15
	.byte		N04   , Fn3 , v056
	.byte	W08
	.byte		N17   , Fn3 , v064
	.byte	W17
	.byte		N03   , Ds3 , v060
	.byte	W08
	.byte		N09
	.byte	W08
	.byte		        Cs3 , v064
	.byte	W08
	.byte		N04   , Cn3 , v056
	.byte	W07
	.byte	W10
	.byte		N08   , Fn3 , v064
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Fn3 , v064
	.byte	W08
	.byte		N09   , An3 , v060
	.byte	W08
	.byte		N10   , Cn4 
	.byte	W09
	.byte		N22   , Fn3 
	.byte	W44
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W80
	.byte	W01
	.byte		N03   , En4 , v056
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W07
	.byte	W01
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N04   , Fn4 , v052
	.byte	W08
	.byte		N03   , Cn4 , v064
	.byte	W07
	.byte		        Cs4 , v068
	.byte	W09
	.byte		N24   , Ds4 , v064
	.byte	W23
	.byte		N04   , Cs4 , v052
	.byte	W08
	.byte		N03   , An3 , v064
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N09   , Cn4 , v060
	.byte	W08
	.byte		N03   , As3 , v064
	.byte	W07
	.byte		        Fn3 , v060
	.byte	W08
	.byte		        Fs3 , v068
	.byte	W08
	.byte		        Fn3 , v064
	.byte	W09
	.byte		        En4 , v060
	.byte	W09
	.byte		N24   , Fn3 
	.byte	W32
	.byte	W01
	.byte		N03
	.byte	W08
	.byte		        Fn3 , v056
	.byte	W06
	.byte	W03
	.byte		N07   , Fs3 , v064
	.byte	W08
	.byte		N03   , Fn3 , v056
	.byte	W07
	.byte		        An3 , v060
	.byte	W08
	.byte		        Fn3 , v064
	.byte	W08
	.byte		        Cn4 
	.byte	W07
	.byte		        An3 
	.byte	W08
	.byte		        Ds4 , v068
	.byte	W08
	.byte		        Cn4 , v064
	.byte	W08
	.byte		        Fs4 , v068
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N02   , An4 , v072
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W07
	.byte	W01
	.byte		N05   , Cn5 , v060
	.byte	W17
	.byte		N03   , An4 , v068
	.byte	W08
	.byte		N05   , En4 , v060
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N21   , Fn4 
	.byte	W28
	.byte	W01
	.byte		N04   , En4 , v064
	.byte	W08
	.byte		N03   , Fn4 , v072
	.byte	W09
	.byte		N24   , Fs4 , v060
	.byte	W23
	.byte		N03   , Fn4 , v056
	.byte	W08
	.byte		        Cn4 , v068
	.byte	W07
	.byte		N04   , Cs4 , v072
	.byte	W09
	.byte		N24   , Ds4 , v064
	.byte	W23
	.byte		N04   , Cs4 , v052
	.byte	W08
	.byte		N03   , An3 , v072
	.byte	W07
	.byte		        As3 , v068
	.byte	W08
	.byte		N09   , Cn4 
	.byte	W03
	.byte	W05
	.byte		N03   , As3 , v060
	.byte	W07
	.byte		        Fn3 , v064
	.byte	W08
	.byte		N05   , Fs3 
	.byte	W16
	.byte		N08   , Fn3 , v068
	.byte	W08
	.byte		N28   , En3 
	.byte	W36
	.byte	W02
	.byte		N09   , En3 , v064
	.byte	W09
	.byte		N11   , Fn3 
	.byte	W05
	.byte	W12
	.byte		N03
	.byte	W09
	.byte		        Fn3 , v060
	.byte	W07
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W16
	.byte		        Cn4 , v056
	.byte	W07
	.byte		        An3 , v060
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 , v064
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N08   , Fn4 , v068
	.byte	W05
	.byte	W10
	.byte		N03   , Cs4 , v064
	.byte	W09
	.byte		N06   , As3 
	.byte	W15
	.byte		N11   , Dn4 , v068
	.byte	W09
	.byte		N06   , Ds4 , v064
	.byte	W17
	.byte		N09   , En4 , v068
	.byte	W08
	.byte		N02   , Fn4 , v060
	.byte	W17
	.byte		N03   , An4 , v076
	.byte	W09
	.byte		N07   , As4 , v072
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_duskull_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_duskull_3:  @ 0x08697C1D
	.byte	KEYSH , mus_bonus_field_duskull_key+0
mus_bonus_field_duskull_3_B1:
	.byte		VOICE , 52
	.byte		VOL   , 85*mus_bonus_field_duskull_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W14
	.byte		N01   , Cs3 , v048
	.byte		N02   , Fn3 , v060
	.byte	W06
	.byte		N03   , Fn3 , v048
	.byte	W01
	.byte		        Cs3 , v056
	.byte	W09
	.byte		N04   , Cs3 , v052
	.byte		N03   , Fn3 , v060
	.byte	W24
	.byte	W03
	.byte		N28   , Cs3 , v040
	.byte	W01
	.byte		        En3 , v056
	.byte	W36
	.byte	W02
	.byte	W08
	.byte		N03   , Cs3 
	.byte	W01
	.byte		N02   , Fn3 , v048
	.byte	W07
	.byte		N03   , Cs3 , v044
	.byte		N03   , Fn3 , v052
	.byte	W08
	.byte		        Cs3 , v044
	.byte		N03   , Fn3 , v056
	.byte	W32
	.byte	W03
	.byte		N24   , Cs3 , v044
	.byte		N23   , En3 , v048
	.byte	W36
	.byte	W01
	.byte	W12
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 , v052
	.byte	W07
	.byte		N03
	.byte	W01
	.byte		        Cs3 , v044
	.byte	W08
	.byte		        Cs3 , v036
	.byte		N03   , Fn3 , v056
	.byte	W32
	.byte		N23   , Cs3 , v044
	.byte		N22   , En3 , v048
	.byte	W36
	.byte	W10
	.byte		N03   , Cs3 
	.byte		N01   , Fn3 , v040
	.byte	W07
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 , v056
	.byte	W09
	.byte		        Cs3 , v048
	.byte		N03   , Fn3 , v056
	.byte	W30
	.byte	W01
	.byte		N24   , Cs3 , v044
	.byte		N23   , En3 , v048
	.byte	W36
	.byte	W03
	.byte	W06
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 , v052
	.byte	W08
	.byte		N03
	.byte	W01
	.byte		N02   , Cn3 , v044
	.byte	W08
	.byte		        Cn3 , v048
	.byte		N03   , Ds3 , v060
	.byte	W30
	.byte		N24   , Fn3 , v056
	.byte	W01
	.byte		N20   , An2 , v028
	.byte	W42
	.byte	W02
	.byte		N02   , Cn3 , v052
	.byte		N03   , Ds3 , v056
	.byte	W07
	.byte		        Cn3 , v044
	.byte		N04   , Ds3 , v048
	.byte	W08
	.byte		N03   , Cn3 , v052
	.byte		N03   , Ds3 , v048
	.byte	W32
	.byte	W02
	.byte		N22   , An2 , v044
	.byte		N22   , Fn3 , v052
	.byte	W44
	.byte	W01
	.byte	W05
	.byte		N01   , Cs3 , v044
	.byte		N02   , Fn3 , v056
	.byte	W08
	.byte		N03   , Cs3 
	.byte		N02   , Fn3 
	.byte	W08
	.byte		        Cs3 , v048
	.byte		N03   , Fn3 , v052
	.byte	W32
	.byte		N22   , Cs3 , v044
	.byte		N22   , En3 , v048
	.byte	W42
	.byte	W01
	.byte	W03
	.byte		N02   , Cs3 , v040
	.byte		N02   , Fn3 , v044
	.byte	W08
	.byte		N03   , Cs3 , v052
	.byte	W01
	.byte		N01   , Fn3 , v048
	.byte	W07
	.byte		N03   , Cs3 , v044
	.byte		N03   , Fn3 , v052
	.byte	W32
	.byte	W03
	.byte		N28   , Cs3 , v048
	.byte		N28   , En3 
	.byte	W42
	.byte	W06
	.byte		N03   , Cn3 , v044
	.byte	W01
	.byte		N02   , Ds3 , v048
	.byte	W07
	.byte		N03   , Cn3 , v052
	.byte		N03   , Ds3 , v056
	.byte	W09
	.byte		        Cn3 , v052
	.byte		N03   , Ds3 , v060
	.byte	W32
	.byte	W02
	.byte		        An2 , v056
	.byte		N03   , Fn3 
	.byte	W07
	.byte		N02   , Fn3 , v048
	.byte	W01
	.byte		        An2 , v052
	.byte	W07
	.byte		N04   , Fn3 , v056
	.byte	W01
	.byte		N03   , An2 
	.byte	W23
	.byte	W10
	.byte		        Cn3 , v048
	.byte		N03   , Ds3 , v056
	.byte	W07
	.byte		        Cn3 , v044
	.byte		N03   , Ds3 , v052
	.byte	W09
	.byte		        Cn3 
	.byte		N03   , Ds3 , v056
	.byte	W68
	.byte	W02
	.byte	W72
	.byte	W02
	.byte		N13   , Cn3 , v040
	.byte		N24   , Ds3 , v060
	.byte	W22
	.byte	W01
	.byte		N08   , Cs3 , v056
	.byte	W01
	.byte		N07   , As2 , v044
	.byte	W66
	.byte	W01
	.byte		N23   , Ds3 , v064
	.byte		N23   , Fs3 
	.byte	W23
	.byte		N07   , Cs3 , v040
	.byte		N08   , Fn3 , v056
	.byte	W04
	.byte	W66
	.byte	W01
	.byte		N24   , Fn3 , v060
	.byte	W01
	.byte		N15   , Cn3 , v048
	.byte	W23
	.byte		N09   , As3 , v060
	.byte	W01
	.byte		N07   , Cs3 , v040
	.byte	W04
	.byte	W66
	.byte		N15   , An3 , v064
	.byte	W01
	.byte		N11   , Cn3 , v052
	.byte	W24
	.byte		N13   , Cs3 
	.byte		N13   , As3 , v064
	.byte	W05
	.byte	W68
	.byte	W01
	.byte		N21   , Fn3 , v060
	.byte	W01
	.byte		N15   , Cs3 , v052
	.byte	W15
	.byte		N03   , Cn3 , v048
	.byte		N08   , Ds3 , v052
	.byte	W09
	.byte		N09   , As2 , v048
	.byte		N10   , Cs3 , v056
	.byte	W02
	.byte	W68
	.byte		N24   , Fs3 , v064
	.byte	W01
	.byte		        Cn3 , v056
	.byte	W24
	.byte		N11   , Fn3 , v052
	.byte	W01
	.byte		N10   , Cs3 , v048
	.byte	W02
	.byte	W68
	.byte	W01
	.byte		N15   , Fn3 , v064
	.byte	W01
	.byte		N12   , Dn3 , v040
	.byte	W17
	.byte		N10   , Bn3 , v060
	.byte	W08
	.byte		N09   , Ds3 , v048
	.byte		N09   , As3 , v064
	.byte	W01
	.byte	W72
	.byte	W01
	.byte		N16   , An2 , v056
	.byte		N17   , Fn3 , v064
	.byte	W23
	.byte	W09
	.byte		N01   , As2 , v052
	.byte		N02   , Cs3 , v060
	.byte	W07
	.byte		        As2 , v064
	.byte		N03   , Cs3 , v048
	.byte	W07
	.byte		N04   , As2 , v060
	.byte	W01
	.byte		N05   , Cs3 
	.byte	W32
	.byte	W03
	.byte		N24   , Cs3 , v052
	.byte		N24   , En3 , v060
	.byte	W36
	.byte	W01
	.byte	W08
	.byte		N03   , As2 , v052
	.byte		N03   , Cs3 , v056
	.byte	W07
	.byte		N04   , Cs3 , v052
	.byte	W01
	.byte		N03   , As2 
	.byte	W07
	.byte		N05   , Cs3 , v056
	.byte	W01
	.byte		N04   , As2 , v060
	.byte	W32
	.byte	W01
	.byte		N24   , Cs3 , v056
	.byte		N24   , En3 , v064
	.byte	W36
	.byte	W03
	.byte	W08
	.byte		N02   , An2 , v060
	.byte		N03   , Ds3 
	.byte	W09
	.byte		N01   , An2 , v056
	.byte		N03   , Ds3 , v060
	.byte	W08
	.byte		N01   , An2 
	.byte		N04   , Ds3 
	.byte	W32
	.byte		N24   , Cn3 , v064
	.byte		N24   , Fn3 , v076
	.byte	W36
	.byte	W03
	.byte	W08
	.byte		N01   , An2 , v064
	.byte		N03   , Fn3 
	.byte	W07
	.byte		N02   , An2 , v060
	.byte		N03   , Fn3 , v052
	.byte	W09
	.byte		        An2 , v068
	.byte		N04   , Fn3 , v064
	.byte	W48
	.byte	W01
	.byte		N19   , Cn3 
	.byte		N19   , Fn3 , v072
	.byte	W23
	.byte	W09
	.byte		N02   , Cs3 , v056
	.byte		N03   , Fn3 , v064
	.byte	W07
	.byte		N02   , Cs3 , v052
	.byte		N03   , Fn3 
	.byte	W08
	.byte		N04   , Cs3 , v056
	.byte		N04   , Fn3 , v052
	.byte	W30
	.byte		N22   , As2 
	.byte		N23   , En3 , v060
	.byte	W42
	.byte	W05
	.byte		N02   , Cs3 , v056
	.byte		N02   , Fn3 , v060
	.byte	W07
	.byte		N01   , Cs3 
	.byte		N02   , Fn3 
	.byte	W07
	.byte		N03
	.byte	W01
	.byte		N05   , Cs3 , v056
	.byte	W32
	.byte		N22   , As2 , v048
	.byte		N24   , En3 , v060
	.byte	W44
	.byte	W03
	.byte		N02   , Cn3 , v048
	.byte		N03   , Ds3 , v056
	.byte	W08
	.byte		N02   , Cn3 , v048
	.byte		N03   , Ds3 , v060
	.byte	W08
	.byte		        Cn3 , v056
	.byte		N04   , Ds3 , v060
	.byte	W32
	.byte		N22   , Fn3 , v068
	.byte	W01
	.byte		        Cn3 , v056
	.byte	W44
	.byte	W02
	.byte		N01   , Cs3 , v052
	.byte		N03   , Fn3 , v064
	.byte	W08
	.byte		        Cs3 , v060
	.byte		N03   , Fn3 
	.byte	W09
	.byte		        Cs3 
	.byte		N03   , Fn3 
	.byte	W15
	.byte		N10   , Dn3 , v080
	.byte	W08
	.byte		        Ds3 , v064
	.byte	W18
	.byte		N09   , En3 , v076
	.byte	W08
	.byte		N08   , Fn3 , v072
	.byte	W08
	.byte		N09   , An2 , v064
	.byte	W09
	.byte		        Fn3 , v072
	.byte	W09
	.byte		N14   , As2 , v068
	.byte	W02
	.byte	W42
	.byte		N48   , Cs3 , v044
	.byte	W01
	.byte		        En3 
	.byte	W52
	.byte	W01
	.byte		N30   , Fn3 , v048
	.byte	W01
	.byte		        As2 , v040
	.byte	W32
	.byte	W02
	.byte		N03   , Fn3 , v056
	.byte	W06
	.byte		N09   , Fn3 , v048
	.byte	W02
	.byte		N06   , As2 , v024
	.byte	W08
	.byte		N24   , Cs3 , v044
	.byte		N24   , En3 , v052
	.byte	W30
	.byte	W01
	.byte		N03   , Cs3 
	.byte		N04   , En3 , v048
	.byte	W08
	.byte		N09   , Cs3 
	.byte		N07   , En3 , v052
	.byte	W06
	.byte	W02
	.byte		N28   , As2 , v044
	.byte		N28   , Fn3 , v056
	.byte	W32
	.byte	W01
	.byte		N03   , As2 , v044
	.byte		N02   , Fn3 , v048
	.byte	W08
	.byte		N08   , As2 , v044
	.byte		N09   , Fn3 , v060
	.byte	W08
	.byte		N24   , En3 , v048
	.byte	W01
	.byte		        Cs3 
	.byte	W30
	.byte		N03   , En3 
	.byte	W01
	.byte		N01   , Cs3 , v044
	.byte	W07
	.byte		N11   , Cs3 , v052
	.byte		N08   , En3 , v044
	.byte	W06
	.byte	W02
	.byte		N24   , Fn3 , v052
	.byte	W01
	.byte		        As2 , v040
	.byte	W32
	.byte		N03   , As2 , v052
	.byte		N02   , Fn3 , v048
	.byte	W07
	.byte		N08   , As2 
	.byte		N08   , Fn3 , v056
	.byte	W08
	.byte		N24   , En3 , v052
	.byte	W01
	.byte		        Cs3 , v044
	.byte	W30
	.byte	W01
	.byte		N03   , Cs3 , v048
	.byte		N02   , En3 , v044
	.byte	W07
	.byte		N13   , Cs3 , v040
	.byte		N08   , En3 , v048
	.byte	W07
	.byte	W02
	.byte		N28   , Fn3 
	.byte	W01
	.byte		        As2 , v036
	.byte	W92
	.byte	W01
	.byte	GOTO
	 .word	mus_bonus_field_duskull_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_duskull_4:  @ 0x08697F54
	.byte	KEYSH , mus_bonus_field_duskull_key+0
mus_bonus_field_duskull_4_B1:
	.byte		VOICE , 11
	.byte		VOL   , 86*mus_bonus_field_duskull_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N36   , Fn0 , v080
	.byte		N36   , Fn1 
	.byte	W44
	.byte	W03
	.byte		        Fn1 , v088
	.byte	W01
	.byte		        Fn0 , v084
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
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
	 .word	mus_bonus_field_duskull_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_duskull:  @ 0x08697F90
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_duskull_pri	@ Priority
	.byte	mus_bonus_field_duskull_rev	@ Reverb

	.word	mus_bonus_field_duskull_grp

	.word	mus_bonus_field_duskull_0
	.word	mus_bonus_field_duskull_1
	.word	mus_bonus_field_duskull_2
	.word	mus_bonus_field_duskull_3
	.word	mus_bonus_field_duskull_4
@ 0x08697FAC
