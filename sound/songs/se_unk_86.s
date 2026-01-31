	.include "sound/MPlayDef.s"

	.equ	se_unk_86_grp, gUnknown_08531D4C
	.equ	se_unk_86_pri, 5
	.equ	se_unk_86_rev, reverb_set+50
	.equ	se_unk_86_mvl, 127
	.equ	se_unk_86_key, 0
	.equ	se_unk_86_tbs, 1
	.equ	se_unk_86_exg, 0
	.equ	se_unk_86_cmp, 1

	.section .rodata
	.global	se_unk_86
	.align	2

@*********************** Track 01 ***********************@

se_unk_86_0:  @ 0x0869F5D8
	.byte	KEYSH , se_unk_86_key+0
	.byte	TEMPO , 150*se_unk_86_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 94*se_unk_86_mvl/mxv
	.byte		BENDR , 2
	.byte		LFOS  , 40
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , An5 , v112
	.byte	W01
	.byte		N15   , En6 , v104
	.byte	W02
	.byte	W01
	.byte		MOD   , 5
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        0
	.byte	W02
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_86_1:  @ 0x0869F5FB
	.byte	KEYSH , se_unk_86_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_unk_86_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , An4 , v108
	.byte	W01
	.byte		N12   , Cs6 , v104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_86:  @ 0x0869F618
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_86_pri	@ Priority
	.byte	se_unk_86_rev	@ Reverb

	.word	se_unk_86_grp

	.word	se_unk_86_0
	.word	se_unk_86_1
@ 0x0869F628
