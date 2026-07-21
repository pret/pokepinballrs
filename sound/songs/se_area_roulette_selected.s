	.include "sound/MPlayDef.s"

	.equ	se_area_roulette_selected_grp, gUnknown_0853174C
	.equ	se_area_roulette_selected_pri, 5
	.equ	se_area_roulette_selected_rev, reverb_set+50
	.equ	se_area_roulette_selected_mvl, 127
	.equ	se_area_roulette_selected_key, 0
	.equ	se_area_roulette_selected_tbs, 1
	.equ	se_area_roulette_selected_exg, 0
	.equ	se_area_roulette_selected_cmp, 1

	.section .rodata
	.global	se_area_roulette_selected
	.align	2

@*********************** Track 01 ***********************@

se_area_roulette_selected_0:  @ 0x0869FA68
	.byte	KEYSH , se_area_roulette_selected_key+0
	.byte	TEMPO , 144*se_area_roulette_selected_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_area_roulette_selected_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W03
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W04
	.byte	FINE

@*********************** Track 02 ***********************@

se_area_roulette_selected_1:  @ 0x0869FA95
	.byte	KEYSH , se_area_roulette_selected_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_area_roulette_selected_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_area_roulette_selected:  @ 0x0869FAC0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_area_roulette_selected_pri	@ Priority
	.byte	se_area_roulette_selected_rev	@ Reverb

	.word	se_area_roulette_selected_grp

	.word	se_area_roulette_selected_0
	.word	se_area_roulette_selected_1
@ 0x0869FAD0
