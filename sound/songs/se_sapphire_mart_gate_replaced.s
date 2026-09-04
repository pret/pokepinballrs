	.include "sound/MPlayDef.s"

	.equ	se_sapphire_mart_gate_replaced_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_sapphire_mart_gate_replaced_pri, 5
	.equ	se_sapphire_mart_gate_replaced_rev, reverb_set+50
	.equ	se_sapphire_mart_gate_replaced_mvl, 127
	.equ	se_sapphire_mart_gate_replaced_key, 0
	.equ	se_sapphire_mart_gate_replaced_tbs, 1
	.equ	se_sapphire_mart_gate_replaced_exg, 0
	.equ	se_sapphire_mart_gate_replaced_cmp, 1

	.section .rodata
	.global	se_sapphire_mart_gate_replaced
	.align	2

@*********************** Track 01 ***********************@

se_sapphire_mart_gate_replaced_0:  @ 0x086A124C
	.byte	KEYSH , se_sapphire_mart_gate_replaced_key+0
	.byte	TEMPO , 150*se_sapphire_mart_gate_replaced_tbs/2
	.byte		VOICE , 28
	.byte		VOL   , 100*se_sapphire_mart_gate_replaced_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte		N03   , Gs3 , v080
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		N17   , Gs4 , v096
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v-8
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W05
	.byte	FINE

@*********************** Track 02 ***********************@

se_sapphire_mart_gate_replaced_1:  @ 0x086A1273
	.byte	KEYSH , se_sapphire_mart_gate_replaced_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*se_sapphire_mart_gate_replaced_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , En4 , v060
	.byte	W04
	.byte		N17   , Gs4 , v096
	.byte	W20
	.byte	FINE

@******************************************************@

	.align	2

se_sapphire_mart_gate_replaced:  @ 0x086A1284
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_sapphire_mart_gate_replaced_pri	@ Priority
	.byte	se_sapphire_mart_gate_replaced_rev	@ Reverb

	.word	se_sapphire_mart_gate_replaced_grp

	.word	se_sapphire_mart_gate_replaced_0
	.word	se_sapphire_mart_gate_replaced_1
@ 0x086A1294
