	.include "sound/MPlayDef.s"

	.equ	se_zigzagoon_emerge_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_zigzagoon_emerge_pri, 5
	.equ	se_zigzagoon_emerge_rev, reverb_set+50
	.equ	se_zigzagoon_emerge_mvl, 127
	.equ	se_zigzagoon_emerge_key, 0
	.equ	se_zigzagoon_emerge_tbs, 1
	.equ	se_zigzagoon_emerge_exg, 0
	.equ	se_zigzagoon_emerge_cmp, 1

	.section .rodata
	.global	se_zigzagoon_emerge
	.align	2

@*********************** Track 01 ***********************@

se_zigzagoon_emerge_0:  @ 0x086A084C
	.byte	KEYSH , se_zigzagoon_emerge_key+0
	.byte	TEMPO , 240*se_zigzagoon_emerge_tbs/2
	.byte		VOICE , 41
	.byte		BENDR , 12
	.byte		VOL   , 110*se_zigzagoon_emerge_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Fs4 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N10   , Cn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_zigzagoon_emerge_mvl/mxv
	.byte	W02
	.byte		        82*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte		        45*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte		        20*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        110*se_zigzagoon_emerge_mvl/mxv
	.byte		N10   , Cn4 , v040
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte		        82*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte		        45*se_zigzagoon_emerge_mvl/mxv
	.byte	W01
	.byte		        20*se_zigzagoon_emerge_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

se_zigzagoon_emerge:  @ 0x086A0884
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_zigzagoon_emerge_pri	@ Priority
	.byte	se_zigzagoon_emerge_rev	@ Reverb

	.word	se_zigzagoon_emerge_grp

	.word	se_zigzagoon_emerge_0
@ 0x086A0890
