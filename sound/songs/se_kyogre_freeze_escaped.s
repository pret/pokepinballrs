	.include "sound/MPlayDef.s"

	.equ	se_kyogre_freeze_escaped_grp, gUnknown_08532310
	.equ	se_kyogre_freeze_escaped_pri, 5
	.equ	se_kyogre_freeze_escaped_rev, reverb_set+50
	.equ	se_kyogre_freeze_escaped_mvl, 127
	.equ	se_kyogre_freeze_escaped_key, 0
	.equ	se_kyogre_freeze_escaped_tbs, 1
	.equ	se_kyogre_freeze_escaped_exg, 0
	.equ	se_kyogre_freeze_escaped_cmp, 1

	.section .rodata
	.global	se_kyogre_freeze_escaped
	.align	2

@*********************** Track 01 ***********************@

se_kyogre_freeze_escaped_0:  @ 0x086A217C
	.byte	KEYSH , se_kyogre_freeze_escaped_key+0
	.byte	TEMPO , 150*se_kyogre_freeze_escaped_tbs/2
	.byte		VOL   , 100*se_kyogre_freeze_escaped_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 30
	.byte		N48   , Cn3 , v127
	.byte	W48
	.byte	FINE

@*********************** Track 02 ***********************@

se_kyogre_freeze_escaped_1:  @ 0x086A218B
	.byte	KEYSH , se_kyogre_freeze_escaped_key+0
	.byte	TEMPO , 150*se_kyogre_freeze_escaped_tbs/2
	.byte		VOL   , 100*se_kyogre_freeze_escaped_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 19
	.byte		N06   , Cn7 , v100
	.byte	W06
	.byte		N48   , Cs7 , v100
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_kyogre_freeze_escaped:  @ 0x086A21A0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kyogre_freeze_escaped_pri	@ Priority
	.byte	se_kyogre_freeze_escaped_rev	@ Reverb

	.word	se_kyogre_freeze_escaped_grp

	.word	se_kyogre_freeze_escaped_0
	.word	se_kyogre_freeze_escaped_1
@ 0x086A21B0
