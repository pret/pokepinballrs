	.include "sound/MPlayDef.s"

	.equ	se_unk_104_grp, gUnknown_0853174C
	.equ	se_unk_104_pri, 5
	.equ	se_unk_104_rev, reverb_set+50
	.equ	se_unk_104_mvl, 127
	.equ	se_unk_104_key, 0
	.equ	se_unk_104_tbs, 1
	.equ	se_unk_104_exg, 0
	.equ	se_unk_104_cmp, 1

	.section .rodata
	.global	se_unk_104
	.align	2

@*********************** Track 01 ***********************@

se_unk_104_0:  @ 0x086A1D74
	.byte	KEYSH , se_unk_104_key+0
	.byte	TEMPO , 120*se_unk_104_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 127*se_unk_104_mvl/mxv
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

se_unk_104:  @ 0x086A1DB4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_104_pri	@ Priority
	.byte	se_unk_104_rev	@ Reverb

	.word	se_unk_104_grp

	.word	se_unk_104_0
@ 0x086A1DC0
