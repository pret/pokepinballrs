	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_groudon_grp, gUnknown_08532808
	.equ	mus_bonus_field_groudon_pri, 0
	.equ	mus_bonus_field_groudon_rev, reverb_set+50
	.equ	mus_bonus_field_groudon_mvl, 127
	.equ	mus_bonus_field_groudon_key, 0
	.equ	mus_bonus_field_groudon_tbs, 1
	.equ	mus_bonus_field_groudon_exg, 0
	.equ	mus_bonus_field_groudon_cmp, 1

	.section .rodata
	.global	mus_bonus_field_groudon
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_groudon_0:  @ 0x08698D50
	.byte	KEYSH , mus_bonus_field_groudon_key+0
	.byte	TEMPO , 110*mus_bonus_field_groudon_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 94*mus_bonus_field_groudon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N78   , Cn1 , v060
	.byte	W16
	.byte		N60   , Gn1 , v064
	.byte	W16
	.byte		N44   , Cn2 , v060
	.byte	W16
	.byte		N40   , Cs2 , v068
	.byte	W16
	.byte		N32   , Gs2 
	.byte	W16
	.byte		N18   , Cs3 
	.byte	W16
	.byte		N92   , Cn2 
	.byte	W16
	.byte		N76   , Gn2 , v072
	.byte	W16
	.byte		N60   , Cn3 
	.byte	W16
	.byte		N48   , Cs3 , v076
	.byte	W16
	.byte		N32   , Gs3 
	.byte	W16
	.byte		N16   , Cs4 , v084
	.byte	W16
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
mus_bonus_field_groudon_0_B1:
	.byte		N03   , Cn1 , v080
	.byte		N04   , Gn1 , v072
	.byte	W04
	.byte		N06   , Cn2 , v060
	.byte	W07
	.byte		N04   , Cn1 , v056
	.byte		N05   , Gn1 , v064
	.byte	W05
	.byte		N06   , Cn2 , v048
	.byte	W07
	.byte		N05   , Gn1 , v060
	.byte	W04
	.byte		        Cn2 , v048
	.byte	W07
	.byte		        Gn1 , v052
	.byte	W01
	.byte		N04   , Cn1 , v068
	.byte	W03
	.byte		N07   , Cn2 , v044
	.byte	W08
	.byte		N05   , Cs1 , v084
	.byte		N08   , Gs1 , v068
	.byte	W07
	.byte		N05   , Cs2 , v056
	.byte	W05
	.byte		N04   , Cs1 , v076
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v056
	.byte	W05
	.byte		        Cs2 , v048
	.byte	W06
	.byte		        Gs1 
	.byte	W02
	.byte		N04   , Cs1 , v068
	.byte	W03
	.byte		N06   , Cs2 , v048
	.byte	W07
	.byte		N07   , Gn1 , v072
	.byte	W01
	.byte		N04   , Cn1 , v084
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v064
	.byte	W06
	.byte		N04   , Cn1 
	.byte		N06   , Gn1 , v056
	.byte	W05
	.byte		N05   , Cn2 , v048
	.byte	W06
	.byte		        Gn1 , v056
	.byte	W06
	.byte		        Cn2 , v044
	.byte	W06
	.byte		        Gn1 , v056
	.byte	W02
	.byte		N04   , Cn1 , v076
	.byte	W03
	.byte		N07   , Cn2 , v044
	.byte	W07
	.byte		N06   , Gs1 , v076
	.byte	W01
	.byte		N05   , Cs1 
	.byte	W05
	.byte		N06   , Cs2 , v064
	.byte	W06
	.byte		N05   , Gs1 , v056
	.byte	W01
	.byte		N04   , Cs1 , v068
	.byte	W04
	.byte		N06   , Cs2 , v056
	.byte	W07
	.byte		N04   , Gs1 , v060
	.byte	W04
	.byte		N06   , Cs2 , v048
	.byte	W07
	.byte		        Gs1 
	.byte	W02
	.byte		N04   , Cs1 , v060
	.byte	W04
	.byte		N07   , Cs2 , v048
	.byte	W07
	.byte		N05   , Cn1 , v084
	.byte		N06   , Gn1 , v076
	.byte	W03
	.byte	W04
	.byte		N04   , Cn2 , v056
	.byte	W05
	.byte		        Cn1 , v072
	.byte		N05   , Gn1 , v056
	.byte	W06
	.byte		N06   , Cn2 , v044
	.byte	W07
	.byte		N05   , Gn1 , v060
	.byte	W05
	.byte		        Cn2 , v048
	.byte	W07
	.byte		N04   , Cn1 , v076
	.byte		N05   , Gn1 , v060
	.byte	W04
	.byte		N08   , Cn2 , v048
	.byte	W08
	.byte		N05   , Cs1 , v080
	.byte		N07   , Gs1 , v076
	.byte	W06
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W04
	.byte		N07   , Cs2 , v056
	.byte	W07
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W04
	.byte		N07   , Cs2 , v056
	.byte	W08
	.byte		N04   , Cn1 , v084
	.byte		N07   , Gn1 , v076
	.byte	W01
	.byte	W06
	.byte		N05   , Cn2 , v060
	.byte	W05
	.byte		N03   , Cn1 , v072
	.byte		N06   , Gn1 , v060
	.byte	W05
	.byte		        Cn2 , v048
	.byte	W08
	.byte		        Gn1 , v064
	.byte	W05
	.byte		N05   , Cn2 , v052
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W04
	.byte		N07   , Cn2 , v048
	.byte	W07
	.byte		N05   , Cs1 , v080
	.byte		N06   , Gs1 , v076
	.byte	W06
	.byte		        Cs2 , v064
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W01
	.byte		N04   , Cs1 , v068
	.byte	W04
	.byte		N07   , Cs2 , v060
	.byte	W07
	.byte		N05   , Gs1 , v064
	.byte	W04
	.byte		N06   , Cs2 , v056
	.byte	W07
	.byte		        Gs1 
	.byte	W02
	.byte		N03   , Cs1 , v072
	.byte	W03
	.byte		N07   , Cs2 , v052
	.byte	W08
	.byte		N04   , Cn1 , v084
	.byte		N06   , Gn1 , v072
	.byte	W01
	.byte	W05
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N04   , Cn1 , v076
	.byte		N06   , Gn1 , v060
	.byte	W05
	.byte		        Cn2 , v048
	.byte	W08
	.byte		N05   , Gn1 , v060
	.byte	W04
	.byte		        Cn2 , v048
	.byte	W06
	.byte		N06   , Gn1 , v060
	.byte	W02
	.byte		N04   , Cn1 , v076
	.byte	W03
	.byte		N07   , Cn2 , v048
	.byte	W07
	.byte		N06   , Gs1 , v076
	.byte	W01
	.byte		N04   , Cs1 , v084
	.byte	W05
	.byte		N05   , Cs2 , v064
	.byte	W05
	.byte		N06   , Gs1 , v060
	.byte	W01
	.byte		N04   , Cs1 , v068
	.byte	W04
	.byte		N06   , Cs2 , v060
	.byte	W07
	.byte		N05   , Gs1 
	.byte	W04
	.byte		N07   , Cs2 , v056
	.byte	W08
	.byte		N05   , Gs1 , v060
	.byte	W02
	.byte		N02   , Cs1 , v068
	.byte	W02
	.byte		N07   , Cs2 , v048
	.byte	W09
	.byte		N04   , Cn1 , v084
	.byte		N06   , Gn1 , v072
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N03   , Cn1 , v076
	.byte		N05   , Gn1 , v056
	.byte	W06
	.byte		N06   , Cn2 , v052
	.byte	W07
	.byte		N05   , Gn1 , v056
	.byte	W04
	.byte		N06   , Cn2 , v048
	.byte	W07
	.byte		N05   , Gn1 , v060
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W04
	.byte		N08   , Cn2 , v052
	.byte	W07
	.byte		N06   , Gs1 , v076
	.byte	W01
	.byte		N05   , Cs1 , v084
	.byte	W05
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W01
	.byte		N03   , Cs1 
	.byte	W04
	.byte		N07   , Cs2 , v056
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W06
	.byte		        Gs1 , v056
	.byte	W02
	.byte		N04   , Cs1 , v068
	.byte	W03
	.byte		N08   , Cs2 , v048
	.byte	W08
	.byte		N05   , As0 , v076
	.byte	W01
	.byte		        Fn1 , v068
	.byte	W01
	.byte		N06   , Gn1 , v076
	.byte	W01
	.byte		N04   , Cn1 
	.byte	W05
	.byte		N05   , Cn2 , v064
	.byte	W06
	.byte		N04   , Cn1 , v060
	.byte		N05   , Gn1 , v064
	.byte	W05
	.byte		        Cn2 , v060
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        Cn2 , v060
	.byte	W06
	.byte		N04   , Gn1 , v064
	.byte	W01
	.byte		        Cn1 , v068
	.byte	W03
	.byte		N07   , Cn2 , v048
	.byte	W07
	.byte		        Gs1 , v072
	.byte	W01
	.byte		N04   , Cs1 , v080
	.byte	W06
	.byte		N05   , Cs2 , v060
	.byte	W05
	.byte		        Gs1 , v064
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W04
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W02
	.byte		N03   , Cs1 , v064
	.byte	W03
	.byte		N07   , Cs2 , v048
	.byte	W08
	.byte		N05   , Cn1 , v076
	.byte		N06   , Gn1 , v068
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N04   , Cn1 , v072
	.byte		N06   , Gn1 , v060
	.byte	W05
	.byte		N05   , Cn2 , v044
	.byte	W07
	.byte		N06   , Gn1 , v060
	.byte	W05
	.byte		N05   , Cn2 , v040
	.byte	W06
	.byte		N06   , Gn1 , v056
	.byte	W03
	.byte		N04   , Cn1 , v076
	.byte	W03
	.byte		N07   , Cn2 , v048
	.byte	W07
	.byte		N06   , Gs1 , v072
	.byte	W01
	.byte		N05   , Cs1 , v080
	.byte	W05
	.byte		N06   , Cs2 , v064
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W02
	.byte		N04   , Cs1 , v068
	.byte	W03
	.byte		N06   , Cs2 , v056
	.byte	W06
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W08
	.byte		N04   , Gs1 , v060
	.byte	W01
	.byte		N03   , Cs1 , v064
	.byte	W03
	.byte		N07   , Cs2 , v048
	.byte	W08
	.byte		N05   , As0 , v080
	.byte		N06   , Fn1 , v072
	.byte	W02
	.byte		N04   , As1 , v084
	.byte		N04   , Fn2 , v076
	.byte	W04
	.byte		N05   , As2 , v064
	.byte	W06
	.byte		        Fn2 , v068
	.byte	W01
	.byte		        As1 , v076
	.byte	W05
	.byte		        As2 , v064
	.byte	W06
	.byte		        Fn2 , v072
	.byte	W06
	.byte		        As2 , v064
	.byte	W06
	.byte		        Fn2 , v060
	.byte	W01
	.byte		N03   , As1 , v080
	.byte	W03
	.byte		N08   , As2 , v056
	.byte	W09
	.byte		N04   , Cn2 , v080
	.byte		N06   , Gn2 , v076
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		N05   , Cn2 , v076
	.byte		N05   , Gn2 , v064
	.byte	W05
	.byte		N07   , Cn3 , v060
	.byte	W07
	.byte		N05   , Gn2 , v068
	.byte	W06
	.byte		N06   , Cn3 , v060
	.byte	W07
	.byte		N05   , Gn2 , v064
	.byte	W01
	.byte		N03   , Cn2 , v068
	.byte	W03
	.byte		N08   , Cn3 , v060
	.byte	W08
	.byte		N04   , Fn1 , v076
	.byte		N05   , Gs2 
	.byte	W05
	.byte		N07   , Cn3 , v060
	.byte	W07
	.byte		N04   , Fn1 , v072
	.byte		N05   , Gs2 
	.byte	W05
	.byte		N07   , Cn3 , v064
	.byte	W07
	.byte		N06   , Gs2 , v072
	.byte	W05
	.byte		        Cn3 , v060
	.byte	W06
	.byte		N05   , Gs2 
	.byte	W01
	.byte		N03   , Fn1 , v076
	.byte	W04
	.byte		N07   , Cn3 , v064
	.byte	W07
	.byte		N05   , Fs1 , v084
	.byte		N07   , As2 , v072
	.byte	W06
	.byte		N06   , Cs3 , v068
	.byte	W06
	.byte		N05   , Fs1 
	.byte		N06   , As2 
	.byte	W06
	.byte		N07   , Cs3 , v064
	.byte	W06
	.byte		N06   , As2 , v068
	.byte	W07
	.byte		        Cs3 , v060
	.byte	W05
	.byte		N04   , Fs1 , v076
	.byte		N06   , As2 , v060
	.byte	W06
	.byte		N05   , Cs3 , v056
	.byte	W06
	.byte		        Ds1 , v080
	.byte		N06   , As2 , v068
	.byte	W01
	.byte	W05
	.byte		        Ds3 , v064
	.byte	W06
	.byte		N05   , Ds1 , v072
	.byte		N05   , As2 , v064
	.byte	W04
	.byte		N07   , Ds3 , v060
	.byte	W07
	.byte		N05   , As2 , v068
	.byte	W05
	.byte		N07   , Ds3 , v056
	.byte	W07
	.byte		N04   , Ds1 , v072
	.byte		N05   , As2 , v068
	.byte	W05
	.byte		N07   , Ds3 , v060
	.byte	W07
	.byte		N04   , Ds1 , v076
	.byte		N06   , As2 , v072
	.byte	W05
	.byte		N07   , Ds3 , v056
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte		N05   , As2 , v072
	.byte	W05
	.byte		N08   , Ds3 , v056
	.byte	W07
	.byte		N06   , As2 , v072
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W06
	.byte		N05   , As2 
	.byte	W01
	.byte		N03   , Ds1 , v072
	.byte	W04
	.byte		N08   , Ds3 , v052
	.byte	W08
	.byte		N05   , Cn2 , v080
	.byte		N06   , Gn2 , v068
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		N05   , Cn2 , v080
	.byte		N06   , Gn2 , v068
	.byte	W05
	.byte		        Cn3 , v064
	.byte	W07
	.byte		        Gn2 , v068
	.byte	W05
	.byte		N07   , Cn3 , v048
	.byte	W07
	.byte		N04   , Cn2 , v076
	.byte		N05   , Gn2 , v068
	.byte	W05
	.byte		N07   , Cn3 , v064
	.byte	W06
	.byte		N05   , Cs2 , v084
	.byte		N06   , Gs2 , v076
	.byte	W06
	.byte		        Cs3 , v068
	.byte	W06
	.byte		        Gs2 
	.byte	W01
	.byte		N05   , Cs2 , v072
	.byte	W04
	.byte		N06   , Cs3 , v060
	.byte	W06
	.byte		        Gs2 , v056
	.byte	W05
	.byte		N07   , Cs3 , v052
	.byte	W08
	.byte		N05   , Gs2 , v056
	.byte	W01
	.byte		N04   , Cs2 , v072
	.byte	W04
	.byte		N06   , Cs3 , v048
	.byte	W07
	.byte		N05   , Cn2 , v084
	.byte		N06   , Gn2 , v068
	.byte	W01
	.byte	W05
	.byte		N05   , Cn3 , v060
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W01
	.byte		        Gn2 , v056
	.byte	W04
	.byte		        Cn3 , v048
	.byte	W07
	.byte		        Gn2 , v056
	.byte	W05
	.byte		        Cn3 , v048
	.byte	W07
	.byte		N04   , Cn2 , v084
	.byte		N04   , Gn2 , v060
	.byte	W04
	.byte		N08   , Cn3 , v052
	.byte	W07
	.byte		N06   , Gs2 , v076
	.byte	W01
	.byte		N05   , Cs2 , v080
	.byte	W05
	.byte		N06   , Cs3 , v060
	.byte	W06
	.byte		N07   , Gs2 
	.byte	W01
	.byte		N05   , Cs2 , v072
	.byte	W05
	.byte		N07   , Cs3 , v060
	.byte	W08
	.byte		N06   , Gs2 , v072
	.byte	W06
	.byte		N07   , Cs3 , v056
	.byte	W05
	.byte		N03   , Cs2 , v068
	.byte	W01
	.byte		N05   , Gs2 , v052
	.byte	W05
	.byte		N01   , Cs3 
	.byte	W07
	.byte	W01
	.byte		N03   , Cn1 , v080
	.byte	W01
	.byte		N05   , Gn1 , v064
	.byte	W04
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn1 , v076
	.byte		N06   , Gn1 , v064
	.byte	W05
	.byte		N05   , Cn2 , v052
	.byte	W05
	.byte		N06   , Gn1 , v060
	.byte	W05
	.byte		N05   , Cn2 , v056
	.byte	W07
	.byte		N03   , Cn1 , v076
	.byte		N05   , Gn1 , v060
	.byte	W05
	.byte		N06   , Cn2 , v052
	.byte	W06
	.byte		N05   , Cs1 , v080
	.byte		N06   , Gs1 , v072
	.byte	W06
	.byte		N05   , Cs2 , v060
	.byte	W06
	.byte		N06   , Gs1 , v056
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W05
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		N04   , Gs1 , v064
	.byte	W02
	.byte		N03   , Cs1 , v072
	.byte	W03
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		N06   , Gn1 , v072
	.byte	W01
	.byte		N04   , Cn1 , v084
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W01
	.byte		N04   , Cn1 , v068
	.byte	W05
	.byte		N06   , Cn2 , v052
	.byte	W07
	.byte		        Gn1 , v068
	.byte	W06
	.byte		N05   , Cn2 , v052
	.byte	W06
	.byte		        Gn1 , v072
	.byte	W01
	.byte		N04   , Cn1 
	.byte	W04
	.byte		N07   , Cn2 , v052
	.byte	W07
	.byte		N06   , Gs1 , v076
	.byte	W01
	.byte		N05   , Cs1 
	.byte	W05
	.byte		N06   , Cs2 , v064
	.byte	W06
	.byte		        Gs1 
	.byte	W01
	.byte		N04   , Cs1 , v068
	.byte	W04
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		N07   , Cs2 , v056
	.byte	W08
	.byte		N03   , Cs1 , v076
	.byte		N05   , Gs1 , v060
	.byte	W04
	.byte		N07   , Cs2 , v048
	.byte	W07
	.byte		N06   , Gn1 , v072
	.byte	W01
	.byte		N04   , Cn1 , v084
	.byte	W01
	.byte	W05
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N04   , Cn1 , v080
	.byte		N06   , Gn1 , v068
	.byte	W05
	.byte		N05   , Cn2 , v048
	.byte	W07
	.byte		N06   , Gn1 , v064
	.byte	W06
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		N04   , Cn1 , v076
	.byte		N04   , Gn1 , v060
	.byte	W04
	.byte		N07   , Cn2 , v056
	.byte	W07
	.byte		N06   , Gs1 , v076
	.byte	W01
	.byte		N05   , Cs1 , v084
	.byte	W05
	.byte		N06   , Cs2 , v064
	.byte	W06
	.byte		N05   , Gs1 
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W04
	.byte		N07   , Cs2 , v060
	.byte	W07
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N05   , Gs1 , v064
	.byte	W02
	.byte		N03   , Cs1 , v072
	.byte	W04
	.byte		N06   , Cs2 , v056
	.byte	W07
	.byte		N04   , Cn1 , v084
	.byte		N06   , Gn1 , v076
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		        Gn1 
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W04
	.byte		N06   , Cn2 , v048
	.byte	W08
	.byte		        Gn1 , v064
	.byte	W05
	.byte		N04   , Cn2 , v056
	.byte	W06
	.byte		N06   , Gn1 , v064
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W04
	.byte		N07   , Cn2 , v056
	.byte	W08
	.byte		N05   , Cs1 , v084
	.byte		N06   , Gs1 , v080
	.byte	W06
	.byte		        Cs2 , v060
	.byte	W06
	.byte		N04   , Cs1 , v068
	.byte		N06   , Gs1 , v064
	.byte	W05
	.byte		        Cs2 , v060
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N07   , Cs2 , v056
	.byte	W07
	.byte		N02   , Cs1 , v072
	.byte		N05   , Gs1 , v056
	.byte	W04
	.byte		N07   , Cs2 , v048
	.byte	W08
	.byte		N04   , Cn1 , v088
	.byte		N06   , Gn1 , v068
	.byte	W01
	.byte	W05
	.byte		N05   , Cn2 , v056
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W05
	.byte		N05   , Cn2 , v048
	.byte	W06
	.byte		N06   , Gn1 , v060
	.byte	W07
	.byte		N05   , Cn2 , v056
	.byte	W06
	.byte		N04   , Cn1 , v068
	.byte		N05   , Gn1 , v060
	.byte	W04
	.byte		N06   , Cn2 , v052
	.byte	W07
	.byte		N05   , Cs1 , v080
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N05   , Cs2 , v060
	.byte	W05
	.byte		N06   , Gs1 , v056
	.byte	W01
	.byte		N04   , Cs1 , v076
	.byte	W06
	.byte		N06   , Cs2 , v056
	.byte	W06
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N07   , Cs2 , v056
	.byte	W08
	.byte		N03   , Cs1 , v076
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		N06   , Cs2 , v044
	.byte	W06
	.byte		N04   , Cn1 , v084
	.byte		N06   , Gn1 , v072
	.byte	W01
	.byte	W06
	.byte		N05   , Cn2 , v064
	.byte	W06
	.byte		N04   , Cn1 , v072
	.byte		N06   , Gn1 , v060
	.byte	W06
	.byte		N05   , Cn2 , v048
	.byte	W06
	.byte		N06   , Gn1 , v056
	.byte	W06
	.byte		N04   , Cn2 , v048
	.byte	W05
	.byte		        Cn1 , v076
	.byte	W01
	.byte		N05   , Gn1 , v060
	.byte	W04
	.byte		N07   , Cn2 , v044
	.byte	W07
	.byte		N05   , Cs1 , v084
	.byte		N06   , Gs1 , v080
	.byte	W06
	.byte		N05   , Cs2 , v060
	.byte	W05
	.byte		        Gs1 
	.byte	W01
	.byte		N04   , Cs1 , v068
	.byte	W05
	.byte		N06   , Cs2 , v056
	.byte	W06
	.byte		N04   , Gs1 , v064
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v064
	.byte	W01
	.byte		N02   , Cs1 , v072
	.byte	W04
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N03   , Cn1 , v080
	.byte		N06   , Gn1 , v076
	.byte	W02
	.byte	W04
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W05
	.byte		N05   , Cn2 , v044
	.byte	W07
	.byte		        Gn1 , v064
	.byte	W05
	.byte		        Cn2 , v052
	.byte	W06
	.byte		        Gn1 , v068
	.byte	W01
	.byte		N04   , Cn1 , v076
	.byte	W04
	.byte		N07   , Cn2 , v044
	.byte	W07
	.byte		N06   , Gs1 , v080
	.byte	W01
	.byte		N04   , Cs1 
	.byte	W06
	.byte		N05   , Cs2 , v060
	.byte	W05
	.byte		N06   , Gs1 
	.byte	W01
	.byte		N04   , Cs1 , v072
	.byte	W05
	.byte		N05   , Cs2 , v056
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W06
	.byte		        Cs2 , v056
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W01
	.byte		N03   , Cs1 , v076
	.byte	W05
	.byte		N05   , Cs2 , v056
	.byte	W06
	.byte		N06   , Gn1 , v076
	.byte	W01
	.byte		N04   , Cn1 , v084
	.byte	W01
	.byte	W05
	.byte		        Cn2 , v060
	.byte	W05
	.byte		N05   , Gn1 
	.byte	W01
	.byte		N04   , Cn1 , v068
	.byte	W05
	.byte		        Cn2 , v056
	.byte	W06
	.byte		N06   , Gn1 , v064
	.byte	W06
	.byte		N05   , Cn2 , v056
	.byte	W07
	.byte		        Gn1 
	.byte	W01
	.byte		N03   , Cn1 , v080
	.byte	W04
	.byte		N06   , Cn2 , v044
	.byte	W06
	.byte		        Gs1 , v072
	.byte	W01
	.byte		N05   , Cs1 , v084
	.byte	W06
	.byte		        Cs2 , v060
	.byte	W06
	.byte		N04   , Cs1 , v076
	.byte		N05   , Gs1 , v060
	.byte	W06
	.byte		        Cs2 , v056
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W01
	.byte		N04   , Cs1 , v076
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N04   , Cn1 , v084
	.byte		N06   , Gn1 , v072
	.byte	W06
	.byte		N04   , Cn2 , v060
	.byte	W05
	.byte		        Cn1 , v076
	.byte	W01
	.byte		N06   , Gn1 , v056
	.byte	W06
	.byte		N04   , Cn2 , v048
	.byte	W06
	.byte		N06   , Gn1 , v060
	.byte	W06
	.byte		N03   , Cn2 , v056
	.byte	W06
	.byte		N05   , Gn1 , v060
	.byte	W01
	.byte		N03   , Cn1 , v076
	.byte	W04
	.byte		N06   , Cn2 , v056
	.byte	W06
	.byte		        Gs1 , v076
	.byte	W01
	.byte		N04   , Cs1 
	.byte	W05
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		N04   , Cs1 , v072
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W02
	.byte		N03   , Cs1 , v076
	.byte	W04
	.byte		N06   , Cs2 , v056
	.byte	W06
	.byte		        Gn1 , v076
	.byte	W01
mus_bonus_field_groudon_0_B2:
	.byte		N04   , Cn1 , v084
	.byte	W06
	.byte		N05   , Cn2 , v060
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W05
	.byte		N06   , Cn2 , v048
	.byte	W07
	.byte		        Gn1 , v064
	.byte	W06
	.byte		N05   , Cn2 , v056
	.byte	W06
	.byte		N03   , Cn1 , v080
	.byte	W01
	.byte		N05   , Gn1 , v064
	.byte	W03
	.byte		N07   , Cn2 , v048
	.byte	W07
	.byte		N05   , Cs1 , v080
	.byte		N06   , Gs1 , v076
	.byte	W07
	.byte		N05   , Cs2 , v060
	.byte	W05
	.byte		        Cs1 , v076
	.byte		N06   , Gs1 , v064
	.byte	W06
	.byte		        Cs2 , v056
	.byte	W07
	.byte		N05   , Gs1 , v060
	.byte	W05
	.byte		N06   , Cs2 , v056
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W02
	.byte		N03   , Cs1 , v084
	.byte	W04
	.byte		N06   , Cs2 , v052
	.byte	W07
	.byte	PEND
	.byte		N04   , Cn1 , v088
	.byte		N06   , Gn1 , v068
	.byte	W08
	.byte		N05   , Cn2 , v052
	.byte	W04
	.byte		N04   , Cn1 , v076
	.byte	W01
	.byte		N05   , Gn1 , v056
	.byte	W05
	.byte		N06   , Cn2 , v052
	.byte	W07
	.byte		N05   , Gn1 , v064
	.byte	W05
	.byte		N06   , Cn2 , v048
	.byte	W06
	.byte		N04   , Cn1 , v076
	.byte	W01
	.byte		        Gn1 , v064
	.byte	W05
	.byte		N07   , Cn2 , v048
	.byte	W06
	.byte		N05   , Cs1 , v084
	.byte		N06   , Gs1 , v076
	.byte	W06
	.byte		        Cs2 , v060
	.byte	W06
	.byte		        Gs1 , v064
	.byte	W01
	.byte		N05   , Cs1 , v080
	.byte	W05
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		        Gs1 , v064
	.byte	W05
	.byte		N07   , Cs2 , v052
	.byte	W06
	.byte		N04   , Cs1 , v080
	.byte		N05   , Gs1 , v064
	.byte	W05
	.byte		        Cs2 , v052
	.byte	W08
	.byte	PATT
	 .word	mus_bonus_field_groudon_0_B2
	.byte	GOTO
	 .word	mus_bonus_field_groudon_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_groudon_1:  @ 0x08699535
	.byte	KEYSH , mus_bonus_field_groudon_key+0
	.byte		VOICE , 49
	.byte		VOL   , 85*mus_bonus_field_groudon_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W01
	.byte		N24   , Cn2 , v048
	.byte	W03
mus_bonus_field_groudon_1_B1:
	.byte	W19
	.byte		N19   , Gn2 , v060
	.byte	W16
	.byte		N17   , Cn3 , v064
	.byte	W15
	.byte		N20   , Cs3 , v068
	.byte	W18
	.byte		N16   , Gs2 , v072
	.byte	W15
	.byte		        Cs2 , v060
	.byte	W13
	.byte	W02
	.byte		N20   , Cn2 , v052
	.byte	W18
	.byte		N18   , Gn2 , v056
	.byte	W14
	.byte		N17   , Cn3 , v068
	.byte	W15
	.byte		N19   , Cs3 
	.byte	W18
	.byte		N16   , Gs2 
	.byte	W15
	.byte		        Cs2 , v060
	.byte	W14
	.byte	W01
	.byte		N20   , Cn2 , v052
	.byte	W18
	.byte		N17   , Gn2 , v056
	.byte	W15
	.byte		        Cn3 , v068
	.byte	W15
	.byte		N19   , Cs3 
	.byte	W18
	.byte		N16   , Gs2 
	.byte	W15
	.byte		N17   , Cs2 , v056
	.byte	W14
	.byte	W01
	.byte		N21   , Cn2 , v052
	.byte	W18
	.byte		N18   , Gn2 , v060
	.byte	W17
	.byte		N17   , Cn3 , v076
	.byte	W15
	.byte		N21   , Cs3 , v072
	.byte	W18
	.byte		N18   , Gs2 , v064
	.byte	W17
	.byte		N17   , Cs2 , v056
	.byte	W10
	.byte	W06
	.byte		N19   , Cn2 , v052
	.byte	W13
	.byte		N18   , Gn2 , v056
	.byte	W16
	.byte		N16   , Cn3 , v072
	.byte	W14
	.byte		N21   , Cs3 , v068
	.byte	W19
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N15   , Cs2 , v060
	.byte	W12
	.byte	W01
	.byte		N20   , Cn2 , v052
	.byte	W17
	.byte		N19   , Gn2 , v064
	.byte	W16
	.byte		N16   , Cn3 , v068
	.byte	W15
	.byte		N22   , Cs3 , v072
	.byte	W20
	.byte		N15   , Gs2 , v064
	.byte	W14
	.byte		N17   , Cs2 , v056
	.byte	W13
	.byte	W03
	.byte		N19   , Cn2 , v048
	.byte	W17
	.byte		N18   , Gn2 , v068
	.byte	W15
	.byte		N16   , Cn3 , v072
	.byte	W15
	.byte		N20   , Cs3 , v076
	.byte	W18
	.byte		N14   , Gs2 , v068
	.byte	W13
	.byte		N16   , Cs2 , v056
	.byte	W15
	.byte		N20   , Cn2 
	.byte	W16
	.byte		N18   , Gn2 , v064
	.byte	W16
	.byte		        Cn3 , v076
	.byte	W16
	.byte		N22   , Cs3 , v072
	.byte	W20
	.byte		N19   , Gs2 
	.byte	W17
	.byte		N16   , Cs2 , v056
	.byte	W11
	.byte	W04
	.byte		N18   , As1 , v068
	.byte	W16
	.byte		N13   , Fn2 , v060
	.byte	W15
	.byte		N16   , Cs3 , v072
	.byte	W14
	.byte		N21   , Cn3 
	.byte	W19
	.byte		N16   , Gn3 , v076
	.byte	W16
	.byte		N15   , Cn3 , v072
	.byte	W12
	.byte	W02
	.byte		N17   , Fn3 
	.byte	W17
	.byte		N18   , Cn4 , v076
	.byte	W17
	.byte		N14   , Fn3 , v072
	.byte	W13
	.byte		N19   , As3 
	.byte	W17
	.byte		N16   , Fs3 , v076
	.byte	W16
	.byte		N15   , Cs3 , v060
	.byte	W14
	.byte		N18   , Ds3 , v076
	.byte	W17
	.byte		N15   , Fs3 , v072
	.byte	W14
	.byte		N18   , As3 , v068
	.byte	W16
	.byte		N20   , Ds4 , v076
	.byte	W17
	.byte		        As3 
	.byte	W17
	.byte		N15   , Fs3 , v068
	.byte	W15
	.byte		N22   , Cn3 , v064
	.byte	W18
	.byte		N15   , Gn3 , v076
	.byte	W15
	.byte		N18   , Cn4 , v072
	.byte	W20
	.byte		N16   , Fn4 , v076
	.byte	W14
	.byte		N14   , Cs4 , v072
	.byte	W16
	.byte		N16   , Gs3 , v064
	.byte	W13
	.byte	W01
	.byte		N22   , Cn3 , v056
	.byte	W17
	.byte		N18   , Gn3 , v068
	.byte	W16
	.byte		N17   , Cn4 , v076
	.byte	W15
	.byte		N19   , Fn4 , v080
	.byte	W17
	.byte		        Cs4 , v072
	.byte	W17
	.byte		N14   , Gs3 , v068
	.byte	W13
	.byte	W02
	.byte		N21   , Cn2 , v064
	.byte	W18
	.byte		N18   , Gn2 
	.byte	W16
	.byte		N16   , Cn3 , v072
	.byte	W14
	.byte		N20   , Fn3 , v080
	.byte	W18
	.byte		N16   , Cs3 , v064
	.byte	W15
	.byte		N15   , Gs2 
	.byte	W13
	.byte	W02
	.byte		N19   , Cn2 
	.byte	W15
	.byte		N17   , Gn2 
	.byte	W16
	.byte		N15   , Cn3 , v068
	.byte	W14
	.byte		N23   , Fn3 , v076
	.byte	W20
	.byte		N16   , Cs3 , v064
	.byte	W17
	.byte		N15   , Gs2 , v060
	.byte	W12
	.byte	W02
	.byte		N20   , Cn2 , v064
	.byte	W18
	.byte		N18   , Gn2 
	.byte	W15
	.byte		N16   , Cn3 
	.byte	W15
	.byte		N22   , Cs3 , v068
	.byte	W19
	.byte		N17   , Gs2 , v064
	.byte	W16
	.byte		N15   , Cs2 , v060
	.byte	W11
	.byte	W03
	.byte		N17   , Cn2 
	.byte	W15
	.byte		N18   , Gn2 , v056
	.byte	W16
	.byte		N17   , Cn3 , v064
	.byte	W16
	.byte		N21   , Cs3 , v068
	.byte	W19
	.byte		N17   , Gs2 , v072
	.byte	W16
	.byte		N15   , Cs2 , v060
	.byte	W11
	.byte	W03
	.byte		N21   , Cn2 , v064
	.byte	W17
	.byte		N17   , Gn2 , v060
	.byte	W15
	.byte		N16   , Cn3 , v068
	.byte	W15
	.byte		N21   , Cs3 , v072
	.byte	W19
	.byte		N16   , Gs2 
	.byte	W15
	.byte		N14   , Cs2 , v064
	.byte	W12
	.byte	W01
	.byte		N20   , Cn2 
	.byte	W17
	.byte		N17   , Gn2 , v068
	.byte	W16
	.byte		N16   , Cn3 , v072
	.byte	W16
	.byte		N20   , Cs3 , v076
	.byte	W18
	.byte		N17   , Gs2 , v068
	.byte	W17
	.byte		N15   , Cs2 , v064
	.byte	W11
	.byte	W03
	.byte		N20   , Cn2 , v068
	.byte	W17
	.byte		N17   , Gn2 
	.byte	W16
	.byte		        Cn3 , v076
	.byte	W16
	.byte		N20   , Cs3 , v072
	.byte	W17
	.byte		N17   , Gs2 , v076
	.byte	W16
	.byte		N15   , Cs2 , v064
	.byte	W11
	.byte	W02
	.byte		N20   , Dn2 , v076
	.byte	W17
	.byte		N15   , An2 , v080
	.byte	W15
	.byte		N18   , Dn3 , v076
	.byte	W17
	.byte		N13   , Ds3 , v080
	.byte	W12
	.byte		N12   , As2 , v072
	.byte	W10
	.byte		N11   , En3 , v076
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W11
	.byte		N22   , Cn2 
	.byte	W18
	.byte		N16   , Gn2 
	.byte	W15
	.byte		        Cn3 , v076
	.byte	W16
	.byte		N21   , Cs3 , v080
	.byte	W18
	.byte		N18   , Gs2 , v076
	.byte	W16
	.byte		N17   , Cs2 , v064
	.byte	W13
	.byte	W03
	.byte		        Dn2 , v076
	.byte	W17
	.byte		N18   , An2 
	.byte	W17
	.byte		N15   , Dn3 , v068
	.byte	W14
	.byte		N12   , Ds3 , v076
	.byte	W11
	.byte		        As2 , v068
	.byte	W11
	.byte		        En3 , v076
	.byte	W12
	.byte		        Bn2 , v064
	.byte	W11
	.byte		N24   , Cn2 
	.byte	W20
	.byte		N16   , Cn3 
	.byte	W16
	.byte		        Gn2 , v068
	.byte	W14
	.byte		N19   , Cs3 , v064
	.byte	W17
	.byte		N18   , Gs2 , v076
	.byte	W19
	.byte		N16   , Cs2 , v060
	.byte	W10
	.byte	W04
	.byte		N20   , Cn2 , v064
	.byte	W17
	.byte		N17   , Cn3 , v072
	.byte	W15
	.byte		N15   , Gn2 , v056
	.byte	W14
	.byte		N19   , Cs3 , v072
	.byte	W18
	.byte		N13   , Gs2 
	.byte	W13
	.byte		N16   , Cs2 , v060
	.byte	W15
	.byte	GOTO
	 .word	mus_bonus_field_groudon_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_groudon_2:  @ 0x08699796
	.byte	KEYSH , mus_bonus_field_groudon_key+0
	.byte		VOICE , 56
	.byte		VOL   , 108*mus_bonus_field_groudon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W92
	.byte	W02
	.byte		N24   , Gn3 , v100
	.byte		N24   , Cn4 
	.byte	W02
	.byte	W28
	.byte		N01   , Cn4 , v076
	.byte	W05
	.byte		N02   , Cn4 , v088
	.byte	W05
	.byte		N03   , Cn4 , v084
	.byte	W06
	.byte		N04   , Gs3 , v096
	.byte		N04   , Cs4 
	.byte	W13
	.byte		N17   , Gs3 , v100
	.byte	W24
	.byte	W01
	.byte		N04   , Gs3 , v096
	.byte		N04   , Cs4 , v092
	.byte	W14
	.byte		N21   , Gn3 , v100
	.byte		N24   , Cn4 , v108
	.byte	W28
	.byte	W01
	.byte		N01   , Cn4 , v084
	.byte	W05
	.byte		        Cn4 , v088
	.byte	W05
	.byte		        Cn4 , v092
	.byte	W06
	.byte		N03   , Cs4 , v100
	.byte	W01
	.byte		N01   , Gs3 , v076
	.byte	W11
	.byte		N17   , Gs3 , v100
	.byte	W23
	.byte		N04   , Gs3 , v092
	.byte		N05   , Cs4 , v096
	.byte	W16
mus_bonus_field_groudon_2_B1:
	.byte	W96
	.byte	W96
	.byte		N21   , Cn4 , v100
	.byte	W20
	.byte		N17   , Gn3 , v096
	.byte	W15
	.byte		N15   , Fs3 , v100
	.byte	W14
	.byte		N44   , Cs3 , v096
	.byte	W44
	.byte	W03
	.byte	W02
	.byte		N22   , Cn3 , v092
	.byte	W18
	.byte		N18   , Gn3 , v096
	.byte	W17
	.byte		N17   , Fs3 
	.byte	W14
	.byte		N40   , Cs4 
	.byte	W44
	.byte	W01
	.byte	W02
	.byte		N24   , Cn4 
	.byte	W28
	.byte	W01
	.byte		N06   , Cn4 , v084
	.byte	W06
	.byte		N04   , Cs4 , v092
	.byte	W14
	.byte		N24   , Fn4 , v100
	.byte	W23
	.byte		N06   , Ds4 , v096
	.byte	W11
	.byte		N04   , Cs4 , v088
	.byte	W11
	.byte	W01
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N40   , Gn3 , v096
	.byte	W80
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W01
	.byte		N19   , Cs4 , v100
	.byte	W17
	.byte		N18   , Fn3 , v096
	.byte	W16
	.byte		N16   , Cs4 , v092
	.byte	W15
	.byte		N28   , Cn4 
	.byte	W32
	.byte	W02
	.byte		N16   , Cn4 , v072
	.byte	W13
	.byte	W01
	.byte		N18   , Fn4 , v100
	.byte	W16
	.byte		        Gs3 , v092
	.byte	W16
	.byte		N15   , Fn4 , v100
	.byte	W14
	.byte		N28   , Cs4 , v096
	.byte	W36
	.byte	W01
	.byte		N13   , Cs4 , v088
	.byte	W11
	.byte		N12   , Fs4 , v084
	.byte	W01
	.byte	W11
	.byte		N14   , Fn4 , v092
	.byte	W12
	.byte		N13   , Ds4 
	.byte	W12
	.byte		N12   , Cs4 , v088
	.byte	W11
	.byte		        Cn4 
	.byte	W12
	.byte		N14   , As3 , v084
	.byte	W13
	.byte		N13   , Gs3 
	.byte	W11
	.byte		N14   , As3 , v088
	.byte	W13
	.byte		TIE   , Cn4 , v084
	.byte	W01
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		EOT
	.byte	W01
	.byte		N28   , Cn4 , v100
	.byte	W32
	.byte	W01
	.byte		N04   , Cn4 , v088
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , Fn4 , v096
	.byte	W44
	.byte	W01
	.byte		N24   , Cn4 , v100
	.byte	W30
	.byte	W01
	.byte		N05   , Cn4 , v084
	.byte	W05
	.byte		N04   , Gn3 , v088
	.byte	W06
	.byte		N07   , Fs4 , v076
	.byte	W06
	.byte		N06   , Fn4 , v096
	.byte	W05
	.byte		N07   , Ds4 
	.byte	W07
	.byte		N24   , Cs4 , v092
	.byte	W36
	.byte		N21   , Gn4 , v104
	.byte	W19
	.byte		N19   , Ds4 , v100
	.byte	W17
	.byte		N14   , Cn4 , v092
	.byte	W14
	.byte		N21   , Gs3 , v096
	.byte	W18
	.byte		N10   , Fn4 
	.byte	W28
	.byte	W01
	.byte		N20   , Gn4 , v100
	.byte	W18
	.byte		N19   , Ds4 , v096
	.byte	W17
	.byte		N15   , Cn4 
	.byte	W14
	.byte		N21   , Gs4 , v104
	.byte	W18
	.byte		N09   , Cs4 , v080
	.byte	W28
	.byte	W02
	.byte		N19   , Gn3 , v100
	.byte	W18
	.byte		N18   , Ds3 , v088
	.byte	W16
	.byte		N15   , Cn3 , v092
	.byte	W13
	.byte		N21   , Gs2 , v088
	.byte	W18
	.byte		N11   , Fn3 
	.byte	W28
	.byte	W01
	.byte		N20   , Gn3 , v096
	.byte	W18
	.byte		N19   , Ds3 
	.byte	W17
	.byte		N17   , Cn3 , v092
	.byte	W15
	.byte		N19   , Gs3 , v096
	.byte	W17
	.byte		N08   , Cs3 , v080
	.byte	W28
	.byte	W01
	.byte	W01
	.byte		N48   , Gn3 , v096
	.byte	W01
	.byte		        Cn3 , v088
	.byte	W48
	.byte		        Cs3 
	.byte		N48   , Gs3 , v084
	.byte	W44
	.byte	W02
	.byte	W02
	.byte		N44   , Dn3 , v072
	.byte		N48   , An3 , v092
	.byte	W44
	.byte	W02
	.byte		N24   , As3 , v076
	.byte	W01
	.byte		        Ds3 
	.byte	W23
	.byte		N10   , Bn3 
	.byte	W01
	.byte		N09   , En3 , v064
	.byte	W08
	.byte		N08   , Ds3 , v072
	.byte		N09   , As3 , v092
	.byte	W08
	.byte		        En3 , v088
	.byte		N09   , Bn3 , v100
	.byte	W07
	.byte		N52   , Cn4 , v092
	.byte	W01
	.byte		        Cn3 , v084
	.byte	W48
	.byte	W01
	.byte		N48   , Cs4 , v100
	.byte	W01
	.byte		        Cs3 , v088
	.byte	W44
	.byte	W01
	.byte	W03
	.byte		N44   , Dn3 
	.byte		N44   , Dn4 , v096
	.byte	W44
	.byte	W02
	.byte		N24   , Ds3 , v092
	.byte		N24   , Ds4 , v100
	.byte	W24
	.byte		N09   , En3 , v084
	.byte		N09   , En4 , v096
	.byte	W07
	.byte		        Ds4 
	.byte	W01
	.byte		        Ds3 , v092
	.byte	W07
	.byte		N08   , En4 , v096
	.byte	W01
	.byte		N09   , En3 , v092
	.byte	W07
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_groudon_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_groudon_3:  @ 0x08699970
	.byte	KEYSH , mus_bonus_field_groudon_key+0
	.byte		VOICE , 47
	.byte		VOL   , 85*mus_bonus_field_groudon_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
mus_bonus_field_groudon_3_B1:
	.byte		N04   , Cn2 , v092
	.byte	W30
	.byte		N01   , Cn2 , v072
	.byte	W06
	.byte		N03   , Cn2 , v076
	.byte	W06
	.byte		N02   , Cn2 , v064
	.byte	W06
	.byte		N03   , Cs2 , v088
	.byte	W12
	.byte		N04   , Cs2 , v084
	.byte	W24
	.byte		N03   , Cs2 , v080
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_groudon_3_B1
mus_bonus_field_groudon_3_B2:
	.byte		N04   , Cn2 , v088
	.byte	W12
	.byte		N03   , Cn2 , v076
	.byte	W24
	.byte		N04   , Cn2 , v080
	.byte	W12
	.byte		N03   , Cs2 , v076
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N03   , Cs2 , v080
	.byte	W12
mus_bonus_field_groudon_3_B3:
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		N02   , Cn2 , v076
	.byte	W12
	.byte		N04   , Cs2 , v080
	.byte	W12
	.byte		N03   , Cs2 , v072
	.byte	W24
	.byte		N02   , Cs2 , v068
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_groudon_3_B3
	.byte		N04   , Cn2 , v080
	.byte	W12
	.byte		        Cn2 , v064
	.byte	W24
	.byte		        Cn2 , v080
	.byte	W12
	.byte		N03   , Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 , v072
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		        Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W24
	.byte		N03   , Cs2 , v080
	.byte	W12
	.byte		N04   , Cn2 
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		        Cn2 , v076
	.byte	W12
	.byte		N04   , Cs2 , v080
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W24
	.byte		N02
	.byte	W12
	.byte		N03   , Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v072
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v080
	.byte	W24
	.byte		N04   , Cs2 , v068
	.byte	W12
	.byte		        As1 , v084
	.byte	W12
	.byte		        As1 , v072
	.byte	W24
	.byte		        As1 , v076
	.byte	W12
	.byte		N03   , Cn2 , v084
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W24
	.byte		N03
	.byte	W12
	.byte		        Fn2 , v088
	.byte	W12
	.byte		N04   , Fn2 , v084
	.byte	W24
	.byte		N02   , Fn2 , v076
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N04   , Fs2 , v084
	.byte	W24
	.byte		N03   , Fs2 , v080
	.byte	W12
	.byte		N04   , Ds2 , v084
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N03
	.byte	W12
	.byte		N04
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		        Ds2 , v080
	.byte	W12
	.byte		        Cn2 , v084
	.byte	W12
	.byte		        Cn2 , v080
	.byte	W24
	.byte		        Cn2 , v076
	.byte	W12
	.byte		        Cs2 , v080
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N03
	.byte	W12
	.byte		N04   , Cn2 
	.byte	W12
	.byte		N03   , Cn2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		        Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v080
	.byte	W24
	.byte		        Cs2 , v072
	.byte	W12
	.byte		        Cn2 , v084
	.byte	W12
	.byte		N03   , Cn2 , v072
	.byte	W24
	.byte		N04   , Cn2 , v080
	.byte	W12
	.byte		        Cs2 , v084
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		        Cs2 , v080
	.byte	W12
	.byte		N04   , Cn2 
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W24
	.byte		        Cn2 , v080
	.byte	W12
	.byte		N03   , Cs2 , v084
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		        Cn2 , v076
	.byte	W12
	.byte		N04   , Cs2 
	.byte	W12
	.byte		        Cs2 , v080
	.byte	W24
	.byte		N03
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		N04   , Cn2 , v076
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N03
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W12
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W24
	.byte		N04
	.byte	W12
	.byte		N03   , Cs2 , v080
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W24
	.byte		N03
	.byte	W12
	.byte		N02   , Cn2 , v080
	.byte	W12
	.byte		N04   , Gn1 , v068
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W12
	.byte		        Cs2 , v076
	.byte	W12
	.byte		        Gs1 , v068
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 , v076
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W12
	.byte		        An1 , v072
	.byte	W12
	.byte		N03   , Dn2 , v076
	.byte	W12
	.byte		N04   , An1 
	.byte	W12
	.byte		        Ds2 , v080
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		        En2 , v084
	.byte	W12
	.byte		N04   , Bn1 , v076
	.byte	W12
	.byte		        Cn2 , v080
	.byte	W12
	.byte		N03   , Gn1 , v064
	.byte	W12
	.byte		N04   , Cn2 , v076
	.byte	W12
	.byte		        Gn1 , v072
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 , v068
	.byte	W12
	.byte		        Cs2 , v072
	.byte	W12
	.byte		N03   , Gs1 , v076
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W12
	.byte		N04   , An1 , v076
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N04   , Ds2 , v080
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		        En2 , v084
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W12
	.byte	PATT
	 .word	mus_bonus_field_groudon_3_B3
	.byte	PATT
	 .word	mus_bonus_field_groudon_3_B3
	.byte	GOTO
	 .word	mus_bonus_field_groudon_3_B2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_groudon_4:  @ 0x08699B63
	.byte	KEYSH , mus_bonus_field_groudon_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*mus_bonus_field_groudon_mvl/mxv
	.byte	W96
	.byte	W96
mus_bonus_field_groudon_4_B1:
	.byte		N48   , Cs2 , v100
	.byte	W48
	.byte		        Ds2 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_groudon_4_B1
mus_bonus_field_groudon_4_B2:
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
	 .word	mus_bonus_field_groudon_4_B2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_groudon:  @ 0x08699B9C
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_groudon_pri	@ Priority
	.byte	mus_bonus_field_groudon_rev	@ Reverb

	.word	mus_bonus_field_groudon_grp

	.word	mus_bonus_field_groudon_0
	.word	mus_bonus_field_groudon_1
	.word	mus_bonus_field_groudon_2
	.word	mus_bonus_field_groudon_3
	.word	mus_bonus_field_groudon_4
@ 0x08699BB8
