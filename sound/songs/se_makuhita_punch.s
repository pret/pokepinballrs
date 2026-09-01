	.include "sound/MPlayDef.s"

	.equ	se_makuhita_punch_grp, gVoiceGroup_SFX_0853174C
	.equ	se_makuhita_punch_pri, 5
	.equ	se_makuhita_punch_rev, reverb_set+50
	.equ	se_makuhita_punch_mvl, 127
	.equ	se_makuhita_punch_key, 0
	.equ	se_makuhita_punch_tbs, 1
	.equ	se_makuhita_punch_exg, 0
	.equ	se_makuhita_punch_cmp, 1

	.section .rodata
	.global	se_makuhita_punch
	.align	2

@*********************** Track 01 ***********************@

se_makuhita_punch_0:  @ 0x086A07DC
	.byte	KEYSH , se_makuhita_punch_key+0
	.byte	TEMPO , 90*se_makuhita_punch_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 110*se_makuhita_punch_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Cn4 , v100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 02 ***********************@

se_makuhita_punch_1:  @ 0x086A07EF
	.byte	KEYSH , se_makuhita_punch_key+0
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 82*se_makuhita_punch_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gs4 , v060
	.byte	W03
	.byte		VOL   , 94*se_makuhita_punch_mvl/mxv
	.byte	W03
	.byte		        103*se_makuhita_punch_mvl/mxv
	.byte		N22
	.byte	W03
	.byte		VOL   , 110*se_makuhita_punch_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@*********************** Track 03 ***********************@

se_makuhita_punch_2:  @ 0x086A080A
	.byte	KEYSH , se_makuhita_punch_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_makuhita_punch_mvl/mxv
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

se_makuhita_punch:  @ 0x086A081C
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_makuhita_punch_pri	@ Priority
	.byte	se_makuhita_punch_rev	@ Reverb

	.word	se_makuhita_punch_grp

	.word	se_makuhita_punch_0
	.word	se_makuhita_punch_1
	.word	se_makuhita_punch_2
@ 0x086A0830
