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
