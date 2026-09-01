	.include "sound/MPlayDef.s"

	.equ	se_kecleon_seeing_stars_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_kecleon_seeing_stars_pri, 5
	.equ	se_kecleon_seeing_stars_rev, reverb_set+50
	.equ	se_kecleon_seeing_stars_mvl, 127
	.equ	se_kecleon_seeing_stars_key, 0
	.equ	se_kecleon_seeing_stars_tbs, 1
	.equ	se_kecleon_seeing_stars_exg, 0
	.equ	se_kecleon_seeing_stars_cmp, 1

	.section .rodata
	.global	se_kecleon_seeing_stars
	.align	2

@*********************** Track 01 ***********************@

se_kecleon_seeing_stars_0:  @ 0x086A1CDC
	.byte	KEYSH , se_kecleon_seeing_stars_key+0
	.byte	TEMPO , 150*se_kecleon_seeing_stars_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_kecleon_seeing_stars_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+2
	.byte		N54   , Dn4 , v080
	.byte	W12
	.byte		PAN   , c_v-4
	.byte	W12
	.byte		        c_v-10
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W06
	.byte		PAN   , c_v+6
	.byte	W12
	.byte		        c_v+9
	.byte	W12
	.byte		        c_v+5
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-4
	.byte		N54   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-10
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+6
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W06
	.byte		PAN   , c_v+9
	.byte	W12
	.byte		        c_v+5
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte	FINE

@*********************** Track 02 ***********************@

se_kecleon_seeing_stars_1:  @ 0x086A1D1F
	.byte	KEYSH , se_kecleon_seeing_stars_key+0
	.byte		VOICE , 62
	.byte		BENDR , 44
	.byte		VOL   , 110*se_kecleon_seeing_stars_mvl/mxv
	.byte		MOD   , 30
	.byte		PAN   , c_v+1
	.byte		BEND  , c_v+1
	.byte		N24   , Dn4 , v040
	.byte	W24
	.byte	W02
	.byte		PAN   , c_v+47
	.byte		N24   , Dn4 , v032
	.byte	W22
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v040
	.byte	W18
	.byte	W08
	.byte		PAN   , c_v-49
	.byte		N24   , Cn4 , v032
	.byte	W16
	.byte	W12
	.byte		PAN   , c_v+1
	.byte		N24   , Dn4 , v040
	.byte	W12
	.byte	W14
	.byte		PAN   , c_v+47
	.byte		N24   , Dn4 , v032
	.byte	W10
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v040
	.byte	W06
	.byte	W20
	.byte		PAN   , c_v-48
	.byte		N24   , Cn4 , v032
	.byte	W04
	.byte	W24
	.byte	FINE

@******************************************************@

	.align	2

se_kecleon_seeing_stars:  @ 0x086A1D64
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kecleon_seeing_stars_pri	@ Priority
	.byte	se_kecleon_seeing_stars_rev	@ Reverb

	.word	se_kecleon_seeing_stars_grp

	.word	se_kecleon_seeing_stars_0
	.word	se_kecleon_seeing_stars_1
@ 0x086A1D74
