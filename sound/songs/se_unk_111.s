	.include "sound/MPlayDef.s"

	.equ	se_unk_111_grp, gUnknown_0853174C
	.equ	se_unk_111_pri, 5
	.equ	se_unk_111_rev, reverb_set+50
	.equ	se_unk_111_mvl, 127
	.equ	se_unk_111_key, 0
	.equ	se_unk_111_tbs, 1
	.equ	se_unk_111_exg, 0
	.equ	se_unk_111_cmp, 1

	.section .rodata
	.global	se_unk_111
	.align	2

@*********************** Track 01 ***********************@

se_unk_111_0:  @ 0x086A2140
	.byte	KEYSH , se_unk_111_key+0
	.byte	TEMPO , 150*se_unk_111_tbs/2
	.byte		VOICE , 9
	.byte		VOL   , 100*se_unk_111_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Gn5 , v088
	.byte	W01
	.byte		N01
	.byte	W02
	.byte		        Cn6 , v072
	.byte	W03
	.byte		        Cn6 , v056
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_111_1:  @ 0x086A2157
	.byte	KEYSH , se_unk_111_key+0
	.byte		VOICE , 122
	.byte		VOL   , 100*se_unk_111_mvl/mxv
	.byte		N01   , Gn2 , v112
	.byte	W02
	.byte		VOICE , 123
	.byte	W01
	.byte		N01   , Gs4 , v096
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_111:  @ 0x086A216C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_111_pri	@ Priority
	.byte	se_unk_111_rev	@ Reverb

	.word	se_unk_111_grp

	.word	se_unk_111_0
	.word	se_unk_111_1
@ 0x086A217C
