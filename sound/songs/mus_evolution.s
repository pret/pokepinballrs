	.include "sound/MPlayDef.s"

	.equ	mus_evolution_grp, gUnknown_0852E404
	.equ	mus_evolution_pri, 0
	.equ	mus_evolution_rev, reverb_set+50
	.equ	mus_evolution_mvl, 127
	.equ	mus_evolution_key, 0
	.equ	mus_evolution_tbs, 1
	.equ	mus_evolution_exg, 0
	.equ	mus_evolution_cmp, 1

	.section .rodata
	.global	mus_evolution
	.align	2

@*********************** Track 01 ***********************@

mus_evolution_0:  @ 0x08691950
	.byte	KEYSH , mus_evolution_key+0
	.byte	TEMPO , 120*mus_evolution_tbs/2
	.byte		VOICE , 60
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W24
	.byte		        Gn3 , v060
	.byte	W24
	.byte		        Gn3 , v064
	.byte	W24
mus_evolution_0_B1:
	.byte		N06   , Gn3 , v068
	.byte	W24
	.byte		        Gn3 , v072
	.byte	W24
	.byte		        Gn3 , v076
	.byte	W24
	.byte		N24   , An3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
mus_evolution_0_B2:
	.byte		MOD   , 0
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W24
	.byte		        Gn3 , v060
	.byte	W24
	.byte		        Gn3 , v064
	.byte	W24
	.byte	PEND
mus_evolution_0_B3:
	.byte		N06   , Gn3 , v068
	.byte	W24
	.byte		        Gn3 , v072
	.byte	W24
	.byte		        Gn3 , v076
	.byte	W24
	.byte		N24   , Bn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_0_B2
	.byte	PATT
	 .word	mus_evolution_0_B1
	.byte	PATT
	 .word	mus_evolution_0_B2
	.byte	PATT
	 .word	mus_evolution_0_B3
mus_evolution_0_B4:
	.byte		MOD   , 0
	.byte		N06   , An3 , v080
	.byte	W24
	.byte		        An3 , v056
	.byte	W24
	.byte		        An3 , v060
	.byte	W24
	.byte		        An3 , v064
	.byte	W24
	.byte	PEND
mus_evolution_0_B5:
	.byte		N06   , An3 , v068
	.byte	W24
	.byte		        An3 , v072
	.byte	W24
	.byte		        An3 , v076
	.byte	W24
	.byte		N24   , Bn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_0_B4
mus_evolution_0_B6:
	.byte		N06   , An3 , v068
	.byte	W24
	.byte		        An3 , v072
	.byte	W24
	.byte		        An3 , v076
	.byte	W24
	.byte		N24   , Cs4 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_0_B4
	.byte	PATT
	 .word	mus_evolution_0_B5
	.byte	PATT
	 .word	mus_evolution_0_B4
	.byte	PATT
	 .word	mus_evolution_0_B6
	.byte	GOTO
	 .word	mus_evolution_0_B4
	.byte		MOD   , 0
	.byte	FINE

@*********************** Track 02 ***********************@

mus_evolution_1:  @ 0x08691A02
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		N06   , Cn3 , v080
	.byte	W24
	.byte		        Dn3 , v056
	.byte	W24
	.byte		        Cn3 , v060
	.byte	W24
	.byte		        Dn3 , v064
	.byte	W24
mus_evolution_1_B1:
	.byte		N06   , Cn3 , v068
	.byte	W24
	.byte		        Dn3 , v072
	.byte	W24
	.byte		        Cn3 , v076
	.byte	W24
	.byte		N24   , Dn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
mus_evolution_1_B2:
	.byte		MOD   , 0
	.byte		N06   , Cn3 , v080
	.byte	W24
	.byte		        Dn3 , v056
	.byte	W24
	.byte		        Cn3 , v060
	.byte	W24
	.byte		        Dn3 , v064
	.byte	W24
	.byte	PEND
mus_evolution_1_B3:
	.byte		N06   , Cn3 , v068
	.byte	W24
	.byte		        Dn3 , v072
	.byte	W24
	.byte		        Cn3 , v076
	.byte	W24
	.byte		N24   , Fs3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_1_B2
	.byte	PATT
	 .word	mus_evolution_1_B1
	.byte	PATT
	 .word	mus_evolution_1_B2
	.byte	PATT
	 .word	mus_evolution_1_B3
mus_evolution_1_B4:
	.byte		MOD   , 0
	.byte		N06   , Dn3 , v080
	.byte	W24
	.byte		        En3 , v056
	.byte	W24
	.byte		        Dn3 , v060
	.byte	W24
	.byte		        En3 , v064
	.byte	W24
	.byte	PEND
mus_evolution_1_B5:
	.byte		N06   , Dn3 , v068
	.byte	W24
	.byte		        En3 , v072
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte		N24   , En3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_1_B4
mus_evolution_1_B6:
	.byte		N06   , Dn3 , v068
	.byte	W24
	.byte		        En3 , v072
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte		N24   , Gs3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_1_B4
	.byte	PATT
	 .word	mus_evolution_1_B5
	.byte	PATT
	 .word	mus_evolution_1_B4
	.byte	PATT
	 .word	mus_evolution_1_B6
	.byte	GOTO
	 .word	mus_evolution_1_B4
	.byte		MOD   , 0
	.byte	FINE

@*********************** Track 03 ***********************@

mus_evolution_2:  @ 0x08691AB4
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 81
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
mus_evolution_2_B1:
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	PEND
	.byte		N06   , Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PATT
	 .word	mus_evolution_2_B1
mus_evolution_2_B2:
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_2_B2
	.byte	PATT
	 .word	mus_evolution_2_B2
	.byte	PATT
	 .word	mus_evolution_2_B2
mus_evolution_2_B3:
	.byte		N03   , Dn2 , v080
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	PATT
	 .word	mus_evolution_2_B3
	.byte	GOTO
	 .word	mus_evolution_2_B3
	.byte	FINE

@*********************** Track 04 ***********************@

mus_evolution_3:  @ 0x08691B4C
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 47
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		N12
	.byte	W12
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
mus_evolution_3_B1:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		N12
	.byte	W12
	.byte	PEND
mus_evolution_3_B2:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W18
	.byte		N06
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W24
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_3_B1
	.byte	PATT
	 .word	mus_evolution_3_B2
mus_evolution_3_B3:
	.byte		N12   , Dn2 , v112
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		N12
	.byte	W12
	.byte	PEND
mus_evolution_3_B4:
	.byte		N12   , Dn2 , v112
	.byte	W24
	.byte		        En2 
	.byte	W18
	.byte		N06
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v108
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_3_B3
mus_evolution_3_B5:
	.byte		N15   , Dn2 , v112
	.byte	W24
	.byte		N12   , En2 
	.byte	W18
	.byte		N06
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v108
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_3_B3
	.byte	PATT
	 .word	mus_evolution_3_B5
	.byte	PATT
	 .word	mus_evolution_3_B3
	.byte	PATT
	 .word	mus_evolution_3_B4
	.byte	GOTO
	 .word	mus_evolution_3_B3
	.byte	FINE

@*********************** Track 05 ***********************@

mus_evolution_4:  @ 0x08691C1F
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 83
	.byte		PAN   , c_v-47
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		N06   , Cn3 , v056
	.byte	W24
	.byte		        Dn3 , v032
	.byte	W24
	.byte		        Cn3 , v036
	.byte	W24
	.byte		        Dn3 , v040
	.byte	W24
mus_evolution_4_B1:
	.byte		N06   , Cn3 , v044
	.byte	W24
	.byte		        Dn3 , v048
	.byte	W24
	.byte		        Cn3 , v052
	.byte	W24
	.byte		N24   , Dn3 , v056
	.byte	W24
	.byte	PEND
mus_evolution_4_B2:
	.byte		N06   , Cn3 , v056
	.byte	W24
	.byte		        Dn3 , v032
	.byte	W24
	.byte		        Cn3 , v036
	.byte	W24
	.byte		        Dn3 , v040
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_4_B1
	.byte	PATT
	 .word	mus_evolution_4_B2
	.byte	PATT
	 .word	mus_evolution_4_B1
	.byte	PATT
	 .word	mus_evolution_4_B2
	.byte	PATT
	 .word	mus_evolution_4_B1
mus_evolution_4_B3:
	.byte		N06   , Dn3 , v056
	.byte	W24
	.byte		        En3 , v032
	.byte	W24
	.byte		        Dn3 , v036
	.byte	W24
	.byte		        En3 , v040
	.byte	W24
	.byte	PEND
mus_evolution_4_B4:
	.byte		N06   , Dn3 , v044
	.byte	W24
	.byte		        En3 , v048
	.byte	W24
	.byte		        Dn3 , v052
	.byte	W24
	.byte		N24   , En3 , v056
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_4_B3
	.byte	PATT
	 .word	mus_evolution_4_B4
	.byte	PATT
	 .word	mus_evolution_4_B3
	.byte	PATT
	 .word	mus_evolution_4_B4
	.byte	PATT
	 .word	mus_evolution_4_B3
	.byte	PATT
	 .word	mus_evolution_4_B4
	.byte	GOTO
	 .word	mus_evolution_4_B3
	.byte	FINE

@*********************** Track 06 ***********************@

mus_evolution_5:  @ 0x08691CB0
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An2 , v056
	.byte	W24
	.byte		        Bn2 , v032
	.byte	W24
	.byte		        An2 , v036
	.byte	W24
	.byte		        Bn2 , v040
	.byte	W24
mus_evolution_5_B1:
	.byte		N06   , An2 , v044
	.byte	W24
	.byte		        Bn2 , v048
	.byte	W24
	.byte		        An2 , v052
	.byte	W24
	.byte		N24   , Bn2 , v056
	.byte	W24
	.byte	PEND
mus_evolution_5_B2:
	.byte		N06   , An2 , v056
	.byte	W24
	.byte		        Bn2 , v032
	.byte	W24
	.byte		        An2 , v036
	.byte	W24
	.byte		        Bn2 , v040
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_5_B1
	.byte	PATT
	 .word	mus_evolution_5_B2
	.byte	PATT
	 .word	mus_evolution_5_B1
	.byte	PATT
	 .word	mus_evolution_5_B2
	.byte	PATT
	 .word	mus_evolution_5_B1
mus_evolution_5_B3:
	.byte		N06   , Bn2 , v056
	.byte	W24
	.byte		        Cs3 , v032
	.byte	W24
	.byte		        Bn2 , v036
	.byte	W24
	.byte		        Cs3 , v040
	.byte	W24
	.byte	PEND
mus_evolution_5_B4:
	.byte		N06   , Bn2 , v044
	.byte	W24
	.byte		        Cs3 , v048
	.byte	W24
	.byte		        Bn2 , v052
	.byte	W24
	.byte		N24   , Cs3 , v056
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_evolution_5_B3
	.byte	PATT
	 .word	mus_evolution_5_B4
	.byte	PATT
	 .word	mus_evolution_5_B3
	.byte	PATT
	 .word	mus_evolution_5_B4
	.byte	PATT
	 .word	mus_evolution_5_B3
	.byte	PATT
	 .word	mus_evolution_5_B4
	.byte	GOTO
	 .word	mus_evolution_5_B3
	.byte	FINE

@*********************** Track 07 ***********************@

mus_evolution_6:  @ 0x08691D43
	.byte		VOL   , 68*mus_evolution_mvl/mxv
	.byte	KEYSH , mus_evolution_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v112
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		N03
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v076
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		N03
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v100
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		N06
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
mus_evolution_6_B1:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PEND
mus_evolution_6_B2:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		N03
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
	.byte	PEND
mus_evolution_6_B3:
	.byte	PATT
	 .word	mus_evolution_6_B1
	.byte	PATT
	 .word	mus_evolution_6_B2
	.byte	PATT
	 .word	mus_evolution_6_B1
	.byte	PATT
	 .word	mus_evolution_6_B2
	.byte	PATT
	 .word	mus_evolution_6_B1
	.byte	PATT
	 .word	mus_evolution_6_B2
	.byte	PATT
	 .word	mus_evolution_6_B1
	.byte	PATT
	 .word	mus_evolution_6_B2
	.byte	GOTO
	 .word	mus_evolution_6_B3
	.byte	FINE

@******************************************************@

	.align	2

mus_evolution:  @ 0x08691EA8
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_evolution_pri	@ Priority
	.byte	mus_evolution_rev	@ Reverb

	.word	mus_evolution_grp

	.word	mus_evolution_0
	.word	mus_evolution_1
	.word	mus_evolution_2
	.word	mus_evolution_3
	.word	mus_evolution_4
	.word	mus_evolution_5
	.word	mus_evolution_6
