	.include "sound/MPlayDef.s"

	.equ	mus_table_select_grp, gUnknown_08532808
	.equ	mus_table_select_pri, 0
	.equ	mus_table_select_rev, reverb_set+50
	.equ	mus_table_select_mvl, 127
	.equ	mus_table_select_key, 0
	.equ	mus_table_select_tbs, 1
	.equ	mus_table_select_exg, 0
	.equ	mus_table_select_cmp, 1

	.section .rodata
	.global	mus_table_select
	.align	2

@*********************** Track 01 ***********************@

mus_table_select_0:  @ 0x0868945C
	.byte	KEYSH , mus_table_select_key+0
	.byte	TEMPO , 124*mus_table_select_tbs/2
	.byte		VOICE , 62
	.byte		VOL   , 85*mus_table_select_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
mus_table_select_0_B1:
	.byte		N06   , Dn1 , v072
	.byte	W24
	.byte		N05   , An1 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W24
	.byte		N04   , Dn1 
	.byte	W24
	.byte	PEND
mus_table_select_0_B2:
	.byte		N03   , En1 , v068
	.byte	W24
	.byte		N04   , Bn1 , v072
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N05   , En1 , v056
	.byte	W24
	.byte	PEND
mus_table_select_0_B3:
	.byte		N04   , An1 , v080
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An2 , v076
	.byte	W24
	.byte		        An1 , v068
	.byte	W24
	.byte	PEND
mus_table_select_0_B4:
	.byte		N05   , Dn1 , v076
	.byte	W24
	.byte		        An1 , v080
	.byte	W24
	.byte		N04   , En2 , v076
	.byte	W24
	.byte		        An1 , v064
	.byte	W24
	.byte	PEND
mus_table_select_0_B5:
	.byte		N05   , Dn1 , v072
	.byte	W24
	.byte		N04   , An1 , v076
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N05   , An1 , v072
	.byte	W24
	.byte	PEND
mus_table_select_0_B6:
	.byte		N05   , En1 , v076
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W24
	.byte		N05   , En2 , v072
	.byte	W24
	.byte		N04   , Bn1 , v080
	.byte	W24
	.byte	PEND
mus_table_select_0_B7:
	.byte		N04   , Fn1 , v076
	.byte	W24
	.byte		N05   , Cn2 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		N04   , En2 
	.byte	W24
	.byte	PEND
mus_table_select_0_B8:
	.byte		N04   , An1 , v076
	.byte	W24
	.byte		N05   , En2 
	.byte	W24
	.byte		N04   , An2 , v080
	.byte	W24
	.byte		        An1 , v072
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_table_select_0_B1
	.byte	PATT
	 .word	mus_table_select_0_B2
	.byte	PATT
	 .word	mus_table_select_0_B3
	.byte	PATT
	 .word	mus_table_select_0_B4
	.byte	PATT
	 .word	mus_table_select_0_B5
	.byte	PATT
	 .word	mus_table_select_0_B6
	.byte	PATT
	 .word	mus_table_select_0_B7
	.byte	PATT
	 .word	mus_table_select_0_B8
	.byte		N03   , Bn1 , v060
	.byte	W12
	.byte		N04   , Fs2 , v064
	.byte	W12
	.byte		N03   , Bn1 , v060
	.byte	W12
	.byte		N04   , Fs2 
	.byte	W12
	.byte		N03   , Bn2 , v064
	.byte	W12
	.byte		N05   , Fs2 
	.byte	W12
	.byte		        Bn1 , v060
	.byte	W12
	.byte		N04   , Fs2 
	.byte	W12
	.byte		N05   , Fs1 , v068
	.byte	W12
	.byte		N04   , Cs2 , v064
	.byte	W12
	.byte		N05   , Fs1 , v060
	.byte	W12
	.byte		        Cs2 , v068
	.byte	W12
	.byte		N04   , An2 , v072
	.byte	W12
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		N05   , Cs2 , v056
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N04   , Fs2 , v064
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs2 , v060
	.byte	W12
	.byte		N02   , Bn2 , v068
	.byte	W12
	.byte		N03   , Fs2 , v060
	.byte	W12
	.byte		N02   , Bn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N04   , Fs1 , v068
	.byte	W12
	.byte		        Cs2 , v060
	.byte	W12
	.byte		        Fs1 , v064
	.byte	W12
	.byte		N03   , Cs2 , v060
	.byte	W12
	.byte		N04   , An2 , v068
	.byte	W12
	.byte		N03   , Fs2 , v060
	.byte	W12
	.byte		N04   , Cs2 , v056
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        En1 , v076
	.byte	W12
	.byte		N05   , Bn1 , v072
	.byte	W12
	.byte		N04   , En1 , v064
	.byte	W12
	.byte		N05   , Bn1 , v068
	.byte	W12
	.byte		N04   , Gn2 , v064
	.byte	W12
	.byte		        En2 , v056
	.byte	W12
	.byte		N06   , En1 , v068
	.byte	W12
	.byte		N05   , Bn1 , v072
	.byte	W12
	.byte		N04   , Dn1 , v068
	.byte	W12
	.byte		N05   , Bn1 , v064
	.byte	W12
	.byte		N04   , Dn1 , v060
	.byte	W12
	.byte		N05   , Bn1 , v064
	.byte	W12
	.byte		N04   , Fs2 , v068
	.byte	W12
	.byte		N05   , Bn1 , v064
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W12
	.byte		N04   , Cn2 , v068
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn2 , v072
	.byte	W12
	.byte		        Gn2 , v068
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N05
	.byte	W12
	.byte		N04   , Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		        An2 , v076
	.byte	W12
	.byte		        En2 , v068
	.byte	W12
	.byte		        An2 , v076
	.byte	W12
	.byte		N03   , En2 , v072
	.byte	W12
	.byte		N05   , An1 
	.byte	W12
	.byte		N04   , En2 
	.byte	W12
	.byte		        An1 , v064
	.byte	W12
	.byte		        En2 , v060
	.byte	W12
	.byte		N05   , An2 , v072
	.byte	W12
	.byte		N04   , En2 , v068
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N02   , En2 , v064
	.byte	W12
	.byte		N05   , An2 , v072
	.byte	W12
	.byte		N04   , En2 , v076
	.byte	W12
	.byte	GOTO
	 .word	mus_table_select_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_table_select_1:  @ 0x08689602
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 74
	.byte		VOL   , 108*mus_table_select_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		MOD   , 5
	.byte	W01
	.byte		N05   , An3 , v076
	.byte	W05
	.byte		N07   , Bn3 , v088
	.byte	W06
mus_table_select_1_B1:
	.byte		N04   , An3 , v100
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N02   , Gn3 , v104
	.byte	W12
	.byte		N24   , Fs3 , v108
	.byte	W30
	.byte		N05   , Fs3 , v072
	.byte	W05
	.byte		        Gn3 , v092
	.byte	W05
	.byte		N06   , An3 , v088
	.byte	W06
	.byte		N03   , Gn3 , v096
	.byte	W02
	.byte	W11
	.byte		N02   , Gn3 , v088
	.byte	W23
	.byte		N04   , Fs3 , v100
	.byte	W13
	.byte		N28   , En3 , v104
	.byte	W48
	.byte	W01
	.byte		N02   , Gn3 , v096
	.byte	W12
	.byte		N04   , Gn3 , v100
	.byte	W24
	.byte		        Fs3 
	.byte	W13
	.byte		N23   , En3 , v104
	.byte	W30
	.byte		N06   , En3 , v072
	.byte	W04
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        Gn3 , v084
	.byte	W05
	.byte		N05   , Fs3 , v096
	.byte	W02
	.byte	W10
	.byte		N04   , Fs3 , v100
	.byte	W24
	.byte		N03   , Bn3 
	.byte	W13
	.byte		N24   , An3 , v108
	.byte	W36
	.byte		N05   , An3 , v088
	.byte	W05
	.byte		N07   , Bn3 , v096
	.byte	W06
	.byte		N02   , An3 , v088
	.byte	W02
	.byte	W11
	.byte		N04   , An3 , v104
	.byte	W23
	.byte		        Gn3 , v096
	.byte	W12
	.byte		N24   , Fs3 , v104
	.byte	W32
	.byte		N05   , Fs3 , v084
	.byte	W05
	.byte		        Gn3 , v088
	.byte	W05
	.byte		N08   , An3 , v084
	.byte	W07
	.byte		N04   , Gn3 , v100
	.byte	W01
	.byte	W11
	.byte		        Gn3 , v112
	.byte	W24
	.byte		        Bn3 , v100
	.byte	W12
	.byte		N20   , En4 , v116
	.byte	W18
	.byte		N18   , Fs4 , v112
	.byte	W16
	.byte		N13   , En4 , v108
	.byte	W13
	.byte		N03   , An3 , v100
	.byte	W02
	.byte	W05
	.byte		N01   , An3 , v076
	.byte	W05
	.byte		N05   , An3 , v112
	.byte	W24
	.byte		N13   , An3 , v108
	.byte	W12
	.byte		N05   , Bn3 , v112
	.byte	W13
	.byte		N04
	.byte	W24
	.byte		        En3 , v108
	.byte	W13
	.byte		N56   , An3 , v112
	.byte	W96
	.byte		N05   , Dn4 , v104
	.byte	W12
	.byte		        Dn4 , v100
	.byte	W23
	.byte		N04   , En4 , v104
	.byte	W11
	.byte		N13   , Fs4 , v108
	.byte	W13
	.byte		N04   , Dn4 , v104
	.byte	W23
	.byte		        An3 , v100
	.byte	W12
	.byte		        Bn3 , v108
	.byte	W02
	.byte	W11
	.byte		        Bn3 , v104
	.byte	W24
	.byte		N02   , Dn4 , v100
	.byte	W12
	.byte		N24   , Bn3 , v108
	.byte	W48
	.byte		N04   , Cs4 
	.byte	W01
	.byte	W11
	.byte		        Cs4 , v100
	.byte	W23
	.byte		        En4 
	.byte	W12
	.byte		N13   , Gn4 , v116
	.byte	W13
	.byte		N02   , En4 , v096
	.byte	W24
	.byte	W01
	.byte		N04   , Cs4 , v100
	.byte	W12
	.byte		N02   , Dn4 , v096
	.byte	W11
	.byte		N04   , Dn4 , v100
	.byte	W12
	.byte		N03
	.byte	W12
	.byte		        En4 , v104
	.byte	W12
	.byte		N24   , Cs4 , v100
	.byte	W48
	.byte		N04   , Dn4 , v108
	.byte	W01
	.byte	W11
	.byte		        Dn4 , v112
	.byte	W24
	.byte		N03   , En4 , v092
	.byte	W12
	.byte		N13   , Fs4 , v112
	.byte	W13
	.byte		N01   , Dn4 , v088
	.byte	W23
	.byte		N03   , An3 
	.byte	W13
	.byte		N05   , Bn3 , v100
	.byte	W12
	.byte		N04   , En4 , v092
	.byte	W11
	.byte		        Gn4 , v096
	.byte	W12
	.byte		N03   , Bn4 , v108
	.byte	W12
	.byte		N04   , En5 , v112
	.byte	W23
	.byte		        En4 , v100
	.byte	W24
	.byte	W02
	.byte	W12
	.byte		        An4 , v112
	.byte	W11
	.byte		        Fn4 , v108
	.byte	W12
	.byte		        Cn4 , v100
	.byte	W24
	.byte		        Bn4 , v112
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 , v108
	.byte	W13
	.byte	W12
	.byte		        An4 
	.byte	W11
	.byte		N03   , En4 , v096
	.byte	W12
	.byte		N05   , Cs4 
	.byte	W11
	.byte		N04   , An3 , v100
	.byte	W23
	.byte		        An4 , v127
	.byte	W01
	.byte		N03   , Gs4 , v088
	.byte	W24
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	W01
	.byte		N05   , An3 , v076
	.byte	W05
	.byte		N07   , Bn3 , v088
	.byte	W06
	.byte	GOTO
	 .word	mus_table_select_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_table_select_2:  @ 0x0868977E
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 2
	.byte		VOL   , 85*mus_table_select_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W12
mus_table_select_2_B1:
	.byte	W23
	.byte		N05   , An2 , v056
	.byte	W05
	.byte		        Dn3 , v048
	.byte	W06
	.byte		N06   , An2 , v060
	.byte	W04
	.byte		N07   , Dn3 , v056
	.byte	W08
	.byte		N06   , Fs3 , v064
	.byte	W12
	.byte		N01   , Dn3 
	.byte	W12
	.byte		N02   , An2 , v068
	.byte	W12
	.byte		N03   , Dn3 , v060
	.byte	W14
	.byte	W23
	.byte		N05   , Gn2 , v064
	.byte	W06
	.byte		        Bn2 , v060
	.byte	W05
	.byte		N07   , Gn2 , v056
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , En3 , v060
	.byte	W13
	.byte		N01   , Bn2 
	.byte	W12
	.byte		N04   , Gn2 
	.byte	W12
	.byte		N02   , Bn2 
	.byte	W13
	.byte	W23
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N05   , Cs3 , v056
	.byte	W06
	.byte		N07   , Gn2 , v052
	.byte	W06
	.byte		N06   , Cs3 , v056
	.byte	W06
	.byte		N02   , En3 , v060
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W12
	.byte		N02   , Gn2 , v052
	.byte	W12
	.byte		        Cs3 , v060
	.byte	W13
	.byte	W23
	.byte		N06   , An2 , v064
	.byte	W05
	.byte		N05   , Dn3 , v052
	.byte	W06
	.byte		N06   , An2 , v056
	.byte	W05
	.byte		N08   , Dn3 , v048
	.byte	W08
	.byte		N02   , Fs3 , v064
	.byte	W12
	.byte		N01   , Dn3 , v060
	.byte	W13
	.byte		N03   , En3 , v052
	.byte	W12
	.byte		N02   , Cs3 , v060
	.byte	W12
	.byte	W23
	.byte		N06   , An2 , v056
	.byte	W06
	.byte		N05   , Dn3 , v048
	.byte	W07
	.byte		        An2 , v052
	.byte	W05
	.byte		N07   , Dn3 , v040
	.byte	W06
	.byte		N05   , Fs3 , v060
	.byte	W12
	.byte		N02   , Dn3 , v056
	.byte	W12
	.byte		N01   , An2 , v060
	.byte	W11
	.byte		N03   , Dn3 
	.byte	W14
	.byte	W23
	.byte		N05   , Gn2 , v052
	.byte	W06
	.byte		        Bn2 , v056
	.byte	W05
	.byte		N07   , Gn2 , v048
	.byte	W06
	.byte		        Bn2 
	.byte	W07
	.byte		N03   , En3 , v056
	.byte	W13
	.byte		N02   , Bn2 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N01   , Bn2 
	.byte	W12
	.byte	W22
	.byte		N06   , An2 , v064
	.byte	W06
	.byte		        Cn3 , v056
	.byte	W05
	.byte		N07   , Fn3 , v060
	.byte	W06
	.byte		N04   , Cn3 , v044
	.byte	W32
	.byte	W01
	.byte		N05   , Gs2 , v064
	.byte	W05
	.byte		        Bn2 , v060
	.byte	W05
	.byte		N07   , En3 
	.byte	W07
	.byte		N04   , Bn2 , v044
	.byte	W07
	.byte	W24
	.byte	W01
	.byte		        An2 , v056
	.byte	W05
	.byte		N05   , Cs3 , v060
	.byte	W06
	.byte		N06   , An2 , v052
	.byte	W05
	.byte		N08   , Cs3 , v060
	.byte	W07
	.byte		N02   , En3 
	.byte	W12
	.byte		N04   , Cs3 , v064
	.byte	W11
	.byte		        An3 , v060
	.byte	W12
	.byte		N01   , En3 
	.byte	W13
	.byte	W23
	.byte		N05   , An2 , v064
	.byte	W06
	.byte		N04   , Dn3 , v048
	.byte	W05
	.byte		N06   , An2 , v056
	.byte	W06
	.byte		N08   , Dn3 , v048
	.byte	W07
	.byte		N05   , Fs3 , v064
	.byte	W12
	.byte		N02   , Dn3 , v056
	.byte	W12
	.byte		        An2 
	.byte	W11
	.byte		        Dn3 , v060
	.byte	W14
	.byte	W22
	.byte		N04   , Gn2 
	.byte	W05
	.byte		N05   , Bn2 
	.byte	W06
	.byte		N06   , Gn2 , v056
	.byte	W06
	.byte		        Bn2 , v052
	.byte	W07
	.byte		N04   , En3 , v060
	.byte	W13
	.byte		N01   , Bn2 , v056
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W11
	.byte		        Bn2 , v060
	.byte	W14
	.byte	W24
	.byte		N05   , Gn2 , v052
	.byte	W06
	.byte		        Cs3 , v056
	.byte	W05
	.byte		N06   , Gn2 
	.byte	W05
	.byte		        Cs3 , v052
	.byte	W07
	.byte		N03   , En3 , v064
	.byte	W12
	.byte		N02   , Cs3 , v052
	.byte	W12
	.byte		        Gn2 , v048
	.byte	W11
	.byte		N04   , Cs3 , v064
	.byte	W14
	.byte	W23
	.byte		N05   , An2 
	.byte	W07
	.byte		        Dn3 , v044
	.byte	W05
	.byte		        An2 , v052
	.byte	W05
	.byte		N06   , Dn3 , v048
	.byte	W07
	.byte		N03   , En3 , v064
	.byte	W12
	.byte		N02   , Cs3 , v056
	.byte	W12
	.byte		        An2 , v060
	.byte	W13
	.byte		N03   , An3 , v064
	.byte	W12
	.byte	W24
	.byte		N05   , An2 , v068
	.byte	W05
	.byte		N06   , Dn3 , v056
	.byte	W07
	.byte		N05   , An2 , v064
	.byte	W05
	.byte		N06   , Dn3 , v040
	.byte	W05
	.byte		N04   , Fs3 , v064
	.byte	W13
	.byte		N01   , Dn3 , v056
	.byte	W12
	.byte		        An2 , v064
	.byte	W11
	.byte		N02   , Dn3 
	.byte	W14
	.byte	W23
	.byte		N04   , Gn2 , v060
	.byte	W06
	.byte		N02   , Bn2 , v056
	.byte	W05
	.byte		N05   , Gn2 
	.byte	W07
	.byte		N03   , Bn2 , v048
	.byte	W06
	.byte		        En3 , v060
	.byte	W12
	.byte		N01   , Bn2 , v056
	.byte	W12
	.byte		N02   , Gn2 
	.byte	W12
	.byte		        Bn2 , v060
	.byte	W13
	.byte	W24
	.byte		N05   , An2 , v064
	.byte	W06
	.byte		        Cn3 , v048
	.byte	W05
	.byte		N06   , Fn3 , v056
	.byte	W06
	.byte		N03   , Cn3 , v044
	.byte	W30
	.byte	W01
	.byte		N04   , Gs2 , v060
	.byte	W05
	.byte		N05   , Bn2 , v056
	.byte	W05
	.byte		N07   , En3 , v060
	.byte	W06
	.byte		N05   , Bn2 , v048
	.byte	W08
	.byte	W24
	.byte		        An2 , v056
	.byte	W05
	.byte		N06   , Cs3 , v060
	.byte	W07
	.byte		        En3 , v052
	.byte	W04
	.byte		N09   , Cs3 , v056
	.byte	W08
	.byte		N02   , An3 , v064
	.byte	W12
	.byte		N01   , En3 
	.byte	W12
	.byte		N02   , Cs3 , v060
	.byte	W12
	.byte		        An2 , v064
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
	.byte	GOTO
	 .word	mus_table_select_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_table_select_3:  @ 0x08689978
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 41
	.byte		VOL   , 108*mus_table_select_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 5
	.byte	W12
mus_table_select_3_B1:
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
	.byte		N12   , Fs3 , v060
	.byte	W12
	.byte		N14   , Bn3 , v068
	.byte	W12
	.byte		N24   , Dn4 , v060
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N13   , Bn3 , v068
	.byte	W12
	.byte		N06   , An3 , v076
	.byte	W12
	.byte		N08   , Gs3 , v060
	.byte	W12
	.byte		N32   , An3 
	.byte	W36
	.byte		N12   , An3 , v076
	.byte	W12
	.byte		        Bn3 , v072
	.byte	W12
	.byte		        An3 , v068
	.byte	W12
	.byte	W24
	.byte		N13   , Fs3 , v064
	.byte	W12
	.byte		N14   , Bn3 
	.byte	W12
	.byte		N24   , Dn4 , v072
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N14   , Dn4 , v068
	.byte	W12
	.byte		N06   , Cs4 , v076
	.byte	W12
	.byte		N07   , Fs4 , v068
	.byte	W12
	.byte		N32   , An3 , v064
	.byte	W36
	.byte		N13   , An3 , v072
	.byte	W12
	.byte		N11   , Bn3 , v068
	.byte	W12
	.byte		N13   , Cs4 
	.byte	W12
	.byte		N11   , Bn3 
	.byte	W12
	.byte		N13   , An3 , v076
	.byte	W12
	.byte		N30   , Gn3 , v068
	.byte	W36
	.byte		N12   , Gn3 , v076
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N13   , Gn3 , v072
	.byte	W12
	.byte		N20   , Fs3 , v068
	.byte	W18
	.byte		N17   , As3 , v076
	.byte	W16
	.byte		N10   , Bn3 
	.byte	W14
	.byte		N20
	.byte	W18
	.byte		N16   , Cs4 
	.byte	W15
	.byte		N15   , Dn4 , v072
	.byte	W15
	.byte		N60   , En4 , v080
	.byte	W60
	.byte		N13   , Fs4 , v072
	.byte	W12
	.byte		N12   , Gn4 , v068
	.byte	W12
	.byte		N15   , Gs4 , v080
	.byte	W12
	.byte		N60   , An4 , v076
	.byte	W60
	.byte		N12   , As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N15   , Cn5 , v080
	.byte	W12
	.byte		N24   , Cs5 , v072
	.byte	W24
	.byte		N40   , An4 , v080
	.byte	W72
	.byte	GOTO
	 .word	mus_table_select_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_table_select_4:  @ 0x08689A3E
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 12
	.byte		VOL   , 85*mus_table_select_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W12
mus_table_select_4_B1:
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
	.byte	W48
	.byte		N03   , Dn3 , v076
	.byte		N03   , Fs3 , v084
	.byte	W18
	.byte		N02   , Fs3 , v072
	.byte	W01
	.byte		N01   , Dn3 , v056
	.byte	W05
	.byte		N23   , Dn3 , v080
	.byte		N24   , Fs3 , v088
	.byte	W24
	.byte	W44
	.byte	W03
	.byte		N01   , Cs3 , v072
	.byte		N03   , Fs3 , v080
	.byte	W18
	.byte		N01   , Cs3 , v060
	.byte		N01   , Fs3 
	.byte	W05
	.byte		N24   , Cs3 , v080
	.byte		N24   , Fs3 , v076
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N03   , Fs3 , v084
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W18
	.byte		N02   , Dn3 , v060
	.byte		N01   , Fs3 , v064
	.byte	W05
	.byte		N24   , Fs3 , v080
	.byte	W01
	.byte		        Dn3 , v076
	.byte	W24
	.byte	W44
	.byte	W03
	.byte		N02   , Cs3 , v068
	.byte		N04   , Fs3 , v072
	.byte	W17
	.byte		N02   , Cs3 , v068
	.byte		N01   , Fs3 
	.byte	W06
	.byte		N23   , Cs3 , v084
	.byte		N23   , Fs3 
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N04   , Gn3 
	.byte	W01
	.byte		N02   , Bn2 , v080
	.byte	W17
	.byte		N01   , Bn2 , v060
	.byte		N01   , Gn3 , v068
	.byte	W05
	.byte		N24   , Bn2 , v080
	.byte		N24   , Gn3 , v084
	.byte	W24
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N02   , Dn3 , v076
	.byte		N03   , Bn3 , v084
	.byte	W18
	.byte		N01   , Dn3 , v060
	.byte		N01   , Bn3 , v072
	.byte	W05
	.byte		N18   , Dn3 , v076
	.byte		N21   , Bn3 , v084
	.byte	W24
	.byte	W02
	.byte	W12
	.byte		N02   , En3 , v060
	.byte		N04   , Cn4 , v072
	.byte	W12
	.byte		N02   , Gn3 , v064
	.byte	W01
	.byte		        En3 , v048
	.byte	W10
	.byte		N04   , Cn4 , v076
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W24
	.byte		N03   , En3 , v068
	.byte		N04   , Cn4 , v076
	.byte	W11
	.byte		N02   , Gn3 , v064
	.byte	W01
	.byte		        En3 , v056
	.byte	W11
	.byte		N03   , En3 , v068
	.byte		N04   , Cn4 , v076
	.byte	W13
	.byte	W11
	.byte		N03   , En3 , v064
	.byte		N05   , Cs4 , v068
	.byte	W12
	.byte		N02   , En3 , v048
	.byte		N03   , Gn3 , v060
	.byte	W11
	.byte		        En3 
	.byte		N04   , Cs4 , v072
	.byte	W24
	.byte	W01
	.byte		N02   , En3 , v052
	.byte		N05   , Cs4 , v064
	.byte	W11
	.byte		N02   , En3 , v044
	.byte		N02   , Gn3 , v056
	.byte	W12
	.byte		N05   , Cs4 , v064
	.byte	W01
	.byte		N02   , En3 , v048
	.byte	W12
	.byte		N03
	.byte		N04   , Cs4 , v056
	.byte	W01
	.byte	W11
	.byte		N03   , En3 
	.byte		N04   , Cs4 , v060
	.byte	W12
	.byte		N02   , En3 , v056
	.byte		N04   , Cs4 , v060
	.byte	W12
	.byte		N02   , En3 
	.byte		N05   , Cs4 , v064
	.byte	W12
	.byte		N04   , En4 
	.byte	W01
	.byte		N05   , An3 
	.byte	W11
	.byte		N04   , An3 , v060
	.byte		N04   , En4 , v064
	.byte	W12
	.byte		        An3 , v060
	.byte		N04   , En4 
	.byte	W11
	.byte		        En4 , v068
	.byte	W01
	.byte		N05   , An3 , v072
	.byte	W13
	.byte	GOTO
	 .word	mus_table_select_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 06 ***********************@

mus_table_select_5:  @ 0x08689B75
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 48
	.byte		VOL   , 85*mus_table_select_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W12
mus_table_select_5_B1:
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
	.byte		N44   , Bn2 , v056
	.byte	W48
	.byte		        Dn3 , v052
	.byte	W48
	.byte		        Fs2 , v056
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		        Bn2 , v060
	.byte	W48
	.byte		        Dn3 
	.byte	W48
	.byte		        Fs2 , v064
	.byte	W48
	.byte		        Cs3 , v056
	.byte	W48
	.byte		        En2 , v064
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte		        Fs2 , v068
	.byte	W48
	.byte		        Bn2 , v064
	.byte	W48
	.byte		        Gn2 , v076
	.byte	W48
	.byte		        Cn3 , v068
	.byte	W48
	.byte		        An2 , v072
	.byte	W48
	.byte		        En3 , v068
	.byte	W48
	.byte		        En2 , v064
	.byte	W48
	.byte		N32   , Cs3 , v060
	.byte	W48
	.byte	GOTO
	 .word	mus_table_select_5_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 07 ***********************@

mus_table_select_6:  @ 0x08689BCD
	.byte	KEYSH , mus_table_select_key+0
	.byte		VOICE , 0
	.byte		VOL   , 51*mus_table_select_mvl/mxv
	.byte	W12
mus_table_select_6_B1:
	.byte		N04   , Dn1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W04
	.byte		        Dn1 , v076
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N04   , Dn1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PEND
mus_table_select_6_B2:
	.byte		N04   , Dn1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W04
	.byte		        Dn1 , v076
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N03
	.byte	W04
	.byte		N04   , Dn1 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N04
	.byte	W06
	.byte		N04
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
	.byte	PATT
	 .word	mus_table_select_6_B1
	.byte	PATT
	 .word	mus_table_select_6_B2
mus_table_select_6_B3:
	.byte		N06   , Cn1 , v100
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte	PATT
	 .word	mus_table_select_6_B3
	.byte		N06   , Cn1 , v100
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N09   , As1 
	.byte	W11
	.byte		N24   , Cs2 
	.byte	W01
	.byte	GOTO
	 .word	mus_table_select_6_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_table_select:  @ 0x08689CC0
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_table_select_pri	@ Priority
	.byte	mus_table_select_rev	@ Reverb

	.word	mus_table_select_grp

	.word	mus_table_select_0
	.word	mus_table_select_1
	.word	mus_table_select_2
	.word	mus_table_select_3
	.word	mus_table_select_4
	.word	mus_table_select_5
	.word	mus_table_select_6
