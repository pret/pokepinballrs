	.include "sound/MPlayDef.s"

	.equ	se_unk_ec_grp, gUnknown_08531D4C
	.equ	se_unk_ec_pri, 5
	.equ	se_unk_ec_rev, reverb_set+50
	.equ	se_unk_ec_mvl, 127
	.equ	se_unk_ec_key, 0
	.equ	se_unk_ec_tbs, 1
	.equ	se_unk_ec_exg, 0
	.equ	se_unk_ec_cmp, 1

	.section .rodata
	.global	se_unk_ec
	.align	2

@*********************** Track 01 ***********************@

se_unk_ec_0:  @ 0x086A1428
	.byte	KEYSH , se_unk_ec_key+0
	.byte	TEMPO , 150*se_unk_ec_tbs/2
	.byte		VOICE , 21
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 120*se_unk_ec_mvl/mxv
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
	.byte		VOL   , 63*se_unk_ec_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 77*se_unk_ec_mvl/mxv
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 91*se_unk_ec_mvl/mxv
	.byte		BEND  , c_v+21
	.byte	W01
	.byte		VOL   , 106*se_unk_ec_mvl/mxv
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		VOL   , 120*se_unk_ec_mvl/mxv
	.byte	W05
	.byte		        109*se_unk_ec_mvl/mxv
	.byte	W01
	.byte		        102*se_unk_ec_mvl/mxv
	.byte	W02
	.byte		        84*se_unk_ec_mvl/mxv
	.byte	W01
	.byte		        68*se_unk_ec_mvl/mxv
	.byte	W01
	.byte		        56*se_unk_ec_mvl/mxv
	.byte	W01
	.byte		        24*se_unk_ec_mvl/mxv
	.byte	W01
	.byte		        10*se_unk_ec_mvl/mxv
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_ec_1:  @ 0x086A146F
	.byte	KEYSH , se_unk_ec_key+0
	.byte		VOL   , 120*se_unk_ec_mvl/mxv
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

se_unk_ec:  @ 0x086A14A4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ec_pri	@ Priority
	.byte	se_unk_ec_rev	@ Reverb

	.word	se_unk_ec_grp

	.word	se_unk_ec_0
	.word	se_unk_ec_1
@ 0x086A14B4
