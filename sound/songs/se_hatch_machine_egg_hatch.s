	.include "sound/MPlayDef.s"

	.equ	se_hatch_machine_egg_hatch_grp, gUnknown_08531D4C
	.equ	se_hatch_machine_egg_hatch_pri, 5
	.equ	se_hatch_machine_egg_hatch_rev, reverb_set+50
	.equ	se_hatch_machine_egg_hatch_mvl, 127
	.equ	se_hatch_machine_egg_hatch_key, 0
	.equ	se_hatch_machine_egg_hatch_tbs, 1
	.equ	se_hatch_machine_egg_hatch_exg, 0
	.equ	se_hatch_machine_egg_hatch_cmp, 1

	.section .rodata
	.global	se_hatch_machine_egg_hatch
	.align	2

@*********************** Track 01 ***********************@

se_hatch_machine_egg_hatch_0:  @ 0x086A1000
	.byte	KEYSH , se_hatch_machine_egg_hatch_key+0
se_hatch_machine_egg_hatch_0_B1:
	.byte	TEMPO , 150*se_hatch_machine_egg_hatch_tbs/2
	.byte		VOICE , 15
	.byte		VOL   , 90*se_hatch_machine_egg_hatch_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn2 , v100
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		EOT
	.byte	GOTO
	 .word	se_hatch_machine_egg_hatch_0_B1
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_hatch_machine_egg_hatch:  @ 0x086A101C
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hatch_machine_egg_hatch_pri	@ Priority
	.byte	se_hatch_machine_egg_hatch_rev	@ Reverb

	.word	se_hatch_machine_egg_hatch_grp

	.word	se_hatch_machine_egg_hatch_0
@ 0x086A1028
