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
