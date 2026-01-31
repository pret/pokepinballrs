	.include "sound/MPlayDef.s"

	.equ	mus_jirachi_grp, gUnknown_0852FB5C
	.equ	mus_jirachi_pri, 0
	.equ	mus_jirachi_rev, reverb_set+50
	.equ	mus_jirachi_mvl, 127
	.equ	mus_jirachi_key, 0
	.equ	mus_jirachi_tbs, 1
	.equ	mus_jirachi_exg, 0
	.equ	mus_jirachi_cmp, 1

	.section .rodata
	.global	mus_jirachi
	.align	2

@*********************** Track 01 ***********************@

mus_jirachi_0:  @ 0x0869C2EC
	.byte	KEYSH , mus_jirachi_key+0
	.byte	TEMPO , 114*mus_jirachi_tbs/2
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 40*mus_jirachi_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W24
mus_jirachi_0_B1:
	.byte		PAN   , c_v-42
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , En5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte	GOTO
	 .word	mus_jirachi_0_B1
	.byte	FINE

@*********************** Track 02 ***********************@

mus_jirachi_1:  @ 0x0869C6B0
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+11
	.byte		VOL   , 26*mus_jirachi_mvl/mxv
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
mus_jirachi_1_B1:
	.byte		N96   , Dn4 , v112
	.byte	W96
	.byte		        Cs4 
	.byte	W96
	.byte		N88   , Dn4 
	.byte	W88
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N96   , En4 
	.byte	W96
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		TIE   , En4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		N96   , Dn4 
	.byte	W96
	.byte		        Cs4 
	.byte	W96
	.byte		        Dn4 
	.byte	W96
	.byte		        En4 
	.byte	W96
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		TIE   , En4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_jirachi_1_B1
	.byte	FINE

@*********************** Track 03 ***********************@

mus_jirachi_2:  @ 0x0869C6FC
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 57*mus_jirachi_mvl/mxv
	.byte	W24
mus_jirachi_2_B1:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N12
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte	PEND
	.byte		N04
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N04   , Cn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte	PATT
	 .word	mus_jirachi_2_B1
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte	PATT
	 .word	mus_jirachi_2_B1
	.byte	PATT
	 .word	mus_jirachi_2_B1
	.byte	PATT
	 .word	mus_jirachi_2_B1
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N32   , Ds1 
	.byte	W32
	.byte		N04   , As0 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        As0 
	.byte	W16
	.byte		N16   , Ds1 
	.byte	W16
	.byte		N12   , As1 
	.byte	W16
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N32   , As1 
	.byte	W32
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N16   , As1 
	.byte	W16
	.byte		N08   , Gn1 
	.byte	W16
	.byte		N32   , An1 
	.byte	W32
	.byte		N04   , Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N32   , Cn2 
	.byte	W32
	.byte		N08   , Fn1 
	.byte	W16
	.byte		N40   , Dn2 
	.byte	W40
	.byte		N04   , As1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W16
	.byte		        As1 
	.byte	W16
	.byte		        Cn2 
	.byte	W16
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N48   , Dn2 
	.byte	W48
	.byte		N16   , En2 
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		        Fs1 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N32   , En2 
	.byte	W32
	.byte		N08   , Ds2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N48   , Cs2 
	.byte	W48
	.byte	GOTO
	 .word	mus_jirachi_2_B1
	.byte	FINE

@*********************** Track 04 ***********************@

mus_jirachi_3:  @ 0x0869C803
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-11
	.byte		VOL   , 26*mus_jirachi_mvl/mxv
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
mus_jirachi_3_B1:
	.byte		PAN   , c_v-10
	.byte		VOL   , 26*mus_jirachi_mvl/mxv
	.byte		N96   , Gn3 , v112
	.byte	W96
	.byte		        Fs3 
	.byte	W96
	.byte		        Gn3 
	.byte	W96
	.byte		        An3 
	.byte	W96
	.byte		TIE   , As3 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 42*mus_jirachi_mvl/mxv
	.byte		N40   , Gn3 
	.byte	W40
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		N48   , An3 
	.byte	W48
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N12   , Cn4 
	.byte	W16
	.byte		N08
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N40   , Cn4 
	.byte	W40
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N04   , As3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N04   , En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W32
	.byte		N04   , An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N96   , Cs4 
	.byte	W96
	.byte	GOTO
	 .word	mus_jirachi_3_B1
	.byte	FINE

@*********************** Track 05 ***********************@

mus_jirachi_4:  @ 0x0869C8AC
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*mus_jirachi_mvl/mxv
	.byte		N04   , Gn2 , v112
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
mus_jirachi_4_B1:
	.byte		N96   , Ds3 , v112
	.byte	W96
	.byte		        Dn3 
	.byte	W96
	.byte		        Ds3 
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		TIE   , Fs3 
	.byte	W96
	.byte	W96
	.byte		EOT
mus_jirachi_4_B2:
	.byte		N32   , Ds3 , v112
	.byte	W32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		N08   , As2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		        As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte	PEND
	.byte		N40   , Dn3 
	.byte	W40
	.byte		N08   , An2 
	.byte	W08
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N04   , Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte	PATT
	 .word	mus_jirachi_4_B2
	.byte		N40   , Fn3 , v112
	.byte	W40
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N12   , An2 
	.byte	W12
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N40   , Fn3 
	.byte	W40
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04   , As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N48   , Fn3 
	.byte	W48
	.byte		TIE   , Fs3 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_jirachi_4_B1
	.byte	FINE

@*********************** Track 06 ***********************@

mus_jirachi_5:  @ 0x0869C94F
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*mus_jirachi_mvl/mxv
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
mus_jirachi_5_B1:
	.byte		N96   , As3 , v112
	.byte	W96
	.byte		        An3 
	.byte	W96
	.byte		        As3 
	.byte	W96
	.byte		        Cn4 
	.byte	W96
	.byte		TIE   , Dn4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		TIE   , Cs4 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N04   , An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N32   , Gn3 
	.byte	W32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N08
	.byte	W08
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		N40   , As3 
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N24
	.byte	W24
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N48   , As3 
	.byte	W48
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	GOTO
	 .word	mus_jirachi_5_B1
	.byte	FINE

@*********************** Track 07 ***********************@

mus_jirachi_6:  @ 0x0869C9FB
	.byte		VOL   , 68*mus_jirachi_mvl/mxv
	.byte	KEYSH , mus_jirachi_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte	W24
mus_jirachi_6_B1:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		N12
	.byte	W16
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
	.byte	PATT
	 .word	mus_jirachi_6_B1
mus_jirachi_6_B2:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		        Dn1 
	.byte	W08
	.byte		N04
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	PATT
	 .word	mus_jirachi_6_B2
	.byte	GOTO
	 .word	mus_jirachi_6_B1
	.byte	FINE

@******************************************************@

	.align	2

mus_jirachi:  @ 0x0869CA80
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_jirachi_pri	@ Priority
	.byte	mus_jirachi_rev	@ Reverb

	.word	mus_jirachi_grp

	.word	mus_jirachi_0
	.word	mus_jirachi_1
	.word	mus_jirachi_2
	.word	mus_jirachi_3
	.word	mus_jirachi_4
	.word	mus_jirachi_5
	.word	mus_jirachi_6
@ 0x0869CAA4
