@ Generated for the European version (BPPP) from data/rom_1.s
.section .rodata
.align 2

#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "gba/io_reg.h"
#include "gba/oam_types.h"
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
	.4byte BonusFieldSelect_Menu
	.4byte BonusFieldSelect_FadeToSelection

gEReaderStateFuncs:: @ 0x0805C75C
	.4byte LoadEReaderGraphics
	.4byte Ereader_ShowInstructions
	.4byte Ereader_AnimateLinkCable
	.4byte Ereader_Communicating
	.4byte Ereader_ShowLinkTimeout
	.4byte Ereader_CloseSuccessfulTransmission
	.4byte Ereader_ShowSuccessPopup
	.4byte Ereader_ShowPrizeText
	.4byte Ereader_FadeScreenToMenu

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















































































































































































































gPokedexEntries:: @ 0x08063910
	.incbin "data/eu/bin/rom_1_08063910.bin"
gLanguageSelectStateFuncs:: @ 0x080EC4CC
	.byte 0x05, 0x96, 0x00, 0x08, 0x85, 0x97, 0x00, 0x08, 0x9D, 0x98, 0x00, 0x08, 0x45, 0x99, 0x00, 0x08
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

	@ 4 'name' blocks followed by 2 score high/low







gDefaultHighScores:: @ 0x080EC64C
	.incbin "data/eu/bin/rom_1_080EC64C.bin"
gHighScoreNamePositions:: @ 0x080EC7CC
	.incbin "data/eu/bin/rom_1_080EC7CC.bin"
gHighScoreNamePixelPositions:: @ 0x080EC88C
	.incbin "data/eu/bin/rom_1_080EC88C.bin"
gHighScoreNameRowTilemapOffsets:: @ 0x08079870
	.4byte 0x02, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11

gTitlescreenStateFuncs:: @ 0x08079890
	.4byte LoadTitlescreenGraphics                @ SUBSTATE_LOAD_GRAPHICS
	.4byte TitleScreen1_WaitForStartButton        @ SUBSTATE_WAIT_FOR_START_BUTTON
	.4byte TitleScreen2_AnimatePressStartSelected @ SUBSTATE_ANIM_PRESS_START_SELECTED
	.4byte TitleScreen3_AnimateMenuSlideIn        @ SUBSTATE_ANIM_MENU_SLIDE_IN
	.4byte TitleScreen4_MenuInputNoSavedGame      @ SUBSTATE_MENU_INPUT_NO_SAVED_GAME
	.4byte TitleScreen5_MenuInputSavedGame        @ SUBSTATE_MENU_INPUT_SAVED_GAME
	.4byte TitleScreen6_AnimCloseMenu             @ SUBSTATE_ANIM_CLOSE_MENU
	.4byte TitleScreen7_ProcessMenuItemSelected_NoSavedGame @ SUBSTATE_MENU_ITEM_SELECTED_NO_SAVED_GAME
	.4byte TitleScreen8_ProcessMenuItemSelected_SavedGame   @ SUBSTATE_MENU_ITEM_SELECTED_SAVED_GAME
	.4byte TitleScreen9_DeleteSaveConfirmation              @ SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION
	.4byte TitleScreen10_ExecMenuSelection        @ SUBSTATE_EXEC_MENU_SELECTION
	.4byte TitleScreen11_FadeToAction             @ SUBSTATE_FADE_TO_MENU_ACTION

gIntroCopyright_Tilemap:: @ 0x080798C0
	.incbin "graphics/intro/copyright_tilemap.bin"

gIntroCopyright_Gfx:: @ 0x0807A0C0
    .incbin "graphics/intro/copyright.4bpp"
	.space 0x20

gIntroCopyright_Pal:: @ 0x0807A8E0
    .incbin "graphics/intro/copyright.gbapal"

gBonusFieldSelectBg0_Tilemap:: @ 0x0807AAE0
	.incbin "graphics/field_select/bonus_field_select_bg0_tilemap.bin"


gBonusFieldSelectBg1_Tilemap_En:: @ 0x080EE37C
	.incbin "data/eu/bin/rom_1_080EE37C.bin"
gBonusFieldSelectBg1_Tilemap_FrDeItEs:: @ 0x080EEB7C
	.incbin "data/eu/bin/rom_1_080EEB7C.bin"
gBonusFieldSelectBg2_Tilemap:: @ 0x0807BAE0
	.incbin "graphics/field_select/bonus_field_select_bg2_tilemap.bin"

gBonusFieldSelectStages_Pals:: @ 0x0807C2E0
	.incbin "graphics/field_select/bonus_field_select_stages.gbapal"

gBonusFieldSelectStages_Gfx:: @ 0x0807C4E0
	.incbin "graphics/field_select/bonus_field_select_stages.4bpp"
	.space 0x20


gEReaderText_Tilemap:: @ 0x080F159C
	.incbin "data/eu/bin/rom_1_080F159C.bin"
gEReaderOverlay_Tilemap:: @ 0x0807FD00
	.incbin "graphics/ereader/ereader_overlay_tilemap.bin"


gEReaderBackground_Gfx:: @ 0x080F3D9C
	.incbin "data/eu/bin/rom_1_080F3D9C.bin"
gEReaderBackgroundText_Gfx_Fr:: @ 0x080F559C
	.incbin "data/eu/bin/rom_1_080F559C.bin"
gEReaderBackgroundText_Gfx_It:: @ 0x080F5D9C
	.incbin "data/eu/bin/rom_1_080F5D9C.bin"
gEReaderBackgroundText_Gfx_De:: @ 0x080F659C
	.incbin "data/eu/bin/rom_1_080F659C.bin"
gEReaderBackgroundText_Gfx_Es:: @ 0x080F6D9C
	.incbin "data/eu/bin/rom_1_080F6D9C.bin"
gEReaderBackground_Pals:: @ 0x08081D20
	.incbin "graphics/ereader/background.gbapal"

gPokedexBg1_Tilemap_En:: @ 0x080F77BC
gPokedexBg1_Tilemap:: @ 0x08081F20
	.incbin "graphics/pokedex/bg1_tilemap.bin"

gPokedexBgText_Gfx_En:: @ 0x080F7FBC
gPokedexBgText_Gfx:: @ 0x08082720
	.incbin "graphics/pokedex/bg_text.4bpp"
	.space 0x20

@ 32x32 u16 tilemap (0x800 bytes) for the pokedex info window that slides
@ in over the dex entry view. Copied to BG1's screenblock 0 tilemap at
@ row 10 (VRAM 0x6000280) by Pokedex_InfoWindowSlideIn (src/pokedex.c).
@ Only the first 7 rows (2*0xE0 bytes) are DMA'd; rows 0-5 hold the
@ window content and the rest is 0x001F filler (tile 31, blank).
@ The window is a 26x6 chunk of tile indices 224..409, i.e. sheet rows
@ 7..12, cols 0..25 of the 32 wide gPokedexBgText_Gfx tileset
@ (graphics/pokedex/bg_text.png), with palette bank 1 (0x1000 attr bit).
@
@ Note: this area of the raw bg_text.png starts blank. The text from the dex
@ entry is drawn to it, in memory, (PrintDexDescription function) before
@ this tilemap definition draws that text to screen from the background tiles.

gPokedexBg1_Tilemap_De:: @ 0x080FC3DC
	.incbin "data/eu/bin/rom_1_080FC3DC.bin"
gPokedexBgText_Gfx_De:: @ 0x080FCBDC
	.incbin "data/eu/bin/rom_1_080FCBDC.bin"
gPokedexBg1_Tilemap_Fr:: @ 0x08100FFC
	.incbin "data/eu/bin/rom_1_08100FFC.bin"
gPokedexBgText_Gfx_Fr:: @ 0x081017FC
	.incbin "data/eu/bin/rom_1_081017FC.bin"
gPokedexBg1_Tilemap_It:: @ 0x08105C1C
	.incbin "data/eu/bin/rom_1_08105C1C.bin"
gPokedexBgText_Gfx_It:: @ 0x0810641C
	.incbin "data/eu/bin/rom_1_0810641C.bin"
gPokedexBg1_Tilemap_Es:: @ 0x0810A83C
	.incbin "data/eu/bin/rom_1_0810A83C.bin"
gPokedexBgText_Gfx_Es:: @ 0x0810B03C
	.incbin "data/eu/bin/rom_1_0810B03C.bin"
gPokedexInfoWindowTilemap:: @ 0x0810F45C
	.incbin "data/eu/bin/rom_1_0810F45C.bin"
gPokedexBg2_Tilemap:: @ 0x08087340
	.incbin "graphics/pokedex/bg2_tilemap.bin"


gPokedexBg_Gfx_En:: @ 0x0811045C
	.incbin "data/eu/bin/rom_1_0811045C.bin"
gPokedexBg_Gfx_FrDeItEs:: @ 0x0811187C
	.incbin "data/eu/bin/rom_1_0811187C.bin"
gPokedexBg3_Tilemap_En:: @ 0x08112C9C
gPokedexBg3_Tilemap:: @ 0x08088F60
	.incbin "graphics/pokedex/bg3_tilemap.bin"

gPokedexBg3_Tilemap_FrDeItEs:: @ 0x0811349C
	.incbin "data/eu/bin/rom_1_0811349C.bin"
gPokedexBackground_Pals:: @ 0x08089760
	.incbin "graphics/pokedex/bg.gbapal"

gPokedexSprites_Pals:: @ 0x08089960
	.incbin "graphics/pokedex/sprites.gbapal"

gPokedexSprites_Gfx_En:: @ 0x0811409C
gPokedexSprites_Gfx:: @ 0x08089B60
	.incbin "graphics/pokedex/sprites.4bpp"
	.space 0x20




gPokedexSprites_Gfx_De:: @ 0x0811ACBC
	.incbin "data/eu/bin/rom_1_0811ACBC.bin"
gPokedexSprites_Gfx_Fr:: @ 0x08121CDC
	.incbin "data/eu/bin/rom_1_08121CDC.bin"
gPokedexSprites_Gfx_It:: @ 0x081290FC
	.incbin "data/eu/bin/rom_1_081290FC.bin"
gPokedexSprites_Gfx_Es:: @ 0x0812FD1C
	.incbin "data/eu/bin/rom_1_0812FD1C.bin"
gPokedexTextGlyphs_Gfx:: @ 0x08136D3C
	.incbin "data/eu/bin/rom_1_08136D3C.bin"
gHighScoreScoreTable_Tilemap_En:: @ 0x0813BD5C
	.incbin "data/eu/bin/rom_1_0813BD5C.bin"
gHighScoreText_Gfx:: @ 0x0813CD5C
	.incbin "data/eu/bin/rom_1_0813CD5C.bin"
gHighScoreScoreTable_Tilemap_De:: @ 0x0814457C
	.incbin "data/eu/bin/rom_1_0814457C.bin"
gHighScoreScoreTable_Tilemap_Fr:: @ 0x0814557C
	.incbin "data/eu/bin/rom_1_0814557C.bin"
gHighScoreScoreTable_Tilemap_It:: @ 0x0814657C
	.incbin "data/eu/bin/rom_1_0814657C.bin"
gHighScoreScoreTable_Tilemap_Es:: @ 0x0814757C
	.incbin "data/eu/bin/rom_1_0814757C.bin"
gHighScoreBallWatermark_Tilemap:: @ 0x08099FC0
	.incbin "graphics/high_score/high_score_ball_watermark_tilemap.bin"

gHighScoreBallWatermark_Gfx:: @ 0x0809AFC0
	.incbin "graphics/high_score/ball_watermark_tiles.4bpp"
	.space 0x20


gHighScoreBG_Pals:: @ 0x0814C19C
	.incbin "data/eu/bin/rom_1_0814C19C.bin"
gHighScoreSprite_Pals:: @ 0x0809DDE0
	.incbin "graphics/high_score/sprites.gbapal"

gHighScoreDialogs_Gfx_En:: @ 0x0814C59C
gHighScoreDialogs_Gfx:: @ 0x0809DFE0
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20

gHighScoreDialogs_Gfx_De:: @ 0x081509BC
	.incbin "data/eu/bin/rom_1_081509BC.bin"
gHighScoreDialogs_Gfx_Fr:: @ 0x08154DDC
	.incbin "data/eu/bin/rom_1_08154DDC.bin"
gHighScoreDialogs_Gfx_It:: @ 0x081591FC
	.incbin "data/eu/bin/rom_1_081591FC.bin"
gHighScoreDialogs_Gfx_Es:: @ 0x0815D61C
	.incbin "data/eu/bin/rom_1_0815D61C.bin"
gHighScoreTitle_Gfx_Fr:: @ 0x08161A3C
	.incbin "data/eu/bin/rom_1_08161A3C.bin"
gHighScoreTitle_Gfx_It:: @ 0x08161B9C
	.incbin "data/eu/bin/rom_1_08161B9C.bin"
gHighScoreTitle_Gfx_De:: @ 0x08162A3C
	.incbin "data/eu/bin/rom_1_08162A3C.bin"
gHighScoreTitle_Gfx_Es:: @ 0x08162B9C
	.incbin "data/eu/bin/rom_1_08162B9C.bin"
gFieldSelectBG0Tilemap:: @ 0x080A2400
	.incbin "graphics/field_select/field_select_bg_tilemap.bin"



gFieldSelectWindow_Gfx_En:: @ 0x0816425C
	.incbin "data/eu/bin/rom_1_0816425C.bin"
gFieldSelectWindow_Gfx_De:: @ 0x0816567C
	.incbin "data/eu/bin/rom_1_0816567C.bin"
gFieldSelectWindow_Gfx_Fr:: @ 0x08166A9C
	.incbin "data/eu/bin/rom_1_08166A9C.bin"
gBonusFieldSelectWindow_Gfx_Fr:: @ 0x08167EBC
	.incbin "data/eu/bin/rom_1_08167EBC.bin"
gFieldSelectWindow_Gfx_It:: @ 0x081692DC
	.incbin "data/eu/bin/rom_1_081692DC.bin"
gBonusFieldSelectWindow_Gfx_It:: @ 0x0816A6FC
	.incbin "data/eu/bin/rom_1_0816A6FC.bin"
gFieldSelectWindow_Gfx_Es:: @ 0x0816BB1C
	.incbin "data/eu/bin/rom_1_0816BB1C.bin"
gBonusFieldSelectWindow_Gfx_Es:: @ 0x0816CF3C
	.incbin "data/eu/bin/rom_1_0816CF3C.bin"
gFieldSelectFrameShadowTilemap_En:: @ 0x0816E35C
	.incbin "data/eu/bin/rom_1_0816E35C.bin"
gFieldSelectMiniFields_Gfx:: @ 0x080A4820
	.incbin "graphics/field_select/mini_fields.4bpp"
	.space 0x20

gFieldSelectFrameShadowTilemap_FrDeItEs:: @ 0x0817237C
	.incbin "data/eu/bin/rom_1_0817237C.bin"
gFieldSelectWindowTilemap:: @ 0x080A8040
	.incbin "graphics/field_select/window_tilemap.bin"

gFieldSelectBGPals:: @ 0x080A8840
	.incbin "graphics/field_select/bg_pals.gbapal"

gFieldSelectSpritePals:: @ 0x080A8A40
	.incbin "graphics/field_select/sprite_pals.gbapal"

gFieldSelectSpriteGfx_En:: @ 0x0817377C
gFieldSelectSpriteGfx:: @ 0x080A8C40
	.incbin "graphics/field_select/sprites.4bpp"


gFieldSelectSpriteGfx_De:: @ 0x0817779C
	.incbin "data/eu/bin/rom_1_0817779C.bin"
gFieldSelectSpriteGfx_Fr:: @ 0x0817B7BC
	.incbin "data/eu/bin/rom_1_0817B7BC.bin"
gFieldSelectSpriteGfx_It:: @ 0x0817F7DC
	.incbin "data/eu/bin/rom_1_0817F7DC.bin"
gFieldSelectSpriteGfx_Es:: @ 0x081837FC
	.incbin "data/eu/bin/rom_1_081837FC.bin"
gEReaderText_Gfx:: @ 0x0818781C
	.incbin "data/eu/bin/rom_1_0818781C.bin"
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

gIntroScene2Pikas_BG0Tilemap:: @ 0x080D0700
	.incbin "graphics/intro/scene2pikas/bg0_pichu_tilemap.bin"

gIntroScene2Pikas_BG1Tilemap:: @ 0x080D2700
	.incbin "graphics/intro/scene2pikas/bg1_pikachu_tilemap.bin"

gIntroScene3Treecko_Pal:: @ 0x080D4700
	.incbin "graphics/intro/scene3treecko/scene.gbapal"

gIntroScene3Treecko_BG2Tilemap:: @ 0x080D4900
	.incbin "graphics/intro/scene3treecko/bg2_tilemap.bin"

gIntroScene3Treecko_BG3Tilemap:: @ 0x080D5900
	.incbin "graphics/intro/scene3treecko/bg3_text_tilemap.bin"

gIntroScene3TreeckoBgTiles_Gfx:: @ 0x080D6100
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

gIntroScene4PlusleMinun_Pal:: @ 0x080E1540
	.incbin "graphics/intro/scene4plusleminun/scene.gbapal"

gIntroScene4PlusleMinun_BG3Tilemap:: @ 0x080E1740
	.incbin "graphics/intro/scene4plusleminun/bg3_text_tilemap.bin"

gIntroScene4PlusleMinunBgTiles_Gfx:: @ 0x080E1F40
	.incbin "graphics/intro/scene4plusleminun/tiles.4bpp"

gIntroScene4PlusleMinun_BG0Tilemap:: @ 0x080E5F60
	.incbin "graphics/intro/scene4plusleminun/bg0_minun_tilemap.bin"

gIntroScene4PlusleMinun_BG1Tilemap:: @ 0x080E7F60
	.incbin "graphics/intro/scene4plusleminun/bg1_plusle_tilemap.bin"

gIntroScene5Mudkip_Pal:: @ 0x080E9F60
	.incbin "graphics/intro/scene5mudkip/scene.gbapal"

gIntroScene5Mudkip_BG2Tilemap:: @ 0x080EA160
	.incbin "graphics/intro/scene5mudkip/bg2_2sections_tilemap.bin"

gIntroScene5Mudkip_BG1Tilemap:: @ 0x080EB160
	.incbin "graphics/intro/scene5mudkip/bg1_1sections_tilemap.bin"

gIntroScene5Mudkip_BG3Tilemap:: @ 0x080EC160
	.incbin "graphics/intro/scene5mudkip/bg3_text_tilemap.bin"

gIntroScene5MudkipBgTiles_Gfx:: @ 0x080EC960
	.incbin "graphics/intro/scene5mudkip/text_tiles.4bpp"
	.space 0x20

gIntroScene5Mudkip_BG0Tilemap:: @ 0x080F1980
	.incbin "graphics/intro/scene5mudkip/bg0_tilemap.bin"

gIntroScene5MudkipSprites_Gfx:: @ 0x080F2180
	.incbin "graphics/intro/scene5mudkip/sprites.4bpp"
	.space 0x20

	.incbin "graphics/intro/scene5mudkip/unused_bg_tilemap.bin"

gIntroScene6Chinchou_Pal:: @ 0x080F61A0
	.incbin "graphics/intro/scene6chinchou/scene.gbapal"

gIntroScene6Chinchou_BG3Tilemap:: @ 0x080F63A0
	.incbin "graphics/intro/scene6chinchou/bg3_burst_tilemap.bin"

gIntroScene6ChinchouBgTiles_Gfx:: @ 0x080F6BA0
	.incbin "graphics/intro/scene6chinchou/tiles.4bpp"
	.space 0x20

gIntroScene6Chinchou_BG2Tilemap:: @ 0x080FCFC0
	.incbin "graphics/intro/scene6chinchou/bg2_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG0Tilemap:: @ 0x080FD7C0
	.incbin "graphics/intro/scene6chinchou/bg0_chinchou_tilemap.bin"

gIntroScene6Chinchou_BG1Tilemap:: @ 0x080FDFC0
	.incbin "graphics/intro/scene6chinchou/bg1_ball_tilemap.bin"

gIntroScene6ChinchouStars_Gfx:: @ 0x080FFFC0
	.incbin "graphics/intro/scene6chinchou/stars.4bpp"
	.space 0x20

gIntroScene7Parade_Pal:: @ 0x08100FE0
	.incbin "graphics/intro/scene7parade/scene.gbapal"

gIntroScene7Parade_BG3Tilemap:: @ 0x081011E0
	.incbin "graphics/intro/scene7parade/bg3_text_tilemap.bin"

gIntroScene7ParadeBgTiles_Gfx:: @ 0x081019E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pelipper, makuhita, spoink

	.incbin "graphics/intro/scene7parade/tiles.4bpp"
	.space 0x20

gIntroScene7Parade_BG2Tilemap:: @ 0x08106A00
	.incbin "graphics/intro/scene7parade/bg2_makuhita_tilemap.bin"

gIntroScene7Parade_BG0Tilemap:: @ 0x08108A00
	.incbin "graphics/intro/scene7parade/bg0_pelipper_tilemap.bin"

gIntroScene7Parade_BG1Tilemap:: @ 0x0810AA00
	.incbin "graphics/intro/scene7parade/bg1_spoink_tilemap.bin"

gIntroScene7ParadeWailmer_Gfx:: @ 0x0810CA00
	.incbin "graphics/intro/scene7parade/wailmer.4bpp"
	.space 0x20

gIntroScene8WailmerLaunch_Pal:: @ 0x0810EA20
	.incbin "graphics/intro/scene8wailmerlaunch/scene.gbapal"

gIntroScene8WailmerLaunch_BG2Tilemap:: @ 0x0810EC20
	.incbin "graphics/intro/scene8wailmerlaunch/bg2_explosion_tilemap.bin"

gIntroScene8WailmerLaunchBgTiles_Gfx:: @ 0x0810F420
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






gLanguageSelectBg0_Tilemap:: @ 0x081FC87C
	.incbin "data/eu/bin/rom_1_081FC87C.bin"
gLanguageSelectBg1_Tilemap:: @ 0x081FD07C
	.incbin "data/eu/bin/rom_1_081FD07C.bin"
gLanguageSelectSprite_Gfx:: @ 0x081FD87C
	.incbin "data/eu/bin/rom_1_081FD87C.bin"
gLanguageSelectSprite_Pals:: @ 0x081FE89C
	.incbin "data/eu/bin/rom_1_081FE89C.bin"
gLanguageSelect_Gfx:: @ 0x081FEA9C
	.incbin "data/eu/bin/rom_1_081FEA9C.bin"
gLanguageSelectTitle_Gfx:: @ 0x08200A9C
	.incbin "data/eu/bin/rom_1_08200A9C.bin"
gLanguageSelectBg_Pals:: @ 0x08202ABC
	.incbin "data/eu/bin/rom_1_08202ABC.bin"
gTitlescreenBgTilemap_En:: @ 0x08202CBC
	.incbin "data/eu/bin/rom_1_08202CBC.bin"
gTitlescreenBg_Pals:: @ 0x082034BC
	.incbin "data/eu/bin/rom_1_082034BC.bin"
gTitlescreenBg_Gfx:: @ 0x082036BC
	.incbin "data/eu/bin/rom_1_082036BC.bin"
gTitlescreenBgTilemap_Fr:: @ 0x0820B6BC
	.incbin "data/eu/bin/rom_1_0820B6BC.bin"
gTitlescreenBgTilemap_De:: @ 0x0820BEBC
	.incbin "data/eu/bin/rom_1_0820BEBC.bin"
gTitlescreenBgTilemap_It:: @ 0x0820C6BC
	.incbin "data/eu/bin/rom_1_0820C6BC.bin"
gTitlescreenBgTilemap_Es:: @ 0x0820CEBC
	.incbin "data/eu/bin/rom_1_0820CEBC.bin"
gTitlescreenSpritesNoSavedGame_Gfx_De:: @ 0x0820D6BC
	.incbin "data/eu/bin/rom_1_0820D6BC.bin"
gTitlescreenSpritesNoSavedGame_Gfx_En:: @ 0x082146DC
	.incbin "data/eu/bin/rom_1_082146DC.bin"
gTitlescreenSpritesNoSavedGame_Gfx_Fr:: @ 0x0821B6FC
	.incbin "data/eu/bin/rom_1_0821B6FC.bin"
gTitlescreenSpritesNoSavedGame_Gfx_It:: @ 0x0822271C
	.incbin "data/eu/bin/rom_1_0822271C.bin"
gTitlescreenSpritesNoSavedGame_Gfx_Es:: @ 0x0822973C
	.incbin "data/eu/bin/rom_1_0822973C.bin"
gTitlescreenSpritesSavedGame_Gfx_De:: @ 0x0823075C
	.incbin "data/eu/bin/rom_1_0823075C.bin"
gTitlescreenSpritesSavedGame_Gfx_En:: @ 0x0823777C
	.incbin "data/eu/bin/rom_1_0823777C.bin"
gTitlescreenSpritesSavedGame_Gfx_Fr:: @ 0x0823E79C
	.incbin "data/eu/bin/rom_1_0823E79C.bin"
gTitlescreenSpritesSavedGame_Gfx_It:: @ 0x082457BC
	.incbin "data/eu/bin/rom_1_082457BC.bin"
gTitlescreenSpritesSavedGame_Gfx_Es:: @ 0x0824C7DC
	.incbin "data/eu/bin/rom_1_0824C7DC.bin"
gTitlescreenSprites_Pals:: @ 0x08137700
	.incbin "graphics/titlescreen/sprites.gbapal"

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

gChinchouBumper_Pals:: @ 0x08137998
	.incbin "graphics/stage/main/chinchou_bumper.gbapal"

gLotadBumper_Pals:: @ 0x081379B8
	.incbin "graphics/stage/main/lotad_bumper.gbapal"

gWhiscash_Pals:: @ 0x081379D8
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

gFieldVariant_Pals:: @ 0x08137B3C
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

	@ Vector16

gPauseMenuSpriteOffsets:: @ 0x08253E74
	.incbin "data/eu/bin/rom_1_08253E74.bin"
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

gIdlePressStartTiles_Fr:: @ 0x08253F10
	.incbin "data/eu/bin/rom_1_08253F10.bin"
gIdlePressStartTiles_De:: @ 0x08253F32
	.byte 0x16, 0x00, 0x17, 0x00, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x1B, 0x00, 0x1F, 0x00, 0x1C, 0x00
	.byte 0x1D, 0x00, 0x1E, 0x00, 0x17, 0x00, 0x1D, 0x00, 0x00, 0x00
gBall_Pals:: @ 0x08137E14
	.incbin "graphics/stage/main/pokeball_regular.gbapal"
	.incbin "graphics/stage/main/pokeball_great.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra.gbapal"
	.incbin "graphics/stage/main/pokeball_master.gbapal"
	.incbin "graphics/stage/main/pokeball_regular_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_great_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra_flash.gbapal"
	.incbin "graphics/stage/main/pokeball_master_flash.gbapal"
	.incbin "graphics/stage/main/ball_full_white.gbapal"
	@ The following are actually unused; apparently, these were considered
	@ for the freeze trap at some point, but were switched to pure white instead.
	.incbin "graphics/stage/main/pokeball_regular_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_great_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_ultra_frozen.gbapal"
	.incbin "graphics/stage/main/pokeball_master_frozen.gbapal"

gCaptureBallTilesGfx:: @ 0x08138014
	.incbin "graphics/stage/main/ball_open_to_catch.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx_En:: @ 0x0825496C
gDusclopsBonusClear_Gfx:: @ 0x08138834
	.incbin "graphics/stage/dusclops/dusclops_bonus_clear.4bpp"
	.space 0x20

gDusclopsBonusClear_Gfx_Fr:: @ 0x0825698C
	.incbin "data/eu/bin/rom_1_0825698C.bin"
gDusclopsBonusClear_Gfx_De:: @ 0x082589AC
	.incbin "data/eu/bin/rom_1_082589AC.bin"
gDusclopsBonusClear_Gfx_It:: @ 0x0825A9CC
	.incbin "data/eu/bin/rom_1_0825A9CC.bin"
gDusclopsBonusClear_Gfx_Es:: @ 0x0825C9EC
	.incbin "data/eu/bin/rom_1_0825C9EC.bin"
gKecleonBonusClear_Gfx_En:: @ 0x0825EA0C
gKecleonBonusClear_Gfx:: @ 0x0813A854
	.incbin "graphics/stage/kecleon/kecleon_bonus_clear.4bpp"
	.space 0x20

gKecleonBonusClear_Gfx_Fr:: @ 0x08260A2C
	.incbin "data/eu/bin/rom_1_08260A2C.bin"
gKecleonBonusClear_Gfx_De:: @ 0x08262A4C
	.incbin "data/eu/bin/rom_1_08262A4C.bin"
gKecleonBonusClear_Gfx_It:: @ 0x08264A6C
	.incbin "data/eu/bin/rom_1_08264A6C.bin"
gKecleonBonusClear_Gfx_Es:: @ 0x08266A8C
	.incbin "data/eu/bin/rom_1_08266A8C.bin"
gKyogreBonusClear_Gfx_En:: @ 0x08268AAC
gKyogreBonusClear_Gfx:: @ 0x0813C874
	.incbin "graphics/stage/kyogre/kyogre_bonus_clear.4bpp"
	.space 0x20

gKyogreBonusClear_Gfx_Fr:: @ 0x0826AACC
	.incbin "data/eu/bin/rom_1_0826AACC.bin"
gKyogreBonusClear_Gfx_De:: @ 0x0826CAEC
	.incbin "data/eu/bin/rom_1_0826CAEC.bin"
gKyogreBonusClear_Gfx_It:: @ 0x0826EB0C
	.incbin "data/eu/bin/rom_1_0826EB0C.bin"
gKyogreBonusClear_Gfx_Es:: @ 0x08270B2C
	.incbin "data/eu/bin/rom_1_08270B2C.bin"
gGroudonBonusClear_Gfx_En:: @ 0x08272B4C
gGroudonBonusClear_Gfx:: @ 0x0813E894
	.incbin "graphics/stage/groudon/groudon_bonus_clear.4bpp"
	.space 0x20

gGroudonBonusClear_Gfx_Fr:: @ 0x08274B6C
	.incbin "data/eu/bin/rom_1_08274B6C.bin"
gGroudonBonusClear_Gfx_De:: @ 0x08276B8C
	.incbin "data/eu/bin/rom_1_08276B8C.bin"
gGroudonBonusClear_Gfx_It:: @ 0x08278BAC
	.incbin "data/eu/bin/rom_1_08278BAC.bin"
gGroudonBonusClear_Gfx_Es:: @ 0x0827ABCC
	.incbin "data/eu/bin/rom_1_0827ABCC.bin"
gRayquazaBonusClear_Gfx_En:: @ 0x0827CBEC
gRayquazaBonusClear_Gfx:: @ 0x081408B4
	.incbin "graphics/stage/rayquaza/rayquaza_bonus_clear.4bpp"
	.space 0x20

gRayquazaBonusClear_Gfx_Fr:: @ 0x0827EC0C
	.incbin "data/eu/bin/rom_1_0827EC0C.bin"
gRayquazaBonusClear_Gfx_De:: @ 0x08280C2C
	.incbin "data/eu/bin/rom_1_08280C2C.bin"
gRayquazaBonusClear_Gfx_It:: @ 0x08282C4C
	.incbin "data/eu/bin/rom_1_08282C4C.bin"
gRayquazaBonusClear_Gfx_Es:: @ 0x08284C6C
	.incbin "data/eu/bin/rom_1_08284C6C.bin"
gCaptureScreenTilesGfx:: @ 0x081428D4
	.incbin "graphics/stage/main/capture_screen.4bpp"

.include "data/graphics/mon_hatch_sprites_pals.inc"

@ Attract-mode demos. Each IdleBoardConfig entry has 4800 ReplayInputFrame entries
@ (3 bytes of button bits per game frame).
@ Eeach GameState is one PinballGame snapshot the demo starts from.
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

gEvolutionCutsceneTilesGfx_EnFr:: @ 0x0829C63C
gEvolutionCutsceneTilesGfx:: @ 0x08158284
	.incbin "graphics/stage/main/board_action.4bpp"
	.space 0x3E0

gEvolutionCutsceneTilesGfx_De:: @ 0x0829EA5C
	.incbin "data/eu/bin/rom_1_0829EA5C.bin"
gEvolutionCutsceneTilesGfx_It:: @ 0x082A0E7C
	.incbin "data/eu/bin/rom_1_082A0E7C.bin"
gEvolutionCutsceneTilesGfx_Es:: @ 0x082A329C
	.incbin "data/eu/bin/rom_1_082A329C.bin"
gBoardActionObj_Pals:: @ 0x0815A6A4
	.incbin "graphics/stage/main/board_action_obj.gbapal"

gEvoExAppear_Gfx:: @ 0x0815A8A4
	.incbin "graphics/board_pickups/evo_item_ex.4bpp";

	.incbin "data/eu/bin/rom_1_082A74DC.bin"
gEvoItem_Pals:: @ 0x0815C4C4
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
	@ Six blank palettes, filling out the block. Solely containing a near-flat grey.
	.incbin "graphics/board_pickups/evo_item_unused.gbapal.bin"

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

@ 8x8 font, one tile per character.

	.include "data/graphics/mon_catch_sprites_pals.inc"

gKyogreWaterAnimFrame_Pals:: @ 0x081B0DE4
	.incbin "graphics/stage/kyogre/water_anim_frames.gbapal"

gPokeballCaptureOamFrames:: @ 0x081B0FE4
	@ frame 0
	packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0x0, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2C0, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1

	@ frame 1
	packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2CC, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2D4, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2D8, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2DC, paletteNum=0x1

	@ frame 2
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2DE, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2E6, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2EA, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x2EE, paletteNum=0x1

	@ frame 3
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x10, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x10, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=0x10, y=0x0, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2F0, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x2F8, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x2FC, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x300, paletteNum=0x1

	@ frame 4
    packed_sprite_oam x=-0xB, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=0x15, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=-0x10, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x0, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=0x15, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0xF, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x302, paletteNum=0x1
    packed_sprite_oam x=-0x6, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x30A, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1
    packed_sprite_oam x=-0xE, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x30E, paletteNum=0x1

	@ frame 5
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=0x16, y=-0x8, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1
    packed_sprite_oam x=-0x7, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x310, paletteNum=0x1
    packed_sprite_oam x=-0xF, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x318, paletteNum=0x1

	@ frame 6
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=-0x8, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x7, hFlip=0x1, vFlip=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x2C4, paletteNum=0x1

	@ frame 7
    packed_sprite_oam x=0x0, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x32E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x336, paletteNum=0x1
    packed_sprite_oam x=-0x3, y=0x21, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x338, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x10, y=-0x2, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x0, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x32E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x9, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x336, paletteNum=0x1
    packed_sprite_oam x=-0x3, y=0x21, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x338, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1
    packed_sprite_oam x=-0xB, y=0x29, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x33A, paletteNum=0x1

	@ frame 8
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0xD, y=0x1A, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x343, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0xA, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x34B, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x34D, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x3E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x35F, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x361, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0xD, y=0x1A, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x343, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0xA, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x34B, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x34D, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x3E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1

	@ frame 9
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xF, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37A, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=0x7, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x37B, paletteNum=0x1
    packed_sprite_oam x=0x1F, y=0x37, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1

	@ frame 10
    packed_sprite_oam x=0x6, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x36, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1

	@ frame 11
	packed_sprite_oam x=0xA, y=0x18, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0xA, y=0x38, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=-0x5, y=0x20, hFlip=0x1, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x18, hFlip=0x1, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=0x6, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=-0x12, y=0x36, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x26, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x16, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0x46, hFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1

	@ frame 12
	packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x21, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x396, paletteNum=0x1
    packed_sprite_oam x=0x3, y=0x19, vFlip=0x1, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x39E, paletteNum=0x1
    packed_sprite_oam x=-0x11, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_32x32, tileNum=0x362, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_32x16, tileNum=0x372, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xF, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37A, paletteNum=0x1
    packed_sprite_oam x=-0x8, y=0x7, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x37B, paletteNum=0x1
    packed_sprite_oam x=0x1F, y=0x37, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x37F, paletteNum=0x1
    packed_sprite_oam x=0xF, y=0x27, priority=0x1, spriteSize=SPRITE_SIZE_16x32, tileNum=0x380, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x17, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x388, paletteNum=0x1
    packed_sprite_oam x=-0x9, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x38A, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1
    packed_sprite_oam x=0x17, y=0x47, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x38E, paletteNum=0x1

	@ frame 13
    packed_sprite_oam x=-0x2, y=0x6, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x38F, paletteNum=0x1
    packed_sprite_oam x=-0xA, y=0xE, priority=0x1, spriteSize=SPRITE_SIZE_32x8, tileNum=0x391, paletteNum=0x1
    packed_sprite_oam x=-0x1, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x33B, paletteNum=0x1
    packed_sprite_oam x=0x7, y=0xC, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x341, paletteNum=0x1
    packed_sprite_oam x=0xF, y=-0x4, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x33F, paletteNum=0x1
    packed_sprite_oam x=0x5, y=0x26, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35D, paletteNum=0x1
    packed_sprite_oam x=0x1, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x356, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x16, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x358, paletteNum=0x1
    packed_sprite_oam x=0x1, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x35A, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1
    packed_sprite_oam x=0x11, y=0x1E, priority=0x1, spriteSize=SPRITE_SIZE_8x8, tileNum=0x35C, paletteNum=0x1

	@ frame 14
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_16x16, tileNum=0x326, paletteNum=0x1
    packed_sprite_oam x=0x12, y=-0x5, priority=0x1, spriteSize=SPRITE_SIZE_8x16, tileNum=0x32A, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1
    packed_sprite_oam x=0x2, y=0xB, priority=0x1, spriteSize=SPRITE_SIZE_16x8, tileNum=0x32C, paletteNum=0x1

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

@ Evolution selection background loop
gEvoModeBG0_0_Tilemap_En:: @ 0x082FCBFC
gEvoModeBG0_0_Tilemap:: @ 0x081B4784
	.incbin "graphics/stage/main/evo_mode_bg0_frame0_tilemap.bin"

gEvoModeBG0_0_Tilemap_Fr:: @ 0x082FDBFC
	.incbin "data/eu/bin/rom_1_082FDBFC.bin"
gEvoModeBG0_0_Tilemap_De:: @ 0x082FEBFC
	.incbin "data/eu/bin/rom_1_082FEBFC.bin"
gEvoModeBG0_0_Tilemap_It:: @ 0x082FFBFC
	.incbin "data/eu/bin/rom_1_082FFBFC.bin"
gEvoModeBG0_0_Tilemap_Es:: @ 0x08300BFC
	.incbin "data/eu/bin/rom_1_08300BFC.bin"
gEvoModeBG0_1_Tilemap:: @ 0x081B5784
	.incbin "graphics/stage/main/evo_mode_bg0_frame1_tilemap.bin"

	.incbin "data/eu/bin/rom_1_08302BFC.bin"
gEvoModeBG0_2_Tilemap:: @ 0x081B6784
	.incbin "graphics/stage/main/evo_mode_bg0_frame2_tilemap.bin"

	.incbin "data/eu/bin/rom_1_08307BFC.bin"
gEvoModeBG0_3_Tilemap:: @ 0x081B7784
	.incbin "graphics/stage/main/evo_mode_bg0_frame3_tilemap.bin"

	.incbin "data/eu/bin/rom_1_0830CBFC.bin"
gShopEvoUI_Pals:: @ 0x081B8784
	.incbin "graphics/stage/main/shop_evo_ui.gbapal"

@ Shop mode background loop
gShopModeBG0_0_Tilemap_En:: @ 0x08310DFC
gShopModeBG0_0_Tilemap:: @ 0x081B8984
	.incbin "graphics/stage/main/shop_mode_bg0_frame0_tilemap.bin"

gShopModeBG0_0_Tilemap_Fr:: @ 0x08311DFC
	.incbin "data/eu/bin/rom_1_08311DFC.bin"
gShopModeBG0_0_Tilemap_De:: @ 0x08312DFC
	.incbin "data/eu/bin/rom_1_08312DFC.bin"
gShopModeBG0_0_Tilemap_It:: @ 0x08313DFC
	.incbin "data/eu/bin/rom_1_08313DFC.bin"
gShopModeBG0_0_Tilemap_Es:: @ 0x08314DFC
	.incbin "data/eu/bin/rom_1_08314DFC.bin"
gShopModeBG0_1_Tilemap:: @ 0x081B9984
	.incbin "graphics/stage/main/shop_mode_bg0_frame1_tilemap.bin"

	.incbin "data/eu/bin/rom_1_08316DFC.bin"
gShopModeBG0_2_Tilemap:: @ 0x081BA984
	.incbin "graphics/stage/main/shop_mode_bg0_frame2_tilemap.bin"

	.incbin "data/eu/bin/rom_1_0831BDFC.bin"
gShopModeBG0_3_Tilemap:: @ 0x081BB984
	.incbin "graphics/stage/main/shop_mode_bg0_frame3_tilemap.bin"

	.incbin "data/eu/bin/rom_1_08320DFC.bin"
gSapphireShopSign_Pals:: @ 0x081BC984
	.incbin "graphics/stage/sapphire/shop_sign.gbapal"

gRubyTravelPaint_Gfx:: @ 0x081BCAA4
	.incbin "graphics/stage/ruby/travel_paint.4bpp"
	.space 0x120

gRubyPainter_Pals:: @ 0x081BE2C4
	.incbin "graphics/stage/ruby/painter.gbapal"

gSapphireTravelPaint_Gfx:: @ 0x081BE4C4
	.incbin "graphics/stage/sapphire/travel_paint.4bpp"
	.space 0x120

gSapphirePainter_Pals:: @ 0x081BFCE4
	.incbin "graphics/stage/sapphire/painter.gbapal"

gRubyBoard_Pals:: @ 0x081BFEE4
	.incbin "graphics/stage/ruby/ruby_board.gbapal"

gTimer_Default_Pal:: @ 0x081C0064
	.incbin "graphics/stage/main/default_timer.gbapal"

gLocation_Pals:: @ 0x081C00E4
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

	@ 3 unused palettes: one with color data, two blank
	.incbin "graphics/area_portraits/loc_unused.gbapal.bin"

gPortraitAnim_Pals:: @ 0x081C02E4
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

@ Note: file has a shared 'bumper collision map' at 0x08252B10
@ All other entries in this file are ruby board specific

gRubyBoardBG3Tilemap:: @ 0x081C08E4
	.incbin "graphics/stage/ruby/ruby_board_bg3_tilemap.bin"

gRubyBoardCollisionTileDataLayer0:: @ 0x081C18E4
    .incbin "data/board_data/collision/ruby/boardtop_launch_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0:: @ 0x081C38E4
    .incbin "data/board_data/collision/ruby/boardtop_launch_angledata.bin"

gRubyBoardCollisionTypeDataLayer0:: @ 0x081DC064
    .incbin "data/board_data/collision/ruby/boardtop_launch_typedata.bin"

gRubyBoardCollisionTileDataLayer0Alt:: @ 0x081E8424
    .incbin "data/board_data/collision/ruby/boardtop_normal_tiledata.bin"

gRubyBoardCollisionAngleDataLayer0Alt:: @ 0x081EA424
    .incbin "data/board_data/collision/ruby/boardtop_normal_angledata.bin"

gRubyBoardCollisionTypeDataLayer0Alt:: @ 0x082027A4
    .incbin "data/board_data/collision/ruby/boardtop_normal_typedata.bin"

gRubyBoardCollisionTileDataLayer1:: @ 0x0820E964
    .incbin "data/board_data/collision/ruby/boardbottom_tiledata.bin"

gRubyBoardCollisionAngleDataLayer1:: @ 0x08210964
    .incbin "data/board_data/collision/ruby/boardbottom_angledata.bin"

gRubyBoardCollisionTypeDataLayer1:: @ 0x082245E4
    .incbin "data/board_data/collision/ruby/boardbottom_typedata.bin"

gRubyBoardBG2Tilemap:: @ 0x0822E424
	.incbin "graphics/stage/ruby/ruby_board_ramp_tilemap.bin"

gRubyBoardCollisionTileDataLayer2:: @ 0x0822F424
    .incbin "data/board_data/collision/ruby/topramps_tiledata.bin"

gRubyBoardCollisionAngleDataLayer2:: @ 0x08231424
    .incbin "data/board_data/collision/ruby/topramps_angledata.bin"

gRubyBoardCollisionTypeDataLayer2:: @ 0x082432A4
    .incbin "data/board_data/collision/ruby/topramps_typedata.bin"

gRubyBoardCompressedTiles1_En:: @ 0x083B465C
gRubyBoardCompressedTiles1:: @ 0x0824C1E4
	.incbin "graphics/stage/ruby/ruby_board_bgramp_tiles.4bpp.lz"

gRubyBoardCompressedTiles2_En:: @ 0x083B61D8
gRubyBoardCompressedTiles2:: @ 0x0824DD60
	.incbin "graphics/stage/ruby/ruby_board_bgtop_tiles.4bpp.lz"

gRubyBoardCompressedTiles2_Fr:: @ 0x083B8DAC
	.incbin "data/eu/bin/rom_1_083B8DAC.bin"
gRubyBoardCompressedTiles2_De:: @ 0x083BB964
	.incbin "data/eu/bin/rom_1_083BB964.bin"
gRubyBoardCompressedTiles2_It:: @ 0x083BE4DC
	.incbin "data/eu/bin/rom_1_083BE4DC.bin"
gRubyBoardCompressedTiles2_Es:: @ 0x083C108C
	.incbin "data/eu/bin/rom_1_083C108C.bin"
gRubyBoardCompressedBGTileBuffer_En:: @ 0x083C3C44
gRubyBoardCompressedBGTileBuffer:: @ 0x08250934
	.incbin "graphics/stage/ruby/ruby_board_bgbottom_tiles.4bpp.lz"

gRubyBoardCompressedBGTileBuffer_Fr:: @ 0x083C5E20
	.incbin "data/eu/bin/rom_1_083C5E20.bin"
gRubyBoardCompressedBGTileBuffer_De:: @ 0x083C7FF8
	.incbin "data/eu/bin/rom_1_083C7FF8.bin"
gRubyBoardCompressedBGTileBuffer_It:: @ 0x083CA1E0
	.incbin "data/eu/bin/rom_1_083CA1E0.bin"
gRubyBoardCompressedBGTileBuffer_Es:: @ 0x083CC39C
	.incbin "data/eu/bin/rom_1_083CC39C.bin"
gRubyBoardCompressedTiles1_Fr:: @ 0x083CE564
	.incbin "data/eu/bin/rom_1_083CE564.bin"
gRubyBoardCompressedTiles1_De:: @ 0x083D00B8
	.incbin "data/eu/bin/rom_1_083D00B8.bin"
gRubyBoardCompressedTiles1_It:: @ 0x083D1BF4
	.incbin "data/eu/bin/rom_1_083D1BF4.bin"
gRubyBoardCompressedTiles1_Es:: @ 0x083D374C
	.incbin "data/eu/bin/rom_1_083D374C.bin"
gSharedBumperCollisionMap:: @ 0x08252B10
	.incbin "data/board_data/collision/ruby/shared_bumper_entity_collision_64x64.bin"

gRubyLinooneLeftCollisionMap:: @ 0x08254B10
    .incbin "data/board_data/collision/ruby/linoone_left_collision_map_72x72.bin"

gRubyLinooneRightCollisionMap:: @ 0x08257390
    .incbin "data/board_data/collision/ruby/linoone_right_collision_map_72x72.bin"

gWhiscashCollisionMap:: @ 0x08259C10
	.incbin "data/board_data/collision/ruby/whiscash_entity_collision_80x88.bin"


@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gRubyEvoArrow_E_0Lit_Top:: @ 0x0825D310
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_0.4bpp"

gRubyEvoArrow_E_1Lit_Top:: @ 0x0825D370
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_0.4bpp"

gRubyEvoArrow_E_2PlusLit_Top:: @ 0x0825D3D0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_0.4bpp"

gRubyEvoArrow_V_0Lit_Top:: @ 0x0825D430
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_0.4bpp"

gRubyEvoArrow_V_1Lit_Top:: @ 0x0825D490
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_0.4bpp"

gRubyEvoArrow_V_2Lit_Top:: @ 0x0825D4F0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_0.4bpp"

gRubyEvoArrow_V_3Lit_Top:: @ 0x0825D550
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_0.4bpp"

gRubyEvoArrow_O_Under2Lit_Top:: @ 0x0825D5B0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_0.4bpp"

gRubyEvoArrow_O_2Lit_Top:: @ 0x0825D610
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_0.4bpp"

gRubyEvoArrow_O_3Lit_Top:: @ 0x0825D670
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_0.4bpp"
	.space 0x40

gRubyEvoArrow_E_0Lit_Mid:: @ 0x0825D710
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_1.4bpp"

gRubyEvoArrow_E_1Lit_Mid:: @ 0x0825D770
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_1.4bpp"

gRubyEvoArrow_E_2PlusLit_Mid:: @ 0x0825D7D0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_1.4bpp"

gRubyEvoArrow_V_0Lit_Mid:: @ 0x0825D830
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_1.4bpp"

gRubyEvoArrow_V_1Lit_Mid:: @ 0x0825D890
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_1.4bpp"

gRubyEvoArrow_V_2Lit_Mid:: @ 0x0825D8F0
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_1.4bpp"

gRubyEvoArrow_V_3Lit_Mid:: @ 0x0825D950
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_1.4bpp"

gRubyEvoArrow_O_Under2Lit_Mid:: @ 0x0825D9B0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_1.4bpp"

gRubyEvoArrow_O_2Lit_Mid:: @ 0x0825DA10
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_1.4bpp"

gRubyEvoArrow_O_3Lit_Mid:: @ 0x0825DA70
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_1.4bpp"
	.space 0x40

gRubyEvoArrow_E_0Lit_Bot:: @ 0x0825DB10
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_0_2.4bpp"

gRubyEvoArrow_E_1Lit_Bot:: @ 0x0825DB70
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_1_2.4bpp"

gRubyEvoArrow_E_2PlusLit_Bot:: @ 0x0825DBD0
	.incbin "graphics/stage/ruby/evo_arrow/ruby_evo_e_arrow_2_2.4bpp"

gRubyEvoArrow_V_0Lit_Bot:: @ 0x0825DC30
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_0_2.4bpp"

gRubyEvoArrow_V_1Lit_Bot:: @ 0x0825DC90
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_1_2.4bpp"

gRubyEvoArrow_V_2Lit_Bot:: @ 0x0825DCF0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_2_2.4bpp"

gRubyEvoArrow_V_3Lit_Bot:: @ 0x0825DD50
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_v_arrow_3_2.4bpp"

gRubyEvoArrow_O_Under2Lit_Bot:: @ 0x0825DDB0
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_0_2.4bpp"

gRubyEvoArrow_O_2Lit_Bot:: @ 0x0825DE10
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_1_2.4bpp"

gRubyEvoArrow_O_3Lit_Bot:: @ 0x0825DE70
    .incbin "graphics/stage/ruby/evo_arrow/ruby_evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows

gRubyCoinArrow_1_0Lit_Top:: @ 0x0825DF10
	@.incbin "graphics/stage/ruby/ruby_coin_arrows.4bpp"

    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p0.4bpp"

gRubyCoinArrow_1_1Lit_Top:: @ 0x0825DF70
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p0.4bpp"

gRubyCoinArrow_1_2PlusLit_Top:: @ 0x0825DFD0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p0.4bpp"

gRubyCoinArrow_5_0Lit_Top:: @ 0x0825E030
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p0.4bpp"

gRubyCoinArrow_5_1Lit_Top:: @ 0x0825E090
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p0.4bpp"

gRubyCoinArrow_5_2Lit_Top:: @ 0x0825E0F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gRubyCoinArrow_5_3Lit_Top:: @ 0x0825E150
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p0.4bpp"

gRubyCoinArrow_10_Under2Lit_Top:: @ 0x0825E1B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p0.4bpp"

gRubyCoinArrow_10_2Lit_Top:: @ 0x0825E210
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p0.4bpp"

gRubyCoinArrow_10_3Lit_Top:: @ 0x0825E270
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p0.4bpp"
    .space 0x40

gRubyCoinArrow_1_0Lit_Mid:: @ 0x0825E310
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gRubyCoinArrow_1_1Lit_Mid:: @ 0x0825E370
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p1.4bpp"

gRubyCoinArrow_1_2PlusLit_Mid:: @ 0x0825E3D0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p1.4bpp"

gRubyCoinArrow_5_0Lit_Mid:: @ 0x0825E430
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p1.4bpp"

gRubyCoinArrow_5_1Lit_Mid:: @ 0x0825E490
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p1.4bpp"

gRubyCoinArrow_5_2Lit_Mid:: @ 0x0825E4F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gRubyCoinArrow_5_3Lit_Mid:: @ 0x0825E550
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p1.4bpp"

gRubyCoinArrow_10_Under2Lit_Mid:: @ 0x0825E5B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p1.4bpp"

gRubyCoinArrow_10_2Lit_Mid:: @ 0x0825E610
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p1.4bpp"

gRubyCoinArrow_10_3Lit_Mid:: @ 0x0825E670
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p1.4bpp"
    .space 0x40

gRubyCoinArrow_1_0Lit_Bot:: @ 0x0825E710
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gRubyCoinArrow_1_1Lit_Bot:: @ 0x0825E770
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gRubyCoinArrow_1_2PlusLit_Bot:: @ 0x0825E7D0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g0_v3_p2.4bpp"

gRubyCoinArrow_5_0Lit_Bot:: @ 0x0825E830
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gRubyCoinArrow_5_1Lit_Bot:: @ 0x0825E890
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gRubyCoinArrow_5_2Lit_Bot:: @ 0x0825E8F0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gRubyCoinArrow_5_3Lit_Bot:: @ 0x0825E950
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g1_v3_p2.4bpp"

gRubyCoinArrow_10_Under2Lit_Bot:: @ 0x0825E9B0
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v0_p2.4bpp"

gRubyCoinArrow_10_2Lit_Bot:: @ 0x0825EA10
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v2_p2.4bpp"

gRubyCoinArrow_10_3Lit_Bot:: @ 0x0825EA70
    .incbin "graphics/stage/ruby/coin_arrow/coin_arrow_g2_v3_p2.4bpp"
    .space 0x40


@ Get Arrows

gRubyGetArrow_G_0Lit_Top:: @ 0x0825EB10
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_0.4bpp"

gRubyGetArrow_G_1Lit_Top:: @ 0x0825EB70
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_0.4bpp"

gRubyGetArrow_G_2PlusLit_Top:: @ 0x0825EBD0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_E_0Lit_Top:: @ 0x0825EC50
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_E_1Lit_Top:: @ 0x0825ECB0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gRubyGetArrow_E_2Lit_Top:: @ 0x0825ED10
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_E_3Lit_Top:: @ 0x0825ED70
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_0.4bpp"
    .space 0x20

gRubyGetArrow_T_Under2Lit_Top:: @ 0x0825EDD0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_0.4bpp"
    .space 0x20

gRubyGetArrow_T_2Lit_Top:: @ 0x0825EE30
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_0.4bpp"
    .space 0x20

gRubyGetArrow_T_3Lit_Top:: @ 0x0825EE90
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gRubyGetArrow_G_0Lit_Mid:: @ 0x0825EF10
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_1.4bpp"

gRubyGetArrow_G_1Lit_Mid:: @ 0x0825EF70
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_1.4bpp"

gRubyGetArrow_G_2PlusLit_Mid:: @ 0x0825EFD0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_1.4bpp"
    .space 0x20

gRubyGetArrow_E_0Lit_Mid:: @ 0x0825F050
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_1.4bpp"
    .space 0x20

gRubyGetArrow_E_1Lit_Mid:: @ 0x0825F0B0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_1.4bpp"
    .space 0x20

gRubyGetArrow_E_2Lit_Mid:: @ 0x0825F110
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_1.4bpp"
    .space 0x20

gRubyGetArrow_E_3Lit_Mid:: @ 0x0825F170
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_1.4bpp"

gRubyGetArrow_T_Under2Lit_Mid:: @ 0x0825F1B0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_1.4bpp"

gRubyGetArrow_T_2Lit_Mid:: @ 0x0825F210
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_1.4bpp"

gRubyGetArrow_T_3Lit_Mid:: @ 0x0825F270
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gRubyGetArrow_G_0Lit_Bot:: @ 0x0825F310
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_0_2.4bpp"

gRubyGetArrow_G_1Lit_Bot:: @ 0x0825F370
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_2_2.4bpp"

gRubyGetArrow_G_2PlusLit_Bot:: @ 0x0825F3D0
    .incbin "graphics/stage/ruby/get_arrow/get_g_arrow_3_2.4bpp"

gRubyGetArrow_E_0Lit_Bot:: @ 0x0825F430
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_0_2.4bpp"

gRubyGetArrow_E_1Lit_Bot:: @ 0x0825F490
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_1_2.4bpp"

gRubyGetArrow_E_2Lit_Bot:: @ 0x0825F4F0
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_2_2.4bpp"

gRubyGetArrow_E_3Lit_Bot:: @ 0x0825F550
    .incbin "graphics/stage/ruby/get_arrow/get_e_arrow_3_2.4bpp"

gRubyGetArrow_T_Under2Lit_Bot:: @ 0x0825F5B0
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_0_2.4bpp"

gRubyGetArrow_T_2Lit_Bot:: @ 0x0825F610
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_2_2.4bpp"

gRubyGetArrow_T_3Lit_Bot:: @ 0x0825F670
    .incbin "graphics/stage/ruby/get_arrow/get_t_arrow_3_2.4bpp"
	.space 0x40
	.fill 0x20, 1, 0x22


@ Ball power up lights

	.incbin "data/eu/bin/rom_1_083E1EC4.bin"
gRubyBallPowerUpLight0off:: @ 0x0825F730
	.incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_off.4bpp"

gRubyBallPowerUpLight0on:: @ 0x0825F770
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_0_on.4bpp"

gRubyBallPowerUpLight1off:: @ 0x0825F7B0
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_off.4bpp"

gRubyBallPowerUpLight1on:: @ 0x0825F7F0
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_1_on.4bpp"

gRubyBallPowerUpLight2off:: @ 0x0825F830
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_off.4bpp"

gRubyBallPowerUpLight2on:: @ 0x0825F870
    .incbin "graphics/stage/ruby/ball_power_up_lights/ruby_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gRubyHoleLightH_Off:: @ 0x0825F8B0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_off.4bpp"

gRubyHoleLightH_On:: @ 0x0825F8F0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_h_on.4bpp"

gRubyHoleLightO_Off:: @ 0x0825F930
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_off.4bpp"

gRubyHoleLightO_On:: @ 0x0825F970
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_o_on.4bpp"

gRubyHoleLightL_Off:: @ 0x0825F9B0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_off.4bpp"

gRubyHoleLightL_On:: @ 0x0825F9F0
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_l_on.4bpp"

gRubyHoleLightE_Off:: @ 0x0825FA30
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_off.4bpp"

gRubyHoleLightE_On:: @ 0x0825FA70
	.incbin "graphics/stage/ruby/hole_lights/ruby_hole_light_e_on.4bpp"



@ Catch light arrows : 3 balls / CATCH! / EVO

gRubyCatchLightState0Top:: @ 0x0825FAB0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_top.4bpp"

gRubyCatchLightState1Top:: @ 0x0825FAF0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_top.4bpp"
    .space 0x380

gRubyCatchLightState0Bot:: @ 0x0825FEB0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state0_bot.4bpp"

gRubyCatchLightState1Bot:: @ 0x0825FEF0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_state1_bot.4bpp"

gRubyTrapIndicatorState0Top:: @ 0x0825FF30
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_top.4bpp"

gRubyTrapIndicatorState1Top:: @ 0x0825FF70
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_top.4bpp"

gRubyTrapIndicatorState2Top:: @ 0x0825FFB0
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_top.4bpp"



gRubyCatchLightSlot0State2Top:: @ 0x083EB804
	.incbin "data/eu/bin/rom_1_083EB804.bin"
gRubyCatchLightSlot0State3Top:: @ 0x083EB844
	.incbin "data/eu/bin/rom_1_083EB844.bin"
gRubyCatchLightSlot1State2Top:: @ 0x08260070
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_top.4bpp"

gRubyCatchLightSlot1State3Top:: @ 0x082600B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_top.4bpp"

gRubyCatchLightSlot2State2Top:: @ 0x082600F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_top.4bpp"

gRubyCatchLightSlot2State3Top:: @ 0x08260130
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_top.4bpp"

gRubyCatchLightSlot0State4Top:: @ 0x08260170
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_top.4bpp"

gRubyCatchLightSlot0State5Top:: @ 0x082601B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_top.4bpp"

gRubyCatchLightSlot1State4Top:: @ 0x082601F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_top.4bpp"

gRubyCatchLightSlot1State5Top:: @ 0x08260230
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_top.4bpp"

gRubyCatchLightSlot2State4Top:: @ 0x08260270
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_top.4bpp"

gRubyCatchLightSlot2State5Top:: @ 0x082602B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state5_top.4bpp"
	.space 0x40

gRubyTrapIndicatorState0Bot:: @ 0x08260330
    .incbin "graphics/stage/ruby/trap_indicator/trap_state0_bot.4bpp"

gRubyTrapIndicatorState1Bot:: @ 0x08260370
    .incbin "graphics/stage/ruby/trap_indicator/trap_state1_bot.4bpp"

gRubyTrapIndicatorState2Bot:: @ 0x082603B0
    .incbin "graphics/stage/ruby/trap_indicator/trap_state2_bot.4bpp"



gRubyCatchLightSlot0State2Bot:: @ 0x083EBC04
	.incbin "data/eu/bin/rom_1_083EBC04.bin"
gRubyCatchLightSlot0State3Bot:: @ 0x083EBC44
	.incbin "data/eu/bin/rom_1_083EBC44.bin"
gRubyCatchLightSlot1State2Bot:: @ 0x08260470
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state2_bot.4bpp"

gRubyCatchLightSlot1State3Bot:: @ 0x082604B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state3_bot.4bpp"

gRubyCatchLightSlot2State2Bot:: @ 0x082604F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state2_bot.4bpp"

gRubyCatchLightSlot2State3Bot:: @ 0x08260530
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state3_bot.4bpp"

gRubyCatchLightSlot0State4Bot:: @ 0x08260570
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state4_bot.4bpp"

gRubyCatchLightSlot0State5Bot:: @ 0x082605B0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot0_state5_bot.4bpp"

gRubyCatchLightSlot1State4Bot:: @ 0x082605F0
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state4_bot.4bpp"

gRubyCatchLightSlot1State5Bot:: @ 0x08260630
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot1_state5_bot.4bpp"

gRubyCatchLightSlot2State4Bot:: @ 0x08260670
    .incbin "graphics/stage/ruby/catch_lights/catch_light_slot2_state4_bot.4bpp"



@ Ruby Saver indicator

gRubyCatchLightSlot2State5Bot:: @ 0x083EBEC4
	.incbin "data/eu/bin/rom_1_083EBEC4.bin"
gRubySaverRow0Tile_Off:: @ 0x08260770
    .incbin "graphics/stage/ruby/saver/saver_off_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row0_filler.4bpp"

gRubySaverRow0Tile_On:: @ 0x08260870
    .incbin "graphics/stage/ruby/saver/saver_on_row0.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row0_filler.4bpp"

gRubySaverRow1Tile_Off:: @ 0x08260B70
    .incbin "graphics/stage/ruby/saver/saver_off_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row1_filler.4bpp"

gRubySaverRow1Tile_On:: @ 0x08260C70
    .incbin "graphics/stage/ruby/saver/saver_on_row1.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_on_row1_filler.4bpp"

gRubySaverRow2Tile_Off:: @ 0x08260F90
    .incbin "graphics/stage/ruby/saver/saver_off_row2.4bpp"
    .incbin "graphics/stage/ruby/saver/saver_off_row2_filler.4bpp"

gRubySaverRow2Tile_On:: @ 0x08261090
    .incbin "graphics/stage/ruby/saver/saver_on_row2.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x200
	.fill 0xA0, 1, 0x11

gRubySaverRow3Tile_Off:: @ 0x082613F0
    .incbin "graphics/stage/ruby/saver/saver_off_row3.4bpp"
	.fill 0xC0, 1, 0x11

gRubySaverRow3Tile_On:: @ 0x082614F0
    .incbin "graphics/stage/ruby/saver/saver_on_row3.4bpp"
	.fill 0x20, 1, 0x11
	.space 0x220

	.incbin "data/eu/bin/rom_1_083F1004.bin"
gRubyHatchArrowRow0Tile_Off:: @ 0x08261770
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row0.4bpp"

gRubyHatchArrowRow0Tile_On:: @ 0x082617F0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_Off:: @ 0x082618B0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row0_filler.4bpp"

gRubyCatchArrowRow0Tile_On:: @ 0x08261930
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0.4bpp"
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_Off:: @ 0x082619B0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row0_filler.4bpp"

gRubyBumperArrowRow0Tile_On:: @ 0x08261A30
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row0.4bpp"
    .space 0x100

gRubyHatchArrowRow1Tile_Off:: @ 0x08261B70
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row1.4bpp"

gRubyHatchArrowRow1Tile_On:: @ 0x08261BF0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row1.4bpp"

gRubyCatchArrowRow1Tile_Off:: @ 0x08261C70
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row1.4bpp"

gRubyCatchArrowRow1Tile_On:: @ 0x08261CF0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row1.4bpp"

gRubyBumperArrowRow1Tile_Off:: @ 0x08261D70
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row1.4bpp"

gRubyBumperArrowRow1Tile_On:: @ 0x08261DF0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gRubyHatchArrowRow2Tile_Off:: @ 0x08261F70
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row2.4bpp"

gRubyHatchArrowRow2Tile_On:: @ 0x08261FF0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row2.4bpp"

gRubyCatchArrowRow2Tile_Off:: @ 0x08262070
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row2.4bpp"

gRubyCatchArrowRow2Tile_On:: @ 0x082620F0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row2.4bpp"

gRubyBumperArrowRow2Tile_Off:: @ 0x08262170
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row2.4bpp"

gRubyBumperArrowRow2Tile_On:: @ 0x082621F0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gRubyHatchArrowRow3Tile_Off:: @ 0x08262370
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_off_row3.4bpp"

gRubyHatchArrowRow3Tile_On:: @ 0x082623F0
    .incbin "graphics/stage/ruby/hatch_arrow/hatch_arrow_on_row3.4bpp"

gRubyCatchArrowRow3Tile_Off:: @ 0x08262470
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_off_row3.4bpp"

gRubyCatchArrowRow3Tile_On:: @ 0x082624F0
    .incbin "graphics/stage/ruby/catch_arrow/catch_arrow_on_row3.4bpp"

gRubyBumperArrowRow3Tile_Off:: @ 0x08262570
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_off_row3_filler.4bpp"

gRubyBumperArrowRow3Tile_On:: @ 0x082625F0
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .incbin "graphics/stage/ruby/bumper_arrow/bumper_arrow_on_row3_filler.4bpp"


@ Sign for bonus multiplier left/right digits

	.incbin "data/eu/bin/rom_1_083F5084.bin"
gRubyProgressDigit0_Tens:: @ 0x08262790
    .incbin "graphics/stage/ruby/progress_digits/digit0_tens.4bpp"

gRubyProgressDigit1_Tens:: @ 0x082627B0
    .incbin "graphics/stage/ruby/progress_digits/digit1_tens.4bpp"

gRubyProgressDigit2_Tens:: @ 0x082627D0
    .incbin "graphics/stage/ruby/progress_digits/digit2_tens.4bpp"

gRubyProgressDigit3_Tens:: @ 0x082627F0
    .incbin "graphics/stage/ruby/progress_digits/digit3_tens.4bpp"

gRubyProgressDigit4_Tens:: @ 0x08262810
    .incbin "graphics/stage/ruby/progress_digits/digit4_tens.4bpp"

gRubyProgressDigit5_Tens:: @ 0x08262830
    .incbin "graphics/stage/ruby/progress_digits/digit5_tens.4bpp"

gRubyProgressDigit6_Tens:: @ 0x08262850
    .incbin "graphics/stage/ruby/progress_digits/digit6_tens.4bpp"

gRubyProgressDigit7_Tens:: @ 0x08262870
    .incbin "graphics/stage/ruby/progress_digits/digit7_tens.4bpp"

gRubyProgressDigit8_Tens:: @ 0x08262890
    .incbin "graphics/stage/ruby/progress_digits/digit8_tens.4bpp"

gRubyProgressDigit9_Tens:: @ 0x082628B0
    .incbin "graphics/stage/ruby/progress_digits/digit9_tens.4bpp"

gRubyProgressDigit0_Ones:: @ 0x082628D0
    .incbin "graphics/stage/ruby/progress_digits/digit0_ones.4bpp"

gRubyProgressDigit1_Ones:: @ 0x082628F0
    .incbin "graphics/stage/ruby/progress_digits/digit1_ones.4bpp"

gRubyProgressDigit2_Ones:: @ 0x08262910
    .incbin "graphics/stage/ruby/progress_digits/digit2_ones.4bpp"

gRubyProgressDigit3_Ones:: @ 0x08262930
    .incbin "graphics/stage/ruby/progress_digits/digit3_ones.4bpp"

gRubyProgressDigit4_Ones:: @ 0x08262950
    .incbin "graphics/stage/ruby/progress_digits/digit4_ones.4bpp"

gRubyProgressDigit5_Ones:: @ 0x08262970
    .incbin "graphics/stage/ruby/progress_digits/digit5_ones.4bpp"

gRubyProgressDigit6_Ones:: @ 0x08262990
    .incbin "graphics/stage/ruby/progress_digits/digit6_ones.4bpp"

gRubyProgressDigit7_Ones:: @ 0x082629B0
    .incbin "graphics/stage/ruby/progress_digits/digit7_ones.4bpp"

gRubyProgressDigit8_Ones:: @ 0x082629D0
    .incbin "graphics/stage/ruby/progress_digits/digit8_ones.4bpp"

gRubyProgressDigit9_Ones:: @ 0x082629F0
    .incbin "graphics/stage/ruby/progress_digits/digit9_ones.4bpp"

.space 0x1A0


@ Text for sign over Ruby shop entrance

	.incbin "data/eu/bin/rom_1_083F9524.bin"
gRubyShopSignMartPiece0:: @ 0x08262BB0
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece0.4bpp"


gRubyShopSignMartPiece1:: @ 0x08262FB0
    .incbin "graphics/stage/ruby/shop_sign/shop_sign_mart_piece1.4bpp"






@ arrow for ramp leading to shop: mart/evo

	.incbin "data/eu/bin/rom_1_083F9764.bin"
gRubyEvoArrow_R0_Off:: @ 0x082637D0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gRubyEvoArrow_R0_On:: @ 0x08263870
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row0.4bpp"

gRubyMartArrow_R0_Off:: @ 0x08263910
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gRubyMartArrow_R0_On:: @ 0x082639B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row0.4bpp"
	.space 0x180

gRubyEvoArrow_R1_Off:: @ 0x08263BD0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gRubyEvoArrow_R1_On:: @ 0x08263C70
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row1.4bpp"

gRubyMartArrow_R1_Off:: @ 0x08263D10
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gRubyMartArrow_R1_On:: @ 0x08263DB0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row1.4bpp"
	.space 0x180

gRubyEvoArrow_R2_Off:: @ 0x08263FD0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gRubyEvoArrow_R2_On:: @ 0x08264070
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row2.4bpp"

gRubyMartArrow_R2_Off:: @ 0x08264110
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gRubyMartArrow_R2_On:: @ 0x082641B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row2.4bpp"
	.space 0x180

gRubyEvoArrow_R3_Off:: @ 0x082643D0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_off_row3_filler.4bpp"

gRubyEvoArrow_R3_On:: @ 0x08264470
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_evo_on_row3_filler.4bpp"

gRubyMartArrow_R3_Off:: @ 0x08264510
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_off_row3_filler.4bpp"

gRubyMartArrow_R3_On:: @ 0x082645B0
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "graphics/stage/ruby/mart_arrow/mart_arrow_mart_on_row3_filler.4bpp"
	.space 0x1A0



@ Slingshot wedge lights

	.incbin "data/eu/bin/rom_1_083FCDE4.bin"
gRuby_LSlingshot_Off_R0:: @ 0x082647F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gRuby_LSlingshot_On_R0:: @ 0x08264850
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gRuby_RSlingshot_Off_R0:: @ 0x082648F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gRuby_RSlingshot_On_R0:: @ 0x08264950
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R1:: @ 0x08264BF0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R1:: @ 0x08264C50
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gRuby_RSlingshot_Off_R1:: @ 0x08264CD0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R1:: @ 0x08264D30
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R2:: @ 0x08264FF0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row2.4bpp"

gRuby_LSlingshot_On_R2:: @ 0x08265050
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row2.4bpp"

gRuby_RSlingshot_Off_R2:: @ 0x082650B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row2.4bpp"

gRuby_RSlingshot_On_R2:: @ 0x08265110
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gRuby_LSlingshot_Off_R3:: @ 0x082653F0
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row3.4bpp"

gRuby_LSlingshot_On_R3:: @ 0x08265450
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row3.4bpp"

gRuby_RSlingshot_Off_R3:: @ 0x082654B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row3.4bpp"

gRuby_RSlingshot_On_R3:: @ 0x08265510
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gRuby_LSlingshot_Off_R4:: @ 0x08265810
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gRuby_LSlingshot_On_R4:: @ 0x08265870
    .incbin "graphics/stage/ruby/slingshot/slingshot_left_on_row4.4bpp"

gRuby_RSlingshot_Off_R4:: @ 0x082658B0
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gRuby_RSlingshot_On_R4:: @ 0x08265910
    .incbin "graphics/stage/ruby/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0



gRubyBoardBG1Tiles:: @ 0x08265C10
	@ loaded to charblock 2; tiles 0-703 are blank because all_board_setup.c
	@ later overwrites that region with the decompressed bgtop tiles
	.incbin "graphics/stage/ruby/ruby_board_bg1_tiles.4bpp"

gRubyBoardBG1Tilemap:: @ 0x0826DC10
	.incbin "graphics/stage/ruby/ruby_board_bg1_tilemap.bin"

@ Note: ruby_board.inc file has a shared 'bumper collision map' at 0x08252B10

gSapphireBoardPalette:: @ 0x0826EC10
	.incbin "graphics/stage/sapphire/sapphire_board.gbapal"

gSapphireBoardBG3Tilemap:: @ 0x0826EE10
	.incbin "graphics/stage/sapphire/sapphire_board_bg3_tilemap.bin"

gSapphireBoardCollisionTileDataLayer0:: @ 0x0826FE10
.incbin "data/board_data/collision/sapphire/boardtop_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer0:: @ 0x08271E10
.incbin "data/board_data/collision/sapphire/boardtop_angledata.bin"

gSapphireBoardCollisionTypeDataLayer0:: @ 0x08286A10
.incbin "data/board_data/collision/sapphire/boardtop_typedata.bin"

gSapphireBoardCollisionTileDataLayer1:: @ 0x08291010
.incbin "data/board_data/collision/sapphire/boardbottom_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer1:: @ 0x08293010
.incbin "data/board_data/collision/sapphire/boardbottom_angledata.bin"

gSapphireBoardCollisionTypeDataLayer1:: @ 0x082A5490
.incbin "data/board_data/collision/sapphire/boardbottom_typedata.bin"

gSapphireBoardBG2Tilemap:: @ 0x082AE6D0
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tilemap.bin"

gSapphireBoardCollisionTileDataLayer2:: @ 0x082AF6D0
.incbin "data/board_data/collision/sapphire/topramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer2:: @ 0x082B16D0
.incbin "data/board_data/collision/sapphire/topramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer2:: @ 0x082BE7D0
.incbin "data/board_data/collision/sapphire/topramp_typedata.bin"

gSapphireBoardCollisionTileDataLayer3:: @ 0x082C5050
.incbin "data/board_data/collision/sapphire/hatchexitramp_tiledata.bin"

gSapphireBoardCollisionAngleDataLayer3:: @ 0x082C7050
.incbin "data/board_data/collision/sapphire/hatchexitramp_angledata.bin"

gSapphireBoardCollisionTypeDataLayer3:: @ 0x082CF350
.incbin "data/board_data/collision/sapphire/hatchexitramp_typedata.bin"

gSapphireBoardCompressedTiles1_En:: @ 0x0846FB44
gSapphireBoardCompressedTiles1:: @ 0x082D34D0
	.incbin "graphics/stage/sapphire/sapphire_board_bgramp_tiles.4bpp.lz"

gSapphireBoardCompressedTiles2_En:: @ 0x084718B0
gSapphireBoardCompressedTiles2:: @ 0x082D523C
	.incbin "graphics/stage/sapphire/sapphire_board_bgtop_tiles.4bpp.lz"

gSapphireBoardCompressedTiles2_Fr:: @ 0x0847500C
	.incbin "data/eu/bin/rom_1_0847500C.bin"
gSapphireBoardCompressedTiles2_De:: @ 0x0847875C
	.incbin "data/eu/bin/rom_1_0847875C.bin"
gSapphireBoardCompressedTiles2_It:: @ 0x0847BEB8
	.incbin "data/eu/bin/rom_1_0847BEB8.bin"
gSapphireBoardCompressedTiles2_Es:: @ 0x0847F608
	.incbin "data/eu/bin/rom_1_0847F608.bin"
gSapphireBoardCompressedBGTileBuffer_En:: @ 0x08482D44
gSapphireBoardCompressedBGTileBuffer:: @ 0x082D8998
	.incbin "graphics/stage/sapphire/sapphire_board_bgbottom_tiles.4bpp.lz"



@ Evo Arrows. Named this way for comprehension in folder.
@ E/V/O arrows. Second digit is '0 Top/1 Mid/2 Bottom',
@ First digit is 'variant'.
gSapphireBoardCompressedBGTileBuffer_Fr:: @ 0x08484D8C
	.incbin "data/eu/bin/rom_1_08484D8C.bin"
gSapphireBoardCompressedBGTileBuffer_De:: @ 0x08486DB4
	.incbin "data/eu/bin/rom_1_08486DB4.bin"
gSapphireBoardCompressedBGTileBuffer_It:: @ 0x08488DC4
	.incbin "data/eu/bin/rom_1_08488DC4.bin"
gSapphireBoardCompressedBGTileBuffer_Es:: @ 0x0848ADE0
	.incbin "data/eu/bin/rom_1_0848ADE0.bin"
gSapphireBoardCompressedTiles1_Fr:: @ 0x0848CE20
	.incbin "data/eu/bin/rom_1_0848CE20.bin"
gSapphireBoardCompressedTiles1_De:: @ 0x0848EB64
	.incbin "data/eu/bin/rom_1_0848EB64.bin"
gSapphireBoardCompressedTiles1_It:: @ 0x08490890
	.incbin "data/eu/bin/rom_1_08490890.bin"
gSapphireBoardCompressedTiles1_Es:: @ 0x084925D8
	.incbin "data/eu/bin/rom_1_084925D8.bin"
gSapphireEvoArrow_E_0Lit_Top:: @ 0x082DA9E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_0.4bpp"

gSapphireEvoArrow_E_1Lit_Top:: @ 0x082DAA40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_0.4bpp"

gSapphireEvoArrow_E_2Lit_Top:: @ 0x082DAAA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_0.4bpp"

gSapphireEvoArrow_V_0Lit_Top:: @ 0x082DAB00
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_0.4bpp"

gSapphireEvoArrow_V_1Lit_Top:: @ 0x082DAB60
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_0.4bpp"

gSapphireEvoArrow_V_2Lit_Top:: @ 0x082DABC0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_0.4bpp"

gSapphireEvoArrow_V_3Lit_Top:: @ 0x082DAC20
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_0.4bpp"

gSapphireEvoArrow_O_Under2Lit_Top:: @ 0x082DAC80
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_0.4bpp"

gSapphireEvoArrow_O_2Lit_Top:: @ 0x082DACE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_0.4bpp"

gSapphireEvoArrow_O_3Lit_Top:: @ 0x082DAD40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_0.4bpp"
	.space 0x40

gSapphireEvoArrow_E_0Lit_Mid:: @ 0x082DADE0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_1.4bpp"

gSapphireEvoArrow_E_1Lit_Mid:: @ 0x082DAE40
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_1.4bpp"

gSapphireEvoArrow_E_2Lit_Mid:: @ 0x082DAEA0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_1.4bpp"

gSapphireEvoArrow_V_0Lit_Mid:: @ 0x082DAF00
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_1.4bpp"

gSapphireEvoArrow_V_1Lit_Mid:: @ 0x082DAF60
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_1.4bpp"

gSapphireEvoArrow_V_2Lit_Mid:: @ 0x082DAFC0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_1.4bpp"

gSapphireEvoArrow_V_3Lit_Mid:: @ 0x082DB020
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_1.4bpp"

gSapphireEvoArrow_O_Under2Lit_Mid:: @ 0x082DB080
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_1.4bpp"

gSapphireEvoArrow_O_2Lit_Mid:: @ 0x082DB0E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_1.4bpp"

gSapphireEvoArrow_O_3Lit_Mid:: @ 0x082DB140
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_1.4bpp"
	.space 0x40

gSapphireEvoArrow_E_0Lit_Bot:: @ 0x082DB1E0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_0_2.4bpp"

gSapphireEvoArrow_E_1Lit_Bot:: @ 0x082DB240
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_1_2.4bpp"

gSapphireEvoArrow_E_2Lit_Bot:: @ 0x082DB2A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_e_arrow_2_2.4bpp"

gSapphireEvoArrow_V_0Lit_Bot:: @ 0x082DB300
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_0_2.4bpp"

gSapphireEvoArrow_V_1Lit_Bot:: @ 0x082DB360
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_1_2.4bpp"

gSapphireEvoArrow_V_2Lit_Bot:: @ 0x082DB3C0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_2_2.4bpp"

gSapphireEvoArrow_V_3Lit_Bot:: @ 0x082DB420
    .incbin "graphics/stage/sapphire/evo_arrows/evo_v_arrow_3_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_Under2Lit_Bot:: @ 0x082DB4A0
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_0_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_2Lit_Bot:: @ 0x082DB500
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_1_2.4bpp"
	.space 0x20

gSapphireEvoArrow_O_3Lit_Bot:: @ 0x082DB560
    .incbin "graphics/stage/sapphire/evo_arrows/evo_o_arrow_2_2.4bpp"
	.space 0x40


@ Coin Arrows


gSapphireCoinArrow_1_0Lit_Top:: @ 0x082DB5E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_1_1Lit_Top:: @ 0x082DB640
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p0.4bpp"
    .space 0x20

gSapphireCoinArrow_1_2PlusLit_Top:: @ 0x082DB6A0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p0_filler.4bpp"

gSapphireCoinArrow_5_Under2Lit_Top:: @ 0x082DB720
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p0_filler.4bpp"

gSapphireCoinArrow_5_2Lit_Top:: @ 0x082DB780
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p0_filler.4bpp"

gSapphireCoinArrow_5_3Lit_Top:: @ 0x082DB7E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p0.4bpp"

gSapphireCoinArrow_10_Under2Lit_Top:: @ 0x082DB820
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCoinArrow_10_2Lit_Top:: @ 0x082DB880
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCoinArrow_10_3Lit_Top:: @ 0x082DB8E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p0.4bpp"
	.fill 0x20, 1, 0xDD
	.space 0xA0

gSapphireCoinArrow_1_0Lit_Mid:: @ 0x082DB9E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p1.4bpp"

gSapphireCoinArrow_1_1Lit_Mid:: @ 0x082DBA40
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p1.4bpp"

gSapphireCoinArrow_1_2PlusLit_Mid:: @ 0x082DBAA0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p1_filler.4bpp"

gSapphireCoinArrow_5_Under2Lit_Mid:: @ 0x082DBB20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p1_filler.4bpp"

gSapphireCoinArrow_5_2Lit_Mid:: @ 0x082DBB80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p1_filler.4bpp"

gSapphireCoinArrow_5_3Lit_Mid:: @ 0x082DBBE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p1.4bpp"

gSapphireCoinArrow_10_Under2Lit_Mid:: @ 0x082DBC20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p1_filler.4bpp"

gSapphireCoinArrow_10_2Lit_Mid:: @ 0x082DBC80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p1_filler.4bpp"

gSapphireCoinArrow_10_3Lit_Mid:: @ 0x082DBCE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p1_filler.4bpp"

gSapphireCoinArrow_1_0Lit_Bot:: @ 0x082DBDE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v0_p2.4bpp"

gSapphireCoinArrow_1_1Lit_Bot:: @ 0x082DBE40
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v1_p2.4bpp"

gSapphireCoinArrow_1_2PlusLit_Bot:: @ 0x082DBEA0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g0_v2_p2.4bpp"

gSapphireCoinArrow_5_Under2Lit_Bot:: @ 0x082DBF20
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v0_p2.4bpp"

gSapphireCoinArrow_5_2Lit_Bot:: @ 0x082DBF80
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v1_p2.4bpp"

gSapphireCoinArrow_5_3Lit_Bot:: @ 0x082DBFE0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g1_v2_p2.4bpp"

gSapphireCoinArrow_10_Under2Lit_Bot:: @ 0x082DC020
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v0_p2_filler.4bpp"

gSapphireCoinArrow_10_2Lit_Bot:: @ 0x082DC080
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v1_p2_filler.4bpp"

gSapphireCoinArrow_10_3Lit_Bot:: @ 0x082DC0E0
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2.4bpp"
    .incbin "graphics/stage/sapphire/coin_arrow/coin_arrow_g2_v2_p2_filler.4bpp"


@ Get Arrows

gSapphireGetArrow_G_0Lit_Top:: @ 0x082DC1E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_0.4bpp"

gSapphireGetArrow_G_1Lit_Top:: @ 0x082DC240
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_0.4bpp"

gSapphireGetArrow_G_2PlusLit_Top:: @ 0x082DC2A0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_0Lit_Top:: @ 0x082DC320
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_1Lit_Top:: @ 0x082DC380
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_2Lit_Top:: @ 0x082DC3E0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_0.4bpp"
    .space 0x20

gSapphireGetArrow_E_3Lit_Top:: @ 0x082DC440
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_Under2Lit_Top:: @ 0x082DC4A0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_2Lit_Top:: @ 0x082DC500
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireGetArrow_T_3Lit_Top:: @ 0x082DC560
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_0.4bpp"
    .space 0x40

gSapphireGetArrow_G_0Lit_Mid:: @ 0x082DC5E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_1.4bpp"

gSapphireGetArrow_G_1Lit_Mid:: @ 0x082DC640
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_1.4bpp"

gSapphireGetArrow_G_2PlusLit_Mid:: @ 0x082DC6A0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_1_filler.4bpp"

gSapphireGetArrow_E_0Lit_Mid:: @ 0x082DC720
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_1_filler.4bpp"

gSapphireGetArrow_E_1Lit_Mid:: @ 0x082DC780
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_1_filler.4bpp"

gSapphireGetArrow_E_2Lit_Mid:: @ 0x082DC7E0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1.4bpp"
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_1_filler.4bpp"

gSapphireGetArrow_E_3Lit_Mid:: @ 0x082DC840
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_1.4bpp"

gSapphireGetArrow_T_Under2Lit_Mid:: @ 0x082DC880
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_1.4bpp"

gSapphireGetArrow_T_2Lit_Mid:: @ 0x082DC8E0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_1.4bpp"

gSapphireGetArrow_T_3Lit_Mid:: @ 0x082DC940
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_1.4bpp"
    .space 0x40

gSapphireGetArrow_G_0Lit_Bot:: @ 0x082DC9E0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_0_2.4bpp"

gSapphireGetArrow_G_1Lit_Bot:: @ 0x082DCA40
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_2_2.4bpp"

gSapphireGetArrow_G_2PlusLit_Bot:: @ 0x082DCAA0
    .incbin "graphics/stage/sapphire/get_arrow/get_g_arrow_3_2.4bpp"

gSapphireGetArrow_E_0Lit_Bot:: @ 0x082DCB00
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_0_2.4bpp"

gSapphireGetArrow_E_1Lit_Bot:: @ 0x082DCB60
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_1_2.4bpp"

gSapphireGetArrow_E_2Lit_Bot:: @ 0x082DCBC0
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_2_2.4bpp"

gSapphireGetArrow_E_3Lit_Bot:: @ 0x082DCC20
    .incbin "graphics/stage/sapphire/get_arrow/get_e_arrow_3_2.4bpp"

gSapphireGetArrow_T_Under2Lit_Bot:: @ 0x082DCC80
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_0_2.4bpp"
    .space 0x20

gSapphireGetArrow_T_2Lit_Bot:: @ 0x082DCCE0
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_2_2.4bpp"
    .space 0x20

gSapphireGetArrow_T_3Lit_Bot:: @ 0x082DCD40
    .incbin "graphics/stage/sapphire/get_arrow/get_t_arrow_3_2.4bpp"
    .space 0x80


@ Arrow for bonus multiplier left/right top/bottom digits

gSapphireProgressDigit0_TensTop:: @ 0x082DCE00
    .incbin "graphics/stage/sapphire/progress_digits/digit0_tens_top.4bpp"

gSapphireProgressDigit1_TensTop:: @ 0x082DCE20
    .incbin "graphics/stage/sapphire/progress_digits/digit1_tens_top.4bpp"

gSapphireProgressDigit2_TensTop:: @ 0x082DCE40
    .incbin "graphics/stage/sapphire/progress_digits/digit2_tens_top.4bpp"

gSapphireProgressDigit3_TensTop:: @ 0x082DCE60
    .incbin "graphics/stage/sapphire/progress_digits/digit3_tens_top.4bpp"

gSapphireProgressDigit4_TensTop:: @ 0x082DCE80
    .incbin "graphics/stage/sapphire/progress_digits/digit4_tens_top.4bpp"

gSapphireProgressDigit5_TensTop:: @ 0x082DCEA0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_tens_top.4bpp"

gSapphireProgressDigit6_TensTop:: @ 0x082DCEC0
    .incbin "graphics/stage/sapphire/progress_digits/digit6_tens_top.4bpp"

gSapphireProgressDigit7_TensTop:: @ 0x082DCEE0
    .incbin "graphics/stage/sapphire/progress_digits/digit7_tens_top.4bpp"

gSapphireProgressDigit8_TensTop:: @ 0x082DCF00
    .incbin "graphics/stage/sapphire/progress_digits/digit8_tens_top.4bpp"

gSapphireProgressDigit9_TensTop:: @ 0x082DCF20
    .incbin "graphics/stage/sapphire/progress_digits/digit9_tens_top.4bpp"

gSapphireProgressDigit0_OnesTop:: @ 0x082DCF40
    .incbin "graphics/stage/sapphire/progress_digits/digit0_ones_top.4bpp"

gSapphireProgressDigit1_OnesTop:: @ 0x082DCF60
    .incbin "graphics/stage/sapphire/progress_digits/digit1_ones_top.4bpp"

gSapphireProgressDigit2_OnesTop:: @ 0x082DCF80
    .incbin "graphics/stage/sapphire/progress_digits/digit2_ones_top.4bpp"

gSapphireProgressDigit3_OnesTop:: @ 0x082DCFA0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_ones_top.4bpp"

gSapphireProgressDigit4_OnesTop:: @ 0x082DCFC0
    .incbin "graphics/stage/sapphire/progress_digits/digit4_ones_top.4bpp"

gSapphireProgressDigit5_OnesTop:: @ 0x082DCFE0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_ones_top.4bpp"

gSapphireProgressDigit6_OnesTop:: @ 0x082DD000
    .incbin "graphics/stage/sapphire/progress_digits/digit6_ones_top.4bpp"

gSapphireProgressDigit7_OnesTop:: @ 0x082DD020
    .incbin "graphics/stage/sapphire/progress_digits/digit7_ones_top.4bpp"

gSapphireProgressDigit8_OnesTop:: @ 0x082DD040
    .incbin "graphics/stage/sapphire/progress_digits/digit8_ones_top.4bpp"

gSapphireProgressDigit9_OnesTop:: @ 0x082DD060
    .incbin "graphics/stage/sapphire/progress_digits/digit9_ones_top.4bpp"
    .space 0x180

gSapphireProgressDigit0_TensBot:: @ 0x082DD200
    .incbin "graphics/stage/sapphire/progress_digits/digit0_tens_bot.4bpp"

gSapphireProgressDigit1_TensBot:: @ 0x082DD220
    .incbin "graphics/stage/sapphire/progress_digits/digit1_tens_bot.4bpp"

gSapphireProgressDigit2_TensBot:: @ 0x082DD240
    .incbin "graphics/stage/sapphire/progress_digits/digit2_tens_bot.4bpp"

gSapphireProgressDigit3_TensBot:: @ 0x082DD260
    .incbin "graphics/stage/sapphire/progress_digits/digit3_tens_bot.4bpp"

gSapphireProgressDigit4_TensBot:: @ 0x082DD280
    .incbin "graphics/stage/sapphire/progress_digits/digit4_tens_bot.4bpp"

gSapphireProgressDigit5_TensBot:: @ 0x082DD2A0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_tens_bot.4bpp"

gSapphireProgressDigit6_TensBot:: @ 0x082DD2C0
    .incbin "graphics/stage/sapphire/progress_digits/digit6_tens_bot.4bpp"

gSapphireProgressDigit7_TensBot:: @ 0x082DD2E0
    .incbin "graphics/stage/sapphire/progress_digits/digit7_tens_bot.4bpp"

gSapphireProgressDigit8_TensBot:: @ 0x082DD300
    .incbin "graphics/stage/sapphire/progress_digits/digit8_tens_bot.4bpp"

gSapphireProgressDigit9_TensBot:: @ 0x082DD320
    .incbin "graphics/stage/sapphire/progress_digits/digit9_tens_bot.4bpp"

gSapphireProgressDigit0_OnesBot:: @ 0x082DD340
    .incbin "graphics/stage/sapphire/progress_digits/digit0_ones_bot.4bpp"

gSapphireProgressDigit1_OnesBot:: @ 0x082DD360
    .incbin "graphics/stage/sapphire/progress_digits/digit1_ones_bot.4bpp"

gSapphireProgressDigit2_OnesBot:: @ 0x082DD380
    .incbin "graphics/stage/sapphire/progress_digits/digit2_ones_bot.4bpp"

gSapphireProgressDigit3_OnesBot:: @ 0x082DD3A0
    .incbin "graphics/stage/sapphire/progress_digits/digit3_ones_bot.4bpp"

gSapphireProgressDigit4_OnesBot:: @ 0x082DD3C0
    .incbin "graphics/stage/sapphire/progress_digits/digit4_ones_bot.4bpp"

gSapphireProgressDigit5_OnesBot:: @ 0x082DD3E0
    .incbin "graphics/stage/sapphire/progress_digits/digit5_ones_bot.4bpp"

gSapphireProgressDigit6_OnesBot:: @ 0x082DD400
    .incbin "graphics/stage/sapphire/progress_digits/digit6_ones_bot.4bpp"

gSapphireProgressDigit7_OnesBot:: @ 0x082DD420
    .incbin "graphics/stage/sapphire/progress_digits/digit7_ones_bot.4bpp"

gSapphireProgressDigit8_OnesBot:: @ 0x082DD440
    .incbin "graphics/stage/sapphire/progress_digits/digit8_ones_bot.4bpp"

gSapphireProgressDigit9_OnesBot:: @ 0x082DD460
    .incbin "graphics/stage/sapphire/progress_digits/digit9_ones_bot.4bpp"
    .space 0x1A0


@ Ball power up lights

	.incbin "data/eu/bin/rom_1_08496F60.bin"
gSapphireBallPowerUpLight0off:: @ 0x082DD620
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_off.4bpp"

gSapphireBallPowerUpLight0on:: @ 0x082DD660
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_0_on.4bpp"

gSapphireBallPowerUpLight1off:: @ 0x082DD6A0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_off.4bpp"

gSapphireBallPowerUpLight1on:: @ 0x082DD6E0
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_1_on.4bpp"

gSapphireBallPowerUpLight2off:: @ 0x082DD720
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_off.4bpp"

gSapphireBallPowerUpLight2on:: @ 0x082DD760
    .incbin "graphics/stage/sapphire/ball_power_up_lights/sapphire_ball_power_up_light_2_on.4bpp"


@ 'H' 'o' 'l' 'e' Lights

gSapphireHoleLightH_Off:: @ 0x082DD7A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_off.4bpp"

gSapphireHoleLightH_On:: @ 0x082DD7E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_h_on.4bpp"

gSapphireHoleLightO_Off:: @ 0x082DD820
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_off.4bpp"

gSapphireHoleLightO_On:: @ 0x082DD860
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_o_on.4bpp"

gSapphireHoleLightL_Off:: @ 0x082DD8A0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_off.4bpp"

gSapphireHoleLightL_On:: @ 0x082DD8E0
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_l_on.4bpp"

gSapphireHoleLightE_Off:: @ 0x082DD920
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_off.4bpp"

gSapphireHoleLightE_On:: @ 0x082DD960
    .incbin "graphics/stage/sapphire/hole_lights/sapphire_hole_light_e_on.4bpp"



@ Catch light arrows / Center trap / hatch machine / P square indicator
@ Data is mostly separate... but cuts across rows into an otherwise blank



gSapphireCatchLightState0Top:: @ 0x082DD9A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_top.4bpp"

gSapphireCatchLightState1Top:: @ 0x082DD9E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_top.4bpp"
	.space 0x380

gSapphireCatchLightState0Bot:: @ 0x082DDDA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state0_bot.4bpp"

gSapphireCatchLightState1Bot:: @ 0x082DDDE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_state1_bot.4bpp"

gSapphireTrapIndicatorState0Top:: @ 0x082DDE20
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state0_top.4bpp"

gSapphireTrapIndicatorState1Top:: @ 0x082DDE60
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state1_top.4bpp"

gSapphireTrapIndicatorState2Top:: @ 0x082DDEA0
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state2_top.4bpp"

gSapphireCatchLightSlot0State2Top:: @ 0x082DDEE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_top.4bpp"

gSapphireCatchLightSlot0State3Top:: @ 0x082DDF20
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_top.4bpp"

gSapphireCatchLightSlot1State2Top:: @ 0x082DDF60
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_top.4bpp"

gSapphireCatchLightSlot1State3Top:: @ 0x082DDFA0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_top.4bpp"

gSapphireCatchLightSlot2State2Top:: @ 0x082DDFE0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_top.4bpp"

gSapphireCatchLightSlot2State3Top:: @ 0x082DE020
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_top.4bpp"

gSapphireCatchLightSlot0State4Top:: @ 0x082DE060
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_top.4bpp"

gSapphireCatchLightSlot0State5Top:: @ 0x082DE0A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_top.4bpp"

gSapphireCatchLightSlot1State4Top:: @ 0x082DE0E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_top.4bpp"

gSapphireCatchLightSlot1State5Top:: @ 0x082DE120
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_top.4bpp"

gSapphireCatchLightSlot2State4Top:: @ 0x082DE160
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_top.4bpp"

gSapphireCatchLightSlot2State5Top:: @ 0x082DE1A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_top.4bpp"

gHatchMachineSeg0IdleA:: @ 0x082DE1E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_a.4bpp"

gSapphireTrapIndicatorState0Bot:: @ 0x082DE220
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state0_bot.4bpp"

gSapphireTrapIndicatorState1Bot:: @ 0x082DE260
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state1_bot.4bpp"

gSapphireTrapIndicatorState2Bot:: @ 0x082DE2A0
    .incbin "graphics/stage/sapphire/trap_indicator/trap_state2_bot.4bpp"

gSapphireCatchLightSlot0State2Bot:: @ 0x082DE2E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state2_bot.4bpp"

gSapphireCatchLightSlot0State3Bot:: @ 0x082DE320
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state3_bot.4bpp"

gSapphireCatchLightSlot1State2Bot:: @ 0x082DE360
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state2_bot.4bpp"

gSapphireCatchLightSlot1State3Bot:: @ 0x082DE3A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state3_bot.4bpp"

gSapphireCatchLightSlot2State2Bot:: @ 0x082DE3E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state2_bot.4bpp"

gSapphireCatchLightSlot2State3Bot:: @ 0x082DE420
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state3_bot.4bpp"

gSapphireCatchLightSlot0State4Bot:: @ 0x082DE460
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state4_bot.4bpp"

gSapphireCatchLightSlot0State5Bot:: @ 0x082DE4A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot0_state5_bot.4bpp"

gSapphireCatchLightSlot1State4Bot:: @ 0x082DE4E0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state4_bot.4bpp"

gSapphireCatchLightSlot1State5Bot:: @ 0x082DE520
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot1_state5_bot.4bpp"

gSapphireCatchLightSlot2State4Bot:: @ 0x082DE560
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state4_bot.4bpp"

gSapphireCatchLightSlot2State5Bot:: @ 0x082DE5A0
    .incbin "graphics/stage/sapphire/catch_lights/catch_light_slot2_state5_bot.4bpp"




gHatchMachineSeg0IdleB:: @ 0x082DE5E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_idle_b.4bpp"

gHatchMachineSeg0HitA:: @ 0x082DE620
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_a.4bpp"

gHatchMachineSeg1IdleA:: @ 0x082DE660
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_a.4bpp"

gHatchMachineSeg1HitA:: @ 0x082DE6A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_a.4bpp"

gHatchMachineSeg2IdleA:: @ 0x082DE6E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_a.4bpp"

gHatchMachineSeg2HitA:: @ 0x082DE720
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_a.4bpp"
    .space 0x80

gHatchMachineSeg4IdleA:: @ 0x082DE7E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_a.4bpp"

gHatchMachineSeg4HitA:: @ 0x082DE820
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_a.4bpp"

gHatchMachineSeg5IdleA:: @ 0x082DE860
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_a.4bpp"

gHatchMachineSeg5HitA:: @ 0x082DE8A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_a.4bpp"

gHatchMachineSeg6IdleA:: @ 0x082DE8E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_a.4bpp"

gHatchMachineSeg6HitA:: @ 0x082DE920
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_a.4bpp"

gHatchMachineSeg7IdleA:: @ 0x082DE960
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_a.4bpp"

gHatchMachineSeg7HitA:: @ 0x082DE9A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_a.4bpp"

gHatchMachineSeg8IdleA:: @ 0x082DE9E0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_a.4bpp"

gHatchMachineSeg0HitB:: @ 0x082DEA20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg0_hit_b.4bpp"

gHatchMachineSeg1IdleB:: @ 0x082DEA60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_idle_b.4bpp"

gHatchMachineSeg1HitB:: @ 0x082DEAA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg1_hit_b.4bpp"

gHatchMachineSeg2IdleB:: @ 0x082DEAE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_idle_b.4bpp"

gHatchMachineSeg2HitB:: @ 0x082DEB20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg2_hit_b.4bpp"

gHatchMachineSeg3Idle:: @ 0x082DEB60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_idle.4bpp"

gHatchMachineSeg3Hit:: @ 0x082DEBA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg3_hit.4bpp"

gHatchMachineSeg4IdleB:: @ 0x082DEBE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_idle_b.4bpp"

gHatchMachineSeg4HitB:: @ 0x082DEC20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg4_hit_b.4bpp"

gHatchMachineSeg5IdleB:: @ 0x082DEC60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_idle_b.4bpp"

gHatchMachineSeg5HitB:: @ 0x082DECA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg5_hit_b.4bpp"

gHatchMachineSeg6IdleB:: @ 0x082DECE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_idle_b.4bpp"

gHatchMachineSeg6HitB:: @ 0x082DED20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg6_hit_b.4bpp"

gHatchMachineSeg7IdleB:: @ 0x082DED60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_idle_b.4bpp"

gHatchMachineSeg7HitB:: @ 0x082DEDA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg7_hit_b.4bpp"

gHatchMachineSeg8IdleB:: @ 0x082DEDE0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_idle_b.4bpp"

gHatchMachineSeg8HitA:: @ 0x082DEE20
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_a.4bpp"

gHatchMachineSeg9IdleA:: @ 0x082DEE60
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_a.4bpp"

gHatchMachineSeg9HitA:: @ 0x082DEEA0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_a.4bpp"



gSapphirePSquareFrame0Top:: @ 0x082DEEE0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame0_top.4bpp"

gSapphirePSquareFrame1Top:: @ 0x082DEF20
    .incbin "graphics/stage/sapphire/p_square/p_square_frame1_top.4bpp"

gSapphirePSquareFrame2Top:: @ 0x082DEF60
    .incbin "graphics/stage/sapphire/p_square/p_square_frame2_top.4bpp"

gSapphirePSquareFrame3Top:: @ 0x082DEFA0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame3_top.4bpp"

gSapphirePSquareFrame4Top:: @ 0x082DEFE0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame4_top.4bpp"
    .space 0x200

gHatchMachineSeg8HitB:: @ 0x082DF220
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg8_hit_b.4bpp"

gHatchMachineSeg9IdleB:: @ 0x082DF260
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_idle_b.4bpp"

gHatchMachineSeg9HitB:: @ 0x082DF2A0
    .incbin "graphics/stage/sapphire/hatch_machine/hatch_machine_seg9_hit_b.4bpp"



gSapphirePSquareFrame0Bot:: @ 0x082DF2E0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame0_bot.4bpp"

gSapphirePSquareFrame1Bot:: @ 0x082DF320
    .incbin "graphics/stage/sapphire/p_square/p_square_frame1_bot.4bpp"

gSapphirePSquareFrame2Bot:: @ 0x082DF360
    .incbin "graphics/stage/sapphire/p_square/p_square_frame2_bot.4bpp"

gSapphirePSquareFrame3Bot:: @ 0x082DF3A0
    .incbin "graphics/stage/sapphire/p_square/p_square_frame3_bot.4bpp"




@ Saver light space. Area has more tiles than are actually used.
@ Actual usage is 2 rows of 7 tiles, one row of 6 tiles, one row 2 tiles
@ Data in memory has those as rectangles, and a different offset.
@ Leaving as is, without carving out the 'space' and separate carved zones for the junk data.

gSapphirePSquareFrame4Bot:: @ 0x084A1DA0
	.incbin "data/eu/bin/rom_1_084A1DA0.bin"
gSapphireSaverRow0Tile_Off:: @ 0x082DF660
    .incbin "graphics/stage/sapphire/saver/saver_off_row0.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row0_filler.4bpp"

gSapphireSaverRow0Tile_On:: @ 0x082DF760
    .incbin "graphics/stage/sapphire/saver/saver_on_row0.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_on_row0_filler.4bpp"

gSapphireSaverRow1Tile_Off:: @ 0x082DFA60
    .incbin "graphics/stage/sapphire/saver/saver_off_row1.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row1_filler.4bpp"

gSapphireSaverRow1Tile_On:: @ 0x082DFB60
    .incbin "graphics/stage/sapphire/saver/saver_on_row1.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_on_row1_filler.4bpp"

gSapphireSaverRow2Tile_Off:: @ 0x082DFE80
    .incbin "graphics/stage/sapphire/saver/saver_off_row2.4bpp"
    .incbin "graphics/stage/sapphire/saver/saver_off_row2_filler.4bpp"

gSapphireSaverRow2Tile_On:: @ 0x082DFF80
    .incbin "graphics/stage/sapphire/saver/saver_on_row2.4bpp"
	.space 0x200
	.fill 0xA0, 1, 0xCC

gSapphireSaverRow3Tile_Off:: @ 0x082E02E0
    .incbin "graphics/stage/sapphire/saver/saver_off_row3.4bpp"
	.fill 0xC0, 1, 0xCC



@ Hatch arrow, Catch arrow, Bumper arrow


gSapphireSaverRow3Tile_On:: @ 0x084AAE20
	.incbin "data/eu/bin/rom_1_084AAE20.bin"
gSapphireHatchArrow_R0_Off:: @ 0x082E06A0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row0.4bpp"
    .space 0x40

gSapphireHatchArrow_R0_On:: @ 0x082E0720
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCatchArrow_R0_Off:: @ 0x082E0780
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row0.4bpp"
	.fill 0x20, 1, 0xDD

gSapphireCatchArrow_R0_On:: @ 0x082E0800
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row0.4bpp"

gSapphireBumperArrow_R0_Off:: @ 0x082E0860
    .space 0x80 @ reference, not actually used
	@.incbin "baserom.gba", 0x2E0860, 0x80

gSapphireBumperArrow_R0_On:: @ 0x082E08E0
	.space 0x80 @ reference, not actually used
	.space 0x100

gSapphireHatchArrow_R1_Off:: @ 0x082E0A60
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row1.4bpp"

gSapphireHatchArrow_R1_On:: @ 0x082E0AE0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row1.4bpp"

gSapphireCatchArrow_R1_Off:: @ 0x082E0B60
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row1.4bpp"

gSapphireCatchArrow_R1_On:: @ 0x082E0BE0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row1.4bpp"

gSapphireBumperArrow_R1_Off:: @ 0x082E0C60
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row1.4bpp"

gSapphireBumperArrow_R1_On:: @ 0x082E0CE0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row1.4bpp"
    .space 0x100

gSapphireHatchArrow_R2_Off:: @ 0x082E0E60
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row2.4bpp"

gSapphireHatchArrow_R2_On:: @ 0x082E0EE0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row2.4bpp"

gSapphireCatchArrow_R2_Off:: @ 0x082E0F60
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row2.4bpp"

gSapphireCatchArrow_R2_On:: @ 0x082E0FE0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row2.4bpp"

gSapphireBumperArrow_R2_Off:: @ 0x082E1060
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row2.4bpp"

gSapphireBumperArrow_R2_On:: @ 0x082E10E0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row2.4bpp"
    .space 0x100

gSapphireHatchArrow_R3_Off:: @ 0x082E1260
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_off_row3.4bpp"

gSapphireHatchArrow_R3_On:: @ 0x082E12E0
    .incbin "graphics/stage/sapphire/hatch_arrow/hatch_arrow_on_row3.4bpp"

gSapphireCatchArrow_R3_Off:: @ 0x082E1360
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_off_row3.4bpp"
    .space 0x20

gSapphireCatchArrow_R3_On:: @ 0x082E13E0
    .incbin "graphics/stage/sapphire/catch_arrow/catch_arrow_on_row3.4bpp"
    .space 0x20

gSapphireBumperArrow_R3_Off:: @ 0x082E1460
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_off_row3.4bpp"

gSapphireBumperArrow_R3_On:: @ 0x082E14E0
    .incbin "graphics/stage/sapphire/bumper_arrow/bumper_arrow_on_row3.4bpp"
    .space 0x120



@ arrow for ramp leading to shop: mart/evo

	.incbin "data/eu/bin/rom_1_084AF120.bin"
gSapphireMartArrow_R0_Off:: @ 0x082E1680
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row0.4bpp"

gSapphireMartArrow_R0_On:: @ 0x082E1700
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row0.4bpp"

gSapphireEvoArrow_R0_Off:: @ 0x082E1780
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row0.4bpp"

gSapphireEvoArrow_R0_On:: @ 0x082E1800
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row0.4bpp"
	.space 0x200

gSapphireMartArrow_R1_Off:: @ 0x082E1A80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row1.4bpp"

gSapphireMartArrow_R1_On:: @ 0x082E1B00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row1.4bpp"

gSapphireEvoArrow_R1_Off:: @ 0x082E1B80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row1.4bpp"

gSapphireEvoArrow_R1_On:: @ 0x082E1C00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row1.4bpp"
	.space 0x200

gSapphireMartArrow_R2_Off:: @ 0x082E1E80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row2.4bpp"

gSapphireMartArrow_R2_On:: @ 0x082E1F00
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row2.4bpp"

gSapphireEvoArrow_R2_Off:: @ 0x082E1F80
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row2.4bpp"

gSapphireEvoArrow_R2_On:: @ 0x082E2000
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row2.4bpp"
	.space 0x200

gSapphireMartArrow_R3_Off:: @ 0x082E2280
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_off_row3_filler.4bpp"

gSapphireMartArrow_R3_On:: @ 0x082E2300
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_mart_on_row3_filler.4bpp"

gSapphireEvoArrow_R3_Off:: @ 0x082E2380
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_off_row3_filler.4bpp"

gSapphireEvoArrow_R3_On:: @ 0x082E2400
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3.4bpp"
    .incbin "graphics/stage/sapphire/mart_arrow/mart_arrow_evo_on_row3_filler.4bpp"
	.space 0x620


@ Slingshot wedge lights

	.incbin "data/eu/bin/rom_1_084B45C0.bin"
gSapphire_LSlingshot_Off_R0:: @ 0x082E2AA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row0.4bpp"
	.space 0x40

gSapphire_LSlingshot_On_R0:: @ 0x082E2B00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row0.4bpp"
	.space 0x80

gSapphire_RSlingshot_Off_R0:: @ 0x082E2BA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row0.4bpp"
	.space 0x40

gSapphire_RSlingshot_On_R0:: @ 0x082E2C00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row0.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R1:: @ 0x082E2EA0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row1.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R1:: @ 0x082E2F00
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row1.4bpp"
	.space 0x40

gSapphire_RSlingshot_Off_R1:: @ 0x082E2F80
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row1.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R1:: @ 0x082E2FE0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row1.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R2:: @ 0x082E32A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row2.4bpp"

gSapphire_LSlingshot_On_R2:: @ 0x082E3300
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row2.4bpp"

gSapphire_RSlingshot_Off_R2:: @ 0x082E3360
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row2.4bpp"

gSapphire_RSlingshot_On_R2:: @ 0x082E33C0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row2.4bpp"
	.space 0x280

gSapphire_LSlingshot_Off_R3:: @ 0x082E36A0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row3.4bpp"

gSapphire_LSlingshot_On_R3:: @ 0x082E3700
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row3.4bpp"

gSapphire_RSlingshot_Off_R3:: @ 0x082E3760
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row3.4bpp"

gSapphire_RSlingshot_On_R3:: @ 0x082E37C0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row3.4bpp"
	.space 0x2A0

gSapphire_LSlingshot_Off_R4:: @ 0x082E3AC0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_off_row4.4bpp"
	.space 0x20

gSapphire_LSlingshot_On_R4:: @ 0x082E3B20
    .incbin "graphics/stage/sapphire/slingshot/slingshot_left_on_row4.4bpp"

gSapphire_RSlingshot_Off_R4:: @ 0x082E3B60
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_off_row4.4bpp"
	.space 0x20

gSapphire_RSlingshot_On_R4:: @ 0x082E3BC0
    .incbin "graphics/stage/sapphire/slingshot/slingshot_right_on_row4.4bpp"
	.space 0x2C0


gWailmerWaterFrame0Row0:: @ 0x082E3EC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row0.4bpp"
	.space 0x40

gWailmerWaterFrame1Row0:: @ 0x082E3F40
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row0.4bpp"
	.space 0x40

gWailmerWaterFrame2Row0:: @ 0x082E3FC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row0.4bpp"
	.space 0x2C0

gWailmerWaterFrame0Row1:: @ 0x082E42C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row1.4bpp"

gWailmerWaterFrame1Row1:: @ 0x082E4340
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row1.4bpp"

gWailmerWaterFrame2Row1:: @ 0x082E43C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row1.4bpp"
	.space 0x280

gWailmerWaterFrame0Row2:: @ 0x082E46C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row2.4bpp"
	.space 0x20

gWailmerWaterFrame1Row2:: @ 0x082E4740
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row2.4bpp"
	.space 0x20

gWailmerWaterFrame2Row2:: @ 0x082E47C0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row2.4bpp"
	.space 0x2A0

gWailmerWaterFrame0Row3:: @ 0x082E4AC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame0_row3.4bpp"
	.space 0x20

gWailmerWaterFrame1Row3:: @ 0x082E4B40
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame1_row3.4bpp"
	.space 0x20

gWailmerWaterFrame2Row3:: @ 0x082E4BC0
    .incbin "graphics/stage/sapphire/wailmer_water/water_frame2_row3.4bpp"
	.space 0x2C0

gSapphireBoardBG1Tiles:: @ 0x082E4EE0
	@ loaded to charblock 2; tiles 0-703 are overwritten by the scroll ring
	.incbin "graphics/stage/sapphire/sapphire_board_bg1_tiles.4bpp"

gSapphireBoardBG1Tilemap:: @ 0x082ECEE0
	.incbin "graphics/stage/sapphire/sapphire_board_bg1_tilemap.bin"

.include "data/board_data/dusclops_board.inc"

.include "data/board_data/kecleon_board.inc"

.include "data/board_data/kyogre_board.inc"

.include "data/board_data/groudon_board.inc"

.include "data/board_data/rayquaza_board.inc"

.include "data/board_data/spheal_board.inc"

gPichuKickbackFx_Gfx:: @ 0x08395A4C
	.incbin "graphics/stage/main/pichu_saver_kickback.4bpp"
	.space 0x20

gPikachuKickbackFx_Gfx:: @ 0x08397E6C
	.incbin "graphics/stage/main/pikachu_saver_kickback.4bpp"
	.space 0x20

gCatchTargetCollisionBitmap:: @ 0x0839A28C
	.incbin "data/board_data/collision/catch_target_collision_48x48_typeless.bin"

gMonPortraitsGroup0_Pals:: @ 0x39AB8C
	.incbin "graphics/mon_portraits/treecko_portrait.gbapal"
	.incbin "graphics/mon_portraits/grovyle_portrait.gbapal"
	.incbin "graphics/mon_portraits/sceptile_portrait.gbapal"
	.incbin "graphics/mon_portraits/torchic_portrait.gbapal"
	.incbin "graphics/mon_portraits/combusken_portrait.gbapal"
	.incbin "graphics/mon_portraits/blaziken_portrait.gbapal"
	.incbin "graphics/mon_portraits/mudkip_portrait.gbapal"
	.incbin "graphics/mon_portraits/marshtomp_portrait.gbapal"
	.incbin "graphics/mon_portraits/swampert_portrait.gbapal"
	.incbin "graphics/mon_portraits/poochyena_portrait.gbapal"
	.incbin "graphics/mon_portraits/mightyena_portrait.gbapal"
	.incbin "graphics/mon_portraits/zigzagoon_portrait.gbapal"
	.incbin "graphics/mon_portraits/linoone_portrait.gbapal"
	.incbin "graphics/mon_portraits/wurmple_portrait.gbapal"
	.incbin "graphics/mon_portraits/silcoon_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup1_Pals:: @ 0x39AD8C
	.incbin "graphics/mon_portraits/beautifly_portrait.gbapal"
	.incbin "graphics/mon_portraits/cascoon_portrait.gbapal"
	.incbin "graphics/mon_portraits/dustox_portrait.gbapal"
	.incbin "graphics/mon_portraits/lotad_portrait.gbapal"
	.incbin "graphics/mon_portraits/lombre_portrait.gbapal"
	.incbin "graphics/mon_portraits/ludicolo_portrait.gbapal"
	.incbin "graphics/mon_portraits/seedot_portrait.gbapal"
	.incbin "graphics/mon_portraits/nuzleaf_portrait.gbapal"
	.incbin "graphics/mon_portraits/shiftry_portrait.gbapal"
	.incbin "graphics/mon_portraits/taillow_portrait.gbapal"
	.incbin "graphics/mon_portraits/swellow_portrait.gbapal"
	.incbin "graphics/mon_portraits/wingull_portrait.gbapal"
	.incbin "graphics/mon_portraits/pelipper_portrait.gbapal"
	.incbin "graphics/mon_portraits/ralts_portrait.gbapal"
	.incbin "graphics/mon_portraits/kirlia_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup2_Pals:: @ 0x39AF8C
	.incbin "graphics/mon_portraits/gardevoir_portrait.gbapal"
	.incbin "graphics/mon_portraits/surskit_portrait.gbapal"
	.incbin "graphics/mon_portraits/masquerain_portrait.gbapal"
	.incbin "graphics/mon_portraits/shroomish_portrait.gbapal"
	.incbin "graphics/mon_portraits/breloom_portrait.gbapal"
	.incbin "graphics/mon_portraits/slakoth_portrait.gbapal"
	.incbin "graphics/mon_portraits/vigoroth_portrait.gbapal"
	.incbin "graphics/mon_portraits/slaking_portrait.gbapal"
	.incbin "graphics/mon_portraits/abra_portrait.gbapal"
	.incbin "graphics/mon_portraits/kadabra_portrait.gbapal"
	.incbin "graphics/mon_portraits/alakazam_portrait.gbapal"
	.incbin "graphics/mon_portraits/nincada_portrait.gbapal"
	.incbin "graphics/mon_portraits/ninjask_portrait.gbapal"
	.incbin "graphics/mon_portraits/shedinja_portrait.gbapal"
	.incbin "graphics/mon_portraits/whismur_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette_2.gbapal"

gMonPortraitsGroup3_Pals:: @ 0x39B18C
	.incbin "graphics/mon_portraits/loudred_portrait.gbapal"
	.incbin "graphics/mon_portraits/exploud_portrait.gbapal"
	.incbin "graphics/mon_portraits/makuhita_portrait.gbapal"
	.incbin "graphics/mon_portraits/hariyama_portrait.gbapal"
	.incbin "graphics/mon_portraits/goldeen_portrait.gbapal"
	.incbin "graphics/mon_portraits/seaking_portrait.gbapal"
	.incbin "graphics/mon_portraits/magikarp_portrait.gbapal"
	.incbin "graphics/mon_portraits/gyarados_portrait.gbapal"
	.incbin "graphics/mon_portraits/azurill_portrait.gbapal"
	.incbin "graphics/mon_portraits/marill_portrait.gbapal"
	.incbin "graphics/mon_portraits/azumarill_portrait.gbapal"
	.incbin "graphics/mon_portraits/geodude_portrait.gbapal"
	.incbin "graphics/mon_portraits/graveler_portrait.gbapal"
	.incbin "graphics/mon_portraits/golem_portrait.gbapal"
	.incbin "graphics/mon_portraits/nosepass_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup4_Pals:: @ 0x39B38C
	.incbin "graphics/mon_portraits/skitty_portrait.gbapal"
	.incbin "graphics/mon_portraits/delcatty_portrait.gbapal"
	.incbin "graphics/mon_portraits/zubat_portrait.gbapal"
	.incbin "graphics/mon_portraits/golbat_portrait.gbapal"
	.incbin "graphics/mon_portraits/crobat_portrait.gbapal"
	.incbin "graphics/mon_portraits/tentacool_portrait.gbapal"
	.incbin "graphics/mon_portraits/tentacruel_portrait.gbapal"
	.incbin "graphics/mon_portraits/sableye_portrait.gbapal"
	.incbin "graphics/mon_portraits/mawile_portrait.gbapal"
	.incbin "graphics/mon_portraits/aron_portrait.gbapal"
	.incbin "graphics/mon_portraits/lairon_portrait.gbapal"
	.incbin "graphics/mon_portraits/aggron_portrait.gbapal"
	.incbin "graphics/mon_portraits/machop_portrait.gbapal"
	.incbin "graphics/mon_portraits/machoke_portrait.gbapal"
	.incbin "graphics/mon_portraits/machamp_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup5_Pals:: @ 0x39B58C
	.incbin "graphics/mon_portraits/meditite_portrait.gbapal"
	.incbin "graphics/mon_portraits/medicham_portrait.gbapal"
	.incbin "graphics/mon_portraits/electrike_portrait.gbapal"
	.incbin "graphics/mon_portraits/manectric_portrait.gbapal"
	.incbin "graphics/mon_portraits/plusle_portrait.gbapal"
	.incbin "graphics/mon_portraits/minun_portrait.gbapal"
	.incbin "graphics/mon_portraits/magnemite_portrait.gbapal"
	.incbin "graphics/mon_portraits/magneton_portrait.gbapal"
	.incbin "graphics/mon_portraits/voltorb_portrait.gbapal"
	.incbin "graphics/mon_portraits/electrode_portrait.gbapal"
	.incbin "graphics/mon_portraits/volbeat_portrait.gbapal"
	.incbin "graphics/mon_portraits/illumise_portrait.gbapal"
	.incbin "graphics/mon_portraits/oddish_portrait.gbapal"
	.incbin "graphics/mon_portraits/gloom_portrait.gbapal"
	.incbin "graphics/mon_portraits/vileplume_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup6_Pals:: @ 0x39B78C
	.incbin "graphics/mon_portraits/bellossom_portrait.gbapal"
	.incbin "graphics/mon_portraits/doduo_portrait.gbapal"
	.incbin "graphics/mon_portraits/dodrio_portrait.gbapal"
	.incbin "graphics/mon_portraits/roselia_portrait.gbapal"
	.incbin "graphics/mon_portraits/gulpin_portrait.gbapal"
	.incbin "graphics/mon_portraits/swalot_portrait.gbapal"
	.incbin "graphics/mon_portraits/carvanha_portrait.gbapal"
	.incbin "graphics/mon_portraits/sharpedo_portrait.gbapal"
	.incbin "graphics/mon_portraits/wailmer_portrait.gbapal"
	.incbin "graphics/mon_portraits/wailord_portrait.gbapal"
	.incbin "graphics/mon_portraits/numel_portrait.gbapal"
	.incbin "graphics/mon_portraits/camerupt_portrait.gbapal"
	.incbin "graphics/mon_portraits/slugma_portrait.gbapal"
	.incbin "graphics/mon_portraits/magcargo_portrait.gbapal"
	.incbin "graphics/mon_portraits/torkoal_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup7_Pals:: @ 0x39B98C
	.incbin "graphics/mon_portraits/grimer_portrait.gbapal"
	.incbin "graphics/mon_portraits/muk_portrait.gbapal"
	.incbin "graphics/mon_portraits/koffing_portrait.gbapal"
	.incbin "graphics/mon_portraits/weezing_portrait.gbapal"
	.incbin "graphics/mon_portraits/spoink_portrait.gbapal"
	.incbin "graphics/mon_portraits/grumpig_portrait.gbapal"
	.incbin "graphics/mon_portraits/sandshrew_portrait.gbapal"
	.incbin "graphics/mon_portraits/sandslash_portrait.gbapal"
	.incbin "graphics/mon_portraits/spinda_portrait.gbapal"
	.incbin "graphics/mon_portraits/skarmory_portrait.gbapal"
	.incbin "graphics/mon_portraits/trapinch_portrait.gbapal"
	.incbin "graphics/mon_portraits/vibrava_portrait.gbapal"
	.incbin "graphics/mon_portraits/flygon_portrait.gbapal"
	.incbin "graphics/mon_portraits/cacnea_portrait.gbapal"
	.incbin "graphics/mon_portraits/cacturne_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup8_Pals:: @ 0x39BB8C
	.incbin "graphics/mon_portraits/swablu_portrait.gbapal"
	.incbin "graphics/mon_portraits/altaria_portrait.gbapal"
	.incbin "graphics/mon_portraits/zangoose_portrait.gbapal"
	.incbin "graphics/mon_portraits/seviper_portrait.gbapal"
	.incbin "graphics/mon_portraits/lunatone_portrait.gbapal"
	.incbin "graphics/mon_portraits/solrock_portrait.gbapal"
	.incbin "graphics/mon_portraits/barboach_portrait.gbapal"
	.incbin "graphics/mon_portraits/whiscash_portrait.gbapal"
	.incbin "graphics/mon_portraits/corphish_portrait.gbapal"
	.incbin "graphics/mon_portraits/crawdaunt_portrait.gbapal"
	.incbin "graphics/mon_portraits/baltoy_portrait.gbapal"
	.incbin "graphics/mon_portraits/claydol_portrait.gbapal"
	.incbin "graphics/mon_portraits/lileep_portrait.gbapal"
	.incbin "graphics/mon_portraits/cradily_portrait.gbapal"
	.incbin "graphics/mon_portraits/anorith_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup9_Pals:: @ 0x39BD8C
	.incbin "graphics/mon_portraits/armaldo_portrait.gbapal"
	.incbin "graphics/mon_portraits/igglybuff_portrait.gbapal"
	.incbin "graphics/mon_portraits/jigglypuff_portrait.gbapal"
	.incbin "graphics/mon_portraits/wigglytuff_portrait.gbapal"
	.incbin "graphics/mon_portraits/feebas_portrait.gbapal"
	.incbin "graphics/mon_portraits/milotic_portrait.gbapal"
	.incbin "graphics/mon_portraits/castform_portrait.gbapal"
	.incbin "graphics/mon_portraits/staryu_portrait.gbapal"
	.incbin "graphics/mon_portraits/starmie_portrait.gbapal"
	.incbin "graphics/mon_portraits/kecleon_portrait.gbapal"
	.incbin "graphics/mon_portraits/shuppet_portrait.gbapal"
	.incbin "graphics/mon_portraits/banette_portrait.gbapal"
	.incbin "graphics/mon_portraits/duskull_portrait.gbapal"
	.incbin "graphics/mon_portraits/dusclops_portrait.gbapal"
	.incbin "graphics/mon_portraits/tropius_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup10_Pals:: @ 0x39BF8C
	.incbin "graphics/mon_portraits/chimecho_portrait.gbapal"
	.incbin "graphics/mon_portraits/absol_portrait.gbapal"
	.incbin "graphics/mon_portraits/vulpix_portrait.gbapal"
	.incbin "graphics/mon_portraits/ninetales_portrait.gbapal"
	.incbin "graphics/mon_portraits/pichu_portrait.gbapal"
	.incbin "graphics/mon_portraits/pikachu_portrait.gbapal"
	.incbin "graphics/mon_portraits/raichu_portrait.gbapal"
	.incbin "graphics/mon_portraits/psyduck_portrait.gbapal"
	.incbin "graphics/mon_portraits/golduck_portrait.gbapal"
	.incbin "graphics/mon_portraits/wynaut_portrait.gbapal"
	.incbin "graphics/mon_portraits/wobbuffet_portrait.gbapal"
	.incbin "graphics/mon_portraits/natu_portrait.gbapal"
	.incbin "graphics/mon_portraits/xatu_portrait.gbapal"
	.incbin "graphics/mon_portraits/girafarig_portrait.gbapal"
	.incbin "graphics/mon_portraits/phanpy_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup11_Pals:: @ 0x39C18C
	.incbin "graphics/mon_portraits/donphan_portrait.gbapal"
	.incbin "graphics/mon_portraits/pinsir_portrait.gbapal"
	.incbin "graphics/mon_portraits/heracross_portrait.gbapal"
	.incbin "graphics/mon_portraits/rhyhorn_portrait.gbapal"
	.incbin "graphics/mon_portraits/rhydon_portrait.gbapal"
	.incbin "graphics/mon_portraits/snorunt_portrait.gbapal"
	.incbin "graphics/mon_portraits/glalie_portrait.gbapal"
	.incbin "graphics/mon_portraits/spheal_portrait.gbapal"
	.incbin "graphics/mon_portraits/sealeo_portrait.gbapal"
	.incbin "graphics/mon_portraits/walrein_portrait.gbapal"
	.incbin "graphics/mon_portraits/clamperl_portrait.gbapal"
	.incbin "graphics/mon_portraits/huntail_portrait.gbapal"
	.incbin "graphics/mon_portraits/gorebyss_portrait.gbapal"
	.incbin "graphics/mon_portraits/relicanth_portrait.gbapal"
	.incbin "graphics/mon_portraits/corsola_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"

gMonPortraitsGroup12_Pals:: @ 0x39C38C
	.incbin "graphics/mon_portraits/chinchou_portrait.gbapal"
	.incbin "graphics/mon_portraits/lanturn_portrait.gbapal"
	.incbin "graphics/mon_portraits/luvdisc_portrait.gbapal"
	.incbin "graphics/mon_portraits/horsea_portrait.gbapal"
	.incbin "graphics/mon_portraits/seadra_portrait.gbapal"
	.incbin "graphics/mon_portraits/kingdra_portrait.gbapal"
	.incbin "graphics/mon_portraits/bagon_portrait.gbapal"
	.incbin "graphics/mon_portraits/shelgon_portrait.gbapal"
	.incbin "graphics/mon_portraits/salamence_portrait.gbapal"
	.incbin "graphics/mon_portraits/beldum_portrait.gbapal"
	.incbin "graphics/mon_portraits/metang_portrait.gbapal"
	.incbin "graphics/mon_portraits/metagross_portrait.gbapal"
	.incbin "graphics/mon_portraits/regirock_portrait.gbapal"
	.incbin "graphics/mon_portraits/regice_portrait.gbapal"
	.incbin "graphics/mon_portraits/registeel_portrait.gbapal"
	.incbin "graphics/mon_portraits/silhouette.gbapal"


@ The puff that reveals the catch mon.
gMonPortraitsGroup13_Pals:: @ 0x0857312C
	.incbin "data/eu/bin/rom_1_0857312C.bin"
gCatchMonAppearFx_Gfx:: @ 0x0839C78C
	.incbin "graphics/stage/main/catch_mon_appear_fx.4bpp"
	.space 0x20

gCatchMonAppearFx_Pal:: @ 0x0839DBAC
	.incbin "graphics/stage/main/catch_mon_appear_fx.gbapal"

gCatchTile_RevealTilesGfx:: @ 0x0839DDAC
	.incbin "graphics/stage/main/catch_tile_reveal.4bpp"
	.space 0xA00

gCatchTile_Reveal_Pal:: @ 0x083A05CC
	.incbin "graphics/stage/main/catch_tile_reveal.gbapal"

@ Lightning strike
gCatchTile_BurstStart_Gfx:: @ 0x083A07CC
	.incbin "graphics/stage/main/catch_tile_burst_start.4bpp"
	.space 0x20


@ Tile Grid
gCatchTile_BurstStart_Pal:: @ 0x0857938C
	.incbin "data/eu/bin/rom_1_0857938C.bin"
gCatchTile_BurstStage2_Gfx:: @ 0x083A29EC
	.incbin "graphics/stage/main/catch_tile_burst_stage2.4bpp"
	.space 0x20


gCatchTile_BurstStage2_Pal:: @ 0x08579BCC
	.incbin "data/eu/bin/rom_1_08579BCC.bin"
gCatchTile_BurstStage3_Gfx:: @ 0x083A340C
	.incbin "graphics/stage/main/catch_tile_burst_stage3.4bpp"
	.space 0x20


gCatchTile_BurstStage3_Pal:: @ 0x0857BC0C
	.incbin "data/eu/bin/rom_1_0857BC0C.bin"
gCatchTile_BurstStage4_Gfx:: @ 0x083A562C
	.incbin "graphics/stage/main/catch_tile_burst_stage4.4bpp"
	.space 0x20


gCatchTile_BurstStage4_Pal:: @ 0x0857D44C
	.incbin "data/eu/bin/rom_1_0857D44C.bin"
gAerodactlyFlight_Gfx:: @ 0x083A704C
	.incbin "graphics/stage/ruby/aerodactyl_flight.4bpp"
	.space 0x500
	.incbin "graphics/stage/ruby/aerodactyl_flight_cap.4bpp"

gAerodactlyFlight_Pal:: @ 0x083A806C
	.incbin "graphics/stage/ruby/aerodactyl_flight.gbapal"

gTotodile_Pal:: @ 0x083A808C
	.incbin "graphics/stage/ruby/totodile.gbapal"

gBoardHudTiles_B:: @ 0x083A826C
	.incbin "graphics/stage/main/board_hud_tiles_b.4bpp"
	.space 0x20

gRubyShopSign_Pal:: @ 0x083A8A8C
	.incbin "graphics/stage/ruby/shopsign.gbapal"

gTravelPortrait_Pal:: @ 0x083A8AAC
	.incbin "graphics/stage/main/travel_portrait.gbapal"

gBoardHudTiles_A_En:: @ 0x0857EEEC
gBoardHudTiles_A:: @ 0x083A8ACC
	.incbin "graphics/stage/main/board_hud_tiles_a.4bpp"
	.space 0x20


gBoardHudTiles_A_Fr:: @ 0x0857F30C
	.incbin "data/eu/bin/rom_1_0857F30C.bin"
gBoardHudTiles_A_De:: @ 0x0857F72C
	.incbin "data/eu/bin/rom_1_0857F72C.bin"
gBoardHudTiles_A_It:: @ 0x0857FB4C
	.incbin "data/eu/bin/rom_1_0857FB4C.bin"
gBoardHudTiles_A_Es:: @ 0x0857FF6C
	.incbin "data/eu/bin/rom_1_0857FF6C.bin"
gPortraitAnimFrameGraphics_En:: @ 0x0858038C
	.incbin "data/eu/bin/rom_1_0858038C.bin"
gPortraitAnimFrameGraphics_Fr:: @ 0x0859238C
	.incbin "data/eu/bin/rom_1_0859238C.bin"
gPortraitAnimFrameGraphics_De:: @ 0x085A438C
	.incbin "data/eu/bin/rom_1_085A438C.bin"
gPortraitAnimFrameGraphics_It:: @ 0x085B638C
	.incbin "data/eu/bin/rom_1_085B638C.bin"
gPortraitAnimFrameGraphics_Es:: @ 0x085C838C
	.incbin "data/eu/bin/rom_1_085C838C.bin"
gBallRotationTileGraphics:: @ 0x083BB16C
	.incbin "graphics/stage/main/pokeball_regular.4bpp"
	.incbin "graphics/stage/main/pokeball_great.4bpp"
	.incbin "graphics/stage/main/pokeball_ultra.4bpp"
	.incbin "graphics/stage/main/pokeball_master.4bpp"

gBallUpgradeFx_Gfx:: @ 0x083BD36C
	.incbin "graphics/stage/main/ball_upgrade_fx_frames.4bpp"

gBallSpawnGlowTiles_Type2:: @ 0x083BDF6C
	.incbin "graphics/stage/main/ball_spawn_glow_type2.4bpp"

gBallSpawnGlowTiles_Type1:: @ 0x083BF16C
	.incbin "graphics/stage/main/ball_spawn_glow_type1.4bpp"

gSpoinkEntity_Gfx:: @ 0x083C076C
	.incbin "graphics/stage/main/spoink_launcher.4bpp"

gKyogreSurfacingFx_Gfx:: @ 0x083C13AC
	.incbin "graphics/stage/kyogre/surfacing_fx_frames.4bpp"

gKyogreFreeze_Gfx:: @ 0x083C1A6C
	.incbin "graphics/stage/kyogre/freeze_trap_frames.4bpp"

gRubyChikoritaEntity:: @ 0x083C3C2C
	.incbin "graphics/stage/ruby/chikorita_frames.4bpp"

gChikoritaProjectileTiles:: @ 0x083C542C
	.incbin "graphics/stage/ruby/chikorita_projectile.4bpp"

@ Used when the leaf blade hits one of the linoone
gChikoritaExplosionTiles:: @ 0x083C562C
	.incbin "graphics/stage/ruby/chikorita_projectile_fx.4bpp"

@ Clouds from the intro sequence
gRayquazaSkyBackgroundGfx:: @ 0x083C5A2C
	.incbin "graphics/stage/rayquaza/sky_background.4bpp"

gChinchouBumper_Gfx:: @ 0x083C806C
	.incbin "graphics/stage/main/chinchou_bumper.4bpp"

.include "data/graphics/mon_hatch_sprites.inc"

gPickupIcon1_Gfx:: @ 0x083EB84C
	.incbin "graphics/board_pickups/icon1_xp.4bpp"
	.incbin "data/eu/bin/rom_1_0860C86C.bin"
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

gFlipper_Gfx:: @ 0x083FE44C
	.incbin "graphics/stage/main/flipper_frames.4bpp"

gAlphabetTilesGfx:: @ 0x083FF04C
	.incbin "graphics/stage/main/alphabet.4bpp"

	.incbin "data/eu/bin/rom_1_0862496C.bin"
gSpaceTileGfx:: @ 0x083FFD4C
	.space 0x40  @ Note: this 0x40 space is required, and is used as a tile pair.

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
	.incbin "graphics/stage/main/jirachi_fx.4bpp"

gSapphireStageBasket_Gfx:: @ 0x0844F20C
	.incbin "graphics/stage/sapphire/seedot_basket.4bpp"

gKecleonStageKecleon_Gfx:: @ 0x0844F98C
	.incbin "graphics/stage/kecleon/kecleon.4bpp"

gKecleonStageKecleonFx_Gfx:: @ 0x0845588C
	.incbin "graphics/stage/kecleon/kecleon_fx.4bpp"

gOneUpTreeckoSprite_Gfx:: @ 0x08455E8C
	.incbin "graphics/stage/misc/treecko_1_up_deliverer.4bpp"

gLifeCountDigit_Gfx:: @ 0x0845648C
	.incbin "graphics/stage/misc/life_count_digit.4bpp"

gShroomishBumperHit_Gfx:: @ 0x0845690C
	.incbin "graphics/stage/sapphire/shroomish_bumper_hit.4bpp"

gRubyStageNuzleaf_Gfx:: @ 0x0845710C
	.incbin "graphics/stage/ruby/nuzleaf.4bpp"

gHatchMachineSparkleFx_Gfx:: @ 0x0845A08C
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

gSapphireMinun_Gfx:: @ 0x0847A40C
	.incbin "graphics/stage/sapphire/bumper_minun.4bpp"

gSapphireMinunHeadElectricity_Gfx:: @ 0x0847D10C
	.incbin "graphics/stage/sapphire/bumper_minun_fx.4bpp"

gRubyMakuhitaGfx:: @ 0x0847DF0C
	.incbin "graphics/stage/ruby/makuhita.4bpp"

gLinooneBumperGfx:: @ 0x0847FD0C
	.incbin "graphics/stage/ruby/linoone_side_bumper.4bpp"

@ Shop selection change sheen, and "SOLD OUT" banner.
gShopPortraitOverlayGfx_En:: @ 0x086A4B6C
gShopPortraitOverlayGfx:: @ 0x0847FF0C
	.incbin "graphics/stage/main/shop_portrait_overlay.4bpp"

gShopPortraitOverlayGfx_Fr:: @ 0x086A5A6C
	.incbin "data/eu/bin/rom_1_086A5A6C.bin"
gShopPortraitOverlayGfx_De:: @ 0x086A696C
	.incbin "data/eu/bin/rom_1_086A696C.bin"
gShopPortraitOverlayGfx_It:: @ 0x086A786C
	.incbin "data/eu/bin/rom_1_086A786C.bin"
gShopPortraitOverlayGfx_Es:: @ 0x086A876C
	.incbin "data/eu/bin/rom_1_086A876C.bin"
gDecimalDigitTilesGfx:: @ 0x08480E0C
	.incbin "graphics/stage/main/decimal_digits.4bpp"

gSapphireShopSignTileGfx_En:: @ 0x086A98EC
gSapphireShopSignTileGfx:: @ 0x0848108C
	.incbin "graphics/stage/sapphire/shop_sign_tiles.4bpp"

gSapphireShopSignTileGfx_Fr:: @ 0x086AC5EC
	.incbin "data/eu/bin/rom_1_086AC5EC.bin"
gSapphireShopSignTileGfx_De:: @ 0x086AF2EC
	.incbin "data/eu/bin/rom_1_086AF2EC.bin"
gSapphireShopSignTileGfx_It:: @ 0x086B1FEC
	.incbin "data/eu/bin/rom_1_086B1FEC.bin"
gSapphireShopSignTileGfx_Es:: @ 0x086B4CEC
	.incbin "data/eu/bin/rom_1_086B4CEC.bin"
gRubyTravelVolbeat_Gfx:: @ 0x08483D8C
	.incbin "graphics/stage/ruby/travel_volbeat.4bpp"

gSapphireTravelIllumise_Gfx:: @ 0x08488A0C
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

@ Includes the rope tiles, totodile, and egg
gTotodileEggDelivery_Gfx:: @ 0x0848FD8C
	.incbin "graphics/stage/ruby/totodile.4bpp"

gHatchMachineElevator_Gfx:: @ 0x08490A4C
	.incbin "graphics/stage/sapphire/hatch_machine_elevator.4bpp"

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x08494E4C
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gKyogreTopPosition_Gfx:: @ 0x0849664C
	.incbin "graphics/stage/kyogre/kyogre_top.4bpp"

gKyogreBreach_Gfx:: @ 0x0849B8CC
	.incbin "graphics/stage/kyogre/kyogre_breach.4bpp"

gGroudonAttackFx_Gfx:: @ 0x0849F1CC
	.incbin "graphics/stage/groudon/board_fx.4bpp"
	.space 0x20

gGroudonBoardBoulders_Gfx:: @ 0x084A11EC
	.incbin "graphics/stage/groudon/boulders.4bpp";

gRayquazaTornadoGfx:: @ 0x084A6EEC
	.incbin "graphics/stage/rayquaza/tornado_frames.4bpp"

gRayquazaFlyby_Gfx:: @ 0x084A856C
	.incbin "graphics/stage/rayquaza/wind_board.4bpp"
	.space 0x20

gRayquazaSpriteSheet:: @ 0x084AA18C
	.incbin "graphics/stage/rayquaza/entity_flying.4bpp"

gRayquazaBodyVariantTiles:: @ 0x084AA9EC
	.incbin "graphics/stage/rayquaza/body_variants.4bpp"

gSphealNetGfx:: @ 0x084AF9EC
	.incbin "graphics/stage/spheal/spheal_net.4bpp"

gSphealNetFrontGfx:: @ 0x084AFFEC
	.incbin "graphics/stage/spheal/spheal_net_front.4bpp"

gSphealEntitySprites:: @ 0x084B046C
	.incbin "graphics/stage/spheal/spheal.4bpp"

gSealeoEntitySprites:: @ 0x084B47EC
	.incbin "graphics/stage/spheal/sealeo.4bpp"

gSphealResultsScreenGfx_EnFr:: @ 0x086EB44C
gSphealResultsScreenGfx:: @ 0x084B77EC
	.incbin "graphics/stage/spheal/spheal_results.4bpp"

gSphealResultsScreenGfx_De:: @ 0x086EBC4C
	.incbin "data/eu/bin/rom_1_086EBC4C.bin"
gSphealResultsScreenGfx_It:: @ 0x086EC44C
	.incbin "data/eu/bin/rom_1_086EC44C.bin"
gSphealResultsScreenGfx_Es:: @ 0x086ECC4C
	.incbin "data/eu/bin/rom_1_086ECC4C.bin"
gWhiscash_Gfx:: @ 0x084B7FEC
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelipper_Gfx:: @ 0x084BB16C
	.incbin "graphics/stage/sapphire/pelipper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gChargeFillIndicator_Gfx:: @ 0x084C00EC
	.incbin "graphics/stage/main/charge_fill_indicator.4bpp"

gPikachuSaverTilesGfx:: @ 0x084C07EC
	.incbin "graphics/stage/main/pikachu_saver_tiles.4bpp"

gDxModePikachuObjTiles:: @ 0x084C0C6C
	.incbin "graphics/stage/main/dx_mode_pikachu_obj_tiles.4bpp"

gPichuSaverTilesGfx:: @ 0x084C156C
	.incbin "graphics/stage/main/pichu_saver_tiles.4bpp"

gSapphirePlusle_Gfx:: @ 0x084C1E6C
	.incbin "graphics/stage/sapphire/bumper_plusle.4bpp"

gSapphirePlusleHeadElectricity_Gfx:: @ 0x084C4B6C
	.incbin "graphics/stage/sapphire/bumper_plusle_fx.4bpp"

gMonPortraitsGroup0_Gfx:: @ 0x084C596C
	.incbin "graphics/mon_portraits/treecko_portrait.4bpp"
	.incbin "graphics/mon_portraits/grovyle_portrait.4bpp"
	.incbin "graphics/mon_portraits/sceptile_portrait.4bpp"
	.incbin "graphics/mon_portraits/torchic_portrait.4bpp"
	.incbin "graphics/mon_portraits/combusken_portrait.4bpp"
	.incbin "graphics/mon_portraits/blaziken_portrait.4bpp"
	.incbin "graphics/mon_portraits/mudkip_portrait.4bpp"
	.incbin "graphics/mon_portraits/marshtomp_portrait.4bpp"
	.incbin "graphics/mon_portraits/swampert_portrait.4bpp"
	.incbin "graphics/mon_portraits/poochyena_portrait.4bpp"
	.incbin "graphics/mon_portraits/mightyena_portrait.4bpp"
	.incbin "graphics/mon_portraits/zigzagoon_portrait.4bpp"
	.incbin "graphics/mon_portraits/linoone_portrait.4bpp"
	.incbin "graphics/mon_portraits/wurmple_portrait.4bpp"
	.incbin "graphics/mon_portraits/silcoon_portrait.4bpp"

gMonPortraitsGroup1_Gfx:: @ 0x084C866C
	.incbin "graphics/mon_portraits/beautifly_portrait.4bpp"
	.incbin "graphics/mon_portraits/cascoon_portrait.4bpp"
	.incbin "graphics/mon_portraits/dustox_portrait.4bpp"
	.incbin "graphics/mon_portraits/lotad_portrait.4bpp"
	.incbin "graphics/mon_portraits/lombre_portrait.4bpp"
	.incbin "graphics/mon_portraits/ludicolo_portrait.4bpp"
	.incbin "graphics/mon_portraits/seedot_portrait.4bpp"
	.incbin "graphics/mon_portraits/nuzleaf_portrait.4bpp"
	.incbin "graphics/mon_portraits/shiftry_portrait.4bpp"
	.incbin "graphics/mon_portraits/taillow_portrait.4bpp"
	.incbin "graphics/mon_portraits/swellow_portrait.4bpp"
	.incbin "graphics/mon_portraits/wingull_portrait.4bpp"
	.incbin "graphics/mon_portraits/pelipper_portrait.4bpp"
	.incbin "graphics/mon_portraits/ralts_portrait.4bpp"
	.incbin "graphics/mon_portraits/kirlia_portrait.4bpp"

gMonPortraitsGroup2_Gfx:: @ 0x084CB36C
	.incbin "graphics/mon_portraits/gardevoir_portrait.4bpp"
	.incbin "graphics/mon_portraits/surskit_portrait.4bpp"
	.incbin "graphics/mon_portraits/masquerain_portrait.4bpp"
	.incbin "graphics/mon_portraits/shroomish_portrait.4bpp"
	.incbin "graphics/mon_portraits/breloom_portrait.4bpp"
	.incbin "graphics/mon_portraits/slakoth_portrait.4bpp"
	.incbin "graphics/mon_portraits/vigoroth_portrait.4bpp"
	.incbin "graphics/mon_portraits/slaking_portrait.4bpp"
	.incbin "graphics/mon_portraits/abra_portrait.4bpp"
	.incbin "graphics/mon_portraits/kadabra_portrait.4bpp"
	.incbin "graphics/mon_portraits/alakazam_portrait.4bpp"
	.incbin "graphics/mon_portraits/nincada_portrait.4bpp"
	.incbin "graphics/mon_portraits/ninjask_portrait.4bpp"
	.incbin "graphics/mon_portraits/shedinja_portrait.4bpp"
	.incbin "graphics/mon_portraits/whismur_portrait.4bpp"

gMonPortraitsGroup3_Gfx:: @ 0x084CE06C
	.incbin "graphics/mon_portraits/loudred_portrait.4bpp"
	.incbin "graphics/mon_portraits/exploud_portrait.4bpp"
	.incbin "graphics/mon_portraits/makuhita_portrait.4bpp"
	.incbin "graphics/mon_portraits/hariyama_portrait.4bpp"
	.incbin "graphics/mon_portraits/goldeen_portrait.4bpp"
	.incbin "graphics/mon_portraits/seaking_portrait.4bpp"
	.incbin "graphics/mon_portraits/magikarp_portrait.4bpp"
	.incbin "graphics/mon_portraits/gyarados_portrait.4bpp"
	.incbin "graphics/mon_portraits/azurill_portrait.4bpp"
	.incbin "graphics/mon_portraits/marill_portrait.4bpp"
	.incbin "graphics/mon_portraits/azumarill_portrait.4bpp"
	.incbin "graphics/mon_portraits/geodude_portrait.4bpp"
	.incbin "graphics/mon_portraits/graveler_portrait.4bpp"
	.incbin "graphics/mon_portraits/golem_portrait.4bpp"
	.incbin "graphics/mon_portraits/nosepass_portrait.4bpp"

gMonPortraitsGroup4_Gfx:: @ 0x084D0D6C
	.incbin "graphics/mon_portraits/skitty_portrait.4bpp"
	.incbin "graphics/mon_portraits/delcatty_portrait.4bpp"
	.incbin "graphics/mon_portraits/zubat_portrait.4bpp"
	.incbin "graphics/mon_portraits/golbat_portrait.4bpp"
	.incbin "graphics/mon_portraits/crobat_portrait.4bpp"
	.incbin "graphics/mon_portraits/tentacool_portrait.4bpp"
	.incbin "graphics/mon_portraits/tentacruel_portrait.4bpp"
	.incbin "graphics/mon_portraits/sableye_portrait.4bpp"
	.incbin "graphics/mon_portraits/mawile_portrait.4bpp"
	.incbin "graphics/mon_portraits/aron_portrait.4bpp"
	.incbin "graphics/mon_portraits/lairon_portrait.4bpp"
	.incbin "graphics/mon_portraits/aggron_portrait.4bpp"
	.incbin "graphics/mon_portraits/machop_portrait.4bpp"
	.incbin "graphics/mon_portraits/machoke_portrait.4bpp"
	.incbin "graphics/mon_portraits/machamp_portrait.4bpp"

gMonPortraitsGroup5_Gfx:: @ 0x084D3A6C
	.incbin "graphics/mon_portraits/meditite_portrait.4bpp"
	.incbin "graphics/mon_portraits/medicham_portrait.4bpp"
	.incbin "graphics/mon_portraits/electrike_portrait.4bpp"
	.incbin "graphics/mon_portraits/manectric_portrait.4bpp"
	.incbin "graphics/mon_portraits/plusle_portrait.4bpp"
	.incbin "graphics/mon_portraits/minun_portrait.4bpp"
	.incbin "graphics/mon_portraits/magnemite_portrait.4bpp"
	.incbin "graphics/mon_portraits/magneton_portrait.4bpp"
	.incbin "graphics/mon_portraits/voltorb_portrait.4bpp"
	.incbin "graphics/mon_portraits/electrode_portrait.4bpp"
	.incbin "graphics/mon_portraits/volbeat_portrait.4bpp"
	.incbin "graphics/mon_portraits/illumise_portrait.4bpp"
	.incbin "graphics/mon_portraits/oddish_portrait.4bpp"
	.incbin "graphics/mon_portraits/gloom_portrait.4bpp"
	.incbin "graphics/mon_portraits/vileplume_portrait.4bpp"

gMonPortraitsGroup6_Gfx:: @ 0x084D676C
	.incbin "graphics/mon_portraits/bellossom_portrait.4bpp"
	.incbin "graphics/mon_portraits/doduo_portrait.4bpp"
	.incbin "graphics/mon_portraits/dodrio_portrait.4bpp"
	.incbin "graphics/mon_portraits/roselia_portrait.4bpp"
	.incbin "graphics/mon_portraits/gulpin_portrait.4bpp"
	.incbin "graphics/mon_portraits/swalot_portrait.4bpp"
	.incbin "graphics/mon_portraits/carvanha_portrait.4bpp"
	.incbin "graphics/mon_portraits/sharpedo_portrait.4bpp"
	.incbin "graphics/mon_portraits/wailmer_portrait.4bpp"
	.incbin "graphics/mon_portraits/wailord_portrait.4bpp"
	.incbin "graphics/mon_portraits/numel_portrait.4bpp"
	.incbin "graphics/mon_portraits/camerupt_portrait.4bpp"
	.incbin "graphics/mon_portraits/slugma_portrait.4bpp"
	.incbin "graphics/mon_portraits/magcargo_portrait.4bpp"
	.incbin "graphics/mon_portraits/torkoal_portrait.4bpp"

gMonPortraitsGroup7_Gfx:: @ 0x084D946C
	.incbin "graphics/mon_portraits/grimer_portrait.4bpp"
	.incbin "graphics/mon_portraits/muk_portrait.4bpp"
	.incbin "graphics/mon_portraits/koffing_portrait.4bpp"
	.incbin "graphics/mon_portraits/weezing_portrait.4bpp"
	.incbin "graphics/mon_portraits/spoink_portrait.4bpp"
	.incbin "graphics/mon_portraits/grumpig_portrait.4bpp"
	.incbin "graphics/mon_portraits/sandshrew_portrait.4bpp"
	.incbin "graphics/mon_portraits/sandslash_portrait.4bpp"
	.incbin "graphics/mon_portraits/spinda_portrait.4bpp"
	.incbin "graphics/mon_portraits/skarmory_portrait.4bpp"
	.incbin "graphics/mon_portraits/trapinch_portrait.4bpp"
	.incbin "graphics/mon_portraits/vibrava_portrait.4bpp"
	.incbin "graphics/mon_portraits/flygon_portrait.4bpp"
	.incbin "graphics/mon_portraits/cacnea_portrait.4bpp"
	.incbin "graphics/mon_portraits/cacturne_portrait.4bpp"

gMonPortraitsGroup8_Gfx:: @ 0x084DC16C
	.incbin "graphics/mon_portraits/swablu_portrait.4bpp"
	.incbin "graphics/mon_portraits/altaria_portrait.4bpp"
	.incbin "graphics/mon_portraits/zangoose_portrait.4bpp"
	.incbin "graphics/mon_portraits/seviper_portrait.4bpp"
	.incbin "graphics/mon_portraits/lunatone_portrait.4bpp"
	.incbin "graphics/mon_portraits/solrock_portrait.4bpp"
	.incbin "graphics/mon_portraits/barboach_portrait.4bpp"
	.incbin "graphics/mon_portraits/whiscash_portrait.4bpp"
	.incbin "graphics/mon_portraits/corphish_portrait.4bpp"
	.incbin "graphics/mon_portraits/crawdaunt_portrait.4bpp"
	.incbin "graphics/mon_portraits/baltoy_portrait.4bpp"
	.incbin "graphics/mon_portraits/claydol_portrait.4bpp"
	.incbin "graphics/mon_portraits/lileep_portrait.4bpp"
	.incbin "graphics/mon_portraits/cradily_portrait.4bpp"
	.incbin "graphics/mon_portraits/anorith_portrait.4bpp"

gMonPortraitsGroup9_Gfx:: @ 0x084DF16C
	.incbin "graphics/mon_portraits/armaldo_portrait.4bpp"
	.incbin "graphics/mon_portraits/igglybuff_portrait.4bpp"
	.incbin "graphics/mon_portraits/jigglypuff_portrait.4bpp"
	.incbin "graphics/mon_portraits/wigglytuff_portrait.4bpp"
	.incbin "graphics/mon_portraits/feebas_portrait.4bpp"
	.incbin "graphics/mon_portraits/milotic_portrait.4bpp"
	.incbin "graphics/mon_portraits/castform_portrait.4bpp"
	.incbin "graphics/mon_portraits/staryu_portrait.4bpp"
	.incbin "graphics/mon_portraits/starmie_portrait.4bpp"
	.incbin "graphics/mon_portraits/kecleon_portrait.4bpp"
	.incbin "graphics/mon_portraits/shuppet_portrait.4bpp"
	.incbin "graphics/mon_portraits/banette_portrait.4bpp"
	.incbin "graphics/mon_portraits/duskull_portrait.4bpp"
	.incbin "graphics/mon_portraits/dusclops_portrait.4bpp"
	.incbin "graphics/mon_portraits/tropius_portrait.4bpp"

gMonPortraitsGroup10_Gfx:: @ 0x084E216C
	.incbin "graphics/mon_portraits/chimecho_portrait.4bpp"
	.incbin "graphics/mon_portraits/absol_portrait.4bpp"
	.incbin "graphics/mon_portraits/vulpix_portrait.4bpp"
	.incbin "graphics/mon_portraits/ninetales_portrait.4bpp"
	.incbin "graphics/mon_portraits/pichu_portrait.4bpp"
	.incbin "graphics/mon_portraits/pikachu_portrait.4bpp"
	.incbin "graphics/mon_portraits/raichu_portrait.4bpp"
	.incbin "graphics/mon_portraits/psyduck_portrait.4bpp"
	.incbin "graphics/mon_portraits/golduck_portrait.4bpp"
	.incbin "graphics/mon_portraits/wynaut_portrait.4bpp"
	.incbin "graphics/mon_portraits/wobbuffet_portrait.4bpp"
	.incbin "graphics/mon_portraits/natu_portrait.4bpp"
	.incbin "graphics/mon_portraits/xatu_portrait.4bpp"
	.incbin "graphics/mon_portraits/girafarig_portrait.4bpp"
	.incbin "graphics/mon_portraits/phanpy_portrait.4bpp"

gMonPortraitsGroup11_Gfx:: @ 0x084E4E6C
	.incbin "graphics/mon_portraits/donphan_portrait.4bpp"
	.incbin "graphics/mon_portraits/pinsir_portrait.4bpp"
	.incbin "graphics/mon_portraits/heracross_portrait.4bpp"
	.incbin "graphics/mon_portraits/rhyhorn_portrait.4bpp"
	.incbin "graphics/mon_portraits/rhydon_portrait.4bpp"
	.incbin "graphics/mon_portraits/snorunt_portrait.4bpp"
	.incbin "graphics/mon_portraits/glalie_portrait.4bpp"
	.incbin "graphics/mon_portraits/spheal_portrait.4bpp"
	.incbin "graphics/mon_portraits/sealeo_portrait.4bpp"
	.incbin "graphics/mon_portraits/walrein_portrait.4bpp"
	.incbin "graphics/mon_portraits/clamperl_portrait.4bpp"
	.incbin "graphics/mon_portraits/huntail_portrait.4bpp"
	.incbin "graphics/mon_portraits/gorebyss_portrait.4bpp"
	.incbin "graphics/mon_portraits/relicanth_portrait.4bpp"
	.incbin "graphics/mon_portraits/corsola_portrait.4bpp"

gMonPortraitsGroup12_Gfx:: @ 0x084E756C
	.incbin "graphics/mon_portraits/chinchou_portrait.4bpp"
	.incbin "graphics/mon_portraits/lanturn_portrait.4bpp"
	.incbin "graphics/mon_portraits/luvdisc_portrait.4bpp"
	.incbin "graphics/mon_portraits/horsea_portrait.4bpp"
	.incbin "graphics/mon_portraits/seadra_portrait.4bpp"
	.incbin "graphics/mon_portraits/kingdra_portrait.4bpp"
	.incbin "graphics/mon_portraits/bagon_portrait.4bpp"
	.incbin "graphics/mon_portraits/shelgon_portrait.4bpp"
	.incbin "graphics/mon_portraits/salamence_portrait.4bpp"
	.incbin "graphics/mon_portraits/beldum_portrait.4bpp"
	.incbin "graphics/mon_portraits/metang_portrait.4bpp"
	.incbin "graphics/mon_portraits/metagross_portrait.4bpp"
	.incbin "graphics/mon_portraits/regirock_portrait.4bpp"
	.incbin "graphics/mon_portraits/regice_portrait.4bpp"
	.incbin "graphics/mon_portraits/registeel_portrait.4bpp"



gMonPortraitsGroup13_Gfx:: @ 0x0871F6CC
	.incbin "data/eu/bin/rom_1_0871F6CC.bin"
gRubyBoardShopDoor_Gfx:: @ 0x084ED0CC
	.incbin "graphics/stage/ruby/shop_door.4bpp";


gZigzagoonShockWallIndicator_Gfx:: @ 0x087229CC
	.incbin "data/eu/bin/rom_1_087229CC.bin"
gDusclopsBoardDusclops_Gfx:: @ 0x084EDACC
	.incbin "graphics/stage/dusclops/dusclops.4bpp";

gRubyBoardSharpedo_Gfx:: @ 0x084F5ACC
	.incbin "graphics/stage/ruby/sharpedo.4bpp";

gMartEvoForegroundMenuUx_Gfx:: @ 0x084F61EC
	.incbin "graphics/stage/main/mart_evo_menu_foreground.4bpp";

gMartEvoForegroundMenuUx_Gfx_De:: @ 0x0872CA0C
	.incbin "data/eu/bin/rom_1_0872CA0C.bin"
gRubyBoardShop_Gfx_En:: @ 0x0872D32C
gRubyBoardShop_Gfx:: @ 0x084F6B0C
	.incbin "graphics/stage/ruby/shop.4bpp";

gRubyBoardShop_Gfx_Fr:: @ 0x08730A2C
	.incbin "data/eu/bin/rom_1_08730A2C.bin"
gRubyBoardShop_Gfx_De:: @ 0x0873412C
	.incbin "data/eu/bin/rom_1_0873412C.bin"
gRubyBoardShop_Gfx_It:: @ 0x0873782C
	.incbin "data/eu/bin/rom_1_0873782C.bin"
gRubyBoardShop_Gfx_Es:: @ 0x0873AF2C
	.incbin "data/eu/bin/rom_1_0873AF2C.bin"
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

gRubyBoardRampPrize_Gfx_EnFr:: @ 0x0874332C
gRubyBoardRampPrize_Gfx:: @ 0x084FEF0C
	.incbin "graphics/stage/ruby/ramp_prize.4bpp";

gRubyBoardRampPrize_Gfx_DeItEs:: @ 0x0874372C
	.incbin "data/eu/bin/rom_1_0874372C.bin"
gDusclopsBoardDusclopsBallGrabSwirl_Gfx:: @ 0x084FF30C
	.incbin "graphics/stage/dusclops/dusclops_ball_grab.4bpp";

gKyogreWhirlpoolTrap_Gfx:: @ 0x084FF90C
	.incbin "graphics/stage/kyogre/whirlpool_trap.4bpp"

gMainBoardBallSave_Gfx_En:: @ 0x0874582C
gMainBoardBallSave_Gfx:: @ 0x0850100C
	.incbin "graphics/stage/main/ball_save.4bpp";

gMainBoardBallSave_Gfx_Fr:: @ 0x087470EC
	.incbin "data/eu/bin/rom_1_087470EC.bin"
gMainBoardBallSave_Gfx_De:: @ 0x087489AC
	.incbin "data/eu/bin/rom_1_087489AC.bin"
gMainBoardBallSave_Gfx_It:: @ 0x0874A26C
	.incbin "data/eu/bin/rom_1_0874A26C.bin"
gMainBoardBallSaveLatios_Gfx:: @ 0x085028CC
	.incbin "graphics/stage/main/latios.4bpp";

gMainBoardBallSaveLatiosArm_Gfx:: @ 0x085038CC
	.incbin "graphics/stage/main/latios_arm.4bpp";

gMainBoardBallSave_Gfx_Es:: @ 0x0874CBEC
	.incbin "data/eu/bin/rom_1_0874CBEC.bin"
gMainBoardEndOfBall_Gfx_En:: @ 0x0874E4AC
gMainBoardEndOfBall_Gfx:: @ 0x0850398C
	.incbin "graphics/stage/main/end_of_ball.4bpp";



gEobBonusSummaryCharTiles:: @ 0x087500AC
	.incbin "data/eu/bin/rom_1_087500AC.bin"
gMainBoardEndOfBall_Gfx_Fr:: @ 0x087507CC
	.incbin "data/eu/bin/rom_1_087507CC.bin"
gMainBoardEndOfBall_Gfx_De:: @ 0x087523CC
	.incbin "data/eu/bin/rom_1_087523CC.bin"
gMainBoardEndOfBall_Gfx_It:: @ 0x08753FCC
	.incbin "data/eu/bin/rom_1_08753FCC.bin"
gMainBoardEndOfBall_Gfx_Es:: @ 0x08755BCC
	.incbin "data/eu/bin/rom_1_08755BCC.bin"
gMainBoardEvoBanner_Gfx:: @ 0x08505BCC
	.incbin "graphics/stage/main/evo_banner.4bpp";

	.incbin "data/eu/bin/rom_1_0875BB4C.bin"
gMainBoardGameOverText_Gfx_EnFrDeIt:: @ 0x0876C94C
gMainBoardGameOverText_Gfx:: @ 0x08509F4C
	.incbin "graphics/stage/main/game_over_text.4bpp";

gMainBoardGameOverText_Gfx_Es:: @ 0x0876CD4C
	.incbin "data/eu/bin/rom_1_0876CD4C.bin"
gMainBoardJirachiBanner_Gfx:: @ 0x0850A34C
	.incbin "graphics/stage/main/jirachi_banner.4bpp";

gMainBoardTravel_Gfx:: @ 0x0850E6CC
	.incbin "graphics/stage/main/travel.4bpp";

	.incbin "data/eu/bin/rom_1_08773AAC.bin"
gPauseMenuText_Gfx:: @ 0x08510CAC
	.incbin "graphics/stage/main/pause_menu_text.4bpp";

gFieldIntroText_Gfx_En:: @ 0x0877D3CC
	.incbin "data/eu/bin/rom_1_0877D3CC.bin"
gFieldIntroText_Gfx_Fr:: @ 0x0877D50C
	.incbin "data/eu/bin/rom_1_0877D50C.bin"
gFieldIntroText_Gfx_De:: @ 0x0877D64C
	.incbin "data/eu/bin/rom_1_0877D64C.bin"
gFieldIntroText_Gfx_It:: @ 0x0877D78C
	.incbin "data/eu/bin/rom_1_0877D78C.bin"
gFieldIntroText_Gfx_Es:: @ 0x0877D8CC
	.incbin "data/eu/bin/rom_1_0877D8CC.bin"
gDusclopsBoardDuskull_Gfx:: @ 0x08510E4C
	.incbin "graphics/stage/dusclops/duskull.4bpp";

gSapphireBoardZigzagoon_Gfx:: @ 0x08512C4C
	.incbin "graphics/stage/sapphire/zigzagoon.4bpp";

gBallSaver_Ruby_Pal:: @ 0x08514F4C
	.incbin "graphics/stage/ruby/ball_saver.gbapal"

gBallSaver_Sapphire_Pal:: @ 0x08514F6C
	.incbin "graphics/stage/sapphire/ball_saver.gbapal"

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

gEndOfBallBonus_Ruby_Pal:: @ 0x08521FAC
	.incbin "graphics/stage/ruby/end_of_ball_bonus.gbapal"

gEndOfBallBonus_Sapphire_Pal:: @ 0x08521FCC
	.incbin "graphics/stage/sapphire/end_of_ball_bonus.gbapal"

gMainBoardEvoBanner_Pal:: @ 0x085221AC
    .incbin "graphics/stage/main/evo_banner.gbapal"

gMainCatchModeBanner_Gfx:: @ 0x085223AC
	.incbin "graphics/stage/main/catch_mode_banner.4bpp"
	.space 0xA0

	.incbin "data/eu/bin/rom_1_0879338C.bin"
gMainCatchModeBanner_Pal:: @ 0x085267CC
    .incbin "graphics/stage/main/catch_mode_banner.gbapal"

gMainBoardJirachiBanner_Pal:: @ 0x085269CC
    .incbin "graphics/stage/main/jirachi_banner.gbapal"

gMainBoardTravel_Pal:: @ 0x08526BCC
    .incbin "graphics/stage/main/travel.gbapal"

gSapphireBoardZigzagoonFx_Gfx:: @ 0x08526DCC
	.incbin "graphics/stage/sapphire/zigzagoon_fx.4bpp";

@ Unreferenced blob, most likely a leftover tilemap. This has mostly ascending id values with runs of repeats.
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
    .2byte SE_BUMPER_HIT, SE_CYNDAQUIL_EGG_GUARD_HIT, SE_AERODACTYL_EGG_FLIGHT, SE_CYNDAQUIL_BALL_EJECT_AFTER_EGG_ARRIVAL, SE_RUBY_MART_GATE_OPEN
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
	.byte 1, 10, 0, 10, 5, 10, 4, 10, 6, 10

gOptionsStateFuncs:: @ 0x08527F08
	.4byte Options_LoadGraphics
	.4byte Options_HandleInput
	.4byte Options_State2_51C3C
	.4byte Options_State3_51C60

.include "data/pokedex_entries/species_rs_to_cry_id.inc"

gOptionsText_Tilemap_En:: @ 0x087A5C68
gOptionsText_Tilemap:: @ 0x08528028
	.incbin "graphics/options/text.bin"

gOptionsText_Gfx_En:: @ 0x087A6468
gOptionsText_Gfx:: @ 0x08528828
	.incbin "graphics/options/text.4bpp"
	.space 0x20

gOptionsText_Tilemap_De:: @ 0x087A7C88
	.incbin "data/eu/bin/rom_1_087A7C88.bin"
gOptionsText_Gfx_De:: @ 0x087A8488
	.incbin "data/eu/bin/rom_1_087A8488.bin"
gOptionsText_Tilemap_Fr:: @ 0x087A9CA8
	.incbin "data/eu/bin/rom_1_087A9CA8.bin"
gOptionsText_Gfx_Fr:: @ 0x087AA4A8
	.incbin "data/eu/bin/rom_1_087AA4A8.bin"
gOptionsText_Tilemap_It:: @ 0x087ABCC8
	.incbin "data/eu/bin/rom_1_087ABCC8.bin"
gOptionsText_Gfx_It:: @ 0x087AC4C8
	.incbin "data/eu/bin/rom_1_087AC4C8.bin"
gOptionsText_Tilemap_Es:: @ 0x087ADCE8
	.incbin "data/eu/bin/rom_1_087ADCE8.bin"
gOptionsText_Gfx_Es:: @ 0x087AE4E8
	.incbin "data/eu/bin/rom_1_087AE4E8.bin"
gOptionsBackground_Tilemap_EnDe:: @ 0x087AFD08
gOptionsBackground_Tilemap:: @ 0x0852A048
	.incbin "graphics/options/background.bin"

gOptionsBackground_Gfx_EnFr:: @ 0x087B0508
gOptionsBackground_Gfx:: @ 0x0852A848
	.incbin "graphics/options/background.4bpp"
	.space 0x20

gOptionsBackground_Gfx_De:: @ 0x087B1128
	.incbin "data/eu/bin/rom_1_087B1128.bin"
gOptionsBackground_Tilemap_Fr:: @ 0x087B1D48
	.incbin "data/eu/bin/rom_1_087B1D48.bin"
gOptionsBackground_Tilemap_It:: @ 0x087B2548
	.incbin "data/eu/bin/rom_1_087B2548.bin"
gOptionsBackground_Gfx_It:: @ 0x087B2D48
	.incbin "data/eu/bin/rom_1_087B2D48.bin"
gOptionsBackground_Tilemap_Es:: @ 0x087B3968
	.incbin "data/eu/bin/rom_1_087B3968.bin"
gOptionsBackground_Gfx_Es:: @ 0x087B4168
	.incbin "data/eu/bin/rom_1_087B4168.bin"
gOptionsBackground_Pals:: @ 0x0852B468
	.incbin "graphics/options/background.gbapal"

gGBAButtonIcons_Pals:: @ 0x0852B668
	.incbin "graphics/gba_buttons.gbapal"

gOptionsSprites_Gfx_En:: @ 0x087B5188
gOptionsSprites_Gfx:: @ 0x0852B868
	.incbin "graphics/options/sprites.4bpp"

.align 2
gOptionsSprites_Gfx_De:: @ 0x087B71A8
	.incbin "data/eu/bin/rom_1_087B71A8.bin"
gOptionsSprites_Gfx_Fr:: @ 0x087B91C8
	.incbin "data/eu/bin/rom_1_087B91C8.bin"
gOptionsSprites_Gfx_It:: @ 0x087BB1E8
	.incbin "data/eu/bin/rom_1_087BB1E8.bin"
gOptionsSprites_Gfx_Es:: @ 0x087BD208
	.incbin "data/eu/bin/rom_1_087BD208.bin"
