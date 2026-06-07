	.include "sound/MPlayDef.s"

	.equ	se_spheal_surfacing_grp, gUnknown_08532310
	.equ	se_spheal_surfacing_pri, 5
	.equ	se_spheal_surfacing_rev, reverb_set+50
	.equ	se_spheal_surfacing_mvl, 127
	.equ	se_spheal_surfacing_key, 0
	.equ	se_spheal_surfacing_tbs, 1
	.equ	se_spheal_surfacing_exg, 0
	.equ	se_spheal_surfacing_cmp, 1

	.section .rodata
	.global	se_spheal_surfacing
	.align	2

@*********************** Track 01 ***********************@

se_spheal_surfacing_0:  @ 0x086A2C90
	.byte	KEYSH , se_spheal_surfacing_key+0
	.byte	TEMPO , 150*se_spheal_surfacing_tbs/2
	.byte		VOL   , 110*se_spheal_surfacing_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		TIE   , En3 , v127
	.byte	W24
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_spheal_surfacing:  @ 0x086A2CA0
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_spheal_surfacing_pri	@ Priority
	.byte	se_spheal_surfacing_rev	@ Reverb

	.word	se_spheal_surfacing_grp

	.word	se_spheal_surfacing_0
@ 0x086A2CAC
