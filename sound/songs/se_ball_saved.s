	.include "sound/MPlayDef.s"

	.equ	se_ball_saved_grp, gUnknown_0853174C
	.equ	se_ball_saved_pri, 5
	.equ	se_ball_saved_rev, reverb_set+50
	.equ	se_ball_saved_mvl, 127
	.equ	se_ball_saved_key, 0
	.equ	se_ball_saved_tbs, 1
	.equ	se_ball_saved_exg, 0
	.equ	se_ball_saved_cmp, 1

	.section .rodata
	.global	se_ball_saved
	.align	2

@*********************** Track 01 ***********************@

se_ball_saved_0:  @ 0x0869FAD0
	.byte	KEYSH , se_ball_saved_key+0
	.byte	TEMPO , 90*se_ball_saved_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 110*se_ball_saved_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Cn4 , v100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_ball_saved_1:  @ 0x0869FAE3
	.byte	KEYSH , se_ball_saved_key+0
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 82*se_ball_saved_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gs4 , v060
	.byte	W03
	.byte		VOL   , 94*se_ball_saved_mvl/mxv
	.byte	W03
	.byte		        103*se_ball_saved_mvl/mxv
	.byte		N22
	.byte	W03
	.byte		VOL   , 110*se_ball_saved_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 03 ***********************@

se_ball_saved_2:  @ 0x0869FAFE
	.byte	KEYSH , se_ball_saved_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_ball_saved_mvl/mxv
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		N18   , Cn3 , v092
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@

	.align	2

se_ball_saved:  @ 0x0869FB10
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_ball_saved_pri	@ Priority
	.byte	se_ball_saved_rev	@ Reverb

	.word	se_ball_saved_grp

	.word	se_ball_saved_0
	.word	se_ball_saved_1
	.word	se_ball_saved_2
@ 0x0869FB24
