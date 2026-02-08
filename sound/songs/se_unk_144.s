	.include "sound/MPlayDef.s"

	.equ	se_unk_144_grp, gUnknown_08531D4C
	.equ	se_unk_144_pri, 5
	.equ	se_unk_144_rev, reverb_set+50
	.equ	se_unk_144_mvl, 127
	.equ	se_unk_144_key, 0
	.equ	se_unk_144_tbs, 1
	.equ	se_unk_144_exg, 0
	.equ	se_unk_144_cmp, 1

	.section .rodata
	.global	se_unk_144
	.align	2

@*********************** Track 01 ***********************@

se_unk_144_0:  @ 0x086A2FAC
	.byte	KEYSH , se_unk_144_key+0
	.byte	TEMPO , 150*se_unk_144_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 95*se_unk_144_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte	W03
	.byte		N06   , Dn6 , v112
	.byte	W03
	.byte	W03
	.byte		        An5 , v104
	.byte	W03
	.byte	W03
	.byte		        Dn6 , v100
	.byte	W03
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v096
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v092
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6 , v088
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v084
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v080
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v076
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6 
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v068
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v064
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6 , v060
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v056
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		N06   , Dn6 , v052
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v048
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+8
	.byte		N06   , Dn6 , v044
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v040
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		N06   , Dn6 , v036
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v032
	.byte	W03
	.byte	W03
	.byte	FINE

@*********************** Track 02 ***********************@

se_unk_144_1:  @ 0x086A3049
	.byte	KEYSH , se_unk_144_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_unk_144_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , En6 , v108
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v104
	.byte	W03
	.byte	W03
	.byte		        En6 , v100
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v096
	.byte	W03
	.byte	W03
	.byte		        En6 , v092
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v088
	.byte	W03
	.byte	W03
	.byte		        En6 
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v084
	.byte	W03
	.byte	W03
	.byte		        En6 , v080
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v076
	.byte	W03
	.byte	W03
	.byte		        En6 , v072
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v068
	.byte	W03
	.byte	W03
	.byte		        En6 , v064
	.byte	W03
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte	W03
	.byte		        En6 , v060
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v056
	.byte	W03
	.byte	W03
	.byte		        En6 , v052
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v048
	.byte	W03
	.byte	W03
	.byte		        En6 , v044
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v040
	.byte	W03
	.byte	W03
	.byte		        En6 , v036
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v032
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_unk_144:  @ 0x086A30B0
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_144_pri	@ Priority
	.byte	se_unk_144_rev	@ Reverb

	.word	se_unk_144_grp

	.word	se_unk_144_0
	.word	se_unk_144_1
@ 0x086A30C0
