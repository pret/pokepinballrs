	.include "sound/MPlayDef.s"

	.equ	se_hatch_flourish_grp, gUnknown_0852DDE0
	.equ	se_hatch_flourish_pri, 5
	.equ	se_hatch_flourish_rev, reverb_set+50
	.equ	se_hatch_flourish_mvl, 127
	.equ	se_hatch_flourish_key, 0
	.equ	se_hatch_flourish_tbs, 1
	.equ	se_hatch_flourish_exg, 0
	.equ	se_hatch_flourish_cmp, 1

	.section .rodata
	.global	se_hatch_flourish
	.align	2

@*********************** Track 01 ***********************@

se_hatch_flourish_0:  @ 0x0869F984
	.byte	KEYSH , se_hatch_flourish_key+0
	.byte	TEMPO , 174*se_hatch_flourish_tbs/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*se_hatch_flourish_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W08
	.byte		N04   , Bn3 , v100
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N24   , Gs4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

@*********************** Track 02 ***********************@

se_hatch_flourish_1:  @ 0x0869F9A4
	.byte	KEYSH , se_hatch_flourish_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*se_hatch_flourish_mvl/mxv
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04   , En4 , v100
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N04
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N24   , Bn4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

@*********************** Track 03 ***********************@

se_hatch_flourish_2:  @ 0x0869F9C8
	.byte	KEYSH , se_hatch_flourish_key+0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*se_hatch_flourish_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W08
	.byte		N04   , Gs3 , v068
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N24   , En4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

@*********************** Track 04 ***********************@

se_hatch_flourish_3:  @ 0x0869F9E6
	.byte	KEYSH , se_hatch_flourish_key+0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*se_hatch_flourish_mvl/mxv
	.byte	W08
	.byte		N04   , Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		N24   , Gs4 , v048
	.byte	W10
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 63*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        42*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        22*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        9*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        0*se_hatch_flourish_mvl/mxv
	.byte	W15
	.byte	FINE

@*********************** Track 05 ***********************@

se_hatch_flourish_4:  @ 0x0869FA18
	.byte	KEYSH , se_hatch_flourish_key+0
	.byte		VOICE , 85
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*se_hatch_flourish_mvl/mxv
	.byte	W08
	.byte		N04   , En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v020
	.byte	W04
	.byte		N24   , Bn4 , v048
	.byte	W10
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 63*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        42*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        22*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        9*se_hatch_flourish_mvl/mxv
	.byte	W03
	.byte		        0*se_hatch_flourish_mvl/mxv
	.byte	W15
	.byte	FINE

@******************************************************@

	.align	2

se_hatch_flourish:  @ 0x0869FA4C
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hatch_flourish_pri	@ Priority
	.byte	se_hatch_flourish_rev	@ Reverb

	.word	se_hatch_flourish_grp

	.word	se_hatch_flourish_0
	.word	se_hatch_flourish_1
	.word	se_hatch_flourish_2
	.word	se_hatch_flourish_3
	.word	se_hatch_flourish_4
@ 0x0869FA68
