	.include "sound/MPlayDef.s"

	.equ	se_hatch_machine_spinner_trigger_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_hatch_machine_spinner_trigger_pri, 5
	.equ	se_hatch_machine_spinner_trigger_rev, reverb_set+50
	.equ	se_hatch_machine_spinner_trigger_mvl, 127
	.equ	se_hatch_machine_spinner_trigger_key, 0
	.equ	se_hatch_machine_spinner_trigger_tbs, 1
	.equ	se_hatch_machine_spinner_trigger_exg, 0
	.equ	se_hatch_machine_spinner_trigger_cmp, 1

	.section .rodata
	.global	se_hatch_machine_spinner_trigger
	.align	2

@*********************** Track 01 ***********************@

se_hatch_machine_spinner_trigger_0:  @ 0x086A0F90
	.byte	KEYSH , se_hatch_machine_spinner_trigger_key+0
	.byte	TEMPO , 150*se_hatch_machine_spinner_trigger_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_hatch_machine_spinner_trigger_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn6 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Cn6 , v040
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_hatch_machine_spinner_trigger_1:  @ 0x086A0FA4
	.byte	KEYSH , se_hatch_machine_spinner_trigger_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_hatch_machine_spinner_trigger_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Gn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_hatch_machine_spinner_trigger:  @ 0x086A0FB8
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hatch_machine_spinner_trigger_pri	@ Priority
	.byte	se_hatch_machine_spinner_trigger_rev	@ Reverb

	.word	se_hatch_machine_spinner_trigger_grp

	.word	se_hatch_machine_spinner_trigger_0
	.word	se_hatch_machine_spinner_trigger_1
@ 0x086A0FC8
