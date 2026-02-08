	.include "sound/MPlayDef.s"

	.equ	se_unk_9a_grp, gUnknown_08531D4C
	.equ	se_unk_9a_pri, 5
	.equ	se_unk_9a_rev, reverb_set+50
	.equ	se_unk_9a_mvl, 127
	.equ	se_unk_9a_key, 0
	.equ	se_unk_9a_tbs, 1
	.equ	se_unk_9a_exg, 0
	.equ	se_unk_9a_cmp, 1

	.section .rodata
	.global	se_unk_9a
	.align	2

@*********************** Track 01 ***********************@

se_unk_9a_0:  @ 0x0869FC1C
	.byte	KEYSH , se_unk_9a_key+0
	.byte	TEMPO , 150*se_unk_9a_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 24
	.byte		VOL   , 25*se_unk_9a_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+63
	.byte		TIE   , Cn4 , v112
	.byte	W04
	.byte		VOL   , 40*se_unk_9a_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+52
	.byte	W03
	.byte		VOL   , 55*se_unk_9a_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+41
	.byte	W03
	.byte		VOL   , 80*se_unk_9a_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+30
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+22
	.byte	W01
	.byte		VOL   , 100*se_unk_9a_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+63
	.byte	W06
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+52
	.byte	W06
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+41
	.byte	W04
	.byte		        c_v+33
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v+25
	.byte	W03
	.byte		PAN   , c_v-4
	.byte	W03
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		PAN   , c_v-10
	.byte	W06
	.byte		        c_v-5
	.byte		BEND  , c_v+17
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		PAN   , c_v+11
	.byte	W06
	.byte		        c_v+4
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v-4
	.byte	W02
	.byte		BEND  , c_v-3
	.byte	W04
	.byte		PAN   , c_v-10
	.byte	W06
	.byte		        c_v-5
	.byte	W04
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v+4
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W04
	.byte		PAN   , c_v+11
	.byte	W06
	.byte		        c_v+4
	.byte	W01
	.byte		BEND  , c_v-10
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		PAN   , c_v-4
	.byte	W06
	.byte		        c_v-10
	.byte		BEND  , c_v-18
	.byte	W03
	.byte		VOL   , 89*se_unk_9a_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte	W02
	.byte		VOL   , 74*se_unk_9a_mvl/mxv
	.byte		BEND  , c_v-25
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		VOL   , 62*se_unk_9a_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 45*se_unk_9a_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-40
	.byte	W04
	.byte		VOL   , 28*se_unk_9a_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-49
	.byte	W03
	.byte		        c_v-64
	.byte	W01
	.byte		VOL   , 10*se_unk_9a_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		VOL   , 5*se_unk_9a_mvl/mxv
	.byte	W04
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_9a:  @ 0x0869FCE4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_9a_pri	@ Priority
	.byte	se_unk_9a_rev	@ Reverb

	.word	se_unk_9a_grp

	.word	se_unk_9a_0
@ 0x0869FCF0
