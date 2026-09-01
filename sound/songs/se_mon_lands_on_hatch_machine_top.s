	.include "sound/MPlayDef.s"

	.equ	se_mon_lands_on_hatch_machine_top_grp, gVoiceGroup_SFX_08532310
	.equ	se_mon_lands_on_hatch_machine_top_pri, 5
	.equ	se_mon_lands_on_hatch_machine_top_rev, reverb_set+50
	.equ	se_mon_lands_on_hatch_machine_top_mvl, 127
	.equ	se_mon_lands_on_hatch_machine_top_key, 0
	.equ	se_mon_lands_on_hatch_machine_top_tbs, 1
	.equ	se_mon_lands_on_hatch_machine_top_exg, 0
	.equ	se_mon_lands_on_hatch_machine_top_cmp, 1

	.section .rodata
	.global	se_mon_lands_on_hatch_machine_top
	.align	2

@*********************** Track 01 ***********************@

se_mon_lands_on_hatch_machine_top_0:  @ 0x086A0FC8
	.byte	KEYSH , se_mon_lands_on_hatch_machine_top_key+0
	.byte	TEMPO , 150*se_mon_lands_on_hatch_machine_top_tbs/2
	.byte		VOL   , 100*se_mon_lands_on_hatch_machine_top_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 30
	.byte		N48   , Cn1 , v127
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_mon_lands_on_hatch_machine_top:  @ 0x086A0FD8
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mon_lands_on_hatch_machine_top_pri	@ Priority
	.byte	se_mon_lands_on_hatch_machine_top_rev	@ Reverb

	.word	se_mon_lands_on_hatch_machine_top_grp

	.word	se_mon_lands_on_hatch_machine_top_0
@ 0x086A0FE4
