	.include "sound/MPlayDef.s"

@ This is an orphaned sound effect track fragment. No song header references this
@ data, but it's identical to the end of se_unk_14b_0 and se_unk_14b_1. It's
@ puzzling as to why this fragment appears after the agb_sram.c .rodata section, separated
@ from the main sound_data .rodata.

.global	broken_se_6A36D4

broken_se_6A36D4:  @ 0x086A36D4
	@ --- tail of a truncated track ---
	.byte		N24   , Gs4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

	@ --- complete track, identical to se_unk_14b_1 ---
	.byte	KEYSH , 0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04   , En4 , v100
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N04
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N04
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N24   , Bn4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE
@ 0x086A3700
