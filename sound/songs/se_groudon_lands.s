	.include "sound/MPlayDef.s"

	.equ	se_groudon_lands_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_groudon_lands_pri, 5
	.equ	se_groudon_lands_rev, reverb_set+50
	.equ	se_groudon_lands_mvl, 127
	.equ	se_groudon_lands_key, 0
	.equ	se_groudon_lands_tbs, 1
	.equ	se_groudon_lands_exg, 0
	.equ	se_groudon_lands_cmp, 1

	.section .rodata
	.global	se_groudon_lands
	.align	2

@*********************** Track 01 ***********************@

se_groudon_lands_0:  @ 0x086A23F4
	.byte	KEYSH , se_groudon_lands_key+0
	.byte	TEMPO , 150*se_groudon_lands_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_groudon_lands_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 , v127
	.byte	W06
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		VOL   , 98*se_groudon_lands_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		VOL   , 88*se_groudon_lands_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOL   , 68*se_groudon_lands_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		        c_v+7
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		VOL   , 44*se_groudon_lands_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		VOL   , 13*se_groudon_lands_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		        c_v-40
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_groudon_lands_1:  @ 0x086A243B
	.byte	KEYSH , se_groudon_lands_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_groudon_lands_mvl/mxv
	.byte		N48   , Gn2 , v032
	.byte	W18
	.byte		VOL   , 98*se_groudon_lands_mvl/mxv
	.byte	W06
	.byte		        88*se_groudon_lands_mvl/mxv
	.byte	W06
	.byte		        68*se_groudon_lands_mvl/mxv
	.byte	W06
	.byte		        44*se_groudon_lands_mvl/mxv
	.byte	W06
	.byte		        13*se_groudon_lands_mvl/mxv
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_groudon_lands:  @ 0x086A2454
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_groudon_lands_pri	@ Priority
	.byte	se_groudon_lands_rev	@ Reverb

	.word	se_groudon_lands_grp

	.word	se_groudon_lands_0
	.word	se_groudon_lands_1
@ 0x086A2464
