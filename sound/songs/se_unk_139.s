	.include "sound/MPlayDef.s"

	.equ	se_unk_139_grp, gUnknown_08531D4C
	.equ	se_unk_139_pri, 5
	.equ	se_unk_139_rev, reverb_set+50
	.equ	se_unk_139_mvl, 127
	.equ	se_unk_139_key, 0
	.equ	se_unk_139_tbs, 1
	.equ	se_unk_139_exg, 0
	.equ	se_unk_139_cmp, 1

	.section .rodata
	.global	se_unk_139
	.align	2

@*********************** Track 01 ***********************@

se_unk_139_0:  @ 0x086A2DA4
	.byte	KEYSH , se_unk_139_key+0
	.byte	TEMPO , 150*se_unk_139_tbs/2
	.byte		VOICE , 60
	.byte		BENDR , 12
	.byte		VOL   , 25*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Cn3 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 34*se_unk_139_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 46*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 56*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 70*se_unk_139_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 80*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 88*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		VOL   , 96*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		VOL   , 100*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
se_unk_139_0_B1:
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte	PATT
	 .word	se_unk_139_0_B1
	.byte		VOL   , 96*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		VOL   , 92*se_unk_139_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 84*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W02
	.byte		VOL   , 72*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		VOL   , 63*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		VOL   , 52*se_unk_139_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 37*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		VOL   , 22*se_unk_139_mvl/mxv
	.byte	W01
	.byte		        12*se_unk_139_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W02
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@

	.align	2

se_unk_139:  @ 0x086A2E70
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_139_pri	@ Priority
	.byte	se_unk_139_rev	@ Reverb

	.word	se_unk_139_grp

	.word	se_unk_139_0
@ 0x086A2E7C
