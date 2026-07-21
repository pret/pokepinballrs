	.include "sound/MPlayDef.s"

	.equ	se_hatch_machine_elevator_top_grp, gUnknown_08531D4C
	.equ	se_hatch_machine_elevator_top_pri, 5
	.equ	se_hatch_machine_elevator_top_rev, reverb_set+50
	.equ	se_hatch_machine_elevator_top_mvl, 127
	.equ	se_hatch_machine_elevator_top_key, 0
	.equ	se_hatch_machine_elevator_top_tbs, 1
	.equ	se_hatch_machine_elevator_top_exg, 0
	.equ	se_hatch_machine_elevator_top_cmp, 1

	.section .rodata
	.global	se_hatch_machine_elevator_top
	.align	2

@*********************** Track 01 ***********************@

se_hatch_machine_elevator_top_0:  @ 0x086A10A4
	.byte	KEYSH , se_hatch_machine_elevator_top_key+0
	.byte	TEMPO , 150*se_hatch_machine_elevator_top_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 100*se_hatch_machine_elevator_top_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn3 , v127
	.byte	W02
	.byte		N02   , Gn2 
	.byte	W04
	.byte		N17   , Cn3 
	.byte	W06
	.byte		VOL   , 98*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W01
	.byte		        91*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W01
	.byte		        81*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W02
	.byte		        75*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W01
	.byte		        60*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W01
	.byte		        42*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W01
	.byte		        25*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W02
	.byte		        10*se_hatch_machine_elevator_top_mvl/mxv
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_hatch_machine_elevator_top_1:  @ 0x086A10CA
	.byte		VOL   , 100*se_hatch_machine_elevator_top_mvl/mxv
	.byte	KEYSH , se_hatch_machine_elevator_top_key+0
	.byte		VOICE , 4
	.byte		N01   , Cn3 , v064
	.byte	W02
	.byte		N02
	.byte	W04
	.byte		N02
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_hatch_machine_elevator_top:  @ 0x086A10DC
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hatch_machine_elevator_top_pri	@ Priority
	.byte	se_hatch_machine_elevator_top_rev	@ Reverb

	.word	se_hatch_machine_elevator_top_grp

	.word	se_hatch_machine_elevator_top_0
	.word	se_hatch_machine_elevator_top_1
@ 0x086A10EC
