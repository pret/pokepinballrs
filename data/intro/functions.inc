gIntroStateFuncs:: @ 0x080792CC
	.4byte Intro_State0_929C
	.4byte Intro_State1_9348
	.4byte Intro_State2_9370
	.4byte Intro_State3_938C
	.4byte Intro_State4_93D0

gIntroSceneFuncs:: @ 0x080792E0
	.4byte IntroScene1_00_LoadTitleLettersAndTorchicScene
	.4byte IntroScene1TitleText_01_TitleLetterBounceReveal
	.4byte IntroScene1TitleText_02_TitleRecedeToBackground
	.4byte IntroScene1TitleText_03_1PxText
	.4byte IntroScene1Torchic_04_LargeSparkle
	.4byte IntroScene1Torchic_05_SpeedLineFadeIn
	.4byte IntroScene1Torchic_06_BrightenPokeballFlyTowardsScreen
	.4byte IntroScene1Torchic_07_TorchicRiseAndBGSplit
	.4byte nullsub_4
	.4byte IntroScene1Torchic_09_OrangeTextScrolls
	.4byte nullsub_5 @ 10
	.4byte nullsub_17
	.4byte IntroScene1Torchic_12_FlashWhite
	.4byte IntroScene1Torchic_13_ResetTilemap

	.4byte IntroScene2Pikas_14_LoadPinkYellowBackground
	.4byte nullsub_6
	.4byte IntroScene2Pikas_16_PikaPairRising
	.4byte nullsub_7
	.4byte IntroScene2Pikas_18_FlashWhite
	.4byte IntroScene2Pikas_19_ResetTilemap

	.4byte IntroScene3Treecko_20_LoadTreeckoFlipperBall @ 20
	.4byte IntroScene3Treecko_21_MoveTreeckoFlipperBallAndSplit
	.4byte IntroScene3Treecko_22_FlipperHitTextScroll
	.4byte nullsub_8
	.4byte IntroScene3Treecko_24_FlashWhite
	.4byte IntroScene3Treecko_25_ResetTilemap

	.4byte IntroScene4PlusleMinun_26_LoadTealWhiteBackground
	.4byte nullsub_9
	.4byte IntroScene4PlusleMinun_28_PlusleMinunTextScroll
	.4byte nullsub_10
	.4byte IntroScene4PlusleMinun_30_FlashWhite @ 30
	.4byte IntroScene4PlusleMinun_31_ResetTilemap

	.4byte IntroScene5Mudkip_32_LoadMudkipBallScene
	.4byte IntroScene5Mudkip_33_MoveMudkipBallSplit
	.4byte IntroScene5Mudkip_34_MoveMudkipBallTextScroll
	.4byte nullsub_11
	.4byte IntroScene5Mudkip_36_FlashWhite
	.4byte IntroScene5Mudkip_37_ResetTilemap

	.4byte IntroScene6Chinchou_38_LoadChinchou
	.4byte IntroScene6Chinchou_39_MoveChinchouBallAndStars
	.4byte IntroScene6Chinchou_40_MoveChinchouAndStars @ 40
	.4byte IntroScene6Chinchou_41_FlashWhiteClearSprites
	.4byte IntroScene6Chinchou_42_FrameAdvance

	.4byte IntroScene7Parade_43_LoadPinkYellowBackground
	.4byte IntroScene7Parade_44_MoveMakuhita
	.4byte IntroScene7Parade_45_MoveMakuhitaAndSpoink
	.4byte IntroScene7Parade_46_MoveMakuhitaPelipperAndSpoink
	.4byte IntroScene7Parade_47_MoveMakuhitaPelipperWailmerAndSpoink
	.4byte IntroScene7Parade_48_MoveWailmerShake
	.4byte IntroScene7Parade_49_FlashWhite
	.4byte IntroScene7Parade_50_ResetTilemap @ 50

	.4byte IntroScene8WailmerLaunch_51_LoadWailmerBlastBackground
	.4byte IntroScene8WailmerLaunch_52_BallAppearTimer
	.4byte IntroScene8WailmerLaunch_53_MoveBallStarsAndWailmer
	.4byte IntroScene8WailmerLaunch_54_MoveStarsAndWailmer
	.4byte nullsub_12
	.4byte nullsub_13
	.4byte IntroScene8WailmerLaunch_57_FlashWhiteClearSprites
	.4byte IntroScene8WailmerLaunch_58_ResetTilemap

	.4byte IntroScene9BallFlight_59_LoadSkySpeedOrbs
	.4byte IntroScene9BallFlight_60_MoveBallAndSky @ 60
	.4byte IntroScene9BallFlight_61_MoveSky
	.4byte IntroScene9BallFlight_62_MoveBallSkyFadeWhite
	.4byte nullsub_14
	.4byte IntroSceneX_64_HoldWhitescreen
	.4byte IntroSceneX_64_EndIntro
