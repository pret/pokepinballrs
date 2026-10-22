@ Generated for the European version (BPPP) from data/sound_data_2.s
.section .rodata

.include "asm/macros/m4a.inc"
.include "asm/macros/music_voice.inc"

	.include "sound/MPlayDef.s"

@ This is an orphaned sound effect track fragment. No song header references this
@ data, but it's identical to the end of se_high_score_earned_0 and se_high_score_earned_1. It's
@ puzzling as to why this fragment appears after the agb_sram.c .rodata section, separated
@ from the main sound_data .rodata.

.global	broken_se_6A36D4

	.byte 0x25, 0x50, 0x93, 0x08, 0xBC, 0x00, 0xBB, 0x57, 0xBD, 0x2E, 0xCD, 0x08, 0x08, 0x09, 0x08, 0xBE
	.byte 0x50, 0xBF, 0x70, 0x88, 0xD3, 0x47, 0x64, 0x88, 0xD3, 0x88, 0xD3, 0x88
broken_se_6A36D4:  @ 0x08935090
	@ --- tail of a truncated track ---
	.byte		N24   , Gs4 
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

	@ --- complete track, identical to se_high_score_earned_1 ---
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
	.include "data/eu/src/orphaned_se_tracks.inc"
