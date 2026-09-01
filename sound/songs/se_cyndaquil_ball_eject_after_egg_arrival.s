	.include "sound/MPlayDef.s"

	.equ	se_cyndaquil_ball_eject_after_egg_arrival_grp, gVoiceGroup_SFX_08532310
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_pri, 5
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_rev, reverb_set+50
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_mvl, 127
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_key, 0
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_tbs, 1
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_exg, 0
	.equ	se_cyndaquil_ball_eject_after_egg_arrival_cmp, 1

	.section .rodata
	.global	se_cyndaquil_ball_eject_after_egg_arrival
	.align	2

@*********************** Track 01 ***********************@

se_cyndaquil_ball_eject_after_egg_arrival_0:  @ 0x086A04E0
	.byte	KEYSH , se_cyndaquil_ball_eject_after_egg_arrival_key+0
	.byte	TEMPO , 132*se_cyndaquil_ball_eject_after_egg_arrival_tbs/2
	.byte		VOICE , 20
	.byte		VOL   , 100*se_cyndaquil_ball_eject_after_egg_arrival_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v112
	.byte	W03
	.byte		N02
	.byte	W03
	.byte		N08
	.byte	W08
	.byte	FINE

@******************************************************@

	.align	2

se_cyndaquil_ball_eject_after_egg_arrival:  @ 0x086A04F4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_cyndaquil_ball_eject_after_egg_arrival_pri	@ Priority
	.byte	se_cyndaquil_ball_eject_after_egg_arrival_rev	@ Reverb

	.word	se_cyndaquil_ball_eject_after_egg_arrival_grp

	.word	se_cyndaquil_ball_eject_after_egg_arrival_0
@ 0x086A0500
