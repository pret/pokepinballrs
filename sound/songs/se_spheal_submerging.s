	.include "sound/MPlayDef.s"

	.equ	se_spheal_submerging_grp, gUnknown_08532310
	.equ	se_spheal_submerging_pri, 5
	.equ	se_spheal_submerging_rev, reverb_set+50
	.equ	se_spheal_submerging_mvl, 127
	.equ	se_spheal_submerging_key, 0
	.equ	se_spheal_submerging_tbs, 1
	.equ	se_spheal_submerging_exg, 0
	.equ	se_spheal_submerging_cmp, 1

	.section .rodata
	.global	se_spheal_submerging
	.align	2

@*********************** Track 01 ***********************@

se_spheal_submerging_0:  @ 0x086A2CAC
	.byte	KEYSH , se_spheal_submerging_key+0
	.byte	TEMPO , 150*se_spheal_submerging_tbs/2
	.byte		VOL   , 110*se_spheal_submerging_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOICE , 34
	.byte		TIE   , Cn3 , v127
	.byte	W48
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_spheal_submerging:  @ 0x086A2CBC
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_spheal_submerging_pri	@ Priority
	.byte	se_spheal_submerging_rev	@ Reverb

	.word	se_spheal_submerging_grp

	.word	se_spheal_submerging_0
@ 0x086A2CC8
