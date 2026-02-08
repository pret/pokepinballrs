	.include "sound/MPlayDef.s"

	.equ	se_unk_84_grp, gUnknown_08531D4C
	.equ	se_unk_84_pri, 5
	.equ	se_unk_84_rev, reverb_set+50
	.equ	se_unk_84_mvl, 127
	.equ	se_unk_84_key, 0
	.equ	se_unk_84_tbs, 1
	.equ	se_unk_84_exg, 0
	.equ	se_unk_84_cmp, 1

	.section .rodata
	.global	se_unk_84
	.align	2

@*********************** Track 01 ***********************@

se_unk_84_0:  @ 0x0869F4E0
	.byte	KEYSH , se_unk_84_key+0
	.byte	TEMPO , 150*se_unk_84_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 110*se_unk_84_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte	W01
	.byte		N02   , Dn6 , v112
	.byte	W02
	.byte		        Cs6 
	.byte	W03
	.byte		PAN   , c_v+8
	.byte		N02   , An5 
	.byte	W02
	.byte		        Fs5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		PAN   , c_v-7
	.byte	W01
	.byte		N02   , Dn5 , v104
	.byte	W02
	.byte		        Cs5 , v100
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N02   , An4 , v096
	.byte	W02
	.byte		        Fs4 , v092
	.byte	W01
	.byte	W01
	.byte		        Dn4 , v088
	.byte	W02
	.byte		PAN   , c_v+15
	.byte	W01
	.byte		N02   , Dn6 
	.byte	W02
	.byte		        Cs6 , v084
	.byte	W03
	.byte		        An5 , v080
	.byte	W02
	.byte		        Fs5 , v076
	.byte	W01
	.byte	W01
	.byte		        Dn5 , v072
	.byte	W02
	.byte		PAN   , c_v-16
	.byte	W01
	.byte		N02   , Dn6 , v068
	.byte	W02
	.byte		        Cs6 , v064
	.byte	W03
	.byte		        An5 , v060
	.byte	W02
	.byte		        Fs5 , v056
	.byte	W01
	.byte	W01
	.byte		        Dn5 , v052
	.byte	W02
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_84_1:  @ 0x0869F53F
	.byte	KEYSH , se_unk_84_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_unk_84_mvl/mxv
	.byte		BEND  , c_v+15
	.byte		N02   , An6 , v112
	.byte	W02
	.byte		        Fs6 
	.byte	W01
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte	W01
	.byte		        Cs6 
	.byte	W02
	.byte		        An5 
	.byte	W03
	.byte		N02
	.byte	W02
	.byte		        Fs5 , v104
	.byte	W01
	.byte	W01
	.byte		        Dn5 , v100
	.byte	W02
	.byte	W01
	.byte		        Cs5 , v096
	.byte	W02
	.byte		        An4 , v092
	.byte	W03
	.byte		        An6 , v088
	.byte	W02
	.byte		        Fs6 , v084
	.byte	W01
	.byte	W01
	.byte		        Dn6 , v080
	.byte	W02
	.byte	W01
	.byte		        Cs6 , v076
	.byte	W02
	.byte		        An5 , v072
	.byte	W03
	.byte		        An6 , v068
	.byte	W02
	.byte		        Fs6 , v064
	.byte	W01
	.byte	W01
	.byte		        Dn6 , v060
	.byte	W02
	.byte	W01
	.byte		        Cs6 , v056
	.byte	W02
	.byte		        An5 , v052
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_84:  @ 0x0869F58C
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_84_pri	@ Priority
	.byte	se_unk_84_rev	@ Reverb

	.word	se_unk_84_grp

	.word	se_unk_84_0
	.word	se_unk_84_1
@ 0x0869F59C
