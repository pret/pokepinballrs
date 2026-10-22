@ More of the orphaned sound effect tracks after broken_se_6A36D4 (sound/songs/se_unk_6A36D4.s):
@ in the European version they go on with copies of the tracks of se_high_score_earned.
@ eu_range 0x089350BC 0x08935100

	@ --- complete track, identical to se_high_score_earned_2 ---
	.byte	KEYSH , 0
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80
	.byte		PAN   , c_v-48
	.byte	W08
	.byte		N04   , Gs3 , v068
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N24   , En4
	.byte	W10
	.byte		MOD   , 5
	.byte	W06
	.byte	W24
	.byte	FINE

	@ --- start of a track, identical to se_high_score_earned_3 ---
	.byte	KEYSH , 0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80
	.byte	W08
	.byte		N04   , Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Bn3 , v020
	.byte	W04
	.byte		N24   , Gs4 , v048
	.byte	W10
	.byte		MOD   , 5
	.byte	W03
