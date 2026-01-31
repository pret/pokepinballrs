	.include "sound/MPlayDef.s"

	.equ	mus_pokedex_grp, gUnknown_0852EF5C
	.equ	mus_pokedex_pri, 0
	.equ	mus_pokedex_rev, reverb_set+50
	.equ	mus_pokedex_mvl, 127
	.equ	mus_pokedex_key, 0
	.equ	mus_pokedex_tbs, 1
	.equ	mus_pokedex_exg, 0
	.equ	mus_pokedex_cmp, 1

	.section .rodata
	.global	mus_pokedex
	.align	2

@*********************** Track 01 ***********************@

mus_pokedex_0:  @ 0x0869B4EC
	.byte	KEYSH , mus_pokedex_key+0
	.byte	TEMPO , 128*mus_pokedex_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v+30
	.byte		VOL   , 50*mus_pokedex_mvl/mxv
	.byte		N04   , Gn2 , v112
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N08
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N04   , An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N40   , Ds3 
	.byte	W40
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
mus_pokedex_0_B1:
	.byte		N20   , As2 , v112
	.byte	W24
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N16   , As2 
	.byte	W16
	.byte		N32   , Cn3 
	.byte	W08
	.byte	W24
	.byte		N24   , An2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , En3 , v080
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N04   , As2 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N16   , As2 
	.byte	W16
	.byte		N20   , En3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N32   , Fn3 
	.byte	W32
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N72   , As2 
	.byte	W80
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N40   , Cn3 
	.byte	W40
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N24
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N72   , Dn3 
	.byte	W72
	.byte		N04   , As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N40   , Bn2 
	.byte	W40
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N48   , Ds2 
	.byte	W48
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W16
	.byte		N24   , As2 
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N40   , En3 
	.byte	W40
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N20
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		N32   , Fn2 
	.byte	W32
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N64   , As3 
	.byte	W64
	.byte		N04   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N56   , Cn4 
	.byte	W56
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N24
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W24
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N32   , Cn4 
	.byte	W32
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Fs3 
	.byte	W56
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N08   , Fs3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N12   , An3 
	.byte	W12
	.byte		N04   , As3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	GOTO
	 .word	mus_pokedex_0_B1
	.byte	FINE

@*********************** Track 02 ***********************@

mus_pokedex_1:  @ 0x0869B719
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_pokedex_mvl/mxv
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		TIE   , Dn4 
	.byte	W96
	.byte	W40
	.byte		EOT
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N48   , An3 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
mus_pokedex_1_B1:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	PEND
	.byte	W96
	.byte		EOT
mus_pokedex_1_B2:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte	PEND
mus_pokedex_1_B3:
	.byte		N16   , Cn4 , v112
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte	PEND
mus_pokedex_1_B4:
	.byte		N48   , As3 , v112
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , An3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N64   , Cn4 
	.byte	W64
	.byte		N20   , As3 
	.byte	W32
	.byte		N16
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N56   , Cn4 
	.byte	W56
	.byte	PATT
	 .word	mus_pokedex_1_B1
	.byte	W96
	.byte		EOT   , Cn4 
	.byte	PATT
	 .word	mus_pokedex_1_B2
	.byte	PATT
	 .word	mus_pokedex_1_B3
	.byte	PATT
	 .word	mus_pokedex_1_B4
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N20   , Cn4 
	.byte	W32
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		N32   , Fn3 
	.byte	W32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Gs4 
	.byte	W56
	.byte	W72
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N60   , Gs4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N72   , As4 
	.byte	W72
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		TIE   , Gs4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_pokedex_1_B1
	.byte	FINE

@*********************** Track 03 ***********************@

mus_pokedex_2:  @ 0x0869B8AA
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 73*mus_pokedex_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N04   , Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cn2 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn2 , v112
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v096
	.byte	W16
	.byte		        Cn1 , v088
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        En1 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W08
	.byte		        Fn2 , v112
	.byte	W08
	.byte		        Fn1 , v088
	.byte	W08
	.byte		N16   , Fn2 , v112
	.byte	W16
	.byte		N04   , Fn1 , v084
	.byte	W08
	.byte		N12   , Fn1 , v096
	.byte	W16
	.byte		N04   , Fn1 , v088
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fn2 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W08
	.byte		        Fn2 , v112
	.byte	W08
	.byte		        Fn1 , v088
	.byte	W08
	.byte		N16   , Fn2 , v112
	.byte	W16
	.byte		N04   , Fn1 , v084
	.byte	W08
	.byte		        Fn1 , v096
	.byte	W16
	.byte		        Fn1 , v088
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 , v084
	.byte	W08
mus_pokedex_2_B1:
	.byte		N04   , As1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
mus_pokedex_2_B2:
	.byte		N04   , An1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte	PEND
mus_pokedex_2_B3:
	.byte		N04   , Gs1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte	PEND
mus_pokedex_2_B4:
	.byte		N04   , Gn1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte	PEND
mus_pokedex_2_B5:
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte	PEND
mus_pokedex_2_B6:
	.byte		N04   , Fn1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte	PEND
mus_pokedex_2_B7:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte	PEND
	.byte		        Ds1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        As1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_2_B2
	.byte	PATT
	 .word	mus_pokedex_2_B3
	.byte	PATT
	 .word	mus_pokedex_2_B4
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_2_B6
	.byte	PATT
	 .word	mus_pokedex_2_B7
	.byte		N04   , Ds1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_2_B5
	.byte		N04   , Fs1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_2_B6
	.byte		N04   , Fn1 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N12   , Gs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Gs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N12   , Gs1 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte	GOTO
	 .word	mus_pokedex_2_B1
	.byte	FINE

@*********************** Track 04 ***********************@

mus_pokedex_3:  @ 0x0869BB5D
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		PAN   , c_v-20
	.byte		VOL   , 58*mus_pokedex_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_pokedex_3_B1:
	.byte		VOL   , 58*mus_pokedex_mvl/mxv
	.byte	W96
	.byte	W24
	.byte		N24   , Fn3 , v112
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N24   , Gn4 , v108
	.byte	W24
	.byte		N06   , Cn4 , v080
	.byte	W08
	.byte		N24   , Ds4 , v104
	.byte	W24
	.byte		        As3 , v112
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N96   , As4 
	.byte	W24
	.byte		VOL   , 57*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        56*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        55*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        53*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        47*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        36*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        36*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        33*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        30*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        25*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        24*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        22*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        21*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        19*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        17*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        16*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        13*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        10*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        9*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        5*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        5*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        2*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		VOICE , 56
	.byte	W24
	.byte		VOL   , 58*mus_pokedex_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , En4 , v080
	.byte	W04
	.byte		        Ds4 , v076
	.byte	W04
	.byte		N96   , Dn4 , v112
	.byte	W24
	.byte		VOL   , 56*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        36*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        30*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        24*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        22*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        20*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        17*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        16*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        14*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        12*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        10*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        9*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        8*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        7*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        5*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        5*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        2*mus_pokedex_mvl/mxv
	.byte	W05
	.byte		        2*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        58*mus_pokedex_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N48   , Ds4 
	.byte	W72
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , As3 
	.byte	W08
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N08   , Cn4 , v088
	.byte	W08
	.byte		N16   , Fs4 , v112
	.byte	W16
	.byte		N04   , Fn4 , v064
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		N24   , Ds4 , v112
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 , v072
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		N24   , Cn4 , v112
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 14
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
mus_pokedex_3_B2:
	.byte		N48   , Fn4 , v112
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte	PEND
	.byte		        Ds4 
	.byte	W48
	.byte		N44   , Cn4 
	.byte	W48
	.byte		N48   , Gs4 
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte	W72
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_3_B2
	.byte		N48   , Cs5 , v112
	.byte	W12
	.byte		VOL   , 57*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        55*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        38*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        58*mus_pokedex_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W12
	.byte		VOL   , 57*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        55*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        38*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        58*mus_pokedex_mvl/mxv
	.byte		N48   , As4 
	.byte	W12
	.byte		VOL   , 57*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        55*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        38*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        58*mus_pokedex_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W12
	.byte		VOL   , 57*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        55*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        54*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        51*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        48*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        45*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        43*mus_pokedex_mvl/mxv
	.byte	W04
	.byte		        40*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        38*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        35*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        32*mus_pokedex_mvl/mxv
	.byte	W03
	.byte		        29*mus_pokedex_mvl/mxv
	.byte	W01
	.byte		        27*mus_pokedex_mvl/mxv
	.byte	W03
	.byte	GOTO
	 .word	mus_pokedex_3_B1
	.byte		VOL   , 58*mus_pokedex_mvl/mxv
	.byte	FINE

@*********************** Track 05 ***********************@

mus_pokedex_4:  @ 0x0869BD68
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v-63
	.byte		VOL   , 32*mus_pokedex_mvl/mxv
	.byte	W24
	.byte		TIE   , Ds3 , v112
	.byte	W96
	.byte	W96
	.byte		EOT
mus_pokedex_4_B1:
	.byte		N48   , Cn3 , v112
	.byte	W48
	.byte		N48
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_pokedex_4_B1
mus_pokedex_4_B2:
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		TIE
	.byte	W08
	.byte	W96
	.byte		EOT
mus_pokedex_4_B3:
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N04
	.byte	W08
	.byte	PEND
mus_pokedex_4_B4:
	.byte		N16   , Fn3 , v112
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N04
	.byte	W16
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N64   , Cn3 
	.byte	W64
	.byte		N20
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N32
	.byte	W32
	.byte		N24   , An2 
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N80
	.byte	W08
	.byte	W72
	.byte		N08
	.byte	W08
	.byte		N04   , Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_4_B3
	.byte	PATT
	 .word	mus_pokedex_4_B4
	.byte		N48   , Ds3 , v112
	.byte	W48
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N04
	.byte	W16
	.byte		N56
	.byte	W56
	.byte		N48   , Cn3 
	.byte	W48
	.byte		N36   , Gn3 
	.byte	W40
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N32   , An2 
	.byte	W32
	.byte		N24   , Fn3 
	.byte	W24
mus_pokedex_4_B5:
	.byte		N64   , Fs3 , v112
	.byte	W64
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W08
	.byte	PEND
	.byte		N16
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W24
	.byte		N56   , Gs3 
	.byte	W56
	.byte	W96
	.byte	PATT
	 .word	mus_pokedex_4_B5
	.byte		N24   , Fs3 , v112
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04
	.byte	W32
	.byte		N48
	.byte	W48
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N48
	.byte	W48
	.byte		N48
	.byte	W48
	.byte		N16
	.byte	W24
	.byte		N04   , Ds3 
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N60   , Fn3 
	.byte	W64
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04
	.byte	W24
	.byte		N56   , Ds3 
	.byte	W56
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N24
	.byte	W24
	.byte		N48   , Gs3 
	.byte	W48
	.byte		TIE
	.byte	W48
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_pokedex_4_B2
	.byte	FINE

@*********************** Track 06 ***********************@

mus_pokedex_5:  @ 0x0869BEA5
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+63
	.byte		VOL   , 32*mus_pokedex_mvl/mxv
	.byte	W24
	.byte		TIE   , As3 , v112
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N48
	.byte	W48
	.byte		N48
	.byte	W48
	.byte		        An3 
	.byte	W48
mus_pokedex_5_B1:
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		TIE   , An3 
	.byte	W08
	.byte	W96
	.byte		EOT
mus_pokedex_5_B2:
	.byte		N16   , Gs3 , v112
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte	PEND
	.byte		N16   , Gn3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N04
	.byte	W16
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N64   , Gn3 
	.byte	W64
	.byte		N20
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N32   , An3 
	.byte	W32
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N16   , As3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N80   , An3 
	.byte	W08
	.byte	W72
	.byte		N08
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_5_B2
	.byte		N16   , Gn3 , v112
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N04
	.byte	W16
	.byte		N56
	.byte	W56
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N36   , Cn4 
	.byte	W40
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		N32   , Cn3 
	.byte	W32
	.byte		N24   , An3 
	.byte	W24
mus_pokedex_5_B3:
	.byte		N64   , Cs4 , v112
	.byte	W64
	.byte		N04
	.byte	W24
	.byte		        As3 
	.byte	W08
	.byte	PEND
	.byte		N16
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N04   , Ds3 
	.byte	W24
	.byte		N56   , Ds4 
	.byte	W56
	.byte	W96
	.byte	PATT
	 .word	mus_pokedex_5_B3
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N16
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N04
	.byte	W32
	.byte		N48
	.byte	W48
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N16   , Cs4 
	.byte	W20
	.byte		N04
	.byte	W04
	.byte		        An3 
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N60   , Ds4 
	.byte	W64
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N24
	.byte	W24
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04
	.byte	W24
	.byte		N56   , As3 
	.byte	W56
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04
	.byte	W24
	.byte		N08   , An3 
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N24
	.byte	W24
	.byte		TIE   , Ds4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_pokedex_5_B1
	.byte	FINE

@*********************** Track 07 ***********************@

mus_pokedex_6:  @ 0x0869BFE8
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_pokedex_mvl/mxv
	.byte	W24
mus_pokedex_6_B1:
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
mus_pokedex_6_B2:
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        En5 , v064
	.byte	W08
mus_pokedex_6_B3:
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte		N01   , En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		        En5 , v120
	.byte	W08
	.byte		        En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		        En5 , v112
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte		N01
	.byte	W08
	.byte		N03   , En5 , v120
	.byte	W08
	.byte		N01   , En5 , v096
	.byte	W08
	.byte		        En5 , v064
	.byte	W08
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	PATT
	 .word	mus_pokedex_6_B1
	.byte	PATT
	 .word	mus_pokedex_6_B2
	.byte	GOTO
	 .word	mus_pokedex_6_B3
	.byte	FINE

@*********************** Track 08 ***********************@

mus_pokedex_7:  @ 0x0869C12E
	.byte	KEYSH , mus_pokedex_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_pokedex_mvl/mxv
	.byte	W24
	.byte		BEND  , c_v+2
	.byte		TIE   , Dn4 , v112
	.byte	W96
	.byte	W40
	.byte		EOT
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N48   , An3 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
mus_pokedex_7_B1:
	.byte		BEND  , c_v+2
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	W96
	.byte		EOT
mus_pokedex_7_B2:
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte	PEND
mus_pokedex_7_B3:
	.byte		N16   , Cn4 , v112
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte	PEND
mus_pokedex_7_B4:
	.byte		N48   , As3 , v112
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , An3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N64   , Cn4 
	.byte	W64
	.byte		N20   , As3 
	.byte	W32
	.byte		N16
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N56   , Cn4 
	.byte	W56
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		TIE   , Cn4 
	.byte	W08
	.byte	W96
	.byte		EOT
	.byte	PATT
	 .word	mus_pokedex_7_B2
	.byte	PATT
	 .word	mus_pokedex_7_B3
	.byte	PATT
	 .word	mus_pokedex_7_B4
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N04   , Fn4 
	.byte	W16
	.byte		N24   , As4 
	.byte	W24
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N64   , As3 
	.byte	W64
	.byte		N20   , Cn4 
	.byte	W32
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		N56   , Fn3 
	.byte	W56
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W24
	.byte		N56   , Gs4 
	.byte	W56
	.byte	W72
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N64   , Fn4 
	.byte	W64
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N60   , Gs4 
	.byte	W64
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N56   , Cs4 
	.byte	W56
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W24
	.byte		N04   , Cn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		TIE   , Gs4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_pokedex_7_B1
	.byte	FINE

@******************************************************@

	.align	2

mus_pokedex:  @ 0x0869C2C4
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_pokedex_pri	@ Priority
	.byte	mus_pokedex_rev	@ Reverb

	.word	mus_pokedex_grp

	.word	mus_pokedex_0
	.word	mus_pokedex_1
	.word	mus_pokedex_2
	.word	mus_pokedex_3
	.word	mus_pokedex_4
	.word	mus_pokedex_5
	.word	mus_pokedex_6
	.word	mus_pokedex_7
@ 0x0869C2EC
