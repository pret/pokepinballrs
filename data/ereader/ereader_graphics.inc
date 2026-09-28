gEReaderText_Tilemap:: @ 0x0807DD00
	.incbin "graphics/ereader/ereader_text_tilemap.bin"

gEReaderOverlay_Tilemap:: @ 0x0807FD00
	.incbin "graphics/ereader/ereader_overlay_tilemap.bin"

gEReaderBackground_Gfx:: @ 0x08080500
	.incbin "graphics/ereader/background.4bpp"
	.space 0x20

gEReaderBackground_Pals:: @ 0x08081D20
	.incbin "graphics/ereader/background.gbapal"
