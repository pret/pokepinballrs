	.include "sound/MPlayDef.s"

	.equ	se_unk_128_grp, gUnknown_08531D4C
	.equ	se_unk_128_pri, 5
	.equ	se_unk_128_rev, reverb_set+50
	.equ	se_unk_128_mvl, 127
	.equ	se_unk_128_key, 0
	.equ	se_unk_128_tbs, 1
	.equ	se_unk_128_exg, 0
	.equ	se_unk_128_cmp, 1

	.section .rodata
	.global	se_unk_128
	.align	2

@*********************** Track 01 ***********************@

se_unk_128_0:  @ 0x086A28F0
	.byte	KEYSH , se_unk_128_key+0
	.byte	TEMPO , 150*se_unk_128_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 2
	.byte		VOL   , 100*se_unk_128_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fs4 , v080
	.byte	W36
	.byte		EOT
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_128_1:  @ 0x086A2902
	.byte	KEYSH , se_unk_128_key+0
	.byte		VOICE , 27
	.byte		VOL   , 100*se_unk_128_mvl/mxv
	.byte		TIE   , Fn3 , v032
	.byte	W36
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_unk_128:  @ 0x086A2910
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_128_pri	@ Priority
	.byte	se_unk_128_rev	@ Reverb

	.word	se_unk_128_grp

	.word	se_unk_128_0
	.word	se_unk_128_1
@ 0x086A2920
