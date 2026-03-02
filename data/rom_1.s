.section .rodata
#include "constants/areas.h"
#include "constants/fields.h"
#include "constants/species.h"
#include "constants/bg_music.h"
#include "gba/io_reg.h"
	.include "asm/macros.inc"

gUnknown_08055A68:: @ 0x08055A68
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
	.4byte Pokedex_State2_43D4          @ POKEDEX_STATE_2
	.4byte Pokedex_State3_4428          @ POKEDEX_STATE_3
	.4byte Pokedex_State4_4860          @ POKEDEX_STATE_4
	.4byte Pokedex_State5_45A4          @ POKEDEX_STATE_5
	.4byte Pokedex_LinkSetup            @ POKEDEX_STATE_LINK_SETUP
	.4byte Pokedex_State7_49D0          @ POKEDEX_STATE_7
	.4byte Pokedex_State8_4B34          @ POKEDEX_STATE_8
	.4byte Pokedex_State9_4BB4          @ POKEDEX_STATE_9
	.4byte Pokedex_State10_4B10         @ POKEDEX_STATE_10
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
	.4byte sub_9498
	.4byte sub_978C
	.4byte sub_9830
	.4byte sub_9878
	.4byte sub_98B4
	.4byte sub_9920
	.4byte sub_999C
	.4byte sub_9AB8
	.4byte nullsub_4
	.4byte sub_9C10
	.4byte nullsub_5
	.4byte nullsub_17
	.4byte sub_9C9C
	.4byte sub_A154
	.4byte sub_A16C
	.4byte nullsub_6
	.4byte sub_A2F0
	.4byte nullsub_7
	.4byte sub_A39C
	.4byte sub_A43C
	.4byte sub_A454
	.4byte sub_A674
	.4byte sub_A710
	.4byte nullsub_8
	.4byte sub_A860
	.4byte sub_A950
	.4byte sub_A968
	.4byte nullsub_9
	.4byte sub_AAF4
	.4byte nullsub_10
	.4byte sub_AB90
	.4byte sub_AC20
	.4byte sub_AC38
	.4byte sub_AE74
	.4byte sub_AF80
	.4byte nullsub_11
	.4byte sub_B090
	.4byte sub_B2E0
	.4byte sub_B2F8
	.4byte sub_B560
	.4byte sub_B6C4
	.4byte sub_B7A0
	.4byte sub_BA2C
	.4byte sub_BA3C
	.4byte sub_BC54
	.4byte sub_BCE8
	.4byte sub_BDC0
	.4byte sub_BED0
	.4byte sub_C018
	.4byte sub_C0BC
	.4byte sub_C210
	.4byte sub_C228
	.4byte sub_C38C
	.4byte sub_C3D0
	.4byte sub_C450
	.4byte nullsub_12
	.4byte nullsub_13
	.4byte sub_C498
	.4byte sub_C814
	.4byte sub_C948
	.4byte sub_CAA0
	.4byte sub_CB6C
	.4byte sub_CBA4
	.4byte nullsub_14
	.4byte sub_CC94
	.4byte sub_CCF8

gHighScoresStateFuncs:: @ 0x080793E8
	.4byte LoadHighScoreGraphics
	.4byte HighScore_State1_D20C
	.4byte HighScore_State2_D308
	.4byte HighScore_State3_D4B8
	.4byte HighScore_State4_D664
	.4byte HighScore_State5_D9F8
	.4byte HighScore_State6_DA20
	.4byte HighScore_State7_DB70
	.4byte HighScore_State8_DBF4
	.4byte HighScore_State9_DB4C
	.4byte HighScore_State10_DCF0
	.4byte HighScore_State11_DD4C
	.4byte HighScore_State12_E0EC
	.4byte HighScore_State13_E230
	.4byte HighScore_State14_E390

gIdleHighScoresStateFuncs:: @ 0x08079424
	.4byte IdleHighScore_State0_DD70
	.4byte IdleHighScore_State1_DF68
	.4byte IdleHighScore_State2_E0C4

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

gUnknown_08079730:: @ 0x08079730
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

gUnknown_080797F0:: @ 0x080797F0
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

gUnknown_08079870:: @ 0x08079870
	.4byte 0x02, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11

gTitlescreenStateFuncs:: @ 0x08079890
	.4byte LoadTitlescreenGraphics           @ SUBSTATE_LOAD_GRAPHICS
	.4byte TitleScreen1_WaitForStartButton   @ SUBSTATE_WAIT_FOR_START_BUTTON
	.4byte TitleScreen2_8010CF0              @ SUBSTATE_2
	.4byte TitleScreen3_8010E00              @ SUBSTATE_3
	.4byte TitleScreen4_MenuInputNoSavedGame @ SUBSTATE_MENU_INPUT_NO_SAVED_GAME
	.4byte TitleScreen5_MenuInputSavedGame   @ SUBSTATE_MENU_INPUT_SAVED_GAME
	.4byte TitleScreen6_AnimCloseMenu        @ SUBSTATE_ANIM_CLOSE_MENU
	.4byte TitleScreen7_8011020              @ SUBSTATE_7
	.4byte TitleScreen8_8011228              @ SUBSTATE_8
	.4byte TitleScreen9_8010D84              @ SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION
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

gUnknown_0807DD00:: @ 0x0807DD00
	.incbin "baserom.gba", 0x7DD00, 0x2000

gUnknown_0807FD00:: @ 0x0807FD00
	.incbin "baserom.gba", 0x7FD00, 0x800

gEReaderBackground_Gfx:: @ 0x08080500
	.incbin "graphics/ereader/background.4bpp"
	.space 0x20

gUnknown_08081D20:: @ 0x08081D20
	.incbin "baserom.gba", 0x81D20, 0x200

gPokedexBg1_Tilemap:: @ 0x08081F20
	.incbin "graphics/pokedex/bg1_tilemap.bin"

gPokedexBgText_Gfx:: @ 0x08082720
	.incbin "graphics/pokedex/bg_text.4bpp"
	.space 0x20

gUnknown_08086B40:: @ 0x08086B40
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

gUnknown_080947A0:: @ 0x080947A0
	.incbin "baserom.gba", 0x947A0, 0x1000

gHighScoreText_Gfx:: @ 0x080957A0
	.incbin "graphics/high_score/text.4bpp"
	.space 0x20

gUnknown_08099FC0:: @ 0x08099FC0
	.incbin "baserom.gba", 0x99FC0, 0x1000

gHighScoreBallWatermark_Gfx:: @ 0x0809AFC0
	.incbin "graphics/high_score/ball_watermark.4bpp"
	.space 0x20

gUnknown_0809DBE0:: @ 0x0809DBE0
	.incbin "baserom.gba", 0x9DBE0, 0x200

gUnknown_0809DDE0:: @ 0x0809DDE0
	.incbin "baserom.gba", 0x9DDE0, 0x200

gHighScoreDialogs_Gfx:: @ 0x0809DFE0
	@ sheet includes transmission windows, and the
	@ pokedex completion certificate, with latios/latias
	.incbin "graphics/high_score/dialogs.4bpp"
	.space 0x20

gUnknown_080A2400:: @ 0x080A2400
	.incbin "baserom.gba", 0xA2400, 0x800

.include "data/graphics/field_select.inc"

gEReaderText_Gfx:: @ 0x080ACC60
	.incbin "graphics/ereader/text.4bpp"
	.space 0x240

gIntroScene1Sprites_Pals:: @ 0x080B3AA0
	.incbin "graphics/intro/scene_1_sprites.gbapal"

gUnknown_080B3CA0:: @ 0x080B3CA0
	.incbin "baserom.gba", 0xB3CA0, 0x800

gIntroScene1Text_Gfx:: @ 0x080B44A0
	.incbin "graphics/intro/scene_1_text.4bpp"
	.space 0x20

gUnknown_080B9CC0:: @ 0x080B9CC0
	.incbin "baserom.gba", 0xB9CC0, 0x1800

gUnknown_080BB4C0:: @ 0x080BB4C0
	.incbin "baserom.gba", 0xBB4C0, 0x1000

gUnknown_080BC4C0:: @ 0x080BC4C0
	.incbin "baserom.gba", 0xBC4C0, 0x1000

gIntroScene1Ball_Gfx:: @ 0x080BD4C0
	.incbin "graphics/intro/scene_1_ball.4bpp"
	.space 0x20

gIntroScene1Sprites_Gfx:: @ 0x080C3CE0
	.incbin "graphics/intro/scene_1_sprites.4bpp"

gUnknown_080CBCE0:: @ 0x080CBCE0
	.incbin "baserom.gba", 0xCBCE0, 0x200

gUnknown_080CBEE0:: @ 0x080CBEE0
	.incbin "baserom.gba", 0xCBEE0, 0x800

gIntroScene2Sprites_Gfx:: @ 0x080CC6E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pichu/pikachu
	.incbin "graphics/intro/scene_2_sprites.4bpp"
	.space 0x20

gUnknown_080D0700:: @ 0x080D0700
	.incbin "baserom.gba", 0xD0700, 0x2000

gUnknown_080D2700:: @ 0x080D2700
	.incbin "baserom.gba", 0xD2700, 0x2000

gUnknown_080D4700:: @ 0x080D4700
	.incbin "baserom.gba", 0xD4700, 0x200

gUnknown_080D4900:: @ 0x080D4900
	.incbin "baserom.gba", 0xD4900, 0x1000

gUnknown_080D5900:: @ 0x080D5900
	.incbin "baserom.gba", 0xD5900, 0x800

gIntroScene3Sprites_Gfx:: @ 0x080D6100
	@ intro pane with treeko, pinball, flipper
	.incbin "graphics/intro/scene_3_sprites.4bpp"
	.space 0x20

gUnknown_080DCD20:: @ 0x080DCD20
	.incbin "baserom.gba", 0xDCD20, 0x800

gUnknown_080DD520:: @ 0x080DD520
	.incbin "baserom.gba", 0xDD520, 0x800

gUnknown_080DDD20:: @ 0x080DDD20
	.incbin "baserom.gba", 0xDDD20, 0x800

gUnknown_080DE520:: @ 0x080DE520
	.incbin "baserom.gba", 0xDE520, 0x1000

gIntroScene3Treecko_Gfx:: @ 0x080DF520
	.incbin "graphics/intro/treecko.4bpp"
	.space 0x20

gUnknown_080E1540:: @ 0x080E1540
	.incbin "baserom.gba", 0xE1540, 0x200

gUnknown_080E1740:: @ 0x080E1740
	.incbin "baserom.gba", 0xE1740, 0x800

gIntroScene4Sprites_Gfx:: @ 0x080E1F40
	.incbin "graphics/intro/scene_4_sprites.4bpp"

gUnknown_080E5F60:: @ 0x080E5F60
	.incbin "baserom.gba", 0xE5F60, 0x2000

gUnknown_080E7F60:: @ 0x080E7F60
	.incbin "baserom.gba", 0xE7F60, 0x2000

gUnknown_080E9F60:: @ 0x080E9F60
	.incbin "baserom.gba", 0xE9F60, 0x200

gUnknown_080EA160:: @ 0x080EA160
	.incbin "baserom.gba", 0xEA160, 0x1000

gUnknown_080EB160:: @ 0x080EB160
	.incbin "baserom.gba", 0xEB160, 0x1000

gUnknown_080EC160:: @ 0x080EC160
	.incbin "baserom.gba", 0xEC160, 0x800

gIntroScene5Text_Gfx:: @ 0x080EC960
	.incbin "graphics/intro/scene_5_text.4bpp"
	.space 0x20

gUnknown_080F1980:: @ 0x080F1980
	.incbin "baserom.gba", 0xF1980, 0x800

gIntroScene5Sprites_Gfx:: @ 0x080F2180
	.incbin "graphics/intro/scene_5_sprites.4bpp"
	.space 0x20
	.incbin "baserom.gba", 0xF51A0, 0x1000

gUnknown_080F61A0:: @ 0x080F61A0
	.incbin "baserom.gba", 0xF61A0, 0x200

gUnknown_080F63A0:: @ 0x080F63A0
	.incbin "baserom.gba", 0xF63A0, 0x800

gIntroScene6Sprites_Gfx:: @ 0x080F6BA0
	.incbin "graphics/intro/scene_6_sprites.4bpp"
	.space 0x20

gUnknown_080FCFC0:: @ 0x080FCFC0
	.incbin "baserom.gba", 0xFCFC0, 0x800

gUnknown_080FD7C0:: @ 0x080FD7C0
	.incbin "baserom.gba", 0xFD7C0, 0x800

gUnknown_080FDFC0:: @ 0x080FDFC0
	.incbin "baserom.gba", 0xFDFC0, 0x2000

gIntroScene6Stars_Gfx:: @ 0x080FFFC0
	.incbin "graphics/intro/scene_6_stars.4bpp"
	.space 0x20

gUnknown_08100FE0:: @ 0x08100FE0
	.incbin "baserom.gba", 0x100FE0, 0x200

gUnknown_081011E0:: @ 0x081011E0
	.incbin "baserom.gba", 0x1011E0, 0x800

gIntroScene7Sprites_Gfx:: @ 0x081019E0
	@ this has diagonal stripes with "Pokemon Pinball" in 2 colors
	@ with mostly blank secondary rows (reusing tiles)
	@ (shown in pink with yellow text)
	@ sheet also includes pelipper, makuhita, spoink

	.incbin "graphics/intro/scene_7_sprites.4bpp"
	.space 0x20

gUnknown_08106A00:: @ 0x08106A00
	.incbin "baserom.gba", 0x106A00, 0x2000

gUnknown_08108A00:: @ 0x08108A00
	.incbin "baserom.gba", 0x108A00, 0x2000

gUnknown_0810AA00:: @ 0x0810AA00
	.incbin "baserom.gba", 0x10AA00, 0x2000

gIntroScene7Wailmer_Gfx:: @ 0x0810CA00
	.incbin "graphics/intro/scene_7_wailmer.4bpp"
	.space 0x20

gUnknown_0810EA20:: @ 0x0810EA20
	.incbin "baserom.gba", 0x10EA20, 0x200

gUnknown_0810EC20:: @ 0x0810EC20
	.incbin "baserom.gba", 0x10EC20, 0x800

gIntroScene7Explosion_Gfx:: @ 0x0810F420
	.incbin "graphics/intro/scene_7_explosion.4bpp"
	.space 0x20

gIntroScene7WailmerLaunch_Gfx:: @ 0x08112840
	.incbin "graphics/intro/scene_7_wailmer_launch.4bpp"
	.space 0x20

gUnknown_08115860:: @ 0x08115860
	.incbin "baserom.gba", 0x115860, 0x200

gUnknown_08115A60:: @ 0x08115A60
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

gUnknown_08137928:: @ 0x08137928
	.incbin "baserom.gba", 0x137928, 0x1C

gUnknown_08137944:: @ 0x08137944
	.incbin "baserom.gba", 0x137944, 0x24

gUnknown_08137968:: @ 0x08137968
	.2byte 0,2,3,4,5,6,7,10,10,10,7,6,5,4,3,2,1,0
	@.incbin "baserom.gba", 0x137968, 0x24

gUnknown_0813798C:: @ 0x0813798C
	.incbin "baserom.gba", 0x13798C, 0xC

gUnknown_08137998:: @ 0x08137998
	.incbin "baserom.gba", 0x137998, 0x20

gUnknown_081379B8:: @ 0x081379B8
	.incbin "baserom.gba", 0x1379B8, 0x20

gUnknown_081379D8:: @ 0x081379D8
	.incbin "baserom.gba", 0x1379D8, 0xE0

gUnknown_08137AB8:: @ 0x08137AB8
	.incbin "baserom.gba", 0x137AB8, 0x84

gUnknown_08137B3C:: @ 0x08137B3C
	.incbin "baserom.gba", 0x137B3C, 0x20

gUnknown_08137B5C:: @ 0x08137B5C
	.incbin "baserom.gba", 0x137B5C, 0x160

gUnknown_08137CBC:: @ 0x08137CBC
	.incbin "baserom.gba", 0x137CBC, 0x1A

gUnknown_08137CD6:: @ 0x08137CD6
	.incbin "baserom.gba", 0x137CD6, 0xC

gUnknown_08137CE2:: @ 0x08137CE2
	.incbin "baserom.gba", 0x137CE2, 0x14

gUnknown_08137CF6:: @ 0x08137CF6
	.incbin "baserom.gba", 0x137CF6, 0x10

gUnknown_08137D06:: @ 0x08137D06
	.incbin "baserom.gba", 0x137D06, 0x3A

gUnknown_08137D40:: @ 0x08137D40
	.incbin "baserom.gba", 0x137D40, 0x8

gUnknown_08137D48:: @ 0x08137D48
	.incbin "baserom.gba", 0x137D48, 0x18

gUnknown_08137D60:: @ 0x08137D60
	.incbin "baserom.gba", 0x137D60, 0x18

gUnknown_08137D78:: @ 0x08137D78
	.incbin "baserom.gba", 0x137D78, 0x2C

gUnknown_08137DA4:: @ 0x08137DA4
	.incbin "baserom.gba", 0x137DA4, 0x1A

gDebugTextStrings:: @ 0x08137DBE
	.ascii " BALL-MV:"
	.byte 0,0,0,0,0
	.ascii " BALL-SPD:"
	.byte 0,0,0,0
	.ascii "  DEBUG1:"
	.byte 0,0,0,0,0

gUnknown_08137DE8:: @ 0x08137DE8
	.ascii "(000 000)"
	.byte 0,0,0
	.ascii "(000)    "
	.byte 0,0,0

gUnknown_08137E00:: @ 0x08137E00
	.incbin "baserom.gba", 0x137E00, 0x4

gPinballGameStateFuncs:: @ 0x08137E04
	.4byte PinballGame_State0_49ED4 @ called once upon loading the field
	.4byte PinballGame_State1_4AAD8 @ called once every frame while playing
	.4byte PinballGame_State2_4ABC8 @ called once on game over (losing all balls)
	.4byte PinballGame_State3_4B20C @ called once after game over?

gUnknown_08137E14:: @ 0x08137E14
	.incbin "baserom.gba", 0x137E14, 0x100

gUnknown_08137F14:: @ 0x08137F14
	.incbin "baserom.gba", 0x137F14, 0x100

gUnknown_08138014:: @ 0x08138014
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

gUnknown_081428D4:: @ 0x081428D4
	.incbin "baserom.gba", 0x1428D4, 0x1C20

.include "data/graphics/mon_hatch_sprites_pals.inc"

gUnknown_081450F4:: @ 0x081450F4
	.incbin "baserom.gba", 0x1450F4, 0x3840

gUnknown_08148934:: @ 0x08148934
	.incbin "baserom.gba", 0x148934, 0x3840

gUnknown_0814C174:: @ 0x0814C174
	.incbin "baserom.gba", 0x14C174, 0x3840

gUnknown_0814F9B4:: @ 0x0814F9B4
	.incbin "baserom.gba", 0x14F9B4, 0x3840

gUnknown_081531F4:: @ 0x081531F4
	.incbin "baserom.gba", 0x1531F4, 0x1424

gUnknown_08154618:: @ 0x08154618
	.incbin "baserom.gba", 0x154618, 0x1424

gUnknown_08155A3C:: @ 0x08155A3C
	.incbin "baserom.gba", 0x155A3C, 0x1424

gUnknown_08156E60:: @ 0x08156E60
	.incbin "baserom.gba", 0x156E60, 0x1424

gUnknown_08158284:: @ 0x08158284
	.incbin "baserom.gba", 0x158284, 0x2420

gUnknown_0815A6A4:: @ 0x0815A6A4
	.incbin "baserom.gba", 0x15A6A4, 0x200

gEvoExAppear_Gfx:: @ 0x0815A8A4
	.incbin "graphics/board_pickups/evo_item_ex.4bpp";

gUnknown_0815C4C4:: @ 0x0815C4C4
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

gUnknown_0816C3E4:: @ 0x0816C3E4
	.incbin "baserom.gba", 0x16C3E4, 0x42800
	.include "data/graphics/mon_catch_sprites_pals.inc"
@	.incbin "baserom.gba", 0x1AEBE4, 0xA80
	.incbin "baserom.gba", 0x1B0C64, 0x180

gUnknown_081B0DE4:: @ 0x081B0DE4
	.incbin "baserom.gba", 0x1B0DE4, 0x200

gUnknown_081B0FE4:: @ 0x081B0FE4
	.incbin "baserom.gba", 0x1B0FE4, 0x26C0

gUnknown_081B36A4:: @ 0x081B36A4
	.incbin "baserom.gba", 0x1B36A4, 0xEE0

gUnknown_081B4584:: @ 0x081B4584
	.incbin "baserom.gba", 0x1B4584, 0x20

gUnknown_081B45A4:: @ 0x081B45A4
	.incbin "baserom.gba", 0x1B45A4, 0x1E0

gUnknown_081B4784:: @ 0x081B4784
	.incbin "baserom.gba", 0x1B4784, 0x4000

gUnknown_081B8784:: @ 0x081B8784
	.incbin "baserom.gba", 0x1B8784, 0x200

gUnknown_081B8984:: @ 0x081B8984
	.incbin "baserom.gba", 0x1B8984, 0x4000

gUnknown_081BC984:: @ 0x081BC984
	.incbin "baserom.gba", 0x1BC984, 0x120

gUnknown_081BCAA4:: @ 0x081BCAA4
	.incbin "baserom.gba", 0x1BCAA4, 0x1820

gUnknown_081BE2C4:: @ 0x081BE2C4
	.incbin "baserom.gba", 0x1BE2C4, 0x200

gUnknown_081BE4C4:: @ 0x081BE4C4
	.incbin "baserom.gba", 0x1BE4C4, 0x1820

gUnknown_081BFCE4:: @ 0x081BFCE4
	.incbin "baserom.gba", 0x1BFCE4, 0x200

gUnknown_081BFEE4:: @ 0x081BFEE4
	.incbin "baserom.gba", 0x1BFEE4, 0x180

gUnknown_081C0064:: @ 0x081C0064
	.incbin "baserom.gba", 0x1C0064, 0x80

gUnknown_081C00E4:: @ 0x081C00E4
	.incbin "baserom.gba", 0x1C00E4, 0x200

gUnknown_081C02E4:: @ 0x081C02E4
	.incbin "baserom.gba", 0x1C02E4, 0x600

gUnknown_081C08E4:: @ 0x081C08E4
	.incbin "baserom.gba", 0x1C08E4, 0x6DB40

gUnknown_0822E424:: @ 0x0822E424
	.incbin "baserom.gba", 0x22E424, 0x1DDC0

gUnknown_0824C1E4:: @ 0x0824C1E4
	.incbin "baserom.gba", 0x24C1E4, 0x1B7C

gUnknown_0824DD60:: @ 0x0824DD60
	.incbin "baserom.gba", 0x24DD60, 0x2BD4

gUnknown_08250934:: @ 0x08250934
	.incbin "baserom.gba", 0x250934, 0x21DC

gUnknown_08252B10:: @ 0x08252B10
	.incbin "baserom.gba", 0x252B10, 0x2000

gUnknown_08254B10:: @ 0x08254B10
	.incbin "baserom.gba", 0x254B10, 0x2880

gUnknown_08257390:: @ 0x08257390
	.incbin "baserom.gba", 0x257390, 0x2880

gUnknown_08259C10:: @ 0x08259C10
	.incbin "baserom.gba", 0x259C10, 0xC000

gUnknown_08265C10:: @ 0x08265C10
	.incbin "baserom.gba", 0x265C10, 0x8000

gUnknown_0826DC10:: @ 0x0826DC10
	.incbin "baserom.gba", 0x26DC10, 0x1000

gUnknown_0826EC10:: @ 0x0826EC10
	.incbin "baserom.gba", 0x26EC10, 0x200

gUnknown_0826EE10:: @ 0x0826EE10
	.incbin "baserom.gba", 0x26EE10, 0x3F8C0

gUnknown_082AE6D0:: @ 0x082AE6D0
	.incbin "baserom.gba", 0x2AE6D0, 0x24E00

gUnknown_082D34D0:: @ 0x082D34D0
	.incbin "baserom.gba", 0x2D34D0, 0x1D6C

gUnknown_082D523C:: @ 0x082D523C
	.incbin "baserom.gba", 0x2D523C, 0x375C

gUnknown_082D8998:: @ 0x082D8998
	.incbin "baserom.gba", 0x2D8998, 0xC548

gUnknown_082E4EE0:: @ 0x082E4EE0
	.incbin "baserom.gba", 0x2E4EE0, 0x8000

gUnknown_082ECEE0:: @ 0x082ECEE0
	.incbin "baserom.gba", 0x2ECEE0, 0x1000

gUnknown_082EDEE0:: @ 0x082EDEE0
	.incbin "baserom.gba", 0x2EDEE0, 0x200

gUnknown_082EE0E0:: @ 0x082EE0E0
	.incbin "baserom.gba", 0x2EE0E0, 0x3E0

gUnknown_082EE4C0:: @ 0x082EE4C0
	.incbin "baserom.gba", 0x2EE4C0, 0x13240

gUnknown_08301700:: @ 0x08301700
	.incbin "baserom.gba", 0x301700, 0x800

gUnknown_08301F00:: @ 0x08301F00
	.incbin "baserom.gba", 0x301F00, 0x800

gUnknown_08302700:: @ 0x08302700
	.incbin "baserom.gba", 0x302700, 0x1228

gUnknown_08303928:: @ 0x08303928
	.incbin "baserom.gba", 0x303928, 0x38AC

gUnknown_083071D4:: @ 0x083071D4
	.incbin "baserom.gba", 0x3071D4, 0x5A00

gUnknown_0830CBD4:: @ 0x0830CBD4
	.incbin "baserom.gba", 0x30CBD4, 0x200

gUnknown_0830CDD4:: @ 0x0830CDD4
	.incbin "baserom.gba", 0x30CDD4, 0x1ABC0

gUnknown_08327994:: @ 0x08327994
	.incbin "baserom.gba", 0x327994, 0x2000

gUnknown_08329994:: @ 0x08329994
	.incbin "baserom.gba", 0x329994, 0x800

gUnknown_0832A194:: @ 0x0832A194
	.incbin "baserom.gba", 0x32A194, 0x3470

gUnknown_0832D604:: @ 0x0832D604
	.incbin "baserom.gba", 0x32D604, 0x2C00

gUnknown_08330204:: @ 0x08330204
	.incbin "baserom.gba", 0x330204, 0x2C00

gUnknown_08332E04:: @ 0x08332E04
	.incbin "baserom.gba", 0x332E04, 0x200

gUnknown_08333004:: @ 0x08333004
	.incbin "baserom.gba", 0x333004, 0xA840

gUnknown_0833D844:: @ 0x0833D844
	.incbin "baserom.gba", 0x33D844, 0x800

gUnknown_0833E044:: @ 0x0833E044
	.incbin "baserom.gba", 0x33E044, 0x1F14

gUnknown_0833FF58:: @ 0x0833FF58
	.incbin "baserom.gba", 0x33FF58, 0xC00

gUnknown_08340B58:: @ 0x08340B58
	.incbin "baserom.gba", 0x340B58, 0x8E80

gUnknown_083499D8:: @ 0x083499D8
	.incbin "baserom.gba", 0x3499D8, 0x4200

gUnknown_0834DBD8:: @ 0x0834DBD8
	.incbin "baserom.gba", 0x34DBD8, 0x4E00

gUnknown_083529D8:: @ 0x083529D8
	.incbin "baserom.gba", 0x3529D8, 0x200

gUnknown_08352BD8:: @ 0x08352BD8
	.incbin "baserom.gba", 0x352BD8, 0x200

gUnknown_08352DD8:: @ 0x08352DD8
	.incbin "baserom.gba", 0x352DD8, 0x800

gUnknown_083535D8:: @ 0x083535D8
	.incbin "baserom.gba", 0x3535D8, 0x800

gUnknown_08353DD8:: @ 0x08353DD8
	.incbin "baserom.gba", 0x353DD8, 0x3BF0

gUnknown_083579C8:: @ 0x083579C8
	.incbin "baserom.gba", 0x3579C8, 0x7000

gUnknown_0835E9C8:: @ 0x0835E9C8
	.incbin "baserom.gba", 0x35E9C8, 0x5500

gUnknown_08363EC8:: @ 0x08363EC8
	.incbin "baserom.gba", 0x363EC8, 0x200

gUnknown_083640C8:: @ 0x083640C8
	.incbin "baserom.gba", 0x3640C8, 0xA740

gUnknown_0836E808:: @ 0x0836E808
	.incbin "baserom.gba", 0x36E808, 0x1000

gUnknown_0836F808:: @ 0x0836F808
	.incbin "baserom.gba", 0x36F808, 0x1000

gUnknown_08370808:: @ 0x08370808
	.incbin "baserom.gba", 0x370808, 0x1AE0

gUnknown_083722E8:: @ 0x083722E8
	.incbin "baserom.gba", 0x3722E8, 0x8000

gUnknown_0837A2E8:: @ 0x0837A2E8
	.incbin "baserom.gba", 0x37A2E8, 0x200

gUnknown_0837A4E8:: @ 0x0837A4E8
	.incbin "baserom.gba", 0x37A4E8, 0x13B40

gUnknown_0838E028:: @ 0x0838E028
	.incbin "baserom.gba", 0x38E028, 0x800

gUnknown_0838E828:: @ 0x0838E828
	.incbin "baserom.gba", 0x38E828, 0x3224

gUnknown_08391A4C:: @ 0x08391A4C
	.incbin "baserom.gba", 0x391A4C, 0x2000

gUnknown_08393A4C:: @ 0x08393A4C
	.incbin "baserom.gba", 0x393A4C, 0x2000

gUnknown_08395A4C:: @ 0x08395A4C
	.incbin "baserom.gba", 0x395A4C, 0x2420

gUnknown_08397E6C:: @ 0x08397E6C
	.incbin "baserom.gba", 0x397E6C, 0x2420

gUnknown_0839A28C:: @ 0x0839A28C
	.incbin "baserom.gba", 0x39A28C, 0x900

.include "data/graphics/mon_portraits_pals.inc"

gUnknown_0839C78C:: @ 0x0839C78C
	.incbin "baserom.gba", 0x39C78C, 0x1420

gUnknown_0839DBAC:: @ 0x0839DBAC
	.incbin "baserom.gba", 0x39DBAC, 0x200

gUnknown_0839DDAC:: @ 0x0839DDAC
	.incbin "baserom.gba", 0x39DDAC, 0x2820

gUnknown_083A05CC:: @ 0x083A05CC
	.incbin "baserom.gba", 0x3A05CC, 0x200

gUnknown_083A07CC:: @ 0x083A07CC
	.incbin "baserom.gba", 0x3A07CC, 0x2020

gUnknown_083A27EC:: @ 0x083A27EC
	.incbin "baserom.gba", 0x3A27EC, 0x200

gUnknown_083A29EC:: @ 0x083A29EC
	.incbin "baserom.gba", 0x3A29EC, 0x820

gUnknown_083A320C:: @ 0x083A320C
	.incbin "baserom.gba", 0x3A320C, 0x200

gUnknown_083A340C:: @ 0x083A340C
	.incbin "baserom.gba", 0x3A340C, 0x2020

gUnknown_083A542C:: @ 0x083A542C
	.incbin "baserom.gba", 0x3A542C, 0x200

gUnknown_083A562C:: @ 0x083A562C
	.incbin "baserom.gba", 0x3A562C, 0x1820

gUnknown_083A6E4C:: @ 0x083A6E4C
	.incbin "baserom.gba", 0x3A6E4C, 0x200

gUnknown_083A704C:: @ 0x083A704C
	.incbin "baserom.gba", 0x3A704C, 0x1020

gUnknown_083A806C:: @ 0x083A806C
	.incbin "baserom.gba", 0x3A806C, 0x20

gUnknown_083A808C:: @ 0x083A808C
	.incbin "baserom.gba", 0x3A808C, 0x1E0

gUnknown_083A826C:: @ 0x083A826C
	.incbin "baserom.gba", 0x3A826C, 0x820

gUnknown_083A8A8C:: @ 0x083A8A8C
	.incbin "baserom.gba", 0x3A8A8C, 0x20

gUnknown_083A8AAC:: @ 0x083A8AAC
	.incbin "baserom.gba", 0x3A8AAC, 0x20

gUnknown_083A8ACC:: @ 0x083A8ACC
	.incbin "baserom.gba", 0x3A8ACC, 0x420

gUnknown_083A8EEC:: @ 0x083A8EEC
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

gUnknown_083BB16C:: @ 0x083BB16C
	.incbin "graphics/stage/main/pokeball_regular.4bpp"
	.incbin "graphics/stage/main/pokeball_great.4bpp"
	.incbin "graphics/stage/main/pokeball_ultra.4bpp"
	.incbin "graphics/stage/main/pokeball_master.4bpp"

gUnknown_083BD36C:: @ 0x083BD36C
	.incbin "baserom.gba", 0x3BD36C, 0xC00

gUnknown_083BDF6C:: @ 0x083BDF6C
	.incbin "baserom.gba", 0x3BDF6C, 0x1200

gUnknown_083BF16C:: @ 0x083BF16C
	.incbin "baserom.gba", 0x3BF16C, 0x1600

gUnknown_083C076C:: @ 0x083C076C
	.incbin "baserom.gba", 0x3C076C, 0xC40

gUnknown_083C13AC:: @ 0x083C13AC
	.incbin "baserom.gba", 0x3C13AC, 0x6C0

gUnknown_083C1A6C:: @ 0x083C1A6C
	.incbin "baserom.gba", 0x3C1A6C, 0x21C0

gUnknown_083C3C2C:: @ 0x083C3C2C
	.incbin "baserom.gba", 0x3C3C2C, 0x1800

gUnknown_083C542C:: @ 0x083C542C
	.incbin "baserom.gba", 0x3C542C, 0x200

gUnknown_083C562C:: @ 0x083C562C
	.incbin "baserom.gba", 0x3C562C, 0x400

gUnknown_083C5A2C:: @ 0x083C5A2C
	.incbin "baserom.gba", 0x3C5A2C, 0x2640

gUnknown_083C806C:: @ 0x083C806C
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

gUnknown_083FE44C:: @ 0x083FE44C
	.incbin "baserom.gba", 0x3FE44C, 0xC00

gUnknown_083FF04C:: @ 0x083FF04C
	.incbin "baserom.gba", 0x3FF04C, 0xD00

gUnknown_083FFD4C:: @ 0x083FFD4C
	.incbin "baserom.gba", 0x3FFD4C, 0x40

gSapphireBoardWailmer_Gfx:: @ 0x083FFD8C
	.incbin "graphics/stage/sapphire/wailmer.4bpp";

	.include "data/graphics/mon_catch_sprites.inc"

gRubyStageGulpin_Gfx:: @ 0x08447A8C
	.incbin "graphics/stage/ruby/gulpin.4bpp"

gMainStageBonusTrap_Gfx:: @ 0x0844838C
	.incbin "graphics/stage/main/bonus_trap.4bpp"

gUnknown_0844928C:: @ 0x0844928C
	.incbin "baserom.gba", 0x44928C, 0xB00

gRubyStageCyndaquil_Gfx:: @ 0x08449D8C
	.incbin "graphics/stage/ruby/cyndaquil.4bpp"

gUnknown_0844AA0C:: @ 0x0844AA0C
	.incbin "graphics/stage/main/gunk_0844AA0C.4bpp"

gSapphireStageBasket_Gfx:: @ 0x0844F20C
	.incbin "graphics/stage/sapphire/seedot_basket.4bpp"

gKecleonStageKecleon_Gfx:: @ 0x0844F98C
	.incbin "graphics/stage/kecleon/kecleon.4bpp"

gKecleonStageKecleonFx_Gfx:: @ 0x0845588C
	.incbin "graphics/stage/kecleon/kecleon_fx.4bpp"

gUnknown_08455E8C:: @ 0x08455E8C
	.incbin "graphics/stage/misc/gunk_08455E8C.4bpp"

gUnknown_0845648C:: @ 0x0845648C
	.incbin "graphics/stage/misc/gunk_0845648C.4bpp"

gUnknown_0845690C:: @ 0x0845690C
	.incbin "graphics/stage/misc/gunk_0845690C.4bpp"

gRubyStageNuzleaf_Gfx:: @ 0x0845710C
	.incbin "graphics/stage/ruby/nuzleaf.4bpp"

gUnknown_0845A08C:: @ 0x0845A08C
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

gUnknown_084779EC:: @ 0x084779EC
	.incbin "baserom.gba", 0x4779EC, 0x2A20

gUnknown_0847A40C:: @ 0x0847A40C
	.incbin "baserom.gba", 0x47A40C, 0x2D00

gUnknown_0847D10C:: @ 0x0847D10C
	.incbin "baserom.gba", 0x47D10C, 0xE00

gUnknown_0847DF0C:: @ 0x0847DF0C
	.incbin "baserom.gba", 0x47DF0C, 0x1E00

gUnknown_0847FD0C:: @ 0x0847FD0C
	.incbin "baserom.gba", 0x47FD0C, 0x200

gUnknown_0847FF0C:: @ 0x0847FF0C
	.incbin "baserom.gba", 0x47FF0C, 0xF00

gUnknown_08480E0C:: @ 0x08480E0C
	.incbin "baserom.gba", 0x480E0C, 0x280

gUnknown_0848108C:: @ 0x0848108C
	.incbin "baserom.gba", 0x48108C, 0x2D00

gUnknown_08483D8C:: @ 0x08483D8C
	.incbin "baserom.gba", 0x483D8C, 0x4C80

gUnknown_08488A0C:: @ 0x08488A0C
	.incbin "baserom.gba", 0x488A0C, 0x4C80

gUnknown_0848D68C:: @ 0x0848D68C
	.incbin "baserom.gba", 0x48D68C, 0x2700

gUnknown_0848FD8C:: @ 0x0848FD8C
	.incbin "baserom.gba", 0x48FD8C, 0xCC0

gUnknown_08490A4C:: @ 0x08490A4C
	.incbin "baserom.gba", 0x490A4C, 0x4400

gDusclopsBoardDusclopsAppearFx_Gfx:: @ 0x08494E4C
	.incbin "graphics/stage/dusclops/dusclops_appear_fx.4bpp";

gUnknown_0849664C:: @ 0x0849664C
	.incbin "baserom.gba", 0x49664C, 0x5280

gUnknown_0849B8CC:: @ 0x0849B8CC
	.incbin "baserom.gba", 0x49B8CC, 0x3900

gUnknown_0849F1CC:: @ 0x0849F1CC
	.incbin "baserom.gba", 0x49F1CC, 0x2020

gUnknown_084A11EC:: @ 0x084A11EC
	.incbin "baserom.gba", 0x4A11EC, 0x5D00

gUnknown_084A6EEC:: @ 0x084A6EEC
	.incbin "baserom.gba", 0x4A6EEC, 0x1680

gUnknown_084A856C:: @ 0x084A856C
	.incbin "baserom.gba", 0x4A856C, 0x1C20

gUnknown_084AA18C:: @ 0x084AA18C
	.incbin "baserom.gba", 0x4AA18C, 0x860

gUnknown_084AA9EC:: @ 0x084AA9EC
	.incbin "baserom.gba", 0x4AA9EC, 0x5000

gUnknown_084AF9EC:: @ 0x084AF9EC
	.incbin "baserom.gba", 0x4AF9EC, 0x600

gUnknown_084AFFEC:: @ 0x084AFFEC
	.incbin "baserom.gba", 0x4AFFEC, 0x480

gUnknown_084B046C:: @ 0x084B046C
	.incbin "baserom.gba", 0x4B046C, 0x4380

gUnknown_084B47EC:: @ 0x084B47EC
	.incbin "baserom.gba", 0x4B47EC, 0x3000

gUnknown_084B77EC:: @ 0x084B77EC
	.incbin "baserom.gba", 0x4B77EC, 0x800

gWhiscash_Gfx:: @ 0x084B7FEC
	.incbin "graphics/stage/ruby/whiscash.4bpp"

gPelliper_Gfx:: @ 0x084BB16C
	.incbin "graphics/stage/sapphire/pelliper.4bpp"
	.incbin "graphics/stage/sapphire/charger.4bpp"

gUnknown_084C00EC:: @ 0x084C00EC
	.incbin "baserom.gba", 0x4C00EC, 0x700

gUnknown_084C07EC:: @ 0x084C07EC
	.incbin "baserom.gba", 0x4C07EC, 0x480

gUnknown_084C0C6C:: @ 0x084C0C6C
	.incbin "baserom.gba", 0x4C0C6C, 0x900

gUnknown_084C156C:: @ 0x084C156C
	.incbin "baserom.gba", 0x4C156C, 0x900

gUnknown_084C1E6C:: @ 0x084C1E6C
	.incbin "baserom.gba", 0x4C1E6C, 0x2D00

gUnknown_084C4B6C:: @ 0x084C4B6C
	.incbin "baserom.gba", 0x4C4B6C, 0xE00

.include "data/graphics/mon_portraits.inc"

.incbin "baserom.gba", 0x4ECF6C, 0x160 @ 0x4ED0CC - 0x4ECF6C

gRubyBoardShopDoor_Gfx:: @ 0x084ED0CC
	.incbin "graphics/stage/ruby/shop_door.4bpp";

gUnknown_084ED6CC:: @ 0x084ED6CC
	.incbin "graphics/stage/gunk_084ED6CC.4bpp";

gDusclopsBoardDusclops_Gfx:: @ 0x084EDACC
	.incbin "graphics/stage/dusclops/dusclops.4bpp";

gRubyBoardSharpedo_Gfx:: @ 0x084F5ACC
	.incbin "graphics/stage/ruby/sharpedo.4bpp";

gUnknown_084F61EC:: @ 0x084F61EC
	.incbin "graphics/stage/main/gunk_084F61EC.4bpp";

gRubyBoardShop_Gfx:: @ 0x084F6B0C
	.incbin "graphics/stage/ruby/shop.4bpp";

gUnknown_084FA20C:: @ 0x084FA20C
	.incbin "graphics/stage/misc/gunk_084FA20C.4bpp";

gMainBoardPikaSpinner_Gfx:: @ 0x084FA48C
	.incbin "graphics/stage/main/pika_spinner.4bpp";

gRubyBoardHatchCave_Gfx:: @ 0x084FB68C
	.incbin "graphics/stage/ruby/hatch_cave.4bpp";

gUnknown_084FD18C:: @ 0x084FD18C
	.incbin "graphics/stage/main/egg.4bpp";

gSapphireBoardSeedot_Gfx:: @ 0x084FDF8C
	.incbin "graphics/stage/sapphire/seedot.4bpp";

gSapphireBoardShopShockWall_Gfx:: @ 0x084FEA0C
	.incbin "graphics/stage/sapphire/shop_shock_wall.4bpp";

gRubyBoardRampPrize_Gfx:: @ 0x084FEF0C
	.incbin "graphics/stage/ruby/ramp_prize.4bpp";

gDusclopsBoardDusclopsBallGrabSwirl_Gfx:: @ 0x084FF30C
	.incbin "graphics/stage/dusclops/dusclops_ball_grab.4bpp";

gUnknown_084FF90C:: @ 0x084FF90C
	.incbin "baserom.gba", 0x4FF90C, 0x1700

gMainBoardBallSave_Gfx:: @ 0x0850100C
	.incbin "graphics/stage/main/ball_save.4bpp";

gMainBoardBallSaveLatios_Gfx:: @ 0x085028CC
	.incbin "graphics/stage/main/latios.4bpp";

gMainBoardBallSaveLatiosArm_Gfx:: @ 0x085038CC
	.incbin "graphics/stage/main/latios_arm.4bpp";

gMainBoardEndOfBall_Gfx:: @ 0x0850398C
	.incbin "graphics/stage/main/end_of_ball.4bpp";

gUnknown_0850558C:: @ 0x0850558C
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

gUnknown_08514F4C:: @ 0x08514F4C
	.incbin "baserom.gba", 0x514F4C, 0x20

gUnknown_08514F6C:: @ 0x08514F6C
	.incbin "baserom.gba", 0x514F6C, 0x1E0

gUnknown_0851514C:: @ 0x0851514C
	.incbin "baserom.gba", 0x51514C, 0x4620

gUnknown_0851976C:: @ 0x0851976C
	.incbin "baserom.gba", 0x51976C, 0x4420

gUnknown_0851DB8C:: @ 0x0851DB8C
	.incbin "baserom.gba", 0x51DB8C, 0x4420

gUnknown_08521FAC:: @ 0x08521FAC
	.incbin "baserom.gba", 0x521FAC, 0x20

gUnknown_08521FCC:: @ 0x08521FCC
	.incbin "baserom.gba", 0x521FCC, 0x3E0

gUnknown_085223AC:: @ 0x085223AC
	.incbin "baserom.gba", 0x5223AC, 0x4A20

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
    .2byte SE_SCORE_ENTRY_A_B_MOVE, SE_SCORE_ENTRY_LETTER_CHANGE, SE_UNKNOWN_0x6D, SE_FLIPPER_PRESSED, SE_SLINGSHOT_HIT
    .2byte SE_POKEMON_CATCH_HIT, SE_UNKNOWN_0x75, SE_TRIGGER_BUTTON_HIT, SE_WALL_HIT, SE_TILT_TRIGGERED
    .2byte SE_UNKNOWN_0x79, SE_UNKNOWN_0x7A, SE_UNKNOWN_0x7B, SE_UNKNOWN_0x7C, SE_UNKNOWN_0x7E
    .2byte SE_UNKNOWN_0x80, SE_UNKNOWN_0x81, SE_EVO_SELECTION_MOVE, SE_EVO_SELECTION_CONFIRM, SE_UNKNOWN_0x84
    .2byte SE_UNKNOWN_0x85, SE_UNKNOWN_0x86, SE_UNKNOWN_0x87, SE_FAILURE, SE_UNKNOWN_0x8B
    .2byte SE_UNKNOWN_0x8C, SE_UNKNOWN_0x8D, SE_UNKNOWN_0x8E, SE_UNKNOWN_0x8F, SE_UNKNOWN_0x91
    .2byte SE_UNKNOWN_0x92, SE_UNKNOWN_0x93, SE_UNKNOWN_0x94, SE_UNKNOWN_0x95, SE_UNKNOWN_0x96
    .2byte SE_UNKNOWN_0x97, SE_UNKNOWN_0x98, SE_UNKNOWN_0x99, SE_UNKNOWN_0x9A, SE_UNKNOWN_0x9B
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
    .2byte SE_UNKNOWN_0xB1, SE_UNKNOWN_0xB2, SE_UNKNOWN_0xB3, SE_UNKNOWN_0x142


gDefaultButtonConfigs:: @ 0x08527ED6
	@4 sets of 10
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x09, 0x08;
	.byte 0x05, 0x0A, 0x00, 0x0A, 0x09, 0x0A, 0x08, 0x0A, 0x01, 0x0A;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x00, 0x0A, 0x05, 0x00;
	.byte 0x09, 0x0A, 0x08, 0x0A, 0x05, 0x0A, 0x04, 0x0A, 0x06, 0x0A;

gUnknown_08527EFE:: @ 0x08527EFE
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
