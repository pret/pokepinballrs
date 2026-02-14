	.include "sound/MPlayDef.s"

	.equ	se_rayquaza_stage_wind_grp, gUnknown_08531D4C
	.equ	se_rayquaza_stage_wind_pri, 5
	.equ	se_rayquaza_stage_wind_rev, reverb_set+50
	.equ	se_rayquaza_stage_wind_mvl, 127
	.equ	se_rayquaza_stage_wind_key, 0
	.equ	se_rayquaza_stage_wind_tbs, 1
	.equ	se_rayquaza_stage_wind_exg, 0
	.equ	se_rayquaza_stage_wind_cmp, 1

	.section .rodata
	.global	se_rayquaza_stage_wind
	.align	2

@*********************** Track 01 ***********************@

se_rayquaza_stage_wind_0:  @ 0x086A2B54
	.byte	KEYSH , se_rayquaza_stage_wind_key+0
	.byte	TEMPO , 150*se_rayquaza_stage_wind_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 67*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Dn2 , v127
	.byte	W03
	.byte		VOL   , 83*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		VOL   , 88*se_rayquaza_stage_wind_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W03
	.byte		VOL   , 95*se_rayquaza_stage_wind_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 105*se_rayquaza_stage_wind_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		VOL   , 115*se_rayquaza_stage_wind_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v-12
	.byte	W06
se_rayquaza_stage_wind_0_B1:
	.byte		        c_v-17
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v-7
	.byte	W03
	.byte		PAN   , c_v-9
	.byte	W06
	.byte		        c_v-3
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		        c_v+10
	.byte	W06
	.byte		        c_v+16
	.byte	W01
	.byte		BEND  , c_v-20
	.byte	W05
	.byte		PAN   , c_v+13
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		BEND  , c_v-13
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-17
	.byte	W01
	.byte		BEND  , c_v-6
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W06
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+10
	.byte	W01
	.byte		BEND  , c_v+6
	.byte	W05
	.byte		PAN   , c_v+16
	.byte	W06
	.byte		        c_v+13
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte		VOL   , 103*se_rayquaza_stage_wind_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-17
	.byte	W01
	.byte		BEND  , c_v+20
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W01
	.byte		VOL   , 97*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v-3
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		VOL   , 88*se_rayquaza_stage_wind_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W02
	.byte		BEND  , c_v+7
	.byte	W02
	.byte		VOL   , 79*se_rayquaza_stage_wind_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W04
	.byte		VOL   , 62*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		PAN   , c_v+13
	.byte	W04
	.byte		VOL   , 54*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		VOL   , 63*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W05
	.byte		VOL   , 72*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		BEND  , c_v-13
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-17
	.byte	W01
	.byte		BEND  , c_v-6
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W06
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+10
	.byte	W01
	.byte		BEND  , c_v+6
	.byte	W05
	.byte		PAN   , c_v+16
	.byte	W06
	.byte		        c_v+13
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte		VOL   , 103*se_rayquaza_stage_wind_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-17
	.byte	W01
	.byte		BEND  , c_v+20
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W01
	.byte		VOL   , 97*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v-3
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		VOL   , 88*se_rayquaza_stage_wind_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W02
	.byte		BEND  , c_v+7
	.byte	W02
	.byte		VOL   , 79*se_rayquaza_stage_wind_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W04
	.byte		VOL   , 62*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		PAN   , c_v+13
	.byte	W04
	.byte		VOL   , 45*se_rayquaza_stage_wind_mvl/mxv
	.byte	W02
	.byte		VOL   , 36*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W05
	.byte		VOL   , 45*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		VOL   , 54*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W05
	.byte		VOL   , 63*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		VOL   , 72*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W05
	.byte		VOL   , 86*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte		VOL   , 99*se_rayquaza_stage_wind_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W05
	.byte		VOL   , 108*se_rayquaza_stage_wind_mvl/mxv
	.byte	W05
	.byte	GOTO
	 .word	se_rayquaza_stage_wind_0_B1
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_rayquaza_stage_wind:  @ 0x086A2C84
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rayquaza_stage_wind_pri	@ Priority
	.byte	se_rayquaza_stage_wind_rev	@ Reverb

	.word	se_rayquaza_stage_wind_grp

	.word	se_rayquaza_stage_wind_0
@ 0x086A2C90
