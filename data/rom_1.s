.section .rodata
.align 2

#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "gba/io_reg.h"
	.include "asm/macros.inc"

gAreaRouletteTable:: @ 0x08055A68
	.2byte AREA_FOREST_RUBY
	.2byte AREA_VOLCANO
	.2byte AREA_PLAINS_RUBY
	.2byte AREA_OCEAN_RUBY
	.2byte AREA_SAFARI_ZONE
	.2byte AREA_CAVE_RUBY
	.2byte AREA_RUIN_RUBY
	.2byte AREA_FOREST_SAPPHIRE
	.2byte AREA_LAKE
	.2byte AREA_PLAINS_SAPPHIRE
	.2byte AREA_WILDERNESS
	.2byte AREA_OCEAN_SAPPHIRE
	.2byte AREA_CAVE_SAPPHIRE
	.2byte AREA_RUIN_SAPPHIRE

.include "data/mon_locations.inc"

.include "data/sine_table.inc"

.include "data/graphics/empty_oam_data_block.inc"

gGbPlayerPalettes:: @ 0x08058058
	@ This one is weird because some of the colors set the unused bit, so we can't do a matching conversion
	@ from a JASC palette format. Naming it with a ".bin" suffix to prevent `make clean` from deleting it.
	.incbin "graphics/gb_player/gb_player.gbapal.bin"

gGbPlayerGfx:: @ 0x08058248
	.incbin "graphics/gb_player/gb_player.8bpp"

gGbPlayerTilemap:: @ 0x0805C248
	.incbin "graphics/gb_player/gb_player_tilemap.bin"

Sio32ConnectionData:: @ 0x0805C748
	.ascii "NINTENDO"

gBonusFieldSelectStateFuncs:: @ 0x0805C750
	.4byte LoadBonusFieldSelectGraphics
	.4byte BonusFieldSelect_State1_2768
	.4byte BonusFieldSelect_State2_2990

gEReaderStateFuncs:: @ 0x0805C75C
	.4byte LoadEReaderGraphics
	.4byte Ereader_State1_2E40
	.4byte Ereader_State2_2FC0
	.4byte Ereader_State3_304C
	.4byte Ereader_State4_3208
	.4byte Ereader_State5_33A0
	.4byte Ereader_State6_343C
	.4byte Ereader_State7_33C8
	.4byte Ereader_State8_374C

gDexInfoWindowMiddleRowTiles:: @ 0x0805C780
	.2byte 0x00, 0x9A, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x9B, 0x00, 0x00, 0x00

gDexInfoWindowBottomRowTiles:: @ 0x0805C7C0
	.2byte 0x00, 0x5A, 0x5B, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
	.2byte 0x03, 0x03, 0x03, 0x5C, 0x9C, 0x00, 0x00, 0x00

gDexInfoWindowEmptyRowTiles:: @ 0x0805C8
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.2byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

gDexInfoWindowEmptyTextRowTiles:: @ 0x0805C840
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
	.2byte 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F

gPokedexStateFuncs:: @ 0x0805C880
	.4byte LoadPokedexGraphics          @ POKEDEX_STATE_LOAD_GRAPHICS
	.4byte Pokedex_HandleListInput      @ POKEDEX_STATE_HANDLE_LIST_INPUT
	.4byte Pokedex_PostScrollRefresh          @ POKEDEX_STATE_2
	.4byte Pokedex_InfoWindowSlideIn          @ POKEDEX_STATE_3
	.4byte Pokedex_InfoWindowSlideOut          @ POKEDEX_STATE_4
	.4byte Pokedex_DetailViewInput          @ POKEDEX_STATE_5
	.4byte Pokedex_LinkSetup            @ POKEDEX_STATE_LINK_SETUP
	.4byte Pokedex_LinkTransferLoop          @ POKEDEX_STATE_7
	.4byte Pokedex_LinkErrorTimeout          @ POKEDEX_STATE_8
	.4byte Pokedex_LinkSuccessSequence          @ POKEDEX_STATE_9
	.4byte Pokedex_LinkRetryDelay         @ POKEDEX_STATE_10
	.4byte Pokedex_DeleteConfirmation         @ POKEDEX_STATE_DELETE_CONFIRMATION
	.4byte Pokedex_ReturnToTitle        @ POKEDEX_STATE_RETURN_TO_TITLE

gPokedexEntries:: @ 0x0805C8B4
	.include "data/pokedex_entries/dex.inc"

	.align 2, 0
gFieldSelectStateFuncs:: @ 0x080792C0
	.4byte LoadFieldSelectGraphics
	.4byte FieldSelect_State1_8C7C
	.4byte FieldSelect_State2_8F64

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

	.4byte IntroScene4PlussleMinun_26_LoadTealWhiteBackground
	.4byte nullsub_9
	.4byte IntroScene4PlussleMinun_28_PlusleMinunTextScroll
	.4byte nullsub_10
	.4byte IntroScene4PlussleMinun_30_FlashWhite @ 30
	.4byte IntroScene4PlussleMinun_31_ResetTilemap

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

gHighScoresStateFuncs:: @ 0x080793E8
	.4byte LoadHighScoreGraphics
	.4byte HighScore_ShowCompletionBanner
	.4byte HighScore_FlashNewEntry
	.4byte HighScore_BrowseScores
	.4byte HighScore_NameEntry
	.4byte HighScore_InitLinkExchange
	.4byte HighScore_LinkExchangeLoop
	.4byte HighScore_LinkError
	.4byte HighScore_LinkSuccess
	.4byte HighScore_LinkRetryWait
	.4byte HighScore_ResetConfirmation
	.4byte HighScore_ExitToTitle
	.4byte HighScore_ReloadAfterLink
	.4byte HighScore_ShowMergedScores
	.4byte HighScore_ReturnToMain

gIdleHighScoresStateFuncs:: @ 0x08079424
	.4byte IdleHighScore_LoadGraphics
	.4byte IdleHighScore_AutoScroll
	.4byte IdleHighScore_Exit

gDefaultHighScores:: @ 0x08079430
	@ 4 'name' blocks followed by 2 score high/low
	.4byte 0x28, 0x28, 0x28, 0x28, 0x1, 0x0       @ 100M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x2faf080 @  50M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x1312d00 @  20M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x989680  @  10M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x7a1200  @   8M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x4c4b40  @   5M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x2dc6c0  @   3M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0xf4240   @   1M

	.4byte 0x28, 0x28, 0x28, 0x28, 0x1, 0x0       @ 100M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x2faf080 @  50M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x1312d00 @  20M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x989680  @  10M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x7a1200  @   8M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x4c4b40  @   5M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0x2dc6c0  @   3M
	.4byte 0x28, 0x28, 0x28, 0x28, 0x0, 0xf4240   @   1M

gDefaultHighScoresDebug:: @ 0x080795B0

	.4byte 0x19, 0x26, 0x26, 0x26, 0x0, 0x138990 @ 1280400
	.4byte 0x18, 0x26, 0x26, 0x26, 0x0, 0x9c500  @  640256
	.4byte 0x17, 0x26, 0x26, 0x26, 0x0, 0x4e657  @  321111
	.4byte 0x16, 0x26, 0x26, 0x26, 0x0, 0x271c8  @  160200
	.4byte 0x15, 0x26, 0x26, 0x26, 0x0, 0x14439  @   83001
	.4byte 0x14, 0x26, 0x26, 0x26, 0x0, 0x9d12   @   40210
	.4byte 0x13, 0x26, 0x26, 0x26, 0x0, 0x4f6a   @   20330
	.4byte 0x12, 0x26, 0x26, 0x26, 0x0, 0x3e8    @    1000

	.4byte 0x11, 0x26, 0x26, 0x26, 0x4e4, 0x34ad53b @ 125255235899
	.4byte 0x10, 0x26, 0x26, 0x26, 0x336, 0x26a109c @  82240505500
	.4byte 0xf,  0x26, 0x26, 0x26, 0x271, 0x9BF33E  @  62510220350
	.4byte 0xe,  0x26, 0x26, 0x26, 0x208, 0x22cf284 @  52036500100
	.4byte 0xd,  0x26, 0x26, 0x26, 0x191, 0x9959d0  @  40110050000
	.4byte 0xc,  0x26, 0x26, 0x26, 0x145, 0x131d4f8 @  32520043000
	.4byte 0xb,  0x26, 0x26, 0x26, 0xc8,  0x7d0     @  20000002000
	.4byte 0xa,  0x26, 0x26, 0x26, 0x0,   0xd0020   @       852000

gHighScoreNamePositions:: @ 0x08079730
	.4byte 0x06, 0x03, 0x00
	.4byte 0x06, 0x05, 0x01
	.4byte 0x06, 0x07, 0x01
	.4byte 0x06, 0x09, 0x01
	.4byte 0x06, 0x0B, 0x01
	.4byte 0x06, 0x0D, 0x01
	.4byte 0x06, 0x0F, 0x01
	.4byte 0x06, 0x11, 0x01
	.4byte 0x04, 0x23, 0x00
	.4byte 0x04, 0x25, 0x01
	.4byte 0x04, 0x27, 0x01
	.4byte 0x04, 0x29, 0x01
	.4byte 0x04, 0x2B, 0x01
	.4byte 0x04, 0x2D, 0x01
	.4byte 0x04, 0x2F, 0x01
	.4byte 0x04, 0x31, 0x01

gHighScoreNamePixelPositions:: @ 0x080797F0
	.4byte 0x30, 0x18
	.4byte 0x30, 0x2C
	.4byte 0x30, 0x3C
	.4byte 0x30, 0x4C
	.4byte 0x30, 0x5C
	.4byte 0x30, 0x6C
	.4byte 0x30, 0x7C
	.4byte 0x30, 0x8C
	.4byte 0x30, 0x18
	.4byte 0x30, 0x2C
	.4byte 0x30, 0x3C
	.4byte 0x30, 0x4C
	.4byte 0x30, 0x5C
	.4byte 0x30, 0x6C
	.4byte 0x30, 0x7C
	.4byte 0x30, 0x8C

gHighScoreNameRowTilemapOffsets:: @ 0x08079870
	.4byte 0x02, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11

gTitlescreenStateFuncs:: @ 0x08079890
	.4byte LoadTitlescreenGraphics           @ SUBSTATE_LOAD_GRAPHICS
	.4byte TitleScreen1_WaitForStartButton   @ SUBSTATE_WAIT_FOR_START_BUTTON
	.4byte TitleScreen2_AnimOpenMenu              @ SUBSTATE_2
	.4byte TitleScreen3_8010E00              @ SUBSTATE_3
	.4byte TitleScreen4_MenuInputNoSavedGame @ SUBSTATE_MENU_INPUT_NO_SAVED_GAME
	.4byte TitleScreen5_MenuInputSavedGame   @ SUBSTATE_MENU_INPUT_SAVED_GAME
	.4byte TitleScreen6_AnimCloseMenu        @ SUBSTATE_ANIM_CLOSE_MENU
	.4byte TitleScreen7_8011020              @ SUBSTATE_7
	.4byte TitleScreen8_8011228              @ SUBSTATE_8
	.4byte TitleScreen9_DeleteSaveConfirmation              @ SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION
	.4byte TitleScreen10_ExecMenuSelection   @ SUBSTATE_EXEC_MENU_SELECTION
	.4byte TitleScreen11_80114B4             @ SUBSTATE_11

gIntroCopyright_Tilemap:: @ 0x080798C0
	.incbin "graphics/intro/copyright_tilemap.bin"

gIntroCopyright_Gfx:: @ 0x0807A0C0
    .incbin "graphics/intro/copyright.4bpp"
	.space 0x20

gIntroCopyright_Pal:: @ 0x0807A8E0
    .incbin "graphics/intro/copyright.gbapal"

gBonusFieldSelectBg0_Tilemap:: @ 0x0807AAE0
	.incbin "graphics/field_select/bonus_field_select_bg0_tilemap.bin"

gBonusFieldSelectBg1_Tilemap:: @ 0x0807B2E0
	.incbin "graphics/field_select/bonus_field_select_bg1_tilemap.bin"

gBonusFieldSelectBg2_Tilemap:: @ 0x0807BAE0
	.incbin "graphics/field_select/bonus_field_select_bg2_tilemap.bin"

gBonusFieldSelectStages_Pals:: @ 0x0807C2E0
	.incbin "graphics/field_select/bonus_field_select_stages.gbapal"

gBonusFieldSelectStages_Gfx:: @ 0x0807C4E0
	.incbin "graphics/field_select/bonus_field_select_stages.4bpp"
	.space 0x20

gEReaderText_Tilemap:: @ 0x0807DD00
	.incbin "graphics/ereader/ereader_text_tilemap.bin"

gEReaderOverlay_Tilemap:: @ 0x0807FD00
	.incbin "graphics/ereader/ereader_overlay_tilemap.bin"

gEReaderBackground_Gfx:: @ 0x08080500
	.incbin "graphics/ereader/background.4bpp"
	.space 0x20

gEReaderBackground_Pals:: @ 0x08081D20
	.incbin "graphics/ereader/background.gbapal"

gPokedexBg1_Tilemap:: @ 0x08081F20
	.incbin "graphics/pokedex/bg1_tilemap.bin"

gPokedexBgText_Gfx:: @ 0x08082720
	.incbin "graphics/pokedex/bg_text.4bpp"
	.space 0x20

@ BG map entries, not tiles: 1024 of them, the bulk tile 31 with a run of
@ sequential indices laid into it. pokedex.c copies only the first 0x1C0 to
@ 0x06000280 when it opens a dex entry.
gPokedexInfoWindowTiles:: @ 0x08086B40
	.incbin "graphics/pokedex/info_window_tilemap.bin"

gPokedexBg2_Tilemap:: @ 0x08087340
	.incbin "graphics/pokedex/bg2_tilemap.bin"

gPokedexBg_Gfx:: @ 0x08087B40
	.incbin "graphics/pokedex/bg.4bpp"
	.space 0x20

gPokedexBg3_Tilemap:: @ 0x08088F60
	.incbin "graphics/pokedex/bg3_tilemap.bin"

gPokedexBackground_Pals:: @ 0x08089760
	.incbin "graphics/pokedex/bg.gbapal"

gPokedexSprites_Pals:: @ 0x08089960
	.incbin "graphics/pokedex/sprites.gbapal"

gPokedexSprites_Gfx:: @ 0x08089B60
	.incbin "graphics/pokedex/sprites.4bpp"
	.space 0x20

gPokedexTextGlyphs_Gfx:: @ 0x08090780
	.incbin "graphics/pokedex/text_glyphs.4bpp"

gHighScoreScoreTable_Tilemap:: @ 0x080947A0
	.incbin "graphics/high_score/high_score_table_text_tilemap.bin"

gHighScoreText_Gfx:: @ 0x080957A0
	.incbin "graphics/high_score/text.4bpp"
	.space 0x20

gHighScoreBallWatermark_Tilemap:: @ 0x08099FC0
	.incbin "graphics/high_score/high_score_ball_watermark_tilemap.bin"

gHighScoreBallWatermark_Gfx:: @ 0x0809AFC0
	.incbin "graphics/high_score/ball_watermark_tiles.4bpp"
	.space 0x20

gHighScoreBG_Pals:: @ 0x0809DBE0
	.incbin "graphics/high_score/bg.gbapal"

gHighScoreSprite_Pals:: @ 0x0809DDE0
	.incbin "graphics/high_score/sprites.gbapal"

gHighScoreDialogs_Gfx:: @ 0x0809DFE0
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20

gFieldSelectBG0Tilemap:: @ 0x080A2400
	.incbin "graphics/field_select/field_select_bg_tilemap.bin"

.include "data/graphics/field_select.inc"

gEReaderText_Gfx:: @ 0x080ACC60
	.incbin "graphics/ereader/text.4bpp"
	.space 0x240

gIntroScene1TorchicSprites_Pals:: @ 0x080B3AA0
	.incbin "graphics/intro/scene1torchic/sprites.gbapal"

gIntroScene1Torchic_BG3Tilemap:: @ 0x080B3CA0
	.incbin "graphics/intro/scene1torchic/bg3_text_tilemap.bin"

gIntroScene1TorchicText_Gfx:: @ 0x080B44A0
	.incbin "graphics/intro/scene1torchic/tiles.4bpp"
	.space 0x20

gIntroScene1Torchic_BG0Tilemap:: @ 0x080B9CC0
	.incbin "graphics/intro/scene1torchic/bg0_tilemap.bin"

gIntroScene1Torchic_BG2Tilemap:: @ 0x080BB4C0
	.incbin "graphics/intro/scene1torchic/bg2_dividers_tilemap.bin"

gIntroScene1Torchic_BG1Tilemap:: @ 0x080BC4C0
	.incbin "graphics/intro/scene1torchic/bg1_dividers_tilemap.bin"

gIntroScene1TorchicBall_Gfx:: @ 0x080BD4C0
	.incbin "graphics/intro/scene1torchic/ball.4bpp"
	.space 0x20

gIntroScene1TorchicSprites_Gfx:: @ 0x080C3CE0
	.incbin "graphics/intro/scene1torchic/sprites.4bpp"

gIntroScene2Pikas_Pal:: @ 0x080CBCE0
	.incbin "graphics/intro/scene2pikas/scene.gbapal"

gIntroScene2Pikas_BG3Tilemap:: @ 0x080CBEE0
	.incbin "graphics/intro/scene2pikas/bg3_text_tilemap.bin"

gIntroScene2PikasSprites_Gfx:: @ 0x080CC6E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pichu/pikachu
	.incbin "graphics/intro/scene2pikas/tiles.4bpp"
	.space 0x20

gIntroScene2Pikas_BG0Tiles:: @ 0x080D0700
	.incbin "graphics/intro/scene2pikas/bg0_pichu_tilemap.bin"

gIntroScene2Pikas_BG1Tiles:: @ 0x080D2700
	.incbin "graphics/intro/scene2pikas/bg1_pikachu_tilemap.bin"

gIntroScene3Treecko_Pal:: @ 0x080D4700
	.incbin "graphics/intro/scene3treecko/scene.gbapal"

gIntroScene3Treecko_BG2Tilemap:: @ 0x080D4900
	.incbin "graphics/intro/scene3treecko/bg2_tilemap.bin"

gIntroScene3Treecko_BG3Tilemap:: @ 0x080D5900
	.incbin "graphics/intro/scene3treecko/bg3_text_tilemap.bin"

gIntroScene3TreeckoSprites_Gfx:: @ 0x080D6100
	@ intro pane with treeko, pinball, flipper
	.incbin "graphics/intro/scene3treecko/tiles.4bpp"
	.space 0x20

gIntroScene3Treecko_BG1Tilemap:: @ 0x080DCD20
	.incbin "graphics/intro/scene3treecko/bg1_ball_tilemap.bin"

gIntroScene3Treecko_BG1TilemapA:: @ 0x080DD520
	.incbin "graphics/intro/scene3treecko/bg1_ballandflipper_tilemap.bin"

gIntroScene3Treecko_BG1TilemapB:: @ 0x080DDD20
	.incbin "graphics/intro/scene3treecko/bg1_ballflipperhit_tilemap.bin"

gIntroScene3Treecko_BG0Tilemap:: @ 0x080DE520
	.incbin "graphics/intro/scene3treecko/bg0_treecko_tilemap.bin"

gIntroScene3TreeckoTreecko_Gfx:: @ 0x080DF520
	.incbin "graphics/intro/scene3treecko/treecko.4bpp"
	.space 0x20

gIntroScene4PlussleMinun_Pal:: @ 0x080E1540
	.incbin "graphics/intro/scene4plussleminun/scene.gbapal"

gIntroScene4PlussleMinun_BG3Tilemap:: @ 0x080E1740
	.incbin "graphics/intro/scene4plussleminun/bg3_text_tilemap.bin"

gIntroScene4PlussleMinunSprites_Gfx:: @ 0x080E1F40
	.incbin "graphics/intro/scene4plussleminun/tiles.4bpp"

gIntroScene4PlussleMinun_BG0Tiles:: @ 0x080E5F60
	.incbin "graphics/intro/scene4plussleminun/bg0_minun_tilemap.bin"

gIntroScene4PlussleMinun_BG1Tiles:: @ 0x080E7F60
	.incbin "graphics/intro/scene4plussleminun/bg1_plussle_tilemap.bin"

gIntroScene5Mudkip_Pal:: @ 0x080E9F60
	.incbin "graphics/intro/scene5mudkip/scene.gbapal"

gIntroScene5Mudkip_BG2Tilemap:: @ 0x080EA160
	.incbin "graphics/intro/scene5mudkip/bg2_2sections_tilemap.bin"

gIntroScene5Mudkip_BG1Tiles:: @ 0x080EB160
	.incbin "graphics/intro/scene5mudkip/bg1_1sections_tilemap.bin"

gIntroScene5Mudkip_BG3Tilemap:: @ 0x080EC160
	.incbin "graphics/intro/scene5mudkip/bg3_text_tilemap.bin"

gIntroScene5MudkipText_Gfx:: @ 0x080EC960
	.incbin "graphics/intro/scene5mudkip/text_tiles.4bpp"
	.space 0x20

gIntroScene5Mudkip_BG0Tiles:: @ 0x080F1980
	@ despite the label this is a tilemap: intro.c copies it to 0x6006000, a screenblock
	.incbin "graphics/intro/scene5mudkip/bg0_tilemap.bin"

gIntroScene5MudkipSprites_Gfx:: @ 0x080F2180
	.incbin "graphics/intro/scene5mudkip/sprites.4bpp"
	.space 0x20
	@ Not sprite tiles: 2048 BG map entries, two screenblocks, all palette 1.
	@ The first is a field of tile 0x13F with about 130 tiles of content laid into
	@ it, the second is that same tile all the way through. Nothing reaches it --
	@ IntroScene5Mudkip_32_LoadMudkipBallScene copies only 0x3000 from this label,
	@ and no pointer anywhere lands on 0x080F51A0 -- so it is left over.
	.incbin "graphics/intro/scene5mudkip/unused_bg_tilemap.bin"

gIntroScene6Chinchou_Pal:: @ 0x080F61A0
	.incbin "graphics/intro/scene6chinchou/scene.gbapal"

gIntroScene6Chinchou_BG3Tilemap:: @ 0x080F63A0
	.incbin "graphics/intro/scene6chinchou/bg3_burst_tilemap.bin"

gIntroScene6ChinchouSprites_Gfx:: @ 0x080F6BA0
	.incbin "graphics/intro/scene6chinchou/tiles.4bpp"
	.space 0x20

gIntroScene6Chinchou_BG2Tilemap:: @ 0x080FCFC0
	.incbin "graphics/intro/scene6chinchou/bg2_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG0Tilemap:: @ 0x080FD7C0
	.incbin "graphics/intro/scene6chinchou/bg0_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG1Tiles:: @ 0x080FDFC0
	.incbin "graphics/intro/scene6chinchou/bg1_ball_tilemap.bin"

gIntroScene6ChinchouStars_Gfx:: @ 0x080FFFC0
	.incbin "graphics/intro/scene6chinchou/stars.4bpp"
	.space 0x20

gIntroScene7Parade_Pal:: @ 0x08100FE0
	.incbin "graphics/intro/scene7parade/scene.gbapal"

gIntroScene7Parade_BG3Tilemap:: @ 0x081011E0
	.incbin "graphics/intro/scene7parade/bg3_text_tilemap.bin"

gIntroScene7ParadeSprites_Gfx:: @ 0x081019E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pelipper, makuhita, spoink

	.incbin "graphics/intro/scene7parade/tiles.4bpp"
	.space 0x20

gIntroScene7Parade_BG2Tiles:: @ 0x08106A00
	.incbin "graphics/intro/scene7parade/bg2_makuhita_tilemap.bin"

gIntroScene7Parade_BG0Tiles:: @ 0x08108A00
	.incbin "graphics/intro/scene7parade/bg0_pelipper_tilemap.bin"

gIntroScene7Parade_BG1Tiles:: @ 0x0810AA00
	.incbin "graphics/intro/scene7parade/bg1_spoink_tilemap.bin"

gIntroScene7ParadeWailmer_Gfx:: @ 0x0810CA00
	.incbin "graphics/intro/scene7parade/wailmer.4bpp"
	.space 0x20

gIntroScene8WailmerLaunch_Pal:: @ 0x0810EA20
	.incbin "graphics/intro/scene8wailmerlaunch/scene.gbapal"

gIntroScene8WailmerLaunch_BG2Tilemap:: @ 0x0810EC20
	.incbin "graphics/intro/scene8wailmerlaunch/bg2_explosion_tilemap.bin"

gIntroScene8WailmerLaunchExplosion_Gfx:: @ 0x0810F420
	.incbin "graphics/intro/scene8wailmerlaunch/explosion_tiles.4bpp"
	.space 0x20

gIntroScene8WailmerLaunch_Gfx:: @ 0x08112840
	.incbin "graphics/intro/scene8wailmerlaunch/sprites.4bpp"
	.space 0x20

gIntroScene9BallFlight_Pal:: @ 0x08115860
	.incbin "graphics/intro/scene9ballflight/scene.gbapal"

gIntroScene9BallFlight_BG3Tilemap:: @ 0x08115A60
	.incbin "graphics/intro/scene9ballflight/bg3_clouds_tilemap.bin"

gIntroScene9BallFlightClouds_Gfx:: @ 0x08116260
	.incbin "graphics/intro/scene9ballflight/cloud_tiles.4bpp"
	.space 0x20

gIntroScene9BallFlightall_Gfx:: @ 0x08118680
	.incbin "graphics/intro/scene9ballflight/ball.4bpp"

	.incbin "graphics/intro/wailmer_swallow.4bpp"

	.incbin "graphics/intro/scene9ballflight/ball_tail.4bpp"

.include "data/graphics/titlescreen.inc"

gGravityDeltas_Strong:: @ 0x08137900
	.2byte 1, 1, 1, 0

gGravityDeltas_Medium:: @ 0x08137908
	.2byte 1, 0, 1, 0

gGravityDeltas_Light:: @ 0x08137910
	.2byte 1, 0, 0, 0

gIdlePinballGameStateFuncs:: @ 0x08137918
	.4byte PinballGameIdle0_19048
	.4byte PinballGameIdle1_19190
	.4byte PinballGame_State2_4ABC8 @shared with main game mode
	.4byte PinballGameIdle3_19288

gAreaPortraitIndexes:: @ 0x08137928
	.2byte 0, 1, 2, 3, 4
	.2byte 5, 6, 7, 8, 9
	.2byte 10, 11, 12, 12

gPondBumperRetractFrames:: @ 0x08137944
	.2byte 10, 7,6,5,4,3,2,1,0,1,0,1,0,1,0,1,0,1

gPondBumperTransitionFrames:: @ 0x08137968
	.2byte 0,2,3,4,5,6,7,10,10,10,7,6,5,4,3,2,1,0

gLotadBobOffsets:: @ 0x0813798C
	.2byte 0, 10, 20, 30, 20, 10

gChinchouBumperPalettes:: @ 0x08137998
	.incbin "graphics/stage/main/chinchou_bumper.gbapal"

gLotadBumperPalettes:: @ 0x081379B8
	.incbin "graphics/stage/main/lotad_bumper.gbapal"

gWhiscashPalettes:: @ 0x081379D8
	.incbin "graphics/stage/main/whiscash.gbapal"

gBoardArrowAnimFrames:: @ 0x08137AB8
	.2byte 0,1,2,3,2,1,0,3,0,3

	@ Outside range used by the bumperAnimFrames.
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,0,0,0,0,0,0,0
	.2byte 0,0,0,1,0,0,0,1,0,0
	.2byte 0,1,0,1,0,1,0,1,0,1
	.2byte 0,1,1,1,0,1,1,1,0,1
	.2byte 1,1,1,1,1,1

gFieldPaletteVariants:: @ 0x08137B3C
	.incbin "graphics/stage/main/field_variants.gbapal"

gPelipperFlyAnimTable:: @ 0x08137CBC
	@ frameId, yOffset
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 9, -4
	.byte 10, -2
	.byte 10, -2
	.byte 11, 0
	.byte 11, 0
	.byte 11, 0
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2
	.byte 12, -2

gBumperMosaicValues:: @ 0x08137CD6
	.2byte 0,4,2,0,4,2

gShopSignLoopFrames:: @ 0x08137CE2
	@2 sets of 5
	.2byte 0,1,2,2,1
	.2byte 7,8,9,8,0

gShopSignIntroFrames:: @ 0x08137CF6
	@2 sets of 4
	.2byte 3,0,3,0
	.2byte 6,7,6,7

gShopSignTransitionFrames:: @ 0x08137D06
	@2 sets of 14
	.2byte 6,7,6,4,4,5,5,4,4,5,5,3,0,3
	.2byte 3,0,3,4,4,5,5,4,4,5,5,6,7,6
	.space 2, 0

gDusclopsBossGuardReadyTileOffsets:: @ 0x08137D40
	.2byte 12,13,12,14

gLightningGrabAnimFrameIndices:: @ 0x08137D48
	.2byte 0,1,2,3,4,7,2,1,7,5,6,0

gSphealScoreDigitSpriteIndices:: @ 0x08137D60
	.byte 0,2,2,2,2,2,0,0,0,0
	.byte 2,2,2,2,2,1,1,1,1,1
	.byte 1,1,0,0

gPauseMenuSpriteOffsets:: @ 0x08137D78
	@ Vector16
	.2byte -16, 0
	.2byte 0, 0
	.2byte 8, 0
	.2byte 16, 0
	.2byte 24, 0
	.2byte 0, 12
	.2byte 8, 12
	.2byte 16, 12
	.2byte 24, 12
	.2byte 32, 12
	.2byte 40, 12

gPauseMenuTextAnimFrames:: @ 0x08137DA4
	.2byte 0,0,0,0,0,1,2,3,3,3,3,4,5

gDebugTextStrings:: @ 0x08137DBE
	.ascii " BALL-MV:"
	.byte 0,0,0,0,0
	.ascii " BALL-SPD:"
	.byte 0,0,0,0
	.ascii "  DEBUG1:"
	.byte 0,0,0,0,0

gDebugMenuValueTemplate:: @ 0x08137DE8
	.ascii "(000 000)"
	.byte 0,0,0
	.ascii "(000)    "
	.byte 0,0,0

gDebugMenuCursorText:: @ 0x08137E00
	.ascii "*"
	.byte 0

	.align 2, 0
gPinballGameStateFuncs:: @ 0x08137E04
	.4byte PinballGame_State0_49ED4 @ called once upon loading the field
	.4byte PinballGame_State1_4AAD8 @ called once every frame while playing
	.4byte PinballGame_State2_4ABC8 @ called once on game over (losing all balls)
	.4byte PinballGame_State3_4B20C @ called once after game over?

gBallPalettes:: @ 0x08137E14
	.incbin "graphics/stage/main/pokeball_regular.gbapal"
	.incbin "graphics/stage/main/pokeball_great.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra.gbapal"
	.incbin "graphics/stage/main/pokeball_master.gbapal"
	@ Four more past the four gBallPalettes is indexed with by ballUpgradeType.
	@ These have no art to carry them, and a bare .gbapal is a build product that
	@ make clean removes, so they take the .bin suffix gb_player.gbapal.bin uses.
	.incbin "graphics/stage/main/pokeball_unused.gbapal.bin"

gBallFlashPalette:: @ 0x08137F14
	.incbin "graphics/stage/main/ball_flash.gbapal"

gCaptureBallTilesGfx:: @ 0x08138014
	.incbin "graphics/stage/main/ball_open_to_catch.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx:: @ 0x08138834
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear.4bpp"
	.space 0x20

gKecleonBonusClear_Gfx:: @ 0x0813A854
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear.4bpp"
	.space 0x20

gKyogreBonusClear_Gfx:: @ 0x0813C874
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear.4bpp"
	.space 0x20

gGroudonBonusClear_Gfx:: @ 0x0813E894
	.incbin "graphics/stage/groudon/groudon_bonus_clear.4bpp"
	.space 0x20

gRayquazaBonusClear_Gfx:: @ 0x081408B4
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear.4bpp"
	.space 0x20

@ The capture cutscene, streamed over the tile-704 overlay slot from three
@ places (main_board_center_capture_hole.c, main_board_to_be_split.c and
@ save_and_restore_game.c). t0..101 is the float-up fx drawn by
@ gPokemonFloatOamFramesets; t106..122 and t127..222 are the ball absorb fx,
@ the first frame reaching out for the ball and then the rest, drawn by
@ gMonCatchBallAbsorbPokemonFxSpriteSet. t102..105 and t123..126 are sub-slots
@ the ball graphic streams into, from gCaptureBallTilesGfx -- one per absorb
@ frame, 21 tiles apart, which is the same stride that separates the sprite
@ set's ball-adjacent entries (t123/t127/t129) from t102/t106/t108.
@ Unlike the other sheets here the copy is 0x20 short of the label, and that
@ last tile is not blank, so it stays in the sheet rather than becoming .space.
gCaptureScreenTilesGfx:: @ 0x081428D4
	.incbin "graphics/stage/main/capture_screen.4bpp"

.include "data/graphics/mon_hatch_sprites_pals.inc"

@ Attract-mode demos. Each Config is 4800 struct ReplayInputFrame (3 bytes of
@ button bits per game frame); each GameState is one struct PinballGame snapshot
@ the demo starts from. game_idle.c pairs Config<N> with GameState<N>.
@ Note the labels run 0, 2, 3, 1 in ROM order.
gIdleBoardConfig0:: @ 0x081450F4
	.incbin "data/idle_board/replay_input_0.bin"

gIdleBoardConfig2:: @ 0x08148934
	.incbin "data/idle_board/replay_input_2.bin"

gIdleBoardConfig3:: @ 0x0814C174
	.incbin "data/idle_board/replay_input_3.bin"

gIdleBoardConfig1:: @ 0x0814F9B4
	.incbin "data/idle_board/replay_input_1.bin"

gIdleBoardGameState0:: @ 0x081531F4
	.incbin "data/idle_board/game_state_0.bin"

gIdleBoardGameState2:: @ 0x08154618
	.incbin "data/idle_board/game_state_2.bin"

gIdleBoardGameState3:: @ 0x08155A3C
	.incbin "data/idle_board/game_state_3.bin"

gIdleBoardGameState1:: @ 0x08156E60
	.incbin "data/idle_board/game_state_1.bin"

@ The evolution banner: three sizes of EVOLUTION text plus the lightning that
@ strikes it, streamed over the tile-704 overlay slot with gBoardActionObjPal
@ into OBJ bank 14 beside it (main_board_launcher_and_cutscenes.c). t102..173 is
@ bolt art no bank-14 OAM entry reaches; the last 31 tiles are blank padding.
gBoardActionTilesGfx:: @ 0x08158284
	.incbin "graphics/stage/main/board_action.4bpp"
	.space 0x3E0

gBoardActionObjPal:: @ 0x0815A6A4
	.incbin "graphics/stage/main/board_action_obj.gbapal"

gEvoExAppear_Gfx:: @ 0x0815A8A4
	.incbin "graphics/board_pickups/evo_item_ex.4bpp";

gEvoItemPalettes:: @ 0x0815C4C4
	.incbin "graphics/board_pickups/icon1_xp.gbapal";
	.incbin "graphics/board_pickups/icon2_leaf.gbapal";
	.incbin "graphics/board_pickups/icon3_fire.gbapal";
	.incbin "graphics/board_pickups/icon4_link.gbapal";
	.incbin "graphics/board_pickups/icon5_moon.gbapal";
	.incbin "graphics/board_pickups/icon6_water.gbapal";
	.incbin "graphics/board_pickups/icon7_bolt.gbapal";
	.incbin "graphics/board_pickups/icon8_sun.gbapal";
	.incbin "graphics/board_pickups/icon9_heart.gbapal";
	.incbin "graphics/board_pickups/icon10_pokeblock.gbapal";
	@ Six more past the ten icons, all the same near-flat grey.
	.incbin "graphics/board_pickups/evo_item_unused.gbapal.bin"
	@.incbin "baserom.gba", 0x15C4C4, 0x200

gEvoLeafAppear_Gfx:: @ 0x0815C6C4
	.incbin "graphics/board_pickups/evo_item_leaf.4bpp";

gEvoFireAppear_Gfx:: @ 0x0815E2E4
	.incbin "graphics/board_pickups/evo_item_fire.4bpp";

gEvoHeartAppear_Gfx:: @ 0x0815FF04
	.incbin "graphics/board_pickups/evo_item_heart.4bpp";

gEvoLinkAppear_Gfx:: @ 0x08161B24
	.incbin "graphics/board_pickups/evo_item_link.4bpp";

gEvoMoonAppear_Gfx:: @ 0x08163744
	.incbin "graphics/board_pickups/evo_item_moon.4bpp";

gEvoWaterAppear_Gfx:: @ 0x08165364
	.incbin "graphics/board_pickups/evo_item_water.4bpp";

gEvoBoxAppear_Gfx:: @ 0x08166F84
	.incbin "graphics/board_pickups/evo_item_box.4bpp";

gEvoSunAppear_Gfx:: @ 0x08168BA4
	.incbin "graphics/board_pickups/evo_item_sun.4bpp";

gEvoBoltAppear_Gfx:: @ 0x0816A7C4
	.incbin "graphics/board_pickups/evo_item_bolt.4bpp";

gFlipperCollisionData:: @ 0x0816C3E4
@ Flipper data has 13 sets of 96*96 u16 data (2 unused at the end)
	.incbin "data/board_data/collision/flipper_collision_all_96x96.bin"

gDebugAsciiFont:: @ 0x081A6BE4
@ 8x8 font, one tile per character, ASCII 0x20-0x5F in order. Slot 0x5C draws a
@ yen sign instead of a backslash, the usual Japanese font convention. Only
@ colour indices 1 and 2 are used. Nothing in the ROM references it.
	.incbin "graphics/debug_ascii_font.4bpp"
	.space 0x7800   @ 960 unused tiles, all zero

	.include "data/graphics/mon_catch_sprites_pals.inc"
@	.incbin "baserom.gba", 0x1AEBE4, 0xA80
	.incbin "graphics/debug_ascii_font_extra.4bpp"

gKyogreWaterAnimPaletteFrames:: @ 0x081B0DE4
	.incbin "graphics/stage/kyogre/water_anim_frames.gbapal"

@ 40 framesets of 6 OAM entries, three halfwords each, indexed [frame][i*3+n]
@ by the capture animation. Listed as raw attributes rather than
@ packed_sprite_oam macros because nothing has confirmed the field split for
@ this table yet.
gPokeballCaptureOamFrames:: @ 0x081B0FE4
	@ frame 0
	.2byte 0x0000, 0x4000, 0x12C0
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x0000, 0x4000, 0x12C0
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	@ frame 1
	.2byte 0x0000, 0x4000, 0x12C0
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x0000, 0x4000, 0x12C0
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	@ frame 2
	.2byte 0x0000, 0x4000, 0x12C0
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F0, 0x81F0, 0x12CC
	.2byte 0x4000, 0x41F0, 0x12D4
	@ frame 3
	.2byte 0x00F0, 0x4010, 0x12D8
	.2byte 0x4000, 0x0010, 0x12DC
	.2byte 0x400F, 0xB1FF, 0x12CC
	.2byte 0x4007, 0x71FF, 0x12D4
	.2byte 0x000F, 0x71EF, 0x12D8
	.2byte 0x4007, 0x31EF, 0x12DC
	@ frame 4
	.2byte 0x40F0, 0x81F0, 0x12CC
	.2byte 0x4000, 0x41F0, 0x12D4
	.2byte 0x00F0, 0x4010, 0x12D8
	.2byte 0x4000, 0x0010, 0x12DC
	.2byte 0x400F, 0xB1FF, 0x12CC
	.2byte 0x4007, 0x71FF, 0x12D4
	@ frame 5
	.2byte 0x000F, 0x71EF, 0x12D8
	.2byte 0x4007, 0x31EF, 0x12DC
	.2byte 0x40F0, 0x81F0, 0x12DE
	.2byte 0x00F0, 0x4010, 0x12E6
	.2byte 0x4000, 0x41F0, 0x12EA
	.2byte 0x4000, 0x0010, 0x12EE
	@ frame 6
	.2byte 0x400F, 0xB1FF, 0x12DE
	.2byte 0x000F, 0x71EF, 0x12E6
	.2byte 0x4007, 0x71FF, 0x12EA
	.2byte 0x4007, 0x31EF, 0x12EE
	.2byte 0x40F0, 0x81F0, 0x12DE
	.2byte 0x00F0, 0x4010, 0x12E6
	@ frame 7
	.2byte 0x4000, 0x41F0, 0x12EA
	.2byte 0x4000, 0x0010, 0x12EE
	.2byte 0x400F, 0xB1FF, 0x12DE
	.2byte 0x000F, 0x71EF, 0x12E6
	.2byte 0x4007, 0x71FF, 0x12EA
	.2byte 0x4007, 0x31EF, 0x12EE
	@ frame 8
	.2byte 0x40F0, 0x81F0, 0x12F0
	.2byte 0x00F0, 0x4010, 0x12F8
	.2byte 0x4000, 0x41F0, 0x12FC
	.2byte 0x4000, 0x0010, 0x1300
	.2byte 0x400F, 0xB1FF, 0x12F0
	.2byte 0x000F, 0x71EF, 0x12F8
	@ frame 9
	.2byte 0x4007, 0x71FF, 0x12FC
	.2byte 0x4007, 0x31EF, 0x1300
	.2byte 0x40F0, 0x81F0, 0x12F0
	.2byte 0x00F0, 0x4010, 0x12F8
	.2byte 0x4000, 0x41F0, 0x12FC
	.2byte 0x4000, 0x0010, 0x1300
	@ frame 10
	.2byte 0x400F, 0xB1FF, 0x12F0
	.2byte 0x000F, 0x71EF, 0x12F8
	.2byte 0x4007, 0x71FF, 0x12FC
	.2byte 0x4007, 0x31EF, 0x1300
	.2byte 0x40F0, 0x81F5, 0x1302
	.2byte 0x4000, 0x41F5, 0x130A
	@ frame 11
	.2byte 0x80F8, 0x0015, 0x130E
	.2byte 0x400F, 0xB1FA, 0x1302
	.2byte 0x4007, 0x71FA, 0x130A
	.2byte 0x8007, 0x31F2, 0x130E
	.2byte 0x40F0, 0x81F5, 0x1302
	.2byte 0x4000, 0x41F5, 0x130A
	@ frame 12
	.2byte 0x80F8, 0x0015, 0x130E
	.2byte 0x400F, 0xB1FA, 0x1302
	.2byte 0x4007, 0x71FA, 0x130A
	.2byte 0x8007, 0x31F2, 0x130E
	.2byte 0x8007, 0x31F2, 0x130E
	.2byte 0x8007, 0x31F2, 0x130E
	@ frame 13
	.2byte 0x8007, 0x31F2, 0x130E
	.2byte 0x8007, 0x31F2, 0x130E
	.2byte 0x40F8, 0x81F6, 0x1310
	.2byte 0x80F8, 0x0016, 0x1318
	.2byte 0x4007, 0xB1F9, 0x1310
	.2byte 0x8007, 0x31F1, 0x1318
	@ frame 14
	.2byte 0x40F8, 0x81F6, 0x1310
	.2byte 0x80F8, 0x0016, 0x1318
	.2byte 0x4007, 0xB1F9, 0x1310
	.2byte 0x8007, 0x31F1, 0x1318
	.2byte 0x40F8, 0x81F6, 0x1310
	.2byte 0x80F8, 0x0016, 0x1318
	@ frame 15
	.2byte 0x4007, 0xB1F9, 0x1310
	.2byte 0x8007, 0x31F1, 0x1318
	.2byte 0x40F8, 0x81F6, 0x1310
	.2byte 0x80F8, 0x0016, 0x1318
	.2byte 0x4007, 0xB1F9, 0x1310
	.2byte 0x8007, 0x31F1, 0x1318
	@ frame 16
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	@ frame 17
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	@ frame 18
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x40F8, 0x81F8, 0x12C4
	.2byte 0x4007, 0xB1F7, 0x12C4
	.2byte 0x00FE, 0x4000, 0x1726
	.2byte 0x80FE, 0x0010, 0x172A
	@ frame 19
	.2byte 0x400E, 0x0000, 0x172C
	.2byte 0x8009, 0x81EE, 0x172E
	.2byte 0x8009, 0x01FE, 0x1736
	.2byte 0x8021, 0x01FD, 0x1738
	.2byte 0x0029, 0x01F5, 0x173A
	.2byte 0x00FE, 0x4000, 0x1726
	@ frame 20
	.2byte 0x80FE, 0x0010, 0x172A
	.2byte 0x400E, 0x0000, 0x172C
	.2byte 0x8009, 0x81EE, 0x172E
	.2byte 0x8009, 0x01FE, 0x1736
	.2byte 0x8021, 0x01FD, 0x1738
	.2byte 0x0029, 0x01F5, 0x173A
	@ frame 21
	.2byte 0x0029, 0x01F5, 0x173A
	.2byte 0x0029, 0x01F5, 0x173A
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x801A, 0x81F3, 0x1743
	@ frame 22
	.2byte 0x800A, 0x01FB, 0x174B
	.2byte 0x001E, 0x8003, 0x174D
	.2byte 0x403E, 0x000F, 0x175D
	.2byte 0x8006, 0x0003, 0x175F
	.2byte 0x0016, 0x0003, 0x1761
	.2byte 0x00FC, 0x41FF, 0x173B
	@ frame 23
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x801A, 0x81F3, 0x1743
	.2byte 0x800A, 0x01FB, 0x174B
	.2byte 0x001E, 0x8003, 0x174D
	.2byte 0x403E, 0x000F, 0x175D
	@ frame 24
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x0027, 0x81EF, 0x1762
	.2byte 0x4017, 0x81F7, 0x1772
	.2byte 0x000F, 0x0007, 0x177A
	@ frame 25
	.2byte 0x0007, 0x41F8, 0x177B
	.2byte 0x0037, 0x001F, 0x177F
	.2byte 0x8027, 0x800F, 0x1780
	.2byte 0x8017, 0x0017, 0x1788
	.2byte 0x4047, 0x41F7, 0x178A
	.2byte 0x0047, 0x0017, 0x178E
	@ frame 26
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0026, 0x9006, 0x1762
	.2byte 0x4016, 0x91FE, 0x1772
	@ frame 27
	.2byte 0x0036, 0x11EE, 0x177F
	.2byte 0x8026, 0x91F6, 0x1780
	.2byte 0x8016, 0x11F6, 0x1788
	.2byte 0x4046, 0x51FE, 0x178A
	.2byte 0x0046, 0x11F6, 0x178E
	.2byte 0x4006, 0x01FE, 0x178F
	@ frame 28
	.2byte 0x400E, 0x41F6, 0x1791
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x80FC, 0x000F, 0x173F
	@ frame 29
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x8018, 0x800A, 0x1796
	.2byte 0x0038, 0x000A, 0x179E
	.2byte 0x8020, 0xB1FB, 0x1796
	.2byte 0x0018, 0x3003, 0x179E
	@ frame 30
	.2byte 0x0026, 0x9006, 0x1762
	.2byte 0x4016, 0x91FE, 0x1772
	.2byte 0x0036, 0x11EE, 0x177F
	.2byte 0x8026, 0x91F6, 0x1780
	.2byte 0x8016, 0x11F6, 0x1788
	.2byte 0x4046, 0x51FE, 0x178A
	@ frame 31
	.2byte 0x0046, 0x11F6, 0x178E
	.2byte 0x4006, 0x01FE, 0x178F
	.2byte 0x400E, 0x41F6, 0x1791
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x80FC, 0x000F, 0x173F
	@ frame 32
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x8021, 0xA003, 0x1796
	.2byte 0x0019, 0x2003, 0x179E
	.2byte 0x0027, 0x81EF, 0x1762
	@ frame 33
	.2byte 0x4017, 0x81F7, 0x1772
	.2byte 0x000F, 0x0007, 0x177A
	.2byte 0x0007, 0x41F8, 0x177B
	.2byte 0x0037, 0x001F, 0x177F
	.2byte 0x8027, 0x800F, 0x1780
	.2byte 0x8017, 0x0017, 0x1788
	@ frame 34
	.2byte 0x4047, 0x41F7, 0x178A
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x0047, 0x0017, 0x178E
	.2byte 0x4006, 0x01FE, 0x178F
	.2byte 0x400E, 0x41F6, 0x1791
	@ frame 35
	.2byte 0x00FC, 0x41FF, 0x173B
	.2byte 0x400C, 0x0007, 0x1741
	.2byte 0x80FC, 0x000F, 0x173F
	.2byte 0x4026, 0x0005, 0x175D
	.2byte 0x4016, 0x0001, 0x1756
	.2byte 0x0016, 0x0011, 0x1758
	@ frame 36
	.2byte 0x401E, 0x0001, 0x175A
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x001E, 0x0011, 0x175C
	@ frame 37
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x001E, 0x0011, 0x175C
	.2byte 0x00FB, 0x4002, 0x1726
	.2byte 0x80FB, 0x0012, 0x172A
	.2byte 0x400B, 0x0002, 0x172C
	.2byte 0x00FB, 0x4002, 0x1726
	@ frame 38
	.2byte 0x80FB, 0x0012, 0x172A
	.2byte 0x400B, 0x0002, 0x172C
	.2byte 0x00FB, 0x4002, 0x1726
	.2byte 0x80FB, 0x0012, 0x172A
	.2byte 0x400B, 0x0002, 0x172C
	.2byte 0x00FB, 0x4002, 0x1726
	@ frame 39
	.2byte 0x80FB, 0x0012, 0x172A
	.2byte 0x400B, 0x0002, 0x172C
	.2byte 0x00FB, 0x4002, 0x1726
	.2byte 0x80FB, 0x0012, 0x172A
	.2byte 0x400B, 0x0002, 0x172C
	.2byte 0x400B, 0x0002, 0x172C

gRubyBoardPaletteSet1:: @ 0x081B1584
    .incbin "graphics/stage/ruby/ruby_board_palset_1.gbapal"

gSapphireBoardPaletteSet1:: @ 0x081B1784
    .incbin "graphics/stage/sapphire/sapphire_board_palset_1.gbapal"

gDusclopsBoardPaletteSet1:: @ 0x081B1984
    .incbin "graphics/stage/dusclops/dusclops_board_palset_1.gbapal"

gKecleonBoardPaletteSet1:: @ 0x081B1B84
    .incbin "graphics/stage/kecleon/kecleon_board_palset_1.gbapal"

gKyogreBoardPaletteSet1:: @ 0x081B1D84
    .incbin "graphics/stage/kyogre/kyogre_board_palset_1.gbapal"

gGroudonBoardPaletteSet1:: @ 0x081B1F84
    .incbin "graphics/stage/groudon/groudon_board_palset_1.gbapal"

gRayquazaBoardPaletteSet1:: @ 0x081B2184
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_1.gbapal"

gSphealBoardPaletteSet1:: @ 0x081B2384
    .incbin "graphics/stage/spheal/spheal_board_palset_1.gbapal"

gRubyBoardPaletteSet2:: @ 0x081B2584
    .incbin "graphics/stage/ruby/ruby_board_palset_2.gbapal"

gSapphireBoardPaletteSet2:: @ 0x081B2784
    .incbin "graphics/stage/sapphire/sapphire_board_palset_2.gbapal"

gDusclopsBoardPaletteSet2:: @ 0x081B2984
    .incbin "graphics/stage/dusclops/dusclops_board_palset_2.gbapal"

gKecleonBoardPaletteSet2:: @ 0x081B2B84
    .incbin "graphics/stage/kecleon/kecleon_board_palset_2.gbapal"

gKyogreBoardPaletteSet2:: @ 0x081B2D84
    .incbin "graphics/stage/kyogre/kyogre_board_palset_2.gbapal"

gGroudonBoardPaletteSet2:: @ 0x081B2F84
    .incbin "graphics/stage/groudon/groudon_board_palset_2.gbapal"

gRayquazaBoardPaletteSet2:: @ 0x081B3184
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_2.gbapal"

gSphealBoardPaletteSet2:: @ 0x081B3384
    .incbin "graphics/stage/spheal/spheal_board_palset_2.gbapal"

gRubyBoardPaletteSet0:: @ 0x081B3584
    .incbin "graphics/stage/ruby/ruby_board_palset_0.gbapal"

gBonusStageObjPal:: @ 0x081B36A4
	.incbin "graphics/stage/main/bonus_stage_obj.gbapal"

gSapphireBoardPaletteSet0:: @ 0x081B3784
    .incbin "graphics/stage/sapphire/sapphire_board_palset_0.gbapal"

gDusclopsBoardPaletteSet0:: @ 0x081B3984
	.incbin "graphics/stage/dusclops/dusclops_board_palset_0.gbapal"

gKecleonBoardPaletteSet0:: @ 0x081B3B84
    .incbin "graphics/stage/kecleon/kecleon_board_palset_0.gbapal"

gKyogreBoardPaletteSet0:: @ 0x081B3D84
    .incbin "graphics/stage/kyogre/kyogre_board_palset_0.gbapal"

gGroudonBoardPaletteSet0:: @ 0x081B3F84
    .incbin "graphics/stage/groudon/groudon_board_palset_0.gbapal"

gRayquazaBoardPaletteSet0:: @ 0x081B4184
    .incbin "graphics/stage/rayquaza/rayquaza_board_palset_0.gbapal"

gSphealBoardPaletteSet0:: @ 0x081B4384
    .incbin "graphics/stage/spheal/spheal_board_palset_0.gbapal"

gEvoNameDisplay_Pals:: @ 0x081B4584
	.incbin "graphics/stage/main/evo_name_display.gbapal"

gShopNameDisplay_Pals:: @ 0x081B45A4
	.incbin "graphics/stage/main/shop_name_display.gbapal"
	.space 0x1C0

@ Evolution mode counterpart of the shop mode background below: 4 frames
@ cycled through by gShopEvoBGAnimFrames (data/rom_2.s), and BG0 tilemaps
@ rather than tile graphics for the same reason. Each frame is a full
@ 32x64 map (0x1000 bytes) copied to VRAM + 0x2000; only the first 49
@ rows (0xC40) are copied, and the rest is 0x01FF filler in all 4 frames.
@ Uses tiles found in lower part of gSapphireBoardCompressedTiles1 and gRubyBoardCompressedTiles1 
gEvoModeBG0_0_Tilemap:: @ 0x081B4784
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap.bin"

gEvoModeBG0_1_Tilemap:: @ 0x081B5784
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap.bin"

gEvoModeBG0_2_Tilemap:: @ 0x081B6784
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap.bin"

gEvoModeBG0_3_Tilemap:: @ 0x081B7784
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap.bin"

gShopEvoUI_Pals:: @ 0x081B8784
	.incbin "graphics/stage/main/shop_evo_ui.gbapal"

@ 4 animation frames of the shop mode background, cycled through by
@ gShopEvoBGAnimFrames (data/rom_2.s). Despite the _Gfx name these are
@ BG0 tilemaps, not tile graphics: BG0 is BGCNT_TXT256x512 with
@ BGCNT_SCREENBASE(4), so each frame is a full 32x64 map (0x1000 bytes)
@ copied to BG_VRAM + 0x2000. Only the first 49 rows (0xC40) are copied;
@ the remaining rows are 0x01FF filler and are identical in all 4 frames.
@ Uses tiles found in  lower part of gSapphireBoardCompressedTiles1 and gRubyBoardCompressedTiles1
gShopModeBG0_0_Tilemap:: @ 0x081B8984
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap.bin"

gShopModeBG0_1_Tilemap:: @ 0x081B9984
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap.bin"

gShopModeBG0_2_Tilemap:: @ 0x081BA984
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap.bin"

gShopModeBG0_3_Tilemap:: @ 0x081BB984
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap.bin"

@ 9 palettes of 16 colors, one per shop sign color cycle step
gSapphireShopSignPalettes:: @ 0x081BC984
	.incbin "graphics/stage/sapphire/shop_sign.gbapal"

gRubyTravelPaint_Gfx:: @ 0x081BCAA4
	.incbin "graphics/stage/ruby/travel_paint.4bpp"
	.space 0x120

gRubyPainterPalette:: @ 0x081BE2C4
	.incbin "graphics/stage/ruby/painter.gbapal"

gSapphireTravelPaint_Gfx:: @ 0x081BE4C4
	.incbin "graphics/stage/sapphire/travel_paint.4bpp"
	.space 0x120

gSapphirePainterPalette:: @ 0x081BFCE4
	.incbin "graphics/stage/sapphire/painter.gbapal"

gRubyBoardPalette:: @ 0x081BFEE4
	.incbin "graphics/stage/ruby/ruby_board.gbapal"

gDefaultTimerPalette:: @ 0x081C0064
	.incbin "graphics/stage/main/default_timer.gbapal"

gLocationPalettes:: @ 0x081C00E4
	.incbin "graphics/area_portraits/loc00_ruby_forest.gbapal"
	.incbin "graphics/area_portraits/loc01_sapphire_forest.gbapal"
	.incbin "graphics/area_portraits/loc02_ruby_plains.gbapal"
	.incbin "graphics/area_portraits/loc03_sapphire_plains.gbapal"
	.incbin "graphics/area_portraits/loc04_ruby_harbor.gbapal"
	.incbin "graphics/area_portraits/loc05_sapphire_beach.gbapal"
	.incbin "graphics/area_portraits/loc06_ruby_cave.gbapal"
	.incbin "graphics/area_portraits/loc07_sapphire_cave.gbapal"
	.incbin "graphics/area_portraits/loc08_ruby_safari_zone.gbapal"
	.incbin "graphics/area_portraits/loc09_ruby_volcano.gbapal"
	.incbin "graphics/area_portraits/loc10_sapphire_lake.gbapal"
	.incbin "graphics/area_portraits/loc11_sapphire_desert.gbapal"
	.incbin "graphics/area_portraits/loc12_ruins.gbapal"

	@ 3 unused palettes: one real, two all zero
	.incbin "graphics/area_portraits/loc_unused.gbapal.bin"

gPortraitAnimPalettes:: @ 0x081C02E4
	.incbin "graphics/slot_options/slot_options_1.gbapal"
	.incbin "graphics/slot_options/slot_options_3.gbapal"
	.incbin "graphics/slot_options/slot_options_5.gbapal"
	.incbin "graphics/slot_options/slot_options_7.gbapal"
	.incbin "graphics/slot_options/slot_options_9.gbapal"
	.incbin "graphics/slot_options/slot_options_11.gbapal"
	.incbin "graphics/slot_options/slot_options_13.gbapal"
	.incbin "graphics/slot_options/slot_options_15.gbapal"
	.incbin "graphics/slot_options/slot_options_17.gbapal"
	.incbin "graphics/slot_options/slot_options_19.gbapal"
	.incbin "graphics/slot_options/slot_options_21.gbapal"
	.incbin "graphics/slot_options/slot_options_23.gbapal"
	.incbin "graphics/slot_options/slot_options_25.gbapal"
	.incbin "graphics/slot_options/slot_options_27.gbapal"
	.incbin "graphics/slot_options/slot_options_29.gbapal"
	.incbin "graphics/slot_options/slot_options_31.gbapal"
	.incbin "graphics/slot_options/slot_options_33.gbapal"
	.incbin "graphics/slot_options/slot_options_35.gbapal"
	.incbin "graphics/slot_options/slot_options_37.gbapal"
	.incbin "graphics/slot_options/slot_options_39.gbapal"
	.incbin "graphics/slot_options/slot_options_41.gbapal"
	.incbin "graphics/slot_options/slot_options_43.gbapal"
	.incbin "graphics/slot_options/slot_options_45.gbapal"
	.incbin "graphics/slot_options/slot_options_47.gbapal"
	.incbin "graphics/slot_options/slot_options_49.gbapal"
	.incbin "graphics/slot_options/slot_options_51.gbapal"
	.incbin "graphics/slot_options/slot_options_53.gbapal"
	.incbin "graphics/slot_options/slot_options_55.gbapal"
	.incbin "graphics/slot_options/slot_options_57.gbapal"
	.incbin "graphics/slot_options/slot_options_59.gbapal"
	.incbin "graphics/slot_options/slot_options_61.gbapal"
	.incbin "graphics/slot_options/slot_options_63.gbapal"
	.incbin "graphics/slot_options/slot_options_65.gbapal"
	.incbin "graphics/slot_options/slot_options_67.gbapal"
	.incbin "graphics/slot_options/slot_options_69.gbapal"
	.incbin "graphics/slot_options/slot_options_71.gbapal"
	.incbin "graphics/slot_options/slot_options_73.gbapal"
	.incbin "graphics/slot_options/slot_options_75.gbapal"
	.incbin "graphics/slot_options/slot_options_77.gbapal"
	.incbin "graphics/slot_options/slot_options_79.gbapal"
	.incbin "graphics/slot_options/slot_options_81.gbapal"
	.incbin "graphics/slot_options/slot_options_83.gbapal"
	.incbin "graphics/slot_options/slot_options_85.gbapal"
	.incbin "graphics/slot_options/slot_options_87.gbapal"
	.incbin "graphics/slot_options/slot_options_89.gbapal"
	.incbin "graphics/slot_options/slot_options_91.gbapal"
	.incbin "graphics/slot_options/slot_options_93.gbapal"
	.incbin "graphics/slot_options/slot_options_95.gbapal"

.include "data/board_data/ruby_board.inc"

.include "data/board_data/sapphire_board.inc"

.include "data/board_data/dusclops_board.inc"

.include "data/board_data/kecleon_board.inc"

.include "data/board_data/kyogre_board.inc"

.include "data/board_data/groudon_board.inc"

.include "data/board_data/rayquaza_board.inc"

.include "data/board_data/spheal_board.inc"

@ Not a uniform frame bank: this is a packed atlas of variable-sized
@ sprites. The whole 0x2400 is uploaded to OBJ VRAM in one go, and
@ UpdateKickbackLogic then writes raw OAM entries straight out of
@ gCatchOverlayOamData (data/rom_2.s), so every animation frame picks its
@ own sizes and tile numbers. Those entries give 27 sprites packed back
@ to back with no alignment, in sizes from 8x8 to 32x32; the last 13
@ tiles are never referenced. pika_saver_coverage_shape.json describes
@ that packing for gbagfx. The trailing 0x20 is a blank tile.
gPikaSaverFullCoverageGfx:: @ 0x08395A4C
	.incbin "graphics/stage/main/pika_saver_full_coverage.4bpp"
	.space 0x20

gPikaSaverPartialCoverageGfx:: @ 0x08397E6C
	.incbin "graphics/stage/main/pika_saver_partial_coverage.4bpp"
	.space 0x20

@ Not graphics: a 48x48 collision map, one byte per position, indexed
@ [y * 48 + x] by CheckCatchTargetCollision (all_board_process6_collision.c)
@ against the ball's offset from the Jirachi centre. Bit 7 is the solid flag and
@ the low seven bits are the surface angle the collision answers with.
gCatchTargetCollisionBitmap:: @ 0x0839A28C
	.incbin "data/board_data/collision/catch_target_collision_48x48_typeless.bin"

.include "data/graphics/mon_portraits_pals.inc"

@ The puff the caught mon appears out of, over the tile-704 overlay slot, with
@ gCatchMonAppearFx_Pal going to OBJ bank 14 in the copy right below.
@ gCatchMonRevealOamFramesets draws it: a 16x16 spark, then six puff frames of a
@ 32x32 with a 32x8 under it and an 8x32 beside it. Five of those frames add an
@ 8x8 corner and fill a 5x5 block exactly; the first is missing that corner, so
@ it takes a shape with one spacer. t153..159 are unreferenced.
gCatchMonAppearFx_Gfx:: @ 0x0839C78C
	.incbin "graphics/stage/main/catch_mon_appear_fx.4bpp"
	.space 0x20

gCatchMonAppearFx_Pal:: @ 0x0839DBAC
	.incbin "graphics/stage/main/catch_mon_appear_fx.gbapal"

@ The sequential catch-tile break: 13 frames drawn as 6 sprites each by
@ gCatchTile_SequentialBreakSpritesheetOam, streamed over the tile-704 overlay
@ slot with gCatchTile_RevealPalette in OBJ bank 14. The segments follow that
@ table's piece boundaries; t68..102 is debris no OAM entry in the tree reaches,
@ and the sheet's last 80 tiles are blank padding.
gCatchTile_RevealTilesGfx:: @ 0x0839DDAC
	.incbin "graphics/stage/main/catch_tile_reveal.4bpp"
	.space 0xA00

gCatchTile_RevealPalette:: @ 0x083A05CC
	.incbin "graphics/stage/main/catch_tile_reveal.gbapal"

@ 8 frames of the lightning strike, drawn by gCatchTile_RevealOamFramesets over
@ the tile-704 overlay slot, with gCatchTile_BurstStart_Pal to OBJ bank 14 in the
@ copy beside it. Six of the frames have their pieces on one sub-tile phase and
@ consume the slice in order, so they get shapes; frame 4 has a piece 4px off and
@ takes an approximate one.
@ Frame 6 is the exception and stays a strip: its first two pieces both claim
@ t207 -- a 16x16 at t204 and a 16x32 at t207 -- so the frame's tiles are not a
@ single run and no shape can lay them out without reading one of them twice.
@ t219 is unused, and t240..255 are unreferenced.
gCatchTile_BurstStart_Gfx:: @ 0x083A07CC
	.incbin "graphics/stage/main/catch_tile_burst_start.4bpp"
	.space 0x20

gCatchTile_BurstStart_Pal:: @ 0x083A27EC
	.incbin "graphics/stage/main/catch_tile_burst_start.gbapal"

@ 16 sprites of 16x16, a uniform 2x2 grid with nothing irregular in it.
@ gCatchTile_BurstRevealOamFramesets0 draws six of them at a time into a 3x2
@ block of cells, so the sheet is a bank of quarters the framesets pick from
@ rather than a run of whole frames. Only t0..35 are ever named; t36..63 are
@ unreferenced but still inside the copy. Palette from gCatchTile_BurstStage2_Pal
@ into OBJ bank 14, in the copy right after.
gCatchTile_BurstStage2_Gfx:: @ 0x083A29EC
	.incbin "graphics/stage/main/catch_tile_burst_stage2.4bpp"
	.space 0x20

gCatchTile_BurstStage2_Pal:: @ 0x083A320C
	.incbin "graphics/stage/main/catch_tile_burst_stage2.gbapal"

@ 4 frames of the catch tile collapsing, streamed over the tile-704 overlay slot
@ by the burst particles (main_board_catch_tile_particles.c). Each frame is a
@ single 64x64 sprite from gCatchTileParticleOamAttributes, palette bank 14, so
@ the sheet is 8 tiles wide with no OAM packing. The trailing 0x20 is blank.
gCatchTile_BurstStage3_Gfx:: @ 0x083A340C
	.incbin "graphics/stage/main/catch_tile_burst_stage3.4bpp"
	.space 0x20

gCatchTile_BurstStage3_Pal:: @ 0x083A542C
	.incbin "graphics/stage/main/catch_tile_burst_stage3.gbapal"

@ 9 frames of the catch tile burst, streamed over the tile-704 overlay slot and
@ drawn by gCatchTile_BurstRevealOamFramesets1. Unlike the burst start sheet the
@ frames tile cleanly: every group is contiguous and none of them overlap.
@ Frames 0, 1 and 2 have all their pieces on multiples of 8 so they take
@ oam-shapes; 4 and 5 are plain 6x4 blocks; the rest put a piece at an odd offset
@ (frame 3 at x=9, frame 6 at y=-5) and stay strips. t158..191 are unreferenced.
gCatchTile_BurstStage4_Gfx:: @ 0x083A562C
	.incbin "graphics/stage/main/catch_tile_burst_stage4.4bpp"
	.space 0x20

gCatchTile_BurstStage4_Pal:: @ 0x083A6E4C
	.incbin "graphics/stage/main/catch_tile_burst_stage4.gbapal"

@ Egg mode, over the tile-704 overlay slot, with gAerodactlyFlight_Pal going to OBJ
@ bank 14 in the copy above. gEggFloatOamFramesets draws three frames, each a
@ 32x32 with a 16x8 under it and a 16x32 and 8x32 beside it. Only the first has
@ every piece on one sub-tile phase, so it takes a shape; the other two put one
@ piece a single pixel off and stay strips.
@ t88..127 are blank but still inside the copy, so they are .space rather than a
@ sheet of empty tiles. t128 is past the copy and is not blank.
gAerodactlyFlight_Gfx:: @ 0x083A704C
	.incbin "graphics/stage/main/aerodactyl_flight.4bpp"
	.space 0x500
	.incbin "graphics/stage/main/aerodactyl_flight_cap.4bpp"

gAerodactlyFlight_Pal:: @ 0x083A806C
	.incbin "graphics/stage/main/aerodactyl_flight.gbapal"

gCaptureModePalette:: @ 0x083A808C
	.incbin "graphics/stage/main/capture_mode.gbapal"

@ BG map entries rather than tiles, so these go in as .bin like the other
@ tilemaps. all_board_setup.c copies A to 0x06006800 and B to 0x06006C00 on every
@ board, so the two sit end to end and make one 48-row strip: A is the top 16
@ rows, B the 32 below it.
gBoardHudTilemapB:: @ 0x083A826C
	.incbin "graphics/stage/main/board_hud_b_tilemap.bin"
	.space 0x20

gShopPalette:: @ 0x083A8A8C
	.incbin "graphics/stage/main/shop.gbapal"

gTravelPortraitPalette:: @ 0x083A8AAC
	.incbin "graphics/stage/main/travel_portrait.gbapal"

gBoardHudTilemapA:: @ 0x083A8ACC
	.incbin "graphics/stage/main/board_hud_a_tilemap.bin"
	.space 0x20

gPortraitAnimFrameGraphics:: @ 0x083A8EEC
	.incbin "graphics/slot_options/slot_options_1.4bpp"
	.incbin "graphics/slot_options/slot_options_2.4bpp"
	.incbin "graphics/slot_options/slot_options_3.4bpp"
	.incbin "graphics/slot_options/slot_options_4.4bpp"
	.incbin "graphics/slot_options/slot_options_5.4bpp"
	.incbin "graphics/slot_options/slot_options_6.4bpp"
	.incbin "graphics/slot_options/slot_options_7.4bpp"
	.incbin "graphics/slot_options/slot_options_8.4bpp"
	.incbin "graphics/slot_options/slot_options_9.4bpp"
	.incbin "graphics/slot_options/slot_options_10.4bpp"
	.incbin "graphics/slot_options/slot_options_11.4bpp"
	.incbin "graphics/slot_options/slot_options_12.4bpp"
	.incbin "graphics/slot_options/slot_options_13.4bpp"
	.incbin "graphics/slot_options/slot_options_14.4bpp"
	.incbin "graphics/slot_options/slot_options_15.4bpp"
	.incbin "graphics/slot_options/slot_options_16.4bpp"
	.incbin "graphics/slot_options/slot_options_17.4bpp"
	.incbin "graphics/slot_options/slot_options_18.4bpp"
	.incbin "graphics/slot_options/slot_options_19.4bpp"
	.incbin "graphics/slot_options/slot_options_20.4bpp"
	.incbin "graphics/slot_options/slot_options_21.4bpp"
	.incbin "graphics/slot_options/slot_options_22.4bpp"
	.incbin "graphics/slot_options/slot_options_23.4bpp"
	.incbin "graphics/slot_options/slot_options_24.4bpp"
	.incbin "graphics/slot_options/slot_options_25.4bpp"
	.incbin "graphics/slot_options/slot_options_26.4bpp"
	.incbin "graphics/slot_options/slot_options_27.4bpp"
	.incbin "graphics/slot_options/slot_options_28.4bpp"
	.incbin "graphics/slot_options/slot_options_29.4bpp"
	.incbin "graphics/slot_options/slot_options_30.4bpp"
	.incbin "graphics/slot_options/slot_options_31.4bpp"
	.incbin "graphics/slot_options/slot_options_32.4bpp"
	.incbin "graphics/slot_options/slot_options_33.4bpp"
	.incbin "graphics/slot_options/slot_options_34.4bpp"
	.incbin "graphics/slot_options/slot_options_35.4bpp"
	.incbin "graphics/slot_options/slot_options_36.4bpp"
	.incbin "graphics/slot_options/slot_options_37.4bpp"
	.incbin "graphics/slot_options/slot_options_38.4bpp"
	.incbin "graphics/slot_options/slot_options_39.4bpp"
	.incbin "graphics/slot_options/slot_options_40.4bpp"
	.incbin "graphics/slot_options/slot_options_41.4bpp"
	.incbin "graphics/slot_options/slot_options_42.4bpp"
	.incbin "graphics/slot_options/slot_options_43.4bpp"
	.incbin "graphics/slot_options/slot_options_44.4bpp"
	.incbin "graphics/slot_options/slot_options_45.4bpp"
	.incbin "graphics/slot_options/slot_options_46.4bpp"
	.incbin "graphics/slot_options/slot_options_47.4bpp"
	.incbin "graphics/slot_options/slot_options_48.4bpp"
	.incbin "graphics/slot_options/slot_options_49.4bpp"
	.incbin "graphics/slot_options/slot_options_50.4bpp"
	.incbin "graphics/slot_options/slot_options_51.4bpp"
	.incbin "graphics/slot_options/slot_options_52.4bpp"
	.incbin "graphics/slot_options/slot_options_53.4bpp"
	.incbin "graphics/slot_options/slot_options_54.4bpp"
	.incbin "graphics/slot_options/slot_options_55.4bpp"
	.incbin "graphics/slot_options/slot_options_56.4bpp"
	.incbin "graphics/slot_options/slot_options_57.4bpp"
	.incbin "graphics/slot_options/slot_options_58.4bpp"
	.incbin "graphics/slot_options/slot_options_59.4bpp"
	.incbin "graphics/slot_options/slot_options_60.4bpp"
	.incbin "graphics/slot_options/slot_options_61.4bpp"
	.incbin "graphics/slot_options/slot_options_62.4bpp"
	.incbin "graphics/slot_options/slot_options_63.4bpp"
	.incbin "graphics/slot_options/slot_options_64.4bpp"
	.incbin "graphics/slot_options/slot_options_65.4bpp"
	.incbin "graphics/slot_options/slot_options_66.4bpp"
	.incbin "graphics/slot_options/slot_options_67.4bpp"
	.incbin "graphics/slot_options/slot_options_68.4bpp"
	.incbin "graphics/slot_options/slot_options_69.4bpp"
	.incbin "graphics/slot_options/slot_options_70.4bpp"
	.incbin "graphics/slot_options/slot_options_71.4bpp"
	.incbin "graphics/slot_options/slot_options_72.4bpp"
	.incbin "graphics/slot_options/slot_options_73.4bpp"
	.incbin "graphics/slot_options/slot_options_74.4bpp"
	.incbin "graphics/slot_options/slot_options_75.4bpp"
	.incbin "graphics/slot_options/slot_options_76.4bpp"
	.incbin "graphics/slot_options/slot_options_77.4bpp"
	.incbin "graphics/slot_options/slot_options_78.4bpp"
	.incbin "graphics/slot_options/slot_options_79.4bpp"
	.incbin "graphics/slot_options/slot_options_80.4bpp"
	.incbin "graphics/slot_options/slot_options_81.4bpp"
	.incbin "graphics/slot_options/slot_options_82.4bpp"
	.incbin "graphics/slot_options/slot_options_83.4bpp"
	.incbin "graphics/slot_options/slot_options_84.4bpp"
	.incbin "graphics/slot_options/slot_options_85.4bpp"
	.incbin "graphics/slot_options/slot_options_86.4bpp"
	.incbin "graphics/slot_options/slot_options_87.4bpp"
	.incbin "graphics/slot_options/slot_options_88.4bpp"
	.incbin "graphics/slot_options/slot_options_89.4bpp"
	.incbin "graphics/slot_options/slot_options_90.4bpp"
	.incbin "graphics/slot_options/slot_options_91.4bpp"
	.incbin "graphics/slot_options/slot_options_92.4bpp"
	.incbin "graphics/slot_options/slot_options_93.4bpp"
	.incbin "graphics/slot_options/slot_options_94.4bpp"
	.incbin "graphics/slot_options/slot_options_95.4bpp"
	.incbin "graphics/slot_options/slot_options_96.4bpp"
	.incbin "graphics/slot_options/slot_options_97.4bpp"

gBallRotationTileGraphics:: @ 0x083BB16C
	.incbin "graphics/stage/main/pokeball_regular.4bpp"
	.incbin "graphics/stage/main/pokeball_great.4bpp"
	.incbin "graphics/stage/main/pokeball_ultra.4bpp"
	.incbin "graphics/stage/main/pokeball_master.4bpp"

@ Not a shadow: the group all_board_process7.c streams these into is
@ FIELD_SG_BALL_UPGRADE_FX and gBallUpgradeFxSpriteSet draws them, a single 32x32
@ over tile 247 in palette bank 1 -- the ball's own bank, which is why the frames
@ come out as the upgrade sparkle rather than anything dark. 6 frames of 0x200,
@ 4 tiles wide, no OAM packing. gBallUpgradeFx_TileIndicies and gBallUpgradeFxTimer in
@ ruby_board_indicators.c pick the frame and carry the same wrong name.
gBallUpgradeFx_Gfx:: @ 0x083BD36C
	.incbin "graphics/stage/main/ball_upgrade_fx_frames.4bpp"

@ The two ball spawn glows, streamed a frame at a time over tile 57 by
@ all_board_process7.c -- the gBonusBoardBallRespawnFxSpriteSet slot, one 32x32
@ in palette bank 1, so both sheets are 4 tiles wide with no OAM packing.
@ Type 2 is 9 frames of 0x200, type 1 is 11.
gBallSpawnGlowTiles_Type2:: @ 0x083BDF6C
	.incbin "graphics/stage/main/ball_spawn_glow_type2.4bpp"

gBallSpawnGlowTiles_Type1:: @ 0x083BF16C
	.incbin "graphics/stage/main/ball_spawn_glow_type1.4bpp"

@ 7 frames of the launcher Spoink, 0x1C0 each, streamed over tile 263 by
@ main_board_launcher_and_cutscenes.c. gSpoinkLauncherSpriteSet draws a 16x32
@ and an 8x32 beside it, then a 16x8 below -- 14 tiles. The body pair sits on
@ the tile grid but the lower strip is offset 4px, half a tile, so the shape
@ places it at the nearest column. That is the one approximation in the layout;
@ everything else is exact and the sheet still rebuilds byte for byte. Ruby's
@ intro sheet splits the same sprite at that seam instead, as spoink and
@ spoink_tail, which is not an option here with 7 frames to interleave.
gSpoinkEntity_Gfx:: @ 0x083C076C
	.incbin "graphics/stage/main/spoink_launcher.4bpp"

@ 9 frames of 0xC0 over tile 289, the surfacing splash. 6 tiles a frame, 2 wide.
gKyogreSplashSpriteFrames:: @ 0x083C13AC
	.incbin "graphics/stage/kyogre/surfacing_fx_frames.4bpp"

@ 9 frames of the freeze trap, 0x3C0 each, streamed over tile 295 by
@ KyogreProcess3 (kyogre_process3.c). Each frame is 4 OAM pieces -- a 32x32
@ over a 16x32 with a 32x8 and a 16x8 beneath, gKyogreFreezeTrapSpriteSet,
@ palette bank 12 -- so a frame tiles into a 6x5 block. Frame 0 is the same
@ 30 tiles the intro sheet already carries as iceberg + ice_bits.
gKyogreWhirlpoolSpriteFrames:: @ 0x083C1A6C
	.incbin "graphics/stage/kyogre/freeze_trap_frames.4bpp"

@ Not decorations: these are the ruby board's Chikorita, 8 frames of 0x300
@ streamed over tile 313 by ruby_trigger_targets.c and drawn through
@ gRubyChikoritaSpriteSet in palette bank 3. Each frame is a 32x32 over a 32x16,
@ so it tiles into a clean 4x6 block with nothing left over.
gRubyChikoritaEntity:: @ 0x083C3C2C
	.incbin "graphics/stage/ruby/chikorita_frames.4bpp"

@ 4 frames of 0x80 over tile 528, one 16x16 each from
@ gRubyChikoritaProjectileSpriteSet in palette bank 3.
gChikoritaProjectileTiles:: @ 0x083C542C
	.incbin "graphics/stage/ruby/chikorita_projectile.4bpp"

@ 4 frames of 0x100 over tile 532, drawn as a 16x32 pair by
@ gRubyChikoritaProjectileCollisionFxSpriteSet in palette bank 3.
gChikoritaExplosionTiles:: @ 0x083C562C
	.incbin "graphics/stage/ruby/chikorita_projectile_fx.4bpp"

@ The three storm clouds of the Rayquaza intro, drawn by gRaquazaIntroCloud0/1/2
@ SpriteSet over the tile-704 overlay slot in OBJ bank 2. The copy in
@ rayquaza_process3.c asks for 0x2800 but the sheet is only 0x2640, so the last
@ 14 tiles it lands in VRAM come from gChinchouBumper_Gfx below.
gRayquazaSkyBackgroundGfx:: @ 0x083C5A2C
	.incbin "graphics/stage/rayquaza/sky_background.4bpp"

@ Not flashing tiles: this is the Chinchou pond bumper, the else branch of the
@ pond bumper draw in ruby_process3_entities_2.c. 11 frames of 0x100, streamed
@ into tile 372 + 8i for the three bumpers, each a single 16x32 from
@ gRubyBumpersSpriteSet drawn twice side by side. Palette bank 9, loaded from
@ gChinchouBumperPalettes in the copy right after. The Lotad bumper below is the
@ if branch of the same loop and matches it frame for frame.
gChinchouBumper_Gfx:: @ 0x083C806C
	.incbin "graphics/stage/main/chinchou_bumper.4bpp"

.include "data/graphics/mon_hatch_sprites.inc"

gPickupIcon1_Gfx:: @ 0x083EB84C
	.incbin "graphics/board_pickups/icon1_xp.4bpp"
gPickupIcon2_Gfx:: @ 0x083ED64C
	.incbin "graphics/board_pickups/icon2_leaf.4bpp"
gPickupIcon3_Gfx:: @ 0x083EF44C
	.incbin "graphics/board_pickups/icon3_fire.4bpp"
gPickupIcon9_Gfx:: @ 0x083F124C
	.incbin "graphics/board_pickups/icon9_heart.4bpp"
gPickupIcon4_Gfx:: @ 0x083F304C
	.incbin "graphics/board_pickups/icon4_link.4bpp"
gPickupIcon5_Gfx:: @ 0x083F4E4C
	.incbin "graphics/board_pickups/icon5_moon.4bpp"
gPickupIcon6_Gfx:: @ 0x083F6C4C
	.incbin "graphics/board_pickups/icon6_water.4bpp"
gPickupIcon10_Gfx:: @ 0x083F8A4C
	.incbin "graphics/board_pickups/icon10_pokeblock.4bpp"
gPickupIcon8_Gfx:: @ 0x083FA84C
	.incbin "graphics/board_pickups/icon8_sun.4bpp"
gPickupIcon7_Gfx:: @ 0x083FC64C
	.incbin "graphics/board_pickups/icon7_bolt.4bpp"

@ 6 flipper angles of 0x200, copied into tile 0 for the left flipper and tile 16
@ for the right (all_board_process4.c). Each is a single 32x32 from
@ gBonusBoardLeft/RightFlipperSpriteSet in palette bank 0, so the sheet is 4
@ tiles wide with no OAM packing. These are the same two slots the shared
@ bonus-board block occupies at t0..31 on every board's intro sheet.
gFlipperTileGraphics:: @ 0x083FE44C
	.incbin "graphics/stage/main/flipper_frames.4bpp"

@ 52 letters of 0x40 -- A-Z then a-z -- each an 8x16 pair of tiles. The name
@ display copies one letter at a time into tile 704 + 2i (main_board_to_be_split.c)
@ and gLegendaryCatchNameBannerSpriteSet draws the ten slots in palette bank 1.
@ Laid out 26 across so the two cases read as two rows. gSpaceTileGfx below is
@ the blank the same loop uses for a space.
gAlphabetTilesGfx:: @ 0x083FF04C
	.incbin "graphics/stage/main/alphabet.4bpp"

gSpaceTileGfx:: @ 0x083FFD4C
	.space 0x40

gSapphireBoardWailmer_Gfx:: @ 0x083FFD8C
	.incbin "graphics/stage/sapphire/wailmer.4bpp";

	.include "data/graphics/mon_catch_sprites.inc"

gRubyStageGulpin_Gfx:: @ 0x08447A8C
	.incbin "graphics/stage/ruby/gulpin.4bpp"

gMainStageBonusTrap_Gfx:: @ 0x0844838C
	.incbin "graphics/stage/main/bonus_trap.4bpp"

gLotadBumper_Gfx:: @ 0x0844928C
	.incbin "graphics/stage/main/lotad_bumper.4bpp"

gRubyStageCyndaquil_Gfx:: @ 0x08449D8C
	.incbin "graphics/stage/ruby/cyndaquil.4bpp"

gJirachiFx_Gfx:: @ 0x0844AA0C
	.incbin "graphics/stage/main/gunk_0844AA0C.4bpp"

gSapphireStageBasket_Gfx:: @ 0x0844F20C
	.incbin "graphics/stage/sapphire/seedot_basket.4bpp"

gKecleonStageKecleon_Gfx:: @ 0x0844F98C
	.incbin "graphics/stage/kecleon/kecleon.4bpp"

gKecleonStageKecleonFx_Gfx:: @ 0x0845588C
	.incbin "graphics/stage/kecleon/kecleon_fx.4bpp"

gOneUpBannerSprite_Gfx:: @ 0x08455E8C
	.incbin "graphics/stage/misc/gunk_08455E8C.4bpp"

gLifeCountDigit_Gfx:: @ 0x0845648C
	.incbin "graphics/stage/misc/gunk_0845648C.4bpp"

gPondBumper_Gfx:: @ 0x0845690C
	.incbin "graphics/stage/misc/gunk_0845690C.4bpp"

gRubyStageNuzleaf_Gfx:: @ 0x0845710C
	.incbin "graphics/stage/ruby/nuzleaf.4bpp"

@ 4 chunks of 0x100 streamed over tile 517 and the three slots after it, the
@ hatch machine's light spark (gSapphireHatchMachineLightSparkFx0SpriteSet).
gSplashEffectTileGfx:: @ 0x0845A08C
	.incbin "graphics/stage/sapphire/hatch_machine_spark_fx.4bpp"

gRubyIntroSprites_Gfx:: @ 0x0845A48C
	.incbin "graphics/stage/ruby/intro_sprite.4bpp"

gSapphireIntroSprites_Gfx:: @ 0x0845F9EC
	.incbin "graphics/stage/sapphire/intro_sprite.4bpp"

gDusclopsIntroSprite_Gfx:: @ 0x08464F4C
	.incbin "graphics/stage/dusclops/intro_sprite.4bpp";

gKecleonIntroSprite_Gfx:: @ 0x084675EC
	.incbin "graphics/stage/kecleon/intro_sprite.4bpp";

gKyogreIntroSprite_Gfx:: @ 0x0846A40C
	.incbin "graphics/stage/kyogre/intro_sprite.4bpp"

gGroudonIntroSprite_Gfx:: @ 0x0846D2AC
	.incbin "graphics/stage/groudon/intro_sprite.4bpp"

gRayquazaIntroSprite_Gfx:: @ 0x08472A6C
	.incbin "graphics/stage/rayquaza/intro_sprite.4bpp"

gSphealIntroSprites_Gfx:: @ 0x084779EC
	.incbin "graphics/stage/spheal/intro_sprite.4bpp"

gSapphireBumperLeft_Gfx:: @ 0x0847A40C
@ 15 frames of the Sapphire Minun bumper, stride 0x300. The sprite is
@ a 32x32 over a 32x16 (24 tiles, gSapphireMinunSpriteSet, palette bank 10 from the OBJ
@ palette sets); only 0x280 of each frame is DMAd, the rest is padding.
	.incbin "graphics/stage/sapphire/bumper_minun.4bpp"

gSapphireBumperLeftHit_Gfx:: @ 0x0847D10C
@ 7 frames of the Sapphire Minun hit bumper, stride 0x200. The sprite is
@ one 32x32 (16 tiles, gSapphireMinunElectricityFxSpriteSet, palette bank 10 from the OBJ
@ palette sets); only 0x180 of each frame is DMAd, the rest is padding.
	.incbin "graphics/stage/sapphire/bumper_minun_fx.4bpp"

@ 10 frames of the ramp Makuhita, 0x300 each, streamed over tile 428 by
@ ruby_ramp.c. gRubyMakuhitaSpriteSet draws each frame as a 32x32 with an 8x32
@ beside it and a 32x8 under it, offset 8px right -- a 5x5 block with the
@ bottom-left tile unused, so it needs an oam-shape rather than -mwidth.
gRubyMakuhitaGfx:: @ 0x0847DF0C
	.incbin "graphics/stage/ruby/makuhita.4bpp"

@ 2 frames of 0x100 streamed over tile 337 for each of the Linoone side
@ bumpers (ruby_trigger_targets.c), gRubyLinooneLeftSpriteSet, palette bank 4.
gSideBumperGfx:: @ 0x0847FD0C
	.incbin "graphics/stage/ruby/linoone_side_bumper.4bpp"

@ 5 overlays of 0x300 each, drawn as 2 sprites (32x32 + 16x32) by
@ gMainShopPortraitOverlaySpriteSet, so each frame is 6x4 tiles.
@ Frames 0-3 are the selection sheen; frame 4 is the "SOLD OUT" banner.
gShopPortraitOverlayGfx:: @ 0x0847FF0C
	.incbin "graphics/stage/main/shop_portrait_overlay.4bpp"

@ 0 through 9, one 8x16 digit per 0x40, copied a digit at a time into the score
@ slots at tile 749 onwards. Laid out 10 across so the sheet reads as the digits.
gDecimalDigitTilesGfx:: @ 0x08480E0C
	.incbin "graphics/stage/main/decimal_digits.4bpp"

@ 10 sign frames of 0x480 each, drawn as 2 sprites (64x32 face at (0,0)
@ plus a 32x8 post at (0,32)) by gSapphireMartSignSpriteSet. That is not a
@ rectangle, so shop_sign_shape.json describes the slicing for gbagfx.
gSapphireShopSignTileGfx:: @ 0x0848108C
	.incbin "graphics/stage/sapphire/shop_sign_tiles.4bpp"

gRubyTravelVolbeat_Gfx:: @ 0x08483D8C
@ 17 frames of Volbeat for the travel cutscene, 0x480 each. A frame is the
@ first 4 pieces of gTravelPainterSpriteSet (32x32, 16x32, 32x16, 16x16 =
@ 36 tiles) DMAd over tile 0x2c0; the last 2 pieces stay from the paint
@ sheet loaded just before. Palette is bank 14, the first 16 colours of
@ the painter palette.
	.incbin "graphics/stage/ruby/travel_volbeat.4bpp"

gSapphireTravelIllumise_Gfx:: @ 0x08488A0C
@ 17 frames of Illumise for the travel cutscene, 0x480 each. A frame is the
@ first 4 pieces of gTravelPainterSpriteSet (32x32, 16x32, 32x16, 16x16 =
@ 36 tiles) DMAd over tile 0x2c0; the last 2 pieces stay from the paint
@ sheet loaded just before. Palette is bank 14, the first 16 colours of
@ the painter palette.
	.incbin "graphics/stage/sapphire/travel_illumise.4bpp"

gLocationPortraitGfx:: @ 0x0848D68C
	.incbin "graphics/area_portraits/loc00_ruby_forest.4bpp"
	.incbin "graphics/area_portraits/loc01_sapphire_forest.4bpp"
	.incbin "graphics/area_portraits/loc02_ruby_plains.4bpp"
	.incbin "graphics/area_portraits/loc03_sapphire_plains.4bpp"
	.incbin "graphics/area_portraits/loc04_ruby_harbor.4bpp"
	.incbin "graphics/area_portraits/loc05_sapphire_beach.4bpp"
	.incbin "graphics/area_portraits/loc06_ruby_cave.4bpp"
	.incbin "graphics/area_portraits/loc07_sapphire_cave.4bpp"
	.incbin "graphics/area_portraits/loc08_ruby_safari_zone.4bpp"
	.incbin "graphics/area_portraits/loc09_ruby_volcano.4bpp"
	.incbin "graphics/area_portraits/loc10_sapphire_lake.4bpp"
	.incbin "graphics/area_portraits/loc11_sapphire_desert.4bpp"
	.incbin "graphics/area_portraits/loc12_ruins.4bpp"

@ The two egg deliveries, over the tile-704 overlay slot, with gCaptureModePalette
@ going to OBJ bank 14 in the copy above (main_board_to_be_split.c).
@ gRubyAerodactylEggDeliverySpriteSet holds t0..30 and gRubyTotodileEggDelivery-
@ SpriteSet t28..34 and t56..77, so the two overlap at t28..30 and no cut
@ separates them -- t0..34 is one segment. The Totodile egg at t72..77 draws in
@ bank 11 while everything around it is bank 14, so it is split out to keep the
@ colours honest. t35..55 and t78..100 are unreferenced, and t101 is past the
@ copy: a solid colour-1 tile.
gCaptureModeTilesGfx:: @ 0x0848FD8C
	.incbin "graphics/stage/main/capture_mode.4bpp"

gHoleIndicatorTileGfx:: @ 0x08490A4C
@ 16 frames of 34 BG tiles (0x440 each), one per row of the sheet. Each frame
@ is DMAd to 0x0600D900, i.e. char base 2 tile 712, inside the static board
@ overlay. The 34 tiles are not one shape: the tilemap scatters them over
@ several hole positions at rows 8-10 and 42-46, in palette banks 2 and 6.
@ Sheet is coloured with Ruby bank 2; Sapphire reuses the same tiles.
	.incbin "graphics/stage/main/hole_indicator.4bpp"

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x08494E4C
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gKyogreBodySprites_First15:: @ 0x0849664C
@ 15 animation frames of 44 OBJ tiles (0x580 each), one per row of the sheet.
@ kyogre_process3.c picks the frame with bossVulnerable and DMAs it to tile 0x7d.
@ gKyogreEntitySpriteSet draws it as 5 pieces plus 5 hFlipped mirrors, palette 15.
@ Boards use 1D OBJ mapping, so a row is the pieces back to back, not the shape.
	.incbin "graphics/stage/kyogre/body_first15.4bpp"

gKyogreBodySprites_After15:: @ 0x0849B8CC
@ The frames used when bossVulnerable is 15 or more: 12 frames of 38 tiles
@ (0x4C0 each), one per row. Max bossVulnerable is 26, and 26 - 15 = 11, the
@ last of these 12.
	.incbin "graphics/stage/kyogre/body_after15.4bpp"

@ Not a background despite the label: this is the Groudon board's OBJ effect
@ art, streamed whole over the tile-704 overlay slot by groudon_process3.c.
@ Three animations share it -- gGroudonProjectileAttackOamData at t0..51,
@ gGroudonProjectileOamData at t52..163 and gGroudonBallGrabOamData at
@ t164..255 -- all in palette bank 12. t50..51 and t240..254 are unreferenced.
gGroudonAttackFx_Gfx:: @ 0x0849F1CC
	.incbin "graphics/stage/groudon/board_fx.4bpp"
	.space 0x20

gGroudonBoardBoulders_Gfx:: @ 0x084A11EC
	.incbin "graphics/stage/groudon/boulders.4bpp";

@ Not orbs: 9 frames of the tornado, 0x280 each, streamed over tile 245 by
@ rayquaza_process3.c and drawn through gRaquazaTornadoSpriteSet in palette
@ bank 12. Each frame is a 32x32 over a 32x8, so it tiles into a clean 4x5 block.
gRayquazaTornadoGfx:: @ 0x084A6EEC
	.incbin "graphics/stage/rayquaza/tornado_frames.4bpp"

@ The wind attack, streamed whole over the tile-704 overlay slot by
@ rayquaza_process3.c when the entity enters its flyby. t0..101 is the flyby
@ Rayquaza itself (gRaquazaEntityFlybyLeft/RightSpriteSet, palette bank 15),
@ t102..207 the three speedline tiers (gRaquazaFlyby*WindSpeedlines0/1/2A/B,
@ bank 12), t208..223 unreferenced. The entity is 18 pieces at offsets that are
@ not multiples of 8 and would overlap if rounded to a tile grid, so no oam-shape
@ can reassemble it -- the segments are plain strips whose widths merely divide
@ their tile counts.
gRayquazaWindBoardGfx:: @ 0x084A856C
	.incbin "graphics/stage/rayquaza/wind_board.4bpp"
	.space 0x20

@ The flying Rayquaza, one 67-tile sprite of 14 pieces
@ (gRaquazaEntityFlyingUp/DownSpriteSet, palette bank 15) copied whole to tile
@ 177. The pieces run the tile slice in order but sit on three different sub-tile
@ phases, so the shape places the odd ones at their nearest column.
gRayquazaSpriteSheet:: @ 0x084AA18C
	.incbin "graphics/stage/rayquaza/entity_flying.4bpp"

gRayquazaBodyVariantTiles:: @ 0x084AA9EC
@ 10 variants of the coiled body, 0x800 each. Every variant is one 64x64 sprite
@ (gRaquazaEntityBouncingSpriteSet, tile 0xb1, palette 15), so at 8 tiles wide
@ each occupies 8 rows and reads as the sprite itself under 1D OBJ mapping.
@ Colours come from the OBJ palette sets (fieldLayout.objPaletteSets), not the
@ board BG palette -- bank 15 there is all black. Palsets 1 and 2 are dimmed.
	.incbin "graphics/stage/rayquaza/body_variants.4bpp"

gSphealNetGfx:: @ 0x084AF9EC
	.incbin "graphics/stage/spheal/spheal_net.4bpp"

gSphealNetFrontGfx:: @ 0x084AFFEC
	.incbin "graphics/stage/spheal/spheal_net_front.4bpp"

gSphealFlyingEnemyVariantSprites:: @ 0x084B046C
	.incbin "graphics/stage/spheal/spheal.4bpp"

gSphealMinionBodySprites:: @ 0x084B47EC
	.incbin "graphics/stage/spheal/sealeo.4bpp"

gSphealResultsScreenGfx:: @ 0x084B77EC
	.incbin "graphics/stage/spheal/spheal_results.4bpp"

gWhiscash_Gfx:: @ 0x084B7FEC
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelipper_Gfx:: @ 0x084BB16C
	.incbin "graphics/stage/sapphire/pelipper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gChargeFillIndicator_Gfx:: @ 0x084C00EC
	.incbin "graphics/stage/main/charge_fill_indicator.4bpp"

@ These three are one contiguous bank of 15 frames of 0x180 (4x3 tiles),
@ indexed as gPikaSaverTilesGfx + pikaSaverTileIndex * 0x180, which runs
@ up to index 9 and so reads past gPikaSaverTilesGfx into the two symbols
@ that follow. Each frame is drawn as SPRITE_SIZE_32x16 over
@ SPRITE_SIZE_32x8 (gPikachuKickbackSpriteSet / gPichuKickbackSpriteSet).
gPikaSaverTilesGfx:: @ 0x084C07EC
	.incbin "graphics/stage/main/pika_saver_tiles.4bpp"

gDxModePikachuObjTiles:: @ 0x084C0C6C
	.incbin "graphics/stage/main/dx_mode_pikachu_obj_tiles.4bpp"

gPikachuSaverTilesGfx:: @ 0x084C156C
	.incbin "graphics/stage/main/pikachu_saver_tiles.4bpp"

gSapphireBumperRight_Gfx:: @ 0x084C1E6C
@ 15 frames of the Sapphire Plusle bumper, stride 0x300. The sprite is
@ a 32x32 over a 32x16 (24 tiles, gSapphirePlusleSpriteSet, palette bank 10 from the OBJ
@ palette sets); only 0x280 of each frame is DMAd, the rest is padding.
	.incbin "graphics/stage/sapphire/bumper_plusle.4bpp"

gSapphireBumperRightHit_Gfx:: @ 0x084C4B6C
@ 7 frames of the Sapphire Plusle hit bumper, stride 0x200. The sprite is
@ one 32x32 (16 tiles, gSapphirePlusleElectricityFxSpriteSet, palette bank 10 from the OBJ
@ palette sets); only 0x180 of each frame is DMAd, the rest is padding.
	.incbin "graphics/stage/sapphire/bumper_plusle_fx.4bpp"

.include "data/graphics/mon_portraits.inc"

@ A narrow "compressed" digit font: 11 tiles stacked one tile wide, holding
@ 0 through 9 plus a trailing glyph. Unrelated to the Plusle hit bumper it was
@ previously filed under; no pointer in the ROM targets this address, so it is
@ reached by offset from whatever indexes the font.
gCompressedNumbers_Gfx:: @ 0x084ECF6C
	.incbin "graphics/stage/sapphire/compressed_numbers.4bpp"

gRubyBoardShopDoor_Gfx:: @ 0x084ED0CC
	.incbin "graphics/stage/ruby/shop_door.4bpp";

gZigzagoonShockWallIndicator_Gfx:: @ 0x084ED6CC
	.incbin "graphics/stage/gunk_084ED6CC.4bpp";

gDusclopsBoardDusclops_Gfx:: @ 0x084EDACC
	.incbin "graphics/stage/dusclops/dusclops.4bpp";

gRubyBoardSharpedo_Gfx:: @ 0x084F5ACC
	.incbin "graphics/stage/ruby/sharpedo.4bpp";

gPokemonNameDisplayGfx:: @ 0x084F61EC
	.incbin "graphics/stage/main/gunk_084F61EC.4bpp";

gRubyBoardShop_Gfx:: @ 0x084F6B0C
	.incbin "graphics/stage/ruby/shop.4bpp";

gAreaRouletteSelectedFx_Gfx:: @ 0x084FA20C
	.incbin "graphics/stage/main/area_roulette_selected_fx.4bpp";

gMainBoardPikaSpinner_Gfx:: @ 0x084FA48C
	.incbin "graphics/stage/main/pika_spinner.4bpp";

gRubyBoardHatchCave_Gfx:: @ 0x084FB68C
	.incbin "graphics/stage/ruby/hatch_cave.4bpp";

gEggFrameTilesGfx:: @ 0x084FD18C
	.incbin "graphics/stage/main/egg.4bpp";

gSapphireBoardSeedot_Gfx:: @ 0x084FDF8C
	.incbin "graphics/stage/sapphire/seedot.4bpp";

gSapphireBoardShopShockWall_Gfx:: @ 0x084FEA0C
	.incbin "graphics/stage/sapphire/shop_shock_wall.4bpp";

gRubyBoardRampPrize_Gfx:: @ 0x084FEF0C
	.incbin "graphics/stage/ruby/ramp_prize.4bpp";

gDusclopsBoardDusclopsBallGrabSwirl_Gfx:: @ 0x084FF30C
	.incbin "graphics/stage/dusclops/dusclops_ball_grab.4bpp";

@ 11 frames of the vortex minion, 0x200 each, streamed into whichever of the two
@ 16-tile slots at t169 and t185 the entity holds (kyogre_process3.c). Each frame
@ is a single 32x32, so the sheet is 4 tiles wide with no OAM packing. The 8
@ tiles after the eleventh frame are past the end of the animation.
gKyogreWhirlpoolMinionSprites:: @ 0x084FF90C
	.incbin "graphics/stage/kyogre/whirlpool_minion_frames.4bpp"

gMainBoardBallSave_Gfx:: @ 0x0850100C
	.incbin "graphics/stage/main/ball_save.4bpp";

gMainBoardBallSaveLatios_Gfx:: @ 0x085028CC
	.incbin "graphics/stage/main/latios.4bpp";

gMainBoardBallSaveLatiosArm_Gfx:: @ 0x085038CC
	.incbin "graphics/stage/main/latios_arm.4bpp";

gMainBoardEndOfBall_Gfx:: @ 0x0850398C
	.incbin "graphics/stage/main/end_of_ball.4bpp";

gBonusSummaryCharTiles:: @ 0x0850558C
	.incbin "graphics/stage/misc/gunk_0850558C.4bpp";

.space 0x40

gMainBoardEvoBanner_Gfx:: @ 0x08505BCC
	.incbin "graphics/stage/main/evo_banner.4bpp";

gMainBoardGameOverText_Gfx:: @ 0x08509F4C
	.incbin "graphics/stage/main/game_over_text.4bpp";

gMainBoardJirachiBanner_Gfx:: @ 0x0850A34C
	.incbin "graphics/stage/main/jirachi_banner.4bpp";

gMainBoardTravel_Gfx:: @ 0x0850E6CC
	.incbin "graphics/stage/main/travel.4bpp";

gPauseMenuText_Gfx:: @ 0x08510CAC
	.incbin "graphics/stage/main/pause_menu_text.4bpp";

gDusclopsBoardDuskull_Gfx:: @ 0x08510E4C
	.incbin "graphics/stage/dusclops/duskull.4bpp";

gSapphireBoardZigzagoon_Gfx:: @ 0x08512C4C
	.incbin "graphics/stage/sapphire/zigzagoon.4bpp";

gBonusStagePal_Lit:: @ 0x08514F4C
	.incbin "graphics/stage/main/bonus_stage_lit.gbapal"

gBonusStagePal_Dark:: @ 0x08514F6C
	.incbin "graphics/stage/main/bonus_stage_dark.gbapal"

gRubyChinchouCatchBurstBanner_Gfx:: @ 0x0851514C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.4bpp"
	.space 0xA0

gRubyChinchouCatchBurstBanner_Pal:: @ 0x0851956C
	.incbin "graphics/stage/ruby/chinchou_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Pal:: @ 0x0851958C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.gbapal"

gSapphireShroomishCatchBurstBanner_Pal:: @ 0x085195AC
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.gbapal"

gRubyLotadCatchBurstBanner_Gfx:: @ 0x0851976C
	.incbin "graphics/stage/ruby/lotad_catch_burst_banner.4bpp"
	.space 0xA0

gSapphireShroomishCatchBurstBanner_Gfx:: @ 0x0851DB8C
	.incbin "graphics/stage/sapphire/shroomish_catch_burst_banner.4bpp"
	.space 0xA0

gBonusClearTextPal_Lit:: @ 0x08521FAC
	.incbin "graphics/stage/main/bonus_clear_text_lit.gbapal"

gBonusClearTextPal_Dark:: @ 0x08521FCC
	.incbin "graphics/stage/main/bonus_clear_text_dark.gbapal"

gMainBoardEvoBanner_Pal:: @ 0x085221AC
    .incbin "graphics/stage/main/evo_banner.gbapal"

gMainCatchModeBanner_Gfx:: @ 0x085223AC
	.incbin "graphics/stage/main/catch_mode_banner.4bpp"
	.space 0xA0

gMainCatchModeBanner_Pal:: @ 0x085267CC
    .incbin "graphics/stage/main/catch_mode_banner.gbapal"

gMainBoardJirachiBanner_Pal:: @ 0x085269CC
    .incbin "graphics/stage/main/jirachi_banner.gbapal"

gMainBoardTravel_Pal:: @ 0x08526BCC
    .incbin "graphics/stage/main/travel.gbapal"

gSapphireBoardZigzagoonFx_Gfx:: @ 0x08526DCC
	.incbin "graphics/stage/sapphire/zigzagoon_fx.4bpp";

@ Unreferenced 854-byte blob, most likely a leftover tilemap: mostly ascending
@ tile ids with runs of repeats. Both ends are pinned by real references (the
@ 0xC00 copies of the gfx above, and the pointer to gOptionsBGMList below), and
@ no pointer anywhere in the ROM lands inside it.
gUnknown_085279CC:: @ 0x085279CC
	.incbin "graphics/stage/unknown_085279CC.bin"

gOptionsBGMList:: @ 0x08527D22
	.2byte MUS_TITLE, MUS_TABLE_SELECT, MUS_EREADER, MUS_OPENING, MUS_HIGH_SCORE
	.2byte MUS_POKEDEX, MUS_SHOP, MUS_SLOTS_PRIZE, MUS_END_OF_BALL, MUS_BONUS_CHANCE, MUS_BONUS_CHANCE_LEGENDARY
	.2byte MUS_TRAVEL_MODE_START, MUS_SUCCESS, MUS_PRIZE_AWARDED, MUS_EGG_MODE, MUS_EGG_MODE_START
	.2byte MUS_TRAVEL_MODE, MUS_HURRY_UP, MUS_EVOLUTION, MUS_FIELD_RUBY, MUS_CATCH_EM_MODE
	.2byte MUS_EVO_MODE, MUS_FIELD_RUBY2, MUS_FIELD_SAPPHIRE, MUS_CATCH_EM_MODE2, MUS_FIELD_SAPPHIRE2
	.2byte MUS_BONUS_FIELD_KECLEON, MUS_BONUS_FIELD_DUSKULL, MUS_BONUS_FIELD_DUSCLOPS, MUS_BONUS_FIELD_SPHEAL, MUS_BONUS_FIELD_GROUDON
	.2byte MUS_BONUS_FIELD_KYOGRE, MUS_BONUS_FIELD_RAYQUAZA, MUS_JIRACHI

gOptionsSEList:: @ 0x08527D66 
    .2byte SE_MENU_SELECT, SE_MENU_CANCEL, SE_MENU_MOVE, SE_MENU_POPUP_OPEN, SE_MENU_POPUP_CLOSE
    .2byte SE_SCORE_ENTRY_A_B_MOVE, SE_SCORE_ENTRY_LETTER_CHANGE, SE_DEX_INFO_FIELD_SELECT_MOVE, SE_FLIPPER_PRESSED, SE_SLINGSHOT_HIT
    .2byte SE_POKEMON_CATCH_HIT, SE_PICHU_IN_POSITION_CHIRP, SE_TRIGGER_BUTTON_HIT, SE_WALL_HIT, SE_TILT_TRIGGERED
    .2byte SE_PIKA_SPINNER_CLACK, SE_PIKA_FULL_CHARGE_1_UP, SE_UNKNOWN_0x7B, SE_KICKBACK_THUNDERWAVE, SE_COIN_COLLECTED
    .2byte SE_CENTER_HOLE_EJECT, SE_ROULETTE_TICK, SE_EVO_SELECTION_MOVE, SE_EVO_SELECTION_CONFIRM, SE_EVO_ITEM_APPEAR
    .2byte SE_EVO_ITEM_FINISH_APPEAR, SE_EVO_ITEM_COLLECTED, SE_BALL_UPGRADE, SE_FAILURE, SE_CATCH_EVO_BANNER
    .2byte SE_CATCH_TILE_REVEAL, SE_CATCH_ALL_REVEAL_LIGHTNING, SE_CATCH_ALL_REVEAL_SHATTER, SE_SHOP_LIST_REVEAL, SE_BONUS_SCORE_TALLIED
    .2byte SE_HATCH_FLOURISH, SE_AREA_ROULETTE_SELECTED, SE_BALL_SAVED, SE_LATI_DELIVERY, SE_SAVER_PLUNGER_DROP
    .2byte SE_TRAVEL_PAINTER_FLIGHT, SE_TRAVEL_PAINTER_PAINTS, SE_EVO_GET_ARROW_EARNED, SE_MON_CATCH_BALL_WOOSH, SE_MON_CATCH_ENERGY_BEAM
    .2byte SE_MON_CATCH_BALL_CLOSE, SE_MON_CATCH_BALL_HIT_GROUND, SE_MON_CATCH_BALL_SHAKE, SE_WARP, SE_BALL_SUMMARY_TEXT_PROGRESS

    .2byte SE_BALL_SUMMARY_PAGE_SWIPE, SE_PAUSE_CURSOR_MOVE, SE_BONUS_PANEL_SLIDE, SE_PAUSING, SE_UNPAUSING
    .2byte SE_CATCH_MON_ENTITY_APPEARS, SE_PIKA_CHARGE_DO, SE_PIKA_CHARGE_RE, SE_PIKA_CHARGE_MI, SE_PIKA_CHARGE_FA
    .2byte SE_PIKA_CHARGE_SO, SE_PIKA_CHARGE_LA, SE_PIKA_CHARGE_TI, SE_PIKA_CHARGE_HIGH_DO, SE_EVO_CUTSCENE_MON_PORTRAIT_CHANGE
    .2byte SE_RUBY_BUMPER_HIT, SE_CYNDAQUIL_EGG_GUARD_HIT, SE_AERODACTYL_EGG_FLIGHT, SE_CYNDAQUIL_BALL_EJECT_AFTER_EGG_ARRIVAL, SE_RUBY_MART_GATE_OPEN
    .2byte SE_SHARPEDO_BALL_EJECT, SE_SHOP_EJECT, SE_MAKUHITA_PUNCH, SE_CHIKORITA_LEAF_BLADE, SE_ZIGZAGOON_EMERGE
    .2byte SE_RUBY_BUMPER_EMERGES, SE_RUBY_BUMPER_LEAVES, SE_RUBY_MART_SIGN_CHANGED, SE_SPOINK_LAUNCHER_CHARGED, SE_SPOINK_LAUNCHER_FIRED
    .2byte SE_SHARPEDO_BITE, SE_NUZLEAF_HIT, SE_NUZLEAF_TEETERING, SE_NUZLEAF_FORMS_BRIDGE, SE_GULPIN_LANDS_OR_LEAVES
    .2byte SE_WHISCASH_EMERGE_SPLASH, SE_WHISCASH_LEAVE_BURBLE, SE_WHISCASH_CATCH_BALL, SE_WHISCASH_SPIT_BALL, SE_WHISCASH_SPLASHDOWN
    .2byte SE_RAMP_PRIZE_COLLECTED, SE_HATCH_MACHINE_SPINNER_TRIGGER, SE_MON_LANDS_ON_HATCH_MACHINE_TOP, SE_HATCH_MACHINE_STAGE_ADVANCE, SE_HATCH_MACHINE_EGG_HATCH
    .2byte SE_HATCH_MACHINE_ELEVATOR, SE_HATCH_MACHINE_ELEVATOR_TOP, SE_PELIPPER_BALL_GRAB, SE_PELIPPER_WING_FLAP, SE_PELIPPER_SWOOSH

    .2byte SE_PELIPPER_BALL_DROP_LANDS, SE_SAPPHIRE_MART_GATE_TRIGGER, SE_SAPPHIRE_MART_GATE_REPLACED, SE_SAPPHIRE_MART_GATE_HIT, SE_SEEDOT_FALLING
    .2byte SE_SEEDOT_LANDS, SE_SEEDOT_LEAVES, SE_ZIGZAGOON_ROULETTE_STOP, SE_DUSKULL_APPEAR, SE_DUSKULL_DEATH_CRY
    .2byte SE_DUSCLOPS_DEPART_INCOMPLETE, SE_DUSCLOPS_MOVE, SE_DUSCLOPS_APPEAR, SE_DUSCLOPS_HIT, SE_DUSCLOPS_BALL_ABSORB
    .2byte SE_DUSCLOPS_BALL_LAUNCH, SE_BONUS_BOARD_BALL_SPAWN, SE_KECLEON_SIDE_LOOK, SE_KECLEON_VANISH, SE_KECLEON_STARTLED
    .2byte SE_KECLEON_RUNNING, SE_KECLEON_KNOCKED_OVER, SE_KECLEON_HIT_DAMAGED, SE_KECLEON_HITS_GROUND_DEFEATED, SE_KECLEON_SEEING_STARS
    .2byte SE_KECLEON_TREE_HIT, SE_KECLEON_SCOPE_FALL, SE_KECLEON_SCOPE_ACTIVATED, SE_KYOGRE_HIT, SE_KYOGRE_BREACH_SURFACE
    .2byte SE_KYOGRE_DIVE, SE_KYOGRE_SPAWN_WHIRLPOOL, SE_KYOGRE_FREEZE_RING, SE_KYOGRE_DEPARTS, SE_KYOGRE_FREEZE_HITS_BALL
    .2byte SE_KYOGRE_FREEZE_CRACK, SE_KYOGRE_FREEZE_ESCAPED, SE_KYOGRE_WHIRLPOOL_GRABS_BALL, SE_GROUDON_HIT, SE_GROUDON_STEP
    .2byte SE_GROUDON_INTRO_LEAP, SE_GROUDON_LANDS, SE_GROUDON_SPITS_FIRE, SE_GROUDON_FIRE_RING, SE_GROUDON_FIRE_GRAB_RESIST
    .2byte SE_GROUDON_FIRE_GRAB, SE_GROUDON_FIREBALL_CONNECTS, SE_GROUDON_BOULDER_LAND, SE_GROUDON_DUSTORM_LIFT, SE_GROUDON_BALL_HIT_FIRE
    
	.2byte SE_RAYQUAZA_HIT, SE_RAYQUAZA_WIND, SE_RAYQUAZA_LIGHTNING_CHARGE, SE_RAYQUAZA_FLYBY, SE_RAYQUAZA_LIGHTNING_TRAP
    .2byte SE_RAYQUAZA_WHIRLWIND_BALL_LAUNCH, SE_RAYQUAZA_WHIRLWIND_BALL_LAND, SE_RAYQUAZA_SONIC_BOOM, SE_RAYQUAZA_STAGE_WIND, SE_SPHEAL_SURFACING
    .2byte SE_SPHEAL_SUBMERGING, SE_SPHEAL_SUBMERGE_AFTER_SCORING, SE_SPHEAL_HIT, SE_SPHEAL_NET_SWOOSH, SE_SPHEAL_CROWD_CHEER
    .2byte SE_SPHEAL_END_WHISTLE, SE_SEALEO_HIT_THUD, SE_SEALEO_NOSE_BOUNCE, SE_SPHEAL_LAND_UNDER_NET, SE_SPHEAL_SURFACE_AT_RAMP
    .2byte SE_JIRACHI_MOVE, SE_JIRACHI_HIT, SE_TOTODILE_LOWERS_ROPE, SE_TOTODILE_SLIDES_DOWN, SE_TOTODILE_PLACES_EGG
    .2byte SE_TOTODILE_CLIMBS_ROPE, SE_WHISCASH_EARTHQUAKE, SE_HIGHEST_SCORE_EARNED, SE_HIGH_SCORE_EARNED, SE_UNKNOWN_0x71
    .2byte SE_PIKACHU_KICKBACK, SE_PICHU_KICKBACK_ENABLED, SE_PICHU_KICKBACK, SE_PIKA_NO_KICKBACK


gDefaultButtonConfigs:: @ 0x08527ED6
	@4 sets of 10
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x09, 0x08;
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x01, 0x0A;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x00, 0x0A, 0x05, 0x00;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x04, 0x0A, 0x06, 0x0A;

gDefaultCustomButtonConfigTileIds:: @ 0x08527EFE
	@ Copied into gCustomButtonConfigTileIds by the options screen; pairs of
	@ (tile id, 10) for the five configurable buttons.
	.byte 1, 10, 0, 10, 5, 10, 4, 10, 6, 10

gOptionsStateFuncs:: @ 0x08527F08
	.4byte Options_LoadGraphics
	.4byte Options_HandleInput
	.4byte Options_State2_51C3C
	.4byte Options_State3_51C60

.include "data/pokedex_entries/species_rs_to_cry_id.inc"

gOptionsText_Tilemap:: @ 0x08528028
	.incbin "graphics/options/text.bin"

gOptionsText_Gfx:: @ 0x08528828
	.incbin "graphics/options/text.4bpp"
	.space 0x20

gOptionsBackground_Tilemap:: @ 0x0852A048
	.incbin "graphics/options/background.bin"

gOptionsBackground_Gfx:: @ 0x0852A848
	.incbin "graphics/options/background.4bpp"
	.space 0x20

gOptionsBackground_Pals:: @ 0x0852B468
	.incbin "graphics/options/background.gbapal"

gGBAButtonIcons_Pals:: @ 0x0852B668
	.incbin "graphics/gba_buttons.gbapal"

gOptionsSprites_Gfx:: @ 0x0852B868
	.incbin "graphics/options/sprites.4bpp"

.align 2
