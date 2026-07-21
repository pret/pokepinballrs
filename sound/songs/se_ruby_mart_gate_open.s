	.include "sound/MPlayDef.s"

	.equ	se_ruby_mart_gate_open_grp, gUnknown_08531D4C
	.equ	se_ruby_mart_gate_open_pri, 5
	.equ	se_ruby_mart_gate_open_rev, reverb_set+50
	.equ	se_ruby_mart_gate_open_mvl, 127
	.equ	se_ruby_mart_gate_open_key, 0
	.equ	se_ruby_mart_gate_open_tbs, 1
	.equ	se_ruby_mart_gate_open_exg, 0
	.equ	se_ruby_mart_gate_open_cmp, 1

	.section .rodata
	.global	se_ruby_mart_gate_open
	.align	2

@*********************** Track 01 ***********************@

se_ruby_mart_gate_open_0:  @ 0x086A05B8
	.byte	KEYSH , se_ruby_mart_gate_open_key+0
	.byte	TEMPO , 150*se_ruby_mart_gate_open_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 110*se_ruby_mart_gate_open_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_ruby_mart_gate_open:  @ 0x086A05D0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ruby_mart_gate_open_pri	@ Priority
	.byte	se_ruby_mart_gate_open_rev	@ Reverb

	.word	se_ruby_mart_gate_open_grp

	.word	se_ruby_mart_gate_open_0
@ 0x086A05DC
