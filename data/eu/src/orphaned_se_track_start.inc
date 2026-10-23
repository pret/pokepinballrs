@ In the European version the orphaned track fragment of broken_se_6A36D4 is complete: its start
@ comes before it, after a leftover word.
@ eu_range 0x08935074 0x08935090

	.4byte 0x08935025  @ leftover word: points into se_whiscash_earthquake_1, nothing reads it

	@ --- start of a track, identical to se_high_score_earned_0 (it goes on in broken_se_6A36D4) ---
	.byte	KEYSH , 0
	.byte	TEMPO , 174/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80
	.byte		PAN   , c_v+48
	.byte	W08
	.byte		N04   , Bn3 , v100
	.byte	W08
	.byte		N04
	.byte	W08
	.byte		N04
	.byte	W08
