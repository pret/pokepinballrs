	.include "sound/MPlayDef.s"

	.equ	se_nuzleaf_forms_bridge_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_nuzleaf_forms_bridge_pri, 5
	.equ	se_nuzleaf_forms_bridge_rev, reverb_set+50
	.equ	se_nuzleaf_forms_bridge_mvl, 127
	.equ	se_nuzleaf_forms_bridge_key, 0
	.equ	se_nuzleaf_forms_bridge_tbs, 1
	.equ	se_nuzleaf_forms_bridge_exg, 0
	.equ	se_nuzleaf_forms_bridge_cmp, 1

	.section .rodata
	.global	se_nuzleaf_forms_bridge
	.align	2

@*********************** Track 01 ***********************@

se_nuzleaf_forms_bridge_0:  @ 0x086A0C0C
	.byte	KEYSH , se_nuzleaf_forms_bridge_key+0
	.byte	TEMPO , 150*se_nuzleaf_forms_bridge_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 100*se_nuzleaf_forms_bridge_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W01
	.byte		N02   , Gn2 
	.byte	W02
	.byte		N04   , Cn3 
	.byte	W04
	.byte	FINE

@******************************************************@

	.align	2

se_nuzleaf_forms_bridge:  @ 0x086A0C24
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_nuzleaf_forms_bridge_pri	@ Priority
	.byte	se_nuzleaf_forms_bridge_rev	@ Reverb

	.word	se_nuzleaf_forms_bridge_grp

	.word	se_nuzleaf_forms_bridge_0
@ 0x086A0C30
