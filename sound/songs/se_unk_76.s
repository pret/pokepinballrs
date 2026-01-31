	.include "sound/MPlayDef.s"

	.equ	se_unk_76_grp, gUnknown_0853174C
	.equ	se_unk_76_pri, 5
	.equ	se_unk_76_rev, reverb_set+50
	.equ	se_unk_76_mvl, 127
	.equ	se_unk_76_key, 0
	.equ	se_unk_76_tbs, 1
	.equ	se_unk_76_exg, 0
	.equ	se_unk_76_cmp, 1

	.section .rodata
	.global	se_unk_76
	.align	2

@*********************** Track 01 ***********************@

se_unk_76_0:  @ 0x0869F1AC
	.byte	KEYSH , se_unk_76_key+0
	.byte	TEMPO , 150*se_unk_76_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 110*se_unk_76_mvl/mxv
	.byte		N01   , Gs3 , v127
	.byte	W01
	.byte		        Cn4 , v068
	.byte	W02
	.byte	W02
	.byte		N03   , Gs4 , v127
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_76:  @ 0x0869F1C4
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_76_pri	@ Priority
	.byte	se_unk_76_rev	@ Reverb

	.word	se_unk_76_grp

	.word	se_unk_76_0
@ 0x0869F1D0
