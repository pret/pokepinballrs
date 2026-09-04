	.include "sound/MPlayDef.s"

	.equ	se_rayquaza_lightning_charge_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_rayquaza_lightning_charge_pri, 5
	.equ	se_rayquaza_lightning_charge_rev, reverb_set+50
	.equ	se_rayquaza_lightning_charge_mvl, 127
	.equ	se_rayquaza_lightning_charge_key, 0
	.equ	se_rayquaza_lightning_charge_tbs, 1
	.equ	se_rayquaza_lightning_charge_exg, 0
	.equ	se_rayquaza_lightning_charge_cmp, 1

	.section .rodata
	.global	se_rayquaza_lightning_charge
	.align	2

@*********************** Track 01 ***********************@

se_rayquaza_lightning_charge_0:  @ 0x086A28F0
	.byte	KEYSH , se_rayquaza_lightning_charge_key+0
	.byte	TEMPO , 150*se_rayquaza_lightning_charge_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 2
	.byte		VOL   , 100*se_rayquaza_lightning_charge_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fs4 , v080
	.byte	W36
	.byte		EOT
	.byte	FINE

@*********************** Track 02 ***********************@

se_rayquaza_lightning_charge_1:  @ 0x086A2902
	.byte	KEYSH , se_rayquaza_lightning_charge_key+0
	.byte		VOICE , 27
	.byte		VOL   , 100*se_rayquaza_lightning_charge_mvl/mxv
	.byte		TIE   , Fn3 , v032
	.byte	W36
	.byte		EOT
	.byte	FINE

@******************************************************@

	.align	2

se_rayquaza_lightning_charge:  @ 0x086A2910
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rayquaza_lightning_charge_pri	@ Priority
	.byte	se_rayquaza_lightning_charge_rev	@ Reverb

	.word	se_rayquaza_lightning_charge_grp

	.word	se_rayquaza_lightning_charge_0
	.word	se_rayquaza_lightning_charge_1
@ 0x086A2920
