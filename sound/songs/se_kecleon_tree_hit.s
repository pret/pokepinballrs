	.include "sound/MPlayDef.s"

	.equ	se_kecleon_tree_hit_grp, gUnknown_0853174C
	.equ	se_kecleon_tree_hit_pri, 5
	.equ	se_kecleon_tree_hit_rev, reverb_set+50
	.equ	se_kecleon_tree_hit_mvl, 127
	.equ	se_kecleon_tree_hit_key, 0
	.equ	se_kecleon_tree_hit_tbs, 1
	.equ	se_kecleon_tree_hit_exg, 0
	.equ	se_kecleon_tree_hit_cmp, 1

	.section .rodata
	.global	se_kecleon_tree_hit
	.align	2

@*********************** Track 01 ***********************@

se_kecleon_tree_hit_0:  @ 0x086A1D74
	.byte	KEYSH , se_kecleon_tree_hit_key+0
	.byte	TEMPO , 120*se_kecleon_tree_hit_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 127*se_kecleon_tree_hit_mvl/mxv
	.byte		N08   , An2 , v112
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		N01   , Gs2 
	.byte	W01
	.byte	W01
	.byte		N08   , An2 , v096
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N01   , Gs2 , v092
	.byte	W01
	.byte		N08   , An2 , v080
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		N01   , Gs2 , v076
	.byte	W01
	.byte		N08   , An2 , v064
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N01   , Gs2 , v060
	.byte	W02
	.byte		N09   , An2 , v048
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		N01   , Gs2 , v040
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_kecleon_tree_hit:  @ 0x086A1DB4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kecleon_tree_hit_pri	@ Priority
	.byte	se_kecleon_tree_hit_rev	@ Reverb

	.word	se_kecleon_tree_hit_grp

	.word	se_kecleon_tree_hit_0
@ 0x086A1DC0
