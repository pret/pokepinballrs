@ note: base collision data for kyogre/groudon boards are shared.
@ that is in this file at 0x08333804, 0x08335804, 0x0833AD84
@ other data is kyogre specific

gKyogreBoardPalette:: @ 0x08332E04
	.incbin "graphics/stage/kyogre/kyogre_board.gbapal"

gKyogreWaterBackgroundTilemap:: @ 0x08333004
	.incbin "graphics/stage/kyogre/kyogre_board_bg0_tilemap.bin"

gKyrGrouBoardCollisionTileDataAllLayers:: @ 0x08333804
	.incbin "data/board_data/collision/kyogre/board_tiledata.bin"

gKyrGrouBoardCollisionAngleDataAllLayers:: @ 0x08335804
	.incbin "data/board_data/collision/kyogre/board_angledata.bin"

gKyrGrouBoardCollisionTypeDataAllLayers:: @ 0x0833AD84
	.incbin "data/board_data/collision/kyogre/board_typedata.bin"

gKyogreBoardBG1Tilemap:: @ 0x0833D844
	.incbin "graphics/stage/kyogre/kyogre_board_bg1_tilemap.bin"

gKyogreBoardCompressedBGTiles:: @ 0x0833E044
	.incbin "graphics/stage/kyogre/kyogre_board_bg_tiles.4bpp.lz"

gKyogreIntroShorePalette:: @ 0x0833FF58
	.incbin "graphics/stage/kyogre/intro_shore.gbapal"

gKyogreFadeInPaletteStep4:: @ 0x08340158
    .incbin "graphics/stage/kyogre/fade_in_step4.gbapal"

gKyogreFadeInPaletteStep3:: @ 0x08340358
    .incbin "graphics/stage/kyogre/fade_in_step3.gbapal"

gKyogreFadeInPaletteStep2:: @ 0x08340558
    .incbin "graphics/stage/kyogre/fade_in_step2.gbapal"

gKyogreFadeInPaletteStep1:: @ 0x08340758
    .incbin "graphics/stage/kyogre/fade_in_step1.gbapal"

gKyogreFadeInPaletteStep0:: @ 0x08340958
    .incbin "graphics/stage/kyogre/fade_in_step0.gbapal"

gKyogreForm1CollisionMap:: @ 0x08340B58
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_1_collision_120x152.bin"

gKyogreForm2CollisionMap:: @ 0x083499D8
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_2_collision_96x88.bin"

gKyogreForm3CollisionMap:: @ 0x0834DBD8
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_3_collision_96x104.bin"

gKyogreIntroIcePalette:: @ 0x083529D8
	.incbin "graphics/stage/kyogre/intro_ice.gbapal"
