	.include "sound/MPlayDef.s"

	.equ	se_slingshot_hit_grp, gUnknown_08531D4C
	.equ	se_slingshot_hit_pri, 5
	.equ	se_slingshot_hit_rev, reverb_set+50
	.equ	se_slingshot_hit_mvl, 127
	.equ	se_slingshot_hit_key, 0
	.equ	se_slingshot_hit_tbs, 1
	.equ	se_slingshot_hit_exg, 0
	.equ	se_slingshot_hit_cmp, 1

	.section .rodata
	.global	se_slingshot_hit
	.align	2

@*********************** Track 01 ***********************@

se_slingshot_hit_0:  @ 0x0869F124
	.byte	KEYSH , se_slingshot_hit_key+0
	.byte	TEMPO , 240*se_slingshot_hit_tbs/2
	.byte		VOICE , 41
	.byte		BENDR , 12
	.byte		VOL   , 110*se_slingshot_hit_mvl/mxv
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
	.byte		VOL   , 96*se_slingshot_hit_mvl/mxv
	.byte	W02
	.byte		        82*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte		        45*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte		        20*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        110*se_slingshot_hit_mvl/mxv
	.byte		N10   , Cn4 , v040
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte		        82*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte		        45*se_slingshot_hit_mvl/mxv
	.byte	W01
	.byte		        20*se_slingshot_hit_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_slingshot_hit:  @ 0x0869F15C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_slingshot_hit_pri	@ Priority
	.byte	se_slingshot_hit_rev	@ Reverb

	.word	se_slingshot_hit_grp

	.word	se_slingshot_hit_0
@ 0x0869F168
