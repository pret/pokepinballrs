	.include "sound/MPlayDef.s"

	.equ	se_unk_14c_grp, gUnknown_08531D4C
	.equ	se_unk_14c_pri, 5
	.equ	se_unk_14c_rev, reverb_set+50
	.equ	se_unk_14c_mvl, 127
	.equ	se_unk_14c_key, 0
	.equ	se_unk_14c_tbs, 1
	.equ	se_unk_14c_exg, 0
	.equ	se_unk_14c_cmp, 1

	.section .rodata
	.global	se_unk_14c
	.align	2

@*********************** Track 01 ***********************@

se_unk_14c_0:  @ 0x086A3494
	.byte	KEYSH , se_unk_14c_key+0
	.byte	TEMPO , 150*se_unk_14c_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_14c_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cs2 , v127
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v120
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Bn1 , v116
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
se_unk_14c_0_B1:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v108
	.byte	W04
	.byte	PEND
se_unk_14c_0_B2:
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte	PEND
se_unk_14c_0_B3:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v108
	.byte	W02
	.byte	PEND
se_unk_14c_0_B4:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v100
	.byte	W04
	.byte	PEND
se_unk_14c_0_B5:
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte	PEND
se_unk_14c_0_B6:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v100
	.byte	W02
	.byte	PEND
se_unk_14c_0_B7:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v116
	.byte	W04
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v116
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v112
	.byte	W04
se_unk_14c_0_B8:
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte	PEND
se_unk_14c_0_B9:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	se_unk_14c_0_B1
	.byte	PATT
	 .word	se_unk_14c_0_B2
	.byte	PATT
	 .word	se_unk_14c_0_B3
	.byte	PATT
	 .word	se_unk_14c_0_B4
	.byte	PATT
	 .word	se_unk_14c_0_B8
	.byte	PATT
	 .word	se_unk_14c_0_B9
	.byte	PATT
	 .word	se_unk_14c_0_B1
	.byte	PATT
	 .word	se_unk_14c_0_B2
	.byte	PATT
	 .word	se_unk_14c_0_B3
	.byte	PATT
	 .word	se_unk_14c_0_B4
	.byte	PATT
	 .word	se_unk_14c_0_B5
	.byte	PATT
	 .word	se_unk_14c_0_B6
	.byte	PATT
	 .word	se_unk_14c_0_B7
	.byte		VOL   , 106*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		VOL   , 103*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte	W01
	.byte		VOL   , 97*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		VOL   , 89*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v116
	.byte	W02
	.byte	W02
	.byte		VOL   , 85*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v112
	.byte	W04
	.byte		VOL   , 78*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		VOL   , 72*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte	W01
	.byte		VOL   , 66*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		VOL   , 58*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
	.byte	W02
	.byte		VOL   , 46*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v108
	.byte	W04
	.byte		VOL   , 30*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		VOL   , 12*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_14c_1:  @ 0x086A35E5
	.byte	KEYSH , se_unk_14c_key+0
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_unk_14c_mvl/mxv
	.byte		N02   , Fn2 , v072
	.byte	W02
	.byte		N01
	.byte	W01
	.byte		N02   , Gn2 
	.byte	W03
	.byte		N01   , Gs2 , v060
	.byte	W06
	.byte		VOICE , 27
	.byte		N06   , Bn1 , v080
	.byte	W06
se_unk_14c_1_B1:
	.byte		PAN   , c_v+0
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte	PEND
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_unk_14c_1_B1
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		VOL   , 106*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 103*se_unk_14c_mvl/mxv
	.byte	W03
	.byte		N06
	.byte	W01
	.byte		VOL   , 97*se_unk_14c_mvl/mxv
	.byte	W03
	.byte		        89*se_unk_14c_mvl/mxv
	.byte	W02
	.byte		N06
	.byte	W02
	.byte		VOL   , 85*se_unk_14c_mvl/mxv
	.byte	W04
	.byte		        78*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 72*se_unk_14c_mvl/mxv
	.byte	W03
	.byte		N06
	.byte	W01
	.byte		VOL   , 66*se_unk_14c_mvl/mxv
	.byte	W03
	.byte		        58*se_unk_14c_mvl/mxv
	.byte	W02
	.byte		N06
	.byte	W02
	.byte		VOL   , 46*se_unk_14c_mvl/mxv
	.byte	W04
	.byte		        30*se_unk_14c_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 12*se_unk_14c_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_14c:  @ 0x086A368C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_14c_pri	@ Priority
	.byte	se_unk_14c_rev	@ Reverb

	.word	se_unk_14c_grp

	.word	se_unk_14c_0
	.word	se_unk_14c_1
@ 0x086A369C
