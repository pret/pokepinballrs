	.include "sound/MPlayDef.s"

	.equ	se_unk_ea_grp, gUnknown_08531D4C
	.equ	se_unk_ea_pri, 5
	.equ	se_unk_ea_rev, reverb_set+50
	.equ	se_unk_ea_mvl, 127
	.equ	se_unk_ea_key, 0
	.equ	se_unk_ea_tbs, 1
	.equ	se_unk_ea_exg, 0
	.equ	se_unk_ea_cmp, 1

	.section .rodata
	.global	se_unk_ea
	.align	2

@*********************** Track 01 ***********************@

se_unk_ea_0:  @ 0x086A1354
	.byte	KEYSH , se_unk_ea_key+0
	.byte	TEMPO , 220*se_unk_ea_tbs/2
	.byte		VOICE , 58
	.byte		BENDR , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 19*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-32
	.byte		N16   , Gn1 , v127
	.byte	W01
	.byte		VOL   , 43*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 72*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 92*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W01
	.byte		VOL   , 109*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v+19
	.byte	W02
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+40
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		VOL   , 102*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v+19
	.byte	W01
	.byte		VOL   , 88*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		VOL   , 69*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		VOL   , 37*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 17*se_unk_ea_mvl/mxv
	.byte		BEND  , c_v-34
	.byte	W10
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_ea_1:  @ 0x086A139A
	.byte	KEYSH , se_unk_ea_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_unk_ea_mvl/mxv
	.byte		N02   , Gs3 , v032
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W02
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W02
	.byte		        Gs2 
	.byte	W10
	.byte	FINE

@******************************************************@

	.align	2

se_unk_ea:  @ 0x086A13B4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_ea_pri	@ Priority
	.byte	se_unk_ea_rev	@ Reverb

	.word	se_unk_ea_grp

	.word	se_unk_ea_0
	.word	se_unk_ea_1
@ 0x086A13C4
