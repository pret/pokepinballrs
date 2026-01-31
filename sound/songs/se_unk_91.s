	.include "sound/MPlayDef.s"

	.equ	se_unk_91_grp, gUnknown_0853174C
	.equ	se_unk_91_pri, 5
	.equ	se_unk_91_rev, reverb_set+50
	.equ	se_unk_91_mvl, 127
	.equ	se_unk_91_key, 0
	.equ	se_unk_91_tbs, 1
	.equ	se_unk_91_exg, 0
	.equ	se_unk_91_cmp, 1

	.section .rodata
	.global	se_unk_91
	.align	2

@*********************** Track 01 ***********************@

se_unk_91_0:  @ 0x0869F950
	.byte	KEYSH , se_unk_91_key+0
	.byte	TEMPO , 100*se_unk_91_tbs/2
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 90*se_unk_91_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N01   , Cn5 , v064
	.byte	W01
	.byte		        Cn5 , v020
	.byte	W01
	.byte		        Cn5 , v064
	.byte	W01
	.byte		        Cn5 , v020
	.byte	W01
	.byte		        Cn6 , v064
	.byte	W02
	.byte		        Cn6 , v020
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_91:  @ 0x0869F978
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_91_pri	@ Priority
	.byte	se_unk_91_rev	@ Reverb

	.word	se_unk_91_grp

	.word	se_unk_91_0
@ 0x0869F984
