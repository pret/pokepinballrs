	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_kecleon_grp, gUnknown_08532808
	.equ	mus_bonus_field_kecleon_pri, 0
	.equ	mus_bonus_field_kecleon_rev, reverb_set+50
	.equ	mus_bonus_field_kecleon_mvl, 127
	.equ	mus_bonus_field_kecleon_key, 0
	.equ	mus_bonus_field_kecleon_tbs, 1
	.equ	mus_bonus_field_kecleon_exg, 0
	.equ	mus_bonus_field_kecleon_cmp, 1

	.section .rodata
	.global	mus_bonus_field_kecleon
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_kecleon_0:  @ 0x08696F20
	.byte	KEYSH , mus_bonus_field_kecleon_key+0
mus_bonus_field_kecleon_0_B1:
	.byte	TEMPO , 204*mus_bonus_field_kecleon_tbs/2
	.byte		VOICE , 5
	.byte		VOL   , 105*mus_bonus_field_kecleon_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N78   , An1 , v068
	.byte	W24
	.byte		N03   , En2 , v056
	.byte	W01
	.byte		N05   , Cs3 , v060
	.byte	W24
	.byte		N04   , En2 , v056
	.byte		N07   , Cs3 , v060
	.byte	W23
	.byte	W01
	.byte		N72   , Ds2 , v072
	.byte	W24
	.byte	W01
	.byte		N44   , Cn3 , v064
	.byte	W01
	.byte		N48   , Fn2 , v052
	.byte	W44
	.byte	W01
	.byte	W04
	.byte		N44   , An1 , v060
	.byte	W23
	.byte		N04   , Cs3 , v064
	.byte	W01
	.byte		N03   , En2 , v060
	.byte	W23
	.byte		N03
	.byte		N05   , Cs3 , v068
	.byte	W21
	.byte	W02
	.byte		N72   , Ds2 , v064
	.byte	W24
	.byte	W01
	.byte		N48   , Cn3 , v056
	.byte	W01
	.byte		        Fn2 
	.byte	W44
	.byte	W04
	.byte		N72   , An1 , v072
	.byte	W23
	.byte		N04   , Cs3 , v060
	.byte	W01
	.byte		N05   , En2 
	.byte	W22
	.byte		N07   , En2 , v056
	.byte	W01
	.byte		N06   , Cs3 , v064
	.byte	W21
	.byte	W04
	.byte		N76   , Ds2 , v072
	.byte	W24
	.byte	W01
	.byte		N44   , Cn3 , v064
	.byte	W01
	.byte		N48   , Fn2 , v052
	.byte	W42
	.byte	W06
	.byte		N76   , An1 , v072
	.byte	W24
	.byte		N04   , Cs3 , v064
	.byte	W01
	.byte		        En2 , v060
	.byte	W23
	.byte		N03
	.byte		N05   , Cs3 , v068
	.byte	W18
	.byte	W07
	.byte		N72   , Ds2 
	.byte	W24
	.byte	W01
	.byte		N44   , Cn3 , v064
	.byte	W01
	.byte		N48   , Fn2 , v056
	.byte	W36
	.byte	W03
	.byte	W09
	.byte		N72   , An1 , v068
	.byte	W22
	.byte		N07   , Cs3 , v056
	.byte	W01
	.byte		N05   , En2 
	.byte	W24
	.byte	W01
	.byte		        Cs3 , v064
	.byte	W01
	.byte		N03   , En2 , v056
	.byte	W14
	.byte	W10
	.byte		N68   , Ds2 , v064
	.byte	W24
	.byte		N42   , Cn3 
	.byte	W01
	.byte		N44   , Fn2 , v052
	.byte	W36
	.byte	W01
	.byte	W08
	.byte		N72   , An1 , v060
	.byte	W24
	.byte		N06   , En2 
	.byte		N07   , Cs3 
	.byte	W24
	.byte	W02
	.byte		N02   , En2 , v056
	.byte		N03   , Cs3 , v060
	.byte	W14
	.byte	W09
	.byte		N72   , Ds2 , v068
	.byte	W24
	.byte	W01
	.byte		N36   , Cn3 , v064
	.byte	W01
	.byte		N48   , Fn2 , v056
	.byte	W36
	.byte	W01
	.byte	W10
	.byte		N72   , An1 , v068
	.byte	W22
	.byte		N03   , Cs3 , v064
	.byte	W02
	.byte		        En2 , v056
	.byte	W23
	.byte		N08
	.byte	W01
	.byte		N07   , Cs3 , v068
	.byte	W14
	.byte	W11
	.byte		N76   , Ds2 , v072
	.byte	W24
	.byte		N48   , Cn3 , v068
	.byte	W02
	.byte		        Fn2 , v052
	.byte	W32
	.byte	W03
	.byte	W15
	.byte		N72   , An1 , v064
	.byte	W23
	.byte		N06   , En2 , v060
	.byte	W01
	.byte		N04   , Cs3 , v064
	.byte	W24
	.byte		N03   , En2 
	.byte		N06   , Cs3 , v060
	.byte	W09
	.byte	W15
	.byte		N72   , Ds2 , v072
	.byte	W24
	.byte		N44   , Cn3 , v060
	.byte	W01
	.byte		N48   , Fn2 , v052
	.byte	W32
	.byte	W17
	.byte		N76   , An1 , v064
	.byte	W23
	.byte		N05   , Cs3 
	.byte	W01
	.byte		N04   , En2 , v060
	.byte	W23
	.byte		N08   , En2 , v064
	.byte	W01
	.byte		N06   , Cs3 , v060
	.byte	W07
	.byte	W17
	.byte		N72   , Ds2 , v068
	.byte	W24
	.byte	W01
	.byte		N42   , Cn3 , v064
	.byte	W01
	.byte		N48   , Fn2 , v056
	.byte	W28
	.byte	W01
	.byte	W19
	.byte		TIE   , An1 , v064
	.byte	W23
	.byte		N04   , Cs3 , v060
	.byte	W01
	.byte		        En2 , v052
	.byte	W23
	.byte		N07   , En2 , v056
	.byte		N06   , Cs3 , v060
	.byte	W06
	.byte	W18
	.byte		N72   , Ds2 , v072
	.byte	W24
	.byte		N48   , Cn3 , v068
	.byte	W01
	.byte		N42   , Fn2 , v060
	.byte	W03
	.byte		EOT   , An1 
	.byte	W24
	.byte	W02
	.byte	W21
	.byte		N72   , Dn2 , v072
	.byte	W24
	.byte		N04   , An2 , v064
	.byte	W01
	.byte		N07   , Fs2 , v056
	.byte	W22
	.byte		N08
	.byte	W01
	.byte		N04   , An2 , v064
	.byte	W03
	.byte	W20
	.byte		N68   , Cs2 , v072
	.byte	W23
	.byte		N44   , An2 , v076
	.byte	W01
	.byte		N52   , En2 , v064
	.byte	W28
	.byte	W20
	.byte		N72   , Cn2 
	.byte	W24
	.byte		N05   , An2 , v068
	.byte	W01
	.byte		N07   , Ds2 , v060
	.byte	W23
	.byte		N09   , Ds2 , v064
	.byte		N04   , An2 , v072
	.byte	W04
	.byte	W21
	.byte		N72   , Bn1 , v068
	.byte	W24
	.byte		N42   , Dn2 , v060
	.byte		N42   , Gs2 , v072
	.byte	W24
	.byte	W03
	.byte	W22
	.byte		N72   , Cs2 , v068
	.byte	W23
	.byte		N07   , En2 , v064
	.byte		N06   , An2 , v072
	.byte	W24
	.byte		        En2 , v056
	.byte		N06   , An2 , v072
	.byte	W03
	.byte	W20
	.byte		N76   , Cn2 , v076
	.byte	W24
	.byte		N48   , Ds2 , v068
	.byte		N36   , An2 , v072
	.byte	W28
	.byte	W21
	.byte		N68   , Bn1 
	.byte	W23
	.byte		N05   , An2 , v068
	.byte	W01
	.byte		N09   , Dn2 , v056
	.byte	W23
	.byte		N04   , An2 , v072
	.byte	W01
	.byte		N08   , Dn2 , v040
	.byte	W03
	.byte	W20
	.byte		N68   , En1 , v060
	.byte	W23
	.byte		N40   , Gs2 , v072
	.byte	W01
	.byte		N42   , En2 , v068
	.byte	W28
	.byte	W22
	.byte		N72   , An1 , v080
	.byte	W24
	.byte	W02
	.byte		N03   , En2 , v056
	.byte		N03   , Cs3 , v060
	.byte	W22
	.byte		N06   , En2 , v056
	.byte		N04   , Cs3 , v060
	.byte	W02
	.byte	W21
	.byte		N72   , Ds2 , v076
	.byte	W23
	.byte		N44   , Cn3 , v060
	.byte	W01
	.byte		N48   , Fn2 
	.byte	W24
	.byte	W03
	.byte	W22
	.byte		N72   , An1 , v076
	.byte	W23
	.byte		N05   , Cs3 , v064
	.byte	W01
	.byte		N03   , En2 , v056
	.byte	W22
	.byte		N06   , Cs3 , v064
	.byte	W01
	.byte		N03   , En2 , v056
	.byte	W03
	.byte	W20
	.byte		N72   , Ds2 , v068
	.byte	W24
	.byte	W01
	.byte		N36   , Cn3 , v064
	.byte	W02
	.byte		N44   , Fn2 , v056
	.byte	W24
	.byte	W01
	.byte	W21
	.byte		N72   , An1 , v068
	.byte	W24
	.byte		N06   , En2 , v060
	.byte		N05   , Cs3 
	.byte	W23
	.byte		N02   , En2 , v056
	.byte		N07   , Cs3 , v064
	.byte	W04
	.byte	W18
	.byte		N68   , Ds2 , v072
	.byte	W23
	.byte		N44   , Cn3 
	.byte	W02
	.byte		        Fn2 , v056
	.byte	W28
	.byte	W01
	.byte	W16
	.byte		N72   , An1 , v068
	.byte	W24
	.byte		N05   , En2 , v056
	.byte		N07   , Cs3 , v060
	.byte	W23
	.byte		N06   , En2 
	.byte		N06   , Cs3 , v064
	.byte	W09
	.byte	W14
	.byte		N76   , Ds2 , v076
	.byte	W24
	.byte		N48   , Fn2 , v056
	.byte		N52   , Cn3 , v072
	.byte	W32
	.byte	W02
	.byte	W15
	.byte		N68   , An1 , v064
	.byte	W23
	.byte		N05   , Cs3 , v052
	.byte	W01
	.byte		N02   , En2 , v056
	.byte	W07
	.byte		N04   , En3 , v052
	.byte	W05
	.byte		N09   , Cs3 , v060
	.byte	W09
	.byte		N02   , En2 , v052
	.byte		N02   , An2 , v060
	.byte	W12
	.byte	W10
	.byte		N76   , Ds2 , v072
	.byte	W24
	.byte	W01
	.byte		N48   , Fn2 , v056
	.byte		N48   , Cn3 , v072
	.byte	W36
	.byte	W01
	.byte	W13
	.byte		N66   , An1 , v068
	.byte	W21
	.byte		N03   , Cs3 , v052
	.byte	W02
	.byte		N05   , En2 , v060
	.byte	W06
	.byte		N06   , En3 , v040
	.byte	W05
	.byte		N10   , Cs3 , v056
	.byte	W09
	.byte		N03   , En2 , v052
	.byte		N03   , An2 , v064
	.byte	W16
	.byte	W07
	.byte		N68   , Ds2 , v072
	.byte	W23
	.byte		N44   , Cn3 , v068
	.byte	W01
	.byte		N48   , Fn2 , v064
	.byte	W40
	.byte	W01
	.byte	W06
	.byte		N76   , An1 , v068
	.byte	W24
	.byte		N06   , En2 , v064
	.byte		N03   , Cs3 
	.byte	W23
	.byte		N08   , En2 
	.byte		N05   , Cs3 , v060
	.byte	W19
	.byte	W06
	.byte		N68   , Ds2 , v076
	.byte	W23
	.byte		N36   , Cn3 , v072
	.byte	W01
	.byte		N44   , Fn2 , v060
	.byte	W42
	.byte	W03
	.byte		N76   , An1 , v068
	.byte	W24
	.byte	W01
	.byte		N07   , Cs3 , v064
	.byte	W01
	.byte		N06   , En2 
	.byte	W22
	.byte		N08   , Cs3 
	.byte	W01
	.byte		N03   , En2 , v060
	.byte	W20
	.byte	W02
	.byte		N72   , Ds2 , v076
	.byte	W24
	.byte	W01
	.byte		N48   , Fn2 , v060
	.byte		N40   , Cn3 , v064
	.byte	W44
	.byte	W01
	.byte	W02
	.byte		N72   , An1 , v068
	.byte	W22
	.byte		N06   , Cs3 
	.byte	W01
	.byte		N03   , En2 , v060
	.byte	W23
	.byte		N07   , En2 , v064
	.byte		N06   , Cs3 , v068
	.byte	W23
	.byte		N72   , Ds2 , v076
	.byte	W01
	.byte	W21
	.byte		N44   , Cn3 , v068
	.byte	W01
	.byte		N48   , Fn2 , v060
	.byte	W48
	.byte	W01
	.byte		N72   , An1 , v072
	.byte	W01
	.byte	W22
	.byte		N04   , En2 , v060
	.byte		N06   , Cs3 , v064
	.byte	W22
	.byte		        En2 , v060
	.byte		N07   , Cs3 , v064
	.byte	W23
	.byte		N68   , Ds2 , v068
	.byte	W05
	.byte	W19
	.byte		N40   , Cn3 , v064
	.byte	W01
	.byte		N44   , Fn2 , v056
	.byte	W44
	.byte	W02
	.byte		N72   , Dn2 , v072
	.byte	W06
	.byte	W18
	.byte		N08   , Fs2 , v060
	.byte		N06   , An2 , v068
	.byte	W23
	.byte		N04   , Fs2 , v048
	.byte		N06   , An2 , v068
	.byte	W22
	.byte		N72   , Ds2 , v076
	.byte	W09
	.byte	W13
	.byte		N44   , Cn3 , v072
	.byte	W02
	.byte		N48   , An2 , v068
	.byte	W44
	.byte	W02
	.byte		N72   , En2 , v076
	.byte	W11
	.byte	W12
	.byte		N07   , Cs3 , v068
	.byte	W01
	.byte		N06   , An2 , v064
	.byte	W23
	.byte		N09   , An2 , v060
	.byte		N06   , Cs3 , v072
	.byte	W22
	.byte		N72   , Fs2 , v068
	.byte	W14
	.byte	W10
	.byte		N44   , Fs3 , v076
	.byte	W01
	.byte		N24   , As2 , v064
	.byte	W48
	.byte		N68   , Bn1 
	.byte	W13
	.byte	W09
	.byte		N08   , Fs2 , v060
	.byte	W02
	.byte		N04   , Dn3 , v036
	.byte	W23
	.byte		N22   , Fs2 , v056
	.byte		N07   , Dn3 , v060
	.byte	W23
	.byte		N72   , En2 , v064
	.byte	W15
	.byte	W07
	.byte		N44   , En3 , v068
	.byte	W02
	.byte		N32   , Gs2 , v064
	.byte	W44
	.byte	W03
	.byte		N60   , An1 , v072
	.byte	W16
	.byte	W07
	.byte		N04   , En2 , v060
	.byte		N06   , Cs3 
	.byte	W23
	.byte		N07
	.byte	W01
	.byte		N10   , En2 
	.byte	W23
	.byte		N72   , Ds2 , v076
	.byte	W18
	.byte	W06
	.byte		N44   , An2 , v068
	.byte		N48   , Cn3 
	.byte	W44
	.byte	W03
	.byte		N72   , An1 , v064
	.byte	W19
	.byte	W05
	.byte		N07   , Cs3 , v056
	.byte	W01
	.byte		N06   , En2 , v060
	.byte	W24
	.byte		N06
	.byte		N06   , Cs3 , v064
	.byte	W23
	.byte		N78   , Ds2 , v068
	.byte	W19
	.byte	W06
	.byte		N40   , An2 , v064
	.byte		N42   , Cn3 , v068
	.byte	W48
	.byte	W01
	.byte		N68   , Dn2 , v072
	.byte	W17
	.byte	W05
	.byte		N08   , Fs2 , v056
	.byte		N06   , An2 , v064
	.byte	W23
	.byte		N09   , Fs2 , v052
	.byte	W01
	.byte		N06   , An2 , v068
	.byte	W22
	.byte		N72   , Cs2 , v072
	.byte	W21
	.byte	W03
	.byte		N07   , An2 , v064
	.byte	W01
	.byte		N06   , En2 , v056
	.byte	W23
	.byte		N07   , An2 , v068
	.byte	W01
	.byte		N08   , En2 , v056
	.byte	W23
	.byte		N52   , Cn2 , v072
	.byte	W21
	.byte	W02
	.byte		N09   , Ds2 , v064
	.byte		N06   , An2 , v072
	.byte	W22
	.byte		N09   , Ds2 , v064
	.byte	W01
	.byte		N08   , An2 , v072
	.byte	W21
	.byte		N48   , En1 , v068
	.byte	W24
	.byte		N08   , En2 , v064
	.byte		N08   , Gs2 , v068
	.byte	W02
	.byte	W22
	.byte		N10   , En2 , v056
	.byte		N08   , Gs2 , v064
	.byte	W24
	.byte	W01
	.byte		N14   , Dn2 , v060
	.byte	W22
	.byte		N19   , Dn2 , v012
	.byte		N11   , En2 , v068
	.byte	W01
	.byte		N05   , An2 , v056
	.byte	W02
	.byte	W20
	.byte		N09   , En2 , v072
	.byte	W01
	.byte		N07   , An2 
	.byte	W22
	.byte		N56   , Cn2 , v068
	.byte	W24
	.byte		N07   , An2 , v076
	.byte	W01
	.byte		        Ds2 , v060
	.byte	W04
	.byte	W18
	.byte		N09   , Ds2 , v056
	.byte		N07   , An2 , v072
	.byte	W22
	.byte		N52   , Bn1 , v080
	.byte	W23
	.byte		N07   , En2 , v060
	.byte		N06   , An2 , v072
	.byte	W09
	.byte	W14
	.byte		N03   , En2 , v056
	.byte		N07   , An2 , v076
	.byte	W22
	.byte		N48   , En1 
	.byte	W23
	.byte		N08   , Dn2 , v060
	.byte		N07   , Gs2 , v068
	.byte	W13
	.byte	W11
	.byte		N06   , Dn2 , v052
	.byte		N07   , Gs2 , v064
	.byte	W22
	.byte		N72   , An1 , v076
	.byte	W23
	.byte		N07   , En2 , v056
	.byte	W16
	.byte	W07
	.byte		N14   , En2 , v040
	.byte		N05   , Cs3 , v056
	.byte	W23
	.byte		N68   , Ds2 , v072
	.byte	W24
	.byte		N72   , Cn3 , v060
	.byte	W01
	.byte		N44   , Fn2 , v056
	.byte	W17
	.byte	W28
	.byte		N72   , An1 , v068
	.byte	W24
	.byte		N06   , En2 , v052
	.byte	W01
	.byte		N05   , Cs3 
	.byte	W19
	.byte	W03
	.byte		        En2 , v044
	.byte	W01
	.byte		N04   , Cs3 , v048
	.byte	W22
	.byte		N72   , Ds2 , v068
	.byte	W24
	.byte		N48   , Cn3 , v060
	.byte	W01
	.byte		N44   , Fn2 , v052
	.byte	W21
	.byte	W24
	.byte	GOTO
	 .word	mus_bonus_field_kecleon_0_B1
	.byte	W01
	.byte		N09   , Cs3 , v064
	.byte	W02
	.byte		N11   , An1 , v040
	.byte		N09   , En2 , v052
	.byte	W44
	.byte	W01
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_kecleon_1:  @ 0x086973DD
	.byte	KEYSH , mus_bonus_field_kecleon_key+0
mus_bonus_field_kecleon_1_B1:
	.byte		VOICE , 5
	.byte		VOL   , 105*mus_bonus_field_kecleon_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W02
	.byte		N32   , En4 , v088
	.byte	W36
	.byte	W01
	.byte		N04   , Cs4 , v072
	.byte	W11
	.byte		N02   , An3 , v068
	.byte	W10
	.byte		N03   , En3 , v076
	.byte	W12
	.byte	W01
	.byte		N48   , Gn3 , v084
	.byte	W48
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		N07   , Gn3 , v068
	.byte	W05
	.byte		N11   , Fn3 , v060
	.byte	W10
	.byte		N44   , En3 , v076
	.byte	W02
	.byte	W42
	.byte		N03   , An3 , v068
	.byte	W11
	.byte		        Cs4 , v072
	.byte	W11
	.byte		N07   , En4 , v080
	.byte	W08
	.byte	W07
	.byte		N48   , Cn4 , v076
	.byte	W48
	.byte		N08   , Fn3 , v064
	.byte	W08
	.byte		        Gn3 , v060
	.byte	W05
	.byte		N13   , Fn3 , v044
	.byte	W04
	.byte	W08
	.byte		        En3 , v076
	.byte	W11
	.byte		N03   , An3 , v072
	.byte	W12
	.byte		        En3 , v064
	.byte	W11
	.byte		N04   , An3 
	.byte	W12
	.byte		N02   , En3 , v060
	.byte	W09
	.byte		N03   , An3 , v064
	.byte	W09
	.byte	W07
	.byte		N28   , Gn3 , v068
	.byte	W24
	.byte	W03
	.byte		N36   , Fn3 , v072
	.byte	W36
	.byte	W02
	.byte		N14   , Cn3 , v056
	.byte	W12
	.byte		N32   , En3 , v064
	.byte	W32
	.byte	W01
	.byte		N13   , Cs3 
	.byte	W11
	.byte		N14   , En3 , v052
	.byte	W11
	.byte		N18   , Cs3 , v060
	.byte	W05
	.byte	W09
	.byte		N48   , Cn3 , v048
	.byte	W60
	.byte	W03
	.byte	W32
	.byte		N03   , En3 , v068
	.byte	W22
	.byte		N07   , An3 
	.byte	W18
	.byte	W32
	.byte	W02
	.byte		N06   , Fn3 , v072
	.byte	W24
	.byte		N05   , Cn4 
	.byte	W14
	.byte	W32
	.byte	W03
	.byte		        En3 , v064
	.byte	W24
	.byte	W01
	.byte		N07   , Cs4 , v068
	.byte	W12
	.byte	W36
	.byte	W02
	.byte		N05   , An3 , v064
	.byte	W24
	.byte	W02
	.byte		N04   , Fn4 , v068
	.byte	W08
	.byte	W16
	.byte		N07   , En4 
	.byte	W36
	.byte	W01
	.byte		N05   , Cs4 , v076
	.byte	W10
	.byte		N06   , An3 , v060
	.byte	W09
	.byte	W36
	.byte	W03
	.byte		N07   , Cn4 
	.byte	W24
	.byte	W02
	.byte		        Fn3 
	.byte	W07
	.byte	W18
	.byte		N06   , En3 , v056
	.byte	W32
	.byte	W03
	.byte		N03   , An3 , v064
	.byte	W12
	.byte		N06   , Cs4 , v060
	.byte	W07
	.byte	W18
	.byte		N07   , Cn4 , v064
	.byte	W54
	.byte	W18
	.byte		N40   , An3 
	.byte	W36
	.byte	W01
	.byte		N13   , Gs3 , v068
	.byte	W13
	.byte		N24   , An3 , v064
	.byte	W04
	.byte	W20
	.byte		N48   , Bn3 , v068
	.byte	W44
	.byte	W03
	.byte		N16   , An3 , v064
	.byte	W05
	.byte	W19
	.byte		N36   , An3 , v060
	.byte	W36
	.byte	W02
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N32   , An3 , v068
	.byte	W03
	.byte	W44
	.byte	W02
	.byte		N24   , Dn4 
	.byte	W24
	.byte	W01
	.byte		N04   , An3 , v048
	.byte	W01
	.byte	W23
	.byte		N36   , An3 , v068
	.byte	W36
	.byte	W01
	.byte		N12   , Gs3 , v056
	.byte	W11
	.byte		N15   , An3 , v060
	.byte	W01
	.byte	W44
	.byte	W01
	.byte		N24   , En4 , v076
	.byte	W23
	.byte		        An3 , v068
	.byte	W04
	.byte	W21
	.byte		N36   , Dn4 , v072
	.byte	W32
	.byte	W01
	.byte		N13   , En4 , v060
	.byte	W11
	.byte		N24   , Fs4 , v076
	.byte	W07
	.byte	W18
	.byte		        En4 
	.byte	W24
	.byte	W01
	.byte		        Fs4 , v084
	.byte	W24
	.byte	W01
	.byte		N28   , Gs4 , v092
	.byte	W04
	.byte	W21
	.byte		N22   , An4 
	.byte	W48
	.byte	W03
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W44
	.byte	W01
	.byte		N12   , En4 , v072
	.byte	W10
	.byte		        Cs4 , v064
	.byte	W13
	.byte		N04   , An3 , v068
	.byte	W04
	.byte	W40
	.byte		N42   , Fn4 , v084
	.byte	W32
	.byte	W36
	.byte	W03
	.byte		N14   , En4 , v072
	.byte	W11
	.byte		N13   , Cs4 , v060
	.byte	W12
	.byte		N03   , An3 , v056
	.byte	W10
	.byte	W36
	.byte	W02
	.byte		N24   , Fn4 , v080
	.byte	W32
	.byte	W02
	.byte	W40
	.byte		N22   , An3 , v068
	.byte	W22
	.byte		N24   , En3 
	.byte	W10
	.byte	W13
	.byte		N56   , Fn3 , v072
	.byte	W56
	.byte	W03
	.byte	W32
	.byte	W02
	.byte		N24   , An3 
	.byte	W23
	.byte		        En3 , v064
	.byte	W15
	.byte	W09
	.byte		N52   , Fn3 , v060
	.byte	W60
	.byte	W03
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		N32   , En4 , v084
	.byte	W32
	.byte	W02
	.byte		N04   , Cs4 , v076
	.byte	W12
	.byte		N02   , An3 , v068
	.byte	W11
	.byte		N03   , En3 
	.byte	W14
	.byte		N44   , Gn3 , v076
	.byte	W01
	.byte	W44
	.byte	W01
	.byte		N06   , Fn3 , v060
	.byte	W06
	.byte		N07   , Gn3 , v056
	.byte	W06
	.byte		N10   , Fn3 , v060
	.byte	W09
	.byte		N32   , En3 , v072
	.byte	W06
	.byte	W30
	.byte	W01
	.byte		N04   , An3 , v064
	.byte	W12
	.byte		N07   , Cs4 , v060
	.byte	W11
	.byte		N03   , En4 , v064
	.byte	W14
	.byte		N44   , Cn4 
	.byte	W04
	.byte	W40
	.byte		N09   , Fn3 , v056
	.byte	W09
	.byte		N06   , Gn3 , v048
	.byte	W05
	.byte		N09   , Fn3 , v040
	.byte	W18
	.byte	W20
	.byte		N24   , Fs3 , v068
	.byte	W22
	.byte		N10   , An3 , v076
	.byte	W30
	.byte	W16
	.byte		        An3 , v064
	.byte	W11
	.byte		N12   , Cn4 , v072
	.byte	W11
	.byte		N11   , An3 , v068
	.byte	W08
	.byte		N07   , Cn4 , v076
	.byte	W24
	.byte	W02
	.byte	W13
	.byte		N24   , Cs4 , v084
	.byte	W23
	.byte		N08   , En4 , v076
	.byte	W36
	.byte	W11
	.byte		N11   , En4 , v080
	.byte	W09
	.byte		N14   , Gn4 , v068
	.byte	W12
	.byte		N12   , En4 
	.byte	W10
	.byte		N14   , Gn4 
	.byte	W13
	.byte		        Fs4 , v076
	.byte	W12
	.byte		N12   , En4 , v068
	.byte	W05
	.byte	W07
	.byte		N13   , Dn4 , v056
	.byte	W12
	.byte		N15   , Cs4 , v068
	.byte	W13
	.byte		N12   , Dn4 , v064
	.byte	W11
	.byte		N14   , Bn3 , v060
	.byte	W13
	.byte		N48   , Fs3 , v072
	.byte	W16
	.byte	W32
	.byte		N24   , Gs3 , v068
	.byte	W24
	.byte		N52   , An3 , v076
	.byte	W16
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W54
	.byte	W01
	.byte		N36   , Fs3 , v064
	.byte	W17
	.byte	W17
	.byte		N13   , Gs3 
	.byte	W12
	.byte		N24   , An3 , v072
	.byte	W23
	.byte		        En3 , v076
	.byte	W20
	.byte	W03
	.byte		        An3 , v068
	.byte	W24
	.byte		N28   , En3 
	.byte	W24
	.byte		N36   , Ds3 , v072
	.byte	W21
	.byte	W13
	.byte		N14   , An3 , v064
	.byte	W11
	.byte		N24   , Ds3 , v060
	.byte	W22
	.byte		N32   , Dn3 , v068
	.byte	W24
	.byte	W02
	.byte	W10
	.byte		N13   , En3 , v064
	.byte	W11
	.byte		        Fs3 , v072
	.byte	W10
	.byte		N06   , Gs3 , v068
	.byte	W36
	.byte	W02
	.byte		N12   , Fs3 , v076
	.byte	W03
	.byte	W06
	.byte		N14   , Gs3 
	.byte	W12
	.byte		N24   , An3 , v072
	.byte	W24
	.byte	W01
	.byte		        En3 , v076
	.byte	W24
	.byte	W01
	.byte		        An3 , v072
	.byte	W04
	.byte	W19
	.byte		N28   , En3 , v076
	.byte	W24
	.byte	W01
	.byte		        Ds3 
	.byte	W28
	.byte	W01
	.byte		N16   , An3 , v072
	.byte	W14
	.byte		N24   , Ds3 , v064
	.byte	W23
	.byte		N32   , Dn3 , v068
	.byte	W32
	.byte	W01
	.byte		N12   , En3 , v072
	.byte	W01
	.byte	W09
	.byte		        Fs3 
	.byte	W10
	.byte		N13   , Gs3 , v076
	.byte	W14
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cs4 
	.byte	W15
	.byte	W08
	.byte		N10   , An4 , v080
	.byte	W42
	.byte	W01
	.byte		N24   , Fn4 , v076
	.byte	W21
	.byte	W05
	.byte		N09   , Cn4 , v064
	.byte	W24
	.byte		N36   , An3 , v072
	.byte	W32
	.byte	W02
	.byte		N14   , Cs4 , v068
	.byte	W09
	.byte	W02
	.byte		N07   , An4 , v072
	.byte	W48
	.byte		N24   , Fn4 , v076
	.byte	W22
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W23
	.byte	GOTO
	 .word	mus_bonus_field_kecleon_1_B1
	.byte		N09   , Cs4 , v064
	.byte	W48
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_kecleon_2:  @ 0x086976A7
	.byte	KEYSH , mus_bonus_field_kecleon_key+0
mus_bonus_field_kecleon_2_B1:
	.byte		VOICE , 13
	.byte		VOL   , 112*mus_bonus_field_kecleon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W24
	.byte	W01
	.byte		N02   , Cs5 , v076
	.byte	W22
	.byte		N06   , En4 
	.byte	W24
	.byte	W01
	.byte	W23
	.byte		N07   , Fn4 , v080
	.byte	W22
	.byte		N06   , Cn5 
	.byte	W24
	.byte	W03
	.byte	W18
	.byte		N02   , Cs5 , v072
	.byte	W11
	.byte		        An4 
	.byte	W13
	.byte		N05   , En4 
	.byte	W30
	.byte	W18
	.byte		N06   , Fn4 , v084
	.byte	W23
	.byte		        An3 , v076
	.byte	W30
	.byte	W01
	.byte	W72
	.byte	W17
	.byte		N03
	.byte	W23
	.byte		N06   , Fs3 , v080
	.byte	W32
	.byte	W12
	.byte		N03   , En3 , v076
	.byte	W24
	.byte	W01
	.byte		N07   , An3 
	.byte	W32
	.byte	W03
	.byte	W09
	.byte		N06   , As3 
	.byte	W24
	.byte	W01
	.byte		N07   , Cs3 , v072
	.byte	W36
	.byte	W02
	.byte	W07
	.byte		N03   , Bn2 , v076
	.byte	W12
	.byte		N02   , Dn3 , v060
	.byte	W10
	.byte		N06   , Fs3 , v072
	.byte	W12
	.byte		        Bn3 , v080
	.byte	W30
	.byte	W01
	.byte	W07
	.byte		        Gs3 
	.byte	W24
	.byte		        En4 
	.byte	W23
	.byte		N07   , An3 
	.byte	W18
	.byte	W17
	.byte		N05   , Cs4 , v072
	.byte	W10
	.byte		N04   , En4 , v076
	.byte	W12
	.byte		N06   , An4 , v084
	.byte	W32
	.byte	W01
	.byte	W05
	.byte		        Fn4 
	.byte	W23
	.byte		N07   , An3 , v068
	.byte	W44
	.byte	W05
	.byte		N02   , Cs4 , v064
	.byte	W11
	.byte		N04   , En4 , v068
	.byte	W12
	.byte		N03   , An4 , v076
	.byte	W12
	.byte		N05   , En4 , v068
	.byte	W32
	.byte	W05
	.byte		N07   , Fn4 , v084
	.byte	W24
	.byte		N05   , An3 , v068
	.byte	W42
	.byte	W01
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W56
	.byte		        An3 , v064
	.byte	W16
	.byte	W08
	.byte		N07   , Cs4 , v084
	.byte	W44
	.byte	W01
	.byte		N10   , Cn4 , v072
	.byte	W10
	.byte		N04   , Fn4 
	.byte	W09
	.byte	W01
	.byte		N06   , An4 , v080
	.byte	W48
	.byte	W02
	.byte		N07   , En4 , v068
	.byte	W21
	.byte	W02
	.byte		N08   , Cs5 , v084
	.byte	W44
	.byte	W03
	.byte		N06   , Fn4 , v072
	.byte	W11
	.byte		N03   , An4 , v076
	.byte	W10
	.byte		N07   , Cn5 
	.byte	W02
	.byte	W24
	.byte	GOTO
	 .word	mus_bonus_field_kecleon_2_B1
	.byte	W48
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_kecleon:  @ 0x086977A8
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_kecleon_pri	@ Priority
	.byte	mus_bonus_field_kecleon_rev	@ Reverb

	.word	mus_bonus_field_kecleon_grp

	.word	mus_bonus_field_kecleon_0
	.word	mus_bonus_field_kecleon_1
	.word	mus_bonus_field_kecleon_2
