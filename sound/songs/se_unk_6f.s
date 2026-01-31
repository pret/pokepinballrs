	.include "sound/MPlayDef.s"

	.equ	se_unk_6f_grp, gUnknown_0853174C
	.equ	se_unk_6f_pri, 5
	.equ	se_unk_6f_rev, reverb_set+50
	.equ	se_unk_6f_mvl, 127
	.equ	se_unk_6f_key, 0
	.equ	se_unk_6f_tbs, 1
	.equ	se_unk_6f_exg, 0
	.equ	se_unk_6f_cmp, 1

	.section .rodata
	.global	se_unk_6f
	.align	2

@*********************** Track 01 ***********************@

se_unk_6f_0:  @ 0x0869F07C
	.byte	KEYSH , se_unk_6f_key+0
	.byte	TEMPO , 144*se_unk_6f_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_unk_6f_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W03
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W04
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_6f_1:  @ 0x0869F0A9
	.byte	KEYSH , se_unk_6f_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_unk_6f_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_6f:  @ 0x0869F0D4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_6f_pri	@ Priority
	.byte	se_unk_6f_rev	@ Reverb

	.word	se_unk_6f_grp

	.word	se_unk_6f_0
	.word	se_unk_6f_1
@ 0x0869F0E4
