	.include "sound/MPlayDef.s"

	.equ	se_hatch_machine_stage_advance_grp, gVoiceGroup_SFX_0853174C
	.equ	se_hatch_machine_stage_advance_pri, 5
	.equ	se_hatch_machine_stage_advance_rev, reverb_set+50
	.equ	se_hatch_machine_stage_advance_mvl, 127
	.equ	se_hatch_machine_stage_advance_key, 0
	.equ	se_hatch_machine_stage_advance_tbs, 1
	.equ	se_hatch_machine_stage_advance_exg, 0
	.equ	se_hatch_machine_stage_advance_cmp, 1

	.section .rodata
	.global	se_hatch_machine_stage_advance
	.align	2

@*********************** Track 01 ***********************@

se_hatch_machine_stage_advance_0:  @ 0x086A0FE4
	.byte	KEYSH , se_hatch_machine_stage_advance_key+0
	.byte	TEMPO , 220*se_hatch_machine_stage_advance_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 110*se_hatch_machine_stage_advance_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		N15   , Gn4 
	.byte	W21
	.byte	FINE

@******************************************************@

	.align	2

se_hatch_machine_stage_advance:  @ 0x086A0FF4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hatch_machine_stage_advance_pri	@ Priority
	.byte	se_hatch_machine_stage_advance_rev	@ Reverb

	.word	se_hatch_machine_stage_advance_grp

	.word	se_hatch_machine_stage_advance_0
@ 0x086A1000
