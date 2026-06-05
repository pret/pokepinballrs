	.include "sound/MPlayDef.s"

	.equ	se_kyogre_freeze_crack_grp, gUnknown_0853174C
	.equ	se_kyogre_freeze_crack_pri, 5
	.equ	se_kyogre_freeze_crack_rev, reverb_set+50
	.equ	se_kyogre_freeze_crack_mvl, 127
	.equ	se_kyogre_freeze_crack_key, 0
	.equ	se_kyogre_freeze_crack_tbs, 1
	.equ	se_kyogre_freeze_crack_exg, 0
	.equ	se_kyogre_freeze_crack_cmp, 1

	.section .rodata
	.global	se_kyogre_freeze_crack
	.align	2

@*********************** Track 01 ***********************@

se_kyogre_freeze_crack_0:  @ 0x086A2140
	.byte	KEYSH , se_kyogre_freeze_crack_key+0
	.byte	TEMPO , 150*se_kyogre_freeze_crack_tbs/2
	.byte		VOICE , 9
	.byte		VOL   , 100*se_kyogre_freeze_crack_mvl/mxv
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

se_kyogre_freeze_crack_1:  @ 0x086A2157
	.byte	KEYSH , se_kyogre_freeze_crack_key+0
	.byte		VOICE , 122
	.byte		VOL   , 100*se_kyogre_freeze_crack_mvl/mxv
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

se_kyogre_freeze_crack:  @ 0x086A216C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kyogre_freeze_crack_pri	@ Priority
	.byte	se_kyogre_freeze_crack_rev	@ Reverb

	.word	se_kyogre_freeze_crack_grp

	.word	se_kyogre_freeze_crack_0
	.word	se_kyogre_freeze_crack_1
@ 0x086A217C
