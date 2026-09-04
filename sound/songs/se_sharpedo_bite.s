	.include "sound/MPlayDef.s"

	.equ	se_sharpedo_bite_grp, gVoiceGroup_SFX_08531D4C
	.equ	se_sharpedo_bite_pri, 5
	.equ	se_sharpedo_bite_rev, reverb_set+50
	.equ	se_sharpedo_bite_mvl, 127
	.equ	se_sharpedo_bite_key, 0
	.equ	se_sharpedo_bite_tbs, 1
	.equ	se_sharpedo_bite_exg, 0
	.equ	se_sharpedo_bite_cmp, 1

	.section .rodata
	.global	se_sharpedo_bite
	.align	2

@*********************** Track 01 ***********************@

se_sharpedo_bite_0:  @ 0x086A0AF4
	.byte	KEYSH , se_sharpedo_bite_key+0
	.byte	TEMPO , 220*se_sharpedo_bite_tbs/2
	.byte		VOICE , 6
	.byte		VOL   , 110*se_sharpedo_bite_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Cn3 , v127
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		        c_v-64
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , En3 
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		PAN   , c_v+7
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		        c_v-64
	.byte	W02
	.byte	FINE

@*********************** Unused Track ***********************@

se_sharpedo_bite_unused:  @ 0x086A0B26
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , An2 
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-29
	.byte	W01
	.byte		VOL   , 86*se_sharpedo_bite_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W02
	.byte		VOL   , 69*se_sharpedo_bite_mvl/mxv
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		VOL   , 53*se_sharpedo_bite_mvl/mxv
	.byte		BEND  , c_v-56
	.byte	W01
	.byte		VOL   , 20*se_sharpedo_bite_mvl/mxv
	.byte		BEND  , c_v-64
	.byte	W04
	.byte		        c_v-64
	.byte	FINE

@*********************** Track 02 ***********************@

se_sharpedo_bite_1:  @ 0x086A0B4A
	.byte	KEYSH , se_sharpedo_bite_key+0
	.byte		VOICE , 5
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 110*se_sharpedo_bite_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N03   , Gs2 , v052
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

se_sharpedo_bite:  @ 0x086A0B64
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_sharpedo_bite_pri	@ Priority
	.byte	se_sharpedo_bite_rev	@ Reverb

	.word	se_sharpedo_bite_grp

	.word	se_sharpedo_bite_0
	.word	se_sharpedo_bite_1
@ 0x086A0B74
