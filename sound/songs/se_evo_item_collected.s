	.include "sound/MPlayDef.s"

	.equ	se_evo_item_collected_grp, gUnknown_08531D4C
	.equ	se_evo_item_collected_pri, 5
	.equ	se_evo_item_collected_rev, reverb_set+50
	.equ	se_evo_item_collected_mvl, 127
	.equ	se_evo_item_collected_key, 0
	.equ	se_evo_item_collected_tbs, 1
	.equ	se_evo_item_collected_exg, 0
	.equ	se_evo_item_collected_cmp, 1

	.section .rodata
	.global	se_evo_item_collected
	.align	2

@*********************** Track 01 ***********************@

se_evo_item_collected_0:  @ 0x0869F5D8
	.byte	KEYSH , se_evo_item_collected_key+0
	.byte	TEMPO , 150*se_evo_item_collected_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 94*se_evo_item_collected_mvl/mxv
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

se_evo_item_collected_1:  @ 0x0869F5FB
	.byte	KEYSH , se_evo_item_collected_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_evo_item_collected_mvl/mxv
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

se_evo_item_collected:  @ 0x0869F618
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_evo_item_collected_pri	@ Priority
	.byte	se_evo_item_collected_rev	@ Reverb

	.word	se_evo_item_collected_grp

	.word	se_evo_item_collected_0
	.word	se_evo_item_collected_1
@ 0x0869F628
