
.include "data/options_screen/options_sound_lists.inc"

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

.include "data/pokemon/species_rs_to_cry_id.inc"

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
