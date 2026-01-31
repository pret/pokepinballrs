	.include "sound/MPlayDef.s"

	.equ	mus_egg_mode_start_grp, gUnknown_0853015C
	.equ	mus_egg_mode_start_pri, 0
	.equ	mus_egg_mode_start_rev, reverb_set+50
	.equ	mus_egg_mode_start_mvl, 127
	.equ	mus_egg_mode_start_key, 0
	.equ	mus_egg_mode_start_tbs, 1
	.equ	mus_egg_mode_start_exg, 0
	.equ	mus_egg_mode_start_cmp, 1

	.section .rodata
	.global	mus_egg_mode_start
	.align	2

@*********************** Track 01 ***********************@

mus_egg_mode_start_0:  @ 0x0868EEDC
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte	TEMPO , 136*mus_egg_mode_start_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_egg_mode_start_0_B1:
	.byte		N03   , Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v076
	.byte	W06
	.byte		        Gn5 , v056
	.byte	W06
	.byte		        Gn5 , v072
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v076
	.byte	W06
	.byte		        Gn5 , v056
	.byte	W06
	.byte		        Gn5 , v072
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	PATT
	 .word	mus_egg_mode_start_0_B1
	.byte	GOTO
	 .word	mus_egg_mode_start_0_B1
	.byte	FINE

@*********************** Track 02 ***********************@

mus_egg_mode_start_1:  @ 0x0868EF96
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_egg_mode_start_mvl/mxv
	.byte		N03   , As4 , v112
	.byte	W03
	.byte		        Fs4 , v064
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Gs4 , v064
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cs5 , v112
	.byte	W03
	.byte		        As4 , v064
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
mus_egg_mode_start_1_B1:
	.byte		VOICE , 13
	.byte		VOL   , 38*mus_egg_mode_start_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
mus_egg_mode_start_1_B2:
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte	PEND
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 25*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Cs6 
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 38*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cs2 , v096
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W12
mus_egg_mode_start_1_B3:
	.byte		VOICE , 13
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	PEND
mus_egg_mode_start_1_B4:
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte	PEND
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 17
	.byte		VOL   , 35*mus_egg_mode_start_mvl/mxv
	.byte		N03   , As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N24   , Fs5 
	.byte	W24
	.byte		N03   , Cs5 , v080
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 38*mus_egg_mode_start_mvl/mxv
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Fs5 
	.byte	W06
	.byte		VOICE , 13
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	PATT
	 .word	mus_egg_mode_start_1_B2
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Gs5 
	.byte	W06
	.byte		N03   , Gn5 , v092
	.byte	W03
	.byte		        Fs5 , v084
	.byte	W03
	.byte		        En5 , v072
	.byte	W03
	.byte		        Dn5 , v064
	.byte	W09
	.byte	PATT
	 .word	mus_egg_mode_start_1_B3
	.byte	PATT
	 .word	mus_egg_mode_start_1_B4
	.byte		N06   , Cs5 , v112
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		VOICE , 17
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		VOICE , 21
	.byte		VOL   , 31*mus_egg_mode_start_mvl/mxv
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N32   , Ds4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		N24   , Cs5 
	.byte	W30
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W18
	.byte		N18   , As4 
	.byte	W18
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	GOTO
	 .word	mus_egg_mode_start_1_B1
	.byte	FINE

@*********************** Track 03 ***********************@

mus_egg_mode_start_2:  @ 0x0868F224
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 21
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 32*mus_egg_mode_start_mvl/mxv
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        Fs3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        As3 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
mus_egg_mode_start_2_B1:
	.byte	W48
	.byte		VOICE , 56
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	W48
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W96
	.byte	W48
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte	W54
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	W48
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 17
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N03   , As4 , v080
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		VOICE , 56
	.byte		N03
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		VOICE , 14
	.byte		VOL   , 25*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v-52
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+47
	.byte		N48   , Fs3 
	.byte	W48
	.byte		PAN   , c_v-49
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+50
	.byte		N48   , Fs3 
	.byte	W48
	.byte		PAN   , c_v-49
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+47
	.byte		N48   , Cs4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , En5 , v092
	.byte	W03
	.byte		        Ds5 , v084
	.byte	W03
	.byte		        Cs5 , v072
	.byte	W03
	.byte		        Bn4 , v064
	.byte	W09
	.byte		VOICE , 73
	.byte		VOL   , 21*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v-43
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		        Ds5 
	.byte	W03
	.byte		PAN   , c_v-28
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		PAN   , c_v+13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W03
	.byte		PAN   , c_v+40
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 24*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 34*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 29*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		VOL   , 22*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W03
	.byte		VOL   , 26*mus_egg_mode_start_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-34
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-49
	.byte		VOL   , 33*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		VOICE , 47
	.byte		PAN   , c_v+47
	.byte		VOL   , 48*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , Bn2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , As2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*mus_egg_mode_start_mvl/mxv
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		VOICE , 13
	.byte		PAN   , c_v-48
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W03
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , As3 
	.byte	W03
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W03
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W09
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N06   , As4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W24
	.byte		N06
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_egg_mode_start_2_B1
	.byte	FINE

@*********************** Track 04 ***********************@

mus_egg_mode_start_3:  @ 0x0868F586
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 27*mus_egg_mode_start_mvl/mxv
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
mus_egg_mode_start_3_B1:
	.byte		PAN   , c_v-63
	.byte		VOL   , 28*mus_egg_mode_start_mvl/mxv
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
mus_egg_mode_start_3_B2:
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , Gs5 
	.byte	W15
	.byte		        Cs2 
	.byte	W03
	.byte		        Cs3 
	.byte	W09
	.byte		        Cs2 
	.byte	W09
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W12
	.byte	W48
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	W96
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , En4 , v092
	.byte	W03
	.byte		        Ds4 , v084
	.byte	W03
	.byte		        Cs4 , v072
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W09
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	PATT
	 .word	mus_egg_mode_start_3_B2
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		VOL   , 27*mus_egg_mode_start_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N32   , Ds5 , v112
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N32   , Cs5 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N32   , Bn4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N32   , Ds5 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W06
	.byte		N24   , As5 
	.byte	W30
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		N18   , Gn5 
	.byte	W18
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N06   , Fs5 
	.byte	W18
	.byte		        Ds5 
	.byte	W18
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	GOTO
	 .word	mus_egg_mode_start_3_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@*********************** Track 05 ***********************@

mus_egg_mode_start_4:  @ 0x0868F757
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*mus_egg_mode_start_mvl/mxv
	.byte		N24   , Cs3 , v112
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
mus_egg_mode_start_4_B1:
	.byte		PAN   , c_v+63
	.byte		VOL   , 31*mus_egg_mode_start_mvl/mxv
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v092
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
mus_egg_mode_start_4_B2:
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v092
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Cs6 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W12
	.byte	W96
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	W96
	.byte		N03   , Fn4 , v112
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Gn4 , v092
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        En4 , v072
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W09
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	PATT
	 .word	mus_egg_mode_start_4_B2
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		VOL   , 31*mus_egg_mode_start_mvl/mxv
	.byte		N32   , Ds5 , v112
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N32   , Cs5 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N32   , Bn4 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N32   , Ds5 
	.byte	W36
	.byte		N06
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W18
	.byte		N24   , As5 
	.byte	W30
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		N18   , Gn5 
	.byte	W18
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N06   , Fs5 
	.byte	W18
	.byte		        Ds5 
	.byte	W18
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	GOTO
	 .word	mus_egg_mode_start_4_B1
	.byte	FINE

@*********************** Track 06 ***********************@

mus_egg_mode_start_5:  @ 0x0868F904
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 0
	.byte		VOL   , 59*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_egg_mode_start_5_B1:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v096
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte	PATT
	 .word	mus_egg_mode_start_5_B1
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte	GOTO
	 .word	mus_egg_mode_start_5_B1
	.byte	FINE

@*********************** Track 07 ***********************@

mus_egg_mode_start_6:  @ 0x0868F9C4
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*mus_egg_mode_start_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Cs2 , v112
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Cs1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte	W12
mus_egg_mode_start_6_B1:
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_6_B1
	.byte	PATT
	 .word	mus_egg_mode_start_6_B1
mus_egg_mode_start_6_B2:
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_egg_mode_start_6_B2
	.byte	PATT
	 .word	mus_egg_mode_start_6_B2
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PATT
	 .word	mus_egg_mode_start_6_B1
	.byte	PATT
	 .word	mus_egg_mode_start_6_B1
	.byte	PATT
	 .word	mus_egg_mode_start_6_B1
	.byte	PATT
	 .word	mus_egg_mode_start_6_B2
	.byte	PATT
	 .word	mus_egg_mode_start_6_B2
	.byte	PATT
	 .word	mus_egg_mode_start_6_B2
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
mus_egg_mode_start_6_B3:
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PATT
	 .word	mus_egg_mode_start_6_B3
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N06   , As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte	GOTO
	 .word	mus_egg_mode_start_6_B1
	.byte	FINE

@*********************** Track 08 ***********************@

mus_egg_mode_start_7:  @ 0x0868FB76
	.byte	KEYSH , mus_egg_mode_start_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 33*mus_egg_mode_start_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
mus_egg_mode_start_7_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v+16
	.byte	W48
	.byte		        c_v-43
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W48
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v-45
	.byte		N06   , As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		VOICE , 9
	.byte		PAN   , c_v-16
	.byte		N06   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N06
	.byte	W24
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	W96
	.byte		VOICE , 13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		PAN   , c_v-38
	.byte		N06   , Cs6 , v080
	.byte	W12
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W12
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W12
	.byte	W96
	.byte		VOL   , 27*mus_egg_mode_start_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 32*mus_egg_mode_start_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Gn4 , v092
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        En4 , v072
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W09
	.byte		VOICE , 13
	.byte		VOL   , 29*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 48
	.byte		N06   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		VOICE , 47
	.byte		PAN   , c_v+35
	.byte		VOL   , 47*mus_egg_mode_start_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W06
	.byte		PAN   , c_v-33
	.byte		N12   , Cs3 
	.byte	W12
	.byte		PAN   , c_v+34
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v+34
	.byte		N06   , Fs3 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N06   , Fs2 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , Fs3 
	.byte	W06
	.byte		VOICE , 13
	.byte		VOL   , 34*mus_egg_mode_start_mvl/mxv
	.byte	W12
	.byte		N06   , Ds6 , v092
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Ds6 
	.byte	W18
	.byte		N06
	.byte	W12
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Cs6 
	.byte	W18
	.byte		N06
	.byte	W12
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		N06
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Bn5 
	.byte	W18
	.byte		N06
	.byte	W12
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		        Bn5 
	.byte	W18
	.byte		        Cn6 
	.byte	W18
	.byte		        Cs6 
	.byte	W12
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		N06
	.byte	W24
	.byte		        Fs6 
	.byte	W06
	.byte		        Ds6 
	.byte	W12
	.byte		N06
	.byte	W18
	.byte		N06
	.byte	W12
	.byte	W12
	.byte		        Cs6 
	.byte	W24
	.byte		        Bn5 
	.byte	W12
	.byte		        As5 
	.byte	W18
	.byte		N06
	.byte	W18
	.byte		        Gn5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		N06
	.byte	W12
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        As5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        As5 
	.byte	W12
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        As5 
	.byte	W24
	.byte		N06
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte	GOTO
	 .word	mus_egg_mode_start_7_B1
	.byte	FINE

@******************************************************@

	.align	2

mus_egg_mode_start:  @ 0x0868FD98
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_egg_mode_start_pri	@ Priority
	.byte	mus_egg_mode_start_rev	@ Reverb

	.word	mus_egg_mode_start_grp

	.word	mus_egg_mode_start_0
	.word	mus_egg_mode_start_1
	.word	mus_egg_mode_start_2
	.word	mus_egg_mode_start_3
	.word	mus_egg_mode_start_4
	.word	mus_egg_mode_start_5
	.word	mus_egg_mode_start_6
	.word	mus_egg_mode_start_7
