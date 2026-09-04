	.include "sound/MPlayDef.s"

	.equ	se_rayquaza_lightning_trap_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_rayquaza_lightning_trap_pri, 5
	.equ	se_rayquaza_lightning_trap_rev, reverb_set+50
	.equ	se_rayquaza_lightning_trap_mvl, 127
	.equ	se_rayquaza_lightning_trap_key, 0
	.equ	se_rayquaza_lightning_trap_tbs, 1
	.equ	se_rayquaza_lightning_trap_exg, 0
	.equ	se_rayquaza_lightning_trap_cmp, 1

	.section .rodata
	.global	se_rayquaza_lightning_trap
	.align	2

@*********************** Track 01 ***********************@

se_rayquaza_lightning_trap_0:  @ 0x086A2988
	.byte	KEYSH , se_rayquaza_lightning_trap_key+0
	.byte	TEMPO , 220*se_rayquaza_lightning_trap_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 100*se_rayquaza_lightning_trap_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v088
	.byte	W06
	.byte		PAN   , c_v-9
	.byte		N03   , Cn4 , v080
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N03   , Cn4 , v072
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn4 , v060
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn4 , v052
	.byte	W18
	.byte	FINE

@*********************** Track 02 ***********************@

se_rayquaza_lightning_trap_1:  @ 0x086A29B9
	.byte	KEYSH , se_rayquaza_lightning_trap_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_rayquaza_lightning_trap_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v072
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v068
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v064
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v060
	.byte	W06
	.byte		PAN   , c_v+9
	.byte		N02   , Gn3 , v056
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v048
	.byte	W18
	.byte	FINE

@******************************************************@

	.align	2

se_rayquaza_lightning_trap:  @ 0x086A29E4
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rayquaza_lightning_trap_pri	@ Priority
	.byte	se_rayquaza_lightning_trap_rev	@ Reverb

	.word	se_rayquaza_lightning_trap_grp

	.word	se_rayquaza_lightning_trap_0
	.word	se_rayquaza_lightning_trap_1
@ 0x086A29F4
