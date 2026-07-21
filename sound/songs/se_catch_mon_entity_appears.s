	.include "sound/MPlayDef.s"

	.equ	se_catch_mon_entity_appears_grp, gUnknown_0853174C
	.equ	se_catch_mon_entity_appears_pri, 5
	.equ	se_catch_mon_entity_appears_rev, reverb_set+50
	.equ	se_catch_mon_entity_appears_mvl, 127
	.equ	se_catch_mon_entity_appears_key, 0
	.equ	se_catch_mon_entity_appears_tbs, 1
	.equ	se_catch_mon_entity_appears_exg, 0
	.equ	se_catch_mon_entity_appears_cmp, 1

	.section .rodata
	.global	se_catch_mon_entity_appears
	.align	2

@*********************** Track 01 ***********************@

se_catch_mon_entity_appears_0:  @ 0x086A003C
	.byte	KEYSH , se_catch_mon_entity_appears_key+0
	.byte	TEMPO , 90*se_catch_mon_entity_appears_tbs/2
	.byte		VOICE , 86
	.byte		VOL   , 100*se_catch_mon_entity_appears_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Gn1 , v100
	.byte	W03
	.byte		N05   , Fn2 
	.byte	W03
	.byte	W03
	.byte		N06   , Fn2 , v052
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_catch_mon_entity_appears_1:  @ 0x086A0054
	.byte	KEYSH , se_catch_mon_entity_appears_key+0
	.byte		VOICE , 0
	.byte		VOL   , 100*se_catch_mon_entity_appears_mvl/mxv
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v052
	.byte	W03
	.byte		        Cn2 , v112
	.byte	W03
	.byte	W03
	.byte		        Cn1 , v092
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 03 ***********************@

se_catch_mon_entity_appears_2:  @ 0x086A006B
	.byte	KEYSH , se_catch_mon_entity_appears_key+0
	.byte		VOICE , 124
	.byte		VOL   , 100*se_catch_mon_entity_appears_mvl/mxv
	.byte		N03   , Gn3 , v052
	.byte	W03
	.byte		N06   , Gs4 
	.byte	W03
	.byte	W03
	.byte		        Gs4 , v020
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_catch_mon_entity_appears:  @ 0x086A0080
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_catch_mon_entity_appears_pri	@ Priority
	.byte	se_catch_mon_entity_appears_rev	@ Reverb

	.word	se_catch_mon_entity_appears_grp

	.word	se_catch_mon_entity_appears_0
	.word	se_catch_mon_entity_appears_1
	.word	se_catch_mon_entity_appears_2
@ 0x086A0094
