	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_kyogre_grp, gUnknown_08532808
	.equ	mus_bonus_field_kyogre_pri, 0
	.equ	mus_bonus_field_kyogre_rev, reverb_set+50
	.equ	mus_bonus_field_kyogre_mvl, 127
	.equ	mus_bonus_field_kyogre_key, 0
	.equ	mus_bonus_field_kyogre_tbs, 1
	.equ	mus_bonus_field_kyogre_exg, 0
	.equ	mus_bonus_field_kyogre_cmp, 1

	.section .rodata
	.global	mus_bonus_field_kyogre
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_kyogre_0:  @ 0x08699BB8
	.byte	KEYSH , mus_bonus_field_kyogre_key+0
	.byte	TEMPO , 110*mus_bonus_field_kyogre_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 42*mus_bonus_field_kyogre_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_field_kyogre_0_B1:
	.byte		N03   , An4 , v064
	.byte		N04   , En5 , v072
	.byte	W06
	.byte		N03   , En6 , v056
	.byte	W01
	.byte		N01   , Bn5 , v052
	.byte	W06
	.byte		N03   , En5 , v060
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W04
	.byte		N02   , Bn5 
	.byte		N02   , En6 , v040
	.byte	W06
	.byte		N03   , En5 , v060
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W05
	.byte		        Bn5 
	.byte		N02   , En6 
	.byte	W06
	.byte		        En5 , v056
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W04
	.byte		N02   , En6 
	.byte	W01
	.byte		N01   , Bn5 , v048
	.byte	W06
	.byte		N04   , As4 , v068
	.byte		N04   , Fn5 , v072
	.byte	W05
	.byte		N02   , Cn6 , v056
	.byte		N03   , Fn6 , v064
	.byte	W06
	.byte		        Fn5 
	.byte	W01
	.byte		N01   , As4 , v052
	.byte	W05
	.byte		N02   , Cn6 , v048
	.byte		N02   , Fn6 , v052
	.byte	W06
	.byte		N03   , Fn5 , v060
	.byte	W01
	.byte		N01   , As4 , v044
	.byte	W05
	.byte		N02   , Cn6 , v056
	.byte		N02   , Fn6 
	.byte	W06
	.byte		N01   , Fn5 
	.byte	W01
	.byte		        As4 , v048
	.byte	W04
	.byte		N02   , Cn6 , v068
	.byte	W01
	.byte		        Fn6 
	.byte	W06
	.byte		N03   , En5 , v076
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W04
	.byte		N03   , Bn5 
	.byte	W01
	.byte		        En6 , v056
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v040
	.byte	W05
	.byte		        Bn5 , v052
	.byte		N02   , En6 , v048
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v036
	.byte	W04
	.byte		N03   , Bn5 , v060
	.byte	W01
	.byte		        En6 , v052
	.byte	W06
	.byte		N02   , An4 , v060
	.byte		N03   , En5 
	.byte	W05
	.byte		N01   , Bn5 , v068
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        As4 , v072
	.byte		N03   , Fn5 , v080
	.byte	W06
	.byte		N02   , Cn6 , v076
	.byte		N03   , Fn6 
	.byte	W07
	.byte		N02   , As4 , v056
	.byte		N02   , Fn5 , v064
	.byte	W05
	.byte		        Cn6 
	.byte		N03   , Fn6 
	.byte	W07
	.byte		N02   , As4 , v052
	.byte		N02   , Fn5 , v064
	.byte	W05
	.byte		N03   , Cn6 
	.byte		N03   , Fn6 
	.byte	W06
	.byte		N01   , Fn5 , v056
	.byte	W01
	.byte		        As4 , v052
	.byte	W05
	.byte		N02   , Cn6 
	.byte		N03   , Fn6 , v068
	.byte	W07
	.byte		N04   , An4 , v064
	.byte		N03   , En5 , v068
	.byte	W01
	.byte	W03
	.byte		        Bn5 , v072
	.byte		N03   , En6 , v068
	.byte	W07
	.byte		N02   , An4 , v060
	.byte	W01
	.byte		N03   , En5 , v056
	.byte	W05
	.byte		N02   , Bn5 
	.byte		N03   , En6 
	.byte	W07
	.byte		        An4 , v052
	.byte		N02   , En5 , v048
	.byte	W05
	.byte		N03   , Bn5 , v060
	.byte		N03   , En6 
	.byte	W07
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W05
	.byte		        Bn5 , v064
	.byte		N03   , En6 
	.byte	W06
	.byte		        As4 , v068
	.byte		N03   , Fn5 , v080
	.byte	W05
	.byte		        Cn6 , v068
	.byte		N03   , Fn6 
	.byte	W06
	.byte		        Fn5 , v072
	.byte	W01
	.byte		N01   , As4 , v052
	.byte	W04
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 
	.byte	W07
	.byte		N01   , As4 , v056
	.byte		N02   , Fn5 , v068
	.byte	W05
	.byte		        Cn6 , v056
	.byte		N03   , Fn6 , v064
	.byte	W06
	.byte		        Fn5 , v068
	.byte	W01
	.byte		N02   , As4 , v056
	.byte	W04
	.byte		N03   , Fn6 , v064
	.byte	W01
	.byte		N02   , Cn6 , v052
	.byte	W06
	.byte		N04   , An4 , v068
	.byte		N04   , En5 , v076
	.byte	W03
	.byte	W03
	.byte		N02   , Bn5 , v040
	.byte		N03   , En6 , v056
	.byte	W06
	.byte		        En5 , v064
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W05
	.byte		N02   , Bn5 , v060
	.byte		N03   , En6 , v052
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W05
	.byte		N03   , En6 
	.byte	W01
	.byte		N01   , Bn5 
	.byte	W05
	.byte		N03   , En5 , v072
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W05
	.byte		N02   , Bn5 , v052
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		N04   , As4 , v072
	.byte		N04   , Fn5 , v080
	.byte	W06
	.byte		N02   , Cn6 , v064
	.byte		N04   , Fn6 , v068
	.byte	W06
	.byte		N01   , As4 , v056
	.byte		N02   , Fn5 , v068
	.byte	W06
	.byte		N03   , Cn6 , v060
	.byte		N03   , Fn6 
	.byte	W06
	.byte		N02   , Fn5 , v068
	.byte	W01
	.byte		        As4 , v060
	.byte	W05
	.byte		        Cn6 , v056
	.byte		N02   , Fn6 , v060
	.byte	W06
	.byte		        Fn5 , v068
	.byte	W01
	.byte		N01   , As4 , v052
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 
	.byte	W07
	.byte		        An4 , v068
	.byte		N03   , En5 , v080
	.byte	W02
	.byte	W03
	.byte		        Bn5 , v072
	.byte	W01
	.byte		        En6 , v060
	.byte	W06
	.byte		N02   , An4 , v052
	.byte		N03   , En5 , v068
	.byte	W06
	.byte		N01   , Bn5 , v060
	.byte		N02   , En6 , v056
	.byte	W06
	.byte		N01   , An4 , v060
	.byte		N03   , En5 , v068
	.byte	W05
	.byte		N02   , Bn5 
	.byte		N03   , En6 , v052
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N02   , An4 , v064
	.byte	W05
	.byte		        Bn5 , v068
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        Fn5 , v084
	.byte	W01
	.byte		        As4 , v072
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 , v068
	.byte	W06
	.byte		        Fn5 , v076
	.byte	W01
	.byte		N01   , As4 , v056
	.byte	W05
	.byte		N02   , Cn6 
	.byte		N03   , Fn6 , v060
	.byte	W06
	.byte		        Fn5 , v072
	.byte	W02
	.byte		N01   , As4 , v044
	.byte	W05
	.byte		        Cn6 , v056
	.byte		N02   , Fn6 , v060
	.byte	W06
	.byte		        As4 , v056
	.byte		N02   , Fn5 , v076
	.byte	W05
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v072
	.byte	W07
	.byte		N04   , An4 
	.byte		N04   , En5 , v080
	.byte	W02
	.byte	W04
	.byte		N02   , Bn5 , v068
	.byte		N03   , En6 , v060
	.byte	W06
	.byte		        En5 , v064
	.byte	W01
	.byte		N02   , An4 , v048
	.byte	W05
	.byte		        Bn5 , v068
	.byte		N03   , En6 , v060
	.byte	W06
	.byte		N02   , En5 
	.byte	W01
	.byte		        An4 , v052
	.byte	W05
	.byte		        Bn5 , v064
	.byte		N03   , En6 , v060
	.byte	W07
	.byte		N01   , An4 , v056
	.byte		N03   , En5 , v064
	.byte	W05
	.byte		N01   , Bn5 , v068
	.byte		N02   , En6 , v060
	.byte	W06
	.byte		N03   , As4 , v076
	.byte		N04   , Fn5 , v084
	.byte	W06
	.byte		N02   , Cn6 , v068
	.byte		N03   , Fn6 
	.byte	W07
	.byte		N01   , As4 , v048
	.byte		N03   , Fn5 , v064
	.byte	W05
	.byte		N02   , Fn6 , v060
	.byte	W01
	.byte		        Cn6 , v052
	.byte	W06
	.byte		N01   , Fn5 , v060
	.byte	W01
	.byte		        As4 , v056
	.byte	W05
	.byte		        Cn6 
	.byte		N03   , Fn6 , v068
	.byte	W07
	.byte		N02   , As4 , v052
	.byte		N01   , Fn5 , v056
	.byte	W06
	.byte		        Cn6 , v060
	.byte		N02   , Fn6 , v068
	.byte	W06
	.byte		N03   , An4 , v064
	.byte		N03   , En5 , v076
	.byte	W06
	.byte		N01   , Bn5 , v068
	.byte	W01
	.byte		N02   , En6 , v056
	.byte	W06
	.byte		        An4 , v048
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		N01   , Bn5 , v056
	.byte		N02   , En6 
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W04
	.byte		N02   , Bn5 , v068
	.byte		N02   , En6 , v056
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W04
	.byte		N02   , Bn5 , v068
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		N04   , Fn5 , v076
	.byte	W01
	.byte		N03   , As4 , v064
	.byte	W05
	.byte		N01   , Cn6 , v072
	.byte		N03   , Fn6 
	.byte	W07
	.byte		N02   , As4 , v060
	.byte		N03   , Fn5 , v072
	.byte	W05
	.byte		N01   , Cn6 , v060
	.byte		N03   , Fn6 , v068
	.byte	W07
	.byte		N01   , As4 , v052
	.byte		N02   , Fn5 , v068
	.byte	W05
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v064
	.byte	W07
	.byte		N02   , As4 , v060
	.byte		N02   , Fn5 , v068
	.byte	W05
	.byte		N01   , Cn6 , v060
	.byte		N02   , Fn6 , v064
	.byte	W07
	.byte		        An4 , v068
	.byte		N03   , En5 , v080
	.byte	W06
	.byte		N02   , Bn5 , v068
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		        Bn5 , v060
	.byte		N02   , En6 , v056
	.byte	W06
	.byte		N01   , An4 , v052
	.byte		N03   , En5 , v060
	.byte	W06
	.byte		N01   , Bn5 
	.byte		N03   , En6 , v064
	.byte	W05
	.byte		N01   , An4 
	.byte		N03   , En5 , v072
	.byte	W06
	.byte		N01   , Bn5 , v068
	.byte		N03   , En6 
	.byte	W05
	.byte		N04   , Fn5 , v076
	.byte	W01
	.byte		N03   , As4 , v068
	.byte	W06
	.byte		        Cn6 , v076
	.byte		N03   , Fn6 
	.byte	W06
	.byte		        Fn5 , v072
	.byte	W01
	.byte		N01   , As4 , v056
	.byte	W05
	.byte		        Cn6 
	.byte		N01   , Fn6 , v068
	.byte	W07
	.byte		N02   , Fn5 , v064
	.byte	W01
	.byte		N01   , As4 , v048
	.byte	W05
	.byte		        Cn6 , v064
	.byte		N03   , Fn6 , v072
	.byte	W06
	.byte		N02   , Fn5 , v064
	.byte	W01
	.byte		N01   , As4 , v040
	.byte	W05
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N01   , An4 , v072
	.byte		N03   , En5 , v080
	.byte	W06
	.byte		N01   , Bn5 , v064
	.byte		N03   , En6 
	.byte	W05
	.byte		        En5 , v072
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		        Bn5 , v068
	.byte	W01
	.byte		N02   , En6 , v056
	.byte	W06
	.byte		N01   , An4 
	.byte		N03   , En5 , v068
	.byte	W06
	.byte		N01   , Bn5 , v060
	.byte		N03   , En6 
	.byte	W06
	.byte		N01   , An4 
	.byte		N03   , En5 , v072
	.byte	W06
	.byte		N01   , Bn5 , v056
	.byte		N03   , En6 , v076
	.byte	W05
	.byte		N04   , Fn5 
	.byte	W01
	.byte		N03   , As4 , v068
	.byte	W05
	.byte		N02   , Cn6 
	.byte	W01
	.byte		N01   , Fn6 , v032
	.byte	W06
	.byte		        As4 , v052
	.byte		N03   , Fn5 , v064
	.byte	W05
	.byte		N01   , Cn6 , v056
	.byte		N03   , Fn6 , v072
	.byte	W06
	.byte		        Fn5 , v064
	.byte	W01
	.byte		N01   , As4 , v052
	.byte	W04
	.byte		N03   , Fn6 , v072
	.byte	W01
	.byte		N02   , Cn6 , v060
	.byte	W07
	.byte		N01   , As4 , v056
	.byte		N02   , Fn5 , v064
	.byte	W05
	.byte		N01   , Cn6 , v060
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N04   , En5 , v080
	.byte	W01
	.byte		        An4 , v068
	.byte	W05
	.byte		N02   , Bn5 , v064
	.byte		N03   , En6 , v068
	.byte	W06
	.byte		        En5 , v064
	.byte	W01
	.byte		N01   , An4 , v044
	.byte	W06
	.byte		        Bn5 , v056
	.byte		N03   , En6 , v068
	.byte	W05
	.byte		        En5 , v072
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W06
	.byte		        Bn5 
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N02   , An4 , v040
	.byte	W04
	.byte		N03   , Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W05
	.byte		N04   , Fn5 , v076
	.byte	W06
	.byte		N03   , Fn6 
	.byte	W01
	.byte		N02   , Cn6 , v060
	.byte	W06
	.byte		N03   , Fn5 , v064
	.byte	W01
	.byte		N01   , As4 , v056
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 , v072
	.byte	W06
	.byte		        Fn5 , v068
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W04
	.byte		N03   , Fn6 , v064
	.byte	W01
	.byte		N02   , Cn6 , v056
	.byte	W06
	.byte		N03   , As4 , v060
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 , v076
	.byte	W07
	.byte		N04   , En5 
	.byte	W01
	.byte		N02   , An4 , v068
	.byte	W05
	.byte		        Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W05
	.byte		        Bn5 , v064
	.byte		N02   , En6 , v056
	.byte	W07
	.byte		N01   , An4 , v060
	.byte		N03   , En5 , v068
	.byte	W05
	.byte		N01   , Bn5 , v048
	.byte		N03   , En6 , v060
	.byte	W06
	.byte		        En5 , v072
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W05
	.byte		        Bn5 , v052
	.byte		N03   , En6 , v064
	.byte	W05
	.byte		N04   , Fn5 , v080
	.byte	W01
	.byte		N03   , As4 , v068
	.byte	W05
	.byte		N02   , Cn6 , v056
	.byte		N03   , Fn6 , v068
	.byte	W06
	.byte		        Fn5 
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W05
	.byte		        Cn6 , v056
	.byte		N03   , Fn6 , v064
	.byte	W07
	.byte		        As4 , v060
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N02   , Cn6 , v052
	.byte		N03   , Fn6 , v064
	.byte	W07
	.byte		        Fn5 , v068
	.byte	W01
	.byte		N01   , As4 , v052
	.byte	W05
	.byte		        Cn6 , v048
	.byte		N02   , Fn6 , v072
	.byte	W06
	.byte		N04   , En5 , v080
	.byte	W01
	.byte		N03   , An4 , v068
	.byte	W05
	.byte		        Bn5 
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W05
	.byte		N02   , En6 , v064
	.byte	W01
	.byte		N01   , Bn5 , v052
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W04
	.byte		N02   , Bn5 
	.byte	W01
	.byte		        En6 , v048
	.byte	W05
	.byte		N03   , En5 , v064
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W05
	.byte		        Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W05
	.byte		N04   , Fn5 , v080
	.byte	W01
	.byte		        As4 , v068
	.byte	W05
	.byte		N01   , Cn6 , v060
	.byte		N03   , Fn6 , v076
	.byte	W07
	.byte		        Fn5 , v068
	.byte	W01
	.byte		N01   , As4 , v056
	.byte	W05
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v068
	.byte	W06
	.byte		N02   , As4 , v060
	.byte		N03   , Fn5 , v072
	.byte	W05
	.byte		        Cn6 , v064
	.byte		N03   , Fn6 
	.byte	W07
	.byte		        As4 
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N01   , Cn6 , v072
	.byte		N03   , Fn6 
	.byte	W07
	.byte		        An4 
	.byte		N04   , En5 , v080
	.byte	W01
	.byte	W04
	.byte		N03   , En6 , v068
	.byte	W01
	.byte		N01   , Bn5 , v060
	.byte	W06
	.byte		N02   , An4 , v056
	.byte		N03   , En5 , v068
	.byte	W05
	.byte		N02   , Bn5 , v060
	.byte		N03   , En6 , v068
	.byte	W07
	.byte		        An4 , v056
	.byte		N03   , En5 , v068
	.byte	W06
	.byte		N02   , Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		N02   , An4 , v056
	.byte		N03   , En5 , v072
	.byte	W05
	.byte		        En6 , v068
	.byte	W01
	.byte		N01   , Bn5 , v056
	.byte	W05
	.byte		N04   , Fn5 , v080
	.byte	W01
	.byte		        As4 , v068
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 , v072
	.byte	W07
	.byte		N02   , As4 , v056
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		        Cn6 , v064
	.byte		N04   , Fn6 
	.byte	W07
	.byte		N03   , As4 , v060
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N02   , Cn6 , v052
	.byte		N03   , Fn6 , v064
	.byte	W06
	.byte		        Fn5 , v068
	.byte	W01
	.byte		        As4 , v060
	.byte	W04
	.byte		        Fn6 , v068
	.byte	W01
	.byte		        Cn6 , v064
	.byte	W06
	.byte		N04   , En5 , v080
	.byte	W01
	.byte		        An4 , v068
	.byte	W01
	.byte	W04
	.byte		N03   , Bn5 
	.byte		N03   , En6 , v060
	.byte	W07
	.byte		        En5 , v064
	.byte	W01
	.byte		N02   , An4 , v048
	.byte	W05
	.byte		N01   , Bn5 , v064
	.byte		N03   , En6 , v060
	.byte	W06
	.byte		        En5 , v068
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		N02   , Bn5 , v068
	.byte		N03   , En6 , v060
	.byte	W06
	.byte		N02   , An4 
	.byte		N03   , En5 , v068
	.byte	W05
	.byte		N02   , Bn5 
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        Fn5 , v076
	.byte	W01
	.byte		        As4 , v068
	.byte	W05
	.byte		        Fn6 , v076
	.byte	W01
	.byte		N02   , Cn6 , v064
	.byte	W07
	.byte		N03   , As4 
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N02   , Cn6 , v064
	.byte		N03   , Fn6 
	.byte	W06
	.byte		        As4 
	.byte		N02   , Fn5 
	.byte	W05
	.byte		N01   , Cn6 , v060
	.byte		N03   , Fn6 , v068
	.byte	W07
	.byte		N02   , As4 , v060
	.byte		N03   , Fn5 , v076
	.byte	W05
	.byte		N01   , Cn6 , v068
	.byte		N03   , Fn6 , v076
	.byte	W08
	.byte		N01   , An4 , v060
	.byte		N02   , En5 , v064
	.byte	W06
	.byte		        An5 , v060
	.byte		N03   , En6 
	.byte	W07
	.byte		N02   , An4 , v052
	.byte		N03   , En5 , v060
	.byte	W05
	.byte		N02   , An5 , v064
	.byte		N03   , En6 
	.byte	W07
	.byte		N02   , An4 , v060
	.byte		N02   , En5 , v064
	.byte	W05
	.byte		        An5 , v068
	.byte		N03   , En6 , v064
	.byte	W07
	.byte		        An4 
	.byte		N01   , En5 
	.byte	W05
	.byte		        An5 , v072
	.byte		N03   , En6 , v064
	.byte	W07
	.byte		N02   , Fn4 , v056
	.byte		N03   , Cn5 , v072
	.byte	W05
	.byte		        Gs5 , v068
	.byte	W01
	.byte		        Fn6 , v076
	.byte	W07
	.byte		N02   , Fn4 , v048
	.byte		N01   , Cn5 , v064
	.byte	W04
	.byte		N02   , Gs5 
	.byte		N01   , Fn6 , v072
	.byte	W07
	.byte		N02   , Fn4 , v052
	.byte		N01   , Cn5 , v064
	.byte	W05
	.byte		N02   , Gs5 
	.byte		N01   , Fn6 , v068
	.byte	W07
	.byte		        Fn4 , v052
	.byte		N02   , Cn5 , v064
	.byte	W04
	.byte		N03   , Gs5 , v068
	.byte		N01   , Fn6 
	.byte	W07
	.byte		N03   , An4 , v076
	.byte		N03   , En5 
	.byte	W05
	.byte		        An5 , v068
	.byte		N03   , En6 
	.byte	W07
	.byte		        An4 
	.byte		N02   , En5 , v064
	.byte	W06
	.byte		N01   , An5 
	.byte		N03   , En6 
	.byte	W07
	.byte		N02   , An4 
	.byte		N03   , En5 , v068
	.byte	W06
	.byte		N01   , An5 , v064
	.byte		N01   , En6 
	.byte	W06
	.byte		N03   , An4 , v068
	.byte		N02   , En5 
	.byte	W05
	.byte		N01   , An5 
	.byte		N02   , En6 , v060
	.byte	W07
	.byte		N04   , Fn4 
	.byte		N03   , Cn5 , v072
	.byte	W06
	.byte		N02   , Gs5 
	.byte		N02   , Fn6 , v076
	.byte	W07
	.byte		        Fn4 , v040
	.byte		N01   , Cn5 , v064
	.byte	W04
	.byte		N02   , Gs5 , v076
	.byte		N02   , Fn6 , v072
	.byte	W08
	.byte		N01   , Fn4 , v048
	.byte		N01   , Cn5 , v060
	.byte	W05
	.byte		N03   , Gs5 , v072
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N01   , Fn4 , v056
	.byte		N02   , Cn5 , v064
	.byte	W05
	.byte		N03   , Gs5 , v068
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N02   , An4 
	.byte		N02   , En5 , v080
	.byte	W05
	.byte		N03   , En6 , v068
	.byte	W01
	.byte		N01   , Bn5 , v056
	.byte	W07
	.byte		        An4 , v048
	.byte		N02   , En5 , v064
	.byte	W05
	.byte		        Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		N02   , Bn5 , v056
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		N01   , An4 , v052
	.byte		N03   , En5 , v064
	.byte	W05
	.byte		        En6 , v072
	.byte	W01
	.byte		N01   , Bn5 , v060
	.byte	W05
	.byte		N04   , Fn5 , v076
	.byte	W01
	.byte		N03   , As4 , v072
	.byte	W05
	.byte		        Fn6 , v084
	.byte	W01
	.byte		N01   , Cn6 , v064
	.byte	W05
	.byte		N03   , Fn5 , v068
	.byte	W01
	.byte		N01   , As4 , v044
	.byte	W05
	.byte		N02   , Cn6 , v060
	.byte		N03   , Fn6 , v072
	.byte	W06
	.byte		        Fn5 , v064
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W05
	.byte		N03   , Cn6 , v056
	.byte		N03   , Fn6 , v072
	.byte	W07
	.byte		N02   , As4 , v060
	.byte		N04   , Fn5 , v068
	.byte	W05
	.byte		N02   , Cn6 , v052
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N04   , En5 , v080
	.byte	W01
	.byte		N02   , An4 , v064
	.byte	W06
	.byte		N01   , Bn5 , v060
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		N02   , An4 , v048
	.byte		N03   , En5 , v064
	.byte	W05
	.byte		        En6 
	.byte	W01
	.byte		N01   , Bn5 , v060
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W04
	.byte		        Bn5 , v060
	.byte		N03   , En6 , v068
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W05
	.byte		        Bn5 
	.byte		N03   , En6 , v068
	.byte	W07
	.byte		        As4 
	.byte		N04   , Fn5 , v080
	.byte	W05
	.byte		N03   , Cn6 , v064
	.byte		N03   , Fn6 , v076
	.byte	W07
	.byte		N01   , As4 , v052
	.byte		N02   , Fn5 , v064
	.byte	W05
	.byte		        Cn6 , v052
	.byte		N03   , Fn6 , v064
	.byte	W07
	.byte		N01   , As4 , v048
	.byte		N02   , Fn5 , v052
	.byte	W05
	.byte		        Cn6 
	.byte		N03   , Fn6 , v068
	.byte	W06
	.byte		        Fn5 , v060
	.byte	W01
	.byte		N01   , As4 , v048
	.byte	W05
	.byte		N02   , Cn6 , v060
	.byte		N03   , Fn6 , v076
	.byte	W07
	.byte		N01   , An4 , v068
	.byte		N03   , En5 , v084
	.byte	W06
	.byte		N02   , Bn5 , v068
	.byte		N03   , En6 
	.byte	W05
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v048
	.byte	W05
	.byte		N03   , En6 , v068
	.byte	W01
	.byte		N01   , Bn5 , v064
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W01
	.byte		N01   , An4 , v040
	.byte	W05
	.byte		N02   , Bn5 , v064
	.byte		N03   , En6 
	.byte	W05
	.byte		N04   , En5 
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		N02   , Bn5 , v072
	.byte		N03   , En6 
	.byte	W06
	.byte		        Fn5 , v076
	.byte	W01
	.byte		N01   , As4 , v068
	.byte	W05
	.byte		N03   , Cn6 , v072
	.byte		N03   , Fn6 , v080
	.byte	W07
	.byte		N01   , As4 , v052
	.byte		N03   , Fn5 , v068
	.byte	W05
	.byte		N01   , Cn6 , v064
	.byte		N03   , Fn6 , v076
	.byte	W07
	.byte		N02   , Fn5 , v056
	.byte	W01
	.byte		N01   , As4 , v044
	.byte	W04
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v072
	.byte	W07
	.byte		N01   , As4 , v048
	.byte		N02   , Fn5 , v056
	.byte	W05
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		N04   , En5 , v080
	.byte	W01
	.byte		N01   , An4 , v060
	.byte	W06
	.byte		N03   , Bn5 , v064
	.byte		N03   , En6 , v072
	.byte	W06
	.byte		        En5 , v064
	.byte	W01
	.byte		N01   , An4 , v052
	.byte	W05
	.byte		        Bn5 , v056
	.byte		N03   , En6 , v064
	.byte	W06
	.byte		        En5 
	.byte	W01
	.byte		N01   , An4 , v044
	.byte	W05
	.byte		N02   , Bn5 , v056
	.byte		N02   , En6 , v060
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W01
	.byte		N01   , An4 , v056
	.byte	W04
	.byte		N03   , En6 , v068
	.byte	W01
	.byte		N01   , Bn5 , v060
	.byte	W05
	.byte		N04   , Fn5 , v080
	.byte	W01
	.byte		        As4 , v072
	.byte	W05
	.byte		N03   , Fn6 , v080
	.byte	W01
	.byte		N02   , Cn6 , v072
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W01
	.byte		N01   , As4 , v056
	.byte	W04
	.byte		        Cn6 , v060
	.byte		N03   , Fn6 , v068
	.byte	W06
	.byte		N01   , As4 , v056
	.byte		N02   , Fn5 , v068
	.byte	W06
	.byte		N03   , Cn6 
	.byte		N03   , Fn6 , v076
	.byte	W06
	.byte		        Fn5 , v072
	.byte	W01
	.byte		N02   , As4 , v060
	.byte	W04
	.byte		N03   , Fn6 , v076
	.byte	W01
	.byte		N01   , Cn6 , v064
	.byte	W07
	.byte	GOTO
	 .word	mus_bonus_field_kyogre_0_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_kyogre_1:  @ 0x0869A413
	.byte	KEYSH , mus_bonus_field_kyogre_key+0
	.byte		VOICE , 48
	.byte		VOL   , 76*mus_bonus_field_kyogre_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W92
	.byte	W01
	.byte		N48   , Cn3 , v044
	.byte	W03
mus_bonus_field_kyogre_1_B1:
	.byte	W44
	.byte		N48   , Dn3 , v048
	.byte	W48
	.byte	W03
	.byte		N44   , Cn3 , v044
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		        Dn3 
	.byte	W48
	.byte		N48   , Cn3 , v052
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N44   , Dn3 , v048
	.byte	W48
	.byte		N48   , Cn3 
	.byte	W02
	.byte	W44
	.byte	W01
	.byte		        Dn3 , v056
	.byte	W48
	.byte		        Cn3 , v048
	.byte	W03
	.byte	W44
	.byte	W01
	.byte		N44   , Dn3 , v056
	.byte	W48
	.byte		N48   , Cn3 , v052
	.byte	W03
	.byte	W44
	.byte	W01
	.byte		        Dn3 
	.byte	W48
	.byte	W01
	.byte		        Cn3 , v048
	.byte	W02
	.byte	W48
	.byte		N44   , Dn3 
	.byte	W44
	.byte	W02
	.byte		N48   , Cn3 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		        Dn3 , v052
	.byte	W48
	.byte		        Cn3 , v048
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N44   , Dn3 , v052
	.byte	W44
	.byte	W02
	.byte		N48   , Cn3 , v044
	.byte	W03
	.byte	W44
	.byte	W03
	.byte		N44   , Dn3 , v048
	.byte	W44
	.byte	W03
	.byte		N48   , Cn3 , v044
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		N44   , Dn3 , v052
	.byte	W44
	.byte	W03
	.byte		N48   , Cn3 , v048
	.byte	W03
	.byte	W48
	.byte		N44   , Dn3 , v056
	.byte	W44
	.byte	W03
	.byte		N48   , Cn3 , v052
	.byte	W01
	.byte	W44
	.byte	W01
	.byte		N44   , Dn3 
	.byte	W48
	.byte		N48   , Cn3 , v048
	.byte	W03
	.byte	W44
	.byte	W02
	.byte		        Dn3 
	.byte	W48
	.byte		        Cn3 , v044
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W44
	.byte	W03
	.byte		        Cn3 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		        Gs2 
	.byte	W48
	.byte	W01
	.byte		        Cn3 , v056
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N44   , Dn3 , v060
	.byte	W44
	.byte	W03
	.byte		N48   , Cn3 
	.byte	W02
	.byte	W44
	.byte	W02
	.byte		        Dn3 , v056
	.byte	W48
	.byte		        Cn3 
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		        Dn3 
	.byte	W44
	.byte	W03
	.byte		        Cn3 , v044
	.byte	W02
	.byte	W44
	.byte	W03
	.byte		N44   , Dn3 , v052
	.byte	W48
	.byte	W01
	.byte	GOTO
	 .word	mus_bonus_field_kyogre_1_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_kyogre_2:  @ 0x0869A4DC
	.byte	KEYSH , mus_bonus_field_kyogre_key+0
	.byte		VOICE , 1
	.byte		VOL   , 108*mus_bonus_field_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_field_kyogre_2_B1:
	.byte	W96
	.byte	W96
	.byte		N18   , En2 , v084
	.byte		N21   , En3 , v092
	.byte	W18
	.byte		N03   , An2 , v080
	.byte		N04   , An3 , v088
	.byte	W12
	.byte		        En2 , v064
	.byte		N07   , En3 , v080
	.byte	W06
	.byte		N01   , Ds2 
	.byte		N03   , Ds3 , v084
	.byte	W12
	.byte		N40   , As1 , v080
	.byte		N40   , As2 , v088
	.byte	W48
	.byte		N19   , An1 , v080
	.byte		N19   , An2 , v088
	.byte	W18
	.byte		N03   , En2 , v080
	.byte		N03   , En3 
	.byte	W12
	.byte		N06   , Ds2 , v064
	.byte		N06   , Ds3 , v068
	.byte	W06
	.byte		N01   , Fn2 , v076
	.byte		N02   , Fn3 , v084
	.byte	W12
	.byte		N36   , As2 
	.byte		N36   , As3 , v088
	.byte	W48
	.byte		N48   , An2 
	.byte		N48   , An3 
	.byte	W96
	.byte	W96
	.byte		N19   , Cn3 , v076
	.byte		N16   , Cn4 , v092
	.byte	W18
	.byte		N06   , En2 , v064
	.byte		N08   , En3 
	.byte	W12
	.byte		N06   , Cn4 , v076
	.byte	W06
	.byte		N04   , En2 
	.byte		N06   , Cn3 
	.byte		N04   , En3 
	.byte	W12
	.byte		N32   , As2 , v080
	.byte		N32   , As3 , v088
	.byte	W48
	.byte		N18   , An2 , v084
	.byte		N19   , An3 
	.byte	W18
	.byte		N05   , En2 , v076
	.byte		N05   , En3 
	.byte	W12
	.byte		N06   , An2 , v068
	.byte		N05   , An3 
	.byte	W06
	.byte		N03   , En2 , v072
	.byte		N04   , En3 , v080
	.byte	W12
	.byte		N23   , As2 
	.byte		N23   , As3 , v088
	.byte	W24
	.byte		N24   , Dn3 , v084
	.byte		N20   , Dn4 , v096
	.byte	W24
	.byte		N06   , Cn3 , v068
	.byte		N05   , Cn4 , v076
	.byte	W06
	.byte		N07   , As2 , v064
	.byte		N07   , As3 , v080
	.byte	W06
	.byte		N36   , An2 
	.byte		N36   , An3 , v084
	.byte	W84
	.byte	W96
	.byte		N07   , An2 , v080
	.byte	W06
	.byte		N06   , An3 , v072
	.byte	W06
	.byte		N04   , An2 , v060
	.byte	W06
	.byte		        An3 , v076
	.byte	W06
	.byte		N02   , Gs4 , v088
	.byte	W24
	.byte		N05   , Fn3 , v076
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		N06   , Fn3 , v072
	.byte	W06
	.byte		N03   , Fn4 , v076
	.byte	W06
	.byte		N04   , Fs5 , v088
	.byte	W24
	.byte		N07   , An2 , v080
	.byte	W06
	.byte		        An3 , v072
	.byte	W06
	.byte		N08   , An2 , v060
	.byte	W06
	.byte		N06   , An3 , v076
	.byte	W06
	.byte		N03   , Gs4 , v088
	.byte	W24
	.byte		N06   , Fn3 , v072
	.byte	W06
	.byte		N04   , Fn4 , v084
	.byte	W06
	.byte		N06   , Fn3 , v068
	.byte	W06
	.byte		N03   , Fn4 , v080
	.byte	W06
	.byte		N04   , Fs5 , v088
	.byte	W24
	.byte		N03   , An2 , v084
	.byte		N03   , An3 , v088
	.byte	W12
	.byte		N04   , An2 
	.byte		N03   , An3 , v096
	.byte	W84
	.byte	W96
	.byte		N19   , Cn3 , v080
	.byte		N19   , Cn4 , v092
	.byte	W18
	.byte		N03   , An2 , v084
	.byte		N04   , An3 , v088
	.byte	W18
	.byte		        En2 , v080
	.byte		N04   , En3 , v084
	.byte	W12
	.byte		N19   , Gs2 , v088
	.byte		N19   , Gs3 
	.byte	W18
	.byte		N03   , Gn2 , v084
	.byte		N04   , Gn3 
	.byte	W18
	.byte		N03   , Fn2 , v076
	.byte		N04   , Fn3 , v084
	.byte	W12
	.byte		N19   , Cn3 , v080
	.byte		N19   , Cn4 , v096
	.byte	W18
	.byte		N03   , An2 , v080
	.byte		N04   , An3 , v084
	.byte	W18
	.byte		N03   , En2 , v080
	.byte		N04   , En3 
	.byte	W12
	.byte		N19   , Gs2 , v088
	.byte		N19   , Gs3 
	.byte	W18
	.byte		N04   , Gn2 , v076
	.byte		N05   , Gn3 , v084
	.byte	W18
	.byte		N04   , Fn2 , v080
	.byte		N04   , Fn3 , v092
	.byte	W12
	.byte		N06   , En2 , v084
	.byte		N05   , En3 , v096
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_bonus_field_kyogre_2_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_kyogre_3:  @ 0x0869A648
	.byte	KEYSH , mus_bonus_field_kyogre_key+0
	.byte		VOICE , 48
	.byte		VOL   , 68*mus_bonus_field_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N72   , An0 , v028
	.byte		TIE   , An1 , v036
	.byte		TIE   , An2 , v040
	.byte		N92   , Cn3 , v032
	.byte		N80   , En3 , v036
	.byte	W04
	.byte	W01
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W04
	.byte	W78
	.byte	W01
	.byte		EOT   , An2 
	.byte	W02
	.byte		N64   , Fn0 , v028
	.byte		N92   , Gs2 
	.byte		N72   , Fn3 
	.byte	W01
	.byte		EOT   , An1 
	.byte		N92   , Fn1 , v024
	.byte	W01
	.byte		N72   , Cn3 , v028
	.byte	W03
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W05
	.byte	W02
	.byte	W02
	.byte	W01
	.byte	W02
	.byte	W02
	.byte	W04
	.byte	W60
	.byte	W03
	.byte		TIE   , An1 , v032
	.byte		TIE   , An2 , v040
	.byte	W01
	.byte		N80   , An0 , v032
	.byte		N84   , Cn3 , v028
	.byte		N84   , En3 , v036
	.byte	W02
	.byte	W02
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W06
	.byte	W02
	.byte	W02
	.byte	W02
	.byte	W02
	.byte	W01
	.byte	W08
	.byte	W66
	.byte		EOT   , An1 
	.byte		        An2 
	.byte	W02
	.byte		TIE   , Fn1 , v028
	.byte		TIE   , Gs2 , v052
	.byte		N72   , Fn3 , v064
	.byte	W01
	.byte		        Fn0 , v024
	.byte		TIE   , Cn3 , v044
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W06
	.byte	W02
	.byte	W02
	.byte	W01
	.byte	W02
	.byte	W03
	.byte	W11
	.byte	W54
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W05
mus_bonus_field_kyogre_3_B1:
	.byte	W01
	.byte		EOT   , Fn1 
	.byte		        Gs2 
	.byte	W01
	.byte		        Cn3 
	.byte	W72
	.byte	W02
	.byte	W01
	.byte	W19
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
	 .word	mus_bonus_field_kyogre_3_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_kyogre_4:  @ 0x0869A6F1
	.byte	KEYSH , mus_bonus_field_kyogre_key+0
	.byte		VOICE , 47
	.byte		VOL   , 102*mus_bonus_field_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_bonus_field_kyogre_4_B1:
	.byte		N03   , An1 , v072
	.byte	W12
	.byte		N01   , En2 , v056
	.byte	W12
	.byte		N04   , An1 , v076
	.byte	W12
	.byte		N01   , En2 , v060
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v056
	.byte	W12
	.byte		N03   , As1 , v072
	.byte	W12
	.byte		N01   , Fn2 , v060
	.byte	W12
	.byte		N04   , An1 , v072
	.byte	W12
	.byte		N01   , En2 , v064
	.byte	W12
	.byte		N02   , An1 
	.byte	W12
	.byte		N01   , En2 , v068
	.byte	W12
	.byte		        As1 , v064
	.byte	W12
	.byte		        Fn2 , v060
	.byte	W12
	.byte		N02   , As1 , v068
	.byte	W12
	.byte		N01   , Fn2 , v064
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N01   , En2 , v056
	.byte	W12
	.byte		N04   , An1 , v072
	.byte	W12
	.byte		N01   , En2 , v064
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v056
	.byte	W12
	.byte		N04   , As1 , v072
	.byte	W12
	.byte		N01   , Fn2 , v056
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N01   , En2 , v064
	.byte	W12
	.byte		N04   , An1 , v072
	.byte	W12
	.byte		N01   , En2 
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v068
	.byte	W12
	.byte		N03   , As1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v064
	.byte	W12
	.byte		N03   , An1 , v080
	.byte	W12
	.byte		N01   , En2 , v056
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N01   , En2 , v068
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v060
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N02   , Fn2 , v064
	.byte	W12
	.byte		N03   , An1 , v080
	.byte	W12
	.byte		N01   , En2 , v072
	.byte	W12
	.byte		N03   , An1 
	.byte	W12
	.byte		N01   , En2 , v068
	.byte	W12
	.byte		N03   , As1 , v076
	.byte	W12
	.byte		N01   , Fn2 , v064
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		N01   , Fn2 
	.byte	W12
	.byte		N03   , An1 
	.byte	W12
	.byte		N02   , En2 , v076
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 , v068
	.byte	W12
	.byte		        As1 , v076
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N01   , Fn2 , v072
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		N02   , Fn2 , v072
	.byte	W12
	.byte		N01   , An1 , v076
	.byte	W12
	.byte		N02   , En2 
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		N04   , As1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v076
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N02   , Fn2 , v068
	.byte	W12
	.byte		        An1 , v072
	.byte	W12
	.byte		N01   , En2 
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		N02   , As1 , v068
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N02   , Fn2 
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N01   , An1 , v072
	.byte	W12
	.byte		N03   , En2 , v076
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 , v072
	.byte	W12
	.byte		N04   , As1 
	.byte	W12
	.byte		N02   , Fn2 , v064
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		N01   , En2 
	.byte	W12
	.byte		N03   , As1 , v072
	.byte	W12
	.byte		        Fn2 , v076
	.byte	W12
	.byte		N02   , As1 , v072
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W12
	.byte		N02   , An1 , v076
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		        As1 , v072
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 , v064
	.byte	W12
	.byte		N02   , Fn2 , v068
	.byte	W12
	.byte		N01   , An1 , v072
	.byte	W12
	.byte		N02   , En2 , v076
	.byte	W12
	.byte		        An1 , v072
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		N03   , Fn2 , v072
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N02   , An1 , v076
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N01   , An1 , v068
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		N02   , Fn1 , v076
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N01   , Fn1 , v064
	.byte	W12
	.byte		N02   , Cn2 , v060
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		N01   , En2 , v068
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N01   , En2 , v080
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W12
	.byte		        Cn2 , v068
	.byte	W12
	.byte		N02   , Fn1 , v076
	.byte	W12
	.byte		        Cn2 , v072
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		N01   , En2 
	.byte	W12
	.byte		N02   , An1 , v072
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N02   , Fn2 
	.byte	W12
	.byte		N03   , As1 , v072
	.byte	W12
	.byte		N02   , Fn2 
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N02   , En2 
	.byte	W12
	.byte		N03   , An1 , v072
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N02   , Fn2 , v072
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N02   , Fn2 , v068
	.byte	W12
	.byte		N03   , An1 , v076
	.byte	W12
	.byte		N01   , En2 
	.byte	W12
	.byte		N02   , An1 , v068
	.byte	W12
	.byte		        En2 , v076
	.byte	W12
	.byte		N04   , As1 , v072
	.byte	W12
	.byte		N02   , Fn2 , v076
	.byte	W12
	.byte		        As1 , v060
	.byte	W12
	.byte		N01   , Fn2 , v076
	.byte	W12
	.byte		        An1 , v068
	.byte	W12
	.byte		N03   , En2 , v080
	.byte	W12
	.byte		N02   , An1 , v068
	.byte	W12
	.byte		N01   , En2 , v080
	.byte	W12
	.byte		N03   , As1 , v068
	.byte	W12
	.byte		N02   , Fn2 , v076
	.byte	W12
	.byte		        As1 , v068
	.byte	W12
	.byte		        Fn2 , v076
	.byte	W12
	.byte	GOTO
	 .word	mus_bonus_field_kyogre_4_B1
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_kyogre:  @ 0x0869A92C
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_kyogre_pri	@ Priority
	.byte	mus_bonus_field_kyogre_rev	@ Reverb

	.word	mus_bonus_field_kyogre_grp

	.word	mus_bonus_field_kyogre_0
	.word	mus_bonus_field_kyogre_1
	.word	mus_bonus_field_kyogre_2
	.word	mus_bonus_field_kyogre_3
	.word	mus_bonus_field_kyogre_4
@ 0x0869A948
