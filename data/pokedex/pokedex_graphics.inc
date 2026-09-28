gPokedexBg1_Tilemap:: @ 0x08081F20
	.incbin "graphics/pokedex/bg1_tilemap.bin"

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
gPokedexInfoWindowTilemap:: @ 0x08086B40
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
