    .section .rodata
@ field select palettes 0xA8840

.incbin "baserom.gba", 0x55A68, 0x7A0C0 - 0x55A68

gIntroCopyright_Gfx:: @ 0x0807A0C0
    .incbin "graphics/intro/copyright.4bpp"

.incbin "baserom.gba", 0x7A8C0, 0x20

gIntroCopyright_Pal:: @ 0x0807A8E0
    .incbin "graphics/intro/copyright.gbapal"

.incbin "baserom.gba", 0x7AAE0, 0xA2C00 - 0x7AAE0

.include "data/graphics/field_select.inc"

.incbin "baserom.gba", 0xACC60, 0xB3AA0 - 0xACC60

gIntroScene1Sprites_Pals:: @ 0x080B3AA0
	.incbin "graphics/intro/scene_1_sprites.gbapal"

.incbin "baserom.gba", 0xB3CA0, 0xC3CE0 - 0xB3CA0

gIntroScene1Sprites_Gfx:: @ 0x080C3CE0
	.incbin "graphics/intro/scene_1_sprites.4bpp"

.incbin "baserom.gba", 0xCBCE0, 0x120CC0 - 0xCBCE0

.include "data/graphics/titlescreen.inc"

.incbin "baserom.gba", 0x137900, 0x1444F4 - 0x137900

.include "data/graphics/mon_hatch_sprites_pals.inc"

.incbin "baserom.gba", 0x1450F4, 0x39AB8C - 0x1450F4

.include "data/graphics/mon_portraits_pals.inc"

.incbin "baserom.gba", 0x39C78C, 0x3C8B6C - 0x39C78C

.include "data/graphics/mon_hatch_sprites.inc"

.incbin "baserom.gba", 0x3EB84C, 0x4C596C - 0x3EB84C

.include "data/graphics/mon_portraits.inc"

.incbin "baserom.gba", 0x4ECF6C, 0x6A4AD8 - 0x4ECF6C

gMainFuncs:: @ 0x086A4AD8
	.4byte IntroMain
	.4byte TitlescreenMain
	.4byte PinballGameMain
	.4byte sub_19028_Main
	.4byte OptionsMain
	.4byte PokedexMain
	.4byte sub_9BC_Main
	.4byte EReaderMain
	.4byte HighScoresMain
	.4byte sub_CE68_Main
	.4byte FieldSelectMain
	.4byte sub_25A4_Main

.incbin "baserom.gba", 0x6A4B08, 0x6B159C - 0x6A4B08

gMonHatchSpriteGroupPals:: @ 0x086B159C
	.4byte gMonHatchSpriteGroup0_Pals
	.4byte gMonHatchSpriteGroup1_Pals
	.4byte gMonHatchSpriteGroup2_Pals
	.4byte gMonHatchSpriteGroup3_Pals
	.4byte gMonHatchSpriteGroup4_Pals
	.4byte gMonHatchSpriteGroup5_Pals

.incbin "baserom.gba", 0x6B15B4, 0x6BB6A4 - 0x6B15B4

gMonPortraitGroupPals:: @ 0x086BB6A4
	.4byte gMonPortraitsGroup0_Pals
	.4byte gMonPortraitsGroup1_Pals
	.4byte gMonPortraitsGroup2_Pals
	.4byte gMonPortraitsGroup3_Pals
	.4byte gMonPortraitsGroup4_Pals
	.4byte gMonPortraitsGroup5_Pals
	.4byte gMonPortraitsGroup6_Pals
	.4byte gMonPortraitsGroup7_Pals
	.4byte gMonPortraitsGroup8_Pals
	.4byte gMonPortraitsGroup9_Pals
	.4byte gMonPortraitsGroup10_Pals
	.4byte gMonPortraitsGroup11_Pals
	.4byte gMonPortraitsGroup12_Pals
	.4byte gMonPortraitsGroup13_Pals

gMonHatchSpriteGroupGfx:: @ 0x086BB6DC
	.4byte gMonHatchSpriteGroup0_Gfx
	.4byte gMonHatchSpriteGroup1_Gfx
	.4byte gMonHatchSpriteGroup2_Gfx
	.4byte gMonHatchSpriteGroup3_Gfx
	.4byte gMonHatchSpriteGroup4_Gfx
	.4byte gMonHatchSpriteGroup5_Gfx

.incbin "baserom.gba", 0x6BB6F4, 0x6BB738 - 0x6BB6F4

gMonPortraitGroupGfx:: @ 0x086BB738
	.4byte gMonPortraitsGroup0_Gfx
	.4byte gMonPortraitsGroup1_Gfx
	.4byte gMonPortraitsGroup2_Gfx
	.4byte gMonPortraitsGroup3_Gfx
	.4byte gMonPortraitsGroup4_Gfx
	.4byte gMonPortraitsGroup5_Gfx
	.4byte gMonPortraitsGroup6_Gfx
	.4byte gMonPortraitsGroup7_Gfx
	.4byte gMonPortraitsGroup8_Gfx
	.4byte gMonPortraitsGroup9_Gfx
	.4byte gMonPortraitsGroup10_Gfx
	.4byte gMonPortraitsGroup11_Gfx
	.4byte gMonPortraitsGroup12_Gfx
	.4byte gMonPortraitsGroup13_Gfx

.incbin "baserom.gba", 0x6BB770, 0x6BBFD0 - 0x6BB770

@ rom end 0x6BBFD0
