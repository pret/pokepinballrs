	.include "sound/MPlayDef.s"

	.equ	mus_bonus_field_spheal_grp, gUnknown_08532808
	.equ	mus_bonus_field_spheal_pri, 0
	.equ	mus_bonus_field_spheal_rev, reverb_set+50
	.equ	mus_bonus_field_spheal_mvl, 127
	.equ	mus_bonus_field_spheal_key, 0
	.equ	mus_bonus_field_spheal_tbs, 1
	.equ	mus_bonus_field_spheal_exg, 0
	.equ	mus_bonus_field_spheal_cmp, 1

	.section .rodata
	.global	mus_bonus_field_spheal
	.align	2

@*********************** Track 01 ***********************@

mus_bonus_field_spheal_0:  @ 0x086986B8
	.byte	KEYSH , mus_bonus_field_spheal_key+0
	.byte	TEMPO , 132*mus_bonus_field_spheal_tbs/2
	.byte		VOICE , 12
	.byte		VOL   , 94*mus_bonus_field_spheal_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Gs3 , v080
	.byte	W12
	.byte		N08   , Fs3 , v068
	.byte	W12
	.byte		N09   , Fn3 , v076
	.byte	W12
	.byte		N06   , Ds3 , v068
	.byte	W12
	.byte		        Ds4 , v080
	.byte	W24
	.byte		        Gs3 , v084
	.byte	W24
mus_bonus_field_spheal_0_B1:
	.byte		N05   , Gs3 , v080
	.byte	W12
	.byte		        Fs3 , v068
	.byte	W12
	.byte		N04   , Fn3 , v076
	.byte	W12
	.byte		N24   , Gs3 , v080
	.byte	W24
	.byte		N10   , Fn3 , v072
	.byte	W12
	.byte		N05   , Fs3 , v076
	.byte	W12
	.byte		N09   , Gs3 , v064
	.byte	W12
	.byte		N06   , As3 , v076
	.byte	W12
	.byte		N05   , Gs3 , v068
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W12
	.byte		N40   , Gs3 
	.byte	W60
	.byte		N04   , Fs3 
	.byte	W12
	.byte		N09   , Fn3 
	.byte	W12
	.byte		N04   , Ds3 , v072
	.byte	W12
	.byte		N13
	.byte	W24
	.byte		N08   , Ds3 , v068
	.byte	W12
	.byte		N16   , Fn3 , v080
	.byte	W12
	.byte		N07   , Fs3 , v068
	.byte	W12
	.byte		N06   , Fn3 , v076
	.byte	W12
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Cs3 , v068
	.byte	W12
	.byte		N05   , Cn3 , v072
	.byte	W24
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		N05   , Gs3 , v076
	.byte	W24
	.byte		        Gs3 , v080
	.byte	W12
	.byte		N08   , Fs3 , v064
	.byte	W12
	.byte		N04   , Fn3 , v072
	.byte	W12
	.byte		N24   , Gs3 , v076
	.byte	W24
	.byte		N10   , Fn3 , v068
	.byte	W12
	.byte		N18   , Fs3 , v080
	.byte	W12
	.byte		N10   , Gs3 , v068
	.byte	W12
	.byte		N05   , As3 , v080
	.byte	W12
	.byte		N09   , Gs3 , v076
	.byte	W12
	.byte		N05   , Fs3 
	.byte	W12
	.byte		N15   , Gs3 , v080
	.byte	W24
	.byte		N10   , Gs3 , v068
	.byte	W12
	.byte		N06   , Cs4 , v084
	.byte	W24
	.byte		N03   , As3 , v076
	.byte	W21
	.byte		N02   , As3 , v064
	.byte	W08
	.byte		N03   , Fs4 , v060
	.byte	W08
	.byte		N01   , Cs4 
	.byte	W08
	.byte		N03   , As3 , v068
	.byte	W13
	.byte		N05   , Fs3 , v060
	.byte	W11
	.byte		        As3 , v064
	.byte	W13
	.byte		N03   , Cs4 , v056
	.byte	W13
	.byte		N04   , Cn4 , v068
	.byte	W01
	.byte	W23
	.byte		N05   , Gs3 , v076
	.byte	W23
	.byte		N04   , Cs4 
	.byte	W48
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N05   , Fs3 
	.byte	W12
	.byte		        Fn3 , v060
	.byte	W12
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		N04   , Fn3 , v076
	.byte	W24
	.byte		N03   , Cs3 , v060
	.byte	W12
	.byte		N04   , Gs3 , v080
	.byte	W24
	.byte		        As3 , v076
	.byte	W12
	.byte		N05   , Gs3 , v068
	.byte	W12
	.byte		N04   , Fs3 , v076
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W24
	.byte		N05   , Fn3 , v072
	.byte	W12
	.byte		        Cs4 , v080
	.byte	W24
	.byte		        Ds4 , v076
	.byte	W12
	.byte		        As3 , v068
	.byte	W12
	.byte		N04   , Fs3 , v060
	.byte	W12
	.byte		N05   , Ds4 , v084
	.byte	W24
	.byte		N06   , Cs4 , v076
	.byte	W12
	.byte		N05   , Cn4 , v068
	.byte	W12
	.byte		        As3 , v052
	.byte	W12
	.byte		        Cn4 , v084
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte	W96
	.byte		N13   , Gs3 
	.byte	W11
	.byte		N12   , Fs3 , v076
	.byte	W12
	.byte		N15   , Fn3 
	.byte	W13
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N14   , Fn3 
	.byte	W12
	.byte		N13   , Fs3 , v080
	.byte	W12
	.byte		        Gs3 , v076
	.byte	W12
	.byte		N15   , As3 , v080
	.byte	W13
	.byte		N13   , Gs3 , v076
	.byte	W11
	.byte		        Fs3 , v072
	.byte	W12
	.byte		N04   , Gs3 , v080
	.byte	W24
	.byte		N14   , Gs3 , v076
	.byte	W12
	.byte		N13   , Cs4 
	.byte	W11
	.byte		N15   , Fn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W01
	.byte	W11
	.byte		N14   , Fn4 
	.byte	W12
	.byte		        Ds4 , v080
	.byte	W13
	.byte		N06   , Fn4 
	.byte	W24
	.byte		N12
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N11   , Cs4 , v068
	.byte	W11
	.byte		N14   , Cn4 , v076
	.byte	W01
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N13   , Dn4 , v072
	.byte	W12
	.byte		N06   , Ds4 , v076
	.byte	W23
	.byte		N14
	.byte	W13
	.byte		N05   , Gs4 , v084
	.byte	W24
	.byte		N13   , Gs4 , v088
	.byte	W12
	.byte		        Fs4 , v080
	.byte	W13
	.byte		        Fn4 , v076
	.byte	W12
	.byte		N04   , Gs4 , v084
	.byte	W24
	.byte		N14   , Fn4 , v080
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W11
	.byte		        Gs4 
	.byte	W12
	.byte		N14   , As4 , v084
	.byte	W12
	.byte		        Gs4 , v076
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N04   , Gs4 , v084
	.byte	W24
	.byte	W01
	.byte		N14   , Gs4 , v076
	.byte	W12
	.byte		N13   , Cs5 
	.byte	W11
	.byte		N12   , Gs4 , v068
	.byte	W11
	.byte		        Fs4 , v064
	.byte	W01
	.byte	W12
	.byte		N11   , Fn4 
	.byte	W11
	.byte		N12   , Ds4 , v068
	.byte	W13
	.byte		N05   , Cs4 , v064
	.byte	W24
	.byte		N12   , Cs4 , v068
	.byte	W13
	.byte		        Ds4 , v076
	.byte	W11
	.byte		        Cs4 , v060
	.byte	W12
	.byte		N17   , Cn4 , v072
	.byte	W24
	.byte	W01
	.byte		N11   , Gs4 , v080
	.byte	W24
	.byte		N10   , Cs4 
	.byte	W44
	.byte	W03
	.byte	GOTO
	 .word	mus_bonus_field_spheal_0_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

mus_bonus_field_spheal_1:  @ 0x0869889A
	.byte	KEYSH , mus_bonus_field_spheal_key+0
	.byte		VOICE , 1
	.byte		VOL   , 85*mus_bonus_field_spheal_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N04   , Gs1 , v080
	.byte	W24
	.byte		N03   , Gs2 , v076
	.byte	W24
	.byte		N04   , Ds2 
	.byte	W24
	.byte		N03   , Gs2 , v072
	.byte	W24
mus_bonus_field_spheal_1_B1:
	.byte		N04   , Cs2 , v068
	.byte	W24
	.byte		N03   , Gs2 , v076
	.byte	W24
	.byte		N04   , Gs1 , v072
	.byte	W24
	.byte		        Gs2 , v076
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B2:
	.byte		N03   , Fs2 , v076
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W24
	.byte		        Cs2 , v068
	.byte	W24
	.byte		        Gs2 , v072
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B3:
	.byte		N04   , Fs2 , v072
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Ds2 , v068
	.byte	W24
	.byte		N03   , Ds3 , v072
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B4:
	.byte		N04   , Gs2 , v076
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B5:
	.byte		N04   , Cs2 , v076
	.byte	W24
	.byte		        Gs2 , v072
	.byte	W24
	.byte		        Gs1 , v068
	.byte	W24
	.byte		        Gs2 , v076
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B6:
	.byte		N04   , Fs2 , v076
	.byte	W24
	.byte		        Cs3 , v072
	.byte	W24
	.byte		        Cs2 , v068
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B7:
	.byte		N04   , Fs2 , v064
	.byte	W24
	.byte		N03   , Cs3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_1_B8:
	.byte		N03   , Gs2 , v072
	.byte	W24
	.byte		N02   , Cn3 , v076
	.byte	W24
	.byte		N04   , Cs3 , v072
	.byte	W24
	.byte		        Cs2 , v064
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B3
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B4
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B5
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B6
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B7
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B8
	.byte		N04   , Ds2 , v076
	.byte	W24
	.byte		        As2 , v072
	.byte	W24
	.byte		N05   , Cs2 , v068
	.byte	W24
	.byte		N04   , Gs2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        As2 , v072
	.byte	W24
	.byte		N05   , Cs2 , v060
	.byte	W24
	.byte		N03   , Gs2 , v072
	.byte	W24
	.byte		N04   , Fs2 
	.byte	W24
	.byte		N05   , Cs3 , v068
	.byte	W24
	.byte		N04   , Fs2 , v064
	.byte	W24
	.byte		N03   , Cs3 
	.byte	W24
	.byte		N05   , Gs2 , v076
	.byte	W24
	.byte		N03   , Ds3 , v072
	.byte	W24
	.byte		N04   , Gs2 , v076
	.byte	W24
	.byte		        Ds3 , v064
	.byte	W24
	.byte		N02   , Gs2 , v068
	.byte	W24
	.byte		N04   , Ds3 
	.byte	W24
	.byte		N05   , Gs2 
	.byte	W24
	.byte		N04   , Gs1 
	.byte	W24
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B3
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B4
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B5
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B6
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B7
	.byte	PATT
	 .word	mus_bonus_field_spheal_1_B8
	.byte	GOTO
	 .word	mus_bonus_field_spheal_1_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

mus_bonus_field_spheal_2:  @ 0x086989BF
	.byte	KEYSH , mus_bonus_field_spheal_key+0
	.byte		VOICE , 12
	.byte		VOL   , 85*mus_bonus_field_spheal_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W48
	.byte		N24   , Ds3 , v076
	.byte	W01
	.byte		N23   , Gs2 , v068
	.byte	W44
	.byte	W02
	.byte		N28
	.byte		N24   , Fn3 , v076
	.byte	W01
mus_bonus_field_spheal_2_B1:
	.byte	W48
	.byte		N24   , Gs2 , v076
	.byte		N24   , Fn3 , v080
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B2:
	.byte		N28   , As2 , v068
	.byte		N28   , Fs3 , v076
	.byte	W48
	.byte		        Gs2 , v068
	.byte		N28   , Fn3 , v080
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B3:
	.byte		N24   , As2 , v068
	.byte		N24   , Fs3 , v076
	.byte	W48
	.byte		        As2 , v072
	.byte		N24   , Ds3 
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B4:
	.byte		N24   , Gs2 , v068
	.byte		N28   , Cs3 , v076
	.byte	W48
	.byte		N24   , Gs2 , v068
	.byte		N28   , Ds3 , v076
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B5:
	.byte		N24   , Gs2 , v064
	.byte		N24   , Fn3 , v076
	.byte	W48
	.byte		        Gs2 , v068
	.byte		N24   , Fn3 , v076
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B6:
	.byte		N32   , As2 , v068
	.byte		N32   , Fs3 , v076
	.byte	W48
	.byte		N24   , Gs2 , v072
	.byte		N24   , Fn3 , v076
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B7:
	.byte		N04   , As2 , v064
	.byte		N06   , Ds3 , v068
	.byte	W48
	.byte		N22   , As2 , v056
	.byte		N21   , Fs3 , v068
	.byte	W48
	.byte	PEND
mus_bonus_field_spheal_2_B8:
	.byte		N24   , Gs2 , v060
	.byte		N24   , Ds3 , v064
	.byte	W48
	.byte		        Gs2 , v060
	.byte		N24   , Fn3 , v068
	.byte	W48
	.byte	PEND
	.byte	W44
	.byte	W03
	.byte		        Gs2 , v076
	.byte		N24   , Fn3 , v080
	.byte	W48
	.byte		N28   , Fs3 , v076
	.byte	W01
	.byte		        As2 , v068
	.byte	W44
	.byte	W03
	.byte		        Fn3 , v080
	.byte	W01
	.byte		        Gs2 , v068
	.byte	W44
	.byte	W03
	.byte		N24   , Fs3 , v076
	.byte	W01
	.byte		        As2 , v068
	.byte	W44
	.byte	W02
	.byte		        As2 , v072
	.byte	W01
	.byte		        Ds3 
	.byte	W48
	.byte		        Gs2 , v068
	.byte		N28   , Cs3 , v076
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N24   , Gs2 , v068
	.byte		N28   , Ds3 , v076
	.byte	W48
	.byte		N24   , Fn3 
	.byte	W01
	.byte		        Gs2 , v064
	.byte	W48
	.byte		        Gs2 , v068
	.byte		N24   , Fn3 , v076
	.byte	W48
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B6
	.byte		N04   , As2 , v060
	.byte		N05   , Ds3 , v064
	.byte	W48
	.byte		N22   , As2 , v056
	.byte		N21   , Fs3 , v068
	.byte	W48
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B8
	.byte	W24
	.byte		N04   , Fs2 , v068
	.byte		N06   , As2 , v076
	.byte	W48
	.byte		N02   , Fn2 , v068
	.byte		N05   , Gs2 , v080
	.byte	W24
	.byte	W24
	.byte		        As2 
	.byte		N05   , Cs3 , v076
	.byte	W48
	.byte		N01   , Gs2 
	.byte		N06   , Cs3 , v080
	.byte	W24
	.byte	W24
	.byte		N02   , As2 , v064
	.byte		N05   , Ds3 , v080
	.byte	W48
	.byte		N03   , As2 , v072
	.byte		N06   , Fs3 , v080
	.byte	W24
	.byte	W24
	.byte		N03   , Cn3 , v068
	.byte		N06   , Gs3 , v080
	.byte	W48
	.byte		N04   , As2 , v076
	.byte		N05   , Fs3 , v084
	.byte	W24
	.byte		N04   , Gs2 , v080
	.byte		N04   , Fn3 , v084
	.byte	W24
	.byte		N05   , Fs2 , v072
	.byte		N04   , Ds3 , v076
	.byte	W24
	.byte		        Fn2 
	.byte		N05   , Cs3 , v080
	.byte	W24
	.byte		N04   , Ds2 , v076
	.byte		N05   , Cn3 , v080
	.byte	W24
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B3
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B4
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B5
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B6
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B7
	.byte	PATT
	 .word	mus_bonus_field_spheal_2_B8
	.byte	GOTO
	 .word	mus_bonus_field_spheal_2_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

mus_bonus_field_spheal_3:  @ 0x08698B1F
	.byte	KEYSH , mus_bonus_field_spheal_key+0
	.byte		VOICE , 11
	.byte		VOL   , 86*mus_bonus_field_spheal_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_bonus_field_spheal_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N04   , Gs4 , v068
	.byte	W11
	.byte		        Cs5 , v076
	.byte	W24
	.byte		N06   , Gs4 , v068
	.byte	W11
	.byte		N05   , Cs5 , v080
	.byte	W24
	.byte	W02
	.byte	W22
	.byte		        As4 , v072
	.byte	W12
	.byte		        Ds5 , v080
	.byte	W24
	.byte	W01
	.byte		        Gs4 , v064
	.byte	W12
	.byte		        Cs5 , v072
	.byte	W24
	.byte	W01
	.byte	W21
	.byte		        As4 , v068
	.byte	W13
	.byte		N06   , Ds5 , v072
	.byte	W24
	.byte	W02
	.byte		N05   , As4 , v060
	.byte	W11
	.byte		N06   , Ds5 , v076
	.byte	W24
	.byte	W01
	.byte	W22
	.byte		N04   , Gs4 , v072
	.byte	W12
	.byte		        Cs5 , v076
	.byte	W24
	.byte	W01
	.byte		        Gs4 , v064
	.byte	W12
	.byte		N05   , Ds5 , v076
	.byte	W24
	.byte	W01
	.byte	W22
	.byte		        Gs4 , v064
	.byte	W12
	.byte		N04   , Cs5 , v072
	.byte	W24
	.byte	W01
	.byte		        Gs4 , v064
	.byte	W12
	.byte		N05   , Cs5 , v072
	.byte	W24
	.byte	W01
	.byte	W22
	.byte		        As4 
	.byte	W13
	.byte		        Ds5 , v080
	.byte	W24
	.byte	W01
	.byte		        Gs4 , v064
	.byte	W11
	.byte		N06   , Cs5 , v076
	.byte	W24
	.byte	W01
	.byte	W22
	.byte		N05   , As4 , v064
	.byte	W12
	.byte		        Fs5 , v076
	.byte	W24
	.byte		        As4 , v068
	.byte	W11
	.byte		N06   , Fs5 , v076
	.byte	W24
	.byte	W03
	.byte	W22
	.byte		N05   , Gs4 , v064
	.byte	W12
	.byte		        Ds5 , v076
	.byte	W24
	.byte		        Gs4 , v064
	.byte	W12
	.byte		N07   , Cs5 , v076
	.byte	W24
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Fn4 , v072
	.byte	W10
	.byte		N14   , Ds4 , v076
	.byte	W13
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W24
	.byte		N14   , Cs4 , v072
	.byte	W12
	.byte		N12   , Ds4 , v076
	.byte	W12
	.byte		N14   , Fn4 
	.byte	W12
	.byte		        Fs4 , v064
	.byte	W01
	.byte	W11
	.byte		N13   , Fn4 , v068
	.byte	W12
	.byte		N14   , Ds4 , v072
	.byte	W13
	.byte		N07   , Fn4 
	.byte	W23
	.byte		N13   , Fn4 , v068
	.byte	W11
	.byte		N08   , Cs5 , v084
	.byte	W24
	.byte	W02
	.byte	W22
	.byte		N13   , As4 , v076
	.byte	W12
	.byte		N07   , Ds5 , v084
	.byte	W24
	.byte		N14   , As4 , v072
	.byte	W12
	.byte		N09   , Ds5 , v084
	.byte	W24
	.byte	W02
	.byte	W22
	.byte		N13   , Gs4 , v072
	.byte	W12
	.byte		N08   , Ds5 , v080
	.byte	W24
	.byte	W02
	.byte		N12   , Cn5 , v060
	.byte	W11
	.byte		N07   , Gs5 , v080
	.byte	W24
	.byte	W01
	.byte		N14   , Fn4 , v068
	.byte	W12
	.byte		N15   , Ds4 , v072
	.byte	W12
	.byte		N13   , Cs4 , v056
	.byte	W12
	.byte		N06   , Fn4 , v072
	.byte	W23
	.byte		N12   , Fn4 , v076
	.byte	W12
	.byte		N13   , Gs4 , v072
	.byte	W12
	.byte		N15   , Cs5 , v076
	.byte	W12
	.byte		        As4 , v072
	.byte	W01
	.byte	W11
	.byte		N13   , Gs4 , v076
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N09   , Cs5 , v080
	.byte	W23
	.byte		N12   , Cs5 , v068
	.byte	W12
	.byte		N14   , Ds5 , v072
	.byte	W12
	.byte		N16   , Fn5 , v076
	.byte	W13
	.byte		N09   , Fs5 , v072
	.byte	W01
	.byte	W23
	.byte		N08   , Cs5 , v076
	.byte	W23
	.byte		        As4 , v068
	.byte	W24
	.byte	W02
	.byte		        Fs4 , v076
	.byte	W24
	.byte		N12   , Gs4 , v072
	.byte	W12
	.byte		N14   , Cn5 , v068
	.byte	W12
	.byte		N13   , Ds5 , v072
	.byte	W12
	.byte		N15   , Cn5 , v064
	.byte	W12
	.byte		N07   , Cs5 , v072
	.byte	W24
	.byte	W01
	.byte		N09   , Gs5 , v084
	.byte	W23
	.byte	GOTO
	 .word	mus_bonus_field_spheal_3_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

mus_bonus_field_spheal_4:  @ 0x08698C77
	.byte	KEYSH , mus_bonus_field_spheal_key+0
	.byte		VOICE , 0
	.byte		VOL   , 51*mus_bonus_field_spheal_mvl/mxv
	.byte		N09   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
mus_bonus_field_spheal_4_B1:
	.byte		N09   , Cn1 , v100
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N09
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
mus_bonus_field_spheal_4_B2:
	.byte		N09   , Cn1 , v100
	.byte	W12
	.byte		N09
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N09
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B2
	.byte	PATT
	 .word	mus_bonus_field_spheal_4_B1
	.byte	GOTO
	 .word	mus_bonus_field_spheal_4_B1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

mus_bonus_field_spheal:  @ 0x08698D34
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bonus_field_spheal_pri	@ Priority
	.byte	mus_bonus_field_spheal_rev	@ Reverb

	.word	mus_bonus_field_spheal_grp

	.word	mus_bonus_field_spheal_0
	.word	mus_bonus_field_spheal_1
	.word	mus_bonus_field_spheal_2
	.word	mus_bonus_field_spheal_3
	.word	mus_bonus_field_spheal_4
@ 0x08698D50
