	.include "sound/MPlayDef.s"

	.equ	se_trigger_button_hit_grp, gUnknown_0853174C
	.equ	se_trigger_button_hit_pri, 5
	.equ	se_trigger_button_hit_rev, reverb_set+50
	.equ	se_trigger_button_hit_mvl, 127
	.equ	se_trigger_button_hit_key, 0
	.equ	se_trigger_button_hit_tbs, 1
	.equ	se_trigger_button_hit_exg, 0
	.equ	se_trigger_button_hit_cmp, 1

	.section .rodata
	.global	se_trigger_button_hit
	.align	2

@*********************** Track 01 ***********************@

se_trigger_button_hit_0:  @ 0x0869F1AC
	.byte	KEYSH , se_trigger_button_hit_key+0
	.byte	TEMPO , 150*se_trigger_button_hit_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 110*se_trigger_button_hit_mvl/mxv
	.byte		N01   , Gs3 , v127
	.byte	W01
	.byte		        Cn4 , v068
	.byte	W02
	.byte	W02
	.byte		N03   , Gs4 , v127
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_trigger_button_hit:  @ 0x0869F1C4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_trigger_button_hit_pri	@ Priority
	.byte	se_trigger_button_hit_rev	@ Reverb

	.word	se_trigger_button_hit_grp

	.word	se_trigger_button_hit_0
@ 0x0869F1D0
