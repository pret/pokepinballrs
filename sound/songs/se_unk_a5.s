	.include "sound/MPlayDef.s"

	.equ	se_unk_a5_grp, gUnknown_0853174C
	.equ	se_unk_a5_pri, 5
	.equ	se_unk_a5_rev, reverb_set+50
	.equ	se_unk_a5_mvl, 127
	.equ	se_unk_a5_key, 0
	.equ	se_unk_a5_tbs, 1
	.equ	se_unk_a5_exg, 0
	.equ	se_unk_a5_cmp, 1

	.section .rodata
	.global	se_unk_a5
	.align	2

@*********************** Track 01 ***********************@

se_unk_a5_0:  @ 0x0869FF6C
	.byte	KEYSH , se_unk_a5_key+0
	.byte	TEMPO , 144*se_unk_a5_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_unk_a5_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W03
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W04
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_a5_1:  @ 0x0869FF99
	.byte	KEYSH , se_unk_a5_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_unk_a5_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_a5:  @ 0x0869FFC4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_a5_pri	@ Priority
	.byte	se_unk_a5_rev	@ Reverb

	.word	se_unk_a5_grp

	.word	se_unk_a5_0
	.word	se_unk_a5_1
@ 0x0869FFD4
