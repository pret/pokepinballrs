@ note: base collision data for kyogre/groudon boards are shared.
@ that is in this file at 0x08333804, 0x08335804, 0x0833AD84
@ other data is kyogre specific

gKyogreBoardPalette:: @ 0x08332E04
	.incbin "baserom.gba", 0x332E04, 0x200

gKyogreWaterBackgroundTilemap:: @ 0x08333004
	.incbin "baserom.gba", 0x333004, 0x800

gKyrGrouBoardCollisionTileDataAllLayers:: @ 0x08333804
.incbin "data/board_data/collision/kyogre/board_tiledata.bin"

gKyrGrouBoardCollisionAngleDataAllLayers:: @ 0x08335804
.incbin "data/board_data/collision/kyogre/board_angledata.bin"

gKyrGrouBoardCollisionTypeDataAllLayers:: @ 0x0833AD84
.incbin "data/board_data/collision/kyogre/board_typedata.bin"

gKyogreBoardBG1Tilemap:: @ 0x0833D844
	.incbin "baserom.gba", 0x33D844, 0x800

gKyogreBoardCompressedBGTiles:: @ 0x0833E044
	.incbin "baserom.gba", 0x33E044, 0x1F14

gKyogreIntroShorePalette:: @ 0x0833FF58
	.incbin "baserom.gba", 0x33FF58, 0x200

gKyogreFadeInPaletteStep4:: @ 0x08340158
    .incbin "baserom.gba", 0x340158, 0x200

gKyogreFadeInPaletteStep3:: @ 0x08340358
    .incbin "baserom.gba", 0x340358, 0x200

gKyogreFadeInPaletteStep2:: @ 0x08340558
    .incbin "baserom.gba", 0x340558, 0x200

gKyogreFadeInPaletteStep1:: @ 0x08340758
    .incbin "baserom.gba", 0x340758, 0x200

gKyogreFadeInPaletteStep0:: @ 0x08340958
    .incbin "baserom.gba", 0x340958, 0x200

gKyogreForm1CollisionMap:: @ 0x08340B58
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_1_collision_120x152.bin"

gKyogreForm2CollisionMap:: @ 0x083499D8
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_2_collision_96x88.bin"

gKyogreForm3CollisionMap:: @ 0x0834DBD8
	.incbin "data/board_data/collision/kyogre/kyogre_entity_form_3_collision_96x104.bin"

gKyogreIntroIcePalette:: @ 0x083529D8
	.incbin "baserom.gba", 0x3529D8, 0x200
