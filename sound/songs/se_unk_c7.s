	.include "sound/MPlayDef.s"

	.equ	se_unk_c7_grp, gUnknown_08531D4C
	.equ	se_unk_c7_pri, 5
	.equ	se_unk_c7_rev, reverb_set+50
	.equ	se_unk_c7_mvl, 127
	.equ	se_unk_c7_key, 0
	.equ	se_unk_c7_tbs, 1
	.equ	se_unk_c7_exg, 0
	.equ	se_unk_c7_cmp, 1

	.section .rodata
	.global	se_unk_c7
	.align	2

@*********************** Track 01 ***********************@

se_unk_c7_0:  @ 0x086A084C
	.byte	KEYSH , se_unk_c7_key+0
	.byte	TEMPO , 240*se_unk_c7_tbs/2
	.byte		VOICE , 41
	.byte		BENDR , 12
	.byte		VOL   , 110*se_unk_c7_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Fs4 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N10   , Cn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_unk_c7_mvl/mxv
	.byte	W02
	.byte		        82*se_unk_c7_mvl/mxv
	.byte	W01
	.byte		        45*se_unk_c7_mvl/mxv
	.byte	W01
	.byte		        20*se_unk_c7_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        110*se_unk_c7_mvl/mxv
	.byte		N10   , Cn4 , v040
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_unk_c7_mvl/mxv
	.byte	W01
	.byte		        82*se_unk_c7_mvl/mxv
	.byte	W01
	.byte		        45*se_unk_c7_mvl/mxv
	.byte	W01
	.byte		        20*se_unk_c7_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_unk_c7:  @ 0x086A0884
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_c7_pri	@ Priority
	.byte	se_unk_c7_rev	@ Reverb

	.word	se_unk_c7_grp

	.word	se_unk_c7_0
@ 0x086A0890
