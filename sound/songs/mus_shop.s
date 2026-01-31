	.include "sound/MPlayDef.s"

	.equ	mus_shop_grp, gUnknown_08532808
	.equ	mus_shop_pri, 0
	.equ	mus_shop_rev, reverb_set+50
	.equ	mus_shop_mvl, 127
	.equ	mus_shop_key, 0
	.equ	mus_shop_tbs, 1
	.equ	mus_shop_exg, 0
	.equ	mus_shop_cmp, 1

	.section .rodata
	.global	mus_shop
	.align	2

@*********************** Track 01 ***********************@

mus_shop_0:  @ 0x0868BD78
	.byte	KEYSH , mus_shop_key+0
	.byte	TEMPO , 124*mus_shop_tbs/2
	.byte		VOICE , 26
	.byte		VOL   , 82*mus_shop_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N07   , Bn2 , v056
	.byte	W08
	.byte		N08   , Bn3 , v060
	.byte	W08
	.byte		N07   , Bn2 , v068
	.byte	W08
	.byte		N17   , Bn3 , v072
	.byte	W17
	.byte		N06   , Bn2 , v060
	.byte	W07
	.byte		N07   , Bn3 , v068
	.byte	W09
	.byte		N06   , Bn2 , v060
	.byte	W06
	.byte		N09   , Bn3 , v072
	.byte	W09
	.byte		N17   , Bn2 , v068
	.byte	W16
	.byte		N06   , Bn3 , v072
	.byte	W08
	.byte	W96
mus_shop_0_B1:
	.byte		N24   , En1 , v072
	.byte	W40
	.byte		N02   , En1 , v056
	.byte	W08
	.byte		N04   , En1 , v068
	.byte	W24
	.byte		        En1 , v076
	.byte	W24
	.byte	PEND
mus_shop_0_B2:
	.byte		N30   , Gs1 , v076
	.byte	W40
	.byte		N01   , Gs1 , v064
	.byte	W08
	.byte		N04   , Gs1 , v072
	.byte	W24
	.byte		N05   , Gs1 , v076
	.byte	W24
	.byte	PEND
mus_shop_0_B3:
	.byte		N24   , Cs2 , v072
	.byte	W40
	.byte		N02   , Cs2 , v064
	.byte	W08
	.byte		N04
	.byte	W24
	.byte		N05   , Cs2 , v072
	.byte	W24
	.byte	PEND
mus_shop_0_B4:
	.byte		N24   , En1 , v076
	.byte	W40
	.byte		N02   , En1 , v064
	.byte	W08
	.byte		N04
	.byte	W24
	.byte		        En1 , v072
	.byte	W24
	.byte	PEND
mus_shop_0_B5:
	.byte		N24   , An1 , v072
	.byte	W40
	.byte		N04   , An1 , v064
	.byte	W08
	.byte		N03   , An1 , v076
	.byte	W24
	.byte		N04   , An1 , v072
	.byte	W24
	.byte	PEND
mus_shop_0_B6:
	.byte		N28   , Fs1 , v076
	.byte	W40
	.byte		N02   , Fs1 , v064
	.byte	W08
	.byte		N04   , Fs1 , v068
	.byte	W24
	.byte		        Fs1 , v072
	.byte	W24
	.byte	PEND
mus_shop_0_B7:
	.byte		N24   , Bn1 , v080
	.byte	W40
	.byte		N02   , Bn1 , v064
	.byte	W08
	.byte		N05   , Bn1 , v072
	.byte	W24
	.byte		N04   , Bn1 , v080
	.byte	W24
	.byte	PEND
mus_shop_0_B8:
	.byte		N06   , Bn0 , v064
	.byte	W08
	.byte		N07   , Bn1 , v068
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		N16   , Bn1 , v076
	.byte	W16
	.byte		N04   , Bn0 , v064
	.byte	W08
	.byte		N07   , Bn1 , v068
	.byte	W08
	.byte		N05   , Bn0 , v076
	.byte	W08
	.byte		N08   , Bn1 , v072
	.byte	W08
	.byte		N17   , Bn0 , v076
	.byte	W16
	.byte		N06   , Bn1 , v068
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_shop_0_B1
	.byte	PATT
	 .word	mus_shop_0_B2
	.byte	PATT
	 .word	mus_shop_0_B3
	.byte	PATT
	 .word	mus_shop_0_B4
	.byte	PATT
	 .word	mus_shop_0_B5
	.byte	PATT
	 .word	mus_shop_0_B6
	.byte	PATT
	 .word	mus_shop_0_B7
	.byte	PATT
	 .word	mus_shop_0_B8
	.byte		N06   , Gs1 , v076
	.byte	W24
	.byte		N07   , Gs1 , v068
	.byte	W24
	.byte		N06   , Gs1 , v064
	.byte	W24
	.byte		N07   , Gs1 , v068
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , Gs1 , v064
	.byte	W24
	.byte		        Gs1 , v076
	.byte	W24
	.byte		        Gs1 , v072
	.byte	W24
	.byte		N24   , Cs2 , v076
	.byte	W24
	.byte		N19   , Gs2 , v072
	.byte	W16
	.byte		N09   , Cs2 , v056
	.byte	W08
	.byte		N24   , Cn2 , v076
	.byte	W24
	.byte		N17   , Gs2 , v072
	.byte	W16
	.byte		N09   , Cn2 , v056
	.byte	W08
	.byte		N24   , Bn1 , v072
	.byte	W23
	.byte		N17   , Gs2 
	.byte	W17
	.byte		N09   , Bn1 , v060
	.byte	W08
	.byte		N24   , As1 , v072
	.byte	W23
	.byte		N16   , Gs2 , v068
	.byte	W17
	.byte		N10   , As1 , v056
	.byte	W08
	.byte		N07   , Gs1 , v068
	.byte	W24
	.byte		        Gs1 , v072
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N06   , Gs1 , v068
	.byte	W24
	.byte		        Gs1 , v064
	.byte	W24
	.byte		N05   , Gs1 , v072
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		N32   , Cs2 , v076
	.byte	W24
	.byte		N19   , Gs2 , v068
	.byte	W16
	.byte		N10   , Cs2 , v060
	.byte	W08
	.byte		N30   , Cn2 , v072
	.byte	W24
	.byte		N18   , Gs2 , v068
	.byte	W16
	.byte		N10   , Cn2 , v060
	.byte	W08
	.byte		N24   , Bn1 , v072
	.byte	W23
	.byte		N18   , Gs2 , v076
	.byte	W17
	.byte		N10   , Bn1 , v060
	.byte	W09
	.byte		N23   , As1 , v076
	.byte	W21
	.byte		N17   , Gs2 , v072
	.byte	W18
	.byte		N09   , As1 , v048
	.byte	W07
	.byte		N40   , An1 , v080
	.byte	W01
	.byte	W48
	.byte		N07   , An1 , v076
	.byte	W24
	.byte		        An1 , v080
	.byte	W24
	.byte		N32   , As1 , v084
	.byte	W48
	.byte		N09   , As1 , v080
	.byte	W24
	.byte		N24   , As1 , v076
	.byte	W24
	.byte		N06   , Bn1 , v080
	.byte	W24
	.byte		N07   , Bn1 , v076
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N07
	.byte	W24
	.byte		N06   , Bn0 , v060
	.byte	W08
	.byte		N07   , Bn1 , v072
	.byte	W08
	.byte		N06   , Bn0 
	.byte	W08
	.byte		N17   , Bn1 , v076
	.byte	W16
	.byte		N05   , Bn0 , v068
	.byte	W08
	.byte		N07   , Bn1 
	.byte	W08
	.byte		N05   , Bn0 
	.byte	W08
	.byte		N08   , Bn1 , v076
	.byte	W08
	.byte		N18   , Bn0 , v080
	.byte	W16
	.byte		N07   , Bn1 , v072
	.byte	W08
	.byte	GOTO
	 .word	mus_shop_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_shop_1:  @ 0x0868BF4E
	.byte	KEYSH , mus_shop_key+0
	.byte		VOICE , 4
	.byte		VOL   , 58*mus_shop_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
mus_shop_1_B1:
	.byte		N10   , Bn2 , v076
	.byte	W14
	.byte		N03   , Bn2 , v064
	.byte	W09
	.byte		        Bn2 , v060
	.byte	W16
	.byte		N04   , Bn2 , v072
	.byte	W32
	.byte		N05   , Bn2 , v080
	.byte	W22
	.byte		N13   , Cn3 , v076
	.byte	W03
	.byte	W15
	.byte		N04   , Cn3 , v064
	.byte	W08
	.byte		N05   , Cn3 , v056
	.byte	W16
	.byte		N04   , Cn3 , v072
	.byte	W30
	.byte	W01
	.byte		N06   , Cn3 , v076
	.byte	W23
	.byte		N12   , Cs3 
	.byte	W03
	.byte	W14
	.byte		N04   , Cs3 , v056
	.byte	W08
	.byte		        Cs3 , v064
	.byte	W17
	.byte		        Cs3 , v076
	.byte	W32
	.byte		N03   , Cs3 , v060
	.byte	W08
	.byte		N04   , Cs3 , v064
	.byte	W09
	.byte		        Cs3 , v060
	.byte	W08
	.byte	W15
	.byte		N23   , En3 , v080
	.byte	W23
	.byte		N09   , Dn3 , v072
	.byte	W08
	.byte		N08   , Fs3 , v080
	.byte	W22
	.byte		N15   , En3 , v072
	.byte	W17
	.byte		N09   , Dn3 , v060
	.byte	W08
	.byte		N08   , Cs3 , v072
	.byte	W03
	.byte	W06
	.byte		N09   , An2 , v068
	.byte	W08
	.byte		N10   , Cs3 
	.byte	W09
	.byte		N04   , En3 
	.byte	W15
	.byte		N24   , An3 , v080
	.byte	W24
	.byte		N23   , En3 , v072
	.byte	W23
	.byte		N10   , Cs3 , v068
	.byte	W09
	.byte		N18   , An2 , v076
	.byte	W02
	.byte	W36
	.byte	W02
	.byte		N32   , Fs2 , v072
	.byte	W32
	.byte	W02
	.byte		N24   , An2 , v080
	.byte	W24
	.byte		N28   , Bn2 , v076
	.byte	W36
	.byte		N21
	.byte	W36
	.byte		N13
	.byte	W24
	.byte		N08   , Bn2 , v072
	.byte	W08
	.byte		        Cn3 , v056
	.byte	W07
	.byte		N07   , Cs3 , v064
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W08
	.byte		        Ds3 , v060
	.byte	W08
	.byte		N09   , En3 , v064
	.byte	W08
	.byte		N08   , Fn3 , v060
	.byte	W08
	.byte		N07   , Fs3 , v068
	.byte	W08
	.byte		N08   , Gn3 , v060
	.byte	W07
	.byte		N07   , Gs3 , v064
	.byte	W08
	.byte		N09   , An3 
	.byte	W08
	.byte		        As3 , v068
	.byte	W09
	.byte		N16   , Bn3 , v080
	.byte	W01
	.byte	W92
	.byte	W03
	.byte		N10   , Cn3 , v076
	.byte	W01
	.byte	W15
	.byte		N03   , Cn3 , v064
	.byte	W07
	.byte		N04   , Cn3 , v068
	.byte	W17
	.byte		        Cn3 , v072
	.byte	W56
	.byte	W01
	.byte		N10   , Cs3 , v076
	.byte	W15
	.byte		N04   , Cs3 , v060
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W17
	.byte		N05
	.byte	W30
	.byte		N08   , En3 
	.byte	W07
	.byte		N10   , Cs3 
	.byte	W09
	.byte		N07   , Gs2 
	.byte	W10
	.byte	W14
	.byte		N28   , En2 , v080
	.byte	W24
	.byte	W02
	.byte		N10   , Gs2 , v068
	.byte	W08
	.byte		N06   , Dn3 , v076
	.byte	W17
	.byte		N07   , Bn2 , v064
	.byte	W07
	.byte		N06   , Gs2 , v072
	.byte	W15
	.byte		N04   , En2 
	.byte	W09
	.byte	W23
	.byte		N09   , An2 , v068
	.byte	W08
	.byte		N08   , Cs3 , v060
	.byte	W07
	.byte		        En3 , v068
	.byte	W08
	.byte		N04   , An3 , v072
	.byte	W17
	.byte		N09   , En3 , v064
	.byte	W08
	.byte		N05   , Cs3 , v068
	.byte	W15
	.byte		N04   , An2 
	.byte	W10
	.byte	W14
	.byte		N24   , An2 , v084
	.byte	W32
	.byte	W01
	.byte		N05   , An2 , v080
	.byte	W24
	.byte		N06   , An2 , v084
	.byte	W24
	.byte		N28   , Bn2 , v080
	.byte	W01
	.byte	W36
	.byte		N06   , Bn2 , v076
	.byte	W10
	.byte		N05   , Bn3 , v080
	.byte	W18
	.byte		N06   , Bn2 , v060
	.byte	W08
	.byte		N05   , Bn3 , v084
	.byte	W16
	.byte		        Bn2 , v072
	.byte	W08
	.byte	W96
	.byte		        Cn3 
	.byte	W24
	.byte		        Cn3 , v068
	.byte	W24
	.byte		N04   , Cn3 , v072
	.byte	W24
	.byte		        Cn3 , v068
	.byte	W24
	.byte		N05   , Cn3 , v072
	.byte	W24
	.byte		        Cn3 , v068
	.byte	W24
	.byte		N06   , Cn3 , v064
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N48   , Cs3 , v076
	.byte	W44
	.byte	W03
	.byte		        Cn3 
	.byte	W48
	.byte	W01
	.byte		        Bn2 , v084
	.byte	W44
	.byte	W03
	.byte		N40   , As2 , v080
	.byte	W48
	.byte	W01
	.byte		N05   , Cn3 , v076
	.byte	W24
	.byte		        Cn3 , v080
	.byte	W24
	.byte		N06   , Cn3 , v072
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N05   , Cn3 , v068
	.byte	W24
	.byte		N05
	.byte	W24
	.byte		        Cn3 , v064
	.byte	W24
	.byte		N04
	.byte	W24
	.byte		N11   , Cs3 , v060
	.byte	W08
	.byte		N06   , En3 , v056
	.byte	W06
	.byte		N10   , Gs3 , v060
	.byte	W08
	.byte		N06   , Cs4 , v064
	.byte	W17
	.byte		N09   , Gs3 
	.byte	W08
	.byte		N17   , En3 
	.byte	W16
	.byte		N09   , Cs3 , v056
	.byte	W08
	.byte		N19   , Gs3 , v060
	.byte	W18
	.byte		N01   , En3 , v052
	.byte	W07
	.byte		N08   , Gs2 , v064
	.byte	W08
	.byte		N07   , Cs3 , v052
	.byte	W06
	.byte		N09   , En3 , v064
	.byte	W08
	.byte		N06   , Gs3 , v068
	.byte	W17
	.byte		N08   , En3 , v052
	.byte	W08
	.byte		N18   , Cs3 , v064
	.byte	W17
	.byte		N10   , Gs2 
	.byte	W08
	.byte		N17   , En3 , v068
	.byte	W16
	.byte		N04   , Cs3 , v064
	.byte	W08
	.byte	W23
	.byte		N16   , An3 , v080
	.byte	W16
	.byte		N08   , En3 , v064
	.byte	W07
	.byte		N17   , Cs3 , v072
	.byte	W16
	.byte		N05   , An2 , v068
	.byte	W32
	.byte	W02
	.byte	W22
	.byte		N18   , As3 , v084
	.byte	W17
	.byte		N09   , Fs3 , v072
	.byte	W07
	.byte		N17   , Cs3 
	.byte	W17
	.byte		N05   , As2 , v076
	.byte	W32
	.byte	W01
	.byte	W24
	.byte		N16   , En4 , v084
	.byte	W15
	.byte		N09   , Bn3 , v072
	.byte	W09
	.byte		N16   , Gs3 , v076
	.byte	W15
	.byte		N05   , En3 
	.byte	W32
	.byte	W01
	.byte	W23
	.byte		N17   , Ds4 , v084
	.byte	W16
	.byte		N10   , Bn3 , v072
	.byte	W09
	.byte		N16   , Fs3 , v068
	.byte	W16
	.byte		N06   , Ds3 
	.byte	W32
	.byte	GOTO
	 .word	mus_shop_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_shop_2:  @ 0x0868C167
	.byte	KEYSH , mus_shop_key+0
	.byte		VOICE , 1
	.byte		VOL   , 103*mus_shop_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W01
	.byte		N04   , Bn5 , v068
	.byte	W01
	.byte		N06   , An5 
	.byte	W04
	.byte		N05   , Gn5 , v052
	.byte	W03
	.byte		        Fn5 , v048
	.byte	W03
	.byte		N04   , En5 , v052
	.byte	W03
	.byte		N05   , Dn5 , v056
	.byte	W03
	.byte		        Cn5 , v048
	.byte	W03
	.byte		        Bn4 , v060
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Gn4 , v048
	.byte	W03
	.byte		        Fn4 
	.byte	W04
	.byte		N02   , En4 , v044
	.byte	W04
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N05   , Cn4 , v040
	.byte	W03
	.byte		N01   , Bn3 , v048
	.byte	W04
	.byte		N04   , An3 
	.byte	W03
	.byte		N05   , Gn3 , v040
	.byte	W04
	.byte		        Fn3 , v048
	.byte	W04
	.byte		N04   , En3 
	.byte	W03
	.byte		        Dn3 , v052
	.byte	W03
	.byte		        Cn3 
	.byte	W04
	.byte		N08   , Bn2 , v068
	.byte	W08
	.byte		N09   , En3 , v076
	.byte	W08
	.byte		N04   , Fs3 , v072
	.byte	W08
mus_shop_2_B1:
	.byte		N16   , Fs3 , v096
	.byte	W16
	.byte		N09   , En3 , v080
	.byte	W07
	.byte		N19   , Fs3 , v092
	.byte	W17
	.byte		N22   , Gs3 
	.byte	W32
	.byte		N07   , Bn2 , v068
	.byte	W08
	.byte		N09   , En3 , v080
	.byte	W08
	.byte		N04   , Fs3 , v084
	.byte	W08
	.byte		N18   , Fs3 , v088
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N16   , Fs3 , v100
	.byte	W14
	.byte		N24   , Gs3 , v096
	.byte	W32
	.byte	W02
	.byte		N09   , Cn3 , v072
	.byte	W07
	.byte		        Fn3 , v080
	.byte	W07
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N18   , Fs3 , v104
	.byte	W02
	.byte	W16
	.byte		N08   , En3 , v084
	.byte	W06
	.byte		N18   , Fs3 , v088
	.byte	W16
	.byte		N24   , Gs3 , v092
	.byte	W32
	.byte	W03
	.byte		N08   , En3 , v084
	.byte	W07
	.byte		        Fs3 
	.byte	W07
	.byte		N03   , Gs3 , v092
	.byte	W09
	.byte	W15
	.byte		N24   , Cs4 , v104
	.byte	W22
	.byte		N09   , Bn3 , v088
	.byte	W08
	.byte		N05   , Gs3 , v100
	.byte	W24
	.byte	W01
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N08   , En3 , v088
	.byte	W07
	.byte		N24   , Fs3 
	.byte	W01
	.byte	W23
	.byte		N18   , Gs3 , v100
	.byte	W16
	.byte		N54   , En3 , v096
	.byte	W56
	.byte	W01
	.byte	W16
	.byte		N32   , Cs3 , v104
	.byte	W32
	.byte	W01
	.byte		N06   , Ds3 , v100
	.byte	W23
	.byte		        En3 , v092
	.byte	W24
	.byte		N32   , Gs3 , v104
	.byte	W32
	.byte	W03
	.byte		N07   , An3 , v084
	.byte	W05
	.byte		        Gs3 , v088
	.byte	W06
	.byte		N44   , Fs3 , v100
	.byte	W48
	.byte	W02
	.byte	W72
	.byte		N09   , Bn2 , v088
	.byte	W08
	.byte		        En3 , v080
	.byte	W07
	.byte		N05   , Fs3 , v088
	.byte	W08
	.byte		N17   , Fs3 , v104
	.byte	W01
	.byte	W16
	.byte		N09   , En3 , v088
	.byte	W07
	.byte		N18   , Fs3 , v096
	.byte	W16
	.byte		N24   , Gs3 
	.byte	W30
	.byte	W01
	.byte		N09   , Bn2 , v080
	.byte	W10
	.byte		        En3 , v084
	.byte	W08
	.byte		N05   , Fs3 , v092
	.byte	W08
	.byte		N17   , Fs3 , v104
	.byte	W16
	.byte		N08   , Fn3 , v096
	.byte	W08
	.byte		N20   , Fs3 , v100
	.byte	W15
	.byte		N24   , Gs3 , v096
	.byte	W32
	.byte	W01
	.byte		N09   , Cn3 , v084
	.byte	W08
	.byte		        Fn3 , v092
	.byte	W06
	.byte		N05   , Fs3 
	.byte	W09
	.byte		N17   , Fs3 , v108
	.byte	W01
	.byte	W17
	.byte		N08   , En3 , v084
	.byte	W07
	.byte		N17   , Fs3 , v092
	.byte	W15
	.byte		N32   , Gs3 , v088
	.byte	W32
	.byte	W01
	.byte		N10   , En3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W07
	.byte		N05   , Gs3 , v096
	.byte	W09
	.byte	W14
	.byte		        Cn4 , v088
	.byte	W02
	.byte		N24   , Cs4 , v100
	.byte	W24
	.byte		N10   , Bn3 , v092
	.byte	W08
	.byte		N07   , Gs3 , v096
	.byte	W23
	.byte		N18   , Fs3 , v104
	.byte	W17
	.byte		N09   , En3 , v080
	.byte	W08
	.byte		        Fs3 , v100
	.byte	W22
	.byte		N18   , Gs3 
	.byte	W17
	.byte		N54   , En3 
	.byte	W56
	.byte	W01
	.byte	W16
	.byte		N32   , Cs3 , v104
	.byte	W32
	.byte		N06   , Ds3 , v100
	.byte	W24
	.byte		        En3 , v096
	.byte	W23
	.byte		N36   , Gs3 , v104
	.byte	W01
	.byte	W36
	.byte		N07   , Bn3 , v088
	.byte	W05
	.byte		N08   , Gs3 , v092
	.byte	W07
	.byte		N60   , Fs3 , v096
	.byte	W48
	.byte	W72
	.byte		N08   , Fs3 , v076
	.byte	W08
	.byte		N10   , Fn3 
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		N07   , Gs3 , v100
	.byte	W24
	.byte		N08   , Gs3 , v096
	.byte	W24
	.byte		N16   , Gs3 , v092
	.byte	W16
	.byte		N10   , Gn3 , v088
	.byte	W08
	.byte		N17   , Gs3 , v092
	.byte	W16
	.byte		N09   , An3 , v088
	.byte	W08
	.byte	W14
	.byte		N08   , Gs3 
	.byte	W24
	.byte	W01
	.byte		N11   , Gs3 , v092
	.byte	W10
	.byte		N24   , An3 
	.byte	W23
	.byte		N19   , Gs3 
	.byte	W17
	.byte		N09   , Fs3 , v088
	.byte	W07
	.byte	W01
	.byte		        En3 , v092
	.byte	W23
	.byte		N09
	.byte	W24
	.byte		N17
	.byte	W16
	.byte		N09   , Ds3 , v088
	.byte	W08
	.byte		N17   , En3 , v100
	.byte	W16
	.byte		N11   , Fs3 , v092
	.byte	W08
	.byte		N52   , Gs3 , v100
	.byte	W64
	.byte		N10   , Fs3 , v088
	.byte	W08
	.byte		N18   , Fn3 , v064
	.byte	W16
	.byte		N10   , Fs3 , v092
	.byte	W08
	.byte		        Gs3 , v100
	.byte	W24
	.byte		        Gs3 , v104
	.byte	W24
	.byte		N17   , Gs3 , v100
	.byte	W16
	.byte		N11   , Gn3 , v096
	.byte	W10
	.byte		N15   , Gs3 , v092
	.byte	W15
	.byte		N24   , An3 , v088
	.byte	W07
	.byte	W15
	.byte		N09   , Gs3 , v092
	.byte	W24
	.byte		        Gs3 , v080
	.byte	W08
	.byte		        Cn4 
	.byte	W07
	.byte		        Ds4 , v092
	.byte	W08
	.byte		N11   , Fs4 , v096
	.byte	W09
	.byte		N09   , Ds4 
	.byte	W16
	.byte		        Cn4 , v088
	.byte	W08
	.byte		N14   , Cs4 , v100
	.byte	W01
	.byte	W13
	.byte		N10   , Cn4 , v080
	.byte	W09
	.byte		N18   , Cs4 , v092
	.byte	W16
	.byte		N11   , Ds4 , v104
	.byte	W09
	.byte		N19   , En4 
	.byte	W18
	.byte		N08   , Ds4 , v088
	.byte	W08
	.byte		N18   , En4 , v100
	.byte	W16
	.byte		N08   , Fs4 , v096
	.byte	W07
	.byte		N44   , Gs4 , v108
	.byte	W72
	.byte		N23   , Gs3 , v104
	.byte	W24
	.byte		N60   , An3 , v108
	.byte	W68
	.byte	W03
	.byte		N09   , An3 , v096
	.byte	W09
	.byte		N07   , Gs3 , v092
	.byte	W07
	.byte		N10   , An3 , v096
	.byte	W09
	.byte		N40   , As3 , v108
	.byte	W40
	.byte	W01
	.byte		N10   , Fs3 , v088
	.byte	W09
	.byte		N24   , As3 , v100
	.byte	W24
	.byte		        Cs4 , v108
	.byte	W22
	.byte	W01
	.byte		N80   , En4 , v120
	.byte	W78
	.byte	W01
	.byte		N09   , Ds4 , v100
	.byte	W07
	.byte		N10   , Cs4 , v092
	.byte	W09
	.byte		N64   , Bn3 , v100
	.byte	W72
	.byte		N08   , Bn2 , v068
	.byte	W08
	.byte		N09   , En3 , v076
	.byte	W08
	.byte		N04   , Fs3 , v072
	.byte	W08
	.byte	GOTO
	 .word	mus_shop_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_shop_3:  @ 0x0868C3E7
	.byte	KEYSH , mus_shop_key+0
	.byte		VOICE , 8
	.byte		VOL   , 75*mus_shop_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
mus_shop_3_B1:
	.byte	W44
	.byte	W03
	.byte		N08   , En5 , v064
	.byte	W08
	.byte		N07   , En4 , v052
	.byte	W07
	.byte		        En5 , v064
	.byte	W07
	.byte		N05   , En4 
	.byte	W24
	.byte	W03
	.byte	W48
	.byte		N08   , Ds5 , v076
	.byte	W08
	.byte		N07   , Ds4 , v064
	.byte	W08
	.byte		        Ds5 , v076
	.byte	W08
	.byte		N04   , Ds4 , v056
	.byte	W24
	.byte	W48
	.byte		N08   , Cs5 , v072
	.byte	W08
	.byte		N06   , Cs4 , v064
	.byte	W08
	.byte		N08   , Cs5 , v072
	.byte	W08
	.byte		N05   , Cs4 , v064
	.byte	W24
	.byte	W48
	.byte		N07   , Bn4 , v076
	.byte	W08
	.byte		        Bn3 , v068
	.byte	W08
	.byte		N08   , Bn4 , v076
	.byte	W08
	.byte		N05   , Bn3 , v060
	.byte	W24
	.byte	W48
	.byte		N08   , An4 , v068
	.byte	W08
	.byte		N07   , An3 , v060
	.byte	W08
	.byte		N08   , An4 , v072
	.byte	W08
	.byte		N05   , An3 , v060
	.byte	W24
	.byte	W48
	.byte		N09   , Cs5 , v068
	.byte	W08
	.byte		N08   , Cs4 , v056
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		N05   , Cs4 , v064
	.byte	W24
	.byte	W96
	.byte		N09   , Bn4 , v076
	.byte	W08
	.byte		N08   , Bn5 , v068
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		N07   , Bn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N08   , Bn5 
	.byte	W08
	.byte		N07   , Bn4 , v076
	.byte	W08
	.byte		N09   , Bn5 , v080
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		N10   , Bn5 , v076
	.byte	W08
	.byte		N07   , Bn4 , v072
	.byte	W08
	.byte		N05   , Bn5 , v076
	.byte	W08
	.byte	W48
	.byte		N09   , En5 
	.byte	W08
	.byte		        En4 , v060
	.byte	W08
	.byte		N07   , En5 , v076
	.byte	W08
	.byte		N05   , En4 , v068
	.byte	W24
	.byte	W48
	.byte		N09   , Ds5 , v072
	.byte	W08
	.byte		        Ds4 , v060
	.byte	W08
	.byte		N08   , Ds5 , v072
	.byte	W08
	.byte		N05   , Ds4 , v068
	.byte	W24
	.byte	W48
	.byte		N07   , Cs5 
	.byte	W08
	.byte		        Cs4 , v064
	.byte	W08
	.byte		N06   , Cs5 , v076
	.byte	W08
	.byte		N05   , Cs4 , v064
	.byte	W24
	.byte	W48
	.byte		N08   , Bn4 , v072
	.byte	W08
	.byte		        Bn3 , v052
	.byte	W08
	.byte		N07   , Bn4 , v068
	.byte	W08
	.byte		N06   , Bn3 , v056
	.byte	W24
	.byte	W48
	.byte		N09   , An5 , v076
	.byte	W08
	.byte		N07   , An4 , v064
	.byte	W08
	.byte		N08   , An5 
	.byte	W08
	.byte		N06   , An4 , v076
	.byte	W24
	.byte	W48
	.byte		N08   , Fs5 , v072
	.byte	W08
	.byte		        Fs4 , v064
	.byte	W08
	.byte		N09   , Fs5 , v076
	.byte	W08
	.byte		N05   , Fs4 , v068
	.byte	W24
	.byte	W96
	.byte		N08   , Bn5 , v076
	.byte	W08
	.byte		N09   , Bn4 , v072
	.byte	W08
	.byte		        Bn5 , v076
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		N08   , Bn5 , v060
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		        Bn5 
	.byte	W08
	.byte		        Bn4 , v064
	.byte	W08
	.byte		N07   , Bn5 , v072
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N08   , Bn5 
	.byte	W08
	.byte		N04   , Bn4 , v064
	.byte	W08
	.byte	W48
	.byte		N09   , Cn4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N10   , Gs4 , v060
	.byte	W08
	.byte		N03   , Cn5 , v056
	.byte	W24
	.byte	W24
	.byte		N10   , Cn4 , v064
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N11   , Gs4 
	.byte	W08
	.byte		N04   , Cn5 , v076
	.byte	W24
	.byte		N06
	.byte	W08
	.byte		N09   , Gs4 , v068
	.byte	W08
	.byte		N02   , Ds4 , v056
	.byte	W08
	.byte	W24
	.byte		N09   , Cs4 
	.byte	W08
	.byte		N06   , En4 , v052
	.byte	W08
	.byte		N09   , Gs4 , v064
	.byte	W08
	.byte		N06   , Cs5 , v076
	.byte	W24
	.byte		N09   , Cs5 , v068
	.byte	W08
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		N04   , En4 , v056
	.byte	W08
	.byte	W24
	.byte		N09   , Cs4 
	.byte	W08
	.byte		N07   , En4 
	.byte	W08
	.byte		N09   , Gs4 , v068
	.byte	W08
	.byte		N05   , Cs5 , v072
	.byte	W48
	.byte	W24
	.byte		N09   , Cn4 , v064
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N09   , Gs4 
	.byte	W08
	.byte		N03   , Cn5 , v076
	.byte	W48
	.byte	W24
	.byte		N07   , Cn5 , v068
	.byte	W08
	.byte		N09   , Gs4 , v076
	.byte	W08
	.byte		N08   , Ds4 , v060
	.byte	W08
	.byte		N06   , Cn4 , v056
	.byte	W24
	.byte		N09   , Cn4 , v060
	.byte	W08
	.byte		N10   , Ds4 , v068
	.byte	W08
	.byte		N06   , Gs4 , v072
	.byte	W08
	.byte	W24
	.byte		N08   , Cs4 , v064
	.byte	W08
	.byte		        En4 , v060
	.byte	W08
	.byte		N09   , Gs4 , v068
	.byte	W08
	.byte		N01   , Cs5 , v076
	.byte	W24
	.byte		N08   , Cs5 , v068
	.byte	W08
	.byte		N09   , Gs4 , v060
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		N05   , Cs4 
	.byte	W24
	.byte		N09   , Cs4 , v048
	.byte	W08
	.byte		N07   , En4 , v056
	.byte	W08
	.byte		N11   , Gs4 , v064
	.byte	W08
	.byte		N07   , Cs5 , v072
	.byte	W24
	.byte		N08   , Cs5 , v068
	.byte	W08
	.byte		        Gs4 , v060
	.byte	W08
	.byte		N05   , En4 
	.byte	W08
	.byte	W24
	.byte		N08   , Cs4 , v056
	.byte	W08
	.byte		        En4 , v052
	.byte	W08
	.byte		N10   , An4 , v060
	.byte	W08
	.byte		        Cs5 , v064
	.byte	W08
	.byte		N09   , An4 , v048
	.byte	W08
	.byte		N08   , En4 , v056
	.byte	W08
	.byte		N09   , Cs4 , v048
	.byte	W08
	.byte		        En4 , v052
	.byte	W08
	.byte		N06   , An4 , v072
	.byte	W08
	.byte	W24
	.byte		N10   , Cs4 , v056
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N10   , As4 , v064
	.byte	W08
	.byte		N11   , Cs5 
	.byte	W08
	.byte		N10   , As4 , v068
	.byte	W08
	.byte		N09   , Fs4 , v056
	.byte	W08
	.byte		N11   , Cs4 
	.byte	W08
	.byte		N09   , Fs4 , v060
	.byte	W08
	.byte		N05   , As4 , v064
	.byte	W08
	.byte	W24
	.byte		N10   , Bn3 , v056
	.byte	W08
	.byte		        En4 , v060
	.byte	W08
	.byte		        Fs4 , v064
	.byte	W08
	.byte		N08   , Bn4 , v072
	.byte	W08
	.byte		N09   , Fs4 , v052
	.byte	W08
	.byte		N07   , En4 , v056
	.byte	W08
	.byte		N10   , Bn3 , v060
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		N06   , Fs4 , v060
	.byte	W08
	.byte	W24
	.byte		N11   , Bn3 
	.byte	W08
	.byte		        Ds4 , v064
	.byte	W08
	.byte		N10   , Fs4 
	.byte	W08
	.byte		N08   , Bn4 , v076
	.byte	W08
	.byte		N09   , Fs4 , v064
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N10   , Bn3 , v056
	.byte	W08
	.byte		N09   , Ds4 , v060
	.byte	W08
	.byte		N03   , Fs4 , v064
	.byte	W08
	.byte	GOTO
	 .word	mus_shop_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_shop_4:  @ 0x0868C64B
	.byte	KEYSH , mus_shop_key+0
	.byte		VOICE , 0
	.byte		VOL   , 51*mus_shop_mvl/mxv
	.byte	W96
	.byte	W96
mus_shop_4_B1:
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1 
	.byte	W16
	.byte		N06
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		        Cn1 
	.byte		N06   , Fs1 
	.byte	W08
	.byte		        Cn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		N06
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		N06
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
	.byte	PATT
	 .word	mus_shop_4_B1
mus_shop_4_B2:
	.byte		N06   , Dn1 , v100
	.byte		N06   , Fs1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_shop_4_B2
mus_shop_4_B3:
	.byte		N06   , Cn1 , v100
	.byte		N06   , Fs1 
	.byte	W16
	.byte		N06
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		        Cn1 
	.byte		N06   , Fs1 
	.byte	W08
	.byte		N06
	.byte	W16
	.byte		        Cn1 
	.byte		N06   , Fs1 
	.byte	W08
	.byte		        Dn1 
	.byte		N06   , Fs1 
	.byte	W16
	.byte		N06
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B2
	.byte	PATT
	 .word	mus_shop_4_B2
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	PATT
	 .word	mus_shop_4_B3
	.byte	GOTO
	 .word	mus_shop_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_shop:  @ 0x0868C72C
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_shop_pri	@ Priority
	.byte	mus_shop_rev	@ Reverb

	.word	mus_shop_grp

	.word	mus_shop_0
	.word	mus_shop_1
	.word	mus_shop_2
	.word	mus_shop_3
	.word	mus_shop_4
