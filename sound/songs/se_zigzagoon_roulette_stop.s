	.include "sound/MPlayDef.s"

	.equ	se_zigzagoon_roulette_stop_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_zigzagoon_roulette_stop_pri, 5
	.equ	se_zigzagoon_roulette_stop_rev, reverb_set+50
	.equ	se_zigzagoon_roulette_stop_mvl, 127
	.equ	se_zigzagoon_roulette_stop_key, 0
	.equ	se_zigzagoon_roulette_stop_tbs, 1
	.equ	se_zigzagoon_roulette_stop_exg, 0
	.equ	se_zigzagoon_roulette_stop_cmp, 1

	.section .rodata
	.global	se_zigzagoon_roulette_stop
	.align	2

@*********************** Track 01 ***********************@

se_zigzagoon_roulette_stop_0:  @ 0x086A1428
	.byte	KEYSH , se_zigzagoon_roulette_stop_key+0
	.byte	TEMPO , 150*se_zigzagoon_roulette_stop_tbs/2
	.byte		VOICE , 21
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 120*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N01   , Bn5 , v127
	.byte	W01
	.byte		        Cn5 , v100
	.byte	W01
	.byte		VOICE , 18
	.byte		N01   , Cn4 , v127
	.byte	W02
	.byte		VOICE , 36
	.byte		N19   , Cn6 , v040
	.byte	W02
	.byte		VOL   , 63*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 77*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 91*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		BEND  , c_v+21
	.byte	W01
	.byte		VOL   , 106*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		VOL   , 120*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W05
	.byte		        109*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W01
	.byte		        102*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W02
	.byte		        84*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W01
	.byte		        68*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W01
	.byte		        56*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W01
	.byte		        24*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W01
	.byte		        10*se_zigzagoon_roulette_stop_mvl/mxv
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_zigzagoon_roulette_stop_1:  @ 0x086A146F
	.byte	KEYSH , se_zigzagoon_roulette_stop_key+0
	.byte		VOL   , 120*se_zigzagoon_roulette_stop_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W07
	.byte		VOICE , 46
	.byte		N01   , Cn6 , v100
	.byte	W02
	.byte		BEND  , c_v+4
	.byte		N01   , Gn5 , v088
	.byte	W03
	.byte		BEND  , c_v+8
	.byte		N01   , Cn6 , v072
	.byte	W02
	.byte		BEND  , c_v+16
	.byte		N01   , Gn5 , v056
	.byte	W02
	.byte		BEND  , c_v+23
	.byte		N01   , Cn6 , v040
	.byte	W03
	.byte		BEND  , c_v+33
	.byte		N01   , Gn5 , v028
	.byte	W02
	.byte		BEND  , c_v+53
	.byte		N01   , Cn6 , v012
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_zigzagoon_roulette_stop:  @ 0x086A14A4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_zigzagoon_roulette_stop_pri	@ Priority
	.byte	se_zigzagoon_roulette_stop_rev	@ Reverb

	.word	se_zigzagoon_roulette_stop_grp

	.word	se_zigzagoon_roulette_stop_0
	.word	se_zigzagoon_roulette_stop_1
@ 0x086A14B4
