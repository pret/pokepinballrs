	.include "sound/MPlayDef.s"

	.equ	se_sealeo_nose_bounce_grp, gUnknown_08531D4C
	.equ	se_sealeo_nose_bounce_pri, 5
	.equ	se_sealeo_nose_bounce_rev, reverb_set+50
	.equ	se_sealeo_nose_bounce_mvl, 127
	.equ	se_sealeo_nose_bounce_key, 0
	.equ	se_sealeo_nose_bounce_tbs, 1
	.equ	se_sealeo_nose_bounce_exg, 0
	.equ	se_sealeo_nose_bounce_cmp, 1

	.section .rodata
	.global	se_sealeo_nose_bounce
	.align	2

@*********************** Track 01 ***********************@

se_sealeo_nose_bounce_0:  @ 0x086A2EB8
	.byte	KEYSH , se_sealeo_nose_bounce_key+0
	.byte	TEMPO , 240*se_sealeo_nose_bounce_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_sealeo_nose_bounce_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Fn3 , v127
	.byte	W02
	.byte		N01   , Cn4 , v112
	.byte	W02
	.byte		N03   , Fn3 , v052
	.byte	W02
	.byte	W02
	.byte		VOICE , 23
	.byte		N01   , En4 , v092
	.byte	W01
	.byte		        Cn5 
	.byte	W03
	.byte		        Gn3 
	.byte	W01
	.byte		        En4 
	.byte	W02
	.byte		        En3 , v048
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_sealeo_nose_bounce:  @ 0x086A2EE4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_sealeo_nose_bounce_pri	@ Priority
	.byte	se_sealeo_nose_bounce_rev	@ Reverb

	.word	se_sealeo_nose_bounce_grp

	.word	se_sealeo_nose_bounce_0
@ 0x086A2EF0
