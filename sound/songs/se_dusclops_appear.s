	.include "sound/MPlayDef.s"

	.equ	se_dusclops_appear_grp, gUnknown_0853174C
	.equ	se_dusclops_appear_pri, 5
	.equ	se_dusclops_appear_rev, reverb_set+50
	.equ	se_dusclops_appear_mvl, 127
	.equ	se_dusclops_appear_key, 0
	.equ	se_dusclops_appear_tbs, 1
	.equ	se_dusclops_appear_exg, 0
	.equ	se_dusclops_appear_cmp, 1

	.section .rodata
	.global	se_dusclops_appear
	.align	2

@*********************** Track 01 ***********************@

se_dusclops_appear_0:  @ 0x086A1724
	.byte	KEYSH , se_dusclops_appear_key+0
	.byte	TEMPO , 110*se_dusclops_appear_tbs/2
	.byte		VOICE , 123
	.byte		BENDR , 12
	.byte		VOL   , 100*se_dusclops_appear_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N60   , Gs2 , v052
	.byte	W06
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v+1
	.byte	W04
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+3
	.byte	W02
	.byte		        c_v+5
	.byte	W02
	.byte	W01
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+11
	.byte	W02
	.byte		        c_v+13
	.byte	W02
	.byte	W01
	.byte		        c_v+15
	.byte	W02
	.byte		        c_v+17
	.byte	W03
	.byte		        c_v+19
	.byte	W02
	.byte		        c_v+24
	.byte	W02
	.byte		        c_v+27
	.byte	W02
	.byte	W01
	.byte		        c_v+30
	.byte	W02
	.byte		        c_v+38
	.byte	W03
	.byte		        c_v+43
	.byte	W02
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+63
	.byte	W02
	.byte		        c_v+0
	.byte		N72   , Gs3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W02
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v+2
	.byte	W02
	.byte	W01
	.byte		        c_v+3
	.byte	W02
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+9
	.byte	W02
	.byte		VOL   , 98*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		VOL   , 96*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 92*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+15
	.byte	W01
	.byte		VOL   , 92*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		VOL   , 85*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+19
	.byte	W02
	.byte		VOL   , 81*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		VOL   , 74*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		VOL   , 66*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+30
	.byte	W01
	.byte		VOL   , 62*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		VOL   , 56*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+43
	.byte	W02
	.byte		VOL   , 50*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+56
	.byte	W01
	.byte		VOL   , 42*se_dusclops_appear_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		VOL   , 34*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        29*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		        25*se_dusclops_appear_mvl/mxv
	.byte	W03
	.byte		        23*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		        19*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		        14*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        11*se_dusclops_appear_mvl/mxv
	.byte	W02
	.byte		        5*se_dusclops_appear_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_dusclops_appear:  @ 0x086A17D8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_dusclops_appear_pri	@ Priority
	.byte	se_dusclops_appear_rev	@ Reverb

	.word	se_dusclops_appear_grp

	.word	se_dusclops_appear_0
@ 0x086A17E4
