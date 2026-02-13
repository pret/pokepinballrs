	.include "sound/MPlayDef.s"

	.equ	MUS_SLOTS_PRIZE_grp, gUnknown_08532808
	.equ	MUS_SLOTS_PRIZE_pri, 0
	.equ	MUS_SLOTS_PRIZE_rev, reverb_set+50
	.equ	MUS_SLOTS_PRIZE_mvl, 127
	.equ	MUS_SLOTS_PRIZE_key, 0
	.equ	MUS_SLOTS_PRIZE_tbs, 1
	.equ	MUS_SLOTS_PRIZE_exg, 0
	.equ	MUS_SLOTS_PRIZE_cmp, 1

	.section .rodata
	.global	MUS_SLOTS_PRIZE
	.align	2

@*********************** Track 01 ***********************@

MUS_SLOTS_PRIZE_0:  @ 0x0868C748
	.byte	KEYSH , MUS_SLOTS_PRIZE_key+0
	.byte	TEMPO , 122*MUS_SLOTS_PRIZE_tbs/2
	.byte		VOICE , 70
	.byte		VOL   , 104*MUS_SLOTS_PRIZE_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N07   , Cn4 , v076
	.byte	W16
	.byte		N11   , Ds4 , v068
	.byte	W08
	.byte		N10   , Cn4 
	.byte	W07
	.byte		N09   , Gs3 , v072
	.byte	W07
	.byte		        Ds3 , v068
	.byte	W08
	.byte		N06   , Cn4 , v076
	.byte	W15
	.byte		N06
	.byte	W09
	.byte		N07   , Ds3 
	.byte	W01
	.byte		N06   , Dn3 , v052
	.byte	W17
	.byte		N08   , Cn4 , v072
	.byte	W08
	.byte		        As3 , v064
	.byte	W07
	.byte		N10   , Cs4 , v068
	.byte	W07
	.byte		N09   , As3 , v060
	.byte	W08
	.byte		N05   , Fs3 , v076
	.byte	W16
	.byte		N10   , Cs4 , v068
	.byte	W08
	.byte		N04   , As3 , v076
	.byte	W16
	.byte		N10   , As3 , v056
	.byte	W07
	.byte		N06   , Cs3 , v072
	.byte	W02
	.byte		N03   , Cn3 , v056
	.byte	W15
	.byte		N06   , As3 , v068
	.byte	W10
	.byte		N08   , Gs3 , v072
	.byte	W08
	.byte		        Bn3 , v068
	.byte	W08
	.byte		N09   , Gs3 
	.byte	W08
	.byte		N05   , En3 
	.byte	W24
	.byte		N07   , Fs3 , v064
	.byte	W08
	.byte		N08   , An3 , v068
	.byte	W08
	.byte		        Fs3 , v064
	.byte	W08
	.byte		N05   , Dn3 , v076
	.byte	W24
	.byte		N04   , En3 
	.byte	W12
	.byte		        Gn3 , v072
	.byte	W12
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		        Ds3 , v064
	.byte	W12
	.byte		N04   , Dn3 , v072
	.byte	W12
	.byte		N05   , Fn3 
	.byte	W12
	.byte		        Cs3 , v060
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		N14   , Dn3 , v056
	.byte	W11
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N09   , Cn3 , v060
	.byte	W07
	.byte		TIE   , Bn2 , v064
	.byte	W72
	.byte	W72
	.byte		EOT
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 02 ***********************@

MUS_SLOTS_PRIZE_1:  @ 0x0868C7E7
	.byte	KEYSH , MUS_SLOTS_PRIZE_key+0
	.byte		VOICE , 1
	.byte		VOL   , 100*MUS_SLOTS_PRIZE_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N11   , Gs2 , v080
	.byte		N11   , Ds3 , v084
	.byte	W60
	.byte	W02
	.byte		N08   , Gs2 , v072
	.byte	W09
	.byte		N03   , Dn3 , v080
	.byte	W16
	.byte		N09   , Gs2 , v072
	.byte	W08
	.byte		N13   , Fs2 , v076
	.byte		N13   , Cs3 
	.byte	W01
	.byte	W60
	.byte	W03
	.byte		N08   , Fs2 , v068
	.byte	W07
	.byte		N05   , Cn3 , v080
	.byte	W16
	.byte		N09   , Fs2 , v068
	.byte	W08
	.byte		N11   , En2 , v084
	.byte		N11   , Bn2 
	.byte	W02
	.byte	W36
	.byte	W03
	.byte		N04   , En2 
	.byte	W08
	.byte		N12   , Dn2 , v076
	.byte		N12   , An2 , v088
	.byte	W36
	.byte	W03
	.byte		N03   , Dn2 , v084
	.byte	W10
	.byte		N06   , Cn2 , v076
	.byte		N07   , Gn2 , v080
	.byte	W24
	.byte		N06   , Bn1 
	.byte		N07   , Fs2 , v076
	.byte	W23
	.byte		        As1 
	.byte		N07   , Fn2 , v080
	.byte	W24
	.byte		N06   , En2 
	.byte	W01
	.byte		        An1 
	.byte	W24
	.byte	W01
	.byte		N48   , Gn1 
	.byte		N44   , Dn2 , v076
	.byte	W64
	.byte	W01
	.byte		N08   , Gn1 , v064
	.byte	W06
	.byte		N06   , Fs1 , v076
	.byte	W18
	.byte		N08   , Gn1 
	.byte	W06
	.byte	W01
	.byte		N68   , Gn0 , v080
	.byte	W92
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 03 ***********************@

MUS_SLOTS_PRIZE_2:  @ 0x0868C861
	.byte	KEYSH , MUS_SLOTS_PRIZE_key+0
	.byte		VOICE , 3
	.byte		VOL   , 99*MUS_SLOTS_PRIZE_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N07   , Cn4 , v076
	.byte	W16
	.byte		N11   , Ds4 , v068
	.byte	W08
	.byte		N10   , Cn4 
	.byte	W07
	.byte		N09   , Gs3 , v072
	.byte	W07
	.byte		        Ds3 , v068
	.byte	W08
	.byte		N06   , Cn4 , v076
	.byte	W15
	.byte		N06
	.byte	W09
	.byte		N07   , Ds3 
	.byte	W01
	.byte		N06   , Dn3 , v052
	.byte	W17
	.byte		N08   , Cn4 , v072
	.byte	W08
	.byte		        As3 , v064
	.byte	W07
	.byte		N10   , Cs4 , v068
	.byte	W07
	.byte		N09   , As3 , v060
	.byte	W08
	.byte		N05   , Fs3 , v076
	.byte	W16
	.byte		N10   , Cs4 , v068
	.byte	W08
	.byte		N04   , As3 , v076
	.byte	W16
	.byte		N10   , As3 , v056
	.byte	W07
	.byte		N06   , Cs3 , v072
	.byte	W02
	.byte		N03   , Cn3 , v056
	.byte	W15
	.byte		N06   , As3 , v068
	.byte	W10
	.byte		N08   , Gs3 , v072
	.byte	W08
	.byte		        Bn3 , v068
	.byte	W08
	.byte		N09   , Gs3 
	.byte	W08
	.byte		N05   , En3 
	.byte	W24
	.byte		N07   , Fs3 , v064
	.byte	W08
	.byte		N08   , An3 , v068
	.byte	W08
	.byte		        Fs3 , v064
	.byte	W08
	.byte		N05   , Dn3 , v076
	.byte	W24
	.byte		N04   , En3 
	.byte	W12
	.byte		        Gn3 , v072
	.byte	W12
	.byte		N05   , Fs3 , v068
	.byte	W12
	.byte		        Ds3 , v064
	.byte	W12
	.byte		N04   , Dn3 , v072
	.byte	W12
	.byte		N05   , Fn3 
	.byte	W12
	.byte		        Cs3 , v060
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		N14   , Dn3 , v056
	.byte	W11
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N09   , Cn3 , v060
	.byte	W07
	.byte		TIE   , Bn2 , v064
	.byte	W72
	.byte	W72
	.byte		EOT
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 04 ***********************@

MUS_SLOTS_PRIZE_3:  @ 0x0868C8FE
	.byte	KEYSH , MUS_SLOTS_PRIZE_key+0
	.byte		VOICE , 11
	.byte		VOL   , 86*MUS_SLOTS_PRIZE_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte		N04   , Gn4 , v080
	.byte		N05   , Gs4 
	.byte	W24
	.byte	W72
	.byte		        Fs4 , v072
	.byte		N04   , Gn4 , v068
	.byte	W24
	.byte		N05   , Fn4 , v076
	.byte		N07   , Fs4 
	.byte	W48
	.byte		N06   , En4 , v080
	.byte		N07   , Fn4 , v072
	.byte	W48
	.byte		N05   , Ds4 , v068
	.byte		N05   , En4 , v076
	.byte	W24
	.byte		        Dn4 , v068
	.byte		N06   , Ds4 , v076
	.byte	W24
	.byte		        Cs4 , v072
	.byte		N06   , Dn4 , v068
	.byte	W24
	.byte		        Cn4 , v064
	.byte		N07   , Cs4 , v076
	.byte	W24
	.byte		N08   , Bn3 
	.byte		N08   , Cn4 , v064
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@*********************** Track 05 ***********************@

MUS_SLOTS_PRIZE_4:  @ 0x0868C944
	.byte	KEYSH , MUS_SLOTS_PRIZE_key+0
	.byte		VOICE , 0
	.byte		VOL   , 42*MUS_SLOTS_PRIZE_mvl/mxv
	.byte		N48   , Cs2 , v100
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@

	.align	2

MUS_SLOTS_PRIZE:  @ 0x0868C958
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	MUS_SLOTS_PRIZE_pri	@ Priority
	.byte	MUS_SLOTS_PRIZE_rev	@ Reverb

	.word	MUS_SLOTS_PRIZE_grp

	.word	MUS_SLOTS_PRIZE_0
	.word	MUS_SLOTS_PRIZE_1
	.word	MUS_SLOTS_PRIZE_2
	.word	MUS_SLOTS_PRIZE_3
	.word	MUS_SLOTS_PRIZE_4
