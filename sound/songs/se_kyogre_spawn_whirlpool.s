	.include "sound/MPlayDef.s"

	.equ	se_kyogre_spawn_whirlpool_grp, gVoiceGroup_SFX_08532310
	.equ	se_kyogre_spawn_whirlpool_pri, 5
	.equ	se_kyogre_spawn_whirlpool_rev, reverb_set+50
	.equ	se_kyogre_spawn_whirlpool_mvl, 127
	.equ	se_kyogre_spawn_whirlpool_key, 0
	.equ	se_kyogre_spawn_whirlpool_tbs, 1
	.equ	se_kyogre_spawn_whirlpool_exg, 0
	.equ	se_kyogre_spawn_whirlpool_cmp, 1

	.section .rodata
	.global	se_kyogre_spawn_whirlpool
	.align	2

@*********************** Track 01 ***********************@

se_kyogre_spawn_whirlpool_0:  @ 0x086A1FD4
	.byte	KEYSH , se_kyogre_spawn_whirlpool_key+0
	.byte	TEMPO , 150*se_kyogre_spawn_whirlpool_tbs/2
	.byte		VOL   , 110*se_kyogre_spawn_whirlpool_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 5
	.byte		N48   , En3 , v127
	.byte	W48
	.byte	FINE

@******************************************************@

	.align	2

se_kyogre_spawn_whirlpool:  @ 0x086A1FE4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kyogre_spawn_whirlpool_pri	@ Priority
	.byte	se_kyogre_spawn_whirlpool_rev	@ Reverb

	.word	se_kyogre_spawn_whirlpool_grp

	.word	se_kyogre_spawn_whirlpool_0
@ 0x086A1FF0
