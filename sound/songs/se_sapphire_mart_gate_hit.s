	.include "sound/MPlayDef.s"

	.equ	se_sapphire_mart_gate_hit_grp, gUnknown_08531D4C
	.equ	se_sapphire_mart_gate_hit_pri, 5
	.equ	se_sapphire_mart_gate_hit_rev, reverb_set+50
	.equ	se_sapphire_mart_gate_hit_mvl, 127
	.equ	se_sapphire_mart_gate_hit_key, 0
	.equ	se_sapphire_mart_gate_hit_tbs, 1
	.equ	se_sapphire_mart_gate_hit_exg, 0
	.equ	se_sapphire_mart_gate_hit_cmp, 1

	.section .rodata
	.global	se_sapphire_mart_gate_hit
	.align	2

@*********************** Track 01 ***********************@

se_sapphire_mart_gate_hit_0:  @ 0x086A1294
	.byte	KEYSH , se_sapphire_mart_gate_hit_key+0
	.byte	TEMPO , 220*se_sapphire_mart_gate_hit_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 100*se_sapphire_mart_gate_hit_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		PAN   , c_v-9
	.byte		N03   , Cn4 , v080
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N03   , Cn4 , v072
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn4 , v060
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v052
	.byte	W18
	.byte	FINE

@*********************** Track 02 ***********************@

se_sapphire_mart_gate_hit_1:  @ 0x086A12C5
	.byte	KEYSH , se_sapphire_mart_gate_hit_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_sapphire_mart_gate_hit_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v072
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v068
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v064
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v060
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v056
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v048
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_sapphire_mart_gate_hit:  @ 0x086A12F0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_sapphire_mart_gate_hit_pri	@ Priority
	.byte	se_sapphire_mart_gate_hit_rev	@ Reverb

	.word	se_sapphire_mart_gate_hit_grp

	.word	se_sapphire_mart_gate_hit_0
	.word	se_sapphire_mart_gate_hit_1
@ 0x086A1300
