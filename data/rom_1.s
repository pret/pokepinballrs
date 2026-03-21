.section .rodata
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
	.4byte IntroScene1_LoadGraphics
	.4byte IntroScene1_AnimateTitleReveal
	.4byte IntroScene1_ZoomOutTitle
	.4byte IntroScene1_ResetAfterZoom
	.4byte IntroScene1_AnimateSecondReveal
	.4byte IntroScene1_FadeInOverlay
	.4byte IntroScene1_ScrollAndFade
	.4byte IntroScene1_ParallaxScroll
	.4byte nullsub_4
	.4byte IntroScene1_FinalScroll
	.4byte nullsub_5
	.4byte nullsub_17
	.4byte IntroScene1_BeginFadeOut
	.4byte IntroScene1_ClearGraphics
	.4byte IntroScene2_LoadGraphics
	.4byte nullsub_6
	.4byte IntroScene2_ScrollBGs
	.4byte nullsub_7
	.4byte IntroScene2_FinalScrollAndFade
	.4byte IntroScene2_ClearGraphics
	.4byte IntroScene3_LoadGraphics
	.4byte IntroScene3_ScrollIn
	.4byte IntroScene3_AnimateAndSwapBG
	.4byte nullsub_8
	.4byte IntroScene3_BeginFadeOut
	.4byte IntroScene3_ClearGraphics
	.4byte IntroScene4_LoadGraphics
	.4byte nullsub_9
	.4byte IntroScene4_ScrollBGs
	.4byte nullsub_10
	.4byte IntroScene4_FinalScrollAndFade
	.4byte IntroScene4_ClearGraphics
	.4byte IntroScene5_LoadGraphics
	.4byte IntroScene5_ScrollIn
	.4byte IntroScene5_AnimateEntities
	.4byte nullsub_11
	.4byte IntroScene5_FadeOutAndClearOAM
	.4byte IntroScene5_ClearGraphics
	.4byte IntroScene6_LoadGraphics
	.4byte IntroScene6_AnimateStarsScrollIn
	.4byte IntroScene6_ContinueBounce
	.4byte IntroScene6_FadeOutAndClearOAM
	.4byte IntroScene6_AdvanceIndex
	.4byte IntroScene7_LoadGraphics
	.4byte IntroScene7_ScrollWaves1
	.4byte IntroScene7_ScrollWaves2
	.4byte IntroScene7_ScrollWaves3
	.4byte IntroScene7_WailmerAndAllWaves
	.4byte IntroScene7_WailmerShakeAndShrink
	.4byte IntroScene7_BeginFadeOut
	.4byte IntroScene7_ClearGraphics
	.4byte IntroScene8a_LoadGraphics
	.4byte IntroScene8a_WaitForExplosion
	.4byte IntroScene8a_ExplodeAndLaunch
	.4byte IntroScene8a_DriftAndFade
	.4byte nullsub_12
	.4byte nullsub_13
	.4byte IntroScene8a_FadeOutAndClearOAM
	.4byte IntroScene8a_ClearAndResetOAM
	.4byte IntroScene8b_LoadGraphics
	.4byte IntroScene8b_BallFlyIn
	.4byte IntroScene8b_ScrollClouds
	.4byte IntroScene8b_CloudSpriteAndWhiteFlash
	.4byte nullsub_14
	.4byte IntroScene8b_FadeOutMusic
	.4byte IntroScene8b_EndIntro

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
	.incbin "baserom.gba", 0x7DD00, 0x2000

gEReaderOverlay_Tilemap:: @ 0x0807FD00
	.incbin "baserom.gba", 0x7FD00, 0x800

gEReaderBackground_Gfx:: @ 0x08080500
	.incbin "graphics/ereader/background.4bpp"
	.space 0x20

gEReaderBackground_Pals:: @ 0x08081D20
	.incbin "baserom.gba", 0x81D20, 0x200

gPokedexBg1_Tilemap:: @ 0x08081F20
	.incbin "graphics/pokedex/bg1_tilemap.bin"

gPokedexBgText_Gfx:: @ 0x08082720
	.incbin "graphics/pokedex/bg_text.4bpp"
	.space 0x20

gPokedexInfoWindowTiles:: @ 0x08086B40
	.incbin "baserom.gba", 0x86B40, 0x800

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
	.incbin "baserom.gba", 0x947A0, 0x1000

gHighScoreText_Gfx:: @ 0x080957A0
	.incbin "graphics/high_score/text.4bpp"
	.space 0x20

gHighScoreBallWatermark_Tilemap:: @ 0x08099FC0
	.incbin "baserom.gba", 0x99FC0, 0x1000

gHighScoreBallWatermark_Gfx:: @ 0x0809AFC0
	.incbin "graphics/high_score/ball_watermark.4bpp"
	.space 0x20

gHighScoreBG_Pals:: @ 0x0809DBE0
	.incbin "baserom.gba", 0x9DBE0, 0x200

gHighScoreSprite_Pals:: @ 0x0809DDE0
	.incbin "baserom.gba", 0x9DDE0, 0x200

gHighScoreDialogs_Gfx:: @ 0x0809DFE0
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20

gFieldSelectBG0Tilemap:: @ 0x080A2400
	.incbin "baserom.gba", 0xA2400, 0x800

.include "data/graphics/field_select.inc"

gEReaderText_Gfx:: @ 0x080ACC60
	.incbin "graphics/ereader/text.4bpp"
	.space 0x240

gIntroScene1Sprites_Pals:: @ 0x080B3AA0
	.incbin "graphics/intro/scene_1_sprites.gbapal"

gIntroScene1_BG3Tilemap:: @ 0x080B3CA0
	.incbin "baserom.gba", 0xB3CA0, 0x800

gIntroScene1Text_Gfx:: @ 0x080B44A0
	.incbin "graphics/intro/scene_1_text.4bpp"
	.space 0x20

gIntroScene1_BG0Tilemap:: @ 0x080B9CC0
	.incbin "baserom.gba", 0xB9CC0, 0x1800

gIntroScene1_BG2Tilemap:: @ 0x080BB4C0
	.incbin "baserom.gba", 0xBB4C0, 0x1000

gIntroScene1_BG1Tilemap:: @ 0x080BC4C0
	.incbin "baserom.gba", 0xBC4C0, 0x1000

gIntroScene1Ball_Gfx:: @ 0x080BD4C0
	.incbin "graphics/intro/scene_1_ball.4bpp"
	.space 0x20

gIntroScene1Sprites_Gfx:: @ 0x080C3CE0
	.incbin "graphics/intro/scene_1_sprites.4bpp"

gIntroScene2_Pal:: @ 0x080CBCE0
	.incbin "baserom.gba", 0xCBCE0, 0x200

gIntroScene2_BG3Tilemap:: @ 0x080CBEE0
	.incbin "baserom.gba", 0xCBEE0, 0x800

gIntroScene2Sprites_Gfx:: @ 0x080CC6E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pichu/pikachu
	.incbin "graphics/intro/scene_2_sprites.4bpp"
	.space 0x20

gIntroScene2_BG0Tiles:: @ 0x080D0700
	.incbin "baserom.gba", 0xD0700, 0x2000

gIntroScene2_BG1Tiles:: @ 0x080D2700
	.incbin "baserom.gba", 0xD2700, 0x2000

gIntroScene3_Pal:: @ 0x080D4700
	.incbin "baserom.gba", 0xD4700, 0x200

gIntroScene3_BG2Tilemap:: @ 0x080D4900
	.incbin "baserom.gba", 0xD4900, 0x1000

gIntroScene3_BG3Tilemap:: @ 0x080D5900
	.incbin "baserom.gba", 0xD5900, 0x800

gIntroScene3Sprites_Gfx:: @ 0x080D6100
	@ intro pane with treeko, pinball, flipper
	.incbin "graphics/intro/scene_3_sprites.4bpp"
	.space 0x20

gIntroScene3_BG1Tilemap:: @ 0x080DCD20
	.incbin "baserom.gba", 0xDCD20, 0x800

gIntroScene3_BG1TilemapA:: @ 0x080DD520
	.incbin "baserom.gba", 0xDD520, 0x800

gIntroScene3_BG1TilemapB:: @ 0x080DDD20
	.incbin "baserom.gba", 0xDDD20, 0x800

gIntroScene3_BG0Tilemap:: @ 0x080DE520
	.incbin "baserom.gba", 0xDE520, 0x1000

gIntroScene3Treecko_Gfx:: @ 0x080DF520
	.incbin "graphics/intro/treecko.4bpp"
	.space 0x20

gIntroScene4_Pal:: @ 0x080E1540
	.incbin "baserom.gba", 0xE1540, 0x200

gIntroScene4_BG3Tilemap:: @ 0x080E1740
	.incbin "baserom.gba", 0xE1740, 0x800

gIntroScene4Sprites_Gfx:: @ 0x080E1F40
	.incbin "graphics/intro/scene_4_sprites.4bpp"

gIntroScene4_BG0Tiles:: @ 0x080E5F60
	.incbin "baserom.gba", 0xE5F60, 0x2000

gIntroScene4_BG1Tiles:: @ 0x080E7F60
	.incbin "baserom.gba", 0xE7F60, 0x2000

gIntroScene5_Pal:: @ 0x080E9F60
	.incbin "baserom.gba", 0xE9F60, 0x200

gIntroScene5_BG2Tilemap:: @ 0x080EA160
	.incbin "baserom.gba", 0xEA160, 0x1000

gIntroScene5_BG1Tiles:: @ 0x080EB160
	.incbin "baserom.gba", 0xEB160, 0x1000

gIntroScene5_BG3Tilemap:: @ 0x080EC160
	.incbin "baserom.gba", 0xEC160, 0x800

gIntroScene5Text_Gfx:: @ 0x080EC960
	.incbin "graphics/intro/scene_5_text.4bpp"
	.space 0x20

gIntroScene5_BG0Tiles:: @ 0x080F1980
	.incbin "baserom.gba", 0xF1980, 0x800

gIntroScene5Sprites_Gfx:: @ 0x080F2180
	.incbin "graphics/intro/scene_5_sprites.4bpp"
	.space 0x20
	.incbin "baserom.gba", 0xF51A0, 0x1000

gIntroScene6_Pal:: @ 0x080F61A0
	.incbin "baserom.gba", 0xF61A0, 0x200

gIntroScene6_BG3Tilemap:: @ 0x080F63A0
	.incbin "baserom.gba", 0xF63A0, 0x800

gIntroScene6Sprites_Gfx:: @ 0x080F6BA0
	.incbin "graphics/intro/scene_6_sprites.4bpp"
	.space 0x20

gIntroScene6_BG2Tilemap:: @ 0x080FCFC0
	.incbin "baserom.gba", 0xFCFC0, 0x800

gIntroScene6_BG0Tilemap:: @ 0x080FD7C0
	.incbin "baserom.gba", 0xFD7C0, 0x800

gIntroScene6_BG1Tiles:: @ 0x080FDFC0
	.incbin "baserom.gba", 0xFDFC0, 0x2000

gIntroScene6Stars_Gfx:: @ 0x080FFFC0
	.incbin "graphics/intro/scene_6_stars.4bpp"
	.space 0x20

gIntroScene7_Pal:: @ 0x08100FE0
	.incbin "baserom.gba", 0x100FE0, 0x200

gIntroScene7_BG3Tilemap:: @ 0x081011E0
	.incbin "baserom.gba", 0x1011E0, 0x800

gIntroScene7Sprites_Gfx:: @ 0x081019E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pelipper, makuhita, spoink

	.incbin "graphics/intro/scene_7_sprites.4bpp"
	.space 0x20

gIntroScene7_BG2Tiles:: @ 0x08106A00
	.incbin "baserom.gba", 0x106A00, 0x2000

gIntroScene7_BG0Tiles:: @ 0x08108A00
	.incbin "baserom.gba", 0x108A00, 0x2000

gIntroScene7_BG1Tiles:: @ 0x0810AA00
	.incbin "baserom.gba", 0x10AA00, 0x2000

gIntroScene7Wailmer_Gfx:: @ 0x0810CA00
	.incbin "graphics/intro/scene_7_wailmer.4bpp"
	.space 0x20

gIntroScene8a_Pal:: @ 0x0810EA20
	.incbin "baserom.gba", 0x10EA20, 0x200

gIntroScene8a_BG2Tilemap:: @ 0x0810EC20
	.incbin "baserom.gba", 0x10EC20, 0x800

gIntroScene7Explosion_Gfx:: @ 0x0810F420
	.incbin "graphics/intro/scene_7_explosion.4bpp"
	.space 0x20

gIntroScene7WailmerLaunch_Gfx:: @ 0x08112840
	.incbin "graphics/intro/scene_7_wailmer_launch.4bpp"
	.space 0x20

gIntroScene8b_Pal:: @ 0x08115860
	.incbin "baserom.gba", 0x115860, 0x200

gIntroScene8b_BG3Tilemap:: @ 0x08115A60
	.incbin "baserom.gba", 0x115A60, 0x800

gIntroScene8Clouds_Gfx:: @ 0x08116260
	.incbin "graphics/intro/scene_8_clouds.4bpp"
	.space 0x20

gIntroScene8Ball_Gfx:: @ 0x08118680
	.incbin "graphics/intro/scene_8_ball.4bpp"

	.incbin "baserom.gba", 0x11F680, 0x1640

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

gAreaToSpeciesTable:: @ 0x08137928
	.incbin "baserom.gba", 0x137928, 0x1C

gPondDialAnimFrames:: @ 0x08137944
	.incbin "baserom.gba", 0x137944, 0x24

gPondBumperTransitionFrames:: @ 0x08137968
	.2byte 0,2,3,4,5,6,7,10,10,10,7,6,5,4,3,2,1,0
	@.incbin "baserom.gba", 0x137968, 0x24

gLotadBobOffsets:: @ 0x0813798C
	.incbin "baserom.gba", 0x13798C, 0xC

gChinchouBumperPalettes:: @ 0x08137998
	.incbin "baserom.gba", 0x137998, 0x20

gLotadBumperPalettes:: @ 0x081379B8
	.incbin "baserom.gba", 0x1379B8, 0x20

gWhiscashPalettes:: @ 0x081379D8
	.incbin "baserom.gba", 0x1379D8, 0xE0

gBumperAnimFrames:: @ 0x08137AB8
	.incbin "baserom.gba", 0x137AB8, 0x84

gFieldPaletteVariants:: @ 0x08137B3C
	.incbin "baserom.gba", 0x137B3C, 0x20

gUnknown_08137B5C:: @ 0x08137B5C
	.incbin "baserom.gba", 0x137B5C, 0x160

gPelipperFlyAnimTable:: @ 0x08137CBC
	.incbin "baserom.gba", 0x137CBC, 0x1A

gBumperMosaicValues:: @ 0x08137CD6
	.incbin "baserom.gba", 0x137CD6, 0xC

gShopSignLoopFrames:: @ 0x08137CE2
	.incbin "baserom.gba", 0x137CE2, 0x14

gShopSignIntroFrames:: @ 0x08137CF6
	.incbin "baserom.gba", 0x137CF6, 0x10

gShopSignTransitionFrames:: @ 0x08137D06
	.incbin "baserom.gba", 0x137D06, 0x3A

gDusclopsBossAnimFrames:: @ 0x08137D40
	.incbin "baserom.gba", 0x137D40, 0x8

gWhirlwindGrabAnimFrameIndices:: @ 0x08137D48
	.incbin "baserom.gba", 0x137D48, 0x18

gSphealScoreDigitSpriteIndices:: @ 0x08137D60
	.incbin "baserom.gba", 0x137D60, 0x18

gPauseMenuSpriteOffsets:: @ 0x08137D78
	.incbin "baserom.gba", 0x137D78, 0x2C

gPauseMenuTextAnimFrames:: @ 0x08137DA4
	.incbin "baserom.gba", 0x137DA4, 0x1A

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

gDebugMenuCursorGfx:: @ 0x08137E00
	.incbin "baserom.gba", 0x137E00, 0x4

gPinballGameStateFuncs:: @ 0x08137E04
	.4byte PinballGame_State0_49ED4 @ called once upon loading the field
	.4byte PinballGame_State1_4AAD8 @ called once every frame while playing
	.4byte PinballGame_State2_4ABC8 @ called once on game over (losing all balls)
	.4byte PinballGame_State3_4B20C @ called once after game over?

gBallPalettes:: @ 0x08137E14
	.incbin "baserom.gba", 0x137E14, 0x100

gBallFlashPalette:: @ 0x08137F14
	.incbin "baserom.gba", 0x137F14, 0x100

gBallUpgradeTilesGfx:: @ 0x08138014
	.incbin "baserom.gba", 0x138014, 0x820

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

gCaptureScreenTilesGfx:: @ 0x081428D4
	.incbin "baserom.gba", 0x1428D4, 0x1C20

.include "data/graphics/mon_hatch_sprites_pals.inc"

gIdleBoardConfig0:: @ 0x081450F4
	.incbin "baserom.gba", 0x1450F4, 0x3840

gIdleBoardConfig2:: @ 0x08148934
	.incbin "baserom.gba", 0x148934, 0x3840

gIdleBoardConfig3:: @ 0x0814C174
	.incbin "baserom.gba", 0x14C174, 0x3840

gIdleBoardConfig1:: @ 0x0814F9B4
	.incbin "baserom.gba", 0x14F9B4, 0x3840

gIdleBoardGameState0:: @ 0x081531F4
	.incbin "baserom.gba", 0x1531F4, 0x1424

gIdleBoardGameState2:: @ 0x08154618
	.incbin "baserom.gba", 0x154618, 0x1424

gIdleBoardGameState3:: @ 0x08155A3C
	.incbin "baserom.gba", 0x155A3C, 0x1424

gIdleBoardGameState1:: @ 0x08156E60
	.incbin "baserom.gba", 0x156E60, 0x1424

gBoardActionTilesGfx:: @ 0x08158284
	.incbin "baserom.gba", 0x158284, 0x2420

gBoardActionObjPal:: @ 0x0815A6A4
	.incbin "baserom.gba", 0x15A6A4, 0x200

gEvoExAppear_Gfx:: @ 0x0815A8A4
	.incbin "graphics/board_pickups/evo_item_ex.4bpp";

gEvoItemPalettes:: @ 0x0815C4C4
	.incbin "baserom.gba", 0x15C4C4, 0x200

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
	.incbin "baserom.gba", 0x16C3E4, 0x42800
	.include "data/graphics/mon_catch_sprites_pals.inc"
@	.incbin "baserom.gba", 0x1AEBE4, 0xA80
	.incbin "baserom.gba", 0x1B0C64, 0x180

gKyogreWaterAnimPaletteFrames:: @ 0x081B0DE4
	.incbin "baserom.gba", 0x1B0DE4, 0x200

gPokeballCaptureOamFrames:: @ 0x081B0FE4
	.incbin "baserom.gba", 0x1B0FE4, 0x26C0

gBonusStageObjPal:: @ 0x081B36A4
	.incbin "baserom.gba", 0x1B36A4, 0xEE0

gEvoNameDisplay_Pals:: @ 0x081B4584
	.incbin "baserom.gba", 0x1B4584, 0x20

gShopNameDisplay_Pals:: @ 0x081B45A4
	.incbin "baserom.gba", 0x1B45A4, 0x1E0

gEvoModeBG_Gfx:: @ 0x081B4784
	.incbin "baserom.gba", 0x1B4784, 0x1000

gUnknown_081B5784:: @ 0x081B5784
	.incbin "baserom.gba", 0x1B5784, 0x1000

gUnknown_081B6784:: @ 0x081B6784
	.incbin "baserom.gba", 0x1B6784, 0x1000

gUnknown_081B7784:: @ 0x081B7784
	.incbin "baserom.gba", 0x1B7784, 0x1000

gShopEvoUI_Pals:: @ 0x081B8784
	.incbin "baserom.gba", 0x1B8784, 0x200

gShopModeBG_Gfx:: @ 0x081B8984
	.incbin "baserom.gba", 0x1B8984, 0x1000

gUnknown_081B9984:: @ 0x081B9984
	.incbin "baserom.gba", 0x1B9984, 0x1000

gUnknown_081BA984:: @ 0x081BA984
	.incbin "baserom.gba", 0x1BA984, 0x1000

gUnknown_081BB984:: @ 0x081BB984
	.incbin "baserom.gba", 0x1BB984, 0x1000

gSapphireShopSignPalettes:: @ 0x081BC984
	.incbin "baserom.gba", 0x1BC984, 0x120

gRubyBoardBonusGfx:: @ 0x081BCAA4
	.incbin "baserom.gba", 0x1BCAA4, 0x1820

gRubyBoardBonusObjPalette:: @ 0x081BE2C4
	.incbin "baserom.gba", 0x1BE2C4, 0x200

gSapphireBoardBonusGfx:: @ 0x081BE4C4
	.incbin "baserom.gba", 0x1BE4C4, 0x1820

gSapphireBoardBonusObjPalette:: @ 0x081BFCE4
	.incbin "baserom.gba", 0x1BFCE4, 0x200

gRubyBoardPalette:: @ 0x081BFEE4
	.incbin "baserom.gba", 0x1BFEE4, 0x180

gDefaultBallPalette:: @ 0x081C0064
	.incbin "baserom.gba", 0x1C0064, 0x80

gPortraitGenericPalettes:: @ 0x081C00E4
	.incbin "baserom.gba", 0x1C00E4, 0x200

gPortraitAnimPalettes:: @ 0x081C02E4
	.incbin "baserom.gba", 0x1C02E4, 0x600

gRubyBoardBG0Tilemap:: @ 0x081C08E4
	.incbin "baserom.gba", 0x1C08E4, 0x6DB40

gRubyBoardBG1Tilemap:: @ 0x0822E424
	.incbin "baserom.gba", 0x22E424, 0x1DDC0

gRubyBoardCompressedTiles1:: @ 0x0824C1E4
	.incbin "baserom.gba", 0x24C1E4, 0x1B7C

gRubyBoardCompressedTiles2:: @ 0x0824DD60
	.incbin "baserom.gba", 0x24DD60, 0x2BD4

gRubyBoardCompressedBGTileBuffer:: @ 0x08250934
	.incbin "baserom.gba", 0x250934, 0x21DC

gSharedBumperCollisionMap:: @ 0x08252B10
	.incbin "baserom.gba", 0x252B10, 0x2000

gRubyAltEntity0CollisionMap:: @ 0x08254B10
	.incbin "baserom.gba", 0x254B10, 0x2880

gRubyAltEntity1CollisionMap:: @ 0x08257390
	.incbin "baserom.gba", 0x257390, 0x2880

gWhiscashCollisionMap:: @ 0x08259C10
	.incbin "baserom.gba", 0x259C10, 0x3700

gUnknown_0825D310:: @ 0x0825D310
    .incbin "baserom.gba", 0x25D310, 0x60

gUnknown_0825D370:: @ 0x0825D370
    .incbin "baserom.gba", 0x25D370, 0x60

gUnknown_0825D3D0:: @ 0x0825D3D0
    .incbin "baserom.gba", 0x25D3D0, 0x60

gUnknown_0825D430:: @ 0x0825D430
    .incbin "baserom.gba", 0x25D430, 0x60

gUnknown_0825D490:: @ 0x0825D490
    .incbin "baserom.gba", 0x25D490, 0x60

gUnknown_0825D4F0:: @ 0x0825D4F0
    .incbin "baserom.gba", 0x25D4F0, 0x60

gUnknown_0825D550:: @ 0x0825D550
    .incbin "baserom.gba", 0x25D550, 0x60

gUnknown_0825D5B0:: @ 0x0825D5B0
    .incbin "baserom.gba", 0x25D5B0, 0x60

gUnknown_0825D610:: @ 0x0825D610
    .incbin "baserom.gba", 0x25D610, 0x60

gUnknown_0825D670:: @ 0x0825D670
    .incbin "baserom.gba", 0x25D670, 0xA0

gUnknown_0825D710:: @ 0x0825D710
    .incbin "baserom.gba", 0x25D710, 0x60

gUnknown_0825D770:: @ 0x0825D770
    .incbin "baserom.gba", 0x25D770, 0x60

gUnknown_0825D7D0:: @ 0x0825D7D0
    .incbin "baserom.gba", 0x25D7D0, 0x60

gUnknown_0825D830:: @ 0x0825D830
    .incbin "baserom.gba", 0x25D830, 0x60

gUnknown_0825D890:: @ 0x0825D890
    .incbin "baserom.gba", 0x25D890, 0x60

gUnknown_0825D8F0:: @ 0x0825D8F0
    .incbin "baserom.gba", 0x25D8F0, 0x60

gUnknown_0825D950:: @ 0x0825D950
    .incbin "baserom.gba", 0x25D950, 0x60

gUnknown_0825D9B0:: @ 0x0825D9B0
    .incbin "baserom.gba", 0x25D9B0, 0x60

gUnknown_0825DA10:: @ 0x0825DA10
    .incbin "baserom.gba", 0x25DA10, 0x60

gUnknown_0825DA70:: @ 0x0825DA70
    .incbin "baserom.gba", 0x25DA70, 0xA0

gUnknown_0825DB10:: @ 0x0825DB10
    .incbin "baserom.gba", 0x25DB10, 0x60

gUnknown_0825DB70:: @ 0x0825DB70
    .incbin "baserom.gba", 0x25DB70, 0x60

gUnknown_0825DBD0:: @ 0x0825DBD0
    .incbin "baserom.gba", 0x25DBD0, 0x60

gUnknown_0825DC30:: @ 0x0825DC30
    .incbin "baserom.gba", 0x25DC30, 0x60

gUnknown_0825DC90:: @ 0x0825DC90
    .incbin "baserom.gba", 0x25DC90, 0x60

gUnknown_0825DCF0:: @ 0x0825DCF0
    .incbin "baserom.gba", 0x25DCF0, 0x60

gUnknown_0825DD50:: @ 0x0825DD50
    .incbin "baserom.gba", 0x25DD50, 0x60

gUnknown_0825DDB0:: @ 0x0825DDB0
    .incbin "baserom.gba", 0x25DDB0, 0x60

gUnknown_0825DE10:: @ 0x0825DE10
    .incbin "baserom.gba", 0x25DE10, 0x60

gUnknown_0825DE70:: @ 0x0825DE70
    .incbin "baserom.gba", 0x25DE70, 0xA0

gUnknown_0825DF10:: @ 0x0825DF10
    .incbin "baserom.gba", 0x25DF10, 0x60

gUnknown_0825DF70:: @ 0x0825DF70
    .incbin "baserom.gba", 0x25DF70, 0x60

gUnknown_0825DFD0:: @ 0x0825DFD0
    .incbin "baserom.gba", 0x25DFD0, 0x60

gUnknown_0825E030:: @ 0x0825E030
    .incbin "baserom.gba", 0x25E030, 0x60

gUnknown_0825E090:: @ 0x0825E090
    .incbin "baserom.gba", 0x25E090, 0x60

gUnknown_0825E0F0:: @ 0x0825E0F0
    .incbin "baserom.gba", 0x25E0F0, 0x60

gUnknown_0825E150:: @ 0x0825E150
    .incbin "baserom.gba", 0x25E150, 0x60

gUnknown_0825E1B0:: @ 0x0825E1B0
    .incbin "baserom.gba", 0x25E1B0, 0x60

gUnknown_0825E210:: @ 0x0825E210
    .incbin "baserom.gba", 0x25E210, 0x60

gUnknown_0825E270:: @ 0x0825E270
    .incbin "baserom.gba", 0x25E270, 0xA0

gUnknown_0825E310:: @ 0x0825E310
    .incbin "baserom.gba", 0x25E310, 0x60

gUnknown_0825E370:: @ 0x0825E370
    .incbin "baserom.gba", 0x25E370, 0x60

gUnknown_0825E3D0:: @ 0x0825E3D0
    .incbin "baserom.gba", 0x25E3D0, 0x60

gUnknown_0825E430:: @ 0x0825E430
    .incbin "baserom.gba", 0x25E430, 0x60

gUnknown_0825E490:: @ 0x0825E490
    .incbin "baserom.gba", 0x25E490, 0x60

gUnknown_0825E4F0:: @ 0x0825E4F0
    .incbin "baserom.gba", 0x25E4F0, 0x60

gUnknown_0825E550:: @ 0x0825E550
    .incbin "baserom.gba", 0x25E550, 0x60

gUnknown_0825E5B0:: @ 0x0825E5B0
    .incbin "baserom.gba", 0x25E5B0, 0x60

gUnknown_0825E610:: @ 0x0825E610
    .incbin "baserom.gba", 0x25E610, 0x60

gUnknown_0825E670:: @ 0x0825E670
    .incbin "baserom.gba", 0x25E670, 0xA0

gUnknown_0825E710:: @ 0x0825E710
    .incbin "baserom.gba", 0x25E710, 0x60

gUnknown_0825E770:: @ 0x0825E770
    .incbin "baserom.gba", 0x25E770, 0x60

gUnknown_0825E7D0:: @ 0x0825E7D0
    .incbin "baserom.gba", 0x25E7D0, 0x60

gUnknown_0825E830:: @ 0x0825E830
    .incbin "baserom.gba", 0x25E830, 0x60

gUnknown_0825E890:: @ 0x0825E890
    .incbin "baserom.gba", 0x25E890, 0x60

gUnknown_0825E8F0:: @ 0x0825E8F0
    .incbin "baserom.gba", 0x25E8F0, 0x60

gUnknown_0825E950:: @ 0x0825E950
    .incbin "baserom.gba", 0x25E950, 0x60

gUnknown_0825E9B0:: @ 0x0825E9B0
    .incbin "baserom.gba", 0x25E9B0, 0x60

gUnknown_0825EA10:: @ 0x0825EA10
    .incbin "baserom.gba", 0x25EA10, 0x60

gUnknown_0825EA70:: @ 0x0825EA70
    .incbin "baserom.gba", 0x25EA70, 0xA0

gUnknown_0825EB10:: @ 0x0825EB10
    .incbin "baserom.gba", 0x25EB10, 0x60

gUnknown_0825EB70:: @ 0x0825EB70
    .incbin "baserom.gba", 0x25EB70, 0x60

gUnknown_0825EBD0:: @ 0x0825EBD0
    .incbin "baserom.gba", 0x25EBD0, 0x80

gUnknown_0825EC50:: @ 0x0825EC50
    .incbin "baserom.gba", 0x25EC50, 0x60

gUnknown_0825ECB0:: @ 0x0825ECB0
    .incbin "baserom.gba", 0x25ECB0, 0x60

gUnknown_0825ED10:: @ 0x0825ED10
    .incbin "baserom.gba", 0x25ED10, 0x60

gUnknown_0825ED70:: @ 0x0825ED70
    .incbin "baserom.gba", 0x25ED70, 0x60

gUnknown_0825EDD0:: @ 0x0825EDD0
    .incbin "baserom.gba", 0x25EDD0, 0x60

gUnknown_0825EE30:: @ 0x0825EE30
    .incbin "baserom.gba", 0x25EE30, 0x60

gUnknown_0825EE90:: @ 0x0825EE90
    .incbin "baserom.gba", 0x25EE90, 0x80

gUnknown_0825EF10:: @ 0x0825EF10
    .incbin "baserom.gba", 0x25EF10, 0x60

gUnknown_0825EF70:: @ 0x0825EF70
    .incbin "baserom.gba", 0x25EF70, 0x60

gUnknown_0825EFD0:: @ 0x0825EFD0
    .incbin "baserom.gba", 0x25EFD0, 0x80

gUnknown_0825F050:: @ 0x0825F050
    .incbin "baserom.gba", 0x25F050, 0x60

gUnknown_0825F0B0:: @ 0x0825F0B0
    .incbin "baserom.gba", 0x25F0B0, 0x60

gUnknown_0825F110:: @ 0x0825F110
    .incbin "baserom.gba", 0x25F110, 0x60

gUnknown_0825F170:: @ 0x0825F170
    .incbin "baserom.gba", 0x25F170, 0x40

gUnknown_0825F1B0:: @ 0x0825F1B0
    .incbin "baserom.gba", 0x25F1B0, 0x60

gUnknown_0825F210:: @ 0x0825F210
    .incbin "baserom.gba", 0x25F210, 0x60

gUnknown_0825F270:: @ 0x0825F270
    .incbin "baserom.gba", 0x25F270, 0xA0

gUnknown_0825F310:: @ 0x0825F310
    .incbin "baserom.gba", 0x25F310, 0x60

gUnknown_0825F370:: @ 0x0825F370
    .incbin "baserom.gba", 0x25F370, 0x60

gUnknown_0825F3D0:: @ 0x0825F3D0
    .incbin "baserom.gba", 0x25F3D0, 0x60

gUnknown_0825F430:: @ 0x0825F430
    .incbin "baserom.gba", 0x25F430, 0x60

gUnknown_0825F490:: @ 0x0825F490
    .incbin "baserom.gba", 0x25F490, 0x60

gUnknown_0825F4F0:: @ 0x0825F4F0
    .incbin "baserom.gba", 0x25F4F0, 0x60

gUnknown_0825F550:: @ 0x0825F550
    .incbin "baserom.gba", 0x25F550, 0x60

gUnknown_0825F5B0:: @ 0x0825F5B0
    .incbin "baserom.gba", 0x25F5B0, 0x60

gUnknown_0825F610:: @ 0x0825F610
    .incbin "baserom.gba", 0x25F610, 0x60

gUnknown_0825F670:: @ 0x0825F670
    .incbin "baserom.gba", 0x25F670, 0xC0

gUnknown_0825F730:: @ 0x0825F730
    .incbin "baserom.gba", 0x25F730, 0x40

gUnknown_0825F770:: @ 0x0825F770
    .incbin "baserom.gba", 0x25F770, 0x40

gUnknown_0825F7B0:: @ 0x0825F7B0
    .incbin "baserom.gba", 0x25F7B0, 0x40

gUnknown_0825F7F0:: @ 0x0825F7F0
    .incbin "baserom.gba", 0x25F7F0, 0x40

gUnknown_0825F830:: @ 0x0825F830
    .incbin "baserom.gba", 0x25F830, 0x40

gUnknown_0825F870:: @ 0x0825F870
    .incbin "baserom.gba", 0x25F870, 0x40

gUnknown_0825F8B0:: @ 0x0825F8B0
    .incbin "baserom.gba", 0x25F8B0, 0x40

gUnknown_0825F8F0:: @ 0x0825F8F0
    .incbin "baserom.gba", 0x25F8F0, 0x40

gUnknown_0825F930:: @ 0x0825F930
    .incbin "baserom.gba", 0x25F930, 0x40

gUnknown_0825F970:: @ 0x0825F970
    .incbin "baserom.gba", 0x25F970, 0x40

gUnknown_0825F9B0:: @ 0x0825F9B0
    .incbin "baserom.gba", 0x25F9B0, 0x40

gUnknown_0825F9F0:: @ 0x0825F9F0
    .incbin "baserom.gba", 0x25F9F0, 0x40

gUnknown_0825FA30:: @ 0x0825FA30
    .incbin "baserom.gba", 0x25FA30, 0x40

gUnknown_0825FA70:: @ 0x0825FA70
    .incbin "baserom.gba", 0x25FA70, 0x40

gUnknown_0825FAB0:: @ 0x0825FAB0
    .incbin "baserom.gba", 0x25FAB0, 0x40

gUnknown_0825FAF0:: @ 0x0825FAF0
    .incbin "baserom.gba", 0x25FAF0, 0x3C0

gUnknown_0825FEB0:: @ 0x0825FEB0
    .incbin "baserom.gba", 0x25FEB0, 0x40

gUnknown_0825FEF0:: @ 0x0825FEF0
    .incbin "baserom.gba", 0x25FEF0, 0x40

gUnknown_0825FF30:: @ 0x0825FF30
    .incbin "baserom.gba", 0x25FF30, 0x40

gUnknown_0825FF70:: @ 0x0825FF70
    .incbin "baserom.gba", 0x25FF70, 0x40

gUnknown_0825FFB0:: @ 0x0825FFB0
    .incbin "baserom.gba", 0x25FFB0, 0x40

gUnknown_0825FFF0:: @ 0x0825FFF0
    .incbin "baserom.gba", 0x25FFF0, 0x40

gUnknown_08260030:: @ 0x08260030
    .incbin "baserom.gba", 0x260030, 0x40

gUnknown_08260070:: @ 0x08260070
    .incbin "baserom.gba", 0x260070, 0x40

gUnknown_082600B0:: @ 0x082600B0
    .incbin "baserom.gba", 0x2600B0, 0x40

gUnknown_082600F0:: @ 0x082600F0
    .incbin "baserom.gba", 0x2600F0, 0x40

gUnknown_08260130:: @ 0x08260130
    .incbin "baserom.gba", 0x260130, 0x40

gUnknown_08260170:: @ 0x08260170
    .incbin "baserom.gba", 0x260170, 0x40

gUnknown_082601B0:: @ 0x082601B0
    .incbin "baserom.gba", 0x2601B0, 0x40

gUnknown_082601F0:: @ 0x082601F0
    .incbin "baserom.gba", 0x2601F0, 0x40

gUnknown_08260230:: @ 0x08260230
    .incbin "baserom.gba", 0x260230, 0x40

gUnknown_08260270:: @ 0x08260270
    .incbin "baserom.gba", 0x260270, 0x40

gUnknown_082602B0:: @ 0x082602B0
    .incbin "baserom.gba", 0x2602B0, 0x80

gUnknown_08260330:: @ 0x08260330
    .incbin "baserom.gba", 0x260330, 0x40

gUnknown_08260370:: @ 0x08260370
    .incbin "baserom.gba", 0x260370, 0x40

gUnknown_082603B0:: @ 0x082603B0
    .incbin "baserom.gba", 0x2603B0, 0x40

gUnknown_082603F0:: @ 0x082603F0
    .incbin "baserom.gba", 0x2603F0, 0x40

gUnknown_08260430:: @ 0x08260430
    .incbin "baserom.gba", 0x260430, 0x40

gUnknown_08260470:: @ 0x08260470
    .incbin "baserom.gba", 0x260470, 0x40

gUnknown_082604B0:: @ 0x082604B0
    .incbin "baserom.gba", 0x2604B0, 0x40

gUnknown_082604F0:: @ 0x082604F0
    .incbin "baserom.gba", 0x2604F0, 0x40

gUnknown_08260530:: @ 0x08260530
    .incbin "baserom.gba", 0x260530, 0x40

gUnknown_08260570:: @ 0x08260570
    .incbin "baserom.gba", 0x260570, 0x40

gUnknown_082605B0:: @ 0x082605B0
    .incbin "baserom.gba", 0x2605B0, 0x40

gUnknown_082605F0:: @ 0x082605F0
    .incbin "baserom.gba", 0x2605F0, 0x40

gUnknown_08260630:: @ 0x08260630
    .incbin "baserom.gba", 0x260630, 0x40

gUnknown_08260670:: @ 0x08260670
    .incbin "baserom.gba", 0x260670, 0x40

gUnknown_082606B0:: @ 0x082606B0
    .incbin "baserom.gba", 0x2606B0, 0xC0

gUnknown_08260770:: @ 0x08260770
    .incbin "baserom.gba", 0x260770, 0x100

gUnknown_08260870:: @ 0x08260870
    .incbin "baserom.gba", 0x260870, 0x300

gUnknown_08260B70:: @ 0x08260B70
    .incbin "baserom.gba", 0x260B70, 0x100

gUnknown_08260C70:: @ 0x08260C70
    .incbin "baserom.gba", 0x260C70, 0x320

gUnknown_08260F90:: @ 0x08260F90
    .incbin "baserom.gba", 0x260F90, 0x100

gUnknown_08261090:: @ 0x08261090
    .incbin "baserom.gba", 0x261090, 0x360

gUnknown_082613F0:: @ 0x082613F0
    .incbin "baserom.gba", 0x2613F0, 0x100

gUnknown_082614F0:: @ 0x082614F0
    .incbin "baserom.gba", 0x2614F0, 0x280

gUnknown_08261770:: @ 0x08261770
    .incbin "baserom.gba", 0x261770, 0x80

gUnknown_082617F0:: @ 0x082617F0
    .incbin "baserom.gba", 0x2617F0, 0xC0

gUnknown_082618B0:: @ 0x082618B0
    .incbin "baserom.gba", 0x2618B0, 0x80

gUnknown_08261930:: @ 0x08261930
    .incbin "baserom.gba", 0x261930, 0x80

gUnknown_082619B0:: @ 0x082619B0
    .incbin "baserom.gba", 0x2619B0, 0x80

gUnknown_08261A30:: @ 0x08261A30
    .incbin "baserom.gba", 0x261A30, 0x140

gUnknown_08261B70:: @ 0x08261B70
    .incbin "baserom.gba", 0x261B70, 0x80

gUnknown_08261BF0:: @ 0x08261BF0
    .incbin "baserom.gba", 0x261BF0, 0x80

gUnknown_08261C70:: @ 0x08261C70
    .incbin "baserom.gba", 0x261C70, 0x80

gUnknown_08261CF0:: @ 0x08261CF0
    .incbin "baserom.gba", 0x261CF0, 0x80

gUnknown_08261D70:: @ 0x08261D70
    .incbin "baserom.gba", 0x261D70, 0x80

gUnknown_08261DF0:: @ 0x08261DF0
    .incbin "baserom.gba", 0x261DF0, 0x180

gUnknown_08261F70:: @ 0x08261F70
    .incbin "baserom.gba", 0x261F70, 0x80

gUnknown_08261FF0:: @ 0x08261FF0
    .incbin "baserom.gba", 0x261FF0, 0x80

gUnknown_08262070:: @ 0x08262070
    .incbin "baserom.gba", 0x262070, 0x80

gUnknown_082620F0:: @ 0x082620F0
    .incbin "baserom.gba", 0x2620F0, 0x80

gUnknown_08262170:: @ 0x08262170
    .incbin "baserom.gba", 0x262170, 0x80

gUnknown_082621F0:: @ 0x082621F0
    .incbin "baserom.gba", 0x2621F0, 0x180

gUnknown_08262370:: @ 0x08262370
    .incbin "baserom.gba", 0x262370, 0x80

gUnknown_082623F0:: @ 0x082623F0
    .incbin "baserom.gba", 0x2623F0, 0x80

gUnknown_08262470:: @ 0x08262470
    .incbin "baserom.gba", 0x262470, 0x80

gUnknown_082624F0:: @ 0x082624F0
    .incbin "baserom.gba", 0x2624F0, 0x80

gUnknown_08262570:: @ 0x08262570
    .incbin "baserom.gba", 0x262570, 0x80

gUnknown_082625F0:: @ 0x082625F0
    .incbin "baserom.gba", 0x2625F0, 0x1A0

gUnknown_08262790:: @ 0x08262790
    .incbin "baserom.gba", 0x262790, 0x20

gUnknown_082627B0:: @ 0x082627B0
    .incbin "baserom.gba", 0x2627B0, 0x20

gUnknown_082627D0:: @ 0x082627D0
    .incbin "baserom.gba", 0x2627D0, 0x20

gUnknown_082627F0:: @ 0x082627F0
    .incbin "baserom.gba", 0x2627F0, 0x20

gUnknown_08262810:: @ 0x08262810
    .incbin "baserom.gba", 0x262810, 0x20

gUnknown_08262830:: @ 0x08262830
    .incbin "baserom.gba", 0x262830, 0x20

gUnknown_08262850:: @ 0x08262850
    .incbin "baserom.gba", 0x262850, 0x20

gUnknown_08262870:: @ 0x08262870
    .incbin "baserom.gba", 0x262870, 0x20

gUnknown_08262890:: @ 0x08262890
    .incbin "baserom.gba", 0x262890, 0x20

gUnknown_082628B0:: @ 0x082628B0
    .incbin "baserom.gba", 0x2628B0, 0x20

gUnknown_082628D0:: @ 0x082628D0
    .incbin "baserom.gba", 0x2628D0, 0x20

gUnknown_082628F0:: @ 0x082628F0
    .incbin "baserom.gba", 0x2628F0, 0x20

gUnknown_08262910:: @ 0x08262910
    .incbin "baserom.gba", 0x262910, 0x20

gUnknown_08262930:: @ 0x08262930
    .incbin "baserom.gba", 0x262930, 0x20

gUnknown_08262950:: @ 0x08262950
    .incbin "baserom.gba", 0x262950, 0x20

gUnknown_08262970:: @ 0x08262970
    .incbin "baserom.gba", 0x262970, 0x20

gUnknown_08262990:: @ 0x08262990
    .incbin "baserom.gba", 0x262990, 0x20

gUnknown_082629B0:: @ 0x082629B0
    .incbin "baserom.gba", 0x2629B0, 0x20

gUnknown_082629D0:: @ 0x082629D0
    .incbin "baserom.gba", 0x2629D0, 0x20

gUnknown_082629F0:: @ 0x082629F0
    .incbin "baserom.gba", 0x2629F0, 0x1C0

gUnknown_08262BB0:: @ 0x08262BB0
    .incbin "baserom.gba", 0x262BB0, 0xC0

gUnknown_08262C70:: @ 0x08262C70
    .incbin "baserom.gba", 0x262C70, 0x340

gUnknown_08262FB0:: @ 0x08262FB0
    .incbin "baserom.gba", 0x262FB0, 0xC0

gUnknown_08263070:: @ 0x08263070
    .incbin "baserom.gba", 0x263070, 0x3C0

gUnknown_08263430:: @ 0x08263430
    .incbin "baserom.gba", 0x263430, 0xC0

gUnknown_082634F0:: @ 0x082634F0
    .incbin "baserom.gba", 0x2634F0, 0x2E0

gUnknown_082637D0:: @ 0x082637D0
    .incbin "baserom.gba", 0x2637D0, 0xA0

gUnknown_08263870:: @ 0x08263870
    .incbin "baserom.gba", 0x263870, 0xA0

gUnknown_08263910:: @ 0x08263910
    .incbin "baserom.gba", 0x263910, 0xA0

gUnknown_082639B0:: @ 0x082639B0
    .incbin "baserom.gba", 0x2639B0, 0x220

gUnknown_08263BD0:: @ 0x08263BD0
    .incbin "baserom.gba", 0x263BD0, 0xA0

gUnknown_08263C70:: @ 0x08263C70
    .incbin "baserom.gba", 0x263C70, 0xA0

gUnknown_08263D10:: @ 0x08263D10
    .incbin "baserom.gba", 0x263D10, 0xA0

gUnknown_08263DB0:: @ 0x08263DB0
    .incbin "baserom.gba", 0x263DB0, 0x220

gUnknown_08263FD0:: @ 0x08263FD0
    .incbin "baserom.gba", 0x263FD0, 0xA0

gUnknown_08264070:: @ 0x08264070
    .incbin "baserom.gba", 0x264070, 0xA0

gUnknown_08264110:: @ 0x08264110
    .incbin "baserom.gba", 0x264110, 0xA0

gUnknown_082641B0:: @ 0x082641B0
    .incbin "baserom.gba", 0x2641B0, 0x220

gUnknown_082643D0:: @ 0x082643D0
    .incbin "baserom.gba", 0x2643D0, 0xA0

gUnknown_08264470:: @ 0x08264470
    .incbin "baserom.gba", 0x264470, 0xA0

gUnknown_08264510:: @ 0x08264510
    .incbin "baserom.gba", 0x264510, 0xA0

gUnknown_082645B0:: @ 0x082645B0
    .incbin "baserom.gba", 0x2645B0, 0x240

gUnknown_082647F0:: @ 0x082647F0
    .incbin "baserom.gba", 0x2647F0, 0x60

gUnknown_08264850:: @ 0x08264850
    .incbin "baserom.gba", 0x264850, 0xA0

gUnknown_082648F0:: @ 0x082648F0
    .incbin "baserom.gba", 0x2648F0, 0x60

gUnknown_08264950:: @ 0x08264950
    .incbin "baserom.gba", 0x264950, 0x2A0

gUnknown_08264BF0:: @ 0x08264BF0
    .incbin "baserom.gba", 0x264BF0, 0x60

gUnknown_08264C50:: @ 0x08264C50
    .incbin "baserom.gba", 0x264C50, 0x80

gUnknown_08264CD0:: @ 0x08264CD0
    .incbin "baserom.gba", 0x264CD0, 0x60

gUnknown_08264D30:: @ 0x08264D30
    .incbin "baserom.gba", 0x264D30, 0x2C0

gUnknown_08264FF0:: @ 0x08264FF0
    .incbin "baserom.gba", 0x264FF0, 0x60

gUnknown_08265050:: @ 0x08265050
    .incbin "baserom.gba", 0x265050, 0x60

gUnknown_082650B0:: @ 0x082650B0
    .incbin "baserom.gba", 0x2650B0, 0x60

gUnknown_08265110:: @ 0x08265110
    .incbin "baserom.gba", 0x265110, 0x2E0

gUnknown_082653F0:: @ 0x082653F0
    .incbin "baserom.gba", 0x2653F0, 0x60

gUnknown_08265450:: @ 0x08265450
    .incbin "baserom.gba", 0x265450, 0x60

gUnknown_082654B0:: @ 0x082654B0
    .incbin "baserom.gba", 0x2654B0, 0x60

gUnknown_08265510:: @ 0x08265510
    .incbin "baserom.gba", 0x265510, 0x300

gUnknown_08265810:: @ 0x08265810
    .incbin "baserom.gba", 0x265810, 0x60

gUnknown_08265870:: @ 0x08265870
    .incbin "baserom.gba", 0x265870, 0x40

gUnknown_082658B0:: @ 0x082658B0
    .incbin "baserom.gba", 0x2658B0, 0x60

gUnknown_08265910:: @ 0x08265910
    .incbin "baserom.gba", 0x265910, 0x300

gRubyBoardBGTiles:: @ 0x08265C10
	.incbin "baserom.gba", 0x265C10, 0x8000

gRubyBoardBGTilemap:: @ 0x0826DC10
	.incbin "baserom.gba", 0x26DC10, 0x1000

gSapphireBoardPalette:: @ 0x0826EC10
	.incbin "baserom.gba", 0x26EC10, 0x200

gSapphireBoardBG0Tilemap:: @ 0x0826EE10
	.incbin "baserom.gba", 0x26EE10, 0x3F8C0

gSapphireBoardBG1Tilemap:: @ 0x082AE6D0
	.incbin "baserom.gba", 0x2AE6D0, 0x24E00

gSapphireBoardCompressedTiles1:: @ 0x082D34D0
	.incbin "baserom.gba", 0x2D34D0, 0x1D6C

gSapphireBoardCompressedTiles2:: @ 0x082D523C
	.incbin "baserom.gba", 0x2D523C, 0x375C

gSapphireBoardCompressedBGTileBuffer:: @ 0x082D8998
	.incbin "baserom.gba", 0x2D8998, 0x2048

gUnknown_082DA9E0:: @ 0x082DA9E0
    .incbin "baserom.gba", 0x2DA9E0, 0x60

gUnknown_082DAA40:: @ 0x082DAA40
    .incbin "baserom.gba", 0x2DAA40, 0x60

gUnknown_082DAAA0:: @ 0x082DAAA0
    .incbin "baserom.gba", 0x2DAAA0, 0x60

gUnknown_082DAB00:: @ 0x082DAB00
    .incbin "baserom.gba", 0x2DAB00, 0x60

gUnknown_082DAB60:: @ 0x082DAB60
    .incbin "baserom.gba", 0x2DAB60, 0x60

gUnknown_082DABC0:: @ 0x082DABC0
    .incbin "baserom.gba", 0x2DABC0, 0x60

gUnknown_082DAC20:: @ 0x082DAC20
    .incbin "baserom.gba", 0x2DAC20, 0x60

gUnknown_082DAC80:: @ 0x082DAC80
    .incbin "baserom.gba", 0x2DAC80, 0x60

gUnknown_082DACE0:: @ 0x082DACE0
    .incbin "baserom.gba", 0x2DACE0, 0x60

gUnknown_082DAD40:: @ 0x082DAD40
    .incbin "baserom.gba", 0x2DAD40, 0xA0

gUnknown_082DADE0:: @ 0x082DADE0
    .incbin "baserom.gba", 0x2DADE0, 0x60

gUnknown_082DAE40:: @ 0x082DAE40
    .incbin "baserom.gba", 0x2DAE40, 0x60

gUnknown_082DAEA0:: @ 0x082DAEA0
    .incbin "baserom.gba", 0x2DAEA0, 0x60

gUnknown_082DAF00:: @ 0x082DAF00
    .incbin "baserom.gba", 0x2DAF00, 0x60

gUnknown_082DAF60:: @ 0x082DAF60
    .incbin "baserom.gba", 0x2DAF60, 0x60

gUnknown_082DAFC0:: @ 0x082DAFC0
    .incbin "baserom.gba", 0x2DAFC0, 0x60

gUnknown_082DB020:: @ 0x082DB020
    .incbin "baserom.gba", 0x2DB020, 0x60

gUnknown_082DB080:: @ 0x082DB080
    .incbin "baserom.gba", 0x2DB080, 0x60

gUnknown_082DB0E0:: @ 0x082DB0E0
    .incbin "baserom.gba", 0x2DB0E0, 0x60

gUnknown_082DB140:: @ 0x082DB140
    .incbin "baserom.gba", 0x2DB140, 0xA0

gUnknown_082DB1E0:: @ 0x082DB1E0
    .incbin "baserom.gba", 0x2DB1E0, 0x60

gUnknown_082DB240:: @ 0x082DB240
    .incbin "baserom.gba", 0x2DB240, 0x60

gUnknown_082DB2A0:: @ 0x082DB2A0
    .incbin "baserom.gba", 0x2DB2A0, 0x60

gUnknown_082DB300:: @ 0x082DB300
    .incbin "baserom.gba", 0x2DB300, 0x60

gUnknown_082DB360:: @ 0x082DB360
    .incbin "baserom.gba", 0x2DB360, 0x60

gUnknown_082DB3C0:: @ 0x082DB3C0
    .incbin "baserom.gba", 0x2DB3C0, 0x60

gUnknown_082DB420:: @ 0x082DB420
    .incbin "baserom.gba", 0x2DB420, 0x80

gUnknown_082DB4A0:: @ 0x082DB4A0
    .incbin "baserom.gba", 0x2DB4A0, 0x60

gUnknown_082DB500:: @ 0x082DB500
    .incbin "baserom.gba", 0x2DB500, 0x60

gUnknown_082DB560:: @ 0x082DB560
    .incbin "baserom.gba", 0x2DB560, 0x80

gUnknown_082DB5E0:: @ 0x082DB5E0
    .incbin "baserom.gba", 0x2DB5E0, 0x60

gUnknown_082DB640:: @ 0x082DB640
    .incbin "baserom.gba", 0x2DB640, 0x60

gUnknown_082DB6A0:: @ 0x082DB6A0
    .incbin "baserom.gba", 0x2DB6A0, 0x80

gUnknown_082DB720:: @ 0x082DB720
    .incbin "baserom.gba", 0x2DB720, 0x60

gUnknown_082DB780:: @ 0x082DB780
    .incbin "baserom.gba", 0x2DB780, 0x60

gUnknown_082DB7E0:: @ 0x082DB7E0
    .incbin "baserom.gba", 0x2DB7E0, 0x40

gUnknown_082DB820:: @ 0x082DB820
    .incbin "baserom.gba", 0x2DB820, 0x60

gUnknown_082DB880:: @ 0x082DB880
    .incbin "baserom.gba", 0x2DB880, 0x60

gUnknown_082DB8E0:: @ 0x082DB8E0
    .incbin "baserom.gba", 0x2DB8E0, 0x100

gUnknown_082DB9E0:: @ 0x082DB9E0
    .incbin "baserom.gba", 0x2DB9E0, 0x60

gUnknown_082DBA40:: @ 0x082DBA40
    .incbin "baserom.gba", 0x2DBA40, 0x60

gUnknown_082DBAA0:: @ 0x082DBAA0
    .incbin "baserom.gba", 0x2DBAA0, 0x80

gUnknown_082DBB20:: @ 0x082DBB20
    .incbin "baserom.gba", 0x2DBB20, 0x60

gUnknown_082DBB80:: @ 0x082DBB80
    .incbin "baserom.gba", 0x2DBB80, 0x60

gUnknown_082DBBE0:: @ 0x082DBBE0
    .incbin "baserom.gba", 0x2DBBE0, 0x40

gUnknown_082DBC20:: @ 0x082DBC20
    .incbin "baserom.gba", 0x2DBC20, 0x60

gUnknown_082DBC80:: @ 0x082DBC80
    .incbin "baserom.gba", 0x2DBC80, 0x60

gUnknown_082DBCE0:: @ 0x082DBCE0
    .incbin "baserom.gba", 0x2DBCE0, 0x100

gUnknown_082DBDE0:: @ 0x082DBDE0
    .incbin "baserom.gba", 0x2DBDE0, 0x60

gUnknown_082DBE40:: @ 0x082DBE40
    .incbin "baserom.gba", 0x2DBE40, 0x60

gUnknown_082DBEA0:: @ 0x082DBEA0
    .incbin "baserom.gba", 0x2DBEA0, 0x80

gUnknown_082DBF20:: @ 0x082DBF20
    .incbin "baserom.gba", 0x2DBF20, 0x60

gUnknown_082DBF80:: @ 0x082DBF80
    .incbin "baserom.gba", 0x2DBF80, 0x60

gUnknown_082DBFE0:: @ 0x082DBFE0
    .incbin "baserom.gba", 0x2DBFE0, 0x40

gUnknown_082DC020:: @ 0x082DC020
    .incbin "baserom.gba", 0x2DC020, 0x60

gUnknown_082DC080:: @ 0x082DC080
    .incbin "baserom.gba", 0x2DC080, 0x60

gUnknown_082DC0E0:: @ 0x082DC0E0
    .incbin "baserom.gba", 0x2DC0E0, 0x100

gUnknown_082DC1E0:: @ 0x082DC1E0
    .incbin "baserom.gba", 0x2DC1E0, 0x60

gUnknown_082DC240:: @ 0x082DC240
    .incbin "baserom.gba", 0x2DC240, 0x60

gUnknown_082DC2A0:: @ 0x082DC2A0
    .incbin "baserom.gba", 0x2DC2A0, 0x80

gUnknown_082DC320:: @ 0x082DC320
    .incbin "baserom.gba", 0x2DC320, 0x60

gUnknown_082DC380:: @ 0x082DC380
    .incbin "baserom.gba", 0x2DC380, 0x60

gUnknown_082DC3E0:: @ 0x082DC3E0
    .incbin "baserom.gba", 0x2DC3E0, 0x60

gUnknown_082DC440:: @ 0x082DC440
    .incbin "baserom.gba", 0x2DC440, 0x60

gUnknown_082DC4A0:: @ 0x082DC4A0
    .incbin "baserom.gba", 0x2DC4A0, 0x60

gUnknown_082DC500:: @ 0x082DC500
    .incbin "baserom.gba", 0x2DC500, 0x60

gUnknown_082DC560:: @ 0x082DC560
    .incbin "baserom.gba", 0x2DC560, 0x80

gUnknown_082DC5E0:: @ 0x082DC5E0
    .incbin "baserom.gba", 0x2DC5E0, 0x60

gUnknown_082DC640:: @ 0x082DC640
    .incbin "baserom.gba", 0x2DC640, 0x60

gUnknown_082DC6A0:: @ 0x082DC6A0
    .incbin "baserom.gba", 0x2DC6A0, 0x80

gUnknown_082DC720:: @ 0x082DC720
    .incbin "baserom.gba", 0x2DC720, 0x60

gUnknown_082DC780:: @ 0x082DC780
    .incbin "baserom.gba", 0x2DC780, 0x60

gUnknown_082DC7E0:: @ 0x082DC7E0
    .incbin "baserom.gba", 0x2DC7E0, 0x60

gUnknown_082DC840:: @ 0x082DC840
    .incbin "baserom.gba", 0x2DC840, 0x40

gUnknown_082DC880:: @ 0x082DC880
    .incbin "baserom.gba", 0x2DC880, 0x60

gUnknown_082DC8E0:: @ 0x082DC8E0
    .incbin "baserom.gba", 0x2DC8E0, 0x60

gUnknown_082DC940:: @ 0x082DC940
    .incbin "baserom.gba", 0x2DC940, 0xA0

gUnknown_082DC9E0:: @ 0x082DC9E0
    .incbin "baserom.gba", 0x2DC9E0, 0x60

gUnknown_082DCA40:: @ 0x082DCA40
    .incbin "baserom.gba", 0x2DCA40, 0x60

gUnknown_082DCAA0:: @ 0x082DCAA0
    .incbin "baserom.gba", 0x2DCAA0, 0x60

gUnknown_082DCB00:: @ 0x082DCB00
    .incbin "baserom.gba", 0x2DCB00, 0x60

gUnknown_082DCB60:: @ 0x082DCB60
    .incbin "baserom.gba", 0x2DCB60, 0x60

gUnknown_082DCBC0:: @ 0x082DCBC0
    .incbin "baserom.gba", 0x2DCBC0, 0x60

gUnknown_082DCC20:: @ 0x082DCC20
    .incbin "baserom.gba", 0x2DCC20, 0x60

gUnknown_082DCC80:: @ 0x082DCC80
    .incbin "baserom.gba", 0x2DCC80, 0x60

gUnknown_082DCCE0:: @ 0x082DCCE0
    .incbin "baserom.gba", 0x2DCCE0, 0x60

gUnknown_082DCD40:: @ 0x082DCD40
    .incbin "baserom.gba", 0x2DCD40, 0xC0

gUnknown_082DCE00:: @ 0x082DCE00
    .incbin "baserom.gba", 0x2DCE00, 0x20

gUnknown_082DCE20:: @ 0x082DCE20
    .incbin "baserom.gba", 0x2DCE20, 0x20

gUnknown_082DCE40:: @ 0x082DCE40
    .incbin "baserom.gba", 0x2DCE40, 0x20

gUnknown_082DCE60:: @ 0x082DCE60
    .incbin "baserom.gba", 0x2DCE60, 0x20

gUnknown_082DCE80:: @ 0x082DCE80
    .incbin "baserom.gba", 0x2DCE80, 0x20

gUnknown_082DCEA0:: @ 0x082DCEA0
    .incbin "baserom.gba", 0x2DCEA0, 0x20

gUnknown_082DCEC0:: @ 0x082DCEC0
    .incbin "baserom.gba", 0x2DCEC0, 0x20

gUnknown_082DCEE0:: @ 0x082DCEE0
    .incbin "baserom.gba", 0x2DCEE0, 0x20

gUnknown_082DCF00:: @ 0x082DCF00
    .incbin "baserom.gba", 0x2DCF00, 0x20

gUnknown_082DCF20:: @ 0x082DCF20
    .incbin "baserom.gba", 0x2DCF20, 0x20

gUnknown_082DCF40:: @ 0x082DCF40
    .incbin "baserom.gba", 0x2DCF40, 0x20

gUnknown_082DCF60:: @ 0x082DCF60
    .incbin "baserom.gba", 0x2DCF60, 0x20

gUnknown_082DCF80:: @ 0x082DCF80
    .incbin "baserom.gba", 0x2DCF80, 0x20

gUnknown_082DCFA0:: @ 0x082DCFA0
    .incbin "baserom.gba", 0x2DCFA0, 0x20

gUnknown_082DCFC0:: @ 0x082DCFC0
    .incbin "baserom.gba", 0x2DCFC0, 0x20

gUnknown_082DCFE0:: @ 0x082DCFE0
    .incbin "baserom.gba", 0x2DCFE0, 0x20

gUnknown_082DD000:: @ 0x082DD000
    .incbin "baserom.gba", 0x2DD000, 0x20

gUnknown_082DD020:: @ 0x082DD020
    .incbin "baserom.gba", 0x2DD020, 0x20

gUnknown_082DD040:: @ 0x082DD040
    .incbin "baserom.gba", 0x2DD040, 0x20

gUnknown_082DD060:: @ 0x082DD060
    .incbin "baserom.gba", 0x2DD060, 0x1A0

gUnknown_082DD200:: @ 0x082DD200
    .incbin "baserom.gba", 0x2DD200, 0x20

gUnknown_082DD220:: @ 0x082DD220
    .incbin "baserom.gba", 0x2DD220, 0x20

gUnknown_082DD240:: @ 0x082DD240
    .incbin "baserom.gba", 0x2DD240, 0x20

gUnknown_082DD260:: @ 0x082DD260
    .incbin "baserom.gba", 0x2DD260, 0x20

gUnknown_082DD280:: @ 0x082DD280
    .incbin "baserom.gba", 0x2DD280, 0x20

gUnknown_082DD2A0:: @ 0x082DD2A0
    .incbin "baserom.gba", 0x2DD2A0, 0x20

gUnknown_082DD2C0:: @ 0x082DD2C0
    .incbin "baserom.gba", 0x2DD2C0, 0x20

gUnknown_082DD2E0:: @ 0x082DD2E0
    .incbin "baserom.gba", 0x2DD2E0, 0x20

gUnknown_082DD300:: @ 0x082DD300
    .incbin "baserom.gba", 0x2DD300, 0x20

gUnknown_082DD320:: @ 0x082DD320
    .incbin "baserom.gba", 0x2DD320, 0x20

gUnknown_082DD340:: @ 0x082DD340
    .incbin "baserom.gba", 0x2DD340, 0x20

gUnknown_082DD360:: @ 0x082DD360
    .incbin "baserom.gba", 0x2DD360, 0x20

gUnknown_082DD380:: @ 0x082DD380
    .incbin "baserom.gba", 0x2DD380, 0x20

gUnknown_082DD3A0:: @ 0x082DD3A0
    .incbin "baserom.gba", 0x2DD3A0, 0x20

gUnknown_082DD3C0:: @ 0x082DD3C0
    .incbin "baserom.gba", 0x2DD3C0, 0x20

gUnknown_082DD3E0:: @ 0x082DD3E0
    .incbin "baserom.gba", 0x2DD3E0, 0x20

gUnknown_082DD400:: @ 0x082DD400
    .incbin "baserom.gba", 0x2DD400, 0x20

gUnknown_082DD420:: @ 0x082DD420
    .incbin "baserom.gba", 0x2DD420, 0x20

gUnknown_082DD440:: @ 0x082DD440
    .incbin "baserom.gba", 0x2DD440, 0x20

gUnknown_082DD460:: @ 0x082DD460
    .incbin "baserom.gba", 0x2DD460, 0x1C0

gUnknown_082DD620:: @ 0x082DD620
    .incbin "baserom.gba", 0x2DD620, 0x40

gUnknown_082DD660:: @ 0x082DD660
    .incbin "baserom.gba", 0x2DD660, 0x40

gUnknown_082DD6A0:: @ 0x082DD6A0
    .incbin "baserom.gba", 0x2DD6A0, 0x40

gUnknown_082DD6E0:: @ 0x082DD6E0
    .incbin "baserom.gba", 0x2DD6E0, 0x40

gUnknown_082DD720:: @ 0x082DD720
    .incbin "baserom.gba", 0x2DD720, 0x40

gUnknown_082DD760:: @ 0x082DD760
    .incbin "baserom.gba", 0x2DD760, 0x40

gUnknown_082DD7A0:: @ 0x082DD7A0
    .incbin "baserom.gba", 0x2DD7A0, 0x40

gUnknown_082DD7E0:: @ 0x082DD7E0
    .incbin "baserom.gba", 0x2DD7E0, 0x40

gUnknown_082DD820:: @ 0x082DD820
    .incbin "baserom.gba", 0x2DD820, 0x40

gUnknown_082DD860:: @ 0x082DD860
    .incbin "baserom.gba", 0x2DD860, 0x40

gUnknown_082DD8A0:: @ 0x082DD8A0
    .incbin "baserom.gba", 0x2DD8A0, 0x40

gUnknown_082DD8E0:: @ 0x082DD8E0
    .incbin "baserom.gba", 0x2DD8E0, 0x40

gUnknown_082DD920:: @ 0x082DD920
    .incbin "baserom.gba", 0x2DD920, 0x40

gUnknown_082DD960:: @ 0x082DD960
    .incbin "baserom.gba", 0x2DD960, 0x40

gUnknown_082DD9A0:: @ 0x082DD9A0
    .incbin "baserom.gba", 0x2DD9A0, 0x40

gUnknown_082DD9E0:: @ 0x082DD9E0
    .incbin "baserom.gba", 0x2DD9E0, 0x3C0

gUnknown_082DDDA0:: @ 0x082DDDA0
    .incbin "baserom.gba", 0x2DDDA0, 0x40

gUnknown_082DDDE0:: @ 0x082DDDE0
    .incbin "baserom.gba", 0x2DDDE0, 0x40

gUnknown_082DDE20:: @ 0x082DDE20
    .incbin "baserom.gba", 0x2DDE20, 0x40

gUnknown_082DDE60:: @ 0x082DDE60
    .incbin "baserom.gba", 0x2DDE60, 0x40

gUnknown_082DDEA0:: @ 0x082DDEA0
    .incbin "baserom.gba", 0x2DDEA0, 0x40

gUnknown_082DDEE0:: @ 0x082DDEE0
    .incbin "baserom.gba", 0x2DDEE0, 0x40

gUnknown_082DDF20:: @ 0x082DDF20
    .incbin "baserom.gba", 0x2DDF20, 0x40

gUnknown_082DDF60:: @ 0x082DDF60
    .incbin "baserom.gba", 0x2DDF60, 0x40

gUnknown_082DDFA0:: @ 0x082DDFA0
    .incbin "baserom.gba", 0x2DDFA0, 0x40

gUnknown_082DDFE0:: @ 0x082DDFE0
    .incbin "baserom.gba", 0x2DDFE0, 0x40

gUnknown_082DE020:: @ 0x082DE020
    .incbin "baserom.gba", 0x2DE020, 0x40

gUnknown_082DE060:: @ 0x082DE060
    .incbin "baserom.gba", 0x2DE060, 0x40

gUnknown_082DE0A0:: @ 0x082DE0A0
    .incbin "baserom.gba", 0x2DE0A0, 0x40

gUnknown_082DE0E0:: @ 0x082DE0E0
    .incbin "baserom.gba", 0x2DE0E0, 0x40

gUnknown_082DE120:: @ 0x082DE120
    .incbin "baserom.gba", 0x2DE120, 0x40

gUnknown_082DE160:: @ 0x082DE160
    .incbin "baserom.gba", 0x2DE160, 0x40

gUnknown_082DE1A0:: @ 0x082DE1A0
    .incbin "baserom.gba", 0x2DE1A0, 0x40

gUnknown_082DE1E0:: @ 0x082DE1E0
    .incbin "baserom.gba", 0x2DE1E0, 0x40

gUnknown_082DE220:: @ 0x082DE220
    .incbin "baserom.gba", 0x2DE220, 0x40

gUnknown_082DE260:: @ 0x082DE260
    .incbin "baserom.gba", 0x2DE260, 0x40

gUnknown_082DE2A0:: @ 0x082DE2A0
    .incbin "baserom.gba", 0x2DE2A0, 0x40

gUnknown_082DE2E0:: @ 0x082DE2E0
    .incbin "baserom.gba", 0x2DE2E0, 0x40

gUnknown_082DE320:: @ 0x082DE320
    .incbin "baserom.gba", 0x2DE320, 0x40

gUnknown_082DE360:: @ 0x082DE360
    .incbin "baserom.gba", 0x2DE360, 0x40

gUnknown_082DE3A0:: @ 0x082DE3A0
    .incbin "baserom.gba", 0x2DE3A0, 0x40

gUnknown_082DE3E0:: @ 0x082DE3E0
    .incbin "baserom.gba", 0x2DE3E0, 0x40

gUnknown_082DE420:: @ 0x082DE420
    .incbin "baserom.gba", 0x2DE420, 0x40

gUnknown_082DE460:: @ 0x082DE460
    .incbin "baserom.gba", 0x2DE460, 0x40

gUnknown_082DE4A0:: @ 0x082DE4A0
    .incbin "baserom.gba", 0x2DE4A0, 0x40

gUnknown_082DE4E0:: @ 0x082DE4E0
    .incbin "baserom.gba", 0x2DE4E0, 0x40

gUnknown_082DE520:: @ 0x082DE520
    .incbin "baserom.gba", 0x2DE520, 0x40

gUnknown_082DE560:: @ 0x082DE560
    .incbin "baserom.gba", 0x2DE560, 0x40

gUnknown_082DE5A0:: @ 0x082DE5A0
    .incbin "baserom.gba", 0x2DE5A0, 0x40

gUnknown_082DE5E0:: @ 0x082DE5E0
    .incbin "baserom.gba", 0x2DE5E0, 0x40

gUnknown_082DE620:: @ 0x082DE620
    .incbin "baserom.gba", 0x2DE620, 0x40

gUnknown_082DE660:: @ 0x082DE660
    .incbin "baserom.gba", 0x2DE660, 0x40

gUnknown_082DE6A0:: @ 0x082DE6A0
    .incbin "baserom.gba", 0x2DE6A0, 0x40

gUnknown_082DE6E0:: @ 0x082DE6E0
    .incbin "baserom.gba", 0x2DE6E0, 0x40

gUnknown_082DE720:: @ 0x082DE720
    .incbin "baserom.gba", 0x2DE720, 0xC0

gUnknown_082DE7E0:: @ 0x082DE7E0
    .incbin "baserom.gba", 0x2DE7E0, 0x40

gUnknown_082DE820:: @ 0x082DE820
    .incbin "baserom.gba", 0x2DE820, 0x40

gUnknown_082DE860:: @ 0x082DE860
    .incbin "baserom.gba", 0x2DE860, 0x40

gUnknown_082DE8A0:: @ 0x082DE8A0
    .incbin "baserom.gba", 0x2DE8A0, 0x40

gUnknown_082DE8E0:: @ 0x082DE8E0
    .incbin "baserom.gba", 0x2DE8E0, 0x40

gUnknown_082DE920:: @ 0x082DE920
    .incbin "baserom.gba", 0x2DE920, 0x40

gUnknown_082DE960:: @ 0x082DE960
    .incbin "baserom.gba", 0x2DE960, 0x40

gUnknown_082DE9A0:: @ 0x082DE9A0
    .incbin "baserom.gba", 0x2DE9A0, 0x40

gUnknown_082DE9E0:: @ 0x082DE9E0
    .incbin "baserom.gba", 0x2DE9E0, 0x40

gUnknown_082DEA20:: @ 0x082DEA20
    .incbin "baserom.gba", 0x2DEA20, 0x40

gUnknown_082DEA60:: @ 0x082DEA60
    .incbin "baserom.gba", 0x2DEA60, 0x40

gUnknown_082DEAA0:: @ 0x082DEAA0
    .incbin "baserom.gba", 0x2DEAA0, 0x40

gUnknown_082DEAE0:: @ 0x082DEAE0
    .incbin "baserom.gba", 0x2DEAE0, 0x40

gUnknown_082DEB20:: @ 0x082DEB20
    .incbin "baserom.gba", 0x2DEB20, 0x40

gUnknown_082DEB60:: @ 0x082DEB60
    .incbin "baserom.gba", 0x2DEB60, 0x40

gUnknown_082DEBA0:: @ 0x082DEBA0
    .incbin "baserom.gba", 0x2DEBA0, 0x40

gUnknown_082DEBE0:: @ 0x082DEBE0
    .incbin "baserom.gba", 0x2DEBE0, 0x40

gUnknown_082DEC20:: @ 0x082DEC20
    .incbin "baserom.gba", 0x2DEC20, 0x40

gUnknown_082DEC60:: @ 0x082DEC60
    .incbin "baserom.gba", 0x2DEC60, 0x40

gUnknown_082DECA0:: @ 0x082DECA0
    .incbin "baserom.gba", 0x2DECA0, 0x40

gUnknown_082DECE0:: @ 0x082DECE0
    .incbin "baserom.gba", 0x2DECE0, 0x40

gUnknown_082DED20:: @ 0x082DED20
    .incbin "baserom.gba", 0x2DED20, 0x40

gUnknown_082DED60:: @ 0x082DED60
    .incbin "baserom.gba", 0x2DED60, 0x40

gUnknown_082DEDA0:: @ 0x082DEDA0
    .incbin "baserom.gba", 0x2DEDA0, 0x40

gUnknown_082DEDE0:: @ 0x082DEDE0
    .incbin "baserom.gba", 0x2DEDE0, 0x40

gUnknown_082DEE20:: @ 0x082DEE20
    .incbin "baserom.gba", 0x2DEE20, 0x40

gUnknown_082DEE60:: @ 0x082DEE60
    .incbin "baserom.gba", 0x2DEE60, 0x40

gUnknown_082DEEA0:: @ 0x082DEEA0
    .incbin "baserom.gba", 0x2DEEA0, 0x40

gUnknown_082DEEE0:: @ 0x082DEEE0
    .incbin "baserom.gba", 0x2DEEE0, 0x40

gUnknown_082DEF20:: @ 0x082DEF20
    .incbin "baserom.gba", 0x2DEF20, 0x40

gUnknown_082DEF60:: @ 0x082DEF60
    .incbin "baserom.gba", 0x2DEF60, 0x40

gUnknown_082DEFA0:: @ 0x082DEFA0
    .incbin "baserom.gba", 0x2DEFA0, 0x40

gUnknown_082DEFE0:: @ 0x082DEFE0
    .incbin "baserom.gba", 0x2DEFE0, 0x240

gUnknown_082DF220:: @ 0x082DF220
    .incbin "baserom.gba", 0x2DF220, 0x40

gUnknown_082DF260:: @ 0x082DF260
    .incbin "baserom.gba", 0x2DF260, 0x40

gUnknown_082DF2A0:: @ 0x082DF2A0
    .incbin "baserom.gba", 0x2DF2A0, 0x40

gUnknown_082DF2E0:: @ 0x082DF2E0
    .incbin "baserom.gba", 0x2DF2E0, 0x40

gUnknown_082DF320:: @ 0x082DF320
    .incbin "baserom.gba", 0x2DF320, 0x40

gUnknown_082DF360:: @ 0x082DF360
    .incbin "baserom.gba", 0x2DF360, 0x40

gUnknown_082DF3A0:: @ 0x082DF3A0
    .incbin "baserom.gba", 0x2DF3A0, 0x40

gUnknown_082DF3E0:: @ 0x082DF3E0
    .incbin "baserom.gba", 0x2DF3E0, 0x280

gUnknown_082DF660:: @ 0x082DF660
    .incbin "baserom.gba", 0x2DF660, 0x100

gUnknown_082DF760:: @ 0x082DF760
    .incbin "baserom.gba", 0x2DF760, 0x300

gUnknown_082DFA60:: @ 0x082DFA60
    .incbin "baserom.gba", 0x2DFA60, 0x100

gUnknown_082DFB60:: @ 0x082DFB60
    .incbin "baserom.gba", 0x2DFB60, 0x320

gUnknown_082DFE80:: @ 0x082DFE80
    .incbin "baserom.gba", 0x2DFE80, 0x100

gUnknown_082DFF80:: @ 0x082DFF80
    .incbin "baserom.gba", 0x2DFF80, 0x360

gUnknown_082E02E0:: @ 0x082E02E0
    .incbin "baserom.gba", 0x2E02E0, 0x100

gUnknown_082E03E0:: @ 0x082E03E0
    .incbin "baserom.gba", 0x2E03E0, 0x2C0

gUnknown_082E06A0:: @ 0x082E06A0
    .incbin "baserom.gba", 0x2E06A0, 0x80

gUnknown_082E0720:: @ 0x082E0720
    .incbin "baserom.gba", 0x2E0720, 0x60

gUnknown_082E0780:: @ 0x082E0780
    .incbin "baserom.gba", 0x2E0780, 0x80

gUnknown_082E0800:: @ 0x082E0800
    .incbin "baserom.gba", 0x2E0800, 0x60

gUnknown_082E0860:: @ 0x082E0860
    .incbin "baserom.gba", 0x2E0860, 0x80

gUnknown_082E08E0:: @ 0x082E08E0
    .incbin "baserom.gba", 0x2E08E0, 0x180

gUnknown_082E0A60:: @ 0x082E0A60
    .incbin "baserom.gba", 0x2E0A60, 0x80

gUnknown_082E0AE0:: @ 0x082E0AE0
    .incbin "baserom.gba", 0x2E0AE0, 0x80

gUnknown_082E0B60:: @ 0x082E0B60
    .incbin "baserom.gba", 0x2E0B60, 0x80

gUnknown_082E0BE0:: @ 0x082E0BE0
    .incbin "baserom.gba", 0x2E0BE0, 0x80

gUnknown_082E0C60:: @ 0x082E0C60
    .incbin "baserom.gba", 0x2E0C60, 0x80

gUnknown_082E0CE0:: @ 0x082E0CE0
    .incbin "baserom.gba", 0x2E0CE0, 0x180

gUnknown_082E0E60:: @ 0x082E0E60
    .incbin "baserom.gba", 0x2E0E60, 0x80

gUnknown_082E0EE0:: @ 0x082E0EE0
    .incbin "baserom.gba", 0x2E0EE0, 0x80

gUnknown_082E0F60:: @ 0x082E0F60
    .incbin "baserom.gba", 0x2E0F60, 0x80

gUnknown_082E0FE0:: @ 0x082E0FE0
    .incbin "baserom.gba", 0x2E0FE0, 0x80

gUnknown_082E1060:: @ 0x082E1060
    .incbin "baserom.gba", 0x2E1060, 0x80

gUnknown_082E10E0:: @ 0x082E10E0
    .incbin "baserom.gba", 0x2E10E0, 0x180

gUnknown_082E1260:: @ 0x082E1260
    .incbin "baserom.gba", 0x2E1260, 0x80

gUnknown_082E12E0:: @ 0x082E12E0
    .incbin "baserom.gba", 0x2E12E0, 0x80

gUnknown_082E1360:: @ 0x082E1360
    .incbin "baserom.gba", 0x2E1360, 0x80

gUnknown_082E13E0:: @ 0x082E13E0
    .incbin "baserom.gba", 0x2E13E0, 0x80

gUnknown_082E1460:: @ 0x082E1460
    .incbin "baserom.gba", 0x2E1460, 0x80

gUnknown_082E14E0:: @ 0x082E14E0
    .incbin "baserom.gba", 0x2E14E0, 0x1A0

gUnknown_082E1680:: @ 0x082E1680
    .incbin "baserom.gba", 0x2E1680, 0x80

gUnknown_082E1700:: @ 0x082E1700
    .incbin "baserom.gba", 0x2E1700, 0x80

gUnknown_082E1780:: @ 0x082E1780
    .incbin "baserom.gba", 0x2E1780, 0x80

gUnknown_082E1800:: @ 0x082E1800
    .incbin "baserom.gba", 0x2E1800, 0x280

gUnknown_082E1A80:: @ 0x082E1A80
    .incbin "baserom.gba", 0x2E1A80, 0x80

gUnknown_082E1B00:: @ 0x082E1B00
    .incbin "baserom.gba", 0x2E1B00, 0x80

gUnknown_082E1B80:: @ 0x082E1B80
    .incbin "baserom.gba", 0x2E1B80, 0x80

gUnknown_082E1C00:: @ 0x082E1C00
    .incbin "baserom.gba", 0x2E1C00, 0x280

gUnknown_082E1E80:: @ 0x082E1E80
    .incbin "baserom.gba", 0x2E1E80, 0x80

gUnknown_082E1F00:: @ 0x082E1F00
    .incbin "baserom.gba", 0x2E1F00, 0x80

gUnknown_082E1F80:: @ 0x082E1F80
    .incbin "baserom.gba", 0x2E1F80, 0x80

gUnknown_082E2000:: @ 0x082E2000
    .incbin "baserom.gba", 0x2E2000, 0x280

gUnknown_082E2280:: @ 0x082E2280
    .incbin "baserom.gba", 0x2E2280, 0x80

gUnknown_082E2300:: @ 0x082E2300
    .incbin "baserom.gba", 0x2E2300, 0x80

gUnknown_082E2380:: @ 0x082E2380
    .incbin "baserom.gba", 0x2E2380, 0x80

gUnknown_082E2400:: @ 0x082E2400
    .incbin "baserom.gba", 0x2E2400, 0x6A0

gUnknown_082E2AA0:: @ 0x082E2AA0
    .incbin "baserom.gba", 0x2E2AA0, 0x60

gUnknown_082E2B00:: @ 0x082E2B00
    .incbin "baserom.gba", 0x2E2B00, 0xA0

gUnknown_082E2BA0:: @ 0x082E2BA0
    .incbin "baserom.gba", 0x2E2BA0, 0x60

gUnknown_082E2C00:: @ 0x082E2C00
    .incbin "baserom.gba", 0x2E2C00, 0x2A0

gUnknown_082E2EA0:: @ 0x082E2EA0
    .incbin "baserom.gba", 0x2E2EA0, 0x60

gUnknown_082E2F00:: @ 0x082E2F00
    .incbin "baserom.gba", 0x2E2F00, 0x80

gUnknown_082E2F80:: @ 0x082E2F80
    .incbin "baserom.gba", 0x2E2F80, 0x60

gUnknown_082E2FE0:: @ 0x082E2FE0
    .incbin "baserom.gba", 0x2E2FE0, 0x2C0

gUnknown_082E32A0:: @ 0x082E32A0
    .incbin "baserom.gba", 0x2E32A0, 0x60

gUnknown_082E3300:: @ 0x082E3300
    .incbin "baserom.gba", 0x2E3300, 0x60

gUnknown_082E3360:: @ 0x082E3360
    .incbin "baserom.gba", 0x2E3360, 0x60

gUnknown_082E33C0:: @ 0x082E33C0
    .incbin "baserom.gba", 0x2E33C0, 0x2E0

gUnknown_082E36A0:: @ 0x082E36A0
    .incbin "baserom.gba", 0x2E36A0, 0x60

gUnknown_082E3700:: @ 0x082E3700
    .incbin "baserom.gba", 0x2E3700, 0x60

gUnknown_082E3760:: @ 0x082E3760
    .incbin "baserom.gba", 0x2E3760, 0x60

gUnknown_082E37C0:: @ 0x082E37C0
    .incbin "baserom.gba", 0x2E37C0, 0x300

gUnknown_082E3AC0:: @ 0x082E3AC0
    .incbin "baserom.gba", 0x2E3AC0, 0x60

gUnknown_082E3B20:: @ 0x082E3B20
    .incbin "baserom.gba", 0x2E3B20, 0x40

gUnknown_082E3B60:: @ 0x082E3B60
    .incbin "baserom.gba", 0x2E3B60, 0x60

gUnknown_082E3BC0:: @ 0x082E3BC0
    .incbin "baserom.gba", 0x2E3BC0, 0x300

gUnknown_082E3EC0:: @ 0x082E3EC0
    .incbin "baserom.gba", 0x2E3EC0, 0x80

gUnknown_082E3F40:: @ 0x082E3F40
    .incbin "baserom.gba", 0x2E3F40, 0x80

gUnknown_082E3FC0:: @ 0x082E3FC0
    .incbin "baserom.gba", 0x2E3FC0, 0x300

gUnknown_082E42C0:: @ 0x082E42C0
    .incbin "baserom.gba", 0x2E42C0, 0x80

gUnknown_082E4340:: @ 0x082E4340
    .incbin "baserom.gba", 0x2E4340, 0x80

gUnknown_082E43C0:: @ 0x082E43C0
    .incbin "baserom.gba", 0x2E43C0, 0x300

gUnknown_082E46C0:: @ 0x082E46C0
    .incbin "baserom.gba", 0x2E46C0, 0x80

gUnknown_082E4740:: @ 0x082E4740
    .incbin "baserom.gba", 0x2E4740, 0x80

gUnknown_082E47C0:: @ 0x082E47C0
    .incbin "baserom.gba", 0x2E47C0, 0x300

gUnknown_082E4AC0:: @ 0x082E4AC0
    .incbin "baserom.gba", 0x2E4AC0, 0x80

gUnknown_082E4B40:: @ 0x082E4B40
    .incbin "baserom.gba", 0x2E4B40, 0x80

gUnknown_082E4BC0:: @ 0x082E4BC0
    .incbin "baserom.gba", 0x2E4BC0, 0x320

gSapphireBoardBGTiles:: @ 0x082E4EE0
	.incbin "baserom.gba", 0x2E4EE0, 0x8000

gSapphireBoardBGTilemap:: @ 0x082ECEE0
	.incbin "baserom.gba", 0x2ECEE0, 0x1000

gDusclopsBoardPalette:: @ 0x082EDEE0
	.incbin "baserom.gba", 0x2EDEE0, 0x200

gDusclopsAnimPalettes:: @ 0x082EE0E0
	.incbin "baserom.gba", 0x2EE0E0, 0x3E0

gDusclopsBoardBG0Tilemap:: @ 0x082EE4C0
	.incbin "baserom.gba", 0x2EE4C0, 0x13240

gDusclopsBoardBG1Tilemap:: @ 0x08301700
	.incbin "baserom.gba", 0x301700, 0x800

gDusclopsBoardBG2Tilemap:: @ 0x08301F00
	.incbin "baserom.gba", 0x301F00, 0x800

gBonusFieldCompressedBaseTiles:: @ 0x08302700
	.incbin "baserom.gba", 0x302700, 0x1228

gDusclopsBoardCompressedBGTiles:: @ 0x08303928
	.incbin "baserom.gba", 0x303928, 0x38AC

gDusclopsBodyCollisionMap:: @ 0x083071D4
	.incbin "baserom.gba", 0x3071D4, 0x5A00

gKecleonBoardPalette:: @ 0x0830CBD4
	.incbin "baserom.gba", 0x30CBD4, 0x200

gKecleonBoardBG1Tilemap:: @ 0x0830CDD4
	.incbin "baserom.gba", 0x30CDD4, 0x1ABC0

gKecleonBerryOverlayTilemap:: @ 0x08327994
	.incbin "baserom.gba", 0x327994, 0x2000

gKecleonBoardBG0Tilemap:: @ 0x08329994
	.incbin "baserom.gba", 0x329994, 0x800

gKecleonBoardCompressedBGTiles:: @ 0x0832A194
	.incbin "baserom.gba", 0x32A194, 0x3470

gKecleonTongueCollisionMap:: @ 0x0832D604
	.incbin "baserom.gba", 0x32D604, 0x2C00

gKecleonBodyCollisionMap:: @ 0x08330204
	.incbin "baserom.gba", 0x330204, 0x2C00

gKyogreBoardPalette:: @ 0x08332E04
	.incbin "baserom.gba", 0x332E04, 0x200

gKyogreWaterBackgroundTilemap:: @ 0x08333004
	.incbin "baserom.gba", 0x333004, 0xA840

gKyogreBoardBG1Tilemap:: @ 0x0833D844
	.incbin "baserom.gba", 0x33D844, 0x800

gKyogreBoardCompressedBGTiles:: @ 0x0833E044
	.incbin "baserom.gba", 0x33E044, 0x1F14

gKyogreIntroShorePalette:: @ 0x0833FF58
	.incbin "baserom.gba", 0x33FF58, 0xC00

gKyogreForm1CollisionMap:: @ 0x08340B58
	.incbin "baserom.gba", 0x340B58, 0x8E80

gKyogreForm2CollisionMap:: @ 0x083499D8
	.incbin "baserom.gba", 0x3499D8, 0x4200

gKyogreForm3CollisionMap:: @ 0x0834DBD8
	.incbin "baserom.gba", 0x34DBD8, 0x4E00

gKyogreIntroIcePalette:: @ 0x083529D8
	.incbin "baserom.gba", 0x3529D8, 0x200

gGroudonLavaPaletteCycleData:: @ 0x08352BD8
	.incbin "baserom.gba", 0x352BD8, 0x200

gGroudonBoardBG0Tilemap:: @ 0x08352DD8
	.incbin "baserom.gba", 0x352DD8, 0x800

gGroudonBoardBG1Tilemap:: @ 0x083535D8
	.incbin "baserom.gba", 0x3535D8, 0x800

gGroudonBoardCompressedBGTiles:: @ 0x08353DD8
	.incbin "baserom.gba", 0x353DD8, 0x3BF0

gGroudonBodyCollisionMap:: @ 0x083579C8
	.incbin "baserom.gba", 0x3579C8, 0x7000

gGroudonProjectileCollisionMap:: @ 0x0835E9C8
	.incbin "baserom.gba", 0x35E9C8, 0x5500

gRayquazaBoardPalette:: @ 0x08363EC8
	.incbin "baserom.gba", 0x363EC8, 0x200

gRayquazaBoardBG0Tilemap:: @ 0x083640C8
	.incbin "baserom.gba", 0x3640C8, 0xA740

gRayquazaBoardBGScrollTilemap:: @ 0x0836E808
	.incbin "baserom.gba", 0x36E808, 0x1000

gRayquazaBoardBG1Tilemap:: @ 0x0836F808
	.incbin "baserom.gba", 0x36F808, 0x1000

gRayquazaBoardCompressedBGTiles:: @ 0x08370808
	.incbin "baserom.gba", 0x370808, 0x1AE0

gRayquazaBodyCollisionMap:: @ 0x083722E8
	.incbin "baserom.gba", 0x3722E8, 0x8000

gSphealBoardPalette:: @ 0x0837A2E8
	.incbin "baserom.gba", 0x37A2E8, 0x200

gSphealWaterBackgroundTilemap:: @ 0x0837A4E8
	.incbin "baserom.gba", 0x37A4E8, 0x13B40

gSphealBoardBG1Tilemap:: @ 0x0838E028
	.incbin "baserom.gba", 0x38E028, 0x800

gSphealBoardCompressedBGTiles:: @ 0x0838E828
	.incbin "baserom.gba", 0x38E828, 0x3224

gSphealCrackedIceCollisionMap:: @ 0x08391A4C
	.incbin "baserom.gba", 0x391A4C, 0x2000

gSphealFrozenIceCollisionMap:: @ 0x08393A4C
	.incbin "baserom.gba", 0x393A4C, 0x2000

gPikaSaverFullCoverageGfx:: @ 0x08395A4C
	.incbin "baserom.gba", 0x395A4C, 0x2420

gPikaSaverPartialCoverageGfx:: @ 0x08397E6C
	.incbin "baserom.gba", 0x397E6C, 0x2420

gCatchTargetCollisionBitmap:: @ 0x0839A28C
	.incbin "baserom.gba", 0x39A28C, 0x900

.include "data/graphics/mon_portraits_pals.inc"

gSapphireCatchTilesGfx:: @ 0x0839C78C
	.incbin "baserom.gba", 0x39C78C, 0x1420

gSapphireCatchPalette:: @ 0x0839DBAC
	.incbin "baserom.gba", 0x39DBAC, 0x200

gHatchRevealTilesGfx:: @ 0x0839DDAC
	.incbin "baserom.gba", 0x39DDAC, 0x2820

gHatchRevealPalette:: @ 0x083A05CC
	.incbin "baserom.gba", 0x3A05CC, 0x200

gHatchStartTilesGfx:: @ 0x083A07CC
	.incbin "baserom.gba", 0x3A07CC, 0x2020

gHatchStartPalette:: @ 0x083A27EC
	.incbin "baserom.gba", 0x3A27EC, 0x200

gHatchStage2TilesGfx:: @ 0x083A29EC
	.incbin "baserom.gba", 0x3A29EC, 0x820

gHatchStage2Palette:: @ 0x083A320C
	.incbin "baserom.gba", 0x3A320C, 0x200

gHatchStage3TilesGfx:: @ 0x083A340C
	.incbin "baserom.gba", 0x3A340C, 0x2020

gHatchStage3Palette:: @ 0x083A542C
	.incbin "baserom.gba", 0x3A542C, 0x200

gHatchFinalTilesGfx:: @ 0x083A562C
	.incbin "baserom.gba", 0x3A562C, 0x1820

gHatchFinalPalette:: @ 0x083A6E4C
	.incbin "baserom.gba", 0x3A6E4C, 0x200

gEggModeTilesGfx:: @ 0x083A704C
	.incbin "baserom.gba", 0x3A704C, 0x1020

gEggModePalette:: @ 0x083A806C
	.incbin "baserom.gba", 0x3A806C, 0x20

gCaptureModePalette:: @ 0x083A808C
	.incbin "baserom.gba", 0x3A808C, 0x1E0

gBoardHudTilemapB:: @ 0x083A826C
	.incbin "baserom.gba", 0x3A826C, 0x820

gShopPalette:: @ 0x083A8A8C
	.incbin "baserom.gba", 0x3A8A8C, 0x20

gTravelPortraitPalette:: @ 0x083A8AAC
	.incbin "baserom.gba", 0x3A8AAC, 0x20

gBoardHudTilemapA:: @ 0x083A8ACC
	.incbin "baserom.gba", 0x3A8ACC, 0x420

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

gBallShadowTileGraphics:: @ 0x083BD36C
	.incbin "baserom.gba", 0x3BD36C, 0xC00

gBallSpawnGlowTiles_Type2:: @ 0x083BDF6C
	.incbin "baserom.gba", 0x3BDF6C, 0x1200

gBallSpawnGlowTiles_Type1:: @ 0x083BF16C
	.incbin "baserom.gba", 0x3BF16C, 0x1600

gSpoinkEntity_Gfx:: @ 0x083C076C
	.incbin "baserom.gba", 0x3C076C, 0xC40

gKyogreSplashSpriteFrames:: @ 0x083C13AC
	.incbin "baserom.gba", 0x3C13AC, 0x6C0

gKyogreWhirlpoolSpriteFrames:: @ 0x083C1A6C
	.incbin "baserom.gba", 0x3C1A6C, 0x21C0

gRubyFlashingDecorationTiles:: @ 0x083C3C2C
	.incbin "baserom.gba", 0x3C3C2C, 0x1800

gChikoritaProjectileTiles:: @ 0x083C542C
	.incbin "baserom.gba", 0x3C542C, 0x200

gChikoritaExplosionTiles:: @ 0x083C562C
	.incbin "baserom.gba", 0x3C562C, 0x400

gRayquazaSkyBackgroundGfx:: @ 0x083C5A2C
	.incbin "baserom.gba", 0x3C5A2C, 0x2640

gRubyFlashingTiles_Secondary:: @ 0x083C806C
	.incbin "baserom.gba", 0x3C806C, 0xB00

.include "data/graphics/mon_hatch_sprites.inc"

gPickupIcon1_Gfx:: @ 0x083EB84C
	.incbin "graphics/board_pickups/icon1.4bpp"
gPickupIcon2_Gfx:: @ 0x083ED64C
	.incbin "graphics/board_pickups/icon2.4bpp"
gPickupIcon3_Gfx:: @ 0x083EF44C
	.incbin "graphics/board_pickups/icon3.4bpp"
gPickupIcon9_Gfx:: @ 0x083F124C
	.incbin "graphics/board_pickups/icon9.4bpp"
gPickupIcon4_Gfx:: @ 0x083F304C
	.incbin "graphics/board_pickups/icon4.4bpp"
gPickupIcon5_Gfx:: @ 0x083F4E4C
	.incbin "graphics/board_pickups/icon5.4bpp"
gPickupIcon6_Gfx:: @ 0x083F6C4C
	.incbin "graphics/board_pickups/icon6.4bpp"
gPickupIcon10_Gfx:: @ 0x083F8A4C
	.incbin "graphics/board_pickups/icon10.4bpp"
gPickupIcon8_Gfx:: @ 0x083FA84C
	.incbin "graphics/board_pickups/icon8.4bpp"
gPickupIcon7_Gfx:: @ 0x083FC64C
	.incbin "graphics/board_pickups/icon7.4bpp"

gFlipperTileGraphics:: @ 0x083FE44C
	.incbin "baserom.gba", 0x3FE44C, 0xC00

gAlphabetTilesGfx:: @ 0x083FF04C
	.incbin "baserom.gba", 0x3FF04C, 0xD00

gSpaceTileGfx:: @ 0x083FFD4C
	.incbin "baserom.gba", 0x3FFD4C, 0x40

gSapphireBoardWailmer_Gfx:: @ 0x083FFD8C
	.incbin "graphics/stage/sapphire/wailmer.4bpp";

	.include "data/graphics/mon_catch_sprites.inc"

gRubyStageGulpin_Gfx:: @ 0x08447A8C
	.incbin "graphics/stage/ruby/gulpin.4bpp"

gMainStageBonusTrap_Gfx:: @ 0x0844838C
	.incbin "graphics/stage/main/bonus_trap.4bpp"

gLotadBumperTiles:: @ 0x0844928C
	.incbin "baserom.gba", 0x44928C, 0xB00

gRubyStageCyndaquil_Gfx:: @ 0x08449D8C
	.incbin "graphics/stage/ruby/cyndaquil.4bpp"

gBasketAnimationTilesGfx:: @ 0x0844AA0C
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

gSplashEffectTileGfx:: @ 0x0845A08C
	.incbin "baserom.gba", 0x45A08C, 0x400

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
	.incbin "baserom.gba", 0x4779EC, 0x2A20

gSapphireBumperLeft_Gfx:: @ 0x0847A40C
	.incbin "baserom.gba", 0x47A40C, 0x2D00

gSapphireBumperLeftHit_Gfx:: @ 0x0847D10C
	.incbin "baserom.gba", 0x47D10C, 0xE00

gRubyRampGateTileGfx:: @ 0x0847DF0C
	.incbin "baserom.gba", 0x47DF0C, 0x1E00

gSideBumperGfx:: @ 0x0847FD0C
	.incbin "baserom.gba", 0x47FD0C, 0x200

gShopDigitTilesGfx:: @ 0x0847FF0C
	.incbin "baserom.gba", 0x47FF0C, 0xF00

gDecimalDigitTilesGfx:: @ 0x08480E0C
	.incbin "baserom.gba", 0x480E0C, 0x280

gSapphireShopSignTileGfx:: @ 0x0848108C
	.incbin "baserom.gba", 0x48108C, 0x2D00

gRubyTravelVolbeat_Gfx:: @ 0x08483D8C
	.incbin "baserom.gba", 0x483D8C, 0x4C80

gSapphireTravelIllumise_Gfx:: @ 0x08488A0C
	.incbin "baserom.gba", 0x488A0C, 0x4C80

gPortraitGenericGraphics:: @ 0x0848D68C
	.incbin "baserom.gba", 0x48D68C, 0x2700

gCaptureModeTilesGfx:: @ 0x0848FD8C
	.incbin "baserom.gba", 0x48FD8C, 0xCC0

gHoleIndicatorTileGfx:: @ 0x08490A4C
	.incbin "baserom.gba", 0x490A4C, 0x4400

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x08494E4C
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gKyogreBodySprites_First15:: @ 0x0849664C
	.incbin "baserom.gba", 0x49664C, 0x5280

gKyogreBodySprites_After15:: @ 0x0849B8CC
	.incbin "baserom.gba", 0x49B8CC, 0x3900

gGroudonBoardBackgroundGfx:: @ 0x0849F1CC
	.incbin "baserom.gba", 0x49F1CC, 0x2020

gGroudonBoulderSpriteFrames:: @ 0x084A11EC
	.incbin "baserom.gba", 0x4A11EC, 0x5D00

gRayquazaMinionOrbFrames:: @ 0x084A6EEC
	.incbin "baserom.gba", 0x4A6EEC, 0x1680

gRayquazaWindBoardGfx:: @ 0x084A856C
	.incbin "baserom.gba", 0x4A856C, 0x1C20

gRayquazaSpriteSheet:: @ 0x084AA18C
	.incbin "baserom.gba", 0x4AA18C, 0x860

gRayquazaBodyVariantTiles:: @ 0x084AA9EC
	.incbin "baserom.gba", 0x4AA9EC, 0x5000

gSphealScoreCounterDigitSprites:: @ 0x084AF9EC
	.incbin "baserom.gba", 0x4AF9EC, 0x600

gSphealExtendedScoreSprites:: @ 0x084AFFEC
	.incbin "baserom.gba", 0x4AFFEC, 0x480

gSphealFlyingEnemyVariantSprites:: @ 0x084B046C
	.incbin "baserom.gba", 0x4B046C, 0x4380

gSphealMinionBodySprites:: @ 0x084B47EC
	.incbin "baserom.gba", 0x4B47EC, 0x3000

gSphealResultsScreenGfx:: @ 0x084B77EC
	.incbin "baserom.gba", 0x4B77EC, 0x800

gWhiscash_Gfx:: @ 0x084B7FEC
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelipper_Gfx:: @ 0x084BB16C
	.incbin "graphics/stage/sapphire/pelipper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gChargeFillIndicator_Gfx:: @ 0x084C00EC
	.incbin "graphics/stage/main/charge_fill_indicator.4bpp"

gPikaSaverTilesGfx:: @ 0x084C07EC
	.incbin "baserom.gba", 0x4C07EC, 0x480

gDxModePikachuObjTiles:: @ 0x084C0C6C
	.incbin "baserom.gba", 0x4C0C6C, 0x900

gPikachuSaverTilesGfx:: @ 0x084C156C
	.incbin "baserom.gba", 0x4C156C, 0x900

gSapphireBumperRight_Gfx:: @ 0x084C1E6C
	.incbin "baserom.gba", 0x4C1E6C, 0x2D00

gSapphireBumperRightHit_Gfx:: @ 0x084C4B6C
	.incbin "baserom.gba", 0x4C4B6C, 0xE00

.include "data/graphics/mon_portraits.inc"

.incbin "baserom.gba", 0x4ECF6C, 0x160 @ 0x4ED0CC - 0x4ECF6C

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

gKyogreWhirlpoolMinionSprites:: @ 0x084FF90C
	.incbin "baserom.gba", 0x4FF90C, 0x1700

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

gUnknown_08505B8C:: @ 0x08505B8C
	.incbin "baserom.gba", 0x505B8C, 0x40

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
	.incbin "baserom.gba", 0x514F4C, 0x20

gBonusStagePal_Dark:: @ 0x08514F6C
	.incbin "baserom.gba", 0x514F6C, 0x1E0

gUnknown_0851514C:: @ 0x0851514C
	.incbin "baserom.gba", 0x51514C, 0x4420

gUnknown_0851956C:: @ 0x0851956C
    .incbin "baserom.gba", 0x51956C, 0x20

gUnknown_0851958C:: @ 0x0851958C
    .incbin "baserom.gba", 0x51958C, 0x20

gUnknown_085195AC:: @ 0x085195AC
    .incbin "baserom.gba", 0x5195AC, 0x1C0

gUnknown_0851976C:: @ 0x0851976C
	.incbin "baserom.gba", 0x51976C, 0x4420

gUnknown_0851DB8C:: @ 0x0851DB8C
	.incbin "baserom.gba", 0x51DB8C, 0x4420

gBonusClearTextPal_Lit:: @ 0x08521FAC
	.incbin "baserom.gba", 0x521FAC, 0x20

gBonusClearTextPal_Dark:: @ 0x08521FCC
	.incbin "baserom.gba", 0x521FCC, 0x1E0

gUnknown_085221AC:: @ 0x085221AC
    .incbin "baserom.gba", 0x5221AC, 0x200

gUnknown_085223AC:: @ 0x085223AC
	.incbin "baserom.gba", 0x5223AC, 0x4420

gUnknown_085267CC:: @ 0x085267CC
    .incbin "baserom.gba", 0x5267CC, 0x200

gUnknown_085269CC:: @ 0x085269CC
    .incbin "baserom.gba", 0x5269CC, 0x200

gUnknown_08526BCC:: @ 0x08526BCC
    .incbin "baserom.gba", 0x526BCC, 0x200

gSapphireBoardZigzagoonFx_Gfx:: @ 0x08526DCC
	.incbin "graphics/stage/sapphire/zigzagoon_fx.4bpp";

	.incbin "baserom.gba", 0x5279CC, 0x356


gOptionsBGMList:: @ 0x08527D22
	.2byte MUS_TITLE, MUS_TABLE_SELECT, MUS_UNKNOWN_0x5, MUS_OPENING, MUS_HIGH_SCORE
	.2byte MUS_POKEDEX, MUS_SHOP, MUS_SLOTS_PRIZE, MUS_END_OF_BALL, MUS_BONUS_CHANCE, MUS_BONUS_CHANCE_LEGENDARY
	.2byte MUS_TRAVEL_MODE_START, MUS_SUCCESS, MUS_UNKNOWN_0x14, MUS_EGG_MODE, MUS_EGG_MODE_START
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
    .2byte SE_TRAVEL_PAINTER_FLIGHT, SE_TRAVEL_PAINTER_PAINTS, SE_UNKNOWN_0x99, SE_UNKNOWN_0x9A, SE_UNKNOWN_0x9B
    .2byte SE_UNKNOWN_0x9C, SE_UNKNOWN_0x9D, SE_UNKNOWN_0x9E, SE_WARP, SE_UNKNOWN_0xA1
    .2byte SE_UNKNOWN_0xA2, SE_UNKNOWN_0xA3, SE_UNKNOWN_0xA4, SE_UNKNOWN_0xA5, SE_UNKNOWN_0xA6
    .2byte SE_UNKNOWN_0xA7, SE_PIKA_CHARGE_DO, SE_PIKA_CHARGE_RE, SE_PIKA_CHARGE_MI, SE_PIKA_CHARGE_FA
    .2byte SE_PIKA_CHARGE_SO, SE_PIKA_CHARGE_LA, SE_PIKA_CHARGE_TI, SE_PIKA_CHARGE_HIGH_DO, SE_UNKNOWN_0xB0
    .2byte SE_RUBY_BUMPER_HIT, SE_UNKNOWN_0xB7, SE_UNKNOWN_0xB8, SE_UNKNOWN_0xB9, SE_UNKNOWN_0xBD
    .2byte SE_UNKNOWN_0xC2, SE_UNKNOWN_0xC3, SE_UNKNOWN_0xC5, SE_UNKNOWN_0xC6, SE_UNKNOWN_0xC7
    .2byte SE_RUBY_BUMPER_EMERGES, SE_RUBY_BUMPER_LEAVES, SE_UNKNOWN_0xCA, SE_UNKNOWN_0xCC, SE_UNKNOWN_0xCD
    .2byte SE_UNKNOWN_0xCE, SE_UNKNOWN_0xCF, SE_UNKNOWN_0xD0, SE_UNKNOWN_0xD1, SE_UNKNOWN_0xD2
    .2byte SE_WHISCASH_EMERGE_SPLASH, SE_WHISCASH_LEAVE_BURBLE, SE_WHISCASH_CATCH_BALL, SE_WHISCASH_SPIT_BALL, SE_WHISCASH_SPLASHDOWN
    .2byte SE_UNKNOWN_0xD8, SE_UNKNOWN_0xDC, SE_UNKNOWN_0xDD, SE_UNKNOWN_0xDE, SE_UNKNOWN_0xDF
    .2byte SE_UNKNOWN_0xE0, SE_UNKNOWN_0xE1, SE_UNKNOWN_0xE2, SE_UNKNOWN_0xE3, SE_UNKNOWN_0xE4

    .2byte SE_UNKNOWN_0xE5, SE_UNKNOWN_0xE6, SE_UNKNOWN_0xE7, SE_UNKNOWN_0xE8, SE_UNKNOWN_0xE9
    .2byte SE_UNKNOWN_0xEA, SE_UNKNOWN_0xEB, SE_UNKNOWN_0xEC, SE_DUSKULL_APPEAR, SE_DUSKULL_DEATH_CRY
    .2byte SE_DUSCLOPS_DEPART_INCOMPLETE, SE_DUSCLOPS_MOVE, SE_DUSCLOPS_APPEAR, SE_DUSCLOPS_HIT, SE_DUSCLOPS_BALL_ABSORB
    .2byte SE_DUSCLOPS_BALL_LAUNCH, SE_UNKNOWN_0xF9, SE_UNKNOWN_0xFC, SE_UNKNOWN_0xFD, SE_UNKNOWN_0xFE
    .2byte SE_UNKNOWN_0xFF, SE_UNKNOWN_0x100, SE_UNKNOWN_0x101, SE_UNKNOWN_0x102, SE_UNKNOWN_0x103
    .2byte SE_KECLEON_TREE_HIT, SE_KECLEON_SCOPE_FALL, SE_KECLEON_SCOPE_ACTIVATED, SE_UNKNOWN_0x10A, SE_UNKNOWN_0x10B
    .2byte SE_UNKNOWN_0x10C, SE_UNKNOWN_0x10D, SE_UNKNOWN_0x10E, SE_UNKNOWN_0x10F, SE_UNKNOWN_0x110
    .2byte SE_UNKNOWN_0x111, SE_UNKNOWN_0x112, SE_UNKNOWN_0x113, SE_UNKNOWN_0x118, SE_GROUDON_STEP
    .2byte SE_UNKNOWN_0x11A, SE_UNKNOWN_0x11B, SE_UNKNOWN_0x11C, SE_UNKNOWN_0x11D, SE_UNKNOWN_0x11E
    .2byte SE_UNKNOWN_0x11F, SE_UNKNOWN_0x120, SE_GROUDON_BOULDER_LAND, SE_GROUDON_DUSTORM_LIFT, SE_GROUDON_BALL_HIT_FIRE
    .2byte SE_RAYQUAZA_HIT, SE_RAYQUAZA_WIND, SE_UNKNOWN_0x128, SE_RAYQUAZA_FLYBY, SE_UNKNOWN_0x12A
    .2byte SE_UNKNOWN_0x12B, SE_UNKNOWN_0x12C, SE_UNKNOWN_0x12D, SE_RAYQUAZA_STAGE_WIND, SE_UNKNOWN_0x134
    .2byte SE_UNKNOWN_0x135, SE_UNKNOWN_0x136, SE_UNKNOWN_0x137, SE_UNKNOWN_0x138, SE_UNKNOWN_0x139
    .2byte SE_UNKNOWN_0x13B, SE_UNKNOWN_0x13C, SE_UNKNOWN_0x13D, SE_UNKNOWN_0x13E, SE_UNKNOWN_0x140
    .2byte SE_JIRACHI_MOVE, SE_JIRACHI_HIT, SE_UNKNOWN_0x146, SE_UNKNOWN_0x147, SE_UNKNOWN_0x148
    .2byte SE_UNKNOWN_0x149, SE_WHISCASH_EARTHQUAKE, SE_HIGH_SCORE_EARNED, SE_UNKNOWN_0x14B, SE_UNKNOWN_0x71
    .2byte SE_PIKACHU_KICKBACK, SE_UNKNOWN_0xB2, SE_PICHU_KICKBACK, SE_PIKA_NO_KICKBACK


gDefaultButtonConfigs:: @ 0x08527ED6
	@4 sets of 10
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x09, 0x08;
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x01, 0x0A;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x00, 0x0A, 0x05, 0x00;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x04, 0x0A, 0x06, 0x0A;

gDefaultCustomButtonConfigTileIds:: @ 0x08527EFE
	.incbin "baserom.gba", 0x527EFE, 0xA

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

.incbin "baserom.gba", 0x52D888, 0xA0 @ 0x52D928 - 0x52D888
